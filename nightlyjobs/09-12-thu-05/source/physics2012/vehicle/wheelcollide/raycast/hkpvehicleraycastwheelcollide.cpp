// File Line: 23
// RVA: 0xE28770
void __fastcall hkpVehicleRayCastWheelCollide::hkpVehicleRayCastWheelCollide(hkpVehicleRayCastWheelCollide *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_alreadyUsed.m_bool = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleRayCastWheelCollide::`vftable;
  this->m_wheelCollisionFilterInfo = 0;
  this->m_phantom = 0i64;
  this->m_rejectRayChassisListener.vfptr = (hkBaseObjectVtbl *)&hkpRejectChassisListener::`vftable{for `hkReferencedObject};
  *(_DWORD *)&this->m_rejectRayChassisListener.m_memSizeAndFlags = 0x1FFFF;
  this->m_rejectRayChassisListener.vfptr = (hkpPhantomOverlapListenerVtbl *)&hkpRejectChassisListener::`vftable{for `hkpPhantomOverlapListener};
  *(_WORD *)&this->m_alreadyUsed.m_bool = 256;
}

// File Line: 30
// RVA: 0xE28830
void __fastcall hkpVehicleRayCastWheelCollide::init(hkpVehicleRayCastWheelCollide *this, hkpVehicleInstance *vehicle)
{
  _QWORD **Value; // rax
  hkpAabbPhantom *v5; // rax
  hkpPhantomOverlapListener *v6; // rdi
  hkpAabbPhantom *v7; // rax
  hkpAabbPhantom *v8; // rcx
  hkAabb aabb; // [rsp+20h] [rbp-28h] BYREF

  ((void (__fastcall *)(hkpVehicleRayCastWheelCollide *, hkpVehicleInstance *, hkAabb *))this->vfptr[6].__first_virtual_table_function__)(
    this,
    vehicle,
    &aabb);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkpAabbPhantom *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 304i64);
  v6 = 0i64;
  if ( v5 )
  {
    hkpAabbPhantom::hkpAabbPhantom(v5, &aabb, this->m_wheelCollisionFilterInfo);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  this->m_phantom = v8;
  this->m_rejectRayChassisListener.m_chassis = &vehicle->m_entity->m_collidable;
  if ( this != (hkpVehicleRayCastWheelCollide *)-40i64 )
    v6 = &this->m_rejectRayChassisListener.hkpPhantomOverlapListener;
  hkpPhantom::addPhantomOverlapListener(v8, v6);
}

// File Line: 47
// RVA: 0xE288D0
void __fastcall hkpVehicleRayCastWheelCollide::getPhantoms(
        hkpVehicleRayCastWheelCollide *this,
        hkArray<hkpPhantom *,hkContainerHeapAllocator> *phantomsOut)
{
  hkpAabbPhantom *m_phantom; // rdi

  m_phantom = this->m_phantom;
  if ( phantomsOut->m_size == (phantomsOut->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&phantomsOut->m_data, 8);
  phantomsOut->m_data[phantomsOut->m_size++] = m_phantom;
}

// File Line: 53
// RVA: 0xE28950
hkpVehicleWheelCollide *__fastcall hkpVehicleRayCastWheelCollide::clone(
        hkpVehicleRayCastWheelCollide *this,
        hkpRigidBody *newChassis,
        hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  _QWORD **Value; // rax
  hkpVehicleRayCastWheelCollide *v7; // rax
  hkpPhantomOverlapListener *v8; // rdi
  __int64 v9; // rax
  __int64 v10; // rbx
  hkpPhantom *v11; // rcx
  hkpPhantomOverlapListener *v12; // rdx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkpVehicleRayCastWheelCollide *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                          Value[11],
                                          72i64);
  v8 = 0i64;
  if ( v7 )
  {
    hkpVehicleRayCastWheelCollide::hkpVehicleRayCastWheelCollide(v7);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = *newPhantoms->m_data;
  *(_QWORD *)(v10 + 32) = v11;
  hkReferencedObject::addReference(v11);
  v12 = &this->m_rejectRayChassisListener.hkpPhantomOverlapListener;
  if ( this == (hkpVehicleRayCastWheelCollide *)-40i64 )
    v12 = 0i64;
  hkpPhantom::removePhantomOverlapListener(*(hkpPhantom **)(v10 + 32), v12);
  if ( v10 != -40 )
    v8 = (hkpPhantomOverlapListener *)(v10 + 56);
  hkpPhantom::addPhantomOverlapListener(*(hkpPhantom **)(v10 + 32), v8);
  *(_QWORD *)(v10 + 64) = &newChassis->m_collidable;
  *(_DWORD *)(v10 + 24) = this->m_wheelCollisionFilterInfo;
  return (hkpVehicleWheelCollide *)v10;
}

// File Line: 69
// RVA: 0xE287C0
void __fastcall hkpVehicleRayCastWheelCollide::~hkpVehicleRayCastWheelCollide(hkpVehicleRayCastWheelCollide *this)
{
  hkpAabbPhantom *m_phantom; // rcx
  hkpPhantomOverlapListener *v3; // rdx

  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleRayCastWheelCollide::`vftable;
  m_phantom = this->m_phantom;
  if ( m_phantom )
  {
    if ( this->m_rejectRayChassisListener.m_chassis )
    {
      if ( this == (hkpVehicleRayCastWheelCollide *)-40i64 )
        v3 = 0i64;
      else
        v3 = &this->m_rejectRayChassisListener.hkpPhantomOverlapListener;
      hkpPhantom::removePhantomOverlapListener(m_phantom, v3);
    }
    hkReferencedObject::removeReference(this->m_phantom);
  }
  hkpRejectChassisListener::~hkpRejectChassisListener(&this->m_rejectRayChassisListener);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 86
// RVA: 0xE28CB0
void __fastcall hkpVehicleRayCastWheelCollide::calcWheelsAABB(
        hkpVehicleRayCastWheelCollide *this,
        hkpVehicleInstance *vehicle,
        hkAabb *aabbOut)
{
  int v3; // r10d
  hkVector4f v4; // xmm1
  __int64 v5; // r9
  hkpVehicleInstance::WheelInfo *m_data; // rax
  hkVector4f v7; // xmm0
  hkVector4f v8; // xmm1

  v3 = 1;
  aabbOut->m_min.m_quad = _mm_min_ps(
                            vehicle->m_wheelsInfo.m_data->m_hardPointWs.m_quad,
                            vehicle->m_wheelsInfo.m_data->m_rayEndPointWs.m_quad);
  v4.m_quad = _mm_max_ps(
                vehicle->m_wheelsInfo.m_data->m_hardPointWs.m_quad,
                vehicle->m_wheelsInfo.m_data->m_rayEndPointWs.m_quad);
  aabbOut->m_max = (hkVector4f)v4.m_quad;
  if ( vehicle->m_data->m_numWheels > 1 )
  {
    v5 = 1i64;
    do
    {
      m_data = vehicle->m_wheelsInfo.m_data;
      ++v3;
      v7.m_quad = _mm_min_ps(aabbOut->m_min.m_quad, m_data[v5++].m_rayEndPointWs.m_quad);
      aabbOut->m_min = (hkVector4f)v7.m_quad;
      aabbOut->m_min.m_quad = _mm_min_ps(v7.m_quad, m_data[v5 - 1].m_hardPointWs.m_quad);
      v8.m_quad = _mm_max_ps(v4.m_quad, m_data[v5 - 1].m_rayEndPointWs.m_quad);
      aabbOut->m_max = (hkVector4f)v8.m_quad;
      v4.m_quad = _mm_max_ps(v8.m_quad, m_data[v5 - 1].m_hardPointWs.m_quad);
      aabbOut->m_max = (hkVector4f)v4.m_quad;
    }
    while ( v3 < vehicle->m_data->m_numWheels );
  }
}

// File Line: 102
// RVA: 0xE28920
void __fastcall hkpVehicleRayCastWheelCollide::updateBeforeCollisionDetection(
        hkpVehicleRayCastWheelCollide *this,
        hkpVehicleInstance *vehicle)
{
  hkAabb newAabb; // [rsp+20h] [rbp-28h] BYREF

  ((void (__fastcall *)(hkpVehicleRayCastWheelCollide *, hkpVehicleInstance *, hkAabb *))this->vfptr[6].__first_virtual_table_function__)(
    this,
    vehicle,
    &newAabb);
  hkpAabbPhantom::setAabb(this->m_phantom, &newAabb);
}

// File Line: 114
// RVA: 0xE28D50
void __fastcall hkpVehicleRayCastWheelCollide::castSingleWheel(
        hkpVehicleRayCastWheelCollide *this,
        hkpVehicleInstance::WheelInfo *wheelInfo,
        hkpWorldRayCastOutput *output)
{
  hkVector4f v3; // xmm0
  hkVector4f v4; // xmm1
  unsigned int m_wheelCollisionFilterInfo; // eax
  hkpAabbPhantom *m_phantom; // rcx
  hkpWorldRayCastInput input; // [rsp+20h] [rbp-38h] BYREF

  v3.m_quad = (__m128)wheelInfo->m_hardPointWs;
  v4.m_quad = (__m128)wheelInfo->m_rayEndPointWs;
  m_wheelCollisionFilterInfo = this->m_wheelCollisionFilterInfo;
  m_phantom = this->m_phantom;
  input.m_userData = 0i64;
  input.m_from = (hkVector4f)v3.m_quad;
  input.m_to = (hkVector4f)v4.m_quad;
  input.m_filterInfo = m_wheelCollisionFilterInfo;
  input.m_enableShapeCollectionFilter.m_bool = 1;
  hkpAabbPhantom::castRay(m_phantom, &input, output);
}

// File Line: 125
// RVA: 0xE28A80
void __fastcall hkpVehicleRayCastWheelCollide::collideWheels(
        hkpVehicleRayCastWheelCollide *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfoOut)
{
  hkpVehicleData *m_data; // rax
  unsigned __int8 v5; // di
  int m_numWheels; // r14d
  hkBaseObjectVtbl *vfptr; // rax
  hkpVehicleInstance::WheelInfo *v11; // rdx
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *v12; // rsi
  hkBaseObjectVtbl *v13; // rax
  char v14[16]; // [rsp+30h] [rbp-78h] BYREF
  int v15; // [rsp+40h] [rbp-68h]
  int v16; // [rsp+44h] [rbp-64h]
  int v17; // [rsp+50h] [rbp-58h]
  int v18; // [rsp+70h] [rbp-38h]
  __int64 v19; // [rsp+80h] [rbp-28h]

  m_data = vehicle->m_data;
  v5 = 0;
  m_numWheels = (unsigned __int8)m_data->m_numWheels;
  if ( m_data->m_numWheels )
  {
    do
    {
      vfptr = this->vfptr;
      v15 = 1065353216;
      v11 = &vehicle->m_wheelsInfo.m_data[v5];
      v16 = -1;
      v12 = &cdInfoOut[v5];
      v18 = 0;
      v17 = -1;
      v19 = 0i64;
      ((void (__fastcall *)(hkpVehicleRayCastWheelCollide *, hkpVehicleInstance::WheelInfo *, char *))vfptr[7].__vecDelDtor)(
        this,
        v11,
        v14);
      v13 = this->vfptr;
      if ( v19 )
        ((void (__fastcall *)(hkpVehicleRayCastWheelCollide *, hkpVehicleInstance *, _QWORD, char *, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *))v13[7].__first_virtual_table_function__)(
          this,
          vehicle,
          v5,
          v14,
          v12);
      else
        ((void (__fastcall *)(hkpVehicleRayCastWheelCollide *, hkpVehicleInstance *, _QWORD, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *))v13[8].__vecDelDtor)(
          this,
          vehicle,
          v5,
          v12);
      ((void (__fastcall *)(hkpVehicleRayCastWheelCollide *, hkpVehicleInstance *, _QWORD, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *))this->vfptr[5].__first_virtual_table_function__)(
        this,
        vehicle,
        v5++,
        v12);
    }
    while ( v5 < m_numWheels );
  }
}

// File Line: 152
// RVA: 0xE28DA0
void __fastcall hkpVehicleRayCastWheelCollide::getCollisionOutputFromCastResult(
        hkpVehicleRayCastWheelCollide *this,
        hkpVehicleInstance *vehicle,
        unsigned __int8 wheelInfoNum,
        hkpWorldRayCastOutput *rayCastOutput,
        hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo)
{
  hkpVehicleInstance::WheelInfo *v5; // r10
  float m_length; // xmm2_4
  hkpCollidable *m_rootCollidable; // rax
  hkpRigidBody *v8; // r11
  float v9; // xmm1_4
  hkVector4f v10; // xmm6
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  hkpEntity *m_entity; // rax
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 m_quad; // xmm0
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm3
  float v22; // xmm5_4
  unsigned int v23; // [rsp+30h] [rbp+18h]

  v5 = &vehicle->m_wheelsInfo.m_data[wheelInfoNum];
  m_length = vehicle->m_suspension->m_wheelParams.m_data[wheelInfoNum].m_length;
  cdInfo->m_contactPoint.m_separatingNormal.m_quad = _mm_shuffle_ps(
                                                       rayCastOutput->m_normal.m_quad,
                                                       _mm_unpackhi_ps(
                                                         rayCastOutput->m_normal.m_quad,
                                                         cdInfo->m_contactPoint.m_separatingNormal.m_quad),
                                                       196);
  cdInfo->m_contactShapeKey[0] = rayCastOutput->m_shapeKeys[0];
  cdInfo->m_contactShapeKey[1] = rayCastOutput->m_shapeKeys[1];
  cdInfo->m_contactShapeKey[2] = rayCastOutput->m_shapeKeys[2];
  cdInfo->m_contactShapeKey[3] = rayCastOutput->m_shapeKeys[3];
  cdInfo->m_contactShapeKey[4] = rayCastOutput->m_shapeKeys[4];
  cdInfo->m_contactShapeKey[5] = rayCastOutput->m_shapeKeys[5];
  cdInfo->m_contactShapeKey[6] = rayCastOutput->m_shapeKeys[6];
  cdInfo->m_contactShapeKey[7] = rayCastOutput->m_shapeKeys[7];
  m_rootCollidable = rayCastOutput->m_rootCollidable;
  if ( m_rootCollidable->m_broadPhaseHandle.m_type == 1 )
    v8 = (hkpRigidBody *)((char *)m_rootCollidable + m_rootCollidable->m_ownerOffset);
  else
    v8 = 0i64;
  cdInfo->m_contactBody = v8;
  *(float *)&v23 = (float)(vehicle->m_data->m_wheelParams.m_data[wheelInfoNum].m_radius + m_length)
                 * rayCastOutput->m_hitFraction;
  v9 = *(float *)&v23 - vehicle->m_data->m_wheelParams.m_data[wheelInfoNum].m_radius;
  cdInfo->m_currentSuspensionLength = v9;
  cdInfo->m_contactPoint.m_position.m_quad = _mm_add_ps(
                                               _mm_mul_ps(
                                                 _mm_shuffle_ps((__m128)v23, (__m128)v23, 0),
                                                 v5->m_suspensionDirectionWs.m_quad),
                                               v5->m_hardPointWs.m_quad);
  cdInfo->m_contactPoint.m_separatingNormal.m_quad.m128_f32[3] = v9;
  v10.m_quad = (__m128)cdInfo->m_contactPoint.m_separatingNormal;
  cdInfo->m_contactFriction = cdInfo->m_contactBody->m_material.m_friction;
  v11 = _mm_mul_ps(v10.m_quad, v5->m_suspensionDirectionWs.m_quad);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  if ( v12.m128_f32[0] >= (float)(0.0
                                - _mm_shuffle_ps(
                                    (__m128)LODWORD(vehicle->m_data->m_normalClippingAngleCos),
                                    (__m128)LODWORD(vehicle->m_data->m_normalClippingAngleCos),
                                    0).m128_f32[0]) )
  {
    cdInfo->m_suspensionClosingSpeed = 0.0;
    cdInfo->m_suspensionScalingFactor = 1.0 / vehicle->m_data->m_normalClippingAngleCos;
  }
  else
  {
    m_entity = vehicle->m_entity;
    v14 = _mm_sub_ps(
            cdInfo->m_contactPoint.m_position.m_quad,
            v8->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
    v15 = _mm_sub_ps(
            cdInfo->m_contactPoint.m_position.m_quad,
            m_entity->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
    v16 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), m_entity->m_motion.m_angularVelocity.m_quad),
            _mm_mul_ps(
              _mm_shuffle_ps(
                m_entity->m_motion.m_angularVelocity.m_quad,
                m_entity->m_motion.m_angularVelocity.m_quad,
                201),
              v15));
    m_quad = v8->m_motion.m_angularVelocity.m_quad;
    v18 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), m_quad);
    v19 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v14);
    v14.m128_f32[0] = _mm_rcp_ps(v12).m128_f32[0];
    v20 = _mm_sub_ps(v18, v19);
    v21 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_add_ps(_mm_shuffle_ps(v16, v16, 201), m_entity->m_motion.m_linearVelocity.m_quad),
              _mm_add_ps(_mm_shuffle_ps(v20, v20, 201), v8->m_motion.m_linearVelocity.m_quad)),
            v10.m_quad);
    v22 = 0.0 - (float)((float)(2.0 - (float)(v14.m128_f32[0] * v12.m128_f32[0])) * v14.m128_f32[0]);
    cdInfo->m_suspensionScalingFactor = v22;
    cdInfo->m_suspensionClosingSpeed = (float)((float)(_mm_shuffle_ps(v21, v21, 85).m128_f32[0]
                                                     + _mm_shuffle_ps(v21, v21, 0).m128_f32[0])
                                             + _mm_shuffle_ps(v21, v21, 170).m128_f32[0])
                                     * v22;
  }
}

// File Line: 213
// RVA: 0xE28FE0
void __fastcall hkpVehicleRayCastWheelCollide::getCollisionOutputWithoutHit(
        hkpVehicleRayCastWheelCollide *this,
        hkpVehicleInstance *vehicle,
        unsigned __int8 wheelNum,
        hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo)
{
  hkpVehicleInstance::WheelInfo *v4; // r10
  float m_length; // xmm3_4
  __m128 v6; // xmm2

  v4 = &vehicle->m_wheelsInfo.m_data[wheelNum];
  m_length = vehicle->m_suspension->m_wheelParams.m_data[wheelNum].m_length;
  cdInfo->m_currentSuspensionLength = m_length;
  cdInfo->m_contactBody = 0i64;
  cdInfo->m_suspensionClosingSpeed = 0.0;
  cdInfo->m_contactPoint.m_position = v4->m_rayEndPointWs;
  v6 = _mm_xor_ps(
         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
         v4->m_suspensionDirectionWs.m_quad);
  cdInfo->m_contactPoint.m_separatingNormal.m_quad = _mm_shuffle_ps(
                                                       v6,
                                                       _mm_unpackhi_ps(
                                                         v6,
                                                         cdInfo->m_contactPoint.m_separatingNormal.m_quad),
                                                       196);
  cdInfo->m_contactFriction = 0.0;
  cdInfo->m_suspensionScalingFactor = 1.0;
  cdInfo->m_contactPoint.m_separatingNormal.m_quad.m128_f32[3] = m_length;
}

// File Line: 231
// RVA: 0xE28BA0
__int64 __fastcall hkpVehicleRayCastWheelCollide::buildRayCastCommands(
        hkpVehicleRayCastWheelCollide *this,
        hkpVehicleInstance *vehicle,
        hkpCollisionFilter *collisionFilter,
        unsigned int filterSize,
        hkpShapeRayCastCommand *commandStorage,
        hkpWorldRayCastOutput *outputStorage)
{
  int m_size; // r11d
  char v11; // r8
  int m_numWheels; // r10d
  unsigned int *p_m_filterInfo; // rax
  hkpVehicleInstance::WheelInfo *v15; // rcx
  hkpRayShapeCollectionFilter *v16; // rcx
  unsigned int m_storage; // ecx
  hkpCollidable **m_data; // rdx

  this->m_phantom->vfptr[5].__first_virtual_table_function__(this->m_phantom);
  m_size = this->m_phantom->m_overlappingCollidables.m_size;
  if ( m_size <= 0 )
    return 0i64;
  v11 = 0;
  m_numWheels = vehicle->m_data->m_numWheels;
  if ( m_numWheels > 0 )
  {
    p_m_filterInfo = &commandStorage->m_rayInput.m_filterInfo;
    do
    {
      v15 = &vehicle->m_wheelsInfo.m_data[v11];
      *((_OWORD *)p_m_filterInfo - 2) = v15->m_hardPointWs;
      *((_OWORD *)p_m_filterInfo - 1) = v15->m_rayEndPointWs;
      *p_m_filterInfo = this->m_wheelCollisionFilterInfo;
      v16 = &collisionFilter->hkpRayShapeCollectionFilter;
      if ( !collisionFilter )
        v16 = 0i64;
      *((_QWORD *)p_m_filterInfo + 1) = v16;
      m_storage = collisionFilter->m_type.m_storage;
      p_m_filterInfo[9] = filterSize;
      p_m_filterInfo[8] = m_storage;
      *((_BYTE *)p_m_filterInfo + 72) = 0;
      m_data = this->m_phantom->m_overlappingCollidables.m_data;
      ++v11;
      *((_QWORD *)p_m_filterInfo + 7) = outputStorage;
      p_m_filterInfo[12] = m_size;
      *((_QWORD *)p_m_filterInfo + 8) = 1i64;
      *((_QWORD *)p_m_filterInfo + 5) = m_data;
      p_m_filterInfo += 28;
      ++outputStorage;
    }
    while ( v11 < m_numWheels );
  }
  return (unsigned int)m_numWheels;
}

// File Line: 288
// RVA: 0xE28A20
void __fastcall hkpVehicleRayCastWheelCollide::addToWorld(hkpVehicleRayCastWheelCollide *this, hkpWorld *world)
{
  hkpWorld::addPhantom(world, this->m_phantom);
}

// File Line: 294
// RVA: 0xE28A40
void __fastcall hkpVehicleRayCastWheelCollide::removeFromWorld(hkpVehicleRayCastWheelCollide *this)
{
  hkpWorld::removePhantom(this->m_phantom->m_world, this->m_phantom);
}

// File Line: 301
// RVA: 0xE28A60
void __fastcall hkpVehicleRayCastWheelCollide::setCollisionFilterInfo(
        hkpVehicleRayCastWheelCollide *this,
        unsigned int filterInfo)
{
  hkpAabbPhantom *m_phantom; // rax

  m_phantom = this->m_phantom;
  this->m_wheelCollisionFilterInfo = filterInfo;
  if ( m_phantom )
    m_phantom->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = filterInfo;
}

