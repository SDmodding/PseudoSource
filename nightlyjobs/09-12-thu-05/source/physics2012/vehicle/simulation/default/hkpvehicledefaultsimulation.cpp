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
void __fastcall hkpVehicleDefaultSimulation::simulateVehicle(
        hkpVehicleDefaultSimulation *this,
        hkpVehicleInstance *instance,
        hkStepInfo *stepInfo,
        hkpVehicleSimulation::SimulationInput *simulInput)
{
  hkArray<float,hkContainerHeapAllocator> *suspensionForceAtWheel; // r13
  hkArray<float,hkContainerHeapAllocator> *totalLinearForceAtWheel; // rdx
  hkpVehicleData *m_data; // rsi
  float *p_m_maxFrictionCoefficient; // rax
  __int64 v11; // rcx
  float m_storage; // xmm6_4
  hkpVehicleJobResults *v13; // r15
  hkpVehicleData *v14; // rbx
  int v15; // r10d
  __m128 v16; // xmm1
  float v17; // xmm4_4
  hkBool *v18; // r11
  __int64 v19; // r9
  float *i; // rdx
  __int64 m_axle; // r8
  float v22; // xmm1_4
  __m128 v23; // xmm1
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  hkpRigidBody *groundBodies[2]; // [rsp+50h] [rbp-88h] BYREF
  hkVector4f originalAngularVels; // [rsp+60h] [rbp-78h] BYREF
  hkVector4f originalLinearVels; // [rsp+70h] [rbp-68h] BYREF
  hkpVehicleFrictionSolverParams frictionParams; // [rsp+88h] [rbp-50h] BYREF
  hkpVelocityAccumulator groundAccum; // [rsp+258h] [rbp+180h] BYREF
  hkpVelocityAccumulator groundAccumAtIntegration; // [rsp+358h] [rbp+280h] BYREF
  char v35; // [rsp+458h] [rbp+380h] BYREF
  hkpVehicleAerodynamics::AerodynamicsDragOutput *aerodynamicsDragInfo; // [rsp+708h] [rbp+630h]
  hkpVehicleJobResults *retaddr; // [rsp+728h] [rbp+650h]

  suspensionForceAtWheel = simulInput->suspensionForceAtWheel;
  totalLinearForceAtWheel = simulInput->totalLinearForceAtWheel;
  m_data = instance->m_data;
  aerodynamicsDragInfo = simulInput->aerodynamicsDragInfo;
  p_m_maxFrictionCoefficient = &frictionParams.m_axleParams[0].m_maxFrictionCoefficient;
  v11 = 2i64;
  do
  {
    *((_OWORD *)p_m_maxFrictionCoefficient - 2) = 0i64;
    *((_OWORD *)p_m_maxFrictionCoefficient - 1) = 0i64;
    *(_OWORD *)p_m_maxFrictionCoefficient = 0i64;
    *((_QWORD *)p_m_maxFrictionCoefficient + 4) = 0i64;
    *((_QWORD *)p_m_maxFrictionCoefficient + 5) = 0i64;
    *((_QWORD *)p_m_maxFrictionCoefficient + 6) = 0i64;
    *((_BYTE *)p_m_maxFrictionCoefficient + 56) = 0;
    *((_QWORD *)p_m_maxFrictionCoefficient + 2) = 0i64;
    *((_QWORD *)p_m_maxFrictionCoefficient + 3) = 0i64;
    p_m_maxFrictionCoefficient += 24;
    --v11;
  }
  while ( v11 );
  m_storage = stepInfo->m_deltaTime.m_storage;
  groundBodies[0] = 0i64;
  groundBodies[1] = 0i64;
  hkpVehicleDefaultSimulation::prepareAxleParams(
    this,
    instance,
    m_storage,
    suspensionForceAtWheel,
    totalLinearForceAtWheel,
    groundBodies,
    &frictionParams,
    stepInfo,
    &groundAccum,
    &groundAccumAtIntegration);
  hkpVehicleDefaultSimulation::prepareChassisParams(this, instance, stepInfo, &frictionParams);
  v13 = (hkpVehicleJobResults *)&v35;
  if ( retaddr )
    v13 = retaddr;
  hkpVehicleDefaultSimulation::applyAerodynamicDrag(this, instance, aerodynamicsDragInfo, &frictionParams, m_storage);
  hkpVehicleDefaultSimulation::applyVelocityDamping(this, m_storage, &frictionParams, instance->m_velocityDamper);
  hkpVehicleDefaultSimulation::applySuspensionForces(
    this,
    instance,
    m_storage,
    suspensionForceAtWheel,
    groundBodies,
    &frictionParams,
    v13->m_groundBodyImpulses);
  hkpVehicleDefaultSimulation::applyDampingToAxleAccumulators(
    this,
    stepInfo,
    groundBodies,
    &frictionParams,
    &originalLinearVels,
    (hkVector4f *)&originalAngularVels.m_quad.m128_u16[4]);
  hkpVehicleDefaultSimulation::applyDampingToChassisAccumulator(
    this,
    stepInfo,
    &frictionParams.m_chassis,
    &instance->m_entity->m_motion);
  hkpVehicleDefaultSimulation::getExtraTorqueFactor(this, instance, m_storage, &frictionParams.m_chassis);
  hkpVehicleDefaultSimulation::applyFrictionSolver(this, instance, stepInfo, &frictionParams, &this->m_frictionStatus);
  hkpVehicleDefaultSimulation::calcChassisVelocities(this, instance, &frictionParams.m_chassis, v13);
  hkpVehicleDefaultSimulation::calcGroundBodyVelocities(
    this,
    instance,
    m_storage,
    frictionParams.m_axleParams,
    groundBodies,
    v13,
    &originalLinearVels,
    (hkVector4f *)&originalAngularVels.m_quad.m128_u16[4]);
  if ( !retaddr )
    hkpVehicleJobResults::applyForcesFromStep(v13, instance);
  hkVector4f::setRotatedDir(
    &originalAngularVels,
    &instance->m_entity->m_motion.m_motionState.m_transform.m_rotation,
    &m_data->m_chassisOrientation.m_col1);
  v14 = instance->m_data;
  v15 = 0;
  v16 = _mm_mul_ps(frictionParams.m_chassis.m_linearVel.m_quad, originalAngularVels.m_quad);
  v17 = (float)(_mm_shuffle_ps(v16, v16, 85).m128_f32[0] + _mm_shuffle_ps(v16, v16, 0).m128_f32[0])
      + _mm_shuffle_ps(v16, v16, 170).m128_f32[0];
  if ( v14->m_numWheels )
  {
    v18 = instance->m_isFixed.m_data;
    v19 = 0i64;
    for ( i = &instance->m_wheelsInfo.m_data->m_spinAngle; ; i += 56 )
    {
      m_axle = m_data->m_wheelParams.m_data[v19].m_axle;
      i[3] = this->m_frictionStatus.m_axis[m_axle].m_forward_slip_velocity;
      i[2] = this->m_frictionStatus.m_axis[m_axle].m_side_force;
      i[4] = this->m_frictionStatus.m_axis[m_axle].m_side_slip_velocity;
      i[1] = this->m_frictionStatus.m_axis[m_axle].m_skid_energy_density;
      if ( v18->m_bool )
      {
        *((_QWORD *)i - 1) = 0i64;
      }
      else
      {
        v22 = v17;
        if ( groundBodies[m_axle] )
        {
          v23 = _mm_mul_ps(
                  originalAngularVels.m_quad,
                  frictionParams.m_axleParams[m_axle].m_groundObject->m_linearVel.m_quad);
          v22 = v17
              - (float)((float)(_mm_shuffle_ps(v23, v23, 85).m128_f32[0] + _mm_shuffle_ps(v23, v23, 0).m128_f32[0])
                      + _mm_shuffle_ps(v23, v23, 170).m128_f32[0]);
        }
        v24 = v22;
        v25 = v22 + i[3];
        *(i - 1) = v24 / m_data->m_wheelParams.m_data[v19].m_radius;
        v26 = v25 / m_data->m_wheelParams.m_data[v19].m_radius;
        *(i - 2) = v26;
        *i = (float)(v26 * m_storage) + *i;
      }
      v27 = *i;
      if ( *i > 3141.5928 )
        break;
      if ( v27 < -3141.5928 )
      {
        v28 = v27 + 3141.5928;
        goto LABEL_18;
      }
LABEL_19:
      ++v15;
      ++v18;
      ++v19;
      if ( v15 >= (unsigned __int8)v14->m_numWheels )
        return;
    }
    v28 = v27 - 3141.5928;
LABEL_18:
    *i = v28;
    goto LABEL_19;
  }
}

// File Line: 148
// RVA: 0xE2D180
void __fastcall hkpVehicleDefaultSimulation::prepareAxleParams(
        hkpVehicleDefaultSimulation *this,
        hkpVehicleInstance *vehicleInstance,
        float deltaTime,
        hkArray<float,hkContainerHeapAllocator> *suspensionForceAtWheel,
        hkArray<float,hkContainerHeapAllocator> *totalLinearForceAtWheel,
        hkpRigidBody **groundBody,
        hkpVehicleFrictionSolverParams *frictionParams,
        hkStepInfo *stepInfo,
        hkpVelocityAccumulator *groundAccum,
        hkpVelocityAccumulator *groundAccumAtIntegration)
{
  hkpVehicleFrictionSolverParams *v10; // r15
  hkArray<float,hkContainerHeapAllocator> *v11; // r10
  hkpVehicleDefaultSimulation *v12; // r9
  hkpVehicleData *m_data; // rcx
  int v14; // esi
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  float estimatedCarSpeed; // xmm7_4
  __int64 v20; // rbx
  __int64 v21; // rbp
  __int64 v22; // r14
  __int64 m_axle; // r8
  hkpRigidBody *m_contactBody; // rcx
  hkpRigidBody *v25; // rdx
  int v26; // r14d
  hkpVelocityAccumulator *v27; // rdx
  hkpRigidBody **v28; // r13
  hkEnum<enum hkpVelocityAccumulator::hkpAccumulatorContext,unsigned char> *p_m_context; // rbx
  __m128 *p_m_quad; // rbp
  signed __int64 v31; // rsi
  __m128 v32; // xmm5
  hkpVelocityAccumulator *v33; // rcx
  __m128 v34; // xmm1
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  __m128 v38; // xmm3
  __m128 v39; // xmm2
  hkpRigidBody *v40; // rax
  hkpVehicleFrictionSolverParams *v41; // rcx
  __m128 v42; // xmm4
  __m128 v43; // xmm2
  __m128 v44; // xmm3
  __m128 v45; // xmm1
  __m128 m_quad; // xmm3
  __m128 v47; // xmm2
  __m128 v48; // xmm0
  __m128 v49; // xmm3
  __m128 v50; // xmm2
  __m128 v51; // xmm3
  char *v52; // rax
  __m128 v53; // xmm1
  __m128 v54; // xmm0
  __m128 v55; // xmm2
  __int64 v57; // [rsp+C8h] [rbp+10h]

  v10 = frictionParams;
  v11 = suspensionForceAtWheel;
  v12 = this;
  m_data = vehicleInstance->m_data;
  v14 = 0;
  v16 = _mm_mul_ps(
          vehicleInstance->m_entity->m_motion.m_linearVelocity.m_quad,
          vehicleInstance->m_entity->m_motion.m_linearVelocity.m_quad);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_rsqrt_ps(v17);
  LODWORD(estimatedCarSpeed) = _mm_andnot_ps(
                                 _mm_cmple_ps(v17, (__m128)0i64),
                                 _mm_mul_ps(
                                   _mm_mul_ps(
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                                     _mm_mul_ps(v18, *(__m128 *)_xmm)),
                                   v17)).m128_u32[0];
  if ( m_data->m_numWheels > 0 )
  {
    v20 = 0i64;
    v21 = 0i64;
    v22 = 0i64;
    do
    {
      m_axle = m_data->m_wheelParams.m_data[v22].m_axle;
      m_contactBody = vehicleInstance->m_wheelsInfo.m_data[v21].m_contactBody;
      if ( m_contactBody )
      {
        v25 = groundBody[m_axle];
        if ( !v25
          || _mm_shuffle_ps(
               m_contactBody->m_motion.m_inertiaAndMassInv.m_quad,
               m_contactBody->m_motion.m_inertiaAndMassInv.m_quad,
               255).m128_f32[0] < _mm_shuffle_ps(
                                    v25->m_motion.m_inertiaAndMassInv.m_quad,
                                    v25->m_motion.m_inertiaAndMassInv.m_quad,
                                    255).m128_f32[0] )
        {
          groundBody[m_axle] = m_contactBody;
        }
      }
      hkpVehicleDefaultSimulation::getAxleParamsFromWheel(
        v12,
        vehicleInstance,
        v14,
        totalLinearForceAtWheel->m_data[v20],
        v11->m_data[v20],
        estimatedCarSpeed,
        &v10->m_axleParams[m_axle]);
      m_data = vehicleInstance->m_data;
      v12 = this;
      v11 = suspensionForceAtWheel;
      ++v14;
      ++v22;
      ++v21;
      ++v20;
    }
    while ( v14 < m_data->m_numWheels );
  }
  v26 = 0;
  v10->m_maxVelocityForPositionalFriction = vehicleInstance->m_data->m_maxVelocityForPositionalFriction;
  if ( vehicleInstance->m_data->m_numWheelsPerAxle.m_size > 0 )
  {
    v27 = groundAccum;
    v28 = groundBody;
    p_m_context = &groundAccum->m_context;
    p_m_quad = &v10->m_axleParams[0].m_forwardDirWs.m_quad;
    v31 = (char *)groundAccumAtIntegration - (char *)groundAccum;
    do
    {
      v32 = p_m_quad[-1];
      v57 = (__int64)v26 << 7;
      v33 = (hkpVelocityAccumulator *)((char *)v27 + v57);
      v34 = _mm_mul_ps(v32, v32);
      v35 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
              _mm_shuffle_ps(v34, v34, 170));
      v36 = _mm_rsqrt_ps(v35);
      p_m_quad[-1] = _mm_mul_ps(
                       _mm_andnot_ps(
                         _mm_cmple_ps(v35, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v36, v35), v36)),
                           _mm_mul_ps(v36, *(__m128 *)_xmm))),
                       v32);
      v37 = _mm_mul_ps(*p_m_quad, *p_m_quad);
      v38 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
              _mm_shuffle_ps(v37, v37, 170));
      v39 = _mm_rsqrt_ps(v38);
      *p_m_quad = _mm_mul_ps(
                    _mm_andnot_ps(
                      _mm_cmple_ps(v38, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
                        _mm_mul_ps(v39, *(__m128 *)_xmm))),
                    *p_m_quad);
      v40 = *v28;
      p_m_quad[1].m128_u64[0] = (unsigned __int64)v27 + v57;
      p_m_quad[1].m128_u64[1] = (unsigned __int64)v27 + v57;
      if ( v40 )
      {
        if ( v40->m_motion.m_type.m_storage == 5 )
        {
          hkpVehicleDefaultSimulation::handleFixedGroundAccum(v12, v40, v33);
LABEL_20:
          v27 = groundAccum;
          goto LABEL_21;
        }
        if ( v26 <= 0 || v40 != *groundBody )
        {
          frictionParams = (hkpVehicleFrictionSolverParams *)&v40->m_motion;
          hkRigidMotionUtilBuildAccumulators(stepInfo, (hkpMotion *const *)&frictionParams, 1, 0, v33);
          v41 = frictionParams;
          v42 = _mm_shuffle_ps(
                  vehicleInstance->m_entity->m_motion.m_inertiaAndMassInv.m_quad,
                  vehicleInstance->m_entity->m_motion.m_inertiaAndMassInv.m_quad,
                  255);
          v43 = _mm_shuffle_ps(
                  *(__m128 *)&frictionParams->m_chassis.m_type.m_storage,
                  *(__m128 *)&frictionParams->m_chassis.m_type.m_storage,
                  255);
          v44 = _mm_shuffle_ps(
                  (__m128)LODWORD(vehicleInstance->m_data->m_maxFrictionSolverMassRatio),
                  (__m128)LODWORD(vehicleInstance->m_data->m_maxFrictionSolverMassRatio),
                  0);
          if ( (float)(v44.m128_f32[0] * v42.m128_f32[0]) < v43.m128_f32[0] )
          {
            v45 = _mm_rcp_ps(v43);
            *(__m128 *)&p_m_context[47].m_storage = _mm_mul_ps(
                                                      _mm_mul_ps(
                                                        v44,
                                                        _mm_mul_ps(
                                                          _mm_mul_ps(
                                                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v45, v43)),
                                                            v45),
                                                          v42)),
                                                      *(__m128 *)&p_m_context[47].m_storage);
          }
          m_quad = v41->m_axleParams[1].m_constraintNormalWs.m_quad;
          v47 = *(__m128 *)&v41->m_axleParams[1].m_forwardForce;
          v48 = _mm_shuffle_ps(m_quad, m_quad, 255);
          v49 = _mm_sub_ps(m_quad, v41->m_axleParams[1].m_contactPointWs.m_quad);
          p_m_context[v31 - 1] = p_m_context[-1];
          v50 = _mm_mul_ps(v47, v48);
          p_m_context[v31] = (hkEnum<enum hkpVelocityAccumulator::hkpAccumulatorContext,unsigned char>)p_m_context->m_storage;
          v51 = _mm_mul_ps(v49, v48);
          *(_DWORD *)&p_m_context[v31 + 3].m_storage = *(_DWORD *)&p_m_context[3].m_storage;
          *(_DWORD *)&p_m_context[v31 + 7].m_storage = *(_DWORD *)&p_m_context[7].m_storage;
          v52 = &groundAccumAtIntegration->m_type.m_storage + v57;
          *(_OWORD *)&p_m_context[v31 + 15].m_storage = *(_OWORD *)&p_m_context[15].m_storage;
          *(_OWORD *)&p_m_context[v31 + 31].m_storage = *(_OWORD *)&p_m_context[31].m_storage;
          *(_OWORD *)&p_m_context[v31 + 47].m_storage = *(_OWORD *)&p_m_context[47].m_storage;
          *(_OWORD *)&p_m_context[v31 + 63].m_storage = *(_OWORD *)&p_m_context[63].m_storage;
          *(_OWORD *)&p_m_context[v31 + 79].m_storage = *(_OWORD *)&p_m_context[79].m_storage;
          *(_OWORD *)&p_m_context[v31 + 95].m_storage = *(_OWORD *)&p_m_context[95].m_storage;
          *(_OWORD *)&p_m_context[v31 + 111].m_storage = *(_OWORD *)&p_m_context[111].m_storage;
          p_m_quad[1].m128_u64[1] = (unsigned __int64)v52;
          v53 = _mm_mul_ps(_mm_shuffle_ps(v50, v50, 85), *(__m128 *)&p_m_context[79].m_storage);
          v54 = _mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), *(__m128 *)&p_m_context[63].m_storage);
          v55 = _mm_mul_ps(_mm_shuffle_ps(v50, v50, 170), *(__m128 *)&p_m_context[95].m_storage);
          *(__m128 *)&p_m_context[v31 + 15].m_storage = v51;
          *(__m128 *)&p_m_context[v31 + 31].m_storage = _mm_add_ps(_mm_add_ps(v53, v54), v55);
          goto LABEL_20;
        }
        p_m_quad[1].m128_u64[0] = (unsigned __int64)v10->m_axleParams[0].m_groundObject;
        p_m_quad[1].m128_u64[1] = (unsigned __int64)v10->m_axleParams[0].m_groundObjectAtLastIntegration;
      }
      else
      {
        *(_WORD *)&p_m_context[-1].m_storage = 1;
        *(_DWORD *)&p_m_context[7].m_storage = 0;
        *(_OWORD *)&p_m_context[47].m_storage = 0i64;
        *(_OWORD *)&p_m_context[15].m_storage = 0i64;
        *(_OWORD *)&p_m_context[31].m_storage = 0i64;
        *(_OWORD *)&p_m_context[111].m_storage = 0i64;
        *(hkVector4f *)&p_m_context[63].m_storage = (hkVector4f)transform.m_quad;
        *(hkVector4f *)&p_m_context[79].m_storage = (hkVector4f)direction.m_quad;
        *(hkVector4f *)&p_m_context[95].m_storage = (hkVector4f)stru_141A71280.m_quad;
      }
LABEL_21:
      v12 = this;
      ++v26;
      p_m_quad += 6;
      ++v28;
      p_m_context += 128;
    }
    while ( v26 < vehicleInstance->m_data->m_numWheelsPerAxle.m_size );
  }
}

// File Line: 239
// RVA: 0xE2D640
void __fastcall hkpVehicleDefaultSimulation::handleFixedGroundAccum(
        hkpVehicleDefaultSimulation *this,
        hkpRigidBody *ground,
        hkpVelocityAccumulator *accum)
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
void __fastcall hkpVehicleDefaultSimulation::getAxleParamsFromWheel(
        hkpVehicleDefaultSimulation *this,
        hkpVehicleInstance *vehicleInstance,
        int w_it,
        float linearForceAtWheel,
        float suspensionForceAtWheel,
        float estimatedCarSpeed,
        hkpVehicleFrictionSolverAxleParams *axle_params)
{
  hkpVehicleInstance::WheelInfo *m_data; // r10
  hkpVehicleData *v8; // rbx
  __int64 v9; // r9
  __int64 v11; // r11
  __int64 m_axle; // rcx
  __int64 v13; // r8
  __m128 m_quad; // xmm7
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
  float v27; // xmm2_4
  bool v28; // zf
  float v29; // xmm8_4
  bool v30; // al

  m_data = vehicleInstance->m_wheelsInfo.m_data;
  v8 = vehicleInstance->m_data;
  v9 = w_it;
  v11 = w_it;
  m_axle = v8->m_wheelParams.m_data[w_it].m_axle;
  v13 = w_it;
  m_quad = m_data[v13].m_contactPoint.m_separatingNormal.m_quad;
  v15 = m_data[v13].m_spinAxisWs.m_quad;
  v16 = _mm_shuffle_ps(m_quad, m_quad, 201);
  v17 = _mm_shuffle_ps(v15, v15, 201);
  v18 = _mm_sub_ps(_mm_mul_ps(m_quad, v17), _mm_mul_ps(v16, v15));
  v19 = _mm_shuffle_ps(v18, v18, 201);
  v20 = _mm_mul_ps(v19, v19);
  if ( (float)((float)(_mm_shuffle_ps(v20, v20, 85).m128_f32[0] + _mm_shuffle_ps(v20, v20, 0).m128_f32[0])
             + _mm_shuffle_ps(v20, v20, 170).m128_f32[0]) < 0.00000011920929 )
  {
    v21 = _mm_sub_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(
                m_data[v13].m_suspensionDirectionWs.m_quad,
                m_data[v13].m_suspensionDirectionWs.m_quad,
                201),
              v15),
            _mm_mul_ps(m_data[v13].m_suspensionDirectionWs.m_quad, v17));
    v19 = _mm_shuffle_ps(v21, v21, 201);
  }
  v22 = _mm_mul_ps(v19, v19);
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)), _mm_shuffle_ps(v22, v22, 170));
  v24 = _mm_rsqrt_ps(v23);
  v25 = _mm_mul_ps(
          v19,
          _mm_andnot_ps(
            _mm_cmple_ps(v23, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
              _mm_mul_ps(*(__m128 *)_xmm, v24))));
  v26 = _mm_sub_ps(_mm_mul_ps(v16, v25), _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), m_quad));
  v27 = 1.0 / (float)v8->m_numWheelsPerAxle.m_data[m_axle];
  v22.m128_f32[0] = v27 * m_data[v13].m_contactFriction;
  axle_params->m_contactPointWs.m_quad = _mm_add_ps(
                                           _mm_mul_ps(
                                             _mm_shuffle_ps((__m128)LODWORD(v27), (__m128)LODWORD(v27), 0),
                                             m_data[v13].m_contactPoint.m_position.m_quad),
                                           axle_params->m_contactPointWs.m_quad);
  axle_params->m_constraintNormalWs.m_quad = _mm_add_ps(
                                               _mm_shuffle_ps(v26, v26, 201),
                                               axle_params->m_constraintNormalWs.m_quad);
  axle_params->m_forwardDirWs.m_quad = _mm_add_ps(v25, axle_params->m_forwardDirWs.m_quad);
  v28 = axle_params->m_wheelFixed == 0;
  v29 = linearForceAtWheel + axle_params->m_forwardForce;
  axle_params->m_frictionCoefficient = (float)(v22.m128_f32[0]
                                             * vehicleInstance->m_data->m_wheelParams.m_data[v11].m_friction)
                                     + axle_params->m_frictionCoefficient;
  axle_params->m_viscosityFrictionCoefficient = (float)(v22.m128_f32[0]
                                                      * vehicleInstance->m_data->m_wheelParams.m_data[v11].m_viscosityFriction)
                                              + axle_params->m_viscosityFrictionCoefficient;
  v22.m128_f32[0] = v22.m128_f32[0] * vehicleInstance->m_data->m_wheelParams.m_data[v11].m_maxFriction;
  axle_params->m_wheelDownForce = suspensionForceAtWheel + axle_params->m_wheelDownForce;
  axle_params->m_forwardForce = v29;
  axle_params->m_maxFrictionCoefficient = v22.m128_f32[0] + axle_params->m_maxFrictionCoefficient;
  v30 = !v28 || vehicleInstance->m_isFixed.m_data[v9].m_bool;
  axle_params->m_wheelFixed = v30;
  axle_params->m_slipVelocityFactor = (float)((float)(v27
                                                    * vehicleInstance->m_data->m_wheelParams.m_data[v11].m_slipAngle)
                                            * estimatedCarSpeed)
                                    + axle_params->m_slipVelocityFactor;
}

// File Line: 290
// RVA: 0xE2D8F0
void __fastcall hkpVehicleDefaultSimulation::prepareChassisParams(
        hkpVehicleDefaultSimulation *this,
        hkpVehicleInstance *vehicleInstance,
        hkStepInfo *stepInfo,
        hkpVehicleFrictionSolverParams *frictionParams)
{
  hkpVelocityAccumulator *p_m_chassis; // rdi
  hkVector4f v7; // xmm6
  __m128 v8; // xmm1
  hkpVehicleData *m_data; // rax
  hkVector4f v10; // xmm6
  hkVector4f b; // [rsp+30h] [rbp-28h] BYREF
  hkpMotion *motions; // [rsp+68h] [rbp+10h] BYREF

  p_m_chassis = &frictionParams->m_chassis;
  motions = &vehicleInstance->m_entity->m_motion;
  hkRigidMotionUtilBuildAccumulators(stepInfo, &motions, 1, 0, &frictionParams->m_chassis);
  v7.m_quad = (__m128)motions->m_motionState.m_sweptTransform.m_centerOfMass1;
  v8 = _mm_shuffle_ps(v7.m_quad, v7.m_quad, 255);
  m_data = vehicleInstance->m_data;
  v10.m_quad = _mm_mul_ps(_mm_sub_ps(v7.m_quad, motions->m_motionState.m_sweptTransform.m_centerOfMass0.m_quad), v8);
  b.m_quad = _mm_mul_ps(motions->m_motionState.m_deltaAngle.m_quad, v8);
  frictionParams->m_chassis.m_invMasses = m_data->m_chassisFrictionInertiaInvDiag;
  frictionParams->m_chassisAtLastIntegration.m_type.m_storage = p_m_chassis->m_type.m_storage;
  frictionParams->m_chassisAtLastIntegration.m_context.m_storage = p_m_chassis->m_context.m_storage;
  frictionParams->m_chassisAtLastIntegration.m_deactivationClass = p_m_chassis->m_deactivationClass;
  frictionParams->m_chassisAtLastIntegration.m_gravityFactor = p_m_chassis->m_gravityFactor;
  frictionParams->m_chassisAtLastIntegration.m_linearVel = p_m_chassis->m_linearVel;
  frictionParams->m_chassisAtLastIntegration.m_angularVel = p_m_chassis->m_angularVel;
  frictionParams->m_chassisAtLastIntegration.m_invMasses = p_m_chassis->m_invMasses;
  frictionParams->m_chassisAtLastIntegration.m_scratch0 = p_m_chassis->m_scratch0;
  frictionParams->m_chassisAtLastIntegration.m_scratch1 = p_m_chassis->m_scratch1;
  frictionParams->m_chassisAtLastIntegration.m_scratch2 = p_m_chassis->m_scratch2;
  frictionParams->m_chassisAtLastIntegration.m_scratch3 = p_m_chassis->m_scratch3;
  hkVector4f::setRotatedDir(
    &frictionParams->m_chassisAtLastIntegration.m_angularVel,
    (hkMatrix3f *)&frictionParams->m_chassis.m_scratch0,
    &b);
  frictionParams->m_chassisAtLastIntegration.m_linearVel = (hkVector4f)v10.m_quad;
}

// File Line: 310
// RVA: 0xE2DA20
void __fastcall hkpVehicleDefaultSimulation::applyAerodynamicDrag(
        hkpVehicleDefaultSimulation *this,
        hkpVehicleInstance *vehicleInstance,
        hkpVehicleAerodynamics::AerodynamicsDragOutput *aerodynamicsDragInfo,
        hkpVehicleFrictionSolverParams *frictionParams,
        unsigned int deltaTime)
{
  hkpEntity *m_entity; // rax
  __m128 v6; // xmm2
  __m128 m_quad; // xmm3
  __m128 v8; // xmm0
  __m128 v9; // xmm6
  __m128 v10; // xmm1
  __m128 v11; // xmm4
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm5

  m_entity = vehicleInstance->m_entity;
  v6 = _mm_shuffle_ps((__m128)deltaTime, (__m128)deltaTime, 0);
  frictionParams->m_chassis.m_linearVel.m_quad = _mm_add_ps(
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(
                                                       m_entity->m_motion.m_inertiaAndMassInv.m_quad,
                                                       m_entity->m_motion.m_inertiaAndMassInv.m_quad,
                                                       255),
                                                     _mm_mul_ps(aerodynamicsDragInfo->m_aerodynamicsForce.m_quad, v6)),
                                                   frictionParams->m_chassis.m_linearVel.m_quad);
  m_quad = m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad;
  v8 = m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad;
  v9 = _mm_mul_ps(aerodynamicsDragInfo->m_aerodynamicsTorque.m_quad, v6);
  v10 = m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad;
  v11 = _mm_unpackhi_ps(v10, v8);
  v12 = _mm_unpacklo_ps(v10, v8);
  v13 = _mm_movelh_ps(v12, m_quad);
  v14 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(_mm_movehl_ps(v13, v12), m_quad, 212)),
              _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), v13)),
            _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), _mm_shuffle_ps(v11, m_quad, 228))),
          m_entity->m_motion.m_inertiaAndMassInv.m_quad);
  frictionParams->m_chassis.m_angularVel.m_quad = _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v8),
                                                        _mm_mul_ps(
                                                          _mm_shuffle_ps(v14, v14, 0),
                                                          m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
                                                      _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), m_quad)),
                                                    frictionParams->m_chassis.m_angularVel.m_quad);
}

// File Line: 330
// RVA: 0xE2DB10
void __fastcall hkpVehicleDefaultSimulation::applyVelocityDamping(
        hkpVehicleDefaultSimulation *this,
        const float deltaTime,
        hkpVehicleFrictionSolverParams *frictionParams,
        hkpVehicleVelocityDamper *damper)
{
  hkVector4f v4; // xmm4
  __m128 v5; // xmm2
  float v6; // xmm2_4

  v4.m_quad = (__m128)frictionParams->m_chassis.m_angularVel;
  v5 = _mm_mul_ps(v4.m_quad, v4.m_quad);
  if ( (float)((float)(_mm_shuffle_ps(v5, v5, 85).m128_f32[0] + _mm_shuffle_ps(v5, v5, 0).m128_f32[0])
             + _mm_shuffle_ps(v5, v5, 170).m128_f32[0]) <= (float)(*(float *)&damper[1].m_memSizeAndFlags
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
void __fastcall hkpVehicleDefaultSimulation::applySuspensionForces(
        hkpVehicleDefaultSimulation *this,
        hkpVehicleInstance *vehicleInstance,
        float deltaTime,
        hkArray<float,hkContainerHeapAllocator> *suspensionForceAtWheel,
        hkpRigidBody **groundBody,
        hkpVehicleFrictionSolverParams *frictionParams,
        hkVector4f *suspensionForcesOnGround)
{
  hkpVehicleData *m_data; // rcx
  int v8; // edi
  hkArray<float,hkContainerHeapAllocator> *v9; // rax
  __int64 v13; // r14
  __int64 v14; // rbp
  __int64 v15; // r15
  hkpVehicleInstance::WheelInfo *v16; // r12
  hkpRigidBody *m_contactBody; // rbx
  __m128 v18; // xmm7
  hkpEntity *m_entity; // rax
  __m128 m_quad; // xmm3
  __m128 v21; // xmm1
  __m128 v22; // xmm6
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  __m128 v25; // xmm6
  __m128 v26; // xmm2
  __m128 v27; // xmm5
  hkpVehicleData::WheelComponentParams *v28; // rdx
  __m128 m_forceFeedbackMultiplier_low; // xmm1
  __m128 v30; // xmm7
  __m128 v31; // xmm1
  __m128 v32; // xmm5
  __m128 v33; // xmm4
  __m128 v34; // xmm2
  hkpVelocityAccumulator *m_groundObject; // rax
  __m128 v36; // xmm3
  hkpVelocityAccumulator *v37; // rax
  __m128 v38; // xmm1
  __m128 v39; // xmm7
  __m128 v40; // xmm0
  __m128 v41; // xmm1
  __m128 v42; // xmm7
  __m128 v43; // xmm2
  __m128 v44; // xmm5
  int m_axle; // [rsp+20h] [rbp-98h]
  hkpVehicleData *v46; // [rsp+28h] [rbp-90h]
  unsigned int v47; // [rsp+C8h] [rbp+10h]

  m_data = vehicleInstance->m_data;
  v8 = 0;
  v9 = suspensionForceAtWheel;
  v46 = m_data;
  if ( m_data->m_numWheels )
  {
    v13 = 0i64;
    v14 = 0i64;
    v15 = 0i64;
    do
    {
      v16 = vehicleInstance->m_wheelsInfo.m_data;
      m_contactBody = v16[v14].m_contactBody;
      v18 = _mm_mul_ps(
              _mm_shuffle_ps(
                (__m128)COERCE_UNSIGNED_INT(v9->m_data[v15] * deltaTime),
                (__m128)COERCE_UNSIGNED_INT(v9->m_data[v15] * deltaTime),
                0),
              v16[v14].m_contactPoint.m_separatingNormal.m_quad);
      if ( v9->m_data[v15] > 0.0 )
      {
        frictionParams->m_chassis.m_linearVel.m_quad = _mm_add_ps(
                                                         _mm_mul_ps(
                                                           _mm_shuffle_ps(
                                                             vehicleInstance->m_entity->m_motion.m_inertiaAndMassInv.m_quad,
                                                             vehicleInstance->m_entity->m_motion.m_inertiaAndMassInv.m_quad,
                                                             255),
                                                           v18),
                                                         frictionParams->m_chassis.m_linearVel.m_quad);
        m_entity = vehicleInstance->m_entity;
        m_quad = m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad;
        v21 = _mm_sub_ps(
                v16[v14].m_hardPointWs.m_quad,
                m_entity->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
        v22 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v21), _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v18));
        v23 = m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad;
        v24 = _mm_unpacklo_ps(m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad, v23);
        v25 = _mm_shuffle_ps(v22, v22, 201);
        v26 = _mm_movelh_ps(v24, m_quad);
        v27 = _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(_mm_movehl_ps(v26, v24), m_quad, 212)),
                    _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v26)),
                  _mm_mul_ps(
                    _mm_shuffle_ps(
                      _mm_unpackhi_ps(m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad, v23),
                      m_quad,
                      228),
                    _mm_shuffle_ps(v25, v25, 170))),
                m_entity->m_motion.m_inertiaAndMassInv.m_quad);
        frictionParams->m_chassis.m_angularVel.m_quad = _mm_add_ps(
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_mul_ps(_mm_shuffle_ps(v27, v27, 85), v23),
                                                              _mm_mul_ps(
                                                                _mm_shuffle_ps(v27, v27, 0),
                                                                m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
                                                            _mm_mul_ps(_mm_shuffle_ps(v27, v27, 170), m_quad)),
                                                          frictionParams->m_chassis.m_angularVel.m_quad);
      }
      if ( m_contactBody && m_contactBody->m_motion.m_type.m_storage != 5 )
      {
        v28 = m_data->m_wheelParams.m_data;
        m_axle = v28[v13].m_axle;
        m_forceFeedbackMultiplier_low = (__m128)LODWORD(v28[v8].m_forceFeedbackMultiplier);
        v30 = _mm_mul_ps(
                v18,
                _mm_sub_ps(
                  (__m128)0i64,
                  _mm_shuffle_ps(m_forceFeedbackMultiplier_low, m_forceFeedbackMultiplier_low, 0)));
        v31 = _mm_mul_ps(v30, v30);
        *(float *)&v47 = (float)(hkpMotion::getMass(&m_contactBody->m_motion)
                               * v46->m_wheelParams.m_data[v13].m_maxContactBodyAcceleration)
                       * deltaTime;
        v32 = _mm_shuffle_ps((__m128)v47, (__m128)v47, 0);
        v33 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                _mm_shuffle_ps(v31, v31, 170));
        if ( (float)(v32.m128_f32[0] * v32.m128_f32[0]) < v33.m128_f32[0] )
        {
          v34 = _mm_rsqrt_ps(v33);
          v30 = _mm_mul_ps(
                  v30,
                  _mm_mul_ps(
                    _mm_andnot_ps(
                      _mm_cmple_ps(v33, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
                        _mm_mul_ps(*(__m128 *)_xmm, v34))),
                    v32));
        }
        if ( m_contactBody != groundBody[m_axle] )
        {
          *suspensionForcesOnGround = (hkVector4f)v30;
          goto LABEL_12;
        }
        m_groundObject = frictionParams->m_axleParams[m_axle].m_groundObject;
        m_groundObject->m_linearVel.m_quad = _mm_add_ps(
                                               _mm_mul_ps(
                                                 _mm_shuffle_ps(
                                                   m_contactBody->m_motion.m_inertiaAndMassInv.m_quad,
                                                   m_contactBody->m_motion.m_inertiaAndMassInv.m_quad,
                                                   255),
                                                 v30),
                                               m_groundObject->m_linearVel.m_quad);
        v36 = m_contactBody->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad;
        v37 = frictionParams->m_axleParams[m_axle].m_groundObject;
        v38 = _mm_sub_ps(
                v16[v14].m_hardPointWs.m_quad,
                m_contactBody->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
        v39 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v38), _mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), v30));
        v40 = m_contactBody->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad;
        v41 = _mm_unpacklo_ps(m_contactBody->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad, v40);
        v42 = _mm_shuffle_ps(v39, v39, 201);
        v43 = _mm_movelh_ps(v41, v36);
        v44 = _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(_mm_movehl_ps(v43, v41), v36, 212)),
                    _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), v43)),
                  _mm_mul_ps(
                    _mm_shuffle_ps(v42, v42, 170),
                    _mm_shuffle_ps(
                      _mm_unpackhi_ps(m_contactBody->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad, v40),
                      v36,
                      228))),
                m_contactBody->m_motion.m_inertiaAndMassInv.m_quad);
        v37->m_angularVel.m_quad = _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(v44, v44, 85), v40),
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(v44, v44, 0),
                                           m_contactBody->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
                                       _mm_mul_ps(_mm_shuffle_ps(v44, v44, 170), v36)),
                                     v37->m_angularVel.m_quad);
      }
      *suspensionForcesOnGround = 0i64;
LABEL_12:
      ++v8;
      ++v14;
      v9 = suspensionForceAtWheel;
      ++v15;
      ++v13;
      ++suspensionForcesOnGround;
      m_data = v46;
    }
    while ( v8 < (unsigned __int8)vehicleInstance->m_data->m_numWheels );
  }
}

// File Line: 435
// RVA: 0xE2DFE0
void __fastcall hkpVehicleDefaultSimulation::applyDampingToAxleAccumulators(
        hkpVehicleDefaultSimulation *this,
        hkStepInfo *stepInfo,
        hkpRigidBody **groundBodies,
        hkpVehicleFrictionSolverParams *frictionParams,
        hkVector4f *originalLinearVels,
        hkVector4f *originalAngularVels)
{
  __int64 v6; // rcx
  __m128 v7; // xmm3
  __m128 v8; // xmm1
  hkpVelocityAccumulator *m_groundObject; // rax
  __m128 m_quad; // xmm2
  hkpRigidBody *v11; // rcx
  __m128 v12; // xmm1
  hkpVelocityAccumulator *v13; // rax
  __m128 v14; // xmm2
  unsigned int v15; // [rsp+10h] [rbp+10h]
  unsigned int v16; // [rsp+10h] [rbp+10h]

  v6 = (__int64)*groundBodies;
  v7 = _mm_shuffle_ps(
         (__m128)LODWORD(stepInfo->m_deltaTime.m_storage),
         (__m128)LODWORD(stepInfo->m_deltaTime.m_storage),
         0);
  if ( *groundBodies && *(_BYTE *)(v6 + 352) != 5 )
  {
    v8 = (__m128)(unsigned int)(*(__int16 *)(v6 + 532) << 16);
    v15 = *(__int16 *)(v6 + 534) << 16;
    m_groundObject = frictionParams->m_axleParams[0].m_groundObject;
    m_groundObject->m_linearVel.m_quad = _mm_mul_ps(
                                           _mm_max_ps(
                                             (__m128)0i64,
                                             _mm_sub_ps(query.m_quad, _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), v7))),
                                           m_groundObject->m_linearVel.m_quad);
    m_groundObject->m_angularVel.m_quad = _mm_mul_ps(
                                            _mm_max_ps(
                                              (__m128)0i64,
                                              _mm_sub_ps(
                                                query.m_quad,
                                                _mm_mul_ps(_mm_shuffle_ps((__m128)v15, (__m128)v15, 0), v7))),
                                            m_groundObject->m_angularVel.m_quad);
    *originalLinearVels = m_groundObject->m_linearVel;
    *originalAngularVels = m_groundObject->m_angularVel;
    m_quad = m_groundObject->m_angularVel.m_quad;
    m_groundObject->m_angularVel.m_quad = _mm_add_ps(
                                            _mm_add_ps(
                                              _mm_mul_ps(
                                                _mm_shuffle_ps(m_quad, m_quad, 85),
                                                m_groundObject->m_scratch1.m_quad),
                                              _mm_mul_ps(
                                                _mm_shuffle_ps(m_quad, m_quad, 0),
                                                m_groundObject->m_scratch0.m_quad)),
                                            _mm_mul_ps(
                                              _mm_shuffle_ps(m_quad, m_quad, 170),
                                              m_groundObject->m_scratch2.m_quad));
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
                                   _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v13->m_scratch0.m_quad)),
                                 _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v13->m_scratch2.m_quad));
  }
}

// File Line: 487
// RVA: 0xE2E190
void __fastcall hkpVehicleDefaultSimulation::applyDampingToChassisAccumulator(
        hkpVehicleDefaultSimulation *this,
        hkStepInfo *stepInfo,
        hkpVelocityAccumulator *accumulator,
        hkpMotion *motion)
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
void __fastcall hkpVehicleDefaultSimulation::getExtraTorqueFactor(
        hkpVehicleDefaultSimulation *this,
        hkpVehicleInstance *vehicleInstance,
        float deltaTime,
        hkpVelocityAccumulator *accumulatorForChassis)
{
  hkpVehicleData *m_data; // rax
  float m_extraTorqueFactor; // xmm1_4

  m_data = vehicleInstance->m_data;
  m_extraTorqueFactor = m_data->m_extraTorqueFactor;
  if ( m_extraTorqueFactor != 0.0 )
    accumulatorForChassis->m_angularVel.m_quad = _mm_add_ps(
                                                   _mm_mul_ps(
                                                     _mm_mul_ps(
                                                       _mm_shuffle_ps(
                                                         (__m128)COERCE_UNSIGNED_INT(
                                                                   (float)(m_extraTorqueFactor
                                                                         * vehicleInstance->m_mainSteeringAngleAssumingNoReduction)
                                                                 * deltaTime),
                                                         (__m128)COERCE_UNSIGNED_INT(
                                                                   (float)(m_extraTorqueFactor
                                                                         * vehicleInstance->m_mainSteeringAngleAssumingNoReduction)
                                                                 * deltaTime),
                                                         0),
                                                       m_data->m_chassisOrientation.m_col0.m_quad),
                                                     m_data->m_chassisFrictionInertiaInvDiag.m_quad),
                                                   accumulatorForChassis->m_angularVel.m_quad);
}

// File Line: 524
// RVA: 0xE2E290
void __fastcall hkpVehicleDefaultSimulation::applyFrictionSolver(
        hkpVehicleDefaultSimulation *this,
        hkpVehicleInstance *vehicleInstance,
        hkStepInfo *stepInfo,
        hkpVehicleFrictionSolverParams *frictionParams,
        hkpVehicleFrictionStatus *frictionStatus)
{
  float m_storage; // xmm1_4
  hkpVehicleFrictionDescription *m_pntr; // rdx
  hkpVehicleStepInfo stepInfoa; // [rsp+30h] [rbp+8h] BYREF

  m_storage = stepInfo->m_invDeltaTime.m_storage;
  m_pntr = this->m_frictionDescription.m_pntr;
  stepInfoa.m_deltaTime = stepInfo->m_deltaTime.m_storage;
  stepInfoa.m_invDeltaTime = m_storage;
  hkVehicleFrictionApplyVehicleFriction(&stepInfoa, m_pntr, frictionParams, frictionStatus);
}

// File Line: 534
// RVA: 0xE2E2D0
void __fastcall hkpVehicleDefaultSimulation::calcChassisVelocities(
        hkpVehicleDefaultSimulation *this,
        hkpVehicleInstance *vehicleInstance,
        hkpVelocityAccumulator *accumulatorForChassis,
        hkpVehicleJobResults *vehicleResults)
{
  hkpEntity *m_entity; // rax
  hkVector4f v5; // xmm1

  m_entity = vehicleInstance->m_entity;
  vehicleResults->m_chassisLinearVel = accumulatorForChassis->m_linearVel;
  v5.m_quad = (__m128)accumulatorForChassis->m_angularVel;
  vehicleResults->m_chassisAngularVel.m_quad = _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(v5.m_quad, v5.m_quad, 85),
                                                     m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(v5.m_quad, v5.m_quad, 0),
                                                     m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
                                                 _mm_mul_ps(
                                                   _mm_shuffle_ps(v5.m_quad, v5.m_quad, 170),
                                                   m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
}

// File Line: 544
// RVA: 0xE2E320
// local variable allocation has failed, the output may be wrong!
void __fastcall hkpVehicleDefaultSimulation::calcGroundBodyVelocities(
        hkpVehicleDefaultSimulation *this,
        hkpVehicleInstance *vehicleInstance,
        double deltaTime,
        hkpVehicleFrictionSolverAxleParams *axleParams,
        hkpRigidBody **groundBody,
        hkpVehicleJobResults *vehicleResults,
        hkVector4f *originalLinearVels,
        hkVector4f *originalAngularVels)
{
  hkpVehicleData *m_data; // rbx
  int v9; // edx
  __m128 v11; // xmm13
  hkVector4f *m_groundBodyAngularVel; // r9
  __m128 **p_m_groundObject; // r11
  hkpRigidBody **v14; // rcx
  signed __int64 v15; // r10
  __m128 v16; // xmm11
  __m128 v17; // xmm11
  __m128 v18; // xmm8
  __m128 v19; // xmm1
  __m128 v20; // xmm10
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm4
  __m128 v26; // xmm7
  __m128 v27; // xmm12

  m_data = vehicleInstance->m_data;
  v9 = 0;
  v11 = *(__m128 *)&deltaTime;
  if ( m_data->m_numWheelsPerAxle.m_size > 0 )
  {
    m_groundBodyAngularVel = vehicleResults->m_groundBodyAngularVel;
    p_m_groundObject = (__m128 **)&axleParams->m_groundObject;
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
        v18 = (*p_m_groundObject)[6];
        v19 = (*p_m_groundObject)[4];
        v20 = _mm_unpackhi_ps(v19, (*p_m_groundObject)[5]);
        v21 = _mm_unpacklo_ps(v19, (*p_m_groundObject)[5]);
        v22 = _mm_movelh_ps(v21, v18);
        v23 = _mm_movehl_ps(v22, v21);
        v24 = (*p_m_groundObject)[2];
        v25 = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, (__m128)0i64), 196);
        v26 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
        v27 = _mm_add_ps(
                _mm_max_ps(
                  _mm_min_ps(
                    _mm_sub_ps(
                      (*p_m_groundObject)[1],
                      *(__m128 *)((char *)&m_groundBodyAngularVel[-4].m_quad
                                + (char *)originalLinearVels
                                - (char *)vehicleResults)),
                    v25),
                  _mm_xor_ps(v26, v25)),
                *(__m128 *)((char *)&m_groundBodyAngularVel[-4].m_quad
                          + (char *)originalLinearVels
                          - (char *)vehicleResults));
        m_groundBodyAngularVel->m_quad = _mm_add_ps(
                                           _mm_max_ps(
                                             _mm_min_ps(
                                               _mm_sub_ps(
                                                 _mm_add_ps(
                                                   _mm_add_ps(
                                                     _mm_mul_ps(
                                                       _mm_shuffle_ps(v24, v24, 85),
                                                       _mm_shuffle_ps(v23, v18, 212)),
                                                     _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v22)),
                                                   _mm_mul_ps(
                                                     _mm_shuffle_ps(v24, v24, 170),
                                                     _mm_shuffle_ps(v20, v18, 228))),
                                                 *(__m128 *)((char *)&m_groundBodyAngularVel[-4].m_quad
                                                           + (char *)originalAngularVels
                                                           - (char *)vehicleResults)),
                                               v25),
                                             _mm_xor_ps(v26, v25)),
                                           *(__m128 *)((char *)&m_groundBodyAngularVel[-4].m_quad
                                                     + (char *)originalAngularVels
                                                     - (char *)vehicleResults));
        m_groundBodyAngularVel[-2] = (hkVector4f)v27;
        *(hkpRigidBody **)((char *)v14 + v15 + 96) = *v14;
      }
      ++v9;
      p_m_groundObject += 12;
      ++m_groundBodyAngularVel;
      ++v14;
    }
    while ( v9 < m_data->m_numWheelsPerAxle.m_size );
  }
}

// File Line: 597
// RVA: 0xE2CB30
void __fastcall hkpVehicleDefaultSimulation::init(hkpVehicleDefaultSimulation *this, hkpVehicleInstance *instance)
{
  hkpEntity *m_entity; // rbx
  hkpVehicleData *m_data; // rsi
  __m128 m_quad; // xmm2
  hkVector4f v7; // xmm0
  hkVector4f v8; // xmm1
  int m_numWheels; // eax
  __m128i v10; // xmm0
  hkVector4f v11; // xmm1
  hkpVehicleSuspension *m_suspension; // rbx
  hkpVehicleData::WheelComponentParams *v13; // r8
  __int64 v14; // r9
  __int64 v15; // r10
  __int64 v16; // r11
  __int64 m_axle; // rdx
  __int64 v18; // rcx
  _QWORD **Value; // rax
  __int64 v20; // rax
  hkpVehicleFrictionDescription *v21; // rbx
  hkpVehicleFrictionDescription *m_pntr; // rcx
  hkMatrix3f aTb; // [rsp+20h] [rbp-E8h] BYREF
  hkpVehicleFrictionDescription::Cinfo ci; // [rsp+50h] [rbp-B8h] BYREF

  m_entity = instance->m_entity;
  m_data = instance->m_data;
  m_quad = m_data->m_chassisFrictionInertiaInvDiag.m_quad;
  ci.m_chassisCenterOfMass = m_entity->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal;
  v7.m_quad = _mm_mul_ps(
                _mm_shuffle_ps(m_quad, m_quad, 0),
                m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad);
  v8.m_quad = _mm_mul_ps(
                _mm_shuffle_ps(m_quad, m_quad, 85),
                m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad);
  aTb.m_col2.m_quad = _mm_mul_ps(
                        _mm_shuffle_ps(m_quad, m_quad, 170),
                        m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad);
  aTb.m_col0 = (hkVector4f)v7.m_quad;
  aTb.m_col1 = (hkVector4f)v8.m_quad;
  hkMatrix3f::setMulInverse(
    &ci.m_chassisFrictionInertiaInv,
    &aTb,
    &m_entity->m_motion.m_motionState.m_transform.m_rotation);
  m_numWheels = m_data->m_numWheels;
  LODWORD(ci.m_chassisMassInv) = m_entity->m_motion.m_inertiaAndMassInv.m_quad.m128_i32[3];
  *(_QWORD *)ci.m_wheelAxleAngularInertia = 0i64;
  v10 = _mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&m_data->m_chassisOrientation.m_col1), 1u), 1u);
  ci.m_directionUp = (hkVector4f)_mm_srli_epi32(
                                   _mm_slli_epi32(_mm_load_si128((const __m128i *)&m_data->m_chassisOrientation), 1u),
                                   1u);
  v11.m_quad = (__m128)_mm_srli_epi32(
                         _mm_slli_epi32(_mm_load_si128((const __m128i *)&m_data->m_chassisOrientation.m_col2), 1u),
                         1u);
  ci.m_directionFront = (hkVector4f)v10;
  v10.m128i_i32[0] = LODWORD(m_data->m_frictionEqualizer);
  ci.m_directionRight = (hkVector4f)v11.m_quad;
  LODWORD(ci.m_frictionEqualizer) = v10.m128i_i32[0];
  if ( m_numWheels > 0 )
  {
    m_suspension = instance->m_suspension;
    v13 = m_data->m_wheelParams.m_data;
    v14 = 0i64;
    v15 = 0i64;
    v16 = (unsigned int)m_numWheels;
    do
    {
      ++v15;
      ++v14;
      m_axle = v13->m_axle;
      v18 = v13->m_axle;
      ci.m_wheelRadius[m_axle] = v13->m_radius;
      ++v13;
      ci.m_wheelPosition[v18].m_quad = _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(
                                             (__m128)LODWORD(m_suspension->m_wheelParams.m_data[v15 - 1].m_length),
                                             (__m128)LODWORD(m_suspension->m_wheelParams.m_data[v15 - 1].m_length),
                                             0),
                                           m_suspension->m_wheelParams.m_data[v14 - 1].m_directionChassisSpace.m_quad),
                                         m_suspension->m_wheelParams.m_data[v14 - 1].m_hardpointChassisSpace.m_quad);
      ci.m_wheelAxleAngularInertia[m_axle] = (float)(v13[-1].m_mass * v13[-1].m_radius)
                                           + ci.m_wheelAxleAngularInertia[m_axle];
      --v16;
    }
    while ( v16 );
  }
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v20 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 224i64);
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
  m_pntr = this->m_frictionDescription.m_pntr;
  if ( m_pntr && m_pntr != v21 )
    hkReferencedObject::removeReference(m_pntr);
  this->m_frictionDescription.m_pntr = v21;
  hkVehicleFrictionDescriptionInitValues(&ci, v21);
}

// File Line: 645
// RVA: 0xE2CD30
hkpVehicleSimulation *__fastcall hkpVehicleDefaultSimulation::clone(
        hkpVehicleDefaultSimulation *this,
        hkpVehicleInstance *instance)
{
  _QWORD **Value; // rax
  hkpVehicleDefaultSimulation *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rbx
  hkpVehicleFrictionDescription *m_pntr; // rcx
  hkReferencedObject *v8; // rcx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (hkpVehicleDefaultSimulation *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                        Value[11],
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
  m_pntr = this->m_frictionDescription.m_pntr;
  if ( m_pntr )
    hkReferencedObject::addReference(m_pntr);
  v8 = *(hkReferencedObject **)(v6 + 88);
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  *(_QWORD *)(v6 + 88) = this->m_frictionDescription.m_pntr;
  return (hkpVehicleSimulation *)v6;
}

