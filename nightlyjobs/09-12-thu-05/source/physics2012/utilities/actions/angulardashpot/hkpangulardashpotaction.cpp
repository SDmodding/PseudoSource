// File Line: 16
// RVA: 0xE13C10
void __fastcall hkpAngularDashpotAction::hkpAngularDashpotAction(hkpAngularDashpotAction *this, hkpRigidBody *entityA, hkpRigidBody *entityB, unsigned __int64 userData)
{
  hkQuaternionf *v4; // rbx

  v4 = (hkQuaternionf *)this;
  hkpBinaryAction::hkpBinaryAction(
    (hkpBinaryAction *)&this->vfptr,
    (hkpEntity *)&entityA->vfptr,
    (hkpEntity *)&entityB->vfptr,
    userData);
  v4->m_vec.m_quad.m128_u64[0] = (unsigned __int64)&hkpAngularDashpotAction::`vftable;
  v4[5].m_vec.m_quad.m128_i32[0] = 1036831949;
  v4[5].m_vec.m_quad.m128_i32[1] = 1008981770;
  v4[4] = (hkQuaternionf)qi.m_vec.m_quad;
}

// File Line: 21
// RVA: 0xE13C50
void __fastcall hkpAngularDashpotAction::applyAction(hkpAngularDashpotAction *this, hkStepInfo *stepInfo)
{
  hkQuaternionf v2; // xmm3
  hkpEntity *v3; // rdi
  hkpEntity *v4; // rbx
  __m128 v5; // xmm2
  __m128 v6; // xmm5
  float v7; // xmm10_4
  __m128 v8; // xmm4
  __m128i v9; // xmm12
  __m128 v10; // xmm6
  __m128 v11; // xmm3
  __m128 v12; // xmm2
  __m128 v13; // xmm6
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm5
  __m128 v17; // xmm4
  __m128 v18; // xmm11
  __m128 v19; // xmm0
  __m128 v20; // xmm5
  __m128 v21; // xmm11
  __m128 v22; // xmm11
  __m128 v23; // xmm13
  __m128 v24; // xmm9
  __m128 v25; // xmm7
  __m128 v26; // xmm6
  __m128 v27; // xmm2
  __m128 v28; // xmm5
  __m128 v29; // xmm4
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  float v32; // xmm0_4
  __m128 v33; // xmm2
  __m128 v34; // [rsp+20h] [rbp-98h]

  v2.m_vec.m_quad = (__m128)this->m_rotation;
  v3 = this->m_entityB;
  v4 = this->m_entityA;
  v5 = v3->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
  v6 = _mm_shuffle_ps(this->m_rotation.m_vec.m_quad, this->m_rotation.m_vec.m_quad, 255);
  v8 = _mm_shuffle_ps(
         v3->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
         v3->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
         255);
  v9 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  v10 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v2.m_vec.m_quad, v2.m_vec.m_quad, 201), v5),
          _mm_mul_ps(
            _mm_shuffle_ps(v3->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad, v5, 201),
            v2.m_vec.m_quad));
  v11 = _mm_mul_ps(v2.m_vec.m_quad, v5);
  v12 = v4->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
  v13 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v10, v10, 201), _mm_mul_ps(this->m_rotation.m_vec.m_quad, v8)),
          _mm_mul_ps(v3->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad, v6));
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v15 = _mm_shuffle_ps(
          v4->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
          v4->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
          255);
  v16 = _mm_xor_ps(
          (__m128)_mm_shuffle_epi32(v9, 64),
          _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, _mm_sub_ps(_mm_mul_ps(v6, v8), v14)), 196));
  v17 = _mm_shuffle_ps(v16, v16, 255);
  v18 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v12),
          _mm_mul_ps(
            _mm_shuffle_ps(v4->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad, v12, 201),
            v16));
  v19 = _mm_mul_ps(v16, v15);
  v20 = _mm_mul_ps(v16, v12);
  v21 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 201), v19), _mm_mul_ps(v12, v17));
  v22 = _mm_shuffle_ps(
          v21,
          _mm_unpackhi_ps(
            v21,
            _mm_sub_ps(
              _mm_mul_ps(v17, v15),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                _mm_shuffle_ps(v20, v20, 170)))),
          196);
  v23 = _mm_sub_ps(v4->m_motion.m_angularVelocity.m_quad, v3->m_motion.m_angularVelocity.m_quad);
  v24 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_shuffle_ps(v22, v22, 255), 1u), 1u);
  v25 = _mm_andnot_ps(*(__m128 *)_xmm, v24);
  v26 = _mm_cmpltps(v25, *(__m128 *)_xmm);
  v27 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v25), *(__m128 *)_xmm);
  v28 = _mm_cmpltps(*(__m128 *)_xmm, v25);
  v29 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v27), v28), _mm_andnot_ps(v28, v25));
  v30 = _mm_or_ps(_mm_andnot_ps(v28, _mm_mul_ps(v25, v25)), _mm_and_ps(v28, v27));
  v31 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v30, *(__m128 *)coeff4), *(__m128 *)coeff3), v30),
                        *(__m128 *)coeff2),
                      v30),
                    *(__m128 *)coeff1),
                  v30),
                *(__m128 *)coeff0),
              v30),
            v29),
          v29);
  v32 = 1.5707964
      - COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                               v26,
                                               _mm_or_ps(
                                                 _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v31, v31)), v28),
                                                 _mm_andnot_ps(v28, v31))) | v26.m128_i32[0] & v25.m128_i32[0]) ^ v24.m128_i32[0] & _xmm[0]);
  v33 = 0i64;
  if ( (float)(v32 * 2.0) > 0.001 )
    v33 = _mm_mul_ps(
            _mm_shuffle_ps((__m128)COERCE_UNSIGNED_INT(v32 * 2.0), (__m128)COERCE_UNSIGNED_INT(v32 * 2.0), 0),
            v22);
  v7 = stepInfo->m_deltaTime.m_storage * 200.0;
  v34 = _mm_add_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(
              (__m128)COERCE_UNSIGNED_INT(v7 * this->m_strength),
              (__m128)COERCE_UNSIGNED_INT(v7 * this->m_strength),
              0),
            v33),
          _mm_mul_ps(
            _mm_shuffle_ps(
              (__m128)COERCE_UNSIGNED_INT(v7 * this->m_damping),
              (__m128)COERCE_UNSIGNED_INT(v7 * this->m_damping),
              0),
            v23));
  hkpEntity::activate(v3);
  v3->m_motion.vfptr[12].__vecDelDtor((hkBaseObject *)&v3->m_motion.vfptr, (unsigned int)&v34);
  v34 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v9, 0), v34);
  hkpEntity::activate(v4);
  v4->m_motion.vfptr[12].__vecDelDtor((hkBaseObject *)&v4->m_motion.vfptr, (unsigned int)&v34);
}

// File Line: 64
// RVA: 0xE13F90
hkQuaternionf *__fastcall hkpAngularDashpotAction::clone(hkpAngularDashpotAction *this, hkArray<hkpEntity *,hkContainerHeapAllocator> *newEntities, hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  hkpRigidBody ***v3; // rdi
  hkpAngularDashpotAction *v4; // rbx
  _QWORD **v6; // rax
  hkpAngularDashpotAction *v7; // rax
  hkQuaternionf *v8; // rax
  hkQuaternionf *v9; // rcx

  v3 = (hkpRigidBody ***)newEntities;
  v4 = this;
  if ( newEntities->m_size != 2 || newPhantoms->m_size )
    return 0i64;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkpAngularDashpotAction *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 96i64);
  if ( v7 )
  {
    hkpAngularDashpotAction::hkpAngularDashpotAction(v7, **v3, (*v3)[1], v4->m_userData);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v9[4] = v4->m_rotation;
  v9[5].m_vec.m_quad.m128_i32[0] = LODWORD(v4->m_strength);
  v9[5].m_vec.m_quad.m128_i32[1] = LODWORD(v4->m_damping);
  return v9;
}

