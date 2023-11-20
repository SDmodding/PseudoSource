// File Line: 38
// RVA: 0xCA6EF0
void __fastcall hkSimplexSolverSortInfo(hkSimplexSolverInfo *info)
{
  int v1; // edx
  hkSimplexSolverInfo *v2; // rbx
  __m128 **v3; // r10
  signed int v4; // edi
  int v5; // er11
  __m128 **v6; // rax
  float v7; // ecx
  float v8; // edx
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 *v11; // rdx
  __m128 *v12; // r8
  __m128 *v13; // r9

  v1 = info->m_numSupportPlanes;
  v2 = info;
  if ( v1 - 1 > 0 )
  {
    v3 = (__m128 **)&info->m_supportPlanes[0].m_constraint;
    v4 = 1;
    do
    {
      v5 = v4;
      if ( v4 < v1 )
      {
        v6 = v3 + 3;
        do
        {
          v7 = (*v3)[3].m128_f32[0];
          v8 = (*v6)[3].m128_f32[0];
          if ( SLODWORD(v7) >= SLODWORD(v8) )
          {
            if ( LODWORD(v7) != LODWORD(v8)
              || (v9 = _mm_mul_ps((*v3)[1], (*v3)[1]),
                  v10 = _mm_mul_ps((*v6)[1], (*v6)[1]),
                  (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 0)))
                        + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 170))) >= (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 85))
                                                                                      + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 0)))
                                                                              + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 170)))) )
            {
              v11 = *(v3 - 1);
              v12 = *v3;
              v13 = v3[1];
              *(v3 - 1) = *(v6 - 1);
              *v3 = *v6;
              v3[1] = v6[1];
              *(v6 - 1) = v11;
              *v6 = v12;
              v6[1] = v13;
            }
          }
          ++v5;
          v6 += 3;
        }
        while ( v5 < v2->m_numSupportPlanes );
      }
      v1 = v2->m_numSupportPlanes;
      ++v4;
      v3 += 3;
    }
    while ( v4 - 1 < v1 - 1 );
  }
}

// File Line: 65
// RVA: 0xCA6FE0
hkBool *__fastcall hkSimplexSolverSolveTest1d(hkBool *result, hkSurfaceConstraintInfo *sci, hkVector4f *velocityIn)
{
  __m128 v3; // xmm3

  v3 = _mm_mul_ps(_mm_sub_ps(velocityIn->m_quad, sci->m_velocity.m_quad), sci->m_plane.m_quad);
  result->m_bool = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v3, v3, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v3, v3, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v3, v3, 170))) < COERCE_FLOAT(
                                                                          _mm_shuffle_ps(
                                                                            (__m128)LODWORD(FLOAT_N0_001),
                                                                            (__m128)LODWORD(FLOAT_N0_001),
                                                                            0));
  return result;
}

// File Line: 80
// RVA: 0xCA7030
void __fastcall hkSimplexSolverSolve1d(hkSimplexSolverInfo *info, hkSurfaceConstraintInfo *sci, hkVector4f *velocityIn, hkVector4f *velocityOut)
{
  __m128 v4; // xmm5
  hkSimplexSolverInput *v5; // r8
  float v6; // xmm6_4
  __m128 v7; // xmm11
  __m128 v8; // xmm5
  hkVector4f v9; // xmm14
  char *v10; // rax
  __m128 v11; // xmm1
  __m128 v12; // xmm15
  __m128 v13; // xmm9
  __m128 v14; // xmm1
  __m128 v15; // xmm12
  __m128 v16; // xmm0
  float v17; // xmm9_4
  __m128 v18; // xmm5
  __m128 v19; // xmm2
  float v20; // xmm3_4
  __m128 v21; // xmm2
  __m128 v22; // xmm4
  __m128 v23; // xmm4
  __m128 v24; // xmm1
  __m128 v25; // xmm7
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm0
  __m128 v29; // xmm1
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __m128 v32; // xmm4
  __m128 v33; // xmm1
  __m128 v34; // xmm5
  __m128 v35; // xmm1

  v4 = velocityIn->m_quad;
  v5 = info->m_input;
  LODWORD(v6) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(sci->m_staticFriction),
                                     (__m128)LODWORD(sci->m_staticFriction),
                                     0);
  v7 = sci->m_velocity.m_quad;
  v8 = _mm_sub_ps(v4, v7);
  v9.m_quad = (__m128)sci->m_plane;
  v10 = (char *)&sci->m_extraUpStaticFriction;
  v11 = _mm_mul_ps(v8, sci->m_plane.m_quad);
  v12 = _mm_shuffle_ps((__m128)LODWORD(sci->m_dynamicFriction), (__m128)LODWORD(sci->m_dynamicFriction), 0);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v14 = _mm_mul_ps(v8, v8);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_mul_ps(v13, sci->m_plane.m_quad);
  v17 = v13.m128_f32[0] * v13.m128_f32[0];
  v18 = _mm_sub_ps(v8, v16);
  v19 = _mm_mul_ps(v5->m_upVector.m_quad, v18);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 170))) <= 0.0 )
    v10 = (char *)&sci->m_extraDownStaticFriction;
  LODWORD(v20) = (unsigned __int128)_mm_shuffle_ps((__m128)*(unsigned int *)v10, (__m128)*(unsigned int *)v10, 0);
  if ( v20 <= 0.0 )
  {
    if ( (float)((float)((float)(v6 * v6) + 1.0) * v17) >= v15.m128_f32[0] )
      goto LABEL_9;
  }
  else
  {
    v21 = 0i64;
    v22 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v9.m_quad, v9.m_quad, 201), v5->m_upVector.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v5->m_upVector.m_quad, v5->m_upVector.m_quad, 201), v9.m_quad));
    v23 = _mm_shuffle_ps(v22, v22, 201);
    v24 = _mm_mul_ps(v23, v23);
    v25 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
            _mm_shuffle_ps(v24, v24, 170));
    if ( v25.m128_f32[0] > 0.00000011920929 )
    {
      v26 = _mm_rsqrt_ps(v25);
      v23 = _mm_mul_ps(
              v23,
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                _mm_mul_ps(*(__m128 *)_xmm, v26)));
      v27 = _mm_mul_ps(v23, v18);
      v21 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
              _mm_shuffle_ps(v27, v27, 170));
      if ( (float)((float)(v6 * v6) * v17) >= (float)(v21.m128_f32[0] * v21.m128_f32[0]) )
      {
        v28 = _mm_mul_ps(v23, v21);
        v21 = 0i64;
        v18 = _mm_sub_ps(v18, v28);
      }
    }
    if ( (float)((float)((float)(v20 + v6) * (float)(v20 + v6)) * v17) >= (float)((float)(v15.m128_f32[0]
                                                                                        - (float)(v21.m128_f32[0]
                                                                                                * v21.m128_f32[0]))
                                                                                - v17) )
    {
      if ( v21.m128_f32[0] == 0.0 )
      {
LABEL_9:
        *velocityOut = (hkVector4f)v7;
        return;
      }
      v18 = _mm_mul_ps(v23, v21);
    }
  }
  if ( v12.m128_f32[0] < 1.0 )
  {
    v29 = _mm_mul_ps(v18, v18);
    v30 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
            _mm_shuffle_ps(v29, v29, 170));
    if ( v30.m128_f32[0] >= 0.00000011920929
      && v30.m128_f32[0] > (float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0))
                                 * v15.m128_f32[0]) )
    {
      v31 = _mm_rcp_ps(v30);
      v32 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v31, v30)), v31), v15);
      v33 = _mm_rsqrt_ps(v32);
      v34 = _mm_mul_ps(
              v18,
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(query.m_quad, v12),
                  _mm_andnot_ps(
                    _mm_cmpleps(v32, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v33), v33)),
                        _mm_mul_ps(*(__m128 *)_xmm, v33)),
                      v32))),
                v12));
      v35 = _mm_mul_ps(v34, v9.m_quad);
      v18 = _mm_sub_ps(
              v34,
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
                  _mm_shuffle_ps(v35, v35, 170)),
                v9.m_quad));
    }
  }
  velocityOut->m_quad = _mm_add_ps(v18, v7);
}

// File Line: 184
// RVA: 0xCA7360
void __fastcall hkSimplexSolverSolve2d(hkSimplexSolverInfo *info, hkSurfaceConstraintInfo *sci0, hkSurfaceConstraintInfo *sci1, hkVector4f *velocityIn, hkVector4f *velocityOut)
{
  hkSurfaceConstraintInfo *v5; // rbx
  hkSimplexSolverInfo *v6; // rdi
  hkVector4f v7; // xmm9
  hkVector4f v8; // xmm10
  __m128 v9; // xmm3
  __m128 v10; // xmm11
  __m128 v11; // xmm7
  __m128 v12; // xmm6
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  hkSimplexSolverInput *v15; // rcx
  __m128 v16; // xmm1
  __m128 v17; // xmm9
  __m128 v18; // xmm5
  __m128 v19; // xmm6
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm4
  hkVector4f v23; // xmm1
  __m128 v24; // xmm11
  __m128 v25; // xmm4
  __m128 v26; // xmm10
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  hkVector4f v29; // xmm10
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  __m128 v33; // xmm5
  __m128 v34; // xmm1
  float v35; // xmm3_4
  __m128 v36; // xmm4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm3_4
  __m128 v41; // xmm7
  __m128 v42; // xmm1
  __m128i v43; // xmm3
  __m128 v44; // xmm1
  hkSimplexSolverInfo *v45; // rcx
  hkVector4f *v46; // r9
  hkSurfaceConstraintInfo *v47; // rdx
  hkSurfaceConstraintInfo *v48; // r10
  unsigned int v49; // [rsp+A8h] [rbp+10h]
  unsigned int v50; // [rsp+A8h] [rbp+10h]

  v5 = sci0;
  v6 = info;
  v7.m_quad = (__m128)sci1->m_plane;
  v8.m_quad = (__m128)sci0->m_plane;
  v9 = _mm_shuffle_ps(v7.m_quad, v7.m_quad, 201);
  v10 = _mm_shuffle_ps(v8.m_quad, v8.m_quad, 201);
  v11 = _mm_sub_ps(_mm_mul_ps(v9, sci0->m_plane.m_quad), _mm_mul_ps(v10, sci1->m_plane.m_quad));
  v12 = _mm_shuffle_ps(v11, v11, 201);
  v13 = _mm_mul_ps(v12, v12);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  if ( v14.m128_f32[0] <= 0.00000011920929 )
    goto LABEL_18;
  v15 = info->m_input;
  v16 = _mm_rsqrt_ps(v14);
  v17 = _mm_mul_ps(v7.m_quad, sci1->m_velocity.m_quad);
  v18 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v14), v16)), _mm_mul_ps(*(__m128 *)_xmm, v16));
  v19 = _mm_mul_ps(v12, v18);
  v20 = _mm_shuffle_ps(v19, v19, 201);
  v21 = _mm_mul_ps(v8.m_quad, v20);
  v22 = _mm_mul_ps(sci1->m_plane.m_quad, v20);
  v23.m_quad = (__m128)sci0->m_velocity;
  v24 = _mm_sub_ps(_mm_mul_ps(v10, v19), v21);
  v25 = _mm_sub_ps(v22, _mm_mul_ps(v9, v19));
  v26 = _mm_mul_ps(v8.m_quad, v23.m_quad);
  v27 = _mm_mul_ps(_mm_add_ps(v23.m_quad, sci1->m_velocity.m_quad), v19);
  v28 = _mm_movelh_ps(
          _mm_unpacklo_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                _mm_shuffle_ps(v27, v27, 170)),
              (__m128)xmmword_141A711B0),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
              _mm_shuffle_ps(v26, v26, 170))),
          _mm_unpacklo_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170)),
            aabbOut.m_quad));
  v29.m_quad = _mm_mul_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v25, v25, 201)),
                     _mm_mul_ps(_mm_shuffle_ps(v28, v28, 0), _mm_shuffle_ps(v11, v11, 201))),
                   _mm_mul_ps(_mm_shuffle_ps(v28, v28, 170), _mm_shuffle_ps(v24, v24, 201))),
                 v18);
  if ( _mm_movemask_ps(
         _mm_cmpltps(
           v15->m_maxSurfaceVelocity.m_quad,
           (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v29.m_quad, 1u), 1u))) & 7 )
  {
LABEL_18:
    v6->m_output->m_planeInteractions[sci0 - v6->m_input->m_constraints].m_status = 2;
    v6->m_output->m_planeInteractions[sci1 - v6->m_input->m_constraints].m_status = 2;
    if ( sci0->m_priority <= sci1->m_priority )
    {
      hkSimplexSolverSolve1d(v6, sci0, velocityIn, velocityOut);
      v47 = v48;
    }
    else
    {
      hkSimplexSolverSolve1d(v6, sci1, velocityIn, velocityOut);
      v47 = v5;
    }
    hkSimplexSolverSolve1d(v45, v47, v46, v46);
  }
  else
  {
    v30 = _mm_sub_ps(velocityIn->m_quad, v29.m_quad);
    v31 = _mm_mul_ps(v30, v30);
    v32 = _mm_mul_ps(v30, v19);
    v33 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
            _mm_shuffle_ps(v31, v31, 170));
    v34 = _mm_mul_ps(v15->m_upVector.m_quad, v19);
    v35 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 0)))
        + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 170));
    v36 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
            _mm_shuffle_ps(v32, v32, 170));
    *(float *)&v49 = sci0->m_staticFriction + sci1->m_staticFriction;
    LODWORD(v37) = (unsigned __int128)_mm_shuffle_ps((__m128)v49, (__m128)v49, 0);
    if ( (float)(v36.m128_f32[0] * v35) <= 0.0 )
      v38 = sci0->m_extraDownStaticFriction + sci1->m_extraDownStaticFriction;
    else
      v38 = sci0->m_extraUpStaticFriction + sci1->m_extraUpStaticFriction;
    v39 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v38), (__m128)LODWORD(v38), 0)) * v35;
    v40 = v36.m128_f32[0] * v36.m128_f32[0];
    *(float *)&v50 = sci0->m_dynamicFriction + sci1->m_dynamicFriction;
    v41 = _mm_mul_ps(_mm_shuffle_ps((__m128)v50, (__m128)v50, 0), (__m128)xmmword_141A711B0);
    if ( (float)((float)((float)((float)(v37 + v39) * 0.5) * (float)((float)(v37 + v39) * 0.5))
               * (float)(v33.m128_f32[0] - v40)) < v40 )
    {
      if ( v41.m128_f32[0] < 1.0
        && v40 > (float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0))
                       * v33.m128_f32[0]) )
      {
        v42 = _mm_rcp_ps(v36);
        v43 = (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v42, v36)), v42);
        v44 = _mm_rsqrt_ps(v33);
        v36 = _mm_mul_ps(
                v36,
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_andnot_ps(
                        _mm_cmpleps(v33, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v44, v33), v44)),
                            _mm_mul_ps(v44, *(__m128 *)_xmm)),
                          v33)),
                      (__m128)_mm_srli_epi32(_mm_slli_epi32(v43, 1u), 1u)),
                    _mm_sub_ps(query.m_quad, v41)),
                  v41));
      }
      velocityOut->m_quad = _mm_add_ps(_mm_mul_ps(v19, v36), v29.m_quad);
    }
    else
    {
      *velocityOut = (hkVector4f)v29.m_quad;
    }
  }
}

// File Line: 314
// RVA: 0xCA77A0
void __fastcall hkSimplexSolverSolve3d(hkSimplexSolverInfo *info, hkSurfaceConstraintInfo *sci0, hkSurfaceConstraintInfo *sci1, hkSurfaceConstraintInfo *sci2, int allowResort, hkVector4f *velocityIn, hkVector4f *velocityOut)
{
  hkVector4f v7; // xmm4
  hkVector4f v8; // xmm2
  hkSurfaceConstraintInfo *v9; // rsi
  hkSurfaceConstraintInfo *v10; // rbp
  hkSurfaceConstraintInfo *v11; // r14
  hkSimplexSolverInfo *v12; // rbx
  hkVector4f v13; // xmm9
  __m128 v14; // xmm1
  __m128 v15; // xmm5
  __m128 v16; // xmm6
  __m128 v17; // xmm0
  __m128 v18; // xmm6
  __m128 v19; // xmm5
  __m128 v20; // xmm8
  __m128 v21; // xmm1
  __m128 v22; // xmm8
  __m128 v23; // xmm5
  __m128 v24; // xmm7
  __m128 v25; // xmm1
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm4
  __m128 v29; // xmm2
  hkVector4f v30; // xmm3
  int v31; // er15
  bool v32; // zf

  v7.m_quad = (__m128)sci0->m_plane;
  v8.m_quad = (__m128)sci2->m_plane;
  v9 = sci2;
  v10 = sci1;
  v11 = sci0;
  v12 = info;
  v13.m_quad = (__m128)sci1->m_plane;
  v14 = _mm_shuffle_ps(v8.m_quad, v8.m_quad, 201);
  v15 = _mm_shuffle_ps(v13.m_quad, v13.m_quad, 201);
  v16 = _mm_sub_ps(_mm_mul_ps(v14, sci1->m_plane.m_quad), _mm_mul_ps(v15, sci2->m_plane.m_quad));
  v17 = _mm_shuffle_ps(v7.m_quad, v7.m_quad, 201);
  v18 = _mm_shuffle_ps(v16, v16, 201);
  v19 = _mm_sub_ps(_mm_mul_ps(v15, sci0->m_plane.m_quad), _mm_mul_ps(v17, sci1->m_plane.m_quad));
  v20 = _mm_sub_ps(_mm_mul_ps(v17, sci2->m_plane.m_quad), _mm_mul_ps(v14, sci0->m_plane.m_quad));
  v21 = _mm_mul_ps(sci0->m_plane.m_quad, v18);
  v22 = _mm_shuffle_ps(v20, v20, 201);
  v23 = _mm_shuffle_ps(v19, v19, 201);
  v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  if ( COERCE_FLOAT((unsigned int)(2 * v24.m128_i32[0]) >> 1) < 0.00000011920929
    || (v25 = _mm_mul_ps(sci0->m_velocity.m_quad, v7.m_quad),
        v26 = _mm_mul_ps(sci2->m_velocity.m_quad, v8.m_quad),
        v27 = _mm_mul_ps(sci1->m_velocity.m_quad, v13.m_quad),
        v28 = _mm_movelh_ps(
                _mm_unpacklo_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                    _mm_shuffle_ps(v25, v25, 170)),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                    _mm_shuffle_ps(v27, v27, 170))),
                _mm_unpacklo_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                    _mm_shuffle_ps(v26, v26, 170)),
                  aabbOut.m_quad)),
        v29 = _mm_rcp_ps(v24),
        v30.m_quad = _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_shuffle_ps(v28, v28, 85), v22),
                           _mm_mul_ps(_mm_shuffle_ps(v28, v28, 0), v18)),
                         _mm_mul_ps(_mm_shuffle_ps(v28, v28, 170), v23)),
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v29, v24)), v29)),
        _mm_movemask_ps(
          _mm_cmpltps(
            info->m_input->m_maxSurfaceVelocity.m_quad,
            (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v30.m_quad, 1u), 1u))) & 7) )
  {
    if ( allowResort )
    {
      hkSimplexSolverSortInfo(info);
      v11 = v12->m_supportPlanes[0].m_constraint;
      v10 = v12->m_supportPlanes[1].m_constraint;
      v9 = v12->m_supportPlanes[2].m_constraint;
    }
    v12->m_output->m_planeInteractions[v11 - v12->m_input->m_constraints].m_status = 1;
    v12->m_output->m_planeInteractions[v10 - v12->m_input->m_constraints].m_status = 1;
    v12->m_output->m_planeInteractions[v9 - v12->m_input->m_constraints].m_status = 1;
    v31 = v12->m_numSupportPlanes;
    hkSimplexSolverSolve2d(v12, v11, v10, velocityIn, velocityOut);
    v32 = v31 == v12->m_numSupportPlanes;
    if ( v31 == v12->m_numSupportPlanes )
    {
      hkSimplexSolverSolve2d(v12, v11, v9, velocityOut, velocityOut);
      v32 = v31 == v12->m_numSupportPlanes;
    }
    if ( v32 )
      hkSimplexSolverSolve2d(v12, v10, v9, velocityOut, velocityOut);
  }
  else
  {
    *velocityOut = (hkVector4f)v30.m_quad;
  }
}

// File Line: 387
// RVA: 0xCA7A70
void __fastcall hkSimplexSolverExamineActivePlanes(hkSimplexSolverInfo *info)
{
  hkSimplexSolverInfo *v1; // rbx
  signed __int64 v2; // rdi
  signed int v3; // er10
  hkSurfaceConstraintInfo **v4; // rsi
  int v5; // er14
  hkSurfaceConstraintInfo *v6; // r14
  hkSurfaceConstraintInfo *v7; // r15
  hkSurfaceConstraintInfo *v8; // r12
  hkSurfaceConstraintInfo *v9; // rsi
  int v10; // edi
  hkSurfaceConstraintInteraction::hkStatus v11; // ecx
  hkSurfaceConstraintInteraction::hkStatus v12; // edx
  hkSurfaceConstraintInteraction::hkStatus v13; // ecx
  hkSurfaceConstraintInteraction::hkStatus v14; // er8
  signed __int64 v15; // rdx
  signed __int64 v16; // rcx
  hkSimplexSolverActivePlanes *v17; // rcx
  hkSimplexSolverActivePlanes *v18; // rcx
  hkSurfaceConstraintInfo **v19; // rsi
  signed __int64 v20; // rdi
  hkSurfaceConstraintInfo **v21; // r14
  signed __int64 v22; // rcx
  hkSurfaceConstraintInfo *v23; // rdx
  hkVector4f *v24; // rax
  hkVector4f velocityIn; // [rsp+10h] [rbp-29h]
  int allowResort[4]; // [rsp+20h] [rbp-19h]
  hkVector4f *velocityOut; // [rsp+30h] [rbp-9h]
  hkVector4f v28; // [rsp+40h] [rbp+7h]
  hkBool result; // [rsp+A0h] [rbp+67h]
  hkBool v30; // [rsp+A8h] [rbp+6Fh]
  hkBool v31; // [rsp+B0h] [rbp+77h]
  hkBool v32; // [rsp+B8h] [rbp+7Fh]

  v1 = info;
  while ( 1 )
  {
LABEL_2:
    if ( v1->m_numSupportPlanes == 1 )
    {
      hkSimplexSolverSolve1d(
        v1,
        v1->m_supportPlanes[0].m_constraint,
        &v1->m_input->m_velocity,
        &v1->m_output->m_velocity);
      return;
    }
    if ( v1->m_numSupportPlanes == 2 )
      break;
    if ( v1->m_numSupportPlanes == 3 )
    {
      hkSimplexSolverSolve1d(
        v1,
        v1->m_supportPlanes[2].m_constraint,
        &v1->m_input->m_velocity,
        (hkVector4f *)allowResort);
      v19 = &v1->m_supportPlanes[0].m_constraint;
      hkSimplexSolverSolveTest1d(&v30, v1->m_supportPlanes[0].m_constraint, (hkVector4f *)allowResort);
      if ( v30.m_bool
        || (hkSimplexSolverSolveTest1d(&v31, v1->m_supportPlanes[1].m_constraint, (hkVector4f *)allowResort), v31.m_bool) )
      {
        v20 = 0i64;
        v21 = &v1->m_supportPlanes[1].m_constraint;
        while ( 1 )
        {
          hkSimplexSolverSolve2d(v1, *v19, v1->m_supportPlanes[2].m_constraint, &v1->m_input->m_velocity, &v28);
          if ( !hkSimplexSolverSolveTest1d(&v32, *v21, &v28)->m_bool )
            break;
          ++v20;
          v19 += 3;
          v21 -= 3;
          if ( v20 >= 2 )
          {
            hkSimplexSolverSolve3d(
              v1,
              v1->m_supportPlanes[0].m_constraint,
              v1->m_supportPlanes[1].m_constraint,
              v1->m_supportPlanes[2].m_constraint,
              1,
              &v1->m_input->m_velocity,
              &v1->m_output->m_velocity);
            return;
          }
        }
        v22 = (signed __int64)&v1->m_supportPlanes[v20];
        *(_QWORD *)&v1->m_supportPlanes[0].m_index = *(_QWORD *)&v1->m_supportPlanes[v20].m_index;
        v1->m_supportPlanes[0].m_constraint = *(hkSurfaceConstraintInfo **)(v22 + 8);
        v1->m_supportPlanes[0].m_interaction = *(hkSurfaceConstraintInteraction **)(v22 + 16);
        *(_QWORD *)&v1->m_supportPlanes[1].m_index = *(_QWORD *)&v1->m_supportPlanes[2].m_index;
        v1->m_supportPlanes[1].m_constraint = v1->m_supportPlanes[2].m_constraint;
        v1->m_supportPlanes[1].m_interaction = v1->m_supportPlanes[2].m_interaction;
        --v1->m_numSupportPlanes;
      }
      else
      {
        v1->m_output->m_velocity = *(hkVector4f *)allowResort;
        *(_QWORD *)&v1->m_supportPlanes[0].m_index = *(_QWORD *)&v1->m_supportPlanes[2].m_index;
        v1->m_supportPlanes[0].m_constraint = v1->m_supportPlanes[2].m_constraint;
        v1->m_supportPlanes[0].m_interaction = v1->m_supportPlanes[2].m_interaction;
        v1->m_numSupportPlanes = 1;
      }
    }
    else
    {
      if ( v1->m_numSupportPlanes != 4 )
        return;
      hkSimplexSolverSortInfo(v1);
      v2 = 0i64;
      v3 = 1;
      v4 = &v1->m_supportPlanes[0].m_constraint;
      do
      {
        v5 = v3 + 1;
        hkSimplexSolverSolve3d(
          v1,
          v1->m_supportPlanes[v3 % 3].m_constraint,
          v1->m_supportPlanes[(v3 + 1) % 3].m_constraint,
          v1->m_supportPlanes[3].m_constraint,
          0,
          &v1->m_input->m_velocity,
          (hkVector4f *)&velocityOut);
        hkSimplexSolverSolveTest1d(&result, *v4, (hkVector4f *)&velocityOut);
        if ( !result.m_bool )
        {
          v18 = &v1->m_supportPlanes[v2];
          *(_QWORD *)&v18->m_index = *(_QWORD *)&v1->m_supportPlanes[2].m_index;
          v18->m_constraint = v1->m_supportPlanes[2].m_constraint;
          v18->m_interaction = v1->m_supportPlanes[2].m_interaction;
          *(_QWORD *)&v1->m_supportPlanes[2].m_index = *(_QWORD *)&v1->m_supportPlanes[3].m_index;
          v1->m_supportPlanes[2].m_constraint = v1->m_supportPlanes[3].m_constraint;
          v1->m_supportPlanes[2].m_interaction = v1->m_supportPlanes[3].m_interaction;
          v1->m_numSupportPlanes = 3;
          goto LABEL_2;
        }
        ++v2;
        v4 += 3;
        v3 = v5;
      }
      while ( v2 < 3 );
      v6 = v1->m_supportPlanes[0].m_constraint;
      v7 = v1->m_supportPlanes[1].m_constraint;
      v8 = v1->m_supportPlanes[2].m_constraint;
      v9 = v1->m_supportPlanes[3].m_constraint;
      _mm_store_si128((__m128i *)&velocityIn, (__m128i)v1->m_input->m_velocity.m_quad);
      v10 = v1->m_numSupportPlanes;
      hkSimplexSolverSolve3d(v1, v6, v7, v8, 0, &velocityIn, &velocityIn);
      if ( v10 == v1->m_numSupportPlanes )
      {
        hkSimplexSolverSolve3d(v1, v6, v7, v9, 0, &velocityIn, &velocityIn);
        if ( v10 == v1->m_numSupportPlanes )
        {
          hkSimplexSolverSolve3d(v1, v6, v8, v9, 0, &velocityIn, &velocityIn);
          if ( v10 == v1->m_numSupportPlanes )
            hkSimplexSolverSolve3d(v1, v7, v8, v9, 0, &velocityIn, &velocityIn);
        }
      }
      v1->m_output->m_velocity = (hkVector4f)velocityIn.m_quad;
      v11 = v1->m_supportPlanes[0].m_interaction->m_status;
      v12 = v1->m_supportPlanes[1].m_interaction->m_status;
      if ( (signed int)v11 < 0 )
        v11 = 0;
      if ( v11 > v12 )
        v12 = v11;
      v13 = v1->m_supportPlanes[2].m_interaction->m_status;
      v14 = v1->m_supportPlanes[3].m_interaction->m_status;
      if ( v12 > v13 )
        v13 = v12;
      v15 = (signed __int64)&v1->m_supportPlanes[0].m_interaction;
      if ( v13 > v14 )
        v14 = v13;
      v16 = 0i64;
      while ( v14 != *(_DWORD *)(*(_QWORD *)v15 + 12i64) )
      {
        ++v16;
        v15 += 24i64;
        if ( v16 >= 4 )
          goto LABEL_26;
      }
      v17 = &v1->m_supportPlanes[v16];
      *(_QWORD *)&v17->m_index = *(_QWORD *)&v1->m_supportPlanes[3].m_index;
      v17->m_constraint = v1->m_supportPlanes[3].m_constraint;
      v17->m_interaction = v1->m_supportPlanes[3].m_interaction;
LABEL_26:
      --v1->m_numSupportPlanes;
      v1->m_supportPlanes[0].m_interaction->m_status = 0;
      v1->m_supportPlanes[1].m_interaction->m_status = 0;
      v1->m_supportPlanes[2].m_interaction->m_status = 0;
    }
  }
  hkSimplexSolverSolve1d(v1, v1->m_supportPlanes[1].m_constraint, &v1->m_input->m_velocity, (hkVector4f *)allowResort);
  hkSimplexSolverSolveTest1d(&result, v1->m_supportPlanes[0].m_constraint, (hkVector4f *)allowResort);
  v24 = &v1->m_output->m_position;
  if ( result.m_bool )
  {
    hkSimplexSolverSolve2d(v1, v23, v1->m_supportPlanes[1].m_constraint, &v1->m_input->m_velocity, v24 + 1);
  }
  else
  {
    v24[1] = *(hkVector4f *)allowResort;
    *(_QWORD *)&v1->m_supportPlanes[0].m_index = *(_QWORD *)&v1->m_supportPlanes[1].m_index;
    v1->m_supportPlanes[0].m_constraint = v1->m_supportPlanes[1].m_constraint;
    v1->m_supportPlanes[0].m_interaction = v1->m_supportPlanes[1].m_interaction;
    v1->m_numSupportPlanes = 1;
  }
}[0].m_interaction = v1->m_supportPlanes[1].m_interaction;
    v1->m_numSupportPlanes = 1;
  }
}

// File Line: 596
// RVA: 0xCA6AC0
void __fastcall hkSimplexSolverSolve(hkSimplexSolverInput *input, hkSimplexSolverOutput *output)
{
  __int64 v2; // r10
  float v3; // xmm8_4
  hkSimplexSolverOutput *v4; // rbx
  __m128 *v5; // r13
  __m128 v6; // xmm9
  hkVector4f v7; // xmm0
  hkSimplexSolverInput *v8; // rsi
  __m128 v9; // xmm9
  int v10; // edx
  signed int v11; // er8
  hkSimplexSolverInput *v12; // r9
  __int64 v13; // rcx
  hkSurfaceConstraintInteraction *v14; // rax
  float v15; // xmm12_4
  int v16; // edi
  int v17; // er11
  __m128 v18; // xmm3
  int v19; // ecx
  __int64 v20; // r9
  __int64 v21; // rdx
  hkSurfaceConstraintInfo *v22; // rax
  __m128 v23; // xmm6
  __m128 v24; // xmm5
  __m128 v25; // xmm2
  __m128 v26; // xmm0
  __m128 v27; // xmm4
  __m128 v28; // xmm1
  __m128 v29; // xmm1
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm2
  __m128 v33; // xmm1
  float v34; // xmm8_4
  __m128 v35; // xmm0
  hkSurfaceConstraintInteraction **v36; // rcx
  __int64 v37; // rdx
  hkSurfaceConstraintInteraction *v38; // rax
  __int64 v39; // rdx
  hkSurfaceConstraintInteraction *v40; // rcx
  hkSurfaceConstraintInfo *v41; // rax
  hkSurfaceConstraintInteraction *v42; // [rsp+20h] [rbp-C0h]
  hkSimplexSolverInfo info; // [rsp+40h] [rbp-A0h]
  unsigned int v44; // [rsp+160h] [rbp+80h]

  v2 = 0i64;
  LODWORD(v42) = -84215046;
  v3 = 0.0;
  v4 = output;
  v5 = &output->m_position.m_quad;
  v6 = (__m128)LODWORD(input->m_deltaTime);
  info.m_supportPlanes[0].m_interaction = 0i64;
  info.m_supportPlanes[1].m_constraint = 0i64;
  v7.m_quad = (__m128)input->m_velocity;
  info.m_supportPlanes[3].m_constraint = (hkSurfaceConstraintInfo *)output;
  v8 = input;
  output->m_velocity = (hkVector4f)v7.m_quad;
  v9 = _mm_shuffle_ps(v6, v6, 0);
  info.m_supportPlanes[0].m_constraint = 0i64;
  info.m_supportPlanes[2].m_constraint = 0i64;
  HIDWORD(info.m_supportPlanes[2].m_interaction) = 0;
  *(_QWORD *)&info.m_supportPlanes[1].m_index = v42;
  info.m_supportPlanes[1].m_constraint = 0i64;
  info.m_supportPlanes[1].m_interaction = 0i64;
  output->m_position = input->m_position;
  *(_QWORD *)&info.m_supportPlanes[0].m_index = v42;
  v10 = 0;
  info.m_supportPlanes[1].m_interaction = v42;
  *(_QWORD *)&info.m_supportPlanes[2].m_index = 0i64;
  info.m_supportPlanes[2].m_constraint = 0i64;
  v11 = 0;
  LODWORD(info.m_supportPlanes[2].m_interaction) = 0;
  v12 = input;
  *(_QWORD *)&info.m_supportPlanes[3].m_index = input;
  if ( input->m_numConstraints > 0 )
  {
    v13 = 0i64;
    do
    {
      v14 = v4->m_planeInteractions;
      ++v10;
      ++v13;
      *(_WORD *)&v14[v13 - 1].m_touched = 0;
      *(_QWORD *)((char *)&v14[v13] - 12) = 0i64;
      *((_DWORD *)&v14[v13] - 1) = 0;
    }
    while ( v10 < v8->m_numConstraints );
  }
  if ( v9.m128_f32[0] >= 0.0 )
  {
    v44 = LODWORD(FLOAT_0_000099999997);
    LODWORD(v15) = (unsigned __int128)_mm_shuffle_ps((__m128)v44, (__m128)v44, 0);
    while ( 1 )
    {
      v16 = v8->m_numConstraints;
      v17 = -1;
      v18 = v9;
      v19 = v2;
      if ( v16 > 0 )
      {
        v20 = 0i64;
        v21 = 0i64;
        do
        {
          if ( (v11 < 1 || info.m_supportPlanes[0].m_index != v19)
            && (v11 < 2 || info.m_supportPlanes[1].m_index != v19)
            && (v11 < 3 || info.m_supportPlanes[2].m_index != v19)
            && v4->m_planeInteractions[v21].m_status == HK_STATUS_OK )
          {
            v22 = v8->m_constraints;
            v23 = v22[v20].m_velocity.m_quad;
            v24 = v22[v20].m_plane.m_quad;
            v25 = _mm_mul_ps(_mm_sub_ps(v4->m_velocity.m_quad, v23), v24);
            v26 = _mm_shuffle_ps(v25, v25, 0);
            v27 = _mm_sub_ps(
                    (__m128)0i64,
                    _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 85), v26), _mm_shuffle_ps(v25, v25, 170)));
            if ( v27.m128_f32[0] > 0.0 )
            {
              v26.m128_f32[0] = *((float *)&info.m_supportPlanes[2].m_interaction + 1);
              v28 = _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v26, v26, 0)), v23),
                        v4->m_position.m_quad),
                      v24);
              v29 = _mm_shuffle_ps(v28, _mm_unpackhi_ps(v28, v24), 196);
              v30 = _mm_add_ps(_mm_shuffle_ps(v29, v29, 78), v29);
              v31 = _mm_add_ps(_mm_shuffle_ps(v30, v30, 177), v30);
              if ( v31.m128_f32[0] <= 0.00000011920929 )
                v31 = 0i64;
              v32 = _mm_add_ps(
                      v31,
                      _mm_shuffle_ps(
                        (__m128)*(unsigned int *)(v5[2].m128_u64[1] + v2 + 8),
                        (__m128)*(unsigned int *)(v5[2].m128_u64[1] + v2 + 8),
                        0));
              if ( v32.m128_f32[0] < (float)(v18.m128_f32[0] * v27.m128_f32[0]) )
              {
                v33 = _mm_rcp_ps(v27);
                v17 = v19;
                v18 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v33, v27)), v33), v32);
              }
            }
          }
          ++v19;
          v2 += 16i64;
          ++v21;
          ++v20;
        }
        while ( v19 < v16 );
        v12 = *(hkSimplexSolverInput **)&info.m_supportPlanes[3].m_index;
      }
      if ( v18.m128_f32[0] > v15 )
      {
        v34 = v3 + v18.m128_f32[0];
        v9 = _mm_sub_ps(v9, v18);
        v35 = _mm_add_ps(_mm_mul_ps(v4->m_velocity.m_quad, v18), v4->m_position.m_quad);
        *((float *)&info.m_supportPlanes[2].m_interaction + 1) = v34;
        v4->m_position.m_quad = v35;
        if ( v11 > 0 )
        {
          v36 = &info.m_supportPlanes[0].m_interaction;
          v37 = (unsigned int)v11;
          do
          {
            v38 = *v36;
            v36 += 3;
            v38->m_surfaceTime = v18.m128_f32[0] + v38->m_surfaceTime;
            v38->m_touched = 1;
            --v37;
          }
          while ( v37 );
        }
        v4->m_deltaTime = v34;
        if ( v34 > v12->m_minDeltaTime )
          break;
      }
      if ( v17 < 0 )
      {
        v4->m_deltaTime = v8->m_deltaTime;
        return;
      }
      v39 = v11;
      LODWORD(info.m_supportPlanes[2].m_interaction) = v11 + 1;
      info.m_supportPlanes[v39].m_index = v17;
      v40 = &v4->m_planeInteractions[v17];
      v41 = &v8->m_constraints[(signed __int64)v17];
      info.m_supportPlanes[v39].m_interaction = v40;
      info.m_supportPlanes[v39].m_constraint = v41;
      v40->m_penaltyDistance = (float)(v40->m_penaltyDistance + 0.00000011920929) * 2.0;
      hkSimplexSolverExamineActivePlanes(&info);
      if ( v9.m128_f32[0] < 0.0 )
        return;
      v5 = &info.m_supportPlanes[3].m_constraint->m_plane.m_quad;
      v3 = *((float *)&info.m_supportPlanes[2].m_interaction + 1);
      v11 = (signed int)info.m_supportPlanes[2].m_interaction;
      v12 = *(hkSimplexSolverInput **)&info.m_supportPlanes[3].m_index;
      v2 = 0i64;
    }
  }
}

