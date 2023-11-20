// File Line: 25
// RVA: 0xA5B680
void __fastcall CAkBankCallbackMgr::CAkBankCallbackMgr(CAkBankCallbackMgr *this)
{
  CAkBankCallbackMgr *v1; // rbx
  _RTL_CRITICAL_SECTION *v2; // rcx

  v1 = this;
  v2 = &this->m_csLock.m_csLock;
  v2[-1].LockSemaphore = 0i64;
  v2[-1].SpinCount = 0i64;
  InitializeCriticalSection(v2);
  v1->m_CallbackActiveEvent.m_Event = 0i64;
  v1->m_CallbackActiveEvent.m_Event = CreateEventW(0i64, 1, 0, 0i64);
}

// File Line: 30
// RVA: 0xA5B6D0
void __fastcall CAkBankCallbackMgr::~CAkBankCallbackMgr(CAkBankCallbackMgr *this)
{
  MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *v1; // rdx
  CAkBankCallbackMgr *v2; // rbx
  void *v3; // rcx

  v1 = this->m_ListCookies.m_pItems;
  v2 = this;
  if ( this->m_ListCookies.m_pItems )
  {
    this->m_ListCookies.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v1);
    v2->m_ListCookies.m_pItems = 0i64;
    v2->m_ListCookies.m_ulReserved = 0;
  }
  v3 = v2->m_CallbackActiveEvent.m_Event;
  if ( v3 )
    CloseHandle(v3);
  DeleteCriticalSection(&v2->m_csLock.m_csLock);
}

// File Line: 35
// RVA: 0xA5B720
__int64 __fastcall CAkBankCallbackMgr::AddCookie(CAkBankCallbackMgr *this, void *in_cookie)
{
  CAkBankCallbackMgr *v2; // rsi
  void *v3; // rdi
  MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *v4; // rax
  MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *v5; // r8
  signed __int64 v6; // r9
  CAkBankCallbackMgr::BankCallbackItem *v7; // r8
  unsigned int v8; // edi
  MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *v9; // rax

  v2 = this;
  v3 = in_cookie;
  EnterCriticalSection(&this->m_csLock.m_csLock);
  v4 = v2->m_ListCookies.m_pItems;
  v5 = v2->m_ListCookies.m_pItems;
  v6 = (signed __int64)&v2->m_ListCookies.m_pItems[v2->m_ListCookies.m_uLength];
  if ( v2->m_ListCookies.m_pItems != (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)v6 )
  {
    do
    {
      if ( v5->key == v3 )
        break;
      ++v5;
    }
    while ( v5 != (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)v6 );
  }
  if ( v5 != (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)v6 && (v7 = &v5->item) != 0i64 )
  {
    ++v7->m_cookieCount;
    v8 = 1;
  }
  else
  {
    if ( v4 != (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)v6 )
    {
      do
      {
        if ( v4->key == v3 )
          break;
        ++v4;
      }
      while ( v4 != (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)v6 );
      if ( v4 != (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)v6
        && v4 != (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)-8i64 )
      {
        goto LABEL_19;
      }
    }
    v9 = AkArray<MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem>,MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast((AkArray<MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem>,MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)&v2->m_ListCookies.m_pItems);
    if ( v9 && (v9->key = v3, v9 != (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)-8i64) )
LABEL_19:
      v8 = 1;
    else
      v8 = 52;
  }
  LeaveCriticalSection(&v2->m_csLock.m_csLock);
  return v8;
}

// File Line: 51
// RVA: 0xA5BA70
void __fastcall CAkBankCallbackMgr::RemoveOneCookie(CAkBankCallbackMgr *this, void *in_cookie)
{
  CAkBankCallbackMgr *v2; // r14
  void *v3; // rbx
  MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *v4; // rdi
  MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *v5; // rax
  signed __int64 v6; // rsi
  CAkBankCallbackMgr::BankCallbackItem *v7; // rcx
  unsigned int v8; // edi

  v2 = this;
  v3 = in_cookie;
  EnterCriticalSection(&this->m_csLock.m_csLock);
  v4 = v2->m_ListCookies.m_pItems;
  v5 = v2->m_ListCookies.m_pItems;
  v6 = (signed __int64)&v2->m_ListCookies.m_pItems[v2->m_ListCookies.m_uLength];
  if ( v2->m_ListCookies.m_pItems != (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)v6 )
  {
    do
    {
      if ( v5->key == v3 )
        break;
      ++v5;
    }
    while ( v5 != (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)v6 );
  }
  if ( v5 != (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)v6 )
  {
    v7 = &v5->item;
    if ( v5 != (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)-8i64 )
    {
      if ( v7->m_cookieCount > 1 )
      {
        --v7->m_cookieCount;
      }
      else if ( v4 != (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)v6 )
      {
        do
        {
          if ( v4->key == v3 )
            break;
          ++v4;
        }
        while ( v4 != (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)v6 );
        if ( v4 != (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)v6 )
        {
          if ( (unsigned __int64)v4 < v6 - 16 )
            qmemcpy(
              v4,
              &v4[1],
              8
            * (((((unsigned __int64)(v6 - 16 - (_QWORD)v4 - 1) >> 3) & 0xFFFFFFFFFFFFFFFEui64) + 2) & 0x1FFFFFFFFFFFFFFEi64));
          --v2->m_ListCookies.m_uLength;
        }
      }
    }
  }
  LeaveCriticalSection(&v2->m_csLock.m_csLock);
  v8 = CAkBankMgr::m_idThread;
  if ( v8 != GetCurrentThreadId() )
    WaitForSingleObject(v2->m_CallbackActiveEvent.m_Event, 0xFFFFFFFF);
}

// File Line: 79
// RVA: 0xA5B850
void __fastcall CAkBankCallbackMgr::DoCallback(CAkBankCallbackMgr *this, void (__fastcall *in_pfnBankCallback)(unsigned int, const void *, AKRESULT, int, void *), unsigned int in_bankID, const void *in_pInMemoryPtr, AKRESULT in_eLoadResult, int in_memPoolId, void *in_pCookie)
{
  CAkBankCallbackMgr *v7; // r14
  const void *v8; // r13
  void (__fastcall *v9)(unsigned int, const void *, AKRESULT, int, void *); // r12
  void **v10; // rdi
  MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *v11; // rax
  signed __int64 v12; // rsi
  CAkBankCallbackMgr::BankCallbackItem *v13; // rcx
  unsigned int v14; // edx
  bool v15; // r15
  unsigned int v16; // [rsp+70h] [rbp+18h]

  if ( in_pfnBankCallback )
  {
    v16 = in_bankID;
    v7 = this;
    v8 = in_pInMemoryPtr;
    v9 = in_pfnBankCallback;
    EnterCriticalSection(&this->m_csLock.m_csLock);
    v10 = &v7->m_ListCookies.m_pItems->key;
    v11 = v7->m_ListCookies.m_pItems;
    v12 = (signed __int64)&v7->m_ListCookies.m_pItems[v7->m_ListCookies.m_uLength];
    if ( v7->m_ListCookies.m_pItems != (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)v12 )
    {
      do
      {
        if ( v11->key == in_pCookie )
          break;
        ++v11;
      }
      while ( v11 != (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)v12 );
    }
    if ( v11 == (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)v12
      || (v13 = &v11->item, v11 == (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)-8i64) )
    {
      LeaveCriticalSection(&v7->m_csLock.m_csLock);
    }
    else
    {
      v14 = v11->item.m_toSkipCount;
      v15 = v14 != 0;
      if ( v13->m_cookieCount > 1 )
      {
        --v13->m_cookieCount;
        if ( v15 )
          v11->item.m_toSkipCount = v14 - 1;
      }
      else if ( v10 != (void **)v12 )
      {
        do
        {
          if ( *v10 == in_pCookie )
            break;
          v10 += 2;
        }
        while ( v10 != (void **)v12 );
        if ( v10 != (void **)v12 )
        {
          if ( (unsigned __int64)v10 < v12 - 16 )
            qmemcpy(
              v10,
              v10 + 2,
              8
            * (((((unsigned __int64)(v12 - 16 - (_QWORD)v10 - 1) >> 3) & 0xFFFFFFFFFFFFFFFEui64) + 2) & 0x1FFFFFFFFFFFFFFEi64));
          --v7->m_ListCookies.m_uLength;
        }
      }
      ResetEvent(v7->m_CallbackActiveEvent.m_Event);
      LeaveCriticalSection(&v7->m_csLock.m_csLock);
      if ( !v15 )
        v9(v16, v8, in_eLoadResult, in_memPoolId, in_pCookie);
      SetEvent(v7->m_CallbackActiveEvent.m_Event);
    }
  }
}

