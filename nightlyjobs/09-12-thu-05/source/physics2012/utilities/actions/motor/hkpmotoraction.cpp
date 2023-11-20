// File Line: 14
// RVA: 0xE16830
void __fastcall hkpMotorAction::hkpMotorAction(hkpMotorAction *this, hkpRigidBody *body, hkVector4f *axis, float spinRate, float gain)
{
  hkVector4f *v5; // rbx
  hkpMotorAction *v6; // rdi
  __m128 v7; // xmm0
  __m128 v8; // xmm5
  __m128 v9; // xmm0
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm2

  v5 = axis;
  v6 = this;
  hkpUnaryAction::hkpUnaryAction((hkpUnaryAction *)&this->vfptr, (hkpEntity *)&body->vfptr, 0i64);
  v6->vfptr = (hkBaseObjectVtbl *)&hkpMotorAction::`vftable';
  v7 = v5->m_quad;
  v6->m_gain = gain;
  v6->m_spinRate = spinRate;
  v6->m_axis.m_quad = v7;
  v6->m_active.m_bool = 1;
  v8 = v6->m_axis.m_quad;
  v9 = _mm_mul_ps(v8, v8);
  v10 = _mm_add_ps(_mm_shuffle_ps(v9, v9, 78), v9);
  v11 = _mm_add_ps(_mm_shuffle_ps(v10, v10, 177), v10);
  v12 = _mm_rsqrt_ps(v11);
  v6->m_axis.m_quad = _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmpleps(v11, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
                            _mm_mul_ps(*(__m128 *)_xmm, v12))),
                        v8);
}

// File Line: 20
// RVA: 0xE168F0
void __fastcall hkpMotorAction::applyAction(hkpMotorAction *this, hkStepInfo *stepInfo)
{
  hkStepInfo *v2; // rbp
  __m128 *v3; // rbx
  hkpEntity *v4; // rsi
  __m128 v5; // xmm2
  __int128 v6; // xmm6
  __int64 v7; // rdx
  hkVector4f b; // [rsp+20h] [rbp-68h]
  __m128 v9; // [rsp+30h] [rbp-58h]
  __m128 v10; // [rsp+40h] [rbp-48h]
  __m128 v11; // [rsp+50h] [rbp-38h]
  __m128 v12; // [rsp+60h] [rbp-28h]

  v2 = stepInfo;
  v3 = (__m128 *)this;
  if ( this->m_active.m_bool )
  {
    v4 = this->m_entity;
    hkVector4f::setRotatedInverseDir(
      (hkVector4f *)&v9,
      (hkMatrix3f *)&v4->m_motion.m_motionState.m_transform.m_rotation.m_col0,
      &v4->m_motion.m_angularVelocity);
    v5 = _mm_mul_ps(v3[4], v9);
    b.m_quad = _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_shuffle_ps((__m128)v3[5].m128_u32[0], (__m128)v3[5].m128_u32[0], 0),
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)),
                       _mm_shuffle_ps(v5, v5, 170))),
                   _mm_shuffle_ps((__m128)v3[5].m128_u32[1], (__m128)v3[5].m128_u32[1], 0)),
                 v3[4]);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v4->m_motion.vfptr[3].__first_virtual_table_function__)(
      &v4->m_motion,
      &v10);
    b.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(b.m_quad, b.m_quad, 85), v11),
                   _mm_mul_ps(_mm_shuffle_ps(b.m_quad, b.m_quad, 0), v10)),
                 _mm_mul_ps(_mm_shuffle_ps(b.m_quad, b.m_quad, 170), v12));
    hkVector4f::setRotatedDir(&b, (hkMatrix3f *)&v4->m_motion.m_motionState.m_transform.m_rotation.m_col0, &b);
    v6 = LODWORD(v2->m_deltaTime.m_storage);
    hkpEntity::activate(v4);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *))v4->m_motion.vfptr[13].__first_virtual_table_function__)(
      &v4->m_motion,
      v7,
      &b);
  }
}

// File Line: 55
// RVA: 0xE16A30
hkpAction *__fastcall hkpMotorAction::clone(hkpMotorAction *this, hkArray<hkpEntity *,hkContainerHeapAllocator> *newEntities, hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  hkpRigidBody ***v3; // rdi
  hkpMotorAction *v4; // rbx
  _QWORD **v6; // rax
  hkpMotorAction *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rcx

  v3 = (hkpRigidBody ***)newEntities;
  v4 = this;
  if ( newEntities->m_size != 1 || newPhantoms->m_size )
    return 0i64;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkpMotorAction *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 96i64);
  if ( v7 )
  {
    hkpMotorAction::hkpMotorAction(v7, **v3, &v4->m_axis, v4->m_spinRate, v4->m_gain);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  *(_BYTE *)(v9 + 88) = v4->m_active.m_bool;
  *(_QWORD *)(v9 + 32) = v4->m_userData;
  return (hkpAction *)v9;
}

