// File Line: 18
// RVA: 0xE14ED0
void __fastcall hkpDashpotAction::hkpDashpotAction(hkpDashpotAction *this, hkpRigidBody *entityA, hkpRigidBody *entityB, unsigned __int64 userData)
{
  hkpDashpotAction *v4; // rbx

  v4 = this;
  hkpBinaryAction::hkpBinaryAction(
    (hkpBinaryAction *)&this->vfptr,
    (hkpEntity *)&entityA->vfptr,
    (hkpEntity *)&entityB->vfptr,
    userData);
  v4->vfptr = (hkBaseObjectVtbl *)&hkpDashpotAction::`vftable';
  v4->m_strength = 0.1;
  v4->m_damping = 0.0099999998;
  v4->m_point[0] = 0i64;
  v4->m_point[1] = 0i64;
}

// File Line: 30
// RVA: 0xE14F10
void __fastcall hkpDashpotAction::applyAction(hkpDashpotAction *this, hkStepInfo *stepInfo)
{
  hkpDashpotAction *v2; // rbp
  hkStepInfo *v3; // rbx
  _QWORD *v4; // rax
  _QWORD *v5; // rcx
  _QWORD *v6; // r8
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  hkpEntity *v9; // rdi
  hkpEntity *v10; // rsi
  float v11; // xmm6_4
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  _QWORD *v14; // r8
  _QWORD *v15; // rcx
  unsigned __int64 v16; // rax
  signed __int64 v17; // rcx
  hkVector4f v18; // [rsp+20h] [rbp-48h]
  hkVector4f v19; // [rsp+30h] [rbp-38h]
  __m128 v20; // [rsp+40h] [rbp-28h]
  unsigned int v21; // [rsp+70h] [rbp+8h]

  v2 = this;
  v3 = stepInfo;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  v6 = v4;
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtDashpot";
    v7 = __rdtsc();
    v8 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v8 - 8) = v7;
    v6[1] = v8;
  }
  v9 = v2->m_entityA;
  v10 = v2->m_entityB;
  v11 = v3->m_deltaTime.m_storage * 151.0;
  hkVector4f::setTransformedPos(&v18, &v9->m_motion.m_motionState.m_transform, v2->m_point);
  hkVector4f::setTransformedPos(&v19, &v10->m_motion.m_motionState.m_transform, &v2->m_point[1]);
  v12 = _mm_sub_ps(v9->m_motion.m_linearVelocity.m_quad, v10->m_motion.m_linearVelocity.m_quad);
  *(float *)&v21 = v11 * v2->m_damping;
  v2->m_impulse.m_quad = _mm_mul_ps(
                           _mm_shuffle_ps(
                             (__m128)COERCE_UNSIGNED_INT(v11 * v2->m_strength),
                             (__m128)COERCE_UNSIGNED_INT(v11 * v2->m_strength),
                             0),
                           _mm_sub_ps(v18.m_quad, v19.m_quad));
  v13 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v21, (__m128)v21, 0), v12), v2->m_impulse.m_quad);
  v2->m_impulse.m_quad = v13;
  v20 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v13);
  hkpEntity::activate(v9);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, hkVector4f *))v9->m_motion.vfptr[11].__first_virtual_table_function__)(
    &v9->m_motion,
    &v20,
    &v18);
  hkpEntity::activate(v10);
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *, hkVector4f *))v10->m_motion.vfptr[11].__first_virtual_table_function__)(
    &v10->m_motion,
    &v2->m_impulse,
    &v19);
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)v14[1];
  if ( (unsigned __int64)v15 < v14[3] )
  {
    *v15 = "Et";
    v16 = __rdtsc();
    v17 = (signed __int64)(v15 + 2);
    *(_DWORD *)(v17 - 8) = v16;
    v14[1] = v17;
  }
}

// File Line: 84
// RVA: 0xE150C0
hkpAction *__fastcall hkpDashpotAction::clone(hkpDashpotAction *this, hkArray<hkpEntity *,hkContainerHeapAllocator> *newEntities, hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  hkpRigidBody ***v3; // rdi
  hkpDashpotAction *v4; // rbx
  hkpAction *result; // rax
  _QWORD **v6; // rax
  hkpDashpotAction *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rcx

  v3 = (hkpRigidBody ***)newEntities;
  v4 = this;
  if ( newEntities->m_size != 2 || newPhantoms->m_size )
    return 0i64;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkpDashpotAction *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 128i64);
  if ( v7 )
  {
    hkpDashpotAction::hkpDashpotAction(v7, **v3, (*v3)[1], v4->m_userData);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  *(hkVector4f *)(v9 + 64) = v4->m_point[0];
  *(hkVector4f *)(v9 + 80) = v4->m_point[1];
  *(float *)(v9 + 96) = v4->m_strength;
  *(float *)(v9 + 100) = v4->m_damping;
  result = (hkpAction *)v9;
  *(hkVector4f *)(v9 + 112) = v4->m_impulse;
  return result;
}

