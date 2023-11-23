// File Line: 189
// RVA: 0xA60970
void __fastcall CAkUsageSlot::Release(CAkUsageSlot *this, bool in_bSkipNotification)
{
  int v4; // et0
  char v5; // of
  char PoolAttributes; // al
  char *m_pData; // rdx
  int m_memPoolId; // ecx
  bool v9; // zf
  int v10; // edi

  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  v4 = _InterlockedAdd(&this->m_iRefCount, 0xFFFFFFFF);
  if ( (v4 < 0) ^ v5 | (v4 == 0) )
  {
    if ( this->m_pData )
    {
      PoolAttributes = AK::MemoryMgr::GetPoolAttributes(this->m_memPoolId);
      m_pData = this->m_pData;
      m_memPoolId = this->m_memPoolId;
      if ( (PoolAttributes & 8) != 0 )
        AK::MemoryMgr::ReleaseBlock(m_memPoolId, m_pData);
      else
        AK::MemoryMgr::Free(m_memPoolId, m_pData);
      v9 = !this->m_bIsInternalPool;
      this->m_pData = 0i64;
      if ( !v9 )
      {
        AK::MemoryMgr::DestroyPool(this->m_memPoolId);
        this->m_memPoolId = -1;
      }
    }
    CAkBankMgr::UnloadMedia(g_pBankManager, this);
    if ( this->m_iPrepareRefCount > 0 )
    {
      LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
      if ( !in_bSkipNotification )
        CAkUsageSlot::UnloadCompletionNotification(this);
    }
    else
    {
      LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
      if ( !in_bSkipNotification )
        CAkUsageSlot::UnloadCompletionNotification(this);
      v10 = g_DefaultPoolId;
      if ( (*((_BYTE *)this + 112) & 2) != 0 )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, this->m_paLoadedMedia);
        *((_BYTE *)this + 112) &= ~2u;
      }
      this->m_paLoadedMedia = 0i64;
      AK::MemoryMgr::Free(v10, this);
    }
  }
  else
  {
    LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  }
}

// File Line: 230
// RVA: 0xA60BC0
void __fastcall CAkUsageSlot::ReleasePrepare(CAkUsageSlot *this, bool in_bIsFinal)
{
  int v4; // ebx
  unsigned __int64 v5; // [rsp+20h] [rbp-28h]
  AkBankKey v6; // [rsp+30h] [rbp-18h] BYREF

  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  if ( in_bIsFinal )
  {
    this->m_iPrepareRefCount = 0;
  }
  else if ( _InterlockedAdd(&this->m_iPrepareRefCount, 0xFFFFFFFF) > 0 )
  {
LABEL_8:
    LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
    return;
  }
  CAkBankMgr::UnPrepareMedia(g_pBankManager, this);
  if ( this->m_iRefCount > 0 )
    goto LABEL_8;
  LODWORD(v5) = this->m_BankID;
  v6 = (AkBankKey)v5;
  CAkBankList::Remove(&g_pBankManager->m_BankList, &v6);
  LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  CAkUsageSlot::RemoveContent(this);
  CAkUsageSlot::Unload(this);
  v4 = g_DefaultPoolId;
  if ( (*((_BYTE *)this + 112) & 2) != 0 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_paLoadedMedia);
    *((_BYTE *)this + 112) &= ~2u;
  }
  this->m_paLoadedMedia = 0i64;
  AK::MemoryMgr::Free(v4, this);
}

// File Line: 268
// RVA: 0xA60F60
void __fastcall CAkUsageSlot::RemoveContent(CAkUsageSlot *this)
{
  CAkIndexable **m_pItems; // rbx
  char v3; // di

  m_pItems = this->m_listLoadedItem.m_pItems;
  if ( m_pItems != &m_pItems[this->m_listLoadedItem.m_uLength] )
  {
    do
    {
      v3 = 1;
      EnterCriticalSection(&g_csMain.m_csLock);
      for ( ; m_pItems != &this->m_listLoadedItem.m_pItems[this->m_listLoadedItem.m_uLength]; ++v3 )
      {
        if ( !v3 )
          break;
        (*m_pItems)->vfptr->Release(*m_pItems);
        ++m_pItems;
      }
      LeaveCriticalSection(&g_csMain.m_csLock);
    }
    while ( m_pItems != &this->m_listLoadedItem.m_pItems[this->m_listLoadedItem.m_uLength] );
  }
  if ( this->m_listLoadedItem.m_pItems )
  {
    this->m_listLoadedItem.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_listLoadedItem.m_pItems);
    this->m_listLoadedItem.m_pItems = 0i64;
    this->m_listLoadedItem.m_ulReserved = 0;
  }
}

// File Line: 290
// RVA: 0xA61780
void __fastcall CAkUsageSlot::Unload(CAkUsageSlot *this)
{
  char PoolAttributes; // al
  char *m_pData; // rdx
  int m_memPoolId; // ecx
  bool v5; // zf

  if ( this->m_pData )
  {
    PoolAttributes = AK::MemoryMgr::GetPoolAttributes(this->m_memPoolId);
    m_pData = this->m_pData;
    m_memPoolId = this->m_memPoolId;
    if ( (PoolAttributes & 8) != 0 )
      AK::MemoryMgr::ReleaseBlock(m_memPoolId, m_pData);
    else
      AK::MemoryMgr::Free(m_memPoolId, m_pData);
    v5 = !this->m_bIsInternalPool;
    this->m_pData = 0i64;
    if ( !v5 )
    {
      AK::MemoryMgr::DestroyPool(this->m_memPoolId);
      this->m_memPoolId = -1;
    }
  }
}

// File Line: 310
// RVA: 0xA61AB0
void __fastcall CAkUsageSlot::UnloadCompletionNotification(CAkUsageSlot *this)
{
  void (__fastcall *m_pfnBankCallback)(unsigned int, const void *, AKRESULT, int, void *); // rdx

  m_pfnBankCallback = this->m_pfnBankCallback;
  if ( m_pfnBankCallback )
  {
    CAkBankCallbackMgr::DoCallback(
      &g_pBankManager->m_CallbackMgr,
      m_pfnBankCallback,
      this->m_BankID,
      this->key.pInMemoryPtr,
      AK_Success,
      this->m_memPoolId,
      this->m_pCookie);
    this->m_pfnBankCallback = 0i64;
  }
}

// File Line: 336
// RVA: 0xA5C840
void __fastcall CAkBankMgr::CAkBankMgr(CAkBankMgr *this)
{
  CAkBankReader::CAkBankReader(&this->m_BankReader);
  this->m_bStopThread = 0;
  InitializeCriticalSection(&this->m_queueLock.m_csLock);
  InitializeCriticalSection(&this->m_MediaLock.m_csLock);
  *(_QWORD *)&this->m_BankQueue.m_ulMinNumListItems = 0i64;
  this->m_BankQueue.m_ulNumListItems = 0;
  this->m_bIsFirstBusLoaded = 0;
  this->m_MediaHashTable.m_MemPoolId = -1;
  this->m_MediaHashTable.m_uiSize = 0;
  this->m_BankList.m_ListLoadedBanks.m_uiSize = 0;
  this->m_BankIDToFileName.m_MemPoolId = -1;
  this->m_BankIDToFileName.m_uiSize = 0;
  this->m_bFeedbackInBank = 0;
  CAkBankCallbackMgr::CAkBankCallbackMgr(&this->m_CallbackMgr);
  this->m_PreparationAccumulator.m_pItems = 0i64;
  *(_QWORD *)&this->m_PreparationAccumulator.m_uLength = 0i64;
  this->m_bAccumulating = 0;
  this->m_eventQueue = 0i64;
  CAkBankMgr::m_BankMgrThread = 0i64;
}

// File Line: 342
// RVA: 0xA5C8F0
void __fastcall CAkBankMgr::~CAkBankMgr(CAkBankMgr *this)
{
  CAkBankCallbackMgr::~CAkBankCallbackMgr(&this->m_CallbackMgr);
  DeleteCriticalSection(&this->m_MediaLock.m_csLock);
  DeleteCriticalSection(&this->m_queueLock.m_csLock);
  _((AMD_HD3D *)this);
}

// File Line: 346
// RVA: 0xA5D8A0
__int64 __fastcall CAkBankMgr::Init(CAkBankMgr *this)
{
  __int64 result; // rax
  AkHashList<unsigned long,AkMediaEntry,193>::Item **m_table; // rax
  __int64 v4; // rcx
  __int64 v5; // rcx
  AkHashList<unsigned long,char *,31>::Item **v6; // rax
  CAkList2<CAkBankMgr::AkBankQueueItem,CAkBankMgr::AkBankQueueItem const &,1,ArrayPoolDefault>::ListItem *v7; // rax
  CAkList2<CAkBankMgr::AkBankQueueItem,CAkBankMgr::AkBankQueueItem const &,1,ArrayPoolDefault>::ListItem *v8; // rcx
  unsigned int v9; // edx
  CAkList2<CAkBankMgr::AkBankQueueItem,CAkBankMgr::AkBankQueueItem const &,1,ArrayPoolDefault>::ListItem *v10; // rax

  CAkBankList::Init(&this->m_BankList);
  result = CAkBankReader::Init(&this->m_BankReader);
  if ( (_DWORD)result == 1 )
  {
    this->m_MediaHashTable.m_MemPoolId = g_DefaultPoolId;
    m_table = this->m_MediaHashTable.m_table;
    this->m_MediaHashTable.m_uiSize = 0;
    v4 = 24i64;
    do
    {
      *m_table = 0i64;
      m_table[1] = 0i64;
      m_table[2] = 0i64;
      m_table += 8;
      *(m_table - 5) = 0i64;
      *(m_table - 4) = 0i64;
      *(m_table - 3) = 0i64;
      *(m_table - 2) = 0i64;
      *(m_table - 1) = 0i64;
      --v4;
    }
    while ( v4 );
    *m_table = 0i64;
    v5 = 3i64;
    this->m_BankIDToFileName.m_MemPoolId = g_DefaultPoolId;
    v6 = this->m_BankIDToFileName.m_table;
    this->m_BankIDToFileName.m_uiSize = 0;
    do
    {
      *v6 = 0i64;
      v6[1] = 0i64;
      v6[2] = 0i64;
      v6 += 8;
      *(v6 - 5) = 0i64;
      *(v6 - 4) = 0i64;
      *(v6 - 3) = 0i64;
      *(v6 - 2) = 0i64;
      *(v6 - 1) = 0i64;
      --v5;
    }
    while ( v5 );
    *v6 = 0i64;
    v6[1] = 0i64;
    v6[2] = 0i64;
    v6[3] = 0i64;
    v6[4] = 0i64;
    v6[5] = 0i64;
    v6[6] = 0i64;
    this->m_BankQueue.m_ulNumListItems = 0;
    this->m_BankQueue.m_ulMaxNumListItems = -1;
    this->m_BankQueue.m_pFree = 0i64;
    v7 = (CAkList2<CAkBankMgr::AkBankQueueItem,CAkBankMgr::AkBankQueueItem const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x280ui64);
    v8 = v7;
    this->m_BankQueue.m_pvMemStart = v7;
    if ( v7 )
    {
      this->m_BankQueue.m_ulMinNumListItems = 10;
      this->m_BankQueue.m_pFree = v7;
      v9 = 0;
      do
      {
        v10 = v8 + 1;
        ++v9;
        v8->pNextListItem = v8 + 1;
        ++v8;
      }
      while ( v9 < this->m_BankQueue.m_ulMinNumListItems );
      v10[-1].pNextListItem = 0i64;
      result = 1i64;
    }
    else
    {
      result = 52i64;
    }
    this->m_BankQueue.m_pFirst = 0i64;
    this->m_BankQueue.m_pLast = 0i64;
    if ( (_DWORD)result == 1 )
      return CAkBankMgr::StartThread(this);
  }
  return result;
}

// File Line: 366
// RVA: 0xA61280
__int64 __fastcall CAkBankMgr::Term(CAkBankMgr *this)
{
  CAkList2<CAkBankMgr::AkBankQueueItem,CAkBankMgr::AkBankQueueItem const &,1,ArrayPoolDefault>::ListItem *m_pFirst; // rdx
  __int64 v3; // rsi
  unsigned int *pEventID; // rdi
  CAkList2<CAkBankMgr::AkBankQueueItem,CAkBankMgr::AkBankQueueItem const &,1,ArrayPoolDefault>::ListItem *m_pvMemStart; // rcx
  AkSrcTypeInfo *m_pItems; // rdx

  while ( this->m_BankQueue.m_ulNumListItems )
  {
    m_pFirst = this->m_BankQueue.m_pFirst;
    v3 = *(_QWORD *)&m_pFirst->Item.eType;
    pEventID = m_pFirst->Item.prepare.pEventID;
    if ( m_pFirst )
    {
      this->m_BankQueue.m_pFirst = m_pFirst->pNextListItem;
      if ( m_pFirst == this->m_BankQueue.m_pLast )
        this->m_BankQueue.m_pLast = 0i64;
      m_pvMemStart = this->m_BankQueue.m_pvMemStart;
      if ( m_pFirst < m_pvMemStart || m_pFirst >= &m_pvMemStart[(unsigned __int64)this->m_BankQueue.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, m_pFirst);
      }
      else
      {
        m_pFirst->pNextListItem = this->m_BankQueue.m_pFree;
        this->m_BankQueue.m_pFree = m_pFirst;
      }
      --this->m_BankQueue.m_ulNumListItems;
    }
    if ( (((_DWORD)v3 - 9) & 0xFFFFFFFD) == 0 && pEventID )
      AK::MemoryMgr::Free(g_DefaultPoolId, pEventID);
  }
  CAkList2<CAkBankMgr::AkBankQueueItem,CAkBankMgr::AkBankQueueItem const &,1,ArrayPoolDefault>::Term(&this->m_BankQueue);
  CAkBankMgr::UnloadAll(this);
  _((AMD_HD3D *)&this->m_BankList);
  if ( this->m_MediaHashTable.m_MemPoolId != -1 )
  {
    AkHashList<unsigned long,AkMediaEntry,193>::RemoveAll(&this->m_MediaHashTable);
    this->m_MediaHashTable.m_MemPoolId = -1;
  }
  CAkBankMgr::FlushFileNameTable(this);
  CAkBankReader::Term(&this->m_BankReader);
  m_pItems = this->m_PreparationAccumulator.m_pItems;
  if ( m_pItems )
  {
    this->m_PreparationAccumulator.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_PreparationAccumulator.m_pItems = 0i64;
    this->m_PreparationAccumulator.m_ulReserved = 0;
  }
  return 1i64;
}

// File Line: 403
// RVA: 0xA5D530
void __fastcall CAkBankMgr::FlushFileNameTable(CAkBankMgr *this)
{
  AkHashList<unsigned long,char *,31> *p_m_BankIDToFileName; // rsi
  AkHashList<unsigned long,char *,31>::Item *v2; // rdi
  __int64 v3; // rbx

  p_m_BankIDToFileName = &this->m_BankIDToFileName;
  if ( this->m_BankIDToFileName.m_MemPoolId != -1 )
  {
    v2 = this->m_BankIDToFileName.m_table[0];
    LODWORD(v3) = 0;
    if ( v2 )
    {
      do
      {
LABEL_7:
        AK::MemoryMgr::Free(g_DefaultPoolId, v2->Assoc.item);
        v2 = v2->pNextItem;
      }
      while ( v2 );
      while ( 1 )
      {
        v3 = (unsigned int)(v3 + 1);
        if ( (unsigned int)v3 >= 0x1F )
          break;
        v2 = p_m_BankIDToFileName->m_table[v3];
        if ( v2 )
          goto LABEL_7;
      }
    }
    else
    {
      while ( 1 )
      {
        v3 = (unsigned int)(v3 + 1);
        if ( (unsigned int)v3 >= 0x1F )
          break;
        v2 = p_m_BankIDToFileName->m_table[v3];
        if ( v2 )
          goto LABEL_7;
      }
    }
    if ( p_m_BankIDToFileName->m_MemPoolId != -1 )
    {
      AkHashList<unsigned long,char *,31>::RemoveAll(p_m_BankIDToFileName);
      p_m_BankIDToFileName->m_MemPoolId = -1;
    }
  }
}

// File Line: 418
// RVA: 0xA61070
signed __int64 __fastcall CAkBankMgr::StartThread(CAkBankMgr *this)
{
  HANDLE EventW; // rax
  unsigned int ThreadId; // [rsp+48h] [rbp+10h] BYREF

  if ( CAkBankMgr::m_BankMgrThread )
    return 2i64;
  this->m_bStopThread = 0;
  EventW = CreateEventW(0i64, 0, 0, 0i64);
  this->m_eventQueue = EventW;
  if ( !EventW )
    return 2i64;
  CAkBankMgr::m_BankMgrThread = CreateThread(
                                  0i64,
                                  g_PDSettings.threadBankManager.uStackSize,
                                  (LPTHREAD_START_ROUTINE)CAkBankMgr::BankThreadFunc,
                                  this,
                                  0,
                                  &ThreadId);
  if ( !CAkBankMgr::m_BankMgrThread )
    goto LABEL_7;
  AKPLATFORM::AkSetThreadName(ThreadId, "AK::BankManager");
  if ( !SetThreadPriority(CAkBankMgr::m_BankMgrThread, g_PDSettings.threadBankManager.nPriority)
    || g_PDSettings.threadBankManager.dwAffinityMask
    && !SetThreadAffinityMask(CAkBankMgr::m_BankMgrThread, g_PDSettings.threadBankManager.dwAffinityMask) )
  {
    CloseHandle(CAkBankMgr::m_BankMgrThread);
LABEL_7:
    CAkBankMgr::m_BankMgrThread = 0i64;
    return 2i64;
  }
  if ( CAkBankMgr::m_BankMgrThread )
    return 1i64;
  else
    return 2i64;
}

// File Line: 448
// RVA: 0xA61180
void __fastcall CAkBankMgr::StopThread(CAkBankMgr *this)
{
  void *m_eventQueue; // rcx

  this->m_bStopThread = 1;
  if ( CAkBankMgr::m_BankMgrThread )
  {
    SetEvent(this->m_eventQueue);
    WaitForSingleObject(CAkBankMgr::m_BankMgrThread, 0xFFFFFFFF);
    CloseHandle(CAkBankMgr::m_BankMgrThread);
    CAkBankMgr::m_BankMgrThread = 0i64;
  }
  m_eventQueue = this->m_eventQueue;
  if ( m_eventQueue )
    CloseHandle(m_eventQueue);
  this->m_eventQueue = 0i64;
}

// File Line: 463
// RVA: 0xA5CB10
__int64 __fastcall CAkBankMgr::BankThreadFunc(CAkBankMgr *lpParameter)
{
  CAkBankMgr::m_idThread = GetCurrentThreadId();
  WaitForSingleObject(lpParameter->m_eventQueue, 0xFFFFFFFF);
  while ( !lpParameter->m_bStopThread )
  {
    CAkBankMgr::ExecuteCommand(lpParameter);
    WaitForSingleObject(lpParameter->m_eventQueue, 0xFFFFFFFF);
  }
  return 0i64;
}

// File Line: 482
// RVA: 0xA60340
__int64 __fastcall CAkBankMgr::QueueBankCommand(CAkBankMgr *this, CAkBankMgr::AkBankQueueItem *in_Item)
{
  unsigned int v4; // edi

  EnterCriticalSection(&this->m_queueLock.m_csLock);
  if ( !in_Item->callbackInfo.pfnBankCallback
    || (v4 = CAkBankCallbackMgr::AddCookie(&this->m_CallbackMgr, in_Item->callbackInfo.pCookie), v4 == 1) )
  {
    v4 = 2
       - (CAkList2<CAkBankMgr::AkBankQueueItem,CAkBankMgr::AkBankQueueItem const &,1,ArrayPoolDefault>::AddLast(
            &this->m_BankQueue,
            in_Item) != 0i64);
    if ( in_Item->callbackInfo.pfnBankCallback )
    {
      if ( v4 == 1 )
      {
LABEL_7:
        SetEvent(this->m_eventQueue);
        goto LABEL_8;
      }
      CAkBankCallbackMgr::RemoveOneCookie(&this->m_CallbackMgr, in_Item->callbackInfo.pCookie);
    }
    if ( v4 == 1 )
      goto LABEL_7;
  }
LABEL_8:
  LeaveCriticalSection(&this->m_queueLock.m_csLock);
  return v4;
}

// File Line: 550
// RVA: 0xA5D070
__int64 __fastcall CAkBankMgr::ExecuteCommand(CAkBankMgr *this)
{
  AKRESULT v2; // edi
  CAkList2<CAkBankMgr::AkBankQueueItem,CAkBankMgr::AkBankQueueItem const &,1,ArrayPoolDefault>::ListItem *m_pFirst; // rdx
  __int64 v4; // rsi
  void (__fastcall *pfnBankCallback)(unsigned int, const void *, AKRESULT, int, void *); // r13
  __int64 v6; // r15
  unsigned int *pEventID; // r12
  __int64 v8; // rax
  unsigned int *pGameSyncID; // rax
  CAkList2<CAkBankMgr::AkBankQueueItem,CAkBankMgr::AkBankQueueItem const &,1,ArrayPoolDefault>::ListItem *m_pvMemStart; // rcx
  unsigned int v11; // r8d
  unsigned int *v12; // r9
  CAkBankCallbackMgr *p_m_CallbackMgr; // rcx
  AKRESULT in_eLoadResult; // eax
  unsigned int *v16; // r9
  CAkUsageSlot *v17; // rax
  int m_iWasPreparedAsABankCounter; // ecx
  void *in_pCookie; // [rsp+30h] [rbp-D0h]
  CAkBankMgr::AkBankQueueItem in_rItem; // [rsp+40h] [rbp-C0h] BYREF
  unsigned __int64 v21; // [rsp+80h] [rbp-80h]
  __int64 v22; // [rsp+88h] [rbp-78h]
  unsigned __int128 v23; // [rsp+90h] [rbp-70h] BYREF
  CAkBankMgr::AkBankQueueItem v24; // [rsp+A0h] [rbp-60h] BYREF
  CAkBankMgr::AkBankQueueItem v25; // [rsp+E0h] [rbp-20h] BYREF
  CAkBankMgr::AkBankQueueItem v26; // [rsp+120h] [rbp+20h] BYREF
  CAkBankMgr::AkBankQueueItem v27; // [rsp+160h] [rbp+60h] BYREF
  CAkBankMgr::AkBankQueueItem v28; // [rsp+1A0h] [rbp+A0h] BYREF
  CAkBankMgr::AkBankQueueItem v29; // [rsp+1E0h] [rbp+E0h] BYREF
  CAkBankMgr::AkBankQueueItem v30; // [rsp+220h] [rbp+120h] BYREF
  int v31; // [rsp+2A0h] [rbp+1A0h]
  void *pCookie; // [rsp+2A8h] [rbp+1A8h]

  v2 = AK_Success;
  EnterCriticalSection(&this->m_queueLock.m_csLock);
  while ( this->m_BankQueue.m_ulNumListItems )
  {
    m_pFirst = this->m_BankQueue.m_pFirst;
    v4 = *(_QWORD *)&m_pFirst->Item.eType;
    pfnBankCallback = m_pFirst->Item.callbackInfo.pfnBankCallback;
    v6 = *(_QWORD *)&m_pFirst->Item.prepare.numEvents;
    pEventID = m_pFirst->Item.prepare.pEventID;
    pCookie = m_pFirst->Item.callbackInfo.pCookie;
    in_rItem.callbackInfo.pCookie = pCookie;
    v8 = *(_QWORD *)&m_pFirst->Item.bankLoadFlag;
    *(_QWORD *)&in_rItem.eType = v4;
    v31 = v8;
    *(_QWORD *)&in_rItem.bankLoadFlag = v8;
    pGameSyncID = m_pFirst->Item.gameSync.pGameSyncID;
    in_rItem.callbackInfo.pfnBankCallback = pfnBankCallback;
    *(_QWORD *)&in_rItem.prepare.numEvents = v6;
    in_rItem.prepare.pEventID = pEventID;
    in_rItem.gameSync.pGameSyncID = pGameSyncID;
    if ( m_pFirst )
    {
      this->m_BankQueue.m_pFirst = m_pFirst->pNextListItem;
      if ( m_pFirst == this->m_BankQueue.m_pLast )
        this->m_BankQueue.m_pLast = 0i64;
      m_pvMemStart = this->m_BankQueue.m_pvMemStart;
      if ( m_pFirst < m_pvMemStart || m_pFirst >= &m_pvMemStart[(unsigned __int64)this->m_BankQueue.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, m_pFirst);
      }
      else
      {
        m_pFirst->pNextListItem = this->m_BankQueue.m_pFree;
        this->m_BankQueue.m_pFree = m_pFirst;
      }
      --this->m_BankQueue.m_ulNumListItems;
    }
    LeaveCriticalSection(&this->m_queueLock.m_csLock);
    switch ( (int)v4 )
    {
      case 0:
        v2 = (unsigned int)CAkBankMgr::LoadBankPre(this, &in_rItem);
        break;
      case 1:
        v29 = in_rItem;
        v2 = CAkBankMgr::UnloadBankPre(this, &v29);
        break;
      case 2:
        v24 = in_rItem;
        v2 = CAkBankMgr::PrepareEvents(this, &v24);
        break;
      case 3:
        v27 = in_rItem;
        v2 = CAkBankMgr::UnprepareEvents(this, &v27);
        break;
      case 4:
        v25 = in_rItem;
        v2 = CAkBankMgr::PrepareGameSync(this, &v25);
        break;
      case 5:
        CAkBankMgr::ClearPreparedEvents(this);
        v11 = 0;
        in_pCookie = pCookie;
        if ( (_DWORD)v6 == 1 )
          v11 = (unsigned int)pEventID;
        v12 = 0i64;
        p_m_CallbackMgr = &this->m_CallbackMgr;
        if ( v31 == 1 )
          v12 = pEventID;
        goto LABEL_20;
      case 6:
        v28 = in_rItem;
        in_eLoadResult = (unsigned int)CAkBankMgr::PrepareBankInternal(
                                         this,
                                         &v28,
                                         v6,
                                         (CAkBankMgr::AkLoadBankDataMode)((_mm_cvtsi128_si32(
                                                                             _mm_srli_si128(
                                                                               (__m128i)in_rItem.prepare,
                                                                               4)) != 1)
                                                                        + 1),
                                         1);
        v16 = 0i64;
        v2 = in_eLoadResult;
        if ( v31 == 1 )
          v16 = pEventID;
        CAkBankCallbackMgr::DoCallback(&this->m_CallbackMgr, pfnBankCallback, v6, v16, in_eLoadResult, -1, pCookie);
        break;
      case 7:
        LODWORD(v21) = v6;
        v22 = 0i64;
        v23 = v21;
        v17 = CAkBankList::Get(&this->m_BankList, (AkBankKey *)&v23);
        if ( v17 )
        {
          m_iWasPreparedAsABankCounter = v17->m_iWasPreparedAsABankCounter;
          if ( m_iWasPreparedAsABankCounter )
            v17->m_iWasPreparedAsABankCounter = m_iWasPreparedAsABankCounter - 1;
          CAkUsageSlot::ReleasePrepare(v17, 0);
        }
        v12 = 0i64;
        in_pCookie = pCookie;
        p_m_CallbackMgr = &this->m_CallbackMgr;
        if ( v31 == 1 )
          v12 = pEventID;
        v11 = v6;
LABEL_20:
        CAkBankCallbackMgr::DoCallback(p_m_CallbackMgr, pfnBankCallback, v11, v12, AK_Success, -1, in_pCookie);
        goto $LN2_117;
      case 8:
        v26 = in_rItem;
        v2 = (unsigned int)CAkBankMgr::ClearBanksInternal(this, &v26);
        break;
      case 9:
      case 11:
$LN2_117:
        v2 = AK_Success;
        break;
      case 10:
        v30 = in_rItem;
        v2 = CAkBankMgr::UnloadMediaFile(this, &v30);
        break;
      default:
        break;
    }
    EnterCriticalSection(&this->m_queueLock.m_csLock);
  }
  LeaveCriticalSection(&this->m_queueLock.m_csLock);
  return (unsigned int)v2;
}

// File Line: 623
// RVA: 0xA5E8A0
void __fastcall CAkBankMgr::NotifyCompletion(
        CAkBankMgr *this,
        CAkBankMgr::AkBankQueueItem *in_rItem,
        AKRESULT in_OperationResult)
{
  CAkBankMgr::AkBankQueueItemType eType; // eax
  unsigned int *pEventID; // r9
  int in_memPoolId; // r10d
  unsigned int numEvents; // r8d

  eType = in_rItem->eType;
  pEventID = 0i64;
  in_memPoolId = -1;
  numEvents = 0;
  if ( in_rItem->eType >= QueueItemLoad )
  {
    if ( eType <= QueueItemUnload )
    {
      in_memPoolId = in_rItem->load.memPoolId;
      numEvents = in_rItem->prepare.numEvents;
      goto LABEL_9;
    }
    if ( eType == QueueItemSupportedGameSync )
      goto LABEL_9;
    if ( (unsigned int)(eType - 6) <= 1 )
    {
      numEvents = in_rItem->prepare.numEvents;
      goto LABEL_9;
    }
  }
  if ( in_rItem->prepare.numEvents == 1 )
    numEvents = in_rItem->prepare.eventID;
LABEL_9:
  if ( in_rItem->bankLoadFlag == AkBankLoadFlag_InMemory )
    pEventID = in_rItem->prepare.pEventID;
  CAkBankCallbackMgr::DoCallback(
    &this->m_CallbackMgr,
    in_rItem->callbackInfo.pfnBankCallback,
    numEvents,
    pEventID,
    in_OperationResult,
    in_memPoolId,
    in_rItem->callbackInfo.pCookie);
}

// File Line: 687
// RVA: 0xA5E630
__int64 __fastcall CAkBankMgr::LoadSoundFromFile(CAkBankMgr *this, AkSrcTypeInfo *in_rMediaInfo, char *io_pData)
{
  unsigned int uFileOffset; // r8d
  unsigned int dwID_high; // r9d
  unsigned int uFileID; // r10d
  AkHashList<unsigned long,char *,31>::Item *v9; // rax
  unsigned int v10; // eax
  unsigned int v11; // ebx
  unsigned int in_bIsLanguageSpecific; // [rsp+28h] [rbp-10h]
  unsigned int out_rulSizeRead; // [rsp+40h] [rbp+8h] BYREF

  CAkBankReader::Reset(&this->m_BankReader);
  uFileOffset = in_rMediaInfo->mediaInfo.uFileOffset;
  dwID_high = HIWORD(in_rMediaInfo->dwID);
  uFileID = in_rMediaInfo->mediaInfo.uFileID;
  if ( uFileOffset || !HIWORD(in_rMediaInfo->dwID) )
  {
    v9 = this->m_BankIDToFileName.m_table[uFileID % 0x1F];
    if ( v9 )
    {
      while ( v9->Assoc.key != uFileID )
      {
        v9 = v9->pNextItem;
        if ( !v9 )
          goto LABEL_7;
      }
      if ( v9 != (AkHashList<unsigned long,char *,31>::Item *)-16i64 )
      {
        v10 = CAkBankReader::SetFile(&this->m_BankReader, v9->Assoc.item, uFileOffset, 0i64);
        goto LABEL_9;
      }
    }
LABEL_7:
    LOBYTE(in_bIsLanguageSpecific) = 1;
    dwID_high = 0;
  }
  else
  {
    LOBYTE(in_bIsLanguageSpecific) = *((_BYTE *)&in_rMediaInfo->mediaInfo + 16) & 1;
  }
  v10 = CAkBankReader::SetFile(&this->m_BankReader, uFileID, uFileOffset, dwID_high, 0i64, in_bIsLanguageSpecific);
LABEL_9:
  v11 = v10;
  out_rulSizeRead = 0;
  if ( v10 == 1 )
  {
    v11 = CAkBankReader::FillData(
            &this->m_BankReader,
            io_pData,
            in_rMediaInfo->mediaInfo.uInMemoryMediaSize,
            &out_rulSizeRead);
    if ( v11 == 1 && in_rMediaInfo->mediaInfo.uInMemoryMediaSize != out_rulSizeRead )
      v11 = 2;
  }
  CAkBankReader::CloseFile(&this->m_BankReader);
  return v11;
}

// File Line: 710
// RVA: 0xA5DC10
signed __int64 __fastcall CAkBankMgr::LoadBank(
        CAkBankMgr *this,
        CAkBankMgr::AkBankQueueItem *in_Item,
        CAkUsageSlot **out_pUsageSlot,
        CAkBankMgr::AkLoadBankDataMode in_eLoadMode,
        bool in_bIsFromPrepareBank)
{
  unsigned int numEvents; // r13d
  CAkBankMgr::AkLoadBankDataMode v7; // r12d
  CAkUsageSlot **v8; // r15
  unsigned int v10; // ecx
  unsigned int *pEventID; // rax
  CAkUsageSlot *v12; // rax
  CAkUsageSlot *v13; // r14
  AKRESULT MediaIndex; // ebx
  int uPrepareEventMemoryPoolID; // r13d
  int v17; // r12d
  int v18; // r15d
  char *v19; // rdx
  unsigned int v20; // eax
  bool v21; // zf
  AkBankLoadFlag bankLoadFlag; // eax
  bool v23; // r14
  AKRESULT v24; // eax
  AkHashList<unsigned long,char *,31>::Item *v25; // rcx
  CAkFeedbackBus *v26; // r13
  int v27; // eax
  __int64 v28; // r9
  char *Data; // rsi
  CAkFeedbackBus *MasterMotionBusAndAddRef; // rax
  unsigned int in_bIsLanguageSpecific; // [rsp+28h] [rbp-48h]
  AkBankKey in_pBufferToFill; // [rsp+30h] [rbp-40h] BYREF
  AkBank::AkBankHeader in_rBankHeader; // [rsp+40h] [rbp-30h] BYREF
  unsigned int out_rulSizeRead; // [rsp+B0h] [rbp+40h] BYREF
  unsigned int in_FileID; // [rsp+B8h] [rbp+48h]
  CAkUsageSlot **v36; // [rsp+C0h] [rbp+50h]
  CAkBankMgr::AkLoadBankDataMode v37; // [rsp+C8h] [rbp+58h]

  v37 = in_eLoadMode;
  v36 = out_pUsageSlot;
  numEvents = in_Item->prepare.numEvents;
  v7 = in_eLoadMode;
  v8 = out_pUsageSlot;
  in_FileID = numEvents;
  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  v10 = 0;
  if ( in_Item->eType <= (unsigned int)QueueItemUnload || (unsigned int)(in_Item->eType - 6) <= 1 )
    v10 = in_Item->prepare.numEvents;
  if ( in_Item->bankLoadFlag == AkBankLoadFlag_InMemory )
    pEventID = in_Item->prepare.pEventID;
  else
    pEventID = 0i64;
  in_pBufferToFill.bankID = v10;
  in_pBufferToFill.pInMemoryPtr = pEventID;
  v12 = CAkBankList::Get(&this->m_BankList, &in_pBufferToFill);
  v13 = v12;
  if ( v12 && (*((_BYTE *)v12 + 112) & 1) != 0 )
  {
    LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
    return 69i64;
  }
  MediaIndex = AK_Success;
  LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  if ( v13 )
  {
    v21 = !in_bIsFromPrepareBank;
    *v8 = v13;
    if ( !v21 )
      ++v13->m_iWasPreparedAsABankCounter;
  }
  else
  {
    uPrepareEventMemoryPoolID = g_settings.uPrepareEventMemoryPoolID;
    v17 = 0;
    v18 = 0;
    if ( v37 )
    {
      if ( in_bIsFromPrepareBank )
        v18 = 1;
      else
        v17 = 1;
    }
    else
    {
      uPrepareEventMemoryPoolID = in_Item->load.memPoolId;
      LODWORD(v13) = 1;
    }
    v19 = (char *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x78ui64);
    if ( v19 )
    {
      v20 = in_FileID;
      *((_DWORD *)v19 + 11) = uPrepareEventMemoryPoolID;
      *((_DWORD *)v19 + 6) = v20;
      *((_QWORD *)v19 + 4) = 0i64;
      *((_DWORD *)v19 + 10) = 0;
      v19[48] = 0;
      *(_QWORD *)(v19 + 52) = 0i64;
      *((_QWORD *)v19 + 8) = 0i64;
      *((_QWORD *)v19 + 9) = 0i64;
      *((_QWORD *)v19 + 10) = 0i64;
      *((_QWORD *)v19 + 11) = 0i64;
      *((_QWORD *)v19 + 12) = 0i64;
      *((_DWORD *)v19 + 26) = (_DWORD)v13;
      *((_DWORD *)v19 + 27) = v18 + v17;
      LOBYTE(v20) = v19[112] & 0xF0;
      *((_DWORD *)v19 + 29) = v18;
      v19[112] = v20 | ((_DWORD)v13 != 0);
    }
    else
    {
      v19 = 0i64;
    }
    v8 = v36;
    v7 = v37;
    numEvents = in_FileID;
    *v36 = (CAkUsageSlot *)v19;
    if ( !v19 )
      MediaIndex = AK_InsufficientMemory;
  }
  CAkBankReader::Reset(&this->m_BankReader);
  bankLoadFlag = in_Item->bankLoadFlag;
  v23 = bankLoadFlag == AkBankLoadFlag_InMemory;
  if ( MediaIndex != AK_Success )
    goto LABEL_33;
  if ( v7 )
    goto LABEL_28;
  if ( bankLoadFlag == AkBankLoadFlag_UsingFileID )
  {
LABEL_31:
    LOBYTE(in_bIsLanguageSpecific) = 1;
    v24 = (unsigned int)CAkBankReader::SetFile(
                          &this->m_BankReader,
                          numEvents,
                          0,
                          0,
                          in_Item->callbackInfo.pCookie,
                          in_bIsLanguageSpecific);
    goto LABEL_32;
  }
  if ( bankLoadFlag != AkBankLoadFlag_InMemory )
  {
LABEL_28:
    v25 = this->m_BankIDToFileName.m_table[numEvents % 0x1F];
    if ( v25 )
    {
      while ( v25->Assoc.key != numEvents )
      {
        v25 = v25->pNextItem;
        if ( !v25 )
          goto LABEL_31;
      }
      if ( v25 != (AkHashList<unsigned long,char *,31>::Item *)-16i64 )
      {
        v24 = (unsigned int)CAkBankReader::SetFile(
                              &this->m_BankReader,
                              v25->Assoc.item,
                              0,
                              (__int64)in_Item->callbackInfo.pCookie);
        goto LABEL_32;
      }
    }
    goto LABEL_31;
  }
  v24 = (unsigned int)CAkBankReader::SetFile(
                        &this->m_BankReader,
                        in_Item->loadMediaFile.pszAllocatedFileName,
                        in_Item->load.ui32InMemoryBankSize);
LABEL_32:
  MediaIndex = v24;
LABEL_33:
  memset(&in_rBankHeader, 0, sizeof(in_rBankHeader));
  if ( MediaIndex == AK_Success )
    MediaIndex = CAkBankMgr::ProcessBankHeader(this, &in_rBankHeader);
  v26 = 0i64;
  if ( !this->m_bIsFirstBusLoaded )
    v26 = CAkFeedbackBus::ClearTempMasterBus();
  while ( MediaIndex == AK_Success )
  {
    out_rulSizeRead = 0;
    v27 = CAkBankReader::FillData(&this->m_BankReader, (char *)&in_pBufferToFill, 8u, &out_rulSizeRead);
    MediaIndex = v27;
    if ( v27 != 1 )
      break;
    if ( out_rulSizeRead != 8 )
    {
      if ( out_rulSizeRead )
        v27 = 7;
      MediaIndex = v27;
      break;
    }
    if ( in_pBufferToFill.bankID > 0x474D5453 )
    {
      if ( in_pBufferToFill.bankID == 1398165061 )
      {
        MediaIndex = CAkBankMgr::ProcessEnvSettingsChunk(this, *(&in_pBufferToFill.bankID + 1));
      }
      else
      {
        if ( in_pBufferToFill.bankID != 1480870212 )
          goto LABEL_61;
        if ( (unsigned int)v7 < AkLoadBankDataMode_Structure )
          goto LABEL_66;
        if ( v7 == AkLoadBankDataMode_Structure )
          goto LABEL_61;
        if ( v7 == AkLoadBankDataMode_Media )
LABEL_66:
          MediaIndex = (unsigned int)CAkBankMgr::LoadMediaIndex(this, *v8, *(&in_pBufferToFill.bankID + 1), v23);
      }
    }
    else
    {
      switch ( in_pBufferToFill.bankID )
      {
        case 0x474D5453u:                       // STMG
          MediaIndex = CAkBankMgr::ProcessGlobalSettingsChunk(this, *(&in_pBufferToFill.bankID + 1));
          break;
        case 0x41544144u:                       // DATA
          if ( v7 )
          {
            switch ( v7 )
            {
              case AkLoadBankDataMode_MediaAndStructure:
                goto LABEL_53;
              case AkLoadBankDataMode_Structure:
                goto LABEL_61;
              case AkLoadBankDataMode_Media:
LABEL_53:
                MediaIndex = (unsigned int)CAkBankMgr::PrepareMedia(this, *v8, *(&in_pBufferToFill.bankID + 1));
                break;
            }
          }
          else
          {
            if ( v23 )
            {
              Data = CAkBankReader::GetData(&this->m_BankReader, *(&in_pBufferToFill.bankID + 1));
              CAkBankReader::ReleaseData(&this->m_BankReader);
            }
            else
            {
              MediaIndex = CAkBankMgr::ProcessDataChunk(this, *(&in_pBufferToFill.bankID + 1), *v8);
              Data = (*v8)->m_pData;
              if ( MediaIndex != AK_Success )
                goto LABEL_71;
            }
            MediaIndex = (unsigned int)CAkBankMgr::LoadMedia(this, Data, *v8, v23);
          }
          break;
        case 0x43524948u:                       // HIRC
          MediaIndex = CAkBankMgr::ProcessHircChunk(this, *v8, in_FileID);
          break;
        case 0x44495453u:                       // STID
          MediaIndex = CAkBankMgr::ProcessStringMappingChunk(this, *(&in_pBufferToFill.bankID + 1), *v8);
          break;
        default:
LABEL_61:
          CAkBankReader::Skip(&this->m_BankReader, *(&in_pBufferToFill.bankID + 1), &out_rulSizeRead, v28);
          if ( out_rulSizeRead != *(&in_pBufferToFill.bankID + 1) )
          {
            MediaIndex = AK_InvalidFile;
            goto LABEL_71;
          }
          break;
      }
    }
  }
LABEL_71:
  if ( v26 )
  {
    MasterMotionBusAndAddRef = CAkFeedbackBus::GetMasterMotionBusAndAddRef();
    if ( MasterMotionBusAndAddRef )
      MasterMotionBusAndAddRef->vfptr->Release(MasterMotionBusAndAddRef);
    else
      CAkFeedbackBus::ResetMasterBus(v26);
    v26->vfptr->Release(v26);
  }
  CAkBankReader::CloseFile(&this->m_BankReader);
  return (unsigned int)MediaIndex;
}

// File Line: 980
// RVA: 0xA5E0A0
__int64 __fastcall CAkBankMgr::LoadBankPre(CAkBankMgr *this, CAkBankMgr::AkBankQueueItem *in_rItem)
{
  __int128 v2; // xmm0
  __int128 v3; // xmm1
  unsigned int *pEventID; // rbp
  AKRESULT v7; // edi
  unsigned int v8; // eax
  unsigned int v9; // esi
  CAkUsageSlot *v10; // r8
  unsigned int numEvents; // ecx
  CAkUsageSlot *v12; // rdi
  AkBankKey v14; // [rsp+30h] [rbp-68h] BYREF
  CAkBankMgr::AkBankQueueItem v15; // [rsp+40h] [rbp-58h] BYREF
  CAkUsageSlot *v16; // [rsp+A8h] [rbp+10h] BYREF

  v2 = *(_OWORD *)&in_rItem->eType;
  v3 = *(_OWORD *)&in_rItem->callbackInfo.pCookie;
  pEventID = 0i64;
  v7 = AK_Success;
  v16 = 0i64;
  *(_OWORD *)&v15.eType = v2;
  *(_OWORD *)&v15.callbackInfo.pCookie = v3;
  *(_QWORD *)&v3 = in_rItem->gameSync.pGameSyncID;
  v15.prepare = in_rItem->prepare;
  v15.gameSync.pGameSyncID = (unsigned int *)v3;
  v8 = CAkBankMgr::LoadBank(this, &v15, &v16, AkLoadBankDataMode_OneBlock, 0);
  v9 = v8;
  if ( v8 == 69 )
  {
    v9 = 1;
    v7 = AK_BankAlreadyLoaded;
  }
  else if ( v8 == 1 )
  {
    v10 = v16;
    numEvents = 0;
    *((_BYTE *)v16 + 112) |= 1u;
    if ( in_rItem->eType <= (unsigned int)QueueItemUnload || (unsigned int)(in_rItem->eType - 6) <= 1 )
      numEvents = in_rItem->prepare.numEvents;
    if ( in_rItem->bankLoadFlag == AkBankLoadFlag_InMemory )
      pEventID = in_rItem->prepare.pEventID;
    v14.bankID = numEvents;
    v14.pInMemoryPtr = pEventID;
    CAkBankList::Set(&this->m_BankList, &v14, v10);
  }
  else
  {
    v12 = v16;
    if ( v16 )
    {
      CAkUsageSlot::RemoveContent(v16);
      CAkUsageSlot::Release(v12, 1);
    }
    v7 = v9;
  }
  CAkBankMgr::NotifyCompletion(this, in_rItem, v7);
  return v9;
}

// File Line: 1018
// RVA: 0xA61990
signed __int64 __fastcall CAkBankMgr::UnloadBankPre(CAkBankMgr *this, CAkBankMgr::AkBankQueueItem *in_Item)
{
  unsigned int *pEventID; // r8
  unsigned int numEvents; // edx
  AkBankKey v6; // xmm6
  CAkUsageSlot *v7; // rax
  CAkUsageSlot *v8; // rsi
  AkBankKey v10; // [rsp+20h] [rbp-28h] BYREF

  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  pEventID = 0i64;
  numEvents = 0;
  if ( in_Item->eType <= (unsigned int)QueueItemUnload || (unsigned int)(in_Item->eType - 6) <= 1 )
    numEvents = in_Item->prepare.numEvents;
  if ( in_Item->bankLoadFlag == AkBankLoadFlag_InMemory )
    pEventID = in_Item->prepare.pEventID;
  v10.bankID = numEvents;
  v10.pInMemoryPtr = pEventID;
  v6 = v10;
  v7 = CAkBankList::Get(&this->m_BankList, &v10);
  v8 = v7;
  if ( v7 )
  {
    if ( (*((_BYTE *)v7 + 112) & 1) != 0 )
    {
      v10 = v6;
      CAkBankList::Remove(&this->m_BankList, &v10);
      LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
      return CAkBankMgr::KillSlot(this, v8, in_Item->callbackInfo.pfnBankCallback, in_Item->callbackInfo.pCookie);
    }
    else
    {
      LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
      CAkBankMgr::NotifyCompletion(this, in_Item, AK_Fail);
      return 2i64;
    }
  }
  else
  {
    LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
    CAkBankMgr::NotifyCompletion(this, in_Item, AK_UnknownBankID);
    return 54i64;
  }
}

// File Line: 1058
// RVA: 0xA5CB60
__int64 __fastcall CAkBankMgr::ClearBanksInternal(CAkBankMgr *this, CAkBankMgr::AkBankQueueItem *in_Item)
{
  CAkBankMgr::AkBankQueueItem *v3; // r12
  int v4; // r14d
  char *v5; // r15
  __int64 m_uiSize; // rax
  CAkBankList *p_m_BankList; // rdi
  unsigned __int64 v8; // rax
  __int64 v9; // rcx
  signed __int64 v10; // rcx
  void *v11; // rsp
  void *v12; // rsp
  CAkUsageSlot *v13; // rcx
  __int64 v14; // rdx
  CAkUsageSlot *v15; // r9
  char *v16; // rsi
  CAkUsageSlot *pNextItem; // rbx
  __int64 v18; // r8
  CAkUsageSlot *v19; // r11
  HANDLE v20; // rax
  int v21; // r14d
  __int64 v22; // rbx
  unsigned __int64 v23; // rdi
  unsigned __int16 Size; // ax
  char in_cookie[8]; // [rsp+20h] [rbp+0h] BYREF
  HANDLE hHandle; // [rsp+28h] [rbp+8h]
  AkQueuedMsg in_rItem; // [rsp+40h] [rbp+20h] BYREF

  v3 = in_Item;
  v4 = 0;
  v5 = 0i64;
  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  m_uiSize = this->m_BankList.m_ListLoadedBanks.m_uiSize;
  p_m_BankList = &this->m_BankList;
  if ( (_DWORD)m_uiSize )
  {
    v8 = 8 * m_uiSize;
    v9 = v8 + 15;
    if ( v8 + 15 <= v8 )
      v9 = 0xFFFFFFFFFFFFFF0i64;
    v10 = v9 & 0xFFFFFFFFFFFFFFF0ui64;
    v11 = alloca(v10);
    v12 = alloca(v10);
    v13 = p_m_BankList->m_ListLoadedBanks.m_table[0];
    LODWORD(v14) = 0;
    v15 = 0i64;
    v5 = in_cookie;
    if ( p_m_BankList->m_ListLoadedBanks.m_table[0] )
      goto LABEL_8;
    do
    {
      v14 = (unsigned int)(v14 + 1);
      if ( (unsigned int)v14 >= 0x1F )
        break;
      v13 = p_m_BankList->m_ListLoadedBanks.m_table[v14];
    }
    while ( !v13 );
    if ( v13 )
    {
LABEL_8:
      v16 = in_cookie;
      while ( 1 )
      {
LABEL_9:
        while ( (*((_BYTE *)v13 + 112) & 1) != 0 )
        {
          *(_QWORD *)v16 = v13;
          pNextItem = v13->pNextItem;
          ++v4;
          v16 += 8;
          LODWORD(v18) = v14;
          LODWORD(hHandle) = v14;
          v13 = pNextItem;
          v19 = v15;
          if ( !pNextItem )
          {
            do
            {
              v18 = (unsigned int)(v18 + 1);
              if ( (unsigned int)v18 >= 0x1F )
                break;
              v13 = p_m_BankList->m_ListLoadedBanks.m_table[v18];
              v19 = 0i64;
            }
            while ( !v13 );
            LODWORD(hHandle) = v18;
          }
          if ( v15 )
            v15->pNextItem = pNextItem;
          else
            p_m_BankList->m_ListLoadedBanks.m_table[(unsigned int)v14] = pNextItem;
          v20 = hHandle;
          --this->m_BankList.m_ListLoadedBanks.m_uiSize;
          v15 = v19;
          in_rItem.event.GameObjID = (unsigned __int64)v20;
          LODWORD(v14) = (_DWORD)v20;
LABEL_18:
          if ( !v13 )
            goto LABEL_19;
        }
        v15 = v13;
        v13 = v13->pNextItem;
        if ( !v13 )
        {
          while ( 1 )
          {
            v14 = (unsigned int)(v14 + 1);
            if ( (unsigned int)v14 >= 0x1F )
              goto LABEL_18;
            v13 = p_m_BankList->m_ListLoadedBanks.m_table[v14];
            v15 = 0i64;
            if ( v13 )
              goto LABEL_9;
          }
        }
      }
    }
  }
LABEL_19:
  LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  v21 = v4 - 1;
  v22 = v21;
  if ( v21 >= 0 )
  {
    do
    {
      v23 = *(_QWORD *)&v5[8 * v22];
      hHandle = CreateEventW(0i64, 0, 0, 0i64);
      if ( (unsigned int)CAkBankCallbackMgr::AddCookie(&this->m_CallbackMgr, in_cookie) == 1 )
      {
        CAkUsageSlot::RemoveContent((CAkUsageSlot *)v23);
        *(_BYTE *)(v23 + 112) |= 8u;
        *(_QWORD *)(v23 + 80) = in_cookie;
        *(_QWORD *)(v23 + 72) = AK::SoundEngine::DefaultBankCallbackFunc;
        in_rItem.type = 24;
        in_rItem.event.GameObjID = v23;
        Size = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_CreateTexture,Scaleform::Render::DICommand>::GetSize();
        CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, Size);
        if ( (unsigned int)AK::SoundEngine::RenderAudio() == 1 )
          WaitForSingleObject(hHandle, 0xFFFFFFFF);
      }
      if ( hHandle )
        CloseHandle(hHandle);
      --v22;
    }
    while ( v22 >= 0 );
    v3 = in_Item;
  }
  CAkBankMgr::NotifyCompletion(this, v3, AK_Success);
  return 1i64;
}

// File Line: 1112
// RVA: 0xA5EC60
__int64 __fastcall CAkBankMgr::PrepareEvents(CAkBankMgr *this, CAkBankMgr::AkBankQueueItem *in_Item)
{
  unsigned int numEvents; // eax
  unsigned int *pEventID; // r12
  __int128 v6; // xmm1
  unsigned int eventID; // r8d
  AKRESULT in_eLoadResult; // r13d
  unsigned int v9; // esi
  __int128 v10; // xmm1
  unsigned int v11; // r8d
  unsigned int i; // ebp
  unsigned int v13; // esi
  CAkIndexItem<CAkEvent *> *v14; // r14
  CAkEvent *v15; // rbx
  CAkBankMgr::AkBankQueueItemType eType; // eax
  int in_memPoolId; // edx
  unsigned int v18; // r8d
  __int64 v19; // r12
  unsigned int v20; // ebp
  CAkIndexItem<CAkEvent *> *p_m_idxEvents; // r14
  CAkEvent *pNextItem; // rbx
  CAkBankMgr::AkBankQueueItem v24; // [rsp+40h] [rbp-68h] BYREF

  this->m_bAccumulating = 1;
  numEvents = in_Item->prepare.numEvents;
  pEventID = 0i64;
  if ( numEvents == 1 )
  {
    v6 = *(_OWORD *)&in_Item->callbackInfo.pCookie;
    eventID = in_Item->prepare.eventID;
    *(_OWORD *)&v24.eType = *(_OWORD *)&in_Item->eType;
    *(_OWORD *)&v24.callbackInfo.pCookie = v6;
    *(_QWORD *)&v6 = in_Item->gameSync.pGameSyncID;
    v24.prepare = in_Item->prepare;
    v24.gameSync.pGameSyncID = (unsigned int *)v6;
    in_eLoadResult = (unsigned int)CAkBankMgr::PrepareEvent(this, &v24, eventID);
    if ( in_eLoadResult == AK_Success )
    {
      in_eLoadResult = CAkBankMgr::ProcessAccumulated(this);
      if ( in_eLoadResult != AK_Success )
        CAkBankMgr::UnprepareEvent(this, in_Item->prepare.eventID);
    }
  }
  else
  {
    v9 = 0;
    if ( numEvents )
    {
      while ( 1 )
      {
        v10 = *(_OWORD *)&in_Item->callbackInfo.pCookie;
        v11 = in_Item->prepare.pEventID[v9];
        *(_OWORD *)&v24.eType = *(_OWORD *)&in_Item->eType;
        *(_OWORD *)&v24.callbackInfo.pCookie = v10;
        *(_QWORD *)&v10 = in_Item->gameSync.pGameSyncID;
        v24.prepare = in_Item->prepare;
        v24.gameSync.pGameSyncID = (unsigned int *)v10;
        in_eLoadResult = (unsigned int)CAkBankMgr::PrepareEvent(this, &v24, v11);
        if ( in_eLoadResult != AK_Success )
          break;
        if ( ++v9 >= in_Item->prepare.numEvents )
          goto LABEL_8;
      }
      if ( v9 )
      {
        v19 = v9;
        do
        {
          v20 = in_Item->prepare.pEventID[--v19];
          p_m_idxEvents = &g_pIndex->m_idxEvents;
          --v9;
          EnterCriticalSection(&g_pIndex->m_idxEvents.m_IndexLock.m_csLock);
          pNextItem = (CAkEvent *)p_m_idxEvents->m_mapIDToPtr.m_table[v20 % 0xC1];
          if ( pNextItem )
          {
            while ( pNextItem->key != v20 )
            {
              pNextItem = (CAkEvent *)pNextItem->pNextItem;
              if ( !pNextItem )
                goto LABEL_26;
            }
            ++pNextItem->m_lRef;
            LeaveCriticalSection(&p_m_idxEvents->m_IndexLock.m_csLock);
            CAkBankMgr::UnprepareEvent(this, pNextItem, 0);
            pNextItem->vfptr->Release(pNextItem);
          }
          else
          {
LABEL_26:
            LeaveCriticalSection(&p_m_idxEvents->m_IndexLock.m_csLock);
          }
        }
        while ( v9 );
        pEventID = 0i64;
      }
    }
    else
    {
LABEL_8:
      in_eLoadResult = CAkBankMgr::ProcessAccumulated(this);
      if ( in_eLoadResult != AK_Success )
      {
        for ( i = 0; i < in_Item->prepare.numEvents; ++i )
        {
          v13 = in_Item->prepare.pEventID[i];
          v14 = &g_pIndex->m_idxEvents;
          EnterCriticalSection(&g_pIndex->m_idxEvents.m_IndexLock.m_csLock);
          v15 = (CAkEvent *)v14->m_mapIDToPtr.m_table[v13 % 0xC1];
          if ( v15 )
          {
            while ( v15->key != v13 )
            {
              v15 = (CAkEvent *)v15->pNextItem;
              if ( !v15 )
                goto LABEL_13;
            }
            ++v15->m_lRef;
            LeaveCriticalSection(&v14->m_IndexLock.m_csLock);
            CAkBankMgr::UnprepareEvent(this, v15, 0);
            v15->vfptr->Release(v15);
          }
          else
          {
LABEL_13:
            LeaveCriticalSection(&v14->m_IndexLock.m_csLock);
          }
        }
      }
    }
    AK::MemoryMgr::Free(g_DefaultPoolId, in_Item->prepare.pEventID);
    in_Item->prepare.pEventID = 0i64;
  }
  this->m_bAccumulating = 0;
  this->m_PreparationAccumulator.m_uLength = 0;
  eType = in_Item->eType;
  in_memPoolId = -1;
  v18 = 0;
  if ( in_Item->eType >= QueueItemLoad )
  {
    if ( eType <= QueueItemUnload )
    {
      in_memPoolId = in_Item->load.memPoolId;
      v18 = in_Item->prepare.numEvents;
      goto LABEL_34;
    }
    if ( eType == QueueItemSupportedGameSync )
      goto LABEL_34;
    if ( (unsigned int)(eType - 6) <= 1 )
    {
      v18 = in_Item->prepare.numEvents;
      goto LABEL_34;
    }
  }
  if ( in_Item->prepare.numEvents == 1 )
    v18 = in_Item->prepare.eventID;
LABEL_34:
  if ( in_Item->bankLoadFlag == AkBankLoadFlag_InMemory )
    pEventID = in_Item->prepare.pEventID;
  CAkBankCallbackMgr::DoCallback(
    &this->m_CallbackMgr,
    in_Item->callbackInfo.pfnBankCallback,
    v18,
    pEventID,
    in_eLoadResult,
    in_memPoolId,
    in_Item->callbackInfo.pCookie);
  return (unsigned int)in_eLoadResult;
}

// File Line: 1194
// RVA: 0xA5EAA0
__int64 __fastcall CAkBankMgr::PrepareEvent(
        CAkBankMgr *this,
        CAkBankMgr::AkBankQueueItem *in_Item,
        unsigned int in_EventID)
{
  AKRESULT v5; // ebp
  CAkIndexable *PtrAndAddRef; // rax
  CAkIndexable *v7; // rsi
  CAkIndexableVtbl *vfptr; // rbx
  __int128 v9; // xmm1
  unsigned int Category; // r8d
  unsigned int v11; // eax
  CAkUsageSlot *v12; // rax
  CAkIndexableVtbl *i; // rdi
  unsigned int v14; // eax
  CAkUsageSlot *v15; // rax
  AkBankKey v17; // [rsp+30h] [rbp-78h] BYREF
  unsigned __int128 v18; // [rsp+40h] [rbp-68h] BYREF
  CAkBankMgr::AkBankQueueItem v19; // [rsp+50h] [rbp-58h] BYREF

  v5 = AK_Success;
  PtrAndAddRef = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                   (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxEvents,
                   in_EventID);
  v7 = PtrAndAddRef;
  if ( PtrAndAddRef )
  {
    if ( !LODWORD(PtrAndAddRef[1].pNextItem) )
    {
      vfptr = PtrAndAddRef[1].vfptr;
      if ( vfptr )
      {
        while ( 1 )
        {
          if ( WORD2(vfptr[1].Release) == 1027 )
          {
            v9 = *(_OWORD *)&in_Item->callbackInfo.pCookie;
            Category = (unsigned int)vfptr[1].Category;
            *(_OWORD *)&v19.eType = *(_OWORD *)&in_Item->eType;
            *(_OWORD *)&v19.callbackInfo.pCookie = v9;
            *(_QWORD *)&v9 = in_Item->gameSync.pGameSyncID;
            v19.prepare = in_Item->prepare;
            v19.gameSync.pGameSyncID = (unsigned int *)v9;
            v5 = (unsigned int)CAkBankMgr::PrepareBankInternal(this, &v19, Category, AkLoadBankDataMode_Structure, 0);
            if ( v5 != AK_Success )
              goto LABEL_11;
            v5 = CAkParameterNodeBase::PrepareNodeData((unsigned int)vfptr[1].Release);
            if ( v5 != AK_Success )
              break;
          }
          vfptr = (CAkIndexableVtbl *)vfptr->Category;
          if ( !vfptr )
            goto LABEL_16;
        }
        v11 = (unsigned int)vfptr[1].Category;
        v17.pInMemoryPtr = 0i64;
        v17.bankID = v11;
        v12 = CAkBankList::Get(&this->m_BankList, &v17);
        if ( v12 )
          CAkUsageSlot::ReleasePrepare(v12, 0);
LABEL_11:
        for ( i = v7[1].vfptr; i != vfptr; i = (CAkIndexableVtbl *)i->Category )
        {
          if ( WORD2(i[1].Release) == 1027 )
          {
            CAkParameterNodeBase::UnPrepareNodeData((unsigned int)i[1].Release);
            v14 = (unsigned int)i[1].Category;
            v17.pInMemoryPtr = 0i64;
            v17.bankID = v14;
            v18 = *(unsigned __int64 *)&v17.bankID;
            v15 = CAkBankList::Get(&this->m_BankList, (AkBankKey *)&v18);
            if ( v15 )
              CAkUsageSlot::ReleasePrepare(v15, 0);
          }
        }
LABEL_16:
        if ( v5 != AK_Success )
          goto LABEL_19;
      }
      v7->vfptr->AddRef(v7);
    }
    ++LODWORD(v7[1].pNextItem);
LABEL_19:
    v7->vfptr->Release(v7);
    return (unsigned int)v5;
  }
  return 15i64;
}

// File Line: 1261
// RVA: 0xA61F00
__int64 __fastcall CAkBankMgr::UnprepareEvents(CAkBankMgr *this, CAkBankMgr::AkBankQueueItem *in_Item)
{
  unsigned int numEvents; // eax
  AKRESULT in_eLoadResult; // r14d
  unsigned int *pEventID; // r12
  CAkEvent *PtrAndAddRef; // rax
  CAkEvent *v8; // rbx
  unsigned int v9; // ebp
  unsigned int v10; // esi
  CAkIndexItem<CAkEvent *> *p_m_idxEvents; // r15
  CAkEvent *pNextItem; // rbx
  CAkBankMgr::AkBankQueueItemType eType; // eax
  int in_memPoolId; // r9d
  unsigned int eventID; // r8d

  numEvents = in_Item->prepare.numEvents;
  in_eLoadResult = AK_Success;
  pEventID = 0i64;
  if ( numEvents == 1 )
  {
    PtrAndAddRef = (CAkEvent *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                 (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxEvents,
                                 in_Item->prepare.eventID);
    v8 = PtrAndAddRef;
    if ( PtrAndAddRef )
    {
      CAkBankMgr::UnprepareEvent(this, PtrAndAddRef, 0);
      v8->vfptr->Release(v8);
    }
    else
    {
      in_eLoadResult = AK_IDNotFound;
    }
  }
  else
  {
    v9 = 0;
    if ( numEvents )
    {
      do
      {
        v10 = in_Item->prepare.pEventID[v9];
        p_m_idxEvents = &g_pIndex->m_idxEvents;
        in_eLoadResult = AK_Success;
        EnterCriticalSection(&g_pIndex->m_idxEvents.m_IndexLock.m_csLock);
        pNextItem = (CAkEvent *)p_m_idxEvents->m_mapIDToPtr.m_table[v10 % 0xC1];
        if ( pNextItem )
        {
          while ( pNextItem->key != v10 )
          {
            pNextItem = (CAkEvent *)pNextItem->pNextItem;
            if ( !pNextItem )
              goto LABEL_9;
          }
          ++pNextItem->m_lRef;
          LeaveCriticalSection(&p_m_idxEvents->m_IndexLock.m_csLock);
          CAkBankMgr::UnprepareEvent(this, pNextItem, 0);
          pNextItem->vfptr->Release(pNextItem);
        }
        else
        {
LABEL_9:
          LeaveCriticalSection(&p_m_idxEvents->m_IndexLock.m_csLock);
          in_eLoadResult = AK_IDNotFound;
        }
        if ( in_eLoadResult != AK_Success )
          break;
        ++v9;
      }
      while ( v9 < in_Item->prepare.numEvents );
    }
    AK::MemoryMgr::Free(g_DefaultPoolId, in_Item->prepare.pEventID);
    in_Item->prepare.pEventID = 0i64;
  }
  eType = in_Item->eType;
  in_memPoolId = -1;
  eventID = 0;
  if ( in_Item->eType >= QueueItemLoad )
  {
    if ( eType <= QueueItemUnload )
    {
      in_memPoolId = in_Item->load.memPoolId;
      eventID = in_Item->prepare.numEvents;
      goto LABEL_22;
    }
    if ( eType == QueueItemSupportedGameSync )
      goto LABEL_22;
    if ( (unsigned int)(eType - 6) <= 1 )
    {
      eventID = in_Item->prepare.numEvents;
      goto LABEL_22;
    }
  }
  if ( in_Item->prepare.numEvents == 1 )
    eventID = in_Item->prepare.eventID;
LABEL_22:
  if ( in_Item->bankLoadFlag == AkBankLoadFlag_InMemory )
    pEventID = in_Item->prepare.pEventID;
  CAkBankCallbackMgr::DoCallback(
    &this->m_CallbackMgr,
    in_Item->callbackInfo.pfnBankCallback,
    eventID,
    pEventID,
    in_eLoadResult,
    in_memPoolId,
    in_Item->callbackInfo.pCookie);
  return (unsigned int)in_eLoadResult;
}

// File Line: 1303
// RVA: 0xA61DC0
__int64 __fastcall CAkBankMgr::UnprepareEvent(CAkBankMgr *this, unsigned int in_EventID)
{
  CAkEvent *PtrAndAddRef; // rax
  CAkEvent *v4; // rbx

  PtrAndAddRef = (CAkEvent *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                               (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxEvents,
                               in_EventID);
  v4 = PtrAndAddRef;
  if ( !PtrAndAddRef )
    return 15i64;
  CAkBankMgr::UnprepareEvent(this, PtrAndAddRef, 0);
  v4->vfptr->Release(v4);
  return 1i64;
}

// File Line: 1325
// RVA: 0xA61E20
void __fastcall CAkBankMgr::UnprepareEvent(CAkBankMgr *this, CAkEvent *in_pEvent, bool in_bCompleteUnprepare)
{
  unsigned int m_iPreparationCount; // eax
  CAkAction *m_pFirst; // rbx
  CAkAction *v7; // rdi
  CAkUsageSlot *v8; // rax
  unsigned __int64 v9; // [rsp+20h] [rbp-38h]
  unsigned __int128 v10; // [rsp+30h] [rbp-28h] BYREF

  m_iPreparationCount = in_pEvent->m_iPreparationCount;
  if ( m_iPreparationCount )
  {
    in_pEvent->m_iPreparationCount = in_bCompleteUnprepare ? 0 : m_iPreparationCount - 1;
    if ( !in_pEvent->m_iPreparationCount )
    {
      m_pFirst = in_pEvent->m_actions.m_pFirst;
      while ( m_pFirst )
      {
        v7 = m_pFirst;
        m_pFirst = m_pFirst->pNextLightItem;
        if ( v7->m_eActionType == 1027 )
        {
          CAkParameterNodeBase::UnPrepareNodeData(v7->m_ulElementID);
          LODWORD(v9) = v7[1].vfptr;
          v10 = v9;
          v8 = CAkBankList::Get(&this->m_BankList, (AkBankKey *)&v10);
          if ( v8 )
            CAkUsageSlot::ReleasePrepare(v8, 0);
        }
      }
      in_pEvent->vfptr->Release(in_pEvent);
    }
  }
}

// File Line: 1381
// RVA: 0xA5EF90
__int64 __fastcall CAkBankMgr::PrepareGameSync(CAkBankMgr *this, CAkBankMgr::AkBankQueueItem *in_Item)
{
  AKRESULT v4; // esi
  unsigned int uNumGameSync; // eax
  unsigned int *pEventID; // r14
  AKRESULT v7; // eax
  __int64 v8; // rdi
  __int64 v9; // rbp
  unsigned int i; // edi
  CAkBankMgr::AkBankQueueItemType eType; // eax
  int in_memPoolId; // edx
  unsigned int numEvents; // r8d

  v4 = AK_Success;
  if ( in_Item->gameSync.bSupported )
    this->m_bAccumulating = 1;
  uNumGameSync = in_Item->gameSync.uNumGameSync;
  pEventID = 0i64;
  if ( uNumGameSync == 1 )
  {
    v7 = (unsigned int)CAkStateMgr::PrepareGameSync(
                         g_pStateMgr,
                         in_Item->gameSync.eGroupType,
                         in_Item->gameSync.uGroupID,
                         in_Item->load.ui32InMemoryBankSize,
                         in_Item->gameSync.bSupported);
    v4 = v7;
    if ( !in_Item->gameSync.bSupported )
      goto LABEL_23;
    if ( v7 == AK_Success )
    {
      v4 = CAkBankMgr::ProcessAccumulated(this);
      if ( v4 != AK_Success )
        CAkStateMgr::PrepareGameSync(
          g_pStateMgr,
          in_Item->gameSync.eGroupType,
          in_Item->gameSync.uGroupID,
          in_Item->load.ui32InMemoryBankSize,
          0);
    }
  }
  else
  {
    v8 = 0i64;
    if ( uNumGameSync )
    {
      while ( 1 )
      {
        v4 = (unsigned int)CAkStateMgr::PrepareGameSync(
                             g_pStateMgr,
                             in_Item->gameSync.eGroupType,
                             in_Item->gameSync.uGroupID,
                             in_Item->gameSync.pGameSyncID[v8],
                             in_Item->gameSync.bSupported);
        if ( v4 != AK_Success )
          break;
        v8 = (unsigned int)(v8 + 1);
        if ( (unsigned int)v8 >= in_Item->gameSync.uNumGameSync )
          goto LABEL_15;
      }
      if ( (_DWORD)v8 )
      {
        v9 = 0i64;
        do
        {
          CAkStateMgr::PrepareGameSync(
            g_pStateMgr,
            in_Item->gameSync.eGroupType,
            in_Item->gameSync.uGroupID,
            in_Item->gameSync.pGameSyncID[v9++],
            0);
          --v8;
        }
        while ( v8 );
      }
    }
LABEL_15:
    if ( in_Item->gameSync.bSupported && v4 == AK_Success )
    {
      v4 = CAkBankMgr::ProcessAccumulated(this);
      if ( v4 != AK_Success )
      {
        for ( i = 0; i < in_Item->gameSync.uNumGameSync; ++i )
          CAkStateMgr::PrepareGameSync(
            g_pStateMgr,
            in_Item->gameSync.eGroupType,
            in_Item->gameSync.uGroupID,
            in_Item->gameSync.pGameSyncID[i],
            0);
      }
    }
    AK::MemoryMgr::Free(g_DefaultPoolId, in_Item->gameSync.pGameSyncID);
  }
  if ( in_Item->gameSync.bSupported )
  {
    this->m_bAccumulating = 0;
    this->m_PreparationAccumulator.m_uLength = 0;
  }
LABEL_23:
  eType = in_Item->eType;
  in_memPoolId = -1;
  numEvents = 0;
  if ( in_Item->eType >= QueueItemLoad )
  {
    if ( eType <= QueueItemUnload )
    {
      in_memPoolId = in_Item->load.memPoolId;
      numEvents = in_Item->prepare.numEvents;
      goto LABEL_31;
    }
    if ( eType == QueueItemSupportedGameSync )
      goto LABEL_31;
    if ( (unsigned int)(eType - 6) <= 1 )
    {
      numEvents = in_Item->prepare.numEvents;
      goto LABEL_31;
    }
  }
  if ( in_Item->prepare.numEvents == 1 )
    numEvents = in_Item->prepare.eventID;
LABEL_31:
  if ( in_Item->bankLoadFlag == AkBankLoadFlag_InMemory )
    pEventID = in_Item->prepare.pEventID;
  CAkBankCallbackMgr::DoCallback(
    &this->m_CallbackMgr,
    in_Item->callbackInfo.pfnBankCallback,
    numEvents,
    pEventID,
    v4,
    in_memPoolId,
    in_Item->callbackInfo.pCookie);
  return (unsigned int)v4;
}

// File Line: 1654
// RVA: 0xA61CE0
__int64 __fastcall CAkBankMgr::UnloadMediaFile(CAkBankMgr *this, CAkBankMgr::AkBankQueueItem *in_Item)
{
  AKRESULT v4; // ebp
  unsigned int numEvents; // esi
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v6; // rax
  AkMediaEntry *p_item; // rdi
  bool v8; // zf

  v4 = AK_Success;
  EnterCriticalSection(&this->m_MediaLock.m_csLock);
  numEvents = in_Item->prepare.numEvents;
  v6 = this->m_MediaHashTable.m_table[numEvents % 0xC1];
  if ( v6 )
  {
    while ( v6->Assoc.key != numEvents )
    {
      v6 = v6->pNextItem;
      if ( !v6 )
        goto LABEL_12;
    }
    p_item = &v6->Assoc.item;
    if ( v6 != (AkHashList<unsigned long,AkMediaEntry,193>::Item *)-16i64 )
    {
      v8 = v6->Assoc.item.uRefCount-- == 1;
      if ( v8 && p_item->m_preparedMediaInfo.pInMemoryData )
      {
        AK::MemoryMgr::Free(g_settings.uPrepareEventMemoryPoolID, p_item->m_preparedMediaInfo.pInMemoryData);
        p_item->m_preparedMediaInfo.pInMemoryData = 0i64;
        p_item->m_preparedMediaInfo.uInMemoryDataSize = 0;
      }
      if ( p_item->uRefCount )
        v4 = AK_Fail;
      else
        AkHashList<unsigned long,AkMediaEntry,193>::Unset(&this->m_MediaHashTable, numEvents);
    }
  }
LABEL_12:
  CAkBankMgr::NotifyCompletion(this, in_Item, v4);
  LeaveCriticalSection(&this->m_MediaLock.m_csLock);
  return (unsigned int)v4;
}

// File Line: 1796
// RVA: 0xA61410
void __fastcall CAkBankMgr::UnPrepareAllBank(CAkBankMgr *this)
{
  __int64 v2; // rdi
  _QWORD *v3; // r14
  __int64 m_uiSize; // rax
  CAkBankList *p_m_BankList; // rbx
  unsigned __int64 v6; // rax
  __int64 v7; // rcx
  void *v8; // rsp
  CAkUsageSlot *v9; // rdx
  void *v10; // rsp
  signed __int64 v11; // rcx
  _QWORD *v12; // r8
  _QWORD *v13; // rsi
  __int128 v14; // xmm6
  CAkUsageSlot *v15; // rax
  CAkUsageSlot *v16; // rax
  int m_iWasPreparedAsABankCounter; // ecx
  _QWORD v18[2]; // [rsp+20h] [rbp+0h] BYREF
  __int128 v19; // [rsp+30h] [rbp+10h] BYREF
  __int128 v20; // [rsp+40h] [rbp+20h]
  unsigned __int128 v21; // [rsp+50h] [rbp+30h] BYREF

  LODWORD(v2) = 0;
  v3 = 0i64;
  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  m_uiSize = this->m_BankList.m_ListLoadedBanks.m_uiSize;
  p_m_BankList = &this->m_BankList;
  if ( (_DWORD)m_uiSize )
  {
    v6 = 16 * m_uiSize;
    v7 = v6 + 15;
    if ( v6 + 15 <= v6 )
      v7 = 0xFFFFFFFFFFFFFF0i64;
    v11 = v7 & 0xFFFFFFFFFFFFFFF0ui64;
    v8 = alloca(v11);
    v9 = p_m_BankList->m_ListLoadedBanks.m_table[0];
    v10 = alloca(v11);
    v3 = v18;
    LODWORD(v11) = 0;
    if ( p_m_BankList->m_ListLoadedBanks.m_table[0] )
      goto LABEL_8;
    do
    {
      v11 = (unsigned int)(v11 + 1);
      if ( (unsigned int)v11 >= 0x1F )
        break;
      v9 = p_m_BankList->m_ListLoadedBanks.m_table[v11];
    }
    while ( !v9 );
    if ( v9 )
    {
LABEL_8:
      v12 = v18;
      do
      {
LABEL_9:
        if ( v9->m_iWasPreparedAsABankCounter )
        {
          LODWORD(v2) = v2 + 1;
          v12 += 2;
          *(v12 - 2) = *(_QWORD *)&v9->key.bankID;
          *(v12 - 1) = v9->key.pInMemoryPtr;
        }
        v9 = v9->pNextItem;
      }
      while ( v9 );
      while ( 1 )
      {
        v11 = (unsigned int)(v11 + 1);
        if ( (unsigned int)v11 >= 0x1F )
          break;
        v9 = p_m_BankList->m_ListLoadedBanks.m_table[v11];
        if ( v9 )
          goto LABEL_9;
      }
    }
  }
  LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  v2 = (int)v2;
  if ( (int)v2 > 0 )
  {
    v13 = &v3[2 * (int)v2];
    do
    {
      v14 = *((_OWORD *)v13 - 1);
      v13 -= 2;
      --v2;
      v20 = v14;
      EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
      v19 = v14;
      v15 = CAkBankList::Get(p_m_BankList, (AkBankKey *)&v19);
      if ( v15 && v15->m_iWasPreparedAsABankCounter )
      {
        LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
        v18[1] = 0i64;
        LODWORD(v18[0]) = v20;
        v21 = v18[0];
        v16 = CAkBankList::Get(p_m_BankList, (AkBankKey *)&v21);
        if ( v16 )
        {
          m_iWasPreparedAsABankCounter = v16->m_iWasPreparedAsABankCounter;
          if ( m_iWasPreparedAsABankCounter )
            v16->m_iWasPreparedAsABankCounter = m_iWasPreparedAsABankCounter - 1;
          CAkUsageSlot::ReleasePrepare(v16, 1);
        }
      }
      else
      {
        LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
      }
    }
    while ( v2 > 0 );
  }
}

// File Line: 1840
// RVA: 0xA5E920
signed __int64 __fastcall CAkBankMgr::PrepareBankInternal(
        CAkBankMgr *this,
        CAkBankMgr::AkBankQueueItem *in_Item,
        unsigned int in_FileID,
        CAkBankMgr::AkLoadBankDataMode in_LoadBankMode,
        bool in_bIsFromPrepareBank)
{
  AkBankKey v9; // xmm6
  CAkUsageSlot *v10; // rax
  bool v11; // al
  __int128 v12; // xmm1
  AkPrepareEventQueueItemLoad prepare; // xmm0
  unsigned int v14; // eax
  unsigned int v15; // edi
  CAkUsageSlot *v17; // rbx
  AkBankKey v18; // [rsp+30h] [rbp-98h] BYREF
  AkBankKey v19; // [rsp+40h] [rbp-88h] BYREF
  AkBankKey v20; // [rsp+50h] [rbp-78h] BYREF
  CAkBankMgr::AkBankQueueItem v21; // [rsp+60h] [rbp-68h] BYREF
  CAkUsageSlot *v22; // [rsp+D0h] [rbp+8h] BYREF

  v18.bankID = in_FileID;
  v18.pInMemoryPtr = 0i64;
  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  v9 = (AkBankKey)*(unsigned __int64 *)&v18.bankID;
  v10 = CAkBankList::Get(&this->m_BankList, &v18);
  if ( v10 )
  {
    _InterlockedIncrement(&v10->m_iPrepareRefCount);
    ++v10->m_iWasPreparedAsABankCounter;
    if ( in_LoadBankMode == AkLoadBankDataMode_Structure || (*((_BYTE *)v10 + 112) & 4) != 0 )
    {
      LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
      return 1i64;
    }
    in_LoadBankMode = AkLoadBankDataMode_Media;
  }
  LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  v11 = in_bIsFromPrepareBank;
  in_Item->prepare.numEvents = in_FileID;
  v12 = *(_OWORD *)&in_Item->callbackInfo.pCookie;
  *(_OWORD *)&v21.eType = *(_OWORD *)&in_Item->eType;
  *(_OWORD *)&v21.callbackInfo.pCookie = v12;
  prepare = in_Item->prepare;
  *(_QWORD *)&v12 = in_Item->gameSync.pGameSyncID;
  v22 = 0i64;
  v21.prepare = prepare;
  v21.gameSync.pGameSyncID = (unsigned int *)v12;
  v14 = CAkBankMgr::LoadBank(this, &v21, &v22, in_LoadBankMode, v11);
  v15 = v14;
  if ( v14 == 1 )
  {
    v19 = v9;
    CAkBankList::Set(&this->m_BankList, &v19, v22);
  }
  else if ( v14 != 69 )
  {
    v17 = v22;
    if ( v22 )
    {
      v20 = v9;
      CAkBankList::Remove(&this->m_BankList, &v20);
      CAkUsageSlot::ReleasePrepare(v17, 0);
    }
  }
  return v15;
}

// File Line: 1908
// RVA: 0xA617E0
void __fastcall CAkBankMgr::UnloadAll(CAkBankMgr *this)
{
  CAkBankList *p_m_BankList; // r15
  CAkUsageSlot *v3; // rdi
  __int64 v4; // rdx
  __int64 v5; // rbp
  CAkUsageSlot *pNextItem; // r9
  CAkUsageSlot *v7; // rbx
  __int64 v8; // rcx
  __int64 v9; // r8
  int v10; // et0
  char v11; // of
  char PoolAttributes; // al
  char *m_pData; // rdx
  int m_memPoolId; // ecx
  int v15; // esi
  int v16; // [rsp+28h] [rbp-50h]

  CAkBankMgr::ClearPreparedEvents(this);
  CAkBankMgr::UnPrepareAllBank(this);
  p_m_BankList = &this->m_BankList;
  v3 = this->m_BankList.m_ListLoadedBanks.m_table[0];
  LODWORD(v4) = 0;
  v5 = 0i64;
  if ( v3 )
  {
    while ( 1 )
    {
LABEL_6:
      pNextItem = v3->pNextItem;
      v7 = v3;
      LODWORD(v8) = v4;
      v16 = v4;
      v9 = v5;
      v3 = pNextItem;
      if ( !pNextItem )
      {
        do
        {
          v8 = (unsigned int)(v8 + 1);
          if ( (unsigned int)v8 >= 0x1F )
            break;
          v3 = p_m_BankList->m_ListLoadedBanks.m_table[v8];
          v9 = 0i64;
        }
        while ( !v3 );
        v16 = v8;
      }
      p_m_BankList->m_ListLoadedBanks.m_table[(unsigned int)v4] = pNextItem;
      --p_m_BankList->m_ListLoadedBanks.m_uiSize;
      v5 = v9;
      CAkUsageSlot::RemoveContent(v7);
      EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
      v10 = _InterlockedAdd(&v7->m_iRefCount, 0xFFFFFFFF);
      if ( !((v10 < 0) ^ v11 | (v10 == 0)) )
        goto LABEL_21;
      if ( v7->m_pData )
      {
        PoolAttributes = AK::MemoryMgr::GetPoolAttributes(v7->m_memPoolId);
        m_pData = v7->m_pData;
        m_memPoolId = v7->m_memPoolId;
        if ( (PoolAttributes & 8) != 0 )
          AK::MemoryMgr::ReleaseBlock(m_memPoolId, m_pData);
        else
          AK::MemoryMgr::Free(m_memPoolId, m_pData);
        v7->m_pData = 0i64;
        if ( v7->m_bIsInternalPool )
        {
          AK::MemoryMgr::DestroyPool(v7->m_memPoolId);
          v7->m_memPoolId = -1;
        }
      }
      CAkBankMgr::UnloadMedia(g_pBankManager, v7);
      if ( v7->m_iPrepareRefCount <= 0 )
      {
        LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
        v15 = g_DefaultPoolId;
        if ( (*((_BYTE *)v7 + 112) & 2) != 0 )
        {
          AK::MemoryMgr::Free(g_DefaultPoolId, v7->m_paLoadedMedia);
          *((_BYTE *)v7 + 112) &= ~2u;
        }
        v7->m_paLoadedMedia = 0i64;
        AK::MemoryMgr::Free(v15, v7);
      }
      else
      {
LABEL_21:
        LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
      }
      if ( !v3 )
        break;
      LODWORD(v4) = v16;
    }
  }
  else
  {
    while ( 1 )
    {
      v4 = (unsigned int)(v4 + 1);
      if ( (unsigned int)v4 >= 0x1F )
        break;
      v3 = p_m_BankList->m_ListLoadedBanks.m_table[v4];
      if ( v3 )
        goto LABEL_6;
    }
  }
}

// File Line: 1926
// RVA: 0xA5CAA0
void __fastcall CAkBankMgr::AddLoadedItem(CAkBankMgr *this, CAkUsageSlot *in_pUsageSlot, CAkIndexable *in_pIndexable)
{
  __int64 m_uLength; // r10
  CAkIndexable **v4; // r9

  m_uLength = in_pUsageSlot->m_listLoadedItem.m_uLength;
  if ( (unsigned int)m_uLength < in_pUsageSlot->m_listLoadedItem.m_ulReserved )
  {
    v4 = &in_pUsageSlot->m_listLoadedItem.m_pItems[m_uLength];
    in_pUsageSlot->m_listLoadedItem.m_uLength = m_uLength + 1;
    if ( v4 )
      *v4 = in_pIndexable;
  }
}

// File Line: 1948
// RVA: 0xA5F6A0
__int64 __fastcall CAkBankMgr::ProcessBankHeader(CAkBankMgr *this, AkBank::AkBankHeader *in_rBankHeader)
{
  unsigned int v4; // eax
  __int64 v5; // r9
  unsigned int v6; // ebx
  unsigned int v7; // edx
  unsigned int out_rulSizeSkipped; // [rsp+30h] [rbp+8h] BYREF
  int in_pBufferToFill; // [rsp+38h] [rbp+10h] BYREF
  int v11; // [rsp+3Ch] [rbp+14h]

  if ( (unsigned int)CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&in_pBufferToFill, 8u) != 1
    || in_pBufferToFill != 1145588546 )
  {
    v7 = 7;
    goto LABEL_11;
  }
  v4 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)in_rBankHeader, 0x14u);
  v6 = v11 - 20;
  v7 = v4;
  if ( v4 == 1 )
  {
    if ( v11 != 20 )
    {
      out_rulSizeSkipped = 0;
      v7 = CAkBankReader::Skip(&this->m_BankReader, v6, &out_rulSizeSkipped, v5);
      if ( v7 != 1 )
        goto LABEL_11;
      if ( out_rulSizeSkipped != v6 )
      {
        v7 = 56;
        goto LABEL_11;
      }
    }
    if ( in_rBankHeader->dwBankGeneratorVersion != 88 )
      v7 = 64;
  }
LABEL_11:
  this->m_bFeedbackInBank = in_rBankHeader->bFeedbackInBank != 0;
  return v7;
}

// File Line: 1994
// RVA: 0xA5F750
unsigned int __fastcall CAkBankMgr::ProcessDataChunk(
        CAkBankMgr *this,
        unsigned int in_dwDataChunkSize,
        CAkUsageSlot *in_pUsageSlot)
{
  unsigned __int64 v4; // rdi
  unsigned int result; // eax
  int Pool; // eax
  char PoolAttributes; // al
  int m_memPoolId; // ecx
  char *Block; // rax
  char *m_pData; // rdx
  unsigned int out_rulSizeRead; // [rsp+48h] [rbp+10h] BYREF

  v4 = in_dwDataChunkSize;
  if ( !in_dwDataChunkSize )
    return 1;
  if ( in_pUsageSlot->m_memPoolId == -1 )
  {
    Pool = AK::MemoryMgr::CreatePool(0i64, in_dwDataChunkSize, in_dwDataChunkSize, 9u, 0x10u);
    in_pUsageSlot->m_memPoolId = Pool;
    if ( Pool == -1 )
      return 52;
    in_pUsageSlot->m_bIsInternalPool = 1;
  }
  result = AK::MemoryMgr::CheckPoolId(in_pUsageSlot->m_memPoolId);
  if ( result != 1 )
    return result;
  PoolAttributes = AK::MemoryMgr::GetPoolAttributes(in_pUsageSlot->m_memPoolId);
  m_memPoolId = in_pUsageSlot->m_memPoolId;
  if ( (PoolAttributes & 8) != 0 )
  {
    if ( AK::MemoryMgr::GetBlockSize(m_memPoolId) < (unsigned int)v4 )
      goto LABEL_13;
    Block = (char *)AK::MemoryMgr::GetBlock(in_pUsageSlot->m_memPoolId);
  }
  else
  {
    Block = (char *)AK::MemoryMgr::Malloc(m_memPoolId, v4);
  }
  in_pUsageSlot->m_pData = Block;
LABEL_13:
  m_pData = in_pUsageSlot->m_pData;
  if ( !m_pData )
    return 52;
  in_pUsageSlot->m_uLoadedDataSize = v4;
  out_rulSizeRead = 0;
  result = CAkBankReader::FillData(&this->m_BankReader, m_pData, v4, &out_rulSizeRead);
  if ( result == 1 && out_rulSizeRead != (_DWORD)v4 )
    return 7;
  return result;
}

// File Line: 2089
// RVA: 0xA5FD70
__int64 __fastcall CAkBankMgr::ProcessHircChunk(
        CAkBankMgr *this,
        CAkUsageSlot *in_pUsageSlot,
        unsigned int in_dwBankID)
{
  AKRESULT v6; // ebx
  unsigned int v7; // eax
  bool v8; // cf
  bool v9; // r14
  int v10; // r15d
  __int64 v11; // r9
  CAkIndexItem<CAkFxShareSet *> *NodeLock; // rax
  CAkIndexItem<CAkFxShareSet *> *v13; // rax
  CAkIndexItem<CAkFxShareSet *> *v14; // rax
  CAkIndexItem<CAkFxShareSet *> *v15; // rax
  CAkIndexItem<CAkFxShareSet *> *v16; // rax
  AkBank::AKBKSubHircSection in_rSection; // [rsp+20h] [rbp-10h] BYREF
  unsigned int in_pBufferToFill; // [rsp+70h] [rbp+40h] BYREF
  unsigned int out_rulSizeSkipped; // [rsp+88h] [rbp+58h] BYREF

  in_pBufferToFill = 0;
  v6 = (unsigned int)CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&in_pBufferToFill, 4u);
  v7 = in_pBufferToFill;
  if ( v6 == AK_Success && in_pBufferToFill )
  {
    v8 = AkArray<MapStruct<unsigned long,unsigned long>,MapStruct<unsigned long,unsigned long> const &,ArrayPoolDefault,8,AkArrayAllocatorDefault>::GrowArray(
           (AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *)&in_pUsageSlot->m_listLoadedItem,
           in_pBufferToFill);
    v7 = in_pBufferToFill;
    v6 = 2 - v8;
  }
  v9 = 0;
  v10 = 0;
  if ( v7 )
  {
    while ( 1 )
    {
      if ( v6 != AK_Success )
        return (unsigned int)v6;
      v6 = (unsigned int)CAkBankReader::FillDataEx(&this->m_BankReader, &in_rSection.eHircType, 5u);
      if ( v6 == AK_Success )
      {
        switch ( in_rSection.eHircType )
        {
          case 1:
            v6 = CAkBankMgr::ReadState(this, &in_rSection, in_pUsageSlot);
            break;
          case 2:
            v6 = (unsigned int)CAkBankMgr::ReadSourceParent<CAkSound>(this, &in_rSection, in_pUsageSlot, in_dwBankID);
            break;
          case 3:
            v6 = CAkBankMgr::ReadAction(this, &in_rSection, in_pUsageSlot);
            break;
          case 4:
            v6 = CAkBankMgr::ReadEvent(this, &in_rSection, in_pUsageSlot);
            break;
          case 5:
            NodeLock = (CAkIndexItem<CAkFxShareSet *> *)CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Default);
            v6 = (unsigned int)CAkBankMgr::StdBankRead<CAkRanSeqCntr,CAkParameterNodeBase>(
                                 this,
                                 &in_rSection,
                                 in_pUsageSlot,
                                 NodeLock);
            break;
          case 6:
            v13 = (CAkIndexItem<CAkFxShareSet *> *)CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Default);
            v6 = (unsigned int)CAkBankMgr::StdBankRead<CAkSwitchCntr,CAkParameterNodeBase>(
                                 this,
                                 &in_rSection,
                                 in_pUsageSlot,
                                 v13);
            break;
          case 7:
            v15 = (CAkIndexItem<CAkFxShareSet *> *)CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Default);
            v6 = (unsigned int)CAkBankMgr::StdBankRead<CAkActorMixer,CAkParameterNodeBase>(
                                 this,
                                 &in_rSection,
                                 in_pUsageSlot,
                                 v15);
            break;
          case 8:
            v6 = (unsigned int)CAkBankMgr::ReadBus(this, &in_rSection, in_pUsageSlot);
            break;
          case 9:
            v14 = (CAkIndexItem<CAkFxShareSet *> *)CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Default);
            v6 = (unsigned int)CAkBankMgr::StdBankRead<CAkLayerCntr,CAkParameterNodeBase>(
                                 this,
                                 &in_rSection,
                                 in_pUsageSlot,
                                 v14);
            break;
          case 0xE:
            v6 = (unsigned int)CAkBankMgr::StdBankRead<CAkAttenuation,CAkAttenuation>(
                                 this,
                                 &in_rSection,
                                 in_pUsageSlot,
                                 (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxAttenuations);
            break;
          case 0xF:
            v6 = (unsigned int)CAkBankMgr::StdBankRead<CAkDialogueEvent,CAkDialogueEvent>(
                                 this,
                                 &in_rSection,
                                 in_pUsageSlot,
                                 (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxDialogueEvents);
            break;
          case 0x10:
            v16 = (CAkIndexItem<CAkFxShareSet *> *)CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Bus);
            v6 = (unsigned int)CAkBankMgr::StdBankRead<CAkFeedbackBus,CAkParameterNodeBase>(
                                 this,
                                 &in_rSection,
                                 in_pUsageSlot,
                                 v16);
            break;
          case 0x11:
            v6 = (unsigned int)CAkBankMgr::ReadSourceParent<CAkFeedbackNode>(
                                 this,
                                 &in_rSection,
                                 in_pUsageSlot,
                                 in_dwBankID);
            break;
          case 0x12:
            v6 = (unsigned int)CAkBankMgr::StdBankRead<CAkFxShareSet,CAkFxShareSet>(
                                 this,
                                 &in_rSection,
                                 in_pUsageSlot,
                                 &g_pIndex->m_idxFxShareSets);
            break;
          case 0x13:
            v6 = (unsigned int)CAkBankMgr::StdBankRead<CAkFxCustom,CAkFxCustom>(
                                 this,
                                 &in_rSection,
                                 in_pUsageSlot,
                                 (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxFxCustom);
            break;
          case 0x14:
            v6 = CAkBankMgr::ReadAuxBus(this, &in_rSection, in_pUsageSlot);
            break;
          default:
            if ( !g_pExternalBankHandlerCallback )
            {
              if ( !v9 )
                v9 = (unsigned __int8)(in_rSection.eHircType - 10) <= 3u;
LABEL_29:
              out_rulSizeSkipped = 0;
              CAkBankReader::Skip(&this->m_BankReader, in_rSection.dwSectionSize, &out_rulSizeSkipped, v11);
              if ( out_rulSizeSkipped != in_rSection.dwSectionSize )
                v6 = AK_InvalidFile;
              break;
            }
            v6 = g_pExternalBankHandlerCallback(&in_rSection, in_pUsageSlot, in_dwBankID);
            if ( v6 == AK_PartialSuccess )
              goto LABEL_29;
            break;
        }
      }
      if ( ++v10 >= in_pBufferToFill )
        return (unsigned int)v6;
    }
  }
  return (unsigned int)v6;
}

// File Line: 2224
// RVA: 0xA60100
signed __int64 __fastcall CAkBankMgr::ProcessStringMappingChunk(
        CAkBankMgr *this,
        unsigned int in_dwDataChunkSize,
        CAkUsageSlot *__formal)
{
  unsigned int v3; // esi
  unsigned int v5; // edi
  signed __int64 result; // rax
  int v7; // r14d
  __int64 v8; // r9
  AkHashList<unsigned long,char *,31>::Item *v9; // rax
  char *v10; // rax
  char *v11; // rbx
  AkHashList<unsigned long,char *,31>::Item *v12; // rax
  char **p_item; // rax
  unsigned int out_rulSizeSkipped; // [rsp+20h] [rbp-28h] BYREF
  char in_pBufferToFill[4]; // [rsp+28h] [rbp-20h] BYREF
  unsigned int v16; // [rsp+2Ch] [rbp-1Ch]
  unsigned __int8 v17; // [rsp+58h] [rbp+10h] BYREF
  unsigned int in_Key; // [rsp+68h] [rbp+20h] BYREF

  v3 = in_dwDataChunkSize;
  v5 = 1;
  if ( !in_dwDataChunkSize )
    return 1i64;
  do
  {
    if ( v5 != 1 )
      break;
    result = CAkBankReader::FillDataEx(&this->m_BankReader, in_pBufferToFill, 8u);
    v5 = result;
    if ( (_DWORD)result != 1 )
      return result;
    v7 = 0;
    v3 -= 8;
    if ( v16 )
    {
      do
      {
        v5 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&in_Key, 4u);
        if ( v5 != 1 )
          break;
        v3 -= 4;
        v5 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&v17, 1u);
        if ( v5 != 1 )
          break;
        --v3;
        v9 = this->m_BankIDToFileName.m_table[in_Key % 0x1F];
        if ( !v9 )
          goto LABEL_10;
        while ( v9->Assoc.key != in_Key )
        {
          v9 = v9->pNextItem;
          if ( !v9 )
            goto LABEL_10;
        }
        if ( v9 == (AkHashList<unsigned long,char *,31>::Item *)-16i64 )
        {
LABEL_10:
          v10 = (char *)AK::MemoryMgr::Malloc(g_DefaultPoolId, v17 + 5);
          v11 = v10;
          if ( !v10 )
          {
            v5 = 52;
            break;
          }
          v10[v17] = 46;
          v10[v17 + 1] = 98;
          v10[v17 + 2] = 110;
          v10[v17 + 3] = 107;
          v10[v17 + 4] = 0;
          v5 = CAkBankReader::FillDataEx(&this->m_BankReader, v10, v17);
          if ( v5 != 1 )
            goto LABEL_25;
          v3 -= v17;
          v12 = this->m_BankIDToFileName.m_table[in_Key % 0x1F];
          if ( !v12 )
            goto LABEL_19;
          while ( v12->Assoc.key != in_Key )
          {
            v12 = v12->pNextItem;
            if ( !v12 )
              goto LABEL_19;
          }
          p_item = &v12->Assoc.item;
          if ( !p_item )
LABEL_19:
            p_item = AkHashList<unsigned long,char *,31>::CreateEntry(&this->m_BankIDToFileName, in_Key, in_Key % 0x1F);
          if ( !p_item )
          {
            v5 = 52;
LABEL_25:
            AK::MemoryMgr::Free(g_DefaultPoolId, v11);
            break;
          }
          *p_item = v11;
        }
        else
        {
          CAkBankReader::Skip(&this->m_BankReader, v17, &out_rulSizeSkipped, v8);
          v3 -= v17;
        }
      }
      while ( ++v7 < v16 );
    }
  }
  while ( v3 );
  return v5;
}

// File Line: 2357
// RVA: 0xA5F9F0
__int64 __fastcall CAkBankMgr::ProcessGlobalSettingsChunk(CAkBankMgr *this, unsigned int in_dwDataChunkSize)
{
  unsigned int v3; // ebx
  unsigned int i; // r14d
  int v5; // esi
  unsigned int j; // esi
  unsigned int v7; // ebx
  char *v8; // rax
  AkRTPCGraphPointBase<float> *v9; // r14
  unsigned int v11; // [rsp+30h] [rbp-30h] BYREF
  unsigned int v12; // [rsp+34h] [rbp-2Ch] BYREF
  int lTransitionTime; // [rsp+38h] [rbp-28h] BYREF
  float in_pBufferToFill; // [rsp+3Ch] [rbp-24h] BYREF
  int v15; // [rsp+40h] [rbp-20h] BYREF
  unsigned int in_ulStateID2; // [rsp+44h] [rbp-1Ch] BYREF
  unsigned int in_ulStateID1; // [rsp+48h] [rbp-18h] BYREF
  unsigned int in_ulStateGroupID; // [rsp+88h] [rbp+28h] BYREF
  int v19; // [rsp+90h] [rbp+30h] BYREF
  unsigned int in_RTPC_ID; // [rsp+98h] [rbp+38h] BYREF

  v3 = 1;
  if ( in_dwDataChunkSize )
  {
    v3 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&in_pBufferToFill, 4u);
    AK::SoundEngine::SetVolumeThresholdInternal(in_pBufferToFill, AkCommandPriority_InitDefault);
    if ( v3 == 1 )
    {
      v3 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&in_ulStateGroupID, 2u);
      AK::SoundEngine::SetMaxNumVoicesLimitInternal(in_ulStateGroupID, AkCommandPriority_InitDefault);
    }
    v11 = 0;
    if ( v3 == 1 )
    {
      v3 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&v11, 4u);
      if ( v3 == 1 )
      {
        for ( i = 0; i < v11; ++i )
        {
          in_ulStateGroupID = 0;
          lTransitionTime = 0;
          in_RTPC_ID = 0;
          v3 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&in_ulStateGroupID, 4u);
          if ( v3 != 1 )
            break;
          v3 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&lTransitionTime, 4u);
          if ( v3 != 1 )
            break;
          v3 = 2 - ((unsigned int)CAkStateMgr::AddStateGroup(g_pStateMgr, in_ulStateGroupID) != 0);
          if ( v3 != 1 )
            break;
          v3 = CAkStateMgr::SetdefaultTransitionTime(g_pStateMgr, in_ulStateGroupID, lTransitionTime);
          if ( v3 != 1 )
            break;
          v3 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&in_RTPC_ID, 4u);
          if ( v3 != 1 )
            break;
          v5 = 0;
          if ( in_RTPC_ID )
          {
            do
            {
              v3 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&in_ulStateID1, 4u);
              if ( v3 != 1 )
                goto LABEL_19;
              v3 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&in_ulStateID2, 4u);
              if ( v3 != 1 )
                goto LABEL_19;
              v3 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&v15, 4u);
              if ( v3 != 1 )
                goto LABEL_19;
              v3 = CAkStateMgr::AddStateTransition(g_pStateMgr, in_ulStateGroupID, in_ulStateID1, in_ulStateID2, v15, 0);
              if ( v3 != 1 )
                goto LABEL_19;
            }
            while ( ++v5 < in_RTPC_ID );
          }
        }
LABEL_19:
        v12 = 0;
        if ( v3 == 1 )
        {
          v3 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&v12, 4u);
          if ( v3 == 1 )
          {
            for ( j = 0; j < v12; ++j )
            {
              v3 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&in_ulStateID1, 4u);
              if ( v3 != 1 )
                break;
              v3 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&in_RTPC_ID, 4u);
              if ( v3 != 1 )
                break;
              v3 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&in_ulStateGroupID, 4u);
              if ( v3 != 1 )
                break;
              if ( in_ulStateGroupID )
              {
                v7 = 12 * in_ulStateGroupID;
                v8 = (char *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 12 * in_ulStateGroupID);
                v9 = (AkRTPCGraphPointBase<float> *)v8;
                if ( !v8 )
                {
                  v3 = 52;
                  break;
                }
                v3 = CAkBankReader::FillDataEx(&this->m_BankReader, v8, v7);
                if ( v3 == 1 )
                  v3 = CAkRTPCMgr::AddSwitchRTPC(g_pRTPCMgr, in_ulStateID1, in_RTPC_ID, v9, in_ulStateGroupID);
                AK::MemoryMgr::Free(g_DefaultPoolId, v9);
                if ( v3 != 1 )
                  break;
              }
            }
          }
        }
        v19 = 0;
        if ( v3 == 1 )
        {
          v3 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&v19, 4u);
          if ( v3 == 1 )
          {
            for ( ; v19; --v19 )
            {
              v3 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&in_RTPC_ID, 4u);
              if ( v3 != 1 )
                break;
              v3 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&in_ulStateGroupID, 4u);
              if ( v3 != 1 )
                break;
              CAkRTPCMgr::SetDefaultParamValue(g_pRTPCMgr, in_RTPC_ID, *(float *)&in_ulStateGroupID);
            }
          }
        }
      }
    }
  }
  return v3;
}

// File Line: 2527
// RVA: 0xA5F840
__int64 __fastcall CAkBankMgr::ProcessEnvSettingsChunk(CAkBankMgr *this, unsigned int in_dwDataChunkSize)
{
  int v4; // r15d
  __int64 v5; // r12
  int v6; // edi
  __int64 v7; // rbp
  unsigned int v8; // ebx
  char *v9; // rax
  AkRTPCGraphPointBase<float> *in_paPoints; // rsi
  unsigned __int16 v11[8]; // [rsp+30h] [rbp-38h] BYREF
  char in_pBufferToFill; // [rsp+80h] [rbp+18h] BYREF
  unsigned __int8 v13; // [rsp+88h] [rbp+20h] BYREF

  if ( !g_pStateMgr )
    return 2i64;
  if ( in_dwDataChunkSize )
  {
    v4 = 0;
    v5 = 0i64;
LABEL_5:
    v6 = 0;
    v7 = 0i64;
    while ( 1 )
    {
      v8 = CAkBankReader::FillDataEx(&this->m_BankReader, &in_pBufferToFill, 1u);
      if ( v8 != 1 )
        break;
      g_pEnvironmentMgr->m_bCurveEnabled[v5][v7] = in_pBufferToFill != 0;
      v8 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)&v13, 1u);
      if ( v8 != 1 )
        break;
      v8 = CAkBankReader::FillDataEx(&this->m_BankReader, (char *)v11, 2u);
      if ( v8 != 1 )
        break;
      v9 = (char *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 12i64 * v11[0]);
      in_paPoints = (AkRTPCGraphPointBase<float> *)v9;
      if ( !v9 )
        return 52;
      v8 = CAkBankReader::FillDataEx(&this->m_BankReader, v9, 12 * (unsigned int)v11[0]);
      if ( v8 == 1 )
        CAkEnvironmentsMgr::SetObsOccCurve(
          g_pEnvironmentMgr,
          (CAkEnvironmentsMgr::eCurveXType)v4,
          (CAkEnvironmentsMgr::eCurveYType)v6,
          v11[0],
          in_paPoints,
          (AkCurveScaling)v13);
      AK::MemoryMgr::Free(g_DefaultPoolId, in_paPoints);
      if ( v8 != 1 )
        return v8;
      ++v6;
      ++v7;
      if ( v6 >= 2 )
      {
        ++v4;
        ++v5;
        if ( v4 < 2 )
          goto LABEL_5;
        return v8;
      }
    }
  }
  else
  {
    return 2;
  }
  return v8;
}

// File Line: 2602
// RVA: 0xA60870
__int64 __fastcall CAkBankMgr::ReadState(
        CAkBankMgr *this,
        AkBank::AKBKSubHircSection *in_rSection,
        CAkUsageSlot *in_pUsageSlot)
{
  AKRESULT v6; // ebx
  unsigned int *Data; // rax
  char *v8; // r14
  unsigned int v10; // ebp
  CAkIndexable *PtrAndAddRef; // rdi
  CAkState *v12; // rax
  __int64 m_uLength; // rdx
  CAkIndexable **v14; // r8

  v6 = AK_Success;
  Data = (unsigned int *)CAkBankReader::GetData(&this->m_BankReader, in_rSection->dwSectionSize);
  v8 = (char *)Data;
  if ( !Data )
    return 2i64;
  v10 = *Data;
  PtrAndAddRef = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                   (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxCustomStates,
                   *Data);
  if ( PtrAndAddRef )
    goto LABEL_9;
  EnterCriticalSection(&g_csMain.m_csLock);
  v12 = CAkState::Create(v10);
  PtrAndAddRef = v12;
  if ( v12 )
  {
    v6 = CAkState::SetInitialValues(v12, v8, in_rSection->dwSectionSize);
    if ( v6 != AK_Success )
      PtrAndAddRef->vfptr->Release(PtrAndAddRef);
  }
  else
  {
    v6 = AK_Fail;
  }
  LeaveCriticalSection(&g_csMain.m_csLock);
  if ( v6 == AK_Success )
  {
LABEL_9:
    m_uLength = in_pUsageSlot->m_listLoadedItem.m_uLength;
    if ( (unsigned int)m_uLength < in_pUsageSlot->m_listLoadedItem.m_ulReserved )
    {
      v14 = &in_pUsageSlot->m_listLoadedItem.m_pItems[m_uLength];
      in_pUsageSlot->m_listLoadedItem.m_uLength = m_uLength + 1;
      if ( v14 )
        *v14 = PtrAndAddRef;
    }
  }
  CAkBankReader::ReleaseData(&this->m_BankReader);
  return (unsigned int)v6;
}

// File Line: 2646
// RVA: 0xA60640
signed __int64 __fastcall CAkBankMgr::ReadBus(
        CAkBankMgr *this,
        AkBank::AKBKSubHircSection *in_rSection,
        CAkUsageSlot *in_pUsageSlot)
{
  unsigned int v6; // ebx
  unsigned int *Data; // rax
  unsigned int *v8; // r15
  unsigned int v10; // r14d
  CAkParameterNodeBase *NodePtrAndAddRef; // rdi
  CAkBus *v12; // rax
  __int64 m_uLength; // rdx
  CAkIndexable **v14; // r8

  v6 = 1;
  Data = (unsigned int *)CAkBankReader::GetData(&this->m_BankReader, in_rSection->dwSectionSize);
  v8 = Data;
  if ( !Data )
    return 2i64;
  v10 = *Data;
  NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, *Data, AkNodeType_Bus);
  if ( NodePtrAndAddRef )
    goto LABEL_11;
  if ( !this->m_bIsFirstBusLoaded )
    CAkBus::ClearMasterBus();
  EnterCriticalSection(&g_csMain.m_csLock);
  v12 = CAkBus::Create(v10);
  NodePtrAndAddRef = v12;
  if ( v12 )
  {
    v6 = ((__int64 (__fastcall *)(CAkBus *, unsigned int *, _QWORD))v12->vfptr[20].AddRef)(
           v12,
           v8,
           in_rSection->dwSectionSize);
    if ( v6 != 1 )
      NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef);
  }
  else
  {
    v6 = 2;
  }
  LeaveCriticalSection(&g_csMain.m_csLock);
  if ( v6 == 1 )
  {
LABEL_11:
    m_uLength = in_pUsageSlot->m_listLoadedItem.m_uLength;
    if ( (unsigned int)m_uLength < in_pUsageSlot->m_listLoadedItem.m_ulReserved )
    {
      v14 = &in_pUsageSlot->m_listLoadedItem.m_pItems[m_uLength];
      in_pUsageSlot->m_listLoadedItem.m_uLength = m_uLength + 1;
      if ( v14 )
        *v14 = NodePtrAndAddRef;
    }
    this->m_bIsFirstBusLoaded = 1;
  }
  CAkBankReader::ReleaseData(&this->m_BankReader);
  return v6;
}

// File Line: 2701
// RVA: 0xA60540
__int64 __fastcall CAkBankMgr::ReadAuxBus(
        CAkBankMgr *this,
        AkBank::AKBKSubHircSection *in_rSection,
        CAkUsageSlot *in_pUsageSlot)
{
  unsigned int v6; // ebx
  unsigned int *Data; // rax
  unsigned int *v8; // r14
  unsigned int v10; // ebp
  CAkParameterNodeBase *NodePtrAndAddRef; // rdi
  CAkAuxBus *v12; // rax
  __int64 m_uLength; // rdx
  CAkIndexable **v14; // r8

  v6 = 1;
  Data = (unsigned int *)CAkBankReader::GetData(&this->m_BankReader, in_rSection->dwSectionSize);
  v8 = Data;
  if ( !Data )
    return 2i64;
  v10 = *Data;
  NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, *Data, AkNodeType_Bus);
  if ( NodePtrAndAddRef )
    goto LABEL_9;
  EnterCriticalSection(&g_csMain.m_csLock);
  v12 = CAkAuxBus::Create(v10);
  NodePtrAndAddRef = v12;
  if ( v12 )
  {
    v6 = ((__int64 (__fastcall *)(CAkAuxBus *, unsigned int *, _QWORD))v12->vfptr[20].AddRef)(
           v12,
           v8,
           in_rSection->dwSectionSize);
    if ( v6 != 1 )
      NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef);
  }
  else
  {
    v6 = 2;
  }
  LeaveCriticalSection(&g_csMain.m_csLock);
  if ( v6 == 1 )
  {
LABEL_9:
    m_uLength = in_pUsageSlot->m_listLoadedItem.m_uLength;
    if ( (unsigned int)m_uLength < in_pUsageSlot->m_listLoadedItem.m_ulReserved )
    {
      v14 = &in_pUsageSlot->m_listLoadedItem.m_pItems[m_uLength];
      in_pUsageSlot->m_listLoadedItem.m_uLength = m_uLength + 1;
      if ( v14 )
        *v14 = NodePtrAndAddRef;
    }
  }
  CAkBankReader::ReleaseData(&this->m_BankReader);
  return v6;
}

// File Line: 2744
// RVA: 0xA603F0
__int64 __fastcall CAkBankMgr::ReadAction(
        CAkBankMgr *this,
        AkBank::AKBKSubHircSection *in_rSection,
        CAkUsageSlot *in_pUsageSlot)
{
  AKRESULT v6; // ebx
  char *Data; // rax
  char *v8; // r14
  AkActionType v10; // ebp
  unsigned int v11; // r12d
  CAkIndexable *PtrAndAddRef; // rax
  CAkAction *v13; // rdi
  CAkAction *v14; // rax
  __int64 m_uLength; // rdx
  CAkIndexable **v16; // r8

  v6 = AK_Success;
  Data = CAkBankReader::GetData(&this->m_BankReader, in_rSection->dwSectionSize);
  v8 = Data;
  if ( !Data )
    return 2i64;
  v10 = *((unsigned __int16 *)Data + 2);
  v11 = *(_DWORD *)Data;
  PtrAndAddRef = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                   (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxActions,
                   *(_DWORD *)Data);
  v13 = (CAkAction *)PtrAndAddRef;
  if ( PtrAndAddRef )
  {
    if ( v10 != AkActionType_Play || (BYTE6(PtrAndAddRef[2].vfptr) & 0x20) != 0 )
    {
LABEL_13:
      m_uLength = in_pUsageSlot->m_listLoadedItem.m_uLength;
      if ( (unsigned int)m_uLength < in_pUsageSlot->m_listLoadedItem.m_ulReserved )
      {
        v16 = &in_pUsageSlot->m_listLoadedItem.m_pItems[m_uLength];
        in_pUsageSlot->m_listLoadedItem.m_uLength = m_uLength + 1;
        if ( v16 )
          *v16 = v13;
      }
      goto LABEL_16;
    }
    EnterCriticalSection(&g_csMain.m_csLock);
    v6 = CAkAction::SetInitialValues(v13, v8, in_rSection->dwSectionSize);
    if ( v6 != AK_Success )
LABEL_11:
      v13->vfptr->Release(v13);
  }
  else
  {
    EnterCriticalSection(&g_csMain.m_csLock);
    v14 = CAkAction::Create(v10, v11);
    v13 = v14;
    if ( !v14 )
    {
      v6 = AK_Fail;
      goto LABEL_12;
    }
    v6 = CAkAction::SetInitialValues(v14, v8, in_rSection->dwSectionSize);
    if ( v6 != AK_Success )
      goto LABEL_11;
  }
LABEL_12:
  LeaveCriticalSection(&g_csMain.m_csLock);
  if ( v6 == AK_Success )
    goto LABEL_13;
LABEL_16:
  CAkBankReader::ReleaseData(&this->m_BankReader);
  return (unsigned int)v6;
}

// File Line: 2805
// RVA: 0xA60760
__int64 __fastcall CAkBankMgr::ReadEvent(
        CAkBankMgr *this,
        AkBank::AKBKSubHircSection *in_rSection,
        CAkUsageSlot *in_pUsageSlot)
{
  AKRESULT v6; // ebx
  unsigned int *Data; // rax
  char *v8; // r14
  unsigned int v10; // ebp
  CAkEvent *PtrAndAddRef; // rdi
  __int64 m_uLength; // rdx
  CAkIndexable **v13; // r8

  v6 = AK_Success;
  Data = (unsigned int *)CAkBankReader::GetData(&this->m_BankReader, in_rSection->dwSectionSize);
  v8 = (char *)Data;
  if ( !Data )
    return 2i64;
  v10 = *Data;
  PtrAndAddRef = (CAkEvent *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                               (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxEvents,
                               *Data);
  if ( PtrAndAddRef )
  {
LABEL_10:
    m_uLength = in_pUsageSlot->m_listLoadedItem.m_uLength;
    if ( (unsigned int)m_uLength < in_pUsageSlot->m_listLoadedItem.m_ulReserved )
    {
      v13 = &in_pUsageSlot->m_listLoadedItem.m_pItems[m_uLength];
      in_pUsageSlot->m_listLoadedItem.m_uLength = m_uLength + 1;
      if ( v13 )
        *v13 = PtrAndAddRef;
    }
    goto LABEL_13;
  }
  PtrAndAddRef = CAkEvent::CreateNoIndex(v10);
  if ( PtrAndAddRef )
  {
    EnterCriticalSection(&g_csMain.m_csLock);
    v6 = CAkEvent::SetInitialValues(PtrAndAddRef, v8, in_rSection->dwSectionSize);
    if ( v6 == AK_Success )
      CAkEvent::AddToIndex(PtrAndAddRef);
    else
      PtrAndAddRef->vfptr->Release(PtrAndAddRef);
    LeaveCriticalSection(&g_csMain.m_csLock);
    if ( v6 != AK_Success )
      goto LABEL_13;
    goto LABEL_10;
  }
  v6 = AK_Fail;
LABEL_13:
  CAkBankReader::ReleaseData(&this->m_BankReader);
  return (unsigned int)v6;
}

// File Line: 2858
// RVA: 0xA5CDC0
void __fastcall CAkBankMgr::ClearPreparedEvents(CAkBankMgr *this)
{
  CAkIndexItem<CAkEvent *> *p_m_idxEvents; // r13
  CAkIndexable *i; // r14
  __int64 v4; // rsi
  CAkIndexable *v5; // r15
  CAkIndexableVtbl *vfptr; // rbx
  CAkIndexableVtbl *v7; // rdi
  CAkUsageSlot *v8; // rax
  unsigned __int64 v9; // [rsp+20h] [rbp-48h]
  unsigned __int128 v10; // [rsp+30h] [rbp-38h] BYREF

  p_m_idxEvents = &g_pIndex->m_idxEvents;
  EnterCriticalSection(&g_csMain.m_csLock);
  EnterCriticalSection(&p_m_idxEvents->m_IndexLock.m_csLock);
  i = p_m_idxEvents->m_mapIDToPtr.m_table[0];
  LODWORD(v4) = 0;
  if ( i )
  {
    while ( 1 )
    {
LABEL_6:
      while ( 1 )
      {
        v5 = i;
        if ( !LODWORD(i[1].pNextItem) )
          break;
        i->vfptr->AddRef(i);
        if ( LODWORD(i[1].pNextItem) )
        {
          vfptr = i[1].vfptr;
          LODWORD(i[1].pNextItem) = 0;
          while ( vfptr )
          {
            v7 = vfptr;
            vfptr = (CAkIndexableVtbl *)vfptr->Category;
            if ( WORD2(v7[1].Release) == 1027 )
            {
              CAkParameterNodeBase::UnPrepareNodeData((unsigned int)v7[1].Release);
              LODWORD(v9) = v7[1].Category;
              v10 = v9;
              v8 = CAkBankList::Get(&this->m_BankList, (AkBankKey *)&v10);
              if ( v8 )
                CAkUsageSlot::ReleasePrepare(v8, 0);
            }
          }
          i->vfptr->Release(i);
        }
        for ( i = i->pNextItem; !i; i = p_m_idxEvents->m_mapIDToPtr.m_table[v4] )
        {
          v4 = (unsigned int)(v4 + 1);
          if ( (unsigned int)v4 >= 0xC1 )
            break;
        }
        v5->vfptr->Release(v5);
LABEL_18:
        if ( !i )
          goto LABEL_19;
      }
      i = i->pNextItem;
      if ( !i )
      {
        while ( 1 )
        {
          v4 = (unsigned int)(v4 + 1);
          if ( (unsigned int)v4 >= 0xC1 )
            goto LABEL_18;
          i = p_m_idxEvents->m_mapIDToPtr.m_table[v4];
          if ( i )
            goto LABEL_6;
        }
      }
    }
  }
  while ( 1 )
  {
    v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= 0xC1 )
      break;
    i = p_m_idxEvents->m_mapIDToPtr.m_table[v4];
    if ( i )
      goto LABEL_6;
  }
LABEL_19:
  LeaveCriticalSection(&p_m_idxEvents->m_IndexLock.m_csLock);
  LeaveCriticalSection(&g_csMain.m_csLock);
}

// File Line: 2887
// RVA: 0xA5E360
signed __int64 __fastcall CAkBankMgr::LoadMediaIndex(
        CAkBankMgr *this,
        CAkUsageSlot *in_pCurrentSlot,
        unsigned int in_uIndexChunkSize,
        __int64 in_bIsLoadedFromMemory)
{
  unsigned int v6; // edi
  signed __int64 result; // rax
  unsigned int v8; // r14d
  unsigned int v9; // ebp
  AkBank::MediaHeader *v10; // rax
  char *Data; // rax
  unsigned int out_rulSizeSkipped; // [rsp+48h] [rbp+10h] BYREF

  v6 = 1;
  if ( in_pCurrentSlot->m_uNumLoadedItems )
  {
    CAkBankReader::Skip(&this->m_BankReader, in_uIndexChunkSize, &out_rulSizeSkipped, in_bIsLoadedFromMemory);
    return 1i64;
  }
  else
  {
    v8 = in_uIndexChunkSize / 0xC;
    v9 = 12 * (in_uIndexChunkSize / 0xC);
    if ( (_BYTE)in_bIsLoadedFromMemory )
    {
      Data = CAkBankReader::GetData(&this->m_BankReader, v9);
      if ( !in_pCurrentSlot->m_paLoadedMedia )
        in_pCurrentSlot->m_paLoadedMedia = (AkBank::MediaHeader *)Data;
      CAkBankReader::ReleaseData(&this->m_BankReader);
    }
    else
    {
      v10 = (AkBank::MediaHeader *)AK::MemoryMgr::Malloc(g_DefaultPoolId, v9);
      in_pCurrentSlot->m_paLoadedMedia = v10;
      if ( v10 )
      {
        *((_BYTE *)in_pCurrentSlot + 112) |= 2u;
        CAkBankReader::FillDataEx(&this->m_BankReader, (char *)v10, v9);
      }
      else
      {
        v6 = 52;
      }
    }
    result = v6;
    if ( in_pCurrentSlot->m_paLoadedMedia )
      in_pCurrentSlot->m_uIndexSize = v8;
  }
  return result;
}

// File Line: 2939
// RVA: 0xA5E1B0
signed __int64 __fastcall CAkBankMgr::LoadMedia(
        CAkBankMgr *this,
        char *in_pDataBank,
        CAkUsageSlot *in_pCurrentSlot,
        bool __formal)
{
  unsigned int v6; // r12d
  __int64 v7; // rbp
  AkBank::MediaHeader *v8; // r15
  unsigned int id; // ecx
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v10; // rax
  char v11; // r14
  AkMediaEntry *p_item; // rdi

  if ( in_pCurrentSlot->m_uNumLoadedItems || !in_pCurrentSlot->m_uIndexSize )
    return 1i64;
  v6 = 52;
  if ( !in_pCurrentSlot->m_paLoadedMedia )
    goto LABEL_25;
  v7 = 0i64;
  while ( 1 )
  {
    v8 = &in_pCurrentSlot->m_paLoadedMedia[v7];
    if ( v8->id )
      break;
LABEL_15:
    ++in_pCurrentSlot->m_uNumLoadedItems;
    v7 = (unsigned int)(v7 + 1);
    if ( (unsigned int)v7 >= in_pCurrentSlot->m_uIndexSize )
      goto LABEL_22;
  }
  EnterCriticalSection(&this->m_MediaLock.m_csLock);
  id = v8->id;
  v10 = this->m_MediaHashTable.m_table[v8->id % 193];
  if ( !v10 )
    goto LABEL_9;
  while ( v10->Assoc.key != id )
  {
    v10 = v10->pNextItem;
    if ( !v10 )
      goto LABEL_9;
  }
  p_item = &v10->Assoc.item;
  if ( v10 == (AkHashList<unsigned long,AkMediaEntry,193>::Item *)-16i64 )
  {
LABEL_9:
    v11 = 0;
    p_item = AkHashList<unsigned long,AkMediaEntry,193>::CreateEntry(&this->m_MediaHashTable, id, v8->id % 193);
  }
  else
  {
    v11 = 1;
    if ( p_item->m_preparedMediaInfo.pInMemoryData )
      goto LABEL_13;
  }
  if ( !p_item )
    goto LABEL_21;
  p_item->m_sourceID = v8->id;
  v6 = AkMediaEntry::AddAlternateBank(p_item, &in_pDataBank[v8->uOffset], v8->uSize, in_pCurrentSlot);
  if ( v6 == 1 )
  {
    if ( !v11 )
    {
LABEL_14:
      LeaveCriticalSection(&this->m_MediaLock.m_csLock);
      goto LABEL_15;
    }
LABEL_13:
    ++p_item->uRefCount;
    goto LABEL_14;
  }
  AkHashList<unsigned long,AkMediaEntry,193>::Unset(&this->m_MediaHashTable, v8->id);
LABEL_21:
  LeaveCriticalSection(&this->m_MediaLock.m_csLock);
LABEL_22:
  if ( in_pCurrentSlot->m_uIndexSize == (_DWORD)v7 )
    return 1i64;
  if ( v6 != 1 )
LABEL_25:
    CAkBankMgr::UnloadMedia(this, in_pCurrentSlot);
  return v6;
}

// File Line: 3011
// RVA: 0xA5F1A0
__int64 __fastcall CAkBankMgr::PrepareMedia(
        CAkBankMgr *this,
        CAkUsageSlot *in_pCurrentSlot,
        unsigned int in_dwDataChunkSize,
        __int64 a4)
{
  CAkBankMgr *v5; // r15
  unsigned int v6; // esi
  CAkLock *p_m_MediaLock; // rbx
  int v8; // edx
  unsigned int m_uIndexSize; // eax
  unsigned int v10; // r12d
  __int64 v11; // rcx
  unsigned int *v12; // rcx
  unsigned int v13; // r14d
  unsigned int v14; // eax
  unsigned __int64 v15; // r13
  unsigned __int64 v16; // r8
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v17; // rax
  AkMediaEntry *p_item; // rdi
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v19; // rax
  char *v20; // rax
  char *v21; // r15
  __int64 v22; // r9
  unsigned int v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // r12d
  __int64 v26; // rdi
  unsigned int id; // edx
  bool v28; // zf
  int v30; // [rsp+20h] [rbp-48h]
  unsigned int out_rulSizeSkipped; // [rsp+24h] [rbp-44h] BYREF
  __int64 v32; // [rsp+28h] [rbp-40h]
  unsigned int v34; // [rsp+80h] [rbp+18h] BYREF
  int v35; // [rsp+88h] [rbp+20h]

  v34 = in_dwDataChunkSize;
  v5 = this;
  v6 = 1;
  if ( !in_dwDataChunkSize )
    return v6;
  LODWORD(p_m_MediaLock) = 0;
  v8 = 0;
  m_uIndexSize = in_pCurrentSlot->m_uIndexSize;
  v10 = 0;
  v30 = 0;
  v35 = 0;
  if ( in_pCurrentSlot->m_uNumLoadedItems < m_uIndexSize )
  {
    v11 = 0i64;
    v32 = 0i64;
    while ( 1 )
    {
      v12 = (unsigned int *)((char *)&in_pCurrentSlot->m_paLoadedMedia->id + v11);
      v13 = *v12;
      v14 = v12[1] - v8;
      v8 = v12[1];
      v10 += v14;
      v35 = v8;
      if ( v13 )
        break;
      ++in_pCurrentSlot->m_uNumLoadedItems;
LABEL_38:
      v24 = in_pCurrentSlot->m_uIndexSize;
      ++v30;
      v11 = v32 + 12;
      v32 += 12i64;
      if ( in_pCurrentSlot->m_uNumLoadedItems >= v24 )
      {
        LODWORD(p_m_MediaLock) = v30;
        in_dwDataChunkSize = v34;
        goto LABEL_40;
      }
    }
    v15 = v12[2];
    p_m_MediaLock = &v5->m_MediaLock;
    EnterCriticalSection(&v5->m_MediaLock.m_csLock);
    v16 = v13 % 0xC1;
    v17 = v5->m_MediaHashTable.m_table[v16];
    if ( v17 )
    {
      while ( v17->Assoc.key != v13 )
      {
        v17 = v17->pNextItem;
        if ( !v17 )
          goto LABEL_9;
      }
      p_item = &v17->Assoc.item;
    }
    else
    {
LABEL_9:
      p_item = 0i64;
    }
    if ( p_item )
    {
      ++p_item->uRefCount;
      if ( p_item->m_preparedMediaInfo.pInMemoryData )
      {
        ++in_pCurrentSlot->m_uNumLoadedItems;
        LeaveCriticalSection(&v5->m_MediaLock.m_csLock);
LABEL_37:
        v8 = v35;
        goto LABEL_38;
      }
    }
    else
    {
      v19 = v5->m_MediaHashTable.m_table[v16];
      if ( !v19 )
        goto LABEL_19;
      while ( v19->Assoc.key != v13 )
      {
        v19 = v19->pNextItem;
        if ( !v19 )
          goto LABEL_19;
      }
      p_item = &v19->Assoc.item;
      if ( v19 == (AkHashList<unsigned long,AkMediaEntry,193>::Item *)-16i64 )
      {
LABEL_19:
        p_item = AkHashList<unsigned long,AkMediaEntry,193>::CreateEntry(&v5->m_MediaHashTable, v13, v16);
        if ( !p_item )
        {
          v6 = 2;
          LeaveCriticalSection(&v5->m_MediaLock.m_csLock);
          LODWORD(p_m_MediaLock) = v30;
          goto LABEL_43;
        }
      }
      p_item->m_sourceID = v13;
    }
    if ( p_item->m_BankSlots.m_uLength )
    {
      LODWORD(v15) = p_item->m_BankSlots.m_pItems->item.uInMemoryDataSize;
      if ( g_settings.uPrepareEventMemoryPoolID == -1 )
        goto LABEL_50;
      v20 = (char *)AK::MemoryMgr::Malign(g_settings.uPrepareEventMemoryPoolID, (unsigned int)v15, 0x10u);
      v21 = v20;
      if ( !v20 )
        goto LABEL_50;
      memmove(v20, p_item->m_BankSlots.m_pItems->item.pInMemoryData, (unsigned int)v15);
      v6 = 1;
      goto LABEL_36;
    }
    if ( g_settings.uPrepareEventMemoryPoolID == -1
      || (v21 = (char *)AK::MemoryMgr::Malign(g_settings.uPrepareEventMemoryPoolID, v15, 0x10u)) == 0i64 )
    {
LABEL_50:
      v6 = 52;
LABEL_51:
      v28 = p_item->uRefCount-- == 1;
      if ( v28 && p_item->m_preparedMediaInfo.pInMemoryData )
      {
        AK::MemoryMgr::Free(g_settings.uPrepareEventMemoryPoolID, p_item->m_preparedMediaInfo.pInMemoryData);
        p_item->m_preparedMediaInfo.pInMemoryData = 0i64;
        p_item->m_preparedMediaInfo.uInMemoryDataSize = 0;
      }
      v5 = this;
      if ( !p_item->uRefCount )
        AkHashList<unsigned long,AkMediaEntry,193>::Unset(&this->m_MediaHashTable, v13);
      LeaveCriticalSection(&p_m_MediaLock->m_csLock);
      LODWORD(p_m_MediaLock) = v30;
LABEL_43:
      p_m_MediaLock = (CAkLock *)(int)p_m_MediaLock;
      if ( (int)p_m_MediaLock > 0 )
      {
        v26 = (int)p_m_MediaLock;
        do
        {
          --v26;
          p_m_MediaLock = (CAkLock *)((char *)p_m_MediaLock - 1);
          id = in_pCurrentSlot->m_paLoadedMedia[v26].id;
          if ( id )
            CAkBankMgr::ReleaseSingleMedia(v5, id);
        }
        while ( (__int64)p_m_MediaLock > 0 );
      }
      return v6;
    }
    LeaveCriticalSection(&p_m_MediaLock->m_csLock);
    if ( !v10 )
      goto LABEL_31;
    out_rulSizeSkipped = 0;
    v23 = CAkBankReader::Skip(&this->m_BankReader, v10, &out_rulSizeSkipped, v22);
    v6 = v23;
    if ( v10 != out_rulSizeSkipped )
    {
      v6 = 2;
      goto LABEL_35;
    }
    v10 = 0;
    if ( v23 == 1 )
    {
LABEL_31:
      out_rulSizeSkipped = 0;
      v6 = CAkBankReader::FillData(&this->m_BankReader, v21, v15, &out_rulSizeSkipped);
      if ( v6 != 1 || (_DWORD)v15 == out_rulSizeSkipped )
        v35 += out_rulSizeSkipped;
      else
        v6 = 2;
    }
LABEL_35:
    EnterCriticalSection(&p_m_MediaLock->m_csLock);
    if ( v6 != 1 )
    {
      AK::MemoryMgr::Free(g_settings.uPrepareEventMemoryPoolID, v21);
      goto LABEL_51;
    }
LABEL_36:
    p_item->m_preparedMediaInfo.uInMemoryDataSize = v15;
    p_item->m_preparedMediaInfo.pInMemoryData = v21;
    ++in_pCurrentSlot->m_uNumLoadedItems;
    LeaveCriticalSection(&p_m_MediaLock->m_csLock);
    v5 = this;
    goto LABEL_37;
  }
LABEL_40:
  v25 = in_dwDataChunkSize - v35 + v10;
  if ( v25 )
  {
    v5 = this;
    v34 = 0;
    CAkBankReader::Skip(&this->m_BankReader, v25, &v34, a4);
    if ( v25 != v34 )
    {
      v6 = 2;
      goto LABEL_43;
    }
  }
  *((_BYTE *)in_pCurrentSlot + 112) |= 4u;
  return v6;
}

// File Line: 3180
// RVA: 0xA61B10
void __fastcall CAkBankMgr::UnloadMedia(CAkBankMgr *this, CAkUsageSlot *in_pCurrentSlot)
{
  unsigned int id; // r8d
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v5; // r14
  __int64 v6; // rsi
  __int64 v7; // r15
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v8; // rdi
  MapStruct<CAkUsageSlot *,AkMediaInfo> *m_pItems; // rax
  __int64 m_uLength; // rdx
  MapStruct<CAkUsageSlot *,AkMediaInfo> *v11; // rcx
  char *pInMemoryData; // rdx
  AkHashList<unsigned long,AkMediaEntry,193>::Item *pNextItem; // rcx
  MapStruct<CAkUsageSlot *,AkMediaInfo> *v15; // rdx

  if ( in_pCurrentSlot->m_paLoadedMedia )
  {
    EnterCriticalSection(&this->m_MediaLock.m_csLock);
    while ( in_pCurrentSlot->m_uNumLoadedItems )
    {
      id = in_pCurrentSlot->m_paLoadedMedia[--in_pCurrentSlot->m_uNumLoadedItems].id;
      if ( id )
      {
        v5 = 0i64;
        v6 = id % 0xC1;
        v7 = v6;
        v8 = this->m_MediaHashTable.m_table[v6];
        if ( v8 )
        {
          while ( v8->Assoc.key != id )
          {
            v5 = v8;
            v8 = v8->pNextItem;
            if ( !v8 )
              goto LABEL_28;
          }
          m_pItems = v8->Assoc.item.m_BankSlots.m_pItems;
          m_uLength = v8->Assoc.item.m_BankSlots.m_uLength;
          v11 = &m_pItems[m_uLength];
          if ( m_pItems != v11 )
          {
            do
            {
              if ( m_pItems->key == in_pCurrentSlot )
                break;
              ++m_pItems;
            }
            while ( m_pItems != v11 );
            if ( m_pItems != v11 )
            {
              if ( (unsigned int)m_uLength > 1 )
              {
                m_pItems->key = v11[-1].key;
                m_pItems->item.pInMemoryData = v11[-1].item.pInMemoryData;
                *(_QWORD *)&m_pItems->item.uInMemoryDataSize = *(_QWORD *)&v11[-1].item.uInMemoryDataSize;
              }
              --v8->Assoc.item.m_BankSlots.m_uLength;
            }
          }
          if ( v8->Assoc.item.uRefCount-- == 1 )
          {
            pInMemoryData = v8->Assoc.item.m_preparedMediaInfo.pInMemoryData;
            if ( pInMemoryData )
            {
              AK::MemoryMgr::Free(g_settings.uPrepareEventMemoryPoolID, pInMemoryData);
              v8->Assoc.item.m_preparedMediaInfo.pInMemoryData = 0i64;
              v8->Assoc.item.m_preparedMediaInfo.uInMemoryDataSize = 0;
            }
          }
          if ( !v8->Assoc.item.uRefCount )
          {
            pNextItem = v8->pNextItem;
            if ( !v8->pNextItem )
            {
              do
                v6 = (unsigned int)(v6 + 1);
              while ( (unsigned int)v6 < 0xC1 && !this->m_MediaHashTable.m_table[v6] );
            }
            if ( v5 )
              v5->pNextItem = pNextItem;
            else
              this->m_MediaHashTable.m_table[v7] = pNextItem;
            v15 = v8->Assoc.item.m_BankSlots.m_pItems;
            if ( v15 )
            {
              v8->Assoc.item.m_BankSlots.m_uLength = 0;
              AK::MemoryMgr::Free(g_DefaultPoolId, v15);
              v8->Assoc.item.m_BankSlots.m_pItems = 0i64;
              v8->Assoc.item.m_BankSlots.m_ulReserved = 0;
            }
            AK::MemoryMgr::Free(this->m_MediaHashTable.m_MemPoolId, v8);
            --this->m_MediaHashTable.m_uiSize;
          }
        }
      }
LABEL_28:
      ;
    }
    LeaveCriticalSection(&this->m_MediaLock.m_csLock);
  }
}

// File Line: 3211
// RVA: 0xA615D0
void __fastcall CAkBankMgr::UnPrepareMedia(CAkBankMgr *this, CAkUsageSlot *in_pCurrentSlot)
{
  unsigned int i; // ebp
  unsigned int id; // r8d
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v6; // r14
  __int64 v7; // rsi
  __int64 v8; // r12
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v9; // rdi
  char *pInMemoryData; // rdx
  AkHashList<unsigned long,AkMediaEntry,193>::Item *pNextItem; // rcx
  MapStruct<CAkUsageSlot *,AkMediaInfo> *m_pItems; // rdx

  if ( (*((_BYTE *)in_pCurrentSlot + 112) & 4) != 0 && in_pCurrentSlot->m_paLoadedMedia )
  {
    EnterCriticalSection(&this->m_MediaLock.m_csLock);
    for ( i = 0; i < in_pCurrentSlot->m_uNumLoadedItems; ++i )
    {
      id = in_pCurrentSlot->m_paLoadedMedia[i].id;
      if ( id )
      {
        v6 = 0i64;
        v7 = id % 0xC1;
        v8 = v7;
        v9 = this->m_MediaHashTable.m_table[v7];
        if ( v9 )
        {
          while ( v9->Assoc.key != id )
          {
            v6 = v9;
            v9 = v9->pNextItem;
            if ( !v9 )
              goto LABEL_22;
          }
          if ( v9->Assoc.item.uRefCount-- == 1 )
          {
            pInMemoryData = v9->Assoc.item.m_preparedMediaInfo.pInMemoryData;
            if ( pInMemoryData )
            {
              AK::MemoryMgr::Free(g_settings.uPrepareEventMemoryPoolID, pInMemoryData);
              v9->Assoc.item.m_preparedMediaInfo.pInMemoryData = 0i64;
              v9->Assoc.item.m_preparedMediaInfo.uInMemoryDataSize = 0;
            }
          }
          if ( !v9->Assoc.item.uRefCount )
          {
            pNextItem = v9->pNextItem;
            if ( !v9->pNextItem )
            {
              do
                v7 = (unsigned int)(v7 + 1);
              while ( (unsigned int)v7 < 0xC1 && !this->m_MediaHashTable.m_table[v7] );
            }
            if ( v6 )
              v6->pNextItem = pNextItem;
            else
              this->m_MediaHashTable.m_table[v8] = pNextItem;
            m_pItems = v9->Assoc.item.m_BankSlots.m_pItems;
            if ( m_pItems )
            {
              v9->Assoc.item.m_BankSlots.m_uLength = 0;
              AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
              v9->Assoc.item.m_BankSlots.m_pItems = 0i64;
              v9->Assoc.item.m_BankSlots.m_ulReserved = 0;
            }
            AK::MemoryMgr::Free(this->m_MediaHashTable.m_MemPoolId, v9);
            --this->m_MediaHashTable.m_uiSize;
          }
        }
      }
LABEL_22:
      ;
    }
    LeaveCriticalSection(&this->m_MediaLock.m_csLock);
    *((_BYTE *)in_pCurrentSlot + 112) &= ~4u;
  }
}

// File Line: 3243
// RVA: 0xA5D6B0
AkMediaInfo *__fastcall CAkBankMgr::GetMedia(
        CAkBankMgr *this,
        AkMediaInfo *result,
        unsigned int in_mediaId,
        CAkUsageSlot **out_pUsageSlot)
{
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v8; // rax

  result->pInMemoryData = 0i64;
  result->uInMemoryDataSize = 0;
  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  EnterCriticalSection(&this->m_MediaLock.m_csLock);
  v8 = this->m_MediaHashTable.m_table[in_mediaId % 0xC1];
  if ( v8 )
  {
    while ( v8->Assoc.key != in_mediaId )
    {
      v8 = v8->pNextItem;
      if ( !v8 )
        goto LABEL_7;
    }
    if ( v8 != (AkHashList<unsigned long,AkMediaEntry,193>::Item *)-16i64 )
      AkMediaEntry::GetMedia(&v8->Assoc.item, result, out_pUsageSlot);
  }
LABEL_7:
  LeaveCriticalSection(&this->m_MediaLock.m_csLock);
  LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  return result;
}

// File Line: 3261
// RVA: 0xA60A80
void __fastcall CAkBankMgr::ReleaseMedia(CAkBankMgr *this, unsigned int in_mediaId)
{
  CAkLock *p_m_MediaLock; // rbx
  AkHashList<unsigned long,AkMediaEntry,193> *p_m_MediaHashTable; // r15
  _QWORD *v6; // r14
  __int64 v7; // rsi
  char *v8; // r12
  _DWORD *v9; // rdi
  void *v11; // rdx
  __int64 v12; // rcx
  void *v13; // rdx

  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  p_m_MediaLock = &this->m_MediaLock;
  EnterCriticalSection(&this->m_MediaLock.m_csLock);
  p_m_MediaHashTable = &this->m_MediaHashTable;
  v6 = 0i64;
  v7 = in_mediaId % 0xC1;
  v8 = (char *)&this->m_MediaHashTable + 8 * v7;
  v9 = (_DWORD *)*((_QWORD *)v8 + 1);
  if ( v9 )
  {
    while ( v9[2] != in_mediaId )
    {
      v6 = v9;
      v9 = *(_DWORD **)v9;
      if ( !v9 )
        goto LABEL_18;
    }
    if ( v9[12]-- == 1 )
    {
      v11 = (void *)*((_QWORD *)v9 + 2);
      if ( v11 )
      {
        AK::MemoryMgr::Free(g_settings.uPrepareEventMemoryPoolID, v11);
        *((_QWORD *)v9 + 2) = 0i64;
        v9[6] = 0;
      }
    }
    if ( !v9[12] )
    {
      v12 = *(_QWORD *)v9;
      if ( !*(_QWORD *)v9 )
      {
        do
          v7 = (unsigned int)(v7 + 1);
        while ( (unsigned int)v7 < 0xC1 && !p_m_MediaHashTable->m_table[v7] );
      }
      if ( v6 )
        *v6 = v12;
      else
        *((_QWORD *)v8 + 1) = v12;
      v13 = (void *)*((_QWORD *)v9 + 4);
      if ( v13 )
      {
        v9[10] = 0;
        AK::MemoryMgr::Free(g_DefaultPoolId, v13);
        *((_QWORD *)v9 + 4) = 0i64;
        v9[11] = 0;
      }
      AK::MemoryMgr::Free(p_m_MediaHashTable->m_MemPoolId, v9);
      --p_m_MediaHashTable->m_uiSize;
    }
  }
LABEL_18:
  LeaveCriticalSection(&p_m_MediaLock->m_csLock);
  LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
}

// File Line: 3277
// RVA: 0xA5F560
signed __int64 __fastcall CAkBankMgr::PrepareSingleMedia(CAkBankMgr *this, AkSrcTypeInfo *in_rmediaInfo)
{
  __int128 v3; // xmm0
  AkSrcTypeInfo *v4; // rax
  AkMediaInformation v6; // [rsp+20h] [rbp-28h] BYREF

  if ( !this->m_bAccumulating )
    return CAkBankMgr::LoadSingleMedia(this, in_rmediaInfo);
  v3 = *(_OWORD *)&in_rmediaInfo->mediaInfo.sourceID;
  *((_DWORD *)&v6 + 4) = *((_DWORD *)&in_rmediaInfo->mediaInfo + 4);
  *(_OWORD *)&v6.sourceID = v3;
  v4 = AkSortedKeyArray<AkMediaInformation,AkSrcTypeInfo,ArrayPoolDefault,CAkBankMgr::AkSortedPreparationListGetKey,8>::AddNoSetKey<AkMediaInformation>(
         &this->m_PreparationAccumulator,
         &v6);
  if ( !v4 )
    return 52i64;
  *(_QWORD *)&v4->mediaInfo.sourceID = *(_QWORD *)&in_rmediaInfo->mediaInfo.sourceID;
  *(_QWORD *)&v4->mediaInfo.uFileOffset = *(_QWORD *)&in_rmediaInfo->mediaInfo.uFileOffset;
  *((_QWORD *)&v4->mediaInfo + 2) = *((_QWORD *)&in_rmediaInfo->mediaInfo + 2);
  v4->pInMemoryMedia = in_rmediaInfo->pInMemoryMedia;
  *(_QWORD *)&v4->dwID = *(_QWORD *)&in_rmediaInfo->dwID;
  return 1i64;
}

// File Line: 3296
// RVA: 0xA620D0
void __fastcall CAkBankMgr::UnprepareSingleMedia(CAkBankMgr *this, unsigned int in_SourceID)
{
  if ( !this->m_bAccumulating )
    CAkBankMgr::ReleaseSingleMedia(this, in_SourceID);
}

// File Line: 3316
// RVA: 0xA5F5E0
signed __int64 __fastcall CAkBankMgr::ProcessAccumulated(CAkBankMgr *this)
{
  AkSrcTypeInfo *m_pItems; // rdi
  signed __int64 result; // rax
  unsigned int v4; // ebp
  AkSrcTypeInfo *v5; // rbx

  m_pItems = this->m_PreparationAccumulator.m_pItems;
  if ( m_pItems == &m_pItems[this->m_PreparationAccumulator.m_uLength] )
    return 1i64;
  while ( 1 )
  {
    result = CAkBankMgr::LoadSingleMedia(this, m_pItems);
    v4 = result;
    if ( (_DWORD)result != 1 )
      break;
    if ( ++m_pItems == &this->m_PreparationAccumulator.m_pItems[this->m_PreparationAccumulator.m_uLength] )
      return 1i64;
  }
  v5 = this->m_PreparationAccumulator.m_pItems;
  if ( v5 != m_pItems )
  {
    do
    {
      CAkBankMgr::ReleaseSingleMedia(this, v5->mediaInfo.sourceID);
      ++v5;
    }
    while ( v5 != m_pItems );
    return v4;
  }
  return result;
}

// File Line: 3341
// RVA: 0xA5E430
signed __int64 __fastcall CAkBankMgr::LoadSingleMedia(CAkBankMgr *this, AkSrcTypeInfo *in_rMediaInfo)
{
  unsigned __int64 uInMemoryMediaSize; // r15
  unsigned int sourceID; // ebp
  __int64 v7; // rax
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v8; // rdi
  AkMediaEntry *p_item; // rdi
  unsigned int SoundFromFile; // esi
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v11; // rdi
  unsigned int uInMemoryDataSize; // r15d
  char *v13; // rax
  char *v14; // r14
  char *v15; // r14
  bool v16; // zf

  uInMemoryMediaSize = in_rMediaInfo->mediaInfo.uInMemoryMediaSize;
  if ( !(_DWORD)uInMemoryMediaSize )
    return 1i64;
  EnterCriticalSection(&this->m_MediaLock.m_csLock);
  sourceID = in_rMediaInfo->mediaInfo.sourceID;
  v7 = in_rMediaInfo->mediaInfo.sourceID % 0xC1;
  v8 = this->m_MediaHashTable.m_table[v7];
  if ( v8 )
  {
    while ( v8->Assoc.key != sourceID )
    {
      v8 = v8->pNextItem;
      if ( !v8 )
        goto LABEL_6;
    }
    p_item = &v8->Assoc.item;
  }
  else
  {
LABEL_6:
    p_item = 0i64;
  }
  if ( !p_item )
  {
    v11 = this->m_MediaHashTable.m_table[v7];
    if ( !v11 )
      goto LABEL_16;
    while ( v11->Assoc.key != sourceID )
    {
      v11 = v11->pNextItem;
      if ( !v11 )
        goto LABEL_16;
    }
    p_item = &v11->Assoc.item;
    if ( !p_item )
LABEL_16:
      p_item = AkHashList<unsigned long,AkMediaEntry,193>::CreateEntry(
                 &this->m_MediaHashTable,
                 sourceID,
                 in_rMediaInfo->mediaInfo.sourceID % 0xC1);
    if ( !p_item )
    {
      SoundFromFile = 2;
      goto LABEL_35;
    }
    p_item->m_sourceID = sourceID;
LABEL_20:
    if ( p_item->m_BankSlots.m_uLength )
    {
      uInMemoryDataSize = p_item->m_BankSlots.m_pItems->item.uInMemoryDataSize;
      if ( g_settings.uPrepareEventMemoryPoolID != -1 )
      {
        v13 = (char *)AK::MemoryMgr::Malign(g_settings.uPrepareEventMemoryPoolID, uInMemoryDataSize, 0x10u);
        v14 = v13;
        if ( v13 )
        {
          memmove(v13, p_item->m_BankSlots.m_pItems->item.pInMemoryData, uInMemoryDataSize);
          SoundFromFile = 1;
          p_item->m_preparedMediaInfo.uInMemoryDataSize = uInMemoryDataSize;
          p_item->m_preparedMediaInfo.pInMemoryData = v14;
          goto LABEL_35;
        }
      }
    }
    else if ( g_settings.uPrepareEventMemoryPoolID != -1 )
    {
      v15 = (char *)AK::MemoryMgr::Malign(g_settings.uPrepareEventMemoryPoolID, uInMemoryMediaSize, 0x10u);
      if ( v15 )
      {
        LeaveCriticalSection(&this->m_MediaLock.m_csLock);
        SoundFromFile = CAkBankMgr::LoadSoundFromFile(this, in_rMediaInfo, v15);
        EnterCriticalSection(&this->m_MediaLock.m_csLock);
        if ( SoundFromFile == 1 )
        {
          p_item->m_preparedMediaInfo.uInMemoryDataSize = uInMemoryMediaSize;
          p_item->m_preparedMediaInfo.pInMemoryData = v15;
          goto LABEL_35;
        }
        AK::MemoryMgr::Free(g_settings.uPrepareEventMemoryPoolID, v15);
LABEL_30:
        v16 = p_item->uRefCount-- == 1;
        if ( v16 && p_item->m_preparedMediaInfo.pInMemoryData )
        {
          AK::MemoryMgr::Free(g_settings.uPrepareEventMemoryPoolID, p_item->m_preparedMediaInfo.pInMemoryData);
          p_item->m_preparedMediaInfo.pInMemoryData = 0i64;
          p_item->m_preparedMediaInfo.uInMemoryDataSize = 0;
        }
        if ( !p_item->uRefCount )
          AkHashList<unsigned long,AkMediaEntry,193>::Unset(&this->m_MediaHashTable, sourceID);
        goto LABEL_35;
      }
    }
    SoundFromFile = 52;
    goto LABEL_30;
  }
  ++p_item->uRefCount;
  if ( !p_item->m_preparedMediaInfo.pInMemoryData )
    goto LABEL_20;
  SoundFromFile = 1;
LABEL_35:
  LeaveCriticalSection(&this->m_MediaLock.m_csLock);
  return SoundFromFile;
}

// File Line: 3435
// RVA: 0xA60CB0
void __fastcall CAkBankMgr::ReleaseSingleMedia(CAkBankMgr *this, unsigned int in_SourceID)
{
  CAkLock *p_m_MediaLock; // rbx
  AkHashList<unsigned long,AkMediaEntry,193> *p_m_MediaHashTable; // r15
  _QWORD *v6; // r14
  __int64 v7; // rsi
  char *v8; // r12
  _DWORD *v9; // rdi
  void *v11; // rdx
  __int64 v12; // rcx
  void *v13; // rdx

  p_m_MediaLock = &this->m_MediaLock;
  EnterCriticalSection(&this->m_MediaLock.m_csLock);
  p_m_MediaHashTable = &this->m_MediaHashTable;
  v6 = 0i64;
  v7 = in_SourceID % 0xC1;
  v8 = (char *)p_m_MediaHashTable + 8 * v7;
  v9 = (_DWORD *)*((_QWORD *)v8 + 1);
  if ( v9 )
  {
    while ( v9[2] != in_SourceID )
    {
      v6 = v9;
      v9 = *(_DWORD **)v9;
      if ( !v9 )
        goto LABEL_18;
    }
    if ( v9[12]-- == 1 )
    {
      v11 = (void *)*((_QWORD *)v9 + 2);
      if ( v11 )
      {
        AK::MemoryMgr::Free(g_settings.uPrepareEventMemoryPoolID, v11);
        *((_QWORD *)v9 + 2) = 0i64;
        v9[6] = 0;
      }
    }
    if ( !v9[12] )
    {
      v12 = *(_QWORD *)v9;
      if ( !*(_QWORD *)v9 )
      {
        do
          v7 = (unsigned int)(v7 + 1);
        while ( (unsigned int)v7 < 0xC1 && !p_m_MediaHashTable->m_table[v7] );
      }
      if ( v6 )
        *v6 = v12;
      else
        *((_QWORD *)v8 + 1) = v12;
      v13 = (void *)*((_QWORD *)v9 + 4);
      if ( v13 )
      {
        v9[10] = 0;
        AK::MemoryMgr::Free(g_DefaultPoolId, v13);
        *((_QWORD *)v9 + 4) = 0i64;
        v9[11] = 0;
      }
      AK::MemoryMgr::Free(p_m_MediaHashTable->m_MemPoolId, v9);
      --p_m_MediaHashTable->m_uiSize;
    }
  }
LABEL_18:
  LeaveCriticalSection(&p_m_MediaLock->m_csLock);
}

// File Line: 3451
// RVA: 0xA61030
void CAkBankMgr::SignalLastBankUnloaded(void)
{
  EnterCriticalSection(&g_csMain.m_csLock);
  CAkStateMgr::RemoveAllStateGroups(g_pStateMgr, 1);
  LeaveCriticalSection(&g_csMain.m_csLock);
}

// File Line: 3459
// RVA: 0xA5E740
__int64 __fastcall CAkBankMgr::LoadSource(char **io_pData, unsigned int *io_ulDataSize, AkBankSourceData *out_rSource)
{
  unsigned int v4; // r9d
  int v5; // r11d
  char *v6; // rax
  unsigned int v7; // ecx
  unsigned int v8; // ecx
  unsigned int v9; // ecx
  unsigned int v10; // ecx
  char v11; // cl
  __int64 result; // rax
  int v13; // ecx
  __int64 v14; // rcx

  *(_QWORD *)&out_rSource->m_srcID = 0i64;
  *(_QWORD *)&out_rSource->m_MediaInfo.sourceID = 0i64;
  *(_QWORD *)&out_rSource->m_MediaInfo.uFileOffset = 0i64;
  *((_QWORD *)&out_rSource->m_MediaInfo + 2) = 0i64;
  out_rSource->m_pParam = 0i64;
  *(_QWORD *)&out_rSource->m_uSize = 0i64;
  v4 = *(_DWORD *)*io_pData;
  *io_pData += 4;
  out_rSource->m_PluginID = v4;
  v5 = *(_DWORD *)*io_pData;
  v6 = *io_pData + 4;
  *io_pData = v6;
  v7 = *(_DWORD *)v6;
  *io_pData = v6 + 4;
  out_rSource->m_MediaInfo.sourceID = v7;
  v8 = *(_DWORD *)*io_pData;
  *io_pData += 4;
  out_rSource->m_MediaInfo.uFileID = v8;
  if ( v5 == 1 )
  {
    *(_QWORD *)&out_rSource->m_MediaInfo.uFileOffset = 0i64;
  }
  else
  {
    v9 = *(_DWORD *)*io_pData;
    *io_pData += 4;
    out_rSource->m_MediaInfo.uFileOffset = v9;
    v10 = *(_DWORD *)*io_pData;
    *io_pData += 4;
    out_rSource->m_MediaInfo.uInMemoryMediaSize = v10;
  }
  v11 = *(*io_pData)++;
  *((_DWORD *)&out_rSource->m_MediaInfo + 4) &= 0xFFFFFDFC;
  result = out_rSource->m_PluginID & 0xF;
  *((_DWORD *)&out_rSource->m_MediaInfo + 4) |= v11 & 1 | (2 * (((v11 & 2) << 7) | (v5 == 2)));
  v13 = *((_DWORD *)&out_rSource->m_MediaInfo + 4);
  if ( (_DWORD)result == 1 )
  {
    if ( !v5 )
    {
      *((_DWORD *)&out_rSource->m_MediaInfo + 4) = v13 & 0xFFFFFF83 | 0xC;
      return result;
    }
    if ( (unsigned int)(v5 - 1) <= 1 )
    {
      result = 1i64;
      *((_DWORD *)&out_rSource->m_MediaInfo + 4) = v13 & 0xFFFFFF83 | 4;
      return result;
    }
    return 2i64;
  }
  if ( (_DWORD)result == 5 || (_DWORD)result == 2 )
  {
    v14 = *(unsigned int *)*io_pData;
    *io_pData += 4;
    out_rSource->m_uSize = v14;
    out_rSource->m_pParam = *io_pData;
    *io_pData += v14;
    *io_ulDataSize -= out_rSource->m_uSize;
  }
  else if ( (_DWORD)result )
  {
    return 2i64;
  }
  return 1i64;
}

// File Line: 3527
// RVA: 0xA5DBA0
signed __int64 __fastcall CAkBankMgr::KillSlot(
        CAkBankMgr *this,
        CAkUsageSlot *in_pUsageSlot,
        void (__fastcall *in_pCallBack)(unsigned int, const void *, AKRESULT, int, void *),
        void *in_pCookie)
{
  unsigned __int16 Size; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  CAkUsageSlot::RemoveContent(in_pUsageSlot);
  *((_BYTE *)in_pUsageSlot + 112) |= 8u;
  in_pUsageSlot->m_pfnBankCallback = in_pCallBack;
  in_pUsageSlot->m_pCookie = in_pCookie;
  in_rItem.type = 24;
  in_rItem.event.GameObjID = (unsigned __int64)in_pUsageSlot;
  Size = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_CreateTexture,Scaleform::Render::DICommand>::GetSize();
  CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, Size);
  return AK::SoundEngine::RenderAudio();
}

// File Line: 3568
// RVA: 0xA5C930
signed __int64 __fastcall AkMediaEntry::AddAlternateBank(
        AkMediaEntry *this,
        char *in_pData,
        unsigned int in_uSize,
        CAkUsageSlot *in_pSlot)
{
  MapStruct<CAkUsageSlot *,AkMediaInfo> *m_pItems; // rax
  CAkKeyArray<CAkUsageSlot *,AkMediaInfo,1> *p_m_BankSlots; // r9
  MapStruct<CAkUsageSlot *,AkMediaInfo> *v8; // rcx
  AkMediaInfo *p_item; // rbx
  MapStruct<CAkUsageSlot *,AkMediaInfo> *v10; // rax
  signed __int64 result; // rax
  __int64 v12; // [rsp+28h] [rbp-10h]

  m_pItems = this->m_BankSlots.m_pItems;
  p_m_BankSlots = &this->m_BankSlots;
  LODWORD(v12) = in_uSize;
  v8 = &m_pItems[this->m_BankSlots.m_uLength];
  if ( m_pItems == v8 )
    goto LABEL_7;
  do
  {
    if ( m_pItems->key == in_pSlot )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v8 );
  if ( m_pItems == v8 )
  {
LABEL_7:
    p_item = 0i64;
  }
  else
  {
    p_item = &m_pItems->item;
    if ( m_pItems != (MapStruct<CAkUsageSlot *,AkMediaInfo> *)-8i64 )
    {
      p_item->pInMemoryData = in_pData;
      goto LABEL_10;
    }
  }
  v10 = AkArray<MapStruct<CAkUsageSlot *,AkMediaInfo>,MapStruct<CAkUsageSlot *,AkMediaInfo> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::Insert(
          p_m_BankSlots,
          0);
  if ( !v10 )
    goto LABEL_11;
  p_item = &v10->item;
  v10->key = in_pSlot;
  v10->item.pInMemoryData = in_pData;
LABEL_10:
  *(_QWORD *)&p_item->uInMemoryDataSize = v12;
LABEL_11:
  result = 52i64;
  if ( p_item )
    return 1i64;
  return result;
}

// File Line: 3595
// RVA: 0xA5D5D0
void __fastcall AkMediaEntry::GetMedia(AkMediaEntry *this, AkMediaInfo *out_mediaInfo, CAkUsageSlot **out_pUsageSlot)
{
  unsigned int m_uLength; // r8d
  unsigned int v6; // eax
  MapStruct<CAkUsageSlot *,AkMediaInfo> *m_pItems; // r10
  __int64 v9; // rcx

  ++this->uRefCount;
  if ( this->m_preparedMediaInfo.pInMemoryData )
  {
    *out_mediaInfo = this->m_preparedMediaInfo;
  }
  else
  {
    m_uLength = this->m_BankSlots.m_uLength;
    v6 = 0;
    if ( m_uLength )
    {
      m_pItems = this->m_BankSlots.m_pItems;
      while ( (*((_BYTE *)m_pItems[v6].key + 112) & 8) != 0 )
      {
        if ( ++v6 >= m_uLength )
          goto LABEL_7;
      }
      v9 = v6;
      *out_pUsageSlot = m_pItems[v9].key;
      *out_mediaInfo = this->m_BankSlots.m_pItems[v9].item;
      _InterlockedIncrement(&(*out_pUsageSlot)->m_iRefCount);
    }
    else
    {
LABEL_7:
      out_mediaInfo->pInMemoryData = 0i64;
      out_mediaInfo->uInMemoryDataSize = 0;
      if ( this->uRefCount-- == 1 )
      {
        if ( this->m_preparedMediaInfo.pInMemoryData )
        {
          AK::MemoryMgr::Free(g_settings.uPrepareEventMemoryPoolID, this->m_preparedMediaInfo.pInMemoryData);
          this->m_preparedMediaInfo.pInMemoryData = 0i64;
          this->m_preparedMediaInfo.uInMemoryDataSize = 0;
        }
      }
    }
  }
}

