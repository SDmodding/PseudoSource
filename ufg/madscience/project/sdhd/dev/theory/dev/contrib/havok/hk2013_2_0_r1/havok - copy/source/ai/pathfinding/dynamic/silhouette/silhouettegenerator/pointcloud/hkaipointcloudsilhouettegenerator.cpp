// File Line: 32
// RVA: 0xBD3840
void __fastcall hkaiPointCloudSilhouetteGenerator::hkaiPointCloudSilhouetteGenerator(hkaiPointCloudSilhouetteGenerator *this)
{
  __m128 *v1; // rbx

  v1 = (__m128 *)this;
  hkaiSilhouetteGenerator::hkaiSilhouetteGenerator((hkaiSilhouetteGenerator *)&this->vfptr, GENERATOR_POINT_CLOUD);
  v1->m128_u64[0] = (unsigned __int64)&hkaiPointCloudSilhouetteGenerator::`vftable';
  v1[7].m128_i32[3] = 2147483648;
  v1[7].m128_u64[0] = 0i64;
  v1[7].m128_i32[2] = 0;
  v1[8].m128_u64[0] = 0i64;
  v1[8].m128_i32[2] = 0;
  v1[8].m128_i32[3] = 2147483648;
  v1[5] = (__m128)xmmword_141A712A0;
  v1[6] = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v1[5]);
  v1[9].m128_i32[0] = 1008981770;
  v1[9].m128_i32[1] = 16843009;
}

// File Line: 45
// RVA: 0xBD38D0
void __fastcall hkaiPointCloudSilhouetteGenerator::hkaiPointCloudSilhouetteGenerator(hkaiPointCloudSilhouetteGenerator *this, hkFinishLoadedObjectFlag f)
{
  hkaiPointCloudSilhouetteGenerator *v2; // rbx

  v2 = this;
  hkaiSilhouetteGenerator::hkaiSilhouetteGenerator((hkaiSilhouetteGenerator *)&this->vfptr, f);
  v2->vfptr = (hkBaseObjectVtbl *)&hkaiPointCloudSilhouetteGenerator::`vftable';
}

// File Line: 51
// RVA: 0xBD3900
void __fastcall hkaiPointCloudSilhouetteGenerator::~hkaiPointCloudSilhouetteGenerator(hkaiPointCloudSilhouetteGenerator *this)
{
  hkaiPointCloudSilhouetteGenerator *v1; // rbx
  int v2; // er8
  int v3; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPointCloudSilhouetteGenerator::`vftable';
  v2 = this->m_silhouetteSizes.m_capacityAndFlags;
  this->m_silhouetteSizes.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_silhouetteSizes.m_data,
      4 * v2);
  v1->m_silhouetteSizes.m_data = 0i64;
  v1->m_silhouetteSizes.m_capacityAndFlags = 2147483648;
  v3 = v1->m_localPoints.m_capacityAndFlags;
  v1->m_localPoints.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_localPoints.m_data,
      16 * v3);
  v1->m_localPoints.m_data = 0i64;
  v1->m_localPoints.m_capacityAndFlags = 2147483648;
  hkaiSilhouetteGenerator::~hkaiSilhouetteGenerator((hkaiSilhouetteGenerator *)&v1->vfptr);
}

// File Line: 58
// RVA: 0xBD4430
void __fastcall hkaiPointCloudSilhouetteGenerator::setFromAabb(hkaiPointCloudSilhouetteGenerator *this, hkAabb *aabb)
{
  signed __int64 v2; // rdi
  hkAabb *v3; // rbx
  int v4; // eax
  hkaiPointCloudSilhouetteGenerator *v5; // rbp
  int v6; // eax
  int v7; // er9
  __int64 v8; // rcx
  const int *v9; // rdx
  __m128 v10; // xmm2
  hkResult result; // [rsp+40h] [rbp+8h]

  v2 = 8i64;
  v3 = aabb;
  v4 = this->m_localPoints.m_capacityAndFlags & 0x3FFFFFFF;
  v5 = this;
  if ( v4 < 8 )
  {
    v6 = 2 * v4;
    v7 = 8;
    if ( v6 > 8 )
      v7 = v6;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_localPoints,
      v7,
      16);
  }
  v5->m_localPoints.m_size = 8;
  v8 = 0i64;
  v9 = hkVector4fComparison_maskToComparison_168;
  do
  {
    v10 = *(__m128 *)v9;
    ++v8;
    v9 += 4;
    v5->m_localPoints.m_data[v8 - 1].m_quad = _mm_or_ps(
                                                _mm_andnot_ps(v10, v3->m_min.m_quad),
                                                _mm_and_ps(v3->m_max.m_quad, *((__m128 *)v9 - 1)));
    --v2;
  }
  while ( v2 );
  v5->m_localPointsChanged.m_bool = 1;
  v5->m_localAabb.m_min = v3->m_min;
  v5->m_localAabb.m_max = v3->m_max;
}

// File Line: 70
// RVA: 0xBD42A0
void __fastcall hkaiPointCloudSilhouetteGenerator::setLocalPoints(hkaiPointCloudSilhouetteGenerator *this, hkArrayBase<hkVector4f> *points, hkArray<int,hkContainerHeapAllocator> *sizes)
{
  hkArray<int,hkContainerHeapAllocator> *v3; // rsi
  hkArrayBase<hkVector4f> *v4; // rdi
  hkaiPointCloudSilhouetteGenerator *v5; // rbx
  __int64 v6; // rax
  int *v7; // rcx
  __int64 v8; // rdx
  char *v9; // r8
  int v10; // eax
  __int64 v11; // rax
  hkVector4f *v12; // rcx
  __int64 v13; // rdx
  char *v14; // r8
  hkVector4f v15; // xmm0
  int v16; // [rsp+30h] [rbp+8h]

  v3 = sizes;
  v4 = points;
  v5 = this;
  if ( (this->m_silhouetteSizes.m_capacityAndFlags & 0x3FFFFFFF) < sizes->m_size )
  {
    if ( this->m_silhouetteSizes.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        this->m_silhouetteSizes.m_data,
        4 * this->m_silhouetteSizes.m_capacityAndFlags);
    v16 = 4 * v3->m_size;
    v5->m_silhouetteSizes.m_data = (int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                            &v16);
    v5->m_silhouetteSizes.m_capacityAndFlags = v16 / 4;
  }
  v6 = v3->m_size;
  v7 = v5->m_silhouetteSizes.m_data;
  v5->m_silhouetteSizes.m_size = v6;
  v8 = v6;
  if ( (signed int)v6 > 0 )
  {
    v9 = (char *)((char *)v3->m_data - (char *)v7);
    do
    {
      v10 = *(int *)((char *)v7 + (_QWORD)v9);
      ++v7;
      *(v7 - 1) = v10;
      --v8;
    }
    while ( v8 );
  }
  if ( (v5->m_localPoints.m_capacityAndFlags & 0x3FFFFFFF) < v4->m_size )
  {
    if ( v5->m_localPoints.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v5->m_localPoints.m_data,
        16 * v5->m_localPoints.m_capacityAndFlags);
    v16 = 16 * v4->m_size;
    v5->m_localPoints.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                               (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                               &v16);
    v5->m_localPoints.m_capacityAndFlags = v16 / 16;
  }
  v11 = v4->m_size;
  v12 = v5->m_localPoints.m_data;
  v5->m_localPoints.m_size = v11;
  v13 = v11;
  if ( (signed int)v11 > 0 )
  {
    v14 = (char *)((char *)v4->m_data - (char *)v12);
    do
    {
      v15.m_quad = *(__m128 *)((char *)v12 + (_QWORD)v14);
      ++v12;
      v12[-1] = (hkVector4f)v15.m_quad;
      --v13;
    }
    while ( v13 );
  }
  v5->m_localPointsChanged.m_bool = 1;
  hkAabbUtil::calcAabb(v5->m_localPoints.m_data, v5->m_localPoints.m_size, &v5->m_localAabb);
  ((void (__fastcall *)(hkaiPointCloudSilhouetteGenerator *))v5->vfptr[2].__vecDelDtor)(v5);
}

// File Line: 79
// RVA: 0xBD39B0
hkaiConvexSilhouetteSet *__fastcall hkaiPointCloudSilhouetteGenerator::generateSilhouettesCached(hkaiPointCloudSilhouetteGenerator *this, hkQTransformf *localTransform, hkaiSilhouetteGenerationParameters *params)
{
  hkVector4f *up; // r12
  hkaiSilhouetteGenerationParameters *v4; // r14
  hkQTransformf *v5; // r15
  hkaiPointCloudSilhouetteGenerator *v6; // rdi
  hkVector4f *v8; // rax
  signed int v9; // ebx
  hkVector4f *v10; // r13
  int v11; // esi
  int *v12; // rax
  LPVOID v13; // rax
  hkLifoAllocator *v14; // rcx
  int v15; // edx
  char *v16; // r8
  hkBaseObjectVtbl *v17; // rax
  _QWORD **v18; // rax
  __int64 v19; // rax
  hkaiConvexSilhouetteSet *v20; // rbx
  hkReferencedObject *v21; // rcx
  int v22; // eax
  hkaiConvexSilhouetteSet *v23; // r14
  char *v24; // rdi
  signed int v25; // ebx
  hkLifoAllocator *v26; // rax
  int v27; // er8
  hkArrayBase<hkVector4f> vertexPool; // [rsp+30h] [rbp-30h]
  hkArrayBase<int> silhouetteSizes; // [rsp+40h] [rbp-20h]
  void *p; // [rsp+50h] [rbp-10h]
  int v31; // [rsp+58h] [rbp-8h]
  int v32; // [rsp+A0h] [rbp+40h]

  up = &params->m_referenceFrame.m_up;
  v4 = params;
  v5 = localTransform;
  v6 = this;
  if ( hkaiSilhouetteGenerator::canReuseCachedSilhouettes(
         (hkaiSilhouetteGenerator *)&this->vfptr,
         localTransform,
         &params->m_referenceFrame.m_up) )
  {
    return v6->m_cachedSilhouettes.m_pntr;
  }
  v32 = 2048;
  v8 = (hkVector4f *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                       (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                       &v32);
  v9 = v6->m_silhouetteSizes.m_size;
  v10 = v8;
  v11 = 2147483648;
  vertexPool.m_data = v8;
  vertexPool.m_capacityAndFlags = -2147483520;
  if ( v32 / 16 )
    v11 = v32 / 16;
  v12 = 0i64;
  vertexPool.m_size = 0;
  if ( !v9 || v6->m_silhouetteDetailLevel.m_storage == 3 )
    v9 = 1;
  silhouetteSizes.m_data = 0i64;
  silhouetteSizes.m_size = 0;
  silhouetteSizes.m_capacityAndFlags = 2147483648;
  v31 = v9;
  if ( v9 )
  {
    v13 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = (hkLifoAllocator *)v13;
    v12 = (int *)*((_QWORD *)v13 + 3);
    v15 = (4 * v9 + 127) & 0xFFFFFF80;
    v16 = (char *)v12 + v15;
    if ( v15 > v14->m_slabSize || v16 > v14->m_end )
      v12 = (int *)hkLifoAllocator::allocateFromNewSlab(v14, v15);
    else
      v14->m_cur = v16;
  }
  silhouetteSizes.m_data = v12;
  p = v12;
  v17 = v6->vfptr;
  silhouetteSizes.m_capacityAndFlags = v9 | 0x80000000;
  ((void (__fastcall *)(hkaiPointCloudSilhouetteGenerator *, hkQTransformf *, hkaiSilhouetteGenerationParameters *, hkArrayBase<hkVector4f> *, hkArrayBase<int> *))v17[2].__first_virtual_table_function__)(
    v6,
    v5,
    v4,
    &vertexPool,
    &silhouetteSizes);
  if ( !v6->m_cachedSilhouettes.m_pntr )
  {
    v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v19 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v18[11] + 8i64))(v18[11], 96i64);
    v20 = (hkaiConvexSilhouetteSet *)v19;
    if ( v19 )
    {
      *(_DWORD *)(v19 + 8) = 0x1FFFF;
      *(_QWORD *)v19 = &hkaiConvexSilhouetteSet::`vftable';
      *(_DWORD *)(v19 + 28) = 2147483648;
      *(_QWORD *)(v19 + 16) = 0i64;
      *(_DWORD *)(v19 + 24) = 0;
      *(_QWORD *)(v19 + 32) = 0i64;
      *(_DWORD *)(v19 + 40) = 0;
      *(_DWORD *)(v19 + 44) = 2147483648;
    }
    else
    {
      v20 = 0i64;
    }
    v21 = (hkReferencedObject *)&v6->m_cachedSilhouettes.m_pntr->vfptr;
    if ( v21 && v21 != (hkReferencedObject *)v20 )
      hkReferencedObject::removeReference(v21);
    v6->m_cachedSilhouettes.m_pntr = v20;
  }
  hkaiConvexSilhouetteSet::set(v6->m_cachedSilhouettes.m_pntr, &vertexPool, &silhouetteSizes, v5, up);
  v22 = silhouetteSizes.m_size;
  v23 = v6->m_cachedSilhouettes.m_pntr;
  v24 = (char *)p;
  if ( p == silhouetteSizes.m_data )
    v22 = 0;
  silhouetteSizes.m_size = v22;
  v25 = (4 * v31 + 127) & 0xFFFFFF80;
  v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (v25 + 15) & 0xFFFFFFF0;
  if ( v25 > v26->m_slabSize || &v24[v27] != v26->m_cur || v26->m_firstNonLifoEnd == v24 )
    hkLifoAllocator::slowBlockFree(v26, v24, v27);
  else
    v26->m_cur = v24;
  silhouetteSizes.m_size = 0;
  if ( silhouetteSizes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      silhouetteSizes.m_data,
      4 * silhouetteSizes.m_capacityAndFlags);
  silhouetteSizes.m_data = 0i64;
  silhouetteSizes.m_capacityAndFlags = 2147483648;
  if ( v11 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v10,
      16 * v11);
  return v23;
}

// File Line: 105
// RVA: 0xBD3C60
void __fastcall hkaiPointCloudSilhouetteGenerator::invalidateCachedSilhouettes(hkaiPointCloudSilhouetteGenerator *this)
{
  hkaiPointCloudSilhouetteGenerator *v1; // rbx
  hkaiConvexSilhouetteSet *v2; // rcx

  v1 = this;
  v2 = this->m_cachedSilhouettes.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_cachedSilhouettes.m_pntr = 0i64;
}

// File Line: 136
// RVA: 0xBD3C90
void __fastcall hkaiPointCloudSilhouetteGenerator::generateSilhouettesImmediate(hkaiPointCloudSilhouetteGenerator *this, hkQTransformf *localTransform, hkaiSilhouetteGenerationParameters *params, hkArrayBase<hkVector4f> *verticesOut, hkArrayBase<int> *sizesOut)
{
  char v5; // al
  hkaiPointCloudSilhouetteGenerator *v6; // rbp
  int v7; // ecx
  hkaiSilhouetteGenerationParameters *v8; // r10
  hkArrayBase<hkVector4f> *v9; // rbx
  bool v10; // r15
  hkQTransformf *v11; // r8
  signed int v12; // edx
  int v13; // er12
  bool v14; // r13
  hkArrayBase<int> *v15; // rdi
  __int64 v16; // rsi
  __m128 v17; // xmm1
  int v18; // er14
  unsigned int v19; // ecx
  __int64 v20; // r9
  int v21; // edx
  __int64 v22; // r8
  __int64 v23; // [rsp+40h] [rbp-78h]
  hkArrayBase<hkVector4f> v24; // [rsp+48h] [rbp-70h]
  hkSimdFloat32 extraRadius; // [rsp+60h] [rbp-58h]
  hkSimdFloat32 weldTolerance; // [rsp+70h] [rbp-48h]
  int v27; // [rsp+C0h] [rbp+8h]
  hkQTransformf *transform; // [rsp+C8h] [rbp+10h]
  hkaiSilhouetteGenerationParameters *paramsa; // [rsp+D0h] [rbp+18h]

  paramsa = params;
  transform = localTransform;
  v5 = this->m_silhouetteDetailLevel.m_storage;
  v6 = this;
  v7 = this->m_silhouetteSizes.m_size;
  v8 = params;
  v9 = verticesOut;
  v10 = v5 == 2;
  v11 = localTransform;
  if ( !v7 || (v12 = v7, v5 == 3) )
    v12 = 1;
  v13 = 0;
  v14 = !v7 || v5 == 3;
  v15 = sizesOut;
  v16 = 0i64;
  v17 = _mm_shuffle_ps((__m128)LODWORD(v6->m_weldTolerance), (__m128)LODWORD(v6->m_weldTolerance), 0);
  v23 = v12;
  extraRadius.m_real = _mm_shuffle_ps(
                         (__m128)LODWORD(v6->m_lazyRecomputeDisplacementThreshold),
                         (__m128)LODWORD(v6->m_lazyRecomputeDisplacementThreshold),
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
        v18 = v6->m_localPoints.m_size;
      else
        v18 = v6->m_silhouetteSizes.m_data[v16];
      v24.m_data = 0i64;
      v24.m_size = 0;
      v24.m_capacityAndFlags = 2147483648;
      v27 = 2048;
      v24.m_data = (hkVector4f *)((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, int *, hkQTransformf *))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
                                   &hkContainerTempAllocator::s_alloc,
                                   &v27,
                                   v11);
      v19 = 2147483648;
      v24.m_size = 128;
      if ( v27 / 16 )
        v19 = v27 / 16;
      v24.m_capacityAndFlags = v19;
      if ( hkaiConvex2dUtils::getSilhouetteFromPointCloud(
             &v6->m_localPoints.m_data[v13],
             v18,
             paramsa,
             transform,
             &extraRadius,
             &weldTolerance,
             &v24)
        && (v21 = v24.m_size, (v9->m_capacityAndFlags & 0x3FFFFFFF) - v9->m_size >= v24.m_size)
        && (v15->m_capacityAndFlags & 0x3FFFFFFF) - v15->m_size >= 1 )
      {
        v20 = 0i64;
        if ( v24.m_size > 0 )
        {
          v22 = 0i64;
          do
          {
            v20 = (unsigned int)(v20 + 1);
            ++v22;
            v9->m_data[v9->m_size] = v24.m_data[v22 - 1];
            v21 = v24.m_size;
            ++v9->m_size;
          }
          while ( (signed int)v20 < v21 );
        }
        v15->m_data[v15->m_size++] = v21;
        v13 += v18;
      }
      else
      {
        v10 = 1;
        v9->m_size = 0;
        v15->m_size = 0;
      }
      v11 = (hkQTransformf *)(unsigned int)v24.m_capacityAndFlags;
      v24.m_size = 0;
      if ( v24.m_capacityAndFlags >= 0 )
        ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkVector4f *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerTempAllocator::s_alloc,
          v24.m_data,
          (unsigned int)(16 * v24.m_capacityAndFlags),
          v20);
      ++v16;
      v24.m_data = 0i64;
      v24.m_capacityAndFlags = 2147483648;
      if ( v16 >= v23 )
      {
        v8 = paramsa;
        v11 = transform;
        goto LABEL_27;
      }
    }
    v8 = paramsa;
    v11 = transform;
  }
  hkaiConvex2dUtils::createObbSilhouette(v8, &v6->m_localAabb, v11, &extraRadius, v9);
  v15->m_data[v15->m_size++] = v9->m_size;
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
void __fastcall hkaiPointCloudSilhouetteGenerator::getLocalAabb(hkaiPointCloudSilhouetteGenerator *this, hkAabb *aabbOut)
{
  aabbOut->m_min = this->m_localAabb.m_min;
  aabbOut->m_max = this->m_localAabb.m_max;
}

// File Line: 224
// RVA: 0xBD4120
bool __fastcall hkaiPointCloudSilhouetteGenerator::isDirty(hkaiPointCloudSilhouetteGenerator *this)
{
  return this->m_flags.m_storage & 1;
}

// File Line: 231
// RVA: 0xBD4130
_BOOL8 __fastcall hkaiPointCloudSilhouetteGenerator::willGenerateSilhouettes(hkaiPointCloudSilhouetteGenerator *this, hkaiNavMeshInstance *meshInstance, hkVector4f *up)
{
  return this->m_isEnabled.m_bool != 0;
}

// File Line: 236
// RVA: 0xBD4180
void __fastcall hkaiPointCloudSilhouetteGenerator::getPoints(hkaiPointCloudSilhouetteGenerator *this, hkQTransformf *localTransform, hkArray<hkVector4f,hkContainerTempAllocator> *pointsOut)
{
  int v3; // ebx
  int v4; // eax
  hkArray<hkVector4f,hkContainerTempAllocator> *v5; // rdi
  hkQTransformf *v6; // rbp
  hkaiPointCloudSilhouetteGenerator *v7; // rsi
  int v8; // eax
  int v9; // er9
  int v10; // ecx
  __int64 v11; // rdx
  __m128 v12; // xmm6
  __m128 v13; // xmm4
  __m128 v14; // xmm1
  __m128 v15; // xmm5
  __m128 v16; // xmm3
  hkResult result; // [rsp+50h] [rbp+8h]

  v3 = this->m_localPoints.m_size;
  v4 = pointsOut->m_capacityAndFlags & 0x3FFFFFFF;
  v5 = pointsOut;
  v6 = localTransform;
  v7 = this;
  if ( v4 < v3 )
  {
    v8 = 2 * v4;
    v9 = this->m_localPoints.m_size;
    if ( v3 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, pointsOut, v9, 16);
  }
  v5->m_size = v3;
  v10 = 0;
  if ( v7->m_localPoints.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      ++v10;
      ++v11;
      v12 = _mm_shuffle_ps(v6->m_rotation.m_vec.m_quad, v6->m_rotation.m_vec.m_quad, 255);
      v13 = v7->m_localPoints.m_data[v11 - 1].m_quad;
      v14 = _mm_mul_ps(v6->m_rotation.m_vec.m_quad, v13);
      v15 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v6->m_rotation.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v6->m_rotation.m_vec.m_quad, v6->m_rotation.m_vec.m_quad, 201), v13));
      v16 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                    _mm_shuffle_ps(v14, v14, 170)),
                  v6->m_rotation.m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v12, v12), (__m128)xmmword_141A711B0), v13)),
              _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v12));
      v5->m_data[v11 - 1].m_quad = _mm_add_ps(_mm_add_ps(v16, v16), v6->m_translation.m_quad);
    }
    while ( v10 < v7->m_localPoints.m_size );
  }
}

// File Line: 245
// RVA: 0xBD3F70
void __fastcall hkaiPointCloudSilhouetteGenerator::getAabb(hkaiPointCloudSilhouetteGenerator *this, hkQTransformf *localTransform, hkAabb *aabbOut)
{
  hkQTransformf *v3; // rax
  __int64 v4; // rdx
  hkVector4f v5; // xmm6
  hkAabb *v6; // rbx
  hkVector4f v7; // xmm5
  hkVector4f v8; // xmm1
  __int64 v9; // r8
  __m128 v10; // xmm7
  __m128 v11; // xmm8
  __m128 v12; // xmm10
  __m128 v13; // xmm11
  __m128 v14; // xmm9
  hkVector4f *v15; // rax
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm4
  __m128 v20; // xmm4
  hkAabb aabbOuta; // [rsp+20h] [rbp-88h]

  v3 = localTransform;
  v4 = this->m_localPoints.m_size;
  v5.m_quad = (__m128)xmmword_141A712A0;
  aabbOuta.m_min = (hkVector4f)xmmword_141A712A0;
  v6 = aabbOut;
  v7.m_quad = _mm_xor_ps(
                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                (__m128)xmmword_141A712A0);
  aabbOuta.m_max = (hkVector4f)v7.m_quad;
  if ( (signed int)v4 < 128 || this->m_silhouetteDetailLevel.m_storage == 2 )
  {
    v9 = v4;
    if ( (signed int)v4 > 0 )
    {
      v10 = v3->m_rotation.m_vec.m_quad;
      v11 = _mm_shuffle_ps(v10, v10, 255);
      v12 = _mm_shuffle_ps(v10, v10, 201);
      v13 = v3->m_translation.m_quad;
      v14 = _mm_sub_ps(_mm_mul_ps(v11, v11), (__m128)xmmword_141A711B0);
      v15 = this->m_localPoints.m_data;
      do
      {
        v16 = v15->m_quad;
        ++v15;
        v17 = _mm_mul_ps(v10, v16);
        v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v10), _mm_mul_ps(v12, v16));
        v19 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                      _mm_shuffle_ps(v17, v17, 170)),
                    v10),
                  _mm_mul_ps(v14, v16)),
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v11));
        v20 = _mm_add_ps(_mm_add_ps(v19, v19), v13);
        v5.m_quad = _mm_min_ps(v5.m_quad, v20);
        v7.m_quad = _mm_max_ps(v7.m_quad, v20);
        aabbOuta.m_min = (hkVector4f)v5.m_quad;
        aabbOuta.m_max = (hkVector4f)v7.m_quad;
        --v9;
      }
      while ( v9 );
    }
    v6->m_min = (hkVector4f)v5.m_quad;
    v6->m_max = (hkVector4f)v7.m_quad;
  }
  else
  {
    hkAabbUtil::calcAabb(v3, &this->m_localAabb, &aabbOuta);
    v8.m_quad = (__m128)aabbOuta.m_max;
    v6->m_min = aabbOuta.m_min;
    v6->m_max = (hkVector4f)v8.m_quad;
  }
}

// File Line: 274
// RVA: 0xBD44F0
void __fastcall generateSilhouettesFunc(hkaiSilhouetteGenerator *gen, hkQTransformf *localTransform, hkaiSilhouetteGenerationParameters *params, hkArrayBase<hkVector4f> *vertices, hkArrayBase<int> *sizes)
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

