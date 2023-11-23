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
void __fastcall CAkScheduleWindow::CAkScheduleWindow(
        CAkScheduleWindow *this,
        CAkMatrixAwareCtx *in_pCreatorCtx,
        bool in_bFirstItemOnly)
{
  this->m_arBranchStack.m_uSize = 0;
  this->m_itScheduledItem.pCtx = 0i64;
  this->m_itScheduledItem.pItem = 0i64;
  this->m_uLevel = 0;
  this->m_uWindowDuration = 0i64;
  *(_WORD *)&this->m_bIsDurationInfinite = 1;
  this->m_bIsActiveSegment = 0;
  this->m_bFirstItemOnly = in_bFirstItemOnly;
  ((void (__fastcall *)(CAkMatrixAwareCtx *, CAkScheduleWindow *, _QWORD))in_pCreatorCtx->CAkMusicCtx::CAkChildCtx::vfptr[1].VirtualRelease)(
    in_pCreatorCtx,
    this,
    0i64);
  this->m_bIsActiveSegment = !in_bFirstItemOnly;
}

// File Line: 61
// RVA: 0xAAF890
CAkMusicSegment *__fastcall CAkScheduleWindow::GetNode(
        CAkScheduleWindow *this,
        CAkParameterNodeBase **out_ppParentNode)
{
  CAkSegmentCtx *m_pT; // rax
  CAkMusicSegment *result; // rax
  CAkMusicNode *v6; // rax

  m_pT = this->m_itScheduledItem.pItem->m_pSegment.m_pT;
  if ( m_pT )
  {
    result = m_pT->m_pSegmentNode;
    if ( out_ppParentNode )
      *out_ppParentNode = result->m_pParentNode;
  }
  else
  {
    if ( out_ppParentNode )
    {
      v6 = (CAkMusicNode *)((__int64 (__fastcall *)(CAkChainCtx *))this->m_itScheduledItem.pCtx->vfptr[2].OnPaused)(this->m_itScheduledItem.pCtx);
      *out_ppParentNode = v6;
      if ( !v6 )
        *out_ppParentNode = (CAkParameterNodeBase *)((__int64 (__fastcall *)(CAkMusicCtx *))this->m_itScheduledItem.pCtx->m_pParentCtx->vfptr[2].OnPaused)(this->m_itScheduledItem.pCtx->m_pParentCtx);
    }
    return 0i64;
  }
  return result;
}

// File Line: 92
// RVA: 0xAAFB00
unsigned __int64 __fastcall CAkScheduleWindow::StartTime(CAkScheduleWindow *this)
{
  AkScheduledChain::SelfContainedIter *p_m_itScheduledItem; // rdi
  unsigned __int64 v2; // rbx

  p_m_itScheduledItem = &this->m_itScheduledItem;
  if ( !this->m_itScheduledItem.pItem )
    return 0x7FFFFFFFFFFFFFFFi64;
  v2 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(this, 0);
  return v2 + AkScheduledChain::SelfContainedIter::GetScheduledItemTime(p_m_itScheduledItem);
}

// File Line: 108
// RVA: 0xAAF710
AKRESULT __fastcall CAkScheduleWindow::FindSyncPoint(
        CAkScheduleWindow *this,
        __int64 in_iMinTime,
        AkSyncType in_eSyncType,
        unsigned int *io_uCueFilter,
        bool in_bDoSkipEntryCue,
        bool in_bSucceedOnNothing,
        __int64 *out_iSyncTime)
{
  unsigned __int64 v11; // r15
  __int64 v12; // r15
  unsigned __int64 v13; // rax
  __int64 v14; // rdx
  CAkSegmentCtx *m_pT; // rcx
  AKRESULT result; // eax
  AKRESULT v17; // edi
  bool v18; // zf
  __int64 v19; // rbx
  signed __int64 v20; // r8
  unsigned int out_uExitSyncPos; // [rsp+60h] [rbp+8h] BYREF

  if ( this->m_itScheduledItem.pItem )
  {
    v11 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(this, 0);
    v12 = AkScheduledChain::SelfContainedIter::GetScheduledItemTime(&this->m_itScheduledItem) + v11;
  }
  else
  {
    v12 = 0x7FFFFFFFFFFFFFFFi64;
  }
  if ( in_iMinTime < v12 )
    in_iMinTime = v12;
  v13 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(this, 0);
  v14 = AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(&this->m_itScheduledItem, in_iMinTime - v13);
  m_pT = this->m_itScheduledItem.pItem->m_pSegment.m_pT;
  if ( !m_pT || this->m_bInvalidChain )
  {
    v18 = !in_bSucceedOnNothing;
    *io_uCueFilter = 0;
    if ( v18 && in_eSyncType )
      return 2;
    v17 = AK_Success;
  }
  else
  {
    result = CAkMusicSegment::GetExitSyncPos(
               m_pT->m_pSegmentNode,
               v14,
               in_eSyncType,
               io_uCueFilter,
               in_bDoSkipEntryCue,
               &out_uExitSyncPos);
    v14 = out_uExitSyncPos;
    v17 = result;
    if ( result != AK_Success )
      return result;
  }
  v19 = AkScheduledChain::SelfContainedIter::SegmentPositionToCtxTime(&this->m_itScheduledItem, v14);
  v20 = v19 + CAkScheduleWindow::ChainCtxTimeRelativeToLevel(this, 0);
  *out_iSyncTime = v20;
  if ( !this->m_bIsDurationInfinite && v20 > (signed __int64)(v12 + this->m_uWindowDuration) )
    return 3;
  return v17;
}

// File Line: 180
// RVA: 0xAAF910
bool __fastcall CAkScheduleWindow::IsAtExitCue(CAkScheduleWindow *this, unsigned __int64 in_uTime)
{
  AkScheduledChain::SelfContainedIter *p_m_itScheduledItem; // rbx
  unsigned __int64 v5; // rax
  int v6; // eax
  CAkSegmentCtx *m_pT; // rcx
  CAkMusicSegment *m_pSegmentNode; // rcx

  p_m_itScheduledItem = &this->m_itScheduledItem;
  if ( !this->m_itScheduledItem.pItem->m_pSegment.m_pT )
    return 0;
  v5 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(this, 0);
  v6 = AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(p_m_itScheduledItem, in_uTime - v5);
  m_pT = p_m_itScheduledItem->pItem->m_pSegment.m_pT;
  if ( m_pT )
    m_pSegmentNode = m_pT->m_pSegmentNode;
  else
    m_pSegmentNode = 0i64;
  return v6 == CAkMusicSegment::ActiveDuration(m_pSegmentNode);
}

// File Line: 197
// RVA: 0xAAF610
void __fastcall CAkScheduleWindow::CancelActionsAfterTransitionSyncPoint(
        CAkScheduleWindow *this,
        AkListBareLight<AkAssociatedAction,AkListBareLightNextItem<AkAssociatedAction> > *io_listCancelledActions,
        __int64 in_iSyncTime)
{
  AkScheduledChain::SelfContainedIter *p_m_itScheduledItem; // rsi
  __int64 v6; // rbx
  __int64 v7; // rbx

  p_m_itScheduledItem = &this->m_itScheduledItem;
  if ( this->m_itScheduledItem.pItem )
  {
    v6 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(this, 0);
    v7 = AkScheduledChain::SelfContainedIter::GetScheduledItemTime(p_m_itScheduledItem) + v6;
  }
  else
  {
    v7 = 0x7FFFFFFFFFFFFFFFi64;
  }
  CAkScheduledItem::PopAssociatedActionsToRescheduleAfterTransitionSyncPoint(
    p_m_itScheduledItem->pItem,
    io_listCancelledActions,
    in_iSyncTime - v7);
}

// File Line: 211
// RVA: 0xAAF990
void __fastcall CAkScheduleWindow::NotifyMusicCallbacks(
        CAkScheduleWindow *this,
        __int64 in_iCurrentTime,
        unsigned int in_uFrameDuration,
        unsigned int in_uMusicSyncFlags,
        unsigned int in_playingID)
{
  AkScheduledChain::SelfContainedIter *p_m_itScheduledItem; // rbx
  unsigned __int64 v9; // rax
  int v10; // eax

  p_m_itScheduledItem = &this->m_itScheduledItem;
  if ( this->m_itScheduledItem.pItem->m_pSegment.m_pT )
  {
    v9 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(this, 0);
    v10 = AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(p_m_itScheduledItem, in_iCurrentTime - v9);
    CAkScheduledItem::NotifyMusicCallbacks(
      p_m_itScheduledItem->pItem,
      v10,
      in_uFrameDuration,
      in_uMusicSyncFlags,
      in_playingID);
  }
}

// File Line: 225
// RVA: 0xAAFAB0
void __fastcall CAkScheduleWindow::SetScheduledItem(
        CAkScheduleWindow *this,
        AkScheduledChain::SelfContainedIter *in_item)
{
  this->m_bInvalidChain = ((unsigned __int8 (__fastcall *)(CAkChainCtx *))in_item->pCtx->vfptr[3].OnPaused)(in_item->pCtx) == 0;
  this->m_itScheduledItem = *in_item;
  this->m_bIsActiveSegment = 0;
}

// File Line: 234
// RVA: 0xAAFA00
void __fastcall CAkScheduleWindow::SetBranch(
        CAkScheduleWindow *this,
        AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator *in_itTrans)
{
  __int64 v3; // r8
  unsigned int m_uSize; // eax
  __int64 v5; // rdx

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
    if ( (signed int)(this->m_arBranchStack.m_uSize - 1) >= (int)v3 )
    {
      m_uSize = this->m_arBranchStack.m_uSize;
      v5 = m_uSize - (unsigned int)v3;
      do
      {
        --m_uSize;
        --v5;
      }
      while ( v5 );
      this->m_arBranchStack.m_uSize = m_uSize;
    }
    this->m_arBranchStack.m_arBranches[this->m_arBranchStack.m_uSize++] = (AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator)in_itTrans->pItem;
  }
}

// File Line: 263
// RVA: 0xAAF860
AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator __fastcall CAkScheduleWindow::GetBranch(
        CAkScheduleWindow *this,
        CAkMusicSwitchTransition *a2)
{
  __int64 v2; // rax
  AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator result; // rax
  CAkMusicSwitchTransition *pItem; // rcx

  v2 = this->m_uLevel - 1;
  if ( (_DWORD)v2 == this->m_arBranchStack.m_uSize )
  {
    a2->pNextItem = 0i64;
    return (AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator)a2;
  }
  else
  {
    pItem = this->m_arBranchStack.m_arBranches[v2].pItem;
    result.pItem = a2;
    a2->pNextItem = pItem;
  }
  return result;
}

// File Line: 284
// RVA: 0xAAFAA0
void __fastcall CAkScheduleWindow::SetDuration(
        CAkScheduleWindow *this,
        unsigned __int64 in_uDuration,
        bool in_bInfinite)
{
  this->m_uWindowDuration = in_uDuration;
  this->m_bIsDurationInfinite = in_bInfinite;
}

// File Line: 290
// RVA: 0xAAFB50
unsigned __int64 __fastcall CAkScheduleWindow::StartTimeRelativeToCurrentLevel(CAkScheduleWindow *this)
{
  AkScheduledChain::SelfContainedIter *p_m_itScheduledItem; // rdi
  unsigned __int64 v2; // rbx

  p_m_itScheduledItem = &this->m_itScheduledItem;
  if ( !this->m_itScheduledItem.pItem )
    return 0x7FFFFFFFFFFFFFFFi64;
  v2 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(this, this->m_uLevel - 1);
  return v2 + AkScheduledChain::SelfContainedIter::GetScheduledItemTime(p_m_itScheduledItem);
}

// File Line: 304
// RVA: 0xAAF680
unsigned __int64 __fastcall CAkScheduleWindow::ChainCtxTimeRelativeToLevel(
        CAkScheduleWindow *this,
        unsigned int in_uLevel)
{
  unsigned int m_uSize; // esi
  __int64 v3; // r10
  __int64 v4; // rbx
  unsigned __int64 m_iLocalTime; // r8
  __int64 v6; // r9
  unsigned int v7; // eax
  __int64 v8; // rdi
  CAkMusicSwitchTransition *pItem; // rax

  m_uSize = this->m_arBranchStack.m_uSize;
  v3 = 0i64;
  v4 = 0i64;
  m_iLocalTime = 0i64;
  v6 = in_uLevel;
  if ( in_uLevel >= m_uSize )
    return 0i64;
  if ( (int)(m_uSize - in_uLevel) >= 2 )
  {
    v7 = ((m_uSize - in_uLevel - 2) >> 1) + 1;
    v8 = v7;
    in_uLevel += 2 * v7;
    do
    {
      pItem = this->m_arBranchStack.m_arBranches[v6].pItem;
      v6 += 2i64;
      v3 += pItem->m_pDestCtx.m_pT->m_iLocalTime;
      v4 += this->m_arBranchStack.m_arBranches[v6 - 1].pItem->m_pDestCtx.m_pT->m_iLocalTime;
      --v8;
    }
    while ( v8 );
  }
  if ( in_uLevel < m_uSize )
    m_iLocalTime = this->m_arBranchStack.m_arBranches[v6].pItem->m_pDestCtx.m_pT->m_iLocalTime;
  return m_iLocalTime + v4 + v3;
}

