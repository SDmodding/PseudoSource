// File Line: 21
// RVA: 0xC52EE0
hkBool *__fastcall hkaKeyFrameHierarchyUtility::ControlData::isValid(hkaKeyFrameHierarchyUtility::ControlData *this, hkBool *result)
{
  float v2; // xmm2_4
  bool v3; // al
  float v4; // xmm2_4
  char v5; // al
  float v6; // xmm2_4
  char v7; // al
  float v8; // xmm2_4
  char v9; // al
  float v10; // xmm2_4
  char v11; // al
  bool v12; // al
  bool v13; // al
  bool v14; // al
  bool v15; // al
  bool v16; // al
  bool v17; // al
  hkBool *v18; // rax

  v2 = this->m_hierarchyGain;
  result->m_bool = 1;
  v3 = v2 >= 0.0 && v2 <= 1.0;
  result->m_bool = v3;
  v5 = 0;
  if ( v3 )
  {
    v4 = this->m_velocityDamping;
    if ( v4 >= 0.0 && v4 <= 1.0 )
      v5 = 1;
  }
  result->m_bool = v5;
  v7 = 0;
  if ( v5 )
  {
    v6 = this->m_accelerationGain;
    if ( v6 >= 0.0 && v6 <= 1.0 )
      v7 = 1;
  }
  result->m_bool = v7;
  v9 = 0;
  if ( v7 )
  {
    v8 = this->m_velocityGain;
    if ( v8 >= 0.0 && v8 <= 1.0 )
      v9 = 1;
  }
  result->m_bool = v9;
  v11 = 0;
  if ( v9 )
  {
    v10 = this->m_positionGain;
    if ( v10 >= 0.0 && v10 <= 1.0 )
      v11 = 1;
  }
  result->m_bool = v11;
  v12 = v11 && this->m_positionMaxLinearVelocity >= 0.0;
  result->m_bool = v12;
  v13 = v12 && this->m_positionMaxAngularVelocity >= 0.0;
  result->m_bool = v13;
  v14 = v13 && this->m_snapGain >= 0.0;
  result->m_bool = v14;
  v15 = v14 && this->m_snapMaxLinearVelocity >= 0.0;
  result->m_bool = v15;
  v16 = v15 && this->m_snapMaxAngularVelocity >= 0.0;
  result->m_bool = v16;
  v17 = v16 && this->m_snapMaxLinearDistance >= 0.0;
  result->m_bool = v17;
  if ( v17 && this->m_snapMaxAngularDistance >= 0.0 )
  {
    result->m_bool = 1;
    v18 = result;
  }
  else
  {
    result->m_bool = 0;
    v18 = result;
  }
  return v18;
}

// File Line: 71
// RVA: 0xC53000
void __fastcall hkaKeyFrameHierarchyUtility::initialize(hkpRigidBody *rb, hkaKeyFrameHierarchyUtility::WorkElem *workElem)
{
  workElem->m_prevLinearVelocity = rb->m_motion.m_linearVelocity;
  workElem->m_prevAngularVelocity = rb->m_motion.m_angularVelocity;
  workElem->m_prevPosition = rb->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1;
  workElem->m_prevRotation = rb->m_motion.m_motionState.m_sweptTransform.m_rotation1;
}

// File Line: 79
// RVA: 0xC53040
void __fastcall hkaKeyFrameHierarchyUtility::initialize(hkaKeyFrameHierarchyUtility::BodyData *bodies, hkaKeyFrameHierarchyUtility::WorkElem *internalReferencePose)
{
  int v2; // ebx
  hkaKeyFrameHierarchyUtility::WorkElem *v3; // rbp
  hkaKeyFrameHierarchyUtility::BodyData *v4; // rsi
  __int64 v5; // rdi

  v2 = 0;
  v3 = internalReferencePose;
  v4 = bodies;
  if ( bodies->m_numRigidBodies > 0 )
  {
    v5 = 0i64;
    do
    {
      hkaKeyFrameHierarchyUtility::initialize(v4->m_rigidBodies[v5], &v3[(signed __int64)v2++]);
      ++v5;
    }
    while ( v2 < v4->m_numRigidBodies );
  }
}

// File Line: 91
// RVA: 0xC539C0
void __fastcall calcComPoseUsingHierarchy(hkQsTransformf *desiredPoseLocalSpace, hkaKeyFrameHierarchyUtility::BodyData *bodydata, hkaKeyFrameHierarchyUtility::ControlData *controlPalette, hkQsTransformf *worldFromPose, MatrixCache *mc)
{
  int v5; // esi
  hkaKeyFrameHierarchyUtility::BodyData *v6; // rdi
  hkQsTransformf *v7; // r15
  __int64 v8; // r12
  __int64 v9; // r14
  hkQuaternionf *v10; // rbx
  __int64 v11; // rbp
  __int64 v12; // rdx
  hkQsTransformf *v13; // rax
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm6
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm2
  __m128 v20; // xmm3
  __m128 v21; // xmm9
  __m128 v22; // xmm5
  __m128 v23; // xmm4
  __m128 v24; // xmm6
  __m128 v25; // xmm3
  __m128 v26; // xmm6
  __m128 v27; // xmm6
  __m128 v28; // xmm0
  int *v29; // rax
  __m128 v30; // xmm1
  const float *v31; // rcx
  __m128 v32; // xmm1
  __m128 v33; // xmm0
  __m128 *v34; // rdx
  __m128 v35; // xmm6
  __m128 v36; // xmm1
  __m128 v37; // xmm7
  __m128 v38; // xmm5
  __m128 v39; // xmm4
  __m128 v40; // xmm2
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm2
  __m128 v44; // xmm2
  __m128 v45; // xmm4
  __m128 v46; // xmm6
  __m128 v47; // xmm3
  __m128 v48; // xmm4
  __m128 v49; // xmm4
  __m128 v50; // xmm5
  __m128 v51; // xmm2
  __m128 v52; // xmm1
  __m128 v53; // xmm4
  __m128 v54; // xmm3
  hkSimdFloat32 t; // [rsp+20h] [rbp-C8h]
  hkQuaternionf q0; // [rsp+30h] [rbp-B8h]
  __m128 v57; // [rsp+40h] [rbp-A8h]
  hkQuaternionf q1; // [rsp+50h] [rbp-98h]
  __m128 v59; // [rsp+60h] [rbp-88h]
  hkaKeyFrameHierarchyUtility::ControlData *v60; // [rsp+100h] [rbp+18h]
  hkQsTransformf *v61; // [rsp+108h] [rbp+20h]

  v61 = worldFromPose;
  v60 = controlPalette;
  v5 = 0;
  v6 = bodydata;
  v7 = desiredPoseLocalSpace;
  if ( bodydata->m_numRigidBodies > 0 )
  {
    v8 = 0i64;
    v9 = 0i64;
    v10 = &mc->m_zeroHierarchyGainPose.m_rotation;
    v11 = 0i64;
    do
    {
      v12 = v6->m_parentIndices[v11];
      if ( (signed int)v12 < 0 )
        v13 = worldFromPose;
      else
        v13 = &mc[v12].m_zeroHierarchyGainPose;
      v14 = v13->m_rotation.m_vec.m_quad;
      v15 = _mm_mul_ps(v7->m_translation.m_quad, v14);
      v16 = _mm_shuffle_ps(v13->m_rotation.m_vec.m_quad, v14, 255);
      v17 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v7->m_translation.m_quad, v7->m_translation.m_quad, 201), v14),
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v7->m_translation.m_quad));
      v18 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                    _mm_shuffle_ps(v15, v15, 170)),
                  v14),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v16, v16), (__m128)xmmword_141A711B0), v7->m_translation.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v16));
      v10[-1].m_vec.m_quad = _mm_add_ps(_mm_add_ps(v18, v18), v13->m_translation.m_quad);
      v19 = v13->m_rotation.m_vec.m_quad;
      v20 = v7->m_rotation.m_vec.m_quad;
      v21 = v10[-1].m_vec.m_quad;
      v22 = _mm_shuffle_ps(v7->m_rotation.m_vec.m_quad, v7->m_rotation.m_vec.m_quad, 255);
      v23 = _mm_shuffle_ps(v13->m_rotation.m_vec.m_quad, v13->m_rotation.m_vec.m_quad, 255);
      v24 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v19), _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v20));
      v25 = _mm_mul_ps(v20, v19);
      v26 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v24, v24, 201), _mm_mul_ps(v7->m_rotation.m_vec.m_quad, v23)),
              _mm_mul_ps(v13->m_rotation.m_vec.m_quad, v22));
      v27 = _mm_shuffle_ps(
              v26,
              _mm_unpackhi_ps(
                v26,
                _mm_sub_ps(
                  _mm_mul_ps(v22, v23),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                    _mm_shuffle_ps(v25, v25, 170)))),
              196);
      *v10 = (hkQuaternionf)v27;
      v28 = v13->m_scale.m_quad;
      q0.m_vec.m_quad = v27;
      v10[1].m_vec.m_quad = _mm_mul_ps(v28, v7->m_scale.m_quad);
      v29 = v6->m_controlDataIndices;
      if ( !v29 || (LODWORD(v29) = v29[v9], (_DWORD)v29 != -1) )
      {
        v30 = (__m128)LODWORD(controlPalette[(signed int)v29].m_hierarchyGain);
        v31 = v6->m_boneWeights;
        v32 = _mm_shuffle_ps(v30, v30, 0);
        t.m_real = v32;
        if ( v31 )
        {
          v33 = (__m128)LODWORD(v31[v5]);
          v32 = _mm_mul_ps(v32, _mm_shuffle_ps(v33, v33, 0));
          t.m_real = v32;
        }
        if ( v32.m128_f32[0] > 0.0 && (signed int)v12 >= 0 )
        {
          v34 = (__m128 *)v6->m_rigidBodies[v12];
          v35 = v34[30];
          v36 = _mm_mul_ps(v7->m_translation.m_quad, v35);
          v37 = _mm_shuffle_ps(v34[30], v35, 255);
          v38 = _mm_shuffle_ps(v35, v35, 201);
          v39 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v7->m_translation.m_quad, v7->m_translation.m_quad, 201), v35),
                  _mm_mul_ps(v7->m_translation.m_quad, v38));
          v40 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                  _mm_shuffle_ps(v36, v36, 170));
          v41 = v34[30];
          v42 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(v40, v35),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v37, v37), (__m128)xmmword_141A711B0), v7->m_translation.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v37));
          v43 = _mm_add_ps(_mm_add_ps(v42, v42), v34[26]);
          v59 = _mm_mul_ps(query.m_quad, v7->m_scale.m_quad);
          v57 = v43;
          v44 = v7->m_rotation.m_vec.m_quad;
          v45 = _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), v35);
          v46 = _mm_mul_ps(v35, v44);
          v47 = _mm_shuffle_ps(v7->m_rotation.m_vec.m_quad, v7->m_rotation.m_vec.m_quad, 255);
          v48 = _mm_sub_ps(v45, _mm_mul_ps(v38, v44));
          v49 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v48, v48, 201), _mm_mul_ps(v7->m_rotation.m_vec.m_quad, v37)),
                  _mm_mul_ps(v41, v47));
          q1.m_vec.m_quad = _mm_shuffle_ps(
                              v49,
                              _mm_unpackhi_ps(
                                v49,
                                _mm_sub_ps(
                                  _mm_mul_ps(v47, v37),
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
                                    _mm_shuffle_ps(v46, v46, 170)))),
                              196);
          hkQuaternionf::setSlerp(&q0, &q0, &q1, &t);
          worldFromPose = v61;
          controlPalette = v60;
          v27 = q0.m_vec.m_quad;
          v21 = _mm_add_ps(v21, _mm_mul_ps(_mm_sub_ps(v57, v21), t.m_real));
        }
        v50 = _mm_shuffle_ps(v27, v27, 255);
        v51 = v6->m_rigidBodies[v8]->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad;
        v52 = _mm_mul_ps(v27, v51);
        v53 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v27), _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v51));
        v10[-3] = (hkQuaternionf)v27;
        v54 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                      _mm_shuffle_ps(v52, v52, 170)),
                    v27),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v50, v50), (__m128)xmmword_141A711B0), v51)),
                _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v50));
        v10[-4].m_vec.m_quad = _mm_add_ps(_mm_add_ps(v54, v54), v21);
        v10[-2].m_vec = (hkVector4f)aabbOut.m_quad;
      }
      ++v5;
      ++v11;
      ++v9;
      ++v7;
      ++v8;
      v10 += 6;
    }
    while ( v5 < v6->m_numRigidBodies );
  }
};
        v10[-2].m_vec = (hkVector4f)aabbOut.m_quad;
      }
      ++v5;
      ++v11;
      ++v9;
     

// File Line: 169
// RVA: 0xC53DD0
void __fastcall clipVector(hkSimdFloat32 *maxLen, hkVector4f *vec)
{
  __m128 v2; // xmm1
  __m128 v3; // xmm5
  __m128 v4; // xmm6
  __m128 v5; // xmm1

  v2 = _mm_mul_ps(vec->m_quad, vec->m_quad);
  v3 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v2, v2, 85), _mm_shuffle_ps(v2, v2, 0)), _mm_shuffle_ps(v2, v2, 170));
  v4 = _mm_cmpltps(_mm_mul_ps(maxLen->m_real, maxLen->m_real), v3);
  v5 = _mm_rsqrt_ps(v3);
  vec->m_quad = _mm_or_ps(
                  _mm_and_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmpleps(v3, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v5, v3), v5)),
                            _mm_mul_ps(*(__m128 *)_xmm, v5))),
                        maxLen->m_real),
                      vec->m_quad),
                    v4),
                  _mm_andnot_ps(v4, vec->m_quad));
}

// File Line: 189
// RVA: 0xC53E70
hkSimdFloat32 *__fastcall clipSnapVector(hkSimdFloat32 *result, hkSimdFloat32 *snapMaxVelocity, hkSimdFloat32 *maxDist, hkVector4f *vectorIn)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm5
  __m128 v6; // xmm6
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm7
  __m128 v12; // xmm6

  v4 = _mm_mul_ps(vectorIn->m_quad, vectorIn->m_quad);
  v5 = _mm_mul_ps(snapMaxVelocity->m_real, snapMaxVelocity->m_real);
  v6 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)), _mm_shuffle_ps(v4, v4, 170));
  v7 = _mm_rcp_ps(v5);
  result->m_real = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v7, v5)), v7), v6);
  if ( v6.m128_f32[0] > v5.m128_f32[0] )
  {
    v8 = _mm_rcp_ps(v6);
    v9 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v8, v6)), v8), v5);
    v10 = _mm_rsqrt_ps(v9);
    v11 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v8, v6)), v8);
    v12 = _mm_cmpltps(v6, _mm_mul_ps(maxDist->m_real, maxDist->m_real));
    vectorIn->m_quad = _mm_or_ps(
                         _mm_andnot_ps(
                           v12,
                           _mm_mul_ps(
                             vectorIn->m_quad,
                             _mm_mul_ps(v11, _mm_mul_ps(maxDist->m_real, snapMaxVelocity->m_real)))),
                         _mm_and_ps(
                           v12,
                           _mm_mul_ps(
                             _mm_andnot_ps(
                               _mm_cmpleps(v9, (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_mul_ps(
                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                                   _mm_mul_ps(*(__m128 *)_xmm, v10)),
                                 v9)),
                             vectorIn->m_quad)));
  }
  return result;
}

// File Line: 220
// RVA: 0xC530B0
void __fastcall hkaKeyFrameHierarchyUtility::applyKeyFrame(float deltaTime, hkaKeyFrameHierarchyUtility::KeyFrameData *pose, hkaKeyFrameHierarchyUtility::BodyData *bodydata, hkaKeyFrameHierarchyUtility::ControlData *controlPalette, hkaKeyFrameHierarchyUtility::Output *output)
{
  int v5; // ebx
  hkaKeyFrameHierarchyUtility::ControlData *v6; // rsi
  hkaKeyFrameHierarchyUtility::BodyData *v7; // r14
  hkaKeyFrameHierarchyUtility::KeyFrameData *v8; // rbp
  hkLifoAllocator *v9; // rax
  MatrixCache *mc; // rdi
  int v11; // ebx
  char *v12; // rcx
  int v13; // esi
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm9
  __m128 v17; // xmm2
  __int64 v18; // r15
  __int64 v19; // r13
  __m128 *v20; // rbp
  __int64 v21; // r12
  int *v22; // rax
  float v23; // xmm11_4
  const float *v24; // rcx
  hkpEntity *v25; // rdi
  unsigned int *v26; // rbx
  __m128 v27; // xmm12
  __m128 v28; // xmm13
  __m128 v29; // xmm14
  __m128 v30; // xmm10
  __m128 v31; // xmm0
  __m128 v32; // xmm0
  __m128 v33; // xmm0
  __int64 v34; // rax
  __m128 v35; // xmm3
  __m128 v36; // xmm0
  __m128 v37; // xmm1
  __m128 v38; // xmm7
  __m128 v39; // xmm1
  __m128 v40; // xmm0
  signed int v41; // eax
  __m128 v42; // xmm8
  __m128 v43; // xmm8
  __m128 v44; // xmm7
  __m128 v45; // xmm6
  __m128 v46; // xmm1
  __m128 v47; // xmm3
  __m128 v48; // xmm5
  __m128 v49; // xmm4
  __m128 v50; // xmm2
  __m128 v51; // xmm4
  __m128 v52; // xmm8
  __m128 v53; // xmm3
  __m128 v54; // xmm1
  __m128 v55; // xmm5
  __m128 v56; // xmm4
  __m128 v57; // xmm6
  __m128 v58; // xmm4
  __m128 v59; // xmm6
  __m128 v60; // xmm5
  __m128 v61; // xmm6
  __m128 v62; // xmm6
  __m128 v63; // xmm9
  __m128 v64; // xmm1
  __m128 v65; // xmm7
  __m128 v66; // xmm4
  __m128 v67; // xmm3
  __m128 v68; // xmm1
  __m128 v69; // xmm0
  __m128 v70; // xmm7
  __m128 v71; // xmm2
  __m128 v72; // xmm3
  __int64 v73; // rax
  __m128 v74; // xmm1
  __m128 v75; // xmm9
  __m128 v76; // xmm4
  __m128 v77; // xmm3
  __m128 v78; // xmm5
  __m128 v79; // xmm0
  __m128 v80; // xmm8
  __m128 v81; // xmm3
  __m128 v82; // xmm9
  __m128 v83; // xmm4
  __m128 v84; // xmm1
  __m128 v85; // xmm0
  __m128 v86; // xmm3
  __m128 v87; // xmm7
  __m128 v88; // xmm4
  __m128 v89; // xmm0
  __m128 v90; // xmm1
  __m128 v91; // xmm0
  __m128 v92; // xmm12
  __m128 v93; // xmm12
  __m128 v94; // xmm6
  __m128 v95; // xmm7
  __m128 v96; // xmm1
  __m128 v97; // xmm3
  __m128 v98; // xmm5
  __m128 v99; // xmm1
  __m128 v100; // xmm12
  __m128 v101; // xmm3
  __m128 v102; // xmm8
  __m128 v103; // xmm4
  __m128 v104; // xmm0
  __m128 v105; // xmm3
  __m128 v106; // xmm7
  __m128 v107; // xmm4
  __m128 v108; // xmm0
  __m128 v109; // xmm5
  __m128 v110; // xmm4
  __m128 v111; // xmm5
  __m128 v112; // xmm1
  __m128 v113; // xmm6
  float v114; // xmm9_4
  __m128 v115; // xmm3
  __m128 v116; // xmm2
  __m128 v117; // xmm1
  __m128 v118; // xmm0
  __m128 v119; // xmm6
  hkLifoAllocator *v120; // rax
  int v121; // er8
  int v122; // [rsp+30h] [rbp-168h]
  MatrixCache *v123; // [rsp+38h] [rbp-160h]
  __m128 v124; // [rsp+40h] [rbp-158h]
  __m128 v125; // [rsp+50h] [rbp-148h]
  __m128 v126; // [rsp+60h] [rbp-138h]
  __m128 v127; // [rsp+70h] [rbp-128h]
  __int64 v128; // [rsp+80h] [rbp-118h]
  __m128 v129; // [rsp+90h] [rbp-108h]
  __m128 v130; // [rsp+A0h] [rbp-F8h]
  hkaKeyFrameHierarchyUtility::KeyFrameData *v131; // [rsp+1A8h] [rbp+10h]
  signed int v132; // [rsp+1B0h] [rbp+18h]
  hkaKeyFrameHierarchyUtility::ControlData *v133; // [rsp+1B8h] [rbp+20h]

  v133 = controlPalette;
  v131 = pose;
  v5 = bodydata->m_numRigidBodies;
  v6 = controlPalette;
  v7 = bodydata;
  v8 = pose;
  v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  mc = (MatrixCache *)v9->m_cur;
  v123 = mc;
  v11 = (96 * v5 + 127) & 0xFFFFFF80;
  v122 = v11;
  v12 = (char *)mc + v11;
  if ( v11 > v9->m_slabSize || v12 > v9->m_end )
  {
    mc = (MatrixCache *)hkLifoAllocator::allocateFromNewSlab(v9, v11);
    v123 = mc;
  }
  else
  {
    v9->m_cur = v12;
  }
  calcComPoseUsingHierarchy(v8->m_desiredPoseLocalSpace, v7, v6, &v8->m_worldFromRoot, mc);
  v13 = 0;
  v14 = _mm_shuffle_ps((__m128)LODWORD(deltaTime), (__m128)LODWORD(deltaTime), 0);
  v15 = _mm_rcp_ps(v14);
  v16 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v14, v15)), v15);
  v124 = v16;
  if ( v7->m_numRigidBodies > 0 )
  {
    v17 = 0i64;
    v18 = 0i64;
    v19 = 0i64;
    v20 = &mc->m_zeroHierarchyGainPose.m_rotation.m_vec.m_quad;
    v21 = 0i64;
    do
    {
      v22 = v7->m_controlDataIndices;
      if ( v22 )
        LODWORD(v22) = v22[v21];
      v23 = v17.m128_f32[0];
      if ( (_DWORD)v22 != -1 )
      {
        v24 = v7->m_boneWeights;
        v25 = (hkpEntity *)&v7->m_rigidBodies[v19]->vfptr;
        v26 = (unsigned int *)&v133[(signed int)v22];
        v27 = _mm_shuffle_ps((__m128)v26[2], (__m128)v26[2], 0);
        v28 = _mm_shuffle_ps((__m128)v26[3], (__m128)v26[3], 0);
        v29 = _mm_shuffle_ps((__m128)v26[4], (__m128)v26[4], 0);
        v30 = _mm_shuffle_ps((__m128)v26[7], (__m128)v26[7], 0);
        if ( v24 )
        {
          v31 = (__m128)LODWORD(v24[v13]);
          v32 = _mm_shuffle_ps(v31, v31, 0);
          v27 = _mm_mul_ps(v27, v32);
          v28 = _mm_mul_ps(v28, v32);
          v29 = _mm_mul_ps(v29, v32);
          v30 = _mm_mul_ps(v30, v32);
        }
        v33 = _mm_shuffle_ps((__m128)v26[1], (__m128)v26[1], 0);
        v34 = (__int64)v131->m_internalReferencePose;
        v128 = v34;
        v35 = _mm_sub_ps(query.m_quad, v33);
        v36 = v20[-4];
        v37 = _mm_sub_ps(v36, *(__m128 *)(v18 + v34));
        v38 = _mm_sub_ps(v20[-4], v25->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
        *(__m128 *)(v18 + v34) = v36;
        v127 = v35;
        v39 = _mm_mul_ps(v37, v16);
        v40 = _mm_sub_ps(v39, *(__m128 *)(v18 + v34 + 32));
        *(__m128 *)(v18 + v34 + 32) = v39;
        v41 = 0;
        v42 = _mm_add_ps(_mm_mul_ps(v35, v25->m_motion.m_linearVelocity.m_quad), _mm_mul_ps(v40, v27));
        v43 = _mm_add_ps(v42, _mm_mul_ps(_mm_sub_ps(v39, v42), v28));
        v125 = v43;
        v44 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v38, v16), v43), v29);
        v45 = _mm_shuffle_ps((__m128)v26[5], (__m128)v26[5], 0);
        v46 = _mm_mul_ps(v44, v44);
        v129 = *(__m128 *)_xmm;
        v47 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
                _mm_shuffle_ps(v46, v46, 170));
        v48 = _mm_cmpltps(_mm_mul_ps(v45, v45), v47);
        v49 = _mm_cmpleps(v47, v17);
        v50 = _mm_rsqrt_ps(v47);
        v51 = _mm_andnot_ps(
                v49,
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v47), v50)),
                  _mm_mul_ps(*(__m128 *)_xmm, v50)));
        if ( v30.m128_f32[0] != 0.0 )
          v41 = 1;
        v132 = v41;
        v52 = _mm_add_ps(
                v43,
                _mm_or_ps(_mm_and_ps(_mm_mul_ps(_mm_mul_ps(v51, v45), v44), v48), _mm_andnot_ps(v48, v44)));
        v125 = v52;
        if ( v41 )
        {
          v53 = v25->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad;
          v54 = _mm_mul_ps(*v20, v53);
          v55 = _mm_shuffle_ps(*v20, *v20, 255);
          v56 = _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(v25->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad, v53, 201),
                    *v20),
                  _mm_mul_ps(_mm_shuffle_ps(*v20, *v20, 201), v53));
          v57 = _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), _mm_shuffle_ps(v54, v54, 0)),
                    _mm_shuffle_ps(v54, v54, 170)),
                  *v20);
          v58 = _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v55);
          v130 = _mm_shuffle_ps((__m128)v26[8], (__m128)v26[8], 0);
          v59 = _mm_add_ps(v57, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v55, v55), (__m128)xmmword_141A711B0), v53));
          v60 = _mm_mul_ps(v130, v130);
          v61 = _mm_add_ps(v59, v58);
          v62 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_mul_ps(
                      _mm_sub_ps(
                        _mm_add_ps(_mm_add_ps(v61, v61), v20[-1]),
                        v25->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad),
                      v16),
                    v52),
                  v30);
          v63 = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v26[10], (__m128)v26[10], 0), v124), v30);
          v64 = _mm_mul_ps(v62, v62);
          v65 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
                  _mm_shuffle_ps(v64, v64, 170));
          v64.m128_i32[0] = (unsigned __int128)_mm_rcp_ps(v60);
          v23 = (float)((float)(2.0 - (float)(v64.m128_f32[0] * v60.m128_f32[0])) * v64.m128_f32[0]) * v65.m128_f32[0];
          if ( v65.m128_f32[0] > v60.m128_f32[0] )
          {
            v66 = _mm_rcp_ps(v65);
            v67 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v66, v65)), v66), v60);
            v68 = _mm_rsqrt_ps(v67);
            v69 = _mm_mul_ps(v66, v65);
            v70 = _mm_cmpltps(v65, _mm_mul_ps(v63, v63));
            v62 = _mm_or_ps(
                    _mm_andnot_ps(
                      v70,
                      _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v69), v66), _mm_mul_ps(v130, v63)), v62)),
                    _mm_and_ps(
                      v70,
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmpleps(v67, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v68, v67), v68)),
                              _mm_mul_ps(v129, v68)),
                            v67)),
                        v62)));
          }
          v125 = _mm_add_ps(v52, v62);
        }
        hkpEntity::activate(v25);
        v25->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v25->m_motion.vfptr, (unsigned int)&v125);
        v71 = v20[-3];
        v72 = v25->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
        v73 = v128;
        v74 = _mm_mul_ps(
                _mm_shuffle_ps(
                  v25->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
                  v25->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
                  255),
                v71);
        v75 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v71, v71, 201), v72), _mm_mul_ps(_mm_shuffle_ps(v72, v72, 201), v71));
        v76 = _mm_shuffle_ps(v20[-3], v71, 201);
        v77 = _mm_mul_ps(v72, v71);
        v78 = _mm_shuffle_ps(v20[-3], v71, 255);
        v79 = _mm_mul_ps(v25->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad, v78);
        v80 = _mm_add_ps(_mm_shuffle_ps(v77, v77, 78), v77);
        v81 = *(__m128 *)(v18 + v128 + 16);
        *(__m128 *)(v18 + v128 + 16) = v71;
        v82 = _mm_add_ps(_mm_sub_ps(_mm_shuffle_ps(v75, v75, 201), v79), v74);
        v83 = _mm_sub_ps(_mm_mul_ps(v76, v81), _mm_mul_ps(_mm_shuffle_ps(v81, v81, 201), v71));
        v84 = _mm_mul_ps(_mm_shuffle_ps(v81, v81, 255), v71);
        v85 = _mm_mul_ps(v81, v78);
        v86 = _mm_mul_ps(v81, v71);
        v87 = _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v80, v80, 177), v80), 0x1Fu),
                          0x1Fu),
                _mm_add_ps(v82, v82));
        v16 = v124;
        v88 = _mm_add_ps(_mm_sub_ps(_mm_shuffle_ps(v83, v83, 201), v85), v84);
        v89 = _mm_add_ps(_mm_shuffle_ps(v86, v86, 78), v86);
        v90 = _mm_mul_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v89, v89, 177), v89), 0x1Fu),
                            0x1Fu),
                  _mm_add_ps(v88, v88)),
                v124);
        v91 = _mm_sub_ps(v90, *(__m128 *)(v18 + v73 + 48));
        *(__m128 *)(v18 + v73 + 48) = v90;
        v127 = _mm_mul_ps(v25->m_motion.m_angularVelocity.m_quad, v127);
        v92 = _mm_add_ps(v127, _mm_mul_ps(v91, v27));
        v93 = _mm_add_ps(v92, _mm_mul_ps(_mm_sub_ps(v90, v92), v28));
        v126 = v93;
        v94 = _mm_shuffle_ps((__m128)v26[6], (__m128)v26[6], 0);
        v95 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v87, v124), v93), v29);
        v96 = _mm_mul_ps(v95, v95);
        v97 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v96, v96, 85), _mm_shuffle_ps(v96, v96, 0)),
                _mm_shuffle_ps(v96, v96, 170));
        v98 = _mm_cmpltps(_mm_mul_ps(v94, v94), v97);
        v99 = _mm_rsqrt_ps(v97);
        v100 = _mm_add_ps(
                 v93,
                 _mm_or_ps(
                   _mm_and_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmpleps(v97, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v99, v97), v99)),
                             _mm_mul_ps(v99, v129))),
                         v94),
                       v95),
                     v98),
                   _mm_andnot_ps(v98, v95)));
        v126 = v100;
        if ( v132 )
        {
          v101 = v25->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
          v102 = _mm_shuffle_ps((__m128)v26[9], (__m128)v26[9], 0);
          v103 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(*v20, *v20, 201), v101),
                   _mm_mul_ps(_mm_shuffle_ps(v101, v101, 201), *v20));
          v104 = _mm_mul_ps(_mm_shuffle_ps(*v20, *v20, 255), v101);
          v105 = _mm_mul_ps(v101, *v20);
          v106 = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v26[11], (__m128)v26[11], 0), v124), v30);
          v107 = _mm_add_ps(
                   _mm_sub_ps(_mm_shuffle_ps(v103, v103, 201), v104),
                   _mm_mul_ps(
                     _mm_shuffle_ps(
                       v25->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
                       v25->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
                       255),
                     *v20));
          v108 = _mm_add_ps(_mm_shuffle_ps(v105, v105, 78), v105);
          v109 = _mm_mul_ps(
                   _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v108, v108, 177), v108), 0x1Fu),
                               0x1Fu),
                     _mm_add_ps(v107, v107)),
                   v124);
          v110 = _mm_mul_ps(v102, v102);
          v111 = _mm_mul_ps(_mm_sub_ps(v109, v100), v30);
          v112 = _mm_mul_ps(v111, v111);
          v113 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v112, v112, 85), _mm_shuffle_ps(v112, v112, 0)),
                   _mm_shuffle_ps(v112, v112, 170));
          v112.m128_i32[0] = (unsigned __int128)_mm_rcp_ps(v110);
          v114 = (float)((float)(2.0 - (float)(v112.m128_f32[0] * v110.m128_f32[0])) * v112.m128_f32[0])
               * v113.m128_f32[0];
          if ( v113.m128_f32[0] > v110.m128_f32[0] )
          {
            v115 = _mm_rcp_ps(v113);
            v116 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v115, v113)), v115), v110);
            v117 = _mm_rsqrt_ps(v116);
            v118 = _mm_mul_ps(v115, v113);
            v119 = _mm_cmpltps(v113, _mm_mul_ps(v106, v106));
            v111 = _mm_or_ps(
                     _mm_andnot_ps(
                       v119,
                       _mm_mul_ps(
                         _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v118), v115), _mm_mul_ps(v102, v106)),
                         v111)),
                     _mm_and_ps(
                       _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmpleps(v116, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v116, v117), v117)),
                               _mm_mul_ps(v129, v117)),
                             v116)),
                         v111),
                       v119));
          }
          v23 = v23 + v114;
          v16 = v124;
          v126 = _mm_add_ps(v100, v111);
        }
        hkpEntity::activate(v25);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v25->m_motion.vfptr[9].__first_virtual_table_function__)(
          &v25->m_motion,
          &v126);
        v17 = 0i64;
        if ( output )
          output[v13].m_stressSquared = v23;
      }
      ++v13;
      ++v21;
      ++v19;
      v20 += 6;
      v18 += 64i64;
    }
    while ( v13 < v7->m_numRigidBodies );
    v11 = v122;
    mc = v123;
  }
  v120 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v121 = (v11 + 15) & 0xFFFFFFF0;
  if ( v11 > v120->m_slabSize || (char *)mc + v121 != v120->m_cur || v120->m_firstNonLifoEnd == mc )
    hkLifoAllocator::slowBlockFree(v120, mc, v121);
  else
    v120->m_cur = mc;
}

