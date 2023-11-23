// File Line: 50
// RVA: 0xA78090
void __fastcall CAkActionPlayAndContinue::CAkActionPlayAndContinue(
        CAkActionPlayAndContinue *this,
        AkActionType in_eActionType,
        unsigned int in_ulID,
        CAkSmartPtr<CAkContinuationList> *in_spContList)
{
  CAkContinuationList *m_pT; // rcx

  CAkActionPlay::CAkActionPlay(this, in_eActionType, in_ulID);
  this->vfptr = (CAkIndexableVtbl *)&CAkActionPlayAndContinue::`vftable;
  *((_BYTE *)&this->m_PBTrans + 16) &= 0xFCu;
  this->m_PBTrans.pvPSTrans = 0i64;
  this->m_PBTrans.pvPRTrans = 0i64;
  m_pT = in_spContList->m_pT;
  this->m_spContList = (CAkSmartPtr<CAkContinuationList>)in_spContList->m_pT;
  if ( m_pT )
    CAkContinuationList::AddRef(m_pT);
  this->m_PlayHistory.arrayIsContinuous.m_iBitArray = 0;
  this->m_pPreviousPBI = 0i64;
  *(_QWORD *)&this->m_FadeOutTimeForLast = 0i64;
  this->m_SA_PBIID = 0;
  this->m_bSkipDelay = 0;
  this->m_pTransitionOwner = 0i64;
  this->m_pInstigator = 0i64;
  this->m_ulPauseCount = 0;
  this->m_pPathOwner = 0i64;
  this->m_PlayHistory.HistArray.uiArraySize = 0;
  this->m_PathInfo.pPBPath = 0i64;
  this->m_PathInfo.PathOwnerID = 0;
  *(_WORD *)&this->m_bNeedNotifyDelay = 1;
  this->m_ePBIType = ContinuousPBI;
}

// File Line: 57
// RVA: 0xA78140
void __fastcall CAkActionPlayAndContinue::~CAkActionPlayAndContinue(CAkActionPlayAndContinue *this)
{
  CAkTransition *pvPSTrans; // rdx
  AkPendingAction *m_pTransitionOwner; // r8
  CAkTransition *pvPRTrans; // rdx
  AkPendingAction *v5; // r8
  CAkPath *pPBPath; // rdx
  CAkParameterNodeBase *m_pPathOwner; // rcx
  CAkPBIAware *m_pInstigator; // rcx
  CAkContinuationList *m_pT; // rcx

  pvPSTrans = this->m_PBTrans.pvPSTrans;
  this->vfptr = (CAkIndexableVtbl *)&CAkActionPlayAndContinue::`vftable;
  if ( pvPSTrans )
  {
    m_pTransitionOwner = this->m_pTransitionOwner;
    if ( m_pTransitionOwner )
      CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, pvPSTrans, m_pTransitionOwner);
  }
  pvPRTrans = this->m_PBTrans.pvPRTrans;
  *((_BYTE *)&this->m_PBTrans + 16) &= ~1u;
  this->m_PBTrans.pvPSTrans = 0i64;
  if ( pvPRTrans )
  {
    v5 = this->m_pTransitionOwner;
    if ( v5 )
      CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, pvPRTrans, v5);
  }
  pPBPath = this->m_PathInfo.pPBPath;
  *((_BYTE *)&this->m_PBTrans + 16) &= ~2u;
  this->m_PBTrans.pvPRTrans = 0i64;
  if ( pPBPath )
    CAkPathManager::RemovePotentialUser(g_pPathManager, pPBPath);
  m_pPathOwner = this->m_pPathOwner;
  if ( m_pPathOwner )
  {
    m_pPathOwner->vfptr->Release(m_pPathOwner);
    this->m_pPathOwner = 0i64;
  }
  m_pInstigator = this->m_pInstigator;
  if ( m_pInstigator )
    m_pInstigator->vfptr->Release(m_pInstigator);
  m_pT = this->m_spContList.m_pT;
  if ( m_pT )
  {
    CAkContinuationList::Release(m_pT);
    this->m_spContList.m_pT = 0i64;
  }
  CAkActionPlay::~CAkActionPlay(this);
}

// File Line: 77
// RVA: 0xA78420
void __fastcall CAkActionPlayAndContinue::Create(
        AkActionType in_eActionType,
        unsigned int in_ulID,
        CAkSmartPtr<CAkContinuationList> *in_spContList)
{
  CAkActionPlayAndContinue *v6; // rax
  CAkAction *v7; // rax

  v6 = (CAkActionPlayAndContinue *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xF8ui64);
  if ( v6 )
  {
    CAkActionPlayAndContinue::CAkActionPlayAndContinue(v6, in_eActionType, in_ulID, in_spContList);
    if ( v7 )
      CAkAction::AddToIndex(v7);
  }
}

// File Line: 92
// RVA: 0xA78490
__int64 __fastcall CAkActionPlayAndContinue::Execute(CAkActionPlayAndContinue *this, AkPendingAction *in_pAction)
{
  int m_FadeOutTimeForLast; // eax
  AkCurveInterpolation v3; // r8d
  CAkContinuousPBI *m_pPreviousPBI; // rcx
  unsigned int v7; // esi
  CAkParameterNode *v8; // rdi
  char v9; // cl
  CAkContinuationList *m_pT; // r14
  AkPathInfo *p_m_PathInfo; // r15
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  AkPBIParams::ePBIType m_ePBIType; // eax
  CAkPBIAware *m_pInstigator; // rax
  __int128 v16; // xmm0
  __int128 v17; // xmm1
  CAkRegisteredObj *pGameObj; // rax
  AkExternalSourceArray *pExternalSrcs; // rax
  unsigned int v20; // eax
  CAkContinuationList *v21; // rcx
  CAkParameterNodeBase *m_pPathOwner; // rcx
  __int64 v24[3]; // [rsp+20h] [rbp-99h] BYREF
  char v25; // [rsp+38h] [rbp-81h]
  bool v26; // [rsp+39h] [rbp-80h]
  CAkContinuationList *v27; // [rsp+40h] [rbp-79h]
  unsigned int m_ulPauseCount; // [rsp+48h] [rbp-71h]
  AkPBIParams in_rPBIParams; // [rsp+50h] [rbp-69h] BYREF
  TransParams in_transParams; // [rsp+120h] [rbp+67h] BYREF

  m_FadeOutTimeForLast = this->m_FadeOutTimeForLast;
  v3 = AkCurveInterpolation_Linear;
  m_pPreviousPBI = this->m_pPreviousPBI;
  in_transParams.TransitionTime = m_FadeOutTimeForLast;
  in_transParams.eFadeCurve = AkCurveInterpolation_Linear;
  v7 = 1;
  if ( m_pPreviousPBI )
  {
    if ( (*((_BYTE *)m_pPreviousPBI + 632) & 0xF) == 2 )
      v3 = AkCurveInterpolation_Sine;
    in_transParams.eFadeCurve = v3;
    CAkPBI::_Stop(m_pPreviousPBI, &in_transParams, 1);
  }
  v8 = (CAkParameterNode *)CAkAction::GetAndRefTarget(this);
  if ( !v8 )
    return 15i64;
  v9 = *((_BYTE *)&this->m_PBTrans + 16);
  v24[0] = (__int64)this->m_PBTrans.pvPSTrans;
  m_pT = this->m_spContList.m_pT;
  v24[1] = (__int64)this->m_PBTrans.pvPRTrans;
  m_ulPauseCount = this->m_ulPauseCount;
  p_m_PathInfo = &this->m_PathInfo;
  v26 = (v9 & 2) != 0;
  v27 = 0i64;
  v24[2] = (__int64)&this->m_PathInfo;
  v25 = v9 & 1;
  if ( m_pT )
    CAkContinuationList::AddRef(m_pT);
  v27 = m_pT;
  v12 = *(_OWORD *)&this->m_PlayHistory.HistArray.uiArraySize;
  v13 = *(_OWORD *)&this->m_PlayHistory.HistArray.aCntrHist[6];
  in_rPBIParams.bSkipDelay = this->m_bSkipDelay;
  m_ePBIType = this->m_ePBIType;
  in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = 0i64;
  *(_OWORD *)&in_rPBIParams.playHistory.HistArray.uiArraySize = v12;
  *(_OWORD *)&in_rPBIParams.playHistory.HistArray.aCntrHist[6] = v13;
  in_rPBIParams.eType = m_ePBIType;
  m_pInstigator = this->m_pInstigator;
  in_rPBIParams.bTargetFeedback = 0;
  v16 = *(_OWORD *)&this->m_PlayHistory.HistArray.aCntrHist[14];
  v17 = *(_OWORD *)&this->m_PlayHistory.HistArray.aCntrHist[22];
  in_rPBIParams.pInstigator = m_pInstigator;
  pGameObj = in_pAction->pGameObj;
  *(_OWORD *)&in_rPBIParams.playHistory.HistArray.aCntrHist[14] = v16;
  *(_OWORD *)&in_rPBIParams.playHistory.HistArray.aCntrHist[22] = v17;
  *(_QWORD *)&v16 = *(_QWORD *)&this->m_PlayHistory.HistArray.aCntrHist[30];
  in_rPBIParams.pGameObj = pGameObj;
  LODWORD(pGameObj) = in_pAction->UserParam.m_PlayingID;
  *(_QWORD *)&in_rPBIParams.playHistory.HistArray.aCntrHist[30] = v16;
  in_rPBIParams.userParams.m_PlayingID = (unsigned int)pGameObj;
  in_rPBIParams.userParams.m_CustomParam.customParam = in_pAction->UserParam.m_CustomParam.customParam;
  in_rPBIParams.userParams.m_CustomParam.ui32Reserved = in_pAction->UserParam.m_CustomParam.ui32Reserved;
  pExternalSrcs = in_pAction->UserParam.m_CustomParam.pExternalSrcs;
  if ( pExternalSrcs )
    ++pExternalSrcs->m_cRefCount;
  in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = pExternalSrcs;
  in_rPBIParams.ePlaybackState = this->m_InitialPlaybackState;
  in_rPBIParams.uFrameOffset = in_pAction->LaunchFrameOffset;
  in_rPBIParams.bIsFirst = this->m_bIsfirstPlay;
  in_rPBIParams.sequenceID = this->m_SA_PBIID;
  in_rPBIParams.pContinuousParams = (ContParams *)v24;
  in_rPBIParams.pTransitionParameters = &in_transParams;
  v20 = CAkParameterNode::HandleInitialDelay(v8, &in_rPBIParams);
  if ( v20 != 3 )
  {
    if ( v20 == 1 )
      v20 = ((__int64 (__fastcall *)(CAkParameterNode *, AkPBIParams *))v8->vfptr[19].Category)(v8, &in_rPBIParams);
    v7 = v20;
  }
  ++CAkLEngineCmds::m_ulPlayEventID;
  v21 = this->m_spContList.m_pT;
  this->m_spContList.m_pT = 0i64;
  if ( v21 )
    CAkContinuationList::Release(v21);
  if ( p_m_PathInfo->pPBPath )
  {
    CAkPathManager::RemovePotentialUser(g_pPathManager, p_m_PathInfo->pPBPath);
    p_m_PathInfo->pPBPath = 0i64;
    this->m_PathInfo.PathOwnerID = 0;
  }
  m_pPathOwner = this->m_pPathOwner;
  if ( m_pPathOwner )
  {
    m_pPathOwner->vfptr->Release(m_pPathOwner);
    this->m_pPathOwner = 0i64;
  }
  v8->vfptr->Release(v8);
  if ( in_rPBIParams.userParams.m_CustomParam.pExternalSrcs )
    AkExternalSourceArray::Release(in_rPBIParams.userParams.m_CustomParam.pExternalSrcs);
  if ( v27 )
    CAkContinuationList::Release(v27);
  return v7;
}

// File Line: 178
// RVA: 0xA78A40
__int64 __fastcall CAkActionPlayAndContinue::SetPlayStopTransition(
        CAkActionPlayAndContinue *this,
        CAkTransition *in_pTransition,
        bool in_bTransitionFading,
        AkPendingAction *in_pTransitionOwner)
{
  CAkTransition *pvPSTrans; // rdx
  __int64 result; // rax

  pvPSTrans = this->m_PBTrans.pvPSTrans;
  this->m_pTransitionOwner = in_pTransitionOwner;
  if ( pvPSTrans && in_pTransitionOwner )
    CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, pvPSTrans, in_pTransitionOwner);
  *((_BYTE *)&this->m_PBTrans + 16) &= ~1u;
  this->m_PBTrans.pvPSTrans = 0i64;
  if ( !in_pTransition
    || (result = CAkTransitionManager::AddTransitionUser(g_pTransitionManager, in_pTransition, this->m_pTransitionOwner),
        (_DWORD)result == 1) )
  {
    *((_BYTE *)&this->m_PBTrans + 16) &= ~1u;
    this->m_PBTrans.pvPSTrans = in_pTransition;
    *((_BYTE *)&this->m_PBTrans + 16) |= in_bTransitionFading;
    return 1i64;
  }
  return result;
}

// File Line: 197
// RVA: 0xA789A0
__int64 __fastcall CAkActionPlayAndContinue::SetPauseResumeTransition(
        CAkActionPlayAndContinue *this,
        CAkTransition *in_pTransition,
        bool in_bTransitionFading,
        AkPendingAction *in_pTransitionOwner)
{
  CAkTransition *pvPRTrans; // rdx
  __int64 result; // rax

  pvPRTrans = this->m_PBTrans.pvPRTrans;
  this->m_pTransitionOwner = in_pTransitionOwner;
  if ( pvPRTrans && in_pTransitionOwner )
    CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, pvPRTrans, in_pTransitionOwner);
  *((_BYTE *)&this->m_PBTrans + 16) &= ~2u;
  this->m_PBTrans.pvPRTrans = 0i64;
  if ( !in_pTransition
    || (result = CAkTransitionManager::AddTransitionUser(g_pTransitionManager, in_pTransition, this->m_pTransitionOwner),
        (_DWORD)result == 1) )
  {
    *((_BYTE *)&this->m_PBTrans + 16) &= ~2u;
    this->m_PBTrans.pvPRTrans = in_pTransition;
    result = 1i64;
    *((_BYTE *)&this->m_PBTrans + 16) |= 2 * in_bTransitionFading;
  }
  return result;
}

// File Line: 236
// RVA: 0xA78910
void __fastcall CAkActionPlayAndContinue::SetPathInfo(CAkActionPlayAndContinue *this, AkPathInfo *in_pPathInfo)
{
  CAkPath *pPBPath; // rdx
  CAkParameterNodeBase *m_pPathOwner; // rcx

  this->m_PathInfo.pPBPath = 0i64;
  this->m_PathInfo.PathOwnerID = 0;
  pPBPath = in_pPathInfo->pPBPath;
  if ( pPBPath )
    CAkPathManager::AddPotentialUser(g_pPathManager, pPBPath);
  m_pPathOwner = this->m_pPathOwner;
  this->m_PathInfo.pPBPath = in_pPathInfo->pPBPath;
  this->m_PathInfo.PathOwnerID = in_pPathInfo->PathOwnerID;
  if ( m_pPathOwner )
  {
    m_pPathOwner->vfptr->Release(m_pPathOwner);
    this->m_pPathOwner = 0i64;
  }
  this->m_pPathOwner = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_pPathInfo->PathOwnerID, AkNodeType_Default);
}

// File Line: 276
// RVA: 0xA78720
void __fastcall CAkActionPlayAndContinue::GetHistArray(CAkActionPlayAndContinue *this, AkCntrHistArray *out_rHistArray)
{
  *out_rHistArray = this->m_PlayHistory.HistArray;
}

// File Line: 281
// RVA: 0xA78830
void __fastcall CAkActionPlayAndContinue::SetHistory(CAkActionPlayAndContinue *this, PlayHistory *in_rPlayHistory)
{
  this->m_PlayHistory = *in_rPlayHistory;
}

// File Line: 286
// RVA: 0xA788D0
void __fastcall CAkActionPlayAndContinue::SetInitialPlaybackState(
        CAkActionPlayAndContinue *this,
        AkPlaybackState in_eInitialPlaybackState)
{
  this->m_InitialPlaybackState = in_eInitialPlaybackState;
}

// File Line: 291
// RVA: 0xA788E0
void __fastcall CAkActionPlayAndContinue::SetInstigator(CAkActionPlayAndContinue *this, CAkPBIAware *in_pInstigator)
{
  this->m_pInstigator = in_pInstigator;
  in_pInstigator->vfptr->AddRef(in_pInstigator);
}

// File Line: 298
// RVA: 0xA787B0
_BOOL8 __fastcall CAkActionPlayAndContinue::NeedNotifyDelay(CAkActionPlayAndContinue *this)
{
  return this->m_bNeedNotifyDelay;
}

// File Line: 303
// RVA: 0xA78900
void __fastcall CAkActionPlayAndContinue::SetIsFirstPlay(CAkActionPlayAndContinue *this, bool in_bIsFirstPlay)
{
  this->m_bIsfirstPlay = in_bIsFirstPlay;
}

// File Line: 313
// RVA: 0xA78810
void __fastcall CAkActionPlayAndContinue::SetFadeBack(
        CAkActionPlayAndContinue *this,
        CAkContinuousPBI *in_pPBIToNotify,
        int in_CrossFadeTime)
{
  this->m_pPreviousPBI = in_pPBIToNotify;
  this->m_FadeOutTimeForLast = in_CrossFadeTime;
  this->m_bNeedNotifyDelay = 0;
}

// File Line: 320
// RVA: 0xA78AD0
void __fastcall CAkActionPlayAndContinue::SetSAInfo(CAkActionPlayAndContinue *this, unsigned int in_seqID)
{
  this->m_SA_PBIID = in_seqID;
}

// File Line: 325
// RVA: 0xA78AF0
void __fastcall CAkActionPlayAndContinue::UnsetFadeBack(
        CAkActionPlayAndContinue *this,
        CAkContinuousPBI *in_pPBIToCheck)
{
  if ( in_pPBIToCheck == this->m_pPreviousPBI )
    this->m_pPreviousPBI = 0i64;
}

// File Line: 334
// RVA: 0xA78AE0
void __fastcall CAkActionPlayAndContinue::StartAsPaused(CAkActionPlayAndContinue *this)
{
  this->m_InitialPlaybackState = PB_Paused;
}

// File Line: 339
// RVA: 0xA787C0
void __fastcall CAkActionPlayAndContinue::Resume(CAkActionPlayAndContinue *this)
{
  CAkTransition *pvPRTrans; // rdx
  AkPendingAction *m_pTransitionOwner; // r8

  if ( (*((_BYTE *)&this->m_PBTrans + 16) & 2) != 0 )
  {
    pvPRTrans = this->m_PBTrans.pvPRTrans;
    if ( pvPRTrans )
    {
      m_pTransitionOwner = this->m_pTransitionOwner;
      if ( m_pTransitionOwner )
        CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, pvPRTrans, m_pTransitionOwner);
      *((_BYTE *)&this->m_PBTrans + 16) &= ~2u;
      this->m_PBTrans.pvPRTrans = 0i64;
    }
  }
}

// File Line: 348
// RVA: 0xA78240
char __fastcall CAkActionPlayAndContinue::BreakToNode(
        CAkActionPlayAndContinue *this,
        CAkParameterNode *in_pNodeToTest,
        CAkRegisteredObj *in_pGameObj,
        AkPendingAction *in_pPendingAction)
{
  CAkContinuationList *m_pT; // rax
  CAkContinueListItem *v8; // rdi
  CAkMultiPlayNode *v9; // rcx
  unsigned int v11; // edx
  __int64 m_iBitArray; // rcx
  CAkContinuationList *v13; // rdi
  CAkContinuationList *m_pAlternateContList; // rdx
  CAkContinuationList *v15; // rdi
  CAkContinuationList *v16; // rdi
  CAkContinuationList *v17; // rcx
  CAkContinuationList *v18; // rcx
  CAkParameterNodeBase *NextToPlayContinuous; // rax
  CAkContinuationList *v21; // rcx
  unsigned int out_uSelectedNodeID[10]; // [rsp+30h] [rbp-28h] BYREF
  CAkSmartPtr<CAkContinuationList> io_spList; // [rsp+60h] [rbp+8h] BYREF

  m_pT = this->m_spContList.m_pT;
  if ( !m_pT )
    return 1;
  if ( m_pT->m_listItems.m_uLength )
  {
    do
    {
      v8 = &this->m_spContList.m_pT->m_listItems.m_pItems[this->m_spContList.m_pT->m_listItems.m_uLength];
      v9 = v8[-1].m_pMultiPlayNode.m_pT;
      if ( v9 )
      {
        m_pAlternateContList = v8[-1].m_pAlternateContList;
        io_spList.m_pT = 0i64;
        CAkMultiPlayNode::ContGetList(v9, m_pAlternateContList, &io_spList);
        v15 = this->m_spContList.m_pT;
        CAkContinueListItem::~CAkContinueListItem(&v15->m_listItems.m_pItems[v15->m_listItems.m_uLength - 1]);
        --v15->m_listItems.m_uLength;
        v16 = io_spList.m_pT;
        if ( !io_spList.m_pT )
        {
          v21 = this->m_spContList.m_pT;
          this->m_spContList.m_pT = 0i64;
          if ( !v21 )
            return 1;
          CAkContinuationList::Release(v21);
          v18 = io_spList.m_pT;
LABEL_18:
          if ( v18 )
            CAkContinuationList::Release(v18);
          return 1;
        }
        CAkContinuationList::AddRef(io_spList.m_pT);
        v17 = this->m_spContList.m_pT;
        this->m_spContList.m_pT = v16;
        if ( v17 )
          CAkContinuationList::Release(v17);
        if ( io_spList.m_pT )
          CAkContinuationList::Release(io_spList.m_pT);
      }
      else
      {
        if ( !CAkParameterNode::IsOrIsChildOf(v8[-1].m_pContainer.m_pT, in_pNodeToTest, 0) )
        {
          NextToPlayContinuous = CAkRanSeqCntr::GetNextToPlayContinuous(
                                   v8[-1].m_pContainer.m_pT,
                                   in_pGameObj,
                                   (unsigned __int16 *)&io_spList,
                                   out_uSelectedNodeID,
                                   &v8[-1].m_pContainerInfo,
                                   &v8[-1].m_LoopingInfo);
          if ( !NextToPlayContinuous )
            break;
          this->m_PlayHistory.HistArray.aCntrHist[this->m_PlayHistory.HistArray.uiArraySize - 1] = (unsigned __int16)io_spList.m_pT;
          this->m_ulElementID = NextToPlayContinuous->key;
          NextToPlayContinuous->vfptr->Release(NextToPlayContinuous);
          return 0;
        }
        if ( this->m_PlayHistory.HistArray.uiArraySize-- != 1 )
        {
          do
          {
            v11 = this->m_PlayHistory.HistArray.uiArraySize - 1;
            if ( v11 < 0x20 )
            {
              m_iBitArray = this->m_PlayHistory.arrayIsContinuous.m_iBitArray;
              if ( _bittest64(&m_iBitArray, v11) )
                break;
            }
            this->m_PlayHistory.HistArray.uiArraySize = v11;
          }
          while ( v11 );
        }
        v13 = this->m_spContList.m_pT;
        CAkContinueListItem::~CAkContinueListItem(&v13->m_listItems.m_pItems[v13->m_listItems.m_uLength - 1]);
        --v13->m_listItems.m_uLength;
      }
    }
    while ( this->m_spContList.m_pT->m_listItems.m_uLength );
  }
  v18 = this->m_spContList.m_pT;
  if ( !v18->m_listItems.m_uLength )
  {
    this->m_spContList.m_pT = 0i64;
    goto LABEL_18;
  }
  return 1;
}

