// File Line: 25
// RVA: 0x150CDA0
__int64 dynamic_initializer_for__gOnlineMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gOnlineMemoryPool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gOnlineMemoryPool__);
}

// File Line: 42
// RVA: 0x150CDD0
__int64 UFG::_dynamic_initializer_for__g_cPreinitAllocator__()
{
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__g_cPreinitAllocator__);
}

// File Line: 43
// RVA: 0x150CDC0
__int64 UFG::_dynamic_initializer_for__g_cGameAllocator__()
{
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__g_cGameAllocator__);
}

// File Line: 46
// RVA: 0x42EA10
__int64 UFG::OSuitePrintf(const char *fmt, ...)
{
  int v1; // eax
  unsigned int v2; // edi
  UFG::qNode<UFG::qString,UFG::qString> *i; // rbx
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v7; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rcx
  UFG::qList<UFG::qString,UFG::qString,1,0> list; // [rsp+20h] [rbp-E0h] BYREF
  __int64 v11; // [rsp+30h] [rbp-D0h]
  UFG::qString v12; // [rsp+38h] [rbp-C8h] BYREF
  char dest[4112]; // [rsp+60h] [rbp-A0h] BYREF
  va_list va; // [rsp+1088h] [rbp+F88h] BYREF

  va_start(va, fmt);
  v11 = -2i64;
  UFG::qVSPrintf(dest, v1 - 96, fmt, va);
  UFG::qString::qString(&v12, dest);
  list.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
  list.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
  UFG::qString::Tokenize(&v12, &list, "\n", 0i64);
  v2 = 0;
  for ( i = list.mNode.mNext; i != (UFG::qNode<UFG::qString,UFG::qString> *)&list; i = i->mNext )
    v2 += UFG::qPrintf("<OSuiteLog>%s\n", (const char *)i[1].mNext);
  for ( j = (UFG::qString *)list.mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list;
        j = (UFG::qString *)list.mNode.mNext )
  {
    mPrev = j->mPrev;
    mNext = j->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    j->mPrev = j;
    j->mNext = j;
    UFG::qString::~qString(j);
    operator delete[](j);
  }
  v7 = list.mNode.mPrev;
  v8 = list.mNode.mNext;
  list.mNode.mPrev->mNext = list.mNode.mNext;
  v8->mPrev = v7;
  list.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
  list.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
  UFG::qString::~qString(&v12);
  return v2;
}

// File Line: 64
// RVA: 0x435790
UFG::allocator::free_link *__fastcall UFG::HKOSuiteAllocator::malloc(
        UFG::HKOSuiteAllocator *this,
        unsigned __int64 size,
        char *pTag)
{
  const char *v3; // rax

  v3 = "Online Suite";
  if ( pTag )
    v3 = pTag;
  return UFG::qMemoryPool::Allocate(&gOnlineMemoryPool, size, v3, 0i64, 1u);
}

// File Line: 72
// RVA: 0x4357D0
UFG::allocator::free_link *__fastcall UFG::HKOSuiteAllocator::realloc(
        UFG::HKOSuiteAllocator *this,
        void *ptr,
        unsigned __int64 size,
        char *pTag)
{
  const char *v5; // r9

  v5 = "Online Suite";
  if ( pTag )
    v5 = pTag;
  return UFG::qMemoryPool::Realloc(&gOnlineMemoryPool, ptr, size, v5, 0i64);
}

// File Line: 80
// RVA: 0x435780
void __fastcall UFG::HKOSuiteAllocator::free(UFG::HKOSuiteAllocator *this, char *ptr)
{
  UFG::qMemoryPool::Free(&gOnlineMemoryPool, ptr);
}

// File Line: 98
// RVA: 0x42F8E0
void __fastcall UFG::OSuiteManager::RegisterObserver(UFG::OSuiteManager *this, UFG::OSuiteManagerObserver *p)
{
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *mNext; // rax
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v3; // rdx
  UFG::qList<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver,1,0> *p_m_lOSuiteObservers; // rcx

  mNext = this->m_lOSuiteObservers.mNode.mNext;
  v3 = &p->UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver>;
  p_m_lOSuiteObservers = &this->m_lOSuiteObservers;
  p_m_lOSuiteObservers->mNode.mNext = v3;
  v3->mNext = mNext;
  v3->mPrev = &p_m_lOSuiteObservers->mNode;
  mNext->mPrev = v3;
}

// File Line: 103
// RVA: 0x431300
void __fastcall UFG::OSuiteManager::UnRegisterObserver(UFG::OnlineManager *this, UFG::OnlineManagerObserver *p)
{
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *mPrev; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *mNext; // rax
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v4; // rdx

  mPrev = p->mPrev;
  mNext = p->mNext;
  v4 = &p->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
}

// File Line: 108
// RVA: 0x42E1C0
void __fastcall UFG::OSuiteManager::Init(UFG::OSuiteManager *this)
{
  UFG::OnlineManager *v2; // rax
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *p_mNode; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *mNext; // rax

  if ( !this->m_bIsInitialized )
  {
    OSuite::ZThread::SetDefaultPriority(PRI_BELOW_CALLER);
    OSuite::ZOnlineSuite::PreInitialize(&UFG::g_cPreinitAllocator);
    if ( !(unsigned int)OSuite::ZOnlineSuite::Initialize(
                          &UFG::g_cGameAllocator,
                          &this->m_GameConfig,
                          "orangelotushd",
                          URL_SECURE) )
      this->m_bIsInitialized = 1;
    v2 = UFG::OnlineManager::Instance();
    p_mNode = &v2->m_lObservers.mNode;
    mNext = v2->m_lObservers.mNode.mNext;
    p_mNode->mNext = &this->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
    this->mPrev = p_mNode;
    this->mNext = mNext;
    mNext->mPrev = &this->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  }
}

// File Line: 142
// RVA: 0x430E20
void __fastcall UFG::OSuiteManager::Shutdown(UFG::OSuiteManager *this)
{
  OSuite::ZWebServiceClient *m_pWebServiceClient; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *mPrev; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *mNext; // rax

  if ( this->m_bIsInitialized )
  {
    m_pWebServiceClient = this->m_pWebServiceClient;
    if ( m_pWebServiceClient )
      OSuite::ZWebServiceClient::Release(m_pWebServiceClient);
    this->m_pWebServiceClient = 0i64;
    UFG::OnlineManager::Instance();
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = &this->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
    this->mNext = &this->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
    OSuite::ZOnlineSuite::Shutdown();
  }
}

// File Line: 156
// RVA: 0x42E430
UFG::OSuiteManager *__fastcall UFG::OSuiteManager::Instance()
{
  if ( (_S6_8 & 1) == 0 )
  {
    _S6_8 |= 1u;
    qword_142401208 = &qword_142401208;
    unk_142401210 = &qword_142401208;
    instance_0.vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OSuiteManager::`vftable;
    unk_142401218 = 0;
    unk_14240121C = 0;
    unk_142401220 = 0i64;
    qword_142401228 = &qword_142401228;
    unk_142401230 = &qword_142401228;
    UFG::OsuiteGameConfig::OsuiteGameConfig(&stru_142401238);
    qword_142401290 = &qword_142401290;
    unk_142401298 = &qword_142401290;
    unk_1424012A0 = 0;
    atexit(UFG::OSuiteManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  return &instance_0;
}

// File Line: 162
// RVA: 0x434D00
void __fastcall UFG::OSuiteManager::UploadFriendsListToServer(UFG::OSuiteManager *this)
{
  UFG::OnlineManager *v2; // rax
  UFG::OnlineId *OnlineId; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mPrev; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mNext; // rax
  UFG::OnlineId *p_mNext; // rbx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v7; // rsi
  UFG::qList<UFG::qString,UFG::qString,1,0> *p_m_FriendsToSend; // rdi
  UFG::qString *v9; // rax
  UFG::qString *v10; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rax
  int v12; // esi
  UFG::qList<UFG::qString,UFG::qString,1,0> *v13; // rbx
  int v14; // ecx
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rax
  UFG::qString *v16; // rdi
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rax
  int v19; // edx
  UFG::qNode<UFG::qString,UFG::qString> *v20; // rax
  int v21; // eax
  __int64 v22; // rbx
  unsigned __int64 v23; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v24; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v25; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v26; // rax
  unsigned __int64 v27; // rax
  int v28; // eax
  __int64 v29; // rbx
  unsigned __int64 v30; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v31; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v32; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v33; // rax
  unsigned __int64 v34; // rax
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> **v35; // rax
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *i; // rbx
  _QWORD *v37; // rdx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v38; // rcx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v39; // rax
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v40; // rcx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v41; // rax
  _BYTE v42[32]; // [rsp+0h] [rbp-D8h] BYREF
  UFG::qList<UFG::OnlineFriend,UFG::OnlineFriend,1,0> friends; // [rsp+20h] [rbp-B8h] BYREF
  UFG::OnlineId result; // [rsp+30h] [rbp-A8h] BYREF
  OSuite::TMap<OSuite::ZString,OSuite::ZString> params; // [rsp+48h] [rbp-90h] BYREF
  OSuite::ZString that; // [rsp+68h] [rbp-70h] BYREF
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> data; // [rsp+90h] [rbp-48h] BYREF
  UFG::qString v48; // [rsp+C8h] [rbp-10h] BYREF
  __int64 v49; // [rsp+F0h] [rbp+18h]
  UFG::qString v50; // [rsp+F8h] [rbp+20h] BYREF
  OSuite::ZOQuery query; // [rsp+128h] [rbp+50h] BYREF
  void *v52; // [rsp+1C8h] [rbp+F0h]

  v49 = -2i64;
  if ( !this->m_SendingFriendsInProgress )
  {
    friends.mNode.mPrev = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&friends;
    friends.mNode.mNext = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&friends;
    if ( (unsigned int)UFG::OnlineFriendManager::GetFriends(&friends) == 1 )
    {
      v2 = UFG::OnlineManager::Instance();
      OnlineId = UFG::OnlineManager::GetOnlineId(v2, &result);
      UFG::OnlineId::ToString(OnlineId, &v50);
      mPrev = result.mPrev;
      mNext = result.mNext;
      result.mPrev->mNext = result.mNext;
      mNext->mPrev = mPrev;
      result.mPrev = &result;
      result.mNext = &result;
      if ( v50.mLength > 0 )
      {
        p_mNext = (UFG::OnlineId *)&friends.mNode.mNext[-1].mNext;
        v7 = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&v42[24];
        if ( (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)((char *)friends.mNode.mNext - 8) != v7 )
        {
          p_m_FriendsToSend = &this->m_FriendsToSend;
          do
          {
            v9 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
            v52 = v9;
            if ( v9 )
              v10 = UFG::OnlineId::ToString(p_mNext + 1, v9);
            else
              v10 = 0i64;
            v11 = p_m_FriendsToSend->mNode.mPrev;
            v11->mNext = v10;
            v10->mPrev = v11;
            v10->mNext = &p_m_FriendsToSend->mNode;
            p_m_FriendsToSend->mNode.mPrev = v10;
            p_mNext = (UFG::OnlineId *)(p_mNext->m_SteamId.m_steamid.m_unAll64Bits - 8);
          }
          while ( p_mNext != (UFG::OnlineId *)v7 );
        }
        UFG::qString::qString(&v48);
        v12 = 0;
        v13 = &this->m_FriendsToSend;
        while ( 1 )
        {
          v14 = 0;
          v15 = this->m_FriendsToSend.mNode.mNext;
          if ( v15 == (UFG::qNode<UFG::qString,UFG::qString> *)v13 )
            break;
          do
          {
            ++v14;
            v15 = v15->mNext;
          }
          while ( v15 != (UFG::qNode<UFG::qString,UFG::qString> *)v13 );
          if ( v14 <= 0 || v12 >= 200 )
            break;
          v16 = (UFG::qString *)this->m_FriendsToSend.mNode.mNext;
          v17 = v16->mPrev;
          v18 = v16->mNext;
          v17->mNext = v18;
          v18->mPrev = v17;
          v16->mPrev = v16;
          v16->mNext = v16;
          UFG::qString::operator+=(&v48, v16);
          ++v12;
          v19 = 0;
          v20 = this->m_FriendsToSend.mNode.mNext;
          if ( v20 != (UFG::qNode<UFG::qString,UFG::qString> *)v13 )
          {
            do
            {
              ++v19;
              v20 = v20->mNext;
            }
            while ( v20 != (UFG::qNode<UFG::qString,UFG::qString> *)v13 );
            if ( v19 > 0 && v12 < 200 )
              UFG::qString::operator+=(&v48, ",");
          }
          UFG::qString::~qString(v16);
          operator delete[](v16);
        }
        UFG::qPrintf("s_Friends\n%s\n\n", v48.mData);
        this->m_SendingFriendsInProgress = 1;
        OSuite::ZOQuery::ZOQuery(&query);
        OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(&params, 0x10ui64);
        OSuite::ZString::ZString(&that, v50.mData);
        OSuite::ZString::ZString((OSuite::ZString *)&result, "s_Pid");
        v21 = ((__int64 (__fastcall *)(UFG::qNode<UFG::OnlineId,UFG::OnlineId> **))result.mNext->mNext)(&result.mNext);
        v22 = (params.m_nHashSize - 1) & v21;
        v23 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v22]);
        params.m_nCount -= v23;
        v24 = &params.m_pLists[v22];
        data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
        OSuite::ZString::ZString(&data.m_First, (OSuite::ZString *)&result);
        OSuite::ZString::ZString(&data.m_Second, &that);
        data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
        v25 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
        v52 = v25;
        if ( v25 )
          OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
            v25,
            &data);
        else
          v26 = 0i64;
        OSuite::ZRedBlackTreeBase::InsertElementSet(v24, v26);
        data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
        OSuite::ZString::~ZString(&data.m_Second);
        OSuite::ZString::~ZString(&data.m_First);
        v27 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v22]);
        params.m_nCount += v27;
        OSuite::ZString::~ZString((OSuite::ZString *)&result);
        OSuite::ZString::~ZString(&that);
        OSuite::ZString::ZString(&that, v48.mData);
        OSuite::ZString::ZString((OSuite::ZString *)&result, "s_Friends");
        v28 = ((__int64 (__fastcall *)(UFG::qNode<UFG::OnlineId,UFG::OnlineId> **))result.mNext->mNext)(&result.mNext);
        v29 = (params.m_nHashSize - 1) & v28;
        v30 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v29]);
        params.m_nCount -= v30;
        v31 = &params.m_pLists[v29];
        *(_QWORD *)&params.m_nHashSize = &OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
        OSuite::ZString::ZString((OSuite::ZString *)&params.m_nCount, (OSuite::ZString *)&result);
        OSuite::ZString::ZString((OSuite::ZString *)&that.m_pString, &that);
        *(_QWORD *)&params.m_nHashSize = &OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
        v32 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
        v52 = v32;
        if ( v32 )
          OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
            v32,
            (OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> *)&params.m_nHashSize);
        else
          v33 = 0i64;
        OSuite::ZRedBlackTreeBase::InsertElementSet(v31, v33);
        *(_QWORD *)&params.m_nHashSize = &OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
        OSuite::ZString::~ZString((OSuite::ZString *)&that.m_pString);
        OSuite::ZString::~ZString((OSuite::ZString *)&params.m_nCount);
        v34 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v29]);
        params.m_nCount += v34;
        OSuite::ZString::~ZString((OSuite::ZString *)&result);
        OSuite::ZString::~ZString(&that);
        OSuite::ZOQuery::ServiceOperation(&query, "UpdateFriends", &params);
        OSuitePrivate::ZEidosTransaction::GetState((OSuite::Statistics *)this->m_pWebServiceClient);
        result.mPrev = 0i64;
        result.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)UFG::OSuiteManager::FriendsListUpdatedCB;
        result.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)Assembly::GetRCX(this);
        OSuite::ZWebServiceClient::ExecuteQuery(
          this->m_pWebServiceClient,
          &query,
          (OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *)&result);
        OSuitePrivate::ZEidosTransaction::GetState((OSuite::Statistics *)this->m_pWebServiceClient);
        params.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
        if ( params.m_pLists )
        {
          if ( LODWORD(params.m_pLists[-1].m_Comparer.vfptr) )
            params.m_pLists->vfptr->__vecDelDtor(params.m_pLists, 3u);
          else
            operator delete[](&params.m_pLists[-1].m_Comparer.OSuite::ZObject);
        }
        OSuite::ZOQuery::~ZOQuery(&query);
        UFG::qString::~qString(&v48);
      }
      UFG::qString::~qString(&v50);
    }
    v35 = &friends.mNode.mNext[-1].mNext;
    for ( i = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&v42[24];
          (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)((char *)friends.mNode.mNext - 8) != i;
          v35 = &friends.mNode.mNext[-1].mNext )
    {
      v37 = v35 + 1;
      v38 = v35[1];
      v39 = v35[2];
      v38->mNext = v39;
      v39->mPrev = v38;
      *v37 = v37;
      v37[1] = v37;
      if ( v37 != (_QWORD *)8 )
        (*(void (__fastcall **)(_QWORD *, __int64))*(v37 - 1))(v37 - 1, 1i64);
    }
    v40 = friends.mNode.mPrev;
    v41 = friends.mNode.mNext;
    friends.mNode.mPrev->mNext = friends.mNode.mNext;
    v41->mPrev = v40;
  }
}

// File Line: 228
// RVA: 0x42EB60
void __fastcall UFG::OSuiteManager::ProcessRemainingFriends(UFG::OSuiteManager *this)
{
  UFG::qList<UFG::qString,UFG::qString,1,0> *p_m_FriendsToSend; // rdi
  int v3; // edx
  UFG::OSuiteManager *mNext; // rax
  UFG::OnlineManager *v5; // rax
  UFG::OnlineId *OnlineId; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mPrev; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v8; // rax
  int v9; // esi
  int v10; // ecx
  UFG::qList<UFG::qString,UFG::qString,1,0> *v11; // rax
  UFG::qString *v12; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rax
  UFG::qString *v15; // rbx
  int v16; // ecx
  UFG::qList<UFG::qString,UFG::qString,1,0> *v17; // rax
  int v18; // eax
  __int64 v19; // rbx
  unsigned __int64 v20; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v21; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v22; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v23; // rax
  unsigned __int64 v24; // rax
  int v25; // eax
  __int64 v26; // rbx
  unsigned __int64 v27; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v28; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v29; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v30; // rax
  unsigned __int64 v31; // rax
  UFG::OnlineId result; // [rsp+20h] [rbp-B8h] BYREF
  OSuite::TMap<OSuite::ZString,OSuite::ZString> params; // [rsp+38h] [rbp-A0h] BYREF
  OSuite::ZString that; // [rsp+58h] [rbp-80h] BYREF
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> data; // [rsp+70h] [rbp-68h] BYREF
  UFG::qString v36; // [rsp+B8h] [rbp-20h] BYREF
  __int64 v37; // [rsp+E0h] [rbp+8h]
  UFG::qString v38; // [rsp+E8h] [rbp+10h] BYREF
  OSuite::ZOQuery query; // [rsp+118h] [rbp+40h] BYREF
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v40; // [rsp+1B8h] [rbp+E0h]

  v37 = -2i64;
  p_m_FriendsToSend = &this->m_FriendsToSend;
  v3 = 0;
  mNext = (UFG::OSuiteManager *)this->m_FriendsToSend.mNode.mNext;
  if ( mNext != (UFG::OSuiteManager *)&this->m_FriendsToSend )
  {
    do
    {
      ++v3;
      mNext = (UFG::OSuiteManager *)mNext->mPrev;
    }
    while ( mNext != (UFG::OSuiteManager *)p_m_FriendsToSend );
    if ( v3 > 0 && !this->m_SendingFriendsInProgress )
    {
      v5 = UFG::OnlineManager::Instance();
      OnlineId = UFG::OnlineManager::GetOnlineId(v5, &result);
      UFG::OnlineId::ToString(OnlineId, &v38);
      mPrev = result.mPrev;
      v8 = result.mNext;
      result.mPrev->mNext = result.mNext;
      v8->mPrev = mPrev;
      result.mPrev = &result;
      result.mNext = &result;
      if ( v38.mLength > 0 )
      {
        UFG::qString::qString(&v36);
        v9 = 0;
        while ( 1 )
        {
          v10 = 0;
          v11 = (UFG::qList<UFG::qString,UFG::qString,1,0> *)p_m_FriendsToSend->mNode.mNext;
          if ( v11 == p_m_FriendsToSend )
            break;
          do
          {
            ++v10;
            v11 = (UFG::qList<UFG::qString,UFG::qString,1,0> *)v11->mNode.mNext;
          }
          while ( v11 != p_m_FriendsToSend );
          if ( v10 <= 0 || v9 >= 200 )
            break;
          v12 = (UFG::qString *)this->m_FriendsToSend.mNode.mNext;
          v13 = v12->mPrev;
          v14 = v12->mNext;
          v13->mNext = v14;
          v14->mPrev = v13;
          v12->mPrev = v12;
          v12->mNext = v12;
          UFG::qString::operator+=(&v36, v12);
          v15 = (UFG::qString *)v12->mNext;
          ++v9;
          v16 = 0;
          v17 = (UFG::qList<UFG::qString,UFG::qString,1,0> *)p_m_FriendsToSend->mNode.mNext;
          if ( v17 != p_m_FriendsToSend )
          {
            do
            {
              ++v16;
              v17 = (UFG::qList<UFG::qString,UFG::qString,1,0> *)v17->mNode.mNext;
            }
            while ( v17 != p_m_FriendsToSend );
            if ( v16 > 0 && v9 < 200 )
              UFG::qString::operator+=(&v36, ",");
          }
          if ( v15 )
          {
            UFG::qString::~qString(v15);
            operator delete[](v15);
          }
        }
        UFG::qPrintf("s_Friends\n%s\n\n", v36.mData);
        this->m_SendingFriendsInProgress = 1;
        OSuite::ZOQuery::ZOQuery(&query);
        OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(&params, 0x10ui64);
        OSuite::ZString::ZString(&that, v38.mData);
        OSuite::ZString::ZString((OSuite::ZString *)&result, "s_Pid");
        v18 = ((__int64 (__fastcall *)(UFG::qNode<UFG::OnlineId,UFG::OnlineId> **))result.mNext->mNext)(&result.mNext);
        v19 = (params.m_nHashSize - 1) & v18;
        v20 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v19]);
        params.m_nCount -= v20;
        v21 = &params.m_pLists[v19];
        data.m_First.vfptr = (OSuite::IHashableVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
        OSuite::ZString::ZString((OSuite::ZString *)&data.m_First.m_pString, (OSuite::ZString *)&result);
        OSuite::ZString::ZString((OSuite::ZString *)&data.m_Second.m_pString, &that);
        data.m_First.vfptr = (OSuite::IHashableVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
        v22 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
        v40 = v22;
        if ( v22 )
          OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
            v22,
            (OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> *)&data.m_First.OSuite::IHashable);
        else
          v23 = 0i64;
        OSuite::ZRedBlackTreeBase::InsertElementSet(v21, v23);
        data.m_First.vfptr = (OSuite::IHashableVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
        OSuite::ZString::~ZString((OSuite::ZString *)&data.m_Second.m_pString);
        OSuite::ZString::~ZString((OSuite::ZString *)&data.m_First.m_pString);
        v24 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v19]);
        params.m_nCount += v24;
        OSuite::ZString::~ZString((OSuite::ZString *)&result);
        OSuite::ZString::~ZString(&that);
        OSuite::ZString::ZString(&that, v36.mData);
        OSuite::ZString::ZString((OSuite::ZString *)&result, "s_Friends");
        v25 = ((__int64 (__fastcall *)(UFG::qNode<UFG::OnlineId,UFG::OnlineId> **))result.mNext->mNext)(&result.mNext);
        v26 = (params.m_nHashSize - 1) & v25;
        v27 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v26]);
        params.m_nCount -= v27;
        v28 = &params.m_pLists[v26];
        data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
        OSuite::ZString::ZString(&data.m_First, (OSuite::ZString *)&result);
        OSuite::ZString::ZString((OSuite::ZString *)&that.m_pString, &that);
        data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
        v29 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
        v40 = v29;
        if ( v29 )
          OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
            v29,
            &data);
        else
          v30 = 0i64;
        OSuite::ZRedBlackTreeBase::InsertElementSet(v28, v30);
        data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
        OSuite::ZString::~ZString((OSuite::ZString *)&that.m_pString);
        OSuite::ZString::~ZString(&data.m_First);
        v31 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v26]);
        params.m_nCount += v31;
        OSuite::ZString::~ZString((OSuite::ZString *)&result);
        OSuite::ZString::~ZString(&that);
        OSuite::ZOQuery::ServiceOperation(&query, "UpdateAppendFriends", &params);
        OSuitePrivate::ZEidosTransaction::GetState((OSuite::Statistics *)this->m_pWebServiceClient);
        result.mPrev = 0i64;
        result.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)UFG::OSuiteManager::FriendsListUpdatedCB;
        result.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)Assembly::GetRCX(this);
        OSuite::ZWebServiceClient::ExecuteQuery(
          this->m_pWebServiceClient,
          &query,
          (OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *)&result);
        OSuitePrivate::ZEidosTransaction::GetState((OSuite::Statistics *)this->m_pWebServiceClient);
        params.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
        if ( params.m_pLists )
        {
          if ( LODWORD(params.m_pLists[-1].m_Comparer.vfptr) )
            params.m_pLists->vfptr->__vecDelDtor(params.m_pLists, 3u);
          else
            operator delete[](&params.m_pLists[-1].m_Comparer.OSuite::ZObject);
        }
        OSuite::ZOQuery::~ZOQuery(&query);
        UFG::qString::~qString(&v36);
      }
      UFG::qString::~qString(&v38);
    }
  }
}

// File Line: 279
// RVA: 0x42B1E0
void __fastcall UFG::OSuiteManager::Connect(UFG::OSuiteManager *this)
{
  UFG::OnlineManager *v2; // rbx
  OSuite::ZWebServiceClient *m_pWebServiceClient; // rcx
  OSuite::ZOnlineSuite *v4; // rax
  OSuite::ZWebServiceClient *v5; // rax
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *mNext; // rbx
  OSuite::ZWebServiceClient **p_m_pWebServiceClient; // rdi
  OSuite::ZWebServiceClient **i; // rbx
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> cb; // [rsp+20h] [rbp-18h] BYREF

  if ( this->m_bIsInitialized && !this->m_bConnected && !this->m_pWebServiceClient )
  {
    v2 = UFG::OnlineManager::Instance();
    if ( UFG::OnlineManager::IsNetworkAvailable(v2) && UFG::OnlineManager::IsNetworkAvailable(v2) )
    {
      OSuite::ZOnlineSuite::SetPrimaryUser(0);
      m_pWebServiceClient = this->m_pWebServiceClient;
      if ( m_pWebServiceClient )
        OSuite::ZWebServiceClient::Release(m_pWebServiceClient);
      cb.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))UFG::OSuiteManager::DataInitializedCB;
      cb.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
      v4 = OSuite::ZOnlineSuite::Instance();
      v5 = OSuite::ZOnlineSuite::CreateWebServiceClient(v4, "game", &cb);
      this->m_bConnected = 0;
      this->m_pWebServiceClient = v5;
      if ( v5 )
      {
        if ( (unsigned int)OSuitePrivate::ZEidosTransaction::GetState((OSuite::Statistics *)v5) == 2 )
        {
          OSuite::ZWebServiceClient::Release(this->m_pWebServiceClient);
          this->m_pWebServiceClient = 0i64;
        }
      }
    }
    else
    {
      mNext = this->m_lOSuiteObservers.mNode.mNext;
      p_m_pWebServiceClient = &this->m_pWebServiceClient;
      for ( i = (OSuite::ZWebServiceClient **)&mNext[-1].mNext;
            i != p_m_pWebServiceClient;
            i = (OSuite::ZWebServiceClient **)&i[2][-1].m_pszPublicIpAddress )
      {
        ((void (__fastcall *)(OSuite::ZWebServiceClient **))(*i)->m_pCache)(i);
      }
    }
  }
}

// File Line: 347
// RVA: 0x42BC90
void __fastcall UFG::OSuiteManager::Disconnect(UFG::OSuiteManager *this)
{
  OSuite::ZWebServiceClient *m_pWebServiceClient; // rcx

  m_pWebServiceClient = this->m_pWebServiceClient;
  if ( m_pWebServiceClient )
    OSuite::ZWebServiceClient::Release(m_pWebServiceClient);
  this->m_bConnected = 0;
  this->m_pWebServiceClient = 0i64;
}

// File Line: 356
// RVA: 0x431540
void __fastcall UFG::OSuiteManager::Update(UFG::OSuiteManager *this, float timeDelta)
{
  OSuite::ZOnlineSuite *v3; // rax
  OSuite::ZWebServiceClient::EState State; // eax
  bool v5; // zf

  if ( this->m_bIsInitialized )
  {
    v3 = OSuite::ZOnlineSuite::Instance();
    OSuite::ZOnlineSuite::Update(v3);
    if ( this->m_bConnected )
    {
      State = (unsigned int)OSuitePrivate::ZEidosTransaction::GetState((OSuite::Statistics *)this->m_pWebServiceClient);
      v5 = !this->m_bOSuiteFriendsUpdated;
      errState = State;
      if ( v5 && this->m_rOSuiteFriendsUpdateTimer > 3.0 )
      {
        if ( (unsigned int)UFG::OnlineFriendManager::GetFriends(0i64) == 1 && !this->m_bUpdatedingOSuiteFriends )
        {
          this->m_bUpdatedingOSuiteFriends = 1;
          UFG::OSuiteManager::UploadFriendsListToServer(this);
        }
        this->m_rOSuiteFriendsUpdateTimer = 0.0;
      }
      this->m_rOSuiteFriendsUpdateTimer = timeDelta + this->m_rOSuiteFriendsUpdateTimer;
      UFG::OSuiteManager::ProcessRemainingFriends(this);
    }
  }
}

// File Line: 400
// RVA: 0x42E8F0
void __fastcall UFG::OSuiteManager::NetworkSignedIn(UFG::OSuiteManager *this)
{
  UFG::OSuiteManager::Connect(this);
  UFG::OnlineFriendManager::GetFriends(0i64);
}

// File Line: 406
// RVA: 0x42E910
void __fastcall UFG::OSuiteManager::NetworkSignedOut(UFG::OSuiteManager *this)
{
  OSuite::ZWebServiceClient **p_m_pWebServiceClient; // rdi
  OSuite::ZWebServiceClient *m_pWebServiceClient; // rcx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *mNext; // rbx
  OSuite::ZWebServiceClient **i; // rbx

  p_m_pWebServiceClient = &this->m_pWebServiceClient;
  m_pWebServiceClient = this->m_pWebServiceClient;
  if ( m_pWebServiceClient )
    OSuite::ZWebServiceClient::Release(m_pWebServiceClient);
  this->m_bConnected = 0;
  mNext = this->m_lOSuiteObservers.mNode.mNext;
  *p_m_pWebServiceClient = 0i64;
  for ( i = (OSuite::ZWebServiceClient **)&mNext[-1].mNext;
        i != p_m_pWebServiceClient;
        i = (OSuite::ZWebServiceClient **)&i[2][-1].m_pszPublicIpAddress )
  {
    ((void (__fastcall *)(OSuite::ZWebServiceClient **))(*i)->m_pCache)(i);
  }
}

// File Line: 415
// RVA: 0x42B4D0
void __fastcall UFG::OSuiteManager::DataInitializedCB(
        UFG::OSuiteManager *this,
        OSuite::SCallbackData *pData,
        OSuite::ZWebServiceClient *pWebServiceClient)
{
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v4; // rbx
  OSuite::ZWebServiceClient **v5; // rsi
  UFG::OSuiteManager *p_mNext; // rbx
  OSuite::ZWebServiceClient **p_m_pWebServiceClient; // rdi
  OSuite::ZWebServiceClient *m_pWebServiceClient; // rcx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *mNext; // rbx
  OSuite::ZWebServiceClient **i; // rbx

  if ( pData->Status.eError )
  {
    p_m_pWebServiceClient = &this->m_pWebServiceClient;
    m_pWebServiceClient = this->m_pWebServiceClient;
    if ( m_pWebServiceClient )
      OSuite::ZWebServiceClient::Release(m_pWebServiceClient);
    mNext = this->m_lOSuiteObservers.mNode.mNext;
    *p_m_pWebServiceClient = 0i64;
    this->m_bConnected = 0;
    for ( i = (OSuite::ZWebServiceClient **)&mNext[-1].mNext;
          i != p_m_pWebServiceClient;
          i = (OSuite::ZWebServiceClient **)&i[2][-1].m_pszPublicIpAddress )
    {
      ((void (__fastcall *)(OSuite::ZWebServiceClient **, OSuite::SCallbackData *, OSuite::ZWebServiceClient *))(*i)->m_pCache)(
        i,
        pData,
        pWebServiceClient);
    }
  }
  else
  {
    v4 = this->m_lOSuiteObservers.mNode.mNext;
    v5 = &this->m_pWebServiceClient;
    this->m_bConnected = 1;
    p_mNext = (UFG::OSuiteManager *)&v4[-1].mNext;
    if ( p_mNext != (UFG::OSuiteManager *)&this->m_pWebServiceClient )
    {
      do
      {
        ((void (__fastcall *)(UFG::OSuiteManager *, OSuite::ZWebServiceClient *, OSuite::ZWebServiceClient *))p_mNext->vfptr->NetworkSignedIn)(
          p_mNext,
          *v5,
          pWebServiceClient);
        p_mNext = (UFG::OSuiteManager *)&p_mNext->mNext[-1].mNext;
      }
      while ( p_mNext != (UFG::OSuiteManager *)v5 );
    }
  }
}

// File Line: 435
// RVA: 0x42C570
void __fastcall UFG::OSuiteManager::FriendsListUpdatedCB(
        UFG::OSuiteManager *this,
        OSuite::SCallbackData *pData,
        OSuite::ZWebServiceClient *pWebServiceClient)
{
  UFG::qList<UFG::qString,UFG::qString,1,0> *p_m_FriendsToSend; // rdx
  int v5; // ecx
  UFG::qList<UFG::qString,UFG::qString,1,0> *mNext; // rax
  OSuite::ZWebServiceClient **p_m_pWebServiceClient; // rsi
  OSuite::ZWebServiceClient *m_pWebServiceClient; // rcx
  OSuite::ZWebServiceClient **p_mNext; // rbx

  if ( pData->Status.eError )
  {
    p_m_pWebServiceClient = &this->m_pWebServiceClient;
    m_pWebServiceClient = this->m_pWebServiceClient;
    if ( m_pWebServiceClient )
      OSuite::ZWebServiceClient::Release(m_pWebServiceClient);
    p_mNext = (OSuite::ZWebServiceClient **)&this->m_lOSuiteObservers.mNode.mNext[-1].mNext;
    *p_m_pWebServiceClient = 0i64;
    for ( this->m_bConnected = 0;
          p_mNext != p_m_pWebServiceClient;
          p_mNext = (OSuite::ZWebServiceClient **)&p_mNext[2][-1].m_pszPublicIpAddress )
    {
      ((void (__fastcall *)(OSuite::ZWebServiceClient **, OSuite::SCallbackData *, OSuite::ZWebServiceClient *))(*p_mNext)->m_pCache)(
        p_mNext,
        pData,
        pWebServiceClient);
    }
    this->m_bUpdatedingOSuiteFriends = 0;
  }
  else
  {
    p_m_FriendsToSend = &this->m_FriendsToSend;
    v5 = 0;
    mNext = (UFG::qList<UFG::qString,UFG::qString,1,0> *)p_m_FriendsToSend->mNode.mNext;
    if ( mNext == p_m_FriendsToSend )
      goto LABEL_5;
    do
    {
      mNext = (UFG::qList<UFG::qString,UFG::qString,1,0> *)mNext->mNode.mNext;
      ++v5;
    }
    while ( mNext != p_m_FriendsToSend );
    if ( !v5 )
    {
LABEL_5:
      *(_WORD *)&this->m_bUpdatedingOSuiteFriends = 256;
      this->m_SendingFriendsInProgress = 0;
      return;
    }
  }
  this->m_SendingFriendsInProgress = 0;
}

// File Line: 464
// RVA: 0x4287D0
void __fastcall UFG::OsuiteGameConfig::OsuiteGameConfig(UFG::OsuiteGameConfig *this)
{
  UFG::qString *v2; // rax
  UFG::qString *v3; // rax
  __int64 lengthb; // [rsp+20h] [rbp-48h]
  int v5; // [rsp+28h] [rbp-40h]
  UFG::qString result; // [rsp+38h] [rbp-30h] BYREF

  this->vfptr = (OSuite::IGameConfigVtbl *)&UFG::OsuiteGameConfig::`vftable;
  UFG::qString::qString(&this->mBuildId);
  UFG::qString::qString(&this->mGameVersion);
  v2 = UFG::qString::FormatEx(&result, "%d", (unsigned int)UFG::gCL_number);
  UFG::qString::Set(&this->mBuildId, v2->mData, v2->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  v5 = UFG::gCL_number;
  LODWORD(lengthb) = UFG::gGameVersionRelease;
  v3 = UFG::qString::FormatEx(
         &result,
         "%d.%d.%d.%d",
         (unsigned int)UFG::gGameVersionMajor,
         (unsigned int)UFG::gGameVersionMinor,
         lengthb,
         v5);
  UFG::qString::Set(&this->mGameVersion, v3->mData, v3->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
}

// File Line: 470
// RVA: 0x42BA20
__int64 __fastcall UFG::OsuiteGameConfig::DefaultOnlineSuiteThreadPriority(UFG::OsuiteGameConfig *this)
{
  return (unsigned int)UFG::qThread::mDefaultThreadPriority;
}

// File Line: 475
// RVA: 0x42C620
__int64 __fastcall UFG::OsuiteGameConfig::GameTime(UFG::OsuiteGameConfig *this)
{
  return (unsigned int)UFG::Metrics::msRealTimeMSec;
}

// File Line: 486
// RVA: 0x42F0B0
const char *__fastcall UFG::OsuiteGameConfig::Product(UFG::OsuiteGameConfig *this)
{
  return "orangelotushd";
}

// File Line: 501
// RVA: 0x42E6E0
_BOOL8 __fastcall UFG::OsuiteGameConfig::IsFinal(UFG::OsuiteGameConfig *this)
{
  return UFG::gGameVersionMajor > 0;
}

// File Line: 507
// RVA: 0x42E860
const char *__fastcall UFG::OsuiteGameConfig::LanguageString(UFG::OsuiteGameConfig *this)
{
  UFG::UIGfxTranslator *m_translator; // rcx

  m_translator = UFG::UIScreenManager::s_instance->m_translator;
  if ( m_translator )
    return UFG::UIGfxTranslator::getLanguageStringShort(m_translator);
  else
    return "EN";
}

