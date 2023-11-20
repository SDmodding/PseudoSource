// File Line: 23
// RVA: 0xAA5290
void __fastcall AK::StreamMgr::CAkDeviceBlocking::CAkDeviceBlocking(AK::StreamMgr::CAkDeviceBlocking *this, AK::StreamMgr::IAkLowLevelIOHook *in_pLowLevelHook)
{
  AK::StreamMgr::CAkDeviceBlocking *v2; // rbx

  v2 = this;
  AK::StreamMgr::CAkDeviceBase::CAkDeviceBase((AK::StreamMgr::CAkDeviceBase *)&this->vfptr, in_pLowLevelHook);
  v2->vfptr = (AK::StreamMgr::CAkIOThreadVtbl *)&AK::StreamMgr::CAkDeviceBlocking::`vftable';
}

// File Line: 34
// RVA: 0xAA5E90
signed __int64 __fastcall AK::StreamMgr::CAkDeviceBlocking::Init(AK::StreamMgr::CAkDeviceBlocking *this, AkDeviceSettings *in_settings, unsigned int in_deviceID)
{
  AK::StreamMgr::CAkDeviceBlocking *v3; // rbx
  AKRESULT v4; // esi
  unsigned __int64 v5; // rdi
  AK::StreamMgr::CAkStmMemView *v6; // rax
  AK::StreamMgr::CAkStmMemView *v8; // rdx
  AK::StreamMgr::CAkStmMemView *v9; // rcx

  v3 = this;
  v4 = AK::StreamMgr::CAkDeviceBase::Init((AK::StreamMgr::CAkDeviceBase *)&this->vfptr, in_settings, in_deviceID);
  if ( v4 == 1 )
  {
    v5 = v3->m_mgrMemIO.m_uNumViewsAvail + 1;
    v6 = (AK::StreamMgr::CAkStmMemView *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v5 * 24);
    v3->m_pStmMemViewMem = v6;
    if ( !v6 )
      return 2i64;
    v8 = &v6[v5];
    do
    {
      if ( v6 )
      {
        *((_DWORD *)v6 + 5) &= 0xFFFFFFFB;
        *((_DWORD *)v6 + 5) |= 0xBu;
        v6->pNextView = 0i64;
        v6->m_pBlock = 0i64;
        v6->m_uOffsetInBlock = 0;
      }
      v9 = v3->m_poolStmMemView.m_pFirst;
      if ( v9 )
      {
        v6->pNextView = v9;
        v3->m_poolStmMemView.m_pFirst = v6;
      }
      else
      {
        v3->m_poolStmMemView.m_pFirst = v6;
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
AK::StreamMgr::CAkStdStmBase *__fastcall AK::StreamMgr::CAkDeviceBlocking::CreateStd(AK::StreamMgr::CAkDeviceBlocking *this, AkFileDesc *in_pFileDesc, AkOpenMode in_eOpenMode, AK::IAkStdStream **out_pStream)
{
  AK::StreamMgr::CAkDeviceBlocking *v4; // rsi
  AkFileDesc *v5; // r15
  signed __int64 v6; // rbx
  AK::IAkStdStream **v7; // r14
  AkOpenMode v8; // ebp
  AK::StreamMgr::CAkStdStmBase *v9; // rax
  AK::StreamMgr::CAkStdStmBase *v10; // rdi
  int v12; // ebx

  v4 = this;
  v5 = in_pFileDesc;
  v6 = 0i64;
  *out_pStream = 0i64;
  v7 = out_pStream;
  v8 = in_eOpenMode;
  v9 = (AK::StreamMgr::CAkStdStmBase *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0xC8ui64);
  v10 = v9;
  if ( !v9 )
  {
    AK::StreamMgr::CAkStreamMgr::ForceCleanup((AK::StreamMgr::CAkDeviceBase *)&v4->vfptr, 100);
    v9 = (AK::StreamMgr::CAkStdStmBase *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0xC8ui64);
    v10 = v9;
    if ( !v9 )
      return 0i64;
  }
  AK::StreamMgr::CAkStdStmBase::CAkStdStmBase(v9);
  v10->vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkStdStmBlocking::`vftable'{for `AK::StreamMgr::CAkStmTask'};
  LOBYTE(v10[1].m_hBlockEvent) = 0;
  v10[1].vfptr = 0i64;
  v10->vfptr = (AK::IAkStdStreamVtbl *)&AK::StreamMgr::CAkStdStmBlocking::`vftable'{for `AK::IAkStdStream'};
  if ( (unsigned int)AK::StreamMgr::CAkStdStmBase::Init(
                       v10,
                       (AK::StreamMgr::CAkDeviceBase *)&v4->vfptr,
                       v5,
                       (unsigned int)v8) != 1 )
  {
    if ( v10 )
    {
      v12 = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
      v10->vfptr->__vecDelDtor((AK::StreamMgr::CAkClientThreadAware *)&v10->vfptr, 0);
      AK::MemoryMgr::Free(v12, v10);
    }
    return 0i64;
  }
  AK::StreamMgr::CAkDeviceBase::AddTask(
    (AK::StreamMgr::CAkDeviceBase *)&v4->vfptr,
    (AK::StreamMgr::CAkStmTask *)&v10->vfptr);
  if ( v10 )
    v6 = (signed __int64)&v10->vfptr;
  *v7 = (AK::IAkStdStream *)v6;
  return v10;
}

// File Line: 121
// RVA: 0xAA5660
AK::StreamMgr::CAkAutoStmBase *__fastcall AK::StreamMgr::CAkDeviceBlocking::CreateAuto(AK::StreamMgr::CAkDeviceBlocking *this, AkFileDesc *in_pFileDesc, unsigned int in_fileID, AkAutoStmHeuristics *in_heuristics, AkAutoStmBufSettings *in_pBufferSettings, AK::IAkAutoStream **out_pStream)
{
  AK::StreamMgr::CAkDeviceBlocking *v6; // rbx
  AkFileDesc *v7; // r12
  AK::IAkAutoStream *v8; // rsi
  AkAutoStmHeuristics *v9; // rbp
  unsigned int v10; // er15
  AK::StreamMgr::CAkAutoStmBase *v11; // rax
  AK::StreamMgr::CAkAutoStmBase *v12; // rdi
  AK::StreamMgr::CAkAutoStmBase *result; // rax
  int v14; // ebx

  v6 = this;
  v7 = in_pFileDesc;
  v8 = 0i64;
  v9 = in_heuristics;
  *out_pStream = 0i64;
  v10 = in_fileID;
  v11 = (AK::StreamMgr::CAkAutoStmBase *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0xD8ui64);
  v12 = v11;
  if ( !v11 )
  {
    AK::StreamMgr::CAkStreamMgr::ForceCleanup((AK::StreamMgr::CAkDeviceBase *)&v6->vfptr, v9->priority);
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
  v12->vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkAutoStmBlocking::`vftable'{for `AK::StreamMgr::CAkStmTask'};
  LOBYTE(v12[1].m_hBlockEvent) = 0;
  v12[1].vfptr = 0i64;
  v12->vfptr = (AK::IAkAutoStreamVtbl *)&AK::StreamMgr::CAkAutoStmBlocking::`vftable'{for `AK::IAkAutoStream'};
  if ( AK::StreamMgr::CAkAutoStmBase::Init(
         v12,
         (AK::StreamMgr::CAkDeviceBase *)&v6->vfptr,
         v7,
         v10,
         v9,
         in_pBufferSettings,
         v6->m_uGranularity) != 1 )
  {
    if ( v12 )
    {
      v14 = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
      v12->vfptr->__vecDelDtor((AK::StreamMgr::CAkClientThreadAware *)&v12->vfptr, 0);
      AK::MemoryMgr::Free(v14, v12);
    }
    goto LABEL_9;
  }
  AK::StreamMgr::CAkDeviceBase::AddTask(
    (AK::StreamMgr::CAkDeviceBase *)&v6->vfptr,
    (AK::StreamMgr::CAkStmTask *)&v12->vfptr);
  if ( v12 )
    v8 = (AK::IAkAutoStream *)&v12->vfptr;
  result = v12;
LABEL_10:
  *out_pStream = v8;
  return result;
}

// File Line: 189
// RVA: 0xAA5FD0
void __usercall AK::StreamMgr::CAkDeviceBlocking::PerformIO(AK::StreamMgr::CAkDeviceBlocking *this@<rcx>, float a2@<xmm0>)
{
  AK::StreamMgr::CAkDeviceBlocking *v2; // rbx
  AK::StreamMgr::CAkStmTask *v3; // rax
  float out_fOpDeadline; // [rsp+38h] [rbp+10h]

  v2 = this;
  v3 = AK::StreamMgr::CAkDeviceBase::SchedulerFindNextTask(
         (AK::StreamMgr::CAkDeviceBase *)&this->vfptr,
         &out_fOpDeadline,
         a2);
  if ( v3 )
    AK::StreamMgr::CAkDeviceBlocking::ExecuteTask(v2, v3, out_fOpDeadline);
}

// File Line: 205
// RVA: 0xAA5C00
void __fastcall AK::StreamMgr::CAkDeviceBlocking::ExecuteTask(AK::StreamMgr::CAkDeviceBlocking *this, AK::StreamMgr::CAkStmTask *in_pTask, float in_fOpDeadline)
{
  AK::StreamMgr::CAkDeviceBlocking *v3; // r14
  AK::StreamMgr::CAkStmTask *v4; // rbx
  AKRESULT v5; // eax
  AKRESULT v6; // esi
  AK::StreamMgr::CAkClientThreadAwareVtbl *v7; // rax
  AK::StreamMgr::CAkStmMemView *v8; // rbp
  __int64 v9; // r9
  signed __int64 v10; // r8
  AK::StreamMgr::CAkStmMemView *v11; // rdx
  bool v12; // zf
  char v13; // al
  AK::StreamMgr::IAkLowLevelIOHook *v14; // rcx
  unsigned __int8 v15; // di
  __int64 v16; // r9
  AK::StreamMgr::IAkLowLevelIOHookVtbl *v17; // rax
  bool v18; // di
  AKRESULT v19; // eax
  __int64 v20; // [rsp+30h] [rbp-38h]
  __int64 v21; // [rsp+38h] [rbp-30h]
  float v22; // [rsp+88h] [rbp+20h]
  char v23; // [rsp+8Ch] [rbp+24h]

  v3 = this;
  v4 = in_pTask;
  v5 = (unsigned int)AK::StreamMgr::CAkStmTask::EnsureFileIsOpen(in_pTask);
  v6 = v5;
  v12 = v5 == 1;
  v7 = v4->vfptr;
  if ( v12 )
  {
    v8 = (AK::StreamMgr::CAkStmMemView *)((__int64 (__fastcall *)(AK::StreamMgr::CAkStmTask *, __int64 *, __int64 *, _QWORD))v7[4].__vecDelDtor)(
                                           v4,
                                           &v20,
                                           &v21,
                                           0i64);
    if ( v8 )
    {
      v12 = v21 == 0;
      if ( v21 )
      {
        v13 = v4->m_priority;
        v14 = v3->m_pLowLevelHook;
        v22 = in_fOpDeadline;
        v15 = *((_BYTE *)v4 + 117);
        v23 = v13;
        v16 = *(_QWORD *)(v21 + 16);
        v17 = v14->vfptr;
        v18 = ~(v15 >> 1) & 1;
        if ( v18 )
          v19 = ((unsigned int (__fastcall *)(AK::StreamMgr::IAkLowLevelIOHook *, __int64, float *, __int64, __int64))v17[1].__vecDelDtor)(
                  v14,
                  v20,
                  &v22,
                  v16,
                  v21);
        else
          v19 = ((unsigned int (__fastcall *)(AK::StreamMgr::IAkLowLevelIOHook *, __int64, float *, __int64, __int64))v17[1].Close)(
                  v14,
                  v20,
                  &v22,
                  v16,
                  v21);
        v6 = v19;
        AK::StreamMgr::CAkDeviceBlocking::OnLowLevelTransferComplete(v3, v8, v19, v18);
        v12 = v21 == 0;
      }
      LOBYTE(v9) = !v12;
      v10 = (unsigned int)v6;
      v11 = v8;
    }
    else
    {
      v9 = 0i64;
      v10 = 53i64;
      v11 = 0i64;
    }
    ((void (__fastcall *)(AK::StreamMgr::CAkStmTask *, AK::StreamMgr::CAkStmMemView *, signed __int64, __int64))v4->vfptr[5].__vecDelDtor)(
      v4,
      v11,
      v10,
      v9);
  }
  else
  {
    ((void (__fastcall *)(AK::StreamMgr::CAkStmTask *, _QWORD, signed __int64))v7[5].__vecDelDtor)(v4, 0i64, 2i64);
  }
}

// File Line: 279
// RVA: 0xAA5BB0
bool __fastcall AK::StreamMgr::CAkDeviceBlocking::ExecuteCachedTransfer(AK::StreamMgr::CAkDeviceBlocking *this, AK::StreamMgr::CAkStmTask *in_pTask, __int64 a3, __int64 a4)
{
  AK::StreamMgr::CAkStmTask *v4; // rbx
  __int64 v5; // rax
  __int64 v6; // r9
  __int64 v8; // [rsp+38h] [rbp+10h]
  char v9; // [rsp+40h] [rbp+18h]

  v4 = in_pTask;
  LOBYTE(a4) = 1;
  v5 = ((__int64 (__fastcall *)(AK::StreamMgr::CAkStmTask *, char *, __int64 *, __int64))in_pTask->vfptr[4].__vecDelDtor)(
         in_pTask,
         &v9,
         &v8,
         a4);
  if ( v5 )
  {
    LOBYTE(v6) = v8 != 0;
    ((void (__fastcall *)(AK::StreamMgr::CAkStmTask *, __int64, signed __int64, __int64))v4->vfptr[5].__vecDelDtor)(
      v4,
      v5,
      1i64,
      v6);
    LOBYTE(v5) = 1;
  }
  return v5;
}

// File Line: 326
// RVA: 0xAA5950
AK::StreamMgr::CAkStmMemView *__fastcall AK::StreamMgr::CAkDeviceBlocking::CreateMemViewStd(AK::StreamMgr::CAkDeviceBlocking *this, AK::StreamMgr::CAkStmTask *in_pOwner, AK::StreamMgr::AkMemBlock *in_pMemBlock, unsigned int in_uDataOffset, unsigned __int64 in_uPosition, unsigned int in_uBufferSize, unsigned int in_uRequestedSize, AK::StreamMgr::CAkLowLevelTransfer **out_pLowLevelXfer)
{
  AK::StreamMgr::CAkDeviceBlocking *v8; // rdi
  __int64 v9; // r15
  AK::StreamMgr::AkMemBlock *v10; // rsi
  AK::StreamMgr::CAkStmTask *v11; // r13
  AK::StreamMgr::CAkStmMemView *v12; // rbx
  signed __int64 v13; // r8
  char *v14; // rcx
  AK::StreamMgr::CAkStmMemView *result; // rax

  v8 = this;
  v9 = in_uDataOffset;
  v10 = in_pMemBlock;
  v11 = in_pOwner;
  *out_pLowLevelXfer = 0i64;
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  v12 = v8->m_poolStmMemView.m_pFirst;
  if ( v12 )
    v8->m_poolStmMemView.m_pFirst = v12->pNextView;
  LeaveCriticalSection(&v8->m_lockSems.m_csLock);
  v13 = (signed __int64)&v8->m_currentTransfer;
  v14 = (char *)v10->pData + v9;
  *(_QWORD *)v13 = in_uPosition + v11->m_uLLBlockSize * v11->m_pFileDesc->uSector;
  result = v12;
  *(_QWORD *)(v13 + 16) = v14;
  *(_DWORD *)(v13 + 8) = in_uBufferSize;
  *(_DWORD *)(v13 + 12) = in_uRequestedSize;
  *out_pLowLevelXfer = (AK::StreamMgr::CAkLowLevelTransfer *)&v8->m_currentTransfer;
  v10->pNextBlock = (AK::StreamMgr::AkMemBlock *)&v8->m_currentTransfer;
  *((_DWORD *)v12 + 5) &= 0xFFFFFFF8;
  v12->m_pBlock = v10;
  v12->m_uOffsetInBlock = v9;
  return result;
}

// File Line: 379
// RVA: 0xAA5790
AK::StreamMgr::CAkStmMemView *__fastcall AK::StreamMgr::CAkDeviceBlocking::CreateMemViewAuto(AK::StreamMgr::CAkDeviceBlocking *this, AK::StreamMgr::CAkStmTask *in_pOwner, unsigned int in_fileID, unsigned __int64 in_uPosition, unsigned int in_uMinSize, unsigned int in_uRequiredAlign, bool in_bEof, bool in_bCacheOnly, unsigned int *io_uRequestedSize, AK::StreamMgr::CAkLowLevelTransfer **out_pLowLevelXfer)
{
  AK::StreamMgr::CAkDeviceBlocking *v10; // rdi
  AK::StreamMgr::CAkStmMemView *v11; // rbx
  unsigned __int64 v12; // r12
  unsigned int v13; // esi
  unsigned int *v14; // r13
  unsigned int v15; // eax
  AK::StreamMgr::AkMemBlock *v16; // rdx
  unsigned int v17; // ebp
  AK::StreamMgr::AkMemBlock *v18; // rdx
  unsigned int v19; // er11
  unsigned int v20; // er10
  __int64 v21; // r9
  signed __int64 v22; // r8
  AK::StreamMgr::CAkLowLevelTransfer **v23; // rax
  AK::StreamMgr::AkMemBlock *in_pMemBlock; // [rsp+80h] [rbp+8h]
  AK::StreamMgr::CAkStmTask *v26; // [rsp+88h] [rbp+10h]

  v26 = in_pOwner;
  v10 = this;
  v11 = 0i64;
  v12 = in_uPosition;
  v13 = in_fileID;
  *out_pLowLevelXfer = 0i64;
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  v14 = io_uRequestedSize;
  in_pMemBlock = 0i64;
  if ( !v10->m_mgrMemIO.m_bUseCache || v13 == -1 )
  {
    v17 = 0;
    goto LABEL_8;
  }
  v15 = AK::StreamMgr::CAkIOMemMgr::GetCachedBlock(
          &v10->m_mgrMemIO,
          v13,
          v12,
          in_uMinSize,
          in_uRequiredAlign,
          in_bEof,
          io_uRequestedSize,
          &in_pMemBlock);
  v16 = in_pMemBlock;
  v17 = v15;
  if ( !in_pMemBlock )
  {
LABEL_8:
    if ( in_bCacheOnly )
      goto LABEL_15;
    AK::StreamMgr::CAkIOMemMgr::GetOldestFreeBlock(&v10->m_mgrMemIO, &in_pMemBlock);
    v18 = in_pMemBlock;
    if ( !in_pMemBlock )
    {
      AK::StreamMgr::CAkIOThread::NotifyMemIdle((AK::StreamMgr::CAkIOThread *)&v10->vfptr);
      goto LABEL_15;
    }
    v19 = *v14;
    v20 = v10->m_uGranularity;
    v21 = v26->m_uLLBlockSize * v26->m_pFileDesc->uSector;
    v22 = (signed __int64)&v10->m_currentTransfer;
    *(_QWORD *)(v22 + 16) = in_pMemBlock->pData;
    v23 = out_pLowLevelXfer;
    *(_QWORD *)v22 = v12 + v21;
    *(_DWORD *)(v22 + 8) = v20;
    *(_DWORD *)(v22 + 12) = v19;
    *v23 = (AK::StreamMgr::CAkLowLevelTransfer *)&v10->m_currentTransfer;
    AK::StreamMgr::CAkIOMemMgr::TagBlock(
      &v10->m_mgrMemIO,
      v18,
      (AK::StreamMgr::CAkLowLevelTransfer *)&v10->m_currentTransfer,
      v13,
      v12,
      *v14);
    v16 = in_pMemBlock;
    goto LABEL_11;
  }
  if ( in_bCacheOnly && in_pMemBlock->pNextBlock )
  {
    AK::StreamMgr::CAkIOMemMgr::ReleaseBlock(&v10->m_mgrMemIO, in_pMemBlock);
    goto LABEL_15;
  }
LABEL_11:
  v11 = v10->m_poolStmMemView.m_pFirst;
  if ( v11 )
    v10->m_poolStmMemView.m_pFirst = v11->pNextView;
  *((_DWORD *)v11 + 5) &= 0xFFFFFFF8;
  v11->m_pBlock = v16;
  v11->m_uOffsetInBlock = v17;
LABEL_15:
  LeaveCriticalSection(&v10->m_lockSems.m_csLock);
  return v11;
}

// File Line: 478
// RVA: 0xAA5B20
void __fastcall AK::StreamMgr::CAkStdStmBlocking::Destroy(AK::StreamMgr::CAkStdStmBlocking *this)
{
  AK::StreamMgr::CAkStdStmBlocking *v1; // rbx

  v1 = this;
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock);
  *(&v1[-1].m_bTransferCancelling + 5) = *(&v1[-1].m_bTransferCancelling + 5) & 0xBF | 8;
  AK::StreamMgr::CAkStdStmBase::SetStatus(
    (AK::StreamMgr::CAkStdStmBase *)&v1[-1].m_lockStatus.m_csLock.SpinCount,
    AK_StmStatusCancelled);
  if ( v1->m_lockStatus.m_csLock.OwningThread )
  {
    LOBYTE(v1->m_lockStatus.m_csLock.LockSemaphore) = 1;
    AK::StreamMgr::CAkClientThreadAware::SetBlockedStatus((AK::StreamMgr::CAkClientThreadAware *)&v1[-1].m_lockStatus.m_csLock.SpinCount);
    LeaveCriticalSection((LPCRITICAL_SECTION)&v1[-1].m_memBlock);
    AK::StreamMgr::CAkIOThread::WaitForIOCompletion(
      *((AK::StreamMgr::CAkIOThread **)&v1[-1].0 + 22),
      (AK::StreamMgr::CAkClientThreadAware *)&v1[-1].m_lockStatus.m_csLock.SpinCount);
    LOBYTE(v1->m_lockStatus.m_csLock.LockSemaphore) = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)&v1[-1].m_memBlock);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&v1[-1].m_memBlock);
}

// File Line: 510
// RVA: 0xAA5450
void __fastcall AK::StreamMgr::CAkStdStmBlocking::Cancel(AK::StreamMgr::CAkStdStmBlocking *this)
{
  AK::StreamMgr::CAkStdStmBlocking *v1; // rbx

  v1 = this;
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock);
  AK::StreamMgr::CAkStdStmBase::SetStatus(
    (AK::StreamMgr::CAkStdStmBase *)&v1[-1].m_lockStatus.m_csLock.SpinCount,
    AK_StmStatusCancelled);
  if ( v1->m_lockStatus.m_csLock.OwningThread )
  {
    LOBYTE(v1->m_lockStatus.m_csLock.LockSemaphore) = 1;
    AK::StreamMgr::CAkClientThreadAware::SetBlockedStatus((AK::StreamMgr::CAkClientThreadAware *)&v1[-1].m_lockStatus.m_csLock.SpinCount);
    LeaveCriticalSection((LPCRITICAL_SECTION)&v1[-1].m_memBlock);
    AK::StreamMgr::CAkIOThread::WaitForIOCompletion(
      *((AK::StreamMgr::CAkIOThread **)&v1[-1].0 + 22),
      (AK::StreamMgr::CAkClientThreadAware *)&v1[-1].m_lockStatus.m_csLock.SpinCount);
    EnterCriticalSection((LPCRITICAL_SECTION)&v1[-1].m_memBlock);
    LOBYTE(v1->m_lockStatus.m_csLock.LockSemaphore) = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&v1[-1].m_memBlock);
}

// File Line: 538
// RVA: 0xAA5400
_BOOL8 __fastcall AK::StreamMgr::CAkStdStmBlocking::CanBeDestroyed(AK::StreamMgr::CAkStdStmBlocking *this)
{
  _RTL_CRITICAL_SECTION *v1; // rbx
  AK::StreamMgr::CAkStdStmBlocking *v2; // rdi
  bool v3; // di

  v1 = &this->m_lockStatus.m_csLock;
  v2 = this;
  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  v3 = !v2->m_pCurrentTransfer && !v2->m_bTransferCancelling;
  LeaveCriticalSection(v1);
  return v3;
}

// File Line: 556
// RVA: 0xAA6170
AK::StreamMgr::CAkStmMemView *__fastcall AK::StreamMgr::CAkStdStmBlocking::PrepareTransfer(AK::StreamMgr::CAkStdStmBlocking *this, AkFileDesc **out_pFileDesc, AK::StreamMgr::CAkLowLevelTransfer **out_pLowLevelXfer, bool __formal)
{
  AK::StreamMgr::CAkStdStmBlocking *v4; // rdi
  AK::StreamMgr::CAkLowLevelTransfer **v5; // r14
  AkFileDesc **v6; // rsi
  char v7; // al
  unsigned int v8; // er8
  AK::StreamMgr::CAkDeviceBlocking *v9; // r11
  unsigned __int64 in_uPosition; // rdx
  unsigned int in_uBufferSize; // ecx
  unsigned __int64 v12; // rsi
  unsigned int in_uRequestedSize; // esi
  AK::StreamMgr::CAkStmMemView *v14; // rax
  AK::StreamMgr::CAkStmMemView *v15; // rbp

  v4 = this;
  v5 = out_pLowLevelXfer;
  v6 = out_pFileDesc;
  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  v7 = *((_BYTE *)&v4->0 + 117);
  if ( v7 & 8 || !(v7 & 0x40) )
  {
    v15 = 0i64;
  }
  else
  {
    *v6 = v4->m_pFileDesc;
    v8 = v4->m_uTotalScheduledSize;
    v9 = (AK::StreamMgr::CAkDeviceBlocking *)v4->m_pDevice;
    in_uPosition = v4->m_memBlock.uPosition + v4->m_uTotalScheduledSize;
    in_uBufferSize = v4->m_memBlock.uAvailableSize - v8;
    if ( in_uBufferSize > v9->m_uGranularity )
      in_uBufferSize = v9->m_uGranularity;
    if ( *((_BYTE *)&v4->0 + 117) & 2 || (v12 = v4->m_pFileDesc->iFileSize, in_uPosition + in_uBufferSize <= v12) )
    {
      in_uRequestedSize = in_uBufferSize;
    }
    else if ( in_uPosition >= v12 )
    {
      in_uRequestedSize = 0;
    }
    else
    {
      in_uRequestedSize = v12 - in_uPosition;
    }
    v14 = AK::StreamMgr::CAkDeviceBlocking::CreateMemViewStd(
            v9,
            (AK::StreamMgr::CAkStmTask *)&v4->vfptr,
            &v4->m_memBlock,
            v8,
            in_uPosition,
            in_uBufferSize,
            in_uRequestedSize,
            v5);
    v15 = v14;
    if ( v14 )
    {
      v4->m_uTotalScheduledSize += in_uRequestedSize;
      v4->m_pCurrentTransfer = v14;
      v4->m_iIOStartTime = v4->m_pDevice->m_time;
    }
  }
  LeaveCriticalSection(&v4->m_lockStatus.m_csLock);
  return v15;
}

// File Line: 613
// RVA: 0xAA6360
void __fastcall AK::StreamMgr::CAkStdStmBlocking::Update(AK::StreamMgr::CAkStdStmBlocking *this, AK::StreamMgr::CAkStmMemView *in_pTransfer, AKRESULT in_eIOResult, bool in_bRequiredLowLevelXfer)
{
  AK::StreamMgr::CAkStdStmBlocking *v4; // rdi
  AKRESULT v5; // ebp
  AK::StreamMgr::CAkStmMemView *v6; // rsi
  bool v7; // r8

  v4 = this;
  v5 = in_eIOResult;
  v6 = in_pTransfer;
  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  if ( v6 )
  {
    v7 = v5 == 1 && (*((_DWORD *)v6 + 5) & 7) != 2;
    AK::StreamMgr::CAkStdStmBase::AddMemView((AK::StreamMgr::CAkStdStmBase *)&v4->vfptr, v6, v7);
  }
  v4->m_pCurrentTransfer = 0i64;
  AK::StreamMgr::CAkStdStmBase::UpdateTaskStatus((AK::StreamMgr::CAkStdStmBase *)&v4->vfptr, v5);
  LeaveCriticalSection(&v4->m_lockStatus.m_csLock);
}

// File Line: 654
// RVA: 0xAA53B0
_BOOL8 __fastcall AK::StreamMgr::CAkAutoStmBlocking::CanBeDestroyed(AK::StreamMgr::CAkAutoStmBlocking *this)
{
  _RTL_CRITICAL_SECTION *v1; // rbx
  AK::StreamMgr::CAkAutoStmBlocking *v2; // rdi
  bool v3; // di

  v1 = &this->m_lockStatus.m_csLock;
  v2 = this;
  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  v3 = !v2->m_pCurrentTransfer && !v2->m_bTransferCancelled;
  LeaveCriticalSection(v1);
  return v3;
}

// File Line: 669
// RVA: 0xAA6000
AK::StreamMgr::CAkStmMemView *__fastcall AK::StreamMgr::CAkAutoStmBlocking::PrepareTransfer(AK::StreamMgr::CAkAutoStmBlocking *this, AkFileDesc **out_pFileDesc, AK::StreamMgr::CAkLowLevelTransfer **out_pLowLevelXfer, bool in_bCacheOnly)
{
  AK::StreamMgr::CAkAutoStmBlocking *v4; // rdi
  bool v5; // bp
  AK::StreamMgr::CAkLowLevelTransfer **v6; // r14
  char v7; // al
  unsigned __int64 v8; // rsi
  unsigned __int64 v9; // rax
  __int64 in_uMinSize; // rcx
  unsigned __int64 v11; // rdx
  bool in_bEof; // r8
  unsigned int v13; // eax
  AK::StreamMgr::CAkStmMemView *v14; // rax
  AK::StreamMgr::CAkStmMemView *v15; // rbp
  unsigned __int64 v16; // rdx
  unsigned int v17; // ecx
  unsigned int io_uRequestedSize; // [rsp+70h] [rbp+8h]

  v4 = this;
  *out_pFileDesc = this->m_pFileDesc;
  v5 = in_bCacheOnly;
  v6 = out_pLowLevelXfer;
  *out_pLowLevelXfer = 0i64;
  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  v7 = *((_BYTE *)&v4->0 + 117);
  if ( v7 & 8 || !(v7 & 0x40) || v4->m_pCurrentTransfer )
    goto LABEL_24;
  v8 = ((__int64 (__fastcall *)(AK::StreamMgr::CAkAutoStmBlocking *))v4->vfptr[7].__vecDelDtor)(v4);
  v9 = v4->m_uLoopEnd;
  if ( (_DWORD)v9 && v8 >= v9 )
    v8 = v4->m_uLoopStart;
  in_uMinSize = v4->m_uBufferSize;
  v11 = v4->m_pFileDesc->iFileSize;
  if ( v8 + in_uMinSize > v11 )
  {
    in_bEof = 1;
    if ( v8 >= v11 )
      LODWORD(in_uMinSize) = 0;
    else
      LODWORD(in_uMinSize) = v11 - v8;
  }
  else
  {
    in_bEof = 0;
  }
  v13 = v4->m_uMinBufferSize;
  io_uRequestedSize = in_uMinSize;
  if ( v13 < (unsigned int)in_uMinSize )
    LODWORD(in_uMinSize) = v13;
  v14 = AK::StreamMgr::CAkDeviceBlocking::CreateMemViewAuto(
          (AK::StreamMgr::CAkDeviceBlocking *)v4->m_pDevice,
          (AK::StreamMgr::CAkStmTask *)&v4->vfptr,
          v4->m_fileID,
          v8,
          in_uMinSize,
          v4->m_uBufferAlignment,
          in_bEof,
          v5,
          &io_uRequestedSize,
          v6);
  v15 = v14;
  if ( !v14 )
  {
LABEL_24:
    v15 = 0i64;
  }
  else
  {
    v16 = v4->m_uLoopEnd;
    v4->m_pCurrentTransfer = v14;
    if ( v8 >= v16 )
    {
      v17 = io_uRequestedSize;
    }
    else
    {
      v17 = io_uRequestedSize;
      if ( v8 + io_uRequestedSize > v16 )
      {
        v17 = v16 - v8;
        io_uRequestedSize = v16 - v8;
      }
    }
    v4->m_uVirtualBufferingSize += v17;
    AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus((AK::StreamMgr::CAkAutoStmBase *)&v4->vfptr);
    v4->m_iIOStartTime = v4->m_pDevice->m_time;
  }
  LeaveCriticalSection(&v4->m_lockStatus.m_csLock);
  return v15;
}

// File Line: 726
// RVA: 0xAA62A0
void __fastcall AK::StreamMgr::CAkAutoStmBlocking::Update(AK::StreamMgr::CAkAutoStmBlocking *this, AK::StreamMgr::CAkStmMemView *in_pTransfer, AKRESULT in_eIOResult, bool in_bRequiredLowLevelXfer)
{
  AK::StreamMgr::CAkAutoStmBlocking *v4; // rsi
  bool v5; // r14
  AKRESULT v6; // ebp
  AK::StreamMgr::CAkStmMemView *v7; // rdi
  bool v8; // r8

  v4 = this;
  v5 = in_bRequiredLowLevelXfer;
  v6 = in_eIOResult;
  v7 = in_pTransfer;
  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  if ( v7 )
  {
    v8 = v6 == 1 && v4->m_pCurrentTransfer && (*((_DWORD *)v7 + 5) & 7) != 2;
    if ( !v5 && v8 )
    {
      *((_DWORD *)v7 + 5) &= 0xFFFFFFFB;
      *((_DWORD *)v7 + 5) |= 3u;
    }
    AK::StreamMgr::CAkAutoStmBase::AddMemView((AK::StreamMgr::CAkAutoStmBase *)&v4->vfptr, v7, v8);
  }
  v4->m_pCurrentTransfer = 0i64;
  v4->m_bTransferCancelled = 0;
  AK::StreamMgr::CAkAutoStmBase::UpdateTaskStatus((AK::StreamMgr::CAkAutoStmBase *)&v4->vfptr, v6);
  LeaveCriticalSection(&v4->m_lockStatus.m_csLock);
}

// File Line: 759
// RVA: 0xAA5E50
unsigned __int64 __fastcall AK::StreamMgr::CAkAutoStmBlocking::GetVirtualFilePosition(AK::StreamMgr::CAkAutoStmBlocking *this)
{
  AK::StreamMgr::CAkStmMemView *v1; // rax

  v1 = this->m_pCurrentTransfer;
  if ( v1 )
    return v1->m_pBlock->uPosition + v1->m_pBlock->uAvailableSize;
  if ( this->m_listBuffers.m_ulNumListItems > (unsigned __int8)this->m_uNextToGrant )
  {
    v1 = this->m_listBuffers.m_pLast;
    return v1->m_pBlock->uPosition + v1->m_pBlock->uAvailableSize;
  }
  return this->m_uNextExpectedUserPosition;
}

// File Line: 771
// RVA: 0xAA54D0
void __fastcall AK::StreamMgr::CAkAutoStmBlocking::CancelAllPendingTransfers(AK::StreamMgr::CAkAutoStmBlocking *this)
{
  JUMPOUT(this->m_pCurrentTransfer, 0i64, AK::StreamMgr::CAkAutoStmBlocking::CancelCurrentTransfer);
}

// File Line: 781
// RVA: 0xAA5550
void __fastcall AK::StreamMgr::CAkAutoStmBlocking::CancelInconsistentPendingTransfers(AK::StreamMgr::CAkAutoStmBlocking *this, unsigned __int64 in_uNextExpectedPosition)
{
  AK::StreamMgr::CAkStmMemView *v2; // rax

  v2 = this->m_pCurrentTransfer;
  if ( v2 )
    JUMPOUT(
      v2->m_pBlock->uPosition + v2->m_uOffsetInBlock,
      in_uNextExpectedPosition,
      AK::StreamMgr::CAkAutoStmBlocking::CancelCurrentTransfer);
}

// File Line: 792
// RVA: 0xAA5D10
void __fastcall AK::StreamMgr::CAkAutoStmBlocking::FlushSmallBuffersAndPendingTransfers(AK::StreamMgr::CAkAutoStmBlocking *this, unsigned int in_uMinBufferSize)
{
  __int64 v2; // rax
  char v3; // bp
  unsigned int v4; // er14
  AK::StreamMgr::CAkAutoStmBlocking *v5; // rdi
  AK::StreamMgr::CAkStmMemView *v6; // rbx
  AK::StreamMgr::CAkStmMemView *v7; // rsi
  AK::StreamMgr::CAkDeviceBase *v8; // r15
  AK::StreamMgr::CAkStmMemView *v9; // rax
  AK::StreamMgr::CAkStmMemView *v10; // rdx
  __m128i v11; // [rsp+20h] [rbp-38h]
  __m128i v12; // [rsp+30h] [rbp-28h]

  v2 = (unsigned __int8)this->m_uNextToGrant;
  v3 = 0;
  v4 = in_uMinBufferSize;
  v5 = this;
  if ( this->m_listBuffers.m_ulNumListItems > (unsigned int)v2 )
  {
    v6 = this->m_listBuffers.m_pFirst;
    v7 = 0i64;
    if ( this->m_uNextToGrant )
    {
      do
      {
        v7 = v6;
        v6 = v6->pNextView;
        --v2;
      }
      while ( v2 );
    }
    v8 = this->m_pDevice;
    EnterCriticalSection(&v8->m_lockSems.m_csLock);
    if ( v6 )
    {
      do
      {
        if ( v3 || v6->m_pBlock->uAvailableSize - v6->m_uOffsetInBlock < v4 )
        {
          v9 = v6->pNextView;
          v3 = 1;
          v11.m128i_i64[1] = (__int64)v7;
          v11.m128i_i64[0] = (__int64)v6->pNextView;
          if ( v6 == v5->m_listBuffers.m_pFirst )
            v5->m_listBuffers.m_pFirst = v9;
          else
            v7->pNextView = v9;
          if ( v6 == v5->m_listBuffers.m_pLast )
            v5->m_listBuffers.m_pLast = v7;
          --v5->m_listBuffers.m_ulNumListItems;
          _mm_store_si128(&v12, v11);
          AK::StreamMgr::CAkAutoStmBase::DestroyBuffer((AK::StreamMgr::CAkAutoStmBase *)&v5->vfptr, v6);
          v7 = (AK::StreamMgr::CAkStmMemView *)v12.m128i_i64[1];
          v6 = (AK::StreamMgr::CAkStmMemView *)v12.m128i_i64[0];
        }
        else
        {
          v7 = v6;
          v6 = v6->pNextView;
        }
      }
      while ( v6 );
      if ( v3 )
        AK::StreamMgr::CAkIOThread::NotifyMemChange((AK::StreamMgr::CAkIOThread *)&v5->m_pDevice->vfptr);
    }
    LeaveCriticalSection(&v8->m_lockSems.m_csLock);
  }
  v10 = v5->m_pCurrentTransfer;
  if ( v10 && (v3 || v10->m_pBlock->uAvailableSize - v10->m_uOffsetInBlock < v4) )
    AK::StreamMgr::CAkAutoStmBlocking::CancelCurrentTransfer(v5);
}

// File Line: 844
// RVA: 0xAA6280
void __fastcall AK::StreamMgr::CAkAutoStmBlocking::SetLoopEnd(AK::StreamMgr::CAkAutoStmBlocking *this, unsigned int in_uLoopEnd)
{
  this->m_uLoopEnd = in_uLoopEnd;
  this->m_uVirtualBufferingSize = AK::StreamMgr::CAkAutoStmBlocking::ComputeVirtualBuffering(this);
}

// File Line: 851
// RVA: 0xAA5580
__int64 __fastcall AK::StreamMgr::CAkAutoStmBlocking::ComputeVirtualBuffering(AK::StreamMgr::CAkAutoStmBlocking *this)
{
  AK::StreamMgr::CAkStmMemView *v1; // rax
  int v2; // edx
  unsigned int v3; // er8
  AK::StreamMgr::CAkAutoStmBlocking *v4; // rbx
  unsigned __int64 v5; // r11
  AK::StreamMgr::AkMemBlock *v6; // rdx
  __int64 v7; // r9
  unsigned __int64 v8; // r10
  unsigned int v9; // ecx
  AK::StreamMgr::CAkStmMemView *v10; // rdx
  __int64 v11; // r9
  AK::StreamMgr::AkMemBlock *v12; // rdx
  unsigned __int64 v13; // rcx
  unsigned __int64 v14; // r10
  __int64 result; // rax

  v1 = this->m_listBuffers.m_pFirst;
  v2 = (unsigned __int8)this->m_uNextToGrant;
  v3 = 0;
  v4 = this;
  if ( v1 )
  {
    while ( v2 )
    {
      v1 = v1->pNextView;
      --v2;
      if ( !v1 )
        goto LABEL_12;
    }
    if ( v1 )
    {
      v5 = this->m_uLoopEnd;
      do
      {
        v6 = v1->m_pBlock;
        v7 = v1->m_uOffsetInBlock;
        v8 = v6->uPosition;
        if ( v6->uPosition + v7 >= v5 || v8 + v6->uAvailableSize <= v5 )
          v9 = v6->uAvailableSize;
        else
          v9 = v5 - v8;
        v1 = v1->pNextView;
        v3 += v9 - v7;
      }
      while ( v1 );
    }
  }
LABEL_12:
  v10 = v4->m_pCurrentTransfer;
  if ( !v10 )
    return v3;
  v11 = v10->m_uOffsetInBlock;
  v12 = v10->m_pBlock;
  v13 = v4->m_uLoopEnd;
  v14 = v12->uPosition;
  if ( v12->uPosition + v11 >= v13 || v14 + v12->uAvailableSize <= v13 )
    result = v12->uAvailableSize - (_DWORD)v11 + v3;
  else
    result = (_DWORD)v13 - (_DWORD)v14 - (_DWORD)v11 + v3;
  return result;
}

// File Line: 877
// RVA: 0xAA54E0
void __fastcall AK::StreamMgr::CAkAutoStmBlocking::CancelCurrentTransfer(AK::StreamMgr::CAkAutoStmBlocking *this)
{
  AK::StreamMgr::CAkStmMemView *v1; // rax
  AK::StreamMgr::CAkAutoStmBlocking *v2; // r8
  AK::StreamMgr::CAkStmMemView *v3; // r9
  AK::StreamMgr::AkMemBlock *v4; // rcx
  __int64 v5; // r10
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // r11
  unsigned int v8; // edx

  v1 = this->m_pCurrentTransfer;
  v2 = this;
  *((_DWORD *)v1 + 5) &= 0xFFFFFFFA;
  *((_DWORD *)v1 + 5) |= 2u;
  v3 = this->m_pCurrentTransfer;
  v4 = v3->m_pBlock;
  v5 = v3->m_uOffsetInBlock;
  v6 = v2->m_uLoopEnd;
  v7 = v4->uPosition;
  if ( v4->uPosition + v5 >= v6 || v7 + v4->uAvailableSize <= v6 )
    v8 = v4->uAvailableSize;
  else
    v8 = v6 - v7;
  v2->m_uVirtualBufferingSize -= v8 - v5;
  v3->m_uOffsetInBlock = v3->m_pBlock->uAvailableSize;
  v2->m_pCurrentTransfer = 0i64;
  v2->m_bTransferCancelled = 1;
}

