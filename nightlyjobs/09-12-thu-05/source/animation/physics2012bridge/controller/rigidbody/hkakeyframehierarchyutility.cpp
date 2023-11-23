// File Line: 21
// RVA: 0xC52EE0
hkBool *__fastcall hkaKeyFrameHierarchyUtility::ControlData::isValid(
        hkaKeyFrameHierarchyUtility::ControlData *this,
        hkBool *result)
{
  float m_hierarchyGain; // xmm2_4
  bool v3; // al
  float m_velocityDamping; // xmm2_4
  char v5; // al
  float m_accelerationGain; // xmm2_4
  char v7; // al
  float m_velocityGain; // xmm2_4
  char v9; // al
  float m_positionGain; // xmm2_4
  char v11; // al
  bool v12; // al
  bool v13; // al
  bool v14; // al
  bool v15; // al
  bool v16; // al
  bool v17; // al

  m_hierarchyGain = this->m_hierarchyGain;
  result->m_bool = 1;
  v3 = m_hierarchyGain >= 0.0 && m_hierarchyGain <= 1.0;
  result->m_bool = v3;
  v5 = 0;
  if ( v3 )
  {
    m_velocityDamping = this->m_velocityDamping;
    if ( m_velocityDamping >= 0.0 && m_velocityDamping <= 1.0 )
      v5 = 1;
  }
  result->m_bool = v5;
  v7 = 0;
  if ( v5 )
  {
    m_accelerationGain = this->m_accelerationGain;
    if ( m_accelerationGain >= 0.0 && m_accelerationGain <= 1.0 )
      v7 = 1;
  }
  result->m_bool = v7;
  v9 = 0;
  if ( v7 )
  {
    m_velocityGain = this->m_velocityGain;
    if ( m_velocityGain >= 0.0 && m_velocityGain <= 1.0 )
      v9 = 1;
  }
  result->m_bool = v9;
  v11 = 0;
  if ( v9 )
  {
    m_positionGain = this->m_positionGain;
    if ( m_positionGain >= 0.0 && m_positionGain <= 1.0 )
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
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 71
// RVA: 0xC53000
void __fastcall hkaKeyFrameHierarchyUtility::initialize(
        hkpRigidBody *rb,
        hkaKeyFrameHierarchyUtility::WorkElem *workElem)
{
  workElem->m_prevLinearVelocity = rb->m_motion.m_linearVelocity;
  workElem->m_prevAngularVelocity = rb->m_motion.m_angularVelocity;
  workElem->m_prevPosition = rb->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1;
  workElem->m_prevRotation = rb->m_motion.m_motionState.m_sweptTransform.m_rotation1;
}

// File Line: 79
// RVA: 0xC53040
void __fastcall hkaKeyFrameHierarchyUtility::initialize(
        hkaKeyFrameHierarchyUtility::BodyData *bodies,
        hkaKeyFrameHierarchyUtility::WorkElem *internalReferencePose)
{
  int v2; // ebx
  __int64 v5; // rdi

  v2 = 0;
  if ( bodies->m_numRigidBodies > 0 )
  {
    v5 = 0i64;
    do
      hkaKeyFrameHierarchyUtility::initialize(bodies->m_rigidBodies[v5++], &internalReferencePose[(__int64)v2++]);
    while ( v2 < bodies->m_numRigidBodies );
  }
}

// File Line: 91
// RVA: 0xC539C0
void __fastcall calcComPoseUsingHierarchy(
        hkQsTransformf *desiredPoseLocalSpace,
        hkaKeyFrameHierarchyUtility::BodyData *bodydata,
        hkaKeyFrameHierarchyUtility::ControlData *controlPalette,
        hkQsTransformf *worldFromPose,
        MatrixCache *mc)
{
  int v5; // esi
  __int64 v8; // r12
  __int64 v9; // r14
  hkQuaternionf *p_m_rotation; // rbx
  __int64 v11; // rbp
  __int64 v12; // rdx
  hkQsTransformf *p_m_zeroHierarchyGainPose; // rax
  __m128 m_quad; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm6
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm2
  hkQuaternionf v20; // xmm3
  __m128 v21; // xmm9
  __m128 v22; // xmm5
  __m128 v23; // xmm4
  __m128 v24; // xmm6
  __m128 v25; // xmm3
  __m128 v26; // xmm6
  __m128 v27; // xmm6
  __m128 v28; // xmm0
  int *m_controlDataIndices; // rax
  __m128 m_hierarchyGain_low; // xmm1
  const float *m_boneWeights; // rcx
  __m128 v32; // xmm1
  __m128 v33; // xmm0
  hkpRigidBody *v34; // rdx
  __m128 v35; // xmm6
  __m128 v36; // xmm1
  __m128 v37; // xmm7
  __m128 v38; // xmm5
  __m128 v39; // xmm4
  __m128 v40; // xmm2
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm2
  hkQuaternionf v44; // xmm2
  __m128 v45; // xmm4
  __m128 v46; // xmm6
  __m128 v47; // xmm3
  __m128 v48; // xmm4
  __m128 v49; // xmm4
  __m128 v50; // xmm5
  hkVector4f v51; // xmm2
  __m128 v52; // xmm1
  __m128 v53; // xmm4
  __m128 v54; // xmm3
  hkSimdFloat32 t; // [rsp+20h] [rbp-C8h] BYREF
  hkQuaternionf q0; // [rsp+30h] [rbp-B8h] BYREF
  __m128 v57; // [rsp+40h] [rbp-A8h]
  hkQuaternionf q1; // [rsp+50h] [rbp-98h] BYREF
  __m128 v59; // [rsp+60h] [rbp-88h]
  hkaKeyFrameHierarchyUtility::ControlData *v60; // [rsp+100h] [rbp+18h]
  hkQsTransformf *v61; // [rsp+108h] [rbp+20h]

  v61 = worldFromPose;
  v60 = controlPalette;
  v5 = 0;
  if ( bodydata->m_numRigidBodies > 0 )
  {
    v8 = 0i64;
    v9 = 0i64;
    p_m_rotation = &mc->m_zeroHierarchyGainPose.m_rotation;
    v11 = 0i64;
    do
    {
      v12 = bodydata->m_parentIndices[v11];
      if ( (int)v12 < 0 )
        p_m_zeroHierarchyGainPose = worldFromPose;
      else
        p_m_zeroHierarchyGainPose = &mc[v12].m_zeroHierarchyGainPose;
      m_quad = p_m_zeroHierarchyGainPose->m_rotation.m_vec.m_quad;
      v15 = _mm_mul_ps(desiredPoseLocalSpace->m_translation.m_quad, m_quad);
      v16 = _mm_shuffle_ps(m_quad, m_quad, 255);
      v17 = _mm_sub_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(
                  desiredPoseLocalSpace->m_translation.m_quad,
                  desiredPoseLocalSpace->m_translation.m_quad,
                  201),
                m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), desiredPoseLocalSpace->m_translation.m_quad));
      v18 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                    _mm_shuffle_ps(v15, v15, 170)),
                  m_quad),
                _mm_mul_ps(
                  _mm_sub_ps(_mm_mul_ps(v16, v16), (__m128)xmmword_141A711B0),
                  desiredPoseLocalSpace->m_translation.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v16));
      p_m_rotation[-1].m_vec.m_quad = _mm_add_ps(_mm_add_ps(v18, v18), p_m_zeroHierarchyGainPose->m_translation.m_quad);
      v19 = p_m_zeroHierarchyGainPose->m_rotation.m_vec.m_quad;
      v20.m_vec.m_quad = (__m128)desiredPoseLocalSpace->m_rotation;
      v21 = p_m_rotation[-1].m_vec.m_quad;
      v22 = _mm_shuffle_ps(v20.m_vec.m_quad, v20.m_vec.m_quad, 255);
      v23 = _mm_shuffle_ps(v19, v19, 255);
      v24 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v20.m_vec.m_quad, v20.m_vec.m_quad, 201), v19),
              _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v20.m_vec.m_quad));
      v25 = _mm_mul_ps(v20.m_vec.m_quad, v19);
      v26 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v24, v24, 201), _mm_mul_ps(desiredPoseLocalSpace->m_rotation.m_vec.m_quad, v23)),
              _mm_mul_ps(v19, v22));
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
      *p_m_rotation = (hkQuaternionf)v27;
      v28 = p_m_zeroHierarchyGainPose->m_scale.m_quad;
      q0.m_vec.m_quad = v27;
      p_m_rotation[1].m_vec.m_quad = _mm_mul_ps(v28, desiredPoseLocalSpace->m_scale.m_quad);
      m_controlDataIndices = bodydata->m_controlDataIndices;
      if ( !m_controlDataIndices
        || (LODWORD(m_controlDataIndices) = m_controlDataIndices[v9], (_DWORD)m_controlDataIndices != -1) )
      {
        m_hierarchyGain_low = (__m128)LODWORD(controlPalette[(int)m_controlDataIndices].m_hierarchyGain);
        m_boneWeights = bodydata->m_boneWeights;
        v32 = _mm_shuffle_ps(m_hierarchyGain_low, m_hierarchyGain_low, 0);
        t.m_real = v32;
        if ( m_boneWeights )
        {
          v33 = (__m128)LODWORD(m_boneWeights[v5]);
          v32 = _mm_mul_ps(v32, _mm_shuffle_ps(v33, v33, 0));
          t.m_real = v32;
        }
        if ( v32.m128_f32[0] > 0.0 && (int)v12 >= 0 )
        {
          v34 = bodydata->m_rigidBodies[v12];
          v35 = v34->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
          v36 = _mm_mul_ps(desiredPoseLocalSpace->m_translation.m_quad, v35);
          v37 = _mm_shuffle_ps(v35, v35, 255);
          v38 = _mm_shuffle_ps(v35, v35, 201);
          v39 = _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(
                      desiredPoseLocalSpace->m_translation.m_quad,
                      desiredPoseLocalSpace->m_translation.m_quad,
                      201),
                    v35),
                  _mm_mul_ps(desiredPoseLocalSpace->m_translation.m_quad, v38));
          v40 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                  _mm_shuffle_ps(v36, v36, 170));
          v41 = v35;
          v42 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(v40, v35),
                    _mm_mul_ps(
                      _mm_sub_ps(_mm_mul_ps(v37, v37), (__m128)xmmword_141A711B0),
                      desiredPoseLocalSpace->m_translation.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v37));
          v43 = _mm_add_ps(_mm_add_ps(v42, v42), v34->m_motion.m_motionState.m_transform.m_translation.m_quad);
          v59 = _mm_mul_ps(query.m_quad, desiredPoseLocalSpace->m_scale.m_quad);
          v57 = v43;
          v44.m_vec.m_quad = (__m128)desiredPoseLocalSpace->m_rotation;
          v45 = _mm_mul_ps(_mm_shuffle_ps(v44.m_vec.m_quad, v44.m_vec.m_quad, 201), v35);
          v46 = _mm_mul_ps(v35, v44.m_vec.m_quad);
          v47 = _mm_shuffle_ps(v44.m_vec.m_quad, v44.m_vec.m_quad, 255);
          v48 = _mm_sub_ps(v45, _mm_mul_ps(v38, v44.m_vec.m_quad));
          v49 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v48, v48, 201), _mm_mul_ps(v44.m_vec.m_quad, v37)),
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
        v51.m_quad = (__m128)bodydata->m_rigidBodies[v8]->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal;
        v52 = _mm_mul_ps(v27, v51.m_quad);
        v53 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v51.m_quad, v51.m_quad, 201), v27),
                _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v51.m_quad));
        p_m_rotation[-3] = (hkQuaternionf)v27;
        v54 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                      _mm_shuffle_ps(v52, v52, 170)),
                    v27),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v50, v50), (__m128)xmmword_141A711B0), v51.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v50));
        p_m_rotation[-4].m_vec.m_quad = _mm_add_ps(_mm_add_ps(v54, v54), v21);
        p_m_rotation[-2].m_vec = (hkVector4f)aabbOut.m_quad;
      }
      ++v5;
      ++v11;
      ++v9;
      ++desiredPoseLocalSpace;
      ++v8;
      p_m_rotation += 6;
    }
    while ( v5 < bodydata->m_numRigidBodies );
  }
}

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
  v4 = _mm_cmplt_ps(_mm_mul_ps(maxLen->m_real, maxLen->m_real), v3);
  v5 = _mm_rsqrt_ps(v3);
  vec->m_quad = _mm_or_ps(
                  _mm_and_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmple_ps(v3, (__m128)0i64),
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
hkSimdFloat32 *__fastcall clipSnapVector(
        hkSimdFloat32 *result,
        hkSimdFloat32 *snapMaxVelocity,
        hkSimdFloat32 *maxDist,
        hkVector4f *vectorIn)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm5
  __m128 v6; // xmm6
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm0

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
    v11 = _mm_cmplt_ps(v6, _mm_mul_ps(maxDist->m_real, maxDist->m_real));
    vectorIn->m_quad = _mm_or_ps(
                         _mm_andnot_ps(
                           v11,
                           _mm_mul_ps(
                             vectorIn->m_quad,
                             _mm_mul_ps(
                               _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v8, v6)), v8),
                               _mm_mul_ps(maxDist->m_real, snapMaxVelocity->m_real)))),
                         _mm_and_ps(
                           v11,
                           _mm_mul_ps(
                             _mm_andnot_ps(
                               _mm_cmple_ps(v9, (__m128)0i64),
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
void __fastcall hkaKeyFrameHierarchyUtility::applyKeyFrame(
        float deltaTime,
        hkaKeyFrameHierarchyUtility::KeyFrameData *pose,
        hkaKeyFrameHierarchyUtility::BodyData *bodydata,
        hkaKeyFrameHierarchyUtility::ControlData *controlPalette,
        hkaKeyFrameHierarchyUtility::Output *output)
{
  int m_numRigidBodies; // ebx
  hkLifoAllocator *Value; // rax
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
  __m128 *p_m_quad; // rbp
  __int64 v21; // r12
  int *m_controlDataIndices; // rax
  hkaKeyFrameHierarchyUtility::Output v23; // xmm11_4
  const float *m_boneWeights; // rcx
  hkpRigidBody *v25; // rdi
  unsigned int *v26; // rbx
  __m128 v27; // xmm12
  __m128 v28; // xmm13
  __m128 v29; // xmm14
  __m128 v30; // xmm10
  __m128 v31; // xmm0
  __m128 v32; // xmm0
  __m128 v33; // xmm0
  hkaKeyFrameHierarchyUtility::WorkElem *m_internalReferencePose; // rax
  __m128 v35; // xmm3
  __m128 v36; // xmm0
  __m128 v37; // xmm1
  __m128 v38; // xmm7
  __m128 v39; // xmm1
  __m128 v40; // xmm0
  int v41; // eax
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
  __m128 m_quad; // xmm3
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
  __m128 v76; // xmm3
  __m128 v77; // xmm5
  __m128 v78; // xmm0
  __m128 v79; // xmm8
  __m128 v80; // xmm3
  __m128 v81; // xmm9
  __m128 v82; // xmm4
  __m128 v83; // xmm1
  __m128 v84; // xmm0
  __m128 v85; // xmm3
  __m128 v86; // xmm7
  __m128 v87; // xmm4
  __m128 v88; // xmm0
  __m128 v89; // xmm1
  __m128 v90; // xmm0
  __m128 v91; // xmm12
  __m128 v92; // xmm6
  __m128 v93; // xmm7
  __m128 v94; // xmm1
  __m128 v95; // xmm3
  __m128 v96; // xmm5
  __m128 v97; // xmm1
  __m128 v98; // xmm12
  __m128 v99; // xmm3
  __m128 v100; // xmm8
  __m128 v101; // xmm4
  __m128 v102; // xmm0
  __m128 v103; // xmm3
  __m128 v104; // xmm7
  __m128 v105; // xmm4
  __m128 v106; // xmm0
  __m128 v107; // xmm5
  __m128 v108; // xmm4
  __m128 v109; // xmm5
  __m128 v110; // xmm1
  __m128 v111; // xmm6
  float v112; // xmm9_4
  __m128 v113; // xmm3
  __m128 v114; // xmm2
  __m128 v115; // xmm1
  __m128 v116; // xmm0
  __m128 v117; // xmm6
  hkLifoAllocator *v118; // rax
  int v119; // r8d
  int v120; // [rsp+30h] [rbp-168h]
  MatrixCache *v121; // [rsp+38h] [rbp-160h]
  __m128 v122; // [rsp+40h] [rbp-158h]
  __m128 v123; // [rsp+50h] [rbp-148h] BYREF
  __m128 v124; // [rsp+60h] [rbp-138h] BYREF
  __m128 v125; // [rsp+70h] [rbp-128h]
  hkaKeyFrameHierarchyUtility::WorkElem *v126; // [rsp+80h] [rbp-118h]
  __m128 v127; // [rsp+90h] [rbp-108h]
  __m128 v128; // [rsp+A0h] [rbp-F8h]
  int v130; // [rsp+1B0h] [rbp+18h]

  m_numRigidBodies = bodydata->m_numRigidBodies;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  mc = (MatrixCache *)Value->m_cur;
  v121 = mc;
  v11 = (96 * m_numRigidBodies + 127) & 0xFFFFFF80;
  v120 = v11;
  v12 = (char *)mc + v11;
  if ( v11 > Value->m_slabSize || v12 > Value->m_end )
  {
    mc = (MatrixCache *)hkLifoAllocator::allocateFromNewSlab(Value, v11);
    v121 = mc;
  }
  else
  {
    Value->m_cur = v12;
  }
  calcComPoseUsingHierarchy(pose->m_desiredPoseLocalSpace, bodydata, controlPalette, &pose->m_worldFromRoot, mc);
  v13 = 0;
  v14 = _mm_shuffle_ps((__m128)LODWORD(deltaTime), (__m128)LODWORD(deltaTime), 0);
  v15 = _mm_rcp_ps(v14);
  v16 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v14, v15)), v15);
  v122 = v16;
  if ( bodydata->m_numRigidBodies > 0 )
  {
    v17 = 0i64;
    v18 = 0i64;
    v19 = 0i64;
    p_m_quad = &mc->m_zeroHierarchyGainPose.m_rotation.m_vec.m_quad;
    v21 = 0i64;
    do
    {
      m_controlDataIndices = bodydata->m_controlDataIndices;
      if ( m_controlDataIndices )
        LODWORD(m_controlDataIndices) = m_controlDataIndices[v21];
      v23.m_stressSquared = v17.m128_f32[0];
      if ( (_DWORD)m_controlDataIndices != -1 )
      {
        m_boneWeights = bodydata->m_boneWeights;
        v25 = bodydata->m_rigidBodies[v19];
        v26 = (unsigned int *)&controlPalette[(int)m_controlDataIndices];
        v27 = _mm_shuffle_ps((__m128)v26[2], (__m128)v26[2], 0);
        v28 = _mm_shuffle_ps((__m128)v26[3], (__m128)v26[3], 0);
        v29 = _mm_shuffle_ps((__m128)v26[4], (__m128)v26[4], 0);
        v30 = _mm_shuffle_ps((__m128)v26[7], (__m128)v26[7], 0);
        if ( m_boneWeights )
        {
          v31 = (__m128)LODWORD(m_boneWeights[v13]);
          v32 = _mm_shuffle_ps(v31, v31, 0);
          v27 = _mm_mul_ps(v27, v32);
          v28 = _mm_mul_ps(v28, v32);
          v29 = _mm_mul_ps(v29, v32);
          v30 = _mm_mul_ps(v30, v32);
        }
        v33 = _mm_shuffle_ps((__m128)v26[1], (__m128)v26[1], 0);
        m_internalReferencePose = pose->m_internalReferencePose;
        v126 = m_internalReferencePose;
        v35 = _mm_sub_ps(query.m_quad, v33);
        v36 = p_m_quad[-4];
        v37 = _mm_sub_ps(v36, m_internalReferencePose[v18].m_prevPosition.m_quad);
        v38 = _mm_sub_ps(v36, v25->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
        m_internalReferencePose[v18].m_prevPosition.m_quad = v36;
        v125 = v35;
        v39 = _mm_mul_ps(v37, v16);
        v40 = _mm_sub_ps(v39, m_internalReferencePose[v18].m_prevLinearVelocity.m_quad);
        m_internalReferencePose[v18].m_prevLinearVelocity.m_quad = v39;
        v41 = 0;
        v42 = _mm_add_ps(_mm_mul_ps(v35, v25->m_motion.m_linearVelocity.m_quad), _mm_mul_ps(v40, v27));
        v43 = _mm_add_ps(v42, _mm_mul_ps(_mm_sub_ps(v39, v42), v28));
        v123 = v43;
        v44 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v38, v16), v43), v29);
        v45 = _mm_shuffle_ps((__m128)v26[5], (__m128)v26[5], 0);
        v46 = _mm_mul_ps(v44, v44);
        v127 = *(__m128 *)_xmm;
        v47 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
                _mm_shuffle_ps(v46, v46, 170));
        v48 = _mm_cmplt_ps(_mm_mul_ps(v45, v45), v47);
        v49 = _mm_cmple_ps(v47, v17);
        v50 = _mm_rsqrt_ps(v47);
        v51 = _mm_andnot_ps(
                v49,
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v47), v50)),
                  _mm_mul_ps(*(__m128 *)_xmm, v50)));
        if ( v30.m128_f32[0] != 0.0 )
          v41 = 1;
        v130 = v41;
        v52 = _mm_add_ps(
                v43,
                _mm_or_ps(_mm_and_ps(_mm_mul_ps(_mm_mul_ps(v51, v45), v44), v48), _mm_andnot_ps(v48, v44)));
        v123 = v52;
        if ( v41 )
        {
          m_quad = v25->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad;
          v54 = _mm_mul_ps(*p_m_quad, m_quad);
          v55 = _mm_shuffle_ps(*p_m_quad, *p_m_quad, 255);
          v56 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), *p_m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(*p_m_quad, *p_m_quad, 201), m_quad));
          v57 = _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), _mm_shuffle_ps(v54, v54, 0)),
                    _mm_shuffle_ps(v54, v54, 170)),
                  *p_m_quad);
          v58 = _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v55);
          v128 = _mm_shuffle_ps((__m128)v26[8], (__m128)v26[8], 0);
          v59 = _mm_add_ps(v57, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v55, v55), (__m128)xmmword_141A711B0), m_quad));
          v60 = _mm_mul_ps(v128, v128);
          v61 = _mm_add_ps(v59, v58);
          v62 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_mul_ps(
                      _mm_sub_ps(
                        _mm_add_ps(_mm_add_ps(v61, v61), p_m_quad[-1]),
                        v25->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad),
                      v16),
                    v52),
                  v30);
          v63 = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v26[10], (__m128)v26[10], 0), v122), v30);
          v64 = _mm_mul_ps(v62, v62);
          v65 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
                  _mm_shuffle_ps(v64, v64, 170));
          v64.m128_f32[0] = _mm_rcp_ps(v60).m128_f32[0];
          v23.m_stressSquared = (float)((float)(2.0 - (float)(v64.m128_f32[0] * v60.m128_f32[0])) * v64.m128_f32[0])
                              * v65.m128_f32[0];
          if ( v65.m128_f32[0] > v60.m128_f32[0] )
          {
            v66 = _mm_rcp_ps(v65);
            v67 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v66, v65)), v66), v60);
            v68 = _mm_rsqrt_ps(v67);
            v69 = _mm_mul_ps(v66, v65);
            v70 = _mm_cmplt_ps(v65, _mm_mul_ps(v63, v63));
            v62 = _mm_or_ps(
                    _mm_andnot_ps(
                      v70,
                      _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v69), v66), _mm_mul_ps(v128, v63)), v62)),
                    _mm_and_ps(
                      v70,
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmple_ps(v67, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v68, v67), v68)),
                              _mm_mul_ps(v127, v68)),
                            v67)),
                        v62)));
          }
          v123 = _mm_add_ps(v52, v62);
        }
        hkpEntity::activate(v25);
        v25->m_motion.hkpEntity::vfptr[9].__vecDelDtor(&v25->m_motion, (unsigned int)&v123);
        v71 = p_m_quad[-3];
        v72 = v25->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
        v73 = (__int64)v126;
        v74 = _mm_mul_ps(_mm_shuffle_ps(v72, v72, 255), v71);
        v75 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v71, v71, 201), v72), _mm_mul_ps(_mm_shuffle_ps(v72, v72, 201), v71));
        v76 = _mm_mul_ps(v72, v71);
        v77 = _mm_shuffle_ps(v71, v71, 255);
        v78 = _mm_mul_ps(v25->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad, v77);
        v79 = _mm_add_ps(_mm_shuffle_ps(v76, v76, 78), v76);
        v80 = v126[v18].m_prevRotation.m_vec.m_quad;
        v126[v18].m_prevRotation.m_vec.m_quad = v71;
        v81 = _mm_add_ps(_mm_sub_ps(_mm_shuffle_ps(v75, v75, 201), v78), v74);
        v82 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v71, v71, 201), v80), _mm_mul_ps(_mm_shuffle_ps(v80, v80, 201), v71));
        v83 = _mm_mul_ps(_mm_shuffle_ps(v80, v80, 255), v71);
        v84 = _mm_mul_ps(v80, v77);
        v85 = _mm_mul_ps(v80, v71);
        v86 = _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v79, v79, 177), v79), 0x1Fu),
                          0x1Fu),
                _mm_add_ps(v81, v81));
        v16 = v122;
        v87 = _mm_add_ps(_mm_sub_ps(_mm_shuffle_ps(v82, v82, 201), v84), v83);
        v88 = _mm_add_ps(_mm_shuffle_ps(v85, v85, 78), v85);
        v89 = _mm_mul_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v88, v88, 177), v88), 0x1Fu),
                            0x1Fu),
                  _mm_add_ps(v87, v87)),
                v122);
        v90 = _mm_sub_ps(v89, *(__m128 *)(v18 * 64 + v73 + 48));
        *(__m128 *)(v18 * 64 + v73 + 48) = v89;
        v125 = _mm_mul_ps(v25->m_motion.m_angularVelocity.m_quad, v125);
        v91 = _mm_add_ps(v125, _mm_mul_ps(v90, v27));
        v124 = _mm_add_ps(v91, _mm_mul_ps(_mm_sub_ps(v89, v91), v28));
        v92 = _mm_shuffle_ps((__m128)v26[6], (__m128)v26[6], 0);
        v93 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v86, v122), v124), v29);
        v94 = _mm_mul_ps(v93, v93);
        v95 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v94, v94, 85), _mm_shuffle_ps(v94, v94, 0)),
                _mm_shuffle_ps(v94, v94, 170));
        v96 = _mm_cmplt_ps(_mm_mul_ps(v92, v92), v95);
        v97 = _mm_rsqrt_ps(v95);
        v98 = _mm_add_ps(
                v124,
                _mm_or_ps(
                  _mm_and_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmple_ps(v95, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v97, v95), v97)),
                            _mm_mul_ps(v97, v127))),
                        v92),
                      v93),
                    v96),
                  _mm_andnot_ps(v96, v93)));
        v124 = v98;
        if ( v130 )
        {
          v99 = v25->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
          v100 = _mm_shuffle_ps((__m128)v26[9], (__m128)v26[9], 0);
          v101 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(*p_m_quad, *p_m_quad, 201), v99),
                   _mm_mul_ps(_mm_shuffle_ps(v99, v99, 201), *p_m_quad));
          v102 = _mm_mul_ps(_mm_shuffle_ps(*p_m_quad, *p_m_quad, 255), v99);
          v103 = _mm_mul_ps(v99, *p_m_quad);
          v104 = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v26[11], (__m128)v26[11], 0), v122), v30);
          v105 = _mm_add_ps(
                   _mm_sub_ps(_mm_shuffle_ps(v101, v101, 201), v102),
                   _mm_mul_ps(
                     _mm_shuffle_ps(
                       v25->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
                       v25->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
                       255),
                     *p_m_quad));
          v106 = _mm_add_ps(_mm_shuffle_ps(v103, v103, 78), v103);
          v107 = _mm_mul_ps(
                   _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v106, v106, 177), v106), 0x1Fu),
                               0x1Fu),
                     _mm_add_ps(v105, v105)),
                   v122);
          v108 = _mm_mul_ps(v100, v100);
          v109 = _mm_mul_ps(_mm_sub_ps(v107, v98), v30);
          v110 = _mm_mul_ps(v109, v109);
          v111 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v110, v110, 85), _mm_shuffle_ps(v110, v110, 0)),
                   _mm_shuffle_ps(v110, v110, 170));
          v110.m128_f32[0] = _mm_rcp_ps(v108).m128_f32[0];
          v112 = (float)((float)(2.0 - (float)(v110.m128_f32[0] * v108.m128_f32[0])) * v110.m128_f32[0])
               * v111.m128_f32[0];
          if ( v111.m128_f32[0] > v108.m128_f32[0] )
          {
            v113 = _mm_rcp_ps(v111);
            v114 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v113, v111)), v113), v108);
            v115 = _mm_rsqrt_ps(v114);
            v116 = _mm_mul_ps(v113, v111);
            v117 = _mm_cmplt_ps(v111, _mm_mul_ps(v104, v104));
            v109 = _mm_or_ps(
                     _mm_andnot_ps(
                       v117,
                       _mm_mul_ps(
                         _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v116), v113), _mm_mul_ps(v100, v104)),
                         v109)),
                     _mm_and_ps(
                       _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmple_ps(v114, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v114, v115), v115)),
                               _mm_mul_ps(v127, v115)),
                             v114)),
                         v109),
                       v117));
          }
          v23.m_stressSquared = v23.m_stressSquared + v112;
          v16 = v122;
          v124 = _mm_add_ps(v98, v109);
        }
        hkpEntity::activate(v25);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v25->m_motion.hkpEntity::vfptr[9].__first_virtual_table_function__)(
          &v25->m_motion,
          &v124);
        v17 = 0i64;
        if ( output )
          output[v13] = v23;
      }
      ++v13;
      ++v21;
      ++v19;
      p_m_quad += 6;
      ++v18;
    }
    while ( v13 < bodydata->m_numRigidBodies );
    v11 = v120;
    mc = v121;
  }
  v118 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v119 = (v11 + 15) & 0xFFFFFFF0;
  if ( v11 > v118->m_slabSize || (char *)mc + v119 != v118->m_cur || v118->m_firstNonLifoEnd == mc )
    hkLifoAllocator::slowBlockFree(v118, mc, v119);
  else
    v118->m_cur = mc;
}

