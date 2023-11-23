// File Line: 25
// RVA: 0xA5B680
void __fastcall CAkBankCallbackMgr::CAkBankCallbackMgr(CAkBankCallbackMgr *this)
{
  CAkLock *p_m_csLock; // rcx

  p_m_csLock = &this->m_csLock;
  p_m_csLock[-1].m_csLock.LockSemaphore = 0i64;
  p_m_csLock[-1].m_csLock.SpinCount = 0i64;
  InitializeCriticalSection(&p_m_csLock->m_csLock);
  this->m_CallbackActiveEvent.m_Event = 0i64;
  this->m_CallbackActiveEvent.m_Event = CreateEventW(0i64, 1, 0, 0i64);
}

// File Line: 30
// RVA: 0xA5B6D0
void __fastcall CAkBankCallbackMgr::~CAkBankCallbackMgr(CAkBankCallbackMgr *this)
{
  MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *m_pItems; // rdx
  void *m_Event; // rcx

  m_pItems = this->m_ListCookies.m_pItems;
  if ( this->m_ListCookies.m_pItems )
  {
    this->m_ListCookies.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_ListCookies.m_pItems = 0i64;
    this->m_ListCookies.m_ulReserved = 0;
  }
  m_Event = this->m_CallbackActiveEvent.m_Event;
  if ( m_Event )
    CloseHandle(m_Event);
  DeleteCriticalSection(&this->m_csLock.m_csLock);
}

// File Line: 35
// RVA: 0xA5B720
__int64 __fastcall CAkBankCallbackMgr::AddCookie(CAkBankCallbackMgr *this, void *in_cookie)
{
  MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *m_pItems; // rax
  MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *v5; // r8
  MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *v6; // r9
  CAkBankCallbackMgr::BankCallbackItem *p_item; // r8
  unsigned int v8; // edi
  MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *v9; // rax

  EnterCriticalSection(&this->m_csLock.m_csLock);
  m_pItems = this->m_ListCookies.m_pItems;
  v5 = this->m_ListCookies.m_pItems;
  v6 = &this->m_ListCookies.m_pItems[this->m_ListCookies.m_uLength];
  if ( this->m_ListCookies.m_pItems != v6 )
  {
    do
    {
      if ( v5->key == in_cookie )
        break;
      ++v5;
    }
    while ( v5 != v6 );
  }
  if ( v5 == v6 || (p_item = &v5->item) == 0i64 )
  {
    if ( m_pItems != v6 )
    {
      do
      {
        if ( m_pItems->key == in_cookie )
          break;
        ++m_pItems;
      }
      while ( m_pItems != v6 );
      if ( m_pItems != v6 && m_pItems != (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)-8i64 )
        goto LABEL_14;
    }
    v9 = AkArray<MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem>,MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(&this->m_ListCookies);
    if ( !v9 || (v9->key = in_cookie, v9 == (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)-8i64) )
      v8 = 52;
    else
LABEL_14:
      v8 = 1;
  }
  else
  {
    ++p_item->m_cookieCount;
    v8 = 1;
  }
  LeaveCriticalSection(&this->m_csLock.m_csLock);
  return v8;
}

// File Line: 51
// RVA: 0xA5BA70
void __fastcall CAkBankCallbackMgr::RemoveOneCookie(CAkBankCallbackMgr *this, void *in_cookie)
{
  MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *m_pItems; // rdi
  MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *v5; // rax
  MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *v6; // rsi
  CAkBankCallbackMgr::BankCallbackItem *p_item; // rcx
  unsigned int v8; // edi

  EnterCriticalSection(&this->m_csLock.m_csLock);
  m_pItems = this->m_ListCookies.m_pItems;
  v5 = this->m_ListCookies.m_pItems;
  v6 = &this->m_ListCookies.m_pItems[this->m_ListCookies.m_uLength];
  if ( this->m_ListCookies.m_pItems != v6 )
  {
    do
    {
      if ( v5->key == in_cookie )
        break;
      ++v5;
    }
    while ( v5 != v6 );
  }
  if ( v5 != v6 )
  {
    p_item = &v5->item;
    if ( v5 != (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)-8i64 )
    {
      if ( p_item->m_cookieCount > 1 )
      {
        --p_item->m_cookieCount;
      }
      else if ( m_pItems != v6 )
      {
        do
        {
          if ( m_pItems->key == in_cookie )
            break;
          ++m_pItems;
        }
        while ( m_pItems != v6 );
        if ( m_pItems != v6 )
        {
          if ( m_pItems < &v6[-1] )
            qmemcpy(
              m_pItems,
              &m_pItems[1],
              8
            * (((((unsigned __int64)((char *)&v6[-1] - (char *)m_pItems - 1) >> 3) & 0xFFFFFFFFFFFFFFFEui64) + 2) & 0x1FFFFFFFFFFFFFFEi64));
          --this->m_ListCookies.m_uLength;
        }
      }
    }
  }
  LeaveCriticalSection(&this->m_csLock.m_csLock);
  v8 = CAkBankMgr::m_idThread;
  if ( v8 != GetCurrentThreadId() )
    WaitForSingleObject(this->m_CallbackActiveEvent.m_Event, 0xFFFFFFFF);
}

// File Line: 79
// RVA: 0xA5B850
void __fastcall CAkBankCallbackMgr::DoCallback(
        CAkBankCallbackMgr *this,
        void (__fastcall *in_pfnBankCallback)(unsigned int, const void *, AKRESULT, int, void *),
        unsigned int in_bankID,
        const void *in_pInMemoryPtr,
        AKRESULT in_eLoadResult,
        int in_memPoolId,
        void *in_pCookie)
{
  MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *m_pItems; // rdi
  MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *v11; // rax
  MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *v12; // rsi
  CAkBankCallbackMgr::BankCallbackItem *p_item; // rcx
  unsigned int m_toSkipCount; // edx
  bool v15; // r15

  if ( in_pfnBankCallback )
  {
    EnterCriticalSection(&this->m_csLock.m_csLock);
    m_pItems = this->m_ListCookies.m_pItems;
    v11 = this->m_ListCookies.m_pItems;
    v12 = &this->m_ListCookies.m_pItems[this->m_ListCookies.m_uLength];
    if ( this->m_ListCookies.m_pItems != v12 )
    {
      do
      {
        if ( v11->key == in_pCookie )
          break;
        ++v11;
      }
      while ( v11 != v12 );
    }
    if ( v11 == v12 || (p_item = &v11->item, v11 == (MapStruct<void *,CAkBankCallbackMgr::BankCallbackItem> *)-8i64) )
    {
      LeaveCriticalSection(&this->m_csLock.m_csLock);
    }
    else
    {
      m_toSkipCount = v11->item.m_toSkipCount;
      v15 = m_toSkipCount != 0;
      if ( p_item->m_cookieCount > 1 )
      {
        --p_item->m_cookieCount;
        if ( m_toSkipCount )
          v11->item.m_toSkipCount = m_toSkipCount - 1;
      }
      else if ( m_pItems != v12 )
      {
        do
        {
          if ( m_pItems->key == in_pCookie )
            break;
          ++m_pItems;
        }
        while ( m_pItems != v12 );
        if ( m_pItems != v12 )
        {
          if ( m_pItems < &v12[-1] )
            qmemcpy(
              m_pItems,
              &m_pItems[1],
              8
            * (((((unsigned __int64)((char *)&v12[-1] - (char *)m_pItems - 1) >> 3) & 0xFFFFFFFFFFFFFFFEui64) + 2) & 0x1FFFFFFFFFFFFFFEi64));
          --this->m_ListCookies.m_uLength;
        }
      }
      ResetEvent(this->m_CallbackActiveEvent.m_Event);
      LeaveCriticalSection(&this->m_csLock.m_csLock);
      if ( !v15 )
        in_pfnBankCallback(in_bankID, in_pInMemoryPtr, in_eLoadResult, in_memPoolId, in_pCookie);
      SetEvent(this->m_CallbackActiveEvent.m_Event);
    }
  }
}

