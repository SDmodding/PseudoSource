// File Line: 30
// RVA: 0xAA63F0
void __fastcall AK::StreamMgr::CAkDeviceDeferredLinedUp::CAkDeviceDeferredLinedUp(
        AK::StreamMgr::CAkDeviceDeferredLinedUp *this,
        AK::StreamMgr::IAkLowLevelIOHook *in_pLowLevelHook)
{
  AK::StreamMgr::CAkDeviceBase::CAkDeviceBase(this, in_pLowLevelHook);
  this->vfptr = (AK::StreamMgr::CAkIOThreadVtbl *)&AK::StreamMgr::CAkDeviceDeferredLinedUp::`vftable;
  this->m_poolLowLevelTransfers.m_pFirst = 0i64;
  this->m_pLowLevelTransfersMem = 0i64;
}

// File Line: 41
// RVA: 0xAA76E0
__int64 __fastcall AK::StreamMgr::CAkDeviceDeferredLinedUp::Init(
        AK::StreamMgr::CAkDeviceDeferredLinedUp *this,
        AkDeviceSettings *in_settings,
        unsigned int in_deviceID)
{
  AKRESULT v6; // esi
  AK::StreamMgr::CAkLowLevelTransferDeferred *v7; // rcx
  AK::StreamMgr::CAkLowLevelTransferDeferred *v8; // rdx
  AK::StreamMgr::CAkLowLevelTransferDeferred *m_pFirst; // rax
  unsigned __int64 v10; // rdi
  AK::StreamMgr::CAkStmMemView *v11; // rax
  AK::StreamMgr::CAkStmMemView *v12; // r8
  AK::StreamMgr::CAkStmMemView *v13; // rdx
  AK::StreamMgr::CAkStmMemView *v14; // rcx

  if ( !in_settings->uMaxConcurrentIO )
    return 31i64;
  v6 = AK::StreamMgr::CAkDeviceBase::Init(this, in_settings, in_deviceID);
  if ( v6 == AK_Success )
  {
    v7 = (AK::StreamMgr::CAkLowLevelTransferDeferred *)AK::MemoryMgr::Malloc(
                                                         AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId,
                                                         80i64 * in_settings->uMaxConcurrentIO);
    this->m_pLowLevelTransfersMem = v7;
    if ( !v7 )
      return 2i64;
    v8 = &v7[in_settings->uMaxConcurrentIO];
    do
    {
      if ( v7 )
      {
        v7->pNextTransfer = 0i64;
        v7->m_observers.m_pFirst = 0i64;
      }
      m_pFirst = this->m_poolLowLevelTransfers.m_pFirst;
      if ( m_pFirst )
      {
        v7->pNextTransfer = m_pFirst;
        this->m_poolLowLevelTransfers.m_pFirst = v7;
      }
      else
      {
        this->m_poolLowLevelTransfers.m_pFirst = v7;
        v7->pNextTransfer = 0i64;
      }
      ++v7;
    }
    while ( v7 < v8 );
    v10 = 40i64 * (in_settings->uMaxConcurrentIO + this->m_mgrMemIO.m_uNumViewsAvail);
    v11 = (AK::StreamMgr::CAkStmMemView *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v10);
    this->m_pStmMemViewMem = v11;
    if ( !v11 )
      return 2i64;
    v12 = (AK::StreamMgr::CAkStmMemView *)((char *)v11 + v10);
    do
    {
      if ( v11 )
      {
        *((_DWORD *)v11 + 5) &= ~4u;
        *((_DWORD *)v11 + 5) |= 0xBu;
        v11->pNextView = 0i64;
        v11->m_pBlock = 0i64;
        v11->m_uOffsetInBlock = 0;
        v11[1].pNextView = 0i64;
        v11[1].m_pBlock = 0i64;
      }
      v13 = this->m_poolStmMemView.m_pFirst;
      v14 = v11;
      v11 = (AK::StreamMgr::CAkStmMemView *)((char *)v11 + 40);
      if ( v13 )
      {
        v14->pNextView = v13;
        this->m_poolStmMemView.m_pFirst = v14;
      }
      else
      {
        this->m_poolStmMemView.m_pFirst = v14;
        v14->pNextView = 0i64;
      }
    }
    while ( v11 < v12 );
  }
  return (unsigned int)v6;
}

// File Line: 89
// RVA: 0xAA7180
void __fastcall AK::StreamMgr::CAkDeviceDeferredLinedUp::Destroy(AK::StreamMgr::CAkDeviceDeferredLinedUp *this)
{
  AK::StreamMgr::CAkLowLevelTransferDeferred *m_pLowLevelTransfersMem; // rdx

  AK::StreamMgr::CAkIOThread::Term(this);
  m_pLowLevelTransfersMem = this->m_pLowLevelTransfersMem;
  if ( m_pLowLevelTransfersMem )
  {
    this->m_poolLowLevelTransfers.m_pFirst = 0i64;
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, m_pLowLevelTransfersMem);
  }
  this->m_poolLowLevelTransfers.m_pFirst = 0i64;
  AK::StreamMgr::CAkDeviceBase::Destroy(this);
}

// File Line: 110
// RVA: 0xAA7070
AK::StreamMgr::CAkStdStmBase *__fastcall AK::StreamMgr::CAkDeviceDeferredLinedUp::CreateStd(
        AK::StreamMgr::CAkDeviceDeferredLinedUp *this,
        AkFileDesc *in_pFileDesc,
        AkOpenMode in_eOpenMode,
        AK::IAkStdStream **out_pStream)
{
  AK::IAkStdStream *v6; // rbx
  AK::StreamMgr::CAkStdStmBase *v9; // rax
  AK::StreamMgr::CAkStdStmBase *v10; // rdi
  int v12; // ebx

  v6 = 0i64;
  *out_pStream = 0i64;
  v9 = (AK::StreamMgr::CAkStdStmBase *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0xD0ui64);
  v10 = v9;
  if ( !v9 )
  {
    AK::StreamMgr::CAkStreamMgr::ForceCleanup(this, 100);
    v9 = (AK::StreamMgr::CAkStdStmBase *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0xD0ui64);
    v10 = v9;
    if ( !v9 )
      return 0i64;
  }
  AK::StreamMgr::CAkStdStmBase::CAkStdStmBase(v9);
  v10[1].AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr = 0i64;
  v10[1].m_hBlockEvent = 0i64;
  *(_QWORD *)&v10[1].m_bIsBlocked = 0i64;
  v10->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkStdStmDeferredLinedUp::`vftable{for `AK::StreamMgr::CAkStmTask};
  v10->AK::IAkStdStream::vfptr = (AK::IAkStdStreamVtbl *)&AK::StreamMgr::CAkStdStmDeferredLinedUp::`vftable{for `AK::IAkStdStream};
  if ( (unsigned int)AK::StreamMgr::CAkStdStmBase::Init(v10, this, in_pFileDesc, in_eOpenMode) != 1 )
  {
    if ( v10 )
    {
      v12 = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
      v10->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr->__vecDelDtor(v10, 0);
      AK::MemoryMgr::Free(v12, v10);
    }
    return 0i64;
  }
  AK::StreamMgr::CAkDeviceBase::AddTask(this, v10);
  if ( v10 )
    v6 = &v10->AK::IAkStdStream;
  *out_pStream = v6;
  return v10;
}

// File Line: 162
// RVA: 0xAA6B20
AK::StreamMgr::CAkAutoStmBase *__fastcall AK::StreamMgr::CAkDeviceDeferredLinedUp::CreateAuto(
        AK::StreamMgr::CAkDeviceDeferredLinedUp *this,
        AkFileDesc *in_pFileDesc,
        unsigned int in_fileID,
        AkAutoStmHeuristics *in_heuristics,
        AkAutoStmBufSettings *in_pBufferSettings,
        AK::IAkAutoStream **out_pStream)
{
  AK::IAkAutoStream *v8; // rsi
  AK::StreamMgr::CAkAutoStmBase *v11; // rax
  AK::StreamMgr::CAkAutoStmBase *v12; // rdi
  AK::StreamMgr::CAkAutoStmBase *result; // rax
  int v14; // ebx

  v8 = 0i64;
  *out_pStream = 0i64;
  v11 = (AK::StreamMgr::CAkAutoStmBase *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0xE0ui64);
  v12 = v11;
  if ( !v11 )
  {
    AK::StreamMgr::CAkStreamMgr::ForceCleanup(this, in_heuristics->priority);
    v11 = (AK::StreamMgr::CAkAutoStmBase *)AK::MemoryMgr::Malloc(
                                             AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId,
                                             0xE0ui64);
    v12 = v11;
    if ( !v11 )
    {
LABEL_9:
      result = 0i64;
      goto LABEL_10;
    }
  }
  AK::StreamMgr::CAkAutoStmBase::CAkAutoStmBase(v11);
  v12[1].AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr = 0i64;
  v12[1].m_hBlockEvent = 0i64;
  *(_QWORD *)&v12[1].m_bIsBlocked = 0i64;
  v12->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkAutoStmDeferredLinedUp::`vftable{for `AK::StreamMgr::CAkStmTask};
  v12->AK::IAkAutoStream::vfptr = (AK::IAkAutoStreamVtbl *)&AK::StreamMgr::CAkAutoStmDeferredLinedUp::`vftable{for `AK::IAkAutoStream};
  if ( AK::StreamMgr::CAkAutoStmBase::Init(
         v12,
         this,
         in_pFileDesc,
         in_fileID,
         in_heuristics,
         in_pBufferSettings,
         this->m_uGranularity) != AK_Success )
  {
    if ( v12 )
    {
      v14 = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
      v12->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr->__vecDelDtor(v12, 0);
      AK::MemoryMgr::Free(v14, v12);
    }
    goto LABEL_9;
  }
  AK::StreamMgr::CAkDeviceBase::AddTask(this, v12);
  if ( v12 )
    v8 = &v12->AK::IAkAutoStream;
  result = v12;
LABEL_10:
  *out_pStream = v8;
  return result;
}

// File Line: 226
// RVA: 0xAA7830
void __fastcall AK::StreamMgr::CAkDeviceDeferredLinedUp::PerformIO(AK::StreamMgr::CAkDeviceDeferredLinedUp *this)
{
  AK::StreamMgr::CAkStmTask *NextTask; // rax
  float out_fOpDeadline; // [rsp+38h] [rbp+10h] BYREF

  NextTask = AK::StreamMgr::CAkDeviceBase::SchedulerFindNextTask(this, &out_fOpDeadline);
  if ( NextTask )
    AK::StreamMgr::CAkDeviceDeferredLinedUp::ExecuteTask(this, NextTask, out_fOpDeadline);
}

// File Line: 242
// RVA: 0xAA7270
void __fastcall AK::StreamMgr::CAkDeviceDeferredLinedUp::ExecuteTask(
        AK::StreamMgr::CAkDeviceDeferredLinedUp *this,
        AK::StreamMgr::CAkStmTask *in_pTask,
        float in_fOpDeadline)
{
  bool v5; // zf
  AK::StreamMgr::CAkClientThreadAwareVtbl *vfptr; // rax
  __int64 v7; // rdx
  AK::StreamMgr::CAkLowLevelTransferDeferred *v8; // rdi
  char m_priority; // al
  AK::StreamMgr::IAkIOHookDeferred *m_pLowLevelHook; // rdx
  AKRESULT v11; // eax
  AK::StreamMgr::CAkLowLevelTransferDeferred *v12; // [rsp+30h] [rbp-28h] BYREF
  AkFileDesc *in_pFileDesc; // [rsp+38h] [rbp-20h] BYREF
  AkIoHeuristics in_heuristics; // [rsp+78h] [rbp+20h] BYREF

  AK::StreamMgr::CAkIOThread::IncrementIOCount(this);
  v5 = (unsigned int)AK::StreamMgr::CAkStmTask::EnsureFileIsOpen(in_pTask) == 1;
  vfptr = in_pTask->vfptr;
  if ( v5 )
  {
    v7 = ((__int64 (__fastcall *)(AK::StreamMgr::CAkStmTask *, AkFileDesc **, AK::StreamMgr::CAkLowLevelTransferDeferred **, _QWORD))vfptr[4].__vecDelDtor)(
           in_pTask,
           &in_pFileDesc,
           &v12,
           0i64);
    if ( v7 )
    {
      v8 = v12;
      if ( v12 )
      {
        m_priority = in_pTask->m_priority;
        m_pLowLevelHook = (AK::StreamMgr::IAkIOHookDeferred *)this->m_pLowLevelHook;
        in_heuristics.fDeadline = in_fOpDeadline;
        in_heuristics.priority = m_priority;
        v11 = AK::StreamMgr::CAkLowLevelTransferDeferred::Execute(
                v12,
                m_pLowLevelHook,
                in_pFileDesc,
                &in_heuristics,
                (*((_BYTE *)in_pTask + 117) & 2) != 0);
        if ( v11 != AK_Success )
          AK::StreamMgr::CAkLowLevelTransferDeferred::LLIOCallback(&v8->info, v11);
      }
      else
      {
        ((void (__fastcall *)(AK::StreamMgr::CAkStmTask *, __int64, __int64))in_pTask->vfptr[5].__vecDelDtor)(
          in_pTask,
          v7,
          1i64);
      }
    }
    else
    {
      ((void (__fastcall *)(AK::StreamMgr::CAkStmTask *, _QWORD, __int64, _QWORD))in_pTask->vfptr[5].__vecDelDtor)(
        in_pTask,
        0i64,
        53i64,
        0i64);
    }
  }
  else
  {
    ((void (__fastcall *)(AK::StreamMgr::CAkStmTask *, _QWORD, __int64))vfptr[5].__vecDelDtor)(in_pTask, 0i64, 2i64);
  }
}

// File Line: 317
// RVA: 0xAA6EE0
AK::StreamMgr::CAkStmMemViewDeferred *__fastcall AK::StreamMgr::CAkDeviceDeferredLinedUp::CreateMemViewStd(
        AK::StreamMgr::CAkDeviceDeferredLinedUp *this,
        AK::StreamMgr::CAkStdStmDeferredLinedUp *in_pOwner,
        AK::StreamMgr::AkMemBlock *in_pMemBlock,
        unsigned int in_uDataOffset,
        unsigned __int64 in_uPosition,
        unsigned int in_uBufferSize,
        unsigned int in_uRequestedSize,
        AK::StreamMgr::CAkLowLevelTransferDeferred **out_pLowLevelXfer)
{
  AK::StreamMgr::CAkLowLevelTransferDeferred **v8; // r12
  AK::StreamMgr::CAkStmMemView *v10; // rbp
  __int64 v11; // r13
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rbx
  AK::StreamMgr::CAkLowLevelTransferDeferred *v15; // rdx
  char *v16; // r8
  __int64 v17; // rax
  AK::StreamMgr::CAkLowLevelTransferDeferred **v18; // rax
  AK::StreamMgr::CAkLowLevelTransferDeferred **v19; // rax
  AK::StreamMgr::CAkLowLevelTransferDeferred *v20; // rax
  AK::StreamMgr::CAkStmMemViewDeferred *v21; // rcx
  AK::StreamMgr::CAkStmMemView *m_pLast; // rax

  v8 = out_pLowLevelXfer;
  v10 = 0i64;
  v11 = in_uDataOffset;
  *out_pLowLevelXfer = 0i64;
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  m_pFirst = this->m_poolStmMemView.m_pFirst;
  if ( m_pFirst )
    this->m_poolStmMemView.m_pFirst = m_pFirst->pNextView;
  if ( in_pMemBlock->pNextBlock )
  {
    AK::StreamMgr::CAkIOMemMgr::CloneTempBlock(
      &this->m_mgrMemIO,
      in_pMemBlock,
      (AK::StreamMgr::AkMemBlock **)&out_pLowLevelXfer);
    in_pMemBlock = (AK::StreamMgr::AkMemBlock *)out_pLowLevelXfer;
    if ( !out_pLowLevelXfer )
    {
      AK::StreamMgr::CAkDeviceBase::DestroyMemView(this, m_pFirst);
      goto LABEL_16;
    }
  }
  else
  {
    out_pLowLevelXfer = (AK::StreamMgr::CAkLowLevelTransferDeferred **)in_pMemBlock;
  }
  v15 = this->m_poolLowLevelTransfers.m_pFirst;
  v16 = (char *)in_pMemBlock->pData + v11;
  if ( v15 )
    this->m_poolLowLevelTransfers.m_pFirst = v15->pNextTransfer;
  v17 = in_pOwner->m_uLLBlockSize * in_pOwner->m_pFileDesc->uSector;
  *((_DWORD *)v15 + 18) &= 0xFFFFFFFC;
  v15->info.pBuffer = v16;
  v15->info.pCookie = v15;
  v15->info.pUserData = 0i64;
  v15->info.uFilePosition = in_uPosition + v17;
  v15->m_pOwner = in_pOwner;
  v15->info.uBufferSize = in_uBufferSize;
  v15->info.uRequestedSize = in_uRequestedSize;
  v15->info.pCallback = AK::StreamMgr::CAkLowLevelTransferDeferred::LLIOCallback;
  v18 = out_pLowLevelXfer;
  *v8 = v15;
  v18[2] = v15;
  v19 = out_pLowLevelXfer;
  *((_DWORD *)m_pFirst + 5) &= 0xFFFFFFF8;
  m_pFirst->m_pBlock = (AK::StreamMgr::AkMemBlock *)v19;
  m_pFirst->m_uOffsetInBlock = v11;
  v20 = *v8;
  v21 = (*v8)->m_observers.m_pFirst;
  if ( v21 )
  {
    m_pFirst[1].pNextView = v21;
    v20->m_observers.m_pFirst = (AK::StreamMgr::CAkStmMemViewDeferred *)m_pFirst;
  }
  else
  {
    v20->m_observers.m_pFirst = (AK::StreamMgr::CAkStmMemViewDeferred *)m_pFirst;
    m_pFirst[1].pNextView = 0i64;
  }
  m_pFirst->pNextView = 0i64;
  m_pLast = in_pOwner->m_listPendingXfers.m_pLast;
  if ( m_pLast )
    m_pLast->pNextView = m_pFirst;
  else
    in_pOwner->m_listPendingXfers.m_pFirst = m_pFirst;
  in_pOwner->m_listPendingXfers.m_pLast = m_pFirst;
  v10 = m_pFirst;
  m_pFirst[1].m_pBlock = (AK::StreamMgr::AkMemBlock *)in_pOwner;
LABEL_16:
  LeaveCriticalSection(&this->m_lockSems.m_csLock);
  return (AK::StreamMgr::CAkStmMemViewDeferred *)v10;
}

// File Line: 389
// RVA: 0xAA6C60
AK::StreamMgr::CAkStmMemViewDeferred *__fastcall AK::StreamMgr::CAkDeviceDeferredLinedUp::CreateMemViewAuto(
        AK::StreamMgr::CAkDeviceDeferredLinedUp *this,
        AK::StreamMgr::CAkAutoStmDeferredLinedUp *in_pOwner,
        unsigned int in_fileID,
        unsigned __int64 in_uPosition,
        unsigned int in_uMinSize,
        unsigned int in_uRequiredAlign,
        bool in_bEof,
        unsigned int *io_uRequestedSize,
        AK::StreamMgr::CAkLowLevelTransferDeferred **out_pLowLevelXfer)
{
  AK::StreamMgr::CAkLowLevelTransferDeferred **v9; // r14
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rbx
  bool v15; // zf
  unsigned int CachedBlock; // eax
  AK::StreamMgr::CAkLowLevelTransferDeferred **v17; // rcx
  AK::StreamMgr::CAkLowLevelTransferDeferred *v18; // rcx
  AK::StreamMgr::CAkStmMemViewDeferred *v19; // rax
  AK::StreamMgr::CAkLowLevelTransferDeferred *v20; // r8
  unsigned int v21; // edx
  unsigned int m_uGranularity; // r9d
  AK::StreamMgr::CAkLowLevelTransferDeferred *v23; // r10
  __int64 v24; // rax
  AK::StreamMgr::AkMemBlock *v25; // rdx
  AK::StreamMgr::CAkLowLevelTransferDeferred **v26; // rax
  AK::StreamMgr::CAkLowLevelTransferDeferred *v27; // rax
  AK::StreamMgr::CAkStmMemViewDeferred *v28; // rcx
  AK::StreamMgr::CAkStmMemView *m_pLast; // rax

  v9 = out_pLowLevelXfer;
  *out_pLowLevelXfer = 0i64;
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  m_pFirst = this->m_poolStmMemView.m_pFirst;
  if ( m_pFirst )
    this->m_poolStmMemView.m_pFirst = m_pFirst->pNextView;
  v15 = !this->m_mgrMemIO.m_bUseCache;
  out_pLowLevelXfer = 0i64;
  if ( v15
    || in_fileID == -1
    || (CachedBlock = AK::StreamMgr::CAkIOMemMgr::GetCachedBlock(
                        &this->m_mgrMemIO,
                        in_fileID,
                        in_uPosition,
                        in_uMinSize,
                        in_uRequiredAlign,
                        in_bEof,
                        io_uRequestedSize,
                        (AK::StreamMgr::AkMemBlock **)&out_pLowLevelXfer),
        (v17 = out_pLowLevelXfer) == 0i64) )
  {
    AK::StreamMgr::CAkIOMemMgr::GetOldestFreeBlock(&this->m_mgrMemIO, (AK::StreamMgr::AkMemBlock **)&out_pLowLevelXfer);
    if ( !out_pLowLevelXfer )
    {
      AK::StreamMgr::CAkDeviceBase::DestroyMemView(this, m_pFirst);
      AK::StreamMgr::CAkIOThread::NotifyMemIdle(this);
      m_pFirst = 0i64;
      goto LABEL_21;
    }
    v20 = this->m_poolLowLevelTransfers.m_pFirst;
    v21 = *io_uRequestedSize;
    m_uGranularity = this->m_uGranularity;
    v23 = out_pLowLevelXfer[1];
    if ( v20 )
      this->m_poolLowLevelTransfers.m_pFirst = v20->pNextTransfer;
    v24 = in_pOwner->m_uLLBlockSize * in_pOwner->m_pFileDesc->uSector;
    *((_DWORD *)v20 + 18) &= 0xFFFFFFFC;
    v20->info.uBufferSize = m_uGranularity;
    v20->info.pBuffer = v23;
    v20->info.uRequestedSize = v21;
    v20->info.uFilePosition = in_uPosition + v24;
    v20->info.pCookie = v20;
    v20->info.pUserData = 0i64;
    v20->m_pOwner = in_pOwner;
    v20->info.pCallback = AK::StreamMgr::CAkLowLevelTransferDeferred::LLIOCallback;
    v25 = (AK::StreamMgr::AkMemBlock *)out_pLowLevelXfer;
    *v9 = v20;
    AK::StreamMgr::CAkIOMemMgr::TagBlock(&this->m_mgrMemIO, v25, v20, in_fileID, in_uPosition, *io_uRequestedSize);
    v26 = out_pLowLevelXfer;
    *((_DWORD *)m_pFirst + 5) &= 0xFFFFFFF8;
    m_pFirst->m_pBlock = (AK::StreamMgr::AkMemBlock *)v26;
    m_pFirst->m_uOffsetInBlock = 0;
    v27 = *v9;
    v28 = (*v9)->m_observers.m_pFirst;
    if ( v28 )
    {
      m_pFirst[1].pNextView = v28;
      v27->m_observers.m_pFirst = (AK::StreamMgr::CAkStmMemViewDeferred *)m_pFirst;
    }
    else
    {
      v27->m_observers.m_pFirst = (AK::StreamMgr::CAkStmMemViewDeferred *)m_pFirst;
      m_pFirst[1].pNextView = 0i64;
    }
  }
  else
  {
    *((_DWORD *)m_pFirst + 5) &= 0xFFFFFFF8;
    m_pFirst->m_pBlock = (AK::StreamMgr::AkMemBlock *)v17;
    m_pFirst->m_uOffsetInBlock = CachedBlock;
    v18 = out_pLowLevelXfer[2];
    *v9 = v18;
    if ( v18 )
    {
      v19 = v18->m_observers.m_pFirst;
      if ( v19 )
      {
        m_pFirst[1].pNextView = v19;
        v18->m_observers.m_pFirst = (AK::StreamMgr::CAkStmMemViewDeferred *)m_pFirst;
      }
      else
      {
        v18->m_observers.m_pFirst = (AK::StreamMgr::CAkStmMemViewDeferred *)m_pFirst;
        m_pFirst[1].pNextView = 0i64;
      }
    }
  }
  m_pFirst->pNextView = 0i64;
  m_pLast = in_pOwner->m_listPendingXfers.m_pLast;
  if ( m_pLast )
    m_pLast->pNextView = m_pFirst;
  else
    in_pOwner->m_listPendingXfers.m_pFirst = m_pFirst;
  in_pOwner->m_listPendingXfers.m_pLast = m_pFirst;
  m_pFirst[1].m_pBlock = (AK::StreamMgr::AkMemBlock *)in_pOwner;
LABEL_21:
  LeaveCriticalSection(&this->m_lockSems.m_csLock);
  return (AK::StreamMgr::CAkStmMemViewDeferred *)m_pFirst;
}

// File Line: 488
// RVA: 0xAA65C0
void __fastcall AK::StreamMgr::CAkStdStmDeferredLinedUp::Cancel(AK::StreamMgr::CAkStdStmDeferredLinedUp *this)
{
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock.pData);
  if ( this->m_lockStatus.m_csLock.OwningThread || this->m_lockStatus.m_csLock.SpinCount )
  {
    AK::StreamMgr::CAkStdStmBase::SetStatus(
      (AK::StreamMgr::CAkStdStmDeferredLinedUp *)((char *)this - 120),
      AK_StmStatusCancelled);
    AK::StreamMgr::CAkClientThreadAware::SetBlockedStatus((AK::StreamMgr::CAkStdStmDeferredLinedUp *)((char *)this - 120));
    AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkStdStmBase>::CancelTransfers(
      (AK::StreamMgr::CAkStdStmDeferredLinedUp *)((char *)this - 120),
      (AkListBare<AK::StreamMgr::CAkStmMemView,AK::StreamMgr::AkListBareNextMemView,AkCountPolicyNoCount> *)&this->m_lockStatus.m_csLock.OwningThread,
      1);
    LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock.pData);
    AK::StreamMgr::CAkIOThread::WaitForIOCompletion(
      (AK::StreamMgr::CAkIOThread *)this[-1].m_listPendingXfers.m_pFirst,
      (AK::StreamMgr::CAkStdStmDeferredLinedUp *)((char *)this - 120));
  }
  else
  {
    AK::StreamMgr::CAkStdStmBase::SetStatus(
      (AK::StreamMgr::CAkStdStmDeferredLinedUp *)((char *)this - 120),
      AK_StmStatusCancelled);
    LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock.pData);
  }
}

// File Line: 517
// RVA: 0xAA7650
__int64 __fastcall AK::StreamMgr::CAkStdStmDeferredLinedUp::GetStatus(AK::StreamMgr::CAkStdStmDeferredLinedUp *this)
{
  _RTL_CRITICAL_SECTION *p_pData; // rbx
  unsigned int v3; // edi

  p_pData = (_RTL_CRITICAL_SECTION *)&this[-1].m_memBlock.pData;
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock.pData);
  if ( this->m_lockStatus.m_csLock.OwningThread )
    v3 = 2;
  else
    v3 = this->m_lockStatus.m_csLock.LockCount << 28 >> 28;
  LeaveCriticalSection(p_pData);
  return v3;
}

// File Line: 528
// RVA: 0xAA71D0
void __fastcall AK::StreamMgr::CAkStdStmDeferredLinedUp::Destroy(AK::StreamMgr::CAkStdStmDeferredLinedUp *this)
{
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock.pData);
  BYTE5(this[-1].m_listCancelledXfers.m_pFirst) = BYTE5(this[-1].m_listCancelledXfers.m_pFirst) & 0xB7 | 8;
  AK::StreamMgr::CAkStdStmBase::SetStatus(
    (AK::StreamMgr::CAkStdStmDeferredLinedUp *)((char *)this - 120),
    AK_StmStatusCancelled);
  if ( this->m_lockStatus.m_csLock.OwningThread || this->m_lockStatus.m_csLock.SpinCount )
  {
    AK::StreamMgr::CAkClientThreadAware::SetBlockedStatus((AK::StreamMgr::CAkStdStmDeferredLinedUp *)((char *)this - 120));
    AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkStdStmBase>::CancelTransfers(
      (AK::StreamMgr::CAkStdStmDeferredLinedUp *)((char *)this - 120),
      (AkListBare<AK::StreamMgr::CAkStmMemView,AK::StreamMgr::AkListBareNextMemView,AkCountPolicyNoCount> *)&this->m_lockStatus.m_csLock.OwningThread,
      1);
    LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock.pData);
    AK::StreamMgr::CAkIOThread::WaitForIOCompletion(
      (AK::StreamMgr::CAkIOThread *)this[-1].m_listPendingXfers.m_pFirst,
      (AK::StreamMgr::CAkStdStmDeferredLinedUp *)((char *)this - 120));
  }
  else
  {
    LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock.pData);
  }
}

// File Line: 568
// RVA: 0xAA7B50
AK::StreamMgr::CAkStmMemViewDeferred *__fastcall AK::StreamMgr::CAkStdStmDeferredLinedUp::PrepareTransfer(
        AK::StreamMgr::CAkStdStmDeferredLinedUp *this,
        AkFileDesc **out_pFileDesc,
        AK::StreamMgr::CAkLowLevelTransferDeferred **out_pLowLevelXfer,
        bool __formal)
{
  char v7; // al
  AK::StreamMgr::CAkDeviceDeferredLinedUp *m_pDevice; // r10
  unsigned int in_uBufferSize; // ecx
  unsigned __int64 in_uPosition; // rdx
  char v11; // r14
  unsigned __int64 iFileSize; // rsi
  unsigned int in_uRequestedSize; // esi
  AK::StreamMgr::CAkStmMemViewDeferred *v14; // rbp
  AK::StreamMgr::CAkLowLevelTransferDeferred *v16; // [rsp+60h] [rbp+8h] BYREF

  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  v7 = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117);
  if ( (v7 & 8) != 0 || (v7 & 0x40) == 0 )
    goto LABEL_16;
  *out_pFileDesc = this->m_pFileDesc;
  m_pDevice = (AK::StreamMgr::CAkDeviceDeferredLinedUp *)this->m_pDevice;
  in_uBufferSize = this->m_memBlock.uAvailableSize - this->m_uTotalScheduledSize;
  in_uPosition = this->m_memBlock.uPosition + this->m_uTotalScheduledSize;
  if ( in_uBufferSize > m_pDevice->m_uGranularity )
    in_uBufferSize = m_pDevice->m_uGranularity;
  v11 = 0;
  if ( (*((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) & 2) != 0
    || (iFileSize = this->m_pFileDesc->iFileSize, in_uPosition + in_uBufferSize <= iFileSize) )
  {
    in_uRequestedSize = in_uBufferSize;
  }
  else
  {
    v11 = 1;
    in_uRequestedSize = in_uPosition >= iFileSize ? 0 : iFileSize - in_uPosition;
  }
  v14 = AK::StreamMgr::CAkDeviceDeferredLinedUp::CreateMemViewStd(
          m_pDevice,
          this,
          &this->m_memBlock,
          this->m_uTotalScheduledSize,
          in_uPosition,
          in_uBufferSize,
          in_uRequestedSize,
          &v16);
  if ( v14 )
  {
    *out_pLowLevelXfer = v16;
    this->m_uTotalScheduledSize += in_uRequestedSize;
    if ( v11 || this->m_uTotalScheduledSize == this->m_memBlock.uAvailableSize )
      AK::StreamMgr::CAkStdStmBase::SetStatus(this, AK_StmStatusIdle);
    this->m_iIOStartTime = this->m_pDevice->m_time;
  }
  else
  {
LABEL_16:
    v14 = 0i64;
  }
  LeaveCriticalSection(&this->m_lockStatus.m_csLock);
  return v14;
}

// File Line: 660
// RVA: 0xAA7A00
AK::StreamMgr::CAkStmMemViewDeferred *__fastcall AK::StreamMgr::CAkAutoStmDeferredLinedUp::PrepareTransfer(
        AK::StreamMgr::CAkAutoStmDeferredLinedUp *this,
        AkFileDesc **out_pFileDesc,
        AK::StreamMgr::CAkLowLevelTransferDeferred **out_pLowLevelXfer,
        bool __formal)
{
  char v6; // al
  unsigned __int64 m_uLoopStart; // rsi
  unsigned __int64 m_uLoopEnd; // rax
  __int64 in_uMinSize; // rcx
  unsigned __int64 iFileSize; // rdx
  bool in_bEof; // r8
  unsigned int m_uMinBufferSize; // eax
  AK::StreamMgr::CAkStmMemViewDeferred *v13; // rbp
  unsigned __int64 v14; // rdx
  unsigned int v15; // ecx
  unsigned int io_uRequestedSize; // [rsp+70h] [rbp+8h] BYREF
  AK::StreamMgr::CAkLowLevelTransferDeferred *v18; // [rsp+78h] [rbp+10h] BYREF

  *out_pFileDesc = this->m_pFileDesc;
  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  v6 = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117);
  if ( (v6 & 8) != 0 || (v6 & 0x40) == 0 )
    goto LABEL_19;
  m_uLoopStart = ((__int64 (__fastcall *)(AK::StreamMgr::CAkAutoStmDeferredLinedUp *))this->AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::AK::StreamMgr::CAkAutoStmBase::AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr[7].__vecDelDtor)(this);
  m_uLoopEnd = this->m_uLoopEnd;
  if ( (_DWORD)m_uLoopEnd && m_uLoopStart >= m_uLoopEnd )
    m_uLoopStart = this->m_uLoopStart;
  in_uMinSize = this->m_uBufferSize;
  iFileSize = this->m_pFileDesc->iFileSize;
  if ( m_uLoopStart + in_uMinSize > iFileSize )
  {
    in_bEof = 1;
    if ( m_uLoopStart >= iFileSize )
      LODWORD(in_uMinSize) = 0;
    else
      LODWORD(in_uMinSize) = iFileSize - m_uLoopStart;
  }
  else
  {
    in_bEof = 0;
  }
  m_uMinBufferSize = this->m_uMinBufferSize;
  io_uRequestedSize = in_uMinSize;
  if ( m_uMinBufferSize < (unsigned int)in_uMinSize )
    LODWORD(in_uMinSize) = m_uMinBufferSize;
  v13 = AK::StreamMgr::CAkDeviceDeferredLinedUp::CreateMemViewAuto(
          (AK::StreamMgr::CAkDeviceDeferredLinedUp *)this->m_pDevice,
          this,
          this->m_fileID,
          m_uLoopStart,
          in_uMinSize,
          this->m_uBufferAlignment,
          in_bEof,
          &io_uRequestedSize,
          &v18);
  if ( v13 )
  {
    *out_pLowLevelXfer = v18;
    v14 = this->m_uLoopEnd;
    if ( m_uLoopStart >= v14 )
    {
      v15 = io_uRequestedSize;
    }
    else
    {
      v15 = io_uRequestedSize;
      if ( m_uLoopStart + io_uRequestedSize > v14 )
      {
        v15 = v14 - m_uLoopStart;
        io_uRequestedSize = v14 - m_uLoopStart;
      }
    }
    this->m_uVirtualBufferingSize += v15;
    AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus(this);
    this->m_iIOStartTime = this->m_pDevice->m_time;
  }
  else
  {
LABEL_19:
    v13 = 0i64;
  }
  LeaveCriticalSection(&this->m_lockStatus.m_csLock);
  return v13;
}

// File Line: 713
// RVA: 0xAA76A0
unsigned __int64 __fastcall AK::StreamMgr::CAkAutoStmDeferredLinedUp::GetVirtualFilePosition(
        AK::StreamMgr::CAkAutoStmDeferredLinedUp *this)
{
  AK::StreamMgr::CAkStmMemView *m_pLast; // rax

  m_pLast = this->m_listPendingXfers.m_pLast;
  if ( m_pLast )
    return m_pLast->m_pBlock->uPosition + m_pLast->m_pBlock->uAvailableSize;
  if ( this->m_listBuffers.m_ulNumListItems > (unsigned __int8)this->m_uNextToGrant )
  {
    m_pLast = this->m_listBuffers.m_pLast;
    return m_pLast->m_pBlock->uPosition + m_pLast->m_pBlock->uAvailableSize;
  }
  return this->m_uNextExpectedUserPosition;
}

// File Line: 730
// RVA: 0xAA6660
void __fastcall AK::StreamMgr::CAkAutoStmDeferredLinedUp::CancelAllPendingTransfers(
        AK::StreamMgr::CAkAutoStmDeferredLinedUp *this)
{
  AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::CancelTransfers(
    this,
    &this->m_listPendingXfers,
    !this->m_pDevice->m_mgrMemIO.m_bUseCache);
}

// File Line: 746
// RVA: 0xAA6680
void __fastcall AK::StreamMgr::CAkAutoStmDeferredLinedUp::CancelInconsistentPendingTransfers(
        AK::StreamMgr::CAkAutoStmDeferredLinedUp *this,
        unsigned __int64 in_uNextExpectedPosition)
{
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rax
  AK::StreamMgr::CAkStmMemView *v4; // r10
  AK::StreamMgr::CAkStmMemView *v5; // r8
  AK::StreamMgr::AkMemBlock *m_pBlock; // r11
  AK::StreamMgr::CAkStmMemView *pNextView; // rcx
  unsigned __int64 m_uLoopEnd; // rcx
  AkListBare<AK::StreamMgr::CAkStmMemView,AK::StreamMgr::AkListBareNextMemView,AkCountPolicyNoCount> in_listToCancel; // [rsp+20h] [rbp-38h] BYREF
  __int128 v10; // [rsp+30h] [rbp-28h]
  __int128 v11; // [rsp+40h] [rbp-18h]

  m_pFirst = this->m_listPendingXfers.m_pFirst;
  v4 = 0i64;
  in_listToCancel.m_pFirst = 0i64;
  in_listToCancel.m_pLast = 0i64;
  v5 = 0i64;
  while ( m_pFirst )
  {
    m_pBlock = m_pFirst->m_pBlock;
    if ( m_pBlock->uPosition + m_pFirst->m_uOffsetInBlock == in_uNextExpectedPosition )
    {
      m_uLoopEnd = this->m_uLoopEnd;
      in_uNextExpectedPosition = m_pBlock->uPosition + m_pBlock->uAvailableSize;
      if ( (_DWORD)m_uLoopEnd && in_uNextExpectedPosition >= m_uLoopEnd )
        in_uNextExpectedPosition = this->m_uLoopStart;
      v5 = m_pFirst;
      m_pFirst = m_pFirst->pNextView;
    }
    else
    {
      pNextView = m_pFirst->pNextView;
      *((_QWORD *)&v11 + 1) = v5;
      *(_QWORD *)&v11 = pNextView;
      if ( m_pFirst == this->m_listPendingXfers.m_pFirst )
        this->m_listPendingXfers.m_pFirst = pNextView;
      else
        v5->pNextView = pNextView;
      if ( m_pFirst == this->m_listPendingXfers.m_pLast )
        this->m_listPendingXfers.m_pLast = v5;
      in_listToCancel.m_pFirst = m_pFirst;
      v10 = v11;
      v5 = (AK::StreamMgr::CAkStmMemView *)*((_QWORD *)&v11 + 1);
      if ( v4 )
      {
        m_pFirst->pNextView = v4;
        v4 = m_pFirst;
      }
      else
      {
        in_listToCancel.m_pLast = m_pFirst;
        v4 = m_pFirst;
        m_pFirst->pNextView = 0i64;
      }
      m_pFirst = (AK::StreamMgr::CAkStmMemView *)v10;
    }
  }
  if ( this->m_pDevice->m_mgrMemIO.m_bUseCache || this->m_listPendingXfers.m_pFirst )
    AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::CancelTransfers(this, &in_listToCancel, 0);
  else
    AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::CancelTransfers(this, &in_listToCancel, 1);
}

// File Line: 787
// RVA: 0xAA7370
void __fastcall AK::StreamMgr::CAkAutoStmDeferredLinedUp::FlushSmallBuffersAndPendingTransfers(
        AK::StreamMgr::CAkAutoStmDeferredLinedUp *this,
        unsigned int in_uMinBufferSize)
{
  __int64 m_uNextToGrant; // rax
  char v3; // bp
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rbx
  AK::StreamMgr::CAkStmMemView *v7; // rsi
  CAkLock *p_m_lockSems; // r15
  AK::StreamMgr::CAkStmMemView *pNextView; // rax
  bool v10; // r15
  AK::StreamMgr::CAkStmMemView *v11; // rdx
  AK::StreamMgr::CAkStmMemView *v12; // r8
  AK::StreamMgr::CAkStmMemView *v13; // rbx
  bool i; // r8
  AK::StreamMgr::CAkStmMemViewDeferred *v15; // rcx
  AK::StreamMgr::CAkStmMemView *v16; // rbx
  int v17; // eax
  AK::StreamMgr::AkMemBlock *m_pBlock; // r8
  __int64 m_uOffsetInBlock; // r9
  unsigned __int64 uPosition; // r10
  unsigned __int64 m_uLoopEnd; // rcx
  int v22; // ecx
  AK::StreamMgr::CAkStmMemView *v23; // rax
  AK::StreamMgr::CAkStmMemView *v24; // [rsp+20h] [rbp-38h]
  AK::StreamMgr::CAkStmMemView *v25; // [rsp+30h] [rbp-28h]
  AK::StreamMgr::CAkStmMemView *v26; // [rsp+38h] [rbp-20h]

  m_uNextToGrant = (unsigned __int8)this->m_uNextToGrant;
  v3 = 0;
  if ( this->m_listBuffers.m_ulNumListItems <= (unsigned int)m_uNextToGrant )
    goto LABEL_20;
  m_pFirst = this->m_listBuffers.m_pFirst;
  v7 = 0i64;
  if ( this->m_uNextToGrant )
  {
    do
    {
      v7 = m_pFirst;
      m_pFirst = m_pFirst->pNextView;
      --m_uNextToGrant;
    }
    while ( m_uNextToGrant );
  }
  p_m_lockSems = &this->m_pDevice->m_lockSems;
  EnterCriticalSection(&p_m_lockSems->m_csLock);
  if ( m_pFirst )
  {
    do
    {
      if ( v3 || m_pFirst->m_pBlock->uAvailableSize - m_pFirst->m_uOffsetInBlock < in_uMinBufferSize )
      {
        pNextView = m_pFirst->pNextView;
        v3 = 1;
        v24 = m_pFirst->pNextView;
        if ( m_pFirst == this->m_listBuffers.m_pFirst )
          this->m_listBuffers.m_pFirst = pNextView;
        else
          v7->pNextView = pNextView;
        if ( m_pFirst == this->m_listBuffers.m_pLast )
          this->m_listBuffers.m_pLast = v7;
        --this->m_listBuffers.m_ulNumListItems;
        AK::StreamMgr::CAkAutoStmBase::DestroyBuffer(this, m_pFirst);
        m_pFirst = v24;
      }
      else
      {
        v7 = m_pFirst;
        m_pFirst = m_pFirst->pNextView;
      }
    }
    while ( m_pFirst );
    if ( v3 )
      AK::StreamMgr::CAkIOThread::NotifyMemChange(this->m_pDevice);
  }
  LeaveCriticalSection(&p_m_lockSems->m_csLock);
  if ( !v3 || this->m_pDevice->m_mgrMemIO.m_bUseCache )
LABEL_20:
    v10 = 0;
  else
    v10 = 1;
  v11 = this->m_listPendingXfers.m_pFirst;
  v12 = 0i64;
  if ( !v3 )
  {
    if ( !v11 )
      goto LABEL_25;
    while ( v11->m_pBlock->uAvailableSize - v11->m_uOffsetInBlock >= in_uMinBufferSize )
    {
      v12 = v11;
      v11 = v11->pNextView;
      if ( !v11 )
        goto LABEL_25;
    }
  }
  if ( v11 )
  {
    while ( 1 )
    {
      v16 = v11->pNextView;
      v26 = v12;
      v25 = v11->pNextView;
      if ( v11 == this->m_listPendingXfers.m_pFirst )
        this->m_listPendingXfers.m_pFirst = v16;
      else
        v12->pNextView = v16;
      if ( v11 == this->m_listPendingXfers.m_pLast )
        this->m_listPendingXfers.m_pLast = v12;
      v17 = *((_DWORD *)v11 + 5);
      if ( (v17 & 7) != 0 )
      {
        AK::StreamMgr::CAkAutoStmBase::AddMemView(this, v11, 0);
      }
      else
      {
        m_pBlock = v11->m_pBlock;
        m_uOffsetInBlock = v11->m_uOffsetInBlock;
        *((_DWORD *)v11 + 5) = v17 & 0xFFFFFFF8 | 2;
        uPosition = m_pBlock->uPosition;
        m_uLoopEnd = this->m_uLoopEnd;
        if ( m_pBlock->uPosition + m_uOffsetInBlock >= m_uLoopEnd || uPosition + m_pBlock->uAvailableSize <= m_uLoopEnd )
          v22 = m_pBlock->uAvailableSize - m_uOffsetInBlock;
        else
          v22 = m_uLoopEnd - m_uOffsetInBlock - uPosition;
        this->m_uVirtualBufferingSize -= v22;
        v11->m_uOffsetInBlock = v11->m_pBlock->uAvailableSize;
        v23 = this->m_listCancelledXfers.m_pFirst;
        if ( v23 )
        {
          v11->pNextView = v23;
          this->m_listCancelledXfers.m_pFirst = v11;
        }
        else
        {
          this->m_listCancelledXfers.m_pFirst = v11;
          v11->pNextView = 0i64;
        }
      }
      if ( !v16 )
        break;
      v12 = v26;
      v11 = v25;
    }
  }
LABEL_25:
  v13 = this->m_listCancelledXfers.m_pFirst;
  for ( i = 1; v13; i = !v10 )
  {
    v15 = (AK::StreamMgr::CAkStmMemViewDeferred *)v13;
    v13 = v13->pNextView;
    AK::StreamMgr::CAkStmMemViewDeferred::Cancel(
      v15,
      (AK::StreamMgr::IAkIOHookDeferred *)this->m_pDevice->m_pLowLevelHook,
      i,
      v10);
  }
}

// File Line: 887
// RVA: 0xAA7C80
void __fastcall AK::StreamMgr::CAkAutoStmDeferredLinedUp::SetLoopEnd(
        AK::StreamMgr::CAkAutoStmDeferredLinedUp *this,
        unsigned int in_uLoopEnd)
{
  this->m_uLoopEnd = in_uLoopEnd;
  this->m_uVirtualBufferingSize = AK::StreamMgr::CAkAutoStmDeferredLinedUp::ComputeVirtualBuffering(this);
}

// File Line: 894
// RVA: 0xAA6A40
__int64 __fastcall AK::StreamMgr::CAkAutoStmDeferredLinedUp::ComputeVirtualBuffering(
        AK::StreamMgr::CAkAutoStmDeferredLinedUp *this)
{
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rax
  int m_uNextToGrant; // r8d
  unsigned int v3; // edx
  unsigned __int64 m_uLoopEnd; // r11
  AK::StreamMgr::AkMemBlock *m_pBlock; // r8
  __int64 m_uOffsetInBlock; // r9
  unsigned __int64 uPosition; // r10
  int v9; // ecx
  AK::StreamMgr::CAkStmMemView *v10; // rax
  unsigned __int64 v11; // r11
  AK::StreamMgr::AkMemBlock *v12; // r8
  __int64 v13; // r9
  unsigned __int64 v14; // r10
  unsigned int uAvailableSize; // ecx

  m_pFirst = this->m_listBuffers.m_pFirst;
  m_uNextToGrant = (unsigned __int8)this->m_uNextToGrant;
  v3 = 0;
  if ( m_pFirst )
  {
    while ( m_uNextToGrant )
    {
      m_pFirst = m_pFirst->pNextView;
      --m_uNextToGrant;
      if ( !m_pFirst )
        goto LABEL_11;
    }
    m_uLoopEnd = this->m_uLoopEnd;
    do
    {
      m_pBlock = m_pFirst->m_pBlock;
      m_uOffsetInBlock = m_pFirst->m_uOffsetInBlock;
      uPosition = m_pBlock->uPosition;
      if ( m_pBlock->uPosition + m_uOffsetInBlock >= m_uLoopEnd || uPosition + m_pBlock->uAvailableSize <= m_uLoopEnd )
        v9 = m_pBlock->uAvailableSize - m_uOffsetInBlock;
      else
        v9 = m_uLoopEnd - m_uOffsetInBlock - uPosition;
      m_pFirst = m_pFirst->pNextView;
      v3 += v9;
    }
    while ( m_pFirst );
  }
LABEL_11:
  v10 = this->m_listPendingXfers.m_pFirst;
  if ( v10 )
  {
    v11 = this->m_uLoopEnd;
    do
    {
      v12 = v10->m_pBlock;
      v13 = v10->m_uOffsetInBlock;
      v14 = v12->uPosition;
      if ( v12->uPosition + v13 >= v11 || v14 + v12->uAvailableSize <= v11 )
        uAvailableSize = v12->uAvailableSize;
      else
        uAvailableSize = v11 - v14;
      v10 = v10->pNextView;
      v3 += uAvailableSize - v13;
    }
    while ( v10 );
  }
  return v3;
}

