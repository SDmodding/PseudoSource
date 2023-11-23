// File Line: 27
// RVA: 0xAAB2B0
void __fastcall CAkMatrixAwareCtx::CAkMatrixAwareCtx(CAkMatrixAwareCtx *this, CAkMusicCtx *in_parent)
{
  CAkMusicCtx::CAkMusicCtx(this, in_parent);
  this->CAkMusicCtx::CAkChildCtx::vfptr = (CAkChildCtxVtbl *)&CAkMatrixAwareCtx::`vftable{for `CAkChildCtx};
  this->CAkMusicCtx::CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkMatrixAwareCtx::`vftable{for `CAkTransportAware};
  this->CAkMusicCtx::ITransitionable::vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable{for `ITransitionable};
  this->m_pSequencer = 0i64;
  this->m_iLocalTime = 0i64;
}

// File Line: 31
// RVA: 0xAAB300
void __fastcall CAkMatrixAwareCtx::~CAkMatrixAwareCtx(CAkMatrixAwareCtx *this)
{
  this->CAkMusicCtx::CAkChildCtx::vfptr = (CAkChildCtxVtbl *)&CAkMatrixAwareCtx::`vftable{for `CAkChildCtx};
  this->CAkMusicCtx::CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkMatrixAwareCtx::`vftable{for `CAkTransportAware};
  this->CAkMusicCtx::ITransitionable::vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable{for `ITransitionable};
  CAkMusicCtx::~CAkMusicCtx(this);
}

// File Line: 38
// RVA: 0xAAB540
__int64 __fastcall CAkMatrixAwareCtx::Init(
        CAkMatrixAwareCtx *this,
        CAkRegisteredObj *in_pGameObj,
        UserParams *in_rUserparams)
{
  CAkMusicCtx *m_pParentCtx; // rax

  CAkMusicCtx::Init(this, in_pGameObj, in_rUserparams);
  m_pParentCtx = this->m_pParentCtx;
  if ( !m_pParentCtx )
    return CAkMusicRenderer::AddChild(CAkMusicRenderer::m_pMusicRenderer, this, in_rUserparams, in_pGameObj);
  this->m_pSequencer = (CAkMatrixSequencer *)m_pParentCtx[1].CAkChildCtx::vfptr;
  return 1i64;
}

// File Line: 61
// RVA: 0xAAB510
__int64 __fastcall CAkMatrixAwareCtx::GetSilentDuration(CAkMatrixAwareCtx *this)
{
  __int64 v2; // [rsp+30h] [rbp+8h] BYREF
  __int64 v3; // [rsp+38h] [rbp+10h] BYREF

  ((void (__fastcall *)(CAkMatrixAwareCtx *, __int64 *, __int64 *))this->CAkMusicCtx::CAkChildCtx::vfptr[2].OnLastFrame)(
    this,
    &v3,
    &v2);
  return v2 - v3;
}

// File Line: 95
// RVA: 0xAAB430
__int64 __fastcall CAkMatrixAwareCtx::GetPlayingSegmentInfo(CAkMatrixAwareCtx *this, AkSegmentInfo *out_segmentInfo)
{
  CAkScheduledItem *pItem; // rdi
  CAkMatrixAwareCtx *m_pParentCtx; // rcx
  unsigned __int64 m_uTime; // rbp
  unsigned __int64 m_iLocalTime; // rsi
  __int64 v8; // rax
  int v9; // eax
  AKRESULT Info; // ebx
  CAkScheduleWindow v12; // [rsp+20h] [rbp-138h] BYREF

  CAkScheduleWindow::CAkScheduleWindow(&v12, this, 0);
  pItem = v12.m_itScheduledItem.pItem;
  if ( v12.m_itScheduledItem.pItem )
  {
    m_pParentCtx = (CAkMatrixAwareCtx *)this->m_pParentCtx;
    m_uTime = this->m_pSequencer->m_uTime;
    m_iLocalTime = this->m_iLocalTime;
    if ( m_pParentCtx )
      m_iLocalTime += CAkMatrixAwareCtx::GetAbsoluteTimeOffset(m_pParentCtx);
    if ( pItem->m_pSegment.m_pT )
    {
      v8 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(&v12, 0);
      v9 = AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(
             &v12.m_itScheduledItem,
             m_uTime - m_iLocalTime - v8);
    }
    else
    {
      v9 = 0;
    }
    Info = CAkScheduledItem::GetInfo(pItem, v9, out_segmentInfo);
  }
  else
  {
    Info = AK_Fail;
  }
  _((AMD_HD3D *)&v12);
  return (unsigned int)Info;
}

// File Line: 107
// RVA: 0xAAB5B0
void __fastcall CAkMatrixAwareCtx::OnStopped(CAkMatrixAwareCtx *this)
{
  CAkMatrixSequencer *m_pSequencer; // rcx

  CAkMusicCtx::OnStopped(this);
  if ( !this->m_pParentCtx )
  {
    m_pSequencer = this->m_pSequencer;
    if ( m_pSequencer )
      CAkMatrixSequencer::OnStopped(m_pSequencer);
  }
}

// File Line: 149
// RVA: 0xAAB3C0
CAkMusicSegment *__fastcall CAkMatrixAwareCtx::GetFirstSegmentNode(
        CAkMatrixAwareCtx *this,
        CAkMusicNode **out_ppParentNode)
{
  CAkMusicSegment *Node; // rbx
  CAkScheduleWindow v5; // [rsp+20h] [rbp-138h] BYREF

  CAkScheduleWindow::CAkScheduleWindow(&v5, this, 1);
  if ( v5.m_itScheduledItem.pItem )
  {
    Node = CAkScheduleWindow::GetNode(&v5, out_ppParentNode);
  }
  else
  {
    Node = 0i64;
    if ( out_ppParentNode )
      *out_ppParentNode = 0i64;
  }
  _((AMD_HD3D *)&v5);
  return Node;
}

// File Line: 162
// RVA: 0xAAB620
void __fastcall CAkMatrixAwareCtx::SetSequencer(CAkMatrixAwareCtx *this, CAkMatrixSequencer *in_pSequencer)
{
  this->m_pSequencer = in_pSequencer;
}

// File Line: 179
// RVA: 0xAAB5E0
void __fastcall CAkMatrixAwareCtx::ProcessEpilogue(
        CAkMatrixAwareCtx *this,
        __int64 in_iCurrentTime,
        __int64 in_uNumSamples)
{
  if ( !this->m_pParentCtx )
    CAkMatrixSequencer::Process(this->m_pSequencer, in_iCurrentTime, in_uNumSamples);
  if ( (*((_BYTE *)&this->CAkMusicCtx + 98) & 2) != 0 )
    ((void (__fastcall *)(CAkMatrixAwareCtx *, __int64, __int64))this->CAkMusicCtx::CAkChildCtx::vfptr[1].OnPaused)(
      this,
      in_iCurrentTime,
      in_uNumSamples);
  CAkMusicCtx::Release(this);
}

