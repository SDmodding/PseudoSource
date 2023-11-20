// File Line: 24
// RVA: 0xBDC230
_BOOL8 __fastcall isRayDegenerate(hkcdRay *ray)
{
  __m128 v1; // xmm2

  v1 = _mm_mul_ps(ray->m_direction.m_quad, ray->m_direction.m_quad);
  return (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v1, v1, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v1, v1, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v1, v1, 170))) <= 0.0;
}

// File Line: 42
// RVA: 0xBD9A00
void __fastcall hkaiLineOfSightUtil::InputBase::InputBase(hkaiLineOfSightUtil::InputBase *this, hkaiLineOfSightUtil::InputBase::QueryMode mode)
{
  this->m_startPoint = (hkVector4f)xmmword_141A712A0;
  this->m_startFaceKey = -1;
  this->m_up = (hkVector4f)xmmword_141A712A0;
  *(_QWORD *)&this->m_maxNumberOfIterations = 100000i64;
  this->m_agentInfo.m_filterInfo = 0;
  this->m_costModifier = 0i64;
  this->m_edgeFilter = 0i64;
  this->m_searchRadius = -1.0;
  this->m_maximumPathLength = 3.40282e38;
  *(_DWORD *)&this->m_outputEdgesOnFailure.m_bool = 65792;
  this->m_mode.m_storage = mode;
}

// File Line: 47
// RVA: 0xBD9A60
void __fastcall hkaiLineOfSightUtil::InputBase::InputBase(hkaiLineOfSightUtil::InputBase *this, hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 55
// RVA: 0xBD9A70
void __fastcall hkaiLineOfSightUtil::LineOfSightInput::LineOfSightInput(hkaiLineOfSightUtil::LineOfSightInput *this)
{
  hkaiLineOfSightUtil::LineOfSightInput *v1; // rbx

  v1 = this;
  hkaiLineOfSightUtil::InputBase::InputBase((hkaiLineOfSightUtil::InputBase *)&this->m_startPoint, 0);
  v1->m_goalFaceKey = -1;
  v1->m_goalPoint = (hkVector4f)xmmword_141A712A0;
}

// File Line: 60
// RVA: 0xBD9AB0
void __fastcall hkaiLineOfSightUtil::LineOfSightInput::LineOfSightInput(hkaiLineOfSightUtil::LineOfSightInput *this, hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 68
// RVA: 0xBD9AC0
void __fastcall hkaiLineOfSightUtil::DirectPathInput::DirectPathInput(hkaiLineOfSightUtil::DirectPathInput *this)
{
  hkaiLineOfSightUtil::DirectPathInput *v1; // rbx

  v1 = this;
  hkaiLineOfSightUtil::InputBase::InputBase((hkaiLineOfSightUtil::InputBase *)&this->m_startPoint, MODE_DIRECT_PATH);
  v1->m_direction = (hkVector4f)xmmword_141A712A0;
}

// File Line: 73
// RVA: 0xBD9AF0
void __fastcall hkaiLineOfSightUtil::DirectPathInput::DirectPathInput(hkaiLineOfSightUtil::DirectPathInput *this, hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 82
// RVA: 0xBD9B00
void __fastcall hkaiLineOfSightUtil::LineOfSightOutput::LineOfSightOutput(hkaiLineOfSightUtil::LineOfSightOutput *this)
{
  this->m_visitedEdgesOut.m_capacityAndFlags = 2147483648;
  this->m_visitedEdgesOut.m_data = 0i64;
  this->m_visitedEdgesOut.m_size = 0;
  this->m_distancesOut.m_data = 0i64;
  this->m_distancesOut.m_size = 0;
  this->m_distancesOut.m_capacityAndFlags = 2147483648;
  this->m_pointsOut.m_data = 0i64;
  this->m_pointsOut.m_size = 0;
  this->m_pointsOut.m_capacityAndFlags = 2147483648;
  this->m_doNotExceedArrayCapacity.m_bool = 0;
  this->m_numIterationsOut = 0;
  this->m_accumulatedDistance = 0.0;
  this->m_finalPoint = (hkVector4f)xmmword_141A712A0;
}

// File Line: 89
// RVA: 0xBD9B50
void __fastcall hkaiLineOfSightUtil::LineOfSightOutput::LineOfSightOutput(hkaiLineOfSightUtil::LineOfSightOutput *this, hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 99
// RVA: 0xBDC270
signed __int64 __fastcall hkcdRayCastCapsuleWrapper(hkcdRay *ray, hkVector4f *vertex0, hkVector4f *vertex1, hkSimdFloat32 *radius, hkSimdFloat32 *fractionInOut)
{
  __m128 v5; // xmm13
  __m128 v6; // xmm6
  __m128 v7; // xmm4
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm0
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm7
  __m128 v17; // xmm0
  __m128 v18; // xmm4
  __m128 v19; // xmm4
  __m128 v21; // xmm14
  __m128 v22; // xmm2
  hkVector4f v23; // xmm9
  hkVector4f v24; // STB0_16
  __m128 v25; // xmm1
  __m128 v26; // xmm5
  __m128 v27; // xmm15
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm0
  __m128 v33; // xmm5
  __m128 v34; // xmm5
  int v35; // er11
  hkVector4f v36; // xmm7
  __m128 v37; // xmm0
  __m128 v38; // xmm1
  __m128 v39; // xmm7
  __m128 v40; // xmm5
  __m128 v41; // xmm4
  __m128 v42; // xmm1
  __m128 v43; // xmm0
  __m128 v44; // xmm2
  __m128 v45; // xmm0
  __m128 v46; // xmm5
  __m128 v47; // xmm5
  float v48; // xmm8_4
  __m128 v49; // xmm3
  __m128 v50; // xmm2
  __m128 v51; // xmm7
  __m128 v52; // xmm1
  __m128 v53; // xmm2
  __m128 v54; // xmm1
  __m128 v55; // xmm5
  __m128 v56; // xmm0
  __m128 v57; // xmm1
  hkVector4f v58; // xmm5
  unsigned int v59; // edx
  __m128 v60; // xmm2
  __m128 v61; // xmm1
  __m128 v62; // xmm3
  __m128 v63; // xmm2
  __m128 v64; // xmm6
  __m128 v65; // xmm3
  __m128 v66; // xmm7
  __m128 v67; // xmm8
  __m128 v68; // xmm5
  __m128 v69; // xmm1
  __m128 v70; // xmm2
  __m128 v71; // xmm2
  __m128 v72; // xmm4
  __m128 v73; // xmm0
  __m128 v74; // xmm3
  __m128 v75; // xmm2
  __m128 v76; // xmm1
  __m128 v77; // xmm0
  __m128 v78; // xmm2
  __m128 v79; // xmm0
  __m128 v80; // xmm2
  __m128 v81; // xmm2
  __m128 v82; // xmm7
  __m128 v83; // xmm3
  __m128 v84; // xmm1
  __m128 v85; // xmm2
  __m128 v86; // xmm7
  __m128 v87; // xmm2
  __m128 v88; // xmm3
  __m128 v89; // xmm3
  __m128 v90; // xmm4
  __m128 v91; // xmm6
  __m128 v92; // xmm1
  __m128 v93; // xmm5
  __m128 v94; // xmm1
  __m128 v95; // xmm4
  __m128 v96; // xmm1
  __m128 v97; // xmm2
  __m128 v98; // xmm1
  __m128 v99; // xmm5
  __m128 v100; // xmm10
  __m128 v101; // xmm15
  __m128 v102; // xmm7
  __m128 v103; // xmm1
  __m128 v104; // xmm2
  __m128 v105; // xmm2
  __m128 v106; // xmm5
  __m128 v107; // xmm4
  __m128 v108; // xmm4
  __m128 v109; // xmm9
  __m128 v110; // xmm4
  __m128 v111; // xmm2
  __m128i v112; // xmm7
  __m128 v113; // xmm6
  __m128 v114; // xmm13
  __m128 v115; // xmm2
  __m128 v116; // xmm3
  __m128 v117; // xmm3
  __m128 v118; // xmm5
  __m128 v119; // xmm1
  signed int v120; // ecx
  signed int v121; // eax
  __m128 v122; // xmm2
  __m128 v123; // xmm1
  __m128 v124; // xmm3
  __m128 v125; // xmm2
  __m128 v126; // xmm2
  hkVector4f v127; // xmm4
  __m128 v128; // xmm13
  __m128 v129; // xmm8
  __m128 v130; // xmm13
  __m128 v131; // xmm2
  __m128i v132; // xmm5
  __m128 v133; // xmm1
  __m128 v134; // xmm6
  __m128 v135; // xmm2
  __m128 v136; // xmm7
  __m128 v137; // xmm3
  __m128 v138; // xmm3
  __m128 v139; // xmm4
  __m128 v140; // xmm1
  signed int v141; // ecx
  signed int v142; // eax
  __m128 v143; // xmm3
  __m128 v144; // xmm1
  __m128 v145; // xmm2
  __m128 v146; // xmm5
  hkVector4f v147; // [rsp+0h] [rbp-168h]
  __m128 v148; // [rsp+10h] [rbp-158h]
  __m128 v149; // [rsp+20h] [rbp-148h]
  __m128 v150; // [rsp+30h] [rbp-138h]
  __m128 v151; // [rsp+40h] [rbp-128h]
  __m128 v152; // [rsp+50h] [rbp-118h]
  __m128 v153; // [rsp+60h] [rbp-108h]
  __m128 v154; // [rsp+70h] [rbp-F8h]

  v5 = vertex0->m_quad;
  v6 = _mm_sub_ps(vertex0->m_quad, vertex1->m_quad);
  v7 = _mm_sub_ps(vertex0->m_quad, ray->m_origin.m_quad);
  v8 = _mm_mul_ps(v6, v6);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_mul_ps(v6, v7);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_rcp_ps(v9);
  v13 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v12));
  v14 = radius->m_real;
  v15 = _mm_mul_ps(_mm_mul_ps(v13, v12), v11);
  v16 = _mm_mul_ps(v14, v14);
  v151 = v16;
  v17 = _mm_cmpltps(v15, query.m_quad);
  v18 = _mm_sub_ps(
          v7,
          _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v15, v17), _mm_andnot_ps(v17, query.m_quad))), v6));
  v19 = _mm_mul_ps(v18, v18);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 170))) < v16.m128_f32[0] )
  {
    *fractionInOut = 0i64;
    return 1i64;
  }
  v21 = _mm_sub_ps(vertex1->m_quad, v5);
  v22 = _mm_mul_ps(v21, v21);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 170))) <= 0.0 )
  {
    v127.m_quad = (__m128)ray->m_direction;
    v128 = _mm_shuffle_ps(v5, _mm_unpackhi_ps(v5, v14), 196);
    v129 = _mm_sub_ps(ray->m_origin.m_quad, v128);
    v130 = _mm_shuffle_ps(v128, v128, 255);
    v131 = _mm_mul_ps(ray->m_direction.m_quad, v129);
    v132 = (__m128i)_mm_sub_ps(
                      (__m128)0i64,
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v131, v131, 85), _mm_shuffle_ps(v131, v131, 0)),
                        _mm_shuffle_ps(v131, v131, 170)));
    v133 = _mm_mul_ps(v127.m_quad, v127.m_quad);
    v134 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v133, v133, 85), _mm_shuffle_ps(v133, v133, 0)),
             _mm_shuffle_ps(v133, v133, 170));
    v135 = _mm_cmpeqps((__m128)0i64, v134);
    v136 = _mm_rcp_ps(v134);
    v137 = _mm_add_ps(
             _mm_mul_ps(
               _mm_or_ps(
                 _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v132, 0x1Fu), 0x1Fu), (__m128)_xmm), v135),
                 _mm_andnot_ps(
                   v135,
                   _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v136, v134)), v136), (__m128)v132))),
               v127.m_quad),
             v129);
    v138 = _mm_mul_ps(v137, v137);
    v139 = _mm_mul_ps(
             _mm_sub_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v138, v138, 85), _mm_shuffle_ps(v138, v138, 0)),
                 _mm_shuffle_ps(v138, v138, 170)),
               _mm_mul_ps(v130, v130)),
             _mm_sub_ps((__m128)0i64, v134));
    if ( v139.m128_f32[0] >= 0.0 )
    {
      v140 = _mm_rsqrt_ps(v139);
      v59 = 0;
      v141 = 0;
      v142 = 0;
      v143 = _mm_andnot_ps(
               _mm_cmpleps(v139, (__m128)0i64),
               _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v139, v140), v140)),
                   _mm_mul_ps(*(__m128 *)_xmm, v140)),
                 v139));
      v144 = _mm_add_ps(_mm_sub_ps((__m128)0i64, v143), (__m128)v132);
      v145 = _mm_and_ps(_mm_cmpltps(v144, (__m128)0i64), *(__m128 *)hkVector4fComparison_maskToComparison_180);
      v146 = _mm_or_ps(_mm_and_ps(_mm_add_ps((__m128)v132, v143), v145), _mm_andnot_ps(v145, v144));
      if ( v146.m128_f32[0] >= (float)(fractionInOut->m_real.m128_f32[0] * v134.m128_f32[0]) )
        v141 = 1;
      if ( v146.m128_f32[0] < 0.0 )
        v142 = 1;
      if ( !(v142 | v141) )
      {
        v59 = 16 * _mm_movemask_ps(v145) | 1;
        fractionInOut->m_real = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v136, v134)), v136), v146);
      }
    }
    else
    {
      v59 = 0;
    }
    return v59;
  }
  v23.m_quad = (__m128)ray->m_origin;
  v147.m_quad = (__m128)ray->m_direction;
  v24.m_quad = (__m128)ray->m_invDirection;
  v25 = _mm_mul_ps(v6, v6);
  v150 = fractionInOut->m_real;
  v149 = query.m_quad;
  v26 = _mm_sub_ps(v5, ray->m_origin.m_quad);
  v27 = 0i64;
  v28 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)), _mm_shuffle_ps(v25, v25, 170));
  v29 = _mm_mul_ps(v26, v6);
  v30 = _mm_rcp_ps(v28);
  v31 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v28, v30)), v30),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
            _mm_shuffle_ps(v29, v29, 170)));
  v32 = _mm_cmpltps(v31, query.m_quad);
  v33 = _mm_sub_ps(
          v26,
          _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v32, v31), _mm_andnot_ps(v32, query.m_quad))), v6));
  v34 = _mm_mul_ps(v33, v33);
  v35 = _mm_movemask_ps(
          _mm_cmpltps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
              _mm_shuffle_ps(v34, v34, 170)),
            v16));
  if ( v35 == 15 )
  {
    if ( _mm_movemask_ps(*(__m128 *)hkVector4fComparison_maskToComparison_180) != 15 )
      return 0;
    v36.m_quad = (__m128)ray->m_direction;
    v27 = *(__m128 *)&hkVector4fComparison_maskToComparison_180[60];
    v37 = _mm_mul_ps(fractionInOut->m_real, v36.m_quad);
    v38 = _mm_mul_ps(v6, v6);
    v39 = _mm_mul_ps(v36.m_quad, v36.m_quad);
    v40 = _mm_sub_ps(v5, _mm_add_ps(v37, ray->m_origin.m_quad));
    v41 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
            _mm_shuffle_ps(v38, v38, 170));
    v42 = _mm_mul_ps(v40, v6);
    v43 = _mm_rcp_ps(v41);
    v44 = _mm_mul_ps(
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v41, v43)), v43),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)),
              _mm_shuffle_ps(v42, v42, 170)));
    v45 = _mm_cmpltps(v44, query.m_quad);
    v46 = _mm_sub_ps(
            v40,
            _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v45, query.m_quad), _mm_and_ps(v45, v44))), v6));
    v47 = _mm_mul_ps(v46, v46);
    v48 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 0)))
        + COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 170));
    v49 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
            _mm_shuffle_ps(v39, v39, 170));
    v50 = _mm_rsqrt_ps(v49);
    v51 = _mm_andnot_ps(
            _mm_cmpleps(v49, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v49), v50)),
                _mm_mul_ps(*(__m128 *)_xmm, v50)),
              v49));
    v52 = _mm_mul_ps(v21, v21);
    v53 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
            _mm_shuffle_ps(v52, v52, 170));
    v54 = _mm_rsqrt_ps(v53);
    v55 = _mm_mul_ps(*(__m128 *)_xmm, v54);
    v56 = _mm_mul_ps(_mm_mul_ps(v54, v53), v54);
    v57 = _mm_rcp_ps(v51);
    v150.m128_i32[0] = query.m_quad.m128_i32[0];
    v149 = _mm_andnot_ps(
             _mm_cmpeqps(v51, (__m128)0i64),
             _mm_mul_ps(
               _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v57, v51)), v57),
               _mm_min_ps(
                 _mm_add_ps(
                   _mm_andnot_ps(
                     _mm_cmpleps(v53, (__m128)0i64),
                     _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v56), v55), v53)),
                   _mm_mul_ps(radius->m_real, (__m128)xmmword_141A710F0)),
                 _mm_mul_ps(fractionInOut->m_real, v51))));
    v58.m_quad = _mm_xor_ps(
                   (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
                   _mm_mul_ps(ray->m_direction.m_quad, v149));
    v147.m_quad = v58.m_quad;
    v23.m_quad = _mm_sub_ps(ray->m_origin.m_quad, v58.m_quad);
    if ( v48 < v151.m128_f32[0] )
      return 0;
  }
  else
  {
    v58.m_quad = (__m128)ray->m_direction;
  }
  v60 = _mm_sub_ps(v5, v23.m_quad);
  v61 = _mm_mul_ps(v58.m_quad, v21);
  v62 = v60;
  v63 = _mm_mul_ps(v60, v21);
  v154 = _mm_mul_ps(v58.m_quad, v58.m_quad);
  v64 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v63, v63, 85), _mm_shuffle_ps(v63, v63, 0)), _mm_shuffle_ps(v63, v63, 170));
  v65 = _mm_mul_ps(v62, v58.m_quad);
  v66 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v61, v61, 85), _mm_shuffle_ps(v61, v61, 0)), _mm_shuffle_ps(v61, v61, 170));
  v67 = _mm_mul_ps(v21, v21);
  v68 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v67, v67, 85), _mm_shuffle_ps(v67, v67, 0)), _mm_shuffle_ps(v67, v67, 170));
  v69 = _mm_mul_ps(
          v68,
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v154, v154, 85), _mm_shuffle_ps(v154, v154, 0)),
            _mm_shuffle_ps(v154, v154, 170)));
  v70 = _mm_add_ps(*(__m128 *)&epsilon, *(__m128 *)&epsilon);
  v71 = _mm_add_ps(v70, v70);
  v72 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)),
              _mm_shuffle_ps(v65, v65, 170)),
            v68),
          _mm_mul_ps(v64, v66));
  v73 = _mm_mul_ps(v66, v66);
  v74 = _mm_sub_ps(v69, v73);
  v75 = _mm_cmpltps(_mm_mul_ps(v71, _mm_add_ps(v73, v69)), v74);
  v76 = _mm_or_ps(_mm_andnot_ps(v75, v72), _mm_and_ps(v74, v75));
  v77 = _mm_rcp_ps(v76);
  v78 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v76, v77)), v77);
  v79 = _mm_rcp_ps(v68);
  v153 = _mm_mul_ps(v78, v72);
  v80 = _mm_sub_ps(
          _mm_add_ps(_mm_mul_ps(v153, v147.m_quad), v23.m_quad),
          _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v68, v79)), v79),
                _mm_sub_ps(_mm_mul_ps(v66, v153), v64)),
              v21),
            v5));
  v81 = _mm_mul_ps(v80, v80);
  v152 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v81, v81, 85), _mm_shuffle_ps(v81, v81, 0)),
           _mm_shuffle_ps(v81, v81, 170));
  if ( v152.m128_f32[0] <= v151.m128_f32[0] )
  {
    v82 = _mm_cmpltps(
            *(__m128 *)&epsilon,
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v67, v67, 85), _mm_shuffle_ps(v67, v67, 0)),
              _mm_shuffle_ps(v67, v67, 170)));
    v83 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v67, v67, 85), _mm_shuffle_ps(v67, v67, 0)),
            _mm_shuffle_ps(v67, v67, 170));
    v84 = _mm_rsqrt_ps(v83);
    v85 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v84, v83), v84)), _mm_mul_ps(*(__m128 *)_xmm, v84));
    v148 = _mm_and_ps(_mm_mul_ps(v85, v83), v82);
    v86 = _mm_and_ps(_mm_mul_ps(v21, v85), v82);
    v87 = _mm_mul_ps(v86, v147.m_quad);
    v88 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v87, v87, 85), _mm_shuffle_ps(v87, v87, 0)),
                  _mm_shuffle_ps(v87, v87, 170))),
              v86),
            v147.m_quad);
    v89 = _mm_mul_ps(v88, v88);
    v90 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v89, v89, 85), _mm_shuffle_ps(v89, v89, 0)),
            _mm_shuffle_ps(v89, v89, 170));
    v91 = _mm_cmpeqps((__m128)0i64, v90);
    v92 = _mm_rcp_ps(v90);
    v93 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v92, v90)), v92), _mm_sub_ps(v151, v152));
    v94 = _mm_rsqrt_ps(v93);
    v95 = _mm_or_ps(
            _mm_andnot_ps(
              v91,
              _mm_sub_ps(
                v153,
                _mm_andnot_ps(
                  _mm_cmpleps(v93, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v93, v94), v94)),
                      _mm_mul_ps(*(__m128 *)_xmm, v94)),
                    v93)))),
            _mm_and_ps(v91, g_vectorfConstants[0]));
    if ( v95.m128_f32[0] < v150.m128_f32[0] )
    {
      v96 = _mm_mul_ps(v5, v86);
      v97 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v96, v96, 85), _mm_shuffle_ps(v96, v96, 0)),
              _mm_shuffle_ps(v96, v96, 170));
      v98 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v95, v147.m_quad), v23.m_quad), v86);
      v99 = _mm_sub_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v98, v98, 85), _mm_shuffle_ps(v98, v98, 0)),
                _mm_shuffle_ps(v98, v98, 170)),
              v97);
      if ( v95.m128_f32[0] >= 0.0 && v99.m128_f32[0] > 0.0 && v99.m128_f32[0] < v148.m128_f32[0] )
      {
        v59 = 16 * v35 | 1;
        v100 = _mm_and_ps(_mm_mul_ps(_mm_sub_ps(query.m_quad, v95), v149), v27);
        v101 = _mm_andnot_ps(v27, v95);
LABEL_25:
        fractionInOut->m_real = _mm_or_ps(v100, v101);
        return v59;
      }
      v102 = _mm_mul_ps(v86, v23.m_quad);
      v103 = _mm_rcp_ps(v148);
      v104 = _mm_sub_ps(
               v23.m_quad,
               _mm_add_ps(
                 _mm_mul_ps(
                   v21,
                   _mm_mul_ps(
                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v103, v148)), v103),
                     _mm_sub_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v102, v102, 85), _mm_shuffle_ps(v102, v102, 0)),
                         _mm_shuffle_ps(v102, v102, 170)),
                       v97))),
                 v5));
      if ( v95.m128_f32[0] >= 0.0
        || (v105 = _mm_mul_ps(v104, v104),
            (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v105, v105, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v105, v105, 0)))
                  + COERCE_FLOAT(_mm_shuffle_ps(v105, v105, 170))) <= v151.m128_f32[0]) )
      {
        v106 = _mm_cmpleps(v99, (__m128)0i64);
        v59 = 0;
        v107 = _mm_or_ps(_mm_andnot_ps(v106, vertex1->m_quad), _mm_and_ps(v5, v106));
        v108 = _mm_shuffle_ps(v107, _mm_unpackhi_ps(v107, radius->m_real), 196);
        v109 = _mm_sub_ps(v23.m_quad, v108);
        v110 = _mm_shuffle_ps(v108, v108, 255);
        v111 = _mm_mul_ps(v109, v147.m_quad);
        v112 = (__m128i)_mm_sub_ps(
                          (__m128)0i64,
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v111, v111, 85), _mm_shuffle_ps(v111, v111, 0)),
                            _mm_shuffle_ps(v111, v111, 170)));
        v113 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v154, v154, 85), _mm_shuffle_ps(v154, v154, 0)),
                 _mm_shuffle_ps(v154, v154, 170));
        v114 = _mm_rcp_ps(v113);
        v115 = _mm_cmpeqps(v113, (__m128)0i64);
        v116 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_or_ps(
                     _mm_and_ps(
                       _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v112, 0x1Fu), 0x1Fu), (__m128)_xmm),
                       v115),
                     _mm_andnot_ps(
                       v115,
                       _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v114, v113)), v114), (__m128)v112))),
                   v147.m_quad),
                 v109);
        v117 = _mm_mul_ps(v116, v116);
        v118 = _mm_mul_ps(
                 _mm_sub_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v117, v117, 85), _mm_shuffle_ps(v117, v117, 0)),
                     _mm_shuffle_ps(v117, v117, 170)),
                   _mm_mul_ps(v110, v110)),
                 _mm_sub_ps((__m128)0i64, v113));
        if ( v118.m128_f32[0] < 0.0 )
          return v59;
        v119 = _mm_rsqrt_ps(v118);
        v120 = 0;
        v121 = 0;
        v122 = _mm_andnot_ps(
                 _mm_cmpleps(v118, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v119, v118), v119)),
                     _mm_mul_ps(*(__m128 *)_xmm, v119)),
                   v118));
        v123 = _mm_add_ps(_mm_sub_ps((__m128)0i64, v122), (__m128)v112);
        v124 = _mm_and_ps(_mm_cmpltps(v123, (__m128)0i64), *(__m128 *)hkVector4fComparison_maskToComparison_180);
        v125 = _mm_or_ps(_mm_and_ps(_mm_add_ps(v122, (__m128)v112), v124), _mm_andnot_ps(v124, v123));
        if ( v125.m128_f32[0] >= (float)(v113.m128_f32[0] * v150.m128_f32[0]) )
          v120 = 1;
        if ( v125.m128_f32[0] < 0.0 )
          v121 = 1;
        if ( v121 | v120 )
          return v59;
        v126 = _mm_mul_ps(v125, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v114, v113)), v114));
        if ( !(16 * _mm_movemask_ps(v124) | 1) )
          return v59;
        v59 = 16 * v35 | 1;
        v100 = _mm_and_ps(_mm_mul_ps(_mm_sub_ps(query.m_quad, v126), v149), v27);
        v101 = _mm_andnot_ps(v27, v126);
        goto LABEL_25;
      }
    }
  }
  return 0;
}

// File Line: 126
// RVA: 0xBD9CA0
__int64 __fastcall hkaiLineOfSightUtil::checkLineOfSight(hkaiStreamingCollection *collection, hkaiLineOfSightUtil::LineOfSightInput *input, hkaiLineOfSightUtil::LineOfSightOutput *output)
{
  return hkaiLineOfSightUtil::checkLineOfSight(collection->m_instances.m_data, input, output);
}

// File Line: 131
// RVA: 0xBD9B60
__int64 __fastcall hkaiLineOfSightUtil::checkLineOfSight(hkaiStreamingCollection::InstanceInfo *streamingInfo, hkaiLineOfSightUtil::LineOfSightInput *input, hkaiLineOfSightUtil::LineOfSightOutput *output)
{
  hkaiStreamingCollection::InstanceInfo *v3; // rsi
  hkaiLineOfSightUtil::LineOfSightOutput *v4; // rdi
  hkaiLineOfSightUtil::LineOfSightInput *v5; // rbx
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  unsigned int v11; // er8
  __m128 v12; // xmm5
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  BOOL v16; // ebx
  _QWORD *v17; // r8
  _QWORD *v18; // rcx
  unsigned __int64 v19; // rax
  signed __int64 v20; // rcx
  hkVector4f directionIn; // [rsp+30h] [rbp-18h]

  v3 = streamingInfo;
  v4 = output;
  v5 = input;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtlineOfSight";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  if ( v5->m_startFaceKey == -1 || (v11 = v5->m_goalFaceKey, v11 == -1) )
  {
    v16 = 0;
  }
  else
  {
    v12 = _mm_sub_ps(v5->m_goalPoint.m_quad, v5->m_startPoint.m_quad);
    v13 = _mm_mul_ps(v12, v12);
    v14 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170));
    v15 = _mm_rsqrt_ps(v14);
    directionIn.m_quad = _mm_mul_ps(
                           v12,
                           _mm_andnot_ps(
                             _mm_cmpleps(v14, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
                               _mm_mul_ps(*(__m128 *)_xmm, v15))));
    v16 = hkaiLineOfSightUtil::_lineOfSightInternal(
            &directionIn,
            &v5->m_goalPoint,
            v11,
            v3,
            (hkaiLineOfSightUtil::InputBase *)&v5->m_startPoint,
            v4) == 9;
  }
  v17 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v18 = (_QWORD *)v17[1];
  if ( (unsigned __int64)v18 < v17[3] )
  {
    *v18 = "Et";
    v19 = __rdtsc();
    v20 = (signed __int64)(v18 + 2);
    *(_DWORD *)(v20 - 8) = v19;
    v17[1] = v20;
  }
  return (unsigned int)v16;
}

// File Line: 144
// RVA: 0xBD9CB0
__int64 __fastcall hkaiLineOfSightUtil::findDirectPath(hkaiStreamingCollection *collection, hkaiLineOfSightUtil::DirectPathInput *input, hkaiLineOfSightUtil::LineOfSightOutput *output)
{
  hkaiStreamingCollection *v3; // rsi
  hkaiLineOfSightUtil::LineOfSightOutput *v4; // rdi
  hkaiLineOfSightUtil::DirectPathInput *v5; // rbx
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  __m128 v11; // xmm4
  __m128 v12; // xmm1
  hkaiStreamingCollection::InstanceInfo *v13; // r9
  hkaiLineOfSightUtil::LineOfSightResult v14; // ebx
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  signed __int64 v18; // rcx
  hkVector4f goalPoint; // [rsp+30h] [rbp-18h]

  v3 = collection;
  v4 = output;
  v5 = input;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtfindDirectPath";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = v5->m_direction.m_quad;
  if ( _mm_movemask_ps(_mm_cmpunordps(v11, v11)) & 7
    || (v12 = _mm_mul_ps(v11, v11),
        COERCE_FLOAT((unsigned int)(2
                                  * COERCE_SIGNED_INT(
                                      (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85))
                                                    + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
                                            + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170)))
                                    - 1.0)) >> 1) >= COERCE_FLOAT(
                                                       _mm_shuffle_ps(
                                                         (__m128)LODWORD(FLOAT_0_000099999997),
                                                         (__m128)LODWORD(FLOAT_0_000099999997),
                                                         0))) )
  {
    v14 = 0;
  }
  else
  {
    v13 = v3->m_instances.m_data;
    goalPoint.m_quad = _mm_add_ps(v11, v5->m_startPoint.m_quad);
    v14 = hkaiLineOfSightUtil::_lineOfSightInternal(
            &v5->m_direction,
            &goalPoint,
            0xFFFFFFFF,
            v13,
            (hkaiLineOfSightUtil::InputBase *)&v5->m_startPoint,
            v4);
  }
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "Et";
    v17 = __rdtsc();
    v18 = (signed __int64)(v16 + 2);
    *(_DWORD *)(v18 - 8) = v17;
    v15[1] = v18;
  }
  return (unsigned int)v14;
}

// File Line: 160
// RVA: 0xBDCDC0
void __fastcall projectPoint(hkVector4f *pointInOut, hkVector4f *up)
{
  __m128 v2; // xmm1

  v2 = _mm_mul_ps(up->m_quad, pointInOut->m_quad);
  pointInOut->m_quad = _mm_sub_ps(
                         pointInOut->m_quad,
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v2, v2, 85), _mm_shuffle_ps(v2, v2, 0)),
                             _mm_shuffle_ps(v2, v2, 170)),
                           up->m_quad));
}

// File Line: 173
// RVA: 0xBDBF70
unsigned int __fastcall hkaiLineOfSightUtil::_raycastAgainstBoundary(hkVector4f *start, hkVector4f *end, hkSimdFloat32 *radius, bool shouldProject, hkVector4f *up, hkVector4f *edgeA, hkVector4f *edgeB, hkSimdFloat32 *hitFractionInOut)
{
  __m128 v8; // xmm6
  __m128 v9; // xmm7
  __m128 v10; // xmm1
  __m128 v11; // xmm4
  __m128 v12; // xmm5
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128i v20; // xmm6
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm5
  unsigned int result; // eax
  hkVector4f vertex1; // [rsp+30h] [rbp-78h]
  hkVector4f vertex0; // [rsp+40h] [rbp-68h]
  hkcdRay ray; // [rsp+50h] [rbp-58h]

  v8 = end->m_quad;
  v9 = start->m_quad;
  v10 = edgeB->m_quad;
  _mm_store_si128((__m128i *)&vertex0, (__m128i)edgeA->m_quad);
  _mm_store_si128((__m128i *)&vertex1, (__m128i)v10);
  if ( shouldProject )
  {
    v11 = edgeB->m_quad;
    v12 = up->m_quad;
    v13 = _mm_mul_ps(up->m_quad, v9);
    v14 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170));
    v15 = _mm_mul_ps(up->m_quad, v8);
    v9 = _mm_sub_ps(v9, _mm_mul_ps(v14, up->m_quad));
    v16 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
            _mm_shuffle_ps(v15, v15, 170));
    v17 = _mm_mul_ps(up->m_quad, edgeA->m_quad);
    v8 = _mm_sub_ps(v8, _mm_mul_ps(v16, up->m_quad));
    v18 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
            _mm_shuffle_ps(v17, v17, 170));
    v19 = _mm_mul_ps(up->m_quad, edgeB->m_quad);
    vertex0.m_quad = _mm_sub_ps(edgeA->m_quad, _mm_mul_ps(v18, up->m_quad));
    vertex1.m_quad = _mm_sub_ps(
                       v11,
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                           _mm_shuffle_ps(v19, v19, 170)),
                         v12));
  }
  v20 = (__m128i)_mm_sub_ps(v8, v9);
  ray.m_origin.m_quad = v9;
  v21 = _mm_rcp_ps((__m128)v20);
  v22 = _mm_cmpeqps((__m128)0i64, (__m128)v20);
  ray.m_direction.m_quad = _mm_shuffle_ps((__m128)v20, _mm_unpackhi_ps((__m128)v20, hitFractionInOut->m_real), 196);
  v23 = _mm_mul_ps(ray.m_direction.m_quad, ray.m_direction.m_quad);
  ray.m_invDirection.m_quad = _mm_or_ps(
                                _mm_and_ps(
                                  _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v20, 0x1Fu), 0x1Fu), (__m128)_xmm),
                                  v22),
                                _mm_andnot_ps(
                                  v22,
                                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v20, v21)), v21)));
  ray.m_invDirection.m_quad.m128_i32[3] = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, ray.m_direction.m_quad)) & 7 | 0x3F000000;
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 170))) > 0.0 )
    result = hkcdRayCastCapsuleWrapper(&ray, &vertex0, &vertex1, radius, hitFractionInOut);
  else
    result = 0;
  return result;
}

// File Line: 204
// RVA: 0xBDB1C0
__int64 __fastcall hkaiLineOfSightUtil::_checkAgainstNearbyBoundaries(hkVector4f *start, hkVector4f *end, hkVector4f *currentUp, hkSimdFloat32 *radius, hkaiGeneralAccessor *accessor, hkaiLineOfSightUtil::InputBase *input, unsigned int faceKeyIn, hkSimdFloat32 *hitFractionInOut)
{
  hkVector4f *v8; // rdi
  hkSimdFloat32 *v9; // r15
  hkVector4f *v10; // rbx
  _QWORD *v11; // rax
  _QWORD *v12; // rcx
  _QWORD *v13; // r9
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx
  hkVector4f v16; // xmm5
  __m128 v17; // xmm4
  unsigned int v18; // esi
  __m128i v19; // xmm4
  __m128 v20; // xmm8
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm15
  __m128 v24; // xmm2
  hkLifoAllocator *v25; // rax
  unsigned int *v26; // rcx
  unsigned __int64 v27; // rdx
  int v28; // ebx
  hkLifoAllocator *v29; // rax
  char *v30; // r9
  int v31; // edx
  char *v32; // rcx
  int v33; // ecx
  unsigned int *v34; // r9
  unsigned int v35; // edi
  int v36; // er8
  int v37; // ecx
  unsigned int v38; // edx
  int v39; // eax
  int v40; // er10
  signed int v41; // er11
  int v42; // ecx
  unsigned int v43; // edx
  hkaiNavMesh::Face *v44; // rax
  int v45; // edi
  int index; // er12
  hkaiNavMesh::Edge *v47; // rax
  unsigned __int64 v48; // rdx
  signed int v49; // er8
  __int64 v50; // rbx
  __int64 v51; // rax
  __m128 *v52; // rcx
  __m128 v53; // xmm3
  __m128 v54; // xmm4
  __int64 v55; // rax
  __m128 v56; // xmm5
  __m128 v57; // xmm6
  __m128 v58; // xmm14
  __m128 *v59; // rax
  __m128 v60; // xmm1
  __m128 v61; // xmm0
  __m128 v62; // xmm2
  __m128 v63; // xmm0
  __m128 v64; // xmm13
  __m128 v65; // xmm12
  __m128 v66; // xmm2
  __m128 v67; // xmm1
  __m128 v68; // xmm11
  __m128 v69; // xmm1
  __m128 v70; // xmm2
  __m128 v71; // xmm10
  __m128 v72; // xmm9
  __m128 v73; // xmm1
  __m128 v74; // xmm2
  __m128 v75; // xmm1
  __m128 v76; // xmm7
  __m128 v77; // xmm6
  __m128 v78; // xmm1
  __m128 v79; // xmm3
  __m128 v80; // xmm1
  __m128 v81; // xmm5
  __m128 v82; // xmm1
  __m128 v83; // xmm0
  __m128 v84; // xmm2
  __m128 v85; // xmm8
  __m128 v86; // xmm7
  __m128 v87; // xmm0
  __m128 v88; // xmm3
  __m128 v89; // xmm1
  __m128 v90; // xmm2
  __m128 v91; // xmm11
  __m128 v92; // xmm1
  __int128 v93; // xmm4
  __m128 v94; // xmm3
  __m128 v95; // xmm3
  signed int v96; // eax
  bool v97; // r15
  unsigned __int64 v98; // rcx
  __int128 v99; // xmm0
  int v100; // ecx
  unsigned int v101; // eax
  unsigned int v102; // er8
  int v103; // er10
  int v104; // ecx
  unsigned int v105; // edx
  int v106; // eax
  hkVector4f v107; // xmm6
  __m128 v108; // xmm5
  __m128 v109; // xmm3
  __m128 v110; // xmm1
  __m128 v111; // xmm2
  __m128 v112; // xmm1
  __m128 v113; // xmm2
  __m128 v114; // xmm1
  __m128 v115; // xmm2
  __m128 v116; // xmm1
  hkVector4f v117; // xmm15
  __m128i v118; // xmm5
  __m128 v119; // xmm3
  __m128 v120; // xmm1
  __m128 v121; // xmm4
  int v122; // eax
  bool v123; // sf
  unsigned __int8 v124; // of
  unsigned int v125; // ebx
  hkLifoAllocator *v126; // rax
  int v127; // er8
  bool v128; // zf
  void *v129; // rbx
  int v130; // eax
  unsigned int *v131; // rdi
  signed int v132; // ebx
  hkLifoAllocator *v133; // rax
  int v134; // er8
  _QWORD *v135; // rax
  _QWORD *v136; // rcx
  _QWORD *v137; // r8
  unsigned __int64 v138; // rax
  signed __int64 v139; // rcx
  unsigned int *array; // [rsp+60h] [rbp-90h]
  int v142; // [rsp+68h] [rbp-88h]
  int v143; // [rsp+6Ch] [rbp-84h]
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > v144; // [rsp+70h] [rbp-80h]
  int v145; // [rsp+88h] [rbp-68h]
  void *p; // [rsp+90h] [rbp-60h]
  int v147; // [rsp+98h] [rbp-58h]
  unsigned int v148; // [rsp+9Ch] [rbp-54h]
  int v149; // [rsp+A0h] [rbp-50h]
  hkaiNavMesh::Face *v150; // [rsp+A8h] [rbp-48h]
  hkVector4f vertex1; // [rsp+B0h] [rbp-40h]
  hkResult result; // [rsp+C0h] [rbp-30h]
  hkVector4f vertex0; // [rsp+D0h] [rbp-20h]
  hkSimdFloat32 fractionInOut; // [rsp+E0h] [rbp-10h]
  int *v155; // [rsp+F0h] [rbp+0h]
  int *dataPtrOut; // [rsp+F8h] [rbp+8h]
  hkcdRay v157; // [rsp+100h] [rbp+10h]
  hkcdRay ray; // [rsp+130h] [rbp+40h]
  __m128 v159; // [rsp+160h] [rbp+70h]
  __m128 v160; // [rsp+170h] [rbp+80h]
  int v161; // [rsp+180h] [rbp+90h]
  __int64 v162; // [rsp+188h] [rbp+98h]
  __int64 v163; // [rsp+190h] [rbp+A0h]
  __int128 v164; // [rsp+1A0h] [rbp+B0h]
  unsigned int v165; // [rsp+1B0h] [rbp+C0h]
  __int64 v166; // [rsp+1B8h] [rbp+C8h]
  int *v167; // [rsp+1C0h] [rbp+D0h]
  __int128 v168; // [rsp+1D0h] [rbp+E0h]
  unsigned int v169; // [rsp+1E0h] [rbp+F0h]
  hkaiNavMesh::Face *v170; // [rsp+1E8h] [rbp+F8h]
  int *v171; // [rsp+1F0h] [rbp+100h]
  __m128 *vars0; // [rsp+2F0h] [rbp+200h]
  __m128 *retaddr; // [rsp+2F8h] [rbp+208h]
  hkVector4f *v174; // [rsp+300h] [rbp+210h]
  hkSimdFloat32 *radiusa; // [rsp+308h] [rbp+218h]
  hkArray<int,hkContainerHeapAllocator> **v176; // [rsp+310h] [rbp+220h]
  hkSimdFloat32 *v177; // [rsp+318h] [rbp+228h]

  v177 = radius;
  v176 = (hkArray<int,hkContainerHeapAllocator> **)currentUp;
  radiusa = (hkSimdFloat32 *)end;
  v174 = start;
  v8 = start;
  v9 = radius;
  v10 = end;
  v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)v11[1];
  v13 = v11;
  if ( (unsigned __int64)v12 < v11[3] )
  {
    *v12 = "TtcheckAgainstNearbyBoundaries";
    v14 = __rdtsc();
    v15 = (signed __int64)(v12 + 2);
    *(_DWORD *)(v15 - 8) = v14;
    v13[1] = v15;
  }
  v16.m_quad = v8->m_quad;
  v17 = v10->m_quad;
  v18 = 3;
  v145 = 0;
  v19 = (__m128i)_mm_sub_ps(v17, v16.m_quad);
  v20 = (__m128)_xmm;
  ray.m_origin = (hkVector4f)v16.m_quad;
  v21 = _mm_rcp_ps((__m128)v19);
  v22 = _mm_cmpeqps((__m128)v19, (__m128)0i64);
  v23 = _mm_shuffle_ps((__m128)v19, _mm_unpackhi_ps((__m128)v19, input->m_startPoint.m_quad), 196);
  ray.m_direction.m_quad = v23;
  v24 = _mm_mul_ps(v23, v23);
  ray.m_invDirection.m_quad = _mm_or_ps(
                                _mm_and_ps(
                                  _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v19, 0x1Fu), 0x1Fu), (__m128)_xmm),
                                  v22),
                                _mm_andnot_ps(
                                  v22,
                                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v21, (__m128)v19)), v21)));
  ray.m_invDirection.m_quad.m128_i32[3] = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, v23)) & 7 | 0x3F000000;
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 170))) <= 0.0 )
    goto LABEL_100;
  array = 0i64;
  v142 = 0;
  v143 = 2147483648;
  v144.m_elem.m_size = 64;
  v25 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v26 = (unsigned int *)v25->m_cur;
  v27 = (unsigned __int64)(v26 + 64);
  if ( v25->m_slabSize < 256 || (void *)v27 > v25->m_end )
    v26 = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v25, 256);
  else
    v25->m_cur = (void *)v27;
  array = v26;
  v144.m_elem.m_data = v26;
  v143 = -2147483584;
  v28 = hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::getSizeInBytesFor(64);
  v149 = v28;
  if ( v28 )
  {
    v29 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v30 = (char *)v29->m_cur;
    v31 = (v28 + 127) & 0xFFFFFF80;
    p = v30;
    v32 = &v30[v31];
    if ( v31 > v29->m_slabSize || v32 > v29->m_end )
    {
      v30 = (char *)hkLifoAllocator::allocateFromNewSlab(v29, v31);
      p = v30;
    }
    else
    {
      v29->m_cur = v32;
    }
  }
  else
  {
    v30 = 0i64;
    p = 0i64;
  }
  v147 = v28 | 0x80000000;
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>(
    &v144,
    v30,
    v28);
  v33 = v142;
  if ( v142 == (v143 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 4);
    v33 = v142;
  }
  array[v33] = (unsigned int)accessor;
  ++v142;
  v34 = v144.m_elem.m_data;
  while ( 1 )
  {
    v35 = array[v142-- - 1];
    v36 = v144.m_elem.m_size - 1;
    if ( v144.m_elem.m_size - 1 <= 0 || (v37 = v36 & -1640531535 * (v35 >> 4), v38 = v34[v37], v38 == -1) )
    {
LABEL_21:
      v39 = v144.m_elem.m_size;
    }
    else
    {
      while ( v38 != v35 )
      {
        v37 = v36 & (v37 + 1);
        v38 = v34[v37];
        if ( v38 == -1 )
          goto LABEL_21;
      }
      v39 = v37;
    }
    if ( v39 <= v36 )
      goto LABEL_76;
    v40 = v144.m_numElems;
    if ( 2 * v144.m_numElems > v36 )
      break;
    if ( 2 * v144.m_numElems > v36 )
    {
      hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
        &v144,
        &result,
        2 * v36 + 2);
      v40 = v144.m_numElems;
      v34 = v144.m_elem.m_data;
    }
    v41 = 1;
    v42 = (v144.m_elem.m_size - 1) & -1640531535 * (v35 >> 4);
    v43 = v34[v42];
    if ( v43 != -1 )
    {
      while ( v43 != v35 )
      {
        v42 = (v144.m_elem.m_size - 1) & (v42 + 1);
        v43 = v34[v42];
        if ( v43 == -1 )
          goto LABEL_32;
      }
      v41 = 0;
    }
LABEL_32:
    v144.m_numElems = v41 + v40;
    v34[v42] = v35;
    v148 = v35 >> 22;
    hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v176, v35 >> 22);
    v44 = hkaiNavMeshInstance_getWithData_hkaiNavMesh::Face_int__0(
            (hkaiNavMesh::Face *)(*v176)[1].m_data,
            (*v176)[1].m_size,
            (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&(*v176)[15],
            (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&(*v176)[17],
            (*v176)[4].m_data,
            *v176 + 22,
            *v176 + 24,
            *v176 + 14,
            v35 & 0x3FFFFF,
            (*v176)[4].m_size,
            (const int **)&dataPtrOut);
    v169 = v35;
    v171 = dataPtrOut;
    v162 = 0i64;
    v166 = 0i64;
    v170 = v44;
    v161 = -1;
    v165 = -1;
    v150 = v44;
    v45 = 0;
    if ( v44->m_numEdges > 0 )
    {
      while ( 1 )
      {
        index = v45 + v44->m_startEdgeIndex;
        v47 = hkaiNavMeshInstance_getWithData_hkaiNavMesh::Edge_int__1(
                (hkaiNavMesh::Edge *)(*v176)[2].m_data,
                (*v176)[2].m_size,
                (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&(*v176)[16],
                (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&(*v176)[18],
                (*v176)[5].m_data,
                *v176 + 23,
                *v176 + 25,
                *v176 + 13,
                index,
                (*v176)[5].m_size,
                (const int **)&v155);
        v48 = (unsigned __int64)*v176;
        v49 = (*v176)[3].m_size;
        v50 = (__int64)v47;
        v51 = v47->m_a;
        if ( (signed int)v51 >= v49 )
          v52 = (__m128 *)(*(_QWORD *)(v48 + 304) + 16i64 * ((signed int)v51 - v49));
        else
          v52 = (__m128 *)(*(_QWORD *)(v48 + 48) + 16 * v51);
        v53 = *(__m128 *)(v48 + 128);
        v54 = *(__m128 *)(v48 + 112);
        v55 = *(signed int *)(v50 + 4);
        v56 = *(__m128 *)(v48 + 144);
        v57 = *(__m128 *)(v48 + 160);
        v58 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*v52, *v52, 0), v54),
                    _mm_mul_ps(_mm_shuffle_ps(*v52, *v52, 85), v53)),
                  _mm_mul_ps(_mm_shuffle_ps(*v52, *v52, 170), v56)),
                v57);
        if ( (signed int)v55 >= v49 )
          v59 = (__m128 *)(*(_QWORD *)(v48 + 304) + 16i64 * ((signed int)v55 - v49));
        else
          v59 = (__m128 *)(*(_QWORD *)(v48 + 48) + 16 * v55);
        v60 = *v59;
        v61 = *v59;
        vertex0.m_quad = v58;
        v62 = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v60, v60, 0), v54), _mm_mul_ps(_mm_shuffle_ps(v61, v60, 85), v53)),
                _mm_mul_ps(_mm_shuffle_ps(v60, v60, 170), v56));
        v63 = _mm_shuffle_ps(v23, v23, 255);
        v64 = _mm_mul_ps(_mm_sub_ps(*retaddr, *vars0), v63);
        v160 = v63;
        v159 = _mm_add_ps(v62, v57);
        vertex1.m_quad = v159;
        v65 = _mm_sub_ps(v159, v58);
        v66 = _mm_sub_ps(v58, *vars0);
        v67 = _mm_mul_ps(v65, v64);
        v68 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v67, v67, 85), _mm_shuffle_ps(v67, v67, 0)),
                _mm_shuffle_ps(v67, v67, 170));
        v69 = _mm_mul_ps(v66, v64);
        v70 = _mm_mul_ps(v66, v65);
        v71 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v69, v69, 85), _mm_shuffle_ps(v69, v69, 0)),
                _mm_shuffle_ps(v69, v69, 170));
        v72 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v70, v70, 85), _mm_shuffle_ps(v70, v70, 0)),
                _mm_shuffle_ps(v70, v70, 170));
        v73 = _mm_mul_ps(v64, v64);
        v74 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
                _mm_shuffle_ps(v73, v73, 170));
        v75 = _mm_mul_ps(v65, v65);
        v76 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v75, v75, 85), _mm_shuffle_ps(v75, v75, 0)),
                _mm_shuffle_ps(v75, v75, 170));
        v77 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v76, v74), _mm_mul_ps(v68, v68)), *(__m128 *)&epsilon);
        v78 = _mm_rcp_ps(v77);
        v79 = _mm_mul_ps(_mm_sub_ps(v20, _mm_mul_ps(v78, v77)), v78);
        v80 = _mm_rcp_ps(v76);
        v81 = _mm_mul_ps(_mm_sub_ps(v20, _mm_mul_ps(v80, v76)), v80);
        v82 = _mm_rcp_ps(v74);
        v83 = _mm_mul_ps(v82, v74);
        v84 = _mm_cmpleps(v77, *(__m128 *)&epsilon);
        v85 = _mm_mul_ps(_mm_sub_ps(v20, v83), v82);
        v86 = _mm_sub_ps(_mm_mul_ps(v76, v71), _mm_mul_ps(v72, v68));
        v87 = _mm_cmpltps(v86, v77);
        v88 = _mm_sub_ps(
                _mm_mul_ps(
                  _mm_or_ps(
                    _mm_andnot_ps(
                      v84,
                      _mm_mul_ps(
                        _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v87, v86), _mm_andnot_ps(v87, v77))),
                        v79)),
                    _mm_and_ps(v84, query.m_quad)),
                  _mm_mul_ps(v68, v81)),
                _mm_mul_ps(v72, v81));
        v89 = _mm_cmpltps(v88, query.m_quad);
        v90 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v89, v88), _mm_andnot_ps(v89, query.m_quad)));
        v91 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v68, v85), v90), _mm_mul_ps(v71, v85));
        v92 = _mm_cmpltps(v91, query.m_quad);
        v93 = (__int128)*vars0;
        v94 = _mm_sub_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v92, v91), _mm_andnot_ps(v92, query.m_quad))),
                    v64),
                  *vars0),
                _mm_add_ps(_mm_mul_ps(v90, v65), v58));
        v95 = _mm_mul_ps(v94, v94);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v95, v95, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v95, v95, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v95, v95, 170))) >= (float)(v9->m_real.m128_f32[0]
                                                                           * v9->m_real.m128_f32[0]) )
          goto LABEL_71;
        v96 = *(_DWORD *)(v50 + 8) == -1 || *(_BYTE *)(v50 + 16) & 0x20 ? 0 : 1;
        v97 = v96 != 0;
        if ( v96 )
        {
          v98 = v177[4].m_real.m128_u64[0];
          if ( !v98 )
            break;
          v99 = (__int128)*retaddr;
          v157.m_origin.m_quad.m128_u64[0] = v48;
          v161 = -1;
          v162 = 0i64;
          v164 = v93;
          v168 = v99;
          v163 = 0i64;
          v166 = v50;
          v165 = index | (v148 << 22);
          v157.m_direction.m_quad.m128_i8[8] = 34;
          v167 = v155;
          v157.m_origin.m_quad.m128_u64[1] = (unsigned __int64)&v177[2].m_real.m128_u64[1];
          v157.m_direction.m_quad.m128_u64[0] = (unsigned __int64)&v161;
          if ( (*(unsigned __int8 (__fastcall **)(unsigned __int64, hkcdRay *))(*(_QWORD *)v98 + 40i64))(v98, &v157) )
            break;
        }
        fractionInOut.m_real = v160;
        if ( !hkcdRayCastCapsuleWrapper(&ray, &vertex0, &vertex1, radiusa, &fractionInOut) )
        {
          v23 = ray.m_direction.m_quad;
LABEL_70:
          v9 = radiusa;
LABEL_71:
          v34 = v144.m_elem.m_data;
          goto LABEL_72;
        }
        v107.m_quad = *vars0;
        v108 = *retaddr;
        if ( v177[4].m_real.m128_i8[9] )
        {
          v109 = v174->m_quad;
          v110 = _mm_mul_ps(v174->m_quad, v107.m_quad);
          v111 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v110, v110, 85), _mm_shuffle_ps(v110, v110, 0)),
                   _mm_shuffle_ps(v110, v110, 170));
          v112 = _mm_mul_ps(v174->m_quad, v108);
          v107.m_quad = _mm_sub_ps(v107.m_quad, _mm_mul_ps(v111, v174->m_quad));
          v113 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v112, v112, 85), _mm_shuffle_ps(v112, v112, 0)),
                   _mm_shuffle_ps(v112, v112, 170));
          v114 = _mm_mul_ps(v174->m_quad, v58);
          v108 = _mm_sub_ps(v108, _mm_mul_ps(v113, v174->m_quad));
          v115 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v114, v114, 85), _mm_shuffle_ps(v114, v114, 0)),
                   _mm_shuffle_ps(v114, v114, 170));
          v116 = _mm_mul_ps(v174->m_quad, v159);
          vertex0.m_quad = _mm_sub_ps(v58, _mm_mul_ps(v115, v174->m_quad));
          vertex1.m_quad = _mm_sub_ps(
                             v159,
                             _mm_mul_ps(
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v116, v116, 85), _mm_shuffle_ps(v116, v116, 0)),
                                 _mm_shuffle_ps(v116, v116, 170)),
                               v109));
        }
        v117.m_quad = (__m128)ray.m_direction;
        v20 = (__m128)_xmm;
        v118 = (__m128i)_mm_sub_ps(v108, v107.m_quad);
        v119 = _mm_cmpeqps((__m128)v118, (__m128)0i64);
        v157.m_origin = (hkVector4f)v107.m_quad;
        v120 = _mm_rcp_ps((__m128)v118);
        v157.m_direction.m_quad = _mm_shuffle_ps(
                                    (__m128)v118,
                                    _mm_unpackhi_ps(
                                      (__m128)v118,
                                      _mm_shuffle_ps(ray.m_direction.m_quad, ray.m_direction.m_quad, 255)),
                                    196);
        v121 = _mm_mul_ps(v157.m_direction.m_quad, v157.m_direction.m_quad);
        v157.m_invDirection.m_quad = _mm_or_ps(
                                       _mm_and_ps(
                                         _mm_xor_ps(
                                           (__m128)_mm_slli_epi32(_mm_srli_epi32(v118, 0x1Fu), 0x1Fu),
                                           (__m128)_xmm),
                                         v119),
                                       _mm_andnot_ps(
                                         v119,
                                         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v118, v120)), v120)));
        v157.m_invDirection.m_quad.m128_i32[3] = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, v157.m_direction.m_quad)) & 7 | 0x3F000000;
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v121, v121, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v121, v121, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v121, v121, 170))) > 0.0 )
          hkcdRayCastCapsuleWrapper(&v157, &vertex0, &vertex1, radiusa, &fractionInOut);
        v34 = v144.m_elem.m_data;
        v145 = 1;
        v23 = _mm_shuffle_ps(v117.m_quad, _mm_unpackhi_ps(v117.m_quad, fractionInOut.m_real), 196);
        v18 = (v97 != 0) + 4;
        ray.m_direction.m_quad = v23;
        if ( !v177[4].m_real.m128_i8[12] )
          goto LABEL_80;
        v9 = radiusa;
LABEL_73:
        ++v45;
        v122 = v150->m_numEdges;
        v124 = __OFSUB__(v45, v122);
        v123 = v45 - v122 < 0;
        v44 = v150;
        if ( !(v123 ^ v124) )
          goto LABEL_76;
      }
      v100 = *(_DWORD *)(v50 + 12);
      if ( *(_BYTE *)(v50 + 16) & 0x40 )
        v101 = v100 & 0xFFC00000;
      else
        v101 = (*v176)[29].m_size << 22;
      v34 = v144.m_elem.m_data;
      v102 = v101 | v100 & 0x3FFFFF;
      if ( v100 == -1 )
        v102 = -1;
      v103 = v144.m_elem.m_size - 1;
      if ( v144.m_elem.m_size - 1 <= 0
        || (v104 = v103 & -1640531535 * (v102 >> 4), v105 = v144.m_elem.m_data[v104], v105 == -1) )
      {
LABEL_56:
        v106 = v144.m_elem.m_size;
      }
      else
      {
        while ( v105 != v102 )
        {
          v104 = v103 & (v104 + 1);
          v105 = v144.m_elem.m_data[v104];
          if ( v105 == -1 )
            goto LABEL_56;
        }
        v106 = v104;
      }
      if ( v106 > v103 )
      {
        if ( v142 == (v143 & 0x3FFFFFFF) )
          break;
        array[v142++] = v102;
        goto LABEL_70;
      }
      v9 = radiusa;
LABEL_72:
      v20 = (__m128)_xmm;
      goto LABEL_73;
    }
    v34 = v144.m_elem.m_data;
LABEL_76:
    if ( !v142 )
      goto $outputAndExit_0;
  }
  v18 = 2;
$outputAndExit_0:
  if ( v145 )
LABEL_80:
    input->m_startPoint.m_quad = _mm_shuffle_ps(v23, v23, 255);
  v144.m_elem.m_size = 0;
  if ( v144.m_elem.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v34,
      4 * v144.m_elem.m_capacityAndFlags);
  v144.m_elem.m_data = 0i64;
  v144.m_elem.m_capacityAndFlags = 2147483648;
  v125 = (v149 + 127) & 0xFFFFFF80;
  v126 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v127 = (v125 + 15) & 0xFFFFFFF0;
  v124 = __OFSUB__(v125, v126->m_slabSize);
  v128 = v125 == v126->m_slabSize;
  v123 = (signed int)(v125 - v126->m_slabSize) < 0;
  v129 = p;
  if ( (unsigned __int8)(v123 ^ v124) | v128 && (char *)p + v127 == v126->m_cur && v126->m_firstNonLifoEnd != p )
    v126->m_cur = p;
  else
    hkLifoAllocator::slowBlockFree(v126, p, v127);
  if ( v147 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v129,
      v147 & 0x3FFFFFFF);
  v130 = v142;
  v131 = v144.m_elem.m_data;
  if ( v144.m_elem.m_data == array )
    v130 = 0;
  v142 = v130;
  v132 = (4 * v144.m_elem.m_size + 127) & 0xFFFFFF80;
  v133 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v134 = (v132 + 15) & 0xFFFFFFF0;
  if ( v132 > v133->m_slabSize || (char *)v131 + v134 != v133->m_cur || v133->m_firstNonLifoEnd == v131 )
    hkLifoAllocator::slowBlockFree(v133, v131, v134);
  else
    v133->m_cur = v131;
  v142 = 0;
  if ( v143 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v143);
  array = 0i64;
  v143 = 2147483648;
LABEL_100:
  v135 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v136 = (_QWORD *)v135[1];
  v137 = v135;
  if ( (unsigned __int64)v136 < v135[3] )
  {
    *v136 = "Et";
    v138 = __rdtsc();
    v139 = (signed __int64)(v136 + 2);
    *(_DWORD *)(v139 - 8) = v138;
    v137[1] = v139;
  }
  return v18;
}
    v139 = (signed __int64)(v136 + 2);
    *(_DWORD *)(v139 - 8) = v138;
    v137[1] = v139;
  }
  return v18;
}

// File Line: 378
// RVA: 0xBD9DE0
__int64 __usercall hkaiLineOfSightUtil::_lineOfSightInternal@<rax>(hkVector4f *directionIn@<rcx>, hkVector4f *goalPoint@<rdx>, unsigned int goalKey@<r8d>, hkaiStreamingCollection::InstanceInfo *streamingInfo@<r9>, __m128 *a5@<r12>, hkaiLineOfSightUtil::InputBase *input, hkaiLineOfSightUtil::LineOfSightOutput *output)
{
  hkaiLineOfSightUtil::InputBase *v7; // r14
  hkVector4f *v8; // rbx
  unsigned int v9; // edi
  float v10; // xmm1_4
  __m128 v12; // xmm8
  __m128 v13; // xmm9
  __m128 v14; // xmm1
  __m128 v15; // xmm10
  char v16; // cl
  __m128 v17; // xmm9
  __m128 v18; // xmm9
  __m128 v19; // xmm1
  __m128 v20; // xmm4
  __m128 v21; // xmm3
  __m128 v22; // xmm12
  __m128 v23; // xmm9
  __m128 v24; // xmm2
  __m128 v25; // xmm9
  __m128 v26; // xmm1
  __m128 v27; // xmm0
  __m128 v28; // xmm6
  __m128i v29; // xmm15
  __m128 v30; // xmm1
  __m128 v31; // xmm6
  hkLifoAllocator *v32; // rax
  char *v33; // rcx
  unsigned __int64 v34; // rdx
  __m128 v35; // xmm1
  __m128 v36; // xmm1
  __m128 v37; // xmm14
  __m128 v38; // xmm6
  int v39; // er15
  __m128 v40; // xmm7
  __m128 v41; // xmm11
  __m128i v42; // xmm8
  unsigned int v43; // esi
  int v44; // er13
  hkaiNavMesh::Face *v45; // rax
  int *v46; // rbx
  hkaiNavMeshInstance *v47; // rcx
  int v48; // edx
  unsigned int v49; // er13
  int index; // er15
  hkaiNavMesh::Edge *v51; // rax
  __int64 v52; // rdx
  hkaiNavMesh::Edge *v53; // r10
  int v54; // er8
  hkVector4f *v55; // rdx
  __int64 v56; // rax
  __m128 v57; // xmm4
  hkVector4f *v58; // rax
  __m128 v59; // xmm1
  __m128 v60; // xmm5
  __m128 v61; // xmm1
  __m128 v62; // xmm1
  __m128 v63; // xmm0
  __m128 v64; // xmm1
  __m128 v65; // xmm6
  __m128 v66; // xmm1
  __m128 v67; // xmm0
  __m128 v68; // xmm2
  __m128 v69; // xmm1
  __m128 v70; // xmm2
  __m128 v71; // xmm3
  __m128 v72; // xmm2
  __m128 v73; // xmm3
  __m128 v74; // xmm1
  __m128 v75; // xmm2
  int v76; // er8
  signed __int64 v77; // rdx
  bool v78; // zf
  signed int v79; // eax
  bool v80; // r9
  unsigned int v81; // er8
  unsigned int v82; // edx
  int v83; // eax
  unsigned int v84; // er8
  unsigned int v85; // edx
  int v86; // eax
  int v87; // er15
  __m128 v88; // xmm10
  __m128 v89; // xmm6
  hkSimdFloat32 *v90; // rdx
  __m128 v91; // xmm1
  __m128 v92; // xmm3
  __m128 v93; // xmm2
  __m128 v94; // xmm10
  __m128 v95; // xmm11
  __m128 v96; // xmm1
  __m128 v97; // xmm4
  float v98; // xmm1_4
  __m128 v99; // xmm6
  __m128 v100; // xmm1
  __m128 v101; // xmm1
  __m128 v102; // xmm3
  __m128 v103; // xmm2
  __m128 v104; // xmm5
  __m128 v105; // xmm4
  __m128 v106; // xmm1
  __m128 v107; // xmm1
  __m128 v108; // xmm2
  __m128 v109; // xmm1
  __m128 v110; // xmm2
  __m128 v111; // xmm1
  __m128 v112; // xmm1
  __m128 v113; // xmm4
  __m128 v114; // xmm1
  __m128 v115; // xmm4
  __m128 v116; // xmm3
  __m128 v117; // xmm5
  __m128 v118; // xmm2
  __m128 v119; // xmm1
  __m128 v120; // xmm0
  __m128 v121; // xmm2
  __m128 v122; // xmm4
  __m128 v123; // xmm3
  __m128 v124; // xmm1
  __m128 v125; // xmm3
  __m128 v126; // xmm2
  __m128 v127; // xmm0
  hkaiAstarEdgeFilter *v128; // r8
  signed int v129; // ebx
  signed int v130; // eax
  int v131; // ebx
  hkaiAstarCostModifier *v132; // r9
  hkaiLineOfSightUtil::LineOfSightResult v133; // ebx
  __m128 v134; // xmm8
  __m128 v135; // xmm2
  __m128 v136; // xmm9
  __m128 v137; // xmm6
  __m128 v138; // xmm6
  __m128 v139; // xmm7
  __m128 v140; // xmm1
  __m128 v141; // xmm5
  __m128 v142; // xmm2
  __m128 v143; // xmm4
  __m128 v144; // xmm3
  __m128 v145; // xmm6
  __m128 v146; // xmm1
  __m128 v147; // xmm2
  __m128 v148; // xmm3
  __m128 v149; // xmm9
  __m128 v150; // xmm0
  __m128 v151; // xmm9
  __m128 v152; // xmm9
  __m128 v153; // xmm9
  __m128 v154; // xmm9
  __m128 v155; // xmm1
  __m128 v156; // xmm3
  __m128 v157; // xmm2
  __m128 v158; // xmm9
  __m128 v159; // xmm2
  int v160; // eax
  char *v161; // rdi
  signed int v162; // ebx
  hkLifoAllocator *v163; // rax
  int v164; // er8
  signed int v165; // [rsp+58h] [rbp-80h]
  int section; // [rsp+60h] [rbp-78h]
  bool v167; // [rsp+64h] [rbp-74h]
  hkaiGeneralAccessor accessor; // [rsp+68h] [rbp-70h]
  char *v169; // [rsp+80h] [rbp-58h]
  int v170; // [rsp+88h] [rbp-50h]
  int v171; // [rsp+8Ch] [rbp-4Ch]
  void *p; // [rsp+90h] [rbp-48h]
  int v173; // [rsp+98h] [rbp-40h]
  hkaiNavMesh::Face *v174; // [rsp+A0h] [rbp-38h]
  int faceIndex[4]; // [rsp+A8h] [rbp-30h]
  int v176; // [rsp+B8h] [rbp-20h]
  int v177; // [rsp+BCh] [rbp-1Ch]
  hkaiStreamingCollection::InstanceInfo *v178; // [rsp+C0h] [rbp-18h]
  int v179; // [rsp+C8h] [rbp-10h]
  int v180; // [rsp+D0h] [rbp-8h]
  int v181; // [rsp+D4h] [rbp-4h]
  __m128 *v182; // [rsp+D8h] [rbp+0h]
  __m128 *v183; // [rsp+E0h] [rbp+8h]
  hkVector4f end; // [rsp+E8h] [rbp+10h]
  hkQuaternionf v185; // [rsp+F8h] [rbp+20h]
  __m128 v186; // [rsp+108h] [rbp+30h]
  hkVector4f start; // [rsp+118h] [rbp+40h]
  hkSimdFloat32 radius; // [rsp+128h] [rbp+50h]
  int *dataPtrOut; // [rsp+138h] [rbp+60h]
  int *v190; // [rsp+140h] [rbp+68h]
  hkVector4f edgeB; // [rsp+148h] [rbp+70h]
  __m128 v192; // [rsp+158h] [rbp+80h]
  hkVector4f edgeA; // [rsp+168h] [rbp+90h]
  int v194; // [rsp+178h] [rbp+A0h]
  int *v195; // [rsp+180h] [rbp+A8h]
  int *v196; // [rsp+188h] [rbp+B0h]
  __m128 v197; // [rsp+198h] [rbp+C0h]
  int v198; // [rsp+1A8h] [rbp+D0h]
  int *v199; // [rsp+1B0h] [rbp+D8h]
  int *v200; // [rsp+1B8h] [rbp+E0h]
  __m128 v201; // [rsp+1C8h] [rbp+F0h]
  unsigned int v202; // [rsp+1D8h] [rbp+100h]
  hkaiNavMesh::Face *v203; // [rsp+1E0h] [rbp+108h]
  int *v204; // [rsp+1E8h] [rbp+110h]
  hkSimdFloat32 hitFractionInOut; // [rsp+1F8h] [rbp+120h]
  hkSimdFloat32 v206; // [rsp+208h] [rbp+130h]
  hkVector4f from; // [rsp+218h] [rbp+140h]
  hkSimdFloat32 v208; // [rsp+228h] [rbp+150h]
  __m128 v209; // [rsp+238h] [rbp+160h]
  hkaiNavMeshInstance *v210; // [rsp+248h] [rbp+170h]
  hkaiAgentTraversalInfo *v211; // [rsp+250h] [rbp+178h]
  int *v212; // [rsp+258h] [rbp+180h]
  char v213; // [rsp+260h] [rbp+188h]
  __int128 v214; // [rsp+268h] [rbp+190h]
  __int128 v215; // [rsp+278h] [rbp+1A0h]
  __m128 v216; // [rsp+288h] [rbp+1B0h]
  __m128 v217; // [rsp+298h] [rbp+1C0h]
  __m128i v218; // [rsp+2A8h] [rbp+1D0h]
  __m128 v219; // [rsp+2B8h] [rbp+1E0h]
  char v220; // [rsp+2C8h] [rbp+1F0h]
  __m128 *v221; // [rsp+3C0h] [rbp+2E8h]
  int v222; // [rsp+3C8h] [rbp+2F0h]
  hkaiLineOfSightUtil::InputBase *retaddr; // [rsp+3D8h] [rbp+300h]

  v7 = retaddr;
  v8 = directionIn;
  v9 = retaddr->m_startFaceKey;
  if ( v9 == -1 || !streamingInfo )
    return 0i64;
  v10 = retaddr->m_searchRadius;
  if ( v10 > 0.0 && (float)(retaddr->m_agentInfo.m_diameter * 0.5) > v10 )
    return 0i64;
  v12 = retaddr->m_up.m_quad;
  LODWORD(accessor.m_accessor) = -1;
  accessor.m_currentSection = -1;
  v13 = directionIn->m_quad;
  accessor.m_sectionInfo = streamingInfo;
  accessor.m_accessor = 0i64;
  v14 = v12;
  *(__m128 *)faceIndex = v12;
  if ( retaddr->m_isWallClimbing.m_bool )
  {
    hkaiGeneralAccessor::setSection(&accessor, v9 >> 22);
    hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)&v209,
      (hkSimdFloat32 *)accessor.m_accessor,
      (hkaiNavMeshInstance *)(v9 & 0x3FFFFF),
      (__int64)faceIndex);
    v14 = *(__m128 *)faceIndex;
  }
  v15 = (__m128)_xmm;
  v16 = retaddr->m_exactInternalVertexHandling.m_bool;
  v167 = retaddr->m_searchRadius > 0.0;
  v179 = 4;
  v178 = (hkaiStreamingCollection::InstanceInfo *)-1i64;
  v198 = -1;
  v199 = 0i64;
  v202 = -1;
  v203 = 0i64;
  v194 = -1;
  v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v14), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v13));
  v18 = _mm_shuffle_ps(v17, v17, 201);
  v195 = 0i64;
  v196 = 0i64;
  v19 = _mm_mul_ps(v18, v18);
  v183 = &v192;
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_rsqrt_ps(v20);
  v197 = retaddr->m_startPoint.m_quad;
  v22 = v197;
  end.m_quad = v197;
  v23 = _mm_mul_ps(
          v18,
          _mm_andnot_ps(
            _mm_cmpleps(v20, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
              _mm_mul_ps(v21, *(__m128 *)_xmm))));
  v24 = _mm_mul_ps(v23, v197);
  v25 = _mm_shuffle_ps(
          v23,
          _mm_unpackhi_ps(
            v23,
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                _mm_shuffle_ps(v24, v24, 170)))),
          196);
  v26 = _mm_shuffle_ps(
          (__m128)COERCE_UNSIGNED_INT(retaddr->m_agentInfo.m_diameter * 0.5),
          (__m128)COERCE_UNSIGNED_INT(retaddr->m_agentInfo.m_diameter * 0.5),
          0);
  v209 = _mm_shuffle_ps((__m128)LODWORD(retaddr->m_maximumPathLength), (__m128)LODWORD(retaddr->m_maximumPathLength), 0);
  v27 = (__m128)LODWORD(retaddr->m_searchRadius);
  radius.m_real = v26;
  v219 = _mm_sub_ps(_mm_shuffle_ps(v27, v27, 0), v26);
  v216 = _mm_mul_ps(v219, v219);
  if ( v16 )
    v192 = aabbOut.m_quad;
  else
    v192 = _mm_sub_ps((__m128)0i64, v26);
  v182 = &v186;
  if ( v16 )
    v186 = aabbOut.m_quad;
  else
    _mm_store_si128((__m128i *)&v186, (__m128i)v26);
  v28 = v8->m_quad;
  v29 = 0i64;
  v169 = 0i64;
  v170 = 0;
  v171 = 2147483648;
  v173 = 8;
  v30 = _mm_mul_ps(v28, v12);
  v31 = _mm_sub_ps(
          v28,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
              _mm_shuffle_ps(v30, v30, 170)),
            v12));
  v217 = v31;
  v32 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v33 = (char *)v32->m_cur;
  v34 = (unsigned __int64)(v33 + 128);
  if ( v32->m_slabSize < 128 || (void *)v34 > v32->m_end )
    v33 = (char *)hkLifoAllocator::allocateFromNewSlab(v32, 128);
  else
    v32->m_cur = (void *)v34;
  v35 = retaddr->m_startPoint.m_quad;
  LOBYTE(retaddr) = retaddr->m_mode.m_storage == 0;
  v169 = v33;
  p = v33;
  v36 = _mm_mul_ps(v35, v31);
  v171 = -2147483640;
  v170 = 0;
  v37 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)), _mm_shuffle_ps(v36, v36, 170));
  if ( !a5[3].m128_i8[0] || a5[2].m128_i32[2] < (a5[2].m128_i32[3] & 0x3FFFFFFF) )
  {
    if ( a5[2].m128_i32[2] == (a5[2].m128_i32[3] & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &a5[2], 16);
    *(hkVector4f *)(a5[2].m128_u64[0] + 16i64 * a5[2].m128_i32[2]++) = v7->m_startPoint;
  }
  v38 = *(__m128 *)_xmm;
  while ( 2 )
  {
    v39 = v9 >> 22;
    section = v9 >> 22;
    hkaiGeneralAccessor::setSection(&accessor, v9 >> 22);
    v40 = query.m_quad;
    v41 = v22;
    start.m_quad = v22;
    v42 = 0i64;
    v43 = 3;
    v44 = -1;
    v45 = hkaiNavMeshInstance_getWithData_hkaiNavMesh::Face_int__0(
            accessor.m_accessor->m_originalFaces,
            accessor.m_accessor->m_numOriginalFaces,
            &accessor.m_accessor->m_instancedFaces,
            &accessor.m_accessor->m_ownedFaces,
            accessor.m_accessor->m_originalFaceData,
            &accessor.m_accessor->m_instancedFaceData,
            &accessor.m_accessor->m_ownedFaceData,
            &accessor.m_accessor->m_faceMap,
            v9 & 0x3FFFFF,
            accessor.m_accessor->m_faceDataStriding,
            (const int **)&dataPtrOut);
    v174 = v45;
    if ( v9 == v222 )
    {
      v22 = *v221;
      v43 = 9;
      end.m_quad = *v221;
    }
    v165 = 4;
    accessor.m_sectionInfo = (hkaiStreamingCollection::InstanceInfo *)-1i64;
    v46 = 0i64;
    if ( v43 == 9 )
    {
      v47 = accessor.m_accessor;
      edgeA.m_quad = *v221;
      edgeB.m_quad = edgeA.m_quad;
      goto LABEL_89;
    }
    if ( v45->m_numEdges <= 0 )
    {
LABEL_70:
      v40 = 0i64;
      v43 = 1;
LABEL_71:
      v87 = v9 >> 22;
      goto $outputAndExit;
    }
    v47 = accessor.m_accessor;
    v48 = (int)accessor.m_accessor;
    v49 = v9 & 0xFFC00000;
    while ( 1 )
    {
      index = (_DWORD)v46 + v45->m_startEdgeIndex;
      if ( (index | v49) == v48 )
        goto LABEL_48;
      v51 = hkaiNavMeshInstance_getWithData_hkaiNavMesh::Edge_int__1(
              v47->m_originalEdges,
              v47->m_numOriginalEdges,
              &v47->m_instancedEdges,
              &v47->m_ownedEdges,
              v47->m_originalEdgeData,
              &v47->m_instancedEdgeData,
              &v47->m_ownedEdgeData,
              &v47->m_edgeMap,
              index,
              v47->m_edgeDataStriding,
              (const int **)&v190);
      v47 = accessor.m_accessor;
      v52 = v51->m_a;
      v53 = v51;
      v54 = accessor.m_accessor->m_numOriginalVertices;
      v55 = (signed int)v52 >= v54 ? &accessor.m_accessor->m_ownedVertices.m_data[(signed int)v52 - v54] : &accessor.m_accessor->m_originalVertices[v52];
      v56 = v51->m_b;
      v57 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(v55->m_quad, v55->m_quad, 85),
                    accessor.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                  _mm_mul_ps(
                    _mm_shuffle_ps(v55->m_quad, v55->m_quad, 0),
                    accessor.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                _mm_mul_ps(
                  _mm_shuffle_ps(v55->m_quad, v55->m_quad, 170),
                  accessor.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
              accessor.m_accessor->m_referenceFrame.m_transform.m_translation.m_quad);
      v58 = (signed int)v56 >= v54 ? &accessor.m_accessor->m_ownedVertices.m_data[(signed int)v56 - v54] : &accessor.m_accessor->m_originalVertices[v56];
      v59 = v58->m_quad;
      edgeA.m_quad = v57;
      v60 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(v59, v59, 85),
                    accessor.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                  _mm_mul_ps(
                    _mm_shuffle_ps(v59, v59, 0),
                    accessor.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                _mm_mul_ps(
                  _mm_shuffle_ps(v59, v59, 170),
                  accessor.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
              accessor.m_accessor->m_referenceFrame.m_transform.m_translation.m_quad);
      v61 = _mm_mul_ps(v25, v57);
      edgeB.m_quad = v60;
      v62 = _mm_shuffle_ps(v61, _mm_unpackhi_ps(v61, v25), 196);
      v63 = _mm_add_ps(_mm_shuffle_ps(v62, v62, 78), v62);
      v64 = _mm_mul_ps(v25, v60);
      v65 = _mm_add_ps(_mm_shuffle_ps(v63, v63, 177), v63);
      v66 = _mm_shuffle_ps(v64, _mm_unpackhi_ps(v64, v25), 196);
      v67 = _mm_add_ps(_mm_shuffle_ps(v66, v66, 78), v66);
      v68 = _mm_add_ps(_mm_shuffle_ps(v67, v67, 177), v67);
      if ( _mm_movemask_ps(_mm_and_ps(_mm_cmpleps(*v182, v68), _mm_cmpleps(v65, *v183))) )
        break;
LABEL_47:
      v48 = (int)accessor.m_accessor;
LABEL_48:
      LODWORD(v46) = (_DWORD)v46 + 1;
      if ( (signed int)v46 >= v174->m_numEdges )
        goto LABEL_70;
      v45 = v174;
    }
    v69 = _mm_sub_ps(v65, v68);
    v70 = _mm_rcp_ps(v69);
    v71 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v70, v69)), v70), v65);
    v72 = _mm_cmpltps(v71, query.m_quad);
    v73 = _mm_add_ps(
            _mm_mul_ps(
              _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v72, query.m_quad), _mm_and_ps(v72, v71))),
              _mm_sub_ps(v60, v57)),
            v57);
    v74 = _mm_mul_ps(v73, v217);
    v75 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v74, v74, 85), _mm_shuffle_ps(v74, v74, 0)),
            _mm_shuffle_ps(v74, v74, 170));
    if ( v7->m_isWallClimbing.m_bool )
      goto LABEL_52;
    if ( v75.m128_f32[0] <= v37.m128_f32[0] )
    {
      v76 = 0;
      v77 = 0i64;
      if ( v170 <= 0i64 )
        goto LABEL_46;
      while ( *(_DWORD *)&v169[4 * v77] != v9 )
      {
        ++v77;
        ++v76;
        if ( v77 >= v170 )
          goto LABEL_46;
      }
      if ( v76 == -1 )
      {
LABEL_46:
        if ( (v171 & 0x3FFFFFFF) != v170 )
        {
          *(_DWORD *)&v169[4 * v170++] = v9;
          v47 = accessor.m_accessor;
          goto LABEL_52;
        }
      }
      goto LABEL_47;
    }
    v170 = 0;
LABEL_52:
    v78 = v53->m_oppositeEdge == -1;
    v22 = v73;
    end.m_quad = v73;
    v37 = _mm_max_ps(v37, v75);
    if ( v78 || (v79 = 1, v53->m_flags.m_storage & 0x20) )
      v79 = 0;
    v46 = v190;
    accessor.m_currentSection = v53->m_a;
    v80 = v79 != 0;
    *(&accessor.m_currentSection + 1) = v53->m_b;
    accessor.m_sectionInfo = *(hkaiStreamingCollection::InstanceInfo **)&v53->m_oppositeEdge;
    v165 = *(_DWORD *)&v53->m_flags.m_storage;
    v81 = v53->m_oppositeEdge;
    if ( v53->m_flags.m_storage & 0x40 )
      v82 = v81 & 0xFFC00000;
    else
      v82 = v47->m_runtimeId << 22;
    v83 = v82 | v81 & 0x3FFFFF;
    if ( v81 == -1 )
      v83 = -1;
    LODWORD(accessor.m_sectionInfo) = v83;
    v84 = v53->m_oppositeFace;
    if ( v53->m_flags.m_storage & 0x40 )
      v85 = v84 & 0xFFC00000;
    else
      v85 = v47->m_runtimeId << 22;
    v86 = v85 | v84 & 0x3FFFFF;
    if ( v84 == -1 )
      v86 = -1;
    HIDWORD(accessor.m_sectionInfo) = v86;
    if ( index == -1 )
      goto LABEL_70;
    v44 = index | v49;
    if ( v80 )
    {
      v38 = *(__m128 *)_xmm;
      v45 = v174;
      v39 = v9 >> 22;
      goto LABEL_89;
    }
    v43 = 4;
    if ( (_BYTE)retaddr )
      goto LABEL_71;
    v78 = v7->m_projectedRadiusCheck.m_bool == 0;
    _mm_store_si128((__m128i *)&hitFractionInOut, (__m128i)query.m_quad);
    hkaiLineOfSightUtil::_raycastAgainstBoundary(
      &start,
      &end,
      &radius,
      !v78,
      (hkVector4f *)faceIndex,
      &edgeA,
      &edgeB,
      &hitFractionInOut);
    v47 = accessor.m_accessor;
    v38 = *(__m128 *)_xmm;
    v45 = v174;
    v39 = v9 >> 22;
    if ( hitFractionInOut.m_real.m128_f32[0] < 1.0 )
      v40 = hitFractionInOut.m_real;
LABEL_89:
    v100 = _mm_sub_ps(v41, v22);
    v101 = _mm_mul_ps(v100, v100);
    v102 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v101, v101, 85), _mm_shuffle_ps(v101, v101, 0)),
             _mm_shuffle_ps(v101, v101, 170));
    v103 = _mm_rsqrt_ps(v102);
    v42 = (__m128i)_mm_andnot_ps(
                     _mm_cmpleps(v102, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps(v15, _mm_mul_ps(_mm_mul_ps(v102, v103), v103)), _mm_mul_ps(v38, v103)),
                       v102));
    if ( v167 )
    {
      v104 = v7->m_startPoint.m_quad;
      v105 = v22;
      v106 = v41;
      if ( v7->m_projectedRadiusCheck.m_bool )
      {
        v107 = _mm_mul_ps(*(__m128 *)faceIndex, v104);
        v108 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v107, v107, 85), _mm_shuffle_ps(v107, v107, 0)),
                 _mm_shuffle_ps(v107, v107, 170));
        v109 = _mm_mul_ps(*(__m128 *)faceIndex, v22);
        v104 = _mm_sub_ps(v104, _mm_mul_ps(v108, *(__m128 *)faceIndex));
        v110 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v109, v109, 85), _mm_shuffle_ps(v109, v109, 0)),
                 _mm_shuffle_ps(v109, v109, 170));
        v111 = _mm_mul_ps(*(__m128 *)faceIndex, v41);
        v105 = _mm_sub_ps(v22, _mm_mul_ps(v110, *(__m128 *)faceIndex));
        v106 = _mm_sub_ps(
                 v41,
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v111, v111, 85), _mm_shuffle_ps(v111, v111, 0)),
                     _mm_shuffle_ps(v111, v111, 170)),
                   *(__m128 *)faceIndex));
      }
      v112 = _mm_sub_ps(v106, v104);
      v113 = _mm_sub_ps(v105, v104);
      v114 = _mm_mul_ps(v112, v112);
      v115 = _mm_mul_ps(v113, v113);
      v116 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v114, v114, 85), _mm_shuffle_ps(v114, v114, 0)),
               _mm_shuffle_ps(v114, v114, 170));
      v117 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v115, v115, 85), _mm_shuffle_ps(v115, v115, 0)),
               _mm_shuffle_ps(v115, v115, 170));
      if ( v117.m128_f32[0] > v216.m128_f32[0] )
      {
        v118 = _mm_rsqrt_ps(v116);
        v119 = _mm_sub_ps(v15, _mm_mul_ps(_mm_mul_ps(v118, v116), v118));
        v120 = _mm_mul_ps(v38, v118);
        v121 = _mm_rsqrt_ps(v117);
        v122 = _mm_andnot_ps(_mm_cmpleps(v116, (__m128)0i64), _mm_mul_ps(_mm_mul_ps(v119, v120), v116));
        v123 = _mm_sub_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v117, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(_mm_sub_ps(v15, _mm_mul_ps(_mm_mul_ps(v121, v117), v121)), _mm_mul_ps(v121, v38)),
                     v117)),
                 v122);
        v124 = _mm_rcp_ps(v123);
        v125 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v124, v123)), v124), _mm_sub_ps(v219, v122));
        v126 = _mm_cmpltps(v125, (__m128)xmmword_141A712A0);
        v127 = _mm_max_ps(
                 aabbOut.m_quad,
                 _mm_or_ps(_mm_and_ps(v126, v125), _mm_andnot_ps(v126, (__m128)xmmword_141A712A0)));
        if ( v127.m128_f32[0] < v40.m128_f32[0] )
        {
          v40 = v127;
          v43 = 6;
          if ( (_BYTE)retaddr )
            goto LABEL_71;
        }
      }
    }
    v128 = v7->m_edgeFilter;
    if ( !v128 && !v7->m_costModifier )
      goto LABEL_119;
    if ( v43 == 9 )
    {
      v198 = -1;
      v199 = 0i64;
      v200 = 0i64;
LABEL_102:
      v203 = v45;
      v201 = v22;
      v204 = dataPtrOut;
      v129 = 0;
      if ( v43 == 9 )
        v129 = 64;
      v130 = 0;
      v202 = v9;
      if ( !section )
        v130 = 16;
      v131 = v130 | v129;
      if ( !v131 )
        LOBYTE(v131) = 32;
      if ( v128 )
      {
        v210 = v47;
        v211 = &v7->m_agentInfo;
        v212 = &v194;
        v213 = v131 | 2;
        if ( !((unsigned __int8 (__fastcall *)(hkaiAstarEdgeFilter *, hkaiNavMeshInstance **))v128->vfptr[2].__first_virtual_table_function__)(
                v128,
                &v210) )
        {
          if ( v43 == 3 )
            v43 = 5;
          if ( (_BYTE)retaddr )
          {
            v43 = 5;
            goto LABEL_71;
          }
          v78 = v7->m_projectedRadiusCheck.m_bool == 0;
          _mm_store_si128((__m128i *)&v206, (__m128i)v40);
          hkaiLineOfSightUtil::_raycastAgainstBoundary(
            &start,
            &end,
            &radius,
            !v78,
            (hkVector4f *)faceIndex,
            &edgeA,
            &edgeB,
            &v206);
          if ( v206.m_real.m128_f32[0] < v40.m128_f32[0] )
          {
            v40 = v206.m_real;
            v43 = 5;
          }
        }
        v47 = accessor.m_accessor;
      }
      v132 = v7->m_costModifier;
      if ( v132 )
      {
        v210 = v47;
        v211 = &v7->m_agentInfo;
        _mm_store_si128((__m128i *)&v214, v29);
        _mm_store_si128((__m128i *)&v215, v42);
        v213 = v131 | 2;
        v212 = &v194;
        ((void (__fastcall *)(hkaiAstarCostModifier *, __m128i *, hkaiNavMeshInstance **))v132->vfptr[2].__first_virtual_table_function__)(
          v132,
          &v218,
          &v210);
        v42 = v218;
      }
      goto LABEL_119;
    }
    if ( LODWORD(accessor.m_sectionInfo) != -1 && !(v165 & 0x20) )
    {
      v198 = v44;
      v200 = v46;
      v199 = &accessor.m_currentSection;
      goto LABEL_102;
    }
LABEL_119:
    if ( v7->m_exactInternalVertexHandling.m_bool )
    {
      v208.m_real = query.m_quad;
      v133 = hkaiLineOfSightUtil::_checkAgainstNearbyBoundaries(
               &start,
               &end,
               (hkVector4f *)faceIndex,
               &radius,
               &accessor,
               v7,
               v9,
               &v208);
      hkaiGeneralAccessor::setSection(&accessor, v39);
      if ( v133 != 3 && v208.m_real.m128_f32[0] < v40.m128_f32[0] )
      {
        v43 = v133;
        v40 = v208.m_real;
        if ( (_BYTE)retaddr )
          goto LABEL_71;
      }
    }
    v87 = v9 >> 22;
    if ( (float)((float)(v40.m128_f32[0] * *(float *)v42.m128i_i32) + *(float *)v29.m128i_i32) <= v209.m128_f32[0] )
    {
      v87 = section + 1;
      if ( section < v7->m_maxNumberOfIterations )
      {
        if ( hkaiLineOfSightUtil::LineOfSightOutput::canAddEdge((hkaiLineOfSightUtil::LineOfSightOutput *)a5)
          && v44 != -1 )
        {
          if ( LODWORD(a5->m128_u64[1]) == (HIDWORD(a5->m128_u64[1]) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, a5, 4);
          *(_DWORD *)(a5->m128_u64[0] + 4i64 * (signed int)LODWORD(a5->m128_u64[1])++) = v44;
        }
      }
      else
      {
        v43 = 8;
      }
    }
    else
    {
      v43 = 7;
    }
$outputAndExit:
    v29 = (__m128i)_mm_add_ps((__m128)v29, _mm_mul_ps(v40, (__m128)v42));
    if ( hkaiLineOfSightUtil::LineOfSightOutput::canAddDistance((hkaiLineOfSightUtil::LineOfSightOutput *)a5) )
    {
      if ( a5[1].m128_i32[2] == (a5[1].m128_i32[3] & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &a5[1], 4);
      *(_DWORD *)(a5[1].m128_u64[0] + 4i64 * a5[1].m128_i32[2]++) = v29.m128i_i32[0];
    }
    v88 = _mm_sub_ps(v22, v41);
    v89 = _mm_add_ps(_mm_mul_ps(v88, v40), v41);
    if ( hkaiLineOfSightUtil::LineOfSightOutput::canAddPoint((hkaiLineOfSightUtil::LineOfSightOutput *)a5) )
    {
      if ( a5[2].m128_i32[2] == (a5[2].m128_i32[3] & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &a5[2], 16);
      *(__m128 *)(a5[2].m128_u64[0] + 16i64 * a5[2].m128_i32[2]++) = v89;
    }
    if ( v43 == 3 )
    {
      v78 = v7->m_costModifier == 0i64;
      v9 = HIDWORD(accessor.m_sectionInfo);
      LODWORD(accessor.m_accessor) = accessor.m_sectionInfo;
      if ( !v78 || v7->m_edgeFilter )
      {
        v176 = accessor.m_currentSection;
        v197 = v201;
        v177 = *(&accessor.m_currentSection + 1);
        v178 = accessor.m_sectionInfo;
        v179 = v165;
        v194 = v198;
        v195 = &v176;
        v196 = v200;
      }
      v38 = *(__m128 *)_xmm;
      if ( v7->m_isWallClimbing.m_bool )
      {
        hkaiGeneralAccessor::setSection(&accessor, HIDWORD(accessor.m_sectionInfo) >> 22);
        v90 = (hkSimdFloat32 *)accessor.m_accessor;
        _mm_store_si128((__m128i *)&from, *(__m128i *)faceIndex);
        v91 = _mm_mul_ps(v88, v88);
        v92 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v91, v91, 85), _mm_shuffle_ps(v91, v91, 0)),
                _mm_shuffle_ps(v91, v91, 170));
        v93 = _mm_rsqrt_ps(v92);
        v94 = _mm_mul_ps(
                v88,
                _mm_andnot_ps(
                  _mm_cmpleps(v92, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v93, v92), v93)),
                    _mm_mul_ps(v93, *(__m128 *)_xmm))));
        hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)&v220,
          v90,
          (hkaiNavMeshInstance *)(v9 & 0x3FFFFF),
          (__int64)faceIndex);
        v95 = *(__m128 *)faceIndex;
        v181 = 1065353048;
        v96 = _mm_mul_ps(*(__m128 *)faceIndex, from.m_quad);
        v97 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v96, v96, 85), _mm_shuffle_ps(v96, v96, 0)),
                _mm_shuffle_ps(v96, v96, 170));
        LODWORD(v98) = (unsigned __int128)_mm_shuffle_ps((__m128)0x3F7FFF58u, (__m128)0x3F7FFF58u, 0);
        if ( v97.m128_f32[0] > v98 )
        {
          v99 = qi.m_vec.m_quad;
          goto LABEL_137;
        }
        if ( v97.m128_f32[0] >= (float)(0.0 - v98) )
        {
          v180 = -1082147209;
          v134 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v97), (__m128)xmmword_141A711B0);
          v135 = _mm_rsqrt_ps(v134);
          v136 = _mm_andnot_ps(
                   _mm_cmpleps(v134, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v135, v134), v135)),
                     _mm_mul_ps(v135, *(__m128 *)_xmm)));
          v137 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)faceIndex, *(__m128 *)faceIndex, 201), from.m_quad),
                   _mm_mul_ps(_mm_shuffle_ps(from.m_quad, from.m_quad, 201), *(__m128 *)faceIndex));
          v138 = _mm_shuffle_ps(v137, v137, 201);
          v139 = _mm_mul_ps(v136, (__m128)xmmword_141A711B0);
          if ( v97.m128_f32[0] < COERCE_FLOAT(_mm_shuffle_ps((__m128)0xBF7FBE77, (__m128)0xBF7FBE77, 0)) )
          {
            v140 = _mm_mul_ps(v138, v138);
            v141 = _mm_sub_ps(v134, v97);
            v142 = _mm_rsqrt_ps(v141);
            v143 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v140, v140, 85), _mm_shuffle_ps(v140, v140, 0)),
                     _mm_shuffle_ps(v140, v140, 170));
            v144 = _mm_rsqrt_ps(v143);
            v139 = _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_andnot_ps(
                         _mm_cmpleps(v141, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v142, v141), v142)),
                           _mm_mul_ps(v142, *(__m128 *)_xmm))),
                       v141),
                     _mm_andnot_ps(
                       _mm_cmpleps(v143, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v144, v143), v144)),
                         _mm_mul_ps(v144, *(__m128 *)_xmm))));
          }
          v145 = _mm_mul_ps(v138, v139);
          v99 = _mm_shuffle_ps(v145, _mm_unpackhi_ps(v145, _mm_mul_ps(v136, v134)), 196);
LABEL_137:
          v185.m_vec.m_quad = v99;
        }
        else
        {
          hkQuaternionf::setFlippedRotation(&v185, &from);
          v95 = *(__m128 *)faceIndex;
          v99 = v185.m_vec.m_quad;
        }
        v146 = _mm_mul_ps(v99, v94);
        v147 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v94, v94, 201), v99),
                 _mm_mul_ps(_mm_shuffle_ps(v99, v99, 201), v94));
        v148 = _mm_shuffle_ps(v99, v99, 255);
        v149 = _mm_mul_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v146, v146, 85), _mm_shuffle_ps(v146, v146, 0)),
                   _mm_shuffle_ps(v146, v146, 170)),
                 v99);
        v38 = *(__m128 *)_xmm;
        v150 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v148, v148), (__m128)xmmword_141A711B0), v94);
        v15 = (__m128)_xmm;
        v151 = _mm_add_ps(_mm_add_ps(v149, v150), _mm_mul_ps(_mm_shuffle_ps(v147, v147, 201), v148));
        v152 = _mm_add_ps(v151, v151);
        v153 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v152, v152, 201), v95),
                 _mm_mul_ps(_mm_shuffle_ps(v95, v95, 201), v152));
        v154 = _mm_shuffle_ps(v153, v153, 201);
        v155 = _mm_mul_ps(v154, v154);
        v156 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v155, v155, 85), _mm_shuffle_ps(v155, v155, 0)),
                 _mm_shuffle_ps(v155, v155, 170));
        v157 = _mm_rsqrt_ps(v156);
        v158 = _mm_mul_ps(
                 v154,
                 _mm_andnot_ps(
                   _mm_cmpleps(v156, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v157, v156), v157)),
                     _mm_mul_ps(v157, *(__m128 *)_xmm))));
        v159 = _mm_mul_ps(v158, v22);
        v25 = _mm_shuffle_ps(
                v158,
                _mm_unpackhi_ps(
                  v158,
                  _mm_sub_ps(
                    (__m128)0i64,
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v159, v159, 85), _mm_shuffle_ps(v159, v159, 0)),
                      _mm_shuffle_ps(v159, v159, 170)))),
                196);
      }
      else
      {
        v15 = (__m128)_xmm;
      }
      continue;
    }
    break;
  }
  if ( (_BYTE)retaddr && v43 != 9 && !v7->m_outputEdgesOnFailure.m_bool )
    LODWORD(a5->m128_u64[1]) = 0;
  v160 = v170;
  a5[3].m128_i32[2] = v9;
  v161 = (char *)p;
  a5[3].m128_i32[3] = v29.m128i_i32[0];
  a5[4] = v89;
  v78 = v161 == v169;
  a5[3].m128_i32[1] = v87;
  if ( v78 )
    v160 = 0;
  v170 = v160;
  v162 = (4 * v173 + 127) & 0xFFFFFF80;
  v163 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v164 = (v162 + 15) & 0xFFFFFFF0;
  if ( v162 > v163->m_slabSize || &v161[v164] != v163->m_cur || v163->m_firstNonLifoEnd == v161 )
    hkLifoAllocator::slowBlockFree(v163, v161, v164);
  else
    v163->m_cur = v161;
  v170 = 0;
  if ( v171 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v169,
      4 * v171);
  return v43;
}

