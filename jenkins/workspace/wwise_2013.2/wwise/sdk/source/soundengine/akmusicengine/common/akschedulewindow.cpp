// File Line: 29
// RVA: 0xAAF5D0
void __fastcall CAkScheduleWindow::CAkScheduleWindow(CAkScheduleWindow *this, bool in_bFirstItemOnly)
{
  this->m_arBranchStack.m_uSize = 0;
  this->m_itScheduledItem.pCtx = 0i64;
  this->m_itScheduledItem.pItem = 0i64;
  this->m_uLevel = 0;
  this->m_uWindowDuration = 0i64;
  this->m_bIsActiveSegment = 0;
  *(_WORD *)&this->m_bIsDurationInfinite = 1;
  this->m_bFirstItemOnly = in_bFirstItemOnly;
}

// File Line: 42
// RVA: 0xAAF550
void __fastcall CAkScheduleWindow::CAkScheduleWindow(CAkScheduleWindow *this, CAkMatrixAwareCtx *in_pCreatorCtx, bool in_bFirstItemOnly)
{
  bool v3; // bl
  CAkScheduleWindow *v4; // rdi

  v3 = in_bFirstItemOnly;
  this->m_arBranchStack.m_uSize = 0;
  this->m_itScheduledItem.pCtx = 0i64;
  this->m_itScheduledItem.pItem = 0i64;
  this->m_uLevel = 0;
  this->m_uWindowDuration = 0i64;
  *(_WORD *)&this->m_bIsDurationInfinite = 1;
  this->m_bIsActiveSegment = 0;
  this->m_bFirstItemOnly = in_bFirstItemOnly;
  v4 = this;
  ((void (__fastcall *)(CAkMatrixAwareCtx *, CAkScheduleWindow *, _QWORD))in_pCreatorCtx->vfptr[1].VirtualRelease)(
    in_pCreatorCtx,
    this,
    0i64);
  v4->m_bIsActiveSegment = v3 == 0;
}

// File Line: 61
// RVA: 0xAAF890
CAkMusicSegment *__fastcall CAkScheduleWindow::GetNode(CAkScheduleWindow *this, CAkMusicNode **out_ppParentNode)
{
  CAkMusicNode **v2; // rbx
  CAkScheduleWindow *v3; // rdi
  CAkSegmentCtx *v4; // rax
  CAkMusicSegment *result; // rax
  __int64 v6; // rax

  v2 = out_ppParentNode;
  v3 = this;
  v4 = this->m_itScheduledItem.pItem->m_pSegment.m_pT;
  if ( v4 )
  {
    result = v4->m_pSegmentNode;
    if ( out_ppParentNode )
      *out_ppParentNode = (CAkMusicNode *)result->m_pParentNode;
  }
  else
  {
    if ( out_ppParentNode )
    {
      v6 = ((__int64 (*)(void))this->m_itScheduledItem.pCtx->vfptr[2].OnPaused)();
      *v2 = (CAkMusicNode *)v6;
      if ( !v6 )
        *v2 = (CAkMusicNode *)((__int64 (*)(void))v3->m_itScheduledItem.pCtx->m_pParentCtx->vfptr[2].OnPaused)();
    }
    result = 0i64;
  }
  return result;
}

// File Line: 92
// RVA: 0xAAFB00
unsigned __int64 __fastcall CAkScheduleWindow::StartTime(CAkScheduleWindow *this)
{
  AkScheduledChain::SelfContainedIter *v1; // rdi
  unsigned __int64 v2; // rbx

  v1 = &this->m_itScheduledItem;
  if ( !this->m_itScheduledItem.pItem )
    return 0x7FFFFFFFFFFFFFFFi64;
  v2 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(this, 0);
  return v2 + AkScheduledChain::SelfContainedIter::GetScheduledItemTime(v1);
}

// File Line: 108
// RVA: 0xAAF710
AKRESULT __fastcall CAkScheduleWindow::FindSyncPoint(CAkScheduleWindow *this, __int64 in_iMinTime, AkSyncType in_eSyncType, unsigned int *io_uCueFilter, bool in_bDoSkipEntryCue, bool in_bSucceedOnNothing, __int64 *out_iSyncTime)
{
  unsigned int *v7; // r12
  AkSyncType v8; // ebp
  __int64 v9; // rdi
  CAkScheduleWindow *v10; // rsi
  unsigned __int64 v11; // r15
  __int64 v12; // r15
  unsigned __int64 v13; // rax
  __int64 v14; // rdx
  CAkSegmentCtx *v15; // rcx
  AKRESULT result; // eax
  AKRESULT v17; // edi
  bool v18; // zf
  unsigned __int64 v19; // rbx
  __int64 v20; // r8
  unsigned int out_uExitSyncPos; // [rsp+60h] [rbp+8h]

  v7 = io_uCueFilter;
  v8 = in_eSyncType;
  v9 = in_iMinTime;
  v10 = this;
  if ( this->m_itScheduledItem.pItem )
  {
    v11 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(this, 0);
    v12 = AkScheduledChain::SelfContainedIter::GetScheduledItemTime(&v10->m_itScheduledItem) + v11;
  }
  else
  {
    v12 = 0x7FFFFFFFFFFFFFFFi64;
  }
  if ( v9 < v12 )
    v9 = v12;
  v13 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(v10, 0);
  v14 = AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(&v10->m_itScheduledItem, v9 - v13);
  v15 = v10->m_itScheduledItem.pItem->m_pSegment.m_pT;
  if ( !v15 || v10->m_bInvalidChain )
  {
    v18 = in_bSucceedOnNothing == 0;
    *v7 = 0;
    if ( v18 && v8 )
      return 2;
    v17 = 1;
  }
  else
  {
    result = CAkMusicSegment::GetExitSyncPos(v15->m_pSegmentNode, v14, v8, v7, in_bDoSkipEntryCue, &out_uExitSyncPos);
    v14 = out_uExitSyncPos;
    v17 = result;
    if ( result != 1 )
      return result;
  }
  v19 = AkScheduledChain::SelfContainedIter::SegmentPositionToCtxTime(&v10->m_itScheduledItem, v14);
  v20 = v19 + CAkScheduleWindow::ChainCtxTimeRelativeToLevel(v10, 0);
  *out_iSyncTime = v20;
  if ( !v10->m_bIsDurationInfinite && v20 > (signed __int64)(v12 + v10->m_uWindowDuration) )
    v17 = 3;
  return v17;
}

// File Line: 180
// RVA: 0xAAF910
bool __fastcall CAkScheduleWindow::IsAtExitCue(CAkScheduleWindow *this, unsigned __int64 in_uTime)
{
  AkScheduledChain::SelfContainedIter *v2; // rbx
  unsigned __int64 v3; // rdi
  unsigned __int64 v5; // rax
  int v6; // eax
  CAkSegmentCtx *v7; // rcx
  CAkMusicSegment *v8; // rcx

  v2 = &this->m_itScheduledItem;
  v3 = in_uTime;
  if ( !this->m_itScheduledItem.pItem->m_pSegment.m_pT )
    return 0;
  v5 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(this, 0);
  v6 = AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(v2, v3 - v5);
  v7 = v2->pItem->m_pSegment.m_pT;
  if ( v7 )
    v8 = v7->m_pSegmentNode;
  else
    v8 = 0i64;
  return v6 == CAkMusicSegment::ActiveDuration(v8);
}

// File Line: 197
// RVA: 0xAAF610
void __fastcall CAkScheduleWindow::CancelActionsAfterTransitionSyncPoint(CAkScheduleWindow *this, AkListBareLight<AkAssociatedAction,AkListBareLightNextItem<AkAssociatedAction> > *io_listCancelledActions, __int64 in_iSyncTime)
{
  AkScheduledChain::SelfContainedIter *v3; // rsi
  __int64 v4; // rdi
  AkListBareLight<AkAssociatedAction,AkListBareLightNextItem<AkAssociatedAction> > *v5; // rbp
  __int64 v6; // rbx
  __int64 v7; // rbx

  v3 = &this->m_itScheduledItem;
  v4 = in_iSyncTime;
  v5 = io_listCancelledActions;
  if ( this->m_itScheduledItem.pItem )
  {
    v6 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(this, 0);
    v7 = AkScheduledChain::SelfContainedIter::GetScheduledItemTime(v3) + v6;
  }
  else
  {
    v7 = 0x7FFFFFFFFFFFFFFFi64;
  }
  CAkScheduledItem::PopAssociatedActionsToRescheduleAfterTransitionSyncPoint(v3->pItem, v5, v4 - v7);
}

// File Line: 211
// RVA: 0xAAF990
void __fastcall CAkScheduleWindow::NotifyMusicCallbacks(CAkScheduleWindow *this, __int64 in_iCurrentTime, unsigned int in_uFrameDuration, unsigned int in_uMusicSyncFlags, unsigned int in_playingID)
{
  AkScheduledChain::SelfContainedIter *v5; // rbx
  unsigned int v6; // esi
  unsigned int v7; // ebp
  __int64 v8; // rdi
  unsigned __int64 v9; // rax
  int v10; // eax

  v5 = &this->m_itScheduledItem;
  v6 = in_uMusicSyncFlags;
  v7 = in_uFrameDuration;
  v8 = in_iCurrentTime;
  if ( this->m_itScheduledItem.pItem->m_pSegment.m_pT )
  {
    v9 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(this, 0);
    v10 = AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(v5, v8 - v9);
    CAkScheduledItem::NotifyMusicCallbacks(v5->pItem, v10, v7, v6, in_playingID);
  }
}

// File Line: 225
// RVA: 0xAAFAB0
void __fastcall CAkScheduleWindow::SetScheduledItem(CAkScheduleWindow *this, AkScheduledChain::SelfContainedIter *in_item)
{
  CAkScheduleWindow *v2; // rdi
  AkScheduledChain::SelfContainedIter *v3; // rbx

  v2 = this;
  v3 = in_item;
  this->m_bInvalidChain = ((unsigned __int8 (*)(void))in_item->pCtx->vfptr[3].OnPaused)() == 0;
  v2->m_itScheduledItem.pItem = v3->pItem;
  v2->m_itScheduledItem.pCtx = v3->pCtx;
  v2->m_bIsActiveSegment = 0;
}

// File Line: 234
// RVA: 0xAAFA00
void __fastcall CAkScheduleWindow::SetBranch(CAkScheduleWindow *this, AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator *in_itTrans)
{
  AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator *v2; // r9
  __int64 v3; // r8
  unsigned int v4; // eax
  __int64 v5; // rdx

  v2 = in_itTrans;
  v3 = this->m_uLevel - 1;
  if ( (_DWORD)v3 == this->m_arBranchStack.m_uSize )
  {
    this->m_itScheduledItem.pCtx = 0i64;
    this->m_itScheduledItem.pItem = 0i64;
    this->m_arBranchStack.m_arBranches[this->m_arBranchStack.m_uSize++] = (AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator)in_itTrans->pItem;
  }
  else if ( this->m_arBranchStack.m_arBranches[v3].pItem != in_itTrans->pItem )
  {
    this->m_itScheduledItem.pCtx = 0i64;
    this->m_itScheduledItem.pItem = 0i64;
    if ( (signed int)(this->m_arBranchStack.m_uSize - 1) >= (signed int)v3 )
    {
      v4 = this->m_arBranchStack.m_uSize;
      v5 = (unsigned int)(this->m_arBranchStack.m_uSize - v3);
      do
      {
        --v4;
        --v5;
      }
      while ( v5 );
      this->m_arBranchStack.m_uSize = v4;
    }
    this->m_arBranchStack.m_arBranches[this->m_arBranchStack.m_uSize++] = (AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator)v2->pItem;
  }
}

// File Line: 263
// RVA: 0xAAF860
AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator __fastcall CAkScheduleWindow::GetBranch(CAkScheduleWindow *this, CAkMusicSwitchTransition *a2)
{
  __int64 v2; // rax
  AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator result; // rax
  CAkMusicSwitchTransition *v4; // rcx

  v2 = this->m_uLevel - 1;
  if ( (_DWORD)v2 == this->m_arBranchStack.m_uSize )
  {
    a2->pNextItem = 0i64;
    result.pItem = a2;
  }
  else
  {
    v4 = this->m_arBranchStack.m_arBranches[v2].pItem;
    result.pItem = a2;
    a2->pNextItem = v4;
  }
  return result;
}

// File Line: 284
// RVA: 0xAAFAA0
void __fastcall CAkScheduleWindow::SetDuration(CAkScheduleWindow *this, unsigned __int64 in_uDuration, bool in_bInfinite)
{
  this->m_uWindowDuration = in_uDuration;
  this->m_bIsDurationInfinite = in_bInfinite;
}

// File Line: 290
// RVA: 0xAAFB50
unsigned __int64 __fastcall CAkScheduleWindow::StartTimeRelativeToCurrentLevel(CAkScheduleWindow *this)
{
  AkScheduledChain::SelfContainedIter *v1; // rdi
  unsigned __int64 v2; // rbx

  v1 = &this->m_itScheduledItem;
  if ( !this->m_itScheduledItem.pItem )
    return 0x7FFFFFFFFFFFFFFFi64;
  v2 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(this, this->m_uLevel - 1);
  return v2 + AkScheduledChain::SelfContainedIter::GetScheduledItemTime(v1);
}

// File Line: 304
// RVA: 0xAAF680
unsigned __int64 __fastcall CAkScheduleWindow::ChainCtxTimeRelativeToLevel(CAkScheduleWindow *this, unsigned int in_uLevel)
{
  unsigned int v2; // esi
  __int64 v3; // r10
  __int64 v4; // rbx
  unsigned __int64 v5; // r8
  __int64 v6; // r9
  unsigned int v7; // eax
  __int64 v8; // rdi
  CAkMusicSwitchTransition *v9; // rax

  v2 = this->m_arBranchStack.m_uSize;
  v3 = 0i64;
  v4 = 0i64;
  v5 = 0i64;
  v6 = in_uLevel;
  if ( in_uLevel >= v2 )
    return 0i64;
  if ( (signed int)(v2 - in_uLevel) >= 2 )
  {
    v7 = ((v2 - in_uLevel - 2) >> 1) + 1;
    v8 = v7;
    in_uLevel += 2 * v7;
    do
    {
      v9 = this->m_arBranchStack.m_arBranches[v6].pItem;
      v6 += 2i64;
      v3 += v9->m_pDestCtx.m_pT->m_iLocalTime;
      v4 += this->m_arBranchStack.m_arBranches[v6 - 1].pItem->m_pDestCtx.m_pT->m_iLocalTime;
      --v8;
    }
    while ( v8 );
  }
  if ( in_uLevel < v2 )
    v5 = this->m_arBranchStack.m_arBranches[v6].pItem->m_pDestCtx.m_pT->m_iLocalTime;
  return v5 + v4 + v3;
}

