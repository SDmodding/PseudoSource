// File Line: 21
// RVA: 0xD30560
void __fastcall hkCpuPairLinearCastImplementation(hkpPairLinearCastJob *pairLinearCastJob, hkpProcessCollisionInput *collisionInput, hkpPairLinearCastCommand *commandsBase, int numCommands)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  int v6; // eax
  hkpProcessCollisionInput *v7; // rsi
  hkpPairLinearCastJob *v8; // r14
  int *v9; // rbx
  __int64 v10; // rdi
  hkpCdBody *v11; // rcx
  hkpCdBody *v12; // rdx
  hkpShape *v13; // r8
  hkpShape *v14; // r10
  __int64 v15; // r9
  __m128 v16; // xmm1
  __m128 v17; // xmm1
  unsigned int v18; // eax
  __m128 v19; // xmm4
  __m128 v20; // xmm1
  unsigned int v21; // eax
  void ***v22; // rax
  signed __int64 v23; // r10
  int v24; // ecx
  int v25; // eax
  __int64 v26; // rdx
  int v27; // eax
  char *v28; // rcx
  __int64 v29; // rax
  int v30; // ecx
  int v31; // ecx
  char *v32; // rdx
  void **v33; // [rsp+30h] [rbp-B8h]
  int v34; // [rsp+38h] [rbp-B0h]
  char *v35; // [rsp+40h] [rbp-A8h]
  __int64 v36; // [rsp+48h] [rbp-A0h]
  void **v37; // [rsp+50h] [rbp-98h]
  int v38; // [rsp+58h] [rbp-90h]
  char *v39; // [rsp+60h] [rbp-88h]
  unsigned __int64 v40; // [rsp+68h] [rbp-80h]
  float v41; // [rsp+70h] [rbp-78h]
  int v42; // [rsp+74h] [rbp-74h]
  float v43; // [rsp+78h] [rbp-70h]
  hkpCollisionFilter *v44; // [rsp+80h] [rbp-68h]
  __m128 v45; // [rsp+C8h] [rbp-20h]
  float v46; // [rsp+D8h] [rbp-10h]
  int v47; // [rsp+DCh] [rbp-Ch]
  int *v48; // [rsp+E0h] [rbp-8h]
  char v49; // [rsp+E8h] [rbp+0h]
  __int64 v50; // [rsp+100h] [rbp+18h]
  char v51; // [rsp+4E8h] [rbp+400h]
  __int64 v52; // [rsp+500h] [rbp+418h]

  v4 = pairLinearCastJob->m_iterativeLinearCastEarlyOutDistance;
  v5 = pairLinearCastJob->m_tolerance;
  v39 = (char *)&v50;
  v41 = v4;
  v43 = v5;
  v35 = (char *)&v52;
  v6 = pairLinearCastJob->m_iterativeLinearCastMaxIterations;
  v46 = FLOAT_1_1920929eN7;
  v42 = v6;
  v7 = collisionInput;
  v40 = (unsigned __int64)collisionInput->m_dispatcher.m_storage;
  v8 = pairLinearCastJob;
  v44 = collisionInput->m_filter.m_storage;
  v37 = &hkpFixedBufferCdPointCollector::`vftable;
  v40 = 16i64;
  v38 = 2139095022;
  v33 = &hkpFixedBufferCdPointCollector::`vftable;
  v48 = (int *)&v41;
  v36 = 16i64;
  v34 = 2139095022;
  v42 = 0;
  if ( numCommands > 0 )
  {
    v9 = &commandsBase->m_resultsCapacity;
    v10 = (unsigned int)numCommands;
    do
    {
      v11 = (hkpCdBody *)*((_QWORD *)v9 - 3);
      v12 = (hkpCdBody *)*((_QWORD *)v9 - 2);
      v13 = v11->m_shape;
      v14 = v12->m_shape;
      v15 = *((_QWORD *)v9 + 1);
      v16 = _mm_sub_ps(*(__m128 *)(v9 - 10), *(__m128 *)(v9 - 14));
      v43 = v8->m_tolerance;
      v45 = v16;
      v17 = _mm_mul_ps(v16, v16);
      v37 = &hkpFixedBufferCdPointCollector::`vftable;
      v39 = &v49;
      v18 = *v9;
      v19 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170));
      v38 = 2139095022;
      v40 = v18;
      v20 = _mm_rsqrt_ps(v19);
      v46 = v8->m_maxExtraPenetration;
      v47 = (unsigned __int128)_mm_andnot_ps(
                                 _mm_cmpleps(v19, (__m128)0i64),
                                 _mm_mul_ps(
                                   _mm_mul_ps(
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                                     _mm_mul_ps(*(__m128 *)_xmm, v20)),
                                   v19));
      if ( v15 )
      {
        v33 = &hkpFixedBufferCdPointCollector::`vftable;
        v35 = &v51;
        v21 = v9[4];
        v34 = 2139095022;
        v36 = v21;
      }
      v22 = &v33;
      v23 = (unsigned __int8)v7->m_dispatcher.m_storage->m_agent2Types[(unsigned __int8)v13->m_type.m_storage][(unsigned __int8)v14->m_type.m_storage];
      if ( !v15 )
        v22 = 0i64;
      v7->m_dispatcher.m_storage->m_agent2Func[v23].m_linearCastFunc(
        v11,
        v12,
        (hkpLinearCastCollisionInput *)&v40,
        (hkpCdPointCollector *)&v37,
        (hkpCdPointCollector *)v22);
      v24 = WORD2(v40);
      v25 = WORD2(v36);
      v9[1] = WORD2(v40);
      v9[5] = v25;
      if ( v24 > 0 )
      {
        v26 = *((_QWORD *)v9 - 1);
        v27 = 4 * v24;
        v28 = &v49;
        do
        {
          --v27;
          v26 += 16i64;
          *(_OWORD *)(v26 - 16) = *(_OWORD *)v28;
          v28 += 16;
        }
        while ( v27 > 0 );
      }
      v29 = *((_QWORD *)v9 + 1);
      if ( v29 )
      {
        v30 = v9[5];
        if ( v30 > 0 )
        {
          v31 = 4 * v30;
          v32 = &v51;
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
      v9 += 20;
      --v10;
    }
    while ( v10 );
  }
}

// File Line: 114
// RVA: 0xD304A0
__int64 __fastcall hkCpuPairLinearCastJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  hkJobQueue *v2; // rdi
  hkpPairLinearCastJob *v3; // rbx
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx

  v2 = jobQueue;
  v3 = (hkpPairLinearCastJob *)nextJobOut;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtCollQueryPairLinearCast";
    v6 = __rdtsc();
    v7 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v7 - 8) = v6;
    v4[1] = v7;
  }
  hkCpuPairLinearCastImplementation(v3, v3->m_collisionInput, v3->m_commandArray, v3->m_numCommands);
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "Et";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  return hkJobQueue::finishJobAndGetNextJob(v2, (hkJobQueue::JobQueueEntry *)v3, (hkJobQueue::JobQueueEntry *)v3, 0);
}

