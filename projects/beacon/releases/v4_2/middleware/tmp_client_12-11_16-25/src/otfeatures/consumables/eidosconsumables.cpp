// File Line: 32
// RVA: 0x1331728
void __fastcall OSuitePrivate::ZEidosConsumables::ZEidosConsumables(OSuitePrivate::ZEidosConsumables *this)
{
  OSuitePrivate::ZEidosConsumables *v1; // rdi
  OSuite::ZObject *v2; // rdx
  __int64 v3; // rax

  v1 = this;
  *(_WORD *)&this->m_bInit = 0;
  this->m_bQueryInProgress = 0;
  this->m_eStatus = -2147483392;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuitePrivate::ZEidosConsumables::`vftable;
  OSuite::ZMutex::ZMutex(&this->m_Mutex);
  OSuite::ZString::ZString(&v1->m_servlet);
  v1->m_pWebServiceClient = 0i64;
  v1->m_pConsumableFeed = 0i64;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&v1->m_playerData.vfptr, v2);
  v1->m_playerData.m_pList = 0i64;
  v1->m_playerData.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v1->m_playerData.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v3 = OSuite::ZObject::malloc((OSuite::ZObject *)&v1->m_playerData.vfptr, 0x80ui64, 0i64);
  v1->m_playerData.m_nTop = 0i64;
  v1->m_playerData.m_nSize = 16i64;
  v1->m_playerData.m_pList = (OSuitePrivate::ZPlayerConsumableData **)v3;
}

// File Line: 39
// RVA: 0x13317C4
void __fastcall OSuitePrivate::ZEidosConsumables::~ZEidosConsumables(OSuitePrivate::ZEidosConsumables *this)
{
  bool v1; // zf
  OSuitePrivate::ZEidosConsumables *v2; // rbx
  OSuite::TList<OSuitePrivate::ZPlayerConsumableData *> *v3; // rcx
  OSuitePrivate::ZPlayerConsumableData **v4; // rdx

  v1 = this->m_bInit == 0;
  v2 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuitePrivate::ZEidosConsumables::`vftable;
  if ( !v1 )
    OSuitePrivate::ZEidosConsumables::Terminate(this);
  v3 = &v2->m_playerData;
  v4 = v2->m_playerData.m_pList;
  v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  v3->vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free((OSuite::ZObject *)&v2->m_playerData.vfptr, v4);
  OSuite::ZString::~ZString(&v2->m_servlet);
  OSuite::ZMutex::~ZMutex(&v2->m_Mutex);
}

// File Line: 49
// RVA: 0x1331E84
__int64 __fastcall OSuitePrivate::ZEidosConsumables::GetStatus(OSuitePrivate::ZEidosConsumables *this)
{
  return this->m_eStatus;
}

// File Line: 57
// RVA: 0x1331F84
__int64 __fastcall OSuitePrivate::ZEidosConsumables::Initialize(OSuitePrivate::ZEidosConsumables *this)
{
  unsigned int v1; // esi
  OSuitePrivate::ZEidosConsumables *v2; // rdi
  char *v4; // rbx
  OSuite::ZOnlineSuite *v5; // rax
  OSuite::Statistics *v6; // rax
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> cb; // [rsp+20h] [rbp-18h]

  v1 = 0;
  v2 = this;
  if ( this->m_bInit )
    return 0i64;
  if ( this->m_pWebServiceClient )
    return this->m_eStatus;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( v2->m_pWebServiceClient )
    goto LABEL_10;
  cb.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)v2;
  cb.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuitePrivate::ZEidosConsumables::DataInitializedCB;
  v4 = OSuite::ZString::c_str(&v2->m_servlet);
  v5 = OSuite::ZOnlineSuite::Instance();
  v6 = (OSuite::Statistics *)OSuite::ZOnlineSuite::CreateWebServiceClient(v5, v4, &cb);
  v2->m_pWebServiceClient = (OSuite::ZWebServiceClient *)v6;
  if ( v6 )
  {
    if ( (unsigned int)OSuitePrivate::ZEidosTransaction::GetState(v6) == 2 )
    {
      OSuite::ZWebServiceClient::Release(v2->m_pWebServiceClient);
      v2->m_pWebServiceClient = 0i64;
      v2->m_eStatus = -2147483391;
      goto LABEL_9;
    }
LABEL_10:
    if ( (unsigned int)OSuitePrivate::ZEidosTransaction::GetState((OSuite::Statistics *)v2->m_pWebServiceClient) )
    {
      v2->m_bInit = 1;
    }
    else
    {
      v2->m_bInit = 0;
      v1 = 1;
    }
    v2->m_eStatus = v1;
    goto LABEL_14;
  }
LABEL_9:
  v1 = -2147483647;
  ((void (__fastcall *)(OSuitePrivate::ZEidosConsumables *))v2->vfptr[3].__vecDelDtor)(v2);
LABEL_14:
  OSuite::ZMutex::Unlock(&v2->m_Mutex);
  return v1;
}

// File Line: 113
// RVA: 0x1332634
__int64 __fastcall OSuitePrivate::ZEidosConsumables::Terminate(OSuitePrivate::ZEidosConsumables *this)
{
  OSuitePrivate::ZEidosConsumables *v1; // rbx
  OSuite::ZWebServiceClient *v2; // rcx
  OSuite::ZAtomBase *v3; // rdx

  v1 = this;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( v1->m_bInit )
  {
    v1->m_bInit = 0;
    OSuitePrivate::ZEidosConsumables::TermUserData(v1);
    v2 = v1->m_pWebServiceClient;
    if ( v2 )
    {
      v3 = (OSuite::ZAtomBase *)&v1->m_pConsumableFeed->vfptr;
      if ( v3 )
      {
        OSuite::ZWebServiceClient::CloseRequest(v2, v3);
        v1->m_pConsumableFeed = 0i64;
      }
      OSuite::ZWebServiceClient::Release(v1->m_pWebServiceClient);
      v1->m_pWebServiceClient = 0i64;
    }
    v1->m_eStatus = -2147483392;
  }
  OSuite::ZMutex::Unlock(&v1->m_Mutex);
  return 0i64;
}

// File Line: 144
// RVA: 0x13326A4
void __fastcall OSuitePrivate::ZEidosConsumables::Update(OSuitePrivate::ZEidosConsumables *this)
{
  OSuitePrivate::ZEidosConsumables *v1; // rbx
  OSuite::ZAtomBase *v2; // rdx
  OSuite::ZWebServiceClient *v3; // rcx

  v1 = this;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( v1->m_bInit && OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v1->m_playerData) )
  {
    if ( OSuitePrivate::ZEidosConsumables::RequestToProcess(v1) )
    {
      OSuitePrivate::ZEidosConsumables::ProcessRequests(v1);
    }
    else if ( !v1->m_bQueryInProgress )
    {
      if ( OSuitePrivate::ZEidosConsumables::Refresh(v1) )
      {
        v2 = (OSuite::ZAtomBase *)&v1->m_pConsumableFeed->vfptr;
        if ( v2 )
        {
          OSuite::ZWebServiceClient::CloseRequest(v1->m_pWebServiceClient, v2);
          v1->m_pConsumableFeed = 0i64;
        }
        v1->m_bRefreshAll = OSuitePrivate::ZEidosConsumables::QueryData(v1) == 0;
      }
      else
      {
        OSuitePrivate::ZEidosConsumables::UpdateData(v1);
      }
    }
  }
  else
  {
    v3 = v1->m_pWebServiceClient;
    if ( v3 && v1->m_eStatus == -2147483391 )
    {
      OSuite::ZWebServiceClient::Release(v3);
      v1->m_pWebServiceClient = 0i64;
    }
  }
  OSuite::ZMutex::Unlock(&v1->m_Mutex);
}

// File Line: 189
// RVA: 0x1331CA8
__int64 __fastcall OSuitePrivate::ZEidosConsumables::GetCount(OSuitePrivate::ZEidosConsumables *this, OSuite::IPlayerAccount *pPlayerAccount)
{
  OSuite::ZMutex *v2; // rbp
  OSuitePrivate::ZEidosConsumables *v3; // rsi
  OSuite::IPlayerAccount *v4; // rbx
  unsigned int v5; // edi
  unsigned __int64 v6; // rdi
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v7; // rbx
  unsigned __int64 v8; // rsi
  unsigned __int64 pUserIndex; // [rsp+30h] [rbp+8h]

  v2 = &this->m_Mutex;
  v3 = this;
  v4 = pPlayerAccount;
  v5 = 0;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( OSuitePrivate::ZEidosConsumables::ValidateUser(v3, v4, &pUserIndex) == OS_CONSUMABLES_OK )
  {
    v6 = pUserIndex;
    v7 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v3->m_playerData;
    v8 = pUserIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v7, pUserIndex + 1);
    if ( v6 >= v7->m_nTop )
      v7->m_nTop = v8;
    v5 = OSuitePrivate::ZPlayerConsumableData::GetCount((OSuitePrivate::ZPlayerConsumableData *)v7->m_pList[v6]);
  }
  OSuite::ZMutex::Unlock(v2);
  return v5;
}

// File Line: 210
// RVA: 0x1331D34
__int64 __fastcall OSuitePrivate::ZEidosConsumables::GetInfo(OSuitePrivate::ZEidosConsumables *this, OSuite::IPlayerAccount *pPlayerAccount, const char *consumableId, OSuite::IConsumableInfo **ppInfo)
{
  OSuitePrivate::ZEidosConsumables *v4; // rdi
  OSuite::IConsumableInfo **v5; // r15
  const char *v6; // r12
  OSuite::IPlayerAccount *v7; // rsi
  OSuite::ConsumableError v8; // ebx
  unsigned __int64 v9; // rsi
  unsigned __int64 v10; // rbp
  unsigned __int64 pUserIndex; // [rsp+50h] [rbp+8h]

  v4 = this;
  v5 = ppInfo;
  v6 = consumableId;
  v7 = pPlayerAccount;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v8 = -2147483646;
  if ( v5 )
  {
    v8 = OSuitePrivate::ZEidosConsumables::ValidateUser(v4, v7, &pUserIndex);
    if ( v8 == OS_CONSUMABLES_OK )
    {
      v9 = pUserIndex;
      v10 = pUserIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v4->m_playerData,
        pUserIndex + 1);
      if ( v9 >= v4->m_playerData.m_nTop )
        v4->m_playerData.m_nTop = v10;
      v8 = OSuitePrivate::ZPlayerConsumableData::GetInfo(v4->m_playerData.m_pList[v9], v6, v5);
      if ( v8 == OS_CONSUMABLES_OK )
        v8 = v4->m_eStatus;
    }
  }
  OSuite::ZMutex::Unlock(&v4->m_Mutex);
  return v8;
}

// File Line: 240
// RVA: 0x1331DDC
__int64 __fastcall OSuitePrivate::ZEidosConsumables::GetNextInfo(OSuitePrivate::ZEidosConsumables *this, OSuite::IPlayerAccount *pPlayerAccount, unsigned int consumableIndex, OSuite::IConsumableInfo **ppInfo)
{
  OSuitePrivate::ZEidosConsumables *v4; // rdi
  OSuite::IConsumableInfo **v5; // r15
  unsigned int v6; // er12
  OSuite::IPlayerAccount *v7; // rsi
  OSuite::ConsumableError v8; // ebx
  unsigned __int64 v9; // rsi
  unsigned __int64 v10; // rbp
  unsigned __int64 pUserIndex; // [rsp+50h] [rbp+8h]

  v4 = this;
  v5 = ppInfo;
  v6 = consumableIndex;
  v7 = pPlayerAccount;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v8 = -2147483646;
  if ( v5 )
  {
    v8 = OSuitePrivate::ZEidosConsumables::ValidateUser(v4, v7, &pUserIndex);
    if ( v8 == OS_CONSUMABLES_OK )
    {
      v9 = pUserIndex;
      v10 = pUserIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v4->m_playerData,
        pUserIndex + 1);
      if ( v9 >= v4->m_playerData.m_nTop )
        v4->m_playerData.m_nTop = v10;
      v8 = OSuitePrivate::ZPlayerConsumableData::GetNextInfo(v4->m_playerData.m_pList[v9], v6, v5);
      if ( v8 == OS_CONSUMABLES_OK )
        v8 = v4->m_eStatus;
    }
  }
  OSuite::ZMutex::Unlock(&v4->m_Mutex);
  return v8;
}

// File Line: 269
// RVA: 0x13319BC
__int64 __fastcall OSuitePrivate::ZEidosConsumables::Consume(OSuitePrivate::ZEidosConsumables *this, OSuite::IPlayerAccount *pPlayerAccount, OSuite::IConsumableInfo *pInfo)
{
  OSuite::ZMutex *v3; // rbp
  OSuitePrivate::ZEidosConsumables *v4; // rdi
  OSuite::IConsumableInfo *v5; // r14
  OSuite::IPlayerAccount *v6; // rsi
  OSuite::ConsumableError v7; // ebx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v8; // rbx
  unsigned __int64 v9; // rdi
  unsigned __int64 v10; // rsi
  unsigned __int64 pUserIndex; // [rsp+40h] [rbp+8h]

  v3 = &this->m_Mutex;
  v4 = this;
  v5 = pInfo;
  v6 = pPlayerAccount;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v7 = -2147483646;
  if ( v5 )
  {
    v7 = OSuitePrivate::ZEidosConsumables::ValidateUser(v4, v6, &pUserIndex);
    if ( v7 == OS_CONSUMABLES_OK )
    {
      v8 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v4->m_playerData;
      v9 = pUserIndex;
      v10 = pUserIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v8, pUserIndex + 1);
      if ( v9 >= v8->m_nTop )
        v8->m_nTop = v10;
      v7 = OSuitePrivate::ZPlayerConsumableData::Consume((OSuitePrivate::ZPlayerConsumableData *)v8->m_pList[v9], v5);
    }
  }
  OSuite::ZMutex::Unlock(v3);
  return v7;
}

// File Line: 296
// RVA: 0x1332524
__int64 __fastcall OSuitePrivate::ZEidosConsumables::SetServlet(OSuitePrivate::ZEidosConsumables *this, OSuite::ZString *servlet)
{
  OSuite::ZString::operator=(&this->m_servlet, servlet);
  return 0i64;
}

// File Line: 306
// RVA: 0x133184C
__int64 __fastcall OSuitePrivate::ZEidosConsumables::AddUser(OSuitePrivate::ZEidosConsumables *this, OSuite::IPlayerAccount *pPlayerAccount)
{
  OSuitePrivate::ZEidosConsumables *v2; // rbx
  OSuite::IPlayerAccount *v3; // rdi
  OSuite::ConsumableError v4; // ebp
  OSuitePrivate::ZPlayerConsumableData *v5; // rax
  OSuitePrivate::ZPlayerConsumableData *v6; // rax
  OSuitePrivate::ZPlayerConsumableData *v7; // rdi

  v2 = this;
  v3 = pPlayerAccount;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v2->m_bRefreshAll = 1;
  v4 = OSuitePrivate::ZEidosConsumables::ValidateUser(v2, v3, 0i64);
  if ( v4 )
  {
    v5 = (OSuitePrivate::ZPlayerConsumableData *)OSuite::ZObject::operator new(0xC8ui64);
    if ( v5 )
    {
      v5->m_pPlayerProfile = 0i64;
      v5->m_prefixedUserId.m_pString = 0i64;
      v5->m_pConsumablesData = 0i64;
      v5->m_ownedConsumables.m_pList = 0i64;
      v5->m_pendingRequests.m_pList = 0i64;
      v5->m_pTxnFeed = 0i64;
      v5->m_pTxnEntry = 0i64;
      v5->m_pTransferEntry = 0i64;
      v5->m_pTransaction = 0i64;
      OSuitePrivate::ZPlayerConsumableData::ZPlayerConsumableData(v5, v3);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    if ( v7 )
    {
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v2->m_playerData,
        v2->m_playerData.m_nTop + 1);
      v2->m_playerData.m_pList[v2->m_playerData.m_nTop++] = v7;
    }
  }
  OSuite::ZMutex::Unlock(&v2->m_Mutex);
  return v4;
}

// File Line: 339
// RVA: 0x1332070
__int64 __fastcall OSuitePrivate::ZEidosConsumables::NewTransaction(OSuitePrivate::ZEidosConsumables *this, OSuite::IPlayerAccount *pPlayerAccount, OSuite::TList<OSuite::IConsumableInfo *> *infos, const char *tag)
{
  OSuite::ZMutex *v4; // rbp
  OSuitePrivate::ZEidosConsumables *v5; // rdi
  const char *v6; // r14
  OSuite::TList<OSuite::IConsumableInfo *> *v7; // r15
  OSuite::IPlayerAccount *v8; // rbx
  OSuite::ConsumableError v9; // ebx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v10; // rbx
  unsigned __int64 v11; // rdi
  unsigned __int64 v12; // rsi
  unsigned __int64 pUserIndex; // [rsp+40h] [rbp+8h]

  v4 = &this->m_Mutex;
  v5 = this;
  v6 = tag;
  v7 = infos;
  v8 = pPlayerAccount;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v9 = OSuitePrivate::ZEidosConsumables::ValidateUser(v5, v8, &pUserIndex);
  if ( v9 == OS_CONSUMABLES_OK )
  {
    v10 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v5->m_playerData;
    v11 = pUserIndex;
    v12 = pUserIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v10, pUserIndex + 1);
    if ( v11 >= v10->m_nTop )
      v10->m_nTop = v12;
    v9 = OSuitePrivate::ZPlayerConsumableData::NewTransaction(
           (OSuitePrivate::ZPlayerConsumableData *)v10->m_pList[v11],
           v7,
           v6);
  }
  OSuite::ZMutex::Unlock(v4);
  return v9;
}

// File Line: 357
// RVA: 0x1331C18
__int64 __fastcall OSuitePrivate::ZEidosConsumables::GetActiveTransaction(OSuitePrivate::ZEidosConsumables *this, OSuite::IPlayerAccount *pPlayerAccount, OSuite::IConsumableTransaction **ppTransaction)
{
  OSuite::ZMutex *v3; // rbp
  OSuitePrivate::ZEidosConsumables *v4; // rdi
  OSuite::IConsumableTransaction **v5; // r14
  OSuite::IPlayerAccount *v6; // rbx
  OSuite::ConsumableError v7; // ebx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v8; // rbx
  unsigned __int64 v9; // rdi
  unsigned __int64 v10; // rsi
  unsigned __int64 pUserIndex; // [rsp+40h] [rbp+8h]

  v3 = &this->m_Mutex;
  v4 = this;
  v5 = ppTransaction;
  v6 = pPlayerAccount;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v7 = OSuitePrivate::ZEidosConsumables::ValidateUser(v4, v6, &pUserIndex);
  if ( v7 == OS_CONSUMABLES_OK )
  {
    v8 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v4->m_playerData;
    v9 = pUserIndex;
    v10 = pUserIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v8, pUserIndex + 1);
    if ( v9 >= v8->m_nTop )
      v8->m_nTop = v10;
    v7 = OSuitePrivate::ZPlayerConsumableData::GetActiveTransaction(
           (OSuitePrivate::ZPlayerConsumableData *)v8->m_pList[v9],
           v5);
  }
  OSuite::ZMutex::Unlock(v3);
  return v7;
}

// File Line: 375
// RVA: 0x1331930
__int64 __fastcall OSuitePrivate::ZEidosConsumables::CloseActiveTransaction(OSuitePrivate::ZEidosConsumables *this, OSuite::IPlayerAccount *pPlayerAccount)
{
  OSuite::ZMutex *v2; // rbp
  OSuitePrivate::ZEidosConsumables *v3; // rdi
  OSuite::IPlayerAccount *v4; // rbx
  OSuite::ConsumableError v5; // ebx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v6; // rbx
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // rsi
  unsigned __int64 pUserIndex; // [rsp+30h] [rbp+8h]

  v2 = &this->m_Mutex;
  v3 = this;
  v4 = pPlayerAccount;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v5 = OSuitePrivate::ZEidosConsumables::ValidateUser(v3, v4, &pUserIndex);
  if ( v5 == OS_CONSUMABLES_OK )
  {
    v6 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v3->m_playerData;
    v7 = pUserIndex;
    v8 = pUserIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v6, pUserIndex + 1);
    if ( v7 >= v6->m_nTop )
      v6->m_nTop = v8;
    v5 = OSuitePrivate::ZPlayerConsumableData::CloseActiveTransaction((OSuitePrivate::ZPlayerConsumableData *)v6->m_pList[v7]);
  }
  OSuite::ZMutex::Unlock(v2);
  return v5;
}

// File Line: 396
// RVA: 0x1331E88
OSuitePrivate::ZEidosTransaction *__fastcall OSuitePrivate::ZEidosConsumables::GetTransaction(OSuitePrivate::ZEidosConsumables *this, unsigned __int64 userIndex)
{
  OSuitePrivate::ZEidosConsumables *v2; // rbx
  unsigned __int64 v3; // rdi
  OSuitePrivate::ZEidosTransaction *v4; // rsi

  v2 = this;
  v3 = userIndex;
  v4 = 0i64;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( v3 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v2->m_playerData) )
  {
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v2->m_playerData,
      v3 + 1);
    if ( v3 >= v2->m_playerData.m_nTop )
      v2->m_playerData.m_nTop = v3 + 1;
    v4 = v2->m_playerData.m_pList[v3]->m_pTransaction;
  }
  OSuite::ZMutex::Unlock(&v2->m_Mutex);
  return v4;
}

// File Line: 412
// RVA: 0x1331F08
OSuite::IPlayerAccount *__fastcall OSuitePrivate::ZEidosConsumables::GetUser(OSuitePrivate::ZEidosConsumables *this, unsigned __int64 userIndex)
{
  OSuitePrivate::ZEidosConsumables *v2; // rbx
  unsigned __int64 v3; // rdi
  OSuite::IPlayerAccount *v4; // rsi

  v2 = this;
  v3 = userIndex;
  v4 = 0i64;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( v3 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v2->m_playerData) )
  {
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v2->m_playerData,
      v3 + 1);
    if ( v3 >= v2->m_playerData.m_nTop )
      v2->m_playerData.m_nTop = v3 + 1;
    v4 = v2->m_playerData.m_pList[v3]->m_pPlayerProfile;
  }
  OSuite::ZMutex::Unlock(&v2->m_Mutex);
  return v4;
}

// File Line: 430
// RVA: 0x1332178
bool __fastcall OSuitePrivate::ZEidosConsumables::QueryData(OSuitePrivate::ZEidosConsumables *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v1; // rdi
  OSuitePrivate::ZEidosConsumables *v2; // r13
  bool v3; // si
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // r14
  unsigned __int64 v6; // r14
  char *v7; // rax
  unsigned __int64 v8; // r15
  char *v9; // rbx
  OSuite::ZOFilter *v10; // rax
  OSuite::ZOFilter *v11; // rax
  OSuite::ZWebServiceClient *v12; // rcx
  bool v13; // al
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> cb; // [rsp+20h] [rbp-E0h]
  OSuite::ZOFilter v16; // [rsp+30h] [rbp-D0h]
  OSuite::ZString v17; // [rsp+68h] [rbp-98h]
  OSuite::ZOFilter filterExpression; // [rsp+80h] [rbp-80h]
  OSuite::ZOQuery query; // [rsp+C0h] [rbp-40h]

  v1 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData;
  v2 = this;
  v3 = 0;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_playerData) )
  {
    query.m_entityName.m_pString = 0i64;
    query.m_queryMap.m_pLists = 0i64;
    query.m_functionParameters.m_pLists = 0i64;
    OSuite::ZOQuery::ZOQuery(&query);
    OSuite::ZOQuery::EntitySet(&query, "consumables");
    v4 = 0i64;
    if ( !v2->m_bRefreshAll && OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v1) )
    {
      do
      {
        v5 = v4 + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v1, v4 + 1);
        if ( v4 >= v1->m_nTop )
          v1->m_nTop = v5;
        if ( LOBYTE(v1->m_pList[v4]->m_pLeft) )
          break;
        ++v4;
      }
      while ( v5 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v1) );
    }
    if ( v4 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v1) )
    {
      v6 = v4 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v1, v4 + 1);
      if ( v4 >= v1->m_nTop )
        v1->m_nTop = v6;
      OSuitePrivate::ZPlayerConsumableData::InitData((OSuitePrivate::ZPlayerConsumableData *)v1->m_pList[v4]);
      v17.m_pString = 0i64;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v1, v4 + 1);
      if ( v4 >= v1->m_nTop )
        v1->m_nTop = v6;
      OSuite::ZString::ZString(&v17, (OSuite::ZString *)&v1->m_pList[v4]->m_eColour);
      filterExpression.m_queryBuilder.m_Chars.m_pList = 0i64;
      OSuite::ZOFilter::ZOFilter(&filterExpression);
      v7 = OSuite::ZString::c_str(&v17);
      OSuite::ZOFilter::Compare(&filterExpression, "_id", v7, 0);
      if ( v6 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v1) )
      {
        v8 = v4 + 2;
        do
        {
          if ( v2->m_bRefreshAll )
            goto LABEL_30;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v1, v8);
          if ( v6 >= v1->m_nTop )
            v1->m_nTop = v8;
          if ( LOBYTE(v1->m_pList[v6]->m_pLeft) )
          {
LABEL_30:
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v1, v8);
            if ( v6 >= v1->m_nTop )
              v1->m_nTop = v8;
            OSuitePrivate::ZPlayerConsumableData::InitData((OSuitePrivate::ZPlayerConsumableData *)v1->m_pList[v6]);
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v1, v8);
            if ( v6 >= v1->m_nTop )
              v1->m_nTop = v8;
            OSuite::ZString::operator=(&v17, (OSuite::ZString *)&v1->m_pList[v6]->m_eColour);
            v9 = OSuite::ZString::c_str(&v17);
            OSuite::ZOFilter::ZOFilter(&v16);
            v11 = OSuite::ZOFilter::Compare(v10, "_id", v9, 0);
            OSuite::ZOFilter::Or(&filterExpression, v11);
            OSuite::ZOFilter::~ZOFilter(&v16);
          }
          ++v6;
          ++v8;
        }
        while ( v6 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v1) );
      }
      OSuite::ZOQuery::Filter(&query, &filterExpression);
      v12 = v2->m_pWebServiceClient;
      cb.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuitePrivate::ZEidosConsumables::FeedFetchedCB;
      cb.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)v2;
      v13 = OSuite::ZWebServiceClient::ExecuteQuery(v12, &query, &cb);
      v2->m_bQueryInProgress = 1;
      v2->m_eStatus = 3;
      v3 = v13;
      OSuite::ZOFilter::~ZOFilter(&filterExpression);
      OSuite::ZString::~ZString(&v17);
    }
    OSuite::ZOQuery::~ZOQuery(&query);
  }
  return v3;
}

// File Line: 485
// RVA: 0x1332758
void __fastcall OSuitePrivate::ZEidosConsumables::UpdateData(OSuitePrivate::ZEidosConsumables *this)
{
  OSuitePrivate::ZEidosConsumables *v1; // rsi
  OSuite::ZOFeed *v2; // rcx
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase *v5; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v6; // rbx
  char v7; // al
  OSuite::ZMetricAppender *v8; // r14
  OSuite::ZOProperty *v9; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *v10; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v11; // rsi
  unsigned __int64 v12; // rbx
  OSuite::ZString outValue; // [rsp+20h] [rbp-38h]

  v1 = this;
  v2 = this->m_pConsumableFeed;
  v3 = 0i64;
  if ( v2 && v1->m_eStatus == 3 )
  {
    v4 = 0i64;
    if ( OSuite::ZAtomFeed::TotalEntries((OSuite::ZAtomFeed *)&v2->vfptr) )
    {
      do
      {
        v5 = OSuite::ZAtomFeed::GetEntry((OSuite::ZAtomFeed *)&v1->m_pConsumableFeed->vfptr, v4);
        v6 = v5;
        v7 = -(char)v5->vfptr[1].__vecDelDtor((OSuite::ZObject *)&v5->vfptr, OSuite::ZOEntry::s_nClassId);
        v8 = (OSuite::ZMetricAppender *)((unsigned __int64)v6 & -(signed __int64)(v7 != 0));
        if ( (unsigned __int64)v6 & -(signed __int64)(v7 != 0) )
        {
          v9 = OSuite::ZOEntry::Property((OSuite::ZOEntry *)((unsigned __int64)v6 & -(signed __int64)(v7 != 0)), "_id");
          if ( v9 )
          {
            outValue.m_pString = 0i64;
            OSuite::ZString::ZString(&outValue);
            if ( OSuite::ZOProperty::GetValue(v9, &outValue) )
            {
              v10 = OSuitePrivate::ZEidosConsumables::Find(v1, &outValue, 0i64);
              if ( v10 )
                OSuitePrivate::ZPlayerConsumableData::SetConsumablesData((OSuite::ZUsageTracker *)v10, v8);
            }
            OSuite::ZString::~ZString(&outValue);
          }
        }
        ++v4;
      }
      while ( v4 < OSuite::ZAtomFeed::TotalEntries((OSuite::ZAtomFeed *)&v1->m_pConsumableFeed->vfptr) );
    }
    v1->m_eStatus = 0;
  }
  v11 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v1->m_playerData;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v11) )
  {
    do
    {
      v12 = v3 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v11, v3 + 1);
      if ( v3 >= v11->m_nTop )
        v11->m_nTop = v12;
      OSuitePrivate::ZPlayerConsumableData::UpdateData((OSuitePrivate::ZPlayerConsumableData *)v11->m_pList[v3++]);
    }
    while ( v12 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v11) );
  }
}

// File Line: 521
// RVA: 0x1332110
void __fastcall OSuitePrivate::ZEidosConsumables::ProcessRequests(OSuitePrivate::ZEidosConsumables *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v1; // rbx
  unsigned __int64 v2; // rdi
  unsigned __int64 v3; // rsi

  v1 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData;
  v2 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_playerData) )
  {
    do
    {
      v3 = v2 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v1, v2 + 1);
      if ( v2 >= v1->m_nTop )
        v1->m_nTop = v3;
      OSuitePrivate::ZPlayerConsumableData::ProcessRequests((OSuitePrivate::ZPlayerConsumableData *)v1->m_pList[v2++]);
    }
    while ( v3 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v1) );
  }
}

// File Line: 530
// RVA: 0x13324AC
char __fastcall OSuitePrivate::ZEidosConsumables::RequestToProcess(OSuitePrivate::ZEidosConsumables *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v1; // rbx
  unsigned __int64 v2; // rdi
  unsigned __int64 v3; // rsi

  v1 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData;
  v2 = 0i64;
  if ( !OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_playerData) )
    return 0;
  while ( 1 )
  {
    v3 = v2 + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v1, v2 + 1);
    if ( v2 >= v1->m_nTop )
      v1->m_nTop = v3;
    if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v1->m_pList[v2][3].m_pLeft) )
      break;
    ++v2;
    if ( v3 >= OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v1) )
      return 0;
  }
  return 1;
}

// File Line: 544
// RVA: 0x1332538
void __fastcall OSuitePrivate::ZEidosConsumables::TermUserData(OSuitePrivate::ZEidosConsumables *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v1; // rbx
  __int64 v2; // rsi
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase *v5; // rcx
  __int64 v6; // rax

  v1 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_playerData) )
  {
    v2 = 0i64;
    v3 = 1i64;
    do
    {
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v1, v3);
      v4 = v3 - 1;
      if ( v3 - 1 >= v1->m_nTop )
        v1->m_nTop = v3;
      OSuitePrivate::ZPlayerConsumableData::TermData((OSuitePrivate::ZPlayerConsumableData *)v1->m_pList[v2]);
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v1, v3);
      if ( v4 >= v1->m_nTop )
        v1->m_nTop = v3;
      v5 = v1->m_pList[v2];
      if ( v5 )
        v5->vfptr->__vecDelDtor((OSuite::ZObject *)&v5->vfptr, 1u);
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v1, v3);
      if ( v4 >= v1->m_nTop )
        v1->m_nTop = v3;
      ++v3;
      v1->m_pList[v2] = 0i64;
      ++v2;
    }
    while ( v3 - 1 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v1) );
  }
  OSuite::ZObject::free((OSuite::ZObject *)&v1->vfptr, v1->m_pList);
  v6 = OSuite::ZObject::malloc((OSuite::ZObject *)&v1->vfptr, 0x80ui64, 0i64);
  v1->m_nTop = 0i64;
  v1->m_pList = (OSuite::ZRedBlackTreeBase::ZElementBase **)v6;
  v1->m_nSize = 16i64;
}

// File Line: 559
// RVA: 0x13328B0
__int64 __fastcall OSuitePrivate::ZEidosConsumables::ValidateUser(OSuitePrivate::ZEidosConsumables *this, OSuite::IPlayerAccount *pPlayerAccount, unsigned __int64 *pUserIndex)
{
  unsigned __int64 *v3; // rdi
  OSuitePrivate::ZEidosConsumables *v4; // rbx
  OSuite::ZString *v6; // rax

  v3 = pUserIndex;
  v4 = this;
  if ( !this->m_bInit )
    return this->m_pWebServiceClient != 0i64 ? 1 : -2147483392;
  v6 = pPlayerAccount->vfptr->GetUserId(pPlayerAccount, 0);
  return OSuitePrivate::ZEidosConsumables::Find(v4, v6, v3) == 0i64 ? 0x80000105 : 0;
}

// File Line: 575
// RVA: 0x1331B00
OSuite::ZRedBlackTreeBase::ZElementBase *__fastcall OSuitePrivate::ZEidosConsumables::Find(OSuitePrivate::ZEidosConsumables *this, OSuite::ZString *userId, unsigned __int64 *pUserIndex)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v3; // rbx
  int v4; // esi
  unsigned __int64 *v5; // r15
  OSuite::ZString *v6; // r12
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase *v9; // rcx
  OSuite::ZString *v10; // r14
  OSuite::ZString *v11; // rax
  bool v12; // r14
  OSuite::ZString result; // [rsp+20h] [rbp-48h]

  v3 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData;
  v4 = 0;
  v5 = pUserIndex;
  v6 = userId;
  v7 = 0i64;
  if ( !OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_playerData) )
    return 0i64;
  while ( 1 )
  {
    v8 = v7 + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3, v7 + 1);
    if ( v7 >= v3->m_nTop )
      v3->m_nTop = v8;
    v9 = v3->m_pList[v7]->m_pRight;
    v10 = (OSuite::ZString *)v9->vfptr[2].__vecDelDtor((OSuite::ZObject *)&v9->vfptr, 0);
    v12 = 1;
    if ( !OSuite::ZString::operator==(v10, v6) )
    {
      v4 |= 1u;
      v11 = OSuite::operator+(&result, &customWorldMapCaption, v10);
      if ( !OSuite::ZString::operator==(v11, v6) )
        v12 = 0;
    }
    if ( v4 & 1 )
    {
      v4 &= 0xFFFFFFFE;
      OSuite::ZString::~ZString(&result);
    }
    if ( v12 )
      break;
    ++v7;
    if ( v8 >= OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v3) )
      return 0i64;
  }
  if ( v5 )
    *v5 = v7;
  OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v3, v7 + 1);
  if ( v7 >= v3->m_nTop )
    v3->m_nTop = v7 + 1;
  return v3->m_pList[v7];
}

// File Line: 594
// RVA: 0x1332434
char __fastcall OSuitePrivate::ZEidosConsumables::Refresh(OSuitePrivate::ZEidosConsumables *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v2; // rbx
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rsi

  if ( this->m_bRefreshAll )
    return 1;
  v2 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData;
  v3 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_playerData) )
  {
    while ( 1 )
    {
      v4 = v3 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v2, v3 + 1);
      if ( v3 >= v2->m_nTop )
        v2->m_nTop = v4;
      if ( LOBYTE(v2->m_pList[v3]->m_pLeft) )
        break;
      ++v3;
      if ( v4 >= OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v2) )
        return 0;
    }
    return 1;
  }
  return 0;
}

// File Line: 611
// RVA: 0x1331A54
void __fastcall OSuitePrivate::ZEidosConsumables::DataInitializedCB(OSuitePrivate::ZEidosConsumables *this, OSuite::SCallbackData *pData, OSuite::ZWebServiceClient *__formal)
{
  OSuitePrivate::ZEidosConsumables *v3; // rdi
  OSuite::SCallbackData *v4; // rbx

  v3 = this;
  v4 = pData;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( v4->Status.eError )
    v3->m_eStatus = -2147483391;
  else
    *(_WORD *)&v3->m_bInit = 257;
  OSuite::ZMutex::Unlock(&v3->m_Mutex);
}

// File Line: 629
// RVA: 0x1331AA0
void __fastcall OSuitePrivate::ZEidosConsumables::FeedFetchedCB(OSuitePrivate::ZEidosConsumables *this, OSuite::SCallbackData *pData, OSuite::ZWebServiceClient *pWebServiceClient)
{
  OSuitePrivate::ZEidosConsumables *v3; // rbx
  OSuite::ZWebServiceClient *v4; // rbp
  OSuite::SCallbackData *v5; // rsi

  v3 = this;
  v4 = pWebServiceClient;
  v5 = pData;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( v5->Status.eError == HTTPERROR_OK )
    v3->m_pConsumableFeed = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOFeed>(v4, &v5->URL);
  v3->m_bQueryInProgress = 0;
  OSuite::ZMutex::Unlock(&v3->m_Mutex);
}

