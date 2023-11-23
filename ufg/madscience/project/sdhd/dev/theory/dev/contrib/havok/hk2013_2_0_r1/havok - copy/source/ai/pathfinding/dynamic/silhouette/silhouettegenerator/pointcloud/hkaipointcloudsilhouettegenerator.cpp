// File Line: 32
// RVA: 0xBD3840
void __fastcall hkaiPointCloudSilhouetteGenerator::hkaiPointCloudSilhouetteGenerator(
        hkaiPointCloudSilhouetteGenerator *this)
{
  hkaiSilhouetteGenerator::hkaiSilhouetteGenerator(this, GENERATOR_POINT_CLOUD);
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPointCloudSilhouetteGenerator::`vftable;
  this->m_localPoints.m_capacityAndFlags = 0x80000000;
  this->m_localPoints.m_data = 0i64;
  this->m_localPoints.m_size = 0;
  this->m_silhouetteSizes.m_data = 0i64;
  this->m_silhouetteSizes.m_size = 0;
  this->m_silhouetteSizes.m_capacityAndFlags = 0x80000000;
  this->m_localAabb.m_min = (hkVector4f)xmmword_141A712A0;
  this->m_localAabb.m_max.m_quad = _mm_xor_ps(
                                     (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                     this->m_localAabb.m_min.m_quad);
  this->m_weldTolerance = 0.0099999998;
  *(_DWORD *)&this->m_silhouetteDetailLevel.m_storage = 16843009;
}

// File Line: 45
// RVA: 0xBD38D0
void __fastcall hkaiPointCloudSilhouetteGenerator::hkaiPointCloudSilhouetteGenerator(
        hkaiPointCloudSilhouetteGenerator *this,
        hkFinishLoadedObjectFlag f)
{
  hkaiSilhouetteGenerator::hkaiSilhouetteGenerator(this, f);
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPointCloudSilhouetteGenerator::`vftable;
}

// File Line: 51
// RVA: 0xBD3900
void __fastcall hkaiPointCloudSilhouetteGenerator::~hkaiPointCloudSilhouetteGenerator(
        hkaiPointCloudSilhouetteGenerator *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkaiPointCloudSilhouetteGenerator::`vftable;
  m_capacityAndFlags = this->m_silhouetteSizes.m_capacityAndFlags;
  this->m_silhouetteSizes.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_silhouetteSizes.m_data,
      4 * m_capacityAndFlags);
  this->m_silhouetteSizes.m_data = 0i64;
  this->m_silhouetteSizes.m_capacityAndFlags = 0x80000000;
  v3 = this->m_localPoints.m_capacityAndFlags;
  this->m_localPoints.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_localPoints.m_data,
      16 * v3);
  this->m_localPoints.m_data = 0i64;
  this->m_localPoints.m_capacityAndFlags = 0x80000000;
  hkaiSilhouetteGenerator::~hkaiSilhouetteGenerator(this);
}

// File Line: 58
// RVA: 0xBD4430
void __fastcall hkaiPointCloudSilhouetteGenerator::setFromAabb(hkaiPointCloudSilhouetteGenerator *this, hkAabb *aabb)
{
  __int64 v2; // rdi
  int v5; // r9d
  __int64 v6; // rcx
  const int *v7; // rdx
  __m128 v8; // xmm2
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  v2 = 8i64;
  if ( (this->m_localPoints.m_capacityAndFlags & 0x3FFFFFFFu) < 8 )
  {
    v5 = 8;
    if ( 2 * (this->m_localPoints.m_capacityAndFlags & 0x3FFFFFFF) > 8 )
      v5 = 2 * (this->m_localPoints.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_localPoints, v5, 16);
  }
  this->m_localPoints.m_size = 8;
  v6 = 0i64;
  v7 = hkVector4fComparison_maskToComparison_168;
  do
  {
    v8 = *(__m128 *)v7;
    ++v6;
    v7 += 4;
    this->m_localPoints.m_data[v6 - 1].m_quad = _mm_or_ps(
                                                  _mm_andnot_ps(v8, aabb->m_min.m_quad),
                                                  _mm_and_ps(aabb->m_max.m_quad, *((__m128 *)v7 - 1)));
    --v2;
  }
  while ( v2 );
  this->m_localPointsChanged.m_bool = 1;
  this->m_localAabb.m_min = aabb->m_min;
  this->m_localAabb.m_max = aabb->m_max;
}

// File Line: 70
// RVA: 0xBD42A0
void __fastcall hkaiPointCloudSilhouetteGenerator::setLocalPoints(
        hkaiPointCloudSilhouetteGenerator *this,
        hkArrayBase<hkVector4f> *points,
        hkArray<int,hkContainerHeapAllocator> *sizes)
{
  __int64 m_size; // rax
  int *m_data; // rcx
  __int64 v8; // rdx
  char *v9; // r8
  int v10; // eax
  __int64 v11; // rax
  hkVector4f *v12; // rcx
  __int64 v13; // rdx
  char *v14; // r8
  hkVector4f v15; // xmm0
  int v16; // [rsp+30h] [rbp+8h] BYREF

  if ( (this->m_silhouetteSizes.m_capacityAndFlags & 0x3FFFFFFF) < sizes->m_size )
  {
    if ( this->m_silhouetteSizes.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_silhouetteSizes.m_data,
        4 * this->m_silhouetteSizes.m_capacityAndFlags);
    v16 = 4 * sizes->m_size;
    this->m_silhouetteSizes.m_data = (int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                              &hkContainerHeapAllocator::s_alloc,
                                              &v16);
    this->m_silhouetteSizes.m_capacityAndFlags = v16 / 4;
  }
  m_size = sizes->m_size;
  m_data = this->m_silhouetteSizes.m_data;
  this->m_silhouetteSizes.m_size = m_size;
  v8 = m_size;
  if ( (int)m_size > 0 )
  {
    v9 = (char *)((char *)sizes->m_data - (char *)m_data);
    do
    {
      v10 = *(int *)((char *)m_data++ + (_QWORD)v9);
      *(m_data - 1) = v10;
      --v8;
    }
    while ( v8 );
  }
  if ( (this->m_localPoints.m_capacityAndFlags & 0x3FFFFFFF) < points->m_size )
  {
    if ( this->m_localPoints.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_localPoints.m_data,
        16 * this->m_localPoints.m_capacityAndFlags);
    v16 = 16 * points->m_size;
    this->m_localPoints.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                 &hkContainerHeapAllocator::s_alloc,
                                                 &v16);
    this->m_localPoints.m_capacityAndFlags = v16 / 16;
  }
  v11 = points->m_size;
  v12 = this->m_localPoints.m_data;
  this->m_localPoints.m_size = v11;
  v13 = v11;
  if ( (int)v11 > 0 )
  {
    v14 = (char *)((char *)points->m_data - (char *)v12);
    do
    {
      v15.m_quad = *(__m128 *)((char *)v12++ + (_QWORD)v14);
      v12[-1] = (hkVector4f)v15.m_quad;
      --v13;
    }
    while ( v13 );
  }
  this->m_localPointsChanged.m_bool = 1;
  hkAabbUtil::calcAabb(this->m_localPoints.m_data, this->m_localPoints.m_size, &this->m_localAabb);
  ((void (__fastcall *)(hkaiPointCloudSilhouetteGenerator *))this->vfptr[2].__vecDelDtor)(this);
}

// File Line: 79
// RVA: 0xBD39B0
hkaiConvexSilhouetteSet *__fastcall hkaiPointCloudSilhouetteGenerator::generateSilhouettesCached(
        hkaiPointCloudSilhouetteGenerator *this,
        hkQTransformf *localTransform,
        hkaiSilhouetteGenerationParameters *params)
{
  hkaiSilhouetteReferenceFrame *up; // r12
  hkVector4f *v8; // rax
  int m_size; // ebx
  hkVector4f *v10; // r13
  int v11; // esi
  hkLifoAllocator *Value; // rcx
  int *m_cur; // rax
  int v14; // edx
  char *v15; // r8
  hkBaseObjectVtbl *vfptr; // rax
  _QWORD **v17; // rax
  __int64 v18; // rax
  hkaiConvexSilhouetteSet *v19; // rbx
  hkaiConvexSilhouetteSet *m_pntr; // rcx
  int v21; // eax
  hkaiConvexSilhouetteSet *v22; // r14
  char *v23; // rdi
  signed int v24; // ebx
  hkLifoAllocator *v25; // rax
  int v26; // r8d
  hkArrayBase<hkVector4f> vertexPool; // [rsp+30h] [rbp-30h] BYREF
  hkArrayBase<int> silhouetteSizes; // [rsp+40h] [rbp-20h] BYREF
  void *p; // [rsp+50h] [rbp-10h]
  int v30; // [rsp+58h] [rbp-8h]
  int v31; // [rsp+A0h] [rbp+40h] BYREF

  up = &params->m_referenceFrame;
  if ( hkaiSilhouetteGenerator::canReuseCachedSilhouettes(this, localTransform, &params->m_referenceFrame.m_up) )
    return this->m_cachedSilhouettes.m_pntr;
  v31 = 2048;
  v8 = (hkVector4f *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &v31);
  m_size = this->m_silhouetteSizes.m_size;
  v10 = v8;
  v11 = 0x80000000;
  vertexPool.m_data = v8;
  vertexPool.m_capacityAndFlags = -2147483520;
  if ( v31 / 16 )
    v11 = v31 / 16;
  vertexPool.m_size = 0;
  if ( !m_size || this->m_silhouetteDetailLevel.m_storage == 3 )
    m_size = 1;
  silhouetteSizes.m_data = 0i64;
  silhouetteSizes.m_size = 0;
  silhouetteSizes.m_capacityAndFlags = 0x80000000;
  v30 = m_size;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (int *)Value->m_cur;
  v14 = (4 * m_size + 127) & 0xFFFFFF80;
  v15 = (char *)m_cur + v14;
  if ( v14 > Value->m_slabSize || v15 > Value->m_end )
    m_cur = (int *)hkLifoAllocator::allocateFromNewSlab(Value, v14);
  else
    Value->m_cur = v15;
  silhouetteSizes.m_data = m_cur;
  p = m_cur;
  vfptr = this->vfptr;
  silhouetteSizes.m_capacityAndFlags = m_size | 0x80000000;
  ((void (__fastcall *)(hkaiPointCloudSilhouetteGenerator *, hkQTransformf *, hkaiSilhouetteGenerationParameters *, hkArrayBase<hkVector4f> *, hkArrayBase<int> *))vfptr[2].__first_virtual_table_function__)(
    this,
    localTransform,
    params,
    &vertexPool,
    &silhouetteSizes);
  if ( !this->m_cachedSilhouettes.m_pntr )
  {
    v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v17[11] + 8i64))(v17[11], 96i64);
    v19 = (hkaiConvexSilhouetteSet *)v18;
    if ( v18 )
    {
      *(_DWORD *)(v18 + 8) = 0x1FFFF;
      *(_QWORD *)v18 = &hkaiConvexSilhouetteSet::`vftable;
      *(_DWORD *)(v18 + 28) = 0x80000000;
      *(_QWORD *)(v18 + 16) = 0i64;
      *(_DWORD *)(v18 + 24) = 0;
      *(_QWORD *)(v18 + 32) = 0i64;
      *(_DWORD *)(v18 + 40) = 0;
      *(_DWORD *)(v18 + 44) = 0x80000000;
    }
    else
    {
      v19 = 0i64;
    }
    m_pntr = this->m_cachedSilhouettes.m_pntr;
    if ( m_pntr && m_pntr != v19 )
      hkReferencedObject::removeReference(m_pntr);
    this->m_cachedSilhouettes.m_pntr = v19;
  }
  hkaiConvexSilhouetteSet::set(
    this->m_cachedSilhouettes.m_pntr,
    &vertexPool,
    &silhouetteSizes,
    localTransform,
    &up->m_up);
  v21 = silhouetteSizes.m_size;
  v22 = this->m_cachedSilhouettes.m_pntr;
  v23 = (char *)p;
  if ( p == silhouetteSizes.m_data )
    v21 = 0;
  silhouetteSizes.m_size = v21;
  v24 = (4 * v30 + 127) & 0xFFFFFF80;
  v25 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v26 = (v24 + 15) & 0xFFFFFFF0;
  if ( v24 > v25->m_slabSize || &v23[v26] != v25->m_cur || v25->m_firstNonLifoEnd == v23 )
    hkLifoAllocator::slowBlockFree(v25, v23, v26);
  else
    v25->m_cur = v23;
  silhouetteSizes.m_size = 0;
  if ( silhouetteSizes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      silhouetteSizes.m_data,
      4 * silhouetteSizes.m_capacityAndFlags);
  silhouetteSizes.m_data = 0i64;
  silhouetteSizes.m_capacityAndFlags = 0x80000000;
  if ( v11 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v10, 16 * v11);
  return v22;
}

// File Line: 105
// RVA: 0xBD3C60
void __fastcall hkaiPointCloudSilhouetteGenerator::invalidateCachedSilhouettes(hkaiPointCloudSilhouetteGenerator *this)
{
  hkaiConvexSilhouetteSet *m_pntr; // rcx

  m_pntr = this->m_cachedSilhouettes.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_cachedSilhouettes.m_pntr = 0i64;
}

// File Line: 136
// RVA: 0xBD3C90
void __fastcall hkaiPointCloudSilhouetteGenerator::generateSilhouettesImmediate(
        hkaiPointCloudSilhouetteGenerator *this,
        hkQTransformf *localTransform,
        hkaiSilhouetteGenerationParameters *params,
        hkArrayBase<hkVector4f> *verticesOut,
        hkArrayBase<int> *sizesOut)
{
  char m_storage; // al
  int m_size; // ecx
  hkaiSilhouetteGenerationParameters *v8; // r10
  bool v10; // r15
  hkQTransformf *m_capacityAndFlags; // r8
  int v12; // edx
  int v13; // r12d
  bool v14; // r13
  hkArrayBase<int> *v15; // rdi
  __int64 v16; // rsi
  __m128 v17; // xmm1
  int v18; // r14d
  unsigned int v19; // ecx
  __int64 v20; // r9
  int v21; // edx
  __int64 v22; // r8
  __int64 v23; // [rsp+40h] [rbp-78h]
  hkArrayBase<hkVector4f> v24; // [rsp+48h] [rbp-70h] BYREF
  hkSimdFloat32 extraRadius; // [rsp+60h] [rbp-58h] BYREF
  hkSimdFloat32 weldTolerance; // [rsp+70h] [rbp-48h] BYREF
  int v27; // [rsp+C0h] [rbp+8h] BYREF
  hkQTransformf *transform; // [rsp+C8h] [rbp+10h]
  hkaiSilhouetteGenerationParameters *paramsa; // [rsp+D0h] [rbp+18h]

  paramsa = params;
  transform = localTransform;
  m_storage = this->m_silhouetteDetailLevel.m_storage;
  m_size = this->m_silhouetteSizes.m_size;
  v8 = params;
  v10 = m_storage == 2;
  m_capacityAndFlags = localTransform;
  if ( !m_size || (v12 = m_size, m_storage == 3) )
    v12 = 1;
  v13 = 0;
  v14 = !m_size || m_storage == 3;
  v15 = sizesOut;
  v16 = 0i64;
  v17 = _mm_shuffle_ps((__m128)LODWORD(this->m_weldTolerance), (__m128)LODWORD(this->m_weldTolerance), 0);
  v23 = v12;
  extraRadius.m_real = _mm_shuffle_ps(
                         (__m128)LODWORD(this->m_lazyRecomputeDisplacementThreshold),
                         (__m128)LODWORD(this->m_lazyRecomputeDisplacementThreshold),
                         0);
  weldTolerance.m_real = v17;
  if ( v12 <= 0 )
  {
LABEL_27:
    if ( !v10 )
      return;
  }
  else
  {
    while ( !v10 )
    {
      if ( v14 )
        v18 = this->m_localPoints.m_size;
      else
        v18 = this->m_silhouetteSizes.m_data[v16];
      v24.m_data = 0i64;
      v24.m_size = 0;
      v24.m_capacityAndFlags = 0x80000000;
      v27 = 2048;
      v24.m_data = (hkVector4f *)((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, int *, hkQTransformf *))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
                                   &hkContainerTempAllocator::s_alloc,
                                   &v27,
                                   m_capacityAndFlags);
      v19 = 0x80000000;
      v24.m_size = 128;
      if ( v27 / 16 )
        v19 = v27 / 16;
      v24.m_capacityAndFlags = v19;
      if ( hkaiConvex2dUtils::getSilhouetteFromPointCloud(
             &this->m_localPoints.m_data[v13],
             v18,
             paramsa,
             transform,
             &extraRadius,
             &weldTolerance,
             &v24)
        && (v21 = v24.m_size, (verticesOut->m_capacityAndFlags & 0x3FFFFFFF) - verticesOut->m_size >= v24.m_size)
        && (v15->m_capacityAndFlags & 0x3FFFFFFF) - v15->m_size >= 1 )
      {
        v20 = 0i64;
        if ( v24.m_size > 0 )
        {
          v22 = 0i64;
          do
          {
            v20 = (unsigned int)(v20 + 1);
            verticesOut->m_data[verticesOut->m_size] = v24.m_data[v22++];
            v21 = v24.m_size;
            ++verticesOut->m_size;
          }
          while ( (int)v20 < v21 );
        }
        v15->m_data[v15->m_size++] = v21;
        v13 += v18;
      }
      else
      {
        v10 = 1;
        verticesOut->m_size = 0;
        v15->m_size = 0;
      }
      m_capacityAndFlags = (hkQTransformf *)(unsigned int)v24.m_capacityAndFlags;
      v24.m_size = 0;
      if ( v24.m_capacityAndFlags >= 0 )
        ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkVector4f *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerTempAllocator::s_alloc,
          v24.m_data,
          (unsigned int)(16 * v24.m_capacityAndFlags),
          v20);
      ++v16;
      v24.m_data = 0i64;
      v24.m_capacityAndFlags = 0x80000000;
      if ( v16 >= v23 )
      {
        v8 = paramsa;
        m_capacityAndFlags = transform;
        goto LABEL_27;
      }
    }
    v8 = paramsa;
    m_capacityAndFlags = transform;
  }
  hkaiConvex2dUtils::createObbSilhouette(v8, &this->m_localAabb, m_capacityAndFlags, &extraRadius, verticesOut);
  v15->m_data[v15->m_size++] = verticesOut->m_size;
}

// File Line: 208
// RVA: 0xBD3F40
void __fastcall hkaiPointCloudSilhouetteGenerator::update(hkaiPointCloudSilhouetteGenerator *this, hkVector4f *up)
{
  bool v2; // zf

  v2 = this->m_localPointsChanged.m_bool == 0;
  this->m_flags.m_storage = 0;
  if ( !v2 )
    *(_WORD *)&this->m_flags.m_storage = 1;
}

// File Line: 219
// RVA: 0xBD4100
void __fastcall hkaiPointCloudSilhouetteGenerator::getLocalAabb(
        hkaiPointCloudSilhouetteGenerator *this,
        hkAabb *aabbOut)
{
  *aabbOut = this->m_localAabb;
}

// File Line: 224
// RVA: 0xBD4120
bool __fastcall hkaiPointCloudSilhouetteGenerator::isDirty(hkaiPointCloudSilhouetteGenerator *this)
{
  return this->m_flags.m_storage & 1;
}

// File Line: 231
// RVA: 0xBD4130
_BOOL8 __fastcall hkaiPointCloudSilhouetteGenerator::willGenerateSilhouettes(
        hkaiPointCloudSilhouetteGenerator *this,
        hkaiNavMeshInstance *meshInstance,
        hkVector4f *up)
{
  return this->m_isEnabled.m_bool != 0;
}

// File Line: 236
// RVA: 0xBD4180
void __fastcall hkaiPointCloudSilhouetteGenerator::getPoints(
        hkaiPointCloudSilhouetteGenerator *this,
        hkQTransformf *localTransform,
        hkArray<hkVector4f,hkContainerTempAllocator> *pointsOut)
{
  int m_size; // ebx
  int v4; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // ecx
  __int64 v11; // rdx
  __m128 v12; // xmm6
  __m128 m_quad; // xmm4
  __m128 v14; // xmm1
  __m128 v15; // xmm5
  __m128 v16; // xmm3
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  m_size = this->m_localPoints.m_size;
  v4 = pointsOut->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < m_size )
  {
    v8 = 2 * v4;
    v9 = this->m_localPoints.m_size;
    if ( m_size < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, pointsOut, v9, 16);
  }
  pointsOut->m_size = m_size;
  v10 = 0;
  if ( this->m_localPoints.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      ++v10;
      ++v11;
      v12 = _mm_shuffle_ps(localTransform->m_rotation.m_vec.m_quad, localTransform->m_rotation.m_vec.m_quad, 255);
      m_quad = this->m_localPoints.m_data[v11 - 1].m_quad;
      v14 = _mm_mul_ps(localTransform->m_rotation.m_vec.m_quad, m_quad);
      v15 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), localTransform->m_rotation.m_vec.m_quad),
              _mm_mul_ps(
                _mm_shuffle_ps(localTransform->m_rotation.m_vec.m_quad, localTransform->m_rotation.m_vec.m_quad, 201),
                m_quad));
      v16 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                    _mm_shuffle_ps(v14, v14, 170)),
                  localTransform->m_rotation.m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v12, v12), (__m128)xmmword_141A711B0), m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v12));
      pointsOut->m_data[v11 - 1].m_quad = _mm_add_ps(_mm_add_ps(v16, v16), localTransform->m_translation.m_quad);
    }
    while ( v10 < this->m_localPoints.m_size );
  }
}

// File Line: 245
// RVA: 0xBD3F70
void __fastcall hkaiPointCloudSilhouetteGenerator::getAabb(
        hkaiPointCloudSilhouetteGenerator *this,
        hkQTransformf *localTransform,
        hkAabb *aabbOut)
{
  __int64 m_size; // rdx
  hkVector4f v5; // xmm6
  hkVector4f v7; // xmm5
  hkVector4f v8; // xmm1
  __int64 v9; // r8
  hkQuaternionf v10; // xmm7
  __m128 v11; // xmm8
  __m128 v12; // xmm10
  hkVector4f v13; // xmm11
  __m128 v14; // xmm9
  hkVector4f *m_data; // rax
  __m128 m_quad; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm4
  __m128 v20; // xmm4
  hkAabb aabbOuta; // [rsp+20h] [rbp-88h] BYREF

  m_size = this->m_localPoints.m_size;
  v5.m_quad = (__m128)xmmword_141A712A0;
  aabbOuta.m_min = (hkVector4f)xmmword_141A712A0;
  v7.m_quad = _mm_xor_ps(
                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                (__m128)xmmword_141A712A0);
  aabbOuta.m_max = (hkVector4f)v7.m_quad;
  if ( (int)m_size < 128 || this->m_silhouetteDetailLevel.m_storage == 2 )
  {
    v9 = m_size;
    if ( (int)m_size > 0 )
    {
      v10.m_vec.m_quad = (__m128)localTransform->m_rotation;
      v11 = _mm_shuffle_ps(v10.m_vec.m_quad, v10.m_vec.m_quad, 255);
      v12 = _mm_shuffle_ps(v10.m_vec.m_quad, v10.m_vec.m_quad, 201);
      v13.m_quad = (__m128)localTransform->m_translation;
      v14 = _mm_sub_ps(_mm_mul_ps(v11, v11), (__m128)xmmword_141A711B0);
      m_data = this->m_localPoints.m_data;
      do
      {
        m_quad = m_data->m_quad;
        ++m_data;
        v17 = _mm_mul_ps(v10.m_vec.m_quad, m_quad);
        v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v10.m_vec.m_quad), _mm_mul_ps(v12, m_quad));
        v19 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                      _mm_shuffle_ps(v17, v17, 170)),
                    v10.m_vec.m_quad),
                  _mm_mul_ps(v14, m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v11));
        v20 = _mm_add_ps(_mm_add_ps(v19, v19), v13.m_quad);
        v5.m_quad = _mm_min_ps(v5.m_quad, v20);
        v7.m_quad = _mm_max_ps(v7.m_quad, v20);
        aabbOuta.m_min = (hkVector4f)v5.m_quad;
        aabbOuta.m_max = (hkVector4f)v7.m_quad;
        --v9;
      }
      while ( v9 );
    }
    aabbOut->m_min = (hkVector4f)v5.m_quad;
    aabbOut->m_max = (hkVector4f)v7.m_quad;
  }
  else
  {
    hkAabbUtil::calcAabb(localTransform, &this->m_localAabb, &aabbOuta);
    v8.m_quad = (__m128)aabbOuta.m_max;
    aabbOut->m_min = aabbOuta.m_min;
    aabbOut->m_max = (hkVector4f)v8.m_quad;
  }
}

// File Line: 274
// RVA: 0xBD44F0
void __fastcall generateSilhouettesFunc(
        hkaiSilhouetteGenerator *gen,
        hkQTransformf *localTransform,
        hkaiSilhouetteGenerationParameters *params,
        hkArrayBase<hkVector4f> *vertices,
        hkArrayBase<int> *sizes)
{
  ((void (__fastcall *)(hkaiSilhouetteGenerator *, hkQTransformf *, hkaiSilhouetteGenerationParameters *, hkArrayBase<hkVector4f> *))gen->vfptr[2].__first_virtual_table_function__)(
    gen,
    localTransform,
    params,
    vertices);
}

// File Line: 297
// RVA: 0xBD4500
void __fastcall getAabbFunc(hkaiSilhouetteGenerator *gen, hkQTransformf *localTransform, hkAabb *aabbOut)
{
  ((void (__fastcall *)(hkaiSilhouetteGenerator *, hkQTransformf *, hkAabb *))gen->vfptr[3].__first_virtual_table_function__)(
    gen,
    localTransform,
    aabbOut);
}

// File Line: 325
// RVA: 0xBD4150
void hkaiPointCloudSilhouetteGenerator::registerMtFunctions(void)
{
  g_generateSilhouettesFunc = generateSilhouettesFunc;
  g_getAabbFunc = getAabbFunc;
}

