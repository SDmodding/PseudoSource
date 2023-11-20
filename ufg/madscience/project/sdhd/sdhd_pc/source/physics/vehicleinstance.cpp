// File Line: 18
// RVA: 0x44E290
void __fastcall UFG::VehicleInstance::VehicleInstance(UFG::VehicleInstance *this, hkpRigidBody *chassis)
{
  UFG::VehicleInstance *v2; // rbx
  hkVector4f axis; // [rsp+30h] [rbp-18h]

  v2 = this;
  hkpVehicleInstance::hkpVehicleInstance((hkpVehicleInstance *)&this->vfptr, chassis);
  v2->vfptr = (hkBaseObjectVtbl *)&UFG::VehicleInstance::`vftable';
  axis.m_quad = (__m128)_xmm;
  hkQuaternionf::setAxisAngle(&v2->mAxleFixup, &axis, 1.5707964);
}

// File Line: 33
// RVA: 0x459E50
void __fastcall UFG::VehicleInstance::CalcCurrentPositionAndRotation(UFG::VehicleInstance *this, hkpRigidBody *chassis, hkpVehicleSuspension *suspension, int wheelNo, hkVector4f *axlePosOut, hkQuaternionf *axleRotOut, hkQuaternionf *wheelRotOut, float minSuspensionLength, float maxSuspensionLength)
{
  hkpVehicleData *v9; // rax
  __int64 v10; // rsi
  hkpRigidBody *v11; // rdi
  UFG::VehicleInstance *v12; // rbx
  hkpVehicleSuspension *v13; // r14
  __m128 *v14; // rbp
  float v15; // xmm6_4
  __m128 v16; // xmm2
  __m128 v17; // xmm4
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
  hkQuaternionf v32; // xmm7
  __m128 v33; // xmm2
  __m128 v34; // xmm4
  __m128 v35; // xmm3
  __m128 v36; // xmm5
  __m128 v37; // xmm2
  __m128 v38; // xmm5
  float v39; // xmm3_4
  __m128 v40; // xmm1
  __m128 v41; // xmm0
  __m128 v42; // xmm2
  hkVector4f v43; // xmm2
  hkQuaternionf quat; // [rsp+20h] [rbp-98h]
  hkVector4f direction; // [rsp+30h] [rbp-88h]
  hkVector4f axis; // [rsp+40h] [rbp-78h]
  hkRotationf r; // [rsp+50h] [rbp-68h]

  v9 = this->m_data;
  v10 = wheelNo;
  v11 = chassis;
  v12 = this;
  v13 = suspension;
  r.m_col0 = v9->m_chassisOrientation.m_col1;
  v14 = &this->m_wheelsInfo.m_data[wheelNo].m_contactPoint.m_position.m_quad;
  r.m_col1 = v9->m_chassisOrientation.m_col0;
  r.m_col2 = v9->m_chassisOrientation.m_col2;
  hkQuaternionf::set(&quat, &r);
  v15 = v14[12].m128_f32[2];
  direction.m_quad = _xmm;
  hkVector4f::setRotatedInverseDir(&axis, &quat, &direction);
  hkQuaternionf::setAxisAngle(wheelRotOut, &axis, COERCE_FLOAT(LODWORD(v15) ^ _xmm[0]));
  v16 = v14[11];
  v17 = v11->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
  v18 = _mm_shuffle_ps(v11->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad, v17, 255);
  v19 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v16);
  v20 = _mm_shuffle_ps(v14[11], v16, 255);
  v21 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v17);
  v22 = _mm_mul_ps(v17, v16);
  v23 = _mm_sub_ps(v21, v19);
  v24 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v23, v23, 201), _mm_mul_ps(v14[11], v18)),
          _mm_mul_ps(v11->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad, v20));
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
  v32.m_vec.m_quad = _mm_shuffle_ps(
                       v31,
                       _mm_unpackhi_ps(
                         v31,
                         _mm_sub_ps(
                           _mm_mul_ps(v26, v28),
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                             _mm_shuffle_ps(v30, v30, 170)))),
                       196);
  *axleRotOut = (hkQuaternionf)v32.m_vec.m_quad;
  v33 = v12->mAxleFixup.m_vec.m_quad;
  v34 = _mm_shuffle_ps(v12->mAxleFixup.m_vec.m_quad, v33, 255);
  v35 = _mm_shuffle_ps(v32.m_vec.m_quad, v32.m_vec.m_quad, 255);
  v36 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v12->mAxleFixup.m_vec.m_quad, v33, 201), v32.m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v32.m_vec.m_quad, v32.m_vec.m_quad, 201), v33));
  v37 = _mm_mul_ps(v33, v32.m_vec.m_quad);
  v38 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v36, v36, 201), _mm_mul_ps(v12->mAxleFixup.m_vec.m_quad, v35)),
          _mm_mul_ps(v32.m_vec.m_quad, v34));
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
  v39 = fmaxf(0.0, v14[7].m128_f32[0]);
  if ( v39 < minSuspensionLength )
    v39 = minSuspensionLength;
  if ( v39 > maxSuspensionLength )
    v39 = maxSuspensionLength;
  v40 = v13->m_wheelParams.m_data[v10].m_hardpointChassisSpace.m_quad;
  v41 = _mm_mul_ps(
          _mm_shuffle_ps(v13->m_wheelParams.m_data[v10].m_hardpointChassisSpace.m_quad, v40, 0),
          v11->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad);
  v42 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v40, v40, 85), v11->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
          v41);
  v41.m128_f32[0] = v39;
  v43.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   v42,
                   _mm_mul_ps(
                     _mm_shuffle_ps(v40, v40, 170),
                     v11->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)),
                 v11->m_motion.m_motionState.m_transform.m_translation.m_quad);
  *axlePosOut = (hkVector4f)v43.m_quad;
  axlePosOut->m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), v14[8]), v43.m_quad);
}

