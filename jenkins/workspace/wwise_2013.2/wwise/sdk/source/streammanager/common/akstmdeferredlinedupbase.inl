// File Line: 36
// RVA: 0xAA6540
__int64 __fastcall AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::CanBeDestroyed(
        AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase> *this)
{
  CAkLock *p_m_lockStatus; // rbx
  AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase> *v2; // rdi

  p_m_lockStatus = &this->m_lockStatus;
  v2 = this;
  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  LOBYTE(v2) = v2->m_listCancelledXfers.m_pFirst == 0i64;
  LeaveCriticalSection(&p_m_lockStatus->m_csLock);
  return (unsigned __int8)v2;
}

// File Line: 54
// RVA: 0xAA7CA0
void __fastcall AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::Update(
        AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase> *this,
        AK::StreamMgr::CAkStmMemView *in_pTransfer,
        AKRESULT in_eIOResult,
        bool in_bRequiredLowLevelXfer)
{
  int v8; // r10d
  bool v9; // bp
  bool v10; // r14

  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  if ( in_eIOResult != AK_Success || (v8 = *((_DWORD *)in_pTransfer + 5), (v8 & 7) == 2) )
  {
    v9 = 0;
  }
  else
  {
    v9 = 1;
    if ( this->m_listPendingXfers.m_pFirst != in_pTransfer )
    {
      if ( in_bRequiredLowLevelXfer )
        *((_DWORD *)in_pTransfer + 5) = v8 & 0xFFFFFFF8 | 1;
      else
        *((_DWORD *)in_pTransfer + 5) = v8 & 0xFFFFFFF8 | 3;
      goto LABEL_15;
    }
  }
  if ( in_pTransfer )
  {
    v10 = (*((_DWORD *)in_pTransfer + 5) & 7) == 2;
    AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::PopTransferRequest(this, in_pTransfer, v9);
    if ( !in_bRequiredLowLevelXfer && !v10 )
    {
      *((_DWORD *)in_pTransfer + 5) &= ~4u;
      *((_DWORD *)in_pTransfer + 5) |= 3u;
    }
    AK::StreamMgr::CAkAutoStmBase::AddMemView(this, in_pTransfer, v9);
    if ( !v10 )
      AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::UpdateCompletedTransfers(this);
  }
  AK::StreamMgr::CAkAutoStmBase::UpdateTaskStatus(this, in_eIOResult);
  AK::StreamMgr::CAkIOThread::DecrementIOCount(this->m_pDevice);
LABEL_15:
  LeaveCriticalSection(&this->m_lockStatus.m_csLock);
}

// File Line: 126
// RVA: 0xAA7F80
void __fastcall AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkStdStmBase>::UpdateCompletedTransfers(
        AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkStdStmBase> *this)
{
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rdx
  AK::StreamMgr::CAkStmMemView *v3; // rax
  AK::StreamMgr::CAkStmMemView *v4; // rcx
  AK::StreamMgr::CAkStmMemView **p_pNextView; // r8
  AK::StreamMgr::CAkStmMemView *v6; // rax
  bool v7; // zf
  AK::StreamMgr::CAkStmMemView *pNextView; // rcx

  m_pFirst = this->m_listPendingXfers.m_pFirst;
  if ( m_pFirst && (*((_BYTE *)m_pFirst + 20) & 7) != 0 )
  {
    do
    {
      if ( (*((_DWORD *)m_pFirst + 5) & 7) == 2 )
      {
        v4 = this->m_listCancelledXfers.m_pFirst;
        p_pNextView = 0i64;
        v6 = v4;
        if ( v4 )
        {
          while ( v6 != m_pFirst )
          {
            p_pNextView = &v6->pNextView;
            v6 = v6->pNextView;
            if ( !v6 )
              goto LABEL_15;
          }
          v7 = v6 == v4;
          pNextView = v6->pNextView;
          if ( v7 )
            this->m_listCancelledXfers.m_pFirst = pNextView;
          else
            *p_pNextView = pNextView;
        }
      }
      else
      {
        v3 = this->m_listPendingXfers.m_pFirst;
        if ( v3 )
        {
          if ( v3->pNextView )
          {
            this->m_listPendingXfers.m_pFirst = v3->pNextView;
          }
          else
          {
            this->m_listPendingXfers.m_pFirst = 0i64;
            this->m_listPendingXfers.m_pLast = 0i64;
          }
        }
      }
LABEL_15:
      AK::StreamMgr::CAkStdStmBase::AddMemView(this, m_pFirst, 1);
      AK::StreamMgr::CAkIOThread::DecrementIOCount(this->m_pDevice);
      m_pFirst = AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkStdStmBase>::GetOldestCompletedTransfer(this);
    }
    while ( m_pFirst );
  }
}

// File Line: 159
// RVA: 0xAA7860
void __fastcall AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::PopTransferRequest(
        AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase> *this,
        AK::StreamMgr::CAkStmMemView *in_pTransfer,
        bool in_bStoreData)
{
  AK::StreamMgr::CAkStmMemView *v5; // rax
  AK::StreamMgr::CAkStmMemView *v6; // rdx
  AK::StreamMgr::CAkStmMemView *v7; // rcx
  bool v8; // zf
  AK::StreamMgr::CAkStmMemView *v9; // rax
  AK::StreamMgr::CAkStmMemView *v10; // rax
  AK::StreamMgr::CAkStmMemView *v11; // rax
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rcx
  AK::StreamMgr::CAkStmMemView *v13; // rdx
  AK::StreamMgr::CAkStmMemView *v14; // rax
  AK::StreamMgr::CAkStmMemView *pNextView; // rax

  if ( (*((_DWORD *)in_pTransfer + 5) & 7) == 2 )
  {
    m_pFirst = this->m_listCancelledXfers.m_pFirst;
    v13 = 0i64;
    v14 = m_pFirst;
    if ( m_pFirst )
    {
      while ( v14 != in_pTransfer )
      {
        v13 = v14;
        v14 = v14->pNextView;
        if ( !v14 )
          return;
      }
      v8 = v14 == m_pFirst;
      pNextView = v14->pNextView;
      if ( v8 )
        this->m_listCancelledXfers.m_pFirst = pNextView;
      else
        v13->pNextView = pNextView;
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
      while ( v7 != in_pTransfer )
      {
        v6 = v7;
        v7 = v7->pNextView;
        if ( !v7 )
          return;
      }
      v8 = v7 == v5;
      v9 = v7->pNextView;
      if ( v8 )
        this->m_listPendingXfers.m_pFirst = v9;
      else
        v6->pNextView = v9;
      if ( v7 == this->m_listPendingXfers.m_pLast )
        this->m_listPendingXfers.m_pLast = v6;
    }
  }
}

// File Line: 220
// RVA: 0xAA67C0
void __fastcall AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::CancelTransfers(
        AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase> *this,
        AkListBare<AK::StreamMgr::CAkStmMemView,AK::StreamMgr::AkListBareNextMemView,AkCountPolicyNoCount> *in_listToCancel,
        bool in_bNotifyAllCancelled)
{
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rdx
  AK::StreamMgr::CAkStmMemView *v7; // rax
  AK::StreamMgr::CAkStmMemView *pNextView; // rbx
  int v9; // eax
  AK::StreamMgr::AkMemBlock *m_pBlock; // r8
  __int64 m_uOffsetInBlock; // r9
  unsigned __int64 uPosition; // r10
  unsigned __int64 m_uLoopEnd; // rcx
  unsigned int uAvailableSize; // ecx
  AK::StreamMgr::CAkStmMemView *v15; // rax
  AK::StreamMgr::CAkStmMemView *v16; // rbx
  bool i; // r8
  AK::StreamMgr::CAkStmMemViewDeferred *v18; // rcx
  AK::StreamMgr::CAkStmMemView *v19; // [rsp+20h] [rbp-28h]
  AK::StreamMgr::CAkStmMemView *v20; // [rsp+28h] [rbp-20h]

  m_pFirst = in_listToCancel->m_pFirst;
  v7 = 0i64;
  if ( m_pFirst )
  {
    while ( 1 )
    {
      pNextView = m_pFirst->pNextView;
      v20 = v7;
      v19 = m_pFirst->pNextView;
      if ( m_pFirst == in_listToCancel->m_pFirst )
        in_listToCancel->m_pFirst = pNextView;
      else
        v7->pNextView = pNextView;
      if ( m_pFirst == in_listToCancel->m_pLast )
        in_listToCancel->m_pLast = v7;
      v9 = *((_DWORD *)m_pFirst + 5);
      if ( (v9 & 7) != 0 )
      {
        AK::StreamMgr::CAkAutoStmBase::AddMemView(this, m_pFirst, 0);
      }
      else
      {
        m_pBlock = m_pFirst->m_pBlock;
        m_uOffsetInBlock = m_pFirst->m_uOffsetInBlock;
        *((_DWORD *)m_pFirst + 5) = v9 & 0xFFFFFFF8 | 2;
        uPosition = m_pBlock->uPosition;
        m_uLoopEnd = this->m_uLoopEnd;
        if ( m_pBlock->uPosition + m_uOffsetInBlock >= m_uLoopEnd || uPosition + m_pBlock->uAvailableSize <= m_uLoopEnd )
          uAvailableSize = m_pBlock->uAvailableSize;
        else
          uAvailableSize = m_uLoopEnd - uPosition;
        this->m_uVirtualBufferingSize -= uAvailableSize - m_uOffsetInBlock;
        m_pFirst->m_uOffsetInBlock = m_pFirst->m_pBlock->uAvailableSize;
        v15 = this->m_listCancelledXfers.m_pFirst;
        if ( v15 )
        {
          m_pFirst->pNextView = v15;
          this->m_listCancelledXfers.m_pFirst = m_pFirst;
        }
        else
        {
          this->m_listCancelledXfers.m_pFirst = m_pFirst;
          m_pFirst->pNextView = 0i64;
        }
      }
      if ( !pNextView )
        break;
      v7 = v20;
      m_pFirst = v19;
    }
  }
  v16 = this->m_listCancelledXfers.m_pFirst;
  for ( i = 1; v16; i = !in_bNotifyAllCancelled )
  {
    v18 = (AK::StreamMgr::CAkStmMemViewDeferred *)v16;
    v16 = v16->pNextView;
    AK::StreamMgr::CAkStmMemViewDeferred::Cancel(
      v18,
      (AK::StreamMgr::IAkIOHookDeferred *)this->m_pDevice->m_pLowLevelHook,
      i,
      in_bNotifyAllCancelled);
  }
}

// File Line: 298
// RVA: 0xAA7610
AK::StreamMgr::CAkStmMemView *__fastcall AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::GetOldestCompletedTransfer(
        AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase> *this)
{
  AK::StreamMgr::CAkStmMemView *result; // rax

  result = this->m_listPendingXfers.m_pFirst;
  if ( !result || (*((_BYTE *)result + 20) & 7) == 0 )
    return 0i64;
  return result;
}

