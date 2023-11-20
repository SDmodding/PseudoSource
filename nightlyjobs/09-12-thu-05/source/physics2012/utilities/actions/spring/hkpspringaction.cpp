// File Line: 19
// RVA: 0xE1A170
void __fastcall hkpSpringAction::hkpSpringAction(hkpSpringAction *this, hkpRigidBody *entityA, hkpRigidBody *entityB, unsigned __int64 userData)
{
  hkpSpringAction *v4; // rbx

  v4 = this;
  hkpBinaryAction::hkpBinaryAction(
    (hkpBinaryAction *)&this->vfptr,
    (hkpEntity *)&entityA->vfptr,
    (hkpEntity *)&entityB->vfptr,
    userData);
  v4->vfptr = (hkBaseObjectVtbl *)&hkpSpringAction::`vftable;
  v4->m_restLength = 1.0;
  v4->m_strength = 1000.0;
  v4->m_damping = 0.1;
  *(_WORD *)&v4->m_onCompression.m_bool = 257;
}

// File Line: 23
// RVA: 0xE1A500
void __fastcall hkpSpringAction::setPositionsInWorldSpace(hkpSpringAction *this, hkVector4f *pivotA, hkVector4f *pivotB)
{
  hkpEntity *v3; // rbx
  hkVector4f *v4; // rdi
  hkVector4f *v5; // rsi
  hkVector4f *v6; // rbp
  __m128 v7; // xmm1
  __m128 v8; // xmm1
  __m128 v9; // xmm4
  __m128 v10; // xmm1

  v3 = this->m_entityB;
  v4 = pivotA;
  v5 = pivotB;
  v6 = (hkVector4f *)this;
  hkVector4f::setTransformedInversePos(
    &this->m_positionAinA,
    &this->m_entityA->m_motion.m_motionState.m_transform,
    pivotA);
  hkVector4f::setTransformedInversePos(v6 + 6, &v3->m_motion.m_motionState.m_transform, v5);
  v7 = _mm_sub_ps(v4->m_quad, v5->m_quad);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  v6[7].m_quad.m128_i32[0] = (unsigned __int128)_mm_andnot_ps(
                                                  _mm_cmpleps(v9, (__m128)0i64),
                                                  _mm_mul_ps(
                                                    _mm_mul_ps(
                                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                                                      _mm_mul_ps(*(__m128 *)_xmm, v10)),
                                                    v9));
}

// File Line: 36
// RVA: 0xE1A5C0
void __fastcall hkpSpringAction::setPositionsInBodySpace(hkpSpringAction *this, hkVector4f *pivotA, hkVector4f *pivotB)
{
  hkpEntity *v3; // rbx
  hkVector4f *v4; // rdi
  __m128 v5; // xmm1
  hkVector4f *v6; // r8
  hkpSpringAction *v7; // rsi
  hkTransformf *v8; // rdx
  __m128 v9; // xmm1
  __m128 v10; // xmm1
  __m128 v11; // xmm4
  __m128 v12; // xmm1
  hkVector4f v13; // [rsp+20h] [rbp-28h]
  hkVector4f v14; // [rsp+30h] [rbp-18h]

  v3 = this->m_entityB;
  v4 = pivotB;
  this->m_positionAinA = (hkVector4f)pivotA->m_quad;
  v5 = pivotB->m_quad;
  v6 = pivotA;
  v7 = this;
  v8 = &this->m_entityA->m_motion.m_motionState.m_transform;
  this->m_positionBinB.m_quad = v5;
  hkVector4f::setTransformedPos(&v13, v8, v6);
  hkVector4f::setTransformedPos(&v14, &v3->m_motion.m_motionState.m_transform, v4);
  v9 = _mm_sub_ps(v13.m_quad, v14.m_quad);
  v10 = _mm_mul_ps(v9, v9);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_rsqrt_ps(v11);
  LODWORD(v7->m_restLength) = (unsigned __int128)_mm_andnot_ps(
                                                   _mm_cmpleps(v11, (__m128)0i64),
                                                   _mm_mul_ps(
                                                     _mm_mul_ps(
                                                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
                                                       _mm_mul_ps(*(__m128 *)_xmm, v12)),
                                                     v11));
}

// File Line: 56
// RVA: 0xE1A270
void __fastcall hkpSpringAction::applyAction(hkpSpringAction *this, hkStepInfo *stepInfo)
{
  hkpEntity *v2; // rbp
  hkpEntity *v3; // r14
  hkStepInfo *v4; // r15
  hkVector4f *v5; // rbx
  __m128 v6; // xmm8
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm4
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm8
  __m128 v14; // xmm5
  __m128 v15; // xmm6
  __m128 v16; // xmm2
  __m128 v17; // xmm5
  __m128 v18; // xmm5
  __m128 v19; // xmm7
  __int128 v20; // xmm6
  __int64 v21; // rdx
  __int128 v22; // xmm6
  __int64 v23; // rdx
  hkVector4f v24; // [rsp+20h] [rbp-78h]
  hkVector4f v25; // [rsp+30h] [rbp-68h]

  v2 = this->m_entityA;
  v3 = this->m_entityB;
  v4 = stepInfo;
  v5 = (hkVector4f *)this;
  hkVector4f::setTransformedPos(&v25, &v2->m_motion.m_motionState.m_transform, &this->m_positionAinA);
  hkVector4f::setTransformedPos(&v24, &v3->m_motion.m_motionState.m_transform, v5 + 6);
  v6 = _mm_sub_ps(v24.m_quad, v25.m_quad);
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  v10 = _mm_andnot_ps(
          _mm_cmpleps(v8, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)), _mm_mul_ps(*(__m128 *)_xmm, v9)),
            v8));
  if ( v10.m128_f32[0] >= COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0)) )
  {
    v11 = _mm_rcp_ps(v10);
    v12 = _mm_shuffle_ps((__m128)v5[7].m_quad.m128_u32[0], (__m128)v5[7].m_quad.m128_u32[0], 0);
    v13 = _mm_mul_ps(v6, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v11, v10)), v11));
    if ( (v5[7].m_quad.m128_i8[12] || v10.m128_f32[0] >= v12.m128_f32[0])
      && (v5[7].m_quad.m128_i8[13] || v10.m128_f32[0] <= v12.m128_f32[0]) )
    {
      v14 = _mm_sub_ps(v24.m_quad, v3->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
      v15 = _mm_sub_ps(v25.m_quad, v2->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
      v16 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v2->m_motion.m_angularVelocity.m_quad),
              _mm_mul_ps(
                _mm_shuffle_ps(v2->m_motion.m_angularVelocity.m_quad, v2->m_motion.m_angularVelocity.m_quad, 201),
                v15));
      v17 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v3->m_motion.m_angularVelocity.m_quad),
              _mm_mul_ps(
                _mm_shuffle_ps(v3->m_motion.m_angularVelocity.m_quad, v3->m_motion.m_angularVelocity.m_quad, 201),
                v14));
      v18 = _mm_mul_ps(
              _mm_sub_ps(
                _mm_add_ps(_mm_shuffle_ps(v17, v17, 201), v3->m_motion.m_linearVelocity.m_quad),
                _mm_add_ps(_mm_shuffle_ps(v16, v16, 201), v2->m_motion.m_linearVelocity.m_quad)),
              v13);
      v19 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                  _mm_shuffle_ps(v18, v18, 170)),
                _mm_shuffle_ps((__m128)v5[7].m_quad.m128_u32[2], (__m128)v5[7].m_quad.m128_u32[2], 0)),
              _mm_mul_ps(
                _mm_shuffle_ps((__m128)v5[7].m_quad.m128_u32[1], (__m128)v5[7].m_quad.m128_u32[1], 0),
                _mm_sub_ps(v10, v12)));
      v5[4].m_quad = _mm_mul_ps(_mm_sub_ps((__m128)0i64, v19), v13);
      v20 = LODWORD(v4->m_deltaTime.m_storage);
      hkpEntity::activate(v3);
      ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *, hkVector4f *))v3->m_motion.vfptr[12].__first_virtual_table_function__)(
        &v3->m_motion,
        v21,
        &v5[4],
        &v24);
      v5[4].m_quad = _mm_mul_ps(v13, v19);
      v22 = LODWORD(v4->m_deltaTime.m_storage);
      hkpEntity::activate(v2);
      ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *, hkVector4f *))v2->m_motion.vfptr[12].__first_virtual_table_function__)(
        &v2->m_motion,
        v23,
        &v5[4],
        &v25);
    }
  }
}

// File Line: 112
// RVA: 0xE1A1C0
hkVector4f *__fastcall hkpSpringAction::clone(hkpSpringAction *this, hkArray<hkpEntity *,hkContainerHeapAllocator> *newEntities, hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  hkpRigidBody ***v3; // rdi
  hkpSpringAction *v4; // rbx
  _QWORD **v6; // rax
  hkpSpringAction *v7; // rax
  hkVector4f *v8; // rax
  hkVector4f *v9; // rcx

  v3 = (hkpRigidBody ***)newEntities;
  v4 = this;
  if ( newEntities->m_size != 2 || newPhantoms->m_size )
    return 0i64;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkpSpringAction *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 128i64);
  if ( v7 )
  {
    hkpSpringAction::hkpSpringAction(v7, **v3, (*v3)[1], v4->m_userData);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v9[5] = v4->m_positionAinA;
  v9[6] = v4->m_positionBinB;
  v9[7].m_quad.m128_i32[0] = LODWORD(v4->m_restLength);
  v9[7].m_quad.m128_i32[1] = LODWORD(v4->m_strength);
  v9[7].m_quad.m128_i32[2] = LODWORD(v4->m_damping);
  v9[7].m_quad.m128_i8[12] = v4->m_onCompression.m_bool;
  v9[7].m_quad.m128_i8[13] = v4->m_onExtension.m_bool;
  return v9;
}

