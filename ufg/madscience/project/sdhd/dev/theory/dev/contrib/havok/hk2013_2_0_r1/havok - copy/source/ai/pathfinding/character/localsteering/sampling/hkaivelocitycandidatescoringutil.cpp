// File Line: 25
// RVA: 0x15C40B0
void dynamic_initializer_for__HKAI_LOCAL_STEERING_MIN_TTC__()
{
  HKAI_LOCAL_STEERING_MIN_TTC.m_real = (__m128)xmmword_141A71230;
}

// File Line: 36
// RVA: 0xC2A670
bool __fastcall hkaiVelocityCandidateScoringUtil::scoreSphereObstacle(hkaiAvoidanceSolver::SteeringAgent *agent, hkaiAvoidanceSolver::SphereObstacle *sphereObstacle, hkVector4f *up, hkSimdFloat32 *penetrationPenalty, hkaiVelocityCandidateGenerator *velocityCandidates, hkaiVelocityCandidateScores *timesToCollision, hkaiVelocityCandidateScores *bonuses, hkVector4f *bonusVector)
{
  __m128 v8; // xmm5
  hkSphere v9; // xmm4
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  hkVector4f v13; // xmm3
  __m128 v14; // xmm4
  __m128 v15; // xmm1
  __m128 v17; // [rsp+40h] [rbp-38h]
  __m128 v18; // [rsp+50h] [rbp-28h]
  __m128 v19; // [rsp+60h] [rbp-18h]

  v8 = up->m_quad;
  v9.m_pos.m_quad = (__m128)sphereObstacle->m_sphere;
  v10 = _mm_mul_ps(up->m_quad, agent->m_position.m_quad);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_mul_ps(up->m_quad, sphereObstacle->m_sphere.m_pos.m_quad);
  v19 = _mm_sub_ps(agent->m_position.m_quad, _mm_mul_ps(v11, up->m_quad));
  v13.m_quad = (__m128)sphereObstacle->m_velocity;
  v14 = _mm_sub_ps(
          v9.m_pos.m_quad,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
              _mm_shuffle_ps(v12, v12, 170)),
            v8));
  v15 = _mm_mul_ps(v8, v13.m_quad);
  v18 = _mm_shuffle_ps(
          v14,
          _mm_unpackhi_ps(
            v14,
            _mm_add_ps(
              _mm_shuffle_ps(sphereObstacle->m_sphere.m_pos.m_quad, sphereObstacle->m_sphere.m_pos.m_quad, 255),
              _mm_shuffle_ps((__m128)LODWORD(agent->m_radius), (__m128)LODWORD(agent->m_radius), 0))),
          196);
  v17 = _mm_sub_ps(
          v13.m_quad,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
              _mm_shuffle_ps(v15, v15, 170)),
            v8));
  return hkaiVelocityCandidateScoringUtil::scoreMovingSphere(
           (hkVector4f *)&v19,
           (hkSphere *)&v18,
           (hkVector4f *)&v17,
           penetrationPenalty,
           velocityCandidates,
           timesToCollision,
           bonuses,
           bonusVector);
}

// File Line: 71
// RVA: 0xC2A770
bool __fastcall hkaiVelocityCandidateScoringUtil::scoreAgentObstacle(hkaiAvoidanceSolver::SteeringAgent *thisAgent, hkaiAvoidanceSolver::ObstacleAgent *otherAgent, hkVector4f *up, hkaiVelocityCandidateGenerator *velocityCandidatesIn, hkSimdFloat32 *sidednessChangingPenalty, hkSimdFloat32 *penetrationPenalty, hkaiVelocityCandidateScores *timesToCollision, hkaiVelocityCandidateScores *bonuses, hkVector4f *bonusVector)
{
  __int128 *v9; // r10
  __m128 v11; // xmm3
  signed int v12; // er9
  hkVector4f v13; // xmm8
  __m128 v14; // xmm7
  __m128 v15; // xmm1
  hkVector4f v16; // xmm12
  __m128 v17; // xmm7
  __m128 v18; // xmm2
  __m128 v19; // xmm5
  __m128 v20; // xmm1
  __m128 v21; // xmm13
  __m128 v22; // xmm2
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  __m128 v27; // xmm12
  __m128 v28; // xmm8
  __m128 v29; // xmm11
  __m128 v30; // xmm1
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  __m128 v33; // xmm6
  __m128 v34; // xmm3
  __m128 v35; // xmm1
  __m128 v36; // xmm4
  __m128 v37; // xmm0
  __m128 v38; // xmm6
  __m128 v39; // ST10_16
  __m128 v40; // xmm9
  __m128 v41; // xmm14
  __m128 v42; // xmm15
  __m128 v43; // xmm12
  __m128 v44; // xmm8
  __m128 v45; // xmm2
  __m128 v46; // xmm3
  __m128 v47; // xmm1
  __m128 v48; // xmm1
  __m128 v49; // xmm2
  __m128 v50; // xmm1
  __m128 v51; // xmm3
  __m128 v52; // xmm4
  __m128 v53; // xmm1
  __m128 v54; // xmm2
  __m128 v55; // ST20_16
  __m128 v56; // xmm1
  __m128 v57; // xmm2
  __m128 v58; // xmm4
  __m128 v59; // xmm3
  __m128 v60; // xmm1
  __m128 v61; // xmm1
  __m128 v62; // xmm2
  __m128 v63; // xmm1
  __m128 v64; // xmm2
  __m128 v65; // xmm2
  __m128 v66; // xmm1
  hkVector4f *v67; // rcx
  __m128 v68; // xmm3
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm1
  __m128 v72; // xmm4
  __m128 v73; // xmm1
  __m128 v74; // xmm2
  __m128 v75; // xmm9
  __m128 v76; // xmm8
  __m128 v77; // xmm1
  __m128 v78; // xmm0
  __m128 v79; // xmm14
  __m128 v80; // xmm7
  __m128 v81; // xmm0
  __m128 v82; // xmm1
  __m128 v83; // xmm15
  __m128 v84; // xmm6
  __m128 v85; // xmm7
  __m128 v86; // xmm8
  __m128 v87; // xmm1
  __m128 v88; // xmm2
  __m128 v89; // xmm9
  __m128 v90; // xmm2
  __m128 v91; // xmm9
  __m128 v92; // xmm1
  __m128 v93; // xmm4
  __m128 v94; // xmm1
  __m128 v95; // xmm3
  __m128 v96; // xmm1
  __m128 v97; // xmm2
  signed __int64 v98; // rax
  __m128 v99; // xmm12
  __int64 v100; // rdx
  __m128 v101; // xmm0
  __m128 v102; // xmm9
  __m128 v103; // xmm7
  __m128 v104; // xmm5
  __m128i v105; // xmm2
  __m128i v106; // xmm1
  __m128i v107; // xmm2
  __m128 v108; // xmm5
  __m128 v109; // xmm8
  __m128 v110; // xmm1
  __m128 v111; // xmm0
  __m128 v112; // xmm8
  __m128 v113; // xmm7
  __m128 v114; // xmm1
  __m128 v115; // xmm0
  const __m128i *v116; // rdx
  char *v117; // r8
  signed __int64 v118; // rax
  __m128 v119; // xmm1
  __m128 v120; // xmm6
  __m128i v121; // xmm2
  __m128i v122; // xmm5
  __m128 v123; // xmm9
  __m128 v124; // xmm6
  __m128i v125; // xmm1
  __m128i v126; // xmm2
  __m128i v127; // xmm1
  __m128 v128; // xmm3
  __m128 v129; // xmm6
  __m128 v130; // xmm3
  __m128 v131; // xmm9
  __m128 v132; // xmm6
  __m128 v133; // xmm1
  __m128 v134; // xmm2
  __m128 v135; // xmm6
  __m128 v136; // xmm2
  __m128 v137; // xmm0
  __m128 v138; // [rsp+0h] [rbp-1B8h]
  __m128 v139; // [rsp+0h] [rbp-1B8h]
  __m128 v140; // [rsp+10h] [rbp-1A8h]
  __m128 v141; // [rsp+10h] [rbp-1A8h]
  __m128 v142; // [rsp+20h] [rbp-198h]
  __m128 v143; // [rsp+20h] [rbp-198h]
  __m128 v144; // [rsp+30h] [rbp-188h]
  __m128 v145; // [rsp+30h] [rbp-188h]
  __m128 v146; // [rsp+30h] [rbp-188h]
  __m128 v147; // [rsp+40h] [rbp-178h]
  __m128 v148; // [rsp+50h] [rbp-168h]
  __m128 v149; // [rsp+60h] [rbp-158h]
  __m128 v150; // [rsp+70h] [rbp-148h]
  __m128 v151; // [rsp+80h] [rbp-138h]
  __m128 v152; // [rsp+90h] [rbp-128h]
  __m128 v153; // [rsp+A0h] [rbp-118h]
  __int128 v154; // [rsp+B0h] [rbp-108h]

  v9 = (__int128 *)velocityCandidatesIn;
  if ( otherAgent->m_weight == 0.0 )
    return 0;
  v11 = up->m_quad;
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
  v18 = _mm_add_ps(
          _mm_shuffle_ps((__m128)LODWORD(thisAgent->m_radius), (__m128)LODWORD(thisAgent->m_radius), 0),
          _mm_shuffle_ps((__m128)LODWORD(otherAgent->m_radius), (__m128)LODWORD(otherAgent->m_radius), 0));
  v19 = _mm_mul_ps(v17, v17);
  v149 = v17;
  v144 = v18;
  v20 = _mm_mul_ps(v16.m_quad, v11);
  v21 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
            _mm_shuffle_ps(v19, v19, 170)),
          _mm_mul_ps(v18, v18));
  v22 = _mm_shuffle_ps(v20, v20, 85);
  v23 = _mm_shuffle_ps(v20, v20, 0);
  v24 = _mm_shuffle_ps(v20, v20, 170);
  if ( v21.m128_f32[0] <= 0.0 )
    v12 = 1;
  v25 = _mm_add_ps(_mm_add_ps(v22, v23), v24);
  v26 = _mm_mul_ps(v13.m_quad, v11);
  v27 = _mm_sub_ps(v16.m_quad, _mm_mul_ps(v25, v11));
  v28 = _mm_sub_ps(
          v13.m_quad,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
              _mm_shuffle_ps(v26, v26, 170)),
            v11));
  v138 = _mm_sub_ps(v27, v28);
  if ( thisAgent->m_priority >= otherAgent->m_priority )
  {
    v31 = _mm_mul_ps(v27, v27);
    v32 = _mm_shuffle_ps((__m128)LODWORD(otherAgent->m_weight), (__m128)LODWORD(otherAgent->m_weight), 0);
    v33 = _mm_sub_ps(query.m_quad, v32);
    v34 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
            _mm_shuffle_ps(v31, v31, 170));
    v35 = _mm_mul_ps(v28, v28);
    v36 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
            _mm_shuffle_ps(v35, v35, 170));
    if ( v34.m128_f32[0] > v36.m128_f32[0] )
    {
      v33 = _mm_mul_ps(v33, _mm_andnot_ps(_mm_cmpleps(v36, (__m128)0i64), _mm_mul_ps(_mm_rsqrt_ps(v36), v36)));
      v32 = _mm_mul_ps(v32, _mm_andnot_ps(_mm_cmpleps(v34, (__m128)0i64), _mm_mul_ps(_mm_rsqrt_ps(v34), v34)));
    }
    if ( v32.m128_f32[0] == 0.0 )
      return 0;
    v37 = _mm_rcp_ps(v32);
    v29 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v32, v37)), v37), _mm_add_ps(v32, v33));
    v30 = _mm_rcp_ps(v29);
  }
  else
  {
    v29 = query.m_quad;
    v30 = 0i64;
  }
  v38 = (__m128)v9[5];
  v39 = v30;
  v40 = (__m128)v9[4];
  v41 = (__m128)v9[1];
  v42 = (__m128)v9[2];
  v147 = v38;
  v43 = _mm_sub_ps(_mm_sub_ps(v27, _mm_mul_ps(v29, v27)), v28);
  v44 = (__m128)v9[3];
  v45 = _mm_mul_ps(v42, v43);
  v154 = *v9;
  v46 = _mm_mul_ps(_mm_andnot_ps(_mm_cmpeqps(v38, (__m128)0i64), _mm_rcp_ps(v38)), v30);
  v47 = _mm_mul_ps(v41, v43);
  v148 = _mm_mul_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
             _mm_shuffle_ps(v47, v47, 170)),
           v46);
  v48 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
            _mm_shuffle_ps(v45, v45, 170)),
          v46);
  v49 = _mm_mul_ps(v42, v17);
  v150 = v48;
  v50 = _mm_mul_ps(v41, v17);
  v51 = _mm_mul_ps(v38, v29);
  v151 = _mm_mul_ps(v51, v51);
  v153 = _mm_mul_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v50, v50, 0), _mm_shuffle_ps(v50, v50, 85)),
             _mm_shuffle_ps(v50, v50, 170)),
           v51);
  v52 = _mm_mul_ps(v138, v138);
  v152 = _mm_mul_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)),
             _mm_shuffle_ps(v49, v49, 170)),
           v51);
  v53 = _mm_mul_ps(v138, v17);
  v54 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v53, v53, 85), _mm_shuffle_ps(v53, v53, 0)), _mm_shuffle_ps(v53, v53, 170));
  v55 = _mm_andnot_ps(
          _mm_cmpeqps(v54, (__m128)0i64),
          _mm_mul_ps(
            _mm_rcp_ps(v54),
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                _mm_shuffle_ps(v52, v52, 170)),
              sidednessChangingPenalty->m_real)));
  v56 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)), _mm_shuffle_ps(v52, v52, 170));
  v57 = _mm_rsqrt_ps(v56);
  v58 = _mm_shuffle_ps(up->m_quad, up->m_quad, 201);
  v59 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v56, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v57, v56), v57)),
              _mm_mul_ps(v57, *(__m128 *)_xmm))),
          v138);
  v60 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), up->m_quad), _mm_mul_ps(v59, v58));
  v61 = _mm_mul_ps(_mm_shuffle_ps(v60, v60, 201), v17);
  v62 = _mm_max_ps(
          (__m128)_mm_srli_epi32(
                    _mm_slli_epi32(
                      (__m128i)_mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v61, v61, 85), _mm_shuffle_ps(v61, v61, 0)),
                                 _mm_shuffle_ps(v61, v61, 170)),
                      1u),
                    1u),
          v144);
  v63 = _mm_rcp_ps(v62);
  v142 = _mm_mul_ps(_mm_mul_ps(v55, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v62, v63)), v63)), v144);
  v64 = _mm_sub_ps(_mm_mul_ps(v17, v58), _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), up->m_quad));
  v65 = _mm_shuffle_ps(v64, v64, 201);
  v66 = _mm_mul_ps(v65, v138);
  v67 = timesToCollision->m_scores.m_elements;
  v68 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(
                    _mm_srli_epi32(
                      (__m128i)_mm_cmpltps(
                                 _mm_add_ps(
                                   _mm_add_ps(_mm_shuffle_ps(v66, v66, 85), _mm_shuffle_ps(v66, v66, 0)),
                                   _mm_shuffle_ps(v66, v66, 170)),
                                 (__m128)0i64),
                      0x1Fu),
                    0x1Fu),
          v65);
  v69 = _mm_mul_ps(v38, v68);
  v70 = _mm_mul_ps(v68, v43);
  v71 = _mm_mul_ps(v41, v69);
  v72 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v71, v71, 85), _mm_shuffle_ps(v71, v71, 0)), _mm_shuffle_ps(v71, v71, 170));
  v73 = _mm_mul_ps(v42, v69);
  v145 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
           _mm_shuffle_ps(v73, v73, 170));
  v74 = _mm_cmpleps((__m128)0i64, v142);
  v140 = _mm_or_ps(
           _mm_andnot_ps(
             v74,
             _mm_mul_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v70, v70, 85), _mm_shuffle_ps(v70, v70, 0)),
                 _mm_shuffle_ps(v70, v70, 170)),
               _mm_sub_ps((__m128)0i64, v39))),
           _mm_and_ps((__m128)xmmword_141A712F0, v74));
  if ( v12 )
  {
    v75 = _mm_mul_ps(v40, v38);
    v76 = _mm_mul_ps(v44, v38);
    v77 = _mm_shuffle_ps(v42, v42, 0);
    v146 = _mm_shuffle_ps(v41, v41, 0);
    v139 = v77;
    v78 = _mm_shuffle_ps(v41, v41, 85);
    v79 = _mm_shuffle_ps(v41, v41, 170);
    v141 = v78;
    v80 = _mm_mul_ps(v76, v78);
    v81 = _mm_mul_ps(v75, v77);
    v82 = _mm_shuffle_ps(v42, v42, 85);
    v83 = _mm_shuffle_ps(v42, v42, 170);
    v84 = _mm_add_ps(_mm_mul_ps(v76, v146), v81);
    v143 = v82;
    v85 = _mm_add_ps(v80, _mm_mul_ps(v75, v82));
    v86 = _mm_add_ps(_mm_mul_ps(v76, v79), _mm_mul_ps(v75, v83));
    v87 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
            _mm_shuffle_ps(v19, v19, 170));
    v88 = _mm_rsqrt_ps(v87);
    v89 = _mm_andnot_ps(
            _mm_cmpleps(v87, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v88, v87), v88)),
              _mm_mul_ps(v88, *(__m128 *)_xmm)));
    v90 = _mm_sub_ps((__m128)0i64, v21);
    v91 = _mm_mul_ps(v89, v149);
    v92 = _mm_rsqrt_ps(v90);
    v93 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v92, v90), v92)), _mm_mul_ps(v92, *(__m128 *)_xmm));
    v94 = _mm_rcp_ps(v29);
    v95 = _mm_mul_ps(
            _mm_andnot_ps(_mm_cmpleps(v90, (__m128)0i64), _mm_mul_ps(v93, v90)),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v29, v94)), v94));
    v96 = _mm_shuffle_ps(v43, v43, 0);
    v150 = v96;
    v97 = _mm_shuffle_ps(v43, v43, 85);
    bonusVector->m_quad = _mm_add_ps(_mm_mul_ps(v91, _mm_mul_ps(v95, penetrationPenalty->m_real)), bonusVector->m_quad);
    v148 = v97;
    v98 = 32i64;
    v99 = _mm_shuffle_ps(v43, v43, 170);
    v100 = v154 + 8;
    v151 = _mm_shuffle_ps(v91, v91, 85);
    v101 = _mm_shuffle_ps(v91, v91, 0);
    v102 = _mm_shuffle_ps(v91, v91, 170);
    v149 = v101;
    do
    {
      ++v67;
      v100 += 8i64;
      v103 = _mm_add_ps(_mm_mul_ps(v85, v29), v97);
      v104 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v84, v29), v96), v149);
      v105 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(v100 - 8)), (__m128i)0i64);
      v106 = _mm_unpacklo_epi16(v105, (__m128i)0i64);
      v107 = _mm_unpackhi_epi16(v105, (__m128i)0i64);
      v108 = _mm_cmpleps(
               _mm_add_ps(
                 _mm_add_ps(v104, _mm_mul_ps(v103, v151)),
                 _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v86, v29), v99), v102)),
               (__m128)0i64);
      v109 = _mm_mul_ps(
               _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srli_epi32(v106, 0x10u)),
                   (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                 _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v106, 0x10u), 0x10u))),
               (__m128)xmmword_141A71230);
      v110 = _mm_cvtepi32_ps(_mm_srli_epi32(v107, 0x10u));
      v111 = _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v107, 0x10u), 0x10u));
      v97 = v148;
      v112 = _mm_mul_ps(_mm_add_ps(v109, g_vectorfConstants[0]), v147);
      v113 = v112;
      v114 = _mm_mul_ps(
               _mm_add_ps(
                 _mm_mul_ps(
                   _mm_add_ps(_mm_mul_ps(v110, (__m128)`hkIntVector::convertU32ToF32::`2::two16), v111),
                   (__m128)xmmword_141A71230),
                 g_vectorfConstants[0]),
               v147);
      v84 = _mm_add_ps(_mm_mul_ps(v112, v146), _mm_mul_ps(v114, v139));
      v115 = v114;
      v86 = _mm_add_ps(_mm_mul_ps(v112, v79), _mm_mul_ps(v114, v83));
      v96 = v150;
      v85 = _mm_add_ps(_mm_mul_ps(v113, v141), _mm_mul_ps(v115, v143));
      v67[-1].m_quad = _mm_or_ps(
                         _mm_and_ps(v108, HKAI_LOCAL_STEERING_MIN_TTC.m_real),
                         _mm_andnot_ps(v108, v67[-1].m_quad));
      --v98;
    }
    while ( v98 );
  }
  else
  {
    v116 = (const __m128i *)(v154 + 8);
    v117 = (char *)((char *)bonuses->m_scores.m_elements - (char *)v67);
    v118 = 32i64;
    _mm_store_si128((__m128i *)&v147, _mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
    do
    {
      v119 = _mm_add_ps(v44, v148);
      v120 = _mm_add_ps(v40, v150);
      v121 = _mm_unpacklo_epi8(_mm_loadl_epi64(v116), (__m128i)0i64);
      v122 = (__m128i)_mm_mul_ps(_mm_add_ps(_mm_mul_ps(v120, v120), _mm_mul_ps(v119, v119)), v151);
      v123 = _mm_cmpltps(_mm_add_ps(_mm_mul_ps(v40, v145), _mm_mul_ps(v44, v72)), v140);
      v124 = _mm_add_ps(_mm_mul_ps(v120, v152), _mm_mul_ps(v119, v153));
      v125 = v121;
      v126 = _mm_unpackhi_epi16(v121, (__m128i)0i64);
      v127 = _mm_unpacklo_epi16(v125, (__m128i)0i64);
      v128 = _mm_mul_ps(v124, v124);
      v129 = _mm_xor_ps(v124, v147);
      v130 = _mm_sub_ps(v128, _mm_mul_ps((__m128)v122, v21));
      *(__m128 *)((char *)&v67->m_quad + (_QWORD)v117) = _mm_or_ps(
                                                           _mm_and_ps(
                                                             _mm_add_ps(
                                                               *(__m128 *)((char *)&v67->m_quad + (_QWORD)v117),
                                                               v142),
                                                             v123),
                                                           _mm_andnot_ps(
                                                             v123,
                                                             *(__m128 *)((char *)&v67->m_quad + (_QWORD)v117)));
      v44 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_cvtepi32_ps(_mm_srli_epi32(v127, 0x10u)),
                    (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                  _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v127, 0x10u), 0x10u))),
                (__m128)xmmword_141A71230),
              g_vectorfConstants[0]);
      v131 = _mm_mul_ps(
               _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srli_epi32(v126, 0x10u)),
                   (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                 _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v126, 0x10u), 0x10u))),
               (__m128)xmmword_141A71230);
      v132 = _mm_sub_ps(v129, _mm_andnot_ps(_mm_cmpleps(v130, (__m128)0i64), _mm_mul_ps(_mm_rsqrt_ps(v130), v130)));
      v133 = _mm_cmpeqps((__m128)v122, (__m128)0i64);
      v134 = _mm_and_ps(_mm_cmpltps((__m128)0i64, v132), _mm_cmpleps((__m128)0i64, v130));
      v40 = _mm_add_ps(v131, g_vectorfConstants[0]);
      v135 = _mm_mul_ps(
               v132,
               _mm_or_ps(
                 _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v122, 0x1Fu), 0x1Fu), (__m128)_xmm), v133),
                 _mm_andnot_ps(v133, _mm_rcp_ps((__m128)v122))));
      v136 = _mm_and_ps(v134, _mm_cmpltps(v135, v67->m_quad));
      v137 = _mm_or_ps(_mm_andnot_ps(v136, v67->m_quad), _mm_and_ps(v136, v135));
      ++v67;
      v116 = (const __m128i *)((char *)v116 + 8);
      v67[-1] = (hkVector4f)v137;
      --v118;
    }
    while ( v118 );
  }
  return v12 != 0;
}

// File Line: 529
// RVA: 0xC2B1B0
bool __fastcall hkaiVelocityCandidateScoringUtil::scoreBoundaryObstacle(hkaiAvoidanceSolver::SteeringAgent *agent, hkaiAvoidanceSolver::BoundaryObstacle *boundaryObstacle, hkVector4f *up, hkSimdFloat32 *thresholdDistanceSquared, hkSimdFloat32 *penetrationPenalty, hkaiVelocityCandidateGenerator *velocityCandidates, hkaiVelocityCandidateScores *timesToCollision, hkaiVelocityCandidateScores *bonuses, hkVector4f *bonusVector)
{
  __m128 v9; // xmm5
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
  hkSimdFloat32 totalRadius; // [rsp+50h] [rbp-68h]
  hkVector4f c2; // [rsp+60h] [rbp-58h]
  hkVector4f c1; // [rsp+70h] [rbp-48h]
  hkVector4f position; // [rsp+80h] [rbp-38h]

  v9 = up->m_quad;
  v10.m_quad = (__m128)boundaryObstacle->m_end;
  v11 = _mm_shuffle_ps((__m128)LODWORD(agent->m_boundaryRadius), (__m128)LODWORD(agent->m_boundaryRadius), 0);
  v12 = _mm_mul_ps(up->m_quad, agent->m_position.m_quad);
  v13.m_quad = (__m128)boundaryObstacle->m_start;
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v15 = _mm_mul_ps(up->m_quad, v10.m_quad);
  position.m_quad = _mm_sub_ps(agent->m_position.m_quad, _mm_mul_ps(v14, up->m_quad));
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_mul_ps(v9, v13.m_quad);
  v18 = _mm_sub_ps(v10.m_quad, _mm_mul_ps(v16, v9));
  c1.m_quad = _mm_shuffle_ps(v18, _mm_unpackhi_ps(v18, v11), 196);
  v19 = _mm_sub_ps(
          v13.m_quad,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170)),
            v9));
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
  v27 = _mm_cmpltps(v26, query.m_quad);
  v28 = _mm_sub_ps(
          v20,
          _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v26, v27), _mm_andnot_ps(v27, query.m_quad))), v21));
  v29 = _mm_mul_ps(v28, v28);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 170))) > thresholdDistanceSquared->m_real.m128_f32[0] )
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
bool __fastcall hkaiVelocityCandidateScoringUtil::scoreStaticCapsule(hkVector4f *position, hkVector4f *c1, hkVector4f *c2, hkSimdFloat32 *totalRadius, hkSimdFloat32 *penetrationPenalty, hkaiVelocityCandidateGenerator *velocityCandidatesIn, hkaiVelocityCandidateScores *timesToCollision, hkaiVelocityCandidateScores *bonuses, hkVector4f *bonusVector)
{
  __m128 v9; // xmm5
  hkVector4f *v10; // r10
  __m128 v11; // xmm2
  __m128 v12; // xmm3
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
  hkVector4f *v27; // rcx
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
  signed __int64 v41; // rdx
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
  signed __int64 v53; // rdx
  __m128 v54; // xmm7
  __m128 v55; // xmm6
  __m128 v56; // xmm4
  const __m128i *v57; // rax
  __m128 v58; // xmm1
  __m128 v59; // xmm3
  __m128 v60; // xmm4
  __m128 v61; // xmm1
  __m128 v62; // xmm2
  __m128 v63; // xmm3
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
  __m128 v75; // xmm1
  hkSphere sphere; // [rsp+40h] [rbp-178h]
  __m128 v77; // [rsp+50h] [rbp-168h]
  __m128 v78; // [rsp+60h] [rbp-158h]
  __m128 v79; // [rsp+70h] [rbp-148h]
  __m128 v80; // [rsp+80h] [rbp-138h]
  __m128 v81; // [rsp+90h] [rbp-128h]
  __m128 v82; // [rsp+A0h] [rbp-118h]
  hkaiVelocityCandidateGenerator velocityCandidates; // [rsp+B0h] [rbp-108h]

  v9 = totalRadius->m_real;
  v10 = position;
  v11 = _mm_sub_ps(position->m_quad, c1->m_quad);
  v12 = velocityCandidatesIn->m_forward.m_quad;
  v13 = velocityCandidatesIn->m_right.m_quad;
  *(_OWORD *)&velocityCandidates.m_template = *(_OWORD *)&velocityCandidatesIn->m_template;
  v14 = velocityCandidatesIn->m_maxSpeed.m_real;
  v15 = velocityCandidatesIn->m_firstBlockForward.m_quad;
  v16 = velocityCandidatesIn->m_firstBlockRight.m_quad;
  velocityCandidates.m_forward.m_quad = v12;
  v17 = _mm_mul_ps(v12, v11);
  velocityCandidates.m_right.m_quad = v13;
  velocityCandidates.m_firstBlockForward.m_quad = v15;
  velocityCandidates.m_firstBlockRight.m_quad = v16;
  velocityCandidates.m_maxSpeed.m_real = v14;
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_mul_ps(v13, v11);
  v20 = _mm_sub_ps(c2->m_quad, c1->m_quad);
  v21 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v22 = _mm_mul_ps(v12, v20);
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)), _mm_shuffle_ps(v22, v22, 170));
  v24 = _mm_mul_ps(v13, v20);
  v80 = v23;
  v25 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)), _mm_shuffle_ps(v24, v24, 170));
  v82 = v25;
  sphere.m_pos.m_quad = _mm_mul_ps(v9, v9);
  if ( v14.m128_f32[0] == 0.0 )
    return 0;
  v78 = _mm_rcp_ps(v14);
  v27 = timesToCollision->m_scores.m_elements;
  v28 = _mm_add_ps(_mm_mul_ps(v25, v25), _mm_mul_ps(v23, v23));
  v29 = _mm_rsqrt_ps(v28);
  v30 = _mm_andnot_ps(
          _mm_cmpleps(v28, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v29), v29)), _mm_mul_ps(*(__m128 *)_xmm, v29)));
  v31 = _mm_mul_ps(v23, v30);
  v32 = _mm_mul_ps(v25, v30);
  v33 = _mm_sub_ps(_mm_mul_ps(v31, v21), _mm_mul_ps(v32, v18));
  LODWORD(v34) = (unsigned int)(2 * v33.m128_i32[0]) >> 1;
  if ( v34 >= v9.m128_f32[0] )
  {
    if ( v33.m128_f32[0] >= 0.0 )
    {
      v50 = v80;
      v51 = v9;
      v52 = _mm_mul_ps(v9, v31);
      v53 = 32i64;
      v54 = query.m_quad;
      v55 = _mm_sub_ps(v21, v52);
      sphere.m_pos.m_quad = _mm_sub_ps((__m128)0i64, sphere.m_pos.m_quad);
      v81 = v55;
      v56 = _mm_add_ps(_mm_mul_ps(v51, v32), v18);
      v57 = (const __m128i *)(velocityCandidates.m_template + 8);
      v79 = v56;
      _mm_store_si128((__m128i *)&v77, _mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
      do
      {
        v58 = _mm_sub_ps(_mm_mul_ps(v16, v50), _mm_mul_ps(v15, v82));
        v59 = _mm_cmpeqps((__m128)0i64, v58);
        v60 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v56, v16), _mm_mul_ps(v55, v15)), _mm_andnot_ps(v59, _mm_rcp_ps(v58)));
        v61 = _mm_cmpltps(v60, v54);
        v62 = _mm_and_ps(_mm_cmpltps(_mm_add_ps(_mm_mul_ps(v16, v82), _mm_mul_ps(v15, v50)), (__m128)0i64), v59);
        v63 = _mm_max_ps(
                _mm_or_ps(_mm_andnot_ps(v62, aabbOut.m_quad), _mm_and_ps(v62, v54)),
                _mm_or_ps(_mm_andnot_ps(v61, v54), _mm_and_ps(v60, v61)));
        v64 = _mm_sub_ps(v21, _mm_mul_ps(v63, v82));
        v65 = _mm_sub_ps(v18, _mm_mul_ps(v63, v50));
        v66 = _mm_add_ps(_mm_mul_ps(v16, v16), _mm_mul_ps(v15, v15));
        v67 = _mm_add_ps(_mm_mul_ps(v64, v16), _mm_mul_ps(v65, v15));
        v68 = _mm_unpacklo_epi8(_mm_loadl_epi64(v57), (__m128i)0i64);
        v69 = _mm_cmpltps(v67, (__m128)0i64);
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
        ++v27;
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
                  _mm_andnot_ps(_mm_cmpeqps((__m128)0i64, v66), _mm_rcp_ps(v66))),
                v78);
        v75 = _mm_and_ps(_mm_cmpltps(v74, v27[-1].m_quad), _mm_and_ps(_mm_cmpltps((__m128)0i64, v73), v69));
        v27[-1].m_quad = _mm_or_ps(_mm_andnot_ps(v75, v27[-1].m_quad), _mm_and_ps(v75, v74));
        --v53;
      }
      while ( v53 );
    }
    return 0;
  }
  v35 = _mm_rcp_ps(v30);
  v36 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v35, v30)), v35);
  v37 = _mm_add_ps(_mm_mul_ps(v32, v21), _mm_mul_ps(v31, v18));
  v38 = _mm_cmpltps(v36, v37);
  v39 = _mm_cmpltps(v37, (__m128)0i64);
  LODWORD(v40) = *(unsigned __int128 *)&_mm_andnot_ps(v38, _mm_and_ps(v37, v39)) | COERCE_UNSIGNED_INT(v36.m128_f32[0] - v37.m128_f32[0]) & v38.m128_i32[0];
  if ( (float)((float)(v40 * v40) + (float)(v34 * v34)) >= sphere.m_pos.m_quad.m128_f32[0] )
  {
    if ( v33.m128_f32[0] >= 0.0 )
    {
      v49 = _mm_or_ps(_mm_andnot_ps(v39, c2->m_quad), _mm_and_ps(c1->m_quad, v39));
      sphere.m_pos.m_quad = _mm_shuffle_ps(v49, _mm_unpackhi_ps(v49, v9), 196);
      return hkaiVelocityCandidateScoringUtil::scoreStaticSphere(
               v10,
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
                            _mm_mul_ps(_mm_sub_ps(v9, v33), penetrationPenalty->m_real)),
                          bonusVector->m_quad);
  v42 = (const __m128i *)(velocityCandidates.m_template + 8);
  v43 = HKAI_LOCAL_STEERING_MIN_TTC.m_real;
  do
  {
    v44 = _mm_loadl_epi64(v42);
    ++v27;
    v42 = (const __m128i *)((char *)v42 + 8);
    v45 = _mm_unpacklo_epi8(v44, (__m128i)0i64);
    v46 = _mm_unpacklo_epi16(v45, (__m128i)0i64);
    v47 = _mm_unpackhi_epi16(v45, (__m128i)0i64);
    v48 = _mm_cmpleps(_mm_sub_ps(_mm_mul_ps(v31, v16), _mm_mul_ps(v32, v15)), (__m128)0i64);
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
    v27[-1].m_quad = _mm_or_ps(_mm_and_ps(v48, v43), _mm_andnot_ps(v48, v27[-1].m_quad));
    --v41;
  }
  while ( v41 );
  return 1;
}

// File Line: 799
// RVA: 0xC2B3A0
bool __fastcall hkaiVelocityCandidateScoringUtil::scoreStaticSphere(hkVector4f *position, hkSphere *sphere, hkSimdFloat32 *penetrationPenalty, hkaiVelocityCandidateGenerator *velocityCandidates, hkaiVelocityCandidateScores *timesToCollision, hkaiVelocityCandidateScores *bonuses, hkVector4f *bonusVector)
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
_BOOL8 __fastcall hkaiVelocityCandidateScoringUtil::scoreMovingSphere(hkVector4f *position, hkSphere *sphere, hkVector4f *sphereVelocity, hkSimdFloat32 *penetrationPenalty, hkaiVelocityCandidateGenerator *velocityCandidates, hkaiVelocityCandidateScores *timesToCollision, hkaiVelocityCandidateScores *bonuses, hkVector4f *bonusVector)
{
  hkSimdFloat32 *v8; // r10
  __m128 v9; // xmm7
  __m128 v10; // xmm2
  hkSimdFloat32 v11; // xmm11
  __m128 v12; // xmm10
  __m128 v13; // xmm9
  hkVector4f *v14; // rcx
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm15
  __m128 v18; // xmm1
  __m128 v19; // xmm8
  __m128 v20; // xmm6
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  bool v23; // r9
  __m128 v24; // xmm12
  __m128 v25; // xmm10
  __m128 v26; // xmm13
  __m128 v27; // xmm9
  signed __int64 v28; // r8
  __m128 v29; // xmm1
  __m128 v30; // xmm2
  __m128 v31; // xmm6
  __m128 v32; // xmm1
  __m128 v33; // xmm0
  __m128 v34; // xmm2
  __m128 v35; // xmm6
  __m128 v36; // xmm1
  const __m128i *v37; // rdx
  __m128i v38; // xmm2
  __m128i v39; // xmm2
  __m128i v40; // xmm1
  __m128i v41; // xmm2
  __m128 v42; // xmm3
  signed __int64 v43; // r8
  const char *v44; // rax
  __m128 v45; // xmm8
  __m128 v46; // xmm5
  __m128 v47; // xmm7
  __m128 v48; // xmm3
  __m128 v49; // xmm2
  __m128 v50; // xmm1
  __m128i v51; // xmm2
  __m128 v52; // xmm4
  __m128i v53; // xmm1
  __m128i v54; // xmm2
  __m128i v55; // xmm1
  __m128 v56; // xmm10
  __m128 v57; // xmm0
  __m128 v58; // xmm1
  __m128 v59; // xmm8
  __m128 v60; // xmm6
  __m128 v61; // xmm0
  __m128 v62; // xmm6
  __m128 v63; // xmm0
  __m128 v65; // [rsp+0h] [rbp-D8h]
  __m128 v66; // [rsp+10h] [rbp-C8h]
  __m128 v67; // [rsp+20h] [rbp-B8h]

  v8 = penetrationPenalty;
  v9 = _mm_sub_ps(position->m_quad, sphere->m_pos.m_quad);
  v10 = _mm_shuffle_ps(sphere->m_pos.m_quad, sphere->m_pos.m_quad, 255);
  v11.m_real = (__m128)velocityCandidates->m_maxSpeed;
  v12 = _mm_mul_ps(velocityCandidates->m_firstBlockForward.m_quad, v11.m_real);
  v13 = _mm_mul_ps(velocityCandidates->m_firstBlockRight.m_quad, v11.m_real);
  v14 = timesToCollision->m_scores.m_elements;
  v15 = _mm_mul_ps(v9, velocityCandidates->m_forward.m_quad);
  v16 = _mm_mul_ps(v9, v9);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v18 = _mm_mul_ps(v9, velocityCandidates->m_right.m_quad);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v67 = v19;
  v20 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
            _mm_shuffle_ps(v16, v16, 170)),
          _mm_mul_ps(v10, v10));
  v65 = v20;
  v21 = _mm_mul_ps(sphereVelocity->m_quad, velocityCandidates->m_right.m_quad);
  v22 = _mm_mul_ps(sphereVelocity->m_quad, velocityCandidates->m_forward.m_quad);
  v23 = v20.m128_f32[0] < 0.0;
  v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)), _mm_shuffle_ps(v22, v22, 170));
  v25 = _mm_sub_ps(v12, v24);
  v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v27 = _mm_sub_ps(v13, v26);
  if ( v20.m128_f32[0] >= 0.0 )
  {
    v43 = 32i64;
    v44 = velocityCandidates->m_template + 8;
    _mm_store_si128((__m128i *)&v66, _mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
    do
    {
      ++v14;
      v44 += 8;
      --v43;
      v45 = _mm_add_ps(_mm_mul_ps(v19, v27), _mm_mul_ps(v25, v17));
      v46 = v45;
      v47 = _mm_add_ps(_mm_mul_ps(v27, v27), _mm_mul_ps(v25, v25));
      v48 = _mm_sub_ps(_mm_mul_ps(v45, v45), _mm_mul_ps(v47, v20));
      v49 = _mm_rsqrt_ps(v48);
      v50 = _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v48, v49), v49)),
              _mm_mul_ps(v49, *(__m128 *)_xmm));
      v51 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(v44 - 8)), (__m128i)0i64);
      v52 = _mm_andnot_ps(_mm_cmpleps(v48, (__m128)0i64), _mm_mul_ps(v50, v48));
      v53 = v51;
      v54 = _mm_unpackhi_epi16(v51, (__m128i)0i64);
      v55 = _mm_unpacklo_epi16(v53, (__m128i)0i64);
      v56 = _mm_cvtepi32_ps(_mm_srli_epi32(v55, 0x10u));
      v57 = _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v55, 0x10u), 0x10u));
      v58 = _mm_rcp_ps(v47);
      v25 = _mm_sub_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(_mm_mul_ps(v56, (__m128)`hkIntVector::convertU32ToF32::`2::two16), v57),
                    (__m128)xmmword_141A71230),
                  g_vectorfConstants[0]),
                v11.m_real),
              v24);
      v59 = _mm_mul_ps(
              _mm_sub_ps(_mm_xor_ps(v45, v66), v52),
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v47, v58)), v58));
      v27 = _mm_sub_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_cvtepi32_ps(_mm_srli_epi32(v54, 0x10u)),
                        (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                      _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v54, 0x10u), 0x10u))),
                    (__m128)xmmword_141A71230),
                  g_vectorfConstants[0]),
                v11.m_real),
              v26);
      v60 = _mm_and_ps(
              _mm_and_ps(_mm_cmpltps((__m128)0i64, v48), _mm_cmpltps(v46, (__m128)0i64)),
              _mm_cmpltps(v59, v14[-1].m_quad));
      v61 = v60;
      v62 = _mm_and_ps(v60, v59);
      v19 = v67;
      v63 = _mm_or_ps(_mm_andnot_ps(v61, v14[-1].m_quad), v62);
      v20 = v65;
      v14[-1] = (hkVector4f)v63;
    }
    while ( v43 );
  }
  else
  {
    v28 = 32i64;
    v29 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
            _mm_shuffle_ps(v16, v16, 170));
    v30 = _mm_rsqrt_ps(v29);
    v31 = _mm_cmpleps(v29, (__m128)0i64);
    v32 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30));
    v33 = _mm_mul_ps(*(__m128 *)_xmm, v30);
    v34 = _mm_sub_ps((__m128)0i64, v65);
    v35 = _mm_andnot_ps(v31, _mm_mul_ps(v32, v33));
    v36 = _mm_rsqrt_ps(v34);
    bonusVector->m_quad = _mm_add_ps(
                            _mm_mul_ps(
                              _mm_mul_ps(
                                _mm_andnot_ps(
                                  _mm_cmpleps(v34, (__m128)0i64),
                                  _mm_mul_ps(
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v36), v36)),
                                      _mm_mul_ps(*(__m128 *)_xmm, v36)),
                                    v34)),
                                v8->m_real),
                              _mm_mul_ps(v35, v9)),
                            bonusVector->m_quad);
    v37 = (const __m128i *)(velocityCandidates->m_template + 8);
    do
    {
      v38 = _mm_loadl_epi64(v37);
      v37 = (const __m128i *)((char *)v37 + 8);
      ++v14;
      v39 = _mm_unpacklo_epi8(v38, (__m128i)0i64);
      v40 = _mm_unpacklo_epi16(v39, (__m128i)0i64);
      v41 = _mm_unpackhi_epi16(v39, (__m128i)0i64);
      v42 = _mm_cmpleps(_mm_add_ps(_mm_mul_ps(v27, v19), _mm_mul_ps(v25, v17)), (__m128)0i64);
      v25 = _mm_sub_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_cvtepi32_ps(_mm_srli_epi32(v40, 0x10u)),
                        (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                      _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v40, 0x10u), 0x10u))),
                    (__m128)xmmword_141A71230),
                  g_vectorfConstants[0]),
                v11.m_real),
              v24);
      v14[-1].m_quad = _mm_or_ps(
                         _mm_andnot_ps(v42, v14[-1].m_quad),
                         _mm_and_ps(v42, HKAI_LOCAL_STEERING_MIN_TTC.m_real));
      v27 = _mm_sub_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_cvtepi32_ps(_mm_srli_epi32(v41, 0x10u)),
                        (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                      _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v41, 0x10u), 0x10u))),
                    (__m128)xmmword_141A71230),
                  g_vectorfConstants[0]),
                v11.m_real),
              v26);
      --v28;
    }
    while ( v28 );
  }
  return v23;
}

// File Line: 938
// RVA: 0xC2C460
signed __int64 __fastcall hkaiVelocityCandidateScoringUtil::calcWallFollowingDir(hkaiVelocityCandidateGenerator *velocityCandidatesIn, hkaiVelocityCandidateScores *timesToStaticCollision, hkSimdFloat32 *searchDistance, float wallFollowingAngle, hkSimdFloat32 *forwardFactorOut, hkSimdFloat32 *rightFactorOut)
{
  hkVector4f *v6; // r10
  __int64 v7; // r11
  hkVector4f v8; // STC0_16
  hkVector4f v9; // STB0_16
  __m128 v10; // xmm7
  __m128 v11; // xmm8
  __m128 v12; // xmm11
  __m128 v13; // xmm12
  __m128i v14; // xmm2
  __m128i v15; // xmm1
  float v16; // xmm9_4
  hkSimdFloat32 v17; // xmm3
  __m128i v18; // xmm2
  __m128i v19; // xmm1
  __m128 v20; // xmm0
  __m128 v21; // xmm14
  __m128 v22; // xmm1
  __m128 v23; // xmm1
  __m128i v24; // xmm6
  signed int v25; // edx
  __m128 v26; // xmm2
  __m128 *v27; // r8
  signed __int64 v28; // r9
  __m128i v29; // xmm8
  __m128 v30; // xmm7
  __m128i v31; // xmm6
  __m128i v32; // xmm5
  __m128 v33; // xmm4
  __m128i v34; // xmm8
  __m128 v35; // xmm6
  __m128 v36; // xmm5
  __m128 v37; // xmm8
  __m128 v38; // xmm9
  __m128 v39; // xmm4
  __m128 v40; // xmm2
  __m128 v41; // xmm3
  __m128 v42; // xmm0
  __m128 v43; // xmm4
  __m128 v44; // xmm0
  __m128 v45; // xmm5
  __m128 v46; // xmm0
  __m128 v47; // xmm8
  __m128 v48; // xmm0
  __m128 v49; // xmm13
  __m128i v50; // xmm2
  __m128 v51; // xmm3
  __m128i v52; // xmm1
  __m128i v53; // xmm2
  __m128i v54; // xmm1
  __m128 v55; // xmm10
  __m128 v56; // xmm11
  __m128 v57; // xmm1
  __m128 v58; // xmm12
  __m128 v59; // xmm7
  __m128 v60; // xmm5
  __m128 v61; // xmm9
  __m128 v62; // xmm4
  __m128 v63; // xmm6
  __m128 v64; // xmm8
  __m128 v65; // xmm1
  __m128 v66; // xmm2
  __m128 v67; // xmm6
  __m128 v68; // xmm8
  __m128 v69; // xmm9
  __m128i v70; // xmm1
  __m128 v71; // xmm3
  __m128 v72; // xmm6
  __m128 v73; // xmm9
  __m128 v74; // xmm2
  __m128 v75; // xmm7
  __m128 v76; // xmm1
  int v77; // eax
  __int64 v78; // rcx
  __m128 v79; // xmm0
  __m128 v80; // xmm1
  __m128 v82; // xmm2
  __m128 v83; // xmm1
  __m128 v84; // xmm7
  __m128 v85; // xmm1
  hkVector4f v86; // [rsp+0h] [rbp-1A8h]
  __m128 v87; // [rsp+10h] [rbp-198h]
  __m128 v88; // [rsp+20h] [rbp-188h]
  __m128 v89; // [rsp+30h] [rbp-178h]
  __m128 v90; // [rsp+40h] [rbp-168h]
  __m128 v91; // [rsp+50h] [rbp-158h]
  __m128 v92; // [rsp+60h] [rbp-148h]
  __m128 v93; // [rsp+70h] [rbp-138h]
  __m128 v94; // [rsp+90h] [rbp-118h]

  v6 = timesToStaticCollision->m_scores.m_elements;
  v7 = *(_OWORD *)&velocityCandidatesIn->m_template;
  v8.m_quad = (__m128)velocityCandidatesIn->m_right;
  v9.m_quad = (__m128)velocityCandidatesIn->m_forward;
  v10 = _mm_shuffle_ps(
          velocityCandidatesIn->m_firstBlockForward.m_quad,
          velocityCandidatesIn->m_firstBlockForward.m_quad,
          0);
  v86.m_quad = (__m128)timesToStaticCollision->m_scores.m_elements[25];
  v11 = _mm_shuffle_ps(
          velocityCandidatesIn->m_firstBlockRight.m_quad,
          velocityCandidatesIn->m_firstBlockRight.m_quad,
          0);
  v12 = (__m128)`hkIntVector::convertU32ToF32::`2::two16;
  v13 = timesToStaticCollision->m_scores.m_elements[31].m_quad;
  v14 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(v7 + 248)), (__m128i)0i64);
  v15 = v14;
  v16 = wallFollowingAngle;
  v17.m_real = (__m128)velocityCandidatesIn->m_maxSpeed;
  v18 = _mm_unpackhi_epi16(v14, (__m128i)0i64);
  v19 = _mm_unpacklo_epi16(v15, (__m128i)0i64);
  v89 = g_vectorfConstants[0];
  v94 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_cvtepi32_ps(_mm_srli_epi32(v19, 0x10u)),
                (__m128)`hkIntVector::convertU32ToF32::`2::two16),
              _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v19, 0x10u), 0x10u))),
            (__m128)xmmword_141A71230),
          g_vectorfConstants[0]);
  v20 = _mm_rcp_ps(v17.m_real);
  v21 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v17.m_real, v20)), v20), searchDistance->m_real);
  v93 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_cvtepi32_ps(_mm_srli_epi32(v18, 0x10u)),
                (__m128)`hkIntVector::convertU32ToF32::`2::two16),
              _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v18, 0x10u), 0x10u))),
            (__m128)xmmword_141A71230),
          g_vectorfConstants[0]);
  v22 = _mm_add_ps(_mm_mul_ps(v11, v11), _mm_mul_ps(v10, v10));
  if ( v22.m128_f32[0] == 0.0 )
    v23 = 0i64;
  else
    v23 = _mm_div_ps(query.m_quad, _mm_sqrt_ps(v22));
  v24 = _mm_load_si128((const __m128i *)_xmm);
  v25 = 26;
  v26 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(v16));
  v27 = &v6[24].m_quad;
  v90 = _mm_mul_ps(v11, v23);
  v28 = 8i64;
  v29 = _mm_add_epi32(v24, v24);
  v91 = _mm_mul_ps(v10, v23);
  v30 = 0i64;
  v88 = 0i64;
  v31 = _mm_andnot_si128(v24, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v26, *(__m128 *)_xmm)), v24));
  v32 = _mm_and_si128(v31, v29);
  v33 = _mm_cvtepi32_ps(v31);
  v34 = _mm_and_si128(_mm_add_epi32(v29, v29), v31);
  v35 = v93;
  v36 = (__m128)_mm_cmpeq_epi32(v32, (__m128i)0i64);
  v37 = _mm_xor_ps((__m128)_mm_slli_epi32(v34, 0x1Du), _mm_and_ps((__m128)LODWORD(v16), *(__m128 *)_xmm));
  v38 = v86.m_quad;
  v39 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v33, *(__m128 *)DP1_0), v26), _mm_mul_ps(v33, *(__m128 *)DP2)),
          _mm_mul_ps(v33, *(__m128 *)DP3));
  v40 = _mm_mul_ps(v39, v39);
  v41 = _mm_andnot_ps(
          v36,
          _mm_add_ps(
            _mm_sub_ps(
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v40, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v40),
                    *(__m128 *)cosCoeff2_0),
                  v40),
                v40),
              _mm_mul_ps(v40, *(__m128 *)_xmm)),
            *(__m128 *)_xmm));
  v42 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v40, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v40),
                *(__m128 *)sinCoeff2_0),
              v40),
            v39),
          v39);
  v43 = v94;
  v44 = _mm_and_ps(v42, v36);
  v45 = g_vectorfConstants[0];
  v46 = _mm_xor_ps(_mm_or_ps(v44, v41), v37);
  v47 = g_vectorfConstants[0];
  v48 = _mm_xor_ps(v46, *(__m128 *)_xmm);
  v92 = _mm_shuffle_ps(v48, v48, 0);
  v87 = 0i64;
  do
  {
    v49 = *v27;
    v50 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(8 * v25 - 16 + v7)), (__m128i)0i64);
    v51 = _mm_shuffle_ps(_mm_shuffle_ps(v13, *v27, 51), _mm_shuffle_ps(v13, *v27, 153), 236);
    v52 = v50;
    v53 = _mm_unpackhi_epi16(v50, (__m128i)0i64);
    v54 = _mm_unpacklo_epi16(v52, (__m128i)0i64);
    v55 = _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v54, 0x10u)), v12),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v54, 0x10u), 0x10u))),
              (__m128)xmmword_141A71230),
            v47);
    v56 = _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v53, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v53, 0x10u), 0x10u))),
              (__m128)xmmword_141A71230),
            v47);
    v57 = v6[v25 % 8 + 24].m_quad;
    v58 = _mm_and_ps(_mm_cmpltps(v51, v21), _mm_cmpltps(*v27, v21));
    if ( _mm_movemask_ps(v58) )
    {
      v59 = _mm_min_ps(v6[(v25 + 4) % 8 + 24].m_quad, v21);
      v60 = _mm_min_ps(_mm_shuffle_ps(_mm_shuffle_ps(v38, v57, 51), _mm_shuffle_ps(v38, v57, 153), 236), v21);
      v61 = _mm_shuffle_ps(_mm_shuffle_ps(v43, v55, 51), _mm_shuffle_ps(v43, v55, 153), 236);
      v62 = _mm_shuffle_ps(_mm_shuffle_ps(v35, v56, 51), _mm_shuffle_ps(v35, v56, 153), 236);
      v63 = _mm_sub_ps(_mm_mul_ps(v55, v49), _mm_mul_ps(v61, v51));
      v64 = _mm_sub_ps(_mm_mul_ps(v56, v49), _mm_mul_ps(v62, v51));
      v65 = _mm_add_ps(_mm_mul_ps(v64, v64), _mm_mul_ps(v63, v63));
      v66 = _mm_andnot_ps(_mm_cmpleps(v65, (__m128)0i64), _mm_rsqrt_ps(v65));
      v67 = _mm_mul_ps(v63, v66);
      v68 = _mm_mul_ps(v64, v66);
      v69 = _mm_max_ps(
              _mm_sub_ps(_mm_mul_ps(_mm_add_ps(v61, v55), v68), _mm_mul_ps(_mm_add_ps(v62, v56), v67)),
              aabbOut.m_quad);
      v70 = (__m128i)_mm_cmpltps(
                       _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v68, v90), _mm_mul_ps(v67, v91)), v21),
                       _mm_mul_ps(_mm_sub_ps(v59, v60), *(__m128 *)_xmm));
      v71 = (__m128)_mm_slli_epi32(_mm_srli_epi32(v70, 0x1Fu), 0x1Fu);
      v72 = _mm_xor_ps(v67, v71);
      v73 = _mm_mul_ps(v69, _mm_or_ps(_mm_andnot_ps((__m128)v70, v60), _mm_and_ps((__m128)v70, v59)));
      v74 = _mm_and_ps(_mm_and_ps(_mm_cmpltps(v92, v72), v58), _mm_cmpltps(v89, v73));
      v45 = _mm_or_ps(_mm_and_ps(v74, v73), _mm_andnot_ps(v74, v89));
      v89 = v45;
      v87 = _mm_or_ps(_mm_and_ps(v74, v72), _mm_andnot_ps(v74, v87));
      v57 = v6[v25 % 8 + 24].m_quad;
      v75 = _mm_and_ps(_mm_xor_ps(v68, v71), v74);
      v47 = g_vectorfConstants[0];
      v30 = _mm_or_ps(v75, _mm_andnot_ps(v74, v88));
      v88 = v30;
    }
    ++v25;
    ++v27;
    v35 = v56;
    v12 = (__m128)`hkIntVector::convertU32ToF32::`2::two16;
    v13 = v49;
    v43 = v55;
    v38 = v57;
    --v28;
  }
  while ( v28 );
  v76 = _mm_max_ps(_mm_shuffle_ps(v45, v45, 78), v45);
  v77 = _mm_movemask_ps(_mm_cmpleps(_mm_max_ps(v76, _mm_shuffle_ps(v76, v76, 177)), v45));
  v78 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[v77];
  v79 = _mm_and_ps(
          (__m128)`hkVector4f::getComponent::`2::indexToMask[(unsigned __int8)hkVector4Comparison_maskToLastIndex[v77]],
          v45);
  v80 = _mm_or_ps(_mm_shuffle_ps(v79, v79, 78), v79);
  if ( COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v80, v80, 177) | v80.m128_i32[0]) <= 0.0 )
    return 0i64;
  v82 = _mm_and_ps(
          (__m128)`hkVector4f::getComponent::`2::indexToMask[(unsigned __int8)hkVector4Comparison_maskToLastIndex[v77]],
          v87);
  v83 = _mm_or_ps(_mm_shuffle_ps(v82, v82, 78), v82);
  forwardFactorOut->m_real = _mm_or_ps(_mm_shuffle_ps(v83, v83, 177), v83);
  v84 = _mm_and_ps(v30, (__m128)`hkVector4f::getComponent::`2::indexToMask[v78]);
  v85 = _mm_or_ps(_mm_shuffle_ps(v84, v84, 78), v84);
  rightFactorOut->m_real = _mm_or_ps(_mm_shuffle_ps(v85, v85, 177), v85);
  return 1i64;
}

// File Line: 1224
// RVA: 0xC2CBB0
float __fastcall `anonymous namespace::calcWallFollowingPenaltyFromAngle(float angle)
{
  __m128i v1; // xmm6
  __m128 v2; // xmm9
  __m128 v3; // xmm3
  __m128i v4; // xmm7
  __m128i v5; // xmm6
  __m128 v6; // xmm2
  __m128 v7; // xmm5
  __m128 v8; // xmm4
  __m128 v9; // xmm2

  v1 = _mm_load_si128((const __m128i *)_xmm);
  v2 = _mm_add_ps((__m128)LODWORD(angle), *(__m128 *)_xmm);
  v3 = _mm_andnot_ps(*(__m128 *)_xmm, v2);
  v4 = _mm_add_epi32(v1, v1);
  v5 = _mm_andnot_si128(v1, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(*(__m128 *)_xmm, v3)), v1));
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
                 - COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                                          v7,
                                                          _mm_add_ps(
                                                            _mm_sub_ps(
                                                              _mm_mul_ps(
                                                                _mm_mul_ps(
                                                                  _mm_add_ps(
                                                                    _mm_mul_ps(
                                                                      _mm_add_ps(
                                                                        _mm_mul_ps(v9, *(__m128 *)cosCoeff0_0),
                                                                        *(__m128 *)cosCoeff1),
                                                                      v9),
                                                                    *(__m128 *)cosCoeff2_0),
                                                                  v9),
                                                                v9),
                                                              _mm_mul_ps(v9, *(__m128 *)_xmm)),
                                                            *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                                                  (float)((float)((float)((float)((float)((float)(v9.m128_f32[0] * -0.00019515296) + 0.0083321612) * v9.m128_f32[0]) + -0.16666655)
                                                                                                * v9.m128_f32[0])
                                                                                        * v8.m128_f32[0])
                                                                                + v8.m128_f32[0]) & v7.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v4, v4), v5) << 29) ^ _xmm[0] & v2.m128_i32[0]))
         * 2.0);
}

// File Line: 1242
// RVA: 0xC2BF00
void __fastcall hkaiVelocityCandidateScoringUtil::chooseBestCandidate(hkaiVelocityCandidateGenerator *velocityCandidatesIn, hkaiVelocityCandidateScores *staticTtcsIn, hkaiVelocityCandidateScores *dynamicTtcsIn, hkaiVelocityCandidateScores *bonusesIn, hkVector4f *bonusVector, float radialMultiplier, float wallFollowingAngle, float collisionPenaltyIn, float desiredSpeedIn, float wallSearchDistance, __int64 dodgingPenaltyIn, hkVector4f *localGoalPlane)
{
  hkVector4f v12; // xmm1
  hkVector4f *v13; // rdi
  hkVector4f *v14; // rsi
  hkVector4f *v15; // r14
  hkaiVelocityCandidateScores *v16; // rbx
  __m128 v17; // xmm7
  __m128 v18; // xmm6
  __m128 v19; // xmm8
  __m128 v20; // xmm10
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
  signed __int64 v34; // rcx
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
  __m128i v55; // xmm2
  __m128i v56; // xmm1
  __m128i v57; // xmm2
  __m128i v58; // xmm1
  __m128 v59; // xmm1
  __m128 v60; // xmm0
  __m128i v61; // xmm4
  __m128 v62; // xmm3
  __m128 v63; // xmm3
  __m128 v64; // xmm2
  __m128i v65; // xmm1
  __m128 v66; // xmm3
  __m128i v67; // xmm2
  __m128 v68; // xmm3
  __m128i v69; // xmm0
  __m128 v70; // xmm0
  __m128 v71; // xmm1
  __int64 v72; // rcx
  hkSimdFloat32 rightFactorOut; // [rsp+30h] [rbp-C8h]
  hkSimdFloat32 forwardFactorOut; // [rsp+40h] [rbp-B8h]
  hkVector4f v75; // [rsp+50h] [rbp-A8h]
  hkSimdFloat32 searchDistance; // [rsp+60h] [rbp-98h]
  hkVector4f v77; // [rsp+70h] [rbp-88h]
  __m128i v78; // [rsp+88h] [rbp-70h]
  hkaiVelocityCandidateGenerator velocityCandidatesIna; // [rsp+98h] [rbp-60h]
  __m128 v80; // [rsp+F8h] [rbp+0h]
  __m128 v81; // [rsp+108h] [rbp+10h]
  __m128 v82; // [rsp+118h] [rbp+20h]
  __m128 v83; // [rsp+128h] [rbp+30h]
  __m128 v84; // [rsp+138h] [rbp+40h]
  __int128 v85; // [rsp+148h] [rbp+50h]
  __m128 v86; // [rsp+158h] [rbp+60h]
  __m128 *v87; // [rsp+238h] [rbp+140h]

  v12.m_quad = (__m128)velocityCandidatesIn->m_firstBlockRight;
  v13 = staticTtcsIn->m_scores.m_elements;
  v14 = dynamicTtcsIn->m_scores.m_elements;
  v15 = bonusesIn->m_scores.m_elements;
  v16 = staticTtcsIn;
  v17 = velocityCandidatesIn->m_forward.m_quad;
  v18 = _mm_shuffle_ps((__m128)LODWORD(collisionPenaltyIn), (__m128)LODWORD(collisionPenaltyIn), 0);
  v19 = velocityCandidatesIn->m_right.m_quad;
  *(_OWORD *)&velocityCandidatesIna.m_template = *(_OWORD *)&velocityCandidatesIn->m_template;
  v20 = velocityCandidatesIn->m_maxSpeed.m_real;
  velocityCandidatesIna.m_firstBlockForward = velocityCandidatesIn->m_firstBlockForward;
  v82 = _mm_shuffle_ps((__m128)LODWORD(wallFollowingAngle), (__m128)LODWORD(wallFollowingAngle), 0);
  velocityCandidatesIna.m_firstBlockRight = (hkVector4f)v12.m_quad;
  v21 = _mm_rcp_ps(v18);
  velocityCandidatesIna.m_forward.m_quad = v17;
  velocityCandidatesIna.m_right.m_quad = v19;
  v22 = (__m128)LODWORD(radialMultiplier);
  velocityCandidatesIna.m_maxSpeed.m_real = v20;
  v86 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, v21)), v21);
  v22.m128_f32[0] = `anonymous namespace::calcWallFollowingPenaltyFromAngle(radialMultiplier);
  v23 = _mm_rcp_ps(v20);
  v24 = _mm_shuffle_ps((__m128)(unsigned int)bonusVector, (__m128)(unsigned int)bonusVector, 0);
  v25 = (__m128)xmmword_141A712F0;
  v26 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v18);
  v27 = query.m_quad;
  v80 = HKAI_LOCAL_STEERING_MIN_TTC.m_real;
  v28 = query.m_quad;
  v77.m_quad = query.m_quad;
  v29 = _mm_mul_ps(v26, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v20, v23)), v23));
  _mm_store_si128(&v78, (__m128i)0i64);
  if ( radialMultiplier <= 0.0 )
    goto LABEL_6;
  searchDistance.m_real = _mm_shuffle_ps((__m128)LODWORD(desiredSpeedIn), (__m128)LODWORD(desiredSpeedIn), 0);
  if ( !hkaiVelocityCandidateScoringUtil::calcWallFollowingDir(
          &velocityCandidatesIna,
          v16,
          &searchDistance,
          radialMultiplier,
          &forwardFactorOut,
          &rightFactorOut)
    || (v30 = forwardFactorOut.m_real, forwardFactorOut.m_real.m128_f32[0] < (float)(0.0 - v29.m128_f32[0])) )
  {
    v28 = v77.m_quad;
    v20 = velocityCandidatesIna.m_maxSpeed.m_real;
    v19 = velocityCandidatesIna.m_right.m_quad;
    v17 = velocityCandidatesIna.m_forward.m_quad;
    v27 = query.m_quad;
LABEL_6:
    v31 = v24;
    v30 = v28;
    goto LABEL_7;
  }
  v20 = velocityCandidatesIna.m_maxSpeed.m_real;
  v19 = velocityCandidatesIna.m_right.m_quad;
  v17 = velocityCandidatesIna.m_forward.m_quad;
  v31 = rightFactorOut.m_real;
  v27 = query.m_quad;
  v28 = v77.m_quad;
LABEL_7:
  v32 = velocityCandidatesIna.m_firstBlockForward.m_quad;
  v33 = (char *)v14 - (char *)v13;
  v34 = 32i64;
  forwardFactorOut.m_real = v31;
  rightFactorOut.m_real = (__m128)velocityCandidatesIna.m_firstBlockForward;
  v35 = _mm_mul_ps(v17, *v87);
  v36 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)), _mm_shuffle_ps(v35, v35, 170));
  v37 = _mm_mul_ps(v19, *v87);
  v38 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)), _mm_shuffle_ps(v37, v37, 170));
  v39 = (const __m128i *)(velocityCandidatesIna.m_template + 8);
  v40 = (char *)v15 - (char *)v13;
  v41 = _mm_mul_ps(v19, *(__m128 *)dodgingPenaltyIn);
  v42 = _mm_mul_ps(v17, *(__m128 *)dodgingPenaltyIn);
  v43 = _mm_shuffle_ps(*(__m128 *)dodgingPenaltyIn, *(__m128 *)dodgingPenaltyIn, 255);
  *(hkVector4f *)((char *)&v77 + 8) = (hkVector4f)_mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_shuffle_ps(v42, v42, 85),
                                                      _mm_shuffle_ps(v42, v42, 0)),
                                                    _mm_shuffle_ps(v42, v42, 170));
  v44 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)), _mm_shuffle_ps(v41, v41, 170));
  v45 = *(__m128 *)((char *)&v77 + 8);
  v46 = _mm_sub_ps((__m128)0i64, v43);
  v83 = v44;
  v47.m_quad = (__m128)velocityCandidatesIna.m_firstBlockRight;
  v48 = _mm_shuffle_ps((__m128)LODWORD(wallSearchDistance), (__m128)LODWORD(wallSearchDistance), 0);
  v81 = v46;
  v75.m_quad = (__m128)velocityCandidatesIna.m_firstBlockRight;
  v84 = v48;
  _mm_store_si128((__m128i *)&searchDistance, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v85, (__m128i)0i64);
  do
  {
    v49 = _mm_max_ps(_mm_min_ps(v13->m_quad, *(__m128 *)((char *)&v13->m_quad + v33)), v80);
    v50 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v32, v28), _mm_mul_ps(v47.m_quad, v24)), (__m128)xmmword_141A710D0);
    v51 = _mm_sub_ps(
            _mm_mul_ps(
              _mm_add_ps(_mm_mul_ps(v47.m_quad, v31), _mm_mul_ps(rightFactorOut.m_real, v30)),
              (__m128)xmmword_141A710D0),
            v29);
    v52 = _mm_cmpltps(v50, v51);
    v53 = _mm_add_ps(
            _mm_add_ps(
              _mm_sub_ps(
                _mm_or_ps(_mm_andnot_ps(v52, v50), _mm_and_ps(v51, v52)),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_or_ps(_mm_andnot_ps(v52, v48), _mm_and_ps(v52, v27)),
                        _mm_mul_ps(v75.m_quad, v75.m_quad)),
                      _mm_mul_ps(rightFactorOut.m_real, rightFactorOut.m_real)),
                    v86),
                  v20)),
              _mm_mul_ps(rightFactorOut.m_real, v36)),
            _mm_mul_ps(v75.m_quad, v38));
    v54 = _mm_load_si128((const __m128i *)&v85);
    v55 = _mm_unpacklo_epi8(_mm_loadl_epi64(v39), v54);
    v56 = v55;
    v57 = _mm_unpackhi_epi16(v55, v54);
    v58 = _mm_unpacklo_epi16(v56, v54);
    v32 = _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v58, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v58, 0x10u), 0x10u))),
              (__m128)xmmword_141A71230),
            g_vectorfConstants[0]);
    rightFactorOut.m_real = v32;
    v59 = _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v57, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v57, 0x10u), 0x10u))),
              (__m128)xmmword_141A71230),
            g_vectorfConstants[0]);
    v75.m_quad = v59;
    v60 = _mm_rcp_ps(v49);
    v61 = _mm_load_si128((const __m128i *)&searchDistance);
    v62 = *(__m128 *)((char *)&v13->m_quad + v40);
    v39 = (const __m128i *)((char *)v39 + 8);
    ++v13;
    v63 = _mm_add_ps(v62, _mm_mul_ps(v53, v20));
    v27 = query.m_quad;
    v64 = _mm_andnot_ps(
            _mm_cmpltps(_mm_mul_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(v59, v83), _mm_mul_ps(v32, v45)), v20), v49), v81),
            _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v49, v60)), v60), v82));
    v65 = v61;
    v66 = _mm_sub_ps(v63, v64);
    _mm_store_si128((__m128i *)&searchDistance, _mm_add_epi32(v61, (__m128i)xmmword_141A72090));
    v28 = v77.m_quad;
    v67 = (__m128i)_mm_cmpltps(v25, v66);
    v68 = _mm_and_ps(v66, (__m128)v67);
    v69 = _mm_or_si128(_mm_andnot_si128(v67, v78), _mm_and_si128(v65, v67));
    v48 = v84;
    _mm_store_si128(&v78, v69);
    _mm_store_si128((__m128i *)&v77.m_quad.m128_u16[4], v69);
    v70 = _mm_andnot_ps((__m128)v67, v25);
    v47.m_quad = v75.m_quad;
    v25 = _mm_or_ps(v70, v68);
    v31 = forwardFactorOut.m_real;
    --v34;
  }
  while ( v34 );
  v71 = _mm_max_ps(_mm_shuffle_ps(v25, v25, 78), v25);
  v72 = _mm_movemask_ps(_mm_cmpleps(_mm_max_ps(v71, _mm_shuffle_ps(v71, v71, 177)), v25));
  hkaiVelocityCandidateGenerator::generateCandidate(
    &velocityCandidatesIna,
    (unsigned __int8)hkVector4Comparison_maskToLastIndex[v72]
  + 4 * v77.m_quad.m128_i32[(unsigned __int8)hkVector4Comparison_maskToLastIndex[v72] + 2],
    localGoalPlane);
}

