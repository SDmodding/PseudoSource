// File Line: 127
// RVA: 0xA4B4C0
__int64 __fastcall UEL::ArgumentUsageExpression::GetClassSize()
{
  return 32i64;
}

// File Line: 128
// RVA: 0xA4B4D0
__int64 __fastcall Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_CreateTexture,Scaleform::Render::DICommand>::GetSize()
{
  return 16i64;
}

// File Line: 133
// RVA: 0xA4B4B0
__int64 __fastcall Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_GetColorBoundsRect,Scaleform::Render::DICommand>::GetSize()
{
  return 40i64;
}

// File Line: 177
// RVA: 0xA477B0
void __fastcall CAkAudioMgr::CAkAudioMgr(CAkAudioMgr *this)
{
  InitializeCriticalSection(&this->m_queueLock.m_csLock);
  this->m_MsgQueue.blocks.m_pItems = 0i64;
  *(_QWORD *)&this->m_MsgQueue.blocks.m_uLength = 0i64;
  *(_QWORD *)&this->m_MsgQueue.m_uReadBlock = 0i64;
  *(_QWORD *)&this->m_MsgQueue.m_uWriteBlock = 0i64;
  this->m_MsgQueue.m_bBufferFull = 0;
  this->m_bDrainMsgQueue = 0;
  this->m_MsgQueueActualSize = 0;
  *(_QWORD *)&this->m_mmapPending.m_ulMinNumListItems = 0i64;
  this->m_mmapPending.m_ulNumListItems = 0;
  *(_QWORD *)&this->m_mmapPausedPending.m_ulMinNumListItems = 0i64;
  this->m_mmapPausedPending.m_ulNumListItems = 0;
  *(_QWORD *)&this->m_uBufferTick = 0i64;
  this->m_ulReaderFlag = 0;
  CAkAudioThread::CAkAudioThread(&this->m_audioThread);
  this->m_hEventMgrThreadDrainEvent.m_Event = 0i64;
  this->m_timeLastBuffer = 0i64;
  this->m_uCallsWithoutTicks = 0;
}

// File Line: 191
// RVA: 0xA478C0
void __fastcall CAkAudioMgr::~CAkAudioMgr(CAkAudioMgr *this)
{
  void *m_Event; // rcx

  m_Event = this->m_hEventMgrThreadDrainEvent.m_Event;
  if ( m_Event )
    CloseHandle(m_Event);
  DeleteCriticalSection(&this->m_queueLock.m_csLock);
}

// File Line: 195
// RVA: 0xA48140
__int64 __fastcall CAkAudioMgr::Init(CAkAudioMgr *this)
{
  unsigned int uCommandQueueSize; // ebx
  unsigned int ChunkSize; // eax
  __int64 result; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // rax
  unsigned int v6; // ebx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v7; // rcx
  unsigned int v8; // edx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v9; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v10; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v11; // rcx
  unsigned int v12; // edx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v13; // rax

  *(_QWORD *)&this->m_ulWriterFlag = 0i64;
  uCommandQueueSize = g_settings.uCommandQueueSize;
  ChunkSize = AkSparseChunkRing::GetChunkSize();
  result = AkSparseChunkRing::Init(&this->m_MsgQueue, uCommandQueueSize / ChunkSize);
  if ( (_DWORD)result == 1 )
  {
    this->m_mmapPending.m_ulNumListItems = 0;
    this->m_mmapPending.m_ulMaxNumListItems = -1;
    this->m_mmapPending.m_pFree = 0i64;
    v5 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x300ui64);
    v6 = 52;
    v7 = v5;
    this->m_mmapPending.m_pvMemStart = v5;
    if ( v5 )
    {
      this->m_mmapPending.m_ulMinNumListItems = 32;
      this->m_mmapPending.m_pFree = v5;
      v8 = 0;
      do
      {
        v9 = v7 + 1;
        ++v8;
        v7->pNextListItem = v7 + 1;
        ++v7;
      }
      while ( v8 < this->m_mmapPending.m_ulMinNumListItems );
      v9[-1].pNextListItem = 0i64;
      result = 1i64;
    }
    else
    {
      result = 52i64;
    }
    this->m_mmapPending.m_pFirst = 0i64;
    this->m_mmapPending.m_pLast = 0i64;
    if ( (_DWORD)result == 1 )
    {
      this->m_mmapPausedPending.m_ulNumListItems = 0;
      this->m_mmapPausedPending.m_ulMaxNumListItems = -1;
      this->m_mmapPausedPending.m_pFree = 0i64;
      v10 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x300ui64);
      v11 = v10;
      this->m_mmapPausedPending.m_pvMemStart = v10;
      if ( v10 )
      {
        this->m_mmapPausedPending.m_ulMinNumListItems = 32;
        this->m_mmapPausedPending.m_pFree = v10;
        v12 = 0;
        do
        {
          v13 = v11 + 1;
          ++v12;
          v11->pNextListItem = v11 + 1;
          ++v11;
        }
        while ( v12 < this->m_mmapPausedPending.m_ulMinNumListItems );
        v13[-1].pNextListItem = 0i64;
        v6 = 1;
      }
      this->m_mmapPausedPending.m_pFirst = 0i64;
      this->m_mmapPausedPending.m_pLast = 0i64;
      return v6;
    }
  }
  return result;
}

// File Line: 216
// RVA: 0xA4C050
void __fastcall CAkAudioMgr::Term(CAkAudioMgr *this)
{
  CAkAudioThread::Stop(&this->m_audioThread);
  CAkAudioMgr::RemoveAllPreallocAndReferences(this);
  CAkAudioMgr::RemoveAllPausedPendingAction(this);
  CAkAudioMgr::RemoveAllPendingAction(this);
  AkSparseChunkRing::Term(&this->m_MsgQueue);
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::Term((CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault> *)&this->m_mmapPending);
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::Term((CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault> *)&this->m_mmapPausedPending);
}

// File Line: 240
// RVA: 0xA4ACB0
signed __int64 __fastcall CAkAudioMgr::RenderAudio(CAkAudioMgr *this)
{
  bool v2; // al
  bool v3; // di
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  EnterCriticalSection(&this->m_queueLock.m_csLock);
  v2 = *(_QWORD *)&this->m_MsgQueue.m_uReadBlock == *(_QWORD *)&this->m_MsgQueue.m_uWriteBlock
    && !this->m_MsgQueue.m_bBufferFull;
  v3 = !v2;
  if ( !v2 )
  {
    *(_DWORD *)&in_rItem.size = 8;
    CAkAudioMgr::LockedEnqueue(this, &in_rItem, 8u);
    ++this->m_ulWriterFlag;
  }
  LeaveCriticalSection(&this->m_queueLock.m_csLock);
  if ( v3 )
    CAkAudioThread::WakeupEventsConsumer(&this->m_audioThread);
  return 1i64;
}

// File Line: 275
// RVA: 0xA47F70
__int64 __fastcall CAkAudioMgr::Enqueue(CAkAudioMgr *this, AkQueuedMsg *in_rItem, unsigned int in_uSize)
{
  AKRESULT v6; // ebx

  EnterCriticalSection(&this->m_queueLock.m_csLock);
  v6 = CAkAudioMgr::LockedEnqueue(this, in_rItem, in_uSize);
  LeaveCriticalSection(&this->m_queueLock.m_csLock);
  return (unsigned int)v6;
}

// File Line: 292
// RVA: 0xA48530
__int64 __fastcall CAkAudioMgr::LockedEnqueue(CAkAudioMgr *this, AkQueuedMsg *in_rItem, unsigned int in_uSize)
{
  __int64 result; // rax

  in_rItem->size = in_uSize;
  result = AkSparseChunkRing::Write(&this->m_MsgQueue, in_rItem, in_uSize);
  if ( (_DWORD)result == 52 )
  {
    while ( in_uSize <= (unsigned int)AkSparseChunkRing::GetChunkSize() )
    {
      ResetEvent(this->m_hEventMgrThreadDrainEvent.m_Event);
      this->m_bDrainMsgQueue = 1;
      LeaveCriticalSection(&this->m_queueLock.m_csLock);
      CAkAudioThread::WakeupEventsConsumer(&this->m_audioThread);
      WaitForSingleObject(this->m_hEventMgrThreadDrainEvent.m_Event, 0xFFFFFFFF);
      EnterCriticalSection(&this->m_queueLock.m_csLock);
      result = AkSparseChunkRing::Write(&this->m_MsgQueue, in_rItem, in_uSize);
      if ( (_DWORD)result != 52 )
        return result;
    }
    return 81i64;
  }
  return result;
}

// File Line: 340
// RVA: 0xA48D10
void __fastcall CAkAudioMgr::Perform(CAkAudioMgr *this)
{
  int i; // esi
  __int64 j; // rbx
  unsigned int m_uBufferTick; // ebx

  EnterCriticalSection(&g_csMain.m_csLock);
  for ( i = CAkLEngine::GetNumBufferNeededAndSubmit(); ; --i )
  {
    CAkAudioMgr::ProcessMsgQueue(this);
    CAkAudioMgr::ProcessPendingList(this);
    if ( CAkLEngineCmds::m_bProcessPlayCmdsNeeded )
      CAkLEngineCmds::ProcessPlayCommands();
    if ( !i )
      break;
    for ( j = g_aBehavioralExtensions.m_uLength - 1; j >= 0; g_aBehavioralExtensions.m_pItems[j--](0) )
      ;
    m_uBufferTick = this->m_uBufferTick;
    CAkTransitionManager::ProcessTransitionsList(g_pTransitionManager, m_uBufferTick + 1);
    CAkPathManager::ProcessPathsList(g_pPathManager, m_uBufferTick + 1);
    CAkListener::OnBeginFrame();
    CAkURenderer::ProcessLimiters();
    CAkLEngine::Perform();
    CAkURenderer::PerformContextNotif();
    ++this->m_uBufferTick;
  }
  if ( CAkFeedbackDeviceMgr::s_pSingleton )
    CAkFeedbackDeviceMgr::CommandTick(CAkFeedbackDeviceMgr::s_pSingleton);
  LeaveCriticalSection(&g_csMain.m_csLock);
}

// File Line: 436
// RVA: 0xA49040
__int64 __fastcall CAkAudioMgr::ProcessMsgQueue(CAkAudioMgr *this)
{
  char v2; // di
  AkSparseChunkRing *p_m_MsgQueue; // rcx
  unsigned int m_uWriteBlock; // eax
  unsigned int v5; // ebx
  char *v6; // rsi
  int v7; // eax
  CAkRegisteredObj *ObjAndAddref; // rax
  __int64 v9; // rbx
  CAkRegisteredObj *v10; // r15
  AkPendingAction *v11; // rax
  AkPendingAction *v12; // rdi
  AkPendingAction *v13; // rax
  unsigned int v14; // eax
  AkExternalSourceArray *pExternalSrcs; // rcx
  AkExternalSourceArray *v16; // r14
  int v17; // ecx
  int v18; // ebx
  AkExternalSourceArray *v19; // rcx
  int v20; // ecx
  unsigned int v21; // r12d
  int v22; // ebx
  unsigned int v23; // r14d
  CAkParameterNodeBase *v24; // rax
  CAkParameterNodeBase *v25; // rbx
  CAkIndexableVtbl *v26; // r8
  CAkRegisteredObj *v27; // r15
  CAkIndexable *PtrAndAddRef; // rax
  CAkFxCustom *v29; // rdi
  CAkFxCustom *v30; // rax
  CAkParameterNodeBase *v31; // rax
  CAkSound *v32; // rax
  int v33; // ecx
  int v34; // ebx
  CAkRegisteredObj *v35; // rdx
  CAkRegisteredObj *v36; // r14
  CAkAction *v37; // rbx
  CAkParameterNodeBase *v38; // rax
  CAkParameterNodeBase *v39; // rdi
  int v40; // ecx
  int v41; // ecx
  int v42; // ecx
  __int64 v43; // rbx
  CAkParameterNodeBase *NodePtrAndAddRef; // rdi
  char v45; // al
  char v46; // cl
  char v47; // cl
  CAkIndexableVtbl *v48; // rax
  int v49; // ecx
  int v50; // ebx
  unsigned __int64 v51; // rdx
  TransParams *p_in_transParams; // rax
  CAkRegisteredObj *v53; // rdi
  unsigned int v54; // edx
  float v55; // xmm2_4
  int v56; // eax
  bool v57; // zf
  int v58; // eax
  unsigned __int64 v60; // rdx
  CAkRegisteredObj *v61; // rax
  int v62; // edx
  CAkRegisteredObj *v63; // rax
  unsigned __int64 v64; // rdx
  CAkRegisteredObj *v65; // rax
  unsigned __int64 v66; // rdx
  unsigned int v67; // ecx
  unsigned __int64 *p_uDeviceID; // rax
  AkDevice *v69; // rcx
  CAkBusVolumes *pFinalMix; // rcx
  AkSpeakerVolumes *v71; // r8
  unsigned __int64 v72; // rdx
  TransParams *v73; // r9
  CAkRegisteredObj *v74; // rax
  TransParams *v75; // r9
  unsigned __int64 v76; // rdx
  CAkRegisteredObj *v77; // rax
  unsigned __int64 v78; // rbx
  CAkActionStop *v79; // rax
  CAkActionStop *v80; // r14
  CAkRegisteredObj *v81; // rax
  CAkRegisteredObj *v82; // rdi
  int v83; // ecx
  int v84; // ebx
  CAkActionStop *v85; // rcx
  CAkIndexableVtbl *vfptr; // rax
  unsigned int v87; // eax
  unsigned int v88; // eax
  unsigned int v89; // eax
  CAkBus *PrimaryMasterBusAndAddRef; // rax
  CAkBus *v91; // rbx
  CAkBus *SecondaryMasterBusAndAddRef; // rax
  CAkBus *v93; // rbx
  CAkUsageSlot *v94; // rbx
  AkSinkType v95; // ebx
  CAkFeedbackDeviceMgr *v96; // rax
  unsigned int v97; // ecx
  unsigned __int64 *v98; // rax
  CAkSink *pSink; // rcx
  CAkFeedbackDeviceMgr *v100; // r11
  __int64 v101; // rcx
  __int64 v102; // r10
  float v103; // xmm0_4
  unsigned __int8 v104; // r8
  unsigned __int8 v105; // bl
  CAkKeyArray<unsigned long,CAkFeedbackDeviceMgr::DeviceBus,1> *v106; // rdi
  IAkMotionMixBus *m_pFinalBus; // rcx
  CAkParameterNodeBase *v108; // rax
  CAkParameterNodeBase *v109; // rbx
  unsigned int v110; // eax
  const wchar_t *v111; // rcx
  AkPendingAction v112; // [rsp+50h] [rbp-B0h] BYREF
  float v113; // [rsp+A0h] [rbp-60h]
  TransParams v114; // [rsp+A8h] [rbp-58h] BYREF
  AkOutputSettings out_settings; // [rsp+B0h] [rbp-50h] BYREF
  TransParams v116; // [rsp+B8h] [rbp-48h] BYREF
  char *v117; // [rsp+C0h] [rbp-40h]
  TransParams v118; // [rsp+C8h] [rbp-38h] BYREF
  TransParams in_transParams; // [rsp+D0h] [rbp-30h] BYREF
  char v120; // [rsp+1D0h] [rbp+D0h]
  unsigned int v121; // [rsp+1D8h] [rbp+D8h]
  unsigned int v122; // [rsp+1E0h] [rbp+E0h]
  unsigned int out_uSizeAvail; // [rsp+1E8h] [rbp+E8h] BYREF

  if ( this->m_bDrainMsgQueue || this->m_ulWriterFlag != this->m_ulReaderFlag )
  {
    v2 = 0;
    v120 = 0;
    EnterCriticalSection(&this->m_queueLock.m_csLock);
    p_m_MsgQueue = &this->m_MsgQueue;
    while ( 1 )
    {
      m_uWriteBlock = p_m_MsgQueue->m_uWriteBlock;
      v5 = 0;
      out_uSizeAvail = 0;
      v121 = 0;
      if ( p_m_MsgQueue->m_uReadBlock == m_uWriteBlock
        && p_m_MsgQueue->m_uReadOffset == p_m_MsgQueue->m_uWriteOffset
        && !p_m_MsgQueue->m_bBufferFull )
      {
LABEL_90:
        this->m_bDrainMsgQueue = 0;
        LeaveCriticalSection(&this->m_queueLock.m_csLock);
        SetEvent(this->m_hEventMgrThreadDrainEvent.m_Event);
        return 1i64;
      }
      v6 = AkSparseChunkRing::BeginReadEx(p_m_MsgQueue, &out_uSizeAvail);
      LeaveCriticalSection(&this->m_queueLock.m_csLock);
      do
      {
        v7 = *((unsigned __int16 *)v6 + 1);
        v117 = v6;
        switch ( v7 )
        {
          case 0:
            if ( ++this->m_ulReaderFlag != this->m_ulWriterFlag || this->m_bDrainMsgQueue )
            {
              v2 = 0;
              v120 = 0;
            }
            else
            {
              v2 = 1;
              v120 = 1;
            }
            goto LABEL_87;
          case 1:
            ObjAndAddref = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, *((_QWORD *)v6 + 1));
            v9 = *(_QWORD *)(*((_QWORD *)v6 + 6) + 24i64);
            v10 = ObjAndAddref;
            if ( !v9 )
              goto LABEL_28;
            while ( 1 )
            {
              if ( (*(_BYTE *)(v9 + 52) & 1) != 0 )
              {
                if ( v10 )
                {
                  v11 = (AkPendingAction *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
                  v12 = v11;
                  if ( v11 )
                  {
                    v11->vfptr = (ITransitionableVtbl *)&AkPendingAction::`vftable;
                    v11->UserParam.m_PlayingID = 0;
                    v11->UserParam.m_CustomParam.customParam = 0i64;
                    v11->UserParam.m_CustomParam.ui32Reserved = 0;
                    v11->UserParam.m_CustomParam.pExternalSrcs = 0i64;
                    v11->TargetPlayingID = 0;
                    v11->pGameObj = v10;
                    *((_DWORD *)v10 + 30) ^= (*((_DWORD *)v10 + 30) ^ (*((_DWORD *)v10 + 30) + 1)) & 0x3FFFFFFF;
                    goto LABEL_20;
                  }
                }
              }
              else
              {
                v13 = (AkPendingAction *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
                v12 = v13;
                if ( v13 )
                {
                  v13->vfptr = (ITransitionableVtbl *)&AkPendingAction::`vftable;
                  v13->UserParam.m_PlayingID = 0;
                  v13->UserParam.m_CustomParam.customParam = 0i64;
                  v13->UserParam.m_CustomParam.ui32Reserved = 0;
                  v13->UserParam.m_CustomParam.pExternalSrcs = 0i64;
                  v13->TargetPlayingID = 0;
                  v13->pGameObj = 0i64;
LABEL_20:
                  if ( v12 )
                  {
                    v14 = *((_DWORD *)v6 + 5);
                    v12->pAction = (CAkAction *)v9;
                    v12->TargetPlayingID = v14;
                    pExternalSrcs = v12->UserParam.m_CustomParam.pExternalSrcs;
                    v12->UserParam.m_PlayingID = *((_DWORD *)v6 + 4);
                    v12->UserParam.m_CustomParam.customParam = *((_QWORD *)v6 + 3);
                    v12->UserParam.m_CustomParam.ui32Reserved = *((_DWORD *)v6 + 8);
                    v16 = (AkExternalSourceArray *)*((_QWORD *)v6 + 5);
                    if ( pExternalSrcs )
                      AkExternalSourceArray::Release(pExternalSrcs);
                    if ( v16 )
                      ++v16->m_cRefCount;
                    v12->UserParam.m_CustomParam.pExternalSrcs = v16;
                    CAkAudioMgr::EnqueueOrExecuteAction(this, v12);
                  }
                }
              }
              v9 = *(_QWORD *)(v9 + 24);
              if ( !v9 )
              {
                v2 = v120;
LABEL_28:
                if ( v10 )
                {
                  v17 = *((_DWORD *)v10 + 30) ^ (*((_DWORD *)v10 + 30) ^ (*((_DWORD *)v10 + 30) - 1)) & 0x3FFFFFFF;
                  *((_DWORD *)v10 + 30) = v17;
                  if ( (v17 & 0x3FFFFFFF) == 0 )
                  {
                    v18 = g_DefaultPoolId;
                    CAkRegisteredObj::~CAkRegisteredObj(v10);
                    AK::MemoryMgr::Free(v18, v10);
                  }
                }
                CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, *((_DWORD *)v6 + 4));
                (*(void (__fastcall **)(_QWORD))(**((_QWORD **)v6 + 6) + 16i64))(*((_QWORD *)v6 + 6));
                v19 = (AkExternalSourceArray *)*((_QWORD *)v6 + 5);
                if ( v19 )
                {
                  AkExternalSourceArray::Release(v19);
                  goto LABEL_86;
                }
                goto LABEL_197;
              }
            }
          case 2:
            v51 = *((_QWORD *)v6 + 2);
            if ( v51 == -1i64 )
            {
              in_transParams.TransitionTime = 0;
              p_in_transParams = &in_transParams;
              goto LABEL_79;
            }
            v53 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, v51);
            if ( !v53 )
              goto LABEL_198;
            v54 = *((_DWORD *)v6 + 2);
            v55 = *((float *)v6 + 3);
            v114.TransitionTime = 0;
            CAkRTPCMgr::SetRTPCInternal(g_pRTPCMgr, v54, v55, v53, &v114, AkValueMeaning_Independent);
            v56 = *((_DWORD *)v53 + 30) ^ (*((_DWORD *)v53 + 30) ^ (*((_DWORD *)v53 + 30) - 1)) & 0x3FFFFFFF;
            *((_DWORD *)v53 + 30) = v56;
            v57 = (v56 & 0x3FFFFFFF) == 0;
            goto LABEL_82;
          case 3:
            v60 = *((_QWORD *)v6 + 2);
            if ( v60 == -1i64 )
            {
              p_in_transParams = (TransParams *)(v6 + 24);
LABEL_79:
              CAkRTPCMgr::SetRTPCInternal(
                g_pRTPCMgr,
                *((_DWORD *)v6 + 2),
                *((float *)v6 + 3),
                0i64,
                p_in_transParams,
                AkValueMeaning_Independent);
              goto LABEL_87;
            }
            v61 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, v60);
            v53 = v61;
            if ( !v61 )
              goto LABEL_198;
            CAkRTPCMgr::SetRTPCInternal(
              g_pRTPCMgr,
              *((_DWORD *)v6 + 2),
              *((float *)v6 + 3),
              v61,
              (TransParams *)v6 + 3,
              AkValueMeaning_Independent);
            goto LABEL_96;
          case 5:
            v72 = *((_QWORD *)v6 + 2);
            if ( v72 == -1i64 )
            {
              v116.TransitionTime = 0;
              v73 = &v116;
              goto LABEL_131;
            }
            v74 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, v72);
            v53 = v74;
            if ( !v74 )
              goto LABEL_198;
            v118.TransitionTime = 0;
            v75 = &v118;
            goto LABEL_134;
          case 6:
            v76 = *((_QWORD *)v6 + 2);
            if ( v76 == -1i64 )
            {
              v73 = (TransParams *)(v6 + 24);
LABEL_131:
              CAkRTPCMgr::ResetRTPCValue(g_pRTPCMgr, *((_DWORD *)v6 + 2), 0i64, v73);
              goto LABEL_87;
            }
            v74 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, v76);
            v53 = v74;
            if ( !v74 )
              goto LABEL_198;
            v75 = (TransParams *)(v6 + 24);
LABEL_134:
            CAkRTPCMgr::ResetRTPCValue(g_pRTPCMgr, *((_DWORD *)v6 + 2), v74, v75);
            goto LABEL_96;
          case 7:
            CAkStateMgr::SetStateInternal(g_pStateMgr, *((_DWORD *)v6 + 2), *((_DWORD *)v6 + 3), v6[16], v6[17]);
            goto LABEL_87;
          case 8:
            v63 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, *((_QWORD *)v6 + 1));
            v53 = v63;
            if ( !v63 )
              goto LABEL_198;
            CAkRTPCMgr::SetSwitchInternal(g_pRTPCMgr, *((_DWORD *)v6 + 4), *((_DWORD *)v6 + 5), v63);
            goto LABEL_96;
          case 10:
            v64 = *((_QWORD *)v6 + 1);
            if ( v64 == -1i64 )
            {
              CAkStateMgr::Trigger(g_pStateMgr, *((_DWORD *)v6 + 4), 0i64);
              goto LABEL_87;
            }
            v65 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, v64);
            v53 = v65;
            if ( v65 )
            {
              CAkStateMgr::Trigger(g_pStateMgr, *((_DWORD *)v6 + 4), v65);
LABEL_96:
              v62 = *((_DWORD *)v53 + 30) ^ (*((_DWORD *)v53 + 30) ^ (*((_DWORD *)v53 + 30) - 1)) & 0x3FFFFFFF;
              *((_DWORD *)v53 + 30) = v62;
              v57 = (v62 & 0x3FFFFFFF) == 0;
LABEL_82:
              if ( v57 )
              {
                v34 = g_DefaultPoolId;
                CAkRegisteredObj::~CAkRegisteredObj(v53);
                v35 = v53;
                goto LABEL_84;
              }
            }
            goto LABEL_198;
          case 11:
            CAkRegistryMgr::RegisterObject(g_pRegistryMgr, *((_QWORD *)v6 + 1), *((_DWORD *)v6 + 4), *((void **)v6 + 3));
            goto LABEL_87;
          case 12:
            v66 = *((_QWORD *)v6 + 1);
            if ( v66 == -1i64 )
              CAkRegistryMgr::UnregisterAll(g_pRegistryMgr);
            else
              CAkRegistryMgr::UnregisterObject(g_pRegistryMgr, v66);
            goto LABEL_87;
          case 13:
            CAkRegistryMgr::SetPosition(
              g_pRegistryMgr,
              *((_QWORD *)v6 + 1),
              (AkSoundPosition *)(v6 + 16),
              1u,
              MultiPositionType_SingleSource);
            goto LABEL_87;
          case 14:
            CAkRegistryMgr::SetActiveListeners(g_pRegistryMgr, *((_QWORD *)v6 + 1), *((_DWORD *)v6 + 4));
            goto LABEL_87;
          case 16:
            CAkListener::SetListenerPosition(*((_DWORD *)v6 + 2), (AkListenerPosition *)(v6 + 12));
            goto LABEL_87;
          case 17:
            v71 = (AkSpeakerVolumes *)(v6 + 12);
            if ( !v6[45] )
              v71 = 0i64;
            CAkListener::SetListenerSpatialization(*((_DWORD *)v6 + 2), v6[44], v71);
            goto LABEL_87;
          case 18:
            CAkRegistryMgr::SetGameObjectAuxSendValues(
              g_pRegistryMgr,
              *((_QWORD *)v6 + 1),
              (AkAuxSendValue *)(v6 + 20),
              *((_DWORD *)v6 + 4));
            goto LABEL_87;
          case 19:
            CAkRegistryMgr::SetGameObjectOutputBusVolume(g_pRegistryMgr, *((_QWORD *)v6 + 1), *((float *)v6 + 4));
            goto LABEL_87;
          case 20:
            CAkRegistryMgr::SetObjectObstructionAndOcclusion(
              g_pRegistryMgr,
              *((_QWORD *)v6 + 1),
              *((_DWORD *)v6 + 4),
              *((float *)v6 + 5),
              *((float *)v6 + 6));
            goto LABEL_87;
          case 21:
            v67 = 0;
            if ( !CAkOutputMgr::m_Devices.m_uLength )
              goto LABEL_87;
            p_uDeviceID = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
            while ( *p_uDeviceID != (*((int *)v6 + 2) | ((unsigned __int64)*((unsigned int *)v6 + 3) << 32)) )
            {
              ++v67;
              p_uDeviceID += 10;
              if ( v67 >= CAkOutputMgr::m_Devices.m_uLength )
                goto LABEL_87;
            }
            v69 = &CAkOutputMgr::m_Devices.m_pItems[v67];
            if ( v69 )
            {
              pFinalMix = v69->pFinalMix;
              v122 = *((_DWORD *)v6 + 4);
              LODWORD(v113) = (v122 & 0x7FFFFF) + 1065353216;
              CAkBusVolumes::SetNextVolume(
                pFinalMix,
                (float)((float)((float)((float)((float)((float)((float)((float)(v113 - 1.0) / (float)(v113 + 1.0))
                                                              * (float)((float)(v113 - 1.0) / (float)(v113 + 1.0)))
                                                      * 0.33333334)
                                              + 1.0)
                                      * (float)((float)((float)(v113 - 1.0) / (float)(v113 + 1.0)) * 2.0))
                              + (float)((float)((float)(unsigned __int8)(v122 >> 23) - 127.0) * 0.69314718))
                      * 0.43429449)
              * 20.0);
            }
            goto LABEL_87;
          case 22:
            v77 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, *((_QWORD *)v6 + 1));
            v53 = v77;
            if ( !v77 )
              goto LABEL_198;
            CAkDynamicSequence::SetGameObject(*((CAkDynamicSequence **)v6 + 6), v77);
            goto LABEL_96;
          case 23:
            switch ( *((_DWORD *)v6 + 4) )
            {
              case 0:
                CAkDynamicSequence::Play(
                  *((CAkDynamicSequence **)v6 + 1),
                  *((_DWORD *)v6 + 5),
                  *((AkCurveInterpolation *)v6 + 6));
                (*(void (__fastcall **)(_QWORD))(**((_QWORD **)v6 + 1) + 16i64))(*((_QWORD *)v6 + 1));
                break;
              case 1:
                CAkDynamicSequence::Pause(
                  *((CAkDynamicSequence **)v6 + 1),
                  *((_DWORD *)v6 + 5),
                  *((AkCurveInterpolation *)v6 + 6));
                (*(void (__fastcall **)(_QWORD))(**((_QWORD **)v6 + 1) + 16i64))(*((_QWORD *)v6 + 1));
                break;
              case 2:
                CAkDynamicSequence::Resume(
                  *((CAkDynamicSequence **)v6 + 1),
                  *((_DWORD *)v6 + 5),
                  *((AkCurveInterpolation *)v6 + 6));
                (*(void (__fastcall **)(_QWORD))(**((_QWORD **)v6 + 1) + 16i64))(*((_QWORD *)v6 + 1));
                break;
              case 3:
                *(_BYTE *)(*((_QWORD *)v6 + 1) + 128i64) = 1;
                CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, *(_DWORD *)(*((_QWORD *)v6 + 1) + 120i64));
                (*(void (__fastcall **)(_QWORD))(**((_QWORD **)v6 + 1) + 16i64))(*((_QWORD *)v6 + 1));
                goto LABEL_149;
              case 4:
                CAkDynamicSequence::Stop(
                  *((CAkDynamicSequence **)v6 + 1),
                  *((_DWORD *)v6 + 5),
                  *((AkCurveInterpolation *)v6 + 6));
                (*(void (__fastcall **)(_QWORD))(**((_QWORD **)v6 + 1) + 16i64))(*((_QWORD *)v6 + 1));
                break;
              case 5:
                CAkDynamicSequence::Break(*((CAkDynamicSequence **)v6 + 1));
                (*(void (__fastcall **)(_QWORD))(**((_QWORD **)v6 + 1) + 16i64))(*((_QWORD *)v6 + 1));
                break;
              case 6:
                CAkDynamicSequence::ResumeWaiting(*((CAkDynamicSequence **)v6 + 1));
                (*(void (__fastcall **)(_QWORD))(**((_QWORD **)v6 + 1) + 16i64))(*((_QWORD *)v6 + 1));
                break;
              default:
                goto LABEL_149;
            }
            goto LABEL_87;
          case 24:
            v94 = (CAkUsageSlot *)*((_QWORD *)v6 + 1);
            CAkURenderer::StopAllPBIs(v94);
            CAkUsageSlot::Release(v94, 0);
            goto LABEL_86;
          case 25:
            v78 = *((_QWORD *)v6 + 1);
            v79 = CAkActionStop::Create((AkActionType)((v78 != -1i64) + 260), 0);
            v80 = v79;
            if ( !v79 )
              goto LABEL_197;
            if ( v78 == -1i64 )
            {
              v85 = v79;
              v112.vfptr = (ITransitionableVtbl *)&AkPendingAction::`vftable;
              vfptr = v79->vfptr;
              v112.UserParam.m_PlayingID = 0;
              v112.UserParam.m_CustomParam.customParam = 0i64;
              v112.UserParam.m_CustomParam.ui32Reserved = 0;
              v112.UserParam.m_CustomParam.pExternalSrcs = 0i64;
              v112.TargetPlayingID = 0;
              v112.pGameObj = 0i64;
              vfptr[2].__vecDelDtor(v85, (unsigned int)&v112);
              AkPendingAction::~AkPendingAction(&v112);
              v80->vfptr->Release(v80);
            }
            else
            {
              v81 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, v78);
              v82 = v81;
              if ( v81 )
              {
                v112.UserParam.m_PlayingID = 0;
                v112.UserParam.m_CustomParam.customParam = 0i64;
                v112.UserParam.m_CustomParam.ui32Reserved = 0;
                v112.UserParam.m_CustomParam.pExternalSrcs = 0i64;
                v112.TargetPlayingID = 0;
                v112.pGameObj = v81;
                v112.vfptr = (ITransitionableVtbl *)&AkPendingAction::`vftable;
                *((_DWORD *)v81 + 30) ^= (*((_DWORD *)v81 + 30) ^ (*((_DWORD *)v81 + 30) + 1)) & 0x3FFFFFFF;
                v80->vfptr[2].__vecDelDtor(v80, (unsigned int)&v112);
                v83 = *((_DWORD *)v82 + 30) ^ (*((_DWORD *)v82 + 30) ^ (*((_DWORD *)v82 + 30) - 1)) & 0x3FFFFFFF;
                *((_DWORD *)v82 + 30) = v83;
                if ( (v83 & 0x3FFFFFFF) == 0 )
                {
                  v84 = g_DefaultPoolId;
                  CAkRegisteredObj::~CAkRegisteredObj(v82);
                  AK::MemoryMgr::Free(v84, v82);
                }
                AkPendingAction::~AkPendingAction(&v112);
              }
              v2 = v120;
              v80->vfptr->Release(v80);
            }
            goto LABEL_86;
          case 26:
            CAkListener::SetListenerPipeline(*((_DWORD *)v6 + 2), v6[12], v6[13]);
            goto LABEL_87;
          case 27:
            v95 = *((_DWORD *)v6 + 6);
            if ( v95 == 406 )
            {
              if ( v6[32] )
              {
                v96 = CAkFeedbackDeviceMgr::Create();
                CAkFeedbackDeviceMgr::AddPlayerFeedbackDevice(v96, v6[28], 0, 0x196u, *((void **)v6 + 2));
              }
              else if ( CAkFeedbackDeviceMgr::s_pSingleton )
              {
                CAkFeedbackDeviceMgr::RemovePlayerFeedbackDevice(CAkFeedbackDeviceMgr::s_pSingleton, v6[28], 0, 0x196u);
              }
            }
            else if ( v6[32] )
            {
              CAkLEngine::GetDefaultOutputSettings(v95, &out_settings);
              if ( CAkOutputMgr::AddOutputDevice(
                     &out_settings,
                     v95,
                     *((_DWORD *)v6 + 7),
                     *((_DWORD *)v6 + 2),
                     *((void **)v6 + 2)) != AK_Success )
                goto LABEL_197;
              v97 = 0;
              if ( !CAkOutputMgr::m_Devices.m_uLength )
              {
LABEL_174:
                (*(void (__fastcall **)(_QWORD))(*MEMORY[8] + 8i64))(MEMORY[8]);
                goto LABEL_86;
              }
              v98 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
              while ( *v98 != ((int)v95 | ((unsigned __int64)*((unsigned int *)v6 + 7) << 32)) )
              {
                ++v97;
                v98 += 10;
                if ( v97 >= CAkOutputMgr::m_Devices.m_uLength )
                  goto LABEL_174;
              }
              pSink = CAkOutputMgr::m_Devices.m_pItems[v97].pSink;
              (*(void (__fastcall **)(CAkSink *))pSink->vfptr->gap8)(pSink);
            }
            else
            {
              CAkOutputMgr::RemoveOutputDevice(*((_QWORD *)v6 + 3));
            }
LABEL_86:
            v5 = v121;
            goto LABEL_87;
          case 28:
            v100 = CAkFeedbackDeviceMgr::s_pSingleton;
            if ( CAkFeedbackDeviceMgr::s_pSingleton )
            {
              v101 = (unsigned __int8)v6[8];
              v102 = (unsigned __int8)v6[9];
              CAkFeedbackDeviceMgr::s_pSingleton->m_aListenerToPlayer[(unsigned __int8)CAkFeedbackDeviceMgr::s_pSingleton->m_aPlayerToListener[v101]] &= ~(1 << v101);
              v100->m_aPlayerToListener[v101] = v102;
              v100->m_aListenerToPlayer[v102] |= 1 << v101;
            }
            goto LABEL_87;
          case 29:
            if ( !CAkFeedbackDeviceMgr::s_pSingleton )
              goto LABEL_87;
            v103 = *((float *)v6 + 2);
            v104 = v6[12];
            if ( v103 <= 0.0 )
            {
              if ( (float)(v103 * 0.050000001) >= -37.0 && (`AkMath::FastPow10::`4::`local static guard & 1) == 0 )
              {
                `AkMath::FastPow10::`4::`local static guard |= 1u;
                `AkMath::FastPow10::`4::SCALE = 1272224376;
              }
            }
            else if ( (float)(v103 * -0.050000001) >= -37.0 && (`AkMath::FastPow10::`4::`local static guard & 1) == 0 )
            {
              `AkMath::FastPow10::`4::`local static guard |= 1u;
              `AkMath::FastPow10::`4::SCALE = 1272224376;
            }
            v105 = 0;
            v106 = &CAkFeedbackDeviceMgr::s_pSingleton->m_aPlayers[v104];
            if ( v106->m_uLength )
            {
              do
              {
                m_pFinalBus = v106->m_pItems[v105].item.m_pFinalBus;
                m_pFinalBus->vfptr[2].SupportMediaRelocation(m_pFinalBus);
                ++v105;
              }
              while ( v105 < v106->m_uLength );
            }
            goto LABEL_85;
          case 30:
            CAkAudioMgr::ClearPendingItems(this, *((_DWORD *)v6 + 2));
            v87 = *((_DWORD *)v6 + 4);
            *((_WORD *)&v112.PausedTick + 2) = 0;
            v112.PausedTick = v87;
            v88 = *((_DWORD *)v6 + 2);
            *((_BYTE *)&v112.PausedTick + 6) = 0;
            v112.LaunchTick = v88;
            v89 = *((_DWORD *)v6 + 3);
            LODWORD(v112.vfptr) = 0;
            v112.LaunchFrameOffset = v89;
            v112.pAction = 0i64;
            PrimaryMasterBusAndAddRef = CAkBus::GetPrimaryMasterBusAndAddRef();
            v91 = PrimaryMasterBusAndAddRef;
            if ( PrimaryMasterBusAndAddRef )
            {
              PrimaryMasterBusAndAddRef->vfptr[4].__vecDelDtor(PrimaryMasterBusAndAddRef, (unsigned int)&v112);
              v91->vfptr->Release(v91);
            }
            SecondaryMasterBusAndAddRef = CAkBus::GetSecondaryMasterBusAndAddRef();
            v93 = SecondaryMasterBusAndAddRef;
            if ( !SecondaryMasterBusAndAddRef )
              goto LABEL_197;
            SecondaryMasterBusAndAddRef->vfptr[4].__vecDelDtor(SecondaryMasterBusAndAddRef, (unsigned int)&v112);
            v93->vfptr->Release(v93);
            goto LABEL_86;
          case 31:
            v36 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, *((_QWORD *)v6 + 2));
            if ( !v36 && *((_QWORD *)v6 + 2) != -1i64 )
              goto LABEL_149;
            v37 = *(CAkAction **)(*((_QWORD *)v6 + 1) + 24i64);
            if ( !v37 )
              goto LABEL_72;
            break;
          case 32:
            CAkRegistryMgr::SetGameObjectScalingFactor(g_pRegistryMgr, *((_QWORD *)v6 + 1), *((float *)v6 + 4));
            goto LABEL_87;
          case 33:
            CAkRegistryMgr::SetPosition(
              g_pRegistryMgr,
              *((_QWORD *)v6 + 1),
              (AkSoundPosition *)v6 + 1,
              *((_WORD *)v6 + 8),
              *((AK::SoundEngine::MultiPositionType *)v6 + 5));
            goto LABEL_87;
          case 34:
            CAkListener::SetScalingFactor(*((_DWORD *)v6 + 2), *((float *)v6 + 3));
            goto LABEL_87;
          case 35:
            v36 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, *((_QWORD *)v6 + 2));
            if ( !v36 && *((_QWORD *)v6 + 2) != -1i64 )
              goto LABEL_149;
            v43 = *(_QWORD *)(*((_QWORD *)v6 + 1) + 24i64);
            if ( !v43 )
              goto LABEL_72;
            do
            {
              if ( *(_WORD *)(v43 + 52) == 1027 )
              {
                NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(
                                     g_pIndex,
                                     *(_DWORD *)(v43 + 48),
                                     AkNodeType_Default);
                if ( NodePtrAndAddRef )
                {
                  v45 = v6[28] & 1;
                  v46 = v6[29] & 1;
                  *((_WORD *)&v112.PausedTick + 2) = 0;
                  *((_BYTE *)&v112.PausedTick + 6) = 0;
                  v112.PausedTick = 4;
                  v112.pAction = (CAkAction *)v36;
                  *(_QWORD *)&v112.LaunchTick = 0i64;
                  LODWORD(v112.vfptr) = 4;
                  v47 = *(_BYTE *)(&v112.UserParam.m_CustomParam.ui32Reserved + 1) & 0xFC | v45 | (2 * v46);
                  v112.UserParam.m_CustomParam.ui32Reserved = *((_DWORD *)v6 + 6);
                  v48 = NodePtrAndAddRef->vfptr;
                  *((_BYTE *)&v112.UserParam.m_CustomParam.ui32Reserved + 4) = v47;
                  v48[4].__vecDelDtor(NodePtrAndAddRef, (unsigned int)&v112);
                  NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef);
                }
              }
              v43 = *(_QWORD *)(v43 + 24);
            }
            while ( v43 );
            goto LABEL_71;
          case 36:
            v20 = *((_DWORD *)v6 + 14);
            v21 = *((_DWORD *)v6 + 4);
            v22 = 16 * (*((_DWORD *)v6 + 13) + (*((_DWORD *)v6 + 12) << 12));
            v23 = (v22 + 2) | 0x80000000;
            if ( v20 )
            {
              if ( v20 != 1 )
                goto LABEL_86;
              v24 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v23, AkNodeType_Default);
              v25 = v24;
              if ( v24 )
              {
                v26 = v24->vfptr;
                v112.LaunchTick = *((_DWORD *)v6 + 4);
                *((_WORD *)&v112.PausedTick + 2) = 0;
                *((_BYTE *)&v112.PausedTick + 6) = 0;
                v112.PausedTick = 4;
                v112.pAction = 0i64;
                v112.LaunchFrameOffset = 0;
                LODWORD(v112.vfptr) = 0;
                v26[4].__vecDelDtor(v24, (unsigned int)&v112);
                v25->vfptr->Release(v25);
                goto LABEL_86;
              }
            }
            else
            {
              v27 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, *((_QWORD *)v6 + 1));
              if ( v27 )
              {
                PtrAndAddRef = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                 (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxFxCustom,
                                 v23);
                v29 = (CAkFxCustom *)PtrAndAddRef;
                if ( PtrAndAddRef )
                {
                  PtrAndAddRef->vfptr->Release(PtrAndAddRef);
                }
                else
                {
                  v30 = CAkFxCustom::Create(v23);
                  v29 = v30;
                  if ( v30 )
                    CAkFxBase::SetFX(v30, v22 + 2, 0i64);
                }
                v31 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v23, AkNodeType_Default);
                if ( v31 || !v29 )
                {
                  v31->vfptr->Release(v31);
                }
                else
                {
                  v32 = CAkSound::Create(v23);
                  if ( v32 )
                    CAkSource::SetSource(&v32->m_Source, v29->key);
                }
                v112.PausedTick = v21;
                v112.vfptr = 0i64;
                LODWORD(v112.pAction) = 0;
                *(_QWORD *)&v112.LaunchTick = 0i64;
                CAkAudioMgr::PlaySourceInput(this, v23, v27, (UserParams *)&v112);
                v33 = *((_DWORD *)v27 + 30) ^ (*((_DWORD *)v27 + 30) ^ (*((_DWORD *)v27 + 30) - 1)) & 0x3FFFFFFF;
                *((_DWORD *)v27 + 30) = v33;
                if ( (v33 & 0x3FFFFFFF) == 0 )
                {
                  v34 = g_DefaultPoolId;
                  CAkRegisteredObj::~CAkRegisteredObj(v27);
                  v35 = v27;
LABEL_84:
                  AK::MemoryMgr::Free(v34, v35);
LABEL_85:
                  v2 = v120;
                  goto LABEL_86;
                }
              }
            }
LABEL_197:
            v5 = v121;
LABEL_198:
            v2 = v120;
            goto LABEL_87;
          case 37:
            if ( g_pAkSink )
            {
              v111 = (const wchar_t *)*((_QWORD *)v6 + 1);
              if ( v111 )
              {
                CAkOutputMgr::StartOutputCapture(v111);
                if ( v6[16] && CAkFeedbackDeviceMgr::s_pSingleton )
                  CAkFeedbackDeviceMgr::StartOutputCapture(
                    CAkFeedbackDeviceMgr::s_pSingleton,
                    *((const wchar_t **)v6 + 1));
                AK::MemoryMgr::Free(g_DefaultPoolId, *((void **)v6 + 1));
              }
              else
              {
                CAkOutputMgr::StopOutputCapture();
                if ( CAkFeedbackDeviceMgr::s_pSingleton )
                  CAkFeedbackDeviceMgr::StopOutputCapture(CAkFeedbackDeviceMgr::s_pSingleton);
              }
            }
            goto LABEL_87;
          case 38:
            v108 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, *((_DWORD *)v6 + 2), (AkNodeType)*((_DWORD *)v6 + 5));
            v109 = v108;
            if ( !v108 )
              goto LABEL_197;
            v110 = v108->vfptr[3].Release(v108);
            if ( v110 <= 9 || v110 == 12 )
              CAkParameterNodeBase::SetFX(v109, *((_DWORD *)v6 + 3), *((_DWORD *)v6 + 4), 1);
            v109->vfptr->Release(v109);
            goto LABEL_86;
          case 39:
            CAkLEngine::SetPanningRule(*((_DWORD *)v6 + 2), *((_DWORD *)v6 + 3), *((AkPanningRule *)v6 + 4));
            goto LABEL_87;
          default:
            goto LABEL_87;
        }
        do
        {
          if ( v37->m_eActionType == 1027 )
          {
            v38 = CAkAction::GetAndRefTarget(v37);
            v39 = v38;
            if ( v38 )
            {
              CAkAudioMgr::ProcessCustomAction(
                this,
                v38,
                v36,
                *((AK::SoundEngine::AkActionOnEventType *)v6 + 6),
                *((_DWORD *)v6 + 7),
                *((AkCurveInterpolation *)v6 + 8),
                *((_DWORD *)v6 + 9));
              v39->vfptr->Release(v39);
            }
          }
          else
          {
            v40 = *((_DWORD *)v6 + 6);
            if ( !v40 )
              goto LABEL_59;
            v41 = v40 - 1;
            if ( v41 )
            {
              v42 = v41 - 1;
              if ( v42 )
              {
                if ( v42 != 1 )
                  goto LABEL_60;
LABEL_59:
                CAkAudioMgr::StopAction(g_pAudioMgr, v37->key, *((_DWORD *)v6 + 9));
                goto LABEL_60;
              }
              CAkAudioMgr::ResumeAction(g_pAudioMgr, v37->key, *((_DWORD *)v6 + 9));
            }
            else
            {
              CAkAudioMgr::PauseAction(g_pAudioMgr, v37->key, *((_DWORD *)v6 + 9));
            }
          }
LABEL_60:
          v37 = v37->pNextLightItem;
        }
        while ( v37 );
LABEL_71:
        v2 = v120;
LABEL_72:
        if ( v36 )
        {
          v49 = *((_DWORD *)v36 + 30) ^ (*((_DWORD *)v36 + 30) ^ (*((_DWORD *)v36 + 30) - 1)) & 0x3FFFFFFF;
          *((_DWORD *)v36 + 30) = v49;
          if ( (v49 & 0x3FFFFFFF) == 0 )
          {
            v50 = g_DefaultPoolId;
            CAkRegisteredObj::~CAkRegisteredObj(v36);
            AK::MemoryMgr::Free(v50, v36);
          }
        }
        v5 = v121;
LABEL_149:
        (*(void (__fastcall **)(_QWORD))(**((_QWORD **)v6 + 1) + 16i64))(*((_QWORD *)v6 + 1));
LABEL_87:
        v6 += *(unsigned __int16 *)v6;
        v58 = *(unsigned __int16 *)v117;
        ++CAkLEngineCmds::m_ulPlayEventID;
        v5 += v58;
        v121 = v5;
      }
      while ( v5 < out_uSizeAvail && !v2 );
      EnterCriticalSection(&this->m_queueLock.m_csLock);
      AkSparseChunkRing::EndRead(&this->m_MsgQueue, v5);
      p_m_MsgQueue = &this->m_MsgQueue;
      if ( v2 )
        goto LABEL_90;
    }
  }
  return 1i64;
} *((_DWORD *)v36 + 30) ^ (*((_DWORD *)v36 + 30) ^ (*((_DWORD *)v36 + 30) - 1)) & 0x3FFFFFFF;
          *((_DWORD *)v36 + 30) = v49;
          if ( (v49 & 0x3FFFFFFF) == 0 )
          {
            v50 = g_DefaultPoolId;
            CAkRegisteredObj::~CAkRegisteredObj(v36);
            AK::MemoryMgr::Free(v50, v36);
          }
        }
        v5 = v121;
LABEL_149:
        (*(void (__fastcall **)(_QWORD))(**((_QWORD **)v6 + 1) + 16i64))(*((_QWORD *)v6 + 1));
LABEL_87:
        v6 += *(unsigned __int16 *)v6;
        v58 = *(unsigned __int16 *)v117;
        ++CAkLEngineCmds::m_ulPlayEventID;
        v5 += v58;
        v121 = v5;
      }
      while ( v5 < out_uSizeAvail && !v2 );
      EnterCriticalSection(&this->m_queueLock.m_csLock);
      AkSparseChunkRing::EndRead(&this->m_MsgQueue, v5);
      p_m_MsgQueue = &this->m_MsgQueue;
      if ( v2 )
        goto LABEL_90;
    }
  }
  return 1i64;

// File Line: 1391
// RVA: 0xA4A490
void __fastcall CAkAudioMgr::ProcessPendingList(CAkAudioMgr *this)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rcx
  AkPendingAction *item; // rsi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFree; // rax
  CAkActionPlayAndContinue *pAction; // rcx
  int m_eActionType; // eax
  unsigned int m_PlayingID; // edx
  int v8; // edi
  int v9[22]; // [rsp+40h] [rbp-58h] BYREF

  m_pFirst = this->m_mmapPending.m_pFirst;
  if ( m_pFirst )
  {
    while ( m_pFirst->Item.key <= this->m_uBufferTick )
    {
      item = m_pFirst->Item.item;
      if ( m_pFirst == this->m_mmapPending.m_pFirst )
        this->m_mmapPending.m_pFirst = m_pFirst->pNextListItem;
      else
        MEMORY[0] = (size_t)m_pFirst->pNextListItem;
      if ( m_pFirst == this->m_mmapPending.m_pLast )
        this->m_mmapPending.m_pLast = 0i64;
      m_pFree = this->m_mmapPending.m_pFree;
      v9[0] = 0;
      m_pFirst->pNextListItem = m_pFree;
      --this->m_mmapPending.m_ulNumListItems;
      this->m_mmapPending.m_pFree = m_pFirst;
      pAction = (CAkActionPlayAndContinue *)item->pAction;
      m_eActionType = pAction->m_eActionType;
      if ( m_eActionType == 1027 || m_eActionType == 1283 && CAkActionPlayAndContinue::NeedNotifyDelay(pAction) )
        ((void (__fastcall *)(CAkAction *, int *))item->pAction->vfptr[2].Category)(item->pAction, v9);
      item->pAction->vfptr[2].__vecDelDtor(item->pAction, (unsigned int)item);
      m_PlayingID = item->UserParam.m_PlayingID;
      if ( m_PlayingID )
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, m_PlayingID);
      item->pAction->vfptr->Release(item->pAction);
      v8 = g_DefaultPoolId;
      ((void (__fastcall *)(AkPendingAction *, _QWORD))item->vfptr[1].TransUpdateValue)(item, 0i64);
      AK::MemoryMgr::Free(v8, item);
      ++CAkLEngineCmds::m_ulPlayEventID;
      if ( !this->m_mmapPending.m_pFirst )
        break;
      m_pFirst = this->m_mmapPending.m_pFirst;
    }
  }
}

// File Line: 1428
// RVA: 0xA47FC0
void __fastcall CAkAudioMgr::EnqueueOrExecuteAction(CAkAudioMgr *this, AkPendingAction *in_pActionItem)
{
  unsigned int DelayTime; // eax
  __int64 v5; // r8
  unsigned int v6; // r9d
  unsigned int m_PlayingID; // edx
  int v8; // ebx
  unsigned int uContinuousPlaybackLookAhead; // eax
  AKRESULT v10; // eax
  CAkActionPlayAndContinue *pAction; // rcx
  int m_eActionType; // eax
  int v13; // ebx
  int v14[22]; // [rsp+20h] [rbp-58h] BYREF
  AkPendingAction *in_rItem; // [rsp+88h] [rbp+10h] BYREF

  in_rItem = in_pActionItem;
  CAkPlayingMgr::AddItemActiveCount(g_pPlayingMgr, in_pActionItem->UserParam.m_PlayingID);
  in_pActionItem->pAction->vfptr->AddRef(in_pActionItem->pAction);
  DelayTime = CAkAction::GetDelayTime(in_pActionItem->pAction);
  in_pActionItem->LaunchTick = this->m_uBufferTick;
  v5 = DelayTime >> 10;
  v6 = DelayTime;
  in_pActionItem->LaunchFrameOffset = DelayTime - (DelayTime >> 10 << 10);
  if ( (_DWORD)v5 )
  {
    if ( in_pActionItem->pAction->m_eActionType != 1283 )
      goto LABEL_10;
    uContinuousPlaybackLookAhead = g_settings.uContinuousPlaybackLookAhead;
    if ( (unsigned int)v5 < g_settings.uContinuousPlaybackLookAhead )
      uContinuousPlaybackLookAhead = v5;
    LODWORD(v5) = v5 - uContinuousPlaybackLookAhead;
    in_pActionItem->LaunchFrameOffset = v6 - ((_DWORD)v5 << 10);
    if ( (_DWORD)v5 )
    {
LABEL_10:
      in_pActionItem->LaunchTick += v5;
      v10 = CAkMultiKeyList<unsigned long,AkPendingAction *,2>::Insert(
              &this->m_mmapPending,
              in_pActionItem->LaunchTick,
              &in_rItem);
      pAction = (CAkActionPlayAndContinue *)in_pActionItem->pAction;
      if ( v10 == AK_Success )
      {
        v14[0] = 0;
        m_eActionType = pAction->m_eActionType;
        if ( m_eActionType == 1027 || m_eActionType == 1283 && CAkActionPlayAndContinue::NeedNotifyDelay(pAction) )
          ((void (__fastcall *)(CAkAction *, int *))in_pActionItem->pAction->vfptr[2].Category)(
            in_pActionItem->pAction,
            v14);
      }
      else
      {
        pAction->vfptr->Release(pAction);
        v13 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))in_pActionItem->vfptr[1].TransUpdateValue)(
          in_pActionItem,
          0i64);
        AK::MemoryMgr::Free(v13, in_pActionItem);
      }
    }
    else
    {
      CAkAudioMgr::ProcessAction(this, in_pActionItem);
    }
  }
  else
  {
    ((void (__fastcall *)(CAkAction *, AkPendingAction *, __int64, _QWORD))in_pActionItem->pAction->vfptr[2].__vecDelDtor)(
      in_pActionItem->pAction,
      in_pActionItem,
      v5,
      DelayTime);
    m_PlayingID = in_pActionItem->UserParam.m_PlayingID;
    if ( m_PlayingID )
      CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, m_PlayingID);
    in_pActionItem->pAction->vfptr->Release(in_pActionItem->pAction);
    v8 = g_DefaultPoolId;
    ((void (__fastcall *)(AkPendingAction *, _QWORD))in_pActionItem->vfptr[1].TransUpdateValue)(in_pActionItem, 0i64);
    AK::MemoryMgr::Free(v8, in_pActionItem);
  }
}

// File Line: 1495
// RVA: 0xA48F00
void __fastcall CAkAudioMgr::ProcessAction(CAkAudioMgr *this, AkPendingAction *in_pAction)
{
  unsigned int m_PlayingID; // edx
  int v4; // ebx

  ((void (__fastcall *)(CAkAction *))in_pAction->pAction->vfptr[2].__vecDelDtor)(in_pAction->pAction);
  m_PlayingID = in_pAction->UserParam.m_PlayingID;
  if ( m_PlayingID )
    CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, m_PlayingID);
  in_pAction->pAction->vfptr->Release(in_pAction->pAction);
  v4 = g_DefaultPoolId;
  ((void (__fastcall *)(AkPendingAction *, _QWORD))in_pAction->vfptr[1].TransUpdateValue)(in_pAction, 0i64);
  AK::MemoryMgr::Free(v4, in_pAction);
}

// File Line: 1527
// RVA: 0xA48F60
void __fastcall CAkAudioMgr::ProcessCustomAction(
        CAkAudioMgr *this,
        CAkParameterNodeBase *ptargetNode,
        CAkRegisteredObj *in_pGameObj,
        AK::SoundEngine::AkActionOnEventType in_ActionToExecute,
        int in_uTransitionDuration,
        AkCurveInterpolation in_eFadeCurve,
        int in_PlayingID)
{
  int v8; // r9d
  int v9; // r9d
  int v10; // [rsp+30h] [rbp-38h] BYREF
  CAkRegisteredObj *v11; // [rsp+38h] [rbp-30h]
  int v12; // [rsp+40h] [rbp-28h]
  int v13; // [rsp+44h] [rbp-24h]
  AkCurveInterpolation v14; // [rsp+48h] [rbp-20h]
  __int16 v15; // [rsp+4Ch] [rbp-1Ch]
  char v16; // [rsp+4Eh] [rbp-1Ah]
  CAkParameterNodeBase *v17; // [rsp+50h] [rbp-18h]

  if ( ptargetNode )
  {
    v14 = in_eFadeCurve;
    v15 = 0;
    v16 = 0;
    v11 = in_pGameObj;
    v12 = in_PlayingID;
    v13 = in_uTransitionDuration;
    v17 = ptargetNode;
    if ( in_ActionToExecute )
    {
      v8 = in_ActionToExecute - 1;
      if ( v8 )
      {
        v9 = v8 - 1;
        if ( v9 )
        {
          if ( v9 != 1 )
            return;
          CAkAudioMgr::BreakPendingAction(g_pAudioMgr, ptargetNode, in_pGameObj, in_PlayingID);
          v10 = 3;
        }
        else
        {
          CAkAudioMgr::ResumePausedPendingAction(g_pAudioMgr, ptargetNode, in_pGameObj, 0, in_PlayingID);
          v10 = 2;
        }
      }
      else
      {
        CAkAudioMgr::PausePendingAction(g_pAudioMgr, ptargetNode, in_pGameObj, 1, in_PlayingID);
        v10 = 1;
      }
    }
    else
    {
      CAkAudioMgr::StopPendingAction(g_pAudioMgr, ptargetNode, in_pGameObj, in_PlayingID);
      v10 = 0;
    }
    ptargetNode->vfptr[4].__vecDelDtor(ptargetNode, (unsigned int)&v10);
  }
}

// File Line: 1572
// RVA: 0xA48E00
void __fastcall CAkAudioMgr::PlaySourceInput(
        CAkAudioMgr *this,
        unsigned int in_Target,
        CAkRegisteredObj *in_pGameObj,
        UserParams *in_userParams)
{
  CAkParameterNodeBase *NodePtrAndAddRef; // rax
  CAkParameterNode *v7; // rbx
  unsigned int m_PlayingID; // ecx
  __int64 customParam; // rax
  AkExternalSourceArray *pExternalSrcs; // rax
  AkExternalSourceArray *v11; // rcx
  AkPBIParams in_rPBIParams; // [rsp+20h] [rbp-49h] BYREF
  int v13; // [rsp+E8h] [rbp+7Fh] BYREF
  int v14; // [rsp+ECh] [rbp+83h]

  NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_Target, AkNodeType_Default);
  v7 = (CAkParameterNode *)NodePtrAndAddRef;
  if ( NodePtrAndAddRef )
  {
    m_PlayingID = in_userParams->m_PlayingID;
    in_rPBIParams.pInstigator = NodePtrAndAddRef;
    customParam = in_userParams->m_CustomParam.customParam;
    v13 = 0;
    v14 = 4;
    in_rPBIParams.userParams.m_CustomParam.customParam = customParam;
    LODWORD(customParam) = in_userParams->m_CustomParam.ui32Reserved;
    in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = 0i64;
    in_rPBIParams.userParams.m_CustomParam.ui32Reserved = customParam;
    pExternalSrcs = in_userParams->m_CustomParam.pExternalSrcs;
    in_rPBIParams.playHistory.arrayIsContinuous.m_iBitArray = 0;
    in_rPBIParams.bSkipDelay = 0;
    in_rPBIParams.bTargetFeedback = 0;
    in_rPBIParams.playHistory.HistArray.uiArraySize = 0;
    in_rPBIParams.eType = PBI;
    in_rPBIParams.userParams.m_PlayingID = m_PlayingID;
    if ( pExternalSrcs )
      ++pExternalSrcs->m_cRefCount;
    in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = pExternalSrcs;
    memset(&in_rPBIParams.ePlaybackState, 0, 20);
    in_rPBIParams.bIsFirst = 1;
    in_rPBIParams.pGameObj = in_pGameObj;
    in_rPBIParams.pTransitionParameters = (TransParams *)&v13;
    if ( CAkParameterNode::HandleInitialDelay(v7, &in_rPBIParams) == AK_Success )
      ((void (__fastcall *)(CAkParameterNode *, AkPBIParams *))v7->vfptr[19].Category)(v7, &in_rPBIParams);
    v7->vfptr->Release(v7);
    if ( in_rPBIParams.userParams.m_CustomParam.pExternalSrcs )
      AkExternalSourceArray::Release(in_rPBIParams.userParams.m_CustomParam.pExternalSrcs);
  }
  v11 = in_userParams->m_CustomParam.pExternalSrcs;
  if ( v11 )
    AkExternalSourceArray::Release(v11);
}

// File Line: 1616
// RVA: 0xA487E0
void __fastcall CAkAudioMgr::PausePendingAction(
        CAkAudioMgr *this,
        CAkParameterNodeBase *in_pNodeToTarget,
        CAkRegisteredObj *in_GameObj,
        bool in_bIsMasterOnResume,
        unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rbx
  CAkAudioMgr *v9; // r13
  AkPendingAction *item; // rsi
  CAkAction *pAction; // rbp
  CAkParameterNodeBase *v12; // rax
  CAkParameterNodeBase *m_pParentNode; // rdx
  CAkParameterNodeBase *m_pBusOutputNode; // rcx
  unsigned __int16 m_eActionType; // cx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v16; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v17; // r14
  AkPendingAction *v18; // rbp
  CAkAction *v19; // r15
  CAkParameterNodeBase *v20; // rax
  CAkParameterNodeBase *v21; // rsi
  CAkParameterNodeBase *v22; // rdx
  CAkParameterNodeBase *v23; // rcx
  unsigned __int16 v24; // cx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v26; // [rsp+20h] [rbp-58h]

  m_pFirst = this->m_mmapPausedPending.m_pFirst;
  v9 = this;
  if ( m_pFirst )
  {
    while ( 1 )
    {
      item = m_pFirst->Item.item;
      pAction = item->pAction;
      v12 = CAkAction::GetAndRefTarget(pAction);
      if ( !in_pNodeToTarget )
        goto LABEL_14;
      if ( v12 )
      {
        if ( in_pNodeToTarget == v12 )
          goto LABEL_14;
        m_pParentNode = v12->m_pParentNode;
        m_pBusOutputNode = v12->m_pBusOutputNode;
        if ( m_pParentNode )
        {
          while ( in_pNodeToTarget != m_pParentNode )
          {
            if ( !m_pBusOutputNode )
              m_pBusOutputNode = m_pParentNode->m_pBusOutputNode;
            m_pParentNode = m_pParentNode->m_pParentNode;
            if ( !m_pParentNode )
              goto LABEL_10;
          }
          goto LABEL_14;
        }
LABEL_10:
        if ( m_pBusOutputNode )
        {
          while ( in_pNodeToTarget != m_pBusOutputNode )
          {
            m_pBusOutputNode = m_pBusOutputNode->m_pBusOutputNode;
            if ( !m_pBusOutputNode )
              goto LABEL_22;
          }
LABEL_14:
          m_eActionType = pAction->m_eActionType;
          if ( ((m_eActionType & 0xFF00) != 768 || in_bIsMasterOnResume)
            && (!in_GameObj || in_GameObj == item->pGameObj)
            && (!in_PlayingID || in_PlayingID == item->UserParam.m_PlayingID)
            && m_eActionType != 6176 )
          {
            ++item->ulPauseCount;
          }
        }
      }
LABEL_22:
      m_pFirst = m_pFirst->pNextListItem;
      if ( v12 )
        v12->vfptr->Release(v12);
      if ( !m_pFirst )
      {
        v9 = this;
        break;
      }
    }
  }
  v16 = v9->m_mmapPending.m_pFirst;
  v17 = 0i64;
  while ( v16 )
  {
    v18 = v16->Item.item;
    v19 = v18->pAction;
    v20 = CAkAction::GetAndRefTarget(v19);
    v21 = v20;
    if ( in_pNodeToTarget )
    {
      if ( !v20 )
        goto LABEL_38;
      if ( in_pNodeToTarget != v20 )
      {
        v22 = v20->m_pParentNode;
        v23 = v20->m_pBusOutputNode;
        if ( v22 )
        {
          while ( in_pNodeToTarget != v22 )
          {
            if ( !v23 )
              v23 = v22->m_pBusOutputNode;
            v22 = v22->m_pParentNode;
            if ( !v22 )
              goto LABEL_35;
          }
        }
        else
        {
LABEL_35:
          if ( !v23 )
            goto LABEL_38;
          while ( in_pNodeToTarget != v23 )
          {
            v23 = v23->m_pBusOutputNode;
            if ( !v23 )
              goto LABEL_38;
          }
        }
      }
    }
    v24 = v19->m_eActionType;
    if ( ((v24 & 0xFF00) != 768 || in_bIsMasterOnResume)
      && (!in_GameObj || in_GameObj == v18->pGameObj)
      && (!in_PlayingID || in_PlayingID == v18->UserParam.m_PlayingID)
      && v24 != 6176 )
    {
      CAkAudioMgr::InsertAsPaused(v9, v19->m_ulElementID, v18, 0);
      pNextListItem = v16->pNextListItem;
      v26 = v16->pNextListItem;
      if ( v16 == v9->m_mmapPending.m_pFirst )
        v9->m_mmapPending.m_pFirst = pNextListItem;
      else
        v17->pNextListItem = pNextListItem;
      if ( v16 == v9->m_mmapPending.m_pLast )
        v9->m_mmapPending.m_pLast = v17;
      v16->pNextListItem = v9->m_mmapPending.m_pFree;
      --v9->m_mmapPending.m_ulNumListItems;
      v9->m_mmapPending.m_pFree = v16;
      v16 = v26;
      goto LABEL_39;
    }
LABEL_38:
    v17 = v16;
    v16 = v16->pNextListItem;
LABEL_39:
    if ( v21 )
      v21->vfptr->Release(v21);
  }
}

// File Line: 1679
// RVA: 0xA48C10
void __fastcall CAkAudioMgr::PausePendingItems(CAkAudioMgr *this, unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *i; // rax
  AkPendingAction *item; // rcx
  __int128 m_pFirst; // rdi
  AkPendingAction *v7; // r8
  CAkAction *pAction; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v9; // rax
  __int128 v10; // [rsp+20h] [rbp-28h]

  for ( i = this->m_mmapPausedPending.m_pFirst; i; i = i->pNextListItem )
  {
    item = i->Item.item;
    if ( item->UserParam.m_PlayingID == in_PlayingID && MEMORY[0x34] != 6176 )
      ++item->ulPauseCount;
  }
  m_pFirst = (unsigned __int64)this->m_mmapPending.m_pFirst;
  while ( (_QWORD)m_pFirst )
  {
    v7 = *(AkPendingAction **)(m_pFirst + 16);
    pAction = v7->pAction;
    if ( v7->UserParam.m_PlayingID != in_PlayingID || pAction->m_eActionType == 6176 )
    {
      *((_QWORD *)&m_pFirst + 1) = m_pFirst;
      *(_QWORD *)&m_pFirst = *(_QWORD *)m_pFirst;
    }
    else
    {
      CAkAudioMgr::InsertAsPaused(this, pAction->m_ulElementID, v7, 0);
      v9 = *(CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem **)m_pFirst;
      *((_QWORD *)&v10 + 1) = *((_QWORD *)&m_pFirst + 1);
      *(_QWORD *)&v10 = *(_QWORD *)m_pFirst;
      if ( (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)m_pFirst == this->m_mmapPending.m_pFirst )
        this->m_mmapPending.m_pFirst = v9;
      else
        **((_QWORD **)&m_pFirst + 1) = v9;
      if ( (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)m_pFirst == this->m_mmapPending.m_pLast )
        this->m_mmapPending.m_pLast = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)*((_QWORD *)&m_pFirst + 1);
      *(_QWORD *)m_pFirst = this->m_mmapPending.m_pFree;
      --this->m_mmapPending.m_ulNumListItems;
      this->m_mmapPending.m_pFree = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)m_pFirst;
      m_pFirst = v10;
    }
  }
}

// File Line: 1721
// RVA: 0xA48370
void __fastcall CAkAudioMgr::InsertAsPaused(
        CAkAudioMgr *this,
        unsigned int in_ElementID,
        AkPendingAction *in_pPendingAction,
        unsigned int in_ulPauseCount)
{
  CAkActionPlayAndContinue *pAction; // rcx
  int m_eActionType; // eax
  int v7; // ebx
  int v8[22]; // [rsp+20h] [rbp-58h] BYREF
  AkPendingAction *in_rItem; // [rsp+90h] [rbp+18h] BYREF

  in_rItem = in_pPendingAction;
  in_pPendingAction->PausedTick = this->m_uBufferTick;
  in_pPendingAction->ulPauseCount = in_ulPauseCount;
  if ( (unsigned int)CAkMultiKeyList<unsigned long,AkPendingAction *,2>::Insert(
                       &this->m_mmapPausedPending,
                       in_ElementID,
                       &in_rItem) != 1 )
  {
    pAction = (CAkActionPlayAndContinue *)in_pPendingAction->pAction;
    v8[0] = 0;
    m_eActionType = pAction->m_eActionType;
    if ( m_eActionType != 1027 )
    {
      if ( m_eActionType != 1283 )
      {
LABEL_6:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, in_pPendingAction->UserParam.m_PlayingID);
        in_pPendingAction->pAction->vfptr->Release(in_pPendingAction->pAction);
        v7 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))in_pPendingAction->vfptr[1].TransUpdateValue)(
          in_pPendingAction,
          0i64);
        AK::MemoryMgr::Free(v7, in_pPendingAction);
        return;
      }
      CAkActionPlayAndContinue::NeedNotifyDelay(pAction);
    }
    ((void (__fastcall *)(CAkAction *, int *))in_pPendingAction->pAction->vfptr[2].Category)(
      in_pPendingAction->pAction,
      v8);
    goto LABEL_6;
  }
}

// File Line: 1742
// RVA: 0xA4C140
void __fastcall CAkAudioMgr::TransferToPending(CAkAudioMgr *this, AkPendingAction *in_pPendingAction)
{
  CAkActionPlayAndContinue *pAction; // rcx
  int m_eActionType; // eax
  int v5; // ebx
  int v6[22]; // [rsp+20h] [rbp-58h] BYREF
  AkPendingAction *in_rItem; // [rsp+88h] [rbp+10h] BYREF

  in_rItem = in_pPendingAction;
  in_pPendingAction->LaunchTick += this->m_uBufferTick - in_pPendingAction->PausedTick;
  if ( (unsigned int)CAkMultiKeyList<unsigned long,AkPendingAction *,2>::Insert(
                       &this->m_mmapPending,
                       in_pPendingAction->LaunchTick,
                       &in_rItem) != 1 )
  {
    pAction = (CAkActionPlayAndContinue *)in_pPendingAction->pAction;
    v6[0] = 0;
    m_eActionType = pAction->m_eActionType;
    if ( m_eActionType != 1027 )
    {
      if ( m_eActionType != 1283 )
      {
LABEL_6:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, in_pPendingAction->UserParam.m_PlayingID);
        in_pPendingAction->pAction->vfptr->Release(in_pPendingAction->pAction);
        v5 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))in_pPendingAction->vfptr[1].TransUpdateValue)(
          in_pPendingAction,
          0i64);
        AK::MemoryMgr::Free(v5, in_pPendingAction);
        return;
      }
      CAkActionPlayAndContinue::NeedNotifyDelay(pAction);
    }
    ((void (__fastcall *)(CAkAction *, int *))in_pPendingAction->pAction->vfptr[2].Category)(
      in_pPendingAction->pAction,
      v6);
    goto LABEL_6;
  }
}

// File Line: 1770
// RVA: 0xA47920
__int64 __fastcall CAkAudioMgr::BreakPendingAction(
        CAkAudioMgr *this,
        CAkParameterNodeBase *in_pNodeToTarget,
        CAkRegisteredObj *in_GameObj,
        unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // r15
  AkPendingAction *item; // rsi
  CAkAction *pAction; // r12
  CAkParameterNodeBase *v11; // rax
  CAkParameterNodeBase *v12; // r14
  CAkParameterNodeBase *m_pParentNode; // rdx
  CAkParameterNodeBase *m_pBusOutputNode; // rcx
  int m_eActionType; // eax
  CAkActionPlayAndContinue *v16; // rcx
  int v17; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rax
  int v19; // ebx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v20; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v21; // r15
  AkPendingAction *v22; // rsi
  CAkAction *v23; // r12
  CAkParameterNodeBase *v24; // rax
  CAkParameterNodeBase *v25; // r14
  CAkParameterNodeBase *v26; // rdx
  CAkParameterNodeBase *v27; // rcx
  CAkActionPlayAndContinue *v29; // rcx
  int v30; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v31; // rax
  int v32; // ebx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v33; // [rsp+20h] [rbp-98h]
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v34; // [rsp+30h] [rbp-88h]
  int v35[20]; // [rsp+40h] [rbp-78h] BYREF

  m_pFirst = this->m_mmapPending.m_pFirst;
  v5 = 0i64;
  if ( m_pFirst )
  {
    while ( 1 )
    {
      item = m_pFirst->Item.item;
      pAction = item->pAction;
      v11 = CAkAction::GetAndRefTarget(pAction);
      v12 = v11;
      if ( in_pNodeToTarget )
      {
        if ( !v11 )
          goto LABEL_22;
        if ( in_pNodeToTarget != v11 )
        {
          m_pParentNode = v11->m_pParentNode;
          m_pBusOutputNode = v11->m_pBusOutputNode;
          if ( m_pParentNode )
          {
            while ( in_pNodeToTarget != m_pParentNode )
            {
              if ( !m_pBusOutputNode )
                m_pBusOutputNode = m_pParentNode->m_pBusOutputNode;
              m_pParentNode = m_pParentNode->m_pParentNode;
              if ( !m_pParentNode )
                goto LABEL_10;
            }
          }
          else
          {
LABEL_10:
            if ( !m_pBusOutputNode )
              goto LABEL_22;
            while ( in_pNodeToTarget != m_pBusOutputNode )
            {
              m_pBusOutputNode = m_pBusOutputNode->m_pBusOutputNode;
              if ( !m_pBusOutputNode )
              {
                v5 = m_pFirst;
                m_pFirst = m_pFirst->pNextListItem;
                goto LABEL_33;
              }
            }
          }
        }
      }
      if ( in_GameObj && in_GameObj != item->pGameObj )
        goto LABEL_22;
      if ( !in_PlayingID || in_PlayingID == item->UserParam.m_PlayingID )
        break;
      v5 = m_pFirst;
      m_pFirst = m_pFirst->pNextListItem;
LABEL_33:
      if ( v12 )
        v12->vfptr->Release(v12);
      if ( !m_pFirst )
        goto LABEL_36;
    }
    m_eActionType = pAction->m_eActionType;
    if ( m_eActionType == 1027
      || m_eActionType == 1283
      && CAkActionPlayAndContinue::BreakToNode(
           (CAkActionPlayAndContinue *)item->pAction,
           in_pNodeToTarget,
           item->pGameObj,
           item) )
    {
      v16 = (CAkActionPlayAndContinue *)item->pAction;
      v35[0] = 0;
      v17 = v16->m_eActionType;
      if ( v17 == 1027 )
        goto LABEL_26;
      if ( v17 == 1283 )
      {
        CAkActionPlayAndContinue::NeedNotifyDelay(v16);
LABEL_26:
        ((void (__fastcall *)(CAkAction *, int *))item->pAction->vfptr[2].Category)(item->pAction, v35);
      }
      CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, item->UserParam.m_PlayingID);
      pNextListItem = m_pFirst->pNextListItem;
      v33 = m_pFirst->pNextListItem;
      if ( m_pFirst == this->m_mmapPending.m_pFirst )
        this->m_mmapPending.m_pFirst = pNextListItem;
      else
        v5->pNextListItem = pNextListItem;
      if ( m_pFirst == this->m_mmapPending.m_pLast )
        this->m_mmapPending.m_pLast = v5;
      m_pFirst->pNextListItem = this->m_mmapPending.m_pFree;
      --this->m_mmapPending.m_ulNumListItems;
      this->m_mmapPending.m_pFree = m_pFirst;
      item->pAction->vfptr->Release(item->pAction);
      v19 = g_DefaultPoolId;
      ((void (__fastcall *)(AkPendingAction *, _QWORD))item->vfptr[1].TransUpdateValue)(item, 0i64);
      AK::MemoryMgr::Free(v19, item);
      m_pFirst = v33;
      goto LABEL_33;
    }
LABEL_22:
    v5 = m_pFirst;
    m_pFirst = m_pFirst->pNextListItem;
    goto LABEL_33;
  }
LABEL_36:
  v20 = this->m_mmapPausedPending.m_pFirst;
  v21 = 0i64;
  while ( v20 )
  {
    v22 = v20->Item.item;
    v23 = v22->pAction;
    v24 = CAkAction::GetAndRefTarget(v23);
    v25 = v24;
    if ( in_pNodeToTarget )
    {
      if ( !v24 )
        goto LABEL_48;
      if ( in_pNodeToTarget != v24 )
      {
        v26 = v24->m_pParentNode;
        v27 = v24->m_pBusOutputNode;
        if ( v26 )
        {
          while ( in_pNodeToTarget != v26 )
          {
            if ( !v27 )
              v27 = v26->m_pBusOutputNode;
            v26 = v26->m_pParentNode;
            if ( !v26 )
              goto LABEL_45;
          }
        }
        else
        {
LABEL_45:
          if ( !v27 )
            goto LABEL_48;
          while ( in_pNodeToTarget != v27 )
          {
            v27 = v27->m_pBusOutputNode;
            if ( !v27 )
              goto LABEL_48;
          }
        }
      }
    }
    if ( (!in_GameObj || in_GameObj == v22->pGameObj)
      && (!in_PlayingID || in_PlayingID == v22->UserParam.m_PlayingID)
      && v23->m_eActionType == 1283
      && CAkActionPlayAndContinue::BreakToNode(
           (CAkActionPlayAndContinue *)v22->pAction,
           in_pNodeToTarget,
           v22->pGameObj,
           v22) )
    {
      v29 = (CAkActionPlayAndContinue *)v22->pAction;
      v35[0] = 0;
      v30 = v29->m_eActionType;
      if ( v30 == 1027 )
        goto LABEL_62;
      if ( v30 == 1283 )
      {
        CAkActionPlayAndContinue::NeedNotifyDelay(v29);
LABEL_62:
        ((void (__fastcall *)(CAkAction *, int *))v22->pAction->vfptr[2].Category)(v22->pAction, v35);
      }
      CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v22->UserParam.m_PlayingID);
      v31 = v20->pNextListItem;
      v34 = v20->pNextListItem;
      if ( v20 == this->m_mmapPausedPending.m_pFirst )
        this->m_mmapPausedPending.m_pFirst = v31;
      else
        v21->pNextListItem = v31;
      if ( v20 == this->m_mmapPausedPending.m_pLast )
        this->m_mmapPausedPending.m_pLast = v21;
      v20->pNextListItem = this->m_mmapPausedPending.m_pFree;
      --this->m_mmapPausedPending.m_ulNumListItems;
      this->m_mmapPausedPending.m_pFree = v20;
      v22->pAction->vfptr->Release(v22->pAction);
      v32 = g_DefaultPoolId;
      ((void (__fastcall *)(AkPendingAction *, _QWORD))v22->vfptr[1].TransUpdateValue)(v22, 0i64);
      AK::MemoryMgr::Free(v32, v22);
      v20 = v34;
      goto LABEL_49;
    }
LABEL_48:
    v21 = v20;
    v20 = v20->pNextListItem;
LABEL_49:
    if ( v25 )
      v25->vfptr->Release(v25);
  }
  return 1i64;
}  v21 = v20;
    v20 = v20->pNextListItem;
LABEL_49:
    if ( v25 )
      v25->vfptr->Release(v25);
  }
  return 1i64;
}

// File Line: 1873
// RVA: 0xA4B960
__int64 __fastcall CAkAudioMgr::StopPendingAction(
        CAkAudioMgr *this,
        CAkParameterNodeBase *in_pNodeToTarget,
        CAkRegisteredObj *in_GameObj,
        unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // r15
  AkPendingAction *item; // r14
  CAkAction *pAction; // r12
  CAkParameterNodeBase *v11; // rax
  CAkParameterNodeBase *v12; // rsi
  CAkParameterNodeBase *m_pParentNode; // rdx
  CAkParameterNodeBase *m_pBusOutputNode; // rcx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v15; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v16; // r15
  AkPendingAction *v17; // r14
  CAkAction *v18; // r12
  CAkParameterNodeBase *v19; // rax
  CAkParameterNodeBase *v20; // rsi
  CAkParameterNodeBase *v21; // rdx
  CAkParameterNodeBase *v22; // rcx
  CAkActionPlayAndContinue *v24; // rcx
  int m_eActionType; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rax
  int v27; // ebx
  CAkActionPlayAndContinue *v28; // rcx
  int v29; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v30; // rax
  int v31; // ebx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v32; // [rsp+20h] [rbp-98h]
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v33; // [rsp+30h] [rbp-88h]
  int v34[20]; // [rsp+40h] [rbp-78h] BYREF

  m_pFirst = this->m_mmapPending.m_pFirst;
  v5 = 0i64;
  while ( m_pFirst )
  {
    item = m_pFirst->Item.item;
    pAction = item->pAction;
    v11 = CAkAction::GetAndRefTarget(pAction);
    v12 = v11;
    if ( in_pNodeToTarget )
    {
      if ( !v11 )
        goto LABEL_13;
      if ( in_pNodeToTarget != v11 )
      {
        m_pParentNode = v11->m_pParentNode;
        m_pBusOutputNode = v11->m_pBusOutputNode;
        if ( m_pParentNode )
        {
          while ( in_pNodeToTarget != m_pParentNode )
          {
            if ( !m_pBusOutputNode )
              m_pBusOutputNode = m_pParentNode->m_pBusOutputNode;
            m_pParentNode = m_pParentNode->m_pParentNode;
            if ( !m_pParentNode )
              goto LABEL_10;
          }
        }
        else
        {
LABEL_10:
          if ( !m_pBusOutputNode )
            goto LABEL_13;
          while ( in_pNodeToTarget != m_pBusOutputNode )
          {
            m_pBusOutputNode = m_pBusOutputNode->m_pBusOutputNode;
            if ( !m_pBusOutputNode )
              goto LABEL_13;
          }
        }
      }
    }
    if ( (!in_GameObj || in_GameObj == item->pGameObj)
      && (!in_PlayingID || in_PlayingID == item->UserParam.m_PlayingID)
      && pAction->m_eActionType != 6176 )
    {
      v24 = (CAkActionPlayAndContinue *)item->pAction;
      v34[0] = 0;
      m_eActionType = v24->m_eActionType;
      if ( m_eActionType == 1027 )
        goto LABEL_42;
      if ( m_eActionType == 1283 )
      {
        CAkActionPlayAndContinue::NeedNotifyDelay(v24);
LABEL_42:
        ((void (__fastcall *)(CAkAction *, int *))item->pAction->vfptr[2].Category)(item->pAction, v34);
      }
      CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, item->UserParam.m_PlayingID);
      pNextListItem = m_pFirst->pNextListItem;
      v32 = m_pFirst->pNextListItem;
      if ( m_pFirst == this->m_mmapPending.m_pFirst )
        this->m_mmapPending.m_pFirst = pNextListItem;
      else
        v5->pNextListItem = pNextListItem;
      if ( m_pFirst == this->m_mmapPending.m_pLast )
        this->m_mmapPending.m_pLast = v5;
      m_pFirst->pNextListItem = this->m_mmapPending.m_pFree;
      --this->m_mmapPending.m_ulNumListItems;
      this->m_mmapPending.m_pFree = m_pFirst;
      item->pAction->vfptr->Release(item->pAction);
      v27 = g_DefaultPoolId;
      ((void (__fastcall *)(AkPendingAction *, _QWORD))item->vfptr[1].TransUpdateValue)(item, 0i64);
      AK::MemoryMgr::Free(v27, item);
      m_pFirst = v32;
      goto LABEL_14;
    }
LABEL_13:
    v5 = m_pFirst;
    m_pFirst = m_pFirst->pNextListItem;
LABEL_14:
    if ( v12 )
      v12->vfptr->Release(v12);
  }
  v15 = this->m_mmapPausedPending.m_pFirst;
  v16 = 0i64;
  while ( v15 )
  {
    v17 = v15->Item.item;
    v18 = v17->pAction;
    v19 = CAkAction::GetAndRefTarget(v18);
    v20 = v19;
    if ( in_pNodeToTarget )
    {
      if ( !v19 )
        goto LABEL_29;
      if ( in_pNodeToTarget != v19 )
      {
        v21 = v19->m_pParentNode;
        v22 = v19->m_pBusOutputNode;
        if ( v21 )
        {
          while ( in_pNodeToTarget != v21 )
          {
            if ( !v22 )
              v22 = v21->m_pBusOutputNode;
            v21 = v21->m_pParentNode;
            if ( !v21 )
              goto LABEL_26;
          }
        }
        else
        {
LABEL_26:
          if ( !v22 )
            goto LABEL_29;
          while ( in_pNodeToTarget != v22 )
          {
            v22 = v22->m_pBusOutputNode;
            if ( !v22 )
              goto LABEL_29;
          }
        }
      }
    }
    if ( (!in_GameObj || in_GameObj == v17->pGameObj)
      && (!in_PlayingID || in_PlayingID == v17->UserParam.m_PlayingID)
      && v18->m_eActionType != 6176 )
    {
      v28 = (CAkActionPlayAndContinue *)v17->pAction;
      v34[0] = 0;
      v29 = v28->m_eActionType;
      if ( v29 == 1027 )
        goto LABEL_57;
      if ( v29 == 1283 )
      {
        CAkActionPlayAndContinue::NeedNotifyDelay(v28);
LABEL_57:
        ((void (__fastcall *)(CAkAction *, int *))v17->pAction->vfptr[2].Category)(v17->pAction, v34);
      }
      CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v17->UserParam.m_PlayingID);
      v30 = v15->pNextListItem;
      v33 = v15->pNextListItem;
      if ( v15 == this->m_mmapPausedPending.m_pFirst )
        this->m_mmapPausedPending.m_pFirst = v30;
      else
        v16->pNextListItem = v30;
      if ( v15 == this->m_mmapPausedPending.m_pLast )
        this->m_mmapPausedPending.m_pLast = v16;
      v15->pNextListItem = this->m_mmapPausedPending.m_pFree;
      --this->m_mmapPausedPending.m_ulNumListItems;
      this->m_mmapPausedPending.m_pFree = v15;
      v17->pAction->vfptr->Release(v17->pAction);
      v31 = g_DefaultPoolId;
      ((void (__fastcall *)(AkPendingAction *, _QWORD))v17->vfptr[1].TransUpdateValue)(v17, 0i64);
      AK::MemoryMgr::Free(v31, v17);
      v15 = v33;
      goto LABEL_30;
    }
LABEL_29:
    v16 = v15;
    v15 = v15->pNextListItem;
LABEL_30:
    if ( v20 )
      v20->vfptr->Release(v20);
  }
  return 1i64;
}

// File Line: 1947
// RVA: 0xA48A40
void __fastcall CAkAudioMgr::PausePendingActionAllExcept(
        CAkAudioMgr *this,
        CAkRegisteredObj *in_GameObj,
        AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *in_pExceptionList,
        bool in_bIsMasterOnResume,
        unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *i; // rbx
  AkPendingAction *item; // rdi
  CAkAction *pAction; // rbp
  char IsAnException; // al
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *j; // rdi
  AkPendingAction *v14; // rbp
  CAkAction *v15; // r14
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v17; // [rsp+20h] [rbp-48h]
  AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *in_pExceptionLista; // [rsp+80h] [rbp+18h]

  in_pExceptionLista = in_pExceptionList;
  for ( i = this->m_mmapPausedPending.m_pFirst; i; i = i->pNextListItem )
  {
    item = i->Item.item;
    pAction = item->pAction;
    if ( ((pAction->m_eActionType & 0xFF00) != 768 || in_bIsMasterOnResume)
      && (!in_GameObj || in_GameObj == item->pGameObj)
      && (!in_PlayingID || in_PlayingID == item->UserParam.m_PlayingID) )
    {
      IsAnException = CAkAudioMgr::IsAnException(this, item->pAction, in_pExceptionList);
      in_pExceptionList = in_pExceptionLista;
      if ( !IsAnException && pAction->m_eActionType != 6176 )
        ++item->ulPauseCount;
    }
  }
  m_pFirst = this->m_mmapPending.m_pFirst;
  for ( j = 0i64; m_pFirst; in_pExceptionList = in_pExceptionLista )
  {
    v14 = m_pFirst->Item.item;
    v15 = v14->pAction;
    if ( (v15->m_eActionType & 0xFF00) == 768 && !in_bIsMasterOnResume
      || in_GameObj && in_GameObj != v14->pGameObj
      || in_PlayingID && in_PlayingID != v14->UserParam.m_PlayingID
      || CAkAudioMgr::IsAnException(this, v14->pAction, in_pExceptionList)
      || v15->m_eActionType == 6176 )
    {
      j = m_pFirst;
      m_pFirst = m_pFirst->pNextListItem;
    }
    else
    {
      CAkAudioMgr::InsertAsPaused(this, v15->m_ulElementID, v14, 0);
      pNextListItem = m_pFirst->pNextListItem;
      v17 = m_pFirst->pNextListItem;
      if ( m_pFirst == this->m_mmapPending.m_pFirst )
        this->m_mmapPending.m_pFirst = pNextListItem;
      else
        j->pNextListItem = pNextListItem;
      if ( m_pFirst == this->m_mmapPending.m_pLast )
        this->m_mmapPending.m_pLast = j;
      m_pFirst->pNextListItem = this->m_mmapPending.m_pFree;
      --this->m_mmapPending.m_ulNumListItems;
      this->m_mmapPending.m_pFree = m_pFirst;
      m_pFirst = v17;
    }
  }
}

// File Line: 2010
// RVA: 0xA4BCE0
__int64 __fastcall CAkAudioMgr::StopPendingActionAllExcept(
        CAkAudioMgr *this,
        CAkRegisteredObj *in_GameObj,
        AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *in_pExceptionList,
        unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rdi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v9; // r14
  AkPendingAction *item; // rsi
  CAkActionPlayAndContinue *pAction; // rcx
  unsigned __int16 m_eActionType; // ax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rax
  int v14; // edi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v15; // rdi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v16; // r14
  AkPendingAction *v17; // rsi
  CAkActionPlayAndContinue *v18; // rcx
  unsigned __int16 v19; // ax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v20; // rax
  int v21; // edi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v23; // [rsp+20h] [rbp-98h]
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v24; // [rsp+30h] [rbp-88h]
  int v25[20]; // [rsp+40h] [rbp-78h] BYREF

  m_pFirst = this->m_mmapPending.m_pFirst;
  v9 = 0i64;
  if ( m_pFirst )
  {
    while ( 1 )
    {
      item = m_pFirst->Item.item;
      if ( (!in_GameObj || in_GameObj == item->pGameObj)
        && (!in_PlayingID || in_PlayingID == item->UserParam.m_PlayingID)
        && !CAkAudioMgr::IsAnException(this, item->pAction, in_pExceptionList) )
      {
        pAction = (CAkActionPlayAndContinue *)item->pAction;
        m_eActionType = pAction->m_eActionType;
        if ( m_eActionType != 6176 )
          break;
      }
      v9 = m_pFirst;
      m_pFirst = m_pFirst->pNextListItem;
LABEL_19:
      if ( !m_pFirst )
        goto LABEL_20;
    }
    v25[0] = 0;
    if ( m_eActionType != 1027 )
    {
      if ( m_eActionType != 1283 )
      {
LABEL_12:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, item->UserParam.m_PlayingID);
        pNextListItem = m_pFirst->pNextListItem;
        v23 = m_pFirst->pNextListItem;
        if ( m_pFirst == this->m_mmapPending.m_pFirst )
          this->m_mmapPending.m_pFirst = pNextListItem;
        else
          v9->pNextListItem = pNextListItem;
        if ( m_pFirst == this->m_mmapPending.m_pLast )
          this->m_mmapPending.m_pLast = v9;
        m_pFirst->pNextListItem = this->m_mmapPending.m_pFree;
        --this->m_mmapPending.m_ulNumListItems;
        this->m_mmapPending.m_pFree = m_pFirst;
        item->pAction->vfptr->Release(item->pAction);
        v14 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))item->vfptr[1].TransUpdateValue)(item, 0i64);
        AK::MemoryMgr::Free(v14, item);
        m_pFirst = v23;
        goto LABEL_19;
      }
      CAkActionPlayAndContinue::NeedNotifyDelay(pAction);
    }
    ((void (__fastcall *)(CAkIndexableVtbl **, int *))item->pAction->vfptr[2].Category)(&item->pAction->vfptr, v25);
    goto LABEL_12;
  }
LABEL_20:
  v15 = this->m_mmapPausedPending.m_pFirst;
  v16 = 0i64;
  if ( v15 )
  {
    while ( 1 )
    {
      v17 = v15->Item.item;
      if ( (!in_GameObj || in_GameObj == v17->pGameObj)
        && (!in_PlayingID || in_PlayingID == v17->UserParam.m_PlayingID)
        && !CAkAudioMgr::IsAnException(this, v17->pAction, in_pExceptionList) )
      {
        v18 = (CAkActionPlayAndContinue *)v17->pAction;
        v19 = v18->m_eActionType;
        if ( v19 != 6176 )
          break;
      }
      v16 = v15;
      v15 = v15->pNextListItem;
LABEL_38:
      if ( !v15 )
        return 1i64;
    }
    v25[0] = 0;
    if ( v19 != 1027 )
    {
      if ( v19 != 1283 )
      {
LABEL_31:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v17->UserParam.m_PlayingID);
        v20 = v15->pNextListItem;
        v24 = v15->pNextListItem;
        if ( v15 == this->m_mmapPausedPending.m_pFirst )
          this->m_mmapPausedPending.m_pFirst = v20;
        else
          v16->pNextListItem = v20;
        if ( v15 == this->m_mmapPausedPending.m_pLast )
          this->m_mmapPausedPending.m_pLast = v16;
        v15->pNextListItem = this->m_mmapPausedPending.m_pFree;
        --this->m_mmapPausedPending.m_ulNumListItems;
        this->m_mmapPausedPending.m_pFree = v15;
        v17->pAction->vfptr->Release(v17->pAction);
        v21 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))v17->vfptr[1].TransUpdateValue)(v17, 0i64);
        AK::MemoryMgr::Free(v21, v17);
        v15 = v24;
        goto LABEL_38;
      }
      CAkActionPlayAndContinue::NeedNotifyDelay(v18);
    }
    ((void (__fastcall *)(CAkIndexableVtbl **, int *))v17->pAction->vfptr[2].Category)(&v17->pAction->vfptr, v25);
    goto LABEL_31;
  }
  return 1i64;
}

// File Line: 2073
// RVA: 0xA4B010
void __fastcall CAkAudioMgr::ResumePausedPendingAction(
        CAkAudioMgr *this,
        CAkParameterNodeBase *in_pNodeToTarget,
        CAkRegisteredObj *in_GameObj,
        bool in_bIsMasterOnResume,
        unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v6; // r15
  bool v7; // al
  AkPendingAction *item; // rbp
  CAkParameterNodeBase *v12; // rax
  CAkParameterNodeBase *v13; // rsi
  CAkParameterNodeBase *m_pParentNode; // rdx
  CAkParameterNodeBase *m_pBusOutputNode; // rcx
  unsigned int ulPauseCount; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v18; // [rsp+30h] [rbp-48h]

  m_pFirst = this->m_mmapPausedPending.m_pFirst;
  v6 = 0i64;
  v7 = in_bIsMasterOnResume;
  if ( m_pFirst )
  {
    while ( 1 )
    {
      item = m_pFirst->Item.item;
      v12 = CAkAction::GetAndRefTarget(item->pAction);
      v13 = v12;
      if ( in_pNodeToTarget )
      {
        if ( !v12 )
          goto LABEL_18;
        if ( in_pNodeToTarget != v12 )
        {
          m_pParentNode = v12->m_pParentNode;
          m_pBusOutputNode = v12->m_pBusOutputNode;
          if ( m_pParentNode )
          {
            while ( in_pNodeToTarget != m_pParentNode )
            {
              if ( !m_pBusOutputNode )
                m_pBusOutputNode = m_pParentNode->m_pBusOutputNode;
              m_pParentNode = m_pParentNode->m_pParentNode;
              if ( !m_pParentNode )
                goto LABEL_10;
            }
          }
          else
          {
LABEL_10:
            if ( !m_pBusOutputNode )
              goto LABEL_18;
            while ( in_pNodeToTarget != m_pBusOutputNode )
            {
              m_pBusOutputNode = m_pBusOutputNode->m_pBusOutputNode;
              if ( !m_pBusOutputNode )
              {
                v6 = m_pFirst;
                m_pFirst = m_pFirst->pNextListItem;
                goto LABEL_28;
              }
            }
          }
        }
      }
      if ( (!in_GameObj || in_GameObj == item->pGameObj)
        && (!in_PlayingID || in_PlayingID == item->UserParam.m_PlayingID) )
      {
        if ( in_bIsMasterOnResume || (ulPauseCount = item->ulPauseCount) == 0 )
        {
          CAkAudioMgr::TransferToPending(this, item);
          pNextListItem = m_pFirst->pNextListItem;
          v18 = m_pFirst->pNextListItem;
          if ( m_pFirst == this->m_mmapPausedPending.m_pFirst )
            this->m_mmapPausedPending.m_pFirst = pNextListItem;
          else
            v6->pNextListItem = pNextListItem;
          if ( m_pFirst == this->m_mmapPausedPending.m_pLast )
            this->m_mmapPausedPending.m_pLast = v6;
          m_pFirst->pNextListItem = this->m_mmapPausedPending.m_pFree;
          --this->m_mmapPausedPending.m_ulNumListItems;
          this->m_mmapPausedPending.m_pFree = m_pFirst;
          m_pFirst = v18;
        }
        else
        {
          v6 = m_pFirst;
          item->ulPauseCount = ulPauseCount - 1;
          m_pFirst = m_pFirst->pNextListItem;
        }
        goto LABEL_28;
      }
LABEL_18:
      v6 = m_pFirst;
      m_pFirst = m_pFirst->pNextListItem;
LABEL_28:
      if ( v13 )
        v13->vfptr->Release(v13);
      if ( !m_pFirst )
      {
        v7 = in_bIsMasterOnResume;
        break;
      }
    }
  }
  CAkAudioMgr::ResumeNotPausedPendingAction(this, in_pNodeToTarget, in_GameObj, v7, in_PlayingID);
}

// File Line: 2109
// RVA: 0xA4B310
void __fastcall CAkAudioMgr::ResumePausedPendingItems(CAkAudioMgr *this, unsigned int in_playingID)
{
  __int128 m_pFirst; // rdi
  __int64 v5; // rcx
  int v6; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v7; // rax
  __int128 v8; // [rsp+20h] [rbp-28h]

  m_pFirst = (unsigned __int64)this->m_mmapPausedPending.m_pFirst;
  while ( (_QWORD)m_pFirst )
  {
    v5 = *(_QWORD *)(m_pFirst + 16);
    if ( *(_DWORD *)(v5 + 56) == in_playingID )
    {
      v6 = *(_DWORD *)(v5 + 64);
      if ( !v6 )
      {
        CAkAudioMgr::TransferToPending(this, *(AkPendingAction **)(m_pFirst + 16));
        v7 = *(CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem **)m_pFirst;
        *((_QWORD *)&v8 + 1) = *((_QWORD *)&m_pFirst + 1);
        *(_QWORD *)&v8 = *(_QWORD *)m_pFirst;
        if ( (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)m_pFirst == this->m_mmapPausedPending.m_pFirst )
          this->m_mmapPausedPending.m_pFirst = v7;
        else
          **((_QWORD **)&m_pFirst + 1) = v7;
        if ( (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)m_pFirst == this->m_mmapPausedPending.m_pLast )
          this->m_mmapPausedPending.m_pLast = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)*((_QWORD *)&m_pFirst + 1);
        *(_QWORD *)m_pFirst = this->m_mmapPausedPending.m_pFree;
        --this->m_mmapPausedPending.m_ulNumListItems;
        this->m_mmapPausedPending.m_pFree = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)m_pFirst;
        m_pFirst = v8;
        continue;
      }
      *(_DWORD *)(v5 + 64) = v6 - 1;
    }
    *((_QWORD *)&m_pFirst + 1) = m_pFirst;
    *(_QWORD *)&m_pFirst = *(_QWORD *)m_pFirst;
  }
}

// File Line: 2142
// RVA: 0xA4AE50
void __fastcall CAkAudioMgr::ResumeNotPausedPendingAction(
        CAkAudioMgr *this,
        CAkParameterNodeBase *in_pNodeToTarget,
        CAkRegisteredObj *in_GameObj,
        bool __formal,
        unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rsi
  AkPendingAction *item; // rbp
  CAkActionPlayAndContinue *pAction; // r14
  CAkParameterNodeBase *v10; // rax
  CAkParameterNodeBase *v11; // rdi
  CAkParameterNodeBase *m_pParentNode; // rdx
  CAkParameterNodeBase *m_pBusOutputNode; // rcx

  m_pFirst = this->m_mmapPending.m_pFirst;
  while ( m_pFirst )
  {
    item = m_pFirst->Item.item;
    pAction = (CAkActionPlayAndContinue *)item->pAction;
    v10 = CAkAction::GetAndRefTarget(pAction);
    v11 = v10;
    if ( !in_pNodeToTarget )
      goto LABEL_14;
    if ( v10 )
    {
      if ( in_pNodeToTarget == v10 )
        goto LABEL_14;
      m_pParentNode = v10->m_pParentNode;
      m_pBusOutputNode = v10->m_pBusOutputNode;
      if ( m_pParentNode )
      {
        while ( in_pNodeToTarget != m_pParentNode )
        {
          if ( !m_pBusOutputNode )
            m_pBusOutputNode = m_pParentNode->m_pBusOutputNode;
          m_pParentNode = m_pParentNode->m_pParentNode;
          if ( !m_pParentNode )
            goto LABEL_10;
        }
        goto LABEL_14;
      }
LABEL_10:
      if ( m_pBusOutputNode )
      {
        while ( in_pNodeToTarget != m_pBusOutputNode )
        {
          m_pBusOutputNode = m_pBusOutputNode->m_pBusOutputNode;
          if ( !m_pBusOutputNode )
            goto LABEL_20;
        }
LABEL_14:
        if ( (!in_GameObj || in_GameObj == item->pGameObj)
          && (!in_PlayingID || in_PlayingID == item->UserParam.m_PlayingID)
          && pAction->m_eActionType == 1283 )
        {
          CAkActionPlayAndContinue::Resume(pAction);
        }
      }
    }
LABEL_20:
    m_pFirst = m_pFirst->pNextListItem;
    if ( v11 )
      v11->vfptr->Release(v11);
  }
}

// File Line: 2180
// RVA: 0xA4B1D0
void __fastcall CAkAudioMgr::ResumePausedPendingActionAllExcept(
        CAkAudioMgr *this,
        CAkRegisteredObj *in_GameObj,
        AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *in_pExceptionList,
        bool in_bIsMasterOnResume,
        unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v6; // r14
  AkPendingAction *item; // rsi
  unsigned int ulPauseCount; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v14; // [rsp+30h] [rbp-48h]

  m_pFirst = this->m_mmapPausedPending.m_pFirst;
  v6 = 0i64;
  while ( m_pFirst )
  {
    item = m_pFirst->Item.item;
    if ( (!in_GameObj || in_GameObj == item->pGameObj)
      && (!in_PlayingID || in_PlayingID == item->UserParam.m_PlayingID)
      && !CAkAudioMgr::IsAnException(this, item->pAction, in_pExceptionList) )
    {
      if ( in_bIsMasterOnResume || (ulPauseCount = item->ulPauseCount) == 0 )
      {
        CAkAudioMgr::TransferToPending(this, item);
        pNextListItem = m_pFirst->pNextListItem;
        v14 = m_pFirst->pNextListItem;
        if ( m_pFirst == this->m_mmapPausedPending.m_pFirst )
          this->m_mmapPausedPending.m_pFirst = pNextListItem;
        else
          v6->pNextListItem = pNextListItem;
        if ( m_pFirst == this->m_mmapPausedPending.m_pLast )
          this->m_mmapPausedPending.m_pLast = v6;
        m_pFirst->pNextListItem = this->m_mmapPausedPending.m_pFree;
        --this->m_mmapPausedPending.m_ulNumListItems;
        this->m_mmapPausedPending.m_pFree = m_pFirst;
        m_pFirst = v14;
        continue;
      }
      item->ulPauseCount = ulPauseCount - 1;
    }
    v6 = m_pFirst;
    m_pFirst = m_pFirst->pNextListItem;
  }
  CAkAudioMgr::ResumeNotPausedPendingActionAllExcept(
    g_pAudioMgr,
    in_GameObj,
    in_pExceptionList,
    in_bIsMasterOnResume,
    in_PlayingID);
}

// File Line: 2216
// RVA: 0xA4AF60
void __fastcall CAkAudioMgr::ResumeNotPausedPendingActionAllExcept(
        CAkAudioMgr *this,
        CAkRegisteredObj *in_GameObj,
        AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *in_pExceptionList,
        bool __formal,
        unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *i; // rbx
  AkPendingAction *item; // rax
  CAkActionPlayAndContinue *pAction; // rdi

  for ( i = this->m_mmapPending.m_pFirst; i; i = i->pNextListItem )
  {
    item = i->Item.item;
    pAction = (CAkActionPlayAndContinue *)item->pAction;
    if ( (!in_GameObj || in_GameObj == item->pGameObj)
      && (!in_PlayingID || in_PlayingID == item->UserParam.m_PlayingID)
      && !CAkAudioMgr::IsAnException(this, item->pAction, in_pExceptionList)
      && pAction->m_eActionType == 1283 )
    {
      CAkActionPlayAndContinue::Resume(pAction);
    }
  }
}

// File Line: 2246
// RVA: 0xA4AB10
void __fastcall CAkAudioMgr::RemovePendingAction(CAkAudioMgr *this, CAkParameterNodeBase *in_pNodeToTarget)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // r15
  AkPendingAction *item; // r14
  CAkAction *pAction; // r12
  CAkParameterNodeBase *v8; // rax
  CAkParameterNodeBase *v9; // rsi
  CAkParameterNodeBase *m_pParentNode; // rdx
  CAkParameterNodeBase *m_pBusOutputNode; // rcx
  CAkActionPlayAndContinue *v12; // rcx
  int m_eActionType; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rax
  int v15; // ebx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v16; // [rsp+20h] [rbp-98h]
  int v17[30]; // [rsp+40h] [rbp-78h] BYREF

  m_pFirst = this->m_mmapPending.m_pFirst;
  v5 = 0i64;
  while ( m_pFirst )
  {
    item = m_pFirst->Item.item;
    pAction = item->pAction;
    v8 = CAkAction::GetAndRefTarget(pAction);
    v9 = v8;
    if ( !in_pNodeToTarget || !v8 )
      goto LABEL_13;
    if ( in_pNodeToTarget != v8 )
    {
      m_pParentNode = v8->m_pParentNode;
      m_pBusOutputNode = v8->m_pBusOutputNode;
      if ( m_pParentNode )
      {
        while ( in_pNodeToTarget != m_pParentNode )
        {
          if ( !m_pBusOutputNode )
            m_pBusOutputNode = m_pParentNode->m_pBusOutputNode;
          m_pParentNode = m_pParentNode->m_pParentNode;
          if ( !m_pParentNode )
            goto LABEL_10;
        }
      }
      else
      {
LABEL_10:
        if ( !m_pBusOutputNode )
          goto LABEL_13;
        while ( in_pNodeToTarget != m_pBusOutputNode )
        {
          m_pBusOutputNode = m_pBusOutputNode->m_pBusOutputNode;
          if ( !m_pBusOutputNode )
            goto LABEL_13;
        }
      }
    }
    if ( pAction->m_eActionType != 6176 )
    {
      v12 = (CAkActionPlayAndContinue *)item->pAction;
      v17[0] = 0;
      m_eActionType = v12->m_eActionType;
      if ( m_eActionType == 1027 )
        goto LABEL_22;
      if ( m_eActionType == 1283 )
      {
        CAkActionPlayAndContinue::NeedNotifyDelay(v12);
LABEL_22:
        ((void (__fastcall *)(CAkAction *, int *))item->pAction->vfptr[2].Category)(item->pAction, v17);
      }
      CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, item->UserParam.m_PlayingID);
      pNextListItem = m_pFirst->pNextListItem;
      v16 = m_pFirst->pNextListItem;
      if ( m_pFirst == this->m_mmapPending.m_pFirst )
        this->m_mmapPending.m_pFirst = pNextListItem;
      else
        v5->pNextListItem = pNextListItem;
      if ( m_pFirst == this->m_mmapPending.m_pLast )
        this->m_mmapPending.m_pLast = v5;
      m_pFirst->pNextListItem = this->m_mmapPending.m_pFree;
      --this->m_mmapPending.m_ulNumListItems;
      this->m_mmapPending.m_pFree = m_pFirst;
      item->pAction->vfptr->Release(item->pAction);
      v15 = g_DefaultPoolId;
      ((void (__fastcall *)(AkPendingAction *, _QWORD))item->vfptr[1].TransUpdateValue)(item, 0i64);
      AK::MemoryMgr::Free(v15, item);
      m_pFirst = v16;
      goto LABEL_14;
    }
LABEL_13:
    v5 = m_pFirst;
    m_pFirst = m_pFirst->pNextListItem;
LABEL_14:
    if ( v9 )
      v9->vfptr->Release(v9);
  }
}

// File Line: 2274
// RVA: 0xA4A960
void __fastcall CAkAudioMgr::RemovePausedPendingAction(CAkAudioMgr *this, CAkParameterNodeBase *in_pNodeToTarget)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // r15
  AkPendingAction *item; // r14
  CAkParameterNodeBase *v7; // rax
  CAkParameterNodeBase *v8; // rsi
  CAkParameterNodeBase *m_pParentNode; // rdx
  CAkParameterNodeBase *m_pBusOutputNode; // rcx
  CAkActionPlayAndContinue *pAction; // rcx
  int m_eActionType; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rax
  int v14; // ebx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v15; // [rsp+20h] [rbp-88h]
  int v16[20]; // [rsp+40h] [rbp-68h] BYREF

  m_pFirst = this->m_mmapPausedPending.m_pFirst;
  v5 = 0i64;
  while ( m_pFirst )
  {
    item = m_pFirst->Item.item;
    v7 = CAkAction::GetAndRefTarget(item->pAction);
    v8 = v7;
    if ( in_pNodeToTarget && v7 )
    {
      if ( in_pNodeToTarget == v7 )
        goto LABEL_18;
      m_pParentNode = v7->m_pParentNode;
      m_pBusOutputNode = v7->m_pBusOutputNode;
      if ( m_pParentNode )
      {
        while ( in_pNodeToTarget != m_pParentNode )
        {
          if ( !m_pBusOutputNode )
            m_pBusOutputNode = m_pParentNode->m_pBusOutputNode;
          m_pParentNode = m_pParentNode->m_pParentNode;
          if ( !m_pParentNode )
            goto LABEL_10;
        }
LABEL_18:
        pAction = (CAkActionPlayAndContinue *)item->pAction;
        v16[0] = 0;
        m_eActionType = pAction->m_eActionType;
        if ( m_eActionType == 1027 )
        {
LABEL_21:
          ((void (__fastcall *)(CAkAction *, int *))item->pAction->vfptr[2].Category)(item->pAction, v16);
        }
        else if ( m_eActionType == 1283 )
        {
          CAkActionPlayAndContinue::NeedNotifyDelay(pAction);
          goto LABEL_21;
        }
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, item->UserParam.m_PlayingID);
        pNextListItem = m_pFirst->pNextListItem;
        v15 = m_pFirst->pNextListItem;
        if ( m_pFirst == this->m_mmapPausedPending.m_pFirst )
          this->m_mmapPausedPending.m_pFirst = pNextListItem;
        else
          v5->pNextListItem = pNextListItem;
        if ( m_pFirst == this->m_mmapPausedPending.m_pLast )
          this->m_mmapPausedPending.m_pLast = v5;
        m_pFirst->pNextListItem = this->m_mmapPausedPending.m_pFree;
        --this->m_mmapPausedPending.m_ulNumListItems;
        this->m_mmapPausedPending.m_pFree = m_pFirst;
        item->pAction->vfptr->Release(item->pAction);
        v14 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))item->vfptr[1].TransUpdateValue)(item, 0i64);
        AK::MemoryMgr::Free(v14, item);
        m_pFirst = v15;
        goto LABEL_14;
      }
LABEL_10:
      if ( m_pBusOutputNode )
      {
        while ( in_pNodeToTarget != m_pBusOutputNode )
        {
          m_pBusOutputNode = m_pBusOutputNode->m_pBusOutputNode;
          if ( !m_pBusOutputNode )
            goto LABEL_13;
        }
        goto LABEL_18;
      }
    }
LABEL_13:
    v5 = m_pFirst;
    m_pFirst = m_pFirst->pNextListItem;
LABEL_14:
    if ( v8 )
      v8->vfptr->Release(v8);
  }
}

// File Line: 2305
// RVA: 0xA4A5D0
void __fastcall CAkAudioMgr::RemoveAllPausedPendingAction(CAkAudioMgr *this)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rdi
  AkPendingAction *item; // rsi
  CAkActionPlayAndContinue *pAction; // rcx
  int m_eActionType; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rbp
  int v7; // edi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v8; // [rsp+20h] [rbp-88h]
  int v9[20]; // [rsp+40h] [rbp-68h] BYREF

  if ( this->m_mmapPausedPending.m_ulMaxNumListItems )
  {
    m_pFirst = this->m_mmapPausedPending.m_pFirst;
    if ( m_pFirst )
    {
      while ( 1 )
      {
        item = m_pFirst->Item.item;
        v9[0] = 0;
        pAction = (CAkActionPlayAndContinue *)item->pAction;
        m_eActionType = pAction->m_eActionType;
        if ( m_eActionType != 1027 )
        {
          if ( m_eActionType != 1283 )
            goto LABEL_7;
          CAkActionPlayAndContinue::NeedNotifyDelay(pAction);
        }
        ((void (__fastcall *)(CAkAction *, int *))item->pAction->vfptr[2].Category)(item->pAction, v9);
LABEL_7:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, item->UserParam.m_PlayingID);
        pNextListItem = m_pFirst->pNextListItem;
        v8 = m_pFirst->pNextListItem;
        if ( m_pFirst == this->m_mmapPausedPending.m_pFirst )
          this->m_mmapPausedPending.m_pFirst = pNextListItem;
        else
          MEMORY[0] = (size_t)m_pFirst->pNextListItem;
        if ( m_pFirst == this->m_mmapPausedPending.m_pLast )
          this->m_mmapPausedPending.m_pLast = 0i64;
        m_pFirst->pNextListItem = this->m_mmapPausedPending.m_pFree;
        --this->m_mmapPausedPending.m_ulNumListItems;
        this->m_mmapPausedPending.m_pFree = m_pFirst;
        item->pAction->vfptr->Release(item->pAction);
        v7 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))item->vfptr[1].TransUpdateValue)(item, 0i64);
        AK::MemoryMgr::Free(v7, item);
        if ( !pNextListItem )
          return;
        m_pFirst = v8;
      }
    }
  }
}

// File Line: 2331
// RVA: 0xA4A720
void __fastcall CAkAudioMgr::RemoveAllPendingAction(CAkAudioMgr *this)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rdi
  AkPendingAction *item; // rsi
  CAkActionPlayAndContinue *pAction; // rcx
  int m_eActionType; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rbp
  int v7; // edi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v8; // [rsp+20h] [rbp-88h]
  int v9[20]; // [rsp+40h] [rbp-68h] BYREF

  if ( this->m_mmapPending.m_ulMaxNumListItems )
  {
    m_pFirst = this->m_mmapPending.m_pFirst;
    if ( m_pFirst )
    {
      while ( 1 )
      {
        item = m_pFirst->Item.item;
        v9[0] = 0;
        pAction = (CAkActionPlayAndContinue *)item->pAction;
        m_eActionType = pAction->m_eActionType;
        if ( m_eActionType != 1027 )
        {
          if ( m_eActionType != 1283 )
            goto LABEL_7;
          CAkActionPlayAndContinue::NeedNotifyDelay(pAction);
        }
        ((void (__fastcall *)(CAkAction *, int *))item->pAction->vfptr[2].Category)(item->pAction, v9);
LABEL_7:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, item->UserParam.m_PlayingID);
        pNextListItem = m_pFirst->pNextListItem;
        v8 = m_pFirst->pNextListItem;
        if ( m_pFirst == this->m_mmapPending.m_pFirst )
          this->m_mmapPending.m_pFirst = pNextListItem;
        else
          MEMORY[0] = (size_t)m_pFirst->pNextListItem;
        if ( m_pFirst == this->m_mmapPending.m_pLast )
          this->m_mmapPending.m_pLast = 0i64;
        m_pFirst->pNextListItem = this->m_mmapPending.m_pFree;
        --this->m_mmapPending.m_ulNumListItems;
        this->m_mmapPending.m_pFree = m_pFirst;
        item->pAction->vfptr->Release(item->pAction);
        v7 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))item->vfptr[1].TransUpdateValue)(item, 0i64);
        AK::MemoryMgr::Free(v7, item);
        if ( !pNextListItem )
          return;
        m_pFirst = v8;
      }
    }
  }
}

// File Line: 2359
// RVA: 0xA4A850
void __fastcall CAkAudioMgr::RemoveAllPreallocAndReferences(CAkAudioMgr *this)
{
  char *v2; // rax
  char *v3; // rbx
  AkExternalSourceArray *v4; // rcx

  EnterCriticalSection(&this->m_queueLock.m_csLock);
  while ( this->m_MsgQueue.m_uReadBlock != this->m_MsgQueue.m_uWriteBlock
       || this->m_MsgQueue.m_uReadOffset != this->m_MsgQueue.m_uWriteOffset
       || this->m_MsgQueue.m_bBufferFull )
  {
    v2 = AkSparseChunkRing::BeginRead(&this->m_MsgQueue);
    v3 = v2;
    switch ( *((_WORD *)v2 + 1) )
    {
      case 1:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, *((_DWORD *)v2 + 4));
        (*(void (__fastcall **)(_QWORD))(**((_QWORD **)v3 + 6) + 16i64))(*((_QWORD *)v3 + 6));
        v4 = (AkExternalSourceArray *)*((_QWORD *)v3 + 5);
        if ( v4 )
          AkExternalSourceArray::Release(v4);
LABEL_16:
        AkSparseChunkRing::EndRead(&this->m_MsgQueue, *(unsigned __int16 *)v3);
        break;
      case 0xB:
        goto LABEL_16;
      case 0x17:
        if ( *((_DWORD *)v2 + 4) == 3 )
        {
          CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, *(_DWORD *)(*((_QWORD *)v2 + 1) + 120i64));
          (*(void (__fastcall **)(_QWORD))(**((_QWORD **)v3 + 1) + 16i64))(*((_QWORD *)v3 + 1));
        }
        (*(void (__fastcall **)(_QWORD))(**((_QWORD **)v3 + 1) + 16i64))(*((_QWORD *)v3 + 1));
        AkSparseChunkRing::EndRead(&this->m_MsgQueue, *(unsigned __int16 *)v3);
        break;
      case 0x1F:
      case 0x23:
        (*(void (__fastcall **)(_QWORD))(**((_QWORD **)v2 + 1) + 16i64))(*((_QWORD *)v2 + 1));
        AkSparseChunkRing::EndRead(&this->m_MsgQueue, *(unsigned __int16 *)v3);
        break;
      default:
        goto LABEL_16;
    }
  }
  LeaveCriticalSection(&this->m_queueLock.m_csLock);
}

// File Line: 2545
// RVA: 0xA4B540
__int64 __fastcall CAkAudioMgr::StopAction(CAkAudioMgr *this, unsigned int in_ActionID, unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rdi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v7; // r14
  AkPendingAction *item; // rsi
  CAkActionPlayAndContinue *pAction; // rcx
  int m_eActionType; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rax
  int v12; // edi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v13; // rdi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v14; // r14
  AkPendingAction *v15; // rsi
  CAkActionPlayAndContinue *v16; // rcx
  int v17; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v18; // rax
  int v19; // edi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v21; // [rsp+20h] [rbp-88h]
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v22; // [rsp+30h] [rbp-78h]
  int v23[20]; // [rsp+40h] [rbp-68h] BYREF

  m_pFirst = this->m_mmapPending.m_pFirst;
  v7 = 0i64;
  if ( m_pFirst )
  {
    while ( 1 )
    {
      item = m_pFirst->Item.item;
      pAction = (CAkActionPlayAndContinue *)item->pAction;
      if ( pAction->key == in_ActionID && (!in_PlayingID || item->UserParam.m_PlayingID == in_PlayingID) )
        break;
      v7 = m_pFirst;
      m_pFirst = m_pFirst->pNextListItem;
LABEL_16:
      if ( !m_pFirst )
        goto LABEL_17;
    }
    v23[0] = 0;
    m_eActionType = pAction->m_eActionType;
    if ( m_eActionType != 1027 )
    {
      if ( m_eActionType != 1283 )
      {
LABEL_9:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, item->UserParam.m_PlayingID);
        pNextListItem = m_pFirst->pNextListItem;
        v21 = m_pFirst->pNextListItem;
        if ( m_pFirst == this->m_mmapPending.m_pFirst )
          this->m_mmapPending.m_pFirst = pNextListItem;
        else
          v7->pNextListItem = pNextListItem;
        if ( m_pFirst == this->m_mmapPending.m_pLast )
          this->m_mmapPending.m_pLast = v7;
        m_pFirst->pNextListItem = this->m_mmapPending.m_pFree;
        --this->m_mmapPending.m_ulNumListItems;
        this->m_mmapPending.m_pFree = m_pFirst;
        item->pAction->vfptr->Release(item->pAction);
        v12 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))item->vfptr[1].TransUpdateValue)(item, 0i64);
        AK::MemoryMgr::Free(v12, item);
        m_pFirst = v21;
        goto LABEL_16;
      }
      CAkActionPlayAndContinue::NeedNotifyDelay(pAction);
    }
    ((void (__fastcall *)(CAkIndexableVtbl **, int *))item->pAction->vfptr[2].Category)(&item->pAction->vfptr, v23);
    goto LABEL_9;
  }
LABEL_17:
  v13 = this->m_mmapPausedPending.m_pFirst;
  v14 = 0i64;
  if ( v13 )
  {
    while ( 1 )
    {
      v15 = v13->Item.item;
      v16 = (CAkActionPlayAndContinue *)v15->pAction;
      if ( v16->key == in_ActionID && (!in_PlayingID || v15->UserParam.m_PlayingID == in_PlayingID) )
        break;
      v14 = v13;
      v13 = v13->pNextListItem;
LABEL_32:
      if ( !v13 )
        return 1i64;
    }
    v23[0] = 0;
    v17 = v16->m_eActionType;
    if ( v17 != 1027 )
    {
      if ( v17 != 1283 )
      {
LABEL_25:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v15->UserParam.m_PlayingID);
        v18 = v13->pNextListItem;
        v22 = v13->pNextListItem;
        if ( v13 == this->m_mmapPausedPending.m_pFirst )
          this->m_mmapPausedPending.m_pFirst = v18;
        else
          v14->pNextListItem = v18;
        if ( v13 == this->m_mmapPausedPending.m_pLast )
          this->m_mmapPausedPending.m_pLast = v14;
        v13->pNextListItem = this->m_mmapPausedPending.m_pFree;
        --this->m_mmapPausedPending.m_ulNumListItems;
        this->m_mmapPausedPending.m_pFree = v13;
        v15->pAction->vfptr->Release(v15->pAction);
        v19 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))v15->vfptr[1].TransUpdateValue)(v15, 0i64);
        AK::MemoryMgr::Free(v19, v15);
        v13 = v22;
        goto LABEL_32;
      }
      CAkActionPlayAndContinue::NeedNotifyDelay(v16);
    }
    ((void (__fastcall *)(CAkIndexableVtbl **, int *))v15->pAction->vfptr[2].Category)(&v15->pAction->vfptr, v23);
    goto LABEL_25;
  }
  return 1i64;
}

// File Line: 2588
// RVA: 0xA485E0
__int64 __fastcall CAkAudioMgr::PauseAction(CAkAudioMgr *this, unsigned int in_ActionID, unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *i; // rax
  AkPendingAction *item; // r9
  __int128 m_pFirst; // rdi
  AkPendingAction *v9; // r8
  CAkAction *pAction; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v11; // rax
  __int128 v13; // [rsp+20h] [rbp-28h]

  for ( i = this->m_mmapPausedPending.m_pFirst; i; i = i->pNextListItem )
  {
    item = i->Item.item;
    if ( in_ActionID == item->pAction->key && (!in_PlayingID || item->UserParam.m_PlayingID == in_PlayingID) )
      ++item->ulPauseCount;
  }
  m_pFirst = (unsigned __int64)this->m_mmapPending.m_pFirst;
  while ( (_QWORD)m_pFirst )
  {
    v9 = *(AkPendingAction **)(m_pFirst + 16);
    pAction = v9->pAction;
    if ( in_ActionID == pAction->key && (!in_PlayingID || v9->UserParam.m_PlayingID == in_PlayingID) )
    {
      CAkAudioMgr::InsertAsPaused(this, pAction->m_ulElementID, v9, 0);
      v11 = *(CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem **)m_pFirst;
      *((_QWORD *)&v13 + 1) = *((_QWORD *)&m_pFirst + 1);
      *(_QWORD *)&v13 = *(_QWORD *)m_pFirst;
      if ( (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)m_pFirst == this->m_mmapPending.m_pFirst )
        this->m_mmapPending.m_pFirst = v11;
      else
        **((_QWORD **)&m_pFirst + 1) = v11;
      if ( (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)m_pFirst == this->m_mmapPending.m_pLast )
        this->m_mmapPending.m_pLast = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)*((_QWORD *)&m_pFirst + 1);
      *(_QWORD *)m_pFirst = this->m_mmapPending.m_pFree;
      --this->m_mmapPending.m_ulNumListItems;
      this->m_mmapPending.m_pFree = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)m_pFirst;
      m_pFirst = v13;
    }
    else
    {
      *((_QWORD *)&m_pFirst + 1) = m_pFirst;
      *(_QWORD *)&m_pFirst = *(_QWORD *)m_pFirst;
    }
  }
  return 1i64;
}

// File Line: 2640
// RVA: 0xA4AD40
__int64 __fastcall CAkAudioMgr::ResumeAction(CAkAudioMgr *this, unsigned int in_ActionID, unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v4; // rsi
  AkPendingAction *item; // rcx
  unsigned int ulPauseCount; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v12; // [rsp+20h] [rbp-28h]

  m_pFirst = this->m_mmapPausedPending.m_pFirst;
  v4 = 0i64;
  while ( m_pFirst )
  {
    item = m_pFirst->Item.item;
    if ( item->pAction->key == in_ActionID && (!in_PlayingID || item->UserParam.m_PlayingID == in_PlayingID) )
    {
      ulPauseCount = item->ulPauseCount;
      if ( !ulPauseCount )
      {
        CAkAudioMgr::TransferToPending(this, m_pFirst->Item.item);
        pNextListItem = m_pFirst->pNextListItem;
        v12 = m_pFirst->pNextListItem;
        if ( m_pFirst == this->m_mmapPausedPending.m_pFirst )
          this->m_mmapPausedPending.m_pFirst = pNextListItem;
        else
          v4->pNextListItem = pNextListItem;
        if ( m_pFirst == this->m_mmapPausedPending.m_pLast )
          this->m_mmapPausedPending.m_pLast = v4;
        m_pFirst->pNextListItem = this->m_mmapPausedPending.m_pFree;
        --this->m_mmapPausedPending.m_ulNumListItems;
        this->m_mmapPausedPending.m_pFree = m_pFirst;
        m_pFirst = v12;
        continue;
      }
      item->ulPauseCount = ulPauseCount - 1;
    }
    v4 = m_pFirst;
    m_pFirst = m_pFirst->pNextListItem;
  }
  return 1i64;
}

// File Line: 2680
// RVA: 0xA47D60
void __fastcall CAkAudioMgr::ClearPendingItems(CAkAudioMgr *this, unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rdi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // r14
  AkPendingAction *item; // rsi
  CAkActionPlayAndContinue *pAction; // rcx
  int m_eActionType; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rax
  int v10; // edi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v11; // rdi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v12; // r14
  AkPendingAction *v13; // rsi
  CAkActionPlayAndContinue *v14; // rcx
  int v15; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v16; // rax
  int v17; // edi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v18; // [rsp+20h] [rbp-88h]
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v19; // [rsp+30h] [rbp-78h]
  int v20[20]; // [rsp+40h] [rbp-68h] BYREF

  m_pFirst = this->m_mmapPending.m_pFirst;
  v5 = 0i64;
  if ( m_pFirst )
  {
    while ( 1 )
    {
      item = m_pFirst->Item.item;
      if ( item->UserParam.m_PlayingID == in_PlayingID )
        break;
      v5 = m_pFirst;
      m_pFirst = m_pFirst->pNextListItem;
LABEL_14:
      if ( !m_pFirst )
        goto LABEL_15;
    }
    pAction = (CAkActionPlayAndContinue *)item->pAction;
    v20[0] = 0;
    m_eActionType = pAction->m_eActionType;
    if ( m_eActionType != 1027 )
    {
      if ( m_eActionType != 1283 )
      {
LABEL_7:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, item->UserParam.m_PlayingID);
        pNextListItem = m_pFirst->pNextListItem;
        v18 = m_pFirst->pNextListItem;
        if ( m_pFirst == this->m_mmapPending.m_pFirst )
          this->m_mmapPending.m_pFirst = pNextListItem;
        else
          v5->pNextListItem = pNextListItem;
        if ( m_pFirst == this->m_mmapPending.m_pLast )
          this->m_mmapPending.m_pLast = v5;
        m_pFirst->pNextListItem = this->m_mmapPending.m_pFree;
        --this->m_mmapPending.m_ulNumListItems;
        this->m_mmapPending.m_pFree = m_pFirst;
        item->pAction->vfptr->Release(item->pAction);
        v10 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))item->vfptr[1].TransUpdateValue)(item, 0i64);
        AK::MemoryMgr::Free(v10, item);
        m_pFirst = v18;
        goto LABEL_14;
      }
      CAkActionPlayAndContinue::NeedNotifyDelay(pAction);
    }
    ((void (__fastcall *)(CAkIndexableVtbl **, int *))item->pAction->vfptr[2].Category)(&item->pAction->vfptr, v20);
    goto LABEL_7;
  }
LABEL_15:
  v11 = this->m_mmapPausedPending.m_pFirst;
  v12 = 0i64;
  if ( v11 )
  {
    while ( 1 )
    {
      v13 = v11->Item.item;
      if ( v13->UserParam.m_PlayingID == in_PlayingID )
        break;
      v12 = v11;
      v11 = v11->pNextListItem;
LABEL_28:
      if ( !v11 )
        return;
    }
    v14 = (CAkActionPlayAndContinue *)v13->pAction;
    v20[0] = 0;
    v15 = v14->m_eActionType;
    if ( v15 != 1027 )
    {
      if ( v15 != 1283 )
      {
LABEL_21:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v13->UserParam.m_PlayingID);
        v16 = v11->pNextListItem;
        v19 = v11->pNextListItem;
        if ( v11 == this->m_mmapPausedPending.m_pFirst )
          this->m_mmapPausedPending.m_pFirst = v16;
        else
          v12->pNextListItem = v16;
        if ( v11 == this->m_mmapPausedPending.m_pLast )
          this->m_mmapPausedPending.m_pLast = v12;
        v11->pNextListItem = this->m_mmapPausedPending.m_pFree;
        --this->m_mmapPausedPending.m_ulNumListItems;
        this->m_mmapPausedPending.m_pFree = v11;
        v13->pAction->vfptr->Release(v13->pAction);
        v17 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))v13->vfptr[1].TransUpdateValue)(v13, 0i64);
        AK::MemoryMgr::Free(v17, v13);
        v11 = v19;
        goto LABEL_28;
      }
      CAkActionPlayAndContinue::NeedNotifyDelay(v14);
    }
    ((void (__fastcall *)(CAkIndexableVtbl **, int *))v13->pAction->vfptr[2].Category)(&v13->pAction->vfptr, v20);
    goto LABEL_21;
  }
}

// File Line: 2798
// RVA: 0xA47CC0
void __fastcall CAkAudioMgr::ClearCrossFadeOccurence(CAkAudioMgr *this, CAkContinuousPBI *in_pPBIToCheck)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *i; // rbx
  CAkActionPlayAndContinue *pAction; // rcx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *j; // rbx
  CAkActionPlayAndContinue *v7; // rcx

  for ( i = this->m_mmapPending.m_pFirst; i; i = i->pNextListItem )
  {
    pAction = (CAkActionPlayAndContinue *)i->Item.item->pAction;
    if ( pAction->m_eActionType == 1283 )
      CAkActionPlayAndContinue::UnsetFadeBack(pAction, in_pPBIToCheck);
  }
  for ( j = this->m_mmapPausedPending.m_pFirst; j; j = j->pNextListItem )
  {
    v7 = (CAkActionPlayAndContinue *)j->Item.item->pAction;
    if ( v7->m_eActionType == 1283 )
      CAkActionPlayAndContinue::UnsetFadeBack(v7, in_pPBIToCheck);
  }
}

// File Line: 2831
// RVA: 0xA48420
char __fastcall CAkAudioMgr::IsAnException(
        CAkAudioMgr *this,
        CAkAction *in_pAction,
        AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *in_pExceptionList)
{
  CAkParameterNodeBase *m_pBusOutputNode; // rbx
  bool v6; // di
  CAkParameterNodeBase *v7; // r8
  CAkParameterNodeBase *v8; // r11
  WwiseObjectIDext *m_pItems; // r10
  WwiseObjectIDext *v10; // rdx
  WwiseObjectIDext *v11; // rcx
  WwiseObjectIDext *v12; // rax

  if ( !in_pExceptionList )
    return 0;
  m_pBusOutputNode = 0i64;
  v6 = 0;
  if ( !in_pAction->m_ulElementID )
    return 0;
  v7 = CAkAction::GetAndRefTarget(in_pAction);
  v8 = v7;
  if ( !v7 )
    return 0;
  m_pItems = in_pExceptionList->m_pItems;
  v10 = &in_pExceptionList->m_pItems[in_pExceptionList->m_uLength];
  do
  {
    v11 = in_pExceptionList->m_pItems;
    if ( m_pItems != v10 )
    {
      while ( v7->key != v11->id || ((*((_BYTE *)v7 + 83) & 2) != 0) != v11->bIsBus )
      {
        if ( ++v11 == v10 )
          goto LABEL_10;
      }
      goto LABEL_21;
    }
LABEL_10:
    if ( !v6 )
    {
      m_pBusOutputNode = v7->m_pBusOutputNode;
      v6 = m_pBusOutputNode != 0i64;
    }
    v7 = v7->m_pParentNode;
  }
  while ( v7 );
  if ( !m_pBusOutputNode )
  {
LABEL_19:
    v8->vfptr->Release(v8);
    return 0;
  }
  while ( 1 )
  {
    v12 = in_pExceptionList->m_pItems;
    if ( m_pItems != v10 )
      break;
LABEL_18:
    m_pBusOutputNode = m_pBusOutputNode->m_pBusOutputNode;
    if ( !m_pBusOutputNode )
      goto LABEL_19;
  }
  while ( m_pBusOutputNode->key != v12->id || ((*((_BYTE *)m_pBusOutputNode + 83) & 2) != 0) != v12->bIsBus )
  {
    if ( ++v12 == v10 )
      goto LABEL_18;
  }
LABEL_21:
  v8->vfptr->Release(v8);
  return 1;
}

// File Line: 2960
// RVA: 0xA4B4E0
AKRESULT __fastcall CAkAudioMgr::Start(CAkAudioMgr *this)
{
  HANDLE EventW; // rax

  EventW = CreateEventW(0i64, 1, 0, 0i64);
  this->m_hEventMgrThreadDrainEvent.m_Event = EventW;
  if ( EventW )
    return CAkAudioThread::Start(&this->m_audioThread);
  else
    return 2;
}

// File Line: 2971
// RVA: 0xA4B530
void __fastcall CAkAudioMgr::Stop(CAkAudioMgr *this)
{
  CAkAudioThread::Stop(&this->m_audioThread);
}

// File Line: 2981
// RVA: 0xA47770
void __fastcall AkPendingAction::AkPendingAction(AkPendingAction *this, CAkRegisteredObj *in_pGameObj)
{
  this->vfptr = (ITransitionableVtbl *)&AkPendingAction::`vftable;
  this->UserParam.m_PlayingID = 0;
  this->UserParam.m_CustomParam.customParam = 0i64;
  this->UserParam.m_CustomParam.ui32Reserved = 0;
  this->UserParam.m_CustomParam.pExternalSrcs = 0i64;
  this->TargetPlayingID = 0;
  this->pGameObj = in_pGameObj;
  if ( in_pGameObj )
    *((_DWORD *)in_pGameObj + 30) ^= (*((_DWORD *)in_pGameObj + 30) ^ (*((_DWORD *)in_pGameObj + 30) + 1)) & 0x3FFFFFFF;
}

// File Line: 2987
// RVA: 0xA47830
void __fastcall AkPendingAction::~AkPendingAction(AkPendingAction *this)
{
  CAkRegisteredObj *pGameObj; // rdi
  int v3; // r8d
  int v4; // ebx
  AkExternalSourceArray *pExternalSrcs; // rcx

  pGameObj = this->pGameObj;
  this->vfptr = (ITransitionableVtbl *)&AkPendingAction::`vftable;
  if ( pGameObj )
  {
    v3 = *((_DWORD *)pGameObj + 30) ^ (*((_DWORD *)pGameObj + 30) ^ (*((_DWORD *)pGameObj + 30) - 1)) & 0x3FFFFFFF;
    *((_DWORD *)pGameObj + 30) = v3;
    if ( (v3 & 0x3FFFFFFF) == 0 )
    {
      v4 = g_DefaultPoolId;
      CAkRegisteredObj::~CAkRegisteredObj(pGameObj);
      AK::MemoryMgr::Free(v4, pGameObj);
    }
  }
  pExternalSrcs = this->UserParam.m_CustomParam.pExternalSrcs;
  if ( pExternalSrcs )
    AkExternalSourceArray::Release(pExternalSrcs);
}

// File Line: 2998
// RVA: 0xA4C0A0
void __fastcall AkPendingAction::TransUpdateValue(
        AkPendingAction *this,
        __int64 in_eTarget,
        float __formal,
        bool in_bIsTerminated)
{
  CAkAction *pAction; // rbx

  pAction = this->pAction;
  if ( pAction->m_eActionType == 1283 )
  {
    if ( (((_DWORD)in_eTarget - 0x1000000) & 0xFEFFFFFF) != 0 )
    {
      if ( (((_DWORD)in_eTarget - 0x4000000) & 0xFBFFFFFF) == 0 && in_bIsTerminated )
      {
        LOBYTE(pAction[1].pNextLightItem) &= ~2u;
        *(_QWORD *)&pAction[1].key = 0i64;
        if ( (_DWORD)in_eTarget == 0x4000000 )
          CAkAudioMgr::PausePending(g_pAudioMgr, this);
        LODWORD(pAction[4].pNextItem) = 0;
      }
    }
    else if ( in_bIsTerminated )
    {
      LOBYTE(pAction[1].pNextLightItem) &= ~1u;
      pAction[1].pNextItem = 0i64;
      if ( (_DWORD)in_eTarget == 0x2000000 )
        CAkAudioMgr::StopPending(g_pAudioMgr, this);
    }
  }
}

// File Line: 3049
// RVA: 0xA486E0
__int64 __fastcall CAkAudioMgr::PausePending(CAkAudioMgr *this, AkPendingAction *in_pPA)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v4; // rsi
  AkPendingAction *item; // r8
  CAkAction *pAction; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v7; // rax
  AkPendingAction *v8; // rcx
  CAkAction *v9; // r8
  unsigned int v10; // r9d
  int pNextItem; // r9d
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rax

  if ( in_pPA )
  {
    m_pFirst = this->m_mmapPending.m_pFirst;
    v4 = 0i64;
    if ( m_pFirst )
    {
      while ( 1 )
      {
        item = m_pFirst->Item.item;
        pAction = item->pAction;
        if ( item == in_pPA )
          break;
        v4 = m_pFirst;
        m_pFirst = m_pFirst->pNextListItem;
        if ( !m_pFirst )
          goto LABEL_5;
      }
      v10 = 0;
      if ( pAction->m_eActionType == 1283 )
      {
        pNextItem = (int)pAction[4].pNextItem;
        LODWORD(pAction[4].pNextItem) = 0;
        v10 = pNextItem - 1;
      }
      CAkAudioMgr::InsertAsPaused(this, pAction->m_ulElementID, item, v10);
      pNextListItem = m_pFirst->pNextListItem;
      if ( m_pFirst == this->m_mmapPending.m_pFirst )
        this->m_mmapPending.m_pFirst = pNextListItem;
      else
        v4->pNextListItem = pNextListItem;
      if ( m_pFirst == this->m_mmapPending.m_pLast )
        this->m_mmapPending.m_pLast = v4;
      m_pFirst->pNextListItem = this->m_mmapPending.m_pFree;
      --this->m_mmapPending.m_ulNumListItems;
      this->m_mmapPending.m_pFree = m_pFirst;
    }
    else
    {
LABEL_5:
      v7 = this->m_mmapPausedPending.m_pFirst;
      if ( v7 )
      {
        while ( 1 )
        {
          v8 = v7->Item.item;
          v9 = v8->pAction;
          if ( v8 == in_pPA )
            break;
          v7 = v7->pNextListItem;
          if ( !v7 )
            return 1i64;
        }
        if ( v9->m_eActionType == 1283 )
          v8->ulPauseCount += LODWORD(v9[4].pNextItem);
        else
          ++v8->ulPauseCount;
      }
    }
  }
  return 1i64;
}

// File Line: 3103
// RVA: 0xA4B790
__int64 __fastcall CAkAudioMgr::StopPending(CAkAudioMgr *this, AkPendingAction *in_pPA)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // r14
  CAkActionPlayAndContinue *pAction; // rcx
  int m_eActionType; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rax
  int v9; // ebx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v10; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v11; // r14
  CAkActionPlayAndContinue *v12; // rcx
  int v13; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v14; // rax
  int v15; // ebx
  int v17[22]; // [rsp+20h] [rbp-58h] BYREF

  if ( !in_pPA )
    return 1i64;
  m_pFirst = this->m_mmapPausedPending.m_pFirst;
  v5 = 0i64;
  if ( m_pFirst )
  {
    while ( in_pPA != m_pFirst->Item.item )
    {
      v5 = m_pFirst;
      m_pFirst = m_pFirst->pNextListItem;
      if ( !m_pFirst )
        goto LABEL_16;
    }
    pAction = (CAkActionPlayAndContinue *)in_pPA->pAction;
    v17[0] = 0;
    m_eActionType = pAction->m_eActionType;
    if ( m_eActionType != 1027 )
    {
      if ( m_eActionType != 1283 )
      {
LABEL_10:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, in_pPA->UserParam.m_PlayingID);
        pNextListItem = m_pFirst->pNextListItem;
        if ( m_pFirst == this->m_mmapPausedPending.m_pFirst )
          this->m_mmapPausedPending.m_pFirst = pNextListItem;
        else
          v5->pNextListItem = pNextListItem;
        if ( m_pFirst == this->m_mmapPausedPending.m_pLast )
          this->m_mmapPausedPending.m_pLast = v5;
        m_pFirst->pNextListItem = this->m_mmapPausedPending.m_pFree;
        --this->m_mmapPausedPending.m_ulNumListItems;
        this->m_mmapPausedPending.m_pFree = m_pFirst;
        in_pPA->pAction->vfptr->Release(in_pPA->pAction);
        v9 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))in_pPA->vfptr[1].TransUpdateValue)(in_pPA, 0i64);
        AK::MemoryMgr::Free(v9, in_pPA);
        goto LABEL_16;
      }
      CAkActionPlayAndContinue::NeedNotifyDelay(pAction);
    }
    ((void (__fastcall *)(CAkAction *, int *))in_pPA->pAction->vfptr[2].Category)(in_pPA->pAction, v17);
    goto LABEL_10;
  }
LABEL_16:
  v10 = this->m_mmapPending.m_pFirst;
  v11 = 0i64;
  if ( !v10 )
    return 1i64;
  while ( in_pPA != v10->Item.item )
  {
    v11 = v10;
    v10 = v10->pNextListItem;
    if ( !v10 )
      return 1i64;
  }
  v12 = (CAkActionPlayAndContinue *)in_pPA->pAction;
  v17[0] = 0;
  v13 = v12->m_eActionType;
  if ( v13 == 1027 )
    goto LABEL_23;
  if ( v13 == 1283 )
  {
    CAkActionPlayAndContinue::NeedNotifyDelay(v12);
LABEL_23:
    ((void (__fastcall *)(CAkAction *, int *))in_pPA->pAction->vfptr[2].Category)(in_pPA->pAction, v17);
  }
  CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, in_pPA->UserParam.m_PlayingID);
  v14 = v10->pNextListItem;
  if ( v10 == this->m_mmapPending.m_pFirst )
    this->m_mmapPending.m_pFirst = v14;
  else
    v11->pNextListItem = v14;
  if ( v10 == this->m_mmapPending.m_pLast )
    this->m_mmapPending.m_pLast = v11;
  v10->pNextListItem = this->m_mmapPending.m_pFree;
  --this->m_mmapPending.m_ulNumListItems;
  this->m_mmapPending.m_pFree = v10;
  in_pPA->pAction->vfptr->Release(in_pPA->pAction);
  v15 = g_DefaultPoolId;
  ((void (__fastcall *)(AkPendingAction *, _QWORD))in_pPA->vfptr[1].TransUpdateValue)(in_pPA, 0i64);
  AK::MemoryMgr::Free(v15, in_pPA);
  return 1i64;
}

