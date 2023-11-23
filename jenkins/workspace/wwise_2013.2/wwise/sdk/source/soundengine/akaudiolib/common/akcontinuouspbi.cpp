// File Line: 78
// RVA: 0xA75240
void __fastcall CAkContinuousPBI::CAkContinuousPBI(
        CAkContinuousPBI *this,
        CAkSoundBase *in_pSound,
        CAkSource *in_pSource,
        CAkRegisteredObj *in_pGameObj,
        ContParams *in_Cparameters,
        UserParams *in_rUserParams,
        PlayHistory *in_rPlayHistory,
        bool in_bIsFirst,
        unsigned int in_SeqID,
        CAkPBIAware *in_pInstigator,
        PriorityInfoCurrent *in_rPriority,
        bool in_bTargetFeedback,
        CAkLimiter *in_pAMLimiter,
        CAkLimiter *in_pBusLimiter)
{
  CAkContinuationList *m_pT; // rcx
  char v16; // dl
  unsigned int v17; // ecx
  bool bIsPlayStopTransitionFading; // al
  bool bIsPauseResumeTransitionFading; // al

  CAkPBI::CAkPBI(
    this,
    in_pSound,
    in_pSource,
    in_pGameObj,
    in_rUserParams,
    in_rPlayHistory,
    in_SeqID,
    in_rPriority,
    in_bTargetFeedback,
    0,
    in_pAMLimiter,
    in_pBusLimiter);
  this->CAkPBI::CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkContinuousPBI::`vftable{for `CAkTransportAware};
  this->CAkPBI::ITransitionable::vfptr = (ITransitionableVtbl *)&CAkContinuousPBI::`vftable{for `ITransitionable};
  m_pT = in_Cparameters->spContList.m_pT;
  this->m_spContList.m_pT = m_pT;
  if ( m_pT )
    CAkContinuationList::AddRef(m_pT);
  this->m_PlayHistoryForNextToPlay.arrayIsContinuous.m_iBitArray = 0;
  v16 = *((_BYTE *)this + 636);
  *((_DWORD *)this + 158) &= 0xFFFFFFF0;
  this->m_pInstigator = in_pInstigator;
  *(_QWORD *)&this->m_fTransitionTime = 0i64;
  *((_BYTE *)this + 636) = in_bIsFirst | v16 & 0xF8;
  in_pInstigator->vfptr->AddRef(in_pInstigator);
  if ( !this->m_SeqID )
  {
    v17 = CAkContinuousPBI::m_CalSeqID++;
    this->m_SeqID = v17;
  }
  this->m_ulPauseCount = in_Cparameters->ulPauseCount;
  if ( !this->m_PBTrans.pvPSTrans )
  {
    this->m_PBTrans.pvPSTrans = in_Cparameters->pPlayStopTransition;
    bIsPlayStopTransitionFading = in_Cparameters->bIsPlayStopTransitionFading;
    in_Cparameters->pPlayStopTransition = 0i64;
    *((_BYTE *)&this->m_PBTrans + 16) ^= (*((_BYTE *)&this->m_PBTrans + 16) ^ bIsPlayStopTransitionFading) & 1;
  }
  if ( !this->m_PBTrans.pvPRTrans )
  {
    this->m_PBTrans.pvPRTrans = in_Cparameters->pPauseResumeTransition;
    bIsPauseResumeTransitionFading = in_Cparameters->bIsPauseResumeTransitionFading;
    in_Cparameters->pPauseResumeTransition = 0i64;
    *((_BYTE *)&this->m_PBTrans + 16) ^= (*((_BYTE *)&this->m_PBTrans + 16) ^ (2 * bIsPauseResumeTransitionFading)) & 2;
  }
  this->m_PlayHistoryForNextToPlay.HistArray.uiArraySize = 0;
  CAkContinuousPBI::PrepareNextPlayHistory(this, in_rPlayHistory);
}

// File Line: 118
// RVA: 0xA75560
AKRESULT __fastcall CAkContinuousPBI::Init(CAkContinuousPBI *this, AkPathInfo *in_pPathInfo)
{
  AKRESULT result; // eax
  AKRESULT v4; // edi
  CAkTransition *pvPSTrans; // rdx
  int v6; // eax
  char v7; // al
  CAkTransition *pvPRTrans; // rdx
  int v9; // eax
  char v10; // cl
  char v11; // al
  char v12; // al

  result = CAkPBI::Init(this, in_pPathInfo);
  v4 = result;
  if ( result != AK_Success )
    return result;
  pvPSTrans = this->m_PBTrans.pvPSTrans;
  if ( pvPSTrans )
  {
    v6 = CAkTransitionManager::AddTransitionUser(g_pTransitionManager, pvPSTrans, &this->ITransitionable);
    if ( v6 == v4 )
    {
      if ( !CAkTransitionManager::IsTerminated(g_pTransitionManager, this->m_PBTrans.pvPSTrans) )
      {
        ((void (__fastcall *)(CAkContinuousPBI *, _QWORD, __int64))this->CAkPBI::CAkTransportAware::vfptr[8]._Stop)(
          this,
          (unsigned int)(v4 + 13),
          0xFFFFFFFFi64);
        goto LABEL_12;
      }
      CAkTransitionManager::RemoveTransitionUser(
        g_pTransitionManager,
        this->m_PBTrans.pvPSTrans,
        &this->ITransitionable);
      this->m_PBTrans.pvPSTrans = 0i64;
      goto LABEL_10;
    }
    if ( v6 != 28 )
      this->m_PBTrans.pvPSTrans = 0i64;
    if ( v6 == 24 )
    {
LABEL_10:
      v7 = *((_BYTE *)&this->m_PBTrans + 16);
      if ( (v7 & 1) != 0 )
      {
        *((_BYTE *)&this->CAkPBI + 370) &= 0xFAu;
        *((_BYTE *)&this->CAkPBI + 370) |= 2u;
        *((_BYTE *)&this->m_PBTrans + 16) = v7 & 0xFE;
      }
    }
  }
LABEL_12:
  pvPRTrans = this->m_PBTrans.pvPRTrans;
  if ( !pvPRTrans )
    goto LABEL_24;
  v9 = CAkTransitionManager::AddTransitionUser(g_pTransitionManager, pvPRTrans, &this->ITransitionable);
  if ( v9 != 1 )
  {
    if ( v9 != 28 )
      this->m_PBTrans.pvPRTrans = 0i64;
    if ( v9 != 24 )
      goto LABEL_24;
    goto LABEL_20;
  }
  if ( CAkTransitionManager::IsTerminated(g_pTransitionManager, this->m_PBTrans.pvPRTrans) )
  {
    CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, this->m_PBTrans.pvPRTrans, &this->ITransitionable);
    this->m_PBTrans.pvPRTrans = 0i64;
LABEL_20:
    v10 = *((_BYTE *)&this->m_PBTrans + 16);
    if ( (v10 & 2) != 0 )
    {
      v11 = *((_BYTE *)&this->CAkPBI + 370);
      if ( (v11 & 7) == 0 )
        *((_BYTE *)&this->CAkPBI + 370) = v11 & 0xF8 | 1;
      *((_BYTE *)&this->m_PBTrans + 16) = v10 & 0xFD;
    }
    goto LABEL_24;
  }
  ((void (__fastcall *)(CAkContinuousPBI *, __int64))this->CAkPBI::CAkTransportAware::vfptr[8]._Stop)(this, 14i64);
LABEL_24:
  v12 = *((_BYTE *)&this->CAkPBI + 370);
  if ( (v12 & 7) == 0 && this->m_ulPauseCount && !this->m_PBTrans.pvPRTrans )
    *((_BYTE *)&this->CAkPBI + 370) = v12 & 0xF8 | 1;
  return v4;
}

// File Line: 212
// RVA: 0xA753D0
void __fastcall CAkContinuousPBI::~CAkContinuousPBI(CAkContinuousPBI *this)
{
  CAkContinuationList *m_pT; // rcx

  this->CAkPBI::CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkContinuousPBI::`vftable{for `CAkTransportAware};
  this->CAkPBI::ITransitionable::vfptr = (ITransitionableVtbl *)&CAkContinuousPBI::`vftable{for `ITransitionable};
  this->m_pInstigator->vfptr->Release(this->m_pInstigator);
  m_pT = this->m_spContList.m_pT;
  if ( m_pT )
  {
    CAkContinuationList::Release(m_pT);
    this->m_spContList.m_pT = 0i64;
  }
  CAkPBI::~CAkPBI(this);
}

// File Line: 218
// RVA: 0xA762B0
void __fastcall CAkContinuousPBI::Term(CAkContinuousPBI *this, bool in_bFailedToInit)
{
  unsigned int m_ulNextElementToPlay; // edx
  char v5; // al
  CAkParameterNodeBase *NodePtrAndAddRef; // r15
  CAkActionPlayAndContinue *v7; // rax
  CAkActionPlayAndContinue *v8; // rsi
  AkPendingAction *v9; // rax
  AkPendingAction *v10; // rax
  AkPendingAction *v11; // r14
  int v12; // eax
  unsigned int v13; // eax
  __int64 v14; // r10
  int v15; // eax
  signed int v16; // eax
  __int64 v17; // r8
  unsigned int v18; // edx
  int v19; // ebx
  char v20; // al
  CAkContinuationList *m_pT; // rcx
  char v22; // al
  __int64 v23; // [rsp+50h] [rbp+8h]

  CAkPBI::DecrementPlayCount(this);
  ((void (__fastcall *)(CAkContinuousPBI *, _QWORD))this->CAkPBI::CAkTransportAware::vfptr[8].~CAkTransportAware)(
    this,
    0i64);
  if ( !this->m_ulNextElementToPlay && g_pAudioMgr )
    CAkAudioMgr::ClearCrossFadeOccurence(g_pAudioMgr, this);
  m_ulNextElementToPlay = this->m_ulNextElementToPlay;
  if ( m_ulNextElementToPlay )
  {
    v5 = *((_BYTE *)&this->CAkPBI + 373);
    if ( (v5 & 4) == 0 && ((v5 & 0x20) == 0 || (unsigned int)(((int)(*((_DWORD *)this + 158) << 28) >> 28) - 1) > 1) )
    {
      NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, m_ulNextElementToPlay, AkNodeType_Default);
      if ( NodePtrAndAddRef )
      {
        v7 = CAkActionPlayAndContinue::Create(AkActionType_PlayAndContinue, 0, &this->m_spContList);
        v8 = v7;
        if ( !v7 )
        {
LABEL_31:
          v20 = *((_BYTE *)&this->CAkPBI + 373);
          if ( (v20 & 1) != 0 )
            *((_BYTE *)&this->CAkPBI + 373) = v20 | 2;
          NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef);
          goto LABEL_34;
        }
        v7->m_ulPauseCount = this->m_ulPauseCount;
        CAkActionPlayAndContinue::SetHistory(v7, &this->m_PlayHistoryForNextToPlay);
        LODWORD(v23) = NodePtrAndAddRef->key;
        BYTE4(v23) = 0;
        ((void (__fastcall *)(CAkActionPlayAndContinue *, __int64))v8->vfptr[1].AddRef)(v8, v23);
        CAkActionPlayAndContinue::SetInstigator(v8, this->m_pInstigator);
        v9 = (AkPendingAction *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
        if ( v9 )
        {
          AkPendingAction::AkPendingAction(v9, this->m_pGameObj);
          v11 = v10;
          if ( v10 )
          {
            if ( CAkActionPlayAndContinue::SetPlayStopTransition(
                   v8,
                   this->m_PBTrans.pvPSTrans,
                   *((_BYTE *)&this->m_PBTrans + 16) & 1,
                   v10) == AK_Success
              && CAkActionPlayAndContinue::SetPauseResumeTransition(
                   v8,
                   this->m_PBTrans.pvPRTrans,
                   (*((_BYTE *)&this->m_PBTrans + 16) & 2) != 0,
                   v11) == AK_Success )
            {
              CAkActionPlayAndContinue::SetPathInfo(v8, &this->m_PathInfo);
              if ( (*((_BYTE *)&this->CAkPBI + 373) & 8) != 0 || in_bFailedToInit )
              {
                CAkActionPlayAndContinue::SetIsFirstPlay(v8, *((_BYTE *)this + 636) & 1);
                v16 = AkTimeConv::MillisecondsToSamples(this->m_fTransitionTime);
                v17 = (unsigned int)v16;
                v18 = (g_settings.uContinuousPlaybackLookAhead + 10) << 10;
                if ( (*((_BYTE *)this + 632) & 0xF) != 3 || v16 < (int)v18 )
                  v17 = v18;
                v15 = ((__int64 (__fastcall *)(CAkActionPlayAndContinue *, __int64, __int64))v8->vfptr[1].Release)(
                        v8,
                        14i64,
                        v17);
              }
              else
              {
                v12 = (int)(*((_DWORD *)this + 158) << 28) >> 28;
                if ( v12 != 3 )
                {
                  if ( v12 == 4 )
                    CAkActionPlayAndContinue::SetSAInfo(v8, this->m_SeqID);
                  goto LABEL_25;
                }
                v13 = AkTimeConv::MillisecondsToSamples(this->m_fTransitionTime);
                v15 = (*(__int64 (__fastcall **)(CAkActionPlayAndContinue *, __int64, _QWORD))(v14 + 48))(
                        v8,
                        14i64,
                        v13);
              }
              if ( v15 == 1 )
              {
LABEL_25:
                v11->pAction = v8;
                UserParams::operator=(&v11->UserParam, &this->m_UserParams);
                CAkAudioMgr::EnqueueOrExecuteAction(g_pAudioMgr, v11);
                if ( this->m_fTransitionTime != 0.0 && this->m_ulPauseCount && !this->m_PBTrans.pvPRTrans )
                  CAkAudioMgr::PausePending(g_pAudioMgr, v11);
                goto LABEL_30;
              }
            }
            v19 = g_DefaultPoolId;
            ((void (__fastcall *)(AkPendingAction *, _QWORD))v11->vfptr[1].TransUpdateValue)(v11, 0i64);
            AK::MemoryMgr::Free(v19, v11);
          }
        }
LABEL_30:
        v8->vfptr->Release(v8);
        goto LABEL_31;
      }
    }
  }
LABEL_34:
  m_pT = this->m_spContList.m_pT;
  this->m_spContList.m_pT = 0i64;
  if ( m_pT )
    CAkContinuationList::Release(m_pT);
  v22 = *((_BYTE *)&this->CAkPBI + 373);
  if ( (v22 & 1) != 0 && (v22 & 2) != 0 )
    *((_BYTE *)&this->CAkPBI + 373) = v22 & 0xFE;
  CAkPBI::Term(this, in_bFailedToInit);
}

// File Line: 349
// RVA: 0xA75F70
void __fastcall CAkContinuousPBI::SeekTimeAbsolute(CAkContinuousPBI *this, int in_iPosition, bool in_bSnapToMarker)
{
  if ( CAkContinuousPBI::CanSeek(this) )
    CAkPBI::SeekTimeAbsolute(this, in_iPosition, in_bSnapToMarker);
}

// File Line: 360
// RVA: 0xA75F20
void __fastcall CAkContinuousPBI::SeekPercent(CAkContinuousPBI *this, float in_fPercent, bool in_bSnapToMarker)
{
  if ( CAkContinuousPBI::CanSeek(this) )
    CAkPBI::SeekPercent(this, in_fPercent, in_bSnapToMarker);
}

// File Line: 372
// RVA: 0xA754B0
char __fastcall CAkContinuousPBI::CanSeek(CAkContinuousPBI *this)
{
  char v1; // di
  CAkRanSeqCntr *m_pParentNode; // rbx
  char v4; // si

  v1 = 0;
  m_pParentNode = (CAkRanSeqCntr *)this->m_pSound->m_pParentNode;
  v4 = 1;
  if ( m_pParentNode )
  {
    do
    {
      if ( m_pParentNode->vfptr[3].Release(m_pParentNode) == 2 )
      {
        if ( CAkRanSeqCntr::TransitionMode(m_pParentNode) == Transition_CrossFadeAmp
          || CAkRanSeqCntr::TransitionMode(m_pParentNode) == Transition_CrossFadePower
          || CAkRanSeqCntr::TransitionMode(m_pParentNode) == Transition_TriggerRate )
        {
          return 0;
        }
        if ( CAkRanSeqCntr::TransitionMode(m_pParentNode) == Transition_SampleAccurate )
          v1 = 1;
      }
      m_pParentNode = (CAkRanSeqCntr *)m_pParentNode->m_pParentNode;
    }
    while ( m_pParentNode );
    if ( v1 )
    {
      if ( (*((_BYTE *)this + 636) & 1) == 0 )
        return 0;
    }
  }
  return v4;
}

// File Line: 401
// RVA: 0xA75950
void __fastcall CAkContinuousPBI::PrepareNextPlayHistory(CAkContinuousPBI *this, PlayHistory *in_rPlayHistory)
{
  unsigned int v2; // eax
  __int64 m_iBitArray; // rdx

  this->m_PlayHistoryForNextToPlay = *in_rPlayHistory;
  if ( this->m_PlayHistoryForNextToPlay.HistArray.uiArraySize )
  {
    do
    {
      v2 = this->m_PlayHistoryForNextToPlay.HistArray.uiArraySize - 1;
      if ( v2 < 0x20 )
      {
        m_iBitArray = this->m_PlayHistoryForNextToPlay.arrayIsContinuous.m_iBitArray;
        if ( _bittest64(&m_iBitArray, v2) )
          break;
      }
      this->m_PlayHistoryForNextToPlay.HistArray.uiArraySize = v2;
    }
    while ( v2 );
  }
}

// File Line: 421
// RVA: 0xA75A30
void __fastcall CAkContinuousPBI::PrepareNextToPlay(CAkContinuousPBI *this, bool in_bIsPreliminary)
{
  CAkContinuationList *m_pT; // rax
  CAkContinuationList *v5; // rcx
  __int64 m_uLength; // rax
  CAkContinueListItem *m_pItems; // rsi
  __int64 v8; // rbx
  CAkParameterNodeBase *NextToPlayContinuous; // rax
  CAkParameterNodeBase *v10; // r14
  unsigned int v11; // edx
  __int64 m_iBitArray; // rcx
  CAkContinuationList *v13; // rbx
  CAkContinuationList *v14; // rdx
  __int64 v15; // rcx
  bool v16; // zf
  __int64 v17; // rcx
  __int64 v18; // rdx
  __int64 v19; // rcx
  CAkContinuationList *m_pAlternateContList; // rdx
  CAkMultiPlayNode *v21; // rcx
  CAkContinuationList *v22; // rbx
  CAkContinuationList *v23; // rbx
  CAkContinuationList *v24; // rcx
  CAkContinuationList *v25; // rcx
  char v26; // al
  int v27; // ecx
  CAkContinuationList *v28; // rcx
  unsigned __int16 out_rwPositionSelected; // [rsp+60h] [rbp+8h] BYREF
  unsigned int out_uSelectedNodeID; // [rsp+70h] [rbp+18h] BYREF
  CAkSmartPtr<CAkContinuationList> io_spList; // [rsp+78h] [rbp+20h] BYREF

  if ( (*((_BYTE *)this + 636) & 4) != 0 )
    goto LABEL_25;
  m_pT = this->m_spContList.m_pT;
  if ( !m_pT )
    goto LABEL_25;
  if ( !m_pT->m_listItems.m_uLength )
  {
LABEL_23:
    v25 = this->m_spContList.m_pT;
    this->m_spContList.m_pT = 0i64;
    if ( v25 )
      CAkContinuationList::Release(v25);
LABEL_25:
    *((_BYTE *)this + 636) |= 4u;
    return;
  }
  while ( 1 )
  {
    v5 = this->m_spContList.m_pT;
    m_uLength = v5->m_listItems.m_uLength;
    m_pItems = v5->m_listItems.m_pItems;
    v8 = m_uLength;
    if ( !v5->m_listItems.m_pItems[m_uLength - 1].m_pMultiPlayNode.m_pT )
    {
      NextToPlayContinuous = CAkRanSeqCntr::GetNextToPlayContinuous(
                               m_pItems[m_uLength - 1].m_pContainer.m_pT,
                               this->m_pGameObj,
                               &out_rwPositionSelected,
                               &out_uSelectedNodeID,
                               &m_pItems[m_uLength - 1].m_pContainerInfo,
                               &m_pItems[m_uLength - 1].m_LoopingInfo);
      v10 = NextToPlayContinuous;
      if ( NextToPlayContinuous )
      {
        this->m_PlayHistoryForNextToPlay.HistArray.aCntrHist[this->m_PlayHistoryForNextToPlay.HistArray.uiArraySize - 1] = out_rwPositionSelected;
        this->m_ulNextElementToPlay = NextToPlayContinuous->key;
        v26 = CAkRanSeqCntr::TransitionMode(m_pItems[v8 - 1].m_pContainer.m_pT);
        *((_DWORD *)this + 158) &= 0xFFFFFFF0;
        *((_DWORD *)this + 158) |= v26 & 0xF;
        v27 = (int)(*((_DWORD *)this + 158) << 28) >> 28;
        if ( (unsigned int)(v27 - 1) <= 2 || v27 == 5 )
          this->m_fTransitionTime = CAkRanSeqCntr::TransitionTime(m_pItems[v8 - 1].m_pContainer.m_pT, this->m_pGameObj);
        else
          this->m_fTransitionTime = 0.0;
        *((_BYTE *)this + 636) |= 4u;
        v10->vfptr->Release(v10);
        return;
      }
      if ( --this->m_PlayHistoryForNextToPlay.HistArray.uiArraySize )
      {
        do
        {
          v11 = this->m_PlayHistoryForNextToPlay.HistArray.uiArraySize - 1;
          if ( v11 < 0x20 )
          {
            m_iBitArray = this->m_PlayHistoryForNextToPlay.arrayIsContinuous.m_iBitArray;
            if ( _bittest64(&m_iBitArray, v11) )
              break;
          }
          this->m_PlayHistoryForNextToPlay.HistArray.uiArraySize = v11;
        }
        while ( v11 );
      }
      v13 = this->m_spContList.m_pT;
      CAkContinueListItem::~CAkContinueListItem(&v13->m_listItems.m_pItems[v13->m_listItems.m_uLength - 1]);
      --v13->m_listItems.m_uLength;
      goto LABEL_22;
    }
    if ( in_bIsPreliminary )
      break;
LABEL_17:
    m_pAlternateContList = m_pItems[v8 - 1].m_pAlternateContList;
    v21 = m_pItems[v8 - 1].m_pMultiPlayNode.m_pT;
    io_spList.m_pT = 0i64;
    CAkMultiPlayNode::ContGetList(v21, m_pAlternateContList, &io_spList);
    v22 = this->m_spContList.m_pT;
    CAkContinueListItem::~CAkContinueListItem(&v22->m_listItems.m_pItems[v22->m_listItems.m_uLength - 1]);
    --v22->m_listItems.m_uLength;
    v23 = io_spList.m_pT;
    if ( !io_spList.m_pT )
    {
      v28 = this->m_spContList.m_pT;
      this->m_spContList.m_pT = 0i64;
      if ( v28 )
      {
        CAkContinuationList::Release(v28);
        if ( io_spList.m_pT )
          CAkContinuationList::Release(io_spList.m_pT);
      }
      return;
    }
    CAkContinuationList::AddRef(io_spList.m_pT);
    v24 = this->m_spContList.m_pT;
    this->m_spContList.m_pT = v23;
    if ( v24 )
      CAkContinuationList::Release(v24);
    if ( io_spList.m_pT )
    {
      CAkContinuationList::Release(io_spList.m_pT);
      io_spList.m_pT = 0i64;
    }
LABEL_22:
    if ( !this->m_spContList.m_pT->m_listItems.m_uLength )
      goto LABEL_23;
  }
  v14 = m_pItems[m_uLength - 1].m_pAlternateContList;
  if ( !v14->m_listItems.m_uLength )
    return;
  v15 = 5i64 * v14->m_listItems.m_uLength - 5;
  v16 = *((_QWORD *)&v14->m_listItems.m_pItems->m_pMultiPlayNode.m_pT + v15) == 0i64;
  v17 = (__int64)v14->m_listItems.m_pItems + 8 * v15;
  if ( v16 )
  {
LABEL_16:
    if ( CAkRanSeqCntr::TransitionMode(*(CAkRanSeqCntr **)v17) != Transition_TriggerRate )
      return;
    goto LABEL_17;
  }
  while ( 1 )
  {
    v18 = *(_QWORD *)(v17 + 32);
    if ( !*(_DWORD *)(v18 + 8) )
      break;
    v19 = 5i64 * *(unsigned int *)(v18 + 8) - 5;
    v16 = *(_QWORD *)(*(_QWORD *)v18 + 8 * v19 + 24) == 0i64;
    v17 = *(_QWORD *)v18 + 8 * v19;
    if ( v16 )
      goto LABEL_16;
  }
}

// File Line: 518
// RVA: 0xA75FB0
void __fastcall CAkContinuousPBI::SetEstimatedLength(CAkContinuousPBI *this, float in_fEstimatedLength)
{
  __int64 v2; // rdx
  char v3; // al
  int v5; // ecx
  CAkActionPlayAndContinue *v6; // r14
  AkPendingAction *v7; // rax
  AkPendingAction *v8; // rax
  AkPendingAction *v9; // rsi
  int v10; // ebx
  int v11; // eax
  int m_iFrameOffset; // eax
  int v13; // eax
  float m_fTransitionTime; // xmm2_4
  int v15; // ebx
  CAkContinuationList *m_pT; // rcx
  __int64 v17; // [rsp+60h] [rbp+8h]

  v3 = *((_BYTE *)&this->CAkPBI + 373);
  if ( (v3 & 0x10) == 0 && (v3 & 0x20) == 0 )
  {
    LOBYTE(v2) = 1;
    ((void (__fastcall *)(CAkContinuousPBI *, __int64))this->CAkPBI::CAkTransportAware::vfptr[8].~CAkTransportAware)(
      this,
      v2);
    v5 = (int)(*((_DWORD *)this + 158) << 28) >> 28;
    if ( (unsigned int)(v5 - 1) <= 1 )
    {
      if ( in_fEstimatedLength < 50.0 )
        return;
    }
    else if ( v5 != 5 )
    {
      return;
    }
    if ( this->m_ulNextElementToPlay )
    {
      v6 = CAkActionPlayAndContinue::Create(AkActionType_PlayAndContinue, 0, &this->m_spContList);
      if ( v6 )
      {
        v7 = (AkPendingAction *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
        if ( v7 )
        {
          AkPendingAction::AkPendingAction(v7, this->m_pGameObj);
          v9 = v8;
          if ( v8 )
          {
            v6->m_ulPauseCount = this->m_ulPauseCount;
            CAkActionPlayAndContinue::SetHistory(v6, &this->m_PlayHistoryForNextToPlay);
            LODWORD(v17) = this->m_ulNextElementToPlay;
            BYTE4(v17) = 0;
            ((void (__fastcall *)(CAkActionPlayAndContinue *, __int64))v6->vfptr[1].AddRef)(v6, v17);
            CAkActionPlayAndContinue::SetInstigator(v6, this->m_pInstigator);
            CAkActionPlayAndContinue::SetPauseResumeTransition(
              v6,
              this->m_PBTrans.pvPRTrans,
              (*((_BYTE *)&this->m_PBTrans + 16) & 2) != 0,
              v9);
            CAkActionPlayAndContinue::SetPathInfo(v6, &this->m_PathInfo);
            if ( (unsigned int)(((int)(*((_DWORD *)this + 158) << 28) >> 28) - 1) <= 1 )
            {
              m_fTransitionTime = this->m_fTransitionTime;
              if ( m_fTransitionTime >= (float)(in_fEstimatedLength * 0.5) )
                m_fTransitionTime = in_fEstimatedLength;
              v10 = AkTimeConv::MillisecondsToSamples((float)(in_fEstimatedLength - m_fTransitionTime));
              CAkActionPlayAndContinue::SetFadeBack(v6, this, (int)m_fTransitionTime);
            }
            else
            {
              v10 = AkTimeConv::MillisecondsToSamples(this->m_fTransitionTime);
              v11 = 1024;
              if ( *((char *)&this->CAkPBI + 374) < 0 )
                v11 = 8;
              if ( v10 < v11 )
                v10 = v11;
              m_iFrameOffset = this->m_iFrameOffset;
              if ( *((char *)&this->CAkPBI + 374) < 0 )
                v13 = m_iFrameOffset + 8;
              else
                v13 = m_iFrameOffset + 1024;
              if ( v13 > 0 )
                v10 += v13;
              CAkActionPlayAndContinue::SetPlayStopTransition(
                v6,
                this->m_PBTrans.pvPSTrans,
                *((_BYTE *)&this->m_PBTrans + 16) & 1,
                v9);
            }
            if ( ((unsigned int (__fastcall *)(CAkActionPlayAndContinue *, __int64, _QWORD))v6->vfptr[1].Release)(
                   v6,
                   14i64,
                   (unsigned int)v10) == 1 )
            {
              v9->pAction = v6;
              UserParams::operator=(&v9->UserParam, &this->m_UserParams);
              CAkAudioMgr::EnqueueOrExecuteAction(g_pAudioMgr, v9);
              if ( v10 >= 1024 && this->m_ulPauseCount )
                CAkAudioMgr::PausePending(g_pAudioMgr, v9);
            }
            else
            {
              v15 = g_DefaultPoolId;
              ((void (__fastcall *)(AkPendingAction *, _QWORD))v9->vfptr[1].TransUpdateValue)(v9, 0i64);
              AK::MemoryMgr::Free(v15, v9);
            }
          }
        }
        v6->vfptr->Release(v6);
        *((_BYTE *)&this->CAkPBI + 373) |= 2u;
      }
      m_pT = this->m_spContList.m_pT;
      this->m_spContList.m_pT = 0i64;
      if ( m_pT )
        CAkContinuationList::Release(m_pT);
      this->m_ulNextElementToPlay = 0;
    }
  }
}

// File Line: 626
// RVA: 0xA75D30
void __fastcall CAkContinuousPBI::PrepareSampleAccurateTransition(CAkContinuousPBI *this, __int64 a2)
{
  CAkActionPlayAndContinue *v3; // rsi
  AkPendingAction *v4; // rax
  AkPendingAction *v5; // rax
  AkPendingAction *v6; // r14
  int v7; // ebx
  CAkContinuationList *m_pT; // rcx
  __int64 v9; // [rsp+40h] [rbp+8h]

  if ( (*((_BYTE *)&this->CAkPBI + 373) & 0x10) == 0 )
  {
    LOBYTE(a2) = 1;
    ((void (__fastcall *)(CAkContinuousPBI *, __int64))this->CAkPBI::CAkTransportAware::vfptr[8].~CAkTransportAware)(
      this,
      a2);
    if ( (*((_DWORD *)this + 158) & 0xF) == 4 )
    {
      if ( this->m_ulNextElementToPlay )
      {
        v3 = CAkActionPlayAndContinue::Create(AkActionType_PlayAndContinue, 0, &this->m_spContList);
        if ( v3 )
        {
          v4 = (AkPendingAction *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
          if ( v4 )
          {
            AkPendingAction::AkPendingAction(v4, this->m_pGameObj);
            v6 = v5;
            if ( v5 )
            {
              v3->m_ulPauseCount = this->m_ulPauseCount;
              CAkActionPlayAndContinue::SetHistory(v3, &this->m_PlayHistoryForNextToPlay);
              LODWORD(v9) = this->m_ulNextElementToPlay;
              BYTE4(v9) = 0;
              ((void (__fastcall *)(CAkActionPlayAndContinue *, __int64))v3->vfptr[1].AddRef)(v3, v9);
              CAkActionPlayAndContinue::SetInstigator(v3, this->m_pInstigator);
              if ( CAkActionPlayAndContinue::SetPlayStopTransition(
                     v3,
                     this->m_PBTrans.pvPSTrans,
                     *((_BYTE *)&this->m_PBTrans + 16) & 1,
                     v6) == AK_Success
                && CAkActionPlayAndContinue::SetPauseResumeTransition(
                     v3,
                     this->m_PBTrans.pvPRTrans,
                     (*((_BYTE *)&this->m_PBTrans + 16) & 2) != 0,
                     v6) == AK_Success )
              {
                CAkActionPlayAndContinue::SetPathInfo(v3, &this->m_PathInfo);
                if ( (*((_BYTE *)&this->CAkPBI + 373) & 0x40) != 0 )
                  CAkActionPlayAndContinue::StartAsPaused(v3);
                CAkActionPlayAndContinue::SetSAInfo(v3, this->m_SeqID);
                v6->pAction = v3;
                UserParams::operator=(&v6->UserParam, &this->m_UserParams);
                CAkAudioMgr::EnqueueOrExecuteAction(g_pAudioMgr, v6);
              }
              else
              {
                v7 = g_DefaultPoolId;
                ((void (__fastcall *)(AkPendingAction *, _QWORD))v6->vfptr[1].TransUpdateValue)(v6, 0i64);
                AK::MemoryMgr::Free(v7, v6);
              }
            }
          }
          v3->vfptr->Release(v3);
          *((_BYTE *)&this->CAkPBI + 373) |= 2u;
        }
        m_pT = this->m_spContList.m_pT;
        this->m_spContList.m_pT = 0i64;
        if ( m_pT )
          CAkContinuationList::Release(m_pT);
        this->m_ulNextElementToPlay = 0;
      }
    }
  }
}

// File Line: 691
// RVA: 0xA76600
void __fastcall CAkContinuousPBI::_Stop(
        CAkContinuousPBI *this,
        AkPBIStopMode in_eStopMode,
        bool in_bIsFromTransition,
        bool in_bHasNotStarted)
{
  CAkContinuationList *m_pT; // rcx

  *((_BYTE *)this + 636) |= 4u;
  this->m_ulNextElementToPlay = 0;
  m_pT = this->m_spContList.m_pT;
  this->m_spContList.m_pT = 0i64;
  if ( m_pT )
    CAkContinuationList::Release(m_pT);
  CAkPBI::_Stop(this, in_eStopMode, in_bIsFromTransition, in_bHasNotStarted);
}

// File Line: 701
// RVA: 0xA75760
void __fastcall CAkContinuousPBI::PlayToEnd(CAkContinuousPBI *this, CAkParameterNode *in_pNode)
{
  unsigned int m_ulNextElementToPlay; // edx
  CAkParameterNode *NodePtrAndAddRef; // rsi
  CAkContinuationList *m_pT; // rax
  CAkContinueListItem *v7; // r9
  CAkMultiPlayNode *v8; // rcx
  unsigned int v10; // edx
  __int64 m_iBitArray; // rcx
  CAkContinuationList *v12; // rdi
  CAkContinuationList *m_pAlternateContList; // rdx
  CAkContinuationList *v14; // rdi
  CAkContinuationList *v15; // rdi
  CAkContinuationList *v16; // rcx
  CAkContinuationList *v17; // rcx
  CAkSmartPtr<CAkContinuationList> io_spList; // [rsp+40h] [rbp+8h] BYREF

  m_ulNextElementToPlay = this->m_ulNextElementToPlay;
  NodePtrAndAddRef = 0i64;
  if ( m_ulNextElementToPlay )
    NodePtrAndAddRef = (CAkParameterNode *)CAkAudioLibIndex::GetNodePtrAndAddRef(
                                             g_pIndex,
                                             m_ulNextElementToPlay,
                                             AkNodeType_Default);
  if ( (*((_BYTE *)this + 636) & 4) == 0
    || !this->m_ulNextElementToPlay
    || CAkParameterNode::IsOrIsChildOf(NodePtrAndAddRef, in_pNode, 0) )
  {
    m_pT = this->m_spContList.m_pT;
    *((_BYTE *)this + 636) &= ~4u;
    this->m_ulNextElementToPlay = 0;
    if ( m_pT )
    {
      if ( m_pT->m_listItems.m_uLength )
      {
        do
        {
          v7 = &this->m_spContList.m_pT->m_listItems.m_pItems[this->m_spContList.m_pT->m_listItems.m_uLength];
          v8 = v7[-1].m_pMultiPlayNode.m_pT;
          if ( v8 )
          {
            m_pAlternateContList = v7[-1].m_pAlternateContList;
            io_spList.m_pT = 0i64;
            CAkMultiPlayNode::ContGetList(v8, m_pAlternateContList, &io_spList);
            v14 = this->m_spContList.m_pT;
            CAkContinueListItem::~CAkContinueListItem(&v14->m_listItems.m_pItems[v14->m_listItems.m_uLength - 1]);
            --v14->m_listItems.m_uLength;
            v15 = io_spList.m_pT;
            if ( io_spList.m_pT )
            {
              CAkContinuationList::AddRef(io_spList.m_pT);
              v16 = this->m_spContList.m_pT;
              this->m_spContList.m_pT = v15;
              if ( v16 )
                CAkContinuationList::Release(v16);
              if ( io_spList.m_pT )
                CAkContinuationList::Release(io_spList.m_pT);
            }
          }
          else
          {
            if ( !CAkParameterNode::IsOrIsChildOf(v7[-1].m_pContainer.m_pT, in_pNode, 0) )
              break;
            if ( this->m_PlayHistoryForNextToPlay.HistArray.uiArraySize-- != 1 )
            {
              do
              {
                v10 = this->m_PlayHistoryForNextToPlay.HistArray.uiArraySize - 1;
                if ( v10 < 0x20 )
                {
                  m_iBitArray = this->m_PlayHistoryForNextToPlay.arrayIsContinuous.m_iBitArray;
                  if ( _bittest64(&m_iBitArray, v10) )
                    break;
                }
                this->m_PlayHistoryForNextToPlay.HistArray.uiArraySize = v10;
              }
              while ( v10 );
            }
            v12 = this->m_spContList.m_pT;
            CAkContinueListItem::~CAkContinueListItem(&v12->m_listItems.m_pItems[v12->m_listItems.m_uLength - 1]);
            --v12->m_listItems.m_uLength;
          }
        }
        while ( this->m_spContList.m_pT->m_listItems.m_uLength );
      }
      v17 = this->m_spContList.m_pT;
      if ( !v17->m_listItems.m_uLength )
      {
        this->m_spContList.m_pT = 0i64;
        if ( v17 )
          CAkContinuationList::Release(v17);
      }
    }
  }
  if ( NodePtrAndAddRef )
    NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef);
  CAkPBI::PlayToEnd(this, in_pNode);
}

// File Line: 773
// RVA: 0xA76290
void __fastcall CAkContinuousPBI::SetPauseStateForContinuous(CAkContinuousPBI *this, bool in_bIsPaused)
{
  *((_BYTE *)this + 636) &= ~2u;
  *((_BYTE *)this + 636) |= 2 * in_bIsPaused;
}

