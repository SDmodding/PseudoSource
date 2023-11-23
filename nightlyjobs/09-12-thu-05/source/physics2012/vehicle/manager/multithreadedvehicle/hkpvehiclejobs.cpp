// File Line: 14
// RVA: 0xE31620
void __fastcall hkpVehicleIntegrateJob::setRunsOnSpuOrPpu(hkpVehicleIntegrateJob *this)
{
  ;
}

// File Line: 23
// RVA: 0xE313E0
void __fastcall hkpVehicleJobResults::applyForcesFromStep(
        hkpVehicleJobResults *this,
        hkpVehicleInstance *vehicleInstance)
{
  hkpVehicleInstance *v3; // rbx
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  hkpVehicleData *m_data; // rax
  int v9; // ebp
  __int64 m_numWheels; // r12
  __int64 v11; // r15
  hkVector4f *m_groundBodyImpulses; // r14
  __m128 v13; // xmm6
  hkpVehicleInstance::WheelInfo *v14; // rbx
  hkpVehicleInstance::WheelInfo *v15; // rsi
  hkpEntity *m_contactBody; // rbx
  hkpEntity *m_entity; // rbx
  hkpRigidBody **m_groundBodyPtr; // rdi
  hkVector4f *m_groundBodyLinearVel; // rsi
  __int64 v20; // rbp
  hkpEntity *v21; // rbx
  hkpEntity *v22; // rbx
  _QWORD *v23; // rax
  _QWORD *v24; // rcx
  _QWORD *v25; // r8
  unsigned __int64 v26; // rax
  _QWORD *v27; // rcx

  v3 = vehicleInstance;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtApplyVehicleForces";
    v6 = __rdtsc();
    v7 = v5 + 2;
    *((_DWORD *)v7 - 2) = v6;
    Value[1] = v7;
  }
  m_data = v3->m_data;
  v9 = 0;
  m_numWheels = (unsigned __int8)m_data->m_numWheels;
  if ( m_data->m_numWheels )
  {
    v11 = 0i64;
    m_groundBodyImpulses = this->m_groundBodyImpulses;
    v13 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
    do
    {
      if ( (_mm_movemask_ps(
              _mm_cmplt_ps(
                (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)m_groundBodyImpulses), 1u), 1u),
                v13)) & 7) != 7 )
      {
        v14 = v3->m_wheelsInfo.m_data;
        v15 = &v14[v9];
        m_contactBody = v14[v11].m_contactBody;
        hkpEntity::activate(m_contactBody);
        ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *, hkVector4f *))m_contactBody->m_motion.vfptr[11].__first_virtual_table_function__)(
          &m_contactBody->m_motion,
          &this->m_groundBodyImpulses[v9],
          &v15->m_hardPointWs);
        v3 = vehicleInstance;
      }
      ++v9;
      ++m_groundBodyImpulses;
      ++v11;
      --m_numWheels;
    }
    while ( m_numWheels );
  }
  m_entity = v3->m_entity;
  hkpEntity::activate(m_entity);
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))m_entity->m_motion.vfptr[9].__first_virtual_table_function__)(
    &m_entity->m_motion,
    &this->m_chassisAngularVel);
  hkpEntity::activate(m_entity);
  m_entity->m_motion.vfptr[9].__vecDelDtor(&m_entity->m_motion, (unsigned int)this);
  m_groundBodyPtr = this->m_groundBodyPtr;
  m_groundBodyLinearVel = this->m_groundBodyLinearVel;
  v20 = 2i64;
  do
  {
    v21 = *m_groundBodyPtr;
    if ( *m_groundBodyPtr )
    {
      hkpEntity::activate(*m_groundBodyPtr);
      ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))v21->m_motion.vfptr[9].__first_virtual_table_function__)(
        &v21->m_motion,
        &m_groundBodyLinearVel[2]);
      v22 = *m_groundBodyPtr;
      hkpEntity::activate(*m_groundBodyPtr);
      v22->m_motion.vfptr[9].__vecDelDtor(&v22->m_motion, (unsigned int)m_groundBodyLinearVel);
    }
    ++m_groundBodyLinearVel;
    ++m_groundBodyPtr;
    --v20;
  }
  while ( v20 );
  v23 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v24 = (_QWORD *)v23[1];
  v25 = v23;
  if ( (unsigned __int64)v24 < v23[3] )
  {
    *v24 = "Et";
    v26 = __rdtsc();
    v27 = v24 + 2;
    *((_DWORD *)v27 - 2) = v26;
    v25[1] = v27;
  }
}

