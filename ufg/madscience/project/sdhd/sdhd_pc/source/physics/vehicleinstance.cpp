// File Line: 18
// RVA: 0x44E290
void __fastcall UFG::VehicleInstance::VehicleInstance(UFG::VehicleInstance *this, hkpRigidBody *chassis)
{
  hkVector4f axis; // [rsp+30h] [rbp-18h] BYREF

  hkpVehicleInstance::hkpVehicleInstance(this, chassis);
  this->vfptr = (hkBaseObjectVtbl *)&UFG::VehicleInstance::`vftable;
  axis.m_quad = (__m128)_xmm;
  hkQuaternionf::setAxisAngle(&this->mAxleFixup, &axis, 1.5707964);
}

// File Line: 33
// RVA: 0x459E50
void __fastcall UFG::VehicleInstance::CalcCurrentPositionAndRotation(
        UFG::VehicleInstance *this,
        hkpRigidBody *chassis,
        hkpVehicleSuspension *suspension,
        int wheelNo,
        hkVector4f *axlePosOut,
        hkQuaternionf *axleRotOut,
        hkQuaternionf *wheelRotOut,
        float minSuspensionLength,
        float maxSuspensionLength)
{
  hkpVehicleData *m_data; // rax
  __int64 v10; // rsi
  hkpVehicleInstance::WheelInfo *v14; // rbp
  float m_spinAngle; // xmm6_4
  __m128 m_quad; // xmm2
  hkQuaternionf v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm0
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  __m128 v22; // xmm4
  __m128 v23; // xmm6
  __m128 v24; // xmm6
  __m128 v25; // xmm5
  __m128 v26; // xmm4
  __m128 v27; // xmm6
  __m128 v28; // xmm3
  __m128 v29; // xmm7
  __m128 v30; // xmm2
  __m128 v31; // xmm7
  __m128 v32; // xmm7
  hkQuaternionf v33; // xmm2
  __m128 v34; // xmm4
  __m128 v35; // xmm3
  __m128 v36; // xmm5
  __m128 v37; // xmm2
  __m128 v38; // xmm5
  float v39; // xmm3_4
  hkVector4f v40; // xmm1
  __m128 v41; // xmm0
  __m128 v42; // xmm2
  __m128 v43; // xmm2
  hkQuaternionf quat; // [rsp+20h] [rbp-98h] BYREF
  hkVector4f direction; // [rsp+30h] [rbp-88h] BYREF
  hkVector4f axis; // [rsp+40h] [rbp-78h] BYREF
  hkRotationf r; // [rsp+50h] [rbp-68h] BYREF

  m_data = this->m_data;
  v10 = wheelNo;
  r.m_col0 = m_data->m_chassisOrientation.m_col1;
  v14 = &this->m_wheelsInfo.hkpVehicleInstance::m_data[wheelNo];
  r.m_col1 = m_data->m_chassisOrientation.m_col0;
  r.m_col2 = m_data->m_chassisOrientation.m_col2;
  hkQuaternionf::set(&quat, &r);
  m_spinAngle = v14->m_spinAngle;
  direction.m_quad = _xmm;
  hkVector4f::setRotatedInverseDir(&axis, &quat, &direction);
  hkQuaternionf::setAxisAngle(wheelRotOut, &axis, COERCE_FLOAT(LODWORD(m_spinAngle) ^ _xmm[0]));
  m_quad = v14->m_steeringOrientationChassisSpace.m_vec.m_quad;
  v17.m_vec.m_quad = (__m128)chassis->m_motion.m_motionState.m_sweptTransform.m_rotation1;
  v18 = _mm_shuffle_ps(v17.m_vec.m_quad, v17.m_vec.m_quad, 255);
  v19 = _mm_mul_ps(_mm_shuffle_ps(v17.m_vec.m_quad, v17.m_vec.m_quad, 201), m_quad);
  v20 = _mm_shuffle_ps(m_quad, m_quad, 255);
  v21 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v17.m_vec.m_quad);
  v22 = _mm_mul_ps(v17.m_vec.m_quad, m_quad);
  v23 = _mm_sub_ps(v21, v19);
  v24 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v23, v23, 201), _mm_mul_ps(m_quad, v18)),
          _mm_mul_ps(chassis->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad, v20));
  v25 = _mm_sub_ps(
          _mm_mul_ps(v20, v18),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
            _mm_shuffle_ps(v22, v22, 170)));
  v26 = _mm_shuffle_ps(quat.m_vec.m_quad, quat.m_vec.m_quad, 255);
  v27 = _mm_shuffle_ps(v24, _mm_unpackhi_ps(v24, v25), 196);
  v28 = _mm_shuffle_ps(v27, v27, 255);
  v29 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(quat.m_vec.m_quad, quat.m_vec.m_quad, 201), v27),
          _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), quat.m_vec.m_quad));
  v30 = _mm_mul_ps(quat.m_vec.m_quad, v27);
  v31 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v29, v29, 201), _mm_mul_ps(quat.m_vec.m_quad, v28)), _mm_mul_ps(v27, v26));
  v32 = _mm_shuffle_ps(
          v31,
          _mm_unpackhi_ps(
            v31,
            _mm_sub_ps(
              _mm_mul_ps(v26, v28),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                _mm_shuffle_ps(v30, v30, 170)))),
          196);
  *axleRotOut = (hkQuaternionf)v32;
  v33.m_vec.m_quad = (__m128)this->mAxleFixup;
  v34 = _mm_shuffle_ps(v33.m_vec.m_quad, v33.m_vec.m_quad, 255);
  v35 = _mm_shuffle_ps(v32, v32, 255);
  v36 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v33.m_vec.m_quad, v33.m_vec.m_quad, 201), v32),
          _mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), v33.m_vec.m_quad));
  v37 = _mm_mul_ps(v33.m_vec.m_quad, v32);
  v38 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v36, v36, 201), _mm_mul_ps(this->mAxleFixup.m_vec.m_quad, v35)),
          _mm_mul_ps(v32, v34));
  axleRotOut->m_vec.m_quad = _mm_shuffle_ps(
                               v38,
                               _mm_unpackhi_ps(
                                 v38,
                                 _mm_sub_ps(
                                   _mm_mul_ps(v34, v35),
                                   _mm_add_ps(
                                     _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
                                     _mm_shuffle_ps(v37, v37, 170)))),
                               196);
  v39 = fmaxf(0.0, v14->m_currentSuspensionLength);
  if ( v39 < minSuspensionLength )
    v39 = minSuspensionLength;
  if ( v39 > maxSuspensionLength )
    v39 = maxSuspensionLength;
  v40.m_quad = (__m128)suspension->m_wheelParams.m_data[v10].m_hardpointChassisSpace;
  v41 = _mm_mul_ps(
          _mm_shuffle_ps(v40.m_quad, v40.m_quad, 0),
          chassis->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad);
  v42 = _mm_add_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(v40.m_quad, v40.m_quad, 85),
            chassis->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
          v41);
  v41.m128_f32[0] = v39;
  v43 = _mm_add_ps(
          _mm_add_ps(
            v42,
            _mm_mul_ps(
              _mm_shuffle_ps(v40.m_quad, v40.m_quad, 170),
              chassis->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)),
          chassis->m_motion.m_motionState.m_transform.m_translation.m_quad);
  *axlePosOut = (hkVector4f)v43;
  axlePosOut->m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), v14->m_suspensionDirectionWs.m_quad), v43);
}

