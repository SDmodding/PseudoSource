// File Line: 189
// RVA: 0xA60970
void __fastcall CAkUsageSlot::Release(CAkUsageSlot *this, bool in_bSkipNotification)
{
  CAkUsageSlot *v2; // rbx
  bool v3; // di
  signed __int32 v4; // et0
  char v5; // of
  char v6; // al
  char *v7; // rdx
  int v8; // ecx
  bool v9; // zf
  int v10; // edi

  v2 = this;
  v3 = in_bSkipNotification;
  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  v4 = _InterlockedAdd(&v2->m_iRefCount, 0xFFFFFFFF);
  if ( (unsigned __int8)((v4 < 0) ^ v5) | (v4 == 0) )
  {
    if ( v2->m_pData )
    {
      v6 = AK::MemoryMgr::GetPoolAttributes(v2->m_memPoolId);
      v7 = v2->m_pData;
      v8 = v2->m_memPoolId;
      if ( v6 & 8 )
        AK::MemoryMgr::ReleaseBlock(v8, v7);
      else
        AK::MemoryMgr::Free(v8, v7);
      v9 = v2->m_bIsInternalPool == 0;
      v2->m_pData = 0i64;
      if ( !v9 )
      {
        AK::MemoryMgr::DestroyPool(v2->m_memPoolId);
        v2->m_memPoolId = -1;
      }
    }
    CAkBankMgr::UnloadMedia(g_pBankManager, v2);
    if ( v2->m_iPrepareRefCount > 0 )
    {
      LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
      if ( !v3 )
        CAkUsageSlot::UnloadCompletionNotification(v2);
    }
    else
    {
      LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
      if ( !v3 )
        CAkUsageSlot::UnloadCompletionNotification(v2);
      v10 = g_DefaultPoolId;
      if ( *((_BYTE *)v2 + 112) & 2 )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v2->m_paLoadedMedia);
        *((_BYTE *)v2 + 112) &= 0xFDu;
      }
      v2->m_paLoadedMedia = 0i64;
      AK::MemoryMgr::Free(v10, v2);
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
  CAkUsageSlot *v2; // rdi
  bool v3; // bl
  CAkBankList *v4; // rcx
  int v5; // ebx
  unsigned __int64 v6; // [rsp+20h] [rbp-28h]
  __int128 v7; // [rsp+30h] [rbp-18h]

  v2 = this;
  v3 = in_bIsFinal;
  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  if ( v3 )
  {
    v2->m_iPrepareRefCount = 0;
  }
  else if ( _InterlockedAdd(&v2->m_iPrepareRefCount, 0xFFFFFFFF) > 0 )
  {
LABEL_8:
    LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
    return;
  }
  CAkBankMgr::UnPrepareMedia(g_pBankManager, v2);
  if ( v2->m_iRefCount > 0 )
    goto LABEL_8;
  LODWORD(v6) = v2->m_BankID;
  v4 = &g_pBankManager->m_BankList;
  _mm_store_si128((__m128i *)&v7, (__m128i)v6);
  CAkBankList::Remove(v4, (AkBankKey *)&v7);
  LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  CAkUsageSlot::RemoveContent(v2);
  CAkUsageSlot::Unload(v2);
  v5 = g_DefaultPoolId;
  if ( *((_BYTE *)v2 + 112) & 2 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v2->m_paLoadedMedia);
    *((_BYTE *)v2 + 112) &= 0xFDu;
  }
  v2->m_paLoadedMedia = 0i64;
  AK::MemoryMgr::Free(v5, v2);
}

// File Line: 268
// RVA: 0xA60F60
void __fastcall CAkUsageSlot::RemoveContent(CAkUsageSlot *this)
{
  CAkIndexable **v1; // rbx
  CAkUsageSlot *v2; // rsi
  char v3; // di

  v1 = this->m_listLoadedItem.m_pItems;
  v2 = this;
  if ( v1 != &v1[this->m_listLoadedItem.m_uLength] )
  {
    do
    {
      v3 = 1;
      EnterCriticalSection(&g_csMain.m_csLock);
      for ( ; v1 != &v2->m_listLoadedItem.m_pItems[v2->m_listLoadedItem.m_uLength]; ++v3 )
      {
        if ( !v3 )
          break;
        ((void (*)(void))(*v1)->vfptr->Release)();
        ++v1;
      }
      LeaveCriticalSection(&g_csMain.m_csLock);
    }
    while ( v1 != &v2->m_listLoadedItem.m_pItems[v2->m_listLoadedItem.m_uLength] );
  }
  if ( v2->m_listLoadedItem.m_pItems )
  {
    v2->m_listLoadedItem.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v2->m_listLoadedItem.m_pItems);
    v2->m_listLoadedItem.m_pItems = 0i64;
    v2->m_listLoadedItem.m_ulReserved = 0;
  }
}

// File Line: 290
// RVA: 0xA61780
void __fastcall CAkUsageSlot::Unload(CAkUsageSlot *this)
{
  CAkUsageSlot *v1; // rbx
  char v2; // al
  char *v3; // rdx
  int v4; // ecx
  bool v5; // zf

  v1 = this;
  if ( this->m_pData )
  {
    v2 = AK::MemoryMgr::GetPoolAttributes(this->m_memPoolId);
    v3 = v1->m_pData;
    v4 = v1->m_memPoolId;
    if ( v2 & 8 )
      AK::MemoryMgr::ReleaseBlock(v4, v3);
    else
      AK::MemoryMgr::Free(v4, v3);
    v5 = v1->m_bIsInternalPool == 0;
    v1->m_pData = 0i64;
    if ( !v5 )
    {
      AK::MemoryMgr::DestroyPool(v1->m_memPoolId);
      v1->m_memPoolId = -1;
    }
  }
}

// File Line: 310
// RVA: 0xA61AB0
void __fastcall CAkUsageSlot::UnloadCompletionNotification(CAkUsageSlot *this)
{
  void (__fastcall *v1)(unsigned int, const void *, AKRESULT, int, void *); // rdx
  CAkUsageSlot *v2; // rbx

  v1 = this->m_pfnBankCallback;
  v2 = this;
  if ( v1 )
  {
    CAkBankCallbackMgr::DoCallback(
      &g_pBankManager->m_CallbackMgr,
      v1,
      this->m_BankID,
      this->key.pInMemoryPtr,
      AK_Success,
      this->m_memPoolId,
      this->m_pCookie);
    v2->m_pfnBankCallback = 0i64;
  }
}

// File Line: 336
// RVA: 0xA5C840
void __fastcall CAkBankMgr::CAkBankMgr(CAkBankMgr *this)
{
  CAkBankMgr *v1; // rbx

  v1 = this;
  CAkBankReader::CAkBankReader(&this->m_BankReader);
  v1->m_bStopThread = 0;
  InitializeCriticalSection(&v1->m_queueLock.m_csLock);
  InitializeCriticalSection(&v1->m_MediaLock.m_csLock);
  *(_QWORD *)&v1->m_BankQueue.m_ulMinNumListItems = 0i64;
  v1->m_BankQueue.m_ulNumListItems = 0;
  v1->m_bIsFirstBusLoaded = 0;
  v1->m_MediaHashTable.m_MemPoolId = -1;
  v1->m_MediaHashTable.m_uiSize = 0;
  v1->m_BankList.m_ListLoadedBanks.m_uiSize = 0;
  v1->m_BankIDToFileName.m_MemPoolId = -1;
  v1->m_BankIDToFileName.m_uiSize = 0;
  v1->m_bFeedbackInBank = 0;
  CAkBankCallbackMgr::CAkBankCallbackMgr(&v1->m_CallbackMgr);
  v1->m_PreparationAccumulator.m_pItems = 0i64;
  *(_QWORD *)&v1->m_PreparationAccumulator.m_uLength = 0i64;
  v1->m_bAccumulating = 0;
  v1->m_eventQueue = 0i64;
  CAkBankMgr::m_BankMgrThread = 0i64;
}

// File Line: 342
// RVA: 0xA5C8F0
void __fastcall CAkBankMgr::~CAkBankMgr(CAkBankMgr *this)
{
  CAkBankMgr *v1; // rbx

  v1 = this;
  CAkBankCallbackMgr::~CAkBankCallbackMgr(&this->m_CallbackMgr);
  DeleteCriticalSection(&v1->m_MediaLock.m_csLock);
  DeleteCriticalSection(&v1->m_queueLock.m_csLock);
  _((AMD_HD3D *)v1);
}

// File Line: 346
// RVA: 0xA5D8A0
signed __int64 __fastcall CAkBankMgr::Init(CAkBankMgr *this)
{
  CAkBankMgr *v1; // rbx
  signed __int64 result; // rax
  AkHashList<unsigned long,AkMediaEntry,193>::Item **v3; // rax
  signed __int64 v4; // rcx
  signed __int64 v5; // rcx
  AkHashList<unsigned long,char *,31>::Item **v6; // rax
  CAkList2<CAkBankMgr::AkBankQueueItem,CAkBankMgr::AkBankQueueItem const &,1,ArrayPoolDefault>::ListItem *v7; // rax
  CAkList2<CAkBankMgr::AkBankQueueItem,CAkBankMgr::AkBankQueueItem const &,1,ArrayPoolDefault>::ListItem *v8; // rcx
  unsigned int v9; // edx
  signed __int64 v10; // rax

  v1 = this;
  CAkBankList::Init(&this->m_BankList);
  result = CAkBankReader::Init(&v1->m_BankReader);
  if ( (_DWORD)result == 1 )
  {
    v1->m_MediaHashTable.m_MemPoolId = g_DefaultPoolId;
    v3 = v1->m_MediaHashTable.m_table;
    v1->m_MediaHashTable.m_uiSize = 0;
    v4 = 24i64;
    do
    {
      *v3 = 0i64;
      v3[1] = 0i64;
      v3[2] = 0i64;
      v3 += 8;
      *(v3 - 5) = 0i64;
      *(v3 - 4) = 0i64;
      *(v3 - 3) = 0i64;
      *(v3 - 2) = 0i64;
      *(v3 - 1) = 0i64;
      --v4;
    }
    while ( v4 );
    *v3 = 0i64;
    v5 = 3i64;
    v1->m_BankIDToFileName.m_MemPoolId = g_DefaultPoolId;
    v6 = v1->m_BankIDToFileName.m_table;
    v1->m_BankIDToFileName.m_uiSize = 0;
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
    v1->m_BankQueue.m_ulNumListItems = 0;
    v1->m_BankQueue.m_ulMaxNumListItems = -1;
    v1->m_BankQueue.m_pFree = 0i64;
    v7 = (CAkList2<CAkBankMgr::AkBankQueueItem,CAkBankMgr::AkBankQueueItem const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x280ui64);
    v8 = v7;
    v1->m_BankQueue.m_pvMemStart = v7;
    if ( v7 )
    {
      v1->m_BankQueue.m_ulMinNumListItems = 10;
      v1->m_BankQueue.m_pFree = v7;
      v9 = 0;
      do
      {
        v10 = (signed __int64)&v8[1];
        ++v9;
        v8->pNextListItem = v8 + 1;
        ++v8;
      }
      while ( v9 < v1->m_BankQueue.m_ulMinNumListItems );
      *(_QWORD *)(v10 - 64) = 0i64;
      result = 1i64;
    }
    else
    {
      result = 52i64;
    }
    v1->m_BankQueue.m_pFirst = 0i64;
    v1->m_BankQueue.m_pLast = 0i64;
    if ( (_DWORD)result == 1 )
      result = CAkBankMgr::StartThread(v1);
  }
  return result;
}

// File Line: 366
// RVA: 0xA61280
signed __int64 __fastcall CAkBankMgr::Term(CAkBankMgr *this)
{
  CAkBankMgr *v1; // rbx
  CAkList2<CAkBankMgr::AkBankQueueItem,CAkBankMgr::AkBankQueueItem const &,1,ArrayPoolDefault>::ListItem *v2; // rdx
  __int64 v3; // rsi
  unsigned int *v4; // rdi
  void (__fastcall *v5)(unsigned int, const void *, AKRESULT, int, void *); // ST28_8
  void *v6; // ST30_8
  __int64 v7; // ST38_8
  __int64 v8; // ST40_8
  unsigned int *v9; // ST50_8
  CAkList2<CAkBankMgr::AkBankQueueItem,CAkBankMgr::AkBankQueueItem const &,1,ArrayPoolDefault>::ListItem *v10; // rcx
  AkSrcTypeInfo *v11; // rdx

  v1 = this;
  while ( v1->m_BankQueue.m_ulNumListItems )
  {
    v2 = v1->m_BankQueue.m_pFirst;
    v3 = *(_QWORD *)&v2->Item.eType;
    v4 = v2->Item.prepare.pEventID;
    v5 = v2->Item.callbackInfo.pfnBankCallback;
    v6 = v2->Item.callbackInfo.pCookie;
    v7 = *(_QWORD *)&v2->Item.bankLoadFlag;
    v8 = *(_QWORD *)&v2->Item.prepare.numEvents;
    v9 = v2->Item.gameSync.pGameSyncID;
    if ( v2 )
    {
      v1->m_BankQueue.m_pFirst = v2->pNextListItem;
      if ( v2 == v1->m_BankQueue.m_pLast )
        v1->m_BankQueue.m_pLast = 0i64;
      v10 = v1->m_BankQueue.m_pvMemStart;
      if ( v2 < v10 || v2 >= &v10[(unsigned __int64)v1->m_BankQueue.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v2);
      }
      else
      {
        v2->pNextListItem = v1->m_BankQueue.m_pFree;
        v1->m_BankQueue.m_pFree = v2;
      }
      --v1->m_BankQueue.m_ulNumListItems;
    }
    if ( !(((_DWORD)v3 - 9) & 0xFFFFFFFD) && v4 )
      AK::MemoryMgr::Free(g_DefaultPoolId, v4);
  }
  CAkList2<CAkBankMgr::AkBankQueueItem,CAkBankMgr::AkBankQueueItem const &,1,ArrayPoolDefault>::Term(&v1->m_BankQueue);
  CAkBankMgr::UnloadAll(v1);
  _((AMD_HD3D *)&v1->m_BankList);
  if ( v1->m_MediaHashTable.m_MemPoolId != -1 )
  {
    AkHashList<unsigned long,AkMediaEntry,193>::RemoveAll(&v1->m_MediaHashTable);
    v1->m_MediaHashTable.m_MemPoolId = -1;
  }
  CAkBankMgr::FlushFileNameTable(v1);
  CAkBankReader::Term(&v1->m_BankReader);
  v11 = v1->m_PreparationAccumulator.m_pItems;
  if ( v11 )
  {
    v1->m_PreparationAccumulator.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v11);
    v1->m_PreparationAccumulator.m_pItems = 0i64;
    v1->m_PreparationAccumulator.m_ulReserved = 0;
  }
  return 1i64;
}

// File Line: 403
// RVA: 0xA5D530
void __fastcall CAkBankMgr::FlushFileNameTable(CAkBankMgr *this)
{
  AkHashList<unsigned long,char *,31> *v1; // rsi
  AkHashList<unsigned long,char *,31>::Item *v2; // rdi
  __int64 v3; // rbx

  v1 = &this->m_BankIDToFileName;
  if ( this->m_BankIDToFileName.m_MemPoolId != -1 )
  {
    v2 = this->m_BankIDToFileName.m_table[0];
    LODWORD(v3) = 0;
    if ( v2 )
      goto LABEL_16;
    while ( 1 )
    {
      v3 = (unsigned int)(v3 + 1);
      if ( (unsigned int)v3 >= 0x1F )
        break;
      v2 = v1->m_table[v3];
      if ( v2 )
        goto LABEL_7;
    }
    if ( v2 )
    {
LABEL_16:
      do
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
          v2 = v1->m_table[v3];
          if ( v2 )
            goto LABEL_7;
        }
      }
      while ( v2 );
    }
    if ( v1->m_MemPoolId != -1 )
    {
      AkHashList<unsigned long,char *,31>::RemoveAll(v1);
      v1->m_MemPoolId = -1;
    }
  }
}

// File Line: 418
// RVA: 0xA61070
signed __int64 __fastcall CAkBankMgr::StartThread(CAkBankMgr *this)
{
  CAkBankMgr *v1; // rbx
  signed __int64 result; // rax
  HANDLE v3; // rax
  unsigned int ThreadId; // [rsp+48h] [rbp+10h]

  v1 = this;
  if ( CAkBankMgr::m_BankMgrThread )
    return 2i64;
  this->m_bStopThread = 0;
  v3 = CreateEventW(0i64, 0, 0, 0i64);
  v1->m_eventQueue = v3;
  if ( !v3 )
    return 2i64;
  CAkBankMgr::m_BankMgrThread = CreateThread(
                                  0i64,
                                  g_PDSettings.threadBankManager.uStackSize,
                                  (LPTHREAD_START_ROUTINE)CAkBankMgr::BankThreadFunc,
                                  v1,
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
    result = 1i64;
  else
    result = 2i64;
  return result;
}

// File Line: 448
// RVA: 0xA61180
void __fastcall CAkBankMgr::StopThread(CAkBankMgr *this)
{
  CAkBankMgr *v1; // rbx
  void *v2; // rcx

  this->m_bStopThread = 1;
  v1 = this;
  if ( CAkBankMgr::m_BankMgrThread )
  {
    SetEvent(this->m_eventQueue);
    WaitForSingleObject(CAkBankMgr::m_BankMgrThread, 0xFFFFFFFF);
    CloseHandle(CAkBankMgr::m_BankMgrThread);
    CAkBankMgr::m_BankMgrThread = 0i64;
  }
  v2 = v1->m_eventQueue;
  if ( v2 )
    CloseHandle(v2);
  v1->m_eventQueue = 0i64;
}

// File Line: 463
// RVA: 0xA5CB10
__int64 __fastcall CAkBankMgr::BankThreadFunc(void *lpParameter)
{
  CAkBankMgr *v1; // rbx

  v1 = (CAkBankMgr *)lpParameter;
  CAkBankMgr::m_idThread = GetCurrentThreadId();
  WaitForSingleObject(v1->m_eventQueue, 0xFFFFFFFF);
  while ( !v1->m_bStopThread )
  {
    CAkBankMgr::ExecuteCommand(v1);
    WaitForSingleObject(v1->m_eventQueue, 0xFFFFFFFF);
  }
  return 0i64;
}

// File Line: 482
// RVA: 0xA60340
__int64 __fastcall CAkBankMgr::QueueBankCommand(CAkBankMgr *this, CAkBankMgr::AkBankQueueItem *in_Item)
{
  CAkBankMgr *v2; // rsi
  CAkBankMgr::AkBankQueueItem *v3; // rbp
  unsigned int v4; // edi

  v2 = this;
  v3 = in_Item;
  EnterCriticalSection(&this->m_queueLock.m_csLock);
  if ( !v3->callbackInfo.pfnBankCallback
    || (v4 = CAkBankCallbackMgr::AddCookie(&v2->m_CallbackMgr, v3->callbackInfo.pCookie), v4 == 1) )
  {
    v4 = 2
       - (CAkList2<CAkBankMgr::AkBankQueueItem,CAkBankMgr::AkBankQueueItem const &,1,ArrayPoolDefault>::AddLast(
            &v2->m_BankQueue,
            v3) != 0i64);
    if ( v3->callbackInfo.pfnBankCallback )
    {
      if ( v4 == 1 )
      {
LABEL_7:
        SetEvent(v2->m_eventQueue);
        goto LABEL_8;
      }
      CAkBankCallbackMgr::RemoveOneCookie(&v2->m_CallbackMgr, v3->callbackInfo.pCookie);
    }
    if ( v4 == 1 )
      goto LABEL_7;
  }
LABEL_8:
  LeaveCriticalSection(&v2->m_queueLock.m_csLock);
  return v4;
}

// File Line: 550
// RVA: 0xA5D070
__int64 __fastcall CAkBankMgr::ExecuteCommand(CAkBankMgr *this)
{
  CAkBankMgr *v1; // rbx
  AKRESULT v2; // edi
  CAkList2<CAkBankMgr::AkBankQueueItem,CAkBankMgr::AkBankQueueItem const &,1,ArrayPoolDefault>::ListItem *v3; // rdx
  __int64 v4; // rsi
  void (__fastcall *v5)(unsigned int, const void *, AKRESULT, int, void *); // r13
  __int64 v6; // r15
  unsigned int *v7; // r12
  __int64 v8; // rax
  unsigned int *v9; // rax
  CAkList2<CAkBankMgr::AkBankQueueItem,CAkBankMgr::AkBankQueueItem const &,1,ArrayPoolDefault>::ListItem *v10; // rcx
  unsigned int v11; // er8
  unsigned int *v12; // r9
  CAkBankCallbackMgr *v13; // rcx
  AKRESULT in_eLoadResult; // eax
  unsigned int *v16; // r9
  CAkUsageSlot *v17; // rax
  int v18; // ecx
  void *in_pCookie; // [rsp+30h] [rbp-D0h]
  CAkBankMgr::AkBankQueueItem in_rItem; // [rsp+40h] [rbp-C0h]
  __int128 v21; // [rsp+80h] [rbp-80h]
  __int128 v22; // [rsp+90h] [rbp-70h]
  CAkBankMgr::AkBankQueueItem v23; // [rsp+A0h] [rbp-60h]
  CAkBankMgr::AkBankQueueItem v24; // [rsp+E0h] [rbp-20h]
  CAkBankMgr::AkBankQueueItem v25; // [rsp+120h] [rbp+20h]
  CAkBankMgr::AkBankQueueItem v26; // [rsp+160h] [rbp+60h]
  CAkBankMgr::AkBankQueueItem v27; // [rsp+1A0h] [rbp+A0h]
  CAkBankMgr::AkBankQueueItem v28; // [rsp+1E0h] [rbp+E0h]
  CAkBankMgr::AkBankQueueItem v29; // [rsp+220h] [rbp+120h]
  __int64 v30; // [rsp+2A0h] [rbp+1A0h]
  void *v31; // [rsp+2A8h] [rbp+1A8h]

  v1 = this;
  v2 = 1;
  EnterCriticalSection(&this->m_queueLock.m_csLock);
  while ( v1->m_BankQueue.m_ulNumListItems )
  {
    v3 = v1->m_BankQueue.m_pFirst;
    v4 = *(_QWORD *)&v3->Item.eType;
    v5 = v3->Item.callbackInfo.pfnBankCallback;
    v6 = *(_QWORD *)&v3->Item.prepare.numEvents;
    v7 = v3->Item.prepare.pEventID;
    v31 = v3->Item.callbackInfo.pCookie;
    in_rItem.callbackInfo.pCookie = v3->Item.callbackInfo.pCookie;
    v8 = *(_QWORD *)&v3->Item.bankLoadFlag;
    *(_QWORD *)&in_rItem.eType = v4;
    v30 = v8;
    *(_QWORD *)&in_rItem.bankLoadFlag = v8;
    v9 = v3->Item.gameSync.pGameSyncID;
    in_rItem.callbackInfo.pfnBankCallback = v5;
    *(_QWORD *)&in_rItem.prepare.numEvents = v6;
    in_rItem.prepare.pEventID = v7;
    in_rItem.gameSync.pGameSyncID = v9;
    if ( v3 )
    {
      v1->m_BankQueue.m_pFirst = v3->pNextListItem;
      if ( v3 == v1->m_BankQueue.m_pLast )
        v1->m_BankQueue.m_pLast = 0i64;
      v10 = v1->m_BankQueue.m_pvMemStart;
      if ( v3 < v10 || v3 >= &v10[(unsigned __int64)v1->m_BankQueue.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_DefaultPoolId, v3);
      }
      else
      {
        v3->pNextListItem = v1->m_BankQueue.m_pFree;
        v1->m_BankQueue.m_pFree = v3;
      }
      --v1->m_BankQueue.m_ulNumListItems;
    }
    LeaveCriticalSection(&v1->m_queueLock.m_csLock);
    switch ( (_DWORD)v4 )
    {
      case 0:
        v2 = (unsigned int)CAkBankMgr::LoadBankPre(v1, &in_rItem);
        break;
      case 1:
        v28 = in_rItem;
        v2 = CAkBankMgr::UnloadBankPre(v1, &v28);
        break;
      case 2:
        v23 = in_rItem;
        v2 = CAkBankMgr::PrepareEvents(v1, &v23);
        break;
      case 3:
        v26 = in_rItem;
        v2 = CAkBankMgr::UnprepareEvents(v1, &v26);
        break;
      case 4:
        v24 = in_rItem;
        v2 = CAkBankMgr::PrepareGameSync(v1, &v24);
        break;
      case 5:
        CAkBankMgr::ClearPreparedEvents(v1);
        v11 = 0;
        in_pCookie = v31;
        if ( (_DWORD)v6 == 1 )
          v11 = (unsigned int)v7;
        v12 = 0i64;
        v13 = &v1->m_CallbackMgr;
        if ( (_DWORD)v30 == 1 )
          v12 = v7;
        goto LABEL_20;
      case 6:
        v27 = in_rItem;
        in_eLoadResult = (unsigned int)CAkBankMgr::PrepareBankInternal(
                                         v1,
                                         &v27,
                                         v6,
                                         (CAkBankMgr::AkLoadBankDataMode)((_mm_cvtsi128_si32(
                                                                             _mm_srli_si128(
                                                                               (__m128i)in_rItem.prepare,
                                                                               4)) != 1)
                                                                        + 1),
                                         1);
        v16 = 0i64;
        v2 = in_eLoadResult;
        if ( (_DWORD)v30 == 1 )
          v16 = v7;
        CAkBankCallbackMgr::DoCallback(&v1->m_CallbackMgr, v5, v6, v16, in_eLoadResult, -1, v31);
        break;
      case 7:
        LODWORD(v21) = v6;
        *((_QWORD *)&v21 + 1) = 0i64;
        _mm_store_si128((__m128i *)&v22, (__m128i)(unsigned __int64)v21);
        v17 = CAkBankList::Get(&v1->m_BankList, (AkBankKey *)&v22);
        if ( v17 )
        {
          v18 = v17->m_iWasPreparedAsABankCounter;
          if ( v18 )
            v17->m_iWasPreparedAsABankCounter = v18 - 1;
          CAkUsageSlot::ReleasePrepare(v17, 0);
        }
        v12 = 0i64;
        in_pCookie = v31;
        v13 = &v1->m_CallbackMgr;
        if ( (_DWORD)v30 == 1 )
          v12 = v7;
        v11 = v6;
LABEL_20:
        CAkBankCallbackMgr::DoCallback(v13, v5, v11, v12, AK_Success, -1, in_pCookie);
        goto $LN2_117;
      case 8:
        v25 = in_rItem;
        v2 = (unsigned int)CAkBankMgr::ClearBanksInternal(v1, &v25);
        break;
      case 9:
      case 0xB:
$LN2_117:
        v2 = 1;
        break;
      case 0xA:
        v29 = in_rItem;
        v2 = CAkBankMgr::UnloadMediaFile(v1, &v29);
        break;
      default:
        break;
    }
    EnterCriticalSection(&v1->m_queueLock.m_csLock);
  }
  LeaveCriticalSection(&v1->m_queueLock.m_csLock);
  return (unsigned int)v2;
}

// File Line: 623
// RVA: 0xA5E8A0
void __fastcall CAkBankMgr::NotifyCompletion(CAkBankMgr *this, CAkBankMgr::AkBankQueueItem *in_rItem, AKRESULT in_OperationResult)
{
  CAkBankMgr::AkBankQueueItemType v3; // eax
  unsigned int *v4; // r9
  signed int in_memPoolId; // er10
  AKRESULT in_eLoadResult; // er11
  unsigned int v7; // er8

  v3 = in_rItem->eType;
  v4 = 0i64;
  in_memPoolId = -1;
  in_eLoadResult = in_OperationResult;
  v7 = 0;
  if ( in_rItem->eType >= 0 )
  {
    if ( (signed int)v3 <= 1 )
    {
      in_memPoolId = in_rItem->load.memPoolId;
      v7 = in_rItem->prepare.numEvents;
      goto LABEL_9;
    }
    if ( v3 == 4 )
      goto LABEL_9;
    if ( (unsigned int)(v3 - 6) <= 1 )
    {
      v7 = in_rItem->prepare.numEvents;
      goto LABEL_9;
    }
  }
  if ( in_rItem->prepare.numEvents == 1 )
    v7 = in_rItem->prepare.eventID;
LABEL_9:
  if ( in_rItem->bankLoadFlag == 1 )
    v4 = in_rItem->prepare.pEventID;
  CAkBankCallbackMgr::DoCallback(
    &this->m_CallbackMgr,
    in_rItem->callbackInfo.pfnBankCallback,
    v7,
    v4,
    in_eLoadResult,
    in_memPoolId,
    in_rItem->callbackInfo.pCookie);
}

// File Line: 687
// RVA: 0xA5E630
__int64 __fastcall CAkBankMgr::LoadSoundFromFile(CAkBankMgr *this, AkSrcTypeInfo *in_rMediaInfo, char *io_pData)
{
  char *v3; // rbp
  AkSrcTypeInfo *v4; // rsi
  CAkBankMgr *v5; // rdi
  unsigned int v6; // er8
  unsigned int v7; // er10
  unsigned int v8; // eax
  AkHashList<unsigned long,char *,31>::Item *v9; // rax
  unsigned int v10; // ebx
  unsigned int out_rulSizeRead; // [rsp+40h] [rbp+8h]

  v3 = io_pData;
  v4 = in_rMediaInfo;
  v5 = this;
  CAkBankReader::Reset(&this->m_BankReader);
  v6 = v4->mediaInfo.uFileOffset;
  v7 = v4->mediaInfo.uFileID;
  if ( v6 || !HIWORD(v4->dwID) )
  {
    v9 = v5->m_BankIDToFileName.m_table[v7 % 0x1F];
    if ( !v9 )
      goto LABEL_7;
    while ( v9->Assoc.key != v7 )
    {
      v9 = v9->pNextItem;
      if ( !v9 )
        goto LABEL_7;
    }
    if ( v9 != (AkHashList<unsigned long,char *,31>::Item *)-16i64 )
      v8 = CAkBankReader::SetFile(&v5->m_BankReader, v9->Assoc.item, v6, 0i64);
    else
LABEL_7:
      v8 = CAkBankReader::SetFile(&v5->m_BankReader, v7, v6, 0, 0i64, 1);
  }
  else
  {
    v8 = CAkBankReader::SetFile(&v5->m_BankReader, v7, 0, HIWORD(v4->dwID), 0i64, *((_BYTE *)&v4->mediaInfo + 16) & 1);
  }
  v10 = v8;
  out_rulSizeRead = 0;
  if ( v8 == 1 )
  {
    v10 = CAkBankReader::FillData(&v5->m_BankReader, v3, v4->mediaInfo.uInMemoryMediaSize, &out_rulSizeRead);
    if ( v10 == 1 && v4->mediaInfo.uInMemoryMediaSize != out_rulSizeRead )
      v10 = 2;
  }
  CAkBankReader::CloseFile(&v5->m_BankReader);
  return v10;
}

// File Line: 710
// RVA: 0xA5DC10
signed __int64 __fastcall CAkBankMgr::LoadBank(CAkBankMgr *this, CAkBankMgr::AkBankQueueItem *in_Item, CAkUsageSlot **out_pUsageSlot, CAkBankMgr::AkLoadBankDataMode in_eLoadMode, bool in_bIsFromPrepareBank)
{
  unsigned int v5; // er13
  CAkBankMgr *v6; // rdi
  CAkBankMgr::AkLoadBankDataMode v7; // er12
  CAkUsageSlot **v8; // r15
  CAkBankMgr::AkBankQueueItem *v9; // rsi
  unsigned int v10; // ecx
  unsigned int *v11; // rax
  CAkUsageSlot *v12; // rax
  CAkUsageSlot *v13; // r14
  AKRESULT v15; // ebx
  int v16; // er13
  signed int v17; // er12
  signed int v18; // er15
  char *v19; // rdx
  unsigned int v20; // eax
  bool v21; // zf
  AkBankLoadFlag v22; // eax
  bool v23; // r14
  AKRESULT v24; // eax
  AkHashList<unsigned long,char *,31>::Item *v25; // rcx
  CAkFeedbackBus *v26; // r13
  signed int v27; // eax
  __int64 v28; // r9
  char *v29; // rsi
  CAkFeedbackBus *v30; // rax
  __m128i in_pBufferToFill; // [rsp+30h] [rbp-40h]
  AkBank::AkBankHeader in_rBankHeader; // [rsp+40h] [rbp-30h]
  unsigned int out_rulSizeRead; // [rsp+B0h] [rbp+40h]
  unsigned int in_FileID; // [rsp+B8h] [rbp+48h]
  CAkUsageSlot **v35; // [rsp+C0h] [rbp+50h]
  CAkBankMgr::AkLoadBankDataMode v36; // [rsp+C8h] [rbp+58h]

  v36 = in_eLoadMode;
  v35 = out_pUsageSlot;
  v5 = in_Item->prepare.numEvents;
  v6 = this;
  v7 = in_eLoadMode;
  v8 = out_pUsageSlot;
  v9 = in_Item;
  in_FileID = in_Item->prepare.numEvents;
  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  v10 = 0;
  if ( v9->eType <= 1u || (unsigned int)(v9->eType - 6) <= 1 )
    v10 = v9->prepare.numEvents;
  if ( v9->bankLoadFlag == 1 )
    v11 = v9->prepare.pEventID;
  else
    v11 = 0i64;
  in_pBufferToFill.m128i_i32[0] = v10;
  in_pBufferToFill.m128i_i64[1] = (__int64)v11;
  _mm_store_si128(&in_pBufferToFill, in_pBufferToFill);
  v12 = CAkBankList::Get(&v6->m_BankList, (AkBankKey *)&in_pBufferToFill);
  v13 = v12;
  if ( v12 && *((_BYTE *)v12 + 112) & 1 )
  {
    LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
    return 69i64;
  }
  v15 = 1;
  LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  if ( v13 )
  {
    v21 = in_bIsFromPrepareBank == 0;
    *v8 = v13;
    if ( !v21 )
      ++v13->m_iWasPreparedAsABankCounter;
  }
  else
  {
    v16 = in_PoolId;
    v17 = 0;
    v18 = 0;
    if ( v36 )
    {
      if ( in_bIsFromPrepareBank )
        v18 = 1;
      else
        v17 = 1;
    }
    else
    {
      v16 = v9->load.memPoolId;
      LODWORD(v13) = 1;
    }
    v19 = (char *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x78ui64);
    if ( v19 )
    {
      v20 = in_FileID;
      *((_DWORD *)v19 + 11) = v16;
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
    v8 = v35;
    v7 = v36;
    v5 = in_FileID;
    *v35 = (CAkUsageSlot *)v19;
    if ( !v19 )
      v15 = 52;
  }
  CAkBankReader::Reset(&v6->m_BankReader);
  v22 = v9->bankLoadFlag;
  v23 = v22 == 1;
  if ( v15 != 1 )
    goto LABEL_34;
  if ( v7 )
    goto LABEL_29;
  if ( v22 != 2 )
  {
    if ( v23 )
    {
      v24 = (unsigned int)CAkBankReader::SetFile(&v6->m_BankReader, v9->prepare.pEventID, v9->load.ui32InMemoryBankSize);
      goto LABEL_33;
    }
LABEL_29:
    v25 = v6->m_BankIDToFileName.m_table[v5 % 0x1F];
    if ( !v25 )
      goto LABEL_32;
    while ( v25->Assoc.key != v5 )
    {
      v25 = v25->pNextItem;
      if ( !v25 )
        goto LABEL_32;
    }
    if ( v25 != (AkHashList<unsigned long,char *,31>::Item *)-16i64 )
      v24 = (unsigned int)CAkBankReader::SetFile(&v6->m_BankReader, v25->Assoc.item, 0, v9->callbackInfo.pCookie);
    else
LABEL_32:
      v24 = (unsigned int)CAkBankReader::SetFile(&v6->m_BankReader, v5, 0, 0, v9->callbackInfo.pCookie, 1);
    goto LABEL_33;
  }
  v24 = (unsigned int)CAkBankReader::SetFile(&v6->m_BankReader, v5, 0, 0, v9->callbackInfo.pCookie, 1);
LABEL_33:
  v15 = v24;
LABEL_34:
  *(_QWORD *)&in_rBankHeader.dwBankGeneratorVersion = 0i64;
  *(_QWORD *)&in_rBankHeader.dwLanguageID = 0i64;
  in_rBankHeader.dwProjectID = 0;
  if ( v15 == 1 )
    v15 = CAkBankMgr::ProcessBankHeader(v6, &in_rBankHeader);
  v26 = 0i64;
  if ( !v6->m_bIsFirstBusLoaded )
    v26 = CAkFeedbackBus::ClearTempMasterBus();
  while ( v15 == 1 )
  {
    out_rulSizeRead = 0;
    v27 = CAkBankReader::FillData(&v6->m_BankReader, &in_pBufferToFill, 8u, &out_rulSizeRead);
    v15 = v27;
    if ( v27 != 1 )
      break;
    if ( out_rulSizeRead != 8 )
    {
      if ( out_rulSizeRead )
        v27 = 7;
      v15 = v27;
      break;
    }
    if ( in_pBufferToFill.m128i_i32[0] > 0x474D5453u )
    {
      if ( in_pBufferToFill.m128i_i32[0] == 1398165061 )
      {
        v15 = CAkBankMgr::ProcessEnvSettingsChunk(v6, in_pBufferToFill.m128i_u32[1]);
      }
      else
      {
        if ( in_pBufferToFill.m128i_i32[0] != 1480870212 )
          goto LABEL_62;
        switch ( v7 )
        {
          case 0:
          case 1:
            goto LABEL_81;
          case 2:
            goto LABEL_62;
          case 3:
LABEL_81:
            v15 = (unsigned int)CAkBankMgr::LoadMediaIndex(v6, *v8, in_pBufferToFill.m128i_u32[1], v23);
            break;
        }
      }
    }
    else
    {
      switch ( in_pBufferToFill.m128i_i32[0] )
      {
        case 0x474D5453:                        // STMG
          v15 = CAkBankMgr::ProcessGlobalSettingsChunk(v6, in_pBufferToFill.m128i_u32[1]);
          break;
        case 0x41544144:                        // DATA
          if ( v7 )
          {
            switch ( v7 )
            {
              case 1:
                goto LABEL_82;
              case 2:
                goto LABEL_62;
              case 3:
LABEL_82:
                v15 = (unsigned int)CAkBankMgr::PrepareMedia(v6, *v8, in_pBufferToFill.m128i_u32[1]);
                break;
            }
          }
          else
          {
            if ( v23 )
            {
              v29 = CAkBankReader::GetData(&v6->m_BankReader, in_pBufferToFill.m128i_u32[1]);
              CAkBankReader::ReleaseData(&v6->m_BankReader);
            }
            else
            {
              v15 = CAkBankMgr::ProcessDataChunk(v6, in_pBufferToFill.m128i_u32[1], *v8);
              v29 = (*v8)->m_pData;
              if ( v15 != 1 )
                goto LABEL_73;
            }
            v15 = (unsigned int)CAkBankMgr::LoadMedia(v6, v29, *v8, v23);
          }
          break;
        case 0x43524948:                        // HIRC
          v15 = CAkBankMgr::ProcessHircChunk(v6, *v8, in_FileID);
          break;
        case 0x44495453:                        // STID
          v15 = CAkBankMgr::ProcessStringMappingChunk(v6, in_pBufferToFill.m128i_u32[1], *v8);
          break;
        default:
LABEL_62:
          CAkBankReader::Skip(&v6->m_BankReader, in_pBufferToFill.m128i_u32[1], &out_rulSizeRead, v28);
          if ( out_rulSizeRead != in_pBufferToFill.m128i_i32[1] )
          {
            v15 = 7;
            goto LABEL_73;
          }
          break;
      }
    }
  }
LABEL_73:
  if ( v26 )
  {
    v30 = CAkFeedbackBus::GetMasterMotionBusAndAddRef();
    if ( v30 )
      v30->vfptr->Release((CAkIndexable *)&v30->vfptr);
    else
      CAkFeedbackBus::ResetMasterBus(v26);
    v26->vfptr->Release((CAkIndexable *)&v26->vfptr);
  }
  CAkBankReader::CloseFile(&v6->m_BankReader);
  return (unsigned int)v15;
}tr->Release((CAkIndexable *)&v26->vfptr);
  }
  CAkBankReader::CloseFile(&v6->m_BankReader);
  return (unsigned int)v15;
}

// File Line: 980
// RVA: 0xA5E0A0
__int64 __fastcall CAkBankMgr::LoadBankPre(CAkBankMgr *this, CAkBankMgr::AkBankQueueItem *in_rItem)
{
  __int128 v2; // xmm0
  __int128 v3; // xmm1
  CAkBankMgr::AkBankQueueItem *v4; // rbx
  unsigned int *v5; // rbp
  CAkBankMgr *v6; // r14
  AKRESULT v7; // edi
  unsigned int v8; // eax
  unsigned int v9; // esi
  CAkUsageSlot *v10; // r8
  unsigned int v11; // ecx
  CAkUsageSlot *v12; // rdi
  __m128i v14; // [rsp+30h] [rbp-68h]
  __int128 v15; // [rsp+40h] [rbp-58h]
  __int128 v16; // [rsp+50h] [rbp-48h]
  AkPrepareEventQueueItemLoad v17; // [rsp+60h] [rbp-38h]
  __int64 v18; // [rsp+70h] [rbp-28h]
  CAkUsageSlot *v19; // [rsp+A8h] [rbp+10h]

  v2 = *(_OWORD *)&in_rItem->eType;
  v3 = *(_OWORD *)&in_rItem->callbackInfo.pCookie;
  v4 = in_rItem;
  v5 = 0i64;
  v6 = this;
  v7 = 1;
  v19 = 0i64;
  v15 = v2;
  v16 = v3;
  *(_QWORD *)&v3 = in_rItem->gameSync.pGameSyncID;
  v17 = in_rItem->prepare;
  v18 = v3;
  v8 = CAkBankMgr::LoadBank(this, (CAkBankMgr::AkBankQueueItem *)&v15, &v19, 0, 0);
  v9 = v8;
  if ( v8 == 69 )
  {
    v9 = 1;
    v7 = 69;
  }
  else if ( v8 == 1 )
  {
    v10 = v19;
    v11 = 0;
    *((_BYTE *)v10 + 112) |= 1u;
    if ( v4->eType <= 1u || (unsigned int)(v4->eType - 6) <= 1 )
      v11 = v4->prepare.numEvents;
    if ( v4->bankLoadFlag == 1 )
      v5 = v4->prepare.pEventID;
    v14.m128i_i32[0] = v11;
    v14.m128i_i64[1] = (__int64)v5;
    _mm_store_si128(&v14, v14);
    CAkBankList::Set(&v6->m_BankList, (AkBankKey *)&v14, v10);
  }
  else
  {
    v12 = v19;
    if ( v19 )
    {
      CAkUsageSlot::RemoveContent(v19);
      CAkUsageSlot::Release(v12, 1);
    }
    v7 = v9;
  }
  CAkBankMgr::NotifyCompletion(v6, v4, v7);
  return v9;
}

// File Line: 1018
// RVA: 0xA61990
signed __int64 __fastcall CAkBankMgr::UnloadBankPre(CAkBankMgr *this, CAkBankMgr::AkBankQueueItem *in_Item)
{
  CAkBankMgr *v2; // rdi
  CAkBankMgr::AkBankQueueItem *v3; // rbx
  unsigned int *v4; // r8
  unsigned int v5; // edx
  __m128i v6; // xmm6
  CAkUsageSlot *v7; // rax
  CAkUsageSlot *v8; // rsi
  signed __int64 result; // rax
  __m128i v10; // [rsp+20h] [rbp-28h]

  v2 = this;
  v3 = in_Item;
  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  v4 = 0i64;
  v5 = 0;
  if ( v3->eType <= 1u || (unsigned int)(v3->eType - 6) <= 1 )
    v5 = v3->prepare.numEvents;
  if ( v3->bankLoadFlag == 1 )
    v4 = v3->prepare.pEventID;
  v10.m128i_i32[0] = v5;
  v10.m128i_i64[1] = (__int64)v4;
  v6 = v10;
  _mm_store_si128(&v10, v10);
  v7 = CAkBankList::Get(&v2->m_BankList, (AkBankKey *)&v10);
  v8 = v7;
  if ( v7 )
  {
    if ( *((_BYTE *)v7 + 112) & 1 )
    {
      _mm_store_si128(&v10, v6);
      CAkBankList::Remove(&v2->m_BankList, (AkBankKey *)&v10);
      LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
      result = CAkBankMgr::KillSlot(v2, v8, v3->callbackInfo.pfnBankCallback, v3->callbackInfo.pCookie);
    }
    else
    {
      LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
      CAkBankMgr::NotifyCompletion(v2, v3, AK_Fail);
      result = 2i64;
    }
  }
  else
  {
    LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
    CAkBankMgr::NotifyCompletion(v2, v3, AK_UnknownBankID);
    result = 54i64;
  }
  return result;
}

// File Line: 1058
// RVA: 0xA5CB60
signed __int64 __fastcall CAkBankMgr::ClearBanksInternal(CAkBankMgr *this, CAkBankMgr::AkBankQueueItem *in_Item)
{
  CAkBankMgr *v2; // r13
  CAkBankMgr::AkBankQueueItem *v3; // r12
  int v4; // er14
  char *v5; // r15
  __int64 v6; // rax
  CAkBankList *v7; // rdi
  unsigned __int64 v8; // rax
  signed __int64 v9; // rcx
  signed __int64 v10; // rcx
  void *v11; // rsp
  void *v12; // rsp
  CAkUsageSlot *v13; // rcx
  __int64 v14; // rdx
  CAkUsageSlot *v15; // r9
  char *v16; // rsi
  CAkUsageSlot *v17; // rbx
  __int64 v18; // r8
  CAkUsageSlot *v19; // r11
  HANDLE v20; // rax
  int v21; // er14
  __int64 v22; // rbx
  unsigned __int64 v23; // rdi
  unsigned __int16 v24; // ax
  char in_cookie; // [rsp+20h] [rbp+0h]
  HANDLE hHandle; // [rsp+28h] [rbp+8h]
  AkQueuedMsg in_rItem; // [rsp+40h] [rbp+20h]
  CAkBankMgr::AkBankQueueItem *v29; // [rsp+B8h] [rbp+98h]

  v29 = in_Item;
  v2 = this;
  v3 = in_Item;
  v4 = 0;
  v5 = 0i64;
  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  v6 = v2->m_BankList.m_ListLoadedBanks.m_uiSize;
  v7 = &v2->m_BankList;
  if ( (_DWORD)v6 )
  {
    v8 = 8 * v6;
    v9 = v8 + 15;
    if ( v8 + 15 <= v8 )
      v9 = 1152921504606846960i64;
    v10 = v9 & 0xFFFFFFFFFFFFFFF0ui64;
    v11 = alloca(v10);
    v12 = alloca(v10);
    v13 = v7->m_ListLoadedBanks.m_table[0];
    LODWORD(v14) = 0;
    v15 = 0i64;
    v5 = &in_cookie;
    if ( v7->m_ListLoadedBanks.m_table[0] )
      goto LABEL_34;
    do
    {
      v14 = (unsigned int)(v14 + 1);
      if ( (unsigned int)v14 >= 0x1F )
        break;
      v13 = v7->m_ListLoadedBanks.m_table[v14];
    }
    while ( !v13 );
    if ( v13 )
    {
LABEL_34:
      v16 = &in_cookie;
      while ( 1 )
      {
LABEL_9:
        while ( *((_BYTE *)v13 + 112) & 1 )
        {
          *(_QWORD *)v16 = v13;
          v17 = v13->pNextItem;
          ++v4;
          v16 += 8;
          LODWORD(v18) = v14;
          LODWORD(hHandle) = v14;
          v13 = v17;
          v19 = v15;
          if ( !v17 )
          {
            do
            {
              v18 = (unsigned int)(v18 + 1);
              if ( (unsigned int)v18 >= 0x1F )
                break;
              v13 = v7->m_ListLoadedBanks.m_table[v18];
              v19 = 0i64;
            }
            while ( !v13 );
            LODWORD(hHandle) = v18;
          }
          if ( v15 )
            v15->pNextItem = v17;
          else
            v7->m_ListLoadedBanks.m_table[(unsigned int)v14] = v17;
          v20 = hHandle;
          --v2->m_BankList.m_ListLoadedBanks.m_uiSize;
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
            v13 = v7->m_ListLoadedBanks.m_table[v14];
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
      if ( (unsigned int)CAkBankCallbackMgr::AddCookie(&v2->m_CallbackMgr, &in_cookie) == 1 )
      {
        CAkUsageSlot::RemoveContent((CAkUsageSlot *)v23);
        *(_BYTE *)(v23 + 112) |= 8u;
        *(_QWORD *)(v23 + 80) = &in_cookie;
        *(_QWORD *)(v23 + 72) = AK::SoundEngine::DefaultBankCallbackFunc;
        in_rItem.type = 24;
        in_rItem.event.GameObjID = v23;
        v24 = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_CreateTexture,Scaleform::Render::DICommand>::GetSize();
        CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v24);
        if ( (unsigned int)AK::SoundEngine::RenderAudio() == 1 )
          WaitForSingleObject(hHandle, 0xFFFFFFFF);
      }
      if ( hHandle )
        CloseHandle(hHandle);
      --v22;
    }
    while ( v22 >= 0 );
    v3 = v29;
  }
  CAkBankMgr::NotifyCompletion(v2, v3, AK_Success);
  return 1i64;
}

// File Line: 1112
// RVA: 0xA5EC60
__int64 __fastcall CAkBankMgr::PrepareEvents(CAkBankMgr *this, CAkBankMgr::AkBankQueueItem *in_Item)
{
  unsigned int v2; // eax
  unsigned int *v3; // r12
  CAkBankMgr::AkBankQueueItem *v4; // rdi
  CAkBankMgr *v5; // r15
  __int128 v6; // xmm1
  unsigned int v7; // er8
  AKRESULT in_eLoadResult; // er13
  unsigned int v9; // esi
  __int128 v10; // xmm1
  unsigned int v11; // er8
  unsigned int i; // ebp
  unsigned int v13; // esi
  _RTL_CRITICAL_SECTION *v14; // r14
  CAkEvent *v15; // rbx
  signed int v16; // eax
  int in_memPoolId; // edx
  unsigned int v18; // er8
  signed __int64 v19; // r12
  unsigned int v20; // ebp
  _RTL_CRITICAL_SECTION *v21; // r14
  CAkEvent *v22; // rbx
  __int128 v24; // [rsp+40h] [rbp-68h]
  __int128 v25; // [rsp+50h] [rbp-58h]
  AkPrepareEventQueueItemLoad v26; // [rsp+60h] [rbp-48h]
  __int64 v27; // [rsp+70h] [rbp-38h]

  this->m_bAccumulating = 1;
  v2 = in_Item->prepare.numEvents;
  v3 = 0i64;
  v4 = in_Item;
  v5 = this;
  if ( v2 == 1 )
  {
    v6 = *(_OWORD *)&in_Item->callbackInfo.pCookie;
    v7 = in_Item->prepare.eventID;
    v24 = *(_OWORD *)&in_Item->eType;
    v25 = v6;
    *(_QWORD *)&v6 = in_Item->gameSync.pGameSyncID;
    v26 = in_Item->prepare;
    v27 = v6;
    in_eLoadResult = (unsigned int)CAkBankMgr::PrepareEvent(this, (CAkBankMgr::AkBankQueueItem *)&v24, v7);
    if ( in_eLoadResult == 1 )
    {
      in_eLoadResult = CAkBankMgr::ProcessAccumulated(v5);
      if ( in_eLoadResult != 1 )
        CAkBankMgr::UnprepareEvent(v5, v4->prepare.eventID);
    }
  }
  else
  {
    v9 = 0;
    if ( v2 )
    {
      while ( 1 )
      {
        v10 = *(_OWORD *)&v4->callbackInfo.pCookie;
        v11 = v4->prepare.pEventID[v9];
        v24 = *(_OWORD *)&v4->eType;
        v25 = v10;
        *(_QWORD *)&v10 = v4->gameSync.pGameSyncID;
        v26 = v4->prepare;
        v27 = v10;
        in_eLoadResult = (unsigned int)CAkBankMgr::PrepareEvent(v5, (CAkBankMgr::AkBankQueueItem *)&v24, v11);
        if ( in_eLoadResult != 1 )
          break;
        if ( ++v9 >= v4->prepare.numEvents )
          goto LABEL_8;
      }
      if ( v9 )
      {
        v19 = v9;
        do
        {
          --v19;
          v20 = v4->prepare.pEventID[v19];
          v21 = &g_pIndex->m_idxEvents.m_IndexLock.m_csLock;
          --v9;
          EnterCriticalSection(&g_pIndex->m_idxEvents.m_IndexLock.m_csLock);
          v22 = (CAkEvent *)*((_QWORD *)&v21[1].DebugInfo + v20 % 0xC1);
          if ( !v22 )
            goto LABEL_26;
          while ( v22->key != v20 )
          {
            v22 = (CAkEvent *)v22->pNextItem;
            if ( !v22 )
              goto LABEL_26;
          }
          if ( v22 )
          {
            ++v22->m_lRef;
            LeaveCriticalSection(v21);
            CAkBankMgr::UnprepareEvent(v5, v22, 0);
            v22->vfptr->Release((CAkIndexable *)&v22->vfptr);
          }
          else
          {
LABEL_26:
            LeaveCriticalSection(v21);
          }
        }
        while ( v9 );
        v3 = 0i64;
      }
    }
    else
    {
LABEL_8:
      in_eLoadResult = CAkBankMgr::ProcessAccumulated(v5);
      if ( in_eLoadResult != 1 )
      {
        for ( i = 0; i < v4->prepare.numEvents; ++i )
        {
          v13 = v4->prepare.pEventID[i];
          v14 = &g_pIndex->m_idxEvents.m_IndexLock.m_csLock;
          EnterCriticalSection(&g_pIndex->m_idxEvents.m_IndexLock.m_csLock);
          v15 = (CAkEvent *)*((_QWORD *)&v14[1].DebugInfo + v13 % 0xC1);
          if ( !v15 )
            goto LABEL_13;
          while ( v15->key != v13 )
          {
            v15 = (CAkEvent *)v15->pNextItem;
            if ( !v15 )
              goto LABEL_13;
          }
          if ( v15 )
          {
            ++v15->m_lRef;
            LeaveCriticalSection(v14);
            CAkBankMgr::UnprepareEvent(v5, v15, 0);
            v15->vfptr->Release((CAkIndexable *)&v15->vfptr);
          }
          else
          {
LABEL_13:
            LeaveCriticalSection(v14);
          }
        }
      }
    }
    AK::MemoryMgr::Free(g_DefaultPoolId, v4->prepare.pEventID);
    v4->prepare.pEventID = 0i64;
  }
  v5->m_bAccumulating = 0;
  v5->m_PreparationAccumulator.m_uLength = 0;
  v16 = v4->eType;
  in_memPoolId = -1;
  v18 = 0;
  if ( v4->eType >= 0 )
  {
    if ( v16 <= 1 )
    {
      in_memPoolId = v4->load.memPoolId;
      v18 = v4->prepare.numEvents;
      goto LABEL_36;
    }
    if ( v16 == 4 )
      goto LABEL_36;
    if ( (unsigned int)(v16 - 6) <= 1 )
    {
      v18 = v4->prepare.numEvents;
      goto LABEL_36;
    }
  }
  if ( v4->prepare.numEvents == 1 )
    v18 = v4->prepare.eventID;
LABEL_36:
  if ( v4->bankLoadFlag == 1 )
    v3 = v4->prepare.pEventID;
  CAkBankCallbackMgr::DoCallback(
    &v5->m_CallbackMgr,
    v4->callbackInfo.pfnBankCallback,
    v18,
    v3,
    in_eLoadResult,
    in_memPoolId,
    v4->callbackInfo.pCookie);
  return (unsigned int)in_eLoadResult;
}

// File Line: 1194
// RVA: 0xA5EAA0
signed __int64 __fastcall CAkBankMgr::PrepareEvent(CAkBankMgr *this, CAkBankMgr::AkBankQueueItem *in_Item, unsigned int in_EventID)
{
  CAkBankMgr *v3; // r14
  CAkBankMgr::AkBankQueueItem *v4; // rdi
  AKRESULT v5; // ebp
  CAkIndexable *v6; // rax
  CAkIndexable *v7; // rsi
  CAkIndexableVtbl *v8; // rbx
  __int128 v9; // xmm1
  unsigned int v10; // er8
  int v11; // eax
  CAkUsageSlot *v12; // rax
  CAkIndexableVtbl *i; // rdi
  int v14; // eax
  CAkUsageSlot *v15; // rax
  __int128 v17; // [rsp+30h] [rbp-78h]
  __int128 v18; // [rsp+40h] [rbp-68h]
  __int128 v19; // [rsp+50h] [rbp-58h]
  __int128 v20; // [rsp+60h] [rbp-48h]
  AkPrepareEventQueueItemLoad v21; // [rsp+70h] [rbp-38h]
  __int64 v22; // [rsp+80h] [rbp-28h]

  v3 = this;
  v4 = in_Item;
  v5 = 1;
  v6 = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
         (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxEvents,
         in_EventID);
  v7 = v6;
  if ( v6 )
  {
    if ( !LODWORD(v6[1].pNextItem) )
    {
      v8 = v6[1].vfptr;
      if ( v8 )
      {
        while ( 1 )
        {
          if ( WORD2(v8[1].Release) == 1027 )
          {
            v9 = *(_OWORD *)&v4->callbackInfo.pCookie;
            v10 = (unsigned int)v8[1].Category;
            v19 = *(_OWORD *)&v4->eType;
            v20 = v9;
            *(_QWORD *)&v9 = v4->gameSync.pGameSyncID;
            v21 = v4->prepare;
            v22 = v9;
            v5 = (unsigned int)CAkBankMgr::PrepareBankInternal(
                                 v3,
                                 (CAkBankMgr::AkBankQueueItem *)&v19,
                                 v10,
                                 AkLoadBankDataMode_Structure,
                                 0);
            if ( v5 != 1 )
              goto LABEL_11;
            v5 = CAkParameterNodeBase::PrepareNodeData((unsigned int)v8[1].Release);
            if ( v5 != 1 )
              break;
          }
          v8 = (CAkIndexableVtbl *)v8->Category;
          if ( !v8 )
            goto LABEL_16;
        }
        v11 = (int)v8[1].Category;
        *((_QWORD *)&v17 + 1) = 0i64;
        LODWORD(v17) = v11;
        _mm_store_si128((__m128i *)&v17, (__m128i)(unsigned __int64)v17);
        v12 = CAkBankList::Get(&v3->m_BankList, (AkBankKey *)&v17);
        if ( v12 )
          CAkUsageSlot::ReleasePrepare(v12, 0);
LABEL_11:
        for ( i = v7[1].vfptr; i != v8; i = (CAkIndexableVtbl *)i->Category )
        {
          if ( WORD2(i[1].Release) == 1027 )
          {
            CAkParameterNodeBase::UnPrepareNodeData((unsigned int)i[1].Release);
            v14 = (int)i[1].Category;
            *((_QWORD *)&v17 + 1) = 0i64;
            LODWORD(v17) = v14;
            _mm_store_si128((__m128i *)&v18, (__m128i)(unsigned __int64)v17);
            v15 = CAkBankList::Get(&v3->m_BankList, (AkBankKey *)&v18);
            if ( v15 )
              CAkUsageSlot::ReleasePrepare(v15, 0);
          }
        }
LABEL_16:
        if ( v5 != 1 )
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
  unsigned int v2; // eax
  AKRESULT in_eLoadResult; // er14
  unsigned int *v4; // r12
  CAkBankMgr::AkBankQueueItem *v5; // rdi
  CAkBankMgr *v6; // r13
  CAkEvent *v7; // rax
  CAkEvent *v8; // rbx
  unsigned int v9; // ebp
  unsigned int v10; // esi
  _RTL_CRITICAL_SECTION *v11; // r15
  CAkEvent *v12; // rbx
  signed int v13; // eax
  int in_memPoolId; // er9
  unsigned int v15; // er8

  v2 = in_Item->prepare.numEvents;
  in_eLoadResult = 1;
  v4 = 0i64;
  v5 = in_Item;
  v6 = this;
  if ( v2 == 1 )
  {
    v7 = (CAkEvent *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                       (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxEvents,
                       in_Item->prepare.eventID);
    v8 = v7;
    if ( v7 )
    {
      CAkBankMgr::UnprepareEvent(v6, v7, 0);
      v8->vfptr->Release((CAkIndexable *)&v8->vfptr);
    }
    else
    {
      in_eLoadResult = 15;
    }
  }
  else
  {
    v9 = 0;
    if ( v2 )
    {
      do
      {
        v10 = v5->prepare.pEventID[v9];
        v11 = &g_pIndex->m_idxEvents.m_IndexLock.m_csLock;
        in_eLoadResult = 1;
        EnterCriticalSection(&g_pIndex->m_idxEvents.m_IndexLock.m_csLock);
        v12 = (CAkEvent *)*((_QWORD *)&v11[1].DebugInfo + v10 % 0xC1);
        if ( !v12 )
          goto LABEL_9;
        while ( v12->key != v10 )
        {
          v12 = (CAkEvent *)v12->pNextItem;
          if ( !v12 )
            goto LABEL_9;
        }
        if ( v12 )
        {
          ++v12->m_lRef;
          LeaveCriticalSection(v11);
          CAkBankMgr::UnprepareEvent(v6, v12, 0);
          v12->vfptr->Release((CAkIndexable *)&v12->vfptr);
        }
        else
        {
LABEL_9:
          LeaveCriticalSection(v11);
          in_eLoadResult = 15;
        }
        if ( in_eLoadResult != 1 )
          break;
        ++v9;
      }
      while ( v9 < v5->prepare.numEvents );
    }
    AK::MemoryMgr::Free(g_DefaultPoolId, v5->prepare.pEventID);
    v5->prepare.pEventID = 0i64;
  }
  v13 = v5->eType;
  in_memPoolId = -1;
  v15 = 0;
  if ( v5->eType >= 0 )
  {
    if ( v13 <= 1 )
    {
      in_memPoolId = v5->load.memPoolId;
      v15 = v5->prepare.numEvents;
      goto LABEL_23;
    }
    if ( v13 == 4 )
      goto LABEL_23;
    if ( (unsigned int)(v13 - 6) <= 1 )
    {
      v15 = v5->prepare.numEvents;
      goto LABEL_23;
    }
  }
  if ( v5->prepare.numEvents == 1 )
    v15 = v5->prepare.eventID;
LABEL_23:
  if ( v5->bankLoadFlag == 1 )
    v4 = v5->prepare.pEventID;
  CAkBankCallbackMgr::DoCallback(
    &v6->m_CallbackMgr,
    v5->callbackInfo.pfnBankCallback,
    v15,
    v4,
    in_eLoadResult,
    in_memPoolId,
    v5->callbackInfo.pCookie);
  return (unsigned int)in_eLoadResult;
}

// File Line: 1303
// RVA: 0xA61DC0
signed __int64 __fastcall CAkBankMgr::UnprepareEvent(CAkBankMgr *this, unsigned int in_EventID)
{
  CAkBankMgr *v2; // rdi
  CAkEvent *v3; // rax
  CAkEvent *v4; // rbx

  v2 = this;
  v3 = (CAkEvent *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                     (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxEvents,
                     in_EventID);
  v4 = v3;
  if ( !v3 )
    return 15i64;
  CAkBankMgr::UnprepareEvent(v2, v3, 0);
  v4->vfptr->Release((CAkIndexable *)&v4->vfptr);
  return 1i64;
}

// File Line: 1325
// RVA: 0xA61E20
void __fastcall CAkBankMgr::UnprepareEvent(CAkBankMgr *this, CAkEvent *in_pEvent, bool in_bCompleteUnprepare)
{
  unsigned int v3; // eax
  CAkEvent *v4; // rsi
  CAkBankMgr *v5; // rbp
  CAkAction *v6; // rbx
  CAkAction *v7; // rdi
  CAkUsageSlot *v8; // rax
  unsigned __int64 v9; // [rsp+20h] [rbp-38h]
  __int128 v10; // [rsp+30h] [rbp-28h]

  v3 = in_pEvent->m_iPreparationCount;
  v4 = in_pEvent;
  v5 = this;
  if ( v3 )
  {
    in_pEvent->m_iPreparationCount = in_bCompleteUnprepare ? 0 : v3 - 1;
    if ( !in_pEvent->m_iPreparationCount )
    {
      v6 = in_pEvent->m_actions.m_pFirst;
      while ( v6 )
      {
        v7 = v6;
        v6 = v6->pNextLightItem;
        if ( v7->m_eActionType == 1027 )
        {
          CAkParameterNodeBase::UnPrepareNodeData(v7->m_ulElementID);
          LODWORD(v9) = v7[1].vfptr;
          _mm_store_si128((__m128i *)&v10, (__m128i)v9);
          v8 = CAkBankList::Get(&v5->m_BankList, (AkBankKey *)&v10);
          if ( v8 )
            CAkUsageSlot::ReleasePrepare(v8, 0);
        }
      }
      v4->vfptr->Release((CAkIndexable *)&v4->vfptr);
    }
  }
}

// File Line: 1381
// RVA: 0xA5EF90
__int64 __fastcall CAkBankMgr::PrepareGameSync(CAkBankMgr *this, CAkBankMgr::AkBankQueueItem *in_Item)
{
  CAkBankMgr::AkBankQueueItem *v2; // rbx
  CAkBankMgr *v3; // r15
  AKRESULT v4; // esi
  unsigned int v5; // eax
  unsigned int *v6; // r14
  AKRESULT v7; // eax
  __int64 v8; // rdi
  __int64 v9; // rbp
  unsigned int i; // edi
  signed int v11; // eax
  int in_memPoolId; // edx
  unsigned int v13; // er8

  v2 = in_Item;
  v3 = this;
  v4 = 1;
  if ( in_Item->gameSync.bSupported )
    this->m_bAccumulating = 1;
  v5 = in_Item->gameSync.uNumGameSync;
  v6 = 0i64;
  if ( v5 == 1 )
  {
    v7 = (unsigned int)CAkStateMgr::PrepareGameSync(
                         g_pStateMgr,
                         in_Item->gameSync.eGroupType,
                         in_Item->gameSync.uGroupID,
                         in_Item->load.ui32InMemoryBankSize,
                         in_Item->gameSync.bSupported);
    v4 = v7;
    if ( !v2->gameSync.bSupported )
      goto LABEL_23;
    if ( v7 == 1 )
    {
      v4 = CAkBankMgr::ProcessAccumulated(v3);
      if ( v4 != 1 )
        CAkStateMgr::PrepareGameSync(
          g_pStateMgr,
          v2->gameSync.eGroupType,
          v2->gameSync.uGroupID,
          v2->load.ui32InMemoryBankSize,
          0);
    }
  }
  else
  {
    v8 = 0i64;
    if ( v5 )
    {
      while ( 1 )
      {
        v4 = (unsigned int)CAkStateMgr::PrepareGameSync(
                             g_pStateMgr,
                             v2->gameSync.eGroupType,
                             v2->gameSync.uGroupID,
                             v2->gameSync.pGameSyncID[v8],
                             v2->gameSync.bSupported);
        if ( v4 != 1 )
          break;
        v8 = (unsigned int)(v8 + 1);
        if ( (unsigned int)v8 >= v2->gameSync.uNumGameSync )
          goto LABEL_15;
      }
      if ( (_DWORD)v8 )
      {
        v9 = 0i64;
        do
        {
          CAkStateMgr::PrepareGameSync(
            g_pStateMgr,
            v2->gameSync.eGroupType,
            v2->gameSync.uGroupID,
            v2->gameSync.pGameSyncID[v9],
            0);
          ++v9;
          --v8;
        }
        while ( v8 );
      }
    }
LABEL_15:
    if ( v2->gameSync.bSupported )
    {
      if ( v4 == 1 )
      {
        v4 = CAkBankMgr::ProcessAccumulated(v3);
        if ( v4 != 1 )
        {
          for ( i = 0; i < v2->gameSync.uNumGameSync; ++i )
            CAkStateMgr::PrepareGameSync(
              g_pStateMgr,
              v2->gameSync.eGroupType,
              v2->gameSync.uGroupID,
              v2->gameSync.pGameSyncID[i],
              0);
        }
      }
    }
    AK::MemoryMgr::Free(g_DefaultPoolId, v2->gameSync.pGameSyncID);
  }
  if ( v2->gameSync.bSupported )
  {
    v3->m_bAccumulating = 0;
    v3->m_PreparationAccumulator.m_uLength = 0;
  }
LABEL_23:
  v11 = v2->eType;
  in_memPoolId = -1;
  v13 = 0;
  if ( v2->eType >= 0 )
  {
    if ( v11 <= 1 )
    {
      in_memPoolId = v2->load.memPoolId;
      v13 = v2->prepare.numEvents;
      goto LABEL_31;
    }
    if ( v11 == 4 )
      goto LABEL_31;
    if ( (unsigned int)(v11 - 6) <= 1 )
    {
      v13 = v2->prepare.numEvents;
      goto LABEL_31;
    }
  }
  if ( v2->prepare.numEvents == 1 )
    v13 = v2->prepare.eventID;
LABEL_31:
  if ( v2->bankLoadFlag == 1 )
    v6 = v2->prepare.pEventID;
  CAkBankCallbackMgr::DoCallback(
    &v3->m_CallbackMgr,
    v2->callbackInfo.pfnBankCallback,
    v13,
    v6,
    v4,
    in_memPoolId,
    v2->callbackInfo.pCookie);
  return (unsigned int)v4;
}

// File Line: 1654
// RVA: 0xA61CE0
__int64 __fastcall CAkBankMgr::UnloadMediaFile(CAkBankMgr *this, CAkBankMgr::AkBankQueueItem *in_Item)
{
  CAkBankMgr *v2; // r14
  CAkBankMgr::AkBankQueueItem *v3; // r15
  AKRESULT v4; // ebp
  unsigned int v5; // esi
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v6; // rax
  signed __int64 v7; // rdi
  bool v8; // zf

  v2 = this;
  v3 = in_Item;
  v4 = 1;
  EnterCriticalSection(&this->m_MediaLock.m_csLock);
  v5 = v3->prepare.numEvents;
  v6 = v2->m_MediaHashTable.m_table[v3->prepare.numEvents % 0xC1];
  if ( v6 )
  {
    while ( v6->Assoc.key != v5 )
    {
      v6 = v6->pNextItem;
      if ( !v6 )
        goto LABEL_12;
    }
    v7 = (signed __int64)&v6->Assoc.item;
    if ( v6 != (AkHashList<unsigned long,AkMediaEntry,193>::Item *)-16i64 )
    {
      v8 = v6->Assoc.item.uRefCount-- == 1;
      if ( v8 && *(_QWORD *)v7 )
      {
        AK::MemoryMgr::Free(in_PoolId, *(void **)v7);
        *(_QWORD *)v7 = 0i64;
        *(_DWORD *)(v7 + 8) = 0;
      }
      if ( *(_DWORD *)(v7 + 32) )
        v4 = 2;
      else
        AkHashList<unsigned long,AkMediaEntry,193>::Unset(&v2->m_MediaHashTable, v5);
    }
  }
LABEL_12:
  CAkBankMgr::NotifyCompletion(v2, v3, v4);
  LeaveCriticalSection(&v2->m_MediaLock.m_csLock);
  return (unsigned int)v4;
}

// File Line: 1796
// RVA: 0xA61410
void __fastcall CAkBankMgr::UnPrepareAllBank(CAkBankMgr *this)
{
  CAkBankMgr *v1; // rbx
  __int64 v2; // rdi
  __int128 *v3; // r14
  __int64 v4; // rax
  CAkBankList *v5; // rbx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  void *v8; // rsp
  CAkUsageSlot *v9; // rdx
  void *v10; // rsp
  signed __int64 v11; // rcx
  __int128 *v12; // r8
  signed __int64 v13; // rsi
  __m128i v14; // xmm6
  CAkUsageSlot *v15; // rax
  CAkUsageSlot *v16; // rax
  int v17; // ecx
  __int128 v18; // [rsp+20h] [rbp+0h]
  __int128 v19; // [rsp+30h] [rbp+10h]
  __m128i v20; // [rsp+40h] [rbp+20h]
  __int128 v21; // [rsp+50h] [rbp+30h]

  v1 = this;
  LODWORD(v2) = 0;
  v3 = 0i64;
  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  v4 = v1->m_BankList.m_ListLoadedBanks.m_uiSize;
  v5 = &v1->m_BankList;
  if ( (_DWORD)v4 )
  {
    v6 = 16 * v4;
    v7 = v6 + 15;
    if ( v6 + 15 <= v6 )
      v7 = 1152921504606846960i64;
    v11 = v7 & 0xFFFFFFFFFFFFFFF0ui64;
    v8 = alloca(v11);
    v9 = v5->m_ListLoadedBanks.m_table[0];
    v10 = alloca(v11);
    v3 = &v18;
    LODWORD(v11) = 0;
    if ( v5->m_ListLoadedBanks.m_table[0] )
      goto LABEL_28;
    do
    {
      v11 = (unsigned int)(v11 + 1);
      if ( (unsigned int)v11 >= 0x1F )
        break;
      v9 = v5->m_ListLoadedBanks.m_table[v11];
    }
    while ( !v9 );
    if ( v9 )
    {
LABEL_28:
      v12 = &v18;
      do
      {
        do
        {
LABEL_9:
          if ( v9->m_iWasPreparedAsABankCounter )
          {
            LODWORD(v2) = v2 + 1;
            ++v12;
            *((_QWORD *)v12 - 2) = *(_QWORD *)&v9->key.bankID;
            *((_QWORD *)v12 - 1) = v9->key.pInMemoryPtr;
          }
          v9 = v9->pNextItem;
        }
        while ( v9 );
        while ( 1 )
        {
          v11 = (unsigned int)(v11 + 1);
          if ( (unsigned int)v11 >= 0x1F )
            break;
          v9 = v5->m_ListLoadedBanks.m_table[v11];
          if ( v9 )
            goto LABEL_9;
        }
      }
      while ( v9 );
    }
  }
  LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  v2 = (signed int)v2;
  if ( (signed int)v2 > 0i64 )
  {
    v13 = (signed __int64)&v3[v2];
    do
    {
      v14 = *(__m128i *)(v13 - 16);
      v13 -= 16i64;
      --v2;
      v20 = v14;
      EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
      _mm_store_si128((__m128i *)&v19, v14);
      v15 = CAkBankList::Get(v5, (AkBankKey *)&v19);
      if ( v15 && v15->m_iWasPreparedAsABankCounter )
      {
        LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
        *((_QWORD *)&v18 + 1) = 0i64;
        LODWORD(v18) = v20.m128i_i32[0];
        _mm_store_si128((__m128i *)&v21, (__m128i)(unsigned __int64)v18);
        v16 = CAkBankList::Get(v5, (AkBankKey *)&v21);
        if ( v16 )
        {
          v17 = v16->m_iWasPreparedAsABankCounter;
          if ( v17 )
            v16->m_iWasPreparedAsABankCounter = v17 - 1;
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
signed __int64 __fastcall CAkBankMgr::PrepareBankInternal(CAkBankMgr *this, CAkBankMgr::AkBankQueueItem *in_Item, unsigned int in_FileID, CAkBankMgr::AkLoadBankDataMode in_LoadBankMode, bool in_bIsFromPrepareBank)
{
  CAkBankMgr *v5; // r14
  CAkBankMgr::AkLoadBankDataMode v6; // ebx
  unsigned int v7; // ebp
  CAkBankMgr::AkBankQueueItem *v8; // rdi
  __m128i v9; // xmm6
  CAkUsageSlot *v10; // rax
  bool v11; // al
  __int128 v12; // xmm1
  __int128 v13; // xmm0
  unsigned int v14; // eax
  unsigned int v15; // edi
  CAkUsageSlot *v16; // r8
  CAkUsageSlot *v18; // rbx
  __int128 v19; // [rsp+30h] [rbp-98h]
  __int128 v20; // [rsp+40h] [rbp-88h]
  __int128 v21; // [rsp+50h] [rbp-78h]
  __int128 v22; // [rsp+60h] [rbp-68h]
  __int128 v23; // [rsp+70h] [rbp-58h]
  __int128 v24; // [rsp+80h] [rbp-48h]
  __int64 v25; // [rsp+90h] [rbp-38h]
  CAkUsageSlot *v26; // [rsp+D0h] [rbp+8h]

  v5 = this;
  v6 = in_LoadBankMode;
  v7 = in_FileID;
  v8 = in_Item;
  LODWORD(v19) = in_FileID;
  *((_QWORD *)&v19 + 1) = 0i64;
  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  v9 = (__m128i)(unsigned __int64)v19;
  _mm_store_si128((__m128i *)&v19, (__m128i)(unsigned __int64)v19);
  v10 = CAkBankList::Get(&v5->m_BankList, (AkBankKey *)&v19);
  if ( v10 )
  {
    _InterlockedIncrement(&v10->m_iPrepareRefCount);
    ++v10->m_iWasPreparedAsABankCounter;
    if ( v6 == 2 || *((_BYTE *)v10 + 112) & 4 )
    {
      LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
      return 1i64;
    }
    v6 = 3;
  }
  LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  v11 = in_bIsFromPrepareBank;
  v8->prepare.numEvents = v7;
  v12 = *(_OWORD *)&v8->callbackInfo.pCookie;
  v22 = *(_OWORD *)&v8->eType;
  v23 = v12;
  v13 = (__int128)v8->prepare;
  *(_QWORD *)&v12 = v8->gameSync.pGameSyncID;
  v26 = 0i64;
  v24 = v13;
  v25 = v12;
  v14 = CAkBankMgr::LoadBank(v5, (CAkBankMgr::AkBankQueueItem *)&v22, &v26, v6, v11);
  v15 = v14;
  if ( v14 == 1 )
  {
    v16 = v26;
    _mm_store_si128((__m128i *)&v20, v9);
    CAkBankList::Set(&v5->m_BankList, (AkBankKey *)&v20, v16);
  }
  else if ( v14 != 69 )
  {
    v18 = v26;
    if ( v26 )
    {
      _mm_store_si128((__m128i *)&v21, v9);
      CAkBankList::Remove(&v5->m_BankList, (AkBankKey *)&v21);
      CAkUsageSlot::ReleasePrepare(v18, 0);
    }
  }
  return v15;
}

// File Line: 1908
// RVA: 0xA617E0
void __fastcall CAkBankMgr::UnloadAll(CAkBankMgr *this)
{
  CAkBankMgr *v1; // rbx
  signed __int64 v2; // r15
  CAkUsageSlot *v3; // rdi
  __int64 v4; // rdx
  __int64 v5; // rbp
  CAkUsageSlot *v6; // r9
  CAkUsageSlot *v7; // rbx
  __int64 v8; // rcx
  __int64 v9; // r8
  signed __int32 v10; // et0
  char v11; // of
  char v12; // al
  char *v13; // rdx
  int v14; // ecx
  int v15; // esi
  int v16; // [rsp+28h] [rbp-50h]

  v1 = this;
  CAkBankMgr::ClearPreparedEvents(this);
  CAkBankMgr::UnPrepareAllBank(v1);
  v2 = (signed __int64)&v1->m_BankList;
  v3 = v1->m_BankList.m_ListLoadedBanks.m_table[0];
  LODWORD(v4) = 0;
  v5 = 0i64;
  if ( v3 )
    goto LABEL_29;
  while ( 1 )
  {
    v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= 0x1F )
      break;
    v3 = *(CAkUsageSlot **)(v2 + 8 * v4);
    if ( v3 )
      goto LABEL_6;
  }
  if ( v3 )
  {
LABEL_29:
    while ( 1 )
    {
LABEL_6:
      v6 = v3->pNextItem;
      v7 = v3;
      LODWORD(v8) = v4;
      v16 = v4;
      v9 = v5;
      v3 = v6;
      if ( !v6 )
      {
        do
        {
          v8 = (unsigned int)(v8 + 1);
          if ( (unsigned int)v8 >= 0x1F )
            break;
          v3 = *(CAkUsageSlot **)(v2 + 8 * v8);
          v9 = 0i64;
        }
        while ( !v3 );
        v16 = v8;
      }
      if ( v5 )
        *(_QWORD *)(v5 + 16) = v6;
      else
        *(_QWORD *)(v2 + 8i64 * (unsigned int)v4) = v6;
      --*(_DWORD *)(v2 + 248);
      v5 = v9;
      CAkUsageSlot::RemoveContent(v7);
      EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
      v10 = _InterlockedAdd(&v7->m_iRefCount, 0xFFFFFFFF);
      if ( !((unsigned __int8)((v10 < 0) ^ v11) | (v10 == 0)) )
        goto LABEL_30;
      if ( v7->m_pData )
      {
        v12 = AK::MemoryMgr::GetPoolAttributes(v7->m_memPoolId);
        v13 = v7->m_pData;
        v14 = v7->m_memPoolId;
        if ( v12 & 8 )
          AK::MemoryMgr::ReleaseBlock(v14, v13);
        else
          AK::MemoryMgr::Free(v14, v13);
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
        if ( *((_BYTE *)v7 + 112) & 2 )
        {
          AK::MemoryMgr::Free(g_DefaultPoolId, v7->m_paLoadedMedia);
          *((_BYTE *)v7 + 112) &= 0xFDu;
        }
        v7->m_paLoadedMedia = 0i64;
        AK::MemoryMgr::Free(v15, v7);
      }
      else
      {
LABEL_30:
        LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
      }
      if ( !v3 )
        break;
      LODWORD(v4) = v16;
    }
  }
}

// File Line: 1926
// RVA: 0xA5CAA0
void __fastcall CAkBankMgr::AddLoadedItem(CAkBankMgr *this, CAkUsageSlot *in_pUsageSlot, CAkIndexable *in_pIndexable)
{
  __int64 v3; // r10
  CAkIndexable **v4; // r9

  v3 = in_pUsageSlot->m_listLoadedItem.m_uLength;
  if ( (unsigned int)v3 < in_pUsageSlot->m_listLoadedItem.m_ulReserved )
  {
    v4 = &in_pUsageSlot->m_listLoadedItem.m_pItems[v3];
    in_pUsageSlot->m_listLoadedItem.m_uLength = v3 + 1;
    if ( v4 )
      *v4 = in_pIndexable;
  }
}

// File Line: 1948
// RVA: 0xA5F6A0
__int64 __fastcall CAkBankMgr::ProcessBankHeader(CAkBankMgr *this, AkBank::AkBankHeader *in_rBankHeader)
{
  AkBank::AkBankHeader *v2; // rdi
  CAkBankMgr *v3; // rsi
  unsigned int v4; // eax
  __int64 v5; // r9
  unsigned int v6; // ebx
  unsigned int v7; // edx
  unsigned int out_rulSizeSkipped; // [rsp+30h] [rbp+8h]
  int in_pBufferToFill; // [rsp+38h] [rbp+10h]
  int v11; // [rsp+3Ch] [rbp+14h]

  v2 = in_rBankHeader;
  v3 = this;
  if ( (unsigned int)CAkBankReader::FillDataEx(&this->m_BankReader, &in_pBufferToFill, 8u) != 1
    || in_pBufferToFill != 1145588546 )
  {
    v7 = 7;
    goto LABEL_11;
  }
  v4 = CAkBankReader::FillDataEx(&v3->m_BankReader, v2, 0x14u);
  v6 = v11 - 20;
  v7 = v4;
  if ( v4 == 1 )
  {
    if ( v11 != 20 )
    {
      out_rulSizeSkipped = 0;
      v7 = CAkBankReader::Skip(&v3->m_BankReader, v6, &out_rulSizeSkipped, v5);
      if ( v7 != 1 )
        goto LABEL_11;
      if ( out_rulSizeSkipped != v6 )
      {
        v7 = 56;
        goto LABEL_11;
      }
    }
    if ( v2->dwBankGeneratorVersion != 88 )
      v7 = 64;
  }
LABEL_11:
  v3->m_bFeedbackInBank = v2->bFeedbackInBank != 0;
  return v7;
}

// File Line: 1994
// RVA: 0xA5F750
unsigned int __fastcall CAkBankMgr::ProcessDataChunk(CAkBankMgr *this, unsigned int in_dwDataChunkSize, CAkUsageSlot *in_pUsageSlot)
{
  CAkUsageSlot *v3; // rbx
  unsigned __int64 v4; // rdi
  CAkBankMgr *v5; // rsi
  unsigned int result; // eax
  int v7; // eax
  char v8; // al
  int v9; // ecx
  char *v10; // rax
  char *v11; // rdx
  unsigned int out_rulSizeRead; // [rsp+48h] [rbp+10h]

  v3 = in_pUsageSlot;
  v4 = in_dwDataChunkSize;
  v5 = this;
  if ( !in_dwDataChunkSize )
    return 1;
  if ( in_pUsageSlot->m_memPoolId == -1 )
  {
    v7 = AK::MemoryMgr::CreatePool(0i64, in_dwDataChunkSize, in_dwDataChunkSize, 9u, 0x10u);
    v3->m_memPoolId = v7;
    if ( v7 == -1 )
      return 52;
    v3->m_bIsInternalPool = 1;
  }
  result = AK::MemoryMgr::CheckPoolId(v3->m_memPoolId);
  if ( result != 1 )
    return result;
  v8 = AK::MemoryMgr::GetPoolAttributes(v3->m_memPoolId);
  v9 = v3->m_memPoolId;
  if ( v8 & 8 )
  {
    if ( AK::MemoryMgr::GetBlockSize(v9) < (unsigned int)v4 )
      goto LABEL_13;
    v10 = (char *)AK::MemoryMgr::GetBlock(v3->m_memPoolId);
  }
  else
  {
    v10 = (char *)AK::MemoryMgr::Malloc(v9, v4);
  }
  v3->m_pData = v10;
LABEL_13:
  v11 = v3->m_pData;
  if ( !v11 )
    return 52;
  v3->m_uLoadedDataSize = v4;
  out_rulSizeRead = 0;
  result = CAkBankReader::FillData(&v5->m_BankReader, v11, v4, &out_rulSizeRead);
  if ( result == 1 && out_rulSizeRead != (_DWORD)v4 )
    result = 7;
  return result;
}

// File Line: 2089
// RVA: 0xA5FD70
__int64 __fastcall CAkBankMgr::ProcessHircChunk(CAkBankMgr *this, CAkUsageSlot *in_pUsageSlot, unsigned int in_dwBankID)
{
  CAkUsageSlot *v3; // rsi
  unsigned int v4; // er12
  CAkBankMgr *v5; // rdi
  unsigned int v6; // eax
  unsigned int v7; // ebx
  bool v8; // zf
  unsigned int v9; // eax
  bool v10; // cf
  char v11; // r14
  int v12; // er15
  __int64 v13; // r9
  CAkAudioLibIndex *v14; // rax
  CAkAudioLibIndex *v15; // rax
  CAkAudioLibIndex *v16; // rax
  CAkAudioLibIndex *v17; // rax
  CAkAudioLibIndex *v18; // rax
  AkBank::AKBKSubHircSection in_rSection; // [rsp+20h] [rbp-10h]
  unsigned int in_pBufferToFill; // [rsp+70h] [rbp+40h]
  unsigned int out_rulSizeSkipped; // [rsp+88h] [rbp+58h]

  v3 = in_pUsageSlot;
  v4 = in_dwBankID;
  v5 = this;
  in_pBufferToFill = 0;
  v6 = CAkBankReader::FillDataEx(&this->m_BankReader, &in_pBufferToFill, 4u);
  v7 = v6;
  v8 = v6 == 1;
  v9 = in_pBufferToFill;
  if ( v8 && in_pBufferToFill )
  {
    v10 = AkArray<MapStruct<unsigned long,unsigned long>,MapStruct<unsigned long,unsigned long> const &,ArrayPoolDefault,8,AkArrayAllocatorDefault>::GrowArray(
            (AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *)&v3->m_listLoadedItem,
            in_pBufferToFill) != 0;
    v9 = in_pBufferToFill;
    v7 = 2 - v10;
  }
  v11 = 0;
  v12 = 0;
  if ( v9 )
  {
    while ( 1 )
    {
      if ( v7 != 1 )
        return v7;
      v7 = CAkBankReader::FillDataEx(&v5->m_BankReader, &in_rSection, 5u);
      if ( v7 == 1 )
      {
        switch ( in_rSection.eHircType )
        {
          case 1:
            v7 = CAkBankMgr::ReadState(v5, &in_rSection, v3);
            break;
          case 2:
            v7 = CAkBankMgr::ReadSourceParent<CAkSound>(v5, &in_rSection, v3, v4);
            break;
          case 3:
            v7 = CAkBankMgr::ReadAction(v5, &in_rSection, v3);
            break;
          case 4:
            v7 = CAkBankMgr::ReadEvent(v5, &in_rSection, v3);
            break;
          case 5:
            v14 = CAkAudioLibIndex::GetNodeLock(g_pIndex, 0);
            v7 = CAkBankMgr::StdBankRead<CAkRanSeqCntr,CAkParameterNodeBase>(v5, &in_rSection, v3, &v14->m_idxAudioNode);
            break;
          case 6:
            v15 = CAkAudioLibIndex::GetNodeLock(g_pIndex, 0);
            v7 = CAkBankMgr::StdBankRead<CAkSwitchCntr,CAkParameterNodeBase>(v5, &in_rSection, v3, &v15->m_idxAudioNode);
            break;
          case 7:
            v17 = CAkAudioLibIndex::GetNodeLock(g_pIndex, 0);
            v7 = CAkBankMgr::StdBankRead<CAkActorMixer,CAkParameterNodeBase>(v5, &in_rSection, v3, &v17->m_idxAudioNode);
            break;
          case 8:
            v7 = CAkBankMgr::ReadBus(v5, &in_rSection, v3);
            break;
          case 9:
            v16 = CAkAudioLibIndex::GetNodeLock(g_pIndex, 0);
            v7 = CAkBankMgr::StdBankRead<CAkLayerCntr,CAkParameterNodeBase>(v5, &in_rSection, v3, &v16->m_idxAudioNode);
            break;
          case 0xE:
            v7 = CAkBankMgr::StdBankRead<CAkAttenuation,CAkAttenuation>(
                   v5,
                   &in_rSection,
                   v3,
                   &g_pIndex->m_idxAttenuations);
            break;
          case 0xF:
            v7 = CAkBankMgr::StdBankRead<CAkDialogueEvent,CAkDialogueEvent>(
                   v5,
                   &in_rSection,
                   v3,
                   &g_pIndex->m_idxDialogueEvents);
            break;
          case 0x10:
            v18 = CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Bus);
            v7 = CAkBankMgr::StdBankRead<CAkFeedbackBus,CAkParameterNodeBase>(
                   v5,
                   &in_rSection,
                   v3,
                   &v18->m_idxAudioNode);
            break;
          case 0x11:
            v7 = CAkBankMgr::ReadSourceParent<CAkFeedbackNode>(v5, &in_rSection, v3, v4);
            break;
          case 0x12:
            v7 = CAkBankMgr::StdBankRead<CAkFxShareSet,CAkFxShareSet>(v5, &in_rSection, v3, &g_pIndex->m_idxFxShareSets);
            break;
          case 0x13:
            v7 = CAkBankMgr::StdBankRead<CAkFxCustom,CAkFxCustom>(v5, &in_rSection, v3, &g_pIndex->m_idxFxCustom);
            break;
          case 0x14:
            v7 = CAkBankMgr::ReadAuxBus(v5, &in_rSection, v3);
            break;
          default:
            if ( !g_pExternalBankHandlerCallback )
            {
              if ( !v11 )
              {
                v11 = 0;
                if ( (unsigned __int8)(in_rSection.eHircType - 10) <= 3u )
                  v11 = 1;
              }
LABEL_30:
              out_rulSizeSkipped = 0;
              CAkBankReader::Skip(&v5->m_BankReader, in_rSection.dwSectionSize, &out_rulSizeSkipped, v13);
              if ( out_rulSizeSkipped != in_rSection.dwSectionSize )
                v7 = 7;
              break;
            }
            v7 = g_pExternalBankHandlerCallback(&in_rSection, v3, v4);
            if ( v7 == 3 )
              goto LABEL_30;
            break;
        }
      }
      if ( ++v12 >= in_pBufferToFill )
        return v7;
    }
  }
  return v7;
}

// File Line: 2224
// RVA: 0xA60100
signed __int64 __fastcall CAkBankMgr::ProcessStringMappingChunk(CAkBankMgr *this, unsigned int in_dwDataChunkSize, CAkUsageSlot *__formal)
{
  unsigned int v3; // esi
  CAkBankMgr *v4; // rbp
  unsigned int v5; // edi
  signed __int64 result; // rax
  int v7; // er14
  __int64 v8; // r9
  AkHashList<unsigned long,char *,31>::Item *v9; // rax
  void *v10; // rax
  void *v11; // rbx
  AkHashList<unsigned long,char *,31>::Item *v12; // rax
  char **v13; // rax
  unsigned int out_rulSizeSkipped; // [rsp+20h] [rbp-28h]
  char in_pBufferToFill; // [rsp+28h] [rbp-20h]
  unsigned int v16; // [rsp+2Ch] [rbp-1Ch]
  unsigned __int8 v17; // [rsp+58h] [rbp+10h]
  unsigned int in_Key; // [rsp+68h] [rbp+20h]

  v3 = in_dwDataChunkSize;
  v4 = this;
  v5 = 1;
  if ( !in_dwDataChunkSize )
    return 1i64;
  do
  {
    if ( v5 != 1 )
      break;
    result = CAkBankReader::FillDataEx(&v4->m_BankReader, &in_pBufferToFill, 8u);
    v5 = result;
    if ( (_DWORD)result != 1 )
      return result;
    v7 = 0;
    v3 -= 8;
    if ( v16 )
    {
      do
      {
        v5 = CAkBankReader::FillDataEx(&v4->m_BankReader, &in_Key, 4u);
        if ( v5 != 1 )
          break;
        v3 -= 4;
        v5 = CAkBankReader::FillDataEx(&v4->m_BankReader, &v17, 1u);
        if ( v5 != 1 )
          break;
        --v3;
        v9 = v4->m_BankIDToFileName.m_table[in_Key % 0x1F];
        if ( !v9 )
          goto LABEL_10;
        while ( v9->Assoc.key != in_Key )
        {
          v9 = v9->pNextItem;
          if ( !v9 )
            goto LABEL_10;
        }
        if ( v9 != (AkHashList<unsigned long,char *,31>::Item *)-16i64 )
        {
          CAkBankReader::Skip(&v4->m_BankReader, v17, &out_rulSizeSkipped, v8);
          v3 -= v17;
        }
        else
        {
LABEL_10:
          v10 = AK::MemoryMgr::Malloc(g_DefaultPoolId, v17 + 5);
          v11 = v10;
          if ( !v10 )
          {
            v5 = 52;
            break;
          }
          *((_BYTE *)v10 + v17) = 46;
          *((_BYTE *)v10 + v17 + 1) = 98;
          *((_BYTE *)v10 + v17 + 2) = 110;
          *((_BYTE *)v10 + v17 + 3) = 107;
          *((_BYTE *)v10 + v17 + 4) = 0;
          v5 = CAkBankReader::FillDataEx(&v4->m_BankReader, v10, v17);
          if ( v5 != 1 )
            goto LABEL_25;
          v3 -= v17;
          v12 = v4->m_BankIDToFileName.m_table[in_Key % 0x1F];
          if ( !v12 )
            goto LABEL_19;
          while ( v12->Assoc.key != in_Key )
          {
            v12 = v12->pNextItem;
            if ( !v12 )
              goto LABEL_19;
          }
          v13 = &v12->Assoc.item;
          if ( !v13 )
LABEL_19:
            v13 = AkHashList<unsigned long,char *,31>::CreateEntry(&v4->m_BankIDToFileName, in_Key, in_Key % 0x1F);
          if ( !v13 )
          {
            v5 = 52;
LABEL_25:
            AK::MemoryMgr::Free(g_DefaultPoolId, v11);
            break;
          }
          *v13 = (char *)v11;
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
  CAkBankMgr *v2; // rdi
  unsigned int v3; // ebx
  unsigned int i; // er14
  int v5; // esi
  unsigned int j; // esi
  unsigned int v7; // ebx
  AkRTPCGraphPointBase<unsigned long> *v8; // rax
  AkRTPCGraphPointBase<unsigned long> *v9; // r14
  unsigned int v11; // [rsp+30h] [rbp-30h]
  unsigned int v12; // [rsp+34h] [rbp-2Ch]
  int lTransitionTime; // [rsp+38h] [rbp-28h]
  float in_pBufferToFill; // [rsp+3Ch] [rbp-24h]
  int v15; // [rsp+40h] [rbp-20h]
  unsigned int in_ulStateID2; // [rsp+44h] [rbp-1Ch]
  unsigned int in_ulStateID1; // [rsp+48h] [rbp-18h]
  unsigned int in_ulStateGroupID; // [rsp+88h] [rbp+28h]
  unsigned int v19; // [rsp+90h] [rbp+30h]
  unsigned int in_RTPC_ID; // [rsp+98h] [rbp+38h]

  v2 = this;
  v3 = 1;
  if ( in_dwDataChunkSize )
  {
    v3 = CAkBankReader::FillDataEx(&this->m_BankReader, &in_pBufferToFill, 4u);
    AK::SoundEngine::SetVolumeThresholdInternal(in_pBufferToFill, AkCommandPriority_InitDefault);
    if ( v3 == 1 )
    {
      v3 = CAkBankReader::FillDataEx(&v2->m_BankReader, &in_ulStateGroupID, 2u);
      AK::SoundEngine::SetMaxNumVoicesLimitInternal(in_ulStateGroupID, AkCommandPriority_InitDefault);
    }
    v11 = 0;
    if ( v3 == 1 )
    {
      v3 = CAkBankReader::FillDataEx(&v2->m_BankReader, &v11, 4u);
      if ( v3 == 1 )
      {
        for ( i = 0; i < v11; ++i )
        {
          in_ulStateGroupID = 0;
          lTransitionTime = 0;
          in_RTPC_ID = 0;
          v3 = CAkBankReader::FillDataEx(&v2->m_BankReader, &in_ulStateGroupID, 4u);
          if ( v3 != 1 )
            break;
          v3 = CAkBankReader::FillDataEx(&v2->m_BankReader, &lTransitionTime, 4u);
          if ( v3 != 1 )
            break;
          v3 = 2 - ((unsigned int)CAkStateMgr::AddStateGroup(g_pStateMgr, in_ulStateGroupID) != 0);
          if ( v3 != 1 )
            break;
          v3 = CAkStateMgr::SetdefaultTransitionTime(g_pStateMgr, in_ulStateGroupID, lTransitionTime);
          if ( v3 != 1 )
            break;
          v3 = CAkBankReader::FillDataEx(&v2->m_BankReader, &in_RTPC_ID, 4u);
          if ( v3 != 1 )
            break;
          v5 = 0;
          if ( in_RTPC_ID > 0 )
          {
            do
            {
              v3 = CAkBankReader::FillDataEx(&v2->m_BankReader, &in_ulStateID1, 4u);
              if ( v3 != 1 )
                goto LABEL_19;
              v3 = CAkBankReader::FillDataEx(&v2->m_BankReader, &in_ulStateID2, 4u);
              if ( v3 != 1 )
                goto LABEL_19;
              v3 = CAkBankReader::FillDataEx(&v2->m_BankReader, &v15, 4u);
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
          v3 = CAkBankReader::FillDataEx(&v2->m_BankReader, &v12, 4u);
          if ( v3 == 1 )
          {
            for ( j = 0; j < v12; ++j )
            {
              v3 = CAkBankReader::FillDataEx(&v2->m_BankReader, &in_ulStateID1, 4u);
              if ( v3 != 1 )
                break;
              v3 = CAkBankReader::FillDataEx(&v2->m_BankReader, &in_RTPC_ID, 4u);
              if ( v3 != 1 )
                break;
              v3 = CAkBankReader::FillDataEx(&v2->m_BankReader, &in_ulStateGroupID, 4u);
              if ( v3 != 1 )
                break;
              if ( in_ulStateGroupID )
              {
                v7 = 12 * in_ulStateGroupID;
                v8 = (AkRTPCGraphPointBase<unsigned long> *)AK::MemoryMgr::Malloc(
                                                              g_DefaultPoolId,
                                                              12 * in_ulStateGroupID);
                v9 = v8;
                if ( !v8 )
                {
                  v3 = 52;
                  break;
                }
                v3 = CAkBankReader::FillDataEx(&v2->m_BankReader, v8, v7);
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
          v3 = CAkBankReader::FillDataEx(&v2->m_BankReader, &v19, 4u);
          if ( v3 == 1 && v19 > 0 )
          {
            do
            {
              v3 = CAkBankReader::FillDataEx(&v2->m_BankReader, &in_RTPC_ID, 4u);
              if ( v3 != 1 )
                break;
              v3 = CAkBankReader::FillDataEx(&v2->m_BankReader, &in_ulStateGroupID, 4u);
              if ( v3 != 1 )
                break;
              CAkRTPCMgr::SetDefaultParamValue(g_pRTPCMgr, in_RTPC_ID, *(float *)&in_ulStateGroupID);
              --v19;
            }
            while ( v19 );
          }
        }
      }
    }
  }
  return v3;
}

// File Line: 2527
// RVA: 0xA5F840
signed __int64 __fastcall CAkBankMgr::ProcessEnvSettingsChunk(CAkBankMgr *this, unsigned int in_dwDataChunkSize)
{
  CAkBankMgr *v2; // r14
  CAkEnvironmentsMgr::eCurveXType v4; // er15
  __int64 v5; // r12
  CAkEnvironmentsMgr::eCurveYType v6; // edi
  __int64 v7; // rbp
  unsigned int v8; // ebx
  AkRTPCGraphPointBase<float> *v9; // rax
  AkRTPCGraphPointBase<float> *in_paPoints; // rsi
  unsigned __int16 v11; // [rsp+30h] [rbp-38h]
  char in_pBufferToFill; // [rsp+80h] [rbp+18h]
  unsigned __int8 v13; // [rsp+88h] [rbp+20h]

  v2 = this;
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
      v8 = CAkBankReader::FillDataEx(&v2->m_BankReader, &in_pBufferToFill, 1u);
      if ( v8 != 1 )
        break;
      g_pEnvironmentMgr->m_bCurveEnabled[v5][v7] = in_pBufferToFill != 0;
      v8 = CAkBankReader::FillDataEx(&v2->m_BankReader, &v13, 1u);
      if ( v8 != 1 )
        break;
      v8 = CAkBankReader::FillDataEx(&v2->m_BankReader, &v11, 2u);
      if ( v8 != 1 )
        break;
      v9 = (AkRTPCGraphPointBase<float> *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 12i64 * v11);
      in_paPoints = v9;
      if ( !v9 )
        return 52;
      v8 = CAkBankReader::FillDataEx(&v2->m_BankReader, v9, 12 * (unsigned int)v11);
      if ( v8 == 1 )
        CAkEnvironmentsMgr::SetObsOccCurve(g_pEnvironmentMgr, v4, v6, v11, in_paPoints, (AkCurveScaling)v13);
      AK::MemoryMgr::Free(g_DefaultPoolId, in_paPoints);
      if ( v8 != 1 )
        return v8;
      ++v6;
      ++v7;
      if ( (signed int)v6 >= 2 )
      {
        ++v4;
        ++v5;
        if ( (signed int)v4 < 2 )
          goto LABEL_5;
        return v8;
      }
    }
  }
  else
  {
    v8 = 2;
  }
  return v8;
}

// File Line: 2602
// RVA: 0xA60870
signed __int64 __fastcall CAkBankMgr::ReadState(CAkBankMgr *this, AkBank::AKBKSubHircSection *in_rSection, CAkUsageSlot *in_pUsageSlot)
{
  AkBank::AKBKSubHircSection *v3; // r13
  CAkUsageSlot *v4; // rsi
  CAkBankMgr *v5; // r15
  AKRESULT v6; // ebx
  unsigned int *v7; // rax
  char *v8; // r14
  unsigned int v10; // ebp
  CAkIndexable *v11; // rdi
  CAkState *v12; // rax
  __int64 v13; // rdx
  CAkIndexable **v14; // r8

  v3 = in_rSection;
  v4 = in_pUsageSlot;
  v5 = this;
  v6 = 1;
  v7 = (unsigned int *)CAkBankReader::GetData(&this->m_BankReader, in_rSection->dwSectionSize);
  v8 = (char *)v7;
  if ( !v7 )
    return 2i64;
  v10 = *v7;
  v11 = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
          (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxCustomStates,
          *v7);
  if ( v11 )
    goto LABEL_15;
  EnterCriticalSection(&g_csMain.m_csLock);
  v12 = CAkState::Create(v10);
  v11 = (CAkIndexable *)&v12->vfptr;
  if ( v12 )
  {
    v6 = CAkState::SetInitialValues(v12, v8, v3->dwSectionSize);
    if ( v6 != 1 )
      v11->vfptr->Release(v11);
  }
  else
  {
    v6 = 2;
  }
  LeaveCriticalSection(&g_csMain.m_csLock);
  if ( v6 == 1 )
  {
LABEL_15:
    v13 = v4->m_listLoadedItem.m_uLength;
    if ( (unsigned int)v13 < v4->m_listLoadedItem.m_ulReserved )
    {
      v14 = &v4->m_listLoadedItem.m_pItems[v13];
      v4->m_listLoadedItem.m_uLength = v13 + 1;
      if ( v14 )
        *v14 = v11;
    }
  }
  CAkBankReader::ReleaseData(&v5->m_BankReader);
  return (unsigned int)v6;
}

// File Line: 2646
// RVA: 0xA60640
signed __int64 __fastcall CAkBankMgr::ReadBus(CAkBankMgr *this, AkBank::AKBKSubHircSection *in_rSection, CAkUsageSlot *in_pUsageSlot)
{
  AkBank::AKBKSubHircSection *v3; // r13
  CAkUsageSlot *v4; // rbp
  CAkBankMgr *v5; // rsi
  unsigned int v6; // ebx
  unsigned int *v7; // rax
  unsigned int *v8; // r15
  unsigned int v10; // er14
  CAkIndexable *v11; // rdi
  CAkBus *v12; // rax
  __int64 v13; // rdx
  CAkIndexable **v14; // r8

  v3 = in_rSection;
  v4 = in_pUsageSlot;
  v5 = this;
  v6 = 1;
  v7 = (unsigned int *)CAkBankReader::GetData(&this->m_BankReader, in_rSection->dwSectionSize);
  v8 = v7;
  if ( !v7 )
    return 2i64;
  v10 = *v7;
  v11 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, *v7, AkNodeType_Bus);
  if ( v11 )
    goto LABEL_18;
  if ( !v5->m_bIsFirstBusLoaded )
    CAkBus::ClearMasterBus();
  EnterCriticalSection(&g_csMain.m_csLock);
  v12 = CAkBus::Create(v10);
  v11 = (CAkIndexable *)&v12->vfptr;
  if ( v12 )
  {
    v6 = ((__int64 (__fastcall *)(CAkBus *, unsigned int *, _QWORD))v12->vfptr[20].AddRef)(v12, v8, v3->dwSectionSize);
    if ( v6 != 1 )
      v11->vfptr->Release(v11);
  }
  else
  {
    v6 = 2;
  }
  LeaveCriticalSection(&g_csMain.m_csLock);
  if ( v6 == 1 )
  {
LABEL_18:
    v13 = v4->m_listLoadedItem.m_uLength;
    if ( (unsigned int)v13 < v4->m_listLoadedItem.m_ulReserved )
    {
      v14 = &v4->m_listLoadedItem.m_pItems[v13];
      v4->m_listLoadedItem.m_uLength = v13 + 1;
      if ( v14 )
        *v14 = v11;
    }
    v5->m_bIsFirstBusLoaded = 1;
  }
  CAkBankReader::ReleaseData(&v5->m_BankReader);
  return v6;
}

// File Line: 2701
// RVA: 0xA60540
signed __int64 __fastcall CAkBankMgr::ReadAuxBus(CAkBankMgr *this, AkBank::AKBKSubHircSection *in_rSection, CAkUsageSlot *in_pUsageSlot)
{
  AkBank::AKBKSubHircSection *v3; // r13
  CAkUsageSlot *v4; // rsi
  CAkBankMgr *v5; // r15
  unsigned int v6; // ebx
  unsigned int *v7; // rax
  unsigned int *v8; // r14
  unsigned int v10; // ebp
  CAkIndexable *v11; // rdi
  CAkAuxBus *v12; // rax
  __int64 v13; // rdx
  CAkIndexable **v14; // r8

  v3 = in_rSection;
  v4 = in_pUsageSlot;
  v5 = this;
  v6 = 1;
  v7 = (unsigned int *)CAkBankReader::GetData(&this->m_BankReader, in_rSection->dwSectionSize);
  v8 = v7;
  if ( !v7 )
    return 2i64;
  v10 = *v7;
  v11 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, *v7, AkNodeType_Bus);
  if ( v11 )
    goto LABEL_15;
  EnterCriticalSection(&g_csMain.m_csLock);
  v12 = CAkAuxBus::Create(v10);
  v11 = (CAkIndexable *)&v12->vfptr;
  if ( v12 )
  {
    v6 = ((__int64 (__fastcall *)(CAkAuxBus *, unsigned int *, _QWORD))v12->vfptr[20].AddRef)(
           v12,
           v8,
           v3->dwSectionSize);
    if ( v6 != 1 )
      v11->vfptr->Release(v11);
  }
  else
  {
    v6 = 2;
  }
  LeaveCriticalSection(&g_csMain.m_csLock);
  if ( v6 == 1 )
  {
LABEL_15:
    v13 = v4->m_listLoadedItem.m_uLength;
    if ( (unsigned int)v13 < v4->m_listLoadedItem.m_ulReserved )
    {
      v14 = &v4->m_listLoadedItem.m_pItems[v13];
      v4->m_listLoadedItem.m_uLength = v13 + 1;
      if ( v14 )
        *v14 = v11;
    }
  }
  CAkBankReader::ReleaseData(&v5->m_BankReader);
  return v6;
}

// File Line: 2744
// RVA: 0xA603F0
signed __int64 __fastcall CAkBankMgr::ReadAction(CAkBankMgr *this, AkBank::AKBKSubHircSection *in_rSection, CAkUsageSlot *in_pUsageSlot)
{
  AkBank::AKBKSubHircSection *v3; // r15
  CAkUsageSlot *v4; // rsi
  CAkBankMgr *v5; // r13
  AKRESULT v6; // ebx
  char *v7; // rax
  char *v8; // r14
  AkActionType v10; // ebp
  unsigned int v11; // er12
  CAkIndexable *v12; // rax
  CAkAction *v13; // rdi
  CAkAction *v14; // rax
  __int64 v15; // rdx
  CAkAction **v16; // r8

  v3 = in_rSection;
  v4 = in_pUsageSlot;
  v5 = this;
  v6 = 1;
  v7 = CAkBankReader::GetData(&this->m_BankReader, in_rSection->dwSectionSize);
  v8 = v7;
  if ( !v7 )
    return 2i64;
  v10 = *((unsigned __int16 *)v7 + 2);
  v11 = *(_DWORD *)v7;
  v12 = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
          (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxActions,
          *(_DWORD *)v7);
  v13 = (CAkAction *)v12;
  if ( v12 )
  {
    if ( v10 != 1027 || BYTE6(v12[2].vfptr) & 0x20 )
    {
LABEL_13:
      v15 = v4->m_listLoadedItem.m_uLength;
      if ( (unsigned int)v15 < v4->m_listLoadedItem.m_ulReserved )
      {
        v16 = (CAkAction **)&v4->m_listLoadedItem.m_pItems[v15];
        v4->m_listLoadedItem.m_uLength = v15 + 1;
        if ( v16 )
          *v16 = v13;
      }
      goto LABEL_16;
    }
    EnterCriticalSection(&g_csMain.m_csLock);
    v6 = CAkAction::SetInitialValues(v13, v8, v3->dwSectionSize);
    if ( v6 != 1 )
      v13->vfptr->Release((CAkIndexable *)&v13->vfptr);
  }
  else
  {
    EnterCriticalSection(&g_csMain.m_csLock);
    v14 = CAkAction::Create(v10, v11);
    v13 = v14;
    if ( v14 )
    {
      v6 = CAkAction::SetInitialValues(v14, v8, v3->dwSectionSize);
      if ( v6 != 1 )
        v13->vfptr->Release((CAkIndexable *)&v13->vfptr);
    }
    else
    {
      v6 = 2;
    }
  }
  LeaveCriticalSection(&g_csMain.m_csLock);
  if ( v6 == 1 )
    goto LABEL_13;
LABEL_16:
  CAkBankReader::ReleaseData(&v5->m_BankReader);
  return (unsigned int)v6;
}

// File Line: 2805
// RVA: 0xA60760
signed __int64 __fastcall CAkBankMgr::ReadEvent(CAkBankMgr *this, AkBank::AKBKSubHircSection *in_rSection, CAkUsageSlot *in_pUsageSlot)
{
  AkBank::AKBKSubHircSection *v3; // r13
  CAkUsageSlot *v4; // rsi
  CAkBankMgr *v5; // r15
  AKRESULT v6; // ebx
  unsigned int *v7; // rax
  char *v8; // r14
  unsigned int v10; // ebp
  CAkEvent *v11; // rdi
  __int64 v12; // rdx
  CAkEvent **v13; // r8

  v3 = in_rSection;
  v4 = in_pUsageSlot;
  v5 = this;
  v6 = 1;
  v7 = (unsigned int *)CAkBankReader::GetData(&this->m_BankReader, in_rSection->dwSectionSize);
  v8 = (char *)v7;
  if ( !v7 )
    return 2i64;
  v10 = *v7;
  v11 = (CAkEvent *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                      (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxEvents,
                      *v7);
  if ( v11 )
  {
LABEL_10:
    v12 = v4->m_listLoadedItem.m_uLength;
    if ( (unsigned int)v12 < v4->m_listLoadedItem.m_ulReserved )
    {
      v13 = (CAkEvent **)&v4->m_listLoadedItem.m_pItems[v12];
      v4->m_listLoadedItem.m_uLength = v12 + 1;
      if ( v13 )
        *v13 = v11;
    }
    goto LABEL_13;
  }
  v11 = CAkEvent::CreateNoIndex(v10);
  if ( v11 )
  {
    EnterCriticalSection(&g_csMain.m_csLock);
    v6 = CAkEvent::SetInitialValues(v11, v8, v3->dwSectionSize);
    if ( v6 == 1 )
      CAkEvent::AddToIndex(v11);
    else
      v11->vfptr->Release((CAkIndexable *)&v11->vfptr);
    LeaveCriticalSection(&g_csMain.m_csLock);
    if ( v6 != 1 )
      goto LABEL_13;
    goto LABEL_10;
  }
  v6 = 2;
LABEL_13:
  CAkBankReader::ReleaseData(&v5->m_BankReader);
  return (unsigned int)v6;
}

// File Line: 2858
// RVA: 0xA5CDC0
void __fastcall CAkBankMgr::ClearPreparedEvents(CAkBankMgr *this)
{
  CAkBankMgr *v1; // rbp
  _RTL_CRITICAL_SECTION *v2; // r13
  _RTL_CRITICAL_SECTION_DEBUG *i; // r14
  __int64 v4; // rsi
  _RTL_CRITICAL_SECTION_DEBUG *v5; // r15
  _LIST_ENTRY *v6; // rbx
  _LIST_ENTRY *v7; // rdi
  CAkUsageSlot *v8; // rax
  unsigned __int64 v9; // [rsp+20h] [rbp-48h]
  __int128 v10; // [rsp+30h] [rbp-38h]

  v1 = this;
  v2 = &g_pIndex->m_idxEvents.m_IndexLock.m_csLock;
  EnterCriticalSection(&g_csMain.m_csLock);
  EnterCriticalSection(v2);
  i = v2[1].DebugInfo;
  LODWORD(v4) = 0;
  if ( i )
  {
    while ( 1 )
    {
LABEL_6:
      while ( 1 )
      {
        v5 = i;
        if ( !i->EntryCount )
          break;
        (*(void (__fastcall **)(_RTL_CRITICAL_SECTION_DEBUG *))(*(_QWORD *)&i->Type + 8i64))(i);
        if ( i->EntryCount )
        {
          v6 = i->ProcessLocksList.Blink;
          i->EntryCount = 0;
          while ( v6 )
          {
            v7 = v6;
            v6 = v6[1].Blink;
            if ( WORD2(v7[3].Flink) == 1027 )
            {
              CAkParameterNodeBase::UnPrepareNodeData((unsigned int)v7[3].Flink);
              LODWORD(v9) = v7[3].Blink;
              _mm_store_si128((__m128i *)&v10, (__m128i)v9);
              v8 = CAkBankList::Get(&v1->m_BankList, (AkBankKey *)&v10);
              if ( v8 )
                CAkUsageSlot::ReleasePrepare(v8, 0);
            }
          }
          (*(void (__fastcall **)(_RTL_CRITICAL_SECTION_DEBUG *))(*(_QWORD *)&i->Type + 16i64))(i);
        }
        for ( i = (_RTL_CRITICAL_SECTION_DEBUG *)i->CriticalSection;
              !i;
              i = (_RTL_CRITICAL_SECTION_DEBUG *)*((_QWORD *)&v2[1].DebugInfo + v4) )
        {
          v4 = (unsigned int)(v4 + 1);
          if ( (unsigned int)v4 >= 0xC1 )
            break;
        }
        (*(void (__fastcall **)(_RTL_CRITICAL_SECTION_DEBUG *))(*(_QWORD *)&v5->Type + 16i64))(v5);
LABEL_18:
        if ( !i )
          goto LABEL_19;
      }
      i = (_RTL_CRITICAL_SECTION_DEBUG *)i->CriticalSection;
      if ( !i )
      {
        while ( 1 )
        {
          v4 = (unsigned int)(v4 + 1);
          if ( (unsigned int)v4 >= 0xC1 )
            goto LABEL_18;
          i = (_RTL_CRITICAL_SECTION_DEBUG *)*((_QWORD *)&v2[1].DebugInfo + v4);
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
    i = (_RTL_CRITICAL_SECTION_DEBUG *)*((_QWORD *)&v2[1].DebugInfo + v4);
    if ( i )
      goto LABEL_6;
  }
  if ( i )
    goto LABEL_6;
LABEL_19:
  LeaveCriticalSection(v2);
  LeaveCriticalSection(&g_csMain.m_csLock);
}

// File Line: 2887
// RVA: 0xA5E360
signed __int64 __fastcall CAkBankMgr::LoadMediaIndex(CAkBankMgr *this, CAkUsageSlot *in_pCurrentSlot, unsigned int in_uIndexChunkSize, __int64 in_bIsLoadedFromMemory)
{
  CAkUsageSlot *v4; // rbx
  CAkBankMgr *v5; // rsi
  unsigned int v6; // edi
  signed __int64 result; // rax
  unsigned __int64 v8; // r14
  unsigned int v9; // ebp
  AkBank::MediaHeader *v10; // rax
  char *v11; // rax
  unsigned int out_rulSizeSkipped; // [rsp+48h] [rbp+10h]

  v4 = in_pCurrentSlot;
  v5 = this;
  v6 = 1;
  if ( in_pCurrentSlot->m_uNumLoadedItems )
  {
    CAkBankReader::Skip(&this->m_BankReader, in_uIndexChunkSize, &out_rulSizeSkipped, in_bIsLoadedFromMemory);
    result = 1i64;
  }
  else
  {
    v8 = (unsigned __int64)(in_uIndexChunkSize * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 3;
    v9 = 12 * v8;
    if ( (_BYTE)in_bIsLoadedFromMemory )
    {
      v11 = CAkBankReader::GetData(&this->m_BankReader, v9);
      if ( !v4->m_paLoadedMedia )
        v4->m_paLoadedMedia = (AkBank::MediaHeader *)v11;
      CAkBankReader::ReleaseData(&v5->m_BankReader);
    }
    else
    {
      v10 = (AkBank::MediaHeader *)AK::MemoryMgr::Malloc(g_DefaultPoolId, v9);
      v4->m_paLoadedMedia = v10;
      if ( v10 )
      {
        *((_BYTE *)v4 + 112) |= 2u;
        CAkBankReader::FillDataEx(&v5->m_BankReader, v10, v9);
      }
      else
      {
        v6 = 52;
      }
    }
    result = v6;
    if ( v4->m_paLoadedMedia )
      v4->m_uIndexSize = v8;
  }
  return result;
}

// File Line: 2939
// RVA: 0xA5E1B0
signed __int64 __fastcall CAkBankMgr::LoadMedia(CAkBankMgr *this, char *in_pDataBank, CAkUsageSlot *in_pCurrentSlot, bool __formal)
{
  CAkUsageSlot *v4; // rsi
  CAkBankMgr *v5; // r13
  unsigned int v6; // eax
  unsigned int v7; // er12
  __int64 v8; // rbp
  unsigned int *v9; // r15
  unsigned int v10; // ecx
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v11; // rax
  char v12; // r14
  AkMediaEntry *v13; // rdi
  char *v15; // [rsp+58h] [rbp+10h]

  v15 = in_pDataBank;
  v4 = in_pCurrentSlot;
  v5 = this;
  if ( in_pCurrentSlot->m_uNumLoadedItems )
    return 1i64;
  v6 = in_pCurrentSlot->m_uIndexSize;
  if ( !v6 )
    return 1i64;
  v7 = 52;
  if ( !in_pCurrentSlot->m_paLoadedMedia )
    goto LABEL_25;
  v8 = 0i64;
  if ( !v6 )
    goto LABEL_22;
  while ( 1 )
  {
    v9 = &v4->m_paLoadedMedia[v8].id;
    if ( *v9 )
      break;
LABEL_15:
    ++v4->m_uNumLoadedItems;
    v8 = (unsigned int)(v8 + 1);
    if ( (unsigned int)v8 >= v4->m_uIndexSize )
      goto LABEL_22;
  }
  EnterCriticalSection(&v5->m_MediaLock.m_csLock);
  v10 = *v9;
  v11 = v5->m_MediaHashTable.m_table[*v9 % 193];
  if ( !v11 )
    goto LABEL_9;
  while ( v11->Assoc.key != v10 )
  {
    v11 = v11->pNextItem;
    if ( !v11 )
      goto LABEL_9;
  }
  v13 = &v11->Assoc.item;
  if ( v11 != (AkHashList<unsigned long,AkMediaEntry,193>::Item *)-16i64 )
  {
    v12 = 1;
    if ( v13->m_preparedMediaInfo.pInMemoryData )
      goto LABEL_13;
  }
  else
  {
LABEL_9:
    v12 = 0;
    v13 = AkHashList<unsigned long,AkMediaEntry,193>::CreateEntry(&v5->m_MediaHashTable, v10, *v9 % 193);
  }
  if ( !v13 )
    goto LABEL_21;
  v13->m_sourceID = *v9;
  v7 = AkMediaEntry::AddAlternateBank(v13, &v15[v9[1]], v9[2], v4);
  if ( v7 == 1 )
  {
    if ( !v12 )
    {
LABEL_14:
      LeaveCriticalSection(&v5->m_MediaLock.m_csLock);
      goto LABEL_15;
    }
LABEL_13:
    ++v13->uRefCount;
    goto LABEL_14;
  }
  AkHashList<unsigned long,AkMediaEntry,193>::Unset(&v5->m_MediaHashTable, *v9);
LABEL_21:
  LeaveCriticalSection(&v5->m_MediaLock.m_csLock);
LABEL_22:
  if ( v4->m_uIndexSize == (_DWORD)v8 )
    return 1i64;
  if ( v7 != 1 )
LABEL_25:
    CAkBankMgr::UnloadMedia(v5, v4);
  return v7;
}

// File Line: 3011
// RVA: 0xA5F1A0
__int64 __fastcall CAkBankMgr::PrepareMedia(CAkBankMgr *this, CAkUsageSlot *in_pCurrentSlot, unsigned int in_dwDataChunkSize, __int64 a4)
{
  CAkUsageSlot *v4; // rbp
  CAkBankMgr *v5; // r15
  unsigned int v6; // esi
  CAkLock *v7; // rbx
  int v8; // edx
  unsigned int v9; // eax
  unsigned int v10; // er12
  __int64 v11; // rcx
  unsigned int *v12; // rcx
  unsigned int v13; // er14
  int v14; // eax
  unsigned __int64 v15; // r13
  unsigned __int64 v16; // r8
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v17; // rax
  AkMediaEntry *v18; // rdi
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v19; // rax
  char *v20; // rax
  char *v21; // r15
  __int64 v22; // r9
  unsigned int v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // er12
  signed __int64 v26; // rdi
  unsigned int v27; // edx
  bool v28; // zf
  int v30; // [rsp+20h] [rbp-48h]
  unsigned int out_rulSizeSkipped; // [rsp+24h] [rbp-44h]
  __int64 v32; // [rsp+28h] [rbp-40h]
  CAkBankMgr *v33; // [rsp+70h] [rbp+8h]
  unsigned int v34; // [rsp+80h] [rbp+18h]
  int v35; // [rsp+88h] [rbp+20h]

  v34 = in_dwDataChunkSize;
  v33 = this;
  v4 = in_pCurrentSlot;
  v5 = this;
  v6 = 1;
  if ( !in_dwDataChunkSize )
    return v6;
  LODWORD(v7) = 0;
  v8 = 0;
  v9 = v4->m_uIndexSize;
  v10 = 0;
  v30 = 0;
  v35 = 0;
  if ( v4->m_uNumLoadedItems < v9 )
  {
    v11 = 0i64;
    v32 = 0i64;
    while ( 1 )
    {
      v12 = (unsigned int *)((char *)&v4->m_paLoadedMedia->id + v11);
      v13 = *v12;
      v14 = v12[1] - v8;
      v8 = v12[1];
      v10 += v14;
      v35 = v12[1];
      if ( v13 )
        break;
      ++v4->m_uNumLoadedItems;
LABEL_38:
      v24 = v4->m_uIndexSize;
      ++v30;
      v11 = v32 + 12;
      v32 += 12i64;
      if ( v4->m_uNumLoadedItems >= v24 )
      {
        LODWORD(v7) = v30;
        goto LABEL_40;
      }
    }
    v15 = v12[2];
    v7 = &v5->m_MediaLock;
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
      v18 = &v17->Assoc.item;
    }
    else
    {
LABEL_9:
      v18 = 0i64;
    }
    if ( v18 )
    {
      ++v18->uRefCount;
      if ( v18->m_preparedMediaInfo.pInMemoryData )
      {
        ++v4->m_uNumLoadedItems;
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
      v18 = &v19->Assoc.item;
      if ( v19 == (AkHashList<unsigned long,AkMediaEntry,193>::Item *)-16i64 )
      {
LABEL_19:
        v18 = AkHashList<unsigned long,AkMediaEntry,193>::CreateEntry(&v5->m_MediaHashTable, v13, v16);
        if ( !v18 )
        {
          v6 = 2;
          LeaveCriticalSection(&v5->m_MediaLock.m_csLock);
          LODWORD(v7) = v30;
          goto LABEL_44;
        }
      }
      v18->m_sourceID = v13;
    }
    if ( v18->m_BankSlots.m_uLength )
    {
      LODWORD(v15) = v18->m_BankSlots.m_pItems->item.uInMemoryDataSize;
      if ( in_PoolId == -1 )
        goto LABEL_51;
      v20 = (char *)AK::MemoryMgr::Malign(in_PoolId, (unsigned int)v15, 0x10u);
      v21 = v20;
      if ( !v20 )
        goto LABEL_51;
      memmove(v20, v18->m_BankSlots.m_pItems->item.pInMemoryData, (unsigned int)v15);
      v6 = 1;
LABEL_36:
      v18->m_preparedMediaInfo.uInMemoryDataSize = v15;
      v18->m_preparedMediaInfo.pInMemoryData = v21;
      ++v4->m_uNumLoadedItems;
      LeaveCriticalSection(&v7->m_csLock);
      v5 = v33;
      goto LABEL_37;
    }
    if ( in_PoolId == -1 || (v21 = (char *)AK::MemoryMgr::Malign(in_PoolId, v15, 0x10u)) == 0i64 )
    {
LABEL_51:
      v6 = 52;
      goto LABEL_52;
    }
    LeaveCriticalSection(&v7->m_csLock);
    if ( !v10 )
      goto LABEL_64;
    out_rulSizeSkipped = 0;
    v23 = CAkBankReader::Skip(&v33->m_BankReader, v10, &out_rulSizeSkipped, v22);
    v6 = v23;
    if ( v10 != out_rulSizeSkipped )
    {
      v6 = 2;
      goto LABEL_35;
    }
    v10 = 0;
    if ( v23 == 1 )
    {
LABEL_64:
      out_rulSizeSkipped = 0;
      v6 = CAkBankReader::FillData(&v33->m_BankReader, v21, v15, &out_rulSizeSkipped);
      if ( v6 != 1 || (_DWORD)v15 == out_rulSizeSkipped )
        v35 += out_rulSizeSkipped;
      else
        v6 = 2;
    }
LABEL_35:
    EnterCriticalSection(&v7->m_csLock);
    if ( v6 != 1 )
    {
      AK::MemoryMgr::Free(in_PoolId, v21);
LABEL_52:
      v28 = v18->uRefCount-- == 1;
      if ( v28 && v18->m_preparedMediaInfo.pInMemoryData )
      {
        AK::MemoryMgr::Free(in_PoolId, v18->m_preparedMediaInfo.pInMemoryData);
        v18->m_preparedMediaInfo.pInMemoryData = 0i64;
        v18->m_preparedMediaInfo.uInMemoryDataSize = 0;
      }
      v5 = v33;
      if ( !v18->uRefCount )
        AkHashList<unsigned long,AkMediaEntry,193>::Unset(&v33->m_MediaHashTable, v13);
      LeaveCriticalSection(&v7->m_csLock);
      LODWORD(v7) = v30;
      if ( v6 == 1 )
      {
LABEL_40:
        in_dwDataChunkSize = v34;
        goto LABEL_41;
      }
LABEL_44:
      v7 = (CAkLock *)(signed int)v7;
      if ( (signed int)v7 > 0i64 )
      {
        v26 = (signed __int64)v7;
        do
        {
          --v26;
          v7 = (CAkLock *)((char *)v7 - 1);
          v27 = v4->m_paLoadedMedia[v26].id;
          if ( v27 )
            CAkBankMgr::ReleaseSingleMedia(v5, v27);
        }
        while ( (signed __int64)v7 > 0 );
      }
      return v6;
    }
    goto LABEL_36;
  }
LABEL_41:
  v25 = in_dwDataChunkSize - v35 + v10;
  if ( v25 )
  {
    v5 = v33;
    v34 = 0;
    CAkBankReader::Skip(&v33->m_BankReader, v25, &v34, a4);
    if ( v25 != v34 )
    {
      v6 = 2;
      goto LABEL_44;
    }
  }
  *((_BYTE *)v4 + 112) |= 4u;
  return v6;
}

// File Line: 3180
// RVA: 0xA61B10
void __fastcall CAkBankMgr::UnloadMedia(CAkBankMgr *this, CAkUsageSlot *in_pCurrentSlot)
{
  CAkUsageSlot *v2; // rbp
  CAkBankMgr *v3; // r13
  unsigned int v4; // er8
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v5; // r14
  signed __int64 v6; // rsi
  signed __int64 v7; // r15
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v8; // rdi
  CAkUsageSlot **v9; // rax
  __int64 v10; // rdx
  signed __int64 v11; // rcx
  bool v12; // zf
  char *v13; // rdx
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v14; // rcx
  MapStruct<CAkUsageSlot *,AkMediaInfo> *v15; // rdx

  v2 = in_pCurrentSlot;
  v3 = this;
  if ( in_pCurrentSlot->m_paLoadedMedia )
  {
    EnterCriticalSection(&this->m_MediaLock.m_csLock);
    while ( v2->m_uNumLoadedItems )
    {
      v4 = v2->m_paLoadedMedia[--v2->m_uNumLoadedItems].id;
      if ( v4 )
      {
        v5 = 0i64;
        v6 = v4 % 0xC1;
        v7 = v6;
        v8 = v3->m_MediaHashTable.m_table[v6];
        if ( v8 )
        {
          while ( v8->Assoc.key != v4 )
          {
            v5 = v8;
            v8 = v8->pNextItem;
            if ( !v8 )
              goto LABEL_28;
          }
          v9 = &v8->Assoc.item.m_BankSlots.m_pItems->key;
          v10 = v8->Assoc.item.m_BankSlots.m_uLength;
          v11 = (signed __int64)&v9[3 * v10];
          if ( v9 != (CAkUsageSlot **)v11 )
          {
            do
            {
              if ( *v9 == v2 )
                break;
              v9 += 3;
            }
            while ( v9 != (CAkUsageSlot **)v11 );
            if ( v9 != (CAkUsageSlot **)v11 )
            {
              if ( (unsigned int)v10 > 1 )
              {
                *v9 = *(CAkUsageSlot **)(v11 - 24);
                v9[1] = *(CAkUsageSlot **)(v11 - 16);
                v9[2] = *(CAkUsageSlot **)(v11 - 8);
              }
              --v8->Assoc.item.m_BankSlots.m_uLength;
            }
          }
          v12 = v8->Assoc.item.uRefCount-- == 1;
          if ( v12 )
          {
            v13 = v8->Assoc.item.m_preparedMediaInfo.pInMemoryData;
            if ( v13 )
            {
              AK::MemoryMgr::Free(in_PoolId, v13);
              v8->Assoc.item.m_preparedMediaInfo.pInMemoryData = 0i64;
              v8->Assoc.item.m_preparedMediaInfo.uInMemoryDataSize = 0;
            }
          }
          if ( !v8->Assoc.item.uRefCount )
          {
            v14 = v8->pNextItem;
            if ( !v8->pNextItem )
            {
              do
                v6 = (unsigned int)(v6 + 1);
              while ( (unsigned int)v6 < 0xC1 && !v3->m_MediaHashTable.m_table[v6] );
            }
            if ( v5 )
              v5->pNextItem = v14;
            else
              v3->m_MediaHashTable.m_table[v7] = v14;
            v15 = v8->Assoc.item.m_BankSlots.m_pItems;
            if ( v15 )
            {
              v8->Assoc.item.m_BankSlots.m_uLength = 0;
              AK::MemoryMgr::Free(g_DefaultPoolId, v15);
              v8->Assoc.item.m_BankSlots.m_pItems = 0i64;
              v8->Assoc.item.m_BankSlots.m_ulReserved = 0;
            }
            AK::MemoryMgr::Free(v3->m_MediaHashTable.m_MemPoolId, v8);
            --v3->m_MediaHashTable.m_uiSize;
          }
        }
      }
LABEL_28:
      ;
    }
    LeaveCriticalSection(&v3->m_MediaLock.m_csLock);
  }
}

// File Line: 3211
// RVA: 0xA615D0
void __fastcall CAkBankMgr::UnPrepareMedia(CAkBankMgr *this, CAkUsageSlot *in_pCurrentSlot)
{
  CAkUsageSlot *v2; // r15
  CAkBankMgr *v3; // r13
  unsigned int v4; // ebp
  unsigned int v5; // er8
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v6; // r14
  signed __int64 v7; // rsi
  signed __int64 v8; // r12
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v9; // rdi
  bool v10; // zf
  char *v11; // rdx
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v12; // rcx
  MapStruct<CAkUsageSlot *,AkMediaInfo> *v13; // rdx

  v2 = in_pCurrentSlot;
  v3 = this;
  if ( *((_BYTE *)in_pCurrentSlot + 112) & 4 && in_pCurrentSlot->m_paLoadedMedia )
  {
    EnterCriticalSection(&this->m_MediaLock.m_csLock);
    v4 = 0;
    if ( v2->m_uNumLoadedItems )
    {
      do
      {
        v5 = v2->m_paLoadedMedia[v4].id;
        if ( v5 )
        {
          v6 = 0i64;
          v7 = v5 % 0xC1;
          v8 = v7;
          v9 = v3->m_MediaHashTable.m_table[v7];
          if ( v9 )
          {
            while ( v9->Assoc.key != v5 )
            {
              v6 = v9;
              v9 = v9->pNextItem;
              if ( !v9 )
                goto LABEL_22;
            }
            v10 = v9->Assoc.item.uRefCount-- == 1;
            if ( v10 )
            {
              v11 = v9->Assoc.item.m_preparedMediaInfo.pInMemoryData;
              if ( v11 )
              {
                AK::MemoryMgr::Free(in_PoolId, v11);
                v9->Assoc.item.m_preparedMediaInfo.pInMemoryData = 0i64;
                v9->Assoc.item.m_preparedMediaInfo.uInMemoryDataSize = 0;
              }
            }
            if ( !v9->Assoc.item.uRefCount )
            {
              v12 = v9->pNextItem;
              if ( !v9->pNextItem )
              {
                do
                  v7 = (unsigned int)(v7 + 1);
                while ( (unsigned int)v7 < 0xC1 && !v3->m_MediaHashTable.m_table[v7] );
              }
              if ( v6 )
                v6->pNextItem = v12;
              else
                v3->m_MediaHashTable.m_table[v8] = v12;
              v13 = v9->Assoc.item.m_BankSlots.m_pItems;
              if ( v13 )
              {
                v9->Assoc.item.m_BankSlots.m_uLength = 0;
                AK::MemoryMgr::Free(g_DefaultPoolId, v13);
                v9->Assoc.item.m_BankSlots.m_pItems = 0i64;
                v9->Assoc.item.m_BankSlots.m_ulReserved = 0;
              }
              AK::MemoryMgr::Free(v3->m_MediaHashTable.m_MemPoolId, v9);
              --v3->m_MediaHashTable.m_uiSize;
            }
          }
        }
LABEL_22:
        ++v4;
      }
      while ( v4 < v2->m_uNumLoadedItems );
    }
    LeaveCriticalSection(&v3->m_MediaLock.m_csLock);
    *((_BYTE *)v2 + 112) &= 0xFBu;
  }
}

// File Line: 3243
// RVA: 0xA5D6B0
AkMediaInfo *__fastcall CAkBankMgr::GetMedia(CAkBankMgr *this, AkMediaInfo *result, unsigned int in_mediaId, CAkUsageSlot **out_pUsageSlot)
{
  CAkBankMgr *v4; // rdi
  CAkUsageSlot **v5; // rbp
  unsigned int v6; // esi
  AkMediaInfo *v7; // r14
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v8; // rax

  v4 = this;
  v5 = out_pUsageSlot;
  v6 = in_mediaId;
  v7 = result;
  result->pInMemoryData = 0i64;
  result->uInMemoryDataSize = 0;
  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  EnterCriticalSection(&v4->m_MediaLock.m_csLock);
  v8 = v4->m_MediaHashTable.m_table[v6 % 0xC1];
  if ( v8 )
  {
    while ( v8->Assoc.key != v6 )
    {
      v8 = v8->pNextItem;
      if ( !v8 )
        goto LABEL_7;
    }
    if ( v8 != (AkHashList<unsigned long,AkMediaEntry,193>::Item *)-16i64 )
      AkMediaEntry::GetMedia(&v8->Assoc.item, v7, v5);
  }
LABEL_7:
  LeaveCriticalSection(&v4->m_MediaLock.m_csLock);
  LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  return v7;
}

// File Line: 3261
// RVA: 0xA60A80
void __fastcall CAkBankMgr::ReleaseMedia(CAkBankMgr *this, unsigned int in_mediaId)
{
  CAkBankMgr *v2; // rdi
  unsigned int v3; // ebp
  _RTL_CRITICAL_SECTION *v4; // rbx
  int *v5; // r15
  _QWORD *v6; // r14
  __int64 v7; // rsi
  signed __int64 v8; // r12
  _DWORD *v9; // rdi
  bool v10; // zf
  void *v11; // rdx
  __int64 v12; // rcx
  void *v13; // rdx

  v2 = this;
  v3 = in_mediaId;
  EnterCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
  v4 = &v2->m_MediaLock.m_csLock;
  EnterCriticalSection(&v2->m_MediaLock.m_csLock);
  v5 = &v2->m_MediaHashTable.m_MemPoolId;
  v6 = 0i64;
  v7 = v3 % 0xC1;
  v8 = (signed __int64)&v2->m_MediaHashTable + 8 * v7;
  v9 = *(_DWORD **)(v8 + 8);
  if ( v9 )
  {
    while ( v9[2] != v3 )
    {
      v6 = v9;
      v9 = *(_DWORD **)v9;
      if ( !v9 )
        goto LABEL_18;
    }
    v10 = v9[12]-- == 1;
    if ( v10 )
    {
      v11 = (void *)*((_QWORD *)v9 + 2);
      if ( v11 )
      {
        AK::MemoryMgr::Free(in_PoolId, v11);
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
        while ( (unsigned int)v7 < 0xC1 && !*(_QWORD *)&v5[2 * v7 + 2] );
      }
      if ( v6 )
        *v6 = v12;
      else
        *(_QWORD *)(v8 + 8) = v12;
      v13 = (void *)*((_QWORD *)v9 + 4);
      if ( v13 )
      {
        v9[10] = 0;
        AK::MemoryMgr::Free(g_DefaultPoolId, v13);
        *((_QWORD *)v9 + 4) = 0i64;
        v9[11] = 0;
      }
      AK::MemoryMgr::Free(*v5, v9);
      --v5[388];
    }
  }
LABEL_18:
  LeaveCriticalSection(v4);
  LeaveCriticalSection(&CAkBankList::m_BankListLock.m_csLock);
}

// File Line: 3277
// RVA: 0xA5F560
signed __int64 __fastcall CAkBankMgr::PrepareSingleMedia(CAkBankMgr *this, AkSrcTypeInfo *in_rmediaInfo)
{
  AkSrcTypeInfo *v2; // rbx
  __int128 v3; // xmm0
  AkSrcTypeInfo *v4; // rax
  __int128 v6; // [rsp+20h] [rbp-28h]
  int v7; // [rsp+30h] [rbp-18h]

  v2 = in_rmediaInfo;
  if ( !this->m_bAccumulating )
    return CAkBankMgr::LoadSingleMedia(this, in_rmediaInfo);
  v3 = *(_OWORD *)&in_rmediaInfo->mediaInfo.sourceID;
  v7 = *((_DWORD *)&in_rmediaInfo->mediaInfo + 4);
  v6 = v3;
  v4 = AkSortedKeyArray<AkMediaInformation,AkSrcTypeInfo,ArrayPoolDefault,CAkBankMgr::AkSortedPreparationListGetKey,8>::AddNoSetKey<AkMediaInformation>(
         &this->m_PreparationAccumulator,
         (AkMediaInformation *)&v6);
  if ( !v4 )
    return 52i64;
  *(_QWORD *)&v4->mediaInfo.sourceID = *(_QWORD *)&v2->mediaInfo.sourceID;
  *(_QWORD *)&v4->mediaInfo.uFileOffset = *(_QWORD *)&v2->mediaInfo.uFileOffset;
  *((_QWORD *)&v4->mediaInfo + 2) = *((_QWORD *)&v2->mediaInfo + 2);
  v4->pInMemoryMedia = v2->pInMemoryMedia;
  *(_QWORD *)&v4->dwID = *(_QWORD *)&v2->dwID;
  return 1i64;
}

// File Line: 3296
// RVA: 0xA620D0
void __fastcall CAkBankMgr::UnprepareSingleMedia(CAkBankMgr *this, unsigned int in_SourceID)
{
  JUMPOUT(this->m_bAccumulating, 0, CAkBankMgr::ReleaseSingleMedia);
}

// File Line: 3316
// RVA: 0xA5F5E0
signed __int64 __fastcall CAkBankMgr::ProcessAccumulated(CAkBankMgr *this)
{
  AkSrcTypeInfo *v1; // rdi
  CAkBankMgr *v2; // rsi
  signed __int64 result; // rax
  unsigned int v4; // ebp
  unsigned int *v5; // rbx

  v1 = this->m_PreparationAccumulator.m_pItems;
  v2 = this;
  if ( v1 == &v1[this->m_PreparationAccumulator.m_uLength] )
    return 1i64;
  while ( 1 )
  {
    result = CAkBankMgr::LoadSingleMedia(v2, v1);
    v4 = result;
    if ( (_DWORD)result != 1 )
      break;
    ++v1;
    if ( v1 == &v2->m_PreparationAccumulator.m_pItems[v2->m_PreparationAccumulator.m_uLength] )
      return (unsigned int)result;
  }
  v5 = &v2->m_PreparationAccumulator.m_pItems->mediaInfo.sourceID;
  if ( v5 != (unsigned int *)v1 )
  {
    do
    {
      CAkBankMgr::ReleaseSingleMedia(v2, *v5);
      v5 += 10;
    }
    while ( v5 != (unsigned int *)v1 );
    result = v4;
  }
  return result;
}

// File Line: 3341
// RVA: 0xA5E430
signed __int64 __fastcall CAkBankMgr::LoadSingleMedia(CAkBankMgr *this, AkSrcTypeInfo *in_rMediaInfo)
{
  unsigned __int64 v2; // r15
  AkSrcTypeInfo *v3; // rsi
  CAkBankMgr *v4; // r13
  unsigned int v6; // ebp
  __int64 v7; // rax
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v8; // rdi
  AkMediaEntry *v9; // rdi
  unsigned int v10; // esi
  AkHashList<unsigned long,AkMediaEntry,193>::Item *v11; // rdi
  unsigned int v12; // er15
  char *v13; // rax
  char *v14; // r14
  char *v15; // r14
  bool v16; // zf

  v2 = in_rMediaInfo->mediaInfo.uInMemoryMediaSize;
  v3 = in_rMediaInfo;
  v4 = this;
  if ( !(_DWORD)v2 )
    return 1i64;
  EnterCriticalSection(&this->m_MediaLock.m_csLock);
  v6 = v3->mediaInfo.sourceID;
  v7 = v3->mediaInfo.sourceID % 0xC1;
  v8 = v4->m_MediaHashTable.m_table[v7];
  if ( v8 )
  {
    while ( v8->Assoc.key != v6 )
    {
      v8 = v8->pNextItem;
      if ( !v8 )
        goto LABEL_6;
    }
    v9 = &v8->Assoc.item;
  }
  else
  {
LABEL_6:
    v9 = 0i64;
  }
  if ( !v9 )
  {
    v11 = v4->m_MediaHashTable.m_table[v7];
    if ( !v11 )
      goto LABEL_16;
    while ( v11->Assoc.key != v6 )
    {
      v11 = v11->pNextItem;
      if ( !v11 )
        goto LABEL_16;
    }
    v9 = &v11->Assoc.item;
    if ( !v9 )
LABEL_16:
      v9 = AkHashList<unsigned long,AkMediaEntry,193>::CreateEntry(
             &v4->m_MediaHashTable,
             v6,
             v3->mediaInfo.sourceID % 0xC1);
    if ( !v9 )
    {
      v10 = 2;
      goto LABEL_35;
    }
    v9->m_sourceID = v6;
LABEL_20:
    if ( v9->m_BankSlots.m_uLength )
    {
      v12 = v9->m_BankSlots.m_pItems->item.uInMemoryDataSize;
      if ( in_PoolId != -1 )
      {
        v13 = (char *)AK::MemoryMgr::Malign(in_PoolId, v12, 0x10u);
        v14 = v13;
        if ( v13 )
        {
          memmove(v13, v9->m_BankSlots.m_pItems->item.pInMemoryData, v12);
          v10 = 1;
          v9->m_preparedMediaInfo.uInMemoryDataSize = v12;
          v9->m_preparedMediaInfo.pInMemoryData = v14;
          goto LABEL_35;
        }
      }
    }
    else if ( in_PoolId != -1 )
    {
      v15 = (char *)AK::MemoryMgr::Malign(in_PoolId, v2, 0x10u);
      if ( v15 )
      {
        LeaveCriticalSection(&v4->m_MediaLock.m_csLock);
        v10 = CAkBankMgr::LoadSoundFromFile(v4, v3, v15);
        EnterCriticalSection(&v4->m_MediaLock.m_csLock);
        if ( v10 == 1 )
        {
          v9->m_preparedMediaInfo.uInMemoryDataSize = v2;
          v9->m_preparedMediaInfo.pInMemoryData = v15;
          goto LABEL_35;
        }
        AK::MemoryMgr::Free(in_PoolId, v15);
LABEL_30:
        v16 = v9->uRefCount-- == 1;
        if ( v16 && v9->m_preparedMediaInfo.pInMemoryData )
        {
          AK::MemoryMgr::Free(in_PoolId, v9->m_preparedMediaInfo.pInMemoryData);
          v9->m_preparedMediaInfo.pInMemoryData = 0i64;
          v9->m_preparedMediaInfo.uInMemoryDataSize = 0;
        }
        if ( !v9->uRefCount )
          AkHashList<unsigned long,AkMediaEntry,193>::Unset(&v4->m_MediaHashTable, v6);
        goto LABEL_35;
      }
    }
    v10 = 52;
    goto LABEL_30;
  }
  ++v9->uRefCount;
  if ( !v9->m_preparedMediaInfo.pInMemoryData )
    goto LABEL_20;
  v10 = 1;
LABEL_35:
  LeaveCriticalSection(&v4->m_MediaLock.m_csLock);
  return v10;
}

// File Line: 3435
// RVA: 0xA60CB0
void __fastcall CAkBankMgr::ReleaseSingleMedia(CAkBankMgr *this, unsigned int in_SourceID)
{
  _RTL_CRITICAL_SECTION *v2; // rbx
  CAkBankMgr *v3; // r15
  unsigned int v4; // ebp
  int *v5; // r15
  _QWORD *v6; // r14
  __int64 v7; // rsi
  signed __int64 v8; // r12
  _DWORD *v9; // rdi
  bool v10; // zf
  void *v11; // rdx
  __int64 v12; // rcx
  void *v13; // rdx

  v2 = &this->m_MediaLock.m_csLock;
  v3 = this;
  v4 = in_SourceID;
  EnterCriticalSection(&this->m_MediaLock.m_csLock);
  v5 = &v3->m_MediaHashTable.m_MemPoolId;
  v6 = 0i64;
  v7 = v4 % 0xC1;
  v8 = (signed __int64)&v5[2 * v7];
  v9 = *(_DWORD **)(v8 + 8);
  if ( v9 )
  {
    while ( v9[2] != v4 )
    {
      v6 = v9;
      v9 = *(_DWORD **)v9;
      if ( !v9 )
        goto LABEL_18;
    }
    v10 = v9[12]-- == 1;
    if ( v10 )
    {
      v11 = (void *)*((_QWORD *)v9 + 2);
      if ( v11 )
      {
        AK::MemoryMgr::Free(in_PoolId, v11);
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
        while ( (unsigned int)v7 < 0xC1 && !*(_QWORD *)&v5[2 * v7 + 2] );
      }
      if ( v6 )
        *v6 = v12;
      else
        *(_QWORD *)(v8 + 8) = v12;
      v13 = (void *)*((_QWORD *)v9 + 4);
      if ( v13 )
      {
        v9[10] = 0;
        AK::MemoryMgr::Free(g_DefaultPoolId, v13);
        *((_QWORD *)v9 + 4) = 0i64;
        v9[11] = 0;
      }
      AK::MemoryMgr::Free(*v5, v9);
      --v5[388];
    }
  }
LABEL_18:
  LeaveCriticalSection(v2);
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
signed __int64 __fastcall CAkBankMgr::LoadSource(char **io_pData, unsigned int *io_ulDataSize, AkBankSourceData *out_rSource)
{
  unsigned int **v3; // r10
  unsigned int v4; // er9
  int v5; // er11
  char *v6; // rax
  unsigned int v7; // ecx
  unsigned int v8; // ecx
  unsigned int v9; // ecx
  unsigned int v10; // ecx
  char v11; // cl
  signed __int64 result; // rax
  int v13; // ecx
  __int64 v14; // rcx

  v3 = (unsigned int **)io_pData;
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
  *v3 = (unsigned int *)(v6 + 4);
  out_rSource->m_MediaInfo.sourceID = v7;
  v8 = **v3;
  ++*v3;
  out_rSource->m_MediaInfo.uFileID = v8;
  if ( v5 == 1 )
  {
    *(_QWORD *)&out_rSource->m_MediaInfo.uFileOffset = 0i64;
  }
  else
  {
    v9 = **v3;
    ++*v3;
    out_rSource->m_MediaInfo.uFileOffset = v9;
    v10 = **v3;
    ++*v3;
    out_rSource->m_MediaInfo.uInMemoryMediaSize = v10;
  }
  v11 = *(_BYTE *)*v3;
  *v3 = (unsigned int *)((char *)*v3 + 1);
  *((_DWORD *)&out_rSource->m_MediaInfo + 4) &= 0xFFFFFDFC;
  result = out_rSource->m_PluginID & 0xF;
  *((_DWORD *)&out_rSource->m_MediaInfo + 4) |= v11 & 1 | 2 * (((v11 & 2) << 7) | (v5 == 2));
  v13 = *((_DWORD *)&out_rSource->m_MediaInfo + 4);
  if ( (_DWORD)result == 1 )
  {
    if ( !v5 )
    {
      *((_DWORD *)&out_rSource->m_MediaInfo + 4) = v13 & 0xFFFFFF8F | 0xC;
      return result;
    }
    if ( (unsigned int)(v5 - 1) <= 1 )
    {
      result = 1i64;
      *((_DWORD *)&out_rSource->m_MediaInfo + 4) = v13 & 0xFFFFFF87 | 4;
      return result;
    }
    return 2i64;
  }
  if ( (_DWORD)result == 5 || (_DWORD)result == 2 )
  {
    v14 = **v3;
    ++*v3;
    out_rSource->m_uSize = v14;
    out_rSource->m_pParam = *v3;
    *v3 = (unsigned int *)((char *)*v3 + v14);
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
signed __int64 __fastcall CAkBankMgr::KillSlot(CAkBankMgr *this, CAkUsageSlot *in_pUsageSlot, void (__fastcall *in_pCallBack)(unsigned int, const void *, AKRESULT, int, void *), void *in_pCookie)
{
  void *v4; // rdi
  void (__fastcall *v5)(unsigned int, const void *, AKRESULT, int, void *); // rbx
  CAkUsageSlot *v6; // rsi
  unsigned __int16 v7; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  v4 = in_pCookie;
  v5 = in_pCallBack;
  v6 = in_pUsageSlot;
  CAkUsageSlot::RemoveContent(in_pUsageSlot);
  *((_BYTE *)v6 + 112) |= 8u;
  v6->m_pfnBankCallback = v5;
  v6->m_pCookie = v4;
  in_rItem.type = 24;
  in_rItem.event.GameObjID = (unsigned __int64)v6;
  v7 = Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_CreateTexture,Scaleform::Render::DICommand>::GetSize();
  CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v7);
  return AK::SoundEngine::RenderAudio();
}

// File Line: 3568
// RVA: 0xA5C930
signed __int64 __fastcall AkMediaEntry::AddAlternateBank(AkMediaEntry *this, char *in_pData, unsigned int in_uSize, CAkUsageSlot *in_pSlot)
{
  MapStruct<CAkUsageSlot *,AkMediaInfo> *v4; // rax
  CAkUsageSlot *v5; // rdi
  AkArray<MapStruct<CAkUsageSlot *,AkMediaInfo>,MapStruct<CAkUsageSlot *,AkMediaInfo> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v6; // r9
  char *v7; // rsi
  signed __int64 v8; // rcx
  AkMediaInfo *v9; // rbx
  MapStruct<CAkUsageSlot *,AkMediaInfo> *v10; // rax
  signed __int64 result; // rax
  __int64 v12; // [rsp+28h] [rbp-10h]

  v4 = this->m_BankSlots.m_pItems;
  v5 = in_pSlot;
  v6 = (AkArray<MapStruct<CAkUsageSlot *,AkMediaInfo>,MapStruct<CAkUsageSlot *,AkMediaInfo> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)&this->m_BankSlots.m_pItems;
  LODWORD(v12) = in_uSize;
  v7 = in_pData;
  v8 = (signed __int64)&v4[this->m_BankSlots.m_uLength];
  if ( v4 == (MapStruct<CAkUsageSlot *,AkMediaInfo> *)v8 )
    goto LABEL_15;
  do
  {
    if ( v4->key == v5 )
      break;
    ++v4;
  }
  while ( v4 != (MapStruct<CAkUsageSlot *,AkMediaInfo> *)v8 );
  if ( v4 == (MapStruct<CAkUsageSlot *,AkMediaInfo> *)v8 )
  {
LABEL_15:
    v9 = 0i64;
  }
  else
  {
    v9 = &v4->item;
    if ( v4 != (MapStruct<CAkUsageSlot *,AkMediaInfo> *)-8i64 )
    {
      v9->pInMemoryData = in_pData;
      goto LABEL_10;
    }
  }
  v10 = AkArray<MapStruct<CAkUsageSlot *,AkMediaInfo>,MapStruct<CAkUsageSlot *,AkMediaInfo> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::Insert(
          v6,
          0);
  if ( !v10 )
    goto LABEL_11;
  v9 = &v10->item;
  v10->key = v5;
  v10->item.pInMemoryData = v7;
LABEL_10:
  *(_QWORD *)&v9->uInMemoryDataSize = v12;
LABEL_11:
  result = 52i64;
  if ( v9 )
    result = 1i64;
  return result;
}

// File Line: 3595
// RVA: 0xA5D5D0
void __fastcall AkMediaEntry::GetMedia(AkMediaEntry *this, AkMediaInfo *out_mediaInfo, CAkUsageSlot **out_pUsageSlot)
{
  CAkUsageSlot **v3; // r11
  AkMediaEntry *v4; // rbx
  unsigned int v5; // er8
  unsigned int v6; // eax
  MapStruct<CAkUsageSlot *,AkMediaInfo> *v7; // r10
  bool v8; // zf
  unsigned __int64 v9; // rax
  MapStruct<CAkUsageSlot *,AkMediaInfo> *v10; // rcx

  ++this->uRefCount;
  v3 = out_pUsageSlot;
  v4 = this;
  if ( this->m_preparedMediaInfo.pInMemoryData )
  {
    out_mediaInfo->pInMemoryData = this->m_preparedMediaInfo.pInMemoryData;
    *(_QWORD *)&out_mediaInfo->uInMemoryDataSize = *(_QWORD *)&this->m_preparedMediaInfo.uInMemoryDataSize;
  }
  else
  {
    v5 = this->m_BankSlots.m_uLength;
    v6 = 0;
    if ( v5 )
    {
      v7 = this->m_BankSlots.m_pItems;
      while ( *((_BYTE *)v7[v6].key + 112) & 8 )
      {
        if ( ++v6 >= v5 )
          goto LABEL_7;
      }
      v9 = v6;
      *v3 = v7[v9].key;
      v10 = &this->m_BankSlots.m_pItems[v9];
      out_mediaInfo->pInMemoryData = v10->item.pInMemoryData;
      *(_QWORD *)&out_mediaInfo->uInMemoryDataSize = *(_QWORD *)&v10->item.uInMemoryDataSize;
      _InterlockedIncrement(&(*v3)->m_iRefCount);
    }
    else
    {
LABEL_7:
      out_mediaInfo->pInMemoryData = 0i64;
      out_mediaInfo->uInMemoryDataSize = 0;
      v8 = this->uRefCount-- == 1;
      if ( v8 )
      {
        if ( this->m_preparedMediaInfo.pInMemoryData )
        {
          AK::MemoryMgr::Free(in_PoolId, this->m_preparedMediaInfo.pInMemoryData);
          v4->m_preparedMediaInfo.pInMemoryData = 0i64;
          v4->m_preparedMediaInfo.uInMemoryDataSize = 0;
        }
      }
    }
  }
}

