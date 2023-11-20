// File Line: 60
// RVA: 0xA74D60
void __fastcall CAkDynamicSequencePBI::CAkDynamicSequencePBI(CAkDynamicSequencePBI *this, CAkSoundBase *in_pSound, CAkSource *in_pSource, CAkRegisteredObj *in_pGameObj, ContParams *in_rCparameters, UserParams *in_rUserparams, PlayHistory *in_rPlayHistory, bool in_bIsFirst, unsigned int in_SeqID, CAkPBIAware *in_pInstigator, PriorityInfoCurrent *in_rPriority, AK::SoundEngine::DynamicSequence::DynamicSequenceType in_eDynamicSequenceType, CAkLimiter *in_pAMLimiter, CAkLimiter *in_pBusLimiter)
{
  CAkDynamicSequencePBI *v14; // rbx
  CAkPBIAware *v15; // rcx

  v14 = this;
  CAkContinuousPBI::CAkContinuousPBI(
    (CAkContinuousPBI *)&this->vfptr,
    in_pSound,
    in_pSource,
    in_pGameObj,
    in_rCparameters,
    in_rUserparams,
    in_rPlayHistory,
    in_bIsFirst,
    in_SeqID,
    in_pInstigator,
    in_rPriority,
    0,
    in_pAMLimiter,
    in_pBusLimiter);
  v15 = v14->m_pInstigator;
  v14->m_bRequestNextFromDynSeq = 1;
  v14->vfptr = (CAkTransportAwareVtbl *)&CAkDynamicSequencePBI::`vftable'{for `CAkTransportAware'};
  v14->vfptr = (ITransitionableVtbl *)&CAkContinuousPBI::`vftable'{for `ITransitionable'};
  v14->m_eDynamicSequenceType = in_eDynamicSequenceType;
  v14->m_startingNode = v15[6].key;
  v14->m_pDynSecCustomInfo = v15[7].vfptr;
}

// File Line: 72
// RVA: 0xA75180
void __fastcall CAkDynamicSequencePBI::Term(CAkDynamicSequencePBI *this, bool in_bFailedToInit)
{
  bool v2; // di
  CAkDynamicSequencePBI *v3; // rbx

  v2 = in_bFailedToInit;
  v3 = this;
  if ( !in_bFailedToInit )
    CAkPlayingMgr::NotifyEndOfDynamicSequenceItem(
      g_pPlayingMgr,
      this->m_UserParams.m_PlayingID,
      this->m_startingNode,
      this->m_pDynSecCustomInfo);
  CAkContinuousPBI::Term((CAkContinuousPBI *)&v3->vfptr, v2);
}

// File Line: 83
// RVA: 0xA75060
void __fastcall CAkDynamicSequencePBI::PrepareNextToPlay(CAkDynamicSequencePBI *this, bool in_bIsPreliminary)
{
  bool v2; // di
  CAkDynamicSequencePBI *v3; // rbx
  CAkDynamicSequence *v4; // rsi
  CAkDynamicSequence *v5; // rcx
  unsigned int i; // edi
  int out_delay; // [rsp+40h] [rbp+8h]
  void *out_rpCustomParam; // [rsp+50h] [rbp+18h]

  v2 = in_bIsPreliminary;
  v3 = this;
  CAkContinuousPBI::PrepareNextToPlay((CAkContinuousPBI *)&this->vfptr, in_bIsPreliminary);
  if ( *((_BYTE *)&v3->0 + 636) & 4 && !(*((_BYTE *)&v3->0 + 373) & 0x10) )
  {
    if ( v3->m_ulNextElementToPlay )
    {
      v3->m_bRequestNextFromDynSeq = 0;
    }
    else if ( v3->m_bRequestNextFromDynSeq && (!v2 || v3->m_eDynamicSequenceType == DynamicSequenceType_SampleAccurate) )
    {
      v4 = (CAkDynamicSequence *)v3->m_pInstigator;
      v5 = (CAkDynamicSequence *)v3->m_pInstigator;
      v3->m_bRequestNextFromDynSeq = 0;
      out_rpCustomParam = 0i64;
      out_delay = 0;
      for ( i = CAkDynamicSequence::GetNextToPlay(v5, &out_delay, &out_rpCustomParam, &v3->m_UserParams);
            i;
            i = CAkDynamicSequence::GetNextToPlay(v4, &out_delay, &out_rpCustomParam, &v3->m_UserParams) )
      {
        if ( (unsigned int)CAkDynamicSequencePBI::PlayNextElement(v3, i, out_delay) == 1 )
          break;
        CAkPlayingMgr::NotifyEndOfDynamicSequenceItem(g_pPlayingMgr, v3->m_UserParams.m_PlayingID, i, out_rpCustomParam);
        out_rpCustomParam = 0i64;
        out_delay = 0;
      }
    }
  }
}

// File Line: 125
// RVA: 0xA74E90
signed __int64 __fastcall CAkDynamicSequencePBI::PlayNextElement(CAkDynamicSequencePBI *this, unsigned int in_nextElementID, int in_delay)
{
  CAkDynamicSequencePBI *v3; // rbx
  int v4; // esi
  CAkParameterNode *v5; // rdi
  unsigned __int8 v7; // cl
  CAkPBIAware *v9; // rax
  __int64 v10; // rax
  AkExternalSourceArray *v11; // rax
  unsigned int v12; // eax
  unsigned int v13; // esi
  char v14; // al
  CAkTransition *v15; // [rsp+20h] [rbp-89h]
  CAkTransition *v16; // [rsp+28h] [rbp-81h]
  AkPathInfo *v17; // [rsp+30h] [rbp-79h]
  char v18; // [rsp+38h] [rbp-71h]
  char v19; // [rsp+39h] [rbp-70h]
  CAkContinuationList *v20; // [rsp+40h] [rbp-69h]
  unsigned int v21; // [rsp+48h] [rbp-61h]
  AkPBIParams in_rPBIParams; // [rsp+50h] [rbp-59h]
  int v23; // [rsp+128h] [rbp+7Fh]
  int v24; // [rsp+12Ch] [rbp+83h]

  v3 = this;
  v4 = in_delay;
  v5 = (CAkParameterNode *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_nextElementID, 0);
  if ( !v5 )
    return 2i64;
  v7 = *((_BYTE *)&v3->m_PBTrans + 16);
  v15 = v3->m_PBTrans.pvPSTrans;
  v16 = v3->m_PBTrans.pvPRTrans;
  v20 = 0i64;
  v17 = &v3->m_PathInfo;
  v21 = v3->m_ulPauseCount;
  v19 = (v7 >> 1) & 1;
  v18 = v7 & 1;
  v20 = CAkContinuationList::Create();
  v9 = v3->m_pInstigator;
  v23 = 0;
  v24 = 9;
  in_rPBIParams.pInstigator = v9;
  LODWORD(v9) = v3->m_UserParams.m_PlayingID;
  in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = 0i64;
  in_rPBIParams.userParams.m_PlayingID = (unsigned int)v9;
  v10 = v3->m_UserParams.m_CustomParam.customParam;
  in_rPBIParams.playHistory.arrayIsContinuous.m_iBitArray = 0;
  in_rPBIParams.userParams.m_CustomParam.customParam = v10;
  LODWORD(v10) = v3->m_UserParams.m_CustomParam.ui32Reserved;
  in_rPBIParams.bSkipDelay = 0;
  in_rPBIParams.userParams.m_CustomParam.ui32Reserved = v10;
  v11 = v3->m_UserParams.m_CustomParam.pExternalSrcs;
  in_rPBIParams.bTargetFeedback = 0;
  in_rPBIParams.playHistory.HistArray.uiArraySize = 0;
  in_rPBIParams.eType = 2;
  if ( v11 )
    ++v11->m_cRefCount;
  in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = v11;
  in_rPBIParams.ePlaybackState = 0;
  in_rPBIParams.bIsFirst = 0;
  in_rPBIParams.pGameObj = v3->m_pGameObj;
  in_rPBIParams.pTransitionParameters = (TransParams *)&v23;
  in_rPBIParams.uFrameOffset = v4 * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
  in_rPBIParams.pContinuousParams = (ContParams *)&v15;
  in_rPBIParams.sequenceID = v3->m_SeqID;
  v12 = CAkParameterNode::HandleInitialDelay(v5, &in_rPBIParams);
  v13 = v12;
  if ( v12 == 3 )
  {
    v13 = 1;
  }
  else if ( v12 == 1 )
  {
    v13 = ((__int64 (__fastcall *)(CAkParameterNode *, AkPBIParams *))v5->vfptr[19].Category)(v5, &in_rPBIParams);
  }
  v14 = *((_BYTE *)&v3->0 + 373);
  if ( v14 & 1 )
    *((_BYTE *)&v3->0 + 373) = v14 | 2;
  v5->vfptr->Release((CAkIndexable *)&v5->vfptr);
  ++CAkLEngineCmds::m_ulPlayEventID;
  if ( in_rPBIParams.userParams.m_CustomParam.pExternalSrcs )
    AkExternalSourceArray::Release(in_rPBIParams.userParams.m_CustomParam.pExternalSrcs);
  if ( v20 )
    CAkContinuationList::Release(v20);
  return v13;
}

