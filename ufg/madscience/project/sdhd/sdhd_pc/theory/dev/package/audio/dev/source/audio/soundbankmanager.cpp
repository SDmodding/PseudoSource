// File Line: 41
// RVA: 0x1465430
__int64 dynamic_initializer_for__Global__()
{
  Global.mUID = UFG::qWiseSymbolUIDFromString("Global", 0x811C9DC5);
  _((AMD_HD3D *)Global.mUID);
  return atexit(dynamic_atexit_destructor_for__Global__);
}

// File Line: 60
// RVA: 0x1465370
__int64 dynamic_initializer_for__UFG::SoundBankManager::sm_soundBanks__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::SoundBankManager::sm_soundBanks__);
}

// File Line: 61
// RVA: 0x1465340
__int64 dynamic_initializer_for__UFG::SoundBankManager::sm_soundBank_Tree__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::SoundBankManager::sm_soundBank_Tree.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::SoundBankManager::sm_soundBank_Tree__);
}

// File Line: 63
// RVA: 0x14651C0
__int64 dynamic_initializer_for__UFG::SoundBankManager::sm_groups__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::SoundBankManager::sm_groups.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::SoundBankManager::sm_groups__);
}

// File Line: 64
// RVA: 0x1465310
__int64 dynamic_initializer_for__UFG::SoundBankManager::sm_sizes__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::SoundBankManager::sm_sizes.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::SoundBankManager::sm_sizes__);
}

// File Line: 65
// RVA: 0x14650D0
__int64 dynamic_initializer_for__UFG::SoundBankManager::sm_bankFilterString__()
{
  UFG::qString::qString(&UFG::SoundBankManager::sm_bankFilterString, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__UFG::SoundBankManager::sm_bankFilterString__);
}

// File Line: 90
// RVA: 0x1465100
__int64 dynamic_initializer_for__UFG::SoundBankCategory::sm_categories__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::SoundBankCategory::sm_categories__);
}

// File Line: 93
// RVA: 0x140950
void __fastcall UFG::SoundBankCategory::SoundBankCategory(UFG::SoundBankCategory *this, const char *name, const char *categoryPrefix, unsigned int priority)
{
  unsigned int v4; // er14
  const char *v5; // rsi
  const char *v6; // rbx
  UFG::SoundBankCategory *v7; // r15
  __int64 v8; // rax
  __int64 v9; // rax
  UFG::qNode<UFG::SoundBankCategory,UFG::SoundBankCategory> *v10; // rax
  UFG::qString v11; // [rsp+38h] [rbp-40h]

  v4 = priority;
  v5 = categoryPrefix;
  v6 = name;
  v7 = this;
  this->mPrev = (UFG::qNode<UFG::SoundBankCategory,UFG::SoundBankCategory> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::SoundBankCategory,UFG::SoundBankCategory> *)&this->mPrev;
  UFG::qString::qString(&this->m_categoryName);
  UFG::qString::qString(&v7->m_categoryPrefix);
  UFG::qString::qString(&v11, v6);
  UFG::qString::Set(&v7->m_categoryName, *(const char **)(v8 + 24), *(_DWORD *)(v8 + 20), 0i64, 0);
  UFG::qString::~qString(&v11);
  UFG::qString::qString(&v11, v5);
  UFG::qString::Set(&v7->m_categoryPrefix, *(const char **)(v9 + 24), *(_DWORD *)(v9 + 20), 0i64, 0);
  UFG::qString::~qString(&v11);
  UFG::qString::MakeLower(&v7->m_categoryPrefix);
  v7->m_priority = v4;
  v10 = UFG::SoundBankCategory::sm_categories.mNode.mPrev;
  UFG::SoundBankCategory::sm_categories.mNode.mPrev->mNext = (UFG::qNode<UFG::SoundBankCategory,UFG::SoundBankCategory> *)&v7->mPrev;
  v7->mPrev = v10;
  v7->mNext = (UFG::qNode<UFG::SoundBankCategory,UFG::SoundBankCategory> *)&UFG::SoundBankCategory::sm_categories;
  UFG::SoundBankCategory::sm_categories.mNode.mPrev = (UFG::qNode<UFG::SoundBankCategory,UFG::SoundBankCategory> *)&v7->mPrev;
}

// File Line: 104
// RVA: 0x1456C0
UFG::SoundBankCategory *__fastcall UFG::SoundBankCategory::FindMatchingCategoryForSoundBank(UFG::qString *bankName)
{
  UFG::qString *v1; // rsi
  UFG::SoundBankCategory *v2; // rdi
  UFG::SoundBankCategory *i; // rbx
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v1 = bankName;
  UFG::qString::ToLower(bankName, &result);
  v2 = 0i64;
  for ( i = (UFG::SoundBankCategory *)UFG::SoundBankCategory::sm_categories.mNode.mNext;
        i != (UFG::SoundBankCategory *)&UFG::SoundBankCategory::sm_categories;
        i = (UFG::SoundBankCategory *)i->mNext )
  {
    if ( (unsigned int)UFG::qString::StartsWith(&result, i->m_categoryPrefix.mData, -1)
      && (!v2 || i->m_categoryName.mLength > v2->m_categoryName.mLength) )
    {
      v2 = i;
    }
  }
  UFG::qString::~qString(&result);
  UFG::qString::~qString(v1);
  return v2;
}

// File Line: 141
// RVA: 0x14652E0
__int64 dynamic_initializer_for__UFG::SoundBankFragFreePool::sm_pools__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::SoundBankFragFreePool::sm_pools.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::SoundBankFragFreePool::sm_pools__);
}

// File Line: 160
// RVA: 0x145410
signed __int64 __fastcall UFG::SoundBankFragFreePool::FindBestFitPoolForBank(UFG::SoundBank *bank)
{
  unsigned int v1; // edx
  UFG::SoundBank *v2; // rsi
  UFG::qBaseTreeRB *v3; // rax
  UFG::qBaseTreeRB *v4; // rbx
  unsigned int v5; // edx
  __int64 v6; // rdi
  UFG::qBaseTreeRB *v7; // rax
  __int64 v8; // rcx

  v1 = bank->m_name.mUID;
  v2 = bank;
  if ( !v1 )
    return 0xFFFFFFFFi64;
  v3 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_sizes.mTree, v1);
  if ( !v3 || !LODWORD(v3->mNULL.mParent) )
    return 0xFFFFFFFFi64;
  v4 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::SoundBankFragFreePool::sm_pools);
  if ( !v4 )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    v5 = v2->m_name.mUID;
    v6 = HIDWORD(v4[1].mRoot.mParent);
    if ( v5 && (v7 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_sizes.mTree, v5)) != 0i64 )
      v8 = LODWORD(v7->mNULL.mParent);
    else
      v8 = 0i64;
    if ( v6 >= v8 )
      break;
    v4 = UFG::qBaseTreeRB::GetNext(&UFG::SoundBankFragFreePool::sm_pools.mTree, &v4->mRoot);
    if ( !v4 )
      return 0xFFFFFFFFi64;
  }
  return LODWORD(v4[1].mRoot.mChild[0]);
}

// File Line: 264
// RVA: 0x146E00
void UFG::SoundBankManager::Init(void)
{
  Render::SkinningCacheNode *v0; // rax
  Illusion::Buffer **v1; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v2; // rdx

  if ( UFG::SoundBankManager::sm_soundBank_Tree.mTree.mCount )
  {
    while ( 1 )
    {
      v0 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::SoundBankManager::sm_soundBank_Tree);
      if ( !v0 )
        break;
      v1 = &v0[-1].mCachedBufferPtr;
      if ( v0 == (Render::SkinningCacheNode *)8 )
        goto LABEL_6;
      v2 = &v0->mNode;
LABEL_7:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::SoundBankManager::sm_soundBank_Tree,
        v2);
      if ( v1 )
        ((void (__fastcall *)(Illusion::Buffer **, signed __int64))(*v1)->mNode.mParent)(v1, 1i64);
      if ( !UFG::SoundBankManager::sm_soundBank_Tree.mTree.mCount )
        goto LABEL_10;
    }
    v1 = 0i64;
LABEL_6:
    v2 = 0i64;
    goto LABEL_7;
  }
LABEL_10:
  UFG::SoundBankManager::InitFromDefinitionFile();
  UFG::SoundBankManager::LoadBankSymbols(1);
  UFG::SoundBankManager::LoadBankSizes();
  UFG::SoundBankManager::CreatePools();
  UFG::SoundBankManager::LoadGroup("Global");
}

// File Line: 281
// RVA: 0x1442E0
void UFG::SoundBankManager::CreatePools(void)
{
  UFG::qBaseTreeRB *i; // rsi
  int v1; // eax
  unsigned int v2; // edi
  signed __int64 j; // rbx
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax
  unsigned __int64 v6; // rcx
  __int64 v7; // rbx
  signed __int64 k; // rbx
  unsigned int v9; // edx
  UFG::qBaseTreeRB *v10; // rax
  int v11; // eax
  unsigned int v12; // edi
  int v13; // eax

  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::SoundBankManager::sm_groups);
        i;
        i = UFG::qBaseTreeRB::GetNext(&UFG::SoundBankManager::sm_groups.mTree, &i->mRoot) )
  {
    v1 = HIDWORD(i->mNULL.mChild[0]);
    v2 = 0;
    if ( v1 == 2 )
      v2 = (unsigned int)i->mNULL.mChild[0];
    if ( v1 == 1 )
    {
      for ( j = *(_QWORD *)&i[1].mRoot.mUID - 56i64; (UFG::qBaseNodeRB *)j != &i->mNULL; j = v7 - 56 )
      {
        v4 = *(_DWORD *)(j + 72);
        if ( v4 && (v5 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_sizes.mTree, v4)) != 0i64 )
          v6 = LODWORD(v5->mNULL.mParent);
        else
          v6 = 0i64;
        v7 = *(_QWORD *)(j + 64);
        if ( v6 > v2 )
          v2 = v6;
      }
    }
    if ( HIDWORD(i->mNULL.mChild[0]) == 3 )
    {
      for ( k = *(_QWORD *)&i[1].mRoot.mUID - 56i64; (UFG::qBaseNodeRB *)k != &i->mNULL; k = *(_QWORD *)(k + 64) - 56i64 )
      {
        v9 = *(_DWORD *)(k + 72);
        if ( v9 && (v10 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_sizes.mTree, v9)) != 0i64 )
          v11 = (int)v10->mNULL.mParent;
        else
          v11 = 0;
        v2 += v11;
      }
    }
    if ( HIDWORD(i->mNULL.mChild[0]) == 4 )
      HIDWORD(i->mNULL.mParent) = -1;
    if ( v2 )
    {
      v12 = v2 + 0x4000;
      v13 = AK::MemoryMgr::CreatePool(0i64, v12, 1u, 1u, 0x800u);
      LODWORD(i->mNULL.mChild[0]) = v12;
      HIDWORD(i->mNULL.mParent) = v13;
    }
  }
}

// File Line: 336
// RVA: 0x147310
void __usercall UFG::SoundBankManager::InitGroup(SimpleXML::XMLDocument *doc@<rcx>, SimpleXML::XMLNode *groupNode@<rdx>, float a3@<xmm0>)
{
  SimpleXML::XMLNode *v3; // rdi
  SimpleXML::XMLDocument *v4; // r14
  char *v5; // rax
  const char *v6; // rbx
  unsigned int v7; // eax
  UFG::qBaseTreeRB *v8; // rbp
  __int64 v9; // rax
  char *v10; // rax
  unsigned int v11; // eax
  SimpleXML::XMLNode *i; // rsi
  char *v13; // rax
  char *v14; // rbx
  unsigned int v15; // edi
  UFG::SoundBank *v16; // rax
  UFG::SoundBank *v17; // rbx
  char *v18; // rax
  UFG::qString *v19; // rax
  UFG::SoundBankCategory *v20; // rdi
  _QWORD *v21; // rcx
  UFG::qBaseNodeRB *v22; // rax
  UFG::qString text; // [rsp+38h] [rbp-80h]
  UFG::qString v24; // [rsp+60h] [rbp-58h]
  UFG::qWiseSymbol result; // [rsp+D0h] [rbp+18h]
  UFG::qString *v26; // [rsp+D8h] [rbp+20h]

  v3 = groupNode;
  v4 = doc;
  v5 = SimpleXML::XMLNode::GetAttribute(groupNode, "name");
  v6 = v5;
  v7 = UFG::qStringLength(v5);
  if ( v7 )
    v7 = AK::SoundEngine::GetIDFromString(v6);
  v8 = UFG::SoundBankManager::FindOrCreateGroup(v7);
  UFG::qString::qString(&text, v6);
  UFG::qString::Set((UFG::qString *)&v8->mNULL.mChild[1], *(const char **)(v9 + 24), *(_DWORD *)(v9 + 20), 0i64, 0);
  UFG::qString::~qString(&text);
  v10 = SimpleXML::XMLNode::GetAttribute(v3, "poolSize");
  if ( !(unsigned int)UFG::qStringCompare(v10, "SizeOf_LargestBank", -1) )
    HIDWORD(v8->mNULL.mChild[0]) = 1;
  v11 = SimpleXML::XMLNode::GetAttribute(v3, "poolSize", 0);
  if ( v11 )
  {
    HIDWORD(v8->mNULL.mChild[0]) = 2;
    LODWORD(v8->mNULL.mChild[0]) = v11;
  }
  UFG::qStringCompare(v6, "Global", -1);
  for ( i = SimpleXML::XMLDocument::GetChildNode(v4, 0i64, v3); i; i = SimpleXML::XMLDocument::GetNode(v4, 0i64, i) )
  {
    v13 = SimpleXML::XMLNode::GetName(i);
    if ( !(unsigned int)UFG::qStringCompare(v13, "Bank", -1) )
    {
      v14 = SimpleXML::XMLNode::GetAttribute(i, "name");
      v15 = SimpleXML::XMLNode::GetAttribute(i, "priority", 5u);
      SimpleXML::XMLNode::GetAttribute(i, "unload_timer", 0.0);
      UFG::qWiseSymbol::create_from_string(&result, v14);
      v16 = UFG::SoundBankManager::FindOrCreateSoundBank(&result);
      v17 = v16;
      v16->m_unloadAfterTime = a3;
      v16->m_group = (UFG::SoundBankGroup *)v8;
      v16->m_priority = v15;
      v18 = SimpleXML::XMLNode::GetAttribute(i, "category", 0i64);
      if ( v18 )
      {
        UFG::qString::qString(&text, v18);
        v26 = &v24;
        UFG::qString::qString(&v24, &text);
        v20 = UFG::SoundBankCategory::FindMatchingCategoryForSoundBank(v19);
        UFG::qString::~qString(&text);
        if ( v20 )
          v17->m_category = v20;
      }
      v21 = &v17->mPrev;
      v22 = v8[1].mRoot.mChild[1];
      v22->mChild[0] = (UFG::qBaseNodeRB *)&v17->mPrev;
      *v21 = v22;
      v21[1] = (char *)v8 + 88;
      v8[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)&v17->mPrev;
      _((AMD_HD3D *)result.mUID);
    }
  }
}

// File Line: 397
// RVA: 0x146FD0
void UFG::SoundBankManager::InitFromDefinitionFile(void)
{
  SimpleXML::XMLDocument *v0; // rax
  SimpleXML::XMLDocument *v1; // r14
  SimpleXML::XMLNode *i; // r13
  SimpleXML::XMLNode *j; // r15
  char *v4; // r12
  SimpleXML::XMLNode *k; // rbx
  char *v6; // rax
  char *v7; // rdi
  char *v8; // rsi
  unsigned int v9; // ebp
  char *v10; // rax
  SimpleXML::XMLNode *l; // rbx
  char *v12; // rax
  unsigned int v13; // ebp
  unsigned int v14; // esi
  char *v15; // rdi

  v0 = SimpleXML::XMLDocument::Open("Data\\Audio\\Soundbanks.xml", 1ui64, 0i64);
  v1 = v0;
  if ( v0 )
  {
    for ( i = SimpleXML::XMLDocument::GetNode(v0, 0i64, 0i64); i; i = SimpleXML::XMLDocument::GetNode(v1, 0i64, i) )
    {
      for ( j = SimpleXML::XMLDocument::GetChildNode(v1, 0i64, i); j; j = SimpleXML::XMLDocument::GetNode(v1, 0i64, j) )
      {
        v4 = SimpleXML::XMLNode::GetName(j);
        SimpleXML::XMLNode::GetAttribute(j, "name");
        if ( !(unsigned int)UFG::qStringCompare(v4, "Categories", -1) )
        {
          for ( k = SimpleXML::XMLDocument::GetChildNode(v1, 0i64, j); k; k = SimpleXML::XMLDocument::GetNode(
                                                                                v1,
                                                                                0i64,
                                                                                k) )
          {
            v6 = SimpleXML::XMLNode::GetName(k);
            if ( !(unsigned int)UFG::qStringCompare(v6, "Category", -1) )
            {
              v7 = SimpleXML::XMLNode::GetAttribute(k, "name");
              v8 = SimpleXML::XMLNode::GetAttribute(k, "prefix");
              v9 = SimpleXML::XMLNode::GetAttribute(k, "priority", 5u);
              v10 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x68ui64, "SoundBankGroup", 0i64, 1u);
              if ( v10 )
                UFG::SoundBankCategory::SoundBankCategory((UFG::SoundBankCategory *)v10, v7, v8, v9);
            }
          }
        }
        if ( !(unsigned int)UFG::qStringCompare(v4, "Pools", -1) )
        {
          for ( l = SimpleXML::XMLDocument::GetChildNode(v1, 0i64, j); l; l = SimpleXML::XMLDocument::GetNode(
                                                                                v1,
                                                                                0i64,
                                                                                l) )
          {
            v12 = SimpleXML::XMLNode::GetName(l);
            if ( !(unsigned int)UFG::qStringCompare(v12, "Pool", -1) )
            {
              SimpleXML::XMLNode::GetAttribute(l, "name");
              v13 = SimpleXML::XMLNode::GetAttribute(l, "slotSize", 0);
              v14 = SimpleXML::XMLNode::GetAttribute(l, "numSlots", 0);
              if ( v14 )
              {
                v15 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x58ui64, "SoundBankGroup", 0i64, 1u);
                if ( v15 )
                {
                  *(_QWORD *)v15 = 0i64;
                  *((_QWORD *)v15 + 1) = 0i64;
                  *((_QWORD *)v15 + 2) = 0i64;
                  UFG::qString::qString((UFG::qString *)(v15 + 32));
                  *((_DWORD *)v15 + 18) = v14;
                  *((_DWORD *)v15 + 19) = v13;
                  *((_DWORD *)v15 + 21) = 0;
                  *((_DWORD *)v15 + 6) = v13;
                  *((_DWORD *)v15 + 20) = AK::MemoryMgr::CreatePool(0i64, v13 * v14 + 0x2000, v14, 1u, 0x800u);
                  UFG::qBaseTreeRB::Add(&UFG::SoundBankFragFreePool::sm_pools.mTree, (UFG::qBaseNodeRB *)v15);
                }
              }
            }
          }
        }
        if ( !(unsigned int)UFG::qStringCompare(v4, "Group", -1) )
          UFG::SoundBankManager::InitGroup(v1, j);
      }
    }
    SimpleXML::XMLDocument::~XMLDocument(v1);
    operator delete[](v1);
  }
}

// File Line: 469
// RVA: 0x149860
void __fastcall UFG::SoundBankManager::OnGameShutdown(UFG *a1)
{
  Render::SkinningCacheNode *v1; // rax
  Illusion::Buffer **v2; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v3; // rdx
  Render::SkinningCacheNode *v4; // rbx

  while ( UFG::SoundBankManager::sm_numPendingLoads )
  {
    UFG::qFileService(a1);
    UFG::SoundBankManager::Update(1.0);
  }
  if ( (unsigned __int8)AK::SoundEngine::IsInitialized() )
    AK::SoundEngine::ClearBanks();
  AK::SoundEngine::RenderAudio();
  if ( UFG::SoundBankManager::sm_soundBank_Tree.mTree.mCount )
  {
    while ( 1 )
    {
      v1 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::SoundBankManager::sm_soundBank_Tree);
      if ( !v1 )
        break;
      v2 = &v1[-1].mCachedBufferPtr;
      if ( v1 == (Render::SkinningCacheNode *)8 )
        goto LABEL_10;
      v3 = &v1->mNode;
LABEL_11:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::SoundBankManager::sm_soundBank_Tree,
        v3);
      if ( v2 )
        ((void (__fastcall *)(Illusion::Buffer **, signed __int64))(*v2)->mNode.mParent)(v2, 1i64);
      if ( !UFG::SoundBankManager::sm_soundBank_Tree.mTree.mCount )
        goto LABEL_14;
    }
    v2 = 0i64;
LABEL_10:
    v3 = 0i64;
    goto LABEL_11;
  }
LABEL_14:
  UFG::qTreeRB<UFG::SoundBankGroup,UFG::SoundBankGroup,1>::DeleteAll(&UFG::SoundBankManager::sm_groups);
  while ( UFG::SoundBankManager::sm_sizes.mTree.mCount )
  {
    v4 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::SoundBankManager::sm_sizes);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::SoundBankManager::sm_sizes,
      &v4->mNode);
    UFG::qMemoryPool::Free(&g_AudioComponentPool, v4);
  }
}

// File Line: 492
// RVA: 0x14E6D0
void __fastcall UFG::SoundBankManager::UpdatePendingLoadCounts(float delta_sec)
{
  char v1; // al
  UFG::qList<UFG::SoundBank,UFG::SoundBankManagerBankList,0,0> *v2; // rcx
  char v3; // si
  int v4; // eax
  UFG::qList<UFG::SoundBank,UFG::SoundBankManagerBankList,0,0> *v5; // rbx
  UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *v6; // rax
  unsigned int v7; // edx
  unsigned int v8; // eax
  unsigned int v9; // edx
  UFG::qBaseTreeRB *v10; // rax
  __int64 v11; // rax

  UFG::SoundBankManager::sm_numPendingLoads = 0;
  UFG::SoundBankManager::sm_highestPriorityInPendingLoads = 0;
  UFG::SoundBankManager::sm_bytesRemainingToLoad = 0i64;
  v1 = ((__int64 (*)(void))UFG::TiDo::m_pInstance->vfptr->HighSpeedMode)();
  v2 = (UFG::qList<UFG::SoundBank,UFG::SoundBankManagerBankList,0,0> *)&UFG::SoundBankManager::sm_soundBanks.mNode.mNext[-3].mNext;
  v3 = v1;
  if ( &UFG::SoundBankManager::sm_soundBanks.mNode.mNext[-3].mNext != (UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> **)((char *)&UFG::SoundBankManager::sm_soundBanks - 40) )
  {
    do
    {
      v4 = (int)v2[7].mNode.mPrev;
      v5 = (UFG::qList<UFG::SoundBank,UFG::SoundBankManagerBankList,0,0> *)&v2[3].mNode.mPrev[-3].mNext;
      if ( !(v4 & 0xFFFFFFFA) && v4 != 1 && HIDWORD(v2[4].mNode.mNext) )
      {
        v6 = v2[7].mNode.mNext;
        v7 = (unsigned int)v2[5].mNode.mPrev;
        if ( v6 )
        {
          v8 = (unsigned int)v6[6].mPrev;
          if ( v8 > v7 )
            v7 = v8;
        }
        if ( v7 > 3 || !v3 )
        {
          v9 = (unsigned int)v2[4].mNode.mNext;
          ++UFG::SoundBankManager::sm_numPendingLoads;
          if ( v9 && (v10 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_sizes.mTree, v9)) != 0i64 )
            v11 = LODWORD(v10->mNULL.mParent);
          else
            v11 = 0i64;
          UFG::SoundBankManager::sm_bytesRemainingToLoad += v11;
        }
      }
      v2 = v5;
    }
    while ( v5 != (UFG::qList<UFG::SoundBank,UFG::SoundBankManagerBankList,0,0> *)((char *)&UFG::SoundBankManager::sm_soundBanks
                                                                                 - 40) );
  }
}

// File Line: 517
// RVA: 0x14DE20
void __fastcall UFG::SoundBankManager::Update(float delta_sec)
{
  int v1; // esi
  float v2; // xmm6_4
  UFG::SoundBank *v3; // rbx
  UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *v4; // r15
  int v5; // ebp
  signed __int64 v6; // rdi
  float v7; // xmm0_4
  bool v8; // cf
  UFG::SoundBank::LoadState v9; // eax
  char v10; // al
  UFG::SoundBank *v11; // rsi
  char *v12; // rdi
  char v13; // r12
  int v14; // eax
  signed __int64 v15; // r14
  __int64 v16; // rbp
  unsigned int v17; // ebx
  unsigned int v18; // ecx
  unsigned int v19; // ecx
  unsigned int v20; // ecx
  unsigned int v21; // edx
  UFG::qBaseTreeRB *v22; // rax
  __int64 v23; // rax
  UFG::SoundBankCategory *v24; // rax
  unsigned int v25; // ecx
  unsigned int v26; // eax
  UFG::SoundBankCategory *v27; // rax
  unsigned int v28; // ecx
  unsigned int v29; // eax

  v1 = 0;
  v2 = delta_sec;
  v3 = (UFG::SoundBank *)&UFG::SoundBankManager::sm_soundBanks.mNode.mNext[-3].mNext;
  v4 = (UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *)((char *)&UFG::SoundBankManager::sm_soundBanks - 40);
  v5 = 0;
  if ( &UFG::SoundBankManager::sm_soundBanks.mNode.mNext[-3].mNext != (UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> **)((char *)&UFG::SoundBankManager::sm_soundBanks - 40) )
  {
    do
    {
      v6 = (signed __int64)&v3->mNext[-3].mNext;
      if ( v3->m_loadState == 2 && !v3->m_count )
      {
        v7 = v2 + v3->m_unloadTimer;
        v8 = v7 < v3->m_unloadAfterTime;
        v3->m_unloadTimer = v7;
        if ( !v8 )
          UFG::SoundBankManager::UnloadBank(v3);
      }
      v9 = v3->m_loadState;
      if ( v9 == 3 )
        ++v5;
      if ( v9 == 1 )
        ++v1;
      v3 = (UFG::SoundBank *)v6;
    }
    while ( (UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *)v6 != v4 );
    if ( v1 > 0 || v5 > 0 )
    {
      UFG::SoundBankManager::UpdatePendingLoadCounts(v2);
      return;
    }
  }
  UFG::SoundBankManager::sm_numPendingLoads = 0;
  UFG::SoundBankManager::sm_highestPriorityInPendingLoads = 0;
  UFG::SoundBankManager::sm_bytesRemainingToLoad = 0i64;
  v10 = ((__int64 (*)(void))UFG::TiDo::m_pInstance->vfptr->HighSpeedMode)();
  v11 = 0i64;
  v12 = (char *)&UFG::SoundBankManager::sm_soundBanks.mNode.mNext[-3].mNext;
  v13 = v10;
  if ( (UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *)((char *)UFG::SoundBankManager::sm_soundBanks.mNode.mNext
                                                                  - 40) != v4 )
  {
    do
    {
      v14 = *((_DWORD *)v12 + 28);
      v15 = *((_QWORD *)v12 + 6) - 40i64;
      if ( !(v14 & 0xFFFFFFFA) && v14 != 1 && *((_DWORD *)v12 + 19) )
      {
        v16 = *((_QWORD *)v12 + 15);
        v17 = *((_DWORD *)v12 + 20);
        v18 = *((_DWORD *)v12 + 20);
        if ( v16 && *(_DWORD *)(v16 + 96) > v17 )
          v18 = *(_DWORD *)(v16 + 96);
        if ( v18 > 3 || !v13 )
        {
          v19 = *((_DWORD *)v12 + 20);
          if ( v16 && *(_DWORD *)(v16 + 96) > v17 )
            v19 = *(_DWORD *)(v16 + 96);
          if ( v19 > UFG::SoundBankManager::sm_highestPriorityInPendingLoads )
          {
            v20 = *((_DWORD *)v12 + 20);
            if ( v16 && *(_DWORD *)(v16 + 96) > v17 )
              v20 = *(_DWORD *)(v16 + 96);
            UFG::SoundBankManager::sm_highestPriorityInPendingLoads = v20;
          }
          v21 = *((_DWORD *)v12 + 18);
          ++UFG::SoundBankManager::sm_numPendingLoads;
          if ( v21 && (v22 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_sizes.mTree, v21)) != 0i64 )
            v23 = LODWORD(v22->mNULL.mParent);
          else
            v23 = 0i64;
          UFG::SoundBankManager::sm_bytesRemainingToLoad += v23;
          if ( v11 )
          {
            v24 = v11->m_category;
            v25 = v11->m_priority;
            if ( v24 )
            {
              v26 = v24->m_priority;
              if ( v26 > v25 )
                v25 = v26;
            }
            if ( v16 && *(_DWORD *)(v16 + 96) > v17 )
              v17 = *(_DWORD *)(v16 + 96);
            if ( v25 < v17 )
              v11 = (UFG::SoundBank *)v12;
          }
          else
          {
            v11 = (UFG::SoundBank *)v12;
          }
        }
      }
      v12 = (char *)v15;
    }
    while ( (UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *)v15 != v4 );
  }
  if ( UFG::SoundBankManager::sm_enableLoads )
  {
    if ( !v11 )
      return;
LABEL_54:
    UFG::SoundBankManager::LoadBank(v11);
    return;
  }
  if ( v11 )
  {
    v27 = v11->m_category;
    v28 = v11->m_priority;
    if ( v27 )
    {
      v29 = v27->m_priority;
      if ( v29 > v28 )
        v28 = v29;
    }
    if ( v28 > 0xA )
      goto LABEL_54;
  }
}

// File Line: 627
// RVA: 0x143370
void __fastcall UFG::SoundBankManager::BankLoadCallback(unsigned int in_bankId, const void *in_pInMemoryBankPtr, AKRESULT in_eLoadResult, int in_memPoolId, void *in_pCookie)
{
  void *v5; // r11
  __int64 v6; // r10
  int v7; // edx
  int v8; // eax
  __int64 v9; // r8
  char v10; // al
  _QWORD *in_pCookiea; // [rsp+60h] [rbp+28h]

  v5 = in_pCookie;
  v6 = *(_QWORD *)in_pCookie;
  v7 = 0;
  if ( in_eLoadResult != 66 )
  {
    v8 = UFG::TiDo::sm_asyncFileCount - 1;
    if ( UFG::TiDo::sm_asyncFileCount - 1 < 0 )
      v8 = 0;
    UFG::TiDo::sm_asyncFileCount = v8;
  }
  if ( in_eLoadResult == 1 )
  {
    v9 = *(_QWORD *)in_pCookie;
    switch ( *((_DWORD *)in_pCookie + 4) )
    {
      case 1:
      case 3:
      case 5:
        *(_DWORD *)(v9 + 112) = 2;
        break;
      case 2:
      case 4:
      case 6:
        *(_DWORD *)(v9 + 112) = 0;
        break;
      default:
        break;
    }
  }
  else
  {
    if ( in_eLoadResult == 52 )
      UFG::SoundBankManager::sm_failedLoadBankId = in_bankId;
    *(_DWORD *)(v6 + 112) = 6;
  }
  if ( *(_DWORD *)(v6 + 112) == 6 )
  {
    v10 = *(_BYTE *)(v6 + 128);
    if ( v10 & 1 )
    {
      if ( v10 & 2 )
      {
LABEL_18:
        LOBYTE(v7) = (v10 & 1) != 0;
        *(_DWORD *)(v6 + 112) = v7 + 4;
        goto LABEL_19;
      }
      if ( in_memPoolId != -1 )
        *(_DWORD *)(v6 + 112) = 5;
    }
    if ( v10 & 2 )
      goto LABEL_18;
  }
LABEL_19:
  in_pCookiea = (char *)in_pCookie + 8;
  *in_pCookiea = &UFG::WwiseCallbackOperation::`vftable;
  in_pCookiea[2] = &UFG::AudioEventInfo::`vftable;
  operator delete[](v5);
}

// File Line: 743
// RVA: 0x145C30
__int64 __fastcall UFG::SoundBankManager::GetBytesRemainingToLoad()
{
  return (unsigned int)UFG::SoundBankManager::sm_bytesRemainingToLoad;
}

// File Line: 750
// RVA: 0x142D60
bool __fastcall UFG::SoundBankManager::AreAllImportantBankLoadsComplete()
{
  UFG::SoundBankManager::UpdatePendingLoadCounts(1.0);
  return UFG::SoundBankManager::sm_highestPriorityInPendingLoads < 7;
}

// File Line: 780
// RVA: 0x14AE00
char __fastcall UFG::SoundBankManager::QueueBankForLoad(UFG::qWiseSymbol *bankId)
{
  UFG::SoundBank *v1; // rax

  if ( bankId->mUID - 1 > 0xFFFFFFFD )
    return 0;
  v1 = UFG::SoundBankManager::FindOrCreateSoundBank(bankId);
  if ( !v1 )
    return 0;
  ++v1->m_count;
  return 1;
}

// File Line: 813
// RVA: 0x14AE30
void __fastcall UFG::SoundBankManager::QueueBankForUnload(UFG::qWiseSymbol *bankId)
{
  UFG::qBaseTreeRB *v1; // rax
  signed __int64 v2; // rcx
  int v3; // eax

  if ( bankId->mUID - 1 <= 0xFFFFFFFD )
  {
    v1 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, bankId->mUID);
    if ( v1 )
    {
      v2 = (signed __int64)&v1[-1].mCount;
      if ( v1 != (UFG::qBaseTreeRB *)8 )
      {
        v3 = *(_DWORD *)(v2 + 76);
        if ( v3 )
          *(_DWORD *)(v2 + 76) = v3 - 1;
      }
    }
  }
}

// File Line: 843
// RVA: 0x147E80
char __fastcall UFG::SoundBankManager::LoadBank(UFG::SoundBank *bank)
{
  UFG::SoundBank *v1; // rbx
  UFG::SoundBankGroup *v3; // rax
  int v4; // edi
  UFG::AkAsyncLoadCallbackCookie *v5; // rax
  UFG::AkAsyncLoadCallbackCookie *v6; // rsi
  unsigned int v7; // ebx
  UFG::WwiseCallbackOperation *v8; // [rsp+48h] [rbp+10h]

  v1 = bank;
  if ( bank && !bank->mNode.mUID )
    return 0;
  v3 = bank->m_group;
  if ( !v3 || (v4 = v3->poolId, v4 == -1) )
    v4 = UFG::SoundBankFragFreePool::FindBestFitPoolForBank(bank);
  v1->m_idealPoolId = v4;
  if ( v1->m_loadState == 5 )
    v4 = -1;
  v1->m_poolId = v4;
  v5 = (UFG::AkAsyncLoadCallbackCookie *)UFG::qMalloc(0x48ui64, "SoundBankManager.LoadBank.AsyncLoadCookie", 0i64);
  v6 = v5;
  if ( v5 )
  {
    v8 = &v5->op;
    v8->vfptr = (UFG::WwiseCallbackOperationVtbl *)&UFG::WwiseCallbackOperation::`vftable;
    v8->eventInfo.vfptr = (UFG::AudioEventInfoVtbl *)&UFG::AudioEventInfo::`vftable;
    v8->eventInfo.eventId = 0;
    v8->eventInfo.objectId = 0i64;
    v8->eventInfo.flags = 0;
    v8->eventInfo.callbackFun = 0i64;
    v8->eventInfo.pUserData = 0i64;
    *(_QWORD *)&v8->op = 0i64;
    v5->pUserData = 0i64;
  }
  else
  {
    v6 = 0i64;
  }
  v6->op.op = 1;
  v6->pUserData = v1;
  v1->m_loadState = 1;
  v7 = v1->m_name.mUID;
  if ( (unsigned __int8)AK::SoundEngine::IsInitialized() )
  {
    if ( !UFG::WwiseInterface::smShuttingDown )
      AK::SoundEngine::LoadBank(v7, UFG::SoundBankManager::BankLoadCallback, v6, v4);
  }
  ++UFG::TiDo::sm_asyncFileCount;
  return 1;
}

// File Line: 891
// RVA: 0x14CE70
char __fastcall UFG::SoundBankManager::UnloadBank(UFG::SoundBank *bank)
{
  UFG::SoundBank *v1; // rbx
  char *v2; // rax
  char *v3; // rdi
  unsigned int v4; // ebx
  signed __int64 v6; // [rsp+48h] [rbp+10h]

  v1 = bank;
  if ( bank && bank->m_loadState == 2 )
  {
    v2 = UFG::qMalloc(0x48ui64, "SoundBankManager.UnloadBank.AsyncLoadCookie", 0i64);
    v3 = v2;
    if ( v2 )
    {
      v6 = (signed __int64)(v2 + 8);
      *(_QWORD *)v6 = &UFG::WwiseCallbackOperation::`vftable;
      *(_QWORD *)(v6 + 16) = &UFG::AudioEventInfo::`vftable;
      *(_DWORD *)(v6 + 24) = 0;
      *(_QWORD *)(v6 + 32) = 0i64;
      *(_DWORD *)(v6 + 40) = 0;
      *(_QWORD *)(v6 + 48) = 0i64;
      *(_QWORD *)(v6 + 56) = 0i64;
      *(_QWORD *)(v6 + 8) = 0i64;
      *(_QWORD *)v2 = 0i64;
    }
    else
    {
      v3 = 0i64;
    }
    *((_DWORD *)v3 + 4) = 2;
    v1->m_loadState = 3;
    *(_QWORD *)v3 = v1;
    v1->m_unloadTimer = 0.0;
    v4 = v1->m_name.mUID;
    if ( (unsigned __int8)AK::SoundEngine::IsInitialized() )
      AK::SoundEngine::UnloadBank(v4, 0i64, UFG::SoundBankManager::BankLoadCallback, v3);
  }
  return 1;
}

// File Line: 938
// RVA: 0x1434F0
bool __fastcall UFG::SoundBankManager::BankLoaded(UFG::qWiseSymbol *bankId)
{
  UFG::qBaseTreeRB *v1; // rax
  signed __int64 v2; // rax
  bool result; // al

  result = 0;
  if ( bankId->mUID )
  {
    v1 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, bankId->mUID);
    if ( v1 )
    {
      v2 = (signed __int64)&v1[-1].mCount;
      if ( v2 )
      {
        if ( *(_DWORD *)(v2 + 112) == 2 )
          result = 1;
      }
    }
  }
  return result;
}

// File Line: 989
// RVA: 0x1434B0
bool __fastcall UFG::SoundBankManager::BankLoadRequested(UFG::qWiseSymbol *bankId)
{
  UFG::qBaseTreeRB *v1; // rax
  bool result; // al

  if ( bankId->mUID
    && (v1 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, bankId->mUID)) != 0i64
    && v1 != (UFG::qBaseTreeRB *)8 )
  {
    result = *(&v1->mCount + 1) != 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 1006
// RVA: 0x143470
bool __fastcall UFG::SoundBankManager::BankLoadRequestFinished(UFG::qWiseSymbol *bankId)
{
  UFG::qBaseTreeRB *v1; // rax
  signed __int64 v2; // rax
  bool result; // al

  if ( bankId->mUID
    && (v1 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, bankId->mUID)) != 0i64
    && (v2 = (signed __int64)&v1[-1].mCount) != 0 )
  {
    result = ((*(_DWORD *)(v2 + 112) - 2) & 0xFFFFFFFB) == 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

// File Line: 1029
// RVA: 0x143590
bool __fastcall UFG::SoundBankManager::BankLoadedOrLoading(UFG::qWiseSymbol *bankId)
{
  UFG::qWiseSymbol *v1; // rbx
  UFG::qBaseTreeRB *v2; // rax
  signed __int64 v3; // rax
  UFG::qBaseTreeRB *v4; // rax
  signed __int64 v5; // rax
  int v6; // eax
  bool result; // al

  v1 = bankId;
  result = 1;
  if ( !bankId->mUID
    || (v2 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, bankId->mUID)) == 0i64
    || (v3 = (signed __int64)&v2[-1].mCount) == 0
    || *(_DWORD *)(v3 + 112) != 2 )
  {
    if ( !v1->mUID
      || (v4 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, v1->mUID)) == 0i64
      || (v5 = (signed __int64)&v4[-1].mCount) == 0
      || (v6 = *(_DWORD *)(v5 + 112), v6 != 1) && (unsigned int)(v6 - 4) > 1 )
    {
      result = 0;
    }
  }
  return result;
}

// File Line: 1038
// RVA: 0x148C70
char __fastcall UFG::SoundBankManager::LoadGroup(const char *group)
{
  const char *v1; // rbx
  unsigned int v2; // eax
  UFG::SoundBankGroup *v3; // rax
  unsigned int *v4; // rdi
  UFG::qWiseSymbol *v5; // rbx
  UFG::SoundBank *v6; // rax

  v1 = group;
  if ( !(unsigned int)UFG::qStringLength(group) )
    return 0;
  v2 = AK::SoundEngine::GetIDFromString(v1);
  if ( !v2 )
    return 0;
  v3 = (UFG::SoundBankGroup *)UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_groups.mTree, v2);
  if ( !v3 )
    return 0;
  v4 = &v3->nameId;
  v5 = (UFG::qWiseSymbol *)&v3->soundBanks.mNode.mNext[-4].mNext;
  if ( v5 != (UFG::qWiseSymbol *)&v3->nameId )
  {
    do
    {
      if ( v5[18].mUID - 1 <= 0xFFFFFFFD )
      {
        v6 = UFG::SoundBankManager::FindOrCreateSoundBank(v5 + 18);
        if ( v6 )
          ++v6->m_count;
      }
      v5 = (UFG::qWiseSymbol *)(*(_QWORD *)&v5[16].mUID - 56i64);
    }
    while ( v5 != (UFG::qWiseSymbol *)v4 );
  }
  return 1;
}

// File Line: 1120
// RVA: 0x14D050
char __fastcall UFG::SoundBankManager::UnloadGroup(const char *group)
{
  const char *v1; // rbx
  unsigned int v2; // eax
  UFG::qBaseTreeRB *v3; // rax
  signed __int64 v4; // rdi
  signed __int64 v5; // rbx
  unsigned int v6; // edx
  UFG::qBaseTreeRB *v7; // rax
  signed __int64 v8; // rcx
  int v9; // eax

  v1 = group;
  if ( !(unsigned int)UFG::qStringLength(group) )
    return 0;
  v2 = AK::SoundEngine::GetIDFromString(v1);
  if ( !v2 )
    return 0;
  v3 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_groups.mTree, v2);
  if ( !v3 )
    return 0;
  v4 = (signed __int64)&v3->mNULL;
  v5 = *(_QWORD *)&v3[1].mRoot.mUID - 56i64;
  if ( (UFG::qBaseNodeRB *)v5 != &v3->mNULL )
  {
    do
    {
      v6 = *(_DWORD *)(v5 + 72);
      if ( v6 - 1 <= 0xFFFFFFFD )
      {
        v7 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, v6);
        if ( v7 )
        {
          v8 = (signed __int64)&v7[-1].mCount;
          if ( v7 != (UFG::qBaseTreeRB *)8 )
          {
            v9 = *(_DWORD *)(v8 + 76);
            if ( v9 )
              *(_DWORD *)(v8 + 76) = v9 - 1;
          }
        }
      }
      v5 = *(_QWORD *)(v5 + 64) - 56i64;
    }
    while ( v5 != v4 );
  }
  return 1;
}

// File Line: 1141
// RVA: 0x148170
char __fastcall UFG::SoundBankManager::LoadBankSymbols(bool keepStrings)
{
  bool v1; // bp
  SimpleXML::XMLDocument *v2; // rax
  SimpleXML::XMLDocument *v3; // rdi
  SimpleXML::XMLNode *v4; // rax
  SimpleXML::XMLNode *i; // rsi
  char *v6; // rax
  SimpleXML::XMLNode *j; // rbx
  char *v8; // rax
  UFG::qString v10; // [rsp+28h] [rbp-30h]

  v1 = keepStrings;
  UFG::qString::qString(&v10, "Data\\Global\\Act\\AudioTag.xml");
  v2 = SimpleXML::XMLDocument::Open(v10.mData, 1ui64, 0i64);
  v3 = v2;
  if ( v2 )
  {
    v4 = SimpleXML::XMLDocument::GetChildNode(v2, 0i64, 0i64);
    if ( v4 )
    {
      for ( i = SimpleXML::XMLDocument::GetChildNode(v3, 0i64, v4); i; i = SimpleXML::XMLDocument::GetNode(v3, 0i64, i) )
      {
        v6 = SimpleXML::XMLNode::GetName(i);
        if ( !(unsigned int)UFG::qStringCompare(v6, "SoundBankType", -1)
          && (signed int)SimpleXML::XMLNode::GetChildCount(i) > 0 )
        {
          for ( j = SimpleXML::XMLDocument::GetChildNode(v3, 0i64, i); j; j = SimpleXML::XMLDocument::GetNode(
                                                                                v3,
                                                                                0i64,
                                                                                j) )
          {
            v8 = SimpleXML::XMLNode::GetName(j);
            if ( !(unsigned int)UFG::qStringCompare(v8, "SoundBank", -1) )
              UFG::SoundBankManager::LoadBankSymbols_::_2_::Local::AddNodeToRegistry(j, v1);
          }
        }
      }
    }
    SimpleXML::XMLDocument::~XMLDocument(v3);
    operator delete[](v3);
  }
  UFG::qString::~qString(&v10);
  return 1;
}

// File Line: 1148
// RVA: 0x142920
void __fastcall UFG::SoundBankManager::LoadBankSymbols_::_2_::Local::AddNodeToRegistry(SimpleXML::XMLNode *node, bool keepStrings)
{
  SimpleXML::XMLNode *v2; // rbx
  unsigned int v3; // edi
  char *v4; // rbx
  UFG::qString *v5; // rax
  UFG::SoundBank *v6; // rbx
  UFG::qString *v7; // rax
  UFG::SoundBankCategory *v8; // rax
  UFG::qString text; // [rsp+38h] [rbp-60h]
  UFG::qString result; // [rsp+60h] [rbp-38h]
  UFG::qWiseSymbol bankId; // [rsp+B0h] [rbp+18h]
  UFG::qString *v12; // [rsp+B8h] [rbp+20h]

  v2 = node;
  v3 = SimpleXML::XMLNode::GetAttribute(node, "id", 0);
  v4 = SimpleXML::XMLNode::GetAttribute(v2, "name");
  UFG::qString::qString(&text, v4);
  v5 = UFG::qString::ToLower(&text, &result);
  UFG::qString::Set(&text, v5->mData, v5->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  if ( (unsigned int)UFG::qStringCompare(v4, "none", -1) )
  {
    _((AMD_HD3D *)v3);
    UFG::qWiseSymbol::create_from_string(&bankId, v4);
    if ( bankId.mUID )
      UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, bankId.mUID);
    v6 = UFG::SoundBankManager::FindOrCreateSoundBank(&bankId);
    v12 = &result;
    UFG::qString::qString(&result, &text);
    v8 = UFG::SoundBankCategory::FindMatchingCategoryForSoundBank(v7);
    if ( v8 )
      v6->m_category = v8;
    _((AMD_HD3D *)bankId.mUID);
  }
  UFG::qString::~qString(&text);
}

// File Line: 1230
// RVA: 0x147F90
char __fastcall UFG::SoundBankManager::LoadBankSizes()
{
  SimpleXML::XMLDocument *v0; // rax
  SimpleXML::XMLDocument *v1; // rbp
  SimpleXML::XMLNode *i; // r14
  SimpleXML::XMLNode *j; // rsi
  char *v4; // rbx
  unsigned int v5; // edi
  UFG::qBaseTreeRB *v6; // rax
  char *v7; // rbx
  int v8; // eax
  AMD_HD3D *v10; // [rsp+80h] [rbp+8h]
  UFG::qWiseSymbol result; // [rsp+88h] [rbp+10h]
  char *v12; // [rsp+90h] [rbp+18h]
  AMD_HD3D **v13; // [rsp+98h] [rbp+20h]

  v0 = SimpleXML::XMLDocument::Open("Data\\Audio\\Soundbanksizes.xml", 1ui64, 0i64);
  v1 = v0;
  if ( v0 )
  {
    for ( i = SimpleXML::XMLDocument::GetNode(v0, 0i64, 0i64); i; i = SimpleXML::XMLDocument::GetNode(v1, 0i64, i) )
    {
      for ( j = SimpleXML::XMLDocument::GetChildNode(v1, 0i64, i); j; j = SimpleXML::XMLDocument::GetNode(v1, 0i64, j) )
      {
        v4 = SimpleXML::XMLNode::GetAttribute(j, "name");
        v5 = SimpleXML::XMLNode::GetAttribute(j, "size", 0);
        if ( v5 )
        {
          UFG::qWiseSymbol::create_from_string(&result, v4);
          if ( result.mUID && (v6 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_sizes.mTree, result.mUID)) != 0i64 )
          {
            if ( LODWORD(v6->mNULL.mParent) > v5 )
              v5 = (unsigned int)v6->mNULL.mParent;
            LODWORD(v6->mNULL.mParent) = v5;
          }
          else
          {
            v7 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x28ui64, "BankMgr.BankSize", 0i64, 1u);
            v12 = v7;
            if ( v7 )
            {
              v13 = &v10;
              LODWORD(v10) = result;
              _((AMD_HD3D *)result.mUID);
              v8 = (signed int)v10;
              *(_QWORD *)v7 = 0i64;
              *((_QWORD *)v7 + 1) = 0i64;
              *((_QWORD *)v7 + 2) = 0i64;
              *((_DWORD *)v7 + 6) = v8;
              *((_DWORD *)v7 + 8) = v5;
              _((AMD_HD3D *)(unsigned int)v10);
            }
            else
            {
              v7 = 0i64;
            }
            UFG::qBaseTreeRB::Add(&UFG::SoundBankManager::sm_sizes.mTree, (UFG::qBaseNodeRB *)v7);
          }
          _((AMD_HD3D *)result.mUID);
        }
      }
    }
    SimpleXML::XMLDocument::~XMLDocument(v1);
    operator delete[](v1);
  }
  return 1;
}

// File Line: 1433
// RVA: 0x1458E0
UFG::SoundBank *__fastcall UFG::SoundBankManager::FindOrCreateSoundBank(UFG::qWiseSymbol *bankId)
{
  UFG::qWiseSymbol *v1; // rbx
  UFG::qBaseTreeRB *v2; // rax
  UFG::SoundBank *result; // rax
  char *v4; // rax
  UFG::qBaseNodeRB *v5; // rdi
  UFG::SoundBank *v6; // rax
  UFG::SoundBank *v7; // rbx
  UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *v8; // rdx
  UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *v9; // rcx

  v1 = bankId;
  if ( !bankId->mUID
    || (v2 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, bankId->mUID)) == 0i64
    || (result = (UFG::SoundBank *)&v2[-1].mCount) == 0i64 )
  {
    v4 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x88ui64, "BankMgr.Bank", 0i64, 1u);
    v5 = 0i64;
    if ( v4 )
    {
      UFG::SoundBank::SoundBank((UFG::SoundBank *)v4, v1, 5u);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    if ( v7 )
      v5 = &v7->mNode;
    UFG::qBaseTreeRB::Add(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, v5);
    v8 = (UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *)&v7->mPrev;
    v9 = UFG::SoundBankManager::sm_soundBanks.mNode.mPrev;
    UFG::SoundBankManager::sm_soundBanks.mNode.mPrev->mNext = (UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *)&v7->mPrev;
    v8->mPrev = v9;
    v8->mNext = (UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *)&UFG::SoundBankManager::sm_soundBanks;
    UFG::SoundBankManager::sm_soundBanks.mNode.mPrev = (UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *)&v7->mPrev;
    result = v7;
  }
  return result;
}

// File Line: 1474
// RVA: 0x145860
UFG::qBaseTreeRB *__fastcall UFG::SoundBankManager::FindOrCreateGroup(unsigned int groupId)
{
  unsigned int v1; // ebx
  UFG::qBaseTreeRB *result; // rax
  char *v3; // rax
  UFG::qBaseTreeRB *v4; // rax
  UFG::qBaseTreeRB *v5; // rbx

  v1 = groupId;
  if ( !groupId || (result = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_groups.mTree, groupId)) == 0i64 )
  {
    v3 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x68ui64, "BankMgr.Location", 0i64, 1u);
    if ( v3 )
    {
      UFG::SoundBankGroup::SoundBankGroup((UFG::SoundBankGroup *)v3, v1);
      v5 = v4;
    }
    else
    {
      v5 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&UFG::SoundBankManager::sm_groups.mTree, &v5->mRoot);
    result = v5;
  }
  return result;
}

// File Line: 1598
// RVA: 0x1408B0
void __fastcall UFG::SoundBank::SoundBank(UFG::SoundBank *this, UFG::qWiseSymbol *bankId, unsigned int priority)
{
  unsigned int v3; // ebx
  UFG::SoundBank *v4; // rdi
  unsigned int v5; // eax
  UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *v6; // rax
  UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList> *v7; // rax
  AMD_HD3D *v8; // rcx

  v3 = priority;
  v4 = this;
  v5 = bankId->mUID;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v5;
  v6 = (UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *)&this->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  v7 = (UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList> *)&this->mPrev;
  v7->mPrev = v7;
  v7->mNext = v7;
  this->vfptr = (UFG::SoundBankVtbl *)&UFG::SoundBank::`vftable;
  v8 = (AMD_HD3D *)bankId->mUID;
  v4->m_name.mUID = (unsigned int)v8;
  _(v8);
  v4->m_count = 0;
  v4->m_priority = v3;
  *(_QWORD *)&v4->m_unloadTimer = 0i64;
  *(_QWORD *)&v4->m_poolId = 0i64;
  v4->m_group = 0i64;
  v4->m_loadState = 0;
  v4->m_category = 0i64;
  *((_BYTE *)v4 + 128) = *((_BYTE *)v4 + 128) & 0xF9 | 1;
}

