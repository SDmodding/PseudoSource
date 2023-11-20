// File Line: 27
// RVA: 0x14646F0
__int64 dynamic_initializer_for__UFG::AudioEventPropertyManager::mDatabase__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::AudioEventPropertyManager::mDatabase.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::AudioEventPropertyManager::mDatabase__);
}

// File Line: 32
// RVA: 0x147630
void UFG::AudioEventPropertyManager::Initialize(void)
{
  unsigned __int64 v0; // rbx
  UFG::qReflectWarehouse *v1; // rax
  UFG::qReflectInventoryBase *v2; // rax
  UFG::qTree64Base *v3; // rdi
  UFG::qTree64Base *v4; // rax
  signed __int64 v5; // rbx
  char *v6; // rax
  UFG::qTree64Base *v7; // rax

  v0 = UFG::qStringHash64("UFG::AudioEventPropertyData", 0xFFFFFFFFFFFFFFFFui64);
  v1 = UFG::qReflectWarehouse::Instance();
  v2 = UFG::qReflectWarehouse::GetInventory(v1, v0);
  v3 = &v2->mItems.mTree;
  v4 = UFG::qTree64Base::GetHead(&v2->mItems.mTree);
  if ( v4 )
  {
    v5 = (signed __int64)&v4[-1].mCount;
    if ( v4 != (UFG::qTree64Base *)8 )
    {
      do
      {
        v6 = UFG::qMalloc(0x30ui64, "AudioEventProperties", 0i64);
        if ( v6 )
        {
          *(_QWORD *)v6 = 0i64;
          *((_QWORD *)v6 + 1) = 0i64;
          *((_QWORD *)v6 + 2) = 0i64;
          *((_DWORD *)v6 + 8) = 0;
          *((_QWORD *)v6 + 5) = v5;
          *((_DWORD *)v6 + 6) = *(_DWORD *)(v5 + 80);
        }
        else
        {
          v6 = 0i64;
        }
        UFG::qBaseTreeRB::Add(&UFG::AudioEventPropertyManager::mDatabase.mTree, (UFG::qBaseNodeRB *)v6);
        v7 = UFG::qTree64Base::GetNext(v3, (UFG::qTree64Base::BaseNode *)(v5 + 8));
        if ( !v7 )
          break;
        v5 = (signed __int64)&v7[-1].mCount;
      }
      while ( v7 != (UFG::qTree64Base *)8 );
    }
  }
}

// File Line: 51
// RVA: 0x14C910
void UFG::AudioEventPropertyManager::Shutdown(void)
{
  Render::SkinningCacheNode *v0; // rbx

  while ( UFG::AudioEventPropertyManager::mDatabase.mTree.mCount )
  {
    v0 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioEventPropertyManager::mDatabase);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::AudioEventPropertyManager::mDatabase,
      &v0->mNode);
    operator delete[](v0);
  }
}

// File Line: 58
// RVA: 0x1453F0
UFG::qBaseTreeRB *__fastcall UFG::AudioEventPropertyManager::Find(unsigned int uid)
{
  UFG::qBaseTreeRB *result; // rax

  if ( uid )
    result = UFG::qBaseTreeRB::Get(&UFG::AudioEventPropertyManager::mDatabase.mTree, uid);
  else
    result = 0i64;
  return result;
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
  return atexit(dynamic_atexit_destructor_for__UFG::AudioCategoryPropertyManager::mDatabase__);
}

// File Line: 91
// RVA: 0x147560
void UFG::AudioCategoryPropertyManager::Initialize(void)
{
  unsigned __int64 v0; // rbx
  UFG::qReflectWarehouse *v1; // rax
  UFG::qReflectInventoryBase *v2; // rax
  UFG::qTree64Base *v3; // rdi
  UFG::qTree64Base *v4; // rax
  signed __int64 v5; // rbx
  UFG::qBaseNodeRB *v6; // rax
  UFG::qTree64Base *v7; // rax

  v0 = UFG::qStringHash64("UFG::AudioCategoryPropertyData", 0xFFFFFFFFFFFFFFFFui64);
  v1 = UFG::qReflectWarehouse::Instance();
  v2 = UFG::qReflectWarehouse::GetInventory(v1, v0);
  v3 = &v2->mItems.mTree;
  v4 = UFG::qTree64Base::GetHead(&v2->mItems.mTree);
  if ( v4 )
  {
    v5 = (signed __int64)&v4[-1].mCount;
    if ( v4 != (UFG::qTree64Base *)8 )
    {
      do
      {
        v6 = (UFG::qBaseNodeRB *)UFG::qMalloc(0x28ui64, "AudioCategoryProperties", 0i64);
        if ( v6 )
        {
          v6->mParent = 0i64;
          v6->mChild[0] = 0i64;
          v6->mChild[1] = 0i64;
          v6[1].mParent = (UFG::qBaseNodeRB *)v5;
          v6->mUID = *(_DWORD *)(v5 + 80);
        }
        else
        {
          v6 = 0i64;
        }
        UFG::qBaseTreeRB::Add(&UFG::AudioCategoryPropertyManager::mDatabase.mTree, v6);
        v7 = UFG::qTree64Base::GetNext(v3, (UFG::qTree64Base::BaseNode *)(v5 + 8));
        if ( !v7 )
          break;
        v5 = (signed __int64)&v7[-1].mCount;
      }
      while ( v7 != (UFG::qTree64Base *)8 );
    }
  }
}

// File Line: 109
// RVA: 0x14BAE0
void __fastcall UFG::AudioCategoryPropertyManager::SetAuxSendRtpcForEnvironment(UFG::qWiseSymbol *environment, UFG::AudioEntity *entity)
{
  UFG::AudioEntity *v2; // r15
  UFG::qWiseSymbol *v3; // rbx
  bool v4; // r12
  UFG::qSymbolUC *v5; // rax
  char *v6; // rax
  UFG::qSymbolUC *v7; // rax
  char *v8; // rbx
  const char *v9; // rax
  UFG::qBaseTreeRB *i; // r14
  char v11; // r13
  signed __int64 v12; // rbp
  const char *v13; // rax
  unsigned int v14; // esi
  UFG::qBaseNodeRB *v15; // rax
  signed __int64 v16; // rdi
  int v17; // eax
  double v18; // xmm6_8
  const char *v19; // rbx
  const char *v20; // rax
  UFG::qBaseNodeRB *v21; // rax
  double v22; // xmm6_8
  const char *v23; // rbx
  const char *v24; // rax
  signed __int64 v25; // [rsp+20h] [rbp-58h]
  UFG::qWiseSymbol *v26; // [rsp+80h] [rbp+8h]
  UFG::qSymbol result; // [rsp+90h] [rbp+18h]

  v26 = environment;
  v25 = -2i64;
  v2 = entity;
  v3 = environment;
  if ( !(_S2_5 & 1) )
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
      || (v5 = (UFG::qSymbolUC *)UFG::AudioEntity::GetName(v2, &result),
          v6 = UFG::qSymbol::as_cstr_dbg(v5),
          strstr(v6, UFG::AudioEntity::sm_environmentInfoFilter.mData)) )
    {
      v7 = (UFG::qSymbolUC *)UFG::AudioEntity::GetName(v2, &result);
      v8 = UFG::qSymbol::as_cstr_dbg(v7);
      v9 = UFG::qWiseSymbol::as_cstr_dbg(v26);
      UFG::qPrintf("SetAuxSend: %s %s\n", v9, v8);
      v3 = v26;
    }
    else
    {
      v4 = 0;
    }
  }
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioCategoryPropertyManager::mDatabase);
        i;
        v3 = v26 )
  {
    v11 = 0;
    v12 = 0i64;
    if ( v4 )
    {
      v13 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)&i->mNULL.mParent[2].mChild[1]);
      UFG::qPrintf("\tSetAuxSend: category %s\n", v13);
    }
    v14 = 0;
    v15 = i->mNULL.mParent;
    if ( LODWORD(v15[3].mParent) )
    {
      do
      {
        v16 = *(_QWORD *)&v15[2].mUID + 88i64 * v14;
        v17 = *(_DWORD *)(v16 + 80);
        if ( v3->mUID == v17 )
        {
          v11 = 1;
          if ( v4 )
          {
            v18 = *(float *)(v16 + 84);
            v19 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)(v16 + 80));
            v20 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)&i->mNULL.mParent[2].mChild[1] + 1);
            UFG::qPrintf("\t\tSetAuxSend: %s %s %f \n", v20, v19, v18, v25);
            v3 = v26;
          }
          v21 = i->mNULL.mParent;
          if ( v2->m_bIsInitialized )
            UFG::WwiseInterface::SetWwiseRtpcValue(
              HIDWORD(v21[2].mChild[1]),
              *(float *)(v16 + 84),
              (unsigned __int64)v2);
        }
        else if ( default_symbol.mUID == v17 )
        {
          v12 = v16;
        }
        ++v14;
        v15 = i->mNULL.mParent;
      }
      while ( v14 < LODWORD(v15[3].mParent) );
      if ( !v11 && v12 )
      {
        if ( v4 )
        {
          v22 = *(float *)(v12 + 84);
          v23 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)(v12 + 80));
          v24 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)&i->mNULL.mParent[2].mChild[1] + 1);
          UFG::qPrintf("\t\tSetAuxSend (default): %s %s %f \n", v24, v23, v22, v25);
        }
        if ( v2->m_bIsInitialized )
          UFG::WwiseInterface::SetWwiseRtpcValue(
            HIDWORD(i->mNULL.mParent[2].mChild[1]),
            *(float *)(v12 + 84),
            (unsigned __int64)v2);
      }
    }
    i = UFG::qBaseTreeRB::GetNext(&UFG::AudioCategoryPropertyManager::mDatabase.mTree, &i->mRoot);
  }
}      }
 

// File Line: 168
// RVA: 0x1465740
__int64 UFG::_dynamic_initializer_for__qwsTunnel__()
{
  UFG::qWiseSymbol::create_from_string(&qwsTunnel, "tunnel");
  return atexit(UFG::_dynamic_atexit_destructor_for__qwsTunnel__);
}

// File Line: 195
// RVA: 0x14C680
void UFG::AudioCategoryPropertyManager::Shutdown(void)
{
  Render::SkinningCacheNode *v0; // rbx

  while ( UFG::AudioCategoryPropertyManager::mDatabase.mTree.mCount )
  {
    v0 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioCategoryPropertyManager::mDatabase);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::AudioCategoryPropertyManager::mDatabase,
      &v0->mNode);
    operator delete[](v0);
  }
}

