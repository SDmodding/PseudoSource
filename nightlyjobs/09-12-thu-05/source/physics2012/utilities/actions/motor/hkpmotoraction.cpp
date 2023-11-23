// File Line: 14
// RVA: 0xE16830
void __fastcall hkpMotorAction::hkpMotorAction(
        hkpMotorAction *this,
        hkpRigidBody *body,
        hkVector4f *axis,
        float spinRate,
        float gain)
{
  __m128 m_quad; // xmm0
  hkVector4f v8; // xmm5
  __m128 v9; // xmm0
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm2

  hkpUnaryAction::hkpUnaryAction(this, body, 0i64);
  this->vfptr = (hkBaseObjectVtbl *)&hkpMotorAction::`vftable;
  m_quad = axis->m_quad;
  this->m_gain = gain;
  this->m_spinRate = spinRate;
  this->m_axis.m_quad = m_quad;
  this->m_active.m_bool = 1;
  v8.m_quad = (__m128)this->m_axis;
  v9 = _mm_mul_ps(v8.m_quad, v8.m_quad);
  v10 = _mm_add_ps(_mm_shuffle_ps(v9, v9, 78), v9);
  v11 = _mm_add_ps(_mm_shuffle_ps(v10, v10, 177), v10);
  v12 = _mm_rsqrt_ps(v11);
  this->m_axis.m_quad = _mm_mul_ps(
                          _mm_andnot_ps(
                            _mm_cmple_ps(v11, (__m128)0i64),
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
                              _mm_mul_ps(*(__m128 *)_xmm, v12))),
                          v8.m_quad);
}

// File Line: 20
// RVA: 0xE168F0
void __fastcall hkpMotorAction::applyAction(hkpMotorAction *this, hkStepInfo *stepInfo)
{
  hkpEntity *m_entity; // rsi
  __m128 v4; // xmm2
  __int64 v5; // rdx
  hkVector4f b; // [rsp+20h] [rbp-68h] BYREF
  hkVector4f v7; // [rsp+30h] [rbp-58h] BYREF
  __m128 v8[3]; // [rsp+40h] [rbp-48h] BYREF

  if ( this->m_active.m_bool )
  {
    m_entity = this->m_entity;
    hkVector4f::setRotatedInverseDir(
      &v7,
      &m_entity->m_motion.m_motionState.m_transform.m_rotation,
      &m_entity->m_motion.m_angularVelocity);
    v4 = _mm_mul_ps(this->m_axis.m_quad, v7.m_quad);
    b.m_quad = _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_shuffle_ps((__m128)LODWORD(this->m_spinRate), (__m128)LODWORD(this->m_spinRate), 0),
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)),
                       _mm_shuffle_ps(v4, v4, 170))),
                   _mm_shuffle_ps((__m128)LODWORD(this->m_gain), (__m128)LODWORD(this->m_gain), 0)),
                 this->m_axis.m_quad);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))m_entity->m_motion.vfptr[3].__first_virtual_table_function__)(
      &m_entity->m_motion,
      v8);
    b.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(b.m_quad, b.m_quad, 85), v8[1]),
                   _mm_mul_ps(_mm_shuffle_ps(b.m_quad, b.m_quad, 0), v8[0])),
                 _mm_mul_ps(_mm_shuffle_ps(b.m_quad, b.m_quad, 170), v8[2]));
    hkVector4f::setRotatedDir(&b, &m_entity->m_motion.m_motionState.m_transform.m_rotation, &b);
    hkpEntity::activate(m_entity);
    ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *))m_entity->m_motion.vfptr[13].__first_virtual_table_function__)(
      &m_entity->m_motion,
      v5,
      &b);
  }
}

// File Line: 55
// RVA: 0xE16A30
hkpAction *__fastcall hkpMotorAction::clone(
        hkpMotorAction *this,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *newEntities,
        hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  _QWORD **Value; // rax
  hkpMotorAction *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rcx

  if ( newEntities->m_size != 1 || newPhantoms->m_size )
    return 0i64;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkpMotorAction *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 96i64);
  if ( v7 )
  {
    hkpMotorAction::hkpMotorAction(
      v7,
      (hkpRigidBody *)*newEntities->m_data,
      &this->m_axis,
      this->m_spinRate,
      this->m_gain);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  *(_BYTE *)(v9 + 88) = this->m_active.m_bool;
  *(_QWORD *)(v9 + 32) = this->m_userData;
  return (hkpAction *)v9;
}

