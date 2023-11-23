// File Line: 18
// RVA: 0xE2F0B0
void __fastcall hkpVehiclePerWheelSimulation::hkpVehiclePerWheelSimulation(hkpVehiclePerWheelSimulation *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->hkpVehicleSimulation::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpVehiclePerWheelSimulation::`vftable{for `hkpVehicleSimulation};
  this->hkpWorldPostSimulationListener::vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpVehiclePerWheelSimulation::`vftable{for `hkpWorldPostSimulationListener};
  this->m_wheelData.m_capacityAndFlags = 0x80000000;
  this->m_wheelData.m_data = 0i64;
  this->m_wheelData.m_size = 0;
  this->m_world = 0i64;
  this->m_slipDamping = 0.30000001;
  this->m_impulseScaling = 0.050000001;
  this->m_maxImpulse = 2.0;
  this->m_takeDynamicVelocity = 1.0;
  this->m_curbDamping = 10.0;
}

// File Line: 29
// RVA: 0xE2F110
void __fastcall hkpVehiclePerWheelSimulation::~hkpVehiclePerWheelSimulation(hkpVehiclePerWheelSimulation *this)
{
  bool v1; // zf
  int v3; // eax
  __int64 v4; // rcx
  hkpWheelFrictionConstraintData *p_m_frictionData; // rdx
  int m_capacityAndFlags; // r8d

  v1 = this->m_world == 0i64;
  this->hkpVehicleSimulation::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpVehiclePerWheelSimulation::`vftable{for `hkpVehicleSimulation};
  this->hkpWorldPostSimulationListener::vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpVehiclePerWheelSimulation::`vftable{for `hkpWorldPostSimulationListener};
  if ( !v1 )
    hkpVehiclePerWheelSimulation::removeFromWorld(this);
  v3 = this->m_wheelData.m_size - 1;
  v4 = v3;
  if ( v3 >= 0 )
  {
    p_m_frictionData = &this->m_wheelData.m_data[v3].m_frictionData;
    do
    {
      --v4;
      p_m_frictionData->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
      p_m_frictionData = (hkpWheelFrictionConstraintData *)((char *)p_m_frictionData - 336);
    }
    while ( v4 >= 0 );
  }
  m_capacityAndFlags = this->m_wheelData.m_capacityAndFlags;
  this->m_wheelData.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_wheelData.m_data,
      336 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_wheelData.m_data = 0i64;
  this->m_wheelData.m_capacityAndFlags = 0x80000000;
  this->hkpWorldPostSimulationListener::vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpWorldPostSimulationListener::`vftable;
  this->hkpVehicleSimulation::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 40
// RVA: 0xE2F1E0
void __fastcall hkpVehiclePerWheelSimulation::init(hkpVehiclePerWheelSimulation *this, hkpVehicleInstance *instance)
{
  hkpVehicleData *m_data; // r15
  __int64 m_numWheels; // rbx
  int v4; // eax
  int v6; // eax
  int v7; // r9d
  int v8; // eax
  __int64 v9; // rcx
  hkpWheelFrictionConstraintData *p_m_frictionData; // rdx
  int m_size; // eax
  __int64 v12; // rdx
  float *m_frictionImpulse; // rcx
  int v14; // ebp
  __int64 v15; // rbx
  __int64 v16; // rdi
  hkpVehicleData::WheelComponentParams *v17; // r8
  float m_mass; // xmm2_4
  float v19; // xmm2_4
  hkpVehiclePerWheelSimulation::WheelData *v20; // rax
  hkpVehiclePerWheelSimulation::WheelData *v21; // rdx
  hkResult result; // [rsp+90h] [rbp+8h] BYREF

  this->m_instance = instance;
  m_data = instance->m_data;
  m_numWheels = m_data->m_numWheels;
  v4 = this->m_wheelData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < (int)m_numWheels )
  {
    v6 = 2 * v4;
    v7 = m_data->m_numWheels;
    if ( (int)m_numWheels < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_wheelData.m_data,
      v7,
      336);
  }
  v8 = this->m_wheelData.m_size - m_numWheels - 1;
  v9 = v8;
  if ( v8 >= 0 )
  {
    p_m_frictionData = &this->m_wheelData.m_data[m_numWheels + v8].m_frictionData;
    do
    {
      --v9;
      p_m_frictionData->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
      p_m_frictionData = (hkpWheelFrictionConstraintData *)((char *)p_m_frictionData - 336);
    }
    while ( v9 >= 0 );
  }
  m_size = this->m_wheelData.m_size;
  v12 = (int)m_numWheels - m_size;
  if ( (int)m_numWheels - m_size > 0 )
  {
    m_frictionImpulse = this->m_wheelData.m_data[this->m_wheelData.m_size].m_frictionData.m_atoms.m_friction.m_frictionImpulse;
    do
    {
      if ( m_frictionImpulse != (float *)244 )
      {
        *((_DWORD *)m_frictionImpulse - 47) = 0x1FFFF;
        *(_QWORD *)(m_frictionImpulse - 45) = 0i64;
        *(_QWORD *)(m_frictionImpulse - 49) = &hkpWheelFrictionConstraintData::`vftable;
        *((_WORD *)m_frictionImpulse - 82) = 2;
        *((_WORD *)m_frictionImpulse - 10) = 28;
        *((_BYTE *)m_frictionImpulse - 18) = 1;
        *(_QWORD *)m_frictionImpulse = 0i64;
        *((_QWORD *)m_frictionImpulse + 1) = 0i64;
        *(_QWORD *)(m_frictionImpulse + 5) = 0i64;
        *(_QWORD *)(m_frictionImpulse + 7) = 0i64;
      }
      m_frictionImpulse += 84;
      --v12;
    }
    while ( v12 );
  }
  this->m_wheelData.m_size = m_numWheels;
  v14 = 0;
  if ( (int)m_numWheels > 0 )
  {
    v15 = 0i64;
    v16 = 0i64;
    do
    {
      v17 = m_data->m_wheelParams.m_data;
      m_mass = v17[v16].m_mass;
      if ( m_mass == 0.0 )
        v19 = 0.0;
      else
        v19 = 2.0 / (float)((float)(v17[v16].m_radius * m_mass) * v17[v16].m_radius);
      v20 = this->m_wheelData.m_data;
      v20[v15].m_axle.m_invInertia = v19;
      v20[v15].m_axle.m_numWheels = 1;
      if ( v19 == 0.0 )
        v20[v15].m_axle.m_inertia = 0.0;
      else
        v20[v15].m_axle.m_inertia = 1.0 / v19;
      *(_QWORD *)&v20[v15].m_axle.m_spinVelocity = 0i64;
      *(_QWORD *)&v20[v15].m_axle.m_wheelsSolved = 0i64;
      v20[v15].m_axle.m_isFixed.m_bool = 0;
      v20[v15].m_axle.m_impulseScaling = 1.0;
      v20[v15].m_axle.m_impulseMax = 3.40282e38;
      v20[v15].m_axle.m_numWheelsOnGround = 0;
      v21 = &this->m_wheelData.m_data[v14];
      hkpWheelFrictionConstraintData::init(&v21->m_frictionData, &v21->m_axle, v17[v16].m_radius);
      ++v14;
      ++v16;
      ++v15;
    }
    while ( v14 < this->m_wheelData.m_size );
  }
}

// File Line: 70
// RVA: 0xE2F440
hkpVehicleSimulation *__fastcall hkpVehiclePerWheelSimulation::clone(
        hkpVehiclePerWheelSimulation *this,
        hkpVehicleInstance *instance)
{
  _QWORD **Value; // rax
  hkpVehiclePerWheelSimulation *v5; // rax
  float *v6; // rax
  float *v7; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkpVehiclePerWheelSimulation *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                         Value[11],
                                         80i64);
  if ( v5 )
  {
    hkpVehiclePerWheelSimulation::hkpVehiclePerWheelSimulation(v5);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v7[10] = this->m_slipDamping;
  v7[11] = this->m_impulseScaling;
  v7[12] = this->m_maxImpulse;
  v7[13] = this->m_takeDynamicVelocity;
  v7[14] = this->m_curbDamping;
  (*(void (__fastcall **)(float *, hkpVehicleInstance *))(*(_QWORD *)v7 + 24i64))(v7, instance);
  return (hkpVehicleSimulation *)v7;
}

// File Line: 85
// RVA: 0xE2F4D0
void __fastcall hkpVehiclePerWheelSimulation::addToWorld(hkpVehiclePerWheelSimulation *this, hkpWorld *world)
{
  this->m_world = world;
  hkpWorld::addWorldPostSimulationListener(world, &this->hkpWorldPostSimulationListener);
}

// File Line: 91
// RVA: 0xE2F4F0
void __fastcall hkpVehiclePerWheelSimulation::removeFromWorld(hkpVehiclePerWheelSimulation *this)
{
  int v1; // ebx
  hkpWorldPostSimulationListener *v3; // rdx
  __int64 v4; // rsi

  v1 = 0;
  v3 = &this->hkpWorldPostSimulationListener;
  if ( !this )
    v3 = 0i64;
  hkpWorld::removeWorldPostSimulationListener(this->m_world, v3);
  this->m_world = 0i64;
  if ( this->m_wheelData.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      if ( this->m_wheelData.m_data[v4].m_frictionConstraint )
        hkpVehiclePerWheelSimulation::removeFrictionConstraint(this, v1);
      ++v1;
      ++v4;
    }
    while ( v1 < this->m_wheelData.m_size );
  }
}

// File Line: 108
// RVA: 0xE2F570
void __fastcall hkpVehiclePerWheelSimulation::simulateVehicle(
        hkpVehiclePerWheelSimulation *this,
        hkpVehicleInstance *instance,
        hkStepInfo *stepInfo,
        hkpVehicleSimulation::SimulationInput *simulInput,
        hkpVehicleJobResults *vehicleJobResults)
{
  hkpVehiclePerWheelSimulation::applySuspensionForces(this, stepInfo, simulInput);
  hkpVehiclePerWheelSimulation::applyAerodynamicForces(this, stepInfo, simulInput);
  hkpVehiclePerWheelSimulation::setupFriction(this, stepInfo, simulInput);
}

// File Line: 124
// RVA: 0xE2F9E0
void __fastcall hkpVehiclePerWheelSimulation::applySuspensionForces(
        hkpVehiclePerWheelSimulation *this,
        hkStepInfo *stepInfo,
        hkpVehicleSimulation::SimulationInput *simulInput)
{
  hkpVehicleInstance *m_instance; // rax
  __int64 v4; // rbx
  hkpEntity *m_entity; // r13
  hkpVehicleData *m_data; // rax
  __int64 m_numWheels; // rsi
  __int64 v11; // rdi
  hkpVehicleInstance::WheelInfo *v12; // rbp
  float v13; // xmm0_4
  __m128 v14; // [rsp+20h] [rbp-48h] BYREF

  m_instance = this->m_instance;
  v4 = 0i64;
  m_entity = m_instance->m_entity;
  m_data = m_instance->m_data;
  m_numWheels = (unsigned __int8)m_data->m_numWheels;
  if ( m_data->m_numWheels )
  {
    v11 = 0i64;
    do
    {
      v12 = this->m_instance->m_wheelsInfo.m_data;
      v13 = simulInput->suspensionForceAtWheel->m_data[v4];
      if ( v13 > 0.0 )
      {
        v14 = _mm_mul_ps(
                _mm_shuffle_ps(
                  (__m128)COERCE_UNSIGNED_INT(v13 * stepInfo->m_deltaTime.m_storage),
                  (__m128)COERCE_UNSIGNED_INT(v13 * stepInfo->m_deltaTime.m_storage),
                  0),
                v12[v11].m_contactPoint.m_separatingNormal.m_quad);
        hkpEntity::activate(m_entity);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, hkVector4f *))m_entity->m_motion.vfptr[11].__first_virtual_table_function__)(
          &m_entity->m_motion,
          &v14,
          &v12[v11].m_hardPointWs);
      }
      ++v4;
      ++v11;
    }
    while ( v4 < m_numWheels );
  }
}

// File Line: 148
// RVA: 0xE2FAD0
void __fastcall hkpVehiclePerWheelSimulation::applyAerodynamicForces(
        hkpVehiclePerWheelSimulation *this,
        hkStepInfo *stepInfo,
        hkpVehicleSimulation::SimulationInput *simulInput)
{
  hkpEntity *m_entity; // rbp
  hkpVehicleAerodynamics::AerodynamicsDragOutput *aerodynamicsDragInfo; // rax
  __m128 v6; // xmm6
  hkpEntity *v8; // rcx
  __m128 v9; // xmm9
  __m128 v10; // xmm8
  __m128 v11; // xmm4
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm5
  __m128 m_quad; // [rsp+20h] [rbp-58h] BYREF
  __m128 v16[3]; // [rsp+30h] [rbp-48h] BYREF

  m_entity = this->m_instance->m_entity;
  aerodynamicsDragInfo = simulInput->aerodynamicsDragInfo;
  v6 = _mm_shuffle_ps(
         (__m128)LODWORD(stepInfo->m_deltaTime.m_storage),
         (__m128)LODWORD(stepInfo->m_deltaTime.m_storage),
         0);
  m_quad = m_entity->m_motion.m_linearVelocity.m_quad;
  m_quad = _mm_add_ps(
             m_quad,
             _mm_mul_ps(
               _mm_mul_ps(
                 _mm_shuffle_ps(
                   (__m128)m_entity->m_motion.m_inertiaAndMassInv.m_quad.m128_u32[3],
                   (__m128)m_entity->m_motion.m_inertiaAndMassInv.m_quad.m128_u32[3],
                   0),
                 v6),
               aerodynamicsDragInfo->m_aerodynamicsForce.m_quad));
  hkpEntity::activate(m_entity);
  m_entity->m_motion.vfptr[9].__vecDelDtor(&m_entity->m_motion, (unsigned int)&m_quad);
  v8 = this->m_instance->m_entity;
  v9 = v8->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad;
  v10 = v8->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad;
  v11 = _mm_mul_ps(simulInput->aerodynamicsDragInfo->m_aerodynamicsTorque.m_quad, v6);
  v12 = _mm_unpacklo_ps(v10, v8->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad);
  v13 = _mm_movelh_ps(v12, v9);
  v14 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(_mm_movehl_ps(v13, v12), v9, 212)),
              _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v13)),
            _mm_mul_ps(
              _mm_shuffle_ps(
                _mm_unpackhi_ps(v10, v8->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                v9,
                228),
              _mm_shuffle_ps(v11, v11, 170))),
          m_entity->m_motion.m_inertiaAndMassInv.m_quad);
  v16[0] = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(
                   _mm_shuffle_ps(v14, v14, 85),
                   v8->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v10)),
               _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v9)),
             m_entity->m_motion.m_angularVelocity.m_quad);
  hkpEntity::activate(m_entity);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))m_entity->m_motion.vfptr[9].__first_virtual_table_function__)(
    &m_entity->m_motion,
    v16);
}

// File Line: 171
// RVA: 0xE30170
void __fastcall hkpVehiclePerWheelSimulation::removeFrictionConstraint(hkpVehiclePerWheelSimulation *this, int w_it)
{
  hkpVehiclePerWheelSimulation::WheelData *v2; // rbx
  hkBool result; // [rsp+38h] [rbp+10h] BYREF

  v2 = &this->m_wheelData.m_data[w_it];
  hkpWorld::removeConstraint(this->m_instance->m_entity->m_world, &result, v2->m_frictionConstraint);
  hkReferencedObject::removeReference(v2->m_frictionConstraint);
  --v2->m_axle.m_numWheelsOnGround;
  v2->m_frictionConstraint = 0i64;
}

// File Line: 188
// RVA: 0xE2FC70
void __fastcall hkpVehiclePerWheelSimulation::setupFriction(
        hkpVehiclePerWheelSimulation *this,
        hkStepInfo *stepInfo,
        hkpVehicleSimulation::SimulationInput *simulInput)
{
  int v3; // r14d
  __int64 v4; // r15
  hkpEntity *m_entity; // r9
  hkpVehicleSimulation::SimulationInput *v6; // r10
  hkStepInfo *v7; // r11
  __int64 v9; // rdx
  __int64 v10; // r12
  __int64 v11; // rbx
  hkpVehicleInstance *m_instance; // rcx
  hkpVehiclePerWheelSimulation::WheelData *m_data; // rdi
  hkpVehicleData::WheelComponentParams *v14; // r8
  hkVector4f *v15; // rsi
  hkpConstraintInstance *m_frictionConstraint; // rax
  hkpEntity *v17; // r13
  float v18; // xmm10_4
  char m_bool; // al
  float m_spinVelocity; // eax
  __m128 m_quad; // xmm3
  __m128 v22; // xmm2
  __m128 v23; // xmm2
  __m128 v24; // xmm5
  float v25; // xmm9_4
  __m128 v26; // xmm5
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __m128 v30; // xmm4
  __m128 v31; // xmm5
  __m128 v32; // xmm5
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  _QWORD **Value; // rax
  hkpConstraintInstance *v37; // rax
  hkVector4f *side; // [rsp+28h] [rbp-B0h]
  hkpEntity *entityA; // [rsp+30h] [rbp-A8h]
  hkpVehicleData::WheelComponentParams *v40; // [rsp+E0h] [rbp+8h]
  __int64 v43; // [rsp+F8h] [rbp+20h]

  v3 = 0;
  v4 = 0i64;
  m_entity = this->m_instance->m_entity;
  v6 = simulInput;
  v7 = stepInfo;
  entityA = m_entity;
  if ( this->m_wheelData.m_size > 0 )
  {
    v9 = 0i64;
    v10 = 0i64;
    v43 = 0i64;
    v11 = 0i64;
    do
    {
      m_instance = this->m_instance;
      m_data = this->m_wheelData.m_data;
      v14 = m_instance->m_data->m_wheelParams.m_data;
      v15 = (hkVector4f *)((char *)&m_instance->m_wheelsInfo.m_data->m_contactPoint.m_position + v9);
      m_frictionConstraint = m_data[v11].m_frictionConstraint;
      v17 = (hkpEntity *)v15[2].m_quad.m128_u64[1];
      v40 = v14;
      v18 = v6->totalLinearForceAtWheel->m_data[v4] * v14[v10].m_radius;
      if ( m_frictionConstraint && m_frictionConstraint->m_entities[1] != v17 )
      {
        hkpVehiclePerWheelSimulation::removeFrictionConstraint(this, v3);
        v9 = v43;
        m_entity = entityA;
        v14 = v40;
        v6 = simulInput;
        v7 = stepInfo;
      }
      m_bool = this->m_instance->m_isFixed.m_data[v4].m_bool;
      m_data[v11].m_axle.m_isFixed.m_bool = m_bool;
      if ( m_bool )
        m_data[v11].m_axle.m_spinVelocity = 0.0;
      else
        LODWORD(m_data[v11].m_axle.m_spinVelocity) = v15[12].m_quad.m128_i32[0];
      if ( v17 )
      {
        m_quad = v15[1].m_quad;
        v22 = (__m128)LODWORD(v6->suspensionForceAtWheel->m_data[v3]);
        v23 = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v15[8].m_quad), m_quad);
        v24 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v15[10].m_quad, v15[10].m_quad, 201), m_quad),
                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v15[10].m_quad));
        v25 = (float)(COERCE_FLOAT((unsigned int)(2
                                                * COERCE_INT(
                                                    (float)(_mm_shuffle_ps(v23, v23, 85).m128_f32[0]
                                                          + _mm_shuffle_ps(v23, v23, 0).m128_f32[0])
                                                  + _mm_shuffle_ps(v23, v23, 170).m128_f32[0])) >> 1)
                    * v14[v10].m_friction)
            * v15[2].m_quad.m128_f32[0];
        v26 = _mm_shuffle_ps(v24, v24, 201);
        v27 = _mm_mul_ps(v26, v26);
        v28 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                _mm_shuffle_ps(v27, v27, 170));
        v29 = _mm_rsqrt_ps(v28);
        v30 = _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v28, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
                    _mm_mul_ps(*(__m128 *)_xmm, v29))),
                v26);
        m_data[v11].m_forwardDirectionWs.m_quad = v30;
        v31 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v15[1].m_quad, v15[1].m_quad, 201), v30),
                _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v15[1].m_quad));
        v32 = _mm_shuffle_ps(v31, v31, 201);
        v33 = _mm_mul_ps(v32, v32);
        v34 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
                _mm_shuffle_ps(v33, v33, 170));
        v35 = _mm_rsqrt_ps(v34);
        side = &m_data[v11].m_sideDirectionWs;
        side->m_quad = _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmple_ps(v34, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v35, v34), v35)),
                             _mm_mul_ps(*(__m128 *)_xmm, v35))),
                         v32);
        m_data[v11].m_contactLocal.m_quad = _mm_sub_ps(
                                              v15->m_quad,
                                              m_entity->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
        hkpWheelFrictionConstraintData::setInWorldSpace(
          &m_data[v11].m_frictionData,
          &m_entity->m_motion.m_motionState.m_transform,
          &v17->m_motion.m_motionState.m_transform,
          v15,
          &m_data[v11].m_forwardDirectionWs,
          side);
        hkpWheelFrictionConstraintData::setMaxFrictionForce(&m_data[v11].m_frictionData, v25);
        hkpWheelFrictionConstraintData::setTorque(&m_data[v11].m_frictionData, v18);
        hkpWheelFrictionConstraintData::setImpulseScaling(
          &m_data[v11].m_frictionData,
          this->m_impulseScaling,
          this->m_maxImpulse);
        if ( !m_data[v11].m_frictionConstraint )
        {
          Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v37 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                           Value[11],
                                           112i64);
          if ( v37 )
            hkpConstraintInstance::hkpConstraintInstance(v37, entityA, v17, &m_data[v11].m_frictionData, PRIORITY_PSI);
          m_data[v11].m_frictionConstraint = v37;
          hkpWorld::addConstraint(entityA->m_world, v37);
          ++m_data[v11].m_axle.m_numWheelsOnGround;
        }
        v9 = v43;
      }
      else
      {
        v15[13].m_quad.m128_u64[0] = 0i64;
        v15[12].m_quad.m128_i32[3] = 0;
        if ( !m_data[v11].m_axle.m_isFixed.m_bool )
          m_data[v11].m_axle.m_spinVelocity = (float)((float)(v18 * v7->m_deltaTime.m_storage)
                                                    * m_data[v11].m_axle.m_invInertia)
                                            + m_data[v11].m_axle.m_spinVelocity;
        m_spinVelocity = m_data[v11].m_axle.m_spinVelocity;
        v15[13].m_quad.m128_i32[1] = 0;
        v15[12].m_quad.m128_f32[1] = m_spinVelocity;
      }
      m_entity = entityA;
      v6 = simulInput;
      v7 = stepInfo;
      v9 += 224i64;
      ++v3;
      ++v4;
      ++v11;
      ++v10;
      v43 = v9;
    }
    while ( v3 < this->m_wheelData.m_size );
  }
}

// File Line: 270
// RVA: 0xE2F5D0
void __fastcall hkpVehiclePerWheelSimulation::postSimulationCallback(
        hkpVehiclePerWheelSimulation *this,
        hkpWorld *world)
{
  float m_storage; // xmm9_4
  int v4; // r12d
  __int64 v5; // r15
  __int64 v6; // rbx
  __int64 v7; // rsi
  __int64 v8; // rax
  __int64 v9; // rbp
  __int64 v10; // rdi
  __int64 v11; // r13
  float v12; // xmm0_4
  float v13; // xmm0_4
  unsigned int v14; // xmm0_4
  __m128 v15; // xmm6
  __m128 v16; // xmm6
  __m128 v17; // xmm2
  __m128 v18; // xmm7
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm7
  __m128 v22; // xmm2
  __m128 v23; // xmm2
  float v24; // xmm1_4
  int v25; // eax
  hkVector4f worldLinearFrictionImpulse; // [rsp+20h] [rbp-C8h] BYREF
  hkVector4f worldAngularVelocityDeltaOut; // [rsp+30h] [rbp-B8h] BYREF
  float SideSlipImpulse; // [rsp+F0h] [rbp+8h]
  __int64 v29; // [rsp+F8h] [rbp+10h]

  m_storage = world->m_dynamicsStepInfo.m_stepInfo.m_deltaTime.m_storage;
  v4 = 0;
  v29 = *(_QWORD *)(*(_QWORD *)&this->m_memSizeAndFlags + 48i64);
  if ( SLODWORD(this->m_curbDamping) > 0 )
  {
    v5 = 0i64;
    v6 = 0i64;
    v7 = 0i64;
    while ( 1 )
    {
      v8 = *(_QWORD *)&this->m_memSizeAndFlags;
      v9 = *(_QWORD *)&this->m_maxImpulse;
      v10 = *(_QWORD *)(v8 + 152);
      v11 = *(_QWORD *)(*(_QWORD *)(v8 + 56) + 144i64);
      v12 = *(float *)(v6 + v10 + 200);
      if ( v12 > 3141.5928 )
        break;
      if ( v12 < -3141.5928 )
      {
        v13 = v12 + 3141.5928;
        goto LABEL_7;
      }
LABEL_8:
      if ( *(_QWORD *)(v7 + v9 + 272) )
      {
        *(float *)&v14 = hkpWheelFrictionConstraintData::getForwardSlipImpulse((hkpWheelFrictionConstraintData *)(v7 + v9 + 48));
        v15 = _mm_mul_ps(_mm_shuffle_ps((__m128)v14, (__m128)v14, 0), *(__m128 *)(v7 + v9 + 288));
        SideSlipImpulse = hkpWheelFrictionConstraintData::getSideSlipImpulse((hkpWheelFrictionConstraintData *)(v7 + v9 + 48));
        v16 = _mm_add_ps(
                v15,
                _mm_mul_ps(
                  _mm_shuffle_ps((__m128)LODWORD(SideSlipImpulse), (__m128)LODWORD(SideSlipImpulse), 0),
                  *(__m128 *)(v7 + v9 + 304)));
        worldLinearFrictionImpulse.m_quad = v16;
        hkpVehiclePerWheelSimulation::computeAngularChassisAcceleration(
          (hkpVehiclePerWheelSimulation *)((char *)this - 16),
          &worldLinearFrictionImpulse,
          (hkVector4f *)(v7 + v9 + 320),
          &worldAngularVelocityDeltaOut);
        v17 = _mm_sub_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(*(__m128 *)(v7 + v9 + 320), *(__m128 *)(v7 + v9 + 320), 201),
                  worldAngularVelocityDeltaOut.m_quad),
                _mm_mul_ps(
                  _mm_shuffle_ps(worldAngularVelocityDeltaOut.m_quad, worldAngularVelocityDeltaOut.m_quad, 201),
                  *(__m128 *)(v7 + v9 + 320)));
        v18 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps((__m128)*(unsigned int *)(v29 + 556), (__m128)*(unsigned int *)(v29 + 556), 0),
                  v16),
                _mm_shuffle_ps(v17, v17, 201));
        if ( !*(_BYTE *)(v7 + v9 + 36) )
        {
          v19 = _mm_mul_ps(v18, *(__m128 *)(v7 + v9 + 288));
          *(float *)(v7 + v9) = *(float *)(v7 + v9)
                              - (float)((float)((float)((float)((float)(_mm_shuffle_ps(v19, v19, 85).m128_f32[0]
                                                                      + _mm_shuffle_ps(v19, v19, 0).m128_f32[0])
                                                              + _mm_shuffle_ps(v19, v19, 170).m128_f32[0])
                                                      / *(float *)(v5 + v11))
                                              * *(float *)&this->m_instance)
                                      * m_storage);
        }
        *(float *)(v6 + v10 + 208) = hkpWheelFrictionConstraintData::getSideFrictionImpulse((hkpWheelFrictionConstraintData *)(v7 + v9 + 48))
                                   / m_storage;
        v20 = _mm_mul_ps(*(__m128 *)(v7 + v9 + 304), v18);
        v21 = _mm_mul_ps(v18, v18);
        *(float *)(v6 + v10 + 216) = (float)(_mm_shuffle_ps(v20, v20, 85).m128_f32[0]
                                           + _mm_shuffle_ps(v20, v20, 0).m128_f32[0])
                                   + _mm_shuffle_ps(v20, v20, 170).m128_f32[0];
        *(float *)(v6 + v10 + 204) = (float)((float)((float)(_mm_shuffle_ps(v21, v21, 85).m128_f32[0]
                                                           + _mm_shuffle_ps(v21, v21, 0).m128_f32[0])
                                                   + _mm_shuffle_ps(v21, v21, 170).m128_f32[0])
                                           * (float)(hkpMotion::getMass((hkpMotion *)(v29 + 336)) * 0.5))
                                   * 0.001;
        hkpWheelFrictionConstraintData::resetSolverData((hkpWheelFrictionConstraintData *)(v7 + v9 + 48));
        v22 = _mm_sub_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(*(__m128 *)(v29 + 576), *(__m128 *)(v29 + 576), 201),
                  *(__m128 *)(v7 + v9 + 320)),
                _mm_mul_ps(
                  _mm_shuffle_ps(*(__m128 *)(v7 + v9 + 320), *(__m128 *)(v7 + v9 + 320), 201),
                  *(__m128 *)(v29 + 576)));
        v23 = _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 201), *(__m128 *)(v29 + 560)), *(__m128 *)(v7 + v9 + 288));
        v24 = (float)((float)(_mm_shuffle_ps(v23, v23, 85).m128_f32[0] + _mm_shuffle_ps(v23, v23, 0).m128_f32[0])
                    + _mm_shuffle_ps(v23, v23, 170).m128_f32[0])
            / *(float *)(v5 + v11);
        *(float *)(v6 + v10 + 196) = v24;
        *(float *)(v6 + v10 + 212) = (float)(*(float *)(v7 + v9) - v24) * *(float *)(v5 + v11);
      }
      else
      {
        v25 = *(_DWORD *)(v6 + v10 + 192);
        *(_QWORD *)(v6 + v10 + 204) = 0i64;
        *(_QWORD *)(v6 + v10 + 212) = 0i64;
        *(_DWORD *)(v6 + v10 + 196) = v25;
      }
      ++v4;
      *(_DWORD *)(v6 + v10 + 192) = *(_DWORD *)(v7 + v9);
      v6 += 224i64;
      v7 += 336i64;
      v5 += 40i64;
      *(float *)(v6 + v10 - 24) = (float)(m_storage * *(float *)(v7 + v9 - 336)) + *(float *)(v6 + v10 - 24);
      if ( v4 >= SLODWORD(this->m_curbDamping) )
        return;
    }
    v13 = v12 - 3141.5928;
LABEL_7:
    *(float *)(v6 + v10 + 200) = v13;
    goto LABEL_8;
  }
}

// File Line: 346
// RVA: 0xE300C0
void __fastcall hkpVehiclePerWheelSimulation::computeAngularChassisAcceleration(
        hkpVehiclePerWheelSimulation *this,
        hkVector4f *worldLinearFrictionImpulse,
        hkVector4f *contactLocal,
        hkVector4f *worldAngularVelocityDeltaOut)
{
  hkpEntity *m_entity; // rcx
  __m128 m_quad; // xmm3
  __m128 v6; // xmm5
  __m128 v7; // xmm1
  __m128 v8; // xmm4
  __m128 v9; // xmm1
  __m128 v10; // xmm5
  __m128 v11; // xmm2
  hkVector4f b; // [rsp+20h] [rbp-18h] BYREF

  m_entity = this->m_instance->m_entity;
  m_quad = m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad;
  v6 = _mm_sub_ps(
         _mm_mul_ps(
           _mm_shuffle_ps(worldLinearFrictionImpulse->m_quad, worldLinearFrictionImpulse->m_quad, 201),
           contactLocal->m_quad),
         _mm_mul_ps(_mm_shuffle_ps(contactLocal->m_quad, contactLocal->m_quad, 201), worldLinearFrictionImpulse->m_quad));
  v7 = m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad;
  v8 = _mm_unpackhi_ps(v7, m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad);
  v9 = _mm_unpacklo_ps(v7, m_entity->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad);
  v10 = _mm_shuffle_ps(v6, v6, 201);
  v11 = _mm_movelh_ps(v9, m_quad);
  b.m_quad = _mm_mul_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(_mm_movehl_ps(v11, v9), m_quad, 212)),
                   _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v11)),
                 _mm_mul_ps(_mm_shuffle_ps(v8, m_quad, 228), _mm_shuffle_ps(v10, v10, 170))),
               m_entity->m_motion.m_inertiaAndMassInv.m_quad);
  hkVector4f::setRotatedDir(worldAngularVelocityDeltaOut, &m_entity->m_motion.m_motionState.m_transform.m_rotation, &b);
}

