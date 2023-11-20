// File Line: 36
// RVA: 0xAA6540
__int64 __fastcall AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::CanBeDestroyed(AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase> *this)
{
  _RTL_CRITICAL_SECTION *v1; // rbx
  AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase> *v2; // rdi

  v1 = &this->m_lockStatus.m_csLock;
  v2 = this;
  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  LOBYTE(v2) = v2->m_listCancelledXfers.m_pFirst == 0i64;
  LeaveCriticalSection(v1);
  return (unsigned __int8)v2;
}

// File Line: 54
// RVA: 0xAA7CA0
void __fastcall AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::Update(AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase> *this, AK::StreamMgr::CAkStmMemView *in_pTransfer, AKRESULT in_eIOResult, bool in_bRequiredLowLevelXfer)
{
  AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase> *v4; // rsi
  bool v5; // r15
  AKRESULT v6; // er12
  AK::StreamMgr::CAkStmMemView *v7; // rdi
  int v8; // er10
  bool v9; // bp
  unsigned int v10; // er10
  bool v11; // r14

  v4 = this;
  v5 = in_bRequiredLowLevelXfer;
  v6 = in_eIOResult;
  v7 = in_pTransfer;
  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  if ( v6 != 1 || (v8 = *((_DWORD *)v7 + 5), (*((_DWORD *)v7 + 5) & 7) == 2) )
  {
    v9 = 0;
  }
  else
  {
    v9 = 1;
    if ( v4->m_listPendingXfers.m_pFirst != v7 )
    {
      if ( v5 )
        v10 = v8 & 0xFFFFFFF9 | 1;
      else
        v10 = v8 & 0xFFFFFFFB | 3;
      *((_DWORD *)v7 + 5) = v10;
      goto LABEL_16;
    }
  }
  if ( v7 )
  {
    v11 = (*((_DWORD *)v7 + 5) & 7) == 2;
    AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::PopTransferRequest(v4, v7, v9);
    if ( !v5 && !v11 )
    {
      *((_DWORD *)v7 + 5) &= 0xFFFFFFFB;
      *((_DWORD *)v7 + 5) |= 3u;
    }
    AK::StreamMgr::CAkAutoStmBase::AddMemView((AK::StreamMgr::CAkAutoStmBase *)&v4->vfptr, v7, v9);
    if ( !v11 )
      AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::UpdateCompletedTransfers(v4);
  }
  AK::StreamMgr::CAkAutoStmBase::UpdateTaskStatus((AK::StreamMgr::CAkAutoStmBase *)&v4->vfptr, v6);
  AK::StreamMgr::CAkIOThread::DecrementIOCount((AK::StreamMgr::CAkIOThread *)&v4->m_pDevice->vfptr);
LABEL_16:
  LeaveCriticalSection(&v4->m_lockStatus.m_csLock);
}

// File Line: 126
// RVA: 0xAA7F80
void __fastcall AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkStdStmBase>::UpdateCompletedTransfers(AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkStdStmBase> *this)
{
  AK::StreamMgr::CAkStmMemView *v1; // rdx
  AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkStdStmBase> *v2; // rbx
  AK::StreamMgr::CAkStmMemView *v3; // rax
  AK::StreamMgr::CAkStmMemView *v4; // rcx
  AK::StreamMgr::CAkStmMemView *v5; // r8
  AK::StreamMgr::CAkStmMemView *v6; // rax
  bool v7; // zf
  AK::StreamMgr::CAkStmMemView *v8; // rcx

  v1 = this->m_listPendingXfers.m_pFirst;
  v2 = this;
  if ( v1 && *((_BYTE *)v1 + 20) & 7 )
  {
    do
    {
      if ( (*((_DWORD *)v1 + 5) & 7) == 2 )
      {
        v4 = v2->m_listCancelledXfers.m_pFirst;
        v5 = 0i64;
        v6 = v4;
        if ( v4 )
        {
          while ( v6 != v1 )
          {
            v5 = v6;
            v6 = v6->pNextView;
            if ( !v6 )
              goto LABEL_15;
          }
          v7 = v6 == v4;
          v8 = v6->pNextView;
          if ( v7 )
            v2->m_listCancelledXfers.m_pFirst = v8;
          else
            v5->pNextView = v8;
        }
      }
      else
      {
        v3 = v2->m_listPendingXfers.m_pFirst;
        if ( v3 )
        {
          if ( v3->pNextView )
          {
            v2->m_listPendingXfers.m_pFirst = v3->pNextView;
          }
          else
          {
            v2->m_listPendingXfers.m_pFirst = 0i64;
            v2->m_listPendingXfers.m_pLast = 0i64;
          }
        }
      }
LABEL_15:
      AK::StreamMgr::CAkStdStmBase::AddMemView((AK::StreamMgr::CAkStdStmBase *)&v2->vfptr, v1, 1);
      AK::StreamMgr::CAkIOThread::DecrementIOCount((AK::StreamMgr::CAkIOThread *)&v2->m_pDevice->vfptr);
      v1 = AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkStdStmBase>::GetOldestCompletedTransfer(v2);
    }
    while ( v1 );
  }
}

// File Line: 159
// RVA: 0xAA7860
void __fastcall AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::PopTransferRequest(AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase> *this, AK::StreamMgr::CAkStmMemView *in_pTransfer, bool in_bStoreData)
{
  AK::StreamMgr::CAkStmMemView *v3; // r10
  AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase> *v4; // r9
  AK::StreamMgr::CAkStmMemView *v5; // rax
  AK::StreamMgr::CAkStmMemView *v6; // rdx
  AK::StreamMgr::CAkStmMemView *v7; // rcx
  bool v8; // zf
  AK::StreamMgr::CAkStmMemView *v9; // rax
  AK::StreamMgr::CAkStmMemView *v10; // rax
  AK::StreamMgr::CAkStmMemView *v11; // rax
  AK::StreamMgr::CAkStmMemView *v12; // rcx
  AK::StreamMgr::CAkStmMemView *v13; // rdx
  AK::StreamMgr::CAkStmMemView *v14; // rax
  AK::StreamMgr::CAkStmMemView *v15; // rax

  v3 = in_pTransfer;
  v4 = this;
  if ( (*((_DWORD *)in_pTransfer + 5) & 7) == 2 )
  {
    v12 = this->m_listCancelledXfers.m_pFirst;
    v13 = 0i64;
    v14 = v12;
    if ( v12 )
    {
      while ( v14 != v3 )
      {
        v13 = v14;
        v14 = v14->pNextView;
        if ( !v14 )
          return;
      }
      v8 = v14 == v12;
      v15 = v14->pNextView;
      if ( v8 )
        v4->m_listCancelledXfers.m_pFirst = v15;
      else
        v13->pNextView = v15;
    }
  }
  else if ( in_bStoreData || (v5 = this->m_listPendingXfers.m_pFirst, v5 == in_pTransfer) )
  {
    v10 = this->m_listPendingXfers.m_pFirst;
    if ( v10 )
    {
      v11 = v10->pNextView;
      if ( v11 )
      {
        this->m_listPendingXfers.m_pFirst = v11;
      }
      else
      {
        this->m_listPendingXfers.m_pFirst = 0i64;
        this->m_listPendingXfers.m_pLast = 0i64;
      }
    }
  }
  else
  {
    v6 = 0i64;
    v7 = this->m_listPendingXfers.m_pFirst;
    if ( v5 )
    {
      while ( v7 != v3 )
      {
        v6 = v7;
        v7 = v7->pNextView;
        if ( !v7 )
          return;
      }
      v8 = v7 == v5;
      v9 = v7->pNextView;
      if ( v8 )
        v4->m_listPendingXfers.m_pFirst = v9;
      else
        v6->pNextView = v9;
      if ( v7 == v4->m_listPendingXfers.m_pLast )
        v4->m_listPendingXfers.m_pLast = v6;
    }
  }
}

// File Line: 220
// RVA: 0xAA67C0
void __fastcall AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::CancelTransfers(AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase> *this, AkListBare<AK::StreamMgr::CAkStmMemView,AK::StreamMgr::AkListBareNextMemView,AkCountPolicyNoCount> *in_listToCancel, bool in_bNotifyAllCancelled)
{
  AkListBare<AK::StreamMgr::CAkStmMemView,AK::StreamMgr::AkListBareNextMemView,AkCountPolicyNoCount> *v3; // rsi
  AK::StreamMgr::CAkStmMemView *v4; // rdx
  bool v5; // bp
  AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase> *v6; // rdi
  AK::StreamMgr::CAkStmMemView *v7; // rax
  AK::StreamMgr::CAkStmMemView *v8; // rbx
  int v9; // eax
  AK::StreamMgr::AkMemBlock *v10; // r8
  __int64 v11; // r9
  unsigned __int64 v12; // r10
  unsigned __int64 v13; // rcx
  unsigned int v14; // ecx
  AK::StreamMgr::CAkStmMemView *v15; // rax
  AK::StreamMgr::CAkStmMemViewDeferred *v16; // rbx
  char i; // r8
  AK::StreamMgr::CAkStmMemViewDeferred *v18; // rcx
  __m128i v19; // [rsp+20h] [rbp-28h]
  __m128i v20; // [rsp+30h] [rbp-18h]

  v3 = in_listToCancel;
  v4 = in_listToCancel->m_pFirst;
  v5 = in_bNotifyAllCancelled;
  v6 = this;
  v7 = 0i64;
  if ( v4 )
  {
    while ( 1 )
    {
      v8 = v4->pNextView;
      v19.m128i_i64[1] = (__int64)v7;
      v19.m128i_i64[0] = (__int64)v4->pNextView;
      if ( v4 == v3->m_pFirst )
        v3->m_pFirst = v8;
      else
        v7->pNextView = v8;
      if ( v4 == v3->m_pLast )
        v3->m_pLast = v7;
      v9 = *((_DWORD *)v4 + 5);
      _mm_store_si128(&v20, v19);
      if ( v9 & 7 )
      {
        AK::StreamMgr::CAkAutoStmBase::AddMemView((AK::StreamMgr::CAkAutoStmBase *)&v6->vfptr, v4, 0);
      }
      else
      {
        v10 = v4->m_pBlock;
        v11 = v4->m_uOffsetInBlock;
        *((_DWORD *)v4 + 5) = v9 & 0xFFFFFFFA | 2;
        v12 = v10->uPosition;
        v13 = v6->m_uLoopEnd;
        if ( v10->uPosition + v11 >= v13 || v12 + v10->uAvailableSize <= v13 )
          v14 = v10->uAvailableSize;
        else
          v14 = v13 - v12;
        v6->m_uVirtualBufferingSize -= v14 - v11;
        v4->m_uOffsetInBlock = v4->m_pBlock->uAvailableSize;
        v15 = v6->m_listCancelledXfers.m_pFirst;
        if ( v15 )
        {
          v4->pNextView = v15;
          v6->m_listCancelledXfers.m_pFirst = v4;
        }
        else
        {
          v6->m_listCancelledXfers.m_pFirst = v4;
          v4->pNextView = 0i64;
        }
      }
      if ( !v8 )
        break;
      v7 = (AK::StreamMgr::CAkStmMemView *)v20.m128i_i64[1];
      v4 = (AK::StreamMgr::CAkStmMemView *)v20.m128i_i64[0];
    }
  }
  v16 = (AK::StreamMgr::CAkStmMemViewDeferred *)v6->m_listCancelledXfers.m_pFirst;
  for ( i = 1; v16; i = v5 == 0 )
  {
    v18 = v16;
    v16 = (AK::StreamMgr::CAkStmMemViewDeferred *)v16->pNextView;
    AK::StreamMgr::CAkStmMemViewDeferred::Cancel(
      v18,
      (AK::StreamMgr::IAkIOHookDeferred *)v6->m_pDevice->m_pLowLevelHook,
      i,
      v5);
  }
}

// File Line: 298
// RVA: 0xAA7610
AK::StreamMgr::CAkStmMemView *__fastcall AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::GetOldestCompletedTransfer(AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase> *this)
{
  AK::StreamMgr::CAkStmMemView *result; // rax

  result = this->m_listPendingXfers.m_pFirst;
  if ( !result || !(*((_BYTE *)result + 20) & 7) )
    result = 0i64;
  return result;
}

