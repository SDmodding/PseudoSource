// File Line: 19
// RVA: 0xE1A170
void __fastcall hkpSpringAction::hkpSpringAction(
        hkpSpringAction *this,
        hkpRigidBody *entityA,
        hkpRigidBody *entityB,
        unsigned __int64 userData)
{
  hkpBinaryAction::hkpBinaryAction(this, entityA, entityB, userData);
  this->vfptr = (hkBaseObjectVtbl *)&hkpSpringAction::`vftable;
  this->m_restLength = 1.0;
  this->m_strength = 1000.0;
  this->m_damping = 0.1;
  *(_WORD *)&this->m_onCompression.m_bool = 257;
}

// File Line: 23
// RVA: 0xE1A500
void __fastcall hkpSpringAction::setPositionsInWorldSpace(
        hkpSpringAction *this,
        hkVector4f *pivotA,
        hkVector4f *pivotB)
{
  hkpEntity *m_entityB; // rbx
  __m128 v7; // xmm1
  __m128 v8; // xmm1
  __m128 v9; // xmm4
  __m128 v10; // xmm1

  m_entityB = this->m_entityB;
  hkVector4f::setTransformedInversePos(
    &this->m_positionAinA,
    &this->m_entityA->m_motion.m_motionState.m_transform,
    pivotA);
  hkVector4f::setTransformedInversePos(&this->m_positionBinB, &m_entityB->m_motion.m_motionState.m_transform, pivotB);
  v7 = _mm_sub_ps(pivotA->m_quad, pivotB->m_quad);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  LODWORD(this->m_restLength) = _mm_andnot_ps(
                                  _mm_cmple_ps(v9, (__m128)0i64),
                                  _mm_mul_ps(
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                                      _mm_mul_ps(*(__m128 *)_xmm, v10)),
                                    v9)).m128_u32[0];
}

// File Line: 36
// RVA: 0xE1A5C0
void __fastcall hkpSpringAction::setPositionsInBodySpace(hkpSpringAction *this, hkVector4f *pivotA, hkVector4f *pivotB)
{
  hkpEntity *m_entityB; // rbx
  __m128 m_quad; // xmm1
  hkMotionState *p_m_motionState; // rdx
  __m128 v9; // xmm1
  __m128 v10; // xmm1
  __m128 v11; // xmm4
  __m128 v12; // xmm1
  hkVector4f v13; // [rsp+20h] [rbp-28h] BYREF
  hkVector4f v14; // [rsp+30h] [rbp-18h] BYREF

  m_entityB = this->m_entityB;
  this->m_positionAinA = (hkVector4f)pivotA->m_quad;
  m_quad = pivotB->m_quad;
  p_m_motionState = &this->m_entityA->m_motion.m_motionState;
  this->m_positionBinB.m_quad = m_quad;
  hkVector4f::setTransformedPos(&v13, &p_m_motionState->m_transform, pivotA);
  hkVector4f::setTransformedPos(&v14, &m_entityB->m_motion.m_motionState.m_transform, pivotB);
  v9 = _mm_sub_ps(v13.m_quad, v14.m_quad);
  v10 = _mm_mul_ps(v9, v9);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_rsqrt_ps(v11);
  LODWORD(this->m_restLength) = _mm_andnot_ps(
                                  _mm_cmple_ps(v11, (__m128)0i64),
                                  _mm_mul_ps(
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
                                      _mm_mul_ps(*(__m128 *)_xmm, v12)),
                                    v11)).m128_u32[0];
}

// File Line: 56
// RVA: 0xE1A270
void __fastcall hkpSpringAction::applyAction(hkpSpringAction *this, hkStepInfo *stepInfo)
{
  hkpEntity *m_entityA; // rbp
  hkpEntity *m_entityB; // r14
  __m128 v5; // xmm8
  __m128 v6; // xmm1
  __m128 v7; // xmm3
  __m128 v8; // xmm1
  __m128 v9; // xmm4
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  __m128 v12; // xmm8
  __m128 v13; // xmm5
  __m128 v14; // xmm6
  __m128 v15; // xmm2
  __m128 v16; // xmm5
  __m128 v17; // xmm5
  __m128 v18; // xmm7
  __int64 v19; // rdx
  __int64 v20; // rdx
  hkVector4f v21; // [rsp+20h] [rbp-78h] BYREF
  hkVector4f v22; // [rsp+30h] [rbp-68h] BYREF

  m_entityA = this->m_entityA;
  m_entityB = this->m_entityB;
  hkVector4f::setTransformedPos(&v22, &m_entityA->m_motion.m_motionState.m_transform, &this->m_positionAinA);
  hkVector4f::setTransformedPos(&v21, &m_entityB->m_motion.m_motionState.m_transform, &this->m_positionBinB);
  v5 = _mm_sub_ps(v21.m_quad, v22.m_quad);
  v6 = _mm_mul_ps(v5, v5);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v8 = _mm_rsqrt_ps(v7);
  v9 = _mm_andnot_ps(
         _mm_cmple_ps(v7, (__m128)0i64),
         _mm_mul_ps(
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)), _mm_mul_ps(*(__m128 *)_xmm, v8)),
           v7));
  if ( v9.m128_f32[0] >= _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0).m128_f32[0] )
  {
    v10 = _mm_rcp_ps(v9);
    v11 = _mm_shuffle_ps((__m128)LODWORD(this->m_restLength), (__m128)LODWORD(this->m_restLength), 0);
    v12 = _mm_mul_ps(v5, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v10, v9)), v10));
    if ( (this->m_onCompression.m_bool || v9.m128_f32[0] >= v11.m128_f32[0])
      && (this->m_onExtension.m_bool || v9.m128_f32[0] <= v11.m128_f32[0]) )
    {
      v13 = _mm_sub_ps(v21.m_quad, m_entityB->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
      v14 = _mm_sub_ps(v22.m_quad, m_entityA->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
      v15 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), m_entityA->m_motion.m_angularVelocity.m_quad),
              _mm_mul_ps(
                _mm_shuffle_ps(
                  m_entityA->m_motion.m_angularVelocity.m_quad,
                  m_entityA->m_motion.m_angularVelocity.m_quad,
                  201),
                v14));
      v16 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), m_entityB->m_motion.m_angularVelocity.m_quad),
              _mm_mul_ps(
                _mm_shuffle_ps(
                  m_entityB->m_motion.m_angularVelocity.m_quad,
                  m_entityB->m_motion.m_angularVelocity.m_quad,
                  201),
                v13));
      v17 = _mm_mul_ps(
              _mm_sub_ps(
                _mm_add_ps(_mm_shuffle_ps(v16, v16, 201), m_entityB->m_motion.m_linearVelocity.m_quad),
                _mm_add_ps(_mm_shuffle_ps(v15, v15, 201), m_entityA->m_motion.m_linearVelocity.m_quad)),
              v12);
      v18 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                  _mm_shuffle_ps(v17, v17, 170)),
                _mm_shuffle_ps((__m128)LODWORD(this->m_damping), (__m128)LODWORD(this->m_damping), 0)),
              _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(this->m_strength), (__m128)LODWORD(this->m_strength), 0),
                _mm_sub_ps(v9, v11)));
      this->m_lastForce.m_quad = _mm_mul_ps(_mm_sub_ps((__m128)0i64, v18), v12);
      hkpEntity::activate(m_entityB);
      ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *, hkVector4f *))m_entityB->m_motion.vfptr[12].__first_virtual_table_function__)(
        &m_entityB->m_motion,
        v19,
        &this->m_lastForce,
        &v21);
      this->m_lastForce.m_quad = _mm_mul_ps(v12, v18);
      hkpEntity::activate(m_entityA);
      ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *, hkVector4f *))m_entityA->m_motion.vfptr[12].__first_virtual_table_function__)(
        &m_entityA->m_motion,
        v20,
        &this->m_lastForce,
        &v22);
    }
  }
}

// File Line: 112
// RVA: 0xE1A1C0
hkVector4f *__fastcall hkpSpringAction::clone(
        hkpSpringAction *this,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *newEntities,
        hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  _QWORD **Value; // rax
  hkpSpringAction *v7; // rax
  hkVector4f *v8; // rax
  hkVector4f *v9; // rcx

  if ( newEntities->m_size != 2 || newPhantoms->m_size )
    return 0i64;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkpSpringAction *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 128i64);
  if ( v7 )
  {
    hkpSpringAction::hkpSpringAction(
      v7,
      (hkpRigidBody *)*newEntities->m_data,
      *((hkpRigidBody **)newEntities->m_data + 1),
      this->m_userData);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v9[5] = this->m_positionAinA;
  v9[6] = this->m_positionBinB;
  v9[7].m_quad.m128_i32[0] = LODWORD(this->m_restLength);
  v9[7].m_quad.m128_i32[1] = LODWORD(this->m_strength);
  v9[7].m_quad.m128_i32[2] = LODWORD(this->m_damping);
  v9[7].m_quad.m128_i8[12] = this->m_onCompression.m_bool;
  v9[7].m_quad.m128_i8[13] = this->m_onExtension.m_bool;
  return v9;
}

