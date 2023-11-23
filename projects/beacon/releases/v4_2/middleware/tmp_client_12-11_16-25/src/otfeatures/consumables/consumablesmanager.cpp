// File Line: 22
// RVA: 0x132F360
// attributes: thunk
OSuitePrivate::ConsumablesManager *__fastcall OSuite::IConsumablesManager::GetConsumableManager()
{
  return OSuite::TSingleton<OSuitePrivate::ConsumablesManager>::Object();
}

// File Line: 31
// RVA: 0x15DF9C0
__int64 dynamic_initializer_for__OSuitePrivate::ConsumablesManager::m_instance__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__OSuitePrivate::ConsumablesManager::m_instance__);
}

// File Line: 46
// RVA: 0x132EAAC
void __fastcall OSuitePrivate::ConsumablesManager::ConsumablesManager(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::ZObject *a2)
{
  OSuite::TList<OSuite::IPlayerAccount *> *p_m_TransactionRequested; // rbx
  __int64 v4; // rax

  this->m_platformConsumables = 0i64;
  this->m_pEidosConsumables = 0i64;
  this->m_pPlatformOnlyTransaction = 0i64;
  p_m_TransactionRequested = &this->m_TransactionRequested;
  this->OSuite::IConsumablesManager::vfptr = (OSuite::IConsumablesManagerVtbl *)&OSuitePrivate::ConsumablesManager::`vftable{for `OSuite::IConsumablesManager};
  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuitePrivate::ConsumablesManager::`vftable{for `OSuite::ZObject};
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&this->m_TransactionRequested, a2);
  p_m_TransactionRequested->m_pList = 0i64;
  p_m_TransactionRequested->OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  p_m_TransactionRequested->OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  v4 = OSuite::ZObject::malloc(p_m_TransactionRequested, 0x80ui64, 0i64);
  p_m_TransactionRequested->m_nTop = 0i64;
  p_m_TransactionRequested->m_pList = (OSuite::IPlayerAccount **)v4;
  p_m_TransactionRequested->m_nSize = 16i64;
  OSuite::ZMutex::ZMutex(&this->m_mutex);
  this->m_httpRequest = 0i64;
  *(_WORD *)&this->m_bRequestInProgress = 0;
  OSuite::ZString::ZString(&this->m_finalizeData);
}

// File Line: 54
// RVA: 0x132EB50
void __fastcall OSuitePrivate::ConsumablesManager::~ConsumablesManager(OSuitePrivate::ConsumablesManager *this)
{
  OSuitePrivate::ZConsumableTransactionBase *m_pPlatformOnlyTransaction; // rcx
  OSuite::IPlayerAccount **m_pList; // rdx

  this->OSuite::IConsumablesManager::vfptr = (OSuite::IConsumablesManagerVtbl *)&OSuitePrivate::ConsumablesManager::`vftable{for `OSuite::IConsumablesManager};
  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuitePrivate::ConsumablesManager::`vftable{for `OSuite::ZObject};
  m_pPlatformOnlyTransaction = this->m_pPlatformOnlyTransaction;
  if ( m_pPlatformOnlyTransaction )
  {
    ((void (__fastcall *)(OSuitePrivate::ZConsumableTransactionBase *, __int64))m_pPlatformOnlyTransaction->OSuite::IConsumableTransaction::vfptr->~IConsumableTransaction)(
      m_pPlatformOnlyTransaction,
      1i64);
    this->m_pPlatformOnlyTransaction = 0i64;
  }
  OSuite::ZString::~ZString(&this->m_finalizeData);
  OSuite::ZMutex::~ZMutex(&this->m_mutex);
  m_pList = this->m_TransactionRequested.m_pList;
  this->m_TransactionRequested.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
  this->m_TransactionRequested.vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(&this->m_TransactionRequested, m_pList);
}

// File Line: 66
// RVA: 0x1330A0C
void __fastcall OSuitePrivate::ConsumablesManager::Update(OSuitePrivate::ConsumablesManager *this)
{
  OSuitePrivate::ZPlatformConsumables *m_platformConsumables; // rcx
  int v3; // esi
  OSuitePrivate::ZEidosConsumables *m_pEidosConsumables; // rcx

  OSuite::ZMutex::Lock(&this->m_mutex);
  m_platformConsumables = this->m_platformConsumables;
  v3 = 0;
  if ( m_platformConsumables )
  {
    ((void (__fastcall *)(OSuitePrivate::ZPlatformConsumables *))m_platformConsumables->vfptr[4].__vecDelDtor)(m_platformConsumables);
    v3 = ((__int64 (__fastcall *)(OSuitePrivate::ZPlatformConsumables *))this->m_platformConsumables->vfptr[2].__vecDelDtor)(this->m_platformConsumables);
  }
  m_pEidosConsumables = this->m_pEidosConsumables;
  if ( m_pEidosConsumables )
  {
    ((void (__fastcall *)(OSuitePrivate::ZEidosConsumables *))m_pEidosConsumables->vfptr[4].__vecDelDtor)(m_pEidosConsumables);
    if ( !v3 )
    {
      OSuitePrivate::ConsumablesManager::CloseLostTransactions(this);
      OSuitePrivate::ConsumablesManager::CompleteTransactions(this);
      OSuitePrivate::ConsumablesManager::TransferLostConsumables(this);
    }
  }
  OSuite::ZMutex::Unlock(&this->m_mutex);
}

// File Line: 96
// RVA: 0x132F714
__int64 __fastcall OSuitePrivate::ConsumablesManager::GetStatus(OSuitePrivate::ConsumablesManager *this)
{
  OSuitePrivate::ZEidosConsumables *m_pEidosConsumables; // rcx
  unsigned int v3; // ebx
  OSuitePrivate::ZPlatformConsumables *m_platformConsumables; // rcx

  OSuite::ZMutex::Lock(&this->m_mutex);
  m_pEidosConsumables = this->m_pEidosConsumables;
  v3 = 0;
  if ( m_pEidosConsumables )
    v3 = ((__int64 (__fastcall *)(OSuitePrivate::ZEidosConsumables *))m_pEidosConsumables->vfptr[1].__vecDelDtor)(m_pEidosConsumables);
  m_platformConsumables = this->m_platformConsumables;
  if ( m_platformConsumables && !v3 )
    v3 = ((__int64 (__fastcall *)(OSuitePrivate::ZPlatformConsumables *))m_platformConsumables->vfptr[2].__vecDelDtor)(m_platformConsumables);
  OSuite::ZMutex::Unlock(&this->m_mutex);
  return v3;
}

// File Line: 116
// RVA: 0x132FBF4
__int64 __fastcall OSuitePrivate::ConsumablesManager::Initialize(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::IPlayerAccount *pPlayerProfile,
        OSuite::ZString *servlet)
{
  unsigned int v6; // edi
  OSuite::ZString *v7; // rax
  hkEntitySelectorAll *v8; // rax
  hkpEntity *v9; // rdx
  OSuite::ZOnlineSuite *v10; // rax
  OSuite::IGameConfig *GameConfig; // rax
  OSuitePrivate::ZEidosConsumables *v13; // rax

  OSuite::ZMutex::Lock(&this->m_mutex);
  v6 = 0;
  v7 = pPlayerProfile->vfptr->GetUserId(pPlayerProfile, 0i64);
  if ( OSuite::ZString::IsNull(v7) )
  {
    v6 = -2147483646;
  }
  else
  {
    v8 = (hkEntitySelectorAll *)OSuite::GameInterface();
    if ( (unsigned int)hkaReferencePoseAnimation::getNumOriginalFrames(v8, v9) == 1 )
    {
      v10 = OSuite::ZOnlineSuite::Instance();
      GameConfig = OSuite::ZOnlineSuite::GetGameConfig(v10);
      if ( !GameConfig->vfptr->GetSteamWebAPIKey(GameConfig) )
        return 2147483654i64;
    }
    if ( !this->m_pEidosConsumables && !OSuite::ZString::operator==(servlet, &customCaption) )
    {
      v13 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
      this->m_pEidosConsumables = v13;
      OSuitePrivate::ZEidosConsumables::SetServlet(v13, servlet);
      OSuitePrivate::ZEidosConsumables::AddUser(this->m_pEidosConsumables, pPlayerProfile);
      v6 = ((__int64 (__fastcall *)(OSuitePrivate::ZEidosConsumables *))this->m_pEidosConsumables->vfptr[2].__vecDelDtor)(this->m_pEidosConsumables);
    }
    if ( !this->m_platformConsumables )
      this->m_platformConsumables = 0i64;
  }
  OSuite::ZMutex::Unlock(&this->m_mutex);
  return v6;
}

// File Line: 164
// RVA: 0x1330038
__int64 __fastcall OSuitePrivate::ConsumablesManager::RegisterUser(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::IPlayerAccount *pPlayerAccount)
{
  OSuite::ConsumableError v4; // edi
  OSuitePrivate::ZEidosConsumables *m_pEidosConsumables; // rcx

  v4 = OS_CONSUMABLES_OK;
  OSuite::ZMutex::Lock(&this->m_mutex);
  m_pEidosConsumables = this->m_pEidosConsumables;
  if ( m_pEidosConsumables )
    v4 = OSuitePrivate::ZEidosConsumables::AddUser(m_pEidosConsumables, pPlayerAccount);
  OSuite::ZMutex::Unlock(&this->m_mutex);
  return (unsigned int)v4;
}

// File Line: 179
// RVA: 0x1330744
void __fastcall OSuitePrivate::ConsumablesManager::Terminate(OSuitePrivate::ConsumablesManager *this)
{
  OSuitePrivate::ZConsumableTransactionBase *m_pPlatformOnlyTransaction; // rcx
  OSuitePrivate::ZPlatformConsumables *m_platformConsumables; // rcx
  OSuitePrivate::ZEidosConsumables *m_pEidosConsumables; // rcx

  OSuite::ZMutex::Lock(&this->m_mutex);
  m_pPlatformOnlyTransaction = this->m_pPlatformOnlyTransaction;
  if ( m_pPlatformOnlyTransaction )
  {
    ((void (__fastcall *)(OSuitePrivate::ZConsumableTransactionBase *, __int64))m_pPlatformOnlyTransaction->OSuite::IConsumableTransaction::vfptr->~IConsumableTransaction)(
      m_pPlatformOnlyTransaction,
      1i64);
    this->m_pPlatformOnlyTransaction = 0i64;
  }
  m_platformConsumables = this->m_platformConsumables;
  if ( m_platformConsumables )
  {
    ((void (__fastcall *)(OSuitePrivate::ZPlatformConsumables *))m_platformConsumables->vfptr[3].__vecDelDtor)(m_platformConsumables);
    this->m_platformConsumables = 0i64;
  }
  m_pEidosConsumables = this->m_pEidosConsumables;
  if ( m_pEidosConsumables )
  {
    ((void (__fastcall *)(OSuitePrivate::ZEidosConsumables *))m_pEidosConsumables->vfptr[3].__vecDelDtor)(m_pEidosConsumables);
    this->m_pEidosConsumables = 0i64;
  }
  OSuite::ZMutex::Unlock(&this->m_mutex);
}

// File Line: 206
// RVA: 0x132F368
__int64 __fastcall OSuitePrivate::ConsumablesManager::GetCount(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::IPlayerAccount *pPlayerAccount)
{
  unsigned int v4; // ebx
  void *m_pEidosConsumables; // rcx

  v4 = 0;
  OSuite::ZMutex::Lock(&this->m_mutex);
  m_pEidosConsumables = this->m_pEidosConsumables;
  if ( m_pEidosConsumables || (m_pEidosConsumables = this->m_platformConsumables) != 0i64 )
    v4 = (*(__int64 (__fastcall **)(void *, OSuite::IPlayerAccount *))(*(_QWORD *)m_pEidosConsumables + 40i64))(
           m_pEidosConsumables,
           pPlayerAccount);
  OSuite::ZMutex::Unlock(&this->m_mutex);
  return v4;
}

// File Line: 224
// RVA: 0x132F3D4
__int64 __fastcall OSuitePrivate::ConsumablesManager::GetInfo(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::IPlayerAccount *pPlayerAccount,
        const char *consumableId,
        OSuite::IConsumableInfo **ppInfo)
{
  unsigned int v8; // ebx
  void *m_pEidosConsumables; // rcx

  v8 = -2147483643;
  OSuite::ZMutex::Lock(&this->m_mutex);
  m_pEidosConsumables = this->m_pEidosConsumables;
  if ( m_pEidosConsumables || (m_pEidosConsumables = this->m_platformConsumables) != 0i64 )
    v8 = (*(__int64 (__fastcall **)(void *, OSuite::IPlayerAccount *, const char *, OSuite::IConsumableInfo **))(*(_QWORD *)m_pEidosConsumables + 48i64))(
           m_pEidosConsumables,
           pPlayerAccount,
           consumableId,
           ppInfo);
  OSuite::ZMutex::Unlock(&this->m_mutex);
  return v8;
}

// File Line: 242
// RVA: 0x132F450
__int64 __fastcall OSuitePrivate::ConsumablesManager::GetNextInfo(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::IPlayerAccount *pPlayerAccount,
        unsigned int index,
        OSuite::IConsumableInfo **ppInfo)
{
  unsigned int v8; // ebx
  void *m_pEidosConsumables; // rcx

  v8 = -2147483643;
  OSuite::ZMutex::Lock(&this->m_mutex);
  m_pEidosConsumables = this->m_pEidosConsumables;
  if ( m_pEidosConsumables || (m_pEidosConsumables = this->m_platformConsumables) != 0i64 )
    v8 = (*(__int64 (__fastcall **)(void *, OSuite::IPlayerAccount *, _QWORD, OSuite::IConsumableInfo **))(*(_QWORD *)m_pEidosConsumables + 56i64))(
           m_pEidosConsumables,
           pPlayerAccount,
           index,
           ppInfo);
  OSuite::ZMutex::Unlock(&this->m_mutex);
  return v8;
}

// File Line: 260
// RVA: 0x132EED0
__int64 __fastcall OSuitePrivate::ConsumablesManager::Consume(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::IPlayerAccount *pPlayerAccount,
        OSuite::IConsumableInfo *pInfo)
{
  unsigned int v6; // ebx
  void *m_pEidosConsumables; // rcx

  v6 = -2147483643;
  OSuite::ZMutex::Lock(&this->m_mutex);
  m_pEidosConsumables = this->m_pEidosConsumables;
  if ( m_pEidosConsumables || (m_pEidosConsumables = this->m_platformConsumables) != 0i64 )
    v6 = (*(__int64 (__fastcall **)(void *, OSuite::IPlayerAccount *, OSuite::IConsumableInfo *))(*(_QWORD *)m_pEidosConsumables
                                                                                                + 64i64))(
           m_pEidosConsumables,
           pPlayerAccount,
           pInfo);
  OSuite::ZMutex::Unlock(&this->m_mutex);
  return v6;
}

// File Line: 279
// RVA: 0x132FCF0
__int64 __fastcall OSuitePrivate::ConsumablesManager::NewTransaction(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::IPlayerAccount *pPlayerAccount,
        OSuite::TList<OSuite::IConsumableInfo *> *infos,
        const char *tag)
{
  unsigned int v8; // ebx
  OSuitePrivate::ZEidosConsumables *m_pEidosConsumables; // rcx
  __int64 v10; // rax

  v8 = -2147483135;
  OSuite::ZMutex::Lock(&this->m_mutex);
  m_pEidosConsumables = this->m_pEidosConsumables;
  if ( m_pEidosConsumables )
  {
    v8 = OSuitePrivate::ZEidosConsumables::NewTransaction(m_pEidosConsumables, pPlayerAccount, infos, tag);
  }
  else if ( !this->m_pPlatformOnlyTransaction )
  {
    v10 = OSuite::ZObject::operator new(0x18ui64);
    if ( v10 )
    {
      *(_DWORD *)(v10 + 16) = 0;
      *(_QWORD *)v10 = &OSuitePrivate::ZConsumableTransactionBase::`vftable{for `OSuite::IConsumableTransaction};
      *(_QWORD *)(v10 + 8) = &OSuitePrivate::ZConsumableTransactionBase::`vftable{for `OSuite::ZObject};
    }
    this->m_pPlatformOnlyTransaction = (OSuitePrivate::ZConsumableTransactionBase *)v10;
    v8 = v10 == 0 ? 0x80000004 : 0;
  }
  OSuite::ZMutex::Unlock(&this->m_mutex);
  return v8;
}

// File Line: 303
// RVA: 0x132F2DC
__int64 __fastcall OSuitePrivate::ConsumablesManager::GetActiveTransaction(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::IPlayerAccount *pPlayerAccount,
        OSuite::IConsumableTransaction **ppTransaction)
{
  OSuite::ConsumableError ActiveTransaction; // ebx
  OSuitePrivate::ZEidosConsumables *m_pEidosConsumables; // rcx
  OSuitePrivate::ZConsumableTransactionBase *m_pPlatformOnlyTransaction; // rax

  ActiveTransaction = OS_CONSUMABLES_NO_TRANSACTION;
  OSuite::ZMutex::Lock(&this->m_mutex);
  m_pEidosConsumables = this->m_pEidosConsumables;
  if ( m_pEidosConsumables )
  {
    ActiveTransaction = OSuitePrivate::ZEidosConsumables::GetActiveTransaction(
                          m_pEidosConsumables,
                          pPlayerAccount,
                          ppTransaction);
  }
  else
  {
    m_pPlatformOnlyTransaction = this->m_pPlatformOnlyTransaction;
    if ( m_pPlatformOnlyTransaction )
    {
      if ( ppTransaction )
        *ppTransaction = m_pPlatformOnlyTransaction;
      ActiveTransaction = OS_CONSUMABLES_OK;
    }
  }
  OSuite::ZMutex::Unlock(&this->m_mutex);
  return (unsigned int)ActiveTransaction;
}

// File Line: 328
// RVA: 0x132EC3C
__int64 __fastcall OSuitePrivate::ConsumablesManager::CloseActiveTransaction(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::IPlayerAccount *pPlayerAccount)
{
  OSuitePrivate::ZEidosConsumables *m_pEidosConsumables; // rcx
  OSuite::ConsumableError v5; // edi
  OSuitePrivate::ZConsumableTransactionBase *m_pPlatformOnlyTransaction; // rcx
  OSuitePrivate::ZConsumableTransactionBase *v7; // rcx
  OSuite::IConsumableTransaction *ppTransaction; // [rsp+20h] [rbp-28h] BYREF

  OSuite::ZMutex::Lock(&this->m_mutex);
  m_pEidosConsumables = this->m_pEidosConsumables;
  v5 = OS_CONSUMABLES_INVALID_TRANSACTION;
  if ( m_pEidosConsumables )
  {
    ppTransaction = 0i64;
    if ( OSuitePrivate::ZEidosConsumables::GetActiveTransaction(m_pEidosConsumables, pPlayerAccount, &ppTransaction) == OS_CONSUMABLES_OK )
    {
      ppTransaction->vfptr->GetState(ppTransaction);
      ppTransaction = 0i64;
    }
    v5 = OSuitePrivate::ZEidosConsumables::CloseActiveTransaction(this->m_pEidosConsumables, pPlayerAccount);
  }
  else
  {
    m_pPlatformOnlyTransaction = this->m_pPlatformOnlyTransaction;
    if ( m_pPlatformOnlyTransaction )
    {
      m_pPlatformOnlyTransaction->OSuite::IConsumableTransaction::vfptr->GetState(m_pPlatformOnlyTransaction);
      v7 = this->m_pPlatformOnlyTransaction;
      if ( v7 )
        ((void (__fastcall *)(OSuitePrivate::ZConsumableTransactionBase *, __int64))v7->OSuite::IConsumableTransaction::vfptr->~IConsumableTransaction)(
          v7,
          1i64);
      this->m_pPlatformOnlyTransaction = 0i64;
      v5 = OS_CONSUMABLES_OK;
    }
  }
  OSuite::ZMutex::Unlock(&this->m_mutex);
  return (unsigned int)v5;
}

// File Line: 371
// RVA: 0x132EDFC
void __fastcall OSuitePrivate::ConsumablesManager::CompleteTransactions(OSuitePrivate::ConsumablesManager *this)
{
  OSuitePrivate::ZEidosConsumables *m_pEidosConsumables; // rcx
  unsigned __int64 v3; // rsi
  OSuitePrivate::ZEidosTransaction *Transaction; // rax
  OSuitePrivate::ZEidosTransaction *v5; // rbx
  OSuite::IPlayerAccount *v6; // rax
  OSuite::IPlayerAccount *User; // rax

  m_pEidosConsumables = this->m_pEidosConsumables;
  if ( m_pEidosConsumables )
  {
    v3 = 0i64;
    if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&m_pEidosConsumables->m_playerData) )
    {
      do
      {
        Transaction = OSuitePrivate::ZEidosConsumables::GetTransaction(this->m_pEidosConsumables, v3);
        v5 = Transaction;
        if ( Transaction && Transaction->m_bClose )
        {
          if ( OSuitePrivate::ZEidosTransaction::GetCompletionState(Transaction) )
          {
            if ( OSuitePrivate::ZEidosTransaction::GetCompletionState(v5) == TXN_PURCHASED
              || OSuitePrivate::ZEidosTransaction::GetCompletionState(v5) == TXN_CONSUMING )
            {
              User = OSuitePrivate::ZEidosConsumables::GetUser(this->m_pEidosConsumables, v3);
              OSuitePrivate::ConsumablesManager::HandlePurchasedTxn(this, User, v5);
            }
          }
          else
          {
            v6 = OSuitePrivate::ZEidosConsumables::GetUser(this->m_pEidosConsumables, v3);
            OSuitePrivate::ConsumablesManager::HandleNewTxn(this, v6, v5);
          }
        }
        ++v3;
      }
      while ( v3 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_pEidosConsumables->m_playerData) );
    }
  }
}

// File Line: 401
// RVA: 0x132F87C
void __fastcall OSuitePrivate::ConsumablesManager::HandleNewTxn(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::IPlayerAccount *pPlayerAccount,
        OSuitePrivate::ZEidosTransaction *pTxn)
{
  OSuite::ITransactionState v6; // eax
  OSuitePrivate::ZPlatformConsumables *m_platformConsumables; // rcx
  OSuitePrivate::EidosTransactionState v8; // r9d
  hkEntitySelectorAll *v9; // rax
  hkpEntity *v10; // rdx
  OSuitePrivate::ZPlatformConsumables *v11; // rcx
  OSuitePrivate::EidosTransactionState v12; // edx

  v6 = pTxn->vfptr->GetState(pTxn);
  if ( v6 == TRANSACTION_STATE_NEW )
  {
    m_platformConsumables = this->m_platformConsumables;
    if ( m_platformConsumables )
    {
      if ( !((unsigned __int8 (__fastcall *)(OSuitePrivate::ZPlatformConsumables *))m_platformConsumables->vfptr[9].__vecDelDtor)(m_platformConsumables) )
        return;
      v8 = TXN_CANCELLED;
      goto LABEL_5;
    }
    if ( this->m_pEidosConsumables )
    {
      v9 = (hkEntitySelectorAll *)OSuite::GameInterface();
      if ( (unsigned int)hkaReferencePoseAnimation::getNumOriginalFrames(v9, v10) == 1 )
        OSuitePrivate::ConsumablesManager::QuerySteamTxn(this, pPlayerAccount, pTxn);
      else
        pTxn->m_bClose = 0;
    }
    return;
  }
  if ( v6 != TRANSACTION_STATE_PURCHASED )
  {
    if ( v6 != TRANSACTION_STATE_CANCELLED )
      return;
    v12 = TXN_CANCELLED;
    goto LABEL_18;
  }
  v11 = this->m_platformConsumables;
  if ( !v11 )
  {
    if ( !this->m_pEidosConsumables )
      return;
    v12 = TXN_CONSUMED;
LABEL_18:
    OSuitePrivate::ZEidosTransaction::SetCompletionState(pTxn, v12);
    return;
  }
  if ( ((unsigned __int8 (__fastcall *)(OSuitePrivate::ZPlatformConsumables *))v11->vfptr[9].__vecDelDtor)(v11) )
  {
    v8 = TXN_ERROR;
LABEL_5:
    OSuitePrivate::ConsumablesManager::SendPurchasedData(this, pPlayerAccount, pTxn, v8);
  }
}

// File Line: 459
// RVA: 0x1330344
void __fastcall OSuitePrivate::ConsumablesManager::SendPurchasedData(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::ZObject *pPlayerAccount,
        OSuitePrivate::ZEidosTransaction *pTxn,
        OSuitePrivate::EidosTransactionState errState)
{
  OSuitePrivate::EidosTransactionState v7; // ebx
  int *v8; // rax
  __int64 v9; // rsi
  OSuite::ZConsumableInfoBase *v10; // rdi
  OSuitePrivate::ZPlatformConsumables *m_platformConsumables; // rax
  OSuite::ZObjectVtbl *vfptr; // rbx
  OSuite::ZString *v13; // rax
  char *v14; // rax
  unsigned int v15; // ebx
  OSuite::ZObjectVtbl *v16; // rbx
  OSuite::ZString *v17; // rax
  char *v18; // rax
  int v19; // eax
  int v20; // ebx
  __int64 v22; // [rsp+28h] [rbp-40h] BYREF
  OSuite::TList<int> v23; // [rsp+30h] [rbp-38h] BYREF

  v7 = errState;
  v23.m_pList = 0i64;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&v23, pPlayerAccount);
  v23.OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<int>::`vftable{for `OSuite::ZListBase};
  v23.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<int>::`vftable{for `OSuite::IHashable};
  v23.m_pList = 0i64;
  v8 = (int *)OSuite::ZObject::malloc(&v23, 0x40ui64, 0i64);
  v23.m_nSize = 16i64;
  v23.m_nTop = 0i64;
  v23.m_pList = v8;
  v9 = 0i64;
  if ( !OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&pTxn->m_Infos) )
    goto LABEL_13;
  while ( 1 )
  {
    v10 = pTxn->m_Infos.m_pList[v9];
    if ( !v10 )
      goto LABEL_9;
    m_platformConsumables = this->m_platformConsumables;
    v22 = 0i64;
    vfptr = m_platformConsumables->vfptr;
    v13 = (OSuite::ZString *)v10->OSuite::IConsumableInfo::vfptr->GetId(v10);
    v14 = OSuite::ZString::c_str(v13);
    if ( ((unsigned int (__fastcall *)(OSuitePrivate::ZPlatformConsumables *, OSuite::ZObject *, char *, __int64 *))vfptr[6].__vecDelDtor)(
           this->m_platformConsumables,
           pPlayerAccount,
           v14,
           &v22) )
    {
      break;
    }
    v15 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v22 + 8i64))(v22);
    if ( v15 < v10->OSuite::IConsumableInfo::vfptr->GetQuantity(v10) )
    {
      v7 = errState;
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v22 + 16i64))(v22);
      goto LABEL_13;
    }
    if ( ((unsigned __int8 (__fastcall *)(OSuitePrivate::ZPlatformConsumables *))this->m_platformConsumables->vfptr[10].__vecDelDtor)(this->m_platformConsumables) )
    {
      v16 = this->m_platformConsumables->vfptr;
      v17 = (OSuite::ZString *)v10->OSuite::IConsumableInfo::vfptr->GetId(v10);
      v18 = OSuite::ZString::c_str(v17);
      v19 = ((__int64 (__fastcall *)(OSuitePrivate::ZPlatformConsumables *, OSuite::ZObject *, char *))v16[11].__vecDelDtor)(
              this->m_platformConsumables,
              pPlayerAccount,
              v18);
    }
    else
    {
      v19 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v22 + 8i64))(v22);
    }
    v20 = v19;
    OSuite::TList<int>::Grow(&v23, v23.m_nTop + 1);
    v23.m_pList[v23.m_nTop++] = v20;
    v7 = TXN_PURCHASED;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v22 + 16i64))(v22);
LABEL_9:
    if ( ++v9 >= OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&pTxn->m_Infos) )
      goto LABEL_13;
  }
  v7 = errState;
LABEL_13:
  if ( v7 == TXN_PURCHASED )
    OSuitePrivate::ZEidosTransaction::UpdateToPurchased(pTxn, &v23);
  else
    OSuitePrivate::ZEidosTransaction::SetCompletionState(pTxn, v7);
  v23.OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<int>::`vftable{for `OSuite::ZListBase};
  v23.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<int>::`vftable{for `OSuite::IHashable};
  OSuite::ZObject::free(&v23, v23.m_pList);
}

// File Line: 509
// RVA: 0x132F94C
void __fastcall OSuitePrivate::ConsumablesManager::HandlePurchasedTxn(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::IPlayerAccount *pPlayerAccount,
        OSuitePrivate::ZEidosTransaction *pTxn)
{
  OSuitePrivate::ZPlatformConsumables *m_platformConsumables; // rcx

  m_platformConsumables = this->m_platformConsumables;
  if ( m_platformConsumables )
  {
    ((void (__fastcall *)(OSuitePrivate::ZPlatformConsumables *))m_platformConsumables->vfptr[5].__vecDelDtor)(m_platformConsumables);
    if ( ((unsigned __int8 (__fastcall *)(OSuitePrivate::ZPlatformConsumables *))this->m_platformConsumables->vfptr[9].__vecDelDtor)(this->m_platformConsumables) )
    {
      if ( ((unsigned __int8 (__fastcall *)(OSuitePrivate::ZPlatformConsumables *))this->m_platformConsumables->vfptr[10].__vecDelDtor)(this->m_platformConsumables) )
        OSuitePrivate::ConsumablesManager::ConsumeDataFromConsumedCount(this, pPlayerAccount, pTxn);
      else
        OSuitePrivate::ConsumablesManager::ConsumeDataFromInfo(this, pPlayerAccount, pTxn);
    }
  }
  else if ( this->m_pEidosConsumables )
  {
    OSuitePrivate::ZEidosTransaction::SetCompletionState(pTxn, TXN_CONSUMED);
  }
}

// File Line: 533
// RVA: 0x132F0E0
void __fastcall OSuitePrivate::ConsumablesManager::ConsumeDataFromInfo(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::IPlayerAccount *pPlayerAccount,
        OSuitePrivate::ZEidosTransaction *pTxn)
{
  OSuite::ZRedBlackTreeBase *p_m_Infos; // r13
  OSuitePrivate::ConsumablesManager *v4; // rbx
  char v6; // r15
  unsigned __int64 v7; // r14
  __int64 v8; // rdi
  __int64 v9; // r12
  unsigned __int64 v10; // rsi
  __int64 v11; // r12
  OSuitePrivate::ZPlatformConsumables *m_platformConsumables; // rax
  OSuite::ZObjectVtbl *vfptr; // rbx
  OSuite::ZString *v14; // rax
  char *v15; // rax
  int v16; // eax
  int v17; // ebx
  int v18; // edi
  int v19; // ebx
  bool v20; // zf
  OSuitePrivate::EidosTransactionState v21; // edx
  unsigned __int64 v22; // rax
  __int64 v24; // [rsp+28h] [rbp-60h]
  __int64 v26; // [rsp+38h] [rbp-50h]
  __int64 v27; // [rsp+40h] [rbp-48h] BYREF

  p_m_Infos = (OSuite::ZRedBlackTreeBase *)&pTxn->m_Infos;
  v4 = this;
  v6 = 0;
  v7 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&pTxn->m_Infos) )
  {
    v8 = 0i64;
    v9 = 0i64;
    v10 = 1i64;
    v26 = 0i64;
    v24 = 0i64;
    while ( !v6 )
    {
      v11 = *(__int64 *)((char *)&p_m_Infos[1].m_pTop->vfptr + v9);
      if ( v11 )
      {
        m_platformConsumables = v4->m_platformConsumables;
        v27 = 0i64;
        vfptr = m_platformConsumables->vfptr;
        v14 = (OSuite::ZString *)(**(__int64 (__fastcall ***)(__int64))v11)(v11);
        v15 = OSuite::ZString::c_str(v14);
        v16 = ((__int64 (__fastcall *)(OSuitePrivate::ZPlatformConsumables *, OSuite::IPlayerAccount *, char *, __int64 *))vfptr[6].__vecDelDtor)(
                this->m_platformConsumables,
                pPlayerAccount,
                v15,
                &v27);
        if ( v16 )
        {
          v4 = this;
          if ( v16 == -2147483388 )
            ++v7;
          else
            v6 = 1;
        }
        else
        {
          OSuite::TList<int>::Grow(&pTxn->m_tempCount, v10);
          if ( v10 - 1 >= pTxn->m_tempCount.m_nTop )
            pTxn->m_tempCount.m_nTop = v10;
          v17 = *(int *)((char *)pTxn->m_tempCount.m_pList + v24);
          if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v27 + 8i64))(v27) == v17 )
          {
            v4 = this;
            ((void (__fastcall *)(OSuitePrivate::ZPlatformConsumables *, OSuite::IPlayerAccount *, __int64))this->m_platformConsumables->vfptr[8].__vecDelDtor)(
              this->m_platformConsumables,
              pPlayerAccount,
              v11);
          }
          else
          {
            OSuite::TList<int>::Grow(&pTxn->m_tempCount, v10);
            if ( v10 - 1 >= pTxn->m_tempCount.m_nTop )
              pTxn->m_tempCount.m_nTop = v10;
            v18 = *(int *)((char *)pTxn->m_tempCount.m_pList + v24);
            v19 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v27 + 8i64))(v27);
            v20 = (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v11 + 8i64))(v11) + v19 == v18;
            v4 = this;
            if ( v20 )
              ++v7;
            else
              v6 = 1;
          }
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v27 + 16i64))(v27);
          v8 = v24;
        }
      }
      v8 += 4i64;
      v9 = v26 + 8;
      ++v10;
      v24 = v8;
      v26 += 8i64;
      if ( v10 - 1 >= OSuite::ZHttpStreamReader::Tell(p_m_Infos) )
      {
        if ( !v6 )
          goto LABEL_22;
        break;
      }
    }
    v21 = TXN_ERROR;
  }
  else
  {
LABEL_22:
    v22 = OSuite::ZHttpStreamReader::Tell(p_m_Infos);
    v21 = TXN_CONSUMING;
    if ( v7 >= v22 )
      v21 = TXN_CONSUMED;
  }
  OSuitePrivate::ZEidosTransaction::SetCompletionState(pTxn, v21);
}

// File Line: 578
// RVA: 0x132EF48
void __fastcall OSuitePrivate::ConsumablesManager::ConsumeDataFromConsumedCount(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::IPlayerAccount *pPlayerAccount,
        OSuitePrivate::ZEidosTransaction *pTxn)
{
  OSuite::ZRedBlackTreeBase *p_m_Infos; // r15
  OSuitePrivate::ConsumablesManager *v4; // rbx
  char v6; // r12
  unsigned __int64 v7; // rbp
  __int64 v8; // r13
  __int64 v9; // r14
  unsigned __int64 v10; // rdi
  __int64 v11; // r14
  OSuite::ZObjectVtbl *vfptr; // rbx
  OSuite::ZString *v13; // rax
  char *v14; // rax
  int v15; // ebx
  OSuitePrivate::EidosTransactionState v16; // edx
  unsigned __int64 v17; // rax
  int v20; // [rsp+80h] [rbp+18h]
  __int64 v21; // [rsp+88h] [rbp+20h]

  p_m_Infos = (OSuite::ZRedBlackTreeBase *)&pTxn->m_Infos;
  v4 = this;
  v6 = 0;
  v7 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&pTxn->m_Infos) )
  {
    v8 = 0i64;
    v9 = 0i64;
    v10 = 1i64;
    v21 = 0i64;
    while ( 1 )
    {
      if ( v6 )
      {
LABEL_18:
        v16 = TXN_ERROR;
        goto LABEL_21;
      }
      v11 = *(__int64 *)((char *)&p_m_Infos[1].m_pTop->vfptr + v9);
      if ( v11 )
      {
        vfptr = v4->m_platformConsumables->vfptr;
        v13 = (OSuite::ZString *)(**(__int64 (__fastcall ***)(__int64))v11)(v11);
        v14 = OSuite::ZString::c_str(v13);
        v20 = ((__int64 (__fastcall *)(OSuitePrivate::ZPlatformConsumables *, OSuite::IPlayerAccount *, char *))vfptr[11].__vecDelDtor)(
                this->m_platformConsumables,
                pPlayerAccount,
                v14);
        if ( v20 == -2 )
          goto LABEL_6;
        OSuite::TList<int>::Grow(&pTxn->m_tempCount, v10);
        if ( v10 - 1 >= pTxn->m_tempCount.m_nTop )
          pTxn->m_tempCount.m_nTop = v10;
        if ( v20 != pTxn->m_tempCount.m_pList[v8] )
        {
          OSuite::TList<int>::Grow(&pTxn->m_tempCount, v10);
          if ( v10 - 1 >= pTxn->m_tempCount.m_nTop )
            pTxn->m_tempCount.m_nTop = v10;
          v15 = pTxn->m_tempCount.m_pList[v8];
          if ( v15 + (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v11 + 8i64))(v11) == v20 )
LABEL_6:
            ++v7;
          else
            v6 = 1;
          v4 = this;
          goto LABEL_16;
        }
        v4 = this;
        ((void (__fastcall *)(OSuitePrivate::ZPlatformConsumables *, OSuite::IPlayerAccount *, __int64))this->m_platformConsumables->vfptr[8].__vecDelDtor)(
          this->m_platformConsumables,
          pPlayerAccount,
          v11);
      }
LABEL_16:
      ++v10;
      v9 = v21 + 8;
      ++v8;
      v21 += 8i64;
      if ( v10 - 1 >= OSuite::ZHttpStreamReader::Tell(p_m_Infos) )
      {
        if ( !v6 )
          break;
        goto LABEL_18;
      }
    }
  }
  v17 = OSuite::ZHttpStreamReader::Tell(p_m_Infos);
  v16 = TXN_CONSUMING;
  if ( v7 >= v17 )
    v16 = TXN_CONSUMED;
LABEL_21:
  OSuitePrivate::ZEidosTransaction::SetCompletionState(pTxn, v16);
}

// File Line: 615
// RVA: 0x13307B0
void __fastcall OSuitePrivate::ConsumablesManager::TransferLostConsumables(OSuitePrivate::ConsumablesManager *this)
{
  OSuitePrivate::ZPlatformConsumables *m_platformConsumables; // rcx
  unsigned __int64 i; // r14
  OSuite::IPlayerAccount *User; // rsi
  int v5; // r15d
  OSuitePrivate::ZEidosConsumables *m_pEidosConsumables; // rcx
  OSuite::ZObject *v7; // rdx
  OSuite::ZRedBlackTreeBase::ZElementBase **v8; // rax
  int v9; // ebx
  OSuitePrivate::ZPlatformConsumables *v10; // rcx
  unsigned __int64 v11; // rsi
  unsigned __int64 v12; // rbx
  unsigned __int64 m_nTop; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v14; // [rsp+20h] [rbp-40h] BYREF
  OSuite::IConsumableTransaction *ppTransaction; // [rsp+28h] [rbp-38h] BYREF
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> v16; // [rsp+30h] [rbp-30h] BYREF

  m_platformConsumables = this->m_platformConsumables;
  if ( m_platformConsumables )
  {
    if ( this->m_pEidosConsumables )
    {
      if ( ((unsigned __int8 (__fastcall *)(OSuitePrivate::ZPlatformConsumables *))m_platformConsumables->vfptr[9].__vecDelDtor)(m_platformConsumables) )
      {
        for ( i = 0i64;
              i < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_pEidosConsumables->m_playerData);
              ++i )
        {
          User = OSuitePrivate::ZEidosConsumables::GetUser(this->m_pEidosConsumables, i);
          v5 = (int)this->m_platformConsumables->vfptr[5].__vecDelDtor(this->m_platformConsumables, User);
          if ( v5 > 0 )
          {
            m_pEidosConsumables = this->m_pEidosConsumables;
            ppTransaction = 0i64;
            if ( OSuitePrivate::ZEidosConsumables::GetActiveTransaction(m_pEidosConsumables, User, &ppTransaction) == OS_CONSUMABLES_NO_TRANSACTION )
            {
              v16.m_pList = 0i64;
              OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&v16, v7);
              v16.m_pList = 0i64;
              v16.OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
              v16.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
              v8 = (OSuite::ZRedBlackTreeBase::ZElementBase **)OSuite::ZObject::malloc(&v16, 0x80ui64, 0i64);
              v16.m_nTop = 0i64;
              v9 = 0;
              v16.m_pList = v8;
              v16.m_nSize = 16i64;
              do
              {
                v10 = this->m_platformConsumables;
                v14 = 0i64;
                if ( !((unsigned int (__fastcall *)(OSuitePrivate::ZPlatformConsumables *, OSuite::IPlayerAccount *, _QWORD, OSuite::ZRedBlackTreeBase::ZElementBase **))v10->vfptr[7].__vecDelDtor)(
                        v10,
                        User,
                        (unsigned int)v9,
                        &v14) )
                {
                  if ( ((unsigned int (__fastcall *)(OSuite::ZRedBlackTreeBase::ZElementBase *))v14->vfptr[1].__vecDelDtor)(v14) )
                  {
                    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(&v16, v16.m_nTop + 1);
                    v16.m_pList[v16.m_nTop++] = v14;
                  }
                  else
                  {
                    ((void (__fastcall *)(OSuite::ZRedBlackTreeBase::ZElementBase *))v14->vfptr[2].__vecDelDtor)(v14);
                  }
                }
                ++v9;
              }
              while ( v9 < v5 );
              if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v16) )
              {
                if ( OSuitePrivate::ZEidosConsumables::NewTransaction(
                       this->m_pEidosConsumables,
                       User,
                       (OSuite::TList<OSuite::IConsumableInfo *> *)&v16,
                       "ConsumableManager") == OS_CONSUMABLES_OK )
                {
                  OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
                    (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_TransactionRequested,
                    this->m_TransactionRequested.m_nTop + 1);
                  this->m_TransactionRequested.m_pList[this->m_TransactionRequested.m_nTop++] = User;
                }
                v11 = 0i64;
                if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v16) )
                {
                  do
                  {
                    v12 = v11 + 1;
                    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(&v16, v11 + 1);
                    m_nTop = v16.m_nTop;
                    if ( v11 >= v16.m_nTop )
                      m_nTop = v11 + 1;
                    v16.m_nTop = m_nTop;
                    ((void (__fastcall *)(OSuite::ZRedBlackTreeBase::ZElementBase *))v16.m_pList[v11]->vfptr[2].__vecDelDtor)(v16.m_pList[v11]);
                    ++v11;
                  }
                  while ( v12 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v16) );
                }
              }
              v16.OSuite::IHashable::vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable{for `OSuite::IHashable};
              v16.OSuite::ZListBase::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable{for `OSuite::ZListBase};
              OSuite::ZObject::free(&v16, v16.m_pList);
            }
          }
        }
      }
    }
  }
}

// File Line: 663
// RVA: 0x132ECFC
void __fastcall OSuitePrivate::ConsumablesManager::CloseLostTransactions(OSuitePrivate::ConsumablesManager *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *p_m_TransactionRequested; // rbx
  unsigned __int64 v3; // rdi
  unsigned __int64 i; // rsi
  OSuite::ConsumableError ActiveTransaction; // eax
  OSuite::IConsumableTransaction *ppTransaction; // [rsp+20h] [rbp-18h] BYREF

  p_m_TransactionRequested = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_TransactionRequested;
  v3 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_TransactionRequested) )
  {
    for ( i = 1i64; ; ++i )
    {
      ppTransaction = 0i64;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_TransactionRequested, i);
      if ( v3 >= p_m_TransactionRequested->m_nTop )
        p_m_TransactionRequested->m_nTop = i;
      ActiveTransaction = OSuitePrivate::ZEidosConsumables::GetActiveTransaction(
                            this->m_pEidosConsumables,
                            (OSuite::IPlayerAccount *)p_m_TransactionRequested->m_pList[v3],
                            &ppTransaction);
      if ( ppTransaction )
        break;
      if ( ActiveTransaction == OS_CONSUMABLES_NO_TRANSACTION )
        goto LABEL_10;
LABEL_11:
      if ( ++v3 >= OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)p_m_TransactionRequested) )
        return;
    }
    ppTransaction->vfptr->SetState(ppTransaction, TRANSACTION_STATE_PURCHASED);
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(p_m_TransactionRequested, i);
    if ( v3 >= p_m_TransactionRequested->m_nTop )
      p_m_TransactionRequested->m_nTop = i;
    OSuitePrivate::ZEidosConsumables::CloseActiveTransaction(
      this->m_pEidosConsumables,
      (OSuite::IPlayerAccount *)p_m_TransactionRequested->m_pList[v3]);
LABEL_10:
    p_m_TransactionRequested->OSuite::ZListBase::OSuite::ZObject::vfptr[1].__vecDelDtor(p_m_TransactionRequested, v3--);
    --i;
    goto LABEL_11;
  }
}

// File Line: 687
// RVA: 0x132F4CC
OSuite::ZJsonObject *__fastcall OSuitePrivate::ConsumablesManager::GetResponseParams(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::ZJsonDocument *doc)
{
  void *(__fastcall *v2)(OSuite::ZObject *, unsigned int); // rdi
  OSuite::ZObjectVtbl *v4; // rsi
  OSuite::ZJsonObject *vecDelDtor; // rsi
  OSuite::ZObjectVtbl *v6; // rbx
  OSuite::ZObjectVtbl *v7; // rbx
  OSuite::ZJsonObject *v8; // rbx
  OSuite::ZObjectVtbl *v9; // r14
  OSuite::ZObjectVtbl *v10; // rsi
  OSuite::ZString *v11; // rax
  OSuite::ZString *v12; // rax
  OSuite::ZString *v13; // rax
  OSuite::ZString *v14; // rax
  OSuite::ZObjectVtbl *v15; // rbx
  OSuite::ZString sName; // [rsp+20h] [rbp-39h] BYREF
  OSuite::ZString v18; // [rsp+38h] [rbp-21h] BYREF
  OSuite::ZString v19; // [rsp+50h] [rbp-9h] BYREF
  OSuite::ZString result; // [rsp+68h] [rbp+Fh] BYREF
  OSuite::ZString v21; // [rsp+80h] [rbp+27h] BYREF

  v2 = 0i64;
  v21.m_pString = 0i64;
  OSuite::ZString::ZString(&v21);
  OSuite::ZString::ZString(&sName, "response");
  v4 = OSuite::ZJsonObject::Value(doc, &sName);
  OSuite::ZString::~ZString(&sName);
  if ( v4 )
  {
    vecDelDtor = (OSuite::ZJsonObject *)v4[10].__vecDelDtor;
    if ( vecDelDtor )
    {
      OSuite::ZString::ZString(&sName, "result");
      v6 = OSuite::ZJsonObject::Value(vecDelDtor, &sName);
      OSuite::ZString::~ZString(&sName);
      OSuite::ZString::operator=(&v21, (OSuite::ZString *)&v6[2]);
      if ( OSuite::ZString::operator==(&v21, "Failure") )
      {
        OSuite::ZString::ZString(&sName, "error");
        v7 = OSuite::ZJsonObject::Value(vecDelDtor, &sName);
        OSuite::ZString::~ZString(&sName);
        if ( v7 )
        {
          v8 = (OSuite::ZJsonObject *)v7[10].__vecDelDtor;
          if ( v8 )
          {
            OSuite::ZString::ZString(&sName, "errorcode");
            v9 = OSuite::ZJsonObject::Value(v8, &sName);
            OSuite::ZString::~ZString(&sName);
            OSuite::ZString::ZString(&v18, "errordesc");
            v10 = OSuite::ZJsonObject::Value(v8, &v18);
            OSuite::ZString::~ZString(&v18);
            if ( v9 )
            {
              v11 = OSuite::ZString::operator+(&v21, &result, " ErrCode:");
              v12 = OSuite::ZString::operator+(v11, &v19, (OSuite::ZString *)&v9[2]);
              OSuite::ZString::operator=(&v21, v12);
              OSuite::ZString::~ZString(&v19);
              OSuite::ZString::~ZString(&result);
            }
            if ( v10 )
            {
              v13 = OSuite::ZString::operator+(&v21, &v19, " Error Desc:");
              v14 = OSuite::ZString::operator+(v13, &result, (OSuite::ZString *)&v10[2]);
              OSuite::ZString::operator=(&v21, v14);
              OSuite::ZString::~ZString(&result);
              OSuite::ZString::~ZString(&v19);
            }
          }
        }
      }
      else
      {
        OSuite::ZString::ZString(&v18, "params");
        v15 = OSuite::ZJsonObject::Value(vecDelDtor, &v18);
        OSuite::ZString::~ZString(&v18);
        if ( v15 )
          v2 = v15[10].__vecDelDtor;
      }
    }
  }
  OSuite::ZString::~ZString(&v21);
  return (OSuite::ZJsonObject *)v2;
}

// File Line: 750
// RVA: 0x132FF98
void __fastcall OSuitePrivate::ConsumablesManager::QuerySteamTxn(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::IPlayerAccount *pPlayerAccount,
        OSuitePrivate::ZEidosTransaction *pTxn)
{
  __int64 v5; // rax
  __int64 v6; // rax
  OSuitePrivate::EidosTransactionState Response; // eax
  OSuitePrivate::EidosTransactionState v8; // esi
  OSuite::ZHttpManager *v9; // rax
  __int64 v10; // rax

  if ( !this->m_bRequestInProgress )
  {
    if ( this->m_httpRequest )
    {
      if ( this->m_bFinalizingTxn )
      {
        v6 = ((__int64 (__fastcall *)(OSuitePrivate::ZEidosTransaction *, OSuite::IPlayerAccount *))pTxn->vfptr->GetId)(
               pTxn,
               pPlayerAccount);
        Response = (unsigned int)OSuitePrivate::ConsumablesManager::HandleFinalizeResponse(this, v6);
      }
      else
      {
        Response = (unsigned int)OSuitePrivate::ConsumablesManager::HandleQueryResponse(this, pPlayerAccount, pTxn);
      }
      v8 = Response;
      v9 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
      OSuite::ZHttpRequestManager::ReleaseHttpRequest(v9->m_httpRequestManager, this->m_httpRequest);
      this->m_httpRequest = 0i64;
      if ( v8 )
      {
        OSuitePrivate::ZEidosTransaction::SetCompletionState(pTxn, v8);
      }
      else
      {
        v10 = pTxn->vfptr->GetId(pTxn);
        OSuitePrivate::ConsumablesManager::SendFinalize(this, v10);
      }
    }
    else
    {
      v5 = ((__int64 (__fastcall *)(OSuitePrivate::ZEidosTransaction *, OSuite::IPlayerAccount *))pTxn->vfptr->GetId)(
             pTxn,
             pPlayerAccount);
      OSuitePrivate::ConsumablesManager::SendQuery(this, v5);
    }
  }
}

// File Line: 775
// RVA: 0x133052C
void __fastcall OSuitePrivate::ConsumablesManager::SendQuery(OSuitePrivate::ConsumablesManager *this, __int64 orderId)
{
  OSuite::ZGameInterface *v4; // rax
  const char *SteamShopURL; // rax
  OSuite::ZOnlineSuite *v6; // rax
  OSuite::IGameConfig *GameConfig; // rax
  const char *v8; // rax
  OSuite::ZGameInterface *v9; // rax
  int AppID; // eax
  OSuite::ZHttpRequestManager *m_httpRequestManager; // rbx
  OSuite::ZUrl *v12; // rax
  OSuite::IHttpRequest *v13; // rax
  OSuite::ZObjectVtbl *vfptr; // rbx
  __int64 v15; // rax
  OSuite::ZObjectVtbl *v16; // rbx
  __int64 v17; // rax
  hkSeekableStreamReader *RCX; // rax
  OSuite::IHttpRequest *m_httpRequest; // rcx
  __int64 v20[8]; // [rsp+30h] [rbp-D0h] BYREF
  char v21; // [rsp+70h] [rbp-90h]
  OSuite::ZString v22; // [rsp+78h] [rbp-88h] BYREF
  OSuite::ZUrl v23; // [rsp+90h] [rbp-70h] BYREF
  OSuite::ZStringBuilder v24; // [rsp+168h] [rbp+68h] BYREF
  OSuite::ZString result; // [rsp+198h] [rbp+98h] BYREF

  *(_WORD *)&this->m_bRequestInProgress = 1;
  v24.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v24, (OSuite::ZObject *)0x100);
  v4 = OSuite::GameInterface();
  SteamShopURL = OSuite::ZGameInterface::GetSteamShopURL(v4);
  OSuite::ZStringBuilder::Append(&v24, SteamShopURL);
  OSuite::ZStringBuilder::Append(&v24, "QueryTxn/V0001/?key=");
  v6 = OSuite::ZOnlineSuite::Instance();
  GameConfig = OSuite::ZOnlineSuite::GetGameConfig(v6);
  v8 = GameConfig->vfptr->GetSteamWebAPIKey(GameConfig);
  OSuite::ZStringBuilder::Append(&v24, v8);
  OSuite::ZStringBuilder::Append(&v24, "&orderid=");
  OSuite::ZStringBuilder::AppendInt(&v24, orderId);
  OSuite::ZStringBuilder::Append(&v24, "&appid=");
  v9 = OSuite::GameInterface();
  AppID = OSuite::ZGameInterface::GetAppID(v9);
  OSuite::ZStringBuilder::AppendInt(&v24, AppID);
  result.m_pString = 0i64;
  OSuite::ZStringBuilder::ToString(&v24, &result);
  m_httpRequestManager = OSuite::TSingleton<OSuite::ZHttpManager>::Object()->m_httpRequestManager;
  OSuite::ZUrl::ZUrl(&v23, &result);
  OSuite::ZHttpRequestManager::CreateHttpRequest(m_httpRequestManager, v12, 0i64, 0, 30);
  this->m_httpRequest = v13;
  OSuite::ZUrl::~ZUrl(&v23);
  vfptr = this->m_httpRequest->vfptr;
  OSuite::ZString::ZString(&v22, "GET");
  vfptr[44].__vecDelDtor(this->m_httpRequest, v15);
  this->m_httpRequest->vfptr[42].__vecDelDtor(this->m_httpRequest, 0);
  v16 = this->m_httpRequest->vfptr;
  OSuite::ZString::ZString(&v22, "application/json");
  v16[36].__vecDelDtor(this->m_httpRequest, v17);
  RCX = Assembly::GetRCX(this);
  v20[7] = (__int64)OSuitePrivate::ConsumablesManager::OnRequestFinished;
  m_httpRequest = this->m_httpRequest;
  memset(v20, 0, 48);
  v20[6] = (__int64)RCX;
  v21 = 1;
  m_httpRequest->vfptr[6].__vecDelDtor(m_httpRequest, (unsigned int)v20);
  OSuite::ZString::~ZString(&result);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v24);
}

// File Line: 806
// RVA: 0x132F9CC
__int64 __fastcall OSuitePrivate::ConsumablesManager::HandleQueryResponse(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::IPlayerAccount *pPlayerAccount,
        OSuitePrivate::ZEidosTransaction *pTxn)
{
  unsigned int v6; // esi
  __int64 v7; // rax
  __int64 v8; // r14
  __int64 v9; // rax
  OSuite::IReader *v10; // rax
  OSuite::ZJsonObject *ResponseParams; // rbx
  OSuite::ZObjectVtbl *v12; // rdi
  OSuite::ZObjectVtbl *v13; // rdi
  OSuite::ZObjectVtbl *v14; // rbx
  OSuite::ZString *v15; // rax
  OSuite::ZString *v16; // rax
  OSuite::ZString *v17; // rdi
  bool v18; // bl
  OSuite::ZString sName; // [rsp+20h] [rbp-59h] BYREF
  OSuite::ZString v21; // [rsp+38h] [rbp-41h] BYREF
  OSuite::ZString v22; // [rsp+50h] [rbp-29h] BYREF
  OSuite::ZJsonDocument doc; // [rsp+68h] [rbp-11h] BYREF

  v6 = 6;
  v7 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))this->m_httpRequest->vfptr[33].__vecDelDtor)(this->m_httpRequest);
  if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v7 + 32i64))(v7) == 200 )
  {
    v21.m_pString = 0i64;
    OSuite::ZString::ZString(&v21, &customCaption);
    v22.m_pString = 0i64;
    OSuite::ZString::ZString(&v22, &customCaption);
    v8 = -1i64;
    v9 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))this->m_httpRequest->vfptr[33].__vecDelDtor)(this->m_httpRequest);
    v10 = (OSuite::IReader *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 64i64))(v9);
    doc.m_Pairs.m_pLists = 0i64;
    OSuite::ZJsonDocument::ZJsonDocument(&doc, v10);
    ResponseParams = OSuitePrivate::ConsumablesManager::GetResponseParams(this, &doc);
    if ( ResponseParams )
    {
      OSuite::ZString::ZString(&sName, "status");
      v12 = OSuite::ZJsonObject::Value(ResponseParams, &sName);
      OSuite::ZString::~ZString(&sName);
      if ( v12 )
        OSuite::ZString::operator=(&v21, (OSuite::ZString *)&v12[2]);
      OSuite::ZString::ZString(&sName, "orderid");
      v13 = OSuite::ZJsonObject::Value(ResponseParams, &sName);
      OSuite::ZString::~ZString(&sName);
      if ( v13 )
        v8 = OSuite::ZString::ToInt((OSuite::ZString *)&v13[2]);
      OSuite::ZString::ZString(&sName, "steamid");
      v14 = OSuite::ZJsonObject::Value(ResponseParams, &sName);
      OSuite::ZString::~ZString(&sName);
      if ( v14 )
        OSuite::ZString::operator=(&v22, (OSuite::ZString *)&v14[2]);
    }
    if ( OSuite::ZString::operator==(&v21, "Approved") )
    {
      v6 = 0;
    }
    else if ( OSuite::ZString::operator==(&v21, "Succeeded") )
    {
      v6 = 4;
    }
    v15 = pPlayerAccount->vfptr->GetUserId(pPlayerAccount, 0i64);
    OSuite::ZString::ZString(&sName, v15);
    v17 = v16;
    v18 = OSuite::ZString::operator==(&v22, v16) == 0;
    OSuite::ZString::~ZString(v17);
    if ( v18 )
      v6 = 7;
    if ( v8 != pTxn->vfptr->GetId(pTxn) )
      v6 = 7;
    OSuite::ZJsonDocument::~ZJsonDocument(&doc);
    OSuite::ZString::~ZString(&v22);
    OSuite::ZString::~ZString(&v21);
  }
  return v6;
}

// File Line: 878
// RVA: 0x1330090
void __fastcall OSuitePrivate::ConsumablesManager::SendFinalize(
        OSuitePrivate::ConsumablesManager *this,
        __int64 orderId)
{
  OSuite::ZGameInterface *v4; // rax
  const char *SteamShopURL; // rax
  OSuite::ZOnlineSuite *v6; // rax
  OSuite::IGameConfig *GameConfig; // rax
  const char *v8; // rax
  OSuite::ZGameInterface *v9; // rax
  int AppID; // eax
  OSuite::ZString *v11; // rax
  OSuite::ZHttpRequestManager *m_httpRequestManager; // rbx
  OSuite::ZUrl *v13; // rax
  OSuite::IHttpRequest *v14; // rax
  OSuite::ZObjectVtbl *vfptr; // rbx
  __int64 v16; // rax
  OSuite::ZObjectVtbl *v17; // rbx
  unsigned __int64 v18; // rax
  OSuite::ZObjectVtbl *v19; // rbx
  __int64 v20; // rax
  OSuite::ZObjectVtbl *v21; // rbx
  __int64 v22; // rax
  hkSeekableStreamReader *RCX; // rbx
  hkSeekableStreamReader *v24; // rax
  OSuite::IHttpRequest *m_httpRequest; // rcx
  OSuite::ZString result; // [rsp+30h] [rbp-D0h] BYREF
  __int64 v27[8]; // [rsp+48h] [rbp-B8h] BYREF
  char v28; // [rsp+88h] [rbp-78h]
  OSuite::ZUrl v29; // [rsp+90h] [rbp-70h] BYREF
  OSuite::ZStringBuilder v30; // [rsp+168h] [rbp+68h] BYREF
  OSuite::ZString sPath; // [rsp+198h] [rbp+98h] BYREF
  OSuite::ZStringBuilder v32; // [rsp+1B0h] [rbp+B0h] BYREF

  *(_WORD *)&this->m_bRequestInProgress = 257;
  v32.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v32, (OSuite::ZObject *)0x100);
  v4 = OSuite::GameInterface();
  SteamShopURL = OSuite::ZGameInterface::GetSteamShopURL(v4);
  OSuite::ZStringBuilder::Append(&v32, SteamShopURL);
  OSuite::ZStringBuilder::Append(&v32, "FinalizeTxn/V0001/?key=");
  v6 = OSuite::ZOnlineSuite::Instance();
  GameConfig = OSuite::ZOnlineSuite::GetGameConfig(v6);
  v8 = GameConfig->vfptr->GetSteamWebAPIKey(GameConfig);
  OSuite::ZStringBuilder::Append(&v32, v8);
  v30.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v30, (OSuite::ZObject *)0x100);
  OSuite::ZStringBuilder::Append(&v30, "orderid=");
  OSuite::ZStringBuilder::AppendInt(&v30, orderId);
  OSuite::ZStringBuilder::Append(&v30, "&appid=");
  v9 = OSuite::GameInterface();
  AppID = OSuite::ZGameInterface::GetAppID(v9);
  OSuite::ZStringBuilder::AppendInt(&v30, AppID);
  v11 = OSuite::ZStringBuilder::ToString(&v30, &result);
  OSuite::ZString::operator=(&this->m_finalizeData, v11);
  OSuite::ZString::~ZString(&result);
  sPath.m_pString = 0i64;
  OSuite::ZStringBuilder::ToString(&v32, &sPath);
  m_httpRequestManager = OSuite::TSingleton<OSuite::ZHttpManager>::Object()->m_httpRequestManager;
  OSuite::ZUrl::ZUrl(&v29, &sPath);
  OSuite::ZHttpRequestManager::CreateHttpRequest(m_httpRequestManager, v13, 0i64, 0, 30);
  this->m_httpRequest = v14;
  OSuite::ZUrl::~ZUrl(&v29);
  vfptr = this->m_httpRequest->vfptr;
  OSuite::ZString::ZString(&result, "POST");
  vfptr[44].__vecDelDtor(this->m_httpRequest, v16);
  v17 = this->m_httpRequest->vfptr;
  v18 = OSuite::ZString::Count(&this->m_finalizeData);
  v17[42].__vecDelDtor(this->m_httpRequest, v18);
  v19 = this->m_httpRequest->vfptr;
  OSuite::ZString::ZString(&result, "application/json");
  v19[36].__vecDelDtor(this->m_httpRequest, v20);
  v21 = this->m_httpRequest->vfptr;
  OSuite::ZString::ZString(&result, "application/x-www-form-urlencoded");
  v21[41].__vecDelDtor(this->m_httpRequest, v22);
  RCX = Assembly::GetRCX(this);
  v24 = Assembly::GetRCX(this);
  v27[5] = (__int64)OSuitePrivate::ConsumablesManager::OnFinalizeTxnDataNeeded;
  m_httpRequest = this->m_httpRequest;
  v27[4] = (__int64)v24;
  memset(v27, 0, 32);
  v27[6] = (__int64)RCX;
  v28 = 1;
  v27[7] = (__int64)OSuitePrivate::ConsumablesManager::OnRequestFinished;
  m_httpRequest->vfptr[6].__vecDelDtor(m_httpRequest, (unsigned int)v27);
  OSuite::ZString::~ZString(&sPath);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v30);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v32);
}

// File Line: 914
// RVA: 0x132F774
__int64 __fastcall OSuitePrivate::ConsumablesManager::HandleFinalizeResponse(
        OSuitePrivate::ConsumablesManager *this,
        __int64 orderId)
{
  unsigned int v4; // ebx
  __int64 v5; // rax
  __int64 v6; // rsi
  __int64 v7; // rax
  OSuite::IReader *v8; // rax
  OSuite::ZJsonObject *ResponseParams; // rdi
  OSuite::ZObjectVtbl *v10; // rdi
  OSuite::ZString sName; // [rsp+20h] [rbp-58h] BYREF
  OSuite::ZJsonDocument doc; // [rsp+38h] [rbp-40h] BYREF

  v4 = 7;
  v5 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))this->m_httpRequest->vfptr[33].__vecDelDtor)(this->m_httpRequest);
  if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v5 + 32i64))(v5) == 200 )
  {
    v6 = -1i64;
    v7 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))this->m_httpRequest->vfptr[33].__vecDelDtor)(this->m_httpRequest);
    v8 = (OSuite::IReader *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 64i64))(v7);
    doc.m_Pairs.m_pLists = 0i64;
    OSuite::ZJsonDocument::ZJsonDocument(&doc, v8);
    ResponseParams = OSuitePrivate::ConsumablesManager::GetResponseParams(this, &doc);
    if ( ResponseParams )
    {
      OSuite::ZString::ZString(&sName, "orderid");
      v10 = OSuite::ZJsonObject::Value(ResponseParams, &sName);
      OSuite::ZString::~ZString(&sName);
      if ( v10 )
        v6 = OSuite::ZString::ToInt((OSuite::ZString *)&v10[2]);
    }
    if ( v6 == orderId )
      v4 = 4;
    OSuite::ZJsonDocument::~ZJsonDocument(&doc);
  }
  return v4;
}

// File Line: 955
// RVA: 0x132FF8C
bool __fastcall OSuitePrivate::ConsumablesManager::OnRequestFinished(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::IHttpRequest *__formal,
        OSuite::ZHttp::EError error)
{
  this->m_bRequestInProgress = 0;
  return error == HTTPERROR_OK;
}

// File Line: 962
// RVA: 0x132FF30
bool __fastcall OSuitePrivate::ConsumablesManager::OnFinalizeTxnDataNeeded(
        OSuitePrivate::ConsumablesManager *this,
        OSuite::IHttpRequest *request,
        unsigned __int64 __formal)
{
  OSuite::ZObjectVtbl *vfptr; // rsi
  OSuite::ZString *p_m_finalizeData; // rbx
  unsigned __int64 v6; // rdi
  char *v7; // rax

  vfptr = request->vfptr;
  p_m_finalizeData = &this->m_finalizeData;
  v6 = OSuite::ZString::Count(&this->m_finalizeData);
  v7 = OSuite::ZString::c_str(p_m_finalizeData);
  return ((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *, char *, unsigned __int64))vfptr[14].__vecDelDtor)(
           request,
           v7,
           v6) != 0;
}

