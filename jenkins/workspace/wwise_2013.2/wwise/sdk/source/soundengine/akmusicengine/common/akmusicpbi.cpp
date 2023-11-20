// File Line: 66
// RVA: 0xAAAE00
void __fastcall CAkMusicPBI::CAkMusicPBI(CAkMusicPBI *this, CAkMusicCtx *in_parent, CAkSoundBase *in_pSound, CAkSource *in_pSource, CAkRegisteredObj *in_pGameObj, UserParams *in_UserParams, AkTrackSrc *in_pSrcInfo, PlayHistory *in_rPlayHistory, unsigned int in_SeqID, PriorityInfoCurrent *in_Priority, unsigned int in_uSourceOffset, CAkLimiter *in_pAMLimiter, CAkLimiter *in_pBusLimiter)
{
  CAkMusicCtx *v13; // rdi
  CAkMusicPBI *v14; // rsi

  v13 = in_parent;
  v14 = this;
  CAkPBI::CAkPBI(
    (CAkPBI *)&this->vfptr,
    in_pSound,
    in_pSource,
    in_pGameObj,
    in_UserParams,
    in_rPlayHistory,
    in_SeqID,
    in_Priority,
    0,
    in_uSourceOffset,
    in_pAMLimiter,
    in_pBusLimiter);
  CAkChildCtx::CAkChildCtx((CAkChildCtx *)&v14->vfptr, v13);
  *((_DWORD *)v14 + 144) &= 0xFFFFFFFC;
  *((_BYTE *)&v14->0 + 374) &= 0xDFu;
  v14->m_ulStopOffset = -1;
  v14->vfptr = (CAkTransportAwareVtbl *)&CAkMusicPBI::`vftable{for `CAkTransportAware};
  v14->vfptr = (ITransitionableVtbl *)&CAkContinuousPBI::`vftable{for `ITransitionable};
  v14->vfptr = (CAkChildCtxVtbl *)&CAkMusicPBI::`vftable;
  v14->m_pSrcInfo = in_pSrcInfo;
}

// File Line: 77
// RVA: 0xAAB210
void __fastcall CAkMusicPBI::Term(CAkMusicPBI *this, bool in_bFailedToInit)
{
  bool v2; // di
  CAkMusicPBI *v3; // rbx

  v2 = in_bFailedToInit;
  v3 = this;
  if ( !(*((_BYTE *)this + 576) & 1) )
    CAkSegmentCtx::RemoveAllReferences((CAkSegmentCtx *)this->m_pParentCtx, (CAkPBI *)&this->vfptr);
  CAkMusicCtx::RemoveChild(v3->m_pParentCtx, (CAkChildCtx *)&v3->vfptr);
  CAkPBI::Term((CAkPBI *)&v3->vfptr, v2);
}

// File Line: 91
// RVA: 0xAAB040
AKRESULT __fastcall CAkMusicPBI::Init(CAkMusicPBI *this, AkPathInfo *in_pPathInfo)
{
  CAkMusicPBI *v2; // rdi
  AkPathInfo *v3; // rbx

  v2 = this;
  v3 = in_pPathInfo;
  CAkChildCtx::Connect((CAkChildCtx *)&this->vfptr);
  return CAkPBI::Init((CAkPBI *)&v2->vfptr, v3);
}

// File Line: 111
// RVA: 0xAAB270
void __fastcall CAkMusicPBI::_Stop(CAkMusicPBI *this, AkPBIStopMode in_eStopMode, bool in_bIsFromTransition, bool in_bHasNotStarted)
{
  if ( !in_bHasNotStarted || this->m_ulStopOffset == -1 )
    CAkPBI::_Stop((CAkPBI *)&this->vfptr, in_eStopMode, in_bIsFromTransition, 0);
}

// File Line: 118
// RVA: 0xAAB1A0
void __fastcall CAkMusicPBI::SetAutomationValue(CAkMusicPBI *this, AkClipAutomationType in_eAutomationType, float in_fValue)
{
  if ( in_eAutomationType == AutomationType_Volume )
    goto LABEL_9;
  if ( in_eAutomationType == 1 )
  {
    this->m_LPFAutomationOffset = in_fValue;
    CAkPBI::CalculateEffectiveLPF((CAkPBI *)&this->vfptr);
    return;
  }
  if ( (unsigned int)(in_eAutomationType - 2) <= 1 )
LABEL_9:
    ((void (__fastcall *)(CAkChildCtxVtbl **, char *))this->vfptr->SetPBIFade)(
      &this->vfptr,
      (char *)this + (signed int)in_eAutomationType);
}

// File Line: 152
// RVA: 0xAAB0E0
void __fastcall CAkMusicPBI::OnLastFrame(CAkMusicPBI *this, unsigned int in_uNumSamples, __int64 a3, _BOOL8 a4)
{
  bool v4; // zf
  TransParams in_transParams; // [rsp+30h] [rbp+8h]

  if ( in_uNumSamples < LODWORD(this->pNextItem) && in_uNumSamples != -1 )
    LODWORD(this->pNextItem) = in_uNumSamples;
  v4 = LODWORD(this->pNextItem) == -1;
  in_transParams.TransitionTime = 0;
  if ( v4 || (_QWORD)this->m_pUsageSlot & 2 )
    LOBYTE(a3) = 1;
  else
    a3 = 0i64;
  CAkPBI::_Stop((CAkPBI *)&this[-1].m_mapMutedNodes, &in_transParams, a3, a4);
}

// File Line: 166
// RVA: 0xAAB130
void __fastcall CAkMusicPBI::OnPaused(CAkMusicPBI *this, __int64 a2)
{
  LOBYTE(a2) = 1;
  (*(void (__fastcall **)(CAkKeyArray<AkMutedMapItem,float,2> *, __int64))&this[-1].m_mapMutedNodes.m_pItems[1].item)(
    &this[-1].m_mapMutedNodes,
    a2);
}

// File Line: 173
// RVA: 0xAAB140
void __fastcall CAkMusicPBI::OnResumed(CAkMusicPBI *this)
{
  CAkMusicPBI *v1; // rdi

  v1 = this;
  ((void (__fastcall *)(CAkKeyArray<AkMutedMapItem,float,2> *))this[-1].m_mapMutedNodes.m_pItems[2].key.m_Identifier)(&this[-1].m_mapMutedNodes);
  *(_DWORD *)&v1[-1].m_CntrHistArray.aCntrHist[20] = 1065353216;
  CAkPBI::CalculateMutedEffectiveVolume((CAkPBI *)&v1[-1].m_mapMutedNodes);
}

// File Line: 219
// RVA: 0xAAB290
void __fastcall CAkMusicPBI::_Stop(CAkMusicPBI *this, __int64 in_uStopOffset)
{
  *((_DWORD *)this + 144) |= 1u;
  this->vfptr->OnLastFrame(&this->vfptr, in_uStopOffset);
}

// File Line: 234
// RVA: 0xAAB1E0
void __fastcall CAkMusicPBI::SetPBIFade(CAkMusicPBI *this, void *in_pOwner, float in_fFadeRatio)
{
  AkMutedMapItem in_key; // [rsp+20h] [rbp-18h]

  in_key.m_Identifier = in_pOwner;
  *((_DWORD *)&in_key + 2) = *((_DWORD *)&in_key + 2) & 0xFFFFFFFE | 2;
  CAkPBI::SetMuteMapEntry((CAkPBI *)&this[-1].m_mapMutedNodes, &in_key, in_fFadeRatio);
}

// File Line: 244
// RVA: 0xAAAF80
void __fastcall CAkMusicPBI::FixStartTimeForFadeIn(CAkMusicPBI *this)
{
  int v1; // er8
  CAkMusicPBI *v2; // rdx
  int v3; // eax
  signed int v4; // ecx

  v1 = this->m_iFrameOffset;
  v2 = this;
  v3 = this->m_iFrameOffset % 1024;
  if ( v3 > 512 || (v4 = this->m_uSeekPosition, v3 > v4) )
  {
    *((_BYTE *)&v2->0 + 375) &= 0xF3u;
    *((_BYTE *)&v2->0 + 375) |= 0x82u;
    v2->m_uSeekPosition += 1024 - v3;
    v2->m_iFrameOffset = v1 + 1024 - v3;
  }
  else if ( v3 <= 0 )
  {
    *((_BYTE *)&v2->0 + 375) |= 0x80u;
  }
  else
  {
    *((_BYTE *)&v2->0 + 375) &= 0xF3u;
    *((_BYTE *)&v2->0 + 375) |= 0x82u;
    v2->m_iFrameOffset = v1 - v3;
    v2->m_uSeekPosition = v4 - v3;
  }
}

// File Line: 266
// RVA: 0xAAB030
__int64 __fastcall CAkMusicPBI::GetStopOffset(CAkMusicPBI *this)
{
  return this->m_ulStopOffset;
}

// File Line: 271
// RVA: 0xAAB010
signed __int64 __fastcall CAkMusicPBI::GetAndClearStopOffset(CAkMusicPBI *this)
{
  unsigned int v1; // edx
  signed __int64 result; // rax
  bool v3; // zf

  v1 = this->m_ulStopOffset;
  result = 0xFFFFFFFFi64;
  v3 = (*((_BYTE *)this + 576) & 2) == 0;
  this->m_ulStopOffset = -1;
  if ( v3 )
    result = v1;
  return result;
}

// File Line: 278
// RVA: 0xAAB080
signed __int64 __fastcall CAkMusicPBI::NotifyVirtualOff(CAkMusicPBI *this, AkVirtualQueueBehavior in_eBehavior)
{
  CAkMusicPBI *v2; // rbx
  int v3; // eax
  int out_iLookAhead; // [rsp+30h] [rbp+8h]
  int out_iSourceOffset; // [rsp+40h] [rbp+18h]

  v2 = this;
  if ( !CAkSegmentCtx::GetSourceInfoForPlaybackRestart(
          (CAkSegmentCtx *)this->m_pParentCtx,
          this,
          &out_iLookAhead,
          &out_iSourceOffset) )
    return 2i64;
  v3 = out_iLookAhead;
  *((_BYTE *)&v2->0 + 375) &= 0xF3u;
  *((_BYTE *)&v2->0 + 375) |= 2u;
  v2->m_iFrameOffset = v3;
  v2->m_uSeekPosition = out_iSourceOffset;
  return 1i64;
}

// File Line: 302
// RVA: 0xAAB180
void __fastcall CAkMusicPBI::RefreshParameters(CAkMusicPBI *this)
{
  CAkMusicPBI *v1; // rbx

  v1 = this;
  CAkPBI::RefreshParameters((CAkPBI *)&this->vfptr);
  v1->m_EffectiveParams.Pitch = 0.0;
}

