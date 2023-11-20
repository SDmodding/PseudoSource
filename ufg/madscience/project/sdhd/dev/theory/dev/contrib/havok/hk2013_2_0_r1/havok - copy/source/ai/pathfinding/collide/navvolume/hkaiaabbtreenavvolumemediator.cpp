// File Line: 22
// RVA: 0xBE6850
void __fastcall hkaiAabbTreeNavVolumeMediator::hkaiAabbTreeNavVolumeMediator(hkaiAabbTreeNavVolumeMediator *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiAabbTreeNavVolumeMediator::`vftable';
  this->m_navVolume.m_pntr = 0i64;
  this->m_tree.m_pntr = 0i64;
}

// File Line: 29
// RVA: 0xBE6880
void __fastcall hkaiAabbTreeNavVolumeMediator::hkaiAabbTreeNavVolumeMediator(hkaiAabbTreeNavVolumeMediator *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiAabbTreeNavVolumeMediator::`vftable';
}

// File Line: 35
// RVA: 0xBE68A0
void __fastcall hkaiAabbTreeNavVolumeMediator::~hkaiAabbTreeNavVolumeMediator(hkaiAabbTreeNavVolumeMediator *this)
{
  hkaiAabbTreeNavVolumeMediator *v1; // rbx
  hkcdStaticAabbTree *v2; // rcx
  hkReferencedObject *v3; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiAabbTreeNavVolumeMediator::`vftable';
  v2 = this->m_tree.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_tree.m_pntr = 0i64;
  v3 = (hkReferencedObject *)&v1->m_navVolume.m_pntr->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v1->m_navVolume.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 39
// RVA: 0xBE6900
void __fastcall hkaiAabbTreeNavVolumeMediator::build(hkaiAabbTreeNavVolumeMediator *this, hkaiNavVolume *navVolume)
{
  hkaiNavVolume *v2; // rdi
  hkaiAabbTreeNavVolumeMediator *v3; // rsi
  hkReferencedObject *v4; // rcx
  int v5; // ebp
  hkcdStaticAabbTree *v6; // rbx
  signed int v7; // er14
  __int64 v8; // r15
  __m128i v9; // xmm5
  __m128i v10; // xmm2
  __m128 v11; // xmm4
  __m128 v12; // xmm0
  __m128 v13; // xmm2
  __m128 v14; // xmm4
  __m128i v15; // xmm0
  _QWORD **v16; // rax
  hkcdStaticAabbTree *v17; // rax
  hkcdStaticAabbTree *v18; // rax
  hkReferencedObject *v19; // rcx
  hkcdDynamicAabbTree dynTree; // [rsp+20h] [rbp-68h]
  hkAabb aabb; // [rsp+40h] [rbp-48h]
  hkResult result; // [rsp+90h] [rbp+8h]

  v2 = navVolume;
  v3 = this;
  if ( !this->m_navVolume.m_pntr )
  {
    if ( navVolume )
      hkReferencedObject::addReference((hkReferencedObject *)&navVolume->vfptr);
    v4 = (hkReferencedObject *)&v3->m_navVolume.m_pntr->vfptr;
    if ( v4 )
      hkReferencedObject::removeReference(v4);
    v3->m_navVolume.m_pntr = v2;
    hkcdDynamicAabbTree::hkcdDynamicAabbTree(&dynTree);
    v5 = v2->m_cells.m_size;
    hkcdDynamicAabbTree::reserveLeaves(&dynTree, &result, v2->m_cells.m_size);
    v6 = 0i64;
    v7 = 0;
    if ( v5 > 0 )
    {
      v8 = 0i64;
      do
      {
        v9 = _mm_loadu_si128((const __m128i *)&v2->m_cells.m_data[v8]);
        v10 = _mm_unpacklo_epi16(v9, (__m128i)0i64);
        v11 = _mm_cvtepi32_ps(_mm_srli_epi32(v10, 0x10u));
        v12 = _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v10, 0x10u), 0x10u));
        v13 = v2->m_quantizationScale.m_quad;
        v14 = _mm_add_ps(_mm_mul_ps(v11, (__m128)`hkIntVector::convertU32ToF32'::`2'::two16), v12);
        v15 = _mm_unpackhi_epi16(v9, (__m128i)0i64);
        aabb.m_min.m_quad = _mm_add_ps(_mm_mul_ps(v2->m_quantizationScale.m_quad, v14), v2->m_quantizationOffset.m_quad);
        aabb.m_max.m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                v13,
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_cvtepi32_ps(_mm_srli_epi32(v15, 0x10u)),
                                    (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
                                  _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v15, 0x10u), 0x10u)))),
                              v2->m_quantizationOffset.m_quad);
        hkcdDynamicAabbTree::insert(&dynTree, &aabb, v7++);
        ++v8;
      }
      while ( v7 < v5 );
    }
    hkcdDynamicAabbTree::rebuild(&dynTree);
    v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (hkcdStaticAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v16[11] + 8i64))(v16[11], 32i64);
    if ( v17 )
    {
      hkcdStaticAabbTree::hkcdStaticAabbTree(v17);
      v6 = v18;
    }
    v19 = (hkReferencedObject *)&v3->m_tree.m_pntr->vfptr;
    if ( v19 )
    {
      if ( v19 != (hkReferencedObject *)v6 )
        hkReferencedObject::removeReference(v19);
    }
    v3->m_tree.m_pntr = v6;
    hkcdStaticAabbTree::buildFromDynamicTree(v6, &dynTree);
    hkcdDynamicAabbTree::~hkcdDynamicAabbTree(&dynTree);
  }
}

// File Line: 69
// RVA: 0xBE6AC0
void __fastcall hkaiAabbTreeNavVolumeMediator::setNavVolumeAndTree(hkaiAabbTreeNavVolumeMediator *this, hkaiNavVolume *navVolume, hkcdStaticAabbTree *staticTree)
{
  hkcdStaticAabbTree *v3; // rdi
  hkaiNavVolume *v4; // rsi
  hkaiAabbTreeNavVolumeMediator *v5; // rbx
  hkReferencedObject *v6; // rcx
  hkReferencedObject *v7; // rcx

  v3 = staticTree;
  v4 = navVolume;
  v5 = this;
  if ( navVolume )
    hkReferencedObject::addReference((hkReferencedObject *)&navVolume->vfptr);
  v6 = (hkReferencedObject *)&v5->m_navVolume.m_pntr->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v5->m_navVolume.m_pntr = v4;
  if ( v3 )
    hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
  v7 = (hkReferencedObject *)&v5->m_tree.m_pntr->vfptr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  v5->m_tree.m_pntr = v3;
}

// File Line: 88
// RVA: 0xBE6C90
hkSimdFloat32 *__fastcall NavVolumeClosestPointCollector::processLeaf(NavVolumeClosestPointCollector *this, hkSimdFloat32 *result, unsigned int leafKey, hkAabb *decompressedCellAabb, hkVector4f *queryPoint, hkVector4f *closestPointOut)
{
  hkaiNavVolumeMediator::GetClosestPointInput *v6; // r9
  NavVolumeClosestPointCollector *v7; // rdi
  __int64 v8; // rsi
  hkaiSpatialQueryHitFilter *v9; // rcx
  hkSimdFloat32 *v10; // rbx
  hkSimdFloat32 *v11; // rax
  __m128 *v12; // rdx
  __m128i v13; // xmm4
  __m128i v14; // xmm2
  __m128i v15; // xmm4
  __m128i v16; // xmm2
  hkVector4f v17; // xmm2
  __m128 v18; // xmm2
  __m128 v19; // xmm2

  v6 = this->m_gcpInput;
  v7 = this;
  v8 = (signed int)leafKey;
  v9 = v6->m_hitFilter;
  v10 = result;
  if ( !v9
    || ((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavVolume *const , _QWORD, _QWORD, unsigned __int64))v9->vfptr[3].__vecDelDtor)(
         v9,
         v7->m_navVolume,
         leafKey,
         v6->m_filterInfo,
         v6->m_userData) )
  {
    v12 = (__m128 *)v7->m_navVolume;
    v13 = _mm_loadu_si128((const __m128i *)(v12[1].m128_u64[0] + 24 * v8));
    v14 = v13;
    v15 = _mm_unpackhi_epi16(v13, (__m128i)0i64);
    v16 = _mm_unpacklo_epi16(v14, (__m128i)0i64);
    v17.m_quad = _mm_max_ps(
                   _mm_min_ps(
                     queryPoint->m_quad,
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_cvtepi32_ps(_mm_srli_epi32(v15, 0x10u)),
                             (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
                           _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v15, 0x10u), 0x10u))),
                         v12[6]),
                       v12[7])),
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_cvtepi32_ps(_mm_srli_epi32(v16, 0x10u)),
                           (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
                         _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v16, 0x10u), 0x10u))),
                       v12[6]),
                     v12[7]));
    *closestPointOut = (hkVector4f)v17.m_quad;
    v18 = _mm_sub_ps(v17.m_quad, queryPoint->m_quad);
    v11 = v10;
    v19 = _mm_mul_ps(v18, v18);
    v10->m_real = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                    _mm_shuffle_ps(v19, v19, 170));
  }
  else
  {
    v11 = v10;
    *v10 = (hkSimdFloat32)xmmword_141A712A0;
  }
  return v11;
}

// File Line: 115
// RVA: 0xBE6C00
__int64 __fastcall getRuntimeIndexForVolumeInstance(hkaiNavVolumeInstance *meshInstance)
{
  __int64 result; // rax
  int v2; // ecx

  result = 0i64;
  if ( meshInstance )
  {
    v2 = meshInstance->m_runtimeId;
    if ( v2 > 0 )
      result = (unsigned int)v2;
  }
  return result;
}

// File Line: 125
// RVA: 0xBE6B30
signed __int64 __fastcall hkaiAabbTreeNavVolumeMediator::getClosestPoint(hkaiAabbTreeNavVolumeMediator *this, hkaiNavVolumeMediator::GetClosestPointInput *gcpInput, hkVector4f *closestPointOut)
{
  hkaiAabbTreeNavVolumeMediator *v3; // rdi
  hkaiSpatialQueryHitFilter *v4; // rcx
  hkVector4f *v5; // rsi
  hkaiNavVolumeMediator::GetClosestPointInput *v6; // rbx
  __m128 v7; // xmm0
  __int64 v8; // rax
  __m128 *v9; // rax
  unsigned int v10; // edx
  hkaiNavVolumeInstance *v11; // rcx
  int v12; // eax
  int v13; // ecx
  hkVector4f point; // [rsp+30h] [rbp-38h]
  hkcdAabbTreeQueries::ClosestPointCollector collector; // [rsp+40h] [rbp-28h]
  __int64 v17; // [rsp+48h] [rbp-20h]
  hkaiNavVolumeMediator::GetClosestPointInput *v18; // [rsp+50h] [rbp-18h]

  v3 = this;
  v4 = gcpInput->m_hitFilter;
  v5 = closestPointOut;
  v6 = gcpInput;
  if ( v4
    && !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavVolume *, _QWORD, unsigned __int64))v4->vfptr[2].__first_virtual_table_function__)(
          v4,
          v3->m_navVolume.m_pntr,
          gcpInput->m_filterInfo,
          gcpInput->m_userData) )
  {
    return 0xFFFFFFFFi64;
  }
  v7 = v6->m_position.m_quad;
  v18 = v6;
  collector.vfptr = (hkcdAabbTreeQueries::ClosestPointCollectorVtbl *)&NavVolumeClosestPointCollector::`vftable';
  v8 = (__int64)v3->m_navVolume.m_pntr;
  point.m_quad = v7;
  v17 = v8;
  v9 = &v6->m_translation->m_quad;
  if ( v9 )
    point.m_quad = _mm_sub_ps(v7, *v9);
  v10 = hkcdStaticAabbTree::getClosestPoint(v3->m_tree.m_pntr, &point, &v6->m_queryRadius, &collector, v5);
  if ( v10 == -1 )
    return 0xFFFFFFFFi64;
  v11 = v6->m_instance;
  v12 = 0;
  if ( v11 )
  {
    v13 = v11->m_runtimeId;
    if ( v13 > 0 )
      v12 = v13;
  }
  return v10 | (v12 << 22);
}

