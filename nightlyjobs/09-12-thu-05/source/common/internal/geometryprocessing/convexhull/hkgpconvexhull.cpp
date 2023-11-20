// File Line: 36
// RVA: 0xCA8E80
void __fastcall hkgpConvexHull::BuildConfig::BuildConfig(hkgpConvexHull::BuildConfig *this)
{
  *(_WORD *)&this->m_allowLowerDimensions.m_bool = 0;
  this->m_minCosAngle = 0.99998999;
  *(_DWORD *)&this->m_setSourceIndices.m_bool = 16777472;
  *(_WORD *)&this->m_internalInputs.m_bool = 0;
  this->m_ensurePlaneEnclosing.m_bool = 0;
}

// File Line: 46
// RVA: 0xCA8EB0
void __fastcall hkgpConvexHull::SimplifyConfig::SimplifyConfig(hkgpConvexHull::SimplifyConfig *this)
{
  this->m_maxVertices = -1;
  this->m_ensureContainment.m_bool = 1;
  *(_QWORD *)&this->m_minArea = 0i64;
  *(_WORD *)&this->m_removeUnreferencedVertices.m_bool = 0;
}

// File Line: 53
// RVA: 0xCA8ED0
void __fastcall hkgpConvexHull::AbsoluteScaleConfig::AbsoluteScaleConfig(hkgpConvexHull::AbsoluteScaleConfig *this)
{
  this->m_method = 1;
  *(_QWORD *)&this->m_minComDistance = 925353388i64;
}

// File Line: 61
// RVA: 0xCA8EF0
void __fastcall hkgpConvexHull::hkgpConvexHull(hkgpConvexHull *this)
{
  hkgpConvexHull *v1; // rbx
  _QWORD **v2; // rax
  hkgpConvexHullImpl *v3; // rax

  v1 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkgpConvexHull::`vftable;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkgpConvexHullImpl *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 496i64);
  if ( v3 )
    hkgpConvexHullImpl::hkgpConvexHullImpl(v3);
  v1->m_data = v3;
  v3->m_hull = v1;
  v1->m_userData = 0i64;
  v1->m_userObject = 0i64;
}

// File Line: 69
// RVA: 0xCA8F60
void __fastcall hkgpConvexHull::~hkgpConvexHull(hkgpConvexHull *this)
{
  hkgpConvexHullImpl *v1; // rdi
  hkgpConvexHull *v2; // rbx
  _QWORD **v3; // rax

  v1 = this->m_data;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkgpConvexHull::`vftable;
  if ( v1 )
  {
    hkgpConvexHullImpl::~hkgpConvexHullImpl(v1);
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkgpConvexHullImpl *, signed __int64))(*v3[11] + 16i64))(v3[11], v1, 496i64);
  }
  hkgpConvexHull::deleteUserObject(v2);
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 75
// RVA: 0xCA9010
void __fastcall hkgpConvexHull::reset(hkgpConvexHull *this)
{
  hkgpConvexHull *v1; // rbx

  v1 = this;
  hkgpConvexHullImpl::reset(this->m_data, 0);
  hkgpConvexHull::deleteUserObject(v1);
}

// File Line: 81
// RVA: 0xCA9040
hkgpConvexHull *__fastcall hkgpConvexHull::clone(hkgpConvexHull *this)
{
  hkgpConvexHull *v1; // rsi
  _QWORD **v2; // rax
  hkgpConvexHull *v3; // rax
  hkgpConvexHull *v4; // rax
  hkgpConvexHull *v5; // rbx
  hkgpConvexHullImpl *v6; // rdi
  _QWORD **v7; // rax
  hkgpConvexHullImpl *v8; // rax
  hkgpConvexHull::IUserObject *v9; // rcx

  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkgpConvexHull *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 40i64);
  if ( v3 )
  {
    hkgpConvexHull::hkgpConvexHull(v3);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = v5->m_data;
  if ( v6 )
  {
    hkgpConvexHullImpl::~hkgpConvexHullImpl(v5->m_data);
    v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkgpConvexHullImpl *, signed __int64))(*v7[11] + 16i64))(v7[11], v6, 496i64);
  }
  v5->m_data = 0i64;
  v8 = hkgpConvexHullImpl::clone(v1->m_data);
  v5->m_data = v8;
  v8->m_hull = v5;
  v5->m_userData = v1->m_userData;
  v9 = v1->m_userObject;
  if ( v9 )
    v5->m_userObject = (hkgpConvexHull::IUserObject *)((__int64 (*)(void))v9->vfptr->clone)();
  else
    v5->m_userObject = 0i64;
  return v5;
}

// File Line: 93
// RVA: 0xCA9120
void **__fastcall hkgpConvexHull::userData(hkgpConvexHull *this)
{
  return &this->m_userData;
}

// File Line: 98
// RVA: 0xCA9130
hkgpConvexHull::IUserObject **__fastcall hkgpConvexHull::userObject(hkgpConvexHull *this)
{
  return &this->m_userObject;
}

// File Line: 103
// RVA: 0xCA9140
void __fastcall hkgpConvexHull::deleteUserObject(hkgpConvexHull *this)
{
  hkgpConvexHull *v1; // rbx
  hkgpConvexHull::IUserObject *v2; // rcx

  v1 = this;
  v2 = this->m_userObject;
  if ( v2 )
    v2->vfptr->__vecDelDtor(v2, 1u);
  v1->m_userObject = 0i64;
}

// File Line: 109
// RVA: 0xCA8FD0
__int64 __fastcall hkgpConvexHull::uid(hkgpConvexHull *this)
{
  return this->m_data->m_uid;
}

// File Line: 114
// RVA: 0xCA8FF0
void __fastcall hkgpConvexHull::changeUid(hkgpConvexHull *this, unsigned int newUid)
{
  this->m_data->m_uid = newUid;
}

// File Line: 119
// RVA: 0xCAF4D0
void hkgpConvexHull::resetUidGenerator(void)
{
  hkgpConvexHullImpl::g_uidGenerator = 0;
}

// File Line: 124
// RVA: 0xCA9170
int __fastcall hkgpConvexHull::build(hkgpConvexHull *this, hkVector4f *points, int numPoints, hkgpConvexHull::BuildConfig *config)
{
  hkgpConvexHullImpl *v4; // r10

  v4 = this->m_data;
  *(_DWORD *)&v4->m_config.m_allowLowerDimensions.m_bool = *(_DWORD *)&config->m_allowLowerDimensions.m_bool;
  v4->m_config.m_minCosAngle = config->m_minCosAngle;
  *(_DWORD *)&v4->m_config.m_setSourceIndices.m_bool = *(_DWORD *)&config->m_setSourceIndices.m_bool;
  *(_DWORD *)&v4->m_config.m_internalInputs.m_bool = *(_DWORD *)&config->m_internalInputs.m_bool;
  return hkgpConvexHullImpl::build(this->m_data, points, numPoints, 0, 0i64);
}

// File Line: 130
// RVA: 0xCA91C0
int __fastcall hkgpConvexHull::build(hkgpConvexHull *this, hkStridedVertices *points, hkgpConvexHull::BuildConfig *config)
{
  hkgpConvexHull::BuildConfig *v3; // rbp
  hkStridedVertices *v4; // rbx
  hkgpConvexHull *v5; // r14
  hkVector4f *v6; // rdx
  const float *v8; // rsi
  int v9; // edi
  int v10; // er9
  int v11; // edx
  __int64 v12; // rcx
  hkVector4f *v13; // rdx
  int v14; // eax
  int v15; // ebx
  hkVector4f *array; // [rsp+30h] [rbp-28h]
  int v17; // [rsp+38h] [rbp-20h]
  int v18; // [rsp+3Ch] [rbp-1Ch]
  hkResult result; // [rsp+68h] [rbp+10h]

  v3 = config;
  v4 = points;
  v5 = this;
  if ( points->m_striding == 16 )
  {
    v6 = (hkVector4f *)points->m_vertices;
    if ( !((unsigned __int8)v6 & 0xF) )
      return hkgpConvexHull::build(this, v6, v4->m_numVertices, config);
  }
  v8 = v4->m_vertices;
  v9 = v4->m_numVertices;
  array = 0i64;
  v17 = 0;
  v18 = 2147483648;
  if ( v9 > 0 )
  {
    v10 = v9;
    if ( v9 < 0 )
      v10 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v10, 16);
  }
  v11 = 0;
  v17 = v9;
  if ( v4->m_numVertices > 0 )
  {
    v12 = 0i64;
    do
    {
      ++v11;
      ++v12;
      array[v12 - 1].m_quad = _mm_movelh_ps((__m128)*(unsigned __int64 *)v8, (__m128)*((unsigned int *)v8 + 2));
      array[v12 - 1] = (hkVector4f)_mm_srli_si128(
                                     _mm_slli_si128(_mm_load_si128((const __m128i *)&array[v12 - 1]), 4),
                                     4);
      v8 = (const float *)((char *)v8 + v4->m_striding);
    }
    while ( v11 < v4->m_numVertices );
    v9 = v17;
  }
  v13 = 0i64;
  if ( v9 )
    v13 = array;
  v14 = hkgpConvexHull::build(v5, v13, v9, v3);
  v17 = 0;
  v15 = v14;
  if ( v18 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v18);
  return v15;
}

// File Line: 161
// RVA: 0xCA9320
int __fastcall hkgpConvexHull::buildPlanar(hkgpConvexHull *this, hkVector4f *points, int numPoints, hkVector4f *plane, hkgpConvexHull::BuildConfig *config)
{
  hkgpConvexHullImpl *v5; // r11

  v5 = this->m_data;
  *(_DWORD *)&v5->m_config.m_allowLowerDimensions.m_bool = *(_DWORD *)&config->m_allowLowerDimensions.m_bool;
  v5->m_config.m_minCosAngle = config->m_minCosAngle;
  *(_DWORD *)&v5->m_config.m_setSourceIndices.m_bool = *(_DWORD *)&config->m_setSourceIndices.m_bool;
  *(_DWORD *)&v5->m_config.m_internalInputs.m_bool = *(_DWORD *)&config->m_internalInputs.m_bool;
  this->m_data->m_projectionPlane = (hkVector4f)plane->m_quad;
  return hkgpConvexHullImpl::build(this->m_data, points, numPoints, 1, 0i64);
}

// File Line: 168
// RVA: 0xCA9380
int __fastcall hkgpConvexHull::buildPlanar(hkgpConvexHull *this, hkStridedVertices *points, hkVector4f *plane, hkgpConvexHull::BuildConfig *config)
{
  hkgpConvexHull::BuildConfig *v4; // rbp
  hkVector4f *v5; // r14
  hkStridedVertices *v6; // rbx
  hkgpConvexHull *v7; // r15
  const float *v9; // rsi
  int v10; // edi
  int v11; // er9
  int v12; // edx
  __int64 v13; // rcx
  hkVector4f *v14; // rdx
  int v15; // eax
  int v16; // ebx
  hkVector4f *array; // [rsp+30h] [rbp-38h]
  int v18; // [rsp+38h] [rbp-30h]
  int v19; // [rsp+3Ch] [rbp-2Ch]
  hkResult result; // [rsp+78h] [rbp+10h]

  v4 = config;
  v5 = plane;
  v6 = points;
  v7 = this;
  if ( points->m_striding == 16 )
    return hkgpConvexHull::buildPlanar(this, (hkVector4f *)points->m_vertices, points->m_numVertices, plane, config);
  v9 = points->m_vertices;
  v10 = points->m_numVertices;
  array = 0i64;
  v18 = 0;
  v19 = 2147483648;
  if ( v10 > 0 )
  {
    v11 = v10;
    if ( v10 < 0 )
      v11 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v11, 16);
  }
  v12 = 0;
  v18 = v10;
  if ( v6->m_numVertices > 0 )
  {
    v13 = 0i64;
    do
    {
      ++v12;
      ++v13;
      array[v13 - 1].m_quad = _mm_movelh_ps((__m128)*(unsigned __int64 *)v9, (__m128)*((unsigned int *)v9 + 2));
      array[v13 - 1] = (hkVector4f)_mm_srli_si128(
                                     _mm_slli_si128(_mm_load_si128((const __m128i *)&array[v13 - 1]), 4),
                                     4);
      v9 = (const float *)((char *)v9 + v6->m_striding);
    }
    while ( v12 < v6->m_numVertices );
    v10 = v18;
  }
  v14 = 0i64;
  if ( v10 )
    v14 = array;
  v15 = hkgpConvexHull::buildPlanar(v7, v14, v10, v5, v4);
  v18 = 0;
  v16 = v15;
  if ( v19 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v19);
  return v16;
}

// File Line: 188
// RVA: 0xCA94F0
__int64 __fastcall hkgpConvexHull::buildFromPlanes(hkgpConvexHull *this, hkVector4f *planes, int numPlanes, hkgpConvexHull::BuildConfig *config)
{
  hkgpConvexHull *v4; // r15
  hkgpConvexHull::BuildConfig *v5; // r14
  signed __int64 v6; // rbx
  hkVector4f *v7; // rsi
  _QWORD *v8; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  int v12; // er9
  float v13; // xmm8_4
  signed __int64 v14; // r13
  signed __int64 v15; // rdi
  hkVector4f *v16; // rcx
  signed __int64 v17; // rax
  signed __int64 v18; // r14
  __m128 v19; // xmm13
  hkVector4f *v20; // r12
  signed __int64 v21; // rax
  signed __int64 v22; // rbx
  __m128 v23; // xmm1
  hkVector4f *v24; // r15
  __m128 v25; // xmm9
  __m128 v26; // xmm6
  char v27; // cl
  int v28; // er8
  signed __int64 v29; // rdx
  __m128 v30; // xmm7
  __m128 *v31; // rax
  __m128 v32; // xmm2
  __m128 v33; // xmm2
  __m128 v34; // xmm1
  signed __int64 v35; // rdx
  int v36; // er8
  __m128 *v37; // r9
  __m128 v38; // xmm2
  __m128 v39; // xmm2
  __m128 v40; // xmm1
  signed __int64 v41; // rdx
  int v42; // er8
  __m128 *v43; // r9
  __m128 v44; // xmm2
  __m128 v45; // xmm2
  __m128 v46; // xmm1
  int v47; // er8
  signed __int64 v48; // r9
  __m128 *v49; // rdx
  __m128 v50; // xmm2
  __m128 v51; // xmm2
  __m128 v52; // xmm1
  int v53; // ecx
  _QWORD *v54; // rax
  _QWORD *v55; // rcx
  _QWORD *v56; // r8
  unsigned __int64 v57; // rax
  signed __int64 v58; // rcx
  unsigned int v59; // ebx
  hkVector4f *v61; // [rsp+30h] [rbp-C0h]
  hkVector4f *array; // [rsp+48h] [rbp-A8h]
  int numPoints; // [rsp+50h] [rbp-A0h]
  int v64; // [rsp+54h] [rbp-9Ch]
  hkMatrix3f v65; // [rsp+60h] [rbp-90h]
  hkgpConvexHull *vars0; // [rsp+140h] [rbp+50h]
  hkgpConvexHull *result; // [rsp+150h] [rbp+60h]
  hkgpConvexHull::BuildConfig *v68; // [rsp+158h] [rbp+68h]
  hkgpConvexHull::BuildConfig *v69; // [rsp+168h] [rbp+78h]

  v69 = config;
  result = this;
  v4 = this;
  v5 = config;
  v6 = numPlanes;
  v7 = planes;
  array = 0i64;
  numPoints = 0;
  v64 = 2147483648;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtVertexEnumeration";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  *(float *)&result = FLOAT_0_0000099999997;
  v12 = 3 * v6;
  LODWORD(v13) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(FLOAT_0_0000099999997),
                                      (__m128)LODWORD(FLOAT_0_0000099999997),
                                      0);
  if ( (v64 & 0x3FFFFFFF) < 3 * (signed int)v6 )
  {
    if ( v12 < 2 * (v64 & 0x3FFFFFFF) )
      v12 = 2 * (v64 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      v12,
      16);
  }
  v14 = 0i64;
  v15 = v6;
  if ( (signed int)v6 > 0 )
  {
    v16 = v7;
    v61 = v7;
    do
    {
      v17 = v14 + 1;
      v18 = v14 + 1;
      v19 = _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v16->m_quad, v16->m_quad, 255));
      if ( v14 + 1 < v15 )
      {
        v20 = v16 + 1;
        do
        {
          v21 = v18 + 1;
          v22 = v18 + 1;
          v23 = _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v20->m_quad, v20->m_quad, 255));
          if ( v18 + 1 < v15 )
          {
            v24 = v20 + 1;
            v25 = _mm_unpacklo_ps(v19, v23);
            do
            {
              v65.m_col1 = (hkVector4f)v24->m_quad;
              v65.m_col0 = (hkVector4f)v16->m_quad;
              v26 = _mm_movelh_ps(
                      v25,
                      _mm_unpacklo_ps(
                        _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v65.m_col1.m_quad, v65.m_col1.m_quad, 255)),
                        query.m_quad));
              v65.m_col1 = (hkVector4f)v20->m_quad;
              hkMatrix3f::transpose(&v65);
              if ( hkMatrix3f::invert(&v65, (hkResult *)&result, 0.00000011920929)->m_enum == HK_SUCCESS )
              {
                v27 = 1;
                v28 = 0;
                v29 = 0i64;
                v30 = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), v65.m_col1.m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), v65.m_col0.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v26, v26, 170), v65.m_col1.m_quad));
                if ( v14 > 0 )
                {
                  v31 = &v7->m_quad;
                  do
                  {
                    if ( !v27 )
                      break;
                    v32 = _mm_mul_ps(v30, *v31);
                    v33 = _mm_shuffle_ps(v32, _mm_unpackhi_ps(v32, *v31), 196);
                    v34 = _mm_add_ps(_mm_shuffle_ps(v33, v33, 78), v33);
                    if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 177)) + v34.m128_f32[0]) > v13 )
                      v27 = 0;
                    ++v29;
                    ++v28;
                    ++v31;
                  }
                  while ( v29 < v14 );
                }
                v35 = v29 + 1;
                v36 = v28 + 1;
                if ( v35 < v18 )
                {
                  v37 = &v7[v35].m_quad;
                  do
                  {
                    if ( !v27 )
                      break;
                    v38 = _mm_mul_ps(v30, *v37);
                    v39 = _mm_shuffle_ps(v38, _mm_unpackhi_ps(v38, *v37), 196);
                    v40 = _mm_add_ps(_mm_shuffle_ps(v39, v39, 78), v39);
                    if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 177)) + v40.m128_f32[0]) > v13 )
                      v27 = 0;
                    ++v35;
                    ++v36;
                    ++v37;
                  }
                  while ( v35 < v18 );
                }
                v41 = v35 + 1;
                v42 = v36 + 1;
                if ( v41 < v22 )
                {
                  v43 = &v7[v41].m_quad;
                  do
                  {
                    if ( !v27 )
                      break;
                    v44 = _mm_mul_ps(v30, *v43);
                    v45 = _mm_shuffle_ps(v44, _mm_unpackhi_ps(v44, *v43), 196);
                    v46 = _mm_add_ps(_mm_shuffle_ps(v45, v45, 78), v45);
                    if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v46, v46, 177)) + v46.m128_f32[0]) > v13 )
                      v27 = 0;
                    ++v41;
                    ++v42;
                    ++v43;
                  }
                  while ( v41 < v22 );
                }
                v47 = v42 + 1;
                v48 = v47;
                if ( v47 >= v15 )
                {
LABEL_38:
                  if ( v27 )
                  {
                    v53 = numPoints;
                    if ( numPoints == (v64 & 0x3FFFFFFF) )
                    {
                      hkArrayUtil::_reserveMore(
                        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                        &array,
                        16);
                      v53 = numPoints;
                    }
                    array[v53] = (hkVector4f)v30;
                    ++numPoints;
                  }
                }
                else
                {
                  v49 = &v7[v47].m_quad;
                  while ( v27 )
                  {
                    v50 = _mm_mul_ps(v30, *v49);
                    v51 = _mm_shuffle_ps(v50, _mm_unpackhi_ps(v50, *v49), 196);
                    v52 = _mm_add_ps(_mm_shuffle_ps(v51, v51, 78), v51);
                    if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v52, v52, 177)) + v52.m128_f32[0]) > v13 )
                      v27 = 0;
                    ++v48;
                    ++v49;
                    if ( v48 >= v15 )
                      goto LABEL_38;
                  }
                }
              }
              v16 = v61;
              ++v22;
              ++v24;
            }
            while ( v22 < v15 );
            v21 = v18 + 1;
          }
          ++v20;
          v18 = v21;
        }
        while ( v21 < v15 );
        v17 = v14 + 1;
      }
      ++v16;
      v14 = v17;
      v61 = v16;
    }
    while ( v17 < v15 );
    v5 = v68;
    v4 = vars0;
  }
  v54 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v55 = (_QWORD *)v54[1];
  v56 = v54;
  if ( (unsigned __int64)v55 < v54[3] )
  {
    *v55 = "Et";
    v57 = __rdtsc();
    v58 = (signed __int64)(v55 + 2);
    *(_DWORD *)(v58 - 8) = v57;
    v56[1] = v58;
  }
  if ( numPoints <= 3 )
    v59 = -1;
  else
    v59 = hkgpConvexHull::build(v4, array, numPoints, v5);
  numPoints = 0;
  if ( v64 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v64);
  return v59;
}

// File Line: 240
// RVA: 0xCA9A40
__int64 __fastcall hkgpConvexHull::buildFromPlanes(hkgpConvexHull *this, hkVector4f *planes, int numPlanes, hkVector4f *projectionPlane, hkgpConvexHull::BuildConfig *config)
{
  hkgpConvexHull *v5; // r15
  hkVector4f *v6; // r14
  signed __int64 v7; // rbx
  hkVector4f *v8; // r13
  _QWORD *v9; // r10
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  int v13; // er9
  __m128 v14; // xmm7
  signed __int64 v15; // rsi
  signed __int64 v16; // rdi
  __m128 *v17; // r15
  __m128 v18; // xmm0
  signed __int64 v19; // r12
  signed __int64 v20; // rbx
  __m128 *v21; // r12
  __m128 *v22; // r14
  __m128 v23; // xmm1
  __m128 v24; // xmm7
  __m128 v25; // xmm2
  hkVector4f v26; // xmm4
  signed __int64 v27; // rax
  __m128 *v28; // rcx
  __m128 v29; // xmm6
  __m128 v30; // xmm2
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  int v33; // ecx
  _QWORD *v34; // rax
  _QWORD *v35; // rcx
  _QWORD *v36; // r8
  unsigned __int64 v37; // rax
  signed __int64 v38; // rcx
  unsigned int v39; // ebx
  int sizeElem[2]; // [rsp+20h] [rbp-71h]
  int v42; // [rsp+28h] [rbp-69h]
  int v43; // [rsp+2Ch] [rbp-65h]
  __m128 *array; // [rsp+30h] [rbp-61h]
  int v45; // [rsp+38h] [rbp-59h]
  int v46; // [rsp+3Ch] [rbp-55h]
  hkMatrix3f v47; // [rsp+40h] [rbp-51h]
  hkgpConvexHull *vars0; // [rsp+F0h] [rbp+5Fh]
  hkgpConvexHull *result; // [rsp+100h] [rbp+6Fh]
  hkVector4f *v50; // [rsp+108h] [rbp+77h]
  hkgpConvexHull::BuildConfig *v51; // [rsp+110h] [rbp+7Fh]
  hkVector4f *v52; // [rsp+118h] [rbp+87h]

  v52 = projectionPlane;
  result = this;
  v5 = this;
  v6 = projectionPlane;
  v7 = numPlanes;
  v8 = planes;
  array = 0i64;
  v45 = 0;
  v46 = 2147483648;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtVertexEnumeration";
    v11 = __rdtsc();
    v12 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v9[1] = v12;
  }
  v13 = 3 * v7;
  v14 = 0i64;
  if ( (v46 & 0x3FFFFFFF) < 3 * (signed int)v7 )
  {
    sizeElem[0] = 16;
    if ( v13 < 2 * (v46 & 0x3FFFFFFF) )
      v13 = 2 * (v46 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      v13,
      sizeElem[0]);
  }
  v15 = 0i64;
  v16 = v7;
  if ( (signed int)v7 > 0 )
  {
    v17 = &v8->m_quad;
    do
    {
      v18 = *v17;
      v19 = v15 + 1;
      *(_QWORD *)sizeElem = v15 + 1;
      v20 = v15 + 1;
      v14.m128_f32[0] = 0.0 - COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 255));
      if ( v15 + 1 < v16 )
      {
        v21 = &v50->m_quad;
        v22 = v17 + 1;
        do
        {
          v23 = _mm_unpacklo_ps(*v17, *v22);
          v24 = _mm_shuffle_ps(
                  _mm_unpacklo_ps(v14, _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(*v22, *v22, 255))),
                  v14,
                  228);
          v25 = *v21;
          v26.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(*v17, *v22), *v21, 228);
          v47.m_col0.m_quad = _mm_movelh_ps(v23, *v21);
          v47.m_col1.m_quad = _mm_shuffle_ps(_mm_movehl_ps(v47.m_col0.m_quad, v23), v25, 212);
          v47.m_col2 = (hkVector4f)v26.m_quad;
          v14 = _mm_shuffle_ps(v24, _mm_unpackhi_ps(v24, _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v25, v25, 255))), 180);
          if ( hkMatrix3f::invert(&v47, (hkResult *)&result, 0.00000011920929)->m_enum == HK_SUCCESS )
          {
            v27 = 0i64;
            v28 = &v8->m_quad;
            v29 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v47.m_col1.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v47.m_col0.m_quad)),
                    _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v47.m_col2.m_quad));
            while ( 1 )
            {
              if ( v27 != v15 && v27 != v20 )
              {
                v30 = _mm_mul_ps(v29, *v28);
                v31 = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, *v28), 196);
                v32 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 78), v31);
                if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 177)) + v32.m128_f32[0]) > 0.00000011920929 )
                  break;
              }
              ++v27;
              ++v28;
              if ( v27 >= v16 )
              {
                v33 = v45;
                if ( v45 == (v46 & 0x3FFFFFFF) )
                {
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
                  v33 = v45;
                }
                array[v33] = v29;
                ++v45;
                break;
              }
            }
          }
          ++v20;
          ++v22;
        }
        while ( v20 < v16 );
        v19 = *(_QWORD *)sizeElem;
      }
      ++v17;
      v15 = v19;
    }
    while ( v19 < v16 );
    v6 = v50;
    v5 = vars0;
  }
  v34 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v35 = (_QWORD *)v34[1];
  v36 = v34;
  if ( (unsigned __int64)v35 < v34[3] )
  {
    *v35 = "Et";
    v37 = __rdtsc();
    v38 = (signed __int64)(v35 + 2);
    *(_DWORD *)(v38 - 8) = v37;
    v36[1] = v38;
  }
  if ( v45 < 3 )
  {
    v39 = -1;
  }
  else
  {
    v42 = v45;
    *(_QWORD *)sizeElem = array;
    v43 = 16;
    v39 = hkgpConvexHull::buildPlanar(v5, (hkStridedVertices *)sizeElem, v6, v51);
  }
  v45 = 0;
  if ( v46 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v46);
  return v39;
}

// File Line: 282
// RVA: 0xCA9DD0
hkResult *__fastcall hkgpConvexHull::simplify(hkgpConvexHull *this, hkResult *result, hkgpConvexHull::SimplifyConfig *config)
{
  hkResult *v3; // rbx

  v3 = result;
  hkgpConvexHullImpl::simplify(this->m_data, result, config);
  return v3;
}

// File Line: 287
// RVA: 0xCA9E00
hkBool *__fastcall hkgpConvexHull::ensureContainment(hkgpConvexHull *this, hkBool *result, hkArray<hkVector4f,hkContainerHeapAllocator> *points)
{
  hkBool *v3; // rbx

  v3 = result;
  hkgpConvexHullImpl::ensureContainment(this->m_data, result, points);
  return v3;
}

// File Line: 292
// RVA: 0xCA9E30
hkBool *__fastcall hkgpConvexHull::decimateVertices(hkgpConvexHull *this, hkBool *result, int numVerticesToKeep, hkBool bEnsureContainment, hkBool useCgo)
{
  hkBool *v5; // rbx

  v5 = result;
  result->m_bool = hkgpConvexHullImpl::decimateVertices(
                     this->m_data,
                     numVerticesToKeep,
                     bEnsureContainment.m_bool != 0,
                     useCgo.m_bool != 0);
  return v5;
}

// File Line: 297
// RVA: 0xCA9E70
int hkgpConvexHull::expandByPlanarMargin(...)
{
  hkgpConvexHullImpl *v4; // rsi
  __m128 v5; // xmm7
  hkBool *v6; // rbx
  hkgpConvexHull *v7; // rdi
  __m128 v8; // xmm10
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // ebx
  int v13; // er9
  __m128 v14; // xmm7
  hkgpConvexHull::Triangle *v15; // rsi
  __m128 v16; // xmm1
  __m128 v17; // xmm6
  hkgpConvexHull::Vertex *v18; // rax
  hkVector4f *v19; // rax
  int v20; // edx
  __m128 v21; // xmm10
  __m128 v22; // xmm9
  int v23; // er9
  __m128 v24; // xmm7
  hkgpConvexHull::Vertex *v25; // rsi
  __m128 v26; // xmm8
  __m128 v27; // xmm6
  hkVector4f *v28; // rax
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // eax
  hkBool *v33; // rsi
  const float *v35; // rdx
  __m128 v36; // xmm12
  __m128 v37; // xmm11
  __m128 v38; // xmm7
  __m128 v39; // xmm5
  __m128 v40; // xmm4
  __m128 v41; // xmm5
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm3
  __m128 v45; // xmm6
  __m128 v46; // xmm1
  __m128 v47; // xmm3
  __m128 v48; // xmm2
  __m128 v49; // xmm8
  __m128 v50; // xmm8
  int v51; // ecx
  __m128 v52; // xmm7
  __m128 v53; // xmm1
  __m128 v54; // xmm2
  __m128 v55; // xmm7
  __m128 v56; // xmm1
  __m128 v57; // xmm6
  int v58; // ecx
  int v59; // ecx
  int v60; // ecx
  int v61; // ecx
  int v62; // ecx
  int v63; // ecx
  int v64; // ecx
  int v65; // er8
  float *v66; // rdx
  __m128 v67; // xmm6
  __m128 v68; // xmm2
  hkStridedVertices points; // [rsp+30h] [rbp-B0h]
  __m128 *array; // [rsp+40h] [rbp-A0h]
  int v71; // [rsp+48h] [rbp-98h]
  int v72; // [rsp+4Ch] [rbp-94h]
  hkgpConvexHull::BuildConfig config; // [rsp+50h] [rbp-90h]
  hkResult v74; // [rsp+60h] [rbp-80h]
  hkResult resulta; // [rsp+64h] [rbp-7Ch]
  hkResult v76; // [rsp+68h] [rbp-78h]
  hkErrStream buf; // [rsp+70h] [rbp-70h]
  hkResult v78; // [rsp+310h] [rbp+230h]
  hkBool *v79; // [rsp+318h] [rbp+238h]
  unsigned int vars0; // [rsp+320h] [rbp+240h]
  bool retaddr; // [rsp+328h] [rbp+248h]

  v4 = this->m_data;
  v5 = (__m128)vars0;
  v6 = result;
  v7 = this;
  *(_DWORD *)&config.m_allowLowerDimensions.m_bool = *(_DWORD *)&v4->m_config.m_allowLowerDimensions.m_bool;
  v8 = _mm_mul_ps(_mm_shuffle_ps(v5, v5, 0), (__m128)xmmword_141A711B0);
  config.m_minCosAngle = v4->m_config.m_minCosAngle;
  *(_DWORD *)&config.m_setSourceIndices.m_bool = *(_DWORD *)&v4->m_config.m_setSourceIndices.m_bool;
  *(_DWORD *)&config.m_internalInputs.m_bool = *(_DWORD *)&v4->m_config.m_internalInputs.m_bool;
  LOBYTE(v78.m_enum) = v4->m_hasIndexing;
  retaddr = v4->m_hasMassProperties;
  v9 = hkgpConvexHull::getDimensions(this);
  if ( !v9 )
  {
    v72 = 2147483648;
    array = 0i64;
    v71 = 0;
    v67 = v4->m_mesh.m_vertices.m_used->m_source.m_quad;
    hkArrayUtil::_reserve(
      (hkResult *)&points,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      6,
      16);
    v68 = _mm_sub_ps((__m128)0i64, v8);
    v71 = 6;
    *array = _mm_add_ps(_mm_mul_ps(v8, transform.m_quad), v67);
    array[1] = _mm_add_ps(_mm_mul_ps(v68, transform.m_quad), v67);
    array[2] = _mm_add_ps(_mm_mul_ps(v8, direction.m_quad), v67);
    array[3] = _mm_add_ps(_mm_mul_ps(v68, direction.m_quad), v67);
    array[4] = _mm_add_ps(_mm_mul_ps(v8, stru_141A71280.m_quad), v67);
    array[5] = _mm_add_ps(_mm_mul_ps(v68, stru_141A71280.m_quad), v67);
LABEL_61:
    points.m_vertices = (const float *)array;
    points.m_numVertices = v71;
    points.m_striding = 16;
    hkgpConvexHull::build(v7, &points, &config);
    v71 = 0;
LABEL_62:
    v65 = v72;
    if ( v72 < 0 )
    {
LABEL_65:
      v6 = v79;
LABEL_66:
      if ( hkgpConvexHull::getDimensions(v7) == 3 )
      {
        if ( LOBYTE(v78.m_enum) )
          hkgpConvexHull::buildIndices(v7, 0.99998999, 0);
        if ( retaddr )
          hkgpConvexHull::buildMassProperties(v7, &v78);
        v6->m_bool = 1;
      }
      else
      {
        v6->m_bool = 0;
      }
      return v6;
    }
    v66 = (float *)array;
LABEL_64:
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v66,
      16 * v65);
    goto LABEL_65;
  }
  v10 = v9 - 1;
  if ( !v10 )
  {
    points.m_vertices = 0i64;
    points.m_numVertices = 0;
    points.m_striding = 2147483648;
    hkArrayUtil::_reserve(&v76, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &points, 10, 16);
    hkgpConvexHull::fetchPositions(v7, 0, (hkArray<hkVector4f,hkContainerHeapAllocator> *)&points);
    v35 = points.m_vertices;
    v36 = *(__m128 *)((char *)points.m_vertices + 16);
    v37 = *(__m128 *)points.m_vertices;
    v38 = _mm_sub_ps(*(__m128 *)((char *)points.m_vertices + 16), *(__m128 *)points.m_vertices);
    v39 = _mm_shuffle_ps(v38, _mm_unpackhi_ps(v38, (__m128)0i64), 196);
    v40 = _mm_shuffle_ps(v39, v39, 241);
    v41 = _mm_shuffle_ps(v39, v39, 206);
    v42 = _mm_mul_ps(v40, v40);
    v43 = _mm_mul_ps(v41, v41);
    v44 = _mm_cmpltps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)),
              _mm_shuffle_ps(v42, v42, 170)),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
              _mm_shuffle_ps(v43, v43, 170)));
    v45 = _mm_xor_ps(
            _mm_or_ps(_mm_and_ps(v44, v41), _mm_andnot_ps(v44, v40)),
            (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
    v46 = _mm_mul_ps(v45, v45);
    v47 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
            _mm_shuffle_ps(v46, v46, 170));
    v48 = _mm_rsqrt_ps(v47);
    v49 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v45, v45, 201), v38), _mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), v45));
    v50 = _mm_shuffle_ps(v49, v49, 201);
    v51 = points.m_numVertices;
    v52 = _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmpleps(v47, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v48, v47), v48)),
                _mm_mul_ps(v48, *(__m128 *)_xmm))),
            v45);
    v53 = _mm_mul_ps(v50, v50);
    v54 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v53, v53, 85), _mm_shuffle_ps(v53, v53, 0)),
            _mm_shuffle_ps(v53, v53, 170));
    v55 = _mm_mul_ps(v52, v8);
    v56 = _mm_rsqrt_ps(v54);
    v57 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmpleps(v54, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v56, v54), v56)),
                  _mm_mul_ps(v56, *(__m128 *)_xmm))),
              v50),
            v8);
    if ( points.m_numVertices == (points.m_striding & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &points, 16);
      v51 = points.m_numVertices;
      v35 = points.m_vertices;
    }
    points.m_numVertices = v51 + 1;
    *(__m128 *)&v35[4 * v51] = _mm_add_ps(v55, v37);
    v58 = points.m_numVertices;
    if ( points.m_numVertices == (points.m_striding & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &points, 16);
      v58 = points.m_numVertices;
    }
    points.m_numVertices = v58 + 1;
    *(__m128 *)&points.m_vertices[4 * v58] = _mm_sub_ps(v37, v55);
    v59 = points.m_numVertices;
    if ( points.m_numVertices == (points.m_striding & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &points, 16);
      v59 = points.m_numVertices;
    }
    points.m_numVertices = v59 + 1;
    *(__m128 *)&points.m_vertices[4 * v59] = _mm_add_ps(v57, v37);
    v60 = points.m_numVertices;
    if ( points.m_numVertices == (points.m_striding & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &points, 16);
      v60 = points.m_numVertices;
    }
    points.m_numVertices = v60 + 1;
    *(__m128 *)&points.m_vertices[4 * v60] = _mm_sub_ps(v37, v57);
    v61 = points.m_numVertices;
    if ( points.m_numVertices == (points.m_striding & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &points, 16);
      v61 = points.m_numVertices;
    }
    points.m_numVertices = v61 + 1;
    *(__m128 *)&points.m_vertices[4 * v61] = _mm_add_ps(v55, v36);
    v62 = points.m_numVertices;
    if ( points.m_numVertices == (points.m_striding & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &points, 16);
      v62 = points.m_numVertices;
    }
    points.m_numVertices = v62 + 1;
    *(__m128 *)&points.m_vertices[4 * v62] = _mm_sub_ps(v36, v55);
    v63 = points.m_numVertices;
    if ( points.m_numVertices == (points.m_striding & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &points, 16);
      v63 = points.m_numVertices;
    }
    points.m_numVertices = v63 + 1;
    *(__m128 *)&points.m_vertices[4 * v63] = _mm_add_ps(v57, v36);
    v64 = points.m_numVertices;
    if ( points.m_numVertices == (points.m_striding & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &points, 16);
      v64 = points.m_numVertices;
    }
    points.m_numVertices = v64 + 1;
    v72 = 16;
    *(__m128 *)&points.m_vertices[4 * v64] = _mm_sub_ps(v36, v57);
    array = (__m128 *)points.m_vertices;
    v71 = points.m_numVertices;
    hkgpConvexHull::build(v7, (hkStridedVertices *)&array, &config);
    v65 = points.m_striding;
    points.m_numVertices = 0;
    if ( points.m_striding < 0 )
      goto LABEL_65;
    v66 = (float *)points.m_vertices;
    goto LABEL_64;
  }
  v11 = v10 - 1;
  if ( v11 )
  {
    if ( v11 != 1 )
    {
      hkErrStream::hkErrStream(&buf, &buf, 512);
      hkOstream::operator<<((hkOstream *)&buf.vfptr, "Invalid dimemsions for that operation");
      if ( (unsigned int)hkError::messageError(
                           388816712,
                           (const char *)&buf,
                           "GeometryProcessing\\ConvexHull\\hkgpConvexHull.cpp",
                           399) )
        __debugbreak();
      hkOstream::~hkOstream((hkOstream *)&buf.vfptr);
      goto LABEL_66;
    }
    v12 = 0;
    v72 = 2147483648;
    array = 0i64;
    v71 = 0;
    v13 = 6 * hkgpConvexHull::getNumTriangles(v7);
    if ( v13 <= 0 )
    {
      resulta.m_enum = 0;
    }
    else
    {
      if ( v13 < 0 )
        v13 = 0;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v13, 16);
    }
    hkgpConvexHull::fetchPositions(v7, 0, (hkArray<hkVector4f,hkContainerHeapAllocator> *)&array);
    v14 = _mm_shuffle_ps(v5, v5, 0);
    v15 = hkgpConvexHull::getFirstTriangle(v7);
    if ( v15 )
    {
      *(float *)&points.m_vertices = FLOAT_0_000099999997;
      do
      {
        hkgpConvexHull::getPlaneEquation(v7, (hkVector4f *)&buf, v15);
        if ( !(_mm_movemask_ps(_mm_cmpunordps(*(__m128 *)&buf.vfptr, *(__m128 *)&buf.vfptr)) & 7) )
        {
          a4.m128_f32[0] = 0.000099999997;
          v16 = _mm_mul_ps(*(__m128 *)&buf.vfptr, *(__m128 *)&buf.vfptr);
          a4 = _mm_shuffle_ps(a4, a4, 0);
          if ( COERCE_FLOAT((unsigned int)(2
                                         * COERCE_SIGNED_INT(
                                             (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 85))
                                                           + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 0)))
                                                   + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 170)))
                                           - 1.0)) >> 1) < a4.m128_f32[0] )
          {
            v17 = _mm_mul_ps(*(__m128 *)&buf.vfptr, v14);
            do
            {
              v18 = hkgpConvexHull::getVertex(v7, v15, v12);
              v19 = hkgpConvexHull::getSourcePosition(v7, v18);
              v20 = v71;
              points.m_vertices = (const float *)v19;
              if ( v71 == (v72 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
                v20 = v71;
                v19 = (hkVector4f *)points.m_vertices;
              }
              v71 = v20 + 1;
              ++v12;
              array[v20] = _mm_add_ps(v17, v19->m_quad);
            }
            while ( v12 < 3 );
            v12 = 0;
          }
        }
        v15 = hkgpConvexHull::getNext(v7, v15);
      }
      while ( v15 );
    }
    goto LABEL_61;
  }
  v72 = 2147483648;
  array = 0i64;
  v71 = 0;
  v21 = hkgpConvexHull::getCentroid(v7)->m_quad;
  v22 = hkgpConvexHull::getProjectionPlane(v7)->m_quad;
  v23 = 3 * hkgpConvexHull::getNumVertices(v7);
  if ( v23 <= 0 )
  {
    v74.m_enum = 0;
  }
  else
  {
    if ( v23 < 0 )
      v23 = 0;
    hkArrayUtil::_reserve(&v74, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v23, 16);
  }
  hkgpConvexHull::fetchPositions(v7, 0, (hkArray<hkVector4f,hkContainerHeapAllocator> *)&array);
  v24 = _mm_shuffle_ps(v5, v5, 0);
  v25 = hkgpConvexHull::getFirstVertex(v7);
  if ( v25 )
  {
    v26 = _mm_mul_ps(v22, v24);
    v27 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, v24), v22);
    do
    {
      v28 = hkgpConvexHull::getSourcePosition(v7, v25);
      v29 = v71;
      points.m_vertices = (const float *)v28;
      if ( v71 == (v72 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
        v29 = v71;
        v28 = (hkVector4f *)points.m_vertices;
      }
      v71 = v29 + 1;
      array[v29] = _mm_add_ps(v28->m_quad, v26);
      v30 = v71;
      if ( v71 == (v72 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
        v30 = v71;
      }
      v71 = v30 + 1;
      array[v30] = _mm_add_ps(*(__m128 *)points.m_vertices, v27);
      v25 = hkgpConvexHull::getNext(v7, v25);
    }
    while ( v25 );
  }
  points.m_vertices = (const float *)array;
  points.m_numVertices = v71;
  points.m_striding = 16;
  v31 = hkgpConvexHull::build(v7, &points, &config);
  v71 = 0;
  if ( v31 == 3 )
    goto LABEL_62;
  v32 = 0;
  if ( !(v72 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
    v32 = v71;
  }
  points.m_striding = 16;
  array[v32] = v21;
  points.m_vertices = (const float *)array;
  points.m_numVertices = ++v71;
  hkgpConvexHull::build(v7, &points, &config);
  v33 = v79;
  hkgpConvexHull::expandByPlanarMargin(v7, v79, margin);
  v71 = 0;
  if ( v72 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v72);
  return v33;
}

// File Line: 448
// RVA: 0xCAF8B0
void __fastcall anonymous_namespace_::_calcSideInfo_1_4_(hkgpConvexHull *hull, hkgpConvexHull::Triangle *triangle, hkMxVector<4> *sides, hkVector4f *edgeMask, VertexInfo *vertexInfos)
{
  hkgpConvexHull::Triangle *v5; // rsi
  hkVector4f *v6; // r15
  hkMxVector<4> *v7; // rdi
  hkgpConvexHull *v8; // r14
  hkgpConvexHull::Vertex *v9; // rbx
  __m128 *v10; // rax
  __m128 v11; // xmm0
  __int64 v12; // rbx
  int v13; // eax
  __int64 v14; // rdi
  int v15; // ebp
  VertexInfo *v16; // rdi
  __int64 v17; // rdx
  hkSimdFloat32 v18; // ST30_16
  int v19; // esi
  hkSimdFloat32 v20; // ST40_16
  hkVector4f *v21; // rbx
  hkVector4f *v22; // rax
  __m128 v23; // xmm7
  int v24; // ebx
  __m128 v25; // xmm7
  __m128 v26; // xmm7
  __m128i v27; // xmm1
  __m128i v28; // xmm0
  __m128i v29; // xmm6
  hkSimdFloat32 v30; // ST30_16
  hkSimdFloat32 v31; // ST40_16
  hkVector4f *v32; // rbx
  int v33; // esi
  hkVector4f *v34; // rax
  __m128 v35; // xmm0
  int v36; // ebx
  __m128 v37; // xmm7
  __m128 v38; // xmm7
  __m128i v39; // xmm1
  __m128i v40; // xmm0
  __m128i v41; // xmm6
  hkSimdFloat32 v42; // ST30_16
  int v43; // esi
  hkSimdFloat32 v44; // ST40_16
  hkVector4f *v45; // rbx
  int v46; // er15
  hkVector4f *v47; // rax
  __m128 v48; // xmm6
  __m128 v49; // xmm6
  __m128i v50; // xmm1
  __m128i v51; // xmm0
  hkVector4f *v52; // rbx
  hkVector4f *v53; // rax
  __m128 v54; // xmm6
  __m128 v55; // xmm6
  __m128i v56; // xmm1
  __m128i v57; // [rsp+20h] [rbp-68h]
  __m128i v58; // [rsp+20h] [rbp-68h]
  __m128i v59; // [rsp+20h] [rbp-68h]

  v5 = triangle;
  v6 = edgeMask;
  v7 = sides;
  v8 = hull;
  v9 = hkgpConvexHull::getSourcePosition(hull, *(hkgpConvexHull::Vertex **)&triangle[32]);
  v10 = (__m128 *)hkgpConvexHull::getSourcePosition(v8, *(hkgpConvexHull::Vertex **)&v5[24]);
  v11 = *(__m128 *)v9;
  v12 = *(_QWORD *)&v5[48];
  v7->m_vec.v[1].m_quad = _mm_sub_ps(v11, *v10);
  v13 = hkgpConvexHull::getPlaneIndex(v8, v5);
  v14 = *(signed int *)(*(_QWORD *)&v5[24] + 52i64);
  v15 = v13;
  if ( (unsigned int)hkgpConvexHull::getPlaneIndex(v8, (hkgpConvexHull::Triangle *)(v12 & 0xFFFFFFFFFFFFFFFCui64)) != v13 )
    v6->m_quad = _mm_shuffle_ps(_mm_unpacklo_ps(v6->m_quad, query.m_quad), v6->m_quad, 228);
  v16 = &vertexInfos[v14];
  v17 = v16->m_numPlanes;
  switch ( (_DWORD)v17 )
  {
    case 0:
LABEL_20:
      v16->m_planeIndices[v17] = v15;
      ++v16->m_numPlanes;
      return;
    case 1:
      if ( v16->m_planeIndices[0] == v15 )
        return;
      goto LABEL_20;
    case 2:
      if ( v16->m_planeIndices[0] != v15 && v16->m_planeIndices[1] != v15 )
      {
        v16->m_planeIndices[2] = v15;
        ++v16->m_numPlanes;
        v52 = hkgpConvexHull::getPlane(v8, v16->m_planeIndices[1]);
        v53 = hkgpConvexHull::getPlane(v8, v16->m_planeIndices[0]);
        v54 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v52->m_quad, v52->m_quad, 201), v53->m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v53->m_quad, v53->m_quad, 201), v52->m_quad));
        v55 = _mm_mul_ps(_mm_shuffle_ps(v54, v54, 201), hkgpConvexHull::getPlane(v8, v16->m_planeIndices[2])->m_quad);
        v56 = (__m128i)_mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                         _mm_shuffle_ps(v55, v55, 170));
        v16->m_determinant = (hkSimdFloat32)v56;
        v16->m_absDeterminant = (hkSimdFloat32)_mm_srli_epi32(_mm_slli_epi32(v56, 1u), 1u);
      }
      break;
    default:
      if ( v16->m_planeIndices[0] != v15 && v16->m_planeIndices[1] != v15 && v16->m_planeIndices[2] != v15 )
      {
        v18.m_real = (__m128)v16->m_determinant;
        v19 = _mm_cvtsi128_si32(_mm_srli_si128(*(__m128i *)&v16->m_numPlanes, 8));
        v57 = *(__m128i *)&v16->m_numPlanes;
        v20.m_real = (__m128)v16->m_absDeterminant;
        v21 = hkgpConvexHull::getPlane(v8, v19);
        v22 = hkgpConvexHull::getPlane(v8, v15);
        v23 = v21->m_quad;
        v24 = _mm_cvtsi128_si32(_mm_srli_si128(v57, 12));
        v25 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v22->m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v22->m_quad, v22->m_quad, 201), v23));
        v26 = _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), hkgpConvexHull::getPlane(v8, v24)->m_quad);
        v27 = (__m128i)_mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                         _mm_shuffle_ps(v26, v26, 170));
        v28 = _mm_srli_epi32(_mm_slli_epi32(v27, 1u), 1u);
        if ( *(float *)v28.m128i_i32 > v16->m_absDeterminant.m_real.m128_f32[0] )
        {
          v16->m_numPlanes = v57.m128i_i32[0];
          v16->m_planeIndices[0] = v15;
          v16->m_planeIndices[1] = v19;
          v16->m_planeIndices[2] = v24;
          v16->m_determinant = (hkSimdFloat32)v27;
          v16->m_absDeterminant = (hkSimdFloat32)v28;
        }
        v29 = *(__m128i *)&v16->m_numPlanes;
        v58 = *(__m128i *)&v16->m_numPlanes;
        v30.m_real = (__m128)v16->m_determinant;
        v31.m_real = (__m128)v16->m_absDeterminant;
        v32 = hkgpConvexHull::getPlane(v8, v15);
        v33 = _mm_cvtsi128_si32(_mm_srli_si128(v29, 4));
        v34 = hkgpConvexHull::getPlane(v8, v33);
        v35 = v32->m_quad;
        v36 = _mm_cvtsi128_si32(_mm_srli_si128(v29, 12));
        v37 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), v34->m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v34->m_quad, v34->m_quad, 201), v35));
        v38 = _mm_mul_ps(_mm_shuffle_ps(v37, v37, 201), hkgpConvexHull::getPlane(v8, v36)->m_quad);
        v39 = (__m128i)_mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                         _mm_shuffle_ps(v38, v38, 170));
        v40 = _mm_srli_epi32(_mm_slli_epi32(v39, 1u), 1u);
        if ( *(float *)v40.m128i_i32 > v16->m_absDeterminant.m_real.m128_f32[0] )
        {
          v16->m_numPlanes = v58.m128i_i32[0];
          v16->m_planeIndices[0] = v33;
          v16->m_planeIndices[1] = v15;
          v16->m_planeIndices[2] = v36;
          v16->m_determinant = (hkSimdFloat32)v39;
          v16->m_absDeterminant = (hkSimdFloat32)v40;
        }
        v41 = *(__m128i *)&v16->m_numPlanes;
        v42.m_real = (__m128)v16->m_determinant;
        v59 = *(__m128i *)&v16->m_numPlanes;
        v43 = _mm_cvtsi128_si32(_mm_srli_si128(*(__m128i *)&v16->m_numPlanes, 8));
        v44.m_real = (__m128)v16->m_absDeterminant;
        v45 = hkgpConvexHull::getPlane(v8, v43);
        v46 = _mm_cvtsi128_si32(_mm_srli_si128(v41, 4));
        v47 = hkgpConvexHull::getPlane(v8, v46);
        v48 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v45->m_quad, v45->m_quad, 201), v47->m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v47->m_quad, v47->m_quad, 201), v45->m_quad));
        v49 = _mm_mul_ps(_mm_shuffle_ps(v48, v48, 201), hkgpConvexHull::getPlane(v8, v15)->m_quad);
        v50 = (__m128i)_mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)),
                         _mm_shuffle_ps(v49, v49, 170));
        v51 = _mm_srli_epi32(_mm_slli_epi32(v50, 1u), 1u);
        if ( *(float *)v51.m128i_i32 > v16->m_absDeterminant.m_real.m128_f32[0] )
        {
          v16->m_numPlanes = v59.m128i_i32[0];
          v16->m_planeIndices[0] = v46;
          v16->m_planeIndices[1] = v43;
          v16->m_planeIndices[2] = v15;
          v16->m_determinant = (hkSimdFloat32)v50;
          v16->m_absDeterminant = (hkSimdFloat32)v51;
        }
      }
      break;
  }
}

// File Line: 511
// RVA: 0xCAA950
float __fastcall hkgpConvexHull::absoluteScale(hkgpConvexHull *this, const float offset, hkgpConvexHull::AbsoluteScaleConfig *config)
{
  hkgpConvexHullImpl *v3; // rsi
  hkgpConvexHull::AbsoluteScaleConfig *v4; // rbx
  hkgpConvexHull *v5; // rdi
  hkOstream *v6; // rax
  hkOstream *v7; // rax
  hkVector4f *v8; // rax
  __m128 v9; // xmm8
  __m128 v10; // xmm7
  __m128i v11; // xmm10
  __m128 v12; // xmm9
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm15
  __m128 v16; // xmm2
  __m128 v17; // xmm12
  int v18; // ebx
  int v19; // esi
  hkVector4f *v20; // rax
  signed int v21; // eax
  signed int v22; // esi
  __m128 v23; // xmm6
  int v24; // eax
  int v25; // edx
  int v26; // ebx
  hkLifoAllocator *v27; // rax
  hkVector4f *v28; // r8
  int v29; // edx
  char *v30; // rcx
  hkVector4f *v31; // rax
  hkVector4f *v32; // r15
  signed int v33; // eax
  int v34; // eax
  int v35; // er9
  int v36; // eax
  hkVector4f *v37; // rcx
  __int64 v38; // rdx
  __m128 v39; // xmm9
  hkgpConvexHull::Triangle *v40; // r14
  hkStridedVertices v41; // xmm10
  float v42; // xmm15_4
  hkVector4f *v43; // r12
  __m128 v44; // xmm8
  hkVector4f *v45; // rbx
  hkVector4f *v46; // rax
  __m128 v47; // xmm14
  __int64 v48; // rbx
  __m128 v49; // xmm14
  int v50; // eax
  __int64 v51; // rsi
  int v52; // er15
  hkVector4f *v53; // rsi
  __int64 v54; // rdx
  __m128i v55; // xmm6
  __int128 v56; // xmm1
  int v57; // er12
  hkVector4f *v58; // rbx
  hkVector4f *v59; // rax
  __m128 v60; // xmm0
  int v61; // ebx
  __m128 v62; // xmm7
  __m128 v63; // xmm7
  __m128i v64; // xmm1
  __m128i v65; // xmm0
  __m128i v66; // xmm6
  __int128 v67; // xmm0
  __int128 v68; // xmm1
  hkVector4f *v69; // rbx
  int v70; // er12
  hkVector4f *v71; // rax
  __m128 v72; // xmm0
  int v73; // ebx
  __m128 v74; // xmm7
  __m128 v75; // xmm7
  __m128i v76; // xmm1
  __m128i v77; // xmm0
  __m128i v78; // xmm6
  __int128 v79; // xmm1
  int v80; // er12
  hkVector4f *v81; // rbx
  int v82; // er13
  hkVector4f *v83; // rax
  __m128 v84; // xmm6
  __m128 v85; // xmm6
  __m128i v86; // xmm1
  __m128i v87; // xmm0
  hkVector4f *v88; // rbx
  hkVector4f *v89; // rax
  __m128 v90; // xmm6
  __m128 v91; // xmm6
  __m128i v92; // xmm1
  hkVector4f *v93; // r12
  hkVector4f *v94; // rbx
  hkVector4f *v95; // rax
  __m128 v96; // xmm13
  __int64 v97; // rbx
  __m128 v98; // xmm13
  int v99; // eax
  __int64 v100; // rsi
  int v101; // er15
  hkVector4f *v102; // rsi
  __int64 v103; // rdx
  __m128i v104; // xmm6
  __int128 v105; // xmm1
  int v106; // er12
  hkVector4f *v107; // rbx
  hkVector4f *v108; // rax
  __m128 v109; // xmm0
  int v110; // ebx
  __m128 v111; // xmm7
  __m128 v112; // xmm7
  __m128i v113; // xmm1
  __m128i v114; // xmm0
  __m128i v115; // xmm6
  __int128 v116; // xmm0
  __int128 v117; // xmm1
  hkVector4f *v118; // rbx
  int v119; // er12
  hkVector4f *v120; // rax
  __m128 v121; // xmm0
  int v122; // ebx
  __m128 v123; // xmm7
  __m128 v124; // xmm7
  __m128i v125; // xmm1
  __m128i v126; // xmm0
  __m128i v127; // xmm6
  __int128 v128; // xmm1
  int v129; // er12
  hkVector4f *v130; // rbx
  int v131; // er13
  hkVector4f *v132; // rax
  __m128 v133; // xmm6
  __m128 v134; // xmm6
  __m128i v135; // xmm1
  __m128i v136; // xmm0
  hkVector4f *v137; // rbx
  hkVector4f *v138; // rax
  __m128 v139; // xmm6
  __m128 v140; // xmm6
  __m128i v141; // xmm1
  hkVector4f *v142; // r12
  hkVector4f *v143; // rbx
  hkVector4f *v144; // rax
  __m128 v145; // xmm12
  __int64 v146; // rbx
  __m128 v147; // xmm12
  int v148; // eax
  __int64 v149; // rsi
  int v150; // er15
  hkVector4f *v151; // rsi
  __int64 v152; // rdx
  __m128i v153; // xmm6
  __int128 v154; // xmm1
  int v155; // er12
  hkVector4f *v156; // rbx
  hkVector4f *v157; // rax
  __m128 v158; // xmm0
  int v159; // ebx
  __m128 v160; // xmm7
  __m128 v161; // xmm7
  __m128i v162; // xmm1
  __m128i v163; // xmm0
  __m128i v164; // xmm6
  __int128 v165; // xmm0
  __int128 v166; // xmm1
  hkVector4f *v167; // rbx
  int v168; // er12
  hkVector4f *v169; // rax
  __m128 v170; // xmm7
  int v171; // ebx
  __m128 v172; // xmm7
  __m128 v173; // xmm7
  __m128i v174; // xmm1
  __m128i v175; // xmm0
  __m128i v176; // xmm6
  __int128 v177; // xmm1
  int v178; // er12
  hkVector4f *v179; // rbx
  int v180; // er13
  hkVector4f *v181; // rax
  __m128 v182; // xmm6
  __m128 v183; // xmm6
  __m128i v184; // xmm1
  __m128i v185; // xmm0
  hkVector4f *v186; // rbx
  hkVector4f *v187; // rax
  __m128 v188; // xmm6
  __m128 v189; // xmm6
  __m128i v190; // xmm1
  signed int v191; // ecx
  __m128 v192; // xmm14
  __m128 v193; // xmm13
  __m128 v194; // xmm12
  __m128 v195; // xmm1
  float v196; // xmm4_4
  __m128 v197; // xmm1
  __m128 v198; // xmm3
  __m128 v199; // xmm1
  __m128 v200; // xmm0
  __m128 v201; // xmm5
  __m128 v202; // xmm5
  __m128 v203; // xmm3
  __m128 v204; // xmm0
  __m128 v205; // xmm1
  __m128 v206; // xmm2
  __m128 v207; // xmm4
  __m128 v208; // xmm0
  int v209; // ecx
  int v210; // ecx
  __m128 v211; // xmm0
  __m128 v212; // xmm5
  __m128 v213; // xmm5
  __m128 v214; // xmm1
  __m128 v215; // xmm2
  __m128 v216; // xmm2
  __m128 v217; // xmm1
  __m128 v218; // xmm8
  hkgpConvexHull::Vertex *v219; // rsi
  int v220; // eax
  hkVector4f v221; // xmm0
  __m128 v222; // xmm14
  hkVector4f v223; // xmm6
  __int64 v224; // rax
  __m128 v225; // xmm13
  __m128 v226; // xmm9
  __m128 v227; // xmm12
  hkVector4f *v228; // rax
  __m128 v229; // xmm1
  __m128 v230; // xmm4
  __m128 v231; // xmm6
  __m128 v232; // xmm3
  __m128 v233; // xmm0
  __m128 v234; // xmm3
  __m128 v235; // xmm4
  __m128 v236; // xmm5
  __m128 v237; // xmm1
  __m128 v238; // xmm4
  __m128 v239; // xmm5
  __m128 v240; // xmm2
  __m128 v241; // xmm2
  __m128 v242; // xmm5
  __m128 v243; // xmm1
  __m128 v244; // xmm3
  __m128 v245; // xmm2
  __m128 v246; // xmm4
  __m128 v247; // xmm4
  __m128 v248; // xmm0
  __m128 v249; // xmm0
  __m128 v250; // xmm8
  __m128 v251; // xmm1
  signed int v252; // ebx
  hkLifoAllocator *v253; // rax
  int v254; // er8
  signed int v255; // ebx
  hkLifoAllocator *v256; // rax
  int v257; // er8
  int j; // ebx
  hkVector4f *v259; // rax
  __m128 v260; // xmm2
  __m128 v261; // xmm2
  __m128 v262; // xmm0
  int v263; // eax
  int v264; // ebx
  hkLifoAllocator *v265; // rax
  hkLifoAllocator *v266; // rcx
  hkVector4f *v267; // rax
  int v268; // edx
  char *v269; // r8
  int v270; // ebx
  int v271; // er14
  hkVector4f *v272; // rax
  int v273; // ecx
  __m128 v274; // xmm1
  __m128 v275; // xmm1
  __m128 v276; // xmm0
  __m128 v277; // xmm6
  int v278; // esi
  hkgpConvexHull::BuildConfig *v279; // rbx
  hkVector4f *v280; // rax
  hkgpConvexHull::BuildConfig *v281; // rax
  int v282; // eax
  char *v283; // rsi
  signed int v284; // ebx
  hkLifoAllocator *v285; // rax
  int v286; // er8
  int v287; // er8
  float *v288; // rdx
  hkgpConvexHull::Vertex *i; // rbx
  __m128 v290; // xmm1
  __m128 v291; // xmm1
  __m128 v292; // xmm3
  __m128 v293; // xmm2
  __m128 v294; // xmm4
  int v295; // ebx
  int v296; // esi
  int v297; // eax
  hkgpConvexHull::Vertex *v298; // r14
  hkVector4f *v299; // r15
  __m128 v300; // xmm5
  __m128 v301; // xmm1
  __m128 v302; // xmm3
  __m128 v303; // xmm2
  __m128 v304; // xmm4
  __m128 v305; // xmm6
  __m128 v306; // xmm6
  int v307; // eax
  hkgpConvexHull::BuildConfig *v308; // rbx
  hkVector4f *v309; // rax
  hkgpConvexHull::BuildConfig *v310; // rax
  char v311; // si
  signed int v312; // ebx
  int v313; // ecx
  __m128 *v314; // rdx
  hkgpConvexHull::BuildConfig *v315; // rax
  hkgpConvexHull::BuildConfig *v316; // rax
  int v317; // eax
  int v318; // er15
  int v319; // ecx
  int v320; // er10
  const float *v321; // r8
  int v322; // esi
  __m128i v323; // xmm9
  int v324; // er11
  __int64 v325; // r14
  __m128 v326; // xmm4
  __m128i v327; // xmm5
  __m128i v328; // xmm6
  __int64 v329; // rdx
  const float *v330; // rax
  __m128 v331; // xmm1
  __m128 v332; // xmm1
  __m128 v333; // xmm3
  __m128i v334; // xmm2
  int v335; // ebx
  int v336; // edx
  signed __int64 v337; // rax
  int v338; // eax
  int v339; // er14
  __int64 v340; // rax
  float *v341; // rsi
  signed int v342; // ebx
  int v343; // er10
  __int64 v344; // rdx
  float *v345; // r9
  signed __int64 v346; // rcx
  hkgpConvexHull::BuildConfig *v347; // rax
  hkStridedVertices v349; // [rsp+30h] [rbp-C8h]
  hkStridedVertices points; // [rsp+40h] [rbp-B8h]
  hkVector4f *array; // [rsp+50h] [rbp-A8h]
  int v352; // [rsp+58h] [rbp-A0h]
  int v353; // [rsp+5Ch] [rbp-9Ch]
  void *p; // [rsp+60h] [rbp-98h]
  int v355; // [rsp+68h] [rbp-90h]
  hkArray<hkVector4f,hkContainerHeapAllocator> positions; // [rsp+70h] [rbp-88h]
  hkStridedVertices v357; // [rsp+88h] [rbp-70h]
  hkErrStream v358; // [rsp+98h] [rbp-60h]
  __m128 v359; // [rsp+B8h] [rbp-40h]
  __m128 v360; // [rsp+C8h] [rbp-30h]
  __m128 v361; // [rsp+D8h] [rbp-20h]
  int index[4]; // [rsp+E8h] [rbp-10h]
  hkVector4f v363; // [rsp+F8h] [rbp+0h]
  __int128 v364; // [rsp+108h] [rbp+10h]
  __m128 v365; // [rsp+118h] [rbp+20h]
  __m128 v366; // [rsp+128h] [rbp+30h]
  __m128 v367; // [rsp+138h] [rbp+40h]
  hkAabb aabbOut; // [rsp+148h] [rbp+50h]
  __m128i v369; // [rsp+168h] [rbp+70h]
  __int128 v370; // [rsp+178h] [rbp+80h]
  __int128 v371; // [rsp+188h] [rbp+90h]
  __m128i v372; // [rsp+198h] [rbp+A0h]
  hkVector4f v373; // [rsp+1A8h] [rbp+B0h]
  __int128 v374; // [rsp+1B8h] [rbp+C0h]
  __m128i v375; // [rsp+1C8h] [rbp+D0h]
  hkVector4f v376; // [rsp+1D8h] [rbp+E0h]
  __int128 v377; // [rsp+1E8h] [rbp+F0h]
  __m128i v378; // [rsp+1F8h] [rbp+100h]
  hkVector4f v379; // [rsp+208h] [rbp+110h]
  __int128 v380; // [rsp+218h] [rbp+120h]
  __m128i v381; // [rsp+228h] [rbp+130h]
  __int128 v382; // [rsp+238h] [rbp+140h]
  __int128 v383; // [rsp+248h] [rbp+150h]
  __m128i v384; // [rsp+258h] [rbp+160h]
  hkVector4f v385; // [rsp+268h] [rbp+170h]
  __int128 v386; // [rsp+278h] [rbp+180h]
  __m128i v387; // [rsp+288h] [rbp+190h]
  hkVector4f v388; // [rsp+298h] [rbp+1A0h]
  __int128 v389; // [rsp+2A8h] [rbp+1B0h]
  __m128i v390; // [rsp+2B8h] [rbp+1C0h]
  __int128 v391; // [rsp+2C8h] [rbp+1D0h]
  __int128 v392; // [rsp+2D8h] [rbp+1E0h]
  char buf; // [rsp+2E8h] [rbp+1F0h]
  int retaddr; // [rsp+5D8h] [rbp+4E0h]
  unsigned int v395; // [rsp+5E0h] [rbp+4E8h]
  hkResult result; // [rsp+5E8h] [rbp+4F0h]
  int v397; // [rsp+5F0h] [rbp+4F8h]

  result.m_enum = LODWORD(offset);
  v3 = this->m_data;
  v4 = config;
  v5 = this;
  if ( !v3->m_hasIndexing )
  {
    hkErrStream::hkErrStream(&v358, &buf, 512);
    v6 = hkOstream::operator<<((hkOstream *)&v358.vfptr, "No index available (");
    v7 = hkOstream::operator<<(v6, v3->m_uid, (int)v6);
    hkOstream::operator<<(v7, ") hkgpConvexHull::buildIndices need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         2046417030,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         358) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v358.vfptr);
  }
  if ( v5->m_data->m_hasMassProperties )
    v8 = hkgpConvexHull::getCenterOfMass(v5);
  else
    v8 = hkgpConvexHull::getCentroid(v5);
  v9 = v8->m_quad;
  v10 = _mm_shuffle_ps((__m128)LODWORD(v4->m_minComDistance), (__m128)LODWORD(v4->m_minComDistance), 0);
  v11 = (__m128i)_mm_shuffle_ps((__m128)v395, (__m128)v395, 0);
  v360 = v8->m_quad;
  v12 = 0i64;
  positions.m_data = 0i64;
  positions.m_size = 0;
  positions.m_capacityAndFlags = 2147483648;
  points = (hkStridedVertices)v11;
  v361 = v10;
  hkgpConvexHull::fetchPositions(v5, INTERNAL_VERTICES, &positions);
  hkAabbUtil::calcAabb(positions.m_data, positions.m_size, &aabbOut);
  if ( v4->m_method == SKM_VERTICES )
  {
    if ( *(float *)v11.m128i_i32 < 0.0 )
    {
      for ( i = hkgpConvexHull::getFirstVertex(v5); i; i = hkgpConvexHull::getNext(v5, i) )
      {
        v290 = _mm_sub_ps(hkgpConvexHull::getSourcePosition(v5, i)->m_quad, v9);
        v291 = _mm_mul_ps(v290, v290);
        v292 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v291, v291, 85), _mm_shuffle_ps(v291, v291, 0)),
                 _mm_shuffle_ps(v291, v291, 170));
        v293 = _mm_rsqrt_ps(v292);
        v294 = _mm_andnot_ps(
                 _mm_cmpleps(v292, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v293, v292), v293)),
                     _mm_mul_ps(v293, *(__m128 *)_xmm)),
                   v292));
        if ( v294.m128_f32[0] < (float)(0.0 - *(float *)v11.m128i_i32) )
          v11 = (__m128i)_mm_sub_ps((__m128)0i64, v294);
      }
    }
    v295 = 0;
    v296 = 2147483648;
    v349.m_numVertices = 0;
    v349.m_striding = 2147483648;
    v349.m_vertices = 0i64;
    v297 = hkgpConvexHull::getNumVertices(v5);
    if ( v297 <= 0 )
    {
      positions.m_size = 0;
    }
    else
    {
      hkArrayUtil::_reserve(
        (hkResult *)&positions.m_size,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v349,
        v297,
        16);
      v296 = v349.m_striding;
      v295 = v349.m_numVertices;
    }
    v298 = hkgpConvexHull::getFirstVertex(v5);
    if ( v298 )
    {
      while ( 1 )
      {
        v299 = hkgpConvexHull::getSourcePosition(v5, v298);
        v300 = _mm_sub_ps(v299->m_quad, v9);
        v301 = _mm_mul_ps(v300, v300);
        v302 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v301, v301, 85), _mm_shuffle_ps(v301, v301, 0)),
                 _mm_shuffle_ps(v301, v301, 170));
        v303 = _mm_rsqrt_ps(v302);
        v304 = _mm_andnot_ps(
                 _mm_cmpleps(v302, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v303, v302), v303)),
                     _mm_mul_ps(v303, *(__m128 *)_xmm)),
                   v302));
        if ( v304.m128_f32[0] <= v10.m128_f32[0] )
        {
          if ( v295 == (v296 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v349, 16);
            v295 = v349.m_numVertices;
          }
          *(hkVector4f *)&v349.m_vertices[4 * v295] = (hkVector4f)v299->m_quad;
        }
        else
        {
          v305 = _mm_add_ps(v304, (__m128)v11);
          if ( v305.m128_f32[0] < v10.m128_f32[0] )
            v305 = v10;
          v306 = _mm_add_ps(_mm_mul_ps(_mm_div_ps(v305, v304), v300), v9);
          if ( v295 == (v296 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v349, 16);
            v295 = v349.m_numVertices;
          }
          *(__m128 *)&v349.m_vertices[4 * v295] = v306;
        }
        v295 = v349.m_numVertices++ + 1;
        v298 = hkgpConvexHull::getNext(v5, v298);
        if ( !v298 )
          break;
        v296 = v349.m_striding;
      }
    }
    v307 = hkgpConvexHull::getDimensions(v5);
    points.m_numVertices = v295;
    points.m_striding = 16;
    points.m_vertices = v349.m_vertices;
    if ( v307 == 2 )
    {
      v308 = hkgpConvexHull::getConfiguration(v5);
      v309 = hkgpConvexHull::getProjectionPlane(v5);
      hkgpConvexHull::buildPlanar(v5, &points, v309, v308);
    }
    else
    {
      v310 = hkgpConvexHull::getConfiguration(v5);
      hkgpConvexHull::build(v5, &points, v310);
    }
    v287 = v349.m_striding;
    v349.m_numVertices = 0;
    if ( v349.m_striding < 0 )
      goto LABEL_192;
    v288 = (float *)v349.m_vertices;
    goto LABEL_191;
  }
  if ( v4->m_method != 1 )
  {
    if ( v4->m_method != 2 )
      goto LABEL_192;
    v13 = (__m128)LODWORD(v4->m_featurePreservationFactor);
    v12 = v10;
    v359 = v10;
    v14 = _mm_shuffle_ps(v13, v13, 0);
    v357 = (hkStridedVertices)xmmword_141A712A0;
    v15 = (__m128)xmmword_141A712A0;
    v16 = _mm_cmpltps(v14, query.m_quad);
    v349 = (hkStridedVertices)xmmword_141A712A0;
    v17 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v16, v14), _mm_andnot_ps(v16, query.m_quad)));
    v365 = v17;
    if ( *(float *)v11.m128i_i32 < 0.0 )
    {
      v18 = 0;
      v19 = hkgpConvexHull::getNumPlanes(v5);
      if ( v19 > 0 )
      {
        do
        {
          v20 = hkgpConvexHull::getPlane(v5, v18++);
          v15 = _mm_min_ps(
                  v15,
                  _mm_sub_ps(
                    (__m128)0i64,
                    hkgpConvexHull::getMinimumDistanceFromPlane(v5, (hkSimdFloat32 *)&v358, v20)->m_real));
        }
        while ( v18 < v19 );
      }
      v15 = _mm_mul_ps(v15, (__m128)xmmword_141A711D0);
      v357 = (hkStridedVertices)xmmword_141A712A0;
      v349 = (hkStridedVertices)v15;
    }
    v21 = 0;
    v22 = 0;
    v23 = _mm_sub_ps((__m128)0i64, v15);
    v366 = v23;
    if ( *(float *)v11.m128i_i32 < v23.m128_f32[0] )
      v21 = 1;
    retaddr = v21;
    if ( v17.m128_f32[0] > 0.0 )
      v22 = 1;
    v397 = v22;
    if ( v21 || v22 )
    {
      result.m_enum = LODWORD(FLOAT_0_0000099999997);
      v367 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0);
      v24 = hkgpConvexHull::getNumVertices(v5);
      v25 = 0;
      array = 0i64;
      v353 = 2147483648;
      v26 = v24;
      v352 = 0;
      v355 = v24;
      if ( v24 )
      {
        v27 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v28 = (hkVector4f *)v27->m_cur;
        v29 = (48 * v26 + 127) & 0xFFFFFF80;
        v30 = (char *)v28 + v29;
        if ( v29 > v27->m_slabSize || v30 > v27->m_end )
        {
          v31 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v27, v29);
          v25 = v352;
          array = v31;
        }
        else
        {
          v27->m_cur = v30;
          v25 = v352;
          array = v28;
        }
      }
      else
      {
        array = 0i64;
      }
      v32 = array;
      p = array;
      v353 = v26 | 0x80000000;
      v33 = (v26 | 0x80000000) & 0x3FFFFFFF;
      if ( v33 < v26 )
      {
        v34 = 2 * v33;
        v35 = v26;
        if ( v26 < v34 )
          v35 = v34;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v35, 48);
        v32 = (hkVector4f *)p;
        v25 = v352;
      }
      v36 = v26 - v25;
      v37 = &array[3 * v25];
      v38 = v26 - v25;
      if ( v36 > 0 )
      {
        do
        {
          if ( v37 )
          {
            v37->m_quad.m128_i32[0] = 0;
            v37[1] = (hkVector4f)::aabbOut.m_quad;
          }
          v37 += 3;
          --v38;
        }
        while ( v38 );
        v32 = (hkVector4f *)p;
      }
      v352 = v26;
      v39 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v11, 1u), 1u);
      v40 = hkgpConvexHull::getFirstTriangle(v5);
      if ( v40 )
      {
        v41 = v357;
        v42 = v367.m128_f32[0];
        while ( 1 )
        {
          v43 = array;
          v44 = 0i64;
          v45 = hkgpConvexHull::getSourcePosition(v5, *(hkgpConvexHull::Vertex **)&v40[24]);
          v46 = hkgpConvexHull::getSourcePosition(v5, *(hkgpConvexHull::Vertex **)&v40[16]);
          v47 = v45->m_quad;
          v48 = *(_QWORD *)&v40[40];
          v49 = _mm_sub_ps(v47, v46->m_quad);
          v50 = hkgpConvexHull::getPlaneIndex(v5, v40);
          v51 = *(signed int *)(*(_QWORD *)&v40[16] + 52i64);
          v52 = v50;
          if ( hkgpConvexHull::getPlaneIndex(v5, (hkgpConvexHull::Triangle *)(v48 & 0xFFFFFFFFFFFFFFFCui64)) != v50 )
            v44.m128_f32[0] = 1.0;
          v53 = &v43[3 * v51];
          v54 = v53->m_quad.m128_i32[0];
          if ( !(_DWORD)v54 )
            goto LABEL_56;
          if ( (_DWORD)v54 == 1 )
            break;
          if ( (_DWORD)v54 == 2 )
          {
            if ( v53->m_quad.m128_i32[1] != v52 && v53->m_quad.m128_i32[2] != v52 )
            {
              v53->m_quad.m128_i32[3] = v52;
              ++v53->m_quad.m128_i32[0];
              v88 = hkgpConvexHull::getPlane(v5, v53->m_quad.m128_i32[2]);
              v89 = hkgpConvexHull::getPlane(v5, v53->m_quad.m128_i32[1]);
              v90 = _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v88->m_quad, v88->m_quad, 201), v89->m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v89->m_quad, v89->m_quad, 201), v88->m_quad));
              v91 = _mm_mul_ps(
                      _mm_shuffle_ps(v90, v90, 201),
                      hkgpConvexHull::getPlane(v5, v53->m_quad.m128_i32[3])->m_quad);
              v92 = (__m128i)_mm_add_ps(
                               _mm_add_ps(_mm_shuffle_ps(v91, v91, 85), _mm_shuffle_ps(v91, v91, 0)),
                               _mm_shuffle_ps(v91, v91, 170));
              v53[1] = (hkVector4f)v92;
              v53[2] = (hkVector4f)_mm_srli_epi32(_mm_slli_epi32(v92, 1u), 1u);
            }
          }
          else if ( v53->m_quad.m128_i32[1] != v52 && v53->m_quad.m128_i32[2] != v52 && v53->m_quad.m128_i32[3] != v52 )
          {
            v55 = (__m128i)v53->m_quad;
            v56 = (__int128)v53[2];
            v388.m_quad = (__m128)v53[1];
            v387 = v55;
            v57 = _mm_cvtsi128_si32(_mm_srli_si128(v55, 8));
            v389 = v56;
            v58 = hkgpConvexHull::getPlane(v5, v57);
            v59 = hkgpConvexHull::getPlane(v5, v52);
            v60 = v58->m_quad;
            v61 = _mm_cvtsi128_si32(_mm_srli_si128(v55, 12));
            v62 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v60, v60, 201), v59->m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v59->m_quad, v59->m_quad, 201), v60));
            v63 = _mm_mul_ps(_mm_shuffle_ps(v62, v62, 201), hkgpConvexHull::getPlane(v5, v61)->m_quad);
            v64 = (__m128i)_mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v63, v63, 85), _mm_shuffle_ps(v63, v63, 0)),
                             _mm_shuffle_ps(v63, v63, 170));
            v65 = _mm_srli_epi32(_mm_slli_epi32(v64, 1u), 1u);
            if ( *(float *)v65.m128i_i32 > v53[2].m_quad.m128_f32[0] )
            {
              v53->m_quad.m128_i32[0] = v387.m128i_i32[0];
              v53->m_quad.m128_i32[1] = v52;
              v53->m_quad.m128_i32[2] = v57;
              v53->m_quad.m128_i32[3] = v61;
              v53[1] = (hkVector4f)v64;
              v53[2] = (hkVector4f)v65;
            }
            v67 = (__int128)v53[1];
            v68 = (__int128)v53[2];
            v369 = (__m128i)v53->m_quad;
            v66 = v369;
            v370 = v67;
            v371 = v68;
            v69 = hkgpConvexHull::getPlane(v5, v52);
            v70 = _mm_cvtsi128_si32(_mm_srli_si128(v66, 4));
            v71 = hkgpConvexHull::getPlane(v5, v70);
            v72 = v69->m_quad;
            v73 = _mm_cvtsi128_si32(_mm_srli_si128(v66, 12));
            v74 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v72, v72, 201), v71->m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v71->m_quad, v71->m_quad, 201), v72));
            v75 = _mm_mul_ps(_mm_shuffle_ps(v74, v74, 201), hkgpConvexHull::getPlane(v5, v73)->m_quad);
            v76 = (__m128i)_mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v75, v75, 85), _mm_shuffle_ps(v75, v75, 0)),
                             _mm_shuffle_ps(v75, v75, 170));
            v77 = _mm_srli_epi32(_mm_slli_epi32(v76, 1u), 1u);
            if ( *(float *)v77.m128i_i32 > v53[2].m_quad.m128_f32[0] )
            {
              v53->m_quad.m128_i32[0] = v369.m128i_i32[0];
              v53->m_quad.m128_i32[1] = v70;
              v53->m_quad.m128_i32[2] = v52;
              v53->m_quad.m128_i32[3] = v73;
              v53[1] = (hkVector4f)v76;
              v53[2] = (hkVector4f)v77;
            }
            v78 = (__m128i)v53->m_quad;
            v79 = (__int128)v53[2];
            v385.m_quad = (__m128)v53[1];
            v384 = v78;
            v80 = _mm_cvtsi128_si32(_mm_srli_si128(v78, 8));
            v386 = v79;
            v81 = hkgpConvexHull::getPlane(v5, v80);
            v82 = _mm_cvtsi128_si32(_mm_srli_si128(v78, 4));
            v83 = hkgpConvexHull::getPlane(v5, v82);
            v84 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v81->m_quad, v81->m_quad, 201), v83->m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v83->m_quad, v83->m_quad, 201), v81->m_quad));
            v85 = _mm_mul_ps(_mm_shuffle_ps(v84, v84, 201), hkgpConvexHull::getPlane(v5, v52)->m_quad);
            v86 = (__m128i)_mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v85, v85, 85), _mm_shuffle_ps(v85, v85, 0)),
                             _mm_shuffle_ps(v85, v85, 170));
            v87 = _mm_srli_epi32(_mm_slli_epi32(v86, 1u), 1u);
            if ( *(float *)v87.m128i_i32 > v53[2].m_quad.m128_f32[0] )
            {
              v53->m_quad.m128_i32[0] = v384.m128i_i32[0];
              v53->m_quad.m128_i32[1] = v82;
              v53->m_quad.m128_i32[2] = v80;
              v53->m_quad.m128_i32[3] = v52;
              v53[1] = (hkVector4f)v86;
              v53[2] = (hkVector4f)v87;
            }
          }
LABEL_57:
          v93 = array;
          v94 = hkgpConvexHull::getSourcePosition(v5, *(hkgpConvexHull::Vertex **)&v40[32]);
          v95 = hkgpConvexHull::getSourcePosition(v5, *(hkgpConvexHull::Vertex **)&v40[24]);
          v96 = v94->m_quad;
          v97 = *(_QWORD *)&v40[48];
          v98 = _mm_sub_ps(v96, v95->m_quad);
          v99 = hkgpConvexHull::getPlaneIndex(v5, v40);
          v100 = *(signed int *)(*(_QWORD *)&v40[24] + 52i64);
          v101 = v99;
          if ( hkgpConvexHull::getPlaneIndex(v5, (hkgpConvexHull::Triangle *)(v97 & 0xFFFFFFFFFFFFFFFCui64)) != v99 )
            v44 = _mm_shuffle_ps(_mm_unpacklo_ps(v44, query.m_quad), v44, 228);
          v102 = &v93[3 * v100];
          v103 = v102->m_quad.m128_i32[0];
          switch ( (_DWORD)v103 )
          {
            case 0:
              goto LABEL_75;
            case 1:
              if ( v102->m_quad.m128_i32[1] == v101 )
                break;
LABEL_75:
              v102->m_quad.m128_i32[v103 + 1] = v101;
              ++v102->m_quad.m128_i32[0];
              break;
            case 2:
              if ( v102->m_quad.m128_i32[1] != v101 && v102->m_quad.m128_i32[2] != v101 )
              {
                v102->m_quad.m128_i32[3] = v101;
                ++v102->m_quad.m128_i32[0];
                v137 = hkgpConvexHull::getPlane(v5, v102->m_quad.m128_i32[2]);
                v138 = hkgpConvexHull::getPlane(v5, v102->m_quad.m128_i32[1]);
                v139 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v137->m_quad, v137->m_quad, 201), v138->m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v138->m_quad, v138->m_quad, 201), v137->m_quad));
                v140 = _mm_mul_ps(
                         _mm_shuffle_ps(v139, v139, 201),
                         hkgpConvexHull::getPlane(v5, v102->m_quad.m128_i32[3])->m_quad);
                v141 = (__m128i)_mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v140, v140, 85), _mm_shuffle_ps(v140, v140, 0)),
                                  _mm_shuffle_ps(v140, v140, 170));
                v102[1] = (hkVector4f)v141;
                v102[2] = (hkVector4f)_mm_srli_epi32(_mm_slli_epi32(v141, 1u), 1u);
              }
              break;
            default:
              if ( v102->m_quad.m128_i32[1] != v101
                && v102->m_quad.m128_i32[2] != v101
                && v102->m_quad.m128_i32[3] != v101 )
              {
                v104 = (__m128i)v102->m_quad;
                v105 = (__int128)v102[2];
                v379.m_quad = (__m128)v102[1];
                v378 = v104;
                v106 = _mm_cvtsi128_si32(_mm_srli_si128(v104, 8));
                v380 = v105;
                v107 = hkgpConvexHull::getPlane(v5, v106);
                v108 = hkgpConvexHull::getPlane(v5, v101);
                v109 = v107->m_quad;
                v110 = _mm_cvtsi128_si32(_mm_srli_si128(v104, 12));
                v111 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v109, v109, 201), v108->m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v108->m_quad, v108->m_quad, 201), v109));
                v112 = _mm_mul_ps(_mm_shuffle_ps(v111, v111, 201), hkgpConvexHull::getPlane(v5, v110)->m_quad);
                v113 = (__m128i)_mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v112, v112, 85), _mm_shuffle_ps(v112, v112, 0)),
                                  _mm_shuffle_ps(v112, v112, 170));
                v114 = _mm_srli_epi32(_mm_slli_epi32(v113, 1u), 1u);
                if ( *(float *)v114.m128i_i32 > v102[2].m_quad.m128_f32[0] )
                {
                  v102->m_quad.m128_i32[0] = v378.m128i_i32[0];
                  v102->m_quad.m128_i32[1] = v101;
                  v102->m_quad.m128_i32[2] = v106;
                  v102->m_quad.m128_i32[3] = v110;
                  v102[1] = (hkVector4f)v113;
                  v102[2] = (hkVector4f)v114;
                }
                v116 = (__int128)v102[1];
                v117 = (__int128)v102[2];
                v390 = (__m128i)v102->m_quad;
                v115 = v390;
                v391 = v116;
                v392 = v117;
                v118 = hkgpConvexHull::getPlane(v5, v101);
                v119 = _mm_cvtsi128_si32(_mm_srli_si128(v115, 4));
                v120 = hkgpConvexHull::getPlane(v5, v119);
                v121 = v118->m_quad;
                v122 = _mm_cvtsi128_si32(_mm_srli_si128(v115, 12));
                v123 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v121, v121, 201), v120->m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v120->m_quad, v120->m_quad, 201), v121));
                v124 = _mm_mul_ps(_mm_shuffle_ps(v123, v123, 201), hkgpConvexHull::getPlane(v5, v122)->m_quad);
                v125 = (__m128i)_mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v124, v124, 85), _mm_shuffle_ps(v124, v124, 0)),
                                  _mm_shuffle_ps(v124, v124, 170));
                v126 = _mm_srli_epi32(_mm_slli_epi32(v125, 1u), 1u);
                if ( *(float *)v126.m128i_i32 > v102[2].m_quad.m128_f32[0] )
                {
                  v102->m_quad.m128_i32[0] = v390.m128i_i32[0];
                  v102->m_quad.m128_i32[1] = v119;
                  v102->m_quad.m128_i32[2] = v101;
                  v102->m_quad.m128_i32[3] = v122;
                  v102[1] = (hkVector4f)v125;
                  v102[2] = (hkVector4f)v126;
                }
                v127 = (__m128i)v102->m_quad;
                v128 = (__int128)v102[2];
                v373.m_quad = (__m128)v102[1];
                v372 = v127;
                v129 = _mm_cvtsi128_si32(_mm_srli_si128(v127, 8));
                v374 = v128;
                v130 = hkgpConvexHull::getPlane(v5, v129);
                v131 = _mm_cvtsi128_si32(_mm_srli_si128(v127, 4));
                v132 = hkgpConvexHull::getPlane(v5, v131);
                v133 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v130->m_quad, v130->m_quad, 201), v132->m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v132->m_quad, v132->m_quad, 201), v130->m_quad));
                v134 = _mm_mul_ps(_mm_shuffle_ps(v133, v133, 201), hkgpConvexHull::getPlane(v5, v101)->m_quad);
                v135 = (__m128i)_mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v134, v134, 85), _mm_shuffle_ps(v134, v134, 0)),
                                  _mm_shuffle_ps(v134, v134, 170));
                v136 = _mm_srli_epi32(_mm_slli_epi32(v135, 1u), 1u);
                if ( *(float *)v136.m128i_i32 > v102[2].m_quad.m128_f32[0] )
                {
                  v102->m_quad.m128_i32[0] = v372.m128i_i32[0];
                  v102->m_quad.m128_i32[1] = v131;
                  v102->m_quad.m128_i32[2] = v129;
                  v102->m_quad.m128_i32[3] = v101;
                  v102[1] = (hkVector4f)v135;
                  v102[2] = (hkVector4f)v136;
                }
              }
              break;
          }
          v142 = array;
          v143 = hkgpConvexHull::getSourcePosition(v5, *(hkgpConvexHull::Vertex **)&v40[16]);
          v144 = hkgpConvexHull::getSourcePosition(v5, *(hkgpConvexHull::Vertex **)&v40[32]);
          v145 = v143->m_quad;
          v146 = *(_QWORD *)&v40[56];
          v147 = _mm_sub_ps(v145, v144->m_quad);
          v148 = hkgpConvexHull::getPlaneIndex(v5, v40);
          v149 = *(signed int *)(*(_QWORD *)&v40[32] + 52i64);
          v150 = v148;
          if ( hkgpConvexHull::getPlaneIndex(v5, (hkgpConvexHull::Triangle *)(v146 & 0xFFFFFFFFFFFFFFFCui64)) != v148 )
            v44 = _mm_shuffle_ps(v44, _mm_unpackhi_ps(v44, query.m_quad), 180);
          v151 = &v142[3 * v149];
          v152 = v151->m_quad.m128_i32[0];
          switch ( (_DWORD)v152 )
          {
            case 0:
LABEL_94:
              v151->m_quad.m128_i32[v152 + 1] = v150;
              ++v151->m_quad.m128_i32[0];
              break;
            case 1:
              if ( v151->m_quad.m128_i32[1] != v150 )
                goto LABEL_94;
              break;
            case 2:
              if ( v151->m_quad.m128_i32[1] != v150 && v151->m_quad.m128_i32[2] != v150 )
              {
                v151->m_quad.m128_i32[3] = v150;
                ++v151->m_quad.m128_i32[0];
                v186 = hkgpConvexHull::getPlane(v5, v151->m_quad.m128_i32[2]);
                v187 = hkgpConvexHull::getPlane(v5, v151->m_quad.m128_i32[1]);
                v188 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v186->m_quad, v186->m_quad, 201), v187->m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v187->m_quad, v187->m_quad, 201), v186->m_quad));
                v189 = _mm_mul_ps(
                         _mm_shuffle_ps(v188, v188, 201),
                         hkgpConvexHull::getPlane(v5, v151->m_quad.m128_i32[3])->m_quad);
                v190 = (__m128i)_mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v189, v189, 85), _mm_shuffle_ps(v189, v189, 0)),
                                  _mm_shuffle_ps(v189, v189, 170));
                v151[1] = (hkVector4f)v190;
                v151[2] = (hkVector4f)_mm_srli_epi32(_mm_slli_epi32(v190, 1u), 1u);
              }
              break;
            default:
              if ( v151->m_quad.m128_i32[1] != v150
                && v151->m_quad.m128_i32[2] != v150
                && v151->m_quad.m128_i32[3] != v150 )
              {
                v153 = (__m128i)v151->m_quad;
                v154 = (__int128)v151[2];
                v376.m_quad = (__m128)v151[1];
                v375 = v153;
                v155 = _mm_cvtsi128_si32(_mm_srli_si128(v153, 8));
                v377 = v154;
                v156 = hkgpConvexHull::getPlane(v5, v155);
                v157 = hkgpConvexHull::getPlane(v5, v150);
                v158 = v156->m_quad;
                v159 = _mm_cvtsi128_si32(_mm_srli_si128(v153, 12));
                v160 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v158, v158, 201), v157->m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v157->m_quad, v157->m_quad, 201), v158));
                v161 = _mm_mul_ps(_mm_shuffle_ps(v160, v160, 201), hkgpConvexHull::getPlane(v5, v159)->m_quad);
                v162 = (__m128i)_mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v161, v161, 85), _mm_shuffle_ps(v161, v161, 0)),
                                  _mm_shuffle_ps(v161, v161, 170));
                v163 = _mm_srli_epi32(_mm_slli_epi32(v162, 1u), 1u);
                if ( *(float *)v163.m128i_i32 > v151[2].m_quad.m128_f32[0] )
                {
                  v151->m_quad.m128_i32[0] = v375.m128i_i32[0];
                  v151->m_quad.m128_i32[1] = v150;
                  v151->m_quad.m128_i32[2] = v155;
                  v151->m_quad.m128_i32[3] = v159;
                  v151[1] = (hkVector4f)v162;
                  v151[2] = (hkVector4f)v163;
                }
                v165 = (__int128)v151[1];
                v166 = (__int128)v151[2];
                v381 = (__m128i)v151->m_quad;
                v164 = v381;
                v382 = v165;
                v383 = v166;
                v167 = hkgpConvexHull::getPlane(v5, v150);
                v168 = _mm_cvtsi128_si32(_mm_srli_si128(v164, 4));
                v169 = hkgpConvexHull::getPlane(v5, v168);
                v170 = v167->m_quad;
                v171 = _mm_cvtsi128_si32(_mm_srli_si128(v164, 12));
                v172 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v170, v170, 201), v169->m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v169->m_quad, v169->m_quad, 201), v170));
                v173 = _mm_mul_ps(_mm_shuffle_ps(v172, v172, 201), hkgpConvexHull::getPlane(v5, v171)->m_quad);
                v174 = (__m128i)_mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v173, v173, 85), _mm_shuffle_ps(v173, v173, 0)),
                                  _mm_shuffle_ps(v173, v173, 170));
                v175 = _mm_srli_epi32(_mm_slli_epi32(v174, 1u), 1u);
                if ( *(float *)v175.m128i_i32 > v151[2].m_quad.m128_f32[0] )
                {
                  v151->m_quad.m128_i32[0] = v381.m128i_i32[0];
                  v151->m_quad.m128_i32[1] = v168;
                  v151->m_quad.m128_i32[2] = v150;
                  v151->m_quad.m128_i32[3] = v171;
                  v151[1] = (hkVector4f)v174;
                  v151[2] = (hkVector4f)v175;
                }
                v176 = (__m128i)v151->m_quad;
                v177 = (__int128)v151[2];
                v363.m_quad = (__m128)v151[1];
                *(__m128i *)index = v176;
                v178 = _mm_cvtsi128_si32(_mm_srli_si128(v176, 8));
                v364 = v177;
                v179 = hkgpConvexHull::getPlane(v5, v178);
                v180 = _mm_cvtsi128_si32(_mm_srli_si128(v176, 4));
                v181 = hkgpConvexHull::getPlane(v5, v180);
                v182 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v179->m_quad, v179->m_quad, 201), v181->m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v181->m_quad, v181->m_quad, 201), v179->m_quad));
                v183 = _mm_mul_ps(_mm_shuffle_ps(v182, v182, 201), hkgpConvexHull::getPlane(v5, v150)->m_quad);
                v184 = (__m128i)_mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v183, v183, 85), _mm_shuffle_ps(v183, v183, 0)),
                                  _mm_shuffle_ps(v183, v183, 170));
                v185 = _mm_srli_epi32(_mm_slli_epi32(v184, 1u), 1u);
                if ( *(float *)v185.m128i_i32 > v151[2].m_quad.m128_f32[0] )
                {
                  v151->m_quad.m128_i32[0] = index[0];
                  v151->m_quad.m128_i32[1] = v180;
                  v151->m_quad.m128_i32[2] = v178;
                  v151->m_quad.m128_i32[3] = v150;
                  v151[1] = (hkVector4f)v184;
                  v151[2] = (hkVector4f)v185;
                }
              }
              break;
          }
          if ( retaddr )
          {
            v191 = (signed int)(float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 85))
                                             + COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 0)))
                                     + COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 170)));
            if ( v191 )
            {
              v192 = _mm_mul_ps(v49, v49);
              v193 = _mm_mul_ps(v98, v98);
              v194 = _mm_mul_ps(v147, v147);
              v195 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v192, v192, 85), _mm_shuffle_ps(v192, v192, 0)),
                       _mm_shuffle_ps(v192, v192, 170));
              LODWORD(v196) = (unsigned __int128)_mm_andnot_ps(
                                                   _mm_cmpleps(v195, (__m128)0i64),
                                                   _mm_mul_ps(_mm_rsqrt_ps(v195), v195));
              v197 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v193, v193, 85), _mm_shuffle_ps(v193, v193, 0)),
                       _mm_shuffle_ps(v193, v193, 170));
              v198 = _mm_andnot_ps(_mm_cmpleps(v197, (__m128)0i64), _mm_mul_ps(_mm_rsqrt_ps(v197), v197));
              v199 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v194, v194, 85), _mm_shuffle_ps(v194, v194, 0)),
                       _mm_shuffle_ps(v194, v194, 170));
              v200 = ::aabbOut.m_quad;
              v200.m128_f32[0] = v196;
              v201 = _mm_shuffle_ps(_mm_unpacklo_ps(v200, v198), v200, 228);
              v202 = _mm_shuffle_ps(
                       v201,
                       _mm_unpackhi_ps(
                         v201,
                         _mm_andnot_ps(_mm_cmpleps(v199, (__m128)0i64), _mm_mul_ps(_mm_rsqrt_ps(v199), v199))),
                       180);
              v203 = _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v202, v202, 85), _mm_shuffle_ps(v202, v202, 0)),
                         _mm_shuffle_ps(v202, v202, 170)),
                       (__m128)xmmword_141A711B0);
              v204 = _mm_sub_ps(v203, v202);
              v205 = _mm_mul_ps(_mm_shuffle_ps(v204, v204, 78), v204);
              v206 = _mm_mul_ps(_mm_shuffle_ps(v205, v205, 177), v205);
              v207 = _mm_andnot_ps(_mm_cmpleps(v206, (__m128)0i64), _mm_mul_ps(_mm_rsqrt_ps(v206), v206));
              if ( v207.m128_f32[0] >= v42 )
              {
                v208 = _mm_cmpltps((__m128)0i64, v44);
                v209 = v191 - 1;
                if ( v209 )
                {
                  v210 = v209 - 1;
                  if ( v210 )
                  {
                    if ( v210 == 1 )
                    {
                      v211 = _mm_rcp_ps(v203);
                      v39 = _mm_min_ps(
                              v39,
                              _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v203, v211)), v211), v207));
                    }
                    goto LABEL_105;
                  }
                  v212 = _mm_and_ps(v202, v208);
                  v213 = _mm_max_ps(
                           _mm_shuffle_ps(v212, v212, 170),
                           _mm_max_ps(_mm_shuffle_ps(v212, v212, 85), _mm_shuffle_ps(v212, v212, 0)));
                  v214 = _mm_rcp_ps(v213);
                  v215 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v214, v213)), v214), v207);
                }
                else
                {
                  v216 = _mm_or_ps(_mm_andnot_ps(v208, (__m128)v41), _mm_and_ps(v202, v208));
                  v215 = _mm_min_ps(
                           _mm_shuffle_ps(v216, v216, 170),
                           _mm_min_ps(_mm_shuffle_ps(v216, v216, 85), _mm_shuffle_ps(v216, v216, 0)));
                }
                v39 = _mm_min_ps(v39, v215);
              }
            }
          }
LABEL_105:
          v40 = hkgpConvexHull::getNext(v5, v40);
          if ( !v40 )
          {
            v32 = (hkVector4f *)p;
            v26 = v352;
            v11 = (__m128i)points;
            v15 = (__m128)v349;
            v23 = v366;
            v22 = v397;
            goto LABEL_107;
          }
        }
        if ( v53->m_quad.m128_i32[1] == v52 )
          goto LABEL_57;
LABEL_56:
        v53->m_quad.m128_i32[v54 + 1] = v52;
        ++v53->m_quad.m128_i32[0];
        goto LABEL_57;
      }
LABEL_107:
      if ( retaddr )
      {
        v217 = _mm_cmpltps(v39, v15);
        v11 = (__m128i)_mm_or_ps(_mm_andnot_ps(v217, _mm_sub_ps((__m128)0i64, v39)), _mm_and_ps(v217, v23));
        points = (hkStridedVertices)v11;
      }
      if ( v22 )
      {
        v218 = (__m128)xmmword_141A712B0;
        v219 = hkgpConvexHull::getFirstVertex(v5);
        if ( v219 )
        {
          do
          {
            v220 = hkgpConvexHull::getIndex(v5, v219);
            v221.m_quad = (__m128)array[3 * v220];
            v222 = array[3 * v220 + 1].m_quad;
            v223.m_quad = (__m128)array[3 * v220 + 2];
            v224 = (__int64)array[3 * v220];
            *(hkVector4f *)index = (hkVector4f)v221.m_quad;
            if ( (signed int)v224 >= 3 )
            {
              v225 = hkgpConvexHull::getPlane(v5, SHIDWORD(v224))->m_quad;
              v226 = hkgpConvexHull::getPlane(v5, index[2])->m_quad;
              v227 = hkgpConvexHull::getPlane(v5, index[3])->m_quad;
              if ( v223.m_quad.m128_f32[0] > 0.00000011920929 )
              {
                v228 = hkgpConvexHull::getSourcePosition(v5, v219);
                v229 = _mm_shuffle_ps(v227, v227, 201);
                v230 = _mm_shuffle_ps(v226, v226, 201);
                v231 = _mm_shuffle_ps(v228->m_quad, _mm_unpackhi_ps(v228->m_quad, query.m_quad), 196);
                v232 = _mm_sub_ps(_mm_mul_ps(v229, v226), _mm_mul_ps(v230, v227));
                v233 = _mm_shuffle_ps(v225, v225, 201);
                v234 = _mm_shuffle_ps(v232, v232, 201);
                v235 = _mm_sub_ps(_mm_mul_ps(v230, v225), _mm_mul_ps(v233, v226));
                v236 = _mm_sub_ps(_mm_mul_ps(v233, v227), _mm_mul_ps(v229, v225));
                v237 = 0i64;
                v238 = _mm_shuffle_ps(v235, v235, 201);
                v239 = _mm_shuffle_ps(v236, v236, 201);
                v237.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v225, v225, 255));
                v240 = _mm_shuffle_ps(_mm_unpacklo_ps(v237, _mm_shuffle_ps(v226, v226, 255)), v237, 228);
                v241 = _mm_shuffle_ps(v240, _mm_unpackhi_ps(v240, _mm_shuffle_ps(v227, v227, 255)), 180);
                v242 = _mm_sub_ps(
                         _mm_add_ps(_mm_add_ps(v239, v234), v238),
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(v241, v241, 85), v239),
                               _mm_mul_ps(_mm_shuffle_ps(v241, v241, 0), v234)),
                             _mm_mul_ps(_mm_shuffle_ps(v241, v241, 170), v238)),
                           _mm_mul_ps(v222, v231)));
                v243 = _mm_mul_ps(v242, v242);
                v244 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v243, v243, 85), _mm_shuffle_ps(v243, v243, 0)),
                         _mm_shuffle_ps(v243, v243, 170));
                v245 = _mm_rsqrt_ps(v244);
                v246 = _mm_add_ps(
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_andnot_ps(
                               _mm_cmpleps(v244, (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v245, v244), v245)),
                                 _mm_mul_ps(*(__m128 *)_xmm, v245))),
                             _mm_shuffle_ps((__m128)v395, (__m128)v395, 0)),
                           v242),
                         v231);
                v247 = _mm_mul_ps(_mm_shuffle_ps(v246, _mm_unpackhi_ps(v246, query.m_quad), 196), v225);
                v248 = _mm_add_ps(_mm_shuffle_ps(v247, v247, 78), v247);
                v218 = _mm_min_ps(
                         v218,
                         (__m128)_mm_srli_epi32(
                                   _mm_slli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v248, v248, 177), v248), 1u),
                                   1u));
              }
            }
            v219 = hkgpConvexHull::getNext(v5, v219);
          }
          while ( v219 );
          v32 = (hkVector4f *)p;
          v26 = v352;
          v11 = (__m128i)points;
        }
        v249 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v11, 1u), 1u);
        v250 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v218, v249), v365), v249);
        v251 = _mm_cmpltps(v250, v249);
        v11 = (__m128i)_mm_or_ps(
                         _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v11, 0x1Fu), 0x1Fu), v250), v251),
                         _mm_andnot_ps(v251, (__m128)v11));
      }
      if ( *(float *)v11.m128i_i32 == 0.0 )
      {
        if ( v32 == array )
          v26 = 0;
        v352 = v26;
        v252 = (48 * v355 + 127) & 0xFFFFFF80;
        v253 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v254 = (v252 + 15) & 0xFFFFFFF0;
        if ( v252 > v253->m_slabSize || (char *)v32 + v254 != v253->m_cur || v253->m_firstNonLifoEnd == v32 )
          hkLifoAllocator::slowBlockFree(v253, v32, v254);
        else
          v253->m_cur = v32;
        v352 = 0;
        if ( v353 >= 0 )
        {
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            array,
            48 * (v353 & 0x3FFFFFFF));
          v11.m128i_i32[0] = 0;
          goto LABEL_238;
        }
        goto LABEL_141;
      }
      if ( v32 == array )
        v26 = 0;
      v352 = v26;
      v255 = (48 * v355 + 127) & 0xFFFFFF80;
      v256 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v257 = (v255 + 15) & 0xFFFFFFF0;
      if ( v255 > v256->m_slabSize || (char *)v32 + v257 != v256->m_cur || v256->m_firstNonLifoEnd == v32 )
        hkLifoAllocator::slowBlockFree(v256, v32, v257);
      else
        v256->m_cur = v32;
      v352 = 0;
      if ( v353 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          48 * (v353 & 0x3FFFFFFF));
      v12 = v359;
      v9 = v360;
      v10 = v361;
    }
  }
  if ( *(float *)v11.m128i_i32 < 0.0 )
  {
    for ( j = 0;
          j < hkgpConvexHull::getNumPlanes(v5);
          v11 = (__m128i)_mm_max_ps(_mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v262, v262, 177), v262), v12), (__m128)v11) )
    {
      v259 = hkgpConvexHull::getPlane(v5, j++);
      v260 = _mm_mul_ps(v259->m_quad, v9);
      v261 = _mm_shuffle_ps(v260, _mm_unpackhi_ps(v260, v259->m_quad), 196);
      v262 = _mm_add_ps(_mm_shuffle_ps(v261, v261, 78), v261);
    }
    if ( *(float *)v11.m128i_i32 >= 0.0 )
    {
LABEL_141:
      v11.m128i_i32[0] = 0;
      goto LABEL_238;
    }
  }
  v263 = hkgpConvexHull::getNumPlanes(v5);
  array = 0i64;
  v352 = 0;
  v264 = v263;
  v353 = 2147483648;
  v355 = v263;
  if ( v263 )
  {
    v265 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v266 = v265;
    v267 = (hkVector4f *)v265->m_cur;
    v268 = (16 * v264 + 127) & 0xFFFFFF80;
    v269 = (char *)v267 + v268;
    if ( v268 > v266->m_slabSize || v269 > v266->m_end )
      v267 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v266, v268);
    else
      v266->m_cur = v269;
  }
  else
  {
    v267 = 0i64;
  }
  array = v267;
  v353 = v264 | 0x80000000;
  v270 = 0;
  p = v267;
  v271 = hkgpConvexHull::getNumPlanes(v5);
  if ( v271 <= 0 )
  {
    v278 = v352;
  }
  else
  {
    do
    {
      v272 = hkgpConvexHull::getPlane(v5, v270);
      v273 = v352;
      v274 = _mm_mul_ps(v272->m_quad, v9);
      v275 = _mm_shuffle_ps(v274, _mm_unpackhi_ps(v274, v272->m_quad), 196);
      v276 = _mm_add_ps(_mm_shuffle_ps(v275, v275, 78), v275);
      v277 = _mm_shuffle_ps(
               v272->m_quad,
               _mm_unpackhi_ps(
                 v272->m_quad,
                 _mm_sub_ps(
                   _mm_shuffle_ps(v272->m_quad, v272->m_quad, 255),
                   _mm_max_ps((__m128)v11, _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v276, v276, 177), v276), v10)))),
               196);
      if ( v352 == (v353 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
        v273 = v352;
      }
      ++v270;
      array[v273] = (hkVector4f)v277;
      v278 = v352++ + 1;
    }
    while ( v270 < v271 );
  }
  if ( hkgpConvexHull::getDimensions(v5) == 2 )
  {
    v279 = hkgpConvexHull::getConfiguration(v5);
    v280 = hkgpConvexHull::getProjectionPlane(v5);
    hkgpConvexHull::buildFromPlanes(v5, array, v278, v280, v279);
  }
  else
  {
    v281 = hkgpConvexHull::getConfiguration(v5);
    hkgpConvexHull::buildFromPlanes(v5, array, v278, v281);
  }
  v282 = v352;
  v283 = (char *)p;
  if ( p == array )
    v282 = 0;
  v352 = v282;
  v284 = (16 * v355 + 127) & 0xFFFFFF80;
  v285 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v286 = (v284 + 15) & 0xFFFFFFF0;
  if ( v284 > v285->m_slabSize || &v283[v286] != v285->m_cur || v285->m_firstNonLifoEnd == v283 )
    hkLifoAllocator::slowBlockFree(v285, v283, v286);
  else
    v285->m_cur = v283;
  v287 = v353;
  v352 = 0;
  if ( v353 >= 0 )
  {
    v288 = (float *)array;
LABEL_191:
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v288,
      16 * v287);
  }
LABEL_192:
  v311 = 0;
  v312 = 0;
  if ( *(float *)v11.m128i_i32 < 0.0 )
    v312 = 1;
  if ( v312 )
  {
    points.m_vertices = 0i64;
    points.m_numVertices = 0;
    points.m_striding = 2147483648;
    hkgpConvexHull::fetchPositions(v5, INTERNAL_VERTICES, (hkArray<hkVector4f,hkContainerHeapAllocator> *)&points);
    v313 = 0;
    if ( points.m_numVertices > 0 )
    {
      v314 = (__m128 *)points.m_vertices;
      while ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(*v314, aabbOut.m_max.m_quad), _mm_cmpleps(aabbOut.m_min.m_quad, *v314))) & 7) == 7 )
      {
        ++v313;
        ++v314;
        if ( v313 >= points.m_numVertices )
          goto LABEL_201;
      }
      v311 = 1;
      v349.m_vertices = positions.m_data->m_quad.m128_f32;
      v349.m_striding = 16;
      v349.m_numVertices = positions.m_size;
      v315 = hkgpConvexHull::getConfiguration(v5);
      hkgpConvexHull::build(v5, &v349, v315);
    }
LABEL_201:
    if ( !hkgpConvexHull::getNumVertices(v5) )
    {
      hkErrStream::hkErrStream(&v358, &buf, 512);
      hkOstream::operator<<(
        (hkOstream *)&v358.vfptr,
        "The resulting convex hull after shrinking has zero vertices! Reverting to the unshrunk hull.");
      hkError::messageWarning(-1413808364, &buf, "GeometryProcessing\\ConvexHull\\hkgpConvexHull.cpp", 860);
      hkOstream::~hkOstream((hkOstream *)&v358.vfptr);
      v349.m_vertices = positions.m_data->m_quad.m128_f32;
      v349.m_striding = 16;
      v349.m_numVertices = positions.m_size;
      v316 = hkgpConvexHull::getConfiguration(v5);
      hkgpConvexHull::build(v5, &v349, v316);
    }
    points.m_numVertices = 0;
    if ( points.m_striding >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        (void *)points.m_vertices,
        16 * points.m_striding);
    if ( !v311 )
    {
      if ( v312 )
      {
        v317 = hkgpConvexHull::getNumVertices(v5);
        if ( v317 > positions.m_size )
        {
          points.m_vertices = 0i64;
          points.m_numVertices = 0;
          points.m_striding = 2147483648;
          hkgpConvexHull::fetchPositions(v5, INTERNAL_VERTICES, (hkArray<hkVector4f,hkContainerHeapAllocator> *)&points);
          v318 = positions.m_size;
          v319 = 0;
          v320 = 2147483648;
          v321 = 0i64;
          v349.m_vertices = 0i64;
          v349.m_numVertices = 0;
          v322 = 0;
          v349.m_striding = 2147483648;
          if ( positions.m_size > 0 )
          {
            v323 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
            v324 = points.m_numVertices;
            v325 = 0i64;
            do
            {
              v326 = (__m128)xmmword_141A712A0;
              v327 = v323;
              v328 = 0i64;
              retaddr = -1;
              if ( v324 > 0 )
              {
                v329 = (unsigned int)v324;
                v330 = points.m_vertices;
                do
                {
                  v330 += 4;
                  v331 = _mm_sub_ps(positions.m_data[v325].m_quad, *(__m128 *)((char *)v330 - 16));
                  v332 = _mm_mul_ps(v331, v331);
                  v333 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v332, v332, 85), _mm_shuffle_ps(v332, v332, 0)),
                           _mm_shuffle_ps(v332, v332, 170));
                  v334 = (__m128i)_mm_cmpltps(v333, v326);
                  v326 = _mm_or_ps(_mm_and_ps((__m128)v334, v333), _mm_andnot_ps((__m128)v334, v326));
                  v327 = _mm_or_si128(_mm_andnot_si128(v334, v327), _mm_and_si128(v328, v334));
                  v328 = _mm_add_epi32((__m128i)xmmword_141A72090, v328);
                  --v329;
                }
                while ( v329 );
              }
              retaddr = v327.m128i_i32[0];
              v335 = v327.m128i_i32[0];
              v336 = 0;
              v337 = 0i64;
              if ( v319 <= 0 )
                goto LABEL_218;
              while ( LODWORD(v321[v337]) != v327.m128i_i32[0] )
              {
                ++v337;
                ++v336;
                if ( v337 >= v319 )
                  goto LABEL_218;
              }
              if ( v336 == -1 )
              {
LABEL_218:
                if ( v319 == (v320 & 0x3FFFFFFF) )
                {
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v349, 4);
                  v319 = v349.m_numVertices;
                  v321 = v349.m_vertices;
                }
                LODWORD(v321[v319]) = v335;
                v318 = positions.m_size;
                v324 = points.m_numVertices;
                v320 = v349.m_striding;
                v321 = v349.m_vertices;
                v319 = v349.m_numVertices++ + 1;
              }
              ++v322;
              ++v325;
            }
            while ( v322 < v318 );
          }
          v338 = v319;
          v339 = v319;
          if ( v319 )
          {
            retaddr = 16 * v319;
            v340 = ((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, int *, const float *))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
                     &hkContainerTempAllocator::s_alloc,
                     &retaddr,
                     v321);
            v319 = v349.m_numVertices;
            v321 = v349.m_vertices;
            v341 = (float *)v340;
            v338 = retaddr / 16;
          }
          else
          {
            v341 = 0i64;
          }
          v342 = 2147483648;
          v343 = 0;
          if ( v338 )
            v342 = v338;
          if ( v319 > 0 )
          {
            v344 = 0i64;
            v345 = v341;
            while ( 1 )
            {
              ++v343;
              v346 = 2i64 * SLODWORD(v321[v344]);
              ++v344;
              v345 += 4;
              *((_OWORD *)v345 - 1) = *(_OWORD *)&points.m_vertices[2 * v346];
              if ( v343 >= v349.m_numVertices )
                break;
              v321 = v349.m_vertices;
            }
          }
          v357.m_vertices = v341;
          v357.m_numVertices = v339;
          v357.m_striding = 16;
          v347 = hkgpConvexHull::getConfiguration(v5);
          hkgpConvexHull::build(v5, &v357, v347);
          if ( v342 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              v341,
              16 * v342);
          v349.m_numVertices = 0;
          if ( v349.m_striding >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              (void *)v349.m_vertices,
              4 * v349.m_striding);
          v349.m_vertices = 0i64;
          v349.m_striding = 2147483648;
          points.m_numVertices = 0;
          if ( points.m_striding >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              (void *)points.m_vertices,
              16 * points.m_striding);
        }
      }
    }
  }
  hkgpConvexHull::buildMassProperties(v5, (hkResult *)&retaddr);
  hkgpConvexHull::buildIndices(v5, 0.99998999, 0);
LABEL_238:
  positions.m_size = 0;
  if ( positions.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      positions.m_data,
      16 * positions.m_capacityAndFlags);
  return *(float *)v11.m128i_i32;
}reak;
              v321 = v349.m_vertices;
            }
          }
          v357.m_vertices = v341;
          v357.m_numVertices = v339;
          v357.m_striding = 16;
          v347 = hkgpConvexHull::getConfiguration(v5);
          hkgpConvexHull::build(v5, &v357, v347);
          if ( v342 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              v341,
              16 * v342);
          v349.m_numVertices = 0;
          if ( v349.m_striding >= 0 )
            hkContainerTempAllocator::s_alloc.v

// File Line: 935
// RVA: 0xCAC8B0
void __fastcall hkgpConvexHull::buildIndices(hkgpConvexHull *this, float minCosAngle, hkBool forceRebuild)
{
  if ( forceRebuild.m_bool )
    this->m_data->m_hasIndexing = 0;
  this->m_data->m_config.m_minCosAngle = minCosAngle;
  hkgpConvexHullImpl::buildIndices<hkgpConvexHullImpl::PositionAsTransform>(this->m_data);
}

// File Line: 942
// RVA: 0xCAC8F0
hkBool *__fastcall hkgpConvexHull::hasIndices(hkgpConvexHull *this, hkBool *result)
{
  hkBool *v2; // rax

  v2 = result;
  result->m_bool = this->m_data->m_hasIndexing;
  return v2;
}

// File Line: 947
// RVA: 0xCAC910
hkResult *__fastcall hkgpConvexHull::buildMassProperties(hkgpConvexHull *this, hkResult *result)
{
  hkResult *v2; // rbx

  v2 = result;
  hkgpConvexHullImpl::buildMassProperties<hkgpConvexHullImpl::PositionAsTransform>(this->m_data, result);
  return v2;
}

// File Line: 952
// RVA: 0xCAC940
hkBool *__fastcall hkgpConvexHull::hasMassProperties(hkgpConvexHull *this, hkBool *result)
{
  hkBool *v2; // rax

  v2 = result;
  result->m_bool = this->m_data->m_hasMassProperties;
  return v2;
}

// File Line: 957
// RVA: 0xCAC960
hkBool *__fastcall hkgpConvexHull::hasValidMassProperties(hkgpConvexHull *this, hkBool *result)
{
  hkgpConvexHullImpl *v2; // rax
  hkBool *v3; // rax

  v2 = this->m_data;
  if ( !v2->m_hasMassProperties || v2->m_degeneratedMassProperties )
  {
    result->m_bool = 0;
    v3 = result;
  }
  else
  {
    result->m_bool = 1;
    v3 = result;
  }
  return v3;
}

// File Line: 962
// RVA: 0xCAC990
hkBool *__fastcall hkgpConvexHull::isVertexUsed(hkgpConvexHull *this, hkBool *result, hkVector4f *point)
{
  hkgpConvexHullImpl *v3; // rax
  hkgpConvexHullImpl::Vertex *v4; // rcx
  __m128 v5; // xmm3
  __m128 v6; // xmm1
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  hkBool *v10; // rax
  __int64 v11; // [rsp+20h] [rbp-28h]

  v3 = this->m_data;
  v4 = v3->m_mesh.m_vertices.m_used;
  v5 = _mm_mul_ps(_mm_sub_ps(point->m_quad, v3->m_origin.m_quad), v3->m_scale.m_quad);
  v6 = _mm_cmpltps(v5, (__m128)_xmm);
  v7 = _mm_max_ps(
         (__m128)_xmm_c6000000c6000000c6000000c6000000,
         _mm_or_ps(_mm_andnot_ps(v6, (__m128)_xmm), _mm_and_ps(v6, v5)));
  v8 = _mm_cmpltps(v7, (__m128)0i64);
  v9 = _mm_or_ps(
         _mm_andnot_ps(v8, _mm_add_ps(v7, (__m128)xmmword_141A711B0)),
         _mm_and_ps(_mm_sub_ps(v7, (__m128)xmmword_141A711B0), v8));
  v11 = (unsigned __int128)_mm_xor_si128(
                             (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v9),
                             _mm_cvttps_epi32(v9));
  if ( v4 )
  {
    while ( v11 != *(_QWORD *)v4->m_x )
    {
      v4 = v4->m_next;
      if ( !v4 )
        goto LABEL_4;
    }
    result->m_bool = 1;
    v10 = result;
  }
  else
  {
LABEL_4:
    result->m_bool = 0;
    v10 = result;
  }
  return v10;
}

// File Line: 972
// RVA: 0xCACA60
hkBool *__fastcall hkgpConvexHull::isPointInside(hkgpConvexHull *this, hkBool *result, hkVector4f *point, hkBool usePlanes, float epsilon)
{
  hkBool *v5; // rbx

  v5 = result;
  result->m_bool = hkgpConvexHullImpl::isPointInside(this->m_data, point, usePlanes.m_bool != 0, epsilon);
  return v5;
}

// File Line: 977
// RVA: 0xCACAA0
hkBool *__fastcall hkgpConvexHull::clipLine(hkgpConvexHull *this, hkBool *result, hkVector4f *a, hkVector4f *b, float *t0, float *t1, float epsilon)
{
  hkBool *v7; // rbx

  v7 = result;
  result->m_bool = hkgpConvexHullImpl::clipLine(this->m_data, a, b, t0, t1, epsilon);
  return v7;
}

// File Line: 982
// RVA: 0xCACAF0
hkSimdFloat32 *__fastcall hkgpConvexHull::maximumDistanceToPlanes(hkgpConvexHull *this, hkSimdFloat32 *result, hkVector4f *point, int *planeIndexOut)
{
  __m128i v4; // xmm6
  int *v5; // rdi
  hkVector4f *v6; // r14
  hkSimdFloat32 *v7; // rbx
  hkgpConvexHull *v8; // rsi
  int v9; // ebp
  __m128i v10; // xmm7
  hkVector4f *v11; // rax
  __m128 v12; // xmm2
  __m128 v13; // xmm2
  __m128 v14; // xmm0
  __m128 v15; // xmm2
  __m128i v16; // xmm3
  __m128 v17; // xmm1
  __m128i v18; // xmm0
  __m128i v19; // xmm3
  hkSimdFloat32 *v20; // rax

  v4 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
  v5 = planeIndexOut;
  v6 = point;
  v7 = result;
  v8 = this;
  v9 = 0;
  v10 = 0i64;
  for ( *result = (hkSimdFloat32)xmmword_141A712F0;
        v9 < hkgpConvexHull::getNumPlanes(v8);
        v4 = _mm_or_si128(_mm_andnot_si128(v18, v4), v19) )
  {
    v11 = hkgpConvexHull::getPlane(v8, v9++);
    v12 = _mm_mul_ps(v6->m_quad, v11->m_quad);
    v13 = _mm_shuffle_ps(v12, _mm_unpackhi_ps(v12, v11->m_quad), 196);
    v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
    v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14);
    v16 = (__m128i)_mm_cmpltps(v7->m_real, v15);
    v17 = _mm_or_ps(_mm_andnot_ps((__m128)v16, v7->m_real), _mm_and_ps((__m128)v16, v15));
    v18 = v16;
    v19 = _mm_and_si128(v16, v10);
    v10 = _mm_add_epi32(v10, (__m128i)xmmword_141A72090);
    *v7 = (hkSimdFloat32)v17;
  }
  v20 = v7;
  if ( v5 )
    *v5 = v4.m128i_i32[0];
  return v20;
}

// File Line: 1020
// RVA: 0xCACC00
hkgpConvexHullImpl *__fastcall hkgpConvexHull::getConfiguration(hkgpConvexHull *this)
{
  return this->m_data;
}

// File Line: 1025
// RVA: 0xCACC10
hkgpConvexHullImpl *__fastcall hkgpConvexHull::getConfiguration(hkgpConvexHull *this)
{
  return this->m_data;
}

// File Line: 1030
// RVA: 0xCACC20
__int64 __fastcall hkgpConvexHull::getDimensions(hkgpConvexHull *this)
{
  return (unsigned int)this->m_data->m_dimensions;
}

// File Line: 1035
// RVA: 0xCACC40
hkAabb *__fastcall hkgpConvexHull::getBoundingBox(hkgpConvexHull *this, hkAabb *result, hkgpConvexHull::Inputs inputs, float scale, float radialScale)
{
  hkgpConvexHullImpl *v5; // rsi
  hkgpConvexHull::Inputs v6; // ebx
  hkAabb *v7; // r14
  hkgpConvexHull *v8; // rbp
  signed __int64 v9; // rdi
  hkgpConvexHull::Vertex *v10; // rax
  bool v11; // zf
  hkgpConvexHull::Vertex *v12; // rbx
  hkVector4f *v13; // rax
  hkgpConvexHull::Vertex *v14; // rbx
  __m128 v15; // xmm6
  hkVector4f *v16; // rax
  hkgpConvexHull::Vertex *i; // rbx
  hkVector4f *v18; // rax
  __m128 v19; // xmm1
  hkVector4f v20; // xmm1
  __m128 v21; // xmm6
  __m128 v22; // xmm5
  __m128 v23; // xmm1
  __m128 v24; // xmm1
  __m128 v25; // xmm4
  __m128 v26; // xmm1
  __m128 v27; // xmm0
  __m128 v28; // xmm0
  __m128 v29; // xmm5
  __m128 v30; // xmm1
  hkVector4f resulta; // [rsp+20h] [rbp-48h]

  v5 = this->m_data;
  v6 = inputs;
  v7 = result;
  v8 = this;
  v9 = inputs;
  if ( _mm_movemask_ps(_mm_cmpleps(v5->m_boundingBoxes[v9].m_max.m_quad, v5->m_boundingBoxes[v9].m_min.m_quad)) & 7
    && hkgpConvexHull::getNumVertices(this) > 0 )
  {
    v10 = hkgpConvexHull::getFirstVertex(v8);
    v11 = v6 == 0;
    v12 = v10;
    if ( v11 )
    {
      v13 = hkgpConvexHull::getSourcePosition(v8, v10);
      v5->m_boundingBoxes[v9].m_min = (hkVector4f)v13->m_quad;
      v5->m_boundingBoxes[v9].m_max = (hkVector4f)v13->m_quad;
      v14 = hkgpConvexHull::getNext(v8, v12);
      if ( v14 )
      {
        v15 = v5->m_boundingBoxes[v9].m_max.m_quad;
        do
        {
          v16 = hkgpConvexHull::getSourcePosition(v8, v14);
          v5->m_boundingBoxes[v9].m_min.m_quad = _mm_min_ps(v5->m_boundingBoxes[v9].m_min.m_quad, v16->m_quad);
          v15 = _mm_max_ps(v15, v16->m_quad);
          v5->m_boundingBoxes[v9].m_max.m_quad = v15;
          v14 = hkgpConvexHull::getNext(v8, v14);
        }
        while ( v14 );
      }
    }
    else
    {
      v5->m_boundingBoxes[v9].m_min = (hkVector4f)hkgpConvexHull::getPosition(v8, &resulta, v10)->m_quad;
      v5->m_boundingBoxes[v9].m_max = (hkVector4f)hkgpConvexHull::getPosition(v8, &resulta, v12)->m_quad;
      for ( i = hkgpConvexHull::getNext(v8, v12); i; i = hkgpConvexHull::getNext(v8, i) )
      {
        v18 = hkgpConvexHull::getPosition(v8, &resulta, i);
        v19 = v5->m_boundingBoxes[v9].m_max.m_quad;
        v5->m_boundingBoxes[v9].m_min.m_quad = _mm_min_ps(v5->m_boundingBoxes[v9].m_min.m_quad, v18->m_quad);
        v5->m_boundingBoxes[v9].m_max.m_quad = _mm_max_ps(v19, v18->m_quad);
      }
    }
  }
  if ( scale != 1.0 || radialScale > 0.0 )
  {
    v21 = v5->m_boundingBoxes[v9].m_min.m_quad;
    v22 = v5->m_boundingBoxes[v9].m_max.m_quad;
    if ( radialScale > 0.0 )
    {
      v23 = _mm_sub_ps(v22, v21);
      v24 = _mm_mul_ps(v23, v23);
      v25 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
              _mm_shuffle_ps(v24, v24, 170));
      v26 = _mm_rsqrt_ps(v25);
      v27 = _mm_mul_ps(
              _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(radialScale), (__m128)LODWORD(radialScale), 0),
                (__m128)xmmword_141A711B0),
              _mm_andnot_ps(
                _mm_cmpleps(v25, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                    _mm_mul_ps(*(__m128 *)_xmm, v26)),
                  v25)));
      v21 = _mm_sub_ps(v21, v27);
      v22 = _mm_add_ps(v22, v27);
    }
    if ( scale != 1.0 )
    {
      v28 = v22;
      v29 = _mm_mul_ps(_mm_add_ps(v22, v21), (__m128)xmmword_141A711B0);
      v30 = _mm_mul_ps(
              _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(scale), (__m128)LODWORD(scale), 0), (__m128)xmmword_141A711B0),
              _mm_sub_ps(v28, v21));
      v21 = _mm_sub_ps(v29, v30);
      v22 = _mm_add_ps(v29, v30);
    }
    v7->m_min.m_quad = v21;
    v7->m_max.m_quad = v22;
  }
  else
  {
    v20.m_quad = (__m128)v5->m_boundingBoxes[v9].m_max;
    v7->m_min = v5->m_boundingBoxes[v9].m_min;
    v7->m_max = (hkVector4f)v20.m_quad;
  }
  return v7;
}

// File Line: 1095
// RVA: 0xCACEF0
void __fastcall hkgpConvexHull::getOrientedBoundingBox(hkgpConvexHull *this, hkVector4f *halfExtents, hkTransformf *worldTransform)
{
  hkgpConvexHullImpl::getOrientedBoundingBox(this->m_data, halfExtents, worldTransform);
}

// File Line: 1100
// RVA: 0xCACF00
void __fastcall hkgpConvexHull::getOrientedRectangle(hkgpConvexHull *this, hkVector4f *projectionPlane, hkVector4f *halfExtents, hkTransformf *worldTransform)
{
  hkSimdFloat32 result; // [rsp+30h] [rbp-18h]

  hkgpConvexHullImpl::getOrientedRectangle(this->m_data, &result, projectionPlane, halfExtents, worldTransform);
}

// File Line: 1105
// RVA: 0xCACF30
hkVector4f *__fastcall hkgpConvexHull::getProjectionAxis(hkgpConvexHull *this, hkVector4f *result)
{
  hkVector4f *v2; // rax

  v2 = result;
  _mm_store_si128((__m128i *)result, (__m128i)this->m_data->m_projectionAxis.m_quad);
  return v2;
}

// File Line: 1110
// RVA: 0xCACF50
hkVector4f *__fastcall hkgpConvexHull::getProjectionPlane(hkgpConvexHull *this)
{
  return &this->m_data->m_projectionPlane;
}

// File Line: 1115
// RVA: 0xCACF70
__int64 __fastcall hkgpConvexHull::getNumPlanes(hkgpConvexHull *this)
{
  hkgpConvexHullImpl *v1; // rdi
  hkgpConvexHull *v2; // rbx
  hkOstream *v3; // rax
  hkOstream *v4; // rax
  hkErrStream v6; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v1 = this->m_data;
  v2 = this;
  if ( v1->m_hasIndexing )
    return (unsigned int)v1->m_planes.m_size;
  hkErrStream::hkErrStream(&v6, &buf, 512);
  v3 = hkOstream::operator<<((hkOstream *)&v6.vfptr, "No index available (");
  v4 = hkOstream::operator<<(v3, v1->m_uid, (int)v3);
  hkOstream::operator<<(v4, ") hkgpConvexHull::buildIndices need to be called before this operation.");
  if ( (unsigned int)hkError::messageError(
                       2046417030,
                       &buf,
                       "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                       358) )
    __debugbreak();
  hkOstream::~hkOstream((hkOstream *)&v6.vfptr);
  return (unsigned int)v2->m_data->m_planes.m_size;
}

// File Line: 1121
// RVA: 0xCAD040
hkVector4f *__fastcall hkgpConvexHull::getPlane(hkgpConvexHull *this, int index)
{
  hkgpConvexHullImpl *v2; // rdi
  __int64 v3; // rsi
  hkgpConvexHull *v4; // rbx
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  hkErrStream v8; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v2 = this->m_data;
  v3 = index;
  v4 = this;
  if ( !v2->m_hasIndexing )
  {
    hkErrStream::hkErrStream(&v8, &buf, 512);
    v5 = hkOstream::operator<<((hkOstream *)&v8.vfptr, "No index available (");
    v6 = hkOstream::operator<<(v5, v2->m_uid, (int)v5);
    hkOstream::operator<<(v6, ") hkgpConvexHull::buildIndices need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         2046417030,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         358) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v8.vfptr);
  }
  return &v4->m_data->m_planes.m_data[v3];
}

// File Line: 1127
// RVA: 0xCAD100
__int64 __fastcall hkgpConvexHull::getNumVertices(hkgpConvexHull *this)
{
  return (unsigned int)this->m_data->m_mesh.m_vertices.m_numUsed;
}

// File Line: 1132
// RVA: 0xCAD110
hkgpConvexHullImpl::Vertex *__fastcall hkgpConvexHull::getFirstVertex(hkgpConvexHull *this)
{
  return this->m_data->m_mesh.m_vertices.m_used;
}

// File Line: 1137
// RVA: 0xCAD120
__int64 __fastcall hkgpConvexHull::getIndex(hkgpConvexHull *this, hkgpConvexHull::Vertex *vertex)
{
  hkgpConvexHullImpl *v2; // rdi
  hkgpConvexHull::Vertex *v3; // rbx
  hkOstream *v4; // rax
  hkOstream *v5; // rax
  hkErrStream v7; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v2 = this->m_data;
  v3 = vertex;
  if ( v2->m_hasIndexing )
    return *(unsigned int *)&vertex[52];
  hkErrStream::hkErrStream(&v7, &buf, 512);
  v4 = hkOstream::operator<<((hkOstream *)&v7.vfptr, "No index available (");
  v5 = hkOstream::operator<<(v4, v2->m_uid, (int)v4);
  hkOstream::operator<<(v5, ") hkgpConvexHull::buildIndices need to be called before this operation.");
  if ( (unsigned int)hkError::messageError(
                       2046417030,
                       &buf,
                       "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                       358) )
    __debugbreak();
  hkOstream::~hkOstream((hkOstream *)&v7.vfptr);
  return *(unsigned int *)&v3[52];
}

// File Line: 1143
// RVA: 0xCAD1E0
hkgpConvexHull::Vertex *__fastcall hkgpConvexHull::getNext(hkgpConvexHull *this, hkgpConvexHull::Vertex *vertex)
{
  return *(hkgpConvexHull::Vertex **)vertex;
}

// File Line: 1148
// RVA: 0xCAD1F0
hkVector4f *__fastcall hkgpConvexHull::getPosition(hkgpConvexHull *this, hkVector4f *result, hkgpConvexHull::Vertex *vertex)
{
  hkgpConvexHullImpl *v3; // rax
  hkVector4f v4; // xmm0
  hkVector4f v5; // xmm1
  hkVector4f *v6; // rax

  v3 = this->m_data;
  v4.m_quad = _mm_cvtepi32_ps(
                _mm_unpacklo_epi32(
                  _mm_unpacklo_epi32(
                    _mm_cvtsi32_si128(*(_DWORD *)&vertex[32]),
                    _mm_cvtsi32_si128(*(_DWORD *)&vertex[40])),
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(_DWORD *)&vertex[36]), _mm_cvtsi32_si128(0))));
  *result = (hkVector4f)v4.m_quad;
  v5.m_quad = _mm_add_ps(
                _mm_mul_ps((__m128)_mm_srli_si128(_mm_slli_si128((__m128i)v4.m_quad, 4), 4), v3->m_scaleInv.m_quad),
                v3->m_origin.m_quad);
  v6 = result;
  *result = (hkVector4f)v5.m_quad;
  return v6;
}

// File Line: 1153
// RVA: 0xCAD250
hkgpConvexHull::Vertex *__fastcall hkgpConvexHull::getSourcePosition(hkgpConvexHull *this, hkgpConvexHull::Vertex *vertex)
{
  return vertex + 16;
}

// File Line: 1158
// RVA: 0xCAD260
__int64 __fastcall hkgpConvexHull::getNumTriangles(hkgpConvexHull *this)
{
  return (unsigned int)this->m_data->m_mesh.m_triangles.m_numUsed;
}

// File Line: 1163
// RVA: 0xCAD270
hkgpConvexHullImpl::Triangle *__fastcall hkgpConvexHull::getFirstTriangle(hkgpConvexHull *this)
{
  return this->m_data->m_mesh.m_triangles.m_used;
}

// File Line: 1168
// RVA: 0xCAD280
__int64 __fastcall hkgpConvexHull::getIndex(hkgpConvexHull *this, hkgpConvexHull::Triangle *triangle)
{
  hkgpConvexHullImpl *v2; // rdi
  hkgpConvexHull::Triangle *v3; // rbx
  hkOstream *v4; // rax
  hkOstream *v5; // rax
  hkErrStream v7; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v2 = this->m_data;
  v3 = triangle;
  if ( v2->m_hasIndexing )
    return *(unsigned int *)&triangle[100];
  hkErrStream::hkErrStream(&v7, &buf, 512);
  v4 = hkOstream::operator<<((hkOstream *)&v7.vfptr, "No index available (");
  v5 = hkOstream::operator<<(v4, v2->m_uid, (int)v4);
  hkOstream::operator<<(v5, ") hkgpConvexHull::buildIndices need to be called before this operation.");
  if ( (unsigned int)hkError::messageError(
                       2046417030,
                       &buf,
                       "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                       358) )
    __debugbreak();
  hkOstream::~hkOstream((hkOstream *)&v7.vfptr);
  return *(unsigned int *)&v3[100];
}

// File Line: 1174
// RVA: 0xCAD340
hkgpConvexHull::Triangle *__fastcall hkgpConvexHull::getNext(hkgpConvexHull *this, hkgpConvexHull::Triangle *triangle)
{
  return *(hkgpConvexHull::Triangle **)triangle;
}

// File Line: 1179
// RVA: 0xCAD350
__int64 __fastcall hkgpConvexHull::getPlaneIndex(hkgpConvexHull *this, hkgpConvexHull::Triangle *triangle)
{
  hkgpConvexHullImpl *v2; // rdi
  hkgpConvexHull::Triangle *v3; // rbx
  hkOstream *v4; // rax
  hkOstream *v5; // rax
  hkErrStream v7; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v2 = this->m_data;
  v3 = triangle;
  if ( v2->m_hasIndexing )
    return *(unsigned int *)&triangle[88];
  hkErrStream::hkErrStream(&v7, &buf, 512);
  v4 = hkOstream::operator<<((hkOstream *)&v7.vfptr, "No index available (");
  v5 = hkOstream::operator<<(v4, v2->m_uid, (int)v4);
  hkOstream::operator<<(v5, ") hkgpConvexHull::buildIndices need to be called before this operation.");
  if ( (unsigned int)hkError::messageError(
                       2046417030,
                       &buf,
                       "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                       358) )
    __debugbreak();
  hkOstream::~hkOstream((hkOstream *)&v7.vfptr);
  return *(unsigned int *)&v3[88];
}

// File Line: 1185
// RVA: 0xCAD410
hkVector4f *__fastcall hkgpConvexHull::getPlaneEquation(hkgpConvexHull *this, hkVector4f *result, hkgpConvexHull::Triangle *triangle)
{
  hkgpConvexHull::Triangle *v3; // rbx
  hkVector4f *v4; // rsi
  hkgpConvexHull *v5; // rdi
  hkgpConvexHull::Vertex *v6; // rax
  __m128 v7; // xmm8
  hkgpConvexHull::Vertex *v8; // rax
  __m128 v9; // xmm6
  hkgpConvexHull::Vertex *v10; // rax
  __m128 v11; // xmm0
  hkVector4f *v12; // rax
  __m128 v13; // xmm0
  __m128 v14; // xmm7
  __m128 v15; // xmm7
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm5
  __m128 v20; // xmm8

  v3 = triangle;
  v4 = result;
  v5 = this;
  v6 = hkgpConvexHull::getVertex(this, triangle, 0);
  v7 = *(__m128 *)hkgpConvexHull::getSourcePosition(v5, v6);
  v8 = hkgpConvexHull::getVertex(v5, v3, 1);
  v9 = _mm_sub_ps(*(__m128 *)hkgpConvexHull::getSourcePosition(v5, v8), v7);
  v10 = hkgpConvexHull::getVertex(v5, v3, 2);
  v11 = *(__m128 *)hkgpConvexHull::getSourcePosition(v5, v10);
  v12 = v4;
  v13 = _mm_sub_ps(v11, v7);
  v14 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v9), _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v13));
  v15 = _mm_shuffle_ps(v14, v14, 201);
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_rsqrt_ps(v17);
  v19 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v17, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
              _mm_mul_ps(*(__m128 *)_xmm, v18))),
          v15);
  v20 = _mm_mul_ps(v7, v19);
  v4->m_quad = _mm_shuffle_ps(
                 v19,
                 _mm_unpackhi_ps(
                   v19,
                   _mm_sub_ps(
                     (__m128)0i64,
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                       _mm_shuffle_ps(v20, v20, 170)))),
                 196);
  return v12;
}

// File Line: 1196
// RVA: 0xCAD560
hkgpConvexHull::Vertex *__fastcall hkgpConvexHull::getVertex(hkgpConvexHull *this, hkgpConvexHull::Triangle *triangle, int index)
{
  return *(hkgpConvexHull::Vertex **)&triangle[8 * index + 16];
}

// File Line: 1202
// RVA: 0xCAD570
hkgpConvexHull::Triangle *__fastcall hkgpConvexHull::getNeighbour(hkgpConvexHull *this, hkgpConvexHull::Triangle *triangle, int index)
{
  return (hkgpConvexHull::Triangle *)(*(_QWORD *)&triangle[8 * index + 40] & 0xFFFFFFFFFFFFFFFCui64);
}

// File Line: 1209
// RVA: 0xCAD590
hkSimdFloat32 *__fastcall hkgpConvexHull::getWidth(hkgpConvexHull *this, hkSimdFloat32 *result, hkVector4f *direction)
{
  hkSimdFloat32 *v3; // rsi
  hkgpConvexHull *v4; // rdi
  hkSimdFloat32 *v5; // rbx
  __m128 v6; // xmm0
  hkSimdFloat32 *v7; // rax
  hkVector4f plane; // [rsp+20h] [rbp-38h]
  hkSimdFloat32 resulta; // [rsp+30h] [rbp-28h]
  hkSimdFloat32 v10; // [rsp+40h] [rbp-18h]

  v3 = result;
  v4 = this;
  plane.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)direction->m_quad, 4), 4);
  v5 = hkgpConvexHull::getMinimumDistanceFromPlane(this, &resulta, &plane);
  v6 = hkgpConvexHull::getMaximumDistanceFromPlane(v4, &v10, &plane)->m_real;
  v7 = v3;
  v3->m_real = _mm_sub_ps(v6, v5->m_real);
  return v7;
}

// File Line: 1215
// RVA: 0xCAD600
hkSimdFloat32 *__fastcall hkgpConvexHull::getMinWidth(hkgpConvexHull *this, hkSimdFloat32 *result)
{
  hkSimdFloat32 *v2; // rbx
  hkSimdFloat32 *v3; // rax
  hkSimdFloat32 minWidth; // [rsp+20h] [rbp-28h]
  hkSimdFloat32 maxWidth; // [rsp+30h] [rbp-18h]

  v2 = result;
  hkgpConvexHull::getWidthBounds(this, &minWidth, &maxWidth);
  v3 = v2;
  _mm_store_si128((__m128i *)v2, (__m128i)minWidth.m_real);
  return v3;
}

// File Line: 1221
// RVA: 0xCAD630
hkSimdFloat32 *__fastcall hkgpConvexHull::getMaxWidth(hkgpConvexHull *this, hkSimdFloat32 *result)
{
  hkSimdFloat32 *v2; // rbx
  hkSimdFloat32 *v3; // rax
  hkSimdFloat32 minWidth; // [rsp+20h] [rbp-28h]
  hkSimdFloat32 maxWidth; // [rsp+30h] [rbp-18h]

  v2 = result;
  hkgpConvexHull::getWidthBounds(this, &minWidth, &maxWidth);
  v3 = v2;
  _mm_store_si128((__m128i *)v2, (__m128i)maxWidth.m_real);
  return v3;
}

// File Line: 1227
// RVA: 0xCAD660
void __fastcall hkgpConvexHull::getWidthBounds(hkgpConvexHull *this, hkSimdFloat32 *minWidth, hkSimdFloat32 *maxWidth)
{
  hkSimdFloat32 *v3; // rsi
  hkSimdFloat32 *v4; // rbp
  hkgpConvexHull *v5; // rdi
  __m128 v6; // xmm6
  signed int v7; // er14
  __m128 v8; // xmm0
  __int128 *v9; // rbx
  __m128 v10; // xmm0
  __m128 v11; // xmm0
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  __m128 v15; // [rsp+20h] [rbp-68h]
  __int64 v16; // [rsp+30h] [rbp-58h]

  v3 = maxWidth;
  v4 = minWidth;
  v15 = 0i64;
  v5 = this;
  hkgpConvexHull::getOrientedBoundingBox(this, (hkVector4f *)&v15, (hkTransformf *)&v16);
  v6 = v15;
  v7 = 1;
  v8 = _mm_shuffle_ps(v15, v15, 0);
  *v4 = (hkSimdFloat32)v8;
  *v3 = (hkSimdFloat32)v8;
  if ( (signed int)hkgpConvexHull::getDimensions(v5) > 1 )
  {
    v9 = &xmmword_141687F10;
    do
    {
      v10 = (__m128)*v9;
      ++v7;
      ++v9;
      v11 = _mm_and_ps(v10, v6);
      v12 = _mm_or_ps(_mm_shuffle_ps(v11, v11, 78), v11);
      v4->m_real = _mm_min_ps(v4->m_real, _mm_or_ps(_mm_shuffle_ps(v12, v12, 177), v12));
      v13 = _mm_and_ps((__m128)*(v9 - 1), v6);
      v14 = _mm_or_ps(_mm_shuffle_ps(v13, v13, 78), v13);
      v3->m_real = _mm_max_ps(v3->m_real, _mm_or_ps(_mm_shuffle_ps(v14, v14, 177), v14));
    }
    while ( v7 < (signed int)hkgpConvexHull::getDimensions(v5) );
  }
}

// File Line: 1241
// RVA: 0xCAD760
hkSimdFloat32 *__fastcall hkgpConvexHull::getMinimumDistanceFromPlane(hkgpConvexHull *this, hkSimdFloat32 *result, hkVector4f *plane)
{
  hkVector4f *v3; // rbx
  hkSimdFloat32 *v4; // rdi
  hkSimdFloat32 *v5; // rax
  __m128 v6; // xmm1
  hkVector4f vertexOut; // [rsp+20h] [rbp-28h]
  hkVector4f direction; // [rsp+30h] [rbp-18h]

  v3 = plane;
  v4 = result;
  vertexOut.m_quad = 0i64;
  direction.m_quad = _mm_xor_ps(
                       (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                       plane->m_quad);
  hkgpConvexHull::getSupportingVertex(this, &direction, &vertexOut);
  v5 = v4;
  v6 = _mm_mul_ps(v3->m_quad, vertexOut.m_quad);
  v4->m_real = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)),
                   _mm_shuffle_ps(v6, v6, 170)),
                 _mm_shuffle_ps(v3->m_quad, v3->m_quad, 255));
  return v5;
}

// File Line: 1248
// RVA: 0xCAD7F0
hkSimdFloat32 *__fastcall hkgpConvexHull::getMaximumDistanceFromPlane(hkgpConvexHull *this, hkSimdFloat32 *result, hkVector4f *plane)
{
  hkVector4f *v3; // rbx
  hkSimdFloat32 *v4; // rdi
  hkSimdFloat32 *v5; // rax
  __m128 v6; // xmm1
  hkVector4f vertexOut; // [rsp+20h] [rbp-18h]

  v3 = plane;
  v4 = result;
  vertexOut.m_quad = 0i64;
  hkgpConvexHull::getSupportingVertex(this, plane, &vertexOut);
  v5 = v4;
  v6 = _mm_mul_ps(v3->m_quad, vertexOut.m_quad);
  v4->m_real = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)),
                   _mm_shuffle_ps(v6, v6, 170)),
                 _mm_shuffle_ps(v3->m_quad, v3->m_quad, 255));
  return v5;
}

// File Line: 1255
// RVA: 0xCAD860
void __fastcall hkgpConvexHull::getSupportingVertex(hkgpConvexHull *this, hkVector4f *direction, hkVector4f *vertexOut)
{
  hkgpConvexHullImpl *v3; // rbx
  hkVector4f *v4; // rsi
  hkVector4f *v5; // rbp
  int v6; // edi
  int v7; // eax
  hkVector4f *v8; // r9
  int v9; // er9
  hkgpConvexHullImpl::Vertex *v10; // rcx
  hkVector4f *v11; // rax
  hkVector4f *array; // [rsp+30h] [rbp-28h]
  int i; // [rsp+38h] [rbp-20h]
  int v14; // [rsp+3Ch] [rbp-1Ch]
  hkResult result; // [rsp+60h] [rbp+8h]

  v3 = this->m_data;
  v4 = vertexOut;
  v5 = direction;
  if ( !v3->m_supportCache.m_size )
  {
    v6 = v3->m_mesh.m_vertices.m_numUsed;
    v14 = 2147483648;
    v7 = 0;
    v8 = 0i64;
    array = 0i64;
    i = 0;
    if ( v6 > 0 )
    {
      v9 = v6;
      if ( v6 < 0 )
        v9 = 0;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v9, 16);
      v7 = i;
      v8 = array;
    }
    v10 = v3->m_mesh.m_vertices.m_used;
    for ( i = v6 + v7; v10; v10 = v10->m_next )
    {
      v11 = v8;
      ++v8;
      *v11 = v10->m_source;
    }
    hkGeometryProcessing::buildTransposedArray(
      (hkArray<hkVector4f,hkContainerHeapAllocator> *)&array,
      &v3->m_supportCache);
    i = 0;
    if ( v14 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        16 * v14);
  }
  hkGeometryProcessing::getSupportingVertex((hkArrayBase<hkFourTransposedPointsf> *)&v3->m_supportCache.m_data, v5, v4);
}

// File Line: 1260
// RVA: 0xCAD970
void __fastcall hkgpConvexHull::getNearestVertex(hkgpConvexHull *this, hkgpConvexHull::Inputs inputs, hkVector4f *point, hkVector4f *vertexOut)
{
  float v4; // xmm4_4
  __m128 v5; // xmm0
  hkgpConvexHullImpl *v6; // rax
  hkgpConvexHullImpl::Vertex *j; // rax
  hkVector4f v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm1
  float v11; // xmm2_4
  hkgpConvexHullImpl *v12; // rdx
  hkgpConvexHullImpl::Vertex *i; // rax
  __m128 v14; // xmm5
  __m128 v15; // xmm6
  __m128i v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm1
  float v19; // xmm2_4

  v4 = *(float *)&xmmword_141A712A0;
  v5 = point->m_quad;
  if ( inputs )
  {
    v12 = this->m_data;
    *vertexOut = (hkVector4f)v5;
    for ( i = v12->m_mesh.m_vertices.m_used; i; i = i->m_next )
    {
      v14 = v12->m_scaleInv.m_quad;
      v15 = v12->m_origin.m_quad;
      v16 = _mm_unpacklo_epi32(
              _mm_unpacklo_epi32(_mm_cvtsi32_si128(i->m_x[0]), _mm_cvtsi32_si128(i->m_x[2])),
              _mm_unpacklo_epi32(_mm_cvtsi32_si128(i->m_x[1]), _mm_cvtsi32_si128(0)));
      v17 = _mm_sub_ps(
              point->m_quad,
              _mm_add_ps(
                _mm_mul_ps((__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_cvtepi32_ps(v16), 4), 4), v14),
                v15));
      v18 = _mm_mul_ps(v17, v17);
      v19 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 170));
      if ( v19 < v4 )
      {
        v4 = v19;
        vertexOut->m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_cvtepi32_ps(v16), 4), 4),
                                v14),
                              v15);
      }
    }
  }
  else
  {
    v6 = this->m_data;
    *vertexOut = (hkVector4f)v5;
    for ( j = v6->m_mesh.m_vertices.m_used; j; j = j->m_next )
    {
      v8.m_quad = (__m128)j->m_source;
      v9 = _mm_sub_ps(point->m_quad, v8.m_quad);
      v10 = _mm_mul_ps(v9, v9);
      v11 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 170));
      if ( v11 < v4 )
      {
        v4 = v11;
        *vertexOut = (hkVector4f)v8.m_quad;
      }
    }
  }
}

// File Line: 1268
// RVA: 0xCADAA0
void __fastcall hkgpConvexHull::getFarthestVertex(hkgpConvexHull *this, hkgpConvexHull::Inputs inputs, hkVector4f *point, hkVector4f *vertexOut)
{
  __m128 v4; // xmm0
  float v5; // xmm4_4
  hkgpConvexHullImpl *v6; // rax
  hkgpConvexHullImpl::Vertex *j; // rax
  hkVector4f v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm1
  float v11; // xmm2_4
  hkgpConvexHullImpl *v12; // rdx
  hkgpConvexHullImpl::Vertex *i; // rax
  __m128 v14; // xmm5
  __m128 v15; // xmm6
  __m128i v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm1
  float v19; // xmm2_4

  v4 = point->m_quad;
  v5 = 0.0;
  if ( inputs )
  {
    v12 = this->m_data;
    *vertexOut = (hkVector4f)v4;
    for ( i = v12->m_mesh.m_vertices.m_used; i; i = i->m_next )
    {
      v14 = v12->m_scaleInv.m_quad;
      v15 = v12->m_origin.m_quad;
      v16 = _mm_unpacklo_epi32(
              _mm_unpacklo_epi32(_mm_cvtsi32_si128(i->m_x[0]), _mm_cvtsi32_si128(i->m_x[2])),
              _mm_unpacklo_epi32(_mm_cvtsi32_si128(i->m_x[1]), _mm_cvtsi32_si128(0)));
      v17 = _mm_sub_ps(
              point->m_quad,
              _mm_add_ps(
                _mm_mul_ps((__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_cvtepi32_ps(v16), 4), 4), v14),
                v15));
      v18 = _mm_mul_ps(v17, v17);
      v19 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 170));
      if ( v19 > v5 )
      {
        v5 = v19;
        vertexOut->m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_cvtepi32_ps(v16), 4), 4),
                                v14),
                              v15);
      }
    }
  }
  else
  {
    v6 = this->m_data;
    *vertexOut = (hkVector4f)v4;
    for ( j = v6->m_mesh.m_vertices.m_used; j; j = j->m_next )
    {
      v8.m_quad = (__m128)j->m_source;
      v9 = _mm_sub_ps(point->m_quad, v8.m_quad);
      v10 = _mm_mul_ps(v9, v9);
      v11 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 170));
      if ( v11 > v5 )
      {
        v5 = v11;
        *vertexOut = (hkVector4f)v8.m_quad;
      }
    }
  }
}

// File Line: 1276
// RVA: 0xCADBD0
hkVector4f *__fastcall hkgpConvexHull::getCentroid(hkgpConvexHull *this)
{
  return hkgpConvexHullImpl::getCentroid<hkgpConvexHullImpl::PositionAsSource>(this->m_data);
}

// File Line: 1281
// RVA: 0xCADCA0
hkSimdFloat32 *__fastcall hkgpConvexHull::getVolume(hkgpConvexHull *this, hkSimdFloat32 *result)
{
  hkgpConvexHullImpl *v2; // rsi
  hkSimdFloat32 *v3; // rbx
  hkgpConvexHull *v4; // rdi
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  hkSimdFloat32 *v7; // rax
  hkErrStream v8; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v2 = this->m_data;
  v3 = result;
  v4 = this;
  if ( !v2->m_hasMassProperties )
  {
    hkErrStream::hkErrStream(&v8, &buf, 512);
    v5 = hkOstream::operator<<((hkOstream *)&v8.vfptr, "No mass properties available (");
    v6 = hkOstream::operator<<(v5, v2->m_uid, (int)v5);
    hkOstream::operator<<(v6, ") hkgpConvexHull::buildMassProperties need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         2046417031,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         366) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v8.vfptr);
  }
  v7 = v3;
  _mm_store_si128((__m128i *)v3, (__m128i)v4->m_data->m_volume.m_real);
  return v7;
}

// File Line: 1287
// RVA: 0xCADD60
hkSimdFloat32 *__fastcall hkgpConvexHull::getSurfaceArea(hkgpConvexHull *this, hkSimdFloat32 *result)
{
  hkgpConvexHullImpl *v2; // rsi
  hkSimdFloat32 *v3; // rbx
  hkgpConvexHull *v4; // rdi
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  hkSimdFloat32 *v7; // rax
  hkErrStream v8; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v2 = this->m_data;
  v3 = result;
  v4 = this;
  if ( !v2->m_hasMassProperties )
  {
    hkErrStream::hkErrStream(&v8, &buf, 512);
    v5 = hkOstream::operator<<((hkOstream *)&v8.vfptr, "No mass properties available (");
    v6 = hkOstream::operator<<(v5, v2->m_uid, (int)v5);
    hkOstream::operator<<(v6, ") hkgpConvexHull::buildMassProperties need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         2046417031,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         366) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v8.vfptr);
  }
  v7 = v3;
  _mm_store_si128((__m128i *)v3, (__m128i)v4->m_data->m_surface.m_real);
  return v7;
}

// File Line: 1293
// RVA: 0xCADBE0
hkSimdFloat32 *__fastcall hkgpConvexHull::getEdgeLengths(hkgpConvexHull *this, hkSimdFloat32 *result)
{
  hkSimdFloat32 *v2; // rbx

  v2 = result;
  hkgpConvexHullImpl::getEdgeLengths(this->m_data, result);
  return v2;
}

// File Line: 1298
// RVA: 0xCADC10
hkSimdFloat32 *__fastcall hkgpConvexHull::getSphericity(hkgpConvexHull *this, hkSimdFloat32 *result)
{
  hkSimdFloat32 *v2; // rdi
  hkgpConvexHull *v3; // rbx
  hkSimdFloat32 *v4; // rax
  float v5; // xmm0_4
  __m128 v6; // xmm0
  hkSimdFloat32 *v7; // rax
  hkSimdFloat32 resulta; // [rsp+20h] [rbp-18h]

  v2 = result;
  v3 = this;
  v4 = hkgpConvexHull::getVolume(this, &resulta);
  v5 = powf(v4->m_real.m128_f32[0], 0.66666669);
  v2->m_real = _mm_mul_ps(
                 _mm_shuffle_ps((__m128)LODWORD(FLOAT_4_8359756), (__m128)LODWORD(FLOAT_4_8359756), 0),
                 _mm_shuffle_ps((__m128)LODWORD(v5), (__m128)LODWORD(v5), 0));
  v6 = _mm_div_ps(v2->m_real, hkgpConvexHull::getSurfaceArea(v3, &resulta)->m_real);
  v7 = v2;
  *v2 = (hkSimdFloat32)v6;
  return v7;
}

// File Line: 1308
// RVA: 0xCADE20
void __fastcall hkgpConvexHull::getLocalInertia(hkgpConvexHull *this, hkTransformf *inertiaSpace, hkVector4f *inertiaDiagonal)
{
  hkgpConvexHullImpl *v3; // rsi
  hkVector4f *v4; // rbp
  hkTransformf *v5; // rbx
  hkgpConvexHull *v6; // rdi
  hkOstream *v7; // rax
  hkOstream *v8; // rax
  hkgpConvexHullImpl *v9; // rax
  hkErrStream v10; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v3 = this->m_data;
  v4 = inertiaDiagonal;
  v5 = inertiaSpace;
  v6 = this;
  if ( !v3->m_hasMassProperties )
  {
    hkErrStream::hkErrStream(&v10, &buf, 512);
    v7 = hkOstream::operator<<((hkOstream *)&v10.vfptr, "No mass properties available (");
    v8 = hkOstream::operator<<(v7, v3->m_uid, (int)v7);
    hkOstream::operator<<(v8, ") hkgpConvexHull::buildMassProperties need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         2046417031,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         366) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v10.vfptr);
  }
  v9 = v6->m_data;
  v5->m_rotation.m_col0 = v9->m_localTransform.m_rotation.m_col0;
  v5->m_rotation.m_col1 = v9->m_localTransform.m_rotation.m_col1;
  v5->m_rotation.m_col2 = v9->m_localTransform.m_rotation.m_col2;
  v5->m_translation = v9->m_localTransform.m_translation;
  *v4 = v6->m_data->m_inertia;
}

// File Line: 1315
// RVA: 0xCADF20
hkMatrix3f *__fastcall hkgpConvexHull::getWorldInertia(hkgpConvexHull *this)
{
  hkgpConvexHullImpl *v1; // rdi
  hkgpConvexHull *v2; // rbx
  hkOstream *v3; // rax
  hkOstream *v4; // rax
  hkErrStream v6; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v1 = this->m_data;
  v2 = this;
  if ( !v1->m_hasMassProperties )
  {
    hkErrStream::hkErrStream(&v6, &buf, 512);
    v3 = hkOstream::operator<<((hkOstream *)&v6.vfptr, "No mass properties available (");
    v4 = hkOstream::operator<<(v3, v1->m_uid, (int)v3);
    hkOstream::operator<<(v4, ") hkgpConvexHull::buildMassProperties need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         2046417031,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         366) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v6.vfptr);
  }
  return &v2->m_data->m_inertiaMatrix;
}

// File Line: 1321
// RVA: 0xCADFD0
hkVector4f *__fastcall hkgpConvexHull::getCenterOfMass(hkgpConvexHull *this)
{
  hkgpConvexHullImpl *v1; // rdi
  hkgpConvexHull *v2; // rbx
  hkOstream *v3; // rax
  hkOstream *v4; // rax
  hkErrStream v6; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v1 = this->m_data;
  v2 = this;
  if ( !v1->m_hasMassProperties )
  {
    hkErrStream::hkErrStream(&v6, &buf, 512);
    v3 = hkOstream::operator<<((hkOstream *)&v6.vfptr, "No mass properties available (");
    v4 = hkOstream::operator<<(v3, v1->m_uid, (int)v3);
    hkOstream::operator<<(v4, ") hkgpConvexHull::buildMassProperties need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         2046417031,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         366) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v6.vfptr);
  }
  return &v2->m_data->m_localTransform.m_translation;
}

// File Line: 1327
// RVA: 0xCAE080
hkVector4f *__fastcall hkgpConvexHull::getMajorPlane(hkgpConvexHull *this, hkVector4f *result)
{
  hkgpConvexHullImpl *v2; // rbx
  hkVector4f *v3; // rsi
  hkgpConvexHull *v4; // rdi
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  __m128 v7; // xmm3
  __m128i v8; // xmm0
  hkVector4f *v9; // rax
  __m128 v10; // xmm1
  hkErrStream v11; // [rsp+20h] [rbp-268h]
  hkTransformf inertiaSpace; // [rsp+40h] [rbp-248h]
  char buf; // [rsp+80h] [rbp-208h]

  v2 = this->m_data;
  v3 = result;
  v4 = this;
  if ( !v2->m_hasMassProperties )
  {
    hkErrStream::hkErrStream(&v11, &buf, 512);
    v5 = hkOstream::operator<<((hkOstream *)&v11.vfptr, "No mass properties available (");
    v6 = hkOstream::operator<<(v5, v2->m_uid, (int)v5);
    hkOstream::operator<<(v6, ") hkgpConvexHull::buildMassProperties need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         2046417031,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         366) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v11.vfptr);
  }
  hkgpConvexHull::getLocalInertia(v4, &inertiaSpace, (hkVector4f *)&v11);
  v7 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&v11), 1u), 1u);
  v8 = *((__m128i *)&inertiaSpace.m_rotation.m_col0
       + (unsigned __int8)hkVector4Comparison_maskToFirstIndex[_mm_movemask_ps(
                                                                 _mm_and_ps(
                                                                   _mm_cmpleps(
                                                                     v7,
                                                                     _mm_min_ps(
                                                                       _mm_shuffle_ps(v7, v7, 170),
                                                                       _mm_min_ps(
                                                                         _mm_shuffle_ps(v7, v7, 85),
                                                                         _mm_shuffle_ps(v7, v7, 0)))),
                                                                   (__m128)xmmword_141A79650))]);
  v9 = v3;
  _mm_store_si128((__m128i *)v3, v8);
  v10 = _mm_mul_ps((__m128)v8, inertiaSpace.m_translation.m_quad);
  v3->m_quad = _mm_shuffle_ps(
                 (__m128)v8,
                 _mm_unpackhi_ps(
                   (__m128)v8,
                   _mm_sub_ps(
                     (__m128)0i64,
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                       _mm_shuffle_ps(v10, v10, 170)))),
                 196);
  return v9;
}

// File Line: 1339
// RVA: 0xCAE460
hkVector4f *__fastcall hkgpConvexHull::getBestProjectionPlane(hkgpConvexHull *this, hkVector4f *result)
{
  hkVector4f *v2; // rbx
  hkgpConvexHullImpl *v3; // rdx
  __m128 v4; // xmm1
  __m128 v5; // xmm6
  __m128 v6; // xmm5
  __m128 v7; // xmm6
  __m128 v8; // xmm4
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm7
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm5
  hkVector4f *v16; // rax
  hkVector4f halfExtents; // [rsp+20h] [rbp-88h]
  hkTransformf worldTransform; // [rsp+30h] [rbp-78h]

  v2 = result;
  *result = 0i64;
  v3 = this->m_data;
  switch ( v3->m_dimensions )
  {
    case 1:
      v5 = _mm_shuffle_ps(v3->m_projectionAxis.m_quad, _mm_unpackhi_ps(v3->m_projectionAxis.m_quad, (__m128)0i64), 196);
      v6 = _mm_shuffle_ps(v5, v5, 241);
      v7 = _mm_shuffle_ps(v5, v5, 206);
      v8 = _mm_mul_ps(v6, v6);
      v9 = _mm_mul_ps(v7, v7);
      v10 = _mm_cmpltps(
              _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170)),
              _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170)));
      v11 = _mm_xor_ps(
              _mm_or_ps(_mm_andnot_ps(v10, v6), _mm_and_ps(v7, v10)),
              (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
      v12 = _mm_mul_ps(v11, v11);
      v13 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
              _mm_shuffle_ps(v12, v12, 170));
      v14 = _mm_rsqrt_ps(v13);
      v15 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v13), (__m128)0i64);
      v2->m_quad = _mm_or_ps(
                     _mm_and_ps(
                       _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmpleps(v13, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
                             _mm_mul_ps(*(__m128 *)_xmm, v14))),
                         v11),
                       v15),
                     _mm_andnot_ps(v15, v11));
      break;
    case 2:
      *v2 = v3->m_projectionPlane;
      break;
    case 3:
      halfExtents.m_quad = 0i64;
      hkgpConvexHull::getOrientedBoundingBox(this, &halfExtents, &worldTransform);
      v4 = *(&transform.m_quad
           + (unsigned __int8)hkVector4Comparison_maskToFirstIndex[_mm_movemask_ps(
                                                                     _mm_and_ps(
                                                                       _mm_cmpleps(
                                                                         halfExtents.m_quad,
                                                                         _mm_min_ps(
                                                                           _mm_shuffle_ps(
                                                                             halfExtents.m_quad,
                                                                             halfExtents.m_quad,
                                                                             170),
                                                                           _mm_min_ps(
                                                                             _mm_shuffle_ps(
                                                                               halfExtents.m_quad,
                                                                               halfExtents.m_quad,
                                                                               85),
                                                                             _mm_shuffle_ps(
                                                                               halfExtents.m_quad,
                                                                               halfExtents.m_quad,
                                                                               0)))),
                                                                       (__m128)xmmword_141A79650))]);
      v2->m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v4, v4, 85), worldTransform.m_rotation.m_col1.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v4, v4, 0), worldTransform.m_rotation.m_col0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v4, v4, 170), worldTransform.m_rotation.m_col2.m_quad));
      break;
  }
  v16 = v2;
  *(__m128i *)v2 = _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)v2), 4), 4);
  return v16;
}

// File Line: 1366
// RVA: 0xCAE670
void __fastcall hkgpConvexHull::computeLocalTransform(hkgpConvexHull *this, hkTransformf *localTransform)
{
  hkgpConvexHullImpl *v2; // rsi
  hkTransformf *v3; // rbx
  hkgpConvexHull *v4; // rdi
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  hkgpConvexHullImpl *v7; // rax
  hkErrStream v8; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v2 = this->m_data;
  v3 = localTransform;
  v4 = this;
  if ( !v2->m_hasMassProperties )
  {
    hkErrStream::hkErrStream(&v8, &buf, 512);
    v5 = hkOstream::operator<<((hkOstream *)&v8.vfptr, "No mass properties available (");
    v6 = hkOstream::operator<<(v5, v2->m_uid, (int)v5);
    hkOstream::operator<<(v6, ") hkgpConvexHull::buildMassProperties need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         2046417031,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         366) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v8.vfptr);
  }
  v7 = v4->m_data;
  v3->m_rotation.m_col0 = v7->m_localTransform.m_rotation.m_col0;
  v3->m_rotation.m_col1 = v7->m_localTransform.m_rotation.m_col1;
  v3->m_rotation.m_col2 = v7->m_localTransform.m_rotation.m_col2;
  v3->m_translation = v7->m_localTransform.m_translation;
}

// File Line: 1372
// RVA: 0xCAE1E0
void __fastcall hkgpConvexHull::getMajorPlanes(hkgpConvexHull *this, hkVector4f *planes)
{
  hkgpConvexHullImpl *v2; // rdi
  hkVector4f *v3; // rsi
  hkgpConvexHull *v4; // rbx
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  signed __int64 v7; // rdi
  __int128 *v8; // rax
  signed __int64 v9; // rdx
  __int128 v10; // xmm1
  __int128 v11; // xmm0
  int v12; // eax
  int v13; // ecx
  __m128 v14; // xmm10
  __int64 v15; // rax
  __m128 v16; // xmm5
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm4
  __m128 v21; // xmm6
  __m128 v22; // xmm2
  hkVector4f inertiaDiagonal; // [rsp+20h] [rbp-D8h]
  hkErrStream v24; // [rsp+30h] [rbp-C8h]
  __m128 v25; // [rsp+50h] [rbp-A8h]
  __m128 v26; // [rsp+60h] [rbp-98h]
  hkVector4f v27; // [rsp+70h] [rbp-88h]
  hkVector4f v28; // [rsp+88h] [rbp-70h]
  __int128 v29[3]; // [rsp+98h] [rbp-60h]
  __m128 v30; // [rsp+A8h] [rbp-50h]
  char buf; // [rsp+B8h] [rbp-40h]

  v2 = this->m_data;
  v3 = planes;
  v4 = this;
  if ( !v2->m_hasMassProperties )
  {
    hkErrStream::hkErrStream(&v24, &buf, 512);
    v5 = hkOstream::operator<<((hkOstream *)&v24.vfptr, "No mass properties available (");
    v6 = hkOstream::operator<<(v5, v2->m_uid, (int)v5);
    hkOstream::operator<<(v6, ") hkgpConvexHull::buildMassProperties need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         2046417031,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         366) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v24.vfptr);
  }
  hkgpConvexHull::getLocalInertia(v4, (hkTransformf *)&v27.m_quad.m128_u16[4], &inertiaDiagonal);
  v7 = 0i64;
  inertiaDiagonal.m_quad.m128_u64[0] = 0x100000000i64;
  inertiaDiagonal.m_quad.m128_i32[2] = 2;
  v25 = hkgpConvexHull::getWidth(v4, (hkSimdFloat32 *)&v24, (hkVector4f *)((char *)&v27 + 8))->m_real;
  v26 = hkgpConvexHull::getWidth(v4, (hkSimdFloat32 *)&v24, &v28)->m_real;
  v8 = (__int128 *)hkgpConvexHull::getWidth(v4, (hkSimdFloat32 *)&v24, (hkVector4f *)v29);
  v9 = 0i64;
  v27.m_quad = (__m128)*v8;
  do
  {
    v10 = *((_OWORD *)&v25 + v9 + 1);
    v11 = *((_OWORD *)&v25 + v9);
    if ( *(float *)&v11 < *(float *)&v10 )
    {
      *((_OWORD *)&v25 + v9) = v10;
      v12 = inertiaDiagonal.m_quad.m128_i32[v9 + 1];
      *((_OWORD *)&v25 + v9 + 1) = v11;
      v13 = inertiaDiagonal.m_quad.m128_i32[v9];
      inertiaDiagonal.m_quad.m128_i32[v9] = v12;
      inertiaDiagonal.m_quad.m128_i32[v9 + 1] = v13;
      v9 = -1i64;
    }
    ++v9;
  }
  while ( v9 < 2 );
  v14 = v30;
  do
  {
    v15 = inertiaDiagonal.m_quad.m128_i32[v7++];
    ++v3;
    v16 = *(__m128 *)((char *)&v27.m_quad + 16 * v15 + 8);
    v17 = _mm_mul_ps(v16, v16);
    v18 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
            _mm_shuffle_ps(v17, v17, 170));
    v19 = _mm_rsqrt_ps(v18);
    v20 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v18), (__m128)0i64);
    v21 = _mm_or_ps(
            _mm_and_ps(
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v18, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                    _mm_mul_ps(*(__m128 *)_xmm, v19))),
                v16),
              v20),
            _mm_andnot_ps(v20, v16));
    v22 = _mm_mul_ps(v21, v14);
    v3[-1].m_quad = _mm_shuffle_ps(
                      v21,
                      _mm_unpackhi_ps(
                        v21,
                        _mm_sub_ps(
                          (__m128)0i64,
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                            _mm_shuffle_ps(v22, v22, 170)))),
                      196);
  }
  while ( v7 < 3 );
}                     _mm_shuffle_ps(v22, v22, 170)))),
                      196);
  

// File Line: 1402
// RVA: 0xCAE750
hkBool *__fastcall hkgpConvexHull::rayCast(hkgpConvexHull *this, hkBool *result, hkVector4f *origin, hkVector4f *direction, float *minFractionInOut, int *planeOut)
{
  hkVector4f *v6; // rbp
  hkVector4f *v7; // r14
  hkBool *v8; // rbx
  hkgpConvexHull *v9; // rdi
  hkgpConvexHullImpl *v10; // rsi
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkgpConvexHullImpl *v13; // rax
  __m128i v14; // xmm8
  __int64 v15; // rcx
  __m128i v16; // xmm9
  __int64 v17; // r8
  __m128 *v18; // rdx
  __m128 v19; // xmm6
  __m128 v20; // xmm5
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm10
  __m128 v26; // xmm7
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  __m128i v29; // xmm0
  __m128 v30; // xmm1
  hkErrStream v32; // [rsp+20h] [rbp-2B8h]
  char buf; // [rsp+40h] [rbp-298h]

  v6 = direction;
  v7 = origin;
  v8 = result;
  v9 = this;
  if ( (unsigned int)hkgpConvexHull::getDimensions(this) != 3 )
    goto LABEL_18;
  v10 = v9->m_data;
  if ( !v10->m_hasIndexing )
  {
    hkErrStream::hkErrStream(&v32, &buf, 512);
    v11 = hkOstream::operator<<((hkOstream *)&v32.vfptr, "No index available (");
    v12 = hkOstream::operator<<(v11, v10->m_uid, (int)v11);
    hkOstream::operator<<(v12, ") hkgpConvexHull::buildIndices need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         2046417030,
                         &buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         358) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v32.vfptr);
  }
  v13 = v9->m_data;
  v14 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
  v15 = 0i64;
  v16 = 0i64;
  v17 = v13->m_planes.m_size;
  v18 = &v13->m_planes.m_data->m_quad;
  v19 = (__m128)xmmword_141A712F0;
  v20 = (__m128)xmmword_141A712A0;
  if ( v17 > 0 )
  {
    do
    {
      v21 = _mm_mul_ps(*v18, v7->m_quad);
      v22 = _mm_mul_ps(*v18, v6->m_quad);
      v23 = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, *v18), 196);
      v24 = _mm_add_ps(_mm_shuffle_ps(v23, v23, 78), v23);
      v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 177), v24);
      v26 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
              _mm_shuffle_ps(v22, v22, 170));
      if ( (float)(v26.m128_f32[0] * v26.m128_f32[0]) <= 0.00000011920929 )
        goto LABEL_18;
      v27 = _mm_rcp_ps(v26);
      v28 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v27, v26)), v27), _mm_sub_ps((__m128)0i64, v25));
      if ( v25.m128_f32[0] <= 0.0 )
      {
        if ( v28.m128_f32[0] > 0.0 )
        {
          v30 = _mm_cmpltps(v28, v20);
          v20 = _mm_or_ps(_mm_and_ps(v30, v28), _mm_andnot_ps(v30, v20));
        }
      }
      else
      {
        if ( v26.m128_f32[0] >= 0.0 )
          goto LABEL_18;
        v29 = (__m128i)_mm_cmpltps(v19, v28);
        v19 = _mm_or_ps(_mm_and_ps(v28, (__m128)v29), _mm_andnot_ps((__m128)v29, v19));
        v14 = _mm_or_si128(_mm_andnot_si128(v29, v14), _mm_and_si128(v29, v16));
      }
      ++v15;
      ++v18;
      v16 = _mm_add_epi32((__m128i)xmmword_141A72090, v16);
    }
    while ( v15 < v17 );
  }
  if ( !_mm_movemask_ps(
          _mm_and_ps(
            _mm_and_ps(
              _mm_and_ps(
                (__m128)_mm_or_si128(
                          _mm_cmpgt_epi32(v14, *(__m128i *)&g_intVectorConstants[0][0]),
                          _mm_cmpeq_epi32(v14, *(__m128i *)&g_intVectorConstants[0][0])),
                _mm_cmpleps(v19, v20)),
              _mm_cmpltps((__m128)0i64, v19)),
            _mm_cmpltps(
              v19,
              _mm_shuffle_ps((__m128)*(unsigned int *)minFractionInOut, (__m128)*(unsigned int *)minFractionInOut, 0)))) )
  {
LABEL_18:
    v8->m_bool = 0;
    return v8;
  }
  if ( planeOut )
    *planeOut = v14.m128i_i32[0];
  *minFractionInOut = v19.m128_f32[0];
  v8->m_bool = 1;
  return v8;
}aneOut )
    *planeOut = v14.m12

// File Line: 1484
// RVA: 0xCAEA50
__int64 __fastcall hkgpConvexHull::classify(hkgpConvexHull *this, hkVector4f *plane, float thickness, float *boundsR)
{
  unsigned int v4; // er11
  __m128 *v5; // rcx
  float v6; // xmm5_4
  __m128 v7; // xmm3
  __m128 v8; // xmm4
  int v9; // er10
  int v10; // er8
  __m128 v11; // xmm2
  __m128 v12; // xmm2
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __int64 result; // rax

  v4 = 0;
  v5 = (__m128 *)this->m_data->m_mesh.m_vertices.m_used;
  LODWORD(v6) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(thickness), (__m128)LODWORD(thickness), 0);
  v7 = 0i64;
  v8 = 0i64;
  v9 = 0;
  v10 = 0;
  if ( v5 )
  {
    do
    {
      v11 = _mm_mul_ps(v5[1], plane->m_quad);
      v12 = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, plane->m_quad), 196);
      v13 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 78), v12);
      v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 177), v13);
      if ( v5->m128_u64[1] )
      {
        v7 = _mm_min_ps(v14, v7);
        v8 = _mm_max_ps(v14, v8);
      }
      else
      {
        v7 = v14;
        v8 = v14;
      }
      if ( COERCE_FLOAT((unsigned int)(2 * v14.m128_i32[0]) >> 1) >= v6 )
      {
        v5[2].m128_i32[3] = v14.m128_i32[0];
        if ( v14.m128_f32[0] <= 0.0 )
          ++v9;
        else
          ++v10;
      }
      else
      {
        v5[2].m128_i32[3] = 0;
      }
      v5 = (__m128 *)v5->m128_u64[0];
    }
    while ( v5 );
    if ( v10 && v9 )
    {
      v4 = 3;
    }
    else if ( v9 <= v10 )
    {
      if ( v10 )
        v4 = 1;
    }
    else
    {
      v4 = 2;
    }
  }
  *boundsR = v7.m128_f32[0];
  result = v4;
  boundsR[1] = v8.m128_f32[0];
  return result;
}

// File Line: 1494
// RVA: 0xCAEB50
hkgpConvexHull::Side __fastcall hkgpConvexHull::splitByPlane(hkgpConvexHull *this, hkVector4f *plane, hkgpConvexHull **pos, hkgpConvexHull **neg, float thickness)
{
  return hkgpConvexHullImpl::splitByPlane<hkgpConvexHullImpl::PositionAsSource>(
           this->m_data,
           plane,
           pos,
           neg,
           thickness);
}

// File Line: 1499
// RVA: 0xCAEB60
void __fastcall hkgpConvexHull::subdivide(hkgpConvexHull *this, int recursions, hkArray<hkgpConvexHull *,hkContainerHeapAllocator> *output, float thickness)
{
  hkArray<hkgpConvexHull *,hkContainerHeapAllocator> *v4; // rbx
  __int64 v5; // rdi
  hkgpConvexHull *v6; // rsi
  __int64 v7; // r13
  __int64 v8; // r12
  int v9; // er15
  __int64 v10; // rbp
  hkgpConvexHull *v11; // r14
  hkVector4f *v12; // rax
  hkgpConvexHull *v13; // rsi
  hkgpConvexHull *v14; // rdi
  int v15; // eax
  __int64 v16; // rax
  hkBaseObjectVtbl *v17; // rax
  hkgpConvexHull *v18; // rcx
  hkgpConvexHull *pos; // [rsp+30h] [rbp-58h]
  hkgpConvexHull *neg; // [rsp+38h] [rbp-50h]
  hkVector4f v21; // [rsp+40h] [rbp-48h]
  hkResult result; // [rsp+98h] [rbp+10h]

  v4 = output;
  v5 = (unsigned int)recursions;
  output->m_size = 0;
  v6 = hkgpConvexHull::clone(this);
  if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
  v4->m_data[v4->m_size++] = v6;
  if ( (signed int)v5 > 0 )
  {
    v7 = v5;
    while ( 1 )
    {
      v8 = v4->m_size;
      v9 = 0;
      v10 = 0i64;
      if ( v8 > 0 )
        break;
LABEL_22:
      if ( !--v7 )
        return;
    }
    while ( 1 )
    {
      v11 = v4->m_data[v10];
      hkgpConvexHull::buildMassProperties(v4->m_data[v10], &result);
      v12 = hkgpConvexHull::getMajorPlane(v11, &v21);
      if ( hkgpConvexHull::splitByPlane(v11, v12, &pos, &neg, thickness) == 3 )
      {
        v13 = pos;
        v14 = neg;
        if ( pos )
        {
          if ( neg )
          {
            if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
            v4->m_data[v4->m_size] = v13;
            v15 = v4->m_capacityAndFlags;
            if ( ++v4->m_size == (v15 & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
            v4->m_data[v4->m_size] = v14;
            v16 = v4->m_size;
            v4->m_size = v16;
            if ( (_DWORD)v16 != v9 )
              v4->m_data[v10] = v4->m_data[v16];
            if ( !v11 )
              goto LABEL_21;
            v17 = v11->vfptr;
            v18 = v11;
            goto LABEL_20;
          }
          pos->vfptr->__vecDelDtor((hkBaseObject *)pos, 1u);
        }
        if ( v14 )
        {
          v17 = v14->vfptr;
          v18 = v14;
LABEL_20:
          v17->__vecDelDtor((hkBaseObject *)&v18->vfptr, 1u);
          goto LABEL_21;
        }
      }
LABEL_21:
      ++v10;
      ++v9;
      if ( v10 >= v8 )
        goto LABEL_22;
    }
  }
}

// File Line: 1529
// RVA: 0xCAED60
void __fastcall hkgpConvexHull::fetchPositions(hkgpConvexHull *this, hkgpConvexHull::Inputs inputs, hkArray<hkVector4f,hkContainerHeapAllocator> *positions)
{
  hkgpConvexHullImpl *v3; // rdi
  __int64 v4; // r14
  int v5; // esi
  int v6; // eax
  hkArray<hkVector4f,hkContainerHeapAllocator> *v7; // rbx
  int v8; // er9
  int v9; // eax
  hkgpConvexHullImpl::Vertex *v10; // rax
  signed __int64 j; // rdx
  _OWORD *v12; // rcx
  int v13; // eax
  hkgpConvexHullImpl::Vertex *v14; // rdx
  signed __int64 i; // rcx
  __m128 *v16; // rax
  hkResult result; // [rsp+48h] [rbp+10h]

  v3 = this->m_data;
  v4 = positions->m_size;
  v5 = v3->m_mesh.m_vertices.m_numUsed;
  v6 = positions->m_capacityAndFlags & 0x3FFFFFFF;
  v7 = positions;
  v8 = v4 + v5;
  if ( inputs )
  {
    if ( v6 < v8 )
    {
      v13 = 2 * v6;
      if ( v8 < v13 )
        v8 = v13;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, positions, v8, 16);
    }
    v7->m_size += v5;
    v14 = v3->m_mesh.m_vertices.m_used;
    for ( i = (signed __int64)&v7->m_data[v4]; v14; v14 = v14->m_next )
    {
      v16 = (__m128 *)i;
      i += 16i64;
      *v16 = _mm_add_ps(
               _mm_mul_ps(
                 (__m128)_mm_srli_si128(
                           _mm_slli_si128(
                             (__m128i)_mm_cvtepi32_ps(
                                        _mm_unpacklo_epi32(
                                          _mm_unpacklo_epi32(
                                            _mm_cvtsi32_si128(v14->m_x[0]),
                                            _mm_cvtsi32_si128(v14->m_x[2])),
                                          _mm_unpacklo_epi32(_mm_cvtsi32_si128(v14->m_x[1]), _mm_cvtsi32_si128(0)))),
                             4),
                           4),
                 v3->m_scaleInv.m_quad),
               v3->m_origin.m_quad);
    }
  }
  else
  {
    if ( v6 < v8 )
    {
      v9 = 2 * v6;
      if ( v8 < v9 )
        v8 = v9;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, positions, v8, 16);
    }
    v7->m_size += v5;
    v10 = v3->m_mesh.m_vertices.m_used;
    for ( j = (signed __int64)&v7->m_data[v4]; v10; v10 = v10->m_next )
    {
      v12 = (_OWORD *)j;
      j += 16i64;
      *v12 = v10->m_source;
    }
  }
}

// File Line: 1537
// RVA: 0xCAEEB0
void __fastcall hkgpConvexHull::fetchPlanes(hkgpConvexHull *this, hkArray<hkVector4f,hkContainerHeapAllocator> *planes)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v2; // rbx
  hkgpConvexHull *v3; // rbp
  int v4; // eax
  __int64 v5; // rsi
  int v6; // edi
  int v7; // er9
  int v8; // ecx
  int v9; // ecx
  signed __int64 v10; // rsi
  int v11; // ebx
  int v12; // er14
  _OWORD *v13; // rdi
  hkVector4f *v14; // rax
  hkResult result; // [rsp+58h] [rbp+10h]

  v2 = planes;
  v3 = this;
  v4 = hkgpConvexHull::getNumPlanes(this);
  v5 = v2->m_size;
  v6 = v4;
  v7 = v5 + v4;
  v8 = v2->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < (signed int)v5 + v4 )
  {
    v9 = 2 * v8;
    if ( v7 < v9 )
      v7 = v9;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, v7, 16);
  }
  v2->m_size += v6;
  v10 = (signed __int64)&v2->m_data[v5];
  v11 = 0;
  v12 = hkgpConvexHull::getNumPlanes(v3);
  if ( v12 > 0 )
  {
    do
    {
      v13 = (_OWORD *)v10;
      v10 += 16i64;
      v14 = hkgpConvexHull::getPlane(v3, v11++);
      *v13 = v14->m_quad;
    }
    while ( v11 < v12 );
  }
}

// File Line: 1546
// RVA: 0xCAEF70
void __fastcall hkgpConvexHull::fetchBevelPlanes(hkgpConvexHull *this, float maxCosAngle, hkArray<hkVector4f,hkContainerHeapAllocator> *bevelPlanes)
{
  hkgpConvexHullImpl::buildBevelPlanes<hkgpConvexHullImpl::PositionAsTransform>(this->m_data, maxCosAngle, bevelPlanes);
}

// File Line: 1551
// RVA: 0xCAEF80
int __fastcall hkgpConvexHull::generateIndexedFaces(hkgpConvexHull *this, hkgpConvexHull::Inputs inputs, hkArray<unsigned char,hkContainerHeapAllocator> *verticesPerFace, hkArray<unsigned short,hkContainerHeapAllocator> *indices, hkBool maximizeArea)
{
  return hkgpConvexHullImpl::generateIndexedFaces<unsigned char,unsigned short>(
           this->m_data,
           verticesPerFace,
           indices,
           inputs == 0,
           maximizeArea.m_bool != 0);
}

// File Line: 1556
// RVA: 0xCAEFC0
int __fastcall hkgpConvexHull::generateIndexedFaces(hkgpConvexHull *this, hkgpConvexHull::Inputs inputs, hkArray<int,hkContainerHeapAllocator> *verticesPerFace, hkArray<int,hkContainerHeapAllocator> *indices, hkBool maximizeArea)
{
  return hkgpConvexHullImpl::generateIndexedFaces<int,int>(
           this->m_data,
           verticesPerFace,
           indices,
           inputs == 0,
           maximizeArea.m_bool != 0);
}

// File Line: 1561
// RVA: 0xCAF000
void __fastcall hkgpConvexHull::generateVertexAdjacencyGraph(hkgpConvexHull *this, hkArray<int,hkContainerHeapAllocator> *edges, hkArray<int,hkContainerHeapAllocator> *vertexOffsets)
{
  hkgpConvexHullImpl::generateVertexAdjacencyGraph(this->m_data, edges, vertexOffsets);
}

// File Line: 1566
// RVA: 0xCAF010
void __fastcall hkgpConvexHull::generatePlanesPerVertex(hkgpConvexHull *this, hkArray<int,hkContainerHeapAllocator> *startPlaneOffsetOut, hkArray<int,hkContainerHeapAllocator> *planeIndicesOut)
{
  hkgpConvexHullImpl::generatePlanesPerVertex(this->m_data, startPlaneOffsetOut, planeIndicesOut);
}

// File Line: 1573
// RVA: 0xCAF020
void __fastcall hkgpConvexHull::generateGeometry(hkgpConvexHull *this, hkgpConvexHull::Inputs inputs, hkGeometry *geometry, int material, bool planarTwoSided)
{
  hkgpConvexHull *v5; // rsi
  hkgpConvexHullImpl *v6; // rcx
  bool v7; // r12
  int v8; // er14
  hkGeometry *v9; // rbx
  int v10; // eax
  int v11; // edi
  int v12; // er9
  int v13; // eax
  int v14; // eax
  int v15; // er13
  __m128 *v16; // rdi
  int v17; // er9
  int v18; // eax
  int v19; // eax
  signed __int64 v20; // r13
  unsigned __int64 v21; // rbx
  hkResultEnum v22; // er14
  __m128 v23; // xmm0
  hkgpConvexHullImpl::Triangle *v24; // rbx
  signed __int64 v25; // rdi
  int v26; // eax
  int v27; // eax
  int v28; // edi
  int v29; // er9
  int v30; // eax
  int v31; // eax
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *v32; // r13
  int v33; // ecx
  __m128 *v34; // rdi
  __int64 v35; // rbx
  __int32 v36; // eax
  int v37; // er9
  int v38; // er9
  signed __int64 v39; // rbx
  hkgpConvexHullImpl::Vertex *v40; // r8
  hkResultEnum v41; // er9
  __m128 v42; // xmm0
  signed __int64 v43; // rdx
  signed __int64 v44; // r8
  bool v45; // r9
  int v46; // ecx
  int v47; // ecx
  hkResult v48; // [rsp+30h] [rbp-20h]
  hkResult result; // [rsp+34h] [rbp-1Ch]
  hkResult v50; // [rsp+38h] [rbp-18h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > array; // [rsp+40h] [rbp-10h]
  hkResult v52; // [rsp+90h] [rbp+40h]
  int v53; // [rsp+98h] [rbp+48h]
  int v54; // [rsp+A8h] [rbp+58h]

  v54 = material;
  v5 = this;
  v6 = this->m_data;
  v7 = inputs == 0;
  v8 = material;
  v9 = geometry;
  if ( v6->m_dimensions == 2 )
  {
    v27 = geometry->m_vertices.m_size;
    array.m_hashMod = 2147483648;
    result.m_enum = v27;
    array.m_elem = 0i64;
    array.m_numElems = 0;
    v28 = v6->m_mesh.m_vertices.m_numUsed;
    v52.m_enum = (planarTwoSided != 0) + 1;
    v29 = geometry->m_vertices.m_size + v28;
    v53 = geometry->m_vertices.m_size;
    v30 = geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v30 < v29 )
    {
      v31 = 2 * v30;
      if ( v29 < v31 )
        v29 = v31;
      hkArrayUtil::_reserve(
        &v50,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &geometry->m_vertices,
        v29,
        16);
    }
    v9->m_vertices.m_size += v28;
    v32 = &v9->m_triangles;
    v33 = v9->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
    v34 = &v9->m_vertices.m_data[v53].m_quad;
    v35 = v9->m_triangles.m_size;
    v36 = v52.m_enum * (v5->m_data->m_mesh.m_vertices.m_numUsed - 2);
    v37 = v35 + v36;
    v53 = v52.m_enum * (v5->m_data->m_mesh.m_vertices.m_numUsed - 2);
    if ( v33 < (signed int)v35 + v36 )
    {
      if ( v37 < 2 * v33 )
        v37 = 2 * v33;
      hkArrayUtil::_reserve(&v52, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v32, v37, 16);
      v36 = v53;
    }
    v32->m_size += v36;
    v38 = v5->m_data->m_mesh.m_vertices.m_numUsed;
    v39 = (signed __int64)&v32->m_data[v35];
    if ( (array.m_hashMod & 0x3FFFFFFF) >= v38 )
    {
      v48.m_enum = 0;
    }
    else
    {
      if ( v38 < 2 * (array.m_hashMod & 0x3FFFFFFF) )
        v38 = 2 * (array.m_hashMod & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v48, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v38, 4);
    }
    v40 = v5->m_data->m_mesh.m_vertices.m_used;
    if ( v40 )
    {
      v41 = result.m_enum;
      do
      {
        *((_DWORD *)&array.m_elem->key + array.m_numElems) = array.m_numElems++ + v41;
        if ( v7 )
          v42 = v40->m_source.m_quad;
        else
          v42 = _mm_add_ps(
                  _mm_mul_ps(
                    (__m128)_mm_srli_si128(
                              _mm_slli_si128(
                                (__m128i)_mm_cvtepi32_ps(
                                           _mm_unpacklo_epi32(
                                             _mm_unpacklo_epi32(
                                               _mm_cvtsi32_si128(v40->m_x[0]),
                                               _mm_cvtsi32_si128(v40->m_x[2])),
                                             _mm_unpacklo_epi32(_mm_cvtsi32_si128(v40->m_x[1]), _mm_cvtsi32_si128(0)))),
                                4),
                              4),
                    v5->m_data->m_scaleInv.m_quad),
                  v5->m_data->m_origin.m_quad);
        *v34 = v42;
        v40 = v40->m_next;
        ++v34;
      }
      while ( v40 );
    }
    v43 = 1i64;
    v44 = array.m_numElems - 1;
    if ( v44 > 1 )
    {
      v45 = planarTwoSided;
      do
      {
        v39 += 16i64;
        *(_DWORD *)(v39 - 16) = array.m_elem->key;
        *(_DWORD *)(v39 - 12) = *((_DWORD *)&array.m_elem->key + v43);
        v46 = *((_DWORD *)&array.m_elem->key + v43 + 1);
        *(_DWORD *)(v39 - 4) = v8;
        *(_DWORD *)(v39 - 8) = v46;
        if ( v45 )
        {
          v39 += 16i64;
          *(_DWORD *)(v39 - 16) = array.m_elem->key;
          *(_DWORD *)(v39 - 12) = *((_DWORD *)&array.m_elem->key + v43 + 1);
          v47 = *((_DWORD *)&array.m_elem->key + v43);
          *(_DWORD *)(v39 - 4) = v8;
          *(_DWORD *)(v39 - 8) = v47;
        }
        ++v43;
      }
      while ( v43 < v44 );
    }
    array.m_numElems = 0;
    if ( array.m_hashMod >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array.m_elem,
        4 * array.m_hashMod);
  }
  else if ( v6->m_dimensions == 3 )
  {
    v10 = geometry->m_vertices.m_size;
    array.m_hashMod = -1;
    v52.m_enum = v10;
    v53 = v10;
    array.m_elem = 0i64;
    array.m_numElems = 0;
    v11 = v6->m_mesh.m_vertices.m_numUsed;
    v12 = v10 + v11;
    v13 = geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v13 < v12 )
    {
      v14 = 2 * v13;
      if ( v12 < v14 )
        v12 = v14;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &geometry->m_vertices,
        v12,
        16);
    }
    v9->m_vertices.m_size += v11;
    v15 = v5->m_data->m_mesh.m_triangles.m_numUsed;
    v16 = &v9->m_vertices.m_data[v53].m_quad;
    v17 = v9->m_triangles.m_size + v15;
    v53 = v9->m_triangles.m_size;
    v18 = v9->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v18 < v17 )
    {
      v19 = 2 * v18;
      if ( v17 < v19 )
        v17 = v19;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v9->m_triangles,
        v17,
        16);
    }
    v9->m_triangles.m_size += v15;
    v20 = (signed __int64)&v9->m_triangles.m_data[v53];
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
      &array,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v5->m_data->m_mesh.m_vertices.m_numUsed);
    v21 = (unsigned __int64)v5->m_data->m_mesh.m_vertices.m_used;
    if ( v21 )
    {
      v22 = v52.m_enum;
      do
      {
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &array,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v21,
          v22 + (array.m_numElems & 0x7FFFFFFF));
        if ( v7 )
          v23 = *(__m128 *)(v21 + 16);
        else
          v23 = _mm_add_ps(
                  _mm_mul_ps(
                    (__m128)_mm_srli_si128(
                              _mm_slli_si128(
                                (__m128i)_mm_cvtepi32_ps(
                                           _mm_unpacklo_epi32(
                                             _mm_unpacklo_epi32(
                                               _mm_cvtsi32_si128(*(_DWORD *)(v21 + 32)),
                                               _mm_cvtsi32_si128(*(_DWORD *)(v21 + 40))),
                                             _mm_unpacklo_epi32(
                                               _mm_cvtsi32_si128(*(_DWORD *)(v21 + 36)),
                                               _mm_cvtsi32_si128(0)))),
                                4),
                              4),
                    v5->m_data->m_scaleInv.m_quad),
                  v5->m_data->m_origin.m_quad);
        *v16 = v23;
        v21 = *(_QWORD *)v21;
        ++v16;
      }
      while ( v21 );
      v8 = v54;
    }
    v24 = v5->m_data->m_mesh.m_triangles.m_used;
    if ( v24 )
    {
      v25 = v20 + 8;
      do
      {
        *(_DWORD *)(v25 - 8) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                 &array,
                                 (unsigned __int64)v24->m_vertices[0],
                                 0xFFFFFFFFFFFFFFFFui64);
        *(_DWORD *)(v25 - 4) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                 &array,
                                 (unsigned __int64)v24->m_vertices[1],
                                 0xFFFFFFFFFFFFFFFFui64);
        v26 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                &array,
                (unsigned __int64)v24->m_vertices[2],
                0xFFFFFFFFFFFFFFFFui64);
        *(_DWORD *)(v25 + 4) = v8;
        v25 += 16i64;
        *(_DWORD *)(v25 - 16) = v26;
        v24 = v24->m_next;
      }
      while ( v24 );
    }
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &array,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&array);
  }
}

