// File Line: 40
// RVA: 0x438140
void __fastcall UFG::TrueCrowdDefinition::~TrueCrowdDefinition(UFG::TrueCrowdDefinition *this)
{
  `eh vector destructor iterator(
    this->mEntities,
    0x50Cui64,
    25,
    (void (__fastcall *)(void *))UFG::TrueCrowdDefinition::Entity::~Entity);
}

// File Line: 106
// RVA: 0x439590
UFG::BitFlags128 *__fastcall UFG::TrueCrowdDefinition::BuildBitFlagFromTags(
        UFG::TrueCrowdDefinition *this,
        UFG::BitFlags128 *result,
        UFG::qPropertyList *tag_list,
        UFG::qPropertySet *property_set)
{
  __int64 mNumElements; // rbx
  UFG::qSymbolUC *v8; // rsi
  __int64 v9; // rbp
  __int64 mOffset; // rax
  char *v11; // rdx
  __int64 mNumTags; // r8
  unsigned int v13; // ecx
  __int64 v14; // rax
  char *v15; // rbx
  char *v16; // rax
  UFG::BaseCameraComponent *mCurrentCamera; // rdx

  mNumElements = tag_list->mNumElements;
  result->mFlags[0] = 0i64;
  result->mFlags[1] = 0i64;
  if ( (_DWORD)mNumElements )
    v8 = (UFG::qSymbolUC *)UFG::qPropertyList::Get<UFG::qSymbol>(tag_list, 0);
  else
    v8 = 0i64;
  if ( (_DWORD)mNumElements )
  {
    v9 = mNumElements;
    do
    {
      mOffset = this->mTagList.mOffset;
      if ( mOffset )
        v11 = (char *)&this->mTagList + mOffset;
      else
        v11 = 0i64;
      mNumTags = (int)this->mNumTags;
      v13 = 0;
      v14 = 0i64;
      if ( mNumTags <= 0 )
        goto LABEL_12;
      while ( *(_DWORD *)&v11[4 * v14] != v8->mUID )
      {
        ++v14;
        ++v13;
        if ( v14 >= mNumTags )
          goto LABEL_12;
      }
      if ( v13 == -1 )
      {
LABEL_12:
        if ( property_set )
          v15 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&property_set->mName);
        else
          v15 = "no ps set passed in";
        v16 = UFG::qSymbol::as_cstr_dbg(v8);
        UFG::qPrintf("WARNING!!Found tag that is not in the tag list:%s in set:%s\n", v16, v15);
        mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
        if ( mCurrentCamera )
          mCurrentCamera = (UFG::BaseCameraComponent *)((char *)mCurrentCamera + 80);
        UFG::qPrintf("Please fix soon...tell James Agay or Dave -- cam pos:%v\n", &mCurrentCamera->mCamera.mView.v2);
      }
      else if ( v13 >= 0x40 )
      {
        result->mFlags[1] |= 1i64 << ((unsigned __int8)v13 - 64);
      }
      else
      {
        result->mFlags[0] |= 1i64 << v13;
      }
      ++v8;
      --v9;
    }
    while ( v9 );
  }
  return result;
}

// File Line: 174
// RVA: 0x43D950
signed __int64 __fastcall UFG::TrueCrowdDefinition::GetEntityComponentIndex(
        UFG::TrueCrowdDefinition *this,
        unsigned int entityIndex,
        UFG::qSymbol *entityComponentName)
{
  char *v3; // rcx
  signed __int64 result; // rax
  unsigned int v5; // r9d
  _DWORD *i; // rcx

  v3 = (char *)this + 1292 * entityIndex;
  result = 0i64;
  v5 = *((_DWORD *)v3 + 228);
  if ( !v5 )
    return 0xFFFFFFFFi64;
  for ( i = v3 + 920; *i != entityComponentName->mUID; i += 20 )
  {
    result = (unsigned int)(result + 1);
    if ( (unsigned int)result >= v5 )
      return 0xFFFFFFFFi64;
  }
  return result;
}

