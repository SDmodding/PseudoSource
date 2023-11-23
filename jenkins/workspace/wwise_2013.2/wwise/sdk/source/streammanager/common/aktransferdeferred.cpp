// File Line: 36
// RVA: 0xAA90E0
void __fastcall AK::StreamMgr::CAkStmMemViewDeferred::Cancel(
        AK::StreamMgr::CAkStmMemViewDeferred *this,
        AK::StreamMgr::IAkIOHookDeferred *in_pLowLevelHook,
        bool in_bCallLowLevelIO,
        bool in_bAllCancelled)
{
  AK::StreamMgr::CAkDeviceBase *m_pDevice; // rbp
  AK::StreamMgr::AkMemBlock *m_pBlock; // rdx
  AK::StreamMgr::AkMemBlock *pNextBlock; // rbx
  AK::StreamMgr::AkMemBlock *v10; // rcx
  bool v11; // [rsp+58h] [rbp+20h] BYREF

  v11 = in_bAllCancelled;
  m_pDevice = this->m_pOwner->m_pDevice;
  EnterCriticalSection(&m_pDevice->m_lockSems.m_csLock);
  m_pBlock = this->m_pBlock;
  pNextBlock = m_pBlock->pNextBlock;
  if ( pNextBlock )
  {
    v10 = pNextBlock[1].pNextBlock;
    if ( *(_QWORD *)&v10->uAvailableSize || *(_QWORD *)&v10->uRefCount != *(_QWORD *)&pNextBlock[1].uAvailableSize )
    {
      pNextBlock = 0i64;
    }
    else if ( m_pBlock->fileID != -1 )
    {
      AK::StreamMgr::CAkIOMemMgr::UntagBlock(&m_pDevice->m_mgrMemIO, m_pBlock);
    }
  }
  LeaveCriticalSection(&m_pDevice->m_lockSems.m_csLock);
  if ( pNextBlock )
  {
    if ( in_bCallLowLevelIO )
    {
      if ( (pNextBlock[1].uRefCount & 1) != 0 )
        v11 = 0;
      else
        ((void (__fastcall *)(AK::StreamMgr::IAkIOHookDeferred *, _QWORD, void **, bool *))in_pLowLevelHook->vfptr[1].GetBlockSize)(
          in_pLowLevelHook,
          *(_QWORD *)(*(_QWORD *)&pNextBlock[1].uAvailableSize + 40i64),
          &pNextBlock->pData,
          &v11);
    }
    *(_DWORD *)&pNextBlock[1].uRefCount |= 1u;
  }
}

// File Line: 79
// RVA: 0xAA9220
void __fastcall AK::StreamMgr::CAkLowLevelTransferDeferred::LLIOCallback(
        AkAsyncIOTransferInfo *in_pTransferInfo,
        AKRESULT in_eResult)
{
  AK::StreamMgr::CAkLowLevelTransferDeferred *pCookie; // rcx

  pCookie = (AK::StreamMgr::CAkLowLevelTransferDeferred *)in_pTransferInfo->pCookie;
  if ( in_eResult != AK_Success )
    in_eResult = AK_Fail;
  AK::StreamMgr::CAkLowLevelTransferDeferred::Update(pCookie, in_eResult);
}

// File Line: 103
// RVA: 0xAA9240
void __fastcall AK::StreamMgr::CAkLowLevelTransferDeferred::Update(
        AK::StreamMgr::CAkLowLevelTransferDeferred *this,
        unsigned int in_eResult)
{
  AK::StreamMgr::CAkDeviceBase *m_pDevice; // rbp
  AK::StreamMgr::CAkStmMemViewDeferred *m_pFirst; // rbx
  AK::StreamMgr::AkMemBlock *m_pBlock; // rdx
  AK::StreamMgr::CAkIOThreadVtbl *vfptr; // rcx
  AK::StreamMgr::AkMemBlock *pNextBlock; // rax
  __int64 v9; // r9
  AK::StreamMgr::CAkStmMemViewDeferred *i; // rdx
  AK::StreamMgr::CAkStmMemViewDeferred *pNextObserver; // rdi

  m_pDevice = this->m_pOwner->m_pDevice;
  EnterCriticalSection(&m_pDevice->m_lockSems.m_csLock);
  m_pFirst = this->m_observers.m_pFirst;
  this->m_observers.m_pFirst = 0i64;
  m_pBlock = m_pFirst->m_pBlock;
  vfptr = m_pDevice[1].vfptr;
  pNextBlock = m_pBlock->pNextBlock;
  if ( vfptr )
  {
    pNextBlock->uPosition = (unsigned __int64)vfptr;
    m_pDevice[1].vfptr = (AK::StreamMgr::CAkIOThreadVtbl *)pNextBlock;
  }
  else
  {
    m_pDevice[1].vfptr = (AK::StreamMgr::CAkIOThreadVtbl *)pNextBlock;
    pNextBlock->uPosition = 0i64;
  }
  m_pBlock->pNextBlock = 0i64;
  if ( in_eResult != 1 && m_pBlock->fileID != -1 )
    AK::StreamMgr::CAkIOMemMgr::UntagBlock(&m_pDevice->m_mgrMemIO, m_pBlock);
  LeaveCriticalSection(&m_pDevice->m_lockSems.m_csLock);
  LOBYTE(v9) = 1;
  for ( i = m_pFirst; ; i = pNextObserver )
  {
    pNextObserver = i->pNextObserver;
    if ( i == m_pFirst )
      m_pFirst = i->pNextObserver;
    else
      MEMORY[0x18] = i->pNextObserver;
    ((void (__fastcall *)(AK::StreamMgr::CAkStmTask *, AK::StreamMgr::CAkStmMemViewDeferred *, _QWORD, __int64))i->m_pOwner->vfptr[5].__vecDelDtor)(
      i->m_pOwner,
      i,
      in_eResult,
      v9);
    LOBYTE(v9) = 0;
    if ( !pNextObserver )
      break;
  }
}

// File Line: 146
// RVA: 0xAA91B0
__int64 __fastcall AK::StreamMgr::CAkLowLevelTransferDeferred::Execute(
        AK::StreamMgr::CAkLowLevelTransferDeferred *this,
        AK::StreamMgr::IAkIOHookDeferred *in_pLowLevelHook,
        AkFileDesc *in_pFileDesc,
        AkIoHeuristics *in_heuristics,
        bool in_bWriteOp)
{
  AK::StreamMgr::IAkLowLevelIOHookVtbl *vfptr; // rax
  AkAsyncIOTransferInfo *p_info; // r9
  __int64 result; // rax

  if ( (*((_BYTE *)this + 72) & 2) != 0 )
    return 1i64;
  vfptr = in_pLowLevelHook->vfptr;
  p_info = &this->info;
  if ( in_bWriteOp )
    result = ((__int64 (__fastcall *)(AK::StreamMgr::IAkIOHookDeferred *, AkFileDesc *, AkIoHeuristics *, AkAsyncIOTransferInfo *))vfptr[1].Close)(
               in_pLowLevelHook,
               in_pFileDesc,
               in_heuristics,
               p_info);
  else
    result = ((__int64 (__fastcall *)(AK::StreamMgr::IAkIOHookDeferred *, AkFileDesc *, AkIoHeuristics *, AkAsyncIOTransferInfo *))vfptr[1].__vecDelDtor)(
               in_pLowLevelHook,
               in_pFileDesc,
               in_heuristics,
               p_info);
  *((_DWORD *)this + 18) |= 2u;
  return result;
}

