// File Line: 20
// RVA: 0xC52D00
void __fastcall hkaRagdollPoweredConstraintController::startMotors(hkaRagdollInstance *ragdoll)
{
  hkaRagdollInstance *v1; // rbp
  __int64 v2; // r14
  __int64 i; // rdi
  int v4; // ecx
  hkpConstraintInstance *v5; // rsi
  hkpConstraintData *v6; // rbx
  int v7; // eax

  v1 = ragdoll;
  v2 = ragdoll->m_skeleton.m_pntr->m_bones.m_size;
  for ( i = 0i64; i < v2; ++i )
  {
    v4 = v1->m_boneToRigidBodyMap.m_data[i] - 1;
    if ( v4 >= 0 )
    {
      v5 = v1->m_constraints.m_data[v4];
      if ( v5 )
      {
        v6 = v5->m_data;
        if ( v6 )
        {
          v7 = ((__int64 (__fastcall *)(hkpConstraintData *))v6->vfptr[1].__first_virtual_table_function__)(v5->m_data);
          if ( v7 == 2 )
          {
            hkpLimitedHingeConstraintData::setMotorEnabled(
              (hkpLimitedHingeConstraintData *)v6,
              v5->m_internal->m_runtime,
              (hkBool)1);
            *(_DWORD *)(&v6[8].m_referenceCount + 1) = 0;
          }
          else if ( v7 == 7 )
          {
            hkpRagdollConstraintData::setMotorsEnabled(
              (hkpRagdollConstraintData *)v6,
              v5->m_internal->m_runtime,
              (hkBool)1);
            hkpRagdollConstraintData::setTargetRelativeOrientationOfBodies(
              (hkpRagdollConstraintData *)v6,
              (hkRotationf *)&transform);
          }
        }
      }
    }
  }
}

// File Line: 76
// RVA: 0xC52DD0
void __fastcall hkaRagdollPoweredConstraintController::stopMotors(hkaRagdollInstance *ragdoll)
{
  __int64 v1; // rbx
  hkaRagdollInstance *v2; // rbp
  __int64 v3; // r14
  int v4; // edx
  hkpConstraintInstance *v5; // rsi
  hkpLimitedHingeConstraintData *v6; // rdi
  int v7; // eax

  v1 = 0i64;
  v2 = ragdoll;
  v3 = ragdoll->m_skeleton.m_pntr->m_bones.m_size;
  if ( v3 > 0 )
  {
    do
    {
      v4 = v2->m_boneToRigidBodyMap.m_data[v1] - 1;
      if ( v4 >= 0 )
      {
        v5 = v2->m_constraints.m_data[v4];
        if ( v5 )
        {
          v6 = (hkpLimitedHingeConstraintData *)v5->m_data;
          if ( v6 )
          {
            v7 = ((__int64 (__fastcall *)(hkpConstraintData *))v6->vfptr[1].__first_virtual_table_function__)(v5->m_data);
            if ( v7 == 2 )
            {
              hkpLimitedHingeConstraintData::setMotorEnabled(v6, v5->m_internal->m_runtime, 0);
            }
            else if ( v7 == 7 )
            {
              hkpRagdollConstraintData::setMotorsEnabled((hkpRagdollConstraintData *)v6, v5->m_internal->m_runtime, 0);
            }
          }
        }
      }
      ++v1;
    }
    while ( v1 < v3 );
  }
}

// File Line: 113
// RVA: 0xC52AF0
void __fastcall hkaRagdollPoweredConstraintController::driveToPose(hkaRagdollInstance *ragdoll, hkQsTransformf *desiredPose)
{
  __int64 v2; // rdi
  hkaRagdollInstance *v3; // rbp
  __int64 v4; // r14
  hkQuaternionf *v5; // rsi
  int v6; // ecx
  hkpConstraintInstance *v7; // rbx
  hkpRagdollConstraintData *v8; // rbx
  int v9; // eax
  __m128 v10; // xmm4
  __m128 v11; // xmm5
  __m128 v12; // xmm6
  __m128 v13; // xmm3
  __m128 v14; // xmm6
  __m128 v15; // xmm6
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  hkQuaternionf v20; // [rsp+20h] [rbp-98h]
  hkQuaternionf v21; // [rsp+30h] [rbp-88h]
  hkQuaternionf v22; // [rsp+40h] [rbp-78h]
  hkSimdFloat32 angleOut; // [rsp+50h] [rbp-68h]
  hkQuaternionf restOut; // [rsp+60h] [rbp-58h]
  hkRotationf target_bRa; // [rsp+70h] [rbp-48h]

  v2 = 0i64;
  v3 = ragdoll;
  v4 = ragdoll->m_skeleton.m_pntr->m_bones.m_size;
  if ( v4 > 0 )
  {
    v5 = &desiredPose->m_rotation;
    do
    {
      v6 = v3->m_boneToRigidBodyMap.m_data[v2] - 1;
      if ( v6 >= 0 )
      {
        v7 = v3->m_constraints.m_data[v6];
        if ( v7 )
        {
          v8 = (hkpRagdollConstraintData *)v7->m_data;
          v9 = ((__int64 (__fastcall *)(hkpRagdollConstraintData *))v8->vfptr[1].__first_virtual_table_function__)(v8);
          if ( v9 == 2 )
          {
            if ( v8->m_atoms.m_ragdollMotors.m_isEnabled.m_bool )
            {
              hkQuaternionf::set(&v20, &v8->m_atoms.m_transforms.m_transformA.m_rotation);
              hkQuaternionf::set(&v21, &v8->m_atoms.m_transforms.m_transformB.m_rotation);
              v10 = _mm_shuffle_ps(v5->m_vec.m_quad, v5->m_vec.m_quad, 255);
              v11 = _mm_shuffle_ps(v20.m_vec.m_quad, v20.m_vec.m_quad, 255);
              v12 = _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v20.m_vec.m_quad, v20.m_vec.m_quad, 201), v5->m_vec.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v5->m_vec.m_quad, v5->m_vec.m_quad, 201), v20.m_vec.m_quad));
              v13 = _mm_mul_ps(v20.m_vec.m_quad, v5->m_vec.m_quad);
              v14 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v12, v12, 201), _mm_mul_ps(v20.m_vec.m_quad, v10)),
                      _mm_mul_ps(v11, v5->m_vec.m_quad));
              v15 = _mm_shuffle_ps(
                      v14,
                      _mm_unpackhi_ps(
                        v14,
                        _mm_sub_ps(
                          _mm_mul_ps(v11, v10),
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                            _mm_shuffle_ps(v13, v13, 170)))),
                      196);
              v16 = _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v21.m_vec.m_quad, v21.m_vec.m_quad, 201), v15),
                      _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v21.m_vec.m_quad));
              v17 = _mm_mul_ps(v21.m_vec.m_quad, v15);
              v18 = _mm_sub_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v21.m_vec.m_quad, v21.m_vec.m_quad, 255), v15),
                        _mm_shuffle_ps(v16, v16, 201)),
                      _mm_mul_ps(_mm_shuffle_ps(v15, v15, 255), v21.m_vec.m_quad));
              v19 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 78), v17);
              v22.m_vec.m_quad = _mm_shuffle_ps(
                                   v18,
                                   _mm_unpackhi_ps(v18, _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19)),
                                   196);
              hkQuaternionf::decomposeRestAxis(&v22, &transform, &restOut, &angleOut);
              *(_DWORD *)(&v8->m_atoms.m_ragdollMotors.m_previousTargetAnglesOffset + 3) = angleOut.m_real.m128_i32[0];
            }
          }
          else if ( v9 == 7 )
          {
            if ( v8->m_atoms.m_ragdollMotors.m_isEnabled.m_bool )
            {
              hkRotationf::set(&target_bRa, v5);
              hkpRagdollConstraintData::setTargetRelativeOrientationOfBodies(v8, &target_bRa);
            }
          }
        }
      }
      ++v2;
      v5 += 3;
    }
    while ( v2 < v4 );
  }
}

