// File Line: 22
// RVA: 0xBE6850
void __fastcall hkaiAabbTreeNavVolumeMediator::hkaiAabbTreeNavVolumeMediator(hkaiAabbTreeNavVolumeMediator *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiAabbTreeNavVolumeMediator::`vftable;
  this->m_navVolume.m_pntr = 0i64;
  this->m_tree.m_pntr = 0i64;
}

// File Line: 29
// RVA: 0xBE6880
void __fastcall hkaiAabbTreeNavVolumeMediator::hkaiAabbTreeNavVolumeMediator(
        hkaiAabbTreeNavVolumeMediator *this,
        hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiAabbTreeNavVolumeMediator::`vftable;
}

// File Line: 35
// RVA: 0xBE68A0
void __fastcall hkaiAabbTreeNavVolumeMediator::~hkaiAabbTreeNavVolumeMediator(hkaiAabbTreeNavVolumeMediator *this)
{
  hkcdStaticAabbTree *m_pntr; // rcx
  hkaiNavVolume *v3; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiAabbTreeNavVolumeMediator::`vftable;
  m_pntr = this->m_tree.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_tree.m_pntr = 0i64;
  v3 = this->m_navVolume.m_pntr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  this->m_navVolume.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 39
// RVA: 0xBE6900
void __fastcall hkaiAabbTreeNavVolumeMediator::build(hkaiAabbTreeNavVolumeMediator *this, hkaiNavVolume *navVolume)
{
  hkaiNavVolume *m_pntr; // rcx
  int m_size; // ebp
  hkcdStaticAabbTree *v6; // rbx
  signed int v7; // r14d
  __int64 v8; // r15
  __m128i v9; // xmm2
  __m128i v10; // xmm5
  __m128i v11; // xmm0
  hkVector4f v12; // xmm2
  _QWORD **Value; // rax
  hkcdStaticAabbTree *v14; // rax
  hkcdStaticAabbTree *v15; // rax
  hkcdStaticAabbTree *v16; // rcx
  hkcdDynamicAabbTree dynTree; // [rsp+20h] [rbp-68h] BYREF
  hkAabb aabb; // [rsp+40h] [rbp-48h] BYREF
  hkResult result; // [rsp+90h] [rbp+8h] BYREF

  if ( !this->m_navVolume.m_pntr )
  {
    if ( navVolume )
      hkReferencedObject::addReference(navVolume);
    m_pntr = this->m_navVolume.m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
    this->m_navVolume.m_pntr = navVolume;
    hkcdDynamicAabbTree::hkcdDynamicAabbTree(&dynTree);
    m_size = navVolume->m_cells.m_size;
    hkcdDynamicAabbTree::reserveLeaves(&dynTree, &result, m_size);
    v6 = 0i64;
    v7 = 0;
    if ( m_size > 0 )
    {
      v8 = 0i64;
      do
      {
        v9 = _mm_loadu_si128((const __m128i *)&navVolume->m_cells.m_data[v8]);
        v10 = _mm_unpackhi_epi16(v9, (__m128i)0i64);
        v11 = _mm_unpacklo_epi16(v9, (__m128i)0i64);
        v12.m_quad = (__m128)navVolume->m_quantizationScale;
        aabb.m_min.m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                v12.m_quad,
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_cvtepi32_ps(_mm_srli_epi32(v11, 0x10u)),
                                    (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                                  _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v11, 0x10u), 0x10u)))),
                              navVolume->m_quantizationOffset.m_quad);
        aabb.m_max.m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                v12.m_quad,
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_cvtepi32_ps(_mm_srli_epi32(v10, 0x10u)),
                                    (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                                  _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v10, 0x10u), 0x10u)))),
                              navVolume->m_quantizationOffset.m_quad);
        hkcdDynamicAabbTree::insert(&dynTree, &aabb, v7++);
        ++v8;
      }
      while ( v7 < m_size );
    }
    hkcdDynamicAabbTree::rebuild(&dynTree);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = (hkcdStaticAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
    if ( v14 )
    {
      hkcdStaticAabbTree::hkcdStaticAabbTree(v14);
      v6 = v15;
    }
    v16 = this->m_tree.m_pntr;
    if ( v16 )
    {
      if ( v16 != v6 )
        hkReferencedObject::removeReference(v16);
    }
    this->m_tree.m_pntr = v6;
    hkcdStaticAabbTree::buildFromDynamicTree(v6, &dynTree);
    hkcdDynamicAabbTree::~hkcdDynamicAabbTree(&dynTree);
  }
}

// File Line: 69
// RVA: 0xBE6AC0
void __fastcall hkaiAabbTreeNavVolumeMediator::setNavVolumeAndTree(
        hkaiAabbTreeNavVolumeMediator *this,
        hkaiNavVolume *navVolume,
        hkcdStaticAabbTree *staticTree)
{
  hkaiNavVolume *m_pntr; // rcx
  hkcdStaticAabbTree *v7; // rcx

  if ( navVolume )
    hkReferencedObject::addReference(navVolume);
  m_pntr = this->m_navVolume.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_navVolume.m_pntr = navVolume;
  if ( staticTree )
    hkReferencedObject::addReference(staticTree);
  v7 = this->m_tree.m_pntr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  this->m_tree.m_pntr = staticTree;
}

// File Line: 88
// RVA: 0xBE6C90
hkSimdFloat32 *__fastcall NavVolumeClosestPointCollector::processLeaf(
        NavVolumeClosestPointCollector *this,
        hkSimdFloat32 *result,
        int leafKey,
        hkAabb *decompressedCellAabb,
        hkVector4f *queryPoint,
        hkVector4f *closestPointOut)
{
  hkaiNavVolumeMediator::GetClosestPointInput *m_gcpInput; // r9
  __int64 v8; // rsi
  hkaiSpatialQueryHitFilter *m_hitFilter; // rcx
  hkSimdFloat32 *v11; // rax
  hkaiNavVolume *m_navVolume; // rdx
  __m128i v13; // xmm2
  __m128i v14; // xmm0
  __m128 v15; // xmm5
  __m128i v16; // xmm0
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  __m128 v19; // xmm2

  m_gcpInput = this->m_gcpInput;
  v8 = leafKey;
  m_hitFilter = m_gcpInput->m_hitFilter;
  if ( !m_hitFilter
    || ((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavVolume *const, _QWORD, _QWORD, unsigned __int64))m_hitFilter->vfptr[3].__vecDelDtor)(
         m_hitFilter,
         this->m_navVolume,
         (unsigned int)leafKey,
         m_gcpInput->m_filterInfo,
         m_gcpInput->m_userData) )
  {
    m_navVolume = this->m_navVolume;
    v13 = _mm_loadu_si128((const __m128i *)&m_navVolume->m_cells.m_data[v8]);
    v14 = _mm_unpacklo_epi16(v13, (__m128i)0i64);
    v15 = _mm_add_ps(
            _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v14, 0x10u)), (__m128)`hkIntVector::convertU32ToF32::`2::two16),
            _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v14, 0x10u), 0x10u)));
    v16 = _mm_unpackhi_epi16(v13, (__m128i)0i64);
    v17 = _mm_max_ps(
            _mm_min_ps(
              queryPoint->m_quad,
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_cvtepi32_ps(_mm_srli_epi32(v16, 0x10u)),
                      (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                    _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v16, 0x10u), 0x10u))),
                  m_navVolume->m_quantizationScale.m_quad),
                m_navVolume->m_quantizationOffset.m_quad)),
            _mm_add_ps(
              _mm_mul_ps(v15, m_navVolume->m_quantizationScale.m_quad),
              m_navVolume->m_quantizationOffset.m_quad));
    *closestPointOut = (hkVector4f)v17;
    v18 = _mm_sub_ps(v17, queryPoint->m_quad);
    v11 = result;
    v19 = _mm_mul_ps(v18, v18);
    result->m_real = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                       _mm_shuffle_ps(v19, v19, 170));
  }
  else
  {
    v11 = result;
    *result = (hkSimdFloat32)xmmword_141A712A0;
  }
  return v11;
}

// File Line: 115
// RVA: 0xBE6C00
__int64 __fastcall getRuntimeIndexForVolumeInstance(hkaiNavVolumeInstance *meshInstance)
{
  __int64 result; // rax
  int m_runtimeId; // ecx

  result = 0i64;
  if ( meshInstance )
  {
    m_runtimeId = meshInstance->m_runtimeId;
    if ( m_runtimeId > 0 )
      return (unsigned int)m_runtimeId;
  }
  return result;
}

// File Line: 125
// RVA: 0xBE6B30
__int64 __fastcall hkaiAabbTreeNavVolumeMediator::getClosestPoint(
        hkaiAabbTreeNavVolumeMediator *this,
        hkaiNavVolumeMediator::GetClosestPointInput *gcpInput,
        hkVector4f *closestPointOut)
{
  hkaiSpatialQueryHitFilter *m_hitFilter; // rcx
  __m128 m_quad; // xmm0
  hkaiNavVolume *m_pntr; // rax
  hkVector4f *m_translation; // rax
  unsigned int ClosestPoint; // edx
  hkaiNavVolumeInstance *m_instance; // rcx
  int v12; // eax
  int m_runtimeId; // ecx
  hkVector4f point; // [rsp+30h] [rbp-38h] BYREF
  hkcdAabbTreeQueries::ClosestPointCollector collector; // [rsp+40h] [rbp-28h] BYREF
  hkaiNavVolume *v17; // [rsp+48h] [rbp-20h]
  hkaiNavVolumeMediator::GetClosestPointInput *v18; // [rsp+50h] [rbp-18h]

  m_hitFilter = gcpInput->m_hitFilter;
  if ( m_hitFilter
    && !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavVolume *, _QWORD, unsigned __int64))m_hitFilter->vfptr[2].__first_virtual_table_function__)(
          m_hitFilter,
          this->m_navVolume.m_pntr,
          gcpInput->m_filterInfo,
          gcpInput->m_userData) )
  {
    return 0xFFFFFFFFi64;
  }
  m_quad = gcpInput->m_position.m_quad;
  v18 = gcpInput;
  collector.vfptr = (hkcdAabbTreeQueries::ClosestPointCollectorVtbl *)&NavVolumeClosestPointCollector::`vftable;
  m_pntr = this->m_navVolume.m_pntr;
  point.m_quad = m_quad;
  v17 = m_pntr;
  m_translation = gcpInput->m_translation;
  if ( m_translation )
    point.m_quad = _mm_sub_ps(m_quad, m_translation->m_quad);
  ClosestPoint = hkcdStaticAabbTree::getClosestPoint(
                   this->m_tree.m_pntr,
                   &point,
                   &gcpInput->m_queryRadius,
                   &collector,
                   closestPointOut);
  if ( ClosestPoint == -1 )
    return 0xFFFFFFFFi64;
  m_instance = gcpInput->m_instance;
  v12 = 0;
  if ( m_instance )
  {
    m_runtimeId = m_instance->m_runtimeId;
    if ( m_runtimeId > 0 )
      v12 = m_runtimeId;
  }
  return ClosestPoint | (v12 << 22);
}

