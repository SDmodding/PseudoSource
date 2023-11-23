// File Line: 27
// RVA: 0x14646F0
__int64 dynamic_initializer_for__UFG::AudioEventPropertyManager::mDatabase__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::AudioEventPropertyManager::mDatabase.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AudioEventPropertyManager::mDatabase__);
}

// File Line: 32
// RVA: 0x147630
void UFG::AudioEventPropertyManager::Initialize(void)
{
  unsigned __int64 v0; // rbx
  UFG::qReflectWarehouse *v1; // rax
  UFG::qTree64<UFG::qReflectObject,UFG::qReflectObject,0> *p_mItems; // rdi
  UFG::qTree64Base *Head; // rax
  __int64 *p_mCount; // rbx
  char *v5; // rax
  UFG::qTree64Base *Next; // rax

  v0 = UFG::qStringHash64("UFG::AudioEventPropertyData", 0xFFFFFFFFFFFFFFFFui64);
  v1 = UFG::qReflectWarehouse::Instance();
  p_mItems = &UFG::qReflectWarehouse::GetInventory(v1, v0)->mItems;
  Head = UFG::qTree64Base::GetHead(&p_mItems->mTree);
  if ( Head )
  {
    p_mCount = &Head[-1].mCount;
    if ( Head != (UFG::qTree64Base *)8 )
    {
      do
      {
        v5 = UFG::qMalloc(0x30ui64, "AudioEventProperties", 0i64);
        if ( v5 )
        {
          *(_QWORD *)v5 = 0i64;
          *((_QWORD *)v5 + 1) = 0i64;
          *((_QWORD *)v5 + 2) = 0i64;
          *((_DWORD *)v5 + 8) = 0;
          *((_QWORD *)v5 + 5) = p_mCount;
          *((_DWORD *)v5 + 6) = *((_DWORD *)p_mCount + 20);
        }
        else
        {
          v5 = 0i64;
        }
        UFG::qBaseTreeRB::Add(&UFG::AudioEventPropertyManager::mDatabase.mTree, (UFG::qBaseNodeRB *)v5);
        Next = UFG::qTree64Base::GetNext(&p_mItems->mTree, (UFG::qTree64Base::BaseNode *)(p_mCount + 1));
        if ( !Next )
          break;
        p_mCount = &Next[-1].mCount;
      }
      while ( Next != (UFG::qTree64Base *)8 );
    }
  }
}

// File Line: 51
// RVA: 0x14C910
void UFG::AudioEventPropertyManager::Shutdown(void)
{
  Render::SkinningCacheNode *Head; // rbx

  while ( UFG::AudioEventPropertyManager::mDatabase.mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioEventPropertyManager::mDatabase);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::AudioEventPropertyManager::mDatabase,
      &Head->mNode);
    operator delete[](Head);
  }
}

// File Line: 58
// RVA: 0x1453F0
UFG::qBaseTreeRB *__fastcall UFG::AudioEventPropertyManager::Find(unsigned int uid)
{
  if ( uid )
    return UFG::qBaseTreeRB::Get(&UFG::AudioEventPropertyManager::mDatabase.mTree, uid);
  else
    return 0i64;
}

// File Line: 67
// RVA: 0x14B550
void UFG::AudioEventPropertyManager::Reset(void)
{
  UFG::qBaseTreeRB *i; // rax

  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioEventPropertyManager::mDatabase);
        i;
        i = UFG::qBaseTreeRB::GetNext(&UFG::AudioEventPropertyManager::mDatabase.mTree, &i->mRoot) )
  {
    LODWORD(i->mNULL.mParent) = 0;
  }
}

// File Line: 86
// RVA: 0x14646C0
__int64 dynamic_initializer_for__UFG::AudioCategoryPropertyManager::mDatabase__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::AudioCategoryPropertyManager::mDatabase.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AudioCategoryPropertyManager::mDatabase__);
}

// File Line: 91
// RVA: 0x147560
void UFG::AudioCategoryPropertyManager::Initialize(void)
{
  unsigned __int64 v0; // rbx
  UFG::qReflectWarehouse *v1; // rax
  UFG::qTree64<UFG::qReflectObject,UFG::qReflectObject,0> *p_mItems; // rdi
  UFG::qTree64Base *Head; // rax
  __int64 *p_mCount; // rbx
  UFG::qBaseNodeRB *v5; // rax
  UFG::qTree64Base *Next; // rax

  v0 = UFG::qStringHash64("UFG::AudioCategoryPropertyData", 0xFFFFFFFFFFFFFFFFui64);
  v1 = UFG::qReflectWarehouse::Instance();
  p_mItems = &UFG::qReflectWarehouse::GetInventory(v1, v0)->mItems;
  Head = UFG::qTree64Base::GetHead(&p_mItems->mTree);
  if ( Head )
  {
    p_mCount = &Head[-1].mCount;
    if ( Head != (UFG::qTree64Base *)8 )
    {
      do
      {
        v5 = (UFG::qBaseNodeRB *)UFG::qMalloc(0x28ui64, "AudioCategoryProperties", 0i64);
        if ( v5 )
        {
          v5->mParent = 0i64;
          v5->mChild[0] = 0i64;
          v5->mChild[1] = 0i64;
          v5[1].mParent = (UFG::qBaseNodeRB *)p_mCount;
          v5->mUID = *((_DWORD *)p_mCount + 20);
        }
        else
        {
          v5 = 0i64;
        }
        UFG::qBaseTreeRB::Add(&UFG::AudioCategoryPropertyManager::mDatabase.mTree, v5);
        Next = UFG::qTree64Base::GetNext(&p_mItems->mTree, (UFG::qTree64Base::BaseNode *)(p_mCount + 1));
        if ( !Next )
          break;
        p_mCount = &Next[-1].mCount;
      }
      while ( Next != (UFG::qTree64Base *)8 );
    }
  }
}

// File Line: 109
// RVA: 0x14BAE0
void __fastcall UFG::AudioCategoryPropertyManager::SetAuxSendRtpcForEnvironment(
        UFG::qWiseSymbol *environment,
        UFG::AudioEntity *entity)
{
  UFG::qWiseSymbol *v3; // rbx
  bool v4; // r12
  UFG::qSymbolUC *v5; // rax
  char *v6; // rax
  UFG::qSymbolUC *Name; // rax
  char *v8; // rbx
  const char *v9; // rax
  UFG::qBaseTreeRB *i; // r14
  char v11; // r13
  __int64 v12; // rbp
  const char *v13; // rax
  unsigned int v14; // esi
  UFG::qBaseNodeRB *mParent; // rax
  __int64 v16; // rdi
  int v17; // eax
  double v18; // xmm6_8
  const char *v19; // rbx
  const char *v20; // rax
  double v21; // xmm6_8
  const char *v22; // rbx
  const char *v23; // rax
  UFG::qSymbol result; // [rsp+90h] [rbp+18h] BYREF

  v3 = environment;
  if ( (_S2_5 & 1) == 0 )
  {
    _S2_5 |= 1u;
    default_symbol.mUID = UFG::qWiseSymbolUIDFromString("default", 0x811C9DC5);
    _((AMD_HD3D *)default_symbol.mUID);
    atexit(UFG::AudioCategoryPropertyManager::SetAuxSendRtpcForEnvironment_::_2_::_dynamic_atexit_destructor_for__default_symbol__);
  }
  v4 = UFG::AudioEntity::sm_displayEnvironmentInfo;
  if ( UFG::AudioEntity::sm_displayEnvironmentInfo )
  {
    if ( !UFG::AudioEntity::sm_environmentInfoFilter.mLength
      || (v5 = (UFG::qSymbolUC *)UFG::AudioEntity::GetName(entity, &result),
          v6 = UFG::qSymbol::as_cstr_dbg(v5),
          strstr(v6, UFG::AudioEntity::sm_environmentInfoFilter.mData)) )
    {
      Name = (UFG::qSymbolUC *)UFG::AudioEntity::GetName(entity, &result);
      v8 = UFG::qSymbol::as_cstr_dbg(Name);
      v9 = UFG::qWiseSymbol::as_cstr_dbg(environment);
      UFG::qPrintf("SetAuxSend: %s %s\n", v9, v8);
      v3 = environment;
    }
    else
    {
      v4 = 0;
    }
  }
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioCategoryPropertyManager::mDatabase);
        i;
        v3 = environment )
  {
    v11 = 0;
    v12 = 0i64;
    if ( v4 )
    {
      v13 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)&i->mNULL.mParent[2].mChild[1]);
      UFG::qPrintf("\tSetAuxSend: category %s\n", v13);
    }
    v14 = 0;
    mParent = i->mNULL.mParent;
    if ( LODWORD(mParent[3].mParent) )
    {
      do
      {
        v16 = *(_QWORD *)&mParent[2].mUID + 88i64 * v14;
        v17 = *(_DWORD *)(v16 + 80);
        if ( v3->mUID == v17 )
        {
          v11 = 1;
          if ( v4 )
          {
            v18 = *(float *)(v16 + 84);
            v19 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)(v16 + 80));
            v20 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)&i->mNULL.mParent[2].mChild[1] + 1);
            UFG::qPrintf("\t\tSetAuxSend: %s %s %f \n", v20, v19, v18);
            v3 = environment;
          }
          if ( entity->m_bIsInitialized )
            UFG::WwiseInterface::SetWwiseRtpcValue(
              HIDWORD(i->mNULL.mParent[2].mChild[1]),
              *(float *)(v16 + 84),
              (unsigned __int64)entity);
        }
        else if ( default_symbol.mUID == v17 )
        {
          v12 = v16;
        }
        ++v14;
        mParent = i->mNULL.mParent;
      }
      while ( v14 < LODWORD(mParent[3].mParent) );
      if ( !v11 && v12 )
      {
        if ( v4 )
        {
          v21 = *(float *)(v12 + 84);
          v22 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)(v12 + 80));
          v23 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)&i->mNULL.mParent[2].mChild[1] + 1);
          UFG::qPrintf("\t\tSetAuxSend (default): %s %s %f \n", v23, v22, v21);
        }
        if ( entity->m_bIsInitialized )
          UFG::WwiseInterface::SetWwiseRtpcValue(
            HIDWORD(i->mNULL.mParent[2].mChild[1]),
            *(float *)(v12 + 84),
            (unsigned __int64)entity);
      }
    }
    i = UFG::qBaseTreeRB::GetNext(&UFG::AudioCategoryPropertyManager::mDatabase.mTree, &i->mRoot);
  }
}

// File Line: 168
// RVA: 0x1465740
__int64 UFG::_dynamic_initializer_for__qwsTunnel__()
{
  UFG::qWiseSymbol::create_from_string(&qwsTunnel, "tunnel");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qwsTunnel__);
}

// File Line: 195
// RVA: 0x14C680
void UFG::AudioCategoryPropertyManager::Shutdown(void)
{
  Render::SkinningCacheNode *Head; // rbx

  while ( UFG::AudioCategoryPropertyManager::mDatabase.mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioCategoryPropertyManager::mDatabase);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::AudioCategoryPropertyManager::mDatabase,
      &Head->mNode);
    operator delete[](Head);
  }
}

