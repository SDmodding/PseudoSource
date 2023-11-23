// File Line: 32
// RVA: 0xBE1530
void __fastcall collectNavMeshBoundaries(
        hkaiCharacter *character,
        hkaiStreamingCollection::InstanceInfo *sectionInfo,
        unsigned int navMeshFaceKey,
        hkaiObstacleCollector *collector)
{
  hkaiAvoidanceProperties *m_pntr; // rax
  hkVector4f *position; // rdi
  hkVector4f v9; // xmm0
  hkVector4f v10; // xmm1
  hkLifoAllocator *Value; // rax
  hkVector4f *m_cur; // rdx
  hkVector4f *v14; // rcx
  unsigned int m_agentFilterInfo; // eax
  float m_radius; // xmm0_4
  hkaiAvoidanceProperties *v17; // rax
  int m_size; // ecx
  int v19; // edi
  int v20; // ebx
  char *v21; // rdi
  signed int v22; // ebx
  hkLifoAllocator *v23; // rax
  int v24; // r8d
  hkArrayBase<hkVector4f> boundariesOut; // [rsp+50h] [rbp-9h] BYREF
  void *p; // [rsp+60h] [rbp+7h]
  int v27; // [rsp+68h] [rbp+Fh]
  hkAabb aabb; // [rsp+70h] [rbp+17h] BYREF
  hkaiAgentTraversalInfo traversalInfo; // [rsp+C0h] [rbp+67h] BYREF

  m_pntr = character->m_avoidanceProperties.m_pntr;
  position = &character->m_position;
  v9.m_quad = _mm_add_ps(character->m_position.m_quad, m_pntr->m_localSensorAabb.m_min.m_quad);
  v10.m_quad = _mm_add_ps(character->m_position.m_quad, m_pntr->m_localSensorAabb.m_max.m_quad);
  boundariesOut.m_capacityAndFlags = 0x80000000;
  v27 = 32;
  aabb.m_min = (hkVector4f)v9.m_quad;
  aabb.m_max = (hkVector4f)v10.m_quad;
  boundariesOut.m_data = 0i64;
  boundariesOut.m_size = 0;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkVector4f *)Value->m_cur;
  v14 = m_cur + 32;
  if ( Value->m_slabSize < 512 || v14 > Value->m_end )
    m_cur = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(Value, 512);
  else
    Value->m_cur = v14;
  m_agentFilterInfo = character->m_agentFilterInfo;
  m_radius = character->m_radius;
  boundariesOut.m_data = m_cur;
  traversalInfo.m_filterInfo = m_agentFilterInfo;
  v17 = character->m_avoidanceProperties.m_pntr;
  p = m_cur;
  traversalInfo.m_diameter = m_radius * 2.0;
  boundariesOut.m_capacityAndFlags = -2147483616;
  hkaiNavMeshUtils::getNearbyBoundaries(
    sectionInfo,
    navMeshFaceKey,
    &aabb,
    &traversalInfo,
    character->m_edgeFilter.m_pntr,
    v17->m_nearbyBoundariesSearchType.m_storage == 1,
    position,
    &character->m_up,
    &boundariesOut);
  m_size = boundariesOut.m_size;
  v19 = 0;
  if ( boundariesOut.m_size / 2 > 0 )
  {
    v20 = 0;
    do
    {
      hkaiObstacleCollector::addBoundary(collector, &boundariesOut.m_data[v20], &boundariesOut.m_data[v20 + 1]);
      m_size = boundariesOut.m_size;
      ++v19;
      v20 += 2;
    }
    while ( v19 < boundariesOut.m_size / 2 );
  }
  v21 = (char *)p;
  if ( p == boundariesOut.m_data )
    m_size = 0;
  boundariesOut.m_size = m_size;
  v22 = (16 * v27 + 127) & 0xFFFFFF80;
  v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v24 = (v22 + 15) & 0xFFFFFFF0;
  if ( v22 > v23->m_slabSize || &v21[v24] != v23->m_cur || v23->m_firstNonLifoEnd == v21 )
    hkLifoAllocator::slowBlockFree(v23, v21, v24);
  else
    v23->m_cur = v21;
  boundariesOut.m_size = 0;
  if ( boundariesOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      boundariesOut.m_data,
      16 * boundariesOut.m_capacityAndFlags);
}

// File Line: 53
// RVA: 0xBE1740
void __fastcall processObstacleGenerators(
        hkaiCharacter *character,
        hkArrayBase<hkaiObstacleGenerator const *> *obstacleGenerators,
        hkaiObstacleCollector *collector)
{
  hkaiAvoidanceProperties *m_pntr; // rax
  int v4; // ebx
  hkVector4f v7; // xmm2
  __int64 v8; // rdi
  hkAabb sensorAabb; // [rsp+20h] [rbp-28h] BYREF

  m_pntr = character->m_avoidanceProperties.m_pntr;
  v4 = 0;
  v7.m_quad = _mm_add_ps(character->m_position.m_quad, m_pntr->m_localSensorAabb.m_max.m_quad);
  sensorAabb.m_min.m_quad = _mm_add_ps(character->m_position.m_quad, m_pntr->m_localSensorAabb.m_min.m_quad);
  sensorAabb.m_max = (hkVector4f)v7.m_quad;
  if ( obstacleGenerators->m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      hkaiObstacleGenerator::appendObstacles(obstacleGenerators->m_data[v8], &sensorAabb, collector);
      ++v4;
      ++v8;
    }
    while ( v4 < obstacleGenerators->m_size );
  }
}

// File Line: 85
// RVA: 0xBDE3C0
void __fastcall hkaiAvoidanceSolverUtils::setupAgent(
        hkaiLocalSteeringInput *steeringInput,
        hkaiObstacleCollector *sectionInfo,
        unsigned int navMeshFaceKey,
        float erosionRadius)
{
  hkaiLocalSteeringInput *v4; // rsi
  _QWORD *Value; // r10
  unsigned __int64 v8; // r9
  unsigned __int64 v9; // rax
  hkaiCharacter *m_character; // r13
  __m128 m_quad; // xmm9
  char m_storage; // bl
  int v13; // r14d
  hkArrayBase<hkaiObstacleGenerator const *> *v14; // rsi
  bool v15; // zf
  _QWORD *v16; // rdi
  char v17; // di
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  _QWORD *v21; // rcx
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm7
  __m128 v26; // xmm6
  __m128 v27; // xmm2
  __m128 v28; // xmm6
  __m128 v29; // xmm1
  __m128 v30; // xmm5
  __m128 v31; // xmm4
  hkVector4f v32; // xmm0
  unsigned int m_size; // eax
  _QWORD *v34; // r8
  _QWORD *v35; // rcx
  unsigned __int64 v36; // rax
  _QWORD *v37; // rcx
  signed int v38; // r11d
  hkaiReferenceFrame *v39; // rbx
  unsigned __int64 v40; // rcx
  __int64 v41; // rsi
  __int64 v42; // rdi
  __m128 v43; // xmm0
  __m128 v44; // xmm3
  hkaiNavVolumeMediator *m_data; // r10
  __m128 v46; // xmm2
  __m128 v47; // xmm2
  __m128 v48; // xmm2
  int v49; // xmm0_4
  __int64 v50; // r8
  __int64 v51; // rax
  _DWORD *v52; // r9
  _DWORD *v53; // rcx
  __int64 v54; // rax
  int v55; // xmm1_4
  int v56; // xmm0_4
  int v57; // eax
  int v58; // eax
  float m_radius; // xmm0_4
  __int64 v60; // r9
  __int64 v61; // rcx
  _DWORD *v62; // r10
  _DWORD *v63; // rax
  int v64; // xmm1_4
  int v65; // xmm0_4
  _QWORD *v66; // r8
  _QWORD *v67; // rcx
  unsigned __int64 v68; // rax
  _QWORD *v69; // rcx
  hkVector4f worldDir; // [rsp+48h] [rbp-80h] BYREF
  hkVector4f localDirOut; // [rsp+58h] [rbp-70h] BYREF
  _BYTE localPosOut[160]; // [rsp+68h] [rbp-60h] BYREF
  hkaiLocalSteeringInput *v73; // [rsp+118h] [rbp+50h]
  hkaiStreamingCollection::InstanceInfo *sectionInfoa; // [rsp+120h] [rbp+58h]
  unsigned int navMeshFaceKeya; // [rsp+128h] [rbp+60h]
  __int64 v76; // [rsp+138h] [rbp+70h]
  hkArrayBase<hkaiObstacleGenerator const *> *vars0; // [rsp+140h] [rbp+78h]
  int *retaddr; // [rsp+148h] [rbp+80h]

  v4 = steeringInput;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = Value[1];
  if ( v8 < Value[3] )
  {
    *(_QWORD *)v8 = "LtsetupAgent";
    *(_QWORD *)(v8 + 16) = "Stinit";
    v9 = __rdtsc();
    *(_DWORD *)(v8 + 8) = v9;
    Value[1] = v8 + 24;
  }
  m_character = v4->m_character;
  m_quad = v4->m_currentUp.m_quad;
  m_storage = m_character->m_avoidanceEnabledMask.m_storage;
  v13 = 0;
  worldDir.m_quad.m128_i8[9] = m_storage;
  if ( (m_storage & 7) == 0 )
    goto LABEL_8;
  v14 = vars0;
  v15 = navMeshFaceKey == -1;
  v16 = (_QWORD *)v76;
  if ( v15 && !*(_DWORD *)(v76 + 8) && !vars0->m_size )
  {
    v4 = v73;
LABEL_8:
    v17 = 0;
    goto LABEL_9;
  }
  worldDir.m_quad.m128_i8[8] = 1;
  v34 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v35 = (_QWORD *)v34[1];
  if ( (unsigned __int64)v35 < v34[3] )
  {
    *v35 = "StobstacleSetup";
    v36 = __rdtsc();
    v37 = v35 + 2;
    *((_DWORD *)v37 - 2) = v36;
    v34[1] = v37;
  }
  localDirOut.m_quad.m128_u64[1] = (unsigned __int64)v73->m_referenceFrame;
  sectionInfo->m_referenceFrame = (hkaiReferenceFrame *)localDirOut.m_quad.m128_u64[1];
  if ( (m_storage & 1) != 0 )
    collectNavMeshBoundaries(m_character, sectionInfoa, navMeshFaceKeya, sectionInfo);
  if ( (m_storage & 4) != 0 )
    processObstacleGenerators(m_character, v14, sectionInfo);
  sectionInfo->m_referenceFrame = 0i64;
  if ( (m_storage & 2) != 0 )
  {
    v38 = 0;
    worldDir.m_quad.m128_i32[3] = 0;
    if ( sectionInfo->m_neighborAgents.m_size > 0 )
    {
      v39 = (hkaiReferenceFrame *)localDirOut.m_quad.m128_u64[1];
      v40 = 0i64;
      localDirOut.m_quad.m128_u64[0] = 0i64;
      v41 = 0i64;
      do
      {
        v42 = *(_QWORD *)(v40 + *v16);
        if ( m_character->m_avoidanceProperties.m_pntr->m_movementProperties.m_kinematicConstraintType.m_storage == 1 )
          v43 = *(__m128 *)(v42 + 48);
        else
          v43 = 0i64;
        worldDir.m_quad = v43;
        if ( v39 )
        {
          hkaiReferenceFrame::transformWorldPosDirVelToLocalPosDirVel(
            v39,
            (hkVector4f *)(v42 + 32),
            &worldDir,
            (hkVector4f *)(v42 + 64),
            (hkVector4f *)(v42 + 80),
            (hkVector4f *)localPosOut,
            &localDirOut,
            (hkVector4f *)&localPosOut[8],
            (hkVector4f *)&localPosOut[16]);
          v38 = worldDir.m_quad.m128_i32[3];
          v40 = localDirOut.m_quad.m128_u64[0];
          v44 = *(__m128 *)localPosOut;
        }
        else
        {
          v44 = *(__m128 *)(v42 + 32);
          localDirOut.m_quad = v43;
          *(__m128 *)localPosOut = v44;
          *(_OWORD *)&localPosOut[8] = *(_OWORD *)(v42 + 64);
          *(_OWORD *)&localPosOut[16] = *(_OWORD *)(v42 + 80);
        }
        m_data = (hkaiNavVolumeMediator *)sectionInfo->m_neighborAgents.m_data;
        v46 = _mm_mul_ps(m_quad, v44);
        m_data[v41] = (hkaiNavVolumeMediator)_mm_add_ps(
                                               _mm_mul_ps(
                                                 _mm_sub_ps(
                                                   (__m128)0i64,
                                                   _mm_add_ps(
                                                     _mm_add_ps(
                                                       _mm_shuffle_ps(v46, v46, 85),
                                                       _mm_shuffle_ps(v46, v46, 0)),
                                                     _mm_shuffle_ps(v46, v46, 170))),
                                                 m_quad),
                                               v44);
        v47 = _mm_mul_ps(m_quad, *(__m128 *)&localPosOut[8]);
        m_data[v41 + 1] = (hkaiNavVolumeMediator)_mm_add_ps(
                                                   _mm_mul_ps(
                                                     _mm_sub_ps(
                                                       (__m128)0i64,
                                                       _mm_add_ps(
                                                         _mm_add_ps(
                                                           _mm_shuffle_ps(v47, v47, 85),
                                                           _mm_shuffle_ps(v47, v47, 0)),
                                                         _mm_shuffle_ps(v47, v47, 170))),
                                                     m_quad),
                                                   *(__m128 *)&localPosOut[8]);
        v48 = _mm_mul_ps(m_quad, localDirOut.m_quad);
        m_data[v41 + 2] = (hkaiNavVolumeMediator)_mm_add_ps(
                                                   _mm_mul_ps(
                                                     _mm_sub_ps(
                                                       (__m128)0i64,
                                                       _mm_add_ps(
                                                         _mm_add_ps(
                                                           _mm_shuffle_ps(v48, v48, 85),
                                                           _mm_shuffle_ps(v48, v48, 0)),
                                                         _mm_shuffle_ps(v48, v48, 170))),
                                                     m_quad),
                                                   localDirOut.m_quad);
        m_data[v41 + 3].vfptr = *(hkBaseObjectVtbl **)(v42 + 152);
        m_data[v41 + 3].m_memSizeAndFlags = *(_WORD *)(v42 + 164);
        v49 = *(_DWORD *)(v42 + 100);
        HIDWORD(m_data[v41 + 4].vfptr) = 1056964608;
        *(_DWORD *)(&m_data[v41 + 3].m_referenceCount + 1) = v49;
        LODWORD(m_data[v41 + 4].vfptr) = v49;
        if ( retaddr )
        {
          v50 = retaddr[6];
          v51 = 0i64;
          if ( v50 > 0 )
          {
            v52 = (_DWORD *)*((_QWORD *)retaddr + 2);
            v53 = v52;
            while ( *(unsigned __int16 *)(v42 + 168) + (m_character->m_avoidanceType << 16) != *v53 )
            {
              ++v51;
              v53 += 3;
              if ( v51 >= v50 )
                goto LABEL_35;
            }
            v54 = 3 * v51;
            v55 = v52[v54 + 1];
            localDirOut.m_quad.m128_i32[2] = v52[v54];
            v56 = v52[v54 + 2];
            HIDWORD(m_data[v41 + 4].vfptr) = v55;
            *(_DWORD *)localPosOut = v56;
LABEL_35:
            v40 = localDirOut.m_quad.m128_u64[0];
          }
        }
        v16 = (_QWORD *)v76;
        ++v38;
        v40 += 8i64;
        v41 += 5i64;
        worldDir.m_quad.m128_i32[3] = v38;
        localDirOut.m_quad.m128_u64[0] = v40;
      }
      while ( v38 < sectionInfo->m_neighborAgents.m_size );
      m_storage = worldDir.m_quad.m128_i8[9];
    }
  }
  v4 = v73;
  v17 = worldDir.m_quad.m128_i8[8];
LABEL_9:
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  if ( (unsigned __int64)v19 < v18[3] )
  {
    *v19 = "StagentSetup";
    v20 = __rdtsc();
    v21 = v19 + 2;
    *((_DWORD *)v21 - 2) = v20;
    v18[1] = v21;
  }
  v22 = _mm_mul_ps(m_quad, v4->m_currentVelocity.m_quad);
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)), _mm_shuffle_ps(v22, v22, 170));
  v24 = _mm_mul_ps(m_quad, v4->m_currentForward.m_quad);
  v25 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, v23), m_quad);
  v26 = _mm_sub_ps(
          (__m128)0i64,
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
            _mm_shuffle_ps(v24, v24, 170)));
  v27 = _mm_mul_ps(m_quad, v4->m_currentPosition.m_quad);
  v28 = _mm_add_ps(_mm_mul_ps(v26, m_quad), v4->m_currentForward.m_quad);
  v29 = _mm_mul_ps(v28, v28);
  v30 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)), _mm_shuffle_ps(v29, v29, 170));
  v31 = _mm_rsqrt_ps(v30);
  v32.m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(
                     (__m128)0i64,
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                       _mm_shuffle_ps(v27, v27, 170))),
                   m_quad),
                 v4->m_currentPosition.m_quad);
  steeringInput->m_currentForward.m_quad = _mm_add_ps(v25, v4->m_currentVelocity.m_quad);
  steeringInput->m_currentPosition = (hkVector4f)v32.m_quad;
  steeringInput->m_currentUp.m_quad = _mm_mul_ps(
                                        _mm_andnot_ps(
                                          _mm_cmple_ps(v30, (__m128)0i64),
                                          _mm_mul_ps(
                                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                                            _mm_mul_ps(*(__m128 *)_xmm, v31))),
                                        v28);
  steeringInput->m_desiredFutureDir = v4->m_currentPosition;
  steeringInput->m_localGoalPlane = v4->m_currentForward;
  *(hkVector4f *)&steeringInput->m_distToLocalGoal = v4->m_currentUp;
  *(hkVector4f *)&steeringInput->m_referenceFrame = v4->m_currentVelocity;
  *(hkVector4f *)&steeringInput->m_isLocalGoalLast.m_bool = v4->m_desiredVelocity;
  steeringInput[1].m_currentPosition = v4->m_desiredFutureDir;
  steeringInput[1].m_currentForward = v4->m_localGoalPlane;
  steeringInput[1].m_currentUp.m_quad.m128_i32[0] = LODWORD(v4->m_distToLocalGoal);
  steeringInput[1].m_currentUp.m_quad.m128_i32[1] = LODWORD(v4->m_timeToLocalGoal);
  steeringInput[1].m_currentUp.m_quad.m128_u64[1] = (unsigned __int64)v4->m_character;
  steeringInput[1].m_currentVelocity.m_quad.m128_u64[0] = (unsigned __int64)v4->m_referenceFrame;
  steeringInput[1].m_currentVelocity.m_quad.m128_u64[1] = (unsigned __int64)v4->m_avoidanceProperties;
  steeringInput[1].m_desiredVelocity.m_quad.m128_i8[0] = v4->m_isLocalGoalLast.m_bool;
  steeringInput[1].m_desiredVelocity.m_quad.m128_i8[1] = v4->m_applyKinematicConstraints.m_bool;
  steeringInput[1].m_desiredVelocity.m_quad.m128_i8[2] = v4->m_applyAvoidanceSteering.m_bool;
  steeringInput[1].m_desiredVelocity.m_quad.m128_i8[3] = v4->m_enableLocalSteering.m_bool;
  steeringInput->m_currentVelocity.m_quad.m128_u64[0] = (unsigned __int64)m_character->m_avoidanceProperties.m_pntr;
  if ( (m_storage & 2) != 0 )
    m_size = sectionInfo->m_neighborAgents.m_size;
  else
    m_size = 0;
  steeringInput[1].m_desiredFutureDir.m_quad.m128_i32[2] = m_size;
  if ( (m_storage & 5) != 0 )
    v57 = sectionInfo->m_boundaries.m_size;
  else
    v57 = 0;
  steeringInput[1].m_localGoalPlane.m_quad.m128_i32[2] = v57;
  if ( (m_storage & 4) != 0 )
    v58 = sectionInfo->m_spheres.m_size;
  else
    v58 = 0;
  LODWORD(steeringInput[1].m_character) = v58;
  if ( v17 )
  {
    steeringInput[1].m_desiredFutureDir.m_quad.m128_u64[0] = (unsigned __int64)sectionInfo->m_neighborAgents.m_data;
    steeringInput[1].m_localGoalPlane.m_quad.m128_u64[0] = (unsigned __int64)sectionInfo->m_boundaries.m_data;
    *(_QWORD *)&steeringInput[1].m_distToLocalGoal = sectionInfo->m_spheres.m_data;
    steeringInput->m_currentVelocity.m_quad.m128_i16[4] = m_character->m_agentPriority;
    m_radius = m_character->m_radius;
    steeringInput->m_desiredVelocity.m_quad.m128_i32[1] = 1056964608;
    steeringInput->m_currentVelocity.m_quad.m128_f32[3] = m_radius;
    LODWORD(v73) = 0;
    steeringInput->m_desiredVelocity.m_quad.m128_f32[0] = fmaxf(0.0, m_radius - erosionRadius);
    if ( retaddr )
    {
      v60 = retaddr[6];
      v61 = 0i64;
      if ( v60 > 0 )
      {
        v62 = (_DWORD *)*((_QWORD *)retaddr + 2);
        v63 = v62;
        while ( 65537 * m_character->m_avoidanceType != *v63 )
        {
          ++v61;
          ++v13;
          v63 += 3;
          if ( v61 >= v60 )
            goto LABEL_54;
        }
        v64 = v62[3 * v13 + 1];
        localDirOut.m_quad.m128_i32[2] = v62[3 * v13];
        v65 = v62[3 * v13 + 2];
        steeringInput->m_desiredVelocity.m_quad.m128_i32[1] = v64;
        *(_DWORD *)localPosOut = v65;
      }
    }
LABEL_54:
    BYTE4(steeringInput[1].m_character) = 0;
  }
  v66 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v67 = (_QWORD *)v66[1];
  if ( (unsigned __int64)v67 < v66[3] )
  {
    *v67 = "lt";
    v68 = __rdtsc();
    v69 = v67 + 2;
    *((_DWORD *)v69 - 2) = v68;
    v66[1] = v69;
  }
}

// File Line: 267
// RVA: 0xBE11C0
void __fastcall hkaiAvoidanceSolverUtils::manageAgentPenetration(
        float timestep,
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkaiAvoidanceSolver::ObstacleAgent *obstacle,
        hkaiAvoidanceSolver::ControlGradient *gradient)
{
  __m128 v5; // xmm5
  __m128 v6; // xmm2
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v10; // xmm5
  float v11; // xmm4_4
  __m128 v12; // xmm1
  __m128 v13; // xmm0

  v5 = _mm_sub_ps(obstacle->m_position.m_quad, agent->m_position.m_quad);
  v6 = _mm_mul_ps(v5, v5);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v8 = _mm_rsqrt_ps(v7);
  v9 = _mm_andnot_ps(
         _mm_cmple_ps(v7, (__m128)0i64),
         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)), _mm_mul_ps(*(__m128 *)_xmm, v8)));
  v10 = _mm_mul_ps(v5, v9);
  v11 = (float)(agent->m_radius + obstacle->m_radius) - (float)(v9.m128_f32[0] * v7.m128_f32[0]);
  if ( v11 > 0.0 )
  {
    v12 = _mm_mul_ps(agent->m_velocity.m_quad, v10);
    v13 = 0u;
    v13.m128_i32[0] = COERCE_UNSIGNED_INT(
                        fminf(
                          fmaxf(
                            (float)((float)(fminf(
                                              fmaxf(
                                                (float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0]
                                                      + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])
                                              + _mm_shuffle_ps(v12, v12, 170).m128_f32[0],
                                                timestep),
                                              1.0)
                                          * 0.5)
                                  * v11)
                          / timestep,
                            0.0),
                          (float)(timestep * 2.0) * agent->m_avoidanceProperties->m_movementProperties.m_maxDeceleration)) ^ _xmm[0];
    gradient->m_repulsion.m_quad = _mm_add_ps(
                                     _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v10),
                                     gradient->m_repulsion.m_quad);
    gradient->m_repulsion.m_quad.m128_f32[3] = v11;
  }
}

// File Line: 303
// RVA: 0xBE1310
void __fastcall hkaiAvoidanceSolverUtils::manageObstaclePenetration(
        float timestep,
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkaiAvoidanceSolver::SphereObstacle *obstacle,
        hkaiAvoidanceSolver::ControlGradient *gradient)
{
  __m128 v5; // xmm5
  __m128 v6; // xmm2
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v10; // xmm5
  float v11; // xmm4_4
  __m128 v12; // xmm1
  __m128 v13; // xmm0

  v5 = _mm_sub_ps(obstacle->m_sphere.m_pos.m_quad, agent->m_position.m_quad);
  v6 = _mm_mul_ps(v5, v5);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v8 = _mm_rsqrt_ps(v7);
  v9 = _mm_andnot_ps(
         _mm_cmple_ps(v7, (__m128)0i64),
         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)), _mm_mul_ps(*(__m128 *)_xmm, v8)));
  v10 = _mm_mul_ps(v5, v9);
  v11 = (float)(agent->m_radius + obstacle->m_sphere.m_pos.m_quad.m128_f32[3])
      - (float)(v9.m128_f32[0] * v7.m128_f32[0]);
  if ( v11 > 0.0 )
  {
    v12 = _mm_mul_ps(agent->m_velocity.m_quad, v10);
    v13 = (__m128)COERCE_UNSIGNED_INT(
                    fminf(
                      fmaxf(
                        (float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0] + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])
                      + _mm_shuffle_ps(v12, v12, 170).m128_f32[0],
                        timestep * agent->m_avoidanceProperties->m_movementProperties.m_maxDeceleration),
                      agent->m_avoidanceProperties->m_movementProperties.m_maxVelocity)
                  * 0.5);
    v13.m128_i32[0] = COERCE_UNSIGNED_INT(fminf(fmaxf(v11 / timestep, 0.0), v13.m128_f32[0])) ^ _xmm[0];
    gradient->m_repulsion.m_quad = _mm_add_ps(
                                     _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v10),
                                     gradient->m_repulsion.m_quad);
    gradient->m_repulsion.m_quad.m128_f32[3] = v11;
  }
}

// File Line: 327
// RVA: 0xBE1450
void __fastcall hkaiAvoidanceSolverUtils::manageBoundaryPenetration(
        float timestep,
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkVector4f *boundaryPlane,
        const float closestDist,
        hkaiAvoidanceSolver::ControlGradient *gradient)
{
  float v5; // xmm4_4
  __m128 v6; // xmm1
  __m128 v7; // xmm2
  float v8; // [rsp+38h] [rbp+20h]

  v5 = agent->m_boundaryRadius - closestDist;
  if ( v5 > 0.0 )
  {
    v6 = _mm_mul_ps(agent->m_velocity.m_quad, boundaryPlane->m_quad);
    v8 = (float)(fminf(
                   fmaxf(
                     COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                    (float)(_mm_shuffle_ps(v6, v6, 85).m128_f32[0]
                                          + _mm_shuffle_ps(v6, v6, 0).m128_f32[0])
                                  + _mm_shuffle_ps(v6, v6, 170).m128_f32[0]) ^ _xmm[0]),
                     timestep),
                   1.0)
               * v5)
       / timestep;
    v7 = (__m128)LODWORD(v8);
    v7.m128_f32[0] = fminf(
                       fmaxf(v8, 0.0),
                       (float)(timestep * 3.0) * agent->m_avoidanceProperties->m_movementProperties.m_maxAcceleration);
    gradient->m_repulsion.m_quad = _mm_add_ps(
                                     _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), boundaryPlane->m_quad),
                                     gradient->m_repulsion.m_quad);
    gradient->m_repulsion.m_quad.m128_f32[3] = v5;
  }
}

// File Line: 368
// RVA: 0xBDEAF0
void __fastcall hkaiAvoidanceSolverUtils::applyKinematicConstraints(
        float timestep,
        hkaiMovementProperties *movementLimits,
        hkVector4f *up,
        hkVector4f *oldVelocity,
        hkVector4f *oldForward,
        hkVector4f *desiredVelocity,
        hkVector4f *constrainedVelocity,
        bool limitEnabled)
{
  __m128 v8; // xmm14
  char m_storage; // al
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm10
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm9
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // xmm4
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  __m128 v27; // xmm5
  __m128 v28; // xmm9
  __m128 v29; // xmm1
  __m128 m_maxAcceleration_low; // xmm1
  __m128 v31; // xmm5
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  __m128 m_quad; // xmm4
  __m128 v37; // xmm1
  __m128 v38; // xmm3
  __m128 v39; // xmm2
  float v40; // xmm11_4
  __m128 v41; // xmm1
  float v42; // xmm13_4
  __m128 v43; // xmm1
  __m128 v44; // xmm2
  __m128 v45; // xmm1
  __m128 v46; // xmm14
  __m128 v47; // xmm15
  __m128 v48; // xmm5
  __m128 v49; // xmm2
  float v50; // xmm15_4
  __m128 v51; // xmm9
  __m128 v52; // xmm7
  __m128 v53; // xmm2
  __m128 v54; // xmm5
  __m128 v55; // xmm4
  __m128 v56; // xmm3
  __m128 v57; // xmm2
  __m128 v58; // xmm1
  __m128 v59; // xmm5
  __m128 v60; // xmm2
  __m128 v61; // xmm10
  __m128 v62; // xmm10
  float v63; // xmm2_4
  float v64; // xmm1_4
  __m128 v65; // xmm2
  hkVector4f vel; // [rsp+30h] [rbp-99h] BYREF
  hkQuaternionf quat; // [rsp+40h] [rbp-89h] BYREF
  __m128 v68; // [rsp+60h] [rbp-69h]
  float m_maxTurnVelocity; // [rsp+118h] [rbp+4Fh]
  float m_minVelocity; // [rsp+118h] [rbp+4Fh]

  m_storage = movementLimits->m_kinematicConstraintType.m_storage;
  if ( m_storage )
  {
    if ( m_storage == 2 )
    {
      v14 = _mm_mul_ps(oldVelocity->m_quad, up->m_quad);
      v15 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
              _mm_shuffle_ps(v14, v14, 170));
      v16 = _mm_mul_ps(up->m_quad, desiredVelocity->m_quad);
      v17 = _mm_sub_ps(oldVelocity->m_quad, _mm_mul_ps(v15, up->m_quad));
      v18 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
              _mm_shuffle_ps(v16, v16, 170));
      v19 = _mm_mul_ps(v17, v17);
      v20 = _mm_sub_ps(_mm_sub_ps(desiredVelocity->m_quad, _mm_mul_ps(v18, up->m_quad)), v17);
      v21 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
              _mm_shuffle_ps(v19, v19, 170));
      v22 = _mm_rsqrt_ps(v21);
      v23 = _mm_mul_ps(v20, v20);
      v24 = _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmple_ps(v21, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                  _mm_mul_ps(*(__m128 *)_xmm, v22))),
              v17);
      v25 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
              _mm_shuffle_ps(v23, v23, 170));
      v26 = _mm_rsqrt_ps(v25);
      v27 = _mm_andnot_ps(
              _mm_cmple_ps(v25, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                _mm_mul_ps(*(__m128 *)_xmm, v26)));
      v28 = _mm_mul_ps(v20, v27);
      v29 = _mm_mul_ps(v28, v24);
      v26.m128_f32[0] = (float)(_mm_shuffle_ps(v29, v29, 85).m128_f32[0] + _mm_shuffle_ps(v29, v29, 0).m128_f32[0])
                      + _mm_shuffle_ps(v29, v29, 170).m128_f32[0];
      m_maxAcceleration_low = (__m128)LODWORD(movementLimits->m_maxAcceleration);
      m_maxAcceleration_low.m128_f32[0] = (float)((float)((float)((float)(m_maxAcceleration_low.m128_f32[0]
                                                                        - movementLimits->m_maxDeceleration)
                                                                * (float)(v26.m128_f32[0] - -1.0))
                                                        * 0.5)
                                                + movementLimits->m_maxDeceleration)
                                        * timestep;
      v31 = _mm_add_ps(
              _mm_mul_ps(
                _mm_min_ps(_mm_mul_ps(v27, v25), _mm_shuffle_ps(m_maxAcceleration_low, m_maxAcceleration_low, 0)),
                v28),
              v17);
      v32 = _mm_mul_ps(v31, v31);
      v33 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
              _mm_shuffle_ps(v32, v32, 170));
      v34 = _mm_rsqrt_ps(v33);
      v35 = _mm_andnot_ps(
              _mm_cmple_ps(v33, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
                _mm_mul_ps(*(__m128 *)_xmm, v34)));
      constrainedVelocity->m_quad = _mm_mul_ps(
                                      _mm_min_ps(
                                        _mm_mul_ps(v35, v33),
                                        _mm_shuffle_ps(
                                          (__m128)LODWORD(movementLimits->m_maxVelocity),
                                          (__m128)LODWORD(movementLimits->m_maxVelocity),
                                          0)),
                                      _mm_mul_ps(v31, v35));
    }
    else
    {
      m_quad = desiredVelocity->m_quad;
      v37 = _mm_mul_ps(m_quad, m_quad);
      v38 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
              _mm_shuffle_ps(v37, v37, 170));
      v39 = _mm_rsqrt_ps(v38);
      v40 = _mm_andnot_ps(
              _mm_cmple_ps(v38, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
                  _mm_mul_ps(*(__m128 *)_xmm, v39)),
                v38)).m128_f32[0];
      if ( v40 <= 0.001 )
      {
        *constrainedVelocity = (hkVector4f)m_quad;
      }
      else
      {
        v41 = oldVelocity->m_quad;
        v68 = v8;
        v42 = timestep * movementLimits->m_maxAngularVelocity;
        v43 = _mm_mul_ps(v41, v41);
        v8.m128_f32[0] = 1.0 / v40;
        v44 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                _mm_shuffle_ps(v43, v43, 170));
        v45 = _mm_rsqrt_ps(v44);
        v46 = _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), m_quad);
        v47 = _mm_cmple_ps(v44, (__m128)0i64);
        v48 = _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v45, v44), v45)),
                  _mm_mul_ps(*(__m128 *)_xmm, v45)),
                v44);
        v49 = _mm_mul_ps(v46, oldForward->m_quad);
        LODWORD(v50) = _mm_andnot_ps(v47, v48).m128_u32[0];
        v51 = _mm_min_ps(
                _mm_max_ps(
                  (__m128)COERCE_UNSIGNED_INT(
                            (float)(_mm_shuffle_ps(v49, v49, 85).m128_f32[0] + _mm_shuffle_ps(v49, v49, 0).m128_f32[0])
                          + _mm_shuffle_ps(v49, v49, 170).m128_f32[0]),
                  *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
                *(__m128 *)_xmm);
        v52 = _mm_andnot_ps(*(__m128 *)_xmm, v51);
        v53 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v52), *(__m128 *)_xmm);
        v54 = _mm_cmplt_ps(*(__m128 *)_xmm, v52);
        v55 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v53), v54), _mm_andnot_ps(v54, v52));
        v56 = _mm_or_ps(_mm_andnot_ps(v54, _mm_mul_ps(v52, v52)), _mm_and_ps(v54, v53));
        v57 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v56, *(__m128 *)coeff4), *(__m128 *)coeff3), v56),
                              *(__m128 *)coeff2),
                            v56),
                          *(__m128 *)coeff1),
                        v56),
                      *(__m128 *)coeff0),
                    v56),
                  v55),
                v55);
        v58 = _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v57, v57)), v54);
        v59 = _mm_andnot_ps(v54, v57);
        v60 = _mm_cmplt_ps(v52, *(__m128 *)_xmm);
        if ( (float)(1.5707964
                   - COERCE_FLOAT((_mm_andnot_ps(v60, _mm_or_ps(v58, v59)).m128_u32[0] | v60.m128_i32[0] & v52.m128_i32[0]) ^ v51.m128_i32[0] & _xmm[0])) > v42 )
        {
          v61 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(oldForward->m_quad, oldForward->m_quad, 201), up->m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(up->m_quad, up->m_quad, 201), oldForward->m_quad));
          v62 = _mm_mul_ps(_mm_shuffle_ps(v61, v61, 201), v46);
          if ( (float)((float)(_mm_shuffle_ps(v62, v62, 85).m128_f32[0] + _mm_shuffle_ps(v62, v62, 0).m128_f32[0])
                     + _mm_shuffle_ps(v62, v62, 170).m128_f32[0]) < 0.0 )
            LODWORD(v42) ^= _xmm[0];
          hkQuaternionf::setAxisAngle(&quat, up, v42);
          hkVector4f::setRotatedDir(&vel, &quat, oldForward);
          v63 = hkaiAvoidanceSolverUtils::intersectVelLine(&vel, oldVelocity, desiredVelocity, up);
          if ( v63 < 3.40282e38 )
          {
            if ( movementLimits->m_kinematicConstraintType.m_storage == 1 )
              m_maxTurnVelocity = movementLimits->m_maxTurnVelocity;
            else
              m_maxTurnVelocity = movementLimits->m_maxVelocity;
            v64 = fminf(v40, m_maxTurnVelocity);
            if ( limitEnabled )
              m_minVelocity = v64;
            else
              m_minVelocity = movementLimits->m_minVelocity;
            v40 = fminf(fmaxf(v63, m_minVelocity), movementLimits->m_maxVelocity);
          }
          v46 = vel.m_quad;
        }
        v65 = (__m128)COERCE_UNSIGNED_INT(
                        fminf(
                          fmaxf(
                            v40 - v50,
                            COERCE_FLOAT(COERCE_UNSIGNED_INT(timestep * movementLimits->m_maxDeceleration) ^ _xmm[0])),
                          timestep * movementLimits->m_maxAcceleration)
                      + v50);
        v65.m128_f32[0] = fminf(fmaxf(v65.m128_f32[0], movementLimits->m_minVelocity), movementLimits->m_maxVelocity);
        constrainedVelocity->m_quad = _mm_mul_ps(_mm_shuffle_ps(v65, v65, 0), v46);
      }
    }
  }
  else
  {
    *constrainedVelocity = (hkVector4f)desiredVelocity->m_quad;
  }
}

// File Line: 596
// RVA: 0xBDFFB0
bool __fastcall hkaiAvoidanceSolverUtils::detectFrontArea(
        float radius,
        hkVector4f *agentPos,
        hkaiAvoidanceSolver::BoundaryObstacle *boundary,
        hkVector4f *boundaryPlane)
{
  __m128 v4; // xmm3
  __m128 v5; // xmm3
  __m128 v6; // xmm1
  __m128 v7; // xmm8
  __m128 v8; // xmm7
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  float v11; // xmm11_4
  __m128 v12; // xmm3
  float v13; // xmm1_4
  bool result; // al

  v4 = _mm_mul_ps(boundaryPlane->m_quad, agentPos->m_quad);
  v5 = _mm_shuffle_ps(v4, _mm_unpackhi_ps(v4, boundaryPlane->m_quad), 196);
  v6 = _mm_add_ps(_mm_shuffle_ps(v5, v5, 78), v5);
  result = 1;
  if ( (float)(_mm_shuffle_ps(v6, v6, 177).m128_f32[0] + v6.m128_f32[0]) < radius )
  {
    v7 = _mm_sub_ps(boundary->m_end.m_quad, boundary->m_start.m_quad);
    v8 = _mm_mul_ps(v7, v7);
    v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
    v10 = _mm_rsqrt_ps(v9);
    LODWORD(v11) = _mm_andnot_ps(
                     _mm_cmple_ps(v9, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                         _mm_mul_ps(*(__m128 *)_xmm, v10)),
                       v9)).m128_u32[0];
    v12 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmple_ps(v9, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                  _mm_mul_ps(*(__m128 *)_xmm, v10))),
              v7),
            _mm_sub_ps(agentPos->m_quad, boundary->m_start.m_quad));
    v13 = (float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0] + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])
        + _mm_shuffle_ps(v12, v12, 170).m128_f32[0];
    if ( v13 < 0.0 || v13 > v11 )
      return 0;
  }
  return result;
}

// File Line: 615
// RVA: 0xBE0110
void __fastcall hkaiAvoidanceSolverUtils::calcVOGradient(
        const float agentMinVel,
        hkVector4f *agentVel,
        hkaiDynamicObstacleSolver::VelocityObstacle *velocityObstacle,
        hkVector4f *preferred,
        hkVector4f *gradient)
{
  int m_gradientType; // ecx
  __m128 m_quad; // xmm5
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  float v13; // xmm4_4
  __m128 v14; // xmm7
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  float v17; // xmm6_4
  hkVector4f v18; // xmm5
  hkaiDynamicObstacleSolver::VelocityObstacle *p_m_rightPlane; // rax
  __m128 v20; // xmm2
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm0
  __m128 v25; // xmm5
  float v26; // xmm6_4
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  float v30; // xmm7_4
  float v31; // xmm4_4
  float v32; // xmm3_4
  hkVector4f v33; // xmm0
  hkVector4f *v34; // rax
  hkVector4f v35; // xmm0
  hkVector4f dvel; // [rsp+30h] [rbp-30h] BYREF

  m_gradientType = velocityObstacle->m_gradientType;
  if ( m_gradientType != 1 )
  {
    v18.m_quad = (__m128)velocityObstacle->m_rightPlane;
    p_m_rightPlane = (hkaiDynamicObstacleSolver::VelocityObstacle *)&velocityObstacle->m_rightPlane;
    v20 = _mm_mul_ps(velocityObstacle->m_leftPlane.m_quad, agentVel->m_quad);
    v21 = _mm_shuffle_ps(v20, _mm_unpackhi_ps(v20, velocityObstacle->m_leftPlane.m_quad), 196);
    v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 78), v21);
    v23 = _mm_mul_ps(v18.m_quad, agentVel->m_quad);
    v24 = _mm_unpackhi_ps(v23, v18.m_quad);
    v25 = _mm_mul_ps(v18.m_quad, preferred->m_quad);
    v26 = fminf(fmaxf(_mm_shuffle_ps(v22, v22, 177).m128_f32[0] + v22.m128_f32[0], 0.0), 3.40282e38);
    v27 = _mm_shuffle_ps(v23, v24, 196);
    v28 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 78), v27);
    v29 = _mm_mul_ps(preferred->m_quad, velocityObstacle->m_leftPlane.m_quad);
    v30 = fminf(fmaxf(_mm_shuffle_ps(v28, v28, 177).m128_f32[0] + v28.m128_f32[0], 0.0), 3.40282e38);
    v31 = fminf(
            fmaxf(
              (float)(_mm_shuffle_ps(v29, v29, 85).m128_f32[0] + _mm_shuffle_ps(v29, v29, 0).m128_f32[0])
            + _mm_shuffle_ps(v29, v29, 170).m128_f32[0],
              -1.0),
            1.0);
    v32 = fminf(
            fmaxf(
              (float)(_mm_shuffle_ps(v25, v25, 85).m128_f32[0] + _mm_shuffle_ps(v25, v25, 0).m128_f32[0])
            + _mm_shuffle_ps(v25, v25, 170).m128_f32[0],
              -1.0),
            1.0);
    if ( (COERCE_FLOAT((unsigned int)(2 * COERCE_INT(v26 - v30)) >> 1) < 0.0049999999
       || COERCE_FLOAT((unsigned int)(2 * COERCE_INT(v31 - v32)) >> 1) > 0.0049999999)
      && m_gradientType == 3 )
    {
      if ( v31 > v32 )
        p_m_rightPlane = velocityObstacle;
      v33.m_quad = (__m128)p_m_rightPlane->m_leftPlane;
      v34 = gradient;
      *gradient = (hkVector4f)v33.m_quad;
      if ( v32 >= v31 )
        v26 = v30;
    }
    else
    {
      if ( v30 > v26 )
        p_m_rightPlane = velocityObstacle;
      v35.m_quad = (__m128)p_m_rightPlane->m_leftPlane;
      v34 = gradient;
      *gradient = (hkVector4f)v35.m_quad;
      if ( v26 >= v30 )
      {
        gradient->m_quad.m128_f32[3] = v30;
        return;
      }
    }
    v34->m_quad.m128_f32[3] = v26;
    return;
  }
  m_quad = agentVel->m_quad;
  *gradient = (hkVector4f)agentVel->m_quad;
  v9 = _mm_mul_ps(m_quad, m_quad);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_rsqrt_ps(v10);
  v12 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)), _mm_mul_ps(*(__m128 *)_xmm, v11)),
          v10);
  v13 = _mm_andnot_ps(_mm_cmple_ps(v10, (__m128)0i64), v12).m128_f32[0];
  if ( v13 > 0.00000011920929 )
  {
    v14 = (__m128)COERCE_UNSIGNED_INT(v13 - agentMinVel);
    v12.m128_f32[0] = 1.0 / v13;
    v14.m128_f32[0] = fminf(fmaxf(v13 - agentMinVel, 0.0), v13);
    v15 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), m_quad);
    v16 = _mm_xor_ps(v14, *(__m128 *)_xmm);
    *gradient = (hkVector4f)v15;
    dvel.m_quad = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v15);
    v17 = hkaiAvoidanceSolverUtils::intersectVelDeltaVelRVO(agentVel, &dvel, &velocityObstacle->m_leftPlane);
    gradient->m_quad.m128_f32[3] = fminf(
                                     fmaxf(
                                       fminf(
                                         v17,
                                         hkaiAvoidanceSolverUtils::intersectVelDeltaVelRVO(
                                           agentVel,
                                           &dvel,
                                           &velocityObstacle->m_rightPlane)),
                                       0.0),
                                     1.0)
                                 * v14.m128_f32[0];
  }
}

// File Line: 663
// RVA: 0xBE10C0
double __fastcall hkaiAvoidanceSolverUtils::calcSphereCollisionTime(
        float totalRadius,
        hkVector4f *agentToObstacle,
        hkVector4f *relativeVelocity,
        hkVector4f *up)
{
  double result; // xmm0_8

  *(float *)&result = hkaiAvoidanceSolverUtils::intersectVelCircle(relativeVelocity, totalRadius, agentToObstacle, up);
  return result;
}

// File Line: 668
// RVA: 0xBE10E0
float __fastcall hkaiAvoidanceSolverUtils::calcBoundaryCollisionTime(
        float radius,
        hkVector4f *agentToStart,
        hkVector4f *agentToEnd,
        hkVector4f *relativeVelocity,
        hkVector4f *normal,
        hkVector4f *up)
{
  __m128 v6; // xmm3
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  hkVector4f end; // [rsp+20h] [rbp-38h] BYREF
  hkVector4f start; // [rsp+30h] [rbp-28h] BYREF
  float v15; // [rsp+68h] [rbp+10h]
  float normala; // [rsp+80h] [rbp+28h]

  v6.m128_f32[0] = radius;
  v10 = _mm_mul_ps(_mm_shuffle_ps(v6, v6, 0), normal->m_quad);
  v11 = _mm_add_ps(agentToEnd->m_quad, v10);
  start.m_quad = _mm_add_ps(agentToStart->m_quad, v10);
  end.m_quad = v11;
  v15 = hkaiAvoidanceSolverUtils::intersectVelCircle(relativeVelocity, radius, agentToEnd, up);
  normala = fminf(hkaiAvoidanceSolverUtils::intersectVelCircle(relativeVelocity, radius, agentToStart, up), v15);
  return fminf(normala, hkaiAvoidanceSolverUtils::intersectVelLine(relativeVelocity, &start, &end, up));
}

// File Line: 682
// RVA: 0xBE0440
void __fastcall hkaiAvoidanceSolverUtils::calcBoundaryPlane(
        hkaiAvoidanceSolver::BoundaryObstacle *boundary,
        hkVector4f *up,
        hkVector4f *boundaryPlane)
{
  __m128 v3; // xmm6
  __m128 v4; // xmm6
  __m128 v5; // xmm6
  __m128 v6; // xmm1
  __m128 v7; // xmm3
  __m128 v8; // xmm2
  __m128 v9; // xmm5
  __m128 v10; // xmm2

  v3 = _mm_sub_ps(boundary->m_end.m_quad, boundary->m_start.m_quad);
  v4 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v3, v3, 201), up->m_quad),
         _mm_mul_ps(_mm_shuffle_ps(up->m_quad, up->m_quad, 201), v3));
  v5 = _mm_shuffle_ps(v4, v4, 201);
  v6 = _mm_mul_ps(v5, v5);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v8 = _mm_rsqrt_ps(v7);
  v9 = _mm_mul_ps(
         _mm_andnot_ps(
           _mm_cmple_ps(v7, (__m128)0i64),
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)), _mm_mul_ps(*(__m128 *)_xmm, v8))),
         v5);
  *boundaryPlane = (hkVector4f)v9;
  v10 = _mm_mul_ps(v9, boundary->m_start.m_quad);
  boundaryPlane->m_quad = _mm_shuffle_ps(
                            v9,
                            _mm_unpackhi_ps(
                              v9,
                              _mm_sub_ps(
                                (__m128)0i64,
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                                  _mm_shuffle_ps(v10, v10, 170)))),
                            196);
}

// File Line: 692
// RVA: 0xBE0500
float __fastcall hkaiAvoidanceSolverUtils::intersectVelCircle(
        hkVector4f *vel,
        float circleRadius,
        hkVector4f *circlePos,
        hkVector4f *up)
{
  __m128 m_quad; // xmm7
  __m128 v6; // xmm3
  float v7; // xmm6_4
  float v9; // xmm0_4
  __m128 v10; // xmm3
  float v11; // xmm0_4
  __m128 v12; // xmm2
  float v13; // xmm4_4
  __m128 v14; // xmm3
  float v15; // xmm1_4

  m_quad = circlePos->m_quad;
  v6 = _mm_mul_ps(m_quad, m_quad);
  v7 = circleRadius * circleRadius;
  if ( (float)((float)(_mm_shuffle_ps(v6, v6, 85).m128_f32[0] + _mm_shuffle_ps(v6, v6, 0).m128_f32[0])
             + _mm_shuffle_ps(v6, v6, 170).m128_f32[0]) <= (float)(circleRadius * circleRadius) )
    return 0.0;
  v9 = hkaiAvoidanceSolverUtils::determinant2d(vel, circlePos, up);
  v10 = vel->m_quad;
  v11 = v9 * v9;
  v12 = _mm_mul_ps(v10, v10);
  v13 = (float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0] + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])
      + _mm_shuffle_ps(v12, v12, 170).m128_f32[0];
  if ( (float)((float)(v13 * v7) - v11) <= 0.0 )
    return FLOAT_3_40282e38;
  v14 = _mm_mul_ps(v10, m_quad);
  v15 = (float)((float)((float)(_mm_shuffle_ps(v14, v14, 85).m128_f32[0] + _mm_shuffle_ps(v14, v14, 0).m128_f32[0])
                      + _mm_shuffle_ps(v14, v14, 170).m128_f32[0])
              - fsqrt((float)(v13 * v7) - v11))
      / v13;
  if ( v15 < 0.0 )
    return FLOAT_3_40282e38;
  return v15;
}

// File Line: 724
// RVA: 0xBE05F0
float __fastcall hkaiAvoidanceSolverUtils::intersectVelLine(
        hkVector4f *vel,
        hkVector4f *start,
        hkVector4f *end,
        hkVector4f *up)
{
  __m128 m_quad; // xmm7
  __m128 v7; // xmm10
  __m128 v8; // xmm10
  float v9; // xmm0_4
  float v11; // xmm6_4
  float v12; // xmm9_4
  float v13; // xmm0_4
  __m128 v14; // xmm10
  __m128 v15; // xmm10
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm4
  hkVector4f p; // [rsp+20h] [rbp-78h] BYREF
  hkVector4f q; // [rsp+30h] [rbp-68h] BYREF

  m_quad = start->m_quad;
  v7 = end->m_quad;
  p.m_quad = m_quad;
  v8 = _mm_sub_ps(v7, m_quad);
  q.m_quad = v8;
  v9 = hkaiAvoidanceSolverUtils::determinant2d(vel, &q, up);
  if ( v9 == 0.0 )
    return FLOAT_3_40282e38;
  v11 = 1.0 / v9;
  v12 = hkaiAvoidanceSolverUtils::determinant2d(&p, &q, up) * (float)(1.0 / v9);
  p.m_quad = _mm_mul_ps(m_quad, *(__m128 *)_xmm_bf800000bf800000bf800000bf800000);
  LODWORD(v13) = COERCE_UNSIGNED_INT(hkaiAvoidanceSolverUtils::determinant2d(&p, vel, up) * v11) ^ _xmm[0];
  if ( v13 < 0.0 || v13 > 1.0 )
    return FLOAT_3_40282e38;
  if ( v12 > 0.0 )
    return v12;
  v14 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), up->m_quad),
          _mm_mul_ps(_mm_shuffle_ps(up->m_quad, up->m_quad, 201), v8));
  v15 = _mm_shuffle_ps(v14, v14, 201);
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_rsqrt_ps(v17);
  v19 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmple_ps(v17, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                _mm_mul_ps(*(__m128 *)_xmm, v18))),
            v15),
          vel->m_quad);
  if ( (float)((float)(_mm_shuffle_ps(v19, v19, 85).m128_f32[0] + _mm_shuffle_ps(v19, v19, 0).m128_f32[0])
             + _mm_shuffle_ps(v19, v19, 170).m128_f32[0]) >= 0.0 )
    return FLOAT_3_40282e38;
  else
    return 0.0;
}

// File Line: 779
// RVA: 0xBE0950
bool __fastcall hkaiAvoidanceSolverUtils::isInsideRVO(hkVector4f *v, hkVector4f *planeA, hkVector4f *planeB)
{
  __m128 v3; // xmm2
  __m128 v4; // xmm2
  __m128 v5; // xmm0
  __m128 v6; // xmm2
  float v7; // xmm4_4
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  float v10; // xmm1_4

  v3 = _mm_mul_ps(planeA->m_quad, v->m_quad);
  v4 = _mm_shuffle_ps(v3, _mm_unpackhi_ps(v3, planeA->m_quad), 196);
  v5 = _mm_add_ps(_mm_shuffle_ps(v4, v4, 78), v4);
  v6 = _mm_mul_ps(planeB->m_quad, v->m_quad);
  v7 = _mm_shuffle_ps(v5, v5, 177).m128_f32[0] + v5.m128_f32[0];
  v8 = _mm_shuffle_ps(v6, _mm_unpackhi_ps(v6, planeB->m_quad), 196);
  v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 78), v8);
  v10 = _mm_shuffle_ps(v9, v9, 177).m128_f32[0] + v9.m128_f32[0];
  return v7 >= 0.0 && v10 >= 0.0;
}

// File Line: 787
// RVA: 0xBE0D80
bool __fastcall hkaiAvoidanceSolverUtils::isAngleInsideVO(float angle, float openEdge, float closeEdge)
{
  float v3; // xmm0_4
  float v4; // xmm2_4

  if ( angle < 0.0 )
    angle = angle + 6.2831855;
  if ( openEdge < 0.0 )
    openEdge = openEdge + 6.2831855;
  if ( closeEdge < 0.0 )
    closeEdge = closeEdge + 6.2831855;
  v3 = angle - openEdge;
  if ( v3 > 6.2831855 )
    v3 = v3 + -6.2831855;
  if ( v3 < 0.0 )
    v3 = v3 + 6.2831855;
  v4 = closeEdge - openEdge;
  if ( v4 > 6.2831855 )
    v4 = v4 + -6.2831855;
  if ( v4 < 0.0 )
    v4 = v4 + 6.2831855;
  return v4 > v3;
}

// File Line: 809
// RVA: 0xBE0D50
float __fastcall hkaiAvoidanceSolverUtils::clampAngle(float angle)
{
  if ( angle < -3.1415927 )
    angle = angle + 6.2831855;
  if ( angle > 3.1415927 )
    return angle + -6.2831855;
  return angle;
}

// File Line: 822
// RVA: 0xBE0D00
float __fastcall hkaiAvoidanceSolverUtils::fabsAngle(float openEdge, float closeEdge)
{
  float v2; // xmm1_4

  if ( openEdge < 0.0 )
    openEdge = openEdge + 6.2831855;
  if ( closeEdge < 0.0 )
    closeEdge = closeEdge + 6.2831855;
  v2 = closeEdge - openEdge;
  if ( v2 > 6.2831855 )
    v2 = v2 + -6.2831855;
  if ( v2 < 0.0 )
    return v2 + 6.2831855;
  return v2;
}

// File Line: 838
// RVA: 0xBE07B0
float __fastcall hkaiAvoidanceSolverUtils::intersectVelDeltaVelRVO(
        hkVector4f *vel,
        hkVector4f *dvel,
        hkVector4f *plane)
{
  __m128 m_quad; // xmm4
  __m128 v4; // xmm1
  __m128 v5; // xmm3
  __m128 v7; // xmm2
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  float v10; // xmm0_4
  float v11; // xmm4_4

  m_quad = plane->m_quad;
  v4 = _mm_mul_ps(plane->m_quad, dvel->m_quad);
  v5 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)), _mm_shuffle_ps(v4, v4, 170));
  if ( v5.m128_f32[0] < 0.00000011920929 )
    return FLOAT_3_40282e38;
  v7 = _mm_mul_ps(vel->m_quad, m_quad);
  v8 = _mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, m_quad), 196);
  v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 78), v8);
  v10 = _mm_shuffle_ps(v9, v9, 177).m128_f32[0] + v9.m128_f32[0];
  v9.m128_f32[0] = _mm_rcp_ps(v5).m128_f32[0];
  v11 = (float)((float)(2.0 - (float)(v9.m128_f32[0] * v5.m128_f32[0])) * v9.m128_f32[0]) * (float)(0.0 - v10);
  if ( v11 < 0.0 )
    return FLOAT_3_40282e38;
  return v11;
}

// File Line: 852
// RVA: 0xBE0850
float __fastcall hkaiAvoidanceSolverUtils::intersectVelDeltaVelVOEdge(
        hkVector4f *vel,
        hkVector4f *dvel,
        hkVector4f *up,
        hkVector4f *edge)
{
  __m128 v4; // xmm6
  __m128 v5; // xmm6
  __m128 v6; // xmm1
  __m128 v7; // xmm3
  __m128 v8; // xmm2
  __m128 v9; // xmm6
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  float v15; // xmm0_4
  float result; // xmm0_4

  v4 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(edge->m_quad, edge->m_quad, 201), up->m_quad),
         _mm_mul_ps(_mm_shuffle_ps(up->m_quad, up->m_quad, 201), edge->m_quad));
  v5 = _mm_shuffle_ps(v4, v4, 201);
  v6 = _mm_mul_ps(v5, v5);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v8 = _mm_rsqrt_ps(v7);
  v9 = _mm_mul_ps(
         v5,
         _mm_andnot_ps(
           _mm_cmple_ps(v7, (__m128)0i64),
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)), _mm_mul_ps(*(__m128 *)_xmm, v8))));
  v10 = _mm_mul_ps(dvel->m_quad, v9);
  v11 = _mm_mul_ps(vel->m_quad, v9);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v13 = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, v9), 196);
  v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
  v15 = _mm_shuffle_ps(v14, v14, 177).m128_f32[0] + v14.m128_f32[0];
  v14.m128_f32[0] = _mm_rcp_ps(v12).m128_f32[0];
  result = (float)((float)(2.0 - (float)(v12.m128_f32[0] * v14.m128_f32[0])) * v14.m128_f32[0]) * (float)(0.0 - v15);
  if ( result < 0.0 )
    return FLOAT_3_40282e38;
  return result;
}

// File Line: 862
// RVA: 0xBE09C0
float __fastcall hkaiAvoidanceSolverUtils::determinant2d(hkVector4f *p, hkVector4f *q, hkVector4f *up)
{
  __m128 v3; // xmm2
  __m128 v4; // xmm2

  v3 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(q->m_quad, q->m_quad, 201), p->m_quad),
         _mm_mul_ps(_mm_shuffle_ps(p->m_quad, p->m_quad, 201), q->m_quad));
  v4 = _mm_mul_ps(_mm_shuffle_ps(v3, v3, 201), up->m_quad);
  return (float)(_mm_shuffle_ps(v4, v4, 85).m128_f32[0] + _mm_shuffle_ps(v4, v4, 0).m128_f32[0])
       + _mm_shuffle_ps(v4, v4, 170).m128_f32[0];
}

// File Line: 872
// RVA: 0xBE0DF0
bool __fastcall hkaiAvoidanceSolverUtils::clipSegmentInsideAabb(
        hkAabb *aabb,
        hkVector4f *startInOut,
        hkVector4f *endInOut)
{
  hkVector4f v3; // xmm8
  hkVector4f v4; // xmm9
  BOOL v5; // r9d
  BOOL v6; // ecx
  bool result; // al
  __m128 m_quad; // xmm10
  __m128 v9; // xmm11
  __m128 v10; // xmm7
  __m128 v11; // xmm6
  __m128i v12; // xmm7
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm4
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm4
  __m128i v20; // xmm6
  __m128 v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm0
  __m128 v24; // xmm3
  __m128 v25; // xmm2
  __m128 v26; // xmm3
  __m128 v27; // xmm3
  __m128 v28; // [rsp+20h] [rbp-88h]
  __m128 v29; // [rsp+20h] [rbp-88h]

  v3.m_quad = (__m128)aabb->m_min;
  v4.m_quad = (__m128)aabb->m_max;
  v5 = (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(aabb->m_min.m_quad, startInOut->m_quad), _mm_cmple_ps(startInOut->m_quad, v4.m_quad))) & 7) == 7;
  v6 = (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(aabb->m_min.m_quad, endInOut->m_quad), _mm_cmple_ps(endInOut->m_quad, v4.m_quad))) & 7) == 7;
  if ( v5 && v6 )
    return 1;
  m_quad = endInOut->m_quad;
  v9 = startInOut->m_quad;
  v10 = startInOut->m_quad;
  v11 = endInOut->m_quad;
  if ( !v5 )
  {
    v12 = (__m128i)_mm_sub_ps(m_quad, v9);
    v13 = _mm_rcp_ps((__m128)v12);
    v14 = _mm_cmpeq_ps((__m128)0i64, (__m128)v12);
    v28 = _mm_or_ps(
            _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v12, 0x1Fu), 0x1Fu), (__m128)_xmm), v14),
            _mm_andnot_ps(v14, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v12, v13)), v13)));
    v28.m128_i32[3] = _mm_movemask_ps(
                        _mm_cmple_ps(
                          (__m128)0i64,
                          _mm_shuffle_ps((__m128)v12, _mm_unpackhi_ps((__m128)v12, query.m_quad), 196))) & 7 | 0x3F000000;
    v15 = _mm_mul_ps(v28, _mm_sub_ps(v4.m_quad, v9));
    v16 = _mm_mul_ps(v28, _mm_sub_ps(v3.m_quad, v9));
    v17 = _mm_max_ps(v16, v15);
    v18 = _mm_min_ps(v16, v15);
    v19 = _mm_max_ps(
            _mm_max_ps(
              _mm_shuffle_ps(v18, v18, 170),
              _mm_max_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0))),
            aabbOut.m_quad);
    if ( v19.m128_f32[0] > fmin(
                             fmin(
                               _mm_shuffle_ps(v17, v17, 170).m128_f32[0],
                               fmin(_mm_shuffle_ps(v17, v17, 85).m128_f32[0], _mm_shuffle_ps(v17, v17, 0).m128_f32[0])),
                             1.0) )
      return 0;
    v10 = _mm_add_ps(_mm_mul_ps((__m128)v12, v19), v9);
  }
  if ( !v6 )
  {
    v20 = (__m128i)_mm_sub_ps(v9, m_quad);
    v21 = _mm_cmpeq_ps((__m128)0i64, (__m128)v20);
    v22 = _mm_rcp_ps((__m128)v20);
    v29 = _mm_or_ps(
            _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v20, 0x1Fu), 0x1Fu), (__m128)_xmm), v21),
            _mm_andnot_ps(v21, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v20, v22)), v22)));
    v29.m128_i32[3] = _mm_movemask_ps(
                        _mm_cmple_ps(
                          (__m128)0i64,
                          _mm_shuffle_ps((__m128)v20, _mm_unpackhi_ps((__m128)v20, query.m_quad), 196))) & 7 | 0x3F000000;
    v23 = _mm_mul_ps(v29, _mm_sub_ps(v4.m_quad, m_quad));
    v24 = _mm_mul_ps(v29, _mm_sub_ps(v3.m_quad, m_quad));
    v25 = _mm_max_ps(v24, v23);
    v26 = _mm_min_ps(v24, v23);
    v27 = _mm_max_ps(
            _mm_max_ps(
              _mm_shuffle_ps(v26, v26, 170),
              _mm_max_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0))),
            aabbOut.m_quad);
    if ( v27.m128_f32[0] > fmin(
                             fmin(
                               _mm_shuffle_ps(v25, v25, 170).m128_f32[0],
                               fmin(_mm_shuffle_ps(v25, v25, 85).m128_f32[0], _mm_shuffle_ps(v25, v25, 0).m128_f32[0])),
                             1.0) )
      return 0;
    v11 = _mm_add_ps(_mm_mul_ps((__m128)v20, v27), m_quad);
  }
  *startInOut = (hkVector4f)v10;
  result = 1;
  *endInOut = (hkVector4f)v11;
  return result;
}

// File Line: 918
// RVA: 0xBE0A10
float __fastcall hkaiAvoidanceSolverUtils::closestDistToLineSegment(hkVector4f *p, hkVector4f *a, hkVector4f *b)
{
  __m128 v3; // xmm5
  __m128 v4; // xmm1
  __m128 v5; // xmm4
  __m128 v6; // xmm6
  __m128 v7; // xmm3
  __m128 v8; // xmm1
  __m128 v9; // xmm0
  __m128 v10; // xmm1
  __m128 v11; // xmm4
  __m128 v12; // xmm5
  __m128 v13; // xmm6
  __m128 v14; // xmm1
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  float result; // xmm0_4

  v3 = _mm_sub_ps(b->m_quad, a->m_quad);
  v4 = _mm_mul_ps(v3, v3);
  v5 = _mm_sub_ps(p->m_quad, a->m_quad);
  v6 = _mm_sub_ps(p->m_quad, b->m_quad);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)), _mm_shuffle_ps(v4, v4, 170));
  v8 = _mm_mul_ps(v5, v3);
  v9 = _mm_rcp_ps(v7);
  v10 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v7, v9)), v9),
          _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170)));
  if ( v10.m128_f32[0] >= 0.0 )
  {
    if ( v10.m128_f32[0] <= 1.0 )
    {
      v14 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v3), a->m_quad), p->m_quad);
      v15 = _mm_mul_ps(v14, v14);
      v12 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
              _mm_shuffle_ps(v15, v15, 170));
    }
    else
    {
      v13 = _mm_mul_ps(v6, v6);
      v12 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
              _mm_shuffle_ps(v13, v13, 170));
    }
  }
  else
  {
    v11 = _mm_mul_ps(v5, v5);
    v12 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170));
  }
  v16 = _mm_rsqrt_ps(v12);
  LODWORD(result) = _mm_andnot_ps(
                      _mm_cmple_ps(v12, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v12), v16)),
                          _mm_mul_ps(*(__m128 *)_xmm, v16)),
                        v12)).m128_u32[0];
  return result;
}

// File Line: 945
// RVA: 0xBE0B50
float __fastcall hkaiAvoidanceSolverUtils::calcAngle(hkVector4f *va, hkVector4f *vap, hkVector4f *vb)
{
  __m128 v3; // xmm10
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm1
  __m128 v7; // xmm9
  __m128 v8; // xmm7
  __m128 v9; // xmm2
  __m128 v10; // xmm5
  __m128 v11; // xmm4
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm0
  float v15; // xmm3_4

  v3 = _mm_mul_ps(vb->m_quad, vap->m_quad);
  v4 = _mm_mul_ps(vb->m_quad, va->m_quad);
  v5 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)), _mm_shuffle_ps(v4, v4, 170));
  v6 = _mm_cmplt_ps(v5, query.m_quad);
  v7 = _mm_min_ps(
         _mm_max_ps(
           (__m128)COERCE_UNSIGNED_INT(
                     fmax(
                       -1.0,
                       COERCE_FLOAT(v5.m128_i32[0] & v6.m128_i32[0] | _mm_andnot_ps(v6, query.m_quad).m128_u32[0]))),
           *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
         *(__m128 *)_xmm);
  v8 = _mm_andnot_ps(*(__m128 *)_xmm, v7);
  v9 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v8), *(__m128 *)_xmm);
  v10 = _mm_cmplt_ps(*(__m128 *)_xmm, v8);
  v11 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v9), v10), _mm_andnot_ps(v10, v8));
  v12 = _mm_or_ps(_mm_andnot_ps(v10, _mm_mul_ps(v8, v8)), _mm_and_ps(v10, v9));
  v13 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v12, *(__m128 *)coeff4), *(__m128 *)coeff3), v12),
                        *(__m128 *)coeff2),
                      v12),
                    *(__m128 *)coeff1),
                  v12),
                *(__m128 *)coeff0),
              v12),
            v11),
          v11);
  v14 = _mm_cmplt_ps(v8, *(__m128 *)_xmm);
  v15 = 1.5707964
      - COERCE_FLOAT((_mm_andnot_ps(
                        v14,
                        _mm_or_ps(
                          _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v13, v13)), v10),
                          _mm_andnot_ps(v10, v13))).m128_u32[0] | v14.m128_i32[0] & v8.m128_i32[0]) ^ _xmm[0] & v7.m128_i32[0]);
  if ( (float)((float)(_mm_shuffle_ps(v3, v3, 85).m128_f32[0] + _mm_shuffle_ps(v3, v3, 0).m128_f32[0])
             + _mm_shuffle_ps(v3, v3, 170).m128_f32[0]) < 0.0 )
    LODWORD(v15) ^= _xmm[0];
  return v15;
}

// File Line: 1103
// RVA: 0xBDF150
hkResult *__fastcall hkaiAvoidanceSolverUtils::calcSteeringVelocity(
        hkResult *result,
        float timestep,
        hkVector4f *up,
        hkaiAvoidanceSolver::SteeringAgent *agentIn,
        hkVector4f *steerVelocityOut,
        hkVector4f *steerForwardOut)
{
  _QWORD *Value; // rcx
  unsigned __int64 v11; // r9
  unsigned __int64 v12; // rax
  __m128 m_quad; // xmm8
  __m128 v14; // xmm0
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  _QWORD *v18; // rcx
  hkaiAvoidanceProperties *m_avoidanceProperties; // rdx
  __m128 v20; // xmm6
  bool v21; // zf
  __m128 v22; // xmm3
  __m128 v23; // xmm6
  __m128 v24; // xmm1
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  __m128 v27; // xmm6
  _QWORD *v28; // r8
  _QWORD *v29; // rcx
  unsigned __int64 v30; // rax
  _QWORD *v31; // rcx
  hkResult *v32; // rax
  __m128 v33; // xmm6
  _QWORD *v34; // r8
  _QWORD *v35; // rcx
  unsigned __int64 v36; // rax
  _QWORD *v37; // rcx
  hkaiAvoidanceProperties *v38; // rdx
  char m_storage; // cl
  bool v40; // al
  _QWORD *v41; // r8
  unsigned __int64 v42; // rcx
  unsigned __int64 v43; // rax
  _QWORD *v44; // r8
  _QWORD *v45; // rcx
  unsigned __int64 v46; // rax
  _QWORD *v47; // rcx
  hkVector4f newVelocity; // [rsp+40h] [rbp-98h] BYREF
  hkVector4f deltaVelocity; // [rsp+50h] [rbp-88h] BYREF
  hkVector4f oldForward; // [rsp+60h] [rbp-78h] BYREF
  hkVector4f oldVelocity; // [rsp+70h] [rbp-68h] BYREF
  hkaiAvoidanceSolver::WorldInfo worldInfo; // [rsp+80h] [rbp-58h] BYREF
  hkResult resulta; // [rsp+E0h] [rbp+8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = Value[1];
  if ( v11 < Value[3] )
  {
    *(_QWORD *)v11 = "LtcalcSteerVel";
    *(_QWORD *)(v11 + 16) = "Stinit";
    v12 = __rdtsc();
    *(_DWORD *)(v11 + 8) = v12;
    Value[1] = v11 + 24;
  }
  m_quad = agentIn->m_velocity.m_quad;
  v14 = agentIn->m_forward.m_quad;
  oldVelocity.m_quad = m_quad;
  oldForward.m_quad = v14;
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "StapplyKineConst1";
    v17 = __rdtsc();
    v18 = v16 + 2;
    *((_DWORD *)v18 - 2) = v17;
    v15[1] = v18;
  }
  if ( agentIn->m_localSteeringInput.m_applyKinematicConstraints.m_bool
    && (m_avoidanceProperties = agentIn->m_avoidanceProperties,
        m_avoidanceProperties->m_avoidanceSolverType.m_storage == 1) )
  {
    hkaiAvoidanceSolverUtils::applyKinematicConstraints(
      timestep,
      &m_avoidanceProperties->m_movementProperties,
      up,
      &oldVelocity,
      &oldForward,
      &agentIn->m_localSteeringInput.m_desiredVelocity,
      &newVelocity,
      1);
    v20 = newVelocity.m_quad;
    agentIn->m_localSteeringInput.m_desiredVelocity = (hkVector4f)newVelocity.m_quad;
  }
  else
  {
    v20 = agentIn->m_localSteeringInput.m_desiredVelocity.m_quad;
  }
  v21 = agentIn->m_numNearbyAgents == 0;
  v22 = up->m_quad;
  v23 = _mm_sub_ps(v20, m_quad);
  v24 = up->m_quad;
  result->m_enum = HK_SUCCESS;
  v25 = _mm_mul_ps(v24, v23);
  v26 = _mm_shuffle_ps(v25, v25, 0);
  v27 = _mm_sub_ps(
          v23,
          _mm_mul_ps(_mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 85), v26), _mm_shuffle_ps(v25, v25, 170)), v22));
  deltaVelocity.m_quad = v27;
  if ( !v21 || agentIn->m_numSphereObstacles || agentIn->m_numBoundaryObstacles )
  {
    v26.m128_f32[0] = timestep;
    worldInfo.m_up.m_quad = v22;
    worldInfo.m_timeStep.m_real = _mm_shuffle_ps(v26, v26, 0);
    v28 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v29 = (_QWORD *)v28[1];
    if ( (unsigned __int64)v29 < v28[3] )
    {
      *v29 = "StsolveSingleAgent";
      v30 = __rdtsc();
      v31 = v29 + 2;
      *((_DWORD *)v31 - 2) = v30;
      v28[1] = v31;
    }
    v32 = hkaiAvoidanceSolver::solveSingleAgent(&resulta, &worldInfo, agentIn, &deltaVelocity);
    v27 = deltaVelocity.m_quad;
    result->m_enum = v32->m_enum;
  }
  v33 = _mm_add_ps(v27, agentIn->m_localSteeringInput.m_currentVelocity.m_quad);
  newVelocity.m_quad = v33;
  v34 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v35 = (_QWORD *)v34[1];
  if ( (unsigned __int64)v35 < v34[3] )
  {
    *v35 = "StapplyKineConst2";
    v36 = __rdtsc();
    v37 = v35 + 2;
    *((_DWORD *)v37 - 2) = v36;
    v34[1] = v37;
  }
  v38 = agentIn->m_avoidanceProperties;
  m_storage = v38->m_avoidanceSolverType.m_storage;
  v40 = !m_storage && v38->m_movementProperties.m_kinematicConstraintType.m_storage == 1 && result->m_enum == HK_FAILURE;
  if ( agentIn->m_localSteeringInput.m_applyKinematicConstraints.m_bool && !m_storage && !v40 )
  {
    hkaiAvoidanceSolverUtils::applyKinematicConstraints(
      timestep,
      &v38->m_movementProperties,
      up,
      &oldVelocity,
      &oldForward,
      &newVelocity,
      &worldInfo.m_up,
      1);
    v33 = worldInfo.m_up.m_quad;
    newVelocity.m_quad = (__m128)worldInfo.m_up;
  }
  v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v42 = v41[1];
  if ( v42 < v41[3] )
  {
    *(_QWORD *)v42 = "StcalcAngVel";
    v43 = __rdtsc();
    *(_DWORD *)(v42 + 8) = v43;
    v41[1] = v42 + 16;
  }
  hkaiAvoidanceSolverUtils::calcAngularVelocityAndForward(
    &agentIn->m_localSteeringInput.m_currentVelocity,
    &newVelocity,
    &agentIn->m_localSteeringInput.m_currentForward,
    &agentIn->m_localSteeringInput.m_currentUp,
    &agentIn->m_avoidanceProperties->m_movementProperties,
    timestep,
    (hkSimdFloat32 *)&worldInfo,
    steerForwardOut);
  steerVelocityOut->m_quad = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, worldInfo.m_up.m_quad), 196);
  v44 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v45 = (_QWORD *)v44[1];
  if ( (unsigned __int64)v45 < v44[3] )
  {
    *v45 = "lt";
    v46 = __rdtsc();
    v47 = v45 + 2;
    *((_DWORD *)v47 - 2) = v46;
    v44[1] = v47;
  }
  return result;
}

// File Line: 1193
// RVA: 0xBDF4F0
void __fastcall hkaiAvoidanceSolverUtils::calcUnsteeredVelocity(
        float timestep,
        hkVector4f *up,
        hkaiMovementProperties *movementProperties,
        hkaiLocalSteeringInput *steeringInput,
        hkVector4f *steerVelocityOut,
        hkVector4f *steerForwardOut)
{
  _QWORD *Value; // r9
  unsigned __int64 v11; // rcx
  unsigned __int64 v12; // rax
  __m128 m_quad; // xmm4
  __m128 v14; // xmm2
  __m128 v15; // xmm0
  __m128 v16; // xmm2
  __m128 v17; // xmm5
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  _QWORD *v21; // r8
  _QWORD *v22; // rcx
  unsigned __int64 v23; // rax
  _QWORD *v24; // rcx
  __m128 v25; // xmm6
  _QWORD *v26; // r10
  unsigned __int64 v27; // r9
  unsigned __int64 v28; // rax
  _QWORD *v29; // r8
  _QWORD *v30; // rcx
  unsigned __int64 v31; // rax
  _QWORD *v32; // rcx
  hkVector4f oldVelocity; // [rsp+40h] [rbp-58h] BYREF
  hkVector4f oldForward; // [rsp+50h] [rbp-48h] BYREF
  hkVector4f constrainedVelocity; // [rsp+60h] [rbp-38h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = Value[1];
  if ( v11 < Value[3] )
  {
    *(_QWORD *)v11 = "LtcalcUnsteeredVelocity";
    *(_QWORD *)(v11 + 16) = "Stinit";
    v12 = __rdtsc();
    *(_DWORD *)(v11 + 8) = v12;
    Value[1] = v11 + 24;
  }
  m_quad = up->m_quad;
  v14 = _mm_mul_ps(up->m_quad, steeringInput->m_currentVelocity.m_quad);
  v15 = _mm_sub_ps(
          (__m128)0i64,
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
            _mm_shuffle_ps(v14, v14, 170)));
  v16 = _mm_mul_ps(steeringInput->m_currentForward.m_quad, up->m_quad);
  oldVelocity.m_quad = _mm_add_ps(_mm_mul_ps(v15, up->m_quad), steeringInput->m_currentVelocity.m_quad);
  v17 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                _mm_shuffle_ps(v16, v16, 170))),
            m_quad),
          steeringInput->m_currentForward.m_quad);
  v18 = _mm_mul_ps(v17, v17);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v20 = _mm_rsqrt_ps(v19);
  oldForward.m_quad = _mm_mul_ps(
                        v17,
                        _mm_andnot_ps(
                          _mm_cmple_ps(v19, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                            _mm_mul_ps(*(__m128 *)_xmm, v20))));
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "StapplyKineConst";
    v23 = __rdtsc();
    v24 = v22 + 2;
    *((_DWORD *)v24 - 2) = v23;
    v21[1] = v24;
  }
  if ( steeringInput->m_applyKinematicConstraints.m_bool )
  {
    hkaiAvoidanceSolverUtils::applyKinematicConstraints(
      timestep,
      movementProperties,
      up,
      &oldVelocity,
      &oldForward,
      &steeringInput->m_desiredVelocity,
      &constrainedVelocity,
      1);
    v25 = constrainedVelocity.m_quad;
  }
  else
  {
    v25 = steeringInput->m_desiredVelocity.m_quad;
  }
  oldVelocity.m_quad = v25;
  v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v27 = v26[1];
  if ( v27 < v26[3] )
  {
    *(_QWORD *)v27 = "StcalcAngVel";
    v28 = __rdtsc();
    *(_DWORD *)(v27 + 8) = v28;
    v26[1] = v27 + 16;
  }
  hkaiAvoidanceSolverUtils::calcAngularVelocityAndForward(
    &steeringInput->m_currentVelocity,
    &oldVelocity,
    &steeringInput->m_currentForward,
    &steeringInput->m_currentUp,
    movementProperties,
    timestep,
    (hkSimdFloat32 *)&constrainedVelocity,
    steerForwardOut);
  steerVelocityOut->m_quad = _mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, constrainedVelocity.m_quad), 196);
  v29 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v30 = (_QWORD *)v29[1];
  if ( (unsigned __int64)v30 < v29[3] )
  {
    *v30 = "lt";
    v31 = __rdtsc();
    v32 = v30 + 2;
    *((_DWORD *)v32 - 2) = v31;
    v29[1] = v32;
  }
}

// File Line: 1246
// RVA: 0xBDF790
void __fastcall hkaiAvoidanceSolverUtils::calcAngularVelocityAndForward(
        hkVector4f *currentVelocity,
        hkVector4f *newVelocity,
        hkVector4f *forward,
        hkVector4f *up,
        hkaiMovementProperties *movementProperties,
        float timestep,
        hkSimdFloat32 *angularVelocityOut,
        hkVector4f *steerForwardOut)
{
  __m128 m_quad; // xmm7
  __m128 v10; // xmm1
  __m128i v11; // xmm8
  __m128 v13; // xmm1
  __m128 v14; // xmm10
  __m128 v15; // xmm10
  __m128 v16; // xmm2
  float v17; // xmm0_4
  __m128 v18; // xmm2
  __m128 v19; // xmm2
  __m128i si128; // xmm6
  __m128 v21; // xmm9
  __m128 v22; // xmm2
  __m128i v23; // xmm8
  __m128i v24; // xmm6
  __m128 v25; // xmm5
  __m128 v26; // xmm0
  __m128 v27; // xmm4
  __m128 v28; // xmm2
  __m128 v29; // xmm3
  __m128 v30; // xmm1
  __m128 v31; // xmm9
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm14
  __m128 v38; // xmm14
  __m128 v39; // xmm1
  __m128 v40; // xmm8
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  __m128i v44; // xmm11
  __m128 v45; // xmm8
  __m128 v46; // xmm1
  __m128i v47; // xmm9
  float v48; // xmm13_4
  __m128 v49; // xmm1
  __m128i v50; // xmm10
  __m128 v51; // xmm7
  __m128 v52; // xmm2
  __m128i v53; // xmm6
  __m128 v54; // xmm5
  __m128 v55; // xmm0
  __m128 v56; // xmm4
  __m128 v57; // xmm3
  float v58; // xmm0_4
  __m128 v59; // xmm7
  __m128 v60; // xmm7
  __m128 v61; // xmm2
  __m128i v62; // xmm11
  __m128 v63; // xmm1
  __m128 v64; // xmm5
  __m128 v65; // xmm4
  __m128 v66; // xmm2
  __m128 v67; // xmm0
  __m128 v68; // xmm1
  __m128 v69; // xmm2
  __m128 v70; // xmm4
  __m128 v71; // xmm6
  __m128 v72; // xmm3
  __m128 v73; // xmm2
  __m128 v74; // xmm0
  __m128 v75; // xmm6
  __m128 v76; // xmm0
  __m128 v77; // [rsp+20h] [rbp-B8h]
  unsigned int movementPropertiesa; // [rsp+100h] [rbp+28h]

  m_quad = up->m_quad;
  v10 = _mm_mul_ps(up->m_quad, newVelocity->m_quad);
  v11 = (__m128i)_mm_sub_ps(
                   newVelocity->m_quad,
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                       _mm_shuffle_ps(v10, v10, 170)),
                     up->m_quad));
  if ( (_mm_movemask_ps(_mm_cmplt_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v11, 1u), 1u), *(__m128 *)&epsilon)) & 7) == 7 )
  {
    *angularVelocityOut = 0i64;
    *steerForwardOut = (hkVector4f)forward->m_quad;
  }
  else if ( movementProperties->m_kinematicConstraintType.m_storage == 1 )
  {
    v13 = _mm_mul_ps(forward->m_quad, (__m128)v11);
    v14 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(forward->m_quad, forward->m_quad, 201), m_quad),
            _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), forward->m_quad));
    v15 = _mm_shuffle_ps(v14, v14, 201);
    v16 = _mm_mul_ps(v15, (__m128)v11);
    v17 = (float)(_mm_shuffle_ps(v16, v16, 0).m128_f32[0] + _mm_shuffle_ps(v16, v16, 85).m128_f32[0])
        + _mm_shuffle_ps(v16, v16, 170).m128_f32[0];
    v18 = _mm_xor_ps((__m128)LODWORD(movementProperties->m_maxAngularVelocity), *(__m128 *)_xmm);
    v18.m128_f32[0] = fminf(
                        fmaxf(
                          atan2f(
                            v17,
                            _mm_shuffle_ps(v13, v13, 170).m128_f32[0]
                          + (float)(_mm_shuffle_ps(v13, v13, 85).m128_f32[0] + _mm_shuffle_ps(v13, v13, 0).m128_f32[0]))
                        * (float)(1.0 / timestep),
                          v18.m128_f32[0]),
                        movementProperties->m_maxAngularVelocity);
    v19 = _mm_shuffle_ps(v18, v18, 0);
    *angularVelocityOut = (hkSimdFloat32)v19;
    si128 = _mm_load_si128((const __m128i *)_xmm);
    v21 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(timestep), (__m128)LODWORD(timestep), 0), v19),
            *(__m128 *)offset_1);
    v22 = _mm_andnot_ps(*(__m128 *)_xmm, v21);
    v23 = _mm_add_epi32(si128, si128);
    v24 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v22, *(__m128 *)_xmm)), si128));
    v25 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v24, v23), (__m128i)0i64);
    v26 = _mm_cvtepi32_ps(v24);
    v27 = _mm_add_ps(
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(v26, *(__m128 *)DP1_0), v22), _mm_mul_ps(v26, *(__m128 *)DP2)),
            _mm_mul_ps(v26, *(__m128 *)DP3));
    v28 = _mm_mul_ps(v27, v27);
    v29 = _mm_xor_ps(
            _mm_or_ps(
              _mm_andnot_ps(
                v25,
                _mm_add_ps(
                  _mm_sub_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v28, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v28),
                          *(__m128 *)cosCoeff2_0),
                        v28),
                      v28),
                    _mm_mul_ps(v28, *(__m128 *)_xmm)),
                  *(__m128 *)_xmm)),
              _mm_and_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v28, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v28),
                        *(__m128 *)sinCoeff2_0),
                      v28),
                    v27),
                  v27),
                v25)),
            _mm_xor_ps(
              (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v23, v23), v24), 0x1Du),
              _mm_and_ps(v21, *(__m128 *)_xmm)));
    steerForwardOut->m_quad = _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v29, v29, 0), v15),
                                _mm_mul_ps(_mm_shuffle_ps(v29, v29, 85), forward->m_quad));
  }
  else
  {
    v30 = _mm_mul_ps(forward->m_quad, m_quad);
    v31 = _mm_sub_ps(
            forward->m_quad,
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                _mm_shuffle_ps(v30, v30, 170)),
              m_quad));
    v32 = _mm_mul_ps(v31, v31);
    v33 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
            _mm_shuffle_ps(v32, v32, 170));
    v34 = _mm_rsqrt_ps(v33);
    v35 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)), _mm_mul_ps(*(__m128 *)_xmm, v34));
    v36 = _mm_mul_ps(m_quad, (__m128)v11);
    v77 = _mm_mul_ps(v31, _mm_andnot_ps(_mm_cmple_ps(v33, (__m128)0i64), v35));
    v37 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v77, v77, 201), m_quad),
            _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v77));
    v38 = _mm_shuffle_ps(v37, v37, 201);
    v39 = (__m128)LODWORD(timestep);
    v39.m128_f32[0] = timestep * 2.0;
    v40 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(
                (__m128)v11,
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                    _mm_shuffle_ps(v36, v36, 170)),
                  m_quad)),
              _mm_shuffle_ps(v39, v39, 0)),
            v77);
    v41 = _mm_mul_ps(v40, v40);
    v42 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
            _mm_shuffle_ps(v41, v41, 170));
    v43 = _mm_rsqrt_ps(v42);
    v44 = _mm_load_si128((const __m128i *)_xmm);
    v45 = _mm_mul_ps(
            v40,
            _mm_andnot_ps(
              _mm_cmple_ps(v42, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v43, v42), v43)),
                _mm_mul_ps(*(__m128 *)_xmm, v43))));
    v46 = _mm_mul_ps(v45, v77);
    v47 = _mm_add_epi32(v44, v44);
    v48 = (float)(_mm_shuffle_ps(v46, v46, 85).m128_f32[0] + _mm_shuffle_ps(v46, v46, 0).m128_f32[0])
        + _mm_shuffle_ps(v46, v46, 170).m128_f32[0];
    v49 = _mm_mul_ps(v45, v38);
    v50 = (__m128i)_mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)),
                     _mm_shuffle_ps(v49, v49, 170));
    *(float *)&movementPropertiesa = timestep * movementProperties->m_maxAngularVelocity;
    v51 = _mm_add_ps((__m128)movementPropertiesa, *(__m128 *)_xmm);
    v52 = _mm_andnot_ps(*(__m128 *)_xmm, v51);
    v53 = _mm_andnot_si128(v44, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v52, *(__m128 *)_xmm)), v44));
    v54 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v53, v47), (__m128i)0i64);
    v55 = _mm_cvtepi32_ps(v53);
    v56 = _mm_add_ps(
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(v55, *(__m128 *)DP1_0), v52), _mm_mul_ps(v55, *(__m128 *)DP2)),
            _mm_mul_ps(v55, *(__m128 *)DP3));
    v57 = _mm_mul_ps(v56, v56);
    v58 = timestep * movementProperties->m_maxAngularVelocity;
    v59 = _mm_xor_ps(
            _mm_xor_ps(
              _mm_and_ps(v51, *(__m128 *)_xmm),
              (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v47, v47), v53), 0x1Du)),
            _mm_or_ps(
              _mm_andnot_ps(
                v54,
                _mm_add_ps(
                  _mm_sub_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v57, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v57),
                          *(__m128 *)cosCoeff2_0),
                        v57),
                      v57),
                    _mm_mul_ps(v57, *(__m128 *)_xmm)),
                  *(__m128 *)_xmm)),
              _mm_and_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v57, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v57),
                        *(__m128 *)sinCoeff2_0),
                      v57),
                    v56),
                  v56),
                v54)));
    v60 = _mm_shuffle_ps(v59, v59, 0);
    if ( *(float *)&movementPropertiesa < 3.1415927 && v48 < v60.m128_f32[0] )
    {
      v48 = v60.m128_f32[0];
      v61 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(v58));
      v62 = _mm_andnot_si128(v44, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v61, *(__m128 *)_xmm)), v44));
      v63 = _mm_cvtepi32_ps(v62);
      v64 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v62, v47), (__m128i)0i64);
      v65 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v63, *(__m128 *)DP1_0), v61), _mm_mul_ps(v63, *(__m128 *)DP2)),
              _mm_mul_ps(v63, *(__m128 *)DP3));
      v66 = _mm_mul_ps(v65, v65);
      v67 = _mm_xor_ps(
              _mm_or_ps(
                _mm_and_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v66, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v66),
                          *(__m128 *)sinCoeff2_0),
                        v66),
                      v65),
                    v65),
                  v64),
                _mm_andnot_ps(
                  v64,
                  _mm_add_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v66, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v66),
                            *(__m128 *)cosCoeff2_0),
                          v66),
                        v66),
                      _mm_mul_ps(v66, *(__m128 *)_xmm)),
                    *(__m128 *)_xmm))),
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v47, v47), v62), 0x1Du),
                _mm_and_ps((__m128)LODWORD(v58), *(__m128 *)_xmm)));
      v50 = (__m128i)_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v50, 0x1Fu), 0x1Fu), _mm_shuffle_ps(v67, v67, 0));
      v45 = _mm_add_ps(_mm_mul_ps(v60, v77), _mm_mul_ps(v38, (__m128)v50));
    }
    v68 = _mm_rcp_ps((__m128)LODWORD(v48));
    v69 = _mm_mul_ps(v68, (__m128)v50.m128i_u32[0]);
    v70 = _mm_or_ps(_mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v69), _mm_cmplt_ps(*(__m128 *)_xmm, v69));
    v71 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v69), v70), _mm_andnot_ps(v70, v69));
    v72 = _mm_mul_ps(v71, v71);
    v73 = _mm_mul_ps(
            _mm_rcp_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_rcp_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_rcp_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v72, *(__m128 *)s0)), *(__m128 *)t0),
                            _mm_add_ps(v72, *(__m128 *)s1))),
                        *(__m128 *)t1),
                      _mm_add_ps(v72, *(__m128 *)s2))),
                  *(__m128 *)t2),
                _mm_add_ps(v72, *(__m128 *)s3))),
            _mm_mul_ps(v71, *(__m128 *)t3));
    v74 = _mm_cmple_ps((__m128)0i64, v68);
    v75 = _mm_or_ps(
            _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v71, *(__m128 *)_xmm), *(__m128 *)_xmm), v73), v70),
            _mm_andnot_ps(v70, v73));
    v76 = _mm_or_ps(
            _mm_andnot_ps(
              v74,
              _mm_add_ps(_mm_or_ps(_mm_and_ps((__m128)v50.m128i_u32[0], *(__m128 *)_xmm), *(__m128 *)_xmm), v75)),
            _mm_and_ps(v75, v74));
    v76.m128_f32[0] = v76.m128_f32[0] / timestep;
    angularVelocityOut->m_real = _mm_shuffle_ps(v76, v76, 0);
    *steerForwardOut = (hkVector4f)v45;
  }
}

