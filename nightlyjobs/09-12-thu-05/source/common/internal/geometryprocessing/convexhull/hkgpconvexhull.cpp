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
  this->m_method = SKM_PLANES;
  *(_QWORD *)&this->m_minComDistance = 925353388i64;
}

// File Line: 61
// RVA: 0xCA8EF0
void __fastcall hkgpConvexHull::hkgpConvexHull(hkgpConvexHull *this)
{
  _QWORD **Value; // rax
  hkgpConvexHullImpl *v3; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkgpConvexHull::`vftable;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkgpConvexHullImpl *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 496i64);
  if ( v3 )
    hkgpConvexHullImpl::hkgpConvexHullImpl(v3);
  this->m_data = v3;
  v3->m_hull = this;
  this->m_userData = 0i64;
  this->m_userObject = 0i64;
}

// File Line: 69
// RVA: 0xCA8F60
void __fastcall hkgpConvexHull::~hkgpConvexHull(hkgpConvexHull *this)
{
  hkgpConvexHullImpl *m_data; // rdi
  _QWORD **Value; // rax

  m_data = this->m_data;
  this->vfptr = (hkBaseObjectVtbl *)&hkgpConvexHull::`vftable;
  if ( m_data )
  {
    hkgpConvexHullImpl::~hkgpConvexHullImpl(m_data);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkgpConvexHullImpl *, __int64))(*Value[11] + 16i64))(Value[11], m_data, 496i64);
  }
  hkgpConvexHull::deleteUserObject(this);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 75
// RVA: 0xCA9010
void __fastcall hkgpConvexHull::reset(hkgpConvexHull *this)
{
  hkgpConvexHullImpl::reset(this->m_data, 0);
  hkgpConvexHull::deleteUserObject(this);
}

// File Line: 81
// RVA: 0xCA9040
hkgpConvexHull *__fastcall hkgpConvexHull::clone(hkgpConvexHull *this)
{
  _QWORD **Value; // rax
  hkgpConvexHull *v3; // rax
  hkgpConvexHull *v4; // rax
  hkgpConvexHull *v5; // rbx
  hkgpConvexHullImpl *m_data; // rdi
  _QWORD **v7; // rax
  hkgpConvexHullImpl *v8; // rax
  hkgpConvexHull::IUserObject *m_userObject; // rcx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkgpConvexHull *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  if ( v3 )
  {
    hkgpConvexHull::hkgpConvexHull(v3);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  m_data = v5->m_data;
  if ( m_data )
  {
    hkgpConvexHullImpl::~hkgpConvexHullImpl(v5->m_data);
    v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkgpConvexHullImpl *, __int64))(*v7[11] + 16i64))(v7[11], m_data, 496i64);
  }
  v5->m_data = 0i64;
  v8 = hkgpConvexHullImpl::clone(this->m_data);
  v5->m_data = v8;
  v8->m_hull = v5;
  v5->m_userData = this->m_userData;
  m_userObject = this->m_userObject;
  if ( m_userObject )
    v5->m_userObject = m_userObject->vfptr->clone(m_userObject);
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
  hkgpConvexHull::IUserObject *m_userObject; // rcx

  m_userObject = this->m_userObject;
  if ( m_userObject )
    m_userObject->vfptr->__vecDelDtor(m_userObject, 1u);
  this->m_userObject = 0i64;
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
int __fastcall hkgpConvexHull::build(
        hkgpConvexHull *this,
        hkVector4f *points,
        int numPoints,
        hkgpConvexHull::BuildConfig *config)
{
  this->m_data->m_config = *config;
  return hkgpConvexHullImpl::build(this->m_data, points, numPoints, 0, 0i64);
}

// File Line: 130
// RVA: 0xCA91C0
int __fastcall hkgpConvexHull::build(
        hkgpConvexHull *this,
        hkStridedVertices *points,
        hkgpConvexHull::BuildConfig *config)
{
  hkVector4f *m_vertices; // rdx
  const float *v8; // rsi
  int m_numVertices; // edi
  int v10; // edx
  __int64 v11; // rcx
  hkVector4f *v12; // rdx
  int v13; // eax
  int v14; // ebx
  hkVector4f *array; // [rsp+30h] [rbp-28h] BYREF
  int v16; // [rsp+38h] [rbp-20h]
  int v17; // [rsp+3Ch] [rbp-1Ch]
  hkResult result; // [rsp+68h] [rbp+10h] BYREF

  if ( points->m_striding == 16 )
  {
    m_vertices = (hkVector4f *)points->m_vertices;
    if ( ((unsigned __int8)m_vertices & 0xF) == 0 )
      return hkgpConvexHull::build(this, m_vertices, points->m_numVertices, config);
  }
  v8 = points->m_vertices;
  m_numVertices = points->m_numVertices;
  array = 0i64;
  v16 = 0;
  v17 = 0x80000000;
  if ( m_numVertices > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, m_numVertices, 16);
  v10 = 0;
  v16 = m_numVertices;
  if ( points->m_numVertices > 0 )
  {
    v11 = 0i64;
    do
    {
      ++v10;
      array[v11++].m_quad = _mm_movelh_ps((__m128)*(unsigned __int64 *)v8, (__m128)*((unsigned int *)v8 + 2));
      array[v11 - 1] = (hkVector4f)_mm_srli_si128(
                                     _mm_slli_si128(_mm_load_si128((const __m128i *)&array[v11 - 1]), 4),
                                     4);
      v8 = (const float *)((char *)v8 + points->m_striding);
    }
    while ( v10 < points->m_numVertices );
    m_numVertices = v16;
  }
  v12 = 0i64;
  if ( m_numVertices )
    v12 = array;
  v13 = hkgpConvexHull::build(this, v12, m_numVertices, config);
  v16 = 0;
  v14 = v13;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v17);
  return v14;
}

// File Line: 161
// RVA: 0xCA9320
int __fastcall hkgpConvexHull::buildPlanar(
        hkgpConvexHull *this,
        hkVector4f *points,
        int numPoints,
        hkVector4f *plane,
        hkgpConvexHull::BuildConfig *config)
{
  this->m_data->m_config = *config;
  this->m_data->m_projectionPlane = (hkVector4f)plane->m_quad;
  return hkgpConvexHullImpl::build(this->m_data, points, numPoints, 1, 0i64);
}

// File Line: 168
// RVA: 0xCA9380
int __fastcall hkgpConvexHull::buildPlanar(
        hkgpConvexHull *this,
        hkStridedVertices *points,
        hkVector4f *plane,
        hkgpConvexHull::BuildConfig *config)
{
  const float *m_vertices; // rsi
  int m_numVertices; // edi
  int v11; // edx
  __int64 v12; // rcx
  hkVector4f *v13; // rdx
  int v14; // eax
  int v15; // ebx
  hkVector4f *array; // [rsp+30h] [rbp-38h] BYREF
  int v17; // [rsp+38h] [rbp-30h]
  int v18; // [rsp+3Ch] [rbp-2Ch]
  hkResult result; // [rsp+78h] [rbp+10h] BYREF

  if ( points->m_striding == 16 )
    return hkgpConvexHull::buildPlanar(this, (hkVector4f *)points->m_vertices, points->m_numVertices, plane, config);
  m_vertices = points->m_vertices;
  m_numVertices = points->m_numVertices;
  array = 0i64;
  v17 = 0;
  v18 = 0x80000000;
  if ( m_numVertices > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, m_numVertices, 16);
  v11 = 0;
  v17 = m_numVertices;
  if ( points->m_numVertices > 0 )
  {
    v12 = 0i64;
    do
    {
      ++v11;
      array[v12++].m_quad = _mm_movelh_ps(
                              (__m128)*(unsigned __int64 *)m_vertices,
                              (__m128)*((unsigned int *)m_vertices + 2));
      array[v12 - 1] = (hkVector4f)_mm_srli_si128(
                                     _mm_slli_si128(_mm_load_si128((const __m128i *)&array[v12 - 1]), 4),
                                     4);
      m_vertices = (const float *)((char *)m_vertices + points->m_striding);
    }
    while ( v11 < points->m_numVertices );
    m_numVertices = v17;
  }
  v13 = 0i64;
  if ( m_numVertices )
    v13 = array;
  v14 = hkgpConvexHull::buildPlanar(this, v13, m_numVertices, plane, config);
  v17 = 0;
  v15 = v14;
  if ( v18 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v18);
  return v15;
}

// File Line: 188
// RVA: 0xCA94F0
__int64 __fastcall hkgpConvexHull::buildFromPlanes(
        hkgpConvexHull *this,
        hkVector4f *planes,
        int numPlanes,
        hkgpConvexHull::BuildConfig *config)
{
  hkgpConvexHull *v4; // r15
  hkgpConvexHull::BuildConfig *v5; // r14
  __int64 v6; // rbx
  _QWORD *Value; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  int v12; // r9d
  float v13; // xmm8_4
  __int64 v14; // r13
  __int64 v15; // rdi
  hkVector4f *v16; // rcx
  __int64 v17; // rax
  __int64 v18; // r14
  __m128 v19; // xmm13
  hkVector4f *v20; // r12
  __int64 v21; // rax
  __int64 v22; // rbx
  __m128 v23; // xmm1
  hkVector4f *v24; // r15
  __m128 v25; // xmm9
  __m128 v26; // xmm6
  char v27; // cl
  int v28; // r8d
  __int64 v29; // rdx
  __m128 v30; // xmm7
  hkVector4f *v31; // rax
  __m128 v32; // xmm2
  __m128 v33; // xmm2
  __m128 v34; // xmm1
  __int64 v35; // rdx
  int v36; // r8d
  hkVector4f *v37; // r9
  __m128 v38; // xmm2
  __m128 v39; // xmm2
  __m128 v40; // xmm1
  __int64 v41; // rdx
  int v42; // r8d
  hkVector4f *v43; // r9
  __m128 v44; // xmm2
  __m128 v45; // xmm2
  __m128 v46; // xmm1
  int v47; // r8d
  __int64 v48; // r9
  hkVector4f *v49; // rdx
  __m128 v50; // xmm2
  __m128 v51; // xmm2
  __m128 v52; // xmm1
  int v53; // ecx
  _QWORD *v54; // rax
  _QWORD *v55; // rcx
  _QWORD *v56; // r8
  unsigned __int64 v57; // rax
  _QWORD *v58; // rcx
  unsigned int v59; // ebx
  hkVector4f *v61; // [rsp+30h] [rbp-C0h]
  hkVector4f *array; // [rsp+48h] [rbp-A8h] BYREF
  int numPoints; // [rsp+50h] [rbp-A0h]
  int v64; // [rsp+54h] [rbp-9Ch]
  hkMatrix3f v65; // [rsp+60h] [rbp-90h] BYREF
  hkgpConvexHull *vars0; // [rsp+140h] [rbp+50h]
  hkgpConvexHull *result; // [rsp+150h] [rbp+60h] BYREF
  hkgpConvexHull::BuildConfig *v68; // [rsp+158h] [rbp+68h]
  hkgpConvexHull::BuildConfig *v69; // [rsp+168h] [rbp+78h]

  v69 = config;
  result = this;
  v4 = this;
  v5 = config;
  v6 = numPlanes;
  array = 0i64;
  numPoints = 0;
  v64 = 0x80000000;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtVertexEnumeration";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  *(float *)&result = FLOAT_0_0000099999997;
  v12 = 3 * v6;
  LODWORD(v13) = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0).m128_u32[0];
  if ( (v64 & 0x3FFFFFFF) < 3 * (int)v6 )
  {
    if ( v12 < 2 * (v64 & 0x3FFFFFFF) )
      v12 = 2 * (v64 & 0x3FFFFFFF);
    hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v12, 16);
  }
  v14 = 0i64;
  v15 = v6;
  if ( (int)v6 > 0 )
  {
    v16 = planes;
    v61 = planes;
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
                  v31 = planes;
                  do
                  {
                    if ( !v27 )
                      break;
                    v32 = _mm_mul_ps(v30, v31->m_quad);
                    v33 = _mm_shuffle_ps(v32, _mm_unpackhi_ps(v32, v31->m_quad), 196);
                    v34 = _mm_add_ps(_mm_shuffle_ps(v33, v33, 78), v33);
                    if ( (float)(_mm_shuffle_ps(v34, v34, 177).m128_f32[0] + v34.m128_f32[0]) > v13 )
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
                  v37 = &planes[v35];
                  do
                  {
                    if ( !v27 )
                      break;
                    v38 = _mm_mul_ps(v30, v37->m_quad);
                    v39 = _mm_shuffle_ps(v38, _mm_unpackhi_ps(v38, v37->m_quad), 196);
                    v40 = _mm_add_ps(_mm_shuffle_ps(v39, v39, 78), v39);
                    if ( (float)(_mm_shuffle_ps(v40, v40, 177).m128_f32[0] + v40.m128_f32[0]) > v13 )
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
                  v43 = &planes[v41];
                  do
                  {
                    if ( !v27 )
                      break;
                    v44 = _mm_mul_ps(v30, v43->m_quad);
                    v45 = _mm_shuffle_ps(v44, _mm_unpackhi_ps(v44, v43->m_quad), 196);
                    v46 = _mm_add_ps(_mm_shuffle_ps(v45, v45, 78), v45);
                    if ( (float)(_mm_shuffle_ps(v46, v46, 177).m128_f32[0] + v46.m128_f32[0]) > v13 )
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
                      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
                      v53 = numPoints;
                    }
                    array[v53] = (hkVector4f)v30;
                    ++numPoints;
                  }
                }
                else
                {
                  v49 = &planes[v47];
                  while ( v27 )
                  {
                    v50 = _mm_mul_ps(v30, v49->m_quad);
                    v51 = _mm_shuffle_ps(v50, _mm_unpackhi_ps(v50, v49->m_quad), 196);
                    v52 = _mm_add_ps(_mm_shuffle_ps(v51, v51, 78), v51);
                    if ( (float)(_mm_shuffle_ps(v52, v52, 177).m128_f32[0] + v52.m128_f32[0]) > v13 )
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
    v58 = v55 + 2;
    *((_DWORD *)v58 - 2) = v57;
    v56[1] = v58;
  }
  if ( numPoints <= 3 )
    v59 = -1;
  else
    v59 = hkgpConvexHull::build(v4, array, numPoints, v5);
  numPoints = 0;
  if ( v64 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v64);
  return v59;
}

// File Line: 240
// RVA: 0xCA9A40
__int64 __fastcall hkgpConvexHull::buildFromPlanes(
        hkgpConvexHull *this,
        hkVector4f *planes,
        int numPlanes,
        hkVector4f *projectionPlane,
        hkgpConvexHull::BuildConfig *config)
{
  hkgpConvexHull *v5; // r15
  hkVector4f *v6; // r14
  __int64 v7; // rbx
  _QWORD *Value; // r10
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  int v13; // r9d
  __m128 v14; // xmm7
  const float *v15; // rsi
  __int64 v16; // rdi
  hkVector4f *v17; // r15
  __m128 m_quad; // xmm0
  const float *m_vertices; // r12
  const float *v20; // rbx
  __m128 *p_m_quad; // r12
  __m128 *v22; // r14
  __m128 v23; // xmm1
  __m128 v24; // xmm7
  __m128 v25; // xmm2
  hkVector4f v26; // xmm4
  const float *v27; // rax
  hkVector4f *v28; // rcx
  __m128 v29; // xmm6
  __m128 v30; // xmm2
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  int v33; // ecx
  _QWORD *v34; // rax
  _QWORD *v35; // rcx
  _QWORD *v36; // r8
  unsigned __int64 v37; // rax
  _QWORD *v38; // rcx
  unsigned int v39; // ebx
  hkStridedVertices sizeElem; // [rsp+20h] [rbp-71h] BYREF
  float *array; // [rsp+30h] [rbp-61h] BYREF
  int v43; // [rsp+38h] [rbp-59h]
  int v44; // [rsp+3Ch] [rbp-55h]
  hkMatrix3f v45; // [rsp+40h] [rbp-51h] BYREF
  hkgpConvexHull *vars0; // [rsp+F0h] [rbp+5Fh]
  hkgpConvexHull *result; // [rsp+100h] [rbp+6Fh] BYREF
  hkVector4f *v48; // [rsp+108h] [rbp+77h]
  hkgpConvexHull::BuildConfig *v49; // [rsp+110h] [rbp+7Fh]
  hkVector4f *v50; // [rsp+118h] [rbp+87h]

  v50 = projectionPlane;
  result = this;
  v5 = this;
  v6 = projectionPlane;
  v7 = numPlanes;
  array = 0i64;
  v43 = 0;
  v44 = 0x80000000;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtVertexEnumeration";
    v11 = __rdtsc();
    v12 = v10 + 2;
    *((_DWORD *)v12 - 2) = v11;
    Value[1] = v12;
  }
  v13 = 3 * v7;
  v14 = 0i64;
  if ( (v44 & 0x3FFFFFFF) < 3 * (int)v7 )
  {
    LODWORD(sizeElem.m_vertices) = 16;
    if ( v13 < 2 * (v44 & 0x3FFFFFFF) )
      v13 = 2 * (v44 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&array,
      v13,
      (int)sizeElem.m_vertices);
  }
  v15 = 0i64;
  v16 = v7;
  if ( (int)v7 > 0 )
  {
    v17 = planes;
    do
    {
      m_quad = v17->m_quad;
      m_vertices = (const float *)((char *)v15 + 1);
      sizeElem.m_vertices = (const float *)((char *)v15 + 1);
      v20 = (const float *)((char *)v15 + 1);
      v14.m128_f32[0] = 0.0 - _mm_shuffle_ps(m_quad, m_quad, 255).m128_f32[0];
      if ( (__int64)v15 + 1 < v16 )
      {
        p_m_quad = &v48->m_quad;
        v22 = &v17[1].m_quad;
        do
        {
          v23 = _mm_unpacklo_ps(v17->m_quad, *v22);
          v24 = _mm_shuffle_ps(
                  _mm_unpacklo_ps(v14, _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(*v22, *v22, 255))),
                  v14,
                  228);
          v25 = *p_m_quad;
          v26.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(v17->m_quad, *v22), *p_m_quad, 228);
          v45.m_col0.m_quad = _mm_movelh_ps(v23, *p_m_quad);
          v45.m_col1.m_quad = _mm_shuffle_ps(_mm_movehl_ps(v45.m_col0.m_quad, v23), v25, 212);
          v45.m_col2 = (hkVector4f)v26.m_quad;
          v14 = _mm_shuffle_ps(v24, _mm_unpackhi_ps(v24, _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v25, v25, 255))), 180);
          if ( hkMatrix3f::invert(&v45, (hkResult *)&result, 0.00000011920929)->m_enum == HK_SUCCESS )
          {
            v27 = 0i64;
            v28 = planes;
            v29 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v45.m_col1.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v45.m_col0.m_quad)),
                    _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v45.m_col2.m_quad));
            while ( 1 )
            {
              if ( v27 != v15 && v27 != v20 )
              {
                v30 = _mm_mul_ps(v29, v28->m_quad);
                v31 = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, v28->m_quad), 196);
                v32 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 78), v31);
                if ( (float)(_mm_shuffle_ps(v32, v32, 177).m128_f32[0] + v32.m128_f32[0]) > 0.00000011920929 )
                  break;
              }
              v27 = (const float *)((char *)v27 + 1);
              ++v28;
              if ( (__int64)v27 >= v16 )
              {
                v33 = v43;
                if ( v43 == (v44 & 0x3FFFFFFF) )
                {
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
                  v33 = v43;
                }
                *(__m128 *)&array[4 * v33] = v29;
                ++v43;
                break;
              }
            }
          }
          v20 = (const float *)((char *)v20 + 1);
          ++v22;
        }
        while ( (__int64)v20 < v16 );
        m_vertices = sizeElem.m_vertices;
      }
      ++v17;
      v15 = m_vertices;
    }
    while ( (__int64)m_vertices < v16 );
    v6 = v48;
    v5 = vars0;
  }
  v34 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v35 = (_QWORD *)v34[1];
  v36 = v34;
  if ( (unsigned __int64)v35 < v34[3] )
  {
    *v35 = "Et";
    v37 = __rdtsc();
    v38 = v35 + 2;
    *((_DWORD *)v38 - 2) = v37;
    v36[1] = v38;
  }
  if ( v43 < 3 )
  {
    v39 = -1;
  }
  else
  {
    sizeElem.m_numVertices = v43;
    sizeElem.m_vertices = array;
    sizeElem.m_striding = 16;
    v39 = hkgpConvexHull::buildPlanar(v5, &sizeElem, v6, v49);
  }
  v43 = 0;
  if ( v44 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v44);
  return v39;
}

// File Line: 282
// RVA: 0xCA9DD0
hkResult *__fastcall hkgpConvexHull::simplify(
        hkgpConvexHull *this,
        hkResult *result,
        hkgpConvexHull::SimplifyConfig *config)
{
  hkgpConvexHullImpl::simplify(this->m_data, result, config);
  return result;
}

// File Line: 287
// RVA: 0xCA9E00
hkBool *__fastcall hkgpConvexHull::ensureContainment(
        hkgpConvexHull *this,
        hkBool *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *points)
{
  hkgpConvexHullImpl::ensureContainment(this->m_data, result, points);
  return result;
}

// File Line: 292
// RVA: 0xCA9E30
hkBool *__fastcall hkgpConvexHull::decimateVertices(
        hkgpConvexHull *this,
        hkBool *result,
        int numVerticesToKeep,
        hkBool bEnsureContainment,
        hkBool useCgo)
{
  result->m_bool = hkgpConvexHullImpl::decimateVertices(
                     this->m_data,
                     numVerticesToKeep,
                     bEnsureContainment.m_bool != 0,
                     useCgo.m_bool != 0);
  return result;
}

// File Line: 297
// RVA: 0xCA9E70
// local variable allocation has failed, the output may be wrong!
hkBool *__fastcall hkgpConvexHull::expandByPlanarMargin(hkgpConvexHull *this, hkBool *result, float margin, double a4)
{
  hkgpConvexHullImpl *m_data; // rsi
  __m128 v5; // xmm7
  __m128 v8; // xmm10
  int Dimensions; // eax
  int v10; // eax
  int v11; // eax
  int v12; // ebx
  int v13; // r9d
  __m128 v14; // xmm7
  hkgpConvexHull::Triangle *FirstTriangle; // rsi
  __m128 v16; // xmm1
  __m128 v17; // xmm6
  hkgpConvexHull::Vertex *Vertex; // rax
  hkVector4f *SourcePosition; // rax
  int m_size; // edx
  __m128 v21; // xmm10
  __m128 v22; // xmm9
  int v23; // r9d
  __m128 v24; // xmm7
  hkgpConvexHull::Vertex *FirstVertex; // rsi
  __m128 v26; // xmm8
  __m128 v27; // xmm6
  hkVector4f *v28; // rax
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // eax
  hkBool *v33; // rsi
  const float *m_vertices; // rdx
  __m128 v36; // xmm12
  __m128 v37; // xmm11
  __m128 v38; // xmm7
  __m128 v39; // xmm5
  __m128 v40; // xmm4
  __m128 v41; // xmm5
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm6
  __m128 v45; // xmm6
  __m128 v46; // xmm1
  __m128 v47; // xmm3
  __m128 v48; // xmm2
  __m128 v49; // xmm8
  __m128 v50; // xmm8
  int m_numVertices; // ecx
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
  int m_capacityAndFlags; // r8d
  hkVector4f *v66; // rdx
  __m128 m_quad; // xmm6
  __m128 v68; // xmm2
  hkStridedVertices points; // [rsp+30h] [rbp-B0h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> array; // [rsp+40h] [rbp-A0h] BYREF
  hkgpConvexHull::BuildConfig config; // [rsp+50h] [rbp-90h] BYREF
  hkResult v72; // [rsp+60h] [rbp-80h] BYREF
  hkResult resulta; // [rsp+64h] [rbp-7Ch] BYREF
  hkResult v74; // [rsp+68h] [rbp-78h] BYREF
  hkErrStream buf; // [rsp+70h] [rbp-70h] BYREF
  hkResult v76; // [rsp+310h] [rbp+230h] BYREF
  hkBool *v77; // [rsp+318h] [rbp+238h]
  unsigned int vars0; // [rsp+320h] [rbp+240h]
  void *retaddr; // [rsp+328h] [rbp+248h]

  m_data = this->m_data;
  v5 = (__m128)vars0;
  config = m_data->m_config;
  v8 = _mm_mul_ps(_mm_shuffle_ps(v5, v5, 0), (__m128)xmmword_141A711B0);
  LOBYTE(v76.m_enum) = m_data->m_hasIndexing;
  LOBYTE(retaddr) = m_data->m_hasMassProperties;
  Dimensions = hkgpConvexHull::getDimensions(this);
  if ( !Dimensions )
  {
    array.m_capacityAndFlags = 0x80000000;
    array.m_data = 0i64;
    array.m_size = 0;
    m_quad = m_data->m_mesh.m_vertices.m_used->m_source.m_quad;
    hkArrayUtil::_reserve((hkResult *)&points, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 6, 16);
    v68 = _mm_sub_ps((__m128)0i64, v8);
    array.m_size = 6;
    *array.m_data = (hkVector4f)_mm_add_ps(_mm_mul_ps(v8, transform.m_quad), m_quad);
    array.m_data[1].m_quad = _mm_add_ps(_mm_mul_ps(v68, transform.m_quad), m_quad);
    array.m_data[2].m_quad = _mm_add_ps(_mm_mul_ps(v8, direction.m_quad), m_quad);
    array.m_data[3].m_quad = _mm_add_ps(_mm_mul_ps(v68, direction.m_quad), m_quad);
    array.m_data[4].m_quad = _mm_add_ps(_mm_mul_ps(v8, stru_141A71280.m_quad), m_quad);
    array.m_data[5].m_quad = _mm_add_ps(_mm_mul_ps(v68, stru_141A71280.m_quad), m_quad);
LABEL_57:
    points.m_vertices = array.m_data->m_quad.m128_f32;
    points.m_numVertices = array.m_size;
    points.m_striding = 16;
    hkgpConvexHull::build(this, &points, &config);
    array.m_size = 0;
LABEL_58:
    m_capacityAndFlags = array.m_capacityAndFlags;
    if ( array.m_capacityAndFlags < 0 )
    {
LABEL_61:
      result = v77;
LABEL_62:
      if ( hkgpConvexHull::getDimensions(this) == 3 )
      {
        if ( LOBYTE(v76.m_enum) )
          hkgpConvexHull::buildIndices(this, 0.99998999, 0);
        if ( (_BYTE)retaddr )
          hkgpConvexHull::buildMassProperties(this, &v76);
        result->m_bool = 1;
      }
      else
      {
        result->m_bool = 0;
      }
      return result;
    }
    v66 = array.m_data;
LABEL_60:
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v66, 16 * m_capacityAndFlags);
    goto LABEL_61;
  }
  v10 = Dimensions - 1;
  if ( !v10 )
  {
    points.m_vertices = 0i64;
    points.m_numVertices = 0;
    points.m_striding = 0x80000000;
    hkArrayUtil::_reserve(&v74, &hkContainerHeapAllocator::s_alloc, (const void **)&points.m_vertices, 10, 16);
    hkgpConvexHull::fetchPositions(this, SOURCE_VERTICES, (hkArray<hkVector4f,hkContainerHeapAllocator> *)&points);
    m_vertices = points.m_vertices;
    v36 = *(__m128 *)(points.m_vertices + 4);
    v37 = *(__m128 *)points.m_vertices;
    v38 = _mm_sub_ps(v36, *(__m128 *)points.m_vertices);
    v39 = _mm_shuffle_ps(v38, _mm_unpackhi_ps(v38, (__m128)0i64), 196);
    v40 = _mm_shuffle_ps(v39, v39, 241);
    v41 = _mm_shuffle_ps(v39, v39, 206);
    v42 = _mm_mul_ps(v40, v40);
    v43 = _mm_mul_ps(v41, v41);
    v44 = _mm_cmplt_ps(
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
    m_numVertices = points.m_numVertices;
    v52 = _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmple_ps(v47, (__m128)0i64),
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
                _mm_cmple_ps(v54, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v56, v54), v56)),
                  _mm_mul_ps(v56, *(__m128 *)_xmm))),
              v50),
            v8);
    if ( points.m_numVertices == (points.m_striding & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&points.m_vertices, 16);
      m_numVertices = points.m_numVertices;
      m_vertices = points.m_vertices;
    }
    points.m_numVertices = m_numVertices + 1;
    *(__m128 *)&m_vertices[4 * m_numVertices] = _mm_add_ps(v55, v37);
    v58 = points.m_numVertices;
    if ( points.m_numVertices == (points.m_striding & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&points.m_vertices, 16);
      v58 = points.m_numVertices;
    }
    points.m_numVertices = v58 + 1;
    *(__m128 *)&points.m_vertices[4 * v58] = _mm_sub_ps(v37, v55);
    v59 = points.m_numVertices;
    if ( points.m_numVertices == (points.m_striding & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&points.m_vertices, 16);
      v59 = points.m_numVertices;
    }
    points.m_numVertices = v59 + 1;
    *(__m128 *)&points.m_vertices[4 * v59] = _mm_add_ps(v57, v37);
    v60 = points.m_numVertices;
    if ( points.m_numVertices == (points.m_striding & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&points.m_vertices, 16);
      v60 = points.m_numVertices;
    }
    points.m_numVertices = v60 + 1;
    *(__m128 *)&points.m_vertices[4 * v60] = _mm_sub_ps(v37, v57);
    v61 = points.m_numVertices;
    if ( points.m_numVertices == (points.m_striding & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&points.m_vertices, 16);
      v61 = points.m_numVertices;
    }
    points.m_numVertices = v61 + 1;
    *(__m128 *)&points.m_vertices[4 * v61] = _mm_add_ps(v55, v36);
    v62 = points.m_numVertices;
    if ( points.m_numVertices == (points.m_striding & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&points.m_vertices, 16);
      v62 = points.m_numVertices;
    }
    points.m_numVertices = v62 + 1;
    *(__m128 *)&points.m_vertices[4 * v62] = _mm_sub_ps(v36, v55);
    v63 = points.m_numVertices;
    if ( points.m_numVertices == (points.m_striding & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&points.m_vertices, 16);
      v63 = points.m_numVertices;
    }
    points.m_numVertices = v63 + 1;
    *(__m128 *)&points.m_vertices[4 * v63] = _mm_add_ps(v57, v36);
    v64 = points.m_numVertices;
    if ( points.m_numVertices == (points.m_striding & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&points.m_vertices, 16);
      v64 = points.m_numVertices;
    }
    points.m_numVertices = v64 + 1;
    array.m_capacityAndFlags = 16;
    *(__m128 *)&points.m_vertices[4 * v64] = _mm_sub_ps(v36, v57);
    array.m_data = (hkVector4f *)points.m_vertices;
    array.m_size = points.m_numVertices;
    hkgpConvexHull::build(this, (hkStridedVertices *)&array, &config);
    m_capacityAndFlags = points.m_striding;
    points.m_numVertices = 0;
    if ( points.m_striding < 0 )
      goto LABEL_61;
    v66 = (hkVector4f *)points.m_vertices;
    goto LABEL_60;
  }
  v11 = v10 - 1;
  if ( v11 )
  {
    if ( v11 != 1 )
    {
      hkErrStream::hkErrStream(&buf, (char *)&buf, 512);
      hkOstream::operator<<(&buf, "Invalid dimemsions for that operation");
      if ( (unsigned int)hkError::messageError(
                           0x172CDF48u,
                           (const char *)&buf,
                           "GeometryProcessing\\ConvexHull\\hkgpConvexHull.cpp",
                           399) )
        __debugbreak();
      hkOstream::~hkOstream(&buf);
      goto LABEL_62;
    }
    v12 = 0;
    array.m_capacityAndFlags = 0x80000000;
    array.m_data = 0i64;
    array.m_size = 0;
    v13 = 6 * hkgpConvexHull::getNumTriangles(this);
    if ( v13 <= 0 )
      resulta.m_enum = HK_SUCCESS;
    else
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, v13, 16);
    hkgpConvexHull::fetchPositions(this, SOURCE_VERTICES, &array);
    v14 = _mm_shuffle_ps(v5, v5, 0);
    FirstTriangle = hkgpConvexHull::getFirstTriangle(this);
    if ( FirstTriangle )
    {
      *(float *)&points.m_vertices = FLOAT_0_000099999997;
      do
      {
        hkgpConvexHull::getPlaneEquation(this, (hkVector4f *)&buf, FirstTriangle);
        if ( (_mm_movemask_ps(_mm_cmpunord_ps((__m128)buf.hkReferencedObject, (__m128)buf.hkReferencedObject)) & 7) == 0 )
        {
          *(float *)&a4 = 0.000099999997;
          v16 = _mm_mul_ps((__m128)buf.hkReferencedObject, (__m128)buf.hkReferencedObject);
          *(__m128 *)&a4 = _mm_shuffle_ps(*(__m128 *)&a4, *(__m128 *)&a4, 0);
          if ( COERCE_FLOAT((unsigned int)(2
                                         * COERCE_INT(
                                             (float)((float)(_mm_shuffle_ps(v16, v16, 85).m128_f32[0]
                                                           + _mm_shuffle_ps(v16, v16, 0).m128_f32[0])
                                                   + _mm_shuffle_ps(v16, v16, 170).m128_f32[0])
                                           - 1.0)) >> 1) < *(float *)&a4 )
          {
            v17 = _mm_mul_ps((__m128)buf.hkReferencedObject, v14);
            do
            {
              Vertex = hkgpConvexHull::getVertex(this, FirstTriangle, v12);
              SourcePosition = hkgpConvexHull::getSourcePosition(this, Vertex);
              m_size = array.m_size;
              points.m_vertices = (const float *)SourcePosition;
              if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 16);
                m_size = array.m_size;
                SourcePosition = (hkVector4f *)points.m_vertices;
              }
              array.m_size = m_size + 1;
              ++v12;
              array.m_data[m_size].m_quad = _mm_add_ps(v17, SourcePosition->m_quad);
            }
            while ( v12 < 3 );
            v12 = 0;
          }
        }
        FirstTriangle = hkgpConvexHull::getNext(this, FirstTriangle);
      }
      while ( FirstTriangle );
    }
    goto LABEL_57;
  }
  array.m_capacityAndFlags = 0x80000000;
  array.m_data = 0i64;
  array.m_size = 0;
  v21 = hkgpConvexHull::getCentroid(this)->m_quad;
  v22 = hkgpConvexHull::getProjectionPlane(this)->m_quad;
  v23 = 3 * hkgpConvexHull::getNumVertices(this);
  if ( v23 <= 0 )
    v72.m_enum = HK_SUCCESS;
  else
    hkArrayUtil::_reserve(&v72, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, v23, 16);
  hkgpConvexHull::fetchPositions(this, SOURCE_VERTICES, &array);
  v24 = _mm_shuffle_ps(v5, v5, 0);
  FirstVertex = hkgpConvexHull::getFirstVertex(this);
  if ( FirstVertex )
  {
    v26 = _mm_mul_ps(v22, v24);
    v27 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, v24), v22);
    do
    {
      v28 = hkgpConvexHull::getSourcePosition(this, FirstVertex);
      v29 = array.m_size;
      points.m_vertices = (const float *)v28;
      if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 16);
        v29 = array.m_size;
        v28 = (hkVector4f *)points.m_vertices;
      }
      array.m_size = v29 + 1;
      array.m_data[v29].m_quad = _mm_add_ps(v28->m_quad, v26);
      v30 = array.m_size;
      if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 16);
        v30 = array.m_size;
      }
      array.m_size = v30 + 1;
      array.m_data[v30].m_quad = _mm_add_ps(*(__m128 *)points.m_vertices, v27);
      FirstVertex = hkgpConvexHull::getNext(this, FirstVertex);
    }
    while ( FirstVertex );
  }
  points.m_vertices = array.m_data->m_quad.m128_f32;
  points.m_numVertices = array.m_size;
  points.m_striding = 16;
  v31 = hkgpConvexHull::build(this, &points, &config);
  array.m_size = 0;
  if ( v31 == 3 )
    goto LABEL_58;
  v32 = 0;
  if ( (array.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 16);
    v32 = array.m_size;
  }
  points.m_striding = 16;
  array.m_data[v32].m_quad = v21;
  points.m_vertices = array.m_data->m_quad.m128_f32;
  points.m_numVertices = ++array.m_size;
  hkgpConvexHull::build(this, &points, &config);
  v33 = v77;
  hkgpConvexHull::expandByPlanarMargin(this, v77, margin);
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      16 * array.m_capacityAndFlags);
  return v33;
}apAllocator::s_alloc,
      array.m_data,
      16 * array.m_capacityAndFlags);
  return v33;
}

// File Line: 448
// RVA: 0xCAF8B0
void __fastcall anonymous_namespace_::_calcSideInfo_1_4_(
        hkgpConvexHull *hull,
        hkgpConvexHull::Triangle *triangle,
        hkMxVector<4> *sides,
        hkVector4f *edgeMask,
        VertexInfo *vertexInfos)
{
  hkgpConvexHull::Vertex *SourcePosition; // rbx
  __m128 *v10; // rax
  __m128 v11; // xmm0
  __int64 v12; // rbx
  int PlaneIndex; // eax
  __int64 v14; // rdi
  int v15; // ebp
  VertexInfo *v16; // rdi
  __int64 m_numPlanes; // rdx
  int v18; // esi
  hkVector4f *v19; // rbx
  hkVector4f *v20; // rax
  __m128 m_quad; // xmm7
  int v22; // ebx
  __m128 v23; // xmm7
  __m128 v24; // xmm7
  __m128i v25; // xmm1
  __m128i v26; // xmm0
  __m128i v27; // xmm6
  hkVector4f *v28; // rbx
  int v29; // esi
  hkVector4f *v30; // rax
  __m128 v31; // xmm0
  int v32; // ebx
  __m128 v33; // xmm7
  __m128 v34; // xmm7
  __m128i v35; // xmm1
  __m128i v36; // xmm0
  __m128i v37; // xmm6
  int v38; // esi
  hkVector4f *v39; // rbx
  int v40; // r15d
  hkVector4f *v41; // rax
  __m128 v42; // xmm6
  __m128 v43; // xmm6
  __m128i v44; // xmm1
  __m128i v45; // xmm0
  hkVector4f *Plane; // rbx
  hkVector4f *v47; // rax
  __m128 v48; // xmm6
  __m128 v49; // xmm6
  __m128i v50; // xmm1
  __m128i v51; // [rsp+20h] [rbp-68h]
  __m128i v52; // [rsp+20h] [rbp-68h]
  __m128i v53; // [rsp+20h] [rbp-68h]

  SourcePosition = hkgpConvexHull::getSourcePosition(hull, *(hkgpConvexHull::Vertex **)&triangle[32]);
  v10 = (__m128 *)hkgpConvexHull::getSourcePosition(hull, *(hkgpConvexHull::Vertex **)&triangle[24]);
  v11 = *(__m128 *)SourcePosition;
  v12 = *(_QWORD *)&triangle[48];
  sides->m_vec.v[1].m_quad = _mm_sub_ps(v11, *v10);
  PlaneIndex = hkgpConvexHull::getPlaneIndex(hull, triangle);
  v14 = *(int *)(*(_QWORD *)&triangle[24] + 52i64);
  v15 = PlaneIndex;
  if ( (unsigned int)hkgpConvexHull::getPlaneIndex(hull, (hkgpConvexHull::Triangle *)(v12 & 0xFFFFFFFFFFFFFFFCui64)) != PlaneIndex )
    edgeMask->m_quad = _mm_shuffle_ps(_mm_unpacklo_ps(edgeMask->m_quad, query.m_quad), edgeMask->m_quad, 228);
  v16 = &vertexInfos[v14];
  m_numPlanes = v16->m_numPlanes;
  switch ( (_DWORD)m_numPlanes )
  {
    case 0:
      goto LABEL_20;
    case 1:
      if ( v16->m_planeIndices[0] == v15 )
        return;
LABEL_20:
      v16->m_planeIndices[m_numPlanes] = v15;
      ++v16->m_numPlanes;
      return;
    case 2:
      if ( v16->m_planeIndices[0] != v15 && v16->m_planeIndices[1] != v15 )
      {
        v16->m_planeIndices[2] = v15;
        ++v16->m_numPlanes;
        Plane = hkgpConvexHull::getPlane(hull, v16->m_planeIndices[1]);
        v47 = hkgpConvexHull::getPlane(hull, v16->m_planeIndices[0]);
        v48 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(Plane->m_quad, Plane->m_quad, 201), v47->m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v47->m_quad, v47->m_quad, 201), Plane->m_quad));
        v49 = _mm_mul_ps(_mm_shuffle_ps(v48, v48, 201), hkgpConvexHull::getPlane(hull, v16->m_planeIndices[2])->m_quad);
        v50 = (__m128i)_mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)),
                         _mm_shuffle_ps(v49, v49, 170));
        v16->m_determinant = (hkSimdFloat32)v50;
        v16->m_absDeterminant = (hkSimdFloat32)_mm_srli_epi32(_mm_slli_epi32(v50, 1u), 1u);
      }
      break;
    default:
      if ( v16->m_planeIndices[0] != v15 && v16->m_planeIndices[1] != v15 && v16->m_planeIndices[2] != v15 )
      {
        v18 = _mm_cvtsi128_si32(_mm_srli_si128(*(__m128i *)&v16->m_numPlanes, 8));
        v51 = *(__m128i *)&v16->m_numPlanes;
        v19 = hkgpConvexHull::getPlane(hull, v18);
        v20 = hkgpConvexHull::getPlane(hull, v15);
        m_quad = v19->m_quad;
        v22 = _mm_cvtsi128_si32(_mm_srli_si128(v51, 12));
        v23 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v20->m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v20->m_quad, v20->m_quad, 201), m_quad));
        v24 = _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), hkgpConvexHull::getPlane(hull, v22)->m_quad);
        v25 = (__m128i)_mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                         _mm_shuffle_ps(v24, v24, 170));
        v26 = _mm_srli_epi32(_mm_slli_epi32(v25, 1u), 1u);
        if ( *(float *)v26.m128i_i32 > v16->m_absDeterminant.m_real.m128_f32[0] )
        {
          v16->m_numPlanes = v51.m128i_i32[0];
          v16->m_planeIndices[0] = v15;
          v16->m_planeIndices[1] = v18;
          v16->m_planeIndices[2] = v22;
          v16->m_determinant = (hkSimdFloat32)v25;
          v16->m_absDeterminant = (hkSimdFloat32)v26;
        }
        v27 = *(__m128i *)&v16->m_numPlanes;
        v52 = *(__m128i *)&v16->m_numPlanes;
        v28 = hkgpConvexHull::getPlane(hull, v15);
        v29 = _mm_cvtsi128_si32(_mm_srli_si128(v27, 4));
        v30 = hkgpConvexHull::getPlane(hull, v29);
        v31 = v28->m_quad;
        v32 = _mm_cvtsi128_si32(_mm_srli_si128(v27, 12));
        v33 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v30->m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v30->m_quad, v30->m_quad, 201), v31));
        v34 = _mm_mul_ps(_mm_shuffle_ps(v33, v33, 201), hkgpConvexHull::getPlane(hull, v32)->m_quad);
        v35 = (__m128i)_mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                         _mm_shuffle_ps(v34, v34, 170));
        v36 = _mm_srli_epi32(_mm_slli_epi32(v35, 1u), 1u);
        if ( *(float *)v36.m128i_i32 > v16->m_absDeterminant.m_real.m128_f32[0] )
        {
          v16->m_numPlanes = v52.m128i_i32[0];
          v16->m_planeIndices[0] = v29;
          v16->m_planeIndices[1] = v15;
          v16->m_planeIndices[2] = v32;
          v16->m_determinant = (hkSimdFloat32)v35;
          v16->m_absDeterminant = (hkSimdFloat32)v36;
        }
        v37 = *(__m128i *)&v16->m_numPlanes;
        v53 = *(__m128i *)&v16->m_numPlanes;
        v38 = _mm_cvtsi128_si32(_mm_srli_si128(*(__m128i *)&v16->m_numPlanes, 8));
        v39 = hkgpConvexHull::getPlane(hull, v38);
        v40 = _mm_cvtsi128_si32(_mm_srli_si128(v37, 4));
        v41 = hkgpConvexHull::getPlane(hull, v40);
        v42 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v39->m_quad, v39->m_quad, 201), v41->m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v41->m_quad, v41->m_quad, 201), v39->m_quad));
        v43 = _mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), hkgpConvexHull::getPlane(hull, v15)->m_quad);
        v44 = (__m128i)_mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                         _mm_shuffle_ps(v43, v43, 170));
        v45 = _mm_srli_epi32(_mm_slli_epi32(v44, 1u), 1u);
        if ( *(float *)v45.m128i_i32 > v16->m_absDeterminant.m_real.m128_f32[0] )
        {
          v16->m_numPlanes = v53.m128i_i32[0];
          v16->m_planeIndices[0] = v40;
          v16->m_planeIndices[1] = v38;
          v16->m_planeIndices[2] = v15;
          v16->m_determinant = (hkSimdFloat32)v44;
          v16->m_absDeterminant = (hkSimdFloat32)v45;
        }
      }
      break;
  }
}

// File Line: 511
// RVA: 0xCAA950
float __fastcall hkgpConvexHull::absoluteScale(
        hkgpConvexHull *this,
        const float offset,
        hkgpConvexHull::AbsoluteScaleConfig *config)
{
  hkgpConvexHullImpl *m_data; // rsi
  hkOstream *v6; // rax
  hkOstream *v7; // rax
  hkVector4f *CenterOfMass; // rax
  __m128 m_quad; // xmm8
  __m128 v10; // xmm7
  __m128i v11; // xmm10
  __m128 v12; // xmm9
  __m128 m_featurePreservationFactor_low; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm15
  __m128 v16; // xmm1
  __m128 v17; // xmm12
  int v18; // ebx
  int NumPlanes; // esi
  hkVector4f *Plane; // rax
  int v21; // eax
  int v22; // esi
  __m128 v23; // xmm6
  int v24; // eax
  int v25; // edx
  int v26; // ebx
  hkLifoAllocator *Value; // rax
  hkVector4f *m_cur; // r8
  int v29; // edx
  char *v30; // rcx
  hkVector4f *v31; // rax
  hkVector4f *v32; // r15
  int v33; // r9d
  int v34; // eax
  hkVector4f *v35; // rcx
  __int64 v36; // rdx
  __m128 v37; // xmm9
  hkgpConvexHull::Triangle *FirstTriangle; // r14
  hkStridedVertices v39; // xmm10
  float v40; // xmm15_4
  hkVector4f *v41; // r12
  __m128 v42; // xmm8
  hkVector4f *v43; // rbx
  hkVector4f *v44; // rax
  __m128 v45; // xmm14
  __int64 v46; // rbx
  __m128 v47; // xmm14
  int PlaneIndex; // eax
  __int64 v49; // rsi
  int v50; // r15d
  hkVector4f *v51; // rsi
  __int64 v52; // rdx
  __m128i v53; // xmm6
  __int128 v54; // xmm1
  int v55; // r12d
  hkVector4f *v56; // rbx
  hkVector4f *v57; // rax
  __m128 v58; // xmm0
  int v59; // ebx
  __m128 v60; // xmm7
  __m128 v61; // xmm7
  __m128i v62; // xmm1
  __m128i v63; // xmm0
  __m128i v64; // xmm6
  __int128 v65; // xmm0
  __int128 v66; // xmm1
  hkVector4f *v67; // rbx
  int v68; // r12d
  hkVector4f *v69; // rax
  __m128 v70; // xmm0
  int v71; // ebx
  __m128 v72; // xmm7
  __m128 v73; // xmm7
  __m128i v74; // xmm1
  __m128i v75; // xmm0
  __m128i v76; // xmm6
  __int128 v77; // xmm1
  int v78; // r12d
  hkVector4f *v79; // rbx
  int v80; // r13d
  hkVector4f *v81; // rax
  __m128 v82; // xmm6
  __m128 v83; // xmm6
  __m128i v84; // xmm1
  __m128i v85; // xmm0
  hkVector4f *v86; // rbx
  hkVector4f *v87; // rax
  __m128 v88; // xmm6
  __m128 v89; // xmm6
  __m128i v90; // xmm1
  hkVector4f *v91; // r12
  hkVector4f *v92; // rbx
  hkVector4f *v93; // rax
  __m128 v94; // xmm13
  __int64 v95; // rbx
  __m128 v96; // xmm13
  int v97; // eax
  __int64 v98; // rsi
  int v99; // r15d
  hkVector4f *v100; // rsi
  __int64 v101; // rdx
  __m128i v102; // xmm6
  __int128 v103; // xmm1
  int v104; // r12d
  hkVector4f *v105; // rbx
  hkVector4f *v106; // rax
  __m128 v107; // xmm0
  int v108; // ebx
  __m128 v109; // xmm7
  __m128 v110; // xmm7
  __m128i v111; // xmm1
  __m128i v112; // xmm0
  __m128i v113; // xmm6
  __int128 v114; // xmm0
  __int128 v115; // xmm1
  hkVector4f *v116; // rbx
  int v117; // r12d
  hkVector4f *v118; // rax
  __m128 v119; // xmm0
  int v120; // ebx
  __m128 v121; // xmm7
  __m128 v122; // xmm7
  __m128i v123; // xmm1
  __m128i v124; // xmm0
  __m128i v125; // xmm6
  __int128 v126; // xmm1
  int v127; // r12d
  hkVector4f *v128; // rbx
  int v129; // r13d
  hkVector4f *v130; // rax
  __m128 v131; // xmm6
  __m128 v132; // xmm6
  __m128i v133; // xmm1
  __m128i v134; // xmm0
  hkVector4f *v135; // rbx
  hkVector4f *v136; // rax
  __m128 v137; // xmm6
  __m128 v138; // xmm6
  __m128i v139; // xmm1
  hkVector4f *v140; // r12
  hkVector4f *v141; // rbx
  hkVector4f *v142; // rax
  __m128 v143; // xmm12
  __int64 v144; // rbx
  __m128 v145; // xmm12
  int v146; // eax
  __int64 v147; // rsi
  int v148; // r15d
  hkVector4f *v149; // rsi
  __int64 v150; // rdx
  __m128i v151; // xmm6
  __int128 v152; // xmm1
  int v153; // r12d
  hkVector4f *v154; // rbx
  hkVector4f *v155; // rax
  __m128 v156; // xmm0
  int v157; // ebx
  __m128 v158; // xmm7
  __m128 v159; // xmm7
  __m128i v160; // xmm1
  __m128i v161; // xmm0
  __m128i v162; // xmm6
  __int128 v163; // xmm0
  __int128 v164; // xmm1
  hkVector4f *v165; // rbx
  int v166; // r12d
  hkVector4f *v167; // rax
  __m128 v168; // xmm7
  int v169; // ebx
  __m128 v170; // xmm7
  __m128 v171; // xmm7
  __m128i v172; // xmm1
  __m128i v173; // xmm0
  __m128i v174; // xmm6
  __int128 v175; // xmm1
  int v176; // r12d
  hkVector4f *v177; // rbx
  int v178; // r13d
  hkVector4f *v179; // rax
  __m128 v180; // xmm6
  __m128 v181; // xmm6
  __m128i v182; // xmm1
  __m128i v183; // xmm0
  hkVector4f *v184; // rbx
  hkVector4f *v185; // rax
  __m128 v186; // xmm6
  __m128 v187; // xmm6
  __m128i v188; // xmm1
  int v189; // ecx
  __m128 v190; // xmm14
  __m128 v191; // xmm13
  __m128 v192; // xmm12
  __m128 v193; // xmm1
  float v194; // xmm4_4
  __m128 v195; // xmm1
  __m128 v196; // xmm3
  __m128 v197; // xmm1
  __m128 v198; // xmm0
  __m128 v199; // xmm5
  __m128 v200; // xmm5
  __m128 v201; // xmm3
  __m128 v202; // xmm0
  __m128 v203; // xmm1
  __m128 v204; // xmm2
  __m128 v205; // xmm4
  __m128 v206; // xmm0
  int v207; // ecx
  int v208; // ecx
  __m128 v209; // xmm0
  __m128 v210; // xmm5
  __m128 v211; // xmm5
  __m128 v212; // xmm1
  __m128 v213; // xmm2
  __m128 v214; // xmm2
  __m128 v215; // xmm10
  __m128 v216; // xmm8
  hkgpConvexHull::Vertex *Next; // rsi
  int v218; // eax
  hkVector4f v219; // xmm0
  __m128 v220; // xmm14
  hkVector4f v221; // xmm6
  unsigned __int64 v222; // rax
  __m128 v223; // xmm13
  __m128 v224; // xmm9
  __m128 v225; // xmm12
  hkVector4f *v226; // rax
  __m128 v227; // xmm4
  __m128 v228; // xmm3
  __m128 v229; // xmm1
  __m128 v230; // xmm6
  __m128 v231; // xmm3
  __m128 v232; // xmm3
  __m128 v233; // xmm5
  __m128 v234; // xmm4
  __m128 v235; // xmm5
  __m128 v236; // xmm1
  __m128 v237; // xmm4
  __m128 v238; // xmm5
  __m128 v239; // xmm2
  __m128 v240; // xmm2
  __m128 v241; // xmm5
  __m128 v242; // xmm1
  __m128 v243; // xmm3
  __m128 v244; // xmm2
  __m128 v245; // xmm4
  __m128 v246; // xmm4
  __m128 v247; // xmm0
  __m128 v248; // xmm0
  __m128 v249; // xmm8
  __m128 v250; // xmm1
  signed int v251; // ebx
  hkLifoAllocator *v252; // rax
  int v253; // r8d
  signed int v254; // ebx
  hkLifoAllocator *v255; // rax
  int v256; // r8d
  int j; // ebx
  hkVector4f *v258; // rax
  __m128 v259; // xmm2
  __m128 v260; // xmm2
  __m128 v261; // xmm0
  int v262; // eax
  int v263; // ebx
  hkLifoAllocator *v264; // rcx
  hkVector4f *v265; // rax
  int v266; // edx
  char *v267; // r8
  int v268; // ebx
  int v269; // r14d
  hkVector4f *v270; // rax
  int v271; // ecx
  __m128 v272; // xmm1
  __m128 v273; // xmm1
  __m128 v274; // xmm0
  __m128 v275; // xmm6
  int v276; // esi
  hkgpConvexHull::BuildConfig *v277; // rbx
  hkVector4f *v278; // rax
  hkgpConvexHull::BuildConfig *v279; // rax
  int v280; // eax
  char *v281; // rsi
  signed int v282; // ebx
  hkLifoAllocator *v283; // rax
  int v284; // r8d
  int v285; // r8d
  hkVector4f *m_vertices; // rdx
  hkgpConvexHull::Vertex *i; // rbx
  __m128 v288; // xmm1
  __m128 v289; // xmm1
  __m128 v290; // xmm3
  __m128 v291; // xmm2
  __m128 v292; // xmm4
  int m_numVertices; // ebx
  int m_striding; // esi
  int NumVertices; // eax
  hkgpConvexHull::Vertex *FirstVertex; // r14
  hkVector4f *SourcePosition; // r15
  __m128 v298; // xmm5
  __m128 v299; // xmm1
  __m128 v300; // xmm3
  __m128 v301; // xmm2
  __m128 v302; // xmm4
  __m128 v303; // xmm6
  __m128 v304; // xmm6
  int Dimensions; // eax
  hkgpConvexHull::BuildConfig *Configuration; // rbx
  hkVector4f *ProjectionPlane; // rax
  hkgpConvexHull::BuildConfig *v308; // rax
  char v309; // si
  int v310; // ecx
  __m128 *v311; // rdx
  hkgpConvexHull::BuildConfig *v312; // rax
  hkgpConvexHull::BuildConfig *v313; // rax
  int v314; // eax
  int m_size; // r15d
  int v316; // ecx
  int v317; // r10d
  const float *v318; // r8
  int v319; // esi
  __m128i si128; // xmm9
  int v321; // r11d
  __int64 v322; // r14
  __m128 v323; // xmm4
  __m128i v324; // xmm5
  __m128i v325; // xmm6
  __int64 v326; // rdx
  const float *v327; // rax
  __m128 v328; // xmm1
  __m128 v329; // xmm1
  __m128 v330; // xmm3
  __m128i v331; // xmm2
  int v332; // ebx
  int v333; // edx
  __int64 v334; // rax
  int v335; // eax
  int v336; // r14d
  __int64 v337; // rax
  float *v338; // rsi
  int v339; // ebx
  int v340; // r10d
  __int64 v341; // rdx
  float *v342; // r9
  __int64 v343; // rcx
  hkgpConvexHull::BuildConfig *v344; // rax
  hkStridedVertices v346; // [rsp+30h] [rbp-C8h] BYREF
  hkStridedVertices points; // [rsp+40h] [rbp-B8h] BYREF
  hkVector4f *array; // [rsp+50h] [rbp-A8h] BYREF
  int v349; // [rsp+58h] [rbp-A0h]
  int v350; // [rsp+5Ch] [rbp-9Ch]
  void *p; // [rsp+60h] [rbp-98h]
  int v352; // [rsp+68h] [rbp-90h]
  hkArray<hkVector4f,hkContainerHeapAllocator> positions; // [rsp+70h] [rbp-88h] BYREF
  hkStridedVertices v354; // [rsp+88h] [rbp-70h] BYREF
  hkErrStream v355; // [rsp+98h] [rbp-60h] BYREF
  __m128 v356; // [rsp+B8h] [rbp-40h]
  __m128 v357; // [rsp+C8h] [rbp-30h]
  __m128 v358; // [rsp+D8h] [rbp-20h]
  int index[4]; // [rsp+E8h] [rbp-10h]
  hkVector4f v360; // [rsp+F8h] [rbp+0h]
  __int128 v361; // [rsp+108h] [rbp+10h]
  __m128 v362; // [rsp+118h] [rbp+20h]
  __m128 v363; // [rsp+128h] [rbp+30h]
  __m128 v364; // [rsp+138h] [rbp+40h]
  hkAabb aabbOut; // [rsp+148h] [rbp+50h] BYREF
  __m128i v366; // [rsp+168h] [rbp+70h]
  __int128 v367; // [rsp+178h] [rbp+80h]
  __int128 v368; // [rsp+188h] [rbp+90h]
  __m128i v369; // [rsp+198h] [rbp+A0h]
  hkVector4f v370; // [rsp+1A8h] [rbp+B0h]
  __int128 v371; // [rsp+1B8h] [rbp+C0h]
  __m128i v372; // [rsp+1C8h] [rbp+D0h]
  hkVector4f v373; // [rsp+1D8h] [rbp+E0h]
  __int128 v374; // [rsp+1E8h] [rbp+F0h]
  __m128i v375; // [rsp+1F8h] [rbp+100h]
  hkVector4f v376; // [rsp+208h] [rbp+110h]
  __int128 v377; // [rsp+218h] [rbp+120h]
  __m128i v378; // [rsp+228h] [rbp+130h]
  __int128 v379; // [rsp+238h] [rbp+140h]
  __int128 v380; // [rsp+248h] [rbp+150h]
  __m128i v381; // [rsp+258h] [rbp+160h]
  hkVector4f v382; // [rsp+268h] [rbp+170h]
  __int128 v383; // [rsp+278h] [rbp+180h]
  __m128i v384; // [rsp+288h] [rbp+190h]
  hkVector4f v385; // [rsp+298h] [rbp+1A0h]
  __int128 v386; // [rsp+2A8h] [rbp+1B0h]
  __m128i v387; // [rsp+2B8h] [rbp+1C0h]
  __int128 v388; // [rsp+2C8h] [rbp+1D0h]
  __int128 v389; // [rsp+2D8h] [rbp+1E0h]
  char buf[520]; // [rsp+2E8h] [rbp+1F0h] BYREF
  void *retaddr; // [rsp+5D8h] [rbp+4E0h] BYREF
  unsigned int v392; // [rsp+5E0h] [rbp+4E8h]
  hkResult result; // [rsp+5E8h] [rbp+4F0h] BYREF
  int v394; // [rsp+5F0h] [rbp+4F8h]

  result.m_enum = LODWORD(offset);
  m_data = this->m_data;
  if ( !m_data->m_hasIndexing )
  {
    hkErrStream::hkErrStream(&v355, buf, 512);
    v6 = hkOstream::operator<<(&v355, "No index available (");
    v7 = hkOstream::operator<<(v6, m_data->m_uid);
    hkOstream::operator<<(v7, ") hkgpConvexHull::buildIndices need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         0x79F9D886u,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         358) )
      __debugbreak();
    hkOstream::~hkOstream(&v355);
  }
  if ( this->m_data->m_hasMassProperties )
    CenterOfMass = hkgpConvexHull::getCenterOfMass(this);
  else
    CenterOfMass = hkgpConvexHull::getCentroid(this);
  m_quad = CenterOfMass->m_quad;
  v10 = _mm_shuffle_ps((__m128)LODWORD(config->m_minComDistance), (__m128)LODWORD(config->m_minComDistance), 0);
  v11 = (__m128i)_mm_shuffle_ps((__m128)v392, (__m128)v392, 0);
  v357 = CenterOfMass->m_quad;
  v12 = 0i64;
  positions.m_data = 0i64;
  positions.m_size = 0;
  positions.m_capacityAndFlags = 0x80000000;
  points = (hkStridedVertices)v11;
  v358 = v10;
  hkgpConvexHull::fetchPositions(this, INTERNAL_VERTICES, &positions);
  hkAabbUtil::calcAabb(positions.m_data, positions.m_size, &aabbOut);
  if ( config->m_method == SKM_VERTICES )
  {
    if ( *(float *)v11.m128i_i32 < 0.0 )
    {
      for ( i = hkgpConvexHull::getFirstVertex(this); i; i = hkgpConvexHull::getNext(this, i) )
      {
        v288 = _mm_sub_ps(hkgpConvexHull::getSourcePosition(this, i)->m_quad, m_quad);
        v289 = _mm_mul_ps(v288, v288);
        v290 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v289, v289, 85), _mm_shuffle_ps(v289, v289, 0)),
                 _mm_shuffle_ps(v289, v289, 170));
        v291 = _mm_rsqrt_ps(v290);
        v292 = _mm_andnot_ps(
                 _mm_cmple_ps(v290, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v291, v290), v291)),
                     _mm_mul_ps(v291, *(__m128 *)_xmm)),
                   v290));
        if ( v292.m128_f32[0] < (float)(0.0 - *(float *)v11.m128i_i32) )
          v11 = (__m128i)_mm_sub_ps((__m128)0i64, v292);
      }
    }
    m_numVertices = 0;
    m_striding = 0x80000000;
    v346.m_numVertices = 0;
    v346.m_striding = 0x80000000;
    v346.m_vertices = 0i64;
    NumVertices = hkgpConvexHull::getNumVertices(this);
    if ( NumVertices <= 0 )
    {
      positions.m_size = 0;
    }
    else
    {
      hkArrayUtil::_reserve(
        (hkResult *)&positions.m_size,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&v346.m_vertices,
        NumVertices,
        16);
      m_striding = v346.m_striding;
      m_numVertices = v346.m_numVertices;
    }
    FirstVertex = hkgpConvexHull::getFirstVertex(this);
    if ( FirstVertex )
    {
      while ( 1 )
      {
        SourcePosition = hkgpConvexHull::getSourcePosition(this, FirstVertex);
        v298 = _mm_sub_ps(SourcePosition->m_quad, m_quad);
        v299 = _mm_mul_ps(v298, v298);
        v300 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v299, v299, 85), _mm_shuffle_ps(v299, v299, 0)),
                 _mm_shuffle_ps(v299, v299, 170));
        v301 = _mm_rsqrt_ps(v300);
        v302 = _mm_andnot_ps(
                 _mm_cmple_ps(v300, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v301, v300), v301)),
                     _mm_mul_ps(v301, *(__m128 *)_xmm)),
                   v300));
        if ( v302.m128_f32[0] <= v10.m128_f32[0] )
        {
          if ( m_numVertices == (m_striding & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v346.m_vertices, 16);
            m_numVertices = v346.m_numVertices;
          }
          *(hkVector4f *)&v346.m_vertices[4 * m_numVertices] = (hkVector4f)SourcePosition->m_quad;
        }
        else
        {
          v303 = _mm_add_ps(v302, (__m128)v11);
          if ( v303.m128_f32[0] < v10.m128_f32[0] )
            v303 = v10;
          v304 = _mm_add_ps(_mm_mul_ps(_mm_div_ps(v303, v302), v298), m_quad);
          if ( m_numVertices == (m_striding & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v346.m_vertices, 16);
            m_numVertices = v346.m_numVertices;
          }
          *(__m128 *)&v346.m_vertices[4 * m_numVertices] = v304;
        }
        m_numVertices = ++v346.m_numVertices;
        FirstVertex = hkgpConvexHull::getNext(this, FirstVertex);
        if ( !FirstVertex )
          break;
        m_striding = v346.m_striding;
      }
    }
    Dimensions = hkgpConvexHull::getDimensions(this);
    points.m_numVertices = m_numVertices;
    points.m_striding = 16;
    points.m_vertices = v346.m_vertices;
    if ( Dimensions == 2 )
    {
      Configuration = hkgpConvexHull::getConfiguration(this);
      ProjectionPlane = hkgpConvexHull::getProjectionPlane(this);
      hkgpConvexHull::buildPlanar(this, &points, ProjectionPlane, Configuration);
    }
    else
    {
      v308 = hkgpConvexHull::getConfiguration(this);
      hkgpConvexHull::build(this, &points, v308);
    }
    v285 = v346.m_striding;
    v346.m_numVertices = 0;
    if ( v346.m_striding < 0 )
      goto LABEL_192;
    m_vertices = (hkVector4f *)v346.m_vertices;
    goto LABEL_191;
  }
  if ( config->m_method != SKM_PLANES )
  {
    if ( config->m_method != SKM_CLAMPED_PLANES )
      goto LABEL_192;
    m_featurePreservationFactor_low = (__m128)LODWORD(config->m_featurePreservationFactor);
    v12 = v10;
    v356 = v10;
    v14 = _mm_shuffle_ps(m_featurePreservationFactor_low, m_featurePreservationFactor_low, 0);
    v354 = (hkStridedVertices)xmmword_141A712A0;
    v15 = (__m128)xmmword_141A712A0;
    v16 = _mm_cmplt_ps(v14, query.m_quad);
    v346 = (hkStridedVertices)xmmword_141A712A0;
    v17 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v16, v14), _mm_andnot_ps(v16, query.m_quad)));
    v362 = v17;
    if ( *(float *)v11.m128i_i32 < 0.0 )
    {
      v18 = 0;
      NumPlanes = hkgpConvexHull::getNumPlanes(this);
      if ( NumPlanes > 0 )
      {
        do
        {
          Plane = hkgpConvexHull::getPlane(this, v18++);
          v15 = _mm_min_ps(
                  v15,
                  _mm_sub_ps(
                    (__m128)0i64,
                    hkgpConvexHull::getMinimumDistanceFromPlane(this, (hkSimdFloat32 *)&v355, Plane)->m_real));
        }
        while ( v18 < NumPlanes );
      }
      v15 = _mm_mul_ps(v15, (__m128)xmmword_141A711D0);
      v354 = (hkStridedVertices)xmmword_141A712A0;
      v346 = (hkStridedVertices)v15;
    }
    v21 = 0;
    v22 = 0;
    v23 = _mm_sub_ps((__m128)0i64, v15);
    v363 = v23;
    if ( *(float *)v11.m128i_i32 < v23.m128_f32[0] )
      v21 = 1;
    LODWORD(retaddr) = v21;
    if ( v17.m128_f32[0] > 0.0 )
      v22 = 1;
    v394 = v22;
    if ( v21 || v22 )
    {
      result.m_enum = LODWORD(FLOAT_0_0000099999997);
      v364 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0);
      v24 = hkgpConvexHull::getNumVertices(this);
      v25 = 0;
      array = 0i64;
      v350 = 0x80000000;
      v26 = v24;
      v349 = 0;
      v352 = v24;
      if ( v24 )
      {
        Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        m_cur = (hkVector4f *)Value->m_cur;
        v29 = (48 * v26 + 127) & 0xFFFFFF80;
        v30 = (char *)m_cur + v29;
        if ( v29 > Value->m_slabSize || v30 > Value->m_end )
        {
          v31 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(Value, v29);
          v25 = v349;
          array = v31;
        }
        else
        {
          Value->m_cur = v30;
          v25 = v349;
          array = m_cur;
        }
      }
      else
      {
        array = 0i64;
      }
      v32 = array;
      p = array;
      v350 = v26 | 0x80000000;
      if ( (v26 & 0x3FFFFFFF) < v26 )
      {
        v33 = v26;
        if ( v26 < 2 * (v26 & 0x3FFFFFFF) )
          v33 = 2 * (v26 & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v33, 48);
        v32 = (hkVector4f *)p;
        v25 = v349;
      }
      v34 = v26 - v25;
      v35 = &array[3 * v25];
      v36 = v26 - v25;
      if ( v34 > 0 )
      {
        do
        {
          if ( v35 )
          {
            v35->m_quad.m128_i32[0] = 0;
            v35[1] = (hkVector4f)::aabbOut.m_quad;
          }
          v35 += 3;
          --v36;
        }
        while ( v36 );
        v32 = (hkVector4f *)p;
      }
      v349 = v26;
      v37 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v11, 1u), 1u);
      FirstTriangle = hkgpConvexHull::getFirstTriangle(this);
      if ( FirstTriangle )
      {
        v39 = v354;
        v40 = v364.m128_f32[0];
        while ( 1 )
        {
          v41 = array;
          v42 = 0i64;
          v43 = hkgpConvexHull::getSourcePosition(this, *(hkgpConvexHull::Vertex **)&FirstTriangle[24]);
          v44 = hkgpConvexHull::getSourcePosition(this, *(hkgpConvexHull::Vertex **)&FirstTriangle[16]);
          v45 = v43->m_quad;
          v46 = *(_QWORD *)&FirstTriangle[40];
          v47 = _mm_sub_ps(v45, v44->m_quad);
          PlaneIndex = hkgpConvexHull::getPlaneIndex(this, FirstTriangle);
          v49 = *(int *)(*(_QWORD *)&FirstTriangle[16] + 52i64);
          v50 = PlaneIndex;
          if ( hkgpConvexHull::getPlaneIndex(this, (hkgpConvexHull::Triangle *)(v46 & 0xFFFFFFFFFFFFFFFCui64)) != PlaneIndex )
            v42.m128_f32[0] = 1.0;
          v51 = &v41[3 * v49];
          v52 = v51->m_quad.m128_i32[0];
          if ( !(_DWORD)v52 )
            goto LABEL_56;
          if ( (_DWORD)v52 == 1 )
            break;
          if ( (_DWORD)v52 == 2 )
          {
            if ( v51->m_quad.m128_i32[1] != v50 && v51->m_quad.m128_i32[2] != v50 )
            {
              v51->m_quad.m128_i32[3] = v50;
              ++v51->m_quad.m128_i32[0];
              v86 = hkgpConvexHull::getPlane(this, v51->m_quad.m128_i32[2]);
              v87 = hkgpConvexHull::getPlane(this, v51->m_quad.m128_i32[1]);
              v88 = _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v86->m_quad, v86->m_quad, 201), v87->m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v87->m_quad, v87->m_quad, 201), v86->m_quad));
              v89 = _mm_mul_ps(
                      _mm_shuffle_ps(v88, v88, 201),
                      hkgpConvexHull::getPlane(this, v51->m_quad.m128_i32[3])->m_quad);
              v90 = (__m128i)_mm_add_ps(
                               _mm_add_ps(_mm_shuffle_ps(v89, v89, 85), _mm_shuffle_ps(v89, v89, 0)),
                               _mm_shuffle_ps(v89, v89, 170));
              v51[1] = (hkVector4f)v90;
              v51[2] = (hkVector4f)_mm_srli_epi32(_mm_slli_epi32(v90, 1u), 1u);
            }
          }
          else if ( v51->m_quad.m128_i32[1] != v50 && v51->m_quad.m128_i32[2] != v50 && v51->m_quad.m128_i32[3] != v50 )
          {
            v53 = (__m128i)v51->m_quad;
            v54 = (__int128)v51[2];
            v385.m_quad = (__m128)v51[1];
            v384 = v53;
            v55 = _mm_cvtsi128_si32(_mm_srli_si128(v53, 8));
            v386 = v54;
            v56 = hkgpConvexHull::getPlane(this, v55);
            v57 = hkgpConvexHull::getPlane(this, v50);
            v58 = v56->m_quad;
            v59 = _mm_cvtsi128_si32(_mm_srli_si128(v53, 12));
            v60 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v58, v58, 201), v57->m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v57->m_quad, v57->m_quad, 201), v58));
            v61 = _mm_mul_ps(_mm_shuffle_ps(v60, v60, 201), hkgpConvexHull::getPlane(this, v59)->m_quad);
            v62 = (__m128i)_mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v61, v61, 85), _mm_shuffle_ps(v61, v61, 0)),
                             _mm_shuffle_ps(v61, v61, 170));
            v63 = _mm_srli_epi32(_mm_slli_epi32(v62, 1u), 1u);
            if ( *(float *)v63.m128i_i32 > v51[2].m_quad.m128_f32[0] )
            {
              v51->m_quad.m128_i32[0] = v384.m128i_i32[0];
              v51->m_quad.m128_i32[1] = v50;
              v51->m_quad.m128_i32[2] = v55;
              v51->m_quad.m128_i32[3] = v59;
              v51[1] = (hkVector4f)v62;
              v51[2] = (hkVector4f)v63;
            }
            v65 = (__int128)v51[1];
            v66 = (__int128)v51[2];
            v366 = (__m128i)v51->m_quad;
            v64 = v366;
            v367 = v65;
            v368 = v66;
            v67 = hkgpConvexHull::getPlane(this, v50);
            v68 = _mm_cvtsi128_si32(_mm_srli_si128(v64, 4));
            v69 = hkgpConvexHull::getPlane(this, v68);
            v70 = v67->m_quad;
            v71 = _mm_cvtsi128_si32(_mm_srli_si128(v64, 12));
            v72 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v70, v70, 201), v69->m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v69->m_quad, v69->m_quad, 201), v70));
            v73 = _mm_mul_ps(_mm_shuffle_ps(v72, v72, 201), hkgpConvexHull::getPlane(this, v71)->m_quad);
            v74 = (__m128i)_mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
                             _mm_shuffle_ps(v73, v73, 170));
            v75 = _mm_srli_epi32(_mm_slli_epi32(v74, 1u), 1u);
            if ( *(float *)v75.m128i_i32 > v51[2].m_quad.m128_f32[0] )
            {
              v51->m_quad.m128_i32[0] = v366.m128i_i32[0];
              v51->m_quad.m128_i32[1] = v68;
              v51->m_quad.m128_i32[2] = v50;
              v51->m_quad.m128_i32[3] = v71;
              v51[1] = (hkVector4f)v74;
              v51[2] = (hkVector4f)v75;
            }
            v76 = (__m128i)v51->m_quad;
            v77 = (__int128)v51[2];
            v382.m_quad = (__m128)v51[1];
            v381 = v76;
            v78 = _mm_cvtsi128_si32(_mm_srli_si128(v76, 8));
            v383 = v77;
            v79 = hkgpConvexHull::getPlane(this, v78);
            v80 = _mm_cvtsi128_si32(_mm_srli_si128(v76, 4));
            v81 = hkgpConvexHull::getPlane(this, v80);
            v82 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v79->m_quad, v79->m_quad, 201), v81->m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v81->m_quad, v81->m_quad, 201), v79->m_quad));
            v83 = _mm_mul_ps(_mm_shuffle_ps(v82, v82, 201), hkgpConvexHull::getPlane(this, v50)->m_quad);
            v84 = (__m128i)_mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v83, v83, 85), _mm_shuffle_ps(v83, v83, 0)),
                             _mm_shuffle_ps(v83, v83, 170));
            v85 = _mm_srli_epi32(_mm_slli_epi32(v84, 1u), 1u);
            if ( *(float *)v85.m128i_i32 > v51[2].m_quad.m128_f32[0] )
            {
              v51->m_quad.m128_i32[0] = v381.m128i_i32[0];
              v51->m_quad.m128_i32[1] = v80;
              v51->m_quad.m128_i32[2] = v78;
              v51->m_quad.m128_i32[3] = v50;
              v51[1] = (hkVector4f)v84;
              v51[2] = (hkVector4f)v85;
            }
          }
LABEL_57:
          v91 = array;
          v92 = hkgpConvexHull::getSourcePosition(this, *(hkgpConvexHull::Vertex **)&FirstTriangle[32]);
          v93 = hkgpConvexHull::getSourcePosition(this, *(hkgpConvexHull::Vertex **)&FirstTriangle[24]);
          v94 = v92->m_quad;
          v95 = *(_QWORD *)&FirstTriangle[48];
          v96 = _mm_sub_ps(v94, v93->m_quad);
          v97 = hkgpConvexHull::getPlaneIndex(this, FirstTriangle);
          v98 = *(int *)(*(_QWORD *)&FirstTriangle[24] + 52i64);
          v99 = v97;
          if ( hkgpConvexHull::getPlaneIndex(this, (hkgpConvexHull::Triangle *)(v95 & 0xFFFFFFFFFFFFFFFCui64)) != v97 )
            v42 = _mm_shuffle_ps(_mm_unpacklo_ps(v42, query.m_quad), v42, 228);
          v100 = &v91[3 * v98];
          v101 = v100->m_quad.m128_i32[0];
          switch ( (_DWORD)v101 )
          {
            case 0:
              goto LABEL_75;
            case 1:
              if ( v100->m_quad.m128_i32[1] == v99 )
                break;
LABEL_75:
              v100->m_quad.m128_i32[v101 + 1] = v99;
              ++v100->m_quad.m128_i32[0];
              break;
            case 2:
              if ( v100->m_quad.m128_i32[1] != v99 && v100->m_quad.m128_i32[2] != v99 )
              {
                v100->m_quad.m128_i32[3] = v99;
                ++v100->m_quad.m128_i32[0];
                v135 = hkgpConvexHull::getPlane(this, v100->m_quad.m128_i32[2]);
                v136 = hkgpConvexHull::getPlane(this, v100->m_quad.m128_i32[1]);
                v137 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v135->m_quad, v135->m_quad, 201), v136->m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v136->m_quad, v136->m_quad, 201), v135->m_quad));
                v138 = _mm_mul_ps(
                         _mm_shuffle_ps(v137, v137, 201),
                         hkgpConvexHull::getPlane(this, v100->m_quad.m128_i32[3])->m_quad);
                v139 = (__m128i)_mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v138, v138, 85), _mm_shuffle_ps(v138, v138, 0)),
                                  _mm_shuffle_ps(v138, v138, 170));
                v100[1] = (hkVector4f)v139;
                v100[2] = (hkVector4f)_mm_srli_epi32(_mm_slli_epi32(v139, 1u), 1u);
              }
              break;
            default:
              if ( v100->m_quad.m128_i32[1] != v99 && v100->m_quad.m128_i32[2] != v99 && v100->m_quad.m128_i32[3] != v99 )
              {
                v102 = (__m128i)v100->m_quad;
                v103 = (__int128)v100[2];
                v376.m_quad = (__m128)v100[1];
                v375 = v102;
                v104 = _mm_cvtsi128_si32(_mm_srli_si128(v102, 8));
                v377 = v103;
                v105 = hkgpConvexHull::getPlane(this, v104);
                v106 = hkgpConvexHull::getPlane(this, v99);
                v107 = v105->m_quad;
                v108 = _mm_cvtsi128_si32(_mm_srli_si128(v102, 12));
                v109 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v107, v107, 201), v106->m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v106->m_quad, v106->m_quad, 201), v107));
                v110 = _mm_mul_ps(_mm_shuffle_ps(v109, v109, 201), hkgpConvexHull::getPlane(this, v108)->m_quad);
                v111 = (__m128i)_mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v110, v110, 85), _mm_shuffle_ps(v110, v110, 0)),
                                  _mm_shuffle_ps(v110, v110, 170));
                v112 = _mm_srli_epi32(_mm_slli_epi32(v111, 1u), 1u);
                if ( *(float *)v112.m128i_i32 > v100[2].m_quad.m128_f32[0] )
                {
                  v100->m_quad.m128_i32[0] = v375.m128i_i32[0];
                  v100->m_quad.m128_i32[1] = v99;
                  v100->m_quad.m128_i32[2] = v104;
                  v100->m_quad.m128_i32[3] = v108;
                  v100[1] = (hkVector4f)v111;
                  v100[2] = (hkVector4f)v112;
                }
                v114 = (__int128)v100[1];
                v115 = (__int128)v100[2];
                v387 = (__m128i)v100->m_quad;
                v113 = v387;
                v388 = v114;
                v389 = v115;
                v116 = hkgpConvexHull::getPlane(this, v99);
                v117 = _mm_cvtsi128_si32(_mm_srli_si128(v113, 4));
                v118 = hkgpConvexHull::getPlane(this, v117);
                v119 = v116->m_quad;
                v120 = _mm_cvtsi128_si32(_mm_srli_si128(v113, 12));
                v121 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v119, v119, 201), v118->m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v118->m_quad, v118->m_quad, 201), v119));
                v122 = _mm_mul_ps(_mm_shuffle_ps(v121, v121, 201), hkgpConvexHull::getPlane(this, v120)->m_quad);
                v123 = (__m128i)_mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v122, v122, 85), _mm_shuffle_ps(v122, v122, 0)),
                                  _mm_shuffle_ps(v122, v122, 170));
                v124 = _mm_srli_epi32(_mm_slli_epi32(v123, 1u), 1u);
                if ( *(float *)v124.m128i_i32 > v100[2].m_quad.m128_f32[0] )
                {
                  v100->m_quad.m128_i32[0] = v387.m128i_i32[0];
                  v100->m_quad.m128_i32[1] = v117;
                  v100->m_quad.m128_i32[2] = v99;
                  v100->m_quad.m128_i32[3] = v120;
                  v100[1] = (hkVector4f)v123;
                  v100[2] = (hkVector4f)v124;
                }
                v125 = (__m128i)v100->m_quad;
                v126 = (__int128)v100[2];
                v370.m_quad = (__m128)v100[1];
                v369 = v125;
                v127 = _mm_cvtsi128_si32(_mm_srli_si128(v125, 8));
                v371 = v126;
                v128 = hkgpConvexHull::getPlane(this, v127);
                v129 = _mm_cvtsi128_si32(_mm_srli_si128(v125, 4));
                v130 = hkgpConvexHull::getPlane(this, v129);
                v131 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v128->m_quad, v128->m_quad, 201), v130->m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v130->m_quad, v130->m_quad, 201), v128->m_quad));
                v132 = _mm_mul_ps(_mm_shuffle_ps(v131, v131, 201), hkgpConvexHull::getPlane(this, v99)->m_quad);
                v133 = (__m128i)_mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v132, v132, 85), _mm_shuffle_ps(v132, v132, 0)),
                                  _mm_shuffle_ps(v132, v132, 170));
                v134 = _mm_srli_epi32(_mm_slli_epi32(v133, 1u), 1u);
                if ( *(float *)v134.m128i_i32 > v100[2].m_quad.m128_f32[0] )
                {
                  v100->m_quad.m128_i32[0] = v369.m128i_i32[0];
                  v100->m_quad.m128_i32[1] = v129;
                  v100->m_quad.m128_i32[2] = v127;
                  v100->m_quad.m128_i32[3] = v99;
                  v100[1] = (hkVector4f)v133;
                  v100[2] = (hkVector4f)v134;
                }
              }
              break;
          }
          v140 = array;
          v141 = hkgpConvexHull::getSourcePosition(this, *(hkgpConvexHull::Vertex **)&FirstTriangle[16]);
          v142 = hkgpConvexHull::getSourcePosition(this, *(hkgpConvexHull::Vertex **)&FirstTriangle[32]);
          v143 = v141->m_quad;
          v144 = *(_QWORD *)&FirstTriangle[56];
          v145 = _mm_sub_ps(v143, v142->m_quad);
          v146 = hkgpConvexHull::getPlaneIndex(this, FirstTriangle);
          v147 = *(int *)(*(_QWORD *)&FirstTriangle[32] + 52i64);
          v148 = v146;
          if ( hkgpConvexHull::getPlaneIndex(this, (hkgpConvexHull::Triangle *)(v144 & 0xFFFFFFFFFFFFFFFCui64)) != v146 )
            v42 = _mm_shuffle_ps(v42, _mm_unpackhi_ps(v42, query.m_quad), 180);
          v149 = &v140[3 * v147];
          v150 = v149->m_quad.m128_i32[0];
          switch ( (_DWORD)v150 )
          {
            case 0:
LABEL_94:
              v149->m_quad.m128_i32[v150 + 1] = v148;
              ++v149->m_quad.m128_i32[0];
              break;
            case 1:
              if ( v149->m_quad.m128_i32[1] != v148 )
                goto LABEL_94;
              break;
            case 2:
              if ( v149->m_quad.m128_i32[1] != v148 && v149->m_quad.m128_i32[2] != v148 )
              {
                v149->m_quad.m128_i32[3] = v148;
                ++v149->m_quad.m128_i32[0];
                v184 = hkgpConvexHull::getPlane(this, v149->m_quad.m128_i32[2]);
                v185 = hkgpConvexHull::getPlane(this, v149->m_quad.m128_i32[1]);
                v186 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v184->m_quad, v184->m_quad, 201), v185->m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v185->m_quad, v185->m_quad, 201), v184->m_quad));
                v187 = _mm_mul_ps(
                         _mm_shuffle_ps(v186, v186, 201),
                         hkgpConvexHull::getPlane(this, v149->m_quad.m128_i32[3])->m_quad);
                v188 = (__m128i)_mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v187, v187, 85), _mm_shuffle_ps(v187, v187, 0)),
                                  _mm_shuffle_ps(v187, v187, 170));
                v149[1] = (hkVector4f)v188;
                v149[2] = (hkVector4f)_mm_srli_epi32(_mm_slli_epi32(v188, 1u), 1u);
              }
              break;
            default:
              if ( v149->m_quad.m128_i32[1] != v148
                && v149->m_quad.m128_i32[2] != v148
                && v149->m_quad.m128_i32[3] != v148 )
              {
                v151 = (__m128i)v149->m_quad;
                v152 = (__int128)v149[2];
                v373.m_quad = (__m128)v149[1];
                v372 = v151;
                v153 = _mm_cvtsi128_si32(_mm_srli_si128(v151, 8));
                v374 = v152;
                v154 = hkgpConvexHull::getPlane(this, v153);
                v155 = hkgpConvexHull::getPlane(this, v148);
                v156 = v154->m_quad;
                v157 = _mm_cvtsi128_si32(_mm_srli_si128(v151, 12));
                v158 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v156, v156, 201), v155->m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v155->m_quad, v155->m_quad, 201), v156));
                v159 = _mm_mul_ps(_mm_shuffle_ps(v158, v158, 201), hkgpConvexHull::getPlane(this, v157)->m_quad);
                v160 = (__m128i)_mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v159, v159, 85), _mm_shuffle_ps(v159, v159, 0)),
                                  _mm_shuffle_ps(v159, v159, 170));
                v161 = _mm_srli_epi32(_mm_slli_epi32(v160, 1u), 1u);
                if ( *(float *)v161.m128i_i32 > v149[2].m_quad.m128_f32[0] )
                {
                  v149->m_quad.m128_i32[0] = v372.m128i_i32[0];
                  v149->m_quad.m128_i32[1] = v148;
                  v149->m_quad.m128_i32[2] = v153;
                  v149->m_quad.m128_i32[3] = v157;
                  v149[1] = (hkVector4f)v160;
                  v149[2] = (hkVector4f)v161;
                }
                v163 = (__int128)v149[1];
                v164 = (__int128)v149[2];
                v378 = (__m128i)v149->m_quad;
                v162 = v378;
                v379 = v163;
                v380 = v164;
                v165 = hkgpConvexHull::getPlane(this, v148);
                v166 = _mm_cvtsi128_si32(_mm_srli_si128(v162, 4));
                v167 = hkgpConvexHull::getPlane(this, v166);
                v168 = v165->m_quad;
                v169 = _mm_cvtsi128_si32(_mm_srli_si128(v162, 12));
                v170 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v168, v168, 201), v167->m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v167->m_quad, v167->m_quad, 201), v168));
                v171 = _mm_mul_ps(_mm_shuffle_ps(v170, v170, 201), hkgpConvexHull::getPlane(this, v169)->m_quad);
                v172 = (__m128i)_mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v171, v171, 85), _mm_shuffle_ps(v171, v171, 0)),
                                  _mm_shuffle_ps(v171, v171, 170));
                v173 = _mm_srli_epi32(_mm_slli_epi32(v172, 1u), 1u);
                if ( *(float *)v173.m128i_i32 > v149[2].m_quad.m128_f32[0] )
                {
                  v149->m_quad.m128_i32[0] = v378.m128i_i32[0];
                  v149->m_quad.m128_i32[1] = v166;
                  v149->m_quad.m128_i32[2] = v148;
                  v149->m_quad.m128_i32[3] = v169;
                  v149[1] = (hkVector4f)v172;
                  v149[2] = (hkVector4f)v173;
                }
                v174 = (__m128i)v149->m_quad;
                v175 = (__int128)v149[2];
                v360.m_quad = (__m128)v149[1];
                *(__m128i *)index = v174;
                v176 = _mm_cvtsi128_si32(_mm_srli_si128(v174, 8));
                v361 = v175;
                v177 = hkgpConvexHull::getPlane(this, v176);
                v178 = _mm_cvtsi128_si32(_mm_srli_si128(v174, 4));
                v179 = hkgpConvexHull::getPlane(this, v178);
                v180 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v177->m_quad, v177->m_quad, 201), v179->m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v179->m_quad, v179->m_quad, 201), v177->m_quad));
                v181 = _mm_mul_ps(_mm_shuffle_ps(v180, v180, 201), hkgpConvexHull::getPlane(this, v148)->m_quad);
                v182 = (__m128i)_mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v181, v181, 85), _mm_shuffle_ps(v181, v181, 0)),
                                  _mm_shuffle_ps(v181, v181, 170));
                v183 = _mm_srli_epi32(_mm_slli_epi32(v182, 1u), 1u);
                if ( *(float *)v183.m128i_i32 > v149[2].m_quad.m128_f32[0] )
                {
                  v149->m_quad.m128_i32[0] = index[0];
                  v149->m_quad.m128_i32[1] = v178;
                  v149->m_quad.m128_i32[2] = v176;
                  v149->m_quad.m128_i32[3] = v148;
                  v149[1] = (hkVector4f)v182;
                  v149[2] = (hkVector4f)v183;
                }
              }
              break;
          }
          if ( (_DWORD)retaddr )
          {
            v189 = (int)(float)((float)(_mm_shuffle_ps(v42, v42, 85).m128_f32[0]
                                      + _mm_shuffle_ps(v42, v42, 0).m128_f32[0])
                              + _mm_shuffle_ps(v42, v42, 170).m128_f32[0]);
            if ( v189 )
            {
              v190 = _mm_mul_ps(v47, v47);
              v191 = _mm_mul_ps(v96, v96);
              v192 = _mm_mul_ps(v145, v145);
              v193 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v190, v190, 85), _mm_shuffle_ps(v190, v190, 0)),
                       _mm_shuffle_ps(v190, v190, 170));
              v194 = _mm_andnot_ps(_mm_cmple_ps(v193, (__m128)0i64), _mm_mul_ps(_mm_rsqrt_ps(v193), v193)).m128_f32[0];
              v195 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v191, v191, 85), _mm_shuffle_ps(v191, v191, 0)),
                       _mm_shuffle_ps(v191, v191, 170));
              v196 = _mm_andnot_ps(_mm_cmple_ps(v195, (__m128)0i64), _mm_mul_ps(_mm_rsqrt_ps(v195), v195));
              v197 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v192, v192, 85), _mm_shuffle_ps(v192, v192, 0)),
                       _mm_shuffle_ps(v192, v192, 170));
              v198 = ::aabbOut.m_quad;
              v198.m128_f32[0] = v194;
              v199 = _mm_shuffle_ps(_mm_unpacklo_ps(v198, v196), v198, 228);
              v200 = _mm_shuffle_ps(
                       v199,
                       _mm_unpackhi_ps(
                         v199,
                         _mm_andnot_ps(_mm_cmple_ps(v197, (__m128)0i64), _mm_mul_ps(_mm_rsqrt_ps(v197), v197))),
                       180);
              v201 = _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v200, v200, 85), _mm_shuffle_ps(v200, v200, 0)),
                         _mm_shuffle_ps(v200, v200, 170)),
                       (__m128)xmmword_141A711B0);
              v202 = _mm_sub_ps(v201, v200);
              v203 = _mm_mul_ps(_mm_shuffle_ps(v202, v202, 78), v202);
              v204 = _mm_mul_ps(_mm_shuffle_ps(v203, v203, 177), v203);
              v205 = _mm_andnot_ps(_mm_cmple_ps(v204, (__m128)0i64), _mm_mul_ps(_mm_rsqrt_ps(v204), v204));
              if ( v205.m128_f32[0] >= v40 )
              {
                v206 = _mm_cmplt_ps((__m128)0i64, v42);
                v207 = v189 - 1;
                if ( v207 )
                {
                  v208 = v207 - 1;
                  if ( v208 )
                  {
                    if ( v208 == 1 )
                    {
                      v209 = _mm_rcp_ps(v201);
                      v37 = _mm_min_ps(
                              v37,
                              _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v201, v209)), v209), v205));
                    }
                    goto LABEL_105;
                  }
                  v210 = _mm_and_ps(v200, v206);
                  v211 = _mm_max_ps(
                           _mm_shuffle_ps(v210, v210, 170),
                           _mm_max_ps(_mm_shuffle_ps(v210, v210, 85), _mm_shuffle_ps(v210, v210, 0)));
                  v212 = _mm_rcp_ps(v211);
                  v213 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v212, v211)), v212), v205);
                }
                else
                {
                  v214 = _mm_or_ps(_mm_andnot_ps(v206, (__m128)v39), _mm_and_ps(v200, v206));
                  v213 = _mm_min_ps(
                           _mm_shuffle_ps(v214, v214, 170),
                           _mm_min_ps(_mm_shuffle_ps(v214, v214, 85), _mm_shuffle_ps(v214, v214, 0)));
                }
                v37 = _mm_min_ps(v37, v213);
              }
            }
          }
LABEL_105:
          FirstTriangle = hkgpConvexHull::getNext(this, FirstTriangle);
          if ( !FirstTriangle )
          {
            v32 = (hkVector4f *)p;
            v26 = v349;
            v11 = (__m128i)points;
            v15 = (__m128)v346;
            v23 = v363;
            v22 = v394;
            goto LABEL_107;
          }
        }
        if ( v51->m_quad.m128_i32[1] == v50 )
          goto LABEL_57;
LABEL_56:
        v51->m_quad.m128_i32[v52 + 1] = v50;
        ++v51->m_quad.m128_i32[0];
        goto LABEL_57;
      }
LABEL_107:
      if ( (_DWORD)retaddr )
      {
        v215 = _mm_cmplt_ps(v37, v15);
        v11 = (__m128i)_mm_or_ps(_mm_andnot_ps(v215, _mm_sub_ps((__m128)0i64, v37)), _mm_and_ps(v215, v23));
        points = (hkStridedVertices)v11;
      }
      if ( v22 )
      {
        v216 = (__m128)xmmword_141A712B0;
        Next = hkgpConvexHull::getFirstVertex(this);
        if ( Next )
        {
          do
          {
            v218 = hkgpConvexHull::getIndex(this, Next);
            v219.m_quad = (__m128)array[3 * v218];
            v220 = array[3 * v218 + 1].m_quad;
            v221.m_quad = (__m128)array[3 * v218 + 2];
            v222 = array[3 * v218].m_quad.m128_u64[0];
            *(hkVector4f *)index = (hkVector4f)v219.m_quad;
            if ( (int)v222 >= 3 )
            {
              v223 = hkgpConvexHull::getPlane(this, SHIDWORD(v222))->m_quad;
              v224 = hkgpConvexHull::getPlane(this, index[2])->m_quad;
              v225 = hkgpConvexHull::getPlane(this, index[3])->m_quad;
              if ( v221.m_quad.m128_f32[0] > 0.00000011920929 )
              {
                v226 = hkgpConvexHull::getSourcePosition(this, Next);
                v227 = _mm_shuffle_ps(v224, v224, 201);
                v228 = _mm_shuffle_ps(v225, v225, 201);
                v229 = _mm_mul_ps(v228, v223);
                v230 = _mm_shuffle_ps(v226->m_quad, _mm_unpackhi_ps(v226->m_quad, query.m_quad), 196);
                v231 = _mm_sub_ps(_mm_mul_ps(v228, v224), _mm_mul_ps(v227, v225));
                v232 = _mm_shuffle_ps(v231, v231, 201);
                v233 = _mm_shuffle_ps(v223, v223, 201);
                v234 = _mm_sub_ps(_mm_mul_ps(v227, v223), _mm_mul_ps(v233, v224));
                v235 = _mm_sub_ps(_mm_mul_ps(v233, v225), v229);
                v236 = 0i64;
                v237 = _mm_shuffle_ps(v234, v234, 201);
                v238 = _mm_shuffle_ps(v235, v235, 201);
                v236.m128_f32[0] = _mm_shuffle_ps(v223, v223, 255).m128_f32[0];
                v239 = _mm_shuffle_ps(_mm_unpacklo_ps(v236, _mm_shuffle_ps(v224, v224, 255)), v236, 228);
                v240 = _mm_shuffle_ps(v239, _mm_unpackhi_ps(v239, _mm_shuffle_ps(v225, v225, 255)), 180);
                v241 = _mm_sub_ps(
                         _mm_add_ps(_mm_add_ps(v238, v232), v237),
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(v240, v240, 85), v238),
                               _mm_mul_ps(_mm_shuffle_ps(v240, v240, 0), v232)),
                             _mm_mul_ps(_mm_shuffle_ps(v240, v240, 170), v237)),
                           _mm_mul_ps(v220, v230)));
                v242 = _mm_mul_ps(v241, v241);
                v243 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v242, v242, 85), _mm_shuffle_ps(v242, v242, 0)),
                         _mm_shuffle_ps(v242, v242, 170));
                v244 = _mm_rsqrt_ps(v243);
                v245 = _mm_add_ps(
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_andnot_ps(
                               _mm_cmple_ps(v243, (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v244, v243), v244)),
                                 _mm_mul_ps(*(__m128 *)_xmm, v244))),
                             _mm_shuffle_ps((__m128)v392, (__m128)v392, 0)),
                           v241),
                         v230);
                v246 = _mm_mul_ps(_mm_shuffle_ps(v245, _mm_unpackhi_ps(v245, query.m_quad), 196), v223);
                v247 = _mm_add_ps(_mm_shuffle_ps(v246, v246, 78), v246);
                v216 = _mm_min_ps(
                         v216,
                         (__m128)_mm_srli_epi32(
                                   _mm_slli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v247, v247, 177), v247), 1u),
                                   1u));
              }
            }
            Next = hkgpConvexHull::getNext(this, Next);
          }
          while ( Next );
          v32 = (hkVector4f *)p;
          v26 = v349;
          v11 = (__m128i)points;
        }
        v248 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v11, 1u), 1u);
        v249 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v216, v248), v362), v248);
        v250 = _mm_cmplt_ps(v249, v248);
        v11 = (__m128i)_mm_or_ps(
                         _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v11, 0x1Fu), 0x1Fu), v249), v250),
                         _mm_andnot_ps(v250, (__m128)v11));
      }
      if ( *(float *)v11.m128i_i32 == 0.0 )
      {
        if ( v32 == array )
          v26 = 0;
        v349 = v26;
        v251 = (48 * v352 + 127) & 0xFFFFFF80;
        v252 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v253 = (v251 + 15) & 0xFFFFFFF0;
        if ( v251 > v252->m_slabSize || (char *)v32 + v253 != v252->m_cur || v252->m_firstNonLifoEnd == v32 )
          hkLifoAllocator::slowBlockFree(v252, (char *)v32, v253);
        else
          v252->m_cur = v32;
        v349 = 0;
        if ( v350 >= 0 )
        {
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            array,
            48 * (v350 & 0x3FFFFFFF));
          v11.m128i_i32[0] = 0;
          goto LABEL_235;
        }
        goto LABEL_141;
      }
      if ( v32 == array )
        v26 = 0;
      v349 = v26;
      v254 = (48 * v352 + 127) & 0xFFFFFF80;
      v255 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v256 = (v254 + 15) & 0xFFFFFFF0;
      if ( v254 > v255->m_slabSize || (char *)v32 + v256 != v255->m_cur || v255->m_firstNonLifoEnd == v32 )
        hkLifoAllocator::slowBlockFree(v255, (char *)v32, v256);
      else
        v255->m_cur = v32;
      v349 = 0;
      if ( v350 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          array,
          48 * (v350 & 0x3FFFFFFF));
      v12 = v356;
      m_quad = v357;
      v10 = v358;
    }
  }
  if ( *(float *)v11.m128i_i32 < 0.0 )
  {
    for ( j = 0;
          j < hkgpConvexHull::getNumPlanes(this);
          v11 = (__m128i)_mm_max_ps(_mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v261, v261, 177), v261), v12), (__m128)v11) )
    {
      v258 = hkgpConvexHull::getPlane(this, j++);
      v259 = _mm_mul_ps(v258->m_quad, m_quad);
      v260 = _mm_shuffle_ps(v259, _mm_unpackhi_ps(v259, v258->m_quad), 196);
      v261 = _mm_add_ps(_mm_shuffle_ps(v260, v260, 78), v260);
    }
    if ( *(float *)v11.m128i_i32 >= 0.0 )
    {
LABEL_141:
      v11.m128i_i32[0] = 0;
      goto LABEL_235;
    }
  }
  v262 = hkgpConvexHull::getNumPlanes(this);
  array = 0i64;
  v349 = 0;
  v263 = v262;
  v350 = 0x80000000;
  v352 = v262;
  if ( v262 )
  {
    v264 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v265 = (hkVector4f *)v264->m_cur;
    v266 = (16 * v263 + 127) & 0xFFFFFF80;
    v267 = (char *)v265 + v266;
    if ( v266 > v264->m_slabSize || v267 > v264->m_end )
      v265 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v264, v266);
    else
      v264->m_cur = v267;
  }
  else
  {
    v265 = 0i64;
  }
  array = v265;
  v350 = v263 | 0x80000000;
  v268 = 0;
  p = v265;
  v269 = hkgpConvexHull::getNumPlanes(this);
  if ( v269 <= 0 )
  {
    v276 = v349;
  }
  else
  {
    do
    {
      v270 = hkgpConvexHull::getPlane(this, v268);
      v271 = v349;
      v272 = _mm_mul_ps(v270->m_quad, m_quad);
      v273 = _mm_shuffle_ps(v272, _mm_unpackhi_ps(v272, v270->m_quad), 196);
      v274 = _mm_add_ps(_mm_shuffle_ps(v273, v273, 78), v273);
      v275 = _mm_shuffle_ps(
               v270->m_quad,
               _mm_unpackhi_ps(
                 v270->m_quad,
                 _mm_sub_ps(
                   _mm_shuffle_ps(v270->m_quad, v270->m_quad, 255),
                   _mm_max_ps((__m128)v11, _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v274, v274, 177), v274), v10)))),
               196);
      if ( v349 == (v350 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
        v271 = v349;
      }
      ++v268;
      array[v271] = (hkVector4f)v275;
      v276 = ++v349;
    }
    while ( v268 < v269 );
  }
  if ( hkgpConvexHull::getDimensions(this) == 2 )
  {
    v277 = hkgpConvexHull::getConfiguration(this);
    v278 = hkgpConvexHull::getProjectionPlane(this);
    hkgpConvexHull::buildFromPlanes(this, array, v276, v278, v277);
  }
  else
  {
    v279 = hkgpConvexHull::getConfiguration(this);
    hkgpConvexHull::buildFromPlanes(this, array, v276, v279);
  }
  v280 = v349;
  v281 = (char *)p;
  if ( p == array )
    v280 = 0;
  v349 = v280;
  v282 = (16 * v352 + 127) & 0xFFFFFF80;
  v283 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v284 = (v282 + 15) & 0xFFFFFFF0;
  if ( v282 > v283->m_slabSize || &v281[v284] != v283->m_cur || v283->m_firstNonLifoEnd == v281 )
    hkLifoAllocator::slowBlockFree(v283, v281, v284);
  else
    v283->m_cur = v281;
  v285 = v350;
  v349 = 0;
  if ( v350 >= 0 )
  {
    m_vertices = array;
LABEL_191:
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, m_vertices, 16 * v285);
  }
LABEL_192:
  v309 = 0;
  if ( *(float *)v11.m128i_i32 < 0.0 )
  {
    points.m_vertices = 0i64;
    points.m_numVertices = 0;
    points.m_striding = 0x80000000;
    hkgpConvexHull::fetchPositions(this, INTERNAL_VERTICES, (hkArray<hkVector4f,hkContainerHeapAllocator> *)&points);
    v310 = 0;
    if ( points.m_numVertices > 0 )
    {
      v311 = (__m128 *)points.m_vertices;
      while ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(*v311, aabbOut.m_max.m_quad), _mm_cmple_ps(aabbOut.m_min.m_quad, *v311))) & 7) == 7 )
      {
        ++v310;
        ++v311;
        if ( v310 >= points.m_numVertices )
          goto LABEL_199;
      }
      v309 = 1;
      v346.m_vertices = positions.m_data->m_quad.m128_f32;
      v346.m_striding = 16;
      v346.m_numVertices = positions.m_size;
      v312 = hkgpConvexHull::getConfiguration(this);
      hkgpConvexHull::build(this, &v346, v312);
    }
LABEL_199:
    if ( !hkgpConvexHull::getNumVertices(this) )
    {
      hkErrStream::hkErrStream(&v355, buf, 512);
      hkOstream::operator<<(
        &v355,
        "The resulting convex hull after shrinking has zero vertices! Reverting to the unshrunk hull.");
      hkError::messageWarning(0xABBAFF14, buf, "GeometryProcessing\\ConvexHull\\hkgpConvexHull.cpp", 860);
      hkOstream::~hkOstream(&v355);
      v346.m_vertices = positions.m_data->m_quad.m128_f32;
      v346.m_striding = 16;
      v346.m_numVertices = positions.m_size;
      v313 = hkgpConvexHull::getConfiguration(this);
      hkgpConvexHull::build(this, &v346, v313);
    }
    points.m_numVertices = 0;
    if ( points.m_striding >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        (void *)points.m_vertices,
        16 * points.m_striding);
    if ( !v309 )
    {
      v314 = hkgpConvexHull::getNumVertices(this);
      if ( v314 > positions.m_size )
      {
        points.m_vertices = 0i64;
        points.m_numVertices = 0;
        points.m_striding = 0x80000000;
        hkgpConvexHull::fetchPositions(this, INTERNAL_VERTICES, (hkArray<hkVector4f,hkContainerHeapAllocator> *)&points);
        m_size = positions.m_size;
        v316 = 0;
        v317 = 0x80000000;
        v318 = 0i64;
        v346.m_vertices = 0i64;
        v346.m_numVertices = 0;
        v319 = 0;
        v346.m_striding = 0x80000000;
        if ( positions.m_size > 0 )
        {
          si128 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
          v321 = points.m_numVertices;
          v322 = 0i64;
          do
          {
            v323 = (__m128)xmmword_141A712A0;
            v324 = si128;
            v325 = 0i64;
            LODWORD(retaddr) = -1;
            if ( v321 > 0 )
            {
              v326 = (unsigned int)v321;
              v327 = points.m_vertices;
              do
              {
                v327 += 4;
                v328 = _mm_sub_ps(positions.m_data[v322].m_quad, *(__m128 *)(v327 - 4));
                v329 = _mm_mul_ps(v328, v328);
                v330 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v329, v329, 85), _mm_shuffle_ps(v329, v329, 0)),
                         _mm_shuffle_ps(v329, v329, 170));
                v331 = (__m128i)_mm_cmplt_ps(v330, v323);
                v323 = _mm_or_ps(_mm_and_ps((__m128)v331, v330), _mm_andnot_ps((__m128)v331, v323));
                v324 = _mm_or_si128(_mm_andnot_si128(v331, v324), _mm_and_si128(v325, v331));
                v325 = _mm_add_epi32((__m128i)xmmword_141A72090, v325);
                --v326;
              }
              while ( v326 );
            }
            LODWORD(retaddr) = v324.m128i_i32[0];
            v332 = v324.m128i_i32[0];
            v333 = 0;
            v334 = 0i64;
            if ( v316 <= 0 )
              goto LABEL_215;
            while ( LODWORD(v318[v334]) != v324.m128i_i32[0] )
            {
              ++v334;
              ++v333;
              if ( v334 >= v316 )
                goto LABEL_215;
            }
            if ( v333 == -1 )
            {
LABEL_215:
              if ( v316 == (v317 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&v346.m_vertices, 4);
                v316 = v346.m_numVertices;
                v318 = v346.m_vertices;
              }
              LODWORD(v318[v316]) = v332;
              m_size = positions.m_size;
              v321 = points.m_numVertices;
              v317 = v346.m_striding;
              v318 = v346.m_vertices;
              v316 = ++v346.m_numVertices;
            }
            ++v319;
            ++v322;
          }
          while ( v319 < m_size );
        }
        v335 = v316;
        v336 = v316;
        if ( v316 )
        {
          LODWORD(retaddr) = 16 * v316;
          v337 = ((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, void **, const float *))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
                   &hkContainerTempAllocator::s_alloc,
                   &retaddr,
                   v318);
          v316 = v346.m_numVertices;
          v318 = v346.m_vertices;
          v338 = (float *)v337;
          v335 = (int)retaddr / 16;
        }
        else
        {
          v338 = 0i64;
        }
        v339 = 0x80000000;
        v340 = 0;
        if ( v335 )
          v339 = v335;
        if ( v316 > 0 )
        {
          v341 = 0i64;
          v342 = v338;
          while ( 1 )
          {
            ++v340;
            v343 = 2i64 * SLODWORD(v318[v341++]);
            v342 += 4;
            *((_OWORD *)v342 - 1) = *(_OWORD *)&points.m_vertices[2 * v343];
            if ( v340 >= v346.m_numVertices )
              break;
            v318 = v346.m_vertices;
          }
        }
        v354.m_vertices = v338;
        v354.m_numVertices = v336;
        v354.m_striding = 16;
        v344 = hkgpConvexHull::getConfiguration(this);
        hkgpConvexHull::build(this, &v354, v344);
        if ( v339 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v338, 16 * v339);
        v346.m_numVertices = 0;
        if ( v346.m_striding >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            (void *)v346.m_vertices,
            4 * v346.m_striding);
        v346.m_vertices = 0i64;
        v346.m_striding = 0x80000000;
        points.m_numVertices = 0;
        if ( points.m_striding >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            (void *)points.m_vertices,
            16 * points.m_striding);
      }
    }
  }
  hkgpConvexHull::buildMassProperties(this, (hkResult *)&retaddr);
  hkgpConvexHull::buildIndices(this, 0.99998999, 0);
LABEL_235:
  positions.m_size = 0;
  if ( positions.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      positions.m_data,
      16 * positions.m_capacityAndFlags);
  return *(float *)v11.m128i_i32;
}      v342 += 4;
            *((_OWORD *)v342 - 1) = *(_OWORD *)&points.m_vertices[2 * v343];
            if ( v340 >= v346.m_numVertices )
              break;
            v318 = v346.m_vertices;
          }
        }
        v354.m_vertices = v338;
        v354.m_numVertices = v336;
        v354.m_striding = 16;
        v344 = hkgpConvexHull::getConfiguration(this);
        hkgpConvexHull::build(this, &v354, v344);
        if ( v339 >= 0 )
          hkContainerTempAllocator::

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
  hkgpConvexHullImpl::buildMassProperties<hkgpConvexHullImpl::PositionAsTransform>(this->m_data, result);
  return result;
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
  hkgpConvexHullImpl *m_data; // rax

  m_data = this->m_data;
  if ( !m_data->m_hasMassProperties || m_data->m_degeneratedMassProperties )
  {
    result->m_bool = 0;
    return result;
  }
  else
  {
    result->m_bool = 1;
    return result;
  }
}

// File Line: 962
// RVA: 0xCAC990
hkBool *__fastcall hkgpConvexHull::isVertexUsed(hkgpConvexHull *this, hkBool *result, hkVector4f *point)
{
  hkgpConvexHullImpl *m_data; // rax
  hkgpConvexHullImpl::Vertex *m_used; // rcx
  __m128 v5; // xmm3
  __m128 v6; // xmm2
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  unsigned __int64 v11; // [rsp+20h] [rbp-28h]

  m_data = this->m_data;
  m_used = m_data->m_mesh.m_vertices.m_used;
  v5 = _mm_mul_ps(_mm_sub_ps(point->m_quad, m_data->m_origin.m_quad), m_data->m_scale.m_quad);
  v6 = _mm_cmplt_ps(v5, (__m128)_xmm);
  v7 = _mm_max_ps(
         (__m128)_xmm_c6000000c6000000c6000000c6000000,
         _mm_or_ps(_mm_andnot_ps(v6, (__m128)_xmm), _mm_and_ps(v6, v5)));
  v8 = _mm_cmplt_ps(v7, (__m128)0i64);
  v9 = _mm_or_ps(
         _mm_andnot_ps(v8, _mm_add_ps(v7, (__m128)xmmword_141A711B0)),
         _mm_and_ps(_mm_sub_ps(v7, (__m128)xmmword_141A711B0), v8));
  v11 = _mm_xor_si128(
          (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v9),
          _mm_cvttps_epi32(v9)).m128i_u64[0];
  if ( m_used )
  {
    while ( v11 != *(_QWORD *)m_used->m_x )
    {
      m_used = m_used->m_next;
      if ( !m_used )
        goto LABEL_5;
    }
    result->m_bool = 1;
    return result;
  }
  else
  {
LABEL_5:
    result->m_bool = 0;
    return result;
  }
}

// File Line: 972
// RVA: 0xCACA60
hkBool *__fastcall hkgpConvexHull::isPointInside(
        hkgpConvexHull *this,
        hkBool *result,
        hkVector4f *point,
        hkBool usePlanes,
        float epsilon)
{
  result->m_bool = hkgpConvexHullImpl::isPointInside(this->m_data, point, usePlanes.m_bool != 0, epsilon);
  return result;
}

// File Line: 977
// RVA: 0xCACAA0
hkBool *__fastcall hkgpConvexHull::clipLine(
        hkgpConvexHull *this,
        hkBool *result,
        hkVector4f *a,
        hkVector4f *b,
        float *t0,
        float *t1,
        float epsilon)
{
  result->m_bool = hkgpConvexHullImpl::clipLine(this->m_data, a, b, t0, t1, epsilon);
  return result;
}

// File Line: 982
// RVA: 0xCACAF0
hkSimdFloat32 *__fastcall hkgpConvexHull::maximumDistanceToPlanes(
        hkgpConvexHull *this,
        hkSimdFloat32 *result,
        hkVector4f *point,
        int *planeIndexOut)
{
  __m128i si128; // xmm6
  int v9; // ebp
  __m128i v10; // xmm7
  hkVector4f *Plane; // rax
  __m128 v12; // xmm2
  __m128 v13; // xmm2
  __m128 v14; // xmm0
  __m128 v15; // xmm2
  __m128i v16; // xmm3
  hkSimdFloat32 v17; // xmm1
  __m128i v18; // xmm0
  __m128i v19; // xmm3
  hkSimdFloat32 *v20; // rax

  si128 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
  v9 = 0;
  v10 = 0i64;
  for ( *result = (hkSimdFloat32)xmmword_141A712F0;
        v9 < hkgpConvexHull::getNumPlanes(this);
        si128 = _mm_or_si128(_mm_andnot_si128(v18, si128), v19) )
  {
    Plane = hkgpConvexHull::getPlane(this, v9++);
    v12 = _mm_mul_ps(point->m_quad, Plane->m_quad);
    v13 = _mm_shuffle_ps(v12, _mm_unpackhi_ps(v12, Plane->m_quad), 196);
    v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
    v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14);
    v16 = (__m128i)_mm_cmplt_ps(result->m_real, v15);
    v17.m_real = _mm_or_ps(_mm_andnot_ps((__m128)v16, result->m_real), _mm_and_ps((__m128)v16, v15));
    v18 = v16;
    v19 = _mm_and_si128(v16, v10);
    v10 = _mm_add_epi32(v10, (__m128i)xmmword_141A72090);
    *result = (hkSimdFloat32)v17.m_real;
  }
  v20 = result;
  if ( planeIndexOut )
    *planeIndexOut = si128.m128i_i32[0];
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
hkAabb *__fastcall hkgpConvexHull::getBoundingBox(
        hkgpConvexHull *this,
        hkAabb *result,
        int inputs,
        float scale,
        float radialScale)
{
  hkgpConvexHullImpl *m_data; // rsi
  __int64 v9; // rdi
  hkgpConvexHull::Vertex *FirstVertex; // rax
  bool v11; // zf
  hkgpConvexHull::Vertex *v12; // rbx
  hkVector4f *SourcePosition; // rax
  hkgpConvexHull::Vertex *Next; // rbx
  __m128 m_quad; // xmm6
  hkVector4f *v16; // rax
  hkgpConvexHull::Vertex *i; // rbx
  hkVector4f *Position; // rax
  __m128 v19; // xmm1
  hkVector4f v20; // xmm1
  hkVector4f v21; // xmm6
  hkVector4f v22; // xmm5
  __m128 v23; // xmm1
  __m128 v24; // xmm1
  __m128 v25; // xmm4
  __m128 v26; // xmm1
  __m128 v27; // xmm0
  __m128 v28; // xmm0
  __m128 v29; // xmm5
  __m128 v30; // xmm1
  hkVector4f resulta; // [rsp+20h] [rbp-48h] BYREF

  m_data = this->m_data;
  v9 = inputs;
  if ( (_mm_movemask_ps(_mm_cmple_ps(m_data->m_boundingBoxes[v9].m_max.m_quad, m_data->m_boundingBoxes[v9].m_min.m_quad)) & 7) != 0
    && hkgpConvexHull::getNumVertices(this) > 0 )
  {
    FirstVertex = hkgpConvexHull::getFirstVertex(this);
    v11 = inputs == 0;
    v12 = FirstVertex;
    if ( v11 )
    {
      SourcePosition = hkgpConvexHull::getSourcePosition(this, FirstVertex);
      m_data->m_boundingBoxes[v9].m_min = (hkVector4f)SourcePosition->m_quad;
      m_data->m_boundingBoxes[v9].m_max = (hkVector4f)SourcePosition->m_quad;
      Next = hkgpConvexHull::getNext(this, v12);
      if ( Next )
      {
        m_quad = m_data->m_boundingBoxes[v9].m_max.m_quad;
        do
        {
          v16 = hkgpConvexHull::getSourcePosition(this, Next);
          m_data->m_boundingBoxes[v9].m_min.m_quad = _mm_min_ps(m_data->m_boundingBoxes[v9].m_min.m_quad, v16->m_quad);
          m_quad = _mm_max_ps(m_quad, v16->m_quad);
          m_data->m_boundingBoxes[v9].m_max.m_quad = m_quad;
          Next = hkgpConvexHull::getNext(this, Next);
        }
        while ( Next );
      }
    }
    else
    {
      m_data->m_boundingBoxes[v9].m_min = (hkVector4f)hkgpConvexHull::getPosition(this, &resulta, FirstVertex)->m_quad;
      m_data->m_boundingBoxes[v9].m_max = (hkVector4f)hkgpConvexHull::getPosition(this, &resulta, v12)->m_quad;
      for ( i = hkgpConvexHull::getNext(this, v12); i; i = hkgpConvexHull::getNext(this, i) )
      {
        Position = hkgpConvexHull::getPosition(this, &resulta, i);
        v19 = m_data->m_boundingBoxes[v9].m_max.m_quad;
        m_data->m_boundingBoxes[v9].m_min.m_quad = _mm_min_ps(
                                                     m_data->m_boundingBoxes[v9].m_min.m_quad,
                                                     Position->m_quad);
        m_data->m_boundingBoxes[v9].m_max.m_quad = _mm_max_ps(v19, Position->m_quad);
      }
    }
  }
  if ( scale == 1.0 && radialScale <= 0.0 )
  {
    v20.m_quad = (__m128)m_data->m_boundingBoxes[v9].m_max;
    result->m_min = m_data->m_boundingBoxes[v9].m_min;
    result->m_max = (hkVector4f)v20.m_quad;
  }
  else
  {
    v21.m_quad = (__m128)m_data->m_boundingBoxes[v9].m_min;
    v22.m_quad = (__m128)m_data->m_boundingBoxes[v9].m_max;
    if ( radialScale > 0.0 )
    {
      v23 = _mm_sub_ps(v22.m_quad, v21.m_quad);
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
                _mm_cmple_ps(v25, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                    _mm_mul_ps(*(__m128 *)_xmm, v26)),
                  v25)));
      v21.m_quad = _mm_sub_ps(v21.m_quad, v27);
      v22.m_quad = _mm_add_ps(v22.m_quad, v27);
    }
    if ( scale != 1.0 )
    {
      v28 = v22.m_quad;
      v29 = _mm_mul_ps(_mm_add_ps(v22.m_quad, v21.m_quad), (__m128)xmmword_141A711B0);
      v30 = _mm_mul_ps(
              _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(scale), (__m128)LODWORD(scale), 0), (__m128)xmmword_141A711B0),
              _mm_sub_ps(v28, v21.m_quad));
      v21.m_quad = _mm_sub_ps(v29, v30);
      v22.m_quad = _mm_add_ps(v29, v30);
    }
    result->m_min = (hkVector4f)v21.m_quad;
    result->m_max = (hkVector4f)v22.m_quad;
  }
  return result;
}

// File Line: 1095
// RVA: 0xCACEF0
void __fastcall hkgpConvexHull::getOrientedBoundingBox(
        hkgpConvexHull *this,
        hkVector4f *halfExtents,
        hkTransformf *worldTransform)
{
  hkgpConvexHullImpl::getOrientedBoundingBox(this->m_data, halfExtents, worldTransform);
}

// File Line: 1100
// RVA: 0xCACF00
void __fastcall hkgpConvexHull::getOrientedRectangle(
        hkgpConvexHull *this,
        hkVector4f *projectionPlane,
        hkVector4f *halfExtents,
        hkTransformf *worldTransform)
{
  hkSimdFloat32 result; // [rsp+30h] [rbp-18h] BYREF

  hkgpConvexHullImpl::getOrientedRectangle(this->m_data, &result, projectionPlane, halfExtents, worldTransform);
}

// File Line: 1105
// RVA: 0xCACF30
hkVector4f *__fastcall hkgpConvexHull::getProjectionAxis(hkgpConvexHull *this, hkVector4f *result)
{
  hkVector4f *v2; // rax

  v2 = result;
  *result = this->m_data->m_projectionAxis;
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
  hkgpConvexHullImpl *m_data; // rdi
  hkOstream *v3; // rax
  hkOstream *v4; // rax
  hkErrStream v6; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  m_data = this->m_data;
  if ( m_data->m_hasIndexing )
    return (unsigned int)m_data->m_planes.m_size;
  hkErrStream::hkErrStream(&v6, buf, 512);
  v3 = hkOstream::operator<<(&v6, "No index available (");
  v4 = hkOstream::operator<<(v3, m_data->m_uid);
  hkOstream::operator<<(v4, ") hkgpConvexHull::buildIndices need to be called before this operation.");
  if ( (unsigned int)hkError::messageError(
                       0x79F9D886u,
                       buf,
                       "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                       358) )
    __debugbreak();
  hkOstream::~hkOstream(&v6);
  return (unsigned int)this->m_data->m_planes.m_size;
}

// File Line: 1121
// RVA: 0xCAD040
hkVector4f *__fastcall hkgpConvexHull::getPlane(hkgpConvexHull *this, int index)
{
  hkgpConvexHullImpl *m_data; // rdi
  __int64 v3; // rsi
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  hkErrStream v8; // [rsp+20h] [rbp-228h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  m_data = this->m_data;
  v3 = index;
  if ( !m_data->m_hasIndexing )
  {
    hkErrStream::hkErrStream(&v8, buf, 512);
    v5 = hkOstream::operator<<(&v8, "No index available (");
    v6 = hkOstream::operator<<(v5, m_data->m_uid);
    hkOstream::operator<<(v6, ") hkgpConvexHull::buildIndices need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         0x79F9D886u,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         358) )
      __debugbreak();
    hkOstream::~hkOstream(&v8);
  }
  return &this->m_data->m_planes.m_data[v3];
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
  hkgpConvexHullImpl *m_data; // rdi
  hkOstream *v4; // rax
  hkOstream *v5; // rax
  hkErrStream v7; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  m_data = this->m_data;
  if ( m_data->m_hasIndexing )
    return *(unsigned int *)&vertex[52];
  hkErrStream::hkErrStream(&v7, buf, 512);
  v4 = hkOstream::operator<<(&v7, "No index available (");
  v5 = hkOstream::operator<<(v4, m_data->m_uid);
  hkOstream::operator<<(v5, ") hkgpConvexHull::buildIndices need to be called before this operation.");
  if ( (unsigned int)hkError::messageError(
                       0x79F9D886u,
                       buf,
                       "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                       358) )
    __debugbreak();
  hkOstream::~hkOstream(&v7);
  return *(unsigned int *)&vertex[52];
}

// File Line: 1143
// RVA: 0xCAD1E0
hkgpConvexHull::Vertex *__fastcall hkgpConvexHull::getNext(hkgpConvexHull *this, hkgpConvexHull::Vertex *vertex)
{
  return *(hkgpConvexHull::Vertex **)vertex;
}

// File Line: 1148
// RVA: 0xCAD1F0
hkVector4f *__fastcall hkgpConvexHull::getPosition(
        hkgpConvexHull *this,
        hkVector4f *result,
        hkgpConvexHull::Vertex *vertex)
{
  hkgpConvexHullImpl *m_data; // rax
  __m128i v4; // xmm0
  hkVector4f v5; // xmm1
  hkVector4f *v6; // rax

  m_data = this->m_data;
  v4 = (__m128i)_mm_cvtepi32_ps(
                  _mm_unpacklo_epi32(
                    _mm_unpacklo_epi32(
                      _mm_cvtsi32_si128(*(_DWORD *)&vertex[32]),
                      _mm_cvtsi32_si128(*(_DWORD *)&vertex[40])),
                    _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(_DWORD *)&vertex[36]), _mm_cvtsi32_si128(0))));
  *result = (hkVector4f)v4;
  v5.m_quad = _mm_add_ps(
                _mm_mul_ps((__m128)_mm_srli_si128(_mm_slli_si128(v4, 4), 4), m_data->m_scaleInv.m_quad),
                m_data->m_origin.m_quad);
  v6 = result;
  *result = (hkVector4f)v5.m_quad;
  return v6;
}

// File Line: 1153
// RVA: 0xCAD250
hkgpConvexHull::Vertex *__fastcall hkgpConvexHull::getSourcePosition(
        hkgpConvexHull *this,
        hkgpConvexHull::Vertex *vertex)
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
  hkgpConvexHullImpl *m_data; // rdi
  hkOstream *v4; // rax
  hkOstream *v5; // rax
  hkErrStream v7; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  m_data = this->m_data;
  if ( m_data->m_hasIndexing )
    return *(unsigned int *)&triangle[100];
  hkErrStream::hkErrStream(&v7, buf, 512);
  v4 = hkOstream::operator<<(&v7, "No index available (");
  v5 = hkOstream::operator<<(v4, m_data->m_uid);
  hkOstream::operator<<(v5, ") hkgpConvexHull::buildIndices need to be called before this operation.");
  if ( (unsigned int)hkError::messageError(
                       0x79F9D886u,
                       buf,
                       "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                       358) )
    __debugbreak();
  hkOstream::~hkOstream(&v7);
  return *(unsigned int *)&triangle[100];
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
  hkgpConvexHullImpl *m_data; // rdi
  hkOstream *v4; // rax
  hkOstream *v5; // rax
  hkErrStream v7; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  m_data = this->m_data;
  if ( m_data->m_hasIndexing )
    return *(unsigned int *)&triangle[88];
  hkErrStream::hkErrStream(&v7, buf, 512);
  v4 = hkOstream::operator<<(&v7, "No index available (");
  v5 = hkOstream::operator<<(v4, m_data->m_uid);
  hkOstream::operator<<(v5, ") hkgpConvexHull::buildIndices need to be called before this operation.");
  if ( (unsigned int)hkError::messageError(
                       0x79F9D886u,
                       buf,
                       "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                       358) )
    __debugbreak();
  hkOstream::~hkOstream(&v7);
  return *(unsigned int *)&triangle[88];
}

// File Line: 1185
// RVA: 0xCAD410
hkVector4f *__fastcall hkgpConvexHull::getPlaneEquation(
        hkgpConvexHull *this,
        hkVector4f *result,
        hkgpConvexHull::Triangle *triangle)
{
  hkgpConvexHull::Vertex *Vertex; // rax
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

  Vertex = hkgpConvexHull::getVertex(this, triangle, 0);
  v7 = *(__m128 *)hkgpConvexHull::getSourcePosition(this, Vertex);
  v8 = hkgpConvexHull::getVertex(this, triangle, 1);
  v9 = _mm_sub_ps(*(__m128 *)hkgpConvexHull::getSourcePosition(this, v8), v7);
  v10 = hkgpConvexHull::getVertex(this, triangle, 2);
  v11 = *(__m128 *)hkgpConvexHull::getSourcePosition(this, v10);
  v12 = result;
  v13 = _mm_sub_ps(v11, v7);
  v14 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v9), _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v13));
  v15 = _mm_shuffle_ps(v14, v14, 201);
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_rsqrt_ps(v17);
  v19 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v17, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
              _mm_mul_ps(*(__m128 *)_xmm, v18))),
          v15);
  v20 = _mm_mul_ps(v7, v19);
  result->m_quad = _mm_shuffle_ps(
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
hkgpConvexHull::Vertex *__fastcall hkgpConvexHull::getVertex(
        hkgpConvexHull *this,
        hkgpConvexHull::Triangle *triangle,
        int index)
{
  return *(hkgpConvexHull::Vertex **)&triangle[8 * index + 16];
}

// File Line: 1202
// RVA: 0xCAD570
hkgpConvexHull::Triangle *__fastcall hkgpConvexHull::getNeighbour(
        hkgpConvexHull *this,
        hkgpConvexHull::Triangle *triangle,
        int index)
{
  return (hkgpConvexHull::Triangle *)(*(_QWORD *)&triangle[8 * index + 40] & 0xFFFFFFFFFFFFFFFCui64);
}

// File Line: 1209
// RVA: 0xCAD590
hkSimdFloat32 *__fastcall hkgpConvexHull::getWidth(hkgpConvexHull *this, hkSimdFloat32 *result, hkVector4f *direction)
{
  hkSimdFloat32 *MinimumDistanceFromPlane; // rbx
  __m128 m_real; // xmm0
  hkSimdFloat32 *v7; // rax
  hkVector4f plane; // [rsp+20h] [rbp-38h] BYREF
  hkSimdFloat32 resulta; // [rsp+30h] [rbp-28h] BYREF
  hkSimdFloat32 v10; // [rsp+40h] [rbp-18h] BYREF

  plane.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)direction->m_quad, 4), 4);
  MinimumDistanceFromPlane = hkgpConvexHull::getMinimumDistanceFromPlane(this, &resulta, &plane);
  m_real = hkgpConvexHull::getMaximumDistanceFromPlane(this, &v10, &plane)->m_real;
  v7 = result;
  result->m_real = _mm_sub_ps(m_real, MinimumDistanceFromPlane->m_real);
  return v7;
}

// File Line: 1215
// RVA: 0xCAD600
hkSimdFloat32 *__fastcall hkgpConvexHull::getMinWidth(hkgpConvexHull *this, hkSimdFloat32 *result)
{
  hkSimdFloat32 *v3; // rax
  hkSimdFloat32 minWidth; // [rsp+20h] [rbp-28h] BYREF
  hkSimdFloat32 maxWidth; // [rsp+30h] [rbp-18h] BYREF

  hkgpConvexHull::getWidthBounds(this, &minWidth, &maxWidth);
  v3 = result;
  *result = (hkSimdFloat32)minWidth.m_real;
  return v3;
}

// File Line: 1221
// RVA: 0xCAD630
hkSimdFloat32 *__fastcall hkgpConvexHull::getMaxWidth(hkgpConvexHull *this, hkSimdFloat32 *result)
{
  hkSimdFloat32 *v3; // rax
  hkSimdFloat32 minWidth; // [rsp+20h] [rbp-28h] BYREF
  hkSimdFloat32 maxWidth; // [rsp+30h] [rbp-18h] BYREF

  hkgpConvexHull::getWidthBounds(this, &minWidth, &maxWidth);
  v3 = result;
  *result = (hkSimdFloat32)maxWidth.m_real;
  return v3;
}

// File Line: 1227
// RVA: 0xCAD660
void __fastcall hkgpConvexHull::getWidthBounds(hkgpConvexHull *this, hkSimdFloat32 *minWidth, hkSimdFloat32 *maxWidth)
{
  __m128 m_quad; // xmm6
  int v7; // r14d
  hkSimdFloat32 v8; // xmm0
  __int128 *v9; // rbx
  __m128 v10; // xmm0
  __m128 v11; // xmm0
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  hkVector4f v15; // [rsp+20h] [rbp-68h] BYREF
  hkTransformf v16; // [rsp+30h] [rbp-58h] BYREF

  v15.m_quad = 0i64;
  hkgpConvexHull::getOrientedBoundingBox(this, &v15, &v16);
  m_quad = v15.m_quad;
  v7 = 1;
  v8.m_real = _mm_shuffle_ps(v15.m_quad, v15.m_quad, 0);
  *minWidth = (hkSimdFloat32)v8.m_real;
  *maxWidth = (hkSimdFloat32)v8.m_real;
  if ( (int)hkgpConvexHull::getDimensions(this) > 1 )
  {
    v9 = &xmmword_141687F10;
    do
    {
      v10 = (__m128)*v9;
      ++v7;
      ++v9;
      v11 = _mm_and_ps(v10, m_quad);
      v12 = _mm_or_ps(_mm_shuffle_ps(v11, v11, 78), v11);
      minWidth->m_real = _mm_min_ps(minWidth->m_real, _mm_or_ps(_mm_shuffle_ps(v12, v12, 177), v12));
      v13 = _mm_and_ps(*((__m128 *)v9 - 1), m_quad);
      v14 = _mm_or_ps(_mm_shuffle_ps(v13, v13, 78), v13);
      maxWidth->m_real = _mm_max_ps(maxWidth->m_real, _mm_or_ps(_mm_shuffle_ps(v14, v14, 177), v14));
    }
    while ( v7 < (int)hkgpConvexHull::getDimensions(this) );
  }
}

// File Line: 1241
// RVA: 0xCAD760
hkSimdFloat32 *__fastcall hkgpConvexHull::getMinimumDistanceFromPlane(
        hkgpConvexHull *this,
        hkSimdFloat32 *result,
        hkVector4f *plane)
{
  hkSimdFloat32 *v5; // rax
  __m128 v6; // xmm1
  hkVector4f vertexOut; // [rsp+20h] [rbp-28h] BYREF
  hkVector4f direction; // [rsp+30h] [rbp-18h] BYREF

  vertexOut.m_quad = 0i64;
  direction.m_quad = _mm_xor_ps(
                       (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                       plane->m_quad);
  hkgpConvexHull::getSupportingVertex(this, &direction, &vertexOut);
  v5 = result;
  v6 = _mm_mul_ps(plane->m_quad, vertexOut.m_quad);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)),
                       _mm_shuffle_ps(v6, v6, 170)),
                     _mm_shuffle_ps(plane->m_quad, plane->m_quad, 255));
  return v5;
}

// File Line: 1248
// RVA: 0xCAD7F0
hkSimdFloat32 *__fastcall hkgpConvexHull::getMaximumDistanceFromPlane(
        hkgpConvexHull *this,
        hkSimdFloat32 *result,
        hkVector4f *plane)
{
  hkSimdFloat32 *v5; // rax
  __m128 v6; // xmm1
  hkVector4f vertexOut; // [rsp+20h] [rbp-18h] BYREF

  vertexOut.m_quad = 0i64;
  hkgpConvexHull::getSupportingVertex(this, plane, &vertexOut);
  v5 = result;
  v6 = _mm_mul_ps(plane->m_quad, vertexOut.m_quad);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)),
                       _mm_shuffle_ps(v6, v6, 170)),
                     _mm_shuffle_ps(plane->m_quad, plane->m_quad, 255));
  return v5;
}

// File Line: 1255
// RVA: 0xCAD860
void __fastcall hkgpConvexHull::getSupportingVertex(hkgpConvexHull *this, hkVector4f *direction, hkVector4f *vertexOut)
{
  hkgpConvexHullImpl *m_data; // rbx
  int m_numUsed; // edi
  int m_size; // eax
  hkVector4f *v8; // r9
  hkgpConvexHullImpl::Vertex *m_used; // rcx
  hkVector4f *v10; // rax
  hkArray<hkVector4f,hkContainerHeapAllocator> array[2]; // [rsp+30h] [rbp-28h] BYREF
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  m_data = this->m_data;
  if ( !m_data->m_supportCache.m_size )
  {
    m_numUsed = m_data->m_mesh.m_vertices.m_numUsed;
    array[0].m_capacityAndFlags = 0x80000000;
    m_size = 0;
    v8 = 0i64;
    array[0].m_data = 0i64;
    array[0].m_size = 0;
    if ( m_numUsed > 0 )
    {
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array[0].m_data, m_numUsed, 16);
      m_size = array[0].m_size;
      v8 = array[0].m_data;
    }
    m_used = m_data->m_mesh.m_vertices.m_used;
    for ( array[0].m_size = m_numUsed + m_size; m_used; m_used = m_used->m_next )
    {
      v10 = v8++;
      *v10 = m_used->m_source;
    }
    hkGeometryProcessing::buildTransposedArray(array, &m_data->m_supportCache);
    array[0].m_size = 0;
    if ( array[0].m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        array[0].m_data,
        16 * array[0].m_capacityAndFlags);
  }
  hkGeometryProcessing::getSupportingVertex(&m_data->m_supportCache, direction, vertexOut);
}

// File Line: 1260
// RVA: 0xCAD970
void __fastcall hkgpConvexHull::getNearestVertex(
        hkgpConvexHull *this,
        hkgpConvexHull::Inputs inputs,
        hkVector4f *point,
        hkVector4f *vertexOut)
{
  float v4; // xmm4_4
  __m128 m_quad; // xmm0
  hkgpConvexHullImpl *v6; // rax
  hkgpConvexHullImpl::Vertex *j; // rax
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm1
  float v11; // xmm2_4
  hkgpConvexHullImpl *m_data; // rdx
  hkgpConvexHullImpl::Vertex *i; // rax
  __m128 v14; // xmm5
  __m128 v15; // xmm6
  __m128i v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm1
  float v19; // xmm2_4

  v4 = 3.40282e38;
  m_quad = point->m_quad;
  if ( inputs )
  {
    m_data = this->m_data;
    *vertexOut = (hkVector4f)m_quad;
    for ( i = m_data->m_mesh.m_vertices.m_used; i; i = i->m_next )
    {
      v14 = m_data->m_scaleInv.m_quad;
      v15 = m_data->m_origin.m_quad;
      v16 = _mm_unpacklo_epi32(
              _mm_unpacklo_epi32(_mm_cvtsi32_si128(i->m_x[0]), _mm_cvtsi32_si128(i->m_x[2])),
              _mm_unpacklo_epi32(_mm_cvtsi32_si128(i->m_x[1]), _mm_cvtsi32_si128(0)));
      v17 = _mm_sub_ps(
              point->m_quad,
              _mm_add_ps(
                _mm_mul_ps((__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_cvtepi32_ps(v16), 4), 4), v14),
                v15));
      v18 = _mm_mul_ps(v17, v17);
      v19 = (float)(_mm_shuffle_ps(v18, v18, 85).m128_f32[0] + _mm_shuffle_ps(v18, v18, 0).m128_f32[0])
          + _mm_shuffle_ps(v18, v18, 170).m128_f32[0];
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
    *vertexOut = (hkVector4f)m_quad;
    for ( j = v6->m_mesh.m_vertices.m_used; j; j = j->m_next )
    {
      v8 = j->m_source.m_quad;
      v9 = _mm_sub_ps(point->m_quad, v8);
      v10 = _mm_mul_ps(v9, v9);
      v11 = (float)(_mm_shuffle_ps(v10, v10, 85).m128_f32[0] + _mm_shuffle_ps(v10, v10, 0).m128_f32[0])
          + _mm_shuffle_ps(v10, v10, 170).m128_f32[0];
      if ( v11 < v4 )
      {
        v4 = v11;
        *vertexOut = (hkVector4f)v8;
      }
    }
  }
}

// File Line: 1268
// RVA: 0xCADAA0
void __fastcall hkgpConvexHull::getFarthestVertex(
        hkgpConvexHull *this,
        hkgpConvexHull::Inputs inputs,
        hkVector4f *point,
        hkVector4f *vertexOut)
{
  __m128 m_quad; // xmm0
  float v5; // xmm4_4
  hkgpConvexHullImpl *v6; // rax
  hkgpConvexHullImpl::Vertex *j; // rax
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm1
  float v11; // xmm2_4
  hkgpConvexHullImpl *m_data; // rdx
  hkgpConvexHullImpl::Vertex *i; // rax
  __m128 v14; // xmm5
  __m128 v15; // xmm6
  __m128i v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm1
  float v19; // xmm2_4

  m_quad = point->m_quad;
  v5 = 0.0;
  if ( inputs )
  {
    m_data = this->m_data;
    *vertexOut = (hkVector4f)m_quad;
    for ( i = m_data->m_mesh.m_vertices.m_used; i; i = i->m_next )
    {
      v14 = m_data->m_scaleInv.m_quad;
      v15 = m_data->m_origin.m_quad;
      v16 = _mm_unpacklo_epi32(
              _mm_unpacklo_epi32(_mm_cvtsi32_si128(i->m_x[0]), _mm_cvtsi32_si128(i->m_x[2])),
              _mm_unpacklo_epi32(_mm_cvtsi32_si128(i->m_x[1]), _mm_cvtsi32_si128(0)));
      v17 = _mm_sub_ps(
              point->m_quad,
              _mm_add_ps(
                _mm_mul_ps((__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_cvtepi32_ps(v16), 4), 4), v14),
                v15));
      v18 = _mm_mul_ps(v17, v17);
      v19 = (float)(_mm_shuffle_ps(v18, v18, 85).m128_f32[0] + _mm_shuffle_ps(v18, v18, 0).m128_f32[0])
          + _mm_shuffle_ps(v18, v18, 170).m128_f32[0];
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
    *vertexOut = (hkVector4f)m_quad;
    for ( j = v6->m_mesh.m_vertices.m_used; j; j = j->m_next )
    {
      v8 = j->m_source.m_quad;
      v9 = _mm_sub_ps(point->m_quad, v8);
      v10 = _mm_mul_ps(v9, v9);
      v11 = (float)(_mm_shuffle_ps(v10, v10, 85).m128_f32[0] + _mm_shuffle_ps(v10, v10, 0).m128_f32[0])
          + _mm_shuffle_ps(v10, v10, 170).m128_f32[0];
      if ( v11 > v5 )
      {
        v5 = v11;
        *vertexOut = (hkVector4f)v8;
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
  hkgpConvexHullImpl *m_data; // rsi
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  hkSimdFloat32 *v7; // rax
  hkErrStream v8; // [rsp+20h] [rbp-228h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  m_data = this->m_data;
  if ( !m_data->m_hasMassProperties )
  {
    hkErrStream::hkErrStream(&v8, buf, 512);
    v5 = hkOstream::operator<<(&v8, "No mass properties available (");
    v6 = hkOstream::operator<<(v5, m_data->m_uid);
    hkOstream::operator<<(v6, ") hkgpConvexHull::buildMassProperties need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         0x79F9D887u,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         366) )
      __debugbreak();
    hkOstream::~hkOstream(&v8);
  }
  v7 = result;
  *result = this->m_data->m_volume;
  return v7;
}

// File Line: 1287
// RVA: 0xCADD60
hkSimdFloat32 *__fastcall hkgpConvexHull::getSurfaceArea(hkgpConvexHull *this, hkSimdFloat32 *result)
{
  hkgpConvexHullImpl *m_data; // rsi
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  hkSimdFloat32 *v7; // rax
  hkErrStream v8; // [rsp+20h] [rbp-228h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  m_data = this->m_data;
  if ( !m_data->m_hasMassProperties )
  {
    hkErrStream::hkErrStream(&v8, buf, 512);
    v5 = hkOstream::operator<<(&v8, "No mass properties available (");
    v6 = hkOstream::operator<<(v5, m_data->m_uid);
    hkOstream::operator<<(v6, ") hkgpConvexHull::buildMassProperties need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         0x79F9D887u,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         366) )
      __debugbreak();
    hkOstream::~hkOstream(&v8);
  }
  v7 = result;
  *result = this->m_data->m_surface;
  return v7;
}

// File Line: 1293
// RVA: 0xCADBE0
hkSimdFloat32 *__fastcall hkgpConvexHull::getEdgeLengths(hkgpConvexHull *this, hkSimdFloat32 *result)
{
  hkgpConvexHullImpl::getEdgeLengths(this->m_data, result);
  return result;
}

// File Line: 1298
// RVA: 0xCADC10
hkSimdFloat32 *__fastcall hkgpConvexHull::getSphericity(hkgpConvexHull *this, hkSimdFloat32 *result)
{
  hkSimdFloat32 *Volume; // rax
  float v5; // xmm0_4
  hkSimdFloat32 v6; // xmm0
  hkSimdFloat32 *v7; // rax
  hkSimdFloat32 resulta; // [rsp+20h] [rbp-18h] BYREF

  Volume = hkgpConvexHull::getVolume(this, &resulta);
  v5 = powf(Volume->m_real.m128_f32[0], 0.66666669);
  result->m_real = _mm_mul_ps(
                     _mm_shuffle_ps((__m128)LODWORD(FLOAT_4_8359756), (__m128)LODWORD(FLOAT_4_8359756), 0),
                     _mm_shuffle_ps((__m128)LODWORD(v5), (__m128)LODWORD(v5), 0));
  v6.m_real = _mm_div_ps(result->m_real, hkgpConvexHull::getSurfaceArea(this, &resulta)->m_real);
  v7 = result;
  *result = (hkSimdFloat32)v6.m_real;
  return v7;
}

// File Line: 1308
// RVA: 0xCADE20
void __fastcall hkgpConvexHull::getLocalInertia(
        hkgpConvexHull *this,
        hkTransformf *inertiaSpace,
        hkVector4f *inertiaDiagonal)
{
  hkgpConvexHullImpl *m_data; // rsi
  hkOstream *v7; // rax
  hkOstream *v8; // rax
  hkgpConvexHullImpl *v9; // rax
  hkErrStream v10; // [rsp+20h] [rbp-228h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  m_data = this->m_data;
  if ( !m_data->m_hasMassProperties )
  {
    hkErrStream::hkErrStream(&v10, buf, 512);
    v7 = hkOstream::operator<<(&v10, "No mass properties available (");
    v8 = hkOstream::operator<<(v7, m_data->m_uid);
    hkOstream::operator<<(v8, ") hkgpConvexHull::buildMassProperties need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         0x79F9D887u,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         366) )
      __debugbreak();
    hkOstream::~hkOstream(&v10);
  }
  v9 = this->m_data;
  inertiaSpace->m_rotation.m_col0 = v9->m_localTransform.m_rotation.m_col0;
  inertiaSpace->m_rotation.m_col1 = v9->m_localTransform.m_rotation.m_col1;
  inertiaSpace->m_rotation.m_col2 = v9->m_localTransform.m_rotation.m_col2;
  inertiaSpace->m_translation = v9->m_localTransform.m_translation;
  *inertiaDiagonal = this->m_data->m_inertia;
}

// File Line: 1315
// RVA: 0xCADF20
hkMatrix3f *__fastcall hkgpConvexHull::getWorldInertia(hkgpConvexHull *this)
{
  hkgpConvexHullImpl *m_data; // rdi
  hkOstream *v3; // rax
  hkOstream *v4; // rax
  hkErrStream v6; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  m_data = this->m_data;
  if ( !m_data->m_hasMassProperties )
  {
    hkErrStream::hkErrStream(&v6, buf, 512);
    v3 = hkOstream::operator<<(&v6, "No mass properties available (");
    v4 = hkOstream::operator<<(v3, m_data->m_uid);
    hkOstream::operator<<(v4, ") hkgpConvexHull::buildMassProperties need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         0x79F9D887u,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         366) )
      __debugbreak();
    hkOstream::~hkOstream(&v6);
  }
  return &this->m_data->m_inertiaMatrix;
}

// File Line: 1321
// RVA: 0xCADFD0
hkVector4f *__fastcall hkgpConvexHull::getCenterOfMass(hkgpConvexHull *this)
{
  hkgpConvexHullImpl *m_data; // rdi
  hkOstream *v3; // rax
  hkOstream *v4; // rax
  hkErrStream v6; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  m_data = this->m_data;
  if ( !m_data->m_hasMassProperties )
  {
    hkErrStream::hkErrStream(&v6, buf, 512);
    v3 = hkOstream::operator<<(&v6, "No mass properties available (");
    v4 = hkOstream::operator<<(v3, m_data->m_uid);
    hkOstream::operator<<(v4, ") hkgpConvexHull::buildMassProperties need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         0x79F9D887u,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         366) )
      __debugbreak();
    hkOstream::~hkOstream(&v6);
  }
  return &this->m_data->m_localTransform.m_translation;
}

// File Line: 1327
// RVA: 0xCAE080
hkVector4f *__fastcall hkgpConvexHull::getMajorPlane(hkgpConvexHull *this, hkVector4f *result)
{
  hkgpConvexHullImpl *m_data; // rbx
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  __m128 v7; // xmm3
  __m128 v8; // xmm0
  hkVector4f *v9; // rax
  __m128 v10; // xmm1
  hkErrStream v11; // [rsp+20h] [rbp-268h] BYREF
  hkTransformf inertiaSpace; // [rsp+40h] [rbp-248h] BYREF
  char buf[512]; // [rsp+80h] [rbp-208h] BYREF

  m_data = this->m_data;
  if ( !m_data->m_hasMassProperties )
  {
    hkErrStream::hkErrStream(&v11, buf, 512);
    v5 = hkOstream::operator<<(&v11, "No mass properties available (");
    v6 = hkOstream::operator<<(v5, m_data->m_uid);
    hkOstream::operator<<(v6, ") hkgpConvexHull::buildMassProperties need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         0x79F9D887u,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         366) )
      __debugbreak();
    hkOstream::~hkOstream(&v11);
  }
  hkgpConvexHull::getLocalInertia(this, &inertiaSpace, (hkVector4f *)&v11);
  v7 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&v11), 1u), 1u);
  v8 = *(&inertiaSpace.m_rotation.m_col0.m_quad
       + (unsigned __int8)hkVector4Comparison_maskToFirstIndex[_mm_movemask_ps(
                                                                 _mm_and_ps(
                                                                   _mm_cmple_ps(
                                                                     v7,
                                                                     _mm_min_ps(
                                                                       _mm_shuffle_ps(v7, v7, 170),
                                                                       _mm_min_ps(
                                                                         _mm_shuffle_ps(v7, v7, 85),
                                                                         _mm_shuffle_ps(v7, v7, 0)))),
                                                                   (__m128)xmmword_141A79650))]);
  v9 = result;
  *result = (hkVector4f)v8;
  v10 = _mm_mul_ps(v8, inertiaSpace.m_translation.m_quad);
  result->m_quad = _mm_shuffle_ps(
                     v8,
                     _mm_unpackhi_ps(
                       v8,
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
  hkgpConvexHullImpl *m_data; // rdx
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
  hkVector4f halfExtents; // [rsp+20h] [rbp-88h] BYREF
  hkTransformf worldTransform; // [rsp+30h] [rbp-78h] BYREF

  *result = 0i64;
  m_data = this->m_data;
  switch ( m_data->m_dimensions )
  {
    case 1:
      v5 = _mm_shuffle_ps(
             m_data->m_projectionAxis.m_quad,
             _mm_unpackhi_ps(m_data->m_projectionAxis.m_quad, (__m128)0i64),
             196);
      v6 = _mm_shuffle_ps(v5, v5, 241);
      v7 = _mm_shuffle_ps(v5, v5, 206);
      v8 = _mm_mul_ps(v6, v6);
      v9 = _mm_mul_ps(v7, v7);
      v10 = _mm_cmplt_ps(
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
      v15 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v13), (__m128)0i64);
      result->m_quad = _mm_or_ps(
                         _mm_and_ps(
                           _mm_mul_ps(
                             _mm_andnot_ps(
                               _mm_cmple_ps(v13, (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
                                 _mm_mul_ps(*(__m128 *)_xmm, v14))),
                             v11),
                           v15),
                         _mm_andnot_ps(v15, v11));
      break;
    case 2:
      *result = m_data->m_projectionPlane;
      break;
    case 3:
      halfExtents.m_quad = 0i64;
      hkgpConvexHull::getOrientedBoundingBox(this, &halfExtents, &worldTransform);
      v4 = *(&transform.m_quad
           + (unsigned __int8)hkVector4Comparison_maskToFirstIndex[_mm_movemask_ps(
                                                                     _mm_and_ps(
                                                                       _mm_cmple_ps(
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
      result->m_quad = _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_shuffle_ps(v4, v4, 85), worldTransform.m_rotation.m_col1.m_quad),
                           _mm_mul_ps(_mm_shuffle_ps(v4, v4, 0), worldTransform.m_rotation.m_col0.m_quad)),
                         _mm_mul_ps(_mm_shuffle_ps(v4, v4, 170), worldTransform.m_rotation.m_col2.m_quad));
      break;
  }
  v16 = result;
  *(__m128i *)result = _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)result), 4), 4);
  return v16;
}

// File Line: 1366
// RVA: 0xCAE670
void __fastcall hkgpConvexHull::computeLocalTransform(hkgpConvexHull *this, hkTransformf *localTransform)
{
  hkgpConvexHullImpl *m_data; // rsi
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  hkgpConvexHullImpl *v7; // rax
  hkErrStream v8; // [rsp+20h] [rbp-228h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  m_data = this->m_data;
  if ( !m_data->m_hasMassProperties )
  {
    hkErrStream::hkErrStream(&v8, buf, 512);
    v5 = hkOstream::operator<<(&v8, "No mass properties available (");
    v6 = hkOstream::operator<<(v5, m_data->m_uid);
    hkOstream::operator<<(v6, ") hkgpConvexHull::buildMassProperties need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         0x79F9D887u,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         366) )
      __debugbreak();
    hkOstream::~hkOstream(&v8);
  }
  v7 = this->m_data;
  localTransform->m_rotation.m_col0 = v7->m_localTransform.m_rotation.m_col0;
  localTransform->m_rotation.m_col1 = v7->m_localTransform.m_rotation.m_col1;
  localTransform->m_rotation.m_col2 = v7->m_localTransform.m_rotation.m_col2;
  localTransform->m_translation = v7->m_localTransform.m_translation;
}

// File Line: 1372
// RVA: 0xCAE1E0
void __fastcall hkgpConvexHull::getMajorPlanes(hkgpConvexHull *this, hkVector4f *planes)
{
  hkgpConvexHullImpl *m_data; // rdi
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  __int64 v7; // rdi
  hkSimdFloat32 *Width; // rax
  __int64 v9; // rdx
  __int128 v10; // xmm1
  __int128 v11; // xmm0
  int v12; // eax
  int v13; // ecx
  __m128 m_quad; // xmm10
  __int64 v15; // rax
  __m128 v16; // xmm5
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm4
  __m128 v21; // xmm6
  __m128 v22; // xmm2
  hkVector4f inertiaDiagonal; // [rsp+20h] [rbp-D8h] BYREF
  hkErrStream v24; // [rsp+30h] [rbp-C8h] BYREF
  __int128 v25[2]; // [rsp+50h] [rbp-A8h]
  __m128 m_real; // [rsp+70h] [rbp-88h] BYREF
  hkVector4f inertiaSpace_16; // [rsp+88h] [rbp-70h] BYREF
  hkVector4f inertiaSpace_32[2]; // [rsp+98h] [rbp-60h] BYREF
  char buf[600]; // [rsp+B8h] [rbp-40h] BYREF

  m_data = this->m_data;
  if ( !m_data->m_hasMassProperties )
  {
    hkErrStream::hkErrStream(&v24, buf, 512);
    v5 = hkOstream::operator<<(&v24, "No mass properties available (");
    v6 = hkOstream::operator<<(v5, m_data->m_uid);
    hkOstream::operator<<(v6, ") hkgpConvexHull::buildMassProperties need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         0x79F9D887u,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         366) )
      __debugbreak();
    hkOstream::~hkOstream(&v24);
  }
  hkgpConvexHull::getLocalInertia(this, (hkTransformf *)&m_real.m128_u16[4], &inertiaDiagonal);
  v7 = 0i64;
  inertiaDiagonal.m_quad.m128_u64[0] = 0x100000000i64;
  inertiaDiagonal.m_quad.m128_i32[2] = 2;
  v25[0] = (__int128)hkgpConvexHull::getWidth(this, (hkSimdFloat32 *)&v24, (hkVector4f *)&m_real.m128_u16[4])->m_real;
  v25[1] = (__int128)hkgpConvexHull::getWidth(this, (hkSimdFloat32 *)&v24, &inertiaSpace_16)->m_real;
  Width = hkgpConvexHull::getWidth(this, (hkSimdFloat32 *)&v24, inertiaSpace_32);
  v9 = 0i64;
  m_real = Width->m_real;
  do
  {
    v10 = v25[v9 + 1];
    v11 = v25[v9];
    if ( *(float *)&v11 < *(float *)&v10 )
    {
      v25[v9] = v10;
      v12 = inertiaDiagonal.m_quad.m128_i32[v9 + 1];
      v25[v9 + 1] = v11;
      v13 = inertiaDiagonal.m_quad.m128_i32[v9];
      inertiaDiagonal.m_quad.m128_i32[v9] = v12;
      inertiaDiagonal.m_quad.m128_i32[v9 + 1] = v13;
      v9 = -1i64;
    }
    ++v9;
  }
  while ( v9 < 2 );
  m_quad = inertiaSpace_32[1].m_quad;
  do
  {
    v15 = inertiaDiagonal.m_quad.m128_i32[v7++];
    ++planes;
    v16 = *(__m128 *)((char *)&m_real + 16 * v15 + 8);
    v17 = _mm_mul_ps(v16, v16);
    v18 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
            _mm_shuffle_ps(v17, v17, 170));
    v19 = _mm_rsqrt_ps(v18);
    v20 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v18), (__m128)0i64);
    v21 = _mm_or_ps(
            _mm_and_ps(
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v18, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                    _mm_mul_ps(*(__m128 *)_xmm, v19))),
                v16),
              v20),
            _mm_andnot_ps(v20, v16));
    v22 = _mm_mul_ps(v21, m_quad);
    planes[-1].m_quad = _mm_shuffle_ps(
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
}

// File Line: 1402
// RVA: 0xCAE750
hkBool *__fastcall hkgpConvexHull::rayCast(
        hkgpConvexHull *this,
        hkBool *result,
        hkVector4f *origin,
        hkVector4f *direction,
        float *minFractionInOut,
        int *planeOut)
{
  hkgpConvexHullImpl *m_data; // rsi
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkgpConvexHullImpl *v13; // rax
  __m128i si128; // xmm8
  __int64 v15; // rcx
  __m128i v16; // xmm9
  __int64 m_size; // r8
  __m128 *p_m_quad; // rdx
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
  __m128 v30; // xmm0
  hkErrStream v32; // [rsp+20h] [rbp-2B8h] BYREF
  char buf[656]; // [rsp+40h] [rbp-298h] BYREF

  if ( (unsigned int)hkgpConvexHull::getDimensions(this) != 3 )
    goto LABEL_18;
  m_data = this->m_data;
  if ( !m_data->m_hasIndexing )
  {
    hkErrStream::hkErrStream(&v32, buf, 512);
    v11 = hkOstream::operator<<(&v32, "No index available (");
    v12 = hkOstream::operator<<(v11, m_data->m_uid);
    hkOstream::operator<<(v12, ") hkgpConvexHull::buildIndices need to be called before this operation.");
    if ( (unsigned int)hkError::messageError(
                         0x79F9D886u,
                         buf,
                         "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h",
                         358) )
      __debugbreak();
    hkOstream::~hkOstream(&v32);
  }
  v13 = this->m_data;
  si128 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
  v15 = 0i64;
  v16 = 0i64;
  m_size = v13->m_planes.m_size;
  p_m_quad = &v13->m_planes.m_data->m_quad;
  v19 = (__m128)xmmword_141A712F0;
  v20 = (__m128)xmmword_141A712A0;
  if ( m_size > 0 )
  {
    do
    {
      v21 = _mm_mul_ps(*p_m_quad, origin->m_quad);
      v22 = _mm_mul_ps(*p_m_quad, direction->m_quad);
      v23 = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, *p_m_quad), 196);
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
          v30 = _mm_cmplt_ps(v28, v20);
          v20 = _mm_or_ps(_mm_and_ps(v30, v28), _mm_andnot_ps(v30, v20));
        }
      }
      else
      {
        if ( v26.m128_f32[0] >= 0.0 )
          goto LABEL_18;
        v29 = (__m128i)_mm_cmplt_ps(v19, v28);
        v19 = _mm_or_ps(_mm_and_ps(v28, (__m128)v29), _mm_andnot_ps((__m128)v29, v19));
        si128 = _mm_or_si128(_mm_andnot_si128(v29, si128), _mm_and_si128(v29, v16));
      }
      ++v15;
      ++p_m_quad;
      v16 = _mm_add_epi32((__m128i)xmmword_141A72090, v16);
    }
    while ( v15 < m_size );
  }
  if ( !_mm_movemask_ps(
          _mm_and_ps(
            _mm_and_ps(
              _mm_and_ps(
                (__m128)_mm_or_si128(
                          _mm_cmpgt_epi32(si128, *(__m128i *)&g_intVectorConstants[0][0]),
                          _mm_cmpeq_epi32(si128, *(__m128i *)&g_intVectorConstants[0][0])),
                _mm_cmple_ps(v19, v20)),
              _mm_cmplt_ps((__m128)0i64, v19)),
            _mm_cmplt_ps(
              v19,
              _mm_shuffle_ps((__m128)*(unsigned int *)minFractionInOut, (__m128)*(unsigned int *)minFractionInOut, 0)))) )
  {
LABEL_18:
    result->m_bool = 0;
    return result;
  }
  if ( planeOut )
    *planeOut = si128.m128i_i32[0];
  *minFractionInOut = v19.m128_f32[0];
  result->m_bool = 1;
  return result;
}  *planeOut = si128.m128i_i32[0];
  *minFractionInOut = v19.m128_f32[0];

// File Line: 1484
// RVA: 0xCAEA50
__int64 __fastcall hkgpConvexHull::classify(hkgpConvexHull *this, hkVector4f *plane, float thickness, float *boundsR)
{
  unsigned int v4; // r11d
  __m128 *m_used; // rcx
  float v6; // xmm5_4
  __m128 v7; // xmm3
  __m128 v8; // xmm4
  int v9; // r10d
  int v10; // r8d
  __m128 v11; // xmm2
  __m128 v12; // xmm2
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __int64 result; // rax

  v4 = 0;
  m_used = (__m128 *)this->m_data->m_mesh.m_vertices.m_used;
  LODWORD(v6) = _mm_shuffle_ps((__m128)LODWORD(thickness), (__m128)LODWORD(thickness), 0).m128_u32[0];
  v7 = 0i64;
  v8 = 0i64;
  v9 = 0;
  v10 = 0;
  if ( m_used )
  {
    do
    {
      v11 = _mm_mul_ps(m_used[1], plane->m_quad);
      v12 = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, plane->m_quad), 196);
      v13 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 78), v12);
      v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 177), v13);
      if ( m_used->m128_u64[1] )
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
        m_used[2].m128_i32[3] = v14.m128_i32[0];
        if ( v14.m128_f32[0] <= 0.0 )
          ++v9;
        else
          ++v10;
      }
      else
      {
        m_used[2].m128_i32[3] = 0;
      }
      m_used = (__m128 *)m_used->m128_u64[0];
    }
    while ( m_used );
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
hkgpConvexHull::Side __fastcall hkgpConvexHull::splitByPlane(
        hkgpConvexHull *this,
        hkVector4f *plane,
        hkgpConvexHull **pos,
        hkgpConvexHull **neg,
        float thickness)
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
void __fastcall hkgpConvexHull::subdivide(
        hkgpConvexHull *this,
        unsigned int recursions,
        hkArray<hkgpConvexHull *,hkContainerHeapAllocator> *output,
        float thickness)
{
  __int64 v5; // rdi
  hkgpConvexHull *v6; // rsi
  __int64 v7; // r13
  __int64 m_size; // r12
  int v9; // r15d
  __int64 v10; // rbp
  hkgpConvexHull *v11; // r14
  hkVector4f *MajorPlane; // rax
  hkgpConvexHull *v13; // rsi
  hkgpConvexHull *v14; // rdi
  int m_capacityAndFlags; // eax
  __int64 v16; // rax
  hkBaseObjectVtbl *vfptr; // rax
  hkgpConvexHull *v18; // rcx
  hkgpConvexHull *pos; // [rsp+30h] [rbp-58h] BYREF
  hkgpConvexHull *neg; // [rsp+38h] [rbp-50h] BYREF
  hkVector4f v21; // [rsp+40h] [rbp-48h] BYREF
  hkResult result; // [rsp+98h] [rbp+10h] BYREF

  v5 = recursions;
  output->m_size = 0;
  v6 = hkgpConvexHull::clone(this);
  if ( output->m_size == (output->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&output->m_data, 8);
  output->m_data[output->m_size++] = v6;
  if ( (int)v5 > 0 )
  {
    v7 = v5;
    while ( 1 )
    {
      m_size = output->m_size;
      v9 = 0;
      v10 = 0i64;
      if ( m_size > 0 )
        break;
LABEL_22:
      if ( !--v7 )
        return;
    }
    while ( 1 )
    {
      v11 = output->m_data[v10];
      hkgpConvexHull::buildMassProperties(v11, &result);
      MajorPlane = hkgpConvexHull::getMajorPlane(v11, &v21);
      if ( hkgpConvexHull::splitByPlane(v11, MajorPlane, &pos, &neg, thickness) == 3 )
      {
        v13 = pos;
        v14 = neg;
        if ( pos )
        {
          if ( neg )
          {
            if ( output->m_size == (output->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&output->m_data, 8);
            output->m_data[output->m_size] = v13;
            m_capacityAndFlags = output->m_capacityAndFlags;
            if ( ++output->m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&output->m_data, 8);
            output->m_data[output->m_size] = v14;
            v16 = output->m_size;
            output->m_size = v16;
            if ( (_DWORD)v16 != v9 )
              output->m_data[v10] = output->m_data[v16];
            if ( !v11 )
              goto LABEL_21;
            vfptr = v11->vfptr;
            v18 = v11;
            goto LABEL_20;
          }
          pos->vfptr->__vecDelDtor(pos, 1i64);
        }
        if ( v14 )
        {
          vfptr = v14->vfptr;
          v18 = v14;
LABEL_20:
          vfptr->__vecDelDtor(v18, 1u);
        }
      }
LABEL_21:
      ++v10;
      ++v9;
      if ( v10 >= m_size )
        goto LABEL_22;
    }
  }
}

// File Line: 1529
// RVA: 0xCAED60
void __fastcall hkgpConvexHull::fetchPositions(
        hkgpConvexHull *this,
        hkgpConvexHull::Inputs inputs,
        hkArray<hkVector4f,hkContainerHeapAllocator> *positions)
{
  hkgpConvexHullImpl *m_data; // rdi
  __int64 m_size; // r14
  int m_numUsed; // esi
  int v6; // eax
  int v8; // r9d
  int v9; // eax
  hkgpConvexHullImpl::Vertex *m_next; // rax
  hkVector4f *j; // rdx
  hkVector4f *v12; // rcx
  int v13; // eax
  hkgpConvexHullImpl::Vertex *m_used; // rdx
  hkVector4f *i; // rcx
  __m128 *p_m_quad; // rax
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  m_data = this->m_data;
  m_size = positions->m_size;
  m_numUsed = m_data->m_mesh.m_vertices.m_numUsed;
  v6 = positions->m_capacityAndFlags & 0x3FFFFFFF;
  v8 = m_size + m_numUsed;
  if ( inputs )
  {
    if ( v6 < v8 )
    {
      v13 = 2 * v6;
      if ( v8 < v13 )
        v8 = v13;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&positions->m_data, v8, 16);
    }
    positions->m_size += m_numUsed;
    m_used = m_data->m_mesh.m_vertices.m_used;
    for ( i = &positions->m_data[m_size]; m_used; m_used = m_used->m_next )
    {
      p_m_quad = &i->m_quad;
      ++i;
      *p_m_quad = _mm_add_ps(
                    _mm_mul_ps(
                      (__m128)_mm_srli_si128(
                                _mm_slli_si128(
                                  (__m128i)_mm_cvtepi32_ps(
                                             _mm_unpacklo_epi32(
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(m_used->m_x[0]),
                                                 _mm_cvtsi32_si128(m_used->m_x[2])),
                                               _mm_unpacklo_epi32(
                                                 _mm_cvtsi32_si128(m_used->m_x[1]),
                                                 _mm_cvtsi32_si128(0)))),
                                  4),
                                4),
                      m_data->m_scaleInv.m_quad),
                    m_data->m_origin.m_quad);
    }
  }
  else
  {
    if ( v6 < v8 )
    {
      v9 = 2 * v6;
      if ( v8 < v9 )
        v8 = v9;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&positions->m_data, v8, 16);
    }
    positions->m_size += m_numUsed;
    m_next = m_data->m_mesh.m_vertices.m_used;
    for ( j = &positions->m_data[m_size]; m_next; m_next = m_next->m_next )
    {
      v12 = j++;
      *v12 = m_next->m_source;
    }
  }
}

// File Line: 1537
// RVA: 0xCAEEB0
void __fastcall hkgpConvexHull::fetchPlanes(hkgpConvexHull *this, hkArray<hkVector4f,hkContainerHeapAllocator> *planes)
{
  int NumPlanes; // eax
  __int64 m_size; // rsi
  int v6; // edi
  int v7; // r9d
  int v8; // ecx
  int v9; // ecx
  hkVector4f *v10; // rsi
  int v11; // ebx
  int v12; // r14d
  hkVector4f *v13; // rdi
  hkVector4f *Plane; // rax
  hkResult result; // [rsp+58h] [rbp+10h] BYREF

  NumPlanes = hkgpConvexHull::getNumPlanes(this);
  m_size = planes->m_size;
  v6 = NumPlanes;
  v7 = m_size + NumPlanes;
  v8 = planes->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < (int)m_size + NumPlanes )
  {
    v9 = 2 * v8;
    if ( v7 < v9 )
      v7 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&planes->m_data, v7, 16);
  }
  planes->m_size += v6;
  v10 = &planes->m_data[m_size];
  v11 = 0;
  v12 = hkgpConvexHull::getNumPlanes(this);
  if ( v12 > 0 )
  {
    do
    {
      v13 = v10++;
      Plane = hkgpConvexHull::getPlane(this, v11++);
      *v13 = (hkVector4f)Plane->m_quad;
    }
    while ( v11 < v12 );
  }
}

// File Line: 1546
// RVA: 0xCAEF70
void __fastcall hkgpConvexHull::fetchBevelPlanes(
        hkgpConvexHull *this,
        float maxCosAngle,
        hkArray<hkVector4f,hkContainerHeapAllocator> *bevelPlanes)
{
  hkgpConvexHullImpl::buildBevelPlanes<hkgpConvexHullImpl::PositionAsTransform>(this->m_data, maxCosAngle, bevelPlanes);
}

// File Line: 1551
// RVA: 0xCAEF80
int __fastcall hkgpConvexHull::generateIndexedFaces(
        hkgpConvexHull *this,
        hkgpConvexHull::Inputs inputs,
        hkArray<unsigned char,hkContainerHeapAllocator> *verticesPerFace,
        hkArray<unsigned short,hkContainerHeapAllocator> *indices,
        hkBool maximizeArea)
{
  return hkgpConvexHullImpl::generateIndexedFaces<unsigned char,unsigned short>(
           this->m_data,
           verticesPerFace,
           indices,
           inputs == SOURCE_VERTICES,
           maximizeArea.m_bool != 0);
}

// File Line: 1556
// RVA: 0xCAEFC0
int __fastcall hkgpConvexHull::generateIndexedFaces(
        hkgpConvexHull *this,
        hkgpConvexHull::Inputs inputs,
        hkArray<int,hkContainerHeapAllocator> *verticesPerFace,
        hkArray<int,hkContainerHeapAllocator> *indices,
        hkBool maximizeArea)
{
  return hkgpConvexHullImpl::generateIndexedFaces<int,int>(
           this->m_data,
           verticesPerFace,
           indices,
           inputs == SOURCE_VERTICES,
           maximizeArea.m_bool != 0);
}

// File Line: 1561
// RVA: 0xCAF000
void __fastcall hkgpConvexHull::generateVertexAdjacencyGraph(
        hkgpConvexHull *this,
        hkArray<int,hkContainerHeapAllocator> *edges,
        hkArray<int,hkContainerHeapAllocator> *vertexOffsets)
{
  hkgpConvexHullImpl::generateVertexAdjacencyGraph(this->m_data, edges, vertexOffsets);
}

// File Line: 1566
// RVA: 0xCAF010
void __fastcall hkgpConvexHull::generatePlanesPerVertex(
        hkgpConvexHull *this,
        hkArray<int,hkContainerHeapAllocator> *startPlaneOffsetOut,
        hkArray<int,hkContainerHeapAllocator> *planeIndicesOut)
{
  hkgpConvexHullImpl::generatePlanesPerVertex(this->m_data, startPlaneOffsetOut, planeIndicesOut);
}

// File Line: 1573
// RVA: 0xCAF020
void __fastcall hkgpConvexHull::generateGeometry(
        hkgpConvexHull *this,
        hkgpConvexHull::Inputs inputs,
        hkGeometry *geometry,
        int material,
        bool planarTwoSided)
{
  hkgpConvexHullImpl *m_data; // rcx
  bool v7; // r12
  int v8; // r14d
  int v10; // eax
  int v11; // edi
  int v12; // r9d
  int v13; // eax
  int v14; // eax
  int v15; // r13d
  hkVector4f *v16; // rdi
  int v17; // r9d
  int v18; // eax
  int v19; // eax
  hkGeometry::Triangle *v20; // r13
  hkgpConvexHullImpl::Vertex *m_next; // rbx
  hkResultEnum v22; // r14d
  __m128 v23; // xmm0
  hkgpConvexHullImpl::Triangle *v24; // rbx
  int *p_m_c; // rdi
  int v26; // eax
  int m_size; // eax
  int m_numUsed; // edi
  int v29; // r9d
  int v30; // eax
  int v31; // eax
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *p_m_triangles; // r13
  int v33; // ecx
  hkVector4f *v34; // rdi
  __int64 v35; // rbx
  __int32 v36; // eax
  int v37; // r9d
  int v38; // r9d
  __int64 v39; // rbx
  hkgpConvexHullImpl::Vertex *m_used; // r8
  hkResultEnum m_enum; // r9d
  __m128 m_quad; // xmm0
  __int64 v43; // rdx
  __int64 v44; // r8
  bool v45; // r9
  int v46; // ecx
  int v47; // ecx
  hkResult v48; // [rsp+30h] [rbp-20h] BYREF
  hkResult result; // [rsp+34h] [rbp-1Ch] BYREF
  hkResult v50; // [rsp+38h] [rbp-18h] BYREF
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > array; // [rsp+40h] [rbp-10h] BYREF
  hkResult v52; // [rsp+90h] [rbp+40h] BYREF
  int v53; // [rsp+98h] [rbp+48h]
  int v54; // [rsp+A8h] [rbp+58h]

  v54 = material;
  m_data = this->m_data;
  v7 = inputs == SOURCE_VERTICES;
  v8 = material;
  if ( m_data->m_dimensions == 2 )
  {
    m_size = geometry->m_vertices.m_size;
    array.m_hashMod = 0x80000000;
    result.m_enum = m_size;
    array.m_elem = 0i64;
    array.m_numElems = 0;
    m_numUsed = m_data->m_mesh.m_vertices.m_numUsed;
    v52.m_enum = planarTwoSided + 1;
    v29 = geometry->m_vertices.m_size + m_numUsed;
    v53 = geometry->m_vertices.m_size;
    v30 = geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v30 < v29 )
    {
      v31 = 2 * v30;
      if ( v29 < v31 )
        v29 = v31;
      hkArrayUtil::_reserve(
        &v50,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&geometry->m_vertices.m_data,
        v29,
        16);
    }
    geometry->m_vertices.m_size += m_numUsed;
    p_m_triangles = &geometry->m_triangles;
    v33 = geometry->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
    v34 = &geometry->m_vertices.m_data[v53];
    v35 = geometry->m_triangles.m_size;
    v36 = v52.m_enum * (this->m_data->m_mesh.m_vertices.m_numUsed - 2);
    v37 = v35 + v36;
    v53 = v36;
    if ( v33 < (int)v35 + v36 )
    {
      if ( v37 < 2 * v33 )
        v37 = 2 * v33;
      hkArrayUtil::_reserve(&v52, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_triangles->m_data, v37, 16);
      v36 = v53;
    }
    p_m_triangles->m_size += v36;
    v38 = this->m_data->m_mesh.m_vertices.m_numUsed;
    v39 = (__int64)&p_m_triangles->m_data[v35];
    if ( (array.m_hashMod & 0x3FFFFFFF) >= v38 )
    {
      v48.m_enum = HK_SUCCESS;
    }
    else
    {
      if ( v38 < 2 * (array.m_hashMod & 0x3FFFFFFF) )
        v38 = 2 * (array.m_hashMod & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v48, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_elem, v38, 4);
    }
    m_used = this->m_data->m_mesh.m_vertices.m_used;
    if ( m_used )
    {
      m_enum = result.m_enum;
      do
      {
        *((_DWORD *)&array.m_elem->key + array.m_numElems) = array.m_numElems + m_enum;
        ++array.m_numElems;
        if ( v7 )
          m_quad = m_used->m_source.m_quad;
        else
          m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       (__m128)_mm_srli_si128(
                                 _mm_slli_si128(
                                   (__m128i)_mm_cvtepi32_ps(
                                              _mm_unpacklo_epi32(
                                                _mm_unpacklo_epi32(
                                                  _mm_cvtsi32_si128(m_used->m_x[0]),
                                                  _mm_cvtsi32_si128(m_used->m_x[2])),
                                                _mm_unpacklo_epi32(
                                                  _mm_cvtsi32_si128(m_used->m_x[1]),
                                                  _mm_cvtsi32_si128(0)))),
                                   4),
                                 4),
                       this->m_data->m_scaleInv.m_quad),
                     this->m_data->m_origin.m_quad);
        *v34 = (hkVector4f)m_quad;
        m_used = m_used->m_next;
        ++v34;
      }
      while ( m_used );
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
        &hkContainerHeapAllocator::s_alloc,
        array.m_elem,
        4 * array.m_hashMod);
  }
  else if ( m_data->m_dimensions == 3 )
  {
    v10 = geometry->m_vertices.m_size;
    array.m_hashMod = -1;
    v52.m_enum = v10;
    v53 = v10;
    array.m_elem = 0i64;
    array.m_numElems = 0;
    v11 = m_data->m_mesh.m_vertices.m_numUsed;
    v12 = v10 + v11;
    v13 = geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v13 < v12 )
    {
      v14 = 2 * v13;
      if ( v12 < v14 )
        v12 = v14;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&geometry->m_vertices.m_data,
        v12,
        16);
    }
    geometry->m_vertices.m_size += v11;
    v15 = this->m_data->m_mesh.m_triangles.m_numUsed;
    v16 = &geometry->m_vertices.m_data[v53];
    v17 = geometry->m_triangles.m_size + v15;
    v53 = geometry->m_triangles.m_size;
    v18 = geometry->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v18 < v17 )
    {
      v19 = 2 * v18;
      if ( v17 < v19 )
        v17 = v19;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&geometry->m_triangles.m_data,
        v17,
        16);
    }
    geometry->m_triangles.m_size += v15;
    v20 = &geometry->m_triangles.m_data[v53];
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
      &array,
      &hkContainerHeapAllocator::s_alloc,
      this->m_data->m_mesh.m_vertices.m_numUsed);
    m_next = this->m_data->m_mesh.m_vertices.m_used;
    if ( m_next )
    {
      v22 = v52.m_enum;
      do
      {
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &array,
          &hkContainerHeapAllocator::s_alloc,
          (unsigned __int64)m_next,
          v22 + (array.m_numElems & 0x7FFFFFFF));
        if ( v7 )
          v23 = m_next->m_source.m_quad;
        else
          v23 = _mm_add_ps(
                  _mm_mul_ps(
                    (__m128)_mm_srli_si128(
                              _mm_slli_si128(
                                (__m128i)_mm_cvtepi32_ps(
                                           _mm_unpacklo_epi32(
                                             _mm_unpacklo_epi32(
                                               _mm_cvtsi32_si128(m_next->m_x[0]),
                                               _mm_cvtsi32_si128(m_next->m_x[2])),
                                             _mm_unpacklo_epi32(_mm_cvtsi32_si128(m_next->m_x[1]), _mm_cvtsi32_si128(0)))),
                                4),
                              4),
                    this->m_data->m_scaleInv.m_quad),
                  this->m_data->m_origin.m_quad);
        *v16 = (hkVector4f)v23;
        m_next = m_next->m_next;
        ++v16;
      }
      while ( m_next );
      v8 = v54;
    }
    v24 = this->m_data->m_mesh.m_triangles.m_used;
    if ( v24 )
    {
      p_m_c = &v20->m_c;
      do
      {
        *(p_m_c - 2) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                         &array,
                         (unsigned __int64)v24->m_vertices[0],
                         0xFFFFFFFFFFFFFFFFui64);
        *(p_m_c - 1) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                         &array,
                         (unsigned __int64)v24->m_vertices[1],
                         0xFFFFFFFFFFFFFFFFui64);
        v26 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                &array,
                (unsigned __int64)v24->m_vertices[2],
                0xFFFFFFFFFFFFFFFFui64);
        p_m_c[1] = v8;
        p_m_c += 4;
        *(p_m_c - 4) = v26;
        v24 = v24->m_next;
      }
      while ( v24 );
    }
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &array,
      &hkContainerHeapAllocator::s_alloc);
    _((AMD_HD3D *)&array);
  }
}

