// File Line: 47
// RVA: 0xE26590
void __fastcall hkpVehicleInstance::hkpVehicleInstance(hkpVehicleInstance *this, hkpRigidBody *chassis)
{
  hkpUnaryAction::hkpUnaryAction(this, chassis, 0i64);
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleInstance::`vftable;
  this->m_wheelsInfo.m_capacityAndFlags = 0x80000000;
  this->m_wheelsInfo.m_data = 0i64;
  this->m_wheelsInfo.m_size = 0;
  this->m_isFixed.m_data = 0i64;
  this->m_isFixed.m_size = 0;
  this->m_isFixed.m_capacityAndFlags = 0x80000000;
  this->m_wheelsSteeringAngle.m_data = 0i64;
  this->m_wheelsSteeringAngle.m_size = 0;
  this->m_wheelsSteeringAngle.m_capacityAndFlags = 0x80000000;
  this->m_data = 0i64;
  this->m_driverInput = 0i64;
  this->m_steering = 0i64;
  this->m_engine = 0i64;
  this->m_transmission = 0i64;
  this->m_brake = 0i64;
  this->m_suspension = 0i64;
  this->m_aerodynamics = 0i64;
  this->m_wheelCollide = 0i64;
  this->m_tyreMarks = 0i64;
  this->m_velocityDamper = 0i64;
  this->m_deviceStatus = 0i64;
  this->m_vehicleSimulation = 0i64;
}

// File Line: 64
// RVA: 0xE281A0
// attributes: thunk
void __fastcall hkpVehicleInstance::setChassis(hkpVehicleInstance *this, hkpRigidBody *chassis)
{
  hkpUnaryAction::setEntity(this, chassis);
}

// File Line: 69
// RVA: 0xE26500
void __fastcall hkpVehicleInstance::WheelInfo::init(hkpVehicleInstance::WheelInfo *this)
{
  this->m_contactPoint.m_position = (hkVector4f)aabbOut.m_quad;
  this->m_contactPoint.m_separatingNormal = (hkVector4f)direction.m_quad;
  *(unsigned __int64 *)((char *)&this->m_contactPoint.m_separatingNormal.m_quad.m128_u64[1] + 4) = 1065353216i64;
  this->m_contactBody = 0i64;
  this->m_contactShapeKey[0] = -1;
  this->m_currentSuspensionLength = 0.0;
  this->m_hardPointWs = 0i64;
  this->m_rayEndPointWs = 0i64;
  this->m_suspensionDirectionWs = 0i64;
  this->m_spinAxisWs = 0i64;
  this->m_spinAxisChassisSpace = (hkVector4f)_xmm;
  *(_QWORD *)&this->m_spinVelocity = 0i64;
  *(_QWORD *)&this->m_spinAngle = 0i64;
  *(_QWORD *)&this->m_sideForce = 0i64;
  this->m_sideSlipVelocity = 0.0;
  this->m_steeringOrientationChassisSpace = (hkQuaternionf)qi.m_vec.m_quad;
}

// File Line: 99
// RVA: 0xE26650
void __fastcall hkpVehicleInstance::~hkpVehicleInstance(hkpVehicleInstance *this)
{
  hkpVehicleData *m_data; // rcx
  hkpVehicleDriverInput *m_driverInput; // rcx
  hkpVehicleSteering *m_steering; // rcx
  hkpVehicleEngine *m_engine; // rcx
  hkpVehicleTransmission *m_transmission; // rcx
  hkpVehicleBrake *m_brake; // rcx
  hkpVehicleSuspension *m_suspension; // rcx
  hkpVehicleAerodynamics *m_aerodynamics; // rcx
  hkpVehicleWheelCollide *m_wheelCollide; // rcx
  hkpVehicleVelocityDamper *m_velocityDamper; // rcx
  hkpVehicleDriverInputStatus *m_deviceStatus; // rcx
  hkpVehicleSimulation *m_vehicleSimulation; // rcx
  hkpTyremarksInfo *m_tyreMarks; // rcx
  int m_capacityAndFlags; // r8d
  int v16; // r8d
  int v17; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleInstance::`vftable;
  m_data = this->m_data;
  if ( m_data )
    hkReferencedObject::removeReference(m_data);
  m_driverInput = this->m_driverInput;
  if ( m_driverInput )
    hkReferencedObject::removeReference(m_driverInput);
  m_steering = this->m_steering;
  if ( m_steering )
    hkReferencedObject::removeReference(m_steering);
  m_engine = this->m_engine;
  if ( m_engine )
    hkReferencedObject::removeReference(m_engine);
  m_transmission = this->m_transmission;
  if ( m_transmission )
    hkReferencedObject::removeReference(m_transmission);
  m_brake = this->m_brake;
  if ( m_brake )
    hkReferencedObject::removeReference(m_brake);
  m_suspension = this->m_suspension;
  if ( m_suspension )
    hkReferencedObject::removeReference(m_suspension);
  m_aerodynamics = this->m_aerodynamics;
  if ( m_aerodynamics )
    hkReferencedObject::removeReference(m_aerodynamics);
  m_wheelCollide = this->m_wheelCollide;
  if ( m_wheelCollide )
    hkReferencedObject::removeReference(m_wheelCollide);
  m_velocityDamper = this->m_velocityDamper;
  if ( m_velocityDamper )
    hkReferencedObject::removeReference(m_velocityDamper);
  m_deviceStatus = this->m_deviceStatus;
  if ( m_deviceStatus )
    hkReferencedObject::removeReference(m_deviceStatus);
  m_vehicleSimulation = this->m_vehicleSimulation;
  if ( m_vehicleSimulation )
    hkReferencedObject::removeReference(m_vehicleSimulation);
  m_tyreMarks = this->m_tyreMarks;
  if ( m_tyreMarks )
    hkReferencedObject::removeReference(m_tyreMarks);
  m_capacityAndFlags = this->m_wheelsSteeringAngle.m_capacityAndFlags;
  this->m_wheelsSteeringAngle.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_wheelsSteeringAngle.m_data,
      4 * m_capacityAndFlags);
  this->m_wheelsSteeringAngle.m_data = 0i64;
  this->m_wheelsSteeringAngle.m_capacityAndFlags = 0x80000000;
  v16 = this->m_isFixed.m_capacityAndFlags;
  this->m_isFixed.m_size = 0;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_isFixed.m_data,
      v16 & 0x3FFFFFFF);
  this->m_isFixed.m_data = 0i64;
  this->m_isFixed.m_capacityAndFlags = 0x80000000;
  v17 = this->m_wheelsInfo.m_capacityAndFlags;
  this->m_wheelsInfo.m_size = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_wheelsInfo.m_data,
      224 * (v17 & 0x3FFFFFFF));
  this->m_wheelsInfo.m_data = 0i64;
  this->m_wheelsInfo.m_capacityAndFlags = 0x80000000;
  hkpUnaryAction::~hkpUnaryAction(this);
}

// File Line: 119
// RVA: 0xE26820
void __fastcall hkpVehicleInstance::init(hkpVehicleInstance *this)
{
  hkpVehicleData *m_data; // rcx
  const __m128i *v3; // rax
  __m128 v4; // xmm8
  __m128i si128; // xmm9
  __m128 v6; // xmm7
  __m128 v7; // xmm6
  unsigned int v8; // xmm0_4
  hkpRigidBody *m_entity; // rcx
  __m128 v10; // xmm1
  int m_numWheels; // edi
  int v12; // eax
  int v13; // eax
  int v14; // r9d
  hkpVehicleSimulation *v15; // rdi
  int i; // esi
  int v17; // ebp
  int v18; // eax
  int v19; // eax
  int v20; // r9d
  int v21; // ecx
  __int64 j; // rdx
  hkpVehicleData *v23; // rax
  int v24; // ebp
  int v25; // eax
  int v26; // eax
  int v27; // r9d
  int v28; // edx
  __int64 v29; // rcx
  hkpVehicleWheelCollide *m_wheelCollide; // rcx
  _QWORD **Value; // rax
  hkpVehicleDefaultSimulation *v32; // rax
  hkpVehicleSimulation *v33; // rax
  hkMatrix3f inertia; // [rsp+30h] [rbp-78h] BYREF
  hkResult result; // [rsp+B0h] [rbp+8h] BYREF

  m_data = this->m_data;
  if ( !m_data->m_alreadyInitialised.m_bool )
    ((void (__fastcall *)(hkpVehicleData *, hkArray<hkpVehicleSuspension::SuspensionWheelParameters,hkContainerHeapAllocator> *, hkpEntity *))m_data->vfptr[1].__first_virtual_table_function__)(
      m_data,
      &this->m_suspension->m_wheelParams,
      this->m_entity);
  v3 = (const __m128i *)this->m_data;
  v4 = (__m128)v3[7].m128i_u32[1];
  si128 = _mm_load_si128(v3 + 3);
  v6 = _mm_mul_ps(
         (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128(v3 + 4), 1u), 1u),
         _mm_shuffle_ps((__m128)v3[7].m128i_u32[2], (__m128)v3[7].m128i_u32[2], 0));
  v7 = _mm_mul_ps(
         (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128(v3 + 5), 1u), 1u),
         _mm_shuffle_ps((__m128)v3[7].m128i_u32[3], (__m128)v3[7].m128i_u32[3], 0));
  *(float *)&v8 = hkpMotion::getMass(&this->m_entity->m_motion);
  m_entity = (hkpRigidBody *)this->m_entity;
  result.m_enum = v8;
  v10 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(si128, 1u), 1u), _mm_shuffle_ps(v4, v4, 0)), v6),
            v7),
          _mm_shuffle_ps((__m128)v8, (__m128)v8, 0));
  inertia.m_col2.m_quad = _mm_mul_ps(v10, stru_141A71280.m_quad);
  inertia.m_col0.m_quad = _mm_mul_ps(v10, transform.m_quad);
  inertia.m_col1.m_quad = _mm_mul_ps(v10, direction.m_quad);
  hkpRigidBody::setInertiaLocal(m_entity, &inertia);
  m_numWheels = this->m_data->m_numWheels;
  v12 = this->m_wheelsInfo.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v12 < m_numWheels )
  {
    v13 = 2 * v12;
    v14 = this->m_data->m_numWheels;
    if ( m_numWheels < v13 )
      v14 = v13;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_wheelsInfo.m_data,
      v14,
      224);
  }
  this->m_wheelsInfo.m_size = m_numWheels;
  v15 = 0i64;
  for ( i = 0; i < this->m_wheelsInfo.m_size; ++i )
    hkpVehicleInstance::WheelInfo::init(&this->m_wheelsInfo.m_data[i]);
  v17 = this->m_data->m_numWheels;
  v18 = this->m_isFixed.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v18 < v17 )
  {
    v19 = 2 * v18;
    v20 = this->m_data->m_numWheels;
    if ( v17 < v19 )
      v20 = v19;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_isFixed.m_data, v20, 1);
  }
  v21 = 0;
  this->m_isFixed.m_size = v17;
  for ( j = 0i64; v21 < this->m_isFixed.m_size; this->m_isFixed.m_data[j++].m_bool = 0 )
    ++v21;
  v23 = this->m_data;
  this->m_wheelsTimeSinceMaxPedalInput = 0.0;
  *(_QWORD *)&this->m_mainSteeringAngle = 0i64;
  v24 = v23->m_numWheels;
  v25 = this->m_wheelsSteeringAngle.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v25 < v24 )
  {
    v26 = 2 * v25;
    v27 = v24;
    if ( v24 < v26 )
      v27 = v26;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_wheelsSteeringAngle.m_data,
      v27,
      4);
  }
  v28 = 0;
  this->m_wheelsSteeringAngle.m_size = v24;
  if ( v24 > 0 )
  {
    v29 = 0i64;
    do
    {
      ++v28;
      this->m_wheelsSteeringAngle.m_data[v29++] = 0.0;
    }
    while ( v28 < this->m_wheelsSteeringAngle.m_size );
  }
  *(_QWORD *)&this->m_torque = 0i64;
  *(_WORD *)&this->m_isReversing.m_bool = 0;
  this->m_delayed.m_bool = 0;
  m_wheelCollide = this->m_wheelCollide;
  this->m_clutchDelayCountdown = 0.0;
  ((void (__fastcall *)(hkpVehicleWheelCollide *, hkpVehicleInstance *))m_wheelCollide->vfptr[1].__first_virtual_table_function__)(
    m_wheelCollide,
    this);
  this->m_wheelCollide->m_alreadyUsed.m_bool = 1;
  if ( !this->m_vehicleSimulation )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v32 = (hkpVehicleDefaultSimulation *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                           Value[11],
                                           96i64);
    if ( v32 )
    {
      hkpVehicleDefaultSimulation::hkpVehicleDefaultSimulation(v32);
      v15 = v33;
    }
    this->m_vehicleSimulation = v15;
  }
  ((void (__fastcall *)(hkpVehicleSimulation *, hkpVehicleInstance *))this->m_vehicleSimulation->vfptr[1].__first_virtual_table_function__)(
    this->m_vehicleSimulation,
    this);
}

// File Line: 193
// RVA: 0xE26B60
void __fastcall hkpVehicleInstance::getPhantoms(
        hkpVehicleInstance *this,
        hkArray<hkpPhantom *,hkContainerHeapAllocator> *phantomsOut)
{
  ((void (__fastcall *)(hkpVehicleWheelCollide *, hkArray<hkpPhantom *,hkContainerHeapAllocator> *))this->m_wheelCollide->vfptr[2].__first_virtual_table_function__)(
    this->m_wheelCollide,
    phantomsOut);
}

// File Line: 200
// RVA: 0xE27610
void __fastcall hkpVehicleInstance::handleFixedGroundAccum(
        hkpVehicleInstance *this,
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

// File Line: 206
// RVA: 0xE26CC0
void __fastcall hkpVehicleInstance::updateBeforeCollisionDetection(hkpVehicleInstance *this)
{
  _QWORD *Value; // r8
  _QWORD *v3; // rcx
  unsigned __int64 v4; // rax
  _QWORD *v5; // rcx
  hkpEntity *m_entity; // r12
  int v7; // r15d
  __int64 v8; // r13
  hkpVehicleInstance::WheelInfo *m_data; // rbp
  __int64 v10; // rbx
  unsigned int v11; // xmm0_4
  _QWORD *v12; // rax
  _QWORD *v13; // rcx
  _QWORD *v14; // r8
  unsigned __int64 v15; // rax
  _QWORD *v16; // rcx
  __int64 v17; // [rsp+60h] [rbp+8h]
  __int64 v18; // [rsp+68h] [rbp+10h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v3 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v3 < Value[3] )
  {
    *v3 = "TtUpdateBeforeCD";
    v4 = __rdtsc();
    v5 = v3 + 2;
    *((_DWORD *)v5 - 2) = v4;
    Value[1] = v5;
  }
  m_entity = this->m_entity;
  v7 = 0;
  if ( this->m_data->m_numWheels > 0 )
  {
    v18 = 0i64;
    v8 = 0i64;
    v17 = 0i64;
    do
    {
      m_data = this->m_wheelsInfo.m_data;
      v10 = v7;
      hkVector4f::setRotatedDir(
        &m_data[v8].m_suspensionDirectionWs,
        &m_entity->m_motion.m_motionState.m_transform.m_rotation,
        &this->m_suspension->m_wheelParams.m_data[v10].m_directionChassisSpace);
      hkVector4f::setTransformedPos(
        &m_data[v8].m_hardPointWs,
        &m_entity->m_motion.m_motionState.m_transform,
        &this->m_suspension->m_wheelParams.m_data[v10].m_hardpointChassisSpace);
      ++v7;
      ++v8;
      *(float *)&v11 = this->m_data->m_wheelParams.m_data[v18++].m_radius
                     + this->m_suspension->m_wheelParams.m_data[v17++].m_length;
      m_data[v8 - 1].m_rayEndPointWs.m_quad = _mm_add_ps(
                                                _mm_mul_ps(
                                                  _mm_shuffle_ps((__m128)v11, (__m128)v11, 0),
                                                  m_data[v8 - 1].m_suspensionDirectionWs.m_quad),
                                                m_data[v8 - 1].m_hardPointWs.m_quad);
    }
    while ( v7 < this->m_data->m_numWheels );
  }
  ((void (__fastcall *)(hkpVehicleWheelCollide *, hkpVehicleInstance *, _QWORD *))this->m_wheelCollide->vfptr[3].__vecDelDtor)(
    this->m_wheelCollide,
    this,
    Value);
  v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)v12[1];
  v14 = v12;
  if ( (unsigned __int64)v13 < v12[3] )
  {
    *v13 = "Et";
    v15 = __rdtsc();
    v16 = v13 + 2;
    *((_DWORD *)v16 - 2) = v15;
    v14[1] = v16;
  }
}

// File Line: 238
// RVA: 0xE27A30
void __fastcall hkpVehicleInstance::updateWheels(
        hkpVehicleInstance *this,
        float deltaTime,
        hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo)
{
  hkpEntity *m_entity; // rbp
  int v4; // esi
  __int64 v6; // rdx
  __int64 v7; // r9
  __int64 v8; // r14
  __int64 v9; // r15
  hkVector4f *p_m_separatingNormal; // r13
  int *v11; // r12
  hkpVehicleInstance::WheelInfo *m_data; // rbx
  hkpVehicleInstance::WheelInfo *v13; // rax
  hkVector4f *p_m_spinAxisChassisSpace; // r8
  __m128 v15; // xmm1
  hkQuaternionf *p_m_steeringOrientationChassisSpace; // rdx
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm3
  __int64 v21; // [rsp+20h] [rbp-A8h]
  __m128 v22; // [rsp+30h] [rbp-98h]
  hkVector4f b; // [rsp+40h] [rbp-88h] BYREF
  unsigned int v24; // [rsp+D0h] [rbp+8h]
  __int64 v25; // [rsp+E8h] [rbp+20h]

  m_entity = this->m_entity;
  v4 = 0;
  if ( this->m_data->m_numWheels > 0 )
  {
    v6 = 0i64;
    v7 = 0i64;
    v25 = 0i64;
    v21 = 0i64;
    v8 = 0i64;
    v9 = 13i64;
    p_m_separatingNormal = &cdInfo->m_contactPoint.m_separatingNormal;
    v11 = (int *)&cdInfo->m_contactShapeKey[1];
    do
    {
      m_data = this->m_wheelsInfo.m_data;
      LODWORD(m_data[v8].m_currentSuspensionLength) = p_m_separatingNormal[4].m_quad.m128_i32[0];
      v13 = this->m_wheelsInfo.m_data;
      p_m_spinAxisChassisSpace = &m_data[v8].m_spinAxisChassisSpace;
      v13[v8].m_contactPoint.m_position = (hkVector4f)p_m_separatingNormal[-1].m_quad;
      v13[v8].m_contactPoint.m_separatingNormal = (hkVector4f)p_m_separatingNormal->m_quad;
      LODWORD(this->m_wheelsInfo.m_data[v8].m_contactFriction) = p_m_separatingNormal[1].m_quad.m128_i32[0];
      this->m_wheelsInfo.m_data[v8].m_contactBody = (hkpRigidBody *)p_m_separatingNormal[1].m_quad.m128_u64[1];
      this->m_wheelsInfo.m_data->m_contactPoint.m_position.m_quad.m128_i32[v9 - 1] = *(v11 - 1);
      this->m_wheelsInfo.m_data->m_contactPoint.m_position.m_quad.m128_i32[v9] = *v11;
      this->m_wheelsInfo.m_data->m_contactPoint.m_position.m_quad.m128_i32[v9 + 1] = v11[1];
      this->m_wheelsInfo.m_data->m_contactPoint.m_position.m_quad.m128_i32[v9 + 2] = v11[2];
      this->m_wheelsInfo.m_data->m_contactPoint.m_position.m_quad.m128_i32[v9 + 3] = v11[3];
      this->m_wheelsInfo.m_data->m_contactPoint.m_separatingNormal.m_quad.m128_i32[v9] = v11[4];
      this->m_wheelsInfo.m_data->m_contactPoint.m_separatingNormal.m_quad.m128_i32[v9 + 1] = v11[5];
      this->m_wheelsInfo.m_data->m_contactPoint.m_separatingNormal.m_quad.m128_i32[v9 + 2] = v11[6];
      *(float *)&v24 = *(float *)((char *)this->m_wheelsSteeringAngle.m_data + v7) * 0.5;
      v15 = _mm_mul_ps(
              _mm_shuffle_ps((__m128)v24, (__m128)v24, 0),
              *(__m128 *)((char *)&this->m_suspension->m_wheelParams.m_data->m_directionChassisSpace.m_quad + v6));
      p_m_steeringOrientationChassisSpace = &m_data[v8].m_steeringOrientationChassisSpace;
      v22 = v15;
      v22.m128_i32[3] = 1065353216;
      v17 = _mm_mul_ps(v22, v22);
      v18 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 78), v17);
      v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 177), v18);
      v20 = _mm_rsqrt_ps(v19);
      p_m_steeringOrientationChassisSpace->m_vec.m_quad = _mm_mul_ps(
                                                            v22,
                                                            _mm_andnot_ps(
                                                              _mm_cmple_ps(v19, (__m128)0i64),
                                                              _mm_mul_ps(
                                                                _mm_sub_ps(
                                                                  (__m128)_xmm,
                                                                  _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                                                                _mm_mul_ps(*(__m128 *)_xmm, v20))));
      *p_m_spinAxisChassisSpace = this->m_data->m_chassisOrientation.m_col2;
      hkVector4f::setRotatedDir(&b, p_m_steeringOrientationChassisSpace, p_m_spinAxisChassisSpace);
      hkVector4f::setRotatedDir(&m_data[v8].m_spinAxisWs, &m_entity->m_motion.m_motionState.m_transform.m_rotation, &b);
      v7 = v25 + 4;
      v6 = v21 + 48;
      ++v4;
      p_m_separatingNormal += 6;
      ++v8;
      v11 += 24;
      v9 += 56i64;
      v25 += 4i64;
      v21 += 48i64;
    }
    while ( v4 < this->m_data->m_numWheels );
  }
}

// File Line: 291
// RVA: 0xE27D00
void __fastcall hkpVehicleInstance::updateDriverInput(
        hkpVehicleInstance *this,
        float deltaTime,
        hkpVehicleDriverInput::FilteredDriverInputOutput *filteredDriverInputInfo)
{
  __int64 v3; // rdx

  filteredDriverInputInfo->m_tryingToReverse.m_bool = this->m_tryingToReverse.m_bool;
  ((void (__fastcall *)(hkpVehicleDriverInput *, __int64, hkpVehicleInstance *, hkpVehicleDriverInputStatus *, hkpVehicleDriverInput::FilteredDriverInputOutput *))this->m_driverInput->vfptr[1].__first_virtual_table_function__)(
    this->m_driverInput,
    v3,
    this,
    this->m_deviceStatus,
    filteredDriverInputInfo);
  this->m_tryingToReverse.m_bool = filteredDriverInputInfo->m_tryingToReverse.m_bool;
}

// File Line: 299
// RVA: 0xE27D50
void __fastcall hkpVehicleInstance::updateSteering(
        hkpVehicleInstance *this,
        float deltaTime,
        hkpVehicleDriverInput::FilteredDriverInputOutput *filteredDriverInputInfo)
{
  int m_size; // edi
  float m_mainSteeringAngle; // xmm0_4
  float m_mainSteeringAngleAssumingNoReduction; // xmm2_4
  int v8; // r9d
  int v9; // r8d
  __int64 v10; // rdx
  int v11; // r9d
  float v12; // xmm1_4
  __int64 v13; // r8
  float v14; // ecx
  float v15; // [rsp+30h] [rbp-B8h] BYREF
  float v16; // [rsp+34h] [rbp-B4h]
  char *array; // [rsp+38h] [rbp-B0h] BYREF
  int v18; // [rsp+40h] [rbp-A8h]
  int v19; // [rsp+44h] [rbp-A4h]
  char v20; // [rsp+48h] [rbp-A0h] BYREF
  hkResult v21; // [rsp+F0h] [rbp+8h] BYREF

  m_size = this->m_wheelsSteeringAngle.m_size;
  m_mainSteeringAngle = this->m_mainSteeringAngle;
  m_mainSteeringAngleAssumingNoReduction = this->m_mainSteeringAngleAssumingNoReduction;
  v18 = 0;
  v15 = m_mainSteeringAngle;
  v16 = m_mainSteeringAngleAssumingNoReduction;
  v19 = -2147483616;
  array = &v20;
  if ( m_size > 32 )
  {
    v8 = m_size;
    if ( m_size < 64 )
      v8 = 64;
    hkArrayUtil::_reserve(&v21, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v8, 4);
  }
  v9 = 0;
  v18 = m_size;
  if ( this->m_wheelsSteeringAngle.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      ++v9;
      ++v10;
      *(float *)&array[v10 * 4 - 4] = this->m_wheelsSteeringAngle.m_data[v10 - 1];
    }
    while ( v9 < this->m_wheelsSteeringAngle.m_size );
  }
  ((void (__fastcall *)(hkpVehicleSteering *, float *, hkpVehicleInstance *, hkpVehicleDriverInput::FilteredDriverInputOutput *, float *))this->m_steering->vfptr[1].__first_virtual_table_function__)(
    this->m_steering,
    &v15,
    this,
    filteredDriverInputInfo,
    &v15);
  v11 = 0;
  v12 = v16;
  this->m_mainSteeringAngle = v15;
  this->m_mainSteeringAngleAssumingNoReduction = v12;
  if ( this->m_wheelsSteeringAngle.m_size > 0 )
  {
    v13 = 0i64;
    do
    {
      ++v11;
      v14 = *(float *)&array[v13 * 4];
      this->m_wheelsSteeringAngle.m_data[v13++] = v14;
    }
    while ( v11 < this->m_wheelsSteeringAngle.m_size );
  }
  v18 = 0;
  if ( v19 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v19);
}

// File Line: 324
// RVA: 0xE27EE0
void __fastcall hkpVehicleInstance::updateTransmission(
        hkpVehicleInstance *this,
        float deltaTime,
        hkpVehicleTransmission::TransmissionOutput *transmissionInfo)
{
  __int64 m_numWheels; // rdx

  m_numWheels = (unsigned __int8)this->m_data->m_numWheels;
  transmissionInfo->m_numWheelsTramsmittedTorque = m_numWheels;
  transmissionInfo->m_isReversing.m_bool = this->m_isReversing.m_bool;
  transmissionInfo->m_currentGear = this->m_currentGear;
  transmissionInfo->m_delayed.m_bool = this->m_delayed.m_bool;
  transmissionInfo->m_clutchDelayCountdown = this->m_clutchDelayCountdown;
  ((void (__fastcall *)(hkpVehicleTransmission *, __int64, hkpVehicleInstance *, hkpVehicleTransmission::TransmissionOutput *))this->m_transmission->vfptr[1].__first_virtual_table_function__)(
    this->m_transmission,
    m_numWheels,
    this,
    transmissionInfo);
  this->m_isReversing.m_bool = transmissionInfo->m_isReversing.m_bool;
  this->m_currentGear = transmissionInfo->m_currentGear;
  this->m_delayed.m_bool = transmissionInfo->m_delayed.m_bool;
  this->m_clutchDelayCountdown = transmissionInfo->m_clutchDelayCountdown;
}

// File Line: 339
// RVA: 0xE27F70
void __fastcall hkpVehicleInstance::updateEngine(
        hkpVehicleInstance *this,
        float deltaTime,
        hkpVehicleDriverInput::FilteredDriverInputOutput *filteredDriverInputInfo,
        hkpVehicleTransmission::TransmissionOutput *transmissionInfo)
{
  float m_rpm; // xmm0_4
  float m_torque; // xmm2_4
  hkpVehicleEngine *m_engine; // rcx
  float v8; // xmm1_4
  float v9; // [rsp+40h] [rbp+8h] BYREF
  float v10; // [rsp+44h] [rbp+Ch]

  m_rpm = this->m_rpm;
  m_torque = this->m_torque;
  m_engine = this->m_engine;
  v10 = m_rpm;
  v9 = m_torque;
  ((void (__fastcall *)(hkpVehicleEngine *, float *, hkpVehicleInstance *, hkpVehicleDriverInput::FilteredDriverInputOutput *, hkpVehicleTransmission::TransmissionOutput *, float *))m_engine->vfptr[1].__first_virtual_table_function__)(
    m_engine,
    &v9,
    this,
    filteredDriverInputInfo,
    transmissionInfo,
    &v9);
  v8 = v9;
  this->m_rpm = v10;
  this->m_torque = v8;
}

// File Line: 350
// RVA: 0xE27FE0
void __fastcall hkpVehicleInstance::updateBrake(
        hkpVehicleInstance *this,
        float deltaTime,
        hkpVehicleDriverInput::FilteredDriverInputOutput *filteredDriverInputInfo,
        hkpVehicleBrake::WheelBreakingOutput *wheelBreakingInfo)
{
  int m_size; // edi
  int v5; // eax
  int v9; // eax
  int v10; // r9d
  int v11; // edi
  int v12; // eax
  int v13; // eax
  int v14; // r9d
  int v15; // edi
  __int64 v16; // rdx
  int i; // r8d
  char m_bool; // al
  __int64 v19; // rdx
  char v20; // al
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  m_size = this->m_isFixed.m_size;
  v5 = wheelBreakingInfo->m_isFixed.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < m_size )
  {
    v9 = 2 * v5;
    v10 = this->m_isFixed.m_size;
    if ( m_size < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&wheelBreakingInfo->m_isFixed.m_data,
      v10,
      1);
  }
  wheelBreakingInfo->m_isFixed.m_size = m_size;
  v11 = this->m_isFixed.m_size;
  v12 = wheelBreakingInfo->m_brakingTorque.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v12 < v11 )
  {
    v13 = 2 * v12;
    v14 = this->m_isFixed.m_size;
    if ( v11 < v13 )
      v14 = v13;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&wheelBreakingInfo->m_brakingTorque.m_data,
      v14,
      4);
  }
  wheelBreakingInfo->m_brakingTorque.m_size = v11;
  v15 = 0;
  v16 = 0i64;
  for ( i = 0; i < this->m_isFixed.m_size; wheelBreakingInfo->m_isFixed.m_data[v16 - 1].m_bool = m_bool )
  {
    ++i;
    m_bool = this->m_isFixed.m_data[v16++].m_bool;
  }
  wheelBreakingInfo->m_wheelsTimeSinceMaxPedalInput = this->m_wheelsTimeSinceMaxPedalInput;
  ((void (__fastcall *)(hkpVehicleBrake *, __int64, hkpVehicleInstance *, hkpVehicleDriverInput::FilteredDriverInputOutput *, hkpVehicleBrake::WheelBreakingOutput *))this->m_brake->vfptr[1].__first_virtual_table_function__)(
    this->m_brake,
    v16,
    this,
    filteredDriverInputInfo,
    wheelBreakingInfo);
  v19 = 0i64;
  if ( wheelBreakingInfo->m_isFixed.m_size > 0 )
  {
    do
    {
      ++v15;
      v20 = wheelBreakingInfo->m_isFixed.m_data[v19].m_bool;
      this->m_isFixed.m_data[v19++].m_bool = v20;
    }
    while ( v15 < wheelBreakingInfo->m_isFixed.m_size );
  }
  this->m_wheelsTimeSinceMaxPedalInput = wheelBreakingInfo->m_wheelsTimeSinceMaxPedalInput;
}

// File Line: 375
// RVA: 0xE28150
void __fastcall hkpVehicleInstance::updateSuspension(
        hkpVehicleInstance *this,
        float deltaTime,
        hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo,
        hkArray<float,hkContainerHeapAllocator> *suspensionForces)
{
  ((void (__fastcall *)(hkpVehicleSuspension *, hkpVehicleSuspension *, hkpVehicleInstance *, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *, float *))this->m_suspension->vfptr[1].__first_virtual_table_function__)(
    this->m_suspension,
    this->m_suspension,
    this,
    cdInfo,
    suspensionForces->m_data);
}

// File Line: 381
// RVA: 0xE28180
void __fastcall hkpVehicleInstance::updateAerodynamics(
        hkpVehicleInstance *this,
        float deltaTime,
        hkpVehicleAerodynamics::AerodynamicsDragOutput *aerodynamicsDragInfo)
{
  ((void (__fastcall *)(hkpVehicleAerodynamics *, hkBaseObjectVtbl *, hkpVehicleInstance *, hkpVehicleAerodynamics::AerodynamicsDragOutput *))this->m_aerodynamics->vfptr[1].__first_virtual_table_function__)(
    this->m_aerodynamics,
    this->m_aerodynamics->vfptr,
    this,
    aerodynamicsDragInfo);
}

// File Line: 386
// RVA: 0xE27660
void __fastcall hkpVehicleInstance::updateComponents(
        hkpVehicleInstance *this,
        hkStepInfo *stepInfo,
        hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo,
        hkpVehicleAerodynamics::AerodynamicsDragOutput *aerodynamicsDragInfo)
{
  _QWORD *Value; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  hkpVehicleData *m_data; // rax
  int m_numWheels; // ebx
  hkLifoAllocator *v14; // rax
  float *m_cur; // r8
  int v16; // edx
  char *v17; // rcx
  float m_storage; // xmm6_4
  hkpVehicleData *v19; // r9
  int v20; // r8d
  hkpVehicleData::WheelComponentParams *v21; // rdx
  __int64 v22; // rcx
  __int64 v23; // r10
  float *m_wheelsTransmittedTorque; // rdi
  signed int v25; // ebx
  hkLifoAllocator *v26; // rax
  int v27; // r8d
  _QWORD *v28; // r8
  _QWORD *v29; // rcx
  unsigned __int64 v30; // rax
  _QWORD *v31; // rcx
  hkpVehicleDriverInput::FilteredDriverInputOutput filteredDriverInputInfo; // [rsp+20h] [rbp-C8h] BYREF
  hkpVehicleTransmission::TransmissionOutput transmissionInfo; // [rsp+30h] [rbp-B8h] BYREF
  hkpVehicleBrake::WheelBreakingOutput wheelBreakingInfo; // [rsp+50h] [rbp-98h] BYREF
  hkArray<float,hkContainerHeapAllocator> *suspensionForces; // [rsp+158h] [rbp+70h]
  __int64 *v36; // [rsp+160h] [rbp+78h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtUpdateComponents";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  wheelBreakingInfo.m_brakingTorque.m_data = wheelBreakingInfo.m_brakingTorque.m_storage;
  wheelBreakingInfo.m_brakingTorque.m_size = 0;
  *(_QWORD *)&wheelBreakingInfo.m_brakingTorque.m_storage[26] = &wheelBreakingInfo.m_brakingTorque.m_storage[30];
  m_data = this->m_data;
  wheelBreakingInfo.m_brakingTorque.m_capacityAndFlags = -2147483616;
  wheelBreakingInfo.m_brakingTorque.m_storage[28] = 0.0;
  LODWORD(wheelBreakingInfo.m_brakingTorque.m_storage[29]) = -2147483616;
  m_numWheels = m_data->m_numWheels;
  v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (float *)v14->m_cur;
  v16 = (4 * m_numWheels + 127) & 0xFFFFFF80;
  v17 = (char *)m_cur + v16;
  if ( v16 > v14->m_slabSize || v17 > v14->m_end )
    m_cur = (float *)hkLifoAllocator::allocateFromNewSlab(v14, v16);
  else
    v14->m_cur = v17;
  m_storage = stepInfo->m_deltaTime.m_storage;
  transmissionInfo.m_wheelsTransmittedTorque = m_cur;
  hkpVehicleInstance::updateWheels(this, m_storage, cdInfo);
  hkpVehicleInstance::updateDriverInput(this, m_storage, &filteredDriverInputInfo);
  hkpVehicleInstance::updateSteering(this, m_storage, &filteredDriverInputInfo);
  hkpVehicleInstance::updateTransmission(this, m_storage, &transmissionInfo);
  hkpVehicleInstance::updateEngine(this, m_storage, &filteredDriverInputInfo, &transmissionInfo);
  hkpVehicleInstance::updateBrake(this, m_storage, &filteredDriverInputInfo, &wheelBreakingInfo);
  hkpVehicleInstance::updateSuspension(this, m_storage, cdInfo, suspensionForces);
  hkpVehicleInstance::updateAerodynamics(this, m_storage, aerodynamicsDragInfo);
  v19 = this->m_data;
  v20 = 0;
  if ( v19->m_numWheels > 0 )
  {
    v21 = v19->m_wheelParams.m_data;
    v22 = 0i64;
    v23 = *v36;
    do
    {
      ++v20;
      ++v21;
      ++v22;
      *(float *)(v22 * 4 + v23 - 4) = (float)(transmissionInfo.m_wheelsTransmittedTorque[v22 - 1]
                                            + wheelBreakingInfo.m_brakingTorque.m_data[v22 - 1])
                                    / v21[-1].m_radius;
    }
    while ( v20 < v19->m_numWheels );
  }
  m_wheelsTransmittedTorque = transmissionInfo.m_wheelsTransmittedTorque;
  v25 = (4 * v19->m_numWheels + 127) & 0xFFFFFF80;
  v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (v25 + 15) & 0xFFFFFFF0;
  if ( v25 > v26->m_slabSize
    || (char *)m_wheelsTransmittedTorque + v27 != v26->m_cur
    || v26->m_firstNonLifoEnd == m_wheelsTransmittedTorque )
  {
    hkLifoAllocator::slowBlockFree(v26, (char *)m_wheelsTransmittedTorque, v27);
  }
  else
  {
    v26->m_cur = m_wheelsTransmittedTorque;
  }
  v28 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v29 = (_QWORD *)v28[1];
  if ( (unsigned __int64)v29 < v28[3] )
  {
    *v29 = "Et";
    v30 = __rdtsc();
    v31 = v29 + 2;
    *((_DWORD *)v31 - 2) = v30;
    v28[1] = v31;
  }
  wheelBreakingInfo.m_brakingTorque.m_storage[28] = 0.0;
  if ( wheelBreakingInfo.m_brakingTorque.m_storage[29] >= 0.0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)&wheelBreakingInfo.m_brakingTorque.m_storage[26],
      LODWORD(wheelBreakingInfo.m_brakingTorque.m_storage[29]) & 0x3FFFFFFF);
  *(_QWORD *)&wheelBreakingInfo.m_brakingTorque.m_storage[26] = 0i64;
  wheelBreakingInfo.m_brakingTorque.m_storage[29] = -0.0;
  wheelBreakingInfo.m_brakingTorque.m_size = 0;
  if ( wheelBreakingInfo.m_brakingTorque.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      wheelBreakingInfo.m_brakingTorque.m_data,
      4 * wheelBreakingInfo.m_brakingTorque.m_capacityAndFlags);
}

// File Line: 422
// RVA: 0xE27940
void __fastcall hkpVehicleInstance::simulateVehicle(
        hkpVehicleInstance *this,
        hkStepInfo *stepInfo,
        hkpVehicleAerodynamics::AerodynamicsDragOutput *aerodynamicsDragInfo,
        hkArray<float,hkContainerHeapAllocator> *suspensionForceAtWheel,
        hkArray<float,hkContainerHeapAllocator> *totalLinearForceAtWheel,
        hkpVehicleJobResults *vehicleJobResults)
{
  _QWORD *Value; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r10
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  hkpVehicleSimulation *m_vehicleSimulation; // rcx
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx
  __int64 v20[5]; // [rsp+30h] [rbp-28h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)Value[1];
  v12 = Value;
  if ( (unsigned __int64)v11 < Value[3] )
  {
    *v11 = "TtSimulateVehicle";
    v13 = __rdtsc();
    v14 = v11 + 2;
    *((_DWORD *)v14 - 2) = v13;
    v12[1] = v14;
  }
  m_vehicleSimulation = this->m_vehicleSimulation;
  v20[0] = (__int64)aerodynamicsDragInfo;
  v20[2] = (__int64)totalLinearForceAtWheel;
  v20[1] = (__int64)suspensionForceAtWheel;
  ((void (__fastcall *)(hkpVehicleSimulation *, hkpVehicleInstance *, hkStepInfo *, __int64 *, hkpVehicleJobResults *))m_vehicleSimulation->vfptr[3].__first_virtual_table_function__)(
    m_vehicleSimulation,
    this,
    stepInfo,
    v20,
    vehicleJobResults);
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "Et";
    v18 = __rdtsc();
    v19 = v17 + 2;
    *((_DWORD *)v19 - 2) = v18;
    v16[1] = v19;
  }
}

// File Line: 434
// RVA: 0xE26EA0
void __fastcall hkpVehicleInstance::stepVehicleUsingWheelCollideOutput(
        hkpVehicleInstance *this,
        hkStepInfo *stepInfo,
        hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkpVehicleData *m_data; // rcx
  int m_numWheels; // eax
  _QWORD *v13; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  _QWORD *v16; // rcx
  hkArray<float,hkContainerHeapAllocator> totalLinearForceAtWheel; // [rsp+30h] [rbp-C8h] BYREF
  char v18; // [rsp+40h] [rbp-B8h] BYREF
  hkArray<float,hkContainerHeapAllocator> suspensionForceAtWheel; // [rsp+80h] [rbp-78h] BYREF
  char v20; // [rsp+90h] [rbp-68h] BYREF
  hkpVehicleAerodynamics::AerodynamicsDragOutput aerodynamicsDragInfo; // [rsp+D0h] [rbp-28h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtDoVehicle";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  m_data = this->m_data;
  m_numWheels = m_data->m_numWheels;
  suspensionForceAtWheel.m_data = (float *)&v20;
  suspensionForceAtWheel.m_capacityAndFlags = -2147483632;
  suspensionForceAtWheel.m_size = m_numWheels;
  totalLinearForceAtWheel.m_size = m_data->m_numWheels;
  totalLinearForceAtWheel.m_data = (float *)&v18;
  totalLinearForceAtWheel.m_capacityAndFlags = -2147483632;
  hkpVehicleInstance::updateComponents(
    this,
    stepInfo,
    cdInfo,
    &aerodynamicsDragInfo,
    &suspensionForceAtWheel,
    &totalLinearForceAtWheel);
  hkpVehicleInstance::simulateVehicle(
    this,
    stepInfo,
    &aerodynamicsDragInfo,
    &suspensionForceAtWheel,
    &totalLinearForceAtWheel,
    0i64);
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = (_QWORD *)v13[1];
  if ( (unsigned __int64)v14 < v13[3] )
  {
    *v14 = "Et";
    v15 = __rdtsc();
    v16 = v14 + 2;
    *((_DWORD *)v16 - 2) = v15;
    v13[1] = v16;
  }
  totalLinearForceAtWheel.m_size = 0;
  if ( totalLinearForceAtWheel.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      totalLinearForceAtWheel.m_data,
      4 * totalLinearForceAtWheel.m_capacityAndFlags);
  totalLinearForceAtWheel.m_data = 0i64;
  totalLinearForceAtWheel.m_capacityAndFlags = 0x80000000;
  suspensionForceAtWheel.m_size = 0;
  if ( suspensionForceAtWheel.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      suspensionForceAtWheel.m_data,
      4 * suspensionForceAtWheel.m_capacityAndFlags);
}

// File Line: 452
// RVA: 0xE26B80
// attributes: thunk
void __fastcall hkpVehicleInstance::applyAction(hkpVehicleInstance *this, hkStepInfo *stepInfo)
{
  hkpVehicleInstance::stepVehicle(this, stepInfo);
}

// File Line: 457
// RVA: 0xE26B90
void __fastcall hkpVehicleInstance::stepVehicle(hkpVehicleInstance *this, hkStepInfo *stepInfo)
{
  __int64 v4; // rdx
  hkpVehicleData *m_data; // rax
  int m_numWheels; // ebx
  hkLifoAllocator *Value; // rax
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *m_cur; // rdi
  char *v9; // rcx
  signed int v10; // ebx
  hkLifoAllocator *v11; // rax
  int v12; // r8d

  hkpVehicleInstance::updateBeforeCollisionDetection(this);
  m_data = this->m_data;
  m_numWheels = m_data->m_numWheels;
  if ( m_data->m_numWheels )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)Value->m_cur;
    v4 = (96 * m_numWheels + 127) & 0xFFFFFF80;
    v9 = (char *)m_cur + (int)v4;
    if ( (int)v4 > Value->m_slabSize || v9 > Value->m_end )
      m_cur = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)hkLifoAllocator::allocateFromNewSlab(Value, v4);
    else
      Value->m_cur = v9;
  }
  else
  {
    m_cur = 0i64;
  }
  ((void (__fastcall *)(hkpVehicleWheelCollide *, __int64, hkpVehicleInstance *, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *))this->m_wheelCollide->vfptr[2].__vecDelDtor)(
    this->m_wheelCollide,
    v4,
    this,
    m_cur);
  hkpVehicleInstance::stepVehicleUsingWheelCollideOutput(this, stepInfo, m_cur);
  v10 = (96 * m_numWheels + 127) & 0xFFFFFF80;
  v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (v10 + 15) & 0xFFFFFFF0;
  if ( v10 > v11->m_slabSize || (char *)m_cur + v12 != v11->m_cur || v11->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v11, (char *)m_cur, v12);
  else
    v11->m_cur = m_cur;
}

// File Line: 471
// RVA: 0xE27240
void __fastcall hkpVehicleInstance::calcCurrentPositionAndRotation(
        hkpVehicleInstance *this,
        hkpRigidBody *chassis,
        hkpVehicleSuspension *suspension,
        int wheelNo,
        hkVector4f *posOut,
        hkQuaternionf *rotOut)
{
  hkpVehicleData *m_data; // rax
  __int64 v7; // rbx
  hkpVehicleInstance::WheelInfo *v10; // rbp
  float m_spinAngle; // xmm6_4
  __m128 m_quad; // xmm2
  hkQuaternionf v13; // xmm5
  __m128 v14; // xmm3
  __m128 v15; // xmm0
  __m128 v16; // xmm6
  __m128 v17; // xmm5
  __m128 v18; // xmm6
  __m128 v19; // xmm4
  __m128 v20; // xmm6
  __m128 v21; // xmm6
  __m128 v22; // xmm4
  __m128 v23; // xmm3
  __m128 v24; // xmm7
  __m128 v25; // xmm2
  __m128 v26; // xmm7
  __m128 v27; // xmm7
  __m128 v28; // xmm4
  __m128 v29; // xmm3
  __m128 v30; // xmm5
  __m128 v31; // xmm2
  __m128 v32; // xmm5
  hkVector4f v33; // xmm1
  __m128 v34; // xmm2
  hkQuaternionf quat; // [rsp+20h] [rbp-88h] BYREF
  hkVector4f axis; // [rsp+30h] [rbp-78h] BYREF
  hkQuaternionf v37; // [rsp+40h] [rbp-68h] BYREF
  hkRotationf r; // [rsp+50h] [rbp-58h] BYREF
  float v39; // [rsp+C8h] [rbp+20h]

  m_data = this->m_data;
  v7 = wheelNo;
  r.m_col0 = m_data->m_chassisOrientation.m_col1;
  r.m_col1 = m_data->m_chassisOrientation.m_col0;
  v10 = &this->m_wheelsInfo.m_data[wheelNo];
  r.m_col2 = m_data->m_chassisOrientation.m_col2;
  hkQuaternionf::set(&quat, &r);
  m_spinAngle = v10->m_spinAngle;
  hkVector4f::setRotatedInverseDir(&axis, &quat, &v10->m_spinAxisChassisSpace);
  hkQuaternionf::setAxisAngle(&v37, &axis, COERCE_FLOAT(LODWORD(m_spinAngle) ^ _xmm[0]));
  m_quad = v10->m_steeringOrientationChassisSpace.m_vec.m_quad;
  v13.m_vec.m_quad = (__m128)chassis->m_motion.m_motionState.m_sweptTransform.m_rotation1;
  v14 = _mm_shuffle_ps(v13.m_vec.m_quad, v13.m_vec.m_quad, 255);
  v15 = _mm_mul_ps(_mm_shuffle_ps(v13.m_vec.m_quad, v13.m_vec.m_quad, 201), m_quad);
  v16 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v13.m_vec.m_quad);
  v17 = _mm_mul_ps(v13.m_vec.m_quad, m_quad);
  v18 = _mm_sub_ps(v16, v15);
  v19 = _mm_shuffle_ps(m_quad, m_quad, 255);
  v20 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v18, v18, 201), _mm_mul_ps(m_quad, v14)),
          _mm_mul_ps(chassis->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad, v19));
  v21 = _mm_shuffle_ps(
          v20,
          _mm_unpackhi_ps(
            v20,
            _mm_sub_ps(
              _mm_mul_ps(v19, v14),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                _mm_shuffle_ps(v17, v17, 170)))),
          196);
  v22 = _mm_shuffle_ps(quat.m_vec.m_quad, quat.m_vec.m_quad, 255);
  v23 = _mm_shuffle_ps(v21, v21, 255);
  v24 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(quat.m_vec.m_quad, quat.m_vec.m_quad, 201), v21),
          _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), quat.m_vec.m_quad));
  v25 = _mm_mul_ps(quat.m_vec.m_quad, v21);
  v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v24, v24, 201), _mm_mul_ps(quat.m_vec.m_quad, v23)), _mm_mul_ps(v21, v22));
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
  v28 = _mm_shuffle_ps(v37.m_vec.m_quad, v37.m_vec.m_quad, 255);
  v29 = _mm_shuffle_ps(v27, v27, 255);
  v30 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v37.m_vec.m_quad, v37.m_vec.m_quad, 201), v27),
          _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v37.m_vec.m_quad));
  v31 = _mm_mul_ps(v37.m_vec.m_quad, v27);
  v32 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v30, v30, 201), _mm_mul_ps(v37.m_vec.m_quad, v29)), _mm_mul_ps(v27, v28));
  rotOut->m_vec.m_quad = _mm_shuffle_ps(
                           v32,
                           _mm_unpackhi_ps(
                             v32,
                             _mm_sub_ps(
                               _mm_mul_ps(v28, v29),
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                                 _mm_shuffle_ps(v31, v31, 170)))),
                           196);
  v39 = fmaxf(0.0, v10->m_currentSuspensionLength);
  v33.m_quad = (__m128)suspension->m_wheelParams.m_data[v7].m_hardpointChassisSpace;
  v34 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(v33.m_quad, v33.m_quad, 85),
                chassis->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
              _mm_mul_ps(
                _mm_shuffle_ps(v33.m_quad, v33.m_quad, 0),
                chassis->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
            _mm_mul_ps(
              _mm_shuffle_ps(v33.m_quad, v33.m_quad, 170),
              chassis->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)),
          chassis->m_motion.m_motionState.m_transform.m_translation.m_quad);
  *posOut = (hkVector4f)v34;
  posOut->m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_shuffle_ps((__m128)LODWORD(v39), (__m128)LODWORD(v39), 0),
                       v10->m_suspensionDirectionWs.m_quad),
                     v34);
}

// File Line: 505
// RVA: 0xE27500
float __fastcall hkpVehicleInstance::calcRPM(hkpVehicleInstance *this)
{
  return this->m_rpm;
}

// File Line: 512
// RVA: 0xE27510
float __fastcall hkpVehicleInstance::calcKMPH(hkpVehicleInstance *this)
{
  __m128 v1; // xmm1
  __m128 v2; // xmm5
  __m128 v3; // xmm2

  v1 = _mm_mul_ps(this->m_entity->m_motion.m_linearVelocity.m_quad, this->m_entity->m_motion.m_linearVelocity.m_quad);
  v2 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v1, v1, 85), _mm_shuffle_ps(v1, v1, 0)), _mm_shuffle_ps(v1, v1, 170));
  v3 = _mm_rsqrt_ps(v2);
  return (float)(_mm_andnot_ps(
                   _mm_cmple_ps(v2, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v3, v2), v3)),
                       _mm_mul_ps(*(__m128 *)_xmm, v3)),
                     v2)).m128_f32[0]
               * 0.001)
       * 3600.0;
}

// File Line: 520
// RVA: 0xE27590
float __fastcall hkpVehicleInstance::calcMPH(hkpVehicleInstance *this)
{
  __m128 v1; // xmm1
  __m128 v2; // xmm5
  __m128 v3; // xmm2

  v1 = _mm_mul_ps(this->m_entity->m_motion.m_linearVelocity.m_quad, this->m_entity->m_motion.m_linearVelocity.m_quad);
  v2 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v1, v1, 85), _mm_shuffle_ps(v1, v1, 0)), _mm_shuffle_ps(v1, v1, 170));
  v3 = _mm_rsqrt_ps(v2);
  return (float)(_mm_andnot_ps(
                   _mm_cmple_ps(v2, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v3, v2), v3)),
                       _mm_mul_ps(*(__m128 *)_xmm, v3)),
                     v2)).m128_f32[0]
               * 0.00062138814)
       * 3600.0;
}

// File Line: 529
// RVA: 0xE27060
hkpVehicleInstance *__fastcall hkpVehicleInstance::clone(
        hkpVehicleInstance *this,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *newEntities,
        hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  hkpRigidBody *v4; // rdi
  _QWORD **Value; // rax
  hkpVehicleInstance *v7; // rax
  hkpVehicleInstance *v8; // rax
  hkpVehicleInstance *v9; // rbx
  __int64 v10; // rax
  __int64 v11; // rax
  hkReferencedObject *m_data; // rcx

  v4 = (hkpRigidBody *)*newEntities->m_data;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkpVehicleInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 240i64);
  if ( v7 )
  {
    hkpVehicleInstance::hkpVehicleInstance(v7, v4);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  hkpVehicleInstance::operator=(v9, this);
  v9->m_world = 0i64;
  v9->m_island = 0i64;
  v9->m_entity = v4;
  v10 = ((__int64 (__fastcall *)(hkpVehicleWheelCollide *, hkpRigidBody *, hkArray<hkpPhantom *,hkContainerHeapAllocator> *))this->m_wheelCollide->vfptr[3].__first_virtual_table_function__)(
          this->m_wheelCollide,
          v4,
          newPhantoms);
  v9->m_wheelCollide = (hkpVehicleWheelCollide *)v10;
  *(_BYTE *)(v10 + 16) = 1;
  v9->m_vehicleSimulation = (hkpVehicleSimulation *)this->m_vehicleSimulation->vfptr[2].__vecDelDtor(
                                                      this->m_vehicleSimulation,
                                                      v9);
  v11 = ((__int64 (__fastcall *)(hkpVehicleDriverInputStatus *))this->m_deviceStatus->vfptr[1].__first_virtual_table_function__)(this->m_deviceStatus);
  m_data = v9->m_data;
  v9->m_deviceStatus = (hkpVehicleDriverInputStatus *)v11;
  hkReferencedObject::addReference(m_data);
  hkReferencedObject::addReference(v9->m_driverInput);
  hkReferencedObject::addReference(v9->m_steering);
  hkReferencedObject::addReference(v9->m_engine);
  hkReferencedObject::addReference(v9->m_transmission);
  hkReferencedObject::addReference(v9->m_brake);
  hkReferencedObject::addReference(v9->m_suspension);
  hkReferencedObject::addReference(v9->m_aerodynamics);
  hkReferencedObject::addReference(v9->m_velocityDamper);
  if ( this->m_tyreMarks )
    hkReferencedObject::addReference(v9->m_tyreMarks);
  return v9;
}

// File Line: 572
// RVA: 0xE271A0
void __fastcall hkpVehicleInstance::addToWorld(hkpVehicleInstance *this, hkpWorld *world)
{
  hkpWorld::addEntity(world, this->m_entity, HK_ENTITY_ACTIVATION_DO_ACTIVATE);
  this->m_wheelCollide->vfptr[4].__vecDelDtor(this->m_wheelCollide, (unsigned int)world);
  ((void (__fastcall *)(hkpVehicleSimulation *, hkpWorld *))this->m_vehicleSimulation->vfptr[2].__first_virtual_table_function__)(
    this->m_vehicleSimulation,
    world);
}

// File Line: 581
// RVA: 0xE271F0
void __fastcall hkpVehicleInstance::removeFromWorld(hkpVehicleInstance *this)
{
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  ((void (__fastcall *)(hkpVehicleSimulation *))this->m_vehicleSimulation->vfptr[3].__vecDelDtor)(this->m_vehicleSimulation);
  this->m_wheelCollide->vfptr[4].__first_virtual_table_function__(this->m_wheelCollide);
  hkpWorld::removeEntity(this->m_entity->m_world, &result, this->m_entity);
}

