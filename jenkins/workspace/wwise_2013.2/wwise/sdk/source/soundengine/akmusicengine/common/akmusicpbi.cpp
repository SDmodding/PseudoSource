// File Line: 66
// RVA: 0xAAAE00
void __fastcall CAkMusicPBI::CAkMusicPBI(
        CAkMusicPBI *this,
        CAkMusicCtx *in_parent,
        CAkSoundBase *in_pSound,
        CAkSource *in_pSource,
        CAkRegisteredObj *in_pGameObj,
        UserParams *in_UserParams,
        AkTrackSrc *in_pSrcInfo,
        PlayHistory *in_rPlayHistory,
        unsigned int in_SeqID,
        PriorityInfoCurrent *in_Priority,
        unsigned int in_uSourceOffset,
        CAkLimiter *in_pAMLimiter,
        CAkLimiter *in_pBusLimiter)
{
  CAkPBI::CAkPBI(
    this,
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
  CAkChildCtx::CAkChildCtx(&this->CAkChildCtx, in_parent);
  *((_DWORD *)this + 144) &= 0xFFFFFFFC;
  *((_BYTE *)&this->CAkPBI + 374) &= ~0x20u;
  this->m_ulStopOffset = -1;
  this->CAkPBI::CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkMusicPBI::`vftable{for `CAkTransportAware};
  this->CAkPBI::ITransitionable::vfptr = (ITransitionableVtbl *)&CAkContinuousPBI::`vftable{for `ITransitionable};
  this->CAkChildCtx::vfptr = (CAkChildCtxVtbl *)&CAkMusicPBI::`vftable;
  this->m_pSrcInfo = in_pSrcInfo;
}

// File Line: 77
// RVA: 0xAAB210
void __fastcall CAkMusicPBI::Term(CAkMusicPBI *this, bool in_bFailedToInit)
{
  if ( (*((_BYTE *)this + 576) & 1) == 0 )
    CAkSegmentCtx::RemoveAllReferences((CAkSegmentCtx *)this->m_pParentCtx, this);
  CAkMusicCtx::RemoveChild(this->m_pParentCtx, &this->CAkChildCtx);
  CAkPBI::Term(this, in_bFailedToInit);
}

// File Line: 91
// RVA: 0xAAB040
AKRESULT __fastcall CAkMusicPBI::Init(CAkMusicPBI *this, AkPathInfo *in_pPathInfo)
{
  CAkChildCtx::Connect(&this->CAkChildCtx);
  return CAkPBI::Init(this, in_pPathInfo);
}

// File Line: 111
// RVA: 0xAAB270
void __fastcall CAkMusicPBI::_Stop(
        CAkMusicPBI *this,
        AkPBIStopMode in_eStopMode,
        bool in_bIsFromTransition,
        bool in_bHasNotStarted)
{
  if ( !in_bHasNotStarted || this->m_ulStopOffset == -1 )
    CAkPBI::_Stop(this, in_eStopMode, in_bIsFromTransition, 0);
}

// File Line: 118
// RVA: 0xAAB1A0
void __fastcall CAkMusicPBI::SetAutomationValue(CAkMusicPBI *this, int in_eAutomationType, float in_fValue)
{
  if ( !in_eAutomationType )
    goto LABEL_6;
  if ( in_eAutomationType == 1 )
  {
    this->m_LPFAutomationOffset = in_fValue;
    CAkPBI::CalculateEffectiveLPF(this);
    return;
  }
  if ( (unsigned int)(in_eAutomationType - 2) <= 1 )
LABEL_6:
    ((void (__fastcall *)(CAkChildCtx *, char *))this->CAkChildCtx::vfptr->SetPBIFade)(
      &this->CAkChildCtx,
      (char *)this + in_eAutomationType);
}

// File Line: 152
// RVA: 0xAAB0E0
void __fastcall CAkMusicPBI::OnLastFrame(CAkMusicPBI *this, unsigned int in_uNumSamples, CAkTransition **a3, _BOOL8 a4)
{
  bool v4; // zf
  TransParams in_transParams; // [rsp+30h] [rbp+8h] BYREF

  if ( in_uNumSamples < LODWORD(this->pNextItem) && in_uNumSamples != -1 )
    LODWORD(this->pNextItem) = in_uNumSamples;
  v4 = LODWORD(this->pNextItem) == -1;
  in_transParams.TransitionTime = 0;
  if ( v4 || ((__int64)this->m_pUsageSlot & 2) != 0 )
    LOBYTE(a3) = 1;
  else
    a3 = 0i64;
  CAkPBI::_Stop((CAkMusicPBI *)((char *)this - 536), &in_transParams, a3, a4);
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
  ((void (__fastcall *)(CAkKeyArray<AkMutedMapItem,float,2> *))this[-1].m_mapMutedNodes.m_pItems[2].key.m_Identifier)(&this[-1].m_mapMutedNodes);
  *(_DWORD *)&this[-1].m_CntrHistArray.aCntrHist[20] = 1065353216;
  CAkPBI::CalculateMutedEffectiveVolume((CAkMusicPBI *)((char *)this - 536));
}

// File Line: 219
// RVA: 0xAAB290
void __fastcall CAkMusicPBI::_Stop(CAkMusicPBI *this, __int64 in_uStopOffset)
{
  *((_DWORD *)this + 144) |= 1u;
  this->CAkChildCtx::vfptr->OnLastFrame(&this->CAkChildCtx, in_uStopOffset);
}

// File Line: 234
// RVA: 0xAAB1E0
void __fastcall CAkMusicPBI::SetPBIFade(CAkMusicPBI *this, void *in_pOwner, float in_fFadeRatio)
{
  AkMutedMapItem in_key; // [rsp+20h] [rbp-18h] BYREF

  in_key.m_Identifier = in_pOwner;
  *((_DWORD *)&in_key + 2) = *((_DWORD *)&in_key + 2) & 0xFFFFFFFC | 2;
  CAkPBI::SetMuteMapEntry((CAkMusicPBI *)((char *)this - 536), &in_key, in_fFadeRatio);
}

// File Line: 244
// RVA: 0xAAAF80
void __fastcall CAkMusicPBI::FixStartTimeForFadeIn(CAkMusicPBI *this)
{
  int m_iFrameOffset; // r8d
  int v3; // eax
  signed int m_uSeekPosition; // ecx

  m_iFrameOffset = this->m_iFrameOffset;
  v3 = m_iFrameOffset % 1024;
  if ( m_iFrameOffset % 1024 > 512 || (m_uSeekPosition = this->m_uSeekPosition, v3 > m_uSeekPosition) )
  {
    *((_BYTE *)&this->CAkPBI + 375) &= 0xF3u;
    *((_BYTE *)&this->CAkPBI + 375) |= 0x82u;
    this->m_uSeekPosition += 1024 - v3;
    this->m_iFrameOffset = m_iFrameOffset + 1024 - v3;
  }
  else if ( v3 <= 0 )
  {
    *((_BYTE *)&this->CAkPBI + 375) |= 0x80u;
  }
  else
  {
    *((_BYTE *)&this->CAkPBI + 375) &= 0xF3u;
    *((_BYTE *)&this->CAkPBI + 375) |= 0x82u;
    this->m_iFrameOffset = m_iFrameOffset - v3;
    this->m_uSeekPosition = m_uSeekPosition - v3;
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
__int64 __fastcall CAkMusicPBI::GetAndClearStopOffset(CAkMusicPBI *this)
{
  unsigned int m_ulStopOffset; // edx
  __int64 result; // rax
  bool v3; // zf

  m_ulStopOffset = this->m_ulStopOffset;
  result = 0xFFFFFFFFi64;
  v3 = (*((_BYTE *)this + 576) & 2) == 0;
  this->m_ulStopOffset = -1;
  if ( v3 )
    return m_ulStopOffset;
  return result;
}

// File Line: 278
// RVA: 0xAAB080
__int64 __fastcall CAkMusicPBI::NotifyVirtualOff(CAkMusicPBI *this, AkVirtualQueueBehavior in_eBehavior)
{
  int v3; // eax
  int out_iLookAhead; // [rsp+30h] [rbp+8h] BYREF
  int out_iSourceOffset; // [rsp+40h] [rbp+18h] BYREF

  if ( !CAkSegmentCtx::GetSourceInfoForPlaybackRestart(
          (CAkSegmentCtx *)this->m_pParentCtx,
          this,
          &out_iLookAhead,
          &out_iSourceOffset) )
    return 2i64;
  v3 = out_iLookAhead;
  *((_BYTE *)&this->CAkPBI + 375) &= 0xF3u;
  *((_BYTE *)&this->CAkPBI + 375) |= 2u;
  this->m_iFrameOffset = v3;
  this->m_uSeekPosition = out_iSourceOffset;
  return 1i64;
}

// File Line: 302
// RVA: 0xAAB180
void __fastcall CAkMusicPBI::RefreshParameters(CAkMusicPBI *this)
{
  CAkPBI::RefreshParameters(this);
  this->m_EffectiveParams.Pitch = 0.0;
}

