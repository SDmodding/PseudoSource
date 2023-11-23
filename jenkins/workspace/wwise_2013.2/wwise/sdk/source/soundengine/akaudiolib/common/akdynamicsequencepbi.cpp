// File Line: 60
// RVA: 0xA74D60
void __fastcall CAkDynamicSequencePBI::CAkDynamicSequencePBI(
        CAkDynamicSequencePBI *this,
        CAkSoundBase *in_pSound,
        CAkSource *in_pSource,
        CAkRegisteredObj *in_pGameObj,
        ContParams *in_rCparameters,
        UserParams *in_rUserparams,
        PlayHistory *in_rPlayHistory,
        bool in_bIsFirst,
        unsigned int in_SeqID,
        CAkPBIAware *in_pInstigator,
        PriorityInfoCurrent *in_rPriority,
        AK::SoundEngine::DynamicSequence::DynamicSequenceType in_eDynamicSequenceType,
        CAkLimiter *in_pAMLimiter,
        CAkLimiter *in_pBusLimiter)
{
  CAkPBIAware *m_pInstigator; // rcx

  CAkContinuousPBI::CAkContinuousPBI(
    this,
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
  m_pInstigator = this->m_pInstigator;
  this->m_bRequestNextFromDynSeq = 1;
  this->CAkContinuousPBI::CAkPBI::CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkDynamicSequencePBI::`vftable{for `CAkTransportAware};
  this->CAkContinuousPBI::CAkPBI::ITransitionable::vfptr = (ITransitionableVtbl *)&CAkContinuousPBI::`vftable{for `ITransitionable};
  this->m_eDynamicSequenceType = in_eDynamicSequenceType;
  this->m_startingNode = m_pInstigator[6].key;
  this->m_pDynSecCustomInfo = m_pInstigator[7].vfptr;
}

// File Line: 72
// RVA: 0xA75180
void __fastcall CAkDynamicSequencePBI::Term(CAkDynamicSequencePBI *this, bool in_bFailedToInit)
{
  if ( !in_bFailedToInit )
    CAkPlayingMgr::NotifyEndOfDynamicSequenceItem(
      g_pPlayingMgr,
      this->m_UserParams.m_PlayingID,
      this->m_startingNode,
      (__int64)this->m_pDynSecCustomInfo);
  CAkContinuousPBI::Term(this, in_bFailedToInit);
}

// File Line: 83
// RVA: 0xA75060
void __fastcall CAkDynamicSequencePBI::PrepareNextToPlay(CAkDynamicSequencePBI *this, bool in_bIsPreliminary)
{
  CAkDynamicSequence *m_pInstigator; // rsi
  unsigned int i; // edi
  int out_delay; // [rsp+40h] [rbp+8h] BYREF
  void *out_rpCustomParam; // [rsp+50h] [rbp+18h] BYREF

  CAkContinuousPBI::PrepareNextToPlay(this, in_bIsPreliminary);
  if ( (*((_BYTE *)&this->CAkContinuousPBI + 636) & 4) != 0 && (*((_BYTE *)&this->CAkPBI + 373) & 0x10) == 0 )
  {
    if ( this->m_ulNextElementToPlay )
    {
      this->m_bRequestNextFromDynSeq = 0;
    }
    else if ( this->m_bRequestNextFromDynSeq
           && (!in_bIsPreliminary || this->m_eDynamicSequenceType == DynamicSequenceType_SampleAccurate) )
    {
      m_pInstigator = (CAkDynamicSequence *)this->m_pInstigator;
      this->m_bRequestNextFromDynSeq = 0;
      out_rpCustomParam = 0i64;
      out_delay = 0;
      for ( i = CAkDynamicSequence::GetNextToPlay(m_pInstigator, &out_delay, &out_rpCustomParam, &this->m_UserParams);
            i;
            i = CAkDynamicSequence::GetNextToPlay(m_pInstigator, &out_delay, &out_rpCustomParam, &this->m_UserParams) )
      {
        if ( (unsigned int)CAkDynamicSequencePBI::PlayNextElement(this, i, out_delay) == 1 )
          break;
        CAkPlayingMgr::NotifyEndOfDynamicSequenceItem(
          g_pPlayingMgr,
          this->m_UserParams.m_PlayingID,
          i,
          (__int64)out_rpCustomParam);
        out_rpCustomParam = 0i64;
        out_delay = 0;
      }
    }
  }
}

// File Line: 125
// RVA: 0xA74E90
__int64 __fastcall CAkDynamicSequencePBI::PlayNextElement(
        CAkDynamicSequencePBI *this,
        unsigned int in_nextElementID,
        int in_delay)
{
  CAkParameterNode *NodePtrAndAddRef; // rdi
  char v7; // cl
  CAkPBIAware *m_pInstigator; // rax
  __int64 customParam; // rax
  AkExternalSourceArray *pExternalSrcs; // rax
  unsigned int v11; // eax
  unsigned int v12; // esi
  char v13; // al
  __int64 v14[3]; // [rsp+20h] [rbp-89h] BYREF
  char v15; // [rsp+38h] [rbp-71h]
  bool v16; // [rsp+39h] [rbp-70h]
  CAkContinuationList *v17; // [rsp+40h] [rbp-69h]
  unsigned int m_ulPauseCount; // [rsp+48h] [rbp-61h]
  AkPBIParams in_rPBIParams; // [rsp+50h] [rbp-59h] BYREF
  int v20; // [rsp+128h] [rbp+7Fh] BYREF
  int v21; // [rsp+12Ch] [rbp+83h]

  NodePtrAndAddRef = (CAkParameterNode *)CAkAudioLibIndex::GetNodePtrAndAddRef(
                                           g_pIndex,
                                           in_nextElementID,
                                           AkNodeType_Default);
  if ( !NodePtrAndAddRef )
    return 2i64;
  v7 = *((_BYTE *)&this->m_PBTrans + 16);
  v14[0] = (__int64)this->m_PBTrans.pvPSTrans;
  v14[1] = (__int64)this->m_PBTrans.pvPRTrans;
  v17 = 0i64;
  v14[2] = (__int64)&this->m_PathInfo;
  m_ulPauseCount = this->m_ulPauseCount;
  v16 = (v7 & 2) != 0;
  v15 = v7 & 1;
  v17 = CAkContinuationList::Create();
  m_pInstigator = this->m_pInstigator;
  v20 = 0;
  v21 = 9;
  in_rPBIParams.pInstigator = m_pInstigator;
  LODWORD(m_pInstigator) = this->m_UserParams.m_PlayingID;
  in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = 0i64;
  in_rPBIParams.userParams.m_PlayingID = (unsigned int)m_pInstigator;
  customParam = this->m_UserParams.m_CustomParam.customParam;
  in_rPBIParams.playHistory.arrayIsContinuous.m_iBitArray = 0;
  in_rPBIParams.userParams.m_CustomParam.customParam = customParam;
  LODWORD(customParam) = this->m_UserParams.m_CustomParam.ui32Reserved;
  in_rPBIParams.bSkipDelay = 0;
  in_rPBIParams.userParams.m_CustomParam.ui32Reserved = customParam;
  pExternalSrcs = this->m_UserParams.m_CustomParam.pExternalSrcs;
  in_rPBIParams.bTargetFeedback = 0;
  in_rPBIParams.playHistory.HistArray.uiArraySize = 0;
  in_rPBIParams.eType = DynamicSequencePBI;
  if ( pExternalSrcs )
    ++pExternalSrcs->m_cRefCount;
  in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = pExternalSrcs;
  in_rPBIParams.ePlaybackState = PB_Playing;
  in_rPBIParams.bIsFirst = 0;
  in_rPBIParams.pGameObj = this->m_pGameObj;
  in_rPBIParams.pTransitionParameters = (TransParams *)&v20;
  in_rPBIParams.uFrameOffset = in_delay * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
  in_rPBIParams.pContinuousParams = (ContParams *)v14;
  in_rPBIParams.sequenceID = this->m_SeqID;
  v11 = CAkParameterNode::HandleInitialDelay(NodePtrAndAddRef, &in_rPBIParams);
  v12 = v11;
  if ( v11 == 3 )
  {
    v12 = 1;
  }
  else if ( v11 == 1 )
  {
    v12 = ((__int64 (__fastcall *)(CAkParameterNode *, AkPBIParams *))NodePtrAndAddRef->vfptr[19].Category)(
            NodePtrAndAddRef,
            &in_rPBIParams);
  }
  v13 = *((_BYTE *)&this->CAkPBI + 373);
  if ( (v13 & 1) != 0 )
    *((_BYTE *)&this->CAkPBI + 373) = v13 | 2;
  NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef);
  ++CAkLEngineCmds::m_ulPlayEventID;
  if ( in_rPBIParams.userParams.m_CustomParam.pExternalSrcs )
    AkExternalSourceArray::Release(in_rPBIParams.userParams.m_CustomParam.pExternalSrcs);
  if ( v17 )
    CAkContinuationList::Release(v17);
  return v12;
}

