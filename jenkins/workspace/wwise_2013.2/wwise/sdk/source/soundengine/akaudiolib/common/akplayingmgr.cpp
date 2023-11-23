// File Line: 38
// RVA: 0xA5A040
__int64 __fastcall CAkPlayingMgr::Init(CAkPlayingMgr *this)
{
  HANDLE EventW; // rcx
  __int64 result; // rax
  CAkPlayingMgr *v4; // rcx
  __int64 v5; // rdx

  EventW = CreateEventW(0i64, 1, 0, 0i64);
  this->m_CallbackEvent.m_Event = EventW;
  result = 2 - (unsigned int)(EventW != 0i64);
  if ( (_DWORD)result == 1 )
  {
    SetEvent(EventW);
    v4 = this;
    v5 = 3i64;
    this->m_PlayingMap.m_uiSize = 0;
    do
    {
      v4->m_PlayingMap.m_table[0] = 0i64;
      v4->m_PlayingMap.m_table[1] = 0i64;
      v4->m_PlayingMap.m_table[2] = 0i64;
      v4 = (CAkPlayingMgr *)((char *)v4 + 64);
      v4[-1].m_BusCallbackMgr.m_csLock.m_csLock.DebugInfo = 0i64;
      *(_QWORD *)&v4[-1].m_BusCallbackMgr.m_csLock.m_csLock.LockCount = 0i64;
      v4[-1].m_BusCallbackMgr.m_csLock.m_csLock.OwningThread = 0i64;
      v4[-1].m_BusCallbackMgr.m_csLock.m_csLock.LockSemaphore = 0i64;
      v4[-1].m_BusCallbackMgr.m_csLock.m_csLock.SpinCount = 0i64;
      --v5;
    }
    while ( v5 );
    v4->m_PlayingMap.m_table[0] = 0i64;
    v4->m_PlayingMap.m_table[1] = 0i64;
    v4->m_PlayingMap.m_table[2] = 0i64;
    v4->m_PlayingMap.m_table[3] = 0i64;
    v4->m_PlayingMap.m_table[4] = 0i64;
    v4->m_PlayingMap.m_table[5] = 0i64;
    v4->m_PlayingMap.m_table[6] = 0i64;
    result = 1i64;
    g_pBusCallbackMgr = &this->m_BusCallbackMgr;
  }
  return result;
}

// File Line: 68
// RVA: 0xA59DA0
__int64 __fastcall CAkPlayingMgr::AddPlayingID(
        CAkPlayingMgr *this,
        AkQueuedMsg_EventBase *in_event,
        void (__fastcall *in_pfnCallback)(AkCallbackType, AkCallbackInfo *),
        void *in_pCookie,
        unsigned int in_uiRegisteredNotif,
        unsigned int in_id)
{
  CAkPlayingMgr::PlayingMgrItem *v10; // rax
  CAkPlayingMgr::PlayingMgrItem *v11; // rdi
  unsigned int v12; // ebp
  AkExternalSourceArray *pExternalSrcs; // rcx
  AkExternalSourceArray *v14; // rsi
  unsigned int v15; // eax
  unsigned int m_PlayingID; // ecx
  __int64 v17; // rcx

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
    v10->GameObj = in_event->GameObjID;
    pExternalSrcs = v10->userParam.m_CustomParam.pExternalSrcs;
    v10->userParam.m_PlayingID = in_event->PlayingID;
    v10->userParam.m_CustomParam.customParam = in_event->CustomParam.customParam;
    v10->userParam.m_CustomParam.ui32Reserved = in_event->CustomParam.ui32Reserved;
    v14 = in_event->CustomParam.pExternalSrcs;
    if ( pExternalSrcs )
      AkExternalSourceArray::Release(pExternalSrcs);
    if ( v14 )
      ++v14->m_cRefCount;
    v15 = in_uiRegisteredNotif;
    v11->userParam.m_CustomParam.pExternalSrcs = v14;
    v11->pfnCallback = in_pfnCallback;
    v11->pCookie = in_pCookie;
    if ( !in_pfnCallback )
      v15 = in_uiRegisteredNotif & 0xFFFF2004;
    m_PlayingID = v11->userParam.m_PlayingID;
    v11->uiRegisteredNotif = v15;
    v17 = m_PlayingID % 0x1F;
    v11->pNextItem = this->m_PlayingMap.m_table[v17];
    this->m_PlayingMap.m_table[v17] = v11;
    ++this->m_PlayingMap.m_uiSize;
  }
  else
  {
    v12 = 2;
  }
  LeaveCriticalSection(&this->m_csMapLock.m_csLock);
  return v12;
}

// File Line: 130
// RVA: 0xA59ED0
void __fastcall CAkPlayingMgr::CheckRemovePlayingID(
        CAkPlayingMgr *this,
        unsigned int in_PlayingID,
        CAkPlayingMgr::PlayingMgrItem *in_pItem)
{
  void (__fastcall *pfnCallback)(AkCallbackType, AkCallbackInfo *); // r14
  unsigned int uiRegisteredNotif; // ebp
  unsigned int eventID; // eax
  CAkPlayingMgr::PlayingMgrItem *v9; // rdx
  CAkPlayingMgr::PlayingMgrItem **v10; // r8
  CAkPlayingMgr::PlayingMgrItem *v11; // rax
  CAkPlayingMgr::PlayingMgrItem *pNextItem; // rcx
  AkExternalSourceArray *pExternalSrcs; // rcx
  int v14; // esi
  __int64 v15[2]; // [rsp+20h] [rbp-28h] BYREF
  unsigned int v16; // [rsp+30h] [rbp-18h]
  unsigned int v17; // [rsp+34h] [rbp-14h]

  if ( *(_QWORD *)&in_pItem->cPBI )
  {
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
  }
  else
  {
    if ( (in_pItem->uiRegisteredNotif & 0x10000) != 0 )
      CAkPositionRepository::RemovePlayingID((CAkSegmentInfoRepository *)g_pPositionRepository, in_PlayingID);
    pfnCallback = in_pItem->pfnCallback;
    uiRegisteredNotif = in_pItem->uiRegisteredNotif;
    v15[0] = (__int64)in_pItem->pCookie;
    v15[1] = in_pItem->GameObj;
    eventID = in_pItem->eventID;
    v16 = in_PlayingID;
    v17 = eventID;
    v9 = 0i64;
    v10 = &this->m_PlayingMap.m_table[in_PlayingID % 0x1F];
    v11 = *v10;
    if ( *v10 )
    {
      while ( v11->userParam.m_PlayingID != in_PlayingID )
      {
        v9 = v11;
        v11 = v11->pNextItem;
        if ( !v11 )
          goto LABEL_12;
      }
      pNextItem = v11->pNextItem;
      if ( v9 )
        v9->pNextItem = pNextItem;
      else
        *v10 = pNextItem;
      --this->m_PlayingMap.m_uiSize;
    }
LABEL_12:
    pExternalSrcs = in_pItem->userParam.m_CustomParam.pExternalSrcs;
    v14 = g_DefaultPoolId;
    if ( pExternalSrcs )
      AkExternalSourceArray::Release(pExternalSrcs);
    AK::MemoryMgr::Free(v14, in_pItem);
    if ( (uiRegisteredNotif & 1) != 0 )
    {
      ResetEvent(this->m_CallbackEvent.m_Event);
      LeaveCriticalSection(&this->m_csMapLock.m_csLock);
      pfnCallback(AK_EndOfEvent, (AkCallbackInfo *)v15);
      SetEvent(this->m_CallbackEvent.m_Event);
    }
    else
    {
      LeaveCriticalSection(&this->m_csMapLock.m_csLock);
    }
  }
}

// File Line: 181
// RVA: 0xA5A340
void __fastcall CAkPlayingMgr::NotifyEndOfDynamicSequenceItem(
        CAkPlayingMgr *this,
        unsigned int in_PlayingID,
        unsigned int in_audioNodeID,
        __int64 in_pCustomInfo)
{
  CAkPlayingMgr::PlayingMgrItem *v8; // rax
  __int64 pCookie; // rdx
  void *m_Event; // rcx
  void (__fastcall *pfnCallback)(AkCallbackType, AkCallbackInfo *); // rbx
  __int64 v12[2]; // [rsp+20h] [rbp-28h] BYREF
  unsigned int v13; // [rsp+30h] [rbp-18h]
  unsigned int v14; // [rsp+34h] [rbp-14h]
  __int64 v15; // [rsp+38h] [rbp-10h]

  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v8 = this->m_PlayingMap.m_table[in_PlayingID % 0x1F];
  if ( !v8 )
    goto LABEL_4;
  while ( v8->userParam.m_PlayingID != in_PlayingID )
  {
    v8 = v8->pNextItem;
    if ( !v8 )
      goto LABEL_4;
  }
  if ( (v8->uiRegisteredNotif & 2) != 0 )
  {
    pCookie = (__int64)v8->pCookie;
    m_Event = this->m_CallbackEvent.m_Event;
    v13 = in_PlayingID;
    pfnCallback = v8->pfnCallback;
    v12[0] = pCookie;
    v12[1] = v8->GameObj;
    v14 = in_audioNodeID;
    v15 = in_pCustomInfo;
    ResetEvent(m_Event);
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
    pfnCallback(AK_EndOfDynamicSequenceItem, (AkCallbackInfo *)v12);
    SetEvent(this->m_CallbackEvent.m_Event);
  }
  else
  {
LABEL_4:
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
  }
}

// File Line: 212
// RVA: 0xA5A220
void __fastcall CAkPlayingMgr::NotifyDuration(
        CAkPlayingMgr *this,
        unsigned int in_PlayingID,
        float in_fDuration,
        float in_fEstimatedDuration,
        unsigned int in_idAudioNode)
{
  CAkPlayingMgr::PlayingMgrItem *v7; // rbx
  __int64 pCookie; // rax
  void *m_Event; // rcx
  __int64 GameObj; // rax
  void (__fastcall *pfnCallback)(AkCallbackType, AkCallbackInfo *); // rbx
  __int64 v12[2]; // [rsp+20h] [rbp-58h] BYREF
  unsigned int v13; // [rsp+30h] [rbp-48h]
  int v14; // [rsp+34h] [rbp-44h]
  float v15; // [rsp+38h] [rbp-40h]
  float v16; // [rsp+3Ch] [rbp-3Ch]
  unsigned int v17; // [rsp+40h] [rbp-38h]

  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v7 = this->m_PlayingMap.m_table[in_PlayingID % 0x1F];
  if ( !v7 )
    goto LABEL_4;
  while ( v7->userParam.m_PlayingID != in_PlayingID )
  {
    v7 = v7->pNextItem;
    if ( !v7 )
      goto LABEL_4;
  }
  if ( (v7->uiRegisteredNotif & 8) != 0 )
  {
    pCookie = (__int64)v7->pCookie;
    m_Event = this->m_CallbackEvent.m_Event;
    v15 = in_fDuration;
    v12[0] = pCookie;
    GameObj = v7->GameObj;
    v16 = in_fEstimatedDuration;
    v12[1] = GameObj;
    LODWORD(GameObj) = v7->eventID;
    pfnCallback = v7->pfnCallback;
    v14 = GameObj;
    v13 = in_PlayingID;
    v17 = in_idAudioNode;
    ResetEvent(m_Event);
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
    pfnCallback(AK_Duration, (AkCallbackInfo *)v12);
    SetEvent(this->m_CallbackEvent.m_Event);
  }
  else
  {
LABEL_4:
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
  }
}

// File Line: 241
// RVA: 0xA5A850
void __fastcall CAkPlayingMgr::NotifyMusicPlayStarted(CAkPlayingMgr *this, unsigned int in_PlayingID)
{
  CAkPlayingMgr::PlayingMgrItem *v4; // rax
  void (__fastcall *pfnCallback)(AkCallbackType, AkCallbackInfo *); // rdi
  __int64 pCookie; // rdx
  void *m_Event; // rcx
  __int64 v8[2]; // [rsp+20h] [rbp-28h] BYREF
  unsigned int v9; // [rsp+30h] [rbp-18h]
  unsigned int eventID; // [rsp+34h] [rbp-14h]

  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v4 = this->m_PlayingMap.m_table[in_PlayingID % 0x1F];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->userParam.m_PlayingID != in_PlayingID )
  {
    v4 = v4->pNextItem;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( SLOBYTE(v4->uiRegisteredNotif) < 0 && (pfnCallback = v4->pfnCallback) != 0i64 )
  {
    pCookie = (__int64)v4->pCookie;
    m_Event = this->m_CallbackEvent.m_Event;
    v9 = in_PlayingID;
    v8[0] = pCookie;
    v8[1] = v4->GameObj;
    eventID = v4->eventID;
    ResetEvent(m_Event);
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
    pfnCallback(AK_MusicPlayStarted, (AkCallbackInfo *)v8);
    SetEvent(this->m_CallbackEvent.m_Event);
  }
  else
  {
LABEL_4:
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
  }
}

// File Line: 269
// RVA: 0xA5A0F0
void __fastcall CAkPlayingMgr::MusicPlaylistCallback(
        CAkPlayingMgr *this,
        unsigned int in_PlayingID,
        unsigned int in_playlistID,
        unsigned int in_uNumPlaylistItems,
        unsigned int *io_uSelection,
        unsigned int *io_uItemDone)
{
  CAkPlayingMgr::PlayingMgrItem *v9; // rax
  void (__fastcall *pfnCallback)(AkCallbackType, AkCallbackInfo *); // rsi
  __int64 pCookie; // rcx
  int eventID; // edx
  __int64 GameObj; // rcx
  unsigned int v14; // eax
  unsigned int v15; // eax
  void *m_Event; // rcx
  __int64 v17[2]; // [rsp+20h] [rbp-38h] BYREF
  unsigned int v18; // [rsp+30h] [rbp-28h]
  int v19; // [rsp+34h] [rbp-24h]
  unsigned int v20; // [rsp+3Ch] [rbp-1Ch]
  unsigned int v21; // [rsp+40h] [rbp-18h]
  unsigned int v22; // [rsp+44h] [rbp-14h]

  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v9 = this->m_PlayingMap.m_table[in_PlayingID % 0x1F];
  if ( !v9 )
    goto LABEL_4;
  while ( v9->userParam.m_PlayingID != in_PlayingID )
  {
    v9 = v9->pNextItem;
    if ( !v9 )
      goto LABEL_4;
  }
  if ( (v9->uiRegisteredNotif & 0x40) != 0 && (pfnCallback = v9->pfnCallback) != 0i64 )
  {
    pCookie = (__int64)v9->pCookie;
    eventID = v9->eventID;
    v20 = in_uNumPlaylistItems;
    v17[0] = pCookie;
    GameObj = v9->GameObj;
    v14 = *io_uSelection;
    v18 = in_PlayingID;
    v21 = v14;
    v15 = *io_uItemDone;
    v17[1] = GameObj;
    m_Event = this->m_CallbackEvent.m_Event;
    v19 = eventID;
    v22 = v15;
    ResetEvent(m_Event);
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
    pfnCallback(AK_MusicPlaylistSelect, (AkCallbackInfo *)v17);
    SetEvent(this->m_CallbackEvent.m_Event);
    *io_uSelection = v21;
    *io_uItemDone = v22;
  }
  else
  {
LABEL_4:
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
  }
}

// File Line: 304
// RVA: 0xA5A440
void __fastcall CAkPlayingMgr::NotifyMarker(CAkPlayingMgr *this, CAkPBI *in_pPBI, AkAudioMarker *in_pMarker)
{
  unsigned int m_PlayingID; // r10d
  CAkPlayingMgr::PlayingMgrItem *v7; // rax
  void (__fastcall *pfnCallback)(AkCallbackType, AkCallbackInfo *); // rbx
  __int64 GameObj; // rdx
  __int64 pCookie; // rcx
  unsigned int dwPosition; // eax
  void *m_Event; // rcx
  __int64 v13[2]; // [rsp+20h] [rbp-38h] BYREF
  unsigned int v14; // [rsp+30h] [rbp-28h]
  int v15; // [rsp+34h] [rbp-24h]
  unsigned int dwIdentifier; // [rsp+38h] [rbp-20h]
  unsigned int v17; // [rsp+3Ch] [rbp-1Ch]
  char *strLabel; // [rsp+40h] [rbp-18h]

  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  m_PlayingID = in_pPBI->m_UserParams.m_PlayingID;
  v7 = this->m_PlayingMap.m_table[m_PlayingID % 0x1F];
  if ( v7 )
  {
    while ( v7->userParam.m_PlayingID != m_PlayingID )
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
  if ( (v7->uiRegisteredNotif & 4) != 0 && (pfnCallback = v7->pfnCallback) != 0i64 )
  {
    GameObj = v7->GameObj;
    pCookie = (__int64)v7->pCookie;
    v14 = m_PlayingID;
    v13[1] = GameObj;
    LODWORD(GameObj) = v7->eventID;
    dwIdentifier = in_pMarker->dwIdentifier;
    dwPosition = in_pMarker->dwPosition;
    v13[0] = pCookie;
    m_Event = this->m_CallbackEvent.m_Event;
    v17 = dwPosition;
    strLabel = in_pMarker->strLabel;
    v15 = GameObj;
    ResetEvent(m_Event);
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
    pfnCallback(AK_Marker, (AkCallbackInfo *)v13);
    SetEvent(this->m_CallbackEvent.m_Event);
  }
  else
  {
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
  }
}

// File Line: 340
// RVA: 0xA5AAC0
void __fastcall CAkPlayingMgr::NotifySpeakerVolumeMatrix(
        CAkPlayingMgr *this,
        unsigned int in_PlayingID,
        AkSpeakerVolumeMatrixCallbackInfo *in_pInfo)
{
  CAkPlayingMgr::PlayingMgrItem *v6; // rax
  unsigned __int64 GameObj; // rdx
  void (__fastcall *pfnCallback)(AkCallbackType, AkCallbackInfo *); // rbx

  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v6 = this->m_PlayingMap.m_table[in_PlayingID % 0x1F];
  if ( !v6 )
    goto LABEL_4;
  while ( v6->userParam.m_PlayingID != in_PlayingID )
  {
    v6 = v6->pNextItem;
    if ( !v6 )
      goto LABEL_4;
  }
  if ( (v6->uiRegisteredNotif & 0x10) != 0 )
  {
    in_pInfo->pCookie = v6->pCookie;
    GameObj = v6->GameObj;
    in_pInfo->playingID = in_PlayingID;
    in_pInfo->gameObjID = GameObj;
    in_pInfo->eventID = v6->eventID;
    pfnCallback = v6->pfnCallback;
    ResetEvent(this->m_CallbackEvent.m_Event);
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
    pfnCallback(AK_SpeakerVolumeMatrix, in_pInfo);
    SetEvent(this->m_CallbackEvent.m_Event);
  }
  else
  {
LABEL_4:
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
  }
}

// File Line: 362
// RVA: 0xA5A550
void __fastcall CAkPlayingMgr::NotifyMarkers(CAkPlayingMgr *this, AkPipelineBuffer *io_CurrMarkerBuffer)
{
  AkBufferMarker *pMarkers; // rdi
  unsigned int v5; // esi
  __int64 *p_strLabel; // r14
  CAkPBI *pContext; // rbx
  unsigned int m_PlayingID; // r8d
  CAkPlayingMgr::PlayingMgrItem *v9; // rax
  void (__fastcall *pfnCallback)(AkCallbackType, AkCallbackInfo *); // rbx
  __int64 pCookie; // rcx
  int v12; // eax
  void *m_Event; // rcx
  __int64 v14[2]; // [rsp+20h] [rbp-58h] BYREF
  unsigned int v15; // [rsp+30h] [rbp-48h]
  int v16; // [rsp+34h] [rbp-44h]
  int v17; // [rsp+38h] [rbp-40h]
  int v18; // [rsp+3Ch] [rbp-3Ch]
  __int64 v19; // [rsp+40h] [rbp-38h]

  pMarkers = io_CurrMarkerBuffer->pMarkers;
  if ( pMarkers )
  {
    v5 = 0;
    if ( io_CurrMarkerBuffer->uNumMarkers )
    {
      p_strLabel = (__int64 *)&pMarkers->marker.strLabel;
      do
      {
        pContext = pMarkers->pContext;
        EnterCriticalSection(&this->m_csMapLock.m_csLock);
        m_PlayingID = pContext->m_UserParams.m_PlayingID;
        v9 = this->m_PlayingMap.m_table[m_PlayingID % 0x1F];
        if ( v9 )
        {
          while ( v9->userParam.m_PlayingID != m_PlayingID )
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
        if ( (v9->uiRegisteredNotif & 4) != 0 && (pfnCallback = v9->pfnCallback) != 0i64 )
        {
          pCookie = (__int64)v9->pCookie;
          v15 = m_PlayingID;
          v14[0] = pCookie;
          v14[1] = v9->GameObj;
          LODWORD(pCookie) = v9->eventID;
          v17 = *((_DWORD *)p_strLabel - 2);
          v12 = *((_DWORD *)p_strLabel - 1);
          v16 = pCookie;
          m_Event = this->m_CallbackEvent.m_Event;
          v18 = v12;
          v19 = *p_strLabel;
          ResetEvent(m_Event);
          LeaveCriticalSection(&this->m_csMapLock.m_csLock);
          pfnCallback(AK_Marker, (AkCallbackInfo *)v14);
          SetEvent(this->m_CallbackEvent.m_Event);
        }
        else
        {
          LeaveCriticalSection(&this->m_csMapLock.m_csLock);
        }
        ++v5;
        ++pMarkers;
        p_strLabel += 4;
      }
      while ( v5 < io_CurrMarkerBuffer->uNumMarkers );
    }
    AkPipelineBuffer::FreeMarkers(io_CurrMarkerBuffer);
  }
}

// File Line: 379
// RVA: 0xA5A6D0
void __fastcall CAkPlayingMgr::NotifyMusic(
        CAkPlayingMgr *this,
        unsigned int in_PlayingID,
        unsigned int in_NotifType,
        AkMusicGrid *in_rGrid)
{
  CAkPlayingMgr::PlayingMgrItem *v8; // rcx
  void (__fastcall *pfnCallback)(AkCallbackType, AkCallbackInfo *); // rdi
  __int64 GameObj; // rax
  void *m_Event; // rcx
  float v12; // xmm2_4
  float uBeatDuration; // xmm1_4
  float v14; // xmm0_4
  __int64 v15[2]; // [rsp+20h] [rbp-48h] BYREF
  unsigned int v16; // [rsp+30h] [rbp-38h]
  unsigned int v17; // [rsp+34h] [rbp-34h]
  float v18; // [rsp+38h] [rbp-30h]
  float v19; // [rsp+3Ch] [rbp-2Ch]
  float v20; // [rsp+40h] [rbp-28h]
  float v21; // [rsp+44h] [rbp-24h]
  __int64 v22; // [rsp+48h] [rbp-20h]

  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v8 = this->m_PlayingMap.m_table[in_PlayingID % 0x1F];
  if ( v8 )
  {
    while ( v8->userParam.m_PlayingID != in_PlayingID )
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
  pfnCallback = v8->pfnCallback;
  if ( pfnCallback && (in_NotifType & v8->uiRegisteredNotif) != 0 )
  {
    v15[0] = (__int64)v8->pCookie;
    GameObj = v8->GameObj;
    m_Event = this->m_CallbackEvent.m_Event;
    v15[1] = GameObj;
    v16 = in_PlayingID;
    v17 = in_NotifType;
    v22 = 0i64;
    v12 = 1.0 / (float)(int)AkAudioLibSettings::g_pipelineCoreFrequency;
    uBeatDuration = (float)(int)in_rGrid->uBeatDuration;
    LODWORD(GameObj) = in_rGrid->uGridDuration;
    v19 = (float)(int)in_rGrid->uBarDuration * v12;
    v14 = (float)(int)GameObj;
    LODWORD(GameObj) = in_rGrid->uGridOffset;
    v18 = uBeatDuration * v12;
    v20 = v14 * v12;
    v21 = (float)(int)GameObj * v12;
    ResetEvent(m_Event);
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
    pfnCallback((AkCallbackType)in_NotifType, (AkCallbackInfo *)v15);
    SetEvent(this->m_CallbackEvent.m_Event);
  }
  else
  {
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
  }
}

// File Line: 401
// RVA: 0xA5A940
void __fastcall CAkPlayingMgr::NotifyMusicUserCues(
        CAkPlayingMgr *this,
        unsigned int in_PlayingID,
        AkMusicGrid *in_rGrid,
        char *in_pszUserCueName)
{
  CAkPlayingMgr::PlayingMgrItem *v8; // rcx
  void (__fastcall *pfnCallback)(AkCallbackType, AkCallbackInfo *); // rdi
  __int64 GameObj; // rax
  void *m_Event; // rcx
  float v12; // xmm2_4
  float uBeatDuration; // xmm1_4
  float v14; // xmm0_4
  __int64 v15[2]; // [rsp+20h] [rbp-48h] BYREF
  unsigned int v16; // [rsp+30h] [rbp-38h]
  int v17; // [rsp+34h] [rbp-34h]
  float v18; // [rsp+38h] [rbp-30h]
  float v19; // [rsp+3Ch] [rbp-2Ch]
  float v20; // [rsp+40h] [rbp-28h]
  float v21; // [rsp+44h] [rbp-24h]
  char *v22; // [rsp+48h] [rbp-20h]

  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v8 = this->m_PlayingMap.m_table[in_PlayingID % 0x1F];
  if ( v8 )
  {
    while ( v8->userParam.m_PlayingID != in_PlayingID )
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
  pfnCallback = v8->pfnCallback;
  if ( pfnCallback && (v8->uiRegisteredNotif & 0x2000) != 0 )
  {
    v15[0] = (__int64)v8->pCookie;
    GameObj = v8->GameObj;
    m_Event = this->m_CallbackEvent.m_Event;
    v15[1] = GameObj;
    v16 = in_PlayingID;
    v17 = 0x2000;
    v22 = in_pszUserCueName;
    v12 = 1.0 / (float)(int)AkAudioLibSettings::g_pipelineCoreFrequency;
    uBeatDuration = (float)(int)in_rGrid->uBeatDuration;
    LODWORD(GameObj) = in_rGrid->uGridDuration;
    v19 = (float)(int)in_rGrid->uBarDuration * v12;
    v14 = (float)(int)GameObj;
    LODWORD(GameObj) = in_rGrid->uGridOffset;
    v18 = uBeatDuration * v12;
    v20 = v14 * v12;
    v21 = (float)(int)GameObj * v12;
    ResetEvent(m_Event);
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
    pfnCallback(AK_MusicSyncUserCue, (AkCallbackInfo *)v15);
    SetEvent(this->m_CallbackEvent.m_Event);
  }
  else
  {
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
  }
}

// File Line: 442
// RVA: 0xA5ACE0
__int64 __fastcall CAkPlayingMgr::SetPBI(
        CAkPlayingMgr *this,
        unsigned int in_PlayingID,
        CAkTransportAware *in_pPBI,
        unsigned int *out_puRegisteredNotif)
{
  CAkPlayingMgr::PlayingMgrItem *v7; // rax
  unsigned int uiRegisteredNotif; // ecx

  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v7 = this->m_PlayingMap.m_table[in_PlayingID % 0x1F];
  if ( v7 )
  {
    while ( v7->userParam.m_PlayingID != in_PlayingID )
    {
      v7 = v7->pNextItem;
      if ( !v7 )
        goto LABEL_6;
    }
    uiRegisteredNotif = v7->uiRegisteredNotif;
    ++v7->cPBI;
    *out_puRegisteredNotif = uiRegisteredNotif;
  }
LABEL_6:
  LeaveCriticalSection(&this->m_csMapLock.m_csLock);
  return 1i64;
}

// File Line: 468
// RVA: 0xA5ABA0
void __fastcall CAkPlayingMgr::Remove(CAkPlayingMgr *this, unsigned int in_PlayingID, CAkTransportAware *in_pPBI)
{
  CAkPlayingMgr::PlayingMgrItem *v5; // r8

  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v5 = this->m_PlayingMap.m_table[in_PlayingID % 0x1F];
  if ( v5 )
  {
    while ( v5->userParam.m_PlayingID != in_PlayingID )
    {
      v5 = v5->pNextItem;
      if ( !v5 )
        goto LABEL_4;
    }
    --v5->cPBI;
    CAkPlayingMgr::CheckRemovePlayingID(this, in_PlayingID, v5);
  }
  else
  {
LABEL_4:
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
  }
}

// File Line: 495
// RVA: 0xA59D10
void __fastcall CAkPlayingMgr::AddItemActiveCount(CAkPlayingMgr *this, unsigned int in_PlayingID)
{
  CAkPlayingMgr::PlayingMgrItem *v4; // rax

  if ( in_PlayingID )
  {
    EnterCriticalSection(&this->m_csMapLock.m_csLock);
    v4 = this->m_PlayingMap.m_table[in_PlayingID % 0x1F];
    if ( v4 )
    {
      while ( v4->userParam.m_PlayingID != in_PlayingID )
      {
        v4 = v4->pNextItem;
        if ( !v4 )
          goto LABEL_7;
      }
      ++v4->cAction;
    }
LABEL_7:
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
  }
}

// File Line: 508
// RVA: 0xA5AC40
void __fastcall CAkPlayingMgr::RemoveItemActiveCount(CAkPlayingMgr *this, unsigned int in_PlayingID)
{
  CAkPlayingMgr::PlayingMgrItem *v4; // r8

  EnterCriticalSection(&this->m_csMapLock.m_csLock);
  v4 = this->m_PlayingMap.m_table[in_PlayingID % 0x1F];
  if ( v4 )
  {
    while ( v4->userParam.m_PlayingID != in_PlayingID )
    {
      v4 = v4->pNextItem;
      if ( !v4 )
        goto LABEL_4;
    }
    --v4->cAction;
    CAkPlayingMgr::CheckRemovePlayingID(this, in_PlayingID, v4);
  }
  else
  {
LABEL_4:
    LeaveCriticalSection(&this->m_csMapLock.m_csLock);
  }
}

