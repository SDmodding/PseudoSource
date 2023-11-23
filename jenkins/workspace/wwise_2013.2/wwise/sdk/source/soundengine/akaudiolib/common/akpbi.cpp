// File Line: 147
// RVA: 0xA7FAA0
void __fastcall CAkPBI::CAkPBI(
        CAkPBI *this,
        CAkSoundBase *in_pSound,
        CAkSource *in_pSource,
        CAkRegisteredObj *in_pGameObj,
        UserParams *in_rUserparams,
        PlayHistory *in_rPlayHistory,
        unsigned int in_SeqID,
        PriorityInfoCurrent *in_rPriority,
        bool in_bTargetFeedback,
        unsigned int in_uSourceOffset,
        CAkLimiter *in_pAMLimiter,
        CAkLimiter *in_pBusLimiter)
{
  AkExternalSourceArray *pExternalSrcs; // rax
  float distanceOffset; // eax
  unsigned int v16; // ecx
  CAkRegisteredObj *m_pGameObj; // rdx
  AkActivityChunk *m_pActivityChunk; // rax
  CAkPBI *m_pFirst; // rcx
  AkListBareLight<CAkPBI,AkListBareLightNextItem<CAkPBI> > *p_m_listPBI; // rax
  bool v21; // al
  CAkParameterNodeBase *m_pBusOutputNode; // rcx

  this->CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkPBI::`vftable{for `CAkTransportAware};
  this->m_uRegisteredNotif = 0;
  this->m_pUsageSlot = 0i64;
  this->ITransitionable::vfptr = (ITransitionableVtbl *)&CAkContinuousPBI::`vftable{for `ITransitionable};
  this->m_mapMutedNodes.m_pItems = 0i64;
  *(_QWORD *)&this->m_mapMutedNodes.m_uLength = 0i64;
  *(_QWORD *)&this->m_Ranges.VolumeOffset = 0i64;
  this->m_Ranges.LPFOffset = 0.0;
  this->m_p3DSound = 0i64;
  this->m_UserParams.m_CustomParam.pExternalSrcs = 0i64;
  this->m_UserParams.m_PlayingID = in_rUserparams->m_PlayingID;
  this->m_UserParams.m_CustomParam.customParam = in_rUserparams->m_CustomParam.customParam;
  this->m_UserParams.m_CustomParam.ui32Reserved = in_rUserparams->m_CustomParam.ui32Reserved;
  pExternalSrcs = in_rUserparams->m_CustomParam.pExternalSrcs;
  if ( pExternalSrcs )
    ++pExternalSrcs->m_cRefCount;
  this->m_UserParams.m_CustomParam.pExternalSrcs = pExternalSrcs;
  *((_BYTE *)&this->m_PBTrans + 16) &= 0xFCu;
  this->m_PBTrans.pvPSTrans = 0i64;
  this->m_PBTrans.pvPRTrans = 0i64;
  *((_BYTE *)this + 370) &= 0x80u;
  this->m_SeqID = in_SeqID;
  this->m_pSound = in_pSound;
  this->m_uSeekPosition = in_uSourceOffset;
  this->m_pSource = in_pSource;
  this->m_pGameObj = in_pGameObj;
  this->m_pCbx = 0i64;
  *(_QWORD *)&this->m_Volume = 0i64;
  this->m_LPFAutomationOffset = 0.0;
  this->m_fPlayStopFadeRatio = 1.0;
  *(_QWORD *)&this->m_fPauseResumeFadeRatio = 1065353216i64;
  *((_WORD *)this + 186) = 0;
  this->m_LoopCount = 1;
  *((_BYTE *)this + 371) = *((_BYTE *)this + 371) & 0xF | 0x10;
  *((_BYTE *)this + 374) = (in_bTargetFeedback << 7) | 0x22;
  *((_BYTE *)this + 375) = 2 * (in_uSourceOffset != 0);
  this->m_PriorityInfoCurrent.currentPriority.priority = in_rPriority->currentPriority.priority;
  this->m_PriorityInfoCurrent.currentPriority.PBIID = in_rPriority->currentPriority.PBIID;
  this->m_PriorityInfoCurrent.priorityInfo.priority = in_rPriority->priorityInfo.priority;
  distanceOffset = in_rPriority->priorityInfo.distanceOffset;
  *(_QWORD *)&this->m_ulPauseCount = 0i64;
  this->m_PriorityInfoCurrent.priorityInfo.distanceOffset = distanceOffset;
  this->m_pDataPtr = 0i64;
  *(_QWORD *)&this->m_uDataSize = 0i64;
  *((_BYTE *)&this->m_cachedGameObjectPosition.AkSoundPositionRef + 11) &= 0xF8u;
  this->m_cachedGameObjectPosition.m_aPos = 0i64;
  this->m_cachedGameObjectPosition.m_uNumPos = 0;
  this->m_cachedGameObjectPosition.m_uListenerMask = 1;
  this->m_Prev2DParams.prev2DParams.m_fPAN_X_2D = 101.0;
  this->m_pAMLimiter = in_pAMLimiter;
  this->m_pBusLimiter = in_pBusLimiter;
  this->m_pFeedbackInfo = 0i64;
  this->m_pControlBus = CAkParameterNodeBase::GetControlBus(in_pSound);
  v16 = CAkPBI::ms_PBIIDGenerator++;
  m_pGameObj = this->m_pGameObj;
  this->m_PriorityInfoCurrent.currentPriority.PBIID = v16;
  this->m_PathInfo.pPBPath = 0i64;
  this->m_PathInfo.PathOwnerID = 0;
  *((_DWORD *)m_pGameObj + 30) ^= (*((_DWORD *)m_pGameObj + 30) ^ (*((_DWORD *)m_pGameObj + 30) + 1)) & 0x3FFFFFFF;
  in_pSound->vfptr->AddRef(in_pSound);
  m_pActivityChunk = in_pSound->m_pActivityChunk;
  m_pFirst = m_pActivityChunk->m_listPBI.m_pFirst;
  p_m_listPBI = &m_pActivityChunk->m_listPBI;
  if ( m_pFirst )
  {
    this->pNextLightItem = m_pFirst;
    p_m_listPBI->m_pFirst = this;
  }
  else
  {
    p_m_listPBI->m_pFirst = this;
    this->pNextLightItem = 0i64;
  }
  if ( (*((_BYTE *)&in_pSound->CAkParameterNodeBase + 83) & 8) != 0 )
  {
    v21 = 1;
  }
  else
  {
    m_pBusOutputNode = in_pSound->m_pBusOutputNode;
    v21 = (m_pBusOutputNode || (m_pBusOutputNode = in_pSound->m_pParentNode) != 0i64)
       && CAkParameterNodeBase::IsInHdrHierarchy(m_pBusOutputNode);
  }
  *((_BYTE *)this + 376) &= ~1u;
  *((_DWORD *)&this->m_sMediaFormat + 1) &= 0xFFFC0004;
  *((_BYTE *)this + 376) |= v21;
  *((_DWORD *)&this->m_sMediaFormat + 1) |= 4u;
  this->m_CntrHistArray.uiArraySize = in_rPlayHistory->HistArray.uiArraySize;
  *(_DWORD *)this->m_CntrHistArray.aCntrHist = *(_DWORD *)in_rPlayHistory->HistArray.aCntrHist;
  *(_DWORD *)&this->m_CntrHistArray.aCntrHist[2] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[2];
  *(_DWORD *)&this->m_CntrHistArray.aCntrHist[4] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[4];
  *(_DWORD *)&this->m_CntrHistArray.aCntrHist[6] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[6];
  *(_DWORD *)&this->m_CntrHistArray.aCntrHist[8] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[8];
  *(_DWORD *)&this->m_CntrHistArray.aCntrHist[10] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[10];
  *(_DWORD *)&this->m_CntrHistArray.aCntrHist[12] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[12];
  *(_DWORD *)&this->m_CntrHistArray.aCntrHist[14] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[14];
  *(_DWORD *)&this->m_CntrHistArray.aCntrHist[16] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[16];
  *(_DWORD *)&this->m_CntrHistArray.aCntrHist[18] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[18];
  *(_DWORD *)&this->m_CntrHistArray.aCntrHist[20] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[20];
  *(_DWORD *)&this->m_CntrHistArray.aCntrHist[22] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[22];
  *(_DWORD *)&this->m_CntrHistArray.aCntrHist[24] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[24];
  *(_DWORD *)&this->m_CntrHistArray.aCntrHist[26] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[26];
  *(_DWORD *)&this->m_CntrHistArray.aCntrHist[28] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[28];
  *(_DWORD *)&this->m_CntrHistArray.aCntrHist[30] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[30];
}

// File Line: 169
// RVA: 0xA81860
AKRESULT __fastcall CAkPBI::Init(CAkPBI *this, AkPathInfo *in_pPathInfo)
{
  CAkLimiter *m_pAMLimiter; // rcx
  AKRESULT v5; // edi
  CAkLimiter *m_pBusLimiter; // rcx
  unsigned int m_PlayingID; // edx
  char v8; // al
  CAkRegisteredObj *m_pGameObj; // r8
  CAkSoundBase *m_pSound; // rcx
  CAkGen3DParams *m_p3DSound; // rsi
  CAkAttenuation *m_pAttenuation; // rdx
  CAkGen3DParams *v13; // rcx
  AKRESULT result; // eax
  CAkPath *pPBPath; // rdx
  AkPositionSourceType out_ePosType; // [rsp+50h] [rbp+8h] BYREF
  AkPannerType out_ePannerType; // [rsp+60h] [rbp+18h] BYREF

  m_pAMLimiter = this->m_pAMLimiter;
  v5 = AK_Fail;
  if ( m_pAMLimiter )
    CAkLimiter::Add(m_pAMLimiter, this, AKVoiceLimiter_AM);
  m_pBusLimiter = this->m_pBusLimiter;
  if ( m_pBusLimiter )
    CAkLimiter::Add(m_pBusLimiter, this, AKVoiceLimiter_Bus);
  CAkLimiter::Add(&CAkURenderer::m_GlobalLimiter, this, AKVoiceLimiter_Global);
  m_PlayingID = this->m_UserParams.m_PlayingID;
  if ( m_PlayingID )
  {
    v5 = (unsigned int)CAkPlayingMgr::SetPBI(g_pPlayingMgr, m_PlayingID, this, &this->m_uRegisteredNotif);
    if ( v5 == AK_Success )
    {
      v8 = ((__int64 (__fastcall *)(CAkSoundBase *, CAkRegisteredObj *))this->m_pSound->vfptr[14].Release)(
             this->m_pSound,
             this->m_pGameObj);
      *((_BYTE *)this + 375) &= ~1u;
      m_pGameObj = this->m_pGameObj;
      m_pSound = this->m_pSound;
      *((_BYTE *)this + 375) |= v8 & 1;
      this->m_p3DSound = 0i64;
      CAkParameterNode::Get3DParams(
        m_pSound,
        &this->m_p3DSound,
        m_pGameObj,
        &out_ePannerType,
        &out_ePosType,
        &this->m_BasePosParams);
      *((_BYTE *)this + 371) &= 0xF0u;
      m_p3DSound = this->m_p3DSound;
      *((_BYTE *)this + 371) |= out_ePannerType & 3 | (unsigned __int8)(4 * (out_ePosType & 3));
      if ( m_p3DSound )
      {
        if ( !m_p3DSound->m_Params.m_pAttenuation )
          m_p3DSound->m_Params.m_pAttenuation = (CAkAttenuation *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                                                    (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxAttenuations,
                                                                    m_p3DSound->m_Params.m_uAttenuationID);
        m_pAttenuation = m_p3DSound->m_Params.m_pAttenuation;
        v13 = this->m_p3DSound;
        if ( m_pAttenuation )
        {
          v13->m_Params.m_fConeOutsideVolume = m_pAttenuation->m_ConeParams.fOutsideVolume;
          this->m_p3DSound->m_Params.m_fConeLoPass = m_pAttenuation->m_ConeParams.LoPass;
          result = CAkPBI::SubscribeAttenuationRTPC(this, m_pAttenuation);
          v5 = result;
          if ( result != AK_Success )
            return result;
        }
        else if ( v13->m_Params.m_uAttenuationID )
        {
          return 2;
        }
        CAkPBI::Init3DPath(this, in_pPathInfo);
      }
      else
      {
        *((_BYTE *)this + 371) &= 0xFCu;
      }
      pPBPath = this->m_PathInfo.pPBPath;
      if ( pPBPath )
      {
        if ( (unsigned int)CAkPathManager::AddPathUser(g_pPathManager, pPBPath, (ITransitionable *)this) == 2 )
        {
          this->m_PathInfo.pPBPath = 0i64;
        }
        else
        {
          CAkPath::SetSoundUniqueID(this->m_PathInfo.pPBPath, this->m_pSound->key);
          CAkPath::SetPlayingID(this->m_PathInfo.pPBPath, this->m_UserParams.m_PlayingID);
        }
      }
      CAkSource::LockDataPtr(this->m_pSource, (void **)&this->m_pDataPtr, &this->m_uDataSize, &this->m_pUsageSlot);
    }
  }
  return v5;
}

// File Line: 260
// RVA: 0xA7FDC0
void __fastcall CAkPBI::~CAkPBI(CAkPBI *this)
{
  AkSoundPosition *m_aPos; // rdx
  AkExternalSourceArray *pExternalSrcs; // rcx

  this->CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkPBI::`vftable{for `CAkTransportAware};
  this->ITransitionable::vfptr = (ITransitionableVtbl *)&CAkContinuousPBI::`vftable{for `ITransitionable};
  m_aPos = this->m_cachedGameObjectPosition.m_aPos;
  if ( m_aPos )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, m_aPos);
    this->m_cachedGameObjectPosition.m_aPos = 0i64;
    this->m_cachedGameObjectPosition.m_uNumPos = 0;
  }
  pExternalSrcs = this->m_UserParams.m_CustomParam.pExternalSrcs;
  if ( pExternalSrcs )
    AkExternalSourceArray::Release(pExternalSrcs);
  this->CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkTransportAware::`vftable;
}

// File Line: 265
// RVA: 0xA82DA0
void __fastcall CAkPBI::Term(CAkPBI *this, bool __formal)
{
  CAkPath *pPBPath; // rax
  AkPathState *PathState; // rax
  CAkTransition *pvPSTrans; // rdx
  CAkTransition *pvPRTrans; // rdx
  char v7; // al
  unsigned int m_PlayingID; // edx
  CAkRegisteredObj *m_pGameObj; // rsi
  int v10; // ecx
  int v11; // ebx
  CAkGen3DParams *m_p3DSound; // rbx
  CAkAttenuation *m_pAttenuation; // rdx
  CAkGen3DParams *v14; // rbx
  int v15; // esi
  MapStruct<AkMutedMapItem,float> *m_pItems; // rdx
  CAkUsageSlot *m_pUsageSlot; // rcx
  char v18; // bl
  AkFeedbackParams *m_pFeedbackInfo; // rcx
  CAkSource *m_pSource; // rbx
  int v21; // edi

  CAkPBI::DecrementPlayCount(this);
  pPBPath = this->m_PathInfo.pPBPath;
  if ( pPBPath )
  {
    if ( (pPBPath->m_PathMode & 2) != 0 )
    {
      PathState = CAkParameterNode::GetPathState(this->m_pSound);
      PathState->pbPlayed = 0i64;
      PathState->ulCurrentListIndex = 0;
    }
    CAkPathManager::RemovePathUser(g_pPathManager, this->m_PathInfo.pPBPath, this);
    this->m_PathInfo.pPBPath = 0i64;
    this->m_PathInfo.PathOwnerID = 0;
  }
  pvPSTrans = this->m_PBTrans.pvPSTrans;
  if ( pvPSTrans )
    CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, pvPSTrans, &this->ITransitionable);
  pvPRTrans = this->m_PBTrans.pvPRTrans;
  if ( pvPRTrans )
    CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, pvPRTrans, &this->ITransitionable);
  v7 = *((_BYTE *)this + 373);
  if ( (v7 & 1) != 0 )
    *((_BYTE *)this + 373) = v7 & 0xFE;
  m_PlayingID = this->m_UserParams.m_PlayingID;
  if ( m_PlayingID )
    CAkPlayingMgr::Remove(g_pPlayingMgr, m_PlayingID, this);
  m_pGameObj = this->m_pGameObj;
  if ( m_pGameObj )
  {
    v10 = *((_DWORD *)m_pGameObj + 30) ^ (*((_DWORD *)m_pGameObj + 30) ^ (*((_DWORD *)m_pGameObj + 30) - 1)) & 0x3FFFFFFF;
    *((_DWORD *)m_pGameObj + 30) = v10;
    if ( (v10 & 0x3FFFFFFF) == 0 )
    {
      v11 = g_DefaultPoolId;
      CAkRegisteredObj::~CAkRegisteredObj(m_pGameObj);
      AK::MemoryMgr::Free(v11, m_pGameObj);
    }
  }
  m_p3DSound = this->m_p3DSound;
  if ( m_p3DSound )
  {
    if ( !m_p3DSound->m_Params.m_pAttenuation )
      m_p3DSound->m_Params.m_pAttenuation = (CAkAttenuation *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                                                (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxAttenuations,
                                                                m_p3DSound->m_Params.m_uAttenuationID);
    m_pAttenuation = m_p3DSound->m_Params.m_pAttenuation;
    if ( m_pAttenuation )
      CAkPBI::UnsubscribeAttenuationRTPC(this, m_pAttenuation);
    v14 = this->m_p3DSound;
    v15 = g_DefaultPoolId;
    if ( v14 )
    {
      v14->vfptr->__vecDelDtor(this->m_p3DSound, 0);
      AK::MemoryMgr::Free(v15, v14);
    }
    this->m_p3DSound = 0i64;
  }
  m_pItems = this->m_mapMutedNodes.m_pItems;
  if ( m_pItems )
  {
    this->m_mapMutedNodes.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_mapMutedNodes.m_pItems = 0i64;
    this->m_mapMutedNodes.m_ulReserved = 0;
  }
  CAkParameterNodeBase::RemovePBI(this->m_pSound, this);
  if ( this->m_pDataPtr )
  {
    CAkSource::UnLockDataPtr(this->m_pSource);
    this->m_pDataPtr = 0i64;
  }
  m_pUsageSlot = this->m_pUsageSlot;
  if ( m_pUsageSlot )
  {
    CAkUsageSlot::Release(m_pUsageSlot, 0);
    this->m_pUsageSlot = 0i64;
  }
  v18 = BYTE1(*((_DWORD *)&this->m_pSource->m_sSrcTypeInfo.mediaInfo + 4)) & 1;
  this->m_pSound->vfptr->Release(this->m_pSound);
  m_pFeedbackInfo = this->m_pFeedbackInfo;
  if ( m_pFeedbackInfo )
  {
    AkFeedbackParams::Destroy(m_pFeedbackInfo);
    this->m_pFeedbackInfo = 0i64;
  }
  if ( v18 )
  {
    m_pSource = this->m_pSource;
    v21 = g_DefaultPoolId;
    if ( m_pSource )
    {
      CAkSource::~CAkSource(m_pSource);
      AK::MemoryMgr::Free(v21, m_pSource);
    }
  }
}

// File Line: 369
// RVA: 0xA833D0
void __fastcall CAkPBI::_InitPlay(CAkPBI *this)
{
  char v2; // al
  bool v3; // zf
  AkPathState *PathState; // rax

  this->m_LoopCount = CAkSoundBase::Loop(this->m_pSound);
  v2 = *((_BYTE *)this + 373);
  if ( v2 >= 0 )
  {
    v3 = this->m_PathInfo.pPBPath == 0i64;
    *((_BYTE *)this + 373) = v2 | 0x80;
    if ( !v3 )
    {
      PathState = CAkParameterNode::GetPathState(this->m_pSound);
      CAkPathManager::Start(g_pPathManager, this->m_PathInfo.pPBPath, PathState);
    }
  }
}

// File Line: 388
// RVA: 0xA816F0
__int64 __fastcall CAkPBI::Init3DPath(CAkPBI *this, AkPathInfo *in_pPathInfo)
{
  Gen3DParams *p_m_Params; // r9
  char v5; // r8
  CAkSoundBase *m_pSound; // rcx
  bool v7; // al
  CAkParameterNodeBase *i; // rcx
  unsigned int m_ID; // esi
  AKRESULT v10; // edi
  CAkPath *v11; // rax
  AkPathState *PathState; // rax
  CAkPath *pPBPath; // rcx

  p_m_Params = &this->m_p3DSound->m_Params;
  if ( this->m_p3DSound == (CAkGen3DParams *)-8i64 )
    return 1i64;
  v5 = *((_BYTE *)this + 371);
  if ( (v5 & 0xC) == 0 )
  {
    m_pSound = this->m_pSound;
    v7 = (m_pSound->m_RTPCBitArray.m_iBitArray & 0x400) != 0
      && (*((_BYTE *)&m_pSound->CAkParameterNodeBase + 83) & 0x10) != 0;
    for ( i = m_pSound->m_pParentNode; !v7; i = i->m_pParentNode )
    {
      if ( !i )
        break;
      v7 = (i->m_RTPCBitArray.m_iBitArray & 0x400) != 0 && (*((_BYTE *)i + 83) & 0x10) != 0;
    }
    if ( (v5 & 3) == 0 && !v7 )
      return 1i64;
  }
  m_ID = p_m_Params->m_ID;
  v10 = AK_Success;
  if ( in_pPathInfo->pPBPath && in_pPathInfo->PathOwnerID == m_ID )
    this->m_PathInfo = *in_pPathInfo;
  if ( !this->m_PathInfo.pPBPath || (p_m_Params->m_ePathMode & 4) != 0 )
  {
    CAkPathManager::AddPathToList(g_pPathManager);
    this->m_PathInfo.pPBPath = v11;
    if ( v11 )
    {
      PathState = CAkParameterNode::GetPathState(this->m_pSound);
      v10 = CAkGen3DParams::SetPathPlayList(this->m_p3DSound, this->m_PathInfo.pPBPath, PathState);
      if ( v10 != AK_Success )
      {
        CAkPathManager::RemovePathFromList(g_pPathManager, this->m_PathInfo.pPBPath);
        m_ID = 0;
        this->m_PathInfo.pPBPath = 0i64;
      }
      this->m_PathInfo.PathOwnerID = m_ID;
    }
  }
  if ( (*((_BYTE *)&this->m_p3DSound->m_Params + 68) & 0x10) == 0 )
  {
    pPBPath = this->m_PathInfo.pPBPath;
    if ( pPBPath )
      CAkPath::InitRotationMatricesForNoFollowMode(
        pPBPath,
        (unsigned __int8)this->m_pGameObj->m_PosKeep.m_uListenerMask);
  }
  return (unsigned int)v10;
}

// File Line: 459
// RVA: 0xA83650
__int64 __fastcall CAkPBI::_Play(
        CAkPBI *this,
        TransParams *in_transParams,
        CAkTransition **in_bPaused,
        bool in_bForceIgnoreSync)
{
  char v5; // bp
  __int64 in_NewDuration; // rbx
  CAkTransition *pvPSTrans; // rdx
  ITransitionable *v9; // r14
  CAkTransition *v10; // rax
  CAkTransportAwareVtbl *vfptr; // r9
  CAkTransition *v12; // rdi
  __int64 v13; // r8
  __int64 v14; // r9
  unsigned int v15; // ebx
  unsigned int v16; // eax
  CAkTransition *v17; // rdx
  CAkPath *pPBPath; // rdx
  __int64 result; // rax
  TransitionParameters v20; // [rsp+40h] [rbp-48h] BYREF

  v5 = (char)in_bPaused;
  if ( in_transParams->TransitionTime )
  {
    this->m_fPlayStopFadeRatio = 0.0;
    in_NewDuration = (__int64)*in_transParams;
    pvPSTrans = this->m_PBTrans.pvPSTrans;
    if ( pvPSTrans )
    {
      CAkTransitionManager::ChangeParameter(
        g_pTransitionManager,
        pvPSTrans,
        0x1000000i64,
        1.0,
        in_NewDuration,
        SHIDWORD(in_NewDuration),
        AkValueMeaning_Default);
    }
    else
    {
      v20.eTarget = 0x1000000i64;
      v9 = &this->ITransitionable;
      v20.pUser = &this->ITransitionable;
      v20.fStartValue = 0.0;
      LODWORD(v20.fTargetValue) = (_DWORD)FLOAT_1_0;
      LOBYTE(in_bPaused) = 1;
      *(_QWORD *)&v20.lDuration = in_NewDuration;
      *(_WORD *)&v20.bdBs = 256;
      v10 = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &v20, in_bPaused, 0i64);
      vfptr = this->CAkTransportAware::vfptr;
      *((_BYTE *)&this->m_PBTrans + 16) &= ~1u;
      *((_BYTE *)this + 375) |= 0x80u;
      v12 = v10;
      this->m_PBTrans.pvPSTrans = v10;
      ((void (__fastcall *)(CAkPBI *, __int64, _QWORD))vfptr[8]._Stop)(this, 14i64, (unsigned int)in_NewDuration);
      if ( !v12 )
      {
        LOBYTE(v14) = 1;
        ((void (__fastcall *)(ITransitionable *, __int64, __int64, __int64))v9->vfptr->TransUpdateValue)(
          v9,
          v20.eTarget,
          v13,
          v14);
      }
    }
  }
  if ( v5 == 1 || (*((_BYTE *)this + 370) & 7) == 1 )
  {
    *((_BYTE *)this + 373) |= 0x40u;
    v16 = CAkLEngineCmds::EnqueueAction(LEStatePlayPause, this);
    v17 = this->m_PBTrans.pvPSTrans;
    v15 = v16;
    if ( v17 )
      CAkTransitionManager::Pause(g_pTransitionManager, v17);
    pPBPath = this->m_PathInfo.pPBPath;
    if ( pPBPath )
      CAkPathManager::Pause(g_pPathManager, pPBPath);
  }
  else
  {
    v15 = CAkLEngineCmds::EnqueueAction(LEStatePlay, this);
  }
  if ( v15 != 1 )
    return v15;
  if ( (*((_BYTE *)this + 370) & 7) == 2 )
    this->CAkTransportAware::vfptr->_Stop(this, AkPBIStopMode_Normal, 0i64, 0i64);
  result = 1i64;
  if ( in_bForceIgnoreSync )
    ++CAkLEngineCmds::m_ulPlayEventID;
  return result;
}

// File Line: 510
// RVA: 0xA83C20
void __fastcall CAkPBI::_Stop(CAkPBI *this, AkPBIStopMode in_eStopMode, bool in_bIsFromTransition, bool __formal)
{
  char v4; // al
  CAkTransition *pvPSTrans; // rdx
  CAkTransition *pvPRTrans; // rdx
  CAkPath *pPBPath; // rax
  AkPathState *PathState; // rax

  v4 = *((_BYTE *)this + 373);
  if ( (v4 & 0x10) == 0 )
  {
    *((_BYTE *)this + 373) = v4 | 0x10;
    if ( !in_bIsFromTransition )
      CAkLEngineCmds::EnqueueActionStop(this);
    if ( (in_eStopMode & 0xFFFFFFFD) == 0 )
    {
      pvPSTrans = this->m_PBTrans.pvPSTrans;
      if ( pvPSTrans )
      {
        CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, pvPSTrans, &this->ITransitionable);
        this->m_PBTrans.pvPSTrans = 0i64;
      }
      pvPRTrans = this->m_PBTrans.pvPRTrans;
      if ( pvPRTrans )
      {
        CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, pvPRTrans, &this->ITransitionable);
        this->m_PBTrans.pvPRTrans = 0i64;
      }
      pPBPath = this->m_PathInfo.pPBPath;
      if ( pPBPath )
      {
        if ( (pPBPath->m_PathMode & 2) != 0 )
        {
          PathState = CAkParameterNode::GetPathState(this->m_pSound);
          PathState->pbPlayed = 0i64;
          PathState->ulCurrentListIndex = 0;
        }
        CAkPathManager::RemovePathUser(g_pPathManager, this->m_PathInfo.pPBPath, this);
        this->m_PathInfo.pPBPath = 0i64;
        this->m_PathInfo.PathOwnerID = 0;
      }
      *((_BYTE *)this + 373) &= ~1u;
      *((_BYTE *)this + 373) |= 4u;
    }
  }
}

// File Line: 603
// RVA: 0xA83A40
void __fastcall CAkPBI::_Stop(
        CAkPBI *this,
        TransParams *in_transParams,
        CAkTransition **in_bUseMinTransTime,
        _BOOL8 a4)
{
  char v4; // al
  __int64 in_NewDuration; // rbx
  CAkTransition *pvPSTrans; // rdx
  ITransitionable *v8; // r14
  CAkTransition *v9; // rax
  CAkTransportAwareVtbl *vfptr; // r9
  CAkTransition *v11; // rdi
  __int64 v12; // r8
  __int64 v13; // r9
  CAkTransition *v14; // rdx
  TransitionParameters in_Params; // [rsp+40h] [rbp-38h] BYREF

  v4 = *((_BYTE *)this + 373);
  if ( (v4 & 0x40) != 0 || this->m_PBTrans.pvPRTrans && (*((_BYTE *)&this->m_PBTrans + 16) & 2) != 0 )
  {
    this->CAkTransportAware::vfptr->_Stop(this, AkPBIStopMode_Normal, 0i64, 0i64);
  }
  else
  {
    *((_BYTE *)this + 373) = v4 | 0x20;
    if ( in_transParams->TransitionTime )
    {
      in_NewDuration = (__int64)*in_transParams;
      pvPSTrans = this->m_PBTrans.pvPSTrans;
      if ( pvPSTrans )
      {
        CAkTransitionManager::ChangeParameter(
          g_pTransitionManager,
          pvPSTrans,
          0x2000000i64,
          0.0,
          in_NewDuration,
          SHIDWORD(in_NewDuration),
          AkValueMeaning_Default);
      }
      else
      {
        v8 = &this->ITransitionable;
        in_Params.fStartValue = this->m_fPlayStopFadeRatio;
        in_Params.fTargetValue = 0.0;
        LOBYTE(in_bUseMinTransTime) = 1;
        in_Params.pUser = &this->ITransitionable;
        in_Params.eTarget = 0x2000000i64;
        *(_QWORD *)&in_Params.lDuration = in_NewDuration;
        *(_WORD *)&in_Params.bdBs = 256;
        v9 = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, in_bUseMinTransTime, 0i64);
        vfptr = this->CAkTransportAware::vfptr;
        *((_BYTE *)&this->m_PBTrans + 16) |= 1u;
        *((_BYTE *)this + 375) &= ~0x80u;
        v11 = v9;
        this->m_PBTrans.pvPSTrans = v9;
        ((void (__fastcall *)(CAkPBI *, __int64, _QWORD))vfptr[8]._Stop)(this, 14i64, (unsigned int)in_NewDuration);
        if ( !v11 )
        {
          LOBYTE(v13) = 1;
          ((void (__fastcall *)(ITransitionable *, __int64, __int64, __int64))v8->vfptr->TransUpdateValue)(
            v8,
            in_Params.eTarget,
            v12,
            v13);
        }
      }
    }
    else if ( (*((_BYTE *)this + 370) & 0x78) != 0 )
    {
      v14 = this->m_PBTrans.pvPSTrans;
      if ( v14 )
      {
        CAkTransitionManager::ChangeParameter(
          g_pTransitionManager,
          v14,
          0x2000000i64,
          0.0,
          0,
          AkCurveInterpolation_Linear,
          AkValueMeaning_Default);
      }
      else if ( (_BYTE)in_bUseMinTransTime )
      {
        CAkPBI::StopWithMinTransTime(this, 0i64, (_BOOL8)in_bUseMinTransTime);
      }
    }
    else
    {
      LOBYTE(a4) = 1;
      this->CAkTransportAware::vfptr->_Stop(this, AkPBIStopMode_Normal, 0i64, a4);
    }
  }
}

// File Line: 648
// RVA: 0xA82C90
void __fastcall CAkPBI::StopWithMinTransTime(CAkPBI *this, __int64 a2, _BOOL8 a3)
{
  char v3; // al

  v3 = *((_BYTE *)this + 374);
  if ( v3 >= 0 )
  {
    this->m_fPlayStopFadeRatio = 0.0;
    this->m_EffectiveParams.fFadeRatio = 0.0;
  }
  if ( (v3 & 1) == 0 )
    *((_BYTE *)this + 374) = v3 & 0xF0 | 1;
  LOBYTE(a3) = 1;
  this->CAkTransportAware::vfptr->_Stop(this, AkPBIStopMode_Normal, a3, 0i64);
}

// File Line: 678
// RVA: 0xA835D0
void __fastcall CAkPBI::_Pause(CAkPBI *this, bool in_bIsFromTransition)
{
  char v2; // al
  bool v4; // zf
  CAkTransition *pvPSTrans; // rdx
  CAkPath *pPBPath; // rdx

  v2 = *((_BYTE *)this + 373);
  if ( (v2 & 0x10) == 0 && (v2 & 0x40) == 0 )
  {
    v4 = *((_BYTE *)this + 374) >= 0;
    *((_BYTE *)this + 373) = v2 | 0x40;
    if ( v4 )
    {
      this->m_fPauseResumeFadeRatio = 0.0;
      this->m_EffectiveParams.fFadeRatio = 0.0;
    }
    if ( !in_bIsFromTransition )
      CAkLEngineCmds::EnqueueAction(LEStatePause, this);
    pvPSTrans = this->m_PBTrans.pvPSTrans;
    if ( pvPSTrans )
      CAkTransitionManager::Pause(g_pTransitionManager, pvPSTrans);
    pPBPath = this->m_PathInfo.pPBPath;
    if ( pPBPath )
      CAkPathManager::Pause(g_pPathManager, pPBPath);
  }
}

// File Line: 707
// RVA: 0xA83440
void __fastcall CAkPBI::_Pause(CAkPBI *this, TransParams *in_transParams, CAkTransition **a3)
{
  __int64 in_NewDuration; // rbx
  CAkTransition *pvPRTrans; // rdx
  float m_fPauseResumeFadeRatio; // xmm0_4
  ITransitionable *v7; // r14
  CAkTransition *v8; // rax
  CAkTransportAwareVtbl *vfptr; // r9
  CAkTransition *v10; // rdi
  __int64 v11; // r8
  __int64 v12; // r9
  CAkTransition *v13; // rdx
  TransitionParameters in_Params; // [rsp+40h] [rbp-38h] BYREF

  ++this->m_ulPauseCount;
  if ( in_transParams->TransitionTime )
  {
    in_NewDuration = (__int64)*in_transParams;
    pvPRTrans = this->m_PBTrans.pvPRTrans;
    if ( pvPRTrans )
    {
      CAkTransitionManager::ChangeParameter(
        g_pTransitionManager,
        pvPRTrans,
        0x4000000i64,
        0.0,
        in_NewDuration,
        SHIDWORD(in_NewDuration),
        AkValueMeaning_Default);
    }
    else
    {
      m_fPauseResumeFadeRatio = this->m_fPauseResumeFadeRatio;
      in_Params.eTarget = 0x4000000i64;
      *(_QWORD *)&in_Params.lDuration = in_NewDuration;
      in_Params.fStartValue = m_fPauseResumeFadeRatio;
      v7 = &this->ITransitionable;
      in_Params.fTargetValue = 0.0;
      in_Params.pUser = &this->ITransitionable;
      LOBYTE(a3) = 1;
      *(_WORD *)&in_Params.bdBs = 256;
      v8 = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, a3, 0i64);
      vfptr = this->CAkTransportAware::vfptr;
      *((_BYTE *)&this->m_PBTrans + 16) |= 2u;
      v10 = v8;
      this->m_PBTrans.pvPRTrans = v8;
      ((void (__fastcall *)(CAkPBI *, __int64, _QWORD))vfptr[8]._Stop)(this, 14i64, (unsigned int)in_NewDuration);
      if ( !v10 )
      {
        LOBYTE(v12) = 1;
        ((void (__fastcall *)(ITransitionable *, __int64, __int64, __int64))v7->vfptr->TransUpdateValue)(
          v7,
          in_Params.eTarget,
          v11,
          v12);
      }
    }
  }
  else if ( (*((_BYTE *)this + 370) & 0x78) != 0 )
  {
    v13 = this->m_PBTrans.pvPRTrans;
    if ( v13 )
      CAkTransitionManager::ChangeParameter(
        g_pTransitionManager,
        v13,
        0x4000000i64,
        0.0,
        0,
        AkCurveInterpolation_Linear,
        AkValueMeaning_Default);
    else
      ((void (__fastcall *)(CAkPBI *, __int64))this->CAkTransportAware::vfptr[2].~CAkTransportAware)(this, 1i64);
  }
  else
  {
    ((void (__fastcall *)(CAkPBI *, _QWORD))this->CAkTransportAware::vfptr[2].~CAkTransportAware)(this, 0i64);
  }
}

// File Line: 740
// RVA: 0xA839D0
void __fastcall CAkPBI::_Resume(CAkPBI *this)
{
  char v1; // al
  CAkPath *pPBPath; // rdx
  CAkTransition *pvPSTrans; // rdx

  v1 = *((_BYTE *)this + 373);
  if ( (v1 & 0x10) == 0 && (v1 & 0x40) != 0 )
  {
    pPBPath = this->m_PathInfo.pPBPath;
    if ( pPBPath )
      CAkPathManager::Resume(g_pPathManager, pPBPath);
    *((_BYTE *)this + 373) &= ~0x40u;
    CAkLEngineCmds::EnqueueAction(LEStateResume, this);
    pvPSTrans = this->m_PBTrans.pvPSTrans;
    if ( pvPSTrans )
      CAkTransitionManager::Resume(g_pTransitionManager, pvPSTrans);
  }
}

// File Line: 760
// RVA: 0xA83820
void __fastcall CAkPBI::_Resume(CAkPBI *this, TransParams *in_transParams, bool in_bIsMasterResume)
{
  unsigned int m_ulPauseCount; // eax
  CAkTransportAwareVtbl *vfptr; // rax
  CAkTransition **v7; // r8
  CAkTransition *pvPRTrans; // rdx
  __int64 in_NewDuration; // rbx
  CAkTransition *v10; // rax
  CAkTransportAwareVtbl *v11; // r9
  CAkTransition *v12; // rdi
  __int64 v13; // r8
  __int64 v14; // r9
  TransitionParameters in_Params; // [rsp+40h] [rbp-38h] BYREF

  if ( in_bIsMasterResume || (m_ulPauseCount = this->m_ulPauseCount, m_ulPauseCount <= 1) )
  {
    vfptr = this->CAkTransportAware::vfptr;
    this->m_ulPauseCount = 0;
    ((void (*)(void))vfptr[3]._Stop)();
    pvPRTrans = this->m_PBTrans.pvPRTrans;
    if ( in_transParams->TransitionTime )
    {
      in_NewDuration = (__int64)*in_transParams;
      if ( pvPRTrans )
      {
        CAkTransitionManager::ChangeParameter(
          g_pTransitionManager,
          pvPRTrans,
          0x8000000i64,
          1.0,
          in_NewDuration,
          SHIDWORD(in_NewDuration),
          AkValueMeaning_Default);
      }
      else
      {
        in_Params.fStartValue = this->m_fPauseResumeFadeRatio;
        LODWORD(in_Params.fTargetValue) = (_DWORD)FLOAT_1_0;
        LOBYTE(v7) = 1;
        in_Params.eTarget = 0x8000000i64;
        *(_QWORD *)&in_Params.lDuration = in_NewDuration;
        in_Params.pUser = &this->ITransitionable;
        *(_WORD *)&in_Params.bdBs = 256;
        v10 = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, v7, 0i64);
        v11 = this->CAkTransportAware::vfptr;
        *((_BYTE *)&this->m_PBTrans + 16) &= ~2u;
        v12 = v10;
        this->m_PBTrans.pvPRTrans = v10;
        ((void (__fastcall *)(CAkPBI *, __int64, _QWORD))v11[8]._Stop)(this, 14i64, (unsigned int)in_NewDuration);
        if ( !v12 )
        {
          LOBYTE(v14) = 1;
          ((void (__fastcall *)(ITransitionable *, __int64, __int64, __int64))this->ITransitionable::vfptr->TransUpdateValue)(
            &this->ITransitionable,
            in_Params.eTarget,
            v13,
            v14);
        }
      }
    }
    else if ( pvPRTrans )
    {
      CAkTransitionManager::ChangeParameter(
        g_pTransitionManager,
        pvPRTrans,
        0x8000000i64,
        1.0,
        0,
        AkCurveInterpolation_Linear,
        AkValueMeaning_Default);
    }
    else
    {
      this->m_fPauseResumeFadeRatio = 1.0;
      CAkPBI::CalculateMutedEffectiveVolume(this);
    }
  }
  else
  {
    this->m_ulPauseCount = m_ulPauseCount - 1;
  }
}

// File Line: 796
// RVA: 0xA823F0
void __fastcall CAkPBI::PlayToEnd(CAkPBI *this, CAkParameterNodeBase *__formal)
{
  this->m_LoopCount = 1;
  CAkLEngineCmds::EnqueueAction(LEStateStopLooping, this);
}

// File Line: 803
// RVA: 0xA82B10
void __fastcall CAkPBI::SeekTimeAbsolute(CAkPBI *this, int in_iPosition, bool in_bSnapToMarker)
{
  unsigned int v3; // kr00_4

  v3 = AkAudioLibSettings::g_pipelineCoreFrequency;
  *((_BYTE *)this + 375) &= 0xF3u;
  *((_BYTE *)this + 375) |= (unsigned __int8)(8 * in_bSnapToMarker) | 2;
  this->m_uSeekPosition = in_iPosition * (v3 / 0x3E8);
  CAkLEngineCmds::EnqueueAction(LEStateSeek, this);
}

// File Line: 814
// RVA: 0xA82AD0
void __fastcall CAkPBI::SeekPercent(CAkPBI *this, float in_fPercent, bool in_bSnapToMarker)
{
  this->m_fSeekPercent = in_fPercent;
  *((_BYTE *)this + 375) = *((_BYTE *)this + 375) ^ (*((_BYTE *)this + 375) ^ (8 * in_bSnapToMarker)) & 8 | 6;
  CAkLEngineCmds::EnqueueAction(LEStateSeek, this);
}

// File Line: 826
// RVA: 0xA82080
void __fastcall CAkPBI::ParamNotification(CAkPBI *this, NotifParams *in_rParams)
{
  AkFeedbackParams *m_pFeedbackInfo; // rax
  float v5; // xmm0_4
  float v6; // xmm1_4
  AkFeedbackParams *v7; // rax
  AkFeedbackParams *v8; // rax

  switch ( in_rParams->eType )
  {
    case RTPC_Volume:
    case RTPC_BusVolume:
      if ( *((char *)this + 374) >= 0 || !in_rParams->bIsFromBus )
      {
        this->m_Volume = in_rParams->fValue + this->m_Volume;
        CAkPBI::CalculateMutedEffectiveVolume(this);
        if ( in_rParams->bIsFromBus )
        {
          m_pFeedbackInfo = this->m_pFeedbackInfo;
          if ( m_pFeedbackInfo )
            m_pFeedbackInfo->m_AudioBusVolume = in_rParams->fValue + m_pFeedbackInfo->m_AudioBusVolume;
        }
      }
      return;
    case RTPC_Pitch:
      goto $LN17_66;
    case RTPC_LPF:
      v5 = in_rParams->fValue + this->m_LPF;
      this->m_LPF = v5;
      this->m_EffectiveParams.LPF = v5 + this->m_LPFAutomationOffset;
      return;
    case RTPC_Priority:
      v6 = (float)(this->m_PriorityInfoCurrent.priorityInfo.priority + in_rParams->fValue)
         - this->m_PriorityInfoCurrent.currentPriority.priority;
      if ( v6 < 0.0 )
        goto LABEL_13;
      if ( v6 >= 100.0 )
      {
        v6 = FLOAT_100_0;
      }
      else if ( v6 < 0.0 )
      {
LABEL_13:
        v6 = 0.0;
      }
      CAkPBI::UpdatePriority(this, v6);
      this->m_PriorityInfoCurrent.priorityInfo.priority = in_rParams->fValue;
      return;
    case RTPC_UserAuxSendVolume0:
      this->m_EffectiveParams.aUserAuxSendVolume[0] = in_rParams->fValue + this->m_EffectiveParams.aUserAuxSendVolume[0];
      return;
    case RTPC_UserAuxSendVolume1:
      this->m_EffectiveParams.aUserAuxSendVolume[1] = in_rParams->fValue + this->m_EffectiveParams.aUserAuxSendVolume[1];
      return;
    case RTPC_UserAuxSendVolume2:
      this->m_EffectiveParams.aUserAuxSendVolume[2] = in_rParams->fValue + this->m_EffectiveParams.aUserAuxSendVolume[2];
      return;
    case RTPC_UserAuxSendVolume3:
      this->m_EffectiveParams.aUserAuxSendVolume[3] = in_rParams->fValue + this->m_EffectiveParams.aUserAuxSendVolume[3];
      return;
    case RTPC_GameAuxSendVolume:
      this->m_EffectiveParams.fGameAuxSendVolume = in_rParams->fValue + this->m_EffectiveParams.fGameAuxSendVolume;
      return;
    case RTPC_OutputBusVolume:
      this->m_EffectiveParams.fOutputBusVolume = in_rParams->fValue + this->m_EffectiveParams.fOutputBusVolume;
      return;
    case RTPC_OutputBusLPF:
      this->m_EffectiveParams.fOutputBusLPF = in_rParams->fValue + this->m_EffectiveParams.fOutputBusLPF;
      return;
    case RTPC_FeedbackVolume:
      v7 = this->m_pFeedbackInfo;
      if ( v7 )
        v7->m_NewVolume = in_rParams->fValue + v7->m_NewVolume;
      return;
    case RTPC_FeedbackLowpass:
      v8 = this->m_pFeedbackInfo;
      if ( v8 )
        v8->m_LPF = in_rParams->fValue + v8->m_LPF;
      return;
    case RTPC_FeedbackPitch:
      if ( *((char *)this + 374) < 0 )
$LN17_66:
        this->m_EffectiveParams.Pitch = in_rParams->fValue + this->m_EffectiveParams.Pitch;
      return;
    case RTPC_HDRActiveRange:
      this->m_EffectiveParams.hdr.fActiveRange = in_rParams->fValue + this->m_EffectiveParams.hdr.fActiveRange;
      return;
    case RTPC_MakeUpGain:
      this->m_EffectiveParams.normalization.fMakeUpGain = in_rParams->fValue
                                                        + this->m_EffectiveParams.normalization.fMakeUpGain;
      return;
    default:
      return;
  }
}

// File Line: 924
// RVA: 0xA81E60
void __fastcall CAkPBI::MuteNotification(
        CAkPBI *this,
        float in_fMuteRatio,
        AkMutedMapItem *in_rMutedItem,
        bool in_bPrioritizeGameObjectSpecificItems)
{
  MapStruct<AkMutedMapItem,float> *m_pItems; // rdi
  int v6; // r11d
  void *m_Identifier; // r10
  MapStruct<AkMutedMapItem,float> *v8; // rcx
  unsigned __int8 v9; // si
  MapStruct<AkMutedMapItem,float> *i; // rax
  unsigned __int64 v11; // rcx
  MapStruct<AkMutedMapItem,float> *v12; // rdi
  __int64 m_uLength; // rax
  MapStruct<AkMutedMapItem,float> *v14; // rcx
  unsigned __int64 v15; // rcx
  AkMutedMapItem v16; // [rsp+20h] [rbp-18h] BYREF

  if ( in_bPrioritizeGameObjectSpecificItems )
  {
    m_pItems = this->m_mapMutedNodes.m_pItems;
    v6 = *((_DWORD *)in_rMutedItem + 2);
    m_Identifier = in_rMutedItem->m_Identifier;
    v8 = &m_pItems[this->m_mapMutedNodes.m_uLength];
    v9 = *((_BYTE *)&v16 + 8) & 0xFC | ((v6 & 1) == 0);
    for ( i = m_pItems; i != v8; ++i )
    {
      if ( i->key.m_Identifier == m_Identifier && ((v9 ^ *((_BYTE *)&i->key + 8)) & 1) == 0 )
        break;
    }
    if ( i != v8 && i != (MapStruct<AkMutedMapItem,float> *)-16i64 )
    {
      if ( (v6 & 1) != 0 )
        return;
      if ( m_pItems != v8 )
      {
        do
        {
          if ( m_pItems->key.m_Identifier == m_Identifier && ((v9 ^ *((_BYTE *)&m_pItems->key + 8)) & 1) == 0 )
            break;
          ++m_pItems;
        }
        while ( m_pItems != v8 );
        if ( m_pItems != v8 )
        {
          v11 = (unsigned __int64)&v8[-1];
          if ( (unsigned __int64)m_pItems < v11 )
            qmemcpy(m_pItems, &m_pItems[1], 24 * ((v11 - (unsigned __int64)m_pItems - 1) / 0x18 + 1));
          --this->m_mapMutedNodes.m_uLength;
        }
      }
    }
  }
  if ( in_fMuteRatio == 1.0 && (!in_bPrioritizeGameObjectSpecificItems || (*((_BYTE *)in_rMutedItem + 8) & 1) != 0) )
  {
    v12 = this->m_mapMutedNodes.m_pItems;
    m_uLength = this->m_mapMutedNodes.m_uLength;
    v16 = *in_rMutedItem;
    v14 = &v12[m_uLength];
    if ( v12 != v14 )
    {
      do
      {
        if ( v12->key.m_Identifier == v16.m_Identifier && ((*((_BYTE *)&v16 + 8) ^ *((_BYTE *)&v12->key + 8)) & 1) == 0 )
          break;
        ++v12;
      }
      while ( v12 != v14 );
      if ( v12 != v14 )
      {
        v15 = (unsigned __int64)&v14[-1];
        if ( (unsigned __int64)v12 < v15 )
          qmemcpy(v12, &v12[1], 24 * ((v15 - (unsigned __int64)v12 - 1) / 0x18 + 1));
        --this->m_mapMutedNodes.m_uLength;
      }
    }
  }
  else
  {
    v16 = *in_rMutedItem;
    CAkKeyArray<AkMutedMapItem,float,2>::Set(&this->m_mapMutedNodes, &v16, in_fMuteRatio);
  }
  CAkPBI::CalculateMutedEffectiveVolume(this);
}

// File Line: 974
// RVA: 0xA82B60
__int64 __fastcall CAkPBI::SetMuteMapEntry(CAkPBI *this, AkMutedMapItem *in_key, float in_fFadeRatio)
{
  unsigned int v4; // edi
  MapStruct<AkMutedMapItem,float> *m_pItems; // rdi
  MapStruct<AkMutedMapItem,float> *v6; // rax
  AkMutedMapItem v8; // [rsp+20h] [rbp-18h] BYREF

  v8 = *in_key;
  if ( in_fFadeRatio == 1.0 )
  {
    m_pItems = this->m_mapMutedNodes.m_pItems;
    v6 = &m_pItems[this->m_mapMutedNodes.m_uLength];
    if ( m_pItems != v6 )
    {
      do
      {
        if ( m_pItems->key.m_Identifier == v8.m_Identifier
          && ((*((_BYTE *)&v8 + 8) ^ *((_BYTE *)&m_pItems->key + 8)) & 1) == 0 )
        {
          break;
        }
        ++m_pItems;
      }
      while ( m_pItems != v6 );
      if ( m_pItems != v6 )
      {
        if ( m_pItems < &v6[-1] )
          qmemcpy(m_pItems, &m_pItems[1], 24 * (((char *)&v6[-1] - (char *)m_pItems - 1) / 0x18ui64 + 1));
        --this->m_mapMutedNodes.m_uLength;
      }
    }
    v4 = 1;
  }
  else
  {
    v4 = 2 - (CAkKeyArray<AkMutedMapItem,float,2>::Set(&this->m_mapMutedNodes, &v8, in_fFadeRatio) != 0i64);
  }
  CAkPBI::CalculateMutedEffectiveVolume(this);
  return v4;
}

// File Line: 990
// RVA: 0xA82930
void __fastcall CAkPBI::RemoveAllVolatileMuteItems(CAkPBI *this)
{
  MapStruct<AkMutedMapItem,float> *m_pItems; // rax
  __int64 m_uLength; // rdx
  MapStruct<AkMutedMapItem,float> *v3; // r9

  m_pItems = this->m_mapMutedNodes.m_pItems;
  if ( m_pItems != &m_pItems[this->m_mapMutedNodes.m_uLength] )
  {
    do
    {
      if ( (*((_BYTE *)&m_pItems->key + 8) & 2) != 0 )
      {
        ++m_pItems;
      }
      else
      {
        m_uLength = this->m_mapMutedNodes.m_uLength;
        if ( (unsigned int)m_uLength > 1 )
        {
          v3 = &this->m_mapMutedNodes.m_pItems[m_uLength];
          m_pItems->key.m_Identifier = v3[-1].key.m_Identifier;
          *((_QWORD *)&m_pItems->key + 1) = *((_QWORD *)&v3[-1].key + 1);
          *(_QWORD *)&m_pItems->item = *(_QWORD *)&v3[-1].item;
        }
        --this->m_mapMutedNodes.m_uLength;
      }
    }
    while ( m_pItems != &this->m_mapMutedNodes.m_pItems[this->m_mapMutedNodes.m_uLength] );
  }
}

// File Line: 1002
// RVA: 0xA816B0
float __fastcall CAkPBI::GetVoiceVolumedB(CAkPBI *this)
{
  CAkBus *m_pControlBus; // rbx

  m_pControlBus = this->m_pControlBus;
  if ( !m_pControlBus )
    return 0.0;
  if ( (*((_BYTE *)m_pControlBus + 304) & 1) == 0 )
    CAkBus::UpdateVoiceVolumes(this->m_pControlBus);
  return m_pControlBus->m_fEffectiveVoiceVolume;
}

// File Line: 1015
// RVA: 0xA815C0
float __fastcall CAkPBI::GetOutputBusVolumeValuedB(CAkPBI *this)
{
  CAkBus *m_pControlBus; // rbx
  float fOutputBusVolume; // xmm6_4

  m_pControlBus = this->m_pControlBus;
  fOutputBusVolume = this->m_EffectiveParams.fOutputBusVolume;
  if ( m_pControlBus )
  {
    if ( (*((_BYTE *)m_pControlBus + 304) & 1) == 0 )
      CAkBus::UpdateVoiceVolumes(this->m_pControlBus);
    return fOutputBusVolume + m_pControlBus->m_fEffectiveBusVolume;
  }
  return fOutputBusVolume;
}

// File Line: 1028
// RVA: 0xA82A40
float __fastcall CAkPBI::Scale3DUserDefRTPCValue(CAkPBI *this, float in_fValue)
{
  CAkGen3DParams *m_p3DSound; // rbx
  float v3; // xmm6_4
  CAkAttenuation *m_pAttenuation; // rcx
  unsigned __int8 v5; // al
  __int64 v6; // rdx

  m_p3DSound = this->m_p3DSound;
  v3 = in_fValue;
  if ( !m_p3DSound->m_Params.m_pAttenuation )
    m_p3DSound->m_Params.m_pAttenuation = (CAkAttenuation *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                                              (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxAttenuations,
                                                              m_p3DSound->m_Params.m_uAttenuationID);
  m_pAttenuation = m_p3DSound->m_Params.m_pAttenuation;
  if ( m_pAttenuation )
  {
    v5 = m_pAttenuation->m_curveToUse[0];
    if ( v5 != 0xFF )
    {
      v6 = (__int64)&m_pAttenuation->m_curves[v5];
      if ( *(_QWORD *)v6 )
      {
        if ( v6 )
          return (float)(in_fValue * *(float *)(*(_QWORD *)v6 + 12i64 * (unsigned int)(*(_DWORD *)(v6 + 8) - 1)))
               * 0.0099999998;
      }
    }
  }
  return v3;
}

// File Line: 1046
// RVA: 0xA82410
void __fastcall CAkPBI::PositioningChangeNotification(
        CAkPBI *this,
        float in_RTPCValue,
        AkRTPC_ParameterID in_ParameterID)
{
  CAkGen3DParams *m_p3DSound; // rdi
  CAkGen3DParams *v5; // rdi
  char v6; // al
  CAkGen3DParams *v7; // rcx
  int v8; // r8d
  int v9; // r8d
  int v10; // r8d
  AkPositionSourceType out_ePosType; // [rsp+50h] [rbp+18h] BYREF
  AkPannerType out_ePannerType; // [rsp+58h] [rbp+20h] BYREF

  switch ( in_ParameterID )
  {
    case RTPC_PositioningType:
      v6 = (int)in_RTPCValue & 3 | *((_BYTE *)this + 371) & 0xEC | (*((_BYTE *)this + 371) | (16
                                                                                            * ((*((_BYTE *)this + 371) & 3) != (int)in_RTPCValue))) & 0x10;
      *((_BYTE *)this + 371) = v6;
      if ( (v6 & 3) == 1 && !this->m_p3DSound )
      {
        CAkParameterNode::Get3DParams(
          this->m_pSound,
          &this->m_p3DSound,
          this->m_pGameObj,
          &out_ePannerType,
          &out_ePosType,
          &this->m_BasePosParams);
        if ( !this->m_p3DSound )
          *((_BYTE *)this + 371) &= 0xFCu;
      }
      break;
    case RTPC_Positioning_Divergence_Center_PCT:
      this->m_BasePosParams.m_fCenterPCT = in_RTPCValue;
      break;
    case RTPC_Position_PAN_X_2D:
      this->m_BasePosParams.m_fPAN_X_2D = in_RTPCValue;
      break;
    case RTPC_Position_PAN_Y_2D:
      this->m_BasePosParams.m_fPAN_Y_2D = in_RTPCValue;
      break;
    case RTPC_Position_PAN_X_3D:
      m_p3DSound = this->m_p3DSound;
      if ( m_p3DSound )
        m_p3DSound->m_Params.m_Position.X = CAkPBI::Scale3DUserDefRTPCValue(this, in_RTPCValue);
      break;
    case RTPC_Position_PAN_Y_3D:
      v5 = this->m_p3DSound;
      if ( v5 )
        v5->m_Params.m_Position.Z = CAkPBI::Scale3DUserDefRTPCValue(this, in_RTPCValue);
      break;
    case RTPC_MaxNumRTPC:
      this->m_BasePosParams.bIsPannerEnabled = in_RTPCValue > 0.0;
      break;
    default:
      v7 = this->m_p3DSound;
      if ( v7 )
      {
        v8 = in_ParameterID - 65;
        if ( v8 )
        {
          v9 = v8 - 1;
          if ( v9 )
          {
            v10 = v9 - 1;
            if ( v10 )
            {
              if ( v10 == 1 )
                v7->m_Params.m_ePathMode = (int)in_RTPCValue;
            }
            else
            {
              CAkGen3DParams::SetTransition(v7, (int)in_RTPCValue);
            }
          }
          else
          {
            *((_BYTE *)&v7->m_Params + 68) &= ~0x20u;
            if ( in_RTPCValue == 0.0 )
              *((_BYTE *)&v7->m_Params + 68) = *((_BYTE *)&v7->m_Params + 68);
            else
              *((_BYTE *)&v7->m_Params + 68) |= 0x20u;
          }
        }
        else
        {
          *((_BYTE *)&v7->m_Params + 68) &= ~8u;
          *((_BYTE *)&v7->m_Params + 68) |= 8 * (in_RTPCValue != 0.0);
        }
      }
      break;
  }
}

// File Line: 1109
// RVA: 0xA7FF00
void __fastcall CAkPBI::CalculateMutedEffectiveVolume(CAkPBI *this)
{
  MapStruct<AkMutedMapItem,float> *m_pItems; // rax
  float v2; // xmm0_4
  MapStruct<AkMutedMapItem,float> *i; // rdx
  float v4; // xmm0_4

  m_pItems = this->m_mapMutedNodes.m_pItems;
  v2 = *(float *)&FLOAT_1_0;
  for ( i = &m_pItems[this->m_mapMutedNodes.m_uLength]; m_pItems != i; ++m_pItems )
    v2 = v2 * m_pItems->item;
  v4 = (float)(v2 * this->m_fPlayStopFadeRatio) * this->m_fPauseResumeFadeRatio;
  if ( v4 <= 0.0 )
    v4 = 0.0;
  this->m_EffectiveParams.fFadeRatio = v4;
  this->m_EffectiveParams.Volume = this->m_Volume + this->m_Ranges.VolumeOffset;
}

// File Line: 1127
// RVA: 0xA7FEE0
void __fastcall CAkPBI::CalculateEffectiveLPF(CAkPBI *this)
{
  this->m_EffectiveParams.LPF = this->m_LPFAutomationOffset + this->m_LPF;
}

// File Line: 1132
// RVA: 0xA826F0
void __fastcall CAkPBI::RecalcNotification(CAkPBI *this)
{
  *((_BYTE *)this + 372) &= ~0x20u;
  *((_BYTE *)this + 374) &= ~0x40u;
}

// File Line: 1142
// RVA: 0xA82020
void __fastcall CAkPBI::NotifyBypass(CAkPBI *this, char in_bitsFXBypass, unsigned int in_uTargetMask)
{
  CAkVPLSrcCbxNodeBase *m_pCbx; // rcx
  char v5; // si

  m_pCbx = this->m_pCbx;
  v5 = in_uTargetMask;
  if ( m_pCbx && (in_uTargetMask & 0xFFFFFFEF) != 0 )
    ((void (__fastcall *)(CAkVPLSrcCbxNodeBase *))m_pCbx->vfptr->SetFxBypass)(m_pCbx);
  if ( (v5 & 0x10) != 0 )
  {
    *((_BYTE *)this + 375) &= ~1u;
    *((_BYTE *)this + 375) |= (in_bitsFXBypass & 0x10) != 0;
  }
}

// File Line: 1180
// RVA: 0xA82FE0
void __fastcall CAkPBI::TransUpdateValue(CAkPBI *this, __int64 in_eTarget, float in_fValue, bool in_bIsTerminated)
{
  __int64 v4; // r8

  if ( (((_DWORD)in_eTarget - 0x1000000) & 0xFEFFFFFF) != 0 )
  {
    if ( (((_DWORD)in_eTarget - 0x4000000) & 0xFBFFFFFF) == 0 )
    {
      if ( in_bIsTerminated )
      {
        *(_QWORD *)&this->m_UserParams.m_PlayingID = 0i64;
        if ( (_DWORD)in_eTarget == 0x4000000 )
        {
          LOBYTE(in_eTarget) = 1;
          (*(void (__fastcall **)(CAkLimiter **, __int64))&this[-1].m_pBusLimiter[1].m_sortedPBIList.m_uLength)(
            &this[-1].m_pBusLimiter,
            in_eTarget);
        }
      }
      this->m_Volume = in_fValue;
    }
  }
  else
  {
    if ( in_bIsTerminated )
    {
      this->m_UserParams.m_CustomParam.pExternalSrcs = 0i64;
      if ( (_DWORD)in_eTarget == 0x2000000 )
      {
        LOBYTE(v4) = 1;
        ((void (__fastcall *)(CAkLimiter **, _QWORD, __int64, _QWORD))this[-1].m_pBusLimiter->m_sortedPBIList.m_pItems)(
          &this[-1].m_pBusLimiter,
          0i64,
          v4,
          0i64);
      }
    }
    *(float *)&this->m_EffectiveParams.bGameDefinedAuxEnabled = in_fValue;
  }
  CAkPBI::CalculateMutedEffectiveVolume((CAkPBI *)((char *)this - 16));
}

// File Line: 1225
// RVA: 0xA82C40
__int64 __fastcall CAkPBI::SetParam(CAkPBI *this, __int16 in_paramID, float *in_pParam, unsigned int in_uParamSize)
{
  CAkGen3DParams *m_p3DSound; // r9
  float v5; // xmm0_4
  __int64 result; // rax

  m_p3DSound = this->m_p3DSound;
  if ( !m_p3DSound )
    return 1i64;
  v5 = *in_pParam;
  if ( in_paramID == 13 )
  {
    m_p3DSound->m_Params.m_fConeOutsideVolume = v5;
    return 1i64;
  }
  result = 1i64;
  if ( in_paramID == 14 )
    m_p3DSound->m_Params.m_fConeLoPass = v5;
  return result;
}

// File Line: 1302
// RVA: 0xA80B90
void __fastcall CAkPBI::DecrementPlayCount(CAkPBI *this)
{
  char v2; // al
  CAkLimiter *m_pAMLimiter; // rcx
  CAkLimiter *m_pBusLimiter; // rcx
  CAkRegisteredObj *m_pGameObj; // rax
  CAkSoundBase *m_pSound; // rcx
  int v7; // [rsp+20h] [rbp-38h] BYREF
  CAkRegisteredObj *v8; // [rsp+28h] [rbp-30h]
  __int64 v9; // [rsp+30h] [rbp-28h]
  __int64 v10; // [rsp+38h] [rbp-20h]
  int v11; // [rsp+40h] [rbp-18h]
  __int16 v12; // [rsp+44h] [rbp-14h]

  if ( (*((_BYTE *)this + 375) & 0x40) != 0 )
    CAkPBI::Devirtualize(this, 0);
  v2 = *((_BYTE *)this + 374);
  if ( (v2 & 0x10) == 0 )
  {
    m_pAMLimiter = this->m_pAMLimiter;
    *((_BYTE *)this + 374) = v2 | 0x10;
    if ( m_pAMLimiter )
    {
      CAkLimiter::Remove(m_pAMLimiter, this, AKVoiceLimiter_AM);
      this->m_pAMLimiter = 0i64;
    }
    m_pBusLimiter = this->m_pBusLimiter;
    if ( m_pBusLimiter )
    {
      CAkLimiter::Remove(m_pBusLimiter, this, AKVoiceLimiter_Bus);
      this->m_pBusLimiter = 0i64;
    }
    CAkLimiter::Remove(&CAkURenderer::m_GlobalLimiter, this, AKVoiceLimiter_Global);
    m_pGameObj = this->m_pGameObj;
    m_pSound = this->m_pSound;
    v7 = 0;
    v8 = m_pGameObj;
    v9 = 0i64;
    v10 = 0i64;
    v11 = 3;
    v12 = 256;
    ((void (__fastcall *)(CAkSoundBase *, int *))m_pSound->vfptr[8].Category)(m_pSound, &v7);
  }
}

// File Line: 1336
// RVA: 0xA81620
__int64 __fastcall CAkPBI::GetVirtualBehavior(CAkPBI *this, AkVirtualQueueBehavior *out_Behavior)
{
  char v2; // al
  __int64 result; // rax
  char v6; // cl
  char v7; // dl

  v2 = *((_BYTE *)this + 372);
  if ( (v2 & 0x10) != 0 )
  {
    *out_Behavior = *((unsigned __int8 *)this + 371) >> 5;
    return *((_BYTE *)this + 372) & 0xF;
  }
  else
  {
    *((_BYTE *)this + 372) = v2 | 0x10;
    result = CAkParameterNode::GetVirtualBehavior(this->m_pSound, out_Behavior);
    v6 = *(_BYTE *)out_Behavior;
    v7 = *((_BYTE *)this + 371);
    *((_BYTE *)this + 372) &= 0xF0u;
    *((_BYTE *)this + 371) = (32 * v6) | v7 & 0x1F;
    *((_BYTE *)this + 372) |= result & 0xF;
  }
  return result;
}

// File Line: 1431
// RVA: 0xA80C70
void __fastcall CAkPBI::Destroy(CAkPBI *this, AkCtxDestroyReason in_eReason)
{
  this->m_pCbx = 0i64;
  CAkURenderer::EnqueueContextNotif(this, CtxStateToDestroy, in_eReason, 0.0);
}

// File Line: 1440
// RVA: 0xA823D0
void __fastcall CAkPBI::Play(CAkPBI *this, float in_fDuration)
{
  *((_BYTE *)this + 370) &= 0x9Fu;
  *((_BYTE *)this + 370) |= 0x18u;
  CAkURenderer::EnqueueContextNotif(this, CtxStatePlay, CtxDestroyReasonFinished, in_fDuration);
}

// File Line: 1446
// RVA: 0xA82C80
void __fastcall CAkPBI::Stop(CAkPBI *this)
{
  *((_BYTE *)this + 370) &= 0x87u;
}

// File Line: 1454
// RVA: 0xA823B0
void __fastcall CAkPBI::Pause(CAkPBI *this)
{
  *((_BYTE *)this + 370) &= 0x8Fu;
  *((_BYTE *)this + 370) |= 8u;
  CAkURenderer::EnqueueContextNotif(this, CtxStatePause, CtxDestroyReasonFinished, 0.0);
}

// File Line: 1460
// RVA: 0xA82A20
void __fastcall CAkPBI::Resume(CAkPBI *this)
{
  *((_BYTE *)this + 370) &= 0x9Fu;
  *((_BYTE *)this + 370) |= 0x18u;
  CAkURenderer::EnqueueContextNotif(this, CtxStateResume, CtxDestroyReasonFinished, 0.0);
}

// File Line: 1466
// RVA: 0xA82010
void __fastcall CAkPBI::NotifAddedAsSA(CAkPBI *this)
{
  *((_BYTE *)this + 370) &= 0x9Fu;
  *((_BYTE *)this + 370) |= 0x18u;
}

// File Line: 1471
// RVA: 0xA82680
void __fastcall CAkPBI::ProcessContextNotif(
        CAkPBI *this,
        AkCtxState in_eState,
        __int64 in_eDestroyReason,
        float in_fEstimatedLength)
{
  int v4; // edx
  int v6; // edx
  __int64 v7; // rdx
  CAkTransportAwareVtbl *vfptr; // rax

  v4 = in_eState - 1;
  if ( v4 )
  {
    v6 = v4 - 1;
    if ( v6 )
    {
      v7 = (unsigned int)(v6 - 1);
      if ( (_DWORD)v7 )
      {
        if ( (_DWORD)v7 == 1 && (_DWORD)in_eDestroyReason == 1 )
        {
          *((_BYTE *)this + 373) &= ~1u;
          *((_BYTE *)this + 373) |= 8u;
        }
      }
      else
      {
        vfptr = this->CAkTransportAware::vfptr;
        *((_BYTE *)this + 373) |= 1u;
        ((void (__fastcall *)(CAkPBI *, __int64, __int64))vfptr[5].~CAkTransportAware)(this, v7, in_eDestroyReason);
        ((void (__fastcall *)(CAkPBI *))this->CAkTransportAware::vfptr[2]._Stop)(this);
      }
    }
  }
}

// File Line: 1501
// RVA: 0xA81610
__int64 __fastcall CAkPBI::GetSoundID(CAkPBI *this)
{
  return this->m_pSound->key;
}

// File Line: 1506
// RVA: 0xA815A0
CAkFeedbackBus *__fastcall CAkPBI::GetOutputBusPtr(CAkPBI *this)
{
  bool v1; // zf
  CAkSoundBase *m_pSound; // rcx

  v1 = *((_BYTE *)this + 374) >= 0;
  m_pSound = this->m_pSound;
  if ( v1 )
    return (CAkFeedbackBus *)((__int64 (__fastcall *)(CAkSoundBase *))m_pSound->vfptr[7].Category)(m_pSound);
  else
    return CAkParameterNodeBase::GetFeedbackParentBusOrDefault(m_pSound);
}

// File Line: 1538
// RVA: 0xA82700
void __fastcall CAkPBI::RefreshParameters(CAkPBI *this)
{
  AkSoundParamsEx *p_m_EffectiveParams; // rdi
  unsigned int *aAuxSend; // rax
  __int64 v4; // rcx
  CAkVPLSrcCbxNodeBase *m_pCbx; // rcx
  char v6; // al
  float SourceVolumeOffset; // xmm0_4
  bool v8; // zf
  unsigned __int8 v9; // dl
  CAkSoundBase *m_pSound; // rcx
  __int64 v11; // r8
  CAkRegisteredObj *m_pGameObj; // rax
  float Volume; // eax
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  AkFeedbackParams *m_pFeedbackInfo; // rax
  float priority; // xmm1_4
  bool v19; // [rsp+28h] [rbp-20h]
  char v20; // [rsp+38h] [rbp-10h]
  PriorityInfo result; // [rsp+50h] [rbp+8h] BYREF

  p_m_EffectiveParams = &this->m_EffectiveParams;
  this->m_EffectiveParams.Volume = 0.0;
  *(_QWORD *)&this->m_EffectiveParams.fFadeRatio = 1065353216i64;
  *(_QWORD *)&this->m_EffectiveParams.LPF = 0i64;
  *((_BYTE *)&this->m_EffectiveParams.normalization + 4) &= 0xFCu;
  this->m_EffectiveParams.normalization.fMakeUpGain = 0.0;
  *((_BYTE *)&this->m_EffectiveParams.hdr + 4) &= 0xFCu;
  this->m_EffectiveParams.hdr.fActiveRange = 0.0;
  aAuxSend = this->m_EffectiveParams.aAuxSend;
  v4 = 4i64;
  *(_QWORD *)&p_m_EffectiveParams->fOutputBusVolume = 0i64;
  do
  {
    *(aAuxSend - 4) = 0;
    *aAuxSend++ = 0;
    --v4;
  }
  while ( v4 );
  p_m_EffectiveParams->fGameAuxSendVolume = 0.0;
  *(_WORD *)&p_m_EffectiveParams->bGameDefinedAuxEnabled = 0;
  p_m_EffectiveParams->bUserDefinedServiced = 0;
  CAkPBI::RemoveAllVolatileMuteItems(this);
  CAkParameterNode::UpdateBaseParams(this->m_pSound, this->m_pGameObj, &this->m_BasePosParams, this->m_p3DSound);
  m_pCbx = this->m_pCbx;
  if ( m_pCbx )
    m_pCbx->vfptr->RefreshBypassFx(m_pCbx);
  v6 = ((__int64 (__fastcall *)(CAkSoundBase *, CAkRegisteredObj *))this->m_pSound->vfptr[14].Release)(
         this->m_pSound,
         this->m_pGameObj);
  *((_BYTE *)this + 375) &= ~1u;
  *((_BYTE *)this + 375) |= v6 & 1;
  if ( *((char *)this + 374) < 0 )
  {
    SourceVolumeOffset = CAkFeedbackNode::GetSourceVolumeOffset((CAkFeedbackNode *)this->m_pSound, this->m_pSource);
    v8 = (*((_BYTE *)this + 374) & 0x40) == 0;
    p_m_EffectiveParams->Volume = SourceVolumeOffset;
    if ( v8 )
      CAkPBI::ValidateFeedbackParameters(this);
  }
  v9 = *((_BYTE *)this + 372);
  m_pSound = this->m_pSound;
  v11 = 0xFFFFFFFFi64;
  v20 = 1;
  if ( (*((_BYTE *)this + 376) & 1) == 0 )
    v11 = 4294967279i64;
  m_pGameObj = this->m_pGameObj;
  this->m_Prev2DParams.prev2DParams.m_fPAN_X_2D = 101.0;
  v19 = v9 >> 7 == 0;
  ((void (__fastcall *)(CAkSoundBase *, AkSoundParamsEx *, __int64, CAkKeyArray<AkMutedMapItem,float,2> *, CAkRegisteredObj *, bool, AkPBIModValues *, char))m_pSound->vfptr[10].Release)(
    m_pSound,
    p_m_EffectiveParams,
    v11,
    &this->m_mapMutedNodes,
    m_pGameObj,
    v19,
    &this->m_Ranges,
    v20);
  Volume = p_m_EffectiveParams->Volume;
  v14 = this->m_Ranges.LPFOffset + this->m_EffectiveParams.LPF;
  v15 = this->m_Ranges.PitchOffset + this->m_EffectiveParams.Pitch;
  *((_BYTE *)this + 372) |= 0x80u;
  this->m_Volume = Volume;
  this->m_LPF = v14;
  v16 = v14 + this->m_LPFAutomationOffset;
  this->m_EffectiveParams.Pitch = v15;
  this->m_EffectiveParams.LPF = v16;
  CAkPBI::CalculateMutedEffectiveVolume(this);
  if ( *((char *)this + 374) < 0 )
  {
    m_pFeedbackInfo = this->m_pFeedbackInfo;
    if ( m_pFeedbackInfo )
      this->m_EffectiveParams.Pitch = m_pFeedbackInfo->m_MotionBusPitch + this->m_EffectiveParams.Pitch;
  }
  CAkParameterNodeBase::GetPriority(this->m_pSound, &result, this->m_pGameObj);
  priority = result.priority;
  if ( result.priority != this->m_PriorityInfoCurrent.priorityInfo.priority
    || result.distanceOffset != this->m_PriorityInfoCurrent.priorityInfo.distanceOffset )
  {
    this->m_PriorityInfoCurrent.priorityInfo = result;
    CAkPBI::UpdatePriority(this, priority);
  }
  *((_BYTE *)this + 372) |= 0x20u;
}

// File Line: 1609
// RVA: 0xA83110
void __fastcall CAkPBI::UpdatePriority(CAkPBI *this, float in_NewPriority)
{
  CAkLimiter *m_pAMLimiter; // rcx
  CAkLimiter *m_pBusLimiter; // rcx

  if ( in_NewPriority != this->m_PriorityInfoCurrent.currentPriority.priority )
  {
    m_pAMLimiter = this->m_pAMLimiter;
    if ( m_pAMLimiter )
      CAkLimiter::Update(m_pAMLimiter, in_NewPriority, this);
    m_pBusLimiter = this->m_pBusLimiter;
    if ( m_pBusLimiter )
      CAkLimiter::Update(m_pBusLimiter, in_NewPriority, this);
    CAkLimiter::Update(&CAkURenderer::m_GlobalLimiter, in_NewPriority, this);
    this->m_PriorityInfoCurrent.currentPriority.priority = in_NewPriority;
  }
}

// File Line: 1637
// RVA: 0xA7FF70
void __fastcall CAkPBI::ComputePriorityOffset(CAkPBI *this, float in_fMinDistance, Gen3DParams *in_p3DParams)
{
  float priority; // xmm6_4
  float v4; // xmm7_4
  float distanceOffset; // xmm9_4
  CAkAttenuation *m_pAttenuation; // rcx
  unsigned __int8 v9; // al
  __int64 v10; // rdx
  float v11; // xmm0_4
  CAkLimiter *m_pAMLimiter; // rcx
  CAkLimiter *m_pBusLimiter; // rcx

  priority = this->m_PriorityInfoCurrent.priorityInfo.priority;
  v4 = 0.0;
  distanceOffset = this->m_PriorityInfoCurrent.priorityInfo.distanceOffset;
  if ( distanceOffset != 0.0 )
  {
    if ( !in_p3DParams->m_pAttenuation )
      in_p3DParams->m_pAttenuation = (CAkAttenuation *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                                         (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxAttenuations,
                                                         in_p3DParams->m_uAttenuationID);
    m_pAttenuation = in_p3DParams->m_pAttenuation;
    if ( m_pAttenuation )
    {
      v9 = m_pAttenuation->m_curveToUse[0];
      if ( v9 != 0xFF )
      {
        v10 = (__int64)&m_pAttenuation->m_curves[v9];
        if ( *(_QWORD *)v10 )
        {
          if ( v10 )
          {
            v11 = *(float *)(*(_QWORD *)v10 + 12i64 * (unsigned int)(*(_DWORD *)(v10 + 8) - 1));
            if ( in_fMinDistance >= v11 || v11 <= 0.0 )
              priority = priority + distanceOffset;
            else
              priority = priority + (float)((float)(in_fMinDistance / v11) * distanceOffset);
          }
        }
      }
    }
    if ( priority < 0.0 || (v4 = priority, priority <= 100.0) )
      priority = v4;
    else
      priority = FLOAT_100_0;
  }
  if ( priority != this->m_PriorityInfoCurrent.currentPriority.priority )
  {
    m_pAMLimiter = this->m_pAMLimiter;
    if ( m_pAMLimiter )
      CAkLimiter::Update(m_pAMLimiter, priority, this);
    m_pBusLimiter = this->m_pBusLimiter;
    if ( m_pBusLimiter )
      CAkLimiter::Update(m_pBusLimiter, priority, this);
    CAkLimiter::Update(&CAkURenderer::m_GlobalLimiter, priority, this);
    this->m_PriorityInfoCurrent.currentPriority.priority = priority;
  }
}

// File Line: 1672
// RVA: 0xA81D50
bool __fastcall CAkPBI::IsMultiPositionTypeMultiSources(CAkPBI *this)
{
  char v1; // dl
  char v2; // cl

  v1 = *((_BYTE *)this + 371);
  if ( (v1 & 3) != 1 || (v1 & 0xC) != 4 )
    return 0;
  if ( (*((_BYTE *)&this->m_p3DSound->m_Params + 68) & 8) != 0 )
    v2 = *((_BYTE *)&this->m_pGameObj->m_PosKeep.AkSoundPositionRef + 11);
  else
    v2 = *((_BYTE *)&this->m_cachedGameObjectPosition.AkSoundPositionRef + 11);
  return (v2 & 7) == 1;
}

// File Line: 1688
// RVA: 0xA81480
__int64 __fastcall CAkPBI::GetGameObjectPosition(CAkPBI *this, unsigned int in_uIndex, AkSoundPosition *out_position)
{
  CAkRegisteredObj *m_pGameObj; // r9
  unsigned __int16 m_uNumPos; // ax
  __int64 v6; // r8
  __int64 v7; // rcx
  AkSoundPosition *m_aPos; // rdx
  __int64 result; // rax
  float *p_X; // r8

  m_pGameObj = this->m_pGameObj;
  m_uNumPos = 1;
  v6 = in_uIndex;
  if ( (*((_BYTE *)&m_pGameObj->m_PosKeep.AkSoundPositionRef + 11) & 7) != 0 )
    m_uNumPos = m_pGameObj->m_PosKeep.m_uNumPos;
  if ( in_uIndex >= m_uNumPos )
    return 2i64;
  v7 = in_uIndex;
  m_aPos = &g_DefaultSoundPosition;
  if ( m_pGameObj->m_PosKeep.m_aPos )
    m_aPos = m_pGameObj->m_PosKeep.m_aPos;
  result = 1i64;
  p_X = &m_aPos[v6].Position.X;
  out_position->Position.X = m_aPos[v7].Position.X;
  out_position->Position.Y = p_X[1];
  out_position->Position.Z = p_X[2];
  out_position->Orientation.X = p_X[3];
  out_position->Orientation.Y = p_X[4];
  out_position->Orientation.Z = p_X[5];
  return result;
}

// File Line: 1701
// RVA: 0xA81500
__int64 __fastcall CAkPBI::GetListenerData(CAkPBI *this, char in_uListenerMask, AkListener *out_listener)
{
  unsigned int v3; // edx
  unsigned __int8 i; // al

  v3 = (unsigned __int8)(this->m_pGameObj->m_PosKeep.m_uListenerMask & in_uListenerMask);
  if ( !v3 )
    return 2i64;
  for ( i = 0; (v3 & 1) == 0; ++i )
    v3 >>= 1;
  *out_listener = *(AkListener *)&(&CAkListener::m_listeners.vfptr)[18 * i];
  return 1i64;
}

// File Line: 1728
// RVA: 0xA800D0
float __fastcall ComputeRay(
        AkListenerData *in_listenerData,
        AkSoundPosition *in_emitterPosition,
        float in_fGameObjectScalingFactor,
        bool in_bComputePositionAngles,
        bool in_bComputeEmitterDirectionAngle,
        AkRayVolumeData *out_ray)
{
  float v8; // xmm1_4
  float Z; // xmm0_4
  float v11; // xmm9_4
  float v12; // xmm10_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm6_4
  float v16; // xmm8_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  AkVector Vector1; // [rsp+20h] [rbp-68h] BYREF

  v8 = in_emitterPosition->Position.Y - in_listenerData->position.Position.Y;
  Vector1.X = in_emitterPosition->Position.X - in_listenerData->position.Position.X;
  Z = in_emitterPosition->Position.Z;
  Vector1.Y = v8;
  Vector1.Z = Z - in_listenerData->position.Position.Z;
  v11 = AkMath::Magnitude(&Vector1);
  v12 = v11 / (float)(in_fGameObjectScalingFactor * in_listenerData->fScalingFactor);
  out_ray->r = v12;
  if ( in_bComputePositionAngles )
  {
    v13 = (float)((float)(Vector1.Y * in_listenerData->Matrix[0][1]) + (float)(Vector1.X * in_listenerData->Matrix[0][0]))
        + (float)(Vector1.Z * in_listenerData->Matrix[0][2]);
    v14 = (float)((float)(Vector1.Y * in_listenerData->Matrix[2][1]) + (float)(Vector1.X * in_listenerData->Matrix[2][0]))
        + (float)(Vector1.Z * in_listenerData->Matrix[2][2]);
    v15 = (float)((float)(Vector1.Y * in_listenerData->Matrix[1][1]) + (float)(Vector1.X * in_listenerData->Matrix[1][0]))
        + (float)(Vector1.Z * in_listenerData->Matrix[1][2]);
    if ( v14 == 0.0 )
    {
      if ( v13 == 0.0 )
      {
        v16 = 0.0;
        v17 = 0.0;
LABEL_10:
        *((_BYTE *)&out_ray->AkEmitterListenerPairEx + 16) |= 2u;
        out_ray->theta = v16;
        out_ray->phi = v17;
        goto LABEL_11;
      }
      if ( v13 <= 0.0 )
        v16 = FLOAT_N1_5707964;
      else
        v16 = FLOAT_1_5707964;
    }
    else
    {
      v16 = atan2f(v13, v14);
    }
    v17 = asinf(v15 / v11);
    goto LABEL_10;
  }
LABEL_11:
  if ( in_bComputeEmitterDirectionAngle )
  {
    if ( v11 <= 0.0
      || (LODWORD(v18) = COERCE_UNSIGNED_INT(AkMath::DotProduct(&Vector1, &in_emitterPosition->Orientation) / v11) ^ _xmm[0],
          v18 >= 1.0) )
    {
      v18 = *(float *)&FLOAT_1_0;
    }
    else if ( v18 <= -1.0 )
    {
      v18 = FLOAT_N1_0;
    }
    v19 = acosf(v18);
    *((_BYTE *)&out_ray->AkEmitterListenerPairEx + 16) |= 1u;
    out_ray->fEmitterAngle = v19;
  }
  return v12;
}

// File Line: 1787
// RVA: 0xA81210
__int64 __fastcall CAkPBI::GetEmitterListenerPair(
        CAkPBI *this,
        unsigned int in_uIndex,
        AkEmitterListenerPair *out_emitterListenerPair)
{
  CAkRegisteredObj *m_pGameObj; // rbx
  bool v4; // si
  char v5; // r10
  bool in_bComputeEmitterDirectionAngle; // r14
  AkEmitterListenerPairEx *m_pItems; // r11
  int v11; // r8d
  AkEmitterListenerPairEx *v12; // rax
  float r; // xmm0_4
  float theta; // xmm1_4
  float phi; // xmm2_4
  float fEmitterAngle; // xmm3_4
  __int64 result; // rax
  int v18; // eax
  unsigned __int16 m_uNumPos; // cx
  unsigned int m_uListenerMask; // edx
  __int64 v21; // r10
  __int64 v22; // r8
  AkSoundPosition *m_aPos; // rdx
  float v24; // xmm1_4
  CAkRegisteredObj *v25; // rcx
  float v26; // xmm0_4
  float v27; // xmm1_4
  AkRayVolumeData out_ray; // [rsp+30h] [rbp-30h] BYREF

  m_pGameObj = this->m_pGameObj;
  v4 = 1;
  v5 = *((_BYTE *)&out_ray.AkEmitterListenerPairEx + 16) & 0xFC;
  *(_QWORD *)&out_ray.phi = 0i64;
  out_ray.AkPolarCoord = 0i64;
  out_ray.m_uListenerMask = 0;
  out_ray.fDryMixGain = 1.0;
  out_ray.fGameDefAuxMixGain = 1.0;
  *((_BYTE *)&out_ray.AkEmitterListenerPairEx + 16) &= 0xFCu;
  out_ray.fUserDefAuxMixGain = 1.0;
  out_ray.fConeInterp = 1.0;
  in_bComputeEmitterDirectionAngle = 1;
  if ( (*((_DWORD *)m_pGameObj + 30) & 0x40000000) == 0 )
  {
    m_pItems = m_pGameObj->m_arCachedEmitListPairs.m_pItems;
    v11 = 0;
    v12 = m_pItems;
    if ( in_uIndex )
    {
      do
      {
        if ( v12 == &m_pItems[m_pGameObj->m_arCachedEmitListPairs.m_uLength] )
          break;
        ++v11;
        ++v12;
      }
      while ( v11 != in_uIndex );
    }
    if ( v12 != &m_pItems[m_pGameObj->m_arCachedEmitListPairs.m_uLength] )
    {
      r = v12->r;
      out_ray.r = v12->r;
      theta = v12->theta;
      out_ray.theta = theta;
      phi = v12->phi;
      out_ray.phi = phi;
      fEmitterAngle = v12->fEmitterAngle;
      out_ray.fEmitterAngle = fEmitterAngle;
      *((_BYTE *)&out_ray.AkEmitterListenerPairEx + 16) = (*((_BYTE *)v12 + 16) ^ v5) & 1 ^ v5;
      *((_BYTE *)&out_ray.AkEmitterListenerPairEx + 16) ^= (*((_BYTE *)v12 + 16) ^ *((_BYTE *)&out_ray.AkEmitterListenerPairEx
                                                                                   + 16)) & 2;
      in_bComputeEmitterDirectionAngle = (*((_BYTE *)&out_ray.AkEmitterListenerPairEx + 16) & 1) == 0;
      out_ray.m_uListenerMask = v12->m_uListenerMask;
      v4 = (*((_BYTE *)&out_ray.AkEmitterListenerPairEx + 16) & 2) == 0;
      if ( (*((_BYTE *)&out_ray.AkEmitterListenerPairEx + 16) & 2) != 0
        && (*((_BYTE *)&out_ray.AkEmitterListenerPairEx + 16) & 1) != 0 )
      {
        out_emitterListenerPair->r = r;
        out_emitterListenerPair->theta = theta;
        out_emitterListenerPair->phi = phi;
        result = 1i64;
        out_emitterListenerPair->fEmitterAngle = fEmitterAngle;
        return result;
      }
    }
  }
  v18 = 0;
  m_uNumPos = 1;
  if ( (*((_BYTE *)&m_pGameObj->m_PosKeep.AkSoundPositionRef + 11) & 7) != 0 )
    m_uNumPos = m_pGameObj->m_PosKeep.m_uNumPos;
  m_uListenerMask = (unsigned __int8)m_pGameObj->m_PosKeep.m_uListenerMask;
  v21 = 0i64;
  if ( !m_pGameObj->m_PosKeep.m_uListenerMask )
    return 2i64;
  while ( (m_uListenerMask & 1) == 0 )
  {
    m_uListenerMask >>= 1;
    v21 = (unsigned int)(v21 + 1);
LABEL_17:
    if ( !m_uListenerMask )
      return 2i64;
  }
  v22 = 0i64;
  if ( !m_uNumPos )
    goto LABEL_17;
  while ( in_uIndex != v18 )
  {
    v22 = (unsigned int)(v22 + 1);
    ++v18;
    if ( (unsigned int)v22 >= m_uNumPos )
      goto LABEL_17;
  }
  m_aPos = &g_DefaultSoundPosition;
  out_ray.m_uListenerMask = 1 << v21;
  if ( m_pGameObj->m_PosKeep.m_aPos )
    m_aPos = m_pGameObj->m_PosKeep.m_aPos;
  ComputeRay(
    (AkListenerData *)&CAkListener::m_listeners + v21,
    &m_aPos[v22],
    m_pGameObj->m_fScalingFactor,
    v4,
    in_bComputeEmitterDirectionAngle,
    &out_ray);
  v24 = out_ray.theta;
  v25 = this->m_pGameObj;
  out_emitterListenerPair->r = out_ray.r;
  v26 = out_ray.phi;
  out_emitterListenerPair->theta = v24;
  v27 = out_ray.fEmitterAngle;
  out_emitterListenerPair->phi = v26;
  out_emitterListenerPair->fEmitterAngle = v27;
  CAkRegisteredObj::CacheEmitListenPair(v25, &out_ray);
  return 1i64;
}

// File Line: 1879
// RVA: 0xA802D0
__int64 __fastcall CAkPBI::ComputeVolumeData3D(
        CAkPBI *this,
        AkPositionSourceType in_eType,
        AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *out_arVolumeData)
{
  unsigned int v3; // r15d
  CAkGen3DParams *m_p3DSound; // r14
  CAkAttenuation *m_pAttenuation; // rax
  bool v9; // r12
  CAkRegisteredObj *v10; // rdx
  CAkRegisteredObj *v11; // rdi
  float r; // xmm6_4
  char v13; // al
  AkEmitterListenerPairEx *m_pItems; // rbx
  char v15; // cl
  AkRayVolumeData *v16; // rax
  AkPositionKeeper *p_m_PosKeep; // rax
  unsigned __int16 m_uNumPos; // cx
  unsigned int v19; // r12d
  unsigned int v20; // r8d
  int v21; // edx
  unsigned int i; // ecx
  unsigned int m_ulReserved; // eax
  unsigned int v24; // edx
  unsigned int v26; // ecx
  AkListenerData *v27; // rdi
  __int64 v28; // rbx
  __int64 v29; // rsi
  AkRayVolumeData *out_ray; // r8
  bool v31; // r9
  AkSoundPosition *v32; // rdx
  float v33; // xmm0_4
  CAkPath *pPBPath; // rcx
  bool v35; // bl
  CAkPath *v36; // rcx
  AkPathState *PathState; // rax
  CAkRegisteredObj *m_pGameObj; // rax
  unsigned int m_uListenerMask; // edi
  float v40; // xmm11_4
  float v41; // xmm10_4
  AkRayVolumeData *v42; // rax
  AkRayVolumeData *v43; // rbx
  float v44; // xmm9_4
  char v45; // al
  char v46; // dl
  CAkPath *v47; // rax
  float *m_pNoFollowOrientationRotation; // rax
  float v49; // xmm2_4
  float v50; // xmm13_4
  float v51; // xmm4_4
  float v52; // xmm14_4
  float v53; // xmm11_4
  float v54; // xmm7_4
  float v55; // xmm12_4
  float v56; // xmm8_4
  float v57; // xmm6_4
  float v58; // xmm10_4
  float v59; // xmm0_4
  float v60; // xmm5_4
  float v61; // xmm9_4
  float v62; // xmm2_4
  float v63; // xmm3_4
  float v64; // xmm9_4
  float v65; // xmm5_4
  float v66; // xmm0_4
  float v67; // xmm15_4
  float v68; // xmm2_4
  float v69; // xmm9_4
  float v70; // xmm15_4
  float v71; // xmm13_4
  float v72; // xmm4_4
  float v73; // xmm0_4
  float v74; // xmm1_4
  float v75; // xmm3_4
  float v76; // xmm5_4
  float v77; // xmm2_4
  float v78; // xmm4_4
  float v79; // xmm1_4
  float v80; // xmm6_4
  float Y; // xmm6_4
  float X; // xmm8_4
  float Z; // xmm13_4
  float v84; // xmm8_4
  float v85; // xmm0_4
  float v86; // xmm0_4
  float v87; // xmm0_4
  char v88; // [rsp+30h] [rbp-118h]
  float v89; // [rsp+30h] [rbp-118h]
  AkSoundPosition **p_m_aPos; // [rsp+38h] [rbp-110h]
  float v91; // [rsp+38h] [rbp-110h]
  AkVector Vector1; // [rsp+40h] [rbp-108h] BYREF
  AkVector Vector2; // [rsp+50h] [rbp-F8h] BYREF
  unsigned int j; // [rsp+150h] [rbp+8h]
  float v95; // [rsp+150h] [rbp+8h]
  bool in_bComputeEmitterDirectionAngle; // [rsp+158h] [rbp+10h]
  int v97; // [rsp+158h] [rbp+10h]
  unsigned int v98; // [rsp+160h] [rbp+18h]
  float v99; // [rsp+160h] [rbp+18h]
  unsigned int v100; // [rsp+168h] [rbp+20h]
  float v101; // [rsp+168h] [rbp+20h]

  v3 = 0;
  out_arVolumeData->m_uLength = 0;
  m_p3DSound = this->m_p3DSound;
  if ( !m_p3DSound->m_Params.m_pAttenuation )
    m_p3DSound->m_Params.m_pAttenuation = (CAkAttenuation *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                                              (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxAttenuations,
                                                              m_p3DSound->m_Params.m_uAttenuationID);
  m_pAttenuation = m_p3DSound->m_Params.m_pAttenuation;
  v9 = m_pAttenuation && (*((_BYTE *)m_pAttenuation + 125) & 1) != 0;
  in_bComputeEmitterDirectionAngle = v9;
  if ( in_eType != AkGameDef )
  {
    pPBPath = this->m_PathInfo.pPBPath;
    if ( pPBPath )
    {
      v35 = (*((_BYTE *)&m_p3DSound->m_Params + 68) & 0x20) != 0;
      CAkPath::SetIsLooping(pPBPath, v35);
      if ( v35 )
      {
        v36 = this->m_PathInfo.pPBPath;
        if ( (v36->m_PathMode & 2) != 0 && CAkPath::IsIdle(v36) )
        {
          PathState = CAkParameterNode::GetPathState(this->m_pSound);
          CAkPathManager::Start(g_pPathManager, this->m_PathInfo.pPBPath, PathState);
        }
      }
    }
    m_pGameObj = this->m_pGameObj;
    m_uListenerMask = (unsigned __int8)m_pGameObj->m_PosKeep.m_uListenerMask;
    if ( !m_pGameObj->m_PosKeep.m_uListenerMask )
      return out_arVolumeData->m_uLength;
    v40 = *(float *)&FLOAT_1_0;
    v41 = FLOAT_N1_0;
    v97 = 0;
    while ( (m_uListenerMask & 1) == 0 )
    {
      m_uListenerMask >>= 1;
      ++v3;
LABEL_89:
      if ( !m_uListenerMask )
        return out_arVolumeData->m_uLength;
    }
    v42 = AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(out_arVolumeData);
    v43 = v42;
    if ( !v42 )
      return out_arVolumeData->m_uLength;
    v42->m_uListenerMask = 1 << v3;
    v44 = AkMath::Magnitude(&m_p3DSound->m_Params.m_Position);
    v91 = v44;
    v43->r = v44 / (float)(this->m_pGameObj->m_fScalingFactor * *((float *)&CAkListener::m_listeners + 36 * v3 + 9));
    v45 = *((_BYTE *)&m_p3DSound->m_Params + 68);
    if ( (v45 & 1) != 0 && *((_BYTE *)&CAkListener::m_listeners + 144 * v3 + 40) )
    {
      v46 = 1;
    }
    else
    {
      v46 = 0;
      if ( !v9 )
      {
LABEL_88:
        ++v3;
        m_uListenerMask >>= 1;
        goto LABEL_89;
      }
    }
    if ( (v45 & 0x10) != 0 || (v47 = this->m_PathInfo.pPBPath) == 0i64 )
    {
      X = m_p3DSound->m_Params.m_Position.X;
      Y = m_p3DSound->m_Params.m_Position.Y;
      Z = m_p3DSound->m_Params.m_Position.Z;
    }
    else
    {
      m_pNoFollowOrientationRotation = v47->m_pNoFollowOrientationRotation;
      v49 = *((float *)&CAkListener::m_listeners + 36 * v3 + 20);
      v50 = m_pNoFollowOrientationRotation[v97 + 3];
      v51 = m_pNoFollowOrientationRotation[v97];
      v52 = m_pNoFollowOrientationRotation[v97 + 6];
      v53 = m_pNoFollowOrientationRotation[v97 + 4];
      v54 = m_pNoFollowOrientationRotation[v97 + 1];
      v55 = m_pNoFollowOrientationRotation[v97 + 7];
      v56 = m_pNoFollowOrientationRotation[v97 + 5];
      v57 = m_pNoFollowOrientationRotation[v97 + 2];
      v58 = m_pNoFollowOrientationRotation[v97 + 8];
      v59 = *((float *)&CAkListener::m_listeners + 36 * v3 + 21);
      v95 = (float)((float)(v49 * v51) + (float)(v59 * v50))
          + (float)(*((float *)&CAkListener::m_listeners + 36 * v3 + 22) * v52);
      v60 = (float)(v49 * v54) + (float)(v59 * v53);
      v61 = (float)(v59 * v56) + (float)(v49 * v57);
      v62 = *((float *)&CAkListener::m_listeners + 36 * v3 + 24);
      v63 = *((float *)&CAkListener::m_listeners + 36 * v3 + 25);
      v99 = v60 + (float)(*((float *)&CAkListener::m_listeners + 36 * v3 + 22) * v55);
      v101 = v61 + (float)(*((float *)&CAkListener::m_listeners + 36 * v3 + 22) * v58);
      v64 = *((float *)&CAkListener::m_listeners + 36 * v3 + 23);
      v65 = (float)(v64 * v51) + (float)(v62 * v50);
      v66 = v62 * v53;
      v67 = (float)(v64 * v57) + (float)(v62 * v56);
      v68 = *((float *)&CAkListener::m_listeners + 36 * v3 + 27);
      v69 = (float)((float)(v64 * v54) + v66) + (float)(v63 * v55);
      v89 = v65 + (float)(v63 * v52);
      v70 = v67 + (float)(v63 * v58);
      v71 = (float)((float)(*((float *)&CAkListener::m_listeners + 36 * v3 + 26) * v51) + (float)(v68 * v50))
          + (float)(*((float *)&CAkListener::m_listeners + 36 * v3 + 28) * v52);
      v72 = (float)(*((float *)&CAkListener::m_listeners + 36 * v3 + 26) * v54) + (float)(v68 * v53);
      v73 = m_p3DSound->m_Params.m_Position.X;
      v40 = *(float *)&FLOAT_1_0;
      v74 = *((float *)&CAkListener::m_listeners + 36 * v3 + 28);
      v75 = v74 * v58;
      v97 += 9;
      v41 = FLOAT_N1_0;
      v76 = (float)(*((float *)&CAkListener::m_listeners + 36 * v3 + 26) * v57) + (float)(v68 * v56);
      v77 = m_p3DSound->m_Params.m_Position.Z;
      v78 = v72 + (float)(v74 * v55);
      v79 = m_p3DSound->m_Params.m_Position.Y;
      v80 = (float)(v89 * v73) + (float)(v69 * v79);
      v44 = v91;
      Y = v80 + (float)(v70 * v77);
      X = (float)((float)(v95 * v73) + (float)(v99 * v79)) + (float)(v101 * v77);
      Z = (float)((float)(v71 * v73) + (float)(v78 * v79)) + (float)((float)(v76 + v75) * v77);
    }
    Vector1.Z = Z;
    Vector1.Y = Y;
    Vector1.X = X;
    if ( !v46 )
    {
LABEL_81:
      if ( v9 )
      {
        if ( v44 <= 0.0
          || (*(_QWORD *)&Vector2.X = 0i64,
              Vector2.Z = 1.0,
              v86 = AkMath::DotProduct(&Vector1, &Vector2) / v44,
              v86 >= v40) )
        {
          v86 = v40;
        }
        else if ( v86 <= v41 )
        {
          v86 = v41;
        }
        v87 = acosf(v86);
        *((_BYTE *)&v43->AkEmitterListenerPairEx + 16) |= 1u;
        v43->fEmitterAngle = v87;
      }
      goto LABEL_88;
    }
    if ( Z == 0.0 )
    {
      if ( X == 0.0 )
      {
        v84 = 0.0;
        v85 = 0.0;
LABEL_80:
        *((_BYTE *)&v43->AkEmitterListenerPairEx + 16) |= 2u;
        v43->theta = v84;
        v43->phi = v85;
        goto LABEL_81;
      }
      if ( X <= 0.0 )
        v84 = FLOAT_N1_5707964;
      else
        v84 = FLOAT_1_5707964;
    }
    else
    {
      v84 = atan2f(X, Z);
    }
    v85 = asinf(Y / v44);
    goto LABEL_80;
  }
  if ( (*((_BYTE *)&m_p3DSound->m_Params + 68) & 8) == 0 && (*((_BYTE *)this + 372) & 0x40) == 0 )
  {
    v10 = this->m_pGameObj;
    this->m_cachedGameObjectPosition.m_uListenerMask = v10->m_PosKeep.m_uListenerMask;
    *((_BYTE *)&this->m_cachedGameObjectPosition.AkSoundPositionRef + 11) ^= (*((_BYTE *)&this->m_cachedGameObjectPosition.AkSoundPositionRef
                                                                              + 11) ^ *((_BYTE *)&v10->m_PosKeep.AkSoundPositionRef
                                                                                      + 11)) & 7;
    if ( (unsigned int)AkPositionKeeper::SetPosition(
                         &this->m_cachedGameObjectPosition,
                         v10->m_PosKeep.m_aPos,
                         v10->m_PosKeep.m_uNumPos) == 1 )
      *((_BYTE *)this + 372) |= 0x40u;
  }
  v11 = this->m_pGameObj;
  r = FLOAT_1_0e10;
  if ( (*((_DWORD *)v11 + 30) & 0x40000000) != 0
    || (v13 = *((_BYTE *)&m_p3DSound->m_Params + 68), (v13 & 8) == 0)
    || (m_pItems = v11->m_arCachedEmitListPairs.m_pItems, v15 = *((_BYTE *)m_pItems + 16), (v15 & 2) == 0)
    && (v13 & 1) != 0
    || (v15 & 1) == 0 && v9 )
  {
    p_m_PosKeep = &v11->m_PosKeep;
    if ( (*((_BYTE *)&m_p3DSound->m_Params + 68) & 8) == 0 )
      p_m_PosKeep = &this->m_cachedGameObjectPosition;
    p_m_aPos = &p_m_PosKeep->m_aPos;
    m_uNumPos = 1;
    if ( (*((_BYTE *)&p_m_PosKeep->AkSoundPositionRef + 11) & 7) != 0 )
      m_uNumPos = p_m_PosKeep->m_uNumPos;
    v19 = (unsigned __int8)p_m_PosKeep->m_uListenerMask;
    v20 = m_uNumPos;
    v21 = 0;
    v100 = m_uNumPos;
    v98 = v19;
    for ( i = v19; i; i &= i - 1 )
      ++v21;
    m_ulReserved = out_arVolumeData->m_ulReserved;
    v24 = v20 * v21;
    if ( v24 > m_ulReserved )
    {
      if ( !AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(
              out_arVolumeData,
              v24 - m_ulReserved) )
        return 0i64;
      v20 = v100;
    }
    v26 = 0;
    for ( j = 0; v19; j = v26 )
    {
      if ( (v19 & 1) != 0 )
      {
        v88 = 1 << v26;
        v27 = (AkListenerData *)(&CAkListener::m_listeners + 9 * v26);
        if ( v20 )
        {
          v28 = 0i64;
          v29 = v20;
          do
          {
            out_ray = AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(out_arVolumeData);
            out_ray->m_uListenerMask = v88;
            v31 = (*((_BYTE *)&m_p3DSound->m_Params + 68) & 1) != 0 && v27->bSpatialized;
            v32 = &g_DefaultSoundPosition;
            if ( *p_m_aPos )
              v32 = *p_m_aPos;
            v33 = ComputeRay(
                    v27,
                    &v32[v28],
                    this->m_pGameObj->m_fScalingFactor,
                    v31,
                    in_bComputeEmitterDirectionAngle,
                    out_ray);
            if ( v33 < r )
              r = v33;
            ++v28;
            --v29;
          }
          while ( v29 );
          v19 = v98;
          v26 = j;
          v20 = v100;
        }
        ++v26;
        v19 >>= 1;
      }
      else
      {
        v19 >>= 1;
        ++v26;
      }
      v98 = v19;
    }
    if ( (*((_BYTE *)&m_p3DSound->m_Params + 68) & 8) != 0 )
      CAkRegisteredObj::CacheEmitListenPairs(this->m_pGameObj, out_arVolumeData);
  }
  else
  {
    do
    {
      v16 = AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(out_arVolumeData);
      if ( !v16 )
        break;
      v16->r = m_pItems->r;
      v16->theta = m_pItems->theta;
      v16->phi = m_pItems->phi;
      v16->fEmitterAngle = m_pItems->fEmitterAngle;
      *((_BYTE *)&v16->AkEmitterListenerPairEx + 16) ^= (*((_BYTE *)m_pItems + 16) ^ *((_BYTE *)&v16->AkEmitterListenerPairEx
                                                                                     + 16)) & 1;
      *((_BYTE *)&v16->AkEmitterListenerPairEx + 16) ^= (*((_BYTE *)m_pItems + 16) ^ *((_BYTE *)&v16->AkEmitterListenerPairEx
                                                                                     + 16)) & 2;
      v16->m_uListenerMask = m_pItems->m_uListenerMask;
      if ( m_pItems->r < r )
        r = m_pItems->r;
      ++m_pItems;
    }
    while ( m_pItems != &v11->m_arCachedEmitListPairs.m_pItems[v11->m_arCachedEmitListPairs.m_uLength] );
  }
  CAkPBI::ComputePriorityOffset(this, r, &m_p3DSound->m_Params);
  return out_arVolumeData->m_uLength;
}

// File Line: 2115
// RVA: 0xA83260
void __fastcall CAkPBI::VirtualPositionUpdate(CAkPBI *this)
{
  char v1; // al
  CAkRegisteredObj *m_pGameObj; // rax
  float m_fScalingFactor; // xmm6_4
  float MinDistance; // xmm0_4
  CAkPath *pPBPath; // rcx
  bool v7; // bl
  CAkPath *v8; // rcx
  AkPathState *PathState; // rax

  v1 = *((_BYTE *)this + 371);
  if ( (v1 & 3) != 0 )
  {
    if ( (v1 & 0xC) == 4 )
    {
      if ( (*((_BYTE *)&this->m_p3DSound->m_Params + 68) & 8) != 0 || (*((_BYTE *)this + 372) & 0x40) == 0 )
      {
        m_pGameObj = this->m_pGameObj;
        m_fScalingFactor = m_pGameObj->m_fScalingFactor;
        MinDistance = CAkURenderer::GetMinDistance(&m_pGameObj->m_PosKeep);
        CAkPBI::ComputePriorityOffset(this, MinDistance / m_fScalingFactor, &this->m_p3DSound->m_Params);
      }
    }
    else
    {
      pPBPath = this->m_PathInfo.pPBPath;
      if ( pPBPath )
      {
        v7 = (*((_BYTE *)&this->m_p3DSound->m_Params + 68) & 0x20) != 0;
        CAkPath::SetIsLooping(pPBPath, v7);
        if ( v7 )
        {
          v8 = this->m_PathInfo.pPBPath;
          if ( (v8->m_PathMode & 2) != 0 && CAkPath::IsIdle(v8) )
          {
            PathState = CAkParameterNode::GetPathState(this->m_pSound);
            CAkPathManager::Start(g_pPathManager, this->m_PathInfo.pPBPath, PathState);
          }
        }
      }
    }
  }
  else
  {
    this->m_Prev2DParams.prev2DParams.m_fPAN_X_2D = 101.0;
  }
}

// File Line: 2165
// RVA: 0xA81B10
bool __fastcall CAkPBI::IsInitiallyUnderThreshold(
        CAkPBI *this,
        AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *__formal)
{
  CAkBus *m_pControlBus; // rdi
  float v4; // xmm6_4
  float m_fEffectiveVoiceVolume; // xmm1_4
  float v6; // xmm2_4
  int v7; // edx
  float v8; // xmm1_4
  float v9; // xmm8_4
  float v10; // xmm8_4
  __int64 v11; // rcx
  unsigned int *i; // rax
  float fOutputBusVolume; // xmm7_4
  CAkBus *v14; // rbx
  float v15; // xmm7_4
  bool v16; // cf

  if ( (*((_BYTE *)this + 372) & 0x20) == 0 )
    ((void (__fastcall *)(CAkPBI *, AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *))this->CAkTransportAware::vfptr[7].~CAkTransportAware)(
      this,
      __formal);
  m_pControlBus = this->m_pControlBus;
  v4 = 0.0;
  m_fEffectiveVoiceVolume = 0.0;
  if ( m_pControlBus )
  {
    if ( (*((_BYTE *)m_pControlBus + 304) & 1) == 0 )
      CAkBus::UpdateVoiceVolumes(this->m_pControlBus);
    m_fEffectiveVoiceVolume = m_pControlBus->m_fEffectiveVoiceVolume;
  }
  v6 = FLOAT_1_0653532e9;
  v7 = `AkMath::FastPow10::`4::`local static guard;
  v8 = (float)(m_fEffectiveVoiceVolume + this->m_EffectiveParams.Volume) * 0.050000001;
  if ( v8 >= -37.0 )
  {
    if ( (`AkMath::FastPow10::`4::`local static guard & 1) == 0 )
    {
      v7 = `AkMath::FastPow10::`4::`local static guard | 1;
      `AkMath::FastPow10::`4::SCALE = 1272224376;
      `AkMath::FastPow10::`4::`local static guard |= 1u;
    }
    v9 = (float)((float)((float)((float)(COERCE_FLOAT(
                                           ((int)(float)((float)(*(float *)&`AkMath::FastPow10::`4::SCALE * v8)
                                                       + 1065353200.0) & 0x7FFFFF)
                                         + 1065353216)
                                       * 0.32518977)
                               + 0.020805772)
                       * COERCE_FLOAT(
                           ((int)(float)((float)(*(float *)&`AkMath::FastPow10::`4::SCALE * v8) + 1065353200.0) & 0x7FFFFF)
                         + 1065353216))
               + 0.65304345)
       * COERCE_FLOAT((int)(float)((float)(*(float *)&`AkMath::FastPow10::`4::SCALE * v8) + 1065353200.0) & 0xFF800000);
  }
  else
  {
    v9 = 0.0;
  }
  v10 = v9 * this->m_EffectiveParams.fFadeRatio;
  if ( !this->m_EffectiveParams.bGameDefinedAuxEnabled )
  {
    v11 = 0i64;
    for ( i = this->m_EffectiveParams.aAuxSend; !*i; ++i )
    {
      if ( ++v11 >= 4 )
      {
        fOutputBusVolume = this->m_EffectiveParams.fOutputBusVolume;
        v14 = this->m_pControlBus;
        if ( v14 )
        {
          if ( (*((_BYTE *)v14 + 304) & 1) == 0 )
          {
            CAkBus::UpdateVoiceVolumes(v14);
            v7 = `AkMath::FastPow10::`4::`local static guard;
            v6 = FLOAT_1_0653532e9;
          }
          fOutputBusVolume = fOutputBusVolume + v14->m_fEffectiveBusVolume;
        }
        v15 = fOutputBusVolume * 0.050000001;
        if ( v15 >= -37.0 )
        {
          if ( (v7 & 1) == 0 )
          {
            `AkMath::FastPow10::`4::SCALE = 1272224376;
            `AkMath::FastPow10::`4::`local static guard = v7 | 1;
          }
          v4 = (float)((float)((float)((float)(COERCE_FLOAT(
                                                 ((int)(float)((float)(v15 * *(float *)&`AkMath::FastPow10::`4::SCALE)
                                                             + v6) & 0x7FFFFF)
                                               + 1065353216)
                                             * 0.32518977)
                                     + 0.020805772)
                             * COERCE_FLOAT(
                                 ((int)(float)((float)(v15 * *(float *)&`AkMath::FastPow10::`4::SCALE) + v6) & 0x7FFFFF)
                               + 1065353216))
                     + 0.65304345)
             * COERCE_FLOAT((int)(float)((float)(v15 * *(float *)&`AkMath::FastPow10::`4::SCALE) + v6) & 0xFF800000);
        }
        v16 = g_fVolumeThreshold < (float)(v4 * v10);
        return !v16;
      }
    }
  }
  v16 = g_fVolumeThreshold < v10;
  return !v16;
}

// File Line: 2180
// RVA: 0xA80F70
void __fastcall CAkPBI::GetAuxSendsValues(CAkPBI *this, AkAuxSendValueEx *io_paEnvVal)
{
  AkAuxSendValue *m_EnvironmentValues; // r9
  int v4; // edx
  unsigned int v5; // r8d
  float v6; // xmm2_4
  float v7; // xmm3_4
  unsigned int i; // r11d
  unsigned int auxBusID; // ebx
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  __int64 v13; // rax
  float v14; // xmm3_4
  unsigned int v15; // ebx
  float *aUserAuxSendVolume; // r11
  unsigned int v17; // eax
  float v18; // xmm1_4
  __int64 v19; // r9
  float v20; // xmm1_4
  float *p_fControlValue; // rax
  __int64 v22; // rcx

  m_EnvironmentValues = this->m_pGameObj->m_EnvironmentValues;
  v4 = `AkMath::FastPow10::`4::`local static guard;
  v5 = 0;
  v6 = *(float *)&`AkMath::FastPow10::`4::SCALE;
  if ( this->m_EffectiveParams.bGameDefinedAuxEnabled )
  {
    v7 = g_fVolumeThreshold;
    for ( i = 0; i < 4; ++i )
    {
      auxBusID = m_EnvironmentValues->auxBusID;
      if ( !m_EnvironmentValues->auxBusID )
        break;
      v10 = this->m_EffectiveParams.fGameAuxSendVolume * 0.050000001;
      if ( v10 >= -37.0 )
      {
        if ( (v4 & 1) == 0 )
        {
          v6 = FLOAT_2_7866352e7;
          v4 |= 1u;
          `AkMath::FastPow10::`4::`local static guard = v4;
          `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
        }
        v11 = (float)((float)((float)((float)(COERCE_FLOAT(((int)(float)((float)(v6 * v10) + 1065353200.0) & 0x7FFFFF) + 1065353216)
                                            * 0.32518977)
                                    + 0.020805772)
                            * COERCE_FLOAT(((int)(float)((float)(v6 * v10) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                    + 0.65304345)
            * COERCE_FLOAT((int)(float)((float)(v6 * v10) + 1065353200.0) & 0xFF800000);
      }
      else
      {
        v11 = 0.0;
      }
      v12 = v11 * m_EnvironmentValues->fControlValue;
      if ( v12 > v7 )
      {
        v13 = v5++;
        io_paEnvVal[v13].auxBusID = auxBusID;
        io_paEnvVal[v13].eAuxType = AkAuxType_GameDef;
        io_paEnvVal[v13].fControlValue = v12;
      }
      ++m_EnvironmentValues;
    }
  }
  v14 = g_fVolumeThresholdDB;
  v15 = 0;
  aUserAuxSendVolume = this->m_EffectiveParams.aUserAuxSendVolume;
  while ( v5 < 8 )
  {
    v17 = *((_DWORD *)aUserAuxSendVolume + 4);
    if ( v17 && *aUserAuxSendVolume > v14 )
    {
      v18 = *aUserAuxSendVolume * 0.050000001;
      v19 = v5;
      io_paEnvVal[v19].auxBusID = v17;
      if ( v18 >= -37.0 )
      {
        if ( (v4 & 1) == 0 )
        {
          v6 = FLOAT_2_7866352e7;
          v4 |= 1u;
          `AkMath::FastPow10::`4::`local static guard = v4;
          `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
        }
        v20 = (float)((float)((float)((float)(COERCE_FLOAT(((int)(float)((float)(v6 * v18) + 1065353200.0) & 0x7FFFFF) + 1065353216)
                                            * 0.32518977)
                                    + 0.020805772)
                            * COERCE_FLOAT(((int)(float)((float)(v6 * v18) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                    + 0.65304345)
            * COERCE_FLOAT((int)(float)((float)(v6 * v18) + 1065353200.0) & 0xFF800000);
      }
      else
      {
        v20 = 0.0;
      }
      io_paEnvVal[v19].fControlValue = v20;
      io_paEnvVal[v19].eAuxType = AkAuxType_UserDef;
      ++v5;
    }
    ++v15;
    ++aUserAuxSendVolume;
    if ( v15 >= 4 )
    {
      if ( v5 < 8 )
        io_paEnvVal[v5].auxBusID = 0;
      break;
    }
  }
  if ( (*((_BYTE *)this + 375) & 0x10) != 0 && v5 )
  {
    p_fControlValue = &io_paEnvVal->fControlValue;
    v22 = v5;
    do
    {
      *p_fControlValue = 0.0;
      p_fControlValue += 8;
      --v22;
    }
    while ( v22 );
  }
}

// File Line: 2236
// RVA: 0xA82CD0
int __fastcall CAkPBI::SubscribeAttenuationRTPC(CAkPBI *this, CAkAttenuation *in_pAttenuation)
{
  CAkAttenuation::RTPCSubs *m_pItems; // rax
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *p_ConversionTable; // rbx
  int result; // eax

  m_pItems = in_pAttenuation->m_rtpcsubs.m_pItems;
  if ( m_pItems == &m_pItems[in_pAttenuation->m_rtpcsubs.m_uLength] )
    return 1;
  p_ConversionTable = &m_pItems->ConversionTable;
  while ( 1 )
  {
    result = CAkRTPCMgr::SubscribeRTPC(
               g_pRTPCMgr,
               this,
               (unsigned int)p_ConversionTable[-1].m_pArrayGraphPoints,
               SHIDWORD(p_ConversionTable[-1].m_pArrayGraphPoints),
               p_ConversionTable[-1].m_ulArraySize,
               p_ConversionTable->m_eScaling,
               p_ConversionTable->m_pArrayGraphPoints,
               p_ConversionTable->m_ulArraySize,
               this->m_pGameObj,
               SubscriberType_PBI);
    if ( result != 1 )
      break;
    p_ConversionTable += 2;
    if ( &p_ConversionTable[-1] == (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)&in_pAttenuation->m_rtpcsubs.m_pItems[in_pAttenuation->m_rtpcsubs.m_uLength] )
      return 1;
  }
  return result;
}

// File Line: 2261
// RVA: 0xA83080
void __fastcall CAkPBI::UnsubscribeAttenuationRTPC(CAkPBI *this, CAkAttenuation *in_pAttenuation)
{
  CAkAttenuation::RTPCSubs *m_pItems; // rbx

  m_pItems = in_pAttenuation->m_rtpcsubs.m_pItems;
  if ( m_pItems != &m_pItems[in_pAttenuation->m_rtpcsubs.m_uLength] )
  {
    do
    {
      CAkRTPCMgr::UnSubscribeRTPC(g_pRTPCMgr, this, m_pItems->ParamID);
      ++m_pItems;
    }
    while ( m_pItems != &in_pAttenuation->m_rtpcsubs.m_pItems[in_pAttenuation->m_rtpcsubs.m_uLength] );
  }
}

// File Line: 2287
// RVA: 0xA81E10
void __fastcall CAkPBI::Kick(CAkPBI *this, KickFrom in_eIsForMemoryThreshold)
{
  char v2; // al
  TransParams in_transParams; // [rsp+30h] [rbp+8h] BYREF

  v2 = *((_BYTE *)this + 374);
  if ( (v2 & 1) == 0 )
    *((_BYTE *)this + 374) = v2 ^ (v2 ^ (2 * in_eIsForMemoryThreshold)) & 0xE | 1;
  in_transParams.TransitionTime = 0;
  in_transParams.eFadeCurve = AkCurveInterpolation_Linear;
  CAkPBI::_Stop(this, &in_transParams, 1);
}

// File Line: 2318
// RVA: 0xA81460
void __fastcall CAkPBI::GetFXDataID(
        CAkPBI *this,
        __int64 in_uFXIndex,
        __int64 in_uDataIndex,
        unsigned int *out_rDataID)
{
  ((void (__fastcall *)(CAkSoundBase *, __int64, __int64, unsigned int *))this->m_pSound->vfptr[14].AddRef)(
    this->m_pSound,
    in_uFXIndex,
    in_uDataIndex,
    out_rDataID);
}

// File Line: 2325
// RVA: 0xA830F0
void __fastcall CAkPBI::UpdateFx(CAkPBI *this, __int64 in_uFXIndex)
{
  CAkVPLSrcCbxNodeBase *m_pCbx; // rcx

  m_pCbx = this->m_pCbx;
  if ( m_pCbx )
    m_pCbx->vfptr->UpdateFx(m_pCbx, in_uFXIndex);
}

// File Line: 2357
// RVA: 0xA83180
void __fastcall CAkPBI::ValidateFeedbackParameters(CAkPBI *this)
{
  CAkFeedbackDeviceMgr *v1; // rdi
  CAkVPLSrcCbxNodeBase *m_pCbx; // rax
  int vfptr_high; // edx
  AkFeedbackParams *m_pFeedbackInfo; // rdx

  v1 = CAkFeedbackDeviceMgr::s_pSingleton;
  if ( CAkFeedbackDeviceMgr::s_pSingleton && CAkFeedbackDeviceMgr::IsFeedbackEnabled(CAkFeedbackDeviceMgr::s_pSingleton) )
  {
    if ( !this->m_pFeedbackInfo
      && (((__int64 (__fastcall *)(CAkSoundBase *))this->m_pSound->vfptr[16].Release)(this->m_pSound)
       || *((char *)this + 374) < 0) )
    {
      m_pCbx = this->m_pCbx;
      if ( m_pCbx )
        vfptr_high = HIDWORD(m_pCbx[1].vfptr);
      else
        vfptr_high = *((_DWORD *)&this->m_sMediaFormat + 1) & 0x3FFFF;
      this->m_pFeedbackInfo = AkFeedbackParams::Create(
                                (unsigned __int8)v1->m_uLastPlayerIndex,
                                vfptr_high,
                                (AkPannerType)(*((_BYTE *)this + 371) & 3),
                                (AkPositionSourceType)((*((unsigned __int8 *)this + 371) >> 2) & 3));
    }
    m_pFeedbackInfo = this->m_pFeedbackInfo;
    if ( m_pFeedbackInfo )
      ((void (__fastcall *)(CAkSoundBase *, AkFeedbackParams *, CAkSource *, CAkRegisteredObj *, char))this->m_pSound->vfptr[16].__vecDelDtor)(
        this->m_pSound,
        m_pFeedbackInfo,
        this->m_pSource,
        this->m_pGameObj,
        1);
    *((_BYTE *)this + 374) |= 0x40u;
  }
}

// File Line: 2388
// RVA: 0xA81A70
void __fastcall CAkPBI::InvalidateFeedbackParameters(CAkPBI *this)
{
  AkFeedbackParams *m_pFeedbackInfo; // rcx

  m_pFeedbackInfo = this->m_pFeedbackInfo;
  if ( m_pFeedbackInfo )
  {
    AkFeedbackParams::Destroy(m_pFeedbackInfo);
    *((_BYTE *)this + 374) &= ~0x40u;
    this->m_pFeedbackInfo = 0i64;
  }
}

// File Line: 2400
// RVA: 0xA81DB0
char __fastcall CAkPBI::IsUsingThisSlot(CAkPBI *this, CAkUsageSlot *in_pSlotToCheck)
{
  CAkVPLSrcCbxNodeBase *m_pCbx; // rcx

  if ( this->m_pUsageSlot == in_pSlotToCheck && !CAkPBI::FindAlternateMedia(this, in_pSlotToCheck) )
    return 1;
  m_pCbx = this->m_pCbx;
  return m_pCbx && m_pCbx->vfptr->IsUsingThisSlot(m_pCbx, in_pSlotToCheck);
}

// File Line: 2446
// RVA: 0xA80D10
char __fastcall CAkPBI::FindAlternateMedia(CAkPBI *this, CAkUsageSlot *in_pSlotToCheck)
{
  CAkVPLSrcCbxNodeBase *m_pCbx; // rax
  CAkVPLSrcNode *v3; // rbx
  CAkVPLSrcNode *v5; // rcx
  CAkVPLSrcNode *v6; // rax
  CAkSource *m_pSource; // rcx
  CAkUsageSlot *m_pUsageSlot; // rcx
  unsigned int out_ulSize; // [rsp+30h] [rbp+8h] BYREF
  void *out_ppvBuffer; // [rsp+40h] [rbp+18h] BYREF
  CAkUsageSlot *out_rpSlot; // [rsp+48h] [rbp+20h] BYREF

  m_pCbx = this->m_pCbx;
  v3 = 0i64;
  if ( !m_pCbx )
    return 0;
  v5 = m_pCbx->m_pSources[0];
  if ( v5 && v5->m_pCtx == this )
    v3 = m_pCbx->m_pSources[0];
  v6 = m_pCbx->m_pSources[1];
  if ( v6 && v6->m_pCtx == this )
    v3 = v6;
  if ( !v3 )
    return 0;
  if ( !((unsigned __int8 (__fastcall *)(CAkVPLSrcNode *, CAkUsageSlot *))v3->vfptr[1].GetPitch)(v3, in_pSlotToCheck) )
    return 0;
  m_pSource = this->m_pSource;
  out_ppvBuffer = 0i64;
  out_ulSize = 0;
  out_rpSlot = 0i64;
  CAkSource::LockDataPtr(m_pSource, &out_ppvBuffer, &out_ulSize, &out_rpSlot);
  if ( !out_ppvBuffer )
    return 0;
  if ( ((unsigned int (__fastcall *)(CAkVPLSrcNode *, void *, char *))v3->vfptr[1].Connect)(
         v3,
         out_ppvBuffer,
         this->m_pDataPtr) != 1 )
  {
    if ( out_ppvBuffer )
      CAkSource::UnLockDataPtr(this->m_pSource);
    if ( out_rpSlot )
      CAkUsageSlot::Release(out_rpSlot, 0);
    return 0;
  }
  if ( ((unsigned __int8 (__fastcall *)(CAkVPLSrcNode *))v3->vfptr[2].__vecDelDtor)(v3) )
    this->m_pCbx->vfptr->RelocateMedia(this->m_pCbx, (char *)out_ppvBuffer, this->m_pDataPtr);
  if ( (*(unsigned __int8 (__fastcall **)(CAkVPLSrcNode *))v3->vfptr[2].gap8)(v3) )
    v3->m_pAnalysisData = (AkFileParser::AnalysisData *)((char *)v3->m_pAnalysisData
                                                       + (_BYTE *)out_ppvBuffer
                                                       - this->m_pDataPtr);
  if ( this->m_pDataPtr )
    CAkSource::UnLockDataPtr(this->m_pSource);
  m_pUsageSlot = this->m_pUsageSlot;
  if ( m_pUsageSlot )
    CAkUsageSlot::Release(m_pUsageSlot, 0);
  this->m_pDataPtr = (char *)out_ppvBuffer;
  this->m_pUsageSlot = out_rpSlot;
  return 1;
}

// File Line: 2514
// RVA: 0xA80E90
void __fastcall CAkPBI::ForceVirtualize(CAkPBI *this, KickFrom in_eReason)
{
  char v3; // cl
  char v4; // di
  int VirtualBehavior; // eax
  char v6; // cl
  char v7; // al
  AkVirtualQueueBehavior out_Behavior; // [rsp+30h] [rbp+8h] BYREF
  TransParams in_transParams; // [rsp+40h] [rbp+18h] BYREF

  v3 = *((_BYTE *)this + 372);
  v4 = in_eReason;
  if ( (v3 & 0x10) != 0 )
  {
    out_Behavior = *((unsigned __int8 *)this + 371) >> 5;
    VirtualBehavior = v3 & 0xF;
  }
  else
  {
    *((_BYTE *)this + 372) = v3 | 0x10;
    VirtualBehavior = CAkParameterNode::GetVirtualBehavior(this->m_pSound, &out_Behavior);
    *((_BYTE *)this + 371) &= 0x1Fu;
    v6 = out_Behavior;
    *((_BYTE *)this + 372) &= 0xF0u;
    *((_BYTE *)this + 371) |= 32 * v6;
    *((_BYTE *)this + 372) |= VirtualBehavior & 0xF;
  }
  if ( VirtualBehavior == 1 )
  {
    v7 = *((_BYTE *)this + 374);
    if ( (v7 & 1) == 0 )
      *((_BYTE *)this + 374) = v7 ^ (v7 ^ (2 * v4)) & 0xE | 1;
    in_transParams.TransitionTime = 0;
    in_transParams.eFadeCurve = AkCurveInterpolation_Linear;
    CAkPBI::_Stop(this, &in_transParams, 1);
  }
  else if ( VirtualBehavior == 2 )
  {
    *((_BYTE *)this + 375) |= 0x10u;
  }
}

// File Line: 2533
// RVA: 0xA83360
void __fastcall CAkPBI::Virtualize(CAkPBI *this)
{
  char v1; // al
  CAkRegisteredObj *m_pGameObj; // rax
  CAkSoundBase *m_pSound; // rcx
  int v4; // [rsp+20h] [rbp-38h] BYREF
  CAkRegisteredObj *v5; // [rsp+28h] [rbp-30h]
  __int64 v6; // [rsp+30h] [rbp-28h]
  __int64 v7; // [rsp+38h] [rbp-20h]
  int v8; // [rsp+40h] [rbp-18h]
  __int16 v9; // [rsp+44h] [rbp-14h]

  v1 = *((_BYTE *)this + 375);
  if ( (v1 & 0x40) == 0 )
  {
    *((_BYTE *)this + 375) = v1 | 0x40;
    ++CAkURenderer::m_uNumVirtualizedSounds;
    m_pGameObj = this->m_pGameObj;
    v4 = 0;
    m_pSound = this->m_pSound;
    v6 = 0i64;
    v7 = 0i64;
    v8 = 3;
    v9 = 256;
    v5 = m_pGameObj;
    m_pSound->vfptr[9].__vecDelDtor(m_pSound, (unsigned int)&v4);
  }
}

// File Line: 2546
// RVA: 0xA80C90
void __fastcall CAkPBI::Devirtualize(CAkPBI *this, bool in_bAllowKick)
{
  char v2; // al
  CAkRegisteredObj *m_pGameObj; // rax
  CAkSoundBase *m_pSound; // rcx
  int v7; // [rsp+20h] [rbp-38h] BYREF
  CAkRegisteredObj *v8; // [rsp+28h] [rbp-30h]
  __int64 v9; // [rsp+30h] [rbp-28h]
  __int64 v10; // [rsp+38h] [rbp-20h]
  int v11; // [rsp+40h] [rbp-18h]
  char v12; // [rsp+44h] [rbp-14h]
  bool v13; // [rsp+45h] [rbp-13h]

  v2 = *((_BYTE *)this + 375);
  if ( (v2 & 0x40) != 0 )
  {
    *((_BYTE *)this + 375) = v2 & 0xBF;
    CAkURenderer::DecrementVirtualCount(in_bAllowKick);
    m_pGameObj = this->m_pGameObj;
    v9 = 0i64;
    v10 = 0i64;
    v12 = 0;
    v7 = 0;
    m_pSound = this->m_pSound;
    v11 = 3;
    v8 = m_pGameObj;
    v13 = in_bAllowKick;
    ((void (__fastcall *)(CAkSoundBase *, int *))m_pSound->vfptr[9].AddRef)(m_pSound, &v7);
  }
}

// File Line: 2600
// RVA: 0xA81AB0
char __fastcall CAkPBI::IsAuxRoutable(CAkPBI *this)
{
  __int64 v1; // rdx
  unsigned int *i; // rcx

  if ( !this->m_EffectiveParams.bGameDefinedAuxEnabled )
  {
    v1 = 0i64;
    for ( i = this->m_EffectiveParams.aAuxSend; !*i; ++i )
    {
      if ( ++v1 >= 4 )
        return 0;
    }
  }
  return 1;
}

