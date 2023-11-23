// File Line: 28
// RVA: 0xB43C50
hkJobQueue::JobStatus __fastcall hkaCpuSampleAnimationJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  _QWORD *Value; // rax
  unsigned __int64 v5; // rdx
  _QWORD *v6; // rcx
  _QWORD *v7; // r8
  unsigned __int64 v8; // rax
  int v9; // r14d
  __int64 v10; // rbp
  __int64 v11; // rdi
  _QWORD *v12; // rbx
  hkSemaphore *v13; // rcx
  _DWORD *v14; // rax
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  _QWORD *v18; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = (_QWORD *)Value[1];
  v7 = Value;
  if ( (unsigned __int64)v6 < Value[3] )
  {
    *v6 = "TthkaCpuSampleAnimationJob";
    v8 = __rdtsc();
    v5 = (unsigned __int64)HIDWORD(v8) << 32;
    v6 += 2;
    *((_DWORD *)v6 - 2) = v8;
    v7[1] = v6;
  }
  v9 = 0;
  if ( *(int *)&nextJobOut->m_data[40] > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = *(_QWORD *)&nextJobOut->m_data[32];
      v12 = *(_QWORD **)(v11 + v10 + 16);
      (*(__int64 (__fastcall **)(_QWORD *, unsigned __int64, _QWORD *))(*v12 + 64i64))(v6, v5, v7);
      (*(void (__fastcall **)(_QWORD *, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD))(*v12 + 32i64))(
        v12,
        *v12,
        *(unsigned int *)(v11 + v10 + 8),
        *(_QWORD *)(v11 + v10 + 216),
        *(_DWORD *)(v11 + v10 + 12),
        *(_QWORD *)(v11 + v10 + 224));
      ++v9;
      v10 += 240i64;
    }
    while ( v9 < *(_DWORD *)&nextJobOut->m_data[40] );
  }
  v13 = *(hkSemaphore **)&nextJobOut->m_data[8];
  if ( v13 )
    hkSemaphore::release(v13, 1);
  v14 = *(_DWORD **)&nextJobOut->m_data[16];
  if ( v14 )
    ++*v14;
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "Et";
    v17 = __rdtsc();
    v18 = v16 + 2;
    *((_DWORD *)v18 - 2) = v17;
    v15[1] = v18;
  }
  return hkJobQueue::finishJobAndGetNextJob(jobQueue, nextJobOut, nextJobOut, WAIT_FOR_NEXT_JOB);
}

// File Line: 58
// RVA: 0xB43DC0
hkJobQueue::JobStatus __fastcall hkaCpuSampleAndCombineJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  _QWORD *Value; // rax
  unsigned __int64 v5; // r8
  _QWORD *v6; // r9
  unsigned __int64 v7; // rax
  unsigned int v8; // edi
  int v9; // esi
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  hkQsTransformf *v14; // rdx
  __int64 v15; // rcx
  __int64 v16; // r9
  _QWORD *v17; // r8
  unsigned __int64 v18; // rcx
  unsigned __int64 v19; // rax
  hkSemaphore *v20; // rcx
  _DWORD *v21; // rax
  _QWORD *v22; // r8
  _QWORD *v23; // rcx
  unsigned __int64 v24; // rax
  _QWORD *v25; // rcx
  hkQsTransformf *array; // [rsp+30h] [rbp-28h] BYREF
  unsigned int v28; // [rsp+38h] [rbp-20h]
  int v29; // [rsp+3Ch] [rbp-1Ch]
  hkResult result; // [rsp+68h] [rbp+10h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = Value[1];
  v6 = Value;
  if ( v5 < Value[3] )
  {
    *(_QWORD *)v5 = "LthkaCpuSampleAndCombineJob";
    *(_QWORD *)(v5 + 16) = "StSetup";
    v7 = __rdtsc();
    *(_DWORD *)(v5 + 8) = v7;
    v6[1] = v5 + 24;
  }
  if ( !*(_QWORD *)&nextJobOut->m_data[56]
    || (v8 = *(_DWORD *)&nextJobOut->m_data[52], *(_DWORD *)&nextJobOut->m_data[64] >= v8) )
  {
    v8 = *(_DWORD *)&nextJobOut->m_data[64];
  }
  v9 = *(_DWORD *)&nextJobOut->m_data[68];
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "StSampleAndBlend";
    v12 = __rdtsc();
    v13 = v11 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v10[1] = v13;
  }
  if ( *(_QWORD *)&nextJobOut->m_data[56] )
  {
    v29 = 0x80000000;
    v14 = 0i64;
    v28 = 0;
    array = 0i64;
    if ( (int)v8 > 0 )
    {
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, v8, 48);
      v14 = array;
    }
    v15 = *(_QWORD *)&nextJobOut->m_data[32];
    v16 = *(_QWORD *)&nextJobOut->m_data[96];
    v28 = v8;
    (*(void (__fastcall **)(__int64, hkQsTransformf *, _QWORD, __int64, int))(*(_QWORD *)v15 + 40i64))(
      v15,
      v14,
      v8,
      v16,
      v9);
    v17 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v18 = v17[1];
    if ( v18 < v17[3] )
    {
      *(_QWORD *)v18 = "StLocalToModel";
      v19 = __rdtsc();
      *(_DWORD *)(v18 + 8) = v19;
      v17[1] = v18 + 16;
    }
    hkaSkeletonUtils::transformLocalPoseToModelPose(
      v8,
      *(const __int16 **)&nextJobOut->m_data[56],
      array,
      *(hkQsTransformf **)&nextJobOut->m_data[88]);
    v28 = 0;
    if ( v29 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        array,
        48 * (v29 & 0x3FFFFFFF));
  }
  else
  {
    (*(void (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD, int))(**(_QWORD **)&nextJobOut->m_data[32] + 40i64))(
      *(_QWORD *)&nextJobOut->m_data[32],
      *(_QWORD *)&nextJobOut->m_data[88],
      v8,
      *(_QWORD *)&nextJobOut->m_data[96],
      v9);
  }
  v20 = *(hkSemaphore **)&nextJobOut->m_data[8];
  if ( v20 )
    hkSemaphore::release(v20, 1);
  v21 = *(_DWORD **)&nextJobOut->m_data[16];
  if ( v21 )
    ++*v21;
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "lt";
    v24 = __rdtsc();
    v25 = v23 + 2;
    *((_DWORD *)v25 - 2) = v24;
    v22[1] = v25;
  }
  return hkJobQueue::finishJobAndGetNextJob(jobQueue, nextJobOut, nextJobOut, WAIT_FOR_NEXT_JOB);
}

// File Line: 93
// RVA: 0xB43FF0
hkJobQueue::JobStatus __fastcall hkaCpuQuantizedSampleAndCombineJob(
        hkJobQueue *jobQueue,
        hkaQuantizedSampleAndCombineJob *nextJobOut)
{
  hkSemaphore *m_semaphore; // rcx
  unsigned int *m_flag; // rax

  executeQuantizedSampleAndCombineJob(nextJobOut);
  m_semaphore = nextJobOut->m_jobDoneNotifier.m_semaphore;
  if ( m_semaphore )
    hkSemaphore::release(m_semaphore, 1);
  m_flag = nextJobOut->m_jobDoneNotifier.m_flag;
  if ( m_flag )
    ++*m_flag;
  return hkJobQueue::finishJobAndGetNextJob(
           jobQueue,
           (hkJobQueue::JobQueueEntry *)nextJobOut,
           (hkJobQueue::JobQueueEntry *)nextJobOut,
           WAIT_FOR_NEXT_JOB);
}

