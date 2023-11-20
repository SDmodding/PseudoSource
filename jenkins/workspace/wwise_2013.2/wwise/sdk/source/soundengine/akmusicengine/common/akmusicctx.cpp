// File Line: 47
// RVA: 0xAAA4A0
void __fastcall CAkMusicCtx::CAkMusicCtx(CAkMusicCtx *this, CAkMusicCtx *in_parent)
{
  CAkMusicCtx *v2; // rbx

  v2 = this;
  CAkChildCtx::CAkChildCtx((CAkChildCtx *)&this->vfptr, in_parent);
  v2->m_uRegisteredNotif = 0;
  v2->vfptr = (CAkChildCtxVtbl *)&CAkMusicCtx::`vftable{for `CAkChildCtx};
  v2->vfptr = (CAkTransportAwareVtbl *)&CAkMusicCtx::`vftable{for `CAkTransportAware};
  v2->vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable{for `ITransitionable};
  v2->m_listChildren.m_pFirst = 0i64;
  *((_BYTE *)&v2->m_PBTrans + 16) &= 0xFCu;
  v2->m_PBTrans.pvPSTrans = 0i64;
  v2->m_PBTrans.pvPRTrans = 0i64;
  *((_BYTE *)v2 + 98) &= 0xE0u;
  *(_QWORD *)&v2->m_uRefCount = 0i64;
  v2->m_fPauseResumeFadeRatio = 1.0;
  v2->m_uNumLastSamples = -1;
  v2->m_uPauseCount = 0;
}

// File Line: 53
// RVA: 0xAAA510
void __fastcall CAkMusicCtx::~CAkMusicCtx(CAkMusicCtx *this)
{
  CAkTransition *v1; // rdx
  CAkMusicCtx *v2; // rbx
  CAkTransition *v3; // rdx

  v1 = this->m_PBTrans.pvPSTrans;
  v2 = this;
  this->vfptr = (CAkChildCtxVtbl *)&CAkMusicCtx::`vftable{for `CAkChildCtx};
  this->vfptr = (CAkTransportAwareVtbl *)&CAkMusicCtx::`vftable{for `CAkTransportAware};
  this->vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable{for `ITransitionable};
  if ( v1 )
    CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, v1, (ITransitionable *)&this->vfptr);
  v3 = v2->m_PBTrans.pvPRTrans;
  if ( v3 )
    CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, v3, (ITransitionable *)&v2->vfptr);
  v2->m_listChildren.m_pFirst = 0i64;
  v2->vfptr = (CAkTransportAwareVtbl *)&CAkTransportAware::`vftable;
  CAkChildCtx::~CAkChildCtx((CAkChildCtx *)&v2->vfptr);
}

// File Line: 79
// RVA: 0xAAA600
void __fastcall CAkMusicCtx::Init(CAkMusicCtx *this, CAkRegisteredObj *__formal, UserParams *a3)
{
  JUMPOUT(this->m_pParentCtx, 0i64, CAkChildCtx::Connect);
}

// File Line: 88
// RVA: 0xAAA5D0
void __fastcall CAkMusicCtx::AddChild(CAkMusicCtx *this, CAkChildCtx *in_pChildCtx)
{
  CAkChildCtx *v2; // rax

  v2 = this->m_listChildren.m_pFirst;
  if ( v2 )
  {
    in_pChildCtx->pNextLightItem = v2;
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
  CAkMusicCtx *v2; // r9
  CAkChildCtx *v3; // rcx
  CAkChildCtx *v4; // r8
  CAkChildCtx *v5; // rax
  bool v6; // zf
  CAkChildCtx *v7; // rcx

  v2 = this;
  v3 = this->m_listChildren.m_pFirst;
  v4 = 0i64;
  v5 = v3;
  if ( v3 )
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
      v6 = v5 == v3;
      v7 = v5->pNextLightItem;
      if ( v6 )
        v2->m_listChildren.m_pFirst = v7;
      else
        v4->pNextLightItem = v7;
      CAkMusicCtx::Release(v2);
    }
  }
}

// File Line: 107
// RVA: 0xAAA790
void __fastcall CAkMusicCtx::Release(CAkMusicCtx *this)
{
  bool v1; // zf
  CAkMatrixAwareCtx *v2; // rdi
  CAkMusicCtx *v3; // rcx
  CAkChildCtx *v4; // r8
  CAkMatrixAwareCtx *v5; // rdx
  CAkMatrixAwareCtx *v6; // rax
  CAkChildCtx *v7; // rax
  int v8; // ebx

  v1 = this->m_uRefCount-- == 1;
  v2 = (CAkMatrixAwareCtx *)this;
  if ( v1 )
  {
    v3 = this->m_pParentCtx;
    if ( v3 )
    {
      v4 = v3->m_listChildren.m_pFirst;
      v5 = 0i64;
      v6 = (CAkMatrixAwareCtx *)v4;
      if ( v4 )
      {
        while ( v6 != v2 )
        {
          v5 = v6;
          v6 = (CAkMatrixAwareCtx *)v6->pNextLightItem;
          if ( !v6 )
            goto LABEL_13;
        }
        if ( v6 )
        {
          v1 = v6 == (CAkMatrixAwareCtx *)v4;
          v7 = v6->pNextLightItem;
          if ( v1 )
            v3->m_listChildren.m_pFirst = v7;
          else
            v5->pNextLightItem = v7;
          CAkMusicCtx::Release(v3);
        }
      }
    }
    else
    {
      CAkMusicRenderer::RemoveChild(CAkMusicRenderer::m_pMusicRenderer, v2);
    }
LABEL_13:
    v8 = g_DefaultPoolId;
    ((void (__fastcall *)(CAkMatrixAwareCtx *, _QWORD))v2->vfptr->~CAkChildCtx)(v2, 0i64);
    AK::MemoryMgr::Free(v8, v2);
  }
}

// File Line: 127
// RVA: 0xAAA8D0
void __fastcall CAkMusicCtx::TransUpdateValue(CAkMusicCtx *this, __int64 in_eTarget, float in_fValue, bool in_bIsTerminated)
{
  char v4; // bl
  bool v5; // bp
  CAkMusicCtx *v6; // rdi
  CAkTransition *v7; // rax
  CAkTransition *v8; // rax

  v4 = 0;
  v5 = in_bIsTerminated;
  v6 = this;
  switch ( (_DWORD)in_eTarget )
  {
    case 0x1000000:
LABEL_11:
      v8 = this[-1].m_PBTrans.pvPRTrans;
      *((float *)&this->vfptr + 1) = in_fValue;
      (*(void (__fastcall **)(CAkTransition **))&v8->m_uDurationInBufferTick)(&this[-1].m_PBTrans.pvPRTrans);
      if ( v5 )
      {
        v6->m_pParentCtx = 0i64;
        if ( v4 )
          ((void (__fastcall *)(CAkTransition **, signed __int64))v6[-1].m_PBTrans.pvPRTrans->m_eTarget)(
            &v6[-1].m_PBTrans.pvPRTrans,
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
  if ( v5 )
  {
    v6->vfptr = 0i64;
    if ( v4 )
      (*(void (__fastcall **)(CAkTransition **))&v6[-1].m_PBTrans.pvPRTrans->m_fStartValue)(&v6[-1].m_PBTrans.pvPRTrans);
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
  CAkChildCtx *v2; // rbx
  unsigned int v3; // esi
  CAkMusicCtx *i; // rdi
  CAkChildCtx *v5; // rbx
  CAkChildCtx *v6; // rcx
  char v7; // al

  v2 = this->m_listChildren.m_pFirst;
  ++this->m_uRefCount;
  v3 = in_uNumSamples;
  for ( i = this; v2; v2 = v2->pNextLightItem )
  {
    v2->vfptr->VirtualAddRef(v2);
    v2->vfptr->OnLastFrame(v2, v3);
  }
  v5 = i->m_listChildren.m_pFirst;
  while ( v5 )
  {
    v6 = v5;
    v5 = v5->pNextLightItem;
    ((void (*)(void))v6->vfptr->VirtualRelease)();
  }
  if ( v3 < i->m_uNumLastSamples && v3 != -1 )
    i->m_uNumLastSamples = v3;
  if ( i->m_uNumLastSamples && (v7 = *((_BYTE *)i + 98), v7 & 0xF) && !(v7 & 0x10) )
  {
    if ( (v7 & 0xFu) <= 2 )
      *((_BYTE *)i + 98) = v7 & 0xF2 | 2;
  }
  else
  {
    i->vfptr[1].OnPaused((CAkChildCtx *)&i->vfptr);
  }
  CAkMusicCtx::Release(i);
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
  CAkChildCtx *v1; // rbx
  CAkMusicCtx *i; // rdi
  CAkTransition *v3; // rdx

  v1 = this->m_listChildren.m_pFirst;
  for ( i = this; v1; v1 = v1->pNextLightItem )
    v1->vfptr->OnPaused(v1);
  v3 = i->m_PBTrans.pvPSTrans;
  *((_BYTE *)i + 98) |= 0x10u;
  if ( v3 )
    CAkTransitionManager::Pause(g_pTransitionManager, v3);
}

// File Line: 255
// RVA: 0xAAA730
void __fastcall CAkMusicCtx::OnResumed(CAkMusicCtx *this)
{
  CAkChildCtx *v1; // rbx
  CAkMusicCtx *i; // rdi
  CAkTransition *v3; // rdx

  v1 = this->m_listChildren.m_pFirst;
  for ( i = this; v1; v1 = v1->pNextLightItem )
    v1->vfptr->OnResumed(v1);
  v3 = i->m_PBTrans.pvPSTrans;
  *((_BYTE *)i + 98) &= 0xEFu;
  if ( v3 )
    CAkTransitionManager::Resume(g_pTransitionManager, v3);
}

// File Line: 275
// RVA: 0xAAA990
void __fastcall CAkMusicCtx::VirtualAddRef(CAkMusicCtx *this)
{
  ++this->m_uRefCount;
}

// File Line: 279
// RVA: 0xAAA9A0
void __fastcall CAkMusicCtx::VirtualRelease(CAkMusicCtx *this)
{
  CAkMusicCtx::Release(this);
}

// File Line: 319
// RVA: 0xAAAA90
void __fastcall CAkMusicCtx::_Play(CAkMusicCtx *this, AkMusicFade *in_fadeParams, __int64 a3)
{
  AkMusicFade *v3; // rdi
  CAkMusicCtx *v4; // rbx
  CAkTransition *v5; // rdx
  AkCurveInterpolation v6; // eax
  ITransitionable *v7; // rsi
  CAkTransition *v8; // rax
  __int64 v9; // r9
  CAkTransition *v10; // r8
  int v11; // eax
  int v12; // eax
  TransitionParameters in_Params; // [rsp+40h] [rbp-38h]

  v3 = in_fadeParams;
  v4 = this;
  if ( (*((_BYTE *)this + 98) & 0xFu) <= 1 )
  {
    v5 = this->m_PBTrans.pvPSTrans;
    if ( v5 )
    {
      CAkTransitionManager::ChangeParameter(
        g_pTransitionManager,
        v5,
        0x1000000i64,
        1.0,
        v3->transitionTime,
        v3->eFadeCurve,
        0);
    }
    else if ( v3->transitionTime > 0 )
    {
      in_Params.lDuration = v3->transitionTime;
      v6 = v3->eFadeCurve;
      v7 = (ITransitionable *)&this->vfptr;
      LODWORD(in_Params.fTargetValue) = (_DWORD)FLOAT_1_0;
      in_Params.fStartValue = 0.0;
      LOBYTE(a3) = 1;
      in_Params.eFadeCurve = v6;
      in_Params.pUser = (ITransitionable *)&this->vfptr;
      in_Params.eTarget = 0x1000000i64;
      *(_WORD *)&in_Params.bdBs = 256;
      v8 = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, a3, 0i64);
      *((_BYTE *)&v4->m_PBTrans + 16) |= 1u;
      v10 = v8;
      v4->m_PBTrans.pvPSTrans = v8;
      if ( v8 )
      {
        v11 = v3->iFadeOffset;
        if ( v11 )
        {
          v12 = v11 / 1024;
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
    ((void (__fastcall *)(CAkMusicCtx *))v4->vfptr[1].OnLastFrame)(v4);
  }
}

// File Line: 387
// RVA: 0xAAACF0
void __fastcall CAkMusicCtx::_Stop(CAkMusicCtx *this, TransParams *in_transParams, __int64 in_uNumLastSamples)
{
  char v3; // al
  CAkMusicCtx *v4; // rbx
  CAkTransition *v5; // rcx
  AkCurveInterpolation v6; // eax
  CAkTransition *v7; // rax
  __int64 v8; // r8
  __int64 v9; // r9
  TransitionParameters in_Params; // [rsp+40h] [rbp-38h]

  v3 = *((_BYTE *)this + 98);
  v4 = this;
  if ( v3 & 0x10 )
  {
    this->vfptr->OnLastFrame((CAkChildCtx *)this, in_uNumLastSamples);
  }
  else
  {
    v5 = this->m_PBTrans.pvPSTrans;
    if ( v5 )
    {
      CAkTransitionManager::ChangeParameter(
        g_pTransitionManager,
        v5,
        0x2000000i64,
        0.0,
        in_transParams->TransitionTime,
        in_transParams->eFadeCurve,
        0);
    }
    else if ( in_transParams->TransitionTime > 0 && v3 & 3 )
    {
      v6 = in_transParams->eFadeCurve;
      in_Params.lDuration = in_transParams->TransitionTime;
      LODWORD(in_Params.fStartValue) = (_DWORD)FLOAT_1_0;
      in_Params.fTargetValue = 0.0;
      LOBYTE(in_uNumLastSamples) = 1;
      in_Params.eFadeCurve = v6;
      in_Params.eTarget = 0x2000000i64;
      in_Params.pUser = (ITransitionable *)&v4->vfptr;
      *(_WORD *)&in_Params.bdBs = 256;
      v7 = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, in_uNumLastSamples, 0i64);
      *((_BYTE *)&v4->m_PBTrans + 16) |= 1u;
      v4->m_PBTrans.pvPSTrans = v7;
      if ( !v7 )
      {
        LOBYTE(v9) = 1;
        ((void (__fastcall *)(ITransitionableVtbl **, __int64, __int64, __int64))v4->vfptr->TransUpdateValue)(
          &v4->vfptr,
          in_Params.eTarget,
          v8,
          v9);
      }
    }
    else
    {
      v4->vfptr->OnLastFrame((CAkChildCtx *)&v4->vfptr, in_uNumLastSamples);
    }
  }
}

// File Line: 450
// RVA: 0xAAA9B0
void __fastcall CAkMusicCtx::_Pause(CAkMusicCtx *this, TransParams *in_transParams, __int64 a3)
{
  CAkMusicCtx *v3; // rbx
  CAkTransition *v4; // rcx
  AkCurveInterpolation v5; // eax
  CAkTransition *v6; // rax
  __int64 v7; // r8
  __int64 v8; // r9
  TransitionParameters in_Params; // [rsp+40h] [rbp-38h]

  ++this->m_uPauseCount;
  v3 = this;
  v4 = this->m_PBTrans.pvPRTrans;
  if ( v4 )
  {
    CAkTransitionManager::ChangeParameter(
      g_pTransitionManager,
      v4,
      0x4000000i64,
      0.0,
      in_transParams->TransitionTime,
      in_transParams->eFadeCurve,
      0);
  }
  else
  {
    in_Params.lDuration = in_transParams->TransitionTime;
    v5 = in_transParams->eFadeCurve;
    LODWORD(in_Params.fStartValue) = (_DWORD)FLOAT_1_0;
    in_Params.fTargetValue = 0.0;
    LOBYTE(a3) = 1;
    in_Params.eFadeCurve = v5;
    in_Params.pUser = (ITransitionable *)&v3->vfptr;
    in_Params.eTarget = 0x4000000i64;
    *(_WORD *)&in_Params.bdBs = 256;
    v6 = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, a3, 0i64);
    *((_BYTE *)&v3->m_PBTrans + 16) |= 2u;
    v3->m_PBTrans.pvPRTrans = v6;
    if ( !v6 )
    {
      LOBYTE(v8) = 1;
      ((void (__fastcall *)(ITransitionableVtbl **, __int64, __int64, __int64))v3->vfptr->TransUpdateValue)(
        &v3->vfptr,
        in_Params.eTarget,
        v7,
        v8);
    }
  }
}

// File Line: 499
// RVA: 0xAAABD0
void __fastcall CAkMusicCtx::_Resume(CAkMusicCtx *this, TransParams *in_transParams, __int64 in_bIsMasterResume)
{
  CAkMusicCtx *v3; // rbx
  unsigned __int16 v4; // ax
  CAkTransition *v5; // rcx
  float v6; // xmm0_4
  AkCurveInterpolation v7; // eax
  CAkTransition *v8; // rax
  __int64 v9; // r8
  __int64 v10; // r9
  CAkChildCtxVtbl *v11; // rax
  TransitionParameters in_Params; // [rsp+40h] [rbp-38h]

  v3 = this;
  if ( (_BYTE)in_bIsMasterResume || (v4 = this->m_uPauseCount, v4 <= 1u) )
  {
    this->m_uPauseCount = 0;
    v5 = this->m_PBTrans.pvPRTrans;
    if ( v5 )
    {
      CAkTransitionManager::ChangeParameter(
        g_pTransitionManager,
        v5,
        0x8000000i64,
        1.0,
        in_transParams->TransitionTime,
        in_transParams->eFadeCurve,
        0);
    }
    else if ( in_transParams->TransitionTime <= 0 )
    {
      v11 = v3->vfptr;
      v3->m_fPauseResumeFadeRatio = 1.0;
      ((void (__fastcall *)(CAkMusicCtx *))v11->SetPBIFade)(v3);
    }
    else
    {
      v6 = v3->m_fPauseResumeFadeRatio;
      in_Params.lDuration = in_transParams->TransitionTime;
      v7 = in_transParams->eFadeCurve;
      in_Params.fStartValue = v6;
      LODWORD(in_Params.fTargetValue) = (_DWORD)FLOAT_1_0;
      LOBYTE(in_bIsMasterResume) = 1;
      in_Params.eFadeCurve = v7;
      in_Params.pUser = (ITransitionable *)&v3->vfptr;
      in_Params.eTarget = 0x8000000i64;
      *(_WORD *)&in_Params.bdBs = 256;
      v8 = CAkTransitionManager::AddTransitionToList(g_pTransitionManager, &in_Params, in_bIsMasterResume, 0i64);
      *((_BYTE *)&v3->m_PBTrans + 16) |= 2u;
      v3->m_PBTrans.pvPRTrans = v8;
      if ( !v8 )
      {
        LOBYTE(v10) = 1;
        ((void (__fastcall *)(ITransitionableVtbl **, __int64, __int64, __int64))v3->vfptr->TransUpdateValue)(
          &v3->vfptr,
          in_Params.eTarget,
          v9,
          v10);
      }
    }
    v3->vfptr->OnResumed((CAkChildCtx *)&v3->vfptr);
  }
  else
  {
    this->m_uPauseCount = v4 - 1;
  }
}

// File Line: 581
// RVA: 0xAAA880
void __fastcall CAkMusicCtx::SetPBIFade(CAkMusicCtx *this, void *in_pOwner, float in_fFadeRatio)
{
  CAkChildCtx *v3; // rbx
  void *i; // rdi

  v3 = this->m_listChildren.m_pFirst;
  for ( i = in_pOwner; v3; v3 = v3->pNextLightItem )
    ((void (__fastcall *)(CAkChildCtx *, void *))v3->vfptr->SetPBIFade)(v3, i);
}

