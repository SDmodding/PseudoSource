// File Line: 28
// RVA: 0xB43C50
hkJobQueue::JobStatus __fastcall hkaCpuSampleAnimationJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  hkJobQueue *v2; // r15
  hkJobQueue::JobQueueEntry *v3; // rsi
  _QWORD *v4; // rax
  unsigned __int64 v5; // rdx
  _QWORD *v6; // rcx
  _QWORD *v7; // r8
  unsigned __int64 v8; // rax
  int v9; // er14
  __int64 v10; // rbp
  __int64 v11; // rdi
  float *v12; // rbx
  float v13; // xmm6_4
  int v14; // eax
  float v15; // xmm6_4
  hkSemaphore *v16; // rcx
  _DWORD *v17; // rax
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  signed __int64 v21; // rcx
  __int64 v23; // [rsp+20h] [rbp-38h]

  v2 = jobQueue;
  v3 = nextJobOut;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = (_QWORD *)v4[1];
  v7 = v4;
  if ( (unsigned __int64)v6 < v4[3] )
  {
    *v6 = "TthkaCpuSampleAnimationJob";
    v8 = __rdtsc();
    v5 = (unsigned __int64)HIDWORD(v8) << 32;
    v6 += 2;
    *((_DWORD *)v6 - 2) = v8;
    v7[1] = v6;
  }
  v9 = 0;
  if ( *(_DWORD *)&v3->m_data[40] > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = *(_QWORD *)&v3->m_data[32];
      v12 = *(float **)(v11 + v10 + 16);
      v13 = (float)*(signed int *)(v11 + v10) + *(float *)(v11 + v10 + 4);
      v14 = (*(__int64 (__fastcall **)(_QWORD *, unsigned __int64, _QWORD *))(*(_QWORD *)v12 + 64i64))(v6, v5, v7);
      LODWORD(v23) = *(_DWORD *)(v11 + v10 + 12);
      v15 = (float)(v13 / (float)(v14 - 1)) * v12[5];
      (*(void (__fastcall **)(float *, _QWORD, _QWORD, _QWORD, __int64, _QWORD))(*(_QWORD *)v12 + 32i64))(
        v12,
        *(_QWORD *)v12,
        *(unsigned int *)(v11 + v10 + 8),
        *(_QWORD *)(v11 + v10 + 216),
        v23,
        *(_QWORD *)(v11 + v10 + 224));
      ++v9;
      v10 += 240i64;
    }
    while ( v9 < *(_DWORD *)&v3->m_data[40] );
  }
  v16 = *(hkSemaphore **)&v3->m_data[8];
  if ( v16 )
    hkSemaphore::release(v16, 1);
  v17 = *(_DWORD **)&v3->m_data[16];
  if ( v17 )
    ++*v17;
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  if ( (unsigned __int64)v19 < v18[3] )
  {
    *v19 = "Et";
    v20 = __rdtsc();
    v21 = (signed __int64)(v19 + 2);
    *(_DWORD *)(v21 - 8) = v20;
    v18[1] = v21;
  }
  return hkJobQueue::finishJobAndGetNextJob(v2, v3, v3, 0);
}

// File Line: 58
// RVA: 0xB43DC0
hkJobQueue::JobStatus __fastcall hkaCpuSampleAndCombineJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  hkJobQueue *v2; // rbp
  hkJobQueue::JobQueueEntry *v3; // rbx
  _QWORD *v4; // rax
  unsigned __int64 v5; // r8
  _QWORD *v6; // r9
  unsigned __int64 v7; // rax
  unsigned int v8; // edi
  int v9; // esi
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  hkQsTransformf *v14; // rdx
  int v15; // er9
  __int64 v16; // rcx
  __int64 v17; // r9
  _QWORD *v18; // r8
  unsigned __int64 v19; // rcx
  unsigned __int64 v20; // rax
  int v21; // ST20_4
  hkSemaphore *v22; // rcx
  _DWORD *v23; // rax
  _QWORD *v24; // r8
  _QWORD *v25; // rcx
  unsigned __int64 v26; // rax
  signed __int64 v27; // rcx
  _QWORD sizeElem[2]; // [rsp+20h] [rbp-38h]
  hkQsTransformf *array; // [rsp+30h] [rbp-28h]
  unsigned int v31; // [rsp+38h] [rbp-20h]
  int v32; // [rsp+3Ch] [rbp-1Ch]
  hkResult result; // [rsp+68h] [rbp+10h]

  v2 = jobQueue;
  v3 = nextJobOut;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = v4[1];
  v6 = v4;
  if ( v5 < v4[3] )
  {
    *(_QWORD *)v5 = "LthkaCpuSampleAndCombineJob";
    *(_QWORD *)(v5 + 16) = "StSetup";
    v7 = __rdtsc();
    *(_DWORD *)(v5 + 8) = v7;
    v6[1] = v5 + 24;
  }
  if ( !*(_QWORD *)&v3->m_data[56] || (v8 = *(_DWORD *)&v3->m_data[52], *(_DWORD *)&v3->m_data[64] >= v8) )
    v8 = *(_DWORD *)&v3->m_data[64];
  v9 = *(_DWORD *)&v3->m_data[68];
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "StSampleAndBlend";
    v12 = __rdtsc();
    v13 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v10[1] = v13;
  }
  if ( *(_QWORD *)&v3->m_data[56] )
  {
    v32 = 2147483648;
    v14 = 0i64;
    v31 = 0;
    array = 0i64;
    if ( (signed int)v8 > 0 )
    {
      v15 = v8;
      if ( (v8 & 0x80000000) != 0 )
        v15 = 0;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v15, 48);
      v14 = array;
    }
    v16 = *(_QWORD *)&v3->m_data[32];
    v17 = *(_QWORD *)&v3->m_data[96];
    v31 = v8;
    LODWORD(sizeElem[0]) = v9;
    (*(void (__fastcall **)(__int64, hkQsTransformf *, _QWORD, __int64, _QWORD))(*(_QWORD *)v16 + 40i64))(
      v16,
      v14,
      v8,
      v17,
      sizeElem[0]);
    v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v19 = v18[1];
    if ( v19 < v18[3] )
    {
      *(_QWORD *)v19 = "StLocalToModel";
      v20 = __rdtsc();
      *(_DWORD *)(v19 + 8) = v20;
      v18[1] = v19 + 16;
    }
    hkaSkeletonUtils::transformLocalPoseToModelPose(
      v8,
      *(const __int16 **)&v3->m_data[56],
      array,
      *(hkQsTransformf **)&v3->m_data[88]);
    v31 = 0;
    if ( v32 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        48 * (v32 & 0x3FFFFFFF));
  }
  else
  {
    v21 = v9;
    (*(void (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD, int))(**(_QWORD **)&v3->m_data[32] + 40i64))(
      *(_QWORD *)&v3->m_data[32],
      *(_QWORD *)&v3->m_data[88],
      v8,
      *(_QWORD *)&v3->m_data[96],
      v21);
  }
  v22 = *(hkSemaphore **)&v3->m_data[8];
  if ( v22 )
    hkSemaphore::release(v22, 1);
  v23 = *(_DWORD **)&v3->m_data[16];
  if ( v23 )
    ++*v23;
  v24 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v25 = (_QWORD *)v24[1];
  if ( (unsigned __int64)v25 < v24[3] )
  {
    *v25 = "lt";
    v26 = __rdtsc();
    v27 = (signed __int64)(v25 + 2);
    *(_DWORD *)(v27 - 8) = v26;
    v24[1] = v27;
  }
  return hkJobQueue::finishJobAndGetNextJob(v2, v3, v3, 0);
}

// File Line: 93
// RVA: 0xB43FF0
hkJobQueue::JobStatus __fastcall hkaCpuQuantizedSampleAndCombineJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  hkJobQueue *v2; // rdi
  hkJobQueue::JobQueueEntry *v3; // rbx
  hkSemaphore *v4; // rcx
  _DWORD *v5; // rax

  v2 = jobQueue;
  v3 = nextJobOut;
  executeQuantizedSampleAndCombineJob((hkaQuantizedSampleAndCombineJob *)nextJobOut);
  v4 = *(hkSemaphore **)&v3->m_data[8];
  if ( v4 )
    hkSemaphore::release(v4, 1);
  v5 = *(_DWORD **)&v3->m_data[16];
  if ( v5 )
    ++*v5;
  return hkJobQueue::finishJobAndGetNextJob(v2, v3, v3, 0);
}

