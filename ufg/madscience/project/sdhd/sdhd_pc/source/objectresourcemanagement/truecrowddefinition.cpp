// File Line: 40
// RVA: 0x438140
void __fastcall UFG::TrueCrowdDefinition::~TrueCrowdDefinition(UFG::TrueCrowdDefinition *this)
{
  `eh vector destructor iterator'(
    this->mEntities,
    0x50Cui64,
    25,
    (void (__fastcall *)(void *))UFG::TrueCrowdDefinition::Entity::~Entity);
}

// File Line: 106
// RVA: 0x439590
UFG::BitFlags128 *__fastcall UFG::TrueCrowdDefinition::BuildBitFlagFromTags(UFG::TrueCrowdDefinition *this, UFG::BitFlags128 *result, UFG::qPropertyList *tag_list, UFG::qPropertySet *property_set)
{
  __int64 v4; // rbx
  UFG::qPropertySet *v5; // r14
  UFG::BitFlags128 *v6; // rdi
  UFG::TrueCrowdDefinition *v7; // r15
  UFG::qSymbolUC *v8; // rsi
  __int64 v9; // rbp
  __int64 v10; // rax
  signed __int64 v11; // rdx
  __int64 v12; // r8
  unsigned int v13; // ecx
  __int64 v14; // rax
  char *v15; // rbx
  char *v16; // rax
  UFG::BaseCameraComponent *v17; // rdx

  v4 = tag_list->mNumElements;
  v5 = property_set;
  v6 = result;
  v7 = this;
  result->mFlags[0] = 0i64;
  result->mFlags[1] = 0i64;
  if ( (_DWORD)v4 )
    v8 = (UFG::qSymbolUC *)UFG::qPropertyList::Get<UFG::qSymbol>(tag_list, 0);
  else
    v8 = 0i64;
  if ( (_DWORD)v4 )
  {
    v9 = v4;
    do
    {
      v10 = v7->mTagList.mOffset;
      if ( v10 )
        v11 = (signed __int64)&v7->mTagList + v10;
      else
        v11 = 0i64;
      v12 = (signed int)v7->mNumTags;
      v13 = 0;
      v14 = 0i64;
      if ( v12 <= 0 )
        goto LABEL_12;
      while ( *(_DWORD *)(v11 + 4 * v14) != v8->mUID )
      {
        ++v14;
        ++v13;
        if ( v14 >= v12 )
          goto LABEL_12;
      }
      if ( v13 == -1 )
      {
LABEL_12:
        if ( v5 )
          v15 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v5->mName);
        else
          v15 = "no ps set passed in";
        v16 = UFG::qSymbol::as_cstr_dbg(v8);
        UFG::qPrintf("WARNING!!Found tag that is not in the tag list:%s in set:%s\n", v16, v15);
        v17 = UFG::Director::Get()->mCurrentCamera;
        if ( v17 )
          v17 = (UFG::BaseCameraComponent *)((char *)v17 + 80);
        UFG::qPrintf("Please fix soon...tell James Agay or Dave -- cam pos:%v\n", &v17->mCamera.mView.v2);
      }
      else if ( v13 >= 0x40 )
      {
        v6->mFlags[1] |= 1i64 << ((unsigned __int8)v13 - 64);
      }
      else
      {
        v6->mFlags[0] |= 1i64 << v13;
      }
      ++v8;
      --v9;
    }
    while ( v9 );
  }
  return v6;
}

// File Line: 174
// RVA: 0x43D950
signed __int64 __fastcall UFG::TrueCrowdDefinition::GetEntityComponentIndex(UFG::TrueCrowdDefinition *this, unsigned int entityIndex, UFG::qSymbol *entityComponentName)
{
  char *v3; // rcx
  signed __int64 result; // rax
  unsigned int v5; // er9
  _DWORD *v6; // rcx

  v3 = (char *)this + 1292 * entityIndex;
  result = 0i64;
  v5 = *((_DWORD *)v3 + 228);
  if ( !v5 )
    return 0xFFFFFFFFi64;
  v6 = v3 + 920;
  while ( *v6 != entityComponentName->mUID )
  {
    result = (unsigned int)(result + 1);
    v6 += 20;
    if ( (unsigned int)result >= v5 )
      return 0xFFFFFFFFi64;
  }
  return result;
}

