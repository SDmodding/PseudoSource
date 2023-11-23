// File Line: 41
// RVA: 0x1465430
__int64 dynamic_initializer_for__Global__()
{
  Global.mUID = UFG::qWiseSymbolUIDFromString("Global", 0x811C9DC5);
  _((AMD_HD3D *)Global.mUID);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Global__);
}

// File Line: 60
// RVA: 0x1465370
__int64 dynamic_initializer_for__UFG::SoundBankManager::sm_soundBanks__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SoundBankManager::sm_soundBanks__);
}

// File Line: 61
// RVA: 0x1465340
__int64 dynamic_initializer_for__UFG::SoundBankManager::sm_soundBank_Tree__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::SoundBankManager::sm_soundBank_Tree.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SoundBankManager::sm_soundBank_Tree__);
}

// File Line: 63
// RVA: 0x14651C0
__int64 dynamic_initializer_for__UFG::SoundBankManager::sm_groups__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::SoundBankManager::sm_groups.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SoundBankManager::sm_groups__);
}

// File Line: 64
// RVA: 0x1465310
__int64 dynamic_initializer_for__UFG::SoundBankManager::sm_sizes__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::SoundBankManager::sm_sizes.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SoundBankManager::sm_sizes__);
}

// File Line: 65
// RVA: 0x14650D0
__int64 dynamic_initializer_for__UFG::SoundBankManager::sm_bankFilterString__()
{
  UFG::qString::qString(&UFG::SoundBankManager::sm_bankFilterString, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SoundBankManager::sm_bankFilterString__);
}

// File Line: 90
// RVA: 0x1465100
__int64 dynamic_initializer_for__UFG::SoundBankCategory::sm_categories__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SoundBankCategory::sm_categories__);
}

// File Line: 93
// RVA: 0x140950
void __fastcall UFG::SoundBankCategory::SoundBankCategory(
        UFG::SoundBankCategory *this,
        const char *name,
        const char *categoryPrefix,
        unsigned int priority)
{
  __int64 v8; // rax
  __int64 v9; // rax
  UFG::qNode<UFG::SoundBankCategory,UFG::SoundBankCategory> *mPrev; // rax
  UFG::qString v11; // [rsp+38h] [rbp-40h] BYREF

  this->mPrev = this;
  this->mNext = this;
  UFG::qString::qString(&this->m_categoryName);
  UFG::qString::qString(&this->m_categoryPrefix);
  UFG::qString::qString(&v11, name);
  UFG::qString::Set(&this->m_categoryName, *(const char **)(v8 + 24), *(_DWORD *)(v8 + 20), 0i64, 0);
  UFG::qString::~qString(&v11);
  UFG::qString::qString(&v11, categoryPrefix);
  UFG::qString::Set(&this->m_categoryPrefix, *(const char **)(v9 + 24), *(_DWORD *)(v9 + 20), 0i64, 0);
  UFG::qString::~qString(&v11);
  UFG::qString::MakeLower(&this->m_categoryPrefix);
  this->m_priority = priority;
  mPrev = UFG::SoundBankCategory::sm_categories.mNode.mPrev;
  UFG::SoundBankCategory::sm_categories.mNode.mPrev->mNext = this;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::SoundBankCategory,UFG::SoundBankCategory> *)&UFG::SoundBankCategory::sm_categories;
  UFG::SoundBankCategory::sm_categories.mNode.mPrev = this;
}

// File Line: 104
// RVA: 0x1456C0
UFG::SoundBankCategory *__fastcall UFG::SoundBankCategory::FindMatchingCategoryForSoundBank(UFG::qString *bankName)
{
  UFG::SoundBankCategory *v2; // rdi
  UFG::SoundBankCategory *i; // rbx
  UFG::qString v5; // [rsp+28h] [rbp-30h] BYREF

  UFG::qString::ToLower(bankName, &v5);
  v2 = 0i64;
  for ( i = (UFG::SoundBankCategory *)UFG::SoundBankCategory::sm_categories.mNode.mNext;
        i != (UFG::SoundBankCategory *)&UFG::SoundBankCategory::sm_categories;
        i = (UFG::SoundBankCategory *)i->mNext )
  {
    if ( (unsigned int)UFG::qString::StartsWith(&v5, i->m_categoryPrefix.mData, -1)
      && (!v2 || i->m_categoryName.mLength > v2->m_categoryName.mLength) )
    {
      v2 = i;
    }
  }
  UFG::qString::~qString(&v5);
  UFG::qString::~qString(bankName);
  return v2;
}

// File Line: 141
// RVA: 0x14652E0
__int64 dynamic_initializer_for__UFG::SoundBankFragFreePool::sm_pools__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::SoundBankFragFreePool::sm_pools.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SoundBankFragFreePool::sm_pools__);
}

// File Line: 160
// RVA: 0x145410
signed __int64 __fastcall UFG::SoundBankFragFreePool::FindBestFitPoolForBank(UFG::SoundBank *bank)
{
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v3; // rax
  UFG::qBaseTreeRB *Head; // rbx
  unsigned int v5; // edx
  __int64 mParent_high; // rdi
  UFG::qBaseTreeRB *v7; // rax
  __int64 mParent_low; // rcx

  mUID = bank->m_name.mUID;
  if ( !mUID )
    return 0xFFFFFFFFi64;
  v3 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_sizes.mTree, mUID);
  if ( !v3 || !LODWORD(v3->mNULL.mParent) )
    return 0xFFFFFFFFi64;
  Head = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::SoundBankFragFreePool::sm_pools);
  if ( !Head )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    v5 = bank->m_name.mUID;
    mParent_high = HIDWORD(Head[1].mRoot.mParent);
    if ( v5 && (v7 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_sizes.mTree, v5)) != 0i64 )
      mParent_low = LODWORD(v7->mNULL.mParent);
    else
      mParent_low = 0i64;
    if ( mParent_high >= mParent_low )
      break;
    Head = UFG::qBaseTreeRB::GetNext(&UFG::SoundBankFragFreePool::sm_pools.mTree, &Head->mRoot);
    if ( !Head )
      return 0xFFFFFFFFi64;
  }
  return LODWORD(Head[1].mRoot.mChild[0]);
}

// File Line: 264
// RVA: 0x146E00
void UFG::SoundBankManager::Init(void)
{
  Render::SkinningCacheNode *Head; // rax
  Illusion::Buffer **p_mCachedBufferPtr; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNode; // rdx

  if ( UFG::SoundBankManager::sm_soundBank_Tree.mTree.mCount )
  {
    while ( 1 )
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::SoundBankManager::sm_soundBank_Tree);
      if ( !Head )
        break;
      p_mCachedBufferPtr = &Head[-1].mCachedBufferPtr;
      if ( Head == (Render::SkinningCacheNode *)8 )
        goto LABEL_6;
      p_mNode = &Head->mNode;
LABEL_7:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::SoundBankManager::sm_soundBank_Tree,
        p_mNode);
      if ( p_mCachedBufferPtr )
        ((void (__fastcall *)(Illusion::Buffer **, __int64))(*p_mCachedBufferPtr)->mNode.mParent)(
          p_mCachedBufferPtr,
          1i64);
      if ( !UFG::SoundBankManager::sm_soundBank_Tree.mTree.mCount )
        goto LABEL_10;
    }
    p_mCachedBufferPtr = 0i64;
LABEL_6:
    p_mNode = 0i64;
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
  __int64 j; // rbx
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax
  unsigned __int64 mParent_low; // rcx
  __int64 v7; // rbx
  __int64 k; // rbx
  unsigned int v9; // edx
  UFG::qBaseTreeRB *v10; // rax
  int mParent; // eax
  unsigned int v12; // edi
  int Pool; // eax

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
          mParent_low = LODWORD(v5->mNULL.mParent);
        else
          mParent_low = 0i64;
        v7 = *(_QWORD *)(j + 64);
        if ( mParent_low > v2 )
          v2 = mParent_low;
      }
    }
    if ( HIDWORD(i->mNULL.mChild[0]) == 3 )
    {
      for ( k = *(_QWORD *)&i[1].mRoot.mUID - 56i64; (UFG::qBaseNodeRB *)k != &i->mNULL; k = *(_QWORD *)(k + 64) - 56i64 )
      {
        v9 = *(_DWORD *)(k + 72);
        if ( v9 && (v10 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_sizes.mTree, v9)) != 0i64 )
          mParent = (int)v10->mNULL.mParent;
        else
          mParent = 0;
        v2 += mParent;
      }
    }
    if ( HIDWORD(i->mNULL.mChild[0]) == 4 )
      HIDWORD(i->mNULL.mParent) = -1;
    if ( v2 )
    {
      v12 = v2 + 0x4000;
      Pool = AK::MemoryMgr::CreatePool(0i64, v12, 1u, 1u, 0x800u);
      LODWORD(i->mNULL.mChild[0]) = v12;
      HIDWORD(i->mNULL.mParent) = Pool;
    }
  }
}

// File Line: 336
// RVA: 0x147310
void __fastcall UFG::SoundBankManager::InitGroup(SimpleXML::XMLDocument *doc, SimpleXML::XMLNode *groupNode)
{
  char *Attribute; // rbx
  unsigned int IDFromString; // eax
  UFG::qBaseTreeRB *Group; // rbp
  __int64 v7; // rax
  char *v8; // rax
  unsigned int v9; // eax
  SimpleXML::XMLNode *i; // rsi
  char *Name; // rax
  char *v12; // rbx
  unsigned int v13; // edi
  double v14; // xmm0_8
  UFG::SoundBank *v15; // rbx
  char *v16; // rax
  UFG::qString *v17; // rax
  UFG::SoundBankCategory *MatchingCategoryForSoundBank; // rdi
  UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList> *v19; // rax
  UFG::qString text; // [rsp+38h] [rbp-80h] BYREF
  UFG::qString v21; // [rsp+60h] [rbp-58h] BYREF
  UFG::qWiseSymbol result; // [rsp+D0h] [rbp+18h] BYREF
  UFG::qString *v23; // [rsp+D8h] [rbp+20h]

  Attribute = SimpleXML::XMLNode::GetAttribute(groupNode, "name");
  IDFromString = UFG::qStringLength(Attribute);
  if ( IDFromString )
    IDFromString = AK::SoundEngine::GetIDFromString(Attribute);
  Group = UFG::SoundBankManager::FindOrCreateGroup(IDFromString);
  UFG::qString::qString(&text, Attribute);
  UFG::qString::Set((UFG::qString *)&Group->mNULL.mChild[1], *(const char **)(v7 + 24), *(_DWORD *)(v7 + 20), 0i64, 0);
  UFG::qString::~qString(&text);
  v8 = SimpleXML::XMLNode::GetAttribute(groupNode, "poolSize");
  if ( !(unsigned int)UFG::qStringCompare(v8, "SizeOf_LargestBank", -1) )
    HIDWORD(Group->mNULL.mChild[0]) = 1;
  v9 = SimpleXML::XMLNode::GetAttribute(groupNode, "poolSize", 0);
  if ( v9 )
  {
    HIDWORD(Group->mNULL.mChild[0]) = 2;
    LODWORD(Group->mNULL.mChild[0]) = v9;
  }
  UFG::qStringCompare(Attribute, "Global", -1);
  for ( i = SimpleXML::XMLDocument::GetChildNode(doc, 0i64, groupNode); i; i = SimpleXML::XMLDocument::GetNode(
                                                                                 doc,
                                                                                 0i64,
                                                                                 i) )
  {
    Name = SimpleXML::XMLNode::GetName(i);
    if ( !(unsigned int)UFG::qStringCompare(Name, "Bank", -1) )
    {
      v12 = SimpleXML::XMLNode::GetAttribute(i, "name");
      v13 = SimpleXML::XMLNode::GetAttribute(i, "priority", 5u);
      v14 = SimpleXML::XMLNode::GetAttribute(i, "unload_timer", 0.0);
      UFG::qWiseSymbol::create_from_string(&result, v12);
      v15 = UFG::SoundBankManager::FindOrCreateSoundBank(&result);
      v15->m_unloadAfterTime = *(float *)&v14;
      v15->m_group = (UFG::SoundBankGroup *)Group;
      v15->m_priority = v13;
      v16 = SimpleXML::XMLNode::GetAttribute(i, "category", 0i64);
      if ( v16 )
      {
        UFG::qString::qString(&text, v16);
        v23 = &v21;
        UFG::qString::qString(&v21, &text);
        MatchingCategoryForSoundBank = UFG::SoundBankCategory::FindMatchingCategoryForSoundBank(v17);
        UFG::qString::~qString(&text);
        if ( MatchingCategoryForSoundBank )
          v15->m_category = MatchingCategoryForSoundBank;
      }
      v19 = (UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList> *)Group[1].mRoot.mChild[1];
      v19->mNext = &v15->UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList>;
      v15->UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList>::mPrev = v19;
      v15->UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList>::mNext = (UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList> *)&Group[1].mRoot.mChild[1];
      Group[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)&v15->UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList>;
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
  char *Name; // r12
  SimpleXML::XMLNode *k; // rbx
  char *v6; // rax
  char *Attribute; // rdi
  char *v8; // rsi
  unsigned int v9; // ebp
  char *v10; // rax
  SimpleXML::XMLNode *m; // rbx
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
        Name = SimpleXML::XMLNode::GetName(j);
        SimpleXML::XMLNode::GetAttribute(j, "name");
        if ( !(unsigned int)UFG::qStringCompare(Name, "Categories", -1) )
        {
          for ( k = SimpleXML::XMLDocument::GetChildNode(v1, 0i64, j); k; k = SimpleXML::XMLDocument::GetNode(
                                                                                v1,
                                                                                0i64,
                                                                                k) )
          {
            v6 = SimpleXML::XMLNode::GetName(k);
            if ( !(unsigned int)UFG::qStringCompare(v6, "Category", -1) )
            {
              Attribute = SimpleXML::XMLNode::GetAttribute(k, "name");
              v8 = SimpleXML::XMLNode::GetAttribute(k, "prefix");
              v9 = SimpleXML::XMLNode::GetAttribute(k, "priority", 5u);
              v10 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x68ui64, "SoundBankGroup", 0i64, 1u);
              if ( v10 )
                UFG::SoundBankCategory::SoundBankCategory((UFG::SoundBankCategory *)v10, Attribute, v8, v9);
            }
          }
        }
        if ( !(unsigned int)UFG::qStringCompare(Name, "Pools", -1) )
        {
          for ( m = SimpleXML::XMLDocument::GetChildNode(v1, 0i64, j); m; m = SimpleXML::XMLDocument::GetNode(
                                                                                v1,
                                                                                0i64,
                                                                                m) )
          {
            v12 = SimpleXML::XMLNode::GetName(m);
            if ( !(unsigned int)UFG::qStringCompare(v12, "Pool", -1) )
            {
              SimpleXML::XMLNode::GetAttribute(m, "name");
              v13 = SimpleXML::XMLNode::GetAttribute(m, "slotSize", 0);
              v14 = SimpleXML::XMLNode::GetAttribute(m, "numSlots", 0);
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
        if ( !(unsigned int)UFG::qStringCompare(Name, "Group", -1) )
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
  Render::SkinningCacheNode *Head; // rax
  Illusion::Buffer **p_mCachedBufferPtr; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNode; // rdx
  Render::SkinningCacheNode *v4; // rbx

  while ( UFG::SoundBankManager::sm_numPendingLoads )
  {
    UFG::qFileService(a1);
    UFG::SoundBankManager::Update(1.0);
  }
  if ( AK::SoundEngine::IsInitialized() )
    AK::SoundEngine::ClearBanks();
  AK::SoundEngine::RenderAudio();
  if ( UFG::SoundBankManager::sm_soundBank_Tree.mTree.mCount )
  {
    while ( 1 )
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::SoundBankManager::sm_soundBank_Tree);
      if ( !Head )
        break;
      p_mCachedBufferPtr = &Head[-1].mCachedBufferPtr;
      if ( Head == (Render::SkinningCacheNode *)8 )
        goto LABEL_10;
      p_mNode = &Head->mNode;
LABEL_11:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::SoundBankManager::sm_soundBank_Tree,
        p_mNode);
      if ( p_mCachedBufferPtr )
        ((void (__fastcall *)(Illusion::Buffer **, __int64))(*p_mCachedBufferPtr)->mNode.mParent)(
          p_mCachedBufferPtr,
          1i64);
      if ( !UFG::SoundBankManager::sm_soundBank_Tree.mTree.mCount )
        goto LABEL_14;
    }
    p_mCachedBufferPtr = 0i64;
LABEL_10:
    p_mNode = 0i64;
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
  bool v1; // al
  UFG::qList<UFG::SoundBank,UFG::SoundBankManagerBankList,0,0> *p_mNext; // rcx
  bool v3; // si
  int mPrev; // eax
  UFG::qList<UFG::SoundBank,UFG::SoundBankManagerBankList,0,0> *v5; // rbx
  UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *mNext; // rax
  unsigned int v7; // edx
  unsigned int v8; // eax
  unsigned int v9; // edx
  UFG::qBaseTreeRB *v10; // rax
  __int64 mParent_low; // rax

  UFG::SoundBankManager::sm_numPendingLoads = 0;
  UFG::SoundBankManager::sm_highestPriorityInPendingLoads = 0;
  UFG::SoundBankManager::sm_bytesRemainingToLoad = 0i64;
  v1 = UFG::TiDo::m_pInstance->vfptr->HighSpeedMode(UFG::TiDo::m_pInstance);
  p_mNext = (UFG::qList<UFG::SoundBank,UFG::SoundBankManagerBankList,0,0> *)&UFG::SoundBankManager::sm_soundBanks.mNode.mNext[-3].mNext;
  v3 = v1;
  if ( &UFG::SoundBankManager::sm_soundBanks.mNode.mNext[-3].mNext != (UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> **)((char *)&UFG::SoundBankManager::sm_soundBanks - 40) )
  {
    do
    {
      mPrev = (int)p_mNext[7].mNode.mPrev;
      v5 = (UFG::qList<UFG::SoundBank,UFG::SoundBankManagerBankList,0,0> *)&p_mNext[3].mNode.mPrev[-3].mNext;
      if ( (mPrev & 0xFFFFFFFA) == 0 && mPrev != 1 && HIDWORD(p_mNext[4].mNode.mNext) )
      {
        mNext = p_mNext[7].mNode.mNext;
        v7 = (unsigned int)p_mNext[5].mNode.mPrev;
        if ( mNext )
        {
          v8 = (unsigned int)mNext[6].mPrev;
          if ( v8 > v7 )
            v7 = v8;
        }
        if ( v7 > 3 || !v3 )
        {
          v9 = (unsigned int)p_mNext[4].mNode.mNext;
          ++UFG::SoundBankManager::sm_numPendingLoads;
          if ( v9 && (v10 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_sizes.mTree, v9)) != 0i64 )
            mParent_low = LODWORD(v10->mNULL.mParent);
          else
            mParent_low = 0i64;
          UFG::SoundBankManager::sm_bytesRemainingToLoad += mParent_low;
        }
      }
      p_mNext = v5;
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
  UFG::SoundBank *p_mNext; // rbx
  UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *v4; // r15
  int v5; // ebp
  __int64 v6; // rdi
  float v7; // xmm0_4
  bool v8; // cf
  UFG::SoundBank::LoadState m_loadState; // eax
  char v10; // al
  UFG::SoundBank *v11; // rsi
  UFG::SoundBank *v12; // rdi
  char v13; // r12
  UFG::SoundBank::LoadState v14; // eax
  __int64 v15; // r14
  UFG::SoundBankCategory *m_category; // rbp
  unsigned int m_priority; // ebx
  unsigned int v18; // ecx
  unsigned int v19; // ecx
  unsigned int v20; // ecx
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v22; // rax
  __int64 mParent_low; // rax
  UFG::SoundBankCategory *v24; // rax
  unsigned int v25; // ecx
  unsigned int v26; // eax
  UFG::SoundBankCategory *v27; // rax
  unsigned int v28; // ecx
  unsigned int v29; // eax

  v1 = 0;
  p_mNext = (UFG::SoundBank *)&UFG::SoundBankManager::sm_soundBanks.mNode.mNext[-3].mNext;
  v4 = (UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *)((char *)&UFG::SoundBankManager::sm_soundBanks - 40);
  v5 = 0;
  if ( &UFG::SoundBankManager::sm_soundBanks.mNode.mNext[-3].mNext != (UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> **)((char *)&UFG::SoundBankManager::sm_soundBanks - 40) )
  {
    do
    {
      v6 = (__int64)&p_mNext->UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList>::mNext[-3].mNext;
      if ( p_mNext->m_loadState == LoadState_Loaded && !p_mNext->m_count )
      {
        v7 = delta_sec + p_mNext->m_unloadTimer;
        v8 = v7 < p_mNext->m_unloadAfterTime;
        p_mNext->m_unloadTimer = v7;
        if ( !v8 )
          UFG::SoundBankManager::UnloadBank(p_mNext);
      }
      m_loadState = p_mNext->m_loadState;
      if ( m_loadState == LoadState_Unloading )
        ++v5;
      if ( m_loadState == LoadState_Loading )
        ++v1;
      p_mNext = (UFG::SoundBank *)v6;
    }
    while ( (UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *)v6 != v4 );
    if ( v1 > 0 || v5 > 0 )
    {
      UFG::SoundBankManager::UpdatePendingLoadCounts(delta_sec);
      return;
    }
  }
  UFG::SoundBankManager::sm_numPendingLoads = 0;
  UFG::SoundBankManager::sm_highestPriorityInPendingLoads = 0;
  UFG::SoundBankManager::sm_bytesRemainingToLoad = 0i64;
  v10 = ((__int64 (*)(void))UFG::TiDo::m_pInstance->vfptr->HighSpeedMode)();
  v11 = 0i64;
  v12 = (UFG::SoundBank *)&UFG::SoundBankManager::sm_soundBanks.mNode.mNext[-3].mNext;
  v13 = v10;
  if ( (UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *)((char *)UFG::SoundBankManager::sm_soundBanks.mNode.mNext
                                                                  - 40) != v4 )
  {
    do
    {
      v14 = v12->m_loadState;
      v15 = (__int64)&v12->UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList>::mNext[-3].mNext;
      if ( (v14 & 0xFFFFFFFA) == 0 && v14 != LoadState_Loading && v12->m_count )
      {
        m_category = v12->m_category;
        m_priority = v12->m_priority;
        v18 = m_priority;
        if ( m_category && m_category->m_priority > m_priority )
          v18 = m_category->m_priority;
        if ( v18 > 3 || !v13 )
        {
          v19 = v12->m_priority;
          if ( m_category && m_category->m_priority > m_priority )
            v19 = m_category->m_priority;
          if ( v19 > UFG::SoundBankManager::sm_highestPriorityInPendingLoads )
          {
            v20 = v12->m_priority;
            if ( m_category && m_category->m_priority > m_priority )
              v20 = m_category->m_priority;
            UFG::SoundBankManager::sm_highestPriorityInPendingLoads = v20;
          }
          mUID = v12->m_name.mUID;
          ++UFG::SoundBankManager::sm_numPendingLoads;
          if ( mUID && (v22 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_sizes.mTree, mUID)) != 0i64 )
            mParent_low = LODWORD(v22->mNULL.mParent);
          else
            mParent_low = 0i64;
          UFG::SoundBankManager::sm_bytesRemainingToLoad += mParent_low;
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
            if ( m_category && m_category->m_priority > m_priority )
              m_priority = m_category->m_priority;
            if ( v25 < m_priority )
              v11 = v12;
          }
          else
          {
            v11 = v12;
          }
        }
      }
      v12 = (UFG::SoundBank *)v15;
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
void __fastcall UFG::SoundBankManager::BankLoadCallback(
        unsigned int in_bankId,
        const void *in_pInMemoryBankPtr,
        AKRESULT in_eLoadResult,
        int in_memPoolId,
        _DWORD *in_pCookie)
{
  __int64 v5; // r10
  int v6; // edx
  int v7; // eax
  __int64 v8; // r8
  char v9; // al

  v5 = *(_QWORD *)in_pCookie;
  v6 = 0;
  if ( in_eLoadResult != AK_FileNotFound )
  {
    v7 = UFG::TiDo::sm_asyncFileCount - 1;
    if ( UFG::TiDo::sm_asyncFileCount - 1 < 0 )
      v7 = 0;
    UFG::TiDo::sm_asyncFileCount = v7;
  }
  if ( in_eLoadResult == AK_Success )
  {
    v8 = *(_QWORD *)in_pCookie;
    switch ( in_pCookie[4] )
    {
      case 1:
      case 3:
      case 5:
        *(_DWORD *)(v8 + 112) = 2;
        break;
      case 2:
      case 4:
      case 6:
        *(_DWORD *)(v8 + 112) = 0;
        break;
      default:
        break;
    }
  }
  else
  {
    if ( in_eLoadResult == AK_InsufficientMemory )
      UFG::SoundBankManager::sm_failedLoadBankId = in_bankId;
    *(_DWORD *)(v5 + 112) = 6;
  }
  if ( *(_DWORD *)(v5 + 112) == 6 )
  {
    v9 = *(_BYTE *)(v5 + 128);
    if ( (v9 & 1) != 0 )
    {
      if ( (v9 & 2) != 0 )
      {
LABEL_18:
        LOBYTE(v6) = (v9 & 1) != 0;
        *(_DWORD *)(v5 + 112) = v6 + 4;
        goto LABEL_19;
      }
      if ( in_memPoolId != -1 )
        *(_DWORD *)(v5 + 112) = 5;
    }
    if ( (v9 & 2) != 0 )
      goto LABEL_18;
  }
LABEL_19:
  *((_QWORD *)in_pCookie + 1) = &UFG::WwiseCallbackOperation::`vftable;
  *((_QWORD *)in_pCookie + 3) = &UFG::AudioEventInfo::`vftable;
  operator delete[](in_pCookie);
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
  UFG::SoundBank *SoundBank; // rax

  if ( bankId->mUID - 1 > 0xFFFFFFFD )
    return 0;
  SoundBank = UFG::SoundBankManager::FindOrCreateSoundBank(bankId);
  if ( !SoundBank )
    return 0;
  ++SoundBank->m_count;
  return 1;
}

// File Line: 813
// RVA: 0x14AE30
void __fastcall UFG::SoundBankManager::QueueBankForUnload(UFG::qWiseSymbol *bankId)
{
  UFG::qBaseTreeRB *v1; // rax
  int *p_mCount; // rcx
  int v3; // eax

  if ( bankId->mUID - 1 <= 0xFFFFFFFD )
  {
    v1 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, bankId->mUID);
    if ( v1 )
    {
      p_mCount = &v1[-1].mCount;
      if ( v1 != (UFG::qBaseTreeRB *)8 )
      {
        v3 = p_mCount[19];
        if ( v3 )
          p_mCount[19] = v3 - 1;
      }
    }
  }
}

// File Line: 843
// RVA: 0x147E80
char __fastcall UFG::SoundBankManager::LoadBank(UFG::SoundBank *bank)
{
  UFG::SoundBankGroup *m_group; // rax
  unsigned int BestFitPoolForBank; // edi
  UFG::AkAsyncLoadCallbackCookie *v5; // rax
  UFG::AkAsyncLoadCallbackCookie *v6; // rsi
  unsigned int mUID; // ebx

  if ( bank && !bank->mNode.mUID )
    return 0;
  m_group = bank->m_group;
  if ( !m_group || (BestFitPoolForBank = m_group->poolId, BestFitPoolForBank == -1) )
    BestFitPoolForBank = UFG::SoundBankFragFreePool::FindBestFitPoolForBank(bank);
  bank->m_idealPoolId = BestFitPoolForBank;
  if ( bank->m_loadState == LoadState_RetryLoadInDefault )
    BestFitPoolForBank = -1;
  bank->m_poolId = BestFitPoolForBank;
  v5 = (UFG::AkAsyncLoadCallbackCookie *)UFG::qMalloc(0x48ui64, "SoundBankManager.LoadBank.AsyncLoadCookie", 0i64);
  v6 = v5;
  if ( v5 )
  {
    v5->op.vfptr = (UFG::WwiseCallbackOperationVtbl *)&UFG::WwiseCallbackOperation::`vftable;
    v5->op.eventInfo.vfptr = (UFG::AudioEventInfoVtbl *)&UFG::AudioEventInfo::`vftable;
    v5->op.eventInfo.eventId = 0;
    v5->op.eventInfo.objectId = 0i64;
    v5->op.eventInfo.flags = 0;
    v5->op.eventInfo.callbackFun = 0i64;
    v5->op.eventInfo.pUserData = 0i64;
    *(_QWORD *)&v5->op.op = 0i64;
    v5->pUserData = 0i64;
  }
  else
  {
    v6 = 0i64;
  }
  v6->op.op = eWWISEACTION_LOADBANK;
  v6->pUserData = bank;
  bank->m_loadState = LoadState_Loading;
  mUID = bank->m_name.mUID;
  if ( AK::SoundEngine::IsInitialized() && !UFG::WwiseInterface::smShuttingDown )
    AK::SoundEngine::LoadBank(
      mUID,
      (void (__fastcall *)(unsigned int, const void *, AKRESULT, int, void *))UFG::SoundBankManager::BankLoadCallback,
      v6,
      BestFitPoolForBank);
  ++UFG::TiDo::sm_asyncFileCount;
  return 1;
}

// File Line: 891
// RVA: 0x14CE70
char __fastcall UFG::SoundBankManager::UnloadBank(UFG::SoundBank *bank)
{
  char *v2; // rax
  char *v3; // rdi
  unsigned int mUID; // ebx

  if ( bank && bank->m_loadState == LoadState_Loaded )
  {
    v2 = UFG::qMalloc(0x48ui64, "SoundBankManager.UnloadBank.AsyncLoadCookie", 0i64);
    v3 = v2;
    if ( v2 )
    {
      *((_QWORD *)v2 + 1) = &UFG::WwiseCallbackOperation::`vftable;
      *((_QWORD *)v2 + 3) = &UFG::AudioEventInfo::`vftable;
      *((_DWORD *)v2 + 8) = 0;
      *((_QWORD *)v2 + 5) = 0i64;
      *((_DWORD *)v2 + 12) = 0;
      *((_QWORD *)v2 + 7) = 0i64;
      *((_QWORD *)v2 + 8) = 0i64;
      *((_QWORD *)v2 + 2) = 0i64;
      *(_QWORD *)v2 = 0i64;
    }
    else
    {
      v3 = 0i64;
    }
    *((_DWORD *)v3 + 4) = 2;
    bank->m_loadState = LoadState_Unloading;
    *(_QWORD *)v3 = bank;
    bank->m_unloadTimer = 0.0;
    mUID = bank->m_name.mUID;
    if ( AK::SoundEngine::IsInitialized() )
      AK::SoundEngine::UnloadBank(
        mUID,
        0i64,
        (void (__fastcall *)(unsigned int, const void *, AKRESULT, int, void *))UFG::SoundBankManager::BankLoadCallback,
        v3);
  }
  return 1;
}

// File Line: 938
// RVA: 0x1434F0
bool __fastcall UFG::SoundBankManager::BankLoaded(UFG::qWiseSymbol *bankId)
{
  UFG::qBaseTreeRB *v1; // rax
  int *p_mCount; // rax
  bool result; // al

  result = 0;
  if ( bankId->mUID )
  {
    v1 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, bankId->mUID);
    if ( v1 )
    {
      p_mCount = &v1[-1].mCount;
      if ( p_mCount )
      {
        if ( p_mCount[28] == 2 )
          return 1;
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

  return bankId->mUID
      && (v1 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, bankId->mUID)) != 0i64
      && v1 != (UFG::qBaseTreeRB *)8
      && *(&v1->mCount + 1) != 0;
}

// File Line: 1006
// RVA: 0x143470
bool __fastcall UFG::SoundBankManager::BankLoadRequestFinished(UFG::qWiseSymbol *bankId)
{
  UFG::qBaseTreeRB *v1; // rax
  int *p_mCount; // rax

  return !bankId->mUID
      || (v1 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, bankId->mUID)) == 0i64
      || (p_mCount = &v1[-1].mCount) == 0i64
      || ((p_mCount[28] - 2) & 0xFFFFFFFB) == 0;
}

// File Line: 1029
// RVA: 0x143590
bool __fastcall UFG::SoundBankManager::BankLoadedOrLoading(UFG::qWiseSymbol *bankId)
{
  UFG::qBaseTreeRB *v2; // rax
  int *v3; // rax
  UFG::qBaseTreeRB *v4; // rax
  int *p_mCount; // rax
  int v6; // eax
  bool result; // al

  result = 1;
  if ( !bankId->mUID
    || (v2 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, bankId->mUID)) == 0i64
    || (v3 = &v2[-1].mCount) == 0i64
    || v3[28] != 2 )
  {
    if ( !bankId->mUID )
      return 0;
    v4 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, bankId->mUID);
    if ( !v4 )
      return 0;
    p_mCount = &v4[-1].mCount;
    if ( !p_mCount )
      return 0;
    v6 = p_mCount[28];
    if ( v6 != 1 && (unsigned int)(v6 - 4) > 1 )
      return 0;
  }
  return result;
}

// File Line: 1038
// RVA: 0x148C70
char __fastcall UFG::SoundBankManager::LoadGroup(const char *group)
{
  unsigned int IDFromString; // eax
  UFG::SoundBankGroup *v3; // rax
  unsigned int *p_nameId; // rdi
  UFG::qWiseSymbol *p_mNext; // rbx
  UFG::SoundBank *SoundBank; // rax

  if ( !(unsigned int)UFG::qStringLength(group) )
    return 0;
  IDFromString = AK::SoundEngine::GetIDFromString(group);
  if ( !IDFromString )
    return 0;
  v3 = (UFG::SoundBankGroup *)UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_groups.mTree, IDFromString);
  if ( !v3 )
    return 0;
  p_nameId = &v3->nameId;
  p_mNext = (UFG::qWiseSymbol *)&v3->soundBanks.mNode.mNext[-4].mNext;
  if ( p_mNext != (UFG::qWiseSymbol *)&v3->nameId )
  {
    do
    {
      if ( p_mNext[18].mUID - 1 <= 0xFFFFFFFD )
      {
        SoundBank = UFG::SoundBankManager::FindOrCreateSoundBank(p_mNext + 18);
        if ( SoundBank )
          ++SoundBank->m_count;
      }
      p_mNext = (UFG::qWiseSymbol *)(*(_QWORD *)&p_mNext[16].mUID - 56i64);
    }
    while ( p_mNext != (UFG::qWiseSymbol *)p_nameId );
  }
  return 1;
}

// File Line: 1120
// RVA: 0x14D050
char __fastcall UFG::SoundBankManager::UnloadGroup(const char *group)
{
  unsigned int IDFromString; // eax
  UFG::qBaseTreeRB *v3; // rax
  UFG::qBaseNodeRB *p_mNULL; // rdi
  __int64 v5; // rbx
  unsigned int v6; // edx
  UFG::qBaseTreeRB *v7; // rax
  int *p_mCount; // rcx
  int v9; // eax

  if ( !(unsigned int)UFG::qStringLength(group) )
    return 0;
  IDFromString = AK::SoundEngine::GetIDFromString(group);
  if ( !IDFromString )
    return 0;
  v3 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_groups.mTree, IDFromString);
  if ( !v3 )
    return 0;
  p_mNULL = &v3->mNULL;
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
          p_mCount = &v7[-1].mCount;
          if ( v7 != (UFG::qBaseTreeRB *)8 )
          {
            v9 = p_mCount[19];
            if ( v9 )
              p_mCount[19] = v9 - 1;
          }
        }
      }
      v5 = *(_QWORD *)(v5 + 64) - 56i64;
    }
    while ( (UFG::qBaseNodeRB *)v5 != p_mNULL );
  }
  return 1;
}

// File Line: 1141
// RVA: 0x148170
char __fastcall UFG::SoundBankManager::LoadBankSymbols(bool keepStrings)
{
  SimpleXML::XMLDocument *v2; // rax
  SimpleXML::XMLDocument *v3; // rdi
  SimpleXML::XMLNode *ChildNode; // rax
  SimpleXML::XMLNode *i; // rsi
  char *Name; // rax
  SimpleXML::XMLNode *j; // rbx
  char *v8; // rax
  UFG::qString v10; // [rsp+28h] [rbp-30h] BYREF

  UFG::qString::qString(&v10, "Data\\Global\\Act\\AudioTag.xml");
  v2 = SimpleXML::XMLDocument::Open(v10.mData, 1ui64, 0i64);
  v3 = v2;
  if ( v2 )
  {
    ChildNode = SimpleXML::XMLDocument::GetChildNode(v2, 0i64, 0i64);
    if ( ChildNode )
    {
      for ( i = SimpleXML::XMLDocument::GetChildNode(v3, 0i64, ChildNode);
            i;
            i = SimpleXML::XMLDocument::GetNode(v3, 0i64, i) )
      {
        Name = SimpleXML::XMLNode::GetName(i);
        if ( !(unsigned int)UFG::qStringCompare(Name, "SoundBankType", -1)
          && (int)SimpleXML::XMLNode::GetChildCount(i) > 0 )
        {
          for ( j = SimpleXML::XMLDocument::GetChildNode(v3, 0i64, i); j; j = SimpleXML::XMLDocument::GetNode(
                                                                                v3,
                                                                                0i64,
                                                                                j) )
          {
            v8 = SimpleXML::XMLNode::GetName(j);
            if ( !(unsigned int)UFG::qStringCompare(v8, "SoundBank", -1) )
              UFG::SoundBankManager::LoadBankSymbols_::_2_::Local::AddNodeToRegistry(j, keepStrings);
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
void __fastcall UFG::SoundBankManager::LoadBankSymbols_::_2_::Local::AddNodeToRegistry(
        SimpleXML::XMLNode *node,
        bool keepStrings)
{
  unsigned int Attribute; // edi
  char *v4; // rbx
  UFG::qString *v5; // rax
  UFG::SoundBank *v6; // rbx
  UFG::qString *v7; // rax
  UFG::SoundBankCategory *MatchingCategoryForSoundBank; // rax
  UFG::qString text; // [rsp+38h] [rbp-60h] BYREF
  UFG::qString result; // [rsp+60h] [rbp-38h] BYREF
  UFG::qWiseSymbol bankId; // [rsp+B0h] [rbp+18h] BYREF
  UFG::qString *p_result; // [rsp+B8h] [rbp+20h]

  Attribute = SimpleXML::XMLNode::GetAttribute(node, "id", 0);
  v4 = SimpleXML::XMLNode::GetAttribute(node, "name");
  UFG::qString::qString(&text, v4);
  v5 = UFG::qString::ToLower(&text, &result);
  UFG::qString::Set(&text, v5->mData, v5->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  if ( (unsigned int)UFG::qStringCompare(v4, "none", -1) )
  {
    _((AMD_HD3D *)Attribute);
    UFG::qWiseSymbol::create_from_string(&bankId, v4);
    if ( bankId.mUID )
      UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, bankId.mUID);
    v6 = UFG::SoundBankManager::FindOrCreateSoundBank(&bankId);
    p_result = &result;
    UFG::qString::qString(&result, &text);
    MatchingCategoryForSoundBank = UFG::SoundBankCategory::FindMatchingCategoryForSoundBank(v7);
    if ( MatchingCategoryForSoundBank )
      v6->m_category = MatchingCategoryForSoundBank;
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
  char *Attribute; // rbx
  unsigned int mParent; // edi
  UFG::qBaseTreeRB *v6; // rax
  char *v7; // rbx
  int v8; // eax
  AMD_HD3D *v10; // [rsp+80h] [rbp+8h] BYREF
  UFG::qWiseSymbol result; // [rsp+88h] [rbp+10h] BYREF
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
        Attribute = SimpleXML::XMLNode::GetAttribute(j, "name");
        mParent = SimpleXML::XMLNode::GetAttribute(j, "size", 0);
        if ( mParent )
        {
          UFG::qWiseSymbol::create_from_string(&result, Attribute);
          if ( result.mUID && (v6 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_sizes.mTree, result.mUID)) != 0i64 )
          {
            if ( LODWORD(v6->mNULL.mParent) > mParent )
              mParent = (unsigned int)v6->mNULL.mParent;
            LODWORD(v6->mNULL.mParent) = mParent;
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
              v8 = (int)v10;
              *(_QWORD *)v7 = 0i64;
              *((_QWORD *)v7 + 1) = 0i64;
              *((_QWORD *)v7 + 2) = 0i64;
              *((_DWORD *)v7 + 6) = v8;
              *((_DWORD *)v7 + 8) = mParent;
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
  UFG::qBaseTreeRB *v2; // rax
  UFG::SoundBank *result; // rax
  char *v4; // rax
  UFG::qBaseNodeRB *v5; // rdi
  __int64 v6; // rax
  __int64 v7; // rbx
  UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *mPrev; // rcx

  if ( !bankId->mUID
    || (v2 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, bankId->mUID)) == 0i64
    || (result = (UFG::SoundBank *)&v2[-1].mCount) == 0i64 )
  {
    v4 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x88ui64, "BankMgr.Bank", 0i64, 1u);
    v5 = 0i64;
    if ( v4 )
    {
      UFG::SoundBank::SoundBank((UFG::SoundBank *)v4, bankId, 5u);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    if ( v7 )
      v5 = (UFG::qBaseNodeRB *)(v7 + 8);
    UFG::qBaseTreeRB::Add(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, v5);
    mPrev = UFG::SoundBankManager::sm_soundBanks.mNode.mPrev;
    UFG::SoundBankManager::sm_soundBanks.mNode.mPrev->mNext = (UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *)(v7 + 40);
    *(_QWORD *)(v7 + 40) = mPrev;
    *(_QWORD *)(v7 + 48) = &UFG::SoundBankManager::sm_soundBanks;
    UFG::SoundBankManager::sm_soundBanks.mNode.mPrev = (UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *)(v7 + 40);
    return (UFG::SoundBank *)v7;
  }
  return result;
}

// File Line: 1474
// RVA: 0x145860
UFG::qBaseTreeRB *__fastcall UFG::SoundBankManager::FindOrCreateGroup(unsigned int groupId)
{
  UFG::qBaseTreeRB *result; // rax
  char *v3; // rax
  UFG::qBaseNodeRB *v4; // rax
  UFG::qBaseNodeRB *v5; // rbx

  if ( !groupId || (result = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_groups.mTree, groupId)) == 0i64 )
  {
    v3 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x68ui64, "BankMgr.Location", 0i64, 1u);
    if ( v3 )
    {
      UFG::SoundBankGroup::SoundBankGroup((UFG::SoundBankGroup *)v3, groupId);
      v5 = v4;
    }
    else
    {
      v5 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&UFG::SoundBankManager::sm_groups.mTree, v5);
    return (UFG::qBaseTreeRB *)v5;
  }
  return result;
}

// File Line: 1598
// RVA: 0x1408B0
void __fastcall UFG::SoundBank::SoundBank(UFG::SoundBank *this, UFG::qWiseSymbol *bankId, unsigned int priority)
{
  unsigned int mUID; // eax
  AMD_HD3D *v6; // rcx

  mUID = bankId->mUID;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = mUID;
  this->UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList>::mPrev = &this->UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList>;
  this->UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList>::mNext = &this->UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList>;
  this->UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList>::mPrev = &this->UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList>;
  this->UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList>::mNext = &this->UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList>;
  this->vfptr = (UFG::SoundBankVtbl *)&UFG::SoundBank::`vftable;
  v6 = (AMD_HD3D *)bankId->mUID;
  this->m_name.mUID = (unsigned int)v6;
  _(v6);
  this->m_count = 0;
  this->m_priority = priority;
  *(_QWORD *)&this->m_unloadTimer = 0i64;
  *(_QWORD *)&this->m_poolId = 0i64;
  this->m_group = 0i64;
  this->m_loadState = LoadState_Unloaded;
  this->m_category = 0i64;
  *((_BYTE *)this + 128) = *((_BYTE *)this + 128) & 0xF8 | 1;
}

