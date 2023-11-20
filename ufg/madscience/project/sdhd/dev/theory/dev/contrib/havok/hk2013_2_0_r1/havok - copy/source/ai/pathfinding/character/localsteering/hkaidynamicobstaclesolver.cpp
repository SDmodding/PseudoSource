// File Line: 29
// RVA: 0xC28ED0
void __fastcall hkaiDynamicObstacleSolver::solve(hkaiAvoidanceSolver::WorldInfo *worldInfo, hkaiAvoidanceSolver::SteeringAgent *agent, hkVector4f *deltaVelocity, hkaiAvoidanceSolver::ControlGradient *controlGradient)
{
  hkaiAvoidanceSolver::ControlGradient *v4; // rbx
  hkVector4f *v5; // rdi
  hkaiAvoidanceSolver::SteeringAgent *v6; // rsi
  hkaiAvoidanceSolver::WorldInfo *v7; // rbp

  v4 = controlGradient;
  v5 = deltaVelocity;
  v6 = agent;
  v7 = worldInfo;
  hkaiDynamicObstacleSolver::processNearbyAgents(worldInfo, agent, deltaVelocity, controlGradient);
  hkaiDynamicObstacleSolver::processNearbyObstacles(v7, v6, v5, v4);
}

// File Line: 45
// RVA: 0xC28F20
void __usercall hkaiDynamicObstacleSolver::processNearbyAgents(hkaiAvoidanceSolver::WorldInfo *worldInfo@<rcx>, hkaiAvoidanceSolver::SteeringAgent *agent@<rdx>, hkVector4f *deltaVelocity@<r8>, hkaiAvoidanceSolver::ControlGradient *controlGradient@<r9>, __m128 a5@<xmm6>)
{
  hkaiAvoidanceSolver::ObstacleAgent *v5; // r12
  hkaiAvoidanceSolver::ControlGradient *v6; // rdi
  hkVector4f *v7; // r15
  hkaiAvoidanceSolver::SteeringAgent *v8; // rbx
  hkaiAvoidanceSolver::WorldInfo *v9; // r14
  int v10; // ebp
  float v11; // xmm6_4
  hkaiAvoidanceSolver::ObstacleAgent *v12; // rsi
  __m128 v13; // xmm2
  hkaiDynamicObstacleSolver::VelocityObstacle velocityObstacle; // [rsp+20h] [rbp-78h]

  v5 = agent->m_nearbyAgents;
  v6 = controlGradient;
  v7 = deltaVelocity;
  v8 = agent;
  v9 = worldInfo;
  v10 = 0;
  a5.m128_f32[0] = agent->m_avoidanceProperties->m_limitObstacleVelocity
                 * agent->m_avoidanceProperties->m_limitObstacleVelocity;
  for ( LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(a5, a5, 0); v10 < v8->m_numNearbyAgents; ++v10 )
  {
    v12 = v5;
    ++v5;
    v13 = _mm_mul_ps(v12->m_velocity.m_quad, v12->m_velocity.m_quad);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 170))) >= v11 )
    {
      hkaiAvoidanceSolverUtils::manageAgentPenetration(COERCE_FLOAT(*(_OWORD *)&v9->m_timeStep), v8, v12, v6);
      *(_QWORD *)&velocityObstacle.m_desiredCollisionTime = 2139095022i64;
      velocityObstacle.m_currentCollisionTime = 3.40282e38;
      hkaiDynamicObstacleSolver::buildAgentRVO(v8, v12, &v9->m_up, &velocityObstacle);
      if ( velocityObstacle.m_desiredCollisionTime <= (float)(v8->m_localSteeringInput.m_timeToLocalGoal * 0.5)
        || v8->m_localSteeringInput.m_timeToLocalGoal >= v8->m_avoidanceProperties->m_agentLimitTime
        || !v8->m_localSteeringInput.m_isLocalGoalLast.m_bool )
      {
        velocityObstacle.m_gradientType = hkaiDynamicObstacleSolver::selectGradient(v8, v12);
        if ( velocityObstacle.m_gradientType )
          hkaiDynamicObstacleSolver::calcGradient(v8, &velocityObstacle, v7, v6);
        if ( hkaiDynamicObstacleSolver::detectFailure(v12, 0i64, v8, v6) )
          v6->m_failed = 1;
      }
    }
  }
}

// File Line: 101
// RVA: 0xC290B0
void __usercall hkaiDynamicObstacleSolver::processNearbyObstacles(hkaiAvoidanceSolver::WorldInfo *worldInfo@<rcx>, hkaiAvoidanceSolver::SteeringAgent *agent@<rdx>, hkVector4f *deltaVelocity@<r8>, hkaiAvoidanceSolver::ControlGradient *controlGradient@<r9>, __m128 a5@<xmm6>)
{
  hkaiAvoidanceSolver::SphereObstacle *v5; // rbp
  int v6; // ebx
  hkaiAvoidanceSolver::ControlGradient *v7; // r14
  hkVector4f *v8; // r12
  hkaiAvoidanceSolver::SteeringAgent *v9; // rdi
  hkaiAvoidanceSolver::WorldInfo *v10; // r15
  float v11; // xmm6_4
  hkaiAvoidanceSolver::SphereObstacle *v12; // rsi
  __m128 v13; // xmm2
  hkaiDynamicObstacleSolver::VelocityObstacle velocityObstacle; // [rsp+20h] [rbp-58h]

  v5 = agent->m_sphereObstacles;
  v6 = 0;
  v7 = controlGradient;
  v8 = deltaVelocity;
  v9 = agent;
  v10 = worldInfo;
  a5.m128_f32[0] = agent->m_avoidanceProperties->m_limitObstacleVelocity
                 * agent->m_avoidanceProperties->m_limitObstacleVelocity;
  for ( LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(a5, a5, 0); v6 < v9->m_numSphereObstacles; ++v6 )
  {
    v12 = v5;
    ++v5;
    v13 = _mm_mul_ps(v12->m_velocity.m_quad, v12->m_velocity.m_quad);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 170))) >= v11 )
    {
      hkaiAvoidanceSolverUtils::manageObstaclePenetration(COERCE_FLOAT(*(_OWORD *)&v10->m_timeStep), v9, v12, v7);
      velocityObstacle.m_type = 1;
      velocityObstacle.m_currentCollisionTime = 3.40282e38;
      velocityObstacle.m_desiredCollisionTime = 3.40282e38;
      hkaiDynamicObstacleSolver::buildObstacleVO(v12, v9, &v10->m_up, &velocityObstacle);
      velocityObstacle.m_gradientType = 2;
      hkaiDynamicObstacleSolver::calcGradient(v9, &velocityObstacle, v8, v7);
      hkaiDynamicObstacleSolver::detectFailure(0i64, v12, v9, v7);
    }
  }
}

// File Line: 148
// RVA: 0xC291E0
void __fastcall hkaiDynamicObstacleSolver::calcGradient(hkaiAvoidanceSolver::SteeringAgent *agent, hkaiDynamicObstacleSolver::VelocityObstacle *velocityObstacle, hkVector4f *deltaVelocity, hkaiAvoidanceSolver::ControlGradient *controlGradient)
{
  hkaiAvoidanceProperties *v4; // rax
  hkaiAvoidanceSolver::ControlGradient *v5; // rdi
  hkVector4f *v6; // rbp
  hkaiDynamicObstacleSolver::VelocityObstacle *v7; // rsi
  float v8; // xmm6_4
  float v9; // xmm2_4
  __m128 v10; // xmm2
  float v11; // xmm1_4
  hkVector4f *v12; // rbx
  float v13; // xmm1_4
  hkVector4f gradient; // [rsp+40h] [rbp-28h]
  float v15; // [rsp+78h] [rbp+10h]
  float v16; // [rsp+78h] [rbp+10h]

  v4 = agent->m_avoidanceProperties;
  v5 = controlGradient;
  v6 = deltaVelocity;
  v7 = velocityObstacle;
  if ( velocityObstacle->m_type )
    v8 = v4->m_obstacleLimitTime;
  else
    v8 = v4->m_agentLimitTime;
  if ( v8 < velocityObstacle->m_currentCollisionTime )
  {
    if ( v8 > velocityObstacle->m_desiredCollisionTime && controlGradient->m_total.m_quad.m128_f32[3] == 0.0 )
    {
      v12 = &agent->m_velocity;
      v16 = hkaiAvoidanceSolverUtils::intersectVelDeltaVelRVO(
              &agent->m_velocity,
              deltaVelocity,
              &velocityObstacle->m_leftPlane);
      v13 = fminf(v16, hkaiAvoidanceSolverUtils::intersectVelDeltaVelRVO(v12, v6, &v7->m_rightPlane));
      if ( v13 < v5->m_direction.m_quad.m128_f32[3] )
        v5->m_direction.m_quad.m128_f32[3] = v13;
    }
  }
  else
  {
    gradient.m_quad = 0i64;
    hkaiAvoidanceSolverUtils::calcVOGradient(
      v4->m_movementProperties.m_minVelocity,
      &agent->m_velocity,
      velocityObstacle,
      &controlGradient->m_direction,
      &gradient);
    v9 = v7->m_currentCollisionTime;
    if ( v9 == 0.0 )
    {
      v10 = (__m128)LODWORD(FLOAT_1000_0);
    }
    else
    {
      v15 = (float)(1.0 / v9) - (float)(1.0 / v8);
      v10 = (__m128)LODWORD(v15);
      v10.m128_f32[0] = fminf(fmaxf(v15, 0.0), 1000.0);
    }
    v11 = gradient.m_quad.m128_f32[3] + v5->m_total.m_quad.m128_f32[3];
    v5->m_total.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), gradient.m_quad), v5->m_total.m_quad);
    v5->m_total.m_quad.m128_f32[3] = v11;
  }
}

// File Line: 194
// RVA: 0xC29340
signed __int64 __fastcall hkaiDynamicObstacleSolver::selectGradient(hkaiAvoidanceSolver::SteeringAgent *agent, hkaiAvoidanceSolver::ObstacleAgent *obstacle)
{
  unsigned __int16 v2; // r8
  unsigned __int16 v3; // cx
  signed __int64 result; // rax

  v2 = agent->m_priority;
  v3 = obstacle->m_priority;
  if ( v2 < v3 )
    return 1i64;
  result = 2i64;
  if ( v2 > v3 )
    result = 0i64;
  return result;
}

// File Line: 215
// RVA: 0xC29370
bool __fastcall hkaiDynamicObstacleSolver::detectFailure(hkaiAvoidanceSolver::ObstacleAgent *neighborAgent, hkaiAvoidanceSolver::SphereObstacle *sphereObstacle, hkaiAvoidanceSolver::SteeringAgent *agent, hkaiAvoidanceSolver::ControlGradient *controlGradient)
{
  float v4; // xmm3_4
  float v5; // xmm3_4
  __m128 *v6; // rax
  __m128 v7; // xmm2
  __m128 v8; // xmm2
  __m128 *v9; // rax
  __m128 v10; // xmm1
  __m128 v11; // xmm1
  float v12; // xmm2_4
  float v13; // xmm0_4

  if ( neighborAgent )
    v4 = neighborAgent->m_radius;
  else
    v4 = sphereObstacle->m_sphere.m_pos.m_quad.m128_f32[3];
  v5 = v4 + agent->m_radius;
  v6 = &sphereObstacle->m_sphere.m_pos.m_quad;
  if ( neighborAgent )
    v6 = &neighborAgent->m_position.m_quad;
  v7 = _mm_sub_ps(*v6, agent->m_position.m_quad);
  v8 = _mm_mul_ps(v7, v7);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 170))) < (float)((float)(v5 * 0.94999999) * (float)(v5 * 0.94999999)) )
  {
    v9 = &neighborAgent->m_velocity.m_quad;
    if ( !neighborAgent )
      v9 = &sphereObstacle->m_velocity.m_quad;
    v10 = _mm_sub_ps(agent->m_velocity.m_quad, *v9);
    v11 = _mm_mul_ps(v10, v10);
    v12 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))
        + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170));
    if ( neighborAgent )
      v13 = FLOAT_0_25;
    else
      v13 = *(float *)&FLOAT_1_0;
    if ( v12 < v13 && (sphereObstacle || neighborAgent && agent->m_priority >= neighborAgent->m_priority) )
      controlGradient->m_failed = 1;
  }
  return 0;
}

// File Line: 263
// RVA: 0xC29440
void __usercall hkaiDynamicObstacleSolver::buildAgentRVO(hkaiAvoidanceSolver::SteeringAgent *agent@<rcx>, hkaiAvoidanceSolver::ObstacleAgent *obstacle@<rdx>, hkVector4f *up@<r8>, hkaiDynamicObstacleSolver::VelocityObstacle *velocityObstacle@<r9>, __m128 a5@<xmm2>)
{
  __m128 v5; // xmm1
  hkVector4f *v6; // rsi
  hkVector4f *v7; // r14
  hkaiAvoidanceSolver::SteeringAgent *v8; // rbx
  hkaiDynamicObstacleSolver::VelocityObstacle *v9; // rbp
  float radius; // xmm6_4
  __m128 v11; // xmm0
  hkVector4f agentToObstacle; // [rsp+40h] [rbp-38h]
  __m128 v13; // [rsp+50h] [rbp-28h]

  v5 = (__m128)LODWORD(obstacle->m_weight);
  v6 = &obstacle->m_velocity;
  v7 = up;
  v8 = agent;
  v9 = velocityObstacle;
  radius = agent->m_radius + obstacle->m_radius;
  a5.m128_f32[0] = 1.0 - v5.m128_f32[0];
  v11 = _mm_sub_ps(obstacle->m_position.m_quad, agent->m_position.m_quad);
  v13 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(a5, a5, 0), agent->m_velocity.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v5, v5, 0), obstacle->m_velocity.m_quad));
  agentToObstacle.m_quad = v11;
  hkaiDynamicObstacleSolver::calcVOGeometry(up, &agentToObstacle, (hkVector4f *)&v13, radius, velocityObstacle);
  hkaiDynamicObstacleSolver::calcVOCollisionTimes(
    v7,
    &agentToObstacle,
    v6,
    &v8->m_velocity,
    &v8->m_localSteeringInput.m_desiredVelocity,
    1,
    radius,
    v9);
}

// File Line: 287
// RVA: 0xC29520
void __fastcall hkaiDynamicObstacleSolver::buildObstacleVO(hkaiAvoidanceSolver::SphereObstacle *sphereObstacle, hkaiAvoidanceSolver::SteeringAgent *agent, hkVector4f *up, hkaiDynamicObstacleSolver::VelocityObstacle *velocityObstacle)
{
  float radius; // xmm6_4
  hkVector4f *v5; // rbx
  hkVector4f *v6; // rbp
  hkaiAvoidanceSolver::SteeringAgent *v7; // rdi
  hkaiDynamicObstacleSolver::VelocityObstacle *v8; // rsi
  hkVector4f agentToObstacle; // [rsp+40h] [rbp-28h]

  radius = agent->m_radius + sphereObstacle->m_sphere.m_pos.m_quad.m128_f32[3];
  v5 = &sphereObstacle->m_velocity;
  v6 = up;
  v7 = agent;
  v8 = velocityObstacle;
  agentToObstacle.m_quad = _mm_sub_ps(sphereObstacle->m_sphere.m_pos.m_quad, agent->m_position.m_quad);
  hkaiDynamicObstacleSolver::calcVOGeometry(up, &agentToObstacle, &sphereObstacle->m_velocity, radius, velocityObstacle);
  hkaiDynamicObstacleSolver::calcVOCollisionTimes(
    v6,
    &agentToObstacle,
    v5,
    &v7->m_velocity,
    &v7->m_localSteeringInput.m_desiredVelocity,
    0,
    radius,
    v8);
}

// File Line: 304
// RVA: 0xC29920
void __usercall hkaiDynamicObstacleSolver::calcVOCollisionTimes(hkVector4f *up@<rcx>, hkVector4f *agentToObstacle@<rdx>, hkVector4f *obstacleVelocity@<r8>, hkVector4f *agentVelocity@<r9>, __m128 a5@<xmm2>, hkVector4f *agentDesiredVelocity, const bool isObstacleActive, const float radius, hkaiDynamicObstacleSolver::VelocityObstacle *velocityObstacle)
{
  hkVector4f *v9; // rsi
  hkVector4f *v10; // rbp
  hkVector4f *v11; // rdi
  __m128 v12; // xmm0
  float v13; // xmm1_4
  hkVector4f vel; // [rsp+20h] [rbp-18h]

  v9 = agentToObstacle;
  v10 = up;
  v11 = agentVelocity;
  vel.m_quad = _mm_sub_ps(agentVelocity->m_quad, obstacleVelocity->m_quad);
  if ( hkaiAvoidanceSolverUtils::isInsideRVO(
         agentVelocity,
         &velocityObstacle->m_leftPlane,
         &velocityObstacle->m_rightPlane) )
  {
    velocityObstacle->m_currentCollisionTime = hkaiAvoidanceSolverUtils::intersectVelCircle(&vel, radius, v9, v10);
  }
  v12 = _mm_sub_ps(agentDesiredVelocity->m_quad, v11->m_quad);
  if ( isObstacleActive )
    v13 = FLOAT_2_0;
  else
    v13 = *(float *)&FLOAT_1_0;
  a5.m128_f32[0] = v13;
  vel.m_quad = _mm_add_ps(vel.m_quad, _mm_mul_ps(_mm_shuffle_ps(a5, a5, 0), v12));
  if ( hkaiAvoidanceSolverUtils::isInsideRVO(
         agentDesiredVelocity,
         &velocityObstacle->m_leftPlane,
         &velocityObstacle->m_rightPlane) )
  {
    velocityObstacle->m_desiredCollisionTime = hkaiAvoidanceSolverUtils::intersectVelCircle(&vel, radius, v9, v10);
  }
}

// File Line: 332
// RVA: 0xC295D0
void __fastcall hkaiDynamicObstacleSolver::calcVOGeometry(hkVector4f *up, hkVector4f *obstacleAgentPos, hkVector4f *obstacleVelocity, const float radiusR, hkaiDynamicObstacleSolver::VelocityObstacle *velocityObstacle)
{
  __m128 v5; // xmm5
  __m128 v6; // xmm12
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm2
  __m128 v10; // xmm4
  __m128 v11; // xmm5
  __m128 v12; // xmm9
  __m128 v13; // xmm6
  __m128 v14; // xmm0
  __m128 v15; // xmm2
  __m128 v16; // xmm12
  __m128 v17; // xmm0
  __m128 v18; // xmm5
  __m128 v19; // xmm2
  __m128 v20; // xmm10
  __m128 v21; // xmm8
  __m128 v22; // xmm8
  __m128 v23; // xmm13
  __m128 v24; // xmm1
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  __m128 v27; // xmm8
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  hkVector4f v32; // xmm5
  __m128 v33; // xmm2
  __m128 v34; // xmm4
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  hkVector4f v38; // xmm3
  __m128 v39; // xmm2

  v5 = _mm_shuffle_ps((__m128)LODWORD(radiusR), (__m128)LODWORD(radiusR), 0);
  v6 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0049999999), (__m128)LODWORD(FLOAT_0_0049999999), 0);
  v7 = _mm_mul_ps(obstacleAgentPos->m_quad, obstacleAgentPos->m_quad);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  v10 = _mm_mul_ps(_mm_add_ps(v6, query.m_quad), v5);
  v11 = _mm_mul_ps(v5, v5);
  v12 = _mm_max_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v8, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)), _mm_mul_ps(v9, *(__m128 *)_xmm)),
              v8)),
          v10);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(v12, _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v12, v13)), v13), v11));
  v15 = _mm_cmpltps(v14, v12);
  v16 = _mm_max_ps(v6, _mm_or_ps(_mm_and_ps(v15, v14), _mm_andnot_ps(v15, v12)));
  v17 = _mm_sub_ps(v12, v16);
  v18 = _mm_sub_ps(v11, _mm_mul_ps(v17, v17));
  v19 = _mm_rsqrt_ps(v18);
  v20 = _mm_andnot_ps(
          _mm_cmpleps(v18, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
              _mm_mul_ps(v19, *(__m128 *)_xmm)),
            v18));
  v21 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(obstacleAgentPos->m_quad, obstacleAgentPos->m_quad, 201), up->m_quad),
          _mm_mul_ps(_mm_shuffle_ps(up->m_quad, up->m_quad, 201), obstacleAgentPos->m_quad));
  v22 = _mm_shuffle_ps(v21, v21, 201);
  v23 = _mm_sub_ps(query.m_quad, _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v12, v13)), v13), v16));
  v24 = _mm_mul_ps(v22, v22);
  v25 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)), _mm_shuffle_ps(v24, v24, 170));
  v26 = _mm_rsqrt_ps(v25);
  v27 = _mm_mul_ps(
          v22,
          _mm_andnot_ps(
            _mm_cmpleps(v25, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
              _mm_mul_ps(v26, *(__m128 *)_xmm))));
  v28 = _mm_add_ps(_mm_mul_ps(v23, obstacleAgentPos->m_quad), _mm_mul_ps(v27, v20));
  v29 = _mm_mul_ps(v28, v28);
  v30 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)), _mm_shuffle_ps(v29, v29, 170));
  v31 = _mm_rsqrt_ps(v30);
  v32.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v30, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                     _mm_mul_ps(v31, *(__m128 *)_xmm))),
                 v28);
  velocityObstacle->m_leftPlane = (hkVector4f)v32.m_quad;
  v33 = _mm_mul_ps(v32.m_quad, obstacleVelocity->m_quad);
  velocityObstacle->m_leftPlane.m_quad = _mm_shuffle_ps(
                                           v32.m_quad,
                                           _mm_unpackhi_ps(
                                             v32.m_quad,
                                             _mm_sub_ps(
                                               (__m128)0i64,
                                               _mm_add_ps(
                                                 _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
                                                 _mm_shuffle_ps(v33, v33, 170)))),
                                           196);
  v34 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, v20), v27), _mm_mul_ps(obstacleAgentPos->m_quad, v23));
  v35 = _mm_mul_ps(v34, v34);
  v36 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)), _mm_shuffle_ps(v35, v35, 170));
  v37 = _mm_rsqrt_ps(v36);
  v38.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v36, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v37, v36), v37)),
                     _mm_mul_ps(v37, *(__m128 *)_xmm))),
                 v34);
  velocityObstacle->m_rightPlane = (hkVector4f)v38.m_quad;
  v39 = _mm_mul_ps(v38.m_quad, obstacleVelocity->m_quad);
  velocityObstacle->m_rightPlane.m_quad = _mm_shuffle_ps(
                                            v38.m_quad,
                                            _mm_unpackhi_ps(
                                              v38.m_quad,
                                              _mm_sub_ps(
                                                (__m128)0i64,
                                                _mm_add_ps(
                                                  _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                                                  _mm_shuffle_ps(v39, v39, 170)))),
                                            196);
}

