// File Line: 22
// RVA: 0xE2CAE0
void __fastcall hkpVehicleDefaultSimulation::hkpVehicleDefaultSimulation(hkpVehicleDefaultSimulation *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleDefaultSimulation::`vftable;
  *(_QWORD *)&this->m_frictionStatus.m_axis[0].m_forward_slip_velocity = 0i64;
  *(_QWORD *)&this->m_frictionStatus.m_axis[0].m_skid_energy_density = 0i64;
  *(_QWORD *)&this->m_frictionStatus.m_axis[0].m_delayed_forward_impulse = 0i64;
  *(_QWORD *)&this->m_frictionStatus.m_axis[0].m_forwardRhs = 0i64;
  *(_QWORD *)&this->m_frictionStatus.m_axis[0].m_relativeForwardForce = 0i64;
  this->m_frictionDescription.m_pntr = 0i64;
  *(_QWORD *)&this->m_frictionStatus.m_axis[1].m_side_slip_velocity = 0i64;
  *(_QWORD *)&this->m_frictionStatus.m_axis[1].m_side_force = 0i64;
  *(_QWORD *)&this->m_frictionStatus.m_axis[1].m_sideRhs = 0i64;
  *(_QWORD *)&this->m_frictionStatus.m_axis[1].m_relativeSideForce = 0i64;
}

// File Line: 29
// RVA: 0xE2CDB0
void __fastcall hkpVehicleDefaultSimulation::simulateVehicle(hkpVehicleDefaultSimulation *this, hkpVehicleInstance *instance, hkStepInfo *stepInfo, hkpVehicleSimulation::SimulationInput *simulInput)
{
  hkArray<float,hkContainerHeapAllocator> *v4; // r13
  hkpVehicleInstance *v5; // r14
  hkArray<float,hkContainerHeapAllocator> *totalLinearForceAtWheel; // rdx
  hkStepInfo *v7; // r12
  hkVector4f *v8; // rsi
  hkpVehicleDefaultSimulation *v9; // rdi
  char *v10; // rax
  signed __int64 v11; // rcx
  float v12; // xmm6_4
  float v13; // xmm2_4
  hkpVehicleJobResults *v14; // r15
  hkpVehicleData *v15; // rbx
  signed int v16; // er10
  __m128 v17; // xmm1
  float v18; // xmm4_4
  hkBool *v19; // r11
  __int64 v20; // r9
  signed __int64 v21; // rdx
  __int64 v22; // rcx
  __int64 v23; // r8
  float v24; // xmm1_4
  __m128 v25; // xmm1
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  hkpRigidBody *groundBodies; // [rsp+50h] [rbp-88h]
  __int64 v32; // [rsp+58h] [rbp-80h]
  hkVector4f originalAngularVels; // [rsp+60h] [rbp-78h]
  hkVector4f originalLinearVels; // [rsp+70h] [rbp-68h]
  hkpVehicleFrictionSolverParams frictionParams; // [rsp+88h] [rbp-50h]
  hkpVelocityAccumulator groundAccum; // [rsp+258h] [rbp+180h]
  hkpVelocityAccumulator groundAccumAtIntegration; // [rsp+358h] [rbp+280h]
  char v38; // [rsp+458h] [rbp+380h]
  hkpVehicleAerodynamics::AerodynamicsDragOutput *aerodynamicsDragInfo; // [rsp+708h] [rbp+630h]
  hkpVehicleJobResults *retaddr; // [rsp+728h] [rbp+650h]

  v4 = simulInput->suspensionForceAtWheel;
  v5 = instance;
  totalLinearForceAtWheel = simulInput->totalLinearForceAtWheel;
  v7 = stepInfo;
  v8 = (hkVector4f *)v5->m_data;
  aerodynamicsDragInfo = simulInput->aerodynamicsDragInfo;
  v9 = this;
  v10 = (char *)&frictionParams.m_axleParams[0].m_maxFrictionCoefficient;
  v11 = 2i64;
  do
  {
    *((_OWORD *)v10 - 2) = 0i64;
    *((_OWORD *)v10 - 1) = 0i64;
    *(_OWORD *)v10 = 0i64;
    *((_QWORD *)v10 + 4) = 0i64;
    *((_QWORD *)v10 + 5) = 0i64;
    *((_QWORD *)v10 + 6) = 0i64;
    v10[56] = 0;
    *((_QWORD *)v10 + 2) = 0i64;
    *((_QWORD *)v10 + 3) = 0i64;
    v10 += 96;
    --v11;
  }
  while ( v11 );
  v12 = stepInfo->m_deltaTime.m_storage;
  v13 = stepInfo->m_deltaTime.m_storage;
  groundBodies = 0i64;
  v32 = 0i64;
  hkpVehicleDefaultSimulation::prepareAxleParams(
    v9,
    v5,
    v13,
    v4,
    totalLinearForceAtWheel,
    &groundBodies,
    &frictionParams,
    stepInfo,
    &groundAccum,
    &groundAccumAtIntegration);
  hkpVehicleDefaultSimulation::prepareChassisParams(v9, v5, v7, &frictionParams);
  v14 = (hkpVehicleJobResults *)&v38;
  if ( retaddr )
    v14 = retaddr;
  hkpVehicleDefaultSimulation::applyAerodynamicDrag(v9, v5, aerodynamicsDragInfo, &frictionParams, v12);
  hkpVehicleDefaultSimulation::applyVelocityDamping(v9, v12, &frictionParams, v5->m_velocityDamper);
  hkpVehicleDefaultSimulation::applySuspensionForces(
    v9,
    v5,
    v12,
    v4,
    &groundBodies,
    &frictionParams,
    v14->m_groundBodyImpulses);
  hkpVehicleDefaultSimulation::applyDampingToAxleAccumulators(
    v9,
    v7,
    &groundBodies,
    &frictionParams,
    &originalLinearVels,
    (hkVector4f *)((char *)&originalAngularVels + 8));
  hkpVehicleDefaultSimulation::applyDampingToChassisAccumulator(
    v9,
    v7,
    &frictionParams.m_chassis,
    (hkpMotion *)&v5->m_entity->m_motion.vfptr);
  hkpVehicleDefaultSimulation::getExtraTorqueFactor(v9, v5, v12, &frictionParams.m_chassis);
  hkpVehicleDefaultSimulation::applyFrictionSolver(v9, v5, v7, &frictionParams, &v9->m_frictionStatus);
  hkpVehicleDefaultSimulation::calcChassisVelocities(v9, v5, &frictionParams.m_chassis, v14);
  hkpVehicleDefaultSimulation::calcGroundBodyVelocities(
    v9,
    v5,
    v12,
    frictionParams.m_axleParams,
    &groundBodies,
    v14,
    &originalLinearVels,
    (hkVector4f *)((char *)&originalAngularVels + 8));
  if ( !retaddr )
    hkpVehicleJobResults::applyForcesFromStep(v14, v5);
  hkVector4f::setRotatedDir(
    &originalAngularVels,
    (hkMatrix3f *)&v5->m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col0,
    v8 + 4);
  v15 = v5->m_data;
  v16 = 0;
  v17 = _mm_mul_ps(frictionParams.m_chassis.m_linearVel.m_quad, originalAngularVels.m_quad);
  v18 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 170));
  if ( v15->m_numWheels )
  {
    v19 = v5->m_isFixed.m_data;
    v20 = 0i64;
    v21 = (signed __int64)&v5->m_wheelsInfo.m_data->m_spinAngle;
    while ( 1 )
    {
      v22 = *(char *)(v20 + v8[9].m_quad.m128_u64[0] + 36);
      v23 = v22;
      v22 *= 9i64;
      *(_DWORD *)(v21 + 12) = *((_DWORD *)&v9->m_frictionStatus.m_axis[0].m_forward_slip_velocity + v22);
      *(_DWORD *)(v21 + 8) = *((_DWORD *)&v9->m_frictionStatus.m_axis[0].m_side_force + v22);
      *(_DWORD *)(v21 + 16) = *((_DWORD *)&v9->m_frictionStatus.m_axis[0].m_side_slip_velocity + v22);
      *(_DWORD *)(v21 + 4) = *((_DWORD *)&v9->m_frictionStatus.m_axis[0].m_skid_energy_density + v22);
      if ( v19->m_bool )
      {
        *(_QWORD *)(v21 - 8) = 0i64;
      }
      else
      {
        v24 = v18;
        if ( *(&groundBodies + v23) )
        {
          v25 = _mm_mul_ps(
                  originalAngularVels.m_quad,
                  frictionParams.m_axleParams[v23].m_groundObject->m_linearVel.m_quad);
          v24 = v18
              - (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 0)))
                      + COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 170)));
        }
        v26 = v24;
        v27 = v24 + *(float *)(v21 + 12);
        *(float *)(v21 - 4) = v26 / *(float *)(v20 + v8[9].m_quad.m128_u64[0]);
        v28 = v27 / *(float *)(v20 + v8[9].m_quad.m128_u64[0]);
        *(float *)(v21 - 8) = v28;
        *(float *)v21 = (float)(v28 * v12) + *(float *)v21;
      }
      v29 = *(float *)v21;
      if ( *(float *)v21 > 3141.5928 )
        break;
      if ( v29 < -3141.5928 )
      {
        v30 = v29 + 3141.5928;
        goto LABEL_18;
      }
LABEL_19:
      ++v16;
      ++v19;
      v20 += 40i64;
      v21 += 224i64;
      if ( v16 >= (unsigned __int8)v15->m_numWheels )
        return;
    }
    v30 = v29 - 3141.5928;
LABEL_18:
    *(float *)v21 = v30;
    goto LABEL_19;
  }
}

// File Line: 148
// RVA: 0xE2D180
void __fastcall hkpVehicleDefaultSimulation::prepareAxleParams(hkpVehicleDefaultSimulation *this, hkpVehicleInstance *vehicleInstance, float deltaTime, hkArray<float,hkContainerHeapAllocator> *suspensionForceAtWheel, hkArray<float,hkContainerHeapAllocator> *totalLinearForceAtWheel, hkpRigidBody **groundBody, hkpVehicleFrictionSolverParams *frictionParams, hkStepInfo *stepInfo, hkpVelocityAccumulator *groundAccum, hkpVelocityAccumulator *groundAccumAtIntegration)
{
  hkpVehicleFrictionSolverParams *v10; // r15
  hkArray<float,hkContainerHeapAllocator> *v11; // r10
  hkpVehicleDefaultSimulation *v12; // r9
  hkpVehicleData *v13; // rcx
  int v14; // esi
  hkpVehicleInstance *v15; // rdi
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  float estimatedCarSpeed; // xmm7_4
  __int64 v20; // rbx
  __int64 v21; // rbp
  __int64 v22; // r14
  __int64 v23; // r8
  hkpRigidBody *v24; // rcx
  hkpRigidBody *v25; // rdx
  int v26; // er14
  hkpVelocityAccumulator *v27; // rdx
  hkpRigidBody **v28; // r13
  hkEnum<enum hkpVelocityAccumulator::hkpAccumulatorContext,unsigned char> *v29; // rbx
  __m128 *v30; // rbp
  signed __int64 v31; // rsi
  __m128 v32; // xmm5
  signed __int64 v33; // rcx
  hkpVelocityAccumulator *v34; // rcx
  __m128 v35; // xmm1
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  __m128 v39; // xmm3
  __m128 v40; // xmm2
  hkpRigidBody *v41; // rax
  hkpVehicleFrictionSolverParams *v42; // rcx
  __m128 v43; // xmm4
  __m128 v44; // xmm2
  __m128 v45; // xmm3
  __m128 v46; // xmm1
  __m128 v47; // xmm3
  __m128 v48; // xmm2
  __m128 v49; // xmm0
  __m128 v50; // xmm3
  __m128 v51; // xmm2
  __m128 v52; // xmm3
  char *v53; // rax
  __m128 v54; // xmm1
  __m128 v55; // xmm0
  __m128 v56; // xmm2
  hkpVehicleDefaultSimulation *v57; // [rsp+C0h] [rbp+8h]
  signed __int64 v58; // [rsp+C8h] [rbp+10h]
  hkArray<float,hkContainerHeapAllocator> *v59; // [rsp+D8h] [rbp+20h]

  v59 = suspensionForceAtWheel;
  v57 = this;
  v10 = frictionParams;
  v11 = suspensionForceAtWheel;
  v12 = this;
  v13 = vehicleInstance->m_data;
  v14 = 0;
  v15 = vehicleInstance;
  v16 = _mm_mul_ps(
          vehicleInstance->m_entity->m_motion.m_linearVelocity.m_quad,
          vehicleInstance->m_entity->m_motion.m_linearVelocity.m_quad);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_rsqrt_ps(v17);
  LODWORD(estimatedCarSpeed) = (unsigned __int128)_mm_andnot_ps(
                                                    _mm_cmpleps(v17, (__m128)0i64),
                                                    _mm_mul_ps(
                                                      _mm_mul_ps(
                                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                                                        _mm_mul_ps(v18, *(__m128 *)_xmm)),
                                                      v17));
  if ( v13->m_numWheels > 0 )
  {
    v20 = 0i64;
    v21 = 0i64;
    v22 = 0i64;
    do
    {
      v23 = v13->m_wheelParams.m_data[v22].m_axle;
      v24 = v15->m_wheelsInfo.m_data[v21].m_contactBody;
      if ( v24 )
      {
        v25 = groundBody[v23];
        if ( !v25
          || COERCE_FLOAT(_mm_shuffle_ps(v24->m_motion.m_inertiaAndMassInv.m_quad, v24->m_motion.m_inertiaAndMassInv.m_quad, 255)) < COERCE_FLOAT(_mm_shuffle_ps(v25->m_motion.m_inertiaAndMassInv.m_quad, v25->m_motion.m_inertiaAndMassInv.m_quad, 255)) )
        {
          groundBody[v23] = v24;
        }
      }
      hkpVehicleDefaultSimulation::getAxleParamsFromWheel(
        v12,
        v15,
        v14,
        totalLinearForceAtWheel->m_data[v20],
        v11->m_data[v20],
        estimatedCarSpeed,
        &v10->m_axleParams[v23]);
      v13 = v15->m_data;
      v12 = v57;
      v11 = v59;
      ++v14;
      ++v22;
      ++v21;
      ++v20;
    }
    while ( v14 < v13->m_numWheels );
  }
  v26 = 0;
  v10->m_maxVelocityForPositionalFriction = v15->m_data->m_maxVelocityForPositionalFriction;
  if ( v15->m_data->m_numWheelsPerAxle.m_size > 0 )
  {
    v27 = groundAccum;
    v28 = groundBody;
    v29 = &groundAccum->m_context;
    v30 = &v10->m_axleParams[0].m_forwardDirWs.m_quad;
    v31 = (char *)groundAccumAtIntegration - (char *)groundAccum;
    do
    {
      v32 = v30[-1];
      v33 = (signed __int64)v26 << 7;
      v58 = v33;
      v34 = (hkpVelocityAccumulator *)((char *)v27 + v33);
      v35 = _mm_mul_ps(v32, v32);
      v36 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
              _mm_shuffle_ps(v35, v35, 170));
      v37 = _mm_rsqrt_ps(v36);
      v30[-1] = _mm_mul_ps(
                  _mm_andnot_ps(
                    _mm_cmpleps(v36, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v37, v36), v37)),
                      _mm_mul_ps(v37, *(__m128 *)_xmm))),
                  v32);
      v38 = _mm_mul_ps(*v30, *v30);
      v39 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
              _mm_shuffle_ps(v38, v38, 170));
      v40 = _mm_rsqrt_ps(v39);
      *v30 = _mm_mul_ps(
               _mm_andnot_ps(
                 _mm_cmpleps(v39, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v40, v39), v40)),
                   _mm_mul_ps(v40, *(__m128 *)_xmm))),
               *v30);
      v41 = *v28;
      v30[1].m128_u64[0] = (unsigned __int64)v34;
      v30[1].m128_u64[1] = (unsigned __int64)v34;
      if ( v41 )
      {
        if ( v41->m_motion.m_type.m_storage == 5 )
        {
          hkpVehicleDefaultSimulation::handleFixedGroundAccum(v12, v41, v34);
LABEL_20:
          v27 = groundAccum;
          goto LABEL_21;
        }
        if ( v26 <= 0 || v41 != *groundBody )
        {
          frictionParams = (hkpVehicleFrictionSolverParams *)&v41->m_motion;
          hkRigidMotionUtilBuildAccumulators(stepInfo, (hkpMotion *const *)&frictionParams, 1, 0i64, v34);
          v42 = frictionParams;
          v43 = _mm_shuffle_ps(
                  v15->m_entity->m_motion.m_inertiaAndMassInv.m_quad,
                  v15->m_entity->m_motion.m_inertiaAndMassInv.m_quad,
                  255);
          v44 = _mm_shuffle_ps(
                  *(__m128 *)&frictionParams->m_chassis.m_type.m_storage,
                  *(__m128 *)&frictionParams->m_chassis.m_type.m_storage,
                  255);
          v45 = _mm_shuffle_ps(
                  (__m128)LODWORD(v15->m_data->m_maxFrictionSolverMassRatio),
                  (__m128)LODWORD(v15->m_data->m_maxFrictionSolverMassRatio),
                  0);
          if ( (float)(v45.m128_f32[0] * v43.m128_f32[0]) < v44.m128_f32[0] )
          {
            v46 = _mm_rcp_ps(v44);
            *(__m128 *)&v29[47].m_storage = _mm_mul_ps(
                                              _mm_mul_ps(
                                                v45,
                                                _mm_mul_ps(
                                                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v46, v44)), v46),
                                                  v43)),
                                              *(__m128 *)&v29[47].m_storage);
          }
          v47 = v42->m_axleParams[1].m_constraintNormalWs.m_quad;
          v48 = *(__m128 *)&v42->m_axleParams[1].m_forwardForce;
          v49 = _mm_shuffle_ps(v47, v47, 255);
          v50 = _mm_sub_ps(v47, v42->m_axleParams[1].m_contactPointWs.m_quad);
          v29[v31 - 1] = v29[-1];
          v51 = _mm_mul_ps(v48, v49);
          v29[v31] = (hkEnum<enum hkpVelocityAccumulator::hkpAccumulatorContext,unsigned char>)v29->m_storage;
          v52 = _mm_mul_ps(v50, v49);
          *(_DWORD *)&v29[v31 + 3].m_storage = *(_DWORD *)&v29[3].m_storage;
          *(_DWORD *)&v29[v31 + 7].m_storage = *(_DWORD *)&v29[7].m_storage;
          v53 = &groundAccumAtIntegration->m_type.m_storage + v58;
          *(_OWORD *)&v29[v31 + 15].m_storage = *(_OWORD *)&v29[15].m_storage;
          *(_OWORD *)&v29[v31 + 31].m_storage = *(_OWORD *)&v29[31].m_storage;
          *(_OWORD *)&v29[v31 + 47].m_storage = *(_OWORD *)&v29[47].m_storage;
          *(_OWORD *)&v29[v31 + 63].m_storage = *(_OWORD *)&v29[63].m_storage;
          *(_OWORD *)&v29[v31 + 79].m_storage = *(_OWORD *)&v29[79].m_storage;
          *(_OWORD *)&v29[v31 + 95].m_storage = *(_OWORD *)&v29[95].m_storage;
          *(_OWORD *)&v29[v31 + 111].m_storage = *(_OWORD *)&v29[111].m_storage;
          v30[1].m128_u64[1] = (unsigned __int64)v53;
          v54 = _mm_mul_ps(_mm_shuffle_ps(v51, v51, 85), *(__m128 *)&v29[79].m_storage);
          v55 = _mm_mul_ps(_mm_shuffle_ps(v51, v51, 0), *(__m128 *)&v29[63].m_storage);
          v56 = _mm_mul_ps(_mm_shuffle_ps(v51, v51, 170), *(__m128 *)&v29[95].m_storage);
          *(__m128 *)&v29[v31 + 15].m_storage = v52;
          *(__m128 *)&v29[v31 + 31].m_storage = _mm_add_ps(_mm_add_ps(v54, v55), v56);
          goto LABEL_20;
        }
        v30[1].m128_u64[0] = (unsigned __int64)v10->m_axleParams[0].m_groundObject;
        v30[1].m128_u64[1] = (unsigned __int64)v10->m_axleParams[0].m_groundObjectAtLastIntegration;
      }
      else
      {
        *(_WORD *)&v29[-1].m_storage = 1;
        *(_DWORD *)&v29[7].m_storage = 0;
        *(_OWORD *)&v29[47].m_storage = 0i64;
        *(_OWORD *)&v29[15].m_storage = 0i64;
        *(_OWORD *)&v29[31].m_storage = 0i64;
        *(_OWORD *)&v29[111].m_storage = 0i64;
        *(hkVector4f *)&v29[63].m_storage = (hkVector4f)transform.m_quad;
        *(hkVector4f *)&v29[79].m_storage = (hkVector4f)direction.m_quad;
        *(hkVector4f *)&v29[95].m_storage = (hkVector4f)stru_141A71280.m_quad;
      }
LABEL_21:
      v12 = v57;
      ++v26;
      v30 += 6;
      ++v28;
      v29 += 128;
    }
    while ( v26 < v15->m_data->m_numWheelsPerAxle.m_size );
  }
}

// File Line: 239
// RVA: 0xE2D640
void __fastcall hkpVehicleDefaultSimulation::handleFixedGroundAccum(hkpVehicleDefaultSimulation *this, hkpRigidBody *ground, hkpVelocityAccumulator *accum)
{
  *(_WORD *)&accum->m_type.m_storage = 1;
  accum->m_gravityFactor = 0.0;
  accum->m_invMasses = 0i64;
  accum->m_linearVel = 0i64;
  accum->m_angularVel = 0i64;
  accum->m_scratch3 = 0i64;
  accum->m_scratch0 = (hkVector4f)transform.m_quad;
  accum->m_scratch1 = (hkVector4f)direction.m_quad;
  accum->m_scratch2 = (hkVector4f)stru_141A71280.m_quad;
}

// File Line: 246
// RVA: 0xE2D690
void __fastcall hkpVehicleDefaultSimulation::getAxleParamsFromWheel(hkpVehicleDefaultSimulation *this, hkpVehicleInstance *vehicleInstance, int w_it, float linearForceAtWheel, float suspensionForceAtWheel, float estimatedCarSpeed, hkpVehicleFrictionSolverAxleParams *axle_params)
{
  hkpVehicleInstance::WheelInfo *v7; // r10
  hkpVehicleData *v8; // rbx
  __int64 v9; // r9
  float v10; // xmm8_4
  __int64 v11; // r11
  __int64 v12; // rcx
  signed __int64 v13; // r8
  __m128 v14; // xmm7
  __m128 v15; // xmm3
  __m128 v16; // xmm6
  __m128 v17; // xmm4
  __m128 v18; // xmm5
  __m128 v19; // xmm5
  __m128 v20; // xmm2
  __m128 v21; // xmm5
  __m128 v22; // xmm1
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  __m128 v25; // xmm5
  __m128 v26; // xmm6
  float v27; // xmm0_4
  float v28; // xmm2_4
  __m128 v29; // xmm0
  hkpVehicleFrictionSolverAxleParams *v30; // r8
  bool v31; // zf
  float v32; // xmm8_4
  bool v33; // al

  v7 = vehicleInstance->m_wheelsInfo.m_data;
  v8 = vehicleInstance->m_data;
  v9 = w_it;
  v10 = linearForceAtWheel;
  v11 = w_it;
  v12 = v8->m_wheelParams.m_data[w_it].m_axle;
  v13 = w_it;
  v14 = v7[v13].m_contactPoint.m_separatingNormal.m_quad;
  v15 = v7[v13].m_spinAxisWs.m_quad;
  v16 = _mm_shuffle_ps(v14, v14, 201);
  v17 = _mm_shuffle_ps(v15, v15, 201);
  v18 = _mm_sub_ps(_mm_mul_ps(v7[v13].m_contactPoint.m_separatingNormal.m_quad, v17), _mm_mul_ps(v16, v15));
  v19 = _mm_shuffle_ps(v18, v18, 201);
  v20 = _mm_mul_ps(v19, v19);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 170))) < 0.00000011920929 )
  {
    v21 = _mm_sub_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(v7[v13].m_suspensionDirectionWs.m_quad, v7[v13].m_suspensionDirectionWs.m_quad, 201),
              v15),
            _mm_mul_ps(v7[v13].m_suspensionDirectionWs.m_quad, v17));
    v19 = _mm_shuffle_ps(v21, v21, 201);
  }
  v22 = _mm_mul_ps(v19, v19);
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)), _mm_shuffle_ps(v22, v22, 170));
  v24 = _mm_rsqrt_ps(v23);
  v25 = _mm_mul_ps(
          v19,
          _mm_andnot_ps(
            _mm_cmpleps(v23, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
              _mm_mul_ps(*(__m128 *)_xmm, v24))));
  v26 = _mm_sub_ps(_mm_mul_ps(v16, v25), _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v14));
  v27 = (float)v8->m_numWheelsPerAxle.m_data[v12];
  v28 = 1.0 / v27;
  v22.m128_f32[0] = (float)(1.0 / v27) * v7[v13].m_contactFriction;
  v29 = _mm_mul_ps(
          _mm_shuffle_ps((__m128)COERCE_UNSIGNED_INT(1.0 / v27), (__m128)COERCE_UNSIGNED_INT(1.0 / v27), 0),
          v7[v13].m_contactPoint.m_position.m_quad);
  v30 = axle_params;
  axle_params->m_contactPointWs.m_quad = _mm_add_ps(v29, axle_params->m_contactPointWs.m_quad);
  axle_params->m_constraintNormalWs.m_quad = _mm_add_ps(
                                               _mm_shuffle_ps(v26, v26, 201),
                                               axle_params->m_constraintNormalWs.m_quad);
  axle_params->m_forwardDirWs.m_quad = _mm_add_ps(v25, axle_params->m_forwardDirWs.m_quad);
  v31 = axle_params->m_wheelFixed == 0;
  v32 = v10 + axle_params->m_forwardForce;
  v30->m_frictionCoefficient = (float)(v22.m128_f32[0] * vehicleInstance->m_data->m_wheelParams.m_data[v11].m_friction)
                             + v30->m_frictionCoefficient;
  v30->m_viscosityFrictionCoefficient = (float)(v22.m128_f32[0]
                                              * vehicleInstance->m_data->m_wheelParams.m_data[v11].m_viscosityFriction)
                                      + v30->m_viscosityFrictionCoefficient;
  v22.m128_f32[0] = v22.m128_f32[0] * vehicleInstance->m_data->m_wheelParams.m_data[v11].m_maxFriction;
  axle_params->m_wheelDownForce = suspensionForceAtWheel + axle_params->m_wheelDownForce;
  axle_params->m_forwardForce = v32;
  axle_params->m_maxFrictionCoefficient = v22.m128_f32[0] + axle_params->m_maxFrictionCoefficient;
  v33 = !v31 || vehicleInstance->m_isFixed.m_data[v9].m_bool;
  axle_params->m_wheelFixed = v33;
  axle_params->m_slipVelocityFactor = (float)((float)(v28
                                                    * vehicleInstance->m_data->m_wheelParams.m_data[v11].m_slipAngle)
                                            * estimatedCarSpeed)
                                    + axle_params->m_slipVelocityFactor;
}

// File Line: 290
// RVA: 0xE2D8F0
void __fastcall hkpVehicleDefaultSimulation::prepareChassisParams(hkpVehicleDefaultSimulation *this, hkpVehicleInstance *vehicleInstance, hkStepInfo *stepInfo, hkpVehicleFrictionSolverParams *frictionParams)
{
  hkpVelocityAccumulator *v4; // rdi
  hkpVehicleFrictionSolverParams *v5; // rsi
  hkpVehicleInstance *v6; // rbx
  hkVector4f v7; // xmm6
  __m128 v8; // xmm1
  hkpVehicleData *v9; // rax
  __m128 v10; // xmm6
  hkVector4f b; // [rsp+30h] [rbp-28h]
  hkpMotion *motions; // [rsp+68h] [rbp+10h]

  v4 = &frictionParams->m_chassis;
  v5 = frictionParams;
  v6 = vehicleInstance;
  motions = (hkpMotion *)&vehicleInstance->m_entity->m_motion.vfptr;
  hkRigidMotionUtilBuildAccumulators(stepInfo, &motions, 1, 0i64, &frictionParams->m_chassis);
  v7.m_quad = (__m128)motions->m_motionState.m_sweptTransform.m_centerOfMass1;
  v8 = _mm_shuffle_ps(v7.m_quad, v7.m_quad, 255);
  v9 = v6->m_data;
  v10 = _mm_mul_ps(_mm_sub_ps(v7.m_quad, motions->m_motionState.m_sweptTransform.m_centerOfMass0.m_quad), v8);
  b.m_quad = _mm_mul_ps(motions->m_motionState.m_deltaAngle.m_quad, v8);
  v5->m_chassis.m_invMasses = v9->m_chassisFrictionInertiaInvDiag;
  v5->m_chassisAtLastIntegration.m_type.m_storage = v4->m_type.m_storage;
  v5->m_chassisAtLastIntegration.m_context.m_storage = v4->m_context.m_storage;
  v5->m_chassisAtLastIntegration.m_deactivationClass = v4->m_deactivationClass;
  v5->m_chassisAtLastIntegration.m_gravityFactor = v4->m_gravityFactor;
  v5->m_chassisAtLastIntegration.m_linearVel = v4->m_linearVel;
  v5->m_chassisAtLastIntegration.m_angularVel = v4->m_angularVel;
  v5->m_chassisAtLastIntegration.m_invMasses = v4->m_invMasses;
  v5->m_chassisAtLastIntegration.m_scratch0 = v4->m_scratch0;
  v5->m_chassisAtLastIntegration.m_scratch1 = v4->m_scratch1;
  v5->m_chassisAtLastIntegration.m_scratch2 = v4->m_scratch2;
  v5->m_chassisAtLastIntegration.m_scratch3 = v4->m_scratch3;
  hkVector4f::setRotatedDir(&v5->m_chassisAtLastIntegration.m_angularVel, (hkMatrix3f *)&v5->m_chassis.m_scratch0, &b);
  v5->m_chassisAtLastIntegration.m_linearVel.m_quad = v10;
}

// File Line: 310
// RVA: 0xE2DA20
void __fastcall hkpVehicleDefaultSimulation::applyAerodynamicDrag(hkpVehicleDefaultSimulation *this, hkpVehicleInstance *vehicleInstance, hkpVehicleAerodynamics::AerodynamicsDragOutput *aerodynamicsDragInfo, hkpVehicleFrictionSolverParams *frictionParams, const float deltaTime)
{
  hkpEntity *v5; // rax
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  __m128 v8; // xmm0
  __m128 v9; // xmm6
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm5

  v5 = vehicleInstance->m_entity;
  v6 = _mm_shuffle_ps((__m128)LODWORD(deltaTime), (__m128)LODWORD(deltaTime), 0);
  frictionParams->m_chassis.m_linearVel.m_quad = _mm_add_ps(
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(
                                                       v5->m_motion.m_inertiaAndMassInv.m_quad,
                                                       v5->m_motion.m_inertiaAndMassInv.m_quad,
                                                       255),
                                                     _mm_mul_ps(aerodynamicsDragInfo->m_aerodynamicsForce.m_quad, v6)),
                                                   frictionParams->m_chassis.m_linearVel.m_quad);
  v7 = v5->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad;
  v8 = v5->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad;
  v9 = _mm_mul_ps(aerodynamicsDragInfo->m_aerodynamicsTorque.m_quad, v6);
  v10 = _mm_unpacklo_ps(v5->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad, v8);
  v11 = _mm_movelh_ps(v10, v7);
  v12 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(_mm_movehl_ps(v11, v10), v7, 212)),
              _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), v11)),
            _mm_mul_ps(
              _mm_shuffle_ps(v9, v9, 170),
              _mm_shuffle_ps(
                _mm_unpackhi_ps(v5->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad, v8),
                v7,
                228))),
          v5->m_motion.m_inertiaAndMassInv.m_quad);
  frictionParams->m_chassis.m_angularVel.m_quad = _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(
                                                          _mm_shuffle_ps(v12, v12, 85),
                                                          v5->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                                                        _mm_mul_ps(
                                                          _mm_shuffle_ps(v12, v12, 0),
                                                          v5->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
                                                      _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), v7)),
                                                    frictionParams->m_chassis.m_angularVel.m_quad);
}

// File Line: 330
// RVA: 0xE2DB10
void __fastcall hkpVehicleDefaultSimulation::applyVelocityDamping(hkpVehicleDefaultSimulation *this, const float deltaTime, hkpVehicleFrictionSolverParams *frictionParams, hkpVehicleVelocityDamper *damper)
{
  hkVector4f v4; // xmm4
  __m128 v5; // xmm2
  float v6; // xmm2_4

  v4.m_quad = (__m128)frictionParams->m_chassis.m_angularVel;
  v5 = _mm_mul_ps(v4.m_quad, v4.m_quad);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 170))) <= (float)(*(float *)&damper[1].m_memSizeAndFlags
                                                                   * *(float *)&damper[1].m_memSizeAndFlags) )
    v6 = fmaxf(0.0, 1.0 - (float)(deltaTime * *(float *)&damper[1].vfptr));
  else
    v6 = fmaxf(0.0, 1.0 - (float)(deltaTime * *((float *)&damper[1].vfptr + 1)));
  frictionParams->m_chassis.m_angularVel.m_quad = _mm_mul_ps(
                                                    _mm_shuffle_ps((__m128)LODWORD(v6), (__m128)LODWORD(v6), 0),
                                                    v4.m_quad);
}

// File Line: 352
// RVA: 0xE2DBC0
void __fastcall hkpVehicleDefaultSimulation::applySuspensionForces(hkpVehicleDefaultSimulation *this, hkpVehicleInstance *vehicleInstance, float deltaTime, hkArray<float,hkContainerHeapAllocator> *suspensionForceAtWheel, hkpRigidBody **groundBody, hkpVehicleFrictionSolverParams *frictionParams, hkVector4f *suspensionForcesOnGround)
{
  hkpVehicleData *v7; // rcx
  int v8; // edi
  hkArray<float,hkContainerHeapAllocator> *v9; // rax
  float v10; // xmm9_4
  hkpVehicleInstance *v11; // r13
  hkVector4f *v12; // rsi
  __int64 v13; // r14
  __int64 v14; // rbp
  __int64 v15; // r15
  hkpVehicleInstance::WheelInfo *v16; // r12
  hkpRigidBody *v17; // rbx
  float v18; // xmm1_4
  __m128 v19; // xmm7
  hkpEntity *v20; // rax
  __m128 v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm6
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  __m128 v26; // xmm6
  __m128 v27; // xmm2
  __m128 v28; // xmm5
  hkpVehicleData::WheelComponentParams *v29; // rdx
  __m128 v30; // xmm1
  __m128 v31; // xmm7
  __m128 v32; // xmm1
  __m128 v33; // xmm5
  __m128 v34; // xmm4
  __m128 v35; // xmm2
  hkpVelocityAccumulator *v36; // rax
  __m128 v37; // xmm3
  hkpVelocityAccumulator *v38; // rax
  __m128 v39; // xmm1
  __m128 v40; // xmm7
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  __m128 v43; // xmm7
  __m128 v44; // xmm2
  __m128 v45; // xmm5
  int v46; // ecx
  bool v47; // sf
  unsigned __int8 v48; // of
  int v49; // [rsp+20h] [rbp-98h]
  hkpVehicleData *v50; // [rsp+28h] [rbp-90h]
  unsigned int v51; // [rsp+C8h] [rbp+10h]
  hkArray<float,hkContainerHeapAllocator> *v52; // [rsp+D8h] [rbp+20h]

  v52 = suspensionForceAtWheel;
  v7 = vehicleInstance->m_data;
  v8 = 0;
  v9 = suspensionForceAtWheel;
  v10 = deltaTime;
  v11 = vehicleInstance;
  v50 = v7;
  if ( v7->m_numWheels )
  {
    v12 = suspensionForcesOnGround;
    v13 = 0i64;
    v14 = 0i64;
    v15 = 0i64;
    do
    {
      v16 = v11->m_wheelsInfo.m_data;
      v17 = v16[v14].m_contactBody;
      v18 = v9->m_data[v15];
      v19 = _mm_mul_ps(
              _mm_shuffle_ps((__m128)COERCE_UNSIGNED_INT(v18 * v10), (__m128)COERCE_UNSIGNED_INT(v18 * v10), 0),
              v16[v14].m_contactPoint.m_separatingNormal.m_quad);
      if ( v18 > 0.0 )
      {
        frictionParams->m_chassis.m_linearVel.m_quad = _mm_add_ps(
                                                         _mm_mul_ps(
                                                           _mm_shuffle_ps(
                                                             v11->m_entity->m_motion.m_inertiaAndMassInv.m_quad,
                                                             v11->m_entity->m_motion.m_inertiaAndMassInv.m_quad,
                                                             255),
                                                           v19),
                                                         frictionParams->m_chassis.m_linearVel.m_quad);
        v20 = v11->m_entity;
        v21 = v20->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad;
        v22 = _mm_sub_ps(
                v16[v14].m_hardPointWs.m_quad,
                v20->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
        v23 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v22), _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v19));
        v24 = v20->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad;
        v25 = _mm_unpacklo_ps(v20->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad, v24);
        v26 = _mm_shuffle_ps(v23, v23, 201);
        v27 = _mm_movelh_ps(v25, v21);
        v28 = _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(_mm_movehl_ps(v27, v25), v21, 212)),
                    _mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), v27)),
                  _mm_mul_ps(
                    _mm_shuffle_ps(
                      _mm_unpackhi_ps(v20->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad, v24),
                      v21,
                      228),
                    _mm_shuffle_ps(v26, v26, 170))),
                v20->m_motion.m_inertiaAndMassInv.m_quad);
        frictionParams->m_chassis.m_angularVel.m_quad = _mm_add_ps(
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_mul_ps(
                                                                _mm_shuffle_ps(v28, v28, 85),
                                                                v20->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                                                              _mm_mul_ps(
                                                                _mm_shuffle_ps(v28, v28, 0),
                                                                v20->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
                                                            _mm_mul_ps(_mm_shuffle_ps(v28, v28, 170), v21)),
                                                          frictionParams->m_chassis.m_angularVel.m_quad);
      }
      if ( v17 && v17->m_motion.m_type.m_storage != 5 )
      {
        v29 = v7->m_wheelParams.m_data;
        v49 = v29[v13].m_axle;
        v30 = (__m128)LODWORD(v29[v8].m_forceFeedbackMultiplier);
        v31 = _mm_mul_ps(v19, _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v30, v30, 0)));
        v32 = _mm_mul_ps(v31, v31);
        *(float *)&v51 = (float)(hkpMotion::getMass((hkpMotion *)&v17->m_motion.vfptr)
                               * v50->m_wheelParams.m_data[v13].m_maxContactBodyAcceleration)
                       * v10;
        v33 = _mm_shuffle_ps((__m128)v51, (__m128)v51, 0);
        v34 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                _mm_shuffle_ps(v32, v32, 170));
        if ( (float)(v33.m128_f32[0] * v33.m128_f32[0]) < v34.m128_f32[0] )
        {
          v35 = _mm_rsqrt_ps(v34);
          v31 = _mm_mul_ps(
                  v31,
                  _mm_mul_ps(
                    _mm_andnot_ps(
                      _mm_cmpleps(v34, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v35, v34), v35)),
                        _mm_mul_ps(*(__m128 *)_xmm, v35))),
                    v33));
        }
        if ( v17 != groundBody[v49] )
        {
          *v12 = (hkVector4f)v31;
          goto LABEL_12;
        }
        v36 = frictionParams->m_axleParams[v49].m_groundObject;
        v36->m_linearVel.m_quad = _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(
                                        v17->m_motion.m_inertiaAndMassInv.m_quad,
                                        v17->m_motion.m_inertiaAndMassInv.m_quad,
                                        255),
                                      v31),
                                    v36->m_linearVel.m_quad);
        v37 = v17->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad;
        v38 = frictionParams->m_axleParams[v49].m_groundObject;
        v39 = _mm_sub_ps(
                v16[v14].m_hardPointWs.m_quad,
                v17->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
        v40 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v39), _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v31));
        v41 = v17->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad;
        v42 = _mm_unpacklo_ps(v17->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad, v41);
        v43 = _mm_shuffle_ps(v40, v40, 201);
        v44 = _mm_movelh_ps(v42, v37);
        v45 = _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(_mm_movehl_ps(v44, v42), v37, 212)),
                    _mm_mul_ps(_mm_shuffle_ps(v43, v43, 0), v44)),
                  _mm_mul_ps(
                    _mm_shuffle_ps(v43, v43, 170),
                    _mm_shuffle_ps(
                      _mm_unpackhi_ps(v17->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad, v41),
                      v37,
                      228))),
                v17->m_motion.m_inertiaAndMassInv.m_quad);
        v38->m_angularVel.m_quad = _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(v45, v45, 85),
                                           v17->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(v45, v45, 0),
                                           v17->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
                                       _mm_mul_ps(_mm_shuffle_ps(v45, v45, 170), v37)),
                                     v38->m_angularVel.m_quad);
      }
      *v12 = 0i64;
LABEL_12:
      ++v8;
      ++v14;
      v46 = (unsigned __int8)v11->m_data->m_numWheels;
      v9 = v52;
      ++v15;
      ++v13;
      ++v12;
      v48 = __OFSUB__(v8, v46);
      v47 = v8 - v46 < 0;
      v7 = v50;
    }
    while ( v47 ^ v48 );
  }
}

// File Line: 435
// RVA: 0xE2DFE0
void __fastcall hkpVehicleDefaultSimulation::applyDampingToAxleAccumulators(hkpVehicleDefaultSimulation *this, hkStepInfo *stepInfo, hkpRigidBody **groundBodies, hkpVehicleFrictionSolverParams *frictionParams, hkVector4f *originalLinearVels, hkVector4f *originalAngularVels)
{
  hkpRigidBody *v6; // rcx
  __m128 v7; // xmm3
  __m128 v8; // xmm1
  hkpVelocityAccumulator *v9; // rax
  __m128 v10; // xmm2
  hkpRigidBody *v11; // rcx
  __m128 v12; // xmm1
  hkpVelocityAccumulator *v13; // rax
  __m128 v14; // xmm2
  unsigned int v15; // [rsp+10h] [rbp+10h]
  unsigned int v16; // [rsp+10h] [rbp+10h]

  v6 = *groundBodies;
  v7 = _mm_shuffle_ps(
         (__m128)LODWORD(stepInfo->m_deltaTime.m_storage),
         (__m128)LODWORD(stepInfo->m_deltaTime.m_storage),
         0);
  if ( *groundBodies && v6->m_motion.m_type.m_storage != 5 )
  {
    v8 = (__m128)(unsigned int)(v6->m_motion.m_motionState.m_linearDamping.m_value << 16);
    v15 = v6->m_motion.m_motionState.m_angularDamping.m_value << 16;
    v9 = frictionParams->m_axleParams[0].m_groundObject;
    v9->m_linearVel.m_quad = _mm_mul_ps(
                               _mm_max_ps(
                                 (__m128)0i64,
                                 _mm_sub_ps(query.m_quad, _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), v7))),
                               v9->m_linearVel.m_quad);
    v9->m_angularVel.m_quad = _mm_mul_ps(
                                _mm_max_ps(
                                  (__m128)0i64,
                                  _mm_sub_ps(query.m_quad, _mm_mul_ps(_mm_shuffle_ps((__m128)v15, (__m128)v15, 0), v7))),
                                v9->m_angularVel.m_quad);
    *originalLinearVels = v9->m_linearVel;
    *originalAngularVels = v9->m_angularVel;
    v10 = v9->m_angularVel.m_quad;
    v9->m_angularVel.m_quad = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), v9->m_scratch1.m_quad),
                                  _mm_mul_ps(_mm_shuffle_ps(v9->m_angularVel.m_quad, v10, 0), v9->m_scratch0.m_quad)),
                                _mm_mul_ps(_mm_shuffle_ps(v10, v10, 170), v9->m_scratch2.m_quad));
  }
  v11 = groundBodies[1];
  if ( v11 && v11->m_motion.m_type.m_storage != 5 && v11 != *groundBodies )
  {
    v12 = (__m128)(unsigned int)(v11->m_motion.m_motionState.m_linearDamping.m_value << 16);
    v16 = v11->m_motion.m_motionState.m_angularDamping.m_value << 16;
    v13 = frictionParams->m_axleParams[1].m_groundObject;
    v13->m_linearVel.m_quad = _mm_mul_ps(
                                _mm_max_ps(
                                  (__m128)0i64,
                                  _mm_sub_ps(query.m_quad, _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), v7))),
                                v13->m_linearVel.m_quad);
    v13->m_angularVel.m_quad = _mm_mul_ps(
                                 _mm_max_ps(
                                   (__m128)0i64,
                                   _mm_sub_ps(query.m_quad, _mm_mul_ps(_mm_shuffle_ps((__m128)v16, (__m128)v16, 0), v7))),
                                 v13->m_angularVel.m_quad);
    originalLinearVels[1] = v13->m_linearVel;
    originalAngularVels[1] = v13->m_angularVel;
    v14 = v13->m_angularVel.m_quad;
    v13->m_angularVel.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v13->m_scratch1.m_quad),
                                   _mm_mul_ps(_mm_shuffle_ps(v13->m_angularVel.m_quad, v14, 0), v13->m_scratch0.m_quad)),
                                 _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v13->m_scratch2.m_quad));
  }
}

// File Line: 487
// RVA: 0xE2E190
void __fastcall hkpVehicleDefaultSimulation::applyDampingToChassisAccumulator(hkpVehicleDefaultSimulation *this, hkStepInfo *stepInfo, hkpVelocityAccumulator *accumulator, hkpMotion *motion)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm3
  hkVector4f v6; // xmm5
  unsigned int v7; // [rsp+10h] [rbp+10h]

  v4 = (__m128)(unsigned int)(motion->m_motionState.m_linearDamping.m_value << 16);
  v5 = _mm_shuffle_ps(
         (__m128)LODWORD(stepInfo->m_deltaTime.m_storage),
         (__m128)LODWORD(stepInfo->m_deltaTime.m_storage),
         0);
  v7 = motion->m_motionState.m_angularDamping.m_value << 16;
  accumulator->m_linearVel.m_quad = _mm_mul_ps(
                                      _mm_max_ps(
                                        (__m128)0i64,
                                        _mm_sub_ps(query.m_quad, _mm_mul_ps(_mm_shuffle_ps(v4, v4, 0), v5))),
                                      accumulator->m_linearVel.m_quad);
  v6.m_quad = _mm_mul_ps(
                _mm_max_ps(
                  (__m128)0i64,
                  _mm_sub_ps(query.m_quad, _mm_mul_ps(_mm_shuffle_ps((__m128)v7, (__m128)v7, 0), v5))),
                accumulator->m_angularVel.m_quad);
  accumulator->m_angularVel = (hkVector4f)v6.m_quad;
  accumulator->m_angularVel.m_quad = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(v6.m_quad, v6.m_quad, 85),
                                           accumulator->m_scratch1.m_quad),
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(v6.m_quad, v6.m_quad, 0),
                                           accumulator->m_scratch0.m_quad)),
                                       _mm_mul_ps(
                                         _mm_shuffle_ps(v6.m_quad, v6.m_quad, 170),
                                         accumulator->m_scratch2.m_quad));
}

// File Line: 511
// RVA: 0xE2E240
void __fastcall hkpVehicleDefaultSimulation::getExtraTorqueFactor(hkpVehicleDefaultSimulation *this, hkpVehicleInstance *vehicleInstance, float deltaTime, hkpVelocityAccumulator *accumulatorForChassis)
{
  hkpVehicleData *v4; // rax
  float v5; // xmm1_4

  v4 = vehicleInstance->m_data;
  v5 = v4->m_extraTorqueFactor;
  if ( v5 != 0.0 )
    accumulatorForChassis->m_angularVel.m_quad = _mm_add_ps(
                                                   _mm_mul_ps(
                                                     _mm_mul_ps(
                                                       _mm_shuffle_ps(
                                                         (__m128)COERCE_UNSIGNED_INT(
                                                                   (float)(v5
                                                                         * vehicleInstance->m_mainSteeringAngleAssumingNoReduction)
                                                                 * deltaTime),
                                                         (__m128)COERCE_UNSIGNED_INT(
                                                                   (float)(v5
                                                                         * vehicleInstance->m_mainSteeringAngleAssumingNoReduction)
                                                                 * deltaTime),
                                                         0),
                                                       v4->m_chassisOrientation.m_col0.m_quad),
                                                     v4->m_chassisFrictionInertiaInvDiag.m_quad),
                                                   accumulatorForChassis->m_angularVel.m_quad);
}

// File Line: 524
// RVA: 0xE2E290
void __fastcall hkpVehicleDefaultSimulation::applyFrictionSolver(hkpVehicleDefaultSimulation *this, hkpVehicleInstance *vehicleInstance, hkStepInfo *stepInfo, hkpVehicleFrictionSolverParams *frictionParams, hkpVehicleFrictionStatus *frictionStatus)
{
  float v5; // xmm1_4
  hkpVehicleFrictionDescription *v6; // rdx
  hkpVehicleStepInfo stepInfoa; // [rsp+30h] [rbp+8h]

  v5 = stepInfo->m_invDeltaTime.m_storage;
  v6 = this->m_frictionDescription.m_pntr;
  stepInfoa.m_deltaTime = stepInfo->m_deltaTime.m_storage;
  stepInfoa.m_invDeltaTime = v5;
  hkVehicleFrictionApplyVehicleFriction(&stepInfoa, v6, frictionParams, frictionStatus);
}

// File Line: 534
// RVA: 0xE2E2D0
void __fastcall hkpVehicleDefaultSimulation::calcChassisVelocities(hkpVehicleDefaultSimulation *this, hkpVehicleInstance *vehicleInstance, hkpVelocityAccumulator *accumulatorForChassis, hkpVehicleJobResults *vehicleResults)
{
  hkpEntity *v4; // rax
  hkVector4f v5; // xmm1

  v4 = vehicleInstance->m_entity;
  vehicleResults->m_chassisLinearVel = accumulatorForChassis->m_linearVel;
  v5.m_quad = (__m128)accumulatorForChassis->m_angularVel;
  vehicleResults->m_chassisAngularVel.m_quad = _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(v5.m_quad, v5.m_quad, 85),
                                                     v4->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(
                                                       accumulatorForChassis->m_angularVel.m_quad,
                                                       v5.m_quad,
                                                       0),
                                                     v4->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
                                                 _mm_mul_ps(
                                                   _mm_shuffle_ps(v5.m_quad, v5.m_quad, 170),
                                                   v4->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
}

// File Line: 544
// RVA: 0xE2E320
int hkpVehicleDefaultSimulation::calcGroundBodyVelocities(...)
{
  hkpVehicleData *v8; // rbx
  int v9; // edx
  hkpVehicleFrictionSolverAxleParams *v10; // r11
  __m128 v11; // xmm13
  __m128 *v12; // r9
  __m128 **v13; // r11
  hkpRigidBody **v14; // rcx
  signed __int64 v15; // r10
  __m128 v16; // xmm11
  __m128 v17; // xmm11
  __m128 v18; // xmm8
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm7
  __m128 v25; // xmm11
  __m128 v26; // xmm12

  v8 = vehicleInstance->m_data;
  v9 = 0;
  v10 = axleParams;
  v11 = (__m128)deltaTime;
  if ( v8->m_numWheelsPerAxle.m_size > 0 )
  {
    v12 = (__m128 *)vehicleResults->m_groundBodyAngularVel;
    v13 = (__m128 **)&v10->m_groundObject;
    v14 = groundBody;
    v15 = (char *)vehicleResults - (char *)groundBody;
    do
    {
      *(hkpRigidBody **)((char *)v14 + v15 + 96) = 0i64;
      if ( *v14 && (*v14)->m_motion.m_type.m_storage != 5 && (!v9 || *groundBody != groundBody[1]) )
      {
        v16 = v11;
        v16.m128_f32[0] = v11.m128_f32[0] * 10.0;
        v17 = _mm_shuffle_ps(v16, v16, 0);
        v18 = (*v13)[6];
        v19 = _mm_unpacklo_ps((*v13)[4], (*v13)[5]);
        v20 = _mm_movelh_ps(v19, v18);
        v21 = _mm_movehl_ps(v20, v19);
        v22 = (*v13)[2];
        v23 = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, (__m128)0i64), 196);
        v24 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
        v25 = v23;
        v26 = _mm_add_ps(
                _mm_max_ps(
                  _mm_min_ps(
                    _mm_sub_ps(
                      (*v13)[1],
                      *(__m128 *)((char *)v12 + (char *)originalLinearVels - (char *)vehicleResults - 64)),
                    v25),
                  _mm_xor_ps(v24, v25)),
                *(__m128 *)((char *)v12 + (char *)originalLinearVels - (char *)vehicleResults - 64));
        *v12 = _mm_add_ps(
                 _mm_max_ps(
                   _mm_min_ps(
                     _mm_sub_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v21, v18, 212)),
                           _mm_mul_ps(_mm_shuffle_ps((*v13)[2], v22, 0), v20)),
                         _mm_mul_ps(
                           _mm_shuffle_ps(v22, v22, 170),
                           _mm_shuffle_ps(_mm_unpackhi_ps((*v13)[4], (*v13)[5]), v18, 228))),
                       *(__m128 *)((char *)v12 + (char *)originalAngularVels - (char *)vehicleResults - 64)),
                     v23),
                   _mm_xor_ps(v24, v23)),
                 *(__m128 *)((char *)v12 + (char *)originalAngularVels - (char *)vehicleResults - 64));
        v12[-2] = v26;
        *(hkpRigidBody **)((char *)v14 + v15 + 96) = *v14;
      }
      ++v9;
      v13 += 12;
      ++v12;
      ++v14;
    }
    while ( v9 < v8->m_numWheelsPerAxle.m_size );
  }
}

// File Line: 597
// RVA: 0xE2CB30
void __fastcall hkpVehicleDefaultSimulation::init(hkpVehicleDefaultSimulation *this, hkpVehicleInstance *instance)
{
  hkpEntity *v2; // rbx
  hkpVehicleData *v3; // rsi
  hkpVehicleInstance *v4; // rbp
  hkpVehicleDefaultSimulation *v5; // rdi
  __m128 v6; // xmm2
  hkVector4f v7; // xmm0
  hkVector4f v8; // xmm1
  unsigned int v9; // eax
  __m128i v10; // xmm0
  hkVector4f v11; // xmm1
  hkpVehicleSuspension *v12; // rbx
  hkpVehicleData::WheelComponentParams *v13; // r8
  __int64 v14; // r9
  __int64 v15; // r10
  __int64 v16; // r11
  __int64 v17; // rdx
  __int64 v18; // rcx
  _QWORD **v19; // rax
  __int64 v20; // rax
  hkpVehicleFrictionDescription *v21; // rbx
  hkReferencedObject *v22; // rcx
  hkMatrix3f aTb; // [rsp+20h] [rbp-E8h]
  hkpVehicleFrictionDescription::Cinfo ci; // [rsp+50h] [rbp-B8h]

  v2 = instance->m_entity;
  v3 = instance->m_data;
  v4 = instance;
  v5 = this;
  v6 = v3->m_chassisFrictionInertiaInvDiag.m_quad;
  ci.m_chassisCenterOfMass = v2->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal;
  v7.m_quad = _mm_mul_ps(_mm_shuffle_ps(v6, v6, 0), v2->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad);
  v8.m_quad = _mm_mul_ps(_mm_shuffle_ps(v6, v6, 85), v2->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad);
  aTb.m_col2.m_quad = _mm_mul_ps(
                        _mm_shuffle_ps(v6, v6, 170),
                        v2->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad);
  aTb.m_col0 = (hkVector4f)v7.m_quad;
  aTb.m_col1 = (hkVector4f)v8.m_quad;
  hkMatrix3f::setMulInverse(&ci.m_chassisFrictionInertiaInv, &aTb, &v2->m_motion.m_motionState.m_transform.m_rotation);
  v9 = v3->m_numWheels;
  ci.m_chassisMassInv = v2->m_motion.m_inertiaAndMassInv.m_quad.m128_f32[3];
  *(_QWORD *)ci.m_wheelAxleAngularInertia = 0i64;
  v10 = _mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&v3->m_chassisOrientation.m_col1), 1u), 1u);
  ci.m_directionUp = (hkVector4f)_mm_srli_epi32(
                                   _mm_slli_epi32(_mm_load_si128((const __m128i *)&v3->m_chassisOrientation), 1u),
                                   1u);
  v11.m_quad = (__m128)_mm_srli_epi32(
                         _mm_slli_epi32(_mm_load_si128((const __m128i *)&v3->m_chassisOrientation.m_col2), 1u),
                         1u);
  ci.m_directionFront = (hkVector4f)v10;
  v10.m128i_i32[0] = LODWORD(v3->m_frictionEqualizer);
  ci.m_directionRight = (hkVector4f)v11.m_quad;
  LODWORD(ci.m_frictionEqualizer) = v10.m128i_i32[0];
  if ( (signed int)v9 > 0 )
  {
    v12 = v4->m_suspension;
    v13 = v3->m_wheelParams.m_data;
    v14 = 0i64;
    v15 = 0i64;
    v16 = v9;
    do
    {
      ++v15;
      ++v14;
      v17 = v13->m_axle;
      v18 = v13->m_axle;
      ci.m_wheelRadius[v17] = v13->m_radius;
      ++v13;
      ci.m_wheelPosition[v18].m_quad = _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(
                                             (__m128)*((unsigned int *)&v12->m_wheelParams.m_data[v15] - 4),
                                             (__m128)*((unsigned int *)&v12->m_wheelParams.m_data[v15] - 4),
                                             0),
                                           *((__m128 *)&v12->m_wheelParams.m_data[v14] - 2)),
                                         v12->m_wheelParams.m_data[v14 - 1].m_hardpointChassisSpace.m_quad);
      ci.m_wheelAxleAngularInertia[v17] = (float)(v13[-1].m_mass * v13[-1].m_radius) + ci.m_wheelAxleAngularInertia[v17];
      --v16;
    }
    while ( v16 );
  }
  v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v20 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v19[11] + 8i64))(v19[11], 224i64);
  v21 = (hkpVehicleFrictionDescription *)v20;
  if ( v20 )
  {
    *(_DWORD *)(v20 + 8) = 0x1FFFF;
    *(_QWORD *)v20 = &hkpVehicleFrictionDescription::`vftable;
  }
  else
  {
    v21 = 0i64;
  }
  v22 = (hkReferencedObject *)&v5->m_frictionDescription.m_pntr->vfptr;
  if ( v22 && v22 != (hkReferencedObject *)v21 )
    hkReferencedObject::removeReference(v22);
  v5->m_frictionDescription.m_pntr = v21;
  hkVehicleFrictionDescriptionInitValues(&ci, v21);
}

// File Line: 645
// RVA: 0xE2CD30
hkpVehicleSimulation *__fastcall hkpVehicleDefaultSimulation::clone(hkpVehicleDefaultSimulation *this, hkpVehicleInstance *instance)
{
  hkpVehicleDefaultSimulation *v2; // rdi
  _QWORD **v3; // rax
  hkpVehicleDefaultSimulation *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rbx
  hkReferencedObject *v7; // rcx
  hkReferencedObject *v8; // rcx

  v2 = this;
  v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (hkpVehicleDefaultSimulation *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v3[11] + 8i64))(
                                        v3[11],
                                        96i64);
  if ( v4 )
  {
    hkpVehicleDefaultSimulation::hkpVehicleDefaultSimulation(v4);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = (hkReferencedObject *)&v2->m_frictionDescription.m_pntr->vfptr;
  if ( v7 )
    hkReferencedObject::addReference(v7);
  v8 = *(hkReferencedObject **)(v6 + 88);
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  *(_QWORD *)(v6 + 88) = v2->m_frictionDescription.m_pntr;
  return (hkpVehicleSimulation *)v6;
}

