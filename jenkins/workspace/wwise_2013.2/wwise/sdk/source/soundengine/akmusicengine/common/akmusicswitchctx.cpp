// File Line: 84
// RVA: 0xAB87F0
void __fastcall CAkNothingCtx::OnStopped(CAkNothingCtx *this)
{
  ++this->m_uRefCount;
  if ( this->m_bWasReferenced )
  {
    this->m_bWasReferenced = 0;
    CAkMusicCtx::Release(this);
  }
  CAkChainCtx::OnStopped(this);
  CAkMusicCtx::Release(this);
}

// File Line: 114
// RVA: 0xAB7D30
CAkMusicSwitchTransition *__fastcall CAkMusicSwitchTransition::Create(CAkMatrixAwareCtx *in_pDestination)
{
  CAkMusicSwitchTransition *result; // rax

  result = (CAkMusicSwitchTransition *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
  if ( result )
  {
    result->pNextItem = 0i64;
    result->m_pDestCtx.m_pT = in_pDestination;
    if ( in_pDestination )
      ++in_pDestination->m_uRefCount;
    result->m_cutoffInfo.iCutoffTime = 0i64;
    result->m_cutoffInfo.bCutoff = 0;
    *((_BYTE *)result + 72) &= 0xF8u;
  }
  return result;
}

// File Line: 136
// RVA: 0xAB7ED0
void __fastcall CAkMusicSwitchTransition::Dispose(CAkMusicSwitchTransition *this)
{
  int v1; // edi
  CAkMatrixAwareCtx *m_pT; // rcx
  CAkMatrixAwareCtx *v4; // rcx

  if ( this )
  {
    v1 = g_DefaultPoolId;
    m_pT = this->m_pDestCtx.m_pT;
    this->m_pDestCtx.m_pT = 0i64;
    if ( m_pT )
      CAkMusicCtx::Release(m_pT);
    v4 = this->m_pDestCtx.m_pT;
    if ( v4 )
    {
      CAkMusicCtx::Release(v4);
      this->m_pDestCtx.m_pT = 0i64;
    }
    AK::MemoryMgr::Free(v1, this);
  }
}

// File Line: 154
// RVA: 0xAB7C30
void __fastcall CAkMusicSwitchTransition::Cancel(CAkMusicSwitchTransition *this)
{
  CAkMatrixAwareCtx *m_pT; // rcx
  int v3; // edi
  CAkMatrixAwareCtx *v4; // rcx

  *((_BYTE *)this + 72) &= 0xFCu;
  UFG::OnUnloadClass<UITest::HandleArrayTest>(this->m_pDestCtx.m_pT);
  m_pT = this->m_pDestCtx.m_pT;
  v3 = g_DefaultPoolId;
  this->m_pDestCtx.m_pT = 0i64;
  if ( m_pT )
    CAkMusicCtx::Release(m_pT);
  v4 = this->m_pDestCtx.m_pT;
  if ( v4 )
  {
    CAkMusicCtx::Release(v4);
    this->m_pDestCtx.m_pT = 0i64;
  }
  AK::MemoryMgr::Free(v3, this);
}

// File Line: 321
// RVA: 0xABA390
void __fastcall CAkMusicSwitchMonitor::SetSwitch(
        CAkMusicSwitchMonitor *this,
        unsigned int in_switchID,
        CAkRegisteredObj *in_pGameObj)
{
  CAkMusicSwitchCtx *m_pMusicCtx; // rbx
  unsigned int v4; // r9d
  char *m_pGroupTypes; // rcx
  CAkMusicCtx *m_pParentCtx; // rcx
  CAkMusicSwitchCtx *v8; // rcx
  char v9; // al
  unsigned int v10; // esi
  CAkMusicSwitchCtx::TransitionInfo in_transitionInfo; // [rsp+20h] [rbp-18h] BYREF
  CAkMatrixAwareCtx *io_pNewContext; // [rsp+40h] [rbp+8h] BYREF

  m_pMusicCtx = this->m_pMusicCtx;
  v4 = in_switchID;
  if ( in_pGameObj == m_pMusicCtx->m_pSequencer->m_pGameObj
    || (m_pGroupTypes = m_pMusicCtx->m_pSwitchCntrNode->m_pGroupTypes) != 0i64 && m_pGroupTypes[this->m_uIdx] == 1 )
  {
    if ( !in_switchID )
      v4 = 748895195;
    if ( this->m_targetSwitchID != v4 )
    {
      this->m_targetSwitchID = v4;
      m_pParentCtx = m_pMusicCtx->m_pParentCtx;
      if ( m_pParentCtx
        && (m_pParentCtx[1].m_PBTrans.pvPRTrans->m_eTarget
         || (v8 = (CAkMusicSwitchCtx *)m_pParentCtx->m_pParentCtx) != 0i64
         && CAkMusicSwitchCtx::HasOrAscendentHasPendingTransition(v8)) )
      {
        *((_BYTE *)m_pMusicCtx + 184) |= 1u;
      }
      else
      {
        v9 = *((_BYTE *)&m_pMusicCtx->CAkMusicCtx + 98);
        *((_BYTE *)m_pMusicCtx + 184) &= ~1u;
        in_transitionInfo.pSeekingInfo = 0i64;
        in_transitionInfo.bOverrideEntryType = 0;
        if ( (v9 & 0xFu) <= 1 )
        {
          v10 = CAkMusicSwitchCtx::ResolveAudioNode(m_pMusicCtx);
          io_pNewContext = CAkMusicSwitchCtx::CreateDestinationContext(m_pMusicCtx, v10);
          if ( io_pNewContext )
          {
            CAkMusicSwitchCtx::ScheduleSwitchTransition(m_pMusicCtx, v10, &in_transitionInfo, &io_pNewContext);
            if ( io_pNewContext )
              io_pNewContext->CAkMusicCtx::CAkChildCtx::vfptr[1].OnResumed(io_pNewContext);
          }
        }
        CAkMusicSwitchCtx::TryPropagateDelayedSwitchChange(this->m_pMusicCtx);
      }
    }
  }
}

// File Line: 348
// RVA: 0xAB8580
__int64 __fastcall CAkMusicSwitchMonitor::Init(
        CAkMusicSwitchMonitor *this,
        unsigned int in_uIdx,
        CAkMusicSwitchCtx *in_pMusicCtx)
{
  AkGroupType v3; // ebx
  CAkMusicSwitchCntr *m_pSwitchCntrNode; // r9
  unsigned int *m_pArguments; // rcx
  unsigned int v8; // ebp
  char *m_pGroupTypes; // rcx
  __int64 result; // rax
  unsigned int SwitchToUse; // eax

  v3 = AkGroupType_Switch;
  this->m_uIdx = in_uIdx;
  this->m_pMusicCtx = in_pMusicCtx;
  this->m_targetSwitchID = 0;
  m_pSwitchCntrNode = in_pMusicCtx->m_pSwitchCntrNode;
  m_pArguments = m_pSwitchCntrNode->m_pArguments;
  if ( m_pArguments )
    v8 = m_pArguments[in_uIdx];
  else
    v8 = 0;
  m_pGroupTypes = m_pSwitchCntrNode->m_pGroupTypes;
  if ( m_pGroupTypes )
    v3 = (unsigned __int8)m_pGroupTypes[in_uIdx];
  result = CAkSwitchAware::SubscribeSwitch(this, v8, v3);
  if ( (_DWORD)result == 1 )
  {
    SwitchToUse = CAkSwitchAware::GetSwitchToUse(this, in_pMusicCtx->m_pSequencer->m_pGameObj, v8, v3);
    if ( !SwitchToUse )
      SwitchToUse = 748895195;
    this->m_targetSwitchID = SwitchToUse;
    return 1i64;
  }
  return result;
}

// File Line: 382
// RVA: 0xAB7960
void __fastcall CAkMusicSwitchCtx::CAkMusicSwitchCtx(
        CAkMusicSwitchCtx *this,
        CAkMusicSwitchCntr *in_pSwitchNode,
        CAkMusicCtx *in_pParentCtx)
{
  CAkMusicSwitchCntr *m_pSwitchCntrNode; // rcx

  CAkMatrixAwareCtx::CAkMatrixAwareCtx(this, in_pParentCtx);
  this->m_pSwitchCntrNode = in_pSwitchNode;
  this->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr = (CAkChildCtxVtbl *)&CAkMusicSwitchCtx::`vftable{for `CAkChildCtx};
  this->CAkMatrixAwareCtx::CAkMusicCtx::CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkMusicSwitchCtx::`vftable{for `CAkTransportAware};
  this->CAkMatrixAwareCtx::CAkMusicCtx::ITransitionable::vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable{for `ITransitionable};
  this->m_switchMonitors.m_pItems = 0i64;
  *(_QWORD *)&this->m_switchMonitors.m_uLength = 0i64;
  this->m_queueTransitions.m_pFirst = 0i64;
  this->m_queueTransitions.m_pLast = 0i64;
  m_pSwitchCntrNode = this->m_pSwitchCntrNode;
  *((_BYTE *)this + 184) &= 0xFCu;
  this->m_pLastNonCancelledTransitionInFrame = 0i64;
  this->m_itActiveSwitch.pItem = 0i64;
  if ( m_pSwitchCntrNode )
    m_pSwitchCntrNode->CAkMusicTransAware::CAkMusicNode::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr->AddRef(m_pSwitchCntrNode);
}

// File Line: 390
// RVA: 0xAB7A00
void __fastcall CAkMusicSwitchCtx::~CAkMusicSwitchCtx(CAkMusicSwitchCtx *this)
{
  CAkMusicSwitchCntr *m_pSwitchCntrNode; // rcx

  this->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr = (CAkChildCtxVtbl *)&CAkMusicSwitchCtx::`vftable{for `CAkChildCtx};
  this->CAkMatrixAwareCtx::CAkMusicCtx::CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkMusicSwitchCtx::`vftable{for `CAkTransportAware};
  this->CAkMatrixAwareCtx::CAkMusicCtx::ITransitionable::vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable{for `ITransitionable};
  if ( this->m_switchMonitors.m_pItems )
  {
    AkArray<CAkMusicSwitchMonitor,CAkMusicSwitchMonitor const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::RemoveAll(&this->m_switchMonitors);
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_switchMonitors.m_pItems);
    this->m_switchMonitors.m_pItems = 0i64;
    this->m_switchMonitors.m_ulReserved = 0;
  }
  m_pSwitchCntrNode = this->m_pSwitchCntrNode;
  if ( m_pSwitchCntrNode )
    m_pSwitchCntrNode->CAkMusicTransAware::CAkMusicNode::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr->Release(m_pSwitchCntrNode);
  CAkMatrixAwareCtx::~CAkMatrixAwareCtx(this);
}

// File Line: 401
// RVA: 0xAB8380
__int64 __fastcall CAkMusicSwitchCtx::Init(
        CAkMusicSwitchCtx *this,
        CAkRegisteredObj *in_GameObject,
        UserParams *in_rUserparams)
{
  AKRESULT v4; // esi
  AkArray<CAkMusicSwitchMonitor,CAkMusicSwitchMonitor const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *p_m_switchMonitors; // rdi
  __int64 m_uDepth; // r14
  CAkMusicSwitchMonitor *v7; // rax
  unsigned int i; // ebp
  CAkMusicSwitchMonitor *v9; // rax
  AKRESULT v10; // eax
  char v11; // al
  unsigned int v12; // edi
  CAkMusicSwitchCtx::TransitionInfo v14; // [rsp+20h] [rbp-48h] BYREF
  CAkMusicSwitchCtx *v15; // [rsp+30h] [rbp-38h]
  CAkMatrixAwareCtx *io_pNewContext; // [rsp+88h] [rbp+20h] BYREF

  v4 = (unsigned int)CAkMatrixAwareCtx::Init(this, in_GameObject, in_rUserparams);
  if ( v4 == AK_Success )
  {
    p_m_switchMonitors = &this->m_switchMonitors;
    if ( this->m_switchMonitors.m_pItems )
    {
      AkArray<CAkMusicSwitchMonitor,CAkMusicSwitchMonitor const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::RemoveAll(&this->m_switchMonitors);
      AK::MemoryMgr::Free(g_DefaultPoolId, p_m_switchMonitors->m_pItems);
      p_m_switchMonitors->m_pItems = 0i64;
      this->m_switchMonitors.m_ulReserved = 0;
    }
    m_uDepth = this->m_pSwitchCntrNode->m_decisionTree.m_uDepth;
    if ( !(_DWORD)m_uDepth )
      goto LABEL_14;
    v7 = (CAkMusicSwitchMonitor *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 24 * m_uDepth);
    p_m_switchMonitors->m_pItems = v7;
    if ( !v7 )
      return 52;
    this->m_switchMonitors.m_ulReserved = m_uDepth;
    v4 = AK_Success;
    for ( i = 0; i < (unsigned int)m_uDepth; ++i )
    {
      CAkSwitchAware::CAkSwitchAware((CAkSwitchAware *)&v14);
      v14.pSeekingInfo = (AkSeekingInfo *)&CAkMusicSwitchMonitor::`vftable;
      v14.eEntryType = -1;
      v15 = 0i64;
      v9 = AkArray<CAkMusicSwitchMonitor,CAkMusicSwitchMonitor const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(&this->m_switchMonitors);
      if ( v9 )
      {
        v9->m_targetSwitchID = *(_DWORD *)&v14.bOverrideEntryType;
        v9->m_uIdx = v14.eEntryType;
        v9->m_pMusicCtx = v15;
      }
      v14.pSeekingInfo = (AkSeekingInfo *)&CAkMusicSwitchMonitor::`vftable;
      CAkSwitchAware::UnsubscribeSwitches((CAkSwitchAware *)&v14);
      CAkSwitchAware::~CAkSwitchAware((CAkSwitchAware *)&v14);
      v10 = CAkMusicSwitchMonitor::Init(&p_m_switchMonitors->m_pItems[i], i, this);
      v4 = v10;
      if ( v10 != AK_Success )
        return (unsigned int)v4;
    }
    if ( v4 == AK_Success )
    {
LABEL_14:
      ++this->m_uRefCount;
      *((_BYTE *)this + 184) |= 2u;
      if ( this->m_pParentCtx )
      {
        return (unsigned int)CAkMusicSwitchCtx::SetInitialSwitch(this, 0);
      }
      else
      {
        v4 = CAkMusicSwitchCtx::SetInitialSwitch(this, 1);
        if ( v4 == AK_Success )
        {
          v11 = *((_BYTE *)&this->CAkMusicCtx + 98);
          *((_BYTE *)this + 184) &= ~1u;
          v14.pSeekingInfo = 0i64;
          v14.bOverrideEntryType = 0;
          if ( (v11 & 0xFu) <= 1 )
          {
            v12 = CAkMusicSwitchCtx::ResolveAudioNode(this);
            io_pNewContext = CAkMusicSwitchCtx::CreateDestinationContext(this, v12);
            if ( io_pNewContext )
            {
              CAkMusicSwitchCtx::ScheduleSwitchTransition(this, v12, &v14, &io_pNewContext);
              if ( io_pNewContext )
                io_pNewContext->CAkMusicCtx::CAkChildCtx::vfptr[1].OnResumed(io_pNewContext);
            }
          }
        }
      }
    }
  }
  return (unsigned int)v4;
}

// File Line: 457
// RVA: 0xAB7F30
void __fastcall CAkMusicSwitchCtx::EndInit(CAkMusicSwitchCtx *this)
{
  CAkMusicSwitchTransition *i; // rbx
  CAkMatrixAwareCtx *m_pT; // rcx

  for ( i = this->m_queueTransitions.m_pFirst; i; i = i->pNextItem )
  {
    m_pT = i->m_pDestCtx.m_pT;
    if ( m_pT )
      m_pT->CAkMusicCtx::CAkChildCtx::vfptr[1].OnResumed(m_pT);
  }
}

// File Line: 469
// RVA: 0xAB8830
void __fastcall CAkMusicSwitchCtx::PerformDelayedSwitchChange(CAkMusicSwitchCtx *this)
{
  char v1; // al
  char v3; // cl
  unsigned int v4; // edi
  CAkMusicSwitchCtx *m_pParentCtx; // rcx
  CAkMusicSwitchTransition *i; // rbx
  CAkMatrixAwareCtx *m_pT; // rcx
  CAkMusicSwitchCtx::TransitionInfo in_transitionInfo; // [rsp+20h] [rbp-18h] BYREF
  CAkMatrixAwareCtx *io_pNewContext; // [rsp+40h] [rbp+8h] BYREF

  v1 = *((_BYTE *)&this->CAkMusicCtx + 98);
  if ( (v1 & 1) != 0 || (v1 & 0xF) == 0 )
  {
    v3 = *((_BYTE *)this + 184);
    if ( (v3 & 1) != 0 )
    {
      in_transitionInfo.pSeekingInfo = 0i64;
      in_transitionInfo.bOverrideEntryType = 0;
      *((_BYTE *)this + 184) = v3 & 0xFE;
      if ( (v1 & 0xFu) <= 1 )
      {
        v4 = CAkMusicSwitchCtx::ResolveAudioNode(this);
        io_pNewContext = CAkMusicSwitchCtx::CreateDestinationContext(this, v4);
        if ( io_pNewContext )
        {
          CAkMusicSwitchCtx::ScheduleSwitchTransition(this, v4, &in_transitionInfo, &io_pNewContext);
          if ( io_pNewContext )
            io_pNewContext->CAkMusicCtx::CAkChildCtx::vfptr[1].OnResumed(io_pNewContext);
        }
      }
    }
    if ( !this->m_itActiveSwitch.pItem->pNextItem )
    {
      m_pParentCtx = (CAkMusicSwitchCtx *)this->m_pParentCtx;
      if ( !m_pParentCtx || !CAkMusicSwitchCtx::HasOrAscendentHasPendingTransition(m_pParentCtx) )
      {
        for ( i = this->m_queueTransitions.m_pFirst; i; i = i->pNextItem )
        {
          m_pT = i->m_pDestCtx.m_pT;
          if ( m_pT )
            m_pT->CAkMusicCtx::CAkChildCtx::vfptr[2].VirtualAddRef(m_pT);
        }
      }
    }
  }
}

// File Line: 491
// RVA: 0xABA160
__int64 __fastcall CAkMusicSwitchCtx::SetInitialSwitch(CAkMusicSwitchCtx *this, bool in_bNothing)
{
  CAkMusicSwitchTransition *m_pFirst; // rax
  CAkMusicSwitchTransition *v4; // rbp
  CAkMusicSwitchTransition *v5; // rdi
  CAkMusicSwitchTransition *pNextItem; // rcx
  unsigned int v7; // eax
  CAkChainCtx *DestinationContext; // rax
  CAkMusicSwitchTransition *v9; // rbx
  CAkMusicSwitchTransition *v10; // rax
  CAkMusicSwitchTransition *v11; // rsi
  CAkMusicCtx *m_pT; // rcx
  CAkMusicCtx *v13; // rcx
  int v14; // r14d
  CAkMusicCtx *v15; // rcx
  __int128 v17; // rax
  __int64 v18; // rcx
  CAkMusicSwitchTransition *v19; // [rsp+20h] [rbp-38h]
  CAkMusicSwitchTransition *v20; // [rsp+30h] [rbp-28h]
  __int128 v21; // [rsp+30h] [rbp-28h]
  CAkMusicSwitchTransition *v22; // [rsp+38h] [rbp-20h]

  m_pFirst = this->m_queueTransitions.m_pFirst;
  v4 = 0i64;
  v5 = 0i64;
  if ( m_pFirst )
  {
    while ( 1 )
    {
      pNextItem = m_pFirst->pNextItem;
      v19 = m_pFirst->pNextItem;
      if ( m_pFirst == this->m_queueTransitions.m_pFirst )
        this->m_queueTransitions.m_pFirst = pNextItem;
      else
        MEMORY[0] = (size_t)m_pFirst->pNextItem;
      if ( m_pFirst == this->m_queueTransitions.m_pLast )
        this->m_queueTransitions.m_pLast = 0i64;
      m_pFirst->pNextItem = 0i64;
      if ( v5 )
        v5->pNextItem = m_pFirst;
      else
        v4 = m_pFirst;
      v5 = m_pFirst;
      if ( !pNextItem )
        break;
      m_pFirst = v19;
    }
  }
  *((_BYTE *)this + 184) &= ~1u;
  if ( in_bNothing )
    v7 = 0;
  else
    v7 = CAkMusicSwitchCtx::ResolveAudioNode(this);
  DestinationContext = CAkMusicSwitchCtx::CreateDestinationContext(this, v7);
  if ( DestinationContext && (unsigned int)CAkMusicSwitchCtx::PrepareFirstContext(this, DestinationContext) == 1 )
  {
    v9 = v4;
    v10 = 0i64;
    if ( v4 )
    {
      while ( 1 )
      {
        v11 = v9->pNextItem;
        v22 = v10;
        v20 = v9->pNextItem;
        if ( v9 == v4 )
          v4 = v9->pNextItem;
        else
          v10->pNextItem = v11;
        m_pT = v9->m_pDestCtx.m_pT;
        if ( v9 == v5 )
          v5 = v10;
        *((_BYTE *)v9 + 72) &= 0xFCu;
        UFG::OnUnloadClass<UITest::HandleArrayTest>(m_pT);
        v13 = v9->m_pDestCtx.m_pT;
        v14 = g_DefaultPoolId;
        v9->m_pDestCtx.m_pT = 0i64;
        if ( v13 )
          CAkMusicCtx::Release(v13);
        v15 = v9->m_pDestCtx.m_pT;
        if ( v15 )
        {
          CAkMusicCtx::Release(v15);
          v9->m_pDestCtx.m_pT = 0i64;
        }
        AK::MemoryMgr::Free(v14, v9);
        if ( !v11 )
          break;
        v10 = v22;
        v9 = v20;
      }
      return 1i64;
    }
    else
    {
      return 1i64;
    }
  }
  else
  {
    v17 = (unsigned __int64)v4;
    if ( v4 )
    {
      while ( 1 )
      {
        v18 = *(_QWORD *)v17;
        *((_QWORD *)&v21 + 1) = *((_QWORD *)&v17 + 1);
        *(_QWORD *)&v21 = *(_QWORD *)v17;
        if ( (CAkMusicSwitchTransition *)v17 == v4 )
          v4 = *(CAkMusicSwitchTransition **)v17;
        else
          **((_QWORD **)&v17 + 1) = v18;
        *(_QWORD *)v17 = 0i64;
        if ( (CAkMusicSwitchTransition *)v17 == v5 )
          v5 = (CAkMusicSwitchTransition *)*((_QWORD *)&v17 + 1);
        *((_QWORD *)&v17 + 1) = this->m_queueTransitions.m_pLast;
        if ( *((_QWORD *)&v17 + 1) )
          **((_QWORD **)&v17 + 1) = v17;
        else
          this->m_queueTransitions.m_pFirst = (CAkMusicSwitchTransition *)v17;
        this->m_queueTransitions.m_pLast = (CAkMusicSwitchTransition *)v17;
        if ( !v18 )
          break;
        v17 = v21;
      }
    }
    return 2i64;
  }
}

// File Line: 577
// RVA: 0xAB8E30
__int64 __fastcall CAkMusicSwitchCtx::ResolveAudioNode(CAkMusicSwitchCtx *this)
{
  __int64 m_uLength; // r9
  __int64 v2; // rbx
  unsigned __int64 v3; // rdx
  signed __int64 v4; // rdx
  void *v5; // rsp
  void *v6; // rsp
  __int64 v7; // rdx
  unsigned int *p_in_pPath; // r10
  unsigned int in_pPath; // [rsp+30h] [rbp+0h] BYREF

  m_uLength = this->m_switchMonitors.m_uLength;
  v2 = m_uLength;
  v3 = 4 * m_uLength + 15;
  if ( v3 <= 4 * m_uLength )
    v3 = 0xFFFFFFFFFFFFFF0i64;
  v4 = v3 & 0xFFFFFFFFFFFFFFF0ui64;
  v5 = alloca(v4);
  v6 = alloca(v4);
  if ( (_DWORD)m_uLength )
  {
    v7 = 0i64;
    p_in_pPath = &in_pPath;
    do
    {
      *p_in_pPath++ = this->m_switchMonitors.m_pItems[v7++].m_targetSwitchID;
      --v2;
    }
    while ( v2 );
  }
  return AkDecisionTree::ResolvePath(
           &this->m_pSwitchCntrNode->m_decisionTree,
           this->m_pSwitchCntrNode->key,
           &in_pPath,
           m_uLength,
           0);
}

// File Line: 623
// RVA: 0xAB89E0
void __fastcall CAkMusicSwitchCtx::Process(
        CAkMusicSwitchCtx *this,
        __int64 in_iCurrentTime,
        CAkTransition **in_uNumSamples,
        AkCutoffInfo *in_cutoffInfo)
{
  unsigned __int64 m_iLocalTime; // rax
  __int64 v6; // rbp
  unsigned int m_uNumLastSamples; // r14d
  CAkMusicSwitchTransition *m_pFirst; // rbx
  __int64 v10; // r15
  CAkMusicSwitchTransition *pItem; // rdi
  __int64 v12; // rcx
  char v13; // dl
  char v14; // cl
  CAkMusicSwitchTransition *pNextItem; // rax
  CAkMusicCtx *v16; // rcx
  int v17; // edi
  CAkMusicCtx *v18; // rcx
  __int64 iCutoffTime; // rcx
  __int64 v20; // rax
  __int64 iRelativeTime; // rax
  __int64 v22; // rax
  CAkMatrixAwareCtx *m_pT; // r10
  char v24; // al
  AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator in_itNewTransition[2]; // [rsp+20h] [rbp-58h] BYREF
  __int64 v26; // [rsp+30h] [rbp-48h] BYREF
  __int64 v27; // [rsp+38h] [rbp-40h]
  __int128 v28; // [rsp+40h] [rbp-38h]

  m_iLocalTime = this->m_iLocalTime;
  in_cutoffInfo->iCutoffTime -= m_iLocalTime;
  ++this->m_uRefCount;
  v6 = in_iCurrentTime - m_iLocalTime;
  m_uNumLastSamples = (unsigned int)in_uNumSamples;
  if ( (*((_BYTE *)&this->CAkMusicCtx + 98) & 2) != 0 && this->m_uNumLastSamples != -1 )
    m_uNumLastSamples = this->m_uNumLastSamples;
  m_pFirst = this->m_queueTransitions.m_pFirst;
  v10 = v6 + m_uNumLastSamples;
  this->m_pLastNonCancelledTransitionInFrame = 0i64;
  in_itNewTransition[0].pItem = m_pFirst;
  pItem = 0i64;
  in_itNewTransition[1].pItem = 0i64;
  while ( m_pFirst )
  {
    v12 = m_pFirst->m_pDestCtx.m_pT->m_iLocalTime;
    if ( v6 <= v12 && v10 > v12 )
      CAkMusicSwitchCtx::Sync(this, in_itNewTransition);
    v13 = *((_BYTE *)m_pFirst + 72);
    if ( (v13 & 2) != 0
      || (v14 = *((_BYTE *)&m_pFirst->m_pDestCtx.m_pT->CAkMusicCtx + 98), (v14 & 3) != 0) && (v14 & 0x10) == 0
      || (v13 & 1) != 0 )
    {
      iCutoffTime = in_cutoffInfo->iCutoffTime;
      v20 = *(_QWORD *)&in_cutoffInfo->bCutoff;
      v26 = in_cutoffInfo->iCutoffTime;
      v27 = v20;
      if ( (v13 & 1) != 0 )
      {
        iRelativeTime = m_pFirst->m_cmdPlay.iRelativeTime;
        if ( v6 <= iRelativeTime && v10 > iRelativeTime )
        {
          CAkMusicCtx::_Play(m_pFirst->m_pDestCtx.m_pT, &m_pFirst->m_cmdPlay.fadeParams, in_uNumSamples);
          *((_BYTE *)m_pFirst + 72) &= ~1u;
          iCutoffTime = v26;
        }
      }
      if ( (*((_BYTE *)m_pFirst + 72) & 2) != 0 )
      {
        v22 = m_pFirst->m_cmdStop.iRelativeTime;
        if ( v10 > v22 && v6 <= v22 )
        {
          CAkMusicCtx::_Stop(
            m_pFirst->m_pDestCtx.m_pT,
            &m_pFirst->m_cmdStop.transParams,
            (CAkTransition **)(unsigned int)(v22 - v6));
          *((_BYTE *)m_pFirst + 72) &= ~2u;
          iCutoffTime = v26;
        }
      }
      m_pT = m_pFirst->m_pDestCtx.m_pT;
      v24 = *((_BYTE *)&m_pT->CAkMusicCtx + 98);
      if ( (v24 & 3) != 0 && (v24 & 0x10) == 0 )
      {
        if ( m_pFirst->m_cutoffInfo.bCutoff )
        {
          if ( (_BYTE)v27 )
          {
            if ( m_pFirst->m_cutoffInfo.iCutoffTime < iCutoffTime )
              iCutoffTime = m_pFirst->m_cutoffInfo.iCutoffTime;
            v26 = iCutoffTime;
          }
          else
          {
            v26 = m_pFirst->m_cutoffInfo.iCutoffTime;
            LOBYTE(v27) = 1;
          }
        }
        ((void (__fastcall *)(CAkMatrixAwareCtx *, __int64, _QWORD, __int64 *))m_pT->CAkMusicCtx::CAkChildCtx::vfptr[1].SetPBIFade)(
          m_pT,
          v6,
          m_uNumLastSamples,
          &v26);
      }
    }
    else if ( m_pFirst != this->m_itActiveSwitch.pItem )
    {
      pNextItem = m_pFirst->pNextItem;
      *((_QWORD *)&v28 + 1) = pItem;
      *(_QWORD *)&v28 = pNextItem;
      if ( m_pFirst == this->m_queueTransitions.m_pFirst )
        this->m_queueTransitions.m_pFirst = pNextItem;
      else
        pItem->pNextItem = pNextItem;
      if ( m_pFirst == this->m_queueTransitions.m_pLast )
        this->m_queueTransitions.m_pLast = pItem;
      v16 = m_pFirst->m_pDestCtx.m_pT;
      v17 = g_DefaultPoolId;
      *(_OWORD *)&in_itNewTransition[0].pItem = v28;
      m_pFirst->m_pDestCtx.m_pT = 0i64;
      if ( v16 )
        CAkMusicCtx::Release(v16);
      v18 = m_pFirst->m_pDestCtx.m_pT;
      if ( v18 )
      {
        CAkMusicCtx::Release(v18);
        m_pFirst->m_pDestCtx.m_pT = 0i64;
      }
      AK::MemoryMgr::Free(v17, m_pFirst);
      pItem = in_itNewTransition[1].pItem;
      m_pFirst = in_itNewTransition[0].pItem;
      continue;
    }
    pItem = m_pFirst;
    in_itNewTransition[1].pItem = m_pFirst;
    m_pFirst = m_pFirst->pNextItem;
    in_itNewTransition[0].pItem = m_pFirst;
  }
  CAkMatrixAwareCtx::ProcessEpilogue(this, v6, m_uNumLastSamples);
}

// File Line: 676
// RVA: 0xAB8910
__int64 __fastcall CAkMusicSwitchCtx::Prepare(
        CAkMusicSwitchCtx *this,
        AkMusicTransDestRule *in_pRule,
        __int64 in_iMinStartPosition,
        AkSeekingInfo *in_pSeekingInfo,
        unsigned int *out_uSelectedCue,
        unsigned int in_uCueHashForMatchSrc)
{
  return ((__int64 (__fastcall *)(CAkMatrixAwareCtx *, AkMusicTransDestRule *, __int64, AkSeekingInfo *))this->m_queueTransitions.m_pFirst->m_pDestCtx.m_pT->vfptr[1].VirtualAddRef)(
           this->m_queueTransitions.m_pFirst->m_pDestCtx.m_pT,
           in_pRule,
           in_iMinStartPosition,
           in_pSeekingInfo);
}

// File Line: 690
// RVA: 0xAB8C30
void __fastcall CAkMusicSwitchCtx::QueryLookAheadInfo(
        CAkMusicSwitchCtx *this,
        __int64 *out_iPlayTime,
        __int64 *out_iPlayTimeAudible)
{
  CAkMusicSwitchTransition *m_pFirst; // rbx
  CAkMusicSwitchTransition *i; // rbx
  __int64 v7; // rcx
  __int64 v8; // rcx
  __int64 v9; // [rsp+30h] [rbp+8h] BYREF
  __int64 v10; // [rsp+48h] [rbp+20h] BYREF

  m_pFirst = this->m_queueTransitions.m_pFirst;
  if ( m_pFirst )
  {
    if ( !this->m_pParentCtx && m_pFirst->pNextItem )
      m_pFirst = m_pFirst->pNextItem;
    ((void (__fastcall *)(CAkMatrixAwareCtx *, __int64 *, __int64 *))m_pFirst->m_pDestCtx.m_pT->vfptr[2].OnLastFrame)(
      m_pFirst->m_pDestCtx.m_pT,
      &v9,
      &v10);
    *out_iPlayTime = v9 + m_pFirst->m_pDestCtx.m_pT->m_iLocalTime;
    *out_iPlayTimeAudible = v10 + m_pFirst->m_pDestCtx.m_pT->m_iLocalTime;
    for ( i = m_pFirst->pNextItem; i; i = i->pNextItem )
    {
      ((void (__fastcall *)(CAkMatrixAwareCtx *, __int64 *, __int64 *))i->m_pDestCtx.m_pT->vfptr[2].OnLastFrame)(
        i->m_pDestCtx.m_pT,
        &v9,
        &v10);
      v7 = i->m_pDestCtx.m_pT->m_iLocalTime + v9;
      v9 = v7;
      if ( v7 < *out_iPlayTime )
        *out_iPlayTime = v7;
      v8 = i->m_pDestCtx.m_pT->m_iLocalTime + v10;
      v10 = v8;
      if ( v8 < *out_iPlayTimeAudible )
        *out_iPlayTimeAudible = v8;
    }
  }
  else
  {
    *out_iPlayTime = 0i64;
    *out_iPlayTimeAudible = 0i64;
  }
}

// File Line: 738
// RVA: 0xAB7C00
bool __fastcall CAkMusicSwitchCtx::CanRestartPlaying(CAkMusicSwitchCtx *this)
{
  char v1; // al

  v1 = *((_BYTE *)&this->CAkMusicCtx + 98);
  if ( (v1 & 1) != 0 || (v1 & 0xF) == 0 )
    return ((__int64 (__fastcall *)(CAkMatrixAwareCtx *))this->m_queueTransitions.m_pLast->m_pDestCtx.m_pT->vfptr[2].OnResumed)(this->m_queueTransitions.m_pLast->m_pDestCtx.m_pT);
  else
    return 0;
}

// File Line: 750
// RVA: 0xAB7C90
void __fastcall CAkMusicSwitchCtx::CancelPlayback(CAkMusicSwitchCtx *this, __int64 in_iCurrentTime)
{
  char v2; // al
  double v4; // xmm1_8
  double v5; // xmm0_8
  TransParams in_transParams; // [rsp+30h] [rbp+8h] BYREF

  v2 = *((_BYTE *)&this->CAkMusicCtx + 98);
  ++this->m_uRefCount;
  if ( (v2 & 0xF) != 0 )
  {
    if ( (v2 & 1) != 0 )
    {
      v4 = (double)(LODWORD(this->m_iLocalTime) - (int)in_iCurrentTime)
         * 1000.0
         / (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency;
      if ( v4 <= 0.0 )
        v5 = DOUBLE_N0_5;
      else
        v5 = DOUBLE_0_5;
      in_transParams.eFadeCurve = AkCurveInterpolation_Linear;
      in_transParams.TransitionTime = (int)(v5 + v4);
      CAkMusicCtx::_Stop(this, &in_transParams, (CAkTransition **)0xFFFFFFFFi64);
    }
    CAkMusicCtx::Release(this);
  }
  else
  {
    ((void (__fastcall *)(CAkMusicSwitchCtx *, __int64))this->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr[1].OnPaused)(
      this,
      in_iCurrentTime);
    CAkMusicCtx::Release(this);
  }
}

// File Line: 777
// RVA: 0xAB7FC0
void __fastcall CAkMusicSwitchCtx::GetNextScheduleWindow(
        CAkMusicSwitchCtx *this,
        CAkScheduleWindow *io_window,
        bool in_bDoNotGrow)
{
  CAkMusicSwitchTransition *pItem; // rax
  CAkMusicSwitchTransition *pNextItem; // rax
  signed __int64 m_iLocalTime; // rdi
  CAkMusicSwitchTransition *v9; // rax
  unsigned __int64 v10; // rdi
  AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator in_itTrans; // [rsp+38h] [rbp+10h] BYREF
  AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator v12; // [rsp+48h] [rbp+20h] BYREF

  ++io_window->m_uLevel;
  CAkScheduleWindow::GetBranch(io_window, (CAkMusicSwitchTransition *)&in_itTrans);
  pItem = in_itTrans.pItem;
  if ( !in_itTrans.pItem )
  {
    if ( this->m_itActiveSwitch.pItem )
    {
      in_itTrans.pItem = this->m_itActiveSwitch.pItem;
      CAkScheduleWindow::SetBranch(io_window, &in_itTrans);
      pItem = in_itTrans.pItem;
    }
    else if ( !io_window->m_itScheduledItem.pItem )
    {
      goto LABEL_13;
    }
  }
  ((void (__fastcall *)(CAkMatrixAwareCtx *, CAkScheduleWindow *, bool))pItem->m_pDestCtx.m_pT->vfptr[1].VirtualRelease)(
    pItem->m_pDestCtx.m_pT,
    io_window,
    in_bDoNotGrow);
  pNextItem = in_itTrans.pItem->pNextItem;
  in_itTrans.pItem = pNextItem;
  v12.pItem = pNextItem;
  if ( pNextItem )
  {
    m_iLocalTime = pNextItem->m_pDestCtx.m_pT->m_iLocalTime;
    if ( (__int64)CAkScheduleWindow::StartTimeRelativeToCurrentLevel(io_window) < m_iLocalTime )
    {
LABEL_9:
      if ( v12.pItem )
      {
        v10 = m_iLocalTime - CAkScheduleWindow::StartTimeRelativeToCurrentLevel(io_window);
        if ( io_window->m_bIsDurationInfinite || io_window->m_uWindowDuration > v10 )
          CAkScheduleWindow::SetDuration(io_window, v10, 0);
      }
    }
    else
    {
      while ( 1 )
      {
        CAkScheduleWindow::SetBranch(io_window, &v12);
        ((void (__fastcall *)(CAkMatrixAwareCtx *, CAkScheduleWindow *, bool))v12.pItem->m_pDestCtx.m_pT->vfptr[1].VirtualRelease)(
          v12.pItem->m_pDestCtx.m_pT,
          io_window,
          in_bDoNotGrow);
        v9 = v12.pItem->pNextItem;
        v12.pItem = v9;
        if ( !v9 )
          break;
        m_iLocalTime = v9->m_pDestCtx.m_pT->m_iLocalTime;
        if ( (__int64)CAkScheduleWindow::StartTimeRelativeToCurrentLevel(io_window) < m_iLocalTime )
          goto LABEL_9;
      }
    }
  }
LABEL_13:
  --io_window->m_uLevel;
}

// File Line: 851
// RVA: 0xAB8D20
void __fastcall CAkMusicSwitchCtx::RefreshWindow(CAkMusicSwitchCtx *this, CAkScheduleWindow *io_window)
{
  __int64 v3; // rax
  __int64 v4; // rdi
  unsigned __int64 v5; // rdi
  __int64 v6; // [rsp+38h] [rbp+10h] BYREF

  ++io_window->m_uLevel;
  CAkScheduleWindow::GetBranch(io_window, (CAkMusicSwitchTransition *)&v6);
  (*(void (__fastcall **)(_QWORD, CAkScheduleWindow *))(**(_QWORD **)(v6 + 8) + 104i64))(*(_QWORD *)(v6 + 8), io_window);
  v3 = *(_QWORD *)v6;
  v6 = v3;
  if ( v3 )
  {
    v4 = *(_QWORD *)(*(_QWORD *)(v3 + 8) + 112i64);
    v5 = v4 - CAkScheduleWindow::StartTimeRelativeToCurrentLevel(io_window);
    if ( io_window->m_bIsDurationInfinite || io_window->m_uWindowDuration > v5 )
      CAkScheduleWindow::SetDuration(io_window, v5, 0);
    --io_window->m_uLevel;
  }
  else
  {
    --io_window->m_uLevel;
  }
}

// File Line: 919
// RVA: 0xAB8640
void __fastcall CAkMusicSwitchCtx::OnPlayed(CAkMusicSwitchCtx *this, __int64 a2, CAkTransition **a3)
{
  CAkMusicSwitchTransition *m_pFirst; // rcx
  AkMusicFade in_fadeParams; // [rsp+20h] [rbp-18h] BYREF

  if ( (*((_BYTE *)&this->CAkMusicCtx + 98) & 0xF) == 0 )
  {
    this->m_queueTransitions.m_pFirst->m_pDestCtx.m_pT->m_iLocalTime = 0i64;
    m_pFirst = this->m_queueTransitions.m_pFirst;
    in_fadeParams.transitionTime = 0;
    *(_QWORD *)&in_fadeParams.eFadeCurve = 4i64;
    CAkMusicCtx::_Play(m_pFirst->m_pDestCtx.m_pT, &in_fadeParams, a3);
  }
  CAkMusicCtx::OnPlayed(this);
}

// File Line: 937
// RVA: 0xAB8690
void __fastcall CAkMusicSwitchCtx::OnStopped(CAkMusicSwitchCtx *this)
{
  CAkMusicSwitchTransition *m_pFirst; // rbx
  CAkMusicSwitchTransition *v3; // rax
  CAkMusicSwitchTransition *pNextItem; // rsi
  CAkMusicCtx *m_pT; // rcx
  int v6; // ebp
  CAkMusicCtx *v7; // rcx
  CAkMusicSwitchTransition *v8; // rax
  char v9; // al
  CAkMusicSwitchTransition *v10; // [rsp+20h] [rbp-28h]
  CAkMusicSwitchTransition *v11; // [rsp+28h] [rbp-20h]

  ++this->m_uRefCount;
  if ( this->m_switchMonitors.m_pItems )
  {
    AkArray<CAkMusicSwitchMonitor,CAkMusicSwitchMonitor const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::RemoveAll(&this->m_switchMonitors);
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_switchMonitors.m_pItems);
    this->m_switchMonitors.m_pItems = 0i64;
    this->m_switchMonitors.m_ulReserved = 0;
  }
  m_pFirst = this->m_queueTransitions.m_pFirst;
  v3 = 0i64;
  if ( m_pFirst )
  {
    while ( 1 )
    {
      pNextItem = m_pFirst->pNextItem;
      v11 = v3;
      v10 = m_pFirst->pNextItem;
      if ( m_pFirst == this->m_queueTransitions.m_pFirst )
        this->m_queueTransitions.m_pFirst = pNextItem;
      else
        v3->pNextItem = pNextItem;
      if ( m_pFirst == this->m_queueTransitions.m_pLast )
        this->m_queueTransitions.m_pLast = v3;
      m_pT = m_pFirst->m_pDestCtx.m_pT;
      v6 = g_DefaultPoolId;
      m_pFirst->m_pDestCtx.m_pT = 0i64;
      if ( m_pT )
        CAkMusicCtx::Release(m_pT);
      v7 = m_pFirst->m_pDestCtx.m_pT;
      if ( v7 )
      {
        CAkMusicCtx::Release(v7);
        m_pFirst->m_pDestCtx.m_pT = 0i64;
      }
      AK::MemoryMgr::Free(v6, m_pFirst);
      if ( !pNextItem )
        break;
      v3 = v11;
      m_pFirst = v10;
    }
  }
  v8 = this->m_queueTransitions.m_pFirst;
  this->m_queueTransitions.m_pFirst = 0i64;
  this->m_itActiveSwitch.pItem = v8;
  this->m_queueTransitions.m_pLast = 0i64;
  v9 = *((_BYTE *)this + 184);
  if ( (v9 & 2) != 0 )
  {
    *((_BYTE *)this + 184) = v9 & 0xFD;
    CAkMusicCtx::Release(this);
  }
  CAkMatrixAwareCtx::OnStopped(this);
  CAkMusicCtx::Release(this);
}

// File Line: 966
// RVA: 0xAB8630
CAkMusicSwitchCntr *__fastcall CAkMusicSwitchCtx::Node(CAkMusicSwitchCtx *this)
{
  return this->m_pSwitchCntrNode;
}

// File Line: 974
// RVA: 0xABA4B0
void __fastcall CAkMusicSwitchCtx::Sync(
        CAkMusicSwitchCtx *this,
        AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator *in_itNewTransition)
{
  CAkMusicSegment *Node; // rax
  CAkMusicNode *v4; // rcx
  CAkParameterNodeBase **MusicGrid; // rax
  CAkMusicSwitchCtx *m_pParentCtx; // rcx
  CAkMusicSwitchTransition *i; // rbx
  CAkMatrixAwareCtx *m_pT; // rcx
  CAkScheduleWindow v9; // [rsp+20h] [rbp-138h] BYREF
  CAkMusicNode *out_ppParentNode; // [rsp+160h] [rbp+8h] BYREF

  this->m_itActiveSwitch = (AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator)in_itNewTransition->pItem;
  if ( (CAkMatrixSequencer::GetMusicSyncFlags(this->m_pSequencer) & 0x4000) != 0 )
  {
    CAkScheduleWindow::CAkScheduleWindow(&v9, this, 0);
    if ( v9.m_itScheduledItem.pItem )
    {
      Node = CAkScheduleWindow::GetNode(&v9, &out_ppParentNode);
      v4 = out_ppParentNode;
      if ( Node )
        v4 = Node;
      MusicGrid = CAkMusicNode::GetMusicGrid(v4);
      CAkPlayingMgr::NotifyMusic(
        g_pPlayingMgr,
        this->m_pSequencer->m_UserParams.m_PlayingID,
        0x4000u,
        (AkMusicGrid *)MusicGrid);
    }
    _((AMD_HD3D *)&v9);
  }
  if ( !this->m_itActiveSwitch.pItem->pNextItem )
  {
    m_pParentCtx = (CAkMusicSwitchCtx *)this->m_pParentCtx;
    if ( !m_pParentCtx || !CAkMusicSwitchCtx::HasOrAscendentHasPendingTransition(m_pParentCtx) )
    {
      for ( i = this->m_queueTransitions.m_pFirst; i; i = i->pNextItem )
      {
        m_pT = i->m_pDestCtx.m_pT;
        if ( m_pT )
          m_pT->CAkMusicCtx::CAkChildCtx::vfptr[2].VirtualAddRef(m_pT);
      }
    }
  }
}

// File Line: 1014
// RVA: 0xABA590
void __fastcall CAkMusicSwitchCtx::TryPropagateDelayedSwitchChange(CAkMusicSwitchCtx *this)
{
  CAkMusicSwitchCtx *m_pParentCtx; // rcx
  CAkMusicSwitchTransition *i; // rbx
  CAkMatrixAwareCtx *m_pT; // rcx

  if ( !this->m_itActiveSwitch.pItem->pNextItem )
  {
    m_pParentCtx = (CAkMusicSwitchCtx *)this->m_pParentCtx;
    if ( !m_pParentCtx || !CAkMusicSwitchCtx::HasOrAscendentHasPendingTransition(m_pParentCtx) )
    {
      for ( i = this->m_queueTransitions.m_pFirst; i; i = i->pNextItem )
      {
        m_pT = i->m_pDestCtx.m_pT;
        if ( m_pT )
          m_pT->CAkMusicCtx::CAkChildCtx::vfptr[2].VirtualAddRef(m_pT);
      }
    }
  }
}

// File Line: 1033
// RVA: 0xAB7D80
CAkChainCtx *__fastcall CAkMusicSwitchCtx::CreateDestinationContext(CAkMusicSwitchCtx *this, unsigned int in_ID)
{
  CAkChainCtx *result; // rax
  CAkChainCtx *v4; // rax
  CAkChainCtx *v5; // rbx
  __int64 v6; // rax

  if ( !in_ID || (result = (CAkChainCtx *)CAkMusicSwitchCtx::CreateMusicContext(this, in_ID)) == 0i64 )
  {
    v4 = (CAkChainCtx *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xA0ui64);
    v5 = v4;
    if ( v4 )
    {
      CAkChainCtx::CAkChainCtx(v4, this);
      LOBYTE(v5[1].CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr) = 0;
      v5->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr = (CAkChildCtxVtbl *)&CAkNothingCtx::`vftable{for `CAkChildCtx};
      v5->CAkMatrixAwareCtx::CAkMusicCtx::CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkNothingCtx::`vftable{for `CAkTransportAware};
      v5->CAkMatrixAwareCtx::CAkMusicCtx::ITransitionable::vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable{for `ITransitionable};
      ++v5->m_uRefCount;
      if ( (unsigned int)CAkMatrixAwareCtx::Init(v5, this->m_pSequencer->m_pGameObj, &this->m_pSequencer->m_UserParams) == 1 )
      {
        CAkChainCtx::EnqueueItem(v5, 0i64, 0i64);
        if ( v6 )
        {
          ++v5->m_uRefCount;
          LOBYTE(v5[1].CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr) = 1;
          CAkMusicCtx::Release(v5);
          return v5;
        }
      }
      UFG::OnUnloadClass<UITest::HandleArrayTest>(v5);
      CAkMusicCtx::Release(v5);
    }
    return 0i64;
  }
  return result;
}

// File Line: 1071
// RVA: 0xAB7E60
CAkParameterNodeBase *__fastcall CAkMusicSwitchCtx::CreateMusicContext(CAkMusicSwitchCtx *this, unsigned int in_ID)
{
  CAkParameterNodeBase *result; // rax
  CAkMatrixAwareCtx *v4; // rdi
  __int64 v5; // rbx

  result = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_ID, AkNodeType_Default);
  v4 = (CAkMatrixAwareCtx *)result;
  if ( result )
  {
    v5 = ((__int64 (__fastcall *)(CAkParameterNodeBase *, CAkMusicSwitchCtx *, CAkRegisteredObj *, UserParams *))result->vfptr[21].__vecDelDtor)(
           result,
           this,
           this->m_pSequencer->m_pGameObj,
           &this->m_pSequencer->m_UserParams);
    v4->CAkMusicCtx::CAkChildCtx::vfptr->OnResumed(v4);
    return (CAkParameterNodeBase *)v5;
  }
  return result;
}

// File Line: 1094
// RVA: 0xAB8F30
void __fastcall CAkMusicSwitchCtx::ScheduleSwitchTransition(
        CAkMusicSwitchCtx *this,
        unsigned int in_destinationID,
        CAkMusicSwitchCtx::TransitionInfo *in_transitionInfo,
        CAkMusicCtx **io_pNewContext)
{
  CAkMatrixSequencer *m_pSequencer; // rax
  unsigned __int64 m_iLocalTime; // rbx
  CAkMatrixAwareCtx *m_pParentCtx; // rcx
  unsigned __int64 m_uTime; // rsi
  CAkMusicCtx **v9; // r14
  CAkMusicSwitchTransition *v10; // r13
  CAkMusicSwitchTransition *v11; // r15
  CAkMusicSwitchTransition *m_pLastNonCancelledTransitionInFrame; // rax
  __int64 iCutoffTime; // r12
  CAkMusicSwitchTransition *v14; // rsi
  CAkMusicSwitchTransition *i; // rcx
  CAkMusicSwitchTransition *pNextItem; // rax
  CAkMusicSwitchTransition *v17; // rdx
  __int128 v18; // xmm0
  CAkMusicSwitchTransition *LastNonCancellableTransition; // rax
  CAkMusicSwitchCntr *m_pSwitchCntrNode; // rcx
  CAkMusicSwitchTransition *v21; // rbx
  __int64 v22; // rax
  bool v23; // zf
  CAkMusicSwitchTransition *m_pFirst; // rax
  CAkMusicCtx *v25; // r12
  AkMusicTransitionRule *TransitionRule; // rax
  CAkMusicCtx *v27; // r14
  AkMusicTransitionRule *v28; // rbx
  unsigned int *p_segmentID; // rax
  unsigned int v30; // edx
  CAkParameterNodeBase *NodePtrAndAddRef; // rax
  CAkParameterNodeBase *v32; // r14
  CAkMatrixAwareCtx *v33; // rax
  CAkIndexableVtbl *vfptr; // rdx
  CAkMatrixAwareCtx *v35; // r14
  CAkMatrixAwareCtx *v36; // r14
  CAkMusicSwitchTransition *v37; // rax
  CAkMusicSwitchTransition *v38; // rax
  int v39; // edx
  int transitionTime; // r14d
  int iFadeOffset; // r15d
  AkCurveInterpolation eFadeCurve; // eax
  int v43; // eax
  unsigned int v44; // eax
  unsigned int uJumpToID; // eax
  AkMusicTransitionObject *pTransObj; // rcx
  int v47; // eax
  AkMusicTransitionObject *v48; // rcx
  AkCurveInterpolation v49; // eax
  int v50; // ebx
  unsigned int v51; // r12d
  CAkMusicSegment *FirstSegmentNode; // rax
  int active; // r8d
  int v54; // eax
  int v55; // r14d
  int v56; // edx
  int pItem; // r12d
  __int64 v58; // rcx
  int v59; // eax
  __int64 v60; // rbx
  int v61; // eax
  __int64 v62; // rbx
  unsigned int v63; // eax
  AkSyncType v64; // ecx
  bool in_bDoSkipEntryCue; // al
  AKRESULT SyncPoint; // r14d
  CAkMusicSwitchTransition *k; // rcx
  CAkMusicSwitchTransition *transParams; // rax
  CAkMusicSwitchTransition *v69; // rdx
  unsigned __int128 v70; // xmm0
  bool v71; // al
  __int16 v72; // cx
  CAkMusicSwitchTransition *v73; // rbx
  unsigned __int64 v74; // rax
  unsigned int v75; // eax
  int v76; // eax
  CAkMusicSegment *v77; // rax
  AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator v78; // rax
  CAkMusicSwitchTransition *v79; // rcx
  CAkMusicSwitchTransition *v80; // rbx
  CAkMusicSwitchTransition *v81; // rax
  CAkMusicSwitchTransition *v82; // rdx
  __int128 v83; // xmm0
  __int64 v84; // rax
  __int64 v86; // rbx
  CAkMusicSwitchTransition *v87; // rcx
  CAkMusicSwitchTransition *m_pLast; // rbx
  char v89; // al
  int v90; // eax
  CAkMusicCtx *m_pT; // rcx
  CAkTransition **v92; // r8
  CAkMusicSwitchTransition *m; // rcx
  CAkMusicSwitchTransition *v94; // rax
  CAkMusicSwitchTransition *v95; // rdx
  __int128 v96; // xmm0
  CAkMusicSwitchTransition *v97; // rbx
  char v98; // al
  int v99; // eax
  CAkMusicCtx *v100; // rcx
  CAkTransition **v101; // r8
  CAkMusicSwitchTransition *v102; // rbx
  CAkMusicSwitchTransition *iRelativeTime; // rax
  TransParams v104; // rdi
  __int128 v105; // xmm0
  CAkMusicCtx *v106; // rcx
  CAkMusicCtx *v107; // rcx
  int v108; // r14d
  CAkMusicCtx *v109; // rcx
  int in_iDestinationLookAhead; // [rsp+50h] [rbp-B0h]
  AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator in_itTrans; // [rsp+58h] [rbp-A8h] BYREF
  AkSyncType in_eSyncType; // [rsp+60h] [rbp-A0h]
  unsigned int io_uCueFilter; // [rsp+64h] [rbp-9Ch] BYREF
  CAkMatrixAwareCtx *v114; // [rsp+68h] [rbp-98h]
  CAkMusicSwitchTransition *in_pNewTransition; // [rsp+70h] [rbp-90h]
  __int64 in_iCurrentTime; // [rsp+78h] [rbp-88h]
  AkMusicTransDestRule v117; // [rsp+80h] [rbp-80h] BYREF
  char v118[4]; // [rsp+98h] [rbp-68h] BYREF
  int v119; // [rsp+9Ch] [rbp-64h]
  AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator v120; // [rsp+A0h] [rbp-60h] BYREF
  CAkMusicSwitchTransition v121; // [rsp+B0h] [rbp-50h] BYREF
  unsigned int uCueFilterHash; // [rsp+100h] [rbp+0h]
  unsigned int io_uSrcSegmentLookAhead; // [rsp+104h] [rbp+4h] BYREF
  AkMusicTransDestRule in_ruleTo; // [rsp+108h] [rbp+8h] BYREF
  AkListBareLight<AkAssociatedAction,AkListBareLightNextItem<AkAssociatedAction> > in_listActions; // [rsp+120h] [rbp+20h] BYREF
  unsigned int v126; // [rsp+128h] [rbp+28h] BYREF
  CAkMusicSwitchTransition out_iSyncTime; // [rsp+130h] [rbp+30h] BYREF
  unsigned __int128 v128; // [rsp+180h] [rbp+80h]
  CAkScheduleWindow in_source; // [rsp+190h] [rbp+90h] BYREF
  CAkScheduleWindow v130; // [rsp+2C0h] [rbp+1C0h] BYREF
  char j; // [rsp+440h] [rbp+340h]

  m_pSequencer = this->m_pSequencer;
  m_iLocalTime = this->m_iLocalTime;
  m_pParentCtx = (CAkMatrixAwareCtx *)this->m_pParentCtx;
  m_uTime = m_pSequencer->m_uTime;
  v9 = io_pNewContext;
  if ( m_pParentCtx )
    m_iLocalTime += CAkMatrixAwareCtx::GetAbsoluteTimeOffset(m_pParentCtx);
  v10 = 0i64;
  v11 = 0i64;
  in_pNewTransition = 0i64;
  in_iCurrentTime = m_uTime - m_iLocalTime;
  CAkScheduleWindow::CAkScheduleWindow(&in_source, this, 0);
  if ( !in_source.m_itScheduledItem.pItem )
  {
    UFG::OnUnloadClass<UITest::HandleArrayTest>(*v9);
    *v9 = 0i64;
    goto LABEL_215;
  }
  m_pLastNonCancelledTransitionInFrame = this->m_pLastNonCancelledTransitionInFrame;
  v121.m_cutoffInfo.iCutoffTime = 0i64;
  iCutoffTime = 0i64;
  v14 = 0i64;
  if ( m_pLastNonCancelledTransitionInFrame )
  {
    for ( i = this->m_queueTransitions.m_pFirst; i; i = i->pNextItem )
    {
      if ( i == m_pLastNonCancelledTransitionInFrame )
        break;
    }
    pNextItem = i->pNextItem;
    if ( i->pNextItem )
    {
      while ( 1 )
      {
        v17 = pNextItem->pNextItem;
        *(_OWORD *)&v121.pNextItem = __PAIR128__((unsigned __int64)i, pNextItem->pNextItem);
        if ( pNextItem == this->m_queueTransitions.m_pFirst )
          this->m_queueTransitions.m_pFirst = v17;
        else
          i->pNextItem = v17;
        if ( pNextItem == this->m_queueTransitions.m_pLast )
          this->m_queueTransitions.m_pLast = i;
        v18 = *(_OWORD *)&v121.pNextItem;
        pNextItem->pNextItem = 0i64;
        *(_OWORD *)&out_iSyncTime.pNextItem = v18;
        if ( v14 )
          v14->pNextItem = pNextItem;
        else
          iCutoffTime = (__int64)pNextItem;
        v14 = pNextItem;
        if ( !v17 )
          break;
        i = (CAkMusicSwitchTransition *)out_iSyncTime.m_pDestCtx.m_pT;
        pNextItem = out_iSyncTime.pNextItem;
      }
      v121.m_cutoffInfo.iCutoffTime = iCutoffTime;
    }
    ((void (__fastcall *)(CAkMusicSwitchCtx *, CAkScheduleWindow *))this->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr[1].~CAkChildCtx)(
      this,
      &in_source);
  }
  LastNonCancellableTransition = CAkMusicSwitchCtx::FindLastNonCancellableTransition(this);
  m_pSwitchCntrNode = this->m_pSwitchCntrNode;
  v21 = LastNonCancellableTransition;
  *(_QWORD *)&out_iSyncTime.m_cmdPlay.fadeParams.transitionTime = LastNonCancellableTransition;
  if ( !m_pSwitchCntrNode->m_bIsContinuePlayback
    || in_transitionInfo->pSeekingInfo
    || ((v22 = ((__int64 (__fastcall *)(CAkMatrixAwareCtx *))LastNonCancellableTransition->m_pDestCtx.m_pT->vfptr[2].OnPaused)(LastNonCancellableTransition->m_pDestCtx.m_pT)) == 0
      ? (v23 = in_destinationID == 0)
      : (v23 = *(_DWORD *)(v22 + 16) == in_destinationID),
        !v23) )
  {
    if ( ((unsigned __int8 (__fastcall *)(CAkMatrixAwareCtx *))v21->m_pDestCtx.m_pT->vfptr[2].OnResumed)(v21->m_pDestCtx.m_pT) )
    {
      m_pFirst = this->m_queueTransitions.m_pFirst;
      ++in_source.m_uLevel;
      for ( j = 1; m_pFirst; m_pFirst = m_pFirst->pNextItem )
      {
        if ( m_pFirst == v21 )
          break;
      }
      in_itTrans.pItem = m_pFirst;
      if ( CAkScheduleWindow::GetBranch(&in_source, &out_iSyncTime).pItem->pNextItem != m_pFirst )
      {
        CAkScheduleWindow::SetBranch(&in_source, &in_itTrans);
        ((void (__fastcall *)(CAkMatrixAwareCtx *, CAkScheduleWindow *, _QWORD))in_itTrans.pItem->m_pDestCtx.m_pT->vfptr[1].VirtualRelease)(
          in_itTrans.pItem->m_pDestCtx.m_pT,
          &in_source,
          0i64);
      }
      --in_source.m_uLevel;
      v25 = 0i64;
      in_listActions.m_pFirst = 0i64;
      io_uSrcSegmentLookAhead = 0;
      while ( 1 )
      {
        if ( (*((_BYTE *)in_source.m_itScheduledItem.pItem + 60) & 4) != 0 )
        {
LABEL_169:
          if ( j )
          {
            if ( v10 )
            {
              v87 = v10;
              if ( v11 )
              {
                CAkMusicSwitchTransition::Cancel(v10);
                v87 = v11;
              }
              CAkMusicSwitchTransition::Dispose(v87);
            }
            if ( *v9 )
            {
              UFG::OnUnloadClass<UITest::HandleArrayTest>(*v9);
              *v9 = 0i64;
            }
            if ( ((unsigned __int8 (__fastcall *)(CAkMatrixAwareCtx *))this->m_queueTransitions.m_pLast->m_pDestCtx.m_pT->vfptr[2].OnResumed)(this->m_queueTransitions.m_pLast->m_pDestCtx.m_pT) )
            {
              m_pLast = this->m_queueTransitions.m_pLast;
              v89 = *((_BYTE *)m_pLast + 72);
              if ( (v89 & 4) == 0 || (v89 & 2) != 0 )
              {
                *((_BYTE *)m_pLast + 72) = v89 & 0xFD;
              }
              else
              {
                v90 = AkTimeConv::SamplesToMilliseconds((int)in_iCurrentTime - LODWORD(m_pLast->m_cmdStop.iRelativeTime));
                m_pT = m_pLast->m_pDestCtx.m_pT;
                LODWORD(v121.pNextItem) = v90;
                *(CAkMusicSwitchTransition **)((char *)&v121.pNextItem + 4) = (CAkMusicSwitchTransition *)(unsigned int)m_pLast->m_cmdStop.transParams.eFadeCurve;
                CAkMusicCtx::_Play(m_pT, (AkMusicFade *)&v121, v92);
              }
              *((_BYTE *)m_pLast + 72) &= ~4u;
              m_pLast->m_cutoffInfo.bCutoff = 0;
            }
          }
          CAkMatrixSequencer::RescheduleCancelledActions(this->m_pSequencer, &in_listActions);
          iCutoffTime = v121.m_cutoffInfo.iCutoffTime;
          goto LABEL_203;
        }
        TransitionRule = CAkMusicSwitchCtx::GetTransitionRule(
                           this,
                           &in_source,
                           (CAkMatrixAwareCtx **)v9,
                           &io_uSrcSegmentLookAhead);
        v27 = *v9;
        v28 = TransitionRule;
        if ( !v27 )
          goto LABEL_168;
        p_segmentID = &TransitionRule->pTransObj->segmentID;
        v114 = 0i64;
        if ( !p_segmentID )
          break;
        v30 = *p_segmentID;
        v114 = 0i64;
        NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v30, AkNodeType_Default);
        v32 = NodePtrAndAddRef;
        if ( NodePtrAndAddRef )
        {
          v33 = (CAkMatrixAwareCtx *)((__int64 (__fastcall *)(CAkParameterNodeBase *, CAkMusicSwitchCtx *, CAkRegisteredObj *, UserParams *))NodePtrAndAddRef->vfptr[21].__vecDelDtor)(
                                       NodePtrAndAddRef,
                                       this,
                                       this->m_pSequencer->m_pGameObj,
                                       &this->m_pSequencer->m_UserParams);
          vfptr = v32->vfptr;
          v25 = v33;
          v114 = v33;
          vfptr->Release(v32);
        }
        if ( !v25 )
        {
          v36 = (CAkMatrixAwareCtx *)*io_pNewContext;
          v37 = (CAkMusicSwitchTransition *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
          v10 = v37;
          if ( !v37 )
          {
            v10 = 0i64;
LABEL_168:
            v9 = io_pNewContext;
            goto LABEL_169;
          }
          v37->pNextItem = 0i64;
          v37->m_pDestCtx.m_pT = v36;
          if ( v36 )
            ++v36->m_uRefCount;
          v37->m_cutoffInfo.iCutoffTime = 0i64;
          v37->m_cutoffInfo.bCutoff = 0;
          *((_BYTE *)v37 + 72) &= 0xF8u;
LABEL_62:
          v9 = io_pNewContext;
          goto LABEL_63;
        }
        v10 = (CAkMusicSwitchTransition *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
        if ( v10 )
        {
          v10->pNextItem = 0i64;
          v10->m_pDestCtx.m_pT = (CAkMatrixAwareCtx *)v25;
          ++v25->m_uRefCount;
          v10->m_cutoffInfo.iCutoffTime = 0i64;
          v10->m_cutoffInfo.bCutoff = 0;
          *((_BYTE *)v10 + 72) &= 0xF8u;
        }
        else
        {
          v10 = 0i64;
        }
        v35 = (CAkMatrixAwareCtx *)*io_pNewContext;
        v11 = (CAkMusicSwitchTransition *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
        in_pNewTransition = v11;
        if ( v11 )
        {
          v11->pNextItem = 0i64;
          v11->m_pDestCtx.m_pT = v35;
          if ( v35 )
            ++v35->m_uRefCount;
          v11->m_cutoffInfo.iCutoffTime = 0i64;
          v11->m_cutoffInfo.bCutoff = 0;
          *((_BYTE *)v11 + 72) &= 0xF8u;
        }
        else
        {
          v11 = 0i64;
          in_pNewTransition = 0i64;
        }
        if ( v10 )
        {
          if ( v11 )
            goto LABEL_62;
          CAkMusicSwitchTransition::Cancel(v10);
        }
        else
        {
          UFG::OnUnloadClass<UITest::HandleArrayTest>(v25);
        }
        v114 = 0i64;
        if ( v11 )
        {
          CAkMusicSwitchTransition::Dispose(v11);
          v11 = 0i64;
          in_pNewTransition = 0i64;
        }
        v9 = io_pNewContext;
        v10 = CAkMusicSwitchTransition::Create((CAkMatrixAwareCtx *)*io_pNewContext);
LABEL_63:
        if ( !v10 )
          goto LABEL_169;
        v39 = *((_DWORD *)&v28->srcRule + 4);
        transitionTime = v28->srcRule.fadeParams.transitionTime;
        iFadeOffset = v28->srcRule.fadeParams.iFadeOffset;
        HIDWORD(out_iSyncTime.m_cutoffInfo.iCutoffTime) = v28->srcRule.fadeParams.eFadeCurve;
        uCueFilterHash = v28->srcRule.uCueFilterHash;
        *((_DWORD *)&out_iSyncTime.m_cutoffInfo.bCutoff + 1) = uCueFilterHash;
        v117.fadeParams.transitionTime = v28->destRule.fadeParams.transitionTime;
        eFadeCurve = v28->destRule.fadeParams.eFadeCurve;
        LODWORD(out_iSyncTime.m_cutoffInfo.iCutoffTime) = transitionTime;
        v117.fadeParams.eFadeCurve = eFadeCurve;
        v43 = v28->destRule.fadeParams.iFadeOffset;
        *(_DWORD *)&out_iSyncTime.m_cutoffInfo.bCutoff = iFadeOffset;
        v117.fadeParams.iFadeOffset = v43;
        v44 = v28->destRule.uCueFilterHash;
        in_eSyncType = v39;
        v117.uCueFilterHash = v44;
        uJumpToID = v28->destRule.uJumpToID;
        LODWORD(out_iSyncTime.m_cmdPlay.iRelativeTime) = v39;
        v117.uJumpToID = uJumpToID;
        *((_DWORD *)&v117 + 5) = *((_DWORD *)&v28->destRule + 5);
        pTransObj = v28->pTransObj;
        if ( pTransObj )
        {
          in_ruleTo.fadeParams.transitionTime = pTransObj->fadeInParams.transitionTime;
          in_ruleTo.fadeParams.eFadeCurve = pTransObj->fadeInParams.eFadeCurve;
          v47 = pTransObj->fadeInParams.iFadeOffset;
          in_ruleTo.uCueFilterHash = 0;
          in_ruleTo.fadeParams.iFadeOffset = v47;
          *((_WORD *)&in_ruleTo + 10) &= 0xFFF8u;
          *((_WORD *)&in_ruleTo + 10) = *((_WORD *)&in_ruleTo + 10) & 0xFFE7 | (8 * (*((_WORD *)v28->pTransObj + 14) & 1));
          v48 = v28->pTransObj;
          v49 = v48->fadeOutParams.eFadeCurve;
          v50 = v48->fadeOutParams.transitionTime;
          v51 = v48->fadeOutParams.iFadeOffset;
          LODWORD(v48) = *((_DWORD *)v48 + 7);
          *((_DWORD *)&v121.m_cutoffInfo.bCutoff + 1) = v49;
          *(_DWORD *)&v121.m_cutoffInfo.bCutoff = v50;
          v121.m_cmdPlay.iRelativeTime = v51;
          v119 = v121.m_cmdPlay.fadeParams.transitionTime & 0xFFFFFFC7 | (16 * ((unsigned __int8)v48 & 2)) | 7;
          v121.m_cmdPlay.fadeParams.transitionTime = v119;
        }
        else
        {
          in_ruleTo = v117;
          v119 = v39;
          v121.m_cmdPlay.fadeParams.transitionTime = v39;
          *(AkCutoffInfo *)&v121.m_cutoffInfo.bCutoff = out_iSyncTime.m_cutoffInfo;
          v50 = out_iSyncTime.m_cutoffInfo.iCutoffTime;
          v51 = *(_DWORD *)&out_iSyncTime.m_cutoffInfo.bCutoff;
        }
        if ( in_transitionInfo->bOverrideEntryType )
          *((_WORD *)&v117 + 10) ^= (LOWORD(in_transitionInfo->eEntryType) ^ *((_WORD *)&v117 + 10)) & 7;
        LODWORD(v120.pItem) = ((__int64 (__fastcall *)(CAkMusicCtx *, AkMusicTransDestRule *, _QWORD, AkSeekingInfo *, char *, _DWORD))(*io_pNewContext)->CAkChildCtx::vfptr[1].VirtualAddRef)(
                                *io_pNewContext,
                                &v117,
                                0i64,
                                in_transitionInfo->pSeekingInfo,
                                v118,
                                0);
        out_iSyncTime.pNextItem = 0i64;
        CAkScheduleWindow::CAkScheduleWindow(&v130, 1);
        if ( in_pNewTransition )
        {
          in_iDestinationLookAhead = ((__int64 (__fastcall *)(CAkMatrixAwareCtx *, AkMusicTransDestRule *, _QWORD, _QWORD, AkSwitchStopCmd *, _DWORD))v114->CAkMusicCtx::CAkChildCtx::vfptr[1].VirtualAddRef)(
                                       v114,
                                       &in_ruleTo,
                                       0i64,
                                       0i64,
                                       &out_iSyncTime.m_cmdStop,
                                       0);
          FirstSegmentNode = CAkMatrixAwareCtx::GetFirstSegmentNode(v114, 0i64);
          if ( FirstSegmentNode )
            active = CAkMusicSegment::ActiveDuration(FirstSegmentNode);
          else
            active = 0;
          v54 = in_iDestinationLookAhead;
          v55 = AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8 * transitionTime - iFadeOffset;
          if ( v55 > in_iDestinationLookAhead )
            v54 = v55;
          v56 = v50 * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8) - v51;
          pItem = (int)v120.pItem;
          v58 = in_iCurrentTime + v54;
          v59 = (int)v120.pItem;
          if ( v56 > SLODWORD(v120.pItem) )
            v59 = v56;
          v60 = v59 - (__int64)active;
          v61 = (int)v120.pItem;
          v62 = in_iCurrentTime + v60;
          if ( v58 > v62 )
            v62 = v58;
          if ( v56 > SLODWORD(v120.pItem) )
            v61 = v56;
          *(_QWORD *)&out_iSyncTime.m_cmdPlay.fadeParams.iFadeOffset = in_iCurrentTime + v61;
        }
        else
        {
          pItem = (int)v120.pItem;
          *(_QWORD *)&out_iSyncTime.m_cmdPlay.fadeParams.iFadeOffset = 0i64;
          v63 = (unsigned int)v120.pItem;
          in_iDestinationLookAhead = (int)v120.pItem;
          if ( (int)(transitionTime * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8) - iFadeOffset) > SLODWORD(v120.pItem) )
            v63 = transitionTime * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8) - iFadeOffset;
          v62 = in_iCurrentTime + (int)v63;
        }
        v11 = in_pNewTransition;
        v126 = 0;
        v64 = in_eSyncType & 0x1F;
        for ( in_eSyncType = v64; ; v64 = in_eSyncType )
        {
          io_uCueFilter = uCueFilterHash;
          in_bDoSkipEntryCue = (*((_BYTE *)&v117 + 20) & 7) == 1
                            || (*((_BYTE *)&v117 + 20) & 0x10) != 0
                            && (unsigned __int16)((*((_BYTE *)&v117 + 20) & 7) - 2) <= 1u;
          SyncPoint = CAkScheduleWindow::FindSyncPoint(
                        &in_source,
                        v62,
                        v64,
                        &io_uCueFilter,
                        in_bDoSkipEntryCue,
                        1,
                        (__int64 *)&in_itTrans);
          if ( SyncPoint == AK_PartialSuccess && in_source.m_bIsActiveSegment )
          {
            for ( k = this->m_queueTransitions.m_pFirst; k; k = k->pNextItem )
            {
              if ( k == *(CAkMusicSwitchTransition **)&out_iSyncTime.m_cmdPlay.fadeParams.transitionTime )
                break;
            }
            transParams = k->pNextItem;
            if ( k->pNextItem )
            {
              while ( 1 )
              {
                v69 = transParams->pNextItem;
                v128 = __PAIR128__((unsigned __int64)k, transParams->pNextItem);
                if ( transParams == this->m_queueTransitions.m_pFirst )
                  this->m_queueTransitions.m_pFirst = v69;
                else
                  k->pNextItem = v69;
                if ( transParams == this->m_queueTransitions.m_pLast )
                  this->m_queueTransitions.m_pLast = k;
                v70 = v128;
                transParams->pNextItem = 0i64;
                *(_OWORD *)&out_iSyncTime.m_cmdStop.transParams.TransitionTime = v70;
                if ( v14 )
                  v14->pNextItem = transParams;
                else
                  v121.m_cutoffInfo.iCutoffTime = (__int64)transParams;
                v14 = transParams;
                if ( !v69 )
                  break;
                k = (CAkMusicSwitchTransition *)*((_QWORD *)&out_iSyncTime + 9);
                transParams = (CAkMusicSwitchTransition *)out_iSyncTime.m_cmdStop.transParams;
              }
            }
            ((void (__fastcall *)(CAkMusicSwitchCtx *, CAkScheduleWindow *))this->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr[1].~CAkChildCtx)(
              this,
              &in_source);
            v71 = (*((_BYTE *)&v117 + 20) & 7) == 1
               || (*((_BYTE *)&v117 + 20) & 0x10) != 0 && (unsigned __int16)((*((_BYTE *)&v117 + 20) & 7) - 2) <= 1u;
            SyncPoint = CAkScheduleWindow::FindSyncPoint(
                          &in_source,
                          v62,
                          in_eSyncType,
                          &io_uCueFilter,
                          v71,
                          1,
                          (__int64 *)&in_itTrans);
          }
          if ( v11 && SyncPoint == AK_Success )
          {
            v10->m_pDestCtx.m_pT->m_iLocalTime = (unsigned __int64)in_itTrans.pItem;
            ++v130.m_uLevel;
            v120.pItem = v10;
            CAkScheduleWindow::SetBranch(&v130, &v120);
            ((void (__fastcall *)(CAkMatrixAwareCtx *, CAkScheduleWindow *, _QWORD))v120.pItem->m_pDestCtx.m_pT->vfptr[1].VirtualRelease)(
              v120.pItem->m_pDestCtx.m_pT,
              &v130,
              0i64);
            --v130.m_uLevel;
            SyncPoint = CAkScheduleWindow::FindSyncPoint(
                          &v130,
                          *(__int64 *)&out_iSyncTime.m_cmdPlay.fadeParams.iFadeOffset,
                          (AkSyncType)(v119 & 0x1F),
                          &v126,
                          1,
                          1,
                          (__int64 *)&out_iSyncTime);
          }
          v72 = *((_BYTE *)&v117 + 20) & 7;
          if ( v72 != 1 && ((*((_BYTE *)&v117 + 20) & 0x10) == 0 || (unsigned __int16)(v72 - 2) > 1u) )
            break;
          if ( SyncPoint != AK_Success )
            goto LABEL_159;
          if ( in_transitionInfo->pSeekingInfo || !in_source.m_itScheduledItem.pItem->m_pSegment.m_pT )
            goto LABEL_137;
          if ( v72 == 1 )
          {
            v73 = in_itTrans.pItem;
            v74 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(&in_source, 0);
            v75 = AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(
                    &in_source.m_itScheduledItem,
                    (__int64)v73 - v74);
            v76 = ((__int64 (__fastcall *)(CAkMusicCtx *, AkMusicTransDestRule *, _QWORD, _QWORD, char *, _DWORD))(*io_pNewContext)->CAkChildCtx::vfptr[1].VirtualAddRef)(
                    *io_pNewContext,
                    &v117,
                    v75,
                    0i64,
                    v118,
                    0);
          }
          else
          {
            v76 = ((__int64 (__fastcall *)(CAkMusicCtx *, AkMusicTransDestRule *, _QWORD, _QWORD, char *, unsigned int))(*io_pNewContext)->CAkChildCtx::vfptr[1].VirtualAddRef)(
                    *io_pNewContext,
                    &v117,
                    0i64,
                    0i64,
                    v118,
                    io_uCueFilter);
          }
          pItem = v76;
          if ( v11 )
          {
            v77 = CAkMatrixAwareCtx::GetFirstSegmentNode(v114, 0i64);
            if ( v77 )
            {
              v76 = pItem - CAkMusicSegment::ActiveDuration(v77);
              if ( v76 < in_iDestinationLookAhead )
                v76 = in_iDestinationLookAhead;
            }
            else
            {
              v76 = pItem;
              if ( pItem < in_iDestinationLookAhead )
                v76 = in_iDestinationLookAhead;
            }
          }
          else
          {
            in_iDestinationLookAhead = v76;
          }
          if ( v76 <= (__int64)in_itTrans.pItem - in_iCurrentTime )
            goto LABEL_137;
          v62 = v76 + in_iCurrentTime;
        }
        if ( SyncPoint != AK_Success )
        {
LABEL_159:
          if ( v11 )
          {
            CAkMusicSwitchTransition::Cancel(v10);
            CAkMusicSwitchTransition::Dispose(v11);
            v11 = 0i64;
            in_pNewTransition = 0i64;
          }
          else
          {
            CAkMusicSwitchTransition::Dispose(v10);
          }
          ((void (__fastcall *)(CAkMusicSwitchCtx *, CAkScheduleWindow *, _QWORD))this->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr[1].VirtualRelease)(
            this,
            &in_source,
            0i64);
          goto LABEL_163;
        }
LABEL_137:
        ++in_source.m_uLevel;
        v78.pItem = CAkScheduleWindow::GetBranch(&in_source, &v121).pItem;
        v79 = this->m_queueTransitions.m_pFirst;
        v80 = v78.pItem->pNextItem;
        --in_source.m_uLevel;
        for ( *(_QWORD *)&out_iSyncTime.m_cmdPlay.fadeParams.transitionTime = v80; v79; v79 = v79->pNextItem )
        {
          if ( v79 == v80 )
            break;
        }
        v81 = v79->pNextItem;
        if ( v79->pNextItem )
        {
          while ( 1 )
          {
            v82 = v81->pNextItem;
            *(_OWORD *)&v121.m_cmdPlay.fadeParams.iFadeOffset = __PAIR128__((unsigned __int64)v79, v81->pNextItem);
            if ( v81 == this->m_queueTransitions.m_pFirst )
              this->m_queueTransitions.m_pFirst = v82;
            else
              v79->pNextItem = v82;
            if ( v81 == this->m_queueTransitions.m_pLast )
              this->m_queueTransitions.m_pLast = v79;
            v83 = *(_OWORD *)&v121.m_cmdPlay.fadeParams.iFadeOffset;
            v81->pNextItem = 0i64;
            *(_OWORD *)&v121.m_cmdStop.transParams.TransitionTime = v83;
            if ( v14 )
              v14->pNextItem = v81;
            else
              v121.m_cutoffInfo.iCutoffTime = (__int64)v81;
            v14 = v81;
            if ( !v82 )
              break;
            v79 = (CAkMusicSwitchTransition *)*((_QWORD *)&v121 + 9);
            v81 = (CAkMusicSwitchTransition *)v121.m_cmdStop.transParams;
          }
        }
        ((void (__fastcall *)(CAkMusicSwitchCtx *, CAkScheduleWindow *))this->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr[1].~CAkChildCtx)(
          this,
          &in_source);
        if ( this->m_pSwitchCntrNode->m_bIsContinuePlayback && !in_transitionInfo->pSeekingInfo )
        {
          v84 = ((__int64 (__fastcall *)(CAkMatrixAwareCtx *))v80->m_pDestCtx.m_pT->vfptr[2].OnPaused)(v80->m_pDestCtx.m_pT);
          if ( v84 ? *(_DWORD *)(v84 + 16) == in_destinationID : in_destinationID == 0 )
          {
            _((AMD_HD3D *)&v130);
            goto LABEL_168;
          }
        }
        this->m_pLastNonCancelledTransitionInFrame = v80;
        v86 = in_iCurrentTime;
        j = 0;
        CAkMusicSwitchCtx::ScheduleTransition(
          this,
          in_iCurrentTime,
          v10,
          (AkMusicTransSrcRule *)&out_iSyncTime.m_cutoffInfo,
          &in_ruleTo,
          &in_source,
          in_iDestinationLookAhead,
          (__int64)in_itTrans.pItem,
          0,
          &in_listActions);
        if ( v11 )
          CAkMusicSwitchCtx::ScheduleTransition(
            this,
            v86,
            v11,
            (AkMusicTransSrcRule *)&v121.m_cutoffInfo.bCutoff,
            &v117,
            &v130,
            pItem,
            (__int64)out_iSyncTime.pNextItem,
            1,
            &in_listActions);
LABEL_163:
        _((AMD_HD3D *)&v130);
        v23 = SyncPoint == AK_Success;
        v9 = io_pNewContext;
        if ( v23 )
          goto LABEL_169;
        v25 = 0i64;
      }
      v38 = (CAkMusicSwitchTransition *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
      v10 = v38;
      if ( !v38 )
      {
        v10 = 0i64;
        goto LABEL_168;
      }
      v38->pNextItem = 0i64;
      v38->m_pDestCtx.m_pT = (CAkMatrixAwareCtx *)v27;
      ++v27->m_uRefCount;
      v38->m_cutoffInfo.iCutoffTime = 0i64;
      v38->m_cutoffInfo.bCutoff = 0;
      *((_BYTE *)v38 + 72) &= 0xF8u;
      goto LABEL_62;
    }
  }
  for ( m = this->m_queueTransitions.m_pFirst; m; m = m->pNextItem )
  {
    if ( m == v21 )
      break;
  }
  v94 = m->pNextItem;
  if ( m->pNextItem )
  {
    while ( 1 )
    {
      v95 = v94->pNextItem;
      *(_OWORD *)&v121.m_cmdStop.transParams.TransitionTime = __PAIR128__((unsigned __int64)m, v94->pNextItem);
      if ( v94 == this->m_queueTransitions.m_pFirst )
        this->m_queueTransitions.m_pFirst = v95;
      else
        m->pNextItem = v95;
      if ( v94 == this->m_queueTransitions.m_pLast )
        this->m_queueTransitions.m_pLast = m;
      v96 = *(_OWORD *)&v121.m_cmdStop.transParams.TransitionTime;
      v94->pNextItem = 0i64;
      *(_OWORD *)&v121.m_cmdPlay.fadeParams.iFadeOffset = v96;
      if ( v14 )
        v14->pNextItem = v94;
      else
        iCutoffTime = (__int64)v94;
      v14 = v94;
      if ( !v95 )
        break;
      m = (CAkMusicSwitchTransition *)v121.m_cmdStop.iRelativeTime;
      v94 = *(CAkMusicSwitchTransition **)&v121.m_cmdPlay.fadeParams.iFadeOffset;
    }
  }
  ((void (__fastcall *)(CAkMusicSwitchCtx *, CAkScheduleWindow *))this->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr[1].~CAkChildCtx)(
    this,
    &in_source);
  UFG::OnUnloadClass<UITest::HandleArrayTest>(*v9);
  *v9 = 0i64;
  if ( ((unsigned __int8 (__fastcall *)(CAkMatrixAwareCtx *))this->m_queueTransitions.m_pLast->m_pDestCtx.m_pT->vfptr[2].OnResumed)(this->m_queueTransitions.m_pLast->m_pDestCtx.m_pT) )
  {
    v97 = this->m_queueTransitions.m_pLast;
    v98 = *((_BYTE *)v97 + 72);
    if ( (v98 & 4) == 0 || (v98 & 2) != 0 )
    {
      *((_BYTE *)v97 + 72) = v98 & 0xFD;
    }
    else
    {
      v99 = AkTimeConv::SamplesToMilliseconds((int)in_iCurrentTime - LODWORD(v97->m_cmdStop.iRelativeTime));
      v100 = v97->m_pDestCtx.m_pT;
      LODWORD(v121.pNextItem) = v99;
      *(CAkMusicSwitchTransition **)((char *)&v121.pNextItem + 4) = (CAkMusicSwitchTransition *)(unsigned int)v97->m_cmdStop.transParams.eFadeCurve;
      CAkMusicCtx::_Play(v100, (AkMusicFade *)&v121, v101);
    }
    *((_BYTE *)v97 + 72) &= ~4u;
    v97->m_cutoffInfo.bCutoff = 0;
  }
LABEL_203:
  v102 = (CAkMusicSwitchTransition *)iCutoffTime;
  iRelativeTime = 0i64;
  if ( iCutoffTime )
  {
    while ( 1 )
    {
      v104 = (TransParams)v102->pNextItem;
      *((_QWORD *)&v121 + 9) = iRelativeTime;
      v121.m_cmdStop.transParams = v104;
      if ( v102 == (CAkMusicSwitchTransition *)iCutoffTime )
        iCutoffTime = (__int64)v104;
      else
        iRelativeTime->pNextItem = (CAkMusicSwitchTransition *)v104;
      v105 = *(_OWORD *)&v121.m_cmdStop.transParams.TransitionTime;
      v106 = v102->m_pDestCtx.m_pT;
      if ( v102 == v14 )
        v14 = iRelativeTime;
      *((_BYTE *)v102 + 72) &= 0xFCu;
      *(_OWORD *)&v121.m_cmdPlay.fadeParams.iFadeOffset = v105;
      UFG::OnUnloadClass<UITest::HandleArrayTest>(v106);
      v107 = v102->m_pDestCtx.m_pT;
      v108 = g_DefaultPoolId;
      v102->m_pDestCtx.m_pT = 0i64;
      if ( v107 )
        CAkMusicCtx::Release(v107);
      v109 = v102->m_pDestCtx.m_pT;
      if ( v109 )
      {
        CAkMusicCtx::Release(v109);
        v102->m_pDestCtx.m_pT = 0i64;
      }
      AK::MemoryMgr::Free(v108, v102);
      if ( !*(_QWORD *)&v104 )
        break;
      iRelativeTime = (CAkMusicSwitchTransition *)v121.m_cmdStop.iRelativeTime;
      v102 = *(CAkMusicSwitchTransition **)&v121.m_cmdPlay.fadeParams.iFadeOffset;
    }
  }
LABEL_215:
  _((AMD_HD3D *)&in_source);
}

// File Line: 1663
// RVA: 0xAB9DA0
void __fastcall CAkMusicSwitchCtx::ScheduleTransition(
        CAkMusicSwitchCtx *this,
        __int64 in_iCurrentTime,
        CAkMusicSwitchTransition *in_pNewTransition,
        AkMusicTransSrcRule *in_ruleFrom,
        AkMusicTransDestRule *in_ruleTo,
        CAkScheduleWindow *in_source,
        int in_iDestinationLookAhead,
        __int64 in_iSyncPoint,
        bool in_bIsFromTransitionCtx,
        AkListBareLight<AkAssociatedAction,AkListBareLightNextItem<AkAssociatedAction> > *io_listCancelledActions)
{
  int v11; // r15d
  CAkMusicSegment *Node; // rax
  CAkMusicSwitchTransition *m_pLast; // rbx
  char v17; // r8
  unsigned int v18; // ecx
  unsigned int v19; // r15d
  int v20; // eax
  CAkMusicCtx *m_pT; // rcx
  AkCurveInterpolation eFadeCurve; // eax
  CAkTransition **v23; // r8
  int transitionTime; // r8d
  int v25; // r15d
  __int64 v26; // r12
  signed int v27; // eax
  bool v28; // cl
  AkCurveInterpolation v29; // eax
  CAkMatrixAwareCtx *v30; // rcx
  __int64 v31; // r8
  CAkMusicSwitchTransition *v32; // rax
  AkMusicFade in_fadeParams; // [rsp+20h] [rbp-38h] BYREF
  CAkMusicSegment *v34; // [rsp+60h] [rbp+8h]
  int in_sourcea; // [rsp+88h] [rbp+30h]

  v11 = in_iCurrentTime;
  Node = CAkScheduleWindow::GetNode(in_source, 0i64);
  m_pLast = this->m_queueTransitions.m_pLast;
  v17 = *((_BYTE *)m_pLast + 72);
  v34 = Node;
  v18 = in_iSyncPoint - v11;
  if ( (v17 & 4) == 0 || (v17 & 2) != 0 )
  {
    *((_BYTE *)m_pLast + 72) = v17 & 0xFD;
  }
  else
  {
    v19 = v11 - LODWORD(m_pLast->m_cmdStop.iRelativeTime);
    if ( v19 < v18 )
      v18 = v19;
    v20 = AkTimeConv::SamplesToMilliseconds(v18);
    m_pT = m_pLast->m_pDestCtx.m_pT;
    in_fadeParams.transitionTime = v20;
    eFadeCurve = m_pLast->m_cmdStop.transParams.eFadeCurve;
    in_fadeParams.iFadeOffset = 0;
    in_fadeParams.eFadeCurve = eFadeCurve;
    CAkMusicCtx::_Play(m_pT, &in_fadeParams, v23);
    Node = v34;
  }
  *((_BYTE *)m_pLast + 72) &= ~4u;
  m_pLast->m_cutoffInfo.bCutoff = 0;
  transitionTime = in_ruleFrom->fadeParams.transitionTime;
  v25 = 0;
  v26 = in_iSyncPoint;
  in_sourcea = in_ruleFrom->fadeParams.transitionTime;
  if ( in_ruleFrom->fadeParams.transitionTime > 0 && Node )
  {
    v27 = transitionTime * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8) - in_ruleFrom->fadeParams.iFadeOffset;
    v25 = transitionTime * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8) - v27;
    v26 = in_iSyncPoint - v27;
  }
  else if ( (*((_BYTE *)in_ruleFrom + 16) & 0x20) != 0 )
  {
    if ( CAkScheduleWindow::IsAtExitCue(in_source, in_iSyncPoint) )
      v26 = in_iSyncPoint + (unsigned int)CAkMusicSegment::PostExitDuration(v34);
    transitionTime = in_sourcea;
  }
  v28 = !in_bIsFromTransitionCtx && v25 <= 0;
  v29 = in_ruleFrom->fadeParams.eFadeCurve;
  *((_BYTE *)m_pLast + 72) |= 6u;
  m_pLast->m_cmdStop.transParams.TransitionTime = transitionTime;
  m_pLast->m_cmdStop.transParams.eFadeCurve = v29;
  m_pLast->m_cmdStop.iRelativeTime = v26;
  if ( v28 )
  {
    if ( m_pLast->m_cutoffInfo.bCutoff )
    {
      if ( in_iSyncPoint >= m_pLast->m_cutoffInfo.iCutoffTime )
        goto LABEL_23;
    }
    else
    {
      m_pLast->m_cutoffInfo.bCutoff = 1;
    }
    m_pLast->m_cutoffInfo.iCutoffTime = in_iSyncPoint;
  }
LABEL_23:
  CAkScheduledItem::ForcePostExit(in_source->m_itScheduledItem.pItem, (*((_DWORD *)in_ruleFrom + 4) & 0x20) != 0);
  in_pNewTransition->m_pDestCtx.m_pT->m_iLocalTime = in_iSyncPoint;
  in_pNewTransition->m_cmdPlay.iRelativeTime = in_iSyncPoint - in_iDestinationLookAhead;
  v30 = in_pNewTransition->m_pDestCtx.m_pT;
  in_pNewTransition->m_cmdPlay.fadeParams.transitionTime = in_ruleTo->fadeParams.transitionTime;
  in_pNewTransition->m_cmdPlay.fadeParams.eFadeCurve = in_ruleTo->fadeParams.eFadeCurve;
  in_pNewTransition->m_cmdPlay.fadeParams.iFadeOffset = in_ruleTo->fadeParams.iFadeOffset;
  if ( !((__int64 (__fastcall *)(CAkMatrixAwareCtx *))v30->CAkMusicCtx::CAkChildCtx::vfptr[2].OnPaused)(v30) )
    in_pNewTransition->m_cmdPlay.fadeParams.transitionTime = 0;
  if ( in_ruleTo->fadeParams.transitionTime > 0 )
    in_pNewTransition->m_cmdPlay.fadeParams.iFadeOffset += in_iDestinationLookAhead;
  *((_BYTE *)in_pNewTransition + 72) |= 1u;
  CAkScheduleWindow::CancelActionsAfterTransitionSyncPoint(in_source, io_listCancelledActions, in_iSyncPoint);
  while ( !in_source->m_bIsDurationInfinite )
  {
    LOBYTE(v31) = 1;
    ((void (__fastcall *)(CAkMusicSwitchCtx *, CAkScheduleWindow *, __int64))this->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr[1].VirtualRelease)(
      this,
      in_source,
      v31);
    CAkScheduleWindow::CancelActionsAfterTransitionSyncPoint(in_source, io_listCancelledActions, in_iSyncPoint);
  }
  in_pNewTransition->pNextItem = 0i64;
  v32 = this->m_queueTransitions.m_pLast;
  if ( v32 )
    v32->pNextItem = in_pNewTransition;
  else
    this->m_queueTransitions.m_pFirst = in_pNewTransition;
  this->m_queueTransitions.m_pLast = in_pNewTransition;
}

// File Line: 1747
// RVA: 0xAB8110
AkMusicTransitionRule *__fastcall CAkMusicSwitchCtx::GetTransitionRule(
        CAkMusicSwitchCtx *this,
        CAkScheduleWindow *in_source,
        CAkMatrixAwareCtx **io_pDestContext,
        unsigned int *io_uSrcSegmentLookAhead)
{
  CAkMusicSegment *Node; // rax
  unsigned int key; // ebx
  CAkMusicSegment *v9; // rax
  unsigned int in_destID; // edx
  AkMusicTransitionRule *TransitionRule; // rax
  AkMusicTransitionRule *v12; // rsi
  CAkChainCtx *pCtx; // rbx
  CAkSequenceCtx *v14; // rcx
  CAkMusicNode *out_ppParentNode; // [rsp+40h] [rbp-148h] BYREF
  CAkMusicNode *in_pDestParentNode; // [rsp+48h] [rbp-140h] BYREF
  CAkScheduleWindow v17; // [rsp+50h] [rbp-138h] BYREF
  bool out_bIsDestSequenceSpecific; // [rsp+1A8h] [rbp+20h] BYREF

  if ( ++*io_uSrcSegmentLookAhead <= 0x40 )
  {
    Node = CAkScheduleWindow::GetNode(in_source, &out_ppParentNode);
    if ( Node )
      key = Node->key;
    else
      key = 0;
    CAkScheduleWindow::CAkScheduleWindow(&v17, *io_pDestContext, 1);
    v9 = CAkScheduleWindow::GetNode(&v17, &in_pDestParentNode);
    if ( v9 )
      in_destID = v9->key;
    else
      in_destID = 0;
    TransitionRule = CAkMusicTransAware::GetTransitionRule(
                       this->m_pSwitchCntrNode,
                       this->m_pSwitchCntrNode,
                       key,
                       out_ppParentNode,
                       in_destID,
                       in_pDestParentNode,
                       &out_bIsDestSequenceSpecific);
    v12 = TransitionRule;
    if ( out_bIsDestSequenceSpecific )
    {
      pCtx = v17.m_itScheduledItem.pCtx;
      v14 = (CAkSequenceCtx *)v17.m_itScheduledItem.pCtx;
      ++v17.m_itScheduledItem.pCtx->m_uRefCount;
      if ( !CAkSequenceCtx::JumpToSegment(v14, TransitionRule->destRule.uJumpToID) )
      {
        UFG::OnUnloadClass<UITest::HandleArrayTest>(*io_pDestContext);
        *io_pDestContext = 0i64;
      }
      CAkMusicCtx::Release(pCtx);
    }
    _((AMD_HD3D *)&v17);
    return v12;
  }
  else
  {
    return CAkMusicTransAware::GetPanicTransitionRule();
  }
}

// File Line: 1839
// RVA: 0xAB8930
__int64 __fastcall CAkMusicSwitchCtx::PrepareFirstContext(CAkMusicSwitchCtx *this, CAkMatrixAwareCtx *in_pCtx)
{
  CAkMusicSwitchTransition *v4; // rax
  CAkMusicSwitchTransition *m_pLast; // rcx
  char v7; // [rsp+50h] [rbp+18h] BYREF

  v4 = (CAkMusicSwitchTransition *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
  if ( !v4 )
    return 2i64;
  v4->pNextItem = 0i64;
  v4->m_pDestCtx.m_pT = in_pCtx;
  if ( in_pCtx )
    ++in_pCtx->m_uRefCount;
  v4->m_cutoffInfo.iCutoffTime = 0i64;
  v4->m_cutoffInfo.bCutoff = 0;
  *((_BYTE *)v4 + 72) &= 0xF8u;
  v4->pNextItem = 0i64;
  m_pLast = this->m_queueTransitions.m_pLast;
  if ( m_pLast )
    m_pLast->pNextItem = v4;
  else
    this->m_queueTransitions.m_pFirst = v4;
  this->m_queueTransitions.m_pLast = v4;
  this->m_itActiveSwitch.pItem = this->m_queueTransitions.m_pFirst;
  ((void (__fastcall *)(CAkMusicSwitchCtx *, _QWORD, _QWORD, _QWORD, char *, _DWORD))this->CAkMatrixAwareCtx::CAkMusicCtx::CAkChildCtx::vfptr[1].VirtualAddRef)(
    this,
    0i64,
    0i64,
    0i64,
    &v7,
    0);
  return 1i64;
}

// File Line: 1867
// RVA: 0xAB8350
char __fastcall CAkMusicSwitchCtx::HasOrAscendentHasPendingTransition(CAkMusicSwitchCtx *this)
{
  if ( this->m_itActiveSwitch.pItem->pNextItem )
    return 1;
  while ( 1 )
  {
    this = (CAkMusicSwitchCtx *)this->m_pParentCtx;
    if ( !this )
      break;
    if ( this->m_itActiveSwitch.pItem->pNextItem )
      return 1;
  }
  return 0;
}

// File Line: 1883
// RVA: 0xAB7F60
CAkMusicSwitchTransition *__fastcall CAkMusicSwitchCtx::FindLastNonCancellableTransition(CAkMusicSwitchCtx *this)
{
  CAkMusicSwitchTransition *result; // rax
  CAkMusicSwitchTransition *v2; // rdi
  CAkMusicSwitchTransition *pNextItem; // rbx
  char v4; // cl

  result = this->m_itActiveSwitch.pItem;
  v2 = result;
  pNextItem = result->pNextItem;
  if ( result->pNextItem )
  {
    do
    {
      if ( !((unsigned __int8 (__fastcall *)(CAkMatrixAwareCtx *))result->m_pDestCtx.m_pT->vfptr[2].OnResumed)(result->m_pDestCtx.m_pT)
        || (v4 = *((_BYTE *)&pNextItem->m_pDestCtx.m_pT->CAkMusicCtx + 98), (v4 & 3) != 0) && (v4 & 0x10) == 0 )
      {
        v2 = pNextItem;
      }
      result = pNextItem;
      pNextItem = pNextItem->pNextItem;
    }
    while ( pNextItem );
    return v2;
  }
  return result;
}

// File Line: 1941
// RVA: 0xABA0A0
__int64 __fastcall CAkMusicSwitchCtx::SeekTimeAbsolute(CAkMusicSwitchCtx *this, int *io_position, bool in_bSnapToCue)
{
  signed int v4; // edx
  unsigned __int8 v5; // al
  unsigned int v7; // edi
  CAkMusicSwitchCtx::TransitionInfo in_transitionInfo; // [rsp+20h] [rbp-18h] BYREF
  int v9; // [rsp+40h] [rbp+8h] BYREF
  char v10; // [rsp+44h] [rbp+Ch]
  CAkMatrixAwareCtx *io_pNewContext; // [rsp+48h] [rbp+10h] BYREF

  v10 = 0;
  v4 = *io_position * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
  if ( v4 < 0 )
    v4 = 0;
  v5 = *((_BYTE *)&this->CAkMusicCtx + 98) & 0xF;
  v9 = v4;
  if ( v5 > 1u || this->m_pParentCtx )
    return 2i64;
  *((_BYTE *)this + 184) &= ~1u;
  in_transitionInfo.pSeekingInfo = (AkSeekingInfo *)&v9;
  in_transitionInfo.bOverrideEntryType = 0;
  v7 = CAkMusicSwitchCtx::ResolveAudioNode(this);
  io_pNewContext = CAkMusicSwitchCtx::CreateDestinationContext(this, v7);
  if ( io_pNewContext )
  {
    CAkMusicSwitchCtx::ScheduleSwitchTransition(this, v7, &in_transitionInfo, &io_pNewContext);
    if ( io_pNewContext )
      io_pNewContext->CAkMusicCtx::CAkChildCtx::vfptr[1].OnResumed(io_pNewContext);
  }
  return 1i64;
}

// File Line: 1959
// RVA: 0xABA000
__int64 __fastcall CAkMusicSwitchCtx::SeekPercent(CAkMusicSwitchCtx *this, float *io_fPercent, bool in_bSnapToCue)
{
  unsigned __int8 v4; // al
  unsigned int v6; // edi
  CAkMusicSwitchCtx::TransitionInfo in_transitionInfo; // [rsp+20h] [rbp-18h] BYREF
  int v8; // [rsp+40h] [rbp+8h] BYREF
  char v9; // [rsp+44h] [rbp+Ch]
  CAkMatrixAwareCtx *io_pNewContext; // [rsp+48h] [rbp+10h] BYREF

  v4 = *((_BYTE *)&this->CAkMusicCtx + 98) & 0xF;
  v8 = *(_DWORD *)io_fPercent;
  v9 = 1;
  if ( v4 > 1u || this->m_pParentCtx )
    return 2i64;
  *((_BYTE *)this + 184) &= ~1u;
  in_transitionInfo.pSeekingInfo = (AkSeekingInfo *)&v8;
  in_transitionInfo.bOverrideEntryType = 0;
  v6 = CAkMusicSwitchCtx::ResolveAudioNode(this);
  io_pNewContext = CAkMusicSwitchCtx::CreateDestinationContext(this, v6);
  if ( io_pNewContext )
  {
    CAkMusicSwitchCtx::ScheduleSwitchTransition(this, v6, &in_transitionInfo, &io_pNewContext);
    if ( io_pNewContext )
      io_pNewContext->CAkMusicCtx::CAkChildCtx::vfptr[1].OnResumed(io_pNewContext);
  }
  return 1i64;
}

