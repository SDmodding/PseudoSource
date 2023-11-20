// File Line: 39
// RVA: 0xD16020
void __fastcall hkpSampledHeightFieldShape::hkpSampledHeightFieldShape(hkpSampledHeightFieldShape *this, hkpSampledHeightFieldBaseCinfo *ci, hkpSampledHeightFieldShape::HeightFieldType hfType)
{
  hkpSampledHeightFieldShape *v3; // rbx
  __m128 v4; // xmm3
  __m128 v5; // xmm0
  __m128 v6; // xmm4
  hkVector4f v7; // xmm5
  float v8; // xmm0_4
  __m128i v9; // xmm3
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  float out; // [rsp+50h] [rbp+18h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1036;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSampledHeightFieldShape::`vftable;
  this->m_coarseTreeData.m_data = 0i64;
  this->m_coarseTreeData.m_size = 0;
  this->m_coarseTreeData.m_capacityAndFlags = 2147483648;
  this->m_heightfieldType.m_storage = hfType;
  this->m_xRes = ci->m_xRes;
  v3 = this;
  this->m_zRes = ci->m_zRes;
  this->m_useProjectionBasedHeight.m_bool = ci->m_useProjectionBasedHeight.m_bool;
  v4 = (__m128)LODWORD(ci->m_maxHeight);
  v4.m128_f32[0] = v4.m128_f32[0] - ci->m_minHeight;
  v5 = (__m128)COERCE_UNSIGNED_INT((float)ci->m_zRes);
  v6 = (__m128)COERCE_UNSIGNED_INT((float)ci->m_xRes);
  v5.m128_f32[0] = v5.m128_f32[0] - 1.0;
  v6.m128_f32[0] = v6.m128_f32[0] - 1.0;
  v7.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v6, v5), _mm_unpacklo_ps(v4, (__m128)0i64));
  this->m_extents = (hkVector4f)v7.m_quad;
  this->m_extents.m_quad = _mm_mul_ps(v7.m_quad, ci->m_scale.m_quad);
  v8 = ci->m_minHeight;
  if ( v8 <= ci->m_maxHeight )
  {
    this->m_raycastMinY = v8;
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
  v10 = _mm_cmpeqps((__m128)0i64, (__m128)v9);
  this->m_floatToIntScale.m_quad = _mm_or_ps(
                                     _mm_and_ps(
                                       _mm_xor_ps(
                                         (__m128)_mm_slli_epi32(_mm_srli_epi32(v9, 0x1Fu), 0x1Fu),
                                         (__m128)_xmm),
                                       v10),
                                     _mm_andnot_ps(v10, _mm_div_ps(query.m_quad, (__m128)v9)));
  hkVector4UtilImpl<float>::getFloatToInt16FloorCorrection(&out);
  v3->m_coarseness = 0;
  v11 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(out), (__m128)LODWORD(out), 0), v3->m_intToFloatScale.m_quad);
  v3->m_floatToIntOffsetFloorCorrected.m_quad = _mm_shuffle_ps(_mm_unpacklo_ps(v11, (__m128)0i64), v11, 228);
}

// File Line: 84
// RVA: 0xD161A0
void __fastcall hkpSampledHeightFieldShape::hkpSampledHeightFieldShape(hkpSampledHeightFieldShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpSampledHeightFieldShape *v2; // rbx
  int v3; // [rsp+38h] [rbp+10h]

  v3 = flag.m_finishing;
  v2 = this;
  hkpShape::hkpShape((hkpShape *)&this->vfptr, flag);
  v2->m_type.m_storage = 28;
  v2->vfptr = (hkBaseObjectVtbl *)&hkpSampledHeightFieldShape::`vftable;
  if ( v3 )
    v2->m_type.m_storage = 12;
}

// File Line: 92
// RVA: 0xD161E0
void __fastcall hkpSampledHeightFieldShape::~hkpSampledHeightFieldShape(hkpSampledHeightFieldShape *this)
{
  hkpSampledHeightFieldShape *v1; // rsi
  int v2; // eax
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *v3; // rcx
  int v4; // eax
  __int64 v5; // rdi
  int *v6; // rbx
  int v7; // er8
  int v8; // eax

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSampledHeightFieldShape::`vftable;
  v2 = this->m_coarseTreeData.m_size;
  v3 = this->m_coarseTreeData.m_data;
  v4 = v2 - 1;
  v5 = v4;
  if ( v4 >= 0 )
  {
    v6 = &v3->m_minMaxData.m_capacityAndFlags + 6 * v4;
    do
    {
      v7 = *v6;
      *(v6 - 1) = 0;
      if ( v7 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v6 - 3),
          16 * v7);
      *(_QWORD *)(v6 - 3) = 0i64;
      *v6 = 2147483648;
      v6 -= 6;
      --v5;
    }
    while ( v5 >= 0 );
  }
  v8 = v1->m_coarseTreeData.m_capacityAndFlags;
  v1->m_coarseTreeData.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_coarseTreeData.m_data,
      24 * (v8 & 0x3FFFFFFF));
  v1->m_coarseTreeData.m_data = 0i64;
  v1->m_coarseTreeData.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 95
// RVA: 0xD16570
void __fastcall hkpSampledHeightFieldShape::collideSpheres(hkpSampledHeightFieldShape *this, hkpHeightFieldShape::CollideSpheresInput *input, hkVector4f *outputArray)
{
  hkErrStream v3; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  hkErrStream::hkErrStream(&v3, &buf, 512);
  hkOstream::operator<<((hkOstream *)&v3.vfptr, "You must implement collideSpheres!");
  hkError::messageWarning(
    1263534954,
    &buf,
    "Shape\\HeightField\\SampledHeightField\\hkpSampledHeightFieldShape.cpp",
    96);
  hkOstream::~hkOstream((hkOstream *)&v3.vfptr);
}

// File Line: 100
// RVA: 0xD16710
float __fastcall hkpSampledHeightFieldShape::getHeightAtImpl(hkpSampledHeightFieldShape *this, int x, int z)
{
  hkErrStream v4; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  hkErrStream::hkErrStream(&v4, &buf, 512);
  hkOstream::operator<<((hkOstream *)&v4.vfptr, "You must implement getHeightAtImpl!");
  hkError::messageWarning(
    1263534955,
    &buf,
    "Shape\\HeightField\\SampledHeightField\\hkpSampledHeightFieldShape.cpp",
    101);
  hkOstream::~hkOstream((hkOstream *)&v4.vfptr);
  return 0.0;
}

// File Line: 106
// RVA: 0xD16780
hkBool *__fastcall hkpSampledHeightFieldShape::getTriangleFlipImpl(hkpSampledHeightFieldShape *this, hkBool *result)
{
  hkBool *v2; // rbx
  hkErrStream v4; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v2 = result;
  hkErrStream::hkErrStream(&v4, &buf, 512);
  hkOstream::operator<<((hkOstream *)&v4.vfptr, "You must implement getTriangleFlipImpl!");
  hkError::messageWarning(
    1263534956,
    &buf,
    "Shape\\HeightField\\SampledHeightField\\hkpSampledHeightFieldShape.cpp",
    107);
  hkOstream::~hkOstream((hkOstream *)&v4.vfptr);
  v2->m_bool = 0;
  return v2;
}

// File Line: 114
// RVA: 0xD162C0
void __fastcall hkpSampledHeightFieldShape::getCinfo(hkpSampledHeightFieldShape *this, hkpSampledHeightFieldBaseCinfo *cinfo)
{
  ;
}

// File Line: 119
// RVA: 0xD16340
void __usercall hkpSampledHeightFieldShape::getAabb(hkpSampledHeightFieldShape *this@<rcx>, hkTransformf *localToWorld@<rdx>, float tolerance@<xmm2>, hkAabb *out@<r9>, float a5@<xmm0>)
{
  hkTransformf *v5; // rbp
  hkAabb *v6; // r14
  hkpSampledHeightFieldShape *v7; // rbx
  float v8; // xmm6_4
  float v9; // xmm7_4
  int i; // esi
  int j; // edi
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  __m128 v16; // xmm2
  __m128 v17; // ST20_16
  __m128 v18; // xmm6
  __m128 v19; // xmm2
  float v20; // [rsp+90h] [rbp+18h]

  v20 = tolerance;
  v5 = localToWorld;
  v6 = out;
  v7 = this;
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(this, 0i64, 0i64);
  v8 = a5;
  v9 = a5;
  if ( v7->m_extents.m_quad.m128_f32[1] < 0.0 )
  {
    for ( i = 0; i < v7->m_xRes; ++i )
    {
      for ( j = 0; j < v7->m_zRes; v9 = fmaxf(v9, 0.0) )
      {
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v7->vfptr[10].__vecDelDtor)(
          v7,
          (unsigned int)i,
          (unsigned int)j++);
        v8 = fminf(v8, 0.0);
      }
    }
    v7->m_raycastMinY = v8;
    v7->m_raycastMaxY = v9;
    v12 = v8 * v7->m_intToFloatScale.m_quad.m128_f32[1];
    v13 = v9 * v7->m_intToFloatScale.m_quad.m128_f32[1];
    v14 = fminf(v12, v13);
    v15 = fmaxf(v12, v13);
    v7->m_heightCenter = (float)(v15 + v14) * 0.5;
    v7->m_extents.m_quad.m128_f32[1] = v15 - v14;
  }
  v16 = _mm_mul_ps(v7->m_extents.m_quad, (__m128)xmmword_141A711B0);
  v17 = v16;
  v17.m128_i32[1] = LODWORD(v7->m_heightCenter);
  v18 = _mm_add_ps(
          _mm_add_ps(
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32((__m128i)_mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v5->m_rotation.m_col0.m_quad), 1u),
                      1u),
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32(
                        (__m128i)_mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), v5->m_rotation.m_col1.m_quad),
                        1u),
                      1u)),
          _mm_add_ps(
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32(
                        (__m128i)_mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), v5->m_rotation.m_col2.m_quad),
                        1u),
                      1u),
            _mm_shuffle_ps((__m128)LODWORD(v20), (__m128)LODWORD(v20), 0)));
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v5->m_rotation.m_col0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), v5->m_rotation.m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), v5->m_rotation.m_col2.m_quad)),
          v5->m_translation.m_quad);
  v6->m_max.m_quad = _mm_add_ps(v19, v18);
  v6->m_min.m_quad = _mm_add_ps(
                       _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v18),
                       v19);
}

// File Line: 185
// RVA: 0xD167F0
void __fastcall hkpSampledHeightFieldShape::getHeightAndNormalAt(hkpSampledHeightFieldShape *this, int xPos, int zPos, float subX, float subZ, hkVector4f *normalOut, float *heightOut, int *triangleIndexOut)
{
  hkVector4f *v8; // rdi
  unsigned int v9; // ebp
  unsigned int v10; // esi
  hkpSampledHeightFieldShape *v11; // rbx
  __m128 v12; // xmm0
  hkBaseObjectVtbl *v13; // rax
  hkBaseObjectVtbl *v14; // rax
  float v15; // xmm6_4
  hkBaseObjectVtbl *v16; // rax
  int *v17; // rax

  v8 = normalOut;
  v9 = xPos;
  v10 = zPos;
  v11 = this;
  v12 = _mm_unpackhi_ps(*(__m128 *)_xmm, normalOut->m_quad);
  normalOut->m_quad = _mm_shuffle_ps(*(__m128 *)_xmm, v12, 196);
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkVector4f **))this->vfptr[10].__first_virtual_table_function__)(
    this,
    &normalOut);
  v13 = v11->vfptr;
  if ( (_BYTE)normalOut )
  {
    ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v13[10].__vecDelDtor)(v11, v9, v10);
    ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v11->vfptr[10].__vecDelDtor)(
      v11,
      v9 + 1,
      v10 + 1);
    v14 = v11->vfptr;
    if ( subX > subZ )
    {
      ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v14[10].__vecDelDtor)(v11, v9 + 1, v10);
      *heightOut = (float)((float)((float)(v12.m128_f32[0] - v12.m128_f32[0]) * subZ) + v12.m128_f32[0])
                 + (float)((float)(v12.m128_f32[0] - v12.m128_f32[0]) * subX);
      v8->m_quad.m128_i32[0] = COERCE_UNSIGNED_INT(v12.m128_f32[0] - v12.m128_f32[0]) ^ _xmm[0];
      v8->m_quad.m128_i32[2] = COERCE_UNSIGNED_INT(v12.m128_f32[0] - v12.m128_f32[0]) ^ _xmm[0];
      *triangleIndexOut = 1;
      return;
    }
    ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v14[10].__vecDelDtor)(v11, v9, v10 + 1);
    v15 = v12.m128_f32[0] - v12.m128_f32[0];
    *heightOut = (float)((float)((float)(v12.m128_f32[0] - v12.m128_f32[0]) * subZ) + v12.m128_f32[0])
               + (float)((float)(v12.m128_f32[0] - v12.m128_f32[0]) * subX);
    v8->m_quad.m128_i32[2] = COERCE_UNSIGNED_INT(v12.m128_f32[0] - v12.m128_f32[0]) ^ _xmm[0];
  }
  else
  {
    ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v13[10].__vecDelDtor)(v11, v9 + 1, v10);
    ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v11->vfptr[10].__vecDelDtor)(v11, v9, v10 + 1);
    v16 = v11->vfptr;
    if ( (float)(subX + subZ) > 1.0 )
    {
      ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v16[10].__vecDelDtor)(v11, v9 + 1, v10 + 1);
      *heightOut = (float)((float)((float)(v12.m128_f32[0] - v12.m128_f32[0]) * subZ) + v12.m128_f32[0])
                 + (float)((float)(subX - 1.0) * (float)(v12.m128_f32[0] - v12.m128_f32[0]));
      v8->m_quad.m128_i32[0] = COERCE_UNSIGNED_INT(v12.m128_f32[0] - v12.m128_f32[0]) ^ _xmm[0];
      v8->m_quad.m128_i32[2] = COERCE_UNSIGNED_INT(v12.m128_f32[0] - v12.m128_f32[0]) ^ _xmm[0];
      *triangleIndexOut = 1;
      return;
    }
    ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v16[10].__vecDelDtor)(v11, v9, v10);
    v15 = v12.m128_f32[0] - v12.m128_f32[0];
    *heightOut = (float)((float)((float)(v12.m128_f32[0] - v12.m128_f32[0]) * subZ) + v12.m128_f32[0])
               + (float)((float)(v12.m128_f32[0] - v12.m128_f32[0]) * subX);
    v8->m_quad.m128_i32[2] = COERCE_UNSIGNED_INT(v12.m128_f32[0] - v12.m128_f32[0]) ^ _xmm[0];
  }
  v17 = triangleIndexOut;
  v8->m_quad.m128_i32[0] = LODWORD(v15) ^ _xmm[0];
  *v17 = 0;
}

// File Line: 191
// RVA: 0xD162D0
void __fastcall hkpSampledHeightFieldShape::getCoarseMinMax(hkpSampledHeightFieldShape *this, int level, int x, int z, hkVector4f *minOut, hkVector4f *maxOut)
{
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *v6; // r10
  int v7; // eax
  __int64 v8; // rdx

  v6 = &this->m_coarseTreeData.m_data[level - this->m_coarseness];
  if ( x < v6->m_xRes )
  {
    v7 = v6->m_zRes;
    if ( z < v7 )
    {
      v8 = 2 * (z + x * v7);
      *minOut = v6->m_minMaxData.m_data[v8];
      *maxOut = v6->m_minMaxData.m_data[v8 + 1];
    }
  }
}

// File Line: 214
// RVA: 0xD16A90
void __fastcall `anonymous namespace::NearestHitCollector::addRayHit(NearestHitCollector *this, hkpCdBody *cdBody, hkpShapeRayCastCollectorOutput *hitInfoIn)
{
  float v3; // xmm0_4
  hkpShapeRayCastOutput *v4; // rax

  v3 = hitInfoIn->m_hitFraction;
  if ( v3 < this->m_earlyOutHitFraction )
  {
    v4 = this->m_output;
    this->m_earlyOutHitFraction = v3;
    v4->m_normal = hitInfoIn->m_normal;
    this->m_output->m_hitFraction = hitInfoIn->m_hitFraction;
    this->m_output->m_extraInfo = hitInfoIn->m_extraInfo;
    this->m_output->m_shapeKeys[this->m_output->m_shapeKeyIndex] = -1;
    this->m_hasHit.m_bool = 1;
  }
}

// File Line: 242
// RVA: 0xD16AE0
void __fastcall `anonymous namespace::RotateNormalHitCollector::addRayHit(RotateNormalHitCollector *this, hkpCdBody *cdBody, hkpShapeRayCastCollectorOutput *hitIn)
{
  hkVector4f v3; // xmm0
  __m128 *v4; // rax
  RotateNormalHitCollector *v5; // rbx
  hkpRayHitCollector *v6; // rcx
  __m128 v7; // [rsp+20h] [rbp-28h]
  __int128 v8; // [rsp+30h] [rbp-18h]

  v3.m_quad = (__m128)hitIn->m_normal;
  v4 = (__m128 *)cdBody->m_motion;
  v5 = this;
  v6 = this->m_collector;
  v8 = *(_OWORD *)&hitIn->m_hitFraction;
  v7 = v3.m_quad;
  v7 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 85), v4[1]),
           _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 0), *v4)),
         _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 170), v4[2]));
  v6->vfptr->addRayHit(v6, cdBody, (hkpShapeRayCastCollectorOutput *)&v7);
  v5->m_earlyOutHitFraction = v5->m_collector->m_earlyOutHitFraction;
}

// File Line: 253
// RVA: 0xD16670
hkBool *__fastcall hkpSampledHeightFieldShape::castRay(hkpSampledHeightFieldShape *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *results)
{
  float v4; // xmm0_4
  hkBool *v5; // rbx
  hkpRayHitCollector v7; // [rsp+20h] [rbp-28h]
  char v8; // [rsp+30h] [rbp-18h]
  hkpShapeRayCastOutput *v9; // [rsp+38h] [rbp-10h]

  v4 = results->m_hitFraction;
  v5 = result;
  v9 = results;
  v7.m_earlyOutHitFraction = v4;
  v7.vfptr = (hkpRayHitCollectorVtbl *)&`anonymous namespace::NearestHitCollector::`vftable;
  v8 = 0;
  hkpSampledHeightFieldShape::s_rayCastFunc(this, input, 0i64, &v7);
  v5->m_bool = v8;
  return v5;
}

// File Line: 262
// RVA: 0xD166D0
void __fastcall hkpSampledHeightFieldShape::castRayWithCollector(hkpSampledHeightFieldShape *this, hkpShapeRayCastInput *input, hkpCdBody *cdBody, hkpRayHitCollector *collector)
{
  float v4; // xmm0_4
  hkpRayHitCollector v5; // [rsp+20h] [rbp-28h]
  hkpRayHitCollector *v6; // [rsp+30h] [rbp-18h]

  v4 = collector->m_earlyOutHitFraction;
  v6 = collector;
  v5.m_earlyOutHitFraction = v4;
  v5.vfptr = (hkpRayHitCollectorVtbl *)&`anonymous namespace::RotateNormalHitCollector::`vftable;
  hkpSampledHeightFieldShape::s_rayCastFunc(this, input, cdBody, &v5);
}

// File Line: 271
// RVA: 0xD165E0
void __fastcall hkpSampledHeightFieldShape::castSphere(hkpSampledHeightFieldShape *this, hkpHeightFieldShape::hkpSphereCastInput *input, hkpCdBody *cdBody, hkpRayHitCollector *collector)
{
  hkVector4f v4; // xmm4
  __m128 v5; // xmm2
  hkVector4f v6; // xmm1
  __int128 v7; // xmm0
  __int128 v8; // xmm1
  __m128 v9; // xmm4
  __int128 v10; // xmm0
  __m128 v11; // xmm1
  hkVector4f v12; // xmm0
  hkVector4f v13; // [rsp+20h] [rbp-58h]
  __m128 v14; // [rsp+30h] [rbp-48h]
  __int128 v15; // [rsp+40h] [rbp-38h]
  __int128 v16; // [rsp+50h] [rbp-28h]
  __int128 v17; // [rsp+60h] [rbp-18h]

  v4.m_quad = (__m128)this->m_intToFloatScale;
  v5 = _mm_unpacklo_ps(_mm_xor_ps((__m128)LODWORD(input->m_radius), *(__m128 *)_xmm), (__m128)0i64);
  v6.m_quad = (__m128)input->m_to;
  v13.m_quad = (__m128)input->m_from;
  v7 = *(_OWORD *)&input->m_filterInfo;
  v14 = v6.m_quad;
  v8 = *(_OWORD *)&input->m_collidable;
  v15 = v7;
  v9 = _mm_xor_ps(
         (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_shuffle_ps(v4.m_quad, v4.m_quad, 85), 0x1Fu), 0x1Fu),
         _mm_unpacklo_ps((__m128)0i64, v5));
  v10 = *(_OWORD *)&input->m_radius;
  v16 = v8;
  v11 = _mm_add_ps(input->m_from.m_quad, v9);
  v17 = v10;
  v12.m_quad = (__m128)input->m_to;
  v13.m_quad = v11;
  v14 = _mm_add_ps(v12.m_quad, v9);
  hkpSampledHeightFieldShape::s_sphereCastFunc(this, (hkpHeightFieldShape::hkpSphereCastInput *)&v13, cdBody, collector);
}

