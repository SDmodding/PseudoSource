// File Line: 147
// RVA: 0xA7FAA0
void __fastcall CAkPBI::CAkPBI(CAkPBI *this, CAkSoundBase *in_pSound, CAkSource *in_pSource, CAkRegisteredObj *in_pGameObj, UserParams *in_rUserparams, PlayHistory *in_rPlayHistory, unsigned int in_SeqID, PriorityInfoCurrent *in_rPriority, bool in_bTargetFeedback, unsigned int in_uSourceOffset, CAkLimiter *in_pAMLimiter, CAkLimiter *in_pBusLimiter)
{
  CAkPBI *v12; // rbx
  CAkSoundBase *v13; // rdi
  AkExternalSourceArray *v14; // rax
  float v15; // eax
  unsigned int v16; // ecx
  CAkRegisteredObj *v17; // rdx
  AkActivityChunk *v18; // rax
  CAkPBI *v19; // rcx
  CAkPBI **v20; // rax
  bool v21; // al
  CAkParameterNodeBase *v22; // rcx

  v12 = this;
  this->vfptr = (CAkTransportAwareVtbl *)&CAkPBI::`vftable'{for `CAkTransportAware'};
  this->m_uRegisteredNotif = 0;
  this->m_pUsageSlot = 0i64;
  v13 = in_pSound;
  this->vfptr = (ITransitionableVtbl *)&CAkContinuousPBI::`vftable'{for `ITransitionable'};
  this->m_mapMutedNodes.m_pItems = 0i64;
  *(_QWORD *)&this->m_mapMutedNodes.m_uLength = 0i64;
  *(_QWORD *)&this->m_Ranges.VolumeOffset = 0i64;
  this->m_Ranges.LPFOffset = 0.0;
  this->m_p3DSound = 0i64;
  this->m_UserParams.m_CustomParam.pExternalSrcs = 0i64;
  this->m_UserParams.m_PlayingID = in_rUserparams->m_PlayingID;
  this->m_UserParams.m_CustomParam.customParam = in_rUserparams->m_CustomParam.customParam;
  this->m_UserParams.m_CustomParam.ui32Reserved = in_rUserparams->m_CustomParam.ui32Reserved;
  v14 = in_rUserparams->m_CustomParam.pExternalSrcs;
  if ( v14 )
    ++v14->m_cRefCount;
  this->m_UserParams.m_CustomParam.pExternalSrcs = v14;
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
  v15 = in_rPriority->priorityInfo.distanceOffset;
  *(_QWORD *)&this->m_ulPauseCount = 0i64;
  this->m_PriorityInfoCurrent.priorityInfo.distanceOffset = v15;
  this->m_pDataPtr = 0i64;
  *(_QWORD *)&this->m_uDataSize = 0i64;
  *((_BYTE *)&this->m_cachedGameObjectPosition.0 + 11) &= 0xF8u;
  this->m_cachedGameObjectPosition.m_aPos = 0i64;
  this->m_cachedGameObjectPosition.m_uNumPos = 0;
  this->m_cachedGameObjectPosition.m_uListenerMask = 1;
  this->m_Prev2DParams.prev2DParams.m_fPAN_X_2D = 101.0;
  this->m_pAMLimiter = in_pAMLimiter;
  this->m_pBusLimiter = in_pBusLimiter;
  this->m_pFeedbackInfo = 0i64;
  this->m_pControlBus = (CAkBus *)CAkParameterNodeBase::GetControlBus((CAkParameterNodeBase *)&in_pSound->vfptr);
  v16 = CAkPBI::ms_PBIIDGenerator++;
  v17 = v12->m_pGameObj;
  v12->m_PriorityInfoCurrent.currentPriority.PBIID = v16;
  v12->m_PathInfo.pPBPath = 0i64;
  v12->m_PathInfo.PathOwnerID = 0;
  *((_DWORD *)v17 + 30) ^= (*((_DWORD *)v17 + 30) ^ (*((_DWORD *)v17 + 30) + 1)) & 0x3FFFFFFF;
  v13->vfptr->AddRef((CAkIndexable *)&v13->vfptr);
  v18 = v13->m_pActivityChunk;
  v19 = v18->m_listPBI.m_pFirst;
  v20 = &v18->m_listPBI.m_pFirst;
  if ( v19 )
  {
    v12->pNextLightItem = v19;
    *v20 = v12;
  }
  else
  {
    *v20 = v12;
    v12->pNextLightItem = 0i64;
  }
  if ( *((_BYTE *)&v13->0 + 83) & 8 )
  {
    v21 = 1;
  }
  else
  {
    v22 = v13->m_pBusOutputNode;
    if ( v22 || (v22 = v13->m_pParentNode) != 0i64 )
      v21 = CAkParameterNodeBase::IsInHdrHierarchy(v22);
    else
      v21 = 0;
  }
  *((_BYTE *)v12 + 376) &= 0xFEu;
  *((_DWORD *)&v12->m_sMediaFormat + 1) &= 0xFFFC0004;
  *((_BYTE *)v12 + 376) |= v21;
  *((_DWORD *)&v12->m_sMediaFormat + 1) |= 4u;
  v12->m_CntrHistArray.uiArraySize = in_rPlayHistory->HistArray.uiArraySize;
  *(_DWORD *)v12->m_CntrHistArray.aCntrHist = *(_DWORD *)in_rPlayHistory->HistArray.aCntrHist;
  *(_DWORD *)&v12->m_CntrHistArray.aCntrHist[2] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[2];
  *(_DWORD *)&v12->m_CntrHistArray.aCntrHist[4] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[4];
  *(_DWORD *)&v12->m_CntrHistArray.aCntrHist[6] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[6];
  *(_DWORD *)&v12->m_CntrHistArray.aCntrHist[8] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[8];
  *(_DWORD *)&v12->m_CntrHistArray.aCntrHist[10] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[10];
  *(_DWORD *)&v12->m_CntrHistArray.aCntrHist[12] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[12];
  *(_DWORD *)&v12->m_CntrHistArray.aCntrHist[14] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[14];
  *(_DWORD *)&v12->m_CntrHistArray.aCntrHist[16] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[16];
  *(_DWORD *)&v12->m_CntrHistArray.aCntrHist[18] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[18];
  *(_DWORD *)&v12->m_CntrHistArray.aCntrHist[20] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[20];
  *(_DWORD *)&v12->m_CntrHistArray.aCntrHist[22] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[22];
  *(_DWORD *)&v12->m_CntrHistArray.aCntrHist[24] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[24];
  *(_DWORD *)&v12->m_CntrHistArray.aCntrHist[26] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[26];
  *(_DWORD *)&v12->m_CntrHistArray.aCntrHist[28] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[28];
  *(_DWORD *)&v12->m_CntrHistArray.aCntrHist[30] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[30];
}

// File Line: 169
// RVA: 0xA81860
AKRESULT __fastcall CAkPBI::Init(CAkPBI *this, AkPathInfo *in_pPathInfo)
{
  CAkPBI *v2; // rbx
  CAkLimiter *v3; // rcx
  AkPathInfo *v4; // rbp
  AKRESULT v5; // edi
  CAkLimiter *v6; // rcx
  unsigned int v7; // edx
  char v8; // al
  CAkRegisteredObj *v9; // r8
  CAkParameterNode *v10; // rcx
  CAkGen3DParams *v11; // rsi
  CAkAttenuation *v12; // rdx
  CAkGen3DParams *v13; // rcx
  AKRESULT result; // eax
  CAkPath *v15; // rdx
  AkPositionSourceType out_ePosType; // [rsp+50h] [rbp+8h]
  AkPannerType out_ePannerType; // [rsp+60h] [rbp+18h]

  v2 = this;
  v3 = this->m_pAMLimiter;
  v4 = in_pPathInfo;
  v5 = 2;
  if ( v3 )
    CAkLimiter::Add(v3, v2, AKVoiceLimiter_AM);
  v6 = v2->m_pBusLimiter;
  if ( v6 )
    CAkLimiter::Add(v6, v2, AKVoiceLimiter_Bus);
  CAkLimiter::Add(&CAkURenderer::m_GlobalLimiter, v2, 0);
  v7 = v2->m_UserParams.m_PlayingID;
  if ( v7 )
  {
    v5 = (unsigned int)CAkPlayingMgr::SetPBI(
                         g_pPlayingMgr,
                         v7,
                         (CAkTransportAware *)&v2->vfptr,
                         &v2->m_uRegisteredNotif);
    if ( v5 == 1 )
    {
      v8 = ((__int64 (__fastcall *)(CAkSoundBase *, CAkRegisteredObj *))v2->m_pSound->vfptr[14].Release)(
             v2->m_pSound,
             v2->m_pGameObj);
      *((_BYTE *)v2 + 375) &= 0xFEu;
      v9 = v2->m_pGameObj;
      v10 = (CAkParameterNode *)&v2->m_pSound->vfptr;
      *((_BYTE *)v2 + 375) |= v8 & 1;
      v2->m_p3DSound = 0i64;
      CAkParameterNode::Get3DParams(v10, &v2->m_p3DSound, v9, &out_ePannerType, &out_ePosType, &v2->m_BasePosParams);
      *((_BYTE *)v2 + 371) &= 0xF0u;
      v11 = v2->m_p3DSound;
      *((_BYTE *)v2 + 371) |= out_ePannerType & 3 | (unsigned __int8)(4 * (out_ePosType & 3));
      if ( v11 )
      {
        if ( !v11->m_Params.m_pAttenuation )
          v11->m_Params.m_pAttenuation = (CAkAttenuation *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                                             (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxAttenuations,
                                                             v11->m_Params.m_uAttenuationID);
        v12 = v11->m_Params.m_pAttenuation;
        v13 = v2->m_p3DSound;
        if ( v12 )
        {
          v13->m_Params.m_fConeOutsideVolume = v12->m_ConeParams.fOutsideVolume;
          v2->m_p3DSound->m_Params.m_fConeLoPass = v12->m_ConeParams.LoPass;
          result = CAkPBI::SubscribeAttenuationRTPC(v2, v12);
          v5 = result;
          if ( result != 1 )
            return result;
        }
        else if ( v13->m_Params.m_uAttenuationID )
        {
          return 2;
        }
        CAkPBI::Init3DPath(v2, v4);
      }
      else
      {
        *((_BYTE *)v2 + 371) &= 0xFCu;
      }
      v15 = v2->m_PathInfo.pPBPath;
      if ( v15 )
      {
        if ( (unsigned int)CAkPathManager::AddPathUser(g_pPathManager, v15, v2) == 2 )
        {
          v2->m_PathInfo.pPBPath = 0i64;
        }
        else
        {
          CAkPath::SetSoundUniqueID(v2->m_PathInfo.pPBPath, v2->m_pSound->key);
          CAkPath::SetPlayingID(v2->m_PathInfo.pPBPath, v2->m_UserParams.m_PlayingID);
        }
      }
      CAkSource::LockDataPtr(v2->m_pSource, (void **)&v2->m_pDataPtr, &v2->m_uDataSize, &v2->m_pUsageSlot);
    }
  }
  return v5;
}

// File Line: 260
// RVA: 0xA7FDC0
void __fastcall CAkPBI::~CAkPBI(CAkPBI *this)
{
  CAkPBI *v1; // rbx
  AkSoundPosition *v2; // rdx
  AkExternalSourceArray *v3; // rcx

  v1 = this;
  this->vfptr = (CAkTransportAwareVtbl *)&CAkPBI::`vftable'{for `CAkTransportAware'};
  this->vfptr = (ITransitionableVtbl *)&CAkContinuousPBI::`vftable'{for `ITransitionable'};
  v2 = this->m_cachedGameObjectPosition.m_aPos;
  if ( v2 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v2);
    v1->m_cachedGameObjectPosition.m_aPos = 0i64;
    v1->m_cachedGameObjectPosition.m_uNumPos = 0;
  }
  v3 = v1->m_UserParams.m_CustomParam.pExternalSrcs;
  if ( v3 )
    AkExternalSourceArray::Release(v3);
  v1->vfptr = (CAkTransportAwareVtbl *)&CAkTransportAware::`vftable';
}

// File Line: 265
// RVA: 0xA82DA0
void __fastcall CAkPBI::Term(CAkPBI *this, bool __formal)
{
  CAkPBI *v2; // rdi
  CAkPath *v3; // rax
  AkPathState *v4; // rax
  CAkTransition *v5; // rdx
  CAkTransition *v6; // rdx
  char v7; // al
  unsigned int v8; // edx
  CAkRegisteredObj *v9; // rsi
  int v10; // ecx
  int v11; // ebx
  CAkGen3DParams *v12; // rbx
  CAkAttenuation *v13; // rdx
  CAkGen3DParams *v14; // rbx
  int v15; // esi
  MapStruct<AkMutedMapItem,float> *v16; // rdx
  CAkUsageSlot *v17; // rcx
  char v18; // bl
  AkFeedbackParams *v19; // rcx
  CAkSource *v20; // rbx
  int v21; // edi

  v2 = this;
  CAkPBI::DecrementPlayCount(this);
  v3 = v2->m_PathInfo.pPBPath;
  if ( v3 )
  {
    if ( ((unsigned int)v3->m_PathMode >> 1) & 1 )
    {
      v4 = CAkParameterNode::GetPathState((CAkParameterNode *)&v2->m_pSound->vfptr);
      v4->pbPlayed = 0i64;
      v4->ulCurrentListIndex = 0;
    }
    CAkPathManager::RemovePathUser(g_pPathManager, v2->m_PathInfo.pPBPath, v2);
    v2->m_PathInfo.pPBPath = 0i64;
    v2->m_PathInfo.PathOwnerID = 0;
  }
  v5 = v2->m_PBTrans.pvPSTrans;
  if ( v5 )
    CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, v5, (ITransitionable *)&v2->vfptr);
  v6 = v2->m_PBTrans.pvPRTrans;
  if ( v6 )
    CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, v6, (ITransitionable *)&v2->vfptr);
  v7 = *((_BYTE *)v2 + 373);
  if ( v7 & 1 )
    *((_BYTE *)v2 + 373) = v7 & 0xFE;
  v8 = v2->m_UserParams.m_PlayingID;
  if ( v8 )
    CAkPlayingMgr::Remove(g_pPlayingMgr, v8, (CAkTransportAware *)&v2->vfptr);
  v9 = v2->m_pGameObj;
  if ( v9 )
  {
    v10 = *((_DWORD *)v9 + 30) ^ (*((_DWORD *)v9 + 30) ^ (*((_DWORD *)v9 + 30) - 1)) & 0x3FFFFFFF;
    *((_DWORD *)v9 + 30) = v10;
    if ( !(v10 & 0x3FFFFFFF) )
    {
      v11 = g_DefaultPoolId;
      CAkRegisteredObj::~CAkRegisteredObj(v9);
      AK::MemoryMgr::Free(v11, v9);
    }
  }
  v12 = v2->m_p3DSound;
  if ( v12 )
  {
    if ( !v12->m_Params.m_pAttenuation )
      v12->m_Params.m_pAttenuation = (CAkAttenuation *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                                         (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxAttenuations,
                                                         v12->m_Params.m_uAttenuationID);
    v13 = v12->m_Params.m_pAttenuation;
    if ( v13 )
      CAkPBI::UnsubscribeAttenuationRTPC(v2, v13);
    v14 = v2->m_p3DSound;
    v15 = g_DefaultPoolId;
    if ( v14 )
    {
      v14->vfptr->__vecDelDtor(v2->m_p3DSound, 0);
      AK::MemoryMgr::Free(v15, v14);
    }
    v2->m_p3DSound = 0i64;
  }
  v16 = v2->m_mapMutedNodes.m_pItems;
  if ( v16 )
  {
    v2->m_mapMutedNodes.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v16);
    v2->m_mapMutedNodes.m_pItems = 0i64;
    v2->m_mapMutedNodes.m_ulReserved = 0;
  }
  CAkParameterNodeBase::RemovePBI((CAkParameterNodeBase *)&v2->m_pSound->vfptr, v2);
  if ( v2->m_pDataPtr )
  {
    CAkSource::UnLockDataPtr(v2->m_pSource);
    v2->m_pDataPtr = 0i64;
  }
  v17 = v2->m_pUsageSlot;
  if ( v17 )
  {
    CAkUsageSlot::Release(v17, 0);
    v2->m_pUsageSlot = 0i64;
  }
  v18 = (*((_WORD *)&v2->m_pSource->m_sSrcTypeInfo.mediaInfo + 8) >> 8) & 1;
  ((void (*)(void))v2->m_pSound->vfptr->Release)();
  v19 = v2->m_pFeedbackInfo;
  if ( v19 )
  {
    AkFeedbackParams::Destroy(v19);
    v2->m_pFeedbackInfo = 0i64;
  }
  if ( v18 )
  {
    v20 = v2->m_pSource;
    v21 = g_DefaultPoolId;
    if ( v20 )
    {
      CAkSource::~CAkSource(v20);
      AK::MemoryMgr::Free(v21, v20);
    }
  }
}

// File Line: 369
// RVA: 0xA833D0
void __fastcall CAkPBI::_InitPlay(CAkPBI *this)
{
  CAkPBI *v1; // rbx
  char v2; // al
  bool v3; // zf
  AkPathState *v4; // rax

  v1 = this;
  this->m_LoopCount = CAkSoundBase::Loop(this->m_pSound);
  v2 = *((_BYTE *)v1 + 373);
  if ( v2 >= 0 )
  {
    v3 = v1->m_PathInfo.pPBPath == 0i64;
    *((_BYTE *)v1 + 373) = v2 | 0x80;
    if ( !v3 )
    {
      v4 = CAkParameterNode::GetPathState((CAkParameterNode *)&v1->m_pSound->vfptr);
      CAkPathManager::Start(g_pPathManager, v1->m_PathInfo.pPBPath, v4);
    }
  }
}

// File Line: 388
// RVA: 0xA816F0
signed __int64 __fastcall CAkPBI::Init3DPath(CAkPBI *this, AkPathInfo *in_pPathInfo)
{
  CAkPBI *v2; // rbx
  Gen3DParams *v3; // r9
  char v5; // r8
  CAkSoundBase *v6; // rcx
  char v7; // al
  CAkParameterNodeBase *i; // rcx
  unsigned int v9; // esi
  AKRESULT v10; // edi
  CAkPath *v11; // rax
  AkPathState *v12; // rax
  CAkPath *v13; // rcx

  v2 = this;
  v3 = &this->m_p3DSound->m_Params;
  if ( this->m_p3DSound == (CAkGen3DParams *)-8i64 )
    return 1i64;
  v5 = *((_BYTE *)this + 371);
  if ( !(v5 & 0xC) )
  {
    v6 = this->m_pSound;
    v7 = ((unsigned __int64)LODWORD(v6->m_RTPCBitArray.m_iBitArray) >> 10) & 1 && *((_BYTE *)&v6->0 + 83) & 0x10;
    for ( i = v6->m_pParentNode; !v7; i = i->m_pParentNode )
    {
      if ( !i )
        break;
      v7 = ((unsigned __int64)LODWORD(i->m_RTPCBitArray.m_iBitArray) >> 10) & 1 && *((_BYTE *)i + 83) & 0x10 ? 1 : 0;
    }
    if ( !(v5 & 3) && !v7 )
      return 1i64;
  }
  v9 = v3->m_ID;
  v10 = 1;
  if ( in_pPathInfo->pPBPath && in_pPathInfo->PathOwnerID == v9 )
    v2->m_PathInfo = *in_pPathInfo;
  if ( !v2->m_PathInfo.pPBPath || v3->m_ePathMode & 4 )
  {
    CAkPathManager::AddPathToList(g_pPathManager);
    v2->m_PathInfo.pPBPath = v11;
    if ( v11 )
    {
      v12 = CAkParameterNode::GetPathState((CAkParameterNode *)&v2->m_pSound->vfptr);
      v10 = CAkGen3DParams::SetPathPlayList(v2->m_p3DSound, v2->m_PathInfo.pPBPath, v12);
      if ( v10 != 1 )
      {
        CAkPathManager::RemovePathFromList(g_pPathManager, v2->m_PathInfo.pPBPath);
        v9 = 0;
        v2->m_PathInfo.pPBPath = 0i64;
      }
      v2->m_PathInfo.PathOwnerID = v9;
    }
  }
  if ( !(*((_BYTE *)&v2->m_p3DSound->m_Params + 68) & 0x10) )
  {
    v13 = v2->m_PathInfo.pPBPath;
    if ( v13 )
      CAkPath::InitRotationMatricesForNoFollowMode(v13, (unsigned __int8)v2->m_pGameObj->m_PosKeep.m_uListenerMask);
  }
  return (unsigned int)v10;
}

// File Line: 459
// RVA: 0xA83650
signed __int64 __fastcall CAkPBI::_Play(CAkPBI *this, TransParams *in_transParams, __int64 in_bPaused, bool in_bForceIgnoreSync)
{
  bool v4; // r15
  char v5; // bp
  CAkPBI *v6; // rsi
  TransParams in_NewDuration; // rbx
  CAkTransition *v8; // rdx
  ITransitionable *v9; // r14
  CAkTransition *v10; // rax
  CAkTransportAwareVtbl *v11; // r9
  CAkTransition *v12; // rdi
  __int64 v13; // r8
  __int64 v14; // r9
  unsigned int v15; // ebx
  unsigned int v16; // eax
  CAkTransition *v17; // rdx
  CAkPath *v18; // rdx
  signed __int64 result; // rax
  ITransitionable *v20; // [rsp+40h] [rbp-48h]
  __int64 v21; // [rsp+48h] [rbp-40h]
  int v22; // [rsp+50h] [rbp-38h]
  int v23; // [rsp+54h] [rbp-34h]
  TransParams v24; // [rsp+58h] [rbp-30h]
  __int16 v25; // [rsp+60h] [rbp-28h]

  v4 = in_bForceIgnoreSync;
  v5 = in_bPaused;
  v6 = this;
  if ( in_transParams->TransitionTime )
  {
    this->m_fPlayStopFadeRatio = 0.0;
    in_NewDuration = *in_transParams;
    v8 = this->m_PBTrans.pvPSTrans;
    if ( v8 )
    {
      CAkTransitionManager::ChangeParameter(
        g_pTransitionManager,
        v8,
        0x1000000i64,
        1.0,
        in_NewDuration.TransitionTime,
        in_NewDuration.eFadeCurve,
        0);
    }
    else
    {
      v21 = 0x1000000i64;
      v9 = (ITransitionable *)&this->vfptr;
      v20 = (ITransitionable *)&this->vfptr;
      v22 = 0;
      v23 = (signed int)FLOAT_1_0;
      LOBYTE(in_bPaused) = 1;
      v24 = in_NewDuration;
      v25 = 256;
      v10 = CAkTransitionManager::AddTransitionToList(
              g_pTransitionManager,
              (TransitionParameters *)&v20,
              in_bPaused,
              0i64);
      v11 = v6->vfptr;
      *((_BYTE *)&v6->m_PBTrans + 16) &= 0xFEu;
      *((_BYTE *)v6 + 375) |= 0x80u;
      v12 = v10;
      v6->m_PBTrans.pvPSTrans = v10;
      ((void (__fastcall *)(CAkPBI *, signed __int64, _QWORD))v11[8]._Stop)(
        v6,
        14i64,
        (unsigned int)in_NewDuration.TransitionTime);
      if ( !v12 )
      {
        LOBYTE(v14) = 1;
        ((void (__fastcall *)(ITransitionable *, __int64, __int64, __int64))v9->vfptr->TransUpdateValue)(
          v9,
          v21,
          v13,
          v14);
      }
    }
  }
  if ( v5 == 1 || (*((_BYTE *)v6 + 370) & 7) == 1 )
  {
    *((_BYTE *)v6 + 373) |= 0x40u;
    v16 = CAkLEngineCmds::EnqueueAction(LEStatePlayPause, v6);
    v17 = v6->m_PBTrans.pvPSTrans;
    v15 = v16;
    if ( v17 )
      CAkTransitionManager::Pause(g_pTransitionManager, v17);
    v18 = v6->m_PathInfo.pPBPath;
    if ( v18 )
      CAkPathManager::Pause(g_pPathManager, v18);
  }
  else
  {
    v15 = CAkLEngineCmds::EnqueueAction(0, v6);
  }
  if ( v15 != 1 )
    return v15;
  if ( (*((_BYTE *)v6 + 370) & 7) == 2 )
    v6->vfptr->_Stop((CAkTransportAware *)&v6->vfptr, 0i64, 0, 0);
  result = 1i64;
  if ( v4 )
    ++CAkLEngineCmds::m_ulPlayEventID;
  return result;
}

// File Line: 510
// RVA: 0xA83C20
void __fastcall CAkPBI::_Stop(CAkPBI *this, AkPBIStopMode in_eStopMode, bool in_bIsFromTransition, bool __formal)
{
  char v4; // al
  AkPBIStopMode v5; // edi
  CAkPBI *v6; // rbx
  CAkTransition *v7; // rdx
  CAkTransition *v8; // rdx
  CAkPath *v9; // rax
  AkPathState *v10; // rax

  v4 = *((_BYTE *)this + 373);
  v5 = in_eStopMode;
  v6 = this;
  if ( !(v4 & 0x10) )
  {
    *((_BYTE *)this + 373) = v4 | 0x10;
    if ( !in_bIsFromTransition )
      CAkLEngineCmds::EnqueueActionStop(this);
    if ( !(v5 & 0xFFFFFFFD) )
    {
      v7 = v6->m_PBTrans.pvPSTrans;
      if ( v7 )
      {
        CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, v7, (ITransitionable *)&v6->vfptr);
        v6->m_PBTrans.pvPSTrans = 0i64;
      }
      v8 = v6->m_PBTrans.pvPRTrans;
      if ( v8 )
      {
        CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, v8, (ITransitionable *)&v6->vfptr);
        v6->m_PBTrans.pvPRTrans = 0i64;
      }
      v9 = v6->m_PathInfo.pPBPath;
      if ( v9 )
      {
        if ( ((unsigned int)v9->m_PathMode >> 1) & 1 )
        {
          v10 = CAkParameterNode::GetPathState((CAkParameterNode *)&v6->m_pSound->vfptr);
          v10->pbPlayed = 0i64;
          v10->ulCurrentListIndex = 0;
        }
        CAkPathManager::RemovePathUser(g_pPathManager, v6->m_PathInfo.pPBPath, v6);
        v6->m_PathInfo.pPBPath = 0i64;
        v6->m_PathInfo.PathOwnerID = 0;
      }
      *((_BYTE *)v6 + 373) &= 0xFEu;
      *((_BYTE *)v6 + 373) |= 4u;
    }
  }
}

// File Line: 603
// RVA: 0xA83A40
void __fastcall CAkPBI::_Stop(CAkPBI *this, TransParams *in_transParams, __int64 in_bUseMinTransTime, _BOOL8 a4)
{
  char v4; // al
  CAkPBI *v5; // rsi
  TransParams in_NewDuration; // rbx
  CAkTransition *v7; // rdx
  ITransitionable *v8; // r14
  CAkTransition *v9; // rax
  CAkTransportAwareVtbl *v10; // r9
  CAkTransition *v11; // rdi
  __int64 v12; // r8
  __int64 v13; // r9
  CAkTransition *v14; // rdx
  TransitionParameters in_Params; // [rsp+40h] [rbp-38h]

  v4 = *((_BYTE *)this + 373);
  v5 = this;
  if ( v4 & 0x40 || this->m_PBTrans.pvPRTrans && *((_BYTE *)&this->m_PBTrans + 16) & 2 )
  {
    this->vfptr->_Stop((CAkTransportAware *)this, 0i64, 0, 0);
  }
  else
  {
    *((_BYTE *)this + 373) = v4 | 0x20;
    if ( in_transParams->TransitionTime )
    {
      in_NewDuration = *in_transParams;
      v7 = this->m_PBTrans.pvPSTrans;
      if ( v7 )
      {
        CAkTransitionManager::ChangeParameter(
          g_pTransitionManager,
          v7,
          0x2000000i64,
          0.0,
          in_NewDuration.TransitionTime,
          in_NewDuration.eFadeCurve,
          0);
      }
      else
      {
        v8 = (ITransitionable *)&this->vfptr;
        in_Params.fStartValue = this->m_fPlayStopFadeRatio;
        in_Params.fTargetValue = 0.0;
        LOBYTE(in_bUseMinTransTime) = 1;
        in_Params.pUser = (ITransitionable *)&this->vfptr;
        in_Params.eTarget = 0x2000000i64;
        *(TransParams *)&in_Params.lDuration = in_NewDuration;
        *(_WORD *)&in_Params.bdBs = 256;
        v9 = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, in_bUseMinTransTime, 0i64);
        v10 = v5->vfptr;
        *((_BYTE *)&v5->m_PBTrans + 16) |= 1u;
        *((_BYTE *)v5 + 375) &= 0x7Fu;
        v11 = v9;
        v5->m_PBTrans.pvPSTrans = v9;
        ((void (__fastcall *)(CAkPBI *, signed __int64, _QWORD))v10[8]._Stop)(
          v5,
          14i64,
          (unsigned int)in_NewDuration.TransitionTime);
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
    else if ( *((_BYTE *)this + 370) & 0x78 )
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
          0);
      }
      else if ( (_BYTE)in_bUseMinTransTime )
      {
        CAkPBI::StopWithMinTransTime(this, 0i64, in_bUseMinTransTime);
      }
    }
    else
    {
      LOBYTE(a4) = 1;
      this->vfptr->_Stop((CAkTransportAware *)this, 0i64, 0, a4);
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
  if ( !(v3 & 1) )
    *((_BYTE *)this + 374) = v3 & 0xF1 | 1;
  LOBYTE(a3) = 1;
  this->vfptr->_Stop((CAkTransportAware *)this, 0i64, a3, 0);
}

// File Line: 678
// RVA: 0xA835D0
void __fastcall CAkPBI::_Pause(CAkPBI *this, bool in_bIsFromTransition)
{
  char v2; // al
  CAkPBI *v3; // rbx
  bool v4; // zf
  CAkTransition *v5; // rdx
  CAkPath *v6; // rdx

  v2 = *((_BYTE *)this + 373);
  v3 = this;
  if ( !(v2 & 0x10) && !(v2 & 0x40) )
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
    v5 = v3->m_PBTrans.pvPSTrans;
    if ( v5 )
      CAkTransitionManager::Pause(g_pTransitionManager, v5);
    v6 = v3->m_PathInfo.pPBPath;
    if ( v6 )
      CAkPathManager::Pause(g_pPathManager, v6);
  }
}

// File Line: 707
// RVA: 0xA83440
void __fastcall CAkPBI::_Pause(CAkPBI *this, TransParams *in_transParams, __int64 a3)
{
  CAkPBI *v3; // rsi
  TransParams in_NewDuration; // rbx
  CAkTransition *v5; // rdx
  float v6; // xmm0_4
  ITransitionable *v7; // r14
  CAkTransition *v8; // rax
  CAkTransportAwareVtbl *v9; // r9
  CAkTransition *v10; // rdi
  __int64 v11; // r8
  __int64 v12; // r9
  CAkTransition *v13; // rdx
  TransitionParameters in_Params; // [rsp+40h] [rbp-38h]

  ++this->m_ulPauseCount;
  v3 = this;
  if ( in_transParams->TransitionTime )
  {
    in_NewDuration = *in_transParams;
    v5 = this->m_PBTrans.pvPRTrans;
    if ( v5 )
    {
      CAkTransitionManager::ChangeParameter(
        g_pTransitionManager,
        v5,
        0x4000000i64,
        0.0,
        in_NewDuration.TransitionTime,
        in_NewDuration.eFadeCurve,
        0);
    }
    else
    {
      v6 = this->m_fPauseResumeFadeRatio;
      in_Params.eTarget = 0x4000000i64;
      *(TransParams *)&in_Params.lDuration = in_NewDuration;
      in_Params.fStartValue = v6;
      v7 = (ITransitionable *)&this->vfptr;
      in_Params.fTargetValue = 0.0;
      in_Params.pUser = (ITransitionable *)&this->vfptr;
      LOBYTE(a3) = 1;
      *(_WORD *)&in_Params.bdBs = 256;
      v8 = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, a3, 0i64);
      v9 = v3->vfptr;
      *((_BYTE *)&v3->m_PBTrans + 16) |= 2u;
      v10 = v8;
      v3->m_PBTrans.pvPRTrans = v8;
      ((void (__fastcall *)(CAkPBI *, signed __int64, _QWORD))v9[8]._Stop)(
        v3,
        14i64,
        (unsigned int)in_NewDuration.TransitionTime);
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
  else if ( *((_BYTE *)this + 370) & 0x78 )
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
        0);
    else
      ((void (__fastcall *)(CAkPBI *, signed __int64))this->vfptr[2].~CAkTransportAware)(this, 1i64);
  }
  else
  {
    ((void (__fastcall *)(CAkPBI *, _QWORD))this->vfptr[2].~CAkTransportAware)(this, 0i64);
  }
}

// File Line: 740
// RVA: 0xA839D0
void __fastcall CAkPBI::_Resume(CAkPBI *this)
{
  char v1; // al
  CAkPBI *v2; // rbx
  CAkPath *v3; // rdx
  CAkTransition *v4; // rdx

  v1 = *((_BYTE *)this + 373);
  v2 = this;
  if ( !(v1 & 0x10) && v1 & 0x40 )
  {
    v3 = this->m_PathInfo.pPBPath;
    if ( v3 )
      CAkPathManager::Resume(g_pPathManager, v3);
    *((_BYTE *)v2 + 373) &= 0xBFu;
    CAkLEngineCmds::EnqueueAction(LEStateResume, v2);
    v4 = v2->m_PBTrans.pvPSTrans;
    if ( v4 )
      CAkTransitionManager::Resume(g_pTransitionManager, v4);
  }
}

// File Line: 760
// RVA: 0xA83820
void __fastcall CAkPBI::_Resume(CAkPBI *this, TransParams *in_transParams, bool in_bIsMasterResume)
{
  TransParams *v3; // rbx
  CAkPBI *v4; // rsi
  unsigned int v5; // eax
  CAkTransportAwareVtbl *v6; // rax
  __int64 v7; // r8
  CAkTransition *v8; // rdx
  TransParams in_NewDuration; // rbx
  CAkTransition *v10; // rax
  CAkTransportAwareVtbl *v11; // r9
  CAkTransition *v12; // rdi
  __int64 v13; // r8
  __int64 v14; // r9
  TransitionParameters in_Params; // [rsp+40h] [rbp-38h]

  v3 = in_transParams;
  v4 = this;
  if ( in_bIsMasterResume || (v5 = this->m_ulPauseCount, v5 <= 1) )
  {
    v6 = this->vfptr;
    this->m_ulPauseCount = 0;
    ((void (*)(void))v6[3]._Stop)();
    v8 = v4->m_PBTrans.pvPRTrans;
    if ( v3->TransitionTime )
    {
      in_NewDuration = *v3;
      if ( v8 )
      {
        CAkTransitionManager::ChangeParameter(
          g_pTransitionManager,
          v8,
          0x8000000i64,
          1.0,
          in_NewDuration.TransitionTime,
          in_NewDuration.eFadeCurve,
          0);
      }
      else
      {
        in_Params.fStartValue = v4->m_fPauseResumeFadeRatio;
        LODWORD(in_Params.fTargetValue) = (_DWORD)FLOAT_1_0;
        LOBYTE(v7) = 1;
        in_Params.eTarget = 0x8000000i64;
        *(TransParams *)&in_Params.lDuration = in_NewDuration;
        in_Params.pUser = (ITransitionable *)&v4->vfptr;
        *(_WORD *)&in_Params.bdBs = 256;
        v10 = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, v7, 0i64);
        v11 = v4->vfptr;
        *((_BYTE *)&v4->m_PBTrans + 16) &= 0xFDu;
        v12 = v10;
        v4->m_PBTrans.pvPRTrans = v10;
        ((void (__fastcall *)(CAkPBI *, signed __int64, _QWORD))v11[8]._Stop)(
          v4,
          14i64,
          (unsigned int)in_NewDuration.TransitionTime);
        if ( !v12 )
        {
          LOBYTE(v14) = 1;
          ((void (__fastcall *)(ITransitionableVtbl **, __int64, __int64, __int64))v4->vfptr->TransUpdateValue)(
            &v4->vfptr,
            in_Params.eTarget,
            v13,
            v14);
        }
      }
    }
    else if ( v8 )
    {
      CAkTransitionManager::ChangeParameter(
        g_pTransitionManager,
        v8,
        0x8000000i64,
        1.0,
        0,
        AkCurveInterpolation_Linear,
        0);
    }
    else
    {
      v4->m_fPauseResumeFadeRatio = 1.0;
      CAkPBI::CalculateMutedEffectiveVolume(v4);
    }
  }
  else
  {
    this->m_ulPauseCount = v5 - 1;
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
  *((_BYTE *)this + 375) = *((_BYTE *)this + 375) ^ (*((_BYTE *)this + 375) ^ 8 * in_bSnapToMarker) & 8 | 6;
  CAkLEngineCmds::EnqueueAction(LEStateSeek, this);
}

// File Line: 826
// RVA: 0xA82080
void __fastcall CAkPBI::ParamNotification(CAkPBI *this, NotifParams *in_rParams)
{
  NotifParams *v2; // rdi
  CAkPBI *v3; // rbx
  AkFeedbackParams *v4; // rax
  float v5; // xmm0_4
  float v6; // xmm1_4
  AkFeedbackParams *v7; // rax
  AkFeedbackParams *v8; // rax

  v2 = in_rParams;
  v3 = this;
  switch ( in_rParams->eType )
  {
    case 0:
    case 4:
      if ( *((_BYTE *)this + 374) >= 0 || !in_rParams->bIsFromBus )
      {
        this->m_Volume = in_rParams->fValue + this->m_Volume;
        CAkPBI::CalculateMutedEffectiveVolume(this);
        if ( v2->bIsFromBus )
        {
          v4 = v3->m_pFeedbackInfo;
          if ( v4 )
            v4->m_AudioBusVolume = v2->fValue + v4->m_AudioBusVolume;
        }
      }
      return;
    case 2:
      goto $LN17_66;
    case 3:
      v5 = in_rParams->fValue + this->m_LPF;
      this->m_LPF = v5;
      this->m_EffectiveParams.LPF = v5 + this->m_LPFAutomationOffset;
      return;
    case 8:
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
      v3->m_PriorityInfoCurrent.priorityInfo.priority = v2->fValue;
      break;
    case 0xF:
      this->m_EffectiveParams.aUserAuxSendVolume[0] = in_rParams->fValue + this->m_EffectiveParams.aUserAuxSendVolume[0];
      break;
    case 0x10:
      this->m_EffectiveParams.aUserAuxSendVolume[1] = in_rParams->fValue + this->m_EffectiveParams.aUserAuxSendVolume[1];
      break;
    case 0x11:
      this->m_EffectiveParams.aUserAuxSendVolume[2] = in_rParams->fValue + this->m_EffectiveParams.aUserAuxSendVolume[2];
      break;
    case 0x12:
      this->m_EffectiveParams.aUserAuxSendVolume[3] = in_rParams->fValue + this->m_EffectiveParams.aUserAuxSendVolume[3];
      break;
    case 0x13:
      this->m_EffectiveParams.fGameAuxSendVolume = in_rParams->fValue + this->m_EffectiveParams.fGameAuxSendVolume;
      break;
    case 0x16:
      this->m_EffectiveParams.fOutputBusVolume = in_rParams->fValue + this->m_EffectiveParams.fOutputBusVolume;
      break;
    case 0x17:
      this->m_EffectiveParams.fOutputBusLPF = in_rParams->fValue + this->m_EffectiveParams.fOutputBusLPF;
      break;
    case 0x1D:
      v7 = this->m_pFeedbackInfo;
      if ( v7 )
        v7->m_NewVolume = in_rParams->fValue + v7->m_NewVolume;
      break;
    case 0x1E:
      v8 = this->m_pFeedbackInfo;
      if ( v8 )
        v8->m_LPF = in_rParams->fValue + v8->m_LPF;
      break;
    case 0x1F:
      if ( *((_BYTE *)this + 374) < 0 )
$LN17_66:
        this->m_EffectiveParams.Pitch = in_rParams->fValue + this->m_EffectiveParams.Pitch;
      break;
    case 0x23:
      this->m_EffectiveParams.hdr.fActiveRange = in_rParams->fValue + this->m_EffectiveParams.hdr.fActiveRange;
      break;
    case 0x24:
      this->m_EffectiveParams.normalization.fMakeUpGain = in_rParams->fValue
                                                        + this->m_EffectiveParams.normalization.fMakeUpGain;
      break;
    default:
      return;
  }
}

// File Line: 924
// RVA: 0xA81E60
void __fastcall CAkPBI::MuteNotification(CAkPBI *this, float in_fMuteRatio, AkMutedMapItem *in_rMutedItem, bool in_bPrioritizeGameObjectSpecificItems)
{
  CAkPBI *v4; // rbx
  MapStruct<AkMutedMapItem,float> *v5; // rdi
  int v6; // er11
  void *v7; // r10
  signed __int64 v8; // rcx
  unsigned int v9; // esi
  MapStruct<AkMutedMapItem,float> *i; // rax
  unsigned __int64 v11; // rcx
  MapStruct<AkMutedMapItem,float> *v12; // rdi
  __int64 v13; // rax
  signed __int64 v14; // rcx
  unsigned __int64 v15; // rcx
  AkMutedMapItem v16; // [rsp+20h] [rbp-18h]

  v4 = this;
  if ( in_bPrioritizeGameObjectSpecificItems )
  {
    v5 = this->m_mapMutedNodes.m_pItems;
    v6 = *((_DWORD *)in_rMutedItem + 2);
    v7 = in_rMutedItem->m_Identifier;
    v8 = (signed __int64)&v5[this->m_mapMutedNodes.m_uLength];
    v9 = *((_DWORD *)&v16 + 2) & 0xFFFFFFFC | ~(unsigned __int8)*((_DWORD *)in_rMutedItem + 2) & 1;
    for ( i = v5; i != (MapStruct<AkMutedMapItem,float> *)v8; ++i )
    {
      if ( i->key.m_Identifier == v7 && !(((unsigned __int8)v9 ^ *((_BYTE *)&i->key + 8)) & 1) )
        break;
    }
    if ( i != (MapStruct<AkMutedMapItem,float> *)v8 && i != (MapStruct<AkMutedMapItem,float> *)-16i64 )
    {
      if ( v6 & 1 )
        return;
      if ( v5 != (MapStruct<AkMutedMapItem,float> *)v8 )
      {
        do
        {
          if ( v5->key.m_Identifier == v7 && !(((unsigned __int8)v9 ^ *((_BYTE *)&v5->key + 8)) & 1) )
            break;
          ++v5;
        }
        while ( v5 != (MapStruct<AkMutedMapItem,float> *)v8 );
        if ( v5 != (MapStruct<AkMutedMapItem,float> *)v8 )
        {
          v11 = v8 - 24;
          if ( (unsigned __int64)v5 < v11 )
            qmemcpy(
              v5,
              &v5[1],
              24
            * (((unsigned __int64)((v11 - (unsigned __int64)v5 - 1) * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 4)
             + 1));
          --v4->m_mapMutedNodes.m_uLength;
        }
      }
    }
  }
  if ( in_fMuteRatio != 1.0 || in_bPrioritizeGameObjectSpecificItems && !(*((_BYTE *)in_rMutedItem + 8) & 1) )
  {
    v16 = *in_rMutedItem;
    CAkKeyArray<AkMutedMapItem,float,2>::Set(&v4->m_mapMutedNodes, &v16, in_fMuteRatio);
  }
  else
  {
    v12 = v4->m_mapMutedNodes.m_pItems;
    v13 = v4->m_mapMutedNodes.m_uLength;
    v16 = *in_rMutedItem;
    v14 = (signed __int64)&v12[v13];
    if ( v12 != (MapStruct<AkMutedMapItem,float> *)v14 )
    {
      do
      {
        if ( v12->key.m_Identifier == v16.m_Identifier && !((*((_BYTE *)&v16 + 8) ^ *((_BYTE *)&v12->key + 8)) & 1) )
          break;
        ++v12;
      }
      while ( v12 != (MapStruct<AkMutedMapItem,float> *)v14 );
      if ( v12 != (MapStruct<AkMutedMapItem,float> *)v14 )
      {
        v15 = v14 - 24;
        if ( (unsigned __int64)v12 < v15 )
          qmemcpy(
            v12,
            &v12[1],
            24
          * (((unsigned __int64)((v15 - (unsigned __int64)v12 - 1) * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 4)
           + 1));
        --v4->m_mapMutedNodes.m_uLength;
      }
    }
  }
  CAkPBI::CalculateMutedEffectiveVolume(v4);
}

// File Line: 974
// RVA: 0xA82B60
__int64 __fastcall CAkPBI::SetMuteMapEntry(CAkPBI *this, AkMutedMapItem *in_key, float in_fFadeRatio)
{
  CAkPBI *v3; // rbx
  unsigned int v4; // edi
  MapStruct<AkMutedMapItem,float> *v5; // rdi
  signed __int64 v6; // rax
  AkMutedMapItem v8; // [rsp+20h] [rbp-18h]

  v3 = this;
  v8 = *in_key;
  if ( in_fFadeRatio == 1.0 )
  {
    v5 = this->m_mapMutedNodes.m_pItems;
    v6 = (signed __int64)&v5[this->m_mapMutedNodes.m_uLength];
    if ( v5 != (MapStruct<AkMutedMapItem,float> *)v6 )
    {
      do
      {
        if ( v5->key.m_Identifier == v8.m_Identifier && !((*((_BYTE *)&v8 + 8) ^ *((_BYTE *)&v5->key + 8)) & 1) )
          break;
        ++v5;
      }
      while ( v5 != (MapStruct<AkMutedMapItem,float> *)v6 );
      if ( v5 != (MapStruct<AkMutedMapItem,float> *)v6 )
      {
        if ( (unsigned __int64)v5 < v6 - 24 )
          qmemcpy(
            v5,
            &v5[1],
            24
          * (((unsigned __int64)((unsigned __int64)(v6 - 24 - (_QWORD)v5 - 1)
                               * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 4)
           + 1));
        --this->m_mapMutedNodes.m_uLength;
      }
    }
    v4 = 1;
  }
  else
  {
    v4 = 2 - (CAkKeyArray<AkMutedMapItem,float,2>::Set(&this->m_mapMutedNodes, &v8, in_fFadeRatio) != 0i64);
  }
  CAkPBI::CalculateMutedEffectiveVolume(v3);
  return v4;
}

// File Line: 990
// RVA: 0xA82930
void __fastcall CAkPBI::RemoveAllVolatileMuteItems(CAkPBI *this)
{
  MapStruct<AkMutedMapItem,float> *v1; // rax
  __int64 v2; // rdx
  MapStruct<AkMutedMapItem,float> *v3; // r9

  v1 = this->m_mapMutedNodes.m_pItems;
  if ( v1 != &v1[this->m_mapMutedNodes.m_uLength] )
  {
    do
    {
      if ( *((_BYTE *)&v1->key + 8) & 2 )
      {
        ++v1;
      }
      else
      {
        v2 = this->m_mapMutedNodes.m_uLength;
        if ( (unsigned int)v2 > 1 )
        {
          v3 = &this->m_mapMutedNodes.m_pItems[v2];
          v1->key.m_Identifier = v3[-1].key.m_Identifier;
          *((_QWORD *)&v1->key + 1) = *((_QWORD *)&v3[-1].key + 1);
          *(_QWORD *)&v1->item = *(_QWORD *)&v3[-1].item;
        }
        --this->m_mapMutedNodes.m_uLength;
      }
    }
    while ( v1 != &this->m_mapMutedNodes.m_pItems[this->m_mapMutedNodes.m_uLength] );
  }
}

// File Line: 1002
// RVA: 0xA816B0
float __fastcall CAkPBI::GetVoiceVolumedB(CAkPBI *this)
{
  CAkBus *v1; // rbx

  v1 = this->m_pControlBus;
  if ( !v1 )
    return 0.0;
  if ( !(*((_BYTE *)v1 + 304) & 1) )
    CAkBus::UpdateVoiceVolumes(this->m_pControlBus);
  return v1->m_fEffectiveVoiceVolume;
}

// File Line: 1015
// RVA: 0xA815C0
float __fastcall CAkPBI::GetOutputBusVolumeValuedB(CAkPBI *this)
{
  CAkBus *v1; // rbx
  float v2; // xmm6_4

  v1 = this->m_pControlBus;
  v2 = this->m_EffectiveParams.fOutputBusVolume;
  if ( v1 )
  {
    if ( !(*((_BYTE *)v1 + 304) & 1) )
      CAkBus::UpdateVoiceVolumes(this->m_pControlBus);
    v2 = v2 + v1->m_fEffectiveBusVolume;
  }
  return v2;
}

// File Line: 1028
// RVA: 0xA82A40
float __fastcall CAkPBI::Scale3DUserDefRTPCValue(CAkPBI *this, float in_fValue)
{
  CAkGen3DParams *v2; // rbx
  float v3; // xmm6_4
  CAkAttenuation *v4; // rcx
  unsigned __int8 v5; // al
  signed __int64 v6; // rdx

  v2 = this->m_p3DSound;
  v3 = in_fValue;
  if ( !v2->m_Params.m_pAttenuation )
    v2->m_Params.m_pAttenuation = (CAkAttenuation *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                                      (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxAttenuations,
                                                      v2->m_Params.m_uAttenuationID);
  v4 = v2->m_Params.m_pAttenuation;
  if ( v4 )
  {
    v5 = v4->m_curveToUse[0];
    if ( v5 != -1 )
    {
      v6 = (signed __int64)&v4->m_curves[v5];
      if ( *(_QWORD *)v6 )
      {
        if ( v6 )
          v3 = (float)(in_fValue * *(float *)(*(_QWORD *)v6 + 12i64 * (unsigned int)(*(_DWORD *)(v6 + 8) - 1)))
             * 0.0099999998;
      }
    }
  }
  return v3;
}

// File Line: 1046
// RVA: 0xA82410
void __fastcall CAkPBI::PositioningChangeNotification(CAkPBI *this, float in_RTPCValue, AkRTPC_ParameterID in_ParameterID)
{
  CAkPBI *v3; // rbx
  CAkGen3DParams *v4; // rdi
  CAkGen3DParams *v5; // rdi
  char v6; // al
  CAkGen3DParams *v7; // rcx
  __int32 v8; // er8
  int v9; // er8
  int v10; // er8
  AkPositionSourceType out_ePosType; // [rsp+50h] [rbp+18h]
  AkPannerType out_ePannerType; // [rsp+58h] [rbp+20h]

  v3 = this;
  switch ( in_ParameterID )
  {
    case 10:
      v6 = (signed int)in_RTPCValue & 3 | *((_BYTE *)this + 371) & 0xEC | (*((_BYTE *)this + 371) | 16 * ((*((_BYTE *)this + 371) & 3) != (signed int)in_RTPCValue)) & 0x10;
      *((_BYTE *)this + 371) = v6;
      if ( (v6 & 3) == 1 && !this->m_p3DSound )
      {
        CAkParameterNode::Get3DParams(
          (CAkParameterNode *)&this->m_pSound->vfptr,
          &this->m_p3DSound,
          this->m_pGameObj,
          &out_ePannerType,
          &out_ePosType,
          &this->m_BasePosParams);
        if ( !v3->m_p3DSound )
          *((_BYTE *)v3 + 371) &= 0xFCu;
      }
      break;
    case 11:
      this->m_BasePosParams.m_fCenterPCT = in_RTPCValue;
      break;
    case 20:
      this->m_BasePosParams.m_fPAN_X_2D = in_RTPCValue;
      break;
    case 21:
      this->m_BasePosParams.m_fPAN_Y_2D = in_RTPCValue;
      break;
    case 37:
      v4 = this->m_p3DSound;
      if ( v4 )
        v4->m_Params.m_Position.X = CAkPBI::Scale3DUserDefRTPCValue(this, in_RTPCValue);
      break;
    case 38:
      v5 = this->m_p3DSound;
      if ( v5 )
        v5->m_Params.m_Position.Z = CAkPBI::Scale3DUserDefRTPCValue(this, in_RTPCValue);
      break;
    case 64:
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
                v7->m_Params.m_ePathMode = (signed int)in_RTPCValue;
            }
            else
            {
              CAkGen3DParams::SetTransition(v7, (signed int)in_RTPCValue);
            }
          }
          else if ( in_RTPCValue == 0.0 )
          {
            *((_BYTE *)&v7->m_Params + 68) &= 0xDFu;
            *((_BYTE *)&v7->m_Params + 68) = *((_BYTE *)&v7->m_Params + 68);
          }
          else
          {
            *((_BYTE *)&v7->m_Params + 68) &= 0xDFu;
            *((_BYTE *)&v7->m_Params + 68) |= 0x20u;
          }
        }
        else
        {
          *((_BYTE *)&v7->m_Params + 68) &= 0xF7u;
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
  MapStruct<AkMutedMapItem,float> *v1; // rax
  float v2; // xmm0_4
  signed __int64 i; // rdx
  float v4; // xmm0_4

  v1 = this->m_mapMutedNodes.m_pItems;
  v2 = *(float *)&FLOAT_1_0;
  for ( i = (signed __int64)&v1[this->m_mapMutedNodes.m_uLength]; v1 != (MapStruct<AkMutedMapItem,float> *)i; ++v1 )
    v2 = v2 * v1->item;
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
  *((_BYTE *)this + 372) &= 0xDFu;
  *((_BYTE *)this + 374) &= 0xBFu;
}

// File Line: 1142
// RVA: 0xA82020
void __fastcall CAkPBI::NotifyBypass(CAkPBI *this, unsigned int in_bitsFXBypass, unsigned int in_uTargetMask)
{
  CAkPBI *v3; // rdi
  CAkVPLSrcCbxNodeBase *v4; // rcx
  char v5; // si
  unsigned int v6; // ebx

  v3 = this;
  v4 = this->m_pCbx;
  v5 = in_uTargetMask;
  v6 = in_bitsFXBypass;
  if ( v4 && in_uTargetMask & 0xFFFFFFEF )
    ((void (*)(void))v4->vfptr->SetFxBypass)();
  if ( v5 & 0x10 )
  {
    *((_BYTE *)v3 + 375) &= 0xFEu;
    *((_BYTE *)v3 + 375) |= (v6 >> 4) & 1;
  }
}

// File Line: 1180
// RVA: 0xA82FE0
void __usercall CAkPBI::TransUpdateValue(CAkPBI *this@<rcx>, __int64 in_eTarget@<rdx>, float in_fValue@<xmm2>, bool in_bIsTerminated@<r9b>, __int64 a5@<r8>)
{
  CAkPBI *v5; // rbx

  v5 = this;
  if ( ((_DWORD)in_eTarget - 0x1000000) & 0xFEFFFFFF )
  {
    if ( !(((_DWORD)in_eTarget - 0x4000000) & 0xFBFFFFFF) )
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
      v5->m_Volume = in_fValue;
    }
  }
  else
  {
    if ( in_bIsTerminated )
    {
      this->m_UserParams.m_CustomParam.pExternalSrcs = 0i64;
      if ( (_DWORD)in_eTarget == 0x2000000 )
      {
        LOBYTE(a5) = 1;
        ((void (__fastcall *)(CAkLimiter **, _QWORD, __int64, _QWORD))this[-1].m_pBusLimiter->m_sortedPBIList.m_pItems)(
          &this[-1].m_pBusLimiter,
          0i64,
          a5,
          0i64);
      }
    }
    *(float *)&v5->m_EffectiveParams.bGameDefinedAuxEnabled = in_fValue;
  }
  CAkPBI::CalculateMutedEffectiveVolume((CAkPBI *)((char *)v5 - 16));
}

// File Line: 1225
// RVA: 0xA82C40
signed __int64 __fastcall CAkPBI::SetParam(CAkPBI *this, __int16 in_paramID, const void *in_pParam, unsigned int in_uParamSize)
{
  CAkGen3DParams *v4; // r9
  float v5; // xmm0_4
  signed __int64 result; // rax

  v4 = this->m_p3DSound;
  if ( !v4 )
    return 1i64;
  v5 = *(float *)in_pParam;
  if ( in_paramID == 13 )
  {
    v4->m_Params.m_fConeOutsideVolume = v5;
    return 1i64;
  }
  result = 1i64;
  if ( in_paramID == 14 )
    v4->m_Params.m_fConeLoPass = v5;
  return result;
}

// File Line: 1302
// RVA: 0xA80B90
void __fastcall CAkPBI::DecrementPlayCount(CAkPBI *this)
{
  CAkPBI *v1; // rbx
  char v2; // al
  CAkLimiter *v3; // rcx
  CAkLimiter *v4; // rcx
  __int64 v5; // rax
  CAkSoundBase *v6; // rcx
  int v7; // [rsp+20h] [rbp-38h]
  __int64 v8; // [rsp+28h] [rbp-30h]
  __int64 v9; // [rsp+30h] [rbp-28h]
  __int64 v10; // [rsp+38h] [rbp-20h]
  int v11; // [rsp+40h] [rbp-18h]
  __int16 v12; // [rsp+44h] [rbp-14h]

  v1 = this;
  if ( *((_BYTE *)this + 375) & 0x40 )
    CAkPBI::Devirtualize(this, 0);
  v2 = *((_BYTE *)v1 + 374);
  if ( !(v2 & 0x10) )
  {
    v3 = v1->m_pAMLimiter;
    *((_BYTE *)v1 + 374) = v2 | 0x10;
    if ( v3 )
    {
      CAkLimiter::Remove(v3, v1, AKVoiceLimiter_AM);
      v1->m_pAMLimiter = 0i64;
    }
    v4 = v1->m_pBusLimiter;
    if ( v4 )
    {
      CAkLimiter::Remove(v4, v1, AKVoiceLimiter_Bus);
      v1->m_pBusLimiter = 0i64;
    }
    CAkLimiter::Remove(&CAkURenderer::m_GlobalLimiter, v1, 0);
    v5 = (__int64)v1->m_pGameObj;
    v6 = v1->m_pSound;
    v7 = 0;
    v8 = v5;
    v9 = 0i64;
    v10 = 0i64;
    v11 = 3;
    v12 = 256;
    ((void (__fastcall *)(CAkSoundBase *, int *))v6->vfptr[8].Category)(v6, &v7);
  }
}

// File Line: 1336
// RVA: 0xA81620
__int64 __fastcall CAkPBI::GetVirtualBehavior(CAkPBI *this, AkVirtualQueueBehavior *out_Behavior)
{
  char v2; // al
  AkVirtualQueueBehavior *v3; // rdi
  CAkPBI *v4; // rbx
  __int64 result; // rax
  char v6; // cl
  char v7; // dl

  v2 = *((_BYTE *)this + 372);
  v3 = out_Behavior;
  v4 = this;
  if ( v2 & 0x10 )
  {
    *out_Behavior = (unsigned int)*((unsigned __int8 *)this + 371) >> 5;
    result = *((_BYTE *)this + 372) & 0xF;
  }
  else
  {
    *((_BYTE *)this + 372) = v2 | 0x10;
    result = CAkParameterNode::GetVirtualBehavior((CAkParameterNode *)&this->m_pSound->vfptr, out_Behavior);
    v6 = *(_BYTE *)v3;
    v7 = *((_BYTE *)v4 + 371);
    *((_BYTE *)v4 + 372) &= 0xF0u;
    *((_BYTE *)v4 + 371) = 32 * v6 | v7 & 0x1F;
    *((_BYTE *)v4 + 372) |= result & 0xF;
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
  CAkURenderer::EnqueueContextNotif(this, CtxStatePlay, 0, in_fDuration);
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
  CAkURenderer::EnqueueContextNotif(this, CtxStatePause, 0, 0.0);
}

// File Line: 1460
// RVA: 0xA82A20
void __fastcall CAkPBI::Resume(CAkPBI *this)
{
  *((_BYTE *)this + 370) &= 0x9Fu;
  *((_BYTE *)this + 370) |= 0x18u;
  CAkURenderer::EnqueueContextNotif(this, CtxStateResume, 0, 0.0);
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
void __fastcall CAkPBI::ProcessContextNotif(CAkPBI *this, AkCtxState in_eState, __int64 in_eDestroyReason, float in_fEstimatedLength)
{
  __int32 v4; // edx
  CAkPBI *v5; // rbx
  int v6; // edx
  __int64 v7; // rdx
  CAkTransportAwareVtbl *v8; // rax

  v4 = in_eState - 1;
  if ( v4 )
  {
    v5 = this;
    v6 = v4 - 1;
    if ( v6 )
    {
      v7 = (unsigned int)(v6 - 1);
      if ( (_DWORD)v7 )
      {
        if ( (_DWORD)v7 == 1 && (_DWORD)in_eDestroyReason == 1 )
        {
          *((_BYTE *)this + 373) &= 0xFEu;
          *((_BYTE *)this + 373) |= 8u;
        }
      }
      else
      {
        v8 = this->vfptr;
        *((_BYTE *)this + 373) |= 1u;
        ((void (__fastcall *)(CAkPBI *, __int64, __int64))v8[5].~CAkTransportAware)(this, v7, in_eDestroyReason);
        ((void (__fastcall *)(CAkPBI *))v5->vfptr[2]._Stop)(v5);
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
CAkBus *__fastcall CAkPBI::GetOutputBusPtr(CAkPBI *this)
{
  JUMPOUT(*((_BYTE *)this + 374) < 0, CAkParameterNodeBase::GetFeedbackParentBusOrDefault);
  return (CAkBus *)((__int64 (*)(void))this->m_pSound->vfptr[7].Category)();
}

// File Line: 1538
// RVA: 0xA82700
void __fastcall CAkPBI::RefreshParameters(CAkPBI *this)
{
  AkSoundParamsEx *v1; // rdi
  CAkPBI *v2; // rbx
  unsigned int *v3; // rax
  signed __int64 v4; // rcx
  CAkVPLSrcCbxNodeBase *v5; // rcx
  char v6; // al
  float v7; // xmm0_4
  bool v8; // zf
  unsigned __int8 v9; // dl
  CAkSoundBase *v10; // rcx
  signed __int64 v11; // r8
  CAkRegisteredObj *v12; // rax
  char v13; // ST28_1
  float v14; // eax
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  AkFeedbackParams *v18; // rax
  float v19; // xmm1_4
  char v20; // [rsp+38h] [rbp-10h]
  PriorityInfo result; // [rsp+50h] [rbp+8h]

  v1 = &this->m_EffectiveParams;
  v2 = this;
  v1->Volume = 0.0;
  *(_QWORD *)&v1->fFadeRatio = 1065353216i64;
  *(_QWORD *)&v1->LPF = 0i64;
  *((_BYTE *)&v1->normalization + 4) &= 0xFCu;
  v1->normalization.fMakeUpGain = 0.0;
  *((_BYTE *)&v1->hdr + 4) &= 0xFCu;
  v1->hdr.fActiveRange = 0.0;
  v3 = this->m_EffectiveParams.aAuxSend;
  v4 = 4i64;
  *(_QWORD *)&v1->fOutputBusVolume = 0i64;
  do
  {
    *(v3 - 4) = 0;
    *v3 = 0;
    ++v3;
    --v4;
  }
  while ( v4 );
  v1->fGameAuxSendVolume = 0.0;
  *(_WORD *)&v1->bGameDefinedAuxEnabled = 0;
  v1->bUserDefinedServiced = 0;
  CAkPBI::RemoveAllVolatileMuteItems(v2);
  CAkParameterNode::UpdateBaseParams(
    (CAkParameterNode *)&v2->m_pSound->vfptr,
    v2->m_pGameObj,
    &v2->m_BasePosParams,
    v2->m_p3DSound);
  v5 = v2->m_pCbx;
  if ( v5 )
    ((void (*)(void))v5->vfptr->RefreshBypassFx)();
  v6 = ((__int64 (__fastcall *)(CAkSoundBase *, CAkRegisteredObj *))v2->m_pSound->vfptr[14].Release)(
         v2->m_pSound,
         v2->m_pGameObj);
  *((_BYTE *)v2 + 375) &= 0xFEu;
  *((_BYTE *)v2 + 375) |= v6 & 1;
  if ( *((_BYTE *)v2 + 374) < 0 )
  {
    v7 = CAkFeedbackNode::GetSourceVolumeOffset((CAkFeedbackNode *)v2->m_pSound, v2->m_pSource);
    v8 = (*((_BYTE *)v2 + 374) & 0x40) == 0;
    v1->Volume = v7;
    if ( v8 )
      CAkPBI::ValidateFeedbackParameters(v2);
  }
  v9 = *((_BYTE *)v2 + 372);
  v10 = v2->m_pSound;
  v11 = 0xFFFFFFFFi64;
  v20 = 1;
  if ( !(*((_BYTE *)v2 + 376) & 1) )
    v11 = 4294967279i64;
  v12 = v2->m_pGameObj;
  v2->m_Prev2DParams.prev2DParams.m_fPAN_X_2D = 101.0;
  v13 = ~(v9 >> 7) & 1;
  ((void (__fastcall *)(CAkSoundBase *, AkSoundParamsEx *, signed __int64, CAkKeyArray<AkMutedMapItem,float,2> *, CAkRegisteredObj *, char, AkPBIModValues *, char))v10->vfptr[10].Release)(
    v10,
    v1,
    v11,
    &v2->m_mapMutedNodes,
    v12,
    v13,
    &v2->m_Ranges,
    v20);
  v14 = v1->Volume;
  v15 = v2->m_Ranges.LPFOffset + v2->m_EffectiveParams.LPF;
  v16 = v2->m_Ranges.PitchOffset + v2->m_EffectiveParams.Pitch;
  *((_BYTE *)v2 + 372) |= 0x80u;
  v2->m_Volume = v14;
  v2->m_LPF = v15;
  v17 = v15 + v2->m_LPFAutomationOffset;
  v2->m_EffectiveParams.Pitch = v16;
  v2->m_EffectiveParams.LPF = v17;
  CAkPBI::CalculateMutedEffectiveVolume(v2);
  if ( *((_BYTE *)v2 + 374) < 0 )
  {
    v18 = v2->m_pFeedbackInfo;
    if ( v18 )
      v2->m_EffectiveParams.Pitch = v18->m_MotionBusPitch + v2->m_EffectiveParams.Pitch;
  }
  CAkParameterNodeBase::GetPriority((CAkParameterNodeBase *)&v2->m_pSound->vfptr, &result, v2->m_pGameObj);
  v19 = result.priority;
  if ( result.priority != v2->m_PriorityInfoCurrent.priorityInfo.priority
    || result.distanceOffset != v2->m_PriorityInfoCurrent.priorityInfo.distanceOffset )
  {
    v2->m_PriorityInfoCurrent.priorityInfo = result;
    CAkPBI::UpdatePriority(v2, v19);
  }
  *((_BYTE *)v2 + 372) |= 0x20u;
}

// File Line: 1609
// RVA: 0xA83110
void __fastcall CAkPBI::UpdatePriority(CAkPBI *this, float in_NewPriority)
{
  CAkPBI *v2; // rbx
  CAkLimiter *v3; // rcx
  CAkLimiter *v4; // rcx

  v2 = this;
  if ( in_NewPriority != this->m_PriorityInfoCurrent.currentPriority.priority )
  {
    v3 = this->m_pAMLimiter;
    if ( v3 )
      CAkLimiter::Update(v3, in_NewPriority, v2);
    v4 = v2->m_pBusLimiter;
    if ( v4 )
      CAkLimiter::Update(v4, in_NewPriority, v2);
    CAkLimiter::Update(&CAkURenderer::m_GlobalLimiter, in_NewPriority, v2);
    v2->m_PriorityInfoCurrent.currentPriority.priority = in_NewPriority;
  }
}

// File Line: 1637
// RVA: 0xA7FF70
void __fastcall CAkPBI::ComputePriorityOffset(CAkPBI *this, float in_fMinDistance, Gen3DParams *in_p3DParams)
{
  float v3; // xmm6_4
  float v4; // xmm7_4
  Gen3DParams *v5; // rdi
  CAkPBI *v6; // rbx
  float v7; // xmm9_4
  CAkAttenuation *v8; // rcx
  unsigned __int8 v9; // al
  signed __int64 v10; // rdx
  float v11; // xmm0_4
  CAkLimiter *v12; // rcx
  CAkLimiter *v13; // rcx

  v3 = this->m_PriorityInfoCurrent.priorityInfo.priority;
  v4 = 0.0;
  v5 = in_p3DParams;
  v6 = this;
  v7 = this->m_PriorityInfoCurrent.priorityInfo.distanceOffset;
  if ( v7 != 0.0 )
  {
    if ( !in_p3DParams->m_pAttenuation )
      in_p3DParams->m_pAttenuation = (CAkAttenuation *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                                         (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxAttenuations,
                                                         in_p3DParams->m_uAttenuationID);
    v8 = v5->m_pAttenuation;
    if ( v8 )
    {
      v9 = v8->m_curveToUse[0];
      if ( v9 != -1 )
      {
        v10 = (signed __int64)&v8->m_curves[v9];
        if ( *(_QWORD *)v10 )
        {
          if ( v10 )
          {
            v11 = *(float *)(*(_QWORD *)v10 + 12i64 * (unsigned int)(*(_DWORD *)(v10 + 8) - 1));
            if ( in_fMinDistance >= v11 || v11 <= 0.0 )
              v3 = v3 + v7;
            else
              v3 = v3 + (float)((float)(in_fMinDistance / v11) * v7);
          }
        }
      }
    }
    if ( v3 < 0.0 || (v4 = v3, v3 <= 100.0) )
      v3 = v4;
    else
      v3 = FLOAT_100_0;
  }
  if ( v3 != v6->m_PriorityInfoCurrent.currentPriority.priority )
  {
    v12 = v6->m_pAMLimiter;
    if ( v12 )
      CAkLimiter::Update(v12, v3, v6);
    v13 = v6->m_pBusLimiter;
    if ( v13 )
      CAkLimiter::Update(v13, v3, v6);
    CAkLimiter::Update(&CAkURenderer::m_GlobalLimiter, v3, v6);
    v6->m_PriorityInfoCurrent.currentPriority.priority = v3;
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
  if ( *((_BYTE *)&this->m_p3DSound->m_Params + 68) & 8 )
    v2 = *((_BYTE *)&this->m_pGameObj->m_PosKeep.0 + 11);
  else
    v2 = *((_BYTE *)&this->m_cachedGameObjectPosition.0 + 11);
  return (v2 & 7) == 1;
}

// File Line: 1688
// RVA: 0xA81480
signed __int64 __fastcall CAkPBI::GetGameObjectPosition(CAkPBI *this, unsigned int in_uIndex, AkSoundPosition *out_position)
{
  CAkRegisteredObj *v3; // r9
  AkSoundPosition *v4; // r10
  unsigned __int16 v5; // ax
  __int64 v6; // r8
  signed __int64 v7; // rcx
  AkSoundPosition *v8; // rdx
  signed __int64 result; // rax
  _DWORD *v10; // r8

  v3 = this->m_pGameObj;
  v4 = out_position;
  v5 = 1;
  v6 = in_uIndex;
  if ( *((_BYTE *)&v3->m_PosKeep.0 + 11) & 7 )
    v5 = v3->m_PosKeep.m_uNumPos;
  if ( (unsigned int)v6 >= v5 )
    return 2i64;
  v7 = in_uIndex;
  v8 = &g_DefaultSoundPosition;
  if ( v3->m_PosKeep.m_aPos )
    v8 = v3->m_PosKeep.m_aPos;
  result = 1i64;
  v10 = (_DWORD *)&v8[v6].Position.X;
  v4->Position.X = v8[v7].Position.X;
  v4->Position.Y = (float)v10[1];
  v4->Position.Z = (float)v10[2];
  v4->Orientation.X = (float)v10[3];
  v4->Orientation.Y = (float)v10[4];
  v4->Orientation.Z = (float)v10[5];
  return result;
}

// File Line: 1701
// RVA: 0xA81500
signed __int64 __fastcall CAkPBI::GetListenerData(CAkPBI *this, unsigned int in_uListenerMask, AkListener *out_listener)
{
  unsigned int v3; // edx
  unsigned __int8 i; // al

  v3 = this->m_pGameObj->m_PosKeep.m_uListenerMask & in_uListenerMask;
  if ( !v3 )
    return 2i64;
  for ( i = 0; !(v3 & 1); ++i )
    v3 >>= 1;
  out_listener->position.OrientationFront.X = *(float *)&(&CAkListener::m_listeners.vfptr)[18 * i];
  out_listener->position.OrientationFront.Y = *((float *)&(&CAkListener::m_listeners.vfptr)[18 * i] + 1);
  out_listener->position.OrientationFront.Z = *((float *)&CAkListener::m_listeners.m_memSizeAndFlags + 36 * i);
  out_listener->position.OrientationTop.X = *(float *)(&CAkListener::m_listeners.m_referenceCount + 72 * i + 1);
  out_listener->position.OrientationTop.Y = *((float *)&CAkListener::m_listeners + 36 * i + 4);
  out_listener->position.OrientationTop.Z = *((float *)&CAkListener::m_listeners + 36 * i + 5);
  out_listener->position.Position.X = *((float *)&CAkListener::m_listeners + 36 * i + 6);
  out_listener->position.Position.Y = *((float *)&CAkListener::m_listeners + 36 * i + 7);
  out_listener->position.Position.Z = *((float *)&CAkListener::m_listeners + 36 * i + 8);
  out_listener->fScalingFactor = *((float *)&CAkListener::m_listeners + 36 * i + 9);
  *(_DWORD *)&out_listener->bSpatialized = *((_DWORD *)&CAkListener::m_listeners + 36 * i + 10);
  return 1i64;
}

// File Line: 1728
// RVA: 0xA800D0
float __fastcall ComputeRay(AkListenerData *in_listenerData, AkSoundPosition *in_emitterPosition, float in_fGameObjectScalingFactor, bool in_bComputePositionAngles, bool in_bComputeEmitterDirectionAngle, AkRayVolumeData *out_ray)
{
  AkSoundPosition *v6; // rbp
  float *v7; // rsi
  float v8; // xmm1_4
  bool v9; // bl
  float v10; // xmm0_4
  float v11; // xmm9_4
  float v12; // xmm10_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm6_4
  float v16; // xmm8_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  AkVector Vector1; // [rsp+20h] [rbp-68h]

  v6 = in_emitterPosition;
  v7 = &in_listenerData->position.OrientationFront.X;
  v8 = in_emitterPosition->Position.Y - in_listenerData->position.Position.Y;
  v9 = in_bComputePositionAngles;
  Vector1.X = in_emitterPosition->Position.X - in_listenerData->position.Position.X;
  v10 = in_emitterPosition->Position.Z;
  Vector1.Y = v8;
  Vector1.Z = v10 - in_listenerData->position.Position.Z;
  v11 = AkMath::Magnitude(&Vector1);
  v12 = v11 / (float)(in_fGameObjectScalingFactor * v7[9]);
  out_ray->r = v12;
  if ( v9 )
  {
    v13 = (float)((float)(Vector1.Y * v7[21]) + (float)(Vector1.X * v7[20])) + (float)(Vector1.Z * v7[22]);
    v14 = (float)((float)(Vector1.Y * v7[27]) + (float)(Vector1.X * v7[26])) + (float)(Vector1.Z * v7[28]);
    v15 = (float)((float)(Vector1.Y * v7[24]) + (float)(Vector1.X * v7[23])) + (float)(Vector1.Z * v7[25]);
    if ( v14 == 0.0 )
    {
      if ( v13 == 0.0 )
      {
        v16 = 0.0;
        v17 = 0.0;
LABEL_10:
        *((_BYTE *)&out_ray->0 + 16) |= 2u;
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
      || (LODWORD(v18) = COERCE_UNSIGNED_INT(AkMath::DotProduct(&Vector1, &v6->Orientation) / v11) ^ _xmm[0], v18 >= 1.0) )
    {
      v18 = *(float *)&FLOAT_1_0;
    }
    else if ( v18 <= -1.0 )
    {
      v18 = FLOAT_N1_0;
    }
    v19 = acosf(v18);
    *((_BYTE *)&out_ray->0 + 16) |= 1u;
    out_ray->fEmitterAngle = v19;
  }
  return v12;
}

// File Line: 1787
// RVA: 0xA81210
signed __int64 __fastcall CAkPBI::GetEmitterListenerPair(CAkPBI *this, unsigned int in_uIndex, AkEmitterListenerPair *out_emitterListenerPair)
{
  CAkRegisteredObj *v3; // rbx
  bool v4; // si
  char v5; // r10
  AkEmitterListenerPair *v6; // rdi
  unsigned int v7; // er9
  CAkPBI *v8; // r15
  bool in_bComputeEmitterDirectionAngle; // r14
  AkEmitterListenerPairEx *v10; // r11
  int v11; // er8
  AkEmitterListenerPairEx *v12; // rax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  signed __int64 result; // rax
  int v18; // eax
  unsigned int v19; // ecx
  unsigned int v20; // edx
  __int64 v21; // r10
  __int64 v22; // r8
  AkSoundPosition *v23; // rdx
  float v24; // xmm1_4
  CAkRegisteredObj *v25; // rcx
  float v26; // xmm0_4
  float v27; // xmm1_4
  AkRayVolumeData out_ray; // [rsp+30h] [rbp-30h]

  v3 = this->m_pGameObj;
  v4 = 1;
  v5 = *((_BYTE *)&out_ray.0 + 16) & 0xFC;
  *(_QWORD *)&out_ray.phi = 0i64;
  out_ray.0 = 0i64;
  out_ray.m_uListenerMask = 0;
  out_ray.fDryMixGain = 1.0;
  out_ray.fGameDefAuxMixGain = 1.0;
  *((_BYTE *)&out_ray.0 + 16) &= 0xFCu;
  out_ray.fUserDefAuxMixGain = 1.0;
  out_ray.fConeInterp = 1.0;
  v6 = out_emitterListenerPair;
  v7 = in_uIndex;
  v8 = this;
  in_bComputeEmitterDirectionAngle = 1;
  if ( ~(unsigned __int8)(*((_DWORD *)v3 + 30) >> 30) & 1 )
  {
    v10 = v3->m_arCachedEmitListPairs.m_pItems;
    v11 = 0;
    v12 = v3->m_arCachedEmitListPairs.m_pItems;
    if ( in_uIndex )
    {
      do
      {
        if ( v12 == &v10[v3->m_arCachedEmitListPairs.m_uLength] )
          break;
        ++v11;
        ++v12;
      }
      while ( v11 != in_uIndex );
    }
    if ( v12 != &v10[v3->m_arCachedEmitListPairs.m_uLength] )
    {
      v13 = v12->r;
      out_ray.r = v12->r;
      v14 = v12->theta;
      out_ray.theta = v12->theta;
      v15 = v12->phi;
      out_ray.phi = v12->phi;
      v16 = v12->fEmitterAngle;
      out_ray.fEmitterAngle = v12->fEmitterAngle;
      *((_BYTE *)&out_ray.0 + 16) = (*((_BYTE *)v12 + 16) ^ v5) & 1 ^ v5;
      *((_BYTE *)&out_ray.0 + 16) ^= (*((_BYTE *)v12 + 16) ^ *((_BYTE *)&out_ray.0 + 16)) & 2;
      in_bComputeEmitterDirectionAngle = ~*((_BYTE *)&out_ray.0 + 16) & 1;
      out_ray.m_uListenerMask = v12->m_uListenerMask;
      v4 = ~(*((_BYTE *)&out_ray.0 + 16) >> 1) & 1;
      if ( !v4 && !in_bComputeEmitterDirectionAngle )
      {
        v6->r = v13;
        v6->theta = v14;
        v6->phi = v15;
        result = 1i64;
        v6->fEmitterAngle = v16;
        return result;
      }
    }
  }
  v18 = 0;
  LOWORD(v19) = 1;
  if ( *((_BYTE *)&v3->m_PosKeep.0 + 11) & 7 )
    LOWORD(v19) = v3->m_PosKeep.m_uNumPos;
  v20 = (unsigned __int8)v3->m_PosKeep.m_uListenerMask;
  v21 = 0i64;
  v19 = (unsigned __int16)v19;
  if ( !v3->m_PosKeep.m_uListenerMask )
    return 2i64;
  while ( !(v20 & 1) )
  {
    v20 >>= 1;
    v21 = (unsigned int)(v21 + 1);
LABEL_17:
    if ( !v20 )
      return 2i64;
  }
  v22 = 0i64;
  if ( !v19 )
    goto LABEL_17;
  while ( v7 != v18 )
  {
    v22 = (unsigned int)(v22 + 1);
    ++v18;
    if ( (unsigned int)v22 >= v19 )
      goto LABEL_17;
  }
  v23 = &g_DefaultSoundPosition;
  out_ray.m_uListenerMask = 1 << v21;
  if ( v3->m_PosKeep.m_aPos )
    v23 = v3->m_PosKeep.m_aPos;
  ComputeRay(
    (AkListenerData *)&CAkListener::m_listeners + v21,
    &v23[v22],
    v3->m_fScalingFactor,
    v4,
    in_bComputeEmitterDirectionAngle,
    &out_ray);
  v24 = out_ray.theta;
  v25 = v8->m_pGameObj;
  v6->r = out_ray.r;
  v26 = out_ray.phi;
  v6->theta = v24;
  v27 = out_ray.fEmitterAngle;
  v6->phi = v26;
  v6->fEmitterAngle = v27;
  CAkRegisteredObj::CacheEmitListenPair(v25, (AkEmitterListenerPairEx *)&out_ray.0);
  return 1i64;
}

// File Line: 1879
// RVA: 0xA802D0
__int64 __fastcall CAkPBI::ComputeVolumeData3D(CAkPBI *this, AkPositionSourceType in_eType, AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *out_arVolumeData)
{
  unsigned int v3; // er15
  AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v4; // r13
  AkPositionSourceType v5; // ebx
  CAkGen3DParams *v6; // r14
  CAkPBI *v7; // rbp
  CAkAttenuation *v8; // rax
  bool v9; // r12
  CAkRegisteredObj *v10; // rdx
  signed __int64 v11; // rcx
  CAkRegisteredObj *v12; // rdi
  float v13; // xmm6_4
  char v14; // al
  AkEmitterListenerPairEx *v15; // rbx
  char v16; // cl
  AkRayVolumeData *v17; // rax
  signed __int64 v18; // rax
  unsigned __int16 v19; // cx
  unsigned int v20; // er12
  unsigned int v21; // er8
  int v22; // edx
  int v23; // ecx
  unsigned int v24; // eax
  unsigned int v25; // edx
  unsigned int v27; // ecx
  AkListenerData *v28; // rdi
  __int64 v29; // rbx
  __int64 v30; // rsi
  AkRayVolumeData *out_ray; // r8
  bool v32; // r9
  AkSoundPosition *v33; // rdx
  float v34; // xmm0_4
  CAkPath *v35; // rcx
  bool v36; // bl
  CAkPath *v37; // rcx
  AkPathState *v38; // rax
  CAkRegisteredObj *v39; // rax
  unsigned int v40; // edi
  float v41; // xmm11_4
  float v42; // xmm10_4
  AkRayVolumeData *v43; // rax
  AkRayVolumeData *v44; // rbx
  float v45; // xmm9_4
  char v46; // al
  char v47; // dl
  CAkPath *v48; // rax
  float *v49; // rax
  float v50; // xmm9_4
  float v51; // xmm2_4
  float v52; // xmm13_4
  float v53; // xmm4_4
  float v54; // xmm14_4
  float v55; // xmm11_4
  float v56; // xmm7_4
  float v57; // xmm12_4
  float v58; // xmm8_4
  float v59; // xmm6_4
  float v60; // xmm10_4
  float v61; // xmm5_4
  float v62; // xmm9_4
  float v63; // xmm2_4
  float v64; // xmm3_4
  float v65; // xmm9_4
  float v66; // xmm5_4
  float v67; // xmm0_4
  float v68; // xmm15_4
  float v69; // xmm2_4
  float v70; // xmm9_4
  float v71; // ST30_4
  float v72; // xmm15_4
  float v73; // xmm3_4
  float v74; // xmm13_4
  float v75; // xmm4_4
  float v76; // xmm0_4
  float v77; // xmm1_4
  float v78; // xmm3_4
  float v79; // xmm5_4
  float v80; // xmm2_4
  float v81; // xmm4_4
  float v82; // xmm1_4
  float v83; // xmm6_4
  float v84; // xmm6_4
  float v85; // xmm8_4
  float v86; // xmm13_4
  float v87; // xmm8_4
  float v88; // xmm0_4
  float v89; // xmm0_4
  float v90; // xmm0_4
  char v91; // [rsp+30h] [rbp-118h]
  AkSoundPosition **v92; // [rsp+38h] [rbp-110h]
  float v93; // [rsp+38h] [rbp-110h]
  AkVector Vector1; // [rsp+40h] [rbp-108h]
  AkVector Vector2; // [rsp+50h] [rbp-F8h]
  unsigned int i; // [rsp+150h] [rbp+8h]
  float v97; // [rsp+150h] [rbp+8h]
  bool in_bComputeEmitterDirectionAngle; // [rsp+158h] [rbp+10h]
  int v99; // [rsp+158h] [rbp+10h]
  unsigned int v100; // [rsp+160h] [rbp+18h]
  float v101; // [rsp+160h] [rbp+18h]
  unsigned int v102; // [rsp+168h] [rbp+20h]
  float v103; // [rsp+168h] [rbp+20h]

  v3 = 0;
  v4 = out_arVolumeData;
  v5 = in_eType;
  out_arVolumeData->m_uLength = 0;
  v6 = this->m_p3DSound;
  v7 = this;
  if ( !v6->m_Params.m_pAttenuation )
    v6->m_Params.m_pAttenuation = (CAkAttenuation *)CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                                                      (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxAttenuations,
                                                      v6->m_Params.m_uAttenuationID);
  v8 = v6->m_Params.m_pAttenuation;
  v9 = v8 && *((_BYTE *)v8 + 125) & 1;
  in_bComputeEmitterDirectionAngle = v9;
  if ( v5 != 1 )
  {
    v35 = v7->m_PathInfo.pPBPath;
    if ( v35 )
    {
      v36 = (*((_BYTE *)&v6->m_Params + 68) >> 5) & 1;
      CAkPath::SetIsLooping(v35, v36);
      if ( v36 )
      {
        v37 = v7->m_PathInfo.pPBPath;
        if ( ((unsigned int)v37->m_PathMode >> 1) & 1 )
        {
          if ( CAkPath::IsIdle(v37) )
          {
            v38 = CAkParameterNode::GetPathState((CAkParameterNode *)&v7->m_pSound->vfptr);
            CAkPathManager::Start(g_pPathManager, v7->m_PathInfo.pPBPath, v38);
          }
        }
      }
    }
    v39 = v7->m_pGameObj;
    v40 = (unsigned __int8)v39->m_PosKeep.m_uListenerMask;
    if ( !v39->m_PosKeep.m_uListenerMask )
      return v4->m_uLength;
    v41 = *(float *)&FLOAT_1_0;
    v42 = FLOAT_N1_0;
    v99 = 0;
    while ( !(v40 & 1) )
    {
      v40 >>= 1;
      ++v3;
LABEL_89:
      if ( !v40 )
        return v4->m_uLength;
    }
    v43 = AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(v4);
    v44 = v43;
    if ( !v43 )
      return v4->m_uLength;
    v43->m_uListenerMask = 1 << v3;
    v45 = AkMath::Magnitude(&v6->m_Params.m_Position);
    v93 = v45;
    v44->r = v45 / (float)(v7->m_pGameObj->m_fScalingFactor * *((float *)&CAkListener::m_listeners + 36 * v3 + 9));
    v46 = *((_BYTE *)&v6->m_Params + 68);
    if ( v46 & 1 && *((_BYTE *)&CAkListener::m_listeners + 144 * v3 + 40) )
    {
      v47 = 1;
    }
    else
    {
      v47 = 0;
      if ( !v9 )
      {
LABEL_88:
        ++v3;
        v40 >>= 1;
        goto LABEL_89;
      }
    }
    if ( v46 & 0x10 || (v48 = v7->m_PathInfo.pPBPath) == 0i64 )
    {
      v85 = v6->m_Params.m_Position.X;
      v84 = v6->m_Params.m_Position.Y;
      v86 = v6->m_Params.m_Position.Z;
    }
    else
    {
      v49 = v48->m_pNoFollowOrientationRotation;
      v50 = *((float *)&CAkListener::m_listeners + 36 * v3 + 21);
      v51 = *((float *)&CAkListener::m_listeners + 36 * v3 + 20);
      v52 = v49[v99 + 3];
      v53 = v49[v99];
      v54 = v49[v99 + 6];
      v55 = v49[v99 + 4];
      v56 = v49[v99 + 1];
      v57 = v49[v99 + 7];
      v58 = v49[v99 + 5];
      v59 = v49[v99 + 2];
      v60 = v49[v99 + 8];
      v97 = (float)((float)(*((float *)&CAkListener::m_listeners + 36 * v3 + 20) * v53)
                  + (float)(*((float *)&CAkListener::m_listeners + 36 * v3 + 21) * v52))
          + (float)(*((float *)&CAkListener::m_listeners + 36 * v3 + 22) * v54);
      v61 = (float)(v51 * v56) + (float)(v50 * v55);
      v62 = (float)(v50 * v58) + (float)(v51 * v59);
      v63 = *((float *)&CAkListener::m_listeners + 36 * v3 + 24);
      v64 = *((float *)&CAkListener::m_listeners + 36 * v3 + 25);
      v101 = v61 + (float)(*((float *)&CAkListener::m_listeners + 36 * v3 + 22) * v57);
      v103 = v62 + (float)(*((float *)&CAkListener::m_listeners + 36 * v3 + 22) * v60);
      v65 = *((float *)&CAkListener::m_listeners + 36 * v3 + 23);
      v66 = (float)(v65 * v53) + (float)(*((float *)&CAkListener::m_listeners + 36 * v3 + 24) * v52);
      v67 = v63 * v55;
      v68 = (float)(v65 * v59) + (float)(v63 * v58);
      v69 = *((float *)&CAkListener::m_listeners + 36 * v3 + 27);
      v70 = (float)((float)(v65 * v56) + v67) + (float)(v64 * v57);
      v71 = v66 + (float)(*((float *)&CAkListener::m_listeners + 36 * v3 + 25) * v54);
      v72 = v68 + (float)(v64 * v60);
      v73 = *((float *)&CAkListener::m_listeners + 36 * v3 + 28);
      v74 = (float)((float)(*((float *)&CAkListener::m_listeners + 36 * v3 + 26) * v53) + (float)(v69 * v52))
          + (float)(*((float *)&CAkListener::m_listeners + 36 * v3 + 28) * v54);
      v75 = (float)(*((float *)&CAkListener::m_listeners + 36 * v3 + 26) * v56) + (float)(v69 * v55);
      v76 = v6->m_Params.m_Position.X;
      v41 = *(float *)&FLOAT_1_0;
      v77 = v73;
      v78 = v73 * v60;
      v99 += 9;
      v42 = FLOAT_N1_0;
      v79 = (float)(*((float *)&CAkListener::m_listeners + 36 * v3 + 26) * v59) + (float)(v69 * v58);
      v80 = v6->m_Params.m_Position.Z;
      v81 = v75 + (float)(v77 * v57);
      v82 = v6->m_Params.m_Position.Y;
      v83 = (float)(v71 * v76) + (float)(v70 * v82);
      v45 = v93;
      v84 = v83 + (float)(v72 * v80);
      v85 = (float)((float)(v97 * v76) + (float)(v101 * v82)) + (float)(v103 * v80);
      v86 = (float)((float)(v74 * v76) + (float)(v81 * v82)) + (float)((float)(v79 + v78) * v80);
    }
    Vector1.Z = v86;
    Vector1.Y = v84;
    Vector1.X = v85;
    if ( !v47 )
    {
LABEL_81:
      if ( v9 )
      {
        if ( v45 <= 0.0
          || (*(_QWORD *)&Vector2.X = 0i64,
              Vector2.Z = 1.0,
              v89 = AkMath::DotProduct(&Vector1, &Vector2) / v45,
              v89 >= v41) )
        {
          v89 = v41;
        }
        else if ( v89 <= v42 )
        {
          v89 = v42;
        }
        v90 = acosf(v89);
        *((_BYTE *)&v44->0 + 16) |= 1u;
        v44->fEmitterAngle = v90;
      }
      goto LABEL_88;
    }
    if ( v86 == 0.0 )
    {
      if ( v85 == 0.0 )
      {
        v87 = 0.0;
        v88 = 0.0;
LABEL_80:
        *((_BYTE *)&v44->0 + 16) |= 2u;
        v44->theta = v87;
        v44->phi = v88;
        goto LABEL_81;
      }
      if ( v85 <= 0.0 )
        v87 = FLOAT_N1_5707964;
      else
        v87 = FLOAT_1_5707964;
    }
    else
    {
      v87 = atan2f(v85, v86);
    }
    v88 = asinf(v84 / v45);
    goto LABEL_80;
  }
  if ( !(*((_BYTE *)&v6->m_Params + 68) & 8) && !(*((_BYTE *)v7 + 372) & 0x40) )
  {
    v10 = v7->m_pGameObj;
    v11 = (signed __int64)&v7->m_cachedGameObjectPosition;
    *(_BYTE *)(v11 + 10) = v10->m_PosKeep.m_uListenerMask;
    *(_BYTE *)(v11 + 11) ^= (*((_BYTE *)&v7->m_cachedGameObjectPosition.0 + 11) ^ *((_BYTE *)&v10->m_PosKeep.0 + 11)) & 7;
    if ( (unsigned int)AkPositionKeeper::SetPosition(
                         &v7->m_cachedGameObjectPosition,
                         v10->m_PosKeep.m_aPos,
                         v10->m_PosKeep.m_uNumPos) == 1 )
      *((_BYTE *)v7 + 372) |= 0x40u;
  }
  v12 = v7->m_pGameObj;
  v13 = FLOAT_1_0e10;
  if ( ~(unsigned __int8)(*((_DWORD *)v12 + 30) >> 30) & 1
    && (v14 = *((_BYTE *)&v6->m_Params + 68), v14 & 8)
    && ((v15 = v12->m_arCachedEmitListPairs.m_pItems, v16 = *((_BYTE *)v15 + 16), v16 & 2) || !(v14 & 1))
    && (v16 & 1 || !v9) )
  {
    do
    {
      v17 = AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(v4);
      if ( !v17 )
        break;
      v17->r = v15->r;
      v17->theta = v15->theta;
      v17->phi = v15->phi;
      v17->fEmitterAngle = v15->fEmitterAngle;
      *((_BYTE *)&v17->0 + 16) ^= (*((_BYTE *)v15 + 16) ^ *((_BYTE *)&v17->0 + 16)) & 1;
      *((_BYTE *)&v17->0 + 16) ^= (*((_BYTE *)v15 + 16) ^ *((_BYTE *)&v17->0 + 16)) & 2;
      v17->m_uListenerMask = v15->m_uListenerMask;
      if ( v15->r < v13 )
        v13 = v15->r;
      ++v15;
    }
    while ( v15 != &v12->m_arCachedEmitListPairs.m_pItems[v12->m_arCachedEmitListPairs.m_uLength] );
    CAkPBI::ComputePriorityOffset(v7, v13, &v6->m_Params);
  }
  else
  {
    v18 = (signed __int64)&v12->m_PosKeep;
    if ( !(*((_BYTE *)&v6->m_Params + 68) & 8) )
      v18 = (signed __int64)&v7->m_cachedGameObjectPosition;
    v92 = (AkSoundPosition **)v18;
    v19 = 1;
    if ( *(_BYTE *)(v18 + 11) & 7 )
      v19 = *(_WORD *)(v18 + 8);
    v20 = *(unsigned __int8 *)(v18 + 10);
    v21 = v19;
    v22 = 0;
    v102 = v19;
    v100 = *(unsigned __int8 *)(v18 + 10);
    v23 = *(unsigned __int8 *)(v18 + 10);
    if ( *(_BYTE *)(v18 + 10) )
    {
      do
      {
        ++v22;
        v23 &= v23 - 1;
      }
      while ( v23 );
    }
    v24 = v4->m_ulReserved;
    v25 = v21 * v22;
    if ( v25 > v24 )
    {
      if ( !AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(
              v4,
              v25 - v24) )
        return 0i64;
      v21 = v102;
    }
    v27 = 0;
    for ( i = 0; v20; i = v27 )
    {
      if ( v20 & 1 )
      {
        v91 = 1 << v27;
        v28 = (AkListenerData *)(&CAkListener::m_listeners + 9 * v27);
        if ( v21 )
        {
          v29 = 0i64;
          v30 = v21;
          do
          {
            out_ray = AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(v4);
            out_ray->m_uListenerMask = v91;
            v32 = *((_BYTE *)&v6->m_Params + 68) & 1 && v28->bSpatialized;
            v33 = &g_DefaultSoundPosition;
            if ( *v92 )
              v33 = *v92;
            v34 = ComputeRay(
                    v28,
                    &v33[v29],
                    v7->m_pGameObj->m_fScalingFactor,
                    v32,
                    in_bComputeEmitterDirectionAngle,
                    out_ray);
            if ( v34 < v13 )
              v13 = v34;
            ++v29;
            --v30;
          }
          while ( v30 );
          v20 = v100;
          v27 = i;
          v21 = v102;
        }
        ++v27;
        v20 >>= 1;
      }
      else
      {
        v20 >>= 1;
        ++v27;
      }
      v100 = v20;
    }
    if ( *((_BYTE *)&v6->m_Params + 68) & 8 )
      CAkRegisteredObj::CacheEmitListenPairs(v7->m_pGameObj, v4);
    CAkPBI::ComputePriorityOffset(v7, v13, &v6->m_Params);
  }
  return v4->m_uLength;
}

// File Line: 2115
// RVA: 0xA83260
void __fastcall CAkPBI::VirtualPositionUpdate(CAkPBI *this)
{
  char v1; // al
  CAkPBI *v2; // rdi
  CAkRegisteredObj *v3; // rax
  float v4; // xmm6_4
  float v5; // xmm0_4
  CAkPath *v6; // rcx
  bool v7; // bl
  CAkPath *v8; // rcx
  AkPathState *v9; // rax

  v1 = *((_BYTE *)this + 371);
  v2 = this;
  if ( v1 & 3 )
  {
    if ( (v1 & 0xC) == 4 )
    {
      if ( *((_BYTE *)&this->m_p3DSound->m_Params + 68) & 8 || !(*((_BYTE *)this + 372) & 0x40) )
      {
        v3 = this->m_pGameObj;
        v4 = v3->m_fScalingFactor;
        v5 = CAkURenderer::GetMinDistance((AkSoundPositionRef *)&v3->m_PosKeep.m_aPos);
        CAkPBI::ComputePriorityOffset(v2, v5 / v4, &v2->m_p3DSound->m_Params);
      }
    }
    else
    {
      v6 = this->m_PathInfo.pPBPath;
      if ( v6 )
      {
        v7 = (*((_BYTE *)&v2->m_p3DSound->m_Params + 68) >> 5) & 1;
        CAkPath::SetIsLooping(v6, v7);
        if ( v7 )
        {
          v8 = v2->m_PathInfo.pPBPath;
          if ( ((unsigned int)v8->m_PathMode >> 1) & 1 )
          {
            if ( CAkPath::IsIdle(v8) )
            {
              v9 = CAkParameterNode::GetPathState((CAkParameterNode *)&v2->m_pSound->vfptr);
              CAkPathManager::Start(g_pPathManager, v2->m_PathInfo.pPBPath, v9);
            }
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
bool __fastcall CAkPBI::IsInitiallyUnderThreshold(CAkPBI *this, AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *__formal)
{
  CAkPBI *v2; // rbx
  CAkBus *v3; // rdi
  float v4; // xmm6_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  int v7; // edx
  float v8; // xmm1_4
  float v9; // xmm8_4
  float v10; // xmm8_4
  signed __int64 v11; // rcx
  unsigned int *v12; // rax
  float v13; // xmm7_4
  CAkBus *v14; // rbx
  float v15; // xmm7_4
  bool v16; // cf

  v2 = this;
  if ( !(*((_BYTE *)this + 372) & 0x20) )
    ((void (__fastcall *)(CAkPBI *, AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *))this->vfptr[7].~CAkTransportAware)(
      this,
      __formal);
  v3 = v2->m_pControlBus;
  v4 = 0.0;
  v5 = 0.0;
  if ( v3 )
  {
    if ( !(*((_BYTE *)v3 + 304) & 1) )
      CAkBus::UpdateVoiceVolumes(v2->m_pControlBus);
    v5 = v3->m_fEffectiveVoiceVolume;
  }
  v6 = FLOAT_1_0653532e9;
  v7 = `AkMath::FastPow10'::`4'::`local static guard';
  v8 = (float)(v5 + v2->m_EffectiveParams.Volume) * 0.050000001;
  if ( v8 >= -37.0 )
  {
    if ( !(`AkMath::FastPow10'::`4'::`local static guard' & 1) )
    {
      v7 = `AkMath::FastPow10'::`4'::`local static guard' | 1;
      `AkMath::FastPow10'::`4'::SCALE = 1272224376;
      `AkMath::FastPow10'::`4'::`local static guard' |= 1u;
    }
    v9 = (float)((float)((float)((float)(COERCE_FLOAT(
                                           ((signed int)(float)((float)(*(float *)&`AkMath::FastPow10'::`4'::SCALE * v8)
                                                              + 1065353200.0) & 0x7FFFFF)
                                         + 1065353216)
                                       * 0.32518977)
                               + 0.020805772)
                       * COERCE_FLOAT(
                           ((signed int)(float)((float)(*(float *)&`AkMath::FastPow10'::`4'::SCALE * v8) + 1065353200.0) & 0x7FFFFF)
                         + 1065353216))
               + 0.65304345)
       * COERCE_FLOAT((signed int)(float)((float)(*(float *)&`AkMath::FastPow10'::`4'::SCALE * v8) + 1065353200.0) & 0xFF800000);
  }
  else
  {
    v9 = 0.0;
  }
  v10 = v9 * v2->m_EffectiveParams.fFadeRatio;
  if ( !v2->m_EffectiveParams.bGameDefinedAuxEnabled )
  {
    v11 = 0i64;
    v12 = v2->m_EffectiveParams.aAuxSend;
    while ( !*v12 )
    {
      ++v11;
      ++v12;
      if ( v11 >= 4 )
      {
        v13 = v2->m_EffectiveParams.fOutputBusVolume;
        v14 = v2->m_pControlBus;
        if ( v14 )
        {
          if ( !(*((_BYTE *)v14 + 304) & 1) )
          {
            CAkBus::UpdateVoiceVolumes(v14);
            v7 = `AkMath::FastPow10'::`4'::`local static guard';
            v6 = FLOAT_1_0653532e9;
          }
          v13 = v13 + v14->m_fEffectiveBusVolume;
        }
        v15 = v13 * 0.050000001;
        if ( v15 >= -37.0 )
        {
          if ( !(v7 & 1) )
          {
            `AkMath::FastPow10'::`4'::SCALE = 1272224376;
            `AkMath::FastPow10'::`4'::`local static guard' = v7 | 1;
          }
          v4 = (float)((float)((float)((float)(COERCE_FLOAT(
                                                 ((signed int)(float)((float)(v15
                                                                            * *(float *)&`AkMath::FastPow10'::`4'::SCALE)
                                                                    + v6) & 0x7FFFFF)
                                               + 1065353216)
                                             * 0.32518977)
                                     + 0.020805772)
                             * COERCE_FLOAT(
                                 ((signed int)(float)((float)(v15 * *(float *)&`AkMath::FastPow10'::`4'::SCALE) + v6) & 0x7FFFFF)
                               + 1065353216))
                     + 0.65304345)
             * COERCE_FLOAT((signed int)(float)((float)(v15 * *(float *)&`AkMath::FastPow10'::`4'::SCALE) + v6) & 0xFF800000);
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
  float *v2; // r9
  AkAuxSendValueEx *v3; // r10
  int v4; // edx
  unsigned int v5; // er8
  float v6; // xmm2_4
  float v7; // xmm3_4
  unsigned int v8; // er11
  unsigned int v9; // ebx
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  signed __int64 v13; // rax
  float v14; // xmm3_4
  unsigned int v15; // ebx
  char *v16; // r11
  unsigned int v17; // eax
  float v18; // xmm1_4
  signed __int64 v19; // r9
  float v20; // xmm1_4
  _DWORD *v21; // rax
  __int64 v22; // rcx

  v2 = (float *)this->m_pGameObj->m_EnvironmentValues;
  v3 = io_paEnvVal;
  v4 = `AkMath::FastPow10'::`4'::`local static guard';
  v5 = 0;
  v6 = *(float *)&`AkMath::FastPow10'::`4'::SCALE;
  if ( this->m_EffectiveParams.bGameDefinedAuxEnabled )
  {
    v7 = g_fVolumeThreshold;
    v8 = 0;
    do
    {
      v9 = *(_DWORD *)v2;
      if ( !*(_DWORD *)v2 )
        break;
      v10 = this->m_EffectiveParams.fGameAuxSendVolume * 0.050000001;
      if ( v10 >= -37.0 )
      {
        if ( !(v4 & 1) )
        {
          v6 = FLOAT_2_7866352e7;
          v4 |= 1u;
          `AkMath::FastPow10'::`4'::`local static guard' = v4;
          `AkMath::FastPow10'::`4'::SCALE = LODWORD(FLOAT_2_7866352e7);
        }
        v11 = (float)((float)((float)((float)(COERCE_FLOAT(
                                                ((signed int)(float)((float)(v6 * v10) + 1065353200.0) & 0x7FFFFF)
                                              + 1065353216)
                                            * 0.32518977)
                                    + 0.020805772)
                            * COERCE_FLOAT(((signed int)(float)((float)(v6 * v10) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                    + 0.65304345)
            * COERCE_FLOAT((signed int)(float)((float)(v6 * v10) + 1065353200.0) & 0xFF800000);
      }
      else
      {
        v11 = 0.0;
      }
      v12 = v11 * v2[1];
      if ( v12 > v7 )
      {
        v13 = v5++;
        v3[v13].auxBusID = v9;
        v3[v13].eAuxType = 0;
        v3[v13].fControlValue = v12;
      }
      ++v8;
      v2 += 2;
    }
    while ( v8 < 4 );
  }
  v14 = g_fVolumeThresholdDB;
  v15 = 0;
  v16 = (char *)this->m_EffectiveParams.aUserAuxSendVolume;
  while ( v5 < 8 )
  {
    v17 = *((_DWORD *)v16 + 4);
    if ( v17 && *(float *)v16 > v14 )
    {
      v18 = *(float *)v16 * 0.050000001;
      v19 = v5;
      v3[v19].auxBusID = v17;
      if ( v18 >= -37.0 )
      {
        if ( !(v4 & 1) )
        {
          v6 = FLOAT_2_7866352e7;
          v4 |= 1u;
          `AkMath::FastPow10'::`4'::`local static guard' = v4;
          `AkMath::FastPow10'::`4'::SCALE = LODWORD(FLOAT_2_7866352e7);
        }
        v20 = (float)((float)((float)((float)(COERCE_FLOAT(
                                                ((signed int)(float)((float)(v6 * v18) + 1065353200.0) & 0x7FFFFF)
                                              + 1065353216)
                                            * 0.32518977)
                                    + 0.020805772)
                            * COERCE_FLOAT(((signed int)(float)((float)(v6 * v18) + 1065353200.0) & 0x7FFFFF) + 1065353216))
                    + 0.65304345)
            * COERCE_FLOAT((signed int)(float)((float)(v6 * v18) + 1065353200.0) & 0xFF800000);
      }
      else
      {
        v20 = 0.0;
      }
      v3[v19].fControlValue = v20;
      v3[v19].eAuxType = 1;
      ++v5;
    }
    ++v15;
    v16 += 4;
    if ( v15 >= 4 )
    {
      if ( v5 < 8 )
        v3[v5].auxBusID = 0;
      break;
    }
  }
  if ( *((_BYTE *)this + 375) & 0x10 && v5 )
  {
    v21 = (_DWORD *)&v3->fControlValue;
    v22 = v5;
    do
    {
      *v21 = 0;
      v21 += 8;
      --v22;
    }
    while ( v22 );
  }
}

// File Line: 2236
// RVA: 0xA82CD0
signed int __fastcall CAkPBI::SubscribeAttenuationRTPC(CAkPBI *this, CAkAttenuation *in_pAttenuation)
{
  CAkAttenuation::RTPCSubs *v2; // rax
  CAkAttenuation *v3; // rdi
  CAkPBI *v4; // rsi
  signed __int64 v5; // rbx
  signed int result; // eax

  v2 = in_pAttenuation->m_rtpcsubs.m_pItems;
  v3 = in_pAttenuation;
  v4 = this;
  if ( v2 == &v2[in_pAttenuation->m_rtpcsubs.m_uLength] )
    return 1;
  v5 = (signed __int64)&v2->ConversionTable;
  do
  {
    result = CAkRTPCMgr::SubscribeRTPC(
               g_pRTPCMgr,
               v4,
               *(_DWORD *)(v5 - 16),
               *(AkRTPC_ParameterID *)(v5 - 12),
               *(_DWORD *)(v5 - 8),
               *(AkCurveScaling *)(v5 + 12),
               *(AkRTPCGraphPointBase<float> **)v5,
               *(_DWORD *)(v5 + 8),
               v4->m_pGameObj,
               SubscriberType_PBI);
    if ( result != 1 )
      break;
    v5 += 32i64;
  }
  while ( (CAkAttenuation::RTPCSubs *)(v5 - 16) != &v3->m_rtpcsubs.m_pItems[v3->m_rtpcsubs.m_uLength] );
  return result;
}

// File Line: 2261
// RVA: 0xA83080
void __fastcall CAkPBI::UnsubscribeAttenuationRTPC(CAkPBI *this, CAkAttenuation *in_pAttenuation)
{
  CAkAttenuation::RTPCSubs *v2; // rbx
  CAkAttenuation *v3; // rdi
  CAkPBI *v4; // rsi

  v2 = in_pAttenuation->m_rtpcsubs.m_pItems;
  v3 = in_pAttenuation;
  v4 = this;
  if ( v2 != &v2[in_pAttenuation->m_rtpcsubs.m_uLength] )
  {
    do
    {
      CAkRTPCMgr::UnSubscribeRTPC(g_pRTPCMgr, v4, v2->ParamID);
      ++v2;
    }
    while ( v2 != &v3->m_rtpcsubs.m_pItems[v3->m_rtpcsubs.m_uLength] );
  }
}

// File Line: 2287
// RVA: 0xA81E10
void __fastcall CAkPBI::Kick(CAkPBI *this, KickFrom in_eIsForMemoryThreshold)
{
  char v2; // al
  TransParams in_transParams; // [rsp+30h] [rbp+8h]

  v2 = *((_BYTE *)this + 374);
  if ( !(v2 & 1) )
    *((_BYTE *)this + 374) = v2 ^ (v2 ^ 2 * in_eIsForMemoryThreshold) & 0xE | 1;
  in_transParams.TransitionTime = 0;
  in_transParams.eFadeCurve = 4;
  CAkPBI::_Stop(this, &in_transParams, 1);
}

// File Line: 2318
// RVA: 0xA81460
void __fastcall CAkPBI::GetFXDataID(CAkPBI *this, __int64 in_uFXIndex, __int64 in_uDataIndex, unsigned int *out_rDataID)
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
  CAkVPLSrcCbxNodeBase *v2; // rcx

  v2 = this->m_pCbx;
  if ( v2 )
    v2->vfptr->UpdateFx(v2, in_uFXIndex);
}

// File Line: 2357
// RVA: 0xA83180
void __fastcall CAkPBI::ValidateFeedbackParameters(CAkPBI *this)
{
  CAkFeedbackDeviceMgr *v1; // rdi
  CAkPBI *v2; // rbx
  CAkVPLSrcCbxNodeBase *v3; // rax
  int v4; // edx
  AkFeedbackParams *v5; // rdx

  v1 = CAkFeedbackDeviceMgr::s_pSingleton;
  v2 = this;
  if ( CAkFeedbackDeviceMgr::s_pSingleton && CAkFeedbackDeviceMgr::IsFeedbackEnabled(CAkFeedbackDeviceMgr::s_pSingleton) )
  {
    if ( !v2->m_pFeedbackInfo && (((__int64 (*)(void))v2->m_pSound->vfptr[16].Release)() || *((_BYTE *)v2 + 374) < 0) )
    {
      v3 = v2->m_pCbx;
      if ( v3 )
        v4 = HIDWORD(v3[1].vfptr);
      else
        v4 = *((_DWORD *)&v2->m_sMediaFormat + 1) & 0x3FFFF;
      v2->m_pFeedbackInfo = AkFeedbackParams::Create(
                              (unsigned __int8)v1->m_uLastPlayerIndex,
                              v4,
                              (AkPannerType)(*((_BYTE *)v2 + 371) & 3),
                              (AkPositionSourceType)(((unsigned int)*((unsigned __int8 *)v2 + 371) >> 2) & 3));
    }
    v5 = v2->m_pFeedbackInfo;
    if ( v5 )
      ((void (__fastcall *)(CAkSoundBase *, AkFeedbackParams *, CAkSource *, CAkRegisteredObj *, char))v2->m_pSound->vfptr[16].__vecDelDtor)(
        v2->m_pSound,
        v5,
        v2->m_pSource,
        v2->m_pGameObj,
        1);
    *((_BYTE *)v2 + 374) |= 0x40u;
  }
}

// File Line: 2388
// RVA: 0xA81A70
void __fastcall CAkPBI::InvalidateFeedbackParameters(CAkPBI *this)
{
  CAkPBI *v1; // rbx
  AkFeedbackParams *v2; // rcx

  v1 = this;
  v2 = this->m_pFeedbackInfo;
  if ( v2 )
  {
    AkFeedbackParams::Destroy(v2);
    *((_BYTE *)v1 + 374) &= 0xBFu;
    v1->m_pFeedbackInfo = 0i64;
  }
}

// File Line: 2400
// RVA: 0xA81DB0
char __fastcall CAkPBI::IsUsingThisSlot(CAkPBI *this, CAkUsageSlot *in_pSlotToCheck)
{
  CAkUsageSlot *v2; // rdi
  CAkPBI *v3; // rbx
  char result; // al
  CAkVPLSrcCbxNodeBase *v5; // rcx

  v2 = in_pSlotToCheck;
  v3 = this;
  if ( this->m_pUsageSlot == in_pSlotToCheck && !CAkPBI::FindAlternateMedia(this, in_pSlotToCheck) )
    return 1;
  v5 = v3->m_pCbx;
  if ( v5 )
    result = v5->vfptr->IsUsingThisSlot(v5, v2);
  else
    result = 0;
  return result;
}

// File Line: 2446
// RVA: 0xA80D10
char __fastcall CAkPBI::FindAlternateMedia(CAkPBI *this, CAkUsageSlot *in_pSlotToCheck)
{
  CAkVPLSrcCbxNodeBase *v2; // rax
  CAkVPLSrcNode *v3; // rbx
  CAkPBI *v4; // rdi
  CAkVPLSrcNode *v5; // rcx
  CAkVPLSrcNode *v6; // rax
  CAkSource *v7; // rcx
  CAkUsageSlot *v8; // rcx
  unsigned int out_ulSize; // [rsp+30h] [rbp+8h]
  __int128 out_ppvBuffer; // [rsp+40h] [rbp+18h]

  v2 = this->m_pCbx;
  v3 = 0i64;
  v4 = this;
  if ( !v2 )
    return 0;
  v5 = v2->m_pSources[0];
  if ( v5 && v5->m_pCtx == v4 )
    v3 = v2->m_pSources[0];
  v6 = v2->m_pSources[1];
  if ( v6 && v6->m_pCtx == v4 )
    v3 = v6;
  if ( !v3 )
    return 0;
  if ( !((unsigned __int8 (__fastcall *)(CAkVPLSrcNode *, CAkUsageSlot *))v3->vfptr[1].GetPitch)(v3, in_pSlotToCheck) )
    return 0;
  v7 = v4->m_pSource;
  out_ppvBuffer = 0ui64;
  out_ulSize = 0;
  CAkSource::LockDataPtr(v7, (void **)&out_ppvBuffer, &out_ulSize, (CAkUsageSlot **)&out_ppvBuffer + 1);
  if ( !(_QWORD)out_ppvBuffer )
    return 0;
  if ( ((unsigned int (__fastcall *)(CAkVPLSrcNode *, _QWORD, char *))v3->vfptr[1].Connect)(
         v3,
         out_ppvBuffer,
         v4->m_pDataPtr) != 1 )
  {
    if ( (_QWORD)out_ppvBuffer )
      CAkSource::UnLockDataPtr(v4->m_pSource);
    if ( *((_QWORD *)&out_ppvBuffer + 1) )
      CAkUsageSlot::Release(*((CAkUsageSlot **)&out_ppvBuffer + 1), 0);
    return 0;
  }
  if ( ((unsigned __int8 (__fastcall *)(CAkVPLSrcNode *))v3->vfptr[2].__vecDelDtor)(v3) )
    v4->m_pCbx->vfptr->RelocateMedia(v4->m_pCbx, (char *)out_ppvBuffer, v4->m_pDataPtr);
  if ( (*(unsigned __int8 (__fastcall **)(CAkVPLSrcNode *))v3->vfptr[2].gap8)(v3) )
    v3->m_pAnalysisData = (AkFileParser::AnalysisData *)((char *)v3->m_pAnalysisData
                                                       + out_ppvBuffer
                                                       - (unsigned __int64)v4->m_pDataPtr);
  if ( v4->m_pDataPtr )
    CAkSource::UnLockDataPtr(v4->m_pSource);
  v8 = v4->m_pUsageSlot;
  if ( v8 )
    CAkUsageSlot::Release(v8, 0);
  v4->m_pDataPtr = (char *)out_ppvBuffer;
  v4->m_pUsageSlot = (CAkUsageSlot *)*((_QWORD *)&out_ppvBuffer + 1);
  return 1;
}

// File Line: 2514
// RVA: 0xA80E90
void __fastcall CAkPBI::ForceVirtualize(CAkPBI *this, KickFrom in_eReason)
{
  CAkPBI *v2; // rbx
  char v3; // cl
  char v4; // di
  int v5; // eax
  char v6; // cl
  char v7; // al
  AkVirtualQueueBehavior out_Behavior; // [rsp+30h] [rbp+8h]
  TransParams in_transParams; // [rsp+40h] [rbp+18h]

  v2 = this;
  v3 = *((_BYTE *)this + 372);
  v4 = in_eReason;
  if ( v3 & 0x10 )
  {
    out_Behavior = (unsigned int)*((unsigned __int8 *)v2 + 371) >> 5;
    v5 = v3 & 0xF;
  }
  else
  {
    *((_BYTE *)v2 + 372) = v3 | 0x10;
    v5 = CAkParameterNode::GetVirtualBehavior((CAkParameterNode *)&v2->m_pSound->vfptr, &out_Behavior);
    *((_BYTE *)v2 + 371) &= 0x1Fu;
    v6 = out_Behavior;
    *((_BYTE *)v2 + 372) &= 0xF0u;
    *((_BYTE *)v2 + 371) |= 32 * v6;
    *((_BYTE *)v2 + 372) |= v5 & 0xF;
  }
  if ( v5 == 1 )
  {
    v7 = *((_BYTE *)v2 + 374);
    if ( !(v7 & 1) )
      *((_BYTE *)v2 + 374) = v7 ^ (v7 ^ 2 * v4) & 0xE | 1;
    in_transParams.TransitionTime = 0;
    in_transParams.eFadeCurve = 4;
    CAkPBI::_Stop(v2, &in_transParams, 1);
  }
  else if ( v5 == 2 )
  {
    *((_BYTE *)v2 + 375) |= 0x10u;
  }
}

// File Line: 2533
// RVA: 0xA83360
void __fastcall CAkPBI::Virtualize(CAkPBI *this)
{
  char v1; // al
  CAkRegisteredObj *v2; // rax
  CAkSoundBase *v3; // rcx
  int v4; // [rsp+20h] [rbp-38h]
  CAkRegisteredObj *v5; // [rsp+28h] [rbp-30h]
  __int64 v6; // [rsp+30h] [rbp-28h]
  __int64 v7; // [rsp+38h] [rbp-20h]
  int v8; // [rsp+40h] [rbp-18h]
  __int16 v9; // [rsp+44h] [rbp-14h]

  v1 = *((_BYTE *)this + 375);
  if ( !(v1 & 0x40) )
  {
    *((_BYTE *)this + 375) = v1 | 0x40;
    ++CAkURenderer::m_uNumVirtualizedSounds;
    v2 = this->m_pGameObj;
    v4 = 0;
    v3 = this->m_pSound;
    v6 = 0i64;
    v7 = 0i64;
    v8 = 3;
    v9 = 256;
    v5 = v2;
    v3->vfptr[9].__vecDelDtor((CAkIndexable *)&v3->vfptr, (unsigned int)&v4);
  }
}

// File Line: 2546
// RVA: 0xA80C90
void __fastcall CAkPBI::Devirtualize(CAkPBI *this, bool in_bAllowKick)
{
  char v2; // al
  bool v3; // di
  CAkPBI *v4; // rbx
  __int64 v5; // rax
  CAkSoundBase *v6; // rcx
  int v7; // [rsp+20h] [rbp-38h]
  __int64 v8; // [rsp+28h] [rbp-30h]
  __int64 v9; // [rsp+30h] [rbp-28h]
  __int64 v10; // [rsp+38h] [rbp-20h]
  int v11; // [rsp+40h] [rbp-18h]
  char v12; // [rsp+44h] [rbp-14h]
  bool v13; // [rsp+45h] [rbp-13h]

  v2 = *((_BYTE *)this + 375);
  v3 = in_bAllowKick;
  v4 = this;
  if ( v2 & 0x40 )
  {
    *((_BYTE *)this + 375) = v2 & 0xBF;
    CAkURenderer::DecrementVirtualCount(in_bAllowKick);
    v5 = (__int64)v4->m_pGameObj;
    v9 = 0i64;
    v10 = 0i64;
    v12 = 0;
    v7 = 0;
    v6 = v4->m_pSound;
    v11 = 3;
    v8 = v5;
    v13 = v3;
    ((void (__fastcall *)(CAkSoundBase *, int *))v6->vfptr[9].AddRef)(v6, &v7);
  }
}

// File Line: 2600
// RVA: 0xA81AB0
char __fastcall CAkPBI::IsAuxRoutable(CAkPBI *this)
{
  signed __int64 v1; // rdx
  unsigned int *v2; // rcx

  if ( !this->m_EffectiveParams.bGameDefinedAuxEnabled )
  {
    v1 = 0i64;
    v2 = this->m_EffectiveParams.aAuxSend;
    while ( !*v2 )
    {
      ++v1;
      ++v2;
      if ( v1 >= 4 )
        return 0;
    }
  }
  return 1;
}

