// File Line: 16
// RVA: 0xE2C470
void __fastcall hkpTyremarksWheel::hkpTyremarksWheel(hkpTyremarksWheel *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpTyremarksWheel::`vftable;
  this->m_tyremarkPoints.m_capacityAndFlags = 2147483648;
  this->m_tyremarkPoints.m_data = 0i64;
  *(_QWORD *)&this->m_currentPosition = 0i64;
  this->m_tyremarkPoints.m_size = 0;
}

// File Line: 23
// RVA: 0xE2C4A0
void __fastcall hkpTyremarksWheel::setNumPoints(hkpTyremarksWheel *this, int num_points)
{
  int v2; // edi
  hkpTyremarksWheel *v3; // rsi
  signed __int64 v4; // rax
  hkVector4f v5; // xmm1
  hkpTyremarkPoint v6; // [rsp+20h] [rbp-28h]

  v2 = 0;
  v3 = this;
  this->m_numPoints = num_points;
  this->m_currentPosition = 0;
  if ( num_points > 0 )
  {
    do
    {
      hkpTyremarkPoint::hkpTyremarkPoint(&v6);
      if ( v3->m_tyremarkPoints.m_size == (v3->m_tyremarkPoints.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v3->m_tyremarkPoints,
          32);
      v4 = (signed __int64)&v3->m_tyremarkPoints.m_data[v3->m_tyremarkPoints.m_size];
      if ( v4 )
      {
        v5.m_quad = (__m128)v6.m_pointRight;
        *(hkVector4f *)v4 = v6.m_pointLeft;
        *(hkVector4f *)(v4 + 16) = (hkVector4f)v5.m_quad;
      }
      ++v3->m_tyremarkPoints.m_size;
      ++v2;
    }
    while ( v2 < v3->m_numPoints );
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
  signed __int64 v2; // r10
  hkpTyremarkPoint *v3; // r11
  signed __int64 v4; // rax
  signed __int64 v5; // rax

  v2 = this->m_currentPosition;
  v3 = this->m_tyremarkPoints.m_data;
  if ( COERCE_FLOAT(_mm_shuffle_ps(point->m_pointRight.m_quad, point->m_pointRight.m_quad, 255)) != 0.0
    || (v4 = ((signed int)v2 + this->m_numPoints - 1) % this->m_numPoints,
        COERCE_FLOAT(_mm_shuffle_ps(v3[v4].m_pointRight.m_quad, v3[v4].m_pointRight.m_quad, 255)) != 0.0) )
  {
    v5 = v2;
    v3[v5].m_pointLeft = point->m_pointLeft;
    v3[v5].m_pointRight = point->m_pointRight;
    this->m_currentPosition = (this->m_currentPosition + 1) % this->m_numPoints;
  }
}

// File Line: 71
// RVA: 0xE2C8C0
void __fastcall hkpTyremarksInfo::hkpTyremarksInfo(hkpTyremarksInfo *this, hkpVehicleData *data, int num_points)
{
  int v3; // ebx
  int v4; // eax
  int v5; // er15
  hkpTyremarksInfo *v6; // rdi
  int v7; // eax
  int v8; // er9
  int v9; // ebp
  __int64 v10; // rsi
  _QWORD **v11; // rax
  hkpTyremarksWheel *v12; // rax
  hkpTyremarksWheel *v13; // rax
  hkpTyremarksWheel *v14; // rbx
  hkResult result; // [rsp+60h] [rbp+8h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpTyremarksInfo::`vftable;
  this->m_tyremarksWheel.m_data = 0i64;
  this->m_tyremarksWheel.m_size = 0;
  this->m_tyremarksWheel.m_capacityAndFlags = 2147483648;
  *(_QWORD *)&this->m_minTyremarkEnergy = 0i64;
  v3 = data->m_numWheels;
  v4 = this->m_tyremarksWheel.m_capacityAndFlags & 0x3FFFFFFF;
  v5 = num_points;
  v6 = this;
  if ( v4 < v3 )
  {
    v7 = 2 * v4;
    v8 = data->m_numWheels;
    if ( v3 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_tyremarksWheel,
      v8,
      8);
  }
  v6->m_tyremarksWheel.m_size = v3;
  v9 = 0;
  if ( v3 > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v12 = (hkpTyremarksWheel *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(v11[11], 40i64);
      if ( v12 )
      {
        hkpTyremarksWheel::hkpTyremarksWheel(v12);
        v14 = v13;
      }
      else
      {
        v14 = 0i64;
      }
      hkpTyremarksWheel::setNumPoints(v14, v5);
      ++v9;
      v6->m_tyremarksWheel.m_data[v10] = v14;
      ++v10;
    }
    while ( v9 < v6->m_tyremarksWheel.m_size );
  }
}

// File Line: 85
// RVA: 0xE2C9C0
void __fastcall hkpTyremarksInfo::~hkpTyremarksInfo(hkpTyremarksInfo *this)
{
  int v1; // esi
  hkpTyremarksInfo *v2; // rbx
  __int64 v3; // rdi
  int v4; // er8

  v1 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpTyremarksInfo::`vftable;
  v2 = this;
  if ( this->m_tyremarksWheel.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_tyremarksWheel.m_data[v3]->vfptr);
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_tyremarksWheel.m_size );
  }
  v4 = v2->m_tyremarksWheel.m_capacityAndFlags;
  v2->m_tyremarksWheel.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_tyremarksWheel.m_data,
      8 * v4);
  v2->m_tyremarksWheel.m_data = 0i64;
  v2->m_tyremarksWheel.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 94
// RVA: 0xE2C5C0
void __fastcall hkpTyremarksInfo::updateTyremarksInfo(hkpTyremarksInfo *this, float timestep, hkpVehicleInstance *vehicle)
{
  hkpEntity *v3; // rdx
  hkpVehicleInstance *v4; // rdi
  hkpTyremarksInfo *v5; // rbx
  __m128 v6; // xmm13
  hkpVehicleData *v7; // r8
  signed int v8; // ebp
  __int64 v9; // r14
  __int64 v10; // rsi
  __m128 v11; // xmm14
  hkpVehicleInstance::WheelInfo *v12; // rdx
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm3
  __m128 v16; // xmm0
  __m128 v17; // xmm11
  __m128 v18; // xmm10
  __m128 v19; // xmm8
  __m128 v20; // xmm10
  __m128 v21; // xmm9
  hkpTyremarksWheel *v22; // rcx
  __m128 v23; // xmm10
  hkVector4f v24; // [rsp+20h] [rbp-D8h]
  hkpTyremarkPoint point; // [rsp+30h] [rbp-C8h]

  v3 = vehicle->m_entity;
  v4 = vehicle;
  v5 = this;
  v6 = _mm_mul_ps(
         _mm_shuffle_ps((__m128)LODWORD(timestep), (__m128)LODWORD(timestep), 0),
         v3->m_motion.m_linearVelocity.m_quad);
  hkVector4f::setRotatedDir(
    &v24,
    (hkMatrix3f *)&v3->m_motion.m_motionState.m_transform.m_rotation.m_col0,
    &vehicle->m_data->m_chassisOrientation.m_col2);
  v7 = v4->m_data;
  v8 = 0;
  if ( v7->m_numWheels > 0 )
  {
    v9 = 0i64;
    v10 = 0i64;
    v11 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_050000001), (__m128)LODWORD(FLOAT_0_050000001), 0);
    do
    {
      v12 = v4->m_wheelsInfo.m_data;
      v13 = _mm_shuffle_ps((__m128)LODWORD(v5->m_minTyremarkEnergy), (__m128)LODWORD(v5->m_minTyremarkEnergy), 0);
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
                _mm_shuffle_ps((__m128)LODWORD(v5->m_maxTyremarkEnergy), (__m128)LODWORD(v5->m_maxTyremarkEnergy), 0),
                v13);
        v16 = _mm_rcp_ps(v15);
        v17 = _mm_min_ps(
                _mm_mul_ps(
                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v15, v16)), v16),
                  _mm_mul_ps(v14, (__m128)xmmword_141A71160)),
                (__m128)xmmword_141A71160);
      }
      v18 = (__m128)LODWORD(v7->m_wheelParams.m_data[v8].m_width);
      v19 = _mm_add_ps(
              _mm_mul_ps(v12[v10].m_contactPoint.m_separatingNormal.m_quad, v11),
              v12[v10].m_contactPoint.m_position.m_quad);
      v20 = _mm_shuffle_ps(v18, v18, 0);
      v21 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, (__m128)xmmword_141A711B0), v20), v24.m_quad),
                v19),
              v6);
      hkpTyremarkPoint::hkpTyremarkPoint(&point);
      v22 = v5->m_tyremarksWheel.m_data[v9];
      v23 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_mul_ps(v20, (__m128)xmmword_141A711B0), v24.m_quad), v19), v6);
      point.m_pointLeft.m_quad = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, v17), 196);
      point.m_pointRight.m_quad = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, v17), 196);
      hkpTyremarksWheel::addTyremarkPoint(v22, &point);
      v7 = v4->m_data;
      ++v8;
      ++v10;
      ++v9;
    }
    while ( v8 < v7->m_numWheels );
  }
}

// File Line: 170
// RVA: 0xE2C830
void __fastcall hkpTyremarksInfo::getWheelTyremarksStrips(hkpTyremarksInfo *this, hkpVehicleInstance *vehicle, int wheel, hkVector4f *strips_out)
{
  int v4; // esi
  hkpTyremarksWheel *v5; // r14
  hkVector4f *v6; // rbx
  __int64 v7; // rbp
  hkVector4f *v8; // rdi
  hkpTyremarkPoint *v9; // rax

  v4 = 0;
  v5 = this->m_tyremarksWheel.m_data[wheel];
  v6 = strips_out;
  v7 = v5->m_numPoints;
  if ( v7 > 0 )
  {
    v8 = strips_out + 1;
    do
    {
      v9 = hkpTyremarksWheel::getTyremarkPoint(v5, v4++);
      v8 += 2;
      v6 += 2;
      v6[-2] = v9->m_pointLeft;
      v8[-2] = v9->m_pointRight;
      --v7;
    }
    while ( v7 );
  }
}

