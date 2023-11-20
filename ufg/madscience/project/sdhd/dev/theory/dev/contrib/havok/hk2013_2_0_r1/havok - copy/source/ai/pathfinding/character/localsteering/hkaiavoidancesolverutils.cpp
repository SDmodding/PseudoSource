// File Line: 32
// RVA: 0xBE1530
void __fastcall collectNavMeshBoundaries(hkaiCharacter *character, hkaiStreamingCollection::InstanceInfo *sectionInfo, unsigned int navMeshFaceKey, hkaiObstacleCollector *collector)
{
  hkaiAvoidanceProperties *v4; // rax
  hkVector4f *position; // rdi
  hkaiCharacter *v6; // rbx
  hkaiObstacleCollector *v7; // rsi
  unsigned int v8; // er14
  hkVector4f v9; // xmm0
  hkVector4f v10; // xmm1
  hkaiStreamingCollection::InstanceInfo *v11; // r15
  hkLifoAllocator *v12; // rax
  hkVector4f *v13; // rdx
  unsigned __int64 v14; // rcx
  unsigned int v15; // eax
  float v16; // xmm0_4
  hkaiAvoidanceProperties *v17; // rax
  int v18; // ecx
  int v19; // edi
  int v20; // ebx
  char *v21; // rdi
  signed int v22; // ebx
  hkLifoAllocator *v23; // rax
  int v24; // er8
  hkArrayBase<hkVector4f> boundariesOut; // [rsp+50h] [rbp-9h]
  void *p; // [rsp+60h] [rbp+7h]
  int v27; // [rsp+68h] [rbp+Fh]
  hkAabb aabb; // [rsp+70h] [rbp+17h]
  hkaiAgentTraversalInfo traversalInfo; // [rsp+C0h] [rbp+67h]

  v4 = character->m_avoidanceProperties.m_pntr;
  position = &character->m_position;
  v6 = character;
  v7 = collector;
  v8 = navMeshFaceKey;
  v9.m_quad = _mm_add_ps(character->m_position.m_quad, v4->m_localSensorAabb.m_min.m_quad);
  v10.m_quad = _mm_add_ps(character->m_position.m_quad, v4->m_localSensorAabb.m_max.m_quad);
  v11 = sectionInfo;
  boundariesOut.m_capacityAndFlags = 2147483648;
  v27 = 32;
  aabb.m_min = (hkVector4f)v9.m_quad;
  aabb.m_max = (hkVector4f)v10.m_quad;
  boundariesOut.m_data = 0i64;
  boundariesOut.m_size = 0;
  v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (hkVector4f *)v12->m_cur;
  v14 = (unsigned __int64)&v13[32];
  if ( v12->m_slabSize < 512 || (void *)v14 > v12->m_end )
    v13 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v12, 512);
  else
    v12->m_cur = (void *)v14;
  v15 = v6->m_agentFilterInfo;
  v16 = v6->m_radius;
  boundariesOut.m_data = v13;
  traversalInfo.m_filterInfo = v15;
  v17 = v6->m_avoidanceProperties.m_pntr;
  p = v13;
  traversalInfo.m_diameter = v16 * 2.0;
  boundariesOut.m_capacityAndFlags = -2147483616;
  hkaiNavMeshUtils::getNearbyBoundaries(
    v11,
    v8,
    &aabb,
    &traversalInfo,
    v6->m_edgeFilter.m_pntr,
    v17->m_nearbyBoundariesSearchType.m_storage == 1,
    position,
    &v6->m_up,
    &boundariesOut);
  v18 = boundariesOut.m_size;
  v19 = 0;
  if ( boundariesOut.m_size / 2 > 0 )
  {
    v20 = 0;
    do
    {
      hkaiObstacleCollector::addBoundary(v7, &boundariesOut.m_data[v20], &boundariesOut.m_data[v20 + 1]);
      v18 = boundariesOut.m_size;
      ++v19;
      v20 += 2;
    }
    while ( v19 < boundariesOut.m_size / 2 );
  }
  v21 = (char *)p;
  if ( p == boundariesOut.m_data )
    v18 = 0;
  boundariesOut.m_size = v18;
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
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      boundariesOut.m_data,
      16 * boundariesOut.m_capacityAndFlags);
}

// File Line: 53
// RVA: 0xBE1740
void __fastcall processObstacleGenerators(hkaiCharacter *character, hkArrayBase<hkaiObstacleGenerator const *> *obstacleGenerators, hkaiObstacleCollector *collector)
{
  hkaiAvoidanceProperties *v3; // rax
  int v4; // ebx
  hkaiObstacleCollector *v5; // rbp
  hkArrayBase<hkaiObstacleGenerator const *> *v6; // rsi
  hkVector4f v7; // xmm2
  __int64 v8; // rdi
  hkAabb sensorAabb; // [rsp+20h] [rbp-28h]

  v3 = character->m_avoidanceProperties.m_pntr;
  v4 = 0;
  v5 = collector;
  v6 = obstacleGenerators;
  v7.m_quad = _mm_add_ps(character->m_position.m_quad, v3->m_localSensorAabb.m_max.m_quad);
  sensorAabb.m_min.m_quad = _mm_add_ps(character->m_position.m_quad, v3->m_localSensorAabb.m_min.m_quad);
  sensorAabb.m_max = (hkVector4f)v7.m_quad;
  if ( obstacleGenerators->m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      hkaiObstacleGenerator::appendObstacles(v6->m_data[v8], &sensorAabb, v5);
      ++v4;
      ++v8;
    }
    while ( v4 < v6->m_size );
  }
}

// File Line: 85
// RVA: 0xBDE3C0
void __fastcall hkaiAvoidanceSolverUtils::setupAgent(hkaiLocalSteeringInput *steeringInput, hkaiStreamingCollection::InstanceInfo *sectionInfo, unsigned int navMeshFaceKey, float erosionRadius)
{
  hkaiLocalSteeringInput *v4; // rsi
  unsigned int v5; // edi
  float v6; // xmm10_4
  _QWORD *v7; // r10
  unsigned __int64 v8; // r9
  unsigned __int64 v9; // rax
  hkaiCharacter *v10; // r13
  __m128 v11; // xmm9
  char v12; // bl
  int v13; // er14
  hkArrayBase<hkaiObstacleGenerator const *> *v14; // rsi
  bool v15; // zf
  _QWORD *v16; // rdi
  char v17; // di
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  signed __int64 v21; // rcx
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
  __m128 v32; // xmm0
  int v33; // eax
  _QWORD *v34; // r8
  _QWORD *v35; // rcx
  unsigned __int64 v36; // rax
  signed __int64 v37; // rcx
  int v38; // er11
  hkaiReferenceFrame *v39; // rbx
  unsigned __int64 v40; // rcx
  __int64 v41; // rsi
  hkVector4f *v42; // rdi
  __m128 v43; // xmm0
  __m128 v44; // xmm3
  hkaiAvoidanceSolver::ObstacleAgent *v45; // r10
  __m128 v46; // xmm2
  __m128 v47; // xmm2
  __m128 v48; // xmm2
  float v49; // xmm0_4
  __int64 v50; // r8
  __int64 v51; // rax
  __int64 v52; // r9
  _DWORD *v53; // rcx
  signed __int64 v54; // rax
  float v55; // xmm1_4
  int v56; // xmm0_4
  int v57; // eax
  int v58; // eax
  float v59; // xmm0_4
  __int64 v60; // r9
  __int64 v61; // rcx
  __int64 v62; // r10
  _DWORD *v63; // rax
  int v64; // xmm1_4
  int v65; // xmm0_4
  _QWORD *v66; // r8
  _QWORD *v67; // rcx
  unsigned __int64 v68; // rax
  signed __int64 v69; // rcx
  hkVector4f worldDir; // [rsp+48h] [rbp-80h]
  hkVector4f localDirOut; // [rsp+58h] [rbp-70h]
  hkVector4f localPosOut; // [rsp+68h] [rbp-60h]
  hkVector4f localUpOut; // [rsp+78h] [rbp-50h]
  hkaiLocalSteeringInput *v74; // [rsp+118h] [rbp+50h]
  hkaiStreamingCollection::InstanceInfo *sectionInfoa; // [rsp+120h] [rbp+58h]
  unsigned int navMeshFaceKeya; // [rsp+128h] [rbp+60h]
  __int64 v77; // [rsp+138h] [rbp+70h]
  hkArrayBase<hkaiObstacleGenerator const *> *vars0; // [rsp+140h] [rbp+78h]
  signed int *retaddr; // [rsp+148h] [rbp+80h]
  hkaiLocalSteeringInput *v80; // [rsp+150h] [rbp+88h]
  hkaiObstacleCollector *v81; // [rsp+158h] [rbp+90h]

  v81 = (hkaiObstacleCollector *)sectionInfo;
  v80 = steeringInput;
  v4 = steeringInput;
  v5 = navMeshFaceKey;
  v6 = erosionRadius;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = v7[1];
  if ( v8 < v7[3] )
  {
    *(_QWORD *)v8 = "LtsetupAgent";
    *(_QWORD *)(v8 + 16) = "Stinit";
    v9 = __rdtsc();
    *(_DWORD *)(v8 + 8) = v9;
    v7[1] = v8 + 24;
  }
  v10 = v4->m_character;
  v11 = v4->m_currentUp.m_quad;
  v12 = v10->m_avoidanceEnabledMask.m_storage;
  v13 = 0;
  worldDir.m_quad.m128_i8[9] = v12;
  if ( !(v12 & 7) )
    goto LABEL_8;
  v14 = vars0;
  v15 = v5 == -1;
  v16 = (_QWORD *)v77;
  if ( v15 && !*(_DWORD *)(v77 + 8) && !vars0->m_size )
  {
    v4 = v74;
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
    v37 = (signed __int64)(v35 + 2);
    *(_DWORD *)(v37 - 8) = v36;
    v34[1] = v37;
  }
  localDirOut.m_quad.m128_u64[1] = (unsigned __int64)v74->m_referenceFrame;
  v81->m_referenceFrame = (hkaiReferenceFrame *)localDirOut.m_quad.m128_u64[1];
  if ( v12 & 1 )
    collectNavMeshBoundaries(v10, sectionInfoa, navMeshFaceKeya, v81);
  if ( v12 & 4 )
    processObstacleGenerators(v10, v14, v81);
  v81->m_referenceFrame = 0i64;
  if ( v12 & 2 )
  {
    v38 = 0;
    worldDir.m_quad.m128_i32[3] = 0;
    if ( v81->m_neighborAgents.m_size > 0 )
    {
      v39 = (hkaiReferenceFrame *)localDirOut.m_quad.m128_u64[1];
      v40 = 0i64;
      localDirOut.m_quad.m128_u64[0] = 0i64;
      v41 = 0i64;
      do
      {
        v42 = *(hkVector4f **)(v40 + *v16);
        if ( v10->m_avoidanceProperties.m_pntr->m_movementProperties.m_kinematicConstraintType.m_storage == 1 )
          v43 = v42[3].m_quad;
        else
          v43 = 0i64;
        worldDir.m_quad = v43;
        if ( v39 )
        {
          hkaiReferenceFrame::transformWorldPosDirVelToLocalPosDirVel(
            v39,
            v42 + 2,
            &worldDir,
            v42 + 4,
            v42 + 5,
            &localPosOut,
            &localDirOut,
            (hkVector4f *)((char *)&localPosOut + 8),
            &localUpOut);
          v38 = worldDir.m_quad.m128_i32[3];
          v40 = localDirOut.m_quad.m128_u64[0];
          v44 = localPosOut.m_quad;
        }
        else
        {
          v44 = v42[2].m_quad;
          localDirOut.m_quad = v43;
          localPosOut.m_quad = v44;
          *(hkVector4f *)((char *)&localPosOut + 8) = v42[4];
          localUpOut.m_quad = (__m128)v42[5];
        }
        v45 = v81->m_neighborAgents.m_data;
        v46 = _mm_mul_ps(v11, v44);
        v45[v41].m_position.m_quad = _mm_add_ps(
                                       _mm_mul_ps(
                                         _mm_sub_ps(
                                           (__m128)0i64,
                                           _mm_add_ps(
                                             _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
                                             _mm_shuffle_ps(v46, v46, 170))),
                                         v11),
                                       v44);
        v47 = _mm_mul_ps(v11, *(__m128 *)((char *)&localPosOut.m_quad + 8));
        v45[v41].m_velocity.m_quad = _mm_add_ps(
                                       _mm_mul_ps(
                                         _mm_sub_ps(
                                           (__m128)0i64,
                                           _mm_add_ps(
                                             _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
                                             _mm_shuffle_ps(v47, v47, 170))),
                                         v11),
                                       *(__m128 *)((char *)&localPosOut.m_quad + 8));
        v48 = _mm_mul_ps(v11, localDirOut.m_quad);
        v45[v41].m_forward.m_quad = _mm_add_ps(
                                      _mm_mul_ps(
                                        _mm_sub_ps(
                                          (__m128)0i64,
                                          _mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v48, v48, 85), _mm_shuffle_ps(v48, v48, 0)),
                                            _mm_shuffle_ps(v48, v48, 170))),
                                        v11),
                                      localDirOut.m_quad);
        v45[v41].m_avoidanceProperties = (hkaiAvoidanceProperties *)v42[9].m_quad.m128_u64[1];
        v45[v41].m_priority = v42[10].m_quad.m128_u16[2];
        v49 = v42[6].m_quad.m128_f32[1];
        v45[v41].m_weight = 0.5;
        v45[v41].m_radius = v49;
        v45[v41].m_boundaryRadius = v49;
        if ( retaddr )
        {
          v50 = retaddr[6];
          v51 = 0i64;
          if ( v50 > 0 )
          {
            v52 = *((_QWORD *)retaddr + 2);
            v53 = (_DWORD *)*((_QWORD *)retaddr + 2);
            while ( v42[10].m_quad.m128_u16[4] + (v10->m_avoidanceType << 16) != *v53 )
            {
              ++v51;
              v53 += 3;
              if ( v51 >= v50 )
                goto LABEL_35;
            }
            v54 = 3 * v51;
            v55 = *(float *)(v52 + 4 * v54 + 4);
            localDirOut.m_quad.m128_i32[2] = *(_DWORD *)(v52 + 4 * v54);
            v56 = *(_DWORD *)(v52 + 4 * v54 + 8);
            v45[v41].m_weight = v55;
            localPosOut.m_quad.m128_i32[0] = v56;
LABEL_35:
            v40 = localDirOut.m_quad.m128_u64[0];
          }
        }
        v16 = (_QWORD *)v77;
        ++v38;
        v40 += 8i64;
        ++v41;
        worldDir.m_quad.m128_i32[3] = v38;
        localDirOut.m_quad.m128_u64[0] = v40;
      }
      while ( v38 < v81->m_neighborAgents.m_size );
      v12 = worldDir.m_quad.m128_i8[9];
    }
  }
  v4 = v74;
  v17 = worldDir.m_quad.m128_i8[8];
LABEL_9:
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  if ( (unsigned __int64)v19 < v18[3] )
  {
    *v19 = "StagentSetup";
    v20 = __rdtsc();
    v21 = (signed __int64)(v19 + 2);
    *(_DWORD *)(v21 - 8) = v20;
    v18[1] = v21;
  }
  v22 = _mm_mul_ps(v11, v4->m_currentVelocity.m_quad);
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)), _mm_shuffle_ps(v22, v22, 170));
  v24 = _mm_mul_ps(v11, v4->m_currentForward.m_quad);
  v25 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, v23), v11);
  v26 = _mm_sub_ps(
          (__m128)0i64,
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
            _mm_shuffle_ps(v24, v24, 170)));
  v27 = _mm_mul_ps(v11, v4->m_currentPosition.m_quad);
  v28 = _mm_add_ps(_mm_mul_ps(v26, v11), v4->m_currentForward.m_quad);
  v29 = _mm_mul_ps(v28, v28);
  v30 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)), _mm_shuffle_ps(v29, v29, 170));
  v31 = _mm_rsqrt_ps(v30);
  v32 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                _mm_shuffle_ps(v27, v27, 170))),
            v11),
          v4->m_currentPosition.m_quad);
  v80->m_currentForward.m_quad = _mm_add_ps(v25, v4->m_currentVelocity.m_quad);
  v80->m_currentPosition.m_quad = v32;
  v80->m_currentUp.m_quad = _mm_mul_ps(
                              _mm_andnot_ps(
                                _mm_cmpleps(v30, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                                  _mm_mul_ps(*(__m128 *)_xmm, v31))),
                              v28);
  v80->m_desiredFutureDir = v4->m_currentPosition;
  v80->m_localGoalPlane = v4->m_currentForward;
  *(hkVector4f *)&v80->m_distToLocalGoal = v4->m_currentUp;
  *(hkVector4f *)&v80->m_referenceFrame = v4->m_currentVelocity;
  *(hkVector4f *)&v80->m_isLocalGoalLast.m_bool = v4->m_desiredVelocity;
  v80[1].m_currentPosition = v4->m_desiredFutureDir;
  v80[1].m_currentForward = v4->m_localGoalPlane;
  v80[1].m_currentUp.m_quad.m128_i32[0] = LODWORD(v4->m_distToLocalGoal);
  v80[1].m_currentUp.m_quad.m128_i32[1] = LODWORD(v4->m_timeToLocalGoal);
  v80[1].m_currentUp.m_quad.m128_u64[1] = (unsigned __int64)v4->m_character;
  v80[1].m_currentVelocity.m_quad.m128_u64[0] = (unsigned __int64)v4->m_referenceFrame;
  v80[1].m_currentVelocity.m_quad.m128_u64[1] = (unsigned __int64)v4->m_avoidanceProperties;
  v80[1].m_desiredVelocity.m_quad.m128_i8[0] = v4->m_isLocalGoalLast.m_bool;
  v80[1].m_desiredVelocity.m_quad.m128_i8[1] = v4->m_applyKinematicConstraints.m_bool;
  v80[1].m_desiredVelocity.m_quad.m128_i8[2] = v4->m_applyAvoidanceSteering.m_bool;
  v80[1].m_desiredVelocity.m_quad.m128_i8[3] = v4->m_enableLocalSteering.m_bool;
  v80->m_currentVelocity.m_quad.m128_u64[0] = (unsigned __int64)v10->m_avoidanceProperties.m_pntr;
  if ( v12 & 2 )
    v33 = v81->m_neighborAgents.m_size;
  else
    v33 = 0;
  v80[1].m_desiredFutureDir.m_quad.m128_i32[2] = v33;
  if ( v12 & 5 )
    v57 = v81->m_boundaries.m_size;
  else
    v57 = 0;
  v80[1].m_localGoalPlane.m_quad.m128_i32[2] = v57;
  if ( v12 & 4 )
    v58 = v81->m_spheres.m_size;
  else
    v58 = 0;
  LODWORD(v80[1].m_character) = v58;
  if ( v17 )
  {
    v80[1].m_desiredFutureDir.m_quad.m128_u64[0] = (unsigned __int64)v81->m_neighborAgents.m_data;
    v80[1].m_localGoalPlane.m_quad.m128_u64[0] = (unsigned __int64)v81->m_boundaries.m_data;
    *(_QWORD *)&v80[1].m_distToLocalGoal = v81->m_spheres.m_data;
    v80->m_currentVelocity.m_quad.m128_i16[4] = v10->m_agentPriority;
    v59 = v10->m_radius;
    v80->m_desiredVelocity.m_quad.m128_i32[1] = 1056964608;
    v80->m_currentVelocity.m_quad.m128_f32[3] = v59;
    LODWORD(v74) = 0;
    v80->m_desiredVelocity.m_quad.m128_f32[0] = fmaxf(0.0, v59 - v6);
    if ( retaddr )
    {
      v60 = retaddr[6];
      v61 = 0i64;
      if ( v60 > 0 )
      {
        v62 = *((_QWORD *)retaddr + 2);
        v63 = (_DWORD *)*((_QWORD *)retaddr + 2);
        while ( 65537 * v10->m_avoidanceType != *v63 )
        {
          ++v61;
          ++v13;
          v63 += 3;
          if ( v61 >= v60 )
            goto LABEL_54;
        }
        v64 = *(_DWORD *)(v62 + 12i64 * v13 + 4);
        localDirOut.m_quad.m128_i32[2] = *(_DWORD *)(v62 + 12i64 * v13);
        v65 = *(_DWORD *)(v62 + 12i64 * v13 + 8);
        v80->m_desiredVelocity.m_quad.m128_i32[1] = v64;
        localPosOut.m_quad.m128_i32[0] = v65;
      }
    }
LABEL_54:
    BYTE4(v80[1].m_character) = 0;
  }
  v66 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v67 = (_QWORD *)v66[1];
  if ( (unsigned __int64)v67 < v66[3] )
  {
    *v67 = "lt";
    v68 = __rdtsc();
    v69 = (signed __int64)(v67 + 2);
    *(_DWORD *)(v69 - 8) = v68;
    v66[1] = v69;
  }
}

// File Line: 267
// RVA: 0xBE11C0
void __fastcall hkaiAvoidanceSolverUtils::manageAgentPenetration(float timestep, hkaiAvoidanceSolver::SteeringAgent *agent, hkaiAvoidanceSolver::ObstacleAgent *obstacle, hkaiAvoidanceSolver::ControlGradient *gradient)
{
  float v4; // xmm6_4
  __m128 v5; // xmm5
  __m128 v6; // xmm2
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v10; // xmm5
  float v11; // xmm4_4
  __m128 v12; // xmm1
  __m128 v13; // xmm0

  v4 = timestep;
  v5 = _mm_sub_ps(obstacle->m_position.m_quad, agent->m_position.m_quad);
  v6 = _mm_mul_ps(v5, v5);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v8 = _mm_rsqrt_ps(v7);
  v9 = _mm_andnot_ps(
         _mm_cmpleps(v7, (__m128)0i64),
         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)), _mm_mul_ps(*(__m128 *)_xmm, v8)));
  v10 = _mm_mul_ps(v5, v9);
  v11 = (float)(agent->m_radius + obstacle->m_radius) - (float)(v9.m128_f32[0] * v7.m128_f32[0]);
  if ( v11 > 0.0 )
  {
    v12 = _mm_mul_ps(agent->m_velocity.m_quad, v10);
    v13 = 0u;
    v13.m128_f32[0] = COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                     fminf(
                                       fmaxf(
                                         (float)((float)(fminf(
                                                           fmaxf(
                                                             (float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85))
                                                                   + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
                                                           + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170)),
                                                             v4),
                                                           1.0)
                                                       * 0.5)
                                               * v11)
                                       / v4,
                                         0.0),
                                       (float)(v4 * 2.0)
                                     * agent->m_avoidanceProperties->m_movementProperties.m_maxDeceleration)) ^ _xmm[0]);
    gradient->m_repulsion.m_quad = _mm_add_ps(
                                     _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v10),
                                     gradient->m_repulsion.m_quad);
    gradient->m_repulsion.m_quad.m128_f32[3] = v11;
  }
}

// File Line: 303
// RVA: 0xBE1310
void __fastcall hkaiAvoidanceSolverUtils::manageObstaclePenetration(float timestep, hkaiAvoidanceSolver::SteeringAgent *agent, hkaiAvoidanceSolver::SphereObstacle *obstacle, hkaiAvoidanceSolver::ControlGradient *gradient)
{
  float v4; // xmm6_4
  __m128 v5; // xmm5
  __m128 v6; // xmm2
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v10; // xmm5
  float v11; // xmm4_4
  __m128 v12; // xmm1
  __m128 v13; // xmm0

  v4 = timestep;
  v5 = _mm_sub_ps(obstacle->m_sphere.m_pos.m_quad, agent->m_position.m_quad);
  v6 = _mm_mul_ps(v5, v5);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v8 = _mm_rsqrt_ps(v7);
  v9 = _mm_andnot_ps(
         _mm_cmpleps(v7, (__m128)0i64),
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
                        (float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
                      + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170)),
                        timestep * agent->m_avoidanceProperties->m_movementProperties.m_maxDeceleration),
                      agent->m_avoidanceProperties->m_movementProperties.m_maxVelocity)
                  * 0.5);
    v13.m128_f32[0] = COERCE_FLOAT(COERCE_UNSIGNED_INT(fminf(fmaxf(v11 / v4, 0.0), v13.m128_f32[0])) ^ _xmm[0]);
    gradient->m_repulsion.m_quad = _mm_add_ps(
                                     _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v10),
                                     gradient->m_repulsion.m_quad);
    gradient->m_repulsion.m_quad.m128_f32[3] = v11;
  }
}

// File Line: 327
// RVA: 0xBE1450
void __fastcall hkaiAvoidanceSolverUtils::manageBoundaryPenetration(float timestep, hkaiAvoidanceSolver::SteeringAgent *agent, hkVector4f *boundaryPlane, const float closestDist, hkaiAvoidanceSolver::ControlGradient *gradient)
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
                                    (float)(COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 85))
                                          + COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 0)))
                                  + COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 170))) ^ _xmm[0]),
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
void __usercall hkaiAvoidanceSolverUtils::applyKinematicConstraints(float timestep@<xmm0>, hkaiMovementProperties *movementLimits@<rdx>, hkVector4f *up@<r8>, hkVector4f *oldVelocity@<r9>, __m128 a5@<xmm14>, hkVector4f *oldForward, hkVector4f *desiredVelocity, hkVector4f *constrainedVelocity, bool limitEnabled)
{
  char v9; // al
  hkVector4f *v10; // r14
  hkVector4f *v11; // rdi
  hkaiMovementProperties *v12; // rbx
  float v13; // xmm12_4
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
  __m128 v30; // xmm1
  __m128 v31; // xmm5
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  __m128 v36; // xmm4
  __m128 v37; // xmm1
  __m128 v38; // xmm3
  __m128 v39; // xmm2
  float v40; // xmm11_4
  float v41; // xmm13_4
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm1
  __m128 v45; // xmm14
  __m128 v46; // xmm15
  __m128 v47; // xmm5
  __m128 v48; // xmm2
  float v49; // xmm15_4
  __m128 v50; // xmm9
  __m128 v51; // xmm7
  __m128 v52; // xmm6
  __m128 v53; // xmm2
  __m128 v54; // xmm5
  __m128 v55; // xmm4
  __m128 v56; // xmm3
  __m128 v57; // xmm2
  __m128 v58; // xmm10
  __m128 v59; // xmm10
  float v60; // xmm2_4
  float v61; // xmm1_4
  __m128 v62; // xmm2
  hkVector4f vel; // [rsp+30h] [rbp-99h]
  hkQuaternionf quat; // [rsp+40h] [rbp-89h]
  float v65; // [rsp+118h] [rbp+4Fh]
  float v66; // [rsp+118h] [rbp+4Fh]
  float v67; // [rsp+118h] [rbp+4Fh]

  v9 = movementLimits->m_kinematicConstraintType.m_storage;
  v10 = oldVelocity;
  v11 = up;
  v12 = movementLimits;
  v13 = timestep;
  if ( v9 )
  {
    if ( v9 == 2 )
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
                _mm_cmpleps(v21, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                  _mm_mul_ps(*(__m128 *)_xmm, v22))),
              v17);
      v25 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
              _mm_shuffle_ps(v23, v23, 170));
      v26 = _mm_rsqrt_ps(v25);
      v27 = _mm_andnot_ps(
              _mm_cmpleps(v25, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                _mm_mul_ps(*(__m128 *)_xmm, v26)));
      v28 = _mm_mul_ps(v20, v27);
      v29 = _mm_mul_ps(v28, v24);
      v26.m128_f32[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 0)))
                      + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 170));
      v30 = (__m128)LODWORD(movementLimits->m_maxAcceleration);
      v30.m128_f32[0] = (float)((float)((float)((float)(v30.m128_f32[0] - movementLimits->m_maxDeceleration)
                                              * (float)(v26.m128_f32[0] - -1.0))
                                      * 0.5)
                              + movementLimits->m_maxDeceleration)
                      * timestep;
      v31 = _mm_add_ps(_mm_mul_ps(_mm_min_ps(_mm_mul_ps(v27, v25), _mm_shuffle_ps(v30, v30, 0)), v28), v17);
      v32 = _mm_mul_ps(v31, v31);
      v33 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
              _mm_shuffle_ps(v32, v32, 170));
      v34 = _mm_rsqrt_ps(v33);
      v35 = _mm_andnot_ps(
              _mm_cmpleps(v33, (__m128)0i64),
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
      v36 = desiredVelocity->m_quad;
      v37 = _mm_mul_ps(v36, v36);
      v38 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
              _mm_shuffle_ps(v37, v37, 170));
      v39 = _mm_rsqrt_ps(v38);
      LODWORD(v40) = (unsigned __int128)_mm_andnot_ps(
                                          _mm_cmpleps(v38, (__m128)0i64),
                                          _mm_mul_ps(
                                            _mm_mul_ps(
                                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
                                              _mm_mul_ps(*(__m128 *)_xmm, v39)),
                                            v38));
      if ( v40 <= 0.001 )
      {
        *constrainedVelocity = (hkVector4f)v36;
      }
      else
      {
        v41 = timestep * movementLimits->m_maxAngularVelocity;
        v42 = _mm_mul_ps(oldVelocity->m_quad, oldVelocity->m_quad);
        a5.m128_f32[0] = 1.0 / v40;
        v43 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)),
                _mm_shuffle_ps(v42, v42, 170));
        v44 = _mm_rsqrt_ps(v43);
        v45 = _mm_mul_ps(_mm_shuffle_ps(a5, a5, 0), v36);
        v46 = _mm_cmpleps(v43, (__m128)0i64);
        v47 = _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v44, v43), v44)),
                  _mm_mul_ps(*(__m128 *)_xmm, v44)),
                v43);
        v48 = _mm_mul_ps(v45, oldForward->m_quad);
        LODWORD(v49) = (unsigned __int128)_mm_andnot_ps(v46, v47);
        v50 = _mm_min_ps(
                _mm_max_ps(
                  (__m128)COERCE_UNSIGNED_INT(
                            (float)(COERCE_FLOAT(_mm_shuffle_ps(v48, v48, 85))
                                  + COERCE_FLOAT(_mm_shuffle_ps(v48, v48, 0)))
                          + COERCE_FLOAT(_mm_shuffle_ps(v48, v48, 170))),
                  *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
                *(__m128 *)_xmm);
        v51 = _mm_andnot_ps(*(__m128 *)_xmm, v50);
        v52 = _mm_cmpltps(v51, *(__m128 *)_xmm);
        v53 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v51), *(__m128 *)_xmm);
        v54 = _mm_cmpltps(*(__m128 *)_xmm, v51);
        v55 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v53), v54), _mm_andnot_ps(v54, v51));
        v56 = _mm_or_ps(_mm_andnot_ps(v54, _mm_mul_ps(v51, v51)), _mm_and_ps(v54, v53));
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
        if ( (float)(1.5707964
                   - COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                                            v52,
                                                            _mm_or_ps(
                                                              _mm_and_ps(
                                                                _mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v57, v57)),
                                                                v54),
                                                              _mm_andnot_ps(v54, v57))) | v52.m128_i32[0] & v51.m128_i32[0]) ^ v50.m128_i32[0] & _xmm[0])) > v41 )
        {
          v58 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(oldForward->m_quad, oldForward->m_quad, 201), up->m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(up->m_quad, up->m_quad, 201), oldForward->m_quad));
          v59 = _mm_mul_ps(_mm_shuffle_ps(v58, v58, 201), v45);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v59, v59, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v59, v59, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v59, v59, 170))) < 0.0 )
            LODWORD(v41) ^= _xmm[0];
          hkQuaternionf::setAxisAngle(&quat, up, v41);
          hkVector4f::setRotatedDir(&vel, &quat, oldForward);
          v60 = hkaiAvoidanceSolverUtils::intersectVelLine(&vel, v10, desiredVelocity, v11);
          if ( v60 < 3.40282e38 )
          {
            if ( v12->m_kinematicConstraintType.m_storage == 1 )
              v65 = v12->m_maxTurnVelocity;
            else
              v65 = v12->m_maxVelocity;
            v61 = fminf(v40, v65);
            if ( limitEnabled )
              v66 = v61;
            else
              v66 = v12->m_minVelocity;
            v40 = fminf(fmaxf(v60, v66), v12->m_maxVelocity);
          }
          v45 = vel.m_quad;
        }
        v67 = fminf(
                fmaxf(v40 - v49, COERCE_FLOAT(COERCE_UNSIGNED_INT(v13 * v12->m_maxDeceleration) ^ _xmm[0])),
                v13 * v12->m_maxAcceleration)
            + v49;
        v62 = (__m128)LODWORD(v67);
        v62.m128_f32[0] = fminf(fmaxf(v67, v12->m_minVelocity), v12->m_maxVelocity);
        constrainedVelocity->m_quad = _mm_mul_ps(_mm_shuffle_ps(v62, v62, 0), v45);
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
char __fastcall hkaiAvoidanceSolverUtils::detectFrontArea(float radius, hkVector4f *agentPos, hkaiAvoidanceSolver::BoundaryObstacle *boundary, hkVector4f *boundaryPlane)
{
  __m128 v4; // xmm3
  __m128 v5; // xmm3
  __m128 v6; // xmm1
  __m128 v7; // xmm8
  __m128 v8; // xmm7
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  float v13; // xmm11_4
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  float v16; // xmm1_4
  char result; // al

  v4 = _mm_mul_ps(boundaryPlane->m_quad, agentPos->m_quad);
  v5 = _mm_shuffle_ps(v4, _mm_unpackhi_ps(v4, boundaryPlane->m_quad), 196);
  v6 = _mm_add_ps(_mm_shuffle_ps(v5, v5, 78), v5);
  if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 177)) + v6.m128_f32[0]) >= radius )
    goto LABEL_8;
  v7 = _mm_sub_ps(boundary->m_end.m_quad, boundary->m_start.m_quad);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  v11 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)), _mm_mul_ps(*(__m128 *)_xmm, v10));
  v12 = v9;
  LODWORD(v13) = (unsigned __int128)_mm_andnot_ps(_mm_cmpleps(v9, (__m128)0i64), _mm_mul_ps(v11, v9));
  v14 = _mm_rsqrt_ps(v12);
  v15 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmpleps(v12, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v12), v14)),
                _mm_mul_ps(*(__m128 *)_xmm, v14))),
            v7),
          _mm_sub_ps(agentPos->m_quad, boundary->m_start.m_quad));
  v16 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 170));
  if ( v16 < 0.0 )
    goto LABEL_9;
  if ( v16 <= v13 )
LABEL_8:
    result = 1;
  else
LABEL_9:
    result = 0;
  return result;
}

// File Line: 615
// RVA: 0xBE0110
void __fastcall hkaiAvoidanceSolverUtils::calcVOGradient(const float agentMinVel, hkVector4f *agentVel, hkaiDynamicObstacleSolver::VelocityObstacle *velocityObstacle, hkVector4f *preferred, hkVector4f *gradient)
{
  int v5; // ecx
  hkaiDynamicObstacleSolver::VelocityObstacle *v6; // rbx
  hkVector4f *v7; // rdi
  __m128 v8; // xmm5
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  float v13; // xmm4_4
  __m128 v14; // xmm7
  hkVector4f v15; // xmm2
  __m128 v16; // xmm1
  float v17; // xmm6_4
  hkVector4f v18; // xmm5
  hkaiDynamicObstacleSolver::VelocityObstacle *v19; // rax
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
  hkVector4f dvel; // [rsp+30h] [rbp-30h]

  v5 = velocityObstacle->m_gradientType;
  v6 = velocityObstacle;
  v7 = agentVel;
  if ( v5 != 1 )
  {
    v18.m_quad = (__m128)velocityObstacle->m_rightPlane;
    v19 = (hkaiDynamicObstacleSolver::VelocityObstacle *)((char *)velocityObstacle + 16);
    v20 = _mm_mul_ps(velocityObstacle->m_leftPlane.m_quad, agentVel->m_quad);
    v21 = _mm_shuffle_ps(v20, _mm_unpackhi_ps(v20, velocityObstacle->m_leftPlane.m_quad), 196);
    v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 78), v21);
    v23 = _mm_mul_ps(v18.m_quad, agentVel->m_quad);
    v24 = _mm_unpackhi_ps(v23, v18.m_quad);
    v25 = _mm_mul_ps(v18.m_quad, preferred->m_quad);
    v26 = fminf(fmaxf(COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 177)) + v22.m128_f32[0], 0.0), 3.40282e38);
    v27 = _mm_shuffle_ps(v23, v24, 196);
    v28 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 78), v27);
    v29 = _mm_mul_ps(preferred->m_quad, velocityObstacle->m_leftPlane.m_quad);
    v30 = fminf(fmaxf(COERCE_FLOAT(_mm_shuffle_ps(v28, v28, 177)) + v28.m128_f32[0], 0.0), 3.40282e38);
    v31 = fminf(
            fmaxf(
              (float)(COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 0)))
            + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 170)),
              -1.0),
            1.0);
    v32 = fminf(
            fmaxf(
              (float)(COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 0)))
            + COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 170)),
              -1.0),
            1.0);
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v26 - v30)) >> 1) >= 0.0049999999
      && COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v31 - v32)) >> 1) <= 0.0049999999
      || v5 != 3 )
    {
      if ( v30 > v26 )
        v19 = velocityObstacle;
      v35.m_quad = (__m128)v19->m_leftPlane;
      v34 = gradient;
      *gradient = (hkVector4f)v35.m_quad;
      if ( v26 >= v30 )
      {
        gradient->m_quad.m128_f32[3] = v30;
        return;
      }
    }
    else
    {
      if ( v31 > v32 )
        v19 = velocityObstacle;
      v33.m_quad = (__m128)v19->m_leftPlane;
      v34 = gradient;
      *gradient = (hkVector4f)v33.m_quad;
      if ( v32 >= v31 )
        v26 = v30;
    }
    v34->m_quad.m128_f32[3] = v26;
    return;
  }
  v8 = agentVel->m_quad;
  *gradient = (hkVector4f)agentVel->m_quad;
  v9 = _mm_mul_ps(v8, v8);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_rsqrt_ps(v10);
  v12 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)), _mm_mul_ps(*(__m128 *)_xmm, v11)),
          v10);
  LODWORD(v13) = (unsigned __int128)_mm_andnot_ps(_mm_cmpleps(v10, (__m128)0i64), v12);
  if ( v13 > 0.00000011920929 )
  {
    v14 = (__m128)COERCE_UNSIGNED_INT(v13 - agentMinVel);
    v12.m128_f32[0] = 1.0 / v13;
    v14.m128_f32[0] = fminf(fmaxf(v13 - agentMinVel, 0.0), v13);
    v15.m_quad = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), v8);
    v16 = _mm_xor_ps(v14, *(__m128 *)_xmm);
    *gradient = (hkVector4f)v15.m_quad;
    dvel.m_quad = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v15.m_quad);
    v17 = hkaiAvoidanceSolverUtils::intersectVelDeltaVelRVO(agentVel, &dvel, &velocityObstacle->m_leftPlane);
    gradient->m_quad.m128_f32[3] = fminf(
                                     fmaxf(
                                       fminf(
                                         v17,
                                         hkaiAvoidanceSolverUtils::intersectVelDeltaVelRVO(v7, &dvel, &v6->m_rightPlane)),
                                       0.0),
                                     1.0)
                                 * v14.m128_f32[0];
  }
}

// File Line: 663
// RVA: 0xBE10C0
void __fastcall hkaiAvoidanceSolverUtils::calcSphereCollisionTime(const float totalRadius, hkVector4f *agentToObstacle, hkVector4f *relativeVelocity, hkVector4f *up)
{
  hkaiAvoidanceSolverUtils::intersectVelCircle(relativeVelocity, totalRadius, agentToObstacle, up);
}

// File Line: 668
// RVA: 0xBE10E0
float __usercall hkaiAvoidanceSolverUtils::calcBoundaryCollisionTime@<xmm0>(const float radius@<xmm0>, hkVector4f *agentToStart@<rdx>, hkVector4f *agentToEnd@<r8>, hkVector4f *relativeVelocity@<r9>, __m128 a5@<xmm3>, hkVector4f *normal, hkVector4f *up)
{
  hkVector4f *v7; // rsi
  hkVector4f *v8; // rdi
  float v9; // xmm6_4
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  hkVector4f end; // [rsp+20h] [rbp-38h]
  hkVector4f start; // [rsp+30h] [rbp-28h]
  float v15; // [rsp+68h] [rbp+10h]
  float normala; // [rsp+80h] [rbp+28h]

  v7 = relativeVelocity;
  v8 = agentToStart;
  v9 = radius;
  a5.m128_f32[0] = radius;
  v10 = _mm_mul_ps(_mm_shuffle_ps(a5, a5, 0), normal->m_quad);
  v11 = _mm_add_ps(agentToEnd->m_quad, v10);
  start.m_quad = _mm_add_ps(agentToStart->m_quad, v10);
  end.m_quad = v11;
  v15 = hkaiAvoidanceSolverUtils::intersectVelCircle(relativeVelocity, radius, agentToEnd, up);
  normala = fminf(hkaiAvoidanceSolverUtils::intersectVelCircle(v7, v9, v8, up), v15);
  return fminf(normala, hkaiAvoidanceSolverUtils::intersectVelLine(v7, &start, &end, up));
}

// File Line: 682
// RVA: 0xBE0440
void __fastcall hkaiAvoidanceSolverUtils::calcBoundaryPlane(hkaiAvoidanceSolver::BoundaryObstacle *boundary, hkVector4f *up, hkVector4f *boundaryPlane)
{
  __m128 v3; // xmm6
  __m128 v4; // xmm6
  __m128 v5; // xmm6
  __m128 v6; // xmm1
  __m128 v7; // xmm3
  __m128 v8; // xmm2
  hkVector4f v9; // xmm5
  __m128 v10; // xmm2

  v3 = _mm_sub_ps(boundary->m_end.m_quad, boundary->m_start.m_quad);
  v4 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v3, v3, 201), up->m_quad),
         _mm_mul_ps(_mm_shuffle_ps(up->m_quad, up->m_quad, 201), v3));
  v5 = _mm_shuffle_ps(v4, v4, 201);
  v6 = _mm_mul_ps(v5, v5);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v8 = _mm_rsqrt_ps(v7);
  v9.m_quad = _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v7, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)),
                    _mm_mul_ps(*(__m128 *)_xmm, v8))),
                v5);
  *boundaryPlane = (hkVector4f)v9.m_quad;
  v10 = _mm_mul_ps(v9.m_quad, boundary->m_start.m_quad);
  boundaryPlane->m_quad = _mm_shuffle_ps(
                            v9.m_quad,
                            _mm_unpackhi_ps(
                              v9.m_quad,
                              _mm_sub_ps(
                                (__m128)0i64,
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                                  _mm_shuffle_ps(v10, v10, 170)))),
                            196);
}

// File Line: 692
// RVA: 0xBE0500
float __fastcall hkaiAvoidanceSolverUtils::intersectVelCircle(hkVector4f *vel, float circleRadius, hkVector4f *circlePos, hkVector4f *up)
{
  __m128 v4; // xmm7
  hkVector4f *v5; // rbx
  __m128 v6; // xmm3
  float v7; // xmm6_4
  float v9; // xmm0_4
  __m128 v10; // xmm3
  float v11; // xmm0_4
  __m128 v12; // xmm2
  float v13; // xmm4_4
  __m128 v14; // xmm3
  float v15; // xmm1_4

  v4 = circlePos->m_quad;
  v5 = vel;
  v6 = _mm_mul_ps(v4, v4);
  v7 = circleRadius * circleRadius;
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 170))) <= (float)(circleRadius * circleRadius) )
    return 0.0;
  v9 = hkaiAvoidanceSolverUtils::determinant2d(vel, circlePos, up);
  v10 = v5->m_quad;
  v11 = v9 * v9;
  v12 = _mm_mul_ps(v10, v10);
  v13 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170));
  if ( (float)((float)(v13 * v7) - v11) <= 0.0
    || (v14 = _mm_mul_ps(v10, v4),
        v15 = (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 85))
                                    + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 0)))
                            + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 170)))
                    - fsqrt((float)(v13 * v7) - v11))
            / v13,
        v15 < 0.0) )
  {
    v15 = FLOAT_3_40282e38;
  }
  return v15;
}

// File Line: 724
// RVA: 0xBE05F0
float __fastcall hkaiAvoidanceSolverUtils::intersectVelLine(hkVector4f *vel, hkVector4f *start, hkVector4f *end, hkVector4f *up)
{
  __m128 v4; // xmm7
  hkVector4f *v5; // rbx
  hkVector4f *v6; // rdi
  __m128 v7; // xmm10
  __m128 v8; // xmm10
  float v9; // xmm0_4
  float result; // xmm0_4
  float v11; // xmm6_4
  float v12; // xmm9_4
  float v13; // xmm0_4
  __m128 v14; // xmm10
  __m128 v15; // xmm10
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm4
  hkVector4f p; // [rsp+20h] [rbp-78h]
  hkVector4f q; // [rsp+30h] [rbp-68h]

  v4 = start->m_quad;
  v5 = up;
  v6 = vel;
  v7 = end->m_quad;
  p.m_quad = v4;
  v8 = _mm_sub_ps(v7, v4);
  q.m_quad = v8;
  v9 = hkaiAvoidanceSolverUtils::determinant2d(vel, &q, up);
  if ( v9 == 0.0 )
    return FLOAT_3_40282e38;
  v11 = 1.0 / v9;
  v12 = hkaiAvoidanceSolverUtils::determinant2d(&p, &q, v5) * (float)(1.0 / v9);
  p.m_quad = _mm_mul_ps(v4, *(__m128 *)_xmm_bf800000bf800000bf800000bf800000);
  LODWORD(v13) = COERCE_UNSIGNED_INT(hkaiAvoidanceSolverUtils::determinant2d(&p, v6, v5) * v11) ^ _xmm[0];
  if ( v13 < 0.0 || v13 > 1.0 )
    goto LABEL_12;
  if ( v12 > 0.0 )
    return v12;
  v14 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v5->m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v5->m_quad, v5->m_quad, 201), v8));
  v15 = _mm_shuffle_ps(v14, v14, 201);
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_rsqrt_ps(v17);
  v19 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmpleps(v17, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                _mm_mul_ps(*(__m128 *)_xmm, v18))),
            v15),
          v6->m_quad);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 170))) >= 0.0 )
LABEL_12:
    result = FLOAT_3_40282e38;
  else
    result = 0.0;
  return result;
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
  v7 = COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 177)) + v5.m128_f32[0];
  v8 = _mm_shuffle_ps(v6, _mm_unpackhi_ps(v6, planeB->m_quad), 196);
  v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 78), v8);
  v10 = COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 177)) + v9.m128_f32[0];
  return v7 >= 0.0 && v10 >= 0.0;
}

// File Line: 787
// RVA: 0xBE0D80
bool __fastcall hkaiAvoidanceSolverUtils::isAngleInsideVO(const float angle, const float openEdge, const float closeEdge)
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
float __fastcall hkaiAvoidanceSolverUtils::clampAngle(float result)
{
  if ( result < -3.1415927 )
    result = result + 6.2831855;
  if ( result > 3.1415927 )
    result = result + -6.2831855;
  return result;
}

// File Line: 822
// RVA: 0xBE0D00
float __fastcall hkaiAvoidanceSolverUtils::fabsAngle(const float openEdge, const float closeEdge)
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
    v2 = v2 + 6.2831855;
  return v2;
}

// File Line: 838
// RVA: 0xBE07B0
float __fastcall hkaiAvoidanceSolverUtils::intersectVelDeltaVelRVO(hkVector4f *vel, hkVector4f *dvel, hkVector4f *plane)
{
  __m128 v3; // xmm4
  __m128 v4; // xmm1
  __m128 v5; // xmm3
  __m128 v7; // xmm2
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  float v10; // xmm0_4
  float v11; // xmm4_4

  v3 = plane->m_quad;
  v4 = _mm_mul_ps(plane->m_quad, dvel->m_quad);
  v5 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)), _mm_shuffle_ps(v4, v4, 170));
  if ( v5.m128_f32[0] < 0.00000011920929 )
    return FLOAT_3_40282e38;
  v7 = _mm_mul_ps(vel->m_quad, v3);
  v8 = _mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, v3), 196);
  v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 78), v8);
  v10 = COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 177)) + v9.m128_f32[0];
  v9.m128_i32[0] = (unsigned __int128)_mm_rcp_ps(v5);
  v11 = (float)((float)(2.0 - (float)(v9.m128_f32[0] * v5.m128_f32[0])) * v9.m128_f32[0]) * (float)(0.0 - v10);
  if ( v11 < 0.0 )
    v11 = FLOAT_3_40282e38;
  return v11;
}

// File Line: 852
// RVA: 0xBE0850
float __fastcall hkaiAvoidanceSolverUtils::intersectVelDeltaVelVOEdge(hkVector4f *vel, hkVector4f *dvel, hkVector4f *up, hkVector4f *edge)
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
           _mm_cmpleps(v7, (__m128)0i64),
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)), _mm_mul_ps(*(__m128 *)_xmm, v8))));
  v10 = _mm_mul_ps(dvel->m_quad, v9);
  v11 = _mm_mul_ps(vel->m_quad, v9);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v13 = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, v9), 196);
  v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
  v15 = COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 177)) + v14.m128_f32[0];
  v14.m128_i32[0] = (unsigned __int128)_mm_rcp_ps(v12);
  result = (float)((float)(2.0 - (float)(v12.m128_f32[0] * v14.m128_f32[0])) * v14.m128_f32[0]) * (float)(0.0 - v15);
  if ( result < 0.0 )
    result = FLOAT_3_40282e38;
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
  return (float)(COERCE_FLOAT(_mm_shuffle_ps(v4, v4, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v4, v4, 0)))
       + COERCE_FLOAT(_mm_shuffle_ps(v4, v4, 170));
}

// File Line: 872
// RVA: 0xBE0DF0
bool __fastcall hkaiAvoidanceSolverUtils::clipSegmentInsideAabb(hkAabb *aabb, hkVector4f *startInOut, hkVector4f *endInOut)
{
  hkVector4f v3; // xmm8
  hkVector4f v4; // xmm9
  BOOL v5; // er9
  BOOL v6; // ecx
  bool result; // al
  __m128 v8; // xmm10
  __m128 v9; // xmm11
  __m128 v10; // xmm7
  __m128 v11; // xmm6
  __m128i v12; // xmm7
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // ST20_16
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm3
  __m128 v20; // xmm4
  __m128 v21; // xmm4
  __m128i v22; // xmm6
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // ST20_16
  __m128 v26; // xmm0
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __m128 v30; // xmm3
  __m128 v31; // xmm3

  v3.m_quad = (__m128)aabb->m_min;
  v4.m_quad = (__m128)aabb->m_max;
  v5 = (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(aabb->m_min.m_quad, startInOut->m_quad), _mm_cmpleps(startInOut->m_quad, v4.m_quad))) & 7) == 7;
  v6 = (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(aabb->m_min.m_quad, endInOut->m_quad), _mm_cmpleps(endInOut->m_quad, v4.m_quad))) & 7) == 7;
  if ( v5 && v6 )
    return 1;
  v8 = endInOut->m_quad;
  v9 = startInOut->m_quad;
  v10 = startInOut->m_quad;
  v11 = endInOut->m_quad;
  if ( !v5 )
  {
    v12 = (__m128i)_mm_sub_ps(v8, v9);
    v13 = _mm_rcp_ps((__m128)v12);
    v14 = _mm_cmpeqps((__m128)0i64, (__m128)v12);
    v15 = _mm_or_ps(
            _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v12, 0x1Fu), 0x1Fu), (__m128)_xmm), v14),
            _mm_andnot_ps(v14, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v12, v13)), v13)));
    v15.m128_i32[3] = _mm_movemask_ps(
                        _mm_cmpleps(
                          (__m128)0i64,
                          _mm_shuffle_ps((__m128)v12, _mm_unpackhi_ps((__m128)v12, query.m_quad), 196))) & 7 | 0x3F000000;
    v16 = _mm_mul_ps(v15, _mm_sub_ps(v4.m_quad, v9));
    v17 = _mm_mul_ps(v15, _mm_sub_ps(v3.m_quad, v9));
    v18 = v17;
    v19 = _mm_max_ps(v17, v16);
    v20 = _mm_min_ps(v18, v16);
    v21 = _mm_max_ps(
            _mm_max_ps(
              _mm_shuffle_ps(v20, v20, 170),
              _mm_max_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0))),
            aabbOut.m_quad);
    if ( v21.m128_f32[0] > fmin(
                             fmin(
                               COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 170)),
                               fmin(
                                 COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 85)),
                                 COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 0)))),
                             1.0) )
      return 0;
    v10 = _mm_add_ps(_mm_mul_ps((__m128)v12, v21), v9);
  }
  if ( !v6 )
  {
    v22 = (__m128i)_mm_sub_ps(v9, v8);
    v23 = _mm_cmpeqps((__m128)0i64, (__m128)v22);
    v24 = _mm_rcp_ps((__m128)v22);
    v25 = _mm_or_ps(
            _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v22, 0x1Fu), 0x1Fu), (__m128)_xmm), v23),
            _mm_andnot_ps(v23, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v22, v24)), v24)));
    v25.m128_i32[3] = _mm_movemask_ps(
                        _mm_cmpleps(
                          (__m128)0i64,
                          _mm_shuffle_ps((__m128)v22, _mm_unpackhi_ps((__m128)v22, query.m_quad), 196))) & 7 | 0x3F000000;
    v26 = _mm_mul_ps(v25, _mm_sub_ps(v4.m_quad, v8));
    v27 = _mm_mul_ps(v25, _mm_sub_ps(v3.m_quad, v8));
    v28 = v27;
    v29 = _mm_max_ps(v27, v26);
    v30 = _mm_min_ps(v28, v26);
    v31 = _mm_max_ps(
            _mm_max_ps(
              _mm_shuffle_ps(v30, v30, 170),
              _mm_max_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0))),
            aabbOut.m_quad);
    if ( v31.m128_f32[0] > fmin(
                             fmin(
                               COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 170)),
                               fmin(
                                 COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 85)),
                                 COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 0)))),
                             1.0) )
      return 0;
    v11 = _mm_add_ps(_mm_mul_ps((__m128)v22, v31), v8);
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
  LODWORD(result) = (unsigned __int128)_mm_andnot_ps(
                                         _mm_cmpleps(v12, (__m128)0i64),
                                         _mm_mul_ps(
                                           _mm_mul_ps(
                                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v12), v16)),
                                             _mm_mul_ps(*(__m128 *)_xmm, v16)),
                                           v12));
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
  __m128 v9; // xmm6
  __m128 v10; // xmm2
  __m128 v11; // xmm5
  __m128 v12; // xmm4
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  float v15; // xmm3_4

  v3 = _mm_mul_ps(vb->m_quad, vap->m_quad);
  v4 = _mm_mul_ps(vb->m_quad, va->m_quad);
  v5 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)), _mm_shuffle_ps(v4, v4, 170));
  v6 = _mm_cmpltps(v5, query.m_quad);
  v7 = _mm_min_ps(
         _mm_max_ps(
           (__m128)COERCE_UNSIGNED_INT(
                     fmax(
                       -1.0,
                       COERCE_FLOAT(v5.m128_i32[0] & v6.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                                               v6,
                                                                                               query.m_quad)))),
           *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
         *(__m128 *)_xmm);
  v8 = _mm_andnot_ps(*(__m128 *)_xmm, v7);
  v9 = _mm_cmpltps(v8, *(__m128 *)_xmm);
  v10 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v8), *(__m128 *)_xmm);
  v11 = _mm_cmpltps(*(__m128 *)_xmm, v8);
  v12 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v10), v11), _mm_andnot_ps(v11, v8));
  v13 = _mm_or_ps(_mm_andnot_ps(v11, _mm_mul_ps(v8, v8)), _mm_and_ps(v11, v10));
  v14 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v13, *(__m128 *)coeff4), *(__m128 *)coeff3), v13),
                        *(__m128 *)coeff2),
                      v13),
                    *(__m128 *)coeff1),
                  v13),
                *(__m128 *)coeff0),
              v13),
            v12),
          v12);
  v15 = 1.5707964
      - COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                               v9,
                                               _mm_or_ps(
                                                 _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v14, v14)), v11),
                                                 _mm_andnot_ps(v11, v14))) | v9.m128_i32[0] & v8.m128_i32[0]) ^ _xmm[0] & v7.m128_i32[0]);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v3, v3, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v3, v3, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v3, v3, 170))) < 0.0 )
    LODWORD(v15) ^= _xmm[0];
  return v15;
}

// File Line: 1103
// RVA: 0xBDF150
hkResult *__usercall hkaiAvoidanceSolverUtils::calcSteeringVelocity@<rax>(hkResult *result@<rcx>, float timestep@<xmm1>, hkVector4f *up@<r8>, hkaiAvoidanceSolver::SteeringAgent *agentIn@<r9>, __m128 *a5@<xmm14>, hkVector4f *steerVelocityOut, hkVector4f *steerForwardOut)
{
  hkResult *v7; // rsi
  hkaiAvoidanceSolver::SteeringAgent *v8; // rdi
  hkVector4f *v9; // rbp
  float v10; // xmm7_4
  _QWORD *v11; // rcx
  unsigned __int64 v12; // r9
  unsigned __int64 v13; // rax
  __m128 v14; // xmm8
  __m128i v15; // xmm0
  unsigned int v16; // ecx
  _QWORD *v17; // r8
  _QWORD *v18; // rcx
  unsigned __int64 v19; // rax
  signed __int64 v20; // rcx
  hkaiAvoidanceProperties *v21; // rdx
  __m128 v22; // xmm6
  bool v23; // zf
  __m128 v24; // xmm3
  __m128 v25; // xmm6
  __m128 v26; // xmm1
  __m128 v27; // xmm1
  __m128 v28; // xmm0
  __m128 v29; // xmm6
  _QWORD *v30; // r8
  _QWORD *v31; // rcx
  unsigned __int64 v32; // rax
  signed __int64 v33; // rcx
  hkResult *v34; // rax
  __m128 v35; // xmm6
  _QWORD *v36; // r8
  _QWORD *v37; // rcx
  unsigned __int64 v38; // rax
  signed __int64 v39; // rcx
  hkaiAvoidanceProperties *v40; // rdx
  char v41; // cl
  bool v42; // al
  _QWORD *v43; // r8
  unsigned __int64 v44; // rcx
  unsigned __int64 v45; // rax
  _QWORD *v46; // r8
  _QWORD *v47; // rcx
  unsigned __int64 v48; // rax
  signed __int64 v49; // rcx
  hkVector4f newVelocity; // [rsp+40h] [rbp-98h]
  hkVector4f deltaVelocity; // [rsp+50h] [rbp-88h]
  hkVector4f oldForward; // [rsp+60h] [rbp-78h]
  hkVector4f oldVelocity; // [rsp+70h] [rbp-68h]
  hkaiAvoidanceSolver::WorldInfo worldInfo; // [rsp+80h] [rbp-58h]
  hkResult resulta; // [rsp+E0h] [rbp+8h]

  v7 = result;
  v8 = agentIn;
  v9 = up;
  v10 = timestep;
  v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = v11[1];
  if ( v12 < v11[3] )
  {
    *(_QWORD *)v12 = "LtcalcSteerVel";
    *(_QWORD *)(v12 + 16) = "Stinit";
    v13 = __rdtsc();
    *(_DWORD *)(v12 + 8) = v13;
    v11[1] = v12 + 24;
  }
  v14 = v8->m_velocity.m_quad;
  v15 = (__m128i)v8->m_forward;
  v16 = hkMonitorStream__m_instance.m_slotID;
  oldVelocity.m_quad = (__m128)v8->m_velocity;
  _mm_store_si128((__m128i *)&oldForward, v15);
  v17 = TlsGetValue(v16);
  v18 = (_QWORD *)v17[1];
  if ( (unsigned __int64)v18 < v17[3] )
  {
    *v18 = "StapplyKineConst1";
    v19 = __rdtsc();
    v20 = (signed __int64)(v18 + 2);
    *(_DWORD *)(v20 - 8) = v19;
    v17[1] = v20;
  }
  if ( v8->m_localSteeringInput.m_applyKinematicConstraints.m_bool
    && (v21 = v8->m_avoidanceProperties, v21->m_avoidanceSolverType.m_storage == 1) )
  {
    hkaiAvoidanceSolverUtils::applyKinematicConstraints(
      timestep,
      &v21->m_movementProperties,
      v9,
      &oldVelocity,
      a5,
      &oldForward,
      &v8->m_localSteeringInput.m_desiredVelocity,
      &newVelocity,
      1);
    v22 = newVelocity.m_quad;
    v8->m_localSteeringInput.m_desiredVelocity = (hkVector4f)newVelocity.m_quad;
  }
  else
  {
    v22 = v8->m_localSteeringInput.m_desiredVelocity.m_quad;
  }
  v23 = v8->m_numNearbyAgents == 0;
  v24 = v9->m_quad;
  v25 = _mm_sub_ps(v22, v14);
  v26 = v9->m_quad;
  v7->m_enum = 0;
  v27 = _mm_mul_ps(v26, v25);
  v28 = _mm_shuffle_ps(v27, v27, 0);
  v29 = _mm_sub_ps(
          v25,
          _mm_mul_ps(_mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 85), v28), _mm_shuffle_ps(v27, v27, 170)), v24));
  deltaVelocity.m_quad = v29;
  if ( !v23 || v8->m_numSphereObstacles || v8->m_numBoundaryObstacles )
  {
    v28.m128_f32[0] = v10;
    worldInfo.m_up.m_quad = v24;
    worldInfo.m_timeStep.m_real = _mm_shuffle_ps(v28, v28, 0);
    v30 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v31 = (_QWORD *)v30[1];
    if ( (unsigned __int64)v31 < v30[3] )
    {
      *v31 = "StsolveSingleAgent";
      v32 = __rdtsc();
      v33 = (signed __int64)(v31 + 2);
      *(_DWORD *)(v33 - 8) = v32;
      v30[1] = v33;
    }
    v34 = hkaiAvoidanceSolver::solveSingleAgent(&resulta, &worldInfo, v8, &deltaVelocity);
    v29 = deltaVelocity.m_quad;
    v7->m_enum = v34->m_enum;
  }
  v35 = _mm_add_ps(v29, v8->m_localSteeringInput.m_currentVelocity.m_quad);
  newVelocity.m_quad = v35;
  v36 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v37 = (_QWORD *)v36[1];
  if ( (unsigned __int64)v37 < v36[3] )
  {
    *v37 = "StapplyKineConst2";
    v38 = __rdtsc();
    v39 = (signed __int64)(v37 + 2);
    *(_DWORD *)(v39 - 8) = v38;
    v36[1] = v39;
  }
  v40 = v8->m_avoidanceProperties;
  v41 = v40->m_avoidanceSolverType.m_storage;
  v42 = !v41 && v40->m_movementProperties.m_kinematicConstraintType.m_storage == 1 && v7->m_enum == 1;
  if ( v8->m_localSteeringInput.m_applyKinematicConstraints.m_bool && !v41 && !v42 )
  {
    hkaiAvoidanceSolverUtils::applyKinematicConstraints(
      v10,
      &v40->m_movementProperties,
      v9,
      &oldVelocity,
      a5,
      &oldForward,
      &newVelocity,
      &worldInfo.m_up,
      1);
    v35 = worldInfo.m_up.m_quad;
    newVelocity.m_quad = (__m128)worldInfo.m_up;
  }
  v43 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v44 = v43[1];
  if ( v44 < v43[3] )
  {
    *(_QWORD *)v44 = "StcalcAngVel";
    v45 = __rdtsc();
    *(_DWORD *)(v44 + 8) = v45;
    v43[1] = v44 + 16;
  }
  hkaiAvoidanceSolverUtils::calcAngularVelocityAndForward(
    &v8->m_localSteeringInput.m_currentVelocity,
    &newVelocity,
    &v8->m_localSteeringInput.m_currentForward,
    &v8->m_localSteeringInput.m_currentUp,
    &v8->m_avoidanceProperties->m_movementProperties,
    v10,
    (hkSimdFloat32 *)&worldInfo,
    steerForwardOut);
  steerVelocityOut->m_quad = _mm_shuffle_ps(v35, _mm_unpackhi_ps(v35, worldInfo.m_up.m_quad), 196);
  v46 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v47 = (_QWORD *)v46[1];
  if ( (unsigned __int64)v47 < v46[3] )
  {
    *v47 = "lt";
    v48 = __rdtsc();
    v49 = (signed __int64)(v47 + 2);
    *(_DWORD *)(v49 - 8) = v48;
    v46[1] = v49;
  }
  return v7;
}

// File Line: 1193
// RVA: 0xBDF4F0
void __usercall hkaiAvoidanceSolverUtils::calcUnsteeredVelocity(float timestep@<xmm0>, hkVector4f *up@<rdx>, hkaiMovementProperties *movementProperties@<r8>, hkaiLocalSteeringInput *steeringInput@<r9>, __m128 *a5@<xmm14>, hkVector4f *steerVelocityOut, hkVector4f *steerForwardOut)
{
  hkaiLocalSteeringInput *v7; // rbx
  hkaiMovementProperties *v8; // rdi
  hkVector4f *v9; // rsi
  float v10; // xmm7_4
  _QWORD *v11; // r9
  unsigned __int64 v12; // rcx
  unsigned __int64 v13; // rax
  __m128 v14; // xmm4
  __m128 v15; // xmm2
  __m128 v16; // xmm0
  __m128 v17; // xmm2
  __m128 v18; // xmm5
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  _QWORD *v22; // r8
  _QWORD *v23; // rcx
  unsigned __int64 v24; // rax
  signed __int64 v25; // rcx
  __m128 v26; // xmm6
  _QWORD *v27; // r10
  unsigned __int64 v28; // r9
  unsigned __int64 v29; // rax
  _QWORD *v30; // r8
  _QWORD *v31; // rcx
  unsigned __int64 v32; // rax
  signed __int64 v33; // rcx
  hkVector4f oldVelocity; // [rsp+40h] [rbp-58h]
  hkVector4f oldForward; // [rsp+50h] [rbp-48h]
  hkVector4f constrainedVelocity; // [rsp+60h] [rbp-38h]

  v7 = steeringInput;
  v8 = movementProperties;
  v9 = up;
  v10 = timestep;
  v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = v11[1];
  if ( v12 < v11[3] )
  {
    *(_QWORD *)v12 = "LtcalcUnsteeredVelocity";
    *(_QWORD *)(v12 + 16) = "Stinit";
    v13 = __rdtsc();
    *(_DWORD *)(v12 + 8) = v13;
    v11[1] = v12 + 24;
  }
  v14 = v9->m_quad;
  v15 = _mm_mul_ps(v9->m_quad, v7->m_currentVelocity.m_quad);
  v16 = _mm_sub_ps(
          (__m128)0i64,
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
            _mm_shuffle_ps(v15, v15, 170)));
  v17 = _mm_mul_ps(v7->m_currentForward.m_quad, v9->m_quad);
  oldVelocity.m_quad = _mm_add_ps(_mm_mul_ps(v16, v9->m_quad), v7->m_currentVelocity.m_quad);
  v18 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                _mm_shuffle_ps(v17, v17, 170))),
            v14),
          v7->m_currentForward.m_quad);
  v19 = _mm_mul_ps(v18, v18);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_rsqrt_ps(v20);
  oldForward.m_quad = _mm_mul_ps(
                        v18,
                        _mm_andnot_ps(
                          _mm_cmpleps(v20, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                            _mm_mul_ps(*(__m128 *)_xmm, v21))));
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "StapplyKineConst";
    v24 = __rdtsc();
    v25 = (signed __int64)(v23 + 2);
    *(_DWORD *)(v25 - 8) = v24;
    v22[1] = v25;
  }
  if ( v7->m_applyKinematicConstraints.m_bool )
  {
    hkaiAvoidanceSolverUtils::applyKinematicConstraints(
      v10,
      v8,
      v9,
      &oldVelocity,
      a5,
      &oldForward,
      &v7->m_desiredVelocity,
      &constrainedVelocity,
      1);
    v26 = constrainedVelocity.m_quad;
  }
  else
  {
    v26 = v7->m_desiredVelocity.m_quad;
  }
  oldVelocity.m_quad = v26;
  v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v28 = v27[1];
  if ( v28 < v27[3] )
  {
    *(_QWORD *)v28 = "StcalcAngVel";
    v29 = __rdtsc();
    *(_DWORD *)(v28 + 8) = v29;
    v27[1] = v28 + 16;
  }
  hkaiAvoidanceSolverUtils::calcAngularVelocityAndForward(
    &v7->m_currentVelocity,
    &oldVelocity,
    &v7->m_currentForward,
    &v7->m_currentUp,
    v8,
    v10,
    (hkSimdFloat32 *)&constrainedVelocity,
    steerForwardOut);
  steerVelocityOut->m_quad = _mm_shuffle_ps(v26, _mm_unpackhi_ps(v26, constrainedVelocity.m_quad), 196);
  v30 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v31 = (_QWORD *)v30[1];
  if ( (unsigned __int64)v31 < v30[3] )
  {
    *v31 = "lt";
    v32 = __rdtsc();
    v33 = (signed __int64)(v31 + 2);
    *(_DWORD *)(v33 - 8) = v32;
    v30[1] = v33;
  }
}

// File Line: 1246
// RVA: 0xBDF790
void __fastcall hkaiAvoidanceSolverUtils::calcAngularVelocityAndForward(hkVector4f *currentVelocity, hkVector4f *newVelocity, hkVector4f *forward, hkVector4f *up, hkaiMovementProperties *movementProperties, float timestep, hkSimdFloat32 *angularVelocityOut, hkVector4f *steerForwardOut)
{
  __m128 v8; // xmm7
  hkVector4f *v9; // rbx
  __m128 v10; // xmm1
  __m128i v11; // xmm8
  hkaiMovementProperties *v12; // rax
  __m128 v13; // xmm1
  __m128 v14; // xmm10
  __m128 v15; // xmm10
  __m128 v16; // xmm2
  float v17; // xmm0_4
  __m128 v18; // xmm2
  hkSimdFloat32 v19; // xmm2
  __m128i v20; // xmm6
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
  __m128 v37; // xmm9
  __m128 v38; // xmm14
  __m128 v39; // xmm14
  __m128 v40; // xmm1
  __m128 v41; // xmm8
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm1
  __m128i v45; // xmm11
  hkVector4f v46; // xmm8
  __m128 v47; // xmm1
  __m128i v48; // xmm9
  float v49; // xmm13_4
  __m128 v50; // xmm1
  __m128i v51; // xmm10
  __m128 v52; // xmm7
  __m128 v53; // xmm2
  __m128i v54; // xmm6
  __m128 v55; // xmm5
  __m128 v56; // xmm0
  __m128 v57; // xmm4
  __m128 v58; // xmm3
  float v59; // xmm0_4
  __m128 v60; // xmm7
  __m128 v61; // xmm7
  __m128 v62; // xmm2
  __m128i v63; // xmm11
  __m128 v64; // xmm1
  __m128 v65; // xmm5
  __m128 v66; // xmm4
  __m128 v67; // xmm2
  __m128 v68; // xmm0
  __m128 v69; // xmm1
  __m128 v70; // xmm2
  __m128 v71; // xmm4
  __m128 v72; // xmm6
  __m128 v73; // xmm3
  __m128 v74; // xmm2
  __m128 v75; // xmm0
  __m128 v76; // xmm6
  __m128 v77; // xmm0
  __m128 v78; // [rsp+20h] [rbp-B8h]
  unsigned int movementPropertiesa; // [rsp+100h] [rbp+28h]

  v8 = up->m_quad;
  v9 = forward;
  v10 = _mm_mul_ps(up->m_quad, newVelocity->m_quad);
  v11 = (__m128i)_mm_sub_ps(
                   newVelocity->m_quad,
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                       _mm_shuffle_ps(v10, v10, 170)),
                     up->m_quad));
  if ( (_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(_mm_slli_epi32(v11, 1u), 1u), *(__m128 *)&epsilon)) & 7) == 7 )
  {
    *angularVelocityOut = 0i64;
    *steerForwardOut = (hkVector4f)forward->m_quad;
  }
  else
  {
    v12 = movementProperties;
    if ( movementProperties->m_kinematicConstraintType.m_storage == 1 )
    {
      v13 = _mm_mul_ps(forward->m_quad, (__m128)v11);
      v14 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(forward->m_quad, forward->m_quad, 201), v8),
              _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), forward->m_quad));
      v15 = _mm_shuffle_ps(v14, v14, 201);
      v16 = _mm_mul_ps(v15, (__m128)v11);
      v17 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 0)) + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 85)))
          + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 170));
      v18 = _mm_xor_ps((__m128)LODWORD(movementProperties->m_maxAngularVelocity), *(__m128 *)_xmm);
      v18.m128_f32[0] = fminf(
                          fmaxf(
                            atan2f(
                              v17,
                              COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 170))
                            + (float)(COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 85))
                                    + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 0))))
                          * (float)(1.0 / timestep),
                            v18.m128_f32[0]),
                          v12->m_maxAngularVelocity);
      v19.m_real = _mm_shuffle_ps(v18, v18, 0);
      *angularVelocityOut = (hkSimdFloat32)v19.m_real;
      v20 = _mm_load_si128((const __m128i *)_xmm);
      v21 = _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(timestep), (__m128)LODWORD(timestep), 0), v19.m_real),
              *(__m128 *)offset_1);
      v22 = _mm_andnot_ps(*(__m128 *)_xmm, v21);
      v23 = _mm_add_epi32(v20, v20);
      v24 = _mm_andnot_si128(v20, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v22, *(__m128 *)_xmm)), v20));
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
                                  _mm_mul_ps(_mm_shuffle_ps(v29, v29, 85), v9->m_quad));
    }
    else
    {
      v30 = _mm_mul_ps(forward->m_quad, v8);
      v31 = _mm_sub_ps(
              forward->m_quad,
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                  _mm_shuffle_ps(v30, v30, 170)),
                v8));
      v32 = _mm_mul_ps(v31, v31);
      v33 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
              _mm_shuffle_ps(v32, v32, 170));
      v34 = _mm_rsqrt_ps(v33);
      v35 = _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
              _mm_mul_ps(*(__m128 *)_xmm, v34));
      v36 = _mm_mul_ps(v8, (__m128)v11);
      v37 = _mm_mul_ps(v31, _mm_andnot_ps(_mm_cmpleps(v33, (__m128)0i64), v35));
      v78 = v37;
      v38 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v37, v37, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v37));
      v39 = _mm_shuffle_ps(v38, v38, 201);
      v40 = (__m128)LODWORD(timestep);
      v40.m128_f32[0] = timestep * 2.0;
      v41 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  (__m128)v11,
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                      _mm_shuffle_ps(v36, v36, 170)),
                    v8)),
                _mm_shuffle_ps(v40, v40, 0)),
              v37);
      v42 = _mm_mul_ps(v41, v41);
      v43 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)),
              _mm_shuffle_ps(v42, v42, 170));
      v44 = _mm_rsqrt_ps(v43);
      v45 = _mm_load_si128((const __m128i *)_xmm);
      v46.m_quad = _mm_mul_ps(
                     v41,
                     _mm_andnot_ps(
                       _mm_cmpleps(v43, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v44, v43), v44)),
                         _mm_mul_ps(*(__m128 *)_xmm, v44))));
      v47 = _mm_mul_ps(v46.m_quad, v37);
      v48 = _mm_add_epi32(v45, v45);
      v49 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 170));
      v50 = _mm_mul_ps(v46.m_quad, v39);
      v51 = (__m128i)_mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
                       _mm_shuffle_ps(v50, v50, 170));
      *(float *)&movementPropertiesa = timestep * movementProperties->m_maxAngularVelocity;
      v52 = _mm_add_ps((__m128)movementPropertiesa, *(__m128 *)_xmm);
      v53 = _mm_andnot_ps(*(__m128 *)_xmm, v52);
      v54 = _mm_andnot_si128(v45, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v53, *(__m128 *)_xmm)), v45));
      v55 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v54, v48), (__m128i)0i64);
      v56 = _mm_cvtepi32_ps(v54);
      v57 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v56, *(__m128 *)DP1_0), v53), _mm_mul_ps(v56, *(__m128 *)DP2)),
              _mm_mul_ps(v56, *(__m128 *)DP3));
      v58 = _mm_mul_ps(v57, v57);
      v59 = timestep * v12->m_maxAngularVelocity;
      v60 = _mm_xor_ps(
              _mm_xor_ps(
                _mm_and_ps(v52, *(__m128 *)_xmm),
                (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v48, v48), v54), 0x1Du)),
              _mm_or_ps(
                _mm_andnot_ps(
                  v55,
                  _mm_add_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v58, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v58),
                            *(__m128 *)cosCoeff2_0),
                          v58),
                        v58),
                      _mm_mul_ps(v58, *(__m128 *)_xmm)),
                    *(__m128 *)_xmm)),
                _mm_and_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v58, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v58),
                          *(__m128 *)sinCoeff2_0),
                        v58),
                      v57),
                    v57),
                  v55)));
      v61 = _mm_shuffle_ps(v60, v60, 0);
      if ( *(float *)&movementPropertiesa < 3.1415927 && v49 < v61.m128_f32[0] )
      {
        v49 = v61.m128_f32[0];
        v62 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(v59));
        v63 = _mm_andnot_si128(v45, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v62, *(__m128 *)_xmm)), v45));
        v64 = _mm_cvtepi32_ps(v63);
        v65 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v63, v48), (__m128i)0i64);
        v66 = _mm_add_ps(
                _mm_add_ps(_mm_add_ps(_mm_mul_ps(v64, *(__m128 *)DP1_0), v62), _mm_mul_ps(v64, *(__m128 *)DP2)),
                _mm_mul_ps(v64, *(__m128 *)DP3));
        v67 = _mm_mul_ps(v66, v66);
        v68 = _mm_xor_ps(
                _mm_or_ps(
                  _mm_and_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v67, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v67),
                            *(__m128 *)sinCoeff2_0),
                          v67),
                        v66),
                      v66),
                    v65),
                  _mm_andnot_ps(
                    v65,
                    _mm_add_ps(
                      _mm_sub_ps(
                        _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v67, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v67),
                              *(__m128 *)cosCoeff2_0),
                            v67),
                          v67),
                        _mm_mul_ps(v67, *(__m128 *)_xmm)),
                      *(__m128 *)_xmm))),
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v48, v48), v63), 0x1Du),
                  _mm_and_ps((__m128)LODWORD(v59), *(__m128 *)_xmm)));
        v51 = (__m128i)_mm_xor_ps(
                         (__m128)_mm_slli_epi32(_mm_srli_epi32(v51, 0x1Fu), 0x1Fu),
                         _mm_shuffle_ps(v68, v68, 0));
        v46.m_quad = _mm_add_ps(_mm_mul_ps(v61, v78), _mm_mul_ps(v39, (__m128)v51));
      }
      v69 = _mm_rcp_ps((__m128)LODWORD(v49));
      v70 = _mm_mul_ps(v69, (__m128)v51.m128i_u32[0]);
      v71 = _mm_or_ps(_mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v70), _mm_cmpltps(*(__m128 *)_xmm, v70));
      v72 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v70), v71), _mm_andnot_ps(v71, v70));
      v73 = _mm_mul_ps(v72, v72);
      v74 = _mm_mul_ps(
              _mm_rcp_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_rcp_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_rcp_ps(
                            _mm_add_ps(
                              _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v73, *(__m128 *)s0)), *(__m128 *)t0),
                              _mm_add_ps(v73, *(__m128 *)s1))),
                          *(__m128 *)t1),
                        _mm_add_ps(v73, *(__m128 *)s2))),
                    *(__m128 *)t2),
                  _mm_add_ps(v73, *(__m128 *)s3))),
              _mm_mul_ps(v72, *(__m128 *)t3));
      v75 = _mm_cmpleps((__m128)0i64, v69);
      v76 = _mm_or_ps(
              _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v72, *(__m128 *)_xmm), *(__m128 *)_xmm), v74), v71),
              _mm_andnot_ps(v71, v74));
      v77 = _mm_or_ps(
              _mm_andnot_ps(
                v75,
                _mm_add_ps(_mm_or_ps(_mm_and_ps((__m128)v51.m128i_u32[0], *(__m128 *)_xmm), *(__m128 *)_xmm), v76)),
              _mm_and_ps(v76, v75));
      v77.m128_f32[0] = v77.m128_f32[0] / timestep;
      angularVelocityOut->m_real = _mm_shuffle_ps(v77, v77, 0);
      *steerForwardOut = (hkVector4f)v46.m_quad;
    }
  }
}

