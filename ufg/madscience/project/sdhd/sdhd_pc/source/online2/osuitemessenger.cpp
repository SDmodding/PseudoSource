// File Line: 18
// RVA: 0x42E510
UFG::OSuiteMessenger *__fastcall UFG::OSuiteMessenger::Instance()
{
  if ( !(_S7_11 & 1) )
  {
    _S7_11 |= 1u;
    UFG::OSuiteMessenger::OSuiteMessenger(&instance_1);
    atexit(UFG::OSuiteMessenger::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  return &instance_1;
}

// File Line: 28
// RVA: 0x430E80
void __fastcall UFG::OSuiteMessenger::Shutdown(UFG::OSuiteMessenger *this)
{
  UFG::OSuiteMessenger *v1; // rbx

  v1 = this;
  this->m_bExitRequested = 1;
  UFG::qEvent::Signal(&this->m_cThreadEvent);
  UFG::qThread::WaitForCompletion(&v1->m_cUpdateThread);
}

// File Line: 40
// RVA: 0x42F0C0
char __fastcall UFG::OSuiteMessenger::QueueSendMessage(UFG::OSuiteMessenger *this, UFG::OSuiteMessenger::CommandSend *command)
{
  UFG::OSuiteMessenger::CommandSend *v2; // rbx
  UFG::OSuiteMessenger *v3; // rdi
  char result; // al
  UFG::qNode<UFG::OSuiteMessenger::CommandSend,UFG::OSuiteMessenger::CommandSend> *v5; // rax
  UFG::qNode<UFG::OSuiteMessenger::CommandSend,UFG::OSuiteMessenger::CommandSend> *v6; // rcx
  int v7; // er8
  signed __int64 v8; // rax

  v2 = command;
  v3 = this;
  if ( UFG::OSuiteManager::Instance()->m_bConnected )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v3->m_cMutex);
    v5 = v3->m_lMessages.mNode.mPrev;
    v6 = (UFG::qNode<UFG::OSuiteMessenger::CommandSend,UFG::OSuiteMessenger::CommandSend> *)&v2->mPrev;
    v7 = 0;
    v5->mNext = (UFG::qNode<UFG::OSuiteMessenger::CommandSend,UFG::OSuiteMessenger::CommandSend> *)&v2->mPrev;
    v6->mPrev = v5;
    v6->mNext = &v3->m_lMessages.mNode;
    v3->m_lMessages.mNode.mPrev = (UFG::qNode<UFG::OSuiteMessenger::CommandSend,UFG::OSuiteMessenger::CommandSend> *)&v2->mPrev;
    v8 = (signed __int64)&v3->m_lMessages.mNode.mNext[-1].mNext;
    if ( (OSuite::ZWebServiceClient **)v8 != &v3->m_pWebServiceClient )
    {
      do
      {
        ++v7;
        v8 = *(_QWORD *)(v8 + 16) - 8i64;
      }
      while ( (OSuite::ZWebServiceClient **)v8 != &v3->m_pWebServiceClient );
      if ( v7 == 1 )
        UFG::qEvent::Signal(&v3->m_cThreadEvent);
    }
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v3->m_cMutex);
    result = 1;
  }
  else
  {
    if ( v2 )
      v2->vfptr->__vecDelDtor(v2, 1u);
    result = 0;
  }
  return result;
}

// File Line: 62
// RVA: 0x430590
__int64 __fastcall UFG::OSuiteMessenger::Send(UFG::OSuiteMessenger *this, UFG::OSuiteMessage *message, UFG::OnlineId *receiver, void (__fastcall *callback)(OSuite::SCallbackData *, OSuite::ZWebServiceClient *, UFG::OSuiteMessage *))
{
  void (__fastcall *v4)(OSuite::SCallbackData *, OSuite::ZWebServiceClient *, UFG::OSuiteMessage *); // rdi
  UFG::OnlineId *v5; // rbx
  UFG::OSuiteMessage *v6; // rsi
  UFG::OSuiteMessenger *v7; // rbp
  UFG::allocator::free_link *v8; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v9; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v10; // rax
  unsigned __int8 v11; // bl
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *i; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v13; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v14; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v15; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v16; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v17; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v18; // rax
  UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> receivers; // [rsp+30h] [rbp-18h]

  v4 = callback;
  v5 = receiver;
  v6 = message;
  v7 = this;
  receivers.mNode.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&receivers;
  receivers.mNode.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&receivers;
  v8 = UFG::qMalloc(0x18ui64, "OSuiteMessenger", 0i64);
  v9 = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)v8;
  if ( v8 )
  {
    v8->mNext = v8;
    v8[1].mNext = v8;
    LODWORD(v8[2].mNext) = 0;
    HIDWORD(v8[2].mNext) &= 0xFF0FFFFF;
    HIBYTE(v8[2].mNext) = 0;
    HIDWORD(v8[2].mNext) &= 0xFFF00000;
    v8[2].mNext = (UFG::allocator::free_link *)v5->m_SteamId.m_steamid.m_comp;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = receivers.mNode.mPrev;
  receivers.mNode.mPrev->mNext = v9;
  v9->mPrev = v10;
  v9->mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&receivers;
  receivers.mNode.mPrev = v9;
  v11 = UFG::OSuiteMessenger::Send(v7, v6, &receivers, v4);
  for ( i = receivers.mNode.mNext;
        (UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> *)receivers.mNode.mNext != &receivers;
        i = receivers.mNode.mNext )
  {
    v13 = i->mPrev;
    v14 = i->mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    i->mPrev = i;
    i->mNext = i;
    v15 = i->mPrev;
    v16 = i->mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    i->mPrev = i;
    i->mNext = i;
    operator delete[](i);
  }
  v17 = receivers.mNode.mPrev;
  v18 = receivers.mNode.mNext;
  receivers.mNode.mPrev->mNext = receivers.mNode.mNext;
  v18->mPrev = v17;
  return v11;
}

// File Line: 69
// RVA: 0x430420
char __fastcall UFG::OSuiteMessenger::Send(UFG::OSuiteMessenger *this, UFG::OSuiteMessage *message, UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> *receivers, void (__fastcall *callback)(OSuite::SCallbackData *, OSuite::ZWebServiceClient *, UFG::OSuiteMessage *))
{
  void (__fastcall *v4)(OSuite::SCallbackData *, OSuite::ZWebServiceClient *, UFG::OSuiteMessage *); // r14
  UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> *v5; // rbx
  UFG::OSuiteMessage *v6; // rsi
  UFG::OSuiteMessenger *v7; // rbp
  __int64 v8; // r8
  UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> *v9; // rax
  UFG::OnlineId *i; // rdi
  UFG::qString *v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::OSuiteMessenger::CommandSend *v13; // rbx
  UFG::allocator::free_link *v14; // rax
  char v15; // bl
  char v16; // al
  UFG::qString text; // [rsp+30h] [rbp-58h]
  UFG::qString result; // [rsp+58h] [rbp-30h]

  v4 = callback;
  v5 = receivers;
  v6 = message;
  v7 = this;
  if ( !UFG::OSuiteManager::Instance()->m_bConnected )
    goto LABEL_18;
  v8 = 0i64;
  v9 = (UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> *)v5->mNode.mNext;
  if ( v9 == v5 )
    goto LABEL_18;
  do
  {
    v8 = (unsigned int)(v8 + 1);
    v9 = (UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> *)v9->mNode.mNext;
  }
  while ( v9 != v5 );
  if ( (_DWORD)v8 )
  {
    UFG::qString::qString(&text);
    for ( i = (UFG::OnlineId *)v5->mNode.mNext; i != (UFG::OnlineId *)v5; i = (UFG::OnlineId *)i->mNext )
    {
      v11 = UFG::OnlineId::ToString(i, &result);
      UFG::qString::operator+=(&text, v11);
      UFG::qString::~qString(&result);
      if ( (UFG::qList<UFG::OnlineId,UFG::OnlineId,1,0> *)i->mNext != v5 )
        UFG::qString::operator+=(&text, ",");
    }
    v12 = UFG::qMalloc(0x50ui64, "OSuiteMessenger", 0i64);
    v13 = (UFG::OSuiteMessenger::CommandSend *)v12;
    if ( v12 )
    {
      v14 = v12 + 1;
      v14->mNext = v14;
      v14[1].mNext = v14;
      v13->vfptr = (UFG::OSuiteMessenger::CommandSendVtbl *)&UFG::OSuiteMessenger::CommandSend::`vftable;
      v13->m_pMessage = v6;
      UFG::qString::qString(&v13->m_sReceivers, &text);
      v13->m_pCallback = v4;
    }
    else
    {
      v13 = 0i64;
    }
    v15 = UFG::OSuiteMessenger::QueueSendMessage(v7, v13);
    UFG::qString::~qString(&text);
    v16 = v15;
  }
  else
  {
LABEL_18:
    if ( v6 )
      ((void (__fastcall *)(UFG::OSuiteMessage *, signed __int64, __int64))v6->vfptr->__vecDelDtor)(v6, 1i64, v8);
    v16 = 0;
  }
  return v16;
}

// File Line: 96
// RVA: 0x42F300
bool __fastcall UFG::OSuiteMessenger::Recv(UFG::OSuiteMessenger *this, int num, OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *callback)
{
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *v3; // rsi
  int v4; // er14
  UFG::OSuiteMessenger *v5; // r15
  UFG::OnlineManager *v7; // rax
  UFG::OnlineId *v8; // rax
  UFG::qString *v9; // rax
  OSuite::ZString *v10; // rax
  OSuite::ZString *v11; // rdi
  unsigned int v12; // eax
  __int64 v13; // rbx
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v16; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v17; // rax
  OSuite::ZString *v18; // rax
  OSuite::ZString *v19; // rdi
  unsigned int v20; // eax
  __int64 v21; // rbx
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // rax
  bool v24; // bl
  OSuite::TMap<OSuite::ZString,OSuite::ZString> params; // [rsp+20h] [rbp-C8h]
  OSuite::ZString key; // [rsp+40h] [rbp-A8h]
  UFG::OnlineId result; // [rsp+58h] [rbp-90h]
  OSuite::ZString v28; // [rsp+70h] [rbp-78h]
  OSuite::ZOQuery query; // [rsp+A8h] [rbp-40h]

  v28.vfptr = (OSuite::ZObjectVtbl *)-2i64;
  v3 = callback;
  v4 = num;
  v5 = this;
  if ( !UFG::OSuiteManager::Instance()->m_bConnected )
    return 0;
  OSuite::ZOQuery::ZOQuery(&query);
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(&params, 0x10ui64);
  OSuite::ZString::ZString(&key, "s_Receiver");
  v7 = UFG::OnlineManager::Instance();
  v8 = UFG::OnlineManager::GetOnlineId(v7, &result);
  v9 = UFG::OnlineId::ToString(v8, (UFG::qString *)&v28.vfptr);
  OSuite::ZString::ZString(&v28, v9->mData);
  v11 = v10;
  v12 = key.vfptr->ComputeHash((OSuite::IHashable *)&key.vfptr);
  v13 = (signed int)(v12 & (params.m_nHashSize - 1));
  v14 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v13].vfptr);
  params.m_nCount -= v14;
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &params.m_pLists[v13],
    &key,
    v11);
  v15 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v13].vfptr);
  params.m_nCount += v15;
  OSuite::ZString::~ZString(&v28);
  UFG::qString::~qString((UFG::qString *)&v28.vfptr);
  v16 = result.mPrev;
  v17 = result.mNext;
  result.mPrev->mNext = result.mNext;
  v17->mPrev = v16;
  result.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&result;
  result.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&result;
  OSuite::ZString::~ZString(&key);
  OSuite::ZString::ZString(&key, "i32_Tail");
  OSuite::ZString::ZString(&v28, v4);
  v19 = v18;
  v20 = key.vfptr->ComputeHash((OSuite::IHashable *)&key.vfptr);
  v21 = (signed int)(v20 & (params.m_nHashSize - 1));
  v22 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v21].vfptr);
  params.m_nCount -= v22;
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &params.m_pLists[v21],
    &key,
    v19);
  v23 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v21].vfptr);
  params.m_nCount += v23;
  OSuite::ZString::~ZString(&v28);
  OSuite::ZString::~ZString(&key);
  OSuite::ZOQuery::ServiceOperation(&query, "GetMessagesTail", &params);
  v24 = OSuite::ZWebServiceClient::ExecuteQuery(v5->m_pWebServiceClient, &query, v3);
  params.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
  if ( params.m_pLists )
  {
    if ( LODWORD(params.m_pLists[-1].m_Comparer.vfptr) )
      params.m_pLists->vfptr->__vecDelDtor((OSuite::ZObject *)params.m_pLists, 3u);
    else
      operator delete[](&params.m_pLists[-1].m_Comparer.vfptr);
  }
  OSuite::ZOQuery::~ZOQuery(&query);
  return v24;
}

// File Line: 113
// RVA: 0x42BA30
bool __fastcall UFG::OSuiteMessenger::Delete(UFG::OSuiteMessenger *this, unsigned __int64 timeStamp, OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *callback)
{
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *v3; // rsi
  unsigned __int64 v4; // r14
  UFG::OSuiteMessenger *v5; // r15
  UFG::OnlineManager *v7; // rax
  UFG::OnlineId *v8; // rax
  UFG::qString *v9; // rax
  OSuite::ZString *v10; // rax
  OSuite::ZString *v11; // rdi
  unsigned int v12; // eax
  __int64 v13; // rbx
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v16; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v17; // rax
  OSuite::ZString *v18; // rax
  OSuite::ZString *v19; // rdi
  unsigned int v20; // eax
  __int64 v21; // rbx
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // rax
  bool v24; // bl
  OSuite::TMap<OSuite::ZString,OSuite::ZString> params; // [rsp+20h] [rbp-C8h]
  OSuite::ZString key; // [rsp+40h] [rbp-A8h]
  UFG::OnlineId result; // [rsp+58h] [rbp-90h]
  OSuite::ZString v28; // [rsp+70h] [rbp-78h]
  OSuite::ZOQuery query; // [rsp+A8h] [rbp-40h]

  v28.vfptr = (OSuite::ZObjectVtbl *)-2i64;
  v3 = callback;
  v4 = timeStamp;
  v5 = this;
  if ( !UFG::OSuiteManager::Instance()->m_bConnected )
    return 0;
  OSuite::ZOQuery::ZOQuery(&query);
  OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(&params, 0x10ui64);
  OSuite::ZString::ZString(&key, "s_Receiver");
  v7 = UFG::OnlineManager::Instance();
  v8 = UFG::OnlineManager::GetOnlineId(v7, &result);
  v9 = UFG::OnlineId::ToString(v8, (UFG::qString *)&v28.vfptr);
  OSuite::ZString::ZString(&v28, v9->mData);
  v11 = v10;
  v12 = key.vfptr->ComputeHash((OSuite::IHashable *)&key.vfptr);
  v13 = (signed int)(v12 & (params.m_nHashSize - 1));
  v14 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v13].vfptr);
  params.m_nCount -= v14;
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &params.m_pLists[v13],
    &key,
    v11);
  v15 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v13].vfptr);
  params.m_nCount += v15;
  OSuite::ZString::~ZString(&v28);
  UFG::qString::~qString((UFG::qString *)&v28.vfptr);
  v16 = result.mPrev;
  v17 = result.mNext;
  result.mPrev->mNext = result.mNext;
  v17->mPrev = v16;
  result.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&result;
  result.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&result;
  OSuite::ZString::~ZString(&key);
  OSuite::ZString::ZString(&key, "i64_Timestamp");
  OSuite::ZString::ZString(&v28, v4);
  v19 = v18;
  v20 = key.vfptr->ComputeHash((OSuite::IHashable *)&key.vfptr);
  v21 = (signed int)(v20 & (params.m_nHashSize - 1));
  v22 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v21].vfptr);
  params.m_nCount -= v22;
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    &params.m_pLists[v21],
    &key,
    v19);
  v23 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v21].vfptr);
  params.m_nCount += v23;
  OSuite::ZString::~ZString(&v28);
  OSuite::ZString::~ZString(&key);
  OSuite::ZOQuery::ServiceOperation(&query, "DeleteMessagesByTimestamp", &params);
  v24 = OSuite::ZWebServiceClient::ExecuteQuery(v5->m_pWebServiceClient, &query, v3);
  params.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
  if ( params.m_pLists )
  {
    if ( LODWORD(params.m_pLists[-1].m_Comparer.vfptr) )
      params.m_pLists->vfptr->__vecDelDtor((OSuite::ZObject *)params.m_pLists, 3u);
    else
      operator delete[](&params.m_pLists[-1].m_Comparer.vfptr);
  }
  OSuite::ZOQuery::~ZOQuery(&query);
  return v24;
}

// File Line: 130
// RVA: 0x42E9D0
void __fastcall UFG::OSuiteMessenger::OSuiteManagerConnected(UFG::OSuiteMessenger *this, OSuite::ZWebServiceClient *p)
{
  if ( !this->m_pWebServiceClient )
    this->m_pWebServiceClient = p;
}

// File Line: 144
// RVA: 0x428690
void __fastcall UFG::OSuiteMessenger::OSuiteMessenger(UFG::OSuiteMessenger *this)
{
  UFG::OSuiteMessenger *v1; // rsi
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v2; // rdi
  UFG::OSuiteManager *v3; // rax
  signed __int64 v4; // rdx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v5; // rax
  UFG::qList<UFG::OSuiteMessenger::CommandSend,UFG::OSuiteMessenger::CommandSend,1,0> *v6; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteManagerObserver::`vftable;
  this->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteMessenger::`vftable;
  this->m_pWebServiceClient = 0i64;
  v6 = &this->m_lMessages;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  this->m_bExitRequested = 0;
  UFG::qMutex::qMutex(&this->m_cMutex, &customWorldMapCaption);
  UFG::qEvent::qEvent(&v1->m_cThreadEvent, "OSuiteMessenger", 1);
  UFG::qThread::qThread(&v1->m_cUpdateThread, "OSuiteMessenger");
  v3 = UFG::OSuiteManager::Instance();
  v4 = (signed __int64)&v3->m_lOSuiteObservers;
  v5 = v3->m_lOSuiteObservers.mNode.mNext;
  *(_QWORD *)(v4 + 8) = v2;
  v2->mPrev = (UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *)v4;
  v2->mNext = v5;
  v5->mPrev = v2;
  UFG::qBaseNodeRB::SetUID((UFG::qBaseNodeRB *)&v1->m_cUpdateThread, 0x4000u);
  UFG::qThread::Start(&v1->m_cUpdateThread, UFG::OSuiteMessenger::UpdateThread, v1);
}

// File Line: 155
// RVA: 0x4291B0
void __fastcall UFG::OSuiteMessenger::~OSuiteMessenger(UFG::OSuiteMessenger *this)
{
  UFG::OSuiteMessenger *v1; // rsi
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v2; // rdi
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v3; // rcx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v4; // rax
  UFG::qNode<UFG::OSuiteMessenger::CommandSend,UFG::OSuiteMessenger::CommandSend> *v5; // rcx
  UFG::qNode<UFG::OSuiteMessenger::CommandSend,UFG::OSuiteMessenger::CommandSend> *v6; // rax
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v7; // rcx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v8; // rax

  v1 = this;
  this->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteMessenger::`vftable;
  UFG::OSuiteManager::Instance();
  v2 = (UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  _((AMD_HD3D *)&v1->m_cUpdateThread);
  UFG::qEvent::~qEvent(&v1->m_cThreadEvent);
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&v1->m_cMutex);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&v1->m_lMessages);
  v5 = v1->m_lMessages.mNode.mPrev;
  v6 = v1->m_lMessages.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->m_lMessages.mNode.mPrev = &v1->m_lMessages.mNode;
  v1->m_lMessages.mNode.mNext = &v1->m_lMessages.mNode;
  v1->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteManagerObserver::`vftable;
  v7 = v1->mPrev;
  v8 = v1->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->mPrev = v2;
  v1->mNext = (UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *)&v1->mPrev;
}

// File Line: 160
// RVA: 0x42B090
void __fastcall UFG::OSuiteMessenger::CommandCB(UFG::OSuiteMessenger *this, OSuite::SCallbackData *pData, OSuite::ZWebServiceClient *pWebServiceClient)
{
  OSuite::SCallbackData *v3; // r14
  OSuite::ZWebServiceClient *v4; // rbp
  UFG::OSuiteMessenger *v5; // rdi
  UFG::qNode<UFG::OSuiteMessenger::CommandSend,UFG::OSuiteMessenger::CommandSend> *v6; // r10
  UFG::qNode<UFG::OSuiteMessenger::CommandSend,UFG::OSuiteMessenger::CommandSend> *v7; // rax
  UFG::qNode<UFG::OSuiteMessenger::CommandSend,UFG::OSuiteMessenger::CommandSend> *v8; // r9
  signed __int64 v9; // rbx
  UFG::qNode<UFG::OSuiteMessenger::CommandSend,UFG::OSuiteMessenger::CommandSend> *v10; // rax

  v3 = pData;
  v4 = pWebServiceClient;
  v5 = this;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->m_cMutex);
  v6 = v5->m_lMessages.mNode.mNext;
  v7 = v6->mNext;
  v8 = v6->mPrev;
  v9 = (signed __int64)&v6[-1].mNext;
  v8->mNext = v7;
  v7->mPrev = v8;
  v6->mPrev = v6;
  v6->mNext = v6;
  v10 = v6[4].mPrev;
  if ( v10 )
    ((void (__fastcall *)(OSuite::SCallbackData *, OSuite::ZWebServiceClient *, _QWORD))v10)(
      v3,
      v4,
      *(_QWORD *)(v9 + 24));
  (**(void (__fastcall ***)(signed __int64, signed __int64))v9)(v9, 1i64);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v5->m_cMutex);
  UFG::qEvent::Signal(&v5->m_cThreadEvent);
}

// File Line: 176
// RVA: 0x4345F0
void __fastcall UFG::OSuiteMessenger::UpdateThread(void *param)
{
  char *v1; // r14
  char *v2; // rsi
  int v3; // ecx
  signed __int64 v4; // rax
  signed __int64 v5; // rax
  unsigned __int8 v6; // cf
  unsigned __int64 v7; // rax
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *v8; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v9; // rbx
  __int64 v10; // r13
  unsigned __int64 v11; // rdi
  const void *v12; // rbx
  OSuite::ZString *v13; // rbx
  unsigned int v14; // eax
  __int64 v15; // rdi
  unsigned __int64 v16; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v17; // r15
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v18; // rax
  unsigned __int64 v19; // rax
  OSuite::ZString *v20; // rax
  OSuite::ZString *v21; // rbx
  unsigned int v22; // eax
  __int64 v23; // rdi
  unsigned __int64 v24; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v25; // r15
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v26; // rax
  unsigned __int64 v27; // rax
  UFG::OnlineId *v28; // rax
  UFG::qString *v29; // rax
  OSuite::ZString *v30; // rax
  OSuite::ZString *v31; // rbx
  int v32; // eax
  __int64 v33; // rdi
  unsigned __int64 v34; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v35; // r15
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v36; // rax
  unsigned __int64 v37; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v38; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v39; // rax
  OSuite::ZString *v40; // rax
  OSuite::ZString *v41; // rbx
  unsigned int v42; // eax
  __int64 v43; // rdi
  unsigned __int64 v44; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v45; // r15
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v46; // rax
  unsigned __int64 v47; // rax
  OSuite::TMap<OSuite::ZString,OSuite::ZString> params; // [rsp+30h] [rbp-A8h]
  UFG::OnlineId v49; // [rsp+50h] [rbp-88h]
  OSuite::ZString v50; // [rsp+68h] [rbp-70h]
  OSuite::ZString that; // [rsp+80h] [rbp-58h]
  OSuite::ZString v52; // [rsp+98h] [rbp-40h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v53; // [rsp+B0h] [rbp-28h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> data; // [rsp+E8h] [rbp+10h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v55; // [rsp+120h] [rbp+48h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v56; // [rsp+158h] [rbp+80h]
  __int64 v57; // [rsp+190h] [rbp+B8h]
  OSuite::ZString v58; // [rsp+198h] [rbp+C0h]
  OSuite::ZString result; // [rsp+1B0h] [rbp+D8h]
  OSuite::ZString v60; // [rsp+1C8h] [rbp+F0h]
  OSuite::ZString v61; // [rsp+1E0h] [rbp+108h]
  UFG::qString v62; // [rsp+1F8h] [rbp+120h]
  OSuite::ZOQuery query; // [rsp+228h] [rbp+150h]
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *v64; // [rsp+2C8h] [rbp+1F0h]

  v57 = -2i64;
  v1 = (char *)param;
  if ( !*((_BYTE *)param + 48) )
  {
    v2 = (char *)param + 24;
    do
    {
      UFG::qMutex::Lock((LPCRITICAL_SECTION)(v1 + 52));
      v3 = 0;
      v4 = *((_QWORD *)v1 + 5) - 8i64;
      if ( (char *)v4 != v2 )
      {
        do
        {
          ++v3;
          v4 = *(_QWORD *)(v4 + 16) - 8i64;
        }
        while ( (char *)v4 != v2 );
        if ( v3 )
        {
          OSuite::ZOQuery::ZOQuery(&query);
          params.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
          params.m_nHashSize = 16;
          params.m_nCount = 0i64;
          v5 = 640i64;
          if ( !is_mul_ok(0x10ui64, 0x28ui64) )
            v5 = -1i64;
          v6 = __CFADD__(v5, 8i64);
          v7 = v5 + 8;
          if ( v6 )
            v7 = -1i64;
          v8 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)OSuite::ZObject::operator new(v7);
          v64 = v8;
          if ( v8 )
          {
            LODWORD(v8->mNode.mPrev) = 16;
            v9 = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *)&v8->mNode.mNext;
            `eh vector constructor iterator(
              &v8->mNode.mNext,
              0x28ui64,
              16,
              (void (__fastcall *)(void *))OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>);
          }
          else
          {
            v9 = 0i64;
          }
          params.m_pLists = v9;
          v10 = *((_QWORD *)v1 + 5);
          v11 = (*(signed int (__cdecl **)(_QWORD))(**(_QWORD **)(v10 + 16) + 8i64))(*(_QWORD *)(v10 + 16));
          v12 = (const void *)(*(__int64 (__cdecl **)(_QWORD))(**(_QWORD **)(v10 + 16) + 16i64))(*(_QWORD *)(v10 + 16));
          OSuite::ZString::ZString(&that, "bin_Data");
          v13 = OSuite::ZMimeEntity::Base64Encode(&result, v12, v11);
          v14 = that.vfptr->ComputeHash((OSuite::IHashable *)&that.vfptr);
          v15 = (signed int)(v14 & (params.m_nHashSize - 1));
          v16 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v15].vfptr);
          params.m_nCount -= v16;
          v17 = &params.m_pLists[v15];
          data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::ZString(&data.m_First, &that);
          OSuite::ZString::ZString(&data.m_Second, v13);
          data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
          v18 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v64 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v18;
          if ( v18 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v18,
              &data);
          OSuite::ZRedBlackTreeBase::InsertElementSet(
            (OSuite::ZRedBlackTreeBase *)&v17->vfptr,
            (OSuite::ZRedBlackTreeBase::ZElementBase *)&v18->vfptr);
          data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::~ZString(&data.m_Second);
          OSuite::ZString::~ZString(&data.m_First);
          v19 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v15].vfptr);
          params.m_nCount += v19;
          OSuite::ZString::~ZString(&result);
          OSuite::ZString::~ZString(&that);
          OSuite::ZString::ZString(&v50, "i32_Type");
          OSuite::ZString::ZString(&v58, 0);
          v21 = v20;
          v22 = v50.vfptr->ComputeHash((OSuite::IHashable *)&v50.vfptr);
          v23 = (signed int)(v22 & (params.m_nHashSize - 1));
          v24 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v23].vfptr);
          params.m_nCount -= v24;
          v25 = &params.m_pLists[v23];
          v56.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::ZString(&v56.m_First, &v50);
          OSuite::ZString::ZString(&v56.m_Second, v21);
          v56.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
          v26 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v64 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v26;
          if ( v26 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v26,
              &v56);
          OSuite::ZRedBlackTreeBase::InsertElementSet(
            (OSuite::ZRedBlackTreeBase *)&v25->vfptr,
            (OSuite::ZRedBlackTreeBase::ZElementBase *)&v26->vfptr);
          v56.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::~ZString(&v56.m_Second);
          OSuite::ZString::~ZString(&v56.m_First);
          v27 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v23].vfptr);
          params.m_nCount += v27;
          OSuite::ZString::~ZString(&v58);
          OSuite::ZString::~ZString(&v50);
          OSuite::ZString::ZString((OSuite::ZString *)((char *)&v50 + 16), "s_Sender");
          if ( !(_S5_9 & 1) )
          {
            _S5_9 |= 1u;
            instance.vfptr = (UFG::OnlineManagerVtbl *)&UFG::OnlineManager::`vftable;
            unk_1424011B8 = 0;
            v64 = &stru_1424011C0;
            stru_1424011C0.mNode.mPrev = (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *)&stru_1424011C0;
            stru_1424011C0.mNode.mNext = (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *)&stru_1424011C0;
            UFG::qString::qString(&stru_1424011D0);
            atexit(UFG::OnlineManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
          }
          v28 = UFG::OnlineManager::GetOnlineId(&instance, &v49);
          v29 = UFG::OnlineId::ToString(v28, &v62);
          OSuite::ZString::ZString(&v60, v29->mData);
          v31 = v30;
          v32 = ((__int64 (__fastcall *)(UFG::qNode<UFG::OnlineId,UFG::OnlineId> **))v49.mNext->mNext)(&v49.mNext);
          v33 = v32 & (params.m_nHashSize - 1);
          v34 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v33].vfptr);
          params.m_nCount -= v34;
          v35 = &params.m_pLists[v33];
          v53.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::ZString(&v53.m_First, (OSuite::ZString *)((char *)&v50 + 16));
          OSuite::ZString::ZString(&v53.m_Second, v31);
          v53.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
          v36 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v64 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v36;
          if ( v36 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v36,
              &v53);
          OSuite::ZRedBlackTreeBase::InsertElementSet(
            (OSuite::ZRedBlackTreeBase *)&v35->vfptr,
            (OSuite::ZRedBlackTreeBase::ZElementBase *)&v36->vfptr);
          v53.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::~ZString(&v53.m_Second);
          OSuite::ZString::~ZString(&v53.m_First);
          v37 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v33].vfptr);
          params.m_nCount += v37;
          OSuite::ZString::~ZString(&v60);
          UFG::qString::~qString(&v62);
          v38 = v49.mPrev;
          v39 = v49.mNext;
          v49.mPrev->mNext = v49.mNext;
          v39->mPrev = v38;
          v49.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v49;
          v49.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v49;
          OSuite::ZString::~ZString((OSuite::ZString *)((char *)&v50 + 16));
          OSuite::ZString::ZString(&v52, "s_Receivers");
          OSuite::ZString::ZString(&v61, *(const char **)(v10 + 48));
          v41 = v40;
          v42 = v52.vfptr->ComputeHash((OSuite::IHashable *)&v52.vfptr);
          v43 = (signed int)(v42 & (params.m_nHashSize - 1));
          v44 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v43].vfptr);
          params.m_nCount -= v44;
          v45 = &params.m_pLists[v43];
          v55.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::ZString(&v55.m_First, &v52);
          OSuite::ZString::ZString(&v55.m_Second, v41);
          v55.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
          v46 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v64 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v46;
          if ( v46 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v46,
              &v55);
          OSuite::ZRedBlackTreeBase::InsertElementSet(
            (OSuite::ZRedBlackTreeBase *)&v45->vfptr,
            (OSuite::ZRedBlackTreeBase::ZElementBase *)&v46->vfptr);
          v55.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::~ZString(&v55.m_Second);
          OSuite::ZString::~ZString(&v55.m_First);
          v47 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v43].vfptr);
          params.m_nCount += v47;
          OSuite::ZString::~ZString(&v61);
          OSuite::ZString::~ZString(&v52);
          OSuite::ZOQuery::ServiceOperation(&query, "SendMessage", &params);
          v50.vfptr = 0i64;
          v50.vfptr = (OSuite::IHashableVtbl *)UFG::OSuiteMessenger::CommandCB;
          v50.vfptr = (OSuite::ZObjectVtbl *)Assembly::GetRCX(v1);
          OSuite::ZWebServiceClient::ExecuteQuery(
            *((OSuite::ZWebServiceClient **)v1 + 3),
            &query,
            (OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *)&v50);
          params.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
          if ( params.m_pLists )
          {
            if ( LODWORD(params.m_pLists[-1].m_Comparer.vfptr) )
              params.m_pLists->vfptr->__vecDelDtor((OSuite::ZObject *)params.m_pLists, 3u);
            else
              operator delete[](&params.m_pLists[-1].m_Comparer.vfptr);
          }
          OSuite::ZOQuery::~ZOQuery(&query);
        }
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)(v1 + 52));
      UFG::qEvent::Wait((UFG::qEvent *)(v1 + 104));
    }
    while ( !v1[48] );
  }
}

