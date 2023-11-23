// File Line: 52
// RVA: 0xC26DF0
void __fastcall hkaiStaticObstacleSystem::hkaiStaticObstacleSystem(
        hkaiStaticObstacleSystem *this,
        hkVector4f *velocity,
        hkVector4f *up)
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
                  _mm_cmple_ps(v4, (__m128)0i64),
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
                            _mm_cmple_ps(v10, (__m128)0i64),
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)),
                              _mm_mul_ps(*(__m128 *)_xmm, v11))),
                          v8);
}

// File Line: 63
// RVA: 0xC26F00
void __fastcall hkaiStaticObstacleSystem::merge(
        hkaiStaticObstacleSystem *this,
        hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *edges)
{
  int m_size; // r8d
  int v5; // ebx
  int v6; // edx
  hkLifoAllocator *Value; // rax
  char *m_cur; // r8
  int v9; // edx
  char *v10; // rcx
  char *v11; // rax
  int v12; // r15d
  int m_numCutVO; // ebx
  __int64 v14; // r14
  hkaiStaticObstacleSystem::VelocityObstacleEdge *m_data; // rsi
  char *v16; // r8
  char *v17; // r8
  _QWORD *v18; // r10
  __int64 v19; // r8
  BOOL v20; // ecx
  __int64 v21; // r9
  hkaiStaticObstacleSystem::VelocityObstacleEdge *v22; // rcx
  hkaiStaticObstacleSystem::VelocityObstacleEdge v23; // rax
  int v24; // ebx
  int v25; // eax
  int v26; // eax
  char *v27; // rdi
  signed int v28; // ebx
  hkLifoAllocator *v29; // rax
  int v30; // r8d
  char *array; // [rsp+30h] [rbp-40h] BYREF
  int v32; // [rsp+38h] [rbp-38h]
  int v33; // [rsp+3Ch] [rbp-34h]
  void *p; // [rsp+40h] [rbp-30h]
  int v35; // [rsp+48h] [rbp-28h]
  hkResult result; // [rsp+80h] [rbp+10h] BYREF

  m_size = edges->m_size;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<CleanEdgesOutput::CleanEdge,unsigned int (*)(CleanEdgesOutput::CleanEdge const &,CleanEdgesOutput::CleanEdge const &)>(
      edges->m_data,
      0,
      m_size - 1,
      hkaiStaticObstacleSystem::sideLessThan);
  v5 = edges->m_size;
  v33 = 0x80000000;
  v6 = 0;
  array = 0i64;
  v35 = v5;
  v32 = 0;
  if ( v5 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)Value->m_cur;
    v9 = (8 * v5 + 127) & 0xFFFFFF80;
    v10 = &m_cur[v9];
    if ( v9 > Value->m_slabSize || v10 > Value->m_end )
    {
      v11 = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v9);
      v6 = v32;
      array = v11;
    }
    else
    {
      Value->m_cur = v10;
      v6 = v32;
      array = m_cur;
    }
  }
  else
  {
    array = 0i64;
  }
  v12 = 0;
  v33 = v5 | 0x80000000;
  m_numCutVO = this->m_numCutVO;
  p = array;
  if ( edges->m_size > 0 )
  {
    v14 = 0i64;
    do
    {
      m_data = edges->m_data;
      if ( edges->m_data[v14].m_type )
      {
        if ( !--m_numCutVO )
        {
          if ( v6 == (v33 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 8);
            v6 = v32;
          }
          v17 = &array[8 * v6];
          if ( v17 )
          {
            *(hkaiStaticObstacleSystem::VelocityObstacleEdge *)v17 = m_data[v14];
            v6 = v32;
          }
          v32 = ++v6;
        }
      }
      else
      {
        if ( !m_numCutVO )
        {
          if ( v6 == (v33 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 8);
            v6 = v32;
          }
          v16 = &array[8 * v6];
          if ( v16 )
          {
            *(hkaiStaticObstacleSystem::VelocityObstacleEdge *)v16 = m_data[v14];
            v6 = v32;
          }
          v32 = ++v6;
        }
        ++m_numCutVO;
      }
      ++v12;
      ++v14;
    }
    while ( v12 < edges->m_size );
  }
  if ( v6 )
  {
    if ( this->m_numCutVO )
    {
      *edges->m_data = *(hkaiStaticObstacleSystem::VelocityObstacleEdge *)&array[8 * v6 - 8];
      v6 = v32;
    }
    v18 = array;
    v19 = 0i64;
    v20 = this->m_numCutVO != 0;
    v21 = v6 - v20;
    if ( v6 - v20 > 0 )
    {
      v22 = &edges->m_data[this->m_numCutVO != 0];
      do
      {
        v23 = (hkaiStaticObstacleSystem::VelocityObstacleEdge)v18[v19++];
        ++v22;
        v22[-1] = v23;
      }
      while ( v19 < v21 );
      v6 = v32;
    }
    v24 = v6;
    v25 = edges->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v25 < v6 )
    {
      v26 = 2 * v25;
      if ( v6 < v26 )
        v6 = v26;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, edges, v6, 8);
      v6 = v32;
    }
    edges->m_size = v24;
    this->m_merged = 1;
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
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v33);
}

// File Line: 102
// RVA: 0xC271F0
char __fastcall hkaiStaticObstacleSystem::findClosestEdge(
        hkaiStaticObstacleSystem *this,
        hkVector4f *desiredDir,
        hkVector4f *up,
        hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *edges)
{
  float v8; // xmm0_4
  float v9; // xmm1_4
  int m_size; // edx
  hkaiStaticObstacleSystem::VelocityObstacleEdge *m_data; // rcx
  CalculateEdgePenalty evalFunc; // [rsp+30h] [rbp+8h] BYREF

  hkaiStaticObstacleSystem::merge(this, edges);
  if ( !this->m_merged )
    return 0;
  v8 = hkaiAvoidanceSolverUtils::calcAngle(&this->m_forward, &this->m_left, desiredDir);
  if ( this->m_narrowMult < 0.0 )
    v9 = FLOAT_0_1;
  else
    v9 = FLOAT_0_60000002;
  m_size = edges->m_size;
  m_data = edges->m_data;
  evalFunc.m_angle = v8;
  evalFunc.m_weight = v9;
  this->m_closestEdgeIdx = hkAlgorithm::findMinimumIndex<hkaiStaticObstacleSystem::VelocityObstacleEdge,`anonymous namespace::CalculateEdgePenalty>(
                             m_data,
                             m_size,
                             &evalFunc);
  return 1;
}

// File Line: 119
// RVA: 0xC27290
__int64 __fastcall hkaiStaticObstacleSystem::isInsideAnyVO(
        hkVector4f *vel,
        hkaiStaticObstacleSystem *sos,
        hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *edges)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm3
  __m128 v6; // xmm2
  __m128 v7; // xmm8
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  float v11; // xmm0_4
  int v12; // edi
  __int64 i; // rbx
  hkVector4f vb; // [rsp+20h] [rbp-48h] BYREF

  v4 = _mm_mul_ps(vel->m_quad, vel->m_quad);
  v5 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)), _mm_shuffle_ps(v4, v4, 170));
  v6 = _mm_rsqrt_ps(v5);
  v7 = _mm_mul_ps(
         vel->m_quad,
         _mm_andnot_ps(
           _mm_cmple_ps(v5, (__m128)0i64),
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v6, v5), v6)), _mm_mul_ps(*(__m128 *)_xmm, v6))));
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  vb.m_quad = _mm_mul_ps(
                v7,
                _mm_andnot_ps(
                  _mm_cmple_ps(v9, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                    _mm_mul_ps(*(__m128 *)_xmm, v10))));
  v11 = hkaiAvoidanceSolverUtils::calcAngle(&sos->m_forward, &sos->m_left, &vb);
  v12 = 0;
  if ( edges->m_size <= 0 )
    return 0xFFFFFFFFi64;
  for ( i = 0i64;
        !hkaiAvoidanceSolverUtils::isAngleInsideVO(v11, edges->m_data[i].m_angle, edges->m_data[i + 1].m_angle);
        i += 2i64 )
  {
    v12 += 2;
    if ( v12 >= edges->m_size )
      return 0xFFFFFFFFi64;
  }
  return (unsigned int)v12;
}

// File Line: 144
// RVA: 0xC28E70
_BOOL8 __fastcall hkaiStaticObstacleSystem::sideLessThan(
        hkaiStaticObstacleSystem::VelocityObstacleEdge *voeA,
        hkaiStaticObstacleSystem::VelocityObstacleEdge *voeB)
{
  return voeA->m_angle < voeB->m_angle;
}

// File Line: 151
// RVA: 0xC273D0
void __fastcall hkaiStaticObstacleSolver::solve(
        hkaiAvoidanceSolver::WorldInfo *worldInfo,
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkaiAvoidanceSolver::ControlGradient *gradient)
{
  int v6; // ebx
  int v7; // ebx
  bool v8; // zf
  int v9; // ebx
  hkLifoAllocator *Value; // rcx
  hkaiStaticObstacleSystem::VelocityObstacleEdge *m_cur; // rax
  int v12; // edx
  char *v13; // r8
  int m_size; // eax
  char *v15; // rdi
  signed int v16; // ebx
  hkLifoAllocator *v17; // rax
  int v18; // r8d
  hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> edges; // [rsp+30h] [rbp-50h] BYREF
  void *p; // [rsp+40h] [rbp-40h]
  int v21; // [rsp+48h] [rbp-38h]
  hkaiStaticObstacleSystem sos; // [rsp+50h] [rbp-30h] BYREF
  float minCollisionTime; // [rsp+A0h] [rbp+20h] BYREF

  minCollisionTime = FLOAT_3_40282e38;
  hkaiStaticObstacleSystem::hkaiStaticObstacleSystem(&sos, &agent->m_velocity, &worldInfo->m_up);
  v6 = agent->m_numBoundaryObstacles + agent->m_numSphereObstacles;
  edges.m_data = 0i64;
  edges.m_size = 0;
  v7 = agent->m_numNearbyAgents + v6;
  edges.m_capacityAndFlags = 0x80000000;
  v8 = 2 * v7 == 0;
  v9 = 2 * v7;
  v21 = v9;
  if ( v8 )
  {
    m_cur = 0i64;
  }
  else
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkaiStaticObstacleSystem::VelocityObstacleEdge *)Value->m_cur;
    v12 = (8 * v9 + 127) & 0xFFFFFF80;
    v13 = (char *)m_cur + v12;
    if ( v12 > Value->m_slabSize || v13 > Value->m_end )
      m_cur = (hkaiStaticObstacleSystem::VelocityObstacleEdge *)hkLifoAllocator::allocateFromNewSlab(Value, v12);
    else
      Value->m_cur = v13;
  }
  edges.m_data = m_cur;
  p = m_cur;
  edges.m_capacityAndFlags = v9 | 0x80000000;
  sos.m_narrowMult = hkaiStaticObstacleSolver::detectNarrowCorridor(&worldInfo->m_up, agent);
  hkaiStaticObstacleSolver::processNearbyAgents(worldInfo, agent, &sos, &minCollisionTime, gradient, &edges);
  hkaiStaticObstacleSolver::processNearbyObstacles(worldInfo, agent, &sos, &minCollisionTime, gradient, &edges);
  hkaiStaticObstacleSolver::processNearbyBoundaries(worldInfo, agent, &sos, &minCollisionTime, gradient, &edges);
  m_size = edges.m_size;
  if ( edges.m_size >= 2 )
  {
    hkaiStaticObstacleSystem::findClosestEdge(
      &sos,
      &agent->m_localSteeringInput.m_desiredFutureDir,
      &worldInfo->m_up,
      &edges);
    hkaiStaticObstacleSolver::calcGradient(agent, &sos, &worldInfo->m_up, minCollisionTime, gradient, &edges);
    m_size = edges.m_size;
  }
  v15 = (char *)p;
  if ( p == edges.m_data )
    m_size = 0;
  edges.m_size = m_size;
  v16 = (8 * v21 + 127) & 0xFFFFFF80;
  v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v18 = (v16 + 15) & 0xFFFFFFF0;
  if ( v16 > v17->m_slabSize || &v15[v18] != v17->m_cur || v17->m_firstNonLifoEnd == v15 )
    hkLifoAllocator::slowBlockFree(v17, v15, v18);
  else
    v17->m_cur = v15;
  edges.m_size = 0;
  if ( edges.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      edges.m_data,
      8 * edges.m_capacityAndFlags);
}

// File Line: 201
// RVA: 0xC275F0
// bad sp value at call has been detected, the output may be wrong!
void __fastcall hkaiStaticObstacleSolver::calcGradient(
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkaiStaticObstacleSystem *sos,
        hkVector4f *up,
        const float minCollisionTime,
        hkaiAvoidanceSolver::ControlGradient *gradient,
        hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *edges)
{
  hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *v6; // r14
  hkVector4f *p_m_velocity; // r15
  hkVector4f *p_m_desiredVelocity; // r12
  __int64 isInsideAnyVO; // r13
  int v13; // ebx
  int v14; // eax
  __m128 *v15; // rbx
  float m_angle; // xmm6_4
  __m128 v17; // xmm1
  float v18; // xmm9_4
  __m128 v19; // xmm3
  __m128 v20; // xmm1
  float v21; // xmm8_4
  bool v22; // zf
  hkaiAvoidanceProperties *v23; // rax
  __m128 m_quad; // xmm2
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
  hkVector4f edge; // [rsp+0h] [rbp-79h] BYREF
  hkQuaternionf quat; // [rsp+10h] [rbp-69h] BYREF
  hkVector4f dvel; // [rsp+20h] [rbp-59h] BYREF
  float v47; // [rsp+30h] [rbp-49h]
  hkaiAvoidanceProperties *m_avoidanceProperties; // [rsp+D0h] [rbp+57h]
  hkVector4f *axis; // [rsp+E0h] [rbp+67h]
  __m128 *v50; // [rsp+F0h] [rbp+77h]
  hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *vars0; // [rsp+F8h] [rbp+7Fh]

  v6 = vars0;
  p_m_velocity = &agent->m_velocity;
  m_avoidanceProperties = agent->m_avoidanceProperties;
  p_m_desiredVelocity = &agent->m_localSteeringInput.m_desiredVelocity;
  isInsideAnyVO = (int)hkaiStaticObstacleSystem::isInsideAnyVO(&agent->m_velocity, sos, vars0);
  v13 = hkaiStaticObstacleSystem::isInsideAnyVO(p_m_desiredVelocity, sos, vars0);
  v14 = hkaiStaticObstacleSystem::isInsideAnyVO(&agent->m_localSteeringInput.m_desiredFutureDir, sos, vars0);
  if ( v13 != -1 )
  {
    v15 = v50;
    m_angle = FLOAT_3_1415927;
    if ( v14 > -1 && (_DWORD)isInsideAnyVO == v14 )
    {
      v17 = _mm_mul_ps(p_m_velocity->m_quad, p_m_velocity->m_quad);
      v18 = m_avoidanceProperties->m_movementProperties.m_minVelocity + 0.2;
      v19 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170));
      v20 = _mm_rsqrt_ps(v19);
      LODWORD(v21) = _mm_andnot_ps(
                       _mm_cmple_ps(v19, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                           _mm_mul_ps(*(__m128 *)_xmm, v20)),
                         v19)).m128_u32[0];
      if ( hkaiAvoidanceSolverUtils::fabsAngle(
             vars0->m_data[isInsideAnyVO].m_angle,
             vars0->m_data[(int)isInsideAnyVO + 1].m_angle) > 3.1415927
        && v21 < v18 )
      {
        v50[3].m128_i8[0] = 1;
      }
    }
    v22 = !sos->m_merged;
    v23 = m_avoidanceProperties;
    m_quad = p_m_desiredVelocity->m_quad;
    v47 = *(float *)&FLOAT_1_0;
    dvel.m_quad.m128_i32[2] = 1058642330;
    v25 = _mm_mul_ps(m_quad, m_quad);
    *(float *)&m_avoidanceProperties = (float)((float)(minCollisionTime * 0.39999998)
                                             / m_avoidanceProperties->m_boundaryLimitTime)
                                     + 0.60000002;
    v26 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
            _mm_shuffle_ps(v25, v25, 170));
    v27 = _mm_rsqrt_ps(v26);
    dvel.m_quad.m128_i32[2] = LODWORD(v23->m_movementProperties.m_maxVelocity);
    v28 = (__m128)dvel.m_quad.m128_u32[2];
    v29 = _mm_andnot_ps(
            _mm_cmple_ps(v26, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                _mm_mul_ps(*(__m128 *)_xmm, v27)),
              v26)).m128_f32[0]
        * fminf(fmaxf(*(float *)&m_avoidanceProperties, 0.60000002), 1.0);
    *(float *)&m_avoidanceProperties = v23->m_movementProperties.m_minVelocity;
    v47 = v29;
    v30 = fminf(fmaxf(v29, *(float *)&m_avoidanceProperties), dvel.m_quad.m128_f32[2]);
    if ( !v22 )
      m_angle = v6->m_data[sos->m_closestEdgeIdx].m_angle;
    v31 = axis;
    hkQuaternionf::setAxisAngle(&quat, axis, m_angle);
    hkVector4f::setRotatedDir(&edge, &quat, &sos->m_forward);
    v28.m128_f32[0] = v30;
    v32 = _mm_mul_ps(edge.m_quad, _mm_shuffle_ps(v28, v28, 0));
    edge.m_quad = v32;
    if ( (int)isInsideAnyVO <= -1 )
    {
      dvel.m_quad.m128_u64[1] = *(unsigned __int128 *)&_mm_sub_ps(p_m_desiredVelocity->m_quad, p_m_velocity->m_quad) >> 64;
      v43 = hkaiAvoidanceSolverUtils::intersectVelDeltaVelVOEdge(p_m_velocity, &dvel, v31, &edge);
      if ( v43 < v15->m128_f32[3] )
        v15->m128_f32[3] = v43;
    }
    else
    {
      if ( minCollisionTime == 0.0 )
      {
        v33 = FLOAT_100000_0;
      }
      else
      {
        v47 = 0.0;
        dvel.m_quad.m128_f32[2] = FLOAT_100000_0;
        *(float *)&m_avoidanceProperties = 10.0 / minCollisionTime;
        v33 = fminf(fmaxf(10.0 / minCollisionTime, 0.0), 100000.0);
      }
      v34 = _mm_sub_ps(p_m_velocity->m_quad, v32);
      v35 = _mm_mul_ps(v34, v34);
      v36 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
              _mm_shuffle_ps(v35, v35, 170));
      v37 = _mm_rsqrt_ps(v36);
      v38 = _mm_mul_ps(*(__m128 *)_xmm, v37);
      v39 = _mm_mul_ps(_mm_mul_ps(v37, v36), v37);
      v37.m128_f32[0] = v33;
      v40 = _mm_andnot_ps(_mm_cmple_ps(v36, (__m128)0i64), _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v39), v38));
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
void __fastcall hkaiStaticObstacleSolver::processNearbyAgents(
        hkaiAvoidanceSolver::WorldInfo *worldInfo,
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkaiStaticObstacleSystem *sos,
        float *minCollisionTime,
        hkaiAvoidanceSolver::ControlGradient *gradient,
        hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *edges)
{
  __m128 v6; // xmm10
  hkaiAvoidanceProperties *m_avoidanceProperties; // rsi
  hkaiAvoidanceSolver::ObstacleAgent *m_nearbyAgents; // rbp
  int v9; // edi
  float v13; // xmm10_4
  hkaiAvoidanceSolver::ObstacleAgent *v14; // r12
  __m128 v15; // xmm2
  float v16; // xmm9_4
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  double v20; // xmm0_8
  float v21; // xmm8_4
  double v22; // xmm0_8
  __m128 v23; // xmm2
  hkVector4f agentToObstacle; // [rsp+30h] [rbp-88h] BYREF

  m_avoidanceProperties = agent->m_avoidanceProperties;
  m_nearbyAgents = agent->m_nearbyAgents;
  v9 = 0;
  v6.m128_f32[0] = m_avoidanceProperties->m_limitObstacleVelocity * m_avoidanceProperties->m_limitObstacleVelocity;
  for ( LODWORD(v13) = _mm_shuffle_ps(v6, v6, 0).m128_u32[0]; v9 < agent->m_numNearbyAgents; ++v9 )
  {
    v14 = m_nearbyAgents++;
    v15 = _mm_mul_ps(v14->m_velocity.m_quad, v14->m_velocity.m_quad);
    if ( (float)((float)(_mm_shuffle_ps(v15, v15, 85).m128_f32[0] + _mm_shuffle_ps(v15, v15, 0).m128_f32[0])
               + _mm_shuffle_ps(v15, v15, 170).m128_f32[0]) < v13 )
    {
      hkaiAvoidanceSolverUtils::manageAgentPenetration(
        COERCE_FLOAT(*(_OWORD *)&worldInfo->m_timeStep),
        agent,
        v14,
        gradient);
      v16 = v14->m_radius + agent->m_radius;
      agentToObstacle.m_quad = _mm_sub_ps(v14->m_position.m_quad, agent->m_position.m_quad);
      v17 = _mm_mul_ps(agentToObstacle.m_quad, agentToObstacle.m_quad);
      v18 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170));
      v19 = _mm_rsqrt_ps(v18);
      v20 = hkaiAvoidanceSolverUtils::calcSphereCollisionTime(
              v16,
              &agentToObstacle,
              &agent->m_velocity,
              &worldInfo->m_up);
      v21 = *(float *)&v20;
      if ( (float)(_mm_andnot_ps(
                     _mm_cmple_ps(v18, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                         _mm_mul_ps(*(__m128 *)_xmm, v19)),
                       v18)).m128_f32[0]
                 - v16) < m_avoidanceProperties->m_limitObstacleDistance
        || *(float *)&v20 < m_avoidanceProperties->m_obstacleLimitTime
        || (v22 = hkaiAvoidanceSolverUtils::calcSphereCollisionTime(
                    v16,
                    &agentToObstacle,
                    &agent->m_localSteeringInput.m_desiredVelocity,
                    &worldInfo->m_up),
            *(float *)&v22 < m_avoidanceProperties->m_obstacleLimitTime) )
      {
        v23 = _mm_mul_ps(agent->m_localSteeringInput.m_desiredFutureDir.m_quad, agentToObstacle.m_quad);
        if ( (float)((float)(_mm_shuffle_ps(v23, v23, 85).m128_f32[0] + _mm_shuffle_ps(v23, v23, 0).m128_f32[0])
                   + _mm_shuffle_ps(v23, v23, 170).m128_f32[0]) <= agent->m_localSteeringInput.m_distToLocalGoal
          || !agent->m_localSteeringInput.m_isLocalGoalLast.m_bool )
        {
          hkaiStaticObstacleSolver::addSphereVelocityObstacleEdges(v16, &agentToObstacle, &worldInfo->m_up, sos, edges);
          if ( v21 < *minCollisionTime )
            *minCollisionTime = v21;
        }
      }
    }
  }
}

// File Line: 344
// RVA: 0xC27C00
void __fastcall hkaiStaticObstacleSolver::processNearbyObstacles(
        hkaiAvoidanceSolver::WorldInfo *worldInfo,
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkaiStaticObstacleSystem *sos,
        float *minCollisionTime,
        hkaiAvoidanceSolver::ControlGradient *gradient,
        hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *edges)
{
  __m128 v6; // xmm10
  hkaiAvoidanceProperties *m_avoidanceProperties; // rsi
  hkaiAvoidanceSolver::SphereObstacle *m_sphereObstacles; // rbp
  int v9; // edi
  float v13; // xmm10_4
  __int64 v14; // r14
  __m128 *p_m_quad; // r13
  __m128 v16; // xmm2
  hkaiAvoidanceSolver::SphereObstacle *v17; // rax
  __m128 v18; // xmm1
  float v19; // xmm9_4
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  double v22; // xmm0_8
  float v23; // xmm8_4
  double v24; // xmm0_8
  __m128 v25; // xmm2
  hkVector4f agentToObstacle; // [rsp+30h] [rbp-88h] BYREF

  m_avoidanceProperties = agent->m_avoidanceProperties;
  m_sphereObstacles = agent->m_sphereObstacles;
  v9 = 0;
  v6.m128_f32[0] = m_avoidanceProperties->m_limitObstacleVelocity * m_avoidanceProperties->m_limitObstacleVelocity;
  LODWORD(v13) = _mm_shuffle_ps(v6, v6, 0).m128_u32[0];
  if ( agent->m_numSphereObstacles > 0 )
  {
    v14 = 0i64;
    do
    {
      p_m_quad = &m_sphereObstacles->m_sphere.m_pos.m_quad;
      ++m_sphereObstacles;
      v16 = _mm_mul_ps(p_m_quad[1], p_m_quad[1]);
      if ( (float)((float)(_mm_shuffle_ps(v16, v16, 85).m128_f32[0] + _mm_shuffle_ps(v16, v16, 0).m128_f32[0])
                 + _mm_shuffle_ps(v16, v16, 170).m128_f32[0]) < v13 )
      {
        hkaiAvoidanceSolverUtils::manageObstaclePenetration(
          COERCE_FLOAT(*(_OWORD *)&worldInfo->m_timeStep),
          agent,
          &agent->m_sphereObstacles[v9],
          gradient);
        v17 = agent->m_sphereObstacles;
        agentToObstacle.m_quad = _mm_sub_ps(*p_m_quad, agent->m_position.m_quad);
        v18 = _mm_mul_ps(agentToObstacle.m_quad, agentToObstacle.m_quad);
        v19 = v17[v14].m_sphere.m_pos.m_quad.m128_f32[3] + agent->m_radius;
        v20 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                _mm_shuffle_ps(v18, v18, 170));
        v21 = _mm_rsqrt_ps(v20);
        v22 = hkaiAvoidanceSolverUtils::calcSphereCollisionTime(
                v19,
                &agentToObstacle,
                &agent->m_velocity,
                &worldInfo->m_up);
        v23 = *(float *)&v22;
        if ( (float)(_mm_andnot_ps(
                       _mm_cmple_ps(v20, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                           _mm_mul_ps(*(__m128 *)_xmm, v21)),
                         v20)).m128_f32[0]
                   - v19) < m_avoidanceProperties->m_limitObstacleDistance
          || *(float *)&v22 < m_avoidanceProperties->m_obstacleLimitTime
          || (v24 = hkaiAvoidanceSolverUtils::calcSphereCollisionTime(
                      v19,
                      &agentToObstacle,
                      &agent->m_localSteeringInput.m_desiredVelocity,
                      &worldInfo->m_up),
              *(float *)&v24 < m_avoidanceProperties->m_obstacleLimitTime) )
        {
          v25 = _mm_mul_ps(agent->m_localSteeringInput.m_desiredFutureDir.m_quad, agentToObstacle.m_quad);
          if ( (float)((float)(_mm_shuffle_ps(v25, v25, 85).m128_f32[0] + _mm_shuffle_ps(v25, v25, 0).m128_f32[0])
                     + _mm_shuffle_ps(v25, v25, 170).m128_f32[0]) <= agent->m_localSteeringInput.m_distToLocalGoal
            || !agent->m_localSteeringInput.m_isLocalGoalLast.m_bool )
          {
            hkaiStaticObstacleSolver::addSphereVelocityObstacleEdges(
              v19,
              &agentToObstacle,
              &worldInfo->m_up,
              sos,
              edges);
            if ( v23 < *minCollisionTime )
              *minCollisionTime = v23;
          }
        }
      }
      ++v9;
      ++v14;
    }
    while ( v9 < agent->m_numSphereObstacles );
  }
}

// File Line: 396
// RVA: 0xC27E50
void __fastcall hkaiStaticObstacleSolver::processNearbyBoundaries(
        hkaiAvoidanceSolver::WorldInfo *worldInfo,
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkaiStaticObstacleSystem *sos,
        float *minCollisionTime,
        hkaiAvoidanceSolver::ControlGradient *gradient,
        hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *edges)
{
  hkaiAvoidanceProperties *m_avoidanceProperties; // r15
  hkaiAvoidanceSolver::BoundaryObstacle *m_boundaryObstacles; // rax
  float v10; // xmm8_4
  float m_limitBoundaryDistance; // xmm6_4
  int v12; // xmm11_4
  int i; // esi
  hkaiAvoidanceSolver::BoundaryObstacle *v15; // r14
  __m128 v16; // xmm2
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  float v19; // xmm7_4
  float m_boundaryRadius; // xmm0_4
  __m128 v21; // xmm2
  float v22; // xmm9_4
  float v23; // xmm10_4
  float m_narrowMult; // xmm1_4
  float v25; // xmm1_4
  float m_boundaryLimitTime; // xmm0_4
  bool v27; // al
  float v28; // xmm1_4
  hkaiAvoidanceSolver::BoundaryObstacle *v29; // [rsp+40h] [rbp-F8h]
  hkVector4f boundaryPlane; // [rsp+50h] [rbp-E8h] BYREF
  hkVector4f agentToEnd; // [rsp+60h] [rbp-D8h] BYREF
  hkVector4f agentToStart; // [rsp+70h] [rbp-C8h] BYREF

  m_avoidanceProperties = agent->m_avoidanceProperties;
  m_boundaryObstacles = agent->m_boundaryObstacles;
  v10 = FLOAT_3_40282e38;
  m_limitBoundaryDistance = m_avoidanceProperties->m_limitBoundaryDistance;
  v12 = gradient->m_direction.m_quad.m128_i32[3];
  if ( m_limitBoundaryDistance < 0.0 )
    m_limitBoundaryDistance = agent->m_radius * 3.0;
  for ( i = 0; i < agent->m_numBoundaryObstacles; ++i )
  {
    v15 = m_boundaryObstacles;
    v29 = m_boundaryObstacles + 1;
    hkaiAvoidanceSolverUtils::calcBoundaryPlane(m_boundaryObstacles, &worldInfo->m_up, &boundaryPlane);
    v16 = _mm_mul_ps(agent->m_position.m_quad, boundaryPlane.m_quad);
    v17 = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, boundaryPlane.m_quad), 196);
    v18 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 78), v17);
    if ( (float)(_mm_shuffle_ps(v18, v18, 177).m128_f32[0] + v18.m128_f32[0]) > 0.0 )
    {
      v19 = hkaiAvoidanceSolverUtils::closestDistToLineSegment(&agent->m_position, &v15->m_start, &v15->m_end);
      hkaiAvoidanceSolverUtils::manageBoundaryPenetration(
        COERCE_FLOAT(*(_OWORD *)&worldInfo->m_timeStep),
        agent,
        &boundaryPlane,
        v19,
        gradient);
      m_boundaryRadius = agent->m_boundaryRadius;
      v21 = _mm_sub_ps(v15->m_end.m_quad, agent->m_position.m_quad);
      agentToStart.m_quad = _mm_sub_ps(v15->m_start.m_quad, agent->m_position.m_quad);
      agentToEnd.m_quad = v21;
      v22 = hkaiAvoidanceSolverUtils::calcBoundaryCollisionTime(
              m_boundaryRadius,
              &agentToStart,
              &agentToEnd,
              &agent->m_velocity,
              &boundaryPlane,
              &worldInfo->m_up);
      v23 = hkaiAvoidanceSolverUtils::calcBoundaryCollisionTime(
              agent->m_boundaryRadius,
              &agentToStart,
              &agentToEnd,
              &agent->m_localSteeringInput.m_desiredVelocity,
              &boundaryPlane,
              &worldInfo->m_up);
      m_narrowMult = sos->m_narrowMult;
      v25 = m_narrowMult < 0.0 ? m_limitBoundaryDistance : m_narrowMult * m_limitBoundaryDistance;
      if ( v19 < v25
        || (m_boundaryLimitTime = m_avoidanceProperties->m_boundaryLimitTime, v22 < m_boundaryLimitTime)
        || v23 < m_boundaryLimitTime )
      {
        if ( (m_limitBoundaryDistance <= agent->m_localSteeringInput.m_distToLocalGoal
           || !agent->m_localSteeringInput.m_isLocalGoalLast.m_bool)
          && (m_avoidanceProperties->m_boundaryLimitTime <= agent->m_localSteeringInput.m_timeToLocalGoal
           || !agent->m_localSteeringInput.m_isLocalGoalLast.m_bool) )
        {
          v27 = hkaiAvoidanceSolverUtils::detectFrontArea(
                  agent->m_boundaryRadius,
                  &agent->m_position,
                  v15,
                  &boundaryPlane);
          hkaiStaticObstacleSolver::addBoundaryVelocityObstacleEdges(
            v27,
            agent->m_boundaryRadius,
            &agentToStart,
            &agentToEnd,
            &worldInfo->m_up,
            sos,
            edges);
          v28 = fminf(v22, v23);
          if ( v28 < *minCollisionTime )
            *minCollisionTime = v28;
          if ( v19 < v10 )
          {
            v10 = v19;
            gradient->m_direction.m_quad = _mm_mul_ps(
                                             *(__m128 *)_xmm_bf800000bf800000bf800000bf800000,
                                             boundaryPlane.m_quad);
          }
        }
      }
    }
    m_boundaryObstacles = v29;
  }
  gradient->m_direction.m_quad.m128_i32[3] = v12;
}

// File Line: 461
// RVA: 0xC28180
float __fastcall hkaiStaticObstacleSolver::detectNarrowCorridor(
        hkVector4f *up,
        hkaiAvoidanceSolver::SteeringAgent *agent)
{
  __m128 v2; // xmm9
  float v3; // xmm7_4
  float v4; // xmm8_4
  float v6; // xmm6_4
  hkVector4f v8; // xmm11
  __m128 v9; // xmm2
  float v10; // xmm0_4
  hkaiAvoidanceSolver::BoundaryObstacle *m_boundaryObstacles; // rbp
  int v12; // esi
  __m128 v13; // xmm9
  __m128 v14; // xmm2
  __m128 v15; // xmm9
  __m128 v16; // xmm11
  __m128 v17; // xmm11
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 i; // xmm11
  hkVector4f *p_m_start; // rbx
  hkaiAvoidanceSolver::BoundaryObstacle *v23; // rcx
  __m128 v24; // xmm2
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  int v27; // ecx
  int v28; // eax
  __m128 v29; // xmm1
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  __m128 v34; // xmm1
  float v35; // xmm0_4
  float v36; // xmm0_4
  __m128 v37; // xmm1
  float v38; // xmm2_4
  hkVector4f boundaryPlane; // [rsp+20h] [rbp-B8h] BYREF

  v3 = agent->m_radius * 5.0;
  v4 = FLOAT_3_40282e38;
  v6 = FLOAT_3_40282e38;
  v8.m_quad = (__m128)agent->m_localSteeringInput.m_desiredFutureDir;
  v9 = _mm_mul_ps(agent->m_forward.m_quad, v8.m_quad);
  if ( (float)((float)(_mm_shuffle_ps(v9, v9, 85).m128_f32[0] + _mm_shuffle_ps(v9, v9, 0).m128_f32[0])
             + _mm_shuffle_ps(v9, v9, 170).m128_f32[0]) < 0.0 )
    v10 = FLOAT_N1_0;
  else
    v10 = *(float *)&FLOAT_1_0;
  m_boundaryObstacles = agent->m_boundaryObstacles;
  v2.m128_f32[0] = v10;
  v12 = 0;
  v13 = _mm_mul_ps(_mm_shuffle_ps(v2, v2, 0), v8.m_quad);
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
  for ( i = _mm_mul_ps(
              v17,
              _mm_andnot_ps(
                _mm_cmple_ps(v19, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                  _mm_mul_ps(*(__m128 *)_xmm, v20)))); v12 < agent->m_numBoundaryObstacles; ++v12 )
  {
    p_m_start = &m_boundaryObstacles->m_start;
    v23 = m_boundaryObstacles++;
    hkaiAvoidanceSolverUtils::calcBoundaryPlane(v23, up, &boundaryPlane);
    v24 = _mm_mul_ps(boundaryPlane.m_quad, agent->m_position.m_quad);
    v25 = _mm_shuffle_ps(v24, _mm_unpackhi_ps(v24, boundaryPlane.m_quad), 196);
    v26 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 78), v25);
    if ( (float)(_mm_shuffle_ps(v26, v26, 177).m128_f32[0] + v26.m128_f32[0]) > 0.0 )
    {
      v27 = 0;
      v28 = 0;
      v29 = _mm_mul_ps(v15, p_m_start->m_quad);
      v30 = _mm_mul_ps(v15, p_m_start[1].m_quad);
      v31 = _mm_shuffle_ps(v29, _mm_unpackhi_ps(v29, v15), 196);
      v32 = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, v15), 196);
      v33 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 78), v31);
      v34 = _mm_add_ps(_mm_shuffle_ps(v32, v32, 78), v32);
      LODWORD(v35) = _mm_shuffle_ps(v33, v33, 177).m128_u32[0];
      if ( (float)(_mm_shuffle_ps(v34, v34, 177).m128_f32[0] + v34.m128_f32[0]) > 0.0 )
        v27 = 1;
      if ( (float)(v35 + v33.m128_f32[0]) > 0.0 )
        v28 = 1;
      if ( v28 | v27 )
      {
        v36 = hkaiAvoidanceSolverUtils::closestDistToLineSegment(&agent->m_position, p_m_start, p_m_start + 1);
        if ( v36 < v3 )
        {
          v37 = _mm_mul_ps(boundaryPlane.m_quad, i);
          v38 = (float)(_mm_shuffle_ps(v37, v37, 85).m128_f32[0] + _mm_shuffle_ps(v37, v37, 0).m128_f32[0])
              + _mm_shuffle_ps(v37, v37, 170).m128_f32[0];
          if ( v38 > 0.80000001 && v36 < v4 )
            v4 = v36;
          if ( v38 < -0.80000001 && v36 < v6 )
            v6 = v36;
        }
      }
    }
  }
  if ( v4 >= v3 )
  {
    if ( v6 >= v3 )
      return FLOAT_N1_0;
    if ( v4 >= v3 )
      return *(float *)&FLOAT_1_0;
  }
  if ( v6 >= v3 )
    return *(float *)&FLOAT_1_0;
  else
    return fminf(fmaxf((float)(v6 + v4) / (float)(v3 * 1.2), 0.5), 1.0);
}

// File Line: 515
// RVA: 0xC28530
void __fastcall hkaiStaticObstacleSolver::addSphereVelocityObstacleEdges(
        const float radius,
        hkVector4f *agentToObstacle,
        hkVector4f *up,
        hkaiStaticObstacleSystem *sos,
        hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *edges)
{
  __int128 v5; // xmm8
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
  __m128 v17; // xmm2
  __m128 v18; // xmm5
  __m128 v19; // xmm10
  __m128 v20; // xmm4
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  float v23; // xmm10_4
  float v24; // xmm6_4
  float v25; // xmm0_4
  hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *v26; // rbx
  __int64 m_size; // rsi
  int v28; // r9d
  int v29; // eax
  int v30; // eax
  hkaiStaticObstacleSystem::VelocityObstacleEdge *m_data; // rax
  hkaiStaticObstacleSystem::VelocityObstacleEdge *v32; // rdx
  hkVector4f vb; // [rsp+30h] [rbp-88h] BYREF
  __int128 v34; // [rsp+70h] [rbp-48h]
  hkResult result; // [rsp+C0h] [rbp+8h] BYREF
  int v36; // [rsp+C8h] [rbp+10h]
  int v37; // [rsp+D8h] [rbp+20h]

  v7 = _mm_mul_ps(agentToObstacle->m_quad, agentToObstacle->m_quad);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  v10 = _mm_andnot_ps(
          _mm_cmple_ps(v8, (__m128)0i64),
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
    v34 = v5;
    v15 = _mm_min_ps(
            _mm_max_ps((__m128)LODWORD(v14), *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
            *(__m128 *)_xmm);
    v16 = _mm_andnot_ps(*(__m128 *)_xmm, v15);
    v17 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v16), *(__m128 *)_xmm);
    v18 = _mm_cmplt_ps(*(__m128 *)_xmm, v16);
    v19 = _mm_cmplt_ps(v16, *(__m128 *)_xmm);
    v20 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v17), v18), _mm_andnot_ps(v18, v16));
    v21 = _mm_or_ps(_mm_andnot_ps(v18, _mm_mul_ps(v16, v16)), _mm_and_ps(v18, v17));
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
    LODWORD(v23) = (_mm_andnot_ps(
                      v19,
                      _mm_or_ps(
                        _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v22, v22)), v18),
                        _mm_andnot_ps(v18, v22))).m128_u32[0] | v19.m128_i32[0] & v16.m128_i32[0]) ^ v15.m128_i32[0] & _xmm[0];
  }
  v24 = hkaiAvoidanceSolverUtils::clampAngle(v13 - v23);
  v25 = hkaiAvoidanceSolverUtils::clampAngle(v23 + v13);
  v26 = edges;
  m_size = edges->m_size;
  v28 = m_size + 2;
  v29 = edges->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v29 < (int)m_size + 2 )
  {
    v30 = 2 * v29;
    if ( v28 < v30 )
      v28 = v30;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, edges, v28, 8);
  }
  m_data = v26->m_data;
  v26->m_size += 2;
  v32 = &m_data[m_size];
  v32->m_angle = v24;
  v32->m_type = OPEN;
  v32[1].m_angle = v25;
  v32[1].m_type = CLOSE;
  if ( hkaiAvoidanceSolverUtils::isAngleInsideVO(3.1415927, v24, v25) )
    ++sos->m_numCutVO;
}

// File Line: 559
// RVA: 0xC28860
void __fastcall hkaiStaticObstacleSolver::addBoundaryVelocityObstacleEdges(
        bool insideFrontArea,
        const float radius,
        hkVector4f *agentToStart,
        hkVector4f *agentToEnd,
        hkVector4f *up,
        hkaiStaticObstacleSystem *sos,
        hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *edges)
{
  __m128 m_quad; // xmm5
  hkaiStaticObstacleSystem *v8; // rbp
  float v11; // xmm6_4
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
  __m128 v32; // xmm2
  __m128 v33; // xmm5
  __m128 v34; // xmm4
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  __m128 v37; // xmm0
  float v38; // xmm10_4
  __m128 v39; // xmm9
  __m128 v40; // xmm7
  __m128 v41; // xmm2
  __m128 v42; // xmm5
  __m128 v43; // xmm4
  __m128 v44; // xmm3
  __m128 v45; // xmm2
  __m128 v46; // xmm0
  float v47; // xmm0_4
  hkArray<hkaiStaticObstacleSystem::VelocityObstacleEdge,hkContainerHeapAllocator> *v48; // rbx
  __int64 m_size; // rdi
  int v50; // r9d
  int v51; // eax
  int v52; // eax
  hkaiStaticObstacleSystem::VelocityObstacleEdge *m_data; // rax
  hkaiStaticObstacleSystem::VelocityObstacleEdge *v54; // rdx
  hkVector4f vb; // [rsp+30h] [rbp-C8h] BYREF
  hkVector4f v56; // [rsp+40h] [rbp-B8h] BYREF
  hkResult result; // [rsp+100h] [rbp+8h] BYREF
  float v58; // [rsp+108h] [rbp+10h]

  m_quad = agentToStart->m_quad;
  v8 = sos;
  v11 = fmaxf(0.00000011920929, radius * 1.01);
  *(float *)&result.m_enum = v11;
  v13 = _mm_mul_ps(m_quad, m_quad);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_rsqrt_ps(v14);
  v16 = _mm_andnot_ps(
          _mm_cmple_ps(v14, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)), _mm_mul_ps(*(__m128 *)_xmm, v15)));
  v58 = v16.m128_f32[0] * v14.m128_f32[0];
  vb.m_quad = _mm_mul_ps(m_quad, v16);
  v17 = fmaxf(v16.m128_f32[0] * v14.m128_f32[0], v11);
  v18 = hkaiAvoidanceSolverUtils::calcAngle(&sos->m_forward, &sos->m_left, &vb);
  v19 = agentToEnd->m_quad;
  v20 = v18;
  v21 = _mm_mul_ps(v19, v19);
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v23 = _mm_rsqrt_ps(v22);
  LODWORD(v58) = _mm_andnot_ps(
                   _mm_cmple_ps(v22, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                       _mm_mul_ps(*(__m128 *)_xmm, v23)),
                     v22)).m128_u32[0];
  *(float *)&result.m_enum = v11;
  v24 = fmaxf(v58, v11);
  v25 = _mm_mul_ps(v19, v19);
  v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)), _mm_shuffle_ps(v25, v25, 170));
  v27 = _mm_rsqrt_ps(v26);
  v56.m_quad = _mm_mul_ps(
                 v19,
                 _mm_andnot_ps(
                   _mm_cmple_ps(v26, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                     _mm_mul_ps(*(__m128 *)_xmm, v27))));
  v28 = hkaiAvoidanceSolverUtils::calcAngle(&v8->m_forward, &v8->m_left, &v56);
  v29 = v28;
  if ( !insideFrontArea )
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
  *(float *)&result.m_enum = radius / v17;
  v30 = _mm_min_ps(
          _mm_max_ps((__m128)COERCE_UNSIGNED_INT(radius / v17), *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
          *(__m128 *)_xmm);
  v31 = _mm_andnot_ps(*(__m128 *)_xmm, v30);
  v32 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v31), *(__m128 *)_xmm);
  v33 = _mm_cmplt_ps(*(__m128 *)_xmm, v31);
  v34 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v32), v33), _mm_andnot_ps(v33, v31));
  v35 = _mm_or_ps(_mm_andnot_ps(v33, _mm_mul_ps(v31, v31)), _mm_and_ps(v33, v32));
  v36 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v35, *(__m128 *)coeff4), *(__m128 *)coeff3), v35),
                        *(__m128 *)coeff2),
                      v35),
                    *(__m128 *)coeff1),
                  v35),
                *(__m128 *)coeff0),
              v35),
            v34),
          v34);
  v37 = _mm_cmplt_ps(v31, *(__m128 *)_xmm);
  v38 = hkaiAvoidanceSolverUtils::clampAngle(
          v20
        - COERCE_FLOAT((_mm_andnot_ps(
                          v37,
                          _mm_or_ps(
                            _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v36, v36)), v33),
                            _mm_andnot_ps(v33, v36))).m128_u32[0] | v37.m128_i32[0] & v31.m128_i32[0]) ^ v30.m128_i32[0] & _xmm[0]));
  *(float *)&result.m_enum = radius / v24;
  v39 = _mm_min_ps(
          _mm_max_ps((__m128)COERCE_UNSIGNED_INT(radius / v24), *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
          *(__m128 *)_xmm);
  v40 = _mm_andnot_ps(*(__m128 *)_xmm, v39);
  v41 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v40), *(__m128 *)_xmm);
  v42 = _mm_cmplt_ps(*(__m128 *)_xmm, v40);
  v43 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v41), v42), _mm_andnot_ps(v42, v40));
  v44 = _mm_or_ps(_mm_andnot_ps(v42, _mm_mul_ps(v40, v40)), _mm_and_ps(v42, v41));
  v45 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v44, *(__m128 *)coeff4), *(__m128 *)coeff3), v44),
                        *(__m128 *)coeff2),
                      v44),
                    *(__m128 *)coeff1),
                  v44),
                *(__m128 *)coeff0),
              v44),
            v43),
          v43);
  v46 = _mm_cmplt_ps(v40, *(__m128 *)_xmm);
  v47 = hkaiAvoidanceSolverUtils::clampAngle(
          COERCE_FLOAT((_mm_andnot_ps(
                          v46,
                          _mm_or_ps(
                            _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v45, v45)), v42),
                            _mm_andnot_ps(v42, v45))).m128_u32[0] | v46.m128_i32[0] & v40.m128_i32[0]) ^ v39.m128_i32[0] & _xmm[0])
        + v29);
  v48 = edges;
  m_size = edges->m_size;
  v50 = m_size + 2;
  v51 = edges->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v51 < (int)m_size + 2 )
  {
    v52 = 2 * v51;
    if ( v50 < v52 )
      v50 = v52;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, edges, v50, 8);
  }
  m_data = v48->m_data;
  v48->m_size += 2;
  v54 = &m_data[m_size];
  v54->m_angle = v38;
  v54->m_type = OPEN;
  v54[1].m_angle = v47;
  v54[1].m_type = CLOSE;
  if ( hkaiAvoidanceSolverUtils::isAngleInsideVO(3.1415927, v38, v47) )
    ++v8->m_numCutVO;
}

