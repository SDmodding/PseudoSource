// File Line: 37
// RVA: 0xA43ED0
void __fastcall CAkDynamicSequence::CAkDynamicSequence(
        CAkDynamicSequence *this,
        unsigned int in_playingID,
        AK::SoundEngine::DynamicSequence::DynamicSequenceType in_eDynamicSequenceType)
{
  CAkIndexable::CAkIndexable(this, in_playingID);
  this->vfptr = (CAkIndexableVtbl *)&CAkDynamicSequence::`vftable;
  this->m_playList.m_pItems = 0i64;
  *(_QWORD *)&this->m_playList.m_uLength = 0i64;
  InitializeCriticalSection(&this->m_lockPlaylist.m_csLock);
  this->m_eState = State_Stopped;
  this->m_pGameObj = 0i64;
  this->m_userParams.m_CustomParam.customParam = 0i64;
  this->m_userParams.m_CustomParam.ui32Reserved = 0;
  this->m_userParams.m_CustomParam.pExternalSrcs = 0i64;
  this->m_bClosed = 0;
  this->m_eDynamicSequenceType = in_eDynamicSequenceType;
  *(_QWORD *)&this->m_playingItem.audioNodeID = 0i64;
  this->m_playingItem.pCustomInfo = 0i64;
  this->m_playingItem.pExternalSrcs = 0i64;
  *(_QWORD *)&this->m_queuedItem.audioNodeID = 0i64;
  this->m_queuedItem.pCustomInfo = 0i64;
  this->m_queuedItem.pExternalSrcs = 0i64;
  *(_QWORD *)&this->m_ulPauseCount = 0i64;
  this->m_playingItem.audioNodeID = 0;
  this->m_queuedItem.audioNodeID = 0;
  this->m_userParams.m_PlayingID = in_playingID;
}

// File Line: 46
// RVA: 0xA43F90
void __fastcall CAkDynamicSequence::~CAkDynamicSequence(CAkDynamicSequence *this)
{
  CAkRegisteredObj *m_pGameObj; // rsi
  int v3; // ecx
  int v4; // ebx
  AkExternalSourceArray *pExternalSrcs; // rcx
  AkExternalSourceArray *v6; // rcx
  AkExternalSourceArray *v7; // rcx

  this->vfptr = (CAkIndexableVtbl *)&CAkDynamicSequence::`vftable;
  if ( this->m_playList.m_pItems )
  {
    AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::RemoveAll(&this->m_playList);
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_playList.m_pItems);
    this->m_playList.m_pItems = 0i64;
    this->m_playList.m_ulReserved = 0;
  }
  m_pGameObj = this->m_pGameObj;
  if ( m_pGameObj )
  {
    v3 = *((_DWORD *)m_pGameObj + 30) ^ (*((_DWORD *)m_pGameObj + 30) ^ (*((_DWORD *)m_pGameObj + 30) - 1)) & 0x3FFFFFFF;
    *((_DWORD *)m_pGameObj + 30) = v3;
    if ( (v3 & 0x3FFFFFFF) == 0 )
    {
      v4 = g_DefaultPoolId;
      CAkRegisteredObj::~CAkRegisteredObj(m_pGameObj);
      AK::MemoryMgr::Free(v4, m_pGameObj);
    }
  }
  pExternalSrcs = this->m_queuedItem.pExternalSrcs;
  if ( pExternalSrcs )
    AkExternalSourceArray::Release(pExternalSrcs);
  v6 = this->m_playingItem.pExternalSrcs;
  if ( v6 )
    AkExternalSourceArray::Release(v6);
  v7 = this->m_userParams.m_CustomParam.pExternalSrcs;
  if ( v7 )
    AkExternalSourceArray::Release(v7);
  DeleteCriticalSection(&this->m_lockPlaylist.m_csLock);
  CAkPBIAware::~CAkPBIAware(this);
}

// File Line: 53
// RVA: 0xA44330
void __fastcall CAkDynamicSequence::Create(
        unsigned int in_PlayingID,
        AK::SoundEngine::DynamicSequence::DynamicSequenceType in_eDynamicSequenceType)
{
  CAkDynamicSequence *v4; // rax
  CAkDynamicSequence *v5; // rax

  v4 = (CAkDynamicSequence *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xC0ui64);
  if ( v4 )
  {
    CAkDynamicSequence::CAkDynamicSequence(v4, in_PlayingID, in_eDynamicSequenceType);
    if ( v5 )
      CAkDynamicSequence::AddToIndex(v5);
  }
}

// File Line: 72
// RVA: 0xA441D0
void __fastcall CAkDynamicSequence::AddToIndex(CAkDynamicSequence *this)
{
  CAkIndexItem<CAkDynamicSequence *> *p_m_idxDynamicSequences; // rdi
  _RTL_CRITICAL_SECTION_DEBUG **v3; // rdx

  p_m_idxDynamicSequences = &g_pIndex->m_idxDynamicSequences;
  EnterCriticalSection(&g_pIndex->m_idxDynamicSequences.m_IndexLock.m_csLock);
  v3 = &p_m_idxDynamicSequences->m_IndexLock.m_csLock.DebugInfo + this->key % 0xC1;
  this->pNextItem = (CAkIndexable *)v3[5];
  v3[5] = (_RTL_CRITICAL_SECTION_DEBUG *)this;
  ++p_m_idxDynamicSequences->m_mapIDToPtr.m_uiSize;
  LeaveCriticalSection(&p_m_idxDynamicSequences->m_IndexLock.m_csLock);
}

// File Line: 84
// RVA: 0xA44180
__int64 __fastcall CAkDynamicSequence::AddRef(CAkDynamicSequence *this)
{
  CAkAudioLibIndex *v1; // rbx
  unsigned int v3; // edi

  v1 = g_pIndex;
  EnterCriticalSection(&g_pIndex->m_idxDynamicSequences.m_IndexLock.m_csLock);
  v3 = this->m_lRef + 1;
  this->m_lRef = v3;
  LeaveCriticalSection(&v1->m_idxDynamicSequences.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 90
// RVA: 0xA448A0
__int64 __fastcall CAkDynamicSequence::Release(CAkDynamicSequence *this)
{
  CAkAudioLibIndex *v1; // rbx
  bool v3; // zf
  unsigned int m_lRef; // ebp
  int v5; // edi

  v1 = g_pIndex;
  EnterCriticalSection(&g_pIndex->m_idxDynamicSequences.m_IndexLock.m_csLock);
  v3 = this->m_lRef-- == 1;
  m_lRef = this->m_lRef;
  if ( v3 )
  {
    CAkIndexItem<CAkEvent *>::RemoveID(
      (CAkIndexItem<CAkParameterNodeBase *> *)&g_pIndex->m_idxDynamicSequences,
      this->key);
    v5 = g_DefaultPoolId;
    this->vfptr->__vecDelDtor(this, 0i64);
    AK::MemoryMgr::Free(v5, this);
  }
  LeaveCriticalSection(&v1->m_idxDynamicSequences.m_IndexLock.m_csLock);
  return m_lRef;
}

// File Line: 109
// RVA: 0xA44390
void __fastcall CAkDynamicSequence::CreatePBI(
        CAkDynamicSequence *this,
        CAkSoundBase *in_pSound,
        CAkSource *in_pSource,
        AkPBIParams *in_rPBIParams,
        PriorityInfoCurrent *in_rPriority,
        CAkLimiter *in_pAMLimiter,
        CAkLimiter *in_pBusLimiter)
{
  CAkDynamicSequencePBI *v11; // rsi

  v11 = (CAkDynamicSequencePBI *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x298ui64);
  if ( v11 )
    CAkDynamicSequencePBI::CAkDynamicSequencePBI(
      v11,
      in_pSound,
      in_pSource,
      in_rPBIParams->pGameObj,
      in_rPBIParams->pContinuousParams,
      &in_rPBIParams->userParams,
      &in_rPBIParams->playHistory,
      in_rPBIParams->bIsFirst,
      in_rPBIParams->sequenceID,
      in_rPBIParams->pInstigator,
      in_rPriority,
      this->m_eDynamicSequenceType,
      in_pAMLimiter,
      in_pBusLimiter);
}

// File Line: 127
// RVA: 0xA44B40
void __fastcall CAkDynamicSequence::SetGameObject(CAkDynamicSequence *this, CAkRegisteredObj *in_pGameObj)
{
  this->m_pGameObj = in_pGameObj;
  if ( in_pGameObj )
    *((_DWORD *)in_pGameObj + 30) ^= (*((_DWORD *)in_pGameObj + 30) ^ (*((_DWORD *)in_pGameObj + 30) + 1)) & 0x3FFFFFFF;
}

// File Line: 135
// RVA: 0xA44BF0
__int64 __fastcall CAkDynamicSequence::_GetNextToPlay(
        CAkDynamicSequence *this,
        int *out_delay,
        void **out_rpCustomParam)
{
  CAkLock *p_m_lockPlaylist; // rbx
  AK::SoundEngine::DynamicSequence::PlaylistItem *m_pItems; // rsi
  unsigned int audioNodeID; // edi

  if ( !this->m_pGameObj )
    return 0i64;
  p_m_lockPlaylist = &this->m_lockPlaylist;
  this->m_queuedItem.audioNodeID = 0;
  EnterCriticalSection(&this->m_lockPlaylist.m_csLock);
  if ( this->m_eState )
  {
    if ( this->m_playList.m_uLength )
    {
      while ( 1 )
      {
        m_pItems = this->m_playList.m_pItems;
        *out_rpCustomParam = m_pItems->pCustomInfo;
        if ( m_pItems->audioNodeID )
          break;
        AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::Erase(
          &this->m_playList,
          0);
        CAkPlayingMgr::NotifyEndOfDynamicSequenceItem(
          g_pPlayingMgr,
          this->m_userParams.m_PlayingID,
          0,
          *out_rpCustomParam);
        if ( !this->m_playList.m_uLength )
          goto LABEL_9;
      }
      AK::SoundEngine::DynamicSequence::PlaylistItem::operator=(&this->m_queuedItem, m_pItems);
      *out_delay = m_pItems->msDelay;
      AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::Erase(
        &this->m_playList,
        0);
    }
LABEL_9:
    if ( !this->m_queuedItem.audioNodeID )
      this->m_eState = State_Running;
  }
  audioNodeID = this->m_queuedItem.audioNodeID;
  LeaveCriticalSection(&p_m_lockPlaylist->m_csLock);
  return audioNodeID;
}

// File Line: 181
// RVA: 0xA44530
__int64 __fastcall CAkDynamicSequence::GetNextToPlay(
        CAkDynamicSequence *this,
        int *out_delay,
        void **out_rpCustomParam,
        UserParams *out_rUserParam)
{
  AkExternalSourceArray *pExternalSrcs; // rcx
  AkExternalSourceArray *v9; // rax
  unsigned int NextToPlay; // eax
  AkExternalSourceArray *v11; // rcx
  AkExternalSourceArray *v12; // rbx
  unsigned int v13; // esi
  __int64 result; // rax

  pExternalSrcs = this->m_playingItem.pExternalSrcs;
  if ( pExternalSrcs )
    AkExternalSourceArray::Release(pExternalSrcs);
  this->m_playingItem.audioNodeID = this->m_queuedItem.audioNodeID;
  this->m_playingItem.msDelay = this->m_queuedItem.msDelay;
  this->m_playingItem.pCustomInfo = this->m_queuedItem.pCustomInfo;
  v9 = this->m_queuedItem.pExternalSrcs;
  this->m_playingItem.pExternalSrcs = v9;
  if ( v9 )
    ++v9->m_cRefCount;
  NextToPlay = CAkDynamicSequence::_GetNextToPlay(this, out_delay, out_rpCustomParam);
  v11 = out_rUserParam->m_CustomParam.pExternalSrcs;
  v12 = this->m_queuedItem.pExternalSrcs;
  v13 = NextToPlay;
  if ( v11 )
    AkExternalSourceArray::Release(v11);
  result = v13;
  if ( v12 )
    ++v12->m_cRefCount;
  out_rUserParam->m_CustomParam.pExternalSrcs = v12;
  return result;
}

// File Line: 190
// RVA: 0xA446E0
__int64 __fastcall CAkDynamicSequence::Play(
        CAkDynamicSequence *this,
        int in_uTransitionDuration,
        AkCurveInterpolation in_eFadeCurve)
{
  int msDelay; // r15d
  void *pCustomInfo; // rbp
  unsigned int audioNodeID; // esi
  AK::SoundEngine::DynamicSequence::PlaylistItem *m_pItems; // rsi
  AkExternalSourceArray *pExternalSrcs; // rcx
  AkExternalSourceArray *v11; // rax
  AkExternalSourceArray *v12; // rcx
  AkExternalSourceArray *v13; // rbx

  if ( (this->m_eState & 0xFFFFFFFD) != 0 || this->m_ulPauseCount )
    return 1i64;
  this->m_eState = State_Paused;
  msDelay = 0;
  while ( 1 )
  {
    pCustomInfo = 0i64;
    if ( this->m_pGameObj )
    {
      this->m_queuedItem.audioNodeID = 0;
      EnterCriticalSection(&this->m_lockPlaylist.m_csLock);
      if ( this->m_eState )
      {
        if ( this->m_playList.m_uLength )
        {
          while ( 1 )
          {
            m_pItems = this->m_playList.m_pItems;
            pCustomInfo = m_pItems->pCustomInfo;
            if ( m_pItems->audioNodeID )
              break;
            AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::Erase(
              &this->m_playList,
              0);
            CAkPlayingMgr::NotifyEndOfDynamicSequenceItem(g_pPlayingMgr, this->m_userParams.m_PlayingID, 0, pCustomInfo);
            if ( !this->m_playList.m_uLength )
              goto LABEL_16;
          }
          pExternalSrcs = this->m_queuedItem.pExternalSrcs;
          if ( pExternalSrcs )
            AkExternalSourceArray::Release(pExternalSrcs);
          this->m_queuedItem.audioNodeID = m_pItems->audioNodeID;
          this->m_queuedItem.msDelay = m_pItems->msDelay;
          this->m_queuedItem.pCustomInfo = m_pItems->pCustomInfo;
          v11 = m_pItems->pExternalSrcs;
          this->m_queuedItem.pExternalSrcs = v11;
          if ( v11 )
            ++v11->m_cRefCount;
          msDelay = m_pItems->msDelay;
          AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::Erase(
            &this->m_playList,
            0);
        }
LABEL_16:
        if ( !this->m_queuedItem.audioNodeID )
          this->m_eState = State_Running;
      }
      audioNodeID = this->m_queuedItem.audioNodeID;
      LeaveCriticalSection(&this->m_lockPlaylist.m_csLock);
    }
    else
    {
      audioNodeID = 0;
    }
    v12 = this->m_userParams.m_CustomParam.pExternalSrcs;
    v13 = this->m_queuedItem.pExternalSrcs;
    if ( v12 )
      AkExternalSourceArray::Release(v12);
    if ( v13 )
      ++v13->m_cRefCount;
    this->m_userParams.m_CustomParam.pExternalSrcs = v13;
    if ( !audioNodeID
      || CAkDynamicSequence::_PlayNode(this, audioNodeID, msDelay, in_uTransitionDuration, in_eFadeCurve) == AK_Success )
    {
      return 1i64;
    }
    CAkPlayingMgr::NotifyEndOfDynamicSequenceItem(
      g_pPlayingMgr,
      this->m_userParams.m_PlayingID,
      audioNodeID,
      pCustomInfo);
  }
}

// File Line: 223
// RVA: 0xA44B60
AKRESULT __fastcall CAkDynamicSequence::Stop(
        CAkDynamicSequence *this,
        int in_uTransitionDuration,
        AkCurveInterpolation in_eFadeCurve)
{
  this->m_uSequenceID = 0;
  return CAkDynamicSequence::_Stop(this, AK_StopImmediate, in_uTransitionDuration, in_eFadeCurve);
}

// File Line: 233
// RVA: 0xA442A0
__int64 __fastcall CAkDynamicSequence::Break(CAkDynamicSequence *this)
{
  unsigned int m_PlayingID; // edx
  unsigned int audioNodeID; // edx
  CAkParameterNodeBase *NodePtrAndAddRef; // rax
  CAkParameterNodeBase *v5; // rdi

  this->m_uSequenceID = 0;
  if ( this->m_eState )
  {
    m_PlayingID = this->m_userParams.m_PlayingID;
    this->m_eState = State_Stopped;
    this->m_ulPauseCount = 0;
    CAkAudioMgr::ClearPendingItems(g_pAudioMgr, m_PlayingID);
    audioNodeID = this->m_playingItem.audioNodeID;
    if ( audioNodeID )
    {
      NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, audioNodeID, AkNodeType_Default);
      v5 = NodePtrAndAddRef;
      if ( NodePtrAndAddRef )
      {
        ((void (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *, CAkParameterNodeBase *, _QWORD))NodePtrAndAddRef->vfptr[4].Category)(
          NodePtrAndAddRef,
          this->m_pGameObj,
          NodePtrAndAddRef,
          this->m_userParams.m_PlayingID);
        v5->vfptr->Release(v5);
      }
    }
  }
  return 1i64;
}

// File Line: 244
// RVA: 0xA44EF0
__int64 __fastcall CAkDynamicSequence::_Stop(
        CAkDynamicSequence *this,
        CAkDynamicSequence::AkDynamicSequenceStopMode in_eStopMode,
        int in_uTransitionDuration,
        AkCurveInterpolation in_eFadeCurve)
{
  unsigned int m_PlayingID; // edx
  unsigned int audioNodeID; // edx
  CAkParameterNodeBase *NodePtrAndAddRef; // rax
  CAkParameterNodeBase *v11; // rdi
  unsigned int v12; // edx
  CAkParameterNodeBase *v13; // rax
  CAkParameterNodeBase *v14; // rdi
  CAkRegisteredObj *m_pGameObj; // rdx

  m_PlayingID = this->m_userParams.m_PlayingID;
  this->m_eState = State_Stopped;
  this->m_ulPauseCount = 0;
  CAkAudioMgr::ClearPendingItems(g_pAudioMgr, m_PlayingID);
  audioNodeID = this->m_queuedItem.audioNodeID;
  if ( audioNodeID && in_eStopMode == AK_StopImmediate )
  {
    NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, audioNodeID, AkNodeType_Default);
    v11 = NodePtrAndAddRef;
    if ( NodePtrAndAddRef )
    {
      CAkParameterNodeBase::Stop(
        NodePtrAndAddRef,
        this->m_pGameObj,
        this->m_userParams.m_PlayingID,
        in_uTransitionDuration,
        in_eFadeCurve);
      v11->vfptr->Release(v11);
    }
    this->m_queuedItem.audioNodeID = 0;
  }
  v12 = this->m_playingItem.audioNodeID;
  if ( v12 )
  {
    v13 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v12, AkNodeType_Default);
    v14 = v13;
    if ( v13 )
    {
      m_pGameObj = this->m_pGameObj;
      if ( in_eStopMode )
        ((void (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *, CAkParameterNodeBase *, _QWORD))v13->vfptr[4].Category)(
          v13,
          m_pGameObj,
          v13,
          this->m_userParams.m_PlayingID);
      else
        CAkParameterNodeBase::Stop(
          v13,
          m_pGameObj,
          this->m_userParams.m_PlayingID,
          in_uTransitionDuration,
          in_eFadeCurve);
      v14->vfptr->Release(v14);
    }
  }
  return 1i64;
}

// File Line: 290
// RVA: 0xA445F0
__int64 __fastcall CAkDynamicSequence::Pause(
        CAkDynamicSequence *this,
        int in_uTransitionDuration,
        AkCurveInterpolation in_eFadeCurve)
{
  unsigned int audioNodeID; // edx
  CAkParameterNodeBase *NodePtrAndAddRef; // rax
  CAkParameterNodeBase *v8; // rdi
  unsigned int v9; // edx
  CAkParameterNodeBase *v10; // rax
  CAkParameterNodeBase *v11; // rdi

  if ( this->m_eState )
  {
    if ( ++this->m_ulPauseCount == 1 )
    {
      CAkAudioMgr::PausePendingItems(g_pAudioMgr, this->m_userParams.m_PlayingID);
      audioNodeID = this->m_playingItem.audioNodeID;
      if ( audioNodeID )
      {
        NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, audioNodeID, AkNodeType_Default);
        v8 = NodePtrAndAddRef;
        if ( NodePtrAndAddRef )
        {
          CAkParameterNodeBase::Pause(
            NodePtrAndAddRef,
            this->m_pGameObj,
            this->m_userParams.m_PlayingID,
            in_uTransitionDuration,
            in_eFadeCurve);
          v8->vfptr->Release(v8);
        }
      }
      v9 = this->m_queuedItem.audioNodeID;
      if ( v9 )
      {
        v10 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v9, AkNodeType_Default);
        v11 = v10;
        if ( v10 )
        {
          CAkParameterNodeBase::Pause(
            v10,
            this->m_pGameObj,
            this->m_userParams.m_PlayingID,
            in_uTransitionDuration,
            in_eFadeCurve);
          v11->vfptr->Release(v11);
        }
      }
    }
  }
  return 1i64;
}

// File Line: 333
// RVA: 0xA449B0
__int64 __fastcall CAkDynamicSequence::Resume(
        CAkDynamicSequence *this,
        int in_uTransitionDuration,
        AkCurveInterpolation in_eFadeCurve)
{
  unsigned int m_ulPauseCount; // eax
  unsigned int v7; // eax
  unsigned int audioNodeID; // edx
  CAkParameterNodeBase *NodePtrAndAddRef; // rax
  CAkParameterNodeBase *v10; // rdi
  unsigned int v11; // edx
  CAkParameterNodeBase *v12; // rax
  CAkParameterNodeBase *v13; // rdi

  m_ulPauseCount = this->m_ulPauseCount;
  if ( m_ulPauseCount )
  {
    v7 = m_ulPauseCount - 1;
    this->m_ulPauseCount = v7;
    if ( !v7 )
    {
      if ( this->m_eState != State_Paused )
        CAkDynamicSequence::Play(this, in_uTransitionDuration, in_eFadeCurve);
      CAkAudioMgr::ResumePausedPendingItems(g_pAudioMgr, this->m_userParams.m_PlayingID);
      audioNodeID = this->m_playingItem.audioNodeID;
      if ( audioNodeID )
      {
        NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, audioNodeID, AkNodeType_Default);
        v10 = NodePtrAndAddRef;
        if ( NodePtrAndAddRef )
        {
          CAkParameterNodeBase::Resume(
            NodePtrAndAddRef,
            this->m_pGameObj,
            this->m_userParams.m_PlayingID,
            in_uTransitionDuration,
            in_eFadeCurve);
          v10->vfptr->Release(v10);
        }
      }
      v11 = this->m_queuedItem.audioNodeID;
      if ( v11 )
      {
        v12 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v11, AkNodeType_Default);
        v13 = v12;
        if ( v12 )
        {
          CAkParameterNodeBase::Resume(
            v12,
            this->m_pGameObj,
            this->m_userParams.m_PlayingID,
            in_uTransitionDuration,
            in_eFadeCurve);
          v13->vfptr->Release(v13);
        }
      }
    }
  }
  return 1i64;
}

// File Line: 382
// RVA: 0xA44AA0
void __fastcall CAkDynamicSequence::ResumeWaiting(CAkDynamicSequence *this)
{
  if ( this->m_eState == State_Running )
  {
    if ( this->m_playList.m_uLength )
      CAkDynamicSequence::Play(this, 0, AkCurveInterpolation_Linear);
  }
}

// File Line: 390
// RVA: 0xA44D00
__int64 __fastcall CAkDynamicSequence::_PlayNode(
        CAkDynamicSequence *this,
        unsigned int in_nodeID,
        int in_delay,
        int in_uTransitionDuration,
        AkCurveInterpolation in_eFadeCurve)
{
  CAkParameterNode *NodePtrAndAddRef; // rdi
  unsigned int m_PlayingID; // eax
  __int64 customParam; // rax
  AkExternalSourceArray *pExternalSrcs; // rax
  unsigned int v13; // ecx
  AKRESULT v14; // eax
  unsigned int v15; // ebx
  __int64 v16[3]; // [rsp+20h] [rbp-A1h] BYREF
  __int16 v17; // [rsp+38h] [rbp-89h]
  CAkContinuationList *v18; // [rsp+40h] [rbp-81h]
  int v19; // [rsp+48h] [rbp-79h]
  __int64 v20; // [rsp+50h] [rbp-71h] BYREF
  int v21; // [rsp+58h] [rbp-69h]
  AkPBIParams in_rPBIParams; // [rsp+60h] [rbp-61h] BYREF
  int v23; // [rsp+120h] [rbp+5Fh] BYREF
  AkCurveInterpolation v24; // [rsp+124h] [rbp+63h]

  if ( !this->m_pGameObj )
    return 2i64;
  NodePtrAndAddRef = (CAkParameterNode *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_nodeID, AkNodeType_Default);
  if ( NodePtrAndAddRef )
  {
    v23 = in_uTransitionDuration;
    v16[2] = (__int64)&v20;
    v24 = in_eFadeCurve;
    v20 = 0i64;
    v21 = 0;
    v16[0] = 0i64;
    v16[1] = 0i64;
    v17 = 0;
    v19 = 0;
    v18 = CAkContinuationList::Create();
    if ( !v18 )
    {
      NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef);
      return 2i64;
    }
    m_PlayingID = this->m_userParams.m_PlayingID;
    in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = 0i64;
    in_rPBIParams.playHistory.arrayIsContinuous.m_iBitArray = 0;
    in_rPBIParams.userParams.m_PlayingID = m_PlayingID;
    customParam = this->m_userParams.m_CustomParam.customParam;
    in_rPBIParams.bSkipDelay = 0;
    in_rPBIParams.userParams.m_CustomParam.customParam = customParam;
    LODWORD(customParam) = this->m_userParams.m_CustomParam.ui32Reserved;
    in_rPBIParams.bTargetFeedback = 0;
    in_rPBIParams.userParams.m_CustomParam.ui32Reserved = customParam;
    pExternalSrcs = this->m_userParams.m_CustomParam.pExternalSrcs;
    in_rPBIParams.playHistory.HistArray.uiArraySize = 0;
    in_rPBIParams.eType = DynamicSequencePBI;
    in_rPBIParams.pInstigator = this;
    if ( pExternalSrcs )
      ++pExternalSrcs->m_cRefCount;
    in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = pExternalSrcs;
    in_rPBIParams.ePlaybackState = PB_Playing;
    in_rPBIParams.bIsFirst = 1;
    in_rPBIParams.pGameObj = this->m_pGameObj;
    in_rPBIParams.pTransitionParameters = (TransParams *)&v23;
    in_rPBIParams.uFrameOffset = in_delay * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
    in_rPBIParams.pContinuousParams = (ContParams *)v16;
    if ( this->m_eDynamicSequenceType == DynamicSequenceType_SampleAccurate && !this->m_uSequenceID )
    {
      do
      {
        v13 = CAkContinuousPBI::m_CalSeqID++;
        this->m_uSequenceID = v13;
      }
      while ( !v13 );
    }
    in_rPBIParams.sequenceID = this->m_uSequenceID;
    v14 = CAkParameterNode::HandleInitialDelay(NodePtrAndAddRef, &in_rPBIParams);
    v15 = v14;
    if ( v14 == AK_PartialSuccess )
    {
      v15 = 1;
    }
    else if ( v14 == AK_Success )
    {
      v15 = ((__int64 (__fastcall *)(CAkParameterNode *, AkPBIParams *))NodePtrAndAddRef->vfptr[19].Category)(
              NodePtrAndAddRef,
              &in_rPBIParams);
    }
    NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef);
    if ( in_rPBIParams.userParams.m_CustomParam.pExternalSrcs )
      AkExternalSourceArray::Release(in_rPBIParams.userParams.m_CustomParam.pExternalSrcs);
    if ( v18 )
      CAkContinuationList::Release(v18);
  }
  else
  {
    return 15;
  }
  return v15;
}

// File Line: 464
// RVA: 0xA44B80
void __fastcall CAkDynamicSequence::UnlockPlaylist(CAkDynamicSequence *this)
{
  bool v2; // bl
  unsigned __int16 ClassSize; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h] BYREF

  v2 = this->m_eState == State_Running;
  LeaveCriticalSection(&this->m_lockPlaylist.m_csLock);
  if ( v2 )
  {
    in_rItem.type = 23;
    this->vfptr->AddRef(this);
    in_rItem.event.GameObjID = (unsigned __int64)this;
    in_rItem.event.PlayingID = 6;
    ClassSize = UEL::ArgumentUsageExpression::GetClassSize();
    CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, ClassSize);
  }
}

// File Line: 483
// RVA: 0xA44240
void __fastcall CAkDynamicSequence::AllExec(
        CAkDynamicSequence *this,
        ActionParamType in_eType,
        CAkRegisteredObj *in_pGameObj)
{
  int v3; // edx
  unsigned int m_ulPauseCount; // eax
  unsigned int v5; // eax

  if ( this->m_pGameObj == in_pGameObj || !in_pGameObj )
  {
    if ( in_eType )
    {
      v3 = in_eType - 1;
      if ( v3 )
      {
        if ( v3 == 1 )
        {
          m_ulPauseCount = this->m_ulPauseCount;
          if ( m_ulPauseCount )
          {
            v5 = m_ulPauseCount - 1;
            this->m_ulPauseCount = v5;
            if ( !v5 && this->m_eState != State_Paused )
              CAkDynamicSequence::Play(this, 0, AkCurveInterpolation_Linear);
          }
        }
      }
      else if ( this->m_eState )
      {
        ++this->m_ulPauseCount;
      }
    }
    else
    {
      this->m_eState = State_Stopped;
      this->m_ulPauseCount = 0;
      this->m_queuedItem.audioNodeID = 0;
    }
  }
}

// File Line: 521
// RVA: 0xA44070
void __fastcall AK::SoundEngine::DynamicSequence::PlaylistItem::~PlaylistItem(
        AK::SoundEngine::DynamicSequence::PlaylistItem *this)
{
  AkExternalSourceArray *pExternalSrcs; // rcx

  pExternalSrcs = this->pExternalSrcs;
  if ( pExternalSrcs )
    AkExternalSourceArray::Release(pExternalSrcs);
}

// File Line: 527
// RVA: 0xA44AC0
signed __int64 __fastcall AK::SoundEngine::DynamicSequence::PlaylistItem::SetExternalSources(
        AK::SoundEngine::DynamicSequence::PlaylistItem *this,
        unsigned int in_nExternalSrc,
        AkExternalSourceInfo *in_pExternalSrc)
{
  AkExternalSourceArray *pExternalSrcs; // rcx
  AkExternalSourceArray *v7; // rax
  unsigned int v8; // ecx

  pExternalSrcs = this->pExternalSrcs;
  if ( pExternalSrcs )
    AkExternalSourceArray::Release(pExternalSrcs);
  this->pExternalSrcs = 0i64;
  if ( !in_nExternalSrc )
    return 1i64;
  v7 = AkExternalSourceArray::Create(in_nExternalSrc, in_pExternalSrc);
  v8 = 1;
  this->pExternalSrcs = v7;
  if ( !v7 )
    return 52;
  return v8;
}

// File Line: 541
// RVA: 0xA44080
AK::SoundEngine::DynamicSequence::PlaylistItem *__fastcall AK::SoundEngine::DynamicSequence::PlaylistItem::operator=(
        AK::SoundEngine::DynamicSequence::PlaylistItem *this,
        AK::SoundEngine::DynamicSequence::PlaylistItem *in_rCopy)
{
  AkExternalSourceArray *pExternalSrcs; // rcx
  AkExternalSourceArray *v5; // rax

  pExternalSrcs = this->pExternalSrcs;
  if ( pExternalSrcs )
    AkExternalSourceArray::Release(pExternalSrcs);
  this->audioNodeID = in_rCopy->audioNodeID;
  this->msDelay = in_rCopy->msDelay;
  this->pCustomInfo = in_rCopy->pCustomInfo;
  v5 = in_rCopy->pExternalSrcs;
  this->pExternalSrcs = v5;
  if ( v5 )
    ++v5->m_cRefCount;
  return this;
}

