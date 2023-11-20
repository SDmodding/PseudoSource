// File Line: 44
// RVA: 0xAAB9C0
void __fastcall CAkScheduledItem::CAkScheduledItem(CAkScheduledItem *this, __int64 in_iLocalTime, CAkSegmentCtx *in_pSegment)
{
  CAkSegmentCtx *v3; // rax

  this->m_iLocalTime = in_iLocalTime;
  this->pNextItem = 0i64;
  this->m_listAssociatedActions.m_pFirst = 0i64;
  this->m_pSegment.m_pT = in_pSegment;
  if ( in_pSegment )
    ++in_pSegment->m_uRefCount;
  *(_QWORD *)&this->m_cmdPlay.iRelativeTime = 0i64;
  this->m_cmdStop.iRelativeTime = 0;
  *((_WORD *)this + 30) &= 0xFFF8u;
  v3 = this->m_pSegment.m_pT;
  if ( v3 )
    v3->m_pOwner = this;
}

// File Line: 62
// RVA: 0xAAC820
void __fastcall CAkScheduledItem::Process(CAkScheduledItem *this, __int64 in_iCurrentTime, __int64 in_uNumSamples, bool in_bSkipPlay)
{
  CAkScheduledItem *v4; // rdi
  unsigned int v5; // esi
  unsigned __int64 v6; // rbx
  CAkSegmentCtx *v7; // rcx
  bool v8; // r10
  signed __int64 v9; // rbp
  __int16 v10; // r9
  signed __int64 v11; // rax
  signed __int64 v12; // r8
  CAkSegmentCtx *v13; // rcx
  char v14; // al
  AkAssociatedAction *v15; // rbx
  AkAssociatedAction *v16; // rsi
  AkAssociatedAction *v17; // rax
  int v18; // ecx
  __m128i v19; // [rsp+20h] [rbp-28h]
  __m128i v20; // [rsp+30h] [rbp-18h]

  v4 = this;
  v5 = in_uNumSamples;
  v6 = in_iCurrentTime - this->m_iLocalTime;
  v7 = this->m_pSegment.m_pT;
  v8 = in_bSkipPlay;
  v9 = v6 + (unsigned int)in_uNumSamples;
  if ( v7 )
  {
    v10 = *((_WORD *)v4 + 30);
    if ( v10 & 1 )
    {
      v11 = v4->m_cmdPlay.iRelativeTime;
      if ( (signed int)v6 <= (signed int)v11 && v9 > v11 )
      {
        if ( v8 )
          *((_WORD *)v4 + 30) = v10 | 4;
        else
          CAkMusicCtx::_Play((CAkMusicCtx *)&v7->vfptr, &v4->m_cmdPlay.fadeParams, in_uNumSamples);
        *((_WORD *)v4 + 30) &= 0xFFFEu;
      }
    }
    else if ( v8 && *((_BYTE *)&v7->0 + 98) & 1 && !(v10 & 4) )
    {
      CAkScheduledItem::_CancelPlayback(v4, v6);
    }
    if ( *((_BYTE *)v4 + 60) & 2 )
    {
      v12 = v4->m_cmdStop.iRelativeTime;
      if ( v9 > v12 && (signed int)v6 <= (signed int)v12 )
      {
        CAkMusicCtx::_Stop(
          (CAkMusicCtx *)&v4->m_pSegment.m_pT->vfptr,
          &v4->m_cmdStop.transParams,
          (unsigned int)(v12 - v6));
        *((_WORD *)v4 + 30) &= 0xFFFDu;
      }
    }
    v13 = v4->m_pSegment.m_pT;
    if ( v13 )
    {
      v14 = *((_BYTE *)&v13->0 + 98);
      if ( v14 & 3 )
      {
        if ( !(v14 & 0x10) )
          CAkSegmentCtx::Process(v13, v6, v5);
      }
    }
  }
  v15 = v4->m_listAssociatedActions.m_pFirst;
  v16 = 0i64;
  while ( v15 )
  {
    if ( v9 <= v15->iRelativeTime )
    {
      v16 = v15;
      v15 = v15->pNextLightItem;
    }
    else
    {
      if ( v15->eActionType == 1 )
        CAkMusicRenderer::PerformDelayedStateChange(CAkMusicRenderer::m_pMusicRenderer, v15->pStingerRecord);
      v17 = v15->pNextLightItem;
      v19.m128i_i64[1] = (__int64)v16;
      v19.m128i_i64[0] = (__int64)v15->pNextLightItem;
      if ( v15 == v4->m_listAssociatedActions.m_pFirst )
        v4->m_listAssociatedActions.m_pFirst = v17;
      else
        v16->pNextLightItem = v17;
      v18 = g_DefaultPoolId;
      _mm_store_si128(&v20, v19);
      AK::MemoryMgr::Free(v18, v15);
      v16 = (AkAssociatedAction *)v20.m128i_i64[1];
      v15 = (AkAssociatedAction *)v20.m128i_i64[0];
    }
  }
}

// File Line: 155
// RVA: 0xAABED0
signed __int64 __fastcall CAkScheduledItem::GetInfo(CAkScheduledItem *this, int in_iSegmentPosition, AkSegmentInfo *out_uSegmentInfo)
{
  CAkSegmentCtx *v3; // rax
  AkSegmentInfo *v4; // rbx
  int v5; // esi
  CAkScheduledItem *v6; // rdi
  CAkMusicSegment *v7; // rbp
  double v8; // xmm6_8
  double v9; // xmm1_8
  double v10; // xmm0_8
  double v11; // xmm1_8
  double v12; // xmm0_8
  double v13; // xmm1_8
  double v14; // xmm0_8
  double v15; // xmm1_8
  double v16; // xmm0_8
  int v17; // ecx
  double v18; // xmm1_8
  signed int v19; // eax

  v3 = this->m_pSegment.m_pT;
  v4 = out_uSegmentInfo;
  v5 = in_iSegmentPosition;
  v6 = this;
  if ( v3 )
  {
    v7 = v3->m_pSegmentNode;
    v8 = DOUBLE_0_5;
    v9 = (double)CAkMusicSegment::PreEntryDuration(v3->m_pSegmentNode)
       * 1000.0
       / (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency;
    if ( v9 <= 0.0 )
      v10 = DOUBLE_N0_5;
    else
      v10 = DOUBLE_0_5;
    v4->iPreEntryDuration = (signed int)(v10 + v9);
    v11 = (double)(signed int)CAkMusicSegment::ActiveDuration(v7)
        * 1000.0
        / (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency;
    if ( v11 <= 0.0 )
      v12 = DOUBLE_N0_5;
    else
      v12 = DOUBLE_0_5;
    v4->iActiveDuration = (signed int)(v12 + v11);
    v13 = (double)(signed int)CAkMusicSegment::PostExitDuration(v7)
        * 1000.0
        / (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency;
    if ( v13 <= 0.0 )
      v14 = DOUBLE_N0_5;
    else
      v14 = DOUBLE_0_5;
    v4->iPostExitDuration = (signed int)(v14 + v13);
    v15 = (double)v5 * 1000.0 / (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency;
    if ( v15 <= 0.0 )
      v16 = DOUBLE_N0_5;
    else
      v16 = DOUBLE_0_5;
    v4->iCurrentPosition = (signed int)(v16 + v15);
    v17 = v6->m_pSegment.m_pT->m_iAudibleTime - v5;
    if ( v17 <= 0 )
    {
      v19 = 0;
    }
    else
    {
      v18 = (double)v17 * 1000.0 / (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency;
      if ( v18 <= 0.0 )
        v8 = DOUBLE_N0_5;
      v19 = (signed int)(v8 + v18);
    }
    v4->iRemainingLookAheadTime = v19;
  }
  else
  {
    *(_QWORD *)&out_uSegmentInfo->iPreEntryDuration = 0i64;
    *(_QWORD *)&out_uSegmentInfo->iPostExitDuration = 0i64;
    out_uSegmentInfo->iCurrentPosition = 0;
  }
  return 1i64;
}

// File Line: 184
// RVA: 0xAAC610
void __fastcall CAkScheduledItem::OnStopped(CAkScheduledItem *this)
{
  AkAssociatedAction *v1; // rbx
  __int64 v2; // rbp
  CAkScheduledItem *v3; // rsi
  AkAssociatedAction *v4; // rdi
  int v5; // ecx
  CAkSegmentCtx *v6; // rax
  CAkMusicCtx *v7; // rcx
  __m128i v8; // [rsp+20h] [rbp-28h]
  __m128i v9; // [rsp+30h] [rbp-18h]

  v1 = this->m_listAssociatedActions.m_pFirst;
  *((_WORD *)this + 30) &= 0xFFFCu;
  v2 = 0i64;
  v3 = this;
  if ( v1 )
  {
    while ( 1 )
    {
      if ( v1->eActionType == 1 )
        CAkMusicRenderer::PerformDelayedStateChange(CAkMusicRenderer::m_pMusicRenderer, v1->pStingerRecord);
      v4 = v1->pNextLightItem;
      v8.m128i_i64[1] = v2;
      v8.m128i_i64[0] = (__int64)v1->pNextLightItem;
      if ( v1 == v3->m_listAssociatedActions.m_pFirst )
        v3->m_listAssociatedActions.m_pFirst = v4;
      else
        *(_QWORD *)(v2 + 24) = v4;
      v5 = g_DefaultPoolId;
      _mm_store_si128(&v9, v8);
      AK::MemoryMgr::Free(v5, v1);
      if ( !v4 )
        break;
      v2 = v9.m128i_i64[1];
      v1 = (AkAssociatedAction *)v9.m128i_i64[0];
    }
  }
  v6 = v3->m_pSegment.m_pT;
  if ( v6 )
  {
    v6->m_pOwner = 0i64;
    v7 = (CAkMusicCtx *)&v3->m_pSegment.m_pT->vfptr;
    v3->m_pSegment.m_pT = 0i64;
    if ( v7 )
      CAkMusicCtx::Release(v7);
  }
}

// File Line: 221
// RVA: 0xAAC560
void __fastcall CAkScheduledItem::OnPaused(CAkScheduledItem *this)
{
  AkAssociatedAction *v1; // rbx
  AkAssociatedAction *v2; // rdi
  CAkScheduledItem *v3; // rsi
  AkAssociatedAction *v4; // rax
  int v5; // ecx
  __m128i v6; // [rsp+20h] [rbp-28h]
  __m128i v7; // [rsp+30h] [rbp-18h]

  v1 = this->m_listAssociatedActions.m_pFirst;
  v2 = 0i64;
  v3 = this;
  while ( v1 )
  {
    if ( v1->eActionType == 1 )
    {
      CAkMusicRenderer::PerformDelayedStateChange(CAkMusicRenderer::m_pMusicRenderer, v1->pStingerRecord);
      v4 = v1->pNextLightItem;
      v6.m128i_i64[1] = (__int64)v2;
      v6.m128i_i64[0] = (__int64)v1->pNextLightItem;
      if ( v1 == v3->m_listAssociatedActions.m_pFirst )
        v3->m_listAssociatedActions.m_pFirst = v4;
      else
        v2->pNextLightItem = v4;
      v5 = g_DefaultPoolId;
      _mm_store_si128(&v7, v6);
      AK::MemoryMgr::Free(v5, v1);
      v2 = (AkAssociatedAction *)v7.m128i_i64[1];
      v1 = (AkAssociatedAction *)v7.m128i_i64[0];
    }
    else
    {
      v2 = v1;
      v1 = v1->pNextLightItem;
    }
  }
}

// File Line: 248
// RVA: 0xAAC780
__int64 __fastcall CAkScheduledItem::Prepare(CAkScheduledItem *this, unsigned int in_uSyncPosition, int in_iStartPosition, AkMusicFade *in_fade)
{
  CAkScheduledItem *v4; // rbx
  CAkSegmentCtx *v5; // rcx
  __int64 result; // rax
  int v7; // edi
  unsigned int v8; // esi

  v4 = this;
  v5 = this->m_pSegment.m_pT;
  result = 0i64;
  v7 = in_iStartPosition;
  v8 = in_uSyncPosition;
  if ( v5 )
  {
    if ( in_fade->transitionTime > 0 && in_iStartPosition < in_fade->iFadeOffset )
      v7 = in_fade->iFadeOffset;
    result = in_uSyncPosition - v7 + CAkSegmentCtx::Prepare(v5, v7);
  }
  *((_WORD *)v4 + 30) |= 1u;
  *(_QWORD *)&v4->m_cmdPlay.iRelativeTime = v8 - (unsigned int)result;
  return result;
}

// File Line: 288
// RVA: 0xAAD2A0
void __fastcall CAkScheduledItem::SetFadeIn(CAkScheduledItem *this, int in_iTransDuration, AkCurveInterpolation in_eFadeCurve, int in_iFadeOffset)
{
  *((_WORD *)this + 30) |= 1u;
  this->m_cmdPlay.fadeParams.transitionTime = in_iTransDuration;
  this->m_cmdPlay.fadeParams.eFadeCurve = in_eFadeCurve;
  this->m_cmdPlay.fadeParams.iFadeOffset = in_iFadeOffset;
}

// File Line: 301
// RVA: 0xAABAB0
void __fastcall CAkScheduledItem::AttachStopCmd(CAkScheduledItem *this, int in_iTransDuration, AkCurveInterpolation in_eFadeCurve, int in_iRelativeTime)
{
  int v4; // er10
  double v5; // xmm1_8
  double v6; // xmm0_8

  v4 = this->m_cmdPlay.iRelativeTime;
  this->m_cmdStop.transParams.TransitionTime = in_iTransDuration;
  if ( in_iRelativeTime < v4 )
  {
    v5 = (double)(in_iRelativeTime - v4) * 1000.0 / (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency;
    if ( v5 <= 0.0 )
      v6 = DOUBLE_N0_5;
    else
      v6 = DOUBLE_0_5;
    in_iRelativeTime = v4;
    this->m_cmdStop.transParams.TransitionTime = in_iTransDuration + (signed int)(v6 + v5);
  }
  *((_WORD *)this + 30) |= 2u;
  this->m_cmdStop.transParams.eFadeCurve = in_eFadeCurve;
  this->m_cmdStop.iRelativeTime = in_iRelativeTime;
}

// File Line: 323
// RVA: 0xAABD30
void __fastcall CAkScheduledItem::ForcePostExit(CAkScheduledItem *this, bool in_bPlayPostExit)
{
  CAkSegmentCtx *v2; // rsi
  CAkScheduledItem *v3; // rdi
  CAkMusicSegment *v4; // rsi
  unsigned int v5; // ebx

  v2 = this->m_pSegment.m_pT;
  v3 = this;
  if ( v2 && !this->m_cmdStop.transParams.TransitionTime )
  {
    v4 = v2->m_pSegmentNode;
    if ( in_bPlayPostExit )
    {
      v5 = CAkMusicSegment::ActiveDuration(v4);
      v3->m_cmdStop.iRelativeTime = CAkMusicSegment::PostExitDuration(v4) + v5;
    }
    else
    {
      this->m_cmdStop.iRelativeTime = CAkMusicSegment::ActiveDuration(v4);
    }
  }
}

// File Line: 340
// RVA: 0xAABB80
void __fastcall CAkScheduledItem::CancelPlayback(CAkScheduledItem *this, __int64 in_iCurrentTime)
{
  CAkSegmentCtx *v2; // rax

  v2 = this->m_pSegment.m_pT;
  if ( v2 && *((_BYTE *)&v2->0 + 98) & 1 && !(*((_BYTE *)this + 60) & 4) )
    CAkScheduledItem::_CancelPlayback(this, in_iCurrentTime - LODWORD(this->m_iLocalTime));
  else
    CAkScheduledItem::OnStopped(this);
}

// File Line: 358
// RVA: 0xAAD2D0
void __fastcall CAkScheduledItem::_CancelPlayback(CAkScheduledItem *this, int in_iCurrentTime)
{
  signed int v2; // eax
  CAkScheduledItem *v3; // rbx
  CAkSegmentCtx *v4; // rcx
  int v5; // edx
  double v6; // xmm0_8
  TransParams in_transParams; // [rsp+30h] [rbp+8h]

  v2 = 0;
  v3 = this;
  v4 = this->m_pSegment.m_pT;
  in_transParams.eFadeCurve = 4;
  v5 = in_iCurrentTime - v4->m_iAudibleTime;
  if ( v5 > 0 )
    v2 = v5;
  if ( (double)v2 * 1000.0 / (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency <= 0.0 )
    v6 = DOUBLE_N0_5;
  else
    v6 = DOUBLE_0_5;
  in_transParams.TransitionTime = (signed int)(v6
                                             + (double)v2
                                             * 1000.0
                                             / (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency);
  CAkMusicCtx::_Stop((CAkMusicCtx *)&v4->vfptr, &in_transParams, 0xFFFFFFFFi64);
  *((_WORD *)v3 + 30) |= 4u;
}

// File Line: 394
// RVA: 0xAAC6F0
void __fastcall CAkScheduledItem::PopAssociatedActionsToRescheduleAfterTransitionSyncPoint(CAkScheduledItem *this, AkListBareLight<AkAssociatedAction,AkListBareLightNextItem<AkAssociatedAction> > *io_listCancelledActions, __int64 in_iMinActionTime)
{
  AkAssociatedAction *v3; // rax
  CAkScheduledItem *v4; // r11
  AkAssociatedAction *v5; // r9
  AkAssociatedAction *v6; // rcx
  AkAssociatedAction *v7; // rcx
  __int128 v8; // [rsp+0h] [rbp-28h]
  __m128i v9; // [rsp+10h] [rbp-18h]

  v3 = this->m_listAssociatedActions.m_pFirst;
  v4 = this;
  v5 = 0i64;
  while ( v3 )
  {
    if ( v3->iRelativeTime <= in_iMinActionTime && (v3->eActionType || v3->iRelativeTime != in_iMinActionTime) )
    {
      v5 = v3;
      v3 = v3->pNextLightItem;
    }
    else
    {
      v6 = v3->pNextLightItem;
      v9.m128i_i64[1] = (__int64)v5;
      v9.m128i_i64[0] = (__int64)v6;
      if ( v3 == v4->m_listAssociatedActions.m_pFirst )
        v4->m_listAssociatedActions.m_pFirst = v6;
      else
        v5->pNextLightItem = v6;
      v7 = io_listCancelledActions->m_pFirst;
      _mm_store_si128((__m128i *)&v8, v9);
      v5 = (AkAssociatedAction *)*((_QWORD *)&v8 + 1);
      if ( v7 )
      {
        v3->pNextLightItem = v7;
        io_listCancelledActions->m_pFirst = v3;
      }
      else
      {
        io_listCancelledActions->m_pFirst = v3;
        v3->pNextLightItem = 0i64;
      }
      v3 = (AkAssociatedAction *)v8;
    }
  }
}

// File Line: 416
// RVA: 0xAABB20
bool __fastcall CAkScheduledItem::CanDestroy(CAkScheduledItem *this)
{
  return !this->m_pSegment.m_pT && !(*((_BYTE *)this + 60) & 2) && !this->m_listAssociatedActions.m_pFirst;
}

// File Line: 422
// RVA: 0xAABC80
void __fastcall CAkScheduledItem::Destroy(CAkScheduledItem *this)
{
  int v1; // edi
  CAkScheduledItem *v2; // rbx
  CAkSegmentCtx *v3; // rcx

  if ( this )
  {
    v1 = g_DefaultPoolId;
    v2 = this;
    this->m_listAssociatedActions.m_pFirst = 0i64;
    v3 = this->m_pSegment.m_pT;
    if ( v3 )
    {
      CAkMusicCtx::Release((CAkMusicCtx *)&v3->vfptr);
      v2->m_pSegment.m_pT = 0i64;
    }
    AK::MemoryMgr::Free(v1, v2);
  }
}

// File Line: 432
// RVA: 0xAAC370
void __fastcall CAkScheduledItem::NotifyMusicCallbacks(CAkScheduledItem *this, int in_iSegmentPosition, unsigned int in_uFrameDuration, unsigned int in_uNotifFlags, unsigned int in_playingID)
{
  CAkScheduledItem *v5; // r13
  unsigned int v6; // er14
  unsigned int in_uRangeSize; // er12
  int v8; // er15
  AkMusicGrid *v9; // rax
  unsigned int v10; // edi
  AkMusicGrid *v11; // rbx
  unsigned int v12; // esi
  unsigned int i; // ebp
  unsigned int j; // ebp
  int v15; // eax
  unsigned int out_uNumBeats; // [rsp+30h] [rbp-38h]
  unsigned int out_uNumGrids; // [rsp+34h] [rbp-34h]
  unsigned int out_uNumBars; // [rsp+88h] [rbp+20h]

  if ( in_uNotifFlags )
  {
    v5 = this;
    v6 = in_uNotifFlags;
    in_uRangeSize = in_uFrameDuration;
    v8 = in_iSegmentPosition;
    v9 = CAkMusicNode::GetMusicGrid((CAkMusicNode *)&this->m_pSegment.m_pT->m_pSegmentNode->vfptr);
    v10 = in_playingID;
    v11 = v9;
    if ( _bittest((const signed int *)&v6, 0xDu) )
      CAkMusicSegment::NotifyUserCuesInRange(v5->m_pSegment.m_pT->m_pSegmentNode, in_playingID, v9, v8, in_uRangeSize);
    if ( _bittest((const signed int *)&v6, 0xAu) && v8 <= 0 && (signed int)(v8 + in_uRangeSize) > 0 )
      CAkPlayingMgr::NotifyMusic(g_pPlayingMgr, v10, AK_MusicSyncEntry, v11);
    CAkMusicSegment::GetNumMusicGridInRange(
      v5->m_pSegment.m_pT->m_pSegmentNode,
      v8,
      in_uRangeSize,
      &out_uNumBars,
      &out_uNumBeats,
      &out_uNumGrids);
    v12 = 0;
    if ( _bittest((const signed int *)&v6, 9u) )
    {
      for ( i = 0; i < out_uNumBars; ++i )
        CAkPlayingMgr::NotifyMusic(g_pPlayingMgr, v10, AK_MusicSyncBar, v11);
    }
    if ( _bittest((const signed int *)&v6, 8u) )
    {
      for ( j = 0; j < out_uNumBeats; ++j )
        CAkPlayingMgr::NotifyMusic(g_pPlayingMgr, v10, AK_MusicSyncBeat, v11);
    }
    if ( _bittest((const signed int *)&v6, 0xCu) && out_uNumGrids > 0 )
    {
      do
      {
        CAkPlayingMgr::NotifyMusic(g_pPlayingMgr, v10, AK_MusicSyncGrid, v11);
        ++v12;
      }
      while ( v12 < out_uNumGrids );
    }
    if ( _bittest((const signed int *)&v6, 0xBu) )
    {
      v15 = CAkMusicSegment::ActiveDuration(v5->m_pSegment.m_pT->m_pSegmentNode);
      if ( v15 >= v8 && v15 < (signed int)(v8 + in_uRangeSize) )
        CAkPlayingMgr::NotifyMusic(g_pPlayingMgr, v10, AK_MusicSyncExit, v11);
    }
  }
}

// File Line: 524
// RVA: 0xAAB900
void __fastcall CAkMatrixSequencer::CAkMatrixSequencer(CAkMatrixSequencer *this, CAkMatrixAwareCtx *in_pOwner, UserParams *in_rUserparams, CAkRegisteredObj *in_pGameObj)
{
  CAkMatrixSequencer *v4; // rbx
  CAkRegisteredObj *v5; // rsi
  AkExternalSourceArray *v6; // rcx
  AkExternalSourceArray *v7; // rdi

  this->m_pOwner = in_pOwner;
  v4 = this;
  this->vfptr = (IAkTriggerAwareVtbl *)&CAkMatrixSequencer::`vftable';
  v5 = in_pGameObj;
  this->m_uTime = 0i64;
  this->m_UserParams.m_PlayingID = 0;
  this->m_UserParams.m_CustomParam.customParam = 0i64;
  this->m_UserParams.m_CustomParam.ui32Reserved = 0;
  this->m_UserParams.m_CustomParam.pExternalSrcs = 0i64;
  this->m_pGameObj = 0i64;
  this->m_listPendingStingers.m_pFirst = 0i64;
  this->m_uCurTimeWindowSize = 0;
  this->m_UserParams.m_PlayingID = in_rUserparams->m_PlayingID;
  this->m_UserParams.m_CustomParam.customParam = in_rUserparams->m_CustomParam.customParam;
  this->m_UserParams.m_CustomParam.ui32Reserved = in_rUserparams->m_CustomParam.ui32Reserved;
  v6 = this->m_UserParams.m_CustomParam.pExternalSrcs;
  v7 = in_rUserparams->m_CustomParam.pExternalSrcs;
  if ( v6 )
    AkExternalSourceArray::Release(v6);
  if ( v7 )
    ++v7->m_cRefCount;
  v4->m_UserParams.m_CustomParam.pExternalSrcs = v7;
  v4->m_pGameObj = v5;
  *((_DWORD *)v5 + 30) ^= (*((_DWORD *)v5 + 30) ^ (*((_DWORD *)v5 + 30) + 1)) & 0x3FFFFFFF;
  CAkStateMgr::RegisterTrigger(g_pStateMgr, (IAkTriggerAware *)&v4->vfptr, v4->m_pGameObj);
}

// File Line: 534
// RVA: 0xAABA00
void __fastcall CAkMatrixSequencer::~CAkMatrixSequencer(CAkMatrixSequencer *this)
{
  CAkMatrixSequencer *v1; // rdi
  CAkRegisteredObj *v2; // rsi
  int v3; // ecx
  int v4; // ebx
  AkExternalSourceArray *v5; // rcx

  this->vfptr = (IAkTriggerAwareVtbl *)&CAkMatrixSequencer::`vftable';
  v1 = this;
  CAkMatrixSequencer::RemoveAllPendingStingers(this);
  CAkStateMgr::UnregisterTrigger(g_pStateMgr, (IAkTriggerAware *)&v1->vfptr);
  v2 = v1->m_pGameObj;
  v1->m_listPendingStingers.m_pFirst = 0i64;
  if ( v2 )
  {
    v3 = *((_DWORD *)v2 + 30) ^ (*((_DWORD *)v2 + 30) ^ (*((_DWORD *)v2 + 30) - 1)) & 0x3FFFFFFF;
    *((_DWORD *)v2 + 30) = v3;
    if ( !(v3 & 0x3FFFFFFF) )
    {
      v4 = g_DefaultPoolId;
      CAkRegisteredObj::~CAkRegisteredObj(v2);
      AK::MemoryMgr::Free(v4, v2);
    }
    v1->m_pGameObj = 0i64;
  }
  v5 = v1->m_UserParams.m_CustomParam.pExternalSrcs;
  if ( v5 )
    AkExternalSourceArray::Release(v5);
}

// File Line: 562
// RVA: 0xAABCD0
void __fastcall CAkMatrixSequencer::Execute(CAkMatrixSequencer *this, unsigned int in_uNumFrames)
{
  CAkMatrixSequencer *v2; // rbx
  CAkMatrixAwareCtx *v3; // rcx
  char v4; // al
  __int64 v5; // [rsp+20h] [rbp-18h]
  char v6; // [rsp+28h] [rbp-10h]

  v2 = this;
  ++this->m_pOwner->m_uRefCount;
  v3 = this->m_pOwner;
  v4 = *((_BYTE *)&v3->0 + 98);
  if ( v4 & 3 && !(v4 & 0x10) )
  {
    v2->m_uCurTimeWindowSize = in_uNumFrames;
    v5 = 0i64;
    v6 = 0;
    ((void (__fastcall *)(CAkMatrixAwareCtx *, unsigned __int64, _QWORD, __int64 *, _QWORD, _QWORD))v3->vfptr[1].SetPBIFade)(
      v3,
      v2->m_uTime,
      in_uNumFrames,
      &v5,
      0i64,
      *(_QWORD *)&v6);
    v2->m_uTime += v2->m_uCurTimeWindowSize;
  }
  CAkMusicCtx::Release((CAkMusicCtx *)&v2->m_pOwner->vfptr);
}

// File Line: 582
// RVA: 0xAAC600
void __fastcall CAkMatrixSequencer::OnStopped(CAkMatrixSequencer *this)
{
  CAkMatrixSequencer::RemoveAllPendingStingers(this);
}

// File Line: 591
// RVA: 0xAAC7E0
void __fastcall CAkMatrixSequencer::Process(CAkMatrixSequencer *this, __int64 in_iCurrentTime, unsigned int in_uNumSamples)
{
  unsigned int v3; // ebx
  __int64 v4; // rdi
  CAkMatrixSequencer *v5; // rsi

  v3 = in_uNumSamples;
  v4 = in_iCurrentTime;
  v5 = this;
  CAkMatrixSequencer::ProcessStingers(this, in_iCurrentTime, in_uNumSamples);
  CAkMatrixSequencer::ProcessMusicNotifications(v5, v4, v3);
}

// File Line: 630
// RVA: 0xAACF90
void __fastcall CAkMatrixSequencer::RescheduleCancelledActions(CAkMatrixSequencer *this, AkListBareLight<AkAssociatedAction,AkListBareLightNextItem<AkAssociatedAction> > *in_listActions)
{
  AkAssociatedAction *v2; // rbx
  AkListBareLight<AkAssociatedAction,AkListBareLightNextItem<AkAssociatedAction> > *v3; // r14
  CAkMatrixSequencer *v4; // rbp
  __m128i v5; // di
  AkAssociatedActionType v6; // er8
  AkStingerRecord *v7; // rdi
  CAkMatrixAwareCtx *v8; // rcx
  unsigned int v9; // er12
  bool v10; // r15
  AkStingerRecord *v11; // rax
  int v12; // ecx
  __m128i v13; // [rsp+30h] [rbp-38h]

  v2 = in_listActions->m_pFirst;
  v3 = in_listActions;
  v4 = this;
  v5.m128i_i64[1] = 0i64;
  if ( in_listActions->m_pFirst )
  {
    while ( 1 )
    {
      v6 = v2->eActionType;
      if ( v6 )
      {
        if ( v6 == 1 )
          CAkMusicRenderer::RescheduleDelayedStateChange(CAkMusicRenderer::m_pMusicRenderer, v2->pStingerRecord);
      }
      else
      {
        v7 = v2->pStingerRecord;
        v8 = v7->pStingerCtx.m_pT;
        v9 = v7->triggerID;
        v10 = v7->bCanBeRescheduled;
        if ( v8 )
          ((void (__fastcall *)(CAkMatrixAwareCtx *, unsigned __int64))v8->vfptr[2].SetPBIFade)(
            v8,
            v4->m_uTime - v4->m_pOwner->m_iLocalTime);
        v11 = v4->m_listPendingStingers.m_pFirst;
        if ( v11 )
        {
          while ( v11 != v7 )
          {
            v11 = v11->pNextLightItem;
            if ( !v11 )
              goto LABEL_13;
          }
          if ( v11 )
            v11->triggerID = 0;
        }
LABEL_13:
        if ( v10 )
          CAkMatrixSequencer::HandleTrigger(v4, v9, 1);
      }
      v5.m128i_i64[0] = (__int64)v2->pNextLightItem;
      if ( v2 == v3->m_pFirst )
        v3->m_pFirst = *(AkAssociatedAction **)v5.m128i_i8;
      else
        *(_QWORD *)(v5.m128i_i64[1] + 24) = v5.m128i_i64[0];
      v12 = g_DefaultPoolId;
      _mm_store_si128(&v13, v5);
      AK::MemoryMgr::Free(v12, v2);
      if ( !v5.m128i_i64[0] )
        break;
      v5.m128i_i64[1] = v13.m128i_i64[1];
      v2 = (AkAssociatedAction *)v13.m128i_i64[0];
    }
  }
}

// File Line: 679
// RVA: 0xAAC0C0
__int64 __fastcall CAkMatrixSequencer::GetMusicSyncFlags(CAkMatrixSequencer *this)
{
  return this->m_pOwner->m_uRegisteredNotif & 0xFF00;
}

// File Line: 690
// RVA: 0xAAD2C0
void __fastcall CAkMatrixSequencer::Trigger(CAkMatrixSequencer *this, unsigned int in_triggerID)
{
  CAkMatrixSequencer::HandleTrigger(this, in_triggerID, 0);
}

// File Line: 703
// RVA: 0xAAC0D0
void __fastcall CAkMatrixSequencer::HandleTrigger(CAkMatrixSequencer *this, unsigned int in_triggerID, bool in_bReschedule)
{
  unsigned int v3; // esi
  CAkMatrixAwareCtx *v4; // rdx
  CAkMatrixSequencer *v5; // r15
  bool v6; // bl
  CAkStinger *v7; // rdi
  signed int v8; // er13
  AKRESULT v9; // er12
  CAkStinger *v10; // r14
  CAkMusicSegment *v11; // rax
  CAkMusicNode *v12; // rcx
  CAkStinger *v13; // rbx
  CAkStinger *v14; // rax
  CAkMatrixAwareCtx *v15; // rdi
  int v16; // er14
  AkSyncType v17; // er8
  CAkStinger *v18; // rdx
  CAkMusicNode::CAkStingers io_pStingers; // [rsp+40h] [rbp-C0h]
  __int64 in_iSyncTime; // [rsp+58h] [rbp-A8h]
  unsigned __int64 v21; // [rsp+60h] [rbp-A0h]
  CAkMusicNode *out_ppParentNode; // [rsp+68h] [rbp-98h]
  CAkMusicNode *v23; // [rsp+70h] [rbp-90h]
  CAkScheduleWindow in_window; // [rsp+80h] [rbp-80h]
  int out_iLookAheadDuration; // [rsp+1F0h] [rbp+F0h]
  unsigned int io_uCueFilter; // [rsp+208h] [rbp+108h]

  v3 = in_triggerID;
  v4 = this->m_pOwner;
  v5 = this;
  v6 = in_bReschedule;
  v21 = this->m_uTime - v4->m_iLocalTime;
  CAkScheduleWindow::CAkScheduleWindow(&in_window, v4, 0);
  if ( !in_window.m_itScheduledItem.pItem )
    goto LABEL_36;
  v7 = 0i64;
  v8 = 0;
  if ( v6 )
  {
    ((void (__fastcall *)(CAkMatrixAwareCtx *, CAkScheduleWindow *, _QWORD))v5->m_pOwner->vfptr[1].VirtualRelease)(
      v5->m_pOwner,
      &in_window,
      0i64);
    v8 = 1;
  }
  v9 = 2;
  while ( 1 )
  {
    v10 = v7;
    v11 = CAkScheduleWindow::GetNode(&in_window, &out_ppParentNode);
    v12 = out_ppParentNode;
    io_pStingers.m_StingerArray.m_pItems = v7;
    *(_QWORD *)&io_pStingers.m_StingerArray.m_uLength = 0i64;
    if ( v11 )
      v12 = (CAkMusicNode *)&v11->vfptr;
    CAkMusicNode::GetStingers(v12, &io_pStingers);
    v7 = io_pStingers.m_StingerArray.m_pItems;
    v13 = io_pStingers.m_StingerArray.m_pItems;
    v14 = &io_pStingers.m_StingerArray.m_pItems[io_pStingers.m_StingerArray.m_uLength];
    if ( io_pStingers.m_StingerArray.m_pItems == v14 )
      goto LABEL_26;
    while ( v13->m_TriggerID != v3 )
    {
      ++v13;
      if ( v13 == v14 )
        goto LABEL_26;
    }
    if ( !CAkMatrixSequencer::CanPlayStinger(v5, v3) )
      break;
    v15 = CAkMatrixSequencer::CreateStingerCtx(v5, v13->m_SegmentID, &out_iLookAheadDuration);
    if ( !v15 && v13->m_SegmentID )
    {
LABEL_31:
      v18 = io_pStingers.m_StingerArray.m_pItems;
      if ( !io_pStingers.m_StingerArray.m_pItems )
        goto LABEL_36;
      goto LABEL_35;
    }
    v16 = out_iLookAheadDuration;
    v17 = v13->m_SyncPlayAt;
    io_uCueFilter = v13->m_uCueFilterHash;
    v9 = CAkScheduleWindow::FindSyncPoint(
           &in_window,
           v21 + out_iLookAheadDuration,
           v17,
           &io_uCueFilter,
           0,
           0,
           &in_iSyncTime);
    if ( v9 == 1 )
    {
      if ( CAkMatrixSequencer::ScheduleStingerForPlayback(v5, &in_window, v15, v13, in_iSyncTime, v16, v8 == 0) != 1 )
        goto LABEL_31;
      if ( v15 )
        CAkMatrixAwareCtx::GetFirstSegmentNode(v15, &v23);
    }
    else
    {
      if ( v15 )
        UFG::OnUnloadClass<UITest::HandleArrayTest>((CAkMusicCtx *)&v15->vfptr);
      if ( in_window.m_bIsDurationInfinite || v13->m_numSegmentLookAhead != 1 || v8 )
      {
        v9 = 1;
      }
      else
      {
        ((void (__fastcall *)(CAkMatrixAwareCtx *, CAkScheduleWindow *, _QWORD))v5->m_pOwner->vfptr[1].VirtualRelease)(
          v5->m_pOwner,
          &in_window,
          0i64);
        v8 = 1;
      }
    }
    v7 = io_pStingers.m_StingerArray.m_pItems;
    v10 = v13;
LABEL_26:
    if ( v7 )
    {
      io_pStingers.m_StingerArray.m_uLength = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, v7);
      v7 = 0i64;
      io_pStingers.m_StingerArray.m_pItems = 0i64;
      io_pStingers.m_StingerArray.m_ulReserved = 0;
    }
    if ( v9 == 1 || !v10 )
      goto LABEL_36;
  }
  if ( !v7 )
    goto LABEL_36;
  v18 = v7;
LABEL_35:
  io_pStingers.m_StingerArray.m_uLength = 0;
  AK::MemoryMgr::Free(g_DefaultPoolId, v18);
LABEL_36:
  _((AMD_HD3D *)&in_window);
}

// File Line: 900
// RVA: 0xAAD0C0
signed __int64 __fastcall CAkMatrixSequencer::ScheduleStingerForPlayback(CAkMatrixSequencer *this, CAkScheduleWindow *in_window, CAkMatrixAwareCtx *in_pStingerCtx, CAkStinger *in_pStingerData, __int64 in_iSyncTime, int in_iLookAheadDuration, bool in_bScheduledInCurrentSegment)
{
  CAkMatrixSequencer *v7; // rbp
  CAkScheduleWindow *v8; // r13
  CAkStinger *v9; // r15
  CAkMatrixAwareCtx *v10; // rbx
  void *v11; // rax
  void *v12; // rdi
  AkAssociatedAction *v13; // rsi
  CAkMusicCtx *v14; // rcx
  int v15; // ebx
  CAkMusicCtx *v16; // rcx
  signed __int64 result; // rax
  unsigned int v18; // eax
  unsigned int v19; // edx
  CAkMusicCtx *v20; // rcx
  CAkMusicSegment *v21; // rax
  CAkMusicSegment *v22; // r14
  unsigned int v23; // ebx
  char v24; // al
  AkStingerRecord *v25; // rax
  __int64 v26; // rax
  __int64 v27; // rax
  CAkScheduledItem *v28; // rax
  AkAssociatedAction *v29; // rcx

  v7 = this;
  v8 = in_window;
  v9 = in_pStingerData;
  v10 = in_pStingerCtx;
  v11 = AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x30ui64);
  v12 = v11;
  if ( !v11 )
    return 2i64;
  *((_QWORD *)v11 + 1) = 0i64;
  v13 = (AkAssociatedAction *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x20ui64);
  if ( v13 )
  {
    *((_DWORD *)v12 + 4) = v9->m_TriggerID;
    v18 = v9->m_SegmentID;
    *((_QWORD *)v12 + 3) = in_iSyncTime;
    *((_DWORD *)v12 + 5) = v18;
    v19 = v9->m_DontRepeatTime * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
    *((_DWORD *)v12 + 9) = in_iLookAheadDuration;
    *((_DWORD *)v12 + 8) = v19;
    if ( v10 )
    {
      ++v10->m_uRefCount;
      v10->m_iLocalTime = in_iSyncTime;
      v20 = (CAkMusicCtx *)*((_QWORD *)v12 + 1);
      *((_QWORD *)v12 + 1) = v10;
      if ( v20 )
        CAkMusicCtx::Release(v20);
      v21 = CAkMatrixAwareCtx::GetFirstSegmentNode(v10, 0i64);
      v22 = v21;
      if ( v21 )
      {
        v23 = CAkMusicSegment::ActiveDuration(v21);
        *((_DWORD *)v12 + 10) = CAkMusicSegment::PostExitDuration(v22) + v23;
      }
      else
      {
        *((_DWORD *)v12 + 10) = 0;
      }
    }
    if ( !in_bScheduledInCurrentSegment || (v24 = 1, !v9->m_numSegmentLookAhead) )
      v24 = 0;
    *((_BYTE *)v12 + 44) = v24;
    v25 = v7->m_listPendingStingers.m_pFirst;
    if ( v25 )
    {
      *(_QWORD *)v12 = v25;
      v7->m_listPendingStingers.m_pFirst = (AkStingerRecord *)v12;
    }
    else
    {
      v7->m_listPendingStingers.m_pFirst = (AkStingerRecord *)v12;
      *(_QWORD *)v12 = 0i64;
    }
    v13->eActionType = 0;
    v26 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(v8, 0);
    v27 = AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(&v8->m_itScheduledItem, in_iSyncTime - v26);
    v13->pStingerRecord = (AkStingerRecord *)v12;
    v13->iRelativeTime = v27;
    v28 = v8->m_itScheduledItem.pItem;
    v29 = v28->m_listAssociatedActions.m_pFirst;
    if ( v29 )
    {
      v13->pNextLightItem = v29;
      v28->m_listAssociatedActions.m_pFirst = v13;
    }
    else
    {
      v28->m_listAssociatedActions.m_pFirst = v13;
      v13->pNextLightItem = 0i64;
    }
    result = 1i64;
  }
  else
  {
    v14 = (CAkMusicCtx *)*((_QWORD *)v12 + 1);
    v15 = g_DefaultPoolId;
    *((_QWORD *)v12 + 1) = 0i64;
    if ( v14 )
      CAkMusicCtx::Release(v14);
    v16 = (CAkMusicCtx *)*((_QWORD *)v12 + 1);
    if ( v16 )
    {
      CAkMusicCtx::Release(v16);
      *((_QWORD *)v12 + 1) = 0i64;
    }
    AK::MemoryMgr::Free(v15, v12);
    result = 2i64;
  }
  return result;
}

// File Line: 960
// RVA: 0xAABBB0
CAkMatrixAwareCtx *__fastcall CAkMatrixSequencer::CreateStingerCtx(CAkMatrixSequencer *this, unsigned int in_segmentID, int *out_iLookAheadDuration)
{
  CAkMatrixSequencer *v3; // rdi
  int *v4; // rsi
  CAkIndexable *v5; // rax
  CAkIndexable *v6; // rbx
  CAkMatrixAwareCtx *v7; // rax
  CAkMatrixAwareCtx *v8; // rdi
  CAkChildCtxVtbl *v9; // rax
  int v10; // ST28_4
  CAkMatrixAwareCtx *result; // rax
  int v12; // [rsp+30h] [rbp-28h]
  __int64 v13; // [rsp+38h] [rbp-20h]
  int v14; // [rsp+40h] [rbp-18h]
  __int16 v15; // [rsp+44h] [rbp-14h]
  char v16; // [rsp+78h] [rbp+20h]

  v3 = this;
  v4 = out_iLookAheadDuration;
  v5 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_segmentID, 0);
  v6 = v5;
  if ( v5 )
  {
    v7 = (CAkMatrixAwareCtx *)((__int64 (__fastcall *)(CAkIndexable *, CAkMatrixAwareCtx *, CAkRegisteredObj *, UserParams *))v5->vfptr[21].__vecDelDtor)(
                                v5,
                                v3->m_pOwner,
                                v3->m_pGameObj,
                                &v3->m_UserParams);
    v8 = v7;
    if ( v7 )
    {
      v9 = v7->vfptr;
      v10 = 0;
      v13 = 0i64;
      v12 = 0;
      v15 = v15 & 0xFFE8 | 8;
      v14 = 0;
      *v4 = ((__int64 (__fastcall *)(CAkMatrixAwareCtx *, int *, _QWORD, _QWORD, char *, int, _QWORD, _QWORD, _QWORD))v9[1].VirtualAddRef)(
              v8,
              &v12,
              0i64,
              0i64,
              &v16,
              v10,
              *(_QWORD *)&v12,
              0i64,
              *(_QWORD *)&v14);
    }
    v6->vfptr->Release(v6);
    result = v8;
  }
  else
  {
    result = 0i64;
    *v4 = 0;
  }
  return result;
}

// File Line: 992
// RVA: 0xAABB40
char __fastcall CAkMatrixSequencer::CanPlayStinger(CAkMatrixSequencer *this, unsigned int in_triggerID)
{
  AkStingerRecord *i; // rax

  for ( i = this->m_listPendingStingers.m_pFirst; i; i = i->pNextLightItem )
  {
    if ( i->triggerID == in_triggerID
      && i->iSyncTime + i->uDontRepeatTime >= (signed __int64)(this->m_uTime - this->m_pOwner->m_iLocalTime) )
    {
      return 0;
    }
  }
  return 1;
}

// File Line: 1017
// RVA: 0xAACBC0
void __fastcall CAkMatrixSequencer::ProcessStingers(CAkMatrixSequencer *this, __int64 in_iCurrentTime, __int64 in_uFrameDuration)
{
  AkStingerRecord *v3; // rbx
  unsigned int v4; // er15
  __int64 v5; // rdi
  CAkMatrixSequencer *v6; // rbp
  __int64 v7; // r14
  AkStingerRecord *v8; // r9
  CAkMusicCtx *v9; // rcx
  __int64 v10; // rdx
  __int64 v11; // rax
  CAkMusicCtx *v12; // rcx
  CAkMatrixAwareCtx *v13; // rcx
  char v14; // al
  __int64 v15; // rax
  CAkMatrixAwareCtx *v16; // rax
  CAkMusicCtx *v17; // rcx
  AkStingerRecord *v18; // rax
  CAkMusicCtx *v19; // rcx
  int v20; // esi
  CAkMusicCtx *v21; // rcx
  AkMusicFade in_fadeParams; // [rsp+20h] [rbp-68h]
  __int64 v23; // [rsp+30h] [rbp-58h]
  char v24; // [rsp+38h] [rbp-50h]
  __m128i v25; // [rsp+40h] [rbp-48h]
  __m128i v26; // [rsp+50h] [rbp-38h]
  TransParams in_transParams; // [rsp+90h] [rbp+8h]

  v3 = this->m_listPendingStingers.m_pFirst;
  v4 = in_uFrameDuration;
  v5 = in_iCurrentTime;
  v6 = this;
  v7 = in_iCurrentTime + (unsigned int)in_uFrameDuration;
  v8 = 0i64;
  while ( v3 )
  {
    v9 = (CAkMusicCtx *)&v3->pStingerCtx.m_pT->vfptr;
    if ( v9 )
    {
      v10 = v3->iSyncTime - v3->iLookAheadDuration;
      if ( v7 > v10 )
      {
        if ( v5 <= v10 )
        {
          in_fadeParams.iFadeOffset = 0;
          in_fadeParams.transitionTime = 0;
          CAkMusicCtx::_Play(v9, &in_fadeParams, in_uFrameDuration);
        }
        v11 = v3->iSyncTime + v3->iRelativeStopTime;
        if ( v5 <= v11 && v7 > v11 )
        {
          v12 = (CAkMusicCtx *)&v3->pStingerCtx.m_pT->vfptr;
          in_transParams.TransitionTime = 0;
          CAkMusicCtx::_Stop(v12, &in_transParams, (unsigned int)(v11 - v5));
        }
        v13 = v3->pStingerCtx.m_pT;
        v14 = *((_BYTE *)&v13->0 + 98);
        if ( v14 & 3 )
        {
          if ( !(v14 & 0x10) )
          {
            v15 = v3->iSyncTime;
            v24 = 1;
            v23 = v15 + 1;
            ((void (__fastcall *)(CAkMatrixAwareCtx *, __int64, _QWORD, __int64 *))v13->vfptr[1].SetPBIFade)(
              v13,
              v5,
              v4,
              &v23);
            v16 = v3->pStingerCtx.m_pT;
            if ( (*((_BYTE *)&v16->0 + 98) & 0xFu) > 1 )
            {
              v17 = (CAkMusicCtx *)&v3->pStingerCtx.m_pT->vfptr;
              v3->pStingerCtx.m_pT = 0i64;
              if ( v16 )
                CAkMusicCtx::Release(v17);
            }
          }
        }
      }
    }
    else if ( v5 > v3->iSyncTime + v3->uDontRepeatTime )
    {
      v18 = v3->pNextLightItem;
      v25.m128i_i64[1] = (__int64)v8;
      v25.m128i_i64[0] = (__int64)v18;
      if ( v3 == v6->m_listPendingStingers.m_pFirst )
        v6->m_listPendingStingers.m_pFirst = v18;
      else
        v8->pNextLightItem = v18;
      v19 = (CAkMusicCtx *)&v3->pStingerCtx.m_pT->vfptr;
      v20 = g_DefaultPoolId;
      _mm_store_si128(&v26, v25);
      v3->pStingerCtx.m_pT = 0i64;
      if ( v19 )
        CAkMusicCtx::Release(v19);
      v21 = (CAkMusicCtx *)&v3->pStingerCtx.m_pT->vfptr;
      if ( v21 )
      {
        CAkMusicCtx::Release(v21);
        v3->pStingerCtx.m_pT = 0i64;
      }
      AK::MemoryMgr::Free(v20, v3);
      v8 = (AkStingerRecord *)v26.m128i_i64[1];
      v3 = (AkStingerRecord *)v26.m128i_i64[0];
      continue;
    }
    v8 = v3;
    v3 = v3->pNextLightItem;
  }
}

// File Line: 1091
// RVA: 0xAACED0
void __fastcall CAkMatrixSequencer::RemoveAllPendingStingers(CAkMatrixSequencer *this)
{
  AkStingerRecord *v1; // rbx
  CAkMatrixSequencer *v2; // rdi
  __m128i v3; // ax
  CAkMusicCtx *v4; // rcx
  int v5; // esi
  CAkMusicCtx *v6; // rcx
  __m128i v7; // [rsp+30h] [rbp-18h]

  v1 = this->m_listPendingStingers.m_pFirst;
  v2 = this;
  v3.m128i_i64[1] = 0i64;
  if ( v1 )
  {
    while ( 1 )
    {
      v3.m128i_i64[0] = (__int64)v1->pNextLightItem;
      if ( v1 == v2->m_listPendingStingers.m_pFirst )
        v2->m_listPendingStingers.m_pFirst = (AkStingerRecord *)v3.m128i_i64[0];
      else
        *(_QWORD *)v3.m128i_i64[1] = v3.m128i_i64[0];
      v4 = (CAkMusicCtx *)&v1->pStingerCtx.m_pT->vfptr;
      v5 = g_DefaultPoolId;
      _mm_store_si128(&v7, v3);
      v1->pStingerCtx.m_pT = 0i64;
      if ( v4 )
        CAkMusicCtx::Release(v4);
      v6 = (CAkMusicCtx *)&v1->pStingerCtx.m_pT->vfptr;
      if ( v6 )
      {
        CAkMusicCtx::Release(v6);
        v1->pStingerCtx.m_pT = 0i64;
      }
      AK::MemoryMgr::Free(v5, v1);
      if ( !v2->m_listPendingStingers.m_pFirst )
        break;
      v3.m128i_i64[1] = v7.m128i_i64[1];
      v1 = (AkStingerRecord *)v7.m128i_i64[0];
    }
  }
}

// File Line: 1133
// RVA: 0xAACD60
unsigned __int64 __fastcall CAkMatrixSequencer::QueryStateChangeDelay(CAkMatrixSequencer *this, unsigned int in_stateGroupID, unsigned int *out_uSegmentLookAhead, __int64 *out_iSyncTime)
{
  unsigned int v4; // er13
  CAkMatrixAwareCtx *v5; // rdx
  unsigned __int64 v6; // r14
  CAkMatrixSequencer *v7; // r15
  unsigned int *v8; // r12
  __int64 *v9; // rsi
  unsigned __int64 v10; // rbx
  CAkSegmentCtx *v11; // rbp
  signed int v12; // edi
  signed int v13; // eax
  CAkSegmentCtx *v14; // rcx
  __int64 v15; // rbx
  int v16; // eax
  CAkScheduleWindow in_window; // [rsp+20h] [rbp-158h]

  v4 = in_stateGroupID;
  v5 = this->m_pOwner;
  v6 = this->m_uTime - v5->m_iLocalTime;
  v7 = this;
  v8 = out_uSegmentLookAhead;
  v9 = out_iSyncTime;
  CAkScheduleWindow::CAkScheduleWindow(&in_window, v5, 0);
  v10 = 0i64;
  if ( !in_window.m_itScheduledItem.pItem )
    goto LABEL_21;
  v11 = in_window.m_itScheduledItem.pItem->m_pSegment.m_pT;
  v12 = 3;
  *v8 = 0;
  if ( v11 && *((_BYTE *)&v11->0 + 98) & 1 )
  {
    v13 = CAkMatrixSequencer::GetEarliestStateSyncTime(v7, &in_window, v4, v9);
    v12 = v13;
    if ( v13 == 2 )
      goto LABEL_21;
    if ( !v13 )
      goto LABEL_24;
  }
  if ( in_window.m_bIsDurationInfinite )
    goto LABEL_21;
  ((void (__fastcall *)(CAkMatrixAwareCtx *, CAkScheduleWindow *, _QWORD))v7->m_pOwner->vfptr[1].VirtualRelease)(
    v7->m_pOwner,
    &in_window,
    0i64);
  v14 = in_window.m_itScheduledItem.pItem->m_pSegment.m_pT;
  if ( !v14 )
  {
    if ( v12 == 1 && v11 && *((_BYTE *)&v11->0 + 98) & 1 )
    {
      v15 = CAkScheduleWindow::StartTime(&in_window);
      *v9 = v15;
LABEL_20:
      v10 = v15 - v6;
      goto LABEL_21;
    }
    goto LABEL_21;
  }
  if ( v12 == 3 && !(*((_BYTE *)&v14->0 + 98) & 1) )
    goto LABEL_21;
  *v8 = 1;
  v16 = CAkMatrixSequencer::GetEarliestStateSyncTime(v7, &in_window, v4, v9);
  if ( !v16 )
  {
LABEL_24:
    v15 = *v9;
    goto LABEL_20;
  }
  if ( v16 != 1 && (unsigned int)(v16 - 2) <= 1 && v12 != 3 )
  {
    v15 = CAkScheduleWindow::StartTime(&in_window);
    *v9 = v15;
    goto LABEL_20;
  }
LABEL_21:
  _((AMD_HD3D *)&in_window);
  return v10;
}

// File Line: 1252
// RVA: 0xAAC9A0
__int64 __fastcall CAkMatrixSequencer::ProcessDelayedStateChange(CAkMatrixSequencer *this, void *in_pCookie, unsigned int in_uSegmentLookAhead, __int64 in_iSyncTime)
{
  AkStingerRecord *v4; // rbp
  CAkMatrixSequencer *v5; // rdi
  unsigned int v6; // ebx
  __int64 v7; // rsi
  AkAssociatedAction *v8; // rax
  AkAssociatedAction *v9; // rbx
  unsigned int v10; // edi
  __int64 v11; // rax
  __int64 v12; // rax
  CAkScheduledItem *v13; // rax
  AkAssociatedAction *v14; // rcx
  CAkScheduleWindow v16; // [rsp+20h] [rbp-138h]

  v4 = (AkStingerRecord *)in_pCookie;
  v5 = this;
  v6 = in_uSegmentLookAhead;
  v7 = in_iSyncTime;
  CAkScheduleWindow::CAkScheduleWindow(&v16, this->m_pOwner, 0);
  if ( !v16.m_itScheduledItem.pItem )
    goto LABEL_12;
  for ( ; v6; --v6 )
    ((void (__fastcall *)(CAkMatrixAwareCtx *, CAkScheduleWindow *, _QWORD))v5->m_pOwner->vfptr[1].VirtualRelease)(
      v5->m_pOwner,
      &v16,
      0i64);
  v8 = (AkAssociatedAction *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x20ui64);
  v9 = v8;
  if ( v8 )
  {
    v10 = 1;
    v8->eActionType = 1;
    v11 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(&v16, 0);
    v12 = AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(&v16.m_itScheduledItem, v7 - v11);
    v9->pStingerRecord = v4;
    v9->iRelativeTime = v12;
    v13 = v16.m_itScheduledItem.pItem;
    v14 = v16.m_itScheduledItem.pItem->m_listAssociatedActions.m_pFirst;
    if ( v14 )
    {
      v9->pNextLightItem = v14;
      v13->m_listAssociatedActions.m_pFirst = v9;
    }
    else
    {
      v16.m_itScheduledItem.pItem->m_listAssociatedActions.m_pFirst = v9;
      v9->pNextLightItem = 0i64;
    }
  }
  else
  {
LABEL_12:
    v10 = 2;
  }
  _((AMD_HD3D *)&v16);
  return v10;
}

// File Line: 1299
// RVA: 0xAABDA0
__int64 __fastcall CAkMatrixSequencer::GetEarliestStateSyncTime(CAkMatrixSequencer *this, CAkScheduleWindow *in_window, unsigned int in_stateGroupID, __int64 *out_iSyncTime)
{
  CAkScheduleWindow *v4; // r14
  CAkMatrixSequencer *v5; // rbp
  __int64 *v6; // rsi
  unsigned int v7; // ebx
  CAkMusicSegment *v8; // rax
  AkSyncType *v9; // rdx
  AkSyncType *v10; // rbx
  unsigned int v11; // edi
  CAkMatrixAwareCtx *v12; // rax
  unsigned __int64 v13; // rdx
  AkSyncType v14; // er8
  __int64 v16; // [rsp+40h] [rbp-38h]
  CAkParameterNodeBase::CAkStateSyncArray io_pSyncTypes; // [rsp+48h] [rbp-30h]
  unsigned int io_uCueFilter; // [rsp+98h] [rbp+20h]

  v4 = in_window;
  v5 = this;
  v6 = out_iSyncTime;
  v7 = in_stateGroupID;
  *out_iSyncTime = 0i64;
  io_pSyncTypes = (CAkParameterNodeBase::CAkStateSyncArray)0i64;
  v8 = CAkScheduleWindow::GetNode(in_window, 0i64);
  CAkMusicSegment::GetStateSyncTypes(v8, v7, &io_pSyncTypes);
  v9 = io_pSyncTypes.m_StateSyncArray.m_pItems;
  if ( io_pSyncTypes.m_StateSyncArray.m_uLength )
  {
    v10 = io_pSyncTypes.m_StateSyncArray.m_pItems;
    if ( *io_pSyncTypes.m_StateSyncArray.m_pItems )
    {
      v11 = 1;
      if ( io_pSyncTypes.m_StateSyncArray.m_pItems != &io_pSyncTypes.m_StateSyncArray.m_pItems[io_pSyncTypes.m_StateSyncArray.m_uLength] )
      {
        do
        {
          v12 = v5->m_pOwner;
          v13 = v5->m_uTime;
          v14 = *v10;
          io_uCueFilter = 0;
          if ( CAkScheduleWindow::FindSyncPoint(v4, v13 - v12->m_iLocalTime, v14, &io_uCueFilter, 0, 0, &v16) == 1
            && (v11 == 1 || v16 < *v6) )
          {
            *v6 = v16;
            v11 = 0;
          }
          v9 = io_pSyncTypes.m_StateSyncArray.m_pItems;
          ++v10;
        }
        while ( v10 != &io_pSyncTypes.m_StateSyncArray.m_pItems[io_pSyncTypes.m_StateSyncArray.m_uLength] );
      }
    }
    else
    {
      v11 = 2;
    }
  }
  else
  {
    v11 = 3;
  }
  if ( v9 )
  {
    io_pSyncTypes.m_StateSyncArray.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v9);
  }
  return v11;
}

// File Line: 1369
// RVA: 0xAACAA0
void __fastcall CAkMatrixSequencer::ProcessMusicNotifications(CAkMatrixSequencer *this, __int64 in_iCurrentTime, unsigned int in_uFrameDuration)
{
  __int64 v3; // rsi
  CAkMatrixSequencer *v4; // rbx
  unsigned __int64 v5; // rbp
  int v6; // er14
  __int64 v7; // rax
  signed __int64 v8; // rax
  unsigned __int64 v9; // rcx
  CAkScheduleWindow v10; // [rsp+30h] [rbp-138h]

  v3 = in_iCurrentTime;
  v4 = this;
  v5 = in_uFrameDuration;
  CAkScheduleWindow::CAkScheduleWindow(&v10, this->m_pOwner, 0);
  if ( v10.m_itScheduledItem.pItem )
  {
    v6 = v4->m_pOwner->m_uRegisteredNotif & 0xFF00;
    CAkScheduleWindow::NotifyMusicCallbacks(&v10, v3, v5, v6, v4->m_UserParams.m_PlayingID);
    while ( !v10.m_bIsDurationInfinite )
    {
      v7 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(&v10, 0);
      v8 = AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(&v10.m_itScheduledItem, v3 - v7);
      if ( v8 >= (signed __int64)v10.m_uWindowDuration )
        v9 = 0i64;
      else
        v9 = v10.m_uWindowDuration - v8;
      if ( v9 >= v5 )
        break;
      ((void (__fastcall *)(CAkMatrixAwareCtx *, CAkScheduleWindow *, _QWORD))v4->m_pOwner->vfptr[1].VirtualRelease)(
        v4->m_pOwner,
        &v10,
        0i64);
      CAkScheduleWindow::NotifyMusicCallbacks(&v10, v3, v5, v6, v4->m_UserParams.m_PlayingID);
    }
  }
  _((AMD_HD3D *)&v10);
}

