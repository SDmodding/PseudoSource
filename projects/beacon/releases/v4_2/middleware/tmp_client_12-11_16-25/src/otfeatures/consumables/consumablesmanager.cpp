// File Line: 22
// RVA: 0x132F360
OSuitePrivate::ConsumablesManager *__fastcall OSuite::IConsumablesManager::GetConsumableManager()
{
  return OSuite::TSingleton<OSuitePrivate::ConsumablesManager>::Object();
}

// File Line: 31
// RVA: 0x15DF9C0
__int64 dynamic_initializer_for__OSuitePrivate::ConsumablesManager::m_instance__()
{
  return atexit(dynamic_atexit_destructor_for__OSuitePrivate::ConsumablesManager::m_instance__);
}

// File Line: 46
// RVA: 0x132EAAC
void __fastcall OSuitePrivate::ConsumablesManager::ConsumablesManager(OSuitePrivate::ConsumablesManager *this, OSuite::ZObject *a2)
{
  OSuite::ZObject *v2; // rbx
  OSuitePrivate::ConsumablesManager *v3; // rdi
  __int64 v4; // rax

  this->m_platformConsumables = 0i64;
  this->m_pEidosConsumables = 0i64;
  this->m_pPlatformOnlyTransaction = 0i64;
  v2 = (OSuite::ZObject *)&this->m_TransactionRequested.vfptr;
  v3 = this;
  this->vfptr = (OSuite::IConsumablesManagerVtbl *)&OSuitePrivate::ConsumablesManager::`vftable'{for `OSuite::IConsumablesManager'};
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuitePrivate::ConsumablesManager::`vftable'{for `OSuite::ZObject'};
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase((OSuite::ZObject *)&this->m_TransactionRequested.vfptr, a2);
  v2[4].vfptr = 0i64;
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v2[3].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  v4 = OSuite::ZObject::malloc(v2, 0x80ui64, 0i64);
  v2[2].vfptr = 0i64;
  v2[4].vfptr = (OSuite::ZObjectVtbl *)v4;
  v2[1].vfptr = (OSuite::ZObjectVtbl *)16;
  OSuite::ZMutex::ZMutex(&v3->m_mutex);
  v3->m_httpRequest = 0i64;
  *(_WORD *)&v3->m_bRequestInProgress = 0;
  OSuite::ZString::ZString(&v3->m_finalizeData);
}

// File Line: 54
// RVA: 0x132EB50
void __fastcall OSuitePrivate::ConsumablesManager::~ConsumablesManager(OSuitePrivate::ConsumablesManager *this)
{
  OSuitePrivate::ConsumablesManager *v1; // rbx
  OSuitePrivate::ZConsumableTransactionBase *v2; // rcx
  OSuite::TList<OSuite::IPlayerAccount *> *v3; // rcx
  OSuite::IPlayerAccount **v4; // rdx

  v1 = this;
  this->vfptr = (OSuite::IConsumablesManagerVtbl *)&OSuitePrivate::ConsumablesManager::`vftable'{for `OSuite::IConsumablesManager'};
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuitePrivate::ConsumablesManager::`vftable'{for `OSuite::ZObject'};
  v2 = this->m_pPlatformOnlyTransaction;
  if ( v2 )
  {
    ((void (__fastcall *)(OSuitePrivate::ZConsumableTransactionBase *, signed __int64))v2->vfptr->~IConsumableTransaction)(
      v2,
      1i64);
    v1->m_pPlatformOnlyTransaction = 0i64;
  }
  OSuite::ZString::~ZString(&v1->m_finalizeData);
  OSuite::ZMutex::~ZMutex(&v1->m_mutex);
  v3 = &v1->m_TransactionRequested;
  v4 = v1->m_TransactionRequested.m_pList;
  v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
  v3->vfptr = (OSuite::IHashableVtbl *)&OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
  OSuite::ZObject::free((OSuite::ZObject *)&v1->m_TransactionRequested.vfptr, v4);
}

// File Line: 66
// RVA: 0x1330A0C
void __fastcall OSuitePrivate::ConsumablesManager::Update(OSuitePrivate::ConsumablesManager *this)
{
  OSuitePrivate::ConsumablesManager *v1; // rbx
  OSuitePrivate::ZPlatformConsumables *v2; // rcx
  int v3; // esi
  OSuitePrivate::ZEidosConsumables *v4; // rcx

  v1 = this;
  OSuite::ZMutex::Lock(&this->m_mutex);
  v2 = v1->m_platformConsumables;
  v3 = 0;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr[4].__vecDelDtor)();
    v3 = ((__int64 (*)(void))v1->m_platformConsumables->vfptr[2].__vecDelDtor)();
  }
  v4 = v1->m_pEidosConsumables;
  if ( v4 )
  {
    ((void (*)(void))v4->vfptr[4].__vecDelDtor)();
    if ( !v3 )
    {
      OSuitePrivate::ConsumablesManager::CloseLostTransactions(v1);
      OSuitePrivate::ConsumablesManager::CompleteTransactions(v1);
      OSuitePrivate::ConsumablesManager::TransferLostConsumables(v1);
    }
  }
  OSuite::ZMutex::Unlock(&v1->m_mutex);
}

// File Line: 96
// RVA: 0x132F714
__int64 __fastcall OSuitePrivate::ConsumablesManager::GetStatus(OSuitePrivate::ConsumablesManager *this)
{
  OSuitePrivate::ConsumablesManager *v1; // rdi
  OSuitePrivate::ZEidosConsumables *v2; // rcx
  unsigned int v3; // ebx
  OSuitePrivate::ZPlatformConsumables *v4; // rcx

  v1 = this;
  OSuite::ZMutex::Lock(&this->m_mutex);
  v2 = v1->m_pEidosConsumables;
  v3 = 0;
  if ( v2 )
    v3 = ((__int64 (*)(void))v2->vfptr[1].__vecDelDtor)();
  v4 = v1->m_platformConsumables;
  if ( v4 && !v3 )
    v3 = ((__int64 (*)(void))v4->vfptr[2].__vecDelDtor)();
  OSuite::ZMutex::Unlock(&v1->m_mutex);
  return v3;
}

// File Line: 116
// RVA: 0x132FBF4
signed __int64 __fastcall OSuitePrivate::ConsumablesManager::Initialize(OSuitePrivate::ConsumablesManager *this, OSuite::IPlayerAccount *pPlayerProfile, OSuite::ZString *servlet)
{
  OSuitePrivate::ConsumablesManager *v3; // rbx
  OSuite::ZString *v4; // rbp
  OSuite::IPlayerAccount *v5; // r14
  unsigned int v6; // edi
  OSuite::ZString *v7; // rax
  hkEntitySelectorAll *v8; // rax
  hkpEntity *v9; // rdx
  OSuite::ZOnlineSuite *v10; // rax
  OSuite::IGameConfig *v11; // rax
  OSuitePrivate::ZEidosConsumables *v13; // rax

  v3 = this;
  v4 = servlet;
  v5 = pPlayerProfile;
  OSuite::ZMutex::Lock(&this->m_mutex);
  v6 = 0;
  v7 = v5->vfptr->GetUserId(v5, 0);
  if ( (unsigned __int8)OSuite::ZString::IsNull(v7) )
  {
    v6 = -2147483646;
  }
  else
  {
    v8 = (hkEntitySelectorAll *)OSuite::GameInterface();
    if ( (unsigned int)hkaReferencePoseAnimation::getNumOriginalFrames(v8, v9) == 1 )
    {
      v10 = OSuite::ZOnlineSuite::Instance();
      v11 = OSuite::ZOnlineSuite::GetGameConfig(v10);
      if ( !(__int64)v11->vfptr->GetSteamWebAPIKey(v11) )
        return 2147483654i64;
    }
    if ( !v3->m_pEidosConsumables && !OSuite::ZString::operator==(v4, &customWorldMapCaption) )
    {
      v13 = OSuite::TSingleton<OSuitePrivate::ZEidosConsumables>::Object();
      v3->m_pEidosConsumables = v13;
      OSuitePrivate::ZEidosConsumables::SetServlet(v13, v4);
      OSuitePrivate::ZEidosConsumables::AddUser(v3->m_pEidosConsumables, v5);
      v6 = ((__int64 (*)(void))v3->m_pEidosConsumables->vfptr[2].__vecDelDtor)();
    }
    if ( !v3->m_platformConsumables )
      v3->m_platformConsumables = 0i64;
  }
  OSuite::ZMutex::Unlock(&v3->m_mutex);
  return v6;
}

// File Line: 164
// RVA: 0x1330038
__int64 __fastcall OSuitePrivate::ConsumablesManager::RegisterUser(OSuitePrivate::ConsumablesManager *this, OSuite::IPlayerAccount *pPlayerAccount)
{
  OSuitePrivate::ConsumablesManager *v2; // rbx
  OSuite::IPlayerAccount *v3; // rbp
  OSuite::ConsumableError v4; // edi
  OSuitePrivate::ZEidosConsumables *v5; // rcx

  v2 = this;
  v3 = pPlayerAccount;
  v4 = 0;
  OSuite::ZMutex::Lock(&this->m_mutex);
  v5 = v2->m_pEidosConsumables;
  if ( v5 )
    v4 = OSuitePrivate::ZEidosConsumables::AddUser(v5, v3);
  OSuite::ZMutex::Unlock(&v2->m_mutex);
  return v4;
}

// File Line: 179
// RVA: 0x1330744
void __fastcall OSuitePrivate::ConsumablesManager::Terminate(OSuitePrivate::ConsumablesManager *this)
{
  OSuitePrivate::ConsumablesManager *v1; // rbx
  OSuitePrivate::ZConsumableTransactionBase *v2; // rcx
  OSuitePrivate::ZPlatformConsumables *v3; // rcx
  OSuitePrivate::ZEidosConsumables *v4; // rcx

  v1 = this;
  OSuite::ZMutex::Lock(&this->m_mutex);
  v2 = v1->m_pPlatformOnlyTransaction;
  if ( v2 )
  {
    ((void (__fastcall *)(OSuitePrivate::ZConsumableTransactionBase *, signed __int64))v2->vfptr->~IConsumableTransaction)(
      v2,
      1i64);
    v1->m_pPlatformOnlyTransaction = 0i64;
  }
  v3 = v1->m_platformConsumables;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr[3].__vecDelDtor)();
    v1->m_platformConsumables = 0i64;
  }
  v4 = v1->m_pEidosConsumables;
  if ( v4 )
  {
    ((void (*)(void))v4->vfptr[3].__vecDelDtor)();
    v1->m_pEidosConsumables = 0i64;
  }
  OSuite::ZMutex::Unlock(&v1->m_mutex);
}

// File Line: 206
// RVA: 0x132F368
__int64 __fastcall OSuitePrivate::ConsumablesManager::GetCount(OSuitePrivate::ConsumablesManager *this, OSuite::IPlayerAccount *pPlayerAccount)
{
  OSuitePrivate::ConsumablesManager *v2; // rdi
  OSuite::IPlayerAccount *v3; // rbp
  unsigned int v4; // ebx
  void *v5; // rcx

  v2 = this;
  v3 = pPlayerAccount;
  v4 = 0;
  OSuite::ZMutex::Lock(&this->m_mutex);
  v5 = v2->m_pEidosConsumables;
  if ( v5 || (v5 = v2->m_platformConsumables) != 0i64 )
    v4 = (*(__int64 (__fastcall **)(void *, OSuite::IPlayerAccount *))(*(_QWORD *)v5 + 40i64))(v5, v3);
  OSuite::ZMutex::Unlock(&v2->m_mutex);
  return v4;
}

// File Line: 224
// RVA: 0x132F3D4
__int64 __fastcall OSuitePrivate::ConsumablesManager::GetInfo(OSuitePrivate::ConsumablesManager *this, OSuite::IPlayerAccount *pPlayerAccount, const char *consumableId, OSuite::IConsumableInfo **ppInfo)
{
  OSuitePrivate::ConsumablesManager *v4; // rdi
  OSuite::IConsumableInfo **v5; // rbp
  const char *v6; // r14
  OSuite::IPlayerAccount *v7; // r15
  unsigned int v8; // ebx
  void *v9; // rcx

  v4 = this;
  v5 = ppInfo;
  v6 = consumableId;
  v7 = pPlayerAccount;
  v8 = -2147483643;
  OSuite::ZMutex::Lock(&this->m_mutex);
  v9 = v4->m_pEidosConsumables;
  if ( v9 || (v9 = v4->m_platformConsumables) != 0i64 )
    v8 = (*(__int64 (__fastcall **)(void *, OSuite::IPlayerAccount *, const char *, OSuite::IConsumableInfo **))(*(_QWORD *)v9 + 48i64))(
           v9,
           v7,
           v6,
           v5);
  OSuite::ZMutex::Unlock(&v4->m_mutex);
  return v8;
}

// File Line: 242
// RVA: 0x132F450
__int64 __fastcall OSuitePrivate::ConsumablesManager::GetNextInfo(OSuitePrivate::ConsumablesManager *this, OSuite::IPlayerAccount *pPlayerAccount, unsigned int index, OSuite::IConsumableInfo **ppInfo)
{
  OSuitePrivate::ConsumablesManager *v4; // rdi
  OSuite::IConsumableInfo **v5; // rbp
  unsigned int v6; // er14
  OSuite::IPlayerAccount *v7; // r15
  unsigned int v8; // ebx
  void *v9; // rcx

  v4 = this;
  v5 = ppInfo;
  v6 = index;
  v7 = pPlayerAccount;
  v8 = -2147483643;
  OSuite::ZMutex::Lock(&this->m_mutex);
  v9 = v4->m_pEidosConsumables;
  if ( v9 || (v9 = v4->m_platformConsumables) != 0i64 )
    v8 = (*(__int64 (__fastcall **)(void *, OSuite::IPlayerAccount *, _QWORD, OSuite::IConsumableInfo **))(*(_QWORD *)v9 + 56i64))(
           v9,
           v7,
           v6,
           v5);
  OSuite::ZMutex::Unlock(&v4->m_mutex);
  return v8;
}

// File Line: 260
// RVA: 0x132EED0
__int64 __fastcall OSuitePrivate::ConsumablesManager::Consume(OSuitePrivate::ConsumablesManager *this, OSuite::IPlayerAccount *pPlayerAccount, OSuite::IConsumableInfo *pInfo)
{
  OSuitePrivate::ConsumablesManager *v3; // rdi
  OSuite::IConsumableInfo *v4; // rbp
  OSuite::IPlayerAccount *v5; // r14
  unsigned int v6; // ebx
  void *v7; // rcx

  v3 = this;
  v4 = pInfo;
  v5 = pPlayerAccount;
  v6 = -2147483643;
  OSuite::ZMutex::Lock(&this->m_mutex);
  v7 = v3->m_pEidosConsumables;
  if ( v7 || (v7 = v3->m_platformConsumables) != 0i64 )
    v6 = (*(__int64 (__fastcall **)(void *, OSuite::IPlayerAccount *, OSuite::IConsumableInfo *))(*(_QWORD *)v7 + 64i64))(
           v7,
           v5,
           v4);
  OSuite::ZMutex::Unlock(&v3->m_mutex);
  return v6;
}

// File Line: 279
// RVA: 0x132FCF0
__int64 __fastcall OSuitePrivate::ConsumablesManager::NewTransaction(OSuitePrivate::ConsumablesManager *this, OSuite::IPlayerAccount *pPlayerAccount, OSuite::TList<OSuite::IConsumableInfo *> *infos, const char *tag)
{
  OSuitePrivate::ConsumablesManager *v4; // rdi
  const char *v5; // rbp
  OSuite::TList<OSuite::IConsumableInfo *> *v6; // r14
  OSuite::IPlayerAccount *v7; // r15
  unsigned int v8; // ebx
  OSuitePrivate::ZEidosConsumables *v9; // rcx
  __int64 v10; // rax

  v4 = this;
  v5 = tag;
  v6 = infos;
  v7 = pPlayerAccount;
  v8 = -2147483135;
  OSuite::ZMutex::Lock(&this->m_mutex);
  v9 = v4->m_pEidosConsumables;
  if ( v9 )
  {
    v8 = OSuitePrivate::ZEidosConsumables::NewTransaction(v9, v7, v6, v5);
  }
  else if ( !v4->m_pPlatformOnlyTransaction )
  {
    v10 = OSuite::ZObject::operator new(0x18ui64);
    if ( v10 )
    {
      *(_DWORD *)(v10 + 16) = 0;
      *(_QWORD *)v10 = &OSuitePrivate::ZConsumableTransactionBase::`vftable'{for `OSuite::IConsumableTransaction'};
      *(_QWORD *)(v10 + 8) = &OSuitePrivate::ZConsumableTransactionBase::`vftable'{for `OSuite::ZObject'};
    }
    v4->m_pPlatformOnlyTransaction = (OSuitePrivate::ZConsumableTransactionBase *)v10;
    v8 = v10 == 0 ? 0x80000004 : 0;
  }
  OSuite::ZMutex::Unlock(&v4->m_mutex);
  return v8;
}

// File Line: 303
// RVA: 0x132F2DC
__int64 __fastcall OSuitePrivate::ConsumablesManager::GetActiveTransaction(OSuitePrivate::ConsumablesManager *this, OSuite::IPlayerAccount *pPlayerAccount, OSuite::IConsumableTransaction **ppTransaction)
{
  OSuitePrivate::ConsumablesManager *v3; // rsi
  OSuite::IConsumableTransaction **v4; // rdi
  OSuite::IPlayerAccount *v5; // r14
  OSuite::ConsumableError v6; // ebx
  OSuitePrivate::ZEidosConsumables *v7; // rcx
  OSuitePrivate::ZConsumableTransactionBase *v8; // rax

  v3 = this;
  v4 = ppTransaction;
  v5 = pPlayerAccount;
  v6 = -2147483132;
  OSuite::ZMutex::Lock(&this->m_mutex);
  v7 = v3->m_pEidosConsumables;
  if ( v7 )
  {
    v6 = OSuitePrivate::ZEidosConsumables::GetActiveTransaction(v7, v5, v4);
  }
  else
  {
    v8 = v3->m_pPlatformOnlyTransaction;
    if ( v8 )
    {
      if ( v4 )
        *v4 = (OSuite::IConsumableTransaction *)&v8->vfptr;
      v6 = 0;
    }
  }
  OSuite::ZMutex::Unlock(&v3->m_mutex);
  return v6;
}

// File Line: 328
// RVA: 0x132EC3C
__int64 __fastcall OSuitePrivate::ConsumablesManager::CloseActiveTransaction(OSuitePrivate::ConsumablesManager *this, OSuite::IPlayerAccount *pPlayerAccount)
{
  OSuitePrivate::ConsumablesManager *v2; // rbx
  OSuite::IPlayerAccount *v3; // rsi
  OSuitePrivate::ZEidosConsumables *v4; // rcx
  OSuite::ConsumableError v5; // edi
  OSuitePrivate::ZConsumableTransactionBase *v6; // rcx
  OSuitePrivate::ZConsumableTransactionBase *v7; // rcx
  OSuite::IConsumableTransaction *ppTransaction; // [rsp+20h] [rbp-28h]

  v2 = this;
  v3 = pPlayerAccount;
  OSuite::ZMutex::Lock(&this->m_mutex);
  v4 = v2->m_pEidosConsumables;
  v5 = -2147483133;
  if ( v4 )
  {
    ppTransaction = 0i64;
    if ( OSuitePrivate::ZEidosConsumables::GetActiveTransaction(v4, v3, &ppTransaction) == OS_CONSUMABLES_OK )
    {
      ((void (*)(void))ppTransaction->vfptr->GetState)();
      ppTransaction = 0i64;
    }
    v5 = OSuitePrivate::ZEidosConsumables::CloseActiveTransaction(v2->m_pEidosConsumables, v3);
  }
  else
  {
    v6 = v2->m_pPlatformOnlyTransaction;
    if ( v6 )
    {
      ((void (*)(void))v6->vfptr->GetState)();
      v7 = v2->m_pPlatformOnlyTransaction;
      if ( v7 )
        ((void (__fastcall *)(OSuitePrivate::ZConsumableTransactionBase *, signed __int64))v7->vfptr->~IConsumableTransaction)(
          v7,
          1i64);
      v2->m_pPlatformOnlyTransaction = 0i64;
      v5 = 0;
    }
  }
  OSuite::ZMutex::Unlock(&v2->m_mutex);
  return v5;
}

// File Line: 371
// RVA: 0x132EDFC
void __fastcall OSuitePrivate::ConsumablesManager::CompleteTransactions(OSuitePrivate::ConsumablesManager *this)
{
  OSuitePrivate::ConsumablesManager *v1; // rdi
  OSuitePrivate::ZEidosConsumables *v2; // rcx
  unsigned __int64 v3; // rsi
  OSuitePrivate::ZEidosTransaction *v4; // rax
  OSuitePrivate::ZEidosTransaction *v5; // rbx
  OSuite::IPlayerAccount *v6; // rax
  OSuite::IPlayerAccount *v7; // rax

  v1 = this;
  v2 = this->m_pEidosConsumables;
  if ( v2 )
  {
    v3 = 0i64;
    if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v2->m_playerData) )
    {
      do
      {
        v4 = OSuitePrivate::ZEidosConsumables::GetTransaction(v1->m_pEidosConsumables, v3);
        v5 = v4;
        if ( v4 && v4->m_bClose )
        {
          if ( OSuitePrivate::ZEidosTransaction::GetCompletionState(v4) )
          {
            if ( OSuitePrivate::ZEidosTransaction::GetCompletionState(v5) == 2
              || OSuitePrivate::ZEidosTransaction::GetCompletionState(v5) == 3 )
            {
              v7 = OSuitePrivate::ZEidosConsumables::GetUser(v1->m_pEidosConsumables, v3);
              OSuitePrivate::ConsumablesManager::HandlePurchasedTxn(v1, v7, v5);
            }
          }
          else
          {
            v6 = OSuitePrivate::ZEidosConsumables::GetUser(v1->m_pEidosConsumables, v3);
            OSuitePrivate::ConsumablesManager::HandleNewTxn(v1, v6, v5);
          }
        }
        ++v3;
      }
      while ( v3 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v1->m_pEidosConsumables->m_playerData) );
    }
  }
}

// File Line: 401
// RVA: 0x132F87C
void __fastcall OSuitePrivate::ConsumablesManager::HandleNewTxn(OSuitePrivate::ConsumablesManager *this, OSuite::IPlayerAccount *pPlayerAccount, OSuitePrivate::ZEidosTransaction *pTxn)
{
  OSuitePrivate::ConsumablesManager *v3; // rbx
  OSuitePrivate::ZEidosTransaction *v4; // rdi
  OSuite::IPlayerAccount *v5; // rsi
  OSuite::ITransactionState v6; // eax
  OSuitePrivate::ZPlatformConsumables *v7; // rcx
  OSuitePrivate::EidosTransactionState v8; // er9
  hkEntitySelectorAll *v9; // rax
  hkpEntity *v10; // rdx
  OSuitePrivate::ZPlatformConsumables *v11; // rcx
  OSuitePrivate::EidosTransactionState v12; // edx

  v3 = this;
  v4 = pTxn;
  v5 = pPlayerAccount;
  v6 = (unsigned int)pTxn->vfptr->GetState((OSuite::IConsumableTransaction *)pTxn);
  if ( v6 == TRANSACTION_STATE_NEW )
  {
    v7 = v3->m_platformConsumables;
    if ( v7 )
    {
      if ( !((unsigned __int8 (*)(void))v7->vfptr[9].__vecDelDtor)() )
        return;
      v8 = 6;
      goto LABEL_5;
    }
    if ( v3->m_pEidosConsumables )
    {
      v9 = (hkEntitySelectorAll *)OSuite::GameInterface();
      if ( (unsigned int)hkaReferencePoseAnimation::getNumOriginalFrames(v9, v10) == 1 )
        OSuitePrivate::ConsumablesManager::QuerySteamTxn(v3, v5, v4);
      else
        v4->m_bClose = 0;
    }
    return;
  }
  if ( v6 != 1 )
  {
    if ( v6 != 2 )
      return;
    v12 = 6;
    goto LABEL_18;
  }
  v11 = v3->m_platformConsumables;
  if ( !v11 )
  {
    if ( !v3->m_pEidosConsumables )
      return;
    v12 = 4;
LABEL_18:
    OSuitePrivate::ZEidosTransaction::SetCompletionState(v4, v12);
    return;
  }
  if ( ((unsigned __int8 (*)(void))v11->vfptr[9].__vecDelDtor)() )
  {
    v8 = 7;
LABEL_5:
    OSuitePrivate::ConsumablesManager::SendPurchasedData(v3, v5, v4, v8);
  }
}

// File Line: 459
// RVA: 0x1330344
void __fastcall OSuitePrivate::ConsumablesManager::SendPurchasedData(OSuitePrivate::ConsumablesManager *this, OSuite::IPlayerAccount *pPlayerAccount, OSuitePrivate::ZEidosTransaction *pTxn, OSuitePrivate::EidosTransactionState errState)
{
  OSuitePrivate::ConsumablesManager *v4; // r12
  OSuitePrivate::EidosTransactionState v5; // er15
  OSuitePrivate::ZEidosTransaction *v6; // r14
  OSuitePrivate::EidosTransactionState v7; // ebx
  void *v8; // rax
  __int64 v9; // rsi
  OSuite::ZConsumableInfoBase *v10; // rdi
  OSuitePrivate::ZPlatformConsumables *v11; // rax
  OSuite::ZObjectVtbl *v12; // rbx
  OSuite::ZString *v13; // rax
  char *v14; // rax
  unsigned int v15; // ebx
  OSuite::ZObjectVtbl *v16; // rbx
  OSuite::ZString *v17; // rax
  char *v18; // rax
  int v19; // eax
  int v20; // ebx
  OSuite::IPlayerAccount *v21; // [rsp+20h] [rbp-48h]
  __int64 v22; // [rsp+28h] [rbp-40h]
  OSuite::ZObject v23; // [rsp+30h] [rbp-38h]
  __int64 v24; // [rsp+38h] [rbp-30h]
  __int64 v25; // [rsp+40h] [rbp-28h]
  void **v26; // [rsp+48h] [rbp-20h]
  void *ptr; // [rsp+50h] [rbp-18h]

  v4 = this;
  v5 = errState;
  v6 = pTxn;
  v21 = pPlayerAccount;
  v7 = errState;
  ptr = 0i64;
  OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&v23, (OSuite::ZObject *)pPlayerAccount);
  v23.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<int>::`vftable'{for `OSuite::ZListBase'};
  v26 = &OSuite::TList<int>::`vftable'{for `OSuite::IHashable'};
  ptr = 0i64;
  v8 = (void *)OSuite::ZObject::malloc(&v23, 0x40ui64, 0i64);
  v24 = 16i64;
  v25 = 0i64;
  ptr = v8;
  v9 = 0i64;
  if ( !OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v6->m_Infos) )
    goto LABEL_13;
  while ( 1 )
  {
    v10 = v6->m_Infos.m_pList[v9];
    if ( !v10 )
      goto LABEL_9;
    v11 = v4->m_platformConsumables;
    v22 = 0i64;
    v12 = v11->vfptr;
    v13 = (OSuite::ZString *)v10->vfptr->GetId((OSuite::IConsumableInfo *)&v10->vfptr);
    v14 = OSuite::ZString::c_str(v13);
    if ( ((unsigned int (__fastcall *)(OSuitePrivate::ZPlatformConsumables *, OSuite::IPlayerAccount *, char *, __int64 *))v12[6].__vecDelDtor)(
           v4->m_platformConsumables,
           v21,
           v14,
           &v22) )
    {
      break;
    }
    v15 = (*(__int64 (**)(void))(*(_QWORD *)v22 + 8i64))();
    if ( v15 < v10->vfptr->GetQuantity((OSuite::IConsumableInfo *)&v10->vfptr) )
    {
      v7 = v5;
      (*(void (**)(void))(*(_QWORD *)v22 + 16i64))();
      goto LABEL_13;
    }
    if ( ((unsigned __int8 (*)(void))v4->m_platformConsumables->vfptr[10].__vecDelDtor)() )
    {
      v16 = v4->m_platformConsumables->vfptr;
      v17 = (OSuite::ZString *)v10->vfptr->GetId((OSuite::IConsumableInfo *)&v10->vfptr);
      v18 = OSuite::ZString::c_str(v17);
      v19 = ((__int64 (__fastcall *)(OSuitePrivate::ZPlatformConsumables *, OSuite::IPlayerAccount *, char *))v16[11].__vecDelDtor)(
              v4->m_platformConsumables,
              v21,
              v18);
    }
    else
    {
      v19 = (*(__int64 (**)(void))(*(_QWORD *)v22 + 8i64))();
    }
    v20 = v19;
    OSuite::TList<int>::Grow((OSuite::TList<int> *)&v23, v25 + 1);
    *((_DWORD *)ptr + v25++) = v20;
    v7 = 2;
    (*(void (**)(void))(*(_QWORD *)v22 + 16i64))();
LABEL_9:
    if ( ++v9 >= OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v6->m_Infos) )
      goto LABEL_13;
  }
  v7 = v5;
LABEL_13:
  if ( v7 == 2 )
    OSuitePrivate::ZEidosTransaction::UpdateToPurchased(v6, (OSuite::TList<int> *)&v23);
  else
    OSuitePrivate::ZEidosTransaction::SetCompletionState(v6, v7);
  v23.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<int>::`vftable'{for `OSuite::ZListBase'};
  v26 = &OSuite::TList<int>::`vftable'{for `OSuite::IHashable'};
  OSuite::ZObject::free(&v23, ptr);
}

// File Line: 509
// RVA: 0x132F94C
void __fastcall OSuitePrivate::ConsumablesManager::HandlePurchasedTxn(OSuitePrivate::ConsumablesManager *this, OSuite::IPlayerAccount *pPlayerAccount, OSuitePrivate::ZEidosTransaction *pTxn)
{
  OSuitePrivate::ConsumablesManager *v3; // rbx
  OSuitePrivate::ZPlatformConsumables *v4; // rcx
  OSuitePrivate::ZEidosTransaction *v5; // rdi
  OSuite::IPlayerAccount *v6; // rsi

  v3 = this;
  v4 = this->m_platformConsumables;
  v5 = pTxn;
  v6 = pPlayerAccount;
  if ( v4 )
  {
    ((void (*)(void))v4->vfptr[5].__vecDelDtor)();
    if ( ((unsigned __int8 (*)(void))v3->m_platformConsumables->vfptr[9].__vecDelDtor)() )
    {
      if ( ((unsigned __int8 (*)(void))v3->m_platformConsumables->vfptr[10].__vecDelDtor)() )
        OSuitePrivate::ConsumablesManager::ConsumeDataFromConsumedCount(v3, v6, v5);
      else
        OSuitePrivate::ConsumablesManager::ConsumeDataFromInfo(v3, v6, v5);
    }
  }
  else if ( v3->m_pEidosConsumables )
  {
    OSuitePrivate::ZEidosTransaction::SetCompletionState(pTxn, TXN_CONSUMED);
  }
}

// File Line: 533
// RVA: 0x132F0E0
void __fastcall OSuitePrivate::ConsumablesManager::ConsumeDataFromInfo(OSuitePrivate::ConsumablesManager *this, OSuite::IPlayerAccount *pPlayerAccount, OSuitePrivate::ZEidosTransaction *pTxn)
{
  OSuite::ZRedBlackTreeBase *v3; // r13
  OSuitePrivate::ConsumablesManager *v4; // rbx
  OSuitePrivate::ZEidosTransaction *v5; // rbp
  char v6; // r15
  unsigned __int64 v7; // r14
  __int64 v8; // rdi
  signed __int64 v9; // r12
  unsigned __int64 v10; // rsi
  __int64 v11; // r12
  OSuitePrivate::ZPlatformConsumables *v12; // rax
  OSuite::ZObjectVtbl *v13; // rbx
  OSuite::ZString *v14; // rax
  char *v15; // rax
  int v16; // eax
  int v17; // ebx
  int v18; // edi
  int v19; // ebx
  bool v20; // zf
  OSuitePrivate::EidosTransactionState v21; // edx
  unsigned __int64 v22; // rax
  OSuitePrivate::ConsumablesManager *v23; // [rsp+20h] [rbp-68h]
  __int64 v24; // [rsp+28h] [rbp-60h]
  OSuite::IPlayerAccount *v25; // [rsp+30h] [rbp-58h]
  __int64 v26; // [rsp+38h] [rbp-50h]
  __int64 v27; // [rsp+40h] [rbp-48h]

  v3 = (OSuite::ZRedBlackTreeBase *)&pTxn->m_Infos;
  v4 = this;
  v23 = this;
  v5 = pTxn;
  v25 = pPlayerAccount;
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
      v11 = *(__int64 *)((char *)&v3[1].m_pTop->vfptr + v9);
      if ( v11 )
      {
        v12 = v4->m_platformConsumables;
        v27 = 0i64;
        v13 = v12->vfptr;
        v14 = (OSuite::ZString *)(**(__int64 (__fastcall ***)(__int64))v11)(v11);
        v15 = OSuite::ZString::c_str(v14);
        v16 = ((__int64 (__fastcall *)(OSuitePrivate::ZPlatformConsumables *, OSuite::IPlayerAccount *, char *, __int64 *))v13[6].__vecDelDtor)(
                v23->m_platformConsumables,
                v25,
                v15,
                &v27);
        if ( v16 )
        {
          v4 = v23;
          if ( v16 == -2147483388 )
            ++v7;
          else
            v6 = 1;
        }
        else
        {
          OSuite::TList<int>::Grow(&v5->m_tempCount, v10);
          if ( v10 - 1 >= v5->m_tempCount.m_nTop )
            v5->m_tempCount.m_nTop = v10;
          v17 = *(int *)((char *)v5->m_tempCount.m_pList + v24);
          if ( (*(unsigned int (**)(void))(*(_QWORD *)v27 + 8i64))() == v17 )
          {
            v4 = v23;
            ((void (__fastcall *)(OSuitePrivate::ZPlatformConsumables *, OSuite::IPlayerAccount *, __int64))v23->m_platformConsumables->vfptr[8].__vecDelDtor)(
              v23->m_platformConsumables,
              v25,
              v11);
          }
          else
          {
            OSuite::TList<int>::Grow(&v5->m_tempCount, v10);
            if ( v10 - 1 >= v5->m_tempCount.m_nTop )
              v5->m_tempCount.m_nTop = v10;
            v18 = *(int *)((char *)v5->m_tempCount.m_pList + v24);
            v19 = (*(__int64 (**)(void))(*(_QWORD *)v27 + 8i64))();
            v20 = (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v11 + 8i64))(v11) + v19 == v18;
            v4 = v23;
            if ( v20 )
              ++v7;
            else
              v6 = 1;
          }
          (*(void (**)(void))(*(_QWORD *)v27 + 16i64))();
          v8 = v24;
        }
      }
      v8 += 4i64;
      v9 = v26 + 8;
      ++v10;
      v24 = v8;
      v26 += 8i64;
      if ( v10 - 1 >= OSuite::ZHttpStreamReader::Tell(v3) )
      {
        if ( !v6 )
          goto LABEL_22;
        break;
      }
    }
    v21 = 7;
  }
  else
  {
LABEL_22:
    v22 = OSuite::ZHttpStreamReader::Tell(v3);
    v21 = 3;
    if ( v7 >= v22 )
      v21 = 4;
  }
  OSuitePrivate::ZEidosTransaction::SetCompletionState(v5, v21);
}

// File Line: 578
// RVA: 0x132EF48
void __fastcall OSuitePrivate::ConsumablesManager::ConsumeDataFromConsumedCount(OSuitePrivate::ConsumablesManager *this, OSuite::IPlayerAccount *pPlayerAccount, OSuitePrivate::ZEidosTransaction *pTxn)
{
  OSuite::ZRedBlackTreeBase *v3; // r15
  OSuitePrivate::ConsumablesManager *v4; // rbx
  OSuitePrivate::ZEidosTransaction *v5; // rsi
  char v6; // r12
  unsigned __int64 v7; // rbp
  __int64 v8; // r13
  signed __int64 v9; // r14
  unsigned __int64 v10; // rdi
  __int64 v11; // r14
  OSuite::ZObjectVtbl *v12; // rbx
  OSuite::ZString *v13; // rax
  char *v14; // rax
  int v15; // ebx
  OSuitePrivate::EidosTransactionState v16; // edx
  unsigned __int64 v17; // rax
  OSuitePrivate::ConsumablesManager *v18; // [rsp+70h] [rbp+8h]
  OSuite::IPlayerAccount *v19; // [rsp+78h] [rbp+10h]
  int v20; // [rsp+80h] [rbp+18h]
  __int64 v21; // [rsp+88h] [rbp+20h]

  v19 = pPlayerAccount;
  v18 = this;
  v3 = (OSuite::ZRedBlackTreeBase *)&pTxn->m_Infos;
  v4 = this;
  v5 = pTxn;
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
        v16 = 7;
        goto LABEL_21;
      }
      v11 = *(__int64 *)((char *)&v3[1].m_pTop->vfptr + v9);
      if ( v11 )
      {
        v12 = v4->m_platformConsumables->vfptr;
        v13 = (OSuite::ZString *)(**(__int64 (__fastcall ***)(__int64))v11)(v11);
        v14 = OSuite::ZString::c_str(v13);
        v20 = ((__int64 (__fastcall *)(OSuitePrivate::ZPlatformConsumables *, OSuite::IPlayerAccount *, char *))v12[11].__vecDelDtor)(
                v18->m_platformConsumables,
                v19,
                v14);
        if ( v20 == -2 )
          goto LABEL_6;
        OSuite::TList<int>::Grow(&v5->m_tempCount, v10);
        if ( v10 - 1 >= v5->m_tempCount.m_nTop )
          v5->m_tempCount.m_nTop = v10;
        if ( v20 != v5->m_tempCount.m_pList[v8] )
        {
          OSuite::TList<int>::Grow(&v5->m_tempCount, v10);
          if ( v10 - 1 >= v5->m_tempCount.m_nTop )
            v5->m_tempCount.m_nTop = v10;
          v15 = v5->m_tempCount.m_pList[v8];
          if ( v15 + (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v11 + 8i64))(v11) == v20 )
LABEL_6:
            ++v7;
          else
            v6 = 1;
          v4 = v18;
          goto LABEL_16;
        }
        v4 = v18;
        ((void (__fastcall *)(OSuitePrivate::ZPlatformConsumables *, OSuite::IPlayerAccount *, __int64))v18->m_platformConsumables->vfptr[8].__vecDelDtor)(
          v18->m_platformConsumables,
          v19,
          v11);
      }
LABEL_16:
      ++v10;
      v9 = v21 + 8;
      ++v8;
      v21 += 8i64;
      if ( v10 - 1 >= OSuite::ZHttpStreamReader::Tell(v3) )
      {
        if ( !v6 )
          break;
        goto LABEL_18;
      }
    }
  }
  v17 = OSuite::ZHttpStreamReader::Tell(v3);
  v16 = 3;
  if ( v7 >= v17 )
    v16 = 4;
LABEL_21:
  OSuitePrivate::ZEidosTransaction::SetCompletionState(v5, v16);
}

// File Line: 615
// RVA: 0x13307B0
void __fastcall OSuitePrivate::ConsumablesManager::TransferLostConsumables(OSuitePrivate::ConsumablesManager *this)
{
  OSuitePrivate::ConsumablesManager *v1; // rdi
  OSuitePrivate::ZPlatformConsumables *v2; // rcx
  unsigned __int64 v3; // r14
  OSuite::IPlayerAccount *v4; // rsi
  int v5; // er15
  OSuitePrivate::ZEidosConsumables *v6; // rcx
  OSuite::ZObject *v7; // rdx
  void *v8; // rax
  unsigned int v9; // ebx
  OSuitePrivate::ZPlatformConsumables *v10; // rcx
  unsigned __int64 v11; // rsi
  unsigned __int64 v12; // rbx
  signed __int64 v13; // rax
  __int64 v14; // [rsp+20h] [rbp-40h]
  OSuite::IConsumableTransaction *ppTransaction; // [rsp+28h] [rbp-38h]
  OSuite::ZObject v16; // [rsp+30h] [rbp-30h]
  __int64 v17; // [rsp+38h] [rbp-28h]
  unsigned __int64 v18; // [rsp+40h] [rbp-20h]
  void **v19; // [rsp+48h] [rbp-18h]
  void *ptr; // [rsp+50h] [rbp-10h]

  v1 = this;
  v2 = this->m_platformConsumables;
  if ( v2 )
  {
    if ( v1->m_pEidosConsumables )
    {
      if ( ((unsigned __int8 (*)(void))v2->vfptr[9].__vecDelDtor)() )
      {
        v3 = 0i64;
        if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v1->m_pEidosConsumables->m_playerData) )
        {
          do
          {
            v4 = OSuitePrivate::ZEidosConsumables::GetUser(v1->m_pEidosConsumables, v3);
            v5 = (__int64)v1->m_platformConsumables->vfptr[5].__vecDelDtor(
                            (OSuite::ZObject *)&v1->m_platformConsumables->vfptr,
                            (unsigned int)v4);
            if ( v5 > 0 )
            {
              v6 = v1->m_pEidosConsumables;
              ppTransaction = 0i64;
              if ( OSuitePrivate::ZEidosConsumables::GetActiveTransaction(v6, v4, &ppTransaction) == -2147483132 )
              {
                ptr = 0i64;
                OSuite::ZRedBlackTreeBase::ZElementBase::ZElementBase(&v16, v7);
                ptr = 0i64;
                v16.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
                v19 = &OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
                v8 = (void *)OSuite::ZObject::malloc(&v16, 0x80ui64, 0i64);
                v18 = 0i64;
                v9 = 0;
                ptr = v8;
                v17 = 16i64;
                if ( v5 > 0 )
                {
                  do
                  {
                    v10 = v1->m_platformConsumables;
                    v14 = 0i64;
                    if ( !((unsigned int (__fastcall *)(OSuitePrivate::ZPlatformConsumables *, OSuite::IPlayerAccount *, _QWORD, __int64 *))v10->vfptr[7].__vecDelDtor)(
                            v10,
                            v4,
                            v9,
                            &v14) )
                    {
                      if ( (*(unsigned int (**)(void))(*(_QWORD *)v14 + 8i64))() )
                      {
                        OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
                          (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v16,
                          v18 + 1);
                        *((_QWORD *)ptr + v18++) = v14;
                      }
                      else
                      {
                        (*(void (**)(void))(*(_QWORD *)v14 + 16i64))();
                      }
                    }
                    ++v9;
                  }
                  while ( (signed int)v9 < v5 );
                }
                if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v16) )
                {
                  if ( OSuitePrivate::ZEidosConsumables::NewTransaction(
                         v1->m_pEidosConsumables,
                         v4,
                         (OSuite::TList<OSuite::IConsumableInfo *> *)&v16,
                         "ConsumableManager") == OS_CONSUMABLES_OK )
                  {
                    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
                      (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v1->m_TransactionRequested,
                      v1->m_TransactionRequested.m_nTop + 1);
                    v1->m_TransactionRequested.m_pList[v1->m_TransactionRequested.m_nTop++] = v4;
                  }
                  v11 = 0i64;
                  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v16) )
                  {
                    do
                    {
                      v12 = v11 + 1;
                      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(
                        (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&v16,
                        v11 + 1);
                      v13 = v18;
                      if ( v11 >= v18 )
                        v13 = v11 + 1;
                      v18 = v13;
                      (*(void (**)(void))(**((_QWORD **)ptr + v11++) + 16i64))();
                    }
                    while ( v12 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v16) );
                  }
                }
                v19 = &OSuite::TList<OSuite::ZJsonObject *>::`vftable'{for `OSuite::IHashable'};
                v16.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TList<OSuitePrivate::ZPlayerConsumableData::ZRequest *>::`vftable'{for `OSuite::ZListBase'};
                OSuite::ZObject::free(&v16, ptr);
              }
            }
            ++v3;
          }
          while ( v3 < OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v1->m_pEidosConsumables->m_playerData) );
        }
      }
    }
  }
}

// File Line: 663
// RVA: 0x132ECFC
void __fastcall OSuitePrivate::ConsumablesManager::CloseLostTransactions(OSuitePrivate::ConsumablesManager *this)
{
  OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *v1; // rbx
  OSuitePrivate::ConsumablesManager *v2; // rbp
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rsi
  OSuite::ConsumableError v5; // eax
  OSuite::IConsumableTransaction *ppTransaction; // [rsp+20h] [rbp-18h]

  v1 = (OSuite::TList<OSuite::ZRedBlackTreeBase::ZElementBase *> *)&this->m_TransactionRequested;
  v2 = this;
  v3 = 0i64;
  if ( OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&this->m_TransactionRequested) )
  {
    v4 = 1i64;
    while ( 1 )
    {
      ppTransaction = 0i64;
      OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v1, v4);
      if ( v3 >= v1->m_nTop )
        v1->m_nTop = v4;
      v5 = OSuitePrivate::ZEidosConsumables::GetActiveTransaction(
             v2->m_pEidosConsumables,
             (OSuite::IPlayerAccount *)v1->m_pList[v3],
             &ppTransaction);
      if ( ppTransaction )
        break;
      if ( v5 == -2147483132 )
        goto LABEL_10;
LABEL_11:
      ++v3;
      ++v4;
      if ( v3 >= OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)v1) )
        return;
    }
    ppTransaction->vfptr->SetState(ppTransaction, TRANSACTION_STATE_PURCHASED);
    OSuite::TList<OSuite::ZONavigationProperty *>::Grow(v1, v4);
    if ( v3 >= v1->m_nTop )
      v1->m_nTop = v4;
    OSuitePrivate::ZEidosConsumables::CloseActiveTransaction(
      v2->m_pEidosConsumables,
      (OSuite::IPlayerAccount *)v1->m_pList[v3]);
LABEL_10:
    v1->vfptr[1].__vecDelDtor((OSuite::ZObject *)&v1->vfptr, v3--);
    --v4;
    goto LABEL_11;
  }
}

// File Line: 687
// RVA: 0x132F4CC
OSuite::ZJsonObject *__fastcall OSuitePrivate::ConsumablesManager::GetResponseParams(OSuitePrivate::ConsumablesManager *this, OSuite::ZJsonDocument *doc)
{
  void *(__fastcall *v2)(OSuite::ZObject *, unsigned int); // rdi
  OSuite::ZJsonDocument *v3; // rbx
  OSuite::ZObjectVtbl *v4; // rsi
  OSuite::ZJsonObject *v5; // rsi
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
  OSuite::ZString sName; // [rsp+20h] [rbp-39h]
  OSuite::ZString v18; // [rsp+38h] [rbp-21h]
  OSuite::ZString v19; // [rsp+50h] [rbp-9h]
  OSuite::ZString result; // [rsp+68h] [rbp+Fh]
  OSuite::ZString v21; // [rsp+80h] [rbp+27h]

  v2 = 0i64;
  v3 = doc;
  v21.m_pString = 0i64;
  OSuite::ZString::ZString(&v21);
  OSuite::ZString::ZString(&sName, "response");
  v4 = OSuite::ZJsonObject::Value((OSuite::ZJsonObject *)&v3->vfptr, &sName);
  OSuite::ZString::~ZString(&sName);
  if ( v4 )
  {
    v5 = (OSuite::ZJsonObject *)v4[10].__vecDelDtor;
    if ( v5 )
    {
      OSuite::ZString::ZString(&sName, "result");
      v6 = OSuite::ZJsonObject::Value(v5, &sName);
      OSuite::ZString::~ZString(&sName);
      OSuite::ZString::operator=(&v21, (OSuite::ZString *)&v6[2]);
      if ( OSuite::ZString::operator==(&v21, "Failure") )
      {
        OSuite::ZString::ZString(&sName, "error");
        v7 = OSuite::ZJsonObject::Value(v5, &sName);
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
        v15 = OSuite::ZJsonObject::Value(v5, &v18);
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
void __fastcall OSuitePrivate::ConsumablesManager::QuerySteamTxn(OSuitePrivate::ConsumablesManager *this, OSuite::IPlayerAccount *pPlayerAccount, OSuitePrivate::ZEidosTransaction *pTxn)
{
  OSuitePrivate::ZEidosTransaction *v3; // rdi
  OSuitePrivate::ConsumablesManager *v4; // rbx
  __int64 v5; // rax
  __int64 v6; // rax
  OSuitePrivate::EidosTransactionState v7; // eax
  OSuitePrivate::EidosTransactionState v8; // esi
  OSuite::ZHttpManager *v9; // rax
  __int64 v10; // rax

  v3 = pTxn;
  v4 = this;
  if ( !this->m_bRequestInProgress )
  {
    if ( this->m_httpRequest )
    {
      if ( this->m_bFinalizingTxn )
      {
        v6 = ((__int64 (__fastcall *)(OSuitePrivate::ZEidosTransaction *, OSuite::IPlayerAccount *))pTxn->vfptr->GetId)(
               pTxn,
               pPlayerAccount);
        v7 = (unsigned int)OSuitePrivate::ConsumablesManager::HandleFinalizeResponse(v4, v6);
      }
      else
      {
        v7 = (unsigned int)OSuitePrivate::ConsumablesManager::HandleQueryResponse(this, pPlayerAccount, pTxn);
      }
      v8 = v7;
      v9 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
      OSuite::ZHttpRequestManager::ReleaseHttpRequest(v9->m_httpRequestManager, v4->m_httpRequest);
      v4->m_httpRequest = 0i64;
      if ( v8 )
      {
        OSuitePrivate::ZEidosTransaction::SetCompletionState(v3, v8);
      }
      else
      {
        v10 = v3->vfptr->GetId((OSuite::IConsumableTransaction *)&v3->vfptr);
        OSuitePrivate::ConsumablesManager::SendFinalize(v4, v10);
      }
    }
    else
    {
      v5 = ((__int64 (__fastcall *)(OSuitePrivate::ZEidosTransaction *, OSuite::IPlayerAccount *))pTxn->vfptr->GetId)(
             pTxn,
             pPlayerAccount);
      OSuitePrivate::ConsumablesManager::SendQuery(v4, v5);
    }
  }
}

// File Line: 775
// RVA: 0x133052C
void __fastcall OSuitePrivate::ConsumablesManager::SendQuery(OSuitePrivate::ConsumablesManager *this, __int64 orderId)
{
  OSuitePrivate::ConsumablesManager *v2; // rdi
  __int64 v3; // rbx
  OSuite::ZGameInterface *v4; // rax
  const char *v5; // rax
  OSuite::ZOnlineSuite *v6; // rax
  OSuite::IGameConfig *v7; // rax
  const char *v8; // rax
  OSuite::ZGameInterface *v9; // rax
  unsigned int v10; // eax
  OSuite::ZHttpRequestManager *v11; // rbx
  OSuite::ZUrl *v12; // rax
  OSuite::IHttpRequest *v13; // rax
  OSuite::ZObjectVtbl *v14; // rbx
  __int64 v15; // rax
  OSuite::ZObjectVtbl *v16; // rbx
  __int64 v17; // rax
  hkSeekableStreamReader *v18; // rax
  OSuite::IHttpRequest *v19; // rcx
  __int64 v20; // [rsp+30h] [rbp-D0h]
  __int64 v21; // [rsp+38h] [rbp-C8h]
  __int64 v22; // [rsp+40h] [rbp-C0h]
  __int64 v23; // [rsp+48h] [rbp-B8h]
  __int64 v24; // [rsp+50h] [rbp-B0h]
  __int64 v25; // [rsp+58h] [rbp-A8h]
  hkSeekableStreamReader *v26; // [rsp+60h] [rbp-A0h]
  bool (__fastcall *v27)(OSuitePrivate::ConsumablesManager *, OSuite::IHttpRequest *, OSuite::ZHttp::EError); // [rsp+68h] [rbp-98h]
  char v28; // [rsp+70h] [rbp-90h]
  OSuite::ZString v29; // [rsp+78h] [rbp-88h]
  OSuite::ZUrl v30; // [rsp+90h] [rbp-70h]
  OSuite::ZStringBuilder v31; // [rsp+168h] [rbp+68h]
  OSuite::ZString result; // [rsp+198h] [rbp+98h]

  v2 = this;
  *(_WORD *)&this->m_bRequestInProgress = 1;
  v3 = orderId;
  v31.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v31, 0x100ui64);
  v4 = OSuite::GameInterface();
  v5 = OSuite::ZGameInterface::GetSteamShopURL(v4);
  OSuite::ZStringBuilder::Append(&v31, v5);
  OSuite::ZStringBuilder::Append(&v31, "QueryTxn/V0001/?key=");
  v6 = OSuite::ZOnlineSuite::Instance();
  v7 = OSuite::ZOnlineSuite::GetGameConfig(v6);
  v8 = v7->vfptr->GetSteamWebAPIKey(v7);
  OSuite::ZStringBuilder::Append(&v31, v8);
  OSuite::ZStringBuilder::Append(&v31, "&orderid=");
  OSuite::ZStringBuilder::AppendInt(&v31, v3);
  OSuite::ZStringBuilder::Append(&v31, "&appid=");
  v9 = OSuite::GameInterface();
  v10 = OSuite::ZGameInterface::GetAppID(v9);
  OSuite::ZStringBuilder::AppendInt(&v31, v10);
  result.m_pString = 0i64;
  OSuite::ZStringBuilder::ToString(&v31, &result);
  v11 = OSuite::TSingleton<OSuite::ZHttpManager>::Object()->m_httpRequestManager;
  OSuite::ZUrl::ZUrl(&v30, &result);
  OSuite::ZHttpRequestManager::CreateHttpRequest(v11, v12, 0i64, 0, 30);
  v2->m_httpRequest = v13;
  OSuite::ZUrl::~ZUrl(&v30);
  v14 = v2->m_httpRequest->vfptr;
  OSuite::ZString::ZString(&v29, "GET");
  v14[44].__vecDelDtor((OSuite::ZObject *)&v2->m_httpRequest->vfptr, v15);
  v2->m_httpRequest->vfptr[42].__vecDelDtor((OSuite::ZObject *)v2->m_httpRequest, 0);
  v16 = v2->m_httpRequest->vfptr;
  OSuite::ZString::ZString(&v29, "application/json");
  v16[36].__vecDelDtor((OSuite::ZObject *)&v2->m_httpRequest->vfptr, v17);
  v18 = Assembly::GetRCX(v2);
  v21 = 0i64;
  v27 = OSuitePrivate::ConsumablesManager::OnRequestFinished;
  v19 = v2->m_httpRequest;
  v20 = 0i64;
  v23 = 0i64;
  v22 = 0i64;
  v25 = 0i64;
  v24 = 0i64;
  v26 = v18;
  v28 = 1;
  v19->vfptr[6].__vecDelDtor((OSuite::ZObject *)&v19->vfptr, (unsigned int)&v20);
  OSuite::ZString::~ZString(&result);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v31);
}

// File Line: 806
// RVA: 0x132F9CC
__int64 __fastcall OSuitePrivate::ConsumablesManager::HandleQueryResponse(OSuitePrivate::ConsumablesManager *this, OSuite::IPlayerAccount *pPlayerAccount, OSuitePrivate::ZEidosTransaction *pTxn)
{
  OSuitePrivate::ConsumablesManager *v3; // rbx
  OSuitePrivate::ZEidosTransaction *v4; // r12
  OSuite::IPlayerAccount *v5; // r15
  unsigned int v6; // esi
  __int64 v7; // rax
  __int64 v8; // r14
  __int64 v9; // rax
  OSuite::IReader *v10; // rax
  OSuite::ZJsonObject *v11; // rbx
  OSuite::ZObjectVtbl *v12; // rdi
  OSuite::ZObjectVtbl *v13; // rdi
  OSuite::ZObjectVtbl *v14; // rbx
  OSuite::ZString *v15; // rax
  OSuite::ZString *v16; // rax
  OSuite::ZString *v17; // rdi
  bool v18; // bl
  OSuite::ZString sName; // [rsp+20h] [rbp-59h]
  OSuite::ZString v21; // [rsp+38h] [rbp-41h]
  OSuite::ZString v22; // [rsp+50h] [rbp-29h]
  OSuite::ZJsonDocument doc; // [rsp+68h] [rbp-11h]

  v3 = this;
  v4 = pTxn;
  v5 = pPlayerAccount;
  v6 = 6;
  v7 = ((__int64 (*)(void))this->m_httpRequest->vfptr[33].__vecDelDtor)();
  if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v7 + 32i64))(v7) == 200 )
  {
    v21.m_pString = 0i64;
    OSuite::ZString::ZString(&v21, &customWorldMapCaption);
    v22.m_pString = 0i64;
    OSuite::ZString::ZString(&v22, &customWorldMapCaption);
    v8 = -1i64;
    v9 = ((__int64 (*)(void))v3->m_httpRequest->vfptr[33].__vecDelDtor)();
    v10 = (OSuite::IReader *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 64i64))(v9);
    doc.m_Pairs.m_pLists = 0i64;
    OSuite::ZJsonDocument::ZJsonDocument(&doc, v10);
    v11 = OSuitePrivate::ConsumablesManager::GetResponseParams(v3, &doc);
    if ( v11 )
    {
      OSuite::ZString::ZString(&sName, "status");
      v12 = OSuite::ZJsonObject::Value(v11, &sName);
      OSuite::ZString::~ZString(&sName);
      if ( v12 )
        OSuite::ZString::operator=(&v21, (OSuite::ZString *)&v12[2]);
      OSuite::ZString::ZString(&sName, "orderid");
      v13 = OSuite::ZJsonObject::Value(v11, &sName);
      OSuite::ZString::~ZString(&sName);
      if ( v13 )
        v8 = OSuite::ZString::ToInt((OSuite::ZString *)&v13[2]);
      OSuite::ZString::ZString(&sName, "steamid");
      v14 = OSuite::ZJsonObject::Value(v11, &sName);
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
    v15 = v5->vfptr->GetUserId(v5, 0);
    OSuite::ZString::ZString(&sName, v15);
    v17 = v16;
    v18 = OSuite::ZString::operator==(&v22, v16) == 0;
    OSuite::ZString::~ZString(v17);
    if ( v18 )
      v6 = 7;
    if ( v8 != v4->vfptr->GetId((OSuite::IConsumableTransaction *)&v4->vfptr) )
      v6 = 7;
    OSuite::ZJsonDocument::~ZJsonDocument(&doc);
    OSuite::ZString::~ZString(&v22);
    OSuite::ZString::~ZString(&v21);
  }
  return v6;
}

// File Line: 878
// RVA: 0x1330090
void __fastcall OSuitePrivate::ConsumablesManager::SendFinalize(OSuitePrivate::ConsumablesManager *this, __int64 orderId)
{
  OSuitePrivate::ConsumablesManager *v2; // rsi
  __int64 v3; // rbx
  OSuite::ZGameInterface *v4; // rax
  const char *v5; // rax
  OSuite::ZOnlineSuite *v6; // rax
  OSuite::IGameConfig *v7; // rax
  const char *v8; // rax
  OSuite::ZGameInterface *v9; // rax
  unsigned int v10; // eax
  OSuite::ZString *v11; // rax
  OSuite::ZHttpRequestManager *v12; // rbx
  OSuite::ZUrl *v13; // rax
  OSuite::IHttpRequest *v14; // rax
  OSuite::ZObjectVtbl *v15; // rbx
  __int64 v16; // rax
  OSuite::ZObjectVtbl *v17; // rbx
  unsigned __int64 v18; // rax
  OSuite::ZObjectVtbl *v19; // rbx
  __int64 v20; // rax
  OSuite::ZObjectVtbl *v21; // rbx
  __int64 v22; // rax
  hkSeekableStreamReader *v23; // rbx
  hkSeekableStreamReader *v24; // rax
  OSuite::IHttpRequest *v25; // rcx
  OSuite::ZString result; // [rsp+30h] [rbp-D0h]
  __int64 v27; // [rsp+48h] [rbp-B8h]
  __int64 v28; // [rsp+50h] [rbp-B0h]
  __int64 v29; // [rsp+58h] [rbp-A8h]
  __int64 v30; // [rsp+60h] [rbp-A0h]
  hkSeekableStreamReader *v31; // [rsp+68h] [rbp-98h]
  bool (__fastcall *v32)(OSuitePrivate::ConsumablesManager *, OSuite::IHttpRequest *, unsigned __int64); // [rsp+70h] [rbp-90h]
  hkSeekableStreamReader *v33; // [rsp+78h] [rbp-88h]
  bool (__fastcall *v34)(OSuitePrivate::ConsumablesManager *, OSuite::IHttpRequest *, OSuite::ZHttp::EError); // [rsp+80h] [rbp-80h]
  char v35; // [rsp+88h] [rbp-78h]
  OSuite::ZUrl v36; // [rsp+90h] [rbp-70h]
  OSuite::ZStringBuilder v37; // [rsp+168h] [rbp+68h]
  OSuite::ZString sPath; // [rsp+198h] [rbp+98h]
  OSuite::ZStringBuilder v39; // [rsp+1B0h] [rbp+B0h]

  v2 = this;
  *(_WORD *)&this->m_bRequestInProgress = 257;
  v3 = orderId;
  v39.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v39, 0x100ui64);
  v4 = OSuite::GameInterface();
  v5 = OSuite::ZGameInterface::GetSteamShopURL(v4);
  OSuite::ZStringBuilder::Append(&v39, v5);
  OSuite::ZStringBuilder::Append(&v39, "FinalizeTxn/V0001/?key=");
  v6 = OSuite::ZOnlineSuite::Instance();
  v7 = OSuite::ZOnlineSuite::GetGameConfig(v6);
  v8 = v7->vfptr->GetSteamWebAPIKey(v7);
  OSuite::ZStringBuilder::Append(&v39, v8);
  v37.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v37, 0x100ui64);
  OSuite::ZStringBuilder::Append(&v37, "orderid=");
  OSuite::ZStringBuilder::AppendInt(&v37, v3);
  OSuite::ZStringBuilder::Append(&v37, "&appid=");
  v9 = OSuite::GameInterface();
  v10 = OSuite::ZGameInterface::GetAppID(v9);
  OSuite::ZStringBuilder::AppendInt(&v37, v10);
  v11 = OSuite::ZStringBuilder::ToString(&v37, &result);
  OSuite::ZString::operator=(&v2->m_finalizeData, v11);
  OSuite::ZString::~ZString(&result);
  sPath.m_pString = 0i64;
  OSuite::ZStringBuilder::ToString(&v39, &sPath);
  v12 = OSuite::TSingleton<OSuite::ZHttpManager>::Object()->m_httpRequestManager;
  OSuite::ZUrl::ZUrl(&v36, &sPath);
  OSuite::ZHttpRequestManager::CreateHttpRequest(v12, v13, 0i64, 0, 30);
  v2->m_httpRequest = v14;
  OSuite::ZUrl::~ZUrl(&v36);
  v15 = v2->m_httpRequest->vfptr;
  OSuite::ZString::ZString(&result, "POST");
  v15[44].__vecDelDtor((OSuite::ZObject *)&v2->m_httpRequest->vfptr, v16);
  v17 = v2->m_httpRequest->vfptr;
  v18 = OSuite::ZString::Count(&v2->m_finalizeData);
  v17[42].__vecDelDtor((OSuite::ZObject *)&v2->m_httpRequest->vfptr, v18);
  v19 = v2->m_httpRequest->vfptr;
  OSuite::ZString::ZString(&result, "application/json");
  v19[36].__vecDelDtor((OSuite::ZObject *)&v2->m_httpRequest->vfptr, v20);
  v21 = v2->m_httpRequest->vfptr;
  OSuite::ZString::ZString(&result, "application/x-www-form-urlencoded");
  v21[41].__vecDelDtor((OSuite::ZObject *)&v2->m_httpRequest->vfptr, v22);
  v23 = Assembly::GetRCX(v2);
  v24 = Assembly::GetRCX(v2);
  v28 = 0i64;
  v32 = OSuitePrivate::ConsumablesManager::OnFinalizeTxnDataNeeded;
  v25 = v2->m_httpRequest;
  v31 = v24;
  v27 = 0i64;
  v30 = 0i64;
  v29 = 0i64;
  v33 = v23;
  v35 = 1;
  v34 = OSuitePrivate::ConsumablesManager::OnRequestFinished;
  v25->vfptr[6].__vecDelDtor((OSuite::ZObject *)&v25->vfptr, (unsigned int)&v27);
  OSuite::ZString::~ZString(&sPath);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v37);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v39);
}

// File Line: 914
// RVA: 0x132F774
__int64 __fastcall OSuitePrivate::ConsumablesManager::HandleFinalizeResponse(OSuitePrivate::ConsumablesManager *this, __int64 orderId)
{
  OSuitePrivate::ConsumablesManager *v2; // rdi
  __int64 v3; // rbp
  unsigned int v4; // ebx
  __int64 v5; // rax
  __int64 v6; // rsi
  __int64 v7; // rax
  OSuite::IReader *v8; // rax
  OSuite::ZJsonObject *v9; // rdi
  OSuite::ZObjectVtbl *v10; // rdi
  OSuite::ZString sName; // [rsp+20h] [rbp-58h]
  OSuite::ZJsonDocument doc; // [rsp+38h] [rbp-40h]

  v2 = this;
  v3 = orderId;
  v4 = 7;
  v5 = ((__int64 (*)(void))this->m_httpRequest->vfptr[33].__vecDelDtor)();
  if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v5 + 32i64))(v5) == 200 )
  {
    v6 = -1i64;
    v7 = ((__int64 (*)(void))v2->m_httpRequest->vfptr[33].__vecDelDtor)();
    v8 = (OSuite::IReader *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 64i64))(v7);
    doc.m_Pairs.m_pLists = 0i64;
    OSuite::ZJsonDocument::ZJsonDocument(&doc, v8);
    v9 = OSuitePrivate::ConsumablesManager::GetResponseParams(v2, &doc);
    if ( v9 )
    {
      OSuite::ZString::ZString(&sName, "orderid");
      v10 = OSuite::ZJsonObject::Value(v9, &sName);
      OSuite::ZString::~ZString(&sName);
      if ( v10 )
        v6 = OSuite::ZString::ToInt((OSuite::ZString *)&v10[2]);
    }
    if ( v6 == v3 )
      v4 = 4;
    OSuite::ZJsonDocument::~ZJsonDocument(&doc);
  }
  return v4;
}

// File Line: 955
// RVA: 0x132FF8C
bool __fastcall OSuitePrivate::ConsumablesManager::OnRequestFinished(OSuitePrivate::ConsumablesManager *this, OSuite::IHttpRequest *__formal, OSuite::ZHttp::EError error)
{
  this->m_bRequestInProgress = 0;
  return error == 0;
}

// File Line: 962
// RVA: 0x132FF30
bool __fastcall OSuitePrivate::ConsumablesManager::OnFinalizeTxnDataNeeded(OSuitePrivate::ConsumablesManager *this, OSuite::IHttpRequest *request, unsigned __int64 __formal)
{
  OSuite::ZObjectVtbl *v3; // rsi
  OSuite::ZString *v4; // rbx
  OSuite::IHttpRequest *v5; // r14
  unsigned __int64 v6; // rdi
  char *v7; // rax

  v3 = request->vfptr;
  v4 = &this->m_finalizeData;
  v5 = request;
  v6 = OSuite::ZString::Count(&this->m_finalizeData);
  v7 = OSuite::ZString::c_str(v4);
  return ((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *, char *, unsigned __int64))v3[14].__vecDelDtor)(
           v5,
           v7,
           v6) != 0;
}

