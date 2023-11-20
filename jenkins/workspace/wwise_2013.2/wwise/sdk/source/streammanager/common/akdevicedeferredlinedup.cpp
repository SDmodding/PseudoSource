// File Line: 30
// RVA: 0xAA63F0
void __fastcall AK::StreamMgr::CAkDeviceDeferredLinedUp::CAkDeviceDeferredLinedUp(AK::StreamMgr::CAkDeviceDeferredLinedUp *this, AK::StreamMgr::IAkLowLevelIOHook *in_pLowLevelHook)
{
  AK::StreamMgr::CAkDeviceDeferredLinedUp *v2; // rbx

  v2 = this;
  AK::StreamMgr::CAkDeviceBase::CAkDeviceBase((AK::StreamMgr::CAkDeviceBase *)&this->vfptr, in_pLowLevelHook);
  v2->vfptr = (AK::StreamMgr::CAkIOThreadVtbl *)&AK::StreamMgr::CAkDeviceDeferredLinedUp::`vftable';
  v2->m_poolLowLevelTransfers.m_pFirst = 0i64;
  v2->m_pLowLevelTransfersMem = 0i64;
}

// File Line: 41
// RVA: 0xAA76E0
signed __int64 __fastcall AK::StreamMgr::CAkDeviceDeferredLinedUp::Init(AK::StreamMgr::CAkDeviceDeferredLinedUp *this, AkDeviceSettings *in_settings, unsigned int in_deviceID)
{
  AkDeviceSettings *v3; // rdi
  AK::StreamMgr::CAkDeviceDeferredLinedUp *v4; // rbx
  AKRESULT v6; // esi
  AK::StreamMgr::CAkLowLevelTransferDeferred *v7; // rcx
  unsigned __int64 v8; // rdx
  AK::StreamMgr::CAkLowLevelTransferDeferred *v9; // rax
  unsigned __int64 v10; // rdi
  AK::StreamMgr::CAkStmMemView *v11; // rax
  AK::StreamMgr::CAkStmMemView *v12; // r8
  AK::StreamMgr::CAkStmMemView *v13; // rdx
  AK::StreamMgr::CAkStmMemView *v14; // rcx

  v3 = in_settings;
  v4 = this;
  if ( !in_settings->uMaxConcurrentIO )
    return 31i64;
  v6 = AK::StreamMgr::CAkDeviceBase::Init((AK::StreamMgr::CAkDeviceBase *)&this->vfptr, in_settings, in_deviceID);
  if ( v6 == 1 )
  {
    v7 = (AK::StreamMgr::CAkLowLevelTransferDeferred *)AK::MemoryMgr::Malloc(
                                                         AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId,
                                                         80i64 * v3->uMaxConcurrentIO);
    v4->m_pLowLevelTransfersMem = v7;
    if ( !v7 )
      return 2i64;
    v8 = (unsigned __int64)&v7[v3->uMaxConcurrentIO];
    do
    {
      if ( v7 )
      {
        v7->pNextTransfer = 0i64;
        v7->m_observers.m_pFirst = 0i64;
      }
      v9 = v4->m_poolLowLevelTransfers.m_pFirst;
      if ( v9 )
      {
        v7->pNextTransfer = v9;
        v4->m_poolLowLevelTransfers.m_pFirst = v7;
      }
      else
      {
        v4->m_poolLowLevelTransfers.m_pFirst = v7;
        v7->pNextTransfer = 0i64;
      }
      ++v7;
    }
    while ( (unsigned __int64)v7 < v8 );
    v10 = 40i64 * (v3->uMaxConcurrentIO + v4->m_mgrMemIO.m_uNumViewsAvail);
    v11 = (AK::StreamMgr::CAkStmMemView *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v10);
    v4->m_pStmMemViewMem = v11;
    if ( !v11 )
      return 2i64;
    v12 = (AK::StreamMgr::CAkStmMemView *)((char *)v11 + v10);
    do
    {
      if ( v11 )
      {
        *((_DWORD *)v11 + 5) &= 0xFFFFFFFB;
        *((_DWORD *)v11 + 5) |= 0xBu;
        v11->pNextView = 0i64;
        v11->m_pBlock = 0i64;
        v11->m_uOffsetInBlock = 0;
        v11[1].pNextView = 0i64;
        v11[1].m_pBlock = 0i64;
      }
      v13 = v4->m_poolStmMemView.m_pFirst;
      v14 = v11;
      v11 = (AK::StreamMgr::CAkStmMemView *)((char *)v11 + 40);
      if ( v13 )
      {
        v14->pNextView = v13;
        v4->m_poolStmMemView.m_pFirst = v14;
      }
      else
      {
        v4->m_poolStmMemView.m_pFirst = v14;
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
  AK::StreamMgr::CAkDeviceDeferredLinedUp *v1; // rbx
  AK::StreamMgr::CAkLowLevelTransferDeferred *v2; // rdx

  v1 = this;
  AK::StreamMgr::CAkIOThread::Term((AK::StreamMgr::CAkIOThread *)&this->vfptr);
  v2 = v1->m_pLowLevelTransfersMem;
  if ( v2 )
  {
    v1->m_poolLowLevelTransfers.m_pFirst = 0i64;
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v2);
  }
  v1->m_poolLowLevelTransfers.m_pFirst = 0i64;
  AK::StreamMgr::CAkDeviceBase::Destroy((AK::StreamMgr::CAkDeviceBase *)&v1->vfptr);
}

// File Line: 110
// RVA: 0xAA7070
AK::StreamMgr::CAkStdStmBase *__fastcall AK::StreamMgr::CAkDeviceDeferredLinedUp::CreateStd(AK::StreamMgr::CAkDeviceDeferredLinedUp *this, AkFileDesc *in_pFileDesc, AkOpenMode in_eOpenMode, AK::IAkStdStream **out_pStream)
{
  AK::StreamMgr::CAkDeviceDeferredLinedUp *v4; // rsi
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
  v9 = (AK::StreamMgr::CAkStdStmBase *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0xD0ui64);
  v10 = v9;
  if ( !v9 )
  {
    AK::StreamMgr::CAkStreamMgr::ForceCleanup((AK::StreamMgr::CAkDeviceBase *)&v4->vfptr, 100);
    v9 = (AK::StreamMgr::CAkStdStmBase *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0xD0ui64);
    v10 = v9;
    if ( !v9 )
      return 0i64;
  }
  AK::StreamMgr::CAkStdStmBase::CAkStdStmBase(v9);
  v10[1].vfptr = 0i64;
  v10[1].m_hBlockEvent = 0i64;
  *(_QWORD *)&v10[1].m_bIsBlocked = 0i64;
  v10->vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkStdStmDeferredLinedUp::`vftable'{for `AK::StreamMgr::CAkStmTask'};
  v10->vfptr = (AK::IAkStdStreamVtbl *)&AK::StreamMgr::CAkStdStmDeferredLinedUp::`vftable'{for `AK::IAkStdStream'};
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

// File Line: 162
// RVA: 0xAA6B20
AK::StreamMgr::CAkAutoStmBase *__fastcall AK::StreamMgr::CAkDeviceDeferredLinedUp::CreateAuto(AK::StreamMgr::CAkDeviceDeferredLinedUp *this, AkFileDesc *in_pFileDesc, unsigned int in_fileID, AkAutoStmHeuristics *in_heuristics, AkAutoStmBufSettings *in_pBufferSettings, AK::IAkAutoStream **out_pStream)
{
  AK::StreamMgr::CAkDeviceDeferredLinedUp *v6; // rbx
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
  v11 = (AK::StreamMgr::CAkAutoStmBase *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0xE0ui64);
  v12 = v11;
  if ( !v11 )
  {
    AK::StreamMgr::CAkStreamMgr::ForceCleanup((AK::StreamMgr::CAkDeviceBase *)&v6->vfptr, v9->priority);
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
  v12[1].vfptr = 0i64;
  v12[1].m_hBlockEvent = 0i64;
  *(_QWORD *)&v12[1].m_bIsBlocked = 0i64;
  v12->vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkAutoStmDeferredLinedUp::`vftable'{for `AK::StreamMgr::CAkStmTask'};
  v12->vfptr = (AK::IAkAutoStreamVtbl *)&AK::StreamMgr::CAkAutoStmDeferredLinedUp::`vftable'{for `AK::IAkAutoStream'};
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

// File Line: 226
// RVA: 0xAA7830
void __usercall AK::StreamMgr::CAkDeviceDeferredLinedUp::PerformIO(AK::StreamMgr::CAkDeviceDeferredLinedUp *this@<rcx>, float a2@<xmm0>)
{
  AK::StreamMgr::CAkDeviceDeferredLinedUp *v2; // rbx
  AK::StreamMgr::CAkStmTask *v3; // rax
  float out_fOpDeadline; // [rsp+38h] [rbp+10h]

  v2 = this;
  v3 = AK::StreamMgr::CAkDeviceBase::SchedulerFindNextTask(
         (AK::StreamMgr::CAkDeviceBase *)&this->vfptr,
         &out_fOpDeadline,
         a2);
  if ( v3 )
    AK::StreamMgr::CAkDeviceDeferredLinedUp::ExecuteTask(v2, v3, out_fOpDeadline);
}

// File Line: 242
// RVA: 0xAA7270
void __fastcall AK::StreamMgr::CAkDeviceDeferredLinedUp::ExecuteTask(AK::StreamMgr::CAkDeviceDeferredLinedUp *this, AK::StreamMgr::CAkStmTask *in_pTask, float in_fOpDeadline)
{
  AK::StreamMgr::CAkStmTask *v3; // rbx
  AK::StreamMgr::CAkDeviceDeferredLinedUp *v4; // rsi
  bool v5; // zf
  AK::StreamMgr::CAkClientThreadAwareVtbl *v6; // rax
  __int64 v7; // rdx
  AK::StreamMgr::CAkLowLevelTransferDeferred *v8; // rdi
  char v9; // al
  AK::StreamMgr::IAkIOHookDeferred *v10; // rdx
  AKRESULT v11; // eax
  AK::StreamMgr::CAkLowLevelTransferDeferred *v12; // [rsp+30h] [rbp-28h]
  AkFileDesc *in_pFileDesc; // [rsp+38h] [rbp-20h]
  AkIoHeuristics in_heuristics; // [rsp+78h] [rbp+20h]

  v3 = in_pTask;
  v4 = this;
  AK::StreamMgr::CAkIOThread::IncrementIOCount((AK::StreamMgr::CAkIOThread *)&this->vfptr);
  v5 = (unsigned int)AK::StreamMgr::CAkStmTask::EnsureFileIsOpen(v3) == 1;
  v6 = v3->vfptr;
  if ( v5 )
  {
    v7 = ((__int64 (__fastcall *)(AK::StreamMgr::CAkStmTask *, AkFileDesc **, AK::StreamMgr::CAkLowLevelTransferDeferred **, _QWORD))v6[4].__vecDelDtor)(
           v3,
           &in_pFileDesc,
           &v12,
           0i64);
    if ( v7 )
    {
      v8 = v12;
      if ( v12 )
      {
        v9 = v3->m_priority;
        v10 = (AK::StreamMgr::IAkIOHookDeferred *)v4->m_pLowLevelHook;
        in_heuristics.fDeadline = in_fOpDeadline;
        in_heuristics.priority = v9;
        v11 = AK::StreamMgr::CAkLowLevelTransferDeferred::Execute(
                v12,
                v10,
                in_pFileDesc,
                &in_heuristics,
                (*((_BYTE *)v3 + 117) >> 1) & 1);
        if ( v11 != 1 )
          AK::StreamMgr::CAkLowLevelTransferDeferred::LLIOCallback(&v8->info, v11);
      }
      else
      {
        ((void (__fastcall *)(AK::StreamMgr::CAkStmTask *, __int64, signed __int64))v3->vfptr[5].__vecDelDtor)(
          v3,
          v7,
          1i64);
      }
    }
    else
    {
      ((void (__fastcall *)(AK::StreamMgr::CAkStmTask *, _QWORD, signed __int64, _QWORD))v3->vfptr[5].__vecDelDtor)(
        v3,
        0i64,
        53i64,
        0i64);
    }
  }
  else
  {
    ((void (__fastcall *)(AK::StreamMgr::CAkStmTask *, _QWORD, signed __int64))v6[5].__vecDelDtor)(v3, 0i64, 2i64);
  }
}

// File Line: 317
// RVA: 0xAA6EE0
AK::StreamMgr::CAkStmMemView *__fastcall AK::StreamMgr::CAkDeviceDeferredLinedUp::CreateMemViewStd(AK::StreamMgr::CAkDeviceDeferredLinedUp *this, AK::StreamMgr::CAkStdStmDeferredLinedUp *in_pOwner, AK::StreamMgr::AkMemBlock *in_pMemBlock, unsigned int in_uDataOffset, unsigned __int64 in_uPosition, unsigned int in_uBufferSize, unsigned int in_uRequestedSize, AK::StreamMgr::CAkLowLevelTransferDeferred **out_pLowLevelXfer)
{
  AK::StreamMgr::CAkLowLevelTransferDeferred **v8; // r12
  AK::StreamMgr::CAkDeviceDeferredLinedUp *v9; // rsi
  AK::StreamMgr::CAkStmMemView *v10; // rbp
  __int64 v11; // r13
  AK::StreamMgr::AkMemBlock *v12; // r14
  AK::StreamMgr::CAkStdStmDeferredLinedUp *v13; // rdi
  AK::StreamMgr::CAkStmMemView *v14; // rbx
  AK::StreamMgr::CAkLowLevelTransferDeferred *v15; // rdx
  char *v16; // r8
  __int64 v17; // rax
  AK::StreamMgr::CAkLowLevelTransferDeferred **v18; // rax
  AK::StreamMgr::CAkLowLevelTransferDeferred **v19; // rax
  AK::StreamMgr::CAkLowLevelTransferDeferred *v20; // rax
  AK::StreamMgr::CAkStmMemViewDeferred *v21; // rcx
  AK::StreamMgr::CAkStmMemView *v22; // rax

  v8 = out_pLowLevelXfer;
  v9 = this;
  v10 = 0i64;
  v11 = in_uDataOffset;
  v12 = in_pMemBlock;
  *out_pLowLevelXfer = 0i64;
  v13 = in_pOwner;
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  v14 = v9->m_poolStmMemView.m_pFirst;
  if ( v14 )
    v9->m_poolStmMemView.m_pFirst = v14->pNextView;
  if ( v12->pNextBlock )
  {
    AK::StreamMgr::CAkIOMemMgr::CloneTempBlock(&v9->m_mgrMemIO, v12, (AK::StreamMgr::AkMemBlock **)&out_pLowLevelXfer);
    v12 = (AK::StreamMgr::AkMemBlock *)out_pLowLevelXfer;
    if ( !out_pLowLevelXfer )
    {
      AK::StreamMgr::CAkDeviceBase::DestroyMemView((AK::StreamMgr::CAkDeviceBase *)&v9->vfptr, v14);
      goto LABEL_16;
    }
  }
  else
  {
    out_pLowLevelXfer = (AK::StreamMgr::CAkLowLevelTransferDeferred **)v12;
  }
  v15 = v9->m_poolLowLevelTransfers.m_pFirst;
  v16 = (char *)v12->pData + v11;
  if ( v15 )
    v9->m_poolLowLevelTransfers.m_pFirst = v15->pNextTransfer;
  v17 = v13->m_uLLBlockSize * v13->m_pFileDesc->uSector;
  *((_DWORD *)v15 + 18) &= 0xFFFFFFFC;
  v15->info.pBuffer = v16;
  v15->info.pCookie = v15;
  v15->info.pUserData = 0i64;
  v15->info.uFilePosition = in_uPosition + v17;
  v15->m_pOwner = (AK::StreamMgr::CAkStmTask *)&v13->vfptr;
  v15->info.uBufferSize = in_uBufferSize;
  v15->info.uRequestedSize = in_uRequestedSize;
  v15->info.pCallback = AK::StreamMgr::CAkLowLevelTransferDeferred::LLIOCallback;
  v18 = out_pLowLevelXfer;
  *v8 = v15;
  v18[2] = v15;
  v19 = out_pLowLevelXfer;
  *((_DWORD *)v14 + 5) &= 0xFFFFFFF8;
  v14->m_pBlock = (AK::StreamMgr::AkMemBlock *)v19;
  v14->m_uOffsetInBlock = v11;
  v20 = *v8;
  v21 = (*v8)->m_observers.m_pFirst;
  if ( v21 )
  {
    v14[1].pNextView = (AK::StreamMgr::CAkStmMemView *)&v21->pNextView;
    v20->m_observers.m_pFirst = (AK::StreamMgr::CAkStmMemViewDeferred *)v14;
  }
  else
  {
    v20->m_observers.m_pFirst = (AK::StreamMgr::CAkStmMemViewDeferred *)v14;
    v14[1].pNextView = 0i64;
  }
  v14->pNextView = 0i64;
  v22 = v13->m_listPendingXfers.m_pLast;
  if ( v22 )
    v22->pNextView = v14;
  else
    v13->m_listPendingXfers.m_pFirst = v14;
  v13->m_listPendingXfers.m_pLast = v14;
  v10 = v14;
  v14[1].m_pBlock = (AK::StreamMgr::AkMemBlock *)v13;
LABEL_16:
  LeaveCriticalSection(&v9->m_lockSems.m_csLock);
  return v10;
}

// File Line: 389
// RVA: 0xAA6C60
AK::StreamMgr::CAkStmMemView *__fastcall AK::StreamMgr::CAkDeviceDeferredLinedUp::CreateMemViewAuto(AK::StreamMgr::CAkDeviceDeferredLinedUp *this, AK::StreamMgr::CAkAutoStmDeferredLinedUp *in_pOwner, unsigned int in_fileID, unsigned __int64 in_uPosition, unsigned int in_uMinSize, unsigned int in_uRequiredAlign, bool in_bEof, unsigned int *io_uRequestedSize, AK::StreamMgr::CAkLowLevelTransferDeferred **out_pLowLevelXfer)
{
  AK::StreamMgr::CAkLowLevelTransferDeferred **v9; // r14
  AK::StreamMgr::CAkDeviceDeferredLinedUp *v10; // rdi
  unsigned __int64 v11; // r13
  unsigned int v12; // ebp
  AK::StreamMgr::CAkAutoStmDeferredLinedUp *v13; // rsi
  AK::StreamMgr::CAkStmMemView *v14; // rbx
  bool v15; // zf
  unsigned int v16; // eax
  AK::StreamMgr::CAkLowLevelTransferDeferred **v17; // rcx
  AK::StreamMgr::CAkLowLevelTransferDeferred *v18; // rcx
  AK::StreamMgr::CAkStmMemViewDeferred *v19; // rax
  AK::StreamMgr::CAkLowLevelTransferDeferred *v20; // r8
  unsigned int v21; // edx
  unsigned int v22; // er9
  AK::StreamMgr::CAkLowLevelTransferDeferred *v23; // r10
  __int64 v24; // rax
  AK::StreamMgr::CAkLowLevelTransferDeferred **v25; // rdx
  AK::StreamMgr::CAkLowLevelTransferDeferred **v26; // rax
  AK::StreamMgr::CAkLowLevelTransferDeferred *v27; // rax
  AK::StreamMgr::CAkStmMemViewDeferred *v28; // rcx
  AK::StreamMgr::CAkStmMemView *v29; // rax
  unsigned __int64 in_uPositiona; // [rsp+88h] [rbp+20h]

  in_uPositiona = in_uPosition;
  v9 = out_pLowLevelXfer;
  v10 = this;
  v11 = in_uPosition;
  v12 = in_fileID;
  *out_pLowLevelXfer = 0i64;
  v13 = in_pOwner;
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  v14 = v10->m_poolStmMemView.m_pFirst;
  if ( v14 )
    v10->m_poolStmMemView.m_pFirst = v14->pNextView;
  v15 = v10->m_mgrMemIO.m_bUseCache == 0;
  out_pLowLevelXfer = 0i64;
  if ( v15
    || v12 == -1
    || (v16 = AK::StreamMgr::CAkIOMemMgr::GetCachedBlock(
                &v10->m_mgrMemIO,
                v12,
                v11,
                in_uMinSize,
                in_uRequiredAlign,
                in_bEof,
                io_uRequestedSize,
                (AK::StreamMgr::AkMemBlock **)&out_pLowLevelXfer),
        (v17 = out_pLowLevelXfer) == 0i64) )
  {
    AK::StreamMgr::CAkIOMemMgr::GetOldestFreeBlock(&v10->m_mgrMemIO, (AK::StreamMgr::AkMemBlock **)&out_pLowLevelXfer);
    if ( !out_pLowLevelXfer )
    {
      AK::StreamMgr::CAkDeviceBase::DestroyMemView((AK::StreamMgr::CAkDeviceBase *)&v10->vfptr, v14);
      AK::StreamMgr::CAkIOThread::NotifyMemIdle((AK::StreamMgr::CAkIOThread *)&v10->vfptr);
      v14 = 0i64;
      goto LABEL_21;
    }
    v20 = v10->m_poolLowLevelTransfers.m_pFirst;
    v21 = *io_uRequestedSize;
    v22 = v10->m_uGranularity;
    v23 = out_pLowLevelXfer[1];
    if ( v20 )
      v10->m_poolLowLevelTransfers.m_pFirst = v20->pNextTransfer;
    v24 = v13->m_uLLBlockSize * v13->m_pFileDesc->uSector;
    *((_DWORD *)v20 + 18) &= 0xFFFFFFFC;
    v20->info.uBufferSize = v22;
    v20->info.pBuffer = v23;
    v20->info.uRequestedSize = v21;
    v20->info.uFilePosition = in_uPositiona + v24;
    v20->info.pCookie = v20;
    v20->info.pUserData = 0i64;
    v20->m_pOwner = (AK::StreamMgr::CAkStmTask *)&v13->vfptr;
    v20->info.pCallback = AK::StreamMgr::CAkLowLevelTransferDeferred::LLIOCallback;
    v25 = out_pLowLevelXfer;
    *v9 = v20;
    AK::StreamMgr::CAkIOMemMgr::TagBlock(
      &v10->m_mgrMemIO,
      (AK::StreamMgr::AkMemBlock *)v25,
      (AK::StreamMgr::CAkLowLevelTransfer *)v20,
      v12,
      in_uPositiona,
      *io_uRequestedSize);
    v26 = out_pLowLevelXfer;
    *((_DWORD *)v14 + 5) &= 0xFFFFFFF8;
    v14->m_pBlock = (AK::StreamMgr::AkMemBlock *)v26;
    v14->m_uOffsetInBlock = 0;
    v27 = *v9;
    v28 = (*v9)->m_observers.m_pFirst;
    if ( v28 )
    {
      v14[1].pNextView = (AK::StreamMgr::CAkStmMemView *)&v28->pNextView;
      v27->m_observers.m_pFirst = (AK::StreamMgr::CAkStmMemViewDeferred *)v14;
    }
    else
    {
      v27->m_observers.m_pFirst = (AK::StreamMgr::CAkStmMemViewDeferred *)v14;
      v14[1].pNextView = 0i64;
    }
  }
  else
  {
    *((_DWORD *)v14 + 5) &= 0xFFFFFFF8;
    v14->m_pBlock = (AK::StreamMgr::AkMemBlock *)v17;
    v14->m_uOffsetInBlock = v16;
    v18 = out_pLowLevelXfer[2];
    *v9 = v18;
    if ( v18 )
    {
      v19 = v18->m_observers.m_pFirst;
      if ( v19 )
      {
        v14[1].pNextView = (AK::StreamMgr::CAkStmMemView *)&v19->pNextView;
        v18->m_observers.m_pFirst = (AK::StreamMgr::CAkStmMemViewDeferred *)v14;
      }
      else
      {
        v18->m_observers.m_pFirst = (AK::StreamMgr::CAkStmMemViewDeferred *)v14;
        v14[1].pNextView = 0i64;
      }
    }
  }
  v14->pNextView = 0i64;
  v29 = v13->m_listPendingXfers.m_pLast;
  if ( v29 )
    v29->pNextView = v14;
  else
    v13->m_listPendingXfers.m_pFirst = v14;
  v13->m_listPendingXfers.m_pLast = v14;
  v14[1].m_pBlock = (AK::StreamMgr::AkMemBlock *)v13;
LABEL_21:
  LeaveCriticalSection(&v10->m_lockSems.m_csLock);
  return v14;
}

// File Line: 488
// RVA: 0xAA65C0
void __fastcall AK::StreamMgr::CAkStdStmDeferredLinedUp::Cancel(AK::StreamMgr::CAkStdStmDeferredLinedUp *this)
{
  AkListBare<AK::StreamMgr::CAkStmMemView,AK::StreamMgr::AkListBareNextMemView,AkCountPolicyNoCount> *v1; // rdi

  v1 = (AkListBare<AK::StreamMgr::CAkStmMemView,AK::StreamMgr::AkListBareNextMemView,AkCountPolicyNoCount> *)this;
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock.pData);
  if ( v1[4].m_pFirst || v1[5].m_pFirst )
  {
    AK::StreamMgr::CAkStdStmBase::SetStatus((AK::StreamMgr::CAkStdStmBase *)&v1[-8].m_pLast, AK_StmStatusCancelled);
    AK::StreamMgr::CAkClientThreadAware::SetBlockedStatus((AK::StreamMgr::CAkClientThreadAware *)&v1[-8].m_pLast);
    AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkStdStmBase>::CancelTransfers(
      (AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkStdStmBase> *)&v1[-8].m_pLast,
      v1 + 4,
      1);
    LeaveCriticalSection((LPCRITICAL_SECTION)&v1[-5].m_pLast);
    AK::StreamMgr::CAkIOThread::WaitForIOCompletion(
      (AK::StreamMgr::CAkIOThread *)v1[-2].m_pLast,
      (AK::StreamMgr::CAkClientThreadAware *)&v1[-8].m_pLast);
  }
  else
  {
    AK::StreamMgr::CAkStdStmBase::SetStatus((AK::StreamMgr::CAkStdStmBase *)&v1[-8].m_pLast, AK_StmStatusCancelled);
    LeaveCriticalSection((LPCRITICAL_SECTION)&v1[-5].m_pLast);
  }
}

// File Line: 517
// RVA: 0xAA7650
__int64 __fastcall AK::StreamMgr::CAkStdStmDeferredLinedUp::GetStatus(AK::StreamMgr::CAkStdStmDeferredLinedUp *this)
{
  _RTL_CRITICAL_SECTION *v1; // rbx
  AK::StreamMgr::CAkStdStmDeferredLinedUp *v2; // rdi
  unsigned int v3; // edi

  v1 = (_RTL_CRITICAL_SECTION *)&this[-1].m_memBlock.pData;
  v2 = this;
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock.pData);
  if ( v2->m_lockStatus.m_csLock.OwningThread )
    v3 = 2;
  else
    v3 = v2->m_lockStatus.m_csLock.LockCount << 28 >> 28;
  LeaveCriticalSection(v1);
  return v3;
}

// File Line: 528
// RVA: 0xAA71D0
void __fastcall AK::StreamMgr::CAkStdStmDeferredLinedUp::Destroy(AK::StreamMgr::CAkStdStmDeferredLinedUp *this)
{
  AkListBare<AK::StreamMgr::CAkStmMemView,AK::StreamMgr::AkListBareNextMemView,AkCountPolicyNoCount> *v1; // rdi

  v1 = (AkListBare<AK::StreamMgr::CAkStmMemView,AK::StreamMgr::AkListBareNextMemView,AkCountPolicyNoCount> *)this;
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_memBlock.pData);
  BYTE5(v1[-1].m_pLast) = BYTE5(v1[-1].m_pLast) & 0xBF | 8;
  AK::StreamMgr::CAkStdStmBase::SetStatus((AK::StreamMgr::CAkStdStmBase *)&v1[-8].m_pLast, AK_StmStatusCancelled);
  if ( v1[4].m_pFirst || v1[5].m_pFirst )
  {
    AK::StreamMgr::CAkClientThreadAware::SetBlockedStatus((AK::StreamMgr::CAkClientThreadAware *)&v1[-8].m_pLast);
    AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkStdStmBase>::CancelTransfers(
      (AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkStdStmBase> *)&v1[-8].m_pLast,
      v1 + 4,
      1);
    LeaveCriticalSection((LPCRITICAL_SECTION)&v1[-5].m_pLast);
    AK::StreamMgr::CAkIOThread::WaitForIOCompletion(
      (AK::StreamMgr::CAkIOThread *)v1[-2].m_pLast,
      (AK::StreamMgr::CAkClientThreadAware *)&v1[-8].m_pLast);
  }
  else
  {
    LeaveCriticalSection((LPCRITICAL_SECTION)&v1[-5].m_pLast);
  }
}

// File Line: 568
// RVA: 0xAA7B50
AK::StreamMgr::CAkStmMemView *__fastcall AK::StreamMgr::CAkStdStmDeferredLinedUp::PrepareTransfer(AK::StreamMgr::CAkStdStmDeferredLinedUp *this, AkFileDesc **out_pFileDesc, AK::StreamMgr::CAkLowLevelTransfer **out_pLowLevelXfer, bool __formal)
{
  AK::StreamMgr::CAkStdStmDeferredLinedUp *v4; // rdi
  AK::StreamMgr::CAkLowLevelTransfer **v5; // r15
  AkFileDesc **v6; // rsi
  char v7; // al
  AK::StreamMgr::CAkDeviceDeferredLinedUp *v8; // r10
  unsigned int in_uBufferSize; // ecx
  unsigned __int64 in_uPosition; // rdx
  char v11; // r14
  unsigned __int64 v12; // rsi
  unsigned int in_uRequestedSize; // esi
  AK::StreamMgr::CAkStmMemView *v14; // rbp
  AK::StreamMgr::CAkLowLevelTransferDeferred *v16; // [rsp+60h] [rbp+8h]

  v4 = this;
  v5 = out_pLowLevelXfer;
  v6 = out_pFileDesc;
  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  v7 = *((_BYTE *)&v4->0 + 117);
  if ( v7 & 8 || !(v7 & 0x40) )
    goto LABEL_20;
  *v6 = v4->m_pFileDesc;
  v8 = (AK::StreamMgr::CAkDeviceDeferredLinedUp *)v4->m_pDevice;
  in_uBufferSize = v4->m_memBlock.uAvailableSize - v4->m_uTotalScheduledSize;
  in_uPosition = v4->m_memBlock.uPosition + v4->m_uTotalScheduledSize;
  if ( in_uBufferSize > v8->m_uGranularity )
    in_uBufferSize = v8->m_uGranularity;
  v11 = 0;
  if ( *((_BYTE *)&v4->0 + 117) & 2 || (v12 = v4->m_pFileDesc->iFileSize, in_uPosition + in_uBufferSize <= v12) )
  {
    in_uRequestedSize = in_uBufferSize;
  }
  else
  {
    v11 = 1;
    in_uRequestedSize = in_uPosition >= v12 ? 0 : v12 - in_uPosition;
  }
  v14 = AK::StreamMgr::CAkDeviceDeferredLinedUp::CreateMemViewStd(
          v8,
          v4,
          &v4->m_memBlock,
          v4->m_uTotalScheduledSize,
          in_uPosition,
          in_uBufferSize,
          in_uRequestedSize,
          &v16);
  if ( v14 )
  {
    *v5 = (AK::StreamMgr::CAkLowLevelTransfer *)v16;
    v4->m_uTotalScheduledSize += in_uRequestedSize;
    if ( v11 || v4->m_uTotalScheduledSize == v4->m_memBlock.uAvailableSize )
      AK::StreamMgr::CAkStdStmBase::SetStatus((AK::StreamMgr::CAkStdStmBase *)&v4->vfptr, 0);
    v4->m_iIOStartTime = v4->m_pDevice->m_time;
  }
  else
  {
LABEL_20:
    v14 = 0i64;
  }
  LeaveCriticalSection(&v4->m_lockStatus.m_csLock);
  return v14;
}

// File Line: 660
// RVA: 0xAA7A00
AK::StreamMgr::CAkStmMemView *__fastcall AK::StreamMgr::CAkAutoStmDeferredLinedUp::PrepareTransfer(AK::StreamMgr::CAkAutoStmDeferredLinedUp *this, AkFileDesc **out_pFileDesc, AK::StreamMgr::CAkLowLevelTransfer **out_pLowLevelXfer, bool __formal)
{
  AK::StreamMgr::CAkAutoStmDeferredLinedUp *v4; // rdi
  AK::StreamMgr::CAkLowLevelTransfer **v5; // r14
  char v6; // al
  unsigned __int64 v7; // rsi
  unsigned __int64 v8; // rax
  __int64 in_uMinSize; // rcx
  unsigned __int64 v10; // rdx
  bool in_bEof; // r8
  unsigned int v12; // eax
  AK::StreamMgr::CAkStmMemView *v13; // rbp
  unsigned __int64 v14; // rdx
  unsigned int v15; // ecx
  unsigned int io_uRequestedSize; // [rsp+70h] [rbp+8h]
  AK::StreamMgr::CAkLowLevelTransferDeferred *v18; // [rsp+78h] [rbp+10h]

  v4 = this;
  *out_pFileDesc = this->m_pFileDesc;
  v5 = out_pLowLevelXfer;
  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  v6 = *((_BYTE *)&v4->0 + 117);
  if ( v6 & 8 || !(v6 & 0x40) )
    goto LABEL_23;
  v7 = ((__int64 (__fastcall *)(AK::StreamMgr::CAkAutoStmDeferredLinedUp *))v4->vfptr[7].__vecDelDtor)(v4);
  v8 = v4->m_uLoopEnd;
  if ( (_DWORD)v8 && v7 >= v8 )
    v7 = v4->m_uLoopStart;
  in_uMinSize = v4->m_uBufferSize;
  v10 = v4->m_pFileDesc->iFileSize;
  if ( v7 + in_uMinSize > v10 )
  {
    in_bEof = 1;
    if ( v7 >= v10 )
      LODWORD(in_uMinSize) = 0;
    else
      LODWORD(in_uMinSize) = v10 - v7;
  }
  else
  {
    in_bEof = 0;
  }
  v12 = v4->m_uMinBufferSize;
  io_uRequestedSize = in_uMinSize;
  if ( v12 < (unsigned int)in_uMinSize )
    LODWORD(in_uMinSize) = v12;
  v13 = AK::StreamMgr::CAkDeviceDeferredLinedUp::CreateMemViewAuto(
          (AK::StreamMgr::CAkDeviceDeferredLinedUp *)v4->m_pDevice,
          v4,
          v4->m_fileID,
          v7,
          in_uMinSize,
          v4->m_uBufferAlignment,
          in_bEof,
          &io_uRequestedSize,
          &v18);
  if ( v13 )
  {
    *v5 = (AK::StreamMgr::CAkLowLevelTransfer *)v18;
    v14 = v4->m_uLoopEnd;
    if ( v7 >= v14 )
    {
      v15 = io_uRequestedSize;
    }
    else
    {
      v15 = io_uRequestedSize;
      if ( v7 + io_uRequestedSize > v14 )
      {
        v15 = v14 - v7;
        io_uRequestedSize = v14 - v7;
      }
    }
    v4->m_uVirtualBufferingSize += v15;
    AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus((AK::StreamMgr::CAkAutoStmBase *)&v4->vfptr);
    v4->m_iIOStartTime = v4->m_pDevice->m_time;
  }
  else
  {
LABEL_23:
    v13 = 0i64;
  }
  LeaveCriticalSection(&v4->m_lockStatus.m_csLock);
  return v13;
}

// File Line: 713
// RVA: 0xAA76A0
unsigned __int64 __fastcall AK::StreamMgr::CAkAutoStmDeferredLinedUp::GetVirtualFilePosition(AK::StreamMgr::CAkAutoStmDeferredLinedUp *this)
{
  AK::StreamMgr::CAkStmMemView *v1; // rax

  v1 = this->m_listPendingXfers.m_pLast;
  if ( v1 )
    return v1->m_pBlock->uPosition + v1->m_pBlock->uAvailableSize;
  if ( this->m_listBuffers.m_ulNumListItems > (unsigned __int8)this->m_uNextToGrant )
  {
    v1 = this->m_listBuffers.m_pLast;
    return v1->m_pBlock->uPosition + v1->m_pBlock->uAvailableSize;
  }
  return this->m_uNextExpectedUserPosition;
}

// File Line: 730
// RVA: 0xAA6660
void __fastcall AK::StreamMgr::CAkAutoStmDeferredLinedUp::CancelAllPendingTransfers(AK::StreamMgr::CAkAutoStmDeferredLinedUp *this)
{
  AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::CancelTransfers(
    (AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase> *)&this->vfptr,
    &this->m_listPendingXfers,
    this->m_pDevice->m_mgrMemIO.m_bUseCache == 0);
}

// File Line: 746
// RVA: 0xAA6680
void __fastcall AK::StreamMgr::CAkAutoStmDeferredLinedUp::CancelInconsistentPendingTransfers(AK::StreamMgr::CAkAutoStmDeferredLinedUp *this, unsigned __int64 in_uNextExpectedPosition)
{
  AK::StreamMgr::CAkStmMemView *v2; // rax
  AK::StreamMgr::CAkAutoStmDeferredLinedUp *v3; // r9
  AK::StreamMgr::CAkStmMemView *v4; // r10
  AK::StreamMgr::CAkStmMemView *v5; // r8
  AK::StreamMgr::AkMemBlock *v6; // r11
  AK::StreamMgr::CAkStmMemView *v7; // rcx
  unsigned __int64 v8; // rcx
  AkListBare<AK::StreamMgr::CAkStmMemView,AK::StreamMgr::AkListBareNextMemView,AkCountPolicyNoCount> in_listToCancel; // [rsp+20h] [rbp-38h]
  __int128 v10; // [rsp+30h] [rbp-28h]
  __m128i v11; // [rsp+40h] [rbp-18h]

  v2 = this->m_listPendingXfers.m_pFirst;
  v3 = this;
  v4 = 0i64;
  in_listToCancel.m_pFirst = 0i64;
  in_listToCancel.m_pLast = 0i64;
  v5 = 0i64;
  while ( v2 )
  {
    v6 = v2->m_pBlock;
    if ( v6->uPosition + v2->m_uOffsetInBlock == in_uNextExpectedPosition )
    {
      v8 = v3->m_uLoopEnd;
      in_uNextExpectedPosition = v6->uPosition + v6->uAvailableSize;
      if ( (_DWORD)v8 && in_uNextExpectedPosition >= v8 )
        in_uNextExpectedPosition = v3->m_uLoopStart;
      v5 = v2;
      v2 = v2->pNextView;
    }
    else
    {
      v7 = v2->pNextView;
      v11.m128i_i64[1] = (__int64)v5;
      v11.m128i_i64[0] = (__int64)v7;
      if ( v2 == v3->m_listPendingXfers.m_pFirst )
        v3->m_listPendingXfers.m_pFirst = v7;
      else
        v5->pNextView = v7;
      if ( v2 == v3->m_listPendingXfers.m_pLast )
        v3->m_listPendingXfers.m_pLast = v5;
      in_listToCancel.m_pFirst = v2;
      _mm_store_si128((__m128i *)&v10, v11);
      v5 = (AK::StreamMgr::CAkStmMemView *)*((_QWORD *)&v10 + 1);
      if ( v4 )
      {
        v2->pNextView = v4;
        v4 = v2;
      }
      else
      {
        in_listToCancel.m_pLast = v2;
        v4 = v2;
        v2->pNextView = 0i64;
      }
      v2 = (AK::StreamMgr::CAkStmMemView *)v10;
    }
  }
  if ( v3->m_pDevice->m_mgrMemIO.m_bUseCache || v3->m_listPendingXfers.m_pFirst )
    AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::CancelTransfers(
      (AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase> *)&v3->vfptr,
      &in_listToCancel,
      0);
  else
    AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase>::CancelTransfers(
      (AK::StreamMgr::CAkStmDeferredLinedUpBase<AK::StreamMgr::CAkAutoStmBase> *)&v3->vfptr,
      &in_listToCancel,
      1);
}

// File Line: 787
// RVA: 0xAA7370
void __fastcall AK::StreamMgr::CAkAutoStmDeferredLinedUp::FlushSmallBuffersAndPendingTransfers(AK::StreamMgr::CAkAutoStmDeferredLinedUp *this, unsigned int in_uMinBufferSize)
{
  __int64 v2; // rax
  char v3; // bp
  unsigned int v4; // er14
  AK::StreamMgr::CAkAutoStmDeferredLinedUp *v5; // rdi
  AK::StreamMgr::CAkStmMemView *v6; // rbx
  AK::StreamMgr::CAkStmMemView *v7; // rsi
  _RTL_CRITICAL_SECTION *v8; // r15
  AK::StreamMgr::CAkStmMemView *v9; // rax
  __m128i v10; // xmm0
  bool v11; // r15
  AK::StreamMgr::CAkStmMemView *v12; // rdx
  AK::StreamMgr::CAkStmMemView *v13; // r8
  AK::StreamMgr::CAkStmMemViewDeferred *v14; // rbx
  char i; // r8
  AK::StreamMgr::CAkStmMemViewDeferred *v16; // rcx
  AK::StreamMgr::CAkStmMemView *v17; // rbx
  int v18; // eax
  AK::StreamMgr::AkMemBlock *v19; // r8
  __int64 v20; // r9
  unsigned __int64 v21; // r10
  unsigned __int64 v22; // rcx
  int v23; // ecx
  AK::StreamMgr::CAkStmMemView *v24; // rax
  __m128i v25; // [rsp+20h] [rbp-38h]
  __m128i v26; // [rsp+30h] [rbp-28h]

  v2 = (unsigned __int8)this->m_uNextToGrant;
  v3 = 0;
  v4 = in_uMinBufferSize;
  v5 = this;
  if ( this->m_listBuffers.m_ulNumListItems <= (unsigned int)v2 )
    goto LABEL_47;
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
  v8 = &this->m_pDevice->m_lockSems.m_csLock;
  EnterCriticalSection(v8);
  if ( v6 )
  {
    do
    {
      if ( v3 || v6->m_pBlock->uAvailableSize - v6->m_uOffsetInBlock < v4 )
      {
        v9 = v6->pNextView;
        v3 = 1;
        v25.m128i_i64[1] = (__int64)v7;
        v25.m128i_i64[0] = (__int64)v9;
        if ( v6 == v5->m_listBuffers.m_pFirst )
          v5->m_listBuffers.m_pFirst = v9;
        else
          v7->pNextView = v9;
        if ( v6 == v5->m_listBuffers.m_pLast )
          v5->m_listBuffers.m_pLast = v7;
        v10 = v25;
        --v5->m_listBuffers.m_ulNumListItems;
        _mm_store_si128(&v26, v10);
        AK::StreamMgr::CAkAutoStmBase::DestroyBuffer((AK::StreamMgr::CAkAutoStmBase *)&v5->vfptr, v6);
        v7 = (AK::StreamMgr::CAkStmMemView *)v26.m128i_i64[1];
        v6 = (AK::StreamMgr::CAkStmMemView *)v26.m128i_i64[0];
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
  LeaveCriticalSection(v8);
  if ( !v3 || v5->m_pDevice->m_mgrMemIO.m_bUseCache )
LABEL_47:
    v11 = 0;
  else
    v11 = 1;
  v12 = v5->m_listPendingXfers.m_pFirst;
  v13 = 0i64;
  if ( !v3 )
  {
    if ( !v12 )
      goto LABEL_25;
    while ( v12->m_pBlock->uAvailableSize - v12->m_uOffsetInBlock >= v4 )
    {
      v13 = v12;
      v12 = v12->pNextView;
      if ( !v12 )
        goto LABEL_25;
    }
  }
  if ( v12 )
  {
    while ( 1 )
    {
      v17 = v12->pNextView;
      v26.m128i_i64[1] = (__int64)v13;
      v26.m128i_i64[0] = (__int64)v17;
      if ( v12 == v5->m_listPendingXfers.m_pFirst )
        v5->m_listPendingXfers.m_pFirst = v17;
      else
        v13->pNextView = v17;
      if ( v12 == v5->m_listPendingXfers.m_pLast )
        v5->m_listPendingXfers.m_pLast = v13;
      v18 = *((_DWORD *)v12 + 5);
      _mm_store_si128(&v25, v26);
      if ( v18 & 7 )
      {
        AK::StreamMgr::CAkAutoStmBase::AddMemView((AK::StreamMgr::CAkAutoStmBase *)&v5->vfptr, v12, 0);
      }
      else
      {
        v19 = v12->m_pBlock;
        v20 = v12->m_uOffsetInBlock;
        *((_DWORD *)v12 + 5) = v18 & 0xFFFFFFFA | 2;
        v21 = v19->uPosition;
        v22 = v5->m_uLoopEnd;
        if ( v19->uPosition + v20 >= v22 || v21 + v19->uAvailableSize <= v22 )
          v23 = v19->uAvailableSize - v20;
        else
          v23 = v22 - v20 - v21;
        v5->m_uVirtualBufferingSize -= v23;
        v12->m_uOffsetInBlock = v12->m_pBlock->uAvailableSize;
        v24 = v5->m_listCancelledXfers.m_pFirst;
        if ( v24 )
        {
          v12->pNextView = v24;
          v5->m_listCancelledXfers.m_pFirst = v12;
        }
        else
        {
          v5->m_listCancelledXfers.m_pFirst = v12;
          v12->pNextView = 0i64;
        }
      }
      if ( !v17 )
        break;
      v13 = (AK::StreamMgr::CAkStmMemView *)v25.m128i_i64[1];
      v12 = (AK::StreamMgr::CAkStmMemView *)v25.m128i_i64[0];
    }
  }
LABEL_25:
  v14 = (AK::StreamMgr::CAkStmMemViewDeferred *)v5->m_listCancelledXfers.m_pFirst;
  for ( i = 1; v14; i = v11 == 0 )
  {
    v16 = v14;
    v14 = (AK::StreamMgr::CAkStmMemViewDeferred *)v14->pNextView;
    AK::StreamMgr::CAkStmMemViewDeferred::Cancel(
      v16,
      (AK::StreamMgr::IAkIOHookDeferred *)v5->m_pDevice->m_pLowLevelHook,
      i,
      v11);
  }
}

// File Line: 887
// RVA: 0xAA7C80
void __fastcall AK::StreamMgr::CAkAutoStmDeferredLinedUp::SetLoopEnd(AK::StreamMgr::CAkAutoStmDeferredLinedUp *this, unsigned int in_uLoopEnd)
{
  this->m_uLoopEnd = in_uLoopEnd;
  this->m_uVirtualBufferingSize = AK::StreamMgr::CAkAutoStmDeferredLinedUp::ComputeVirtualBuffering(this);
}

// File Line: 894
// RVA: 0xAA6A40
__int64 __fastcall AK::StreamMgr::CAkAutoStmDeferredLinedUp::ComputeVirtualBuffering(AK::StreamMgr::CAkAutoStmDeferredLinedUp *this)
{
  AK::StreamMgr::CAkStmMemView *v1; // rax
  int v2; // er8
  unsigned int v3; // edx
  AK::StreamMgr::CAkAutoStmDeferredLinedUp *v4; // rbx
  unsigned __int64 v5; // r11
  AK::StreamMgr::AkMemBlock *v6; // r8
  __int64 v7; // r9
  unsigned __int64 v8; // r10
  int v9; // ecx
  AK::StreamMgr::CAkStmMemView *v10; // rax
  unsigned __int64 v11; // r11
  AK::StreamMgr::AkMemBlock *v12; // r8
  __int64 v13; // r9
  unsigned __int64 v14; // r10
  unsigned int v15; // ecx

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
          v9 = v6->uAvailableSize - v7;
        else
          v9 = v5 - v7 - v8;
        v1 = v1->pNextView;
        v3 += v9;
      }
      while ( v1 );
    }
  }
LABEL_12:
  v10 = v4->m_listPendingXfers.m_pFirst;
  if ( v10 )
  {
    v11 = v4->m_uLoopEnd;
    do
    {
      v12 = v10->m_pBlock;
      v13 = v10->m_uOffsetInBlock;
      v14 = v12->uPosition;
      if ( v12->uPosition + v13 >= v11 || v14 + v12->uAvailableSize <= v11 )
        v15 = v12->uAvailableSize;
      else
        v15 = v11 - v14;
      v10 = v10->pNextView;
      v3 += v15 - v13;
    }
    while ( v10 );
  }
  return v3;
}

