// File Line: 24
// RVA: 0xAAEF80
__int64 __fastcall AkScheduledChain::SelfContainedIter::GetScheduledItemTime(AkScheduledChain::SelfContainedIter *this)
{
  __int64 result; // rax

  result = this->pItem->m_iLocalTime - this->pCtx->m_uItemsTimeOffset;
  if ( result < 0 )
    return 0i64;
  return result;
}

// File Line: 38
// RVA: 0xAAECC0
__int64 __fastcall AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(
        AkScheduledChain::SelfContainedIter *this,
        __int64 in_iTime)
{
  return in_iTime + this->pCtx->m_uItemsTimeOffset - this->pItem->m_iLocalTime;
}

// File Line: 47
// RVA: 0xAAF530
__int64 __fastcall AkScheduledChain::SelfContainedIter::SegmentPositionToCtxTime(
        AkScheduledChain::SelfContainedIter *this,
        __int64 in_iSegmentPosition)
{
  return in_iSegmentPosition + this->pItem->m_iLocalTime - this->pCtx->m_uItemsTimeOffset;
}

// File Line: 57
// RVA: 0xAAEAD0
void __fastcall CAkChainCtx::CAkChainCtx(CAkChainCtx *this, CAkMusicCtx *in_parent)
{
  CAkMatrixAwareCtx::CAkMatrixAwareCtx(this, in_parent);
  this->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr = (CAkChildCtxVtbl *)&CAkChainCtx::`vftable{for `CAkChildCtx};
  this->CAkMatrixAwareCtx::CAkMusicCtx::CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkChainCtx::`vftable{for `CAkTransportAware};
  this->CAkMatrixAwareCtx::CAkMusicCtx::ITransitionable::vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable{for `ITransitionable};
  this->m_chain.m_pFirst = 0i64;
  this->m_chain.m_pLast = 0i64;
  this->m_uItemsTimeOffset = 0;
}

// File Line: 61
// RVA: 0xAAEB20
void __fastcall CAkChainCtx::~CAkChainCtx(CAkChainCtx *this)
{
  CAkScheduledItem *m_pFirst; // rcx

  this->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr = (CAkChildCtxVtbl *)&CAkChainCtx::`vftable{for `CAkChildCtx};
  this->CAkMatrixAwareCtx::CAkMusicCtx::CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkChainCtx::`vftable{for `CAkTransportAware};
  this->CAkMatrixAwareCtx::CAkMusicCtx::ITransitionable::vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable{for `ITransitionable};
  while ( this->m_chain.m_pFirst )
  {
    m_pFirst = this->m_chain.m_pFirst;
    if ( m_pFirst )
    {
      if ( m_pFirst->pNextItem )
      {
        this->m_chain.m_pFirst = m_pFirst->pNextItem;
      }
      else
      {
        this->m_chain.m_pFirst = 0i64;
        this->m_chain.m_pLast = 0i64;
      }
    }
    CAkScheduledItem::Destroy(m_pFirst);
  }
  this->m_chain.m_pFirst = 0i64;
  this->m_chain.m_pLast = 0i64;
  CAkMatrixAwareCtx::~CAkMatrixAwareCtx(this);
}

// File Line: 68
// RVA: 0xAAEFA0
__int64 __fastcall CAkChainCtx::GetSegmentPosition(CAkChainCtx *this, CAkScheduledItem *in_pItem)
{
  CAkScheduledItem *i; // rdi
  CAkMatrixAwareCtx *m_pParentCtx; // rcx
  unsigned __int64 m_iLocalTime; // rsi
  unsigned __int64 m_uTime; // rbp
  int v8; // eax
  unsigned int v9; // ebx
  CAkScheduleWindow v11; // [rsp+20h] [rbp-138h] BYREF

  CAkScheduleWindow::CAkScheduleWindow(&v11, this, 1);
  for ( i = v11.m_itScheduledItem.pItem; v11.m_itScheduledItem.pItem != in_pItem; i = v11.m_itScheduledItem.pItem )
    ((void (__fastcall *)(CAkChainCtx *, CAkScheduleWindow *, _QWORD))this->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr[1].VirtualRelease)(
      this,
      &v11,
      0i64);
  m_pParentCtx = (CAkMatrixAwareCtx *)this->m_pParentCtx;
  m_iLocalTime = this->m_iLocalTime;
  m_uTime = this->m_pSequencer->m_uTime;
  if ( m_pParentCtx )
    m_iLocalTime += CAkMatrixAwareCtx::GetAbsoluteTimeOffset(m_pParentCtx);
  if ( i->m_pSegment.m_pT )
  {
    v8 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(&v11, 0);
    v9 = m_uTime
       - m_iLocalTime
       - v8
       + v11.m_itScheduledItem.pCtx->m_uItemsTimeOffset
       - LODWORD(v11.m_itScheduledItem.pItem->m_iLocalTime);
  }
  else
  {
    v9 = 0;
  }
  _((AMD_HD3D *)&v11);
  return v9;
}

// File Line: 81
// RVA: 0xAAF090
void __fastcall CAkChainCtx::OnStopped(CAkChainCtx *this)
{
  ++this->m_uRefCount;
  CAkChainCtx::Flush(this);
  CAkMatrixAwareCtx::OnStopped(this);
  CAkMusicCtx::Release(this);
}

// File Line: 109
// RVA: 0xAAECE0
void __fastcall CAkChainCtx::EnqueueItem(
        CAkChainCtx *this,
        unsigned __int64 in_uTimeOffset,
        CAkSegmentCtx *in_pSegment)
{
  CAkScheduledItem *v6; // rax
  CAkScheduledItem *v7; // rax
  CAkScheduledItem *m_pLast; // rcx

  v6 = (CAkScheduledItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x40ui64);
  if ( v6 )
  {
    CAkScheduledItem::CAkScheduledItem(v6, in_uTimeOffset, in_pSegment);
    if ( v7 )
    {
      v7->pNextItem = 0i64;
      m_pLast = this->m_chain.m_pLast;
      if ( m_pLast )
      {
        m_pLast->pNextItem = v7;
        this->m_chain.m_pLast = v7;
      }
      else
      {
        this->m_chain.m_pLast = v7;
        this->m_chain.m_pFirst = v7;
      }
    }
  }
}

// File Line: 122
// RVA: 0xAAF270
void __fastcall CAkChainCtx::Process(
        CAkChainCtx *this,
        __int64 in_iCurrentTime,
        unsigned int in_uNumSamples,
        AkCutoffInfo *in_cutoffInfo)
{
  unsigned __int64 m_iLocalTime; // rax
  __int64 v7; // rdx
  __int64 m_uItemsTimeOffset; // rcx
  __int64 v10; // r15
  __int64 v11; // rbx
  __int128 m_pFirst; // rdi
  char v13; // r12
  bool v14; // r9
  __int64 v15; // rbx
  CAkScheduledItem *v16; // rax
  __int128 v17; // [rsp+20h] [rbp-58h]
  __int64 v18; // [rsp+80h] [rbp+8h]
  __int64 in_iCurrentTimea; // [rsp+88h] [rbp+10h]

  m_iLocalTime = this->m_iLocalTime;
  in_cutoffInfo->iCutoffTime -= m_iLocalTime;
  ++this->m_uRefCount;
  v7 = in_iCurrentTime - m_iLocalTime;
  in_iCurrentTimea = v7;
  if ( (*((_BYTE *)&this->CAkMusicCtx + 98) & 2) != 0 && this->m_uNumLastSamples != -1 )
    in_uNumSamples = this->m_uNumLastSamples;
  m_uItemsTimeOffset = this->m_uItemsTimeOffset;
  v10 = m_uItemsTimeOffset + v7;
  v11 = m_uItemsTimeOffset + in_cutoffInfo->iCutoffTime;
  v18 = v11;
  ((void (__fastcall *)(CAkChainCtx *, __int64))this->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr[3].SetPBIFade)(
    this,
    m_uItemsTimeOffset + v7);
  m_pFirst = (unsigned __int64)this->m_chain.m_pFirst;
  v13 = 1;
  while ( (_QWORD)m_pFirst )
  {
    v14 = in_cutoffInfo->bCutoff && *(_QWORD *)(m_pFirst + 8) >= v11;
    CAkScheduledItem::Process((CAkScheduledItem *)m_pFirst, v10, (CAkTransition **)in_uNumSamples, v14);
    if ( v13 )
    {
      v15 = *(_QWORD *)m_pFirst;
      if ( CAkScheduledItem::CanDestroy((CAkScheduledItem *)m_pFirst) && v15 && v10 > *(_QWORD *)(v15 + 8) )
      {
        v16 = *(CAkScheduledItem **)m_pFirst;
        *((_QWORD *)&v17 + 1) = *((_QWORD *)&m_pFirst + 1);
        *(_QWORD *)&v17 = *(_QWORD *)m_pFirst;
        if ( (CAkScheduledItem *)m_pFirst == this->m_chain.m_pFirst )
          this->m_chain.m_pFirst = v16;
        else
          **((_QWORD **)&m_pFirst + 1) = v16;
        if ( (CAkScheduledItem *)m_pFirst == this->m_chain.m_pLast )
          this->m_chain.m_pLast = (CAkScheduledItem *)*((_QWORD *)&m_pFirst + 1);
        CAkScheduledItem::Destroy((CAkScheduledItem *)m_pFirst);
        m_pFirst = v17;
        v11 = v18;
        continue;
      }
      v11 = v18;
      v13 = 0;
    }
    *((_QWORD *)&m_pFirst + 1) = m_pFirst;
    *(_QWORD *)&m_pFirst = *(_QWORD *)m_pFirst;
  }
  CAkMatrixAwareCtx::ProcessEpilogue(this, in_iCurrentTimea, in_uNumSamples);
}

// File Line: 175
// RVA: 0xAAEE00
void __fastcall CAkChainCtx::GetNextScheduleWindow(CAkChainCtx *this, CAkScheduleWindow *io_window, bool in_bDoNotGrow)
{
  AkScheduledChain::SelfContainedIter m_itScheduledItem; // xmm0
  CAkScheduledItem *pNextItem; // rax
  CAkScheduledItem *m_pFirst; // r14
  AkScheduledChain::SelfContainedIter v9; // xmm6
  CAkMatrixSequencer *m_pSequencer; // rax
  unsigned __int64 m_iLocalTime; // rbp
  CAkMatrixAwareCtx *m_pParentCtx; // rcx
  unsigned __int64 m_uTime; // rdi
  CAkScheduledItem *v14; // rax
  signed __int64 v15; // rdi
  __int64 m_uItemsTimeOffset; // rdx
  CAkScheduledItem *v17; // rcx
  bool v18; // bp
  unsigned __int64 v19; // rdi
  __int64 v20; // rdx
  __int64 v21; // r9
  __int64 v22; // rax
  AkScheduledChain::SelfContainedIter in_item; // [rsp+20h] [rbp-38h] BYREF

  m_itScheduledItem = io_window->m_itScheduledItem;
  if ( io_window->m_itScheduledItem.pItem )
  {
    in_item = io_window->m_itScheduledItem;
    pNextItem = m_itScheduledItem.pItem->pNextItem;
    in_item.pItem = pNextItem;
    if ( !pNextItem )
    {
      io_window->m_itScheduledItem.pItem = 0i64;
      return;
    }
  }
  else
  {
    m_pFirst = this->m_chain.m_pFirst;
    in_item.pCtx = this;
    in_item.pItem = m_pFirst;
    v9 = in_item;
    if ( !m_pFirst )
      return;
    if ( !io_window->m_bFirstItemOnly )
    {
      m_pSequencer = this->m_pSequencer;
      m_iLocalTime = this->m_iLocalTime;
      m_pParentCtx = (CAkMatrixAwareCtx *)this->m_pParentCtx;
      m_uTime = m_pSequencer->m_uTime;
      if ( m_pParentCtx )
        m_iLocalTime += CAkMatrixAwareCtx::GetAbsoluteTimeOffset(m_pParentCtx);
      v14 = m_pFirst->pNextItem;
      v15 = m_uTime - m_iLocalTime;
      in_item.pItem = v14;
      if ( v14 )
      {
        m_uItemsTimeOffset = this->m_uItemsTimeOffset;
        do
        {
          if ( (signed __int64)(v14->m_iLocalTime - m_uItemsTimeOffset) >= v15 )
            break;
          v14 = v14->pNextItem;
          v9 = in_item;
          in_item.pItem = v14;
        }
        while ( v14 );
      }
      in_item = v9;
    }
    pNextItem = in_item.pItem;
  }
  v17 = pNextItem->pNextItem;
  v18 = 0;
  v19 = 0i64;
  if ( pNextItem->pNextItem )
    goto LABEL_18;
  if ( !in_bDoNotGrow
    && ((unsigned __int8 (__fastcall *)(CAkChainCtx *))this->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr[3].OnResumed)(this) )
  {
    pNextItem = in_item.pItem;
    v17 = in_item.pItem->pNextItem;
LABEL_18:
    v20 = this->m_uItemsTimeOffset;
    v21 = pNextItem->m_iLocalTime - v20;
    if ( v21 < 0 )
      v21 = 0i64;
    v22 = v17->m_iLocalTime - v20;
    if ( v22 < 0 )
      v22 = 0i64;
    v19 = v22 - v21;
    goto LABEL_23;
  }
  v18 = 1;
LABEL_23:
  CAkScheduleWindow::SetScheduledItem(io_window, &in_item);
  CAkScheduleWindow::SetDuration(io_window, v19, v18);
}

// File Line: 263
// RVA: 0xAAF480
void __fastcall CAkChainCtx::RefreshWindow(CAkChainCtx *this, CAkScheduleWindow *io_window)
{
  CAkScheduledItem *pItem; // rbx
  bool v3; // bp
  CAkScheduledItem *pNextItem; // rax
  unsigned __int64 v5; // rdi
  __int64 m_uItemsTimeOffset; // r9
  __int64 v9; // r10
  __int64 v10; // rcx

  pItem = io_window->m_itScheduledItem.pItem;
  v3 = 0;
  pNextItem = pItem->pNextItem;
  v5 = 0i64;
  if ( !pItem->pNextItem )
  {
    if ( !((unsigned __int8 (__fastcall *)(CAkChainCtx *))this->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr[3].OnResumed)(this) )
    {
      v3 = 1;
      goto LABEL_10;
    }
    pNextItem = pItem->pNextItem;
  }
  m_uItemsTimeOffset = this->m_uItemsTimeOffset;
  v9 = pItem->m_iLocalTime - m_uItemsTimeOffset;
  if ( v9 < 0 )
    v9 = 0i64;
  v10 = pNextItem->m_iLocalTime - m_uItemsTimeOffset;
  if ( v10 < 0 )
    v10 = 0i64;
  v5 = v10 - v9;
LABEL_10:
  CAkScheduleWindow::SetDuration(io_window, v5, v3);
}

// File Line: 311
// RVA: 0xAAED80
void __fastcall CAkChainCtx::Flush(CAkChainCtx *this)
{
  CAkScheduledItem *i; // rdi
  CAkScheduledItem *m_pFirst; // rax
  CAkScheduledItem *pNextItem; // rax

  for ( i = this->m_chain.m_pFirst; i; i = this->m_chain.m_pFirst )
  {
    CAkScheduledItem::OnStopped(i);
    m_pFirst = this->m_chain.m_pFirst;
    if ( m_pFirst )
    {
      pNextItem = m_pFirst->pNextItem;
      if ( pNextItem )
      {
        this->m_chain.m_pFirst = pNextItem;
      }
      else
      {
        this->m_chain.m_pFirst = 0i64;
        this->m_chain.m_pLast = 0i64;
      }
    }
    CAkScheduledItem::Destroy(i);
  }
}

// File Line: 346
// RVA: 0xAAF0C0
__int64 __fastcall CAkChainCtx::Prepare(
        CAkChainCtx *this,
        AkMusicTransDestRule *in_pRule,
        int in_iMinStartPosition,
        AkSeekingInfo *in_pSeekingInfo,
        unsigned int *out_uSelectedCue,
        unsigned int in_uCueHashForMatchSrc)
{
  CAkScheduledItem *m_pFirst; // rbx
  unsigned int v7; // edi
  int iSeekPosition; // r14d
  CAkSegmentCtx *m_pT; // rax
  int v12; // ebp
  CAkMusicSegment *m_pSegmentNode; // r12
  __int16 v14; // ax
  bool v15; // al
  int v16; // eax
  int v17; // eax
  CAkChildCtxVtbl *vfptr; // rax
  unsigned int v19; // ecx
  unsigned int v20; // r8d
  int v21; // edx
  CAkScheduledItem *pNextItem; // rax
  int v23; // ecx
  AkMusicFade in_fade; // [rsp+30h] [rbp-38h] BYREF
  unsigned int in_uSyncPosition; // [rsp+70h] [rbp+8h] BYREF

  m_pFirst = this->m_chain.m_pFirst;
  v7 = 0;
  in_uSyncPosition = 0;
  iSeekPosition = in_iMinStartPosition;
  if ( in_pRule )
  {
    m_pT = m_pFirst->m_pSegment.m_pT;
    v12 = 0;
    if ( m_pT )
    {
      m_pSegmentNode = m_pT->m_pSegmentNode;
      if ( in_pSeekingInfo )
      {
        if ( in_pSeekingInfo->bRelative )
          iSeekPosition = (int)(float)((float)(int)CAkMusicSegment::ActiveDuration(m_pT->m_pSegmentNode)
                                     * in_pSeekingInfo->fSeekPercent);
        else
          iSeekPosition = in_pSeekingInfo->iSeekPosition;
      }
      CAkMusicSegment::GetEntrySyncPos(
        m_pSegmentNode,
        in_pRule,
        iSeekPosition,
        in_uCueHashForMatchSrc,
        out_uSelectedCue,
        &in_uSyncPosition);
      v14 = *((_WORD *)in_pRule + 10);
      v7 = in_uSyncPosition;
      v15 = (v14 & 8) != 0 && !in_uSyncPosition && (v14 & 7) != 1;
      v12 = in_uSyncPosition;
      if ( v15 )
      {
        v16 = CAkMusicSegment::PreEntryDuration(m_pSegmentNode);
        v7 = in_uSyncPosition;
        v12 -= v16;
      }
    }
    ((void (__fastcall *)(CAkChainCtx *, _QWORD))this->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr[3].SetPBIFade)(
      this,
      v7);
    v17 = CAkScheduledItem::Prepare(m_pFirst, in_uSyncPosition, v12, &in_pRule->fadeParams);
  }
  else
  {
    vfptr = this->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr;
    v19 = 0;
    if ( in_iMinStartPosition > 0 )
      v19 = in_iMinStartPosition;
    in_uSyncPosition = v19;
    ((void (__fastcall *)(CAkChainCtx *, _QWORD))vfptr[3].SetPBIFade)(this, v19);
    in_fade.transitionTime = 0;
    in_fade.iFadeOffset = 0;
    v17 = CAkScheduledItem::Prepare(m_pFirst, in_uSyncPosition, iSeekPosition, &in_fade);
  }
  v20 = in_uSyncPosition;
  this->m_uItemsTimeOffset = in_uSyncPosition;
  v21 = v17;
  pNextItem = m_pFirst->pNextItem;
  while ( pNextItem )
  {
    v23 = v20 - pNextItem->m_cmdPlay.iRelativeTime - LODWORD(pNextItem->m_iLocalTime);
    pNextItem = pNextItem->pNextItem;
    if ( v23 > v21 )
      v21 = v23;
  }
  return (unsigned int)v21;
}

// File Line: 438
// RVA: 0xAAF3D0
void __fastcall CAkChainCtx::QueryLookAheadInfo(
        CAkChainCtx *this,
        __int64 *out_iPlayTime,
        __int64 *out_iPlayTimeAudible)
{
  CAkScheduledItem *m_pFirst; // rax
  CAkSegmentCtx *m_pT; // r9
  __int64 v7; // r8
  signed __int64 v8; // r9
  CAkScheduledItem *pNextItem; // rax
  CAkSegmentCtx *v10; // r10
  signed __int64 v11; // rcx

  m_pFirst = this->m_chain.m_pFirst;
  m_pT = m_pFirst->m_pSegment.m_pT;
  if ( m_pT )
  {
    v7 = m_pFirst->m_iLocalTime + m_pFirst->m_cmdPlay.iRelativeTime;
    v8 = m_pFirst->m_iLocalTime + m_pT->m_iAudibleTime;
    pNextItem = m_pFirst->pNextItem;
    while ( pNextItem )
    {
      v10 = pNextItem->m_pSegment.m_pT;
      if ( !v10 )
        break;
      if ( (signed __int64)(pNextItem->m_iLocalTime + pNextItem->m_cmdPlay.iRelativeTime) < v7 )
        v7 = pNextItem->m_iLocalTime + pNextItem->m_cmdPlay.iRelativeTime;
      v11 = pNextItem->m_iLocalTime + v10->m_iAudibleTime;
      pNextItem = pNextItem->pNextItem;
      if ( v11 < v8 )
        v8 = v11;
    }
    *out_iPlayTime = v7 - this->m_uItemsTimeOffset;
    *out_iPlayTimeAudible = v8 - this->m_uItemsTimeOffset;
  }
  else
  {
    *out_iPlayTime = 0i64;
    *out_iPlayTimeAudible = 0i64;
  }
}

// File Line: 473
// RVA: 0xAAEC00
char __fastcall CAkChainCtx::CanRestartPlaying(CAkChainCtx *this)
{
  char v1; // al
  CAkScheduledItem *m_pFirst; // rax

  v1 = *((_BYTE *)&this->CAkMusicCtx + 98);
  if ( (v1 & 1) != 0 || (v1 & 0xF) == 0 )
  {
    m_pFirst = this->m_chain.m_pFirst;
    if ( !m_pFirst )
      return 1;
    while ( (*((_BYTE *)m_pFirst + 60) & 4) == 0 )
    {
      m_pFirst = m_pFirst->pNextItem;
      if ( !m_pFirst )
        return 1;
    }
  }
  return 0;
}

// File Line: 494
// RVA: 0xAAEC40
void __fastcall CAkChainCtx::CancelPlayback(CAkChainCtx *this, __int64 in_iCurrentTime)
{
  char v2; // al
  CAkScheduledItem *m_pFirst; // rbx
  __int64 i; // rsi

  v2 = *((_BYTE *)&this->CAkMusicCtx + 98);
  ++this->m_uRefCount;
  if ( (v2 & 0xF) != 0 )
  {
    if ( (v2 & 1) != 0 )
    {
      m_pFirst = this->m_chain.m_pFirst;
      for ( i = in_iCurrentTime + this->m_uItemsTimeOffset - this->m_iLocalTime; m_pFirst; m_pFirst = m_pFirst->pNextItem )
        CAkScheduledItem::CancelPlayback(m_pFirst, i);
    }
    CAkMusicCtx::Release(this);
  }
  else
  {
    ((void (__fastcall *)(CAkChainCtx *, __int64))this->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr[1].OnPaused)(
      this,
      in_iCurrentTime);
    CAkMusicCtx::Release(this);
  }
}

// File Line: 517
// RVA: 0xAAF080
CAkScheduledItem *__fastcall UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(CAkChainCtx *this)
{
  return this->m_chain.m_pLast;
}

