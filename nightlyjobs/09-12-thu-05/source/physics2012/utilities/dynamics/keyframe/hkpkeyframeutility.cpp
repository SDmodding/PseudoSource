// File Line: 18
// RVA: 0xE11F80
void __fastcall hkpKeyFrameUtility::KeyFrameInfo::fastSetUsingPositionOrientationPair(hkpKeyFrameUtility::KeyFrameInfo *this, hkVector4f *currentPosition, hkQuaternionf *currentOrientation, hkVector4f *nextPosition, hkQuaternionf *nextOrientation, float invDeltaTime)
{
  hkQuaternionf *v6; // rax
  __m128 v7; // xmm5
  __m128 v8; // xmm4
  __m128 v9; // xmm3
  __m128 v10; // xmm4
  __m128 v11; // xmm0
  __m128 v12; // xmm4

  v6 = nextOrientation;
  this->m_position = (hkVector4f)currentPosition->m_quad;
  v7 = _mm_shuffle_ps((__m128)LODWORD(invDeltaTime), (__m128)LODWORD(invDeltaTime), 0);
  this->m_linearVelocity.m_quad = _mm_mul_ps(_mm_sub_ps(nextPosition->m_quad, currentPosition->m_quad), v7);
  this->m_orientation = (hkQuaternionf)currentOrientation->m_vec.m_quad;
  v8 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v6->m_vec.m_quad, v6->m_vec.m_quad, 201), currentOrientation->m_vec.m_quad),
         _mm_mul_ps(
           _mm_shuffle_ps(currentOrientation->m_vec.m_quad, currentOrientation->m_vec.m_quad, 201),
           nextOrientation->m_vec.m_quad));
  v9 = _mm_mul_ps(nextOrientation->m_vec.m_quad, currentOrientation->m_vec.m_quad);
  v10 = _mm_add_ps(
          _mm_sub_ps(
            _mm_shuffle_ps(v8, v8, 201),
            _mm_mul_ps(_mm_shuffle_ps(v6->m_vec.m_quad, v6->m_vec.m_quad, 255), currentOrientation->m_vec.m_quad)),
          _mm_mul_ps(
            _mm_shuffle_ps(currentOrientation->m_vec.m_quad, currentOrientation->m_vec.m_quad, 255),
            nextOrientation->m_vec.m_quad));
  v11 = _mm_add_ps(_mm_shuffle_ps(v9, v9, 78), v9);
  v12 = _mm_shuffle_ps(v10, _mm_unpackhi_ps(v10, _mm_add_ps(_mm_shuffle_ps(v11, v11, 177), v11)), 196);
  this->m_angularVelocity.m_quad = _mm_xor_ps(
                                     (__m128)_mm_slli_epi32(
                                               _mm_srli_epi32(
                                                 (__m128i)_mm_cmpltps(_mm_shuffle_ps(v12, v12, 255), (__m128)0i64),
                                                 0x1Fu),
                                               0x1Fu),
                                     _mm_mul_ps(_mm_mul_ps((__m128)xmmword_141A710D0, v7), v12));
}

// File Line: 37
// RVA: 0xE12040
void __fastcall hkpKeyFrameUtility::AccelerationInfo::AccelerationInfo(hkpKeyFrameUtility::AccelerationInfo *this)
{
  this->m_maxLinearAcceleration = 3.40282e38;
  this->m_maxAngularAcceleration = 3.40282e38;
  this->m_maxAllowedDistance = 3.40282e38;
  this->m_linearPositionFactor = (hkVector4f)query.m_quad;
  this->m_angularPositionFactor = (hkVector4f)query.m_quad;
  this->m_linearVelocityFactor = (hkVector4f)query.m_quad;
  this->m_angularVelocityFactor = (hkVector4f)query.m_quad;
}

// File Line: 49
// RVA: 0xE11C60
void __fastcall hkpKeyFrameUtility::KeyFrameInfo::setUsingPositionOrientationPair(hkpKeyFrameUtility::KeyFrameInfo *this, hkVector4f *currentPosition, hkQuaternionf *currentOrientation, hkVector4f *nextPosition, hkQuaternionf *nextOrientation, float invDeltaTime)
{
  hkQuaternionf *v6; // rax
  __m128 v7; // xmm13
  __m128 v8; // xmm11
  __m128 v9; // xmm3
  __m128 v10; // xmm11
  __m128 v11; // xmm0
  __m128 v12; // xmm11
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm11
  __m128 v18; // xmm12
  __m128i v19; // xmm10
  __m128 v20; // xmm9
  __m128 v21; // xmm7
  __m128 v22; // xmm6
  __m128 v23; // xmm2
  __m128 v24; // xmm5
  __m128 v25; // xmm4
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm5
  __m128 v29; // xmm2
  __m128 v30; // xmm1

  v6 = nextOrientation;
  this->m_position = (hkVector4f)currentPosition->m_quad;
  v7 = _mm_shuffle_ps((__m128)LODWORD(invDeltaTime), (__m128)LODWORD(invDeltaTime), 0);
  this->m_linearVelocity.m_quad = _mm_mul_ps(_mm_sub_ps(nextPosition->m_quad, currentPosition->m_quad), v7);
  this->m_orientation = (hkQuaternionf)currentOrientation->m_vec.m_quad;
  v8 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v6->m_vec.m_quad, v6->m_vec.m_quad, 201), currentOrientation->m_vec.m_quad),
         _mm_mul_ps(
           _mm_shuffle_ps(currentOrientation->m_vec.m_quad, currentOrientation->m_vec.m_quad, 201),
           nextOrientation->m_vec.m_quad));
  v9 = _mm_mul_ps(nextOrientation->m_vec.m_quad, currentOrientation->m_vec.m_quad);
  v10 = _mm_add_ps(
          _mm_sub_ps(
            _mm_shuffle_ps(v8, v8, 201),
            _mm_mul_ps(_mm_shuffle_ps(v6->m_vec.m_quad, v6->m_vec.m_quad, 255), currentOrientation->m_vec.m_quad)),
          _mm_mul_ps(
            _mm_shuffle_ps(currentOrientation->m_vec.m_quad, currentOrientation->m_vec.m_quad, 255),
            nextOrientation->m_vec.m_quad));
  v11 = _mm_add_ps(_mm_shuffle_ps(v9, v9, 78), v9);
  v12 = _mm_shuffle_ps(v10, _mm_unpackhi_ps(v10, _mm_add_ps(_mm_shuffle_ps(v11, v11, 177), v11)), 196);
  v13 = _mm_mul_ps(v12, v12);
  v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
  v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14);
  v16 = _mm_rsqrt_ps(v15);
  v17 = _mm_mul_ps(
          v12,
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)), _mm_mul_ps(*(__m128 *)_xmm, v16)));
  v18 = _mm_mul_ps(v17, v17);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 170))) > 1.4210855e-14 )
  {
    v19 = (__m128i)_mm_shuffle_ps(v17, v17, 255);
    v20 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v19, 1u), 1u);
    v21 = _mm_andnot_ps(*(__m128 *)_xmm, v20);
    v22 = _mm_cmpltps(v21, *(__m128 *)_xmm);
    v23 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v21), *(__m128 *)_xmm);
    v24 = _mm_cmpltps(*(__m128 *)_xmm, v21);
    v25 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v23), v24), _mm_andnot_ps(v24, v21));
    v26 = _mm_or_ps(_mm_andnot_ps(v24, _mm_mul_ps(v21, v21)), _mm_and_ps(v24, v23));
    v27 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v26, *(__m128 *)coeff4), *(__m128 *)coeff3), v26),
                          *(__m128 *)coeff2),
                        v26),
                      *(__m128 *)coeff1),
                    v26),
                  *(__m128 *)coeff0),
                v26),
              v25),
            v25);
    v28 = (__m128)COERCE_UNSIGNED_INT(
                    (float)(1.5707964
                          - COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                                                   v22,
                                                                   _mm_or_ps(
                                                                     _mm_and_ps(
                                                                       _mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v27, v27)),
                                                                       v24),
                                                                     _mm_andnot_ps(v24, v27))) | v22.m128_i32[0] & v21.m128_i32[0]) ^ v20.m128_i32[0] & _xmm[0]))
                  * 2.0);
    v29 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
            _mm_shuffle_ps(v18, v18, 170));
    v30 = _mm_rsqrt_ps(v29);
    this->m_angularVelocity.m_quad = _mm_mul_ps(
                                       _mm_xor_ps(
                                         (__m128)_mm_slli_epi32(
                                                   _mm_srli_epi32(
                                                     (__m128i)_mm_cmpltps((__m128)v19, (__m128)0i64),
                                                     0x1Fu),
                                                   0x1Fu),
                                         _mm_mul_ps(
                                           _mm_andnot_ps(
                                             _mm_cmpleps(v29, (__m128)0i64),
                                             _mm_mul_ps(
                                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                                               _mm_mul_ps(*(__m128 *)_xmm, v30))),
                                           v17)),
                                       _mm_mul_ps(_mm_shuffle_ps(v28, v28, 0), v7));
  }
  else
  {
    this->m_angularVelocity = 0i64;
  }
}

// File Line: 81
// RVA: 0xE12080
void __fastcall hkpKeyFrameUtility::applySoftKeyFrame(hkpKeyFrameUtility::KeyFrameInfo *keyFrameInfo, hkpKeyFrameUtility::AccelerationInfo *accelInfo, float deltaTime, float invDeltaTime, hkpRigidBody *body)
{
  hkpKeyFrameUtility::KeyFrameInfo *v5; // rsi
  __m128 *v6; // rbp
  float v7; // xmm6_4
  __m128 v8; // xmm9
  __m128 v9; // xmm8
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  hkQuaternionf v12; // xmm3
  hkVector4f v13; // xmm6
  __m128 v14; // xmm4
  __m128 v15; // xmm0
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm0
  __m128 v19; // xmm4
  __m128 v20; // xmm1
  __m128 v21; // xmm8
  __m128 v22; // xmm7
  __m128 v23; // xmm5
  __m128 v24; // xmm1
  __m128 v25; // xmm4
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm8
  __m128 v29; // xmm4
  __m128 v30; // xmm2
  __m128 v31; // xmm7
  __m128 v32; // xmm8
  __m128 v33; // [rsp+20h] [rbp-78h]
  __m128 v34; // [rsp+30h] [rbp-68h]

  v5 = keyFrameInfo;
  v6 = &accelInfo->m_linearPositionFactor.m_quad;
  LODWORD(v7) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(accelInfo->m_maxAllowedDistance),
                                     (__m128)LODWORD(accelInfo->m_maxAllowedDistance),
                                     0);
  v8 = _mm_shuffle_ps((__m128)LODWORD(deltaTime), (__m128)LODWORD(deltaTime), 0);
  v9 = _mm_sub_ps(keyFrameInfo->m_position.m_quad, body->m_motion.m_motionState.m_transform.m_translation.m_quad);
  hkUFloat8::getEncodedFloat(body->m_motion.m_motionState.m_maxAngularVelocity.m_value);
  hkUFloat8::getEncodedFloat(body->m_motion.m_motionState.m_maxLinearVelocity.m_value);
  v10 = _mm_mul_ps(v9, v9);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 170))) > (float)(v7 * v7) )
  {
    v9 = 0i64;
    hkpRigidBody::setPositionAndRotation(body, &v5->m_position, &v5->m_orientation);
    hkpEntity::activate((hkpEntity *)&body->vfptr);
    ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))body->m_motion.vfptr[9].__first_virtual_table_function__)(
      &body->m_motion,
      &v5->m_angularVelocity);
    hkpEntity::activate((hkpEntity *)&body->vfptr);
    body->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&body->m_motion, (unsigned int)&v5->m_linearVelocity);
  }
  v11 = v5->m_orientation.m_vec.m_quad;
  v12.m_vec.m_quad = (__m128)body->m_motion.m_motionState.m_sweptTransform.m_rotation1;
  v13.m_quad = (__m128)body->m_motion.m_angularVelocity;
  v14 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v12.m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v12.m_vec.m_quad, v12.m_vec.m_quad, 201), v11));
  v15 = _mm_mul_ps(
          _mm_shuffle_ps(v5->m_orientation.m_vec.m_quad, v5->m_orientation.m_vec.m_quad, 255),
          v12.m_vec.m_quad);
  v16 = _mm_mul_ps(v12.m_vec.m_quad, v11);
  v17 = _mm_add_ps(
          _mm_sub_ps(_mm_shuffle_ps(v14, v14, 201), v15),
          _mm_mul_ps(
            _mm_shuffle_ps(
              body->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
              body->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
              255),
            v11));
  v18 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 78), v16);
  v19 = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, _mm_add_ps(_mm_shuffle_ps(v18, v18, 177), v18)), 196);
  v20 = _mm_mul_ps(*v6, v9);
  v21 = _mm_mul_ps(_mm_shuffle_ps((__m128)v6[4].m128_u32[0], (__m128)v6[4].m128_u32[0], 0), v8);
  v22 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(v6[2], v8),
            _mm_sub_ps(v5->m_linearVelocity.m_quad, body->m_motion.m_linearVelocity.m_quad)),
          v20);
  v23 = _mm_add_ps(
          _mm_mul_ps(
            _mm_xor_ps(
              (__m128)_mm_slli_epi32(
                        _mm_srli_epi32((__m128i)_mm_cmpltps(_mm_shuffle_ps(v19, v19, 255), (__m128)0i64), 0x1Fu),
                        0x1Fu),
              _mm_mul_ps(v19, (__m128)xmmword_141A710D0)),
            v6[1]),
          _mm_mul_ps(_mm_sub_ps(v5->m_angularVelocity.m_quad, v13.m_quad), _mm_mul_ps(v6[3], v8)));
  v24 = _mm_mul_ps(v22, v22);
  v25 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)), _mm_shuffle_ps(v24, v24, 170));
  if ( v25.m128_f32[0] > (float)(v21.m128_f32[0] * v21.m128_f32[0]) )
  {
    v26 = _mm_rsqrt_ps(v25);
    v22 = _mm_mul_ps(
            v22,
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmpleps(v25, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                  _mm_mul_ps(*(__m128 *)_xmm, v26))),
              v21));
  }
  v27 = _mm_mul_ps(v23, v23);
  v28 = _mm_mul_ps(_mm_shuffle_ps((__m128)v6[4].m128_u32[1], (__m128)v6[4].m128_u32[1], 0), v8);
  v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)), _mm_shuffle_ps(v27, v27, 170));
  if ( v29.m128_f32[0] > (float)(v28.m128_f32[0] * v28.m128_f32[0]) )
  {
    v30 = _mm_rsqrt_ps(v29);
    v23 = _mm_mul_ps(
            v23,
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmpleps(v29, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                  _mm_mul_ps(*(__m128 *)_xmm, v30))),
              v28));
  }
  v31 = _mm_add_ps(v22, body->m_motion.m_linearVelocity.m_quad);
  v33 = v31;
  v32 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0);
  v34 = _mm_add_ps(v23, v13.m_quad);
  if ( (_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v13.m_quad, v34), 1u), 1u), v32)) & 7) != 7 )
  {
    hkpEntity::activate((hkpEntity *)&body->vfptr);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))body->m_motion.vfptr[9].__first_virtual_table_function__)(
      &body->m_motion,
      &v34);
    v31 = v33;
  }
  if ( (_mm_movemask_ps(
          _mm_cmpltps(
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32((__m128i)_mm_sub_ps(body->m_motion.m_linearVelocity.m_quad, v31), 1u),
                      1u),
            v32)) & 7) != 7 )
  {
    hkpEntity::activate((hkpEntity *)&body->vfptr);
    body->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&body->m_motion, (unsigned int)&v33);
  }
}

// File Line: 209
// RVA: 0xE12420
void __usercall hkpKeyFrameUtility::applyHardKeyFrame(hkVector4f *nextPosition@<rcx>, hkQuaternionf *nextOrientation@<rdx>, float invDeltaTime@<xmm2>, hkpRigidBody *body@<r9>, __int128 a5@<xmm8>)
{
  __m128 v5; // xmm2
  hkVector4f v6; // xmm3
  hkpRigidBody *v7; // rbx
  hkQuaternionf *v8; // rdi
  __m128 v9; // xmm1
  __m128 v10; // xmm5
  __m128 v11; // xmm6
  __m128 v12; // xmm14
  __m128 v13; // xmm13
  __m128 v14; // xmm4
  __m128 v15; // xmm4
  char v16; // cl
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 v19; // xmm11
  __m128 v20; // xmm0
  __m128 v21; // xmm3
  __m128 v22; // xmm11
  __m128 v23; // xmm0
  __m128 v24; // xmm11
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  __m128 v29; // xmm11
  __m128 v30; // xmm12
  __m128i v31; // xmm10
  __m128 v32; // xmm9
  __m128 v33; // xmm7
  __m128 v34; // xmm6
  __m128 v35; // xmm2
  __m128 v36; // xmm5
  __m128 v37; // xmm4
  __m128 v38; // xmm3
  __m128 v39; // xmm2
  __m128 v40; // xmm2
  __m128 v41; // xmm1
  __m128 v42; // [rsp+20h] [rbp-B8h]
  __int128 v43; // [rsp+A0h] [rbp-38h]
  unsigned int v44; // [rsp+E0h] [rbp+8h]
  float v45; // [rsp+F0h] [rbp+18h]

  v45 = invDeltaTime;
  v5 = nextOrientation->m_vec.m_quad;
  v6.m_quad = (__m128)body->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal;
  v7 = body;
  v8 = nextOrientation;
  v9 = _mm_mul_ps(v6.m_quad, nextOrientation->m_vec.m_quad);
  v10 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 201), v5),
          _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v6.m_quad));
  v11 = _mm_shuffle_ps(v5, v5, 255);
  v12 = _mm_shuffle_ps((__m128)LODWORD(v45), (__m128)LODWORD(v45), 0);
  v13 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0);
  v14 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170)),
              nextOrientation->m_vec.m_quad),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v11, v11), (__m128)xmmword_141A711B0), v6.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v11));
  v15 = _mm_add_ps(_mm_add_ps(v14, v14), nextPosition->m_quad);
  v16 = body->m_motion.m_motionState.m_maxLinearVelocity.m_value;
  v42 = _mm_mul_ps(_mm_sub_ps(v15, body->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad), v12);
  hkUFloat8::getEncodedFloat(v16);
  if ( (_mm_movemask_ps(
          _mm_cmpltps(
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32((__m128i)_mm_sub_ps(v7->m_motion.m_linearVelocity.m_quad, v42), 1u),
                      1u),
            v13)) & 7) != 7 )
  {
    hkpEntity::activate((hkpEntity *)&v7->vfptr);
    v7->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v7->m_motion.vfptr, (unsigned int)&v42);
  }
  v17 = v8->m_vec.m_quad;
  v18 = v7->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
  v19 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v18), _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v17));
  v20 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 255), v18);
  v21 = _mm_mul_ps(v18, v8->m_vec.m_quad);
  v22 = _mm_add_ps(
          _mm_sub_ps(_mm_shuffle_ps(v19, v19, 201), v20),
          _mm_mul_ps(
            _mm_shuffle_ps(
              v7->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
              v7->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
              255),
            v8->m_vec.m_quad));
  v23 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 78), v21);
  v24 = _mm_shuffle_ps(v22, _mm_unpackhi_ps(v22, _mm_add_ps(_mm_shuffle_ps(v23, v23, 177), v23)), 196);
  v25 = _mm_mul_ps(v24, v24);
  v26 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 78), v25);
  v27 = _mm_add_ps(_mm_shuffle_ps(v26, v26, 177), v26);
  v28 = _mm_rsqrt_ps(v27);
  v29 = _mm_mul_ps(
          v24,
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v27), v28)), _mm_mul_ps(*(__m128 *)_xmm, v28)));
  v30 = _mm_mul_ps(v29, v29);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 170))) > 1.4210855e-14 )
  {
    v43 = a5;
    v31 = (__m128i)_mm_shuffle_ps(v29, v29, 255);
    v32 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v31, 1u), 1u);
    v33 = _mm_andnot_ps(*(__m128 *)_xmm, v32);
    v34 = _mm_cmpltps(v33, *(__m128 *)_xmm);
    v35 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v33), *(__m128 *)_xmm);
    v36 = _mm_cmpltps(*(__m128 *)_xmm, v33);
    v37 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v35), v36), _mm_andnot_ps(v36, v33));
    v38 = _mm_or_ps(_mm_andnot_ps(v36, _mm_mul_ps(v33, v33)), _mm_and_ps(v36, v35));
    v39 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v38, *(__m128 *)coeff4), *(__m128 *)coeff3), v38),
                          *(__m128 *)coeff2),
                        v38),
                      *(__m128 *)coeff1),
                    v38),
                  *(__m128 *)coeff0),
                v38),
              v37),
            v37);
    *(float *)&v44 = (float)(1.5707964
                           - COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                                                    v34,
                                                                    _mm_or_ps(
                                                                      _mm_and_ps(
                                                                        _mm_sub_ps(
                                                                          *(__m128 *)_xmm,
                                                                          _mm_add_ps(v39, v39)),
                                                                        v36),
                                                                      _mm_andnot_ps(v36, v39))) | v34.m128_i32[0] & v33.m128_i32[0]) ^ v32.m128_i32[0] & _xmm[0]))
                   * 2.0;
    v40 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
            _mm_shuffle_ps(v30, v30, 170));
    v41 = _mm_rsqrt_ps(v40);
    v42 = _mm_mul_ps(
            _mm_xor_ps(
              (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmpltps((__m128)v31, (__m128)0i64), 0x1Fu), 0x1Fu),
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v40, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v41, v40), v41)),
                    _mm_mul_ps(v41, *(__m128 *)_xmm))),
                v29)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)v44, (__m128)v44, 0), v12));
  }
  else
  {
    v42 = 0i64;
  }
  hkUFloat8::getEncodedFloat(v7->m_motion.m_motionState.m_maxAngularVelocity.m_value);
  if ( (_mm_movemask_ps(
          _mm_cmpltps(
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32((__m128i)_mm_sub_ps(v7->m_motion.m_angularVelocity.m_quad, v42), 1u),
                      1u),
            v13)) & 7) != 7 )
  {
    hkpEntity::activate((hkpEntity *)&v7->vfptr);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v7->m_motion.vfptr[9].__first_virtual_table_function__)(
      &v7->m_motion,
      &v42);
  }
}

// File Line: 275
// RVA: 0xE12880
void __usercall hkpKeyFrameUtility::applyHardKeyFrameAsynchronously(hkVector4f *nextPosition@<rcx>, hkQuaternionf *nextOrientation@<rdx>, float invDeltaTime@<xmm2>, hkpRigidBody *body@<r9>, __int128 a5@<xmm11>)
{
  hkVector4f *v5; // rbx
  hkpWorld *v6; // rcx
  hkpRigidBody *v7; // rdi
  hkQuaternionf *v8; // rsi
  __m128 v9; // xmm15
  unsigned int v10; // xmm0_4
  __m128 v11; // xmm2
  __m128 v12; // xmm7
  __m128 v13; // xmm3
  __m128 v14; // xmm8
  __m128 v15; // xmm7
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm4
  __m128 v21; // xmm0
  __m128 v22; // xmm3
  __m128 v23; // xmm6
  __m128 v24; // xmm1
  __m128 v25; // xmm8
  __m128 v26; // xmm5
  char v27; // cl
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  __m128 v30; // xmm12
  __m128 v31; // xmm12
  __m128 v32; // xmm1
  __m128 v33; // xmm12
  __m128 v34; // xmm0
  __m128 v35; // xmm12
  __m128 v36; // xmm0
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  __m128 v39; // xmm2
  __m128 v40; // xmm12
  __m128 v41; // xmm3
  __m128i v42; // xmm10
  __m128 v43; // xmm2
  __m128 v44; // xmm1
  __m128 v45; // xmm9
  __m128 v46; // xmm7
  __m128 v47; // xmm10
  __m128 v48; // xmm6
  __m128 v49; // xmm2
  __m128 v50; // xmm5
  __m128 v51; // xmm4
  __m128 v52; // xmm3
  __m128 v53; // xmm2
  __m128 v54; // [rsp+20h] [rbp-C8h]
  __m128 v55; // [rsp+30h] [rbp-B8h]
  __int128 v56; // [rsp+80h] [rbp-68h]

  v5 = nextPosition;
  v6 = body->m_world;
  v7 = body;
  v8 = nextOrientation;
  v9 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0);
  v55 = _mm_shuffle_ps((__m128)LODWORD(invDeltaTime), (__m128)LODWORD(invDeltaTime), 0);
  *(float *)&v10 = hkpWorld::getCurrentTime(v6);
  v11 = v7->m_motion.m_motionState.m_sweptTransform.m_centerOfMass0.m_quad;
  v12 = v7->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad;
  v13 = _mm_mul_ps(
          _mm_sub_ps(_mm_shuffle_ps((__m128)v10, (__m128)v10, 0), _mm_shuffle_ps(v11, v11, 255)),
          _mm_shuffle_ps(v12, v12, 255));
  v14 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(
              v7->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
              v7->m_motion.m_motionState.m_sweptTransform.m_rotation0.m_vec.m_quad),
            v13),
          v7->m_motion.m_motionState.m_sweptTransform.m_rotation0.m_vec.m_quad);
  v15 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v12, v11), v13), v11);
  v16 = _mm_mul_ps(v14, v14);
  v17 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 78), v16);
  v18 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 177), v17);
  v19 = _mm_rsqrt_ps(v18);
  v20 = _mm_cmpleps(v18, (__m128)0i64);
  v21 = _mm_mul_ps(v19, v18);
  v22 = v7->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad;
  v23 = _mm_shuffle_ps(v8->m_vec.m_quad, v8->m_vec.m_quad, 255);
  v24 = _mm_mul_ps(v7->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad, v8->m_vec.m_quad);
  v25 = _mm_mul_ps(
          v14,
          _mm_andnot_ps(
            v20,
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v21, v19)), _mm_mul_ps(*(__m128 *)_xmm, v19))));
  v26 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v8->m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v8->m_vec.m_quad, v8->m_vec.m_quad, 201), v22));
  v27 = v7->m_motion.m_motionState.m_maxLinearVelocity.m_value;
  v28 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                _mm_shuffle_ps(v24, v24, 170)),
              v8->m_vec.m_quad),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v23, v23), (__m128)xmmword_141A711B0), v22)),
          _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v23));
  v54 = _mm_mul_ps(_mm_sub_ps(_mm_add_ps(_mm_add_ps(v28, v28), v5->m_quad), v15), v55);
  hkUFloat8::getEncodedFloat(v27);
  if ( (_mm_movemask_ps(
          _mm_cmpltps(
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32((__m128i)_mm_sub_ps(v7->m_motion.m_linearVelocity.m_quad, v54), 1u),
                      1u),
            v9)) & 7) != 7 )
  {
    hkpEntity::activate((hkpEntity *)&v7->vfptr);
    v7->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v7->m_motion.vfptr, (unsigned int)&v54);
  }
  v29 = v8->m_vec.m_quad;
  v30 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v25), _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v29));
  v31 = _mm_sub_ps(_mm_shuffle_ps(v30, v30, 201), _mm_mul_ps(_mm_shuffle_ps(v29, v29, 255), v25));
  v32 = _mm_mul_ps(v8->m_vec.m_quad, v25);
  v33 = _mm_add_ps(v31, _mm_mul_ps(_mm_shuffle_ps(v25, v25, 255), v8->m_vec.m_quad));
  v34 = _mm_add_ps(_mm_shuffle_ps(v32, v32, 78), v32);
  v35 = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, _mm_add_ps(_mm_shuffle_ps(v34, v34, 177), v34)), 196);
  v36 = _mm_mul_ps(v35, v35);
  v37 = _mm_add_ps(_mm_shuffle_ps(v36, v36, 78), v36);
  v38 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 177), v37);
  v39 = _mm_rsqrt_ps(v38);
  v40 = _mm_mul_ps(
          v35,
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)), _mm_mul_ps(*(__m128 *)_xmm, v39)));
  v41 = _mm_mul_ps(v40, v40);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 170))) > 1.4210855e-14 )
  {
    v56 = a5;
    v42 = (__m128i)_mm_shuffle_ps(v40, v40, 255);
    v43 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
            _mm_shuffle_ps(v41, v41, 170));
    v44 = _mm_rsqrt_ps(v43);
    v45 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v42, 1u), 1u);
    v46 = _mm_andnot_ps(*(__m128 *)_xmm, v45);
    v47 = _mm_xor_ps(
            (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmpltps((__m128)v42, (__m128)0i64), 0x1Fu), 0x1Fu),
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmpleps(v43, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v44, v43), v44)),
                  _mm_mul_ps(*(__m128 *)_xmm, v44))),
              v40));
    v48 = _mm_cmpltps(v46, *(__m128 *)_xmm);
    v49 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v46), *(__m128 *)_xmm);
    v50 = _mm_cmpltps(*(__m128 *)_xmm, v46);
    v51 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v49), v50), _mm_andnot_ps(v50, v46));
    v52 = _mm_or_ps(_mm_andnot_ps(v50, _mm_mul_ps(v46, v46)), _mm_and_ps(v50, v49));
    v53 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v52, *(__m128 *)coeff4), *(__m128 *)coeff3), v52),
                          *(__m128 *)coeff2),
                        v52),
                      *(__m128 *)coeff1),
                    v52),
                  *(__m128 *)coeff0),
                v52),
              v51),
            v51);
    v53.m128_i32[0] = (*(unsigned __int128 *)&_mm_andnot_ps(
                                                v48,
                                                _mm_or_ps(
                                                  _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v53, v53)), v50),
                                                  _mm_andnot_ps(v50, v53))) | v48.m128_i32[0] & v46.m128_i32[0]) ^ v45.m128_i32[0] & _xmm[0];
    v54 = _mm_mul_ps(
            v47,
            _mm_mul_ps(
              _mm_shuffle_ps(
                (__m128)COERCE_UNSIGNED_INT((float)(1.5707964 - v53.m128_f32[0]) * 2.0),
                (__m128)COERCE_UNSIGNED_INT((float)(1.5707964 - v53.m128_f32[0]) * 2.0),
                0),
              v55));
  }
  else
  {
    v54 = 0i64;
  }
  hkUFloat8::getEncodedFloat(v7->m_motion.m_motionState.m_maxAngularVelocity.m_value);
  if ( (_mm_movemask_ps(
          _mm_cmpltps(
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32((__m128i)_mm_sub_ps(v7->m_motion.m_angularVelocity.m_quad, v54), 1u),
                      1u),
            v9)) & 7) != 7 )
  {
    hkpEntity::activate((hkpEntity *)&v7->vfptr);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v7->m_motion.vfptr[9].__first_virtual_table_function__)(
      &v7->m_motion,
      &v54);
  }
}

