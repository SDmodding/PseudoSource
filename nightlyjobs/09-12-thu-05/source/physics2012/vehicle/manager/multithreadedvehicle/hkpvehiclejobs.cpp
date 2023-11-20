// File Line: 14
// RVA: 0xE31620
void __fastcall hkpVehicleIntegrateJob::setRunsOnSpuOrPpu(hkpVehicleIntegrateJob *this)
{
  ;
}

// File Line: 23
// RVA: 0xE313E0
void __fastcall hkpVehicleJobResults::applyForcesFromStep(hkpVehicleJobResults *this, hkpVehicleInstance *vehicleInstance)
{
  hkpVehicleJobResults *v2; // r13
  hkpVehicleInstance *v3; // rbx
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  int v8; // ebp
  __int64 v9; // r12
  __int64 v10; // r15
  const __m128i *v11; // r14
  __m128 v12; // xmm6
  hkpVehicleInstance::WheelInfo *v13; // rbx
  signed __int64 v14; // rsi
  hkpEntity *v15; // rbx
  hkpEntity *v16; // rbx
  hkpEntity **v17; // rdi
  signed __int64 v18; // rsi
  signed __int64 v19; // rbp
  hkpEntity *v20; // rbx
  hkpEntity *v21; // rbx
  _QWORD *v22; // rax
  _QWORD *v23; // rcx
  _QWORD *v24; // r8
  unsigned __int64 v25; // rax
  signed __int64 v26; // rcx
  hkpVehicleInstance *v27; // [rsp+78h] [rbp+10h]

  v27 = vehicleInstance;
  v2 = this;
  v3 = vehicleInstance;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtApplyVehicleForces";
    v6 = __rdtsc();
    v7 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v7 - 8) = v6;
    v4[1] = v7;
  }
  v8 = 0;
  v9 = (unsigned __int8)v3->m_data->m_numWheels;
  if ( (signed int)v9 > 0 )
  {
    v10 = 0i64;
    v11 = (const __m128i *)v2->m_groundBodyImpulses;
    v12 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
    do
    {
      if ( (_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128(v11), 1u), 1u), v12)) & 7) != 7 )
      {
        v13 = v3->m_wheelsInfo.m_data;
        v14 = (signed __int64)&v13[v8];
        v15 = (hkpEntity *)&v13[v10].m_contactBody->vfptr;
        hkpEntity::activate(v15);
        ((void (__fastcall *)(hkpMaxSizeMotion *, signed __int64, signed __int64))v15->m_motion.vfptr[11].__first_virtual_table_function__)(
          &v15->m_motion,
          (signed __int64)v2 + 16 * (v8 + 7i64),
          v14 + 80);
        v3 = v27;
      }
      ++v8;
      ++v11;
      ++v10;
      --v9;
    }
    while ( v9 );
  }
  v16 = v3->m_entity;
  hkpEntity::activate(v16);
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))v16->m_motion.vfptr[9].__first_virtual_table_function__)(
    &v16->m_motion,
    &v2->m_chassisAngularVel);
  hkpEntity::activate(v16);
  v16->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v16->m_motion.vfptr, (unsigned int)v2);
  v17 = (hkpEntity **)v2->m_groundBodyPtr;
  v18 = (signed __int64)v2->m_groundBodyLinearVel;
  v19 = 2i64;
  do
  {
    v20 = *v17;
    if ( *v17 )
    {
      hkpEntity::activate(*v17);
      ((void (__fastcall *)(hkpMaxSizeMotion *, signed __int64))v20->m_motion.vfptr[9].__first_virtual_table_function__)(
        &v20->m_motion,
        v18 + 32);
      v21 = *v17;
      hkpEntity::activate(*v17);
      v21->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v21->m_motion.vfptr, v18);
    }
    v18 += 16i64;
    ++v17;
    --v19;
  }
  while ( v19 );
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = (_QWORD *)v22[1];
  v24 = v22;
  if ( (unsigned __int64)v23 < v22[3] )
  {
    *v23 = "Et";
    v25 = __rdtsc();
    v26 = (signed __int64)(v23 + 2);
    *(_DWORD *)(v26 - 8) = v25;
    v24[1] = v26;
  }
}

