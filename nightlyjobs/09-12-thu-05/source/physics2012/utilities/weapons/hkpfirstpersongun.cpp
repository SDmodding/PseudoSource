// File Line: 22
// RVA: 0xE14070
void __fastcall hkpFirstPersonGun::hkpFirstPersonGun(hkpFirstPersonGun *this)
{
  hkpFirstPersonGun *v1; // rbx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpFirstPersonGun::`vftable';
  this->m_type.m_storage = 0;
  hkStringPtr::hkStringPtr(&this->m_name, &customWorldMapCaption);
  v1->m_keyboardKey.m_storage = 113;
  v1->m_listeners.m_data = 0i64;
  v1->m_listeners.m_size = 0;
  v1->m_listeners.m_capacityAndFlags = 2147483648;
}

// File Line: 27
// RVA: 0xE140E0
const char *__fastcall hkpFirstPersonGun::getName(hkpFirstPersonGun *this)
{
  return (const char *)((_QWORD)this->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
}

// File Line: 32
// RVA: 0xE140D0
void __fastcall hkpFirstPersonGun::quitGun(hkpFirstPersonGun *this, hkpWorld *world)
{
  this->vfptr[4].__vecDelDtor((hkBaseObject *)this, (unsigned int)world);
}

// File Line: 37
// RVA: 0xE140F0
hkResult *__fastcall hkpFirstPersonGun::sweepSphere(hkResult *result, hkpWorld *world, hkVector4f *sweepStart, float radius, hkVector4f *sweepEnd, hkpFirstPersonGun::SweepSphereOut *out)
{
  hkResult *v6; // rbx
  hkVector4f *v7; // rsi
  hkpWorld *v8; // r14
  _QWORD **v9; // rax
  hkpSphereShape *v10; // rax
  hkpShape *v11; // rax
  hkpShape *v12; // rdi
  __int128 v13; // xmm1
  char v14; // sp
  char v15; // cl
  __m128 v16; // xmm0
  hkVector4f v17; // xmm1
  __int64 v18; // rdx
  __int64 v19; // rax
  hkpCollidable collA; // [rsp+30h] [rbp-D0h]
  hkpLinearCastInput input; // [rsp+A0h] [rbp-60h]
  hkpCdPointCollector castCollector; // [rsp+C0h] [rbp-40h]
  hkVector4f v24; // [rsp+D0h] [rbp-30h]
  __m128 v25; // [rsp+E0h] [rbp-20h]
  __int64 v26; // [rsp+F0h] [rbp-10h]
  __int64 v27; // [rsp+100h] [rbp+0h]
  unsigned int v28; // [rsp+108h] [rbp+8h]
  __m128 v29; // [rsp+120h] [rbp+20h]
  __m128 v30; // [rsp+130h] [rbp+30h]
  __m128 v31; // [rsp+140h] [rbp+40h]
  __int128 v32; // [rsp+150h] [rbp+50h]

  v6 = result;
  v7 = sweepStart;
  v8 = world;
  v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkpSphereShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v9[11] + 8i64))(v9[11], 56i64);
  if ( v10 )
  {
    hkpSphereShape::hkpSphereShape(v10, radius);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  collA.m_shape = v12;
  collA.m_parent = 0i64;
  v29 = transform.m_quad;
  v30 = direction.m_quad;
  collA.m_motion = &v29;
  collA.m_shapeKey = -1;
  collA.m_ownerOffset = 0;
  v13 = (__int128)v7->m_quad;
  v31 = stru_141A71280.m_quad;
  collA.m_broadPhaseHandle.m_id = 0;
  *(_WORD *)&collA.m_broadPhaseHandle.m_type = 32512;
  collA.m_broadPhaseHandle.m_collisionFilterInfo = 0;
  collA.m_broadPhaseHandle.m_objectQualityType = -1;
  v32 = v13;
  hkpCollidable::BoundingVolumeData::BoundingVolumeData(&collA.m_boundingVolumeData);
  v15 = v14 + 84;
  collA.m_allowedPenetrationDepth = FLOAT_N1_0;
  castCollector.m_earlyOutDistance = FLOAT_3_40282e38;
  v16 = sweepEnd->m_quad;
  v25 = _mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, (__m128)xmmword_141A712A0), 196);
  input.m_to.m_quad = v16;
  collA.m_broadPhaseHandle.m_ownerOffset = v14 + 48 - v15;
  collA.m_forceCollideOntoPpu = 8;
  collA.m_shapeSizeOnSpu = 0;
  v26 = 0i64;
  input.m_maxExtraPenetration = 0.00000011920929;
  castCollector.vfptr = (hkpCdPointCollectorVtbl *)&hkpClosestCdPointCollector::`vftable';
  input.m_startPointTolerance = 0.00000011920929;
  hkpWorld::linearCast(v8, &collA, &input, &castCollector, 0i64);
  hkReferencedObject::removeReference((hkReferencedObject *)&v12->vfptr);
  if ( v26 )
  {
    v17.m_quad = v25;
    v18 = v27;
    out->m_contactPoint.m_position = (hkVector4f)v24.m_quad;
    out->m_contactPoint.m_separatingNormal = (hkVector4f)v17.m_quad;
    if ( *(_BYTE *)(v18 + 40) == 1 )
    {
      v19 = *(char *)(v18 + 32);
      v6->m_enum = 0;
      out->m_body = (hkpRigidBody *)(v18 + v19);
    }
    else
    {
      v6->m_enum = 0;
      out->m_body = 0i64;
    }
    out->m_shapeKey = v28;
  }
  else
  {
    v6->m_enum = 1;
    out->m_body = 0i64;
    out->m_contactPoint.m_position = (hkVector4f)sweepEnd->m_quad;
    out->m_shapeKey = -1;
    out->m_contactPoint.m_separatingNormal = (hkVector4f)aabbOut.m_quad;
  }
  return v6;
}

// File Line: 76
// RVA: 0xE14300
void __fastcall hkpFirstPersonGun::calcVelocityToTarget(hkVector4f *position, hkVector4f *target, hkVector4f *gravity, float speedR, hkVector4f *velocity)
{
  hkVector4f v5; // xmm6
  __m128 v6; // xmm7
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm2
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm8
  __m128 v17; // xmm1
  __m128 v18; // xmm1

  v5.m_quad = _mm_sub_ps(target->m_quad, position->m_quad);
  v6 = _mm_shuffle_ps((__m128)LODWORD(speedR), (__m128)LODWORD(speedR), 0);
  v7 = _mm_mul_ps(v5.m_quad, v5.m_quad);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  v10 = _mm_andnot_ps(
          _mm_cmpleps(v8, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)), _mm_mul_ps(*(__m128 *)_xmm, v9)),
            v8));
  if ( v10.m128_f32[0] <= 0.00000011920929 )
  {
    *velocity = (hkVector4f)v5.m_quad;
  }
  else
  {
    v11 = _mm_rcp_ps(v6);
    v12 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)0i64, _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v6, v11)), v11), v10)),
              (__m128)xmmword_141A711B0),
            gravity->m_quad);
    v13 = _mm_mul_ps(v12, v12);
    v14 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170));
    v15 = _mm_rsqrt_ps(v14);
    v16 = _mm_andnot_ps(
            _mm_cmpleps(v14, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
                _mm_mul_ps(*(__m128 *)_xmm, v15)),
              v14));
    if ( v16.m128_f32[0] > v6.m128_f32[0] )
    {
      v17 = _mm_rcp_ps(v16);
      v12 = _mm_mul_ps(v12, _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v17, v16)), v17), v6));
    }
    v18 = _mm_rcp_ps(v10);
    velocity->m_quad = _mm_add_ps(
                         _mm_mul_ps(
                           _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, v10)), v18), v6),
                           v5.m_quad),
                         v12);
  }
}

