// File Line: 44
// RVA: 0xAAB9C0
void __fastcall CAkScheduledItem::CAkScheduledItem(
        CAkScheduledItem *this,
        unsigned __int64 in_iLocalTime,
        CAkSegmentCtx *in_pSegment)
{
  CAkSegmentCtx *m_pT; // rax

  this->m_iLocalTime = in_iLocalTime;
  this->pNextItem = 0i64;
  this->m_listAssociatedActions.m_pFirst = 0i64;
  this->m_pSegment.m_pT = in_pSegment;
  if ( in_pSegment )
    ++in_pSegment->m_uRefCount;
  *(_QWORD *)&this->m_cmdPlay.iRelativeTime = 0i64;
  this->m_cmdStop.iRelativeTime = 0;
  *((_WORD *)this + 30) &= 0xFFF8u;
  m_pT = this->m_pSegment.m_pT;
  if ( m_pT )
    m_pT->m_pOwner = this;
}

// File Line: 62
// RVA: 0xAAC820
void __fastcall CAkScheduledItem::Process(
        CAkScheduledItem *this,
        __int64 in_iCurrentTime,
        CAkTransition **in_uNumSamples,
        bool in_bSkipPlay)
{
  unsigned int v5; // esi
  __int64 v6; // rbx
  CAkSegmentCtx *m_pT; // rcx
  __int64 v9; // rbp
  __int16 v10; // r9
  __int64 iRelativeTime; // rax
  __int64 v12; // r8
  CAkSegmentCtx *v13; // rcx
  char v14; // al
  AkAssociatedAction *m_pFirst; // rbx
  AkAssociatedAction *v16; // rsi
  AkAssociatedAction *pNextLightItem; // rax
  AkAssociatedAction *v18; // [rsp+20h] [rbp-28h]

  v5 = (unsigned int)in_uNumSamples;
  v6 = in_iCurrentTime - this->m_iLocalTime;
  m_pT = this->m_pSegment.m_pT;
  v9 = v6 + (unsigned int)in_uNumSamples;
  if ( m_pT )
  {
    v10 = *((_WORD *)this + 30);
    if ( (v10 & 1) != 0 )
    {
      iRelativeTime = this->m_cmdPlay.iRelativeTime;
      if ( (int)v6 <= (int)iRelativeTime && v9 > iRelativeTime )
      {
        if ( in_bSkipPlay )
          *((_WORD *)this + 30) = v10 | 4;
        else
          CAkMusicCtx::_Play(m_pT, &this->m_cmdPlay.fadeParams, in_uNumSamples);
        *((_WORD *)this + 30) &= ~1u;
      }
    }
    else if ( in_bSkipPlay && (*((_BYTE *)&m_pT->CAkMusicCtx + 98) & 1) != 0 && (v10 & 4) == 0 )
    {
      CAkScheduledItem::_CancelPlayback(this, v6);
    }
    if ( (*((_BYTE *)this + 60) & 2) != 0 )
    {
      v12 = this->m_cmdStop.iRelativeTime;
      if ( v9 > v12 && (int)v6 <= (int)v12 )
      {
        CAkMusicCtx::_Stop(
          this->m_pSegment.m_pT,
          &this->m_cmdStop.transParams,
          (CAkTransition **)(unsigned int)(v12 - v6));
        *((_WORD *)this + 30) &= ~2u;
      }
    }
    v13 = this->m_pSegment.m_pT;
    if ( v13 )
    {
      v14 = *((_BYTE *)&v13->CAkMusicCtx + 98);
      if ( (v14 & 3) != 0 && (v14 & 0x10) == 0 )
        CAkSegmentCtx::Process(v13, v6, v5);
    }
  }
  m_pFirst = this->m_listAssociatedActions.m_pFirst;
  v16 = 0i64;
  while ( m_pFirst )
  {
    if ( v9 <= m_pFirst->iRelativeTime )
    {
      v16 = m_pFirst;
      m_pFirst = m_pFirst->pNextLightItem;
    }
    else
    {
      if ( m_pFirst->eActionType == AssocActionTypeState )
        CAkMusicRenderer::PerformDelayedStateChange(
          CAkMusicRenderer::m_pMusicRenderer,
          (CAkMusicRenderer::AkStateChangeRecord *)m_pFirst->pStingerRecord);
      pNextLightItem = m_pFirst->pNextLightItem;
      v18 = pNextLightItem;
      if ( m_pFirst == this->m_listAssociatedActions.m_pFirst )
        this->m_listAssociatedActions.m_pFirst = pNextLightItem;
      else
        v16->pNextLightItem = pNextLightItem;
      AK::MemoryMgr::Free(g_DefaultPoolId, m_pFirst);
      m_pFirst = v18;
    }
  }
}

// File Line: 155
// RVA: 0xAABED0
__int64 __fastcall CAkScheduledItem::GetInfo(
        CAkScheduledItem *this,
        int in_iSegmentPosition,
        AkSegmentInfo *out_uSegmentInfo)
{
  CAkSegmentCtx *m_pT; // rax
  CAkMusicSegment *m_pSegmentNode; // rbp
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
  int v19; // eax

  m_pT = this->m_pSegment.m_pT;
  if ( m_pT )
  {
    m_pSegmentNode = m_pT->m_pSegmentNode;
    v8 = DOUBLE_0_5;
    v9 = (double)CAkMusicSegment::PreEntryDuration(m_pSegmentNode)
       * 1000.0
       / (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency;
    if ( v9 <= 0.0 )
      v10 = DOUBLE_N0_5;
    else
      v10 = DOUBLE_0_5;
    out_uSegmentInfo->iPreEntryDuration = (int)(v10 + v9);
    v11 = (double)(int)CAkMusicSegment::ActiveDuration(m_pSegmentNode)
        * 1000.0
        / (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency;
    if ( v11 <= 0.0 )
      v12 = DOUBLE_N0_5;
    else
      v12 = DOUBLE_0_5;
    out_uSegmentInfo->iActiveDuration = (int)(v12 + v11);
    v13 = (double)(int)CAkMusicSegment::PostExitDuration(m_pSegmentNode)
        * 1000.0
        / (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency;
    if ( v13 <= 0.0 )
      v14 = DOUBLE_N0_5;
    else
      v14 = DOUBLE_0_5;
    out_uSegmentInfo->iPostExitDuration = (int)(v14 + v13);
    v15 = (double)in_iSegmentPosition * 1000.0 / (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency;
    if ( v15 <= 0.0 )
      v16 = DOUBLE_N0_5;
    else
      v16 = DOUBLE_0_5;
    out_uSegmentInfo->iCurrentPosition = (int)(v16 + v15);
    v17 = this->m_pSegment.m_pT->m_iAudibleTime - in_iSegmentPosition;
    if ( v17 <= 0 )
    {
      v19 = 0;
    }
    else
    {
      v18 = (double)v17 * 1000.0 / (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency;
      if ( v18 <= 0.0 )
        v8 = DOUBLE_N0_5;
      v19 = (int)(v8 + v18);
    }
    out_uSegmentInfo->iRemainingLookAheadTime = v19;
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
  AkAssociatedAction *m_pFirst; // rbx
  AkAssociatedAction *pNextLightItem; // rdi
  CAkSegmentCtx *m_pT; // rax
  CAkSegmentCtx *v5; // rcx

  m_pFirst = this->m_listAssociatedActions.m_pFirst;
  *((_WORD *)this + 30) &= 0xFFFCu;
  if ( m_pFirst )
  {
    while ( 1 )
    {
      if ( m_pFirst->eActionType == AssocActionTypeState )
        CAkMusicRenderer::PerformDelayedStateChange(
          CAkMusicRenderer::m_pMusicRenderer,
          (CAkMusicRenderer::AkStateChangeRecord *)m_pFirst->pStingerRecord);
      pNextLightItem = m_pFirst->pNextLightItem;
      if ( m_pFirst == this->m_listAssociatedActions.m_pFirst )
        this->m_listAssociatedActions.m_pFirst = pNextLightItem;
      else
        MEMORY[0x18] = m_pFirst->pNextLightItem;
      AK::MemoryMgr::Free(g_DefaultPoolId, m_pFirst);
      if ( !pNextLightItem )
        break;
      m_pFirst = pNextLightItem;
    }
  }
  m_pT = this->m_pSegment.m_pT;
  if ( m_pT )
  {
    m_pT->m_pOwner = 0i64;
    v5 = this->m_pSegment.m_pT;
    this->m_pSegment.m_pT = 0i64;
    if ( v5 )
      CAkMusicCtx::Release(v5);
  }
}

// File Line: 221
// RVA: 0xAAC560
void __fastcall CAkScheduledItem::OnPaused(CAkScheduledItem *this)
{
  AkAssociatedAction *m_pFirst; // rbx
  AkAssociatedAction *v2; // rdi
  AkAssociatedAction *pNextLightItem; // rax
  AkAssociatedAction *v5; // [rsp+20h] [rbp-28h]

  m_pFirst = this->m_listAssociatedActions.m_pFirst;
  v2 = 0i64;
  while ( m_pFirst )
  {
    if ( m_pFirst->eActionType == AssocActionTypeState )
    {
      CAkMusicRenderer::PerformDelayedStateChange(
        CAkMusicRenderer::m_pMusicRenderer,
        (CAkMusicRenderer::AkStateChangeRecord *)m_pFirst->pStingerRecord);
      pNextLightItem = m_pFirst->pNextLightItem;
      v5 = pNextLightItem;
      if ( m_pFirst == this->m_listAssociatedActions.m_pFirst )
        this->m_listAssociatedActions.m_pFirst = pNextLightItem;
      else
        v2->pNextLightItem = pNextLightItem;
      AK::MemoryMgr::Free(g_DefaultPoolId, m_pFirst);
      m_pFirst = v5;
    }
    else
    {
      v2 = m_pFirst;
      m_pFirst = m_pFirst->pNextLightItem;
    }
  }
}

// File Line: 248
// RVA: 0xAAC780
__int64 __fastcall CAkScheduledItem::Prepare(
        CAkScheduledItem *this,
        unsigned int in_uSyncPosition,
        int in_iStartPosition,
        AkMusicFade *in_fade)
{
  CAkSegmentCtx *m_pT; // rcx
  __int64 result; // rax
  int iFadeOffset; // edi

  m_pT = this->m_pSegment.m_pT;
  result = 0i64;
  iFadeOffset = in_iStartPosition;
  if ( m_pT )
  {
    if ( in_fade->transitionTime > 0 && in_iStartPosition < in_fade->iFadeOffset )
      iFadeOffset = in_fade->iFadeOffset;
    result = in_uSyncPosition - iFadeOffset + CAkSegmentCtx::Prepare(m_pT, iFadeOffset);
  }
  *((_WORD *)this + 30) |= 1u;
  *(_QWORD *)&this->m_cmdPlay.iRelativeTime = in_uSyncPosition - (unsigned int)result;
  return result;
}

// File Line: 288
// RVA: 0xAAD2A0
void __fastcall CAkScheduledItem::SetFadeIn(
        CAkScheduledItem *this,
        int in_iTransDuration,
        AkCurveInterpolation in_eFadeCurve,
        int in_iFadeOffset)
{
  *((_WORD *)this + 30) |= 1u;
  this->m_cmdPlay.fadeParams.transitionTime = in_iTransDuration;
  this->m_cmdPlay.fadeParams.eFadeCurve = in_eFadeCurve;
  this->m_cmdPlay.fadeParams.iFadeOffset = in_iFadeOffset;
}

// File Line: 301
// RVA: 0xAABAB0
void __fastcall CAkScheduledItem::AttachStopCmd(
        CAkScheduledItem *this,
        int in_iTransDuration,
        AkCurveInterpolation in_eFadeCurve,
        int in_iRelativeTime)
{
  int iRelativeTime; // r10d
  double v5; // xmm1_8
  double v6; // xmm0_8

  iRelativeTime = this->m_cmdPlay.iRelativeTime;
  this->m_cmdStop.transParams.TransitionTime = in_iTransDuration;
  if ( in_iRelativeTime < iRelativeTime )
  {
    v5 = (double)(in_iRelativeTime - iRelativeTime) * 1000.0 / (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency;
    if ( v5 <= 0.0 )
      v6 = DOUBLE_N0_5;
    else
      v6 = DOUBLE_0_5;
    in_iRelativeTime = iRelativeTime;
    this->m_cmdStop.transParams.TransitionTime = in_iTransDuration + (int)(v6 + v5);
  }
  *((_WORD *)this + 30) |= 2u;
  this->m_cmdStop.transParams.eFadeCurve = in_eFadeCurve;
  this->m_cmdStop.iRelativeTime = in_iRelativeTime;
}

// File Line: 323
// RVA: 0xAABD30
void __fastcall CAkScheduledItem::ForcePostExit(CAkScheduledItem *this, bool in_bPlayPostExit)
{
  CAkSegmentCtx *m_pT; // rsi
  CAkMusicSegment *m_pSegmentNode; // rsi
  unsigned int active; // ebx

  m_pT = this->m_pSegment.m_pT;
  if ( m_pT && !this->m_cmdStop.transParams.TransitionTime )
  {
    m_pSegmentNode = m_pT->m_pSegmentNode;
    if ( in_bPlayPostExit )
    {
      active = CAkMusicSegment::ActiveDuration(m_pSegmentNode);
      this->m_cmdStop.iRelativeTime = CAkMusicSegment::PostExitDuration(m_pSegmentNode) + active;
    }
    else
    {
      this->m_cmdStop.iRelativeTime = CAkMusicSegment::ActiveDuration(m_pSegmentNode);
    }
  }
}

// File Line: 340
// RVA: 0xAABB80
void __fastcall CAkScheduledItem::CancelPlayback(CAkScheduledItem *this, __int64 in_iCurrentTime)
{
  CAkSegmentCtx *m_pT; // rax

  m_pT = this->m_pSegment.m_pT;
  if ( m_pT && (*((_BYTE *)&m_pT->CAkMusicCtx + 98) & 1) != 0 && (*((_BYTE *)this + 60) & 4) == 0 )
    CAkScheduledItem::_CancelPlayback(this, in_iCurrentTime - LODWORD(this->m_iLocalTime));
  else
    CAkScheduledItem::OnStopped(this);
}

// File Line: 358
// RVA: 0xAAD2D0
void __fastcall CAkScheduledItem::_CancelPlayback(CAkScheduledItem *this, int in_iCurrentTime)
{
  int v2; // eax
  CAkSegmentCtx *m_pT; // rcx
  int v5; // edx
  double v6; // xmm0_8
  TransParams in_transParams; // [rsp+30h] [rbp+8h] BYREF

  v2 = 0;
  m_pT = this->m_pSegment.m_pT;
  in_transParams.eFadeCurve = AkCurveInterpolation_Linear;
  v5 = in_iCurrentTime - m_pT->m_iAudibleTime;
  if ( v5 > 0 )
    v2 = v5;
  if ( (double)v2 * 1000.0 / (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency <= 0.0 )
    v6 = DOUBLE_N0_5;
  else
    v6 = DOUBLE_0_5;
  in_transParams.TransitionTime = (int)(v6
                                      + (double)v2 * 1000.0 / (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency);
  CAkMusicCtx::_Stop(m_pT, &in_transParams, (CAkTransition **)0xFFFFFFFFi64);
  *((_WORD *)this + 30) |= 4u;
}

// File Line: 394
// RVA: 0xAAC6F0
void __fastcall CAkScheduledItem::PopAssociatedActionsToRescheduleAfterTransitionSyncPoint(
        CAkScheduledItem *this,
        AkListBareLight<AkAssociatedAction,AkListBareLightNextItem<AkAssociatedAction> > *io_listCancelledActions,
        __int64 in_iMinActionTime)
{
  AkAssociatedAction *m_pFirst; // rax
  AkAssociatedAction *v5; // r9
  AkAssociatedAction *pNextLightItem; // rcx

  m_pFirst = this->m_listAssociatedActions.m_pFirst;
  v5 = 0i64;
  while ( m_pFirst )
  {
    if ( m_pFirst->iRelativeTime > in_iMinActionTime
      || m_pFirst->eActionType == AssocActionTypeStinger && m_pFirst->iRelativeTime == in_iMinActionTime )
    {
      pNextLightItem = m_pFirst->pNextLightItem;
      if ( m_pFirst == this->m_listAssociatedActions.m_pFirst )
        this->m_listAssociatedActions.m_pFirst = pNextLightItem;
      else
        v5->pNextLightItem = pNextLightItem;
      if ( io_listCancelledActions->m_pFirst )
      {
        m_pFirst->pNextLightItem = io_listCancelledActions->m_pFirst;
        io_listCancelledActions->m_pFirst = m_pFirst;
      }
      else
      {
        io_listCancelledActions->m_pFirst = m_pFirst;
        m_pFirst->pNextLightItem = 0i64;
      }
      m_pFirst = pNextLightItem;
    }
    else
    {
      v5 = m_pFirst;
      m_pFirst = m_pFirst->pNextLightItem;
    }
  }
}

// File Line: 416
// RVA: 0xAABB20
bool __fastcall CAkScheduledItem::CanDestroy(CAkScheduledItem *this)
{
  return !this->m_pSegment.m_pT && (*((_BYTE *)this + 60) & 2) == 0 && !this->m_listAssociatedActions.m_pFirst;
}

// File Line: 422
// RVA: 0xAABC80
void __fastcall CAkScheduledItem::Destroy(CAkScheduledItem *this)
{
  int v1; // edi
  CAkSegmentCtx *m_pT; // rcx

  if ( this )
  {
    v1 = g_DefaultPoolId;
    this->m_listAssociatedActions.m_pFirst = 0i64;
    m_pT = this->m_pSegment.m_pT;
    if ( m_pT )
    {
      CAkMusicCtx::Release(m_pT);
      this->m_pSegment.m_pT = 0i64;
    }
    AK::MemoryMgr::Free(v1, this);
  }
}

// File Line: 432
// RVA: 0xAAC370
void __fastcall CAkScheduledItem::NotifyMusicCallbacks(
        CAkScheduledItem *this,
        int in_iSegmentPosition,
        unsigned int in_uFrameDuration,
        unsigned int in_uNotifFlags,
        unsigned int in_playingID)
{
  __int16 v6; // r14
  AkMusicGrid *MusicGrid; // rax
  unsigned int v10; // edi
  AkMusicGrid *v11; // rbx
  unsigned int v12; // esi
  unsigned int i; // ebp
  unsigned int j; // ebp
  signed int active; // eax
  unsigned int out_uNumBeats; // [rsp+30h] [rbp-38h] BYREF
  unsigned int out_uNumGrids[3]; // [rsp+34h] [rbp-34h] BYREF
  unsigned int out_uNumBars; // [rsp+88h] [rbp+20h] BYREF

  if ( in_uNotifFlags )
  {
    v6 = in_uNotifFlags;
    MusicGrid = CAkMusicNode::GetMusicGrid(this->m_pSegment.m_pT->m_pSegmentNode);
    v10 = in_playingID;
    v11 = MusicGrid;
    if ( (v6 & 0x2000) != 0 )
      CAkMusicSegment::NotifyUserCuesInRange(
        this->m_pSegment.m_pT->m_pSegmentNode,
        in_playingID,
        MusicGrid,
        in_iSegmentPosition,
        in_uFrameDuration);
    if ( (v6 & 0x400) != 0 && in_iSegmentPosition <= 0 && (int)(in_iSegmentPosition + in_uFrameDuration) > 0 )
      CAkPlayingMgr::NotifyMusic(g_pPlayingMgr, v10, 0x400u, v11);
    CAkMusicSegment::GetNumMusicGridInRange(
      this->m_pSegment.m_pT->m_pSegmentNode,
      in_iSegmentPosition,
      in_uFrameDuration,
      &out_uNumBars,
      &out_uNumBeats,
      out_uNumGrids);
    v12 = 0;
    if ( (v6 & 0x200) != 0 )
    {
      for ( i = 0; i < out_uNumBars; ++i )
        CAkPlayingMgr::NotifyMusic(g_pPlayingMgr, v10, 0x200u, v11);
    }
    if ( (v6 & 0x100) != 0 )
    {
      for ( j = 0; j < out_uNumBeats; ++j )
        CAkPlayingMgr::NotifyMusic(g_pPlayingMgr, v10, 0x100u, v11);
    }
    if ( (v6 & 0x1000) != 0 && out_uNumGrids[0] )
    {
      do
      {
        CAkPlayingMgr::NotifyMusic(g_pPlayingMgr, v10, 0x1000u, v11);
        ++v12;
      }
      while ( v12 < out_uNumGrids[0] );
    }
    if ( (v6 & 0x800) != 0 )
    {
      active = CAkMusicSegment::ActiveDuration(this->m_pSegment.m_pT->m_pSegmentNode);
      if ( active >= in_iSegmentPosition && active < (int)(in_iSegmentPosition + in_uFrameDuration) )
        CAkPlayingMgr::NotifyMusic(g_pPlayingMgr, v10, 0x800u, v11);
    }
  }
}

// File Line: 524
// RVA: 0xAAB900
void __fastcall CAkMatrixSequencer::CAkMatrixSequencer(
        CAkMatrixSequencer *this,
        CAkMatrixAwareCtx *in_pOwner,
        UserParams *in_rUserparams,
        CAkRegisteredObj *in_pGameObj)
{
  AkExternalSourceArray *pExternalSrcs; // rcx
  AkExternalSourceArray *v7; // rdi

  this->m_pOwner = in_pOwner;
  this->vfptr = (IAkTriggerAwareVtbl *)&CAkMatrixSequencer::`vftable;
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
  pExternalSrcs = this->m_UserParams.m_CustomParam.pExternalSrcs;
  v7 = in_rUserparams->m_CustomParam.pExternalSrcs;
  if ( pExternalSrcs )
    AkExternalSourceArray::Release(pExternalSrcs);
  if ( v7 )
    ++v7->m_cRefCount;
  this->m_UserParams.m_CustomParam.pExternalSrcs = v7;
  this->m_pGameObj = in_pGameObj;
  *((_DWORD *)in_pGameObj + 30) ^= (*((_DWORD *)in_pGameObj + 30) ^ (*((_DWORD *)in_pGameObj + 30) + 1)) & 0x3FFFFFFF;
  CAkStateMgr::RegisterTrigger(g_pStateMgr, this, this->m_pGameObj);
}

// File Line: 534
// RVA: 0xAABA00
void __fastcall CAkMatrixSequencer::~CAkMatrixSequencer(CAkMatrixSequencer *this)
{
  CAkRegisteredObj *m_pGameObj; // rsi
  int v3; // ecx
  int v4; // ebx
  AkExternalSourceArray *pExternalSrcs; // rcx

  this->vfptr = (IAkTriggerAwareVtbl *)&CAkMatrixSequencer::`vftable;
  CAkMatrixSequencer::RemoveAllPendingStingers(this);
  CAkStateMgr::UnregisterTrigger(g_pStateMgr, this);
  m_pGameObj = this->m_pGameObj;
  this->m_listPendingStingers.m_pFirst = 0i64;
  if ( m_pGameObj )
  {
    v3 = *((_DWORD *)m_pGameObj + 30) ^ (*((_DWORD *)m_pGameObj + 30) ^ (*((_DWORD *)m_pGameObj + 30) - 1)) & 0x3FFFFFFF;
    *((_DWORD *)m_pGameObj + 30) = v3;
    if ( (v3 & 0x3FFFFFFF) == 0 )
    {
      v4 = g_DefaultPoolId;
      CAkRegisteredObj::~CAkRegisteredObj(m_pGameObj);
      AK::MemoryMgr::Free(v4, m_pGameObj);
    }
    this->m_pGameObj = 0i64;
  }
  pExternalSrcs = this->m_UserParams.m_CustomParam.pExternalSrcs;
  if ( pExternalSrcs )
    AkExternalSourceArray::Release(pExternalSrcs);
}

// File Line: 562
// RVA: 0xAABCD0
void __fastcall CAkMatrixSequencer::Execute(CAkMatrixSequencer *this, unsigned int in_uNumFrames)
{
  CAkMatrixAwareCtx *m_pOwner; // rcx
  char v4; // al
  __int64 v5; // [rsp+20h] [rbp-18h] BYREF
  char v6; // [rsp+28h] [rbp-10h]

  ++this->m_pOwner->m_uRefCount;
  m_pOwner = this->m_pOwner;
  v4 = *((_BYTE *)&m_pOwner->CAkMusicCtx + 98);
  if ( (v4 & 3) != 0 && (v4 & 0x10) == 0 )
  {
    this->m_uCurTimeWindowSize = in_uNumFrames;
    v5 = 0i64;
    v6 = 0;
    ((void (__fastcall *)(CAkMatrixAwareCtx *, unsigned __int64, _QWORD, __int64 *))m_pOwner->CAkMusicCtx::CAkChildCtx::vfptr[1].SetPBIFade)(
      m_pOwner,
      this->m_uTime,
      in_uNumFrames,
      &v5);
    this->m_uTime += this->m_uCurTimeWindowSize;
  }
  CAkMusicCtx::Release(this->m_pOwner);
}

// File Line: 582
// RVA: 0xAAC600
// attributes: thunk
void __fastcall CAkMatrixSequencer::OnStopped(CAkMatrixSequencer *this)
{
  CAkMatrixSequencer::RemoveAllPendingStingers(this);
}

// File Line: 591
// RVA: 0xAAC7E0
void __fastcall CAkMatrixSequencer::Process(
        CAkMatrixSequencer *this,
        __int64 in_iCurrentTime,
        unsigned int in_uNumSamples)
{
  CAkMatrixSequencer::ProcessStingers(this, in_iCurrentTime, in_uNumSamples);
  CAkMatrixSequencer::ProcessMusicNotifications(this, in_iCurrentTime, in_uNumSamples);
}

// File Line: 630
// RVA: 0xAACF90
void __fastcall CAkMatrixSequencer::RescheduleCancelledActions(
        CAkMatrixSequencer *this,
        AkListBareLight<AkAssociatedAction,AkListBareLightNextItem<AkAssociatedAction> > *in_listActions)
{
  AkAssociatedAction *m_pFirst; // rbx
  AkAssociatedActionType eActionType; // r8d
  AkStingerRecord *pStingerRecord; // rdi
  CAkMatrixAwareCtx *m_pT; // rcx
  unsigned int triggerID; // r12d
  bool bCanBeRescheduled; // r15
  AkStingerRecord *v10; // rax
  AkAssociatedAction *pNextLightItem; // rdi

  m_pFirst = in_listActions->m_pFirst;
  if ( in_listActions->m_pFirst )
  {
    while ( 1 )
    {
      eActionType = m_pFirst->eActionType;
      if ( eActionType )
      {
        if ( eActionType == AssocActionTypeState )
          CAkMusicRenderer::RescheduleDelayedStateChange(
            CAkMusicRenderer::m_pMusicRenderer,
            (CAkMusicRenderer::AkStateChangeRecord *)m_pFirst->pStingerRecord);
      }
      else
      {
        pStingerRecord = m_pFirst->pStingerRecord;
        m_pT = pStingerRecord->pStingerCtx.m_pT;
        triggerID = pStingerRecord->triggerID;
        bCanBeRescheduled = pStingerRecord->bCanBeRescheduled;
        if ( m_pT )
          ((void (__fastcall *)(CAkMatrixAwareCtx *, unsigned __int64))m_pT->CAkMusicCtx::CAkChildCtx::vfptr[2].SetPBIFade)(
            m_pT,
            this->m_uTime - this->m_pOwner->m_iLocalTime);
        v10 = this->m_listPendingStingers.m_pFirst;
        if ( v10 )
        {
          while ( v10 != pStingerRecord )
          {
            v10 = v10->pNextLightItem;
            if ( !v10 )
              goto LABEL_12;
          }
          v10->triggerID = 0;
        }
LABEL_12:
        if ( bCanBeRescheduled )
          CAkMatrixSequencer::HandleTrigger(this, triggerID, 1);
      }
      pNextLightItem = m_pFirst->pNextLightItem;
      if ( m_pFirst == in_listActions->m_pFirst )
        in_listActions->m_pFirst = pNextLightItem;
      else
        MEMORY[0x18] = m_pFirst->pNextLightItem;
      AK::MemoryMgr::Free(g_DefaultPoolId, m_pFirst);
      if ( !pNextLightItem )
        break;
      m_pFirst = pNextLightItem;
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
void __fastcall CAkMatrixSequencer::HandleTrigger(
        CAkMatrixSequencer *this,
        unsigned int in_triggerID,
        bool in_bReschedule)
{
  CAkMatrixAwareCtx *m_pOwner; // rdx
  CAkStinger *m_pItems; // rdi
  int v8; // r13d
  AKRESULT SyncPoint; // r12d
  CAkStinger *v10; // r14
  CAkMusicSegment *Node; // rax
  CAkMusicNode *v12; // rcx
  CAkStinger *v13; // rbx
  CAkStinger *v14; // rax
  CAkMatrixAwareCtx *v15; // rdi
  int v16; // r14d
  AkSyncType m_SyncPlayAt; // r8d
  CAkStinger *v18; // rdx
  CAkMusicNode::CAkStingers io_pStingers; // [rsp+40h] [rbp-C0h] BYREF
  __int64 in_iSyncTime; // [rsp+58h] [rbp-A8h] BYREF
  unsigned __int64 v21; // [rsp+60h] [rbp-A0h]
  CAkMusicNode *out_ppParentNode; // [rsp+68h] [rbp-98h] BYREF
  CAkMusicNode *v23; // [rsp+70h] [rbp-90h] BYREF
  CAkScheduleWindow in_window; // [rsp+80h] [rbp-80h] BYREF
  int out_iLookAheadDuration; // [rsp+1F0h] [rbp+F0h] BYREF
  unsigned int io_uCueFilter; // [rsp+208h] [rbp+108h] BYREF

  m_pOwner = this->m_pOwner;
  v21 = this->m_uTime - m_pOwner->m_iLocalTime;
  CAkScheduleWindow::CAkScheduleWindow(&in_window, m_pOwner, 0);
  if ( !in_window.m_itScheduledItem.pItem )
    goto LABEL_36;
  m_pItems = 0i64;
  v8 = 0;
  if ( in_bReschedule )
  {
    ((void (__fastcall *)(CAkMatrixAwareCtx *, CAkScheduleWindow *, _QWORD))this->m_pOwner->vfptr[1].VirtualRelease)(
      this->m_pOwner,
      &in_window,
      0i64);
    v8 = 1;
  }
  SyncPoint = AK_Fail;
  while ( 1 )
  {
    v10 = m_pItems;
    Node = CAkScheduleWindow::GetNode(&in_window, &out_ppParentNode);
    v12 = out_ppParentNode;
    io_pStingers.m_StingerArray.m_pItems = m_pItems;
    *(_QWORD *)&io_pStingers.m_StingerArray.m_uLength = 0i64;
    if ( Node )
      v12 = Node;
    CAkMusicNode::GetStingers(v12, &io_pStingers);
    m_pItems = io_pStingers.m_StingerArray.m_pItems;
    v13 = io_pStingers.m_StingerArray.m_pItems;
    v14 = &io_pStingers.m_StingerArray.m_pItems[io_pStingers.m_StingerArray.m_uLength];
    if ( io_pStingers.m_StingerArray.m_pItems == v14 )
      goto LABEL_26;
    while ( v13->m_TriggerID != in_triggerID )
    {
      if ( ++v13 == v14 )
        goto LABEL_26;
    }
    if ( !CAkMatrixSequencer::CanPlayStinger(this, in_triggerID) )
      break;
    v15 = CAkMatrixSequencer::CreateStingerCtx(this, v13->m_SegmentID, &out_iLookAheadDuration);
    if ( !v15 && v13->m_SegmentID )
    {
LABEL_31:
      v18 = io_pStingers.m_StingerArray.m_pItems;
      if ( !io_pStingers.m_StingerArray.m_pItems )
        goto LABEL_36;
      goto LABEL_35;
    }
    v16 = out_iLookAheadDuration;
    m_SyncPlayAt = v13->m_SyncPlayAt;
    io_uCueFilter = v13->m_uCueFilterHash;
    SyncPoint = CAkScheduleWindow::FindSyncPoint(
                  &in_window,
                  v21 + out_iLookAheadDuration,
                  m_SyncPlayAt,
                  &io_uCueFilter,
                  0,
                  0,
                  &in_iSyncTime);
    if ( SyncPoint == AK_Success )
    {
      if ( CAkMatrixSequencer::ScheduleStingerForPlayback(this, &in_window, v15, v13, in_iSyncTime, v16, v8 == 0) != AK_Success )
        goto LABEL_31;
      if ( v15 )
        CAkMatrixAwareCtx::GetFirstSegmentNode(v15, &v23);
    }
    else
    {
      if ( v15 )
        UFG::OnUnloadClass<UITest::HandleArrayTest>(v15);
      if ( in_window.m_bIsDurationInfinite || v13->m_numSegmentLookAhead != 1 || v8 )
      {
        SyncPoint = AK_Success;
      }
      else
      {
        ((void (__fastcall *)(CAkMatrixAwareCtx *, CAkScheduleWindow *, _QWORD))this->m_pOwner->vfptr[1].VirtualRelease)(
          this->m_pOwner,
          &in_window,
          0i64);
        v8 = 1;
      }
    }
    m_pItems = io_pStingers.m_StingerArray.m_pItems;
    v10 = v13;
LABEL_26:
    if ( m_pItems )
    {
      io_pStingers.m_StingerArray.m_uLength = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
      m_pItems = 0i64;
      io_pStingers.m_StingerArray.m_pItems = 0i64;
      io_pStingers.m_StingerArray.m_ulReserved = 0;
    }
    if ( SyncPoint == AK_Success || !v10 )
      goto LABEL_36;
  }
  if ( !m_pItems )
    goto LABEL_36;
  v18 = m_pItems;
LABEL_35:
  io_pStingers.m_StingerArray.m_uLength = 0;
  AK::MemoryMgr::Free(g_DefaultPoolId, v18);
LABEL_36:
  _((AMD_HD3D *)&in_window);
}

// File Line: 900
// RVA: 0xAAD0C0
__int64 __fastcall CAkMatrixSequencer::ScheduleStingerForPlayback(
        CAkMatrixSequencer *this,
        CAkScheduleWindow *in_window,
        CAkMatrixAwareCtx *in_pStingerCtx,
        CAkStinger *in_pStingerData,
        __int64 in_iSyncTime,
        int in_iLookAheadDuration,
        bool in_bScheduledInCurrentSegment)
{
  AkStingerRecord *v11; // rax
  AkStingerRecord *v12; // rdi
  AkAssociatedAction *v13; // rsi
  CAkMusicCtx *v14; // rcx
  int v15; // ebx
  CAkMusicCtx *v16; // rcx
  unsigned int m_SegmentID; // eax
  unsigned int v19; // edx
  CAkMusicCtx *m_pT; // rcx
  CAkMusicSegment *FirstSegmentNode; // rax
  CAkMusicSegment *v22; // r14
  unsigned int active; // ebx
  char v24; // al
  AkStingerRecord *m_pFirst; // rax
  __int64 v26; // rax
  __int64 v27; // rax
  CAkScheduledItem *pItem; // rax
  AkAssociatedAction *v29; // rcx

  v11 = (AkStingerRecord *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x30ui64);
  v12 = v11;
  if ( !v11 )
    return 2i64;
  v11->pStingerCtx.m_pT = 0i64;
  v13 = (AkAssociatedAction *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x20ui64);
  if ( v13 )
  {
    v12->triggerID = in_pStingerData->m_TriggerID;
    m_SegmentID = in_pStingerData->m_SegmentID;
    v12->iSyncTime = in_iSyncTime;
    v12->segmentID = m_SegmentID;
    v19 = in_pStingerData->m_DontRepeatTime * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
    v12->iLookAheadDuration = in_iLookAheadDuration;
    v12->uDontRepeatTime = v19;
    if ( in_pStingerCtx )
    {
      ++in_pStingerCtx->m_uRefCount;
      in_pStingerCtx->m_iLocalTime = in_iSyncTime;
      m_pT = v12->pStingerCtx.m_pT;
      v12->pStingerCtx.m_pT = in_pStingerCtx;
      if ( m_pT )
        CAkMusicCtx::Release(m_pT);
      FirstSegmentNode = CAkMatrixAwareCtx::GetFirstSegmentNode(in_pStingerCtx, 0i64);
      v22 = FirstSegmentNode;
      if ( FirstSegmentNode )
      {
        active = CAkMusicSegment::ActiveDuration(FirstSegmentNode);
        v12->iRelativeStopTime = CAkMusicSegment::PostExitDuration(v22) + active;
      }
      else
      {
        v12->iRelativeStopTime = 0;
      }
    }
    if ( !in_bScheduledInCurrentSegment || (v24 = 1, !in_pStingerData->m_numSegmentLookAhead) )
      v24 = 0;
    v12->bCanBeRescheduled = v24;
    m_pFirst = this->m_listPendingStingers.m_pFirst;
    if ( m_pFirst )
    {
      v12->pNextLightItem = m_pFirst;
      this->m_listPendingStingers.m_pFirst = v12;
    }
    else
    {
      this->m_listPendingStingers.m_pFirst = v12;
      v12->pNextLightItem = 0i64;
    }
    v13->eActionType = AssocActionTypeStinger;
    v26 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(in_window, 0);
    v27 = AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(
            &in_window->m_itScheduledItem,
            in_iSyncTime - v26);
    v13->pStingerRecord = v12;
    v13->iRelativeTime = v27;
    pItem = in_window->m_itScheduledItem.pItem;
    v29 = pItem->m_listAssociatedActions.m_pFirst;
    if ( v29 )
    {
      v13->pNextLightItem = v29;
      pItem->m_listAssociatedActions.m_pFirst = v13;
    }
    else
    {
      pItem->m_listAssociatedActions.m_pFirst = v13;
      v13->pNextLightItem = 0i64;
    }
    return 1i64;
  }
  else
  {
    v14 = v12->pStingerCtx.m_pT;
    v15 = g_DefaultPoolId;
    v12->pStingerCtx.m_pT = 0i64;
    if ( v14 )
      CAkMusicCtx::Release(v14);
    v16 = v12->pStingerCtx.m_pT;
    if ( v16 )
    {
      CAkMusicCtx::Release(v16);
      v12->pStingerCtx.m_pT = 0i64;
    }
    AK::MemoryMgr::Free(v15, v12);
    return 2i64;
  }
}

// File Line: 960
// RVA: 0xAABBB0
CAkMatrixAwareCtx *__fastcall CAkMatrixSequencer::CreateStingerCtx(
        CAkMatrixSequencer *this,
        unsigned int in_segmentID,
        int *out_iLookAheadDuration)
{
  CAkParameterNodeBase *NodePtrAndAddRef; // rax
  CAkParameterNodeBase *v6; // rbx
  _QWORD *v7; // rax
  _QWORD *v8; // rdi
  __int64 v9; // rax
  CAkMatrixAwareCtx *result; // rax
  int v11; // [rsp+30h] [rbp-28h] BYREF
  __int64 v12; // [rsp+38h] [rbp-20h]
  int v13; // [rsp+40h] [rbp-18h]
  __int16 v14; // [rsp+44h] [rbp-14h]
  char v15; // [rsp+78h] [rbp+20h] BYREF

  NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_segmentID, AkNodeType_Default);
  v6 = NodePtrAndAddRef;
  if ( NodePtrAndAddRef )
  {
    v7 = (_QWORD *)((__int64 (__fastcall *)(CAkParameterNodeBase *, CAkMatrixAwareCtx *, CAkRegisteredObj *, UserParams *))NodePtrAndAddRef->vfptr[21].__vecDelDtor)(
                     NodePtrAndAddRef,
                     this->m_pOwner,
                     this->m_pGameObj,
                     &this->m_UserParams);
    v8 = v7;
    if ( v7 )
    {
      v9 = *v7;
      v12 = 0i64;
      v11 = 0;
      v14 = v14 & 0xFFE0 | 8;
      v13 = 0;
      *out_iLookAheadDuration = (*(__int64 (__fastcall **)(_QWORD *, int *, _QWORD, _QWORD, char *, _DWORD))(v9 + 88))(
                                  v8,
                                  &v11,
                                  0i64,
                                  0i64,
                                  &v15,
                                  0);
    }
    v6->vfptr->Release(v6);
    return (CAkMatrixAwareCtx *)v8;
  }
  else
  {
    result = 0i64;
    *out_iLookAheadDuration = 0;
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
void __fastcall CAkMatrixSequencer::ProcessStingers(
        CAkMatrixSequencer *this,
        __int64 in_iCurrentTime,
        CAkTransition **in_uFrameDuration)
{
  AkStingerRecord *m_pFirst; // rbx
  unsigned int v4; // r15d
  __int64 v7; // r14
  AkStingerRecord *v8; // r9
  CAkMusicCtx *m_pT; // rcx
  __int64 v10; // rdx
  __int64 v11; // rax
  CAkMusicCtx *v12; // rcx
  CAkMatrixAwareCtx *v13; // rcx
  char v14; // al
  __int64 iSyncTime; // rax
  CAkMatrixAwareCtx *v16; // rax
  CAkMusicCtx *v17; // rcx
  AkStingerRecord *pNextLightItem; // rax
  CAkMusicCtx *v19; // rcx
  int v20; // esi
  CAkMusicCtx *v21; // rcx
  AkMusicFade in_fadeParams; // [rsp+20h] [rbp-68h] BYREF
  __int64 v23; // [rsp+30h] [rbp-58h] BYREF
  char v24; // [rsp+38h] [rbp-50h]
  __int128 v25; // [rsp+40h] [rbp-48h]
  __int128 v26; // [rsp+50h] [rbp-38h]
  TransParams in_transParams; // [rsp+90h] [rbp+8h] BYREF

  m_pFirst = this->m_listPendingStingers.m_pFirst;
  v4 = (unsigned int)in_uFrameDuration;
  v7 = in_iCurrentTime + (unsigned int)in_uFrameDuration;
  v8 = 0i64;
  while ( m_pFirst )
  {
    m_pT = m_pFirst->pStingerCtx.m_pT;
    if ( m_pT )
    {
      v10 = m_pFirst->iSyncTime - m_pFirst->iLookAheadDuration;
      if ( v7 > v10 )
      {
        if ( in_iCurrentTime <= v10 )
        {
          in_fadeParams.iFadeOffset = 0;
          in_fadeParams.transitionTime = 0;
          CAkMusicCtx::_Play(m_pT, &in_fadeParams, in_uFrameDuration);
        }
        v11 = m_pFirst->iSyncTime + m_pFirst->iRelativeStopTime;
        if ( in_iCurrentTime <= v11 && v7 > v11 )
        {
          v12 = m_pFirst->pStingerCtx.m_pT;
          in_transParams.TransitionTime = 0;
          CAkMusicCtx::_Stop(v12, &in_transParams, (CAkTransition **)(unsigned int)(v11 - in_iCurrentTime));
        }
        v13 = m_pFirst->pStingerCtx.m_pT;
        v14 = *((_BYTE *)&v13->CAkMusicCtx + 98);
        if ( (v14 & 3) != 0 && (v14 & 0x10) == 0 )
        {
          iSyncTime = m_pFirst->iSyncTime;
          v24 = 1;
          v23 = iSyncTime + 1;
          ((void (__fastcall *)(CAkMatrixAwareCtx *, __int64, _QWORD, __int64 *))v13->CAkMusicCtx::CAkChildCtx::vfptr[1].SetPBIFade)(
            v13,
            in_iCurrentTime,
            v4,
            &v23);
          v16 = m_pFirst->pStingerCtx.m_pT;
          if ( (*((_BYTE *)&v16->CAkMusicCtx + 98) & 0xFu) > 1 )
          {
            v17 = m_pFirst->pStingerCtx.m_pT;
            m_pFirst->pStingerCtx.m_pT = 0i64;
            if ( v16 )
              CAkMusicCtx::Release(v17);
          }
        }
      }
    }
    else if ( in_iCurrentTime > m_pFirst->iSyncTime + m_pFirst->uDontRepeatTime )
    {
      pNextLightItem = m_pFirst->pNextLightItem;
      *((_QWORD *)&v25 + 1) = v8;
      *(_QWORD *)&v25 = pNextLightItem;
      if ( m_pFirst == this->m_listPendingStingers.m_pFirst )
        this->m_listPendingStingers.m_pFirst = pNextLightItem;
      else
        v8->pNextLightItem = pNextLightItem;
      v19 = m_pFirst->pStingerCtx.m_pT;
      v20 = g_DefaultPoolId;
      v26 = v25;
      m_pFirst->pStingerCtx.m_pT = 0i64;
      if ( v19 )
        CAkMusicCtx::Release(v19);
      v21 = m_pFirst->pStingerCtx.m_pT;
      if ( v21 )
      {
        CAkMusicCtx::Release(v21);
        m_pFirst->pStingerCtx.m_pT = 0i64;
      }
      AK::MemoryMgr::Free(v20, m_pFirst);
      v8 = (AkStingerRecord *)*((_QWORD *)&v26 + 1);
      m_pFirst = (AkStingerRecord *)v26;
      continue;
    }
    v8 = m_pFirst;
    m_pFirst = m_pFirst->pNextLightItem;
  }
}

// File Line: 1091
// RVA: 0xAACED0
void __fastcall CAkMatrixSequencer::RemoveAllPendingStingers(CAkMatrixSequencer *this)
{
  AkStingerRecord *m_pFirst; // rbx
  __int128 v3; // rax
  CAkMusicCtx *m_pT; // rcx
  int v5; // esi
  CAkMusicCtx *v6; // rcx
  __int128 v7; // [rsp+20h] [rbp-28h]

  m_pFirst = this->m_listPendingStingers.m_pFirst;
  *((_QWORD *)&v3 + 1) = 0i64;
  if ( m_pFirst )
  {
    while ( 1 )
    {
      *(_QWORD *)&v3 = m_pFirst->pNextLightItem;
      v7 = v3;
      if ( m_pFirst == this->m_listPendingStingers.m_pFirst )
        this->m_listPendingStingers.m_pFirst = (AkStingerRecord *)v3;
      else
        **((_QWORD **)&v3 + 1) = v3;
      m_pT = m_pFirst->pStingerCtx.m_pT;
      v5 = g_DefaultPoolId;
      m_pFirst->pStingerCtx.m_pT = 0i64;
      if ( m_pT )
        CAkMusicCtx::Release(m_pT);
      v6 = m_pFirst->pStingerCtx.m_pT;
      if ( v6 )
      {
        CAkMusicCtx::Release(v6);
        m_pFirst->pStingerCtx.m_pT = 0i64;
      }
      AK::MemoryMgr::Free(v5, m_pFirst);
      if ( !this->m_listPendingStingers.m_pFirst )
        break;
      *((_QWORD *)&v3 + 1) = *((_QWORD *)&v7 + 1);
      m_pFirst = (AkStingerRecord *)v7;
    }
  }
}

// File Line: 1133
// RVA: 0xAACD60
unsigned __int64 __fastcall CAkMatrixSequencer::QueryStateChangeDelay(
        CAkMatrixSequencer *this,
        unsigned int in_stateGroupID,
        unsigned int *out_uSegmentLookAhead,
        __int64 *out_iSyncTime)
{
  CAkMatrixAwareCtx *m_pOwner; // rdx
  unsigned __int64 v6; // r14
  unsigned __int64 v10; // rbx
  CAkSegmentCtx *m_pT; // rbp
  int v12; // edi
  int EarliestStateSyncTime; // eax
  CAkSegmentCtx *v14; // rcx
  __int64 started; // rbx
  int v16; // eax
  CAkScheduleWindow in_window; // [rsp+20h] [rbp-158h] BYREF

  m_pOwner = this->m_pOwner;
  v6 = this->m_uTime - m_pOwner->m_iLocalTime;
  CAkScheduleWindow::CAkScheduleWindow(&in_window, m_pOwner, 0);
  v10 = 0i64;
  if ( !in_window.m_itScheduledItem.pItem )
    goto LABEL_21;
  m_pT = in_window.m_itScheduledItem.pItem->m_pSegment.m_pT;
  v12 = 3;
  *out_uSegmentLookAhead = 0;
  if ( m_pT && (*((_BYTE *)&m_pT->CAkMusicCtx + 98) & 1) != 0 )
  {
    EarliestStateSyncTime = CAkMatrixSequencer::GetEarliestStateSyncTime(
                              this,
                              &in_window,
                              in_stateGroupID,
                              out_iSyncTime);
    v12 = EarliestStateSyncTime;
    if ( EarliestStateSyncTime == 2 )
      goto LABEL_21;
    if ( !EarliestStateSyncTime )
      goto LABEL_19;
  }
  if ( in_window.m_bIsDurationInfinite )
    goto LABEL_21;
  ((void (__fastcall *)(CAkMatrixAwareCtx *, CAkScheduleWindow *, _QWORD))this->m_pOwner->vfptr[1].VirtualRelease)(
    this->m_pOwner,
    &in_window,
    0i64);
  v14 = in_window.m_itScheduledItem.pItem->m_pSegment.m_pT;
  if ( v14 )
  {
    if ( v12 == 3 && (*((_BYTE *)&v14->CAkMusicCtx + 98) & 1) == 0 )
      goto LABEL_21;
    *out_uSegmentLookAhead = 1;
    v16 = CAkMatrixSequencer::GetEarliestStateSyncTime(this, &in_window, in_stateGroupID, out_iSyncTime);
    if ( v16 )
    {
      if ( v16 != 1 && (unsigned int)(v16 - 2) <= 1 && v12 != 3 )
        goto LABEL_11;
      goto LABEL_21;
    }
LABEL_19:
    started = *out_iSyncTime;
    goto LABEL_20;
  }
  if ( v12 == 1 && m_pT && (*((_BYTE *)&m_pT->CAkMusicCtx + 98) & 1) != 0 )
  {
LABEL_11:
    started = CAkScheduleWindow::StartTime(&in_window);
    *out_iSyncTime = started;
LABEL_20:
    v10 = started - v6;
  }
LABEL_21:
  _((AMD_HD3D *)&in_window);
  return v10;
}

// File Line: 1252
// RVA: 0xAAC9A0
__int64 __fastcall CAkMatrixSequencer::ProcessDelayedStateChange(
        CAkMatrixSequencer *this,
        AkStingerRecord *in_pCookie,
        unsigned int in_uSegmentLookAhead,
        __int64 in_iSyncTime)
{
  AkAssociatedAction *v8; // rax
  AkAssociatedAction *v9; // rbx
  unsigned int v10; // edi
  __int64 v11; // rax
  __int64 v12; // rax
  CAkScheduledItem *pItem; // rax
  AkAssociatedAction *m_pFirst; // rcx
  CAkScheduleWindow v16; // [rsp+20h] [rbp-138h] BYREF

  CAkScheduleWindow::CAkScheduleWindow(&v16, this->m_pOwner, 0);
  if ( !v16.m_itScheduledItem.pItem )
    goto LABEL_8;
  for ( ; in_uSegmentLookAhead; --in_uSegmentLookAhead )
    ((void (__fastcall *)(CAkMatrixAwareCtx *, CAkScheduleWindow *, _QWORD))this->m_pOwner->vfptr[1].VirtualRelease)(
      this->m_pOwner,
      &v16,
      0i64);
  v8 = (AkAssociatedAction *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x20ui64);
  v9 = v8;
  if ( v8 )
  {
    v10 = 1;
    v8->eActionType = AssocActionTypeState;
    v11 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(&v16, 0);
    v12 = AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(&v16.m_itScheduledItem, in_iSyncTime - v11);
    v9->pStingerRecord = in_pCookie;
    v9->iRelativeTime = v12;
    pItem = v16.m_itScheduledItem.pItem;
    m_pFirst = v16.m_itScheduledItem.pItem->m_listAssociatedActions.m_pFirst;
    if ( m_pFirst )
    {
      v9->pNextLightItem = m_pFirst;
      pItem->m_listAssociatedActions.m_pFirst = v9;
    }
    else
    {
      v16.m_itScheduledItem.pItem->m_listAssociatedActions.m_pFirst = v9;
      v9->pNextLightItem = 0i64;
    }
  }
  else
  {
LABEL_8:
    v10 = 2;
  }
  _((AMD_HD3D *)&v16);
  return v10;
}

// File Line: 1299
// RVA: 0xAABDA0
__int64 __fastcall CAkMatrixSequencer::GetEarliestStateSyncTime(
        CAkMatrixSequencer *this,
        CAkScheduleWindow *in_window,
        unsigned int in_stateGroupID,
        __int64 *out_iSyncTime)
{
  CAkMusicSegment *Node; // rax
  AkSyncType *m_pItems; // rdx
  AkSyncType *v10; // rbx
  unsigned int v11; // edi
  CAkMatrixAwareCtx *m_pOwner; // rax
  unsigned __int64 m_uTime; // rdx
  AkSyncType v14; // r8d
  __int64 v16; // [rsp+40h] [rbp-38h] BYREF
  CAkParameterNodeBase::CAkStateSyncArray io_pSyncTypes; // [rsp+48h] [rbp-30h] BYREF
  unsigned int io_uCueFilter; // [rsp+98h] [rbp+20h] BYREF

  *out_iSyncTime = 0i64;
  io_pSyncTypes.m_StateSyncArray.m_pItems = 0i64;
  *(_QWORD *)&io_pSyncTypes.m_StateSyncArray.m_uLength = 0i64;
  Node = CAkScheduleWindow::GetNode(in_window, 0i64);
  CAkMusicSegment::GetStateSyncTypes(Node, in_stateGroupID, &io_pSyncTypes);
  m_pItems = io_pSyncTypes.m_StateSyncArray.m_pItems;
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
          m_pOwner = this->m_pOwner;
          m_uTime = this->m_uTime;
          v14 = *v10;
          io_uCueFilter = 0;
          if ( CAkScheduleWindow::FindSyncPoint(
                 in_window,
                 m_uTime - m_pOwner->m_iLocalTime,
                 v14,
                 &io_uCueFilter,
                 0,
                 0,
                 &v16) == AK_Success
            && (v11 == 1 || v16 < *out_iSyncTime) )
          {
            *out_iSyncTime = v16;
            v11 = 0;
          }
          m_pItems = io_pSyncTypes.m_StateSyncArray.m_pItems;
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
  if ( m_pItems )
  {
    io_pSyncTypes.m_StateSyncArray.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
  }
  return v11;
}

// File Line: 1369
// RVA: 0xAACAA0
void __fastcall CAkMatrixSequencer::ProcessMusicNotifications(
        CAkMatrixSequencer *this,
        __int64 in_iCurrentTime,
        unsigned int in_uFrameDuration)
{
  unsigned __int64 v5; // rbp
  unsigned int v6; // r14d
  __int64 v7; // rax
  __int64 v8; // rax
  unsigned __int64 v9; // rcx
  CAkScheduleWindow v10; // [rsp+30h] [rbp-138h] BYREF

  v5 = in_uFrameDuration;
  CAkScheduleWindow::CAkScheduleWindow(&v10, this->m_pOwner, 0);
  if ( v10.m_itScheduledItem.pItem )
  {
    v6 = this->m_pOwner->m_uRegisteredNotif & 0xFF00;
    CAkScheduleWindow::NotifyMusicCallbacks(&v10, in_iCurrentTime, v5, v6, this->m_UserParams.m_PlayingID);
    while ( !v10.m_bIsDurationInfinite )
    {
      v7 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(&v10, 0);
      v8 = AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(&v10.m_itScheduledItem, in_iCurrentTime - v7);
      if ( v8 >= (__int64)v10.m_uWindowDuration )
        v9 = 0i64;
      else
        v9 = v10.m_uWindowDuration - v8;
      if ( v9 >= v5 )
        break;
      ((void (__fastcall *)(CAkMatrixAwareCtx *, CAkScheduleWindow *, _QWORD))this->m_pOwner->vfptr[1].VirtualRelease)(
        this->m_pOwner,
        &v10,
        0i64);
      CAkScheduleWindow::NotifyMusicCallbacks(&v10, in_iCurrentTime, v5, v6, this->m_UserParams.m_PlayingID);
    }
  }
  _((AMD_HD3D *)&v10);
}

