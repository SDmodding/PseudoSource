// File Line: 16
// RVA: 0xE2C470
void __fastcall hkpTyremarksWheel::hkpTyremarksWheel(hkpTyremarksWheel *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpTyremarksWheel::`vftable;
  this->m_tyremarkPoints.m_capacityAndFlags = 0x80000000;
  this->m_tyremarkPoints.m_data = 0i64;
  *(_QWORD *)&this->m_currentPosition = 0i64;
  this->m_tyremarkPoints.m_size = 0;
}

// File Line: 23
// RVA: 0xE2C4A0
void __fastcall hkpTyremarksWheel::setNumPoints(hkpTyremarksWheel *this, int num_points)
{
  int v2; // edi
  hkpTyremarkPoint *v4; // rax
  hkVector4f v5; // xmm1
  hkpTyremarkPoint v6; // [rsp+20h] [rbp-28h] BYREF

  v2 = 0;
  this->m_numPoints = num_points;
  for ( this->m_currentPosition = 0; v2 < this->m_numPoints; ++v2 )
  {
    hkpTyremarkPoint::hkpTyremarkPoint(&v6);
    if ( this->m_tyremarkPoints.m_size == (this->m_tyremarkPoints.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_tyremarkPoints.m_data, 32);
    v4 = &this->m_tyremarkPoints.m_data[this->m_tyremarkPoints.m_size];
    if ( v4 )
    {
      v5.m_quad = (__m128)v6.m_pointRight;
      v4->m_pointLeft = v6.m_pointLeft;
      v4->m_pointRight = (hkVector4f)v5.m_quad;
    }
    ++this->m_tyremarkPoints.m_size;
  }
}

// File Line: 36
// RVA: 0xE2C440
void __fastcall hkpTyremarkPoint::hkpTyremarkPoint(hkpTyremarkPoint *this)
{
  this->m_pointLeft = 0i64;
  this->m_pointRight = 0i64;
}

// File Line: 42
// RVA: 0xE2C5A0
hkpTyremarkPoint *__fastcall hkpTyremarksWheel::getTyremarkPoint(hkpTyremarksWheel *this, int point)
{
  return &this->m_tyremarkPoints.m_data[(point + this->m_currentPosition) % this->m_numPoints];
}

// File Line: 50
// RVA: 0xE2C460
float __fastcall hkpTyremarkPoint::getTyremarkStrength(hkpTyremarkPoint *this)
{
  return this->m_pointRight.m_quad.m128_f32[3];
}

// File Line: 55
// RVA: 0xE2C530
void __fastcall hkpTyremarksWheel::addTyremarkPoint(hkpTyremarksWheel *this, hkpTyremarkPoint *point)
{
  __int64 m_currentPosition; // r10
  hkpTyremarkPoint *m_data; // r11
  __int64 v4; // rax

  m_currentPosition = this->m_currentPosition;
  m_data = this->m_tyremarkPoints.m_data;
  if ( _mm_shuffle_ps(point->m_pointRight.m_quad, point->m_pointRight.m_quad, 255).m128_f32[0] != 0.0
    || (v4 = ((int)m_currentPosition + this->m_numPoints - 1) % this->m_numPoints,
        _mm_shuffle_ps(m_data[v4].m_pointRight.m_quad, m_data[v4].m_pointRight.m_quad, 255).m128_f32[0] != 0.0) )
  {
    m_data[m_currentPosition] = *point;
    this->m_currentPosition = (this->m_currentPosition + 1) % this->m_numPoints;
  }
}

// File Line: 71
// RVA: 0xE2C8C0
void __fastcall hkpTyremarksInfo::hkpTyremarksInfo(hkpTyremarksInfo *this, hkpVehicleData *data, int num_points)
{
  int m_numWheels; // ebx
  int v4; // eax
  int v7; // eax
  int v8; // r9d
  int v9; // ebp
  __int64 v10; // rsi
  _QWORD **Value; // rax
  hkpTyremarksWheel *v12; // rax
  hkpTyremarksWheel *v13; // rax
  hkpTyremarksWheel *v14; // rbx
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpTyremarksInfo::`vftable;
  this->m_tyremarksWheel.m_data = 0i64;
  this->m_tyremarksWheel.m_size = 0;
  this->m_tyremarksWheel.m_capacityAndFlags = 0x80000000;
  *(_QWORD *)&this->m_minTyremarkEnergy = 0i64;
  m_numWheels = data->m_numWheels;
  v4 = this->m_tyremarksWheel.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < m_numWheels )
  {
    v7 = 2 * v4;
    v8 = data->m_numWheels;
    if ( m_numWheels < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_tyremarksWheel.m_data,
      v8,
      8);
  }
  this->m_tyremarksWheel.m_size = m_numWheels;
  v9 = 0;
  if ( m_numWheels > 0 )
  {
    v10 = 0i64;
    do
    {
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v12 = (hkpTyremarksWheel *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
      if ( v12 )
      {
        hkpTyremarksWheel::hkpTyremarksWheel(v12);
        v14 = v13;
      }
      else
      {
        v14 = 0i64;
      }
      hkpTyremarksWheel::setNumPoints(v14, num_points);
      ++v9;
      this->m_tyremarksWheel.m_data[v10++] = v14;
    }
    while ( v9 < this->m_tyremarksWheel.m_size );
  }
}

// File Line: 85
// RVA: 0xE2C9C0
void __fastcall hkpTyremarksInfo::~hkpTyremarksInfo(hkpTyremarksInfo *this)
{
  int v1; // esi
  __int64 v3; // rdi
  int m_capacityAndFlags; // r8d

  v1 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpTyremarksInfo::`vftable;
  if ( this->m_tyremarksWheel.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_tyremarksWheel.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_tyremarksWheel.m_size );
  }
  m_capacityAndFlags = this->m_tyremarksWheel.m_capacityAndFlags;
  this->m_tyremarksWheel.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_tyremarksWheel.m_data,
      8 * m_capacityAndFlags);
  this->m_tyremarksWheel.m_data = 0i64;
  this->m_tyremarksWheel.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 94
// RVA: 0xE2C5C0
void __fastcall hkpTyremarksInfo::updateTyremarksInfo(
        hkpTyremarksInfo *this,
        float timestep,
        hkpVehicleInstance *vehicle)
{
  hkpEntity *m_entity; // rdx
  __m128 v6; // xmm13
  hkpVehicleData *m_data; // r8
  int v8; // ebp
  __int64 v9; // r14
  __int64 v10; // rsi
  __m128 v11; // xmm14
  hkpVehicleInstance::WheelInfo *v12; // rdx
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm3
  __m128 v16; // xmm0
  __m128 v17; // xmm11
  __m128 m_width_low; // xmm10
  __m128 v19; // xmm8
  __m128 v20; // xmm10
  __m128 v21; // xmm9
  hkpTyremarksWheel *v22; // rcx
  __m128 v23; // xmm10
  hkVector4f v24; // [rsp+20h] [rbp-D8h] BYREF
  hkpTyremarkPoint point; // [rsp+30h] [rbp-C8h] BYREF

  m_entity = vehicle->m_entity;
  v6 = _mm_mul_ps(
         _mm_shuffle_ps((__m128)LODWORD(timestep), (__m128)LODWORD(timestep), 0),
         m_entity->m_motion.m_linearVelocity.m_quad);
  hkVector4f::setRotatedDir(
    &v24,
    &m_entity->m_motion.m_motionState.m_transform.m_rotation,
    &vehicle->m_data->m_chassisOrientation.m_col2);
  m_data = vehicle->m_data;
  v8 = 0;
  if ( m_data->m_numWheels > 0 )
  {
    v9 = 0i64;
    v10 = 0i64;
    v11 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_050000001), (__m128)LODWORD(FLOAT_0_050000001), 0);
    do
    {
      v12 = vehicle->m_wheelsInfo.m_data;
      v13 = _mm_shuffle_ps((__m128)LODWORD(this->m_minTyremarkEnergy), (__m128)LODWORD(this->m_minTyremarkEnergy), 0);
      v14 = _mm_sub_ps(
              _mm_shuffle_ps(
                (__m128)LODWORD(v12[v10].m_skidEnergyDensity),
                (__m128)LODWORD(v12[v10].m_skidEnergyDensity),
                0),
              v13);
      if ( v14.m128_f32[0] <= 0.0 )
      {
        v17 = 0i64;
      }
      else
      {
        v15 = _mm_sub_ps(
                _mm_shuffle_ps(
                  (__m128)LODWORD(this->m_maxTyremarkEnergy),
                  (__m128)LODWORD(this->m_maxTyremarkEnergy),
                  0),
                v13);
        v16 = _mm_rcp_ps(v15);
        v17 = _mm_min_ps(
                _mm_mul_ps(
                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v15, v16)), v16),
                  _mm_mul_ps(v14, (__m128)xmmword_141A71160)),
                (__m128)xmmword_141A71160);
      }
      m_width_low = (__m128)LODWORD(m_data->m_wheelParams.m_data[v8].m_width);
      v19 = _mm_add_ps(
              _mm_mul_ps(v12[v10].m_contactPoint.m_separatingNormal.m_quad, v11),
              v12[v10].m_contactPoint.m_position.m_quad);
      v20 = _mm_shuffle_ps(m_width_low, m_width_low, 0);
      v21 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, (__m128)xmmword_141A711B0), v20), v24.m_quad),
                v19),
              v6);
      hkpTyremarkPoint::hkpTyremarkPoint(&point);
      v22 = this->m_tyremarksWheel.m_data[v9];
      v23 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_mul_ps(v20, (__m128)xmmword_141A711B0), v24.m_quad), v19), v6);
      point.m_pointLeft.m_quad = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, v17), 196);
      point.m_pointRight.m_quad = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, v17), 196);
      hkpTyremarksWheel::addTyremarkPoint(v22, &point);
      m_data = vehicle->m_data;
      ++v8;
      ++v10;
      ++v9;
    }
    while ( v8 < m_data->m_numWheels );
  }
}

// File Line: 170
// RVA: 0xE2C830
void __fastcall hkpTyremarksInfo::getWheelTyremarksStrips(
        hkpTyremarksInfo *this,
        hkpVehicleInstance *vehicle,
        int wheel,
        hkVector4f *strips_out)
{
  int v4; // esi
  hkpTyremarksWheel *v5; // r14
  hkVector4f *v6; // rbx
  __int64 m_numPoints; // rbp
  hkVector4f *v8; // rdi
  hkpTyremarkPoint *TyremarkPoint; // rax

  v4 = 0;
  v5 = this->m_tyremarksWheel.m_data[wheel];
  v6 = strips_out;
  m_numPoints = v5->m_numPoints;
  if ( m_numPoints > 0 )
  {
    v8 = strips_out + 1;
    do
    {
      TyremarkPoint = hkpTyremarksWheel::getTyremarkPoint(v5, v4++);
      v8 += 2;
      v6 += 2;
      v6[-2] = TyremarkPoint->m_pointLeft;
      v8[-2] = TyremarkPoint->m_pointRight;
      --m_numPoints;
    }
    while ( m_numPoints );
  }
}

