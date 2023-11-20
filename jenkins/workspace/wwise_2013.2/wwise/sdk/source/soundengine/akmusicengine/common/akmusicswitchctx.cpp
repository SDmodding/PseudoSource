// File Line: 84
// RVA: 0xAB87F0
void __fastcall CAkNothingCtx::OnStopped(CAkNothingCtx *this)
{
  CAkNothingCtx *v1; // rbx

  ++this->m_uRefCount;
  v1 = this;
  if ( this->m_bWasReferenced )
  {
    this->m_bWasReferenced = 0;
    CAkMusicCtx::Release((CAkMusicCtx *)&this->vfptr);
  }
  CAkChainCtx::OnStopped((CAkChainCtx *)&v1->vfptr);
  CAkMusicCtx::Release((CAkMusicCtx *)&v1->vfptr);
}

// File Line: 114
// RVA: 0xAB7D30
CAkMusicSwitchTransition *__fastcall CAkMusicSwitchTransition::Create(CAkMatrixAwareCtx *in_pDestination)
{
  CAkMatrixAwareCtx *v1; // rbx
  CAkMusicSwitchTransition *result; // rax

  v1 = in_pDestination;
  result = (CAkMusicSwitchTransition *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
  if ( result )
  {
    result->pNextItem = 0i64;
    result->m_pDestCtx.m_pT = v1;
    if ( v1 )
      ++v1->m_uRefCount;
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
  CAkMusicSwitchTransition *v2; // rbx
  CAkMatrixAwareCtx *v3; // rcx
  CAkMusicCtx *v4; // rcx

  if ( this )
  {
    v1 = g_DefaultPoolId;
    v2 = this;
    v3 = this->m_pDestCtx.m_pT;
    v2->m_pDestCtx.m_pT = 0i64;
    if ( v3 )
      CAkMusicCtx::Release((CAkMusicCtx *)&v3->vfptr);
    v4 = (CAkMusicCtx *)&v2->m_pDestCtx.m_pT->vfptr;
    if ( v4 )
    {
      CAkMusicCtx::Release(v4);
      v2->m_pDestCtx.m_pT = 0i64;
    }
    AK::MemoryMgr::Free(v1, v2);
  }
}

// File Line: 154
// RVA: 0xAB7C30
void __fastcall CAkMusicSwitchTransition::Cancel(CAkMusicSwitchTransition *this)
{
  CAkMusicSwitchTransition *v1; // rbx
  CAkMusicCtx *v2; // rcx
  int v3; // edi
  CAkMusicCtx *v4; // rcx

  *((_BYTE *)this + 72) &= 0xFCu;
  v1 = this;
  UFG::OnUnloadClass<UITest::HandleArrayTest>((CAkMusicCtx *)&this->m_pDestCtx.m_pT->vfptr);
  v2 = (CAkMusicCtx *)&v1->m_pDestCtx.m_pT->vfptr;
  v3 = g_DefaultPoolId;
  v1->m_pDestCtx.m_pT = 0i64;
  if ( v2 )
    CAkMusicCtx::Release(v2);
  v4 = (CAkMusicCtx *)&v1->m_pDestCtx.m_pT->vfptr;
  if ( v4 )
  {
    CAkMusicCtx::Release(v4);
    v1->m_pDestCtx.m_pT = 0i64;
  }
  AK::MemoryMgr::Free(v3, v1);
}

// File Line: 321
// RVA: 0xABA390
void __fastcall CAkMusicSwitchMonitor::SetSwitch(CAkMusicSwitchMonitor *this, unsigned int in_switchID, CAkRegisteredObj *in_pGameObj)
{
  CAkMusicSwitchCtx *v3; // rbx
  unsigned int v4; // er9
  CAkMusicSwitchMonitor *v5; // rdi
  char *v6; // rcx
  CAkMusicCtx *v7; // rcx
  CAkMusicSwitchCtx *v8; // rcx
  char v9; // al
  unsigned int v10; // esi
  __int64 v11; // rdx
  CAkMusicSwitchCtx::TransitionInfo in_transitionInfo; // [rsp+20h] [rbp-18h]
  CAkMatrixAwareCtx *io_pNewContext; // [rsp+40h] [rbp+8h]

  v3 = this->m_pMusicCtx;
  v4 = in_switchID;
  v5 = this;
  if ( in_pGameObj == v3->m_pSequencer->m_pGameObj
    || (v6 = v3->m_pSwitchCntrNode->m_pGroupTypes) != 0i64 && v6[v5->m_uIdx] == 1 )
  {
    if ( !in_switchID )
      v4 = 748895195;
    if ( v5->m_targetSwitchID != v4 )
    {
      v5->m_targetSwitchID = v4;
      v7 = v3->m_pParentCtx;
      if ( v7
        && (v7[1].m_PBTrans.pvPRTrans->m_eTarget
         || (v8 = (CAkMusicSwitchCtx *)v7->m_pParentCtx) != 0i64
         && CAkMusicSwitchCtx::HasOrAscendentHasPendingTransition(v8)) )
      {
        *((_BYTE *)v3 + 184) |= 1u;
      }
      else
      {
        v9 = *((_BYTE *)&v3->0 + 98);
        *((_BYTE *)v3 + 184) &= 0xFEu;
        in_transitionInfo.pSeekingInfo = 0i64;
        in_transitionInfo.bOverrideEntryType = 0;
        if ( (v9 & 0xFu) <= 1 )
        {
          v10 = CAkMusicSwitchCtx::ResolveAudioNode(v3);
          io_pNewContext = (CAkMatrixAwareCtx *)CAkMusicSwitchCtx::CreateDestinationContext(v3, v10);
          if ( io_pNewContext )
          {
            CAkMusicSwitchCtx::ScheduleSwitchTransition(v3, v10, &in_transitionInfo, &io_pNewContext);
            if ( io_pNewContext )
              ((void (__cdecl *)(CAkMatrixAwareCtx *, __int64))io_pNewContext->vfptr[1].OnResumed)(io_pNewContext, v11);
          }
        }
        CAkMusicSwitchCtx::TryPropagateDelayedSwitchChange(v5->m_pMusicCtx);
      }
    }
  }
}

// File Line: 348
// RVA: 0xAB8580
signed __int64 __fastcall CAkMusicSwitchMonitor::Init(CAkMusicSwitchMonitor *this, unsigned int in_uIdx, CAkMusicSwitchCtx *in_pMusicCtx)
{
  AkGroupType v3; // ebx
  CAkMusicSwitchCntr *v4; // r9
  CAkMusicSwitchMonitor *v5; // rdi
  unsigned int *v6; // rcx
  CAkMusicSwitchCtx *v7; // r14
  unsigned int v8; // ebp
  char *v9; // rcx
  signed __int64 result; // rax
  unsigned int v11; // esi
  signed int v12; // eax

  v3 = 0;
  this->m_uIdx = in_uIdx;
  this->m_pMusicCtx = in_pMusicCtx;
  this->m_targetSwitchID = 0;
  v4 = in_pMusicCtx->m_pSwitchCntrNode;
  v5 = this;
  v6 = v4->m_pArguments;
  v7 = in_pMusicCtx;
  if ( v6 )
    v8 = v6[in_uIdx];
  else
    v8 = 0;
  v9 = v4->m_pGroupTypes;
  if ( v9 )
    v3 = (unsigned __int8)v9[in_uIdx];
  result = CAkSwitchAware::SubscribeSwitch((CAkSwitchAware *)&v5->vfptr, v8, v3);
  v11 = result;
  if ( (_DWORD)result == 1 )
  {
    v12 = CAkSwitchAware::GetSwitchToUse((CAkSwitchAware *)&v5->vfptr, v7->m_pSequencer->m_pGameObj, v8, v3);
    if ( !v12 )
      v12 = 748895195;
    v5->m_targetSwitchID = v12;
    result = v11;
  }
  return result;
}

// File Line: 382
// RVA: 0xAB7960
void __fastcall CAkMusicSwitchCtx::CAkMusicSwitchCtx(CAkMusicSwitchCtx *this, CAkMusicSwitchCntr *in_pSwitchNode, CAkMusicCtx *in_pParentCtx)
{
  CAkMusicSwitchCntr *v3; // rbx
  CAkMusicSwitchCtx *v4; // rdi
  CAkMusicSwitchCntr *v5; // rcx

  v3 = in_pSwitchNode;
  v4 = this;
  CAkMatrixAwareCtx::CAkMatrixAwareCtx((CAkMatrixAwareCtx *)&this->vfptr, in_pParentCtx);
  v4->m_pSwitchCntrNode = v3;
  v4->vfptr = (CAkChildCtxVtbl *)&CAkMusicSwitchCtx::`vftable'{for `CAkChildCtx'};
  v4->vfptr = (CAkTransportAwareVtbl *)&CAkMusicSwitchCtx::`vftable'{for `CAkTransportAware'};
  v4->vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable'{for `ITransitionable'};
  v4->m_switchMonitors.m_pItems = 0i64;
  *(_QWORD *)&v4->m_switchMonitors.m_uLength = 0i64;
  v4->m_queueTransitions.m_pFirst = 0i64;
  v4->m_queueTransitions.m_pLast = 0i64;
  v5 = v4->m_pSwitchCntrNode;
  *((_BYTE *)v4 + 184) &= 0xFCu;
  v4->m_pLastNonCancelledTransitionInFrame = 0i64;
  v4->m_itActiveSwitch.pItem = 0i64;
  if ( v5 )
    ((void (*)(void))v5->vfptr->AddRef)();
}

// File Line: 390
// RVA: 0xAB7A00
void __fastcall CAkMusicSwitchCtx::~CAkMusicSwitchCtx(CAkMusicSwitchCtx *this)
{
  CAkMusicSwitchCtx *v1; // rbx
  CAkMusicSwitchCntr *v2; // rcx

  v1 = this;
  this->vfptr = (CAkChildCtxVtbl *)&CAkMusicSwitchCtx::`vftable'{for `CAkChildCtx'};
  this->vfptr = (CAkTransportAwareVtbl *)&CAkMusicSwitchCtx::`vftable'{for `CAkTransportAware'};
  this->vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable'{for `ITransitionable'};
  if ( this->m_switchMonitors.m_pItems )
  {
    AkArray<CAkMusicSwitchMonitor,CAkMusicSwitchMonitor const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::RemoveAll(&this->m_switchMonitors);
    AK::MemoryMgr::Free(g_DefaultPoolId, v1->m_switchMonitors.m_pItems);
    v1->m_switchMonitors.m_pItems = 0i64;
    v1->m_switchMonitors.m_ulReserved = 0;
  }
  v2 = v1->m_pSwitchCntrNode;
  if ( v2 )
    ((void (*)(void))v2->vfptr->Release)();
  CAkMatrixAwareCtx::~CAkMatrixAwareCtx((CAkMatrixAwareCtx *)&v1->vfptr);
}

// File Line: 401
// RVA: 0xAB8380
__int64 __fastcall CAkMusicSwitchCtx::Init(CAkMusicSwitchCtx *this, CAkRegisteredObj *in_GameObject, UserParams *in_rUserparams)
{
  CAkMusicSwitchCtx *v3; // rbx
  AKRESULT v4; // esi
  void **v5; // rdi
  __int64 v6; // r14
  void *v7; // rax
  unsigned int v8; // ebp
  CAkMusicSwitchMonitor *v9; // rax
  AKRESULT v10; // eax
  char v11; // al
  unsigned int v12; // edi
  __int64 v13; // rdx
  CAkSwitchAware v15; // [rsp+20h] [rbp-48h]
  unsigned int v16; // [rsp+28h] [rbp-40h]
  unsigned int v17; // [rsp+2Ch] [rbp-3Ch]
  CAkMusicSwitchCtx *v18; // [rsp+30h] [rbp-38h]
  CAkMatrixAwareCtx *io_pNewContext; // [rsp+88h] [rbp+20h]

  v3 = this;
  v4 = (unsigned int)CAkMatrixAwareCtx::Init((CAkMatrixAwareCtx *)&this->vfptr, in_GameObject, in_rUserparams);
  if ( v4 == 1 )
  {
    v5 = (void **)&v3->m_switchMonitors.m_pItems;
    if ( v3->m_switchMonitors.m_pItems )
    {
      AkArray<CAkMusicSwitchMonitor,CAkMusicSwitchMonitor const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::RemoveAll(&v3->m_switchMonitors);
      AK::MemoryMgr::Free(g_DefaultPoolId, *v5);
      *v5 = 0i64;
      v3->m_switchMonitors.m_ulReserved = 0;
    }
    v6 = v3->m_pSwitchCntrNode->m_decisionTree.m_uDepth;
    if ( !(_DWORD)v6 )
      goto LABEL_24;
    v7 = AK::MemoryMgr::Malloc(g_DefaultPoolId, 24 * v6);
    *v5 = v7;
    if ( !v7 )
      return 52;
    v3->m_switchMonitors.m_ulReserved = v6;
    v4 = 1;
    v8 = 0;
    while ( v8 < (unsigned int)v6 )
    {
      CAkSwitchAware::CAkSwitchAware(&v15);
      v15.vfptr = (CAkSwitchAwareVtbl *)&CAkMusicSwitchMonitor::`vftable';
      v17 = -1;
      v18 = 0i64;
      v9 = AkArray<CAkMusicSwitchMonitor,CAkMusicSwitchMonitor const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(&v3->m_switchMonitors);
      if ( v9 )
      {
        v9->m_targetSwitchID = v16;
        v9->m_uIdx = v17;
        v9->m_pMusicCtx = v18;
      }
      v15.vfptr = (CAkSwitchAwareVtbl *)&CAkMusicSwitchMonitor::`vftable';
      CAkSwitchAware::UnsubscribeSwitches(&v15);
      CAkSwitchAware::~CAkSwitchAware(&v15);
      v10 = CAkMusicSwitchMonitor::Init((CAkMusicSwitchMonitor *)*v5 + v8, v8, v3);
      ++v8;
      v4 = v10;
      if ( v10 != 1 )
        return (unsigned int)v4;
    }
    if ( v4 == 1 )
    {
LABEL_24:
      ++v3->m_uRefCount;
      *((_BYTE *)v3 + 184) |= 2u;
      if ( v3->m_pParentCtx )
      {
        v4 = CAkMusicSwitchCtx::SetInitialSwitch(v3, 0);
      }
      else
      {
        v4 = CAkMusicSwitchCtx::SetInitialSwitch(v3, 1);
        if ( v4 == 1 )
        {
          v11 = *((_BYTE *)&v3->0 + 98);
          *((_BYTE *)v3 + 184) &= 0xFEu;
          v15.vfptr = 0i64;
          LOBYTE(v16) = 0;
          if ( (v11 & 0xFu) <= 1 )
          {
            v12 = CAkMusicSwitchCtx::ResolveAudioNode(v3);
            io_pNewContext = (CAkMatrixAwareCtx *)CAkMusicSwitchCtx::CreateDestinationContext(v3, v12);
            if ( io_pNewContext )
            {
              CAkMusicSwitchCtx::ScheduleSwitchTransition(
                v3,
                v12,
                (CAkMusicSwitchCtx::TransitionInfo *)&v15,
                &io_pNewContext);
              if ( io_pNewContext )
                ((void (__cdecl *)(CAkMatrixAwareCtx *, __int64))io_pNewContext->vfptr[1].OnResumed)(
                  io_pNewContext,
                  v13);
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
  CAkMatrixAwareCtx *v2; // rcx

  for ( i = this->m_queueTransitions.m_pFirst; i; i = i->pNextItem )
  {
    v2 = i->m_pDestCtx.m_pT;
    if ( v2 )
      ((void (*)(void))v2->vfptr[1].OnResumed)();
  }
}

// File Line: 469
// RVA: 0xAB8830
void __fastcall CAkMusicSwitchCtx::PerformDelayedSwitchChange(CAkMusicSwitchCtx *this, __int64 a2)
{
  char v2; // al
  CAkMusicSwitchCtx *v3; // rbx
  char v4; // cl
  unsigned int v5; // edi
  CAkMusicSwitchCtx *v6; // rcx
  CAkMusicSwitchTransition *i; // rbx
  CAkMatrixAwareCtx *v8; // rcx
  CAkMusicSwitchCtx::TransitionInfo in_transitionInfo; // [rsp+20h] [rbp-18h]
  CAkMatrixAwareCtx *io_pNewContext; // [rsp+40h] [rbp+8h]

  v2 = *((_BYTE *)&this->0 + 98);
  v3 = this;
  if ( v2 & 1 || !(v2 & 0xF) )
  {
    v4 = *((_BYTE *)this + 184);
    if ( v4 & 1 )
    {
      in_transitionInfo.pSeekingInfo = 0i64;
      in_transitionInfo.bOverrideEntryType = 0;
      *((_BYTE *)v3 + 184) = v4 & 0xFE;
      if ( (v2 & 0xFu) <= 1 )
      {
        v5 = CAkMusicSwitchCtx::ResolveAudioNode(v3);
        io_pNewContext = (CAkMatrixAwareCtx *)CAkMusicSwitchCtx::CreateDestinationContext(v3, v5);
        if ( io_pNewContext )
        {
          CAkMusicSwitchCtx::ScheduleSwitchTransition(v3, v5, &in_transitionInfo, &io_pNewContext);
          if ( io_pNewContext )
            ((void (__cdecl *)(CAkMatrixAwareCtx *, __int64))io_pNewContext->vfptr[1].OnResumed)(io_pNewContext, a2);
        }
      }
    }
    if ( !v3->m_itActiveSwitch.pItem->pNextItem )
    {
      v6 = (CAkMusicSwitchCtx *)v3->m_pParentCtx;
      if ( !v6 || !CAkMusicSwitchCtx::HasOrAscendentHasPendingTransition(v6) )
      {
        for ( i = v3->m_queueTransitions.m_pFirst; i; i = i->pNextItem )
        {
          v8 = i->m_pDestCtx.m_pT;
          if ( v8 )
            ((void (__cdecl *)(CAkMatrixAwareCtx *, __int64))v8->vfptr[2].VirtualAddRef)(v8, a2);
        }
      }
    }
  }
}

// File Line: 491
// RVA: 0xABA160
signed __int64 __fastcall CAkMusicSwitchCtx::SetInitialSwitch(CAkMusicSwitchCtx *this, bool in_bNothing)
{
  CAkMusicSwitchTransition *v2; // rax
  CAkMusicSwitchCtx *v3; // rbx
  CAkMusicSwitchTransition *v4; // rbp
  CAkMusicSwitchTransition *v5; // rdi
  CAkMusicSwitchTransition *v6; // r8
  CAkMusicSwitchTransition *v7; // rcx
  __m128i v8; // xmm0
  unsigned int v9; // eax
  CAkChainCtx *v10; // rax
  CAkMusicSwitchTransition *v11; // rbx
  CAkMusicSwitchTransition *v12; // rax
  CAkMusicSwitchTransition *v13; // rsi
  __m128i v14; // xmm0
  CAkMusicCtx *v15; // rcx
  CAkMusicCtx *v16; // rcx
  int v17; // er14
  CAkMusicCtx *v18; // rcx
  signed __int64 result; // rax
  __int128 v20; // ax
  CAkMusicSwitchTransition *v21; // rcx
  __m128i v22; // xmm0
  __int128 v23; // [rsp+20h] [rbp-38h]
  __m128i v24; // [rsp+30h] [rbp-28h]

  v2 = this->m_queueTransitions.m_pFirst;
  v3 = this;
  v4 = 0i64;
  v5 = 0i64;
  v6 = 0i64;
  if ( v2 )
  {
    while ( 1 )
    {
      v7 = v2->pNextItem;
      *((_QWORD *)&v23 + 1) = v6;
      *(_QWORD *)&v23 = v7;
      if ( v2 == v3->m_queueTransitions.m_pFirst )
        v3->m_queueTransitions.m_pFirst = v7;
      else
        v6->pNextItem = v7;
      if ( v2 == v3->m_queueTransitions.m_pLast )
        v3->m_queueTransitions.m_pLast = v6;
      v8 = (__m128i)v23;
      v2->pNextItem = 0i64;
      _mm_store_si128(&v24, v8);
      if ( v5 )
        v5->pNextItem = v2;
      else
        v4 = v2;
      v5 = v2;
      if ( !v7 )
        break;
      v6 = (CAkMusicSwitchTransition *)v24.m128i_i64[1];
      v2 = (CAkMusicSwitchTransition *)v24.m128i_i64[0];
    }
  }
  *((_BYTE *)v3 + 184) &= 0xFEu;
  if ( in_bNothing )
    v9 = 0;
  else
    v9 = CAkMusicSwitchCtx::ResolveAudioNode(v3);
  v10 = CAkMusicSwitchCtx::CreateDestinationContext(v3, v9);
  if ( v10 && (unsigned int)CAkMusicSwitchCtx::PrepareFirstContext(v3, (CAkMatrixAwareCtx *)&v10->vfptr) == 1 )
  {
    v11 = v4;
    v12 = 0i64;
    if ( v4 )
    {
      while ( 1 )
      {
        v13 = v11->pNextItem;
        v24.m128i_i64[1] = (__int64)v12;
        v24.m128i_i64[0] = (__int64)v13;
        if ( v11 == v4 )
          v4 = v13;
        else
          v12->pNextItem = v13;
        v14 = v24;
        v15 = (CAkMusicCtx *)&v11->m_pDestCtx.m_pT->vfptr;
        if ( v11 == v5 )
          v5 = v12;
        *((_BYTE *)v11 + 72) &= 0xFCu;
        _mm_store_si128((__m128i *)&v23, v14);
        UFG::OnUnloadClass<UITest::HandleArrayTest>(v15);
        v16 = (CAkMusicCtx *)&v11->m_pDestCtx.m_pT->vfptr;
        v17 = g_DefaultPoolId;
        v11->m_pDestCtx.m_pT = 0i64;
        if ( v16 )
          CAkMusicCtx::Release(v16);
        v18 = (CAkMusicCtx *)&v11->m_pDestCtx.m_pT->vfptr;
        if ( v18 )
        {
          CAkMusicCtx::Release(v18);
          v11->m_pDestCtx.m_pT = 0i64;
        }
        AK::MemoryMgr::Free(v17, v11);
        if ( !v13 )
          break;
        v12 = (CAkMusicSwitchTransition *)*((_QWORD *)&v23 + 1);
        v11 = (CAkMusicSwitchTransition *)v23;
      }
      result = 1i64;
    }
    else
    {
      result = 1i64;
    }
  }
  else
  {
    v20 = (unsigned __int64)v4;
    if ( v4 )
    {
      while ( 1 )
      {
        v21 = *(CAkMusicSwitchTransition **)v20;
        v24.m128i_i64[1] = *((_QWORD *)&v20 + 1);
        v24.m128i_i64[0] = (__int64)v21;
        if ( (CAkMusicSwitchTransition *)v20 == v4 )
          v4 = v21;
        else
          **((_QWORD **)&v20 + 1) = v21;
        v22 = v24;
        *(_QWORD *)v20 = 0i64;
        if ( (CAkMusicSwitchTransition *)v20 == v5 )
          v5 = (CAkMusicSwitchTransition *)*((_QWORD *)&v20 + 1);
        *((_QWORD *)&v20 + 1) = v3->m_queueTransitions.m_pLast;
        _mm_store_si128((__m128i *)&v23, v22);
        if ( *((_QWORD *)&v20 + 1) )
          **((_QWORD **)&v20 + 1) = v20;
        else
          v3->m_queueTransitions.m_pFirst = (CAkMusicSwitchTransition *)v20;
        v3->m_queueTransitions.m_pLast = (CAkMusicSwitchTransition *)v20;
        if ( !v21 )
          break;
        v20 = v23;
      }
    }
    result = 2i64;
  }
  return result;
}witchTrans

// File Line: 577
// RVA: 0xAB8E30
__int64 __fastcall CAkMusicSwitchCtx::ResolveAudioNode(CAkMusicSwitchCtx *this)
{
  __int64 v1; // r9
  __int64 v2; // rbx
  unsigned __int64 v3; // rdx
  signed __int64 v4; // rdx
  void *v5; // rsp
  void *v6; // rsp
  __int64 v7; // rdx
  unsigned int *v8; // r10
  unsigned int in_pPath; // [rsp+30h] [rbp+0h]

  v1 = this->m_switchMonitors.m_uLength;
  v2 = this->m_switchMonitors.m_uLength;
  v3 = 4 * v1 + 15;
  if ( v3 <= 4 * v1 )
    v3 = 1152921504606846960i64;
  v4 = v3 & 0xFFFFFFFFFFFFFFF0ui64;
  v5 = alloca(v4);
  v6 = alloca(v4);
  if ( (_DWORD)v1 )
  {
    v7 = 0i64;
    v8 = &in_pPath;
    do
    {
      ++v8;
      ++v7;
      *(v8 - 1) = *((_DWORD *)&this->m_switchMonitors.m_pItems[v7] - 4);
      --v2;
    }
    while ( v2 );
  }
  return AkDecisionTree::ResolvePath(
           &this->m_pSwitchCntrNode->m_decisionTree,
           this->m_pSwitchCntrNode->key,
           &in_pPath,
           v1,
           0);
}

// File Line: 623
// RVA: 0xAB89E0
void __fastcall CAkMusicSwitchCtx::Process(CAkMusicSwitchCtx *this, __int64 in_iCurrentTime, __int64 in_uNumSamples, AkCutoffInfo *in_cutoffInfo)
{
  unsigned __int64 v4; // rax
  AkCutoffInfo *v5; // r12
  __int64 v6; // rbp
  unsigned int v7; // er14
  CAkMusicSwitchCtx *v8; // rsi
  CAkMusicSwitchTransition *v9; // rbx
  __int64 v10; // r15
  CAkMusicSwitchTransition *v11; // rdi
  __int64 v12; // rcx
  char v13; // dl
  char v14; // cl
  CAkMusicSwitchTransition *v15; // rax
  CAkMusicCtx *v16; // rcx
  int v17; // edi
  CAkMusicCtx *v18; // rcx
  __int64 v19; // rcx
  __int64 v20; // rax
  __int64 v21; // rax
  __int64 v22; // rax
  CAkMatrixAwareCtx *v23; // r10
  char v24; // al
  AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator in_itNewTransition[2]; // [rsp+20h] [rbp-58h]
  __int64 v26; // [rsp+30h] [rbp-48h]
  __int64 v27; // [rsp+38h] [rbp-40h]
  __m128i v28; // [rsp+40h] [rbp-38h]

  v4 = this->m_iLocalTime;
  v5 = in_cutoffInfo;
  in_cutoffInfo->iCutoffTime -= v4;
  ++this->m_uRefCount;
  v6 = in_iCurrentTime - v4;
  v7 = in_uNumSamples;
  v8 = this;
  if ( *((_BYTE *)&this->0 + 98) & 2 && this->m_uNumLastSamples != -1 )
    v7 = this->m_uNumLastSamples;
  v9 = this->m_queueTransitions.m_pFirst;
  v10 = v6 + v7;
  this->m_pLastNonCancelledTransitionInFrame = 0i64;
  in_itNewTransition[0].pItem = v9;
  v11 = 0i64;
  in_itNewTransition[1].pItem = 0i64;
  while ( v9 )
  {
    v12 = v9->m_pDestCtx.m_pT->m_iLocalTime;
    if ( v6 <= v12 && v10 > v12 )
      CAkMusicSwitchCtx::Sync(v8, in_itNewTransition);
    v13 = *((_BYTE *)v9 + 72);
    if ( v13 & 2 || (v14 = *((_BYTE *)&v9->m_pDestCtx.m_pT->0 + 98), v14 & 3) && !(v14 & 0x10) || v13 & 1 )
    {
      v19 = v5->iCutoffTime;
      v20 = *(_QWORD *)&v5->bCutoff;
      v26 = v5->iCutoffTime;
      v27 = v20;
      if ( v13 & 1 )
      {
        v21 = v9->m_cmdPlay.iRelativeTime;
        if ( v6 <= v21 && v10 > v21 )
        {
          CAkMusicCtx::_Play((CAkMusicCtx *)&v9->m_pDestCtx.m_pT->vfptr, &v9->m_cmdPlay.fadeParams, in_uNumSamples);
          *((_BYTE *)v9 + 72) &= 0xFEu;
          v19 = v26;
        }
      }
      if ( *((_BYTE *)v9 + 72) & 2 )
      {
        v22 = v9->m_cmdStop.iRelativeTime;
        if ( v10 > v22 && v6 <= v22 )
        {
          CAkMusicCtx::_Stop(
            (CAkMusicCtx *)&v9->m_pDestCtx.m_pT->vfptr,
            &v9->m_cmdStop.transParams,
            (unsigned int)(v22 - v6));
          *((_BYTE *)v9 + 72) &= 0xFDu;
          v19 = v26;
        }
      }
      v23 = v9->m_pDestCtx.m_pT;
      v24 = *((_BYTE *)&v23->0 + 98);
      if ( v24 & 3 && !(v24 & 0x10) )
      {
        if ( v9->m_cutoffInfo.bCutoff )
        {
          if ( (_BYTE)v27 )
          {
            if ( v9->m_cutoffInfo.iCutoffTime < v19 )
              v19 = v9->m_cutoffInfo.iCutoffTime;
            v26 = v19;
          }
          else
          {
            v26 = v9->m_cutoffInfo.iCutoffTime;
            LOBYTE(v27) = 1;
          }
        }
        ((void (__fastcall *)(CAkMatrixAwareCtx *, __int64, _QWORD, __int64 *))v23->vfptr[1].SetPBIFade)(
          v23,
          v6,
          v7,
          &v26);
      }
    }
    else if ( v9 != v8->m_itActiveSwitch.pItem )
    {
      v15 = v9->pNextItem;
      v28.m128i_i64[1] = (__int64)v11;
      v28.m128i_i64[0] = (__int64)v15;
      if ( v9 == v8->m_queueTransitions.m_pFirst )
        v8->m_queueTransitions.m_pFirst = v15;
      else
        v11->pNextItem = v15;
      if ( v9 == v8->m_queueTransitions.m_pLast )
        v8->m_queueTransitions.m_pLast = v11;
      v16 = (CAkMusicCtx *)&v9->m_pDestCtx.m_pT->vfptr;
      v17 = g_DefaultPoolId;
      _mm_store_si128((__m128i *)in_itNewTransition, v28);
      v9->m_pDestCtx.m_pT = 0i64;
      if ( v16 )
        CAkMusicCtx::Release(v16);
      v18 = (CAkMusicCtx *)&v9->m_pDestCtx.m_pT->vfptr;
      if ( v18 )
      {
        CAkMusicCtx::Release(v18);
        v9->m_pDestCtx.m_pT = 0i64;
      }
      AK::MemoryMgr::Free(v17, v9);
      v11 = in_itNewTransition[1].pItem;
      v9 = in_itNewTransition[0].pItem;
      continue;
    }
    v11 = v9;
    in_itNewTransition[1].pItem = v9;
    v9 = v9->pNextItem;
    in_itNewTransition[0].pItem = v9;
  }
  CAkMatrixAwareCtx::ProcessEpilogue((CAkMatrixAwareCtx *)&v8->vfptr, v6, v7);
}

// File Line: 676
// RVA: 0xAB8910
__int64 __fastcall CAkMusicSwitchCtx::Prepare(CAkMusicSwitchCtx *this, AkMusicTransDestRule *in_pRule, __int64 in_iMinStartPosition, AkSeekingInfo *in_pSeekingInfo, unsigned int *out_uSelectedCue, unsigned int in_uCueHashForMatchSrc)
{
  return ((__int64 (__fastcall *)(CAkMatrixAwareCtx *, AkMusicTransDestRule *, __int64, AkSeekingInfo *))this->m_queueTransitions.m_pFirst->m_pDestCtx.m_pT->vfptr[1].VirtualAddRef)(
           this->m_queueTransitions.m_pFirst->m_pDestCtx.m_pT,
           in_pRule,
           in_iMinStartPosition,
           in_pSeekingInfo);
}

// File Line: 690
// RVA: 0xAB8C30
void __fastcall CAkMusicSwitchCtx::QueryLookAheadInfo(CAkMusicSwitchCtx *this, __int64 *out_iPlayTime, __int64 *out_iPlayTimeAudible)
{
  CAkMusicSwitchTransition *v3; // rbx
  __int64 *v4; // rdi
  __int64 *v5; // rsi
  CAkMusicSwitchTransition *i; // rbx
  __int64 v7; // rcx
  __int64 v8; // rcx
  __int64 v9; // [rsp+30h] [rbp+8h]
  __int64 v10; // [rsp+48h] [rbp+20h]

  v3 = this->m_queueTransitions.m_pFirst;
  v4 = out_iPlayTimeAudible;
  v5 = out_iPlayTime;
  if ( v3 )
  {
    if ( !this->m_pParentCtx && v3->pNextItem )
      v3 = v3->pNextItem;
    ((void (__fastcall *)(CAkMatrixAwareCtx *, __int64 *, __int64 *))v3->m_pDestCtx.m_pT->vfptr[2].OnLastFrame)(
      v3->m_pDestCtx.m_pT,
      &v9,
      &v10);
    *v5 = v9 + v3->m_pDestCtx.m_pT->m_iLocalTime;
    *v4 = v10 + v3->m_pDestCtx.m_pT->m_iLocalTime;
    for ( i = v3->pNextItem; i; i = i->pNextItem )
    {
      ((void (__fastcall *)(CAkMatrixAwareCtx *, __int64 *, __int64 *))i->m_pDestCtx.m_pT->vfptr[2].OnLastFrame)(
        i->m_pDestCtx.m_pT,
        &v9,
        &v10);
      v7 = i->m_pDestCtx.m_pT->m_iLocalTime + v9;
      v9 = v7;
      if ( v7 < *v5 )
        *v5 = v7;
      v8 = i->m_pDestCtx.m_pT->m_iLocalTime + v10;
      v10 = v8;
      if ( v8 < *v4 )
        *v4 = v8;
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
  bool result; // al

  v1 = *((_BYTE *)&this->0 + 98);
  if ( v1 & 1 || !(v1 & 0xF) )
    result = ((__int64 (*)(void))this->m_queueTransitions.m_pLast->m_pDestCtx.m_pT->vfptr[2].OnResumed)();
  else
    result = 0;
  return result;
}

// File Line: 750
// RVA: 0xAB7C90
void __fastcall CAkMusicSwitchCtx::CancelPlayback(CAkMusicSwitchCtx *this, __int64 in_iCurrentTime)
{
  char v2; // al
  CAkMusicSwitchCtx *v3; // rbx
  double v4; // xmm1_8
  double v5; // xmm0_8
  TransParams in_transParams; // [rsp+30h] [rbp+8h]

  v2 = *((_BYTE *)&this->0 + 98);
  ++this->m_uRefCount;
  v3 = this;
  if ( v2 & 0xF )
  {
    if ( v2 & 1 )
    {
      v4 = (double)(LODWORD(this->m_iLocalTime) - (signed int)in_iCurrentTime)
         * 1000.0
         / (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency;
      if ( v4 <= 0.0 )
        v5 = DOUBLE_N0_5;
      else
        v5 = DOUBLE_0_5;
      in_transParams.eFadeCurve = 4;
      in_transParams.TransitionTime = (signed int)(v5 + v4);
      CAkMusicCtx::_Stop((CAkMusicCtx *)&this->vfptr, &in_transParams, 0xFFFFFFFFi64);
    }
    CAkMusicCtx::Release((CAkMusicCtx *)&v3->vfptr);
  }
  else
  {
    ((void (__fastcall *)(CAkMusicSwitchCtx *, __int64))this->vfptr[1].OnPaused)(this, in_iCurrentTime);
    CAkMusicCtx::Release((CAkMusicCtx *)&v3->vfptr);
  }
}

// File Line: 777
// RVA: 0xAB7FC0
void __fastcall CAkMusicSwitchCtx::GetNextScheduleWindow(CAkMusicSwitchCtx *this, CAkScheduleWindow *io_window, bool in_bDoNotGrow)
{
  CAkScheduleWindow *v3; // rbx
  CAkMusicSwitchCtx *v4; // rdi
  bool v5; // si
  CAkMusicSwitchTransition *v6; // rax
  CAkMusicSwitchTransition *v7; // rax
  signed __int64 v8; // rdi
  CAkMusicSwitchTransition *v9; // rax
  unsigned __int64 v10; // rdi
  AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator in_itTrans; // [rsp+38h] [rbp+10h]
  AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator v12; // [rsp+48h] [rbp+20h]

  ++io_window->m_uLevel;
  v3 = io_window;
  v4 = this;
  v5 = in_bDoNotGrow;
  CAkScheduleWindow::GetBranch(io_window, (CAkMusicSwitchTransition *)&in_itTrans);
  v6 = in_itTrans.pItem;
  if ( !in_itTrans.pItem )
  {
    if ( v4->m_itActiveSwitch.pItem )
    {
      in_itTrans.pItem = v4->m_itActiveSwitch.pItem;
      CAkScheduleWindow::SetBranch(v3, &in_itTrans);
      v6 = in_itTrans.pItem;
    }
    else if ( !v3->m_itScheduledItem.pItem )
    {
      goto LABEL_13;
    }
  }
  ((void (__fastcall *)(CAkMatrixAwareCtx *, CAkScheduleWindow *, bool))v6->m_pDestCtx.m_pT->vfptr[1].VirtualRelease)(
    v6->m_pDestCtx.m_pT,
    v3,
    v5);
  v7 = in_itTrans.pItem->pNextItem;
  in_itTrans.pItem = v7;
  v12.pItem = v7;
  if ( v7 )
  {
    v8 = v7->m_pDestCtx.m_pT->m_iLocalTime;
    if ( (signed __int64)CAkScheduleWindow::StartTimeRelativeToCurrentLevel(v3) < v8 )
    {
LABEL_9:
      if ( v12.pItem )
      {
        v10 = v8 - CAkScheduleWindow::StartTimeRelativeToCurrentLevel(v3);
        if ( v3->m_bIsDurationInfinite || v3->m_uWindowDuration > v10 )
          CAkScheduleWindow::SetDuration(v3, v10, 0);
      }
    }
    else
    {
      while ( 1 )
      {
        CAkScheduleWindow::SetBranch(v3, &v12);
        ((void (__fastcall *)(CAkMatrixAwareCtx *, CAkScheduleWindow *, bool))v12.pItem->m_pDestCtx.m_pT->vfptr[1].VirtualRelease)(
          v12.pItem->m_pDestCtx.m_pT,
          v3,
          v5);
        v9 = v12.pItem->pNextItem;
        v12.pItem = v9;
        if ( !v9 )
          break;
        v8 = v9->m_pDestCtx.m_pT->m_iLocalTime;
        if ( (signed __int64)CAkScheduleWindow::StartTimeRelativeToCurrentLevel(v3) < v8 )
          goto LABEL_9;
      }
    }
  }
LABEL_13:
  --v3->m_uLevel;
}

// File Line: 851
// RVA: 0xAB8D20
void __fastcall CAkMusicSwitchCtx::RefreshWindow(CAkMusicSwitchCtx *this, CAkScheduleWindow *io_window)
{
  CAkScheduleWindow *v2; // rbx
  __int64 v3; // rax
  __int64 v4; // rdi
  unsigned __int64 v5; // rdi
  __int64 v6; // [rsp+38h] [rbp+10h]

  ++io_window->m_uLevel;
  v2 = io_window;
  CAkScheduleWindow::GetBranch(io_window, (CAkMusicSwitchTransition *)&v6);
  (*(void (__fastcall **)(_QWORD, CAkScheduleWindow *))(**(_QWORD **)(v6 + 8) + 104i64))(*(_QWORD *)(v6 + 8), v2);
  v3 = *(_QWORD *)v6;
  v6 = v3;
  if ( v3 )
  {
    v4 = *(_QWORD *)(*(_QWORD *)(v3 + 8) + 112i64);
    v5 = v4 - CAkScheduleWindow::StartTimeRelativeToCurrentLevel(v2);
    if ( v2->m_bIsDurationInfinite || v2->m_uWindowDuration > v5 )
      CAkScheduleWindow::SetDuration(v2, v5, 0);
    --v2->m_uLevel;
  }
  else
  {
    --v2->m_uLevel;
  }
}

// File Line: 919
// RVA: 0xAB8640
void __fastcall CAkMusicSwitchCtx::OnPlayed(CAkMusicSwitchCtx *this, __int64 a2, __int64 a3)
{
  CAkMusicSwitchCtx *v3; // rbx
  CAkMusicSwitchTransition *v4; // rcx
  AkMusicFade in_fadeParams; // [rsp+20h] [rbp-18h]

  v3 = this;
  if ( !(*((_BYTE *)&this->0 + 98) & 0xF) )
  {
    this->m_queueTransitions.m_pFirst->m_pDestCtx.m_pT->m_iLocalTime = 0i64;
    v4 = this->m_queueTransitions.m_pFirst;
    in_fadeParams.transitionTime = 0;
    *(_QWORD *)&in_fadeParams.eFadeCurve = 4i64;
    CAkMusicCtx::_Play((CAkMusicCtx *)&v4->m_pDestCtx.m_pT->vfptr, &in_fadeParams, a3);
  }
  CAkMusicCtx::OnPlayed((CAkMusicCtx *)&v3->vfptr);
}

// File Line: 937
// RVA: 0xAB8690
void __fastcall CAkMusicSwitchCtx::OnStopped(CAkMusicSwitchCtx *this)
{
  CAkMusicSwitchCtx *v1; // rdi
  CAkMusicSwitchTransition *v2; // rbx
  CAkMusicSwitchTransition *v3; // rax
  CAkMusicSwitchTransition *v4; // rsi
  CAkMusicCtx *v5; // rcx
  int v6; // ebp
  CAkMusicCtx *v7; // rcx
  CAkMusicSwitchTransition *v8; // rax
  char v9; // al
  __m128i v10; // [rsp+20h] [rbp-28h]
  __m128i v11; // [rsp+30h] [rbp-18h]

  ++this->m_uRefCount;
  v1 = this;
  if ( this->m_switchMonitors.m_pItems )
  {
    AkArray<CAkMusicSwitchMonitor,CAkMusicSwitchMonitor const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::RemoveAll(&this->m_switchMonitors);
    AK::MemoryMgr::Free(g_DefaultPoolId, v1->m_switchMonitors.m_pItems);
    v1->m_switchMonitors.m_pItems = 0i64;
    v1->m_switchMonitors.m_ulReserved = 0;
  }
  v2 = v1->m_queueTransitions.m_pFirst;
  v3 = 0i64;
  if ( v2 )
  {
    while ( 1 )
    {
      v4 = v2->pNextItem;
      v10.m128i_i64[1] = (__int64)v3;
      v10.m128i_i64[0] = (__int64)v2->pNextItem;
      if ( v2 == v1->m_queueTransitions.m_pFirst )
        v1->m_queueTransitions.m_pFirst = v4;
      else
        v3->pNextItem = v4;
      if ( v2 == v1->m_queueTransitions.m_pLast )
        v1->m_queueTransitions.m_pLast = v3;
      v5 = (CAkMusicCtx *)&v2->m_pDestCtx.m_pT->vfptr;
      v6 = g_DefaultPoolId;
      _mm_store_si128(&v11, v10);
      v2->m_pDestCtx.m_pT = 0i64;
      if ( v5 )
        CAkMusicCtx::Release(v5);
      v7 = (CAkMusicCtx *)&v2->m_pDestCtx.m_pT->vfptr;
      if ( v7 )
      {
        CAkMusicCtx::Release(v7);
        v2->m_pDestCtx.m_pT = 0i64;
      }
      AK::MemoryMgr::Free(v6, v2);
      if ( !v4 )
        break;
      v3 = (CAkMusicSwitchTransition *)v11.m128i_i64[1];
      v2 = (CAkMusicSwitchTransition *)v11.m128i_i64[0];
    }
  }
  v8 = v1->m_queueTransitions.m_pFirst;
  v1->m_queueTransitions.m_pFirst = 0i64;
  v1->m_itActiveSwitch.pItem = v8;
  v1->m_queueTransitions.m_pLast = 0i64;
  v9 = *((_BYTE *)v1 + 184);
  if ( v9 & 2 )
  {
    *((_BYTE *)v1 + 184) = v9 & 0xFD;
    CAkMusicCtx::Release((CAkMusicCtx *)&v1->vfptr);
  }
  CAkMatrixAwareCtx::OnStopped((CAkMatrixAwareCtx *)&v1->vfptr);
  CAkMusicCtx::Release((CAkMusicCtx *)&v1->vfptr);
}

// File Line: 966
// RVA: 0xAB8630
CAkMusicSwitchCntr *__fastcall CAkMusicSwitchCtx::Node(CAkMusicSwitchCtx *this)
{
  return this->m_pSwitchCntrNode;
}

// File Line: 974
// RVA: 0xABA4B0
void __fastcall CAkMusicSwitchCtx::Sync(CAkMusicSwitchCtx *this, AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator *in_itNewTransition)
{
  CAkMusicSwitchCtx *v2; // rbx
  int v3; // eax
  CAkMusicSegment *v4; // rax
  CAkMusicNode *v5; // rcx
  CAkParameterNodeBase **v6; // rax
  CAkMusicSwitchCtx *v7; // rcx
  CAkMusicSwitchTransition *i; // rbx
  CAkMatrixAwareCtx *v9; // rcx
  CAkScheduleWindow v10; // [rsp+20h] [rbp-138h]
  CAkMusicNode *out_ppParentNode; // [rsp+160h] [rbp+8h]

  v2 = this;
  this->m_itActiveSwitch = (AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator)in_itNewTransition->pItem;
  v3 = CAkMatrixSequencer::GetMusicSyncFlags(this->m_pSequencer);
  if ( _bittest(&v3, 0xEu) )
  {
    CAkScheduleWindow::CAkScheduleWindow(&v10, (CAkMatrixAwareCtx *)&v2->vfptr, 0);
    if ( v10.m_itScheduledItem.pItem )
    {
      v4 = CAkScheduleWindow::GetNode(&v10, &out_ppParentNode);
      v5 = out_ppParentNode;
      if ( v4 )
        v5 = (CAkMusicNode *)&v4->vfptr;
      v6 = CAkMusicNode::GetMusicGrid(v5);
      CAkPlayingMgr::NotifyMusic(
        g_pPlayingMgr,
        v2->m_pSequencer->m_UserParams.m_PlayingID,
        AK_MusicSyncPoint,
        (AkMusicGrid *)v6);
    }
    _((AMD_HD3D *)&v10);
  }
  if ( !v2->m_itActiveSwitch.pItem->pNextItem )
  {
    v7 = (CAkMusicSwitchCtx *)v2->m_pParentCtx;
    if ( !v7 || !CAkMusicSwitchCtx::HasOrAscendentHasPendingTransition(v7) )
    {
      for ( i = v2->m_queueTransitions.m_pFirst; i; i = i->pNextItem )
      {
        v9 = i->m_pDestCtx.m_pT;
        if ( v9 )
          ((void (*)(void))v9->vfptr[2].VirtualAddRef)();
      }
    }
  }
}

// File Line: 1014
// RVA: 0xABA590
void __fastcall CAkMusicSwitchCtx::TryPropagateDelayedSwitchChange(CAkMusicSwitchCtx *this)
{
  CAkMusicSwitchCtx *v1; // rbx
  CAkMusicSwitchCtx *v2; // rcx
  CAkMusicSwitchTransition *i; // rbx
  CAkMatrixAwareCtx *v4; // rcx

  v1 = this;
  if ( !this->m_itActiveSwitch.pItem->pNextItem )
  {
    v2 = (CAkMusicSwitchCtx *)this->m_pParentCtx;
    if ( !v2 || !CAkMusicSwitchCtx::HasOrAscendentHasPendingTransition(v2) )
    {
      for ( i = v1->m_queueTransitions.m_pFirst; i; i = i->pNextItem )
      {
        v4 = i->m_pDestCtx.m_pT;
        if ( v4 )
          ((void (*)(void))v4->vfptr[2].VirtualAddRef)();
      }
    }
  }
}

// File Line: 1033
// RVA: 0xAB7D80
CAkChainCtx *__fastcall CAkMusicSwitchCtx::CreateDestinationContext(CAkMusicSwitchCtx *this, unsigned int in_ID)
{
  CAkMusicSwitchCtx *v2; // rdi
  CAkChainCtx *result; // rax
  CAkChainCtx *v4; // rax
  CAkChainCtx *v5; // rbx
  __int64 v6; // rax

  v2 = this;
  if ( !in_ID || (result = (CAkChainCtx *)CAkMusicSwitchCtx::CreateMusicContext(this, in_ID)) == 0i64 )
  {
    v4 = (CAkChainCtx *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xA0ui64);
    v5 = v4;
    if ( v4 )
    {
      CAkChainCtx::CAkChainCtx(v4, (CAkMusicCtx *)&v2->vfptr);
      LOBYTE(v5[1].vfptr) = 0;
      v5->vfptr = (CAkChildCtxVtbl *)&CAkNothingCtx::`vftable'{for `CAkChildCtx'};
      v5->vfptr = (CAkTransportAwareVtbl *)&CAkNothingCtx::`vftable'{for `CAkTransportAware'};
      v5->vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable'{for `ITransitionable'};
      ++v5->m_uRefCount;
      if ( (unsigned int)CAkMatrixAwareCtx::Init(
                           (CAkMatrixAwareCtx *)&v5->vfptr,
                           v2->m_pSequencer->m_pGameObj,
                           &v2->m_pSequencer->m_UserParams) == 1 )
      {
        CAkChainCtx::EnqueueItem(v5, 0i64, 0i64);
        if ( v6 )
        {
          ++v5->m_uRefCount;
          LOBYTE(v5[1].vfptr) = 1;
          CAkMusicCtx::Release((CAkMusicCtx *)&v5->vfptr);
          return v5;
        }
      }
      UFG::OnUnloadClass<UITest::HandleArrayTest>((CAkMusicCtx *)&v5->vfptr);
      CAkMusicCtx::Release((CAkMusicCtx *)&v5->vfptr);
    }
    result = 0i64;
  }
  return result;
}

// File Line: 1071
// RVA: 0xAB7E60
CAkIndexable *__fastcall CAkMusicSwitchCtx::CreateMusicContext(CAkMusicSwitchCtx *this, unsigned int in_ID)
{
  CAkMusicSwitchCtx *v2; // rbx
  CAkIndexable *result; // rax
  CAkMatrixAwareCtx *v4; // rdi
  CAkMatrixAwareCtx *v5; // rbx

  v2 = this;
  result = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_ID, 0);
  v4 = (CAkMatrixAwareCtx *)result;
  if ( result )
  {
    v5 = (CAkMatrixAwareCtx *)((__int64 (__fastcall *)(CAkIndexable *, CAkMusicSwitchCtx *, CAkRegisteredObj *, UserParams *))result->vfptr[21].__vecDelDtor)(
                                result,
                                v2,
                                v2->m_pSequencer->m_pGameObj,
                                &v2->m_pSequencer->m_UserParams);
    v4->vfptr->OnResumed((CAkChildCtx *)&v4->vfptr);
    result = (CAkIndexable *)v5;
  }
  return result;
}

// File Line: 1094
// RVA: 0xAB8F30
void __fastcall CAkMusicSwitchCtx::ScheduleSwitchTransition(CAkMusicSwitchCtx *this, unsigned int in_destinationID, CAkMusicSwitchCtx::TransitionInfo *in_transitionInfo, CAkMatrixAwareCtx **io_pNewContext)
{
  CAkMatrixSequencer *v4; // rax
  unsigned __int64 v5; // rbx
  CAkMusicSwitchCtx *v6; // rdi
  CAkMatrixAwareCtx *v7; // rcx
  unsigned __int64 v8; // rsi
  CAkMusicCtx **v9; // r14
  CAkMusicSwitchTransition *v10; // r13
  CAkMusicSwitchTransition *v11; // r15
  CAkMusicSwitchTransition *v12; // rax
  CAkMusicSwitchTransition *v13; // r12
  CAkMusicSwitchTransition *v14; // rsi
  CAkMusicSwitchTransition *i; // rcx
  CAkMusicSwitchTransition *v16; // rax
  CAkMusicSwitchTransition *v17; // rdx
  __m128i v18; // xmm0
  CAkMusicSwitchTransition *v19; // rax
  CAkMusicSwitchCntr *v20; // rcx
  CAkMusicSwitchTransition *v21; // rbx
  __int64 v22; // rax
  bool v23; // zf
  CAkMusicSwitchTransition *v24; // rax
  CAkMusicCtx *v25; // r12
  AkMusicTransitionRule *v26; // rax
  CAkMusicCtx *v27; // r14
  AkMusicTransitionRule *v28; // rbx
  unsigned int *v29; // rax
  unsigned int v30; // edx
  CAkIndexable *v31; // rax
  CAkIndexable *v32; // r14
  CAkMatrixAwareCtx *v33; // rax
  CAkIndexableVtbl *v34; // rdx
  CAkMatrixAwareCtx *v35; // r14
  CAkMatrixAwareCtx *v36; // r14
  CAkMusicSwitchTransition *v37; // rax
  CAkMusicSwitchTransition *v38; // rax
  AkSyncType v39; // edx
  int v40; // er14
  int v41; // er15
  AkCurveInterpolation v42; // eax
  int v43; // eax
  unsigned int v44; // eax
  unsigned int v45; // eax
  AkMusicTransitionObject *v46; // rcx
  int v47; // eax
  int v48; // eax
  AkMusicTransitionObject *v49; // rcx
  AkCurveInterpolation v50; // eax
  int v51; // ebx
  unsigned int v52; // er12
  CAkMusicSegment *v53; // rax
  int v54; // er8
  int v55; // eax
  signed int v56; // er14
  signed int v57; // edx
  int v58; // er12
  __int64 v59; // rcx
  signed int v60; // eax
  signed __int64 v61; // rbx
  signed int v62; // eax
  __int64 v63; // rbx
  signed int v64; // eax
  AkSyncType v65; // ecx
  bool in_bDoSkipEntryCue; // al
  AKRESULT v67; // er14
  CAkMusicSwitchTransition *k; // rcx
  CAkMusicSwitchTransition *v69; // rax
  CAkMusicSwitchTransition *v70; // rdx
  __m128i v71; // xmm0
  bool v72; // al
  __int16 v73; // cx
  CAkMusicSwitchTransition *v74; // rbx
  unsigned __int64 v75; // rax
  unsigned int v76; // eax
  int v77; // eax
  CAkMusicSegment *v78; // rax
  AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator v79; // rax
  CAkMusicSwitchTransition *v80; // rcx
  CAkMusicSwitchTransition *v81; // rbx
  CAkMusicSwitchTransition *v82; // rax
  CAkMusicSwitchTransition *v83; // rdx
  __m128i v84; // xmm0
  __int64 v85; // rax
  bool v86; // zf
  __int64 v87; // rbx
  CAkMusicSwitchTransition *v88; // rcx
  CAkMusicSwitchTransition *v89; // rbx
  char v90; // al
  int v91; // eax
  CAkMusicCtx *v92; // rcx
  __int64 v93; // r8
  CAkMusicSwitchTransition *m; // rcx
  CAkMusicSwitchTransition *v95; // rax
  CAkMusicSwitchTransition *v96; // rdx
  __m128i v97; // xmm0
  CAkMusicSwitchTransition *v98; // rbx
  char v99; // al
  int v100; // eax
  CAkMusicCtx *v101; // rcx
  __int64 v102; // r8
  CAkMusicSwitchTransition *v103; // rbx
  CAkMusicSwitchTransition *v104; // rax
  CAkMusicSwitchTransition *v105; // rdi
  __m128i v106; // xmm0
  CAkMusicCtx *v107; // rcx
  CAkMusicCtx *v108; // rcx
  int v109; // er14
  CAkMusicCtx *v110; // rcx
  __int64 in_bSucceedOnNothing; // [rsp+28h] [rbp-D8h]
  __int64 in_bSucceedOnNothinga; // [rsp+28h] [rbp-D8h]
  int in_iDestinationLookAhead; // [rsp+50h] [rbp-B0h]
  AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator in_itTrans; // [rsp+58h] [rbp-A8h]
  AkSyncType in_eSyncType; // [rsp+60h] [rbp-A0h]
  unsigned int io_uCueFilter; // [rsp+64h] [rbp-9Ch]
  CAkMatrixAwareCtx *v117; // [rsp+68h] [rbp-98h]
  CAkMusicSwitchTransition *in_pNewTransition; // [rsp+70h] [rbp-90h]
  __int64 in_iCurrentTime; // [rsp+78h] [rbp-88h]
  AkMusicTransDestRule v120; // [rsp+80h] [rbp-80h]
  char v121; // [rsp+98h] [rbp-68h]
  unsigned __int32 v122; // [rsp+9Ch] [rbp-64h]
  AkListBare<CAkMusicSwitchTransition,AkListBareNextItem<CAkMusicSwitchTransition>,AkCountPolicyNoCount>::Iterator v123; // [rsp+A0h] [rbp-60h]
  unsigned __int128 v124; // [rsp+B0h] [rbp-50h]
  void *in_pvMemAddress; // [rsp+C0h] [rbp-40h]
  AkMusicTransSrcRule v126; // [rsp+C8h] [rbp-38h]
  unsigned __int128 v127; // [rsp+E0h] [rbp-20h]
  unsigned __int128 v128; // [rsp+F0h] [rbp-10h]
  unsigned int v129; // [rsp+100h] [rbp+0h]
  unsigned int io_uSrcSegmentLookAhead; // [rsp+104h] [rbp+4h]
  AkMusicTransDestRule in_ruleTo; // [rsp+108h] [rbp+8h]
  AkListBareLight<AkAssociatedAction,AkListBareLightNextItem<AkAssociatedAction> > in_listActions; // [rsp+120h] [rbp+20h]
  unsigned int v133; // [rsp+128h] [rbp+28h]
  __int64 out_iSyncTime[2]; // [rsp+130h] [rbp+30h]
  AkMusicTransSrcRule in_ruleFrom; // [rsp+140h] [rbp+40h]
  CAkMusicSwitchTransition *l; // [rsp+158h] [rbp+58h]
  __int64 in_iMinTime; // [rsp+160h] [rbp+60h]
  char v138; // [rsp+168h] [rbp+68h]
  __int128 v139; // [rsp+170h] [rbp+70h]
  unsigned __int128 v140; // [rsp+180h] [rbp+80h]
  CAkScheduleWindow in_source; // [rsp+190h] [rbp+90h]
  CAkScheduleWindow v142; // [rsp+2C0h] [rbp+1C0h]
  char j; // [rsp+440h] [rbp+340h]
  unsigned int v144; // [rsp+448h] [rbp+348h]
  CAkMusicSwitchCtx::TransitionInfo *v145; // [rsp+450h] [rbp+350h]
  CAkMatrixAwareCtx **v146; // [rsp+458h] [rbp+358h]

  v146 = io_pNewContext;
  v145 = in_transitionInfo;
  v144 = in_destinationID;
  v4 = this->m_pSequencer;
  v5 = this->m_iLocalTime;
  v6 = this;
  v7 = (CAkMatrixAwareCtx *)this->m_pParentCtx;
  v8 = v4->m_uTime;
  v9 = (CAkMusicCtx **)io_pNewContext;
  if ( v7 )
    v5 += CAkMatrixAwareCtx::GetAbsoluteTimeOffset(v7);
  v10 = 0i64;
  v11 = 0i64;
  in_pNewTransition = 0i64;
  in_iCurrentTime = v8 - v5;
  CAkScheduleWindow::CAkScheduleWindow(&in_source, (CAkMatrixAwareCtx *)&v6->vfptr, 0);
  if ( !in_source.m_itScheduledItem.pItem )
  {
    UFG::OnUnloadClass<UITest::HandleArrayTest>(*v9);
    *v9 = 0i64;
    goto LABEL_218;
  }
  v12 = v6->m_pLastNonCancelledTransitionInFrame;
  in_pvMemAddress = 0i64;
  v13 = 0i64;
  v14 = 0i64;
  if ( v12 )
  {
    for ( i = v6->m_queueTransitions.m_pFirst; i; i = i->pNextItem )
    {
      if ( i == v12 )
        break;
    }
    v16 = i->pNextItem;
    if ( i->pNextItem )
    {
      while ( 1 )
      {
        v17 = v16->pNextItem;
        v124 = __PAIR__((unsigned __int64)i, v16->pNextItem);
        if ( v16 == v6->m_queueTransitions.m_pFirst )
          v6->m_queueTransitions.m_pFirst = v17;
        else
          i->pNextItem = v17;
        if ( v16 == v6->m_queueTransitions.m_pLast )
          v6->m_queueTransitions.m_pLast = i;
        v18 = (__m128i)v124;
        v16->pNextItem = 0i64;
        _mm_store_si128((__m128i *)out_iSyncTime, v18);
        if ( v14 )
          v14->pNextItem = v16;
        else
          v13 = v16;
        v14 = v16;
        if ( !v17 )
          break;
        i = (CAkMusicSwitchTransition *)out_iSyncTime[1];
        v16 = (CAkMusicSwitchTransition *)out_iSyncTime[0];
      }
      in_pvMemAddress = v13;
    }
    ((void (__fastcall *)(CAkMusicSwitchCtx *, CAkScheduleWindow *))v6->vfptr[1].~CAkChildCtx)(v6, &in_source);
  }
  v19 = CAkMusicSwitchCtx::FindLastNonCancellableTransition(v6);
  v20 = v6->m_pSwitchCntrNode;
  v21 = v19;
  l = v19;
  if ( !v20->m_bIsContinuePlayback
    || v145->pSeekingInfo
    || ((v22 = ((__int64 (*)(void))v19->m_pDestCtx.m_pT->vfptr[2].OnPaused)()) == 0 ? (v23 = v144 == 0) : (v23 = *(_DWORD *)(v22 + 16) == v144),
        !v23) )
  {
    if ( ((unsigned __int8 (*)(void))v21->m_pDestCtx.m_pT->vfptr[2].OnResumed)() )
    {
      v24 = v6->m_queueTransitions.m_pFirst;
      ++in_source.m_uLevel;
      for ( j = 1; v24; v24 = v24->pNextItem )
      {
        if ( v24 == v21 )
          break;
      }
      in_itTrans.pItem = v24;
      if ( CAkScheduleWindow::GetBranch(&in_source, (CAkMusicSwitchTransition *)out_iSyncTime).pItem->pNextItem != v24 )
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
        if ( (*((_BYTE *)in_source.m_itScheduledItem.pItem + 60) >> 2) & 1 )
        {
LABEL_172:
          if ( j )
          {
            if ( v10 )
            {
              v88 = v10;
              if ( v11 )
              {
                CAkMusicSwitchTransition::Cancel(v10);
                v88 = v11;
              }
              CAkMusicSwitchTransition::Dispose(v88);
            }
            if ( *v9 )
            {
              UFG::OnUnloadClass<UITest::HandleArrayTest>(*v9);
              *v9 = 0i64;
            }
            if ( ((unsigned __int8 (*)(void))v6->m_queueTransitions.m_pLast->m_pDestCtx.m_pT->vfptr[2].OnResumed)() )
            {
              v89 = v6->m_queueTransitions.m_pLast;
              v90 = *((_BYTE *)v89 + 72);
              if ( !(v90 & 4) || v90 & 2 )
              {
                *((_BYTE *)v89 + 72) = v90 & 0xFD;
              }
              else
              {
                v91 = AkTimeConv::SamplesToMilliseconds((signed int)in_iCurrentTime - LODWORD(v89->m_cmdStop.iRelativeTime));
                v92 = (CAkMusicCtx *)&v89->m_pDestCtx.m_pT->vfptr;
                LODWORD(v124) = v91;
                *(_QWORD *)((char *)&v124 + 4) = (unsigned int)v89->m_cmdStop.transParams.eFadeCurve;
                CAkMusicCtx::_Play(v92, (AkMusicFade *)&v124, v93);
              }
              *((_BYTE *)v89 + 72) &= 0xFBu;
              v89->m_cutoffInfo.bCutoff = 0;
            }
          }
          CAkMatrixSequencer::RescheduleCancelledActions(v6->m_pSequencer, &in_listActions);
          v13 = (CAkMusicSwitchTransition *)in_pvMemAddress;
          goto LABEL_206;
        }
        v26 = CAkMusicSwitchCtx::GetTransitionRule(v6, &in_source, (CAkMatrixAwareCtx **)v9, &io_uSrcSegmentLookAhead);
        v27 = *v9;
        v28 = v26;
        if ( !v27 )
          goto LABEL_171;
        v29 = &v26->pTransObj->segmentID;
        v117 = 0i64;
        if ( !v29 )
        {
          v38 = (CAkMusicSwitchTransition *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
          v10 = v38;
          if ( !v38 )
          {
            v10 = 0i64;
            goto LABEL_171;
          }
          v38->pNextItem = 0i64;
          v38->m_pDestCtx.m_pT = (CAkMatrixAwareCtx *)v27;
          if ( v27 )
            ++v27->m_uRefCount;
          v38->m_cutoffInfo.iCutoffTime = 0i64;
          v38->m_cutoffInfo.bCutoff = 0;
          *((_BYTE *)v38 + 72) &= 0xF8u;
          goto LABEL_65;
        }
        v30 = *v29;
        v117 = 0i64;
        v31 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v30, 0);
        v32 = v31;
        if ( v31 )
        {
          v33 = (CAkMatrixAwareCtx *)((__int64 (__fastcall *)(CAkIndexable *, CAkMusicSwitchCtx *, CAkRegisteredObj *, UserParams *))v31->vfptr[21].__vecDelDtor)(
                                       v31,
                                       v6,
                                       v6->m_pSequencer->m_pGameObj,
                                       &v6->m_pSequencer->m_UserParams);
          v34 = v32->vfptr;
          v25 = (CAkMusicCtx *)&v33->vfptr;
          v117 = v33;
          v34->Release(v32);
        }
        if ( !v25 )
          break;
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
        v35 = *v146;
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
          {
            LODWORD(v25) = 0;
LABEL_65:
            v9 = (CAkMusicCtx **)v146;
            goto LABEL_66;
          }
          CAkMusicSwitchTransition::Cancel(v10);
        }
        else
        {
          UFG::OnUnloadClass<UITest::HandleArrayTest>(v25);
        }
        LODWORD(v25) = 0;
        v117 = 0i64;
        if ( v11 )
        {
          CAkMusicSwitchTransition::Dispose(v11);
          v11 = 0i64;
          in_pNewTransition = 0i64;
        }
        v9 = (CAkMusicCtx **)v146;
        v10 = CAkMusicSwitchTransition::Create(*v146);
LABEL_66:
        if ( !v10 )
          goto LABEL_172;
        v39 = *((_DWORD *)&v28->srcRule + 4);
        v40 = v28->srcRule.fadeParams.transitionTime;
        v41 = v28->srcRule.fadeParams.iFadeOffset;
        in_ruleFrom.fadeParams.eFadeCurve = v28->srcRule.fadeParams.eFadeCurve;
        v129 = v28->srcRule.uCueFilterHash;
        in_ruleFrom.uCueFilterHash = v129;
        v120.fadeParams.transitionTime = v28->destRule.fadeParams.transitionTime;
        v42 = v28->destRule.fadeParams.eFadeCurve;
        in_ruleFrom.fadeParams.transitionTime = v40;
        v120.fadeParams.eFadeCurve = v42;
        v43 = v28->destRule.fadeParams.iFadeOffset;
        in_ruleFrom.fadeParams.iFadeOffset = v41;
        v120.fadeParams.iFadeOffset = v43;
        v44 = v28->destRule.uCueFilterHash;
        in_eSyncType = v39;
        v120.uCueFilterHash = v44;
        v45 = v28->destRule.uJumpToID;
        *((_DWORD *)&in_ruleFrom + 4) = v39;
        v120.uJumpToID = v45;
        *((_DWORD *)&v120 + 5) = *((_DWORD *)&v28->destRule + 5);
        v46 = v28->pTransObj;
        if ( v46 )
        {
          v47 = v46->fadeInParams.transitionTime;
          v126.uCueFilterHash = 0;
          in_ruleTo.fadeParams.transitionTime = v47;
          in_ruleTo.fadeParams.eFadeCurve = v46->fadeInParams.eFadeCurve;
          v48 = v46->fadeInParams.iFadeOffset;
          in_ruleTo.uCueFilterHash = (unsigned int)v25;
          in_ruleTo.fadeParams.iFadeOffset = v48;
          *((_WORD *)&in_ruleTo + 10) &= 0xFFF8u;
          *((_WORD *)&in_ruleTo + 10) = *((_WORD *)&in_ruleTo + 10) & 0xFFE7 | 8 * (*((_WORD *)v28->pTransObj + 14) & 1);
          v49 = v28->pTransObj;
          v50 = v49->fadeOutParams.eFadeCurve;
          v51 = v49->fadeOutParams.transitionTime;
          v52 = v49->fadeOutParams.iFadeOffset;
          LODWORD(v49) = *((_DWORD *)v49 + 7);
          v126.fadeParams.eFadeCurve = v50;
          v126.fadeParams.transitionTime = v51;
          *(_QWORD *)&v126.fadeParams.iFadeOffset = v52;
          v122 = *((_DWORD *)&v126 + 4) & 0xFFFFFFC7 | 16 * ((unsigned __int8)v49 & 2) | 7;
          *((_DWORD *)&v126 + 4) = *((_DWORD *)&v126 + 4) & 0xFFFFFFC7 | 16 * ((unsigned __int8)v49 & 2) | 7;
        }
        else
        {
          *(_QWORD *)&in_ruleTo.uJumpToID = *(_QWORD *)&v120.uJumpToID;
          v122 = v39;
          *(_QWORD *)&in_ruleTo.fadeParams.transitionTime = *(_QWORD *)&v120.fadeParams.transitionTime;
          *((_DWORD *)&v126 + 4) = v39;
          *(_QWORD *)&in_ruleTo.fadeParams.iFadeOffset = *(_QWORD *)&v120.fadeParams.iFadeOffset;
          *(_QWORD *)&v126.fadeParams.transitionTime = *(_QWORD *)&in_ruleFrom.fadeParams.transitionTime;
          v51 = in_ruleFrom.fadeParams.transitionTime;
          *(_QWORD *)&v126.fadeParams.iFadeOffset = *(_QWORD *)&in_ruleFrom.fadeParams.iFadeOffset;
          v52 = in_ruleFrom.fadeParams.iFadeOffset;
        }
        if ( v145->bOverrideEntryType )
          *((_WORD *)&v120 + 10) ^= (LOWORD(v145->eEntryType) ^ *((_WORD *)&v120 + 10)) & 7;
        LODWORD(in_bSucceedOnNothing) = 0;
        LODWORD(v123.pItem) = ((__int64 (__fastcall *)(CAkMatrixAwareCtx *, AkMusicTransDestRule *, _QWORD, AkSeekingInfo *, char *, __int64))(*v146)->vfptr[1].VirtualAddRef)(
                                *v146,
                                &v120,
                                0i64,
                                v145->pSeekingInfo,
                                &v121,
                                in_bSucceedOnNothing);
        out_iSyncTime[0] = 0i64;
        CAkScheduleWindow::CAkScheduleWindow(&v142, 1);
        if ( in_pNewTransition )
        {
          LODWORD(in_bSucceedOnNothinga) = 0;
          in_iDestinationLookAhead = ((__int64 (__fastcall *)(CAkMatrixAwareCtx *, AkMusicTransDestRule *, _QWORD, _QWORD, char *, __int64))v117->vfptr[1].VirtualAddRef)(
                                       v117,
                                       &in_ruleTo,
                                       0i64,
                                       0i64,
                                       &v138,
                                       in_bSucceedOnNothinga);
          v53 = CAkMatrixAwareCtx::GetFirstSegmentNode(v117, 0i64);
          if ( v53 )
            v54 = CAkMusicSegment::ActiveDuration(v53);
          else
            v54 = 0;
          v55 = in_iDestinationLookAhead;
          v56 = AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8 * v40 - v41;
          if ( v56 > in_iDestinationLookAhead )
            v55 = v56;
          v57 = v51 * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8) - v52;
          v58 = (int)v123.pItem;
          v59 = in_iCurrentTime + v55;
          v60 = (signed int)v123.pItem;
          if ( v57 > SLODWORD(v123.pItem) )
            v60 = v57;
          v61 = v60 - (signed __int64)v54;
          v62 = (signed int)v123.pItem;
          v63 = in_iCurrentTime + v61;
          if ( v59 > v63 )
            v63 = v59;
          if ( v57 > SLODWORD(v123.pItem) )
            v62 = v57;
          in_iMinTime = in_iCurrentTime + v62;
        }
        else
        {
          v58 = (int)v123.pItem;
          in_iMinTime = 0i64;
          v64 = (signed int)v123.pItem;
          in_iDestinationLookAhead = (int)v123.pItem;
          if ( (signed int)(v40 * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8) - v41) > SLODWORD(v123.pItem) )
            v64 = v40 * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8) - v41;
          v63 = in_iCurrentTime + v64;
        }
        v11 = in_pNewTransition;
        v133 = 0;
        v65 = in_eSyncType & 0x1F;
        for ( in_eSyncType &= 0x1Fu; ; v65 = in_eSyncType )
        {
          io_uCueFilter = v129;
          in_bDoSkipEntryCue = (*((_BYTE *)&v120 + 20) & 7) == 1
                            || *((_BYTE *)&v120 + 20) & 0x10
                            && (unsigned __int16)((*((_BYTE *)&v120 + 20) & 7) - 2) <= 1u;
          v67 = CAkScheduleWindow::FindSyncPoint(
                  &in_source,
                  v63,
                  v65,
                  &io_uCueFilter,
                  in_bDoSkipEntryCue,
                  1,
                  (__int64 *)&in_itTrans);
          if ( v67 == 3 && in_source.m_bIsActiveSegment )
          {
            for ( k = v6->m_queueTransitions.m_pFirst; k; k = k->pNextItem )
            {
              if ( k == l )
                break;
            }
            v69 = k->pNextItem;
            if ( k->pNextItem )
            {
              while ( 1 )
              {
                v70 = v69->pNextItem;
                v140 = __PAIR__((unsigned __int64)k, v69->pNextItem);
                if ( v69 == v6->m_queueTransitions.m_pFirst )
                  v6->m_queueTransitions.m_pFirst = v70;
                else
                  k->pNextItem = v70;
                if ( v69 == v6->m_queueTransitions.m_pLast )
                  v6->m_queueTransitions.m_pLast = k;
                v71 = (__m128i)v140;
                v69->pNextItem = 0i64;
                _mm_store_si128((__m128i *)&v139, v71);
                if ( v14 )
                  v14->pNextItem = v69;
                else
                  in_pvMemAddress = v69;
                v14 = v69;
                if ( !v70 )
                  break;
                k = (CAkMusicSwitchTransition *)*((_QWORD *)&v139 + 1);
                v69 = (CAkMusicSwitchTransition *)v139;
              }
            }
            ((void (__fastcall *)(CAkMusicSwitchCtx *, CAkScheduleWindow *))v6->vfptr[1].~CAkChildCtx)(v6, &in_source);
            v72 = (*((_BYTE *)&v120 + 20) & 7) == 1
               || *((_BYTE *)&v120 + 20) & 0x10 && (unsigned __int16)((*((_BYTE *)&v120 + 20) & 7) - 2) <= 1u;
            v67 = CAkScheduleWindow::FindSyncPoint(
                    &in_source,
                    v63,
                    in_eSyncType,
                    &io_uCueFilter,
                    v72,
                    1,
                    (__int64 *)&in_itTrans);
          }
          if ( v11 && v67 == 1 )
          {
            v10->m_pDestCtx.m_pT->m_iLocalTime = (unsigned __int64)in_itTrans.pItem;
            ++v142.m_uLevel;
            v123.pItem = v10;
            CAkScheduleWindow::SetBranch(&v142, &v123);
            ((void (__fastcall *)(CAkMatrixAwareCtx *, CAkScheduleWindow *, _QWORD))v123.pItem->m_pDestCtx.m_pT->vfptr[1].VirtualRelease)(
              v123.pItem->m_pDestCtx.m_pT,
              &v142,
              0i64);
            --v142.m_uLevel;
            v67 = CAkScheduleWindow::FindSyncPoint(
                    &v142,
                    in_iMinTime,
                    (AkSyncType)(v122 & 0x1F),
                    &v133,
                    1,
                    1,
                    out_iSyncTime);
          }
          v73 = *((_BYTE *)&v120 + 20) & 7;
          if ( v73 != 1 && (!(*((_BYTE *)&v120 + 20) & 0x10) || (unsigned __int16)(v73 - 2) > 1u) )
            break;
          if ( v67 != 1 )
            goto LABEL_162;
          if ( v145->pSeekingInfo || !in_source.m_itScheduledItem.pItem->m_pSegment.m_pT )
            goto LABEL_140;
          if ( v73 == 1 )
          {
            v74 = in_itTrans.pItem;
            v75 = CAkScheduleWindow::ChainCtxTimeRelativeToLevel(&in_source, 0);
            v76 = AkScheduledChain::SelfContainedIter::CtxTimeToSegmentPosition(
                    &in_source.m_itScheduledItem,
                    (__int64)v74 - v75);
            LODWORD(in_bSucceedOnNothing) = 0;
            v77 = ((__int64 (__fastcall *)(CAkMatrixAwareCtx *, AkMusicTransDestRule *, _QWORD, _QWORD, char *, __int64))(*v146)->vfptr[1].VirtualAddRef)(
                    *v146,
                    &v120,
                    v76,
                    0i64,
                    &v121,
                    in_bSucceedOnNothing);
          }
          else
          {
            LODWORD(in_bSucceedOnNothing) = io_uCueFilter;
            v77 = ((__int64 (__fastcall *)(CAkMatrixAwareCtx *, AkMusicTransDestRule *, _QWORD, _QWORD, char *, __int64))(*v146)->vfptr[1].VirtualAddRef)(
                    *v146,
                    &v120,
                    0i64,
                    0i64,
                    &v121,
                    in_bSucceedOnNothing);
          }
          v58 = v77;
          if ( v11 )
          {
            v78 = CAkMatrixAwareCtx::GetFirstSegmentNode(v117, 0i64);
            if ( v78 )
            {
              v77 = v58 - (unsigned __int64)CAkMusicSegment::ActiveDuration(v78);
              if ( v77 < in_iDestinationLookAhead )
                v77 = in_iDestinationLookAhead;
            }
            else
            {
              v77 = v58;
              if ( v58 < in_iDestinationLookAhead )
                v77 = in_iDestinationLookAhead;
            }
          }
          else
          {
            in_iDestinationLookAhead = v77;
          }
          if ( v77 <= (_QWORD)((_QWORD)in_itTrans.pItem - in_iCurrentTime) )
            goto LABEL_140;
          v63 = v77 + in_iCurrentTime;
        }
        if ( v67 != 1 )
        {
LABEL_162:
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
          ((void (__fastcall *)(CAkMusicSwitchCtx *, CAkScheduleWindow *, _QWORD))v6->vfptr[1].VirtualRelease)(
            v6,
            &in_source,
            0i64);
          goto LABEL_166;
        }
LABEL_140:
        ++in_source.m_uLevel;
        v79.pItem = CAkScheduleWindow::GetBranch(&in_source, (CAkMusicSwitchTransition *)&v124).pItem;
        v80 = v6->m_queueTransitions.m_pFirst;
        v81 = v79.pItem->pNextItem;
        --in_source.m_uLevel;
        for ( l = v81; v80; v80 = v80->pNextItem )
        {
          if ( v80 == v81 )
            break;
        }
        v82 = v80->pNextItem;
        if ( v80->pNextItem )
        {
          while ( 1 )
          {
            v83 = v82->pNextItem;
            v127 = __PAIR__((unsigned __int64)v80, v82->pNextItem);
            if ( v82 == v6->m_queueTransitions.m_pFirst )
              v6->m_queueTransitions.m_pFirst = v83;
            else
              v80->pNextItem = v83;
            if ( v82 == v6->m_queueTransitions.m_pLast )
              v6->m_queueTransitions.m_pLast = v80;
            v84 = (__m128i)v127;
            v82->pNextItem = 0i64;
            _mm_store_si128((__m128i *)&v128, v84);
            if ( v14 )
              v14->pNextItem = v82;
            else
              in_pvMemAddress = v82;
            v14 = v82;
            if ( !v83 )
              break;
            v80 = (CAkMusicSwitchTransition *)*((_QWORD *)&v128 + 1);
            v82 = (CAkMusicSwitchTransition *)v128;
          }
        }
        ((void (__fastcall *)(CAkMusicSwitchCtx *, CAkScheduleWindow *))v6->vfptr[1].~CAkChildCtx)(v6, &in_source);
        if ( v6->m_pSwitchCntrNode->m_bIsContinuePlayback && !v145->pSeekingInfo )
        {
          v85 = ((__int64 (*)(void))v81->m_pDestCtx.m_pT->vfptr[2].OnPaused)();
          v86 = v85 ? *(_DWORD *)(v85 + 16) == v144 : v144 == 0;
          if ( v86 )
          {
            _((AMD_HD3D *)&v142);
            goto LABEL_171;
          }
        }
        v6->m_pLastNonCancelledTransitionInFrame = v81;
        v87 = in_iCurrentTime;
        j = 0;
        CAkMusicSwitchCtx::ScheduleTransition(
          v6,
          in_iCurrentTime,
          v10,
          &in_ruleFrom,
          &in_ruleTo,
          &in_source,
          in_iDestinationLookAhead,
          (__int64)in_itTrans.pItem,
          0,
          &in_listActions);
        if ( v11 )
          CAkMusicSwitchCtx::ScheduleTransition(
            v6,
            v87,
            v11,
            &v126,
            &v120,
            &v142,
            v58,
            out_iSyncTime[0],
            1,
            &in_listActions);
LABEL_166:
        _((AMD_HD3D *)&v142);
        v23 = v67 == 1;
        v9 = (CAkMusicCtx **)v146;
        if ( v23 )
          goto LABEL_172;
        v25 = 0i64;
      }
      v36 = *v146;
      v37 = (CAkMusicSwitchTransition *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
      v10 = v37;
      if ( !v37 )
      {
        v10 = 0i64;
LABEL_171:
        v9 = (CAkMusicCtx **)v146;
        goto LABEL_172;
      }
      LODWORD(v25) = 0;
      v37->pNextItem = 0i64;
      v37->m_pDestCtx.m_pT = v36;
      if ( v36 )
        ++v36->m_uRefCount;
      v37->m_cutoffInfo.iCutoffTime = 0i64;
      v37->m_cutoffInfo.bCutoff = 0;
      *((_BYTE *)v37 + 72) &= 0xF8u;
      goto LABEL_65;
    }
  }
  for ( m = v6->m_queueTransitions.m_pFirst; m; m = m->pNextItem )
  {
    if ( m == v21 )
      break;
  }
  v95 = m->pNextItem;
  if ( m->pNextItem )
  {
    while ( 1 )
    {
      v96 = v95->pNextItem;
      v128 = __PAIR__((unsigned __int64)m, v95->pNextItem);
      if ( v95 == v6->m_queueTransitions.m_pFirst )
        v6->m_queueTransitions.m_pFirst = v96;
      else
        m->pNextItem = v96;
      if ( v95 == v6->m_queueTransitions.m_pLast )
        v6->m_queueTransitions.m_pLast = m;
      v97 = (__m128i)v128;
      v95->pNextItem = 0i64;
      _mm_store_si128((__m128i *)&v127, v97);
      if ( v14 )
        v14->pNextItem = v95;
      else
        v13 = v95;
      v14 = v95;
      if ( !v96 )
        break;
      m = (CAkMusicSwitchTransition *)*((_QWORD *)&v127 + 1);
      v95 = (CAkMusicSwitchTransition *)v127;
    }
  }
  ((void (__fastcall *)(CAkMusicSwitchCtx *, CAkScheduleWindow *))v6->vfptr[1].~CAkChildCtx)(v6, &in_source);
  UFG::OnUnloadClass<UITest::HandleArrayTest>(*v9);
  *v9 = 0i64;
  if ( ((unsigned __int8 (*)(void))v6->m_queueTransitions.m_pLast->m_pDestCtx.m_pT->vfptr[2].OnResumed)() )
  {
    v98 = v6->m_queueTransitions.m_pLast;
    v99 = *((_BYTE *)v98 + 72);
    if ( !(v99 & 4) || v99 & 2 )
    {
      *((_BYTE *)v98 + 72) = v99 & 0xFD;
    }
    else
    {
      v100 = AkTimeConv::SamplesToMilliseconds((signed int)in_iCurrentTime - LODWORD(v98->m_cmdStop.iRelativeTime));
      v101 = (CAkMusicCtx *)&v98->m_pDestCtx.m_pT->vfptr;
      LODWORD(v124) = v100;
      *(_QWORD *)((char *)&v124 + 4) = (unsigned int)v98->m_cmdStop.transParams.eFadeCurve;
      CAkMusicCtx::_Play(v101, (AkMusicFade *)&v124, v102);
    }
    *((_BYTE *)v98 + 72) &= 0xFBu;
    v98->m_cutoffInfo.bCutoff = 0;
  }
LABEL_206:
  v103 = v13;
  v104 = 0i64;
  if ( v13 )
  {
    while ( 1 )
    {
      v105 = v103->pNextItem;
      *((_QWORD *)&v128 + 1) = v104;
      *(_QWORD *)&v128 = v105;
      if ( v103 == v13 )
        v13 = v105;
      else
        v104->pNextItem = v105;
      v106 = (__m128i)v128;
      v107 = (CAkMusicCtx *)&v103->m_pDestCtx.m_pT->vfptr;
      if ( v103 == v14 )
        v14 = v104;
      *((_BYTE *)v103 + 72) &= 0xFCu;
      _mm_store_si128((__m128i *)&v127, v106);
      UFG::OnUnloadClass<UITest::HandleArrayTest>(v107);
      v108 = (CAkMusicCtx *)&v103->m_pDestCtx.m_pT->vfptr;
      v109 = g_DefaultPoolId;
      v103->m_pDestCtx.m_pT = 0i64;
      if ( v108 )
        CAkMusicCtx::Release(v108);
      v110 = (CAkMusicCtx *)&v103->m_pDestCtx.m_pT->vfptr;
      if ( v110 )
      {
        CAkMusicCtx::Release(v110);
        v103->m_pDestCtx.m_pT = 0i64;
      }
      AK::MemoryMgr::Free(v109, v103);
      if ( !v105 )
        break;
      v104 = (CAkMusicSwitchTransition *)*((_QWORD *)&v127 + 1);
      v103 = (CAkMusicSwitchTransition *)v127;
    }
  }
LABEL_218:
  _((AMD_HD3D *)&in_source);
}

// File Line: 1663
// RVA: 0xAB9DA0
void __fastcall CAkMusicSwitchCtx::ScheduleTransition(CAkMusicSwitchCtx *this, __int64 in_iCurrentTime, CAkMusicSwitchTransition *in_pNewTransition, AkMusicTransSrcRule *in_ruleFrom, AkMusicTransDestRule *in_ruleTo, CAkScheduleWindow *in_source, int in_iDestinationLookAhead, __int64 in_iSyncPoint, bool in_bIsFromTransitionCtx, AkListBareLight<AkAssociatedAction,AkListBareLightNextItem<AkAssociatedAction> > *io_listCancelledActions)
{
  CAkScheduleWindow *v10; // rdi
  int v11; // er15
  CAkMusicSwitchCtx *v12; // r14
  AkMusicTransSrcRule *v13; // r13
  CAkMusicSwitchTransition *v14; // rsi
  CAkMusicSegment *v15; // rax
  CAkMusicSwitchTransition *v16; // rbx
  char v17; // r8
  unsigned int v18; // ecx
  unsigned int v19; // er15
  int v20; // eax
  CAkMusicCtx *v21; // rcx
  __int64 v22; // r8
  int v23; // er8
  signed int v24; // er15
  __int64 v25; // r12
  signed int v26; // eax
  bool v27; // cl
  AkCurveInterpolation v28; // eax
  CAkMatrixAwareCtx *v29; // rcx
  __int64 v30; // r8
  CAkMusicSwitchTransition *v31; // rax
  AkMusicFade in_fadeParams; // [rsp+20h] [rbp-38h]
  CAkMusicSegment *v33; // [rsp+60h] [rbp+8h]
  int in_sourcea; // [rsp+88h] [rbp+30h]

  v10 = in_source;
  v11 = in_iCurrentTime;
  v12 = this;
  v13 = in_ruleFrom;
  v14 = in_pNewTransition;
  v15 = CAkScheduleWindow::GetNode(in_source, 0i64);
  v16 = v12->m_queueTransitions.m_pLast;
  v17 = *((_BYTE *)v16 + 72);
  v33 = v15;
  v18 = in_iSyncPoint - v11;
  if ( !(v17 & 4) || v17 & 2 )
  {
    *((_BYTE *)v16 + 72) = v17 & 0xFD;
  }
  else
  {
    v19 = v11 - LODWORD(v16->m_cmdStop.iRelativeTime);
    if ( v19 < v18 )
      v18 = v19;
    v20 = AkTimeConv::SamplesToMilliseconds(v18);
    v21 = (CAkMusicCtx *)&v16->m_pDestCtx.m_pT->vfptr;
    in_fadeParams.transitionTime = v20;
    *(_QWORD *)&in_fadeParams.eFadeCurve = (unsigned int)v16->m_cmdStop.transParams.eFadeCurve;
    CAkMusicCtx::_Play(v21, &in_fadeParams, v22);
    v15 = v33;
  }
  *((_BYTE *)v16 + 72) &= 0xFBu;
  v16->m_cutoffInfo.bCutoff = 0;
  v23 = v13->fadeParams.transitionTime;
  v24 = 0;
  v25 = in_iSyncPoint;
  in_sourcea = v13->fadeParams.transitionTime;
  if ( v13->fadeParams.transitionTime > 0 && v15 )
  {
    v26 = v23 * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8) - v13->fadeParams.iFadeOffset;
    v24 = v23 * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8) - v26;
    v25 = in_iSyncPoint - v26;
  }
  else if ( *((_BYTE *)v13 + 16) & 0x20 )
  {
    if ( CAkScheduleWindow::IsAtExitCue(v10, in_iSyncPoint) )
      v25 = in_iSyncPoint + (unsigned int)CAkMusicSegment::PostExitDuration(v33);
    v23 = in_sourcea;
  }
  v27 = !in_bIsFromTransitionCtx && v24 <= 0;
  v28 = v13->fadeParams.eFadeCurve;
  *((_BYTE *)v16 + 72) |= 6u;
  v16->m_cmdStop.transParams.TransitionTime = v23;
  v16->m_cmdStop.transParams.eFadeCurve = v28;
  v16->m_cmdStop.iRelativeTime = v25;
  if ( v27 )
  {
    if ( v16->m_cutoffInfo.bCutoff )
    {
      if ( in_iSyncPoint >= v16->m_cutoffInfo.iCutoffTime )
        goto LABEL_23;
    }
    else
    {
      v16->m_cutoffInfo.bCutoff = 1;
    }
    v16->m_cutoffInfo.iCutoffTime = in_iSyncPoint;
  }
LABEL_23:
  CAkScheduledItem::ForcePostExit(v10->m_itScheduledItem.pItem, (*((_DWORD *)v13 + 4) >> 5) & 1);
  v14->m_pDestCtx.m_pT->m_iLocalTime = in_iSyncPoint;
  v14->m_cmdPlay.iRelativeTime = in_iSyncPoint - in_iDestinationLookAhead;
  v29 = v14->m_pDestCtx.m_pT;
  v14->m_cmdPlay.fadeParams.transitionTime = in_ruleTo->fadeParams.transitionTime;
  v14->m_cmdPlay.fadeParams.eFadeCurve = in_ruleTo->fadeParams.eFadeCurve;
  v14->m_cmdPlay.fadeParams.iFadeOffset = in_ruleTo->fadeParams.iFadeOffset;
  if ( !((__int64 (*)(void))v29->vfptr[2].OnPaused)() )
    v14->m_cmdPlay.fadeParams.transitionTime = 0;
  if ( in_ruleTo->fadeParams.transitionTime > 0 )
    v14->m_cmdPlay.fadeParams.iFadeOffset += in_iDestinationLookAhead;
  *((_BYTE *)v14 + 72) |= 1u;
  CAkScheduleWindow::CancelActionsAfterTransitionSyncPoint(v10, io_listCancelledActions, in_iSyncPoint);
  while ( !v10->m_bIsDurationInfinite )
  {
    LOBYTE(v30) = 1;
    ((void (__fastcall *)(CAkMusicSwitchCtx *, CAkScheduleWindow *, __int64))v12->vfptr[1].VirtualRelease)(
      v12,
      v10,
      v30);
    CAkScheduleWindow::CancelActionsAfterTransitionSyncPoint(v10, io_listCancelledActions, in_iSyncPoint);
  }
  v14->pNextItem = 0i64;
  v31 = v12->m_queueTransitions.m_pLast;
  if ( v31 )
    v31->pNextItem = v14;
  else
    v12->m_queueTransitions.m_pFirst = v14;
  v12->m_queueTransitions.m_pLast = v14;
}

// File Line: 1747
// RVA: 0xAB8110
AkMusicTransitionRule *__fastcall CAkMusicSwitchCtx::GetTransitionRule(CAkMusicSwitchCtx *this, CAkScheduleWindow *in_source, CAkMatrixAwareCtx **io_pDestContext, unsigned int *io_uSrcSegmentLookAhead)
{
  CAkMatrixAwareCtx **v4; // rdi
  CAkMusicSwitchCtx *v5; // rsi
  CAkMusicSegment *v7; // rax
  unsigned int v8; // ebx
  CAkMusicSegment *v9; // rax
  unsigned int in_destID; // edx
  AkMusicTransitionRule *v11; // rax
  AkMusicTransitionRule *v12; // rsi
  CAkChainCtx *v13; // rbx
  CAkSequenceCtx *v14; // rcx
  CAkMusicNode *out_ppParentNode; // [rsp+40h] [rbp-148h]
  CAkMusicNode *in_pDestParentNode; // [rsp+48h] [rbp-140h]
  CAkScheduleWindow v17; // [rsp+50h] [rbp-138h]
  bool out_bIsDestSequenceSpecific; // [rsp+1A8h] [rbp+20h]

  ++*io_uSrcSegmentLookAhead;
  v4 = io_pDestContext;
  v5 = this;
  if ( *io_uSrcSegmentLookAhead > 0x40 )
    return CAkMusicTransAware::GetPanicTransitionRule();
  v7 = CAkScheduleWindow::GetNode(in_source, &out_ppParentNode);
  if ( v7 )
    v8 = v7->key;
  else
    v8 = 0;
  CAkScheduleWindow::CAkScheduleWindow(&v17, *v4, 1);
  v9 = CAkScheduleWindow::GetNode(&v17, &in_pDestParentNode);
  if ( v9 )
    in_destID = v9->key;
  else
    in_destID = 0;
  v11 = CAkMusicTransAware::GetTransitionRule(
          (CAkMusicTransAware *)&v5->m_pSwitchCntrNode->vfptr,
          (CAkParameterNodeBase *)&v5->m_pSwitchCntrNode->vfptr,
          v8,
          (CAkParameterNodeBase *)&out_ppParentNode->vfptr,
          in_destID,
          (CAkParameterNodeBase *)&in_pDestParentNode->vfptr,
          &out_bIsDestSequenceSpecific);
  v12 = v11;
  if ( out_bIsDestSequenceSpecific )
  {
    v13 = v17.m_itScheduledItem.pCtx;
    v14 = (CAkSequenceCtx *)v17.m_itScheduledItem.pCtx;
    ++v14->m_uRefCount;
    if ( !CAkSequenceCtx::JumpToSegment(v14, v11->destRule.uJumpToID) )
    {
      UFG::OnUnloadClass<UITest::HandleArrayTest>((CAkMusicCtx *)&(*v4)->vfptr);
      *v4 = 0i64;
    }
    CAkMusicCtx::Release((CAkMusicCtx *)&v13->vfptr);
  }
  _((AMD_HD3D *)&v17);
  return v12;
}

// File Line: 1839
// RVA: 0xAB8930
signed __int64 __fastcall CAkMusicSwitchCtx::PrepareFirstContext(CAkMusicSwitchCtx *this, CAkMatrixAwareCtx *in_pCtx)
{
  CAkMusicSwitchCtx *v2; // rbx
  CAkMatrixAwareCtx *v3; // rdi
  CAkMusicSwitchTransition *v4; // rax
  CAkMusicSwitchTransition *v5; // rcx
  char v7; // [rsp+50h] [rbp+18h]

  v2 = this;
  v3 = in_pCtx;
  v4 = (CAkMusicSwitchTransition *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x50ui64);
  if ( !v4 )
    return 2i64;
  v4->pNextItem = 0i64;
  v4->m_pDestCtx.m_pT = v3;
  if ( v3 )
    ++v3->m_uRefCount;
  v4->m_cutoffInfo.iCutoffTime = 0i64;
  v4->m_cutoffInfo.bCutoff = 0;
  *((_BYTE *)v4 + 72) &= 0xF8u;
  v4->pNextItem = 0i64;
  v5 = v2->m_queueTransitions.m_pLast;
  if ( v5 )
    v5->pNextItem = v4;
  else
    v2->m_queueTransitions.m_pFirst = v4;
  v2->m_queueTransitions.m_pLast = v4;
  v2->m_itActiveSwitch.pItem = v2->m_queueTransitions.m_pFirst;
  ((void (__fastcall *)(CAkMusicSwitchCtx *, _QWORD, _QWORD, _QWORD, char *, _DWORD))v2->vfptr[1].VirtualAddRef)(
    v2,
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
  CAkMusicSwitchTransition *v3; // rbx
  char v4; // cl

  result = this->m_itActiveSwitch.pItem;
  v2 = result;
  v3 = result->pNextItem;
  if ( result->pNextItem )
  {
    do
    {
      if ( !((unsigned __int8 (*)(void))result->m_pDestCtx.m_pT->vfptr[2].OnResumed)()
        || (v4 = *((_BYTE *)&v3->m_pDestCtx.m_pT->0 + 98), v4 & 3) && !(v4 & 0x10) )
      {
        v2 = v3;
      }
      result = v3;
      v3 = v3->pNextItem;
    }
    while ( v3 );
    result = v2;
  }
  return result;
}

// File Line: 1941
// RVA: 0xABA0A0
signed __int64 __fastcall CAkMusicSwitchCtx::SeekTimeAbsolute(CAkMusicSwitchCtx *this, int *io_position, bool in_bSnapToCue)
{
  CAkMusicSwitchCtx *v3; // rbx
  signed int v4; // edx
  unsigned __int8 v5; // al
  unsigned int v7; // edi
  __int64 v8; // rdx
  CAkMusicSwitchCtx::TransitionInfo in_transitionInfo; // [rsp+20h] [rbp-18h]
  int v10; // [rsp+40h] [rbp+8h]
  char v11; // [rsp+44h] [rbp+Ch]
  CAkMatrixAwareCtx *io_pNewContext; // [rsp+48h] [rbp+10h]

  v3 = this;
  v11 = 0;
  v4 = *io_position * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
  if ( v4 < 0 )
    v4 = 0;
  v5 = *((_BYTE *)&this->0 + 98) & 0xF;
  v10 = v4;
  if ( v5 > 1u || this->m_pParentCtx )
    return 2i64;
  *((_BYTE *)this + 184) &= 0xFEu;
  in_transitionInfo.pSeekingInfo = (AkSeekingInfo *)&v10;
  in_transitionInfo.bOverrideEntryType = 0;
  v7 = CAkMusicSwitchCtx::ResolveAudioNode(this);
  io_pNewContext = (CAkMatrixAwareCtx *)CAkMusicSwitchCtx::CreateDestinationContext(v3, v7);
  if ( io_pNewContext )
  {
    CAkMusicSwitchCtx::ScheduleSwitchTransition(v3, v7, &in_transitionInfo, &io_pNewContext);
    if ( io_pNewContext )
      ((void (__cdecl *)(CAkMatrixAwareCtx *, __int64))io_pNewContext->vfptr[1].OnResumed)(io_pNewContext, v8);
  }
  return 1i64;
}

// File Line: 1959
// RVA: 0xABA000
signed __int64 __fastcall CAkMusicSwitchCtx::SeekPercent(CAkMusicSwitchCtx *this, float *io_fPercent, bool in_bSnapToCue)
{
  CAkMusicSwitchCtx *v3; // rbx
  unsigned __int8 v4; // al
  unsigned int v6; // edi
  __int64 v7; // rdx
  CAkMusicSwitchCtx::TransitionInfo in_transitionInfo; // [rsp+20h] [rbp-18h]
  int v9; // [rsp+40h] [rbp+8h]
  char v10; // [rsp+44h] [rbp+Ch]
  CAkMatrixAwareCtx *io_pNewContext; // [rsp+48h] [rbp+10h]

  v3 = this;
  v4 = *((_BYTE *)&this->0 + 98) & 0xF;
  v9 = *(_DWORD *)io_fPercent;
  v10 = 1;
  if ( v4 > 1u || this->m_pParentCtx )
    return 2i64;
  *((_BYTE *)this + 184) &= 0xFEu;
  in_transitionInfo.pSeekingInfo = (AkSeekingInfo *)&v9;
  in_transitionInfo.bOverrideEntryType = 0;
  v6 = CAkMusicSwitchCtx::ResolveAudioNode(this);
  io_pNewContext = (CAkMatrixAwareCtx *)CAkMusicSwitchCtx::CreateDestinationContext(v3, v6);
  if ( io_pNewContext )
  {
    CAkMusicSwitchCtx::ScheduleSwitchTransition(v3, v6, &in_transitionInfo, &io_pNewContext);
    if ( io_pNewContext )
      ((void (__cdecl *)(CAkMatrixAwareCtx *, __int64))io_pNewContext->vfptr[1].OnResumed)(io_pNewContext, v7);
  }
  return 1i64;
}

