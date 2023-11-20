// File Line: 18
// RVA: 0xE2F0B0
void __fastcall hkpVehiclePerWheelSimulation::hkpVehiclePerWheelSimulation(hkpVehiclePerWheelSimulation *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehiclePerWheelSimulation::`vftable{for `hkpVehicleSimulation};
  this->vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpVehiclePerWheelSimulation::`vftable{for `hkpWorldPostSimulationListener};
  this->m_wheelData.m_capacityAndFlags = 2147483648;
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
  hkpVehiclePerWheelSimulation *v2; // rbx
  int v3; // eax
  __int64 v4; // rcx
  hkpWheelFrictionConstraintData *v5; // rdx
  int v6; // er8

  v1 = this->m_world == 0i64;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehiclePerWheelSimulation::`vftable{for `hkpVehicleSimulation};
  this->vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpVehiclePerWheelSimulation::`vftable{for `hkpWorldPostSimulationListener};
  if ( !v1 )
    hkpVehiclePerWheelSimulation::removeFromWorld(this);
  v3 = v2->m_wheelData.m_size - 1;
  v4 = v3;
  if ( v3 >= 0 )
  {
    v5 = &v2->m_wheelData.m_data[v3].m_frictionData;
    do
    {
      --v4;
      v5->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
      v5 = (hkpWheelFrictionConstraintData *)((char *)v5 - 336);
    }
    while ( v4 >= 0 );
  }
  v6 = v2->m_wheelData.m_capacityAndFlags;
  v2->m_wheelData.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_wheelData.m_data,
      336 * (v6 & 0x3FFFFFFF));
  v2->m_wheelData.m_data = 0i64;
  v2->m_wheelData.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpWorldPostSimulationListener::`vftable;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 40
// RVA: 0xE2F1E0
void __fastcall hkpVehiclePerWheelSimulation::init(hkpVehiclePerWheelSimulation *this, hkpVehicleInstance *instance)
{
  hkpVehicleData *v2; // r15
  __int64 v3; // rbx
  int v4; // eax
  hkpVehiclePerWheelSimulation *v5; // r14
  int v6; // eax
  int v7; // er9
  int v8; // eax
  __int64 v9; // rcx
  hkpWheelFrictionConstraintData *v10; // rdx
  int v11; // eax
  __int64 v12; // rdx
  _QWORD *v13; // rcx
  int v14; // ebp
  __int64 v15; // rbx
  __int64 v16; // rdi
  hkpVehicleData::WheelComponentParams *v17; // r8
  float v18; // xmm2_4
  float v19; // xmm2_4
  hkpVehiclePerWheelSimulation::WheelData *v20; // rax
  signed __int64 v21; // rdx
  hkResult result; // [rsp+90h] [rbp+8h]

  this->m_instance = instance;
  v2 = instance->m_data;
  v3 = v2->m_numWheels;
  v4 = this->m_wheelData.m_capacityAndFlags & 0x3FFFFFFF;
  v5 = this;
  if ( v4 < (signed int)v3 )
  {
    v6 = 2 * v4;
    v7 = v2->m_numWheels;
    if ( (signed int)v3 < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_wheelData,
      v7,
      336);
  }
  v8 = v5->m_wheelData.m_size - v3 - 1;
  v9 = v8;
  if ( v8 >= 0 )
  {
    v10 = &v5->m_wheelData.m_data[v3 + v8].m_frictionData;
    do
    {
      --v9;
      v10->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
      v10 = (hkpWheelFrictionConstraintData *)((char *)v10 - 336);
    }
    while ( v9 >= 0 );
  }
  v11 = v5->m_wheelData.m_size;
  v12 = (signed int)v3 - v11;
  if ( (signed int)v3 - v11 > 0 )
  {
    v13 = (_QWORD *)v5->m_wheelData.m_data[v5->m_wheelData.m_size].m_frictionData.m_atoms.m_friction.m_frictionImpulse;
    do
    {
      if ( v13 != (_QWORD *)244 )
      {
        *((_DWORD *)v13 - 47) = 0x1FFFF;
        *(_QWORD *)((char *)v13 - 180) = 0i64;
        *(_QWORD *)((char *)v13 - 196) = &hkpWheelFrictionConstraintData::`vftable;
        *((_WORD *)v13 - 82) = 2;
        *((_WORD *)v13 - 10) = 28;
        *((_BYTE *)v13 - 18) = 1;
        *v13 = 0i64;
        v13[1] = 0i64;
        *(_QWORD *)((char *)v13 + 20) = 0i64;
        *(_QWORD *)((char *)v13 + 28) = 0i64;
      }
      v13 += 42;
      --v12;
    }
    while ( v12 );
  }
  v5->m_wheelData.m_size = v3;
  v14 = 0;
  if ( (signed int)v3 > 0 )
  {
    v15 = 0i64;
    v16 = 0i64;
    do
    {
      v17 = v2->m_wheelParams.m_data;
      v18 = v17[v16].m_mass;
      if ( v18 == 0.0 )
        v19 = 0.0;
      else
        v19 = 2.0 / (float)((float)(v17[v16].m_radius * v18) * v17[v16].m_radius);
      v20 = v5->m_wheelData.m_data;
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
      v21 = (signed __int64)&v5->m_wheelData.m_data[v14];
      hkpWheelFrictionConstraintData::init(
        (hkpWheelFrictionConstraintData *)(v21 + 48),
        (hkpWheelFrictionConstraintAtom::Axle *)v21,
        v17[v16].m_radius);
      ++v14;
      ++v16;
      ++v15;
    }
    while ( v14 < v5->m_wheelData.m_size );
  }
}

// File Line: 70
// RVA: 0xE2F440
hkpVehicleSimulation *__fastcall hkpVehiclePerWheelSimulation::clone(hkpVehiclePerWheelSimulation *this, hkpVehicleInstance *instance)
{
  hkpVehiclePerWheelSimulation *v2; // rdi
  hkpVehicleInstance *v3; // rsi
  _QWORD **v4; // rax
  hkpVehiclePerWheelSimulation *v5; // rax
  _DWORD *v6; // rax
  _DWORD *v7; // rbx

  v2 = this;
  v3 = instance;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkpVehiclePerWheelSimulation *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(
                                         v4[11],
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
  v7[10] = LODWORD(v2->m_slipDamping);
  v7[11] = LODWORD(v2->m_impulseScaling);
  v7[12] = LODWORD(v2->m_maxImpulse);
  v7[13] = LODWORD(v2->m_takeDynamicVelocity);
  v7[14] = LODWORD(v2->m_curbDamping);
  (*(void (__fastcall **)(_DWORD *, hkpVehicleInstance *))(*(_QWORD *)v7 + 24i64))(v7, v3);
  return (hkpVehicleSimulation *)v7;
}

// File Line: 85
// RVA: 0xE2F4D0
void __fastcall hkpVehiclePerWheelSimulation::addToWorld(hkpVehiclePerWheelSimulation *this, hkpWorld *world)
{
  this->m_world = world;
  hkpWorld::addWorldPostSimulationListener(world, (hkpWorldPostSimulationListener *)&this->vfptr);
}

// File Line: 91
// RVA: 0xE2F4F0
void __fastcall hkpVehiclePerWheelSimulation::removeFromWorld(hkpVehiclePerWheelSimulation *this)
{
  int v1; // ebx
  hkpVehiclePerWheelSimulation *v2; // rdi
  hkpWorldPostSimulationListener *v3; // rdx
  __int64 v4; // rsi

  v1 = 0;
  v2 = this;
  v3 = (hkpWorldPostSimulationListener *)&this->vfptr;
  if ( !this )
    v3 = 0i64;
  hkpWorld::removeWorldPostSimulationListener(this->m_world, v3);
  v2->m_world = 0i64;
  if ( v2->m_wheelData.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      if ( v2->m_wheelData.m_data[v4].m_frictionConstraint )
        hkpVehiclePerWheelSimulation::removeFrictionConstraint(v2, v1);
      ++v1;
      ++v4;
    }
    while ( v1 < v2->m_wheelData.m_size );
  }
}

// File Line: 108
// RVA: 0xE2F570
void __fastcall hkpVehiclePerWheelSimulation::simulateVehicle(hkpVehiclePerWheelSimulation *this, hkpVehicleInstance *instance, hkStepInfo *stepInfo, hkpVehicleSimulation::SimulationInput *simulInput, hkpVehicleJobResults *vehicleJobResults)
{
  hkStepInfo *v5; // rsi
  hkpVehicleSimulation::SimulationInput *v6; // rdi
  hkpVehiclePerWheelSimulation *v7; // rbx

  v5 = stepInfo;
  v6 = simulInput;
  v7 = this;
  hkpVehiclePerWheelSimulation::applySuspensionForces(this, stepInfo, simulInput);
  hkpVehiclePerWheelSimulation::applyAerodynamicForces(v7, v5, v6);
  hkpVehiclePerWheelSimulation::setupFriction(v7, v5, v6);
}

// File Line: 124
// RVA: 0xE2F9E0
void __fastcall hkpVehiclePerWheelSimulation::applySuspensionForces(hkpVehiclePerWheelSimulation *this, hkStepInfo *stepInfo, hkpVehicleSimulation::SimulationInput *simulInput)
{
  hkpVehicleInstance *v3; // rax
  __int64 v4; // rbx
  hkpVehicleSimulation::SimulationInput *v5; // r15
  hkpEntity *v6; // r13
  hkStepInfo *v7; // r12
  hkpVehiclePerWheelSimulation *v8; // r14
  __int64 v9; // rsi
  __int64 v10; // rdi
  hkpVehicleInstance::WheelInfo *v11; // rbp
  float v12; // xmm0_4
  __m128 v13; // [rsp+20h] [rbp-48h]

  v3 = this->m_instance;
  v4 = 0i64;
  v5 = simulInput;
  v6 = v3->m_entity;
  v7 = stepInfo;
  v8 = this;
  v9 = (unsigned __int8)v3->m_data->m_numWheels;
  if ( (signed int)v9 > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = v8->m_instance->m_wheelsInfo.m_data;
      v12 = v5->suspensionForceAtWheel->m_data[v4];
      if ( v12 > 0.0 )
      {
        v13 = _mm_mul_ps(
                _mm_shuffle_ps(
                  (__m128)COERCE_UNSIGNED_INT(v12 * v7->m_deltaTime.m_storage),
                  (__m128)COERCE_UNSIGNED_INT(v12 * v7->m_deltaTime.m_storage),
                  0),
                v11[v10].m_contactPoint.m_separatingNormal.m_quad);
        hkpEntity::activate(v6);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, hkVector4f *))v6->m_motion.vfptr[11].__first_virtual_table_function__)(
          &v6->m_motion,
          &v13,
          &v11[v10].m_hardPointWs);
      }
      ++v4;
      ++v10;
    }
    while ( v4 < v9 );
  }
}

// File Line: 148
// RVA: 0xE2FAD0
void __fastcall hkpVehiclePerWheelSimulation::applyAerodynamicForces(hkpVehiclePerWheelSimulation *this, hkStepInfo *stepInfo, hkpVehicleSimulation::SimulationInput *simulInput)
{
  hkpVehiclePerWheelSimulation *v3; // rbx
  hkpEntity *v4; // rbp
  hkpVehicleAerodynamics::AerodynamicsDragOutput *v5; // rax
  __m128 v6; // xmm6
  __m128 **v7; // rdi
  hkpEntity *v8; // rcx
  __m128 v9; // xmm9
  __m128 v10; // xmm8
  __m128 v11; // xmm4
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm5
  __m128 v15; // [rsp+20h] [rbp-58h]
  __m128 v16; // [rsp+30h] [rbp-48h]

  v3 = this;
  v4 = this->m_instance->m_entity;
  v5 = simulInput->aerodynamicsDragInfo;
  v6 = _mm_shuffle_ps(
         (__m128)LODWORD(stepInfo->m_deltaTime.m_storage),
         (__m128)LODWORD(stepInfo->m_deltaTime.m_storage),
         0);
  v7 = (__m128 **)simulInput;
  v15 = v4->m_motion.m_linearVelocity.m_quad;
  v15 = _mm_add_ps(
          v15,
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(
                (__m128)v4->m_motion.m_inertiaAndMassInv.m_quad.m128_u32[3],
                (__m128)v4->m_motion.m_inertiaAndMassInv.m_quad.m128_u32[3],
                0),
              v6),
            v5->m_aerodynamicsForce.m_quad));
  hkpEntity::activate(v4);
  v4->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v4->m_motion.vfptr, (unsigned int)&v15);
  v8 = v3->m_instance->m_entity;
  v9 = v8->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad;
  v10 = v8->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad;
  v11 = _mm_mul_ps((*v7)[1], v6);
  v12 = _mm_unpacklo_ps(v10, v8->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad);
  v13 = _mm_movelh_ps(v12, v9);
  v14 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(_mm_movehl_ps(v13, v12), v9, 212)),
              _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v13)),
            _mm_mul_ps(
              _mm_shuffle_ps(
                _mm_unpackhi_ps(
                  v8->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad,
                  v8->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                v9,
                228),
              _mm_shuffle_ps(v11, v11, 170))),
          v4->m_motion.m_inertiaAndMassInv.m_quad);
  v16 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v8->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v10)),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v9)),
          v4->m_motion.m_angularVelocity.m_quad);
  hkpEntity::activate(v4);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v4->m_motion.vfptr[9].__first_virtual_table_function__)(
    &v4->m_motion,
    &v16);
}

// File Line: 171
// RVA: 0xE30170
void __fastcall hkpVehiclePerWheelSimulation::removeFrictionConstraint(hkpVehiclePerWheelSimulation *this, int w_it)
{
  hkpVehiclePerWheelSimulation::WheelData *v2; // rbx
  hkBool result; // [rsp+38h] [rbp+10h]

  v2 = &this->m_wheelData.m_data[w_it];
  hkpWorld::removeConstraint(this->m_instance->m_entity->m_world, &result, v2->m_frictionConstraint);
  hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_frictionConstraint->vfptr);
  --v2->m_axle.m_numWheelsOnGround;
  v2->m_frictionConstraint = 0i64;
}

// File Line: 188
// RVA: 0xE2FC70
void __fastcall hkpVehiclePerWheelSimulation::setupFriction(hkpVehiclePerWheelSimulation *this, hkStepInfo *stepInfo, hkpVehicleSimulation::SimulationInput *simulInput)
{
  hkpVehicleInstance *v3; // rax
  int v4; // er14
  __int64 v5; // r15
  hkpEntity *v6; // r9
  hkpVehicleSimulation::SimulationInput *v7; // r10
  hkStepInfo *v8; // r11
  hkpVehiclePerWheelSimulation *v9; // rbp
  __int64 v10; // rdx
  __int64 v11; // r12
  __int64 v12; // rbx
  hkpVehicleInstance *v13; // rcx
  hkpVehiclePerWheelSimulation::WheelData *v14; // rdi
  hkpVehicleData::WheelComponentParams *v15; // r8
  hkVector4f *v16; // rsi
  hkpConstraintInstance *v17; // rax
  hkpEntity *v18; // r13
  float v19; // xmm10_4
  char v20; // al
  int v21; // eax
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm2
  __m128 v25; // xmm5
  float v26; // xmm9_4
  __m128 v27; // xmm5
  __m128 v28; // xmm1
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  __m128 v31; // xmm4
  __m128 v32; // xmm5
  __m128 v33; // xmm5
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  __m128 v36; // xmm1
  hkVector4f *side; // ST28_8
  _QWORD **v38; // rax
  hkpConstraintInstance *v39; // rax
  hkpEntity *v40; // rsi
  hkpEntity *entityA; // [rsp+30h] [rbp-A8h]
  hkpVehicleData::WheelComponentParams *v42; // [rsp+E0h] [rbp+8h]
  hkStepInfo *v43; // [rsp+E8h] [rbp+10h]
  hkpVehicleSimulation::SimulationInput *v44; // [rsp+F0h] [rbp+18h]
  __int64 v45; // [rsp+F8h] [rbp+20h]

  v44 = simulInput;
  v43 = stepInfo;
  v3 = this->m_instance;
  v4 = 0;
  v5 = 0i64;
  v6 = v3->m_entity;
  v7 = simulInput;
  v8 = stepInfo;
  v9 = this;
  entityA = v3->m_entity;
  if ( this->m_wheelData.m_size > 0 )
  {
    v10 = 0i64;
    v11 = 0i64;
    v45 = 0i64;
    v12 = 0i64;
    do
    {
      v13 = v9->m_instance;
      v14 = v9->m_wheelData.m_data;
      v15 = v13->m_data->m_wheelParams.m_data;
      v16 = (hkVector4f *)((char *)&v13->m_wheelsInfo.m_data->m_contactPoint.m_position + v10);
      v17 = v14[v12].m_frictionConstraint;
      v18 = (hkpEntity *)v16[2].m_quad.m128_u64[1];
      v42 = v15;
      v19 = v7->totalLinearForceAtWheel->m_data[v5] * v15[v11].m_radius;
      if ( v17 && v17->m_entities[1] != v18 )
      {
        hkpVehiclePerWheelSimulation::removeFrictionConstraint(v9, v4);
        v10 = v45;
        v6 = entityA;
        v15 = v42;
        v7 = v44;
        v8 = v43;
      }
      v20 = v9->m_instance->m_isFixed.m_data[v5].m_bool;
      v14[v12].m_axle.m_isFixed.m_bool = v20;
      if ( v20 )
        v14[v12].m_axle.m_spinVelocity = 0.0;
      else
        v14[v12].m_axle.m_spinVelocity = v16[12].m_quad.m128_f32[0];
      if ( v18 )
      {
        v22 = v16[1].m_quad;
        v23 = (__m128)LODWORD(v7->suspensionForceAtWheel->m_data[v4]);
        v24 = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v16[8].m_quad), v22);
        v25 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v16[10].m_quad, v16[10].m_quad, 201), v22),
                _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v16[10].m_quad));
        v26 = (float)(COERCE_FLOAT((unsigned int)(2
                                                * COERCE_SIGNED_INT(
                                                    (float)(COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 85))
                                                          + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 0)))
                                                  + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 170)))) >> 1)
                    * v15[v11].m_friction)
            * v16[2].m_quad.m128_f32[0];
        v27 = _mm_shuffle_ps(v25, v25, 201);
        v28 = _mm_mul_ps(v27, v27);
        v29 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                _mm_shuffle_ps(v28, v28, 170));
        v30 = _mm_rsqrt_ps(v29);
        v31 = _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v29, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                    _mm_mul_ps(*(__m128 *)_xmm, v30))),
                v27);
        v14[v12].m_forwardDirectionWs.m_quad = v31;
        v32 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v16[1].m_quad, v16[1].m_quad, 201), v31),
                _mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v16[1].m_quad));
        v33 = _mm_shuffle_ps(v32, v32, 201);
        v34 = _mm_mul_ps(v33, v33);
        v35 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                _mm_shuffle_ps(v34, v34, 170));
        v36 = _mm_rsqrt_ps(v35);
        side = &v14[v12].m_sideDirectionWs;
        side->m_quad = _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmpleps(v35, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v36, v35), v36)),
                             _mm_mul_ps(*(__m128 *)_xmm, v36))),
                         v33);
        v14[v12].m_contactLocal.m_quad = _mm_sub_ps(
                                           v16->m_quad,
                                           v6->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
        hkpWheelFrictionConstraintData::setInWorldSpace(
          &v14[v12].m_frictionData,
          &v6->m_motion.m_motionState.m_transform,
          &v18->m_motion.m_motionState.m_transform,
          v16,
          &v14[v12].m_forwardDirectionWs,
          side);
        hkpWheelFrictionConstraintData::setMaxFrictionForce(&v14[v12].m_frictionData, v26);
        hkpWheelFrictionConstraintData::setTorque(&v14[v12].m_frictionData, v19);
        hkpWheelFrictionConstraintData::setImpulseScaling(
          &v14[v12].m_frictionData,
          v9->m_impulseScaling,
          v9->m_maxImpulse);
        if ( !v14[v12].m_frictionConstraint )
        {
          v38 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v39 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v38[11] + 8i64))(
                                           v38[11],
                                           112i64);
          if ( v39 )
          {
            v40 = entityA;
            hkpConstraintInstance::hkpConstraintInstance(
              v39,
              entityA,
              v18,
              (hkpConstraintData *)&v14[v12].m_frictionData.vfptr,
              PRIORITY_PSI);
          }
          else
          {
            v40 = entityA;
          }
          v14[v12].m_frictionConstraint = v39;
          hkpWorld::addConstraint(v40->m_world, v39);
          ++v14[v12].m_axle.m_numWheelsOnGround;
        }
        v10 = v45;
      }
      else
      {
        v16[13].m_quad.m128_u64[0] = 0i64;
        v16[12].m_quad.m128_i32[3] = 0;
        if ( !v14[v12].m_axle.m_isFixed.m_bool )
          v14[v12].m_axle.m_spinVelocity = (float)((float)(v19 * v8->m_deltaTime.m_storage)
                                                 * v14[v12].m_axle.m_invInertia)
                                         + v14[v12].m_axle.m_spinVelocity;
        v21 = LODWORD(v14[v12].m_axle.m_spinVelocity);
        v16[13].m_quad.m128_i32[1] = 0;
        v16[12].m_quad.m128_i32[1] = v21;
      }
      v6 = entityA;
      v7 = v44;
      v8 = v43;
      v10 += 224i64;
      ++v4;
      ++v5;
      ++v12;
      ++v11;
      v45 = v10;
    }
    while ( v4 < v9->m_wheelData.m_size );
  }
}

// File Line: 270
// RVA: 0xE2F5D0
void __fastcall hkpVehiclePerWheelSimulation::postSimulationCallback(hkpVehiclePerWheelSimulation *this, hkpWorld *world)
{
  hkpVehiclePerWheelSimulation *v2; // r14
  float v3; // xmm9_4
  int v4; // er12
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
  hkVector4f worldLinearFrictionImpulse; // [rsp+20h] [rbp-C8h]
  hkVector4f worldAngularVelocityDeltaOut; // [rsp+30h] [rbp-B8h]
  float v28; // [rsp+F0h] [rbp+8h]
  __int64 v29; // [rsp+F8h] [rbp+10h]

  v2 = this;
  v3 = world->m_dynamicsStepInfo.m_stepInfo.m_deltaTime.m_storage;
  v4 = 0;
  v29 = *(_QWORD *)(*(_QWORD *)&this->m_memSizeAndFlags + 48i64);
  if ( SLODWORD(this->m_curbDamping) > 0 )
  {
    v5 = 0i64;
    v6 = 0i64;
    v7 = 0i64;
    while ( 1 )
    {
      v8 = *(_QWORD *)&v2->m_memSizeAndFlags;
      v9 = *(_QWORD *)&v2->m_maxImpulse;
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
        v28 = hkpWheelFrictionConstraintData::getSideSlipImpulse((hkpWheelFrictionConstraintData *)(v7 + v9 + 48));
        v16 = _mm_add_ps(
                v15,
                _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v28), (__m128)LODWORD(v28), 0), *(__m128 *)(v7 + v9 + 304)));
        worldLinearFrictionImpulse.m_quad = v16;
        hkpVehiclePerWheelSimulation::computeAngularChassisAcceleration(
          (hkpVehiclePerWheelSimulation *)((char *)v2 - 16),
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
                              - (float)((float)((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 85))
                                                                      + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 0)))
                                                              + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 170)))
                                                      / *(float *)(v5 + v11))
                                              * *(float *)&v2->m_instance)
                                      * v3);
        }
        *(float *)(v6 + v10 + 208) = hkpWheelFrictionConstraintData::getSideFrictionImpulse((hkpWheelFrictionConstraintData *)(v7 + v9 + 48))
                                   / v3;
        v20 = _mm_mul_ps(*(__m128 *)(v7 + v9 + 304), v18);
        v21 = _mm_mul_ps(v18, v18);
        *(float *)(v6 + v10 + 216) = (float)(COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 170));
        *(float *)(v6 + v10 + 204) = (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 85))
                                                           + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 0)))
                                                   + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 170)))
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
        v24 = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 0)))
                    + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 170)))
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
      *(float *)(v6 + v10 - 24) = (float)(v3 * *(float *)(v7 + v9 - 336)) + *(float *)(v6 + v10 - 24);
      if ( v4 >= SLODWORD(v2->m_curbDamping) )
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
void __fastcall hkpVehiclePerWheelSimulation::computeAngularChassisAcceleration(hkpVehiclePerWheelSimulation *this, hkVector4f *worldLinearFrictionImpulse, hkVector4f *contactLocal, hkVector4f *worldAngularVelocityDeltaOut)
{
  hkpEntity *v4; // rcx
  __m128 v5; // xmm3
  __m128 v6; // xmm5
  __m128 v7; // xmm1
  __m128 v8; // xmm5
  __m128 v9; // xmm2
  hkVector4f b; // [rsp+20h] [rbp-18h]

  v4 = this->m_instance->m_entity;
  v5 = v4->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad;
  v6 = _mm_sub_ps(
         _mm_mul_ps(
           _mm_shuffle_ps(worldLinearFrictionImpulse->m_quad, worldLinearFrictionImpulse->m_quad, 201),
           contactLocal->m_quad),
         _mm_mul_ps(_mm_shuffle_ps(contactLocal->m_quad, contactLocal->m_quad, 201), worldLinearFrictionImpulse->m_quad));
  v7 = _mm_unpacklo_ps(
         v4->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad,
         v4->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad);
  v8 = _mm_shuffle_ps(v6, v6, 201);
  v9 = _mm_movelh_ps(v7, v5);
  b.m_quad = _mm_mul_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(_mm_movehl_ps(v9, v7), v5, 212)),
                   _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), v9)),
                 _mm_mul_ps(
                   _mm_shuffle_ps(
                     _mm_unpackhi_ps(
                       v4->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad,
                       v4->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                     v5,
                     228),
                   _mm_shuffle_ps(v8, v8, 170))),
               v4->m_motion.m_inertiaAndMassInv.m_quad);
  hkVector4f::setRotatedDir(
    worldAngularVelocityDeltaOut,
    (hkMatrix3f *)&v4->m_motion.m_motionState.m_transform.m_rotation.m_col0,
    &b);
}

