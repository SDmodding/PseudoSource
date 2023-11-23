// File Line: 19
// RVA: 0xB488D0
void __fastcall hkaiNavMeshGenerationSettings::RegionPruningSettings::RegionPruningSettings(
        hkaiNavMeshGenerationSettings::RegionPruningSettings *this)
{
  this->m_minRegionArea = 5.0;
  this->m_minDistanceToSeedPoints = 1.0;
  this->m_borderPreservationTolerance = 0.1;
  *(_WORD *)&this->m_preserveVerticalBorderRegions.m_bool = 256;
  this->m_regionSeedPoints.m_capacityAndFlags = 0x80000000;
  this->m_regionSeedPoints.m_data = 0i64;
  this->m_regionSeedPoints.m_size = 0;
}

// File Line: 23
// RVA: 0xB48910
void __fastcall hkaiNavMeshGenerationSettings::RegionPruningSettings::getFaceAabbExpansion(
        hkaiNavMeshGenerationSettings::RegionPruningSettings *this,
        hkVector4f *up,
        hkVector4f *expansion)
{
  __m128 v3; // xmm4
  __m128 v4; // xmm1

  v3 = _mm_shuffle_ps(
         (__m128)LODWORD(this->m_borderPreservationTolerance),
         (__m128)LODWORD(this->m_borderPreservationTolerance),
         0);
  *expansion = (hkVector4f)v3;
  if ( !this->m_preserveVerticalBorderRegions.m_bool )
  {
    v4 = _mm_mul_ps(up->m_quad, v3);
    expansion->m_quad = _mm_sub_ps(
                          v3,
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)),
                              _mm_shuffle_ps(v4, v4, 170)),
                            up->m_quad));
  }
}

// File Line: 35
// RVA: 0xB48960
bool __fastcall hkaiNavMeshGenerationSettings::RegionPruningSettings::isRegionNearBoundary(
        hkAabb *regionAabb,
        hkAabb *meshAabb)
{
  return (_mm_movemask_ps(
            _mm_or_ps(
              _mm_cmplt_ps(meshAabb->m_max.m_quad, regionAabb->m_max.m_quad),
              _mm_cmplt_ps(regionAabb->m_min.m_quad, meshAabb->m_min.m_quad))) & 7) != 0;
}

// File Line: 49
// RVA: 0xB48230
void __fastcall hkaiNavMeshGenerationSettings::OverrideSettings::OverrideSettings(
        hkaiNavMeshGenerationSettings::OverrideSettings *this)
{
  this->m_volume.m_pntr = 0i64;
  this->m_material = -1;
  this->m_characterWidthUsage.m_storage = 1;
  this->m_maxWalkableSlope = 1.0471976;
  hkaiNavMeshEdgeMatchingParameters::hkaiNavMeshEdgeMatchingParameters(&this->m_edgeMatchingParams);
  hkaiNavMeshSimplificationUtils::Settings::Settings(&this->m_simplificationSettings);
}

// File Line: 56
// RVA: 0xB48280
void __fastcall hkaiNavMeshGenerationSettings::OverrideSettings::OverrideSettings(
        hkaiNavMeshGenerationSettings::OverrideSettings *this,
        hkFinishLoadedObjectFlag f)
{
  hkaiNavMeshSimplificationUtils::Settings::Settings(&this->m_simplificationSettings, f);
}

// File Line: 66
// RVA: 0xB482F0
void __fastcall hkaiNavMeshGenerationSettings::OverrideSettings::OverrideSettings(
        hkaiNavMeshGenerationSettings::OverrideSettings *this,
        hkaiNavMeshGenerationSettings *baseSettings)
{
  hkaiNavMeshSimplificationUtils::Settings *p_m_simplificationSettings; // rcx
  float m_maxSeparation; // eax
  hkaiNavMeshSimplificationUtils::Settings *v4; // rdx

  this->m_volume.m_pntr = 0i64;
  this->m_material = -1;
  this->m_characterWidthUsage.m_storage = baseSettings->m_characterWidthUsage.m_storage;
  this->m_maxWalkableSlope = baseSettings->m_maxWalkableSlope;
  p_m_simplificationSettings = &this->m_simplificationSettings;
  p_m_simplificationSettings[-1].m_extraVertexSettings.m_minPartitionArea = baseSettings->m_edgeMatchingParams.m_maxStepHeight;
  m_maxSeparation = baseSettings->m_edgeMatchingParams.m_maxSeparation;
  v4 = &baseSettings->m_simplificationSettings;
  *(float *)&p_m_simplificationSettings[-1].m_extraVertexSettings.m_numSmoothingIterations = m_maxSeparation;
  p_m_simplificationSettings[-1].m_extraVertexSettings.m_iterationDamping = v4[-2].m_extraVertexSettings.m_minPartitionArea;
  *(_DWORD *)&p_m_simplificationSettings[-1].m_extraVertexSettings.m_addVerticesOnBoundaryEdges.m_bool = v4[-2].m_extraVertexSettings.m_numSmoothingIterations;
  p_m_simplificationSettings[-1].m_extraVertexSettings.m_boundaryEdgeSplitLength = v4[-2].m_extraVertexSettings.m_iterationDamping;
  p_m_simplificationSettings[-1].m_extraVertexSettings.m_partitionBordersSplitLength = *(float *)&v4[-2].m_extraVertexSettings.m_addVerticesOnBoundaryEdges.m_bool;
  p_m_simplificationSettings[-1].m_extraVertexSettings.m_userVertexOnBoundaryTolerance = v4[-2].m_extraVertexSettings.m_boundaryEdgeSplitLength;
  *(float *)&p_m_simplificationSettings[-1].m_extraVertexSettings.m_userVertices.m_data = v4[-2].m_extraVertexSettings.m_partitionBordersSplitLength;
  HIDWORD(p_m_simplificationSettings[-1].m_extraVertexSettings.m_userVertices.m_data) = LODWORD(v4[-2].m_extraVertexSettings.m_userVertexOnBoundaryTolerance);
  p_m_simplificationSettings[-1].m_extraVertexSettings.m_userVertices.m_size = (int)v4[-2].m_extraVertexSettings.m_userVertices.m_data;
  p_m_simplificationSettings[-1].m_extraVertexSettings.m_userVertices.m_capacityAndFlags = HIDWORD(v4[-2].m_extraVertexSettings.m_userVertices.m_data);
  *(_DWORD *)&p_m_simplificationSettings[-1].m_saveInputSnapshot.m_bool = v4[-2].m_extraVertexSettings.m_userVertices.m_size;
  *((_DWORD *)&p_m_simplificationSettings[-1].m_saveInputSnapshot + 1) = v4[-2].m_extraVertexSettings.m_userVertices.m_capacityAndFlags;
  LODWORD(p_m_simplificationSettings[-1].m_snapshotFilename.m_stringAndFlag) = *(_DWORD *)&v4[-2].m_saveInputSnapshot.m_bool;
  hkaiNavMeshSimplificationUtils::Settings::Settings(p_m_simplificationSettings, v4);
}

// File Line: 70
// RVA: 0xB482B0
void __fastcall hkaiNavMeshGenerationSettings::OverrideSettings::~OverrideSettings(
        hkaiNavMeshGenerationSettings::OverrideSettings *this)
{
  hkaiNavMeshSimplificationUtils::Settings::~Settings(&this->m_simplificationSettings);
  if ( this->m_volume.m_pntr )
    hkReferencedObject::removeReference(this->m_volume.m_pntr);
  this->m_volume.m_pntr = 0i64;
}

// File Line: 75
// RVA: 0xB483B0
void __fastcall hkaiNavMeshGenerationSettings::OverrideSettings::setForBorderPreservation(
        hkaiNavMeshGenerationSettings::OverrideSettings *this)
{
  this->m_characterWidthUsage.m_storage = 0;
  hkaiNavMeshSimplificationUtils::Settings::setForBorderPreservation(&this->m_simplificationSettings);
}

// File Line: 83
// RVA: 0xB48990
void __fastcall hkaiNavMeshGenerationSettings::WallClimbingSettings::WallClimbingSettings(
        hkaiNavMeshGenerationSettings::WallClimbingSettings *this)
{
  *this = 0;
}

// File Line: 110
// RVA: 0xB483D0
void __fastcall hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings(hkaiNavMeshGenerationSettings *this)
{
  this->m_characterHeight = 1.75;
  this->m_quantizationGridSize = 0.0078125;
  this->m_maxWalkableSlope = 1.0471976;
  this->m_triangleWinding.m_storage = 0;
  this->m_degenerateWidthThreshold = 0.0049999999;
  this->m_convexThreshold = 0.1;
  this->m_maxNumEdgesPerFace = 255;
  this->m_degenerateAreaThreshold = 0.0;
  hkaiNavMeshEdgeMatchingParameters::hkaiNavMeshEdgeMatchingParameters(&this->m_edgeMatchingParams);
  this->m_edgeMatchingMetric.m_storage = 2;
  this->m_edgeConnectionIterations = 2;
  hkaiNavMeshGenerationSettings::RegionPruningSettings::RegionPruningSettings(&this->m_regionPruningSettings);
  hkaiNavMeshGenerationSettings::WallClimbingSettings::WallClimbingSettings(&this->m_wallClimbingSettings);
  this->m_carvers.m_data = 0i64;
  this->m_carvers.m_size = 0;
  this->m_carvers.m_capacityAndFlags = 0x80000000;
  this->m_painters.m_data = 0i64;
  this->m_painters.m_size = 0;
  this->m_painters.m_capacityAndFlags = 0x80000000;
  this->m_painterOverlapCallback = 0i64;
  this->m_defaultConstructionProperties.m_storage = 3;
  this->m_materialMap.m_data = 0i64;
  this->m_materialMap.m_size = 0;
  this->m_materialMap.m_capacityAndFlags = 0x80000000;
  this->m_weldInputVertices.m_bool = 1;
  *(_QWORD *)&this->m_weldThreshold = 1008981770i64;
  *(_WORD *)&this->m_characterWidthUsage.m_storage = 257;
  hkaiNavMeshSimplificationUtils::Settings::Settings(&this->m_simplificationSettings);
  this->m_carvedMaterialDeprecated = -1879048193;
  this->m_carvedCuttingMaterialDeprecated = -1879048194;
  *(_WORD *)&this->m_setBestFaceCenters.m_bool = 1;
  this->m_saveInputSnapshot.m_bool = 0;
  hkStringPtr::hkStringPtr(&this->m_snapshotFilename, 0i64);
  this->m_overrideSettings.m_data = 0i64;
  this->m_overrideSettings.m_size = 0;
  this->m_overrideSettings.m_capacityAndFlags = 0x80000000;
  this->m_up.m_quad = _xmm;
  this->m_boundsAabb.m_min = (hkVector4f)xmmword_141A712A0;
  this->m_boundsAabb.m_max.m_quad = _mm_xor_ps(
                                      (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                      (__m128)xmmword_141A712A0);
}

// File Line: 125
// RVA: 0xB48550
void __fastcall hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings(
        hkaiNavMeshGenerationSettings *this,
        hkFinishLoadedObjectFlag f)
{
  hkaiNavMeshSimplificationUtils::Settings::Settings(&this->m_simplificationSettings, f);
  hkStringPtr::hkStringPtr(&this->m_snapshotFilename, f);
}

// File Line: 130
// RVA: 0xB48590
void __fastcall hkaiNavMeshGenerationSettings::~hkaiNavMeshGenerationSettings(hkaiNavMeshGenerationSettings *this)
{
  hkaiNavMeshGenerationSettings::OverrideSettings *m_data; // rcx
  int v3; // edi
  hkaiNavMeshGenerationSettings::OverrideSettings *v4; // rsi
  int m_capacityAndFlags; // r8d
  int v6; // r8d
  hkRefPtr<hkaiMaterialPainter const > *v7; // rsi
  int v8; // eax
  __int64 i; // rdi
  hkReferencedObject *m_pntr; // rcx
  int v11; // r8d
  hkRefPtr<hkaiVolume const > *v12; // rsi
  int v13; // eax
  __int64 j; // rdi
  hkReferencedObject *v15; // rcx
  int v16; // r8d
  int v17; // r8d

  m_data = this->m_overrideSettings.m_data;
  v3 = this->m_overrideSettings.m_size - 1;
  if ( v3 >= 0 )
  {
    v4 = &m_data[v3];
    do
    {
      hkaiNavMeshGenerationSettings::OverrideSettings::~OverrideSettings(v4--);
      --v3;
    }
    while ( v3 >= 0 );
  }
  m_capacityAndFlags = this->m_overrideSettings.m_capacityAndFlags;
  this->m_overrideSettings.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_overrideSettings.m_data,
      240 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_overrideSettings.m_data = 0i64;
  this->m_overrideSettings.m_capacityAndFlags = 0x80000000;
  hkStringPtr::~hkStringPtr(&this->m_snapshotFilename);
  hkaiNavMeshSimplificationUtils::Settings::~Settings(&this->m_simplificationSettings);
  v6 = this->m_materialMap.m_capacityAndFlags;
  this->m_materialMap.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_materialMap.m_data,
      8 * v6);
  this->m_materialMap.m_data = 0i64;
  this->m_materialMap.m_capacityAndFlags = 0x80000000;
  v7 = this->m_painters.m_data;
  v8 = this->m_painters.m_size - 1;
  for ( i = v8; i >= 0; v7[i--].m_pntr = 0i64 )
  {
    m_pntr = v7[i].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
  }
  v11 = this->m_painters.m_capacityAndFlags;
  this->m_painters.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_painters.m_data,
      8 * v11);
  this->m_painters.m_data = 0i64;
  this->m_painters.m_capacityAndFlags = 0x80000000;
  v12 = this->m_carvers.m_data;
  v13 = this->m_carvers.m_size - 1;
  for ( j = v13; j >= 0; v12[j--].m_pntr = 0i64 )
  {
    v15 = v12[j].m_pntr;
    if ( v15 )
      hkReferencedObject::removeReference(v15);
  }
  v16 = this->m_carvers.m_capacityAndFlags;
  this->m_carvers.m_size = 0;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_carvers.m_data,
      8 * v16);
  this->m_carvers.m_data = 0i64;
  this->m_carvers.m_capacityAndFlags = 0x80000000;
  v17 = this->m_regionPruningSettings.m_regionSeedPoints.m_capacityAndFlags;
  this->m_regionPruningSettings.m_regionSeedPoints.m_size = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_regionPruningSettings.m_regionSeedPoints.m_data,
      16 * v17);
  this->m_regionPruningSettings.m_regionSeedPoints.m_data = 0i64;
  this->m_regionPruningSettings.m_regionSeedPoints.m_capacityAndFlags = 0x80000000;
}

// File Line: 136
// RVA: 0xB487D0
void __fastcall hkaiNavMeshGenerationSettings::setConstructionPropertiesForMaterial(
        hkaiNavMeshGenerationSettings *this,
        int materialIndex,
        unsigned int constructionFlags)
{
  hkArray<hkaiNavMeshGenerationSettings::MaterialConstructionPair,hkContainerHeapAllocator> *p_m_materialMap; // rbx
  __int64 m_size; // rdx
  hkaiNavMeshGenerationSettings::MaterialConstructionPair *v7; // r8

  p_m_materialMap = &this->m_materialMap;
  if ( this->m_materialMap.m_size == (this->m_materialMap.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_materialMap, 8);
  m_size = p_m_materialMap->m_size;
  v7 = &p_m_materialMap->m_data[m_size];
  p_m_materialMap->m_size = m_size + 1;
  v7->m_materialIndex = materialIndex;
  v7->m_flags.m_storage = constructionFlags;
}

// File Line: 143
// RVA: 0xB48840
void __fastcall hkaiNavMeshGenerationSettings::setSimplificationSettingsForMaterial(
        hkaiNavMeshGenerationSettings *this,
        int material,
        hkaiNavMeshSimplificationUtils::Settings *settings)
{
  hkArray<hkaiNavMeshGenerationSettings::OverrideSettings,hkContainerHeapAllocator> *p_m_overrideSettings; // rbx
  hkaiNavMeshGenerationSettings::OverrideSettings *v6; // rcx
  __int64 v7; // rcx

  p_m_overrideSettings = &this->m_overrideSettings;
  if ( this->m_overrideSettings.m_size == (this->m_overrideSettings.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_overrideSettings, 240);
  v6 = &p_m_overrideSettings->m_data[p_m_overrideSettings->m_size];
  if ( v6 )
    hkaiNavMeshGenerationSettings::OverrideSettings::OverrideSettings(v6);
  v7 = (__int64)&p_m_overrideSettings->m_data[p_m_overrideSettings->m_size++];
  *(_DWORD *)(v7 + 8) = material;
  hkaiNavMeshSimplificationUtils::Settings::operator=((hkaiNavMeshSimplificationUtils::Settings *)(v7 + 80), settings);
}

// File Line: 150
// RVA: 0xB48D30
__int64 __fastcall hkaiNavMeshGenerationSettings::getFirstOverrideSettingIndex(
        hkaiNavMeshGenerationSettings *this,
        hkArrayBase<hkVector4f> *points,
        int materialA,
        int materialB,
        bool checkMaterial)
{
  _DWORD *v7; // rdx
  int v8; // ebp
  int v9; // r9d
  int v10; // r8d
  __int64 v12; // r14
  hkaiNavMeshGenerationSettings::OverrideSettings *m_data; // rcx
  hkaiVolume *m_pntr; // rsi
  int v15; // ebx
  int m_material; // eax
  _BYTE *v18; // [rsp+20h] [rbp-48h] BYREF
  int v19; // [rsp+28h] [rbp-40h]
  int v20; // [rsp+2Ch] [rbp-3Ch]
  _DWORD v21[4]; // [rsp+30h] [rbp-38h] BYREF

  v7 = v21;
  v8 = 0;
  v9 = materialA;
  v10 = -2147483647;
  v18 = v21;
  v21[2] = 1;
  v20 = -2147483647;
  v19 = 1;
  v21[0] = 0;
  if ( this->m_overrideSettings.m_size <= 0 )
  {
LABEL_13:
    v8 = -1;
    goto LABEL_14;
  }
  v12 = 0i64;
  while ( 1 )
  {
    m_data = this->m_overrideSettings.m_data;
    m_pntr = m_data[v12].m_volume.m_pntr;
    if ( m_pntr )
      break;
    if ( checkMaterial )
    {
      m_material = m_data[v12].m_material;
      if ( m_material == v9 || m_material == materialB )
        goto LABEL_17;
    }
LABEL_11:
    ++v8;
    ++v12;
    if ( v8 >= this->m_overrideSettings.m_size )
    {
      v10 = v20;
      goto LABEL_13;
    }
  }
  v15 = 0;
  if ( points->m_size <= 0 )
    goto LABEL_11;
  while ( 1 )
  {
    *v7 &= ~1u;
    ((void (__fastcall *)(hkaiVolume *, hkVector4f *, __int64, _BYTE **))m_pntr->vfptr[2].__vecDelDtor)(
      m_pntr,
      &points->m_data[v15],
      1i64,
      &v18);
    v7 = v18;
    if ( (*v18 & 1) != 0 )
      break;
    if ( ++v15 >= points->m_size )
    {
      v9 = materialA;
      goto LABEL_11;
    }
  }
LABEL_17:
  v10 = v20;
LABEL_14:
  v19 = 0;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v7, 4 * v10);
  return (unsigned int)v8;
}

// File Line: 180
// RVA: 0xB489A0
_BOOL8 __fastcall hkaiNavMeshGenerationSettings::isWalkableBySlope(
        hkaiNavMeshGenerationSettings *this,
        hkVector4f *normal,
        hkArrayBase<hkVector4f> *points,
        int material)
{
  unsigned int v6; // xmm0_4
  __m128i si128; // xmm6
  __m128 v8; // xmm9
  __m128 v9; // xmm3
  __m128i v10; // xmm7
  __m128i v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm5
  __m128 v14; // xmm4
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm4

  *(float *)&v6 = hkaiNavMeshGenerationSettings::getMaxWalkableSlope(this, points, material);
  si128 = _mm_load_si128((const __m128i *)_xmm);
  v8 = _mm_add_ps((__m128)v6, *(__m128 *)_xmm);
  v9 = _mm_andnot_ps(*(__m128 *)_xmm, v8);
  v10 = _mm_add_epi32(si128, si128);
  v11 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(*(__m128 *)_xmm, v9)), si128));
  v12 = _mm_cvtepi32_ps(v11);
  v13 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v11, v10), (__m128i)0i64);
  v14 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)DP1_0, v12), v9), _mm_mul_ps(*(__m128 *)DP2, v12)),
          _mm_mul_ps(*(__m128 *)DP3, v12));
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_mul_ps(this->m_up.m_quad, normal->m_quad);
  v17 = (__m128)((_mm_andnot_ps(
                    v13,
                    _mm_add_ps(
                      _mm_sub_ps(
                        _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v15, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v15),
                              *(__m128 *)cosCoeff2_0),
                            v15),
                          v15),
                        _mm_mul_ps(v15, *(__m128 *)_xmm)),
                      *(__m128 *)_xmm)).m128_u32[0] | COERCE_UNSIGNED_INT(
                                                        (float)((float)((float)((float)((float)((float)(v15.m128_f32[0] * -0.00019515296)
                                                                                              + 0.0083321612)
                                                                                      * v15.m128_f32[0])
                                                                              + -0.16666655)
                                                                      * v15.m128_f32[0])
                                                              * v14.m128_f32[0])
                                                      + v14.m128_f32[0]) & v13.m128_i32[0]) ^ (_mm_and_si128(
                                                                                                 _mm_add_epi32(v10, v10),
                                                                                                 v11).m128i_u32[0] << 29) ^ _xmm[0] & v8.m128_i32[0]);
  return (float)((float)(_mm_shuffle_ps(v16, v16, 85).m128_f32[0] + _mm_shuffle_ps(v16, v16, 0).m128_f32[0])
               + _mm_shuffle_ps(v16, v16, 170).m128_f32[0]) >= fmax(
                                                                 _mm_shuffle_ps(v17, v17, 0).m128_f32[0],
                                                                 _mm_shuffle_ps(
                                                                   (__m128)LODWORD(FLOAT_0_0017453284),
                                                                   (__m128)LODWORD(FLOAT_0_0017453284),
                                                                   0).m128_f32[0]);
}

// File Line: 197
// RVA: 0xB48B60
__int64 __fastcall hkaiNavMeshGenerationSettings::getCharacterWidthUsage(
        hkaiNavMeshGenerationSettings *this,
        hkVector4f *point,
        int material)
{
  __m128 m_quad; // xmm0
  int FirstOverrideSettingIndex; // eax
  hkEnum<enum hkaiNavMeshGenerationSettings::CharacterWidthUsage,unsigned char> *p_m_characterWidthUsage; // rax
  unsigned int m_storage; // ebx
  hkArrayBase<hkVector4f> points; // [rsp+30h] [rbp-28h] BYREF
  __m128 v10; // [rsp+40h] [rbp-18h] BYREF

  m_quad = point->m_quad;
  points.m_capacityAndFlags = -2147483647;
  v10 = m_quad;
  points.m_data = (hkVector4f *)&v10;
  points.m_size = 1;
  FirstOverrideSettingIndex = hkaiNavMeshGenerationSettings::getFirstOverrideSettingIndex(
                                this,
                                &points,
                                material,
                                material,
                                1);
  if ( FirstOverrideSettingIndex == -1 )
    p_m_characterWidthUsage = &this->m_characterWidthUsage;
  else
    p_m_characterWidthUsage = &this->m_overrideSettings.m_data[FirstOverrideSettingIndex].m_characterWidthUsage;
  m_storage = (unsigned __int8)p_m_characterWidthUsage->m_storage;
  points.m_size = 0;
  if ( points.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      points.m_data,
      16 * points.m_capacityAndFlags);
  return m_storage;
}

// File Line: 204
// RVA: 0xB48C10
float __fastcall hkaiNavMeshGenerationSettings::getMaxWalkableSlope(
        hkaiNavMeshGenerationSettings *this,
        hkArrayBase<hkVector4f> *points,
        int material)
{
  int FirstOverrideSettingIndex; // eax

  FirstOverrideSettingIndex = hkaiNavMeshGenerationSettings::getFirstOverrideSettingIndex(
                                this,
                                points,
                                material,
                                material,
                                1);
  if ( FirstOverrideSettingIndex == -1 )
    return this->m_maxWalkableSlope;
  else
    return this->m_overrideSettings.m_data[FirstOverrideSettingIndex].m_maxWalkableSlope;
}

// File Line: 210
// RVA: 0xB48C60
hkaiNavMeshEdgeMatchingParameters *__fastcall hkaiNavMeshGenerationSettings::getEdgeMatchingParameters(
        hkaiNavMeshGenerationSettings *this,
        hkArrayBase<hkVector4f> *points,
        int materialA,
        int materialB)
{
  int FirstOverrideSettingIndex; // eax

  FirstOverrideSettingIndex = hkaiNavMeshGenerationSettings::getFirstOverrideSettingIndex(
                                this,
                                points,
                                materialA,
                                materialB,
                                1);
  if ( FirstOverrideSettingIndex == -1 )
    return &this->m_edgeMatchingParams;
  else
    return &this->m_overrideSettings.m_data[FirstOverrideSettingIndex].m_edgeMatchingParams;
}

// File Line: 216
// RVA: 0xB48CB0
hkaiNavMeshSimplificationUtils::Settings *__fastcall hkaiNavMeshGenerationSettings::getSimplificationSettings(
        hkaiNavMeshGenerationSettings *this,
        hkArrayBase<hkVector4f> *points,
        int localSettingsIndex)
{
  int FirstOverrideSettingIndex; // ecx
  int v7; // eax

  FirstOverrideSettingIndex = hkaiNavMeshGenerationSettings::getFirstOverrideSettingIndex(this, points, -1, 0, 1);
  if ( FirstOverrideSettingIndex < 0 && localSettingsIndex < 0 )
    return &this->m_simplificationSettings;
  v7 = localSettingsIndex;
  if ( FirstOverrideSettingIndex < localSettingsIndex )
    v7 = FirstOverrideSettingIndex;
  if ( FirstOverrideSettingIndex > localSettingsIndex )
    localSettingsIndex = FirstOverrideSettingIndex;
  if ( v7 < 0 )
    v7 = localSettingsIndex;
  return &this->m_overrideSettings.m_data[v7].m_simplificationSettings;
}

