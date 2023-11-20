// File Line: 52
// RVA: 0xC26DF0
void __fastcall hkaiStaticObstacleSystem::hkaiStaticObstacleSystem(hkaiStaticObstacleSystem *this, hkVector4f *velocity, hkVector4f *up)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm3
  __m128 v5; // xmm2
  hkVector4f v6; // xmm4
  __m128 v7; // xmm5
  __m128 v8; // xmm5
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm1

  this->m_closestEdgeIdx = -1;
  this->m_numCutVO = 0;
  this->m_narrowMult = -1.0;
  this->m_merged = 0;
  v3 = _mm_mul_ps(velocity->m_quad, velocity->m_quad);
  v4 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v3, v3, 85), _mm_shuffle_ps(v3, v3, 0)), _mm_shuffle_ps(v3, v3, 170));
  v5 = _mm_rsqrt_ps(v4);
  v6.m_quad = _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v4, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v5, v4), v5)),
                    _mm_mul_ps(*(__m128 *)_xmm, v5))),
                velocity->m_quad);
  this->m_forward = (hkVector4f)v6.m_quad;
  v7 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 201), up->m_quad),
         _mm_mul_ps(_mm_shuffle_ps(up->m_quad, up->m_quad, 201), v6.m_quad));
  v8 = _mm_shuffle_ps(v7, v7, 201);
  v9 = _mm_mul_ps(v8, v8);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_rsqrt_ps(v10);
  this->m_left.m_quad = _mm_mul_ps(
                          _mm_andnot_ps(
                            _mm_cmpleps(v10, (__m128)0i64),
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)),
                              _mm_mul_ps(*(__m128 *)_xmm, v11))),
                          v8);
}

// File Line: 63
// RVA: 0xC26F00
void __fastcall hkaiStaticObstacleSystem::merge(hkaiStaticObstacleSystem *this, hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *edges)
{
  int v2; // er8
  hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *v3; // rdi
  hkaiStaticObstacleSystem *v4; // r13
  int v5; // ebx
  int v6; // edx
  hkLifoAllocator *v7; // rax
  char *v8; // r8
  int v9; // edx
  char *v10; // rcx
  char *v11; // rax
  int v12; // er15
  int v13; // ebx
  __int64 v14; // r14
  hkaiStaticObstacleSystem::VelocityObstacleEdge *v15; // rsi
  char *v16; // r8
  char *v17; // r8
  _QWORD *v18; // r10
  __int64 v19; // r8
  BOOL v20; // ecx
  __int64 v21; // r9
  signed __int64 v22; // rcx
  __int64 v23; // rax
  int v24; // ebx
  int v25; // eax
  int v26; // eax
  char *v27; // rdi
  signed int v28; // ebx
  hkLifoAllocator *v29; // rax
  int v30; // er8
  char *array; // [rsp+30h] [rbp-40h]
  int v32; // [rsp+38h] [rbp-38h]
  int v33; // [rsp+3Ch] [rbp-34h]
  void *p; // [rsp+40h] [rbp-30h]
  int v35; // [rsp+48h] [rbp-28h]
  hkResult result; // [rsp+80h] [rbp+10h]

  v2 = edges->m_size;
  v3 = edges;
  v4 = this;
  if ( v2 > 1 )
    hkAlgorithm::quickSortRecursive<CleanEdgesOutput::CleanEdge,unsigned int (*)(CleanEdgesOutput::CleanEdge const &,CleanEdgesOutput::CleanEdge const &)>(
      edges->m_data,
      0,
      v2 - 1,
      hkaiStaticObstacleSystem::sideLessThan);
  v5 = v3->m_size;
  v33 = 2147483648;
  v6 = 0;
  array = 0i64;
  v35 = v5;
  v32 = 0;
  if ( v5 )
  {
    v7 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (char *)v7->m_cur;
    v9 = (8 * v5 + 127) & 0xFFFFFF80;
    v10 = &v8[v9];
    if ( v9 > v7->m_slabSize || v10 > v7->m_end )
    {
      v11 = (char *)hkLifoAllocator::allocateFromNewSlab(v7, v9);
      v6 = v32;
      array = v11;
    }
    else
    {
      v7->m_cur = v10;
      v6 = v32;
      array = v8;
    }
  }
  else
  {
    array = 0i64;
  }
  v12 = 0;
  v33 = v5 | 0x80000000;
  v13 = v4->m_numCutVO;
  p = array;
  if ( v3->m_size > 0 )
  {
    v14 = 0i64;
    do
    {
      v15 = v3->m_data;
      if ( v3->m_data[v14].m_type )
      {
        if ( !--v13 )
        {
          if ( v6 == (v33 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
            v6 = v32;
          }
          v17 = &array[8 * v6];
          if ( v17 )
          {
            *(hkaiStaticObstacleSystem::VelocityObstacleEdge *)v17 = v15[v14];
            v6 = v32;
          }
          v32 = ++v6;
        }
      }
      else
      {
        if ( !v13 )
        {
          if ( v6 == (v33 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
            v6 = v32;
          }
          v16 = &array[8 * v6];
          if ( v16 )
          {
            *(hkaiStaticObstacleSystem::VelocityObstacleEdge *)v16 = v15[v14];
            v6 = v32;
          }
          v32 = ++v6;
        }
        ++v13;
      }
      ++v12;
      ++v14;
    }
    while ( v12 < v3->m_size );
  }
  if ( v6 )
  {
    if ( v4->m_numCutVO )
    {
      *v3->m_data = *(hkaiStaticObstacleSystem::VelocityObstacleEdge *)&array[8 * v6 - 8];
      v6 = v32;
    }
    v18 = array;
    v19 = 0i64;
    v20 = v4->m_numCutVO != 0;
    v21 = v6 - v20;
    if ( v6 - v20 > 0 )
    {
      v22 = (signed __int64)&v3->m_data[v4->m_numCutVO != 0];
      do
      {
        v23 = v18[v19++];
        v22 += 8i64;
        *(_QWORD *)(v22 - 8) = v23;
      }
      while ( v19 < v21 );
      v6 = v32;
    }
    v24 = v6;
    v25 = v3->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v25 < v6 )
    {
      v26 = 2 * v25;
      if ( v6 < v26 )
        v6 = v26;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v6, 8);
      v6 = v32;
    }
    v3->m_size = v24;
    v4->m_merged = 1;
  }
  v27 = (char *)p;
  if ( p == array )
    v6 = 0;
  v28 = (8 * v35 + 127) & 0xFFFFFF80;
  v32 = v6;
  v29 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v30 = (v28 + 15) & 0xFFFFFFF0;
  if ( v28 > v29->m_slabSize || &v27[v30] != v29->m_cur || v29->m_firstNonLifoEnd == v27 )
    hkLifoAllocator::slowBlockFree(v29, v27, v30);
  else
    v29->m_cur = v27;
  v32 = 0;
  if ( v33 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v33);
}

// File Line: 102
// RVA: 0xC271F0
char __fastcall hkaiStaticObstacleSystem::findClosestEdge(hkaiStaticObstacleSystem *this, hkVector4f *desiredDir, hkVector4f *up, hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *edges)
{
  hkVector4f *v4; // rsi
  hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *v5; // rdi
  hkaiStaticObstacleSystem *v6; // rbx
  float v8; // xmm0_4
  float v9; // xmm1_4
  int v10; // edx
  hkaiStaticObstacleSystem::VelocityObstacleEdge *v11; // rcx
  CalculateEdgePenalty evalFunc; // [rsp+30h] [rbp+8h]

  v4 = desiredDir;
  v5 = edges;
  v6 = this;
  hkaiStaticObstacleSystem::merge(this, edges);
  if ( !v6->m_merged )
    return 0;
  v8 = hkaiAvoidanceSolverUtils::calcAngle(&v6->m_forward, &v6->m_left, v4);
  if ( v6->m_narrowMult < 0.0 )
    v9 = FLOAT_0_1;
  else
    v9 = FLOAT_0_60000002;
  v10 = v5->m_size;
  v11 = v5->m_data;
  evalFunc.m_angle = v8;
  evalFunc.m_weight = v9;
  v6->m_closestEdgeIdx = hkAlgorithm::findMinimumIndex<hkaiStaticObstacleSystem::VelocityObstacleEdge,`anonymous namespace'::CalculateEdgePenalty>(
                           v11,
                           v10,
                           &evalFunc);
  return 1;
}

// File Line: 119
// RVA: 0xC27290
signed __int64 __fastcall hkaiStaticObstacleSystem::isInsideAnyVO(hkVector4f *vel, hkaiStaticObstacleSystem *sos, hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *edges)
{
  hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *v3; // rsi
  __m128 v4; // xmm1
  __m128 v5; // xmm3
  __m128 v6; // xmm2
  __m128 v7; // xmm8
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  float v11; // xmm0_4
  int v12; // edi
  __int64 v13; // rbx
  hkVector4f vb; // [rsp+20h] [rbp-48h]

  v3 = edges;
  v4 = _mm_mul_ps(vel->m_quad, vel->m_quad);
  v5 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)), _mm_shuffle_ps(v4, v4, 170));
  v6 = _mm_rsqrt_ps(v5);
  v7 = _mm_mul_ps(
         vel->m_quad,
         _mm_andnot_ps(
           _mm_cmpleps(v5, (__m128)0i64),
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v6, v5), v6)), _mm_mul_ps(*(__m128 *)_xmm, v6))));
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  vb.m_quad = _mm_mul_ps(
                v7,
                _mm_andnot_ps(
                  _mm_cmpleps(v9, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                    _mm_mul_ps(*(__m128 *)_xmm, v10))));
  v11 = hkaiAvoidanceSolverUtils::calcAngle(&sos->m_forward, &sos->m_left, &vb);
  v12 = 0;
  if ( v3->m_size <= 0 )
    return 0xFFFFFFFFi64;
  v13 = 0i64;
  while ( !hkaiAvoidanceSolverUtils::isAngleInsideVO(v11, v3->m_data[v13].m_angle, v3->m_data[v13 + 1].m_angle) )
  {
    v12 += 2;
    v13 += 2i64;
    if ( v12 >= v3->m_size )
      return 0xFFFFFFFFi64;
  }
  return (unsigned int)v12;
}

// File Line: 144
// RVA: 0xC28E70
_BOOL8 __fastcall hkaiStaticObstacleSystem::sideLessThan(hkaiStaticObstacleSystem::VelocityObstacleEdge *voeA, hkaiStaticObstacleSystem::VelocityObstacleEdge *voeB)
{
  return voeA->m_angle < voeB->m_angle;
}

// File Line: 151
// RVA: 0xC273D0
void __fastcall hkaiStaticObstacleSolver::solve(hkaiAvoidanceSolver::WorldInfo *worldInfo, hkaiAvoidanceSolver::SteeringAgent *agent, hkaiAvoidanceSolver::ControlGradient *gradient)
{
  hkaiAvoidanceSolver::ControlGradient *v3; // r14
  hkaiAvoidanceSolver::WorldInfo *v4; // rsi
  hkaiAvoidanceSolver::SteeringAgent *v5; // rdi
  int v6; // ebx
  int v7; // ebx
  bool v8; // zf
  int v9; // ebx
  LPVOID v10; // rax
  hkLifoAllocator *v11; // rcx
  hkaiStaticObstacleSystem::VelocityObstacleEdge *v12; // rax
  int v13; // edx
  char *v14; // r8
  int v15; // eax
  char *v16; // rdi
  signed int v17; // ebx
  hkLifoAllocator *v18; // rax
  int v19; // er8
  hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> edges; // [rsp+30h] [rbp-50h]
  void *p; // [rsp+40h] [rbp-40h]
  int v22; // [rsp+48h] [rbp-38h]
  hkaiStaticObstacleSystem sos; // [rsp+50h] [rbp-30h]
  float minCollisionTime; // [rsp+A0h] [rbp+20h]

  v3 = gradient;
  v4 = worldInfo;
  v5 = agent;
  minCollisionTime = FLOAT_3_40282e38;
  hkaiStaticObstacleSystem::hkaiStaticObstacleSystem(&sos, &agent->m_velocity, &worldInfo->m_up);
  v6 = v5->m_numBoundaryObstacles + v5->m_numSphereObstacles;
  edges.m_data = 0i64;
  edges.m_size = 0;
  v7 = v5->m_numNearbyAgents + v6;
  edges.m_capacityAndFlags = 2147483648;
  v8 = 2 * v7 == 0;
  v9 = 2 * v7;
  v22 = v9;
  if ( v8 )
  {
    v12 = 0i64;
  }
  else
  {
    v10 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (hkLifoAllocator *)v10;
    v12 = (hkaiStaticObstacleSystem::VelocityObstacleEdge *)*((_QWORD *)v10 + 3);
    v13 = (8 * v9 + 127) & 0xFFFFFF80;
    v14 = (char *)v12 + v13;
    if ( v13 > v11->m_slabSize || v14 > v11->m_end )
      v12 = (hkaiStaticObstacleSystem::VelocityObstacleEdge *)hkLifoAllocator::allocateFromNewSlab(v11, v13);
    else
      v11->m_cur = v14;
  }
  edges.m_data = v12;
  p = v12;
  edges.m_capacityAndFlags = v9 | 0x80000000;
  sos.m_narrowMult = hkaiStaticObstacleSolver::detectNarrowCorridor(&v4->m_up, v5);
  hkaiStaticObstacleSolver::processNearbyAgents(v4, v5, &sos, &minCollisionTime, v3, &edges);
  hkaiStaticObstacleSolver::processNearbyObstacles(v4, v5, &sos, &minCollisionTime, v3, &edges);
  hkaiStaticObstacleSolver::processNearbyBoundaries(v4, v5, &sos, &minCollisionTime, v3, &edges);
  v15 = edges.m_size;
  if ( edges.m_size >= 2 )
  {
    hkaiStaticObstacleSystem::findClosestEdge(&sos, &v5->m_localSteeringInput.m_desiredFutureDir, &v4->m_up, &edges);
    hkaiStaticObstacleSolver::calcGradient(v5, &sos, &v4->m_up, minCollisionTime, v3, &edges);
    v15 = edges.m_size;
  }
  v16 = (char *)p;
  if ( p == edges.m_data )
    v15 = 0;
  edges.m_size = v15;
  v17 = (8 * v22 + 127) & 0xFFFFFF80;
  v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v19 = (v17 + 15) & 0xFFFFFFF0;
  if ( v17 > v18->m_slabSize || &v16[v19] != v18->m_cur || v18->m_firstNonLifoEnd == v16 )
    hkLifoAllocator::slowBlockFree(v18, v16, v19);
  else
    v18->m_cur = v16;
  edges.m_size = 0;
  if ( edges.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      edges.m_data,
      8 * edges.m_capacityAndFlags);
}

// File Line: 201
// RVA: 0xC275F0
void __fastcall hkaiStaticObstacleSolver::calcGradient(hkaiAvoidanceSolver::SteeringAgent *agent, hkaiStaticObstacleSystem *sos, hkVector4f *up, const float minCollisionTime, hkaiAvoidanceSolver::ControlGradient *gradient, hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *edges)
{
  hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *v6; // r14
  hkVector4f *v7; // r15
  hkaiAvoidanceSolver::SteeringAgent *v8; // rdi
  float v9; // xmm7_4
  hkaiStaticObstacleSystem *v10; // rsi
  hkVector4f *v11; // r12
  __int64 v12; // r13
  int v13; // ebx
  signed int v14; // eax
  __m128 *v15; // rbx
  float v16; // xmm6_4
  __m128 v17; // xmm1
  float v18; // xmm9_4
  __m128 v19; // xmm3
  __m128 v20; // xmm1
  float v21; // xmm8_4
  bool v22; // zf
  hkaiAvoidanceProperties *v23; // rax
  __m128 v24; // xmm2
  __m128 v25; // xmm2
  __m128 v26; // xmm4
  __m128 v27; // xmm2
  __m128 v28; // xmm0
  float v29; // xmm3_4
  float v30; // xmm8_4
  hkVector4f *v31; // rdi
  __m128 v32; // xmm2
  float v33; // xmm5_4
  __m128 v34; // xmm4
  __m128 v35; // xmm1
  __m128 v36; // xmm3
  __m128 v37; // xmm1
  __m128 v38; // xmm10
  __m128 v39; // xmm0
  __m128 v40; // xmm2
  __m128 v41; // xmm4
  __m128 v42; // xmm1
  float v43; // xmm0_4
  hkVector4f edge; // [rsp+0h] [rbp-79h]
  hkQuaternionf quat; // [rsp+10h] [rbp-69h]
  hkVector4f dvel; // [rsp+20h] [rbp-59h]
  float v47; // [rsp+30h] [rbp-49h]
  hkaiAvoidanceProperties *v48; // [rsp+D0h] [rbp+57h]
  hkVector4f *axis; // [rsp+E0h] [rbp+67h]
  __m128 *v50; // [rsp+F0h] [rbp+77h]
  hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *vars0; // [rsp+F8h] [rbp+7Fh]

  v6 = vars0;
  v7 = &agent->m_velocity;
  v8 = agent;
  v9 = minCollisionTime;
  v10 = sos;
  v48 = agent->m_avoidanceProperties;
  v11 = &agent->m_localSteeringInput.m_desiredVelocity;
  v12 = (signed int)hkaiStaticObstacleSystem::isInsideAnyVO(&agent->m_velocity, sos, vars0);
  v13 = hkaiStaticObstacleSystem::isInsideAnyVO(v11, v10, vars0);
  v14 = hkaiStaticObstacleSystem::isInsideAnyVO(&v8->m_localSteeringInput.m_desiredFutureDir, v10, vars0);
  if ( v13 != -1 )
  {
    v15 = v50;
    v16 = FLOAT_3_1415927;
    if ( v14 > -1 && (_DWORD)v12 == v14 )
    {
      v17 = _mm_mul_ps(v7->m_quad, v7->m_quad);
      v18 = v48->m_movementProperties.m_minVelocity + 0.2;
      v19 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170));
      v20 = _mm_rsqrt_ps(v19);
      LODWORD(v21) = (unsigned __int128)_mm_andnot_ps(
                                          _mm_cmpleps(v19, (__m128)0i64),
                                          _mm_mul_ps(
                                            _mm_mul_ps(
                                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                                              _mm_mul_ps(*(__m128 *)_xmm, v20)),
                                            v19));
      if ( hkaiAvoidanceSolverUtils::fabsAngle(vars0->m_data[v12].m_angle, vars0->m_data[(signed int)v12 + 1].m_angle) > 3.1415927
        && v21 < v18 )
      {
        v50[3].m128_i8[0] = 1;
      }
    }
    v22 = v10->m_merged == 0;
    v23 = v48;
    v24 = v11->m_quad;
    v47 = *(float *)&FLOAT_1_0;
    dvel.m_quad.m128_i32[2] = 1058642330;
    v25 = _mm_mul_ps(v24, v24);
    *(float *)&v48 = (float)((float)(v9 * 0.39999998) / v48->m_boundaryLimitTime) + 0.60000002;
    v26 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
            _mm_shuffle_ps(v25, v25, 170));
    v27 = _mm_rsqrt_ps(v26);
    dvel.m_quad.m128_i32[2] = LODWORD(v23->m_movementProperties.m_maxVelocity);
    v28 = (__m128)dvel.m_quad.m128_u32[2];
    v29 = COERCE_FLOAT(
            _mm_andnot_ps(
              _mm_cmpleps(v26, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                  _mm_mul_ps(*(__m128 *)_xmm, v27)),
                v26)))
        * fminf(fmaxf(*(float *)&v48, 0.60000002), 1.0);
    *(float *)&v48 = v23->m_movementProperties.m_minVelocity;
    v47 = v29;
    v30 = fminf(fmaxf(v29, *(float *)&v48), dvel.m_quad.m128_f32[2]);
    if ( !v22 )
      v16 = v6->m_data[v10->m_closestEdgeIdx].m_angle;
    v31 = axis;
    hkQuaternionf::setAxisAngle(&quat, axis, v16);
    hkVector4f::setRotatedDir(&edge, &quat, &v10->m_forward);
    v28.m128_f32[0] = v30;
    v32 = _mm_mul_ps(edge.m_quad, _mm_shuffle_ps(v28, v28, 0));
    edge.m_quad = v32;
    if ( (signed int)v12 <= -1 )
    {
      dvel.m_quad = _mm_sub_ps(v11->m_quad, v7->m_quad);
      v43 = hkaiAvoidanceSolverUtils::intersectVelDeltaVelVOEdge(v7, &dvel, v31, &edge);
      if ( v43 < *((float *)&v15->m128_u64[1] + 1) )
        *((float *)&v15->m128_u64[1] + 1) = v43;
    }
    else
    {
      if ( v9 == 0.0 )
      {
        v33 = FLOAT_100000_0;
      }
      else
      {
        v47 = 0.0;
        dvel.m_quad.m128_f32[2] = FLOAT_100000_0;
        *(float *)&v48 = 10.0 / v9;
        v33 = fminf(fmaxf(10.0 / v9, 0.0), 100000.0);
      }
      v34 = _mm_sub_ps(v7->m_quad, v32);
      v35 = _mm_mul_ps(v34, v34);
      v36 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
              _mm_shuffle_ps(v35, v35, 170));
      v37 = _mm_rsqrt_ps(v36);
      v38 = _mm_mul_ps(*(__m128 *)_xmm, v37);
      v39 = _mm_mul_ps(_mm_mul_ps(v37, v36), v37);
      v37.m128_f32[0] = v33;
      v40 = _mm_andnot_ps(_mm_cmpleps(v36, (__m128)0i64), _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v39), v38));
      v41 = _mm_mul_ps(v34, v40);
      v15[1] = v41;
      *v15 = _mm_shuffle_ps(v41, _mm_unpackhi_ps(v41, *v15), 196);
      v42 = _mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), v15[1]);
      v15[1] = _mm_shuffle_ps(v42, _mm_unpackhi_ps(v42, _mm_mul_ps(v40, v36)), 196);
    }
  }
}

// File Line: 284
// RVA: 0xC279C0
void __usercall hkaiStaticObstacleSolver::processNearbyAgents(hkaiAvoidanceSolver::WorldInfo *worldInfo@<rcx>, hkaiAvoidanceSolver::SteeringAgent *agent@<rdx>, hkaiStaticObstacleSystem *sos@<r8>, float *minCollisionTime@<r9>, __m128 a5@<xmm10>, hkaiAvoidanceSolver::ControlGradient *gradient, hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *edges)
{
  hkaiAvoidanceProperties *v7; // rsi
  hkaiAvoidanceSolver::ObstacleAgent *v8; // rbp
  int v9; // edi
  float *v10; // r15
  hkaiAvoidanceSolver::SteeringAgent *v11; // rbx
  hkaiAvoidanceSolver::WorldInfo *v12; // r14
  float v13; // xmm10_4
  hkaiAvoidanceSolver::ObstacleAgent *v14; // r12
  __m128 v15; // xmm2
  float v16; // xmm9_4
  __m128 v17; // xmm1
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  hkVector4f agentToObstacle; // [rsp+30h] [rbp-88h]
  hkaiStaticObstacleSystem *sosa; // [rsp+D0h] [rbp+18h]

  sosa = sos;
  v7 = agent->m_avoidanceProperties;
  v8 = agent->m_nearbyAgents;
  v9 = 0;
  v10 = minCollisionTime;
  v11 = agent;
  v12 = worldInfo;
  a5.m128_f32[0] = v7->m_limitObstacleVelocity * v7->m_limitObstacleVelocity;
  for ( LODWORD(v13) = (unsigned __int128)_mm_shuffle_ps(a5, a5, 0); v9 < v11->m_numNearbyAgents; ++v9 )
  {
    v14 = v8;
    ++v8;
    v15 = _mm_mul_ps(v14->m_velocity.m_quad, v14->m_velocity.m_quad);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 170))) < v13 )
    {
      hkaiAvoidanceSolverUtils::manageAgentPenetration(COERCE_FLOAT(*(_OWORD *)&v12->m_timeStep), v11, v14, gradient);
      v16 = v14->m_radius + v11->m_radius;
      v17 = _mm_sub_ps(v14->m_position.m_quad, v11->m_position.m_quad);
      agentToObstacle.m_quad = v17;
      v18 = _mm_mul_ps(v17, v17);
      v19 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
              _mm_shuffle_ps(v18, v18, 170));
      v20 = _mm_rsqrt_ps(v19);
      hkaiAvoidanceSolverUtils::calcSphereCollisionTime(v16, &agentToObstacle, &v11->m_velocity, &v12->m_up);
      if ( (float)(COERCE_FLOAT(
                     _mm_andnot_ps(
                       _mm_cmpleps(v19, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                           _mm_mul_ps(*(__m128 *)_xmm, v20)),
                         v19)))
                 - v16) < v7->m_limitObstacleDistance
        || v16 < v7->m_obstacleLimitTime
        || (hkaiAvoidanceSolverUtils::calcSphereCollisionTime(
              v16,
              &agentToObstacle,
              &v11->m_localSteeringInput.m_desiredVelocity,
              &v12->m_up),
            v16 < v7->m_obstacleLimitTime) )
      {
        v21 = _mm_mul_ps(v11->m_localSteeringInput.m_desiredFutureDir.m_quad, agentToObstacle.m_quad);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 170))) <= v11->m_localSteeringInput.m_distToLocalGoal
          || !v11->m_localSteeringInput.m_isLocalGoalLast.m_bool )
        {
          hkaiStaticObstacleSolver::addSphereVelocityObstacleEdges(v16, &agentToObstacle, &v12->m_up, sosa, edges);
          if ( v16 < *v10 )
            *v10 = v16;
        }
      }
    }
  }
}

// File Line: 344
// RVA: 0xC27C00
void __usercall hkaiStaticObstacleSolver::processNearbyObstacles(hkaiAvoidanceSolver::WorldInfo *worldInfo@<rcx>, hkaiAvoidanceSolver::SteeringAgent *agent@<rdx>, hkaiStaticObstacleSystem *sos@<r8>, float *minCollisionTime@<r9>, __m128 a5@<xmm10>, hkaiAvoidanceSolver::ControlGradient *gradient, hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *edges)
{
  hkaiAvoidanceProperties *v7; // rsi
  hkaiAvoidanceSolver::SphereObstacle *v8; // rbp
  int v9; // edi
  float *v10; // r12
  hkaiAvoidanceSolver::SteeringAgent *v11; // rbx
  hkaiAvoidanceSolver::WorldInfo *v12; // r15
  float v13; // xmm10_4
  __int64 v14; // r14
  __m128 *v15; // r13
  __m128 v16; // xmm2
  hkaiAvoidanceSolver::SphereObstacle *v17; // rax
  __m128 v18; // xmm1
  __m128 v19; // xmm1
  float v20; // xmm9_4
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  hkVector4f agentToObstacle; // [rsp+30h] [rbp-88h]
  hkaiStaticObstacleSystem *sosa; // [rsp+D0h] [rbp+18h]

  sosa = sos;
  v7 = agent->m_avoidanceProperties;
  v8 = agent->m_sphereObstacles;
  v9 = 0;
  v10 = minCollisionTime;
  v11 = agent;
  v12 = worldInfo;
  a5.m128_f32[0] = v7->m_limitObstacleVelocity * v7->m_limitObstacleVelocity;
  LODWORD(v13) = (unsigned __int128)_mm_shuffle_ps(a5, a5, 0);
  if ( agent->m_numSphereObstacles > 0 )
  {
    v14 = 0i64;
    do
    {
      v15 = &v8->m_sphere.m_pos.m_quad;
      ++v8;
      v16 = _mm_mul_ps(v15[1], v15[1]);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 170))) < v13 )
      {
        hkaiAvoidanceSolverUtils::manageObstaclePenetration(
          COERCE_FLOAT(*(_OWORD *)&v12->m_timeStep),
          v11,
          &v11->m_sphereObstacles[v9],
          gradient);
        v17 = v11->m_sphereObstacles;
        v18 = _mm_sub_ps(*v15, v11->m_position.m_quad);
        agentToObstacle.m_quad = v18;
        v19 = _mm_mul_ps(v18, v18);
        v20 = v17[v14].m_sphere.m_pos.m_quad.m128_f32[3] + v11->m_radius;
        v21 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                _mm_shuffle_ps(v19, v19, 170));
        v22 = _mm_rsqrt_ps(v21);
        hkaiAvoidanceSolverUtils::calcSphereCollisionTime(v20, &agentToObstacle, &v11->m_velocity, &v12->m_up);
        if ( (float)(COERCE_FLOAT(
                       _mm_andnot_ps(
                         _mm_cmpleps(v21, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                             _mm_mul_ps(*(__m128 *)_xmm, v22)),
                           v21)))
                   - v20) < v7->m_limitObstacleDistance
          || v20 < v7->m_obstacleLimitTime
          || (hkaiAvoidanceSolverUtils::calcSphereCollisionTime(
                v20,
                &agentToObstacle,
                &v11->m_localSteeringInput.m_desiredVelocity,
                &v12->m_up),
              v20 < v7->m_obstacleLimitTime) )
        {
          v23 = _mm_mul_ps(v11->m_localSteeringInput.m_desiredFutureDir.m_quad, agentToObstacle.m_quad);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 170))) <= v11->m_localSteeringInput.m_distToLocalGoal
            || !v11->m_localSteeringInput.m_isLocalGoalLast.m_bool )
          {
            hkaiStaticObstacleSolver::addSphereVelocityObstacleEdges(v20, &agentToObstacle, &v12->m_up, sosa, edges);
            if ( v20 < *v10 )
              *v10 = v20;
          }
        }
      }
      ++v9;
      ++v14;
    }
    while ( v9 < v11->m_numSphereObstacles );
  }
}

// File Line: 396
// RVA: 0xC27E50
void __fastcall hkaiStaticObstacleSolver::processNearbyBoundaries(hkaiAvoidanceSolver::WorldInfo *worldInfo, hkaiAvoidanceSolver::SteeringAgent *agent, hkaiStaticObstacleSystem *sos, float *minCollisionTime, hkaiAvoidanceSolver::ControlGradient *gradient, hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *edges)
{
  hkaiAvoidanceProperties *v6; // r15
  hkaiAvoidanceSolver::BoundaryObstacle *v7; // rax
  float *v8; // r12
  hkaiAvoidanceSolver::SteeringAgent *v9; // rdi
  float v10; // xmm8_4
  float v11; // xmm6_4
  int v12; // xmm11_4
  hkaiAvoidanceSolver::WorldInfo *up; // r13
  int v14; // esi
  hkaiAvoidanceSolver::BoundaryObstacle *v15; // r14
  __m128 v16; // xmm2
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 *v19; // xmm0_8
  float v20; // xmm7_4
  __m128 *v21; // xmm3_8
  float v22; // xmm0_4
  __m128 v23; // xmm2
  float v24; // xmm9_4
  float v25; // xmm10_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  char v29; // al
  float v30; // xmm1_4
  signed __int64 v31; // [rsp+40h] [rbp-F8h]
  hkVector4f boundaryPlane; // [rsp+50h] [rbp-E8h]
  hkVector4f agentToEnd; // [rsp+60h] [rbp-D8h]
  hkVector4f agentToStart; // [rsp+70h] [rbp-C8h]
  hkaiStaticObstacleSystem *sosa; // [rsp+150h] [rbp+18h]

  sosa = sos;
  v6 = agent->m_avoidanceProperties;
  v7 = agent->m_boundaryObstacles;
  v8 = minCollisionTime;
  v9 = agent;
  v10 = FLOAT_3_40282e38;
  v11 = v6->m_limitBoundaryDistance;
  v12 = gradient->m_direction.m_quad.m128_i32[3];
  up = worldInfo;
  if ( v11 < 0.0 )
    v11 = agent->m_radius * 3.0;
  v14 = 0;
  if ( agent->m_numBoundaryObstacles > 0 )
  {
    do
    {
      v15 = v7;
      v31 = (signed __int64)&v7[1];
      hkaiAvoidanceSolverUtils::calcBoundaryPlane(v7, &up->m_up, &boundaryPlane);
      v16 = _mm_mul_ps(v9->m_position.m_quad, boundaryPlane.m_quad);
      v17 = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, boundaryPlane.m_quad), 196);
      v18 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 78), v17);
      v19 = (__m128 *)*(_OWORD *)&_mm_add_ps(_mm_shuffle_ps(v18, v18, 177), v18);
      if ( *(float *)&v19 > 0.0 )
      {
        *(float *)&v19 = hkaiAvoidanceSolverUtils::closestDistToLineSegment(&v9->m_position, &v15->m_start, &v15->m_end);
        v20 = *(float *)&v19;
        v21 = v19;
        hkaiAvoidanceSolverUtils::manageBoundaryPenetration(
          COERCE_FLOAT(*(_OWORD *)&up->m_timeStep),
          v9,
          &boundaryPlane,
          *(const float *)&v19,
          gradient);
        v22 = v9->m_boundaryRadius;
        v23 = _mm_sub_ps(v15->m_end.m_quad, v9->m_position.m_quad);
        agentToStart.m_quad = _mm_sub_ps(v15->m_start.m_quad, v9->m_position.m_quad);
        agentToEnd.m_quad = v23;
        v24 = hkaiAvoidanceSolverUtils::calcBoundaryCollisionTime(
                v22,
                &agentToStart,
                &agentToEnd,
                &v9->m_velocity,
                v21,
                &boundaryPlane,
                &up->m_up);
        v25 = hkaiAvoidanceSolverUtils::calcBoundaryCollisionTime(
                v9->m_boundaryRadius,
                &agentToStart,
                &agentToEnd,
                &v9->m_localSteeringInput.m_desiredVelocity,
                v21,
                &boundaryPlane,
                &up->m_up);
        v26 = sosa->m_narrowMult;
        v27 = v26 < 0.0 ? v11 : v26 * v11;
        if ( v20 < v27 || (v28 = v6->m_boundaryLimitTime, v24 < v28) || v25 < v28 )
        {
          if ( (v11 <= v9->m_localSteeringInput.m_distToLocalGoal || !v9->m_localSteeringInput.m_isLocalGoalLast.m_bool)
            && (v6->m_boundaryLimitTime <= v9->m_localSteeringInput.m_timeToLocalGoal
             || !v9->m_localSteeringInput.m_isLocalGoalLast.m_bool) )
          {
            v29 = hkaiAvoidanceSolverUtils::detectFrontArea(v9->m_boundaryRadius, &v9->m_position, v15, &boundaryPlane);
            hkaiStaticObstacleSolver::addBoundaryVelocityObstacleEdges(
              v29,
              v9->m_boundaryRadius,
              &agentToStart,
              &agentToEnd,
              &up->m_up,
              sosa,
              edges);
            v30 = fminf(v24, v25);
            if ( v30 < *v8 )
              *v8 = v30;
            if ( v20 < v10 )
            {
              v10 = v20;
              gradient->m_direction.m_quad = _mm_mul_ps(
                                               *(__m128 *)_xmm_bf800000bf800000bf800000bf800000,
                                               boundaryPlane.m_quad);
            }
          }
        }
      }
      v7 = (hkaiAvoidanceSolver::BoundaryObstacle *)v31;
      ++v14;
    }
    while ( v14 < v9->m_numBoundaryObstacles );
  }
  gradient->m_direction.m_quad.m128_i32[3] = v12;
}

// File Line: 461
// RVA: 0xC28180
float __usercall hkaiStaticObstacleSolver::detectNarrowCorridor@<xmm0>(hkVector4f *up@<rcx>, hkaiAvoidanceSolver::SteeringAgent *agent@<rdx>, __m128 a3@<xmm9>)
{
  float v3; // xmm7_4
  float v4; // xmm8_4
  hkaiAvoidanceSolver::SteeringAgent *v5; // rdi
  float v6; // xmm6_4
  hkVector4f *v7; // r14
  hkVector4f v8; // xmm11
  __m128 v9; // xmm2
  float v10; // xmm0_4
  hkaiAvoidanceSolver::BoundaryObstacle *v11; // rbp
  int v12; // esi
  __m128 v13; // xmm9
  __m128 v14; // xmm2
  __m128 v15; // xmm9
  __m128 v16; // xmm11
  __m128 v17; // xmm11
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm11
  hkVector4f *v22; // rbx
  hkaiAvoidanceSolver::BoundaryObstacle *v23; // rcx
  __m128 v24; // xmm2
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  signed int v27; // ecx
  signed int v28; // eax
  __m128 v29; // xmm1
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  __m128 v34; // xmm1
  float v35; // xmm0_4
  bool v36; // cf
  bool v37; // zf
  float v38; // xmm0_4
  float v39; // xmm0_4
  __m128 v40; // xmm1
  float v41; // xmm2_4
  float v43; // xmm1_4
  hkVector4f boundaryPlane; // [rsp+20h] [rbp-B8h]

  v3 = agent->m_radius * 5.0;
  v4 = FLOAT_3_40282e38;
  v5 = agent;
  v6 = FLOAT_3_40282e38;
  v7 = up;
  v8.m_quad = (__m128)agent->m_localSteeringInput.m_desiredFutureDir;
  v9 = _mm_mul_ps(agent->m_forward.m_quad, v8.m_quad);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 170))) < 0.0 )
    v10 = FLOAT_N1_0;
  else
    v10 = *(float *)&FLOAT_1_0;
  v11 = agent->m_boundaryObstacles;
  a3.m128_f32[0] = v10;
  v12 = 0;
  v13 = _mm_mul_ps(_mm_shuffle_ps(a3, a3, 0), v8.m_quad);
  v14 = _mm_mul_ps(v13, agent->m_position.m_quad);
  v15 = _mm_shuffle_ps(
          v13,
          _mm_unpackhi_ps(
            v13,
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                _mm_shuffle_ps(v14, v14, 170)))),
          196);
  v16 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v8.m_quad, v8.m_quad, 201), up->m_quad),
          _mm_mul_ps(_mm_shuffle_ps(up->m_quad, up->m_quad, 201), v8.m_quad));
  v17 = _mm_shuffle_ps(v16, v16, 201);
  v18 = _mm_mul_ps(v17, v17);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v20 = _mm_rsqrt_ps(v19);
  v21 = _mm_mul_ps(
          v17,
          _mm_andnot_ps(
            _mm_cmpleps(v19, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
              _mm_mul_ps(*(__m128 *)_xmm, v20))));
  if ( agent->m_numBoundaryObstacles > 0 )
  {
    do
    {
      v22 = &v11->m_start;
      v23 = v11;
      ++v11;
      hkaiAvoidanceSolverUtils::calcBoundaryPlane(v23, v7, &boundaryPlane);
      v24 = _mm_mul_ps(boundaryPlane.m_quad, v5->m_position.m_quad);
      v25 = _mm_shuffle_ps(v24, _mm_unpackhi_ps(v24, boundaryPlane.m_quad), 196);
      v26 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 78), v25);
      if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 177)) + v26.m128_f32[0]) > 0.0 )
      {
        v27 = 0;
        v28 = 0;
        v29 = _mm_mul_ps(v15, v22->m_quad);
        v30 = _mm_mul_ps(v15, v22[1].m_quad);
        v31 = _mm_shuffle_ps(v29, _mm_unpackhi_ps(v29, v15), 196);
        v32 = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, v15), 196);
        v33 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 78), v31);
        v34 = _mm_add_ps(_mm_shuffle_ps(v32, v32, 78), v32);
        v35 = COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 177)) + v34.m128_f32[0];
        v36 = v35 < 0.0;
        v37 = v35 == 0.0;
        LODWORD(v38) = (unsigned __int128)_mm_shuffle_ps(v33, v33, 177);
        if ( !v36 && !v37 )
          v27 = 1;
        if ( (float)(v38 + v33.m128_f32[0]) > 0.0 )
          v28 = 1;
        if ( v28 | v27 )
        {
          v39 = hkaiAvoidanceSolverUtils::closestDistToLineSegment(&v5->m_position, v22, v22 + 1);
          if ( v39 < v3 )
          {
            v40 = _mm_mul_ps(boundaryPlane.m_quad, v21);
            v41 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 0)))
                + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 170));
            if ( v41 > 0.80000001 && v39 < v4 )
              v4 = v39;
            if ( v41 < -0.80000001 && v39 < v6 )
              v6 = v39;
          }
        }
      }
      ++v12;
    }
    while ( v12 < v5->m_numBoundaryObstacles );
  }
  if ( v4 >= v3 )
  {
    if ( v6 >= v3 )
      return FLOAT_N1_0;
    if ( v4 >= v3 )
      goto LABEL_29;
  }
  if ( v6 >= v3 )
LABEL_29:
    v43 = *(float *)&FLOAT_1_0;
  else
    v43 = fminf(fmaxf((float)(v6 + v4) / (float)(v3 * 1.2), 0.5), 1.0);
  return v43;
}

// File Line: 515
// RVA: 0xC28530
void __usercall hkaiStaticObstacleSolver::addSphereVelocityObstacleEdges(const float radius@<xmm0>, hkVector4f *agentToObstacle@<rdx>, hkVector4f *up@<r8>, hkaiStaticObstacleSystem *sos@<r9>, __int128 a5@<xmm8>, hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *edges)
{
  hkaiStaticObstacleSystem *v6; // rdi
  __m128 v7; // xmm2
  __m128 v8; // xmm5
  __m128 v9; // xmm3
  __m128 v10; // xmm4
  float v11; // xmm7_4
  float v12; // xmm0_4
  float v13; // xmm11_4
  float v14; // xmm0_4
  __m128 v15; // xmm9
  __m128 v16; // xmm7
  __m128 v17; // xmm6
  __m128 v18; // xmm2
  __m128 v19; // xmm5
  __m128 v20; // xmm4
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  float v23; // xmm10_4
  float v24; // xmm6_4
  float v25; // xmm0_4
  hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *v26; // rbx
  __int64 v27; // rsi
  int v28; // er9
  int v29; // eax
  int v30; // eax
  hkaiStaticObstacleSystem::VelocityObstacleEdge *v31; // rax
  signed __int64 v32; // rdx
  hkVector4f vb; // [rsp+30h] [rbp-88h]
  __int128 v34; // [rsp+70h] [rbp-48h]
  hkResult result; // [rsp+C0h] [rbp+8h]
  int v36; // [rsp+C8h] [rbp+10h]
  int v37; // [rsp+D8h] [rbp+20h]

  v6 = sos;
  v7 = _mm_mul_ps(agentToObstacle->m_quad, agentToObstacle->m_quad);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  v10 = _mm_andnot_ps(
          _mm_cmpleps(v8, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)), _mm_mul_ps(*(__m128 *)_xmm, v9)));
  vb.m_quad = _mm_mul_ps(agentToObstacle->m_quad, v10);
  v11 = radius / (float)(v10.m128_f32[0] * v8.m128_f32[0]);
  v12 = hkaiAvoidanceSolverUtils::calcAngle(&sos->m_forward, &sos->m_left, &vb);
  v37 = 1065353216;
  *(float *)&result.m_enum = v11;
  v36 = LODWORD(FLOAT_N1_0);
  v13 = v12;
  v14 = fminf(fmaxf(v11, -1.0), 1.0);
  if ( v11 >= 1.0 )
  {
    v36 = 1070141403;
    v37 = LODWORD(FLOAT_2_3561945);
    *(float *)&result.m_enum = (float)((float)(v11 - 1.0) * 0.78539813) + 1.5707964;
    v23 = fminf(fmaxf(*(float *)&result.m_enum, 1.5707964), 2.3561945);
  }
  else
  {
    *(float *)&result.m_enum = v14;
    v34 = a5;
    v15 = _mm_min_ps(
            _mm_max_ps((__m128)LODWORD(v14), *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
            *(__m128 *)_xmm);
    v16 = _mm_andnot_ps(*(__m128 *)_xmm, v15);
    v17 = _mm_cmpltps(v16, *(__m128 *)_xmm);
    v18 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v16), *(__m128 *)_xmm);
    v19 = _mm_cmpltps(*(__m128 *)_xmm, v16);
    v20 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v18), v19), _mm_andnot_ps(v19, v16));
    v21 = _mm_or_ps(_mm_andnot_ps(v19, _mm_mul_ps(v16, v16)), _mm_and_ps(v19, v18));
    v22 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v21, *(__m128 *)coeff4), *(__m128 *)coeff3), v21),
                          *(__m128 *)coeff2),
                        v21),
                      *(__m128 *)coeff1),
                    v21),
                  *(__m128 *)coeff0),
                v21),
              v20),
            v20);
    LODWORD(v23) = (*(unsigned __int128 *)&_mm_andnot_ps(
                                             v17,
                                             _mm_or_ps(
                                               _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v22, v22)), v19),
                                               _mm_andnot_ps(v19, v22))) | v17.m128_i32[0] & v16.m128_i32[0]) ^ v15.m128_i32[0] & _xmm[0];
  }
  v24 = hkaiAvoidanceSolverUtils::clampAngle(v13 - v23);
  v25 = hkaiAvoidanceSolverUtils::clampAngle(v23 + v13);
  v26 = edges;
  v27 = edges->m_size;
  v28 = v27 + 2;
  v29 = edges->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v29 < (signed int)v27 + 2 )
  {
    v30 = 2 * v29;
    if ( v28 < v30 )
      v28 = v30;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, edges, v28, 8);
  }
  v31 = v26->m_data;
  v26->m_size += 2;
  v32 = (signed __int64)&v31[v27];
  *(float *)v32 = v24;
  *(_DWORD *)(v32 + 4) = 0;
  *(float *)(v32 + 8) = v25;
  *(_DWORD *)(v32 + 12) = 1;
  if ( hkaiAvoidanceSolverUtils::isAngleInsideVO(3.1415927, v24, v25) )
    ++v6->m_numCutVO;
}

// File Line: 559
// RVA: 0xC28860
void __fastcall hkaiStaticObstacleSolver::addBoundaryVelocityObstacleEdges(bool insideFrontArea, const float radius, hkVector4f *agentToStart, hkVector4f *agentToEnd, hkVector4f *up, hkaiStaticObstacleSystem *sos, hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *edges)
{
  __m128 v7; // xmm5
  hkaiStaticObstacleSystem *v8; // rbp
  bool v9; // si
  hkVector4f *v10; // rbx
  float v11; // xmm6_4
  float v12; // xmm14_4
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  float v17; // xmm10_4
  float v18; // xmm0_4
  __m128 v19; // xmm5
  float v20; // xmm12_4
  __m128 v21; // xmm2
  __m128 v22; // xmm4
  __m128 v23; // xmm2
  float v24; // xmm11_4
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  float v28; // xmm0_4
  float v29; // xmm13_4
  __m128 v30; // xmm9
  __m128 v31; // xmm7
  __m128 v32; // xmm6
  __m128 v33; // xmm2
  __m128 v34; // xmm5
  __m128 v35; // xmm4
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  float v38; // xmm10_4
  __m128 v39; // xmm9
  __m128 v40; // xmm7
  __m128 v41; // xmm6
  __m128 v42; // xmm2
  __m128 v43; // xmm5
  __m128 v44; // xmm4
  __m128 v45; // xmm3
  __m128 v46; // xmm2
  float v47; // xmm0_4
  hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *v48; // rbx
  __int64 v49; // rdi
  int v50; // er9
  int v51; // eax
  int v52; // eax
  hkaiStaticObstacleSystem::VelocityObstacleEdge *v53; // rax
  signed __int64 v54; // rdx
  hkVector4f vb; // [rsp+30h] [rbp-C8h]
  hkVector4f v56; // [rsp+40h] [rbp-B8h]
  hkResult result; // [rsp+100h] [rbp+8h]
  float v58; // [rsp+108h] [rbp+10h]

  v7 = agentToStart->m_quad;
  v8 = sos;
  v9 = insideFrontArea;
  v10 = agentToEnd;
  v11 = fmaxf(0.00000011920929, radius * 1.01);
  *(float *)&result.m_enum = v11;
  v12 = radius;
  v13 = _mm_mul_ps(v7, v7);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_rsqrt_ps(v14);
  v16 = _mm_andnot_ps(
          _mm_cmpleps(v14, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)), _mm_mul_ps(*(__m128 *)_xmm, v15)));
  v58 = v16.m128_f32[0] * v14.m128_f32[0];
  vb.m_quad = _mm_mul_ps(v7, v16);
  v17 = fmaxf(v16.m128_f32[0] * v14.m128_f32[0], v11);
  v18 = hkaiAvoidanceSolverUtils::calcAngle(&sos->m_forward, &sos->m_left, &vb);
  v19 = v10->m_quad;
  v20 = v18;
  v21 = _mm_mul_ps(v19, v19);
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v23 = _mm_rsqrt_ps(v22);
  LODWORD(v58) = (unsigned __int128)_mm_andnot_ps(
                                      _mm_cmpleps(v22, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v23)),
                                        v22));
  *(float *)&result.m_enum = v11;
  v24 = fmaxf(v58, v11);
  v25 = _mm_mul_ps(v19, v19);
  v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)), _mm_shuffle_ps(v25, v25, 170));
  v27 = _mm_rsqrt_ps(v26);
  v56.m_quad = _mm_mul_ps(
                 v19,
                 _mm_andnot_ps(
                   _mm_cmpleps(v26, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                     _mm_mul_ps(*(__m128 *)_xmm, v27))));
  v28 = hkaiAvoidanceSolverUtils::calcAngle(&v8->m_forward, &v8->m_left, &v56);
  v29 = v28;
  if ( !v9 )
  {
    if ( v17 >= v24 )
    {
      v17 = v24;
      v20 = v28;
    }
    else
    {
      v24 = v17;
      v29 = v20;
    }
  }
  *(float *)&result.m_enum = v12 / v17;
  v30 = _mm_min_ps(
          _mm_max_ps((__m128)COERCE_UNSIGNED_INT(v12 / v17), *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
          *(__m128 *)_xmm);
  v31 = _mm_andnot_ps(*(__m128 *)_xmm, v30);
  v32 = _mm_cmpltps(v31, *(__m128 *)_xmm);
  v33 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v31), *(__m128 *)_xmm);
  v34 = _mm_cmpltps(*(__m128 *)_xmm, v31);
  v35 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v33), v34), _mm_andnot_ps(v34, v31));
  v36 = _mm_or_ps(_mm_andnot_ps(v34, _mm_mul_ps(v31, v31)), _mm_and_ps(v34, v33));
  v37 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v36, *(__m128 *)coeff4), *(__m128 *)coeff3), v36),
                        *(__m128 *)coeff2),
                      v36),
                    *(__m128 *)coeff1),
                  v36),
                *(__m128 *)coeff0),
              v36),
            v35),
          v35);
  v38 = hkaiAvoidanceSolverUtils::clampAngle(
          v20
        - COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                                 v32,
                                                 _mm_or_ps(
                                                   _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v37, v37)), v34),
                                                   _mm_andnot_ps(v34, v37))) | v32.m128_i32[0] & v31.m128_i32[0]) ^ v30.m128_i32[0] & _xmm[0]));
  *(float *)&result.m_enum = v12 / v24;
  v39 = _mm_min_ps(
          _mm_max_ps((__m128)COERCE_UNSIGNED_INT(v12 / v24), *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
          *(__m128 *)_xmm);
  v40 = _mm_andnot_ps(*(__m128 *)_xmm, v39);
  v41 = _mm_cmpltps(v40, *(__m128 *)_xmm);
  v42 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v40), *(__m128 *)_xmm);
  v43 = _mm_cmpltps(*(__m128 *)_xmm, v40);
  v44 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v42), v43), _mm_andnot_ps(v43, v40));
  v45 = _mm_or_ps(_mm_andnot_ps(v43, _mm_mul_ps(v40, v40)), _mm_and_ps(v43, v42));
  v46 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v45, *(__m128 *)coeff4), *(__m128 *)coeff3), v45),
                        *(__m128 *)coeff2),
                      v45),
                    *(__m128 *)coeff1),
                  v45),
                *(__m128 *)coeff0),
              v45),
            v44),
          v44);
  v47 = hkaiAvoidanceSolverUtils::clampAngle(
          COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                                 v41,
                                                 _mm_or_ps(
                                                   _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v46, v46)), v43),
                                                   _mm_andnot_ps(v43, v46))) | v41.m128_i32[0] & v40.m128_i32[0]) ^ v39.m128_i32[0] & _xmm[0])
        + v29);
  v48 = edges;
  v49 = edges->m_size;
  v50 = v49 + 2;
  v51 = edges->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v51 < (signed int)v49 + 2 )
  {
    v52 = 2 * v51;
    if ( v50 < v52 )
      v50 = v52;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, edges, v50, 8);
  }
  v53 = v48->m_data;
  v48->m_size += 2;
  v54 = (signed __int64)&v53[v49];
  *(float *)v54 = v38;
  *(_DWORD *)(v54 + 4) = 0;
  *(float *)(v54 + 8) = v47;
  *(_DWORD *)(v54 + 12) = 1;
  if ( hkaiAvoidanceSolverUtils::isAngleInsideVO(3.1415927, v38, v47) )
    ++v8->m_numCutVO;
}

