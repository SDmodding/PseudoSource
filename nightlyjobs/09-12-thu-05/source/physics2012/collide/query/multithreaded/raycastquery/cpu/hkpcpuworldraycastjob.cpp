// File Line: 23
// RVA: 0xD310E0
float __fastcall hkCpuWorldRayCastCollector::addBroadPhaseHandle(
        hkCpuWorldRayCastCollector *this,
        hkpBroadPhaseHandle *broadPhaseHandle,
        int castIndex)
{
  hkpCollidable *v4; // rdi
  hkpShape *m_shape; // rsi
  hkpWorldRayCastInput *m_originalInput; // rax
  hkpFixedBufferRayHitCollector *m_fixedBufferRayHitCollector; // r9
  __m128 *m_motion; // rbp
  __m128 v9; // xmm6
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm4
  __m128 v14; // xmm6
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm2
  float m_hitFraction; // xmm0_4
  unsigned __int64 m_userData; // rax
  hkBaseObjectVtbl *vfptr; // rax
  hkpWorldRayCastCommand *m_command; // rdx
  hkpWorldRayCastOutput *m_result; // rcx
  int m_numResultsOut; // eax
  float v24; // xmm3_4
  hkpWorldRayCastOutput *v25; // rdx
  __int64 v26; // r8
  int v27; // edx
  __m128 *v28; // rax
  __m128 v29; // xmm0
  hkpWorldRayCastCommand *v30; // rax
  float v31; // xmm0_4
  __m128 m_earlyOutHitFraction_low; // xmm0
  __m128 v34; // [rsp+20h] [rbp-68h] BYREF
  float v35; // [rsp+30h] [rbp-58h]
  int v36; // [rsp+34h] [rbp-54h]
  int v37; // [rsp+40h] [rbp-48h]
  int v38; // [rsp+60h] [rbp-28h]
  char v39; // [rsp+90h] [rbp+8h] BYREF

  v4 = (hkpCollidable *)((char *)broadPhaseHandle + SBYTE1(broadPhaseHandle[1].m_id));
  m_shape = v4->m_shape;
  if ( !v4->m_shape )
    return this->m_hitFraction;
  if ( this->m_filter->vfptr->isCollisionEnabled(
         &this->m_filter->hkpRayCollidableFilter,
         &v39,
         this->m_originalInput,
         v4)->m_bool )
  {
    m_originalInput = this->m_originalInput;
    m_fixedBufferRayHitCollector = this->m_fixedBufferRayHitCollector;
    m_motion = (__m128 *)v4->m_motion;
    v9 = _mm_sub_ps(m_originalInput->m_from.m_quad, m_motion[3]);
    v10 = m_motion[2];
    v11 = _mm_unpacklo_ps(*m_motion, m_motion[1]);
    v12 = _mm_movelh_ps(v11, v10);
    this->m_workInput.m_from.m_quad = _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_shuffle_ps(_mm_movehl_ps(v12, v11), v10, 212),
                                            _mm_shuffle_ps(v9, v9, 85)),
                                          _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), v12)),
                                        _mm_mul_ps(
                                          _mm_shuffle_ps(v9, v9, 170),
                                          _mm_shuffle_ps(_mm_unpackhi_ps(*m_motion, m_motion[1]), v10, 228)));
    v13 = m_motion[2];
    v14 = _mm_sub_ps(m_originalInput->m_to.m_quad, m_motion[3]);
    v15 = _mm_unpacklo_ps(*m_motion, m_motion[1]);
    v16 = _mm_shuffle_ps(_mm_unpackhi_ps(*m_motion, m_motion[1]), v13, 228);
    this->m_workInput.m_collidable = v4;
    v17 = _mm_movelh_ps(v15, v13);
    m_hitFraction = this->m_hitFraction;
    this->m_workInput.m_to.m_quad = _mm_add_ps(
                                      _mm_add_ps(
                                        _mm_mul_ps(
                                          _mm_shuffle_ps(_mm_movehl_ps(v17, v15), v13, 212),
                                          _mm_shuffle_ps(v14, v14, 85)),
                                        _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v17)),
                                      _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v16));
    m_userData = m_originalInput->m_userData;
    v35 = m_hitFraction;
    this->m_workInput.m_userData = m_userData;
    vfptr = m_shape->vfptr;
    v36 = -1;
    v38 = 0;
    v37 = -1;
    if ( m_fixedBufferRayHitCollector )
    {
      ((void (__fastcall *)(hkpShape *, hkpShapeRayCastInput *, hkpCollidable *))vfptr[3].__vecDelDtor)(
        m_shape,
        &this->m_workInput,
        v4);
      this->m_command->m_numResultsOut = this->m_fixedBufferRayHitCollector->m_numOutputs.m_storage;
      m_earlyOutHitFraction_low = (__m128)LODWORD(this->m_fixedBufferRayHitCollector->m_earlyOutHitFraction);
    }
    else
    {
      ((void (__fastcall *)(hkpShape *, char *, hkpShapeRayCastInput *, __m128 *))vfptr[2].__first_virtual_table_function__)(
        m_shape,
        &v39,
        &this->m_workInput,
        &v34);
      if ( !v39 )
        return this->m_hitFraction;
      m_command = this->m_command;
      m_result = this->m_result;
      m_numResultsOut = m_command->m_numResultsOut;
      if ( m_numResultsOut >= m_command->m_resultsCapacity )
      {
        v25 = m_result + 1;
        if ( m_numResultsOut > 1 )
        {
          v26 = (unsigned int)(m_numResultsOut - 1);
          do
          {
            if ( m_result->m_hitFraction < v25->m_hitFraction )
              m_result = v25;
            ++v25;
            --v26;
          }
          while ( v26 );
        }
        v24 = m_result->m_hitFraction;
        if ( v35 >= v24 )
          return this->m_hitFraction;
      }
      else
      {
        m_result = this->m_nextFreeResult;
        v24 = *(float *)&FLOAT_1_0;
        m_command->m_numResultsOut = m_numResultsOut + 1;
        ++this->m_nextFreeResult;
      }
      if ( !m_result )
        return this->m_hitFraction;
      v27 = 6;
      v28 = &v34;
      v34 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), m_motion[1]),
                _mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), *m_motion)),
              _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), m_motion[2]));
      do
      {
        v29 = *v28;
        --v27;
        *(__m128 *)((char *)++v28 + (char *)m_result - (char *)&v34 - 16) = v29;
      }
      while ( v27 > 0 );
      m_result->m_rootCollidable = v4;
      v30 = this->m_command;
      if ( v30->m_stopAfterFirstHit.m_bool )
      {
        v31 = 0.0;
        v35 = 0.0;
      }
      else
      {
        v31 = v35;
      }
      if ( v30->m_resultsCapacity != 1 )
        v31 = v24;
      this->m_hitFraction = v31;
      this->m_hit.m_bool = 1;
      m_earlyOutHitFraction_low = (__m128)LODWORD(this->m_hitFraction);
    }
    this->m_earlyOutHitFraction.m_quad = _mm_shuffle_ps(m_earlyOutHitFraction_low, m_earlyOutHitFraction_low, 0);
    return this->m_hitFraction;
  }
  return this->m_hitFraction;
}

// File Line: 86
// RVA: 0xD31630
void __fastcall castRayBroadPhase(
        hkpBroadPhase *broadphase,
        hkpWorldRayCastCommand *command,
        hkCpuWorldRayCastCollector *collector,
        hkpFixedBufferRayHitCollector *fixedBufferHitCollector)
{
  hkVector4f v4; // xmm0
  unsigned int m_filterInfo; // eax
  hkpWorldRayCastOutput *m_results; // rax
  hkpCollisionFilter *m_filter; // rax
  int m_resultsCapacity; // ecx
  hkpWorldRayCastOutput *v10; // rax
  hkpWorldRayCastOutput *v11; // rax
  __m128 m_quad; // [rsp+20h] [rbp-38h] BYREF
  int v13; // [rsp+30h] [rbp-28h]
  hkVector4f *p_m_to; // [rsp+38h] [rbp-20h]
  int v15; // [rsp+40h] [rbp-18h]
  __int64 v16; // [rsp+48h] [rbp-10h]

  v4.m_quad = (__m128)command->m_rayInput.m_from;
  collector->m_originalInput = &command->m_rayInput;
  p_m_to = &command->m_rayInput.m_to;
  m_filterInfo = command->m_rayInput.m_filterInfo;
  m_quad = v4.m_quad;
  collector->m_workInput.m_filterInfo = m_filterInfo;
  collector->m_result = command->m_results;
  m_results = command->m_results;
  collector->m_command = command;
  collector->m_nextFreeResult = m_results;
  v15 = 16;
  v16 = 0i64;
  v13 = 1;
  if ( command->m_rayInput.m_enableShapeCollectionFilter.m_bool )
  {
    m_filter = collector->m_filter;
    if ( m_filter )
      collector->m_workInput.m_rayShapeCollectionFilter = &m_filter->hkpRayShapeCollectionFilter;
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
      m_resultsCapacity = command->m_resultsCapacity;
      v10 = command->m_results;
      fixedBufferHitCollector->m_rayCastOutputBase.m_storage = v10;
      fixedBufferHitCollector->m_nextFreeOutput.m_storage = v10;
      fixedBufferHitCollector->m_capacity.m_storage = m_resultsCapacity;
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
  ((void (__fastcall *)(hkpBroadPhase *, __m128 *, hkCpuWorldRayCastCollector *, _QWORD))broadphase->vfptr[12].__first_virtual_table_function__)(
    broadphase,
    &m_quad,
    collector,
    0i64);
}

// File Line: 132
// RVA: 0xD313C0
__int64 __fastcall hkCpuWorldRayCastJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  _QWORD *Value; // rax
  _QWORD *v5; // rcx
  _QWORD *v6; // r8
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  hkpWorldRayCastCommand *v9; // rbx
  __int64 v10; // rax
  __int64 v11; // rcx
  int v12; // edi
  hkpBroadPhase *v13; // rcx
  int v14; // eax
  __int64 v15; // rbx
  __int64 v16; // r13
  int v17; // r14d
  unsigned int *v18; // r15
  unsigned __int64 *v19; // r12
  __int64 v20; // rdi
  hkVector4f v21; // xmm0
  hkVector4f v22; // xmm1
  hkpBroadPhase *v23; // rcx
  unsigned int v24; // eax
  _QWORD *v25; // rax
  _QWORD *v26; // rcx
  _QWORD *v27; // r8
  unsigned __int64 v28; // rax
  _QWORD *v29; // rcx
  hkpFixedBufferRayHitCollector fixedBufferHitCollector; // [rsp+20h] [rbp-C8h] BYREF
  hkpWorldRayCastCommand command; // [rsp+50h] [rbp-98h] BYREF
  int v33; // [rsp+E8h] [rbp+0h]
  __int64 v34; // [rsp+F0h] [rbp+8h]
  __int64 v35; // [rsp+F8h] [rbp+10h]
  __int64 v36; // [rsp+100h] [rbp+18h]
  __int64 v37; // [rsp+108h] [rbp+20h]
  hkJobQueue *v38; // [rsp+158h] [rbp+70h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  v6 = Value;
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtCollQueryWorldRayCast";
    v7 = __rdtsc();
    v8 = v5 + 2;
    *((_DWORD *)v8 - 2) = v7;
    v6[1] = v8;
  }
  v9 = *(hkpWorldRayCastCommand **)&nextJobOut->m_data[40];
  *(_QWORD *)&command.m_resultsCapacity = &hkCpuWorldRayCastCollector::`vftable;
  v10 = *(_QWORD *)&nextJobOut->m_data[24];
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
  for ( fixedBufferHitCollector.m_collidableOnPpu.m_storage = 0i64; v12 < *(_DWORD *)&nextJobOut->m_data[48]; ++v9 )
  {
    v13 = *(hkpBroadPhase **)&nextJobOut->m_data[72];
    *(_DWORD *)(&command.m_stopAfterFirstHit + 7) = 1065353216;
    *((_BYTE *)&command.m_stopAfterFirstHit + 11) = 0;
    castRayBroadPhase(v13, v9, (hkCpuWorldRayCastCollector *)&command.m_resultsCapacity, &fixedBufferHitCollector);
    ++v12;
  }
  v14 = *(_DWORD *)&nextJobOut->m_data[64];
  if ( v14 > 0 )
  {
    v15 = *(_QWORD *)&nextJobOut->m_data[56] + 192i64;
    v16 = (unsigned int)v14;
    do
    {
      v17 = 0;
      if ( *(int *)v15 > 0 )
      {
        v18 = (unsigned int *)(v15 + 48);
        v19 = (unsigned __int64 *)(v15 + 8);
        v20 = v15 - 160;
        do
        {
          v21.m_quad = *(__m128 *)(v20 - 32);
          v22.m_quad = *(__m128 *)(v20 - 16);
          v23 = *(hkpBroadPhase **)&nextJobOut->m_data[72];
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
          *v18++ = command.m_rayInput.m_filterInfo;
          v20 += 48i64;
        }
        while ( v17 < *(_DWORD *)v15 );
      }
      v15 += 272i64;
      --v16;
    }
    while ( v16 );
    jobQueue = v38;
  }
  v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v26 = (_QWORD *)v25[1];
  v27 = v25;
  if ( (unsigned __int64)v26 < v25[3] )
  {
    *v26 = "Et";
    v28 = __rdtsc();
    v29 = v26 + 2;
    *((_DWORD *)v29 - 2) = v28;
    v27[1] = v29;
  }
  return hkJobQueue::finishJobAndGetNextJob(jobQueue, nextJobOut, nextJobOut, WAIT_FOR_NEXT_JOB);
}

