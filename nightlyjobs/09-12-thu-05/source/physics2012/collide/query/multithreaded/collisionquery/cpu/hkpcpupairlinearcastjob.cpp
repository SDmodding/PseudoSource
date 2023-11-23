// File Line: 21
// RVA: 0xD30560
void __fastcall hkCpuPairLinearCastImplementation(
        hkpPairLinearCastJob *pairLinearCastJob,
        hkpProcessCollisionInput *collisionInput,
        hkpPairLinearCastCommand *commandsBase,
        unsigned int numCommands)
{
  float m_iterativeLinearCastEarlyOutDistance; // xmm0_4
  float m_tolerance; // xmm1_4
  int m_iterativeLinearCastMaxIterations; // eax
  int *p_m_resultsCapacity; // rbx
  __int64 v10; // rdi
  hkpCdBody *v11; // rcx
  hkpCdBody *v12; // rdx
  hkpShape *m_shape; // r8
  hkpShape *v14; // r10
  __int64 v15; // r9
  __m128 v16; // xmm1
  __m128 v17; // xmm1
  unsigned int v18; // eax
  __m128 v19; // xmm4
  __m128 v20; // xmm1
  unsigned int v21; // eax
  hkpCdPointCollector *v22; // rax
  __int64 v23; // r10
  int v24; // ecx
  int v25; // eax
  __int64 v26; // rdx
  int v27; // eax
  char *v28; // rcx
  __int64 v29; // rax
  int v30; // ecx
  int v31; // ecx
  char *v32; // rdx
  void **v33; // [rsp+30h] [rbp-B8h] BYREF
  int v34; // [rsp+38h] [rbp-B0h]
  char *v35; // [rsp+40h] [rbp-A8h]
  __int64 v36; // [rsp+48h] [rbp-A0h]
  void **v37; // [rsp+50h] [rbp-98h] BYREF
  int v38; // [rsp+58h] [rbp-90h]
  char *v39; // [rsp+60h] [rbp-88h]
  hkpCollisionDispatcher *m_storage; // [rsp+68h] [rbp-80h] BYREF
  float v41; // [rsp+70h] [rbp-78h] BYREF
  int v42; // [rsp+74h] [rbp-74h]
  float v43; // [rsp+78h] [rbp-70h]
  hkpCollisionFilter *v44; // [rsp+80h] [rbp-68h]
  __m128 v45; // [rsp+C8h] [rbp-20h]
  float m_maxExtraPenetration; // [rsp+D8h] [rbp-10h]
  unsigned int v47; // [rsp+DCh] [rbp-Ch]
  int *v48; // [rsp+E0h] [rbp-8h]
  char v49[24]; // [rsp+E8h] [rbp+0h] BYREF
  __int64 v50; // [rsp+100h] [rbp+18h] BYREF
  char v51[24]; // [rsp+4E8h] [rbp+400h] BYREF
  __int64 v52; // [rsp+500h] [rbp+418h] BYREF

  m_iterativeLinearCastEarlyOutDistance = pairLinearCastJob->m_iterativeLinearCastEarlyOutDistance;
  m_tolerance = pairLinearCastJob->m_tolerance;
  v39 = (char *)&v50;
  v41 = m_iterativeLinearCastEarlyOutDistance;
  v43 = m_tolerance;
  v35 = (char *)&v52;
  m_iterativeLinearCastMaxIterations = pairLinearCastJob->m_iterativeLinearCastMaxIterations;
  m_maxExtraPenetration = FLOAT_1_1920929eN7;
  v42 = m_iterativeLinearCastMaxIterations;
  m_storage = collisionInput->m_dispatcher.m_storage;
  v44 = collisionInput->m_filter.m_storage;
  v37 = &hkpFixedBufferCdPointCollector::`vftable;
  m_storage = (hkpCollisionDispatcher *)16;
  v38 = 2139095022;
  v33 = &hkpFixedBufferCdPointCollector::`vftable;
  v48 = (int *)&v41;
  v36 = 16i64;
  v34 = 2139095022;
  v42 = 0;
  if ( (int)numCommands > 0 )
  {
    p_m_resultsCapacity = &commandsBase->m_resultsCapacity;
    v10 = numCommands;
    do
    {
      v11 = (hkpCdBody *)*((_QWORD *)p_m_resultsCapacity - 3);
      v12 = (hkpCdBody *)*((_QWORD *)p_m_resultsCapacity - 2);
      m_shape = v11->m_shape;
      v14 = v12->m_shape;
      v15 = *((_QWORD *)p_m_resultsCapacity + 1);
      v16 = _mm_sub_ps(*(__m128 *)(p_m_resultsCapacity - 10), *(__m128 *)(p_m_resultsCapacity - 14));
      v43 = pairLinearCastJob->m_tolerance;
      v45 = v16;
      v17 = _mm_mul_ps(v16, v16);
      v37 = &hkpFixedBufferCdPointCollector::`vftable;
      v39 = v49;
      v18 = *p_m_resultsCapacity;
      v19 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170));
      v38 = 2139095022;
      m_storage = (hkpCollisionDispatcher *)v18;
      v20 = _mm_rsqrt_ps(v19);
      m_maxExtraPenetration = pairLinearCastJob->m_maxExtraPenetration;
      v47 = _mm_andnot_ps(
              _mm_cmple_ps(v19, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                  _mm_mul_ps(*(__m128 *)_xmm, v20)),
                v19)).m128_u32[0];
      if ( v15 )
      {
        v33 = &hkpFixedBufferCdPointCollector::`vftable;
        v35 = v51;
        v21 = p_m_resultsCapacity[4];
        v34 = 2139095022;
        v36 = v21;
      }
      v22 = (hkpCdPointCollector *)&v33;
      v23 = (unsigned __int8)collisionInput->m_dispatcher.m_storage->m_agent2Types[(unsigned __int8)m_shape->m_type.m_storage][(unsigned __int8)v14->m_type.m_storage];
      if ( !v15 )
        v22 = 0i64;
      collisionInput->m_dispatcher.m_storage->m_agent2Func[v23].m_linearCastFunc(
        v11,
        v12,
        (hkpLinearCastCollisionInput *)&m_storage,
        (hkpCdPointCollector *)&v37,
        v22);
      v24 = WORD2(m_storage);
      v25 = WORD2(v36);
      p_m_resultsCapacity[1] = WORD2(m_storage);
      p_m_resultsCapacity[5] = v25;
      if ( v24 > 0 )
      {
        v26 = *((_QWORD *)p_m_resultsCapacity - 1);
        v27 = 4 * v24;
        v28 = v49;
        do
        {
          --v27;
          v26 += 16i64;
          *(_OWORD *)(v26 - 16) = *(_OWORD *)v28;
          v28 += 16;
        }
        while ( v27 > 0 );
      }
      v29 = *((_QWORD *)p_m_resultsCapacity + 1);
      if ( v29 )
      {
        v30 = p_m_resultsCapacity[5];
        if ( v30 > 0 )
        {
          v31 = 4 * v30;
          v32 = v51;
          do
          {
            --v31;
            v29 += 16i64;
            *(_OWORD *)(v29 - 16) = *(_OWORD *)v32;
            v32 += 16;
          }
          while ( v31 > 0 );
        }
      }
      p_m_resultsCapacity += 20;
      --v10;
    }
    while ( v10 );
  }
}

// File Line: 114
// RVA: 0xD304A0
__int64 __fastcall hkCpuPairLinearCastJob(hkJobQueue *jobQueue, hkpPairLinearCastJob *nextJobOut)
{
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtCollQueryPairLinearCast";
    v6 = __rdtsc();
    v7 = v5 + 2;
    *((_DWORD *)v7 - 2) = v6;
    Value[1] = v7;
  }
  hkCpuPairLinearCastImplementation(
    nextJobOut,
    nextJobOut->m_collisionInput,
    nextJobOut->m_commandArray,
    nextJobOut->m_numCommands);
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "Et";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    v8[1] = v11;
  }
  return hkJobQueue::finishJobAndGetNextJob(
           jobQueue,
           (hkJobQueue::JobQueueEntry *)nextJobOut,
           (hkJobQueue::JobQueueEntry *)nextJobOut,
           WAIT_FOR_NEXT_JOB);
}

