// File Line: 38
// RVA: 0x452220
void __fastcall UFG::VehicleRaycastWheelCollide::operator delete(void *p, unsigned __int64 nbytes)
{
  void *v2; // rbx
  _QWORD **v3; // rax

  if ( p )
  {
    v2 = p;
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, void *, signed __int64))(*v3[11] + 16i64))(v3[11], v2, 200i64);
  }
}

// File Line: 40
// RVA: 0x44E470
void __fastcall UFG::VehicleRaycastWheelCollide::VehicleRaycastWheelCollide(UFG::VehicleRaycastWheelCollide *this)
{
  UFG::VehicleRaycastWheelCollide *v1; // rbx

  v1 = this;
  hkpVehicleRayCastWheelCollide::hkpVehicleRayCastWheelCollide((hkpVehicleRayCastWheelCollide *)&this->vfptr);
  v1->vfptr = (hkBaseObjectVtbl *)&UFG::VehicleRaycastWheelCollide::`vftable';
  *(_QWORD *)v1->mFrictionMultiplier = 4575657222473777152i64;
  *(_QWORD *)&v1->mFrictionMultiplier[2] = 4575657222473777152i64;
  *(_QWORD *)&v1->mSurfaceNormal[0].x = 0i64;
  *(_QWORD *)&v1->mSurfaceNormal[0].z = 0i64;
  v1->mSurfacePropertyHandleUid[0] = 0i64;
  v1->mObjectPropertyHandleUid[0] = 0i64;
  *(_QWORD *)&v1->mSurfaceNormal[1].y = 0i64;
  v1->mSurfacePropertyHandleUid[1] = 0i64;
  v1->mObjectPropertyHandleUid[1] = 0i64;
  *(_QWORD *)&v1->mSurfaceNormal[2].x = 0i64;
  *(_QWORD *)&v1->mSurfaceNormal[2].z = 0i64;
  v1->mSurfacePropertyHandleUid[2] = 0i64;
  v1->mObjectPropertyHandleUid[2] = 0i64;
  *(_QWORD *)&v1->mSurfaceNormal[3].y = 0i64;
  v1->mSurfacePropertyHandleUid[3] = 0i64;
  v1->mObjectPropertyHandleUid[3] = 0i64;
}

// File Line: 75
// RVA: 0x484840
void __fastcall UFG::VehicleRaycastWheelCollide::castSingleWheel(UFG::VehicleRaycastWheelCollide *this, hkpVehicleInstance::WheelInfo *wheelInfo, hkpWorldRayCastOutput *output)
{
  hkVector4f v3; // xmm0
  hkVector4f v4; // xmm1
  unsigned int v5; // eax
  UFG::VehicleRaycastWheelCollide *v6; // r14
  hkpAabbPhantom *v7; // rcx
  hkpVehicleInstance::WheelInfo *v8; // rdi
  hkpWorldRayCastOutput *v9; // r12
  __m128 v10; // xmm6
  __m128 v11; // xmm1
  hkpAabbPhantom *v12; // rax
  hkpWorld *v13; // r15
  __m128 *v14; // rbx
  signed __int64 v15; // rsi
  float v16; // xmm7_4
  hkVector4f v17; // xmm0
  unsigned int v18; // eax
  hkVector4f v19; // xmm1
  __m128 v20; // xmm6
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  hkpWorldRayCastInput v24; // [rsp+20h] [rbp-E0h]
  hkpWorldRayCastInput input; // [rsp+50h] [rbp-B0h]
  hkpWorldRayCastOutput outputa; // [rsp+80h] [rbp-80h]
  __int128 v27; // [rsp+E0h] [rbp-20h]
  __int128 v28; // [rsp+F0h] [rbp-10h]
  __int128 v29; // [rsp+100h] [rbp+0h]
  __int128 v30; // [rsp+110h] [rbp+10h]

  v3.m_quad = (__m128)wheelInfo->m_hardPointWs;
  v4.m_quad = (__m128)wheelInfo->m_rayEndPointWs;
  v5 = this->m_wheelCollisionFilterInfo;
  v6 = this;
  v7 = this->m_phantom;
  v8 = wheelInfo;
  input.m_filterInfo = v5;
  input.m_from = (hkVector4f)v3.m_quad;
  input.m_to = (hkVector4f)v4.m_quad;
  v9 = output;
  input.m_enableShapeCollectionFilter.m_bool = 1;
  input.m_userData = 0i64;
  hkpAabbPhantom::castRay(v7, &input, output);
  if ( v9->m_rootCollidable )
  {
    v10 = v9->m_normal.m_quad;
    v11 = _mm_mul_ps(v8->m_suspensionDirectionWs.m_quad, v9->m_normal.m_quad);
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                        (float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))
                      + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170))) & _xmm) < 0.70700002 )
    {
      v12 = v6->m_phantom;
      v27 = _xmm;
      v13 = v12->m_world;
      v14 = (__m128 *)&v27;
      v15 = 4i64;
      v28 = _xmm;
      v29 = _xmm;
      v30 = _xmm;
      v16 = *(float *)&FLOAT_1_0;
      do
      {
        v17.m_quad = (__m128)v8->m_hardPointWs;
        v18 = v6->m_wheelCollisionFilterInfo;
        v19.m_quad = _mm_add_ps(v8->m_rayEndPointWs.m_quad, *v14);
        v24.m_userData = 0i64;
        v24.m_from = (hkVector4f)v17.m_quad;
        v24.m_enableShapeCollectionFilter.m_bool = 1;
        v24.m_to = (hkVector4f)v19.m_quad;
        v24.m_filterInfo = v18;
        outputa.m_hitFraction = 1.0;
        outputa.m_extraInfo = -1;
        outputa.m_shapeKeyIndex = 0;
        outputa.m_shapeKeys[0] = -1;
        outputa.m_rootCollidable = 0i64;
        hkpWorld::castRay(v13, &v24, &outputa);
        if ( outputa.m_rootCollidable && outputa.m_rootCollidable->m_broadPhaseHandle.m_type == 1 )
        {
          if ( (hkpCollidable *)((char *)outputa.m_rootCollidable + outputa.m_rootCollidable->m_ownerOffset) )
          {
            v10 = _mm_add_ps(v10, outputa.m_normal.m_quad);
            v16 = v16 + 1.0;
          }
        }
        ++v14;
        --v15;
      }
      while ( v15 );
      v17.m_quad.m128_f32[0] = 1.0 / v16;
      v20 = _mm_mul_ps(v10, _mm_shuffle_ps(v17.m_quad, v17.m_quad, 0));
      v21 = _mm_mul_ps(v20, v20);
      v22 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
              _mm_shuffle_ps(v21, v21, 170));
      v23 = _mm_rsqrt_ps(v22);
      v9->m_normal.m_quad = _mm_mul_ps(
                              _mm_andnot_ps(
                                _mm_cmpleps(v22, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                                  _mm_mul_ps(*(__m128 *)_xmm, v23))),
                              v20);
    }
  }
}

// File Line: 140
// RVA: 0x4897A0
void __fastcall UFG::VehicleRaycastWheelCollide::wheelCollideCallback(UFG::VehicleRaycastWheelCollide *this, hkpVehicleInstance *vehicle, char wheelIndex, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo)
{
  __int64 v4; // r14
  signed int v5; // ebx
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *v6; // rsi
  unsigned __int64 v7; // rbp
  float v8; // xmm1_4
  float v9; // xmm2_4
  UFG::VehicleRaycastWheelCollide *v10; // rdi
  hkpRigidBody *v11; // r15
  unsigned __int64 v12; // rax
  unsigned int v13; // er8
  unsigned int *v14; // rax
  unsigned int v15; // edx
  UFG::BaseProperty *v16; // rax
  float v17; // eax
  float v18; // xmm0_4

  v4 = (unsigned __int8)wheelIndex;
  v5 = 0;
  v6 = cdInfo;
  this->mObjectPropertyHandleUid[v4] = 0i64;
  this->mSurfacePropertyHandleUid[v4] = 0i64;
  v7 = (unsigned __int8)wheelIndex;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  v10 = this;
  this->mSurfaceNormal[v7].x = UFG::qVector3::msZero.x;
  this->mSurfaceNormal[v7].y = v8;
  this->mSurfaceNormal[v7].z = v9;
  v11 = cdInfo->m_contactBody;
  if ( v11 )
  {
    v12 = UFG::PhysicsPropertyManager::GetObjectPropertiesHandleUid((hkpWorldObject *)&cdInfo->m_contactBody->vfptr);
    v13 = -1;
    v10->mObjectPropertyHandleUid[v4] = v12;
    v14 = v6->m_contactShapeKey;
    do
    {
      v15 = *v14;
      if ( *v14 == -1 )
        break;
      ++v5;
      ++v14;
      v13 = v15;
    }
    while ( v5 < 8 );
    if ( v13 != -1 )
    {
      v16 = UFG::GetBaseProperty(v11->m_collidable.m_shape, v13);
      if ( v16 )
      {
        v10->mSurfacePropertyHandleUid[v4] = v16->surfacePropertyHandleId;
        v10->mObjectPropertyHandleUid[v4] = v16->objectPropertyHandleId;
        if ( v16->surfacePropertyHandleId )
          v6->m_contactFriction = v16->tireFriction;
      }
    }
    v6->m_contactFriction = v10->mFrictionMultiplier[v4] * v6->m_contactFriction;
    v17 = v6->m_contactPoint.m_separatingNormal.m_quad.m128_f32[0];
    v18 = v6->m_contactPoint.m_separatingNormal.m_quad.m128_f32[2];
    v10->mSurfaceNormal[v7].y = v6->m_contactPoint.m_separatingNormal.m_quad.m128_f32[1];
    v10->mSurfaceNormal[v7].x = v17;
    v10->mSurfaceNormal[v7].z = v18;
  }
}

// File Line: 202
// RVA: 0x4521E0
void __fastcall UFG::VehicleLinearCastWheelCollide::operator delete(void *p, unsigned __int64 nbytes)
{
  void *v2; // rbx
  _QWORD **v3; // rax

  if ( p )
  {
    v2 = p;
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, void *, signed __int64))(*v3[11] + 16i64))(v3[11], v2, 216i64);
  }
}

// File Line: 204
// RVA: 0x44E2F0
void __fastcall UFG::VehicleLinearCastWheelCollide::VehicleLinearCastWheelCollide(UFG::VehicleLinearCastWheelCollide *this)
{
  UFG::VehicleLinearCastWheelCollide *v1; // rbx

  v1 = this;
  hkpVehicleLinearCastWheelCollide::hkpVehicleLinearCastWheelCollide((hkpVehicleLinearCastWheelCollide *)&this->vfptr);
  v1->vfptr = (hkBaseObjectVtbl *)&UFG::VehicleLinearCastWheelCollide::`vftable';
  *(_QWORD *)v1->mFrictionMultiplier = 4575657222473777152i64;
  *(_QWORD *)&v1->mFrictionMultiplier[2] = 4575657222473777152i64;
  *(_QWORD *)&v1->mSurfaceNormal[0].x = 0i64;
  *(_QWORD *)&v1->mSurfaceNormal[0].z = 0i64;
  v1->mSurfacePropertyHandleUid[0] = 0i64;
  v1->mObjectPropertyHandleUid[0] = 0i64;
  *(_QWORD *)&v1->mSurfaceNormal[1].y = 0i64;
  v1->mSurfacePropertyHandleUid[1] = 0i64;
  v1->mObjectPropertyHandleUid[1] = 0i64;
  *(_QWORD *)&v1->mSurfaceNormal[2].x = 0i64;
  *(_QWORD *)&v1->mSurfaceNormal[2].z = 0i64;
  v1->mSurfacePropertyHandleUid[2] = 0i64;
  v1->mObjectPropertyHandleUid[2] = 0i64;
  *(_QWORD *)&v1->mSurfaceNormal[3].y = 0i64;
  v1->mSurfacePropertyHandleUid[3] = 0i64;
  v1->mObjectPropertyHandleUid[3] = 0i64;
}

// File Line: 220
// RVA: 0x484480
hkBool *__fastcall UFG::VehicleLinearCastWheelCollide::castSingleWheel(UFG::VehicleLinearCastWheelCollide *this, hkBool *result, hkpVehicleInstance *vehicle, char wheelNum)
{
  hkpVehicleInstance *v4; // r13
  hkBool *v5; // r15
  UFG::VehicleLinearCastWheelCollide *v6; // r14
  signed __int64 v7; // rdi
  hkpVehicleLinearCastWheelCollide::WheelState *v8; // rbx
  unsigned __int64 v9; // rdx
  __m128 v10; // xmm6
  signed __int64 v11; // rdi
  __m128 v12; // xmm2
  float v13; // xmm7_4
  hkpWorld *v14; // r12
  __m128 *v15; // rbx
  signed __int64 v16; // rsi
  hkpVehicleInstance::WheelInfo *v17; // rax
  __m128 v18; // xmm0
  __m128 v19; // xmm6
  __m128 v20; // xmm4
  __m128 v21; // xmm4
  __m128 v22; // xmm0
  __m128 v23; // xmm6
  hkpLinearCastInput input; // [rsp+30h] [rbp-A8h]
  hkpCdPointCollector castCollector; // [rsp+50h] [rbp-88h]
  __m128 v27; // [rsp+60h] [rbp-78h]
  __m128 v28; // [rsp+70h] [rbp-68h]
  hkpCollidable toBeCast; // [rsp+88h] [rbp-50h]
  hkpWorldRayCastInput v30; // [rsp+F8h] [rbp+20h]
  __int64 v31; // [rsp+128h] [rbp+50h]
  hkpWorldRayCastOutput output; // [rsp+138h] [rbp+60h]
  __int128 v33; // [rsp+198h] [rbp+C0h]
  __int128 v34; // [rsp+1A8h] [rbp+D0h]
  __int128 v35; // [rsp+1B8h] [rbp+E0h]
  __int128 v36; // [rsp+1C8h] [rbp+F0h]
  hkBool *v37; // [rsp+240h] [rbp+168h]
  __m128 *retaddr; // [rsp+258h] [rbp+180h]

  v31 = -2i64;
  v4 = vehicle;
  v5 = result;
  v6 = this;
  v7 = (unsigned __int8)wheelNum;
  v8 = &this->m_wheelStates.m_data[(unsigned __int8)wheelNum];
  toBeCast.m_shape = v8->m_shape;
  toBeCast.m_motion = &v8->m_transform;
  toBeCast.m_parent = 0i64;
  toBeCast.m_shapeKey = -1;
  toBeCast.m_ownerOffset = 0;
  toBeCast.m_broadPhaseHandle.m_id = 0;
  *(_WORD *)&toBeCast.m_broadPhaseHandle.m_type = 32512;
  toBeCast.m_broadPhaseHandle.m_collisionFilterInfo = 0;
  toBeCast.m_broadPhaseHandle.m_objectQualityType = -1;
  hkpCollidable::BoundingVolumeData::BoundingVolumeData(&toBeCast.m_boundingVolumeData);
  toBeCast.m_allowedPenetrationDepth = FLOAT_N1_0;
  toBeCast.m_broadPhaseHandle.m_ownerOffset = (char *)&v30.m_from.m_quad.m128_u16[-36]
                                            - (char *)&toBeCast.m_broadPhaseHandle;
  toBeCast.m_forceCollideOntoPpu = 8;
  toBeCast.m_shapeSizeOnSpu = 0;
  toBeCast.m_broadPhaseHandle.m_collisionFilterInfo = v6->m_wheelCollisionFilterInfo;
  input.m_maxExtraPenetration = 0.00000011920929;
  input.m_startPointTolerance = 0.00000011920929;
  input.m_to = v8->m_to;
  input.m_maxExtraPenetration = v6->m_maxExtraPenetration;
  input.m_startPointTolerance = v6->m_startPointTolerance;
  castCollector.vfptr = (hkpCdPointCollectorVtbl *)&hkpClosestCdPointCollector::`vftable';
  *(_QWORD *)&castCollector.m_earlyOutDistance = 0i64;
  v28 = _mm_shuffle_ps(v28, _mm_unpackhi_ps(v28, (__m128)xmmword_141A712A0), 196);
  castCollector.m_earlyOutDistance = 3.40282e38;
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
    v12 = _mm_mul_ps(v4->m_wheelsInfo.m_data[v11].m_suspensionDirectionWs.m_quad, v10);
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                        COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170))
                      + (float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))) & _xmm) < 0.70700002 )
    {
      v13 = *(float *)&FLOAT_1_0;
      v33 = _xmm;
      v34 = _xmm;
      v35 = _xmm;
      v36 = _xmm;
      v14 = v8->m_phantom->m_world;
      v15 = (__m128 *)&v33;
      v16 = 4i64;
      do
      {
        v30.m_enableShapeCollectionFilter.m_bool = 0;
        v30.m_filterInfo = 0;
        v30.m_userData = 0i64;
        v17 = v4->m_wheelsInfo.m_data;
        v18 = v17[v11].m_hardPointWs.m_quad;
        v30.m_from = v17[v11].m_hardPointWs;
        v30.m_to.m_quad = _mm_add_ps(*v15, v17[v11].m_rayEndPointWs.m_quad);
        v30.m_enableShapeCollectionFilter.m_bool = 1;
        *(_QWORD *)&v30.m_filterInfo = v6->m_wheelCollisionFilterInfo;
        output.m_hitFraction = 1.0;
        output.m_extraInfo = -1;
        output.m_shapeKeyIndex = 0;
        output.m_shapeKeys[0] = -1;
        output.m_rootCollidable = 0i64;
        hkpWorld::castRay(v14, &v30, &output);
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
      v18.m128_f32[0] = 1.0 / v13;
      v19 = _mm_mul_ps(v10, _mm_shuffle_ps(v18, v18, 0));
      v20 = _mm_mul_ps(v19, v19);
      v21 = _mm_add_ps(
              _mm_shuffle_ps(v20, v20, 170),
              _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)));
      v22 = _mm_rsqrt_ps(v21);
      v23 = _mm_mul_ps(
              v19,
              _mm_andnot_ps(
                _mm_cmpleps(v21, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(*(__m128 *)_xmm, v22),
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)))));
      retaddr[1] = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, retaddr[1]), 196);
      v5 = v37;
    }
    v5->m_bool = 1;
    castCollector.vfptr = (hkpCdPointCollectorVtbl *)&hkpClosestCdPointCollector::`vftable';
  }
  else
  {
    v5->m_bool = 0;
    castCollector.vfptr = (hkpCdPointCollectorVtbl *)&hkpClosestCdPointCollector::`vftable';
  }
  return v5;
}

// File Line: 306
// RVA: 0x489670
void __fastcall UFG::VehicleLinearCastWheelCollide::wheelCollideCallback(UFG::VehicleLinearCastWheelCollide *this, hkpVehicleInstance *vehicle, char wheelIndex, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo)
{
  __int64 v4; // r14
  signed int v5; // ebx
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *v6; // rsi
  unsigned __int64 v7; // rbp
  float v8; // xmm1_4
  float v9; // xmm2_4
  UFG::VehicleLinearCastWheelCollide *v10; // rdi
  hkpRigidBody *v11; // r15
  unsigned __int64 v12; // rax
  unsigned int v13; // er8
  unsigned int *v14; // rax
  unsigned int v15; // edx
  UFG::BaseProperty *v16; // rax
  float v17; // eax
  float v18; // xmm0_4

  v4 = (unsigned __int8)wheelIndex;
  v5 = 0;
  v6 = cdInfo;
  this->mObjectPropertyHandleUid[v4] = 0i64;
  this->mSurfacePropertyHandleUid[v4] = 0i64;
  v7 = (unsigned __int8)wheelIndex;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  v10 = this;
  this->mSurfaceNormal[v7].x = UFG::qVector3::msZero.x;
  this->mSurfaceNormal[v7].y = v8;
  this->mSurfaceNormal[v7].z = v9;
  v11 = cdInfo->m_contactBody;
  if ( v11 )
  {
    v12 = UFG::PhysicsPropertyManager::GetObjectPropertiesHandleUid((hkpWorldObject *)&cdInfo->m_contactBody->vfptr);
    v13 = -1;
    v10->mObjectPropertyHandleUid[v4] = v12;
    v14 = v6->m_contactShapeKey;
    do
    {
      v15 = *v14;
      if ( *v14 == -1 )
        break;
      ++v5;
      ++v14;
      v13 = v15;
    }
    while ( v5 < 8 );
    if ( v13 != -1 )
    {
      v16 = UFG::GetBaseProperty(v11->m_collidable.m_shape, v13);
      if ( v16 )
      {
        v10->mSurfacePropertyHandleUid[v4] = v16->surfacePropertyHandleId;
        v10->mObjectPropertyHandleUid[v4] = v16->objectPropertyHandleId;
        if ( v16->surfacePropertyHandleId )
          v6->m_contactFriction = v16->tireFriction;
      }
    }
    v6->m_contactFriction = v10->mFrictionMultiplier[v4] * v6->m_contactFriction;
    v17 = v6->m_contactPoint.m_separatingNormal.m_quad.m128_f32[0];
    v18 = v6->m_contactPoint.m_separatingNormal.m_quad.m128_f32[2];
    v10->mSurfaceNormal[v7].y = v6->m_contactPoint.m_separatingNormal.m_quad.m128_f32[1];
    v10->mSurfaceNormal[v7].x = v17;
    v10->mSurfaceNormal[v7].z = v18;
  }
}

