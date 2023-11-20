// File Line: 47
// RVA: 0xE26590
void __fastcall hkpVehicleInstance::hkpVehicleInstance(hkpVehicleInstance *this, hkpRigidBody *chassis)
{
  hkpVehicleInstance *v2; // rbx

  v2 = this;
  hkpUnaryAction::hkpUnaryAction((hkpUnaryAction *)&this->vfptr, (hkpEntity *)&chassis->vfptr, 0i64);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpVehicleInstance::`vftable;
  v2->m_wheelsInfo.m_capacityAndFlags = 2147483648;
  v2->m_wheelsInfo.m_data = 0i64;
  v2->m_wheelsInfo.m_size = 0;
  v2->m_isFixed.m_data = 0i64;
  v2->m_isFixed.m_size = 0;
  v2->m_isFixed.m_capacityAndFlags = 2147483648;
  v2->m_wheelsSteeringAngle.m_data = 0i64;
  v2->m_wheelsSteeringAngle.m_size = 0;
  v2->m_wheelsSteeringAngle.m_capacityAndFlags = 2147483648;
  v2->m_data = 0i64;
  v2->m_driverInput = 0i64;
  v2->m_steering = 0i64;
  v2->m_engine = 0i64;
  v2->m_transmission = 0i64;
  v2->m_brake = 0i64;
  v2->m_suspension = 0i64;
  v2->m_aerodynamics = 0i64;
  v2->m_wheelCollide = 0i64;
  v2->m_tyreMarks = 0i64;
  v2->m_velocityDamper = 0i64;
  v2->m_deviceStatus = 0i64;
  v2->m_vehicleSimulation = 0i64;
}

// File Line: 64
// RVA: 0xE281A0
void __fastcall hkpVehicleInstance::setChassis(hkpVehicleInstance *this, hkpRigidBody *chassis)
{
  hkpUnaryAction::setEntity((hkpUnaryAction *)&this->vfptr, (hkpEntity *)&chassis->vfptr);
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
  hkpVehicleInstance *v1; // rbx
  hkpVehicleData *v2; // rcx
  hkReferencedObject *v3; // rcx
  hkReferencedObject *v4; // rcx
  hkReferencedObject *v5; // rcx
  hkReferencedObject *v6; // rcx
  hkReferencedObject *v7; // rcx
  hkReferencedObject *v8; // rcx
  hkReferencedObject *v9; // rcx
  hkReferencedObject *v10; // rcx
  hkReferencedObject *v11; // rcx
  hkReferencedObject *v12; // rcx
  hkReferencedObject *v13; // rcx
  hkReferencedObject *v14; // rcx
  int v15; // er8
  int v16; // er8
  int v17; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleInstance::`vftable;
  v2 = this->m_data;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v3 = (hkReferencedObject *)&v1->m_driverInput->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v4 = (hkReferencedObject *)&v1->m_steering->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v5 = (hkReferencedObject *)&v1->m_engine->vfptr;
  if ( v5 )
    hkReferencedObject::removeReference(v5);
  v6 = (hkReferencedObject *)&v1->m_transmission->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v7 = (hkReferencedObject *)&v1->m_brake->vfptr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  v8 = (hkReferencedObject *)&v1->m_suspension->vfptr;
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  v9 = (hkReferencedObject *)&v1->m_aerodynamics->vfptr;
  if ( v9 )
    hkReferencedObject::removeReference(v9);
  v10 = (hkReferencedObject *)&v1->m_wheelCollide->vfptr;
  if ( v10 )
    hkReferencedObject::removeReference(v10);
  v11 = (hkReferencedObject *)&v1->m_velocityDamper->vfptr;
  if ( v11 )
    hkReferencedObject::removeReference(v11);
  v12 = (hkReferencedObject *)&v1->m_deviceStatus->vfptr;
  if ( v12 )
    hkReferencedObject::removeReference(v12);
  v13 = (hkReferencedObject *)&v1->m_vehicleSimulation->vfptr;
  if ( v13 )
    hkReferencedObject::removeReference(v13);
  v14 = (hkReferencedObject *)&v1->m_tyreMarks->vfptr;
  if ( v14 )
    hkReferencedObject::removeReference(v14);
  v15 = v1->m_wheelsSteeringAngle.m_capacityAndFlags;
  v1->m_wheelsSteeringAngle.m_size = 0;
  if ( v15 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_wheelsSteeringAngle.m_data,
      4 * v15);
  v1->m_wheelsSteeringAngle.m_data = 0i64;
  v1->m_wheelsSteeringAngle.m_capacityAndFlags = 2147483648;
  v16 = v1->m_isFixed.m_capacityAndFlags;
  v1->m_isFixed.m_size = 0;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_isFixed.m_data,
      v16 & 0x3FFFFFFF);
  v1->m_isFixed.m_data = 0i64;
  v1->m_isFixed.m_capacityAndFlags = 2147483648;
  v17 = v1->m_wheelsInfo.m_capacityAndFlags;
  v1->m_wheelsInfo.m_size = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_wheelsInfo.m_data,
      224 * (v17 & 0x3FFFFFFF));
  v1->m_wheelsInfo.m_data = 0i64;
  v1->m_wheelsInfo.m_capacityAndFlags = 2147483648;
  hkpUnaryAction::~hkpUnaryAction((hkpUnaryAction *)&v1->vfptr);
}

// File Line: 119
// RVA: 0xE26820
void __fastcall hkpVehicleInstance::init(hkpVehicleInstance *this)
{
  hkpVehicleInstance *v1; // rbx
  hkpVehicleData *v2; // rcx
  const __m128i *v3; // rax
  __m128 v4; // xmm8
  __m128i v5; // xmm9
  __m128 v6; // xmm7
  __m128 v7; // xmm6
  unsigned int v8; // xmm0_4
  hkpRigidBody *v9; // rcx
  __m128 v10; // xmm1
  int v11; // edi
  int v12; // eax
  int v13; // eax
  int v14; // er9
  hkpVehicleSimulation *v15; // rdi
  int i; // esi
  int v17; // ebp
  int v18; // eax
  int v19; // eax
  int v20; // er9
  int v21; // ecx
  __int64 j; // rdx
  hkpVehicleData *v23; // rax
  int v24; // ebp
  int v25; // eax
  int v26; // eax
  int v27; // er9
  int v28; // edx
  __int64 v29; // rcx
  hkpVehicleWheelCollide *v30; // rcx
  _QWORD **v31; // rax
  hkpVehicleDefaultSimulation *v32; // rax
  hkpVehicleSimulation *v33; // rax
  hkMatrix3f inertia; // [rsp+30h] [rbp-78h]
  hkResult result; // [rsp+B0h] [rbp+8h]

  v1 = this;
  v2 = this->m_data;
  if ( !v2->m_alreadyInitialised.m_bool )
    ((void (__fastcall *)(hkpVehicleData *, hkArray<hkpVehicleSuspension::SuspensionWheelParameters,hkContainerHeapAllocator> *, hkpEntity *))v2->vfptr[1].__first_virtual_table_function__)(
      v2,
      &v1->m_suspension->m_wheelParams,
      v1->m_entity);
  v3 = (const __m128i *)v1->m_data;
  v4 = (__m128)v3[7].m128i_u32[1];
  v5 = _mm_load_si128(v3 + 3);
  v6 = _mm_mul_ps(
         (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128(v3 + 4), 1u), 1u),
         _mm_shuffle_ps((__m128)v3[7].m128i_u32[2], (__m128)v3[7].m128i_u32[2], 0));
  v7 = _mm_mul_ps(
         (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128(v3 + 5), 1u), 1u),
         _mm_shuffle_ps((__m128)v3[7].m128i_u32[3], (__m128)v3[7].m128i_u32[3], 0));
  *(float *)&v8 = hkpMotion::getMass((hkpMotion *)&v1->m_entity->m_motion.vfptr);
  v9 = (hkpRigidBody *)v1->m_entity;
  result.m_enum = v8;
  v10 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v5, 1u), 1u), _mm_shuffle_ps(v4, v4, 0)), v6),
            v7),
          _mm_shuffle_ps((__m128)v8, (__m128)v8, 0));
  inertia.m_col2.m_quad = _mm_mul_ps(v10, stru_141A71280.m_quad);
  inertia.m_col0.m_quad = _mm_mul_ps(v10, transform.m_quad);
  inertia.m_col1.m_quad = _mm_mul_ps(v10, direction.m_quad);
  hkpRigidBody::setInertiaLocal(v9, &inertia);
  v11 = v1->m_data->m_numWheels;
  v12 = v1->m_wheelsInfo.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v12 < v11 )
  {
    v13 = 2 * v12;
    v14 = v1->m_data->m_numWheels;
    if ( v11 < v13 )
      v14 = v13;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_wheelsInfo,
      v14,
      224);
  }
  v1->m_wheelsInfo.m_size = v11;
  v15 = 0i64;
  for ( i = 0; i < v1->m_wheelsInfo.m_size; ++i )
    hkpVehicleInstance::WheelInfo::init(&v1->m_wheelsInfo.m_data[i]);
  v17 = v1->m_data->m_numWheels;
  v18 = v1->m_isFixed.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v18 < v17 )
  {
    v19 = 2 * v18;
    v20 = v1->m_data->m_numWheels;
    if ( v17 < v19 )
      v20 = v19;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_isFixed,
      v20,
      1);
  }
  v21 = 0;
  v1->m_isFixed.m_size = v17;
  for ( j = 0i64; v21 < v1->m_isFixed.m_size; v1->m_isFixed.m_data[j - 1].m_bool = 0 )
  {
    ++v21;
    ++j;
  }
  v23 = v1->m_data;
  v1->m_wheelsTimeSinceMaxPedalInput = 0.0;
  *(_QWORD *)&v1->m_mainSteeringAngle = 0i64;
  v24 = v23->m_numWheels;
  v25 = v1->m_wheelsSteeringAngle.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v25 < v24 )
  {
    v26 = 2 * v25;
    v27 = v24;
    if ( v24 < v26 )
      v27 = v26;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_wheelsSteeringAngle,
      v27,
      4);
  }
  v28 = 0;
  v1->m_wheelsSteeringAngle.m_size = v24;
  if ( v24 > 0 )
  {
    v29 = 0i64;
    do
    {
      ++v28;
      ++v29;
      v1->m_wheelsSteeringAngle.m_data[v29 - 1] = 0.0;
    }
    while ( v28 < v1->m_wheelsSteeringAngle.m_size );
  }
  *(_QWORD *)&v1->m_torque = 0i64;
  *(_WORD *)&v1->m_isReversing.m_bool = 0;
  v1->m_delayed.m_bool = 0;
  v30 = v1->m_wheelCollide;
  v1->m_clutchDelayCountdown = 0.0;
  ((void (__fastcall *)(hkpVehicleWheelCollide *, hkpVehicleInstance *))v30->vfptr[1].__first_virtual_table_function__)(
    v30,
    v1);
  v1->m_wheelCollide->m_alreadyUsed.m_bool = 1;
  if ( !v1->m_vehicleSimulation )
  {
    v31 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v32 = (hkpVehicleDefaultSimulation *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v31[11] + 8i64))(
                                           v31[11],
                                           96i64);
    if ( v32 )
    {
      hkpVehicleDefaultSimulation::hkpVehicleDefaultSimulation(v32);
      v15 = v33;
    }
    v1->m_vehicleSimulation = v15;
  }
  ((void (__fastcall *)(hkpVehicleSimulation *, hkpVehicleInstance *))v1->m_vehicleSimulation->vfptr[1].__first_virtual_table_function__)(
    v1->m_vehicleSimulation,
    v1);
}

// File Line: 193
// RVA: 0xE26B60
void __fastcall hkpVehicleInstance::getPhantoms(hkpVehicleInstance *this, hkArray<hkpPhantom *,hkContainerHeapAllocator> *phantomsOut)
{
  ((void (__fastcall *)(hkpVehicleWheelCollide *, hkArray<hkpPhantom *,hkContainerHeapAllocator> *))this->m_wheelCollide->vfptr[2].__first_virtual_table_function__)(
    this->m_wheelCollide,
    phantomsOut);
}

// File Line: 200
// RVA: 0xE27610
void __fastcall hkpVehicleInstance::handleFixedGroundAccum(hkpVehicleInstance *this, hkpRigidBody *ground, hkpVelocityAccumulator *accum)
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
  hkpVehicleInstance *v1; // r14
  _QWORD *v2; // r8
  _QWORD *v3; // rcx
  unsigned __int64 v4; // rax
  signed __int64 v5; // rcx
  hkpEntity *v6; // r12
  signed int v7; // er15
  __int64 v8; // r13
  hkpVehicleInstance::WheelInfo *v9; // rbp
  signed __int64 v10; // rbx
  unsigned int v11; // xmm0_4
  _QWORD *v12; // rax
  _QWORD *v13; // rcx
  _QWORD *v14; // r8
  unsigned __int64 v15; // rax
  signed __int64 v16; // rcx
  __int64 v17; // [rsp+60h] [rbp+8h]
  __int64 v18; // [rsp+68h] [rbp+10h]

  v1 = this;
  v2 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v3 = (_QWORD *)v2[1];
  if ( (unsigned __int64)v3 < v2[3] )
  {
    *v3 = "TtUpdateBeforeCD";
    v4 = __rdtsc();
    v5 = (signed __int64)(v3 + 2);
    *(_DWORD *)(v5 - 8) = v4;
    v2[1] = v5;
  }
  v6 = v1->m_entity;
  v7 = 0;
  if ( v1->m_data->m_numWheels > 0 )
  {
    v18 = 0i64;
    v8 = 0i64;
    v17 = 0i64;
    do
    {
      v9 = v1->m_wheelsInfo.m_data;
      v10 = v7;
      hkVector4f::setRotatedDir(
        &v9[v8].m_suspensionDirectionWs,
        (hkMatrix3f *)&v6->m_motion.m_motionState.m_transform.m_rotation.m_col0,
        &v1->m_suspension->m_wheelParams.m_data[v10].m_directionChassisSpace);
      hkVector4f::setTransformedPos(
        &v9[v8].m_hardPointWs,
        &v6->m_motion.m_motionState.m_transform,
        &v1->m_suspension->m_wheelParams.m_data[v10].m_hardpointChassisSpace);
      ++v7;
      ++v8;
      ++v18;
      *(float *)&v11 = v1->m_data->m_wheelParams.m_data[v18 - 1].m_radius
                     + v1->m_suspension->m_wheelParams.m_data[v17].m_length;
      ++v17;
      *((__m128 *)&v9[v8] - 8) = _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps((__m128)v11, (__m128)v11, 0), *((__m128 *)&v9[v8] - 6)),
                                   *((__m128 *)&v9[v8] - 9));
    }
    while ( v7 < v1->m_data->m_numWheels );
  }
  ((void (__fastcall *)(hkpVehicleWheelCollide *, hkpVehicleInstance *, _QWORD *))v1->m_wheelCollide->vfptr[3].__vecDelDtor)(
    v1->m_wheelCollide,
    v1,
    v2);
  v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)v12[1];
  v14 = v12;
  if ( (unsigned __int64)v13 < v12[3] )
  {
    *v13 = "Et";
    v15 = __rdtsc();
    v16 = (signed __int64)(v13 + 2);
    *(_DWORD *)(v16 - 8) = v15;
    v14[1] = v16;
  }
}

// File Line: 238
// RVA: 0xE27A30
void __fastcall hkpVehicleInstance::updateWheels(hkpVehicleInstance *this, float deltaTime, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo)
{
  hkpEntity *v3; // rbp
  signed int v4; // esi
  hkpVehicleInstance *v5; // rdi
  signed __int64 v6; // rdx
  signed __int64 v7; // r9
  __int64 v8; // r14
  signed __int64 v9; // r15
  hkVector4f *v10; // r13
  int *v11; // r12
  hkpVehicleInstance::WheelInfo *v12; // rbx
  hkpVehicleInstance::WheelInfo *v13; // rax
  hkVector4f *v14; // r8
  __m128 v15; // xmm1
  hkQuaternionf *v16; // rdx
  __m128 v17; // ST30_16
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  __int64 v22; // [rsp+20h] [rbp-A8h]
  hkVector4f b; // [rsp+40h] [rbp-88h]
  unsigned int v24; // [rsp+D0h] [rbp+8h]
  __int64 v25; // [rsp+E8h] [rbp+20h]

  v3 = this->m_entity;
  v4 = 0;
  v5 = this;
  if ( this->m_data->m_numWheels > 0 )
  {
    v6 = 0i64;
    v7 = 0i64;
    v25 = 0i64;
    v22 = 0i64;
    v8 = 0i64;
    v9 = 13i64;
    v10 = &cdInfo->m_contactPoint.m_separatingNormal;
    v11 = (int *)&cdInfo->m_contactShapeKey[1];
    do
    {
      v12 = v5->m_wheelsInfo.m_data;
      v12[v8].m_currentSuspensionLength = v10[4].m_quad.m128_f32[0];
      v13 = v5->m_wheelsInfo.m_data;
      v14 = &v12[v8].m_spinAxisChassisSpace;
      v13[v8].m_contactPoint.m_position = (hkVector4f)v10[-1].m_quad;
      v13[v8].m_contactPoint.m_separatingNormal = (hkVector4f)v10->m_quad;
      v5->m_wheelsInfo.m_data[v8].m_contactFriction = v10[1].m_quad.m128_f32[0];
      v5->m_wheelsInfo.m_data[v8].m_contactBody = (hkpRigidBody *)v10[1].m_quad.m128_u64[1];
      v5->m_wheelsInfo.m_data->m_contactPoint.m_position.m_quad.m128_i32[v9 - 1] = *(v11 - 1);
      v5->m_wheelsInfo.m_data->m_contactPoint.m_position.m_quad.m128_i32[v9] = *v11;
      v5->m_wheelsInfo.m_data->m_contactPoint.m_position.m_quad.m128_i32[v9 + 1] = v11[1];
      v5->m_wheelsInfo.m_data->m_contactPoint.m_position.m_quad.m128_i32[v9 + 2] = v11[2];
      v5->m_wheelsInfo.m_data->m_contactPoint.m_position.m_quad.m128_i32[v9 + 3] = v11[3];
      v5->m_wheelsInfo.m_data->m_contactPoint.m_separatingNormal.m_quad.m128_i32[v9] = v11[4];
      v5->m_wheelsInfo.m_data->m_contactPoint.m_separatingNormal.m_quad.m128_i32[v9 + 1] = v11[5];
      v5->m_wheelsInfo.m_data->m_contactPoint.m_separatingNormal.m_quad.m128_i32[v9 + 2] = v11[6];
      *(float *)&v24 = *(float *)((char *)v5->m_wheelsSteeringAngle.m_data + v7) * 0.5;
      v15 = _mm_mul_ps(
              _mm_shuffle_ps((__m128)v24, (__m128)v24, 0),
              *(__m128 *)((char *)&v5->m_suspension->m_wheelParams.m_data->m_directionChassisSpace.m_quad + v6));
      v16 = &v12[v8].m_steeringOrientationChassisSpace;
      v17 = v15;
      v17.m128_i32[3] = 1065353216;
      v18 = _mm_mul_ps(v17, v17);
      v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
      v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
      v21 = _mm_rsqrt_ps(v20);
      v16->m_vec.m_quad = _mm_mul_ps(
                            v17,
                            _mm_andnot_ps(
                              _mm_cmpleps(v20, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                                _mm_mul_ps(*(__m128 *)_xmm, v21))));
      *v14 = v5->m_data->m_chassisOrientation.m_col2;
      hkVector4f::setRotatedDir(&b, v16, v14);
      hkVector4f::setRotatedDir(
        &v12[v8].m_spinAxisWs,
        (hkMatrix3f *)&v3->m_motion.m_motionState.m_transform.m_rotation.m_col0,
        &b);
      v7 = v25 + 4;
      v6 = v22 + 48;
      ++v4;
      v10 += 6;
      ++v8;
      v11 += 24;
      v9 += 56i64;
      v25 += 4i64;
      v22 += 48i64;
    }
    while ( v4 < v5->m_data->m_numWheels );
  }
}

// File Line: 291
// RVA: 0xE27D00
void __usercall hkpVehicleInstance::updateDriverInput(hkpVehicleInstance *this@<rcx>, float deltaTime@<xmm1>, hkpVehicleDriverInput::FilteredDriverInputOutput *filteredDriverInputInfo@<r8>, __int64 a4@<rdx>)
{
  hkpVehicleInstance *v4; // rbx
  hkpVehicleDriverInput::FilteredDriverInputOutput *v5; // rdi

  v4 = this;
  v5 = filteredDriverInputInfo;
  filteredDriverInputInfo->m_tryingToReverse.m_bool = this->m_tryingToReverse.m_bool;
  ((void (__fastcall *)(hkpVehicleDriverInput *, __int64, hkpVehicleInstance *, hkpVehicleDriverInputStatus *, hkpVehicleDriverInput::FilteredDriverInputOutput *))this->m_driverInput->vfptr[1].__first_virtual_table_function__)(
    this->m_driverInput,
    a4,
    v4,
    v4->m_deviceStatus,
    filteredDriverInputInfo);
  v4->m_tryingToReverse.m_bool = v5->m_tryingToReverse.m_bool;
}

// File Line: 299
// RVA: 0xE27D50
void __fastcall hkpVehicleInstance::updateSteering(hkpVehicleInstance *this, float deltaTime, hkpVehicleDriverInput::FilteredDriverInputOutput *filteredDriverInputInfo)
{
  int v3; // edi
  float v4; // xmm0_4
  float v5; // xmm2_4
  hkpVehicleDriverInput::FilteredDriverInputOutput *v6; // rsi
  hkpVehicleInstance *v7; // rbx
  int v8; // er9
  int v9; // er8
  __int64 v10; // rdx
  int v11; // er9
  int v12; // xmm1_4
  __int64 v13; // r8
  float v14; // ecx
  float v15; // [rsp+30h] [rbp-B8h]
  int v16; // [rsp+34h] [rbp-B4h]
  char *array; // [rsp+38h] [rbp-B0h]
  int v18; // [rsp+40h] [rbp-A8h]
  int v19; // [rsp+44h] [rbp-A4h]
  char v20; // [rsp+48h] [rbp-A0h]
  __int64 v21; // [rsp+F0h] [rbp+8h]

  v3 = this->m_wheelsSteeringAngle.m_size;
  v4 = this->m_mainSteeringAngle;
  v5 = this->m_mainSteeringAngleAssumingNoReduction;
  v6 = filteredDriverInputInfo;
  v7 = this;
  v18 = 0;
  v15 = v4;
  v16 = LODWORD(v5);
  v19 = -2147483616;
  array = &v20;
  if ( v3 > 32 )
  {
    v8 = v3;
    if ( v3 < 64 )
      v8 = 64;
    hkArrayUtil::_reserve(
      (hkResult *)&v21,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      v8,
      4);
  }
  v9 = 0;
  v18 = v3;
  if ( v7->m_wheelsSteeringAngle.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      ++v9;
      ++v10;
      *(float *)&array[v10 * 4 - 4] = v7->m_wheelsSteeringAngle.m_data[v10 - 1];
    }
    while ( v9 < v7->m_wheelsSteeringAngle.m_size );
  }
  ((void (__fastcall *)(hkpVehicleSteering *, float *, hkpVehicleInstance *, hkpVehicleDriverInput::FilteredDriverInputOutput *, float *))v7->m_steering->vfptr[1].__first_virtual_table_function__)(
    v7->m_steering,
    &v15,
    v7,
    v6,
    &v15);
  v11 = 0;
  v12 = v16;
  v7->m_mainSteeringAngle = v15;
  LODWORD(v7->m_mainSteeringAngleAssumingNoReduction) = v12;
  if ( v7->m_wheelsSteeringAngle.m_size > 0 )
  {
    v13 = 0i64;
    do
    {
      ++v11;
      v14 = *(float *)&array[v13 * 4];
      ++v13;
      v7->m_wheelsSteeringAngle.m_data[v13 - 1] = v14;
    }
    while ( v11 < v7->m_wheelsSteeringAngle.m_size );
  }
  v18 = 0;
  if ( v19 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v19);
}

// File Line: 324
// RVA: 0xE27EE0
void __fastcall hkpVehicleInstance::updateTransmission(hkpVehicleInstance *this, float deltaTime, hkpVehicleTransmission::TransmissionOutput *transmissionInfo)
{
  hkpVehicleInstance *v3; // rbx
  hkpVehicleTransmission::TransmissionOutput *v4; // rdi
  __int64 v5; // rdx

  v3 = this;
  v4 = transmissionInfo;
  v5 = (unsigned __int8)this->m_data->m_numWheels;
  transmissionInfo->m_numWheelsTramsmittedTorque = v5;
  transmissionInfo->m_isReversing.m_bool = this->m_isReversing.m_bool;
  transmissionInfo->m_currentGear = this->m_currentGear;
  transmissionInfo->m_delayed.m_bool = this->m_delayed.m_bool;
  transmissionInfo->m_clutchDelayCountdown = this->m_clutchDelayCountdown;
  ((void (__fastcall *)(hkpVehicleTransmission *, __int64, hkpVehicleInstance *, hkpVehicleTransmission::TransmissionOutput *))this->m_transmission->vfptr[1].__first_virtual_table_function__)(
    this->m_transmission,
    v5,
    this,
    transmissionInfo);
  v3->m_isReversing.m_bool = v4->m_isReversing.m_bool;
  v3->m_currentGear = v4->m_currentGear;
  v3->m_delayed.m_bool = v4->m_delayed.m_bool;
  v3->m_clutchDelayCountdown = v4->m_clutchDelayCountdown;
}

// File Line: 339
// RVA: 0xE27F70
void __fastcall hkpVehicleInstance::updateEngine(hkpVehicleInstance *this, float deltaTime, hkpVehicleDriverInput::FilteredDriverInputOutput *filteredDriverInputInfo, hkpVehicleTransmission::TransmissionOutput *transmissionInfo)
{
  float v4; // xmm0_4
  float v5; // xmm2_4
  hkpVehicleInstance *v6; // rbx
  hkpVehicleEngine *v7; // rcx
  int v8; // xmm1_4
  int v9; // [rsp+40h] [rbp+8h]
  float v10; // [rsp+44h] [rbp+Ch]

  v4 = this->m_rpm;
  v5 = this->m_torque;
  v6 = this;
  v7 = this->m_engine;
  v10 = v4;
  v9 = LODWORD(v5);
  ((void (__fastcall *)(hkpVehicleEngine *, int *, hkpVehicleInstance *, hkpVehicleDriverInput::FilteredDriverInputOutput *, hkpVehicleTransmission::TransmissionOutput *, int *))v7->vfptr[1].__first_virtual_table_function__)(
    v7,
    &v9,
    v6,
    filteredDriverInputInfo,
    transmissionInfo,
    &v9);
  v8 = v9;
  v6->m_rpm = v10;
  LODWORD(v6->m_torque) = v8;
}

// File Line: 350
// RVA: 0xE27FE0
void __fastcall hkpVehicleInstance::updateBrake(hkpVehicleInstance *this, float deltaTime, hkpVehicleDriverInput::FilteredDriverInputOutput *filteredDriverInputInfo, hkpVehicleBrake::WheelBreakingOutput *wheelBreakingInfo)
{
  int v4; // edi
  int v5; // eax
  hkpVehicleBrake::WheelBreakingOutput *v6; // rsi
  hkpVehicleDriverInput::FilteredDriverInputOutput *v7; // rbp
  hkpVehicleInstance *v8; // rbx
  int v9; // eax
  int v10; // er9
  int v11; // edi
  int v12; // eax
  int v13; // eax
  int v14; // er9
  int v15; // edi
  __int64 v16; // rdx
  int i; // er8
  char v18; // al
  __int64 v19; // rdx
  char v20; // al
  hkResult result; // [rsp+60h] [rbp+8h]

  v4 = this->m_isFixed.m_size;
  v5 = wheelBreakingInfo->m_isFixed.m_capacityAndFlags & 0x3FFFFFFF;
  v6 = wheelBreakingInfo;
  v7 = filteredDriverInputInfo;
  v8 = this;
  if ( v5 < v4 )
  {
    v9 = 2 * v5;
    v10 = this->m_isFixed.m_size;
    if ( v4 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_isFixed,
      v10,
      1);
  }
  v6->m_isFixed.m_size = v4;
  v11 = v8->m_isFixed.m_size;
  v12 = v6->m_brakingTorque.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v12 < v11 )
  {
    v13 = 2 * v12;
    v14 = v8->m_isFixed.m_size;
    if ( v11 < v13 )
      v14 = v13;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, v14, 4);
  }
  v6->m_brakingTorque.m_size = v11;
  v15 = 0;
  v16 = 0i64;
  for ( i = 0; i < v8->m_isFixed.m_size; v6->m_isFixed.m_data[v16 - 1].m_bool = v18 )
  {
    ++i;
    v18 = v8->m_isFixed.m_data[v16++].m_bool;
  }
  v6->m_wheelsTimeSinceMaxPedalInput = v8->m_wheelsTimeSinceMaxPedalInput;
  ((void (__fastcall *)(hkpVehicleBrake *, __int64, hkpVehicleInstance *, hkpVehicleDriverInput::FilteredDriverInputOutput *, hkpVehicleBrake::WheelBreakingOutput *))v8->m_brake->vfptr[1].__first_virtual_table_function__)(
    v8->m_brake,
    v16,
    v8,
    v7,
    v6);
  v19 = 0i64;
  if ( v6->m_isFixed.m_size > 0 )
  {
    do
    {
      ++v15;
      v20 = v6->m_isFixed.m_data[v19++].m_bool;
      v8->m_isFixed.m_data[v19 - 1].m_bool = v20;
    }
    while ( v15 < v6->m_isFixed.m_size );
  }
  v8->m_wheelsTimeSinceMaxPedalInput = v6->m_wheelsTimeSinceMaxPedalInput;
}

// File Line: 375
// RVA: 0xE28150
void __fastcall hkpVehicleInstance::updateSuspension(hkpVehicleInstance *this, float deltaTime, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo, hkArray<float,hkContainerHeapAllocator> *suspensionForces)
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
void __fastcall hkpVehicleInstance::updateAerodynamics(hkpVehicleInstance *this, float deltaTime, hkpVehicleAerodynamics::AerodynamicsDragOutput *aerodynamicsDragInfo)
{
  ((void (__fastcall *)(hkpVehicleAerodynamics *, hkBaseObjectVtbl *, hkpVehicleInstance *, hkpVehicleAerodynamics::AerodynamicsDragOutput *))this->m_aerodynamics->vfptr[1].__first_virtual_table_function__)(
    this->m_aerodynamics,
    this->m_aerodynamics->vfptr,
    this,
    aerodynamicsDragInfo);
}

// File Line: 386
// RVA: 0xE27660
void __fastcall hkpVehicleInstance::updateComponents(hkpVehicleInstance *this, hkStepInfo *stepInfo, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo, hkpVehicleAerodynamics::AerodynamicsDragOutput *aerodynamicsDragInfo)
{
  hkpVehicleInstance *v4; // rdi
  hkpVehicleAerodynamics::AerodynamicsDragOutput *v5; // r14
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *v6; // rsi
  hkStepInfo *v7; // r15
  _QWORD *v8; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  hkpVehicleData *v12; // rax
  int v13; // ebx
  hkLifoAllocator *v14; // rax
  float *v15; // r8
  int v16; // edx
  char *v17; // rcx
  float v18; // xmm6_4
  hkpVehicleData *v19; // r9
  signed int v20; // er8
  hkpVehicleData::WheelComponentParams *v21; // rdx
  __int64 v22; // rcx
  __int64 v23; // r10
  float *v24; // rdi
  signed int v25; // ebx
  hkLifoAllocator *v26; // rax
  int v27; // er8
  _QWORD *v28; // r8
  _QWORD *v29; // rcx
  unsigned __int64 v30; // rax
  signed __int64 v31; // rcx
  hkpVehicleDriverInput::FilteredDriverInputOutput filteredDriverInputInfo; // [rsp+20h] [rbp-C8h]
  hkpVehicleTransmission::TransmissionOutput transmissionInfo; // [rsp+30h] [rbp-B8h]
  hkpVehicleBrake::WheelBreakingOutput wheelBreakingInfo; // [rsp+50h] [rbp-98h]
  hkArray<float,hkContainerHeapAllocator> *suspensionForces; // [rsp+158h] [rbp+70h]
  __int64 *v36; // [rsp+160h] [rbp+78h]

  v4 = this;
  v5 = aerodynamicsDragInfo;
  v6 = cdInfo;
  v7 = stepInfo;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtUpdateComponents";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  wheelBreakingInfo.m_brakingTorque.m_data = wheelBreakingInfo.m_brakingTorque.m_storage;
  wheelBreakingInfo.m_brakingTorque.m_size = 0;
  *(_QWORD *)&wheelBreakingInfo.m_brakingTorque.m_storage[26] = (char *)&wheelBreakingInfo + 136;
  v12 = v4->m_data;
  wheelBreakingInfo.m_brakingTorque.m_capacityAndFlags = -2147483616;
  wheelBreakingInfo.m_brakingTorque.m_storage[28] = 0.0;
  LODWORD(wheelBreakingInfo.m_brakingTorque.m_storage[29]) = -2147483616;
  v13 = v12->m_numWheels;
  v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (float *)v14->m_cur;
  v16 = (4 * v13 + 127) & 0xFFFFFF80;
  v17 = (char *)v15 + v16;
  if ( v16 > v14->m_slabSize || v17 > v14->m_end )
    v15 = (float *)hkLifoAllocator::allocateFromNewSlab(v14, v16);
  else
    v14->m_cur = v17;
  v18 = v7->m_deltaTime.m_storage;
  transmissionInfo.m_wheelsTransmittedTorque = v15;
  hkpVehicleInstance::updateWheels(v4, v18, v6);
  hkpVehicleInstance::updateDriverInput(v4, v18, &filteredDriverInputInfo);
  hkpVehicleInstance::updateSteering(v4, v18, &filteredDriverInputInfo);
  hkpVehicleInstance::updateTransmission(v4, v18, &transmissionInfo);
  hkpVehicleInstance::updateEngine(v4, v18, &filteredDriverInputInfo, &transmissionInfo);
  hkpVehicleInstance::updateBrake(v4, v18, &filteredDriverInputInfo, &wheelBreakingInfo);
  hkpVehicleInstance::updateSuspension(v4, v18, v6, suspensionForces);
  hkpVehicleInstance::updateAerodynamics(v4, v18, v5);
  v19 = v4->m_data;
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
  v24 = transmissionInfo.m_wheelsTransmittedTorque;
  v25 = (4 * v19->m_numWheels + 127) & 0xFFFFFF80;
  v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (v25 + 15) & 0xFFFFFFF0;
  if ( v25 > v26->m_slabSize || (char *)v24 + v27 != v26->m_cur || v26->m_firstNonLifoEnd == v24 )
    hkLifoAllocator::slowBlockFree(v26, v24, v27);
  else
    v26->m_cur = v24;
  v28 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v29 = (_QWORD *)v28[1];
  if ( (unsigned __int64)v29 < v28[3] )
  {
    *v29 = "Et";
    v30 = __rdtsc();
    v31 = (signed __int64)(v29 + 2);
    *(_DWORD *)(v31 - 8) = v30;
    v28[1] = v31;
  }
  wheelBreakingInfo.m_brakingTorque.m_storage[28] = 0.0;
  if ( wheelBreakingInfo.m_brakingTorque.m_storage[29] >= 0.0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)&wheelBreakingInfo.m_brakingTorque.m_storage[26],
      LODWORD(wheelBreakingInfo.m_brakingTorque.m_storage[29]) & 0x3FFFFFFF);
  *(_QWORD *)&wheelBreakingInfo.m_brakingTorque.m_storage[26] = 0i64;
  wheelBreakingInfo.m_brakingTorque.m_storage[29] = -0.0;
  wheelBreakingInfo.m_brakingTorque.m_size = 0;
  if ( wheelBreakingInfo.m_brakingTorque.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      wheelBreakingInfo.m_brakingTorque.m_data,
      4 * wheelBreakingInfo.m_brakingTorque.m_capacityAndFlags);
}

// File Line: 422
// RVA: 0xE27940
void __fastcall hkpVehicleInstance::simulateVehicle(hkpVehicleInstance *this, hkStepInfo *stepInfo, hkpVehicleAerodynamics::AerodynamicsDragOutput *aerodynamicsDragInfo, hkArray<float,hkContainerHeapAllocator> *suspensionForceAtWheel, hkArray<float,hkContainerHeapAllocator> *totalLinearForceAtWheel, hkpVehicleJobResults *vehicleJobResults)
{
  hkpVehicleInstance *v6; // rbx
  hkArray<float,hkContainerHeapAllocator> *v7; // rdi
  hkpVehicleAerodynamics::AerodynamicsDragOutput *v8; // rsi
  hkStepInfo *v9; // rbp
  _QWORD *v10; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r10
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  hkpVehicleSimulation *v15; // rcx
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx
  hkpVehicleAerodynamics::AerodynamicsDragOutput *v20; // [rsp+30h] [rbp-28h]
  hkArray<float,hkContainerHeapAllocator> *v21; // [rsp+38h] [rbp-20h]
  hkArray<float,hkContainerHeapAllocator> *v22; // [rsp+40h] [rbp-18h]

  v6 = this;
  v7 = suspensionForceAtWheel;
  v8 = aerodynamicsDragInfo;
  v9 = stepInfo;
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  v12 = v10;
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "TtSimulateVehicle";
    v13 = __rdtsc();
    v14 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v14 - 8) = v13;
    v12[1] = v14;
  }
  v15 = v6->m_vehicleSimulation;
  v20 = v8;
  v22 = totalLinearForceAtWheel;
  v21 = v7;
  ((void (__fastcall *)(hkpVehicleSimulation *, hkpVehicleInstance *, hkStepInfo *, hkpVehicleAerodynamics::AerodynamicsDragOutput **, hkpVehicleJobResults *))v15->vfptr[3].__first_virtual_table_function__)(
    v15,
    v6,
    v9,
    &v20,
    vehicleJobResults);
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "Et";
    v18 = __rdtsc();
    v19 = (signed __int64)(v17 + 2);
    *(_DWORD *)(v19 - 8) = v18;
    v16[1] = v19;
  }
}

// File Line: 434
// RVA: 0xE26EA0
void __fastcall hkpVehicleInstance::stepVehicleUsingWheelCollideOutput(hkpVehicleInstance *this, hkStepInfo *stepInfo, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo)
{
  hkpVehicleInstance *v3; // rbx
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *v4; // rsi
  hkStepInfo *v5; // rdi
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  hkpVehicleData *v11; // rcx
  int v12; // eax
  _QWORD *v13; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  signed __int64 v16; // rcx
  hkArray<float,hkContainerHeapAllocator> totalLinearForceAtWheel; // [rsp+30h] [rbp-C8h]
  char v18; // [rsp+40h] [rbp-B8h]
  hkArray<float,hkContainerHeapAllocator> suspensionForceAtWheel; // [rsp+80h] [rbp-78h]
  char v20; // [rsp+90h] [rbp-68h]
  hkpVehicleAerodynamics::AerodynamicsDragOutput aerodynamicsDragInfo; // [rsp+D0h] [rbp-28h]

  v3 = this;
  v4 = cdInfo;
  v5 = stepInfo;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtDoVehicle";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = v3->m_data;
  v12 = v11->m_numWheels;
  suspensionForceAtWheel.m_data = (float *)&v20;
  suspensionForceAtWheel.m_capacityAndFlags = -2147483632;
  suspensionForceAtWheel.m_size = v12;
  totalLinearForceAtWheel.m_size = v11->m_numWheels;
  totalLinearForceAtWheel.m_data = (float *)&v18;
  totalLinearForceAtWheel.m_capacityAndFlags = -2147483632;
  hkpVehicleInstance::updateComponents(
    v3,
    v5,
    v4,
    &aerodynamicsDragInfo,
    &suspensionForceAtWheel,
    &totalLinearForceAtWheel);
  hkpVehicleInstance::simulateVehicle(
    v3,
    v5,
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
    v16 = (signed __int64)(v14 + 2);
    *(_DWORD *)(v16 - 8) = v15;
    v13[1] = v16;
  }
  totalLinearForceAtWheel.m_size = 0;
  if ( totalLinearForceAtWheel.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      totalLinearForceAtWheel.m_data,
      4 * totalLinearForceAtWheel.m_capacityAndFlags);
  totalLinearForceAtWheel.m_data = 0i64;
  totalLinearForceAtWheel.m_capacityAndFlags = 2147483648;
  suspensionForceAtWheel.m_size = 0;
  if ( suspensionForceAtWheel.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      suspensionForceAtWheel.m_data,
      4 * suspensionForceAtWheel.m_capacityAndFlags);
}

// File Line: 452
// RVA: 0xE26B80
void __fastcall hkpVehicleInstance::applyAction(hkpVehicleInstance *this, hkStepInfo *stepInfo)
{
  hkpVehicleInstance::stepVehicle(this, stepInfo);
}

// File Line: 457
// RVA: 0xE26B90
void __fastcall hkpVehicleInstance::stepVehicle(hkpVehicleInstance *this, hkStepInfo *stepInfo)
{
  hkStepInfo *v2; // r14
  hkpVehicleInstance *v3; // rbp
  __int64 v4; // rdx
  hkpVehicleData *v5; // rax
  int v6; // ebx
  hkLifoAllocator *v7; // rax
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *v8; // rdi
  char *v9; // rcx
  __int128 v10; // xmm1
  signed int v11; // esi
  signed int v12; // ebx
  hkLifoAllocator *v13; // rax
  int v14; // er8

  v2 = stepInfo;
  v3 = this;
  hkpVehicleInstance::updateBeforeCollisionDetection(this);
  v5 = v3->m_data;
  v6 = v5->m_numWheels;
  if ( v5->m_numWheels )
  {
    v7 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)v7->m_cur;
    v4 = (96 * v6 + 127) & 0xFFFFFF80;
    v9 = (char *)v8 + (signed int)v4;
    if ( (signed int)v4 > v7->m_slabSize || v9 > v7->m_end )
      v8 = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)hkLifoAllocator::allocateFromNewSlab(v7, v4);
    else
      v7->m_cur = v9;
  }
  else
  {
    v8 = 0i64;
  }
  v10 = LODWORD(v2->m_deltaTime.m_storage);
  v11 = v6 | 0x80000000;
  ((void (__fastcall *)(hkpVehicleWheelCollide *, __int64, hkpVehicleInstance *, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *))v3->m_wheelCollide->vfptr[2].__vecDelDtor)(
    v3->m_wheelCollide,
    v4,
    v3,
    v8);
  hkpVehicleInstance::stepVehicleUsingWheelCollideOutput(v3, v2, v8);
  v12 = (96 * v6 + 127) & 0xFFFFFF80;
  v13 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (v12 + 15) & 0xFFFFFFF0;
  if ( v12 > v13->m_slabSize || (char *)v8 + v14 != v13->m_cur || v13->m_firstNonLifoEnd == v8 )
    hkLifoAllocator::slowBlockFree(v13, v8, v14);
  else
    v13->m_cur = v8;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v8,
      96 * (v11 & 0x3FFFFFFF));
}

// File Line: 471
// RVA: 0xE27240
void __fastcall hkpVehicleInstance::calcCurrentPositionAndRotation(hkpVehicleInstance *this, hkpRigidBody *chassis, hkpVehicleSuspension *suspension, int wheelNo, hkVector4f *posOut, hkQuaternionf *rotOut)
{
  hkpVehicleData *v6; // rax
  __int64 v7; // rbx
  hkpRigidBody *v8; // rsi
  hkpVehicleSuspension *v9; // rdi
  hkVector4f *v10; // rbp
  float v11; // xmm6_4
  __m128 v12; // xmm2
  __m128 v13; // xmm5
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
  __m128 v33; // xmm1
  hkVector4f v34; // xmm2
  hkQuaternionf quat; // [rsp+20h] [rbp-88h]
  hkVector4f axis; // [rsp+30h] [rbp-78h]
  hkQuaternionf v37; // [rsp+40h] [rbp-68h]
  hkRotationf r; // [rsp+50h] [rbp-58h]
  float v39; // [rsp+C8h] [rbp+20h]

  v6 = this->m_data;
  v7 = wheelNo;
  v8 = chassis;
  v9 = suspension;
  r.m_col0 = v6->m_chassisOrientation.m_col1;
  r.m_col1 = v6->m_chassisOrientation.m_col0;
  v10 = &this->m_wheelsInfo.m_data[wheelNo].m_contactPoint.m_position;
  r.m_col2 = v6->m_chassisOrientation.m_col2;
  hkQuaternionf::set(&quat, &r);
  v11 = v10[12].m_quad.m128_f32[2];
  hkVector4f::setRotatedInverseDir(&axis, &quat, v10 + 9);
  hkQuaternionf::setAxisAngle(&v37, &axis, COERCE_FLOAT(LODWORD(v11) ^ _xmm[0]));
  v12 = v10[11].m_quad;
  v13 = v8->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
  v14 = _mm_shuffle_ps(
          v8->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
          v8->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
          255);
  v15 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v12);
  v16 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v13);
  v17 = _mm_mul_ps(v13, v12);
  v18 = _mm_sub_ps(v16, v15);
  v19 = _mm_shuffle_ps(v10[11].m_quad, v10[11].m_quad, 255);
  v20 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v18, v18, 201), _mm_mul_ps(v10[11].m_quad, v14)),
          _mm_mul_ps(v8->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad, v19));
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
  v39 = fmaxf(0.0, v10[7].m_quad.m128_f32[0]);
  v33 = v9->m_wheelParams.m_data[v7].m_hardpointChassisSpace.m_quad;
  v34.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_shuffle_ps(v33, v33, 85),
                       v8->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                     _mm_mul_ps(
                       _mm_shuffle_ps(v33, v33, 0),
                       v8->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
                   _mm_mul_ps(
                     _mm_shuffle_ps(v33, v33, 170),
                     v8->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)),
                 v8->m_motion.m_motionState.m_transform.m_translation.m_quad);
  *posOut = (hkVector4f)v34.m_quad;
  posOut->m_quad = _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v39), (__m128)LODWORD(v39), 0), v10[8].m_quad),
                     v34.m_quad);
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
  return (float)(COERCE_FLOAT(
                   _mm_andnot_ps(
                     _mm_cmpleps(v2, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v3, v2), v3)),
                         _mm_mul_ps(*(__m128 *)_xmm, v3)),
                       v2)))
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
  return (float)(COERCE_FLOAT(
                   _mm_andnot_ps(
                     _mm_cmpleps(v2, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v3, v2), v3)),
                         _mm_mul_ps(*(__m128 *)_xmm, v3)),
                       v2)))
               * 0.00062138814)
       * 3600.0;
}

// File Line: 529
// RVA: 0xE27060
hkpAction *__fastcall hkpVehicleInstance::clone(hkpVehicleInstance *this, hkArray<hkpEntity *,hkContainerHeapAllocator> *newEntities, hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  hkpVehicleInstance *v3; // rsi
  hkpRigidBody *v4; // rdi
  hkArray<hkpPhantom *,hkContainerHeapAllocator> *v5; // rbp
  _QWORD **v6; // rax
  hkpVehicleInstance *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rbx
  __int64 v10; // rax
  __int64 v11; // rax
  hkReferencedObject *v12; // rcx

  v3 = this;
  v4 = (hkpRigidBody *)*newEntities->m_data;
  v5 = newPhantoms;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkpVehicleInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 240i64);
  if ( v7 )
  {
    hkpVehicleInstance::hkpVehicleInstance(v7, v4);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  hkpVehicleInstance::operator=((hkpVehicleInstance *)v9, v3);
  *(_QWORD *)(v9 + 16) = 0i64;
  *(_QWORD *)(v9 + 24) = 0i64;
  *(_QWORD *)(v9 + 48) = v4;
  v10 = ((__int64 (__fastcall *)(hkpVehicleWheelCollide *, hkpRigidBody *, hkArray<hkpPhantom *,hkContainerHeapAllocator> *))v3->m_wheelCollide->vfptr[3].__first_virtual_table_function__)(
          v3->m_wheelCollide,
          v4,
          v5);
  *(_QWORD *)(v9 + 120) = v10;
  *(_BYTE *)(v10 + 16) = 1;
  *(_QWORD *)(v9 + 144) = v3->m_vehicleSimulation->vfptr[2].__vecDelDtor((hkBaseObject *)v3->m_vehicleSimulation, v9);
  v11 = ((__int64 (*)(void))v3->m_deviceStatus->vfptr[1].__first_virtual_table_function__)();
  v12 = *(hkReferencedObject **)(v9 + 56);
  *(_QWORD *)(v9 + 168) = v11;
  hkReferencedObject::addReference(v12);
  hkReferencedObject::addReference(*(hkReferencedObject **)(v9 + 64));
  hkReferencedObject::addReference(*(hkReferencedObject **)(v9 + 72));
  hkReferencedObject::addReference(*(hkReferencedObject **)(v9 + 80));
  hkReferencedObject::addReference(*(hkReferencedObject **)(v9 + 88));
  hkReferencedObject::addReference(*(hkReferencedObject **)(v9 + 96));
  hkReferencedObject::addReference(*(hkReferencedObject **)(v9 + 104));
  hkReferencedObject::addReference(*(hkReferencedObject **)(v9 + 112));
  hkReferencedObject::addReference(*(hkReferencedObject **)(v9 + 136));
  if ( v3->m_tyreMarks )
    hkReferencedObject::addReference(*(hkReferencedObject **)(v9 + 128));
  return (hkpAction *)v9;
}

// File Line: 572
// RVA: 0xE271A0
void __fastcall hkpVehicleInstance::addToWorld(hkpVehicleInstance *this, hkpWorld *world)
{
  hkpWorld *v2; // rdi
  hkpVehicleInstance *v3; // rbx

  v2 = world;
  v3 = this;
  hkpWorld::addEntity(world, this->m_entity, HK_ENTITY_ACTIVATION_DO_ACTIVATE);
  v3->m_wheelCollide->vfptr[4].__vecDelDtor((hkBaseObject *)&v3->m_wheelCollide->vfptr, (unsigned int)v2);
  ((void (__fastcall *)(hkpVehicleSimulation *, hkpWorld *))v3->m_vehicleSimulation->vfptr[2].__first_virtual_table_function__)(
    v3->m_vehicleSimulation,
    v2);
}

// File Line: 581
// RVA: 0xE271F0
void __fastcall hkpVehicleInstance::removeFromWorld(hkpVehicleInstance *this)
{
  hkpVehicleInstance *v1; // rbx
  hkBool result; // [rsp+30h] [rbp+8h]

  v1 = this;
  ((void (*)(void))this->m_vehicleSimulation->vfptr[3].__vecDelDtor)();
  ((void (*)(void))v1->m_wheelCollide->vfptr[4].__first_virtual_table_function__)();
  hkpWorld::removeEntity(v1->m_entity->m_world, &result, v1->m_entity);
}

