// File Line: 41
// RVA: 0xAB7070
void __fastcall CAkSequenceCtx::CAkSequenceCtx(
        CAkSequenceCtx *this,
        CAkMusicRanSeqCntr *in_pSequenceNode,
        CAkMusicCtx *in_pParentCtx)
{
  CAkMusicRanSeqCntr *m_pSequenceNode; // rcx

  CAkChainCtx::CAkChainCtx(this, in_pParentCtx);
  this->CAkChainCtx::CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr = (CAkChildCtxVtbl *)&CAkSequenceCtx::`vftable{for `CAkChildCtx};
  this->CAkChainCtx::CAkMatrixAwareCtx::CAkMusicCtx::CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkSequenceCtx::`vftable{for `CAkTransportAware};
  this->m_pSequenceNode = in_pSequenceNode;
  this->CAkChainCtx::CAkMatrixAwareCtx::CAkMusicCtx::ITransitionable::vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable{for `ITransitionable};
  AkRSIterator::AkRSIterator(&this->m_PlayListIterator, in_pSequenceNode);
  m_pSequenceNode = this->m_pSequenceNode;
  this->m_bIsChainValid = 1;
  if ( m_pSequenceNode )
    m_pSequenceNode->vfptr->AddRef(m_pSequenceNode);
}

// File Line: 47
// RVA: 0xAB70F0
void __fastcall CAkSequenceCtx::~CAkSequenceCtx(CAkSequenceCtx *this)
{
  AkRSIterator *p_m_PlayListIterator; // rcx
  CAkMusicRanSeqCntr *m_pSequenceNode; // rcx

  p_m_PlayListIterator = &this->m_PlayListIterator;
  *(_QWORD *)&p_m_PlayListIterator[-3].m_arOriginalGlobalRSInfo.m_uLength = &CAkSequenceCtx::`vftable{for `CAkChildCtx};
  *(_QWORD *)&p_m_PlayListIterator[-2].m_playingID = &CAkSequenceCtx::`vftable{for `CAkTransportAware};
  *(_QWORD *)&p_m_PlayListIterator[-2].m_stack.m_uLength = &CAkSegmentCtx::`vftable{for `ITransitionable};
  AkRSIterator::Term(p_m_PlayListIterator);
  m_pSequenceNode = this->m_pSequenceNode;
  if ( m_pSequenceNode )
    m_pSequenceNode->vfptr->Release(m_pSequenceNode);
  _((AMD_HD3D *)&this->m_PlayListIterator);
  CAkChainCtx::~CAkChainCtx(this);
}

// File Line: 63
// RVA: 0xAB7480
__int64 __fastcall CAkSequenceCtx::Init(
        CAkSequenceCtx *this,
        CAkRegisteredObj *in_GameObject,
        UserParams *in_rUserparams)
{
  __int64 result; // rax
  unsigned int v5; // edi
  CAkScheduledItem *v6; // rax
  CAkSegmentCtx *m_pT; // rcx
  __int64 v8; // r8
  unsigned __int64 v9; // rcx
  bool out_bPlayPreEntry; // [rsp+58h] [rbp+20h] BYREF

  result = CAkMatrixAwareCtx::Init(this, in_GameObject, in_rUserparams);
  if ( (_DWORD)result == 1 )
  {
    result = AkRSIterator::Init(&this->m_PlayListIterator, this->m_pSequencer->m_UserParams.m_PlayingID);
    v5 = result;
    if ( (_DWORD)result == 1 )
    {
      v6 = CAkSequenceCtx::ScheduleNextSegment(this, &out_bPlayPreEntry);
      if ( v6 && (m_pT = v6->m_pSegment.m_pT) != 0i64 )
      {
        if ( out_bPlayPreEntry )
          v8 = (unsigned int)-CAkMusicSegment::PreEntryDuration(m_pT->m_pSegmentNode);
        else
          v8 = 0i64;
        v9 = ((int (__fastcall *)(CAkSequenceCtx *, _QWORD, __int64, _QWORD, bool *, _DWORD))this->CAkChainCtx::CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr[1].VirtualAddRef)(
               this,
               0i64,
               v8,
               0i64,
               &out_bPlayPreEntry,
               0);
        result = v5;
        this->m_iLocalTime = v9;
      }
      else
      {
        return 2i64;
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
  CAkScheduledItem *m_pLast; // rbx
  bool out_bPlayPreEntry; // [rsp+30h] [rbp+8h] BYREF

  v1 = 0i64;
  if ( this->m_PlayListIterator.m_bIsSegmentValid )
  {
    m_pLast = this->m_chain.m_pLast;
    v1 = CAkSequenceCtx::ScheduleNextSegment(this, &out_bPlayPreEntry);
    if ( v1 == m_pLast )
      v1 = 0i64;
  }
  return v1 != 0i64;
}

// File Line: 142
// RVA: 0xAB7840
void __fastcall CAkSequenceCtx::UpdateChainLength(CAkSequenceCtx *this, __int64 in_iDesiredPosition)
{
  CAkScheduledItem *m_pFirst; // rbx
  int v3; // esi
  unsigned int v6; // ebp
  CAkScheduledItem *i; // rdi
  CAkScheduledItem *m_pLast; // rdi
  CAkScheduledItem *v9; // rax
  CAkScheduledItem *v10; // rbx
  CAkScheduledItem *v11; // rax
  bool out_bPlayPreEntry; // [rsp+40h] [rbp+8h] BYREF

  m_pFirst = this->m_chain.m_pFirst;
  v3 = 0;
  v6 = 0;
  for ( i = m_pFirst; m_pFirst; m_pFirst = m_pFirst->pNextItem )
  {
    if ( (signed __int64)m_pFirst->m_iLocalTime >= in_iDesiredPosition )
      goto LABEL_11;
    i = m_pFirst;
  }
  m_pFirst = i;
  if ( i )
  {
    if ( (signed __int64)i->m_iLocalTime >= in_iDesiredPosition )
      goto LABEL_11;
    while ( this->m_PlayListIterator.m_bIsSegmentValid )
    {
      m_pLast = this->m_chain.m_pLast;
      v9 = CAkSequenceCtx::ScheduleNextSegment(this, &out_bPlayPreEntry);
      if ( v9 == m_pLast || !v9 )
        break;
      if ( (unsigned int)++v3 > 0x40 )
      {
$break_infinite_loop:
        this->CAkChainCtx::CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr[3].VirtualAddRef(this);
        return;
      }
      i = m_pFirst;
      m_pFirst = m_pFirst->pNextItem;
      if ( (signed __int64)m_pFirst->m_iLocalTime >= in_iDesiredPosition )
      {
        while ( 1 )
        {
LABEL_11:
          ++v6;
          if ( m_pFirst )
          {
            i = m_pFirst;
            m_pFirst = m_pFirst->pNextItem;
          }
          else
          {
            if ( !this->m_PlayListIterator.m_bIsSegmentValid )
              return;
            v10 = this->m_chain.m_pLast;
            v11 = CAkSequenceCtx::ScheduleNextSegment(this, &out_bPlayPreEntry);
            if ( v11 == v10 || !v11 )
              return;
            if ( (unsigned int)++v3 > 0x40 )
              goto $break_infinite_loop;
            i = i->pNextItem;
            m_pFirst = i->pNextItem;
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
  CAkScheduledItem *result; // rax
  bool out_bPlayPreEntry; // [rsp+38h] [rbp+10h] BYREF

  if ( !in_uJumpToID )
    return this->m_chain.m_pFirst;
  CAkChainCtx::Flush(this);
  if ( (unsigned int)AkRSIterator::JumpTo(&this->m_PlayListIterator, in_uJumpToID) != 1 )
    return (CAkScheduledItem *)((__int64 (__fastcall *)(CAkSequenceCtx *))this->CAkChainCtx::CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr[3].VirtualAddRef)(this);
  result = CAkSequenceCtx::ScheduleNextSegment(this, &out_bPlayPreEntry);
  if ( result )
  {
    if ( !result->m_pSegment.m_pT )
    {
      CAkChainCtx::Flush(this);
      return 0i64;
    }
  }
  return result;
}

// File Line: 271
// RVA: 0xAB75D0
CAkScheduledItem *__fastcall CAkSequenceCtx::ScheduleNextSegment(CAkSequenceCtx *this, bool *out_bPlayPreEntry)
{
  unsigned int m_actualSegment; // r15d
  CAkScheduledItem *m_pLast; // rsi
  unsigned int key; // edx
  AkMusicTransitionRule *TransitionRule; // rax
  AkMusicTransitionRule *v9; // rdi
  AkMusicTransitionObject *pTransObj; // rdx
  AkMusicTransRuleBase v11; // xmm0
  int iFadeOffset; // eax
  CAkScheduledItem *appended; // rax
  __int64 v14; // rsi
  AkMusicTransitionObject *v15; // rdx
  CAkScheduledItem *v16; // r8
  int v17; // eax
  int v18; // ecx
  AkCurveInterpolation eFadeCurve; // eax
  AkMusicTransitionRule in_rule; // [rsp+30h] [rbp-19h] BYREF

  *out_bPlayPreEntry = 0;
  if ( (*((_BYTE *)&this->CAkMusicCtx + 98) & 0xFu) > 1 )
    return 0i64;
  m_actualSegment = this->m_PlayListIterator.m_actualSegment;
  if ( !this->m_PlayListIterator.m_bIsSegmentValid )
    return 0i64;
  AkRSIterator::JumpNext(&this->m_PlayListIterator);
  m_pLast = this->m_chain.m_pLast;
  if ( m_pLast )
    key = m_pLast->m_pSegment.m_pT->m_pSegmentNode->key;
  else
    key = 0;
  TransitionRule = CAkMusicTransAware::GetTransitionRule(this->m_pSequenceNode, key, m_actualSegment);
  v9 = TransitionRule;
  pTransObj = TransitionRule->pTransObj;
  if ( pTransObj )
  {
    v11 = TransitionRule->srcRule.AkMusicTransRuleBase;
    *((_DWORD *)&in_rule.srcRule + 4) = *((_DWORD *)&TransitionRule->srcRule + 4);
    memset(&in_rule, 0, 32);
    in_rule.srcRule.AkMusicTransRuleBase = v11;
    in_rule.pTransObj = 0i64;
    in_rule.destRule.fadeParams.transitionTime = pTransObj->fadeInParams.transitionTime;
    in_rule.destRule.fadeParams.eFadeCurve = pTransObj->fadeInParams.eFadeCurve;
    iFadeOffset = pTransObj->fadeInParams.iFadeOffset;
    in_rule.destRule.uCueFilterHash = 0;
    in_rule.destRule.fadeParams.iFadeOffset = iFadeOffset;
    *((_WORD *)&in_rule.destRule + 10) &= 0xFFF8u;
    *((_WORD *)&in_rule.destRule + 10) = *((_WORD *)&in_rule.destRule + 10) & 0xFFE7 | (8
                                                                                      * (*((_WORD *)pTransObj + 14) & 1));
    *out_bPlayPreEntry = *((_BYTE *)pTransObj + 28) & 1;
    appended = CAkSequenceCtx::AppendItem(this, &in_rule, m_pLast, v9->pTransObj->segmentID, 0);
    v14 = (__int64)appended;
    if ( appended )
    {
      if ( appended->m_pSegment.m_pT )
      {
        v15 = v9->pTransObj;
        v16 = appended;
        in_rule.srcRule.fadeParams.transitionTime = v15->fadeOutParams.transitionTime;
        in_rule.srcRule.fadeParams.eFadeCurve = v15->fadeOutParams.eFadeCurve;
        v17 = v15->fadeOutParams.iFadeOffset;
        *((_DWORD *)&in_rule.srcRule + 4) = *((_DWORD *)&in_rule.srcRule + 4) & 0xFFFFFFE0 | 7;
        in_rule.srcRule.fadeParams.iFadeOffset = v17;
        v18 = (*((_BYTE *)&in_rule.srcRule + 16) ^ (unsigned __int8)(16 * *((_DWORD *)v15 + 7))) & 0x20 ^ *((_DWORD *)&in_rule.srcRule + 4);
        in_rule.destRule.fadeParams.transitionTime = v9->destRule.fadeParams.transitionTime;
        eFadeCurve = v9->destRule.fadeParams.eFadeCurve;
        *((_DWORD *)&in_rule.srcRule + 4) = v18;
        in_rule.destRule.fadeParams.eFadeCurve = eFadeCurve;
        in_rule.destRule.fadeParams.iFadeOffset = v9->destRule.fadeParams.iFadeOffset;
        in_rule.destRule.uCueFilterHash = v9->destRule.uCueFilterHash;
        in_rule.destRule.uJumpToID = v9->destRule.uJumpToID;
        *((_DWORD *)&in_rule.destRule + 5) = *((_DWORD *)&v9->destRule + 5);
        CAkSequenceCtx::AppendItem(this, &in_rule, v16, m_actualSegment, 0);
      }
      else
      {
        v14 = ((__int64 (__fastcall *)(CAkSequenceCtx *))this->CAkChainCtx::CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr[3].VirtualAddRef)(this);
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
    return (CAkScheduledItem *)v14;
  }
  else
  {
    *out_bPlayPreEntry = (*((_BYTE *)&TransitionRule->destRule + 20) & 8) != 0;
    return CAkSequenceCtx::AppendItem(this, TransitionRule, m_pLast, m_actualSegment, 0);
  }
}

// File Line: 364
// RVA: 0xAB71A0
CAkScheduledItem *__fastcall CAkSequenceCtx::AppendItem(
        CAkSequenceCtx *this,
        AkMusicTransitionRule *in_rule,
        CAkScheduledItem *in_pSrcItem,
        unsigned int in_nextID,
        unsigned int in_playlistItemID)
{
  CAkSegmentCtx *LowLevelSegmentCtxAndAddRef; // rbx
  signed int v10; // r13d
  CAkMusicSegment *m_pSegmentNode; // r13
  int transitionTime; // r14d
  signed int v13; // esi
  double v14; // xmm1_8
  double v15; // xmm0_8
  int active; // eax
  AkMusicTransDestRule *p_destRule; // rsi
  CAkMusicSegment *NodePtrAndAddRef; // r14
  CAkScheduledItem *v19; // rax
  CAkScheduledItem *v20; // rbp
  int v22; // eax
  unsigned int v23; // edx
  int v24; // r8d
  int v25; // eax
  unsigned int v26; // [rsp+30h] [rbp-48h]
  unsigned __int64 m_iLocalTime; // [rsp+38h] [rbp-40h]
  unsigned int out_uSelectedCueHash; // [rsp+88h] [rbp+10h] BYREF
  unsigned int v29; // [rsp+90h] [rbp+18h] BYREF
  unsigned int in_uSyncPosition; // [rsp+98h] [rbp+20h] BYREF

  LowLevelSegmentCtxAndAddRef = 0i64;
  m_iLocalTime = 0i64;
  v10 = 0;
  if ( in_pSrcItem )
  {
    m_iLocalTime = in_pSrcItem->m_iLocalTime;
    out_uSelectedCueHash = in_rule->srcRule.uCueFilterHash;
    m_pSegmentNode = in_pSrcItem->m_pSegment.m_pT->m_pSegmentNode;
    CAkMusicSegment::GetExitSyncPos(
      m_pSegmentNode,
      0,
      (AkSyncType)(*((_DWORD *)&in_rule->srcRule + 4) & 0x1F),
      &out_uSelectedCueHash,
      1,
      &v29);
    transitionTime = in_rule->srcRule.fadeParams.transitionTime;
    v26 = v29;
    v13 = in_rule->srcRule.fadeParams.iFadeOffset
        - transitionTime * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
    if ( v13 < (signed int)-v29 )
    {
      v13 = -v29;
      v14 = (double)(int)(in_rule->srcRule.fadeParams.iFadeOffset + v29)
          * 1000.0
          / (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency;
      if ( v14 <= 0.0 )
        v15 = DOUBLE_N0_5;
      else
        v15 = DOUBLE_0_5;
      transitionTime = (int)(v15 + v14);
    }
    if ( !v13 && !transitionTime && (*((_BYTE *)&in_rule->srcRule + 16) & 0x20) != 0 )
      v13 = CAkMusicSegment::PostExitDuration(m_pSegmentNode);
    active = CAkMusicSegment::ActiveDuration(m_pSegmentNode);
    CAkScheduledItem::AttachStopCmd(in_pSrcItem, transitionTime, in_rule->srcRule.fadeParams.eFadeCurve, active + v13);
    v10 = v26;
  }
  p_destRule = &in_rule->destRule;
  in_uSyncPosition = 0;
  if ( in_nextID )
  {
    NodePtrAndAddRef = (CAkMusicSegment *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_nextID, AkNodeType_Default);
    if ( NodePtrAndAddRef )
    {
      CAkMusicSegment::GetEntrySyncPos(
        NodePtrAndAddRef,
        &in_rule->destRule,
        0,
        0,
        &out_uSelectedCueHash,
        &in_uSyncPosition);
      LowLevelSegmentCtxAndAddRef = CAkMusicSegment::CreateLowLevelSegmentCtxAndAddRef(
                                      NodePtrAndAddRef,
                                      this,
                                      this->m_pSequencer->m_pGameObj,
                                      &this->m_pSequencer->m_UserParams);
      if ( !LowLevelSegmentCtxAndAddRef )
        this->m_PlayListIterator.m_bIsSegmentValid = 0;
      NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef);
    }
    else
    {
      this->m_PlayListIterator.m_bIsSegmentValid = 0;
    }
  }
  CAkChainCtx::EnqueueItem(this, m_iLocalTime + v10, LowLevelSegmentCtxAndAddRef);
  v20 = v19;
  if ( LowLevelSegmentCtxAndAddRef )
    CAkMusicCtx::Release(LowLevelSegmentCtxAndAddRef);
  if ( !v20 )
    return (CAkScheduledItem *)((__int64 (__fastcall *)(CAkSequenceCtx *))this->CAkChainCtx::CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr[3].VirtualAddRef)(this);
  if ( LowLevelSegmentCtxAndAddRef )
  {
    if ( (*((_BYTE *)p_destRule + 20) & 8) != 0 )
    {
      v22 = CAkMusicSegment::PreEntryDuration(LowLevelSegmentCtxAndAddRef->m_pSegmentNode);
      v23 = in_uSyncPosition;
      v24 = in_uSyncPosition - v22;
    }
    else
    {
      v23 = in_uSyncPosition;
      v24 = in_uSyncPosition;
    }
    v25 = CAkScheduledItem::Prepare(v20, v23, v24, &p_destRule->fadeParams);
    CAkScheduledItem::SetFadeIn(
      v20,
      p_destRule->fadeParams.transitionTime,
      p_destRule->fadeParams.eFadeCurve,
      v25 + p_destRule->fadeParams.iFadeOffset);
  }
  return v20;
}

// File Line: 518
// RVA: 0xAB7460
CAkScheduledItem *__fastcall CAkSequenceCtx::HandleFatalError(CAkSequenceCtx *this)
{
  this->m_PlayListIterator.m_bIsSegmentValid = 0;
  this->m_bIsChainValid = 0;
  return UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(this);
}

// File Line: 527
// RVA: 0xAB7540
_BOOL8 __fastcall CAkSequenceCtx::IsValid(CAkSequenceCtx *this)
{
  return this->m_bIsChainValid;
}

