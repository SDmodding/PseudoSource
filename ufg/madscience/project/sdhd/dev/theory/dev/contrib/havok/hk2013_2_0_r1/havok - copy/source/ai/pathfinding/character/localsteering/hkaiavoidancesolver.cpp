// File Line: 25
// RVA: 0xC0FFC0
void __fastcall hkaiAvoidanceSolver::SteeringAgent::validate(hkaiAvoidanceSolver::SteeringAgent *this)
{
  if ( this->m_localSteeringInput.m_enableLocalSteering.m_bool )
    JUMPOUT(this->m_localSteeringInput.m_referenceFrame, 0i64, hkaiReferenceFrame::validate);
}

// File Line: 55
// RVA: 0xC0FFF0
hkResult *__fastcall hkaiAvoidanceSolver::solveSingleAgent(hkResult *result, hkaiAvoidanceSolver::WorldInfo *worldInfo, hkaiAvoidanceSolver::SteeringAgent *agent, hkVector4f *deltaVelocity)
{
  hkResult *v4; // r15
  hkaiAvoidanceSolver::SteeringAgent *v5; // rdi
  hkVector4f *v6; // r12
  hkaiAvoidanceSolver::WorldInfo *v7; // rsi
  _QWORD *v8; // rax
  unsigned __int64 v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  hkaiAvoidanceProperties *v12; // rax
  __m128 v13; // xmm5
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  __m128 v20; // xmm9
  __m128 v21; // xmm0
  __m128 v22; // xmm5
  __m128 v23; // xmm9
  __m128 v24; // xmm3
  __m128 v25; // xmm4
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  hkResultEnum v28; // ebx
  __m128 v29; // xmm1
  __m128 v30; // xmm1
  __m128 v31; // xmm4
  __m128 v32; // xmm4
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  _QWORD *v36; // r8
  _QWORD *v37; // rcx
  unsigned __int64 v38; // rax
  signed __int64 v39; // rcx
  hkaiAvoidanceProperties *v40; // rax
  char v41; // si
  int v42; // er14
  __m128 v43; // xmm1
  bool v44; // al
  _QWORD *v45; // r8
  _QWORD *v46; // rcx
  unsigned __int64 v47; // rax
  signed __int64 v48; // rcx
  int i; // er14
  bool v50; // al
  _QWORD *v51; // r8
  _QWORD *v52; // rcx
  unsigned __int64 v53; // rax
  signed __int64 v54; // rcx
  int v55; // er14
  bool v56; // al
  _QWORD *v57; // rax
  _QWORD *v58; // rcx
  _QWORD *v59; // r8
  unsigned __int64 v60; // rax
  signed __int64 v61; // rcx
  bool v62; // zf
  hkVector4f *v63; // rdi
  hkMemoryAllocator **v64; // rax
  hkVector4f *v65; // rdi
  hkMemoryAllocator **v66; // rax
  hkVector4f *v67; // rdi
  hkMemoryAllocator **v68; // rax
  _QWORD *v69; // rax
  _QWORD *v70; // rcx
  _QWORD *v71; // r8
  unsigned __int64 v72; // rax
  signed __int64 v73; // rcx
  hkSimdFloat32 penetrationPenalty; // [rsp+70h] [rbp-80h]
  hkVector4f up; // [rsp+80h] [rbp-70h]
  hkSimdFloat32 initScore; // [rsp+90h] [rbp-60h]
  hkVector4f forward; // [rsp+A0h] [rbp-50h]
  hkSimdFloat32 desiredSpeed; // [rsp+B0h] [rbp-40h]
  hkVector4f prev; // [rsp+C0h] [rbp-30h]
  hkaiVelocityCandidateGenerator velocityCandidates; // [rsp+D0h] [rbp-20h]
  hkSimdFloat32 maxSpeed; // [rsp+130h] [rbp+40h]
  hkVector4f bestCandidate; // [rsp+140h] [rbp+50h]
  hkSimdFloat32 v84; // [rsp+150h] [rbp+60h]
  hkSimdFloat32 thresholdDistanceSquared; // [rsp+160h] [rbp+70h]
  hkVector4f right; // [rsp+170h] [rbp+80h]
  hkSimdFloat32 sidednessChangingPenalty; // [rsp+180h] [rbp+90h]
  hkaiVelocityCandidateScores bonusesIn; // [rsp+190h] [rbp+A0h]
  hkaiVelocityCandidateScores staticTtcsIn; // [rsp+3A0h] [rbp+2B0h]
  hkaiVelocityCandidateScores dynamicTtcsIn; // [rsp+5B0h] [rbp+4C0h]
  hkResult resulta; // [rsp+830h] [rbp+740h]

  v4 = result;
  v5 = agent;
  v6 = deltaVelocity;
  v7 = worldInfo;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = v8[1];
  v10 = v8;
  if ( v9 < v8[3] )
  {
    *(_QWORD *)v9 = "LtsolveSingleAgent";
    *(_QWORD *)(v9 + 16) = "Stinit";
    v11 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v11;
    v10[1] = v9 + 24;
  }
  v12 = v5->m_avoidanceProperties;
  if ( v12->m_avoidanceSolverType.m_storage )
  {
    velocityCandidates.m_firstBlockForward.m_quad.m128_i8[0] = 0;
    *(_OWORD *)&velocityCandidates.m_template = 0i64;
    velocityCandidates.m_forward = 0i64;
    velocityCandidates.m_right = 0i64;
    *((float *)&velocityCandidates.m_template + 3) = FLOAT_1_005;
    hkaiStaticObstacleSolver::solve(v7, v5, (hkaiAvoidanceSolver::ControlGradient *)&velocityCandidates);
    hkaiDynamicObstacleSolver::solve(v7, v5, v6, (hkaiAvoidanceSolver::ControlGradient *)&velocityCandidates);
    v28 = hkaiAvoidanceSolver::calculateDeltaVelocity(
            &resulta,
            v7,
            v5,
            (hkaiAvoidanceSolver::ControlGradient *)&velocityCandidates,
            v6)->m_enum;
  }
  else
  {
    v13 = _mm_add_ps(v5->m_velocity.m_quad, v6->m_quad);
    _mm_store_si128((__m128i *)&up, (__m128i)v7->m_up.m_quad);
    v14 = _mm_mul_ps(v13, v13);
    v15 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
            _mm_shuffle_ps(v14, v14, 170));
    v16 = _mm_rsqrt_ps(v15);
    resulta.m_enum = LODWORD(FLOAT_0_0000099999997);
    v17 = _mm_andnot_ps(
            _mm_cmpleps(v15, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
              _mm_mul_ps(*(__m128 *)_xmm, v16)));
    v18 = _mm_mul_ps(v17, v15);
    v19 = _mm_cmpltps(
            v18,
            _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0));
    v20 = v19;
    v21 = _mm_andnot_ps(v19, _mm_mul_ps(v13, v17));
    v22 = v5->m_velocity.m_quad;
    v23 = _mm_andnot_ps(v20, v18);
    forward.m_quad = v21;
    desiredSpeed.m_real = v23;
    v24 = _mm_mul_ps(v22, v22);
    v25 = _mm_shuffle_ps(
            (__m128)LODWORD(v12->m_movementProperties.m_maxVelocity),
            (__m128)LODWORD(v12->m_movementProperties.m_maxVelocity),
            0);
    prev.m_quad = v22;
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 170))) > (float)(v25.m128_f32[0] * v25.m128_f32[0]) )
    {
      v26 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
              _mm_shuffle_ps(v24, v24, 170));
      v27 = _mm_rsqrt_ps(v26);
      prev.m_quad = _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmpleps(v26, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                            _mm_mul_ps(*(__m128 *)_xmm, v27))),
                        v22),
                      v25);
    }
    staticTtcsIn.m_scores.m_elements = staticTtcsIn.m_scores.m_vecs;
    resulta.m_enum = LODWORD(FLOAT_1_8446726e19);
    staticTtcsIn.m_scores.m_vecs[31] = 0i64;
    dynamicTtcsIn.m_scores.m_vecs[31] = 0i64;
    bonusesIn.m_scores.m_vecs[31] = 0i64;
    dynamicTtcsIn.m_scores.m_elements = dynamicTtcsIn.m_scores.m_vecs;
    *(_QWORD *)&staticTtcsIn.m_scores.m_size = 128i64;
    initScore.m_real = _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_8446726e19), (__m128)LODWORD(FLOAT_1_8446726e19), 0);
    maxSpeed.m_real = _mm_min_ps(v25, _mm_mul_ps(v23, (__m128)xmmword_141A710D0));
    v28 = 0;
    *(_QWORD *)&dynamicTtcsIn.m_scores.m_size = 128i64;
    *(_QWORD *)&bonusesIn.m_scores.m_size = 128i64;
    bonusesIn.m_scores.m_elements = bonusesIn.m_scores.m_vecs;
    hkaiVelocityCandidateScores::setAll(&staticTtcsIn, &initScore);
    hkaiVelocityCandidateScores::setAll(&dynamicTtcsIn, &initScore);
    v84.m_real = aabbOut.m_quad;
    hkaiVelocityCandidateScores::setAll(&bonusesIn, &v84);
    v29 = (__m128)LODWORD(v5->m_avoidanceProperties->m_velocityHysteresis);
    *bonusesIn.m_scores.m_elements = (hkVector4f)_mm_unpacklo_ps(
                                                   _mm_unpacklo_ps(v29, v29),
                                                   _mm_unpacklo_ps(v29, (__m128)0i64));
    v30 = v7->m_up.m_quad;
    penetrationPenalty.m_real = 0i64;
    v31 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), forward.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(forward.m_quad, forward.m_quad, 201), v30));
    v32 = _mm_shuffle_ps(v31, v31, 201);
    v33 = _mm_mul_ps(v32, v32);
    v34 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
            _mm_shuffle_ps(v33, v33, 170));
    v35 = _mm_rsqrt_ps(v34);
    right.m_quad = _mm_mul_ps(
                     v32,
                     _mm_andnot_ps(
                       _mm_cmpleps(v34, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v35, v34), v35)),
                         _mm_mul_ps(v35, *(__m128 *)_xmm))));
    hkaiVelocityCandidateGenerator::init(&velocityCandidates, &forward, &right, &prev, &maxSpeed, &desiredSpeed);
    v36 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v37 = (_QWORD *)v36[1];
    if ( (unsigned __int64)v37 < v36[3] )
    {
      *v37 = "StscoreBoundaryObstacles";
      v38 = __rdtsc();
      v39 = (signed __int64)(v37 + 2);
      *(_DWORD *)(v39 - 8) = v38;
      v36[1] = v39;
    }
    v40 = v5->m_avoidanceProperties;
    v41 = 0;
    v42 = 0;
    v43 = _mm_add_ps(
            _mm_shuffle_ps(
              (__m128)LODWORD(v5->m_localSteeringInput.m_distToLocalGoal),
              (__m128)LODWORD(v5->m_localSteeringInput.m_distToLocalGoal),
              0),
            _mm_shuffle_ps((__m128)LODWORD(v5->m_boundaryRadius), (__m128)LODWORD(v5->m_boundaryRadius), 0));
    thresholdDistanceSquared.m_real = _mm_mul_ps(v43, v43);
    for ( penetrationPenalty.m_real = _mm_shuffle_ps(
                                        (__m128)LODWORD(v40->m_penetrationPenalty),
                                        (__m128)LODWORD(v40->m_penetrationPenalty),
                                        0); v42 < v5->m_numBoundaryObstacles; v41 |= v44 )
      v44 = hkaiVelocityCandidateScoringUtil::scoreBoundaryObstacle(
              v5,
              &v5->m_boundaryObstacles[v42++],
              &up,
              &thresholdDistanceSquared,
              &penetrationPenalty,
              &velocityCandidates,
              &staticTtcsIn,
              &bonusesIn,
              (hkVector4f *)&penetrationPenalty);
    v45 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v46 = (_QWORD *)v45[1];
    if ( (unsigned __int64)v46 < v45[3] )
    {
      *v46 = "StscoreSphereObstacles";
      v47 = __rdtsc();
      v48 = (signed __int64)(v46 + 2);
      *(_DWORD *)(v48 - 8) = v47;
      v45[1] = v48;
    }
    for ( i = 0; i < v5->m_numSphereObstacles; v41 |= v50 )
      v50 = hkaiVelocityCandidateScoringUtil::scoreSphereObstacle(
              v5,
              &v5->m_sphereObstacles[i++],
              &up,
              &penetrationPenalty,
              &velocityCandidates,
              &staticTtcsIn,
              &bonusesIn,
              (hkVector4f *)&penetrationPenalty);
    v51 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v52 = (_QWORD *)v51[1];
    if ( (unsigned __int64)v52 < v51[3] )
    {
      *v52 = "StscoreAgentObstacles";
      v53 = __rdtsc();
      v54 = (signed __int64)(v52 + 2);
      *(_DWORD *)(v54 - 8) = v53;
      v51[1] = v54;
    }
    v55 = 0;
    for ( sidednessChangingPenalty.m_real = _mm_shuffle_ps(
                                              (__m128)LODWORD(v5->m_avoidanceProperties->m_sidednessChangingPenalty),
                                              (__m128)LODWORD(v5->m_avoidanceProperties->m_sidednessChangingPenalty),
                                              0); v55 < v5->m_numNearbyAgents; v41 |= v56 )
      v56 = hkaiVelocityCandidateScoringUtil::scoreAgentObstacle(
              v5,
              &v5->m_nearbyAgents[v55++],
              &up,
              &velocityCandidates,
              &sidednessChangingPenalty,
              &penetrationPenalty,
              &staticTtcsIn,
              &bonusesIn,
              (hkVector4f *)&penetrationPenalty);
    v57 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v58 = (_QWORD *)v57[1];
    v59 = v57;
    if ( (unsigned __int64)v58 < v57[3] )
    {
      *v58 = "StchooseBestCandidate";
      v60 = __rdtsc();
      v61 = (signed __int64)(v58 + 2);
      *(_DWORD *)(v61 - 8) = v60;
      v59[1] = v61;
    }
    hkaiVelocityCandidateScoringUtil::chooseBestCandidate(
      &velocityCandidates,
      &staticTtcsIn,
      &dynamicTtcsIn,
      &bonusesIn,
      (hkVector4f *)&penetrationPenalty,
      0.0,
      v5->m_avoidanceProperties->m_wallFollowingAngle,
      v5->m_avoidanceProperties->m_collisionPenalty,
      desiredSpeed.m_real.m128_f32[0],
      v5->m_radius * 4.0,
      v5->m_avoidanceProperties->m_dodgingPenalty,
      &v5->m_localSteeringInput.m_localGoalPlane,
      &bestCandidate);
    LOBYTE(v28) = v41 != 0;
    v62 = bonusesIn.m_scores.m_flags >= 0;
    v6->m_quad = _mm_sub_ps(bestCandidate.m_quad, v5->m_velocity.m_quad);
    if ( !v62 )
    {
      v63 = bonusesIn.m_scores.m_elements;
      v64 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      hkMemoryRouter::alignedFree(v64[11], v63);
    }
    if ( dynamicTtcsIn.m_scores.m_flags < 0 )
    {
      v65 = dynamicTtcsIn.m_scores.m_elements;
      v66 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      hkMemoryRouter::alignedFree(v66[11], v65);
    }
    if ( staticTtcsIn.m_scores.m_flags < 0 )
    {
      v67 = staticTtcsIn.m_scores.m_elements;
      v68 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      hkMemoryRouter::alignedFree(v68[11], v67);
    }
  }
  v69 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v70 = (_QWORD *)v69[1];
  v71 = v69;
  v4->m_enum = v28;
  if ( (unsigned __int64)v70 < v69[3] )
  {
    *v70 = "lt";
    v72 = __rdtsc();
    v73 = (signed __int64)(v70 + 2);
    *(_DWORD *)(v73 - 8) = v72;
    v71[1] = v73;
  }
  return v4;
}

// File Line: 246
// RVA: 0xC107F0
hkResult *__usercall hkaiAvoidanceSolver::calculateDeltaVelocity@<rax>(hkResult *result@<rcx>, hkaiAvoidanceSolver::WorldInfo *worldInfo@<rdx>, hkaiAvoidanceSolver::SteeringAgent *agent@<r8>, hkaiAvoidanceSolver::ControlGradient *gradient@<r9>, __int128 a5@<xmm9>, __m128 *a6@<xmm14>, hkVector4f *deltaVelocity)
{
  hkVector4f v7; // xmm6
  hkaiAvoidanceSolver::WorldInfo *v8; // r15
  hkaiAvoidanceProperties *v9; // rdx
  hkaiAvoidanceSolver::ControlGradient *v10; // rdi
  hkaiAvoidanceSolver::SteeringAgent *v11; // rbp
  hkResult *v12; // r14
  __m128 v13; // xmm5
  __m128 v14; // xmm11
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  hkVector4f v17; // xmm0
  signed __int64 v18; // rdx
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  hkVector4f v22; // xmm4
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  __m128 v25; // xmm0
  hkVector4f v26; // xmm2
  hkSimdFloat32 v27; // xmm0
  __m128 v28; // xmm13
  __m128 v29; // xmm10
  __m128 v30; // xmm1
  __m128 v31; // xmm3
  __m128 v32; // xmm2
  __m128 v33; // xmm7
  __m128 v34; // xmm1
  __m128 v35; // xmm5
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  __m128 v39; // xmm0
  __m128 v40; // xmm5
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  hkVector4f desiredVelocity; // [rsp+40h] [rbp-A8h]
  hkVector4f constrainedVelocity; // [rsp+50h] [rbp-98h]
  __int128 v47; // [rsp+A0h] [rbp-48h]

  v7.m_quad = (__m128)gradient->m_total;
  v8 = worldInfo;
  v9 = agent->m_avoidanceProperties;
  v10 = gradient;
  v11 = agent;
  v12 = result;
  v13 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_050000001), (__m128)LODWORD(FLOAT_0_050000001), 0);
  v14 = _mm_shuffle_ps(
          (__m128)LODWORD(v9->m_movementProperties.m_maxAcceleration),
          (__m128)LODWORD(v9->m_movementProperties.m_maxAcceleration),
          0);
  if ( COERCE_FLOAT(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 255)) >= 0.00000011920929 )
  {
    v18 = (signed __int64)&v9->m_movementProperties;
    v19 = _mm_mul_ps(v7.m_quad, v7.m_quad);
    v20 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
            _mm_shuffle_ps(v19, v19, 170));
    v21 = _mm_rsqrt_ps(v20);
    v22.m_quad = _mm_mul_ps(
                   _mm_andnot_ps(
                     _mm_cmpleps(v20, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                       _mm_mul_ps(*(__m128 *)_xmm, v21))),
                   v7.m_quad);
    *deltaVelocity = (hkVector4f)v22.m_quad;
    v23 = _mm_mul_ps(
            _mm_max_ps(v14, _mm_shuffle_ps((__m128)*(unsigned int *)(v18 + 12), (__m128)*(unsigned int *)(v18 + 12), 0)),
            v8->m_timeStep.m_real);
    v24 = _mm_add_ps(_mm_shuffle_ps(gradient->m_total.m_quad, gradient->m_total.m_quad, 255), v13);
    v25 = _mm_cmpltps(v24, v23);
    v26.m_quad = _mm_mul_ps(
                   _mm_sub_ps(
                     (__m128)0i64,
                     _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v25, v24), _mm_andnot_ps(v25, v23)))),
                   v22.m_quad);
    *deltaVelocity = (hkVector4f)v26.m_quad;
    v27.m_real = (__m128)v8->m_timeStep;
    desiredVelocity.m_quad = _mm_add_ps(v26.m_quad, agent->m_velocity.m_quad);
    hkaiAvoidanceSolverUtils::applyKinematicConstraints(
      v27.m_real.m128_f32[0],
      (hkaiMovementProperties *)v18,
      &v8->m_up,
      &agent->m_velocity,
      a6,
      &agent->m_forward,
      &desiredVelocity,
      &constrainedVelocity,
      0);
    v17.m_quad = _mm_sub_ps(constrainedVelocity.m_quad, v11->m_velocity.m_quad);
  }
  else
  {
    v15 = _mm_sub_ps(_mm_shuffle_ps(gradient->m_direction.m_quad, gradient->m_direction.m_quad, 255), v13);
    v16 = _mm_cmpltps(v15, query.m_quad);
    v17.m_quad = _mm_mul_ps(
                   _mm_max_ps(
                     _mm_sub_ps((__m128)0i64, v13),
                     _mm_or_ps(_mm_and_ps(v16, v15), _mm_andnot_ps(v16, query.m_quad))),
                   deltaVelocity->m_quad);
  }
  *deltaVelocity = (hkVector4f)v17.m_quad;
  v28 = v10->m_repulsion.m_quad;
  if ( COERCE_FLOAT(_mm_shuffle_ps(v28, v28, 255)) > 0.00000011920929 )
  {
    v47 = a5;
    v29 = v11->m_velocity.m_quad;
    v30 = _mm_mul_ps(v29, v29);
    v31 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
            _mm_shuffle_ps(v30, v30, 170));
    v32 = _mm_rsqrt_ps(v31);
    v33 = _mm_andnot_ps(
            _mm_cmpleps(v31, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)),
                _mm_mul_ps(v32, *(__m128 *)_xmm)),
              v31));
    v34 = _mm_mul_ps(v28, v28);
    v35 = _mm_mul_ps(v33, (__m128)xmmword_141A711B0);
    v36 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
            _mm_shuffle_ps(v34, v34, 170));
    v37 = _mm_rsqrt_ps(v36);
    v38 = _mm_rcp_ps(v35);
    v39 = _mm_cmpltps((__m128)0i64, v33);
    v40 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_max_ps(
                  query.m_quad,
                  _mm_or_ps(
                    _mm_andnot_ps(v39, query.m_quad),
                    _mm_and_ps(
                      _mm_mul_ps(
                        _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v38, v35)), v38),
                        _mm_andnot_ps(
                          _mm_cmpleps(v36, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v37, v36), v37)),
                              _mm_mul_ps(v37, *(__m128 *)_xmm)),
                            v36))),
                      v39))),
                v28),
              v29),
            deltaVelocity->m_quad);
    v41 = _mm_mul_ps(v40, v40);
    v42 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
            _mm_shuffle_ps(v41, v41, 170));
    v43 = _mm_rsqrt_ps(v42);
    deltaVelocity->m_quad = _mm_sub_ps(
                              _mm_mul_ps(
                                _mm_min_ps(
                                  query.m_quad,
                                  _mm_mul_ps(
                                    _mm_andnot_ps(
                                      _mm_cmpleps(v42, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v43, v42), v43)),
                                        _mm_mul_ps(v43, *(__m128 *)_xmm))),
                                    _mm_add_ps(_mm_mul_ps(v8->m_timeStep.m_real, v14), v33))),
                                v40),
                              v29);
  }
  v12->m_enum = v10->m_failed != 0;
  return v12;
}

// File Line: 329
// RVA: 0xC0FE40
void __fastcall hkaiAvoidancePairProperties::addPair(hkaiAvoidancePairProperties *this, unsigned __int16 typeA, unsigned __int16 typeB, float weight)
{
  signed int *v4; // rbx
  int v5; // eax
  unsigned __int16 v6; // di
  unsigned __int16 v7; // si
  _DWORD *v8; // rdx
  __int64 v9; // rcx
  __int64 v10; // rdx
  signed __int64 v11; // r8
  __int64 v12; // rbp
  int v13; // er9
  int v14; // eax
  _DWORD *v15; // rdx
  _DWORD *v16; // rdx
  __int64 v17; // r8
  signed __int64 v18; // r9
  hkResult result; // [rsp+58h] [rbp+10h]

  v4 = (signed int *)&this->m_avoidancePairDataMap;
  v5 = this->m_avoidancePairDataMap.m_capacityAndFlags & 0x3FFFFFFF;
  v6 = typeB;
  v7 = typeA;
  if ( typeA == typeB )
  {
    if ( this->m_avoidancePairDataMap.m_size == v5 )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 12);
    v8 = (_DWORD *)(*(_QWORD *)v4 + 12i64 * v4[2]);
    if ( v8 )
    {
      v8[1] = 1056964608;
      v8[2] = -1093149707;
      *v8 = 0;
    }
    v9 = v4[2];
    v10 = *(_QWORD *)v4;
    v11 = 3 * v9;
    v4[2] = v9 + 1;
    *(float *)(v10 + 4 * v11 + 4) = weight;
    *(_DWORD *)(v10 + 4 * v11) = v7 + (v6 << 16);
  }
  else
  {
    v12 = this->m_avoidancePairDataMap.m_size;
    v13 = v12 + 2;
    if ( v5 < (signed int)v12 + 2 )
    {
      v14 = 2 * v5;
      if ( v13 < v14 )
        v13 = v14;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v13, 12);
    }
    v15 = (_DWORD *)(*(_QWORD *)v4 + 12i64 * v4[2]);
    if ( v15 )
    {
      *v15 = 0;
      v15[1] = 1056964608;
      v15[2] = -1093149707;
    }
    v16 = v15 + 3;
    if ( v16 )
    {
      *v16 = 0;
      v16[1] = 1056964608;
      v16[2] = -1093149707;
    }
    v4[2] += 2;
    v17 = *(_QWORD *)v4;
    v18 = 3 * v12;
    *(float *)(v17 + 4 * v18 + 4) = weight;
    *(float *)(v17 + 4 * v18 + 16) = 1.0 - weight;
    *(_DWORD *)(v17 + 4 * v18) = v7 + (v6 << 16);
    *(_DWORD *)(v17 + 4 * v18 + 12) = v6 + (v7 << 16);
  }
}

