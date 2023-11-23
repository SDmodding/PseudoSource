// File Line: 39
// RVA: 0xD16020
void __fastcall hkpSampledHeightFieldShape::hkpSampledHeightFieldShape(
        hkpSampledHeightFieldShape *this,
        hkpSampledHeightFieldBaseCinfo *ci,
        hkpSampledHeightFieldShape::HeightFieldType hfType)
{
  __m128 m_maxHeight_low; // xmm3
  __m128 v5; // xmm0
  __m128 v6; // xmm4
  hkVector4f v7; // xmm5
  float m_minHeight; // xmm0_4
  __m128i v9; // xmm3
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  float out; // [rsp+50h] [rbp+18h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1036;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSampledHeightFieldShape::`vftable;
  this->m_coarseTreeData.m_data = 0i64;
  this->m_coarseTreeData.m_size = 0;
  this->m_coarseTreeData.m_capacityAndFlags = 0x80000000;
  this->m_heightfieldType.m_storage = hfType;
  this->m_xRes = ci->m_xRes;
  this->m_zRes = ci->m_zRes;
  this->m_useProjectionBasedHeight.m_bool = ci->m_useProjectionBasedHeight.m_bool;
  m_maxHeight_low = (__m128)LODWORD(ci->m_maxHeight);
  m_maxHeight_low.m128_f32[0] = m_maxHeight_low.m128_f32[0] - ci->m_minHeight;
  v5 = (__m128)COERCE_UNSIGNED_INT((float)ci->m_zRes);
  v6 = (__m128)COERCE_UNSIGNED_INT((float)ci->m_xRes);
  v5.m128_f32[0] = v5.m128_f32[0] - 1.0;
  v6.m128_f32[0] = v6.m128_f32[0] - 1.0;
  v7.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v6, v5), _mm_unpacklo_ps(m_maxHeight_low, (__m128)0i64));
  this->m_extents = (hkVector4f)v7.m_quad;
  this->m_extents.m_quad = _mm_mul_ps(v7.m_quad, ci->m_scale.m_quad);
  m_minHeight = ci->m_minHeight;
  if ( m_minHeight <= ci->m_maxHeight )
  {
    this->m_raycastMinY = m_minHeight;
    this->m_raycastMaxY = ci->m_maxHeight;
    this->m_heightCenter = (float)((float)(ci->m_minHeight + ci->m_maxHeight) * 0.5) * ci->m_scale.m_quad.m128_f32[1];
  }
  else
  {
    this->m_raycastMinY = -3.40282e38;
    this->m_raycastMaxY = 3.40282e38;
    this->m_heightCenter = -1.0;
    this->m_extents.m_quad.m128_i32[1] = -1082130432;
  }
  this->m_intToFloatScale = ci->m_scale;
  v9 = (__m128i)_mm_shuffle_ps(ci->m_scale.m_quad, _mm_unpackhi_ps(ci->m_scale.m_quad, query.m_quad), 196);
  v10 = _mm_cmpeq_ps((__m128)0i64, (__m128)v9);
  this->m_floatToIntScale.m_quad = _mm_or_ps(
                                     _mm_and_ps(
                                       _mm_xor_ps(
                                         (__m128)_mm_slli_epi32(_mm_srli_epi32(v9, 0x1Fu), 0x1Fu),
                                         (__m128)_xmm),
                                       v10),
                                     _mm_andnot_ps(v10, _mm_div_ps(query.m_quad, (__m128)v9)));
  hkVector4UtilImpl<float>::getFloatToInt16FloorCorrection(&out);
  this->m_coarseness = 0;
  v11 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(out), (__m128)LODWORD(out), 0), this->m_intToFloatScale.m_quad);
  this->m_floatToIntOffsetFloorCorrected.m_quad = _mm_shuffle_ps(_mm_unpacklo_ps(v11, (__m128)0i64), v11, 228);
}

// File Line: 84
// RVA: 0xD161A0
void __fastcall hkpSampledHeightFieldShape::hkpSampledHeightFieldShape(
        hkpSampledHeightFieldShape *this,
        hkFinishLoadedObjectFlag flag)
{
  hkpShape::hkpShape(this, flag);
  this->m_type.m_storage = 28;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSampledHeightFieldShape::`vftable;
  if ( flag.m_finishing )
    this->m_type.m_storage = 12;
}

// File Line: 92
// RVA: 0xD161E0
void __fastcall hkpSampledHeightFieldShape::~hkpSampledHeightFieldShape(hkpSampledHeightFieldShape *this)
{
  int m_size; // eax
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *m_data; // rcx
  int v4; // eax
  __int64 v5; // rdi
  int *v6; // rbx
  int v7; // r8d
  int m_capacityAndFlags; // eax

  this->vfptr = (hkBaseObjectVtbl *)&hkpSampledHeightFieldShape::`vftable;
  m_size = this->m_coarseTreeData.m_size;
  m_data = this->m_coarseTreeData.m_data;
  v4 = m_size - 1;
  v5 = v4;
  if ( v4 >= 0 )
  {
    v6 = &m_data->m_minMaxData.m_capacityAndFlags + 6 * v4;
    do
    {
      v7 = *v6;
      *(v6 - 1) = 0;
      if ( v7 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v6 - 3),
          16 * v7);
      *(_QWORD *)(v6 - 3) = 0i64;
      *v6 = 0x80000000;
      v6 -= 6;
      --v5;
    }
    while ( v5 >= 0 );
  }
  m_capacityAndFlags = this->m_coarseTreeData.m_capacityAndFlags;
  this->m_coarseTreeData.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_coarseTreeData.m_data,
      24 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_coarseTreeData.m_data = 0i64;
  this->m_coarseTreeData.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 95
// RVA: 0xD16570
void __fastcall hkpSampledHeightFieldShape::collideSpheres(
        hkpSampledHeightFieldShape *this,
        hkpHeightFieldShape::CollideSpheresInput *input,
        hkVector4f *outputArray)
{
  hkErrStream v3; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  hkErrStream::hkErrStream(&v3, buf, 512);
  hkOstream::operator<<(&v3, "You must implement collideSpheres!");
  hkError::messageWarning(
    0x4B50036Au,
    buf,
    "Shape\\HeightField\\SampledHeightField\\hkpSampledHeightFieldShape.cpp",
    96);
  hkOstream::~hkOstream(&v3);
}

// File Line: 100
// RVA: 0xD16710
float __fastcall hkpSampledHeightFieldShape::getHeightAtImpl(hkpSampledHeightFieldShape *this, int x, int z)
{
  hkErrStream v4; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  hkErrStream::hkErrStream(&v4, buf, 512);
  hkOstream::operator<<(&v4, "You must implement getHeightAtImpl!");
  hkError::messageWarning(
    0x4B50036Bu,
    buf,
    "Shape\\HeightField\\SampledHeightField\\hkpSampledHeightFieldShape.cpp",
    101);
  hkOstream::~hkOstream(&v4);
  return 0.0;
}

// File Line: 106
// RVA: 0xD16780
hkBool *__fastcall hkpSampledHeightFieldShape::getTriangleFlipImpl(hkpSampledHeightFieldShape *this, hkBool *result)
{
  hkErrStream v4; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  hkErrStream::hkErrStream(&v4, buf, 512);
  hkOstream::operator<<(&v4, "You must implement getTriangleFlipImpl!");
  hkError::messageWarning(
    0x4B50036Cu,
    buf,
    "Shape\\HeightField\\SampledHeightField\\hkpSampledHeightFieldShape.cpp",
    107);
  hkOstream::~hkOstream(&v4);
  result->m_bool = 0;
  return result;
}

// File Line: 114
// RVA: 0xD162C0
void __fastcall hkpSampledHeightFieldShape::getCinfo(
        hkpSampledHeightFieldShape *this,
        hkpSampledHeightFieldBaseCinfo *cinfo)
{
  ;
}

// File Line: 119
// RVA: 0xD16340
void __fastcall hkpSampledHeightFieldShape::getAabb(
        hkpSampledHeightFieldShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  double v7; // xmm0_8
  float v8; // xmm6_4
  float v9; // xmm7_4
  int i; // esi
  int j; // edi
  float v12; // xmm0_4
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  __m128 v17; // xmm2
  __m128 v18; // xmm6
  __m128 v19; // xmm2
  __m128 v20; // [rsp+20h] [rbp-58h]

  v7 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
         this,
         0i64,
         0i64);
  v8 = *(float *)&v7;
  v9 = *(float *)&v7;
  if ( this->m_extents.m_quad.m128_f32[1] < 0.0 )
  {
    for ( i = 0; i < this->m_xRes; ++i )
    {
      for ( j = 0; j < this->m_zRes; v9 = fmaxf(v9, v12) )
      {
        v12 = ((float (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
                this,
                (unsigned int)i,
                (unsigned int)j++);
        v8 = fminf(v8, v12);
      }
    }
    this->m_raycastMinY = v8;
    this->m_raycastMaxY = v9;
    v13 = v8 * this->m_intToFloatScale.m_quad.m128_f32[1];
    v14 = v9 * this->m_intToFloatScale.m_quad.m128_f32[1];
    v15 = fminf(v13, v14);
    v16 = fmaxf(v13, v14);
    this->m_heightCenter = (float)(v16 + v15) * 0.5;
    this->m_extents.m_quad.m128_f32[1] = v16 - v15;
  }
  v17 = _mm_mul_ps(this->m_extents.m_quad, (__m128)xmmword_141A711B0);
  v20 = v17;
  v20.m128_i32[1] = LODWORD(this->m_heightCenter);
  v18 = _mm_add_ps(
          _mm_add_ps(
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32(
                        (__m128i)_mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), localToWorld->m_rotation.m_col0.m_quad),
                        1u),
                      1u),
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32(
                        (__m128i)_mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), localToWorld->m_rotation.m_col1.m_quad),
                        1u),
                      1u)),
          _mm_add_ps(
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32(
                        (__m128i)_mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), localToWorld->m_rotation.m_col2.m_quad),
                        1u),
                      1u),
            _mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0)));
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), localToWorld->m_rotation.m_col0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), localToWorld->m_rotation.m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), localToWorld->m_rotation.m_col2.m_quad)),
          localToWorld->m_translation.m_quad);
  out->m_max.m_quad = _mm_add_ps(v19, v18);
  out->m_min.m_quad = _mm_add_ps(
                        _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v18),
                        v19);
}

// File Line: 185
// RVA: 0xD167F0
void __fastcall hkpSampledHeightFieldShape::getHeightAndNormalAt(
        hkpSampledHeightFieldShape *this,
        unsigned int xPos,
        unsigned int zPos,
        float subX,
        float subZ,
        hkVector4f *normalOut,
        float *heightOut,
        int *triangleIndexOut)
{
  hkVector4f *v8; // rdi
  hkBaseObjectVtbl *vfptr; // rax
  double v13; // xmm0_8
  float v14; // xmm9_4
  double v15; // xmm0_8
  hkBaseObjectVtbl *v16; // rax
  float v17; // xmm6_4
  double v18; // xmm0_8
  float v19; // xmm6_4
  double v20; // xmm0_8
  float v21; // xmm6_4
  double v22; // xmm0_8
  float v23; // xmm6_4
  double v24; // xmm0_8
  hkBaseObjectVtbl *v25; // rax
  float v26; // xmm8_4
  double v27; // xmm0_8
  float v28; // xmm0_4
  float v29; // xmm8_4
  int *v30; // rax

  v8 = normalOut;
  normalOut->m_quad = _mm_shuffle_ps(*(__m128 *)_xmm, _mm_unpackhi_ps(*(__m128 *)_xmm, normalOut->m_quad), 196);
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkVector4f **))this->vfptr[10].__first_virtual_table_function__)(
    this,
    &normalOut);
  vfptr = this->vfptr;
  if ( (_BYTE)normalOut )
  {
    v13 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))vfptr[10].__vecDelDtor)(
            this,
            xPos,
            zPos);
    v14 = *(float *)&v13;
    v15 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
            this,
            xPos + 1,
            zPos + 1);
    v16 = this->vfptr;
    v17 = *(float *)&v15;
    if ( subX > subZ )
    {
      v18 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v16[10].__vecDelDtor)(
              this,
              xPos + 1,
              zPos);
      v19 = v17 - *(float *)&v18;
      *heightOut = (float)((float)(v19 * subZ) + v14) + (float)((float)(*(float *)&v18 - v14) * subX);
      v8->m_quad.m128_i32[0] = COERCE_UNSIGNED_INT(*(float *)&v18 - v14) ^ _xmm[0];
      v8->m_quad.m128_i32[2] = LODWORD(v19) ^ _xmm[0];
      *triangleIndexOut = 1;
      return;
    }
    v20 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v16[10].__vecDelDtor)(
            this,
            xPos,
            zPos + 1);
    v21 = v17 - *(float *)&v20;
    *heightOut = (float)((float)((float)(*(float *)&v20 - v14) * subZ) + v14) + (float)(v21 * subX);
    v8->m_quad.m128_i32[2] = COERCE_UNSIGNED_INT(*(float *)&v20 - v14) ^ _xmm[0];
  }
  else
  {
    v22 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))vfptr[10].__vecDelDtor)(
            this,
            xPos + 1,
            zPos);
    v23 = *(float *)&v22;
    v24 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
            this,
            xPos,
            zPos + 1);
    v25 = this->vfptr;
    v26 = *(float *)&v24;
    if ( (float)(subX + subZ) > 1.0 )
    {
      v27 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v25[10].__vecDelDtor)(
              this,
              xPos + 1,
              zPos + 1);
      *heightOut = (float)((float)((float)(*(float *)&v27 - v23) * subZ) + v23)
                 + (float)((float)(subX - 1.0) * (float)(*(float *)&v27 - v26));
      v8->m_quad.m128_i32[0] = COERCE_UNSIGNED_INT(*(float *)&v27 - v26) ^ _xmm[0];
      v8->m_quad.m128_i32[2] = COERCE_UNSIGNED_INT(*(float *)&v27 - v23) ^ _xmm[0];
      *triangleIndexOut = 1;
      return;
    }
    v28 = ((float (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v25[10].__vecDelDtor)(this, xPos, zPos);
    v29 = v26 - v28;
    v21 = v23 - v28;
    *heightOut = (float)((float)(v29 * subZ) + v28) + (float)(v21 * subX);
    v8->m_quad.m128_i32[2] = LODWORD(v29) ^ _xmm[0];
  }
  v30 = triangleIndexOut;
  v8->m_quad.m128_i32[0] = LODWORD(v21) ^ _xmm[0];
  *v30 = 0;
}

// File Line: 191
// RVA: 0xD162D0
void __fastcall hkpSampledHeightFieldShape::getCoarseMinMax(
        hkpSampledHeightFieldShape *this,
        int level,
        int x,
        int z,
        hkVector4f *minOut,
        hkVector4f *maxOut)
{
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *v6; // r10
  int m_zRes; // eax
  __int64 v8; // rdx

  v6 = &this->m_coarseTreeData.m_data[level - this->m_coarseness];
  if ( x < v6->m_xRes )
  {
    m_zRes = v6->m_zRes;
    if ( z < m_zRes )
    {
      v8 = 2 * (z + x * m_zRes);
      *minOut = v6->m_minMaxData.m_data[v8];
      *maxOut = v6->m_minMaxData.m_data[v8 + 1];
    }
  }
}

// File Line: 214
// RVA: 0xD16A90
void __fastcall `anonymous namespace::NearestHitCollector::addRayHit(
        NearestHitCollector *this,
        hkpCdBody *cdBody,
        hkpShapeRayCastCollectorOutput *hitInfoIn)
{
  float m_hitFraction; // xmm0_4
  hkpShapeRayCastOutput *m_output; // rax

  m_hitFraction = hitInfoIn->m_hitFraction;
  if ( m_hitFraction < this->m_earlyOutHitFraction )
  {
    m_output = this->m_output;
    this->m_earlyOutHitFraction = m_hitFraction;
    m_output->m_normal = hitInfoIn->m_normal;
    this->m_output->m_hitFraction = hitInfoIn->m_hitFraction;
    this->m_output->m_extraInfo = hitInfoIn->m_extraInfo;
    this->m_output->m_shapeKeys[this->m_output->m_shapeKeyIndex] = -1;
    this->m_hasHit.m_bool = 1;
  }
}

// File Line: 242
// RVA: 0xD16AE0
void __fastcall `anonymous namespace::RotateNormalHitCollector::addRayHit(
        RotateNormalHitCollector *this,
        hkpCdBody *cdBody,
        hkpShapeRayCastCollectorOutput *hitIn)
{
  hkVector4f v3; // xmm0
  __m128 *m_motion; // rax
  hkpRayHitCollector *m_collector; // rcx
  __int128 v7[2]; // [rsp+20h] [rbp-28h] BYREF

  v3.m_quad = (__m128)hitIn->m_normal;
  m_motion = (__m128 *)cdBody->m_motion;
  m_collector = this->m_collector;
  v7[1] = *(_OWORD *)&hitIn->m_hitFraction;
  v7[0] = (__int128)v3.m_quad;
  v7[0] = (__int128)_mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 85), m_motion[1]),
                        _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 0), *m_motion)),
                      _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 170), m_motion[2]));
  m_collector->vfptr->addRayHit(m_collector, cdBody, (hkpShapeRayCastCollectorOutput *)v7);
  this->m_earlyOutHitFraction = this->m_collector->m_earlyOutHitFraction;
}

// File Line: 253
// RVA: 0xD16670
hkBool *__fastcall hkpSampledHeightFieldShape::castRay(
        hkpSampledHeightFieldShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  float m_hitFraction; // xmm0_4
  hkpRayHitCollector v7; // [rsp+20h] [rbp-28h] BYREF
  char v8; // [rsp+30h] [rbp-18h]
  hkpShapeRayCastOutput *v9; // [rsp+38h] [rbp-10h]

  m_hitFraction = results->m_hitFraction;
  v9 = results;
  v7.m_earlyOutHitFraction = m_hitFraction;
  v7.vfptr = (hkpRayHitCollectorVtbl *)&`anonymous namespace::NearestHitCollector::`vftable;
  v8 = 0;
  hkpSampledHeightFieldShape::s_rayCastFunc(this, input, 0i64, &v7);
  result->m_bool = v8;
  return result;
}

// File Line: 262
// RVA: 0xD166D0
void __fastcall hkpSampledHeightFieldShape::castRayWithCollector(
        hkpSampledHeightFieldShape *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  float m_earlyOutHitFraction; // xmm0_4
  hkpRayHitCollector v5; // [rsp+20h] [rbp-28h] BYREF
  hkpRayHitCollector *v6; // [rsp+30h] [rbp-18h]

  m_earlyOutHitFraction = collector->m_earlyOutHitFraction;
  v6 = collector;
  v5.m_earlyOutHitFraction = m_earlyOutHitFraction;
  v5.vfptr = (hkpRayHitCollectorVtbl *)&`anonymous namespace::RotateNormalHitCollector::`vftable;
  hkpSampledHeightFieldShape::s_rayCastFunc(this, input, cdBody, &v5);
}

// File Line: 271
// RVA: 0xD165E0
void __fastcall hkpSampledHeightFieldShape::castSphere(
        hkpSampledHeightFieldShape *this,
        hkpHeightFieldShape::hkpSphereCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  hkVector4f v4; // xmm4
  __m128 v5; // xmm2
  hkVector4f v6; // xmm1
  __int128 v7; // xmm0
  __int128 v8; // xmm1
  __m128 v9; // xmm4
  __int128 v10; // xmm0
  hkVector4f v11; // xmm1
  hkVector4f v12; // xmm0
  hkpHeightFieldShape::hkpSphereCastInput v13; // [rsp+20h] [rbp-58h] BYREF

  v4.m_quad = (__m128)this->m_intToFloatScale;
  v5 = _mm_unpacklo_ps(_mm_xor_ps((__m128)LODWORD(input->m_radius), *(__m128 *)_xmm), (__m128)0i64);
  v6.m_quad = (__m128)input->m_to;
  v13.m_from = input->m_from;
  v7 = *(_OWORD *)&input->m_filterInfo;
  v13.m_to = (hkVector4f)v6.m_quad;
  v8 = *(_OWORD *)&input->m_collidable;
  *(_OWORD *)&v13.m_filterInfo = v7;
  v9 = _mm_xor_ps(
         (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_shuffle_ps(v4.m_quad, v4.m_quad, 85), 0x1Fu), 0x1Fu),
         _mm_unpacklo_ps((__m128)0i64, v5));
  v10 = *(_OWORD *)&input->m_radius;
  *(_OWORD *)&v13.m_collidable = v8;
  v11.m_quad = _mm_add_ps(input->m_from.m_quad, v9);
  *(_OWORD *)&v13.m_radius = v10;
  v12.m_quad = (__m128)input->m_to;
  v13.m_from = (hkVector4f)v11.m_quad;
  v13.m_to.m_quad = _mm_add_ps(v12.m_quad, v9);
  hkpSampledHeightFieldShape::s_sphereCastFunc(this, &v13, cdBody, collector);
}

