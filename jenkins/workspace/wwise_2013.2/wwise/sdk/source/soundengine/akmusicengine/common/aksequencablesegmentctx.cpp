// File Line: 25
// RVA: 0xAB4380
void __fastcall CAkSequencableSegmentCtx::CAkSequencableSegmentCtx(CAkSequencableSegmentCtx *this, CAkMusicSegment *in_pSegmentNode, CAkMusicCtx *in_pParentCtx)
{
  CAkMusicSegment *v3; // rdi
  CAkSequencableSegmentCtx *v4; // rbx

  v3 = in_pSegmentNode;
  v4 = this;
  CAkChainCtx::CAkChainCtx((CAkChainCtx *)&this->vfptr, in_pParentCtx);
  v4->m_pSegmentNode = v3;
  v4->vfptr = (CAkChildCtxVtbl *)&CAkSequencableSegmentCtx::`vftable'{for `CAkChildCtx'};
  v4->vfptr = (CAkTransportAwareVtbl *)&CAkSequencableSegmentCtx::`vftable'{for `CAkTransportAware'};
  v4->vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable'{for `ITransitionable'};
  if ( v3 )
    v3->vfptr->AddRef((CAkIndexable *)&v3->vfptr);
}

// File Line: 40
// RVA: 0xAB4540
unsigned int __fastcall CAkSequencableSegmentCtx::Init(CAkSequencableSegmentCtx *this, CAkRegisteredObj *in_GameObject, UserParams *in_rUserparams)
{
  UserParams *v3; // rdi
  CAkRegisteredObj *v4; // rsi
  CAkSequencableSegmentCtx *v5; // rbx
  unsigned int result; // eax
  int v7; // eax
  int out_iLookAheadDuration; // [rsp+58h] [rbp+20h]

  v3 = in_rUserparams;
  v4 = in_GameObject;
  v5 = this;
  result = CAkMatrixAwareCtx::Init((CAkMatrixAwareCtx *)&this->vfptr, in_GameObject, in_rUserparams);
  if ( result == 1 )
  {
    v7 = CAkMusicSegment::PreEntryDuration(v5->m_pSegmentNode);
    result = CAkSequencableSegmentCtx::SetupSegmentChain(v5, v4, v3, -v7, &out_iLookAheadDuration);
    v5->m_iLocalTime = out_iLookAheadDuration;
  }
  return result;
}

// File Line: 72
// RVA: 0xAB4830
signed __int64 __fastcall CAkSequencableSegmentCtx::SetupSegmentChain(CAkSequencableSegmentCtx *this, CAkRegisteredObj *in_GameObject, UserParams *in_rUserparams, int in_iStartPos, int *out_iLookAheadDuration)
{
  int *v5; // r15
  CAkSequencableSegmentCtx *v6; // rdi
  int v7; // er14
  UserParams *v8; // rsi
  CAkRegisteredObj *v9; // rbp
  int v10; // ebx
  CAkSegmentCtx *v12; // rax
  CAkMusicCtx *v13; // rbx
  CAkScheduledItem *v14; // rax
  CAkScheduledItem *v15; // rsi
  CAkChildCtxVtbl *v16; // rax
  int v17; // ST28_4
  int v18; // ebx
  int v19; // eax
  unsigned int v20; // eax
  __int64 v21; // rax
  char v22; // [rsp+68h] [rbp+20h]

  v5 = out_iLookAheadDuration;
  v6 = this;
  v7 = in_iStartPos;
  *out_iLookAheadDuration = 0;
  v8 = in_rUserparams;
  v9 = in_GameObject;
  v10 = CAkMusicSegment::ActiveDuration(this->m_pSegmentNode);
  if ( v7 >= (signed int)((unsigned __int64)CAkMusicSegment::PostExitDuration(v6->m_pSegmentNode) + v10) )
    return 2i64;
  v12 = (CAkSegmentCtx *)CAkMusicSegment::CreateLowLevelSegmentCtxAndAddRef(
                           v6->m_pSegmentNode,
                           (CAkMatrixAwareCtx *)&v6->vfptr,
                           v9,
                           v8);
  v13 = (CAkMusicCtx *)&v12->vfptr;
  if ( !v12 )
    return 2i64;
  CAkChainCtx::EnqueueItem((CAkChainCtx *)&v6->vfptr, 0i64, v12);
  v15 = v14;
  CAkMusicCtx::Release(v13);
  if ( !v15 )
    return 2i64;
  v16 = v6->vfptr;
  v17 = 0;
  v6->m_iLocalTime = 0i64;
  *v5 = ((__int64 (__fastcall *)(CAkSequencableSegmentCtx *, _QWORD, _QWORD, _QWORD, char *, int))v16[1].VirtualAddRef)(
          v6,
          0i64,
          (unsigned int)v7,
          0i64,
          &v22,
          v17);
  v18 = CAkMusicSegment::ActiveDuration(v6->m_pSegmentNode);
  v19 = CAkMusicSegment::PostExitDuration(v6->m_pSegmentNode);
  CAkScheduledItem::AttachStopCmd(v15, 0, AkCurveInterpolation_Linear, v19 + v18);
  v20 = CAkMusicSegment::ActiveDuration(v6->m_pSegmentNode);
  CAkChainCtx::EnqueueItem((CAkChainCtx *)&v6->vfptr, v20, 0i64);
  return 2 - (unsigned int)(v21 != 0);
}

// File Line: 118
// RVA: 0xAB4750
signed __int64 __fastcall CAkSequencableSegmentCtx::SeekTimeAbsolute(CAkSequencableSegmentCtx *this, int *io_position, bool in_bSnapToCue)
{
  int *v3; // r14
  CAkSequencableSegmentCtx *v4; // rdi
  bool v5; // si
  int v6; // ebx
  double v7; // xmm1_8
  double v8; // xmm0_8

  v3 = io_position;
  v4 = this;
  v5 = in_bSnapToCue;
  v6 = *io_position * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
  if ( v6 < -(signed int)CAkMusicSegment::PreEntryDuration(this->m_pSegmentNode) )
    v6 = -(signed int)CAkMusicSegment::PreEntryDuration(v4->m_pSegmentNode);
  if ( v5 )
  {
    v6 = CAkMusicSegment::GetClosestCuePosition(v4->m_pSegmentNode, v6);
    v7 = (double)v6 * 1000.0 / (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency;
    if ( v7 <= 0.0 )
      v8 = DOUBLE_N0_5;
    else
      v8 = DOUBLE_0_5;
    *v3 = (signed int)(v8 + v7);
  }
  return CAkSequencableSegmentCtx::Seek(v4, v6);
}

// File Line: 138
// RVA: 0xAB46B0
signed __int64 __fastcall CAkSequencableSegmentCtx::SeekPercent(CAkSequencableSegmentCtx *this, float *io_fPercent, bool in_bSnapToCue)
{
  CAkSequencableSegmentCtx *v3; // rdi
  bool v4; // bl
  float *v5; // rbp
  int v6; // esi

  v3 = this;
  v4 = in_bSnapToCue;
  v5 = io_fPercent;
  v6 = (signed int)(float)((float)(signed int)CAkMusicSegment::ActiveDuration(this->m_pSegmentNode) * *io_fPercent);
  if ( v4 )
  {
    v6 = CAkMusicSegment::GetClosestCuePosition(v3->m_pSegmentNode, v6);
    *v5 = (float)v6 / (float)(signed int)CAkMusicSegment::ActiveDuration(v3->m_pSegmentNode);
  }
  return CAkSequencableSegmentCtx::Seek(v3, v6);
}

// File Line: 158
// RVA: 0xAB45C0
signed __int64 __fastcall CAkSequencableSegmentCtx::Seek(CAkSequencableSegmentCtx *this, int in_iSeekPosition)
{
  int v2; // esi
  CAkSequencableSegmentCtx *v3; // rdi
  CAkChildCtx *v5; // rbx
  CAkMusicCtx *v6; // rcx
  AKRESULT v7; // ebp
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // rsi
  CAkMatrixAwareCtx *v10; // rcx
  TransParams in_transParams; // [rsp+40h] [rbp+8h]

  v2 = in_iSeekPosition;
  v3 = this;
  if ( (*((_BYTE *)&this->0 + 98) & 0xFu) > 1 )
    return 2i64;
  ++this->m_uRefCount;
  v5 = this->m_listChildren.m_pFirst;
  while ( v5 )
  {
    v6 = (CAkMusicCtx *)v5;
    v5 = v5->pNextLightItem;
    UFG::OnUnloadClass<UITest::HandleArrayTest>(v6);
  }
  CAkChainCtx::Flush((CAkChainCtx *)&v3->vfptr);
  v7 = CAkSequencableSegmentCtx::SetupSegmentChain(
         v3,
         v3->m_pSequencer->m_pGameObj,
         &v3->m_pSequencer->m_UserParams,
         v2,
         (int *)&in_transParams);
  if ( v7 == 1 )
  {
    v8 = v3->m_iLocalTime;
    v9 = v3->m_pSequencer->m_uTime;
    v10 = (CAkMatrixAwareCtx *)v3->m_pParentCtx;
    if ( v10 )
      v8 += CAkMatrixAwareCtx::GetAbsoluteTimeOffset(v10);
    v3->m_iLocalTime = v9 + in_transParams.TransitionTime - v8;
  }
  else
  {
    in_transParams.eFadeCurve = 4;
    in_transParams.TransitionTime = 0;
    CAkMusicCtx::_Stop((CAkMusicCtx *)&v3->vfptr, &in_transParams, 0i64);
  }
  CAkMusicCtx::Release((CAkMusicCtx *)&v3->vfptr);
  return (unsigned int)v7;
}

// File Line: 206
// RVA: 0xAB4460
__int64 __fastcall CAkSequencableSegmentCtx::GetPlayingSegmentInfo(CAkSequencableSegmentCtx *this, AkSegmentInfo *out_segmentInfo)
{
  AkSegmentInfo *v2; // r14
  CAkSequencableSegmentCtx *v3; // rbx
  CAkScheduledItem *v4; // rdi
  unsigned int v5; // ebx
  CAkMatrixAwareCtx *v6; // rcx
  unsigned __int64 v7; // rbp
  unsigned __int64 v8; // rsi
  unsigned __int64 v9; // rax
  int v10; // eax
  CAkScheduleWindow v12; // [rsp+20h] [rbp-138h]

  v2 = out_segmentInfo;
  v3 = this;
  CAkScheduleWindow::CAkScheduleWindow(&v12, (CAkMatrixAwareCtx *)&this->vfptr, 1);
  v4 = v12.m_itScheduledItem.pItem;
  if ( v12.m_itScheduledItem.pItem )
  {
    v6 = (CAkMatrixAwareCtx *)v3->m_pParentCtx;
    v7 = v3->m_pSequencer->m_uTime;
    v8 = v3->m_iLocalTime;
    if ( v6 )
      v8 += CAkMatrixAwareCtx::GetAbsoluteTimeOffset(v6);
    if ( v4->m_pSegment.m_pT )
    {
      v9 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(&v12, 0);
      v10 = AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(&v12.m_itScheduledItem, v7 - v8 - v9);
    }
    else
    {
      v10 = 0;
    }
    v5 = CAkScheduledItem::GetInfo(v4, v10, v2);
  }
  else
  {
    v5 = LODWORD(v12.m_itScheduledItem.pItem) + 2;
  }
  _((AMD_HD3D *)&v12);
  return v5;
}

// File Line: 218
// RVA: 0xAB45B0
CAkMusicRanSeqCntr *__fastcall CAkSequencableSegmentCtx::Node(CAkSequenceCtx *this)
{
  return this->m_pSequenceNode;
}

