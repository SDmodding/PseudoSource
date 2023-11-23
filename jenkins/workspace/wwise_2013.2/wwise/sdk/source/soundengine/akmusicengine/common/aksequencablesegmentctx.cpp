// File Line: 25
// RVA: 0xAB4380
void __fastcall CAkSequencableSegmentCtx::CAkSequencableSegmentCtx(
        CAkSequencableSegmentCtx *this,
        CAkMusicSegment *in_pSegmentNode,
        CAkMusicCtx *in_pParentCtx)
{
  CAkChainCtx::CAkChainCtx(this, in_pParentCtx);
  this->m_pSegmentNode = in_pSegmentNode;
  this->CAkChainCtx::CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr = (CAkChildCtxVtbl *)&CAkSequencableSegmentCtx::`vftable{for `CAkChildCtx};
  this->CAkChainCtx::CAkMatrixAwareCtx::CAkMusicCtx::CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkSequencableSegmentCtx::`vftable{for `CAkTransportAware};
  this->CAkChainCtx::CAkMatrixAwareCtx::CAkMusicCtx::ITransitionable::vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable{for `ITransitionable};
  if ( in_pSegmentNode )
    in_pSegmentNode->vfptr->AddRef(in_pSegmentNode);
}

// File Line: 40
// RVA: 0xAB4540
unsigned int __fastcall CAkSequencableSegmentCtx::Init(
        CAkSequencableSegmentCtx *this,
        CAkRegisteredObj *in_GameObject,
        UserParams *in_rUserparams)
{
  unsigned int result; // eax
  int v7; // eax
  int out_iLookAheadDuration; // [rsp+58h] [rbp+20h] BYREF

  result = CAkMatrixAwareCtx::Init(this, in_GameObject, in_rUserparams);
  if ( result == 1 )
  {
    v7 = CAkMusicSegment::PreEntryDuration(this->m_pSegmentNode);
    result = CAkSequencableSegmentCtx::SetupSegmentChain(
               this,
               in_GameObject,
               in_rUserparams,
               -v7,
               &out_iLookAheadDuration);
    this->m_iLocalTime = out_iLookAheadDuration;
  }
  return result;
}

// File Line: 72
// RVA: 0xAB4830
__int64 __fastcall CAkSequencableSegmentCtx::SetupSegmentChain(
        CAkSequencableSegmentCtx *this,
        CAkRegisteredObj *in_GameObject,
        UserParams *in_rUserparams,
        int in_iStartPos,
        int *out_iLookAheadDuration)
{
  int *v5; // r15
  int active; // ebx
  CAkSegmentCtx *LowLevelSegmentCtxAndAddRef; // rax
  CAkMusicCtx *v13; // rbx
  CAkScheduledItem *v14; // rax
  CAkScheduledItem *v15; // rsi
  CAkChildCtxVtbl *vfptr; // rax
  int v17; // ebx
  int v18; // eax
  unsigned int v19; // eax
  __int64 v20; // rax
  char v21; // [rsp+68h] [rbp+20h] BYREF

  v5 = out_iLookAheadDuration;
  *out_iLookAheadDuration = 0;
  active = CAkMusicSegment::ActiveDuration(this->m_pSegmentNode);
  if ( in_iStartPos >= (int)(CAkMusicSegment::PostExitDuration(this->m_pSegmentNode) + active) )
    return 2i64;
  LowLevelSegmentCtxAndAddRef = CAkMusicSegment::CreateLowLevelSegmentCtxAndAddRef(
                                  this->m_pSegmentNode,
                                  this,
                                  in_GameObject,
                                  in_rUserparams);
  v13 = LowLevelSegmentCtxAndAddRef;
  if ( !LowLevelSegmentCtxAndAddRef )
    return 2i64;
  CAkChainCtx::EnqueueItem(this, 0i64, LowLevelSegmentCtxAndAddRef);
  v15 = v14;
  CAkMusicCtx::Release(v13);
  if ( !v15 )
    return 2i64;
  vfptr = this->CAkChainCtx::CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr;
  this->m_iLocalTime = 0i64;
  *v5 = ((__int64 (__fastcall *)(CAkSequencableSegmentCtx *, _QWORD, _QWORD, _QWORD, char *, _DWORD))vfptr[1].VirtualAddRef)(
          this,
          0i64,
          (unsigned int)in_iStartPos,
          0i64,
          &v21,
          0);
  v17 = CAkMusicSegment::ActiveDuration(this->m_pSegmentNode);
  v18 = CAkMusicSegment::PostExitDuration(this->m_pSegmentNode);
  CAkScheduledItem::AttachStopCmd(v15, 0, AkCurveInterpolation_Linear, v18 + v17);
  v19 = CAkMusicSegment::ActiveDuration(this->m_pSegmentNode);
  CAkChainCtx::EnqueueItem(this, v19, 0i64);
  return 2 - (unsigned int)(v20 != 0);
}

// File Line: 118
// RVA: 0xAB4750
__int64 __fastcall CAkSequencableSegmentCtx::SeekTimeAbsolute(
        CAkSequencableSegmentCtx *this,
        int *io_position,
        bool in_bSnapToCue)
{
  int ClosestCuePosition; // ebx
  double v7; // xmm1_8
  double v8; // xmm0_8

  ClosestCuePosition = *io_position * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
  if ( ClosestCuePosition < -(int)CAkMusicSegment::PreEntryDuration(this->m_pSegmentNode) )
    ClosestCuePosition = -(int)CAkMusicSegment::PreEntryDuration(this->m_pSegmentNode);
  if ( in_bSnapToCue )
  {
    ClosestCuePosition = CAkMusicSegment::GetClosestCuePosition(this->m_pSegmentNode, ClosestCuePosition);
    v7 = (double)ClosestCuePosition * 1000.0 / (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency;
    if ( v7 <= 0.0 )
      v8 = DOUBLE_N0_5;
    else
      v8 = DOUBLE_0_5;
    *io_position = (int)(v8 + v7);
  }
  return CAkSequencableSegmentCtx::Seek(this, ClosestCuePosition);
}

// File Line: 138
// RVA: 0xAB46B0
__int64 __fastcall CAkSequencableSegmentCtx::SeekPercent(
        CAkSequencableSegmentCtx *this,
        float *io_fPercent,
        bool in_bSnapToCue)
{
  int ClosestCuePosition; // esi

  ClosestCuePosition = (int)(float)((float)(int)CAkMusicSegment::ActiveDuration(this->m_pSegmentNode) * *io_fPercent);
  if ( in_bSnapToCue )
  {
    ClosestCuePosition = CAkMusicSegment::GetClosestCuePosition(this->m_pSegmentNode, ClosestCuePosition);
    *io_fPercent = (float)ClosestCuePosition / (float)(int)CAkMusicSegment::ActiveDuration(this->m_pSegmentNode);
  }
  return CAkSequencableSegmentCtx::Seek(this, ClosestCuePosition);
}

// File Line: 158
// RVA: 0xAB45C0
__int64 __fastcall CAkSequencableSegmentCtx::Seek(CAkSequencableSegmentCtx *this, int in_iSeekPosition)
{
  CAkChildCtx *m_pFirst; // rbx
  CAkMusicCtx *v6; // rcx
  AKRESULT v7; // ebp
  unsigned __int64 m_iLocalTime; // rbx
  unsigned __int64 m_uTime; // rsi
  CAkMatrixAwareCtx *m_pParentCtx; // rcx
  TransParams in_transParams; // [rsp+40h] [rbp+8h] BYREF

  if ( (*((_BYTE *)&this->CAkMusicCtx + 98) & 0xFu) > 1 )
    return 2i64;
  ++this->m_uRefCount;
  m_pFirst = this->m_listChildren.m_pFirst;
  while ( m_pFirst )
  {
    v6 = (CAkMusicCtx *)m_pFirst;
    m_pFirst = m_pFirst->pNextLightItem;
    UFG::OnUnloadClass<UITest::HandleArrayTest>(v6);
  }
  CAkChainCtx::Flush(this);
  v7 = CAkSequencableSegmentCtx::SetupSegmentChain(
         this,
         this->m_pSequencer->m_pGameObj,
         &this->m_pSequencer->m_UserParams,
         in_iSeekPosition,
         (int *)&in_transParams);
  if ( v7 == AK_Success )
  {
    m_iLocalTime = this->m_iLocalTime;
    m_uTime = this->m_pSequencer->m_uTime;
    m_pParentCtx = (CAkMatrixAwareCtx *)this->m_pParentCtx;
    if ( m_pParentCtx )
      m_iLocalTime += CAkMatrixAwareCtx::GetAbsoluteTimeOffset(m_pParentCtx);
    this->m_iLocalTime = m_uTime + in_transParams.TransitionTime - m_iLocalTime;
  }
  else
  {
    in_transParams.eFadeCurve = AkCurveInterpolation_Linear;
    in_transParams.TransitionTime = 0;
    CAkMusicCtx::_Stop(this, &in_transParams, 0i64);
  }
  CAkMusicCtx::Release(this);
  return (unsigned int)v7;
}

// File Line: 206
// RVA: 0xAB4460
__int64 __fastcall CAkSequencableSegmentCtx::GetPlayingSegmentInfo(
        CAkSequencableSegmentCtx *this,
        AkSegmentInfo *out_segmentInfo)
{
  CAkScheduledItem *pItem; // rdi
  unsigned int Info; // ebx
  CAkMatrixAwareCtx *m_pParentCtx; // rcx
  unsigned __int64 m_uTime; // rbp
  unsigned __int64 m_iLocalTime; // rsi
  unsigned __int64 v9; // rax
  int v10; // eax
  CAkScheduleWindow v12; // [rsp+20h] [rbp-138h] BYREF

  CAkScheduleWindow::CAkScheduleWindow(&v12, this, 1);
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
      v9 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(&v12, 0);
      v10 = AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(
              &v12.m_itScheduledItem,
              m_uTime - m_iLocalTime - v9);
    }
    else
    {
      v10 = 0;
    }
    Info = CAkScheduledItem::GetInfo(pItem, v10, out_segmentInfo);
  }
  else
  {
    Info = 2;
  }
  _((AMD_HD3D *)&v12);
  return Info;
}

// File Line: 218
// RVA: 0xAB45B0
CAkMusicRanSeqCntr *__fastcall CAkSequencableSegmentCtx::Node(CAkSequenceCtx *this)
{
  return this->m_pSequenceNode;
}

