// File Line: 32
// RVA: 0x1331728
void __fastcall OSuitePrivate::ZEidosConsumables::ZEidosConsumables(OSuitePrivate::ZEidosConsumables *this)
{
  OSuite::ZObject *v2; // rdx
  OSuitePrivate::ZPlayerConsumableData **v3; // rax

  *(_WORD *)&this->m_bInit = 0;
  this->m_bQueryInProgress = 0;
  this->m_eStatus = OS_CONSUMABLES_ERROR_NOTINIT;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuitePrivate::ZEidosConsumables::`vftable;
  OSuite::ZMutex::ZMutex(&this->m_Mutex);
  OSuite::ZString::ZString(&this->m_servlet);
  this->m_pWebServiceClient = 0i64;
  this->m_pConsumableFeed = 0i64;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_playerData, v2);
  this->m_playerData.m_pList = 0i64;
  this->m_playerData.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_playerData.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v3 = (OSuitePrivate::ZPlayerConsumableData **)OSuite::ZObject::malloc(&this->m_playerData, 0x80ui64, 0i64);
  this->m_playerData.m_nTop = 0i64;
  this->m_playerData.m_nSize = 16i64;
  this->m_playerData.m_pList = v3;
}

// File Line: 39
// RVA: 0x13317C4
void __fastcall OSuitePrivate::ZEidosConsumables::~ZEidosConsumables(OSuitePrivate::ZEidosConsumables *this)
{
  bool v1; // zf
  OSuitePrivate::ZPlayerConsumableData **m_pList; // rdx

  v1 = !this->m_bInit;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuitePrivate::ZEidosConsumables::`vftable;
  if ( !v1 )
    OSuitePrivate::ZEidosConsumables::Terminate(this);
  m_pList = this->m_playerData.m_pList;
  this->m_playerData.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_playerData.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(&this->m_playerData, m_pList);
  OSuite::ZString::~ZString(&this->m_servlet);
  OSuite::ZMutex::~ZMutex(&this->m_Mutex);
}

// File Line: 49
// RVA: 0x1331E84
__int64 __fastcall OSuitePrivate::ZEidosConsumables::GetStatus(OSuitePrivate::ZEidosConsumables *this)
{
  return (unsigned int)this->m_eStatus;
}

// File Line: 57
// RVA: 0x1331F84
__int64 __fastcall OSuitePrivate::ZEidosConsumables::Initialize(OSuitePrivate::ZEidosConsumables *this)
{
  OSuite::ConsumableError v1; // esi
  char *v4; // rbx
  OSuite::ZOnlineSuite *v5; // rax
  OSuite::ZWebServiceClient *v6; // rax
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> cb; // [rsp+20h] [rbp-18h] BYREF

  v1 = OS_CONSUMABLES_OK;
  if ( this->m_bInit )
    return 0i64;
  if ( this->m_pWebServiceClient )
    return (unsigned int)this->m_eStatus;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( this->m_pWebServiceClient )
    goto LABEL_10;
  cb.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)this;
  cb.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuitePrivate::ZEidosConsumables::DataInitializedCB;
  v4 = OSuite::ZString::c_str(&this->m_servlet);
  v5 = OSuite::ZOnlineSuite::Instance();
  v6 = OSuite::ZOnlineSuite::CreateWebServiceClient(v5, v4, &cb);
  this->m_pWebServiceClient = v6;
  if ( v6 )
  {
    if ( (unsigned int)OSuitePrivate::ZEidosTransaction::GetState((OSuite::Statistics *)v6) == 2 )
    {
      OSuite::ZWebServiceClient::Release(this->m_pWebServiceClient);
      this->m_pWebServiceClient = 0i64;
      this->m_eStatus = OS_CONSUMABLES_WEBSERVICE_FAILURE;
      goto LABEL_9;
    }
LABEL_10:
    if ( (unsigned int)OSuitePrivate::ZEidosTransaction::GetState((OSuite::Statistics *)this->m_pWebServiceClient) )
    {
      this->m_bInit = 1;
    }
    else
    {
      this->m_bInit = 0;
      v1 = OS_CONSUMABLES_INITIALIZING;
    }
    this->m_eStatus = v1;
    goto LABEL_14;
  }
LABEL_9:
  v1 = OS_CONSUMABLES_ERROR_UNKNOWN;
  ((void (__fastcall *)(OSuitePrivate::ZEidosConsumables *))this->vfptr[3].__vecDelDtor)(this);
LABEL_14:
  OSuite::ZMutex::Unlock(&this->m_Mutex);
  return (unsigned int)v1;
}

// File Line: 113
// RVA: 0x1332634
__int64 __fastcall OSuitePrivate::ZEidosConsumables::Terminate(OSuitePrivate::ZEidosConsumables *this)
{
  OSuite::ZWebServiceClient *m_pWebServiceClient; // rcx
  OSuite::ZOFeed *m_pConsumableFeed; // rdx

  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( this->m_bInit )
  {
    this->m_bInit = 0;
    OSuitePrivate::ZEidosConsumables::TermUserData(this);
    m_pWebServiceClient = this->m_pWebServiceClient;
    if ( m_pWebServiceClient )
    {
      m_pConsumableFeed = this->m_pConsumableFeed;
      if ( m_pConsumableFeed )
      {
        OSuite::ZWebServiceClient::CloseRequest(m_pWebServiceClient, m_pConsumableFeed);
        this->m_pConsumableFeed = 0i64;
      }
      OSuite::ZWebServiceClient::Release(this->m_pWebServiceClient);
      this->m_pWebServiceClient = 0i64;
    }
    this->m_eStatus = OS_CONSUMABLES_ERROR_NOTINIT;
  }
  OSuite::ZMutex::Unlock(&this->m_Mutex);
  return 0i64;
}

// File Line: 144
// RVA: 0x13326A4
void __fastcall OSuitePrivate::ZEidosConsumables::Update(OSuitePrivate::ZEidosConsumables *this)
{
  OSuite::ZOFeed *m_pConsumableFeed; // rdx
  OSuite::ZWebServiceClient *m_pWebServiceClient; // rcx

  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( this->m_bInit && OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_playerData) )
  {
    if ( OSuitePrivate::ZEidosConsumables::RequestToProcess(this) )
    {
      OSuitePrivate::ZEidosConsumables::ProcessRequests(this);
    }
    else if ( !this->m_bQueryInProgress )
    {
      if ( OSuitePrivate::ZEidosConsumables::Refresh(this) )
      {
        m_pConsumableFeed = this->m_pConsumableFeed;
        if ( m_pConsumableFeed )
        {
          OSuite::ZWebServiceClient::CloseRequest(this->m_pWebServiceClient, m_pConsumableFeed);
          this->m_pConsumableFeed = 0i64;
        }
        this->m_bRefreshAll = !OSuitePrivate::ZEidosConsumables::QueryData(this);
      }
      else
      {
        OSuitePrivate::ZEidosConsumables::UpdateData(this);
      }
    }
  }
  else
  {
    m_pWebServiceClient = this->m_pWebServiceClient;
    if ( m_pWebServiceClient && this->m_eStatus == OS_CONSUMABLES_WEBSERVICE_FAILURE )
    {
      OSuite::ZWebServiceClient::Release(m_pWebServiceClient);
      this->m_pWebServiceClient = 0i64;
    }
  }
  OSuite::ZMutex::Unlock(&this->m_Mutex);
}

// File Line: 189
// RVA: 0x1331CA8
__int64 __fastcall OSuitePrivate::ZEidosConsumables::GetCount(
        OSuitePrivate::ZEidosConsumables *this,
        OSuite::IPlayerAccount *pPlayerAccount)
{
  OSuite::ZMutex *p_m_Mutex; // rbp
  unsigned int Count; // edi
  unsigned __int64 v6; // rdi
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_playerData; // rbx
  unsigned __int64 v8; // rsi
  unsigned __int64 pUserIndex; // [rsp+30h] [rbp+8h] BYREF

  p_m_Mutex = &this->m_Mutex;
  Count = 0;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( OSuitePrivate::ZEidosConsumables::ValidateUser(this, pPlayerAccount, &pUserIndex) == OS_CONSUMABLES_OK )
  {
    v6 = pUserIndex;
    p_m_playerData = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData;
    v8 = pUserIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, pUserIndex + 1);
    if ( v6 >= p_m_playerData->m_nTop )
      p_m_playerData->m_nTop = v8;
    Count = OSuitePrivate::ZPlayerConsumableData::GetCount((OSuitePrivate::ZPlayerConsumableData *)p_m_playerData->m_pList[v6]);
  }
  OSuite::ZMutex::Unlock(p_m_Mutex);
  return Count;
}

// File Line: 210
// RVA: 0x1331D34
__int64 __fastcall OSuitePrivate::ZEidosConsumables::GetInfo(
        OSuitePrivate::ZEidosConsumables *this,
        OSuite::IPlayerAccount *pPlayerAccount,
        const char *consumableId,
        OSuite::IConsumableInfo **ppInfo)
{
  OSuite::ConsumableError Info; // ebx
  unsigned __int64 v9; // rsi
  unsigned __int64 v10; // rbp
  unsigned __int64 pUserIndex; // [rsp+50h] [rbp+8h] BYREF

  OSuite::ZMutex::Lock(&this->m_Mutex);
  Info = OS_CONSUMABLES_ERROR_INVALIDARG;
  if ( ppInfo )
  {
    Info = OSuitePrivate::ZEidosConsumables::ValidateUser(this, pPlayerAccount, &pUserIndex);
    if ( Info == OS_CONSUMABLES_OK )
    {
      v9 = pUserIndex;
      v10 = pUserIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData,
        pUserIndex + 1);
      if ( v9 >= this->m_playerData.m_nTop )
        this->m_playerData.m_nTop = v10;
      Info = OSuitePrivate::ZPlayerConsumableData::GetInfo(this->m_playerData.m_pList[v9], consumableId, ppInfo);
      if ( Info == OS_CONSUMABLES_OK )
        Info = this->m_eStatus;
    }
  }
  OSuite::ZMutex::Unlock(&this->m_Mutex);
  return (unsigned int)Info;
}

// File Line: 240
// RVA: 0x1331DDC
__int64 __fastcall OSuitePrivate::ZEidosConsumables::GetNextInfo(
        OSuitePrivate::ZEidosConsumables *this,
        OSuite::IPlayerAccount *pPlayerAccount,
        unsigned int consumableIndex,
        OSuite::IConsumableInfo **ppInfo)
{
  OSuite::ConsumableError NextInfo; // ebx
  unsigned __int64 v9; // rsi
  unsigned __int64 v10; // rbp
  unsigned __int64 pUserIndex; // [rsp+50h] [rbp+8h] BYREF

  OSuite::ZMutex::Lock(&this->m_Mutex);
  NextInfo = OS_CONSUMABLES_ERROR_INVALIDARG;
  if ( ppInfo )
  {
    NextInfo = OSuitePrivate::ZEidosConsumables::ValidateUser(this, pPlayerAccount, &pUserIndex);
    if ( NextInfo == OS_CONSUMABLES_OK )
    {
      v9 = pUserIndex;
      v10 = pUserIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData,
        pUserIndex + 1);
      if ( v9 >= this->m_playerData.m_nTop )
        this->m_playerData.m_nTop = v10;
      NextInfo = OSuitePrivate::ZPlayerConsumableData::GetNextInfo(
                   this->m_playerData.m_pList[v9],
                   consumableIndex,
                   ppInfo);
      if ( NextInfo == OS_CONSUMABLES_OK )
        NextInfo = this->m_eStatus;
    }
  }
  OSuite::ZMutex::Unlock(&this->m_Mutex);
  return (unsigned int)NextInfo;
}

// File Line: 269
// RVA: 0x13319BC
__int64 __fastcall OSuitePrivate::ZEidosConsumables::Consume(
        OSuitePrivate::ZEidosConsumables *this,
        OSuite::IPlayerAccount *pPlayerAccount,
        OSuite::IConsumableInfo *pInfo)
{
  OSuite::ZMutex *p_m_Mutex; // rbp
  OSuite::ConsumableError v7; // ebx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_playerData; // rbx
  unsigned __int64 v9; // rdi
  unsigned __int64 v10; // rsi
  unsigned __int64 pUserIndex; // [rsp+40h] [rbp+8h] BYREF

  p_m_Mutex = &this->m_Mutex;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v7 = OS_CONSUMABLES_ERROR_INVALIDARG;
  if ( pInfo )
  {
    v7 = OSuitePrivate::ZEidosConsumables::ValidateUser(this, pPlayerAccount, &pUserIndex);
    if ( v7 == OS_CONSUMABLES_OK )
    {
      p_m_playerData = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData;
      v9 = pUserIndex;
      v10 = pUserIndex + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, pUserIndex + 1);
      if ( v9 >= p_m_playerData->m_nTop )
        p_m_playerData->m_nTop = v10;
      v7 = OSuitePrivate::ZPlayerConsumableData::Consume(
             (OSuitePrivate::ZPlayerConsumableData *)p_m_playerData->m_pList[v9],
             pInfo);
    }
  }
  OSuite::ZMutex::Unlock(p_m_Mutex);
  return (unsigned int)v7;
}

// File Line: 296
// RVA: 0x1332524
__int64 __fastcall OSuitePrivate::ZEidosConsumables::SetServlet(
        OSuitePrivate::ZEidosConsumables *this,
        OSuite::ZString *servlet)
{
  OSuite::ZString::operator=(&this->m_servlet, servlet);
  return 0i64;
}

// File Line: 306
// RVA: 0x133184C
__int64 __fastcall OSuitePrivate::ZEidosConsumables::AddUser(
        OSuitePrivate::ZEidosConsumables *this,
        OSuite::IPlayerAccount *pPlayerAccount)
{
  OSuite::ConsumableError v4; // ebp
  OSuitePrivate::ZPlayerConsumableData *v5; // rax
  OSuitePrivate::ZPlayerConsumableData *v6; // rax
  OSuitePrivate::ZPlayerConsumableData *v7; // rdi

  OSuite::ZMutex::Lock(&this->m_Mutex);
  this->m_bRefreshAll = 1;
  v4 = OSuitePrivate::ZEidosConsumables::ValidateUser(this, pPlayerAccount, 0i64);
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
      OSuitePrivate::ZPlayerConsumableData::ZPlayerConsumableData(v5, pPlayerAccount);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    if ( v7 )
    {
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData,
        this->m_playerData.m_nTop + 1);
      this->m_playerData.m_pList[this->m_playerData.m_nTop++] = v7;
    }
  }
  OSuite::ZMutex::Unlock(&this->m_Mutex);
  return (unsigned int)v4;
}

// File Line: 339
// RVA: 0x1332070
__int64 __fastcall OSuitePrivate::ZEidosConsumables::NewTransaction(
        OSuitePrivate::ZEidosConsumables *this,
        OSuite::IPlayerAccount *pPlayerAccount,
        OSuite::TList<OSuite::IConsumableInfo *> *infos,
        const char *tag)
{
  OSuite::ZMutex *p_m_Mutex; // rbp
  OSuite::ConsumableError v9; // ebx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_playerData; // rbx
  unsigned __int64 v11; // rdi
  unsigned __int64 v12; // rsi
  unsigned __int64 pUserIndex; // [rsp+40h] [rbp+8h] BYREF

  p_m_Mutex = &this->m_Mutex;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v9 = OSuitePrivate::ZEidosConsumables::ValidateUser(this, pPlayerAccount, &pUserIndex);
  if ( v9 == OS_CONSUMABLES_OK )
  {
    p_m_playerData = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData;
    v11 = pUserIndex;
    v12 = pUserIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, pUserIndex + 1);
    if ( v11 >= p_m_playerData->m_nTop )
      p_m_playerData->m_nTop = v12;
    v9 = OSuitePrivate::ZPlayerConsumableData::NewTransaction(
           (OSuitePrivate::ZPlayerConsumableData *)p_m_playerData->m_pList[v11],
           infos,
           tag);
  }
  OSuite::ZMutex::Unlock(p_m_Mutex);
  return (unsigned int)v9;
}

// File Line: 357
// RVA: 0x1331C18
__int64 __fastcall OSuitePrivate::ZEidosConsumables::GetActiveTransaction(
        OSuitePrivate::ZEidosConsumables *this,
        OSuite::IPlayerAccount *pPlayerAccount,
        OSuite::IConsumableTransaction **ppTransaction)
{
  OSuite::ZMutex *p_m_Mutex; // rbp
  OSuite::ConsumableError ActiveTransaction; // ebx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_playerData; // rbx
  unsigned __int64 v9; // rdi
  unsigned __int64 v10; // rsi
  unsigned __int64 pUserIndex; // [rsp+40h] [rbp+8h] BYREF

  p_m_Mutex = &this->m_Mutex;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  ActiveTransaction = OSuitePrivate::ZEidosConsumables::ValidateUser(this, pPlayerAccount, &pUserIndex);
  if ( ActiveTransaction == OS_CONSUMABLES_OK )
  {
    p_m_playerData = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData;
    v9 = pUserIndex;
    v10 = pUserIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, pUserIndex + 1);
    if ( v9 >= p_m_playerData->m_nTop )
      p_m_playerData->m_nTop = v10;
    ActiveTransaction = OSuitePrivate::ZPlayerConsumableData::GetActiveTransaction(
                          (OSuitePrivate::ZPlayerConsumableData *)p_m_playerData->m_pList[v9],
                          ppTransaction);
  }
  OSuite::ZMutex::Unlock(p_m_Mutex);
  return (unsigned int)ActiveTransaction;
}

// File Line: 375
// RVA: 0x1331930
__int64 __fastcall OSuitePrivate::ZEidosConsumables::CloseActiveTransaction(
        OSuitePrivate::ZEidosConsumables *this,
        OSuite::IPlayerAccount *pPlayerAccount)
{
  OSuite::ZMutex *p_m_Mutex; // rbp
  OSuite::ConsumableError v5; // ebx
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_playerData; // rbx
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // rsi
  unsigned __int64 pUserIndex; // [rsp+30h] [rbp+8h] BYREF

  p_m_Mutex = &this->m_Mutex;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  v5 = OSuitePrivate::ZEidosConsumables::ValidateUser(this, pPlayerAccount, &pUserIndex);
  if ( v5 == OS_CONSUMABLES_OK )
  {
    p_m_playerData = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData;
    v7 = pUserIndex;
    v8 = pUserIndex + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, pUserIndex + 1);
    if ( v7 >= p_m_playerData->m_nTop )
      p_m_playerData->m_nTop = v8;
    v5 = OSuitePrivate::ZPlayerConsumableData::CloseActiveTransaction((OSuitePrivate::ZPlayerConsumableData *)p_m_playerData->m_pList[v7]);
  }
  OSuite::ZMutex::Unlock(p_m_Mutex);
  return (unsigned int)v5;
}

// File Line: 396
// RVA: 0x1331E88
OSuitePrivate::ZEidosTransaction *__fastcall OSuitePrivate::ZEidosConsumables::GetTransaction(
        OSuitePrivate::ZEidosConsumables *this,
        unsigned __int64 userIndex)
{
  OSuitePrivate::ZEidosTransaction *m_pTransaction; // rsi

  m_pTransaction = 0i64;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( userIndex < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_playerData) )
  {
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData,
      userIndex + 1);
    if ( userIndex >= this->m_playerData.m_nTop )
      this->m_playerData.m_nTop = userIndex + 1;
    m_pTransaction = this->m_playerData.m_pList[userIndex]->m_pTransaction;
  }
  OSuite::ZMutex::Unlock(&this->m_Mutex);
  return m_pTransaction;
}

// File Line: 412
// RVA: 0x1331F08
OSuite::IPlayerAccount *__fastcall OSuitePrivate::ZEidosConsumables::GetUser(
        OSuitePrivate::ZEidosConsumables *this,
        unsigned __int64 userIndex)
{
  OSuite::IPlayerAccount *m_pPlayerProfile; // rsi

  m_pPlayerProfile = 0i64;
  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( userIndex < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_playerData) )
  {
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData,
      userIndex + 1);
    if ( userIndex >= this->m_playerData.m_nTop )
      this->m_playerData.m_nTop = userIndex + 1;
    m_pPlayerProfile = this->m_playerData.m_pList[userIndex]->m_pPlayerProfile;
  }
  OSuite::ZMutex::Unlock(&this->m_Mutex);
  return m_pPlayerProfile;
}

// File Line: 430
// RVA: 0x1332178
bool __fastcall OSuitePrivate::ZEidosConsumables::QueryData(OSuitePrivate::ZEidosConsumables *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_playerData; // rdi
  bool v3; // si
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // r14
  unsigned __int64 v6; // r14
  char *v7; // rax
  unsigned __int64 v8; // r15
  char *v9; // rbx
  OSuite::ZOFilter *v10; // rax
  OSuite::ZOFilter *v11; // rax
  OSuite::ZWebServiceClient *m_pWebServiceClient; // rcx
  bool v13; // al
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> cb; // [rsp+20h] [rbp-E0h] BYREF
  OSuite::ZOFilter v16; // [rsp+30h] [rbp-D0h] BYREF
  OSuite::ZString v17; // [rsp+68h] [rbp-98h] BYREF
  OSuite::ZOFilter filterExpression; // [rsp+80h] [rbp-80h] BYREF
  OSuite::ZOQuery query; // [rsp+C0h] [rbp-40h] BYREF

  p_m_playerData = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData;
  v3 = 0;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_playerData) )
  {
    query.m_entityName.m_pString = 0i64;
    query.m_queryMap.m_pLists = 0i64;
    query.m_functionParameters.m_pLists = 0i64;
    OSuite::ZOQuery::ZOQuery(&query);
    OSuite::ZOQuery::EntitySet(&query, "consumables");
    v4 = 0i64;
    if ( !this->m_bRefreshAll && OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)p_m_playerData) )
    {
      do
      {
        v5 = v4 + 1;
        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, v4 + 1);
        if ( v4 >= p_m_playerData->m_nTop )
          p_m_playerData->m_nTop = v5;
        if ( LOBYTE(p_m_playerData->m_pList[v4]->m_pLeft) )
          break;
        ++v4;
      }
      while ( v5 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)p_m_playerData) );
    }
    if ( v4 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)p_m_playerData) )
    {
      v6 = v4 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, v4 + 1);
      if ( v4 >= p_m_playerData->m_nTop )
        p_m_playerData->m_nTop = v6;
      OSuitePrivate::ZPlayerConsumableData::InitData((OSuitePrivate::ZPlayerConsumableData *)p_m_playerData->m_pList[v4]);
      v17.m_pString = 0i64;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, v4 + 1);
      if ( v4 >= p_m_playerData->m_nTop )
        p_m_playerData->m_nTop = v6;
      OSuite::ZString::ZString(&v17, (OSuite::ZString *)&p_m_playerData->m_pList[v4]->m_eColour);
      filterExpression.m_queryBuilder.m_Chars.m_pList = 0i64;
      OSuite::ZOFilter::ZOFilter(&filterExpression);
      v7 = OSuite::ZString::c_str(&v17);
      OSuite::ZOFilter::Compare(&filterExpression, "_id", v7, EQUAL);
      if ( v6 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)p_m_playerData) )
      {
        v8 = v4 + 2;
        do
        {
          if ( this->m_bRefreshAll )
            goto LABEL_19;
          OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, v8);
          if ( v6 >= p_m_playerData->m_nTop )
            p_m_playerData->m_nTop = v8;
          if ( LOBYTE(p_m_playerData->m_pList[v6]->m_pLeft) )
          {
LABEL_19:
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, v8);
            if ( v6 >= p_m_playerData->m_nTop )
              p_m_playerData->m_nTop = v8;
            OSuitePrivate::ZPlayerConsumableData::InitData((OSuitePrivate::ZPlayerConsumableData *)p_m_playerData->m_pList[v6]);
            OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, v8);
            if ( v6 >= p_m_playerData->m_nTop )
              p_m_playerData->m_nTop = v8;
            OSuite::ZString::operator=(&v17, (OSuite::ZString *)&p_m_playerData->m_pList[v6]->m_eColour);
            v9 = OSuite::ZString::c_str(&v17);
            OSuite::ZOFilter::ZOFilter(&v16);
            v11 = OSuite::ZOFilter::Compare(v10, "_id", v9, EQUAL);
            OSuite::ZOFilter::Or(&filterExpression, v11);
            OSuite::ZOFilter::~ZOFilter(&v16);
          }
          ++v6;
          ++v8;
        }
        while ( v6 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)p_m_playerData) );
      }
      OSuite::ZOQuery::Filter(&query, &filterExpression);
      m_pWebServiceClient = this->m_pWebServiceClient;
      cb.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuitePrivate::ZEidosConsumables::FeedFetchedCB;
      cb.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)this;
      v13 = OSuite::ZWebServiceClient::ExecuteQuery(m_pWebServiceClient, &query, &cb);
      this->m_bQueryInProgress = 1;
      this->m_eStatus = OS_CONSUMABLES_FETCHINGDATA;
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
  OSuite::ZOFeed *m_pConsumableFeed; // rcx
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase *Entry; // rbx
  char v6; // al
  OSuite::ZMetricAppender *v7; // r14
  OSuite::ZOProperty *v8; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase *v9; // rax
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_playerData; // rsi
  unsigned __int64 v11; // rbx
  OSuite::ZString outValue; // [rsp+20h] [rbp-38h] BYREF

  m_pConsumableFeed = this->m_pConsumableFeed;
  v3 = 0i64;
  if ( m_pConsumableFeed && this->m_eStatus == OS_CONSUMABLES_FETCHINGDATA )
  {
    v4 = 0i64;
    if ( OSuite::ZAtomFeed::TotalEntries(m_pConsumableFeed) )
    {
      do
      {
        Entry = OSuite::ZAtomFeed::GetEntry(this->m_pConsumableFeed, v4);
        v6 = -(__int64)Entry->vfptr[1].__vecDelDtor(Entry, OSuite::ZOEntry::s_nClassId);
        v7 = (OSuite::ZMetricAppender *)((unsigned __int64)Entry & -(__int64)(v6 != 0));
        if ( v7 )
        {
          v8 = OSuite::ZOEntry::Property((OSuite::ZOEntry *)((unsigned __int64)Entry & -(__int64)(v6 != 0)), "_id");
          if ( v8 )
          {
            outValue.m_pString = 0i64;
            OSuite::ZString::ZString(&outValue);
            if ( OSuite::ZOProperty::GetValue(v8, &outValue) )
            {
              v9 = OSuitePrivate::ZEidosConsumables::Find(this, &outValue, 0i64);
              if ( v9 )
                OSuitePrivate::ZPlayerConsumableData::SetConsumablesData((OSuite::ZUsageTracker *)v9, v7);
            }
            OSuite::ZString::~ZString(&outValue);
          }
        }
        ++v4;
      }
      while ( v4 < OSuite::ZAtomFeed::TotalEntries(this->m_pConsumableFeed) );
    }
    this->m_eStatus = OS_CONSUMABLES_OK;
  }
  p_m_playerData = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)p_m_playerData) )
  {
    do
    {
      v11 = v3 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, v3 + 1);
      if ( v3 >= p_m_playerData->m_nTop )
        p_m_playerData->m_nTop = v11;
      OSuitePrivate::ZPlayerConsumableData::UpdateData((OSuitePrivate::ZPlayerConsumableData *)p_m_playerData->m_pList[v3++]);
    }
    while ( v11 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)p_m_playerData) );
  }
}

// File Line: 521
// RVA: 0x1332110
void __fastcall OSuitePrivate::ZEidosConsumables::ProcessRequests(OSuitePrivate::ZEidosConsumables *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_playerData; // rbx
  unsigned __int64 v2; // rdi
  unsigned __int64 v3; // rsi

  p_m_playerData = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData;
  v2 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_playerData) )
  {
    do
    {
      v3 = v2 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, v2 + 1);
      if ( v2 >= p_m_playerData->m_nTop )
        p_m_playerData->m_nTop = v3;
      OSuitePrivate::ZPlayerConsumableData::ProcessRequests((OSuitePrivate::ZPlayerConsumableData *)p_m_playerData->m_pList[v2++]);
    }
    while ( v3 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)p_m_playerData) );
  }
}

// File Line: 530
// RVA: 0x13324AC
char __fastcall OSuitePrivate::ZEidosConsumables::RequestToProcess(OSuitePrivate::ZEidosConsumables *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_playerData; // rbx
  unsigned __int64 v2; // rdi
  unsigned __int64 v3; // rsi

  p_m_playerData = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData;
  v2 = 0i64;
  if ( !OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_playerData) )
    return 0;
  while ( 1 )
  {
    v3 = v2 + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, v2 + 1);
    if ( v2 >= p_m_playerData->m_nTop )
      p_m_playerData->m_nTop = v3;
    if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&p_m_playerData->m_pList[v2][3].m_pLeft) )
      break;
    ++v2;
    if ( v3 >= OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)p_m_playerData) )
      return 0;
  }
  return 1;
}

// File Line: 544
// RVA: 0x1332538
void __fastcall OSuitePrivate::ZEidosConsumables::TermUserData(OSuitePrivate::ZEidosConsumables *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_playerData; // rbx
  __int64 v2; // rsi
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase *v5; // rcx
  __int64 v6; // rax

  p_m_playerData = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_playerData) )
  {
    v2 = 0i64;
    v3 = 1i64;
    do
    {
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, v3);
      v4 = v3 - 1;
      if ( v3 - 1 >= p_m_playerData->m_nTop )
        p_m_playerData->m_nTop = v3;
      OSuitePrivate::ZPlayerConsumableData::TermData((OSuitePrivate::ZPlayerConsumableData *)p_m_playerData->m_pList[v2]);
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, v3);
      if ( v4 >= p_m_playerData->m_nTop )
        p_m_playerData->m_nTop = v3;
      v5 = p_m_playerData->m_pList[v2];
      if ( v5 )
        v5->vfptr->__vecDelDtor(v5, 1u);
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, v3);
      if ( v4 >= p_m_playerData->m_nTop )
        p_m_playerData->m_nTop = v3;
      ++v3;
      p_m_playerData->m_pList[v2++] = 0i64;
    }
    while ( v3 - 1 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)p_m_playerData) );
  }
  OSuite::ZObject::free(p_m_playerData, p_m_playerData->m_pList);
  v6 = OSuite::ZObject::malloc(p_m_playerData, 0x80ui64, 0i64);
  p_m_playerData->m_nTop = 0i64;
  p_m_playerData->m_pList = (OSuite::ZRedBlackTreeBase::ZElementBase **)v6;
  p_m_playerData->m_nSize = 16i64;
}

// File Line: 559
// RVA: 0x13328B0
__int64 __fastcall OSuitePrivate::ZEidosConsumables::ValidateUser(
        OSuitePrivate::ZEidosConsumables *this,
        OSuite::IPlayerAccount *pPlayerAccount,
        unsigned __int64 *pUserIndex)
{
  OSuite::ZString *v6; // rax

  if ( !this->m_bInit )
    return this->m_pWebServiceClient != 0i64 ? 1 : -2147483392;
  v6 = pPlayerAccount->vfptr->GetUserId(pPlayerAccount, 0i64);
  return OSuitePrivate::ZEidosConsumables::Find(this, v6, pUserIndex) == 0i64 ? 0x80000105 : 0;
}

// File Line: 575
// RVA: 0x1331B00
OSuite::ZRedBlackTreeBase::ZElementBase *__fastcall OSuitePrivate::ZEidosConsumables::Find(
        OSuitePrivate::ZEidosConsumables *this,
        OSuite::ZString *userId,
        unsigned __int64 *pUserIndex)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_playerData; // rbx
  int v4; // esi
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // rbp
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pRight; // rcx
  OSuite::ZString *v10; // r14
  OSuite::ZString *v11; // rax
  bool v12; // r14
  OSuite::ZString result; // [rsp+20h] [rbp-48h] BYREF

  p_m_playerData = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData;
  v4 = 0;
  v7 = 0i64;
  if ( !OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_playerData) )
    return 0i64;
  while ( 1 )
  {
    v8 = v7 + 1;
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, v7 + 1);
    if ( v7 >= p_m_playerData->m_nTop )
      p_m_playerData->m_nTop = v8;
    m_pRight = p_m_playerData->m_pList[v7]->m_pRight;
    v10 = (OSuite::ZString *)m_pRight->vfptr[2].__vecDelDtor(m_pRight, 0);
    v12 = 1;
    if ( !OSuite::ZString::operator==(v10, userId) )
    {
      v4 |= 1u;
      v11 = OSuite::operator+(&result, &customCaption, v10);
      if ( !OSuite::ZString::operator==(v11, userId) )
        v12 = 0;
    }
    if ( (v4 & 1) != 0 )
    {
      v4 &= ~1u;
      OSuite::ZString::~ZString(&result);
    }
    if ( v12 )
      break;
    ++v7;
    if ( v8 >= OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)p_m_playerData) )
      return 0i64;
  }
  if ( pUserIndex )
    *pUserIndex = v7;
  OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, v7 + 1);
  if ( v7 >= p_m_playerData->m_nTop )
    p_m_playerData->m_nTop = v7 + 1;
  return p_m_playerData->m_pList[v7];
}

// File Line: 594
// RVA: 0x1332434
char __fastcall OSuitePrivate::ZEidosConsumables::Refresh(OSuitePrivate::ZEidosConsumables *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_playerData; // rbx
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rsi

  if ( this->m_bRefreshAll )
    return 1;
  p_m_playerData = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_playerData;
  v3 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_playerData) )
  {
    while ( 1 )
    {
      v4 = v3 + 1;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_playerData, v3 + 1);
      if ( v3 >= p_m_playerData->m_nTop )
        p_m_playerData->m_nTop = v4;
      if ( LOBYTE(p_m_playerData->m_pList[v3]->m_pLeft) )
        break;
      ++v3;
      if ( v4 >= OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)p_m_playerData) )
        return 0;
    }
    return 1;
  }
  return 0;
}

// File Line: 611
// RVA: 0x1331A54
void __fastcall OSuitePrivate::ZEidosConsumables::DataInitializedCB(
        OSuitePrivate::ZEidosConsumables *this,
        OSuite::SCallbackData *pData,
        OSuite::ZWebServiceClient *__formal)
{
  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( pData->Status.eError )
    this->m_eStatus = OS_CONSUMABLES_WEBSERVICE_FAILURE;
  else
    *(_WORD *)&this->m_bInit = 257;
  OSuite::ZMutex::Unlock(&this->m_Mutex);
}

// File Line: 629
// RVA: 0x1331AA0
void __fastcall OSuitePrivate::ZEidosConsumables::FeedFetchedCB(
        OSuitePrivate::ZEidosConsumables *this,
        OSuite::SCallbackData *pData,
        OSuite::ZWebServiceClient *pWebServiceClient)
{
  OSuite::ZMutex::Lock(&this->m_Mutex);
  if ( pData->Status.eError == HTTPERROR_OK )
    this->m_pConsumableFeed = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOFeed>(pWebServiceClient, &pData->URL);
  this->m_bQueryInProgress = 0;
  OSuite::ZMutex::Unlock(&this->m_Mutex);
}

