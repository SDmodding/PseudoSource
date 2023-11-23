// File Line: 29
// RVA: 0xC28ED0
void __fastcall hkaiDynamicObstacleSolver::solve(
        hkaiAvoidanceSolver::WorldInfo *worldInfo,
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkVector4f *deltaVelocity,
        hkaiAvoidanceSolver::ControlGradient *controlGradient)
{
  hkaiDynamicObstacleSolver::processNearbyAgents(worldInfo, agent, deltaVelocity, controlGradient);
  hkaiDynamicObstacleSolver::processNearbyObstacles(worldInfo, agent, deltaVelocity, controlGradient);
}

// File Line: 45
// RVA: 0xC28F20
void __fastcall hkaiDynamicObstacleSolver::processNearbyAgents(
        hkaiAvoidanceSolver::WorldInfo *worldInfo,
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkVector4f *deltaVelocity,
        hkaiAvoidanceSolver::ControlGradient *controlGradient)
{
  __m128 v4; // xmm6
  hkaiAvoidanceSolver::ObstacleAgent *m_nearbyAgents; // r12
  int v10; // ebp
  float v11; // xmm6_4
  hkaiAvoidanceSolver::ObstacleAgent *v12; // rsi
  __m128 v13; // xmm2
  hkaiDynamicObstacleSolver::VelocityObstacle velocityObstacle; // [rsp+20h] [rbp-78h] BYREF

  m_nearbyAgents = agent->m_nearbyAgents;
  v10 = 0;
  v4.m128_f32[0] = agent->m_avoidanceProperties->m_limitObstacleVelocity
                 * agent->m_avoidanceProperties->m_limitObstacleVelocity;
  for ( LODWORD(v11) = _mm_shuffle_ps(v4, v4, 0).m128_u32[0]; v10 < agent->m_numNearbyAgents; ++v10 )
  {
    v12 = m_nearbyAgents++;
    v13 = _mm_mul_ps(v12->m_velocity.m_quad, v12->m_velocity.m_quad);
    if ( (float)((float)(_mm_shuffle_ps(v13, v13, 85).m128_f32[0] + _mm_shuffle_ps(v13, v13, 0).m128_f32[0])
               + _mm_shuffle_ps(v13, v13, 170).m128_f32[0]) >= v11 )
    {
      hkaiAvoidanceSolverUtils::manageAgentPenetration(
        COERCE_FLOAT(*(_OWORD *)&worldInfo->m_timeStep),
        agent,
        v12,
        controlGradient);
      *(_QWORD *)&velocityObstacle.m_desiredCollisionTime = 2139095022i64;
      velocityObstacle.m_currentCollisionTime = 3.40282e38;
      hkaiDynamicObstacleSolver::buildAgentRVO(agent, v12, &worldInfo->m_up, &velocityObstacle);
      if ( velocityObstacle.m_desiredCollisionTime <= (float)(agent->m_localSteeringInput.m_timeToLocalGoal * 0.5)
        || agent->m_localSteeringInput.m_timeToLocalGoal >= agent->m_avoidanceProperties->m_agentLimitTime
        || !agent->m_localSteeringInput.m_isLocalGoalLast.m_bool )
      {
        velocityObstacle.m_gradientType = hkaiDynamicObstacleSolver::selectGradient(agent, v12);
        if ( velocityObstacle.m_gradientType )
          hkaiDynamicObstacleSolver::calcGradient(agent, &velocityObstacle, deltaVelocity, controlGradient);
        if ( hkaiDynamicObstacleSolver::detectFailure(v12, 0i64, agent, controlGradient) )
          controlGradient->m_failed = 1;
      }
    }
  }
}

// File Line: 101
// RVA: 0xC290B0
void __fastcall hkaiDynamicObstacleSolver::processNearbyObstacles(
        hkaiAvoidanceSolver::WorldInfo *worldInfo,
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkVector4f *deltaVelocity,
        hkaiAvoidanceSolver::ControlGradient *controlGradient)
{
  __m128 v4; // xmm6
  hkaiAvoidanceSolver::SphereObstacle *m_sphereObstacles; // rbp
  int v6; // ebx
  float v11; // xmm6_4
  hkaiAvoidanceSolver::SphereObstacle *v12; // rsi
  __m128 v13; // xmm2
  hkaiDynamicObstacleSolver::VelocityObstacle velocityObstacle; // [rsp+20h] [rbp-58h] BYREF

  m_sphereObstacles = agent->m_sphereObstacles;
  v6 = 0;
  v4.m128_f32[0] = agent->m_avoidanceProperties->m_limitObstacleVelocity
                 * agent->m_avoidanceProperties->m_limitObstacleVelocity;
  for ( LODWORD(v11) = _mm_shuffle_ps(v4, v4, 0).m128_u32[0]; v6 < agent->m_numSphereObstacles; ++v6 )
  {
    v12 = m_sphereObstacles++;
    v13 = _mm_mul_ps(v12->m_velocity.m_quad, v12->m_velocity.m_quad);
    if ( (float)((float)(_mm_shuffle_ps(v13, v13, 85).m128_f32[0] + _mm_shuffle_ps(v13, v13, 0).m128_f32[0])
               + _mm_shuffle_ps(v13, v13, 170).m128_f32[0]) >= v11 )
    {
      hkaiAvoidanceSolverUtils::manageObstaclePenetration(
        COERCE_FLOAT(*(_OWORD *)&worldInfo->m_timeStep),
        agent,
        v12,
        controlGradient);
      velocityObstacle.m_type = 1;
      velocityObstacle.m_currentCollisionTime = 3.40282e38;
      velocityObstacle.m_desiredCollisionTime = 3.40282e38;
      hkaiDynamicObstacleSolver::buildObstacleVO(v12, agent, &worldInfo->m_up, &velocityObstacle);
      velocityObstacle.m_gradientType = 2;
      hkaiDynamicObstacleSolver::calcGradient(agent, &velocityObstacle, deltaVelocity, controlGradient);
      hkaiDynamicObstacleSolver::detectFailure(0i64, v12, agent, controlGradient);
    }
  }
}

// File Line: 148
// RVA: 0xC291E0
void __fastcall hkaiDynamicObstacleSolver::calcGradient(
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkaiDynamicObstacleSolver::VelocityObstacle *velocityObstacle,
        hkVector4f *deltaVelocity,
        hkaiAvoidanceSolver::ControlGradient *controlGradient)
{
  hkaiAvoidanceProperties *m_avoidanceProperties; // rax
  float m_obstacleLimitTime; // xmm6_4
  float m_currentCollisionTime; // xmm2_4
  __m128 v10; // xmm2
  float v11; // xmm1_4
  hkVector4f *p_m_velocity; // rbx
  float v13; // xmm1_4
  hkVector4f gradient; // [rsp+40h] [rbp-28h] BYREF
  float v15; // [rsp+78h] [rbp+10h]
  float v16; // [rsp+78h] [rbp+10h]

  m_avoidanceProperties = agent->m_avoidanceProperties;
  if ( velocityObstacle->m_type )
    m_obstacleLimitTime = m_avoidanceProperties->m_obstacleLimitTime;
  else
    m_obstacleLimitTime = m_avoidanceProperties->m_agentLimitTime;
  if ( m_obstacleLimitTime < velocityObstacle->m_currentCollisionTime )
  {
    if ( m_obstacleLimitTime > velocityObstacle->m_desiredCollisionTime
      && controlGradient->m_total.m_quad.m128_f32[3] == 0.0 )
    {
      p_m_velocity = &agent->m_velocity;
      v16 = hkaiAvoidanceSolverUtils::intersectVelDeltaVelRVO(
              &agent->m_velocity,
              deltaVelocity,
              &velocityObstacle->m_leftPlane);
      v13 = fminf(
              v16,
              hkaiAvoidanceSolverUtils::intersectVelDeltaVelRVO(
                p_m_velocity,
                deltaVelocity,
                &velocityObstacle->m_rightPlane));
      if ( v13 < controlGradient->m_direction.m_quad.m128_f32[3] )
        controlGradient->m_direction.m_quad.m128_f32[3] = v13;
    }
  }
  else
  {
    gradient.m_quad = 0i64;
    hkaiAvoidanceSolverUtils::calcVOGradient(
      m_avoidanceProperties->m_movementProperties.m_minVelocity,
      &agent->m_velocity,
      velocityObstacle,
      &controlGradient->m_direction,
      &gradient);
    m_currentCollisionTime = velocityObstacle->m_currentCollisionTime;
    if ( m_currentCollisionTime == 0.0 )
    {
      v10 = (__m128)LODWORD(FLOAT_1000_0);
    }
    else
    {
      v15 = (float)(1.0 / m_currentCollisionTime) - (float)(1.0 / m_obstacleLimitTime);
      v10 = (__m128)LODWORD(v15);
      v10.m128_f32[0] = fminf(fmaxf(v15, 0.0), 1000.0);
    }
    v11 = gradient.m_quad.m128_f32[3] + controlGradient->m_total.m_quad.m128_f32[3];
    controlGradient->m_total.m_quad = _mm_add_ps(
                                        _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), gradient.m_quad),
                                        controlGradient->m_total.m_quad);
    controlGradient->m_total.m_quad.m128_f32[3] = v11;
  }
}

// File Line: 194
// RVA: 0xC29340
__int64 __fastcall hkaiDynamicObstacleSolver::selectGradient(
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkaiAvoidanceSolver::ObstacleAgent *obstacle)
{
  unsigned __int16 m_priority; // r8
  unsigned __int16 v3; // cx
  __int64 result; // rax

  m_priority = agent->m_priority;
  v3 = obstacle->m_priority;
  if ( m_priority < v3 )
    return 1i64;
  result = 2i64;
  if ( m_priority > v3 )
    return 0i64;
  return result;
}

// File Line: 215
// RVA: 0xC29370
bool __fastcall hkaiDynamicObstacleSolver::detectFailure(
        hkaiAvoidanceSolver::SphereObstacle *neighborAgent,
        hkaiAvoidanceSolver::SphereObstacle *sphereObstacle,
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkaiAvoidanceSolver::ControlGradient *controlGradient)
{
  float v4; // xmm3_4
  float v5; // xmm3_4
  hkaiAvoidanceSolver::SphereObstacle *v6; // rax
  __m128 v7; // xmm2
  __m128 v8; // xmm2
  hkVector4f *p_m_velocity; // rax
  __m128 v10; // xmm1
  __m128 v11; // xmm1
  float v12; // xmm2_4
  float v13; // xmm0_4

  if ( neighborAgent )
    v4 = neighborAgent[1].m_velocity.m_quad.m128_f32[3];
  else
    v4 = sphereObstacle->m_sphere.m_pos.m_quad.m128_f32[3];
  v5 = v4 + agent->m_radius;
  v6 = sphereObstacle;
  if ( neighborAgent )
    v6 = neighborAgent;
  v7 = _mm_sub_ps(v6->m_sphere.m_pos.m_quad, agent->m_position.m_quad);
  v8 = _mm_mul_ps(v7, v7);
  if ( (float)((float)(_mm_shuffle_ps(v8, v8, 85).m128_f32[0] + _mm_shuffle_ps(v8, v8, 0).m128_f32[0])
             + _mm_shuffle_ps(v8, v8, 170).m128_f32[0]) < (float)((float)(v5 * 0.94999999) * (float)(v5 * 0.94999999)) )
  {
    p_m_velocity = &neighborAgent->m_velocity;
    if ( !neighborAgent )
      p_m_velocity = &sphereObstacle->m_velocity;
    v10 = _mm_sub_ps(agent->m_velocity.m_quad, p_m_velocity->m_quad);
    v11 = _mm_mul_ps(v10, v10);
    v12 = (float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0] + _mm_shuffle_ps(v11, v11, 0).m128_f32[0])
        + _mm_shuffle_ps(v11, v11, 170).m128_f32[0];
    if ( neighborAgent )
      v13 = FLOAT_0_25;
    else
      v13 = *(float *)&FLOAT_1_0;
    if ( v12 < v13
      && (sphereObstacle
       || neighborAgent && agent->m_priority >= (unsigned int)neighborAgent[1].m_velocity.m_quad.m128_i16[4]) )
    {
      controlGradient->m_failed = 1;
    }
  }
  return 0;
}

// File Line: 263
// RVA: 0xC29440
void __fastcall hkaiDynamicObstacleSolver::buildAgentRVO(
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkaiAvoidanceSolver::ObstacleAgent *obstacle,
        hkVector4f *up,
        hkaiDynamicObstacleSolver::VelocityObstacle *velocityObstacle)
{
  __m128 v4; // xmm2
  __m128 m_weight_low; // xmm1
  hkVector4f *p_m_velocity; // rsi
  float radius; // xmm6_4
  __m128 v11; // xmm0
  hkVector4f agentToObstacle; // [rsp+40h] [rbp-38h] BYREF
  hkVector4f v13; // [rsp+50h] [rbp-28h] BYREF

  m_weight_low = (__m128)LODWORD(obstacle->m_weight);
  p_m_velocity = &obstacle->m_velocity;
  radius = agent->m_radius + obstacle->m_radius;
  v4.m128_f32[0] = 1.0 - m_weight_low.m128_f32[0];
  v11 = _mm_sub_ps(obstacle->m_position.m_quad, agent->m_position.m_quad);
  v13.m_quad = _mm_add_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v4, v4, 0), agent->m_velocity.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(m_weight_low, m_weight_low, 0), obstacle->m_velocity.m_quad));
  agentToObstacle.m_quad = v11;
  hkaiDynamicObstacleSolver::calcVOGeometry(up, &agentToObstacle, &v13, radius, velocityObstacle);
  hkaiDynamicObstacleSolver::calcVOCollisionTimes(
    up,
    &agentToObstacle,
    p_m_velocity,
    &agent->m_velocity,
    &agent->m_localSteeringInput.m_desiredVelocity,
    1,
    radius,
    velocityObstacle);
}

// File Line: 287
// RVA: 0xC29520
void __fastcall hkaiDynamicObstacleSolver::buildObstacleVO(
        hkaiAvoidanceSolver::SphereObstacle *sphereObstacle,
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkVector4f *up,
        hkaiDynamicObstacleSolver::VelocityObstacle *velocityObstacle)
{
  float radius; // xmm6_4
  hkVector4f *p_m_velocity; // rbx
  hkVector4f agentToObstacle; // [rsp+40h] [rbp-28h] BYREF

  radius = agent->m_radius + sphereObstacle->m_sphere.m_pos.m_quad.m128_f32[3];
  p_m_velocity = &sphereObstacle->m_velocity;
  agentToObstacle.m_quad = _mm_sub_ps(sphereObstacle->m_sphere.m_pos.m_quad, agent->m_position.m_quad);
  hkaiDynamicObstacleSolver::calcVOGeometry(up, &agentToObstacle, &sphereObstacle->m_velocity, radius, velocityObstacle);
  hkaiDynamicObstacleSolver::calcVOCollisionTimes(
    up,
    &agentToObstacle,
    p_m_velocity,
    &agent->m_velocity,
    &agent->m_localSteeringInput.m_desiredVelocity,
    0,
    radius,
    velocityObstacle);
}

// File Line: 304
// RVA: 0xC29920
void __fastcall hkaiDynamicObstacleSolver::calcVOCollisionTimes(
        hkVector4f *up,
        hkVector4f *agentToObstacle,
        hkVector4f *obstacleVelocity,
        hkVector4f *agentVelocity,
        hkVector4f *agentDesiredVelocity,
        bool isObstacleActive,
        float radius,
        hkaiDynamicObstacleSolver::VelocityObstacle *velocityObstacle)
{
  __m128 v8; // xmm2
  __m128 v12; // xmm0
  float v13; // xmm1_4
  hkVector4f vel; // [rsp+20h] [rbp-18h] BYREF

  vel.m_quad = _mm_sub_ps(agentVelocity->m_quad, obstacleVelocity->m_quad);
  if ( hkaiAvoidanceSolverUtils::isInsideRVO(
         agentVelocity,
         &velocityObstacle->m_leftPlane,
         &velocityObstacle->m_rightPlane) )
  {
    velocityObstacle->m_currentCollisionTime = hkaiAvoidanceSolverUtils::intersectVelCircle(
                                                 &vel,
                                                 radius,
                                                 agentToObstacle,
                                                 up);
  }
  v12 = _mm_sub_ps(agentDesiredVelocity->m_quad, agentVelocity->m_quad);
  if ( isObstacleActive )
    v13 = FLOAT_2_0;
  else
    v13 = *(float *)&FLOAT_1_0;
  v8.m128_f32[0] = v13;
  vel.m_quad = _mm_add_ps(vel.m_quad, _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), v12));
  if ( hkaiAvoidanceSolverUtils::isInsideRVO(
         agentDesiredVelocity,
         &velocityObstacle->m_leftPlane,
         &velocityObstacle->m_rightPlane) )
  {
    velocityObstacle->m_desiredCollisionTime = hkaiAvoidanceSolverUtils::intersectVelCircle(
                                                 &vel,
                                                 radius,
                                                 agentToObstacle,
                                                 up);
  }
}

// File Line: 332
// RVA: 0xC295D0
void __fastcall hkaiDynamicObstacleSolver::calcVOGeometry(
        hkVector4f *up,
        hkVector4f *obstacleAgentPos,
        hkVector4f *obstacleVelocity,
        const float radiusR,
        hkaiDynamicObstacleSolver::VelocityObstacle *velocityObstacle)
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
  __m128 v15; // xmm1
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
            _mm_cmple_ps(v8, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)), _mm_mul_ps(v9, *(__m128 *)_xmm)),
              v8)),
          v10);
  v13 = _mm_rcp_ps(v12);
  v14 = _mm_sub_ps(v12, _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v12, v13)), v13), v11));
  v15 = _mm_cmplt_ps(v14, v12);
  v16 = _mm_max_ps(v6, _mm_or_ps(_mm_and_ps(v15, v14), _mm_andnot_ps(v15, v12)));
  v17 = _mm_sub_ps(v12, v16);
  v18 = _mm_sub_ps(v11, _mm_mul_ps(v17, v17));
  v19 = _mm_rsqrt_ps(v18);
  v20 = _mm_andnot_ps(
          _mm_cmple_ps(v18, (__m128)0i64),
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
            _mm_cmple_ps(v25, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
              _mm_mul_ps(v26, *(__m128 *)_xmm))));
  v28 = _mm_add_ps(_mm_mul_ps(v23, obstacleAgentPos->m_quad), _mm_mul_ps(v27, v20));
  v29 = _mm_mul_ps(v28, v28);
  v30 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)), _mm_shuffle_ps(v29, v29, 170));
  v31 = _mm_rsqrt_ps(v30);
  v32.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v30, (__m128)0i64),
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
                   _mm_cmple_ps(v36, (__m128)0i64),
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

