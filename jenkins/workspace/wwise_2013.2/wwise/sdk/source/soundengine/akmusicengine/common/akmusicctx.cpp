// File Line: 47
// RVA: 0xAAA4A0
void __fastcall CAkMusicCtx::CAkMusicCtx(CAkMusicCtx *this, CAkMusicCtx *in_parent)
{
  CAkChildCtx::CAkChildCtx(this, in_parent);
  this->m_uRegisteredNotif = 0;
  this->CAkChildCtx::vfptr = (CAkChildCtxVtbl *)&CAkMusicCtx::`vftable{for `CAkChildCtx};
  this->CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkMusicCtx::`vftable{for `CAkTransportAware};
  this->ITransitionable::vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable{for `ITransitionable};
  this->m_listChildren.m_pFirst = 0i64;
  *((_BYTE *)&this->m_PBTrans + 16) &= 0xFCu;
  this->m_PBTrans.pvPSTrans = 0i64;
  this->m_PBTrans.pvPRTrans = 0i64;
  *((_BYTE *)this + 98) &= 0xE0u;
  *(_QWORD *)&this->m_uRefCount = 0i64;
  this->m_fPauseResumeFadeRatio = 1.0;
  this->m_uNumLastSamples = -1;
  this->m_uPauseCount = 0;
}

// File Line: 53
// RVA: 0xAAA510
void __fastcall CAkMusicCtx::~CAkMusicCtx(CAkMusicCtx *this)
{
  CAkTransition *pvPSTrans; // rdx
  CAkTransition *pvPRTrans; // rdx

  pvPSTrans = this->m_PBTrans.pvPSTrans;
  this->CAkChildCtx::vfptr = (CAkChildCtxVtbl *)&CAkMusicCtx::`vftable{for `CAkChildCtx};
  this->CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkMusicCtx::`vftable{for `CAkTransportAware};
  this->ITransitionable::vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable{for `ITransitionable};
  if ( pvPSTrans )
    CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, pvPSTrans, &this->ITransitionable);
  pvPRTrans = this->m_PBTrans.pvPRTrans;
  if ( pvPRTrans )
    CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, pvPRTrans, &this->ITransitionable);
  this->m_listChildren.m_pFirst = 0i64;
  this->CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkTransportAware::`vftable;
  CAkChildCtx::~CAkChildCtx(this);
}

// File Line: 79
// RVA: 0xAAA600
void __fastcall CAkMusicCtx::Init(CAkMusicCtx *this, CAkRegisteredObj *__formal, UserParams *a3)
{
  if ( this->m_pParentCtx )
    CAkChildCtx::Connect(this);
}

// File Line: 88
// RVA: 0xAAA5D0
void __fastcall CAkMusicCtx::AddChild(CAkMusicCtx *this, CAkChildCtx *in_pChildCtx)
{
  CAkChildCtx *m_pFirst; // rax

  m_pFirst = this->m_listChildren.m_pFirst;
  if ( m_pFirst )
  {
    in_pChildCtx->pNextLightItem = m_pFirst;
    this->m_listChildren.m_pFirst = in_pChildCtx;
  }
  else
  {
    this->m_listChildren.m_pFirst = in_pChildCtx;
    in_pChildCtx->pNextLightItem = 0i64;
  }
  ++this->m_uRefCount;
}

// File Line: 98
// RVA: 0xAAA830
void __fastcall CAkMusicCtx::RemoveChild(CAkMusicCtx *this, CAkChildCtx *in_pChildCtx)
{
  CAkChildCtx *m_pFirst; // rcx
  CAkChildCtx *v4; // r8
  CAkChildCtx *v5; // rax
  bool v6; // zf
  CAkChildCtx *pNextLightItem; // rcx

  m_pFirst = this->m_listChildren.m_pFirst;
  v4 = 0i64;
  v5 = m_pFirst;
  if ( m_pFirst )
  {
    while ( v5 != in_pChildCtx )
    {
      v4 = v5;
      v5 = v5->pNextLightItem;
      if ( !v5 )
        return;
    }
    if ( v5 )
    {
      v6 = v5 == m_pFirst;
      pNextLightItem = v5->pNextLightItem;
      if ( v6 )
        this->m_listChildren.m_pFirst = pNextLightItem;
      else
        v4->pNextLightItem = pNextLightItem;
      CAkMusicCtx::Release(this);
    }
  }
}

// File Line: 107
// RVA: 0xAAA790
void __fastcall CAkMusicCtx::Release(CAkMusicCtx *this)
{
  bool v1; // zf
  CAkMusicCtx *m_pParentCtx; // rcx
  CAkMusicCtx *m_pFirst; // r8
  CAkMusicCtx *v5; // rdx
  CAkMusicCtx *pNextLightItem; // rax
  CAkChildCtx *v7; // rax
  int v8; // ebx

  v1 = this->m_uRefCount-- == 1;
  if ( v1 )
  {
    m_pParentCtx = this->m_pParentCtx;
    if ( m_pParentCtx )
    {
      m_pFirst = (CAkMusicCtx *)m_pParentCtx->m_listChildren.m_pFirst;
      v5 = 0i64;
      pNextLightItem = m_pFirst;
      if ( m_pFirst )
      {
        while ( pNextLightItem != this )
        {
          v5 = pNextLightItem;
          pNextLightItem = (CAkMusicCtx *)pNextLightItem->pNextLightItem;
          if ( !pNextLightItem )
            goto LABEL_13;
        }
        if ( pNextLightItem )
        {
          v1 = pNextLightItem == m_pFirst;
          v7 = pNextLightItem->pNextLightItem;
          if ( v1 )
            m_pParentCtx->m_listChildren.m_pFirst = v7;
          else
            v5->pNextLightItem = v7;
          CAkMusicCtx::Release(m_pParentCtx);
        }
      }
    }
    else
    {
      CAkMusicRenderer::RemoveChild(CAkMusicRenderer::m_pMusicRenderer, (CAkMatrixAwareCtx *)this);
    }
LABEL_13:
    v8 = g_DefaultPoolId;
    ((void (__fastcall *)(CAkMusicCtx *, _QWORD))this->CAkChildCtx::vfptr->~CAkChildCtx)(this, 0i64);
    AK::MemoryMgr::Free(v8, this);
  }
}

// File Line: 127
// RVA: 0xAAA8D0
void __fastcall CAkMusicCtx::TransUpdateValue(
        CAkMusicCtx *this,
        __int64 in_eTarget,
        float in_fValue,
        bool in_bIsTerminated)
{
  char v4; // bl
  CAkTransition *v7; // rax
  CAkTransition *pvPRTrans; // rax

  v4 = 0;
  switch ( (_DWORD)in_eTarget )
  {
    case 0x1000000:
LABEL_11:
      pvPRTrans = this[-1].m_PBTrans.pvPRTrans;
      *((float *)&this->ITransitionable::vfptr + 1) = in_fValue;
      (*(void (__fastcall **)(CAkTransition **))&pvPRTrans->m_uDurationInBufferTick)(&this[-1].m_PBTrans.pvPRTrans);
      if ( in_bIsTerminated )
      {
        this->m_pParentCtx = 0i64;
        if ( v4 )
          ((void (__fastcall *)(CAkTransition **, __int64))this[-1].m_PBTrans.pvPRTrans->m_eTarget)(
            &this[-1].m_PBTrans.pvPRTrans,
            0xFFFFFFFFi64);
      }
      return;
    case 0x2000000:
      v4 = 1;
      goto LABEL_11;
    case 0x4000000:
      v4 = 1;
      break;
    case 0x8000000:
      break;
    default:
      return;
  }
  v7 = this[-1].m_PBTrans.pvPRTrans;
  *(float *)&this->m_listChildren.m_pFirst = in_fValue;
  (*(void (__fastcall **)(CAkTransition **))&v7->m_uDurationInBufferTick)(&this[-1].m_PBTrans.pvPRTrans);
  if ( in_bIsTerminated )
  {
    this->CAkTransportAware::vfptr = 0i64;
    if ( v4 )
      (*(void (__fastcall **)(CAkTransition **))&this[-1].m_PBTrans.pvPRTrans->m_fStartValue)(&this[-1].m_PBTrans.pvPRTrans);
  }
}

// File Line: 170
// RVA: 0xAAA720
void __fastcall CAkMusicCtx::OnPlayed(CAkMusicCtx *this)
{
  *((_BYTE *)this + 98) &= 0xF1u;
  *((_BYTE *)this + 98) |= 1u;
}

// File Line: 185
// RVA: 0xAAA610
void __fastcall CAkMusicCtx::OnLastFrame(CAkMusicCtx *this, unsigned int in_uNumSamples)
{
  CAkChildCtx *m_pFirst; // rbx
  CAkChildCtx *v5; // rbx
  CAkChildCtx *v6; // rcx
  char v7; // al

  m_pFirst = this->m_listChildren.m_pFirst;
  ++this->m_uRefCount;
  for ( ; m_pFirst; m_pFirst = m_pFirst->pNextLightItem )
  {
    m_pFirst->vfptr->VirtualAddRef(m_pFirst);
    m_pFirst->vfptr->OnLastFrame(m_pFirst, in_uNumSamples);
  }
  v5 = this->m_listChildren.m_pFirst;
  while ( v5 )
  {
    v6 = v5;
    v5 = v5->pNextLightItem;
    v6->vfptr->VirtualRelease(v6);
  }
  if ( in_uNumSamples < this->m_uNumLastSamples && in_uNumSamples != -1 )
    this->m_uNumLastSamples = in_uNumSamples;
  if ( this->m_uNumLastSamples && (v7 = *((_BYTE *)this + 98), (v7 & 0xF) != 0) && (v7 & 0x10) == 0 )
  {
    if ( (v7 & 0xFu) <= 2 )
      *((_BYTE *)this + 98) = v7 & 0xF0 | 2;
  }
  else
  {
    this->CAkChildCtx::vfptr[1].OnPaused(this);
  }
  CAkMusicCtx::Release(this);
}

// File Line: 229
// RVA: 0xAAA780
void __fastcall CAkMusicCtx::OnStopped(CAkMusicCtx *this)
{
  *((_BYTE *)this + 98) &= 0xF4u;
  *((_BYTE *)this + 98) |= 4u;
}

// File Line: 236
// RVA: 0xAAA6D0
void __fastcall CAkMusicCtx::OnPaused(CAkMusicCtx *this)
{
  CAkChildCtx *i; // rbx
  CAkTransition *pvPSTrans; // rdx

  for ( i = this->m_listChildren.m_pFirst; i; i = i->pNextLightItem )
    i->vfptr->OnPaused(i);
  pvPSTrans = this->m_PBTrans.pvPSTrans;
  *((_BYTE *)this + 98) |= 0x10u;
  if ( pvPSTrans )
    CAkTransitionManager::Pause(g_pTransitionManager, pvPSTrans);
}

// File Line: 255
// RVA: 0xAAA730
void __fastcall CAkMusicCtx::OnResumed(CAkMusicCtx *this)
{
  CAkChildCtx *i; // rbx
  CAkTransition *pvPSTrans; // rdx

  for ( i = this->m_listChildren.m_pFirst; i; i = i->pNextLightItem )
    i->vfptr->OnResumed(i);
  pvPSTrans = this->m_PBTrans.pvPSTrans;
  *((_BYTE *)this + 98) &= ~0x10u;
  if ( pvPSTrans )
    CAkTransitionManager::Resume(g_pTransitionManager, pvPSTrans);
}

// File Line: 275
// RVA: 0xAAA990
void __fastcall CAkMusicCtx::VirtualAddRef(CAkMusicCtx *this)
{
  ++this->m_uRefCount;
}

// File Line: 279
// RVA: 0xAAA9A0
// attributes: thunk
void __fastcall CAkMusicCtx::VirtualRelease(CAkMusicCtx *this)
{
  CAkMusicCtx::Release(this);
}

// File Line: 319
// RVA: 0xAAAA90
void __fastcall CAkMusicCtx::_Play(CAkMusicCtx *this, AkMusicFade *in_fadeParams, CAkTransition **a3)
{
  CAkTransition *pvPSTrans; // rdx
  AkCurveInterpolation eFadeCurve; // eax
  ITransitionable *v7; // rsi
  CAkTransition *v8; // rax
  __int64 v9; // r9
  CAkTransition *v10; // r8
  int iFadeOffset; // eax
  int v12; // eax
  TransitionParameters in_Params; // [rsp+40h] [rbp-38h] BYREF

  if ( (*((_BYTE *)this + 98) & 0xFu) <= 1 )
  {
    pvPSTrans = this->m_PBTrans.pvPSTrans;
    if ( pvPSTrans )
    {
      CAkTransitionManager::ChangeParameter(
        g_pTransitionManager,
        pvPSTrans,
        0x1000000i64,
        1.0,
        in_fadeParams->transitionTime,
        in_fadeParams->eFadeCurve,
        AkValueMeaning_Default);
    }
    else if ( in_fadeParams->transitionTime > 0 )
    {
      in_Params.lDuration = in_fadeParams->transitionTime;
      eFadeCurve = in_fadeParams->eFadeCurve;
      v7 = &this->ITransitionable;
      LODWORD(in_Params.fTargetValue) = (_DWORD)FLOAT_1_0;
      in_Params.fStartValue = 0.0;
      LOBYTE(a3) = 1;
      in_Params.eFadeCurve = eFadeCurve;
      in_Params.pUser = &this->ITransitionable;
      in_Params.eTarget = 0x1000000i64;
      *(_WORD *)&in_Params.bdBs = 256;
      v8 = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, a3, 0i64);
      *((_BYTE *)&this->m_PBTrans + 16) |= 1u;
      v10 = v8;
      this->m_PBTrans.pvPSTrans = v8;
      if ( v8 )
      {
        iFadeOffset = in_fadeParams->iFadeOffset;
        if ( iFadeOffset )
        {
          v12 = iFadeOffset / 1024;
          if ( v12 >= 0 || v10->m_uStartTimeInBufferTick > -v12 )
            v10->m_uStartTimeInBufferTick += v12;
          else
            v10->m_uStartTimeInBufferTick = 0;
        }
      }
      else
      {
        LOBYTE(v9) = 1;
        ((void (__fastcall *)(ITransitionable *, __int64, _QWORD, __int64))v7->vfptr->TransUpdateValue)(
          v7,
          in_Params.eTarget,
          0i64,
          v9);
      }
    }
    ((void (__fastcall *)(CAkMusicCtx *))this->CAkChildCtx::vfptr[1].OnLastFrame)(this);
  }
}

// File Line: 387
// RVA: 0xAAACF0
void __fastcall CAkMusicCtx::_Stop(CAkMusicCtx *this, TransParams *in_transParams, CAkTransition **in_uNumLastSamples)
{
  char v3; // al
  CAkTransition *pvPSTrans; // rcx
  AkCurveInterpolation eFadeCurve; // eax
  CAkTransition *v7; // rax
  __int64 v8; // r8
  __int64 v9; // r9
  TransitionParameters in_Params; // [rsp+40h] [rbp-38h] BYREF

  v3 = *((_BYTE *)this + 98);
  if ( (v3 & 0x10) != 0 )
  {
    this->CAkChildCtx::vfptr->OnLastFrame(this, (unsigned int)in_uNumLastSamples);
  }
  else
  {
    pvPSTrans = this->m_PBTrans.pvPSTrans;
    if ( pvPSTrans )
    {
      CAkTransitionManager::ChangeParameter(
        g_pTransitionManager,
        pvPSTrans,
        0x2000000i64,
        0.0,
        in_transParams->TransitionTime,
        in_transParams->eFadeCurve,
        AkValueMeaning_Default);
    }
    else if ( in_transParams->TransitionTime > 0 && (v3 & 3) != 0 )
    {
      eFadeCurve = in_transParams->eFadeCurve;
      in_Params.lDuration = in_transParams->TransitionTime;
      LODWORD(in_Params.fStartValue) = (_DWORD)FLOAT_1_0;
      in_Params.fTargetValue = 0.0;
      LOBYTE(in_uNumLastSamples) = 1;
      in_Params.eFadeCurve = eFadeCurve;
      in_Params.eTarget = 0x2000000i64;
      in_Params.pUser = &this->ITransitionable;
      *(_WORD *)&in_Params.bdBs = 256;
      v7 = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, in_uNumLastSamples, 0i64);
      *((_BYTE *)&this->m_PBTrans + 16) |= 1u;
      this->m_PBTrans.pvPSTrans = v7;
      if ( !v7 )
      {
        LOBYTE(v9) = 1;
        ((void (__fastcall *)(ITransitionable *, __int64, __int64, __int64))this->ITransitionable::vfptr->TransUpdateValue)(
          &this->ITransitionable,
          in_Params.eTarget,
          v8,
          v9);
      }
    }
    else
    {
      this->CAkChildCtx::vfptr->OnLastFrame(this, (unsigned int)in_uNumLastSamples);
    }
  }
}

// File Line: 450
// RVA: 0xAAA9B0
void __fastcall CAkMusicCtx::_Pause(CAkMusicCtx *this, TransParams *in_transParams, CAkTransition **a3)
{
  CAkTransition *pvPRTrans; // rcx
  AkCurveInterpolation eFadeCurve; // eax
  CAkTransition *v6; // rax
  __int64 v7; // r8
  __int64 v8; // r9
  TransitionParameters in_Params; // [rsp+40h] [rbp-38h] BYREF

  ++this->m_uPauseCount;
  pvPRTrans = this->m_PBTrans.pvPRTrans;
  if ( pvPRTrans )
  {
    CAkTransitionManager::ChangeParameter(
      g_pTransitionManager,
      pvPRTrans,
      0x4000000i64,
      0.0,
      in_transParams->TransitionTime,
      in_transParams->eFadeCurve,
      AkValueMeaning_Default);
  }
  else
  {
    in_Params.lDuration = in_transParams->TransitionTime;
    eFadeCurve = in_transParams->eFadeCurve;
    LODWORD(in_Params.fStartValue) = (_DWORD)FLOAT_1_0;
    in_Params.fTargetValue = 0.0;
    LOBYTE(a3) = 1;
    in_Params.eFadeCurve = eFadeCurve;
    in_Params.pUser = &this->ITransitionable;
    in_Params.eTarget = 0x4000000i64;
    *(_WORD *)&in_Params.bdBs = 256;
    v6 = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, a3, 0i64);
    *((_BYTE *)&this->m_PBTrans + 16) |= 2u;
    this->m_PBTrans.pvPRTrans = v6;
    if ( !v6 )
    {
      LOBYTE(v8) = 1;
      ((void (__fastcall *)(ITransitionable *, __int64, __int64, __int64))this->ITransitionable::vfptr->TransUpdateValue)(
        &this->ITransitionable,
        in_Params.eTarget,
        v7,
        v8);
    }
  }
}

// File Line: 499
// RVA: 0xAAABD0
void __fastcall CAkMusicCtx::_Resume(
        CAkMusicCtx *this,
        TransParams *in_transParams,
        CAkTransition **in_bIsMasterResume)
{
  unsigned __int16 m_uPauseCount; // ax
  CAkTransition *pvPRTrans; // rcx
  float m_fPauseResumeFadeRatio; // xmm0_4
  AkCurveInterpolation eFadeCurve; // eax
  CAkTransition *v8; // rax
  __int64 v9; // r8
  __int64 v10; // r9
  CAkChildCtxVtbl *vfptr; // rax
  TransitionParameters in_Params; // [rsp+40h] [rbp-38h] BYREF

  if ( (_BYTE)in_bIsMasterResume || (m_uPauseCount = this->m_uPauseCount, m_uPauseCount <= 1u) )
  {
    this->m_uPauseCount = 0;
    pvPRTrans = this->m_PBTrans.pvPRTrans;
    if ( pvPRTrans )
    {
      CAkTransitionManager::ChangeParameter(
        g_pTransitionManager,
        pvPRTrans,
        0x8000000i64,
        1.0,
        in_transParams->TransitionTime,
        in_transParams->eFadeCurve,
        AkValueMeaning_Default);
    }
    else if ( in_transParams->TransitionTime <= 0 )
    {
      vfptr = this->CAkChildCtx::vfptr;
      this->m_fPauseResumeFadeRatio = 1.0;
      ((void (__fastcall *)(CAkMusicCtx *))vfptr->SetPBIFade)(this);
    }
    else
    {
      m_fPauseResumeFadeRatio = this->m_fPauseResumeFadeRatio;
      in_Params.lDuration = in_transParams->TransitionTime;
      eFadeCurve = in_transParams->eFadeCurve;
      in_Params.fStartValue = m_fPauseResumeFadeRatio;
      LODWORD(in_Params.fTargetValue) = (_DWORD)FLOAT_1_0;
      LOBYTE(in_bIsMasterResume) = 1;
      in_Params.eFadeCurve = eFadeCurve;
      in_Params.pUser = &this->ITransitionable;
      in_Params.eTarget = 0x8000000i64;
      *(_WORD *)&in_Params.bdBs = 256;
      v8 = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, in_bIsMasterResume, 0i64);
      *((_BYTE *)&this->m_PBTrans + 16) |= 2u;
      this->m_PBTrans.pvPRTrans = v8;
      if ( !v8 )
      {
        LOBYTE(v10) = 1;
        ((void (__fastcall *)(ITransitionable *, __int64, __int64, __int64))this->ITransitionable::vfptr->TransUpdateValue)(
          &this->ITransitionable,
          in_Params.eTarget,
          v9,
          v10);
      }
    }
    this->CAkChildCtx::vfptr->OnResumed(this);
  }
  else
  {
    this->m_uPauseCount = m_uPauseCount - 1;
  }
}

// File Line: 581
// RVA: 0xAAA880
void __fastcall CAkMusicCtx::SetPBIFade(CAkMusicCtx *this, void *in_pOwner, float in_fFadeRatio)
{
  CAkChildCtx *i; // rbx

  for ( i = this->m_listChildren.m_pFirst; i; i = i->pNextLightItem )
    ((void (__fastcall *)(CAkChildCtx *, void *))i->vfptr->SetPBIFade)(i, in_pOwner);
}

