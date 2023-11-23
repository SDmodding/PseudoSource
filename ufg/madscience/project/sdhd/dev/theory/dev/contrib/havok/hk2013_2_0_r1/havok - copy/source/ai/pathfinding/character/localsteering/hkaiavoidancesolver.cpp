// File Line: 25
// RVA: 0xC0FFC0
void __fastcall hkaiAvoidanceSolver::SteeringAgent::validate(hkaiAvoidanceSolver::SteeringAgent *this)
{
  hkaiReferenceFrame *m_referenceFrame; // rcx

  if ( this->m_localSteeringInput.m_enableLocalSteering.m_bool )
  {
    m_referenceFrame = this->m_localSteeringInput.m_referenceFrame;
    if ( m_referenceFrame )
      hkaiReferenceFrame::validate(m_referenceFrame);
  }
}

// File Line: 55
// RVA: 0xC0FFF0
hkResult *__fastcall hkaiAvoidanceSolver::solveSingleAgent(
        hkResult *result,
        hkaiAvoidanceSolver::WorldInfo *worldInfo,
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkVector4f *deltaVelocity)
{
  _QWORD *Value; // rax
  unsigned __int64 v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  hkaiAvoidanceProperties *m_avoidanceProperties; // rax
  __m128 v13; // xmm5
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __m128 v19; // xmm9
  __m128 v20; // xmm0
  __m128 m_quad; // xmm5
  __m128 v22; // xmm9
  __m128 v23; // xmm3
  __m128 v24; // xmm4
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  hkResultEnum m_enum; // ebx
  __m128 m_velocityHysteresis_low; // xmm3
  hkVector4f v29; // xmm1
  __m128 v30; // xmm4
  __m128 v31; // xmm4
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  __m128 v34; // xmm1
  _QWORD *v35; // r8
  _QWORD *v36; // rcx
  unsigned __int64 v37; // rax
  _QWORD *v38; // rcx
  hkaiAvoidanceProperties *v39; // rax
  char v40; // si
  int v41; // r14d
  __m128 v42; // xmm1
  bool v43; // al
  _QWORD *v44; // r8
  _QWORD *v45; // rcx
  unsigned __int64 v46; // rax
  _QWORD *v47; // rcx
  int i; // r14d
  bool v49; // al
  _QWORD *v50; // r8
  _QWORD *v51; // rcx
  unsigned __int64 v52; // rax
  _QWORD *v53; // rcx
  int v54; // r14d
  bool v55; // al
  _QWORD *v56; // rax
  _QWORD *v57; // rcx
  _QWORD *v58; // r8
  unsigned __int64 v59; // rax
  _QWORD *v60; // rcx
  bool v61; // zf
  hkVector4f *m_elements; // rdi
  hkMemoryAllocator **v63; // rax
  hkVector4f *v64; // rdi
  hkMemoryAllocator **v65; // rax
  hkVector4f *v66; // rdi
  hkMemoryAllocator **v67; // rax
  _QWORD *v68; // rax
  _QWORD *v69; // rcx
  _QWORD *v70; // r8
  unsigned __int64 v71; // rax
  _QWORD *v72; // rcx
  hkSimdFloat32 penetrationPenalty; // [rsp+70h] [rbp-80h] BYREF
  hkVector4f up; // [rsp+80h] [rbp-70h] BYREF
  hkSimdFloat32 initScore; // [rsp+90h] [rbp-60h] BYREF
  hkVector4f forward; // [rsp+A0h] [rbp-50h] BYREF
  hkSimdFloat32 desiredSpeed; // [rsp+B0h] [rbp-40h] BYREF
  hkVector4f prev; // [rsp+C0h] [rbp-30h] BYREF
  hkaiVelocityCandidateGenerator velocityCandidates; // [rsp+D0h] [rbp-20h] BYREF
  hkSimdFloat32 maxSpeed; // [rsp+130h] [rbp+40h] BYREF
  hkVector4f bestCandidate; // [rsp+140h] [rbp+50h] BYREF
  hkSimdFloat32 v83; // [rsp+150h] [rbp+60h] BYREF
  hkSimdFloat32 thresholdDistanceSquared; // [rsp+160h] [rbp+70h] BYREF
  hkVector4f right; // [rsp+170h] [rbp+80h] BYREF
  hkSimdFloat32 sidednessChangingPenalty; // [rsp+180h] [rbp+90h] BYREF
  hkaiVelocityCandidateScores bonusesIn; // [rsp+190h] [rbp+A0h] BYREF
  hkaiVelocityCandidateScores staticTtcsIn; // [rsp+3A0h] [rbp+2B0h] BYREF
  hkaiVelocityCandidateScores dynamicTtcsIn; // [rsp+5B0h] [rbp+4C0h] BYREF
  hkResult resulta; // [rsp+830h] [rbp+740h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = Value[1];
  v10 = Value;
  if ( v9 < Value[3] )
  {
    *(_QWORD *)v9 = "LtsolveSingleAgent";
    *(_QWORD *)(v9 + 16) = "Stinit";
    v11 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v11;
    v10[1] = v9 + 24;
  }
  m_avoidanceProperties = agent->m_avoidanceProperties;
  if ( m_avoidanceProperties->m_avoidanceSolverType.m_storage )
  {
    memset(&velocityCandidates, 0, 49);
    *((float *)&velocityCandidates.m_template + 3) = FLOAT_1_005;
    hkaiStaticObstacleSolver::solve(worldInfo, agent, (hkaiAvoidanceSolver::ControlGradient *)&velocityCandidates);
    hkaiDynamicObstacleSolver::solve(
      worldInfo,
      agent,
      deltaVelocity,
      (hkaiAvoidanceSolver::ControlGradient *)&velocityCandidates);
    m_enum = hkaiAvoidanceSolver::calculateDeltaVelocity(
               &resulta,
               worldInfo,
               agent,
               (hkaiAvoidanceSolver::ControlGradient *)&velocityCandidates,
               deltaVelocity)->m_enum;
  }
  else
  {
    v13 = _mm_add_ps(agent->m_velocity.m_quad, deltaVelocity->m_quad);
    up.m_quad = (__m128)worldInfo->m_up;
    v14 = _mm_mul_ps(v13, v13);
    v15 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
            _mm_shuffle_ps(v14, v14, 170));
    v16 = _mm_rsqrt_ps(v15);
    resulta.m_enum = LODWORD(FLOAT_0_0000099999997);
    v17 = _mm_andnot_ps(
            _mm_cmple_ps(v15, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
              _mm_mul_ps(*(__m128 *)_xmm, v16)));
    v18 = _mm_mul_ps(v17, v15);
    v19 = _mm_cmplt_ps(
            v18,
            _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0));
    v20 = _mm_andnot_ps(v19, _mm_mul_ps(v13, v17));
    m_quad = agent->m_velocity.m_quad;
    v22 = _mm_andnot_ps(v19, v18);
    forward.m_quad = v20;
    desiredSpeed.m_real = v22;
    v23 = _mm_mul_ps(m_quad, m_quad);
    v24 = _mm_shuffle_ps(
            (__m128)LODWORD(m_avoidanceProperties->m_movementProperties.m_maxVelocity),
            (__m128)LODWORD(m_avoidanceProperties->m_movementProperties.m_maxVelocity),
            0);
    prev.m_quad = m_quad;
    if ( (float)((float)(_mm_shuffle_ps(v23, v23, 85).m128_f32[0] + _mm_shuffle_ps(v23, v23, 0).m128_f32[0])
               + _mm_shuffle_ps(v23, v23, 170).m128_f32[0]) > (float)(v24.m128_f32[0] * v24.m128_f32[0]) )
    {
      v25 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
              _mm_shuffle_ps(v23, v23, 170));
      v26 = _mm_rsqrt_ps(v25);
      prev.m_quad = _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmple_ps(v25, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                            _mm_mul_ps(*(__m128 *)_xmm, v26))),
                        m_quad),
                      v24);
    }
    staticTtcsIn.m_scores.m_elements = staticTtcsIn.m_scores.m_vecs;
    resulta.m_enum = LODWORD(FLOAT_1_8446726e19);
    staticTtcsIn.m_scores.m_vecs[31] = 0i64;
    dynamicTtcsIn.m_scores.m_vecs[31] = 0i64;
    bonusesIn.m_scores.m_vecs[31] = 0i64;
    dynamicTtcsIn.m_scores.m_elements = dynamicTtcsIn.m_scores.m_vecs;
    *(_QWORD *)&staticTtcsIn.m_scores.m_size = 128i64;
    initScore.m_real = _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_8446726e19), (__m128)LODWORD(FLOAT_1_8446726e19), 0);
    maxSpeed.m_real = _mm_min_ps(v24, _mm_mul_ps(v22, (__m128)xmmword_141A710D0));
    m_enum = HK_SUCCESS;
    *(_QWORD *)&dynamicTtcsIn.m_scores.m_size = 128i64;
    *(_QWORD *)&bonusesIn.m_scores.m_size = 128i64;
    bonusesIn.m_scores.m_elements = bonusesIn.m_scores.m_vecs;
    hkaiVelocityCandidateScores::setAll(&staticTtcsIn, &initScore);
    hkaiVelocityCandidateScores::setAll(&dynamicTtcsIn, &initScore);
    v83.m_real = aabbOut.m_quad;
    hkaiVelocityCandidateScores::setAll(&bonusesIn, &v83);
    m_velocityHysteresis_low = (__m128)LODWORD(agent->m_avoidanceProperties->m_velocityHysteresis);
    *bonusesIn.m_scores.m_elements = (hkVector4f)_mm_unpacklo_ps(
                                                   _mm_unpacklo_ps(m_velocityHysteresis_low, m_velocityHysteresis_low),
                                                   _mm_unpacklo_ps(m_velocityHysteresis_low, (__m128)0i64));
    v29.m_quad = (__m128)worldInfo->m_up;
    penetrationPenalty.m_real = 0i64;
    v30 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v29.m_quad, v29.m_quad, 201), forward.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(forward.m_quad, forward.m_quad, 201), v29.m_quad));
    v31 = _mm_shuffle_ps(v30, v30, 201);
    v32 = _mm_mul_ps(v31, v31);
    v33 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
            _mm_shuffle_ps(v32, v32, 170));
    v34 = _mm_rsqrt_ps(v33);
    right.m_quad = _mm_mul_ps(
                     v31,
                     _mm_andnot_ps(
                       _mm_cmple_ps(v33, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
                         _mm_mul_ps(v34, *(__m128 *)_xmm))));
    hkaiVelocityCandidateGenerator::init(&velocityCandidates, &forward, &right, &prev, &maxSpeed, &desiredSpeed);
    v35 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v36 = (_QWORD *)v35[1];
    if ( (unsigned __int64)v36 < v35[3] )
    {
      *v36 = "StscoreBoundaryObstacles";
      v37 = __rdtsc();
      v38 = v36 + 2;
      *((_DWORD *)v38 - 2) = v37;
      v35[1] = v38;
    }
    v39 = agent->m_avoidanceProperties;
    v40 = 0;
    v41 = 0;
    v42 = _mm_add_ps(
            _mm_shuffle_ps(
              (__m128)LODWORD(agent->m_localSteeringInput.m_distToLocalGoal),
              (__m128)LODWORD(agent->m_localSteeringInput.m_distToLocalGoal),
              0),
            _mm_shuffle_ps((__m128)LODWORD(agent->m_boundaryRadius), (__m128)LODWORD(agent->m_boundaryRadius), 0));
    thresholdDistanceSquared.m_real = _mm_mul_ps(v42, v42);
    for ( penetrationPenalty.m_real = _mm_shuffle_ps(
                                        (__m128)LODWORD(v39->m_penetrationPenalty),
                                        (__m128)LODWORD(v39->m_penetrationPenalty),
                                        0); v41 < agent->m_numBoundaryObstacles; v40 |= v43 )
      v43 = hkaiVelocityCandidateScoringUtil::scoreBoundaryObstacle(
              agent,
              &agent->m_boundaryObstacles[v41++],
              &up,
              &thresholdDistanceSquared,
              &penetrationPenalty,
              &velocityCandidates,
              &staticTtcsIn,
              &bonusesIn,
              (hkVector4f *)&penetrationPenalty);
    v44 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v45 = (_QWORD *)v44[1];
    if ( (unsigned __int64)v45 < v44[3] )
    {
      *v45 = "StscoreSphereObstacles";
      v46 = __rdtsc();
      v47 = v45 + 2;
      *((_DWORD *)v47 - 2) = v46;
      v44[1] = v47;
    }
    for ( i = 0; i < agent->m_numSphereObstacles; v40 |= v49 )
      v49 = hkaiVelocityCandidateScoringUtil::scoreSphereObstacle(
              agent,
              &agent->m_sphereObstacles[i++],
              &up,
              &penetrationPenalty,
              &velocityCandidates,
              &staticTtcsIn,
              &bonusesIn,
              (hkVector4f *)&penetrationPenalty);
    v50 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v51 = (_QWORD *)v50[1];
    if ( (unsigned __int64)v51 < v50[3] )
    {
      *v51 = "StscoreAgentObstacles";
      v52 = __rdtsc();
      v53 = v51 + 2;
      *((_DWORD *)v53 - 2) = v52;
      v50[1] = v53;
    }
    v54 = 0;
    for ( sidednessChangingPenalty.m_real = _mm_shuffle_ps(
                                              (__m128)LODWORD(agent->m_avoidanceProperties->m_sidednessChangingPenalty),
                                              (__m128)LODWORD(agent->m_avoidanceProperties->m_sidednessChangingPenalty),
                                              0); v54 < agent->m_numNearbyAgents; v40 |= v55 )
      v55 = hkaiVelocityCandidateScoringUtil::scoreAgentObstacle(
              agent,
              &agent->m_nearbyAgents[v54++],
              &up,
              &velocityCandidates,
              &sidednessChangingPenalty,
              &penetrationPenalty,
              &staticTtcsIn,
              &bonusesIn,
              (hkVector4f *)&penetrationPenalty);
    v56 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v57 = (_QWORD *)v56[1];
    v58 = v56;
    if ( (unsigned __int64)v57 < v56[3] )
    {
      *v57 = "StchooseBestCandidate";
      v59 = __rdtsc();
      v60 = v57 + 2;
      *((_DWORD *)v60 - 2) = v59;
      v58[1] = v60;
    }
    hkaiVelocityCandidateScoringUtil::chooseBestCandidate(
      &velocityCandidates,
      &staticTtcsIn,
      &dynamicTtcsIn,
      &bonusesIn,
      (hkVector4f *)&penetrationPenalty,
      0.0,
      agent->m_avoidanceProperties->m_wallFollowingAngle,
      agent->m_avoidanceProperties->m_collisionPenalty,
      desiredSpeed.m_real.m128_f32[0],
      agent->m_radius * 4.0,
      agent->m_avoidanceProperties->m_dodgingPenalty,
      &agent->m_localSteeringInput.m_localGoalPlane,
      &bestCandidate);
    LOBYTE(m_enum) = v40 != 0;
    v61 = bonusesIn.m_scores.m_flags >= 0;
    deltaVelocity->m_quad = _mm_sub_ps(bestCandidate.m_quad, agent->m_velocity.m_quad);
    if ( !v61 )
    {
      m_elements = bonusesIn.m_scores.m_elements;
      v63 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      hkMemoryRouter::alignedFree(v63[11], m_elements);
    }
    if ( dynamicTtcsIn.m_scores.m_flags < 0 )
    {
      v64 = dynamicTtcsIn.m_scores.m_elements;
      v65 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      hkMemoryRouter::alignedFree(v65[11], v64);
    }
    if ( staticTtcsIn.m_scores.m_flags < 0 )
    {
      v66 = staticTtcsIn.m_scores.m_elements;
      v67 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      hkMemoryRouter::alignedFree(v67[11], v66);
    }
  }
  v68 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v69 = (_QWORD *)v68[1];
  v70 = v68;
  result->m_enum = m_enum;
  if ( (unsigned __int64)v69 < v68[3] )
  {
    *v69 = "lt";
    v71 = __rdtsc();
    v72 = v69 + 2;
    *((_DWORD *)v72 - 2) = v71;
    v70[1] = v72;
  }
  return result;
}

// File Line: 246
// RVA: 0xC107F0
hkResult *__fastcall hkaiAvoidanceSolver::calculateDeltaVelocity(
        hkResult *result,
        hkaiAvoidanceSolver::WorldInfo *worldInfo,
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkaiAvoidanceSolver::ControlGradient *gradient,
        hkVector4f *deltaVelocity)
{
  __int128 v5; // xmm9
  hkVector4f v6; // xmm6
  hkaiAvoidanceProperties *m_avoidanceProperties; // rdx
  __m128 v12; // xmm5
  __m128 v13; // xmm11
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  hkVector4f v16; // xmm0
  hkaiMovementProperties *p_m_movementProperties; // rdx
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm4
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  hkSimdFloat32 v26; // xmm0
  hkVector4f v27; // xmm13
  hkVector4f v28; // xmm10
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm7
  __m128 v33; // xmm1
  __m128 v34; // xmm5
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  __m128 v38; // xmm0
  __m128 v39; // xmm5
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm1
  hkVector4f desiredVelocity; // [rsp+40h] [rbp-A8h] BYREF
  hkVector4f constrainedVelocity; // [rsp+50h] [rbp-98h] BYREF
  __int128 v46; // [rsp+A0h] [rbp-48h]

  v6.m_quad = (__m128)gradient->m_total;
  m_avoidanceProperties = agent->m_avoidanceProperties;
  v12 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_050000001), (__m128)LODWORD(FLOAT_0_050000001), 0);
  v13 = _mm_shuffle_ps(
          (__m128)LODWORD(m_avoidanceProperties->m_movementProperties.m_maxAcceleration),
          (__m128)LODWORD(m_avoidanceProperties->m_movementProperties.m_maxAcceleration),
          0);
  if ( _mm_shuffle_ps(v6.m_quad, v6.m_quad, 255).m128_f32[0] >= 0.00000011920929 )
  {
    p_m_movementProperties = &m_avoidanceProperties->m_movementProperties;
    v18 = _mm_mul_ps(v6.m_quad, v6.m_quad);
    v19 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
            _mm_shuffle_ps(v18, v18, 170));
    v20 = _mm_rsqrt_ps(v19);
    v21 = _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmple_ps(v19, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                _mm_mul_ps(*(__m128 *)_xmm, v20))),
            v6.m_quad);
    *deltaVelocity = (hkVector4f)v21;
    v22 = _mm_mul_ps(
            _mm_max_ps(
              v13,
              _mm_shuffle_ps(
                (__m128)LODWORD(p_m_movementProperties->m_maxDeceleration),
                (__m128)LODWORD(p_m_movementProperties->m_maxDeceleration),
                0)),
            worldInfo->m_timeStep.m_real);
    v23 = _mm_add_ps(_mm_shuffle_ps(gradient->m_total.m_quad, gradient->m_total.m_quad, 255), v12);
    v24 = _mm_cmplt_ps(v23, v22);
    v25 = _mm_mul_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v24, v23), _mm_andnot_ps(v24, v22)))),
            v21);
    *deltaVelocity = (hkVector4f)v25;
    v26.m_real = (__m128)worldInfo->m_timeStep;
    desiredVelocity.m_quad = _mm_add_ps(v25, agent->m_velocity.m_quad);
    hkaiAvoidanceSolverUtils::applyKinematicConstraints(
      v26.m_real.m128_f32[0],
      p_m_movementProperties,
      &worldInfo->m_up,
      &agent->m_velocity,
      &agent->m_forward,
      &desiredVelocity,
      &constrainedVelocity,
      0);
    v16.m_quad = _mm_sub_ps(constrainedVelocity.m_quad, agent->m_velocity.m_quad);
  }
  else
  {
    v14 = _mm_sub_ps(_mm_shuffle_ps(gradient->m_direction.m_quad, gradient->m_direction.m_quad, 255), v12);
    v15 = _mm_cmplt_ps(v14, query.m_quad);
    v16.m_quad = _mm_mul_ps(
                   _mm_max_ps(
                     _mm_sub_ps((__m128)0i64, v12),
                     _mm_or_ps(_mm_and_ps(v15, v14), _mm_andnot_ps(v15, query.m_quad))),
                   deltaVelocity->m_quad);
  }
  *deltaVelocity = (hkVector4f)v16.m_quad;
  v27.m_quad = (__m128)gradient->m_repulsion;
  if ( _mm_shuffle_ps(v27.m_quad, v27.m_quad, 255).m128_f32[0] > 0.00000011920929 )
  {
    v46 = v5;
    v28.m_quad = (__m128)agent->m_velocity;
    v29 = _mm_mul_ps(v28.m_quad, v28.m_quad);
    v30 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
            _mm_shuffle_ps(v29, v29, 170));
    v31 = _mm_rsqrt_ps(v30);
    v32 = _mm_andnot_ps(
            _mm_cmple_ps(v30, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                _mm_mul_ps(v31, *(__m128 *)_xmm)),
              v30));
    v33 = _mm_mul_ps(v27.m_quad, v27.m_quad);
    v34 = _mm_mul_ps(v32, (__m128)xmmword_141A711B0);
    v35 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
            _mm_shuffle_ps(v33, v33, 170));
    v36 = _mm_rsqrt_ps(v35);
    v37 = _mm_rcp_ps(v34);
    v38 = _mm_cmplt_ps((__m128)0i64, v32);
    v39 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_max_ps(
                  query.m_quad,
                  _mm_or_ps(
                    _mm_andnot_ps(v38, query.m_quad),
                    _mm_and_ps(
                      _mm_mul_ps(
                        _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v37, v34)), v37),
                        _mm_andnot_ps(
                          _mm_cmple_ps(v35, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v36, v35), v36)),
                              _mm_mul_ps(v36, *(__m128 *)_xmm)),
                            v35))),
                      v38))),
                v27.m_quad),
              v28.m_quad),
            deltaVelocity->m_quad);
    v40 = _mm_mul_ps(v39, v39);
    v41 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
            _mm_shuffle_ps(v40, v40, 170));
    v42 = _mm_rsqrt_ps(v41);
    deltaVelocity->m_quad = _mm_sub_ps(
                              _mm_mul_ps(
                                _mm_min_ps(
                                  query.m_quad,
                                  _mm_mul_ps(
                                    _mm_andnot_ps(
                                      _mm_cmple_ps(v41, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v42, v41), v42)),
                                        _mm_mul_ps(v42, *(__m128 *)_xmm))),
                                    _mm_add_ps(_mm_mul_ps(worldInfo->m_timeStep.m_real, v13), v32))),
                                v39),
                              v28.m_quad);
  }
  result->m_enum = gradient->m_failed;
  return result;
}

// File Line: 329
// RVA: 0xC0FE40
void __fastcall hkaiAvoidancePairProperties::addPair(
        hkaiAvoidancePairProperties *this,
        unsigned __int16 typeA,
        unsigned __int16 typeB,
        float weight)
{
  hkArray<hkaiAvoidancePairProperties::PairData,hkContainerHeapAllocator> *p_m_avoidancePairDataMap; // rbx
  int v5; // eax
  hkaiAvoidancePairProperties::PairData *v8; // rdx
  __int64 m_size; // rcx
  hkaiAvoidancePairProperties::PairData *m_data; // rdx
  __int64 v11; // r8
  __int64 v12; // rbp
  int v13; // r9d
  int v14; // eax
  hkaiAvoidancePairProperties::PairData *v15; // rdx
  hkaiAvoidancePairProperties::PairData *v16; // rdx
  hkaiAvoidancePairProperties::PairData *v17; // r8
  __int64 v18; // r9
  hkResult result; // [rsp+58h] [rbp+10h] BYREF

  p_m_avoidancePairDataMap = &this->m_avoidancePairDataMap;
  v5 = this->m_avoidancePairDataMap.m_capacityAndFlags & 0x3FFFFFFF;
  if ( typeA == typeB )
  {
    if ( this->m_avoidancePairDataMap.m_size == v5 )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_avoidancePairDataMap, 12);
    v8 = &p_m_avoidancePairDataMap->m_data[p_m_avoidancePairDataMap->m_size];
    if ( v8 )
    {
      v8->m_weight = 0.5;
      v8->m_cosViewAngle = -0.42160001;
      v8->m_key = 0;
    }
    m_size = p_m_avoidancePairDataMap->m_size;
    m_data = p_m_avoidancePairDataMap->m_data;
    v11 = m_size;
    p_m_avoidancePairDataMap->m_size = m_size + 1;
    m_data[v11].m_weight = weight;
    m_data[v11].m_key = typeA + (typeB << 16);
  }
  else
  {
    v12 = this->m_avoidancePairDataMap.m_size;
    v13 = v12 + 2;
    if ( v5 < (int)v12 + 2 )
    {
      v14 = 2 * v5;
      if ( v13 < v14 )
        v13 = v14;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_avoidancePairDataMap, v13, 12);
    }
    v15 = &p_m_avoidancePairDataMap->m_data[p_m_avoidancePairDataMap->m_size];
    if ( v15 )
    {
      v15->m_key = 0;
      v15->m_weight = 0.5;
      v15->m_cosViewAngle = -0.42160001;
    }
    v16 = v15 + 1;
    if ( v16 )
    {
      v16->m_key = 0;
      v16->m_weight = 0.5;
      v16->m_cosViewAngle = -0.42160001;
    }
    p_m_avoidancePairDataMap->m_size += 2;
    v17 = p_m_avoidancePairDataMap->m_data;
    v18 = v12;
    v17[v18].m_weight = weight;
    v17[v18 + 1].m_weight = 1.0 - weight;
    v17[v18].m_key = typeA + (typeB << 16);
    v17[v18 + 1].m_key = typeB + (typeA << 16);
  }
}

