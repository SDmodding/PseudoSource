// File Line: 27
// RVA: 0xAAB2B0
void __fastcall CAkMatrixAwareCtx::CAkMatrixAwareCtx(CAkMatrixAwareCtx *this, CAkMusicCtx *in_parent)
{
  CAkMatrixAwareCtx *v2; // rbx

  v2 = this;
  CAkMusicCtx::CAkMusicCtx((CAkMusicCtx *)&this->vfptr, in_parent);
  v2->vfptr = (CAkChildCtxVtbl *)&CAkMatrixAwareCtx::`vftable'{for `CAkChildCtx'};
  v2->vfptr = (CAkTransportAwareVtbl *)&CAkMatrixAwareCtx::`vftable'{for `CAkTransportAware'};
  v2->vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable'{for `ITransitionable'};
  v2->m_pSequencer = 0i64;
  v2->m_iLocalTime = 0i64;
}

// File Line: 31
// RVA: 0xAAB300
void __fastcall CAkMatrixAwareCtx::~CAkMatrixAwareCtx(CAkMatrixAwareCtx *this)
{
  this->vfptr = (CAkChildCtxVtbl *)&CAkMatrixAwareCtx::`vftable'{for `CAkChildCtx'};
  this->vfptr = (CAkTransportAwareVtbl *)&CAkMatrixAwareCtx::`vftable'{for `CAkTransportAware'};
  this->vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable'{for `ITransitionable'};
  CAkMusicCtx::~CAkMusicCtx((CAkMusicCtx *)&this->vfptr);
}

// File Line: 38
// RVA: 0xAAB540
signed __int64 __fastcall CAkMatrixAwareCtx::Init(CAkMatrixAwareCtx *this, CAkRegisteredObj *in_pGameObj, UserParams *in_rUserparams)
{
  UserParams *v3; // rdi
  CAkRegisteredObj *v4; // rsi
  CAkMatrixAwareCtx *v5; // rbx
  CAkMusicCtx *v6; // rax

  v3 = in_rUserparams;
  v4 = in_pGameObj;
  v5 = this;
  CAkMusicCtx::Init((CAkMusicCtx *)&this->vfptr, in_pGameObj, in_rUserparams);
  v6 = v5->m_pParentCtx;
  if ( !v6 )
    return CAkMusicRenderer::AddChild(CAkMusicRenderer::m_pMusicRenderer, v5, v3, v4);
  v5->m_pSequencer = (CAkMatrixSequencer *)v6[1].vfptr;
  return 1i64;
}

// File Line: 61
// RVA: 0xAAB510
__int64 __fastcall CAkMatrixAwareCtx::GetSilentDuration(CAkMatrixAwareCtx *this)
{
  __int64 v2; // [rsp+30h] [rbp+8h]
  __int64 v3; // [rsp+38h] [rbp+10h]

  ((void (__fastcall *)(CAkMatrixAwareCtx *, __int64 *, __int64 *))this->vfptr[2].OnLastFrame)(this, &v3, &v2);
  return v2 - v3;
}

// File Line: 95
// RVA: 0xAAB430
__int64 __fastcall CAkMatrixAwareCtx::GetPlayingSegmentInfo(CAkMatrixAwareCtx *this, AkSegmentInfo *out_segmentInfo)
{
  AkSegmentInfo *v2; // r14
  CAkMatrixAwareCtx *v3; // rbx
  CAkScheduledItem *v4; // rdi
  CAkMatrixAwareCtx *v5; // rcx
  unsigned __int64 v6; // rbp
  unsigned __int64 v7; // rsi
  __int64 v8; // rax
  int v9; // eax
  AKRESULT v10; // ebx
  CAkScheduleWindow v12; // [rsp+20h] [rbp-138h]

  v2 = out_segmentInfo;
  v3 = this;
  CAkScheduleWindow::CAkScheduleWindow(&v12, this, 0);
  v4 = v12.m_itScheduledItem.pItem;
  if ( v12.m_itScheduledItem.pItem )
  {
    v5 = (CAkMatrixAwareCtx *)v3->m_pParentCtx;
    v6 = v3->m_pSequencer->m_uTime;
    v7 = v3->m_iLocalTime;
    if ( v5 )
      v7 += CAkMatrixAwareCtx::GetAbsoluteTimeOffset(v5);
    if ( v4->m_pSegment.m_pT )
    {
      v8 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(&v12, 0);
      v9 = AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(&v12.m_itScheduledItem, v6 - v7 - v8);
    }
    else
    {
      v9 = 0;
    }
    v10 = CAkScheduledItem::GetInfo(v4, v9, v2);
  }
  else
  {
    v10 = 2;
  }
  _((AMD_HD3D *)&v12);
  return (unsigned int)v10;
}

// File Line: 107
// RVA: 0xAAB5B0
void __fastcall CAkMatrixAwareCtx::OnStopped(CAkMatrixAwareCtx *this)
{
  CAkMatrixAwareCtx *v1; // rbx
  CAkMatrixSequencer *v2; // rcx

  v1 = this;
  CAkMusicCtx::OnStopped((CAkMusicCtx *)&this->vfptr);
  if ( !v1->m_pParentCtx )
  {
    v2 = v1->m_pSequencer;
    if ( v2 )
      CAkMatrixSequencer::OnStopped(v2);
  }
}

// File Line: 149
// RVA: 0xAAB3C0
CAkMusicSegment *__fastcall CAkMatrixAwareCtx::GetFirstSegmentNode(CAkMatrixAwareCtx *this, CAkMusicNode **out_ppParentNode)
{
  CAkMusicNode **v2; // rdi
  CAkMusicSegment *v3; // rbx
  CAkScheduleWindow v5; // [rsp+20h] [rbp-138h]

  v2 = out_ppParentNode;
  CAkScheduleWindow::CAkScheduleWindow(&v5, this, 1);
  if ( v5.m_itScheduledItem.pItem )
  {
    v3 = CAkScheduleWindow::GetNode(&v5, v2);
  }
  else
  {
    v3 = 0i64;
    if ( v2 )
      *v2 = 0i64;
  }
  _((AMD_HD3D *)&v5);
  return v3;
}

// File Line: 162
// RVA: 0xAAB620
void __fastcall CAkMatrixAwareCtx::SetSequencer(CAkMatrixAwareCtx *this, CAkMatrixSequencer *in_pSequencer)
{
  this->m_pSequencer = in_pSequencer;
}

// File Line: 179
// RVA: 0xAAB5E0
void __fastcall CAkMatrixAwareCtx::ProcessEpilogue(CAkMatrixAwareCtx *this, __int64 in_iCurrentTime, __int64 in_uNumSamples)
{
  CAkMatrixAwareCtx *v3; // rbx

  v3 = this;
  if ( !this->m_pParentCtx )
    CAkMatrixSequencer::Process(this->m_pSequencer, in_iCurrentTime, in_uNumSamples);
  if ( *((_BYTE *)&v3->0 + 98) & 2 )
    ((void (__fastcall *)(CAkMatrixAwareCtx *, __int64, __int64))v3->vfptr[1].OnPaused)(
      v3,
      in_iCurrentTime,
      in_uNumSamples);
  CAkMusicCtx::Release((CAkMusicCtx *)&v3->vfptr);
}

