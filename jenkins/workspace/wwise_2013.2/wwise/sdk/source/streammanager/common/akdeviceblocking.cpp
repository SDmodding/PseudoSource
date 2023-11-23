// File Line: 23
// RVA: 0xAA5290
void __fastcall AK::StreamMgr::CAkDeviceBlocking::CAkDeviceBlocking(
        AK::StreamMgr::CAkDeviceBlocking *this,
        AK::StreamMgr::IAkLowLevelIOHook *in_pLowLevelHook)
{
  AK::StreamMgr::CAkDeviceBase::CAkDeviceBase(this, in_pLowLevelHook);
  this->vfptr = (AK::StreamMgr::CAkIOThreadVtbl *)&AK::StreamMgr::CAkDeviceBlocking::`vftable;
}

// File Line: 34
// RVA: 0xAA5E90
__int64 __fastcall AK::StreamMgr::CAkDeviceBlocking::Init(
        AK::StreamMgr::CAkDeviceBlocking *this,
        AkDeviceSettings *in_settings,
        unsigned int in_deviceID)
{
  AKRESULT v4; // esi
  unsigned __int64 v5; // rdi
  AK::StreamMgr::CAkStmMemView *v6; // rax
  AK::StreamMgr::CAkStmMemView *v8; // rdx
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rcx

  v4 = AK::StreamMgr::CAkDeviceBase::Init(this, in_settings, in_deviceID);
  if ( v4 == AK_Success )
  {
    v5 = this->m_mgrMemIO.m_uNumViewsAvail + 1;
    v6 = (AK::StreamMgr::CAkStmMemView *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v5 * 24);
    this->m_pStmMemViewMem = v6;
    if ( !v6 )
      return 2i64;
    v8 = &v6[v5];
    do
    {
      if ( v6 )
      {
        *((_DWORD *)v6 + 5) &= ~4u;
        *((_DWORD *)v6 + 5) |= 0xBu;
        v6->pNextView = 0i64;
        v6->m_pBlock = 0i64;
        v6->m_uOffsetInBlock = 0;
      }
      m_pFirst = this->m_poolStmMemView.m_pFirst;
      if ( m_pFirst )
      {
        v6->pNextView = m_pFirst;
        this->m_poolStmMemView.m_pFirst = v6;
      }
      else
      {
        this->m_poolStmMemView.m_pFirst = v6;
        v6->pNextView = 0i64;
      }
      ++v6;
    }
    while ( v6 < v8 );
  }
  return (unsigned int)v4;
}

// File Line: 69
// RVA: 0xAA5A20
AK::StreamMgr::CAkStdStmBase *__fastcall AK::StreamMgr::CAkDeviceBlocking::CreateStd(
        AK::StreamMgr::CAkDeviceBlocking *this,
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
  v9 = (AK::StreamMgr::CAkStdStmBase *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0xC8ui64);
  v10 = v9;
  if ( !v9 )
  {
    AK::StreamMgr::CAkStreamMgr::ForceCleanup(this, 100);
    v9 = (AK::StreamMgr::CAkStdStmBase *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0xC8ui64);
    v10 = v9;
    if ( !v9 )
      return 0i64;
  }
  AK::StreamMgr::CAkStdStmBase::CAkStdStmBase(v9);
  v10->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkStdStmBlocking::`vftable{for `AK::StreamMgr::CAkStmTask};
  LOBYTE(v10[1].m_hBlockEvent) = 0;
  v10[1].AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr = 0i64;
  v10->AK::IAkStdStream::vfptr = (AK::IAkStdStreamVtbl *)&AK::StreamMgr::CAkStdStmBlocking::`vftable{for `AK::IAkStdStream};
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

// File Line: 121
// RVA: 0xAA5660
AK::StreamMgr::CAkAutoStmBase *__fastcall AK::StreamMgr::CAkDeviceBlocking::CreateAuto(
        AK::StreamMgr::CAkDeviceBlocking *this,
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
  v11 = (AK::StreamMgr::CAkAutoStmBase *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0xD8ui64);
  v12 = v11;
  if ( !v11 )
  {
    AK::StreamMgr::CAkStreamMgr::ForceCleanup(this, in_heuristics->priority);
    v11 = (AK::StreamMgr::CAkAutoStmBase *)AK::MemoryMgr::Malloc(
                                             AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId,
                                             0xD8ui64);
    v12 = v11;
    if ( !v11 )
    {
LABEL_9:
      result = 0i64;
      goto LABEL_10;
    }
  }
  AK::StreamMgr::CAkAutoStmBase::CAkAutoStmBase(v11);
  v12->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkAutoStmBlocking::`vftable{for `AK::StreamMgr::CAkStmTask};
  LOBYTE(v12[1].m_hBlockEvent) = 0;
  v12[1].AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr = 0i64;
  v12->AK::IAkAutoStream::vfptr = (AK::IAkAutoStreamVtbl *)&AK::StreamMgr::CAkAutoStmBlocking::`vftable{for `AK::IAkAutoStream};
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

// File Line: 189
// RVA: 0xAA5FD0
void __fastcall AK::StreamMgr::CAkDeviceBlocking::PerformIO(AK::StreamMgr::CAkDeviceBlocking *this)
{
  AK::StreamMgr::CAkStmTask *NextTask; // rax
  float out_fOpDeadline; // [rsp+38h] [rbp+10h] BYREF

  NextTask = AK::StreamMgr::CAkDeviceBase::SchedulerFindNextTask(this, &out_fOpDeadline);
  if ( NextTask )
    AK::StreamMgr::CAkDeviceBlocking::ExecuteTask(this, NextTask, out_fOpDeadline);
}

// File Line: 205
// RVA: 0xAA5C00
void __fastcall AK::StreamMgr::CAkDeviceBlocking::ExecuteTask(
        AK::StreamMgr::CAkDeviceBlocking *this,
        AK::StreamMgr::CAkStmTask *in_pTask,
        float in_fOpDeadline)
{
  unsigned int IsOpen; // esi
  AK::StreamMgr::CAkClientThreadAwareVtbl *vfptr; // rax
  AK::StreamMgr::CAkStmMemView *v7; // rbp
  __int64 v8; // r9
  __int64 v9; // r8
  AK::StreamMgr::CAkStmMemView *v10; // rdx
  bool v11; // zf
  char m_priority; // al
  AK::StreamMgr::IAkLowLevelIOHook *m_pLowLevelHook; // rcx
  char v14; // di
  __int64 v15; // r9
  AK::StreamMgr::IAkLowLevelIOHookVtbl *v16; // rax
  bool v17; // di
  AKRESULT v18; // eax
  __int64 v19; // [rsp+30h] [rbp-38h] BYREF
  __int64 v20; // [rsp+38h] [rbp-30h] BYREF
  float v21; // [rsp+88h] [rbp+20h] BYREF
  char v22; // [rsp+8Ch] [rbp+24h]

  IsOpen = AK::StreamMgr::CAkStmTask::EnsureFileIsOpen(in_pTask);
  vfptr = in_pTask->vfptr;
  if ( IsOpen == 1 )
  {
    v7 = (AK::StreamMgr::CAkStmMemView *)((__int64 (__fastcall *)(AK::StreamMgr::CAkStmTask *, __int64 *, __int64 *, _QWORD))vfptr[4].__vecDelDtor)(
                                           in_pTask,
                                           &v19,
                                           &v20,
                                           0i64);
    if ( v7 )
    {
      v11 = v20 == 0;
      if ( v20 )
      {
        m_priority = in_pTask->m_priority;
        m_pLowLevelHook = this->m_pLowLevelHook;
        v21 = in_fOpDeadline;
        v14 = *((_BYTE *)in_pTask + 117);
        v22 = m_priority;
        v15 = *(_QWORD *)(v20 + 16);
        v16 = m_pLowLevelHook->vfptr;
        v17 = (v14 & 2) == 0;
        if ( v17 )
          v18 = ((unsigned int (__fastcall *)(AK::StreamMgr::IAkLowLevelIOHook *, __int64, float *, __int64, __int64))v16[1].__vecDelDtor)(
                  m_pLowLevelHook,
                  v19,
                  &v21,
                  v15,
                  v20);
        else
          v18 = ((unsigned int (__fastcall *)(AK::StreamMgr::IAkLowLevelIOHook *, __int64, float *, __int64, __int64))v16[1].Close)(
                  m_pLowLevelHook,
                  v19,
                  &v21,
                  v15,
                  v20);
        IsOpen = v18;
        AK::StreamMgr::CAkDeviceBlocking::OnLowLevelTransferComplete(this, v7, v18, v17);
        v11 = v20 == 0;
      }
      LOBYTE(v8) = !v11;
      v9 = IsOpen;
      v10 = v7;
    }
    else
    {
      v8 = 0i64;
      v9 = 53i64;
      v10 = 0i64;
    }
    ((void (__fastcall *)(AK::StreamMgr::CAkStmTask *, AK::StreamMgr::CAkStmMemView *, __int64, __int64))in_pTask->vfptr[5].__vecDelDtor)(
      in_pTask,
      v10,
      v9,
      v8);
  }
  else
  {
    ((void (__fastcall *)(AK::StreamMgr::CAkStmTask *, _QWORD, __int64))vfptr[5].__vecDelDtor)(in_pTask, 0i64, 2i64);
  }
}

// File Line: 279
// RVA: 0xAA5BB0
bool __fastcall AK::StreamMgr::CAkDeviceBlocking::ExecuteCachedTransfer(
        AK::StreamMgr::CAkDeviceBlocking *this,
        AK::StreamMgr::CAkStmTask *in_pTask,
        __int64 a3,
        __int64 a4)
{
  __int64 v5; // rax
  __int64 v6; // r9
  __int64 v8; // [rsp+38h] [rbp+10h] BYREF
  char v9; // [rsp+40h] [rbp+18h] BYREF

  LOBYTE(a4) = 1;
  v5 = ((__int64 (__fastcall *)(AK::StreamMgr::CAkStmTask *, char *, __int64 *, __int64))in_pTask->vfptr[4].__vecDelDtor)(
         in_pTask,
         &v9,
         &v8,
         a4);
  if ( v5 )
  {
    LOBYTE(v6) = v8 != 0;
    ((void (__fastcall *)(AK::StreamMgr::CAkStmTask *, __int64, __int64, __int64))in_pTask->vfptr[5].__vecDelDtor)(
      in_pTask,
      v5,
      1i64,
      v6);
    LOBYTE(v5) = 1;
  }
  return v5;
}

// File Line: 326
// RVA: 0xAA5950
AK::StreamMgr::CAkStmMemView *__fastcall AK::StreamMgr::CAkDeviceBlocking::CreateMemViewStd(
        AK::StreamMgr::CAkDeviceBlocking *this,
        AK::StreamMgr::CAkStmTask *in_pOwner,
        AK::StreamMgr::AkMemBlock *in_pMemBlock,
        unsigned int in_uDataOffset,
        unsigned __int64 in_uPosition,
        unsigned int in_uBufferSize,
        unsigned int in_uRequestedSize,
        AK::StreamMgr::CAkLowLevelTransfer **out_pLowLevelXfer)
{
  __int64 v9; // r15
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rbx
  char *v13; // rcx
  AK::StreamMgr::CAkStmMemView *result; // rax

  v9 = in_uDataOffset;
  *out_pLowLevelXfer = 0i64;
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  m_pFirst = this->m_poolStmMemView.m_pFirst;
  if ( m_pFirst )
    this->m_poolStmMemView.m_pFirst = m_pFirst->pNextView;
  LeaveCriticalSection(&this->m_lockSems.m_csLock);
  v13 = (char *)in_pMemBlock->pData + v9;
  this->m_currentTransfer.info.uFilePosition = in_uPosition
                                             + in_pOwner->m_uLLBlockSize * in_pOwner->m_pFileDesc->uSector;
  result = m_pFirst;
  this->m_currentTransfer.pAddress = v13;
  this->m_currentTransfer.info.uBufferSize = in_uBufferSize;
  this->m_currentTransfer.info.uRequestedSize = in_uRequestedSize;
  *out_pLowLevelXfer = &this->m_currentTransfer;
  in_pMemBlock->pNextBlock = (AK::StreamMgr::AkMemBlock *)&this->m_currentTransfer;
  *((_DWORD *)m_pFirst + 5) &= 0xFFFFFFF8;
  m_pFirst->m_pBlock = in_pMemBlock;
  m_pFirst->m_uOffsetInBlock = v9;
  return result;
}

// File Line: 379
// RVA: 0xAA5790
AK::StreamMgr::CAkStmMemView *__fastcall AK::StreamMgr::CAkDeviceBlocking::CreateMemViewAuto(
        AK::StreamMgr::CAkDeviceBlocking *this,
        AK::StreamMgr::CAkStmTask *in_pOwner,
        unsigned int in_fileID,
        unsigned __int64 in_uPosition,
        unsigned int in_uMinSize,
        unsigned int in_uRequiredAlign,
        bool in_bEof,
        bool in_bCacheOnly,
        unsigned int *io_uRequestedSize,
        AK::StreamMgr::CAkLowLevelTransfer **out_pLowLevelXfer)
{
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rbx
  unsigned int *v14; // r13
  unsigned int CachedBlock; // eax
  AK::StreamMgr::AkMemBlock *v16; // rdx
  unsigned int v17; // ebp
  AK::StreamMgr::AkMemBlock *v18; // rdx
  unsigned int v19; // r11d
  unsigned int m_uGranularity; // r10d
  __int64 v21; // r9
  AK::StreamMgr::CAkLowLevelTransfer **v22; // rax
  AK::StreamMgr::AkMemBlock *in_pMemBlock; // [rsp+80h] [rbp+8h] BYREF
  AK::StreamMgr::CAkStmTask *v25; // [rsp+88h] [rbp+10h]

  v25 = in_pOwner;
  m_pFirst = 0i64;
  *out_pLowLevelXfer = 0i64;
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  v14 = io_uRequestedSize;
  in_pMemBlock = 0i64;
  if ( !this->m_mgrMemIO.m_bUseCache || in_fileID == -1 )
  {
    v17 = 0;
    goto LABEL_8;
  }
  CachedBlock = AK::StreamMgr::CAkIOMemMgr::GetCachedBlock(
                  &this->m_mgrMemIO,
                  in_fileID,
                  in_uPosition,
                  in_uMinSize,
                  in_uRequiredAlign,
                  in_bEof,
                  io_uRequestedSize,
                  &in_pMemBlock);
  v16 = in_pMemBlock;
  v17 = CachedBlock;
  if ( !in_pMemBlock )
  {
LABEL_8:
    if ( in_bCacheOnly )
      goto LABEL_15;
    AK::StreamMgr::CAkIOMemMgr::GetOldestFreeBlock(&this->m_mgrMemIO, &in_pMemBlock);
    v18 = in_pMemBlock;
    if ( !in_pMemBlock )
    {
      AK::StreamMgr::CAkIOThread::NotifyMemIdle(this);
      goto LABEL_15;
    }
    v19 = *v14;
    m_uGranularity = this->m_uGranularity;
    v21 = v25->m_uLLBlockSize * v25->m_pFileDesc->uSector;
    this->m_currentTransfer.pAddress = in_pMemBlock->pData;
    v22 = out_pLowLevelXfer;
    this->m_currentTransfer.info.uFilePosition = in_uPosition + v21;
    this->m_currentTransfer.info.uBufferSize = m_uGranularity;
    this->m_currentTransfer.info.uRequestedSize = v19;
    *v22 = &this->m_currentTransfer;
    AK::StreamMgr::CAkIOMemMgr::TagBlock(
      &this->m_mgrMemIO,
      v18,
      &this->m_currentTransfer,
      in_fileID,
      in_uPosition,
      *v14);
    v16 = in_pMemBlock;
    goto LABEL_11;
  }
  if ( in_bCacheOnly && in_pMemBlock->pNextBlock )
  {
    AK::StreamMgr::CAkIOMemMgr::ReleaseBlock(&this->m_mgrMemIO, in_pMemBlock);
    goto LABEL_15;
  }
LABEL_11:
  m_pFirst = this->m_poolStmMemView.m_pFirst;
  if ( m_pFirst )
    this->m_poolStmMemView.m_pFirst = m_pFirst->pNextView;
  *((_DWORD *)m_pFirst + 5) &= 0xFFFFFFF8;
  m_pFirst->m_pBlock = v16;
  m_pFirst->m_uOffsetInBlock = v17;
LABEL_15:
  LeaveCriticalSection(&this->m_lockSems.m_csLock);
  return m_pFirst;
}

// File Line: 478
// RVA: 0xAA5B20
void __fastcall AK::StreamMgr::CAkStdStmBlocking::Destroy(AK::StreamMgr::CAkStdStmBlocking *this)
{
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock);
  *(&this[-1].m_bTransferCancelling + 5) = *(&this[-1].m_bTransferCancelling + 5) & 0xB7 | 8;
  AK::StreamMgr::CAkStdStmBase::SetStatus(
    (AK::StreamMgr::CAkStdStmBlocking *)((char *)this - 120),
    AK_StmStatusCancelled);
  if ( this->m_lockStatus.m_csLock.OwningThread )
  {
    LOBYTE(this->m_lockStatus.m_csLock.LockSemaphore) = 1;
    AK::StreamMgr::CAkClientThreadAware::SetBlockedStatus((AK::StreamMgr::CAkStdStmBlocking *)((char *)this - 120));
    LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock);
    AK::StreamMgr::CAkIOThread::WaitForIOCompletion(
      *((AK::StreamMgr::CAkIOThread **)&this[-1].AK::StreamMgr::CAkStdStmBase + 22),
      (AK::StreamMgr::CAkStdStmBlocking *)((char *)this - 120));
    LOBYTE(this->m_lockStatus.m_csLock.LockSemaphore) = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock);
}

// File Line: 510
// RVA: 0xAA5450
void __fastcall AK::StreamMgr::CAkStdStmBlocking::Cancel(AK::StreamMgr::CAkStdStmBlocking *this)
{
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock);
  AK::StreamMgr::CAkStdStmBase::SetStatus(
    (AK::StreamMgr::CAkStdStmBlocking *)((char *)this - 120),
    AK_StmStatusCancelled);
  if ( this->m_lockStatus.m_csLock.OwningThread )
  {
    LOBYTE(this->m_lockStatus.m_csLock.LockSemaphore) = 1;
    AK::StreamMgr::CAkClientThreadAware::SetBlockedStatus((AK::StreamMgr::CAkStdStmBlocking *)((char *)this - 120));
    LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock);
    AK::StreamMgr::CAkIOThread::WaitForIOCompletion(
      *((AK::StreamMgr::CAkIOThread **)&this[-1].AK::StreamMgr::CAkStdStmBase + 22),
      (AK::StreamMgr::CAkStdStmBlocking *)((char *)this - 120));
    EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock);
    LOBYTE(this->m_lockStatus.m_csLock.LockSemaphore) = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock);
}

// File Line: 538
// RVA: 0xAA5400
_BOOL8 __fastcall AK::StreamMgr::CAkStdStmBlocking::CanBeDestroyed(AK::StreamMgr::CAkStdStmBlocking *this)
{
  CAkLock *p_m_lockStatus; // rbx
  bool v3; // di

  p_m_lockStatus = &this->m_lockStatus;
  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  v3 = !this->m_pCurrentTransfer && !this->m_bTransferCancelling;
  LeaveCriticalSection(&p_m_lockStatus->m_csLock);
  return v3;
}

// File Line: 556
// RVA: 0xAA6170
AK::StreamMgr::CAkStmMemView *__fastcall AK::StreamMgr::CAkStdStmBlocking::PrepareTransfer(
        AK::StreamMgr::CAkStdStmBlocking *this,
        AkFileDesc **out_pFileDesc,
        AK::StreamMgr::CAkLowLevelTransfer **out_pLowLevelXfer,
        bool __formal)
{
  char v7; // al
  unsigned int m_uTotalScheduledSize; // r8d
  AK::StreamMgr::CAkDeviceBlocking *m_pDevice; // r11
  unsigned __int64 in_uPosition; // rdx
  unsigned int in_uBufferSize; // ecx
  unsigned __int64 iFileSize; // rsi
  unsigned int in_uRequestedSize; // esi
  AK::StreamMgr::CAkStmMemView *MemViewStd; // rax
  AK::StreamMgr::CAkStmMemView *v15; // rbp

  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  v7 = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117);
  if ( (v7 & 8) != 0 || (v7 & 0x40) == 0 )
  {
    v15 = 0i64;
  }
  else
  {
    *out_pFileDesc = this->m_pFileDesc;
    m_uTotalScheduledSize = this->m_uTotalScheduledSize;
    m_pDevice = (AK::StreamMgr::CAkDeviceBlocking *)this->m_pDevice;
    in_uPosition = this->m_memBlock.uPosition + m_uTotalScheduledSize;
    in_uBufferSize = this->m_memBlock.uAvailableSize - m_uTotalScheduledSize;
    if ( in_uBufferSize > m_pDevice->m_uGranularity )
      in_uBufferSize = m_pDevice->m_uGranularity;
    if ( (*((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) & 2) != 0
      || (iFileSize = this->m_pFileDesc->iFileSize, in_uPosition + in_uBufferSize <= iFileSize) )
    {
      in_uRequestedSize = in_uBufferSize;
    }
    else if ( in_uPosition >= iFileSize )
    {
      in_uRequestedSize = 0;
    }
    else
    {
      in_uRequestedSize = iFileSize - in_uPosition;
    }
    MemViewStd = AK::StreamMgr::CAkDeviceBlocking::CreateMemViewStd(
                   m_pDevice,
                   this,
                   &this->m_memBlock,
                   m_uTotalScheduledSize,
                   in_uPosition,
                   in_uBufferSize,
                   in_uRequestedSize,
                   out_pLowLevelXfer);
    v15 = MemViewStd;
    if ( MemViewStd )
    {
      this->m_uTotalScheduledSize += in_uRequestedSize;
      this->m_pCurrentTransfer = MemViewStd;
      this->m_iIOStartTime = this->m_pDevice->m_time;
    }
  }
  LeaveCriticalSection(&this->m_lockStatus.m_csLock);
  return v15;
}

// File Line: 613
// RVA: 0xAA6360
void __fastcall AK::StreamMgr::CAkStdStmBlocking::Update(
        AK::StreamMgr::CAkStdStmBlocking *this,
        AK::StreamMgr::CAkStmMemView *in_pTransfer,
        AKRESULT in_eIOResult,
        bool in_bRequiredLowLevelXfer)
{
  bool v7; // r8

  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  if ( in_pTransfer )
  {
    v7 = in_eIOResult == AK_Success && (*((_DWORD *)in_pTransfer + 5) & 7) != 2;
    AK::StreamMgr::CAkStdStmBase::AddMemView(this, in_pTransfer, v7);
  }
  this->m_pCurrentTransfer = 0i64;
  AK::StreamMgr::CAkStdStmBase::UpdateTaskStatus(this, in_eIOResult);
  LeaveCriticalSection(&this->m_lockStatus.m_csLock);
}

// File Line: 654
// RVA: 0xAA53B0
_BOOL8 __fastcall AK::StreamMgr::CAkAutoStmBlocking::CanBeDestroyed(AK::StreamMgr::CAkAutoStmBlocking *this)
{
  CAkLock *p_m_lockStatus; // rbx
  bool v3; // di

  p_m_lockStatus = &this->m_lockStatus;
  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  v3 = !this->m_pCurrentTransfer && !this->m_bTransferCancelled;
  LeaveCriticalSection(&p_m_lockStatus->m_csLock);
  return v3;
}

// File Line: 669
// RVA: 0xAA6000
AK::StreamMgr::CAkStmMemView *__fastcall AK::StreamMgr::CAkAutoStmBlocking::PrepareTransfer(
        AK::StreamMgr::CAkAutoStmBlocking *this,
        AkFileDesc **out_pFileDesc,
        AK::StreamMgr::CAkLowLevelTransfer **out_pLowLevelXfer,
        bool in_bCacheOnly)
{
  char v7; // al
  unsigned __int64 m_uLoopStart; // rsi
  unsigned __int64 m_uLoopEnd; // rax
  __int64 in_uMinSize; // rcx
  unsigned __int64 iFileSize; // rdx
  bool in_bEof; // r8
  unsigned int m_uMinBufferSize; // eax
  AK::StreamMgr::CAkStmMemView *v14; // rax
  AK::StreamMgr::CAkStmMemView *v15; // rbp
  unsigned __int64 v16; // rdx
  unsigned int v17; // ecx
  unsigned int io_uRequestedSize; // [rsp+70h] [rbp+8h] BYREF

  *out_pFileDesc = this->m_pFileDesc;
  *out_pLowLevelXfer = 0i64;
  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  v7 = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117);
  if ( (v7 & 8) != 0 || (v7 & 0x40) == 0 || this->m_pCurrentTransfer )
    goto LABEL_20;
  m_uLoopStart = ((__int64 (__fastcall *)(AK::StreamMgr::CAkAutoStmBlocking *))this->AK::StreamMgr::CAkAutoStmBase::AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr[7].__vecDelDtor)(this);
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
  v14 = AK::StreamMgr::CAkDeviceBlocking::CreateMemViewAuto(
          (AK::StreamMgr::CAkDeviceBlocking *)this->m_pDevice,
          this,
          this->m_fileID,
          m_uLoopStart,
          in_uMinSize,
          this->m_uBufferAlignment,
          in_bEof,
          in_bCacheOnly,
          &io_uRequestedSize,
          out_pLowLevelXfer);
  v15 = v14;
  if ( !v14 )
  {
LABEL_20:
    v15 = 0i64;
  }
  else
  {
    v16 = this->m_uLoopEnd;
    this->m_pCurrentTransfer = v14;
    if ( m_uLoopStart >= v16 )
    {
      v17 = io_uRequestedSize;
    }
    else
    {
      v17 = io_uRequestedSize;
      if ( m_uLoopStart + io_uRequestedSize > v16 )
      {
        v17 = v16 - m_uLoopStart;
        io_uRequestedSize = v16 - m_uLoopStart;
      }
    }
    this->m_uVirtualBufferingSize += v17;
    AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus(this);
    this->m_iIOStartTime = this->m_pDevice->m_time;
  }
  LeaveCriticalSection(&this->m_lockStatus.m_csLock);
  return v15;
}

// File Line: 726
// RVA: 0xAA62A0
void __fastcall AK::StreamMgr::CAkAutoStmBlocking::Update(
        AK::StreamMgr::CAkAutoStmBlocking *this,
        AK::StreamMgr::CAkStmMemView *in_pTransfer,
        AKRESULT in_eIOResult,
        bool in_bRequiredLowLevelXfer)
{
  bool v8; // r8

  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  if ( in_pTransfer )
  {
    v8 = in_eIOResult == AK_Success && this->m_pCurrentTransfer && (*((_DWORD *)in_pTransfer + 5) & 7) != 2;
    if ( !in_bRequiredLowLevelXfer && v8 )
    {
      *((_DWORD *)in_pTransfer + 5) &= ~4u;
      *((_DWORD *)in_pTransfer + 5) |= 3u;
    }
    AK::StreamMgr::CAkAutoStmBase::AddMemView(this, in_pTransfer, v8);
  }
  this->m_pCurrentTransfer = 0i64;
  this->m_bTransferCancelled = 0;
  AK::StreamMgr::CAkAutoStmBase::UpdateTaskStatus(this, in_eIOResult);
  LeaveCriticalSection(&this->m_lockStatus.m_csLock);
}

// File Line: 759
// RVA: 0xAA5E50
unsigned __int64 __fastcall AK::StreamMgr::CAkAutoStmBlocking::GetVirtualFilePosition(
        AK::StreamMgr::CAkAutoStmBlocking *this)
{
  AK::StreamMgr::CAkStmMemView *m_pCurrentTransfer; // rax

  m_pCurrentTransfer = this->m_pCurrentTransfer;
  if ( m_pCurrentTransfer )
    return m_pCurrentTransfer->m_pBlock->uPosition + m_pCurrentTransfer->m_pBlock->uAvailableSize;
  if ( this->m_listBuffers.m_ulNumListItems > (unsigned __int8)this->m_uNextToGrant )
  {
    m_pCurrentTransfer = this->m_listBuffers.m_pLast;
    return m_pCurrentTransfer->m_pBlock->uPosition + m_pCurrentTransfer->m_pBlock->uAvailableSize;
  }
  return this->m_uNextExpectedUserPosition;
}

// File Line: 771
// RVA: 0xAA54D0
void __fastcall AK::StreamMgr::CAkAutoStmBlocking::CancelAllPendingTransfers(AK::StreamMgr::CAkAutoStmBlocking *this)
{
  if ( this->m_pCurrentTransfer )
    AK::StreamMgr::CAkAutoStmBlocking::CancelCurrentTransfer(this);
}

// File Line: 781
// RVA: 0xAA5550
void __fastcall AK::StreamMgr::CAkAutoStmBlocking::CancelInconsistentPendingTransfers(
        AK::StreamMgr::CAkAutoStmBlocking *this,
        unsigned __int64 in_uNextExpectedPosition)
{
  AK::StreamMgr::CAkStmMemView *m_pCurrentTransfer; // rax

  m_pCurrentTransfer = this->m_pCurrentTransfer;
  if ( m_pCurrentTransfer )
  {
    if ( m_pCurrentTransfer->m_pBlock->uPosition + m_pCurrentTransfer->m_uOffsetInBlock != in_uNextExpectedPosition )
      AK::StreamMgr::CAkAutoStmBlocking::CancelCurrentTransfer(this);
  }
}

// File Line: 792
// RVA: 0xAA5D10
void __fastcall AK::StreamMgr::CAkAutoStmBlocking::FlushSmallBuffersAndPendingTransfers(
        AK::StreamMgr::CAkAutoStmBlocking *this,
        unsigned int in_uMinBufferSize)
{
  __int64 m_uNextToGrant; // rax
  char v3; // bp
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rbx
  AK::StreamMgr::CAkStmMemView *v7; // rsi
  AK::StreamMgr::CAkDeviceBase *m_pDevice; // r15
  AK::StreamMgr::CAkStmMemView *pNextView; // rax
  AK::StreamMgr::CAkStmMemView *m_pCurrentTransfer; // rdx
  AK::StreamMgr::CAkStmMemView *v11; // [rsp+20h] [rbp-38h]

  m_uNextToGrant = (unsigned __int8)this->m_uNextToGrant;
  v3 = 0;
  if ( this->m_listBuffers.m_ulNumListItems > (unsigned int)m_uNextToGrant )
  {
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
    m_pDevice = this->m_pDevice;
    EnterCriticalSection(&m_pDevice->m_lockSems.m_csLock);
    if ( m_pFirst )
    {
      do
      {
        if ( v3 || m_pFirst->m_pBlock->uAvailableSize - m_pFirst->m_uOffsetInBlock < in_uMinBufferSize )
        {
          pNextView = m_pFirst->pNextView;
          v3 = 1;
          v11 = m_pFirst->pNextView;
          if ( m_pFirst == this->m_listBuffers.m_pFirst )
            this->m_listBuffers.m_pFirst = pNextView;
          else
            v7->pNextView = pNextView;
          if ( m_pFirst == this->m_listBuffers.m_pLast )
            this->m_listBuffers.m_pLast = v7;
          --this->m_listBuffers.m_ulNumListItems;
          AK::StreamMgr::CAkAutoStmBase::DestroyBuffer(this, m_pFirst);
          m_pFirst = v11;
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
    LeaveCriticalSection(&m_pDevice->m_lockSems.m_csLock);
  }
  m_pCurrentTransfer = this->m_pCurrentTransfer;
  if ( m_pCurrentTransfer
    && (v3 || m_pCurrentTransfer->m_pBlock->uAvailableSize - m_pCurrentTransfer->m_uOffsetInBlock < in_uMinBufferSize) )
  {
    AK::StreamMgr::CAkAutoStmBlocking::CancelCurrentTransfer(this);
  }
}

// File Line: 844
// RVA: 0xAA6280
void __fastcall AK::StreamMgr::CAkAutoStmBlocking::SetLoopEnd(
        AK::StreamMgr::CAkAutoStmBlocking *this,
        unsigned int in_uLoopEnd)
{
  this->m_uLoopEnd = in_uLoopEnd;
  this->m_uVirtualBufferingSize = AK::StreamMgr::CAkAutoStmBlocking::ComputeVirtualBuffering(this);
}

// File Line: 851
// RVA: 0xAA5580
__int64 __fastcall AK::StreamMgr::CAkAutoStmBlocking::ComputeVirtualBuffering(AK::StreamMgr::CAkAutoStmBlocking *this)
{
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rax
  int m_uNextToGrant; // edx
  unsigned int v3; // r8d
  unsigned __int64 m_uLoopEnd; // r11
  AK::StreamMgr::AkMemBlock *m_pBlock; // rdx
  __int64 m_uOffsetInBlock; // r9
  unsigned __int64 uPosition; // r10
  unsigned int uAvailableSize; // ecx
  AK::StreamMgr::CAkStmMemView *m_pCurrentTransfer; // rdx
  __int64 v11; // r9
  AK::StreamMgr::AkMemBlock *v12; // rdx
  unsigned __int64 v13; // rcx
  unsigned __int64 v14; // r10

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
        uAvailableSize = m_pBlock->uAvailableSize;
      else
        uAvailableSize = m_uLoopEnd - uPosition;
      m_pFirst = m_pFirst->pNextView;
      v3 += uAvailableSize - m_uOffsetInBlock;
    }
    while ( m_pFirst );
  }
LABEL_11:
  m_pCurrentTransfer = this->m_pCurrentTransfer;
  if ( !m_pCurrentTransfer )
    return v3;
  v11 = m_pCurrentTransfer->m_uOffsetInBlock;
  v12 = m_pCurrentTransfer->m_pBlock;
  v13 = this->m_uLoopEnd;
  v14 = v12->uPosition;
  if ( v12->uPosition + v11 >= v13 || v14 + v12->uAvailableSize <= v13 )
    return v12->uAvailableSize - (_DWORD)v11 + v3;
  else
    return (_DWORD)v13 - (_DWORD)v14 - (_DWORD)v11 + v3;
}

// File Line: 877
// RVA: 0xAA54E0
void __fastcall AK::StreamMgr::CAkAutoStmBlocking::CancelCurrentTransfer(AK::StreamMgr::CAkAutoStmBlocking *this)
{
  AK::StreamMgr::CAkStmMemView *m_pCurrentTransfer; // rax
  AK::StreamMgr::CAkStmMemView *v3; // r9
  AK::StreamMgr::AkMemBlock *m_pBlock; // rcx
  __int64 m_uOffsetInBlock; // r10
  unsigned __int64 m_uLoopEnd; // rdx
  unsigned __int64 uPosition; // r11
  unsigned int uAvailableSize; // edx

  m_pCurrentTransfer = this->m_pCurrentTransfer;
  *((_DWORD *)m_pCurrentTransfer + 5) &= 0xFFFFFFFA;
  *((_DWORD *)m_pCurrentTransfer + 5) |= 2u;
  v3 = this->m_pCurrentTransfer;
  m_pBlock = v3->m_pBlock;
  m_uOffsetInBlock = v3->m_uOffsetInBlock;
  m_uLoopEnd = this->m_uLoopEnd;
  uPosition = m_pBlock->uPosition;
  if ( m_pBlock->uPosition + m_uOffsetInBlock >= m_uLoopEnd || uPosition + m_pBlock->uAvailableSize <= m_uLoopEnd )
    uAvailableSize = m_pBlock->uAvailableSize;
  else
    uAvailableSize = m_uLoopEnd - uPosition;
  this->m_uVirtualBufferingSize -= uAvailableSize - m_uOffsetInBlock;
  v3->m_uOffsetInBlock = v3->m_pBlock->uAvailableSize;
  this->m_pCurrentTransfer = 0i64;
  this->m_bTransferCancelled = 1;
}

