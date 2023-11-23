// File Line: 16
// RVA: 0xE26230
void __fastcall hkpVehicleData::hkpVehicleData(hkpVehicleData *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleData::`vftable;
  this->m_wheelParams.m_capacityAndFlags = 0x80000000;
  this->m_wheelParams.m_data = 0i64;
  this->m_wheelParams.m_size = 0;
  this->m_numWheelsPerAxle.m_data = 0i64;
  this->m_numWheelsPerAxle.m_size = 0;
  this->m_numWheelsPerAxle.m_capacityAndFlags = 0x80000000;
  this->m_numWheels = 0;
  this->m_chassisOrientation.m_col0 = 0i64;
  this->m_chassisOrientation.m_col1 = 0i64;
  this->m_chassisOrientation.m_col2 = 0i64;
  *(_QWORD *)&this->m_torqueRollFactor = 0i64;
  *(_QWORD *)&this->m_torqueYawFactor = 1065353216i64;
  this->m_maxVelocityForPositionalFriction = 10.0;
  this->m_chassisFrictionInertiaInvDiag = 0i64;
  this->m_gravity = 0i64;
  this->m_chassisUnitInertiaYaw = 1.0;
  this->m_chassisUnitInertiaRoll = 1.0;
  *(_QWORD *)&this->m_chassisUnitInertiaPitch = 1065353216i64;
  this->m_normalClippingAngleCos = 0.1;
  this->m_alreadyInitialised.m_bool = 0;
  this->m_maxFrictionSolverMassRatio = 30.0;
}

// File Line: 39
// RVA: 0xE262E0
void __fastcall hkpVehicleData::init(
        hkpVehicleData *this,
        hkArray<hkpVehicleSuspension::SuspensionWheelParameters,hkContainerHeapAllocator> *suspensionWheelParams,
        hkpRigidBody *chassis)
{
  int v3; // esi
  int m_numWheels; // eax
  int v7; // edi
  __int64 v8; // rdx
  char *p_m_axle; // rcx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // r9d
  int v15; // ecx
  __int64 i; // rdx
  __int64 v17; // rdx
  __int64 m_axle; // rcx
  __m128 v19; // xmm4
  __m128 v20; // xmm1
  __m128 v21; // xmm4
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // [rsp+30h] [rbp-28h]
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  v3 = 0;
  this->m_alreadyInitialised.m_bool = 1;
  m_numWheels = this->m_numWheels;
  v7 = 0;
  if ( m_numWheels > 0 )
  {
    v8 = (unsigned int)m_numWheels;
    p_m_axle = &this->m_wheelParams.m_data->m_axle;
    do
    {
      v10 = *p_m_axle;
      p_m_axle += 40;
      v11 = v10 + 1;
      if ( v11 > v7 )
        v7 = v11;
      --v8;
    }
    while ( v8 );
  }
  if ( v7 > this->m_numWheelsPerAxle.m_size )
  {
    v12 = this->m_numWheelsPerAxle.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v12 < v7 )
    {
      v13 = 2 * v12;
      v14 = v7;
      if ( v7 < v13 )
        v14 = v13;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_numWheelsPerAxle.m_data,
        v14,
        1);
    }
    this->m_numWheelsPerAxle.m_size = v7;
  }
  v15 = 0;
  for ( i = 0i64; v15 < this->m_numWheelsPerAxle.m_size; this->m_numWheelsPerAxle.m_data[i - 1] = 0 )
  {
    ++v15;
    ++i;
  }
  if ( this->m_numWheels > 0 )
  {
    v17 = 0i64;
    do
    {
      ++v3;
      m_axle = this->m_wheelParams.m_data[v17++].m_axle;
      ++this->m_numWheelsPerAxle.m_data[m_axle];
    }
    while ( v3 < this->m_numWheels );
  }
  v19 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&this->m_chassisOrientation), 1u), 1u);
  *(float *)&result.m_enum = this->m_torqueYawFactor / this->m_chassisUnitInertiaYaw;
  v20 = _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0);
  *(float *)&result.m_enum = this->m_torqueRollFactor / this->m_chassisUnitInertiaRoll;
  v21 = _mm_mul_ps(v19, v20);
  v22 = _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0);
  v23 = (__m128)_mm_srli_epi32(
                  _mm_slli_epi32(_mm_load_si128((const __m128i *)&this->m_chassisOrientation.m_col2), 1u),
                  1u);
  *(float *)&result.m_enum = this->m_torquePitchFactor / this->m_chassisUnitInertiaPitch;
  v24 = _mm_add_ps(
          _mm_add_ps(
            v21,
            _mm_mul_ps(
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32(_mm_load_si128((const __m128i *)&this->m_chassisOrientation.m_col1), 1u),
                        1u),
              v22)),
          _mm_mul_ps(v23, _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0)));
  v24.m128_i32[3] = (int)FLOAT_1_0;
  this->m_chassisFrictionInertiaInvDiag.m_quad = _mm_mul_ps(
                                                   _mm_shuffle_ps(
                                                     chassis->m_motion.m_inertiaAndMassInv.m_quad,
                                                     chassis->m_motion.m_inertiaAndMassInv.m_quad,
                                                     255),
                                                   v24);
}

