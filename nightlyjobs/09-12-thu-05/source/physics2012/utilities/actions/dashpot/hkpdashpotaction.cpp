// File Line: 18
// RVA: 0xE14ED0
void __fastcall hkpDashpotAction::hkpDashpotAction(
        hkpDashpotAction *this,
        hkpRigidBody *entityA,
        hkpRigidBody *entityB,
        unsigned __int64 userData)
{
  hkpBinaryAction::hkpBinaryAction(this, entityA, entityB, userData);
  this->vfptr = (hkBaseObjectVtbl *)&hkpDashpotAction::`vftable;
  this->m_strength = 0.1;
  this->m_damping = 0.0099999998;
  this->m_point[0] = 0i64;
  this->m_point[1] = 0i64;
}

// File Line: 30
// RVA: 0xE14F10
void __fastcall hkpDashpotAction::applyAction(hkpDashpotAction *this, hkStepInfo *stepInfo)
{
  _QWORD *Value; // rax
  _QWORD *v5; // rcx
  _QWORD *v6; // r8
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  hkpEntity *m_entityA; // rdi
  hkpEntity *m_entityB; // rsi
  float v11; // xmm6_4
  __m128 v12; // xmm2
  hkVector4f v13; // xmm1
  _QWORD *v14; // r8
  _QWORD *v15; // rcx
  unsigned __int64 v16; // rax
  _QWORD *v17; // rcx
  hkVector4f v18; // [rsp+20h] [rbp-48h] BYREF
  hkVector4f v19; // [rsp+30h] [rbp-38h] BYREF
  __m128 v20; // [rsp+40h] [rbp-28h] BYREF
  unsigned int v21; // [rsp+70h] [rbp+8h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  v6 = Value;
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtDashpot";
    v7 = __rdtsc();
    v8 = v5 + 2;
    *((_DWORD *)v8 - 2) = v7;
    v6[1] = v8;
  }
  m_entityA = this->m_entityA;
  m_entityB = this->m_entityB;
  v11 = stepInfo->m_deltaTime.m_storage * 151.0;
  hkVector4f::setTransformedPos(&v18, &m_entityA->m_motion.m_motionState.m_transform, this->m_point);
  hkVector4f::setTransformedPos(&v19, &m_entityB->m_motion.m_motionState.m_transform, &this->m_point[1]);
  v12 = _mm_sub_ps(m_entityA->m_motion.m_linearVelocity.m_quad, m_entityB->m_motion.m_linearVelocity.m_quad);
  *(float *)&v21 = v11 * this->m_damping;
  this->m_impulse.m_quad = _mm_mul_ps(
                             _mm_shuffle_ps(
                               (__m128)COERCE_UNSIGNED_INT(v11 * this->m_strength),
                               (__m128)COERCE_UNSIGNED_INT(v11 * this->m_strength),
                               0),
                             _mm_sub_ps(v18.m_quad, v19.m_quad));
  v13.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v21, (__m128)v21, 0), v12), this->m_impulse.m_quad);
  this->m_impulse = (hkVector4f)v13.m_quad;
  v20 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v13.m_quad);
  hkpEntity::activate(m_entityA);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, hkVector4f *))m_entityA->m_motion.vfptr[11].__first_virtual_table_function__)(
    &m_entityA->m_motion,
    &v20,
    &v18);
  hkpEntity::activate(m_entityB);
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *, hkVector4f *))m_entityB->m_motion.vfptr[11].__first_virtual_table_function__)(
    &m_entityB->m_motion,
    &this->m_impulse,
    &v19);
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)v14[1];
  if ( (unsigned __int64)v15 < v14[3] )
  {
    *v15 = "Et";
    v16 = __rdtsc();
    v17 = v15 + 2;
    *((_DWORD *)v17 - 2) = v16;
    v14[1] = v17;
  }
}

// File Line: 84
// RVA: 0xE150C0
hkpAction *__fastcall hkpDashpotAction::clone(
        hkpDashpotAction *this,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *newEntities,
        hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  hkpAction *result; // rax
  _QWORD **Value; // rax
  hkpDashpotAction *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rcx

  if ( newEntities->m_size != 2 || newPhantoms->m_size )
    return 0i64;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkpDashpotAction *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 128i64);
  if ( v7 )
  {
    hkpDashpotAction::hkpDashpotAction(
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
  *(hkVector4f *)(v9 + 64) = this->m_point[0];
  *(hkVector4f *)(v9 + 80) = this->m_point[1];
  *(float *)(v9 + 96) = this->m_strength;
  *(float *)(v9 + 100) = this->m_damping;
  result = (hkpAction *)v9;
  *(hkVector4f *)(v9 + 112) = this->m_impulse;
  return result;
}

