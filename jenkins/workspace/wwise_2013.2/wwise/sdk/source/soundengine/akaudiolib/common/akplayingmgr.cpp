// File Line: 38
// RVA: 0xA5A040
signed __int64 __fastcall CAkPlayingMgr::Init(CAkPlayingMgr *this)
{
  CAkPlayingMgr *v1; // rbx
  HANDLE v2; // rax
  void *v3; // rcx
  signed __int64 result; // rax
  CAkPlayingMgr *v5; // rcx
  signed __int64 v6; // rdx

  v1 = this;
  v2 = CreateEventW(0i64, 1, 0, 0i64);
  v3 = v2;
  v1->m_CallbackEvent.m_Event = v2;
  result = 2 - (unsigned int)(v2 != 0i64);
  if ( (_DWORD)result == 1 )
  {
    SetEvent(v3);
    v5 = v1;
    v6 = 3i64;
    v1->m_PlayingMap.m_uiSize = 0;
    do
    {
      v5->m_PlayingMap.m_table[0] = 0i64;
      v5->m_PlayingMap.m_table[1] = 0i64;
      v5->m_PlayingMap.m_table[2] = 0i64;
      v5 = (CAkPlayingMgr *)((char *)v5 + 64);
      v5[-1].m_BusCallbackMgr.m_csLock.m_csLock.DebugInfo = 0i64;
      *(_QWORD *)&v5[-1].m_BusCallbackMgr.m_csLock.m_csLock.LockCount = 0i64;
      v5[-1].m_BusCallbackMgr.m_csLock.m_csLock.OwningThread = 0i64;
      v5[-1].m_BusCallbackMgr.m_csLock.m_csLock.LockSemaphore = 0i64;
      v5[-1].m_BusCallbackMgr.m_csLock.m_csLock.SpinCount = 0i64;
      --v6;
    }
    while ( v6 );
    v5->m_PlayingMap.m_table[0] = 0i64;
    v5->m_PlayingMap.m_table[1] = 0i64;
    v5->m_PlayingMap.m_table[2] = 0i64;
    v5->m_PlayingMap.m_table[3] = 0i64;
    v5->m_PlayingMap.m_table[4] = 0i64;
    v5->m_PlayingMap.m_table[5] = 0i64;
    v5->m_PlayingMap.m_table[6] = 0i64;
    result = 1i64;
    g_pBusCallbackMgr = &v1->m_BusCallbackMgr;
  }
  return result;
}

// File Line: 68
// RVA: 0xA59DA0
__int64 __fastcall CAkPlayingMgr::AddPlayingID(CAkPlayingMgr *this, AkQueuedMsg_EventBase *in_event, void (__fastcall *in_pfnCallback)(AkCallbackType, AkCallbackInfo *), void *in_pCookie, unsigned int in_uiRegisteredNotif, unsigned int in_id)
{
  CAkPlayingMgr *v6; // r15
  void *v7; // r12
  void (__fastcall *v8)(AkCallbackType, AkCallbackInfo *); // r14
  AkQueuedMsg_EventBase *v9; // rsi
  CAkPlayingMgr::PlayingMgrItem *v10; // rax
  CAkPlayingMgr::PlayingMgrItem *v11; // rdi
  unsigned int v12; // ebp
  AkExternalSourceArray *v13; // rcx
  AkExternalSourceArray *v14; // rsi
  unsigned int v15; // eax
  unsigned int v16; // ecx
  __int64 v17; // rcx

  v6 = this;
  v7 = in_pCookie;
  v8 = in_pfnCallback;
  v9 = in_event;
  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v10 = (CAkPlayingMgr::PlayingMgrItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x58ui64);
  v11 = v10;
  if ( v10 )
  {
    v12 = 1;
    v10->userParam.m_PlayingID = 0;
    v10->userParam.m_CustomParam.customParam = 0i64;
    v10->userParam.m_CustomParam.ui32Reserved = 0;
    v10->userParam.m_CustomParam.pExternalSrcs = 0i64;
    v10->cPBI = 0;
    v10->eventID = in_id;
    v10->cAction = 1;
    v10->GameObj = v9->GameObjID;
    v13 = v10->userParam.m_CustomParam.pExternalSrcs;
    v10->userParam.m_PlayingID = v9->PlayingID;
    v10->userParam.m_CustomParam.customParam = v9->CustomParam.customParam;
    v10->userParam.m_CustomParam.ui32Reserved = v9->CustomParam.ui32Reserved;
    v14 = v9->CustomParam.pExternalSrcs;
    if ( v13 )
      AkExternalSourceArray::Release(v13);
    if ( v14 )
      ++v14->m_cRefCount;
    v15 = in_uiRegisteredNotif;
    v11->userParam.m_CustomParam.pExternalSrcs = v14;
    v11->pfnCallback = v8;
    v11->pCookie = v7;
    if ( !v8 )
      v15 = in_uiRegisteredNotif & 0xFFFF2004;
    v16 = v11->userParam.m_PlayingID;
    v11->uiRegisteredNotif = v15;
    v17 = v16 % 0x1F;
    v11->pNextItem = v6->m_PlayingMap.m_table[v17];
    v6->m_PlayingMap.m_table[v17] = v11;
    ++v6->m_PlayingMap.m_uiSize;
  }
  else
  {
    v12 = 2;
  }
  LeaveCriticalSection(&v6->m_csMapLock.m_csLock);
  return v12;
}

// File Line: 130
// RVA: 0xA59ED0
void __fastcall CAkPlayingMgr::CheckRemovePlayingID(CAkPlayingMgr *this, unsigned int in_PlayingID, CAkPlayingMgr::PlayingMgrItem *in_pItem)
{
  CAkPlayingMgr::PlayingMgrItem *v3; // rdi
  unsigned int v4; // esi
  CAkPlayingMgr *v5; // rbx
  void (__fastcall *v6)(AkCallbackType, AkCallbackInfo *); // r14
  unsigned int v7; // ebp
  int v8; // eax
  CAkPlayingMgr::PlayingMgrItem *v9; // rdx
  __int64 v10; // rax
  CAkPlayingMgr::PlayingMgrItem **v11; // r8
  CAkPlayingMgr::PlayingMgrItem *v12; // rax
  CAkPlayingMgr::PlayingMgrItem *v13; // rcx
  AkExternalSourceArray *v14; // rcx
  int v15; // esi
  void *v16; // [rsp+20h] [rbp-28h]
  unsigned __int64 v17; // [rsp+28h] [rbp-20h]
  unsigned int v18; // [rsp+30h] [rbp-18h]
  int v19; // [rsp+34h] [rbp-14h]

  v3 = in_pItem;
  v4 = in_PlayingID;
  v5 = this;
  if ( *(_QWORD *)&in_pItem->cPBI )
  {
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
  }
  else
  {
    if ( in_pItem->uiRegisteredNotif & 0x10000 )
      CAkPositionRepository::RemovePlayingID((CAkSegmentInfoRepository *)g_pPositionRepository, in_PlayingID);
    v6 = v3->pfnCallback;
    v7 = v3->uiRegisteredNotif;
    v16 = v3->pCookie;
    v17 = v3->GameObj;
    v8 = v3->eventID;
    v18 = v4;
    v19 = v8;
    v9 = 0i64;
    v10 = v4 % 0x1F;
    v11 = &v5->m_PlayingMap.m_table[v10];
    v12 = v5->m_PlayingMap.m_table[v10];
    if ( v12 )
    {
      while ( v12->userParam.m_PlayingID != v4 )
      {
        v9 = v12;
        v12 = v12->pNextItem;
        if ( !v12 )
          goto LABEL_12;
      }
      v13 = v12->pNextItem;
      if ( v9 )
        v9->pNextItem = v13;
      else
        *v11 = v13;
      --v5->m_PlayingMap.m_uiSize;
    }
LABEL_12:
    v14 = v3->userParam.m_CustomParam.pExternalSrcs;
    v15 = g_DefaultPoolId;
    if ( v14 )
      AkExternalSourceArray::Release(v14);
    AK::MemoryMgr::Free(v15, v3);
    if ( v7 & 1 )
    {
      ResetEvent(v5->m_CallbackEvent.m_Event);
      LeaveCriticalSection(&v5->m_csMapLock.m_csLock);
      v6(AK_EndOfEvent, (AkCallbackInfo *)&v16);
      SetEvent(v5->m_CallbackEvent.m_Event);
    }
    else
    {
      LeaveCriticalSection(&v5->m_csMapLock.m_csLock);
    }
  }
}

// File Line: 181
// RVA: 0xA5A340
void __fastcall CAkPlayingMgr::NotifyEndOfDynamicSequenceItem(CAkPlayingMgr *this, unsigned int in_PlayingID, unsigned int in_audioNodeID, void *in_pCustomInfo)
{
  CAkPlayingMgr *v4; // rsi
  void *v5; // rbp
  unsigned int v6; // er14
  unsigned int v7; // ebx
  CAkPlayingMgr::PlayingMgrItem *v8; // rax
  __int64 v9; // rdx
  void *v10; // rcx
  void (__fastcall *v11)(AkCallbackType, AkCallbackInfo *); // rbx
  __int64 v12; // [rsp+20h] [rbp-28h]
  unsigned __int64 v13; // [rsp+28h] [rbp-20h]
  unsigned int v14; // [rsp+30h] [rbp-18h]
  unsigned int v15; // [rsp+34h] [rbp-14h]
  void *v16; // [rsp+38h] [rbp-10h]

  v4 = this;
  v5 = in_pCustomInfo;
  v6 = in_audioNodeID;
  v7 = in_PlayingID;
  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v8 = v4->m_PlayingMap.m_table[v7 % 0x1F];
  if ( !v8 )
    goto LABEL_4;
  while ( v8->userParam.m_PlayingID != v7 )
  {
    v8 = v8->pNextItem;
    if ( !v8 )
      goto LABEL_4;
  }
  if ( v8 && v8->uiRegisteredNotif & 2 )
  {
    v9 = (__int64)v8->pCookie;
    v10 = v4->m_CallbackEvent.m_Event;
    v14 = v7;
    v11 = v8->pfnCallback;
    v12 = v9;
    v13 = v8->GameObj;
    v15 = v6;
    v16 = v5;
    ResetEvent(v10);
    LeaveCriticalSection(&v4->m_csMapLock.m_csLock);
    v11(AK_EndOfDynamicSequenceItem, (AkCallbackInfo *)&v12);
    SetEvent(v4->m_CallbackEvent.m_Event);
  }
  else
  {
LABEL_4:
    LeaveCriticalSection(&v4->m_csMapLock.m_csLock);
  }
}

// File Line: 212
// RVA: 0xA5A220
void __fastcall CAkPlayingMgr::NotifyDuration(CAkPlayingMgr *this, unsigned int in_PlayingID, float in_fDuration, float in_fEstimatedDuration, unsigned int in_idAudioNode)
{
  CAkPlayingMgr *v5; // r14
  unsigned int v6; // edi
  CAkPlayingMgr::PlayingMgrItem *v7; // rbx
  __int64 v8; // rax
  void *v9; // rcx
  __int64 v10; // rax
  void (__fastcall *v11)(AkCallbackType, AkCallbackInfo *); // rbx
  __int64 v12; // [rsp+20h] [rbp-58h]
  __int64 v13; // [rsp+28h] [rbp-50h]
  unsigned int v14; // [rsp+30h] [rbp-48h]
  int v15; // [rsp+34h] [rbp-44h]
  float v16; // [rsp+38h] [rbp-40h]
  float v17; // [rsp+3Ch] [rbp-3Ch]
  unsigned int v18; // [rsp+40h] [rbp-38h]

  v5 = this;
  v6 = in_PlayingID;
  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v7 = v5->m_PlayingMap.m_table[v6 % 0x1F];
  if ( !v7 )
    goto LABEL_4;
  while ( v7->userParam.m_PlayingID != v6 )
  {
    v7 = v7->pNextItem;
    if ( !v7 )
      goto LABEL_4;
  }
  if ( v7 && v7->uiRegisteredNotif & 8 )
  {
    v8 = (__int64)v7->pCookie;
    v9 = v5->m_CallbackEvent.m_Event;
    v16 = in_fDuration;
    v12 = v8;
    v10 = v7->GameObj;
    v17 = in_fEstimatedDuration;
    v13 = v10;
    LODWORD(v10) = v7->eventID;
    v11 = v7->pfnCallback;
    v15 = v10;
    v14 = v6;
    v18 = in_idAudioNode;
    ResetEvent(v9);
    LeaveCriticalSection(&v5->m_csMapLock.m_csLock);
    v11(AK_Duration, (AkCallbackInfo *)&v12);
    SetEvent(v5->m_CallbackEvent.m_Event);
  }
  else
  {
LABEL_4:
    LeaveCriticalSection(&v5->m_csMapLock.m_csLock);
  }
}

// File Line: 241
// RVA: 0xA5A850
void __fastcall CAkPlayingMgr::NotifyMusicPlayStarted(CAkPlayingMgr *this, unsigned int in_PlayingID)
{
  CAkPlayingMgr *v2; // r14
  unsigned int v3; // ebx
  CAkPlayingMgr::PlayingMgrItem *v4; // rax
  void (__fastcall *v5)(AkCallbackType, AkCallbackInfo *); // rdi
  __int64 v6; // rdx
  void *v7; // rcx
  __int64 v8; // [rsp+20h] [rbp-28h]
  unsigned __int64 v9; // [rsp+28h] [rbp-20h]
  unsigned int v10; // [rsp+30h] [rbp-18h]
  unsigned int v11; // [rsp+34h] [rbp-14h]

  v2 = this;
  v3 = in_PlayingID;
  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v4 = v2->m_PlayingMap.m_table[v3 % 0x1F];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->userParam.m_PlayingID != v3 )
  {
    v4 = v4->pNextItem;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 && SLOBYTE(v4->uiRegisteredNotif) < 0 && (v5 = v4->pfnCallback) != 0i64 )
  {
    v6 = (__int64)v4->pCookie;
    v7 = v2->m_CallbackEvent.m_Event;
    v10 = v3;
    v8 = v6;
    v9 = v4->GameObj;
    v11 = v4->eventID;
    ResetEvent(v7);
    LeaveCriticalSection(&v2->m_csMapLock.m_csLock);
    v5(AK_MusicPlayStarted, (AkCallbackInfo *)&v8);
    SetEvent(v2->m_CallbackEvent.m_Event);
  }
  else
  {
LABEL_4:
    LeaveCriticalSection(&v2->m_csMapLock.m_csLock);
  }
}

// File Line: 269
// RVA: 0xA5A0F0
void __fastcall CAkPlayingMgr::MusicPlaylistCallback(CAkPlayingMgr *this, unsigned int in_PlayingID, unsigned int in_playlistID, unsigned int in_uNumPlaylistItems, unsigned int *io_uSelection, unsigned int *io_uItemDone)
{
  CAkPlayingMgr *v6; // r14
  unsigned int v7; // edi
  unsigned int v8; // ebx
  CAkPlayingMgr::PlayingMgrItem *v9; // rax
  void (__fastcall *v10)(AkCallbackType, AkCallbackInfo *); // rsi
  __int64 v11; // rcx
  int v12; // edx
  __int64 v13; // rcx
  unsigned int v14; // eax
  unsigned int v15; // eax
  void *v16; // rcx
  __int64 v17; // [rsp+20h] [rbp-38h]
  __int64 v18; // [rsp+28h] [rbp-30h]
  unsigned int v19; // [rsp+30h] [rbp-28h]
  int v20; // [rsp+34h] [rbp-24h]
  unsigned int v21; // [rsp+3Ch] [rbp-1Ch]
  unsigned int v22; // [rsp+40h] [rbp-18h]
  unsigned int v23; // [rsp+44h] [rbp-14h]

  v6 = this;
  v7 = in_uNumPlaylistItems;
  v8 = in_PlayingID;
  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v9 = v6->m_PlayingMap.m_table[v8 % 0x1F];
  if ( !v9 )
    goto LABEL_4;
  while ( v9->userParam.m_PlayingID != v8 )
  {
    v9 = v9->pNextItem;
    if ( !v9 )
      goto LABEL_4;
  }
  if ( v9 && v9->uiRegisteredNotif & 0x40 && (v10 = v9->pfnCallback) != 0i64 )
  {
    v11 = (__int64)v9->pCookie;
    v12 = v9->eventID;
    v21 = v7;
    v17 = v11;
    v13 = v9->GameObj;
    v14 = *io_uSelection;
    v19 = v8;
    v22 = v14;
    v15 = *io_uItemDone;
    v18 = v13;
    v16 = v6->m_CallbackEvent.m_Event;
    v20 = v12;
    v23 = v15;
    ResetEvent(v16);
    LeaveCriticalSection(&v6->m_csMapLock.m_csLock);
    v10(AK_MusicPlaylistSelect, (AkCallbackInfo *)&v17);
    SetEvent(v6->m_CallbackEvent.m_Event);
    *io_uSelection = v22;
    *io_uItemDone = v23;
  }
  else
  {
LABEL_4:
    LeaveCriticalSection(&v6->m_csMapLock.m_csLock);
  }
}

// File Line: 304
// RVA: 0xA5A440
void __fastcall CAkPlayingMgr::NotifyMarker(CAkPlayingMgr *this, CAkPBI *in_pPBI, AkAudioMarker *in_pMarker)
{
  CAkPlayingMgr *v3; // rsi
  AkAudioMarker *v4; // r14
  CAkPBI *v5; // rbx
  int v6; // er10
  CAkPlayingMgr::PlayingMgrItem *v7; // rax
  void (__fastcall *v8)(AkCallbackType, AkCallbackInfo *); // rbx
  __int64 v9; // rdx
  __int64 v10; // rcx
  int v11; // eax
  void *v12; // rcx
  __int64 v13; // [rsp+20h] [rbp-38h]
  __int64 v14; // [rsp+28h] [rbp-30h]
  int v15; // [rsp+30h] [rbp-28h]
  int v16; // [rsp+34h] [rbp-24h]
  unsigned int v17; // [rsp+38h] [rbp-20h]
  int v18; // [rsp+3Ch] [rbp-1Ch]
  char *v19; // [rsp+40h] [rbp-18h]

  v3 = this;
  v4 = in_pMarker;
  v5 = in_pPBI;
  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v6 = v5->m_UserParams.m_PlayingID;
  v7 = v3->m_PlayingMap.m_table[v5->m_UserParams.m_PlayingID % 0x1F];
  if ( v7 )
  {
    while ( v7->userParam.m_PlayingID != v6 )
    {
      v7 = v7->pNextItem;
      if ( !v7 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v7 = 0i64;
  }
  if ( v7->uiRegisteredNotif & 4 && (v8 = v7->pfnCallback) != 0i64 )
  {
    v9 = v7->GameObj;
    v10 = (__int64)v7->pCookie;
    v15 = v6;
    v14 = v9;
    LODWORD(v9) = v7->eventID;
    v17 = v4->dwIdentifier;
    v11 = v4->dwPosition;
    v13 = v10;
    v12 = v3->m_CallbackEvent.m_Event;
    v18 = v11;
    v19 = v4->strLabel;
    v16 = v9;
    ResetEvent(v12);
    LeaveCriticalSection(&v3->m_csMapLock.m_csLock);
    v8(AK_Marker, (AkCallbackInfo *)&v13);
    SetEvent(v3->m_CallbackEvent.m_Event);
  }
  else
  {
    LeaveCriticalSection(&v3->m_csMapLock.m_csLock);
  }
}

// File Line: 340
// RVA: 0xA5AAC0
void __fastcall CAkPlayingMgr::NotifySpeakerVolumeMatrix(CAkPlayingMgr *this, unsigned int in_PlayingID, AkSpeakerVolumeMatrixCallbackInfo *in_pInfo)
{
  CAkPlayingMgr *v3; // r14
  AkSpeakerVolumeMatrixCallbackInfo *v4; // rdi
  unsigned int v5; // ebx
  CAkPlayingMgr::PlayingMgrItem *v6; // rax
  unsigned __int64 v7; // rdx
  void (__fastcall *v8)(AkCallbackType, AkCallbackInfo *); // rbx

  v3 = this;
  v4 = in_pInfo;
  v5 = in_PlayingID;
  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v6 = v3->m_PlayingMap.m_table[v5 % 0x1F];
  if ( !v6 )
    goto LABEL_4;
  while ( v6->userParam.m_PlayingID != v5 )
  {
    v6 = v6->pNextItem;
    if ( !v6 )
      goto LABEL_4;
  }
  if ( v6 && v6->uiRegisteredNotif & 0x10 )
  {
    v4->pCookie = v6->pCookie;
    v7 = v6->GameObj;
    v4->playingID = v5;
    v4->gameObjID = v7;
    v4->eventID = v6->eventID;
    v8 = v6->pfnCallback;
    ResetEvent(v3->m_CallbackEvent.m_Event);
    LeaveCriticalSection(&v3->m_csMapLock.m_csLock);
    v8(AK_SpeakerVolumeMatrix, (AkCallbackInfo *)&v4->pCookie);
    SetEvent(v3->m_CallbackEvent.m_Event);
  }
  else
  {
LABEL_4:
    LeaveCriticalSection(&v3->m_csMapLock.m_csLock);
  }
}

// File Line: 362
// RVA: 0xA5A550
void __fastcall CAkPlayingMgr::NotifyMarkers(CAkPlayingMgr *this, AkPipelineBuffer *io_CurrMarkerBuffer)
{
  AkBufferMarker *v2; // rdi
  AkPipelineBuffer *v3; // rbp
  CAkPlayingMgr *v4; // r12
  unsigned int v5; // esi
  __int64 *v6; // r14
  CAkPBI *v7; // rbx
  int v8; // er8
  CAkPlayingMgr::PlayingMgrItem *v9; // rax
  void (__fastcall *v10)(AkCallbackType, AkCallbackInfo *); // rbx
  __int64 v11; // rcx
  int v12; // eax
  void *v13; // rcx
  __int64 v14; // [rsp+20h] [rbp-58h]
  unsigned __int64 v15; // [rsp+28h] [rbp-50h]
  int v16; // [rsp+30h] [rbp-48h]
  int v17; // [rsp+34h] [rbp-44h]
  int v18; // [rsp+38h] [rbp-40h]
  int v19; // [rsp+3Ch] [rbp-3Ch]
  __int64 v20; // [rsp+40h] [rbp-38h]

  v2 = io_CurrMarkerBuffer->pMarkers;
  v3 = io_CurrMarkerBuffer;
  v4 = this;
  if ( v2 )
  {
    v5 = 0;
    if ( io_CurrMarkerBuffer->uNumMarkers > 0u )
    {
      v6 = (__int64 *)&v2->marker.strLabel;
      do
      {
        v7 = v2->pContext;
        EnterCriticalSection(&v4->m_csMapLock.m_csLock);
        v8 = v7->m_UserParams.m_PlayingID;
        v9 = v4->m_PlayingMap.m_table[v7->m_UserParams.m_PlayingID % 0x1F];
        if ( v9 )
        {
          while ( v9->userParam.m_PlayingID != v8 )
          {
            v9 = v9->pNextItem;
            if ( !v9 )
              goto LABEL_7;
          }
        }
        else
        {
LABEL_7:
          v9 = 0i64;
        }
        if ( v9->uiRegisteredNotif & 4 && (v10 = v9->pfnCallback) != 0i64 )
        {
          v11 = (__int64)v9->pCookie;
          v16 = v8;
          v14 = v11;
          v15 = v9->GameObj;
          LODWORD(v11) = v9->eventID;
          v18 = *((_DWORD *)v6 - 2);
          v12 = *((_DWORD *)v6 - 1);
          v17 = v11;
          v13 = v4->m_CallbackEvent.m_Event;
          v19 = v12;
          v20 = *v6;
          ResetEvent(v13);
          LeaveCriticalSection(&v4->m_csMapLock.m_csLock);
          v10(AK_Marker, (AkCallbackInfo *)&v14);
          SetEvent(v4->m_CallbackEvent.m_Event);
        }
        else
        {
          LeaveCriticalSection(&v4->m_csMapLock.m_csLock);
        }
        ++v5;
        ++v2;
        v6 += 4;
      }
      while ( v5 < v3->uNumMarkers );
    }
    AkPipelineBuffer::FreeMarkers(v3);
  }
}

// File Line: 379
// RVA: 0xA5A6D0
void __fastcall CAkPlayingMgr::NotifyMusic(CAkPlayingMgr *this, unsigned int in_PlayingID, AkCallbackType in_NotifType, AkMusicGrid *in_rGrid)
{
  CAkPlayingMgr *v4; // r14
  AkMusicGrid *v5; // r15
  AkCallbackType v6; // ebp
  unsigned int v7; // ebx
  CAkPlayingMgr::PlayingMgrItem *v8; // rcx
  void (__fastcall *v9)(AkCallbackType, AkCallbackInfo *); // rdi
  __int64 v10; // rax
  void *v11; // rcx
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  void *v15; // [rsp+20h] [rbp-48h]
  __int64 v16; // [rsp+28h] [rbp-40h]
  unsigned int v17; // [rsp+30h] [rbp-38h]
  AkCallbackType v18; // [rsp+34h] [rbp-34h]
  float v19; // [rsp+38h] [rbp-30h]
  float v20; // [rsp+3Ch] [rbp-2Ch]
  float v21; // [rsp+40h] [rbp-28h]
  float v22; // [rsp+44h] [rbp-24h]
  __int64 v23; // [rsp+48h] [rbp-20h]

  v4 = this;
  v5 = in_rGrid;
  v6 = in_NotifType;
  v7 = in_PlayingID;
  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v8 = v4->m_PlayingMap.m_table[v7 % 0x1F];
  if ( v8 )
  {
    while ( v8->userParam.m_PlayingID != v7 )
    {
      v8 = v8->pNextItem;
      if ( !v8 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v8 = 0i64;
  }
  v9 = v8->pfnCallback;
  if ( v9 && v6 & v8->uiRegisteredNotif )
  {
    v15 = v8->pCookie;
    v10 = v8->GameObj;
    v11 = v4->m_CallbackEvent.m_Event;
    v16 = v10;
    v17 = v7;
    v18 = v6;
    v23 = 0i64;
    v12 = 1.0 / (float)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency;
    v13 = (float)(signed int)v5->uBeatDuration;
    LODWORD(v10) = v5->uGridDuration;
    v20 = (float)(signed int)v5->uBarDuration * v12;
    v14 = (float)(signed int)v10;
    LODWORD(v10) = v5->uGridOffset;
    v19 = v13 * v12;
    v21 = v14 * v12;
    v22 = (float)(signed int)v10 * v12;
    ResetEvent(v11);
    LeaveCriticalSection(&v4->m_csMapLock.m_csLock);
    v9(v6, (AkCallbackInfo *)&v15);
    SetEvent(v4->m_CallbackEvent.m_Event);
  }
  else
  {
    LeaveCriticalSection(&v4->m_csMapLock.m_csLock);
  }
}

// File Line: 401
// RVA: 0xA5A940
void __fastcall CAkPlayingMgr::NotifyMusicUserCues(CAkPlayingMgr *this, unsigned int in_PlayingID, AkMusicGrid *in_rGrid, char *in_pszUserCueName)
{
  CAkPlayingMgr *v4; // r14
  char *v5; // r15
  AkMusicGrid *v6; // rbp
  unsigned int v7; // ebx
  CAkPlayingMgr::PlayingMgrItem *v8; // rcx
  void (__fastcall *v9)(AkCallbackType, AkCallbackInfo *); // rdi
  __int64 v10; // rax
  void *v11; // rcx
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  void *v15; // [rsp+20h] [rbp-48h]
  __int64 v16; // [rsp+28h] [rbp-40h]
  unsigned int v17; // [rsp+30h] [rbp-38h]
  int v18; // [rsp+34h] [rbp-34h]
  float v19; // [rsp+38h] [rbp-30h]
  float v20; // [rsp+3Ch] [rbp-2Ch]
  float v21; // [rsp+40h] [rbp-28h]
  float v22; // [rsp+44h] [rbp-24h]
  char *v23; // [rsp+48h] [rbp-20h]

  v4 = this;
  v5 = in_pszUserCueName;
  v6 = in_rGrid;
  v7 = in_PlayingID;
  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v8 = v4->m_PlayingMap.m_table[v7 % 0x1F];
  if ( v8 )
  {
    while ( v8->userParam.m_PlayingID != v7 )
    {
      v8 = v8->pNextItem;
      if ( !v8 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v8 = 0i64;
  }
  v9 = v8->pfnCallback;
  if ( v9 && v8->uiRegisteredNotif & 0x2000 )
  {
    v15 = v8->pCookie;
    v10 = v8->GameObj;
    v11 = v4->m_CallbackEvent.m_Event;
    v16 = v10;
    v17 = v7;
    v18 = 0x2000;
    v23 = v5;
    v12 = 1.0 / (float)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency;
    v13 = (float)(signed int)v6->uBeatDuration;
    LODWORD(v10) = v6->uGridDuration;
    v20 = (float)(signed int)v6->uBarDuration * v12;
    v14 = (float)(signed int)v10;
    LODWORD(v10) = v6->uGridOffset;
    v19 = v13 * v12;
    v21 = v14 * v12;
    v22 = (float)(signed int)v10 * v12;
    ResetEvent(v11);
    LeaveCriticalSection(&v4->m_csMapLock.m_csLock);
    v9(AK_MusicSyncUserCue, (AkCallbackInfo *)&v15);
    SetEvent(v4->m_CallbackEvent.m_Event);
  }
  else
  {
    LeaveCriticalSection(&v4->m_csMapLock.m_csLock);
  }
}

// File Line: 442
// RVA: 0xA5ACE0
signed __int64 __fastcall CAkPlayingMgr::SetPBI(CAkPlayingMgr *this, unsigned int in_PlayingID, CAkTransportAware *in_pPBI, unsigned int *out_puRegisteredNotif)
{
  CAkPlayingMgr *v4; // rdi
  unsigned int *v5; // r14
  unsigned int v6; // esi
  CAkPlayingMgr::PlayingMgrItem *v7; // rax
  unsigned int v8; // ecx

  v4 = this;
  v5 = out_puRegisteredNotif;
  v6 = in_PlayingID;
  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v7 = v4->m_PlayingMap.m_table[v6 % 0x1F];
  if ( v7 )
  {
    while ( v7->userParam.m_PlayingID != v6 )
    {
      v7 = v7->pNextItem;
      if ( !v7 )
        goto LABEL_7;
    }
    if ( v7 )
    {
      v8 = v7->uiRegisteredNotif;
      ++v7->cPBI;
      *v5 = v8;
    }
  }
LABEL_7:
  LeaveCriticalSection(&v4->m_csMapLock.m_csLock);
  return 1i64;
}

// File Line: 468
// RVA: 0xA5ABA0
void __fastcall CAkPlayingMgr::Remove(CAkPlayingMgr *this, unsigned int in_PlayingID, CAkTransportAware *in_pPBI)
{
  CAkPlayingMgr *v3; // rdi
  unsigned int v4; // ebx
  CAkPlayingMgr::PlayingMgrItem *v5; // r8

  v3 = this;
  v4 = in_PlayingID;
  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v5 = v3->m_PlayingMap.m_table[v4 % 0x1F];
  if ( !v5 )
    goto LABEL_4;
  while ( v5->userParam.m_PlayingID != v4 )
  {
    v5 = v5->pNextItem;
    if ( !v5 )
      goto LABEL_4;
  }
  if ( v5 )
  {
    --v5->cPBI;
    CAkPlayingMgr::CheckRemovePlayingID(v3, v4, v5);
  }
  else
  {
LABEL_4:
    LeaveCriticalSection(&v3->m_csMapLock.m_csLock);
  }
}

// File Line: 495
// RVA: 0xA59D10
void __fastcall CAkPlayingMgr::AddItemActiveCount(CAkPlayingMgr *this, unsigned int in_PlayingID)
{
  CAkPlayingMgr *v2; // rsi
  unsigned int v3; // edi
  CAkPlayingMgr::PlayingMgrItem *v4; // rax

  if ( in_PlayingID )
  {
    v2 = this;
    v3 = in_PlayingID;
    EnterCriticalSection(&this->m_csMapLock.m_csLock);
    v4 = v2->m_PlayingMap.m_table[v3 % 0x1F];
    if ( v4 )
    {
      while ( v4->userParam.m_PlayingID != v3 )
      {
        v4 = v4->pNextItem;
        if ( !v4 )
          goto LABEL_8;
      }
      if ( v4 )
        ++v4->cAction;
    }
LABEL_8:
    LeaveCriticalSection(&v2->m_csMapLock.m_csLock);
  }
}

// File Line: 508
// RVA: 0xA5AC40
void __fastcall CAkPlayingMgr::RemoveItemActiveCount(CAkPlayingMgr *this, unsigned int in_PlayingID)
{
  CAkPlayingMgr *v2; // rsi
  unsigned int v3; // ebx
  CAkPlayingMgr::PlayingMgrItem *v4; // r8

  v2 = this;
  v3 = in_PlayingID;
  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v4 = v2->m_PlayingMap.m_table[v3 % 0x1F];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->userParam.m_PlayingID != v3 )
  {
    v4 = v4->pNextItem;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    --v4->cAction;
    CAkPlayingMgr::CheckRemovePlayingID(v2, v3, v4);
  }
  else
  {
LABEL_4:
    LeaveCriticalSection(&v2->m_csMapLock.m_csLock);
  }
}

