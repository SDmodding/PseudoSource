// File Line: 41
// RVA: 0xAB7070
void __fastcall CAkSequenceCtx::CAkSequenceCtx(CAkSequenceCtx *this, CAkMusicRanSeqCntr *in_pSequenceNode, CAkMusicCtx *in_pParentCtx)
{
  CAkMusicRanSeqCntr *v3; // rbx
  CAkSequenceCtx *v4; // rdi
  CAkMusicRanSeqCntr *v5; // rcx

  v3 = in_pSequenceNode;
  v4 = this;
  CAkChainCtx::CAkChainCtx((CAkChainCtx *)&this->vfptr, in_pParentCtx);
  v4->vfptr = (CAkChildCtxVtbl *)&CAkSequenceCtx::`vftable'{for `CAkChildCtx'};
  v4->vfptr = (CAkTransportAwareVtbl *)&CAkSequenceCtx::`vftable'{for `CAkTransportAware'};
  v4->m_pSequenceNode = v3;
  v4->vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable'{for `ITransitionable'};
  AkRSIterator::AkRSIterator(&v4->m_PlayListIterator, v3);
  v5 = v4->m_pSequenceNode;
  v4->m_bIsChainValid = 1;
  if ( v5 )
    ((void (*)(void))v5->vfptr->AddRef)();
}

// File Line: 47
// RVA: 0xAB70F0
void __fastcall CAkSequenceCtx::~CAkSequenceCtx(CAkSequenceCtx *this)
{
  CAkSequenceCtx *v1; // rbx
  AkRSIterator *v2; // rcx
  CAkMusicRanSeqCntr *v3; // rcx

  v1 = this;
  v2 = &this->m_PlayListIterator;
  *(_QWORD *)&v2[-3].m_arOriginalGlobalRSInfo.m_uLength = &CAkSequenceCtx::`vftable'{for `CAkChildCtx'};
  *(_QWORD *)&v2[-2].m_playingID = &CAkSequenceCtx::`vftable'{for `CAkTransportAware'};
  *(_QWORD *)&v2[-2].m_stack.m_uLength = &CAkSegmentCtx::`vftable'{for `ITransitionable'};
  AkRSIterator::Term(v2);
  v3 = v1->m_pSequenceNode;
  if ( v3 )
    ((void (*)(void))v3->vfptr->Release)();
  _((AMD_HD3D *)&v1->m_PlayListIterator);
  CAkChainCtx::~CAkChainCtx((CAkChainCtx *)&v1->vfptr);
}

// File Line: 63
// RVA: 0xAB7480
signed __int64 __fastcall CAkSequenceCtx::Init(CAkSequenceCtx *this, CAkRegisteredObj *in_GameObject, UserParams *in_rUserparams)
{
  CAkSequenceCtx *v3; // rbx
  signed __int64 result; // rax
  unsigned int v5; // edi
  CAkScheduledItem *v6; // rax
  CAkSegmentCtx *v7; // rcx
  __int64 v8; // r8
  unsigned __int64 v9; // rcx
  bool out_bPlayPreEntry; // [rsp+58h] [rbp+20h]

  v3 = this;
  result = CAkMatrixAwareCtx::Init((CAkMatrixAwareCtx *)&this->vfptr, in_GameObject, in_rUserparams);
  if ( (_DWORD)result == 1 )
  {
    result = AkRSIterator::Init(&v3->m_PlayListIterator, v3->m_pSequencer->m_UserParams.m_PlayingID);
    v5 = result;
    if ( (_DWORD)result == 1 )
    {
      v6 = CAkSequenceCtx::ScheduleNextSegment(v3, &out_bPlayPreEntry);
      if ( v6 && (v7 = v6->m_pSegment.m_pT) != 0i64 )
      {
        if ( out_bPlayPreEntry )
          v8 = (unsigned int)-CAkMusicSegment::PreEntryDuration(v7->m_pSegmentNode);
        else
          v8 = 0i64;
        v9 = ((signed int (__fastcall *)(CAkSequenceCtx *, _QWORD, __int64, _QWORD, bool *, _DWORD))v3->vfptr[1].VirtualAddRef)(
               v3,
               0i64,
               v8,
               0i64,
               &out_bPlayPreEntry,
               0);
        result = v5;
        v3->m_iLocalTime = v9;
      }
      else
      {
        result = 2i64;
      }
    }
  }
  return result;
}

// File Line: 103
// RVA: 0xAB7410
void __fastcall CAkSequenceCtx::EndInit(CAkSequenceCtx *this)
{
  AkRSIterator::EndInit(&this->m_PlayListIterator);
}

// File Line: 108
// RVA: 0xAB7420
bool __fastcall CAkSequenceCtx::Grow(CAkSequenceCtx *this)
{
  CAkScheduledItem *v1; // rax
  CAkScheduledItem *v2; // rbx
  bool out_bPlayPreEntry; // [rsp+30h] [rbp+8h]

  v1 = 0i64;
  if ( this->m_PlayListIterator.m_bIsSegmentValid )
  {
    v2 = this->m_chain.m_pLast;
    v1 = CAkSequenceCtx::ScheduleNextSegment(this, &out_bPlayPreEntry);
    if ( v1 == v2 )
      v1 = 0i64;
  }
  return v1 != 0i64;
}

// File Line: 142
// RVA: 0xAB7840
void __fastcall CAkSequenceCtx::UpdateChainLength(CAkSequenceCtx *this, __int64 in_iDesiredPosition)
{
  CAkScheduledItem *v2; // rbx
  int v3; // esi
  __int64 v4; // r15
  CAkSequenceCtx *v5; // r14
  unsigned int v6; // ebp
  CAkScheduledItem *i; // rdi
  CAkScheduledItem *v8; // rdi
  CAkScheduledItem *v9; // rax
  CAkScheduledItem *v10; // rbx
  CAkScheduledItem *v11; // rax
  bool out_bPlayPreEntry; // [rsp+40h] [rbp+8h]

  v2 = this->m_chain.m_pFirst;
  v3 = 0;
  v4 = in_iDesiredPosition;
  v5 = this;
  v6 = 0;
  for ( i = v2; v2; v2 = v2->pNextItem )
  {
    if ( (signed __int64)v2->m_iLocalTime >= in_iDesiredPosition )
      goto LABEL_11;
    i = v2;
  }
  v2 = i;
  if ( i )
  {
    if ( (signed __int64)i->m_iLocalTime >= in_iDesiredPosition )
      goto LABEL_11;
    while ( v5->m_PlayListIterator.m_bIsSegmentValid )
    {
      v8 = v5->m_chain.m_pLast;
      v9 = CAkSequenceCtx::ScheduleNextSegment(v5, &out_bPlayPreEntry);
      if ( v9 == v8 || !v9 )
        break;
      if ( (unsigned int)++v3 > 0x40 )
      {
$break_infinite_loop:
        v5->vfptr[3].VirtualAddRef((CAkChildCtx *)&v5->vfptr);
        return;
      }
      i = v2;
      v2 = v2->pNextItem;
      if ( (signed __int64)v2->m_iLocalTime >= v4 )
      {
        while ( 1 )
        {
LABEL_11:
          ++v6;
          if ( v2 )
          {
            i = v2;
            v2 = v2->pNextItem;
          }
          else
          {
            if ( !v5->m_PlayListIterator.m_bIsSegmentValid )
              return;
            v10 = v5->m_chain.m_pLast;
            v11 = CAkSequenceCtx::ScheduleNextSegment(v5, &out_bPlayPreEntry);
            if ( v11 == v10 || !v11 )
              return;
            if ( (unsigned int)++v3 > 0x40 )
              goto $break_infinite_loop;
            i = i->pNextItem;
            v2 = i->pNextItem;
          }
          if ( v6 >= 3 )
            return;
        }
      }
    }
  }
}

// File Line: 230
// RVA: 0xAB7550
CAkScheduledItem *__fastcall CAkSequenceCtx::JumpToSegment(CAkSequenceCtx *this, unsigned int in_uJumpToID)
{
  unsigned int v2; // edi
  CAkSequenceCtx *v3; // rbx
  CAkScheduledItem *result; // rax
  bool out_bPlayPreEntry; // [rsp+38h] [rbp+10h]

  v2 = in_uJumpToID;
  v3 = this;
  if ( !in_uJumpToID )
    return this->m_chain.m_pFirst;
  CAkChainCtx::Flush((CAkChainCtx *)&this->vfptr);
  if ( (unsigned int)AkRSIterator::JumpTo(&v3->m_PlayListIterator, v2) != 1 )
    return (CAkScheduledItem *)((__int64 (__fastcall *)(CAkSequenceCtx *))v3->vfptr[3].VirtualAddRef)(v3);
  result = CAkSequenceCtx::ScheduleNextSegment(v3, &out_bPlayPreEntry);
  if ( result )
  {
    if ( !result->m_pSegment.m_pT )
    {
      CAkChainCtx::Flush((CAkChainCtx *)&v3->vfptr);
      result = 0i64;
    }
  }
  return result;
}

// File Line: 271
// RVA: 0xAB75D0
CAkScheduledItem *__fastcall CAkSequenceCtx::ScheduleNextSegment(CAkSequenceCtx *this, bool *out_bPlayPreEntry)
{
  bool *v2; // r14
  CAkSequenceCtx *v3; // rbx
  CAkScheduledItem *result; // rax
  unsigned int v5; // er15
  CAkScheduledItem *v6; // rsi
  unsigned int v7; // edx
  AkMusicTransitionRule *v8; // rax
  AkMusicTransitionRule *v9; // rdi
  AkMusicTransitionObject *v10; // rdx
  AkMusicTransRuleBase v11; // xmm0
  int v12; // eax
  CAkScheduledItem *v13; // rax
  CAkScheduledItem *v14; // rsi
  AkMusicTransitionObject *v15; // rdx
  CAkScheduledItem *v16; // r8
  unsigned int v17; // ecx
  int v18; // eax
  int v19; // ecx
  AkCurveInterpolation v20; // eax
  AkMusicTransitionRule in_rule; // [rsp+30h] [rbp-19h]

  *out_bPlayPreEntry = 0;
  v2 = out_bPlayPreEntry;
  v3 = this;
  if ( (*((_BYTE *)&this->0 + 98) & 0xFu) > 1 )
    return 0i64;
  v5 = this->m_PlayListIterator.m_actualSegment;
  if ( !this->m_PlayListIterator.m_bIsSegmentValid )
    return 0i64;
  AkRSIterator::JumpNext(&this->m_PlayListIterator);
  v6 = v3->m_chain.m_pLast;
  if ( v6 )
    v7 = v6->m_pSegment.m_pT->m_pSegmentNode->key;
  else
    v7 = 0;
  v8 = CAkMusicTransAware::GetTransitionRule((CAkMusicTransAware *)&v3->m_pSequenceNode->vfptr, v7, v5);
  v9 = v8;
  v10 = v8->pTransObj;
  if ( v10 )
  {
    v11 = v8->srcRule.0;
    *((_DWORD *)&in_rule.srcRule + 4) = *((_DWORD *)&v8->srcRule + 4);
    in_rule.srcIDs.m_pItems = 0i64;
    *(_QWORD *)&in_rule.srcIDs.m_uLength = 0i64;
    in_rule.srcRule.0 = v11;
    in_rule.destIDs.m_pItems = 0i64;
    *(_QWORD *)&in_rule.destIDs.m_uLength = 0i64;
    in_rule.pTransObj = 0i64;
    in_rule.destRule.fadeParams.transitionTime = v10->fadeInParams.transitionTime;
    in_rule.destRule.fadeParams.eFadeCurve = v10->fadeInParams.eFadeCurve;
    v12 = v10->fadeInParams.iFadeOffset;
    in_rule.destRule.uCueFilterHash = 0;
    in_rule.destRule.fadeParams.iFadeOffset = v12;
    *((_WORD *)&in_rule.destRule + 10) &= 0xFFF8u;
    *((_WORD *)&in_rule.destRule + 10) = *((_WORD *)&in_rule.destRule + 10) & 0xFFE7 | 8 * (*((_WORD *)v10 + 14) & 1);
    *v2 = *((_BYTE *)v10 + 28) & 1;
    v13 = CAkSequenceCtx::AppendItem(v3, &in_rule, v6, v9->pTransObj->segmentID, 0);
    v14 = v13;
    if ( v13 )
    {
      if ( v13->m_pSegment.m_pT )
      {
        v15 = v9->pTransObj;
        v16 = v13;
        in_rule.srcRule.fadeParams.transitionTime = v15->fadeOutParams.transitionTime;
        v17 = *((_DWORD *)&in_rule.srcRule + 4) & 0xFFFFFFE7 | 7;
        in_rule.srcRule.fadeParams.eFadeCurve = v15->fadeOutParams.eFadeCurve;
        v18 = v15->fadeOutParams.iFadeOffset;
        *((_DWORD *)&in_rule.srcRule + 4) = v17;
        in_rule.srcRule.fadeParams.iFadeOffset = v18;
        v19 = ((unsigned __int8)v17 ^ (unsigned __int8)(16 * *((unsigned int *)v15 + 7))) & 0x20 ^ v17;
        in_rule.destRule.fadeParams.transitionTime = v9->destRule.fadeParams.transitionTime;
        v20 = v9->destRule.fadeParams.eFadeCurve;
        *((_DWORD *)&in_rule.srcRule + 4) = v19;
        in_rule.destRule.fadeParams.eFadeCurve = v20;
        in_rule.destRule.fadeParams.iFadeOffset = v9->destRule.fadeParams.iFadeOffset;
        in_rule.destRule.uCueFilterHash = v9->destRule.uCueFilterHash;
        in_rule.destRule.uJumpToID = v9->destRule.uJumpToID;
        *((_DWORD *)&in_rule.destRule + 5) = *((_DWORD *)&v9->destRule + 5);
        CAkSequenceCtx::AppendItem(v3, &in_rule, v16, v5, 0);
      }
      else
      {
        v14 = (CAkScheduledItem *)((__int64 (__fastcall *)(CAkSequenceCtx *))v3->vfptr[3].VirtualAddRef)(v3);
      }
    }
    if ( in_rule.pTransObj )
      AK::MemoryMgr::Free(g_DefaultPoolId, in_rule.pTransObj);
    if ( in_rule.srcIDs.m_pItems )
    {
      in_rule.srcIDs.m_uLength = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, in_rule.srcIDs.m_pItems);
      in_rule.srcIDs.m_pItems = 0i64;
      in_rule.srcIDs.m_ulReserved = 0;
    }
    if ( in_rule.destIDs.m_pItems )
    {
      in_rule.destIDs.m_uLength = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, in_rule.destIDs.m_pItems);
    }
    result = v14;
  }
  else
  {
    *v2 = (*((_BYTE *)&v8->destRule + 20) >> 3) & 1;
    result = CAkSequenceCtx::AppendItem(v3, v8, v6, v5, 0);
  }
  return result;
}

// File Line: 364
// RVA: 0xAB71A0
CAkScheduledItem *__fastcall CAkSequenceCtx::AppendItem(CAkSequenceCtx *this, AkMusicTransitionRule *in_rule, CAkScheduledItem *in_pSrcItem, unsigned int in_nextID, unsigned int in_playlistItemID)
{
  CAkSegmentCtx *v5; // rbx
  unsigned int v6; // er12
  CAkScheduledItem *v7; // r15
  AkMusicTransitionRule *v8; // rbp
  CAkSequenceCtx *v9; // rdi
  int v10; // er13
  CAkMusicSegment *v11; // r13
  int v12; // er14
  signed int v13; // esi
  double v14; // xmm1_8
  double v15; // xmm0_8
  int v16; // eax
  signed __int64 v17; // rsi
  CAkMusicSegment *v18; // r14
  CAkScheduledItem *v19; // rax
  CAkScheduledItem *v20; // rbp
  int v22; // eax
  unsigned int v23; // edx
  int v24; // er8
  int v25; // eax
  int v26; // [rsp+30h] [rbp-48h]
  unsigned __int64 v27; // [rsp+38h] [rbp-40h]
  unsigned int out_uSelectedCueHash; // [rsp+88h] [rbp+10h]
  int v29; // [rsp+90h] [rbp+18h]
  unsigned int in_uSyncPosition; // [rsp+98h] [rbp+20h]

  v5 = 0i64;
  v6 = in_nextID;
  v7 = in_pSrcItem;
  v8 = in_rule;
  v9 = this;
  v27 = 0i64;
  v10 = 0;
  if ( in_pSrcItem )
  {
    v27 = in_pSrcItem->m_iLocalTime;
    out_uSelectedCueHash = in_rule->srcRule.uCueFilterHash;
    v11 = in_pSrcItem->m_pSegment.m_pT->m_pSegmentNode;
    CAkMusicSegment::GetExitSyncPos(
      v11,
      0,
      (AkSyncType)(*((_DWORD *)&in_rule->srcRule + 4) & 0x1F),
      &out_uSelectedCueHash,
      1,
      (unsigned int *)&v29);
    v12 = v8->srcRule.fadeParams.transitionTime;
    v26 = v29;
    v13 = v8->srcRule.fadeParams.iFadeOffset - v12 * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
    if ( v13 < -v29 )
    {
      v13 = -v29;
      v14 = (double)(v8->srcRule.fadeParams.iFadeOffset + v29)
          * 1000.0
          / (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency;
      if ( v14 <= 0.0 )
        v15 = DOUBLE_N0_5;
      else
        v15 = DOUBLE_0_5;
      v12 = (signed int)(v15 + v14);
    }
    if ( !v13 && !v12 && *((_BYTE *)&v8->srcRule + 16) & 0x20 )
      v13 = CAkMusicSegment::PostExitDuration(v11);
    v16 = CAkMusicSegment::ActiveDuration(v11);
    CAkScheduledItem::AttachStopCmd(v7, v12, v8->srcRule.fadeParams.eFadeCurve, v16 + v13);
    v10 = v26;
  }
  v17 = (signed __int64)&v8->destRule;
  in_uSyncPosition = 0;
  if ( v6 )
  {
    v18 = (CAkMusicSegment *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v6, 0);
    if ( v18 )
    {
      CAkMusicSegment::GetEntrySyncPos(v18, &v8->destRule, 0, 0, &out_uSelectedCueHash, &in_uSyncPosition);
      v5 = (CAkSegmentCtx *)CAkMusicSegment::CreateLowLevelSegmentCtxAndAddRef(
                              v18,
                              (CAkMatrixAwareCtx *)&v9->vfptr,
                              v9->m_pSequencer->m_pGameObj,
                              &v9->m_pSequencer->m_UserParams);
      if ( !v5 )
        v9->m_PlayListIterator.m_bIsSegmentValid = 0;
      v18->vfptr->Release((CAkIndexable *)&v18->vfptr);
    }
    else
    {
      v9->m_PlayListIterator.m_bIsSegmentValid = 0;
    }
  }
  CAkChainCtx::EnqueueItem((CAkChainCtx *)&v9->vfptr, v27 + v10, v5);
  v20 = v19;
  if ( v5 )
    CAkMusicCtx::Release((CAkMusicCtx *)&v5->vfptr);
  if ( !v20 )
    return (CAkScheduledItem *)((__int64 (__fastcall *)(CAkSequenceCtx *))v9->vfptr[3].VirtualAddRef)(v9);
  if ( v5 )
  {
    if ( *(_BYTE *)(v17 + 20) & 8 )
    {
      v22 = CAkMusicSegment::PreEntryDuration(v5->m_pSegmentNode);
      v23 = in_uSyncPosition;
      v24 = in_uSyncPosition - v22;
    }
    else
    {
      v23 = in_uSyncPosition;
      v24 = in_uSyncPosition;
    }
    v25 = CAkScheduledItem::Prepare(v20, v23, v24, (AkMusicFade *)v17);
    CAkScheduledItem::SetFadeIn(v20, *(_DWORD *)v17, *(AkCurveInterpolation *)(v17 + 4), v25 + *(_DWORD *)(v17 + 8));
  }
  return v20;
}

// File Line: 518
// RVA: 0xAB7460
CAkScheduledItem *__fastcall CAkSequenceCtx::HandleFatalError(CAkSequenceCtx *this)
{
  this->m_PlayListIterator.m_bIsSegmentValid = 0;
  this->m_bIsChainValid = 0;
  return UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)&this->vfptr);
}

// File Line: 527
// RVA: 0xAB7540
_BOOL8 __fastcall CAkSequenceCtx::IsValid(CAkSequenceCtx *this)
{
  return this->m_bIsChainValid;
}

