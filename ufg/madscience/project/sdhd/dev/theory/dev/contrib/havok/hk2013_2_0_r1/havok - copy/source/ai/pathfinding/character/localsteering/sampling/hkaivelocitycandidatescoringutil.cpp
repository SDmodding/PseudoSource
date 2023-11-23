// File Line: 25
// RVA: 0x15C40B0
void dynamic_initializer_for__HKAI_LOCAL_STEERING_MIN_TTC__()
{
  HKAI_LOCAL_STEERING_MIN_TTC.m_real = (__m128)xmmword_141A71230;
}

// File Line: 36
// RVA: 0xC2A670
bool __fastcall hkaiVelocityCandidateScoringUtil::scoreSphereObstacle(
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkaiAvoidanceSolver::SphereObstacle *sphereObstacle,
        hkVector4f *up,
        hkSimdFloat32 *penetrationPenalty,
        hkaiVelocityCandidateGenerator *velocityCandidates,
        hkaiVelocityCandidateScores *timesToCollision,
        hkaiVelocityCandidateScores *bonuses,
        hkVector4f *bonusVector)
{
  __m128 m_quad; // xmm5
  hkSphere v9; // xmm4
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  hkVector4f v13; // xmm3
  __m128 v14; // xmm4
  __m128 v15; // xmm1
  hkVector4f v17; // [rsp+40h] [rbp-38h] BYREF
  hkSphere v18; // [rsp+50h] [rbp-28h] BYREF
  hkVector4f v19; // [rsp+60h] [rbp-18h] BYREF

  m_quad = up->m_quad;
  v9.m_pos.m_quad = (__m128)sphereObstacle->m_sphere;
  v10 = _mm_mul_ps(up->m_quad, agent->m_position.m_quad);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_mul_ps(up->m_quad, sphereObstacle->m_sphere.m_pos.m_quad);
  v19.m_quad = _mm_sub_ps(agent->m_position.m_quad, _mm_mul_ps(v11, up->m_quad));
  v13.m_quad = (__m128)sphereObstacle->m_velocity;
  v14 = _mm_sub_ps(
          v9.m_pos.m_quad,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
              _mm_shuffle_ps(v12, v12, 170)),
            m_quad));
  v15 = _mm_mul_ps(m_quad, v13.m_quad);
  v18.m_pos.m_quad = _mm_shuffle_ps(
                       v14,
                       _mm_unpackhi_ps(
                         v14,
                         _mm_add_ps(
                           _mm_shuffle_ps(
                             sphereObstacle->m_sphere.m_pos.m_quad,
                             sphereObstacle->m_sphere.m_pos.m_quad,
                             255),
                           _mm_shuffle_ps((__m128)LODWORD(agent->m_radius), (__m128)LODWORD(agent->m_radius), 0))),
                       196);
  v17.m_quad = _mm_sub_ps(
                 v13.m_quad,
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                     _mm_shuffle_ps(v15, v15, 170)),
                   m_quad));
  return hkaiVelocityCandidateScoringUtil::scoreMovingSphere(
           &v19,
           &v18,
           &v17,
           penetrationPenalty,
           velocityCandidates,
           timesToCollision,
           bonuses,
           bonusVector);
}

// File Line: 71
// RVA: 0xC2A770
bool __fastcall hkaiVelocityCandidateScoringUtil::scoreAgentObstacle(
        hkaiAvoidanceSolver::SteeringAgent *thisAgent,
        hkaiAvoidanceSolver::ObstacleAgent *otherAgent,
        hkVector4f *up,
        hkaiVelocityCandidateGenerator *velocityCandidatesIn,
        hkSimdFloat32 *sidednessChangingPenalty,
        hkSimdFloat32 *penetrationPenalty,
        hkaiVelocityCandidateScores *timesToCollision,
        hkaiVelocityCandidateScores *bonuses,
        hkVector4f *bonusVector)
{
  __m128 m_quad; // xmm3
  int v12; // r9d
  hkVector4f v13; // xmm8
  __m128 v14; // xmm7
  __m128 v15; // xmm1
  hkVector4f v16; // xmm12
  __m128 v17; // xmm7
  __m128 v18; // xmm5
  __m128 v19; // xmm1
  __m128 v20; // xmm13
  __m128 v21; // xmm2
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  __m128 v26; // xmm12
  __m128 v27; // xmm8
  __m128 v28; // xmm11
  __m128 v29; // xmm1
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  __m128 v32; // xmm6
  __m128 v33; // xmm3
  __m128 v34; // xmm1
  __m128 v35; // xmm4
  __m128 v36; // xmm0
  hkSimdFloat32 v37; // xmm6
  hkVector4f v38; // xmm9
  hkVector4f v39; // xmm14
  hkVector4f v40; // xmm15
  __m128 v41; // xmm12
  hkVector4f v42; // xmm8
  __m128 v43; // xmm2
  __m128 v44; // xmm3
  __m128 v45; // xmm1
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm1
  __m128 v49; // xmm3
  __m128 v50; // xmm4
  __m128 v51; // xmm1
  __m128 v52; // xmm2
  __m128 v53; // xmm1
  __m128 v54; // xmm2
  __m128 v55; // xmm4
  __m128 v56; // xmm3
  __m128 v57; // xmm1
  __m128 v58; // xmm1
  __m128 v59; // xmm2
  __m128 v60; // xmm1
  __m128 v61; // xmm2
  __m128 v62; // xmm2
  __m128 v63; // xmm1
  hkVector4f *m_elements; // rcx
  __m128 v65; // xmm3
  __m128 v66; // xmm2
  __m128 v67; // xmm3
  __m128 v68; // xmm1
  __m128 v69; // xmm4
  __m128 v70; // xmm1
  __m128 v71; // xmm2
  __m128 v72; // xmm9
  __m128 v73; // xmm8
  __m128 v74; // xmm0
  __m128 v75; // xmm14
  __m128 v76; // xmm1
  __m128 v77; // xmm15
  __m128 v78; // xmm6
  __m128 v79; // xmm7
  __m128 v80; // xmm8
  __m128 v81; // xmm1
  __m128 v82; // xmm2
  __m128 v83; // xmm9
  __m128 v84; // xmm2
  __m128 v85; // xmm9
  __m128 v86; // xmm1
  __m128 v87; // xmm4
  __m128 v88; // xmm1
  __m128 v89; // xmm3
  __m128 v90; // xmm1
  __m128 v91; // xmm2
  __int64 v92; // rax
  __m128 v93; // xmm12
  __int64 v94; // rdx
  __m128 v95; // xmm0
  __m128 v96; // xmm9
  __m128 v97; // xmm7
  __m128 v98; // xmm5
  __m128i v99; // xmm2
  __m128i v100; // xmm1
  __m128i v101; // xmm2
  __m128 v102; // xmm5
  __m128 v103; // xmm8
  __m128 v104; // xmm1
  __m128 v105; // xmm0
  __m128 v106; // xmm7
  __m128 v107; // xmm1
  __m128 v108; // xmm0
  __m128 v109; // xmm0
  const __m128i *v110; // rdx
  char *v111; // r8
  __int64 v112; // rax
  __m128 v113; // xmm1
  __m128 v114; // xmm6
  __m128i v115; // xmm5
  __m128 v116; // xmm9
  __m128 v117; // xmm6
  __m128i v118; // xmm1
  __m128i v119; // xmm2
  __m128 v120; // xmm3
  __m128i v121; // xmm0
  __m128 v122; // xmm9
  __m128 v123; // xmm6
  __m128 v124; // xmm1
  __m128 v125; // xmm2
  __m128 v126; // xmm6
  __m128 v127; // xmm0
  __m128 v128; // xmm0
  __m128 v129; // [rsp+0h] [rbp-1B8h]
  __m128 v130; // [rsp+0h] [rbp-1B8h]
  __m128 v131; // [rsp+10h] [rbp-1A8h]
  __m128 v132; // [rsp+10h] [rbp-1A8h]
  __m128 v133; // [rsp+10h] [rbp-1A8h]
  __m128 v134; // [rsp+20h] [rbp-198h]
  __m128 v135; // [rsp+20h] [rbp-198h]
  __m128 v136; // [rsp+20h] [rbp-198h]
  __m128 v137; // [rsp+30h] [rbp-188h]
  __m128 v138; // [rsp+30h] [rbp-188h]
  __m128 v139; // [rsp+30h] [rbp-188h]
  __m128 m_real; // [rsp+40h] [rbp-178h]
  __m128 v141; // [rsp+40h] [rbp-178h]
  __m128 v142; // [rsp+50h] [rbp-168h]
  __m128 v143; // [rsp+50h] [rbp-168h]
  __m128 v144; // [rsp+60h] [rbp-158h]
  __m128 v145; // [rsp+60h] [rbp-158h]
  __m128 v146; // [rsp+70h] [rbp-148h]
  __m128 v147; // [rsp+70h] [rbp-148h]
  __m128 v148; // [rsp+80h] [rbp-138h]
  __m128 v149; // [rsp+80h] [rbp-138h]
  __m128 v150; // [rsp+90h] [rbp-128h]
  __m128 v151; // [rsp+A0h] [rbp-118h]
  __int128 v152; // [rsp+B0h] [rbp-108h]

  if ( otherAgent->m_weight == 0.0 )
    return 0;
  m_quad = up->m_quad;
  v12 = 0;
  v13.m_quad = (__m128)otherAgent->m_velocity;
  v14 = _mm_sub_ps(thisAgent->m_position.m_quad, otherAgent->m_position.m_quad);
  v15 = _mm_mul_ps(up->m_quad, v14);
  v16.m_quad = (__m128)thisAgent->m_velocity;
  v17 = _mm_sub_ps(
          v14,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
              _mm_shuffle_ps(v15, v15, 170)),
            up->m_quad));
  v18 = _mm_mul_ps(v17, v17);
  v144 = v17;
  v137 = _mm_add_ps(
           _mm_shuffle_ps((__m128)LODWORD(thisAgent->m_radius), (__m128)LODWORD(thisAgent->m_radius), 0),
           _mm_shuffle_ps((__m128)LODWORD(otherAgent->m_radius), (__m128)LODWORD(otherAgent->m_radius), 0));
  v19 = _mm_mul_ps(v16.m_quad, up->m_quad);
  v20 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
            _mm_shuffle_ps(v18, v18, 170)),
          _mm_mul_ps(v137, v137));
  v21 = _mm_shuffle_ps(v19, v19, 85);
  v22 = _mm_shuffle_ps(v19, v19, 0);
  v23 = _mm_shuffle_ps(v19, v19, 170);
  if ( v20.m128_f32[0] <= 0.0 )
    v12 = 1;
  v24 = _mm_add_ps(_mm_add_ps(v21, v22), v23);
  v25 = _mm_mul_ps(v13.m_quad, m_quad);
  v26 = _mm_sub_ps(v16.m_quad, _mm_mul_ps(v24, m_quad));
  v27 = _mm_sub_ps(
          v13.m_quad,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
              _mm_shuffle_ps(v25, v25, 170)),
            m_quad));
  v129 = _mm_sub_ps(v26, v27);
  if ( thisAgent->m_priority >= otherAgent->m_priority )
  {
    v30 = _mm_mul_ps(v26, v26);
    v31 = _mm_shuffle_ps((__m128)LODWORD(otherAgent->m_weight), (__m128)LODWORD(otherAgent->m_weight), 0);
    v32 = _mm_sub_ps(query.m_quad, v31);
    v33 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
            _mm_shuffle_ps(v30, v30, 170));
    v34 = _mm_mul_ps(v27, v27);
    v35 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
            _mm_shuffle_ps(v34, v34, 170));
    if ( v33.m128_f32[0] > v35.m128_f32[0] )
    {
      v32 = _mm_mul_ps(v32, _mm_andnot_ps(_mm_cmple_ps(v35, (__m128)0i64), _mm_mul_ps(_mm_rsqrt_ps(v35), v35)));
      v31 = _mm_mul_ps(v31, _mm_andnot_ps(_mm_cmple_ps(v33, (__m128)0i64), _mm_mul_ps(_mm_rsqrt_ps(v33), v33)));
    }
    if ( v31.m128_f32[0] == 0.0 )
      return 0;
    v36 = _mm_rcp_ps(v31);
    v28 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v31, v36)), v36), _mm_add_ps(v31, v32));
    v29 = _mm_rcp_ps(v28);
  }
  else
  {
    v28 = query.m_quad;
    v29 = 0i64;
  }
  v37.m_real = (__m128)velocityCandidatesIn->m_maxSpeed;
  v131 = v29;
  v38.m_quad = (__m128)velocityCandidatesIn->m_firstBlockRight;
  v39.m_quad = (__m128)velocityCandidatesIn->m_forward;
  v40.m_quad = (__m128)velocityCandidatesIn->m_right;
  m_real = v37.m_real;
  v41 = _mm_sub_ps(_mm_sub_ps(v26, _mm_mul_ps(v28, v26)), v27);
  v42.m_quad = (__m128)velocityCandidatesIn->m_firstBlockForward;
  v43 = _mm_mul_ps(v40.m_quad, v41);
  v152 = *(_OWORD *)&velocityCandidatesIn->m_template;
  v44 = _mm_mul_ps(_mm_andnot_ps(_mm_cmpeq_ps(v37.m_real, (__m128)0i64), _mm_rcp_ps(v37.m_real)), v29);
  v45 = _mm_mul_ps(v39.m_quad, v41);
  v142 = _mm_mul_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
             _mm_shuffle_ps(v45, v45, 170)),
           v44);
  v46 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
            _mm_shuffle_ps(v43, v43, 170)),
          v44);
  v47 = _mm_mul_ps(v40.m_quad, v17);
  v146 = v46;
  v48 = _mm_mul_ps(v39.m_quad, v17);
  v49 = _mm_mul_ps(v37.m_real, v28);
  v148 = _mm_mul_ps(v49, v49);
  v151 = _mm_mul_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v48, v48, 0), _mm_shuffle_ps(v48, v48, 85)),
             _mm_shuffle_ps(v48, v48, 170)),
           v49);
  v50 = _mm_mul_ps(v129, v129);
  v150 = _mm_mul_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
             _mm_shuffle_ps(v47, v47, 170)),
           v49);
  v51 = _mm_mul_ps(v129, v17);
  v52 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)), _mm_shuffle_ps(v51, v51, 170));
  v134 = _mm_andnot_ps(
           _mm_cmpeq_ps(v52, (__m128)0i64),
           _mm_mul_ps(
             _mm_rcp_ps(v52),
             _mm_mul_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
                 _mm_shuffle_ps(v50, v50, 170)),
               sidednessChangingPenalty->m_real)));
  v53 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)), _mm_shuffle_ps(v50, v50, 170));
  v54 = _mm_rsqrt_ps(v53);
  v55 = _mm_shuffle_ps(up->m_quad, up->m_quad, 201);
  v56 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v53, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v54, v53), v54)),
              _mm_mul_ps(v54, *(__m128 *)_xmm))),
          v129);
  v57 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), up->m_quad), _mm_mul_ps(v56, v55));
  v58 = _mm_mul_ps(_mm_shuffle_ps(v57, v57, 201), v17);
  v59 = _mm_max_ps(
          (__m128)_mm_srli_epi32(
                    _mm_slli_epi32(
                      (__m128i)_mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v58, v58, 85), _mm_shuffle_ps(v58, v58, 0)),
                                 _mm_shuffle_ps(v58, v58, 170)),
                      1u),
                    1u),
          v137);
  v60 = _mm_rcp_ps(v59);
  v135 = _mm_mul_ps(_mm_mul_ps(v134, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v59, v60)), v60)), v137);
  v61 = _mm_sub_ps(_mm_mul_ps(v17, v55), _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), up->m_quad));
  v62 = _mm_shuffle_ps(v61, v61, 201);
  v63 = _mm_mul_ps(v62, v129);
  m_elements = timesToCollision->m_scores.m_elements;
  v65 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(
                    _mm_srli_epi32(
                      (__m128i)_mm_cmplt_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(_mm_shuffle_ps(v63, v63, 85), _mm_shuffle_ps(v63, v63, 0)),
                                   _mm_shuffle_ps(v63, v63, 170)),
                                 (__m128)0i64),
                      0x1Fu),
                    0x1Fu),
          v62);
  v66 = _mm_mul_ps(v37.m_real, v65);
  v67 = _mm_mul_ps(v65, v41);
  v68 = _mm_mul_ps(v39.m_quad, v66);
  v69 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)), _mm_shuffle_ps(v68, v68, 170));
  v70 = _mm_mul_ps(v40.m_quad, v66);
  v138 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v70, v70, 85), _mm_shuffle_ps(v70, v70, 0)),
           _mm_shuffle_ps(v70, v70, 170));
  v71 = _mm_cmple_ps((__m128)0i64, v135);
  v132 = _mm_or_ps(
           _mm_andnot_ps(
             v71,
             _mm_mul_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v67, v67, 85), _mm_shuffle_ps(v67, v67, 0)),
                 _mm_shuffle_ps(v67, v67, 170)),
               _mm_sub_ps((__m128)0i64, v131))),
           _mm_and_ps((__m128)xmmword_141A712F0, v71));
  if ( v12 )
  {
    v72 = _mm_mul_ps(v38.m_quad, v37.m_real);
    v73 = _mm_mul_ps(v42.m_quad, v37.m_real);
    v139 = _mm_shuffle_ps(v39.m_quad, v39.m_quad, 0);
    v130 = _mm_shuffle_ps(v40.m_quad, v40.m_quad, 0);
    v74 = _mm_shuffle_ps(v39.m_quad, v39.m_quad, 85);
    v75 = _mm_shuffle_ps(v39.m_quad, v39.m_quad, 170);
    v133 = v74;
    v76 = _mm_shuffle_ps(v40.m_quad, v40.m_quad, 85);
    v77 = _mm_shuffle_ps(v40.m_quad, v40.m_quad, 170);
    v78 = _mm_add_ps(_mm_mul_ps(v73, v139), _mm_mul_ps(v72, v130));
    v136 = v76;
    v79 = _mm_add_ps(_mm_mul_ps(v73, v74), _mm_mul_ps(v72, v76));
    v80 = _mm_add_ps(_mm_mul_ps(v73, v75), _mm_mul_ps(v72, v77));
    v81 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
            _mm_shuffle_ps(v18, v18, 170));
    v82 = _mm_rsqrt_ps(v81);
    v83 = _mm_andnot_ps(
            _mm_cmple_ps(v81, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v82, v81), v82)),
              _mm_mul_ps(v82, *(__m128 *)_xmm)));
    v84 = _mm_sub_ps((__m128)0i64, v20);
    v85 = _mm_mul_ps(v83, v144);
    v86 = _mm_rsqrt_ps(v84);
    v87 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v86, v84), v86)), _mm_mul_ps(v86, *(__m128 *)_xmm));
    v88 = _mm_rcp_ps(v28);
    v89 = _mm_mul_ps(
            _mm_andnot_ps(_mm_cmple_ps(v84, (__m128)0i64), _mm_mul_ps(v87, v84)),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v28, v88)), v88));
    v90 = _mm_shuffle_ps(v41, v41, 0);
    v147 = v90;
    v91 = _mm_shuffle_ps(v41, v41, 85);
    bonusVector->m_quad = _mm_add_ps(_mm_mul_ps(v85, _mm_mul_ps(v89, penetrationPenalty->m_real)), bonusVector->m_quad);
    v143 = v91;
    v92 = 32i64;
    v93 = _mm_shuffle_ps(v41, v41, 170);
    v94 = v152 + 8;
    v149 = _mm_shuffle_ps(v85, v85, 85);
    v95 = _mm_shuffle_ps(v85, v85, 0);
    v96 = _mm_shuffle_ps(v85, v85, 170);
    v145 = v95;
    do
    {
      ++m_elements;
      v94 += 8i64;
      v97 = _mm_add_ps(_mm_mul_ps(v79, v28), v91);
      v98 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v78, v28), v90), v145);
      v99 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(v94 - 8)), (__m128i)0i64);
      v100 = _mm_unpacklo_epi16(v99, (__m128i)0i64);
      v101 = _mm_unpackhi_epi16(v99, (__m128i)0i64);
      v102 = _mm_add_ps(_mm_add_ps(v98, _mm_mul_ps(v97, v149)), _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v80, v28), v93), v96));
      v103 = _mm_mul_ps(
               _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srli_epi32(v100, 0x10u)),
                   (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                 _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v100, 0x10u), 0x10u))),
               (__m128)xmmword_141A71230);
      v104 = _mm_cvtepi32_ps(_mm_srli_epi32(v101, 0x10u));
      v105 = _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v101, 0x10u), 0x10u));
      v91 = v143;
      v106 = _mm_mul_ps(_mm_add_ps(v103, g_vectorfConstants[0]), m_real);
      v107 = _mm_mul_ps(
               _mm_add_ps(
                 _mm_mul_ps(
                   _mm_add_ps(_mm_mul_ps(v104, (__m128)`hkIntVector::convertU32ToF32::`2::two16), v105),
                   (__m128)xmmword_141A71230),
                 g_vectorfConstants[0]),
               m_real);
      v78 = _mm_add_ps(_mm_mul_ps(v106, v139), _mm_mul_ps(v107, v130));
      v108 = v107;
      v80 = _mm_add_ps(_mm_mul_ps(v106, v75), _mm_mul_ps(v107, v77));
      v90 = v147;
      v79 = _mm_add_ps(_mm_mul_ps(v106, v133), _mm_mul_ps(v108, v136));
      v109 = _mm_cmple_ps(v102, (__m128)0i64);
      m_elements[-1].m_quad = _mm_or_ps(
                                _mm_and_ps(v109, HKAI_LOCAL_STEERING_MIN_TTC.m_real),
                                _mm_andnot_ps(v109, m_elements[-1].m_quad));
      --v92;
    }
    while ( v92 );
  }
  else
  {
    v110 = (const __m128i *)(v152 + 8);
    v111 = (char *)((char *)bonuses->m_scores.m_elements - (char *)m_elements);
    v112 = 32i64;
    v141 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      v113 = _mm_add_ps(v42.m_quad, v142);
      v114 = _mm_add_ps(v38.m_quad, v146);
      v115 = (__m128i)_mm_mul_ps(_mm_add_ps(_mm_mul_ps(v114, v114), _mm_mul_ps(v113, v113)), v148);
      v116 = _mm_cmplt_ps(_mm_add_ps(_mm_mul_ps(v38.m_quad, v138), _mm_mul_ps(v42.m_quad, v69)), v132);
      v117 = _mm_add_ps(_mm_mul_ps(v114, v150), _mm_mul_ps(v113, v151));
      v118 = _mm_unpacklo_epi8(_mm_loadl_epi64(v110), (__m128i)0i64);
      v119 = _mm_unpackhi_epi16(v118, (__m128i)0i64);
      v120 = _mm_sub_ps(_mm_mul_ps(v117, v117), _mm_mul_ps((__m128)v115, v20));
      *(__m128 *)((char *)&m_elements->m_quad + (_QWORD)v111) = _mm_or_ps(
                                                                  _mm_and_ps(
                                                                    _mm_add_ps(
                                                                      *(__m128 *)((char *)&m_elements->m_quad
                                                                                + (_QWORD)v111),
                                                                      v135),
                                                                    v116),
                                                                  _mm_andnot_ps(
                                                                    v116,
                                                                    *(__m128 *)((char *)&m_elements->m_quad
                                                                              + (_QWORD)v111)));
      v121 = _mm_unpacklo_epi16(v118, (__m128i)0i64);
      v42.m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_cvtepi32_ps(_mm_srli_epi32(v121, 0x10u)),
                           (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                         _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v121, 0x10u), 0x10u))),
                       (__m128)xmmword_141A71230),
                     g_vectorfConstants[0]);
      v122 = _mm_mul_ps(
               _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srli_epi32(v119, 0x10u)),
                   (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                 _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v119, 0x10u), 0x10u))),
               (__m128)xmmword_141A71230);
      v123 = _mm_sub_ps(
               _mm_xor_ps(v117, v141),
               _mm_andnot_ps(_mm_cmple_ps(v120, (__m128)0i64), _mm_mul_ps(_mm_rsqrt_ps(v120), v120)));
      v124 = _mm_cmpeq_ps((__m128)v115, (__m128)0i64);
      v125 = _mm_and_ps(_mm_cmplt_ps((__m128)0i64, v123), _mm_cmple_ps((__m128)0i64, v120));
      v38.m_quad = _mm_add_ps(v122, g_vectorfConstants[0]);
      v126 = _mm_mul_ps(
               v123,
               _mm_or_ps(
                 _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v115, 0x1Fu), 0x1Fu), (__m128)_xmm), v124),
                 _mm_andnot_ps(v124, _mm_rcp_ps((__m128)v115))));
      v127 = _mm_and_ps(v125, _mm_cmplt_ps(v126, m_elements->m_quad));
      v128 = _mm_or_ps(_mm_andnot_ps(v127, m_elements->m_quad), _mm_and_ps(v127, v126));
      ++m_elements;
      v110 = (const __m128i *)((char *)v110 + 8);
      m_elements[-1] = (hkVector4f)v128;
      --v112;
    }
    while ( v112 );
  }
  return v12 != 0;
}

// File Line: 529
// RVA: 0xC2B1B0
bool __fastcall hkaiVelocityCandidateScoringUtil::scoreBoundaryObstacle(
        hkaiAvoidanceSolver::SteeringAgent *agent,
        hkaiAvoidanceSolver::BoundaryObstacle *boundaryObstacle,
        hkVector4f *up,
        hkSimdFloat32 *thresholdDistanceSquared,
        hkSimdFloat32 *penetrationPenalty,
        hkaiVelocityCandidateGenerator *velocityCandidates,
        hkaiVelocityCandidateScores *timesToCollision,
        hkaiVelocityCandidateScores *bonuses,
        hkVector4f *bonusVector)
{
  __m128 m_quad; // xmm5
  hkVector4f v10; // xmm4
  __m128 v11; // xmm3
  __m128 v12; // xmm1
  hkVector4f v13; // xmm7
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm7
  __m128 v20; // xmm7
  __m128 v21; // xmm5
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm7
  __m128 v29; // xmm7
  hkSimdFloat32 totalRadius; // [rsp+50h] [rbp-68h] BYREF
  hkVector4f c2; // [rsp+60h] [rbp-58h] BYREF
  hkVector4f c1; // [rsp+70h] [rbp-48h] BYREF
  hkVector4f position; // [rsp+80h] [rbp-38h] BYREF

  m_quad = up->m_quad;
  v10.m_quad = (__m128)boundaryObstacle->m_end;
  v11 = _mm_shuffle_ps((__m128)LODWORD(agent->m_boundaryRadius), (__m128)LODWORD(agent->m_boundaryRadius), 0);
  v12 = _mm_mul_ps(up->m_quad, agent->m_position.m_quad);
  v13.m_quad = (__m128)boundaryObstacle->m_start;
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v15 = _mm_mul_ps(up->m_quad, v10.m_quad);
  position.m_quad = _mm_sub_ps(agent->m_position.m_quad, _mm_mul_ps(v14, up->m_quad));
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_mul_ps(m_quad, v13.m_quad);
  v18 = _mm_sub_ps(v10.m_quad, _mm_mul_ps(v16, m_quad));
  c1.m_quad = _mm_shuffle_ps(v18, _mm_unpackhi_ps(v18, v11), 196);
  v19 = _mm_sub_ps(
          v13.m_quad,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170)),
            m_quad));
  c2.m_quad = _mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, v11), 196);
  v20 = _mm_sub_ps(c2.m_quad, position.m_quad);
  v21 = _mm_sub_ps(c2.m_quad, c1.m_quad);
  v22 = _mm_mul_ps(v21, v21);
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)), _mm_shuffle_ps(v22, v22, 170));
  v24 = _mm_mul_ps(v20, v21);
  v25 = _mm_rcp_ps(v23);
  v26 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v25)), v25),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
            _mm_shuffle_ps(v24, v24, 170)));
  v27 = _mm_cmplt_ps(v26, query.m_quad);
  v28 = _mm_sub_ps(
          v20,
          _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v26, v27), _mm_andnot_ps(v27, query.m_quad))), v21));
  v29 = _mm_mul_ps(v28, v28);
  if ( (float)((float)(_mm_shuffle_ps(v29, v29, 85).m128_f32[0] + _mm_shuffle_ps(v29, v29, 0).m128_f32[0])
             + _mm_shuffle_ps(v29, v29, 170).m128_f32[0]) > thresholdDistanceSquared->m_real.m128_f32[0] )
    return 0;
  totalRadius.m_real = _mm_shuffle_ps(
                         (__m128)LODWORD(agent->m_boundaryRadius),
                         (__m128)LODWORD(agent->m_boundaryRadius),
                         0);
  return hkaiVelocityCandidateScoringUtil::scoreStaticCapsule(
           &position,
           &c1,
           &c2,
           &totalRadius,
           penetrationPenalty,
           velocityCandidates,
           timesToCollision,
           bonuses,
           bonusVector);
}

// File Line: 572
// RVA: 0xC2B890
bool __fastcall hkaiVelocityCandidateScoringUtil::scoreStaticCapsule(
        hkVector4f *position,
        hkVector4f *c1,
        hkVector4f *c2,
        hkSimdFloat32 *totalRadius,
        hkSimdFloat32 *penetrationPenalty,
        hkaiVelocityCandidateGenerator *velocityCandidatesIn,
        hkaiVelocityCandidateScores *timesToCollision,
        hkaiVelocityCandidateScores *bonuses,
        hkVector4f *bonusVector)
{
  __m128 m_real; // xmm5
  __m128 v11; // xmm2
  __m128 m_quad; // xmm3
  __m128 v13; // xmm6
  __m128 v14; // xmm9
  __m128 v15; // xmm10
  __m128 v16; // xmm11
  __m128 v17; // xmm1
  __m128 v18; // xmm14
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm15
  __m128 v22; // xmm1
  __m128 v23; // xmm7
  __m128 v24; // xmm1
  __m128 v25; // xmm8
  hkVector4f *m_elements; // rcx
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __m128 v30; // xmm4
  __m128 v31; // xmm7
  __m128 v32; // xmm8
  __m128 v33; // xmm13
  float v34; // xmm9_4
  __m128 v35; // xmm1
  __m128 v36; // xmm4
  __m128 v37; // xmm3
  __m128 v38; // xmm1
  __m128 v39; // xmm14
  float v40; // xmm2_4
  __int64 v41; // rdx
  const __m128i *v42; // rax
  __m128 v43; // xmm13
  __m128i v44; // xmm2
  __m128i v45; // xmm2
  __m128i v46; // xmm1
  __m128i v47; // xmm2
  __m128 v48; // xmm3
  __m128 v49; // xmm1
  __m128 v50; // xmm13
  __m128 v51; // xmm4
  __m128 v52; // xmm5
  __int64 v53; // rdx
  __m128 v54; // xmm7
  __m128 v55; // xmm6
  __m128 v56; // xmm4
  const __m128i *v57; // rax
  __m128 v58; // xmm1
  __m128 v59; // xmm3
  __m128 v60; // xmm4
  __m128 v61; // xmm1
  __m128 v62; // xmm3
  __m128 v63; // xmm0
  __m128 v64; // xmm4
  __m128 v65; // xmm7
  __m128 v66; // xmm3
  __m128 v67; // xmm8
  __m128i v68; // xmm2
  __m128 v69; // xmm5
  __m128i v70; // xmm1
  __m128i v71; // xmm2
  __m128 v72; // xmm7
  __m128 v73; // xmm1
  __m128 v74; // xmm8
  __m128 v75; // xmm0
  hkSphere sphere; // [rsp+40h] [rbp-178h] BYREF
  __m128 v77; // [rsp+50h] [rbp-168h]
  __m128 v78; // [rsp+60h] [rbp-158h]
  __m128 v79; // [rsp+70h] [rbp-148h]
  __m128 v80; // [rsp+80h] [rbp-138h]
  __m128 v81; // [rsp+90h] [rbp-128h]
  __m128 v82; // [rsp+A0h] [rbp-118h]
  hkaiVelocityCandidateGenerator velocityCandidates; // [rsp+B0h] [rbp-108h] BYREF

  m_real = totalRadius->m_real;
  v11 = _mm_sub_ps(position->m_quad, c1->m_quad);
  m_quad = velocityCandidatesIn->m_forward.m_quad;
  v13 = velocityCandidatesIn->m_right.m_quad;
  *(_OWORD *)&velocityCandidates.m_template = *(_OWORD *)&velocityCandidatesIn->m_template;
  v14 = velocityCandidatesIn->m_maxSpeed.m_real;
  v15 = velocityCandidatesIn->m_firstBlockForward.m_quad;
  v16 = velocityCandidatesIn->m_firstBlockRight.m_quad;
  velocityCandidates.m_forward.m_quad = m_quad;
  v17 = _mm_mul_ps(m_quad, v11);
  velocityCandidates.m_right.m_quad = v13;
  velocityCandidates.m_firstBlockForward.m_quad = v15;
  velocityCandidates.m_firstBlockRight.m_quad = v16;
  velocityCandidates.m_maxSpeed.m_real = v14;
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_mul_ps(v13, v11);
  v20 = _mm_sub_ps(c2->m_quad, c1->m_quad);
  v21 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v22 = _mm_mul_ps(m_quad, v20);
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)), _mm_shuffle_ps(v22, v22, 170));
  v24 = _mm_mul_ps(v13, v20);
  v80 = v23;
  v25 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)), _mm_shuffle_ps(v24, v24, 170));
  v82 = v25;
  sphere.m_pos.m_quad = _mm_mul_ps(m_real, m_real);
  if ( v14.m128_f32[0] == 0.0 )
    return 0;
  v78 = _mm_rcp_ps(v14);
  m_elements = timesToCollision->m_scores.m_elements;
  v28 = _mm_add_ps(_mm_mul_ps(v25, v25), _mm_mul_ps(v23, v23));
  v29 = _mm_rsqrt_ps(v28);
  v30 = _mm_andnot_ps(
          _mm_cmple_ps(v28, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v29), v29)), _mm_mul_ps(*(__m128 *)_xmm, v29)));
  v31 = _mm_mul_ps(v23, v30);
  v32 = _mm_mul_ps(v25, v30);
  v33 = _mm_sub_ps(_mm_mul_ps(v31, v21), _mm_mul_ps(v32, v18));
  LODWORD(v34) = (unsigned int)(2 * v33.m128_i32[0]) >> 1;
  if ( v34 >= m_real.m128_f32[0] )
  {
    if ( v33.m128_f32[0] >= 0.0 )
    {
      v50 = v80;
      v51 = m_real;
      v52 = _mm_mul_ps(m_real, v31);
      v53 = 32i64;
      v54 = query.m_quad;
      v55 = _mm_sub_ps(v21, v52);
      sphere.m_pos.m_quad = _mm_sub_ps((__m128)0i64, sphere.m_pos.m_quad);
      v81 = v55;
      v56 = _mm_add_ps(_mm_mul_ps(v51, v32), v18);
      v57 = (const __m128i *)(velocityCandidates.m_template + 8);
      v79 = v56;
      v77 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
      do
      {
        v58 = _mm_sub_ps(_mm_mul_ps(v16, v50), _mm_mul_ps(v15, v82));
        v59 = _mm_cmpeq_ps((__m128)0i64, v58);
        v60 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v56, v16), _mm_mul_ps(v55, v15)), _mm_andnot_ps(v59, _mm_rcp_ps(v58)));
        v61 = _mm_cmplt_ps(v60, v54);
        v62 = _mm_and_ps(_mm_cmplt_ps(_mm_add_ps(_mm_mul_ps(v16, v82), _mm_mul_ps(v15, v50)), (__m128)0i64), v59);
        v63 = _mm_max_ps(
                _mm_or_ps(_mm_andnot_ps(v62, aabbOut.m_quad), _mm_and_ps(v62, v54)),
                _mm_or_ps(_mm_andnot_ps(v61, v54), _mm_and_ps(v60, v61)));
        v64 = _mm_sub_ps(v21, _mm_mul_ps(v63, v82));
        v65 = _mm_sub_ps(v18, _mm_mul_ps(v63, v50));
        v66 = _mm_add_ps(_mm_mul_ps(v16, v16), _mm_mul_ps(v15, v15));
        v67 = _mm_add_ps(_mm_mul_ps(v64, v16), _mm_mul_ps(v65, v15));
        v68 = _mm_unpacklo_epi8(_mm_loadl_epi64(v57), (__m128i)0i64);
        v69 = _mm_cmplt_ps(v67, (__m128)0i64);
        v70 = _mm_unpacklo_epi16(v68, (__m128i)0i64);
        v71 = _mm_unpackhi_epi16(v68, (__m128i)0i64);
        v15 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_cvtepi32_ps(_mm_srli_epi32(v70, 0x10u)),
                      (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                    _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v70, 0x10u), 0x10u))),
                  (__m128)xmmword_141A71230),
                g_vectorfConstants[0]);
        ++m_elements;
        v57 = (const __m128i *)((char *)v57 + 8);
        v16 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_cvtepi32_ps(_mm_srli_epi32(v71, 0x10u)),
                      (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                    _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v71, 0x10u), 0x10u))),
                  (__m128)xmmword_141A71230),
                g_vectorfConstants[0]);
        v72 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v65, v65), sphere.m_pos.m_quad), _mm_mul_ps(v64, v64));
        v56 = v79;
        v73 = _mm_sub_ps(_mm_mul_ps(v67, v67), _mm_mul_ps(v72, v66));
        v54 = query.m_quad;
        v55 = v81;
        v74 = _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps(_mm_xor_ps(v67, v77), _mm_mul_ps(_mm_rsqrt_ps(v73), v73)),
                  _mm_andnot_ps(_mm_cmpeq_ps((__m128)0i64, v66), _mm_rcp_ps(v66))),
                v78);
        v75 = _mm_and_ps(_mm_cmplt_ps(v74, m_elements[-1].m_quad), _mm_and_ps(_mm_cmplt_ps((__m128)0i64, v73), v69));
        m_elements[-1].m_quad = _mm_or_ps(_mm_andnot_ps(v75, m_elements[-1].m_quad), _mm_and_ps(v75, v74));
        --v53;
      }
      while ( v53 );
    }
    return 0;
  }
  v35 = _mm_rcp_ps(v30);
  v36 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v35, v30)), v35);
  v37 = _mm_add_ps(_mm_mul_ps(v32, v21), _mm_mul_ps(v31, v18));
  v38 = _mm_cmplt_ps(v36, v37);
  v39 = _mm_cmplt_ps(v37, (__m128)0i64);
  LODWORD(v40) = _mm_andnot_ps(v38, _mm_and_ps(v37, v39)).m128_u32[0] | COERCE_UNSIGNED_INT(v36.m128_f32[0] - v37.m128_f32[0]) & v38.m128_i32[0];
  if ( (float)((float)(v40 * v40) + (float)(v34 * v34)) >= sphere.m_pos.m_quad.m128_f32[0] )
  {
    if ( v33.m128_f32[0] >= 0.0 )
    {
      v49 = _mm_or_ps(_mm_andnot_ps(v39, c2->m_quad), _mm_and_ps(c1->m_quad, v39));
      sphere.m_pos.m_quad = _mm_shuffle_ps(v49, _mm_unpackhi_ps(v49, m_real), 196);
      return hkaiVelocityCandidateScoringUtil::scoreStaticSphere(
               position,
               &sphere,
               penetrationPenalty,
               &velocityCandidates,
               timesToCollision,
               bonuses,
               bonusVector);
    }
    return 0;
  }
  v41 = 32i64;
  bonusVector->m_quad = _mm_add_ps(
                          _mm_mul_ps(
                            _mm_sub_ps(_mm_mul_ps(v13, v31), _mm_mul_ps(velocityCandidatesIn->m_forward.m_quad, v32)),
                            _mm_mul_ps(_mm_sub_ps(m_real, v33), penetrationPenalty->m_real)),
                          bonusVector->m_quad);
  v42 = (const __m128i *)(velocityCandidates.m_template + 8);
  v43 = HKAI_LOCAL_STEERING_MIN_TTC.m_real;
  do
  {
    v44 = _mm_loadl_epi64(v42);
    ++m_elements;
    v42 = (const __m128i *)((char *)v42 + 8);
    v45 = _mm_unpacklo_epi8(v44, (__m128i)0i64);
    v46 = _mm_unpacklo_epi16(v45, (__m128i)0i64);
    v47 = _mm_unpackhi_epi16(v45, (__m128i)0i64);
    v48 = _mm_cmple_ps(_mm_sub_ps(_mm_mul_ps(v31, v16), _mm_mul_ps(v32, v15)), (__m128)0i64);
    v15 = _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v46, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v46, 0x10u), 0x10u))),
              (__m128)xmmword_141A71230),
            g_vectorfConstants[0]);
    v16 = _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v47, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v47, 0x10u), 0x10u))),
              (__m128)xmmword_141A71230),
            g_vectorfConstants[0]);
    m_elements[-1].m_quad = _mm_or_ps(_mm_and_ps(v48, v43), _mm_andnot_ps(v48, m_elements[-1].m_quad));
    --v41;
  }
  while ( v41 );
  return 1;
}

// File Line: 799
// RVA: 0xC2B3A0
bool __fastcall hkaiVelocityCandidateScoringUtil::scoreStaticSphere(
        hkVector4f *position,
        hkSphere *sphere,
        hkSimdFloat32 *penetrationPenalty,
        hkaiVelocityCandidateGenerator *velocityCandidates,
        hkaiVelocityCandidateScores *timesToCollision,
        hkaiVelocityCandidateScores *bonuses,
        hkVector4f *bonusVector)
{
  return hkaiVelocityCandidateScoringUtil::scoreMovingSphere(
           position,
           sphere,
           &aabbOut,
           penetrationPenalty,
           velocityCandidates,
           timesToCollision,
           bonuses,
           bonusVector);
}

// File Line: 813
// RVA: 0xC2B3F0
_BOOL8 __fastcall hkaiVelocityCandidateScoringUtil::scoreMovingSphere(
        hkVector4f *position,
        hkSphere *sphere,
        hkVector4f *sphereVelocity,
        hkSimdFloat32 *penetrationPenalty,
        hkaiVelocityCandidateGenerator *velocityCandidates,
        hkaiVelocityCandidateScores *timesToCollision,
        hkaiVelocityCandidateScores *bonuses,
        hkVector4f *bonusVector)
{
  __m128 v9; // xmm7
  __m128 v10; // xmm2
  hkSimdFloat32 v11; // xmm11
  hkVector4f *m_elements; // rcx
  __m128 v13; // xmm1
  __m128 v14; // xmm5
  __m128 v15; // xmm15
  __m128 v16; // xmm1
  __m128 v17; // xmm8
  __m128 v18; // xmm6
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  bool v21; // r9
  __m128 v22; // xmm12
  __m128 v23; // xmm10
  __m128 v24; // xmm13
  __m128 v25; // xmm9
  __int64 v26; // r8
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  __m128 v29; // xmm6
  __m128 v30; // xmm1
  __m128 v31; // xmm0
  __m128 v32; // xmm2
  __m128 v33; // xmm6
  __m128 v34; // xmm1
  const __m128i *v35; // rdx
  __m128i v36; // xmm2
  __m128i v37; // xmm2
  __m128i v38; // xmm1
  __m128i v39; // xmm2
  __m128 v40; // xmm3
  __int64 v41; // r8
  const char *v42; // rax
  __m128 v43; // xmm5
  __m128 v44; // xmm7
  __m128 v45; // xmm3
  __m128 v46; // xmm2
  __m128 v47; // xmm4
  __m128i v48; // xmm1
  __m128i v49; // xmm2
  __m128i v50; // xmm1
  __m128 v51; // xmm10
  __m128 v52; // xmm0
  __m128 v53; // xmm1
  __m128 v54; // xmm8
  __m128 v55; // xmm0
  __m128 v56; // xmm6
  __m128 v57; // xmm0
  __m128 v59; // [rsp+0h] [rbp-D8h]
  __m128 v60; // [rsp+10h] [rbp-C8h]
  __m128 v61; // [rsp+20h] [rbp-B8h]

  v9 = _mm_sub_ps(position->m_quad, sphere->m_pos.m_quad);
  v10 = _mm_shuffle_ps(sphere->m_pos.m_quad, sphere->m_pos.m_quad, 255);
  v11.m_real = (__m128)velocityCandidates->m_maxSpeed;
  m_elements = timesToCollision->m_scores.m_elements;
  v13 = _mm_mul_ps(v9, velocityCandidates->m_forward.m_quad);
  v14 = _mm_mul_ps(v9, v9);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v16 = _mm_mul_ps(v9, velocityCandidates->m_right.m_quad);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v61 = v17;
  v18 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
            _mm_shuffle_ps(v14, v14, 170)),
          _mm_mul_ps(v10, v10));
  v59 = v18;
  v19 = _mm_mul_ps(sphereVelocity->m_quad, velocityCandidates->m_right.m_quad);
  v20 = _mm_mul_ps(sphereVelocity->m_quad, velocityCandidates->m_forward.m_quad);
  v21 = v18.m128_f32[0] < 0.0;
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)), _mm_shuffle_ps(v20, v20, 170));
  v23 = _mm_sub_ps(_mm_mul_ps(velocityCandidates->m_firstBlockForward.m_quad, v11.m_real), v22);
  v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v25 = _mm_sub_ps(_mm_mul_ps(velocityCandidates->m_firstBlockRight.m_quad, v11.m_real), v24);
  if ( v18.m128_f32[0] >= 0.0 )
  {
    v41 = 32i64;
    v42 = velocityCandidates->m_template + 8;
    v60 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      ++m_elements;
      v42 += 8;
      --v41;
      v43 = _mm_add_ps(_mm_mul_ps(v17, v25), _mm_mul_ps(v23, v15));
      v44 = _mm_add_ps(_mm_mul_ps(v25, v25), _mm_mul_ps(v23, v23));
      v45 = _mm_sub_ps(_mm_mul_ps(v43, v43), _mm_mul_ps(v44, v18));
      v46 = _mm_rsqrt_ps(v45);
      v47 = _mm_andnot_ps(
              _mm_cmple_ps(v45, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v45, v46), v46)),
                  _mm_mul_ps(v46, *(__m128 *)_xmm)),
                v45));
      v48 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(v42 - 8)), (__m128i)0i64);
      v49 = _mm_unpackhi_epi16(v48, (__m128i)0i64);
      v50 = _mm_unpacklo_epi16(v48, (__m128i)0i64);
      v51 = _mm_cvtepi32_ps(_mm_srli_epi32(v50, 0x10u));
      v52 = _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v50, 0x10u), 0x10u));
      v53 = _mm_rcp_ps(v44);
      v23 = _mm_sub_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(_mm_mul_ps(v51, (__m128)`hkIntVector::convertU32ToF32::`2::two16), v52),
                    (__m128)xmmword_141A71230),
                  g_vectorfConstants[0]),
                v11.m_real),
              v22);
      v54 = _mm_mul_ps(
              _mm_sub_ps(_mm_xor_ps(v43, v60), v47),
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v44, v53)), v53));
      v25 = _mm_sub_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_cvtepi32_ps(_mm_srli_epi32(v49, 0x10u)),
                        (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                      _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v49, 0x10u), 0x10u))),
                    (__m128)xmmword_141A71230),
                  g_vectorfConstants[0]),
                v11.m_real),
              v24);
      v55 = _mm_and_ps(
              _mm_and_ps(_mm_cmplt_ps((__m128)0i64, v45), _mm_cmplt_ps(v43, (__m128)0i64)),
              _mm_cmplt_ps(v54, m_elements[-1].m_quad));
      v56 = _mm_and_ps(v55, v54);
      v17 = v61;
      v57 = _mm_or_ps(_mm_andnot_ps(v55, m_elements[-1].m_quad), v56);
      v18 = v59;
      m_elements[-1] = (hkVector4f)v57;
    }
    while ( v41 );
  }
  else
  {
    v26 = 32i64;
    v27 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
            _mm_shuffle_ps(v14, v14, 170));
    v28 = _mm_rsqrt_ps(v27);
    v29 = _mm_cmple_ps(v27, (__m128)0i64);
    v30 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v27), v28));
    v31 = _mm_mul_ps(*(__m128 *)_xmm, v28);
    v32 = _mm_sub_ps((__m128)0i64, v59);
    v33 = _mm_andnot_ps(v29, _mm_mul_ps(v30, v31));
    v34 = _mm_rsqrt_ps(v32);
    bonusVector->m_quad = _mm_add_ps(
                            _mm_mul_ps(
                              _mm_mul_ps(
                                _mm_andnot_ps(
                                  _mm_cmple_ps(v32, (__m128)0i64),
                                  _mm_mul_ps(
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v34), v34)),
                                      _mm_mul_ps(*(__m128 *)_xmm, v34)),
                                    v32)),
                                penetrationPenalty->m_real),
                              _mm_mul_ps(v33, v9)),
                            bonusVector->m_quad);
    v35 = (const __m128i *)(velocityCandidates->m_template + 8);
    do
    {
      v36 = _mm_loadl_epi64(v35);
      v35 = (const __m128i *)((char *)v35 + 8);
      ++m_elements;
      v37 = _mm_unpacklo_epi8(v36, (__m128i)0i64);
      v38 = _mm_unpacklo_epi16(v37, (__m128i)0i64);
      v39 = _mm_unpackhi_epi16(v37, (__m128i)0i64);
      v40 = _mm_cmple_ps(_mm_add_ps(_mm_mul_ps(v25, v17), _mm_mul_ps(v23, v15)), (__m128)0i64);
      v23 = _mm_sub_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_cvtepi32_ps(_mm_srli_epi32(v38, 0x10u)),
                        (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                      _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v38, 0x10u), 0x10u))),
                    (__m128)xmmword_141A71230),
                  g_vectorfConstants[0]),
                v11.m_real),
              v22);
      m_elements[-1].m_quad = _mm_or_ps(
                                _mm_andnot_ps(v40, m_elements[-1].m_quad),
                                _mm_and_ps(v40, HKAI_LOCAL_STEERING_MIN_TTC.m_real));
      v25 = _mm_sub_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_cvtepi32_ps(_mm_srli_epi32(v39, 0x10u)),
                        (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                      _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v39, 0x10u), 0x10u))),
                    (__m128)xmmword_141A71230),
                  g_vectorfConstants[0]),
                v11.m_real),
              v24);
      --v26;
    }
    while ( v26 );
  }
  return v21;
}

// File Line: 938
// RVA: 0xC2C460
__int64 __fastcall hkaiVelocityCandidateScoringUtil::calcWallFollowingDir(
        hkaiVelocityCandidateGenerator *velocityCandidatesIn,
        hkaiVelocityCandidateScores *timesToStaticCollision,
        hkSimdFloat32 *searchDistance,
        float wallFollowingAngle,
        hkSimdFloat32 *forwardFactorOut,
        hkSimdFloat32 *rightFactorOut)
{
  hkVector4f *m_elements; // r10
  __m128 v7; // xmm7
  __m128 v8; // xmm8
  __m128 v9; // xmm11
  __m128 m_quad; // xmm12
  __m128i v11; // xmm1
  hkSimdFloat32 v13; // xmm3
  __m128i v14; // xmm2
  __m128i v15; // xmm0
  __m128 v16; // xmm0
  __m128 v17; // xmm14
  __m128 v18; // xmm1
  __m128 v19; // xmm1
  __m128i si128; // xmm6
  int v21; // edx
  __m128 v22; // xmm2
  __m128 *p_m_quad; // r8
  __int64 v24; // r9
  __m128i v25; // xmm8
  __m128 v26; // xmm7
  __m128i v27; // xmm6
  __m128i v28; // xmm5
  __m128 v29; // xmm4
  __m128i v30; // xmm8
  __m128 v31; // xmm6
  __m128 v32; // xmm5
  __m128 v33; // xmm8
  __m128 v34; // xmm9
  __m128 v35; // xmm4
  __m128 v36; // xmm2
  __m128 v37; // xmm3
  __m128 v38; // xmm0
  __m128 v39; // xmm4
  __m128 v40; // xmm0
  __m128 v41; // xmm5
  __m128 v42; // xmm0
  __m128 v43; // xmm8
  __m128 v44; // xmm0
  __m128 v45; // xmm13
  __m128 v46; // xmm3
  __m128i v47; // xmm1
  __m128i v48; // xmm2
  __m128i v49; // xmm0
  __m128 v50; // xmm10
  __m128 v51; // xmm11
  __m128 v52; // xmm1
  __m128 v53; // xmm12
  __m128 v54; // xmm7
  __m128 v55; // xmm5
  __m128 v56; // xmm9
  __m128 v57; // xmm4
  __m128 v58; // xmm6
  __m128 v59; // xmm8
  __m128 v60; // xmm1
  __m128 v61; // xmm2
  __m128 v62; // xmm6
  __m128 v63; // xmm8
  __m128 v64; // xmm9
  __m128i v65; // xmm1
  __m128 v66; // xmm3
  __m128 v67; // xmm6
  __m128 v68; // xmm9
  __m128 v69; // xmm2
  __m128 v70; // xmm7
  __m128 v71; // xmm1
  int v72; // eax
  __int64 v73; // rcx
  __m128 v74; // xmm0
  __m128 v75; // xmm1
  __m128 v77; // xmm2
  __m128 v78; // xmm1
  __m128 v79; // xmm7
  __m128 v80; // xmm1
  hkVector4f v81; // [rsp+0h] [rbp-1A8h]
  __m128 v82; // [rsp+10h] [rbp-198h]
  __m128 v83; // [rsp+20h] [rbp-188h]
  __m128 v84; // [rsp+30h] [rbp-178h]
  __m128 v85; // [rsp+40h] [rbp-168h]
  __m128 v86; // [rsp+50h] [rbp-158h]
  __m128 v87; // [rsp+60h] [rbp-148h]
  __m128 v88; // [rsp+70h] [rbp-138h]
  __m128 v89; // [rsp+90h] [rbp-118h]

  m_elements = timesToStaticCollision->m_scores.m_elements;
  v7 = _mm_shuffle_ps(
         velocityCandidatesIn->m_firstBlockForward.m_quad,
         velocityCandidatesIn->m_firstBlockForward.m_quad,
         0);
  v81.m_quad = (__m128)timesToStaticCollision->m_scores.m_elements[25];
  v8 = _mm_shuffle_ps(velocityCandidatesIn->m_firstBlockRight.m_quad, velocityCandidatesIn->m_firstBlockRight.m_quad, 0);
  v9 = (__m128)`hkIntVector::convertU32ToF32::`2::two16;
  m_quad = timesToStaticCollision->m_scores.m_elements[31].m_quad;
  v11 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(velocityCandidatesIn->m_template + 248)), (__m128i)0i64);
  v13.m_real = (__m128)velocityCandidatesIn->m_maxSpeed;
  v14 = _mm_unpackhi_epi16(v11, (__m128i)0i64);
  v15 = _mm_unpacklo_epi16(v11, (__m128i)0i64);
  v84 = g_vectorfConstants[0];
  v89 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_cvtepi32_ps(_mm_srli_epi32(v15, 0x10u)),
                (__m128)`hkIntVector::convertU32ToF32::`2::two16),
              _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v15, 0x10u), 0x10u))),
            (__m128)xmmword_141A71230),
          g_vectorfConstants[0]);
  v16 = _mm_rcp_ps(v13.m_real);
  v17 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v13.m_real, v16)), v16), searchDistance->m_real);
  v88 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_cvtepi32_ps(_mm_srli_epi32(v14, 0x10u)),
                (__m128)`hkIntVector::convertU32ToF32::`2::two16),
              _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v14, 0x10u), 0x10u))),
            (__m128)xmmword_141A71230),
          g_vectorfConstants[0]);
  v18 = _mm_add_ps(_mm_mul_ps(v8, v8), _mm_mul_ps(v7, v7));
  if ( v18.m128_f32[0] == 0.0 )
    v19 = 0i64;
  else
    v19 = _mm_div_ps(query.m_quad, _mm_sqrt_ps(v18));
  si128 = _mm_load_si128((const __m128i *)_xmm);
  v21 = 26;
  v22 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(wallFollowingAngle));
  p_m_quad = &m_elements[24].m_quad;
  v85 = _mm_mul_ps(v8, v19);
  v24 = 8i64;
  v25 = _mm_add_epi32(si128, si128);
  v86 = _mm_mul_ps(v7, v19);
  v26 = 0i64;
  v83 = 0i64;
  v27 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v22, *(__m128 *)_xmm)), si128));
  v28 = _mm_and_si128(v27, v25);
  v29 = _mm_cvtepi32_ps(v27);
  v30 = _mm_and_si128(_mm_add_epi32(v25, v25), v27);
  v31 = v88;
  v32 = (__m128)_mm_cmpeq_epi32(v28, (__m128i)0i64);
  v33 = _mm_xor_ps((__m128)_mm_slli_epi32(v30, 0x1Du), _mm_and_ps((__m128)LODWORD(wallFollowingAngle), *(__m128 *)_xmm));
  v34 = v81.m_quad;
  v35 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v29, *(__m128 *)DP1_0), v22), _mm_mul_ps(v29, *(__m128 *)DP2)),
          _mm_mul_ps(v29, *(__m128 *)DP3));
  v36 = _mm_mul_ps(v35, v35);
  v37 = _mm_andnot_ps(
          v32,
          _mm_add_ps(
            _mm_sub_ps(
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v36, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v36),
                    *(__m128 *)cosCoeff2_0),
                  v36),
                v36),
              _mm_mul_ps(v36, *(__m128 *)_xmm)),
            *(__m128 *)_xmm));
  v38 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v36, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v36),
                *(__m128 *)sinCoeff2_0),
              v36),
            v35),
          v35);
  v39 = v89;
  v40 = _mm_and_ps(v38, v32);
  v41 = g_vectorfConstants[0];
  v42 = _mm_xor_ps(_mm_or_ps(v40, v37), v33);
  v43 = g_vectorfConstants[0];
  v44 = _mm_xor_ps(v42, *(__m128 *)_xmm);
  v87 = _mm_shuffle_ps(v44, v44, 0);
  v82 = 0i64;
  do
  {
    v45 = *p_m_quad;
    v46 = _mm_shuffle_ps(_mm_shuffle_ps(m_quad, *p_m_quad, 51), _mm_shuffle_ps(m_quad, *p_m_quad, 153), 236);
    v47 = _mm_unpacklo_epi8(
            _mm_loadl_epi64((const __m128i *)&velocityCandidatesIn->m_template[8 * v21 - 16]),
            (__m128i)0i64);
    v48 = _mm_unpackhi_epi16(v47, (__m128i)0i64);
    v49 = _mm_unpacklo_epi16(v47, (__m128i)0i64);
    v50 = _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v49, 0x10u)), v9),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v49, 0x10u), 0x10u))),
              (__m128)xmmword_141A71230),
            v43);
    v51 = _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v48, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v48, 0x10u), 0x10u))),
              (__m128)xmmword_141A71230),
            v43);
    v52 = m_elements[v21 % 8 + 24].m_quad;
    v53 = _mm_and_ps(_mm_cmplt_ps(v46, v17), _mm_cmplt_ps(*p_m_quad, v17));
    if ( _mm_movemask_ps(v53) )
    {
      v54 = _mm_min_ps(m_elements[(v21 + 4) % 8 + 24].m_quad, v17);
      v55 = _mm_min_ps(_mm_shuffle_ps(_mm_shuffle_ps(v34, v52, 51), _mm_shuffle_ps(v34, v52, 153), 236), v17);
      v56 = _mm_shuffle_ps(_mm_shuffle_ps(v39, v50, 51), _mm_shuffle_ps(v39, v50, 153), 236);
      v57 = _mm_shuffle_ps(_mm_shuffle_ps(v31, v51, 51), _mm_shuffle_ps(v31, v51, 153), 236);
      v58 = _mm_sub_ps(_mm_mul_ps(v50, v45), _mm_mul_ps(v56, v46));
      v59 = _mm_sub_ps(_mm_mul_ps(v51, v45), _mm_mul_ps(v57, v46));
      v60 = _mm_add_ps(_mm_mul_ps(v59, v59), _mm_mul_ps(v58, v58));
      v61 = _mm_andnot_ps(_mm_cmple_ps(v60, (__m128)0i64), _mm_rsqrt_ps(v60));
      v62 = _mm_mul_ps(v58, v61);
      v63 = _mm_mul_ps(v59, v61);
      v64 = _mm_max_ps(
              _mm_sub_ps(_mm_mul_ps(_mm_add_ps(v56, v50), v63), _mm_mul_ps(_mm_add_ps(v57, v51), v62)),
              aabbOut.m_quad);
      v65 = (__m128i)_mm_cmplt_ps(
                       _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v63, v85), _mm_mul_ps(v62, v86)), v17),
                       _mm_mul_ps(_mm_sub_ps(v54, v55), *(__m128 *)_xmm));
      v66 = (__m128)_mm_slli_epi32(_mm_srli_epi32(v65, 0x1Fu), 0x1Fu);
      v67 = _mm_xor_ps(v62, v66);
      v68 = _mm_mul_ps(v64, _mm_or_ps(_mm_andnot_ps((__m128)v65, v55), _mm_and_ps((__m128)v65, v54)));
      v69 = _mm_and_ps(_mm_and_ps(_mm_cmplt_ps(v87, v67), v53), _mm_cmplt_ps(v84, v68));
      v41 = _mm_or_ps(_mm_and_ps(v69, v68), _mm_andnot_ps(v69, v84));
      v84 = v41;
      v82 = _mm_or_ps(_mm_and_ps(v69, v67), _mm_andnot_ps(v69, v82));
      v52 = m_elements[v21 % 8 + 24].m_quad;
      v70 = _mm_and_ps(_mm_xor_ps(v63, v66), v69);
      v43 = g_vectorfConstants[0];
      v26 = _mm_or_ps(v70, _mm_andnot_ps(v69, v83));
      v83 = v26;
    }
    ++v21;
    ++p_m_quad;
    v31 = v51;
    v9 = (__m128)`hkIntVector::convertU32ToF32::`2::two16;
    m_quad = v45;
    v39 = v50;
    v34 = v52;
    --v24;
  }
  while ( v24 );
  v71 = _mm_max_ps(_mm_shuffle_ps(v41, v41, 78), v41);
  v72 = _mm_movemask_ps(_mm_cmple_ps(_mm_max_ps(v71, _mm_shuffle_ps(v71, v71, 177)), v41));
  v73 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[v72];
  v74 = _mm_and_ps(
          (__m128)`hkVector4f::getComponent::`2::indexToMask[(unsigned __int8)hkVector4Comparison_maskToLastIndex[v72]],
          v41);
  v75 = _mm_or_ps(_mm_shuffle_ps(v74, v74, 78), v74);
  if ( COERCE_FLOAT(_mm_shuffle_ps(v75, v75, 177).m128_u32[0] | v75.m128_i32[0]) <= 0.0 )
    return 0i64;
  v77 = _mm_and_ps(
          (__m128)`hkVector4f::getComponent::`2::indexToMask[(unsigned __int8)hkVector4Comparison_maskToLastIndex[v72]],
          v82);
  v78 = _mm_or_ps(_mm_shuffle_ps(v77, v77, 78), v77);
  forwardFactorOut->m_real = _mm_or_ps(_mm_shuffle_ps(v78, v78, 177), v78);
  v79 = _mm_and_ps(v26, (__m128)`hkVector4f::getComponent::`2::indexToMask[v73]);
  v80 = _mm_or_ps(_mm_shuffle_ps(v79, v79, 78), v79);
  rightFactorOut->m_real = _mm_or_ps(_mm_shuffle_ps(v80, v80, 177), v80);
  return 1i64;
}

// File Line: 1224
// RVA: 0xC2CBB0
float __fastcall `anonymous namespace::calcWallFollowingPenaltyFromAngle(float angle)
{
  __m128i si128; // xmm6
  __m128 v2; // xmm9
  __m128 v3; // xmm3
  __m128i v4; // xmm7
  __m128i v5; // xmm6
  __m128 v6; // xmm2
  __m128 v7; // xmm5
  __m128 v8; // xmm4
  __m128 v9; // xmm2

  si128 = _mm_load_si128((const __m128i *)_xmm);
  v2 = _mm_add_ps((__m128)LODWORD(angle), *(__m128 *)_xmm);
  v3 = _mm_andnot_ps(*(__m128 *)_xmm, v2);
  v4 = _mm_add_epi32(si128, si128);
  v5 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(*(__m128 *)_xmm, v3)), si128));
  v6 = _mm_cvtepi32_ps(v5);
  v7 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v5, v4), (__m128i)0i64);
  v8 = _mm_add_ps(
         _mm_add_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)DP1_0, v6), v3), _mm_mul_ps(*(__m128 *)DP2, v6)),
         _mm_mul_ps(*(__m128 *)DP3, v6));
  v9 = _mm_mul_ps(v8, v8);
  return 1.0
       - fmaxf(
           0.0,
           (float)(1.0
                 - COERCE_FLOAT((_mm_andnot_ps(
                                   v7,
                                   _mm_add_ps(
                                     _mm_sub_ps(
                                       _mm_mul_ps(
                                         _mm_mul_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(
                                               _mm_add_ps(_mm_mul_ps(v9, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1),
                                               v9),
                                             *(__m128 *)cosCoeff2_0),
                                           v9),
                                         v9),
                                       _mm_mul_ps(v9, *(__m128 *)_xmm)),
                                     *(__m128 *)_xmm)).m128_u32[0] | COERCE_UNSIGNED_INT(
                                                                       (float)((float)((float)((float)((float)((float)(v9.m128_f32[0] * -0.00019515296) + 0.0083321612) * v9.m128_f32[0])
                                                                                             + -0.16666655)
                                                                                     * v9.m128_f32[0])
                                                                             * v8.m128_f32[0])
                                                                     + v8.m128_f32[0]) & v7.m128_i32[0]) ^ (_mm_and_si128(_mm_add_epi32(v4, v4), v5).m128i_u32[0] << 29) ^ _xmm[0] & v2.m128_i32[0]))
         * 2.0);
}

// File Line: 1242
// RVA: 0xC2BF00
void __fastcall hkaiVelocityCandidateScoringUtil::chooseBestCandidate(
        hkaiVelocityCandidateGenerator *velocityCandidatesIn,
        hkaiVelocityCandidateScores *staticTtcsIn,
        hkaiVelocityCandidateScores *dynamicTtcsIn,
        hkaiVelocityCandidateScores *bonusesIn,
        hkVector4f *bonusVector,
        float radialMultiplier,
        float wallFollowingAngle,
        float collisionPenaltyIn,
        float desiredSpeedIn,
        float wallSearchDistance,
        __m128 *dodgingPenaltyIn,
        hkVector4f *localGoalPlane)
{
  hkVector4f v12; // xmm1
  hkVector4f *m_elements; // rdi
  hkVector4f *v14; // rsi
  hkVector4f *v15; // r14
  __m128 m_quad; // xmm7
  __m128 v18; // xmm6
  __m128 v19; // xmm8
  __m128 m_real; // xmm10
  __m128 v21; // xmm1
  __m128 v22; // xmm0
  __m128 v23; // xmm3
  __m128 v24; // xmm11
  __m128 v25; // xmm12
  __m128 v26; // xmm9
  __m128 v27; // xmm6
  __m128 v28; // xmm4
  __m128 v29; // xmm9
  __m128 v30; // xmm13
  __m128 v31; // xmm3
  __m128 v32; // xmm5
  signed __int64 v33; // rsi
  __int64 v34; // rcx
  __m128 v35; // xmm1
  __m128 v36; // xmm14
  __m128 v37; // xmm1
  __m128 v38; // xmm15
  const __m128i *v39; // rax
  signed __int64 v40; // r14
  __m128 v41; // xmm8
  __m128 v42; // xmm7
  __m128 v43; // xmm1
  __m128 v44; // xmm2
  __m128 v45; // xmm8
  __m128 v46; // xmm0
  hkVector4f v47; // xmm2
  __m128 v48; // xmm1
  __m128 v49; // xmm7
  __m128 v50; // xmm5
  __m128 v51; // xmm4
  __m128 v52; // xmm2
  __m128 v53; // xmm6
  __m128i v54; // xmm0
  __m128i v55; // xmm1
  __m128i v56; // xmm2
  __m128i v57; // xmm0
  __m128 v58; // xmm0
  __m128 v59; // xmm3
  __m128 v60; // xmm3
  __m128i si128; // xmm1
  __m128 v62; // xmm3
  __m128i v63; // xmm2
  __m128 v64; // xmm3
  __m128i v65; // xmm0
  __m128 v66; // xmm0
  __m128 v67; // xmm1
  __int64 v68; // rcx
  hkSimdFloat32 rightFactorOut; // [rsp+30h] [rbp-C8h] BYREF
  hkSimdFloat32 forwardFactorOut; // [rsp+40h] [rbp-B8h] BYREF
  __m128 v71; // [rsp+50h] [rbp-A8h]
  hkSimdFloat32 searchDistance; // [rsp+60h] [rbp-98h] BYREF
  _BYTE v73[24]; // [rsp+70h] [rbp-88h]
  __m128i v74; // [rsp+88h] [rbp-70h]
  hkaiVelocityCandidateGenerator velocityCandidatesIna; // [rsp+98h] [rbp-60h] BYREF
  __m128 v76; // [rsp+F8h] [rbp+0h]
  __m128 v77; // [rsp+108h] [rbp+10h]
  __m128 v78; // [rsp+118h] [rbp+20h]
  __m128 v79; // [rsp+128h] [rbp+30h]
  __m128 v80; // [rsp+138h] [rbp+40h]
  __m128i v81; // [rsp+148h] [rbp+50h] BYREF
  __m128 v82; // [rsp+158h] [rbp+60h]
  __m128 *v83; // [rsp+238h] [rbp+140h]

  v12.m_quad = (__m128)velocityCandidatesIn->m_firstBlockRight;
  m_elements = staticTtcsIn->m_scores.m_elements;
  v14 = dynamicTtcsIn->m_scores.m_elements;
  v15 = bonusesIn->m_scores.m_elements;
  m_quad = velocityCandidatesIn->m_forward.m_quad;
  v18 = _mm_shuffle_ps((__m128)LODWORD(collisionPenaltyIn), (__m128)LODWORD(collisionPenaltyIn), 0);
  v19 = velocityCandidatesIn->m_right.m_quad;
  *(_OWORD *)&velocityCandidatesIna.m_template = *(_OWORD *)&velocityCandidatesIn->m_template;
  m_real = velocityCandidatesIn->m_maxSpeed.m_real;
  velocityCandidatesIna.m_firstBlockForward = velocityCandidatesIn->m_firstBlockForward;
  v78 = _mm_shuffle_ps((__m128)LODWORD(wallFollowingAngle), (__m128)LODWORD(wallFollowingAngle), 0);
  velocityCandidatesIna.m_firstBlockRight = (hkVector4f)v12.m_quad;
  v21 = _mm_rcp_ps(v18);
  velocityCandidatesIna.m_forward.m_quad = m_quad;
  velocityCandidatesIna.m_right.m_quad = v19;
  v22 = (__m128)LODWORD(radialMultiplier);
  velocityCandidatesIna.m_maxSpeed.m_real = m_real;
  v82 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, v21)), v21);
  v22.m128_f32[0] = `anonymous namespace::calcWallFollowingPenaltyFromAngle(radialMultiplier);
  v23 = _mm_rcp_ps(m_real);
  v24 = _mm_shuffle_ps((__m128)(unsigned int)bonusVector, (__m128)(unsigned int)bonusVector, 0);
  v25 = (__m128)xmmword_141A712F0;
  v26 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v18);
  v27 = query.m_quad;
  v76 = HKAI_LOCAL_STEERING_MIN_TTC.m_real;
  v28 = query.m_quad;
  *(hkVector4f *)v73 = (hkVector4f)query.m_quad;
  v29 = _mm_mul_ps(v26, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(m_real, v23)), v23));
  v74 = 0i64;
  if ( radialMultiplier <= 0.0 )
    goto LABEL_6;
  searchDistance.m_real = _mm_shuffle_ps((__m128)LODWORD(desiredSpeedIn), (__m128)LODWORD(desiredSpeedIn), 0);
  if ( !hkaiVelocityCandidateScoringUtil::calcWallFollowingDir(
          &velocityCandidatesIna,
          staticTtcsIn,
          &searchDistance,
          radialMultiplier,
          &forwardFactorOut,
          &rightFactorOut)
    || (v30 = forwardFactorOut.m_real, forwardFactorOut.m_real.m128_f32[0] < (float)(0.0 - v29.m128_f32[0])) )
  {
    v28 = *(__m128 *)v73;
    m_real = velocityCandidatesIna.m_maxSpeed.m_real;
    v19 = velocityCandidatesIna.m_right.m_quad;
    m_quad = velocityCandidatesIna.m_forward.m_quad;
    v27 = query.m_quad;
LABEL_6:
    v31 = v24;
    v30 = v28;
    goto LABEL_7;
  }
  m_real = velocityCandidatesIna.m_maxSpeed.m_real;
  v19 = velocityCandidatesIna.m_right.m_quad;
  m_quad = velocityCandidatesIna.m_forward.m_quad;
  v31 = rightFactorOut.m_real;
  v27 = query.m_quad;
  v28 = *(__m128 *)v73;
LABEL_7:
  v32 = velocityCandidatesIna.m_firstBlockForward.m_quad;
  v33 = (char *)v14 - (char *)m_elements;
  v34 = 32i64;
  forwardFactorOut.m_real = v31;
  rightFactorOut.m_real = (__m128)velocityCandidatesIna.m_firstBlockForward;
  v35 = _mm_mul_ps(m_quad, *v83);
  v36 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)), _mm_shuffle_ps(v35, v35, 170));
  v37 = _mm_mul_ps(v19, *v83);
  v38 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)), _mm_shuffle_ps(v37, v37, 170));
  v39 = (const __m128i *)(velocityCandidatesIna.m_template + 8);
  v40 = (char *)v15 - (char *)m_elements;
  v41 = _mm_mul_ps(v19, *dodgingPenaltyIn);
  v42 = _mm_mul_ps(m_quad, *dodgingPenaltyIn);
  v43 = _mm_shuffle_ps(*dodgingPenaltyIn, *dodgingPenaltyIn, 255);
  *(__m128 *)&v73[8] = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)),
                         _mm_shuffle_ps(v42, v42, 170));
  v44 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)), _mm_shuffle_ps(v41, v41, 170));
  v45 = *(__m128 *)&v73[8];
  v46 = _mm_sub_ps((__m128)0i64, v43);
  v79 = v44;
  v47.m_quad = (__m128)velocityCandidatesIna.m_firstBlockRight;
  v48 = _mm_shuffle_ps((__m128)LODWORD(wallSearchDistance), (__m128)LODWORD(wallSearchDistance), 0);
  v77 = v46;
  v71 = velocityCandidatesIna.m_firstBlockRight.m_quad;
  v80 = v48;
  searchDistance.m_real = 0i64;
  v81 = 0i64;
  do
  {
    v49 = _mm_max_ps(_mm_min_ps(m_elements->m_quad, *(__m128 *)((char *)&m_elements->m_quad + v33)), v76);
    v50 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v32, v28), _mm_mul_ps(v47.m_quad, v24)), (__m128)xmmword_141A710D0);
    v51 = _mm_sub_ps(
            _mm_mul_ps(
              _mm_add_ps(_mm_mul_ps(v47.m_quad, v31), _mm_mul_ps(rightFactorOut.m_real, v30)),
              (__m128)xmmword_141A710D0),
            v29);
    v52 = _mm_cmplt_ps(v50, v51);
    v53 = _mm_add_ps(
            _mm_add_ps(
              _mm_sub_ps(
                _mm_or_ps(_mm_andnot_ps(v52, v50), _mm_and_ps(v51, v52)),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_or_ps(_mm_andnot_ps(v52, v48), _mm_and_ps(v52, v27)), _mm_mul_ps(v71, v71)),
                      _mm_mul_ps(rightFactorOut.m_real, rightFactorOut.m_real)),
                    v82),
                  m_real)),
              _mm_mul_ps(rightFactorOut.m_real, v36)),
            _mm_mul_ps(v71, v38));
    v54 = _mm_load_si128(&v81);
    v55 = _mm_unpacklo_epi8(_mm_loadl_epi64(v39), v54);
    v56 = _mm_unpackhi_epi16(v55, v54);
    v57 = _mm_unpacklo_epi16(v55, v54);
    v32 = _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v57, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v57, 0x10u), 0x10u))),
              (__m128)xmmword_141A71230),
            g_vectorfConstants[0]);
    rightFactorOut.m_real = v32;
    v71 = _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v56, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v56, 0x10u), 0x10u))),
              (__m128)xmmword_141A71230),
            g_vectorfConstants[0]);
    v58 = _mm_rcp_ps(v49);
    v59 = *(__m128 *)((char *)&m_elements->m_quad + v40);
    v39 = (const __m128i *)((char *)v39 + 8);
    ++m_elements;
    v60 = _mm_add_ps(v59, _mm_mul_ps(v53, m_real));
    v27 = query.m_quad;
    si128 = _mm_load_si128((const __m128i *)&searchDistance);
    v62 = _mm_sub_ps(
            v60,
            _mm_andnot_ps(
              _mm_cmplt_ps(
                _mm_mul_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(v71, v79), _mm_mul_ps(v32, v45)), m_real), v49),
                v77),
              _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v49, v58)), v58), v78)));
    searchDistance.m_real = (__m128)_mm_add_epi32(si128, (__m128i)xmmword_141A72090);
    v28 = *(__m128 *)v73;
    v63 = (__m128i)_mm_cmplt_ps(v25, v62);
    v64 = _mm_and_ps(v62, (__m128)v63);
    v65 = _mm_or_si128(_mm_andnot_si128(v63, v74), _mm_and_si128(si128, v63));
    v48 = v80;
    v74 = v65;
    *(__m128i *)&v73[8] = v65;
    v66 = _mm_andnot_ps((__m128)v63, v25);
    v47.m_quad = v71;
    v25 = _mm_or_ps(v66, v64);
    v31 = forwardFactorOut.m_real;
    --v34;
  }
  while ( v34 );
  v67 = _mm_max_ps(_mm_shuffle_ps(v25, v25, 78), v25);
  v68 = _mm_movemask_ps(_mm_cmple_ps(_mm_max_ps(v67, _mm_shuffle_ps(v67, v67, 177)), v25));
  hkaiVelocityCandidateGenerator::generateCandidate(
    &velocityCandidatesIna,
    (unsigned __int8)hkVector4Comparison_maskToLastIndex[v68]
  + 4 * *(_DWORD *)&v73[4 * (unsigned __int8)hkVector4Comparison_maskToLastIndex[v68] + 8],
    localGoalPlane);
}

