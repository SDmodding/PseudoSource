// File Line: 78
// RVA: 0xA75240
void __fastcall CAkContinuousPBI::CAkContinuousPBI(CAkContinuousPBI *this, CAkSoundBase *in_pSound, CAkSource *in_pSource, CAkRegisteredObj *in_pGameObj, ContParams *in_Cparameters, UserParams *in_rUserParams, PlayHistory *in_rPlayHistory, bool in_bIsFirst, unsigned int in_SeqID, CAkPBIAware *in_pInstigator, PriorityInfoCurrent *in_rPriority, bool in_bTargetFeedback, CAkLimiter *in_pAMLimiter, CAkLimiter *in_pBusLimiter)
{
  CAkContinuousPBI *v14; // rbx
  CAkContinuationList *v15; // rcx
  char v16; // dl
  unsigned int v17; // ecx
  bool v18; // al
  bool v19; // al

  v14 = this;
  CAkPBI::CAkPBI(
    (CAkPBI *)&this->vfptr,
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
  v14->vfptr = (CAkTransportAwareVtbl *)&CAkContinuousPBI::`vftable'{for `CAkTransportAware'};
  v14->vfptr = (ITransitionableVtbl *)&CAkContinuousPBI::`vftable'{for `ITransitionable'};
  v15 = in_Cparameters->spContList.m_pT;
  v14->m_spContList.m_pT = v15;
  if ( v15 )
    CAkContinuationList::AddRef(v15);
  v14->m_PlayHistoryForNextToPlay.arrayIsContinuous.m_iBitArray = 0;
  v16 = *((_BYTE *)v14 + 636);
  *((_DWORD *)v14 + 158) &= 0xFFFFFFF0;
  v14->m_pInstigator = in_pInstigator;
  *(_QWORD *)&v14->m_fTransitionTime = 0i64;
  *((_BYTE *)v14 + 636) = in_bIsFirst | v16 & 0xF8;
  ((void (*)(void))in_pInstigator->vfptr->AddRef)();
  if ( !v14->m_SeqID )
  {
    v17 = CAkContinuousPBI::m_CalSeqID++;
    v14->m_SeqID = v17;
  }
  v14->m_ulPauseCount = in_Cparameters->ulPauseCount;
  if ( !v14->m_PBTrans.pvPSTrans )
  {
    v14->m_PBTrans.pvPSTrans = in_Cparameters->pPlayStopTransition;
    v18 = in_Cparameters->bIsPlayStopTransitionFading;
    in_Cparameters->pPlayStopTransition = 0i64;
    *((_BYTE *)&v14->m_PBTrans + 16) ^= (*((_BYTE *)&v14->m_PBTrans + 16) ^ v18) & 1;
  }
  if ( !v14->m_PBTrans.pvPRTrans )
  {
    v14->m_PBTrans.pvPRTrans = in_Cparameters->pPauseResumeTransition;
    v19 = in_Cparameters->bIsPauseResumeTransitionFading;
    in_Cparameters->pPauseResumeTransition = 0i64;
    *((_BYTE *)&v14->m_PBTrans + 16) ^= (*((_BYTE *)&v14->m_PBTrans + 16) ^ 2 * v19) & 2;
  }
  v14->m_PlayHistoryForNextToPlay.HistArray.uiArraySize = 0;
  CAkContinuousPBI::PrepareNextPlayHistory(v14, in_rPlayHistory);
}

// File Line: 118
// RVA: 0xA75560
AKRESULT __fastcall CAkContinuousPBI::Init(CAkContinuousPBI *this, AkPathInfo *in_pPathInfo)
{
  CAkContinuousPBI *v2; // rbx
  AKRESULT result; // eax
  AKRESULT v4; // edi
  CAkTransition *v5; // rdx
  int v6; // eax
  char v7; // al
  CAkTransition *v8; // rdx
  int v9; // eax
  char v10; // cl
  char v11; // al
  char v12; // al

  v2 = this;
  result = CAkPBI::Init((CAkPBI *)&this->vfptr, in_pPathInfo);
  v4 = result;
  if ( result != 1 )
    return result;
  v5 = v2->m_PBTrans.pvPSTrans;
  if ( v5 )
  {
    v6 = CAkTransitionManager::AddTransitionUser(g_pTransitionManager, v5, (ITransitionable *)&v2->vfptr);
    if ( v6 == v4 )
    {
      if ( !CAkTransitionManager::IsTerminated(g_pTransitionManager, v2->m_PBTrans.pvPSTrans) )
      {
        ((void (__fastcall *)(CAkContinuousPBI *, _QWORD, signed __int64))v2->vfptr[8]._Stop)(
          v2,
          (unsigned int)(v4 + 13),
          0xFFFFFFFFi64);
        goto LABEL_12;
      }
      CAkTransitionManager::RemoveTransitionUser(
        g_pTransitionManager,
        v2->m_PBTrans.pvPSTrans,
        (ITransitionable *)&v2->vfptr);
      v2->m_PBTrans.pvPSTrans = 0i64;
      goto LABEL_10;
    }
    if ( v6 != 28 )
      v2->m_PBTrans.pvPSTrans = 0i64;
    if ( v6 == 24 )
    {
LABEL_10:
      v7 = *((_BYTE *)&v2->m_PBTrans + 16);
      if ( v7 & 1 )
      {
        *((_BYTE *)&v2->0 + 370) &= 0xFAu;
        *((_BYTE *)&v2->0 + 370) |= 2u;
        *((_BYTE *)&v2->m_PBTrans + 16) = v7 & 0xFE;
      }
      goto LABEL_12;
    }
  }
LABEL_12:
  v8 = v2->m_PBTrans.pvPRTrans;
  if ( !v8 )
    goto LABEL_24;
  v9 = CAkTransitionManager::AddTransitionUser(g_pTransitionManager, v8, (ITransitionable *)&v2->vfptr);
  if ( v9 != 1 )
  {
    if ( v9 != 28 )
      v2->m_PBTrans.pvPRTrans = 0i64;
    if ( v9 != 24 )
      goto LABEL_24;
    goto LABEL_20;
  }
  if ( CAkTransitionManager::IsTerminated(g_pTransitionManager, v2->m_PBTrans.pvPRTrans) )
  {
    CAkTransitionManager::RemoveTransitionUser(
      g_pTransitionManager,
      v2->m_PBTrans.pvPRTrans,
      (ITransitionable *)&v2->vfptr);
    v2->m_PBTrans.pvPRTrans = 0i64;
LABEL_20:
    v10 = *((_BYTE *)&v2->m_PBTrans + 16);
    if ( v10 & 2 )
    {
      v11 = *((_BYTE *)&v2->0 + 370);
      if ( !(v11 & 7) )
        *((_BYTE *)&v2->0 + 370) = v11 & 0xF9 | 1;
      *((_BYTE *)&v2->m_PBTrans + 16) = v10 & 0xFD;
    }
    goto LABEL_24;
  }
  ((void (__fastcall *)(CAkContinuousPBI *, signed __int64))v2->vfptr[8]._Stop)(v2, 14i64);
LABEL_24:
  v12 = *((_BYTE *)&v2->0 + 370);
  if ( !(v12 & 7) && v2->m_ulPauseCount && !v2->m_PBTrans.pvPRTrans )
    *((_BYTE *)&v2->0 + 370) = v12 & 0xF9 | 1;
  return v4;
}

// File Line: 212
// RVA: 0xA753D0
void __fastcall CAkContinuousPBI::~CAkContinuousPBI(CAkContinuousPBI *this)
{
  CAkContinuousPBI *v1; // rbx
  CAkContinuationList *v2; // rcx

  v1 = this;
  this->vfptr = (CAkTransportAwareVtbl *)&CAkContinuousPBI::`vftable'{for `CAkTransportAware'};
  this->vfptr = (ITransitionableVtbl *)&CAkContinuousPBI::`vftable'{for `ITransitionable'};
  ((void (*)(void))this->m_pInstigator->vfptr->Release)();
  v2 = v1->m_spContList.m_pT;
  if ( v2 )
  {
    CAkContinuationList::Release(v2);
    v1->m_spContList.m_pT = 0i64;
  }
  CAkPBI::~CAkPBI((CAkPBI *)&v1->vfptr);
}

// File Line: 218
// RVA: 0xA762B0
void __fastcall CAkContinuousPBI::Term(CAkContinuousPBI *this, bool in_bFailedToInit)
{
  bool v2; // bp
  CAkContinuousPBI *v3; // rdi
  unsigned int v4; // edx
  char v5; // al
  CAkIndexable *v6; // r15
  CAkActionPlayAndContinue *v7; // rax
  CAkActionPlayAndContinue *v8; // rsi
  AkPendingAction *v9; // rax
  AkPendingAction *v10; // rax
  AkPendingAction *v11; // r14
  int v12; // eax
  CAkIndexableVtbl *v13; // r10
  unsigned int v14; // eax
  __int64 v15; // r10
  int v16; // eax
  int v17; // eax
  __int64 v18; // r8
  int v19; // edx
  int v20; // ebx
  char v21; // al
  CAkContinuationList *v22; // rcx
  char v23; // al
  __int64 v24; // [rsp+50h] [rbp+8h]

  v2 = in_bFailedToInit;
  v3 = this;
  CAkPBI::DecrementPlayCount((CAkPBI *)&this->vfptr);
  ((void (__fastcall *)(CAkContinuousPBI *, _QWORD))v3->vfptr[8].~CAkTransportAware)(v3, 0i64);
  if ( !v3->m_ulNextElementToPlay && g_pAudioMgr )
    CAkAudioMgr::ClearCrossFadeOccurence(g_pAudioMgr, v3);
  v4 = v3->m_ulNextElementToPlay;
  if ( v4 )
  {
    v5 = *((_BYTE *)&v3->0 + 373);
    if ( !(v5 & 4) && (!(v5 & 0x20) || (unsigned int)((*((_DWORD *)v3 + 158) << 28 >> 28) - 1) > 1) )
    {
      v6 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v4, 0);
      if ( v6 )
      {
        v7 = CAkActionPlayAndContinue::Create(AkActionType_PlayAndContinue, 0, &v3->m_spContList);
        v8 = v7;
        if ( !v7 )
        {
LABEL_31:
          v21 = *((_BYTE *)&v3->0 + 373);
          if ( v21 & 1 )
            *((_BYTE *)&v3->0 + 373) = v21 | 2;
          v6->vfptr->Release(v6);
          goto LABEL_34;
        }
        v7->m_ulPauseCount = v3->m_ulPauseCount;
        CAkActionPlayAndContinue::SetHistory(v7, &v3->m_PlayHistoryForNextToPlay);
        LODWORD(v24) = v6->key;
        BYTE4(v24) = 0;
        ((void (__fastcall *)(CAkActionPlayAndContinue *, __int64))v8->vfptr[1].AddRef)(v8, v24);
        CAkActionPlayAndContinue::SetInstigator(v8, v3->m_pInstigator);
        v9 = (AkPendingAction *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
        if ( v9 )
        {
          AkPendingAction::AkPendingAction(v9, v3->m_pGameObj);
          v11 = v10;
          if ( v10 )
          {
            if ( CAkActionPlayAndContinue::SetPlayStopTransition(
                   v8,
                   v3->m_PBTrans.pvPSTrans,
                   *((_BYTE *)&v3->m_PBTrans + 16) & 1,
                   v10) == 1
              && CAkActionPlayAndContinue::SetPauseResumeTransition(
                   v8,
                   v3->m_PBTrans.pvPRTrans,
                   (*((_BYTE *)&v3->m_PBTrans + 16) >> 1) & 1,
                   v11) == 1 )
            {
              CAkActionPlayAndContinue::SetPathInfo(v8, &v3->m_PathInfo);
              if ( *((_BYTE *)&v3->0 + 373) & 8 || v2 )
              {
                CAkActionPlayAndContinue::SetIsFirstPlay(v8, *((_BYTE *)v3 + 636) & 1);
                v17 = AkTimeConv::MillisecondsToSamples(v3->m_fTransitionTime);
                v18 = (unsigned int)v17;
                v19 = (unk_14249E984 + 10) << 10;
                if ( (*((_BYTE *)v3 + 632) & 0xF) != 3 || v17 < v19 )
                  v18 = (unsigned int)v19;
                v16 = ((__int64 (__fastcall *)(CAkActionPlayAndContinue *, signed __int64, __int64))v8->vfptr[1].Release)(
                        v8,
                        14i64,
                        v18);
              }
              else
              {
                v12 = *((_DWORD *)v3 + 158) << 28 >> 28;
                if ( v12 != 3 )
                {
                  if ( v12 == 4 )
                    CAkActionPlayAndContinue::SetSAInfo(v8, v3->m_SeqID);
                  goto LABEL_25;
                }
                v13 = v8->vfptr;
                v14 = AkTimeConv::MillisecondsToSamples(v3->m_fTransitionTime);
                v16 = (*(__int64 (__fastcall **)(CAkActionPlayAndContinue *, signed __int64, _QWORD))(v15 + 48))(
                        v8,
                        14i64,
                        v14);
              }
              if ( v16 == 1 )
              {
LABEL_25:
                v11->pAction = (CAkAction *)&v8->vfptr;
                UserParams::operator=(&v11->UserParam, &v3->m_UserParams);
                CAkAudioMgr::EnqueueOrExecuteAction(g_pAudioMgr, v11);
                if ( v3->m_fTransitionTime != 0.0 && v3->m_ulPauseCount && !v3->m_PBTrans.pvPRTrans )
                  CAkAudioMgr::PausePending(g_pAudioMgr, v11);
                goto LABEL_30;
              }
            }
            v20 = g_DefaultPoolId;
            ((void (__fastcall *)(AkPendingAction *, _QWORD))v11->vfptr[1].TransUpdateValue)(v11, 0i64);
            AK::MemoryMgr::Free(v20, v11);
          }
        }
LABEL_30:
        v8->vfptr->Release((CAkIndexable *)&v8->vfptr);
        goto LABEL_31;
      }
    }
  }
LABEL_34:
  v22 = v3->m_spContList.m_pT;
  v3->m_spContList.m_pT = 0i64;
  if ( v22 )
    CAkContinuationList::Release(v22);
  v23 = *((_BYTE *)&v3->0 + 373);
  if ( v23 & 1 && v23 & 2 )
    *((_BYTE *)&v3->0 + 373) = v23 & 0xFE;
  CAkPBI::Term((CAkPBI *)&v3->vfptr, v2);
}

// File Line: 349
// RVA: 0xA75F70
void __fastcall CAkContinuousPBI::SeekTimeAbsolute(CAkContinuousPBI *this, int in_iPosition, bool in_bSnapToMarker)
{
  bool v3; // di
  int v4; // esi
  CAkContinuousPBI *v5; // rbx

  v3 = in_bSnapToMarker;
  v4 = in_iPosition;
  v5 = this;
  if ( CAkContinuousPBI::CanSeek(this) )
    CAkPBI::SeekTimeAbsolute((CAkPBI *)&v5->vfptr, v4, v3);
}

// File Line: 360
// RVA: 0xA75F20
void __fastcall CAkContinuousPBI::SeekPercent(CAkContinuousPBI *this, float in_fPercent, bool in_bSnapToMarker)
{
  bool v3; // di
  CAkContinuousPBI *v4; // rbx

  v3 = in_bSnapToMarker;
  v4 = this;
  if ( CAkContinuousPBI::CanSeek(this) )
    CAkPBI::SeekPercent((CAkPBI *)&v4->vfptr, in_fPercent, v3);
}

// File Line: 372
// RVA: 0xA754B0
char __fastcall CAkContinuousPBI::CanSeek(CAkContinuousPBI *this)
{
  char v1; // di
  CAkContinuousPBI *v2; // rbp
  CAkRanSeqCntr *v3; // rbx
  char v4; // si

  v1 = 0;
  v2 = this;
  v3 = (CAkRanSeqCntr *)this->m_pSound->m_pParentNode;
  v4 = 1;
  if ( v3 )
  {
    do
    {
      if ( v3->vfptr[3].Release((CAkIndexable *)&v3->vfptr) == 2 )
      {
        if ( CAkRanSeqCntr::TransitionMode(v3) == 1
          || CAkRanSeqCntr::TransitionMode(v3) == 2
          || CAkRanSeqCntr::TransitionMode(v3) == 5 )
        {
          return 0;
        }
        if ( CAkRanSeqCntr::TransitionMode(v3) == 4 )
          v1 = 1;
      }
      v3 = (CAkRanSeqCntr *)v3->m_pParentNode;
    }
    while ( v3 );
    if ( v1 )
    {
      if ( !(*((_BYTE *)v2 + 636) & 1) )
        v4 = 0;
    }
  }
  return v4;
}

// File Line: 401
// RVA: 0xA75950
void __fastcall CAkContinuousPBI::PrepareNextPlayHistory(CAkContinuousPBI *this, PlayHistory *in_rPlayHistory)
{
  unsigned int v2; // eax
  __int64 v3; // rdx

  this->m_PlayHistoryForNextToPlay.HistArray.uiArraySize = in_rPlayHistory->HistArray.uiArraySize;
  *(_DWORD *)this->m_PlayHistoryForNextToPlay.HistArray.aCntrHist = *(_DWORD *)in_rPlayHistory->HistArray.aCntrHist;
  *(_DWORD *)&this->m_PlayHistoryForNextToPlay.HistArray.aCntrHist[2] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[2];
  *(_DWORD *)&this->m_PlayHistoryForNextToPlay.HistArray.aCntrHist[4] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[4];
  *(_DWORD *)&this->m_PlayHistoryForNextToPlay.HistArray.aCntrHist[6] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[6];
  *(_DWORD *)&this->m_PlayHistoryForNextToPlay.HistArray.aCntrHist[8] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[8];
  *(_DWORD *)&this->m_PlayHistoryForNextToPlay.HistArray.aCntrHist[10] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[10];
  *(_DWORD *)&this->m_PlayHistoryForNextToPlay.HistArray.aCntrHist[12] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[12];
  *(_DWORD *)&this->m_PlayHistoryForNextToPlay.HistArray.aCntrHist[14] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[14];
  *(_DWORD *)&this->m_PlayHistoryForNextToPlay.HistArray.aCntrHist[16] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[16];
  *(_DWORD *)&this->m_PlayHistoryForNextToPlay.HistArray.aCntrHist[18] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[18];
  *(_DWORD *)&this->m_PlayHistoryForNextToPlay.HistArray.aCntrHist[20] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[20];
  *(_DWORD *)&this->m_PlayHistoryForNextToPlay.HistArray.aCntrHist[22] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[22];
  *(_DWORD *)&this->m_PlayHistoryForNextToPlay.HistArray.aCntrHist[24] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[24];
  *(_DWORD *)&this->m_PlayHistoryForNextToPlay.HistArray.aCntrHist[26] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[26];
  *(_DWORD *)&this->m_PlayHistoryForNextToPlay.HistArray.aCntrHist[28] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[28];
  *(_DWORD *)&this->m_PlayHistoryForNextToPlay.HistArray.aCntrHist[30] = *(_DWORD *)&in_rPlayHistory->HistArray.aCntrHist[30];
  this->m_PlayHistoryForNextToPlay.arrayIsContinuous.m_iBitArray = in_rPlayHistory->arrayIsContinuous.m_iBitArray;
  if ( this->m_PlayHistoryForNextToPlay.HistArray.uiArraySize )
  {
    do
    {
      v2 = this->m_PlayHistoryForNextToPlay.HistArray.uiArraySize - 1;
      if ( v2 < 0x20 )
      {
        v3 = this->m_PlayHistoryForNextToPlay.arrayIsContinuous.m_iBitArray;
        if ( _bittest64(&v3, v2) )
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
  bool v2; // bp
  CAkContinuousPBI *v3; // rdi
  CAkContinuationList *v4; // rax
  CAkContinuationList *v5; // rcx
  signed __int64 v6; // rax
  CAkContinueListItem *v7; // rsi
  signed __int64 v8; // rbx
  CAkParameterNodeBase *v9; // rax
  CAkParameterNodeBase *v10; // r14
  unsigned int v11; // edx
  __int64 v12; // rcx
  CAkContinuationList *v13; // rbx
  __int64 v14; // rdx
  signed __int64 v15; // rcx
  bool v16; // zf
  signed __int64 v17; // rcx
  __int64 v18; // rdx
  signed __int64 v19; // rcx
  CAkContinuationList *v20; // rdx
  CAkMultiPlayNode *v21; // rcx
  CAkContinuationList *v22; // rbx
  CAkContinuationList *v23; // rbx
  CAkContinuationList *v24; // rcx
  CAkContinuationList *v25; // rcx
  char v26; // al
  int v27; // ecx
  CAkContinuationList *v28; // rcx
  unsigned __int16 out_rwPositionSelected; // [rsp+60h] [rbp+8h]
  unsigned int out_uSelectedNodeID; // [rsp+70h] [rbp+18h]
  CAkSmartPtr<CAkContinuationList> io_spList; // [rsp+78h] [rbp+20h]

  v2 = in_bIsPreliminary;
  v3 = this;
  if ( *((_BYTE *)this + 636) & 4 )
    goto LABEL_25;
  v4 = this->m_spContList.m_pT;
  if ( !v4 )
    goto LABEL_25;
  if ( !v4->m_listItems.m_uLength )
  {
LABEL_23:
    v25 = v3->m_spContList.m_pT;
    v3->m_spContList.m_pT = 0i64;
    if ( v25 )
      CAkContinuationList::Release(v25);
LABEL_25:
    *((_BYTE *)v3 + 636) |= 4u;
    return;
  }
  while ( 1 )
  {
    v5 = v3->m_spContList.m_pT;
    v6 = v5->m_listItems.m_uLength;
    v7 = v5->m_listItems.m_pItems;
    v8 = v6;
    if ( !*((_QWORD *)&v5->m_listItems.m_pItems[v6] - 2) )
    {
      v9 = CAkRanSeqCntr::GetNextToPlayContinuous(
             v7[v6 - 1].m_pContainer.m_pT,
             v3->m_pGameObj,
             &out_rwPositionSelected,
             &out_uSelectedNodeID,
             &v7[v6 - 1].m_pContainerInfo,
             &v7[v6 - 1].m_LoopingInfo);
      v10 = v9;
      if ( v9 )
      {
        v3->m_PlayHistoryForNextToPlay.HistArray.aCntrHist[v3->m_PlayHistoryForNextToPlay.HistArray.uiArraySize - 1] = out_rwPositionSelected;
        v3->m_ulNextElementToPlay = v9->key;
        v26 = CAkRanSeqCntr::TransitionMode(v7[v8 - 1].m_pContainer.m_pT);
        *((_DWORD *)v3 + 158) &= 0xFFFFFFF0;
        *((_DWORD *)v3 + 158) |= v26 & 0xF;
        v27 = *((_DWORD *)v3 + 158) << 28 >> 28;
        if ( (unsigned int)(v27 - 1) <= 2 || v27 == 5 )
          v3->m_fTransitionTime = CAkRanSeqCntr::TransitionTime(v7[v8 - 1].m_pContainer.m_pT, v3->m_pGameObj);
        else
          v3->m_fTransitionTime = 0.0;
        *((_BYTE *)v3 + 636) |= 4u;
        v10->vfptr->Release((CAkIndexable *)&v10->vfptr);
        return;
      }
      if ( --v3->m_PlayHistoryForNextToPlay.HistArray.uiArraySize )
      {
        do
        {
          v11 = v3->m_PlayHistoryForNextToPlay.HistArray.uiArraySize - 1;
          if ( v11 < 0x20 )
          {
            v12 = v3->m_PlayHistoryForNextToPlay.arrayIsContinuous.m_iBitArray;
            if ( _bittest64(&v12, v11) )
              break;
          }
          v3->m_PlayHistoryForNextToPlay.HistArray.uiArraySize = v11;
        }
        while ( v11 );
      }
      v13 = v3->m_spContList.m_pT;
      CAkContinueListItem::~CAkContinueListItem((CAkContinueListItem *)((char *)v13->m_listItems.m_pItems
                                                                      + 8 * (5i64 * v13->m_listItems.m_uLength - 5)));
      --v13->m_listItems.m_uLength;
      goto LABEL_22;
    }
    if ( v2 )
      break;
LABEL_17:
    v20 = (CAkContinuationList *)*((_QWORD *)&v7[v8] - 1);
    v21 = (CAkMultiPlayNode *)*((_QWORD *)&v7[v8] - 2);
    io_spList.m_pT = 0i64;
    CAkMultiPlayNode::ContGetList(v21, v20, &io_spList);
    v22 = v3->m_spContList.m_pT;
    CAkContinueListItem::~CAkContinueListItem((CAkContinueListItem *)((char *)v22->m_listItems.m_pItems
                                                                    + 8 * (5i64 * v22->m_listItems.m_uLength - 5)));
    --v22->m_listItems.m_uLength;
    v23 = io_spList.m_pT;
    if ( !io_spList.m_pT )
    {
      v28 = v3->m_spContList.m_pT;
      v3->m_spContList.m_pT = 0i64;
      if ( v28 )
      {
        CAkContinuationList::Release(v28);
        if ( io_spList.m_pT )
          CAkContinuationList::Release(io_spList.m_pT);
      }
      return;
    }
    CAkContinuationList::AddRef(io_spList.m_pT);
    v24 = v3->m_spContList.m_pT;
    v3->m_spContList.m_pT = v23;
    if ( v24 )
      CAkContinuationList::Release(v24);
    if ( io_spList.m_pT )
    {
      CAkContinuationList::Release(io_spList.m_pT);
      io_spList.m_pT = 0i64;
    }
LABEL_22:
    if ( !v3->m_spContList.m_pT->m_listItems.m_uLength )
      goto LABEL_23;
  }
  v14 = *((_QWORD *)&v7[v6] - 1);
  if ( !*(_DWORD *)(v14 + 8) )
    return;
  v15 = 5i64 * *(unsigned int *)(v14 + 8) - 5;
  v16 = *(_QWORD *)(*(_QWORD *)v14 + 8 * v15 + 24) == 0i64;
  v17 = *(_QWORD *)v14 + 8 * v15;
  if ( v16 )
  {
LABEL_16:
    if ( CAkRanSeqCntr::TransitionMode(*(CAkRanSeqCntr **)v17) != 5 )
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
void __usercall CAkContinuousPBI::SetEstimatedLength(CAkContinuousPBI *this@<rcx>, float in_fEstimatedLength@<xmm1>, __int64 a3@<rdx>)
{
  char v3; // al
  CAkContinuousPBI *v4; // rdi
  int v5; // ecx
  CAkActionPlayAndContinue *v6; // r14
  AkPendingAction *v7; // rax
  AkPendingAction *v8; // rax
  AkPendingAction *v9; // rsi
  signed int v10; // ebx
  signed int v11; // eax
  int v12; // eax
  int v13; // eax
  float v14; // xmm2_4
  int v15; // ebx
  CAkContinuationList *v16; // rcx
  __int64 v17; // [rsp+60h] [rbp+8h]

  v3 = *((_BYTE *)&this->0 + 373);
  v4 = this;
  if ( !(v3 & 0x10) && !(v3 & 0x20) )
  {
    LOBYTE(a3) = 1;
    ((void (__fastcall *)(CAkContinuousPBI *, __int64))this->vfptr[8].~CAkTransportAware)(this, a3);
    v5 = *((_DWORD *)v4 + 158) << 28 >> 28;
    if ( (unsigned int)(v5 - 1) <= 1 )
    {
      if ( in_fEstimatedLength < 50.0 )
        return;
    }
    else if ( v5 != 5 )
    {
      return;
    }
    if ( v4->m_ulNextElementToPlay )
    {
      v6 = CAkActionPlayAndContinue::Create(AkActionType_PlayAndContinue, 0, &v4->m_spContList);
      if ( v6 )
      {
        v7 = (AkPendingAction *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
        if ( v7 )
        {
          AkPendingAction::AkPendingAction(v7, v4->m_pGameObj);
          v9 = v8;
          if ( v8 )
          {
            v6->m_ulPauseCount = v4->m_ulPauseCount;
            CAkActionPlayAndContinue::SetHistory(v6, &v4->m_PlayHistoryForNextToPlay);
            LODWORD(v17) = v4->m_ulNextElementToPlay;
            BYTE4(v17) = 0;
            ((void (__fastcall *)(CAkActionPlayAndContinue *, __int64))v6->vfptr[1].AddRef)(v6, v17);
            CAkActionPlayAndContinue::SetInstigator(v6, v4->m_pInstigator);
            CAkActionPlayAndContinue::SetPauseResumeTransition(
              v6,
              v4->m_PBTrans.pvPRTrans,
              (*((_BYTE *)&v4->m_PBTrans + 16) >> 1) & 1,
              v9);
            CAkActionPlayAndContinue::SetPathInfo(v6, &v4->m_PathInfo);
            if ( (unsigned int)((*((_DWORD *)v4 + 158) << 28 >> 28) - 1) <= 1 )
            {
              v14 = v4->m_fTransitionTime;
              if ( v14 >= (float)(in_fEstimatedLength * 0.5) )
                v14 = in_fEstimatedLength;
              v10 = AkTimeConv::MillisecondsToSamples((float)(in_fEstimatedLength - v14));
              CAkActionPlayAndContinue::SetFadeBack(v6, v4, (signed int)v14);
            }
            else
            {
              v10 = AkTimeConv::MillisecondsToSamples(v4->m_fTransitionTime);
              v11 = 1024;
              if ( *((_BYTE *)&v4->0 + 374) < 0 )
                v11 = 8;
              if ( v10 < v11 )
                v10 = v11;
              v12 = v4->m_iFrameOffset;
              if ( *((_BYTE *)&v4->0 + 374) < 0 )
                v13 = v12 + 8;
              else
                v13 = v12 + 1024;
              if ( v13 > 0 )
                v10 += v13;
              CAkActionPlayAndContinue::SetPlayStopTransition(
                v6,
                v4->m_PBTrans.pvPSTrans,
                *((_BYTE *)&v4->m_PBTrans + 16) & 1,
                v9);
            }
            if ( ((unsigned int (__fastcall *)(CAkActionPlayAndContinue *, signed __int64, _QWORD))v6->vfptr[1].Release)(
                   v6,
                   14i64,
                   (unsigned int)v10) == 1 )
            {
              v9->pAction = (CAkAction *)&v6->vfptr;
              UserParams::operator=(&v9->UserParam, &v4->m_UserParams);
              CAkAudioMgr::EnqueueOrExecuteAction(g_pAudioMgr, v9);
              if ( v10 >= 1024 && v4->m_ulPauseCount )
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
        v6->vfptr->Release((CAkIndexable *)&v6->vfptr);
        *((_BYTE *)&v4->0 + 373) |= 2u;
      }
      v16 = v4->m_spContList.m_pT;
      v4->m_spContList.m_pT = 0i64;
      if ( v16 )
        CAkContinuationList::Release(v16);
      v4->m_ulNextElementToPlay = 0;
    }
  }
}

// File Line: 626
// RVA: 0xA75D30
void __fastcall CAkContinuousPBI::PrepareSampleAccurateTransition(CAkContinuousPBI *this, __int64 a2)
{
  CAkContinuousPBI *v2; // rdi
  CAkActionPlayAndContinue *v3; // rsi
  AkPendingAction *v4; // rax
  AkPendingAction *v5; // rax
  AkPendingAction *v6; // r14
  int v7; // ebx
  CAkContinuationList *v8; // rcx
  __int64 v9; // [rsp+40h] [rbp+8h]

  v2 = this;
  if ( !(*((_BYTE *)&this->0 + 373) & 0x10) )
  {
    LOBYTE(a2) = 1;
    ((void (__fastcall *)(CAkContinuousPBI *, __int64))this->vfptr[8].~CAkTransportAware)(this, a2);
    if ( (*((_DWORD *)v2 + 158) & 0xF) == 4 )
    {
      if ( v2->m_ulNextElementToPlay )
      {
        v3 = CAkActionPlayAndContinue::Create(AkActionType_PlayAndContinue, 0, &v2->m_spContList);
        if ( v3 )
        {
          v4 = (AkPendingAction *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
          if ( v4 )
          {
            AkPendingAction::AkPendingAction(v4, v2->m_pGameObj);
            v6 = v5;
            if ( v5 )
            {
              v3->m_ulPauseCount = v2->m_ulPauseCount;
              CAkActionPlayAndContinue::SetHistory(v3, &v2->m_PlayHistoryForNextToPlay);
              LODWORD(v9) = v2->m_ulNextElementToPlay;
              BYTE4(v9) = 0;
              ((void (__fastcall *)(CAkActionPlayAndContinue *, __int64))v3->vfptr[1].AddRef)(v3, v9);
              CAkActionPlayAndContinue::SetInstigator(v3, v2->m_pInstigator);
              if ( CAkActionPlayAndContinue::SetPlayStopTransition(
                     v3,
                     v2->m_PBTrans.pvPSTrans,
                     *((_BYTE *)&v2->m_PBTrans + 16) & 1,
                     v6) != 1
                || CAkActionPlayAndContinue::SetPauseResumeTransition(
                     v3,
                     v2->m_PBTrans.pvPRTrans,
                     (*((_BYTE *)&v2->m_PBTrans + 16) >> 1) & 1,
                     v6) != 1 )
              {
                v7 = g_DefaultPoolId;
                ((void (__fastcall *)(AkPendingAction *, _QWORD))v6->vfptr[1].TransUpdateValue)(v6, 0i64);
                AK::MemoryMgr::Free(v7, v6);
              }
              else
              {
                CAkActionPlayAndContinue::SetPathInfo(v3, &v2->m_PathInfo);
                if ( *((_BYTE *)&v2->0 + 373) & 0x40 )
                  CAkActionPlayAndContinue::StartAsPaused(v3);
                CAkActionPlayAndContinue::SetSAInfo(v3, v2->m_SeqID);
                v6->pAction = (CAkAction *)&v3->vfptr;
                UserParams::operator=(&v6->UserParam, &v2->m_UserParams);
                CAkAudioMgr::EnqueueOrExecuteAction(g_pAudioMgr, v6);
              }
            }
          }
          v3->vfptr->Release((CAkIndexable *)&v3->vfptr);
          *((_BYTE *)&v2->0 + 373) |= 2u;
        }
        v8 = v2->m_spContList.m_pT;
        v2->m_spContList.m_pT = 0i64;
        if ( v8 )
          CAkContinuationList::Release(v8);
        v2->m_ulNextElementToPlay = 0;
      }
    }
  }
}

// File Line: 691
// RVA: 0xA76600
void __fastcall CAkContinuousPBI::_Stop(CAkContinuousPBI *this, AkPBIStopMode in_eStopMode, bool in_bIsFromTransition, bool in_bHasNotStarted)
{
  CAkContinuousPBI *v4; // rbx
  CAkContinuationList *v5; // rcx
  bool v6; // di
  bool v7; // si
  AkPBIStopMode v8; // ebp

  *((_BYTE *)this + 636) |= 4u;
  v4 = this;
  this->m_ulNextElementToPlay = 0;
  v5 = this->m_spContList.m_pT;
  v6 = in_bHasNotStarted;
  v7 = in_bIsFromTransition;
  v8 = in_eStopMode;
  v4->m_spContList.m_pT = 0i64;
  if ( v5 )
    CAkContinuationList::Release(v5);
  CAkPBI::_Stop((CAkPBI *)&v4->vfptr, v8, v7, v6);
}

// File Line: 701
// RVA: 0xA75760
void __fastcall CAkContinuousPBI::PlayToEnd(CAkContinuousPBI *this, CAkParameterNodeBase *in_pNode)
{
  CAkParameterNodeBase *v2; // rbp
  unsigned int v3; // edx
  CAkContinuousPBI *v4; // rbx
  CAkParameterNode *v5; // rsi
  CAkContinuationList *v6; // rax
  CAkContinuationList *v7; // rdx
  signed __int64 v8; // r9
  CAkMultiPlayNode *v9; // rcx
  bool v10; // zf
  unsigned int v11; // edx
  __int64 v12; // rcx
  CAkContinuationList *v13; // rdi
  CAkContinuationList *v14; // rdx
  CAkContinuationList *v15; // rdi
  CAkContinuationList *v16; // rdi
  CAkContinuationList *v17; // rcx
  CAkContinuationList *v18; // rcx
  CAkSmartPtr<CAkContinuationList> io_spList; // [rsp+40h] [rbp+8h]

  v2 = in_pNode;
  v3 = this->m_ulNextElementToPlay;
  v4 = this;
  v5 = 0i64;
  if ( v3 )
    v5 = (CAkParameterNode *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v3, 0);
  if ( !(*((_BYTE *)v4 + 636) & 4) || !v4->m_ulNextElementToPlay || CAkParameterNode::IsOrIsChildOf(v5, v2, 0) )
  {
    v6 = v4->m_spContList.m_pT;
    *((_BYTE *)v4 + 636) &= 0xFBu;
    v4->m_ulNextElementToPlay = 0;
    if ( v6 )
    {
      if ( v6->m_listItems.m_uLength )
      {
        do
        {
          v7 = v4->m_spContList.m_pT;
          v8 = (signed __int64)&v7->m_listItems.m_pItems[v7->m_listItems.m_uLength];
          v9 = *(CAkMultiPlayNode **)(v8 - 16);
          if ( v9 )
          {
            v14 = *(CAkContinuationList **)(v8 - 8);
            io_spList.m_pT = 0i64;
            CAkMultiPlayNode::ContGetList(v9, v14, &io_spList);
            v15 = v4->m_spContList.m_pT;
            CAkContinueListItem::~CAkContinueListItem((CAkContinueListItem *)((char *)v15->m_listItems.m_pItems
                                                                            + 8
                                                                            * (5i64 * v15->m_listItems.m_uLength - 5)));
            --v15->m_listItems.m_uLength;
            v16 = io_spList.m_pT;
            if ( io_spList.m_pT )
            {
              CAkContinuationList::AddRef(io_spList.m_pT);
              v17 = v4->m_spContList.m_pT;
              v4->m_spContList.m_pT = v16;
              if ( v17 )
                CAkContinuationList::Release(v17);
              if ( io_spList.m_pT )
                CAkContinuationList::Release(io_spList.m_pT);
            }
          }
          else
          {
            if ( !CAkParameterNode::IsOrIsChildOf(*(CAkParameterNode **)(v8 - 40), v2, 0) )
              break;
            v10 = v4->m_PlayHistoryForNextToPlay.HistArray.uiArraySize-- == 1;
            if ( !v10 )
            {
              do
              {
                v11 = v4->m_PlayHistoryForNextToPlay.HistArray.uiArraySize - 1;
                if ( v11 < 0x20 )
                {
                  v12 = v4->m_PlayHistoryForNextToPlay.arrayIsContinuous.m_iBitArray;
                  if ( _bittest64(&v12, v11) )
                    break;
                }
                v4->m_PlayHistoryForNextToPlay.HistArray.uiArraySize = v11;
              }
              while ( v11 );
            }
            v13 = v4->m_spContList.m_pT;
            CAkContinueListItem::~CAkContinueListItem((CAkContinueListItem *)((char *)v13->m_listItems.m_pItems
                                                                            + 8
                                                                            * (5i64 * v13->m_listItems.m_uLength - 5)));
            --v13->m_listItems.m_uLength;
          }
        }
        while ( v4->m_spContList.m_pT->m_listItems.m_uLength );
      }
      v18 = v4->m_spContList.m_pT;
      if ( !v18->m_listItems.m_uLength )
      {
        v4->m_spContList.m_pT = 0i64;
        if ( v18 )
          CAkContinuationList::Release(v18);
      }
    }
  }
  if ( v5 )
    v5->vfptr->Release((CAkIndexable *)&v5->vfptr);
  CAkPBI::PlayToEnd((CAkPBI *)&v4->vfptr, v2);
}

// File Line: 773
// RVA: 0xA76290
void __fastcall CAkContinuousPBI::SetPauseStateForContinuous(CAkContinuousPBI *this, bool in_bIsPaused)
{
  *((_BYTE *)this + 636) &= 0xFDu;
  *((_BYTE *)this + 636) |= 2 * in_bIsPaused;
}

