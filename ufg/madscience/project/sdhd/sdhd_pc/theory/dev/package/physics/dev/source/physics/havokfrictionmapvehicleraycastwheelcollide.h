// File Line: 38
// RVA: 0x452220
void __fastcall UFG::VehicleRaycastWheelCollide::operator delete(void *p, unsigned __int64 nbytes)
{
  _QWORD **Value; // rax

  if ( p )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, void *, __int64))(*Value[11] + 16i64))(Value[11], p, 200i64);
  }
}

// File Line: 40
// RVA: 0x44E470
void __fastcall UFG::VehicleRaycastWheelCollide::VehicleRaycastWheelCollide(UFG::VehicleRaycastWheelCollide *this)
{
  hkpVehicleRayCastWheelCollide::hkpVehicleRayCastWheelCollide(this);
  this->vfptr = (hkBaseObjectVtbl *)&UFG::VehicleRaycastWheelCollide::`vftable;
  *(_QWORD *)this->mFrictionMultiplier = 0x3F8000003F800000i64;
  *(_QWORD *)&this->mFrictionMultiplier[2] = 0x3F8000003F800000i64;
  *(_QWORD *)&this->mSurfaceNormal[0].x = 0i64;
  *(_QWORD *)&this->mSurfaceNormal[0].z = 0i64;
  this->mSurfacePropertyHandleUid[0] = 0i64;
  this->mObjectPropertyHandleUid[0] = 0i64;
  *(_QWORD *)&this->mSurfaceNormal[1].y = 0i64;
  this->mSurfacePropertyHandleUid[1] = 0i64;
  this->mObjectPropertyHandleUid[1] = 0i64;
  *(_QWORD *)&this->mSurfaceNormal[2].x = 0i64;
  *(_QWORD *)&this->mSurfaceNormal[2].z = 0i64;
  this->mSurfacePropertyHandleUid[2] = 0i64;
  this->mObjectPropertyHandleUid[2] = 0i64;
  *(_QWORD *)&this->mSurfaceNormal[3].y = 0i64;
  this->mSurfacePropertyHandleUid[3] = 0i64;
  this->mObjectPropertyHandleUid[3] = 0i64;
}

// File Line: 75
// RVA: 0x484840
void __fastcall UFG::VehicleRaycastWheelCollide::castSingleWheel(
        UFG::VehicleRaycastWheelCollide *this,
        hkpVehicleInstance::WheelInfo *wheelInfo,
        hkpWorldRayCastOutput *output)
{
  hkVector4f v3; // xmm0
  hkVector4f v4; // xmm1
  unsigned int m_wheelCollisionFilterInfo; // eax
  hkpAabbPhantom *m_phantom; // rcx
  hkVector4f v10; // xmm6
  __m128 v11; // xmm1
  hkpAabbPhantom *v12; // rax
  hkpWorld *m_world; // r15
  __m128 *v14; // rbx
  __int64 v15; // rsi
  float v16; // xmm7_4
  __m128 m_quad; // xmm0
  unsigned int v18; // eax
  hkVector4f v19; // xmm1
  __m128 v20; // xmm6
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  hkpWorldRayCastInput v24; // [rsp+20h] [rbp-E0h] BYREF
  hkpWorldRayCastInput input; // [rsp+50h] [rbp-B0h] BYREF
  hkpWorldRayCastOutput outputa; // [rsp+80h] [rbp-80h] BYREF
  __int128 v27[4]; // [rsp+E0h] [rbp-20h] BYREF

  v3.m_quad = (__m128)wheelInfo->m_hardPointWs;
  v4.m_quad = (__m128)wheelInfo->m_rayEndPointWs;
  m_wheelCollisionFilterInfo = this->m_wheelCollisionFilterInfo;
  m_phantom = this->m_phantom;
  input.m_filterInfo = m_wheelCollisionFilterInfo;
  input.m_from = (hkVector4f)v3.m_quad;
  input.m_to = (hkVector4f)v4.m_quad;
  input.m_enableShapeCollectionFilter.m_bool = 1;
  input.m_userData = 0i64;
  hkpAabbPhantom::castRay(m_phantom, &input, output);
  if ( output->m_rootCollidable )
  {
    v10.m_quad = (__m128)output->m_normal;
    v11 = _mm_mul_ps(wheelInfo->m_suspensionDirectionWs.m_quad, output->m_normal.m_quad);
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                        (float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0] + _mm_shuffle_ps(v11, v11, 0).m128_f32[0])
                      + _mm_shuffle_ps(v11, v11, 170).m128_f32[0]) & _xmm) < 0.70700002 )
    {
      v12 = this->m_phantom;
      v27[0] = _xmm;
      m_world = v12->m_world;
      v14 = (__m128 *)v27;
      v15 = 4i64;
      v27[1] = _xmm;
      v27[2] = _xmm;
      v27[3] = _xmm;
      v16 = *(float *)&FLOAT_1_0;
      do
      {
        m_quad = wheelInfo->m_hardPointWs.m_quad;
        v18 = this->m_wheelCollisionFilterInfo;
        v19.m_quad = _mm_add_ps(wheelInfo->m_rayEndPointWs.m_quad, *v14);
        v24.m_userData = 0i64;
        v24.m_from.m_quad = m_quad;
        v24.m_enableShapeCollectionFilter.m_bool = 1;
        v24.m_to = (hkVector4f)v19.m_quad;
        v24.m_filterInfo = v18;
        outputa.m_hitFraction = 1.0;
        outputa.m_extraInfo = -1;
        outputa.m_shapeKeyIndex = 0;
        outputa.m_shapeKeys[0] = -1;
        outputa.m_rootCollidable = 0i64;
        hkpWorld::castRay(m_world, &v24, &outputa);
        if ( outputa.m_rootCollidable && outputa.m_rootCollidable->m_broadPhaseHandle.m_type == 1 )
        {
          if ( (hkpCollidable *)((char *)outputa.m_rootCollidable + outputa.m_rootCollidable->m_ownerOffset) )
          {
            v10.m_quad = _mm_add_ps(v10.m_quad, outputa.m_normal.m_quad);
            v16 = v16 + 1.0;
          }
        }
        ++v14;
        --v15;
      }
      while ( v15 );
      m_quad.m128_f32[0] = 1.0 / v16;
      v20 = _mm_mul_ps(v10.m_quad, _mm_shuffle_ps(m_quad, m_quad, 0));
      v21 = _mm_mul_ps(v20, v20);
      v22 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
              _mm_shuffle_ps(v21, v21, 170));
      v23 = _mm_rsqrt_ps(v22);
      output->m_normal.m_quad = _mm_mul_ps(
                                  _mm_andnot_ps(
                                    _mm_cmple_ps(v22, (__m128)0i64),
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                                      _mm_mul_ps(*(__m128 *)_xmm, v23))),
                                  v20);
    }
  }
}

// File Line: 140
// RVA: 0x4897A0
void __fastcall UFG::VehicleRaycastWheelCollide::wheelCollideCallback(
        UFG::VehicleRaycastWheelCollide *this,
        hkpVehicleInstance *vehicle,
        unsigned __int8 wheelIndex,
        hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo)
{
  __int64 v4; // r14
  int v5; // ebx
  __int64 v7; // rbp
  float y; // xmm1_4
  float z; // xmm2_4
  hkpRigidBody *m_contactBody; // r15
  unsigned __int64 ObjectPropertiesHandleUid; // rax
  int v13; // r8d
  unsigned int *m_contactShapeKey; // rax
  int v15; // edx
  UFG::BaseProperty *BaseProperty; // rax
  float v17; // xmm0_4

  v4 = wheelIndex;
  v5 = 0;
  this->mObjectPropertyHandleUid[wheelIndex] = 0i64;
  this->mSurfacePropertyHandleUid[wheelIndex] = 0i64;
  v7 = wheelIndex;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mSurfaceNormal[v7].x = UFG::qVector3::msZero.x;
  this->mSurfaceNormal[v7].y = y;
  this->mSurfaceNormal[v7].z = z;
  m_contactBody = cdInfo->m_contactBody;
  if ( m_contactBody )
  {
    ObjectPropertiesHandleUid = UFG::PhysicsPropertyManager::GetObjectPropertiesHandleUid(cdInfo->m_contactBody);
    v13 = -1;
    this->mObjectPropertyHandleUid[v4] = ObjectPropertiesHandleUid;
    m_contactShapeKey = cdInfo->m_contactShapeKey;
    do
    {
      v15 = *m_contactShapeKey;
      if ( *m_contactShapeKey == -1 )
        break;
      ++v5;
      ++m_contactShapeKey;
      v13 = v15;
    }
    while ( v5 < 8 );
    if ( v13 != -1 )
    {
      BaseProperty = UFG::GetBaseProperty(m_contactBody->m_collidable.m_shape, v13);
      if ( BaseProperty )
      {
        this->mSurfacePropertyHandleUid[v4] = BaseProperty->surfacePropertyHandleId;
        this->mObjectPropertyHandleUid[v4] = BaseProperty->objectPropertyHandleId;
        if ( BaseProperty->surfacePropertyHandleId )
          cdInfo->m_contactFriction = BaseProperty->tireFriction;
      }
    }
    cdInfo->m_contactFriction = this->mFrictionMultiplier[v4] * cdInfo->m_contactFriction;
    v17 = cdInfo->m_contactPoint.m_separatingNormal.m_quad.m128_f32[2];
    *(_QWORD *)&this->mSurfaceNormal[v7].x = cdInfo->m_contactPoint.m_separatingNormal.m_quad.m128_u64[0];
    this->mSurfaceNormal[v7].z = v17;
  }
}

// File Line: 202
// RVA: 0x4521E0
void __fastcall UFG::VehicleLinearCastWheelCollide::operator delete(void *p, unsigned __int64 nbytes)
{
  _QWORD **Value; // rax

  if ( p )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, void *, __int64))(*Value[11] + 16i64))(Value[11], p, 216i64);
  }
}

// File Line: 204
// RVA: 0x44E2F0
void __fastcall UFG::VehicleLinearCastWheelCollide::VehicleLinearCastWheelCollide(
        UFG::VehicleLinearCastWheelCollide *this)
{
  hkpVehicleLinearCastWheelCollide::hkpVehicleLinearCastWheelCollide(this);
  this->vfptr = (hkBaseObjectVtbl *)&UFG::VehicleLinearCastWheelCollide::`vftable;
  *(_QWORD *)this->mFrictionMultiplier = 0x3F8000003F800000i64;
  *(_QWORD *)&this->mFrictionMultiplier[2] = 0x3F8000003F800000i64;
  *(_QWORD *)&this->mSurfaceNormal[0].x = 0i64;
  *(_QWORD *)&this->mSurfaceNormal[0].z = 0i64;
  this->mSurfacePropertyHandleUid[0] = 0i64;
  this->mObjectPropertyHandleUid[0] = 0i64;
  *(_QWORD *)&this->mSurfaceNormal[1].y = 0i64;
  this->mSurfacePropertyHandleUid[1] = 0i64;
  this->mObjectPropertyHandleUid[1] = 0i64;
  *(_QWORD *)&this->mSurfaceNormal[2].x = 0i64;
  *(_QWORD *)&this->mSurfaceNormal[2].z = 0i64;
  this->mSurfacePropertyHandleUid[2] = 0i64;
  this->mObjectPropertyHandleUid[2] = 0i64;
  *(_QWORD *)&this->mSurfaceNormal[3].y = 0i64;
  this->mSurfacePropertyHandleUid[3] = 0i64;
  this->mObjectPropertyHandleUid[3] = 0i64;
}

// File Line: 220
// RVA: 0x484480
hkBool *__fastcall UFG::VehicleLinearCastWheelCollide::castSingleWheel(
        UFG::VehicleLinearCastWheelCollide *this,
        hkBool *result,
        hkpVehicleInstance *vehicle,
        unsigned __int8 wheelNum)
{
  unsigned __int64 v7; // rdi
  hkpVehicleLinearCastWheelCollide::WheelState *v8; // rbx
  unsigned __int64 v9; // rdx
  __m128 v10; // xmm6
  unsigned __int64 v11; // rdi
  __m128 v12; // xmm2
  float v13; // xmm7_4
  hkpWorld *m_world; // r12
  __m128 *v15; // rbx
  __int64 v16; // rsi
  hkpVehicleInstance::WheelInfo *m_data; // rax
  hkVector4f v18; // xmm0
  __m128 v19; // xmm6
  __m128 v20; // xmm4
  __m128 v21; // xmm4
  __m128 v22; // xmm0
  __m128 v23; // xmm6
  hkpLinearCastInput input; // [rsp+30h] [rbp-A8h] BYREF
  hkpCdPointCollector castCollector; // [rsp+50h] [rbp-88h] BYREF
  __m128 v27; // [rsp+60h] [rbp-78h]
  __m128 v28; // [rsp+70h] [rbp-68h]
  hkpCollidable toBeCast; // [rsp+88h] [rbp-50h] BYREF
  hkpWorldRayCastInput v30; // [rsp+F8h] [rbp+20h] BYREF
  __int64 v31; // [rsp+128h] [rbp+50h]
  hkpWorldRayCastOutput output; // [rsp+138h] [rbp+60h] BYREF
  __int128 v33[9]; // [rsp+198h] [rbp+C0h] BYREF
  hkBool *v34; // [rsp+240h] [rbp+168h]
  __m128 *retaddr; // [rsp+258h] [rbp+180h]

  v31 = -2i64;
  v7 = wheelNum;
  v8 = &this->m_wheelStates.m_data[wheelNum];
  toBeCast.m_shape = v8->m_shape;
  toBeCast.m_motion = &v8->m_transform;
  toBeCast.m_parent = 0i64;
  toBeCast.m_shapeKey = -1;
  toBeCast.m_ownerOffset = 0;
  toBeCast.m_broadPhaseHandle.m_id = 0;
  toBeCast.m_broadPhaseHandle.m_type = 0;
  toBeCast.m_broadPhaseHandle.m_collisionFilterInfo = 0;
  toBeCast.m_broadPhaseHandle.m_objectQualityType = -1;
  hkpCollidable::BoundingVolumeData::BoundingVolumeData(&toBeCast.m_boundingVolumeData);
  toBeCast.m_allowedPenetrationDepth = FLOAT_N1_0;
  toBeCast.m_broadPhaseHandle.m_ownerOffset = (unsigned __int8)&v30.m_from.m_quad.m128_i8[8]
                                            - 80
                                            - (unsigned __int8)&toBeCast.m_broadPhaseHandle;
  toBeCast.m_forceCollideOntoPpu = 8;
  toBeCast.m_shapeSizeOnSpu = 0;
  toBeCast.m_broadPhaseHandle.m_collisionFilterInfo = this->m_wheelCollisionFilterInfo;
  input.m_maxExtraPenetration = 0.00000011920929;
  input.m_startPointTolerance = 0.00000011920929;
  input.m_to = v8->m_to;
  input.m_maxExtraPenetration = this->m_maxExtraPenetration;
  input.m_startPointTolerance = this->m_startPointTolerance;
  castCollector.vfptr = (hkpCdPointCollectorVtbl *)&hkpClosestCdPointCollector::`vftable;
  v28 = _mm_shuffle_ps(v28, _mm_unpackhi_ps(v28, (__m128)xmmword_141A712A0), 196);
  *(_QWORD *)&castCollector.m_earlyOutDistance = 2139095022i64;
  hkpAabbPhantom::linearCast(v8->m_phantom, &toBeCast, &input, &castCollector, 0i64);
  v9 = *(_QWORD *)&castCollector.m_earlyOutDistance;
  if ( *(_QWORD *)&castCollector.m_earlyOutDistance )
  {
    *retaddr = v27;
    retaddr[1] = v28;
    retaddr[2].m128_u64[0] = v9;
    retaddr[2].m128_i32[2] = v27.m128_i32[0];
    retaddr[3].m128_u64[0] = v27.m128_u64[1];
    retaddr[3].m128_i32[2] = v28.m128_i32[0];
    v10 = retaddr[1];
    v11 = v7;
    v12 = _mm_mul_ps(vehicle->m_wheelsInfo.m_data[v11].m_suspensionDirectionWs.m_quad, v10);
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                        _mm_shuffle_ps(v12, v12, 170).m128_f32[0]
                      + (float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0] + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])) & _xmm) < 0.70700002 )
    {
      v13 = *(float *)&FLOAT_1_0;
      v33[0] = _xmm;
      v33[1] = _xmm;
      v33[2] = _xmm;
      v33[3] = _xmm;
      m_world = v8->m_phantom->m_world;
      v15 = (__m128 *)v33;
      v16 = 4i64;
      do
      {
        v30.m_enableShapeCollectionFilter.m_bool = 0;
        v30.m_filterInfo = 0;
        v30.m_userData = 0i64;
        m_data = vehicle->m_wheelsInfo.m_data;
        v18.m_quad = (__m128)m_data[v11].m_hardPointWs;
        v30.m_from = (hkVector4f)v18.m_quad;
        v30.m_to.m_quad = _mm_add_ps(*v15, m_data[v11].m_rayEndPointWs.m_quad);
        v30.m_enableShapeCollectionFilter.m_bool = 1;
        v30.m_filterInfo = this->m_wheelCollisionFilterInfo;
        output.m_hitFraction = 1.0;
        output.m_extraInfo = -1;
        output.m_shapeKeyIndex = 0;
        output.m_shapeKeys[0] = -1;
        output.m_rootCollidable = 0i64;
        hkpWorld::castRay(m_world, &v30, &output);
        if ( output.m_rootCollidable
          && output.m_rootCollidable->m_broadPhaseHandle.m_type == 1
          && (hkpCollidable *)((char *)output.m_rootCollidable + output.m_rootCollidable->m_ownerOffset) )
        {
          v13 = v13 + 1.0;
          v10 = _mm_add_ps(v10, output.m_normal.m_quad);
        }
        ++v15;
        --v16;
      }
      while ( v16 );
      v18.m_quad.m128_f32[0] = 1.0 / v13;
      v19 = _mm_mul_ps(v10, _mm_shuffle_ps(v18.m_quad, v18.m_quad, 0));
      v20 = _mm_mul_ps(v19, v19);
      v21 = _mm_add_ps(
              _mm_shuffle_ps(v20, v20, 170),
              _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)));
      v22 = _mm_rsqrt_ps(v21);
      v23 = _mm_mul_ps(
              v19,
              _mm_andnot_ps(
                _mm_cmple_ps(v21, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(*(__m128 *)_xmm, v22),
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)))));
      retaddr[1] = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, retaddr[1]), 196);
      result = v34;
    }
    result->m_bool = 1;
    castCollector.vfptr = (hkpCdPointCollectorVtbl *)&hkpClosestCdPointCollector::`vftable;
  }
  else
  {
    result->m_bool = 0;
    castCollector.vfptr = (hkpCdPointCollectorVtbl *)&hkpClosestCdPointCollector::`vftable;
  }
  return result;
}

// File Line: 306
// RVA: 0x489670
void __fastcall UFG::VehicleLinearCastWheelCollide::wheelCollideCallback(
        UFG::VehicleLinearCastWheelCollide *this,
        hkpVehicleInstance *vehicle,
        unsigned __int8 wheelIndex,
        hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo)
{
  __int64 v4; // r14
  int v5; // ebx
  __int64 v7; // rbp
  float y; // xmm1_4
  float z; // xmm2_4
  hkpRigidBody *m_contactBody; // r15
  unsigned __int64 ObjectPropertiesHandleUid; // rax
  int v13; // r8d
  unsigned int *m_contactShapeKey; // rax
  int v15; // edx
  UFG::BaseProperty *BaseProperty; // rax
  float v17; // xmm0_4

  v4 = wheelIndex;
  v5 = 0;
  this->mObjectPropertyHandleUid[wheelIndex] = 0i64;
  this->mSurfacePropertyHandleUid[wheelIndex] = 0i64;
  v7 = wheelIndex;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mSurfaceNormal[v7].x = UFG::qVector3::msZero.x;
  this->mSurfaceNormal[v7].y = y;
  this->mSurfaceNormal[v7].z = z;
  m_contactBody = cdInfo->m_contactBody;
  if ( m_contactBody )
  {
    ObjectPropertiesHandleUid = UFG::PhysicsPropertyManager::GetObjectPropertiesHandleUid(cdInfo->m_contactBody);
    v13 = -1;
    this->mObjectPropertyHandleUid[v4] = ObjectPropertiesHandleUid;
    m_contactShapeKey = cdInfo->m_contactShapeKey;
    do
    {
      v15 = *m_contactShapeKey;
      if ( *m_contactShapeKey == -1 )
        break;
      ++v5;
      ++m_contactShapeKey;
      v13 = v15;
    }
    while ( v5 < 8 );
    if ( v13 != -1 )
    {
      BaseProperty = UFG::GetBaseProperty(m_contactBody->m_collidable.m_shape, v13);
      if ( BaseProperty )
      {
        this->mSurfacePropertyHandleUid[v4] = BaseProperty->surfacePropertyHandleId;
        this->mObjectPropertyHandleUid[v4] = BaseProperty->objectPropertyHandleId;
        if ( BaseProperty->surfacePropertyHandleId )
          cdInfo->m_contactFriction = BaseProperty->tireFriction;
      }
    }
    cdInfo->m_contactFriction = this->mFrictionMultiplier[v4] * cdInfo->m_contactFriction;
    v17 = cdInfo->m_contactPoint.m_separatingNormal.m_quad.m128_f32[2];
    *(_QWORD *)&this->mSurfaceNormal[v7].x = cdInfo->m_contactPoint.m_separatingNormal.m_quad.m128_u64[0];
    this->mSurfaceNormal[v7].z = v17;
  }
}

