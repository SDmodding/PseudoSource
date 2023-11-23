// File Line: 24
// RVA: 0xBDC230
_BOOL8 __fastcall isRayDegenerate(hkcdRay *ray)
{
  __m128 v1; // xmm2

  v1 = _mm_mul_ps(ray->m_direction.m_quad, ray->m_direction.m_quad);
  return (float)((float)(_mm_shuffle_ps(v1, v1, 85).m128_f32[0] + _mm_shuffle_ps(v1, v1, 0).m128_f32[0])
               + _mm_shuffle_ps(v1, v1, 170).m128_f32[0]) <= 0.0;
}

// File Line: 42
// RVA: 0xBD9A00
void __fastcall hkaiLineOfSightUtil::InputBase::InputBase(
        hkaiLineOfSightUtil::InputBase *this,
        hkaiLineOfSightUtil::InputBase::QueryMode mode)
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
void __fastcall hkaiLineOfSightUtil::InputBase::InputBase(
        hkaiLineOfSightUtil::InputBase *this,
        hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 55
// RVA: 0xBD9A70
void __fastcall hkaiLineOfSightUtil::LineOfSightInput::LineOfSightInput(hkaiLineOfSightUtil::LineOfSightInput *this)
{
  hkaiLineOfSightUtil::InputBase::InputBase(this, MODE_LINE_OF_SIGHT);
  this->m_goalFaceKey = -1;
  this->m_goalPoint = (hkVector4f)xmmword_141A712A0;
}

// File Line: 60
// RVA: 0xBD9AB0
void __fastcall hkaiLineOfSightUtil::LineOfSightInput::LineOfSightInput(
        hkaiLineOfSightUtil::LineOfSightInput *this,
        hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 68
// RVA: 0xBD9AC0
void __fastcall hkaiLineOfSightUtil::DirectPathInput::DirectPathInput(hkaiLineOfSightUtil::DirectPathInput *this)
{
  hkaiLineOfSightUtil::InputBase::InputBase(this, MODE_DIRECT_PATH);
  this->m_direction = (hkVector4f)xmmword_141A712A0;
}

// File Line: 73
// RVA: 0xBD9AF0
void __fastcall hkaiLineOfSightUtil::DirectPathInput::DirectPathInput(
        hkaiLineOfSightUtil::DirectPathInput *this,
        hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 82
// RVA: 0xBD9B00
void __fastcall hkaiLineOfSightUtil::LineOfSightOutput::LineOfSightOutput(hkaiLineOfSightUtil::LineOfSightOutput *this)
{
  this->m_visitedEdgesOut.m_capacityAndFlags = 0x80000000;
  this->m_visitedEdgesOut.m_data = 0i64;
  this->m_visitedEdgesOut.m_size = 0;
  this->m_distancesOut.m_data = 0i64;
  this->m_distancesOut.m_size = 0;
  this->m_distancesOut.m_capacityAndFlags = 0x80000000;
  this->m_pointsOut.m_data = 0i64;
  this->m_pointsOut.m_size = 0;
  this->m_pointsOut.m_capacityAndFlags = 0x80000000;
  this->m_doNotExceedArrayCapacity.m_bool = 0;
  this->m_numIterationsOut = 0;
  this->m_accumulatedDistance = 0.0;
  this->m_finalPoint = (hkVector4f)xmmword_141A712A0;
}

// File Line: 89
// RVA: 0xBD9B50
void __fastcall hkaiLineOfSightUtil::LineOfSightOutput::LineOfSightOutput(
        hkaiLineOfSightUtil::LineOfSightOutput *this,
        hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 99
// RVA: 0xBDC270
__int64 __fastcall hkcdRayCastCapsuleWrapper(
        hkcdRay *ray,
        hkVector4f *vertex0,
        hkVector4f *vertex1,
        hkSimdFloat32 *radius,
        hkSimdFloat32 *fractionInOut)
{
  __m128 m_quad; // xmm13
  __m128 v6; // xmm6
  __m128 v7; // xmm4
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm0
  __m128 v13; // xmm1
  __m128 m_real; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm7
  __m128 v17; // xmm0
  __m128 v18; // xmm4
  __m128 v19; // xmm4
  __m128 v21; // xmm14
  __m128 v22; // xmm2
  hkVector4f v23; // xmm9
  __m128 v24; // xmm1
  __m128 v25; // xmm5
  __m128 v26; // xmm15
  __m128 v27; // xmm4
  __m128 v28; // xmm1
  __m128 v29; // xmm0
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __m128 v32; // xmm5
  __m128 v33; // xmm5
  int v34; // r11d
  hkVector4f v35; // xmm7
  __m128 v36; // xmm0
  __m128 v37; // xmm1
  __m128 v38; // xmm7
  __m128 v39; // xmm5
  __m128 v40; // xmm4
  __m128 v41; // xmm1
  __m128 v42; // xmm0
  __m128 v43; // xmm2
  __m128 v44; // xmm1
  __m128 v45; // xmm5
  __m128 v46; // xmm5
  float v47; // xmm8_4
  __m128 v48; // xmm3
  __m128 v49; // xmm2
  __m128 v50; // xmm7
  __m128 v51; // xmm1
  __m128 v52; // xmm2
  __m128 v53; // xmm1
  __m128 v54; // xmm5
  __m128 v55; // xmm0
  __m128 v56; // xmm1
  hkVector4f v57; // xmm5
  unsigned int v58; // edx
  __m128 v59; // xmm1
  __m128 v60; // xmm3
  __m128 v61; // xmm2
  __m128 v62; // xmm6
  __m128 v63; // xmm3
  __m128 v64; // xmm7
  __m128 v65; // xmm8
  __m128 v66; // xmm5
  __m128 v67; // xmm1
  __m128 v68; // xmm2
  __m128 v69; // xmm2
  __m128 v70; // xmm4
  __m128 v71; // xmm0
  __m128 v72; // xmm3
  __m128 v73; // xmm2
  __m128 v74; // xmm1
  __m128 v75; // xmm0
  __m128 v76; // xmm2
  __m128 v77; // xmm0
  __m128 v78; // xmm2
  __m128 v79; // xmm2
  __m128 v80; // xmm3
  __m128 v81; // xmm1
  __m128 v82; // xmm2
  __m128 v83; // xmm7
  __m128 v84; // xmm2
  __m128 v85; // xmm3
  __m128 v86; // xmm3
  __m128 v87; // xmm4
  __m128 v88; // xmm1
  __m128 v89; // xmm5
  __m128 v90; // xmm1
  __m128 v91; // xmm4
  __m128 v92; // xmm4
  __m128 v93; // xmm1
  __m128 v94; // xmm2
  __m128 v95; // xmm1
  __m128 v96; // xmm5
  __m128 v97; // xmm10
  __m128 v98; // xmm15
  __m128 v99; // xmm7
  __m128 v100; // xmm1
  __m128 v101; // xmm2
  __m128 v102; // xmm2
  __m128 v103; // xmm5
  __m128 v104; // xmm4
  __m128 v105; // xmm4
  __m128 v106; // xmm9
  __m128 v107; // xmm4
  __m128 v108; // xmm2
  __m128i v109; // xmm7
  __m128 v110; // xmm6
  __m128 v111; // xmm13
  __m128 v112; // xmm2
  __m128 v113; // xmm3
  __m128 v114; // xmm3
  __m128 v115; // xmm5
  __m128 v116; // xmm1
  int v117; // ecx
  int v118; // eax
  __m128 v119; // xmm2
  __m128 v120; // xmm1
  __m128 v121; // xmm3
  __m128 v122; // xmm2
  __m128 v123; // xmm2
  hkVector4f v124; // xmm4
  __m128 v125; // xmm13
  __m128 v126; // xmm8
  __m128 v127; // xmm13
  __m128 v128; // xmm2
  __m128i v129; // xmm5
  __m128 v130; // xmm1
  __m128 v131; // xmm6
  __m128 v132; // xmm2
  __m128 v133; // xmm7
  __m128 v134; // xmm3
  __m128 v135; // xmm3
  __m128 v136; // xmm4
  __m128 v137; // xmm1
  int v138; // ecx
  int v139; // eax
  __m128 v140; // xmm3
  __m128 v141; // xmm1
  __m128 v142; // xmm2
  __m128 v143; // xmm5
  hkVector4f v144; // [rsp+0h] [rbp-168h]
  __m128 v145; // [rsp+10h] [rbp-158h]
  __m128 v146; // [rsp+20h] [rbp-148h]
  __m128 v147; // [rsp+30h] [rbp-138h]
  __m128 v148; // [rsp+40h] [rbp-128h]
  __m128 v149; // [rsp+50h] [rbp-118h]
  __m128 v150; // [rsp+60h] [rbp-108h]
  __m128 v151; // [rsp+70h] [rbp-F8h]
  __m128 v152; // [rsp+80h] [rbp-E8h]

  m_quad = vertex0->m_quad;
  v6 = _mm_sub_ps(vertex0->m_quad, vertex1->m_quad);
  v7 = _mm_sub_ps(vertex0->m_quad, ray->m_origin.m_quad);
  v8 = _mm_mul_ps(v6, v6);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_mul_ps(v6, v7);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_rcp_ps(v9);
  v13 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v12));
  m_real = radius->m_real;
  v15 = _mm_mul_ps(_mm_mul_ps(v13, v12), v11);
  v16 = _mm_mul_ps(m_real, m_real);
  v148 = v16;
  v17 = _mm_cmplt_ps(v15, query.m_quad);
  v18 = _mm_sub_ps(
          v7,
          _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v15, v17), _mm_andnot_ps(v17, query.m_quad))), v6));
  v19 = _mm_mul_ps(v18, v18);
  if ( (float)((float)(_mm_shuffle_ps(v19, v19, 85).m128_f32[0] + _mm_shuffle_ps(v19, v19, 0).m128_f32[0])
             + _mm_shuffle_ps(v19, v19, 170).m128_f32[0]) < v16.m128_f32[0] )
  {
    *fractionInOut = 0i64;
    return 1i64;
  }
  v21 = _mm_sub_ps(vertex1->m_quad, m_quad);
  v22 = _mm_mul_ps(v21, v21);
  if ( (float)((float)(_mm_shuffle_ps(v22, v22, 85).m128_f32[0] + _mm_shuffle_ps(v22, v22, 0).m128_f32[0])
             + _mm_shuffle_ps(v22, v22, 170).m128_f32[0]) <= 0.0 )
  {
    v124.m_quad = (__m128)ray->m_direction;
    v125 = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, m_real), 196);
    v126 = _mm_sub_ps(ray->m_origin.m_quad, v125);
    v127 = _mm_shuffle_ps(v125, v125, 255);
    v128 = _mm_mul_ps(v124.m_quad, v126);
    v129 = (__m128i)_mm_sub_ps(
                      (__m128)0i64,
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v128, v128, 85), _mm_shuffle_ps(v128, v128, 0)),
                        _mm_shuffle_ps(v128, v128, 170)));
    v130 = _mm_mul_ps(v124.m_quad, v124.m_quad);
    v131 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v130, v130, 85), _mm_shuffle_ps(v130, v130, 0)),
             _mm_shuffle_ps(v130, v130, 170));
    v132 = _mm_cmpeq_ps((__m128)0i64, v131);
    v133 = _mm_rcp_ps(v131);
    v134 = _mm_add_ps(
             _mm_mul_ps(
               _mm_or_ps(
                 _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v129, 0x1Fu), 0x1Fu), (__m128)_xmm), v132),
                 _mm_andnot_ps(
                   v132,
                   _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v133, v131)), v133), (__m128)v129))),
               v124.m_quad),
             v126);
    v135 = _mm_mul_ps(v134, v134);
    v136 = _mm_mul_ps(
             _mm_sub_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v135, v135, 85), _mm_shuffle_ps(v135, v135, 0)),
                 _mm_shuffle_ps(v135, v135, 170)),
               _mm_mul_ps(v127, v127)),
             _mm_sub_ps((__m128)0i64, v131));
    if ( v136.m128_f32[0] >= 0.0 )
    {
      v137 = _mm_rsqrt_ps(v136);
      v58 = 0;
      v138 = 0;
      v139 = 0;
      v140 = _mm_andnot_ps(
               _mm_cmple_ps(v136, (__m128)0i64),
               _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v136, v137), v137)),
                   _mm_mul_ps(*(__m128 *)_xmm, v137)),
                 v136));
      v141 = _mm_add_ps(_mm_sub_ps((__m128)0i64, v140), (__m128)v129);
      v142 = _mm_and_ps(_mm_cmplt_ps(v141, (__m128)0i64), *(__m128 *)hkVector4fComparison_maskToComparison_180);
      v143 = _mm_or_ps(_mm_and_ps(_mm_add_ps((__m128)v129, v140), v142), _mm_andnot_ps(v142, v141));
      if ( v143.m128_f32[0] >= (float)(fractionInOut->m_real.m128_f32[0] * v131.m128_f32[0]) )
        v138 = 1;
      if ( v143.m128_f32[0] < 0.0 )
        v139 = 1;
      if ( !(v139 | v138) )
      {
        v58 = (16 * _mm_movemask_ps(v142)) | 1;
        fractionInOut->m_real = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v133, v131)), v133), v143);
      }
    }
    else
    {
      return 0;
    }
    return v58;
  }
  v23.m_quad = (__m128)ray->m_origin;
  v144.m_quad = (__m128)ray->m_direction;
  v24 = _mm_mul_ps(v6, v6);
  v147 = fractionInOut->m_real;
  v146 = query.m_quad;
  v25 = _mm_sub_ps(m_quad, ray->m_origin.m_quad);
  v26 = 0i64;
  v27 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)), _mm_shuffle_ps(v24, v24, 170));
  v28 = _mm_mul_ps(v25, v6);
  v29 = _mm_rcp_ps(v27);
  v30 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v27, v29)), v29),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
            _mm_shuffle_ps(v28, v28, 170)));
  v31 = _mm_cmplt_ps(v30, query.m_quad);
  v32 = _mm_sub_ps(
          v25,
          _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v31, v30), _mm_andnot_ps(v31, query.m_quad))), v6));
  v33 = _mm_mul_ps(v32, v32);
  v34 = _mm_movemask_ps(
          _mm_cmplt_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
              _mm_shuffle_ps(v33, v33, 170)),
            v16));
  if ( v34 == 15 )
  {
    if ( _mm_movemask_ps(*(__m128 *)hkVector4fComparison_maskToComparison_180) != 15 )
      return 0;
    v35.m_quad = (__m128)ray->m_direction;
    v26 = *(__m128 *)&hkVector4fComparison_maskToComparison_180[60];
    v36 = _mm_mul_ps(fractionInOut->m_real, v35.m_quad);
    v37 = _mm_mul_ps(v6, v6);
    v38 = _mm_mul_ps(v35.m_quad, v35.m_quad);
    v39 = _mm_sub_ps(m_quad, _mm_add_ps(v36, ray->m_origin.m_quad));
    v40 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
            _mm_shuffle_ps(v37, v37, 170));
    v41 = _mm_mul_ps(v39, v6);
    v42 = _mm_rcp_ps(v40);
    v43 = _mm_mul_ps(
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v40, v42)), v42),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
              _mm_shuffle_ps(v41, v41, 170)));
    v44 = _mm_cmplt_ps(v43, query.m_quad);
    v45 = _mm_sub_ps(
            v39,
            _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v44, query.m_quad), _mm_and_ps(v44, v43))), v6));
    v46 = _mm_mul_ps(v45, v45);
    v47 = (float)(_mm_shuffle_ps(v46, v46, 85).m128_f32[0] + _mm_shuffle_ps(v46, v46, 0).m128_f32[0])
        + _mm_shuffle_ps(v46, v46, 170).m128_f32[0];
    v48 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
            _mm_shuffle_ps(v38, v38, 170));
    v49 = _mm_rsqrt_ps(v48);
    v50 = _mm_andnot_ps(
            _mm_cmple_ps(v48, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v49, v48), v49)),
                _mm_mul_ps(*(__m128 *)_xmm, v49)),
              v48));
    v51 = _mm_mul_ps(v21, v21);
    v52 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
            _mm_shuffle_ps(v51, v51, 170));
    v53 = _mm_rsqrt_ps(v52);
    v54 = _mm_mul_ps(*(__m128 *)_xmm, v53);
    v55 = _mm_mul_ps(_mm_mul_ps(v53, v52), v53);
    v56 = _mm_rcp_ps(v50);
    v147.m128_i32[0] = 1065353216;
    v146 = _mm_andnot_ps(
             _mm_cmpeq_ps(v50, (__m128)0i64),
             _mm_mul_ps(
               _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v56, v50)), v56),
               _mm_min_ps(
                 _mm_add_ps(
                   _mm_andnot_ps(
                     _mm_cmple_ps(v52, (__m128)0i64),
                     _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v55), v54), v52)),
                   _mm_mul_ps(radius->m_real, (__m128)xmmword_141A710F0)),
                 _mm_mul_ps(fractionInOut->m_real, v50))));
    v57.m_quad = _mm_xor_ps(
                   (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
                   _mm_mul_ps(ray->m_direction.m_quad, v146));
    v144.m_quad = v57.m_quad;
    v23.m_quad = _mm_sub_ps(ray->m_origin.m_quad, v57.m_quad);
    if ( v47 < v148.m128_f32[0] )
      return 0;
  }
  else
  {
    v57.m_quad = (__m128)ray->m_direction;
  }
  v59 = _mm_mul_ps(v57.m_quad, v21);
  v60 = _mm_sub_ps(m_quad, v23.m_quad);
  v61 = _mm_mul_ps(v60, v21);
  v151 = _mm_mul_ps(v57.m_quad, v57.m_quad);
  v62 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v61, v61, 85), _mm_shuffle_ps(v61, v61, 0)), _mm_shuffle_ps(v61, v61, 170));
  v63 = _mm_mul_ps(v60, v57.m_quad);
  v64 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v59, v59, 85), _mm_shuffle_ps(v59, v59, 0)), _mm_shuffle_ps(v59, v59, 170));
  v65 = _mm_mul_ps(v21, v21);
  v66 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)), _mm_shuffle_ps(v65, v65, 170));
  v67 = _mm_mul_ps(
          v66,
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v151, v151, 85), _mm_shuffle_ps(v151, v151, 0)),
            _mm_shuffle_ps(v151, v151, 170)));
  v68 = _mm_add_ps(*(__m128 *)&epsilon, *(__m128 *)&epsilon);
  v69 = _mm_add_ps(v68, v68);
  v70 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v63, v63, 85), _mm_shuffle_ps(v63, v63, 0)),
              _mm_shuffle_ps(v63, v63, 170)),
            v66),
          _mm_mul_ps(v62, v64));
  v71 = _mm_mul_ps(v64, v64);
  v72 = _mm_sub_ps(v67, v71);
  v73 = _mm_cmplt_ps(_mm_mul_ps(_mm_add_ps(v69, v69), _mm_add_ps(v71, v67)), v72);
  v74 = _mm_or_ps(_mm_andnot_ps(v73, v70), _mm_and_ps(v72, v73));
  v75 = _mm_rcp_ps(v74);
  v76 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v74, v75)), v75);
  v77 = _mm_rcp_ps(v66);
  v150 = _mm_mul_ps(v76, v70);
  v78 = _mm_sub_ps(
          _mm_add_ps(_mm_mul_ps(v150, v144.m_quad), v23.m_quad),
          _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v66, v77)), v77),
                _mm_sub_ps(_mm_mul_ps(v64, v150), v62)),
              v21),
            m_quad));
  v79 = _mm_mul_ps(v78, v78);
  v149 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v79, v79, 85), _mm_shuffle_ps(v79, v79, 0)),
           _mm_shuffle_ps(v79, v79, 170));
  if ( v149.m128_f32[0] <= v148.m128_f32[0] )
  {
    v152 = _mm_cmplt_ps(
             *(__m128 *)&epsilon,
             _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)),
               _mm_shuffle_ps(v65, v65, 170)));
    v80 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)),
            _mm_shuffle_ps(v65, v65, 170));
    v81 = _mm_rsqrt_ps(v80);
    v82 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v81, v80), v81)), _mm_mul_ps(*(__m128 *)_xmm, v81));
    v145 = _mm_and_ps(_mm_mul_ps(v82, v80), v152);
    v83 = _mm_and_ps(_mm_mul_ps(v21, v82), v152);
    v84 = _mm_mul_ps(v83, v144.m_quad);
    v85 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v84, v84, 85), _mm_shuffle_ps(v84, v84, 0)),
                  _mm_shuffle_ps(v84, v84, 170))),
              v83),
            v144.m_quad);
    v86 = _mm_mul_ps(v85, v85);
    v87 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v86, v86, 85), _mm_shuffle_ps(v86, v86, 0)),
            _mm_shuffle_ps(v86, v86, 170));
    v88 = _mm_rcp_ps(v87);
    v89 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v88, v87)), v88), _mm_sub_ps(v148, v149));
    v90 = _mm_rsqrt_ps(v89);
    v91 = _mm_cmpeq_ps((__m128)0i64, v87);
    v92 = _mm_or_ps(
            _mm_andnot_ps(
              v91,
              _mm_sub_ps(
                v150,
                _mm_andnot_ps(
                  _mm_cmple_ps(v89, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v89, v90), v90)),
                      _mm_mul_ps(*(__m128 *)_xmm, v90)),
                    v89)))),
            _mm_and_ps(v91, g_vectorfConstants[0]));
    if ( v92.m128_f32[0] < v147.m128_f32[0] )
    {
      v93 = _mm_mul_ps(m_quad, v83);
      v94 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v93, v93, 85), _mm_shuffle_ps(v93, v93, 0)),
              _mm_shuffle_ps(v93, v93, 170));
      v95 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v92, v144.m_quad), v23.m_quad), v83);
      v96 = _mm_sub_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v95, v95, 85), _mm_shuffle_ps(v95, v95, 0)),
                _mm_shuffle_ps(v95, v95, 170)),
              v94);
      if ( v92.m128_f32[0] >= 0.0 && v96.m128_f32[0] > 0.0 && v96.m128_f32[0] < v145.m128_f32[0] )
      {
        v58 = (16 * v34) | 1;
        v97 = _mm_and_ps(_mm_mul_ps(_mm_sub_ps(query.m_quad, v92), v146), v26);
        v98 = _mm_andnot_ps(v26, v92);
LABEL_25:
        fractionInOut->m_real = _mm_or_ps(v97, v98);
        return v58;
      }
      v99 = _mm_mul_ps(v83, v23.m_quad);
      v100 = _mm_rcp_ps(v145);
      v101 = _mm_sub_ps(
               v23.m_quad,
               _mm_add_ps(
                 _mm_mul_ps(
                   v21,
                   _mm_mul_ps(
                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v100, v145)), v100),
                     _mm_sub_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v99, v99, 85), _mm_shuffle_ps(v99, v99, 0)),
                         _mm_shuffle_ps(v99, v99, 170)),
                       v94))),
                 m_quad));
      if ( v92.m128_f32[0] >= 0.0
        || (v102 = _mm_mul_ps(v101, v101),
            (float)((float)(_mm_shuffle_ps(v102, v102, 85).m128_f32[0] + _mm_shuffle_ps(v102, v102, 0).m128_f32[0])
                  + _mm_shuffle_ps(v102, v102, 170).m128_f32[0]) <= v148.m128_f32[0]) )
      {
        v103 = _mm_cmple_ps(v96, (__m128)0i64);
        v58 = 0;
        v104 = _mm_or_ps(_mm_andnot_ps(v103, vertex1->m_quad), _mm_and_ps(m_quad, v103));
        v105 = _mm_shuffle_ps(v104, _mm_unpackhi_ps(v104, radius->m_real), 196);
        v106 = _mm_sub_ps(v23.m_quad, v105);
        v107 = _mm_shuffle_ps(v105, v105, 255);
        v108 = _mm_mul_ps(v106, v144.m_quad);
        v109 = (__m128i)_mm_sub_ps(
                          (__m128)0i64,
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v108, v108, 85), _mm_shuffle_ps(v108, v108, 0)),
                            _mm_shuffle_ps(v108, v108, 170)));
        v110 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v151, v151, 85), _mm_shuffle_ps(v151, v151, 0)),
                 _mm_shuffle_ps(v151, v151, 170));
        v111 = _mm_rcp_ps(v110);
        v112 = _mm_cmpeq_ps(v110, (__m128)0i64);
        v113 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_or_ps(
                     _mm_and_ps(
                       _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v109, 0x1Fu), 0x1Fu), (__m128)_xmm),
                       v112),
                     _mm_andnot_ps(
                       v112,
                       _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v111, v110)), v111), (__m128)v109))),
                   v144.m_quad),
                 v106);
        v114 = _mm_mul_ps(v113, v113);
        v115 = _mm_mul_ps(
                 _mm_sub_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v114, v114, 85), _mm_shuffle_ps(v114, v114, 0)),
                     _mm_shuffle_ps(v114, v114, 170)),
                   _mm_mul_ps(v107, v107)),
                 _mm_sub_ps((__m128)0i64, v110));
        if ( v115.m128_f32[0] < 0.0 )
          return v58;
        v116 = _mm_rsqrt_ps(v115);
        v117 = 0;
        v118 = 0;
        v119 = _mm_andnot_ps(
                 _mm_cmple_ps(v115, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v116, v115), v116)),
                     _mm_mul_ps(*(__m128 *)_xmm, v116)),
                   v115));
        v120 = _mm_add_ps(_mm_sub_ps((__m128)0i64, v119), (__m128)v109);
        v121 = _mm_and_ps(_mm_cmplt_ps(v120, (__m128)0i64), *(__m128 *)hkVector4fComparison_maskToComparison_180);
        v122 = _mm_or_ps(_mm_and_ps(_mm_add_ps(v119, (__m128)v109), v121), _mm_andnot_ps(v121, v120));
        if ( v122.m128_f32[0] >= (float)(v110.m128_f32[0] * v147.m128_f32[0]) )
          v117 = 1;
        if ( v122.m128_f32[0] < 0.0 )
          v118 = 1;
        if ( v118 | v117 )
          return v58;
        v123 = _mm_mul_ps(v122, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v111, v110)), v111));
        if ( !((16 * _mm_movemask_ps(v121)) | 1) )
          return v58;
        v58 = (16 * v34) | 1;
        v97 = _mm_and_ps(_mm_mul_ps(_mm_sub_ps(query.m_quad, v123), v146), v26);
        v98 = _mm_andnot_ps(v26, v123);
        goto LABEL_25;
      }
    }
  }
  return 0;
}

// File Line: 126
// RVA: 0xBD9CA0
_BOOL8 __fastcall hkaiLineOfSightUtil::checkLineOfSight(
        hkaiStreamingCollection *collection,
        hkaiLineOfSightUtil::LineOfSightInput *input,
        hkaiLineOfSightUtil::LineOfSightOutput *output)
{
  return hkaiLineOfSightUtil::checkLineOfSight(collection->m_instances.m_data, input, output);
}

// File Line: 131
// RVA: 0xBD9B60
_BOOL8 __fastcall hkaiLineOfSightUtil::checkLineOfSight(
        hkaiStreamingCollection::InstanceInfo *streamingInfo,
        hkaiLineOfSightUtil::LineOfSightInput *input,
        hkaiLineOfSightUtil::LineOfSightOutput *output)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  unsigned int m_goalFaceKey; // r8d
  __m128 v12; // xmm5
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  BOOL v16; // ebx
  _QWORD *v17; // r8
  _QWORD *v18; // rcx
  unsigned __int64 v19; // rax
  _QWORD *v20; // rcx
  hkVector4f directionIn; // [rsp+30h] [rbp-18h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtlineOfSight";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  if ( input->m_startFaceKey == -1 || (m_goalFaceKey = input->m_goalFaceKey, m_goalFaceKey == -1) )
  {
    v16 = 0;
  }
  else
  {
    v12 = _mm_sub_ps(input->m_goalPoint.m_quad, input->m_startPoint.m_quad);
    v13 = _mm_mul_ps(v12, v12);
    v14 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170));
    v15 = _mm_rsqrt_ps(v14);
    directionIn.m_quad = _mm_mul_ps(
                           v12,
                           _mm_andnot_ps(
                             _mm_cmple_ps(v14, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
                               _mm_mul_ps(*(__m128 *)_xmm, v15))));
    v16 = hkaiLineOfSightUtil::_lineOfSightInternal(
            &directionIn,
            &input->m_goalPoint,
            m_goalFaceKey,
            streamingInfo,
            input,
            output) == RESULT_REACHED_GOAL;
  }
  v17 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v18 = (_QWORD *)v17[1];
  if ( (unsigned __int64)v18 < v17[3] )
  {
    *v18 = "Et";
    v19 = __rdtsc();
    v20 = v18 + 2;
    *((_DWORD *)v20 - 2) = v19;
    v17[1] = v20;
  }
  return v16;
}

// File Line: 144
// RVA: 0xBD9CB0
__int64 __fastcall hkaiLineOfSightUtil::findDirectPath(
        hkaiStreamingCollection *collection,
        hkaiLineOfSightUtil::DirectPathInput *input,
        hkaiLineOfSightUtil::LineOfSightOutput *output)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkVector4f v11; // xmm4
  __m128 v12; // xmm1
  hkaiStreamingCollection::InstanceInfo *m_data; // r9
  hkaiLineOfSightUtil::LineOfSightResult v14; // ebx
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  _QWORD *v18; // rcx
  hkVector4f goalPoint; // [rsp+30h] [rbp-18h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtfindDirectPath";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  v11.m_quad = (__m128)input->m_direction;
  if ( (_mm_movemask_ps(_mm_cmpunord_ps(v11.m_quad, v11.m_quad)) & 7) != 0
    || (v12 = _mm_mul_ps(v11.m_quad, v11.m_quad),
        COERCE_FLOAT((unsigned int)(2
                                  * COERCE_INT(
                                      (float)((float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0]
                                                    + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])
                                            + _mm_shuffle_ps(v12, v12, 170).m128_f32[0])
                                    - 1.0)) >> 1) >= _mm_shuffle_ps(
                                                       (__m128)LODWORD(FLOAT_0_000099999997),
                                                       (__m128)LODWORD(FLOAT_0_000099999997),
                                                       0).m128_f32[0]) )
  {
    v14 = RESULT_INVALID_INPUT;
  }
  else
  {
    m_data = collection->m_instances.m_data;
    goalPoint.m_quad = _mm_add_ps(v11.m_quad, input->m_startPoint.m_quad);
    v14 = hkaiLineOfSightUtil::_lineOfSightInternal(&input->m_direction, &goalPoint, 0xFFFFFFFF, m_data, input, output);
  }
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "Et";
    v17 = __rdtsc();
    v18 = v16 + 2;
    *((_DWORD *)v18 - 2) = v17;
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
unsigned int __fastcall hkaiLineOfSightUtil::_raycastAgainstBoundary(
        hkVector4f *start,
        hkVector4f *end,
        hkSimdFloat32 *radius,
        bool shouldProject,
        hkVector4f *up,
        hkVector4f *edgeA,
        hkVector4f *edgeB,
        hkSimdFloat32 *hitFractionInOut)
{
  __m128 m_quad; // xmm6
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
  hkVector4f vertex1; // [rsp+30h] [rbp-78h] BYREF
  hkVector4f vertex0; // [rsp+40h] [rbp-68h] BYREF
  hkcdRay ray; // [rsp+50h] [rbp-58h] BYREF

  m_quad = end->m_quad;
  v9 = start->m_quad;
  v10 = edgeB->m_quad;
  vertex0.m_quad = edgeA->m_quad;
  vertex1.m_quad = v10;
  if ( shouldProject )
  {
    v11 = edgeB->m_quad;
    v12 = up->m_quad;
    v13 = _mm_mul_ps(up->m_quad, v9);
    v14 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170));
    v15 = _mm_mul_ps(up->m_quad, m_quad);
    v9 = _mm_sub_ps(v9, _mm_mul_ps(v14, up->m_quad));
    v16 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
            _mm_shuffle_ps(v15, v15, 170));
    v17 = _mm_mul_ps(up->m_quad, edgeA->m_quad);
    m_quad = _mm_sub_ps(m_quad, _mm_mul_ps(v16, up->m_quad));
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
  v20 = (__m128i)_mm_sub_ps(m_quad, v9);
  ray.m_origin.m_quad = v9;
  v21 = _mm_rcp_ps((__m128)v20);
  v22 = _mm_cmpeq_ps((__m128)0i64, (__m128)v20);
  ray.m_direction.m_quad = _mm_shuffle_ps((__m128)v20, _mm_unpackhi_ps((__m128)v20, hitFractionInOut->m_real), 196);
  v23 = _mm_mul_ps(ray.m_direction.m_quad, ray.m_direction.m_quad);
  ray.m_invDirection.m_quad = _mm_or_ps(
                                _mm_and_ps(
                                  _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v20, 0x1Fu), 0x1Fu), (__m128)_xmm),
                                  v22),
                                _mm_andnot_ps(
                                  v22,
                                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v20, v21)), v21)));
  ray.m_invDirection.m_quad.m128_i32[3] = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, ray.m_direction.m_quad)) & 7 | 0x3F000000;
  if ( (float)((float)(_mm_shuffle_ps(v23, v23, 85).m128_f32[0] + _mm_shuffle_ps(v23, v23, 0).m128_f32[0])
             + _mm_shuffle_ps(v23, v23, 170).m128_f32[0]) > 0.0 )
    return hkcdRayCastCapsuleWrapper(&ray, &vertex0, &vertex1, radius, hitFractionInOut);
  else
    return 0;
}

// File Line: 204
// RVA: 0xBDB1C0
__int64 __fastcall hkaiLineOfSightUtil::_checkAgainstNearbyBoundaries(
        hkVector4f *start,
        hkSimdFloat32 *end,
        hkaiGeneralAccessor *currentUp,
        hkSimdFloat32 *radius,
        hkaiGeneralAccessor *accessor,
        hkaiLineOfSightUtil::InputBase *input,
        unsigned int faceKeyIn,
        hkSimdFloat32 *hitFractionInOut)
{
  hkSimdFloat32 *v9; // r15
  _QWORD *Value; // rax
  _QWORD *v12; // rcx
  _QWORD *v13; // r9
  unsigned __int64 v14; // rax
  _QWORD *v15; // rcx
  __m128 m_quad; // xmm5
  __m128 m_real; // xmm4
  unsigned int v18; // esi
  __m128i v19; // xmm4
  __m128 v20; // xmm8
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm15
  __m128 v24; // xmm2
  hkLifoAllocator *v25; // rax
  unsigned int *m_cur; // rcx
  unsigned int *v27; // rdx
  unsigned int SizeInBytesFor; // ebx
  hkLifoAllocator *v29; // rax
  char *v30; // r9
  int v31; // edx
  char *v32; // rcx
  int v33; // ecx
  unsigned int *m_data; // r9
  unsigned int v35; // edi
  int v36; // r8d
  int v37; // ecx
  unsigned int v38; // edx
  int m_size; // eax
  int v40; // r11d
  int v41; // ecx
  unsigned int v42; // edx
  hkaiNavMesh::Face *v43; // rax
  int v44; // edi
  int index; // r12d
  hkaiNavMesh::Edge *v46; // rax
  unsigned __int64 m_accessor; // rdx
  int m_numOriginalVertices; // r8d
  __int64 v49; // rbx
  __int64 m_a; // rax
  __m128 *v51; // rcx
  __m128 v52; // xmm3
  __m128 v53; // xmm4
  __int64 v54; // rax
  __m128 v55; // xmm5
  __m128 v56; // xmm6
  __m128 v57; // xmm14
  __m128 *v58; // rax
  __m128 v59; // xmm1
  __m128 v60; // xmm0
  __m128 v61; // xmm2
  __m128 v62; // xmm0
  __m128 v63; // xmm13
  __m128 v64; // xmm12
  __m128 v65; // xmm2
  __m128 v66; // xmm1
  __m128 v67; // xmm11
  __m128 v68; // xmm1
  __m128 v69; // xmm2
  __m128 v70; // xmm10
  __m128 v71; // xmm9
  __m128 v72; // xmm1
  __m128 v73; // xmm2
  __m128 v74; // xmm1
  __m128 v75; // xmm7
  __m128 v76; // xmm6
  __m128 v77; // xmm1
  __m128 v78; // xmm3
  __m128 v79; // xmm1
  __m128 v80; // xmm5
  __m128 v81; // xmm1
  __m128 v82; // xmm8
  __m128 v83; // xmm7
  __m128 v84; // xmm1
  __m128 v85; // xmm0
  __m128 v86; // xmm3
  __m128 v87; // xmm3
  __m128 v88; // xmm0
  __m128 v89; // xmm2
  __m128 v90; // xmm11
  __m128 v91; // xmm0
  __int128 v92; // xmm4
  __m128 v93; // xmm3
  __m128 v94; // xmm3
  BOOL v95; // eax
  bool v96; // r15
  unsigned __int64 v97; // rcx
  __int128 v98; // xmm0
  int v99; // ecx
  unsigned int v100; // eax
  unsigned int v101; // r8d
  int v102; // r10d
  int v103; // ecx
  unsigned int v104; // edx
  int v105; // eax
  hkVector4f v106; // xmm6
  __m128 v107; // xmm5
  __m128 v108; // xmm3
  __m128 v109; // xmm1
  __m128 v110; // xmm2
  __m128 v111; // xmm1
  __m128 v112; // xmm2
  __m128 v113; // xmm1
  __m128 v114; // xmm2
  __m128 v115; // xmm1
  hkVector4f v116; // xmm15
  __m128i v117; // xmm5
  __m128 v118; // xmm3
  __m128 v119; // xmm1
  __m128 v120; // xmm4
  signed int v121; // ebx
  hkLifoAllocator *v122; // rax
  int v123; // r8d
  bool v124; // cc
  void *v125; // rbx
  int v126; // eax
  unsigned int *v127; // rdi
  signed int v128; // ebx
  hkLifoAllocator *v129; // rax
  int v130; // r8d
  _QWORD *v131; // rax
  _QWORD *v132; // rcx
  _QWORD *v133; // r8
  unsigned __int64 v134; // rax
  _QWORD *v135; // rcx
  unsigned int *array; // [rsp+60h] [rbp-90h] BYREF
  int v138; // [rsp+68h] [rbp-88h]
  int v139; // [rsp+6Ch] [rbp-84h]
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > v140; // [rsp+70h] [rbp-80h] BYREF
  int v141; // [rsp+88h] [rbp-68h]
  void *p; // [rsp+90h] [rbp-60h]
  int v143; // [rsp+98h] [rbp-58h]
  unsigned int v144; // [rsp+9Ch] [rbp-54h]
  unsigned int v145; // [rsp+A0h] [rbp-50h]
  hkaiNavMesh::Face *v146; // [rsp+A8h] [rbp-48h]
  hkVector4f vertex1; // [rsp+B0h] [rbp-40h] BYREF
  hkVector4f vertex0; // [rsp+D0h] [rbp-20h] BYREF
  hkSimdFloat32 fractionInOut; // [rsp+E0h] [rbp-10h] BYREF
  int *v150; // [rsp+F0h] [rbp+0h] BYREF
  int *dataPtrOut; // [rsp+F8h] [rbp+8h] BYREF
  hkcdRay v152; // [rsp+100h] [rbp+10h] BYREF
  hkcdRay ray; // [rsp+130h] [rbp+40h] BYREF
  __m128 v154; // [rsp+160h] [rbp+70h]
  __m128 v155; // [rsp+170h] [rbp+80h]
  int v156; // [rsp+180h] [rbp+90h] BYREF
  __int64 v157; // [rsp+188h] [rbp+98h]
  __int64 v158; // [rsp+190h] [rbp+A0h]
  __int128 v159; // [rsp+1A0h] [rbp+B0h]
  unsigned int v160; // [rsp+1B0h] [rbp+C0h]
  __int64 v161; // [rsp+1B8h] [rbp+C8h]
  int *v162; // [rsp+1C0h] [rbp+D0h]
  __int128 v163; // [rsp+1D0h] [rbp+E0h]
  unsigned int v164; // [rsp+1E0h] [rbp+F0h]
  hkaiNavMesh::Face *v165; // [rsp+1E8h] [rbp+F8h]
  int *v166; // [rsp+1F0h] [rbp+100h]
  __m128 *vars0; // [rsp+2F0h] [rbp+200h]
  __m128 *retaddr; // [rsp+2F8h] [rbp+208h]

  v9 = radius;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)Value[1];
  v13 = Value;
  if ( (unsigned __int64)v12 < Value[3] )
  {
    *v12 = "TtcheckAgainstNearbyBoundaries";
    v14 = __rdtsc();
    v15 = v12 + 2;
    *((_DWORD *)v15 - 2) = v14;
    v13[1] = v15;
  }
  m_quad = start->m_quad;
  m_real = end->m_real;
  v18 = 3;
  v141 = 0;
  v19 = (__m128i)_mm_sub_ps(m_real, m_quad);
  v20 = (__m128)_xmm;
  ray.m_origin.m_quad = m_quad;
  v21 = _mm_rcp_ps((__m128)v19);
  v22 = _mm_cmpeq_ps((__m128)v19, (__m128)0i64);
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
  ray.m_invDirection.m_quad.m128_i32[3] = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, v23)) & 7 | 0x3F000000;
  if ( (float)((float)(_mm_shuffle_ps(v24, v24, 85).m128_f32[0] + _mm_shuffle_ps(v24, v24, 0).m128_f32[0])
             + _mm_shuffle_ps(v24, v24, 170).m128_f32[0]) <= 0.0 )
    goto LABEL_98;
  array = 0i64;
  v138 = 0;
  v139 = 0x80000000;
  v140.m_elem.m_size = 64;
  v25 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (unsigned int *)v25->m_cur;
  v27 = m_cur + 64;
  if ( v25->m_slabSize < 256 || v27 > v25->m_end )
    m_cur = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v25, 256);
  else
    v25->m_cur = v27;
  array = m_cur;
  v140.m_elem.m_data = m_cur;
  v139 = -2147483584;
  SizeInBytesFor = hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::getSizeInBytesFor(64);
  v145 = SizeInBytesFor;
  if ( SizeInBytesFor )
  {
    v29 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v30 = (char *)v29->m_cur;
    v31 = (SizeInBytesFor + 127) & 0xFFFFFF80;
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
  v143 = SizeInBytesFor | 0x80000000;
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>(
    &v140,
    (unsigned int *)v30,
    SizeInBytesFor);
  v33 = v138;
  if ( v138 == (v139 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 4);
    v33 = v138;
  }
  array[v33] = (unsigned int)accessor;
  ++v138;
  m_data = v140.m_elem.m_data;
  while ( 1 )
  {
    v35 = array[--v138];
    v36 = v140.m_elem.m_size - 1;
    if ( v140.m_elem.m_size - 1 <= 0 || (v37 = v36 & (-1640531535 * (v35 >> 4)), v38 = m_data[v37], v38 == -1) )
    {
LABEL_21:
      m_size = v140.m_elem.m_size;
    }
    else
    {
      while ( v38 != v35 )
      {
        v37 = v36 & (v37 + 1);
        v38 = m_data[v37];
        if ( v38 == -1 )
          goto LABEL_21;
      }
      m_size = v37;
    }
    if ( m_size <= v36 )
      goto LABEL_74;
    if ( 2 * v140.m_numElems > v36 )
      break;
    v40 = 1;
    v41 = (v140.m_elem.m_size - 1) & (-1640531535 * (v35 >> 4));
    v42 = m_data[v41];
    if ( v42 != -1 )
    {
      while ( v42 != v35 )
      {
        v41 = (v140.m_elem.m_size - 1) & (v41 + 1);
        v42 = m_data[v41];
        if ( v42 == -1 )
          goto LABEL_30;
      }
      v40 = 0;
    }
LABEL_30:
    v140.m_numElems += v40;
    m_data[v41] = v35;
    v144 = v35 >> 22;
    hkaiGeneralAccessor::setSection(currentUp, v35 >> 22);
    v43 = hkaiNavMeshInstance_getWithData_hkaiNavMesh::Face_int__0(
            currentUp->m_accessor->m_originalFaces,
            currentUp->m_accessor->m_numOriginalFaces,
            &currentUp->m_accessor->m_instancedFaces,
            &currentUp->m_accessor->m_ownedFaces,
            currentUp->m_accessor->m_originalFaceData,
            &currentUp->m_accessor->m_instancedFaceData,
            &currentUp->m_accessor->m_ownedFaceData,
            &currentUp->m_accessor->m_faceMap,
            v35 & 0x3FFFFF,
            currentUp->m_accessor->m_faceDataStriding,
            (const int **)&dataPtrOut);
    v164 = v35;
    v166 = dataPtrOut;
    v157 = 0i64;
    v161 = 0i64;
    v165 = v43;
    v156 = -1;
    v160 = -1;
    v146 = v43;
    v44 = 0;
    if ( v43->m_numEdges > 0 )
    {
      while ( 1 )
      {
        index = v44 + v43->m_startEdgeIndex;
        v46 = hkaiNavMeshInstance_getWithData_hkaiNavMesh::Edge_int__1(
                currentUp->m_accessor->m_originalEdges,
                currentUp->m_accessor->m_numOriginalEdges,
                &currentUp->m_accessor->m_instancedEdges,
                &currentUp->m_accessor->m_ownedEdges,
                currentUp->m_accessor->m_originalEdgeData,
                &currentUp->m_accessor->m_instancedEdgeData,
                &currentUp->m_accessor->m_ownedEdgeData,
                &currentUp->m_accessor->m_edgeMap,
                index,
                currentUp->m_accessor->m_edgeDataStriding,
                (const int **)&v150);
        m_accessor = (unsigned __int64)currentUp->m_accessor;
        m_numOriginalVertices = currentUp->m_accessor->m_numOriginalVertices;
        v49 = (__int64)v46;
        m_a = v46->m_a;
        if ( (int)m_a >= m_numOriginalVertices )
          v51 = (__m128 *)(*(_QWORD *)(m_accessor + 304) + 16i64 * ((int)m_a - m_numOriginalVertices));
        else
          v51 = (__m128 *)(*(_QWORD *)(m_accessor + 48) + 16 * m_a);
        v52 = *(__m128 *)(m_accessor + 128);
        v53 = *(__m128 *)(m_accessor + 112);
        v54 = *(int *)(v49 + 4);
        v55 = *(__m128 *)(m_accessor + 144);
        v56 = *(__m128 *)(m_accessor + 160);
        v57 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*v51, *v51, 0), v53),
                    _mm_mul_ps(_mm_shuffle_ps(*v51, *v51, 85), v52)),
                  _mm_mul_ps(_mm_shuffle_ps(*v51, *v51, 170), v55)),
                v56);
        if ( (int)v54 >= m_numOriginalVertices )
          v58 = (__m128 *)(*(_QWORD *)(m_accessor + 304) + 16i64 * ((int)v54 - m_numOriginalVertices));
        else
          v58 = (__m128 *)(*(_QWORD *)(m_accessor + 48) + 16 * v54);
        v59 = *v58;
        v60 = *v58;
        vertex0.m_quad = v57;
        v61 = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v59, v59, 0), v53), _mm_mul_ps(_mm_shuffle_ps(v60, v59, 85), v52)),
                _mm_mul_ps(_mm_shuffle_ps(v59, v59, 170), v55));
        v62 = _mm_shuffle_ps(v23, v23, 255);
        v63 = _mm_mul_ps(_mm_sub_ps(*retaddr, *vars0), v62);
        v155 = v62;
        v154 = _mm_add_ps(v61, v56);
        vertex1.m_quad = v154;
        v64 = _mm_sub_ps(v154, v57);
        v65 = _mm_sub_ps(v57, *vars0);
        v66 = _mm_mul_ps(v64, v63);
        v67 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v66, v66, 85), _mm_shuffle_ps(v66, v66, 0)),
                _mm_shuffle_ps(v66, v66, 170));
        v68 = _mm_mul_ps(v65, v63);
        v69 = _mm_mul_ps(v65, v64);
        v70 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)),
                _mm_shuffle_ps(v68, v68, 170));
        v71 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v69, v69, 85), _mm_shuffle_ps(v69, v69, 0)),
                _mm_shuffle_ps(v69, v69, 170));
        v72 = _mm_mul_ps(v63, v63);
        v73 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v72, v72, 85), _mm_shuffle_ps(v72, v72, 0)),
                _mm_shuffle_ps(v72, v72, 170));
        v74 = _mm_mul_ps(v64, v64);
        v75 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v74, v74, 85), _mm_shuffle_ps(v74, v74, 0)),
                _mm_shuffle_ps(v74, v74, 170));
        v76 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v75, v73), _mm_mul_ps(v67, v67)), *(__m128 *)&epsilon);
        v77 = _mm_rcp_ps(v76);
        v78 = _mm_mul_ps(_mm_sub_ps(v20, _mm_mul_ps(v77, v76)), v77);
        v79 = _mm_rcp_ps(v75);
        v80 = _mm_mul_ps(_mm_sub_ps(v20, _mm_mul_ps(v79, v75)), v79);
        v81 = _mm_rcp_ps(v73);
        v82 = _mm_mul_ps(_mm_sub_ps(v20, _mm_mul_ps(v81, v73)), v81);
        v83 = _mm_sub_ps(_mm_mul_ps(v75, v70), _mm_mul_ps(v71, v67));
        v84 = _mm_cmplt_ps(v83, v76);
        v85 = _mm_mul_ps(_mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v84, v83), _mm_andnot_ps(v84, v76))), v78);
        v86 = _mm_cmple_ps(v76, *(__m128 *)&epsilon);
        v87 = _mm_sub_ps(
                _mm_mul_ps(_mm_or_ps(_mm_andnot_ps(v86, v85), _mm_and_ps(v86, query.m_quad)), _mm_mul_ps(v67, v80)),
                _mm_mul_ps(v71, v80));
        v88 = _mm_cmplt_ps(v87, query.m_quad);
        v89 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v88, v87), _mm_andnot_ps(v88, query.m_quad)));
        v90 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v67, v82), v89), _mm_mul_ps(v70, v82));
        v91 = _mm_cmplt_ps(v90, query.m_quad);
        v92 = (__int128)*vars0;
        v93 = _mm_sub_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v91, v90), _mm_andnot_ps(v91, query.m_quad))),
                    v63),
                  *vars0),
                _mm_add_ps(_mm_mul_ps(v89, v64), v57));
        v94 = _mm_mul_ps(v93, v93);
        if ( (float)((float)(_mm_shuffle_ps(v94, v94, 85).m128_f32[0] + _mm_shuffle_ps(v94, v94, 0).m128_f32[0])
                   + _mm_shuffle_ps(v94, v94, 170).m128_f32[0]) >= (float)(v9->m_real.m128_f32[0]
                                                                         * v9->m_real.m128_f32[0]) )
          goto LABEL_69;
        v95 = *(_DWORD *)(v49 + 8) != -1 && (*(_BYTE *)(v49 + 16) & 0x20) == 0;
        v96 = v95;
        if ( v95 )
        {
          v97 = radius[4].m_real.m128_u64[0];
          if ( !v97 )
            break;
          v98 = (__int128)*retaddr;
          v152.m_origin.m_quad.m128_u64[0] = m_accessor;
          v156 = -1;
          v157 = 0i64;
          v159 = v92;
          v163 = v98;
          v158 = 0i64;
          v161 = v49;
          v160 = index | (v144 << 22);
          v152.m_direction.m_quad.m128_i8[8] = 34;
          v162 = v150;
          v152.m_origin.m_quad.m128_u64[1] = (unsigned __int64)&radius[2].m_real.m128_u64[1];
          v152.m_direction.m_quad.m128_u64[0] = (unsigned __int64)&v156;
          if ( (*(unsigned __int8 (__fastcall **)(unsigned __int64, hkcdRay *))(*(_QWORD *)v97 + 40i64))(v97, &v152) )
            break;
        }
        fractionInOut.m_real = v155;
        if ( !hkcdRayCastCapsuleWrapper(&ray, &vertex0, &vertex1, end, &fractionInOut) )
        {
          v23 = ray.m_direction.m_quad;
LABEL_68:
          v9 = end;
LABEL_69:
          m_data = v140.m_elem.m_data;
          goto LABEL_70;
        }
        v106.m_quad = *vars0;
        v107 = *retaddr;
        if ( radius[4].m_real.m128_i8[9] )
        {
          v108 = start->m_quad;
          v109 = _mm_mul_ps(start->m_quad, v106.m_quad);
          v110 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v109, v109, 85), _mm_shuffle_ps(v109, v109, 0)),
                   _mm_shuffle_ps(v109, v109, 170));
          v111 = _mm_mul_ps(start->m_quad, v107);
          v106.m_quad = _mm_sub_ps(v106.m_quad, _mm_mul_ps(v110, start->m_quad));
          v112 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v111, v111, 85), _mm_shuffle_ps(v111, v111, 0)),
                   _mm_shuffle_ps(v111, v111, 170));
          v113 = _mm_mul_ps(start->m_quad, v57);
          v107 = _mm_sub_ps(v107, _mm_mul_ps(v112, start->m_quad));
          v114 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v113, v113, 85), _mm_shuffle_ps(v113, v113, 0)),
                   _mm_shuffle_ps(v113, v113, 170));
          v115 = _mm_mul_ps(start->m_quad, v154);
          vertex0.m_quad = _mm_sub_ps(v57, _mm_mul_ps(v114, start->m_quad));
          vertex1.m_quad = _mm_sub_ps(
                             v154,
                             _mm_mul_ps(
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v115, v115, 85), _mm_shuffle_ps(v115, v115, 0)),
                                 _mm_shuffle_ps(v115, v115, 170)),
                               v108));
        }
        v116.m_quad = (__m128)ray.m_direction;
        v20 = (__m128)_xmm;
        v117 = (__m128i)_mm_sub_ps(v107, v106.m_quad);
        v118 = _mm_cmpeq_ps((__m128)v117, (__m128)0i64);
        v152.m_origin = (hkVector4f)v106.m_quad;
        v119 = _mm_rcp_ps((__m128)v117);
        v152.m_direction.m_quad = _mm_shuffle_ps(
                                    (__m128)v117,
                                    _mm_unpackhi_ps(
                                      (__m128)v117,
                                      _mm_shuffle_ps(ray.m_direction.m_quad, ray.m_direction.m_quad, 255)),
                                    196);
        v120 = _mm_mul_ps(v152.m_direction.m_quad, v152.m_direction.m_quad);
        v152.m_invDirection.m_quad = _mm_or_ps(
                                       _mm_and_ps(
                                         _mm_xor_ps(
                                           (__m128)_mm_slli_epi32(_mm_srli_epi32(v117, 0x1Fu), 0x1Fu),
                                           (__m128)_xmm),
                                         v118),
                                       _mm_andnot_ps(
                                         v118,
                                         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v117, v119)), v119)));
        v152.m_invDirection.m_quad.m128_i32[3] = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, v152.m_direction.m_quad)) & 7 | 0x3F000000;
        if ( (float)((float)(_mm_shuffle_ps(v120, v120, 85).m128_f32[0] + _mm_shuffle_ps(v120, v120, 0).m128_f32[0])
                   + _mm_shuffle_ps(v120, v120, 170).m128_f32[0]) > 0.0 )
          hkcdRayCastCapsuleWrapper(&v152, &vertex0, &vertex1, end, &fractionInOut);
        m_data = v140.m_elem.m_data;
        v141 = 1;
        v23 = _mm_shuffle_ps(v116.m_quad, _mm_unpackhi_ps(v116.m_quad, fractionInOut.m_real), 196);
        v18 = v96 + 4;
        ray.m_direction.m_quad = v23;
        if ( !radius[4].m_real.m128_i8[12] )
          goto LABEL_78;
        v9 = end;
LABEL_71:
        ++v44;
        v43 = v146;
        if ( v44 >= v146->m_numEdges )
          goto LABEL_74;
      }
      v99 = *(_DWORD *)(v49 + 12);
      if ( (*(_BYTE *)(v49 + 16) & 0x40) != 0 )
        v100 = v99 & 0xFFC00000;
      else
        v100 = currentUp->m_accessor->m_runtimeId << 22;
      m_data = v140.m_elem.m_data;
      v101 = v100 | v99 & 0x3FFFFF;
      if ( v99 == -1 )
        v101 = -1;
      v102 = v140.m_elem.m_size - 1;
      if ( v140.m_elem.m_size - 1 <= 0
        || (v103 = v102 & (-1640531535 * (v101 >> 4)), v104 = v140.m_elem.m_data[v103], v104 == -1) )
      {
LABEL_54:
        v105 = v140.m_elem.m_size;
      }
      else
      {
        while ( v104 != v101 )
        {
          v103 = v102 & (v103 + 1);
          v104 = v140.m_elem.m_data[v103];
          if ( v104 == -1 )
            goto LABEL_54;
        }
        v105 = v103;
      }
      if ( v105 > v102 )
      {
        if ( v138 == (v139 & 0x3FFFFFFF) )
          break;
        array[v138++] = v101;
        goto LABEL_68;
      }
      v9 = end;
LABEL_70:
      v20 = (__m128)_xmm;
      goto LABEL_71;
    }
    m_data = v140.m_elem.m_data;
LABEL_74:
    if ( !v138 )
      goto $outputAndExit_0;
  }
  v18 = 2;
$outputAndExit_0:
  if ( v141 )
LABEL_78:
    input->m_startPoint.m_quad = _mm_shuffle_ps(v23, v23, 255);
  v140.m_elem.m_size = 0;
  if ( v140.m_elem.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      m_data,
      4 * v140.m_elem.m_capacityAndFlags);
  v140.m_elem.m_data = 0i64;
  v140.m_elem.m_capacityAndFlags = 0x80000000;
  v121 = (v145 + 127) & 0xFFFFFF80;
  v122 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v123 = (v121 + 15) & 0xFFFFFFF0;
  v124 = v121 <= v122->m_slabSize;
  v125 = p;
  if ( v124 && (char *)p + v123 == v122->m_cur && v122->m_firstNonLifoEnd != p )
    v122->m_cur = p;
  else
    hkLifoAllocator::slowBlockFree(v122, p, v123);
  if ( v143 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v125, v143 & 0x3FFFFFFF);
  v126 = v138;
  v127 = v140.m_elem.m_data;
  if ( v140.m_elem.m_data == array )
    v126 = 0;
  v138 = v126;
  v128 = (4 * v140.m_elem.m_size + 127) & 0xFFFFFF80;
  v129 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v130 = (v128 + 15) & 0xFFFFFFF0;
  if ( v128 > v129->m_slabSize || (char *)v127 + v130 != v129->m_cur || v129->m_firstNonLifoEnd == v127 )
    hkLifoAllocator::slowBlockFree(v129, v127, v130);
  else
    v129->m_cur = v127;
  v138 = 0;
  if ( v139 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v139);
  array = 0i64;
  v139 = 0x80000000;
LABEL_98:
  v131 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v132 = (_QWORD *)v131[1];
  v133 = v131;
  if ( (unsigned __int64)v132 < v131[3] )
  {
    *v132 = "Et";
    v134 = __rdtsc();
    v135 = v132 + 2;
    *((_DWORD *)v135 - 2) = v134;
    v133[1] = v135;
  }
  return v18;
}

// File Line: 378
// RVA: 0xBD9DE0
__int64 __fastcall hkaiLineOfSightUtil::_lineOfSightInternal(
        hkVector4f *directionIn,
        hkVector4f *goalPoint,
        unsigned int goalKey,
        hkaiStreamingCollection::InstanceInfo *streamingInfo,
        hkaiLineOfSightUtil::InputBase *input,
        hkaiLineOfSightUtil::LineOfSightOutput *output)
{
  hkaiLineOfSightUtil::LineOfSightOutput *v6; // r12
  hkaiLineOfSightUtil::InputBase *v7; // r14
  unsigned int m_startFaceKey; // edi
  float m_searchRadius; // xmm1_4
  __m128 m_quad; // xmm8
  __m128 v13; // xmm9
  __m128 v14; // xmm1
  __m128 v15; // xmm10
  char m_bool; // cl
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
  __m128 m_searchRadius_low; // xmm0
  __m128 v28; // xmm6
  __m128 v29; // xmm15
  __m128 v30; // xmm1
  __m128 v31; // xmm6
  hkLifoAllocator *Value; // rax
  char *m_cur; // rcx
  char *v34; // rdx
  __m128 v35; // xmm1
  __m128 v36; // xmm1
  __m128 v37; // xmm14
  __m128 v38; // xmm6
  int v39; // r15d
  __m128 m_real; // xmm7
  __m128 v41; // xmm11
  __m128 v42; // xmm8
  unsigned int v43; // esi
  int v44; // r13d
  hkaiNavMesh::Face *v45; // rax
  int *v46; // rbx
  hkaiNavMeshInstance *m_accessor; // rcx
  int v48; // edx
  unsigned int v49; // r13d
  int index; // r15d
  hkaiNavMesh::Edge *v51; // rax
  __int64 m_a; // rdx
  hkaiNavMesh::Edge *v53; // r10
  int m_numOriginalVertices; // r8d
  hkVector4f *v55; // rdx
  __int64 m_b; // rax
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
  __m128 v72; // xmm1
  __m128 v73; // xmm3
  __m128 v74; // xmm1
  __m128 v75; // xmm2
  int v76; // r8d
  __int64 v77; // rdx
  bool v78; // zf
  int v79; // eax
  bool v80; // r9
  unsigned int m_oppositeEdge; // r8d
  unsigned int v82; // edx
  int v83; // eax
  unsigned int m_oppositeFace; // r8d
  unsigned int v85; // edx
  int v86; // eax
  unsigned int v87; // r15d
  __m128 v88; // xmm10
  __m128 v89; // xmm6
  __m128 v90; // xmm1
  __m128 v91; // xmm3
  __m128 v92; // xmm2
  __m128 v93; // xmm10
  __m128 v94; // xmm11
  __m128 v95; // xmm1
  __m128 v96; // xmm4
  float v97; // xmm1_4
  __m128 v98; // xmm6
  __m128 v99; // xmm1
  __m128 v100; // xmm1
  __m128 v101; // xmm3
  __m128 v102; // xmm2
  __m128 v103; // xmm5
  __m128 v104; // xmm4
  __m128 v105; // xmm1
  __m128 v106; // xmm1
  __m128 v107; // xmm2
  __m128 v108; // xmm1
  __m128 v109; // xmm2
  __m128 v110; // xmm1
  __m128 v111; // xmm1
  __m128 v112; // xmm4
  __m128 v113; // xmm1
  __m128 v114; // xmm4
  __m128 v115; // xmm3
  __m128 v116; // xmm5
  __m128 v117; // xmm2
  __m128 v118; // xmm1
  __m128 v119; // xmm0
  __m128 v120; // xmm2
  __m128 v121; // xmm4
  __m128 v122; // xmm3
  __m128 v123; // xmm1
  __m128 v124; // xmm3
  __m128 v125; // xmm1
  __m128 v126; // xmm0
  hkaiAstarEdgeFilter *m_edgeFilter; // r8
  int v128; // ebx
  int v129; // eax
  int v130; // ebx
  hkaiAstarCostModifier *m_costModifier; // r9
  hkaiLineOfSightUtil::LineOfSightResult v132; // ebx
  __m128 v133; // xmm8
  __m128 v134; // xmm2
  __m128 v135; // xmm9
  __m128 v136; // xmm6
  __m128 v137; // xmm6
  __m128 v138; // xmm7
  __m128 v139; // xmm1
  __m128 v140; // xmm5
  __m128 v141; // xmm2
  __m128 v142; // xmm4
  __m128 v143; // xmm3
  __m128 v144; // xmm6
  __m128 v145; // xmm1
  __m128 v146; // xmm2
  __m128 v147; // xmm3
  __m128 v148; // xmm9
  __m128 v149; // xmm0
  __m128 v150; // xmm9
  __m128 v151; // xmm9
  __m128 v152; // xmm9
  __m128 v153; // xmm9
  __m128 v154; // xmm1
  __m128 v155; // xmm3
  __m128 v156; // xmm2
  __m128 v157; // xmm9
  __m128 v158; // xmm2
  int v159; // eax
  char *v160; // rdi
  signed int v161; // ebx
  hkLifoAllocator *v162; // rax
  int v163; // r8d
  int v164; // [rsp+58h] [rbp-80h]
  int section; // [rsp+60h] [rbp-78h]
  bool v166; // [rsp+64h] [rbp-74h]
  hkaiGeneralAccessor accessor; // [rsp+68h] [rbp-70h] BYREF
  char *v168; // [rsp+80h] [rbp-58h]
  int v169; // [rsp+88h] [rbp-50h]
  int v170; // [rsp+8Ch] [rbp-4Ch]
  void *p; // [rsp+90h] [rbp-48h]
  int v172; // [rsp+98h] [rbp-40h]
  hkaiNavMesh::Face *v173; // [rsp+A0h] [rbp-38h]
  int faceIndex[4]; // [rsp+A8h] [rbp-30h] BYREF
  int v175[2]; // [rsp+B8h] [rbp-20h] BYREF
  __int64 m_sectionInfo; // [rsp+C0h] [rbp-18h]
  int v177; // [rsp+C8h] [rbp-10h]
  int v178; // [rsp+D0h] [rbp-8h]
  int v179; // [rsp+D4h] [rbp-4h]
  __m128 *v180; // [rsp+D8h] [rbp+0h]
  __m128 *v181; // [rsp+E0h] [rbp+8h]
  hkVector4f end; // [rsp+E8h] [rbp+10h] BYREF
  hkQuaternionf v183; // [rsp+F8h] [rbp+20h] BYREF
  __m128 v184; // [rsp+108h] [rbp+30h] BYREF
  hkVector4f start; // [rsp+118h] [rbp+40h] BYREF
  hkSimdFloat32 radius; // [rsp+128h] [rbp+50h] BYREF
  int *dataPtrOut; // [rsp+138h] [rbp+60h] BYREF
  int *v188; // [rsp+140h] [rbp+68h] BYREF
  hkVector4f edgeB; // [rsp+148h] [rbp+70h] BYREF
  __m128 v190; // [rsp+158h] [rbp+80h] BYREF
  hkVector4f edgeA; // [rsp+168h] [rbp+90h] BYREF
  int v192; // [rsp+178h] [rbp+A0h] BYREF
  int *v193; // [rsp+180h] [rbp+A8h]
  int *v194; // [rsp+188h] [rbp+B0h]
  __m128 v195; // [rsp+198h] [rbp+C0h]
  int v196; // [rsp+1A8h] [rbp+D0h]
  int *p_m_currentSection; // [rsp+1B0h] [rbp+D8h]
  int *v198; // [rsp+1B8h] [rbp+E0h]
  __m128 v199; // [rsp+1C8h] [rbp+F0h]
  unsigned int v200; // [rsp+1D8h] [rbp+100h]
  hkaiNavMesh::Face *v201; // [rsp+1E0h] [rbp+108h]
  int *v202; // [rsp+1E8h] [rbp+110h]
  hkSimdFloat32 hitFractionInOut; // [rsp+1F8h] [rbp+120h] BYREF
  hkSimdFloat32 v204; // [rsp+208h] [rbp+130h] BYREF
  hkVector4f from; // [rsp+218h] [rbp+140h] BYREF
  hkSimdFloat32 v206; // [rsp+228h] [rbp+150h] BYREF
  __m128 v207; // [rsp+238h] [rbp+160h] BYREF
  hkaiNavMeshInstance *v208; // [rsp+248h] [rbp+170h] BYREF
  hkaiAgentTraversalInfo *p_m_agentInfo; // [rsp+250h] [rbp+178h]
  int *v210; // [rsp+258h] [rbp+180h]
  char v211; // [rsp+260h] [rbp+188h]
  __m128 v212; // [rsp+268h] [rbp+190h]
  __m128 v213; // [rsp+278h] [rbp+1A0h]
  __m128 v214; // [rsp+288h] [rbp+1B0h]
  __m128 v215; // [rsp+298h] [rbp+1C0h]
  __m128 v216; // [rsp+2A8h] [rbp+1D0h] BYREF
  __m128 v217; // [rsp+2B8h] [rbp+1E0h]
  hkaiNavMeshUtils v218; // [rsp+2C8h] [rbp+1F0h] BYREF
  __m128 *v219; // [rsp+3C0h] [rbp+2E8h]
  int v220; // [rsp+3C8h] [rbp+2F0h]
  hkaiLineOfSightUtil::InputBase *retaddr; // [rsp+3D8h] [rbp+300h]

  v7 = retaddr;
  m_startFaceKey = retaddr->m_startFaceKey;
  if ( m_startFaceKey == -1 || !streamingInfo )
    return 0i64;
  m_searchRadius = retaddr->m_searchRadius;
  if ( m_searchRadius > 0.0 && (float)(retaddr->m_agentInfo.m_diameter * 0.5) > m_searchRadius )
    return 0i64;
  m_quad = retaddr->m_up.m_quad;
  LODWORD(accessor.m_accessor) = -1;
  accessor.m_currentSection = -1;
  v13 = directionIn->m_quad;
  accessor.m_sectionInfo = streamingInfo;
  accessor.m_accessor = 0i64;
  v14 = m_quad;
  *(__m128 *)faceIndex = m_quad;
  if ( retaddr->m_isWallClimbing.m_bool )
  {
    hkaiGeneralAccessor::setSection(&accessor, m_startFaceKey >> 22);
    hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)&v207,
      (hkSimdFloat32 *)accessor.m_accessor,
      (hkaiNavMeshInstance *)(m_startFaceKey & 0x3FFFFF),
      (__m128 *)faceIndex);
    v14 = *(__m128 *)faceIndex;
  }
  v15 = (__m128)_xmm;
  m_bool = retaddr->m_exactInternalVertexHandling.m_bool;
  v166 = retaddr->m_searchRadius > 0.0;
  v177 = 4;
  m_sectionInfo = -1i64;
  v196 = -1;
  p_m_currentSection = 0i64;
  v200 = -1;
  v201 = 0i64;
  v192 = -1;
  v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v14), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v13));
  v18 = _mm_shuffle_ps(v17, v17, 201);
  v193 = 0i64;
  v194 = 0i64;
  v19 = _mm_mul_ps(v18, v18);
  v181 = &v190;
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_rsqrt_ps(v20);
  v195 = retaddr->m_startPoint.m_quad;
  v22 = v195;
  end.m_quad = v195;
  v23 = _mm_mul_ps(
          v18,
          _mm_andnot_ps(
            _mm_cmple_ps(v20, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
              _mm_mul_ps(v21, *(__m128 *)_xmm))));
  v24 = _mm_mul_ps(v23, v195);
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
  v207 = _mm_shuffle_ps((__m128)LODWORD(retaddr->m_maximumPathLength), (__m128)LODWORD(retaddr->m_maximumPathLength), 0);
  m_searchRadius_low = (__m128)LODWORD(retaddr->m_searchRadius);
  radius.m_real = v26;
  v217 = _mm_sub_ps(_mm_shuffle_ps(m_searchRadius_low, m_searchRadius_low, 0), v26);
  v214 = _mm_mul_ps(v217, v217);
  if ( m_bool )
    v190 = aabbOut.m_quad;
  else
    v190 = _mm_sub_ps((__m128)0i64, v26);
  v180 = &v184;
  if ( m_bool )
    v184 = aabbOut.m_quad;
  else
    v184 = v26;
  v28 = directionIn->m_quad;
  v29 = 0i64;
  v168 = 0i64;
  v169 = 0;
  v170 = 0x80000000;
  v172 = 8;
  v30 = _mm_mul_ps(v28, m_quad);
  v31 = _mm_sub_ps(
          v28,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
              _mm_shuffle_ps(v30, v30, 170)),
            m_quad));
  v215 = v31;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (char *)Value->m_cur;
  v34 = m_cur + 128;
  if ( Value->m_slabSize < 128 || v34 > Value->m_end )
    m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, 128);
  else
    Value->m_cur = v34;
  v35 = retaddr->m_startPoint.m_quad;
  LOBYTE(retaddr) = retaddr->m_mode.m_storage == 0;
  v168 = m_cur;
  p = m_cur;
  v36 = _mm_mul_ps(v35, v31);
  v170 = -2147483640;
  v169 = 0;
  v37 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)), _mm_shuffle_ps(v36, v36, 170));
  if ( !v6->m_doNotExceedArrayCapacity.m_bool
    || v6->m_pointsOut.m_size < (v6->m_pointsOut.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    if ( v6->m_pointsOut.m_size == (v6->m_pointsOut.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v6->m_pointsOut, 16);
    v6->m_pointsOut.m_data[v6->m_pointsOut.m_size++] = v7->m_startPoint;
  }
  v38 = *(__m128 *)_xmm;
  while ( 2 )
  {
    v39 = m_startFaceKey >> 22;
    section = m_startFaceKey >> 22;
    hkaiGeneralAccessor::setSection(&accessor, m_startFaceKey >> 22);
    m_real = query.m_quad;
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
            m_startFaceKey & 0x3FFFFF,
            accessor.m_accessor->m_faceDataStriding,
            (const int **)&dataPtrOut);
    v173 = v45;
    if ( m_startFaceKey == v220 )
    {
      v22 = *v219;
      v43 = 9;
      end.m_quad = *v219;
    }
    v164 = 4;
    accessor.m_sectionInfo = (hkaiStreamingCollection::InstanceInfo *)-1i64;
    v46 = 0i64;
    if ( v43 == 9 )
    {
      m_accessor = accessor.m_accessor;
      edgeA.m_quad = *v219;
      edgeB.m_quad = edgeA.m_quad;
      goto LABEL_89;
    }
    if ( v45->m_numEdges <= 0 )
    {
LABEL_70:
      m_real = 0i64;
      v43 = 1;
LABEL_71:
      v87 = m_startFaceKey >> 22;
      goto $outputAndExit;
    }
    m_accessor = accessor.m_accessor;
    v48 = (int)accessor.m_accessor;
    v49 = m_startFaceKey & 0xFFC00000;
    while ( 1 )
    {
      index = (_DWORD)v46 + v45->m_startEdgeIndex;
      if ( (index | v49) == v48 )
        goto LABEL_48;
      v51 = hkaiNavMeshInstance_getWithData_hkaiNavMesh::Edge_int__1(
              m_accessor->m_originalEdges,
              m_accessor->m_numOriginalEdges,
              &m_accessor->m_instancedEdges,
              &m_accessor->m_ownedEdges,
              m_accessor->m_originalEdgeData,
              &m_accessor->m_instancedEdgeData,
              &m_accessor->m_ownedEdgeData,
              &m_accessor->m_edgeMap,
              index,
              m_accessor->m_edgeDataStriding,
              (const int **)&v188);
      m_accessor = accessor.m_accessor;
      m_a = v51->m_a;
      v53 = v51;
      m_numOriginalVertices = accessor.m_accessor->m_numOriginalVertices;
      v55 = (int)m_a >= m_numOriginalVertices
          ? &accessor.m_accessor->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices]
          : &accessor.m_accessor->m_originalVertices[m_a];
      m_b = v51->m_b;
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
      v58 = (int)m_b >= m_numOriginalVertices
          ? &accessor.m_accessor->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices]
          : &accessor.m_accessor->m_originalVertices[m_b];
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
      if ( _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(*v180, v68), _mm_cmple_ps(v65, *v181))) )
        break;
LABEL_47:
      v48 = (int)accessor.m_accessor;
LABEL_48:
      LODWORD(v46) = (_DWORD)v46 + 1;
      if ( (int)v46 >= v173->m_numEdges )
        goto LABEL_70;
      v45 = v173;
    }
    v69 = _mm_sub_ps(v65, v68);
    v70 = _mm_rcp_ps(v69);
    v71 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v70, v69)), v70), v65);
    v72 = _mm_cmplt_ps(v71, query.m_quad);
    v73 = _mm_add_ps(
            _mm_mul_ps(
              _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v72, query.m_quad), _mm_and_ps(v72, v71))),
              _mm_sub_ps(v60, v57)),
            v57);
    v74 = _mm_mul_ps(v73, v215);
    v75 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v74, v74, 85), _mm_shuffle_ps(v74, v74, 0)),
            _mm_shuffle_ps(v74, v74, 170));
    if ( v7->m_isWallClimbing.m_bool )
      goto LABEL_52;
    if ( v75.m128_f32[0] <= v37.m128_f32[0] )
    {
      v76 = 0;
      v77 = 0i64;
      if ( v169 <= 0 )
        goto LABEL_46;
      while ( *(_DWORD *)&v168[4 * v77] != m_startFaceKey )
      {
        ++v77;
        ++v76;
        if ( v77 >= v169 )
          goto LABEL_46;
      }
      if ( v76 == -1 )
      {
LABEL_46:
        if ( (v170 & 0x3FFFFFFF) != v169 )
        {
          *(_DWORD *)&v168[4 * v169++] = m_startFaceKey;
          m_accessor = accessor.m_accessor;
          goto LABEL_52;
        }
      }
      goto LABEL_47;
    }
    v169 = 0;
LABEL_52:
    v78 = v53->m_oppositeEdge == -1;
    v22 = v73;
    end.m_quad = v73;
    v37 = _mm_max_ps(v37, v75);
    if ( v78 || (v79 = 1, (v53->m_flags.m_storage & 0x20) != 0) )
      v79 = 0;
    v46 = v188;
    accessor.m_currentSection = v53->m_a;
    v80 = v79 != 0;
    *(&accessor.m_currentSection + 1) = v53->m_b;
    accessor.m_sectionInfo = *(hkaiStreamingCollection::InstanceInfo **)&v53->m_oppositeEdge;
    v164 = *(_DWORD *)&v53->m_flags.m_storage;
    m_oppositeEdge = v53->m_oppositeEdge;
    if ( (v53->m_flags.m_storage & 0x40) != 0 )
      v82 = m_oppositeEdge & 0xFFC00000;
    else
      v82 = m_accessor->m_runtimeId << 22;
    v83 = v82 | m_oppositeEdge & 0x3FFFFF;
    if ( m_oppositeEdge == -1 )
      v83 = -1;
    LODWORD(accessor.m_sectionInfo) = v83;
    m_oppositeFace = v53->m_oppositeFace;
    if ( (v53->m_flags.m_storage & 0x40) != 0 )
      v85 = m_oppositeFace & 0xFFC00000;
    else
      v85 = m_accessor->m_runtimeId << 22;
    v86 = v85 | m_oppositeFace & 0x3FFFFF;
    if ( m_oppositeFace == -1 )
      v86 = -1;
    HIDWORD(accessor.m_sectionInfo) = v86;
    if ( index == -1 )
      goto LABEL_70;
    v44 = index | v49;
    if ( v80 )
    {
      v38 = *(__m128 *)_xmm;
      v45 = v173;
      v39 = m_startFaceKey >> 22;
      goto LABEL_89;
    }
    v43 = 4;
    if ( (_BYTE)retaddr )
      goto LABEL_71;
    v78 = v7->m_projectedRadiusCheck.m_bool == 0;
    hitFractionInOut.m_real = query.m_quad;
    hkaiLineOfSightUtil::_raycastAgainstBoundary(
      &start,
      &end,
      &radius,
      !v78,
      (hkVector4f *)faceIndex,
      &edgeA,
      &edgeB,
      &hitFractionInOut);
    m_accessor = accessor.m_accessor;
    v38 = *(__m128 *)_xmm;
    v45 = v173;
    v39 = m_startFaceKey >> 22;
    if ( hitFractionInOut.m_real.m128_f32[0] < 1.0 )
      m_real = hitFractionInOut.m_real;
LABEL_89:
    v99 = _mm_sub_ps(v41, v22);
    v100 = _mm_mul_ps(v99, v99);
    v101 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v100, v100, 85), _mm_shuffle_ps(v100, v100, 0)),
             _mm_shuffle_ps(v100, v100, 170));
    v102 = _mm_rsqrt_ps(v101);
    v42 = _mm_andnot_ps(
            _mm_cmple_ps(v101, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(_mm_sub_ps(v15, _mm_mul_ps(_mm_mul_ps(v101, v102), v102)), _mm_mul_ps(v38, v102)),
              v101));
    if ( v166 )
    {
      v103 = v7->m_startPoint.m_quad;
      v104 = v22;
      v105 = v41;
      if ( v7->m_projectedRadiusCheck.m_bool )
      {
        v106 = _mm_mul_ps(*(__m128 *)faceIndex, v103);
        v107 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v106, v106, 85), _mm_shuffle_ps(v106, v106, 0)),
                 _mm_shuffle_ps(v106, v106, 170));
        v108 = _mm_mul_ps(*(__m128 *)faceIndex, v22);
        v103 = _mm_sub_ps(v103, _mm_mul_ps(v107, *(__m128 *)faceIndex));
        v109 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v108, v108, 85), _mm_shuffle_ps(v108, v108, 0)),
                 _mm_shuffle_ps(v108, v108, 170));
        v110 = _mm_mul_ps(*(__m128 *)faceIndex, v41);
        v104 = _mm_sub_ps(v22, _mm_mul_ps(v109, *(__m128 *)faceIndex));
        v105 = _mm_sub_ps(
                 v41,
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v110, v110, 85), _mm_shuffle_ps(v110, v110, 0)),
                     _mm_shuffle_ps(v110, v110, 170)),
                   *(__m128 *)faceIndex));
      }
      v111 = _mm_sub_ps(v105, v103);
      v112 = _mm_sub_ps(v104, v103);
      v113 = _mm_mul_ps(v111, v111);
      v114 = _mm_mul_ps(v112, v112);
      v115 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v113, v113, 85), _mm_shuffle_ps(v113, v113, 0)),
               _mm_shuffle_ps(v113, v113, 170));
      v116 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v114, v114, 85), _mm_shuffle_ps(v114, v114, 0)),
               _mm_shuffle_ps(v114, v114, 170));
      if ( v116.m128_f32[0] > v214.m128_f32[0] )
      {
        v117 = _mm_rsqrt_ps(v115);
        v118 = _mm_sub_ps(v15, _mm_mul_ps(_mm_mul_ps(v117, v115), v117));
        v119 = _mm_mul_ps(v38, v117);
        v120 = _mm_rsqrt_ps(v116);
        v121 = _mm_andnot_ps(_mm_cmple_ps(v115, (__m128)0i64), _mm_mul_ps(_mm_mul_ps(v118, v119), v115));
        v122 = _mm_sub_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v116, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(_mm_sub_ps(v15, _mm_mul_ps(_mm_mul_ps(v120, v116), v120)), _mm_mul_ps(v120, v38)),
                     v116)),
                 v121);
        v123 = _mm_rcp_ps(v122);
        v124 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v123, v122)), v123), _mm_sub_ps(v217, v121));
        v125 = _mm_cmplt_ps(v124, (__m128)xmmword_141A712A0);
        v126 = _mm_max_ps(
                 aabbOut.m_quad,
                 _mm_or_ps(_mm_and_ps(v125, v124), _mm_andnot_ps(v125, (__m128)xmmword_141A712A0)));
        if ( v126.m128_f32[0] < m_real.m128_f32[0] )
        {
          m_real = v126;
          v43 = 6;
          if ( (_BYTE)retaddr )
            goto LABEL_71;
        }
      }
    }
    m_edgeFilter = v7->m_edgeFilter;
    if ( !m_edgeFilter && !v7->m_costModifier )
      goto LABEL_119;
    if ( v43 == 9 )
    {
      v196 = -1;
      p_m_currentSection = 0i64;
      v198 = 0i64;
LABEL_102:
      v201 = v45;
      v199 = v22;
      v202 = dataPtrOut;
      v128 = 0;
      if ( v43 == 9 )
        v128 = 64;
      v129 = 0;
      v200 = m_startFaceKey;
      if ( !section )
        v129 = 16;
      v130 = v129 | v128;
      if ( !v130 )
        LOBYTE(v130) = 32;
      if ( m_edgeFilter )
      {
        v208 = m_accessor;
        p_m_agentInfo = &v7->m_agentInfo;
        v210 = &v192;
        v211 = v130 | 2;
        if ( !((unsigned __int8 (__fastcall *)(hkaiAstarEdgeFilter *, hkaiNavMeshInstance **))m_edgeFilter->vfptr[2].__first_virtual_table_function__)(
                m_edgeFilter,
                &v208) )
        {
          if ( v43 == 3 )
            v43 = 5;
          if ( (_BYTE)retaddr )
          {
            v43 = 5;
            goto LABEL_71;
          }
          v78 = v7->m_projectedRadiusCheck.m_bool == 0;
          v204.m_real = m_real;
          hkaiLineOfSightUtil::_raycastAgainstBoundary(
            &start,
            &end,
            &radius,
            !v78,
            (hkVector4f *)faceIndex,
            &edgeA,
            &edgeB,
            &v204);
          if ( v204.m_real.m128_f32[0] < m_real.m128_f32[0] )
          {
            m_real = v204.m_real;
            v43 = 5;
          }
        }
        m_accessor = accessor.m_accessor;
      }
      m_costModifier = v7->m_costModifier;
      if ( m_costModifier )
      {
        v208 = m_accessor;
        p_m_agentInfo = &v7->m_agentInfo;
        v212 = v29;
        v213 = v42;
        v211 = v130 | 2;
        v210 = &v192;
        ((void (__fastcall *)(hkaiAstarCostModifier *, __m128 *, hkaiNavMeshInstance **))m_costModifier->vfptr[2].__first_virtual_table_function__)(
          m_costModifier,
          &v216,
          &v208);
        v42 = v216;
      }
      goto LABEL_119;
    }
    if ( LODWORD(accessor.m_sectionInfo) != -1 && (v164 & 0x20) == 0 )
    {
      v196 = v44;
      v198 = v46;
      p_m_currentSection = &accessor.m_currentSection;
      goto LABEL_102;
    }
LABEL_119:
    if ( v7->m_exactInternalVertexHandling.m_bool )
    {
      v206.m_real = query.m_quad;
      v132 = hkaiLineOfSightUtil::_checkAgainstNearbyBoundaries(
               &start,
               &end,
               (hkVector4f *)faceIndex,
               &radius,
               &accessor,
               v7,
               m_startFaceKey,
               &v206);
      hkaiGeneralAccessor::setSection(&accessor, v39);
      if ( v132 != RESULT_IN_PROGRESS && v206.m_real.m128_f32[0] < m_real.m128_f32[0] )
      {
        v43 = v132;
        m_real = v206.m_real;
        if ( (_BYTE)retaddr )
          goto LABEL_71;
      }
    }
    v87 = m_startFaceKey >> 22;
    if ( (float)((float)(m_real.m128_f32[0] * v42.m128_f32[0]) + v29.m128_f32[0]) <= v207.m128_f32[0] )
    {
      v87 = section + 1;
      if ( section < v7->m_maxNumberOfIterations )
      {
        if ( hkaiLineOfSightUtil::LineOfSightOutput::canAddEdge(v6) && v44 != -1 )
        {
          if ( v6->m_visitedEdgesOut.m_size == (v6->m_visitedEdgesOut.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v6, 4);
          v6->m_visitedEdgesOut.m_data[v6->m_visitedEdgesOut.m_size++] = v44;
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
    v29 = _mm_add_ps(v29, _mm_mul_ps(m_real, v42));
    if ( hkaiLineOfSightUtil::LineOfSightOutput::canAddDistance(v6) )
    {
      if ( v6->m_distancesOut.m_size == (v6->m_distancesOut.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v6->m_distancesOut, 4);
      LODWORD(v6->m_distancesOut.m_data[v6->m_distancesOut.m_size++]) = v29.m128_i32[0];
    }
    v88 = _mm_sub_ps(v22, v41);
    v89 = _mm_add_ps(_mm_mul_ps(v88, m_real), v41);
    if ( hkaiLineOfSightUtil::LineOfSightOutput::canAddPoint(v6) )
    {
      if ( v6->m_pointsOut.m_size == (v6->m_pointsOut.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v6->m_pointsOut, 16);
      v6->m_pointsOut.m_data[v6->m_pointsOut.m_size++].m_quad = v89;
    }
    if ( v43 == 3 )
    {
      v78 = v7->m_costModifier == 0i64;
      m_startFaceKey = HIDWORD(accessor.m_sectionInfo);
      LODWORD(accessor.m_accessor) = accessor.m_sectionInfo;
      if ( !v78 || v7->m_edgeFilter )
      {
        v175[0] = accessor.m_currentSection;
        v195 = v199;
        v175[1] = *(&accessor.m_currentSection + 1);
        m_sectionInfo = (__int64)accessor.m_sectionInfo;
        v177 = v164;
        v192 = v196;
        v193 = v175;
        v194 = v198;
      }
      v38 = *(__m128 *)_xmm;
      if ( v7->m_isWallClimbing.m_bool )
      {
        hkaiGeneralAccessor::setSection(&accessor, HIDWORD(accessor.m_sectionInfo) >> 22);
        from.m_quad = *(__m128 *)faceIndex;
        v90 = _mm_mul_ps(v88, v88);
        v91 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v90, v90, 85), _mm_shuffle_ps(v90, v90, 0)),
                _mm_shuffle_ps(v90, v90, 170));
        v92 = _mm_rsqrt_ps(v91);
        v93 = _mm_mul_ps(
                v88,
                _mm_andnot_ps(
                  _mm_cmple_ps(v91, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v92, v91), v92)),
                    _mm_mul_ps(v92, *(__m128 *)_xmm))));
        hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
          &v218,
          (hkSimdFloat32 *)accessor.m_accessor,
          (hkaiNavMeshInstance *)(m_startFaceKey & 0x3FFFFF),
          (__m128 *)faceIndex);
        v94 = *(__m128 *)faceIndex;
        v179 = 1065353048;
        v95 = _mm_mul_ps(*(__m128 *)faceIndex, from.m_quad);
        v96 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v95, v95, 85), _mm_shuffle_ps(v95, v95, 0)),
                _mm_shuffle_ps(v95, v95, 170));
        v97 = _mm_shuffle_ps((__m128)0x3F7FFF58u, (__m128)0x3F7FFF58u, 0).m128_f32[0];
        if ( v96.m128_f32[0] > v97 )
        {
          v98 = qi.m_vec.m_quad;
          goto LABEL_137;
        }
        if ( v96.m128_f32[0] >= (float)(0.0 - v97) )
        {
          v178 = -1082147209;
          v133 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v96), (__m128)xmmword_141A711B0);
          v134 = _mm_rsqrt_ps(v133);
          v135 = _mm_andnot_ps(
                   _mm_cmple_ps(v133, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v134, v133), v134)),
                     _mm_mul_ps(v134, *(__m128 *)_xmm)));
          v136 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)faceIndex, *(__m128 *)faceIndex, 201), from.m_quad),
                   _mm_mul_ps(_mm_shuffle_ps(from.m_quad, from.m_quad, 201), *(__m128 *)faceIndex));
          v137 = _mm_shuffle_ps(v136, v136, 201);
          v138 = _mm_mul_ps(v135, (__m128)xmmword_141A711B0);
          if ( v96.m128_f32[0] < _mm_shuffle_ps((__m128)0xBF7FBE77, (__m128)0xBF7FBE77, 0).m128_f32[0] )
          {
            v139 = _mm_mul_ps(v137, v137);
            v140 = _mm_sub_ps(v133, v96);
            v141 = _mm_rsqrt_ps(v140);
            v142 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v139, v139, 85), _mm_shuffle_ps(v139, v139, 0)),
                     _mm_shuffle_ps(v139, v139, 170));
            v143 = _mm_rsqrt_ps(v142);
            v138 = _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_andnot_ps(
                         _mm_cmple_ps(v140, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v141, v140), v141)),
                           _mm_mul_ps(v141, *(__m128 *)_xmm))),
                       v140),
                     _mm_andnot_ps(
                       _mm_cmple_ps(v142, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v143, v142), v143)),
                         _mm_mul_ps(v143, *(__m128 *)_xmm))));
          }
          v144 = _mm_mul_ps(v137, v138);
          v98 = _mm_shuffle_ps(v144, _mm_unpackhi_ps(v144, _mm_mul_ps(v135, v133)), 196);
LABEL_137:
          v183.m_vec.m_quad = v98;
        }
        else
        {
          hkQuaternionf::setFlippedRotation(&v183, &from);
          v94 = *(__m128 *)faceIndex;
          v98 = v183.m_vec.m_quad;
        }
        v145 = _mm_mul_ps(v98, v93);
        v146 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v93, v93, 201), v98),
                 _mm_mul_ps(_mm_shuffle_ps(v98, v98, 201), v93));
        v147 = _mm_shuffle_ps(v98, v98, 255);
        v148 = _mm_mul_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v145, v145, 85), _mm_shuffle_ps(v145, v145, 0)),
                   _mm_shuffle_ps(v145, v145, 170)),
                 v98);
        v38 = *(__m128 *)_xmm;
        v149 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v147, v147), (__m128)xmmword_141A711B0), v93);
        v15 = (__m128)_xmm;
        v150 = _mm_add_ps(_mm_add_ps(v148, v149), _mm_mul_ps(_mm_shuffle_ps(v146, v146, 201), v147));
        v151 = _mm_add_ps(v150, v150);
        v152 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v151, v151, 201), v94),
                 _mm_mul_ps(_mm_shuffle_ps(v94, v94, 201), v151));
        v153 = _mm_shuffle_ps(v152, v152, 201);
        v154 = _mm_mul_ps(v153, v153);
        v155 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v154, v154, 85), _mm_shuffle_ps(v154, v154, 0)),
                 _mm_shuffle_ps(v154, v154, 170));
        v156 = _mm_rsqrt_ps(v155);
        v157 = _mm_mul_ps(
                 v153,
                 _mm_andnot_ps(
                   _mm_cmple_ps(v155, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v156, v155), v156)),
                     _mm_mul_ps(v156, *(__m128 *)_xmm))));
        v158 = _mm_mul_ps(v157, v22);
        v25 = _mm_shuffle_ps(
                v157,
                _mm_unpackhi_ps(
                  v157,
                  _mm_sub_ps(
                    (__m128)0i64,
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v158, v158, 85), _mm_shuffle_ps(v158, v158, 0)),
                      _mm_shuffle_ps(v158, v158, 170)))),
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
    v6->m_visitedEdgesOut.m_size = 0;
  v159 = v169;
  v6->m_finalFaceKey = m_startFaceKey;
  v160 = (char *)p;
  LODWORD(v6->m_accumulatedDistance) = v29.m128_i32[0];
  v6->m_finalPoint.m_quad = v89;
  v78 = v160 == v168;
  v6->m_numIterationsOut = v87;
  if ( v78 )
    v159 = 0;
  v169 = v159;
  v161 = (4 * v172 + 127) & 0xFFFFFF80;
  v162 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v163 = (v161 + 15) & 0xFFFFFFF0;
  if ( v161 > v162->m_slabSize || &v160[v163] != v162->m_cur || v162->m_firstNonLifoEnd == v160 )
    hkLifoAllocator::slowBlockFree(v162, v160, v163);
  else
    v162->m_cur = v160;
  v169 = 0;
  if ( v170 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v168, 4 * v170);
  return v43;
}

