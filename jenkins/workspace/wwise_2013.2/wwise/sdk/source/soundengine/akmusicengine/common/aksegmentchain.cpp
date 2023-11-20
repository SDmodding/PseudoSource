// File Line: 24
// RVA: 0xAAEF80
__int64 __fastcall AkScheduledChain::SelfContainedIter::GetScheduledItemTime(AkScheduledChain::SelfContainedIter *this)
{
  __int64 result; // rax

  result = this->pItem->m_iLocalTime - this->pCtx->m_uItemsTimeOffset;
  if ( result < 0 )
    result = 0i64;
  return result;
}

// File Line: 38
// RVA: 0xAAECC0
unsigned __int64 __fastcall AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(AkScheduledChain::SelfContainedIter *this, __int64 in_iTime)
{
  return in_iTime + this->pCtx->m_uItemsTimeOffset - this->pItem->m_iLocalTime;
}

// File Line: 47
// RVA: 0xAAF530
unsigned __int64 __fastcall AkScheduledChain::SelfContainedIter::SegmentPositionToCtxTime(AkScheduledChain::SelfContainedIter *this, __int64 in_iSegmentPosition)
{
  return in_iSegmentPosition + this->pItem->m_iLocalTime - this->pCtx->m_uItemsTimeOffset;
}

// File Line: 57
// RVA: 0xAAEAD0
void __fastcall CAkChainCtx::CAkChainCtx(CAkChainCtx *this, CAkMusicCtx *in_parent)
{
  CAkChainCtx *v2; // rbx

  v2 = this;
  CAkMatrixAwareCtx::CAkMatrixAwareCtx((CAkMatrixAwareCtx *)&this->vfptr, in_parent);
  v2->vfptr = (CAkChildCtxVtbl *)&CAkChainCtx::`vftable{for `CAkChildCtx};
  v2->vfptr = (CAkTransportAwareVtbl *)&CAkChainCtx::`vftable{for `CAkTransportAware};
  v2->vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable{for `ITransitionable};
  v2->m_chain.m_pFirst = 0i64;
  v2->m_chain.m_pLast = 0i64;
  v2->m_uItemsTimeOffset = 0;
}

// File Line: 61
// RVA: 0xAAEB20
void __fastcall CAkChainCtx::~CAkChainCtx(CAkChainCtx *this)
{
  CAkChainCtx *v1; // rbx
  CAkScheduledItem *v2; // rcx

  v1 = this;
  this->vfptr = (CAkChildCtxVtbl *)&CAkChainCtx::`vftable{for `CAkChildCtx};
  this->vfptr = (CAkTransportAwareVtbl *)&CAkChainCtx::`vftable{for `CAkTransportAware};
  this->vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable{for `ITransitionable};
  while ( v1->m_chain.m_pFirst )
  {
    v2 = v1->m_chain.m_pFirst;
    if ( v2 )
    {
      if ( v2->pNextItem )
      {
        v1->m_chain.m_pFirst = v2->pNextItem;
      }
      else
      {
        v1->m_chain.m_pFirst = 0i64;
        v1->m_chain.m_pLast = 0i64;
      }
    }
    CAkScheduledItem::Destroy(v2);
  }
  v1->m_chain.m_pFirst = 0i64;
  v1->m_chain.m_pLast = 0i64;
  CAkMatrixAwareCtx::~CAkMatrixAwareCtx((CAkMatrixAwareCtx *)&v1->vfptr);
}

// File Line: 68
// RVA: 0xAAEFA0
__int64 __fastcall CAkChainCtx::GetSegmentPosition(CAkChainCtx *this, CAkScheduledItem *in_pItem)
{
  CAkScheduledItem *v2; // rsi
  CAkChainCtx *v3; // rbx
  CAkScheduledItem *i; // rdi
  CAkMatrixAwareCtx *v5; // rcx
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // rbp
  int v8; // eax
  unsigned int v9; // ebx
  CAkScheduleWindow v11; // [rsp+20h] [rbp-138h]

  v2 = in_pItem;
  v3 = this;
  CAkScheduleWindow::CAkScheduleWindow(&v11, (CAkMatrixAwareCtx *)&this->vfptr, 1);
  for ( i = v11.m_itScheduledItem.pItem; v11.m_itScheduledItem.pItem != v2; i = v11.m_itScheduledItem.pItem )
    ((void (__fastcall *)(CAkChainCtx *, CAkScheduleWindow *, _QWORD))v3->vfptr[1].VirtualRelease)(v3, &v11, 0i64);
  v5 = (CAkMatrixAwareCtx *)v3->m_pParentCtx;
  v6 = v3->m_iLocalTime;
  v7 = v3->m_pSequencer->m_uTime;
  if ( v5 )
    v6 += CAkMatrixAwareCtx::GetAbsoluteTimeOffset(v5);
  if ( i->m_pSegment.m_pT )
  {
    v8 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(&v11, 0);
    v9 = v7
       - v6
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
  CAkChainCtx *v1; // rbx

  ++this->m_uRefCount;
  v1 = this;
  CAkChainCtx::Flush(this);
  CAkMatrixAwareCtx::OnStopped((CAkMatrixAwareCtx *)&v1->vfptr);
  CAkMusicCtx::Release((CAkMusicCtx *)&v1->vfptr);
}

// File Line: 109
// RVA: 0xAAECE0
void __fastcall CAkChainCtx::EnqueueItem(CAkChainCtx *this, unsigned __int64 in_uTimeOffset, CAkSegmentCtx *in_pSegment)
{
  CAkChainCtx *v3; // rbx
  __int64 v4; // rsi
  CAkSegmentCtx *v5; // rdi
  CAkScheduledItem *v6; // rax
  CAkScheduledItem *v7; // rax
  CAkScheduledItem *v8; // rcx

  v3 = this;
  v4 = in_uTimeOffset;
  v5 = in_pSegment;
  v6 = (CAkScheduledItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x40ui64);
  if ( v6 )
  {
    CAkScheduledItem::CAkScheduledItem(v6, v4, v5);
    if ( v7 )
    {
      v7->pNextItem = 0i64;
      v8 = v3->m_chain.m_pLast;
      if ( v8 )
      {
        v8->pNextItem = v7;
        v3->m_chain.m_pLast = v7;
      }
      else
      {
        v3->m_chain.m_pLast = v7;
        v3->m_chain.m_pFirst = v7;
      }
    }
  }
}

// File Line: 122
// RVA: 0xAAF270
void __fastcall CAkChainCtx::Process(CAkChainCtx *this, __int64 in_iCurrentTime, unsigned int in_uNumSamples, AkCutoffInfo *in_cutoffInfo)
{
  unsigned __int64 v4; // rax
  AkCutoffInfo *v5; // r13
  unsigned int v6; // ebp
  __int64 v7; // rdx
  unsigned __int64 *v8; // r14
  __int64 v9; // rcx
  __int64 v10; // r15
  __int64 v11; // rbx
  __int128 v12; // di
  char v13; // r12
  bool v14; // r9
  __int64 v15; // rbx
  unsigned __int64 v16; // rax
  __m128i v17; // [rsp+20h] [rbp-58h]
  __int128 v18; // [rsp+30h] [rbp-48h]
  __int64 v19; // [rsp+80h] [rbp+8h]
  __int64 in_iCurrentTimea; // [rsp+88h] [rbp+10h]

  v4 = this->m_iLocalTime;
  v5 = in_cutoffInfo;
  v6 = in_uNumSamples;
  in_cutoffInfo->iCutoffTime -= v4;
  ++this->m_uRefCount;
  v7 = in_iCurrentTime - v4;
  in_iCurrentTimea = v7;
  v8 = (unsigned __int64 *)this;
  if ( *((_BYTE *)&this->0 + 98) & 2 && this->m_uNumLastSamples != -1 )
    v6 = this->m_uNumLastSamples;
  v9 = this->m_uItemsTimeOffset;
  v10 = v9 + v7;
  v11 = v9 + in_cutoffInfo->iCutoffTime;
  v19 = v9 + in_cutoffInfo->iCutoffTime;
  (*(void (__fastcall **)(unsigned __int64 *, __int64))(*v8 + 192))(v8, v9 + v7);
  v12 = v8[16];
  v13 = 1;
  while ( (_QWORD)v12 )
  {
    v14 = v5->bCutoff && *(_QWORD *)(v12 + 8) >= v11;
    CAkScheduledItem::Process((CAkScheduledItem *)v12, v10, v6, v14);
    if ( v13 )
    {
      v15 = *(_QWORD *)v12;
      if ( CAkScheduledItem::CanDestroy((CAkScheduledItem *)v12) && v15 && v10 > *(_QWORD *)(v15 + 8) )
      {
        v16 = *(_QWORD *)v12;
        v17.m128i_i64[1] = *((_QWORD *)&v12 + 1);
        v17.m128i_i64[0] = *(_QWORD *)v12;
        if ( (_QWORD)v12 == v8[16] )
          v8[16] = v16;
        else
          **((_QWORD **)&v12 + 1) = v16;
        if ( (_QWORD)v12 == v8[17] )
          v8[17] = *((_QWORD *)&v12 + 1);
        _mm_store_si128((__m128i *)&v18, v17);
        CAkScheduledItem::Destroy((CAkScheduledItem *)v12);
        v12 = v18;
        v11 = v19;
        continue;
      }
      v11 = v19;
      v13 = 0;
    }
    *((_QWORD *)&v12 + 1) = v12;
    *(_QWORD *)&v12 = *(_QWORD *)v12;
  }
  CAkMatrixAwareCtx::ProcessEpilogue((CAkMatrixAwareCtx *)v8, in_iCurrentTimea, v6);
}

// File Line: 175
// RVA: 0xAAEE00
void __fastcall CAkChainCtx::GetNextScheduleWindow(CAkChainCtx *this, CAkScheduleWindow *io_window, bool in_bDoNotGrow)
{
  __int128 v3; // xmm0
  bool v4; // r15
  CAkScheduleWindow *v5; // rsi
  CAkChainCtx *v6; // rbx
  CAkScheduledItem *v7; // rax
  CAkScheduledItem *v8; // r14
  AkScheduledChain::SelfContainedIter v9; // xmm6
  CAkMatrixSequencer *v10; // rax
  unsigned __int64 v11; // rbp
  CAkMatrixAwareCtx *v12; // rcx
  unsigned __int64 v13; // rdi
  CAkScheduledItem *v14; // rax
  signed __int64 v15; // rdi
  __int64 v16; // rdx
  CAkScheduledItem *v17; // rcx
  bool v18; // bp
  unsigned __int64 v19; // rdi
  __int64 v20; // rdx
  signed __int64 v21; // r9
  signed __int64 v22; // rax
  AkScheduledChain::SelfContainedIter in_item; // [rsp+20h] [rbp-38h]

  v3 = *(_OWORD *)&io_window->m_itScheduledItem.pItem;
  v4 = in_bDoNotGrow;
  v5 = io_window;
  v6 = this;
  if ( (unsigned __int64)*(_OWORD *)&io_window->m_itScheduledItem.pItem )
  {
    in_item = *(AkScheduledChain::SelfContainedIter *)&io_window->m_itScheduledItem.pItem;
    v7 = *(CAkScheduledItem **)v3;
    in_item.pItem = v7;
    if ( !v7 )
    {
      io_window->m_itScheduledItem.pItem = 0i64;
      return;
    }
  }
  else
  {
    v8 = this->m_chain.m_pFirst;
    in_item.pCtx = this;
    in_item.pItem = v8;
    v9 = in_item;
    _mm_store_si128((__m128i *)&in_item, *(__m128i *)&in_item.pItem);
    if ( !v8 )
      return;
    if ( !io_window->m_bFirstItemOnly )
    {
      v10 = this->m_pSequencer;
      v11 = this->m_iLocalTime;
      v12 = (CAkMatrixAwareCtx *)this->m_pParentCtx;
      v13 = v10->m_uTime;
      if ( v12 )
        v11 += CAkMatrixAwareCtx::GetAbsoluteTimeOffset(v12);
      v14 = v8->pNextItem;
      v15 = v13 - v11;
      in_item.pItem = v14;
      if ( v14 )
      {
        v16 = v6->m_uItemsTimeOffset;
        do
        {
          if ( (signed __int64)(v14->m_iLocalTime - v16) >= v15 )
            break;
          v14 = v14->pNextItem;
          v9 = in_item;
          in_item.pItem = v14;
        }
        while ( v14 );
      }
      _mm_store_si128((__m128i *)&in_item, *(__m128i *)&v9.pItem);
    }
    v7 = in_item.pItem;
  }
  v17 = v7->pNextItem;
  v18 = 0;
  v19 = 0i64;
  if ( v7->pNextItem )
    goto LABEL_18;
  if ( !v4 && ((unsigned __int8 (__fastcall *)(CAkChainCtx *))v6->vfptr[3].OnResumed)(v6) )
  {
    v7 = in_item.pItem;
    v17 = in_item.pItem->pNextItem;
LABEL_18:
    v20 = v6->m_uItemsTimeOffset;
    v21 = v7->m_iLocalTime - v20;
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
  CAkScheduleWindow::SetScheduledItem(v5, &in_item);
  CAkScheduleWindow::SetDuration(v5, v19, v18);
}

// File Line: 263
// RVA: 0xAAF480
void __fastcall CAkChainCtx::RefreshWindow(CAkChainCtx *this, CAkScheduleWindow *io_window)
{
  CAkScheduledItem *v2; // rbx
  bool v3; // bp
  CAkChainCtx *v4; // ST28_8
  CAkScheduledItem *v5; // rax
  unsigned __int64 v6; // rdi
  CAkScheduleWindow *v7; // rsi
  CAkChainCtx *v8; // r14
  __int64 v9; // r9
  signed __int64 v10; // r10
  signed __int64 v11; // rcx

  v2 = io_window->m_itScheduledItem.pItem;
  v3 = 0;
  v4 = io_window->m_itScheduledItem.pCtx;
  v5 = v2->pNextItem;
  v6 = 0i64;
  v7 = io_window;
  v8 = this;
  if ( !v2->pNextItem )
  {
    if ( !((unsigned __int8 (*)(void))this->vfptr[3].OnResumed)() )
    {
      v3 = 1;
      goto LABEL_10;
    }
    v5 = v2->pNextItem;
  }
  v9 = v8->m_uItemsTimeOffset;
  v10 = v2->m_iLocalTime - v9;
  if ( v10 < 0 )
    v10 = 0i64;
  v11 = v5->m_iLocalTime - v9;
  if ( v11 < 0 )
    v11 = 0i64;
  v6 = v11 - v10;
LABEL_10:
  CAkScheduleWindow::SetDuration(v7, v6, v3);
}

// File Line: 311
// RVA: 0xAAED80
void __fastcall CAkChainCtx::Flush(CAkChainCtx *this)
{
  CAkScheduledItem *v1; // rdi
  CAkChainCtx *i; // rbx
  CAkScheduledItem *v3; // rax
  CAkScheduledItem *v4; // rax

  v1 = this->m_chain.m_pFirst;
  for ( i = this; v1; v1 = i->m_chain.m_pFirst )
  {
    CAkScheduledItem::OnStopped(v1);
    v3 = i->m_chain.m_pFirst;
    if ( v3 )
    {
      v4 = v3->pNextItem;
      if ( v4 )
      {
        i->m_chain.m_pFirst = v4;
      }
      else
      {
        i->m_chain.m_pFirst = 0i64;
        i->m_chain.m_pLast = 0i64;
      }
    }
    CAkScheduledItem::Destroy(v1);
  }
}

// File Line: 346
// RVA: 0xAAF0C0
__int64 __fastcall CAkChainCtx::Prepare(CAkChainCtx *this, AkMusicTransDestRule *in_pRule, int in_iMinStartPosition, AkSeekingInfo *in_pSeekingInfo, unsigned int *out_uSelectedCue, unsigned int in_uCueHashForMatchSrc)
{
  CAkScheduledItem *v6; // rbx
  unsigned int v7; // edi
  CAkChainCtx *v8; // r15
  int v9; // er14
  AkMusicTransDestRule *v10; // r13
  CAkSegmentCtx *v11; // rax
  int v12; // ebp
  CAkMusicSegment *v13; // r12
  __int16 v14; // ax
  bool v15; // al
  int v16; // eax
  int v17; // eax
  CAkChildCtxVtbl *v18; // rax
  unsigned int v19; // ecx
  unsigned int v20; // er8
  int v21; // edx
  CAkScheduledItem *v22; // rax
  int v23; // ecx
  AkMusicFade in_fade; // [rsp+30h] [rbp-38h]
  unsigned int in_uSyncPosition; // [rsp+70h] [rbp+8h]

  v6 = this->m_chain.m_pFirst;
  v7 = 0;
  v8 = this;
  in_uSyncPosition = 0;
  v9 = in_iMinStartPosition;
  v10 = in_pRule;
  if ( in_pRule )
  {
    v11 = v6->m_pSegment.m_pT;
    v12 = 0;
    if ( v11 )
    {
      v13 = v11->m_pSegmentNode;
      if ( in_pSeekingInfo )
      {
        if ( in_pSeekingInfo->bRelative )
          v9 = (signed int)(float)((float)(signed int)CAkMusicSegment::ActiveDuration(v11->m_pSegmentNode)
                                 * in_pSeekingInfo->fSeekPercent);
        else
          v9 = in_pSeekingInfo->iSeekPosition;
      }
      CAkMusicSegment::GetEntrySyncPos(v13, v10, v9, in_uCueHashForMatchSrc, out_uSelectedCue, &in_uSyncPosition);
      v14 = *((_WORD *)v10 + 10);
      v7 = in_uSyncPosition;
      v15 = v14 & 8 && !in_uSyncPosition && (v14 & 7) != 1;
      v12 = in_uSyncPosition;
      if ( v15 )
      {
        v16 = CAkMusicSegment::PreEntryDuration(v13);
        v7 = in_uSyncPosition;
        v12 -= v16;
      }
    }
    ((void (__fastcall *)(CAkChainCtx *, _QWORD))v8->vfptr[3].SetPBIFade)(v8, v7);
    v17 = CAkScheduledItem::Prepare(v6, in_uSyncPosition, v12, &v10->fadeParams);
  }
  else
  {
    v18 = this->vfptr;
    v19 = 0;
    if ( in_iMinStartPosition > 0 )
      v19 = in_iMinStartPosition;
    in_uSyncPosition = v19;
    ((void (__fastcall *)(CAkChainCtx *, _QWORD))v18[3].SetPBIFade)(v8, v19);
    in_fade.transitionTime = 0;
    in_fade.iFadeOffset = 0;
    v17 = CAkScheduledItem::Prepare(v6, in_uSyncPosition, v9, &in_fade);
  }
  v20 = in_uSyncPosition;
  v8->m_uItemsTimeOffset = in_uSyncPosition;
  v21 = v17;
  v22 = v6->pNextItem;
  if ( v6->pNextItem )
  {
    do
    {
      v23 = v20 - v22->m_cmdPlay.iRelativeTime - LODWORD(v22->m_iLocalTime);
      v22 = v22->pNextItem;
      if ( v23 > v21 )
        v21 = v23;
    }
    while ( v22 );
  }
  return (unsigned int)v21;
}

// File Line: 438
// RVA: 0xAAF3D0
void __fastcall CAkChainCtx::QueryLookAheadInfo(CAkChainCtx *this, __int64 *out_iPlayTime, __int64 *out_iPlayTimeAudible)
{
  CAkScheduledItem *v3; // rax
  __int64 *v4; // rbx
  CAkChainCtx *v5; // r11
  CAkSegmentCtx *v6; // r9
  signed __int64 v7; // r8
  signed __int64 v8; // r9
  CAkScheduledItem *v9; // rax
  CAkSegmentCtx *v10; // r10
  signed __int64 v11; // rcx

  v3 = this->m_chain.m_pFirst;
  v4 = out_iPlayTimeAudible;
  v5 = this;
  v6 = v3->m_pSegment.m_pT;
  if ( v6 )
  {
    v7 = v3->m_iLocalTime + v3->m_cmdPlay.iRelativeTime;
    v8 = v3->m_iLocalTime + v6->m_iAudibleTime;
    v9 = v3->pNextItem;
    while ( v9 )
    {
      v10 = v9->m_pSegment.m_pT;
      if ( !v10 )
        break;
      if ( (signed __int64)(v9->m_iLocalTime + v9->m_cmdPlay.iRelativeTime) < v7 )
        v7 = v9->m_iLocalTime + v9->m_cmdPlay.iRelativeTime;
      v11 = v9->m_iLocalTime + v10->m_iAudibleTime;
      v9 = v9->pNextItem;
      if ( v11 < v8 )
        v8 = v11;
    }
    *out_iPlayTime = v7 - v5->m_uItemsTimeOffset;
    *v4 = v8 - v5->m_uItemsTimeOffset;
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
  CAkScheduledItem *v2; // rax

  v1 = *((_BYTE *)&this->0 + 98);
  if ( v1 & 1 || !(v1 & 0xF) )
  {
    v2 = this->m_chain.m_pFirst;
    if ( !v2 )
      return 1;
    while ( !((*((_BYTE *)v2 + 60) >> 2) & 1) )
    {
      v2 = v2->pNextItem;
      if ( !v2 )
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
  CAkChainCtx *v3; // rdi
  CAkScheduledItem *v4; // rbx
  __int64 i; // rsi

  v2 = *((_BYTE *)&this->0 + 98);
  ++this->m_uRefCount;
  v3 = this;
  if ( v2 & 0xF )
  {
    if ( v2 & 1 )
    {
      v4 = this->m_chain.m_pFirst;
      for ( i = in_iCurrentTime + this->m_uItemsTimeOffset - this->m_iLocalTime; v4; v4 = v4->pNextItem )
        CAkScheduledItem::CancelPlayback(v4, i);
    }
    CAkMusicCtx::Release((CAkMusicCtx *)&v3->vfptr);
  }
  else
  {
    ((void (__fastcall *)(CAkChainCtx *, __int64))this->vfptr[1].OnPaused)(this, in_iCurrentTime);
    CAkMusicCtx::Release((CAkMusicCtx *)&v3->vfptr);
  }
}

// File Line: 517
// RVA: 0xAAF080
CAkScheduledItem *__fastcall UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(CAkChainCtx *this)
{
  return this->m_chain.m_pLast;
}

