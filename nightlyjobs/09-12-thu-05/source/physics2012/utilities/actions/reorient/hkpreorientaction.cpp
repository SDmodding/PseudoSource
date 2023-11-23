// File Line: 16
// RVA: 0xE12FE0
void __fastcall hkpReorientAction::hkpReorientAction(hkpReorientAction *this)
{
  hkpUnaryAction::hkpUnaryAction(this, 0i64, 0i64);
  this->vfptr = (hkBaseObjectVtbl *)&hkpReorientAction::`vftable;
  this->m_rotationAxis = 0i64;
  this->m_upAxis = 0i64;
  *(_QWORD *)&this->m_strength = 0i64;
}

// File Line: 27
// RVA: 0xE13020
void __fastcall hkpReorientAction::hkpReorientAction(
        hkpReorientAction *this,
        hkpRigidBody *body,
        hkVector4f *rotationAxis,
        hkVector4f *upAxis,
        float strength,
        float damping)
{
  __m128 m_quad; // xmm1

  hkpUnaryAction::hkpUnaryAction(this, body, 0i64);
  this->vfptr = (hkBaseObjectVtbl *)&hkpReorientAction::`vftable;
  this->m_rotationAxis = (hkVector4f)rotationAxis->m_quad;
  m_quad = upAxis->m_quad;
  this->m_strength = strength;
  this->m_upAxis.m_quad = m_quad;
  this->m_damping = damping;
}

// File Line: 35
// RVA: 0xE13090
void __fastcall hkpReorientAction::applyAction(hkpReorientAction *this, hkStepInfo *stepInfo)
{
  hkpEntity *m_entity; // rsi
  __m128 v5; // xmm2
  __m128 v6; // xmm11
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm2
  __m128 v10; // xmm11
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm9
  __m128 v15; // xmm7
  __m128 v16; // xmm2
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm0
  __m128 v22; // xmm6
  __m128 v23; // xmm11
  __m128i v24; // xmm11
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  __m128 v29; // xmm4
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  float m_storage; // xmm0_4
  hkVector4f v33; // [rsp+20h] [rbp-C8h] BYREF
  hkVector4f v34; // [rsp+30h] [rbp-B8h] BYREF
  __m128 v35; // [rsp+40h] [rbp-A8h] BYREF

  m_entity = this->m_entity;
  hkVector4f::setRotatedDir(&v34, &m_entity->m_motion.m_motionState.m_sweptTransform.m_rotation1, &this->m_upAxis);
  hkVector4f::setRotatedDir(&v33, &m_entity->m_motion.m_motionState.m_sweptTransform.m_rotation1, &this->m_rotationAxis);
  v5 = _mm_mul_ps(this->m_upAxis.m_quad, v33.m_quad);
  v6 = _mm_add_ps(
         this->m_upAxis.m_quad,
         _mm_mul_ps(
           _mm_sub_ps(
             (__m128)0i64,
             _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170))),
           v33.m_quad));
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  v10 = _mm_mul_ps(
          v6,
          _mm_andnot_ps(
            _mm_cmple_ps(v8, (__m128)0i64),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)), _mm_mul_ps(*(__m128 *)_xmm, v9))));
  v11 = _mm_mul_ps(v34.m_quad, v10);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_cmplt_ps(v12, query.m_quad);
  v14 = _mm_max_ps(g_vectorfConstants[0], _mm_or_ps(_mm_and_ps(v13, v12), _mm_andnot_ps(v13, query.m_quad)));
  v15 = _mm_andnot_ps(*(__m128 *)_xmm, v14);
  v16 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v15), *(__m128 *)_xmm);
  v17 = _mm_cmplt_ps(*(__m128 *)_xmm, v15);
  v18 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v16), v17), _mm_andnot_ps(v17, v15));
  v19 = _mm_or_ps(_mm_andnot_ps(v17, _mm_mul_ps(v15, v15)), _mm_and_ps(v17, v16));
  v20 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v19, *(__m128 *)coeff4), *(__m128 *)coeff3), v19),
                        *(__m128 *)coeff2),
                      v19),
                    *(__m128 *)coeff1),
                  v19),
                *(__m128 *)coeff0),
              v19),
            v18),
          v18);
  v21 = _mm_cmplt_ps(v15, *(__m128 *)_xmm);
  v22 = _mm_sub_ps(
          *(__m128 *)_xmm,
          _mm_xor_ps(
            _mm_or_ps(
              _mm_andnot_ps(
                v21,
                _mm_or_ps(_mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v20, v20)), v17), _mm_andnot_ps(v17, v20))),
              _mm_and_ps(v21, v15)),
            _mm_and_ps(v14, *(__m128 *)_xmm)));
  v23 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v34.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v34.m_quad, v34.m_quad, 201), v10));
  v24 = (__m128i)_mm_shuffle_ps(v23, v23, 201);
  v25 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v24, 1u), 1u);
  v26 = _mm_cmple_ps(
          _mm_max_ps(
            _mm_shuffle_ps(v25, v25, 170),
            _mm_max_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0))),
          v25);
  v27 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v33.m_quad, 1u), 1u);
  v28 = _mm_and_ps(
          (__m128)`hkVector4f::getComponent::`2::indexToMask[(unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(_mm_and_ps(v26, (__m128)xmmword_141AA8270))]],
          (__m128)v24);
  v29 = _mm_or_ps(_mm_shuffle_ps(v28, v28, 78), v28);
  v30 = _mm_and_ps(
          (__m128)`hkVector4f::getComponent::`2::indexToMask[(unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(_mm_max_ps(_mm_shuffle_ps(v27, v27, 170), _mm_max_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0))), v27), (__m128)xmmword_141AA8270))]],
          v33.m_quad);
  v31 = _mm_or_ps(_mm_shuffle_ps(v30, v30, 78), v30);
  if ( COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 177).m128_u32[0] | v29.m128_i32[0]) < 0.0 != COERCE_FLOAT(_mm_shuffle_ps(v31, v31, 177).m128_u32[0] | v31.m128_i32[0]) < 0.0 )
    v22 = _mm_sub_ps((__m128)0i64, v22);
  m_storage = stepInfo->m_invDeltaTime.m_storage;
  v35 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(
                (__m128)COERCE_UNSIGNED_INT(m_storage * this->m_strength),
                (__m128)COERCE_UNSIGNED_INT(m_storage * this->m_strength),
                0),
              v22),
            v33.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(
              (__m128)COERCE_UNSIGNED_INT(m_storage * this->m_damping),
              (__m128)COERCE_UNSIGNED_INT(m_storage * this->m_damping),
              0),
            m_entity->m_motion.m_angularVelocity.m_quad));
  hkpEntity::activate(m_entity);
  m_entity->m_motion.vfptr[12].__vecDelDtor(&m_entity->m_motion, (unsigned int)&v35);
}

// File Line: 91
// RVA: 0xE13470
hkpAction *__fastcall hkpReorientAction::clone(
        hkpReorientAction *this,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *newEntities,
        hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  _QWORD **Value; // rax
  hkpReorientAction *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rcx

  if ( newEntities->m_size != 1 || newPhantoms->m_size )
    return 0i64;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkpReorientAction *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 112i64);
  if ( v7 )
  {
    hkpReorientAction::hkpReorientAction(
      v7,
      (hkpRigidBody *)*newEntities->m_data,
      &this->m_rotationAxis,
      &this->m_upAxis,
      this->m_strength,
      this->m_damping);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  *(_QWORD *)(v9 + 32) = this->m_userData;
  return (hkpAction *)v9;
}

