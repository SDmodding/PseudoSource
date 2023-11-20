// File Line: 23
// RVA: 0xD310E0
float __fastcall hkCpuWorldRayCastCollector::addBroadPhaseHandle(hkCpuWorldRayCastCollector *this, hkpBroadPhaseHandle *broadPhaseHandle, int castIndex)
{
  __m128 *v3; // rbx
  hkpCollidable *v4; // rdi
  hkpShape *v5; // rsi
  __m128 *v6; // rax
  unsigned __int64 v7; // r9
  __m128 *v8; // rbp
  __m128 v9; // xmm6
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm4
  __m128 v14; // xmm6
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm2
  float v18; // xmm0_4
  unsigned __int64 v19; // rax
  hkBaseObjectVtbl *v20; // rax
  unsigned __int64 v21; // rdx
  signed __int64 v22; // rcx
  signed int v23; // eax
  float v24; // xmm3_4
  signed __int64 v25; // rdx
  __int64 v26; // r8
  signed int v27; // edx
  __m128 *v28; // rax
  __m128 v29; // xmm0
  unsigned __int64 v30; // rax
  float v31; // xmm0_4
  __m128 v32; // xmm0
  __m128 v34; // [rsp+20h] [rbp-68h]
  float v35; // [rsp+30h] [rbp-58h]
  int v36; // [rsp+34h] [rbp-54h]
  int v37; // [rsp+40h] [rbp-48h]
  int v38; // [rsp+60h] [rbp-28h]
  char v39; // [rsp+90h] [rbp+8h]

  v3 = (__m128 *)this;
  v4 = (hkpCollidable *)((char *)broadPhaseHandle + SBYTE1(broadPhaseHandle[1].m_id));
  v5 = v4->m_shape;
  if ( !v4->m_shape )
    return this->m_hitFraction;
  if ( *(_BYTE *)this->m_filter->vfptr->isCollisionEnabled(
                   (hkpRayCollidableFilter *)&this->m_filter->vfptr,
                   (hkBool *)&v39,
                   this->m_originalInput,
                   v4) )
  {
    v6 = (__m128 *)v3[2].m128_u64[0];
    v7 = v3[8].m128_u64[0];
    v8 = (__m128 *)v4->m_motion;
    v9 = _mm_sub_ps(*v6, v8[3]);
    v10 = v8[2];
    v11 = _mm_unpacklo_ps(*v8, v8[1]);
    v12 = _mm_movelh_ps(v11, v10);
    v3[4] = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(_mm_movehl_ps(v12, v11), v10, 212), _mm_shuffle_ps(v9, v9, 85)),
                _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), v12)),
              _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), _mm_shuffle_ps(_mm_unpackhi_ps(*v8, v8[1]), v10, 228)));
    v13 = v8[2];
    v14 = _mm_sub_ps(v6[1], v8[3]);
    v15 = _mm_unpacklo_ps(*v8, v8[1]);
    v16 = _mm_shuffle_ps(_mm_unpackhi_ps(*v8, v8[1]), v13, 228);
    v3[7].m128_u64[0] = (unsigned __int64)v4;
    v17 = _mm_movelh_ps(v15, v13);
    v18 = v3[1].m128_f32[0];
    v3[5] = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(_mm_movehl_ps(v17, v15), v13, 212), _mm_shuffle_ps(v14, v14, 85)),
                _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v17)),
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v16));
    v19 = v6[2].m128_u64[1];
    v35 = v18;
    v3[7].m128_u64[1] = v19;
    v20 = v5->vfptr;
    v36 = -1;
    v38 = 0;
    v37 = -1;
    if ( v7 )
    {
      ((void (__fastcall *)(hkpShape *, __m128 *, hkpCollidable *))v20[3].__vecDelDtor)(v5, v3 + 4, v4);
      *(_DWORD *)(v3[1].m128_u64[1] + 60) = *(_DWORD *)(v3[8].m128_u64[0] + 36);
      v32 = (__m128)*(unsigned int *)(v3[8].m128_u64[0] + 8);
    }
    else
    {
      ((void (__fastcall *)(hkpShape *, char *, __m128 *, __m128 *))v20[2].__first_virtual_table_function__)(
        v5,
        &v39,
        v3 + 4,
        &v34);
      if ( !v39 )
        return v3[1].m128_f32[0];
      v21 = v3[1].m128_u64[1];
      v22 = v3[2].m128_i64[1];
      v23 = *(_DWORD *)(v21 + 60);
      if ( v23 >= *(_DWORD *)(v21 + 56) )
      {
        v25 = v22 + 96;
        if ( v23 > 1 )
        {
          v26 = (unsigned int)(v23 - 1);
          do
          {
            if ( *(float *)(v22 + 16) < *(float *)(v25 + 16) )
              v22 = v25;
            v25 += 96i64;
            --v26;
          }
          while ( v26 );
        }
        v24 = *(float *)(v22 + 16);
        if ( v35 >= v24 )
          return v3[1].m128_f32[0];
      }
      else
      {
        v22 = v3[3].m128_i64[0];
        v24 = *(float *)&FLOAT_1_0;
        *(_DWORD *)(v21 + 60) = v23 + 1;
        v3[3].m128_u64[0] += 96i64;
      }
      if ( !v22 )
        return v3[1].m128_f32[0];
      v27 = 6;
      v28 = &v34;
      v34 = _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), v8[1]), _mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), *v8)),
              _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), v8[2]));
      do
      {
        v29 = *v28;
        --v27;
        ++v28;
        *(__m128 *)((char *)v28 + v22 - (_QWORD)&v34 - 16) = v29;
      }
      while ( v27 > 0 );
      *(_QWORD *)(v22 + 80) = v4;
      v30 = v3[1].m128_u64[1];
      if ( *(_BYTE *)(v30 + 65) )
      {
        v31 = 0.0;
        v35 = 0.0;
      }
      else
      {
        v31 = v35;
      }
      if ( *(_DWORD *)(v30 + 56) != 1 )
        v31 = v24;
      v3[1].m128_f32[0] = v31;
      v3[1].m128_i8[4] = 1;
      v32 = (__m128)v3[1].m128_u32[0];
    }
    v3[9] = _mm_shuffle_ps(v32, v32, 0);
    return v3[1].m128_f32[0];
  }
  return v3[1].m128_f32[0];
}

// File Line: 86
// RVA: 0xD31630
void __fastcall castRayBroadPhase(hkpBroadPhase *broadphase, hkpWorldRayCastCommand *command, hkCpuWorldRayCastCollector *collector, hkpFixedBufferRayHitCollector *fixedBufferHitCollector)
{
  hkVector4f v4; // xmm0
  unsigned int v5; // eax
  hkpBroadPhase *v6; // r10
  hkpWorldRayCastOutput *v7; // rax
  hkpCollisionFilter *v8; // rax
  int v9; // ecx
  hkpWorldRayCastOutput *v10; // rax
  hkpWorldRayCastOutput *v11; // rax
  __m128 v12; // [rsp+20h] [rbp-38h]
  int v13; // [rsp+30h] [rbp-28h]
  hkVector4f *v14; // [rsp+38h] [rbp-20h]
  int v15; // [rsp+40h] [rbp-18h]
  __int64 v16; // [rsp+48h] [rbp-10h]

  v4.m_quad = (__m128)command->m_rayInput.m_from;
  collector->m_originalInput = &command->m_rayInput;
  v14 = &command->m_rayInput.m_to;
  v5 = command->m_rayInput.m_filterInfo;
  v12 = v4.m_quad;
  collector->m_workInput.m_filterInfo = v5;
  v6 = broadphase;
  collector->m_result = command->m_results;
  v7 = command->m_results;
  collector->m_command = command;
  collector->m_nextFreeResult = v7;
  v15 = 16;
  v16 = 0i64;
  v13 = 1;
  if ( command->m_rayInput.m_enableShapeCollectionFilter.m_bool )
  {
    v8 = collector->m_filter;
    if ( v8 )
      collector->m_workInput.m_rayShapeCollectionFilter = (hkpRayShapeCollectionFilter *)&v8->vfptr;
    else
      collector->m_workInput.m_rayShapeCollectionFilter = 0i64;
  }
  else
  {
    collector->m_workInput.m_rayShapeCollectionFilter = 0i64;
  }
  if ( command->m_useCollector.m_bool )
  {
    if ( fixedBufferHitCollector )
    {
      v9 = command->m_resultsCapacity;
      v10 = command->m_results;
      fixedBufferHitCollector->m_rayCastOutputBase.m_storage = v10;
      fixedBufferHitCollector->m_nextFreeOutput.m_storage = v10;
      fixedBufferHitCollector->m_capacity.m_storage = v9;
      fixedBufferHitCollector->m_earlyOutHitFraction = 1.0;
      fixedBufferHitCollector->vfptr = (hkpRayHitCollectorVtbl *)&hkpFixedBufferRayHitCollector::`vftable;
      fixedBufferHitCollector->m_numOutputs.m_storage = 0;
      fixedBufferHitCollector->m_collidableOnPpu.m_storage = 0i64;
    }
    else
    {
      fixedBufferHitCollector = 0i64;
    }
    collector->m_fixedBufferRayHitCollector = fixedBufferHitCollector;
    g_FixedBufferRayHitCollectorAddRayHitCallbackFunc = hkpFixedBufferRayHitCollector::addRayHitImplementation;
  }
  else
  {
    collector->m_fixedBufferRayHitCollector = 0i64;
  }
  v11 = command->m_results;
  v11->m_rootCollidable = 0i64;
  v11->m_hitFraction = 1.0;
  v11->m_extraInfo = -1;
  v11->m_shapeKeyIndex = 0;
  v11->m_shapeKeys[0] = -1;
  ((void (__fastcall *)(hkpBroadPhase *, __m128 *, hkCpuWorldRayCastCollector *, _QWORD, unsigned __int64, unsigned __int64, _QWORD, hkVector4f *, _QWORD, __int64))v6->vfptr[12].__first_virtual_table_function__)(
    v6,
    &v12,
    collector,
    0i64,
    v12.m128_u64[0],
    v12.m128_u64[1],
    *(_QWORD *)&v13,
    v14,
    *(_QWORD *)&v15,
    v16);
}

// File Line: 132
// RVA: 0xD313C0
__int64 __fastcall hkCpuWorldRayCastJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  hkJobQueue *v2; // r14
  hkJobQueue::JobQueueEntry *v3; // rsi
  _QWORD *v4; // rax
  _QWORD *v5; // rcx
  _QWORD *v6; // r8
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  hkpWorldRayCastCommand *v9; // rbx
  __int64 v10; // rax
  __int64 v11; // rcx
  int v12; // edi
  hkpBroadPhase *v13; // rcx
  unsigned int v14; // eax
  signed __int64 v15; // rbx
  __int64 v16; // r13
  int v17; // er14
  unsigned int *v18; // r15
  unsigned __int64 *v19; // r12
  signed __int64 v20; // rdi
  hkVector4f v21; // xmm0
  hkVector4f v22; // xmm1
  hkpBroadPhase *v23; // rcx
  unsigned int v24; // eax
  _QWORD *v25; // rax
  _QWORD *v26; // rcx
  _QWORD *v27; // r8
  unsigned __int64 v28; // rax
  signed __int64 v29; // rcx
  hkpFixedBufferRayHitCollector fixedBufferHitCollector; // [rsp+20h] [rbp-C8h]
  hkpWorldRayCastCommand command; // [rsp+50h] [rbp-98h]
  int v33; // [rsp+E8h] [rbp+0h]
  __int64 v34; // [rsp+F0h] [rbp+8h]
  __int64 v35; // [rsp+F8h] [rbp+10h]
  __int64 v36; // [rsp+100h] [rbp+18h]
  __int64 v37; // [rsp+108h] [rbp+20h]
  hkJobQueue *v38; // [rsp+158h] [rbp+70h]

  v2 = jobQueue;
  v3 = nextJobOut;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  v6 = v4;
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtCollQueryWorldRayCast";
    v7 = __rdtsc();
    v8 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v8 - 8) = v7;
    v6[1] = v8;
  }
  v9 = *(hkpWorldRayCastCommand **)&v3->m_data[40];
  *(_QWORD *)&command.m_resultsCapacity = &hkCpuWorldRayCastCollector::`vftable;
  v10 = *(_QWORD *)&v3->m_data[24];
  v33 = 0;
  v34 = 0i64;
  v35 = 0i64;
  v36 = 0i64;
  v37 = 0i64;
  *(_DWORD *)(&command.m_stopAfterFirstHit + 7) = 1065353216;
  *((_BYTE *)&command.m_stopAfterFirstHit + 11) = 0;
  v11 = *(_QWORD *)(v10 + 24);
  v12 = 0;
  fixedBufferHitCollector.m_earlyOutHitFraction = 1.0;
  fixedBufferHitCollector.m_rayCastOutputBase.m_storage = 0i64;
  fixedBufferHitCollector.m_nextFreeOutput.m_storage = 0i64;
  *(_QWORD *)&command.m_useCollector.m_bool = v11;
  fixedBufferHitCollector.vfptr = (hkpRayHitCollectorVtbl *)&hkpFixedBufferRayHitCollector::`vftable;
  *(_QWORD *)&fixedBufferHitCollector.m_capacity.m_storage = 1i64;
  for ( fixedBufferHitCollector.m_collidableOnPpu.m_storage = 0i64; v12 < *(_DWORD *)&v3->m_data[48]; ++v9 )
  {
    v13 = *(hkpBroadPhase **)&v3->m_data[72];
    *(_DWORD *)(&command.m_stopAfterFirstHit + 7) = 1065353216;
    *((_BYTE *)&command.m_stopAfterFirstHit + 11) = 0;
    castRayBroadPhase(v13, v9, (hkCpuWorldRayCastCollector *)&command.m_resultsCapacity, &fixedBufferHitCollector);
    ++v12;
  }
  v14 = *(_DWORD *)&v3->m_data[64];
  if ( (signed int)v14 > 0 )
  {
    v15 = *(_QWORD *)&v3->m_data[56] + 192i64;
    v16 = v14;
    do
    {
      v17 = 0;
      if ( *(_DWORD *)v15 > 0 )
      {
        v18 = (unsigned int *)(v15 + 48);
        v19 = (unsigned __int64 *)(v15 + 8);
        v20 = v15 - 160;
        do
        {
          v21.m_quad = *(__m128 *)(v20 - 32);
          v22.m_quad = *(__m128 *)(v20 - 16);
          v23 = *(hkpBroadPhase **)&v3->m_data[72];
          command.m_rayInput.m_enableShapeCollectionFilter.m_bool = *(_BYTE *)v20;
          v24 = *(_DWORD *)(v20 + 4);
          command.m_rayInput.m_from = (hkVector4f)v21.m_quad;
          command.m_rayInput.m_to = (hkVector4f)v22.m_quad;
          command.m_rayInput.m_filterInfo = v24;
          command.m_rayInput.m_userData = *(_QWORD *)(v20 + 8);
          command.m_rayInput.m_to.m_quad.m128_u64[1] = *v19;
          LOBYTE(v24) = *(_BYTE *)(v15 + 64);
          *(_QWORD *)&command.m_rayInput.m_enableShapeCollectionFilter.m_bool = 1i64;
          *(_DWORD *)(&command.m_stopAfterFirstHit + 7) = 1065353216;
          LOWORD(command.m_rayInput.m_userData) = (unsigned __int8)v24;
          *((_BYTE *)&command.m_stopAfterFirstHit + 11) = 0;
          castRayBroadPhase(
            v23,
            &command,
            (hkCpuWorldRayCastCollector *)&command.m_resultsCapacity,
            &fixedBufferHitCollector);
          ++v17;
          ++v19;
          *v18 = command.m_rayInput.m_filterInfo;
          ++v18;
          v20 += 48i64;
        }
        while ( v17 < *(_DWORD *)v15 );
      }
      v15 += 272i64;
      --v16;
    }
    while ( v16 );
    v2 = v38;
  }
  v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v26 = (_QWORD *)v25[1];
  v27 = v25;
  if ( (unsigned __int64)v26 < v25[3] )
  {
    *v26 = "Et";
    v28 = __rdtsc();
    v29 = (signed __int64)(v26 + 2);
    *(_DWORD *)(v29 - 8) = v28;
    v27[1] = v29;
  }
  return hkJobQueue::finishJobAndGetNextJob(v2, v3, v3, 0);
}

