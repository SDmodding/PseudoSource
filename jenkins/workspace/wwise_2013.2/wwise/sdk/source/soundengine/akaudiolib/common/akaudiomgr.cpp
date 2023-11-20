// File Line: 127
// RVA: 0xA4B4C0
signed __int64 __fastcall UEL::ArgumentUsageExpression::GetClassSize()
{
  return 32i64;
}

// File Line: 128
// RVA: 0xA4B4D0
signed __int64 __fastcall Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_CreateTexture,Scaleform::Render::DICommand>::GetSize()
{
  return 16i64;
}

// File Line: 133
// RVA: 0xA4B4B0
signed __int64 __fastcall Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_GetColorBoundsRect,Scaleform::Render::DICommand>::GetSize()
{
  return 40i64;
}

// File Line: 177
// RVA: 0xA477B0
void __fastcall CAkAudioMgr::CAkAudioMgr(CAkAudioMgr *this)
{
  CAkAudioMgr *v1; // rbx

  v1 = this;
  InitializeCriticalSection(&this->m_queueLock.m_csLock);
  v1->m_MsgQueue.blocks.m_pItems = 0i64;
  *(_QWORD *)&v1->m_MsgQueue.blocks.m_uLength = 0i64;
  *(_QWORD *)&v1->m_MsgQueue.m_uReadBlock = 0i64;
  *(_QWORD *)&v1->m_MsgQueue.m_uWriteBlock = 0i64;
  v1->m_MsgQueue.m_bBufferFull = 0;
  v1->m_bDrainMsgQueue = 0;
  v1->m_MsgQueueActualSize = 0;
  *(_QWORD *)&v1->m_mmapPending.m_ulMinNumListItems = 0i64;
  v1->m_mmapPending.m_ulNumListItems = 0;
  *(_QWORD *)&v1->m_mmapPausedPending.m_ulMinNumListItems = 0i64;
  v1->m_mmapPausedPending.m_ulNumListItems = 0;
  *(_QWORD *)&v1->m_uBufferTick = 0i64;
  v1->m_ulReaderFlag = 0;
  CAkAudioThread::CAkAudioThread(&v1->m_audioThread);
  v1->m_hEventMgrThreadDrainEvent.m_Event = 0i64;
  v1->m_timeLastBuffer = 0i64;
  v1->m_uCallsWithoutTicks = 0;
}

// File Line: 191
// RVA: 0xA478C0
void __fastcall CAkAudioMgr::~CAkAudioMgr(CAkAudioMgr *this)
{
  CAkAudioMgr *v1; // rbx
  void *v2; // rcx

  v1 = this;
  v2 = this->m_hEventMgrThreadDrainEvent.m_Event;
  if ( v2 )
    CloseHandle(v2);
  DeleteCriticalSection(&v1->m_queueLock.m_csLock);
}

// File Line: 195
// RVA: 0xA48140
signed __int64 __fastcall CAkAudioMgr::Init(CAkAudioMgr *this)
{
  CAkAudioMgr *v1; // rdi
  unsigned int v2; // ebx
  unsigned int v3; // eax
  signed __int64 result; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // rax
  unsigned int v6; // ebx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v7; // rcx
  unsigned int v8; // edx
  signed __int64 v9; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v10; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v11; // rcx
  unsigned int v12; // edx
  signed __int64 v13; // rax

  v1 = this;
  *(_QWORD *)&this->m_ulWriterFlag = 0i64;
  v2 = unk_14249E978;
  v3 = AkSparseChunkRing::GetChunkSize();
  result = AkSparseChunkRing::Init(&v1->m_MsgQueue, v2 / v3);
  if ( (_DWORD)result == 1 )
  {
    v1->m_mmapPending.m_ulNumListItems = 0;
    v1->m_mmapPending.m_ulMaxNumListItems = -1;
    v1->m_mmapPending.m_pFree = 0i64;
    v5 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x300ui64);
    v6 = 52;
    v7 = v5;
    v1->m_mmapPending.m_pvMemStart = v5;
    if ( v5 )
    {
      v1->m_mmapPending.m_ulMinNumListItems = 32;
      v1->m_mmapPending.m_pFree = v5;
      v8 = 0;
      do
      {
        v9 = (signed __int64)&v7[1];
        ++v8;
        v7->pNextListItem = v7 + 1;
        ++v7;
      }
      while ( v8 < v1->m_mmapPending.m_ulMinNumListItems );
      *(_QWORD *)(v9 - 24) = 0i64;
      result = 1i64;
    }
    else
    {
      result = 52i64;
    }
    v1->m_mmapPending.m_pFirst = 0i64;
    v1->m_mmapPending.m_pLast = 0i64;
    if ( (_DWORD)result == 1 )
    {
      v1->m_mmapPausedPending.m_ulNumListItems = 0;
      v1->m_mmapPausedPending.m_ulMaxNumListItems = -1;
      v1->m_mmapPausedPending.m_pFree = 0i64;
      v10 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x300ui64);
      v11 = v10;
      v1->m_mmapPausedPending.m_pvMemStart = v10;
      if ( v10 )
      {
        v1->m_mmapPausedPending.m_ulMinNumListItems = 32;
        v1->m_mmapPausedPending.m_pFree = v10;
        v12 = 0;
        do
        {
          v13 = (signed __int64)&v11[1];
          ++v12;
          v11->pNextListItem = v11 + 1;
          ++v11;
        }
        while ( v12 < v1->m_mmapPausedPending.m_ulMinNumListItems );
        *(_QWORD *)(v13 - 24) = 0i64;
        v6 = 1;
      }
      v1->m_mmapPausedPending.m_pFirst = 0i64;
      v1->m_mmapPausedPending.m_pLast = 0i64;
      result = v6;
    }
  }
  return result;
}

// File Line: 216
// RVA: 0xA4C050
void __fastcall CAkAudioMgr::Term(CAkAudioMgr *this)
{
  CAkAudioMgr *v1; // rbx

  v1 = this;
  CAkAudioThread::Stop(&this->m_audioThread);
  CAkAudioMgr::RemoveAllPreallocAndReferences(v1);
  CAkAudioMgr::RemoveAllPausedPendingAction(v1);
  CAkAudioMgr::RemoveAllPendingAction(v1);
  AkSparseChunkRing::Term(&v1->m_MsgQueue);
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::Term((CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault> *)&v1->m_mmapPending);
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::Term((CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault> *)&v1->m_mmapPausedPending);
}

// File Line: 240
// RVA: 0xA4ACB0
signed __int64 __fastcall CAkAudioMgr::RenderAudio(CAkAudioMgr *this)
{
  CAkAudioMgr *v1; // rbx
  bool v2; // al
  bool v3; // di
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  v1 = this;
  EnterCriticalSection(&this->m_queueLock.m_csLock);
  v2 = v1->m_MsgQueue.m_uReadBlock == v1->m_MsgQueue.m_uWriteBlock
    && v1->m_MsgQueue.m_uReadOffset == v1->m_MsgQueue.m_uWriteOffset
    && !v1->m_MsgQueue.m_bBufferFull;
  v3 = v2 == 0;
  if ( !v2 )
  {
    *(_DWORD *)&in_rItem.size = 8;
    CAkAudioMgr::LockedEnqueue(v1, &in_rItem, 8u);
    ++v1->m_ulWriterFlag;
  }
  LeaveCriticalSection(&v1->m_queueLock.m_csLock);
  if ( v3 )
    CAkAudioThread::WakeupEventsConsumer(&v1->m_audioThread);
  return 1i64;
}

// File Line: 275
// RVA: 0xA47F70
__int64 __fastcall CAkAudioMgr::Enqueue(CAkAudioMgr *this, AkQueuedMsg *in_rItem, unsigned int in_uSize)
{
  unsigned int v3; // ebx
  AkQueuedMsg *v4; // rdi
  CAkAudioMgr *v5; // rsi
  AKRESULT v6; // ebx

  v3 = in_uSize;
  v4 = in_rItem;
  v5 = this;
  EnterCriticalSection(&this->m_queueLock.m_csLock);
  v6 = CAkAudioMgr::LockedEnqueue(v5, v4, v3);
  LeaveCriticalSection(&v5->m_queueLock.m_csLock);
  return (unsigned int)v6;
}

// File Line: 292
// RVA: 0xA48530
signed __int64 __fastcall CAkAudioMgr::LockedEnqueue(CAkAudioMgr *this, AkQueuedMsg *in_rItem, unsigned int in_uSize)
{
  CAkAudioMgr *v3; // rbx
  unsigned int v4; // edi
  AkQueuedMsg *v5; // rsi
  signed __int64 result; // rax

  v3 = this;
  v4 = in_uSize;
  v5 = in_rItem;
  in_rItem->size = in_uSize;
  result = AkSparseChunkRing::Write(&this->m_MsgQueue, in_rItem, in_uSize);
  if ( (_DWORD)result == 52 )
  {
    while ( v4 <= (unsigned int)AkSparseChunkRing::GetChunkSize() )
    {
      ResetEvent(v3->m_hEventMgrThreadDrainEvent.m_Event);
      v3->m_bDrainMsgQueue = 1;
      LeaveCriticalSection(&v3->m_queueLock.m_csLock);
      CAkAudioThread::WakeupEventsConsumer(&v3->m_audioThread);
      WaitForSingleObject(v3->m_hEventMgrThreadDrainEvent.m_Event, 0xFFFFFFFF);
      EnterCriticalSection(&v3->m_queueLock.m_csLock);
      result = AkSparseChunkRing::Write(&v3->m_MsgQueue, v5, v4);
      if ( (_DWORD)result != 52 )
        return result;
    }
    result = 81i64;
  }
  return result;
}

// File Line: 340
// RVA: 0xA48D10
void __fastcall CAkAudioMgr::Perform(CAkAudioMgr *this)
{
  CAkAudioMgr *v1; // rdi
  int i; // esi
  __int64 j; // rbx
  unsigned int v4; // ebx

  v1 = this;
  EnterCriticalSection(&g_csMain.m_csLock);
  for ( i = CAkLEngine::GetNumBufferNeededAndSubmit(); ; --i )
  {
    CAkAudioMgr::ProcessMsgQueue(v1);
    CAkAudioMgr::ProcessPendingList(v1);
    if ( CAkLEngineCmds::m_bProcessPlayCmdsNeeded )
      CAkLEngineCmds::ProcessPlayCommands();
    if ( !i )
      break;
    for ( j = g_aBehavioralExtensions.m_uLength - 1; j >= 0; g_aBehavioralExtensions.m_pItems[j--](0) )
      ;
    v4 = v1->m_uBufferTick;
    CAkTransitionManager::ProcessTransitionsList(g_pTransitionManager, v4 + 1);
    CAkPathManager::ProcessPathsList(g_pPathManager, v4 + 1);
    CAkListener::OnBeginFrame();
    CAkURenderer::ProcessLimiters();
    CAkLEngine::Perform();
    CAkURenderer::PerformContextNotif();
    ++v1->m_uBufferTick;
  }
  if ( CAkFeedbackDeviceMgr::s_pSingleton )
    CAkFeedbackDeviceMgr::CommandTick(CAkFeedbackDeviceMgr::s_pSingleton);
  LeaveCriticalSection(&g_csMain.m_csLock);
}

// File Line: 436
// RVA: 0xA49040
signed __int64 __fastcall CAkAudioMgr::ProcessMsgQueue(CAkAudioMgr *this)
{
  CAkAudioMgr *v1; // r13
  char v2; // di
  AkSparseChunkRing *v3; // rcx
  unsigned int v4; // eax
  unsigned int v5; // ebx
  char *v6; // rsi
  int v7; // eax
  CAkRegisteredObj *v8; // rax
  __int64 v9; // rbx
  CAkRegisteredObj *v10; // r15
  AkPendingAction *v11; // rax
  AkPendingAction *v12; // rdi
  AkPendingAction *v13; // rax
  unsigned int v14; // eax
  AkExternalSourceArray *v15; // rcx
  AkExternalSourceArray *v16; // r14
  int v17; // ecx
  int v18; // ebx
  AkExternalSourceArray *v19; // rcx
  int v20; // ecx
  unsigned int v21; // er12
  int v22; // ebx
  unsigned int v23; // er14
  CAkParameterNodeBase *v24; // rax
  CAkParameterNodeBase *v25; // rbx
  CAkIndexableVtbl *v26; // r8
  CAkRegisteredObj *v27; // r15
  CAkIndexable *v28; // rax
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
  CAkParameterNodeBase *v44; // rdi
  char v45; // al
  char v46; // cl
  char v47; // cl
  CAkIndexableVtbl *v48; // rax
  int v49; // ecx
  int v50; // ebx
  unsigned __int64 v51; // rdx
  TransParams *v52; // rax
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
  unsigned __int64 *v68; // rax
  CAkBusVolumes **v69; // rcx
  CAkBusVolumes *v70; // rcx
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
  CAkIndexableVtbl *v86; // rax
  unsigned int v87; // eax
  unsigned int v88; // eax
  unsigned int v89; // eax
  CAkBus *v90; // rax
  CAkBus *v91; // rbx
  CAkBus *v92; // rax
  CAkBus *v93; // rbx
  CAkUsageSlot *v94; // rbx
  AkSinkType v95; // ebx
  CAkFeedbackDeviceMgr *v96; // rax
  unsigned int v97; // ecx
  unsigned __int64 *v98; // rax
  CAkFeedbackDeviceMgr *v99; // r11
  __int64 v100; // rcx
  __int64 v101; // r10
  float v102; // xmm0_4
  unsigned __int8 v103; // r8
  float v104; // xmm0_4
  unsigned __int8 v105; // bl
  MapStruct<unsigned long,CAkSplitterBus *> **v106; // rdi
  CAkParameterNodeBase *v107; // rax
  CAkParameterNodeBase *v108; // rbx
  unsigned int v109; // eax
  const wchar_t *v110; // rcx
  AkPendingAction v111; // [rsp+50h] [rbp-B0h]
  float v112; // [rsp+A0h] [rbp-60h]
  TransParams v113; // [rsp+A8h] [rbp-58h]
  AkOutputSettings out_settings; // [rsp+B0h] [rbp-50h]
  TransParams v115; // [rsp+B8h] [rbp-48h]
  char *v116; // [rsp+C0h] [rbp-40h]
  TransParams v117; // [rsp+C8h] [rbp-38h]
  TransParams in_transParams; // [rsp+D0h] [rbp-30h]
  char v119; // [rsp+1D0h] [rbp+D0h]
  unsigned int v120; // [rsp+1D8h] [rbp+D8h]
  unsigned int v121; // [rsp+1E0h] [rbp+E0h]
  unsigned int out_uSizeAvail; // [rsp+1E8h] [rbp+E8h]

  v1 = this;
  if ( this->m_bDrainMsgQueue || this->m_ulWriterFlag != this->m_ulReaderFlag )
  {
    v2 = 0;
    v119 = 0;
    EnterCriticalSection(&this->m_queueLock.m_csLock);
    v3 = &v1->m_MsgQueue;
    while ( 1 )
    {
      v4 = v3->m_uWriteBlock;
      v5 = 0;
      out_uSizeAvail = 0;
      v120 = 0;
      if ( v3->m_uReadBlock == v4 && v3->m_uReadOffset == v3->m_uWriteOffset && !v3->m_bBufferFull )
      {
LABEL_90:
        v1->m_bDrainMsgQueue = 0;
        LeaveCriticalSection(&v1->m_queueLock.m_csLock);
        SetEvent(v1->m_hEventMgrThreadDrainEvent.m_Event);
        return 1i64;
      }
      v6 = AkSparseChunkRing::BeginReadEx(v3, &out_uSizeAvail);
      LeaveCriticalSection(&v1->m_queueLock.m_csLock);
      do
      {
        v7 = *((unsigned __int16 *)v6 + 1);
        v116 = v6;
        switch ( v7 )
        {
          case 0:
            if ( ++v1->m_ulReaderFlag != v1->m_ulWriterFlag || v1->m_bDrainMsgQueue )
            {
              v2 = 0;
              v119 = 0;
            }
            else
            {
              v2 = 1;
              v119 = 1;
            }
            goto LABEL_87;
          case 1:
            v8 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, *((_QWORD *)v6 + 1));
            v9 = *(_QWORD *)(*((_QWORD *)v6 + 6) + 24i64);
            v10 = v8;
            if ( !v9 )
              goto LABEL_28;
            while ( 1 )
            {
              if ( *(_BYTE *)(v9 + 52) & 1 )
              {
                if ( v10 )
                {
                  v11 = (AkPendingAction *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
                  v12 = v11;
                  if ( v11 )
                  {
                    v11->vfptr = (ITransitionableVtbl *)&AkPendingAction::`vftable';
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
                  v13->vfptr = (ITransitionableVtbl *)&AkPendingAction::`vftable';
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
                    v15 = v12->UserParam.m_CustomParam.pExternalSrcs;
                    v12->UserParam.m_PlayingID = *((_DWORD *)v6 + 4);
                    v12->UserParam.m_CustomParam.customParam = *((_QWORD *)v6 + 3);
                    v12->UserParam.m_CustomParam.ui32Reserved = *((_DWORD *)v6 + 8);
                    v16 = (AkExternalSourceArray *)*((_QWORD *)v6 + 5);
                    if ( v15 )
                      AkExternalSourceArray::Release(v15);
                    if ( v16 )
                      ++v16->m_cRefCount;
                    v12->UserParam.m_CustomParam.pExternalSrcs = v16;
                    CAkAudioMgr::EnqueueOrExecuteAction(v1, v12);
                  }
                  goto LABEL_26;
                }
              }
LABEL_26:
              v9 = *(_QWORD *)(v9 + 24);
              if ( !v9 )
              {
                v2 = v119;
LABEL_28:
                if ( v10 )
                {
                  v17 = *((_DWORD *)v10 + 30) ^ (*((_DWORD *)v10 + 30) ^ (*((_DWORD *)v10 + 30) - 1)) & 0x3FFFFFFF;
                  *((_DWORD *)v10 + 30) = v17;
                  if ( !(v17 & 0x3FFFFFFF) )
                  {
                    v18 = g_DefaultPoolId;
                    CAkRegisteredObj::~CAkRegisteredObj(v10);
                    AK::MemoryMgr::Free(v18, v10);
                  }
                }
                CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, *((_DWORD *)v6 + 4));
                (*(void (**)(void))(**((_QWORD **)v6 + 6) + 16i64))();
                v19 = (AkExternalSourceArray *)*((_QWORD *)v6 + 5);
                if ( v19 )
                {
                  AkExternalSourceArray::Release(v19);
                  goto LABEL_86;
                }
                goto LABEL_196;
              }
            }
          case 2:
            v51 = *((_QWORD *)v6 + 2);
            if ( v51 == -1i64 )
            {
              in_transParams.TransitionTime = 0;
              v52 = &in_transParams;
              goto LABEL_79;
            }
            v53 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, v51);
            if ( !v53 )
              goto LABEL_197;
            v54 = *((_DWORD *)v6 + 2);
            v55 = *((float *)v6 + 3);
            v113.TransitionTime = 0;
            CAkRTPCMgr::SetRTPCInternal(g_pRTPCMgr, v54, v55, v53, &v113, AkValueMeaning_Independent);
            v56 = *((_DWORD *)v53 + 30) ^ (*((_DWORD *)v53 + 30) ^ (*((_DWORD *)v53 + 30) - 1)) & 0x3FFFFFFF;
            *((_DWORD *)v53 + 30) = v56;
            v57 = (v56 & 0x3FFFFFFF) == 0;
            goto LABEL_82;
          case 3:
            v60 = *((_QWORD *)v6 + 2);
            if ( v60 == -1i64 )
            {
              v52 = (TransParams *)(v6 + 24);
LABEL_79:
              CAkRTPCMgr::SetRTPCInternal(
                g_pRTPCMgr,
                *((_DWORD *)v6 + 2),
                *((float *)v6 + 3),
                0i64,
                v52,
                AkValueMeaning_Independent);
              goto LABEL_87;
            }
            v61 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, v60);
            v53 = v61;
            if ( !v61 )
              goto LABEL_197;
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
              v115.TransitionTime = 0;
              v73 = &v115;
              goto LABEL_131;
            }
            v74 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, v72);
            v53 = v74;
            if ( !v74 )
              goto LABEL_197;
            v117.TransitionTime = 0;
            v75 = &v117;
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
              goto LABEL_197;
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
              goto LABEL_197;
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
            goto LABEL_197;
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
            CAkRegistryMgr::SetPosition(g_pRegistryMgr, *((_QWORD *)v6 + 1), (AkSoundPosition *)(v6 + 16), 1u, 0);
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
            v68 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
            while ( *v68 != (*((signed int *)v6 + 2) | ((unsigned __int64)*((unsigned int *)v6 + 3) << 32)) )
            {
              ++v67;
              v68 += 10;
              if ( v67 >= CAkOutputMgr::m_Devices.m_uLength )
                goto LABEL_87;
            }
            v69 = (CAkBusVolumes **)&CAkOutputMgr::m_Devices.m_pItems[v67];
            if ( v69 )
            {
              v70 = *v69;
              v121 = *((_DWORD *)v6 + 4);
              LODWORD(v112) = (v121 & 0x7FFFFF) + 1065353216;
              CAkBusVolumes::SetNextVolume(
                v70,
                (float)((float)((float)((float)((float)((float)((float)((float)(v112 - 1.0) / (float)(v112 + 1.0))
                                                              * (float)((float)(v112 - 1.0) / (float)(v112 + 1.0)))
                                                      * 0.33333334)
                                              + 1.0)
                                      * (float)((float)((float)(v112 - 1.0) / (float)(v112 + 1.0)) * 2.0))
                              + (float)((float)((float)(unsigned __int8)(v121 >> 23) - 127.0) * 0.69314718))
                      * 0.43429449)
              * 20.0);
            }
            goto LABEL_87;
          case 22:
            v77 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, *((_QWORD *)v6 + 1));
            v53 = v77;
            if ( !v77 )
              goto LABEL_197;
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
                (*(void (**)(void))(**((_QWORD **)v6 + 1) + 16i64))();
                break;
              case 1:
                CAkDynamicSequence::Pause(
                  *((CAkDynamicSequence **)v6 + 1),
                  *((_DWORD *)v6 + 5),
                  *((AkCurveInterpolation *)v6 + 6));
                (*(void (**)(void))(**((_QWORD **)v6 + 1) + 16i64))();
                break;
              case 2:
                CAkDynamicSequence::Resume(
                  *((CAkDynamicSequence **)v6 + 1),
                  *((_DWORD *)v6 + 5),
                  *((AkCurveInterpolation *)v6 + 6));
                (*(void (**)(void))(**((_QWORD **)v6 + 1) + 16i64))();
                break;
              case 3:
                *(_BYTE *)(*((_QWORD *)v6 + 1) + 128i64) = 1;
                CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, *(_DWORD *)(*((_QWORD *)v6 + 1) + 120i64));
                (*(void (**)(void))(**((_QWORD **)v6 + 1) + 16i64))();
                goto LABEL_149;
              case 4:
                CAkDynamicSequence::Stop(
                  *((CAkDynamicSequence **)v6 + 1),
                  *((_DWORD *)v6 + 5),
                  *((AkCurveInterpolation *)v6 + 6));
                (*(void (**)(void))(**((_QWORD **)v6 + 1) + 16i64))();
                break;
              case 5:
                CAkDynamicSequence::Break(*((CAkDynamicSequence **)v6 + 1));
                (*(void (**)(void))(**((_QWORD **)v6 + 1) + 16i64))();
                break;
              case 6:
                CAkDynamicSequence::ResumeWaiting(*((CAkDynamicSequence **)v6 + 1));
                (*(void (**)(void))(**((_QWORD **)v6 + 1) + 16i64))();
                break;
              default:
LABEL_149:
                (*(void (**)(void))(**((_QWORD **)v6 + 1) + 16i64))();
                break;
            }
            goto LABEL_87;
          case 24:
            v94 = (CAkUsageSlot *)*((_QWORD *)v6 + 1);
            CAkURenderer::StopAllPBIs(*((CAkUsageSlot **)v6 + 1));
            CAkUsageSlot::Release(v94, 0);
            goto LABEL_86;
          case 25:
            v78 = *((_QWORD *)v6 + 1);
            v79 = CAkActionStop::Create((AkActionType)((v78 != -1i64) + 260), 0);
            v80 = v79;
            if ( !v79 )
              goto LABEL_196;
            if ( v78 == -1i64 )
            {
              v85 = v79;
              v111.vfptr = (ITransitionableVtbl *)&AkPendingAction::`vftable';
              v86 = v79->vfptr;
              v111.UserParam.m_PlayingID = 0;
              v111.UserParam.m_CustomParam.customParam = 0i64;
              v111.UserParam.m_CustomParam.ui32Reserved = 0;
              v111.UserParam.m_CustomParam.pExternalSrcs = 0i64;
              v111.TargetPlayingID = 0;
              v111.pGameObj = 0i64;
              v86[2].__vecDelDtor((CAkIndexable *)&v85->vfptr, (unsigned int)&v111);
              AkPendingAction::~AkPendingAction(&v111);
              v80->vfptr->Release((CAkIndexable *)&v80->vfptr);
            }
            else
            {
              v81 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, v78);
              v82 = v81;
              if ( v81 )
              {
                v111.UserParam.m_PlayingID = 0;
                v111.UserParam.m_CustomParam.customParam = 0i64;
                v111.UserParam.m_CustomParam.ui32Reserved = 0;
                v111.UserParam.m_CustomParam.pExternalSrcs = 0i64;
                v111.TargetPlayingID = 0;
                v111.pGameObj = v81;
                v111.vfptr = (ITransitionableVtbl *)&AkPendingAction::`vftable';
                *((_DWORD *)v81 + 30) ^= (*((_DWORD *)v81 + 30) ^ (*((_DWORD *)v81 + 30) + 1)) & 0x3FFFFFFF;
                v80->vfptr[2].__vecDelDtor((CAkIndexable *)&v80->vfptr, (unsigned int)&v111);
                v83 = *((_DWORD *)v82 + 30) ^ (*((_DWORD *)v82 + 30) ^ (*((_DWORD *)v82 + 30) - 1)) & 0x3FFFFFFF;
                *((_DWORD *)v82 + 30) = v83;
                if ( !(v83 & 0x3FFFFFFF) )
                {
                  v84 = g_DefaultPoolId;
                  CAkRegisteredObj::~CAkRegisteredObj(v82);
                  AK::MemoryMgr::Free(v84, v82);
                }
                AkPendingAction::~AkPendingAction(&v111);
              }
              v2 = v119;
              v80->vfptr->Release((CAkIndexable *)&v80->vfptr);
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
                     *((void **)v6 + 2)) != 1 )
                goto LABEL_196;
              v97 = 0;
              if ( !CAkOutputMgr::m_Devices.m_uLength )
              {
LABEL_174:
                (*(void (**)(void))(*MEMORY[8] + 8i64))();
                goto LABEL_86;
              }
              v98 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
              while ( *v98 != ((signed int)v95 | ((unsigned __int64)*((unsigned int *)v6 + 7) << 32)) )
              {
                ++v97;
                v98 += 10;
                if ( v97 >= CAkOutputMgr::m_Devices.m_uLength )
                  goto LABEL_174;
              }
              (*(void (**)(void))CAkOutputMgr::m_Devices.m_pItems[v97].pSink->vfptr->gap8)();
            }
            else
            {
              CAkOutputMgr::RemoveOutputDevice(*((_QWORD *)v6 + 3));
            }
LABEL_86:
            v5 = v120;
            goto LABEL_87;
          case 28:
            v99 = CAkFeedbackDeviceMgr::s_pSingleton;
            if ( CAkFeedbackDeviceMgr::s_pSingleton )
            {
              v100 = (unsigned __int8)v6[8];
              v101 = (unsigned __int8)v6[9];
              CAkFeedbackDeviceMgr::s_pSingleton->m_aListenerToPlayer[(unsigned __int8)CAkFeedbackDeviceMgr::s_pSingleton->m_aPlayerToListener[v100]] &= ~(1 << v100);
              v99->m_aPlayerToListener[v100] = v101;
              v99->m_aListenerToPlayer[v101] |= 1 << v100;
            }
            goto LABEL_87;
          case 29:
            if ( !CAkFeedbackDeviceMgr::s_pSingleton )
              goto LABEL_87;
            v102 = *((float *)v6 + 2);
            v103 = v6[12];
            if ( v102 <= 0.0 )
            {
              if ( (float)(v102 * 0.050000001) >= -37.0 && !(`AkMath::FastPow10'::`4'::`local static guard' & 1) )
              {
                `AkMath::FastPow10'::`4'::`local static guard' |= 1u;
                `AkMath::FastPow10'::`4'::SCALE = 1272224376;
              }
            }
            else
            {
              v104 = v102 * -0.050000001;
              if ( v104 >= -37.0 && !(`AkMath::FastPow10'::`4'::`local static guard' & 1) )
              {
                `AkMath::FastPow10'::`4'::`local static guard' |= 1u;
                `AkMath::FastPow10'::`4'::SCALE = 1272224376;
              }
            }
            v105 = 0;
            v106 = &(&CAkFeedbackDeviceMgr::s_pSingleton->m_aBusses.m_pItems)[2 * (v103 + 1i64)];
            if ( *((_DWORD *)v106 + 2) )
            {
              do
                ((void (*)(void))(*v106)[v105++].item->m_aBusses.m_pItems[5].m_pFeedbackMixBus)();
              while ( (unsigned int)v105 < *((_DWORD *)v106 + 2) );
            }
            goto LABEL_85;
          case 30:
            CAkAudioMgr::ClearPendingItems(v1, *((_DWORD *)v6 + 2));
            v87 = *((_DWORD *)v6 + 4);
            *((_WORD *)&v111.PausedTick + 2) = 0;
            v111.PausedTick = v87;
            v88 = *((_DWORD *)v6 + 2);
            *((_BYTE *)&v111.PausedTick + 6) = 0;
            v111.LaunchTick = v88;
            v89 = *((_DWORD *)v6 + 3);
            LODWORD(v111.vfptr) = 0;
            v111.LaunchFrameOffset = v89;
            v111.pAction = 0i64;
            v90 = CAkBus::GetPrimaryMasterBusAndAddRef();
            v91 = v90;
            if ( v90 )
            {
              v90->vfptr[4].__vecDelDtor((CAkIndexable *)&v90->vfptr, (unsigned int)&v111);
              v91->vfptr->Release((CAkIndexable *)&v91->vfptr);
            }
            v92 = CAkBus::GetSecondaryMasterBusAndAddRef();
            v93 = v92;
            if ( !v92 )
              goto LABEL_196;
            v92->vfptr[4].__vecDelDtor((CAkIndexable *)&v92->vfptr, (unsigned int)&v111);
            v93->vfptr->Release((CAkIndexable *)&v93->vfptr);
            goto LABEL_86;
          case 31:
            v36 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, *((_QWORD *)v6 + 2));
            if ( !v36 && *((_QWORD *)v6 + 2) != -1i64 )
              goto LABEL_76;
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
              goto LABEL_76;
            v43 = *(_QWORD *)(*((_QWORD *)v6 + 1) + 24i64);
            if ( !v43 )
              goto LABEL_72;
            do
            {
              if ( *(_WORD *)(v43 + 52) == 1027 )
              {
                v44 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, *(_DWORD *)(v43 + 48), 0);
                if ( v44 )
                {
                  v45 = v6[28] & 1;
                  v46 = v6[29] & 1;
                  *((_WORD *)&v111.PausedTick + 2) = 0;
                  *((_BYTE *)&v111.PausedTick + 6) = 0;
                  v111.PausedTick = 4;
                  v111.pAction = (CAkAction *)v36;
                  *(_QWORD *)&v111.LaunchTick = 0i64;
                  LODWORD(v111.vfptr) = 4;
                  v47 = *(_BYTE *)(&v111.UserParam.m_CustomParam.ui32Reserved + 1) & 0xFC | v45 | 2 * v46;
                  v111.UserParam.m_CustomParam.ui32Reserved = *((_DWORD *)v6 + 6);
                  v48 = v44->vfptr;
                  *((_BYTE *)&v111.UserParam.m_CustomParam.ui32Reserved + 4) = v47;
                  v48[4].__vecDelDtor((CAkIndexable *)&v44->vfptr, (unsigned int)&v111);
                  v44->vfptr->Release((CAkIndexable *)&v44->vfptr);
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
              v24 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v23, 0);
              v25 = v24;
              if ( v24 )
              {
                v26 = v24->vfptr;
                v111.LaunchTick = *((_DWORD *)v6 + 4);
                *((_WORD *)&v111.PausedTick + 2) = 0;
                *((_BYTE *)&v111.PausedTick + 6) = 0;
                v111.PausedTick = 4;
                v111.pAction = 0i64;
                v111.LaunchFrameOffset = 0;
                LODWORD(v111.vfptr) = 0;
                v26[4].__vecDelDtor((CAkIndexable *)&v24->vfptr, (unsigned int)&v111);
                v25->vfptr->Release((CAkIndexable *)&v25->vfptr);
                goto LABEL_86;
              }
            }
            else
            {
              v27 = CAkRegistryMgr::GetObjAndAddref(g_pRegistryMgr, *((_QWORD *)v6 + 1));
              if ( v27 )
              {
                v28 = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                        (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxFxCustom,
                        v23);
                v29 = (CAkFxCustom *)v28;
                if ( v28 )
                {
                  v28->vfptr->Release(v28);
                }
                else
                {
                  v30 = CAkFxCustom::Create(v23);
                  v29 = v30;
                  if ( v30 )
                    CAkFxBase::SetFX((CAkFxBase *)&v30->vfptr, v22 + 2, 0i64);
                }
                v31 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v23, 0);
                if ( v31 || !v29 )
                {
                  v31->vfptr->Release((CAkIndexable *)&v31->vfptr);
                }
                else
                {
                  v32 = CAkSound::Create(v23);
                  if ( v32 )
                    CAkSource::SetSource(&v32->m_Source, v29->key);
                }
                v111.PausedTick = v21;
                v111.vfptr = 0i64;
                LODWORD(v111.pAction) = 0;
                *(_QWORD *)&v111.LaunchTick = 0i64;
                CAkAudioMgr::PlaySourceInput(v1, v23, v27, (UserParams *)&v111);
                v33 = *((_DWORD *)v27 + 30) ^ (*((_DWORD *)v27 + 30) ^ (*((_DWORD *)v27 + 30) - 1)) & 0x3FFFFFFF;
                *((_DWORD *)v27 + 30) = v33;
                if ( !(v33 & 0x3FFFFFFF) )
                {
                  v34 = g_DefaultPoolId;
                  CAkRegisteredObj::~CAkRegisteredObj(v27);
                  v35 = v27;
LABEL_84:
                  AK::MemoryMgr::Free(v34, v35);
LABEL_85:
                  v2 = v119;
                  goto LABEL_86;
                }
              }
            }
LABEL_196:
            v5 = v120;
LABEL_197:
            v2 = v119;
            goto LABEL_87;
          case 37:
            if ( g_pAkSink )
            {
              v110 = (const wchar_t *)*((_QWORD *)v6 + 1);
              if ( v110 )
              {
                CAkOutputMgr::StartOutputCapture(v110);
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
            v107 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, *((_DWORD *)v6 + 2), (AkNodeType)*((_DWORD *)v6 + 5));
            v108 = v107;
            if ( !v107 )
              goto LABEL_196;
            v109 = v107->vfptr[3].Release((CAkIndexable *)&v107->vfptr);
            if ( v109 <= 9 || v109 == 12 )
              CAkParameterNodeBase::SetFX(v108, *((_DWORD *)v6 + 3), *((_DWORD *)v6 + 4), 1);
            v108->vfptr->Release((CAkIndexable *)&v108->vfptr);
            goto LABEL_86;
          case 39:
            CAkLEngine::SetPanningRule(*((_DWORD *)v6 + 2), *((AkSinkType *)v6 + 3), *((AkPanningRule *)v6 + 4));
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
                v1,
                v38,
                v36,
                *((AK::SoundEngine::AkActionOnEventType *)v6 + 6),
                *((_DWORD *)v6 + 7),
                *((AkCurveInterpolation *)v6 + 8),
                *((_DWORD *)v6 + 9));
              v39->vfptr->Release((CAkIndexable *)&v39->vfptr);
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
        v2 = v119;
LABEL_72:
        if ( v36 )
        {
          v49 = *((_DWORD *)v36 + 30) ^ (*((_DWORD *)v36 + 30) ^ (*((_DWORD *)v36 + 30) - 1)) & 0x3FFFFFFF;
          *((_DWORD *)v36 + 30) = v49;
          if ( !(v49 & 0x3FFFFFFF) )
          {
            v50 = g_DefaultPoolId;
            CAkRegisteredObj::~CAkRegisteredObj(v36);
            AK::MemoryMgr::Free(v50, v36);
          }
        }
        v5 = v120;
LABEL_76:
        (*(void (**)(void))(**((_QWORD **)v6 + 1) + 16i64))();
LABEL_87:
        v6 += *(unsigned __int16 *)v6;
        v58 = *(unsigned __int16 *)v116;
        ++CAkLEngineCmds::m_ulPlayEventID;
        v5 += v58;
        v120 = v5;
      }
      while ( v5 < out_uSizeAvail && !v2 );
      EnterCriticalSection(&v1->m_queueLock.m_csLock);
      AkSparseChunkRing::EndRead(&v1->m_MsgQueue, v5);
      v3 = &v1->m_MsgQueue;
      if ( v2 )
        goto LABEL_90;
    }
  }
  return 1i64;
}

// File Line: 1391
// RVA: 0xA4A490
void __fastcall CAkAudioMgr::ProcessPendingList(CAkAudioMgr *this)
{
  CAkAudioMgr *v1; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v2; // rcx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v3; // rdx
  AkPendingAction *v4; // rsi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v6; // rax
  CAkActionPlayAndContinue *v7; // rcx
  int v8; // eax
  __int64 v9; // rdx
  int v10; // edi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v11; // rax
  __int128 v12; // [rsp+30h] [rbp-68h]
  int v13; // [rsp+40h] [rbp-58h]

  v1 = this;
  v2 = this->m_mmapPending.m_pFirst;
  v3 = 0i64;
  if ( v2 )
  {
    while ( v2->Item.key <= v1->m_uBufferTick )
    {
      v4 = v2->Item.item;
      v5 = v2->pNextListItem;
      if ( v2 == v1->m_mmapPending.m_pFirst )
        v1->m_mmapPending.m_pFirst = v5;
      else
        v3->pNextListItem = v5;
      if ( v2 == v1->m_mmapPending.m_pLast )
        v1->m_mmapPending.m_pLast = v3;
      v6 = v1->m_mmapPending.m_pFree;
      v13 = 0;
      v2->pNextListItem = v6;
      --v1->m_mmapPending.m_ulNumListItems;
      v1->m_mmapPending.m_pFree = v2;
      v7 = (CAkActionPlayAndContinue *)v4->pAction;
      v8 = v7->m_eActionType;
      if ( v8 == 1027 || v8 == 1283 && CAkActionPlayAndContinue::NeedNotifyDelay(v7) )
        ((void (__fastcall *)(CAkAction *, int *))v4->pAction->vfptr[2].Category)(v4->pAction, &v13);
      v4->pAction->vfptr[2].__vecDelDtor((CAkIndexable *)&v4->pAction->vfptr, (unsigned int)v4);
      v9 = v4->UserParam.m_PlayingID;
      if ( (_DWORD)v9 )
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v9);
      ((void (__cdecl *)(CAkAction *, __int64))v4->pAction->vfptr->Release)(v4->pAction, v9);
      v10 = g_DefaultPoolId;
      ((void (__fastcall *)(AkPendingAction *, _QWORD))v4->vfptr[1].TransUpdateValue)(v4, 0i64);
      AK::MemoryMgr::Free(v10, v4);
      ++CAkLEngineCmds::m_ulPlayEventID;
      v11 = v1->m_mmapPending.m_pFirst;
      _mm_store_si128((__m128i *)&v12, (__m128i)(unsigned __int64)v1->m_mmapPending.m_pFirst);
      if ( !v11 )
        break;
      v3 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)*((_QWORD *)&v12 + 1);
      v2 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v12;
    }
  }
}

// File Line: 1428
// RVA: 0xA47FC0
void __fastcall CAkAudioMgr::EnqueueOrExecuteAction(CAkAudioMgr *this, AkPendingAction *in_pActionItem)
{
  AkPendingAction *v2; // rdi
  CAkAudioMgr *v3; // rbx
  unsigned int v4; // eax
  __int64 v5; // r8
  unsigned int v6; // er9
  unsigned int v7; // edx
  int v8; // ebx
  int v9; // eax
  AKRESULT v10; // eax
  CAkActionPlayAndContinue *v11; // rcx
  int v12; // eax
  int v13; // ebx
  int v14; // [rsp+20h] [rbp-58h]
  AkPendingAction *in_rItem; // [rsp+88h] [rbp+10h]

  in_rItem = in_pActionItem;
  v2 = in_pActionItem;
  v3 = this;
  CAkPlayingMgr::AddItemActiveCount(g_pPlayingMgr, in_pActionItem->UserParam.m_PlayingID);
  ((void (*)(void))v2->pAction->vfptr->AddRef)();
  v4 = CAkAction::GetDelayTime(v2->pAction);
  v2->LaunchTick = v3->m_uBufferTick;
  v5 = v4 >> 10;
  v6 = v4;
  v2->LaunchFrameOffset = v4 - (v4 >> 10 << 10);
  if ( (_DWORD)v5 )
  {
    if ( v2->pAction->m_eActionType != 1283 )
      goto LABEL_18;
    v9 = unk_14249E984;
    if ( (unsigned int)v5 < unk_14249E984 )
      v9 = v5;
    LODWORD(v5) = v5 - v9;
    v2->LaunchFrameOffset = v6 - ((_DWORD)v5 << 10);
    if ( (_DWORD)v5 )
    {
LABEL_18:
      v2->LaunchTick += v5;
      v10 = CAkMultiKeyList<unsigned long,AkPendingAction *,2>::Insert(&v3->m_mmapPending, v2->LaunchTick, &in_rItem);
      v11 = (CAkActionPlayAndContinue *)v2->pAction;
      if ( v10 == 1 )
      {
        v14 = 0;
        v12 = v11->m_eActionType;
        if ( v12 == 1027 || v12 == 1283 && CAkActionPlayAndContinue::NeedNotifyDelay(v11) )
          ((void (__fastcall *)(CAkAction *, int *))v2->pAction->vfptr[2].Category)(v2->pAction, &v14);
      }
      else
      {
        ((void (*)(void))v11->vfptr->Release)();
        v13 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))v2->vfptr[1].TransUpdateValue)(v2, 0i64);
        AK::MemoryMgr::Free(v13, v2);
      }
    }
    else
    {
      CAkAudioMgr::ProcessAction(v3, v2);
    }
  }
  else
  {
    ((void (__fastcall *)(CAkAction *, AkPendingAction *, __int64, _QWORD))v2->pAction->vfptr[2].__vecDelDtor)(
      v2->pAction,
      v2,
      v5,
      v4);
    v7 = v2->UserParam.m_PlayingID;
    if ( v7 )
      CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v7);
    ((void (*)(void))v2->pAction->vfptr->Release)();
    v8 = g_DefaultPoolId;
    ((void (__fastcall *)(AkPendingAction *, _QWORD))v2->vfptr[1].TransUpdateValue)(v2, 0i64);
    AK::MemoryMgr::Free(v8, v2);
  }
}

// File Line: 1495
// RVA: 0xA48F00
void __fastcall CAkAudioMgr::ProcessAction(CAkAudioMgr *this, AkPendingAction *in_pAction)
{
  AkPendingAction *v2; // rdi
  unsigned int v3; // edx
  int v4; // ebx

  v2 = in_pAction;
  ((void (*)(void))in_pAction->pAction->vfptr[2].__vecDelDtor)();
  v3 = v2->UserParam.m_PlayingID;
  if ( v3 )
    CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v3);
  ((void (*)(void))v2->pAction->vfptr->Release)();
  v4 = g_DefaultPoolId;
  ((void (__fastcall *)(AkPendingAction *, _QWORD))v2->vfptr[1].TransUpdateValue)(v2, 0i64);
  AK::MemoryMgr::Free(v4, v2);
}

// File Line: 1527
// RVA: 0xA48F60
void __fastcall CAkAudioMgr::ProcessCustomAction(CAkAudioMgr *this, CAkParameterNodeBase *ptargetNode, CAkRegisteredObj *in_pGameObj, AK::SoundEngine::AkActionOnEventType in_ActionToExecute, int in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve, unsigned int in_PlayingID)
{
  CAkParameterNodeBase *v7; // rbx
  __int32 v8; // er9
  int v9; // er9
  int v10; // [rsp+30h] [rbp-38h]
  CAkRegisteredObj *v11; // [rsp+38h] [rbp-30h]
  unsigned int v12; // [rsp+40h] [rbp-28h]
  int v13; // [rsp+44h] [rbp-24h]
  AkCurveInterpolation v14; // [rsp+48h] [rbp-20h]
  __int16 v15; // [rsp+4Ch] [rbp-1Ch]
  char v16; // [rsp+4Eh] [rbp-1Ah]
  CAkParameterNodeBase *v17; // [rsp+50h] [rbp-18h]

  if ( ptargetNode )
  {
    v7 = ptargetNode;
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
    v7->vfptr[4].__vecDelDtor((CAkIndexable *)&v7->vfptr, (unsigned int)&v10);
  }
}

// File Line: 1572
// RVA: 0xA48E00
void __fastcall CAkAudioMgr::PlaySourceInput(CAkAudioMgr *this, unsigned int in_Target, CAkRegisteredObj *in_pGameObj, UserParams *in_userParams)
{
  CAkRegisteredObj *v4; // rsi
  UserParams *v5; // rdi
  CAkParameterNodeBase *v6; // rax
  CAkParameterNode *v7; // rbx
  unsigned int v8; // ecx
  __int64 v9; // rax
  AkExternalSourceArray *v10; // rax
  AkExternalSourceArray *v11; // rcx
  AkPBIParams in_rPBIParams; // [rsp+20h] [rbp-49h]
  int v13; // [rsp+E8h] [rbp+7Fh]
  int v14; // [rsp+ECh] [rbp+83h]

  v4 = in_pGameObj;
  v5 = in_userParams;
  v6 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_Target, 0);
  v7 = (CAkParameterNode *)v6;
  if ( v6 )
  {
    v8 = v5->m_PlayingID;
    in_rPBIParams.pInstigator = (CAkPBIAware *)&v6->vfptr;
    v9 = v5->m_CustomParam.customParam;
    v13 = 0;
    v14 = 4;
    in_rPBIParams.userParams.m_CustomParam.customParam = v9;
    LODWORD(v9) = v5->m_CustomParam.ui32Reserved;
    in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = 0i64;
    in_rPBIParams.userParams.m_CustomParam.ui32Reserved = v9;
    v10 = v5->m_CustomParam.pExternalSrcs;
    in_rPBIParams.playHistory.arrayIsContinuous.m_iBitArray = 0;
    in_rPBIParams.bSkipDelay = 0;
    in_rPBIParams.bTargetFeedback = 0;
    in_rPBIParams.playHistory.HistArray.uiArraySize = 0;
    in_rPBIParams.eType = 0;
    in_rPBIParams.userParams.m_PlayingID = v8;
    if ( v10 )
      ++v10->m_cRefCount;
    in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = v10;
    *(_QWORD *)&in_rPBIParams.ePlaybackState = 0i64;
    in_rPBIParams.pContinuousParams = 0i64;
    in_rPBIParams.sequenceID = 0;
    in_rPBIParams.bIsFirst = 1;
    in_rPBIParams.pGameObj = v4;
    in_rPBIParams.pTransitionParameters = (TransParams *)&v13;
    if ( CAkParameterNode::HandleInitialDelay(v7, &in_rPBIParams) == 1 )
      ((void (__fastcall *)(CAkParameterNode *, AkPBIParams *))v7->vfptr[19].Category)(v7, &in_rPBIParams);
    v7->vfptr->Release((CAkIndexable *)&v7->vfptr);
    if ( in_rPBIParams.userParams.m_CustomParam.pExternalSrcs )
      AkExternalSourceArray::Release(in_rPBIParams.userParams.m_CustomParam.pExternalSrcs);
  }
  v11 = v5->m_CustomParam.pExternalSrcs;
  if ( v11 )
    AkExternalSourceArray::Release(v11);
}

// File Line: 1616
// RVA: 0xA487E0
void __fastcall CAkAudioMgr::PausePendingAction(CAkAudioMgr *this, CAkParameterNodeBase *in_pNodeToTarget, CAkRegisteredObj *in_GameObj, bool in_bIsMasterOnResume, unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // rbx
  bool v6; // r15
  CAkRegisteredObj *v7; // r12
  CAkParameterNodeBase *v8; // rdi
  CAkAudioMgr *v9; // r13
  AkPendingAction *v10; // rsi
  CAkAction *v11; // rbp
  CAkParameterNodeBase *v12; // rax
  CAkParameterNodeBase *v13; // rdx
  CAkParameterNodeBase *v14; // rcx
  unsigned __int16 v15; // cx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v16; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v17; // r14
  AkPendingAction *v18; // rbp
  CAkAction *v19; // r15
  CAkParameterNodeBase *v20; // rax
  CAkParameterNodeBase *v21; // rsi
  CAkParameterNodeBase *v22; // rdx
  CAkParameterNodeBase *v23; // rcx
  unsigned __int16 v24; // cx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v25; // rax
  __m128i v26; // [rsp+20h] [rbp-58h]
  __m128i v27; // [rsp+30h] [rbp-48h]
  CAkAudioMgr *v28; // [rsp+80h] [rbp+8h]
  bool v29; // [rsp+98h] [rbp+20h]

  v29 = in_bIsMasterOnResume;
  v28 = this;
  v5 = this->m_mmapPausedPending.m_pFirst;
  v6 = in_bIsMasterOnResume;
  v7 = in_GameObj;
  v8 = in_pNodeToTarget;
  v9 = this;
  if ( v5 )
  {
    while ( 1 )
    {
      v10 = v5->Item.item;
      v11 = v10->pAction;
      v12 = CAkAction::GetAndRefTarget(v10->pAction);
      if ( !v8 )
        goto LABEL_14;
      if ( v12 )
      {
        if ( v8 == v12 )
          goto LABEL_14;
        v13 = v12->m_pParentNode;
        v14 = v12->m_pBusOutputNode;
        if ( v13 )
        {
          while ( v8 != v13 )
          {
            if ( !v14 )
              v14 = v13->m_pBusOutputNode;
            v13 = v13->m_pParentNode;
            if ( !v13 )
              goto LABEL_10;
          }
          goto LABEL_14;
        }
LABEL_10:
        if ( v14 )
        {
          while ( v8 != v14 )
          {
            v14 = v14->m_pBusOutputNode;
            if ( !v14 )
              goto LABEL_22;
          }
LABEL_14:
          v15 = v11->m_eActionType;
          if ( ((v15 & 0xFF00) != 768 || v6)
            && (!v7 || v7 == v10->pGameObj)
            && (!in_PlayingID || in_PlayingID == v10->UserParam.m_PlayingID)
            && v15 != 6176 )
          {
            ++v10->ulPauseCount;
          }
          goto LABEL_22;
        }
      }
LABEL_22:
      v5 = v5->pNextListItem;
      if ( v12 )
        v12->vfptr->Release((CAkIndexable *)&v12->vfptr);
      if ( !v5 )
      {
        v9 = v28;
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
    v20 = CAkAction::GetAndRefTarget(v18->pAction);
    v21 = v20;
    if ( v8 )
    {
      if ( !v20 )
        goto LABEL_38;
      if ( v8 != v20 )
      {
        v22 = v20->m_pParentNode;
        v23 = v20->m_pBusOutputNode;
        if ( v22 )
        {
          while ( v8 != v22 )
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
          while ( v8 != v23 )
          {
            v23 = v23->m_pBusOutputNode;
            if ( !v23 )
              goto LABEL_38;
          }
        }
      }
    }
    v24 = v19->m_eActionType;
    if ( ((v24 & 0xFF00) != 768 || v29)
      && (!v7 || v7 == v18->pGameObj)
      && (!in_PlayingID || in_PlayingID == v18->UserParam.m_PlayingID)
      && v24 != 6176 )
    {
      CAkAudioMgr::InsertAsPaused(v9, v19->m_ulElementID, v18, 0);
      v25 = v16->pNextListItem;
      v26.m128i_i64[1] = (__int64)v17;
      v26.m128i_i64[0] = (__int64)v16->pNextListItem;
      if ( v16 == v9->m_mmapPending.m_pFirst )
        v9->m_mmapPending.m_pFirst = v25;
      else
        v17->pNextListItem = v25;
      if ( v16 == v9->m_mmapPending.m_pLast )
        v9->m_mmapPending.m_pLast = v17;
      v16->pNextListItem = v9->m_mmapPending.m_pFree;
      --v9->m_mmapPending.m_ulNumListItems;
      _mm_store_si128(&v27, v26);
      v17 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v27.m128i_i64[1];
      v9->m_mmapPending.m_pFree = v16;
      v16 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v27.m128i_i64[0];
      goto LABEL_39;
    }
LABEL_38:
    v17 = v16;
    v16 = v16->pNextListItem;
LABEL_39:
    if ( v21 )
      v21->vfptr->Release((CAkIndexable *)&v21->vfptr);
  }
}

// File Line: 1679
// RVA: 0xA48C10
void __fastcall CAkAudioMgr::PausePendingItems(CAkAudioMgr *this, unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v2; // rax
  unsigned int v3; // ebp
  CAkAudioMgr *i; // rbx
  AkPendingAction *v5; // rcx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v6; // rdi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v7; // rsi
  AkPendingAction *v8; // r8
  CAkAction *v9; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v10; // rax
  __m128i v11; // [rsp+20h] [rbp-28h]
  __m128i v12; // [rsp+30h] [rbp-18h]

  v2 = this->m_mmapPausedPending.m_pFirst;
  v3 = in_PlayingID;
  for ( i = this; v2; v2 = v2->pNextListItem )
  {
    v5 = v2->Item.item;
    if ( v5->UserParam.m_PlayingID == in_PlayingID && MEMORY[0x34] != 6176 )
      ++v5->ulPauseCount;
  }
  v6 = i->m_mmapPending.m_pFirst;
  v7 = 0i64;
  while ( v6 )
  {
    v8 = v6->Item.item;
    v9 = v8->pAction;
    if ( v8->UserParam.m_PlayingID != v3 || v9->m_eActionType == 6176 )
    {
      v7 = v6;
      v6 = v6->pNextListItem;
    }
    else
    {
      CAkAudioMgr::InsertAsPaused(i, v9->m_ulElementID, v8, 0);
      v10 = v6->pNextListItem;
      v11.m128i_i64[1] = (__int64)v7;
      v11.m128i_i64[0] = (__int64)v6->pNextListItem;
      if ( v6 == i->m_mmapPending.m_pFirst )
        i->m_mmapPending.m_pFirst = v10;
      else
        v7->pNextListItem = v10;
      if ( v6 == i->m_mmapPending.m_pLast )
        i->m_mmapPending.m_pLast = v7;
      v6->pNextListItem = i->m_mmapPending.m_pFree;
      --i->m_mmapPending.m_ulNumListItems;
      _mm_store_si128(&v12, v11);
      v7 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v12.m128i_i64[1];
      i->m_mmapPending.m_pFree = v6;
      v6 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v12.m128i_i64[0];
    }
  }
}

// File Line: 1721
// RVA: 0xA48370
void __fastcall CAkAudioMgr::InsertAsPaused(CAkAudioMgr *this, unsigned int in_ElementID, AkPendingAction *in_pPendingAction, unsigned int in_ulPauseCount)
{
  AkPendingAction *v4; // rdi
  CAkActionPlayAndContinue *v5; // rcx
  int v6; // eax
  int v7; // ebx
  int v8; // [rsp+20h] [rbp-58h]
  AkPendingAction *in_rItem; // [rsp+90h] [rbp+18h]

  in_rItem = in_pPendingAction;
  v4 = in_pPendingAction;
  in_pPendingAction->PausedTick = this->m_uBufferTick;
  in_pPendingAction->ulPauseCount = in_ulPauseCount;
  if ( (unsigned int)CAkMultiKeyList<unsigned long,AkPendingAction *,2>::Insert(
                       &this->m_mmapPausedPending,
                       in_ElementID,
                       &in_rItem) != 1 )
  {
    v5 = (CAkActionPlayAndContinue *)v4->pAction;
    v8 = 0;
    v6 = v5->m_eActionType;
    if ( v6 != 1027 )
    {
      if ( v6 != 1283 )
      {
LABEL_6:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v4->UserParam.m_PlayingID);
        ((void (__cdecl *)(CAkAction *))v4->pAction->vfptr->Release)(v4->pAction);
        v7 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))v4->vfptr[1].TransUpdateValue)(v4, 0i64);
        AK::MemoryMgr::Free(v7, v4);
        return;
      }
      CAkActionPlayAndContinue::NeedNotifyDelay(v5);
    }
    ((void (__fastcall *)(CAkAction *, int *))v4->pAction->vfptr[2].Category)(v4->pAction, &v8);
    goto LABEL_6;
  }
}

// File Line: 1742
// RVA: 0xA4C140
void __fastcall CAkAudioMgr::TransferToPending(CAkAudioMgr *this, AkPendingAction *in_pPendingAction)
{
  AkPendingAction *v2; // rdi
  CAkActionPlayAndContinue *v3; // rcx
  int v4; // eax
  int v5; // ebx
  int v6; // [rsp+20h] [rbp-58h]
  AkPendingAction *in_rItem; // [rsp+88h] [rbp+10h]

  in_rItem = in_pPendingAction;
  v2 = in_pPendingAction;
  in_pPendingAction->LaunchTick += this->m_uBufferTick - in_pPendingAction->PausedTick;
  if ( (unsigned int)CAkMultiKeyList<unsigned long,AkPendingAction *,2>::Insert(
                       &this->m_mmapPending,
                       in_pPendingAction->LaunchTick,
                       &in_rItem) != 1 )
  {
    v3 = (CAkActionPlayAndContinue *)v2->pAction;
    v6 = 0;
    v4 = v3->m_eActionType;
    if ( v4 != 1027 )
    {
      if ( v4 != 1283 )
      {
LABEL_6:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v2->UserParam.m_PlayingID);
        ((void (__cdecl *)(CAkAction *))v2->pAction->vfptr->Release)(v2->pAction);
        v5 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))v2->vfptr[1].TransUpdateValue)(v2, 0i64);
        AK::MemoryMgr::Free(v5, v2);
        return;
      }
      CAkActionPlayAndContinue::NeedNotifyDelay(v3);
    }
    ((void (__fastcall *)(CAkAction *, int *))v2->pAction->vfptr[2].Category)(v2->pAction, &v6);
    goto LABEL_6;
  }
}

// File Line: 1770
// RVA: 0xA47920
signed __int64 __fastcall CAkAudioMgr::BreakPendingAction(CAkAudioMgr *this, CAkParameterNodeBase *in_pNodeToTarget, CAkRegisteredObj *in_GameObj, unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v4; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // r15
  unsigned int v6; // er13
  CAkParameterNodeBase *v7; // rdi
  CAkAudioMgr *v8; // rbp
  AkPendingAction *v9; // rsi
  CAkAction *v10; // r12
  CAkParameterNodeBase *v11; // rax
  CAkParameterNodeBase *v12; // r14
  CAkParameterNodeBase *v13; // rdx
  CAkParameterNodeBase *v14; // rcx
  int v15; // eax
  CAkActionPlayAndContinue *v16; // rcx
  int v17; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v18; // rax
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
  __m128i v33; // [rsp+20h] [rbp-98h]
  __m128i v34; // [rsp+30h] [rbp-88h]
  int v35; // [rsp+40h] [rbp-78h]
  CAkRegisteredObj *v36; // [rsp+D0h] [rbp+18h]

  v36 = in_GameObj;
  v4 = this->m_mmapPending.m_pFirst;
  v5 = 0i64;
  v6 = in_PlayingID;
  v7 = in_pNodeToTarget;
  v8 = this;
  if ( v4 )
  {
    while ( 1 )
    {
      v9 = v4->Item.item;
      v10 = v9->pAction;
      v11 = CAkAction::GetAndRefTarget(v9->pAction);
      v12 = v11;
      if ( v7 )
      {
        if ( !v11 )
          goto LABEL_22;
        if ( v7 != v11 )
        {
          v13 = v11->m_pParentNode;
          v14 = v11->m_pBusOutputNode;
          if ( v13 )
          {
            while ( v7 != v13 )
            {
              if ( !v14 )
                v14 = v13->m_pBusOutputNode;
              v13 = v13->m_pParentNode;
              if ( !v13 )
                goto LABEL_10;
            }
          }
          else
          {
LABEL_10:
            if ( !v14 )
              goto LABEL_22;
            while ( v7 != v14 )
            {
              v14 = v14->m_pBusOutputNode;
              if ( !v14 )
              {
                v5 = v4;
                v4 = v4->pNextListItem;
                goto LABEL_33;
              }
            }
          }
        }
      }
      if ( v36 && v36 != v9->pGameObj )
        goto LABEL_22;
      if ( !v6 || v6 == v9->UserParam.m_PlayingID )
        break;
      v5 = v4;
      v4 = v4->pNextListItem;
LABEL_33:
      if ( v12 )
        v12->vfptr->Release((CAkIndexable *)&v12->vfptr);
      if ( !v4 )
        goto LABEL_36;
    }
    v15 = v10->m_eActionType;
    if ( v15 == 1027
      || v15 == 1283
      && CAkActionPlayAndContinue::BreakToNode((CAkActionPlayAndContinue *)v9->pAction, v7, v9->pGameObj, v9) )
    {
      v16 = (CAkActionPlayAndContinue *)v9->pAction;
      v35 = 0;
      v17 = v16->m_eActionType;
      if ( v17 == 1027 )
        goto LABEL_26;
      if ( v17 == 1283 )
      {
        CAkActionPlayAndContinue::NeedNotifyDelay(v16);
LABEL_26:
        ((void (__fastcall *)(CAkAction *, int *))v9->pAction->vfptr[2].Category)(v9->pAction, &v35);
      }
      CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v9->UserParam.m_PlayingID);
      v18 = v4->pNextListItem;
      v33.m128i_i64[1] = (__int64)v5;
      v33.m128i_i64[0] = (__int64)v18;
      if ( v4 == v8->m_mmapPending.m_pFirst )
        v8->m_mmapPending.m_pFirst = v18;
      else
        v5->pNextListItem = v18;
      if ( v4 == v8->m_mmapPending.m_pLast )
        v8->m_mmapPending.m_pLast = v5;
      v4->pNextListItem = v8->m_mmapPending.m_pFree;
      --v8->m_mmapPending.m_ulNumListItems;
      v8->m_mmapPending.m_pFree = v4;
      ((void (*)(void))v9->pAction->vfptr->Release)();
      v19 = g_DefaultPoolId;
      ((void (__fastcall *)(AkPendingAction *, _QWORD))v9->vfptr[1].TransUpdateValue)(v9, 0i64);
      AK::MemoryMgr::Free(v19, v9);
      _mm_store_si128(&v34, v33);
      v5 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v34.m128i_i64[1];
      v4 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v34.m128i_i64[0];
      goto LABEL_33;
    }
LABEL_22:
    v5 = v4;
    v4 = v4->pNextListItem;
    goto LABEL_33;
  }
LABEL_36:
  v20 = v8->m_mmapPausedPending.m_pFirst;
  v21 = 0i64;
  while ( v20 )
  {
    v22 = v20->Item.item;
    v23 = v22->pAction;
    v24 = CAkAction::GetAndRefTarget(v22->pAction);
    v25 = v24;
    if ( v7 )
    {
      if ( !v24 )
        goto LABEL_48;
      if ( v7 != v24 )
      {
        v26 = v24->m_pParentNode;
        v27 = v24->m_pBusOutputNode;
        if ( v26 )
        {
          while ( v7 != v26 )
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
          while ( v7 != v27 )
          {
            v27 = v27->m_pBusOutputNode;
            if ( !v27 )
              goto LABEL_48;
          }
        }
      }
    }
    if ( (!v36 || v36 == v22->pGameObj)
      && (!v6 || v6 == v22->UserParam.m_PlayingID)
      && v23->m_eActionType == 1283
      && CAkActionPlayAndContinue::BreakToNode((CAkActionPlayAndContinue *)v22->pAction, v7, v22->pGameObj, v22) )
    {
      v29 = (CAkActionPlayAndContinue *)v22->pAction;
      v35 = 0;
      v30 = v29->m_eActionType;
      if ( v30 == 1027 )
        goto LABEL_62;
      if ( v30 == 1283 )
      {
        CAkActionPlayAndContinue::NeedNotifyDelay(v29);
LABEL_62:
        ((void (__fastcall *)(CAkAction *, int *))v22->pAction->vfptr[2].Category)(v22->pAction, &v35);
      }
      CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v22->UserParam.m_PlayingID);
      v31 = v20->pNextListItem;
      v34.m128i_i64[1] = (__int64)v21;
      v34.m128i_i64[0] = (__int64)v31;
      if ( v20 == v8->m_mmapPausedPending.m_pFirst )
        v8->m_mmapPausedPending.m_pFirst = v31;
      else
        v21->pNextListItem = v31;
      if ( v20 == v8->m_mmapPausedPending.m_pLast )
        v8->m_mmapPausedPending.m_pLast = v21;
      v20->pNextListItem = v8->m_mmapPausedPending.m_pFree;
      --v8->m_mmapPausedPending.m_ulNumListItems;
      v8->m_mmapPausedPending.m_pFree = v20;
      ((void (*)(void))v22->pAction->vfptr->Release)();
      v32 = g_DefaultPoolId;
      ((void (__fastcall *)(AkPendingAction *, _QWORD))v22->vfptr[1].TransUpdateValue)(v22, 0i64);
      AK::MemoryMgr::Free(v32, v22);
      _mm_store_si128(&v33, v34);
      v21 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v33.m128i_i64[1];
      v20 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v33.m128i_i64[0];
      goto LABEL_49;
    }
LABEL_48:
    v21 = v20;
    v20 = v20->pNextListItem;
LABEL_49:
    if ( v25 )
      v25->vfptr->Release((CAkIndexable *)&v25->vfptr);
  }
  return 1i64;
}Item;
LABEL_49:
    if ( v25 )
      v25->vfptr->Release((CAkIndexable *)&v25->vfptr);
  }
  return 1i64;
}

// File Line: 1873
// RVA: 0xA4B960
signed __int64 __fastcall CAkAudioMgr::StopPendingAction(CAkAudioMgr *this, CAkParameterNodeBase *in_pNodeToTarget, CAkRegisteredObj *in_GameObj, unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v4; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // r15
  unsigned int v6; // er13
  CAkParameterNodeBase *v7; // rdi
  CAkAudioMgr *v8; // rbp
  AkPendingAction *v9; // r14
  CAkAction *v10; // r12
  CAkParameterNodeBase *v11; // rax
  CAkParameterNodeBase *v12; // rsi
  CAkParameterNodeBase *v13; // rdx
  CAkParameterNodeBase *v14; // rcx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v15; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v16; // r15
  AkPendingAction *v17; // r14
  CAkAction *v18; // r12
  CAkParameterNodeBase *v19; // rax
  CAkParameterNodeBase *v20; // rsi
  CAkParameterNodeBase *v21; // rdx
  CAkParameterNodeBase *v22; // rcx
  CAkActionPlayAndContinue *v24; // rcx
  int v25; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v26; // rax
  int v27; // ebx
  CAkActionPlayAndContinue *v28; // rcx
  int v29; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v30; // rax
  int v31; // ebx
  __m128i v32; // [rsp+20h] [rbp-98h]
  __m128i v33; // [rsp+30h] [rbp-88h]
  int v34; // [rsp+40h] [rbp-78h]
  CAkRegisteredObj *v35; // [rsp+D0h] [rbp+18h]

  v35 = in_GameObj;
  v4 = this->m_mmapPending.m_pFirst;
  v5 = 0i64;
  v6 = in_PlayingID;
  v7 = in_pNodeToTarget;
  v8 = this;
  while ( v4 )
  {
    v9 = v4->Item.item;
    v10 = v9->pAction;
    v11 = CAkAction::GetAndRefTarget(v9->pAction);
    v12 = v11;
    if ( v7 )
    {
      if ( !v11 )
        goto LABEL_13;
      if ( v7 != v11 )
      {
        v13 = v11->m_pParentNode;
        v14 = v11->m_pBusOutputNode;
        if ( v13 )
        {
          while ( v7 != v13 )
          {
            if ( !v14 )
              v14 = v13->m_pBusOutputNode;
            v13 = v13->m_pParentNode;
            if ( !v13 )
              goto LABEL_10;
          }
        }
        else
        {
LABEL_10:
          if ( !v14 )
            goto LABEL_13;
          while ( v7 != v14 )
          {
            v14 = v14->m_pBusOutputNode;
            if ( !v14 )
              goto LABEL_13;
          }
        }
      }
    }
    if ( (!v35 || v35 == v9->pGameObj) && (!v6 || v6 == v9->UserParam.m_PlayingID) && v10->m_eActionType != 6176 )
    {
      v24 = (CAkActionPlayAndContinue *)v9->pAction;
      v34 = 0;
      v25 = v24->m_eActionType;
      if ( v25 == 1027 )
        goto LABEL_42;
      if ( v25 == 1283 )
      {
        CAkActionPlayAndContinue::NeedNotifyDelay(v24);
LABEL_42:
        ((void (__fastcall *)(CAkAction *, int *))v9->pAction->vfptr[2].Category)(v9->pAction, &v34);
      }
      CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v9->UserParam.m_PlayingID);
      v26 = v4->pNextListItem;
      v32.m128i_i64[1] = (__int64)v5;
      v32.m128i_i64[0] = (__int64)v26;
      if ( v4 == v8->m_mmapPending.m_pFirst )
        v8->m_mmapPending.m_pFirst = v26;
      else
        v5->pNextListItem = v26;
      if ( v4 == v8->m_mmapPending.m_pLast )
        v8->m_mmapPending.m_pLast = v5;
      v4->pNextListItem = v8->m_mmapPending.m_pFree;
      --v8->m_mmapPending.m_ulNumListItems;
      v8->m_mmapPending.m_pFree = v4;
      ((void (*)(void))v9->pAction->vfptr->Release)();
      v27 = g_DefaultPoolId;
      ((void (__fastcall *)(AkPendingAction *, _QWORD))v9->vfptr[1].TransUpdateValue)(v9, 0i64);
      AK::MemoryMgr::Free(v27, v9);
      _mm_store_si128(&v33, v32);
      v5 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v33.m128i_i64[1];
      v4 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v33.m128i_i64[0];
      goto LABEL_14;
    }
LABEL_13:
    v5 = v4;
    v4 = v4->pNextListItem;
LABEL_14:
    if ( v12 )
      v12->vfptr->Release((CAkIndexable *)&v12->vfptr);
  }
  v15 = v8->m_mmapPausedPending.m_pFirst;
  v16 = 0i64;
  while ( v15 )
  {
    v17 = v15->Item.item;
    v18 = v17->pAction;
    v19 = CAkAction::GetAndRefTarget(v17->pAction);
    v20 = v19;
    if ( v7 )
    {
      if ( !v19 )
        goto LABEL_29;
      if ( v7 != v19 )
      {
        v21 = v19->m_pParentNode;
        v22 = v19->m_pBusOutputNode;
        if ( v21 )
        {
          while ( v7 != v21 )
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
          while ( v7 != v22 )
          {
            v22 = v22->m_pBusOutputNode;
            if ( !v22 )
              goto LABEL_29;
          }
        }
      }
    }
    if ( (!v35 || v35 == v17->pGameObj) && (!v6 || v6 == v17->UserParam.m_PlayingID) && v18->m_eActionType != 6176 )
    {
      v28 = (CAkActionPlayAndContinue *)v17->pAction;
      v34 = 0;
      v29 = v28->m_eActionType;
      if ( v29 == 1027 )
        goto LABEL_57;
      if ( v29 == 1283 )
      {
        CAkActionPlayAndContinue::NeedNotifyDelay(v28);
LABEL_57:
        ((void (__fastcall *)(CAkAction *, int *))v17->pAction->vfptr[2].Category)(v17->pAction, &v34);
      }
      CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v17->UserParam.m_PlayingID);
      v30 = v15->pNextListItem;
      v33.m128i_i64[1] = (__int64)v16;
      v33.m128i_i64[0] = (__int64)v30;
      if ( v15 == v8->m_mmapPausedPending.m_pFirst )
        v8->m_mmapPausedPending.m_pFirst = v30;
      else
        v16->pNextListItem = v30;
      if ( v15 == v8->m_mmapPausedPending.m_pLast )
        v8->m_mmapPausedPending.m_pLast = v16;
      v15->pNextListItem = v8->m_mmapPausedPending.m_pFree;
      --v8->m_mmapPausedPending.m_ulNumListItems;
      v8->m_mmapPausedPending.m_pFree = v15;
      ((void (*)(void))v17->pAction->vfptr->Release)();
      v31 = g_DefaultPoolId;
      ((void (__fastcall *)(AkPendingAction *, _QWORD))v17->vfptr[1].TransUpdateValue)(v17, 0i64);
      AK::MemoryMgr::Free(v31, v17);
      _mm_store_si128(&v32, v33);
      v16 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v32.m128i_i64[1];
      v15 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v32.m128i_i64[0];
      goto LABEL_30;
    }
LABEL_29:
    v16 = v15;
    v15 = v15->pNextListItem;
LABEL_30:
    if ( v20 )
      v20->vfptr->Release((CAkIndexable *)&v20->vfptr);
  }
  return 1i64;
}

// File Line: 1947
// RVA: 0xA48A40
void __fastcall CAkAudioMgr::PausePendingActionAllExcept(CAkAudioMgr *this, CAkRegisteredObj *in_GameObj, AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *in_pExceptionList, bool in_bIsMasterOnResume, unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // rbx
  CAkRegisteredObj *v6; // r15
  CAkAudioMgr *v7; // rsi
  bool i; // r13
  AkPendingAction *v9; // rdi
  CAkAction *v10; // rbp
  char v11; // al
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v12; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *j; // rdi
  AkPendingAction *v14; // rbp
  CAkAction *v15; // r14
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v16; // rax
  __m128i v17; // [rsp+20h] [rbp-48h]
  __m128i v18; // [rsp+30h] [rbp-38h]
  AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *in_pExceptionLista; // [rsp+80h] [rbp+18h]

  in_pExceptionLista = in_pExceptionList;
  v5 = this->m_mmapPausedPending.m_pFirst;
  v6 = in_GameObj;
  v7 = this;
  for ( i = in_bIsMasterOnResume; v5; v5 = v5->pNextListItem )
  {
    v9 = v5->Item.item;
    v10 = v9->pAction;
    if ( ((v10->m_eActionType & 0xFF00) != 768 || i)
      && (!v6 || v6 == v9->pGameObj)
      && (!in_PlayingID || in_PlayingID == v9->UserParam.m_PlayingID) )
    {
      v11 = CAkAudioMgr::IsAnException(v7, v9->pAction, in_pExceptionList);
      in_pExceptionList = in_pExceptionLista;
      if ( !v11 && v10->m_eActionType != 6176 )
        ++v9->ulPauseCount;
    }
  }
  v12 = v7->m_mmapPending.m_pFirst;
  for ( j = 0i64; v12; in_pExceptionList = in_pExceptionLista )
  {
    v14 = v12->Item.item;
    v15 = v14->pAction;
    if ( (v15->m_eActionType & 0xFF00) == 768 && !i
      || v6 && v6 != v14->pGameObj
      || in_PlayingID && in_PlayingID != v14->UserParam.m_PlayingID
      || CAkAudioMgr::IsAnException(v7, v14->pAction, in_pExceptionList)
      || v15->m_eActionType == 6176 )
    {
      j = v12;
      v12 = v12->pNextListItem;
    }
    else
    {
      CAkAudioMgr::InsertAsPaused(v7, v15->m_ulElementID, v14, 0);
      v16 = v12->pNextListItem;
      v17.m128i_i64[1] = (__int64)j;
      v17.m128i_i64[0] = (__int64)v12->pNextListItem;
      if ( v12 == v7->m_mmapPending.m_pFirst )
        v7->m_mmapPending.m_pFirst = v16;
      else
        j->pNextListItem = v16;
      if ( v12 == v7->m_mmapPending.m_pLast )
        v7->m_mmapPending.m_pLast = j;
      v12->pNextListItem = v7->m_mmapPending.m_pFree;
      --v7->m_mmapPending.m_ulNumListItems;
      _mm_store_si128(&v18, v17);
      j = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v18.m128i_i64[1];
      v7->m_mmapPending.m_pFree = v12;
      v12 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v18.m128i_i64[0];
    }
  }
}

// File Line: 2010
// RVA: 0xA4BCE0
signed __int64 __fastcall CAkAudioMgr::StopPendingActionAllExcept(CAkAudioMgr *this, CAkRegisteredObj *in_GameObj, AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *in_pExceptionList, unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v4; // rdi
  unsigned int v5; // ebp
  AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v6; // r12
  CAkRegisteredObj *v7; // r15
  CAkAudioMgr *v8; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v9; // r14
  AkPendingAction *v10; // rsi
  CAkActionPlayAndContinue *v11; // rcx
  int v12; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v13; // rax
  int v14; // edi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v15; // rdi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v16; // r14
  AkPendingAction *v17; // rsi
  CAkActionPlayAndContinue *v18; // rcx
  int v19; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v20; // rax
  int v21; // edi
  __m128i v23; // [rsp+20h] [rbp-98h]
  __m128i v24; // [rsp+30h] [rbp-88h]
  int v25; // [rsp+40h] [rbp-78h]

  v4 = this->m_mmapPending.m_pFirst;
  v5 = in_PlayingID;
  v6 = in_pExceptionList;
  v7 = in_GameObj;
  v8 = this;
  v9 = 0i64;
  if ( v4 )
  {
    while ( 1 )
    {
      v10 = v4->Item.item;
      if ( (!v7 || v7 == v10->pGameObj)
        && (!v5 || v5 == v10->UserParam.m_PlayingID)
        && !CAkAudioMgr::IsAnException(v8, v10->pAction, v6) )
      {
        v11 = (CAkActionPlayAndContinue *)v10->pAction;
        LOWORD(v12) = v11->m_eActionType;
        if ( (_WORD)v12 != 6176 )
          break;
      }
      v9 = v4;
      v4 = v4->pNextListItem;
LABEL_19:
      if ( !v4 )
        goto LABEL_20;
    }
    v12 = (unsigned __int16)v12;
    v25 = 0;
    if ( (unsigned __int16)v12 != 1027 )
    {
      if ( v12 != 1283 )
      {
LABEL_12:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v10->UserParam.m_PlayingID);
        v13 = v4->pNextListItem;
        v23.m128i_i64[1] = (__int64)v9;
        v23.m128i_i64[0] = (__int64)v13;
        if ( v4 == v8->m_mmapPending.m_pFirst )
          v8->m_mmapPending.m_pFirst = v13;
        else
          v9->pNextListItem = v13;
        if ( v4 == v8->m_mmapPending.m_pLast )
          v8->m_mmapPending.m_pLast = v9;
        v4->pNextListItem = v8->m_mmapPending.m_pFree;
        --v8->m_mmapPending.m_ulNumListItems;
        v8->m_mmapPending.m_pFree = v4;
        ((void (*)(void))v10->pAction->vfptr->Release)();
        v14 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))v10->vfptr[1].TransUpdateValue)(v10, 0i64);
        AK::MemoryMgr::Free(v14, v10);
        _mm_store_si128(&v24, v23);
        v9 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v24.m128i_i64[1];
        v4 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v24.m128i_i64[0];
        goto LABEL_19;
      }
      CAkActionPlayAndContinue::NeedNotifyDelay(v11);
    }
    ((void (__fastcall *)(CAkIndexableVtbl **, int *))v10->pAction->vfptr[2].Category)(&v10->pAction->vfptr, &v25);
    goto LABEL_12;
  }
LABEL_20:
  v15 = v8->m_mmapPausedPending.m_pFirst;
  v16 = 0i64;
  if ( v15 )
  {
    while ( 1 )
    {
      v17 = v15->Item.item;
      if ( (!v7 || v7 == v17->pGameObj)
        && (!v5 || v5 == v17->UserParam.m_PlayingID)
        && !CAkAudioMgr::IsAnException(v8, v17->pAction, v6) )
      {
        v18 = (CAkActionPlayAndContinue *)v17->pAction;
        LOWORD(v19) = v18->m_eActionType;
        if ( (_WORD)v19 != 6176 )
          break;
      }
      v16 = v15;
      v15 = v15->pNextListItem;
LABEL_38:
      if ( !v15 )
        return 1i64;
    }
    v19 = (unsigned __int16)v19;
    v25 = 0;
    if ( (unsigned __int16)v19 != 1027 )
    {
      if ( v19 != 1283 )
      {
LABEL_31:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v17->UserParam.m_PlayingID);
        v20 = v15->pNextListItem;
        v24.m128i_i64[1] = (__int64)v16;
        v24.m128i_i64[0] = (__int64)v20;
        if ( v15 == v8->m_mmapPausedPending.m_pFirst )
          v8->m_mmapPausedPending.m_pFirst = v20;
        else
          v16->pNextListItem = v20;
        if ( v15 == v8->m_mmapPausedPending.m_pLast )
          v8->m_mmapPausedPending.m_pLast = v16;
        v15->pNextListItem = v8->m_mmapPausedPending.m_pFree;
        --v8->m_mmapPausedPending.m_ulNumListItems;
        v8->m_mmapPausedPending.m_pFree = v15;
        ((void (*)(void))v17->pAction->vfptr->Release)();
        v21 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))v17->vfptr[1].TransUpdateValue)(v17, 0i64);
        AK::MemoryMgr::Free(v21, v17);
        _mm_store_si128(&v23, v24);
        v16 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v23.m128i_i64[1];
        v15 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v23.m128i_i64[0];
        goto LABEL_38;
      }
      CAkActionPlayAndContinue::NeedNotifyDelay(v18);
    }
    ((void (__fastcall *)(CAkIndexableVtbl **, int *))v17->pAction->vfptr[2].Category)(&v17->pAction->vfptr, &v25);
    goto LABEL_31;
  }
  return 1i64;
}

// File Line: 2073
// RVA: 0xA4B010
void __fastcall CAkAudioMgr::ResumePausedPendingAction(CAkAudioMgr *this, CAkParameterNodeBase *in_pNodeToTarget, CAkRegisteredObj *in_GameObj, bool in_bIsMasterOnResume, unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v6; // r15
  bool v7; // al
  CAkRegisteredObj *v8; // r12
  CAkParameterNodeBase *v9; // rdi
  CAkAudioMgr *v10; // r14
  AkPendingAction *v11; // rbp
  CAkParameterNodeBase *v12; // rax
  CAkParameterNodeBase *v13; // rsi
  CAkParameterNodeBase *v14; // rdx
  CAkParameterNodeBase *v15; // rcx
  unsigned int v16; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v17; // rax
  __m128i v18; // [rsp+30h] [rbp-48h]
  __m128i v19; // [rsp+40h] [rbp-38h]
  bool v20; // [rsp+98h] [rbp+20h]

  v20 = in_bIsMasterOnResume;
  v5 = this->m_mmapPausedPending.m_pFirst;
  v6 = 0i64;
  v7 = in_bIsMasterOnResume;
  v8 = in_GameObj;
  v9 = in_pNodeToTarget;
  v10 = this;
  if ( v5 )
  {
    while ( 1 )
    {
      v11 = v5->Item.item;
      v12 = CAkAction::GetAndRefTarget(v11->pAction);
      v13 = v12;
      if ( v9 )
      {
        if ( !v12 )
          goto LABEL_18;
        if ( v9 != v12 )
        {
          v14 = v12->m_pParentNode;
          v15 = v12->m_pBusOutputNode;
          if ( v14 )
          {
            while ( v9 != v14 )
            {
              if ( !v15 )
                v15 = v14->m_pBusOutputNode;
              v14 = v14->m_pParentNode;
              if ( !v14 )
                goto LABEL_10;
            }
          }
          else
          {
LABEL_10:
            if ( !v15 )
              goto LABEL_18;
            while ( v9 != v15 )
            {
              v15 = v15->m_pBusOutputNode;
              if ( !v15 )
              {
                v6 = v5;
                v5 = v5->pNextListItem;
                goto LABEL_28;
              }
            }
          }
        }
      }
      if ( (!v8 || v8 == v11->pGameObj) && (!in_PlayingID || in_PlayingID == v11->UserParam.m_PlayingID) )
      {
        if ( v20 || (v16 = v11->ulPauseCount) == 0 )
        {
          CAkAudioMgr::TransferToPending(v10, v11);
          v17 = v5->pNextListItem;
          v18.m128i_i64[1] = (__int64)v6;
          v18.m128i_i64[0] = (__int64)v5->pNextListItem;
          if ( v5 == v10->m_mmapPausedPending.m_pFirst )
            v10->m_mmapPausedPending.m_pFirst = v17;
          else
            v6->pNextListItem = v17;
          if ( v5 == v10->m_mmapPausedPending.m_pLast )
            v10->m_mmapPausedPending.m_pLast = v6;
          v5->pNextListItem = v10->m_mmapPausedPending.m_pFree;
          --v10->m_mmapPausedPending.m_ulNumListItems;
          _mm_store_si128(&v19, v18);
          v6 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v19.m128i_i64[1];
          v10->m_mmapPausedPending.m_pFree = v5;
          v5 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v19.m128i_i64[0];
        }
        else
        {
          v6 = v5;
          v11->ulPauseCount = v16 - 1;
          v5 = v5->pNextListItem;
        }
        goto LABEL_28;
      }
LABEL_18:
      v6 = v5;
      v5 = v5->pNextListItem;
LABEL_28:
      if ( v13 )
        v13->vfptr->Release((CAkIndexable *)&v13->vfptr);
      if ( !v5 )
      {
        v7 = v20;
        break;
      }
    }
  }
  CAkAudioMgr::ResumeNotPausedPendingAction(v10, v9, v8, v7, in_PlayingID);
}

// File Line: 2109
// RVA: 0xA4B310
void __fastcall CAkAudioMgr::ResumePausedPendingItems(CAkAudioMgr *this, unsigned int in_playingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v2; // rdi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v3; // rsi
  unsigned int v4; // ebp
  CAkAudioMgr *v5; // rbx
  AkPendingAction *v6; // rcx
  unsigned int v7; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v8; // rax
  __m128i v9; // [rsp+20h] [rbp-28h]
  __m128i v10; // [rsp+30h] [rbp-18h]

  v2 = this->m_mmapPausedPending.m_pFirst;
  v3 = 0i64;
  v4 = in_playingID;
  v5 = this;
  while ( v2 )
  {
    v6 = v2->Item.item;
    if ( v6->UserParam.m_PlayingID == v4 )
    {
      v7 = v6->ulPauseCount;
      if ( !v7 )
      {
        CAkAudioMgr::TransferToPending(v5, v2->Item.item);
        v8 = v2->pNextListItem;
        v9.m128i_i64[1] = (__int64)v3;
        v9.m128i_i64[0] = (__int64)v2->pNextListItem;
        if ( v2 == v5->m_mmapPausedPending.m_pFirst )
          v5->m_mmapPausedPending.m_pFirst = v8;
        else
          v3->pNextListItem = v8;
        if ( v2 == v5->m_mmapPausedPending.m_pLast )
          v5->m_mmapPausedPending.m_pLast = v3;
        v2->pNextListItem = v5->m_mmapPausedPending.m_pFree;
        --v5->m_mmapPausedPending.m_ulNumListItems;
        _mm_store_si128(&v10, v9);
        v3 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v10.m128i_i64[1];
        v5->m_mmapPausedPending.m_pFree = v2;
        v2 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v10.m128i_i64[0];
        continue;
      }
      v6->ulPauseCount = v7 - 1;
    }
    v3 = v2;
    v2 = v2->pNextListItem;
  }
}

// File Line: 2142
// RVA: 0xA4AE50
void __fastcall CAkAudioMgr::ResumeNotPausedPendingAction(CAkAudioMgr *this, CAkParameterNodeBase *in_pNodeToTarget, CAkRegisteredObj *in_GameObj, bool __formal, unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // rsi
  CAkRegisteredObj *v6; // r12
  CAkParameterNodeBase *v7; // rbx
  AkPendingAction *v8; // rbp
  CAkActionPlayAndContinue *v9; // r14
  CAkParameterNodeBase *v10; // rax
  CAkParameterNodeBase *v11; // rdi
  CAkParameterNodeBase *v12; // rdx
  CAkParameterNodeBase *v13; // rcx

  v5 = this->m_mmapPending.m_pFirst;
  v6 = in_GameObj;
  v7 = in_pNodeToTarget;
  while ( v5 )
  {
    v8 = v5->Item.item;
    v9 = (CAkActionPlayAndContinue *)v8->pAction;
    v10 = CAkAction::GetAndRefTarget(v8->pAction);
    v11 = v10;
    if ( !v7 )
      goto LABEL_14;
    if ( v10 )
    {
      if ( v7 == v10 )
        goto LABEL_14;
      v12 = v10->m_pParentNode;
      v13 = v10->m_pBusOutputNode;
      if ( v12 )
      {
        while ( v7 != v12 )
        {
          if ( !v13 )
            v13 = v12->m_pBusOutputNode;
          v12 = v12->m_pParentNode;
          if ( !v12 )
            goto LABEL_10;
        }
        goto LABEL_14;
      }
LABEL_10:
      if ( v13 )
      {
        while ( v7 != v13 )
        {
          v13 = v13->m_pBusOutputNode;
          if ( !v13 )
            goto LABEL_20;
        }
LABEL_14:
        if ( (!v6 || v6 == v8->pGameObj)
          && (!in_PlayingID || in_PlayingID == v8->UserParam.m_PlayingID)
          && v9->m_eActionType == 1283 )
        {
          CAkActionPlayAndContinue::Resume(v9);
        }
        goto LABEL_20;
      }
    }
LABEL_20:
    v5 = v5->pNextListItem;
    if ( v11 )
      v11->vfptr->Release((CAkIndexable *)&v11->vfptr);
  }
}

// File Line: 2180
// RVA: 0xA4B1D0
void __fastcall CAkAudioMgr::ResumePausedPendingActionAllExcept(CAkAudioMgr *this, CAkRegisteredObj *in_GameObj, AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *in_pExceptionList, bool in_bIsMasterOnResume, unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v6; // r14
  bool v7; // r12
  AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v8; // r13
  CAkRegisteredObj *v9; // rbp
  CAkAudioMgr *v10; // rdi
  AkPendingAction *v11; // rsi
  unsigned int v12; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v13; // rax
  __m128i v14; // [rsp+30h] [rbp-48h]
  __int128 v15; // [rsp+40h] [rbp-38h]

  v5 = this->m_mmapPausedPending.m_pFirst;
  v6 = 0i64;
  v7 = in_bIsMasterOnResume;
  v8 = in_pExceptionList;
  v9 = in_GameObj;
  v10 = this;
  while ( v5 )
  {
    v11 = v5->Item.item;
    if ( (!v9 || v9 == v11->pGameObj)
      && (!in_PlayingID || in_PlayingID == v11->UserParam.m_PlayingID)
      && !CAkAudioMgr::IsAnException(v10, v11->pAction, v8) )
    {
      if ( v7 || (v12 = v11->ulPauseCount) == 0 )
      {
        CAkAudioMgr::TransferToPending(v10, v11);
        v13 = v5->pNextListItem;
        v14.m128i_i64[1] = (__int64)v6;
        v14.m128i_i64[0] = (__int64)v5->pNextListItem;
        if ( v5 == v10->m_mmapPausedPending.m_pFirst )
          v10->m_mmapPausedPending.m_pFirst = v13;
        else
          v6->pNextListItem = v13;
        if ( v5 == v10->m_mmapPausedPending.m_pLast )
          v10->m_mmapPausedPending.m_pLast = v6;
        v5->pNextListItem = v10->m_mmapPausedPending.m_pFree;
        --v10->m_mmapPausedPending.m_ulNumListItems;
        _mm_store_si128((__m128i *)&v15, v14);
        v6 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)*((_QWORD *)&v15 + 1);
        v10->m_mmapPausedPending.m_pFree = v5;
        v5 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v15;
        continue;
      }
      v11->ulPauseCount = v12 - 1;
    }
    v6 = v5;
    v5 = v5->pNextListItem;
  }
  CAkAudioMgr::ResumeNotPausedPendingActionAllExcept(g_pAudioMgr, v9, v8, v7, in_PlayingID);
}

// File Line: 2216
// RVA: 0xA4AF60
void __fastcall CAkAudioMgr::ResumeNotPausedPendingActionAllExcept(CAkAudioMgr *this, CAkRegisteredObj *in_GameObj, AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *in_pExceptionList, bool __formal, unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // rbx
  AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v6; // r15
  CAkRegisteredObj *v7; // rbp
  CAkAudioMgr *i; // r14
  AkPendingAction *v9; // rax
  CAkActionPlayAndContinue *v10; // rdi

  v5 = this->m_mmapPending.m_pFirst;
  v6 = in_pExceptionList;
  v7 = in_GameObj;
  for ( i = this; v5; v5 = v5->pNextListItem )
  {
    v9 = v5->Item.item;
    v10 = (CAkActionPlayAndContinue *)v9->pAction;
    if ( (!v7 || v7 == v9->pGameObj)
      && (!in_PlayingID || in_PlayingID == v9->UserParam.m_PlayingID)
      && !CAkAudioMgr::IsAnException(i, v9->pAction, v6)
      && v10->m_eActionType == 1283 )
    {
      CAkActionPlayAndContinue::Resume(v10);
    }
  }
}

// File Line: 2246
// RVA: 0xA4AB10
void __fastcall CAkAudioMgr::RemovePendingAction(CAkAudioMgr *this, CAkParameterNodeBase *in_pNodeToTarget)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v2; // rbx
  CAkParameterNodeBase *v3; // rdi
  CAkAudioMgr *v4; // rbp
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // r15
  AkPendingAction *v6; // r14
  CAkAction *v7; // r12
  CAkParameterNodeBase *v8; // rax
  CAkParameterNodeBase *v9; // rsi
  CAkParameterNodeBase *v10; // rdx
  CAkParameterNodeBase *v11; // rcx
  CAkActionPlayAndContinue *v12; // rcx
  int v13; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v14; // rax
  int v15; // ebx
  __m128i v16; // [rsp+20h] [rbp-98h]
  __int128 v17; // [rsp+30h] [rbp-88h]
  int v18; // [rsp+40h] [rbp-78h]

  v2 = this->m_mmapPending.m_pFirst;
  v3 = in_pNodeToTarget;
  v4 = this;
  v5 = 0i64;
  while ( v2 )
  {
    v6 = v2->Item.item;
    v7 = v6->pAction;
    v8 = CAkAction::GetAndRefTarget(v6->pAction);
    v9 = v8;
    if ( !v3 || !v8 )
      goto LABEL_13;
    if ( v3 != v8 )
    {
      v10 = v8->m_pParentNode;
      v11 = v8->m_pBusOutputNode;
      if ( v10 )
      {
        while ( v3 != v10 )
        {
          if ( !v11 )
            v11 = v10->m_pBusOutputNode;
          v10 = v10->m_pParentNode;
          if ( !v10 )
            goto LABEL_10;
        }
      }
      else
      {
LABEL_10:
        if ( !v11 )
          goto LABEL_13;
        while ( v3 != v11 )
        {
          v11 = v11->m_pBusOutputNode;
          if ( !v11 )
            goto LABEL_13;
        }
      }
    }
    if ( v7->m_eActionType != 6176 )
    {
      v12 = (CAkActionPlayAndContinue *)v6->pAction;
      v18 = 0;
      v13 = v12->m_eActionType;
      if ( v13 == 1027 )
        goto LABEL_22;
      if ( v13 == 1283 )
      {
        CAkActionPlayAndContinue::NeedNotifyDelay(v12);
LABEL_22:
        ((void (__fastcall *)(CAkAction *, int *))v6->pAction->vfptr[2].Category)(v6->pAction, &v18);
      }
      CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v6->UserParam.m_PlayingID);
      v14 = v2->pNextListItem;
      v16.m128i_i64[1] = (__int64)v5;
      v16.m128i_i64[0] = (__int64)v2->pNextListItem;
      if ( v2 == v4->m_mmapPending.m_pFirst )
        v4->m_mmapPending.m_pFirst = v14;
      else
        v5->pNextListItem = v14;
      if ( v2 == v4->m_mmapPending.m_pLast )
        v4->m_mmapPending.m_pLast = v5;
      v2->pNextListItem = v4->m_mmapPending.m_pFree;
      --v4->m_mmapPending.m_ulNumListItems;
      v4->m_mmapPending.m_pFree = v2;
      ((void (*)(void))v6->pAction->vfptr->Release)();
      v15 = g_DefaultPoolId;
      ((void (__fastcall *)(AkPendingAction *, _QWORD))v6->vfptr[1].TransUpdateValue)(v6, 0i64);
      AK::MemoryMgr::Free(v15, v6);
      _mm_store_si128((__m128i *)&v17, v16);
      v5 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)*((_QWORD *)&v17 + 1);
      v2 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v17;
      goto LABEL_14;
    }
LABEL_13:
    v5 = v2;
    v2 = v2->pNextListItem;
LABEL_14:
    if ( v9 )
      v9->vfptr->Release((CAkIndexable *)&v9->vfptr);
  }
}

// File Line: 2274
// RVA: 0xA4A960
void __fastcall CAkAudioMgr::RemovePausedPendingAction(CAkAudioMgr *this, CAkParameterNodeBase *in_pNodeToTarget)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v2; // rbx
  CAkParameterNodeBase *v3; // rdi
  CAkAudioMgr *v4; // rbp
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // r15
  AkPendingAction *v6; // r14
  CAkParameterNodeBase *v7; // rax
  CAkParameterNodeBase *v8; // rsi
  CAkParameterNodeBase *v9; // rdx
  CAkParameterNodeBase *v10; // rcx
  CAkActionPlayAndContinue *v11; // rcx
  int v12; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v13; // rax
  int v14; // ebx
  __m128i v15; // [rsp+20h] [rbp-88h]
  __int128 v16; // [rsp+30h] [rbp-78h]
  int v17; // [rsp+40h] [rbp-68h]

  v2 = this->m_mmapPausedPending.m_pFirst;
  v3 = in_pNodeToTarget;
  v4 = this;
  v5 = 0i64;
  while ( v2 )
  {
    v6 = v2->Item.item;
    v7 = CAkAction::GetAndRefTarget(v6->pAction);
    v8 = v7;
    if ( v3 && v7 )
    {
      if ( v3 == v7 )
        goto LABEL_18;
      v9 = v7->m_pParentNode;
      v10 = v7->m_pBusOutputNode;
      if ( v9 )
      {
        while ( v3 != v9 )
        {
          if ( !v10 )
            v10 = v9->m_pBusOutputNode;
          v9 = v9->m_pParentNode;
          if ( !v9 )
            goto LABEL_10;
        }
LABEL_18:
        v11 = (CAkActionPlayAndContinue *)v6->pAction;
        v17 = 0;
        v12 = v11->m_eActionType;
        if ( v12 == 1027 )
        {
LABEL_21:
          ((void (__fastcall *)(CAkAction *, int *))v6->pAction->vfptr[2].Category)(v6->pAction, &v17);
        }
        else if ( v12 == 1283 )
        {
          CAkActionPlayAndContinue::NeedNotifyDelay(v11);
          goto LABEL_21;
        }
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v6->UserParam.m_PlayingID);
        v13 = v2->pNextListItem;
        v15.m128i_i64[1] = (__int64)v5;
        v15.m128i_i64[0] = (__int64)v2->pNextListItem;
        if ( v2 == v4->m_mmapPausedPending.m_pFirst )
          v4->m_mmapPausedPending.m_pFirst = v13;
        else
          v5->pNextListItem = v13;
        if ( v2 == v4->m_mmapPausedPending.m_pLast )
          v4->m_mmapPausedPending.m_pLast = v5;
        v2->pNextListItem = v4->m_mmapPausedPending.m_pFree;
        --v4->m_mmapPausedPending.m_ulNumListItems;
        v4->m_mmapPausedPending.m_pFree = v2;
        ((void (*)(void))v6->pAction->vfptr->Release)();
        v14 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))v6->vfptr[1].TransUpdateValue)(v6, 0i64);
        AK::MemoryMgr::Free(v14, v6);
        _mm_store_si128((__m128i *)&v16, v15);
        v5 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)*((_QWORD *)&v16 + 1);
        v2 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v16;
        goto LABEL_14;
      }
LABEL_10:
      if ( v10 )
      {
        while ( v3 != v10 )
        {
          v10 = v10->m_pBusOutputNode;
          if ( !v10 )
            goto LABEL_13;
        }
        goto LABEL_18;
      }
    }
LABEL_13:
    v5 = v2;
    v2 = v2->pNextListItem;
LABEL_14:
    if ( v8 )
      v8->vfptr->Release((CAkIndexable *)&v8->vfptr);
  }
}

// File Line: 2305
// RVA: 0xA4A5D0
void __fastcall CAkAudioMgr::RemoveAllPausedPendingAction(CAkAudioMgr *this)
{
  CAkAudioMgr *v1; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v2; // rdi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v3; // r14
  AkPendingAction *v4; // rsi
  CAkActionPlayAndContinue *v5; // rcx
  int v6; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v7; // rbp
  int v8; // edi
  __m128i v9; // [rsp+20h] [rbp-88h]
  __int128 v10; // [rsp+30h] [rbp-78h]
  int v11; // [rsp+40h] [rbp-68h]

  v1 = this;
  if ( this->m_mmapPausedPending.m_ulMaxNumListItems )
  {
    v2 = this->m_mmapPausedPending.m_pFirst;
    v3 = 0i64;
    if ( v2 )
    {
      while ( 1 )
      {
        v4 = v2->Item.item;
        v11 = 0;
        v5 = (CAkActionPlayAndContinue *)v4->pAction;
        v6 = v5->m_eActionType;
        if ( v6 != 1027 )
        {
          if ( v6 != 1283 )
            goto LABEL_7;
          CAkActionPlayAndContinue::NeedNotifyDelay(v5);
        }
        ((void (__fastcall *)(CAkAction *, int *))v4->pAction->vfptr[2].Category)(v4->pAction, &v11);
LABEL_7:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v4->UserParam.m_PlayingID);
        v7 = v2->pNextListItem;
        v9.m128i_i64[1] = (__int64)v3;
        v9.m128i_i64[0] = (__int64)v2->pNextListItem;
        if ( v2 == v1->m_mmapPausedPending.m_pFirst )
          v1->m_mmapPausedPending.m_pFirst = v7;
        else
          v3->pNextListItem = v7;
        if ( v2 == v1->m_mmapPausedPending.m_pLast )
          v1->m_mmapPausedPending.m_pLast = v3;
        v2->pNextListItem = v1->m_mmapPausedPending.m_pFree;
        --v1->m_mmapPausedPending.m_ulNumListItems;
        v1->m_mmapPausedPending.m_pFree = v2;
        ((void (*)(void))v4->pAction->vfptr->Release)();
        v8 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))v4->vfptr[1].TransUpdateValue)(v4, 0i64);
        AK::MemoryMgr::Free(v8, v4);
        _mm_store_si128((__m128i *)&v10, v9);
        if ( !v7 )
          return;
        v3 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)*((_QWORD *)&v10 + 1);
        v2 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v10;
      }
    }
  }
}

// File Line: 2331
// RVA: 0xA4A720
void __fastcall CAkAudioMgr::RemoveAllPendingAction(CAkAudioMgr *this)
{
  CAkAudioMgr *v1; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v2; // rdi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v3; // r14
  AkPendingAction *v4; // rsi
  CAkActionPlayAndContinue *v5; // rcx
  int v6; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v7; // rbp
  int v8; // edi
  __m128i v9; // [rsp+20h] [rbp-88h]
  __int128 v10; // [rsp+30h] [rbp-78h]
  int v11; // [rsp+40h] [rbp-68h]

  v1 = this;
  if ( this->m_mmapPending.m_ulMaxNumListItems )
  {
    v2 = this->m_mmapPending.m_pFirst;
    v3 = 0i64;
    if ( v2 )
    {
      while ( 1 )
      {
        v4 = v2->Item.item;
        v11 = 0;
        v5 = (CAkActionPlayAndContinue *)v4->pAction;
        v6 = v5->m_eActionType;
        if ( v6 != 1027 )
        {
          if ( v6 != 1283 )
            goto LABEL_7;
          CAkActionPlayAndContinue::NeedNotifyDelay(v5);
        }
        ((void (__fastcall *)(CAkAction *, int *))v4->pAction->vfptr[2].Category)(v4->pAction, &v11);
LABEL_7:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v4->UserParam.m_PlayingID);
        v7 = v2->pNextListItem;
        v9.m128i_i64[1] = (__int64)v3;
        v9.m128i_i64[0] = (__int64)v2->pNextListItem;
        if ( v2 == v1->m_mmapPending.m_pFirst )
          v1->m_mmapPending.m_pFirst = v7;
        else
          v3->pNextListItem = v7;
        if ( v2 == v1->m_mmapPending.m_pLast )
          v1->m_mmapPending.m_pLast = v3;
        v2->pNextListItem = v1->m_mmapPending.m_pFree;
        --v1->m_mmapPending.m_ulNumListItems;
        v1->m_mmapPending.m_pFree = v2;
        ((void (*)(void))v4->pAction->vfptr->Release)();
        v8 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))v4->vfptr[1].TransUpdateValue)(v4, 0i64);
        AK::MemoryMgr::Free(v8, v4);
        _mm_store_si128((__m128i *)&v10, v9);
        if ( !v7 )
          return;
        v3 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)*((_QWORD *)&v10 + 1);
        v2 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v10;
      }
    }
  }
}

// File Line: 2359
// RVA: 0xA4A850
void __fastcall CAkAudioMgr::RemoveAllPreallocAndReferences(CAkAudioMgr *this)
{
  CAkAudioMgr *v1; // rsi
  char *v2; // rax
  char *v3; // rbx
  AkExternalSourceArray *v4; // rcx

  v1 = this;
  EnterCriticalSection(&this->m_queueLock.m_csLock);
  while ( v1->m_MsgQueue.m_uReadBlock != v1->m_MsgQueue.m_uWriteBlock
       || v1->m_MsgQueue.m_uReadOffset != v1->m_MsgQueue.m_uWriteOffset
       || v1->m_MsgQueue.m_bBufferFull )
  {
    v2 = AkSparseChunkRing::BeginRead(&v1->m_MsgQueue);
    v3 = v2;
    switch ( *((_WORD *)v2 + 1) )
    {
      case 1:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, *((_DWORD *)v2 + 4));
        (*(void (**)(void))(**((_QWORD **)v3 + 6) + 16i64))();
        v4 = (AkExternalSourceArray *)*((_QWORD *)v3 + 5);
        if ( v4 )
          AkExternalSourceArray::Release(v4);
LABEL_16:
        AkSparseChunkRing::EndRead(&v1->m_MsgQueue, *(unsigned __int16 *)v3);
        break;
      case 0xB:
        goto LABEL_16;
      case 0x17:
        if ( *((_DWORD *)v2 + 4) == 3 )
        {
          CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, *(_DWORD *)(*((_QWORD *)v2 + 1) + 120i64));
          (*(void (**)(void))(**((_QWORD **)v3 + 1) + 16i64))();
        }
        (*(void (**)(void))(**((_QWORD **)v3 + 1) + 16i64))();
        AkSparseChunkRing::EndRead(&v1->m_MsgQueue, *(unsigned __int16 *)v3);
        break;
      case 0x1F:
      case 0x23:
        (*(void (**)(void))(**((_QWORD **)v2 + 1) + 16i64))();
        AkSparseChunkRing::EndRead(&v1->m_MsgQueue, *(unsigned __int16 *)v3);
        break;
      default:
        goto LABEL_16;
    }
  }
  LeaveCriticalSection(&v1->m_queueLock.m_csLock);
}

// File Line: 2545
// RVA: 0xA4B540
signed __int64 __fastcall CAkAudioMgr::StopAction(CAkAudioMgr *this, unsigned int in_ActionID, unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v3; // rdi
  unsigned int v4; // ebp
  unsigned int v5; // er15
  CAkAudioMgr *v6; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v7; // r14
  AkPendingAction *v8; // rsi
  CAkActionPlayAndContinue *v9; // rcx
  int v10; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v11; // rax
  int v12; // edi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v13; // rdi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v14; // r14
  AkPendingAction *v15; // rsi
  CAkActionPlayAndContinue *v16; // rcx
  int v17; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v18; // rax
  int v19; // edi
  __m128i v21; // [rsp+20h] [rbp-88h]
  __m128i v22; // [rsp+30h] [rbp-78h]
  int v23; // [rsp+40h] [rbp-68h]

  v3 = this->m_mmapPending.m_pFirst;
  v4 = in_PlayingID;
  v5 = in_ActionID;
  v6 = this;
  v7 = 0i64;
  if ( v3 )
  {
    while ( 1 )
    {
      v8 = v3->Item.item;
      v9 = (CAkActionPlayAndContinue *)v8->pAction;
      if ( v9->key == v5 && (!v4 || v8->UserParam.m_PlayingID == v4) )
        break;
      v7 = v3;
      v3 = v3->pNextListItem;
LABEL_16:
      if ( !v3 )
        goto LABEL_17;
    }
    v23 = 0;
    v10 = v9->m_eActionType;
    if ( v10 != 1027 )
    {
      if ( v10 != 1283 )
      {
LABEL_9:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v8->UserParam.m_PlayingID);
        v11 = v3->pNextListItem;
        v21.m128i_i64[1] = (__int64)v7;
        v21.m128i_i64[0] = (__int64)v11;
        if ( v3 == v6->m_mmapPending.m_pFirst )
          v6->m_mmapPending.m_pFirst = v11;
        else
          v7->pNextListItem = v11;
        if ( v3 == v6->m_mmapPending.m_pLast )
          v6->m_mmapPending.m_pLast = v7;
        v3->pNextListItem = v6->m_mmapPending.m_pFree;
        --v6->m_mmapPending.m_ulNumListItems;
        v6->m_mmapPending.m_pFree = v3;
        ((void (*)(void))v8->pAction->vfptr->Release)();
        v12 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))v8->vfptr[1].TransUpdateValue)(v8, 0i64);
        AK::MemoryMgr::Free(v12, v8);
        _mm_store_si128(&v22, v21);
        v7 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v22.m128i_i64[1];
        v3 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v22.m128i_i64[0];
        goto LABEL_16;
      }
      CAkActionPlayAndContinue::NeedNotifyDelay(v9);
    }
    ((void (__fastcall *)(CAkIndexableVtbl **, int *))v8->pAction->vfptr[2].Category)(&v8->pAction->vfptr, &v23);
    goto LABEL_9;
  }
LABEL_17:
  v13 = v6->m_mmapPausedPending.m_pFirst;
  v14 = 0i64;
  if ( v13 )
  {
    while ( 1 )
    {
      v15 = v13->Item.item;
      v16 = (CAkActionPlayAndContinue *)v15->pAction;
      if ( v16->key == v5 && (!v4 || v15->UserParam.m_PlayingID == v4) )
        break;
      v14 = v13;
      v13 = v13->pNextListItem;
LABEL_32:
      if ( !v13 )
        return 1i64;
    }
    v23 = 0;
    v17 = v16->m_eActionType;
    if ( v17 != 1027 )
    {
      if ( v17 != 1283 )
      {
LABEL_25:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v15->UserParam.m_PlayingID);
        v18 = v13->pNextListItem;
        v22.m128i_i64[1] = (__int64)v14;
        v22.m128i_i64[0] = (__int64)v18;
        if ( v13 == v6->m_mmapPausedPending.m_pFirst )
          v6->m_mmapPausedPending.m_pFirst = v18;
        else
          v14->pNextListItem = v18;
        if ( v13 == v6->m_mmapPausedPending.m_pLast )
          v6->m_mmapPausedPending.m_pLast = v14;
        v13->pNextListItem = v6->m_mmapPausedPending.m_pFree;
        --v6->m_mmapPausedPending.m_ulNumListItems;
        v6->m_mmapPausedPending.m_pFree = v13;
        ((void (*)(void))v15->pAction->vfptr->Release)();
        v19 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))v15->vfptr[1].TransUpdateValue)(v15, 0i64);
        AK::MemoryMgr::Free(v19, v15);
        _mm_store_si128(&v21, v22);
        v14 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v21.m128i_i64[1];
        v13 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v21.m128i_i64[0];
        goto LABEL_32;
      }
      CAkActionPlayAndContinue::NeedNotifyDelay(v16);
    }
    ((void (__fastcall *)(CAkIndexableVtbl **, int *))v15->pAction->vfptr[2].Category)(&v15->pAction->vfptr, &v23);
    goto LABEL_25;
  }
  return 1i64;
}

// File Line: 2588
// RVA: 0xA485E0
signed __int64 __fastcall CAkAudioMgr::PauseAction(CAkAudioMgr *this, unsigned int in_ActionID, unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v3; // rax
  unsigned int v4; // ebp
  unsigned int v5; // er14
  CAkAudioMgr *i; // rbx
  AkPendingAction *v7; // r9
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v8; // rdi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v9; // rsi
  AkPendingAction *v10; // r8
  CAkAction *v11; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v12; // rax
  __m128i v14; // [rsp+20h] [rbp-28h]
  __m128i v15; // [rsp+30h] [rbp-18h]

  v3 = this->m_mmapPausedPending.m_pFirst;
  v4 = in_PlayingID;
  v5 = in_ActionID;
  for ( i = this; v3; v3 = v3->pNextListItem )
  {
    v7 = v3->Item.item;
    if ( in_ActionID == v7->pAction->key && (!in_PlayingID || v7->UserParam.m_PlayingID == in_PlayingID) )
      ++v7->ulPauseCount;
  }
  v8 = this->m_mmapPending.m_pFirst;
  v9 = 0i64;
  while ( v8 )
  {
    v10 = v8->Item.item;
    v11 = v10->pAction;
    if ( v5 != v11->key || v4 && v10->UserParam.m_PlayingID != v4 )
    {
      v9 = v8;
      v8 = v8->pNextListItem;
    }
    else
    {
      CAkAudioMgr::InsertAsPaused(i, v11->m_ulElementID, v10, 0);
      v12 = v8->pNextListItem;
      v14.m128i_i64[1] = (__int64)v9;
      v14.m128i_i64[0] = (__int64)v8->pNextListItem;
      if ( v8 == i->m_mmapPending.m_pFirst )
        i->m_mmapPending.m_pFirst = v12;
      else
        v9->pNextListItem = v12;
      if ( v8 == i->m_mmapPending.m_pLast )
        i->m_mmapPending.m_pLast = v9;
      v8->pNextListItem = i->m_mmapPending.m_pFree;
      --i->m_mmapPending.m_ulNumListItems;
      _mm_store_si128(&v15, v14);
      v9 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v15.m128i_i64[1];
      i->m_mmapPending.m_pFree = v8;
      v8 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v15.m128i_i64[0];
    }
  }
  return 1i64;
}

// File Line: 2640
// RVA: 0xA4AD40
signed __int64 __fastcall CAkAudioMgr::ResumeAction(CAkAudioMgr *this, unsigned int in_ActionID, unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v3; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v4; // rsi
  unsigned int v5; // ebp
  unsigned int v6; // er14
  CAkAudioMgr *v7; // rdi
  AkPendingAction *v8; // rcx
  unsigned int v9; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v10; // rax
  __m128i v12; // [rsp+20h] [rbp-28h]
  __m128i v13; // [rsp+30h] [rbp-18h]

  v3 = this->m_mmapPausedPending.m_pFirst;
  v4 = 0i64;
  v5 = in_PlayingID;
  v6 = in_ActionID;
  v7 = this;
  while ( v3 )
  {
    v8 = v3->Item.item;
    if ( v8->pAction->key == v6 && (!v5 || v8->UserParam.m_PlayingID == v5) )
    {
      v9 = v8->ulPauseCount;
      if ( !v9 )
      {
        CAkAudioMgr::TransferToPending(v7, v3->Item.item);
        v10 = v3->pNextListItem;
        v12.m128i_i64[1] = (__int64)v4;
        v12.m128i_i64[0] = (__int64)v3->pNextListItem;
        if ( v3 == v7->m_mmapPausedPending.m_pFirst )
          v7->m_mmapPausedPending.m_pFirst = v10;
        else
          v4->pNextListItem = v10;
        if ( v3 == v7->m_mmapPausedPending.m_pLast )
          v7->m_mmapPausedPending.m_pLast = v4;
        v3->pNextListItem = v7->m_mmapPausedPending.m_pFree;
        --v7->m_mmapPausedPending.m_ulNumListItems;
        _mm_store_si128(&v13, v12);
        v4 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v13.m128i_i64[1];
        v7->m_mmapPausedPending.m_pFree = v3;
        v3 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v13.m128i_i64[0];
        continue;
      }
      v8->ulPauseCount = v9 - 1;
    }
    v4 = v3;
    v3 = v3->pNextListItem;
  }
  return 1i64;
}

// File Line: 2680
// RVA: 0xA47D60
void __fastcall CAkAudioMgr::ClearPendingItems(CAkAudioMgr *this, unsigned int in_PlayingID)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v2; // rdi
  unsigned int v3; // ebp
  CAkAudioMgr *v4; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // r14
  AkPendingAction *v6; // rsi
  CAkActionPlayAndContinue *v7; // rcx
  int v8; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v9; // rax
  int v10; // edi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v11; // rdi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v12; // r14
  AkPendingAction *v13; // rsi
  CAkActionPlayAndContinue *v14; // rcx
  int v15; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v16; // rax
  int v17; // edi
  __m128i v18; // [rsp+20h] [rbp-88h]
  __m128i v19; // [rsp+30h] [rbp-78h]
  int v20; // [rsp+40h] [rbp-68h]

  v2 = this->m_mmapPending.m_pFirst;
  v3 = in_PlayingID;
  v4 = this;
  v5 = 0i64;
  if ( v2 )
  {
    while ( 1 )
    {
      v6 = v2->Item.item;
      if ( v6->UserParam.m_PlayingID == v3 )
        break;
      v5 = v2;
      v2 = v2->pNextListItem;
LABEL_14:
      if ( !v2 )
        goto LABEL_15;
    }
    v7 = (CAkActionPlayAndContinue *)v6->pAction;
    v20 = 0;
    v8 = v7->m_eActionType;
    if ( v8 != 1027 )
    {
      if ( v8 != 1283 )
      {
LABEL_7:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v6->UserParam.m_PlayingID);
        v9 = v2->pNextListItem;
        v18.m128i_i64[1] = (__int64)v5;
        v18.m128i_i64[0] = (__int64)v9;
        if ( v2 == v4->m_mmapPending.m_pFirst )
          v4->m_mmapPending.m_pFirst = v9;
        else
          v5->pNextListItem = v9;
        if ( v2 == v4->m_mmapPending.m_pLast )
          v4->m_mmapPending.m_pLast = v5;
        v2->pNextListItem = v4->m_mmapPending.m_pFree;
        --v4->m_mmapPending.m_ulNumListItems;
        v4->m_mmapPending.m_pFree = v2;
        ((void (*)(void))v6->pAction->vfptr->Release)();
        v10 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))v6->vfptr[1].TransUpdateValue)(v6, 0i64);
        AK::MemoryMgr::Free(v10, v6);
        _mm_store_si128(&v19, v18);
        v5 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v19.m128i_i64[1];
        v2 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v19.m128i_i64[0];
        goto LABEL_14;
      }
      CAkActionPlayAndContinue::NeedNotifyDelay(v7);
    }
    ((void (__fastcall *)(CAkIndexableVtbl **, int *))v6->pAction->vfptr[2].Category)(&v6->pAction->vfptr, &v20);
    goto LABEL_7;
  }
LABEL_15:
  v11 = v4->m_mmapPausedPending.m_pFirst;
  v12 = 0i64;
  if ( v11 )
  {
    while ( 1 )
    {
      v13 = v11->Item.item;
      if ( v13->UserParam.m_PlayingID == v3 )
        break;
      v12 = v11;
      v11 = v11->pNextListItem;
LABEL_28:
      if ( !v11 )
        return;
    }
    v14 = (CAkActionPlayAndContinue *)v13->pAction;
    v20 = 0;
    v15 = v14->m_eActionType;
    if ( v15 != 1027 )
    {
      if ( v15 != 1283 )
      {
LABEL_21:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v13->UserParam.m_PlayingID);
        v16 = v11->pNextListItem;
        v19.m128i_i64[1] = (__int64)v12;
        v19.m128i_i64[0] = (__int64)v16;
        if ( v11 == v4->m_mmapPausedPending.m_pFirst )
          v4->m_mmapPausedPending.m_pFirst = v16;
        else
          v12->pNextListItem = v16;
        if ( v11 == v4->m_mmapPausedPending.m_pLast )
          v4->m_mmapPausedPending.m_pLast = v12;
        v11->pNextListItem = v4->m_mmapPausedPending.m_pFree;
        --v4->m_mmapPausedPending.m_ulNumListItems;
        v4->m_mmapPausedPending.m_pFree = v11;
        ((void (*)(void))v13->pAction->vfptr->Release)();
        v17 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))v13->vfptr[1].TransUpdateValue)(v13, 0i64);
        AK::MemoryMgr::Free(v17, v13);
        _mm_store_si128(&v18, v19);
        v12 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v18.m128i_i64[1];
        v11 = (CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *)v18.m128i_i64[0];
        goto LABEL_28;
      }
      CAkActionPlayAndContinue::NeedNotifyDelay(v14);
    }
    ((void (__fastcall *)(CAkIndexableVtbl **, int *))v13->pAction->vfptr[2].Category)(&v13->pAction->vfptr, &v20);
    goto LABEL_21;
  }
}

// File Line: 2798
// RVA: 0xA47CC0
void __fastcall CAkAudioMgr::ClearCrossFadeOccurence(CAkAudioMgr *this, CAkContinuousPBI *in_pPBIToCheck)
{
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v2; // rbx
  CAkContinuousPBI *v3; // rdi
  CAkAudioMgr *i; // rsi
  CAkActionPlayAndContinue *v5; // rcx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *j; // rbx
  CAkActionPlayAndContinue *v7; // rcx

  v2 = this->m_mmapPending.m_pFirst;
  v3 = in_pPBIToCheck;
  for ( i = this; v2; v2 = v2->pNextListItem )
  {
    v5 = (CAkActionPlayAndContinue *)v2->Item.item->pAction;
    if ( v5->m_eActionType == 1283 )
      CAkActionPlayAndContinue::UnsetFadeBack(v5, v3);
  }
  for ( j = i->m_mmapPausedPending.m_pFirst; j; j = j->pNextListItem )
  {
    v7 = (CAkActionPlayAndContinue *)j->Item.item->pAction;
    if ( v7->m_eActionType == 1283 )
      CAkActionPlayAndContinue::UnsetFadeBack(v7, v3);
  }
}

// File Line: 2831
// RVA: 0xA48420
char __fastcall CAkAudioMgr::IsAnException(CAkAudioMgr *this, CAkAction *in_pAction, AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *in_pExceptionList)
{
  AkArray<WwiseObjectIDext,WwiseObjectIDext const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v3; // rsi
  CAkParameterNodeBase *v5; // rbx
  char v6; // di
  CAkParameterNodeBase *v7; // r8
  CAkParameterNodeBase *v8; // r11
  WwiseObjectIDext *v9; // r10
  signed __int64 v10; // rdx
  WwiseObjectIDext *v11; // rcx
  WwiseObjectIDext *v12; // rax

  v3 = in_pExceptionList;
  if ( !in_pExceptionList )
    return 0;
  v5 = 0i64;
  v6 = 0;
  if ( !in_pAction->m_ulElementID )
    return 0;
  v7 = CAkAction::GetAndRefTarget(in_pAction);
  v8 = v7;
  if ( !v7 )
    return 0;
  v9 = v3->m_pItems;
  v10 = (signed __int64)&v3->m_pItems[v3->m_uLength];
  do
  {
    v11 = v3->m_pItems;
    if ( v9 != (WwiseObjectIDext *)v10 )
    {
      while ( v7->key != v11->id || ((*((_BYTE *)v7 + 83) >> 1) & 1) != v11->bIsBus )
      {
        ++v11;
        if ( v11 == (WwiseObjectIDext *)v10 )
          goto LABEL_10;
      }
      goto LABEL_22;
    }
LABEL_10:
    if ( !v6 )
    {
      v5 = v7->m_pBusOutputNode;
      v6 = 0;
      if ( v5 )
        v6 = 1;
    }
    v7 = v7->m_pParentNode;
  }
  while ( v7 );
  if ( !v5 )
  {
LABEL_20:
    v8->vfptr->Release((CAkIndexable *)&v8->vfptr);
    return 0;
  }
  while ( 1 )
  {
    v12 = v3->m_pItems;
    if ( v9 != (WwiseObjectIDext *)v10 )
      break;
LABEL_19:
    v5 = v5->m_pBusOutputNode;
    if ( !v5 )
      goto LABEL_20;
  }
  while ( v5->key != v12->id || ((*((_BYTE *)v5 + 83) >> 1) & 1) != v12->bIsBus )
  {
    ++v12;
    if ( v12 == (WwiseObjectIDext *)v10 )
      goto LABEL_19;
  }
LABEL_22:
  v8->vfptr->Release((CAkIndexable *)&v8->vfptr);
  return 1;
}

// File Line: 2960
// RVA: 0xA4B4E0
AKRESULT __fastcall CAkAudioMgr::Start(CAkAudioMgr *this)
{
  CAkAudioMgr *v1; // rbx
  HANDLE v2; // rax
  AKRESULT result; // eax

  v1 = this;
  v2 = CreateEventW(0i64, 1, 0, 0i64);
  v1->m_hEventMgrThreadDrainEvent.m_Event = v2;
  if ( v2 )
    result = CAkAudioThread::Start(&v1->m_audioThread);
  else
    result = 2;
  return result;
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
  this->vfptr = (ITransitionableVtbl *)&AkPendingAction::`vftable';
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
  CAkRegisteredObj *v1; // rdi
  AkPendingAction *v2; // rsi
  int v3; // er8
  int v4; // ebx
  AkExternalSourceArray *v5; // rcx

  v1 = this->pGameObj;
  v2 = this;
  this->vfptr = (ITransitionableVtbl *)&AkPendingAction::`vftable';
  if ( v1 )
  {
    v3 = *((_DWORD *)v1 + 30) ^ (*((_DWORD *)v1 + 30) ^ (*((_DWORD *)v1 + 30) - 1)) & 0x3FFFFFFF;
    *((_DWORD *)v1 + 30) = v3;
    if ( !(v3 & 0x3FFFFFFF) )
    {
      v4 = g_DefaultPoolId;
      CAkRegisteredObj::~CAkRegisteredObj(v1);
      AK::MemoryMgr::Free(v4, v1);
    }
  }
  v5 = v2->UserParam.m_CustomParam.pExternalSrcs;
  if ( v5 )
    AkExternalSourceArray::Release(v5);
}

// File Line: 2998
// RVA: 0xA4C0A0
void __fastcall AkPendingAction::TransUpdateValue(AkPendingAction *this, __int64 in_eTarget, float __formal, bool in_bIsTerminated)
{
  CAkAction *v4; // rbx

  v4 = this->pAction;
  if ( v4->m_eActionType == 1283 )
  {
    if ( ((_DWORD)in_eTarget - 0x1000000) & 0xFEFFFFFF )
    {
      if ( !(((_DWORD)in_eTarget - 0x4000000) & 0xFBFFFFFF) && in_bIsTerminated )
      {
        LOBYTE(v4[1].pNextLightItem) &= 0xFDu;
        *(_QWORD *)&v4[1].key = 0i64;
        if ( (_DWORD)in_eTarget == 0x4000000 )
          CAkAudioMgr::PausePending(g_pAudioMgr, this);
        LODWORD(v4[4].pNextItem) = 0;
      }
    }
    else if ( in_bIsTerminated )
    {
      LOBYTE(v4[1].pNextLightItem) &= 0xFEu;
      v4[1].pNextItem = 0i64;
      if ( (_DWORD)in_eTarget == 0x2000000 )
        CAkAudioMgr::StopPending(g_pAudioMgr, this);
    }
  }
}

// File Line: 3049
// RVA: 0xA486E0
signed __int64 __fastcall CAkAudioMgr::PausePending(CAkAudioMgr *this, AkPendingAction *in_pPA)
{
  CAkAudioMgr *v2; // rdi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v3; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v4; // rsi
  AkPendingAction *v5; // r8
  CAkAction *v6; // rax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v7; // rax
  AkPendingAction *v8; // rcx
  CAkAction *v9; // r8
  unsigned int v10; // er9
  int v11; // er9
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v12; // rax

  v2 = this;
  if ( in_pPA )
  {
    v3 = this->m_mmapPending.m_pFirst;
    v4 = 0i64;
    if ( v3 )
    {
      while ( 1 )
      {
        v5 = v3->Item.item;
        v6 = v5->pAction;
        if ( v5 == in_pPA )
          break;
        v4 = v3;
        v3 = v3->pNextListItem;
        if ( !v3 )
          goto LABEL_5;
      }
      v10 = 0;
      if ( v6->m_eActionType == 1283 )
      {
        v11 = (int)v6[4].pNextItem;
        LODWORD(v6[4].pNextItem) = 0;
        v10 = v11 - 1;
      }
      CAkAudioMgr::InsertAsPaused(this, v6->m_ulElementID, v5, v10);
      v12 = v3->pNextListItem;
      if ( v3 == v2->m_mmapPending.m_pFirst )
        v2->m_mmapPending.m_pFirst = v12;
      else
        v4->pNextListItem = v12;
      if ( v3 == v2->m_mmapPending.m_pLast )
        v2->m_mmapPending.m_pLast = v4;
      v3->pNextListItem = v2->m_mmapPending.m_pFree;
      --v2->m_mmapPending.m_ulNumListItems;
      v2->m_mmapPending.m_pFree = v3;
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
signed __int64 __fastcall CAkAudioMgr::StopPending(CAkAudioMgr *this, AkPendingAction *in_pPA)
{
  AkPendingAction *v2; // rdi
  CAkAudioMgr *v3; // rsi
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v4; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v5; // r14
  CAkActionPlayAndContinue *v6; // rcx
  int v7; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v8; // rax
  int v9; // ebx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v10; // rbx
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v11; // r14
  CAkActionPlayAndContinue *v12; // rcx
  int v13; // eax
  CAkList2<MapStruct<unsigned long,AkPendingAction *>,MapStruct<unsigned long,AkPendingAction *> const &,2,ArrayPoolDefault>::ListItem *v14; // rax
  int v15; // ebx
  int v17; // [rsp+20h] [rbp-58h]

  v2 = in_pPA;
  v3 = this;
  if ( !in_pPA )
    return 1i64;
  v4 = this->m_mmapPausedPending.m_pFirst;
  v5 = 0i64;
  if ( v4 )
  {
    while ( in_pPA != v4->Item.item )
    {
      v5 = v4;
      v4 = v4->pNextListItem;
      if ( !v4 )
        goto LABEL_16;
    }
    v6 = (CAkActionPlayAndContinue *)in_pPA->pAction;
    v17 = 0;
    v7 = v6->m_eActionType;
    if ( v7 != 1027 )
    {
      if ( v7 != 1283 )
      {
LABEL_10:
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v2->UserParam.m_PlayingID);
        v8 = v4->pNextListItem;
        if ( v4 == v3->m_mmapPausedPending.m_pFirst )
          v3->m_mmapPausedPending.m_pFirst = v8;
        else
          v5->pNextListItem = v8;
        if ( v4 == v3->m_mmapPausedPending.m_pLast )
          v3->m_mmapPausedPending.m_pLast = v5;
        v4->pNextListItem = v3->m_mmapPausedPending.m_pFree;
        --v3->m_mmapPausedPending.m_ulNumListItems;
        v3->m_mmapPausedPending.m_pFree = v4;
        ((void (__cdecl *)(CAkAction *))v2->pAction->vfptr->Release)(v2->pAction);
        v9 = g_DefaultPoolId;
        ((void (__fastcall *)(AkPendingAction *, _QWORD))v2->vfptr[1].TransUpdateValue)(v2, 0i64);
        AK::MemoryMgr::Free(v9, v2);
        goto LABEL_16;
      }
      CAkActionPlayAndContinue::NeedNotifyDelay(v6);
    }
    ((void (__fastcall *)(CAkAction *, int *))v2->pAction->vfptr[2].Category)(v2->pAction, &v17);
    goto LABEL_10;
  }
LABEL_16:
  v10 = v3->m_mmapPending.m_pFirst;
  v11 = 0i64;
  if ( !v10 )
    return 1i64;
  while ( v2 != v10->Item.item )
  {
    v11 = v10;
    v10 = v10->pNextListItem;
    if ( !v10 )
      return 1i64;
  }
  v12 = (CAkActionPlayAndContinue *)v2->pAction;
  v17 = 0;
  v13 = v12->m_eActionType;
  if ( v13 == 1027 )
    goto LABEL_23;
  if ( v13 == 1283 )
  {
    CAkActionPlayAndContinue::NeedNotifyDelay(v12);
LABEL_23:
    ((void (__fastcall *)(CAkAction *, int *))v2->pAction->vfptr[2].Category)(v2->pAction, &v17);
  }
  CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v2->UserParam.m_PlayingID);
  v14 = v10->pNextListItem;
  if ( v10 == v3->m_mmapPending.m_pFirst )
    v3->m_mmapPending.m_pFirst = v14;
  else
    v11->pNextListItem = v14;
  if ( v10 == v3->m_mmapPending.m_pLast )
    v3->m_mmapPending.m_pLast = v11;
  v10->pNextListItem = v3->m_mmapPending.m_pFree;
  --v3->m_mmapPending.m_ulNumListItems;
  v3->m_mmapPending.m_pFree = v10;
  ((void (__cdecl *)(CAkAction *))v2->pAction->vfptr->Release)(v2->pAction);
  v15 = g_DefaultPoolId;
  ((void (__fastcall *)(AkPendingAction *, _QWORD))v2->vfptr[1].TransUpdateValue)(v2, 0i64);
  AK::MemoryMgr::Free(v15, v2);
  return 1i64;
}

