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
  hkpVehicleInstance *v2; // rsi
  hkpVehicleRayCastWheelCollide *v3; // rbx
  _QWORD **v4; // rax
  hkpAabbPhantom *v5; // rax
  hkpPhantomOverlapListener *v6; // rdi
  hkpPhantom *v7; // rax
  hkpPhantom *v8; // rcx
  hkAabb aabb; // [rsp+20h] [rbp-28h]

  v2 = vehicle;
  v3 = this;
  ((void (__fastcall *)(hkpVehicleRayCastWheelCollide *, hkpVehicleInstance *, hkAabb *))this->vfptr[6].__first_virtual_table_function__)(
    this,
    vehicle,
    &aabb);
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkpAabbPhantom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 304i64);
  v6 = 0i64;
  if ( v5 )
  {
    hkpAabbPhantom::hkpAabbPhantom(v5, &aabb, v3->m_wheelCollisionFilterInfo);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  v3->m_phantom = (hkpAabbPhantom *)v8;
  v3->m_rejectRayChassisListener.m_chassis = (hkpCollidable *)&v2->m_entity->m_collidable.m_shape;
  if ( v3 != (hkpVehicleRayCastWheelCollide *)-40i64 )
    v6 = (hkpPhantomOverlapListener *)&v3->m_rejectRayChassisListener.vfptr;
  hkpPhantom::addPhantomOverlapListener(v8, v6);
}

// File Line: 47
// RVA: 0xE288D0
void __fastcall hkpVehicleRayCastWheelCollide::getPhantoms(hkpVehicleRayCastWheelCollide *this, hkArray<hkpPhantom *,hkContainerHeapAllocator> *phantomsOut)
{
  hkpAabbPhantom *v2; // rdi
  hkArray<hkpPhantom *,hkContainerHeapAllocator> *v3; // rbx

  v2 = this->m_phantom;
  v3 = phantomsOut;
  if ( phantomsOut->m_size == (phantomsOut->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, phantomsOut, 8);
  v3->m_data[v3->m_size++] = (hkpPhantom *)&v2->vfptr;
}

// File Line: 53
// RVA: 0xE28950
hkpVehicleWheelCollide *__fastcall hkpVehicleRayCastWheelCollide::clone(hkpVehicleRayCastWheelCollide *this, hkpRigidBody *newChassis, hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  hkpVehicleRayCastWheelCollide *v3; // rsi
  hkArray<hkpPhantom *,hkContainerHeapAllocator> *v4; // r14
  hkpRigidBody *v5; // rbp
  _QWORD **v6; // rax
  hkpVehicleRayCastWheelCollide *v7; // rax
  hkpPhantomOverlapListener *v8; // rdi
  __int64 v9; // rax
  __int64 v10; // rbx
  hkReferencedObject *v11; // rcx
  hkpPhantomOverlapListener *v12; // rdx

  v3 = this;
  v4 = newPhantoms;
  v5 = newChassis;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkpVehicleRayCastWheelCollide *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(
                                          v6[11],
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
  v11 = (hkReferencedObject *)*v4->m_data;
  *(_QWORD *)(v10 + 32) = v11;
  hkReferencedObject::addReference(v11);
  v12 = (hkpPhantomOverlapListener *)&v3->m_rejectRayChassisListener.vfptr;
  if ( v3 == (hkpVehicleRayCastWheelCollide *)-40i64 )
    v12 = 0i64;
  hkpPhantom::removePhantomOverlapListener(*(hkpPhantom **)(v10 + 32), v12);
  if ( v10 != -40 )
    v8 = (hkpPhantomOverlapListener *)(v10 + 56);
  hkpPhantom::addPhantomOverlapListener(*(hkpPhantom **)(v10 + 32), v8);
  *(_QWORD *)(v10 + 64) = (char *)v5 + 32;
  *(_DWORD *)(v10 + 24) = v3->m_wheelCollisionFilterInfo;
  return (hkpVehicleWheelCollide *)v10;
}

// File Line: 69
// RVA: 0xE287C0
void __fastcall hkpVehicleRayCastWheelCollide::~hkpVehicleRayCastWheelCollide(hkpVehicleRayCastWheelCollide *this)
{
  hkpVehicleRayCastWheelCollide *v1; // rbx
  hkpAabbPhantom *v2; // rcx
  hkpPhantomOverlapListener *v3; // rdx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleRayCastWheelCollide::`vftable;
  v2 = this->m_phantom;
  if ( v2 )
  {
    if ( v1->m_rejectRayChassisListener.m_chassis )
    {
      if ( v1 == (hkpVehicleRayCastWheelCollide *)-40i64 )
        v3 = 0i64;
      else
        v3 = (hkpPhantomOverlapListener *)&v1->m_rejectRayChassisListener.vfptr;
      hkpPhantom::removePhantomOverlapListener((hkpPhantom *)&v2->vfptr, v3);
    }
    hkReferencedObject::removeReference((hkReferencedObject *)&v1->m_phantom->vfptr);
  }
  hkpRejectChassisListener::~hkpRejectChassisListener(&v1->m_rejectRayChassisListener);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 86
// RVA: 0xE28CB0
void __fastcall hkpVehicleRayCastWheelCollide::calcWheelsAABB(hkpVehicleRayCastWheelCollide *this, hkpVehicleInstance *vehicle, hkAabb *aabbOut)
{
  signed int v3; // er10
  hkVector4f v4; // xmm1
  signed __int64 v5; // r9
  hkpVehicleInstance::WheelInfo *v6; // rax
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
      v6 = vehicle->m_wheelsInfo.m_data;
      ++v3;
      ++v5;
      v7.m_quad = _mm_min_ps(aabbOut->m_min.m_quad, *((__m128 *)&v6[v5] - 8));
      aabbOut->m_min = (hkVector4f)v7.m_quad;
      aabbOut->m_min.m_quad = _mm_min_ps(v7.m_quad, *((__m128 *)&v6[v5] - 9));
      v8.m_quad = _mm_max_ps(v4.m_quad, *((__m128 *)&v6[v5] - 8));
      aabbOut->m_max = (hkVector4f)v8.m_quad;
      v4.m_quad = _mm_max_ps(v8.m_quad, *((__m128 *)&v6[v5] - 9));
      aabbOut->m_max = (hkVector4f)v4.m_quad;
    }
    while ( v3 < vehicle->m_data->m_numWheels );
  }
}

// File Line: 102
// RVA: 0xE28920
void __fastcall hkpVehicleRayCastWheelCollide::updateBeforeCollisionDetection(hkpVehicleRayCastWheelCollide *this, hkpVehicleInstance *vehicle)
{
  hkpVehicleRayCastWheelCollide *v2; // rbx
  hkAabb newAabb; // [rsp+20h] [rbp-28h]

  v2 = this;
  ((void (__fastcall *)(hkpVehicleRayCastWheelCollide *, hkpVehicleInstance *, hkAabb *))this->vfptr[6].__first_virtual_table_function__)(
    this,
    vehicle,
    &newAabb);
  hkpAabbPhantom::setAabb(v2->m_phantom, &newAabb);
}

// File Line: 114
// RVA: 0xE28D50
void __fastcall hkpVehicleRayCastWheelCollide::castSingleWheel(hkpVehicleRayCastWheelCollide *this, hkpVehicleInstance::WheelInfo *wheelInfo, hkpWorldRayCastOutput *output)
{
  hkVector4f v3; // xmm0
  hkVector4f v4; // xmm1
  unsigned int v5; // eax
  hkpAabbPhantom *v6; // rcx
  hkpWorldRayCastInput input; // [rsp+20h] [rbp-38h]

  v3.m_quad = (__m128)wheelInfo->m_hardPointWs;
  v4.m_quad = (__m128)wheelInfo->m_rayEndPointWs;
  v5 = this->m_wheelCollisionFilterInfo;
  v6 = this->m_phantom;
  input.m_userData = 0i64;
  input.m_from = (hkVector4f)v3.m_quad;
  input.m_to = (hkVector4f)v4.m_quad;
  *(_QWORD *)&input.m_filterInfo = v5;
  input.m_enableShapeCollectionFilter.m_bool = 1;
  hkpAabbPhantom::castRay(v6, &input, output);
}

// File Line: 125
// RVA: 0xE28A80
void __fastcall hkpVehicleRayCastWheelCollide::collideWheels(hkpVehicleRayCastWheelCollide *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfoOut)
{
  unsigned __int8 v4; // di
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *v5; // r15
  signed int v6; // er14
  hkpVehicleInstance *v7; // rbp
  hkpVehicleRayCastWheelCollide *v8; // rbx
  hkBaseObjectVtbl *v9; // rax
  signed __int64 v10; // rdx
  signed __int64 v11; // rsi
  hkBaseObjectVtbl *v12; // rax
  char v13; // [rsp+30h] [rbp-78h]
  int v14; // [rsp+40h] [rbp-68h]
  int v15; // [rsp+44h] [rbp-64h]
  int v16; // [rsp+50h] [rbp-58h]
  int v17; // [rsp+70h] [rbp-38h]
  __int64 v18; // [rsp+80h] [rbp-28h]

  v4 = 0;
  v5 = cdInfoOut;
  v6 = (unsigned __int8)vehicle->m_data->m_numWheels;
  v7 = vehicle;
  v8 = this;
  if ( v6 > 0 )
  {
    do
    {
      v9 = v8->vfptr;
      v14 = 1065353216;
      v10 = (signed __int64)&v7->m_wheelsInfo.m_data[v4];
      v15 = -1;
      v11 = (signed __int64)&v5[v4];
      v17 = 0;
      v16 = -1;
      v18 = 0i64;
      ((void (__fastcall *)(hkpVehicleRayCastWheelCollide *, signed __int64, char *))v9[7].__vecDelDtor)(v8, v10, &v13);
      v12 = v8->vfptr;
      if ( v18 )
        ((void (__fastcall *)(hkpVehicleRayCastWheelCollide *, hkpVehicleInstance *, _QWORD, char *, signed __int64))v12[7].__first_virtual_table_function__)(
          v8,
          v7,
          v4,
          &v13,
          v11);
      else
        ((void (__fastcall *)(hkpVehicleRayCastWheelCollide *, hkpVehicleInstance *, _QWORD, signed __int64))v12[8].__vecDelDtor)(
          v8,
          v7,
          v4,
          v11);
      ((void (__fastcall *)(hkpVehicleRayCastWheelCollide *, hkpVehicleInstance *, _QWORD, signed __int64))v8->vfptr[5].__first_virtual_table_function__)(
        v8,
        v7,
        v4++,
        v11);
    }
    while ( v4 < v6 );
  }
}

// File Line: 152
// RVA: 0xE28DA0
void __fastcall hkpVehicleRayCastWheelCollide::getCollisionOutputFromCastResult(hkpVehicleRayCastWheelCollide *this, hkpVehicleInstance *vehicle, char wheelInfoNum, hkpWorldRayCastOutput *rayCastOutput, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo)
{
  hkpVehicleInstance::WheelInfo *v5; // r10
  float v6; // xmm2_4
  hkpCollidable *v7; // rax
  hkpRigidBody *v8; // r11
  float v9; // xmm1_4
  float v10; // xmm1_4
  hkVector4f v11; // xmm6
  hkVector4f v12; // xmm1
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  hkpEntity *v15; // rax
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  __m128 v23; // xmm3
  float v24; // xmm5_4
  float v25; // [rsp+30h] [rbp+18h]

  v5 = &vehicle->m_wheelsInfo.m_data[(unsigned __int8)wheelInfoNum];
  v6 = vehicle->m_suspension->m_wheelParams.m_data[(unsigned __int8)wheelInfoNum].m_length;
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
  v7 = rayCastOutput->m_rootCollidable;
  if ( v7->m_broadPhaseHandle.m_type == 1 )
    v8 = (hkpRigidBody *)((char *)v7 + v7->m_ownerOffset);
  else
    v8 = 0i64;
  cdInfo->m_contactBody = v8;
  v9 = (float)(vehicle->m_data->m_wheelParams.m_data[(unsigned __int8)wheelInfoNum].m_radius + v6)
     * rayCastOutput->m_hitFraction;
  v25 = v9;
  v10 = v9 - vehicle->m_data->m_wheelParams.m_data[(unsigned __int8)wheelInfoNum].m_radius;
  cdInfo->m_currentSuspensionLength = v10;
  cdInfo->m_contactPoint.m_position.m_quad = _mm_add_ps(
                                               _mm_mul_ps(
                                                 _mm_shuffle_ps((__m128)LODWORD(v25), (__m128)LODWORD(v25), 0),
                                                 v5->m_suspensionDirectionWs.m_quad),
                                               v5->m_hardPointWs.m_quad);
  cdInfo->m_contactPoint.m_separatingNormal.m_quad.m128_f32[3] = v10;
  v11.m_quad = (__m128)cdInfo->m_contactPoint.m_separatingNormal;
  v12.m_quad = (__m128)cdInfo->m_contactPoint.m_separatingNormal;
  cdInfo->m_contactFriction = cdInfo->m_contactBody->m_material.m_friction;
  v13 = _mm_mul_ps(v12.m_quad, v5->m_suspensionDirectionWs.m_quad);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  if ( v14.m128_f32[0] >= (float)(0.0
                                - COERCE_FLOAT(
                                    _mm_shuffle_ps(
                                      (__m128)LODWORD(vehicle->m_data->m_normalClippingAngleCos),
                                      (__m128)LODWORD(vehicle->m_data->m_normalClippingAngleCos),
                                      0))) )
  {
    cdInfo->m_suspensionClosingSpeed = 0.0;
    cdInfo->m_suspensionScalingFactor = 1.0 / vehicle->m_data->m_normalClippingAngleCos;
  }
  else
  {
    v15 = vehicle->m_entity;
    v16 = _mm_sub_ps(
            cdInfo->m_contactPoint.m_position.m_quad,
            v8->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
    v17 = _mm_sub_ps(
            cdInfo->m_contactPoint.m_position.m_quad,
            v15->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
    v18 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v15->m_motion.m_angularVelocity.m_quad),
            _mm_mul_ps(
              _mm_shuffle_ps(v15->m_motion.m_angularVelocity.m_quad, v15->m_motion.m_angularVelocity.m_quad, 201),
              v17));
    v19 = v8->m_motion.m_angularVelocity.m_quad;
    v20 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v19);
    v21 = _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v16);
    v16.m128_i32[0] = (unsigned __int128)_mm_rcp_ps(v14);
    v22 = _mm_sub_ps(v20, v21);
    v23 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_add_ps(_mm_shuffle_ps(v18, v18, 201), v15->m_motion.m_linearVelocity.m_quad),
              _mm_add_ps(_mm_shuffle_ps(v22, v22, 201), v8->m_motion.m_linearVelocity.m_quad)),
            v11.m_quad);
    v24 = 0.0 - (float)((float)(2.0 - (float)(v16.m128_f32[0] * v14.m128_f32[0])) * v16.m128_f32[0]);
    cdInfo->m_suspensionScalingFactor = v24;
    cdInfo->m_suspensionClosingSpeed = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 85))
                                                     + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 0)))
                                             + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 170)))
                                     * v24;
  }
}

// File Line: 213
// RVA: 0xE28FE0
void __fastcall hkpVehicleRayCastWheelCollide::getCollisionOutputWithoutHit(hkpVehicleRayCastWheelCollide *this, hkpVehicleInstance *vehicle, char wheelNum, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo)
{
  hkpVehicleInstance::WheelInfo *v4; // r10
  float v5; // xmm3_4
  __m128 v6; // xmm2

  v4 = &vehicle->m_wheelsInfo.m_data[(unsigned __int8)wheelNum];
  v5 = vehicle->m_suspension->m_wheelParams.m_data[(unsigned __int8)wheelNum].m_length;
  cdInfo->m_currentSuspensionLength = v5;
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
  cdInfo->m_contactPoint.m_separatingNormal.m_quad.m128_f32[3] = v5;
}

// File Line: 231
// RVA: 0xE28BA0
__int64 __fastcall hkpVehicleRayCastWheelCollide::buildRayCastCommands(hkpVehicleRayCastWheelCollide *this, hkpVehicleInstance *vehicle, hkpCollisionFilter *collisionFilter, int filterSize, hkpShapeRayCastCommand *commandStorage, hkpWorldRayCastOutput *outputStorage)
{
  hkpVehicleRayCastWheelCollide *v6; // rdi
  int v7; // ebp
  hkpCollisionFilter *v8; // rbx
  hkpVehicleInstance *v9; // rsi
  int v10; // er11
  char v11; // r8
  signed int v12; // er10
  hkpWorldRayCastOutput *v13; // r9
  unsigned int *v14; // rax
  signed __int64 v15; // rcx
  signed __int64 v16; // rcx
  unsigned int v17; // ecx
  hkpCollidable **v18; // rdx

  v6 = this;
  v7 = filterSize;
  v8 = collisionFilter;
  v9 = vehicle;
  ((void (*)(void))this->m_phantom->vfptr[5].__first_virtual_table_function__)();
  v10 = v6->m_phantom->m_overlappingCollidables.m_size;
  if ( v10 <= 0 )
    return 0i64;
  v11 = 0;
  v12 = v9->m_data->m_numWheels;
  if ( v12 > 0 )
  {
    v13 = outputStorage;
    v14 = &commandStorage->m_rayInput.m_filterInfo;
    do
    {
      v15 = (signed __int64)&v9->m_wheelsInfo.m_data[v11];
      *((_OWORD *)v14 - 2) = *(_OWORD *)(v15 + 80);
      *((_OWORD *)v14 - 1) = *(_OWORD *)(v15 + 96);
      *v14 = v6->m_wheelCollisionFilterInfo;
      v16 = (signed __int64)&v8->vfptr;
      if ( !v8 )
        v16 = 0i64;
      *((_QWORD *)v14 + 1) = v16;
      v17 = v8->m_type.m_storage;
      v14[9] = v7;
      v14[8] = v17;
      *((_BYTE *)v14 + 72) = 0;
      v18 = v6->m_phantom->m_overlappingCollidables.m_data;
      ++v11;
      *((_QWORD *)v14 + 7) = v13;
      v14[12] = v10;
      *((_QWORD *)v14 + 8) = 1i64;
      *((_QWORD *)v14 + 5) = v18;
      v14 += 28;
      ++v13;
    }
    while ( v11 < v12 );
  }
  return (unsigned int)v12;
}

// File Line: 288
// RVA: 0xE28A20
void __fastcall hkpVehicleRayCastWheelCollide::addToWorld(hkpVehicleRayCastWheelCollide *this, hkpWorld *world)
{
  hkpWorld::addPhantom(world, (hkpPhantom *)&this->m_phantom->vfptr);
}

// File Line: 294
// RVA: 0xE28A40
void __fastcall hkpVehicleRayCastWheelCollide::removeFromWorld(hkpVehicleRayCastWheelCollide *this)
{
  hkpWorld::removePhantom(this->m_phantom->m_world, (hkpPhantom *)&this->m_phantom->vfptr);
}

// File Line: 301
// RVA: 0xE28A60
void __fastcall hkpVehicleRayCastWheelCollide::setCollisionFilterInfo(hkpVehicleRayCastWheelCollide *this, unsigned int filterInfo)
{
  hkpAabbPhantom *v2; // rax

  v2 = this->m_phantom;
  this->m_wheelCollisionFilterInfo = filterInfo;
  if ( v2 )
    v2->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = filterInfo;
}

