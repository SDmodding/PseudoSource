// File Line: 37
// RVA: 0xA43ED0
void __fastcall CAkDynamicSequence::CAkDynamicSequence(CAkDynamicSequence *this, unsigned int in_playingID, AK::SoundEngine::DynamicSequence::DynamicSequenceType in_eDynamicSequenceType)
{
  AK::SoundEngine::DynamicSequence::DynamicSequenceType v3; // ebx
  unsigned int v4; // edi
  CAkDynamicSequence *v5; // rsi

  v3 = in_eDynamicSequenceType;
  v4 = in_playingID;
  v5 = this;
  CAkIndexable::CAkIndexable((CAkIndexable *)&this->vfptr, in_playingID);
  v5->vfptr = (CAkIndexableVtbl *)&CAkDynamicSequence::`vftable;
  v5->m_playList.m_pItems = 0i64;
  *(_QWORD *)&v5->m_playList.m_uLength = 0i64;
  InitializeCriticalSection(&v5->m_lockPlaylist.m_csLock);
  v5->m_eState = 0;
  v5->m_pGameObj = 0i64;
  v5->m_userParams.m_CustomParam.customParam = 0i64;
  v5->m_userParams.m_CustomParam.ui32Reserved = 0;
  v5->m_userParams.m_CustomParam.pExternalSrcs = 0i64;
  v5->m_bClosed = 0;
  v5->m_eDynamicSequenceType = v3;
  *(_QWORD *)&v5->m_playingItem.audioNodeID = 0i64;
  v5->m_playingItem.pCustomInfo = 0i64;
  v5->m_playingItem.pExternalSrcs = 0i64;
  *(_QWORD *)&v5->m_queuedItem.audioNodeID = 0i64;
  v5->m_queuedItem.pCustomInfo = 0i64;
  v5->m_queuedItem.pExternalSrcs = 0i64;
  *(_QWORD *)&v5->m_ulPauseCount = 0i64;
  v5->m_playingItem.audioNodeID = 0;
  v5->m_queuedItem.audioNodeID = 0;
  v5->m_userParams.m_PlayingID = v4;
}

// File Line: 46
// RVA: 0xA43F90
void __fastcall CAkDynamicSequence::~CAkDynamicSequence(CAkDynamicSequence *this)
{
  CAkDynamicSequence *v1; // rdi
  CAkRegisteredObj *v2; // rsi
  int v3; // ecx
  int v4; // ebx
  AkExternalSourceArray *v5; // rcx
  AkExternalSourceArray *v6; // rcx
  AkExternalSourceArray *v7; // rcx

  v1 = this;
  this->vfptr = (CAkIndexableVtbl *)&CAkDynamicSequence::`vftable;
  if ( this->m_playList.m_pItems )
  {
    AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::RemoveAll((AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)&this->m_playList.m_pItems);
    AK::MemoryMgr::Free(g_DefaultPoolId, v1->m_playList.m_pItems);
    v1->m_playList.m_pItems = 0i64;
    v1->m_playList.m_ulReserved = 0;
  }
  v2 = v1->m_pGameObj;
  if ( v2 )
  {
    v3 = *((_DWORD *)v2 + 30) ^ (*((_DWORD *)v2 + 30) ^ (*((_DWORD *)v2 + 30) - 1)) & 0x3FFFFFFF;
    *((_DWORD *)v2 + 30) = v3;
    if ( !(v3 & 0x3FFFFFFF) )
    {
      v4 = g_DefaultPoolId;
      CAkRegisteredObj::~CAkRegisteredObj(v2);
      AK::MemoryMgr::Free(v4, v2);
    }
  }
  v5 = v1->m_queuedItem.pExternalSrcs;
  if ( v5 )
    AkExternalSourceArray::Release(v5);
  v6 = v1->m_playingItem.pExternalSrcs;
  if ( v6 )
    AkExternalSourceArray::Release(v6);
  v7 = v1->m_userParams.m_CustomParam.pExternalSrcs;
  if ( v7 )
    AkExternalSourceArray::Release(v7);
  DeleteCriticalSection(&v1->m_lockPlaylist.m_csLock);
  CAkPBIAware::~CAkPBIAware((CAkPBIAware *)&v1->vfptr);
}

// File Line: 53
// RVA: 0xA44330
void __fastcall CAkDynamicSequence::Create(unsigned int in_PlayingID, AK::SoundEngine::DynamicSequence::DynamicSequenceType in_eDynamicSequenceType)
{
  unsigned int v2; // edi
  AK::SoundEngine::DynamicSequence::DynamicSequenceType v3; // ebx
  CAkDynamicSequence *v4; // rax
  CAkDynamicSequence *v5; // rax

  v2 = in_PlayingID;
  v3 = in_eDynamicSequenceType;
  v4 = (CAkDynamicSequence *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xC0ui64);
  if ( v4 )
  {
    CAkDynamicSequence::CAkDynamicSequence(v4, v2, v3);
    if ( v5 )
      CAkDynamicSequence::AddToIndex(v5);
  }
}

// File Line: 72
// RVA: 0xA441D0
void __fastcall CAkDynamicSequence::AddToIndex(CAkDynamicSequence *this)
{
  CAkDynamicSequence *v1; // rbx
  CAkIndexItem<CAkDynamicSequence *> *v2; // rdi
  signed __int64 v3; // rdx

  v1 = this;
  v2 = &g_pIndex->m_idxDynamicSequences;
  EnterCriticalSection(&g_pIndex->m_idxDynamicSequences.m_IndexLock.m_csLock);
  v3 = (signed __int64)v2 + 8 * (v1->key % 0xC1);
  v1->pNextItem = *(CAkIndexable **)(v3 + 40);
  *(_QWORD *)(v3 + 40) = v1;
  ++v2->m_mapIDToPtr.m_uiSize;
  LeaveCriticalSection(&v2->m_IndexLock.m_csLock);
}

// File Line: 84
// RVA: 0xA44180
__int64 __fastcall CAkDynamicSequence::AddRef(CAkDynamicSequence *this)
{
  CAkAudioLibIndex *v1; // rbx
  CAkDynamicSequence *v2; // rsi
  unsigned int v3; // edi

  v1 = g_pIndex;
  v2 = this;
  EnterCriticalSection(&g_pIndex->m_idxDynamicSequences.m_IndexLock.m_csLock);
  v3 = v2->m_lRef + 1;
  v2->m_lRef = v3;
  LeaveCriticalSection(&v1->m_idxDynamicSequences.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 90
// RVA: 0xA448A0
__int64 __fastcall CAkDynamicSequence::Release(CAkDynamicSequence *this)
{
  CAkAudioLibIndex *v1; // rbx
  CAkDynamicSequence *v2; // rsi
  bool v3; // zf
  unsigned int v4; // ebp
  int v5; // edi

  v1 = g_pIndex;
  v2 = this;
  EnterCriticalSection(&g_pIndex->m_idxDynamicSequences.m_IndexLock.m_csLock);
  v3 = v2->m_lRef-- == 1;
  v4 = v2->m_lRef;
  if ( v3 )
  {
    CAkIndexItem<CAkEvent *>::RemoveID(
      (CAkIndexItem<CAkParameterNodeBase *> *)&g_pIndex->m_idxDynamicSequences,
      v2->key);
    v5 = g_DefaultPoolId;
    v2->vfptr->__vecDelDtor((CAkIndexable *)&v2->vfptr, 0);
    AK::MemoryMgr::Free(v5, v2);
  }
  LeaveCriticalSection(&v1->m_idxDynamicSequences.m_IndexLock.m_csLock);
  return v4;
}

// File Line: 109
// RVA: 0xA44390
void __fastcall CAkDynamicSequence::CreatePBI(CAkDynamicSequence *this, CAkSoundBase *in_pSound, CAkSource *in_pSource, AkPBIParams *in_rPBIParams, PriorityInfoCurrent *in_rPriority, CAkLimiter *in_pAMLimiter, CAkLimiter *in_pBusLimiter)
{
  CAkDynamicSequence *v7; // r15
  CAkSoundBase *v8; // r14
  AkPBIParams *v9; // rdi
  CAkSource *v10; // rbp
  CAkDynamicSequencePBI *v11; // rsi

  v7 = this;
  v8 = in_pSound;
  v9 = in_rPBIParams;
  v10 = in_pSource;
  v11 = (CAkDynamicSequencePBI *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x298ui64);
  if ( v11 )
    CAkDynamicSequencePBI::CAkDynamicSequencePBI(
      v11,
      v8,
      v10,
      v9->pGameObj,
      v9->pContinuousParams,
      &v9->userParams,
      &v9->playHistory,
      v9->bIsFirst,
      v9->sequenceID,
      v9->pInstigator,
      in_rPriority,
      v7->m_eDynamicSequenceType,
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
__int64 __fastcall CAkDynamicSequence::_GetNextToPlay(CAkDynamicSequence *this, int *out_delay, void **out_rpCustomParam)
{
  void **v3; // r15
  int *v4; // r12
  CAkDynamicSequence *v5; // rdi
  _RTL_CRITICAL_SECTION *v7; // rbx
  AK::SoundEngine::DynamicSequence::PlaylistItem *v8; // rsi
  unsigned int v9; // edi

  v3 = out_rpCustomParam;
  v4 = out_delay;
  v5 = this;
  if ( !this->m_pGameObj )
    return 0i64;
  v7 = &this->m_lockPlaylist.m_csLock;
  this->m_queuedItem.audioNodeID = 0;
  EnterCriticalSection(&this->m_lockPlaylist.m_csLock);
  if ( v5->m_eState )
  {
    if ( v5->m_playList.m_uLength )
    {
      while ( 1 )
      {
        v8 = v5->m_playList.m_pItems;
        *v3 = v8->pCustomInfo;
        if ( v8->audioNodeID )
          break;
        AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::Erase(
          (AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)&v5->m_playList.m_pItems,
          0);
        CAkPlayingMgr::NotifyEndOfDynamicSequenceItem(g_pPlayingMgr, v5->m_userParams.m_PlayingID, 0, *v3);
        if ( !v5->m_playList.m_uLength )
          goto LABEL_9;
      }
      AK::SoundEngine::DynamicSequence::PlaylistItem::operator=(&v5->m_queuedItem, v8);
      *v4 = v8->msDelay;
      AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::Erase(
        (AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)&v5->m_playList.m_pItems,
        0);
    }
LABEL_9:
    if ( !v5->m_queuedItem.audioNodeID )
      v5->m_eState = 2;
  }
  v9 = v5->m_queuedItem.audioNodeID;
  LeaveCriticalSection(v7);
  return v9;
}

// File Line: 181
// RVA: 0xA44530
__int64 __fastcall CAkDynamicSequence::GetNextToPlay(CAkDynamicSequence *this, int *out_delay, void **out_rpCustomParam, UserParams *out_rUserParam)
{
  CAkDynamicSequence *v4; // rbx
  AkExternalSourceArray *v5; // rcx
  UserParams *v6; // rdi
  void **v7; // rsi
  int *v8; // rbp
  AkExternalSourceArray *v9; // rax
  unsigned int v10; // eax
  AkExternalSourceArray *v11; // rcx
  AkExternalSourceArray *v12; // rbx
  unsigned int v13; // esi
  __int64 result; // rax

  v4 = this;
  v5 = this->m_playingItem.pExternalSrcs;
  v6 = out_rUserParam;
  v7 = out_rpCustomParam;
  v8 = out_delay;
  if ( v5 )
    AkExternalSourceArray::Release(v5);
  v4->m_playingItem.audioNodeID = v4->m_queuedItem.audioNodeID;
  v4->m_playingItem.msDelay = v4->m_queuedItem.msDelay;
  v4->m_playingItem.pCustomInfo = v4->m_queuedItem.pCustomInfo;
  v9 = v4->m_queuedItem.pExternalSrcs;
  v4->m_playingItem.pExternalSrcs = v9;
  if ( v9 )
    ++v9->m_cRefCount;
  v10 = CAkDynamicSequence::_GetNextToPlay(v4, v8, v7);
  v11 = v6->m_CustomParam.pExternalSrcs;
  v12 = v4->m_queuedItem.pExternalSrcs;
  v13 = v10;
  if ( v11 )
    AkExternalSourceArray::Release(v11);
  result = v13;
  if ( v12 )
    ++v12->m_cRefCount;
  v6->m_CustomParam.pExternalSrcs = v12;
  return result;
}

// File Line: 190
// RVA: 0xA446E0
signed __int64 __fastcall CAkDynamicSequence::Play(CAkDynamicSequence *this, int in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve)
{
  AkCurveInterpolation v3; // er12
  int v4; // er13
  CAkDynamicSequence *v5; // rdi
  int v6; // er15
  void *v7; // rbp
  unsigned int v8; // esi
  AK::SoundEngine::DynamicSequence::PlaylistItem *v9; // rsi
  AkExternalSourceArray *v10; // rcx
  AkExternalSourceArray *v11; // rax
  AkExternalSourceArray *v12; // rcx
  AkExternalSourceArray *v13; // rbx

  v3 = in_eFadeCurve;
  v4 = in_uTransitionDuration;
  v5 = this;
  if ( this->m_eState & 0xFFFFFFFD || this->m_ulPauseCount )
    return 1i64;
  this->m_eState = 1;
  v6 = 0;
  while ( 1 )
  {
    v7 = 0i64;
    if ( v5->m_pGameObj )
    {
      v5->m_queuedItem.audioNodeID = 0;
      EnterCriticalSection(&v5->m_lockPlaylist.m_csLock);
      if ( v5->m_eState )
      {
        if ( v5->m_playList.m_uLength )
        {
          while ( 1 )
          {
            v9 = v5->m_playList.m_pItems;
            v7 = v9->pCustomInfo;
            if ( v9->audioNodeID )
              break;
            AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::Erase(
              (AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)&v5->m_playList.m_pItems,
              0);
            CAkPlayingMgr::NotifyEndOfDynamicSequenceItem(g_pPlayingMgr, v5->m_userParams.m_PlayingID, 0, v7);
            if ( !v5->m_playList.m_uLength )
              goto LABEL_16;
          }
          v10 = v5->m_queuedItem.pExternalSrcs;
          if ( v10 )
            AkExternalSourceArray::Release(v10);
          v5->m_queuedItem.audioNodeID = v9->audioNodeID;
          v5->m_queuedItem.msDelay = v9->msDelay;
          v5->m_queuedItem.pCustomInfo = v9->pCustomInfo;
          v11 = v9->pExternalSrcs;
          v5->m_queuedItem.pExternalSrcs = v11;
          if ( v11 )
            ++v11->m_cRefCount;
          v6 = v9->msDelay;
          AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::Erase(
            (AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)&v5->m_playList.m_pItems,
            0);
        }
LABEL_16:
        if ( !v5->m_queuedItem.audioNodeID )
          v5->m_eState = 2;
      }
      v8 = v5->m_queuedItem.audioNodeID;
      LeaveCriticalSection(&v5->m_lockPlaylist.m_csLock);
    }
    else
    {
      v8 = 0;
    }
    v12 = v5->m_userParams.m_CustomParam.pExternalSrcs;
    v13 = v5->m_queuedItem.pExternalSrcs;
    if ( v12 )
      AkExternalSourceArray::Release(v12);
    if ( v13 )
      ++v13->m_cRefCount;
    v5->m_userParams.m_CustomParam.pExternalSrcs = v13;
    if ( !v8 || CAkDynamicSequence::_PlayNode(v5, v8, v6, v4, v3) == 1 )
      return 1i64;
    CAkPlayingMgr::NotifyEndOfDynamicSequenceItem(g_pPlayingMgr, v5->m_userParams.m_PlayingID, v8, v7);
  }
}

// File Line: 223
// RVA: 0xA44B60
AKRESULT __fastcall CAkDynamicSequence::Stop(CAkDynamicSequence *this, int in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve)
{
  this->m_uSequenceID = 0;
  return CAkDynamicSequence::_Stop(this, 0, in_uTransitionDuration, in_eFadeCurve);
}

// File Line: 233
// RVA: 0xA442A0
signed __int64 __fastcall CAkDynamicSequence::Break(CAkDynamicSequence *this)
{
  CAkDynamicSequence *v1; // rbx
  unsigned int v2; // edx
  unsigned int v3; // edx
  CAkParameterNodeBase *v4; // rax
  CAkParameterNodeBase *v5; // rdi

  v1 = this;
  this->m_uSequenceID = 0;
  if ( this->m_eState )
  {
    v2 = this->m_userParams.m_PlayingID;
    this->m_eState = 0;
    this->m_ulPauseCount = 0;
    CAkAudioMgr::ClearPendingItems(g_pAudioMgr, v2);
    v3 = v1->m_playingItem.audioNodeID;
    if ( v3 )
    {
      v4 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v3, 0);
      v5 = v4;
      if ( v4 )
      {
        ((void (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *, CAkParameterNodeBase *, _QWORD))v4->vfptr[4].Category)(
          v4,
          v1->m_pGameObj,
          v4,
          v1->m_userParams.m_PlayingID);
        v5->vfptr->Release((CAkIndexable *)&v5->vfptr);
      }
    }
  }
  return 1i64;
}

// File Line: 244
// RVA: 0xA44EF0
signed __int64 __fastcall CAkDynamicSequence::_Stop(CAkDynamicSequence *this, CAkDynamicSequence::AkDynamicSequenceStopMode in_eStopMode, int in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve)
{
  CAkDynamicSequence::AkDynamicSequenceStopMode v4; // esi
  unsigned int v5; // edx
  CAkDynamicSequence *v6; // rbx
  AkCurveInterpolation v7; // ebp
  int v8; // er14
  unsigned int v9; // edx
  CAkParameterNodeBase *v10; // rax
  CAkParameterNodeBase *v11; // rdi
  unsigned int v12; // edx
  CAkParameterNodeBase *v13; // rax
  CAkParameterNodeBase *v14; // rdi
  CAkRegisteredObj *v15; // rdx

  v4 = in_eStopMode;
  v5 = this->m_userParams.m_PlayingID;
  v6 = this;
  this->m_eState = 0;
  this->m_ulPauseCount = 0;
  v7 = in_eFadeCurve;
  v8 = in_uTransitionDuration;
  CAkAudioMgr::ClearPendingItems(g_pAudioMgr, v5);
  v9 = v6->m_queuedItem.audioNodeID;
  if ( v9 && v4 == AK_StopImmediate )
  {
    v10 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v9, 0);
    v11 = v10;
    if ( v10 )
    {
      CAkParameterNodeBase::Stop(v10, v6->m_pGameObj, v6->m_userParams.m_PlayingID, v8, v7);
      v11->vfptr->Release((CAkIndexable *)&v11->vfptr);
    }
    v6->m_queuedItem.audioNodeID = 0;
  }
  v12 = v6->m_playingItem.audioNodeID;
  if ( v12 )
  {
    v13 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v12, 0);
    v14 = v13;
    if ( v13 )
    {
      v15 = v6->m_pGameObj;
      if ( v4 )
        ((void (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *, CAkParameterNodeBase *, _QWORD))v13->vfptr[4].Category)(
          v13,
          v15,
          v13,
          v6->m_userParams.m_PlayingID);
      else
        CAkParameterNodeBase::Stop(v13, v15, v6->m_userParams.m_PlayingID, v8, v7);
      v14->vfptr->Release((CAkIndexable *)&v14->vfptr);
    }
  }
  return 1i64;
}

// File Line: 290
// RVA: 0xA445F0
signed __int64 __fastcall CAkDynamicSequence::Pause(CAkDynamicSequence *this, int in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve)
{
  AkCurveInterpolation v3; // esi
  int v4; // ebp
  CAkDynamicSequence *v5; // rbx
  unsigned int v6; // edx
  CAkParameterNodeBase *v7; // rax
  CAkParameterNodeBase *v8; // rdi
  unsigned int v9; // edx
  CAkParameterNodeBase *v10; // rax
  CAkParameterNodeBase *v11; // rdi

  v3 = in_eFadeCurve;
  v4 = in_uTransitionDuration;
  v5 = this;
  if ( this->m_eState )
  {
    if ( ++this->m_ulPauseCount == 1 )
    {
      CAkAudioMgr::PausePendingItems(g_pAudioMgr, this->m_userParams.m_PlayingID);
      v6 = v5->m_playingItem.audioNodeID;
      if ( v6 )
      {
        v7 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v6, 0);
        v8 = v7;
        if ( v7 )
        {
          CAkParameterNodeBase::Pause(v7, v5->m_pGameObj, v5->m_userParams.m_PlayingID, v4, v3);
          v8->vfptr->Release((CAkIndexable *)&v8->vfptr);
        }
      }
      v9 = v5->m_queuedItem.audioNodeID;
      if ( v9 )
      {
        v10 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v9, 0);
        v11 = v10;
        if ( v10 )
        {
          CAkParameterNodeBase::Pause(v10, v5->m_pGameObj, v5->m_userParams.m_PlayingID, v4, v3);
          v11->vfptr->Release((CAkIndexable *)&v11->vfptr);
        }
      }
    }
  }
  return 1i64;
}

// File Line: 333
// RVA: 0xA449B0
signed __int64 __fastcall CAkDynamicSequence::Resume(CAkDynamicSequence *this, int in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve)
{
  unsigned int v3; // eax
  AkCurveInterpolation v4; // esi
  int v5; // ebp
  CAkDynamicSequence *v6; // rbx
  unsigned int v7; // eax
  unsigned int v8; // edx
  CAkParameterNodeBase *v9; // rax
  CAkParameterNodeBase *v10; // rdi
  unsigned int v11; // edx
  CAkParameterNodeBase *v12; // rax
  CAkParameterNodeBase *v13; // rdi

  v3 = this->m_ulPauseCount;
  v4 = in_eFadeCurve;
  v5 = in_uTransitionDuration;
  v6 = this;
  if ( v3 )
  {
    v7 = v3 - 1;
    this->m_ulPauseCount = v7;
    if ( !v7 )
    {
      if ( this->m_eState != 1 )
        CAkDynamicSequence::Play(this, in_uTransitionDuration, in_eFadeCurve);
      CAkAudioMgr::ResumePausedPendingItems(g_pAudioMgr, v6->m_userParams.m_PlayingID);
      v8 = v6->m_playingItem.audioNodeID;
      if ( v8 )
      {
        v9 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v8, 0);
        v10 = v9;
        if ( v9 )
        {
          CAkParameterNodeBase::Resume(v9, v6->m_pGameObj, v6->m_userParams.m_PlayingID, v5, v4);
          v10->vfptr->Release((CAkIndexable *)&v10->vfptr);
        }
      }
      v11 = v6->m_queuedItem.audioNodeID;
      if ( v11 )
      {
        v12 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v11, 0);
        v13 = v12;
        if ( v12 )
        {
          CAkParameterNodeBase::Resume(v12, v6->m_pGameObj, v6->m_userParams.m_PlayingID, v5, v4);
          v13->vfptr->Release((CAkIndexable *)&v13->vfptr);
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
  if ( this->m_eState == 2 )
  {
    if ( this->m_playList.m_uLength )
      CAkDynamicSequence::Play(this, 0, AkCurveInterpolation_Linear);
  }
}

// File Line: 390
// RVA: 0xA44D00
signed __int64 __fastcall CAkDynamicSequence::_PlayNode(CAkDynamicSequence *this, unsigned int in_nodeID, int in_delay, int in_uTransitionDuration, AkCurveInterpolation in_eFadeCurve)
{
  int v5; // esi
  int v6; // er14
  CAkDynamicSequence *v7; // rbx
  CAkParameterNode *v9; // rdi
  CAkContinuationList *v10; // rax
  unsigned int v12; // eax
  __int64 v13; // rax
  AkExternalSourceArray *v14; // rax
  unsigned int v15; // ecx
  AKRESULT v16; // eax
  unsigned int v17; // ebx
  __int64 v18; // [rsp+20h] [rbp-A1h]
  __int64 v19; // [rsp+28h] [rbp-99h]
  __int64 *v20; // [rsp+30h] [rbp-91h]
  __int16 v21; // [rsp+38h] [rbp-89h]
  CAkContinuationList *v22; // [rsp+40h] [rbp-81h]
  int v23; // [rsp+48h] [rbp-79h]
  __int64 v24; // [rsp+50h] [rbp-71h]
  int v25; // [rsp+58h] [rbp-69h]
  AkPBIParams in_rPBIParams; // [rsp+60h] [rbp-61h]
  int v27; // [rsp+120h] [rbp+5Fh]
  AkCurveInterpolation v28; // [rsp+124h] [rbp+63h]

  v5 = in_uTransitionDuration;
  v6 = in_delay;
  v7 = this;
  if ( !this->m_pGameObj )
    return 2i64;
  v9 = (CAkParameterNode *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_nodeID, 0);
  if ( !v9 )
    return 15;
  v27 = v5;
  v20 = &v24;
  v28 = in_eFadeCurve;
  v24 = 0i64;
  v25 = 0;
  v18 = 0i64;
  v19 = 0i64;
  v21 = 0;
  v23 = 0;
  v10 = CAkContinuationList::Create();
  v22 = v10;
  if ( v10 )
  {
    v12 = v7->m_userParams.m_PlayingID;
    in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = 0i64;
    in_rPBIParams.playHistory.arrayIsContinuous.m_iBitArray = 0;
    in_rPBIParams.userParams.m_PlayingID = v12;
    v13 = v7->m_userParams.m_CustomParam.customParam;
    in_rPBIParams.bSkipDelay = 0;
    in_rPBIParams.userParams.m_CustomParam.customParam = v13;
    LODWORD(v13) = v7->m_userParams.m_CustomParam.ui32Reserved;
    in_rPBIParams.bTargetFeedback = 0;
    in_rPBIParams.userParams.m_CustomParam.ui32Reserved = v13;
    v14 = v7->m_userParams.m_CustomParam.pExternalSrcs;
    in_rPBIParams.playHistory.HistArray.uiArraySize = 0;
    in_rPBIParams.eType = 2;
    in_rPBIParams.pInstigator = (CAkPBIAware *)&v7->vfptr;
    if ( v14 )
      ++v14->m_cRefCount;
    in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = v14;
    in_rPBIParams.ePlaybackState = 0;
    in_rPBIParams.bIsFirst = 1;
    in_rPBIParams.pGameObj = v7->m_pGameObj;
    in_rPBIParams.pTransitionParameters = (TransParams *)&v27;
    in_rPBIParams.uFrameOffset = v6 * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
    in_rPBIParams.pContinuousParams = (ContParams *)&v18;
    if ( v7->m_eDynamicSequenceType == DynamicSequenceType_SampleAccurate && !v7->m_uSequenceID )
    {
      do
      {
        v15 = CAkContinuousPBI::m_CalSeqID++;
        v7->m_uSequenceID = v15;
      }
      while ( !v15 );
    }
    in_rPBIParams.sequenceID = v7->m_uSequenceID;
    v16 = CAkParameterNode::HandleInitialDelay(v9, &in_rPBIParams);
    v17 = v16;
    if ( v16 == 3 )
    {
      v17 = 1;
    }
    else if ( v16 == 1 )
    {
      v17 = ((__int64 (__fastcall *)(CAkParameterNode *, AkPBIParams *))v9->vfptr[19].Category)(v9, &in_rPBIParams);
    }
    v9->vfptr->Release((CAkIndexable *)&v9->vfptr);
    if ( in_rPBIParams.userParams.m_CustomParam.pExternalSrcs )
      AkExternalSourceArray::Release(in_rPBIParams.userParams.m_CustomParam.pExternalSrcs);
    if ( v22 )
      CAkContinuationList::Release(v22);
    return v17;
  }
  v9->vfptr->Release((CAkIndexable *)&v9->vfptr);
  if ( v22 )
    CAkContinuationList::Release(v22);
  return 2i64;
}

// File Line: 464
// RVA: 0xA44B80
void __fastcall CAkDynamicSequence::UnlockPlaylist(CAkDynamicSequence *this)
{
  CAkDynamicSequence *v1; // rdi
  bool v2; // bl
  unsigned __int16 v3; // ax
  AkQueuedMsg in_rItem; // [rsp+20h] [rbp-48h]

  v1 = this;
  v2 = this->m_eState == 2;
  LeaveCriticalSection(&this->m_lockPlaylist.m_csLock);
  if ( v2 )
  {
    in_rItem.type = 23;
    v1->vfptr->AddRef((CAkIndexable *)&v1->vfptr);
    in_rItem.event.GameObjID = (unsigned __int64)v1;
    in_rItem.event.PlayingID = 6;
    v3 = UEL::ArgumentUsageExpression::GetClassSize();
    CAkAudioMgr::Enqueue(g_pAudioMgr, &in_rItem, v3);
  }
}

// File Line: 483
// RVA: 0xA44240
void __fastcall CAkDynamicSequence::AllExec(CAkDynamicSequence *this, ActionParamType in_eType, CAkRegisteredObj *in_pGameObj)
{
  __int32 v3; // edx
  unsigned int v4; // eax
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
          v4 = this->m_ulPauseCount;
          if ( v4 )
          {
            v5 = v4 - 1;
            this->m_ulPauseCount = v5;
            if ( !v5 && this->m_eState != 1 )
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
      this->m_eState = 0;
      this->m_ulPauseCount = 0;
      this->m_queuedItem.audioNodeID = 0;
    }
  }
}

// File Line: 521
// RVA: 0xA44070
void __fastcall AK::SoundEngine::DynamicSequence::PlaylistItem::~PlaylistItem(AK::SoundEngine::DynamicSequence::PlaylistItem *this)
{
  JUMPOUT(this->pExternalSrcs, 0i64, AkExternalSourceArray::Release);
}

// File Line: 527
// RVA: 0xA44AC0
signed __int64 __fastcall AK::SoundEngine::DynamicSequence::PlaylistItem::SetExternalSources(AK::SoundEngine::DynamicSequence::PlaylistItem *this, unsigned int in_nExternalSrc, AkExternalSourceInfo *in_pExternalSrc)
{
  AK::SoundEngine::DynamicSequence::PlaylistItem *v3; // rbx
  AkExternalSourceArray *v4; // rcx
  AkExternalSourceInfo *v5; // rsi
  unsigned int v6; // edi
  AkExternalSourceArray *v7; // rax
  unsigned int v8; // ecx

  v3 = this;
  v4 = this->pExternalSrcs;
  v5 = in_pExternalSrc;
  v6 = in_nExternalSrc;
  if ( v4 )
    AkExternalSourceArray::Release(v4);
  v3->pExternalSrcs = 0i64;
  if ( !v6 )
    return 1i64;
  v7 = AkExternalSourceArray::Create(v6, v5);
  v8 = 1;
  v3->pExternalSrcs = v7;
  if ( !v7 )
    v8 = 52;
  return v8;
}

// File Line: 541
// RVA: 0xA44080
AK::SoundEngine::DynamicSequence::PlaylistItem *__fastcall AK::SoundEngine::DynamicSequence::PlaylistItem::operator=(AK::SoundEngine::DynamicSequence::PlaylistItem *this, AK::SoundEngine::DynamicSequence::PlaylistItem *in_rCopy)
{
  AK::SoundEngine::DynamicSequence::PlaylistItem *v2; // rbx
  AkExternalSourceArray *v3; // rcx
  AK::SoundEngine::DynamicSequence::PlaylistItem *v4; // rdi
  AkExternalSourceArray *v5; // rax

  v2 = this;
  v3 = this->pExternalSrcs;
  v4 = in_rCopy;
  if ( v3 )
    AkExternalSourceArray::Release(v3);
  v2->audioNodeID = v4->audioNodeID;
  v2->msDelay = v4->msDelay;
  v2->pCustomInfo = v4->pCustomInfo;
  v5 = v4->pExternalSrcs;
  v2->pExternalSrcs = v5;
  if ( v5 )
    ++v5->m_cRefCount;
  return v2;
}

