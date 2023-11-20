// File Line: 19
// RVA: 0xB488D0
void __fastcall hkaiNavMeshGenerationSettings::RegionPruningSettings::RegionPruningSettings(hkaiNavMeshGenerationSettings::RegionPruningSettings *this)
{
  this->m_minRegionArea = 5.0;
  this->m_minDistanceToSeedPoints = 1.0;
  this->m_borderPreservationTolerance = 0.1;
  *(_WORD *)&this->m_preserveVerticalBorderRegions.m_bool = 256;
  this->m_regionSeedPoints.m_capacityAndFlags = 2147483648;
  this->m_regionSeedPoints.m_data = 0i64;
  this->m_regionSeedPoints.m_size = 0;
}

// File Line: 23
// RVA: 0xB48910
void __fastcall hkaiNavMeshGenerationSettings::RegionPruningSettings::getFaceAabbExpansion(hkaiNavMeshGenerationSettings::RegionPruningSettings *this, hkVector4f *up, hkVector4f *expansion)
{
  hkVector4f v3; // xmm4
  __m128 v4; // xmm1

  v3.m_quad = _mm_shuffle_ps(
                (__m128)LODWORD(this->m_borderPreservationTolerance),
                (__m128)LODWORD(this->m_borderPreservationTolerance),
                0);
  *expansion = (hkVector4f)v3.m_quad;
  if ( !this->m_preserveVerticalBorderRegions.m_bool )
  {
    v4 = _mm_mul_ps(up->m_quad, v3.m_quad);
    expansion->m_quad = _mm_sub_ps(
                          v3.m_quad,
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)),
                              _mm_shuffle_ps(v4, v4, 170)),
                            up->m_quad));
  }
}

// File Line: 35
// RVA: 0xB48960
bool __fastcall hkaiNavMeshGenerationSettings::RegionPruningSettings::isRegionNearBoundary(hkAabb *regionAabb, hkAabb *meshAabb)
{
  return (_mm_movemask_ps(
            _mm_or_ps(
              _mm_cmpltps(meshAabb->m_max.m_quad, regionAabb->m_max.m_quad),
              _mm_cmpltps(regionAabb->m_min.m_quad, meshAabb->m_min.m_quad))) & 7) != 0;
}

// File Line: 49
// RVA: 0xB48230
void __fastcall hkaiNavMeshGenerationSettings::OverrideSettings::OverrideSettings(hkaiNavMeshGenerationSettings::OverrideSettings *this)
{
  hkaiNavMeshGenerationSettings::OverrideSettings *v1; // rbx

  this->m_volume.m_pntr = 0i64;
  this->m_material = -1;
  this->m_characterWidthUsage.m_storage = 1;
  this->m_maxWalkableSlope = 1.0471976;
  v1 = this;
  hkaiNavMeshEdgeMatchingParameters::hkaiNavMeshEdgeMatchingParameters(&this->m_edgeMatchingParams);
  hkaiNavMeshSimplificationUtils::Settings::Settings(&v1->m_simplificationSettings);
}

// File Line: 56
// RVA: 0xB48280
void __fastcall hkaiNavMeshGenerationSettings::OverrideSettings::OverrideSettings(hkaiNavMeshGenerationSettings::OverrideSettings *this, hkFinishLoadedObjectFlag f)
{
  hkaiNavMeshSimplificationUtils::Settings::Settings(&this->m_simplificationSettings, f);
}

// File Line: 66
// RVA: 0xB482F0
void __fastcall hkaiNavMeshGenerationSettings::OverrideSettings::OverrideSettings(hkaiNavMeshGenerationSettings::OverrideSettings *this, hkaiNavMeshGenerationSettings *baseSettings)
{
  hkaiNavMeshSimplificationUtils::Settings *v2; // rcx
  float v3; // eax
  hkaiNavMeshSimplificationUtils::Settings *v4; // rdx

  this->m_volume.m_pntr = 0i64;
  this->m_material = -1;
  this->m_characterWidthUsage.m_storage = baseSettings->m_characterWidthUsage.m_storage;
  this->m_maxWalkableSlope = baseSettings->m_maxWalkableSlope;
  v2 = &this->m_simplificationSettings;
  v2[-1].m_extraVertexSettings.m_minPartitionArea = baseSettings->m_edgeMatchingParams.m_maxStepHeight;
  v3 = baseSettings->m_edgeMatchingParams.m_maxSeparation;
  v4 = &baseSettings->m_simplificationSettings;
  *(float *)&v2[-1].m_extraVertexSettings.m_numSmoothingIterations = v3;
  v2[-1].m_extraVertexSettings.m_iterationDamping = v4[-2].m_extraVertexSettings.m_minPartitionArea;
  *(_DWORD *)&v2[-1].m_extraVertexSettings.m_addVerticesOnBoundaryEdges.m_bool = v4[-2].m_extraVertexSettings.m_numSmoothingIterations;
  v2[-1].m_extraVertexSettings.m_boundaryEdgeSplitLength = v4[-2].m_extraVertexSettings.m_iterationDamping;
  v2[-1].m_extraVertexSettings.m_partitionBordersSplitLength = *(float *)&v4[-2].m_extraVertexSettings.m_addVerticesOnBoundaryEdges.m_bool;
  v2[-1].m_extraVertexSettings.m_userVertexOnBoundaryTolerance = v4[-2].m_extraVertexSettings.m_boundaryEdgeSplitLength;
  *(float *)&v2[-1].m_extraVertexSettings.m_userVertices.m_data = v4[-2].m_extraVertexSettings.m_partitionBordersSplitLength;
  HIDWORD(v2[-1].m_extraVertexSettings.m_userVertices.m_data) = LODWORD(v4[-2].m_extraVertexSettings.m_userVertexOnBoundaryTolerance);
  v2[-1].m_extraVertexSettings.m_userVertices.m_size = (int)v4[-2].m_extraVertexSettings.m_userVertices.m_data;
  v2[-1].m_extraVertexSettings.m_userVertices.m_capacityAndFlags = HIDWORD(v4[-2].m_extraVertexSettings.m_userVertices.m_data);
  *(_DWORD *)&v2[-1].m_saveInputSnapshot.m_bool = v4[-2].m_extraVertexSettings.m_userVertices.m_size;
  *((_DWORD *)&v2[-1].m_saveInputSnapshot + 1) = v4[-2].m_extraVertexSettings.m_userVertices.m_capacityAndFlags;
  LODWORD(v2[-1].m_snapshotFilename.m_stringAndFlag) = *(_DWORD *)&v4[-2].m_saveInputSnapshot.m_bool;
  hkaiNavMeshSimplificationUtils::Settings::Settings(v2, v4);
}

// File Line: 70
// RVA: 0xB482B0
void __fastcall hkaiNavMeshGenerationSettings::OverrideSettings::~OverrideSettings(hkaiNavMeshGenerationSettings::OverrideSettings *this)
{
  hkReferencedObject **v1; // rbx

  v1 = (hkReferencedObject **)this;
  hkaiNavMeshSimplificationUtils::Settings::~Settings(&this->m_simplificationSettings);
  if ( *v1 )
    hkReferencedObject::removeReference(*v1);
  *v1 = 0i64;
}

// File Line: 75
// RVA: 0xB483B0
void __fastcall hkaiNavMeshGenerationSettings::OverrideSettings::setForBorderPreservation(hkaiNavMeshGenerationSettings::OverrideSettings *this)
{
  this->m_characterWidthUsage.m_storage = 0;
  hkaiNavMeshSimplificationUtils::Settings::setForBorderPreservation(&this->m_simplificationSettings);
}

// File Line: 83
// RVA: 0xB48990
void __fastcall hkaiNavMeshGenerationSettings::WallClimbingSettings::WallClimbingSettings(hkaiNavMeshGenerationSettings::WallClimbingSettings *this)
{
  *this = 0;
}

// File Line: 110
// RVA: 0xB483D0
void __fastcall hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings(hkaiNavMeshGenerationSettings *this)
{
  hkaiNavMeshGenerationSettings *v1; // rbx

  this->m_characterHeight = 1.75;
  this->m_quantizationGridSize = 0.0078125;
  this->m_maxWalkableSlope = 1.0471976;
  this->m_triangleWinding.m_storage = 0;
  v1 = this;
  this->m_degenerateWidthThreshold = 0.0049999999;
  this->m_convexThreshold = 0.1;
  this->m_maxNumEdgesPerFace = 255;
  this->m_degenerateAreaThreshold = 0.0;
  hkaiNavMeshEdgeMatchingParameters::hkaiNavMeshEdgeMatchingParameters(&this->m_edgeMatchingParams);
  v1->m_edgeMatchingMetric.m_storage = 2;
  v1->m_edgeConnectionIterations = 2;
  hkaiNavMeshGenerationSettings::RegionPruningSettings::RegionPruningSettings(&v1->m_regionPruningSettings);
  hkaiNavMeshGenerationSettings::WallClimbingSettings::WallClimbingSettings(&v1->m_wallClimbingSettings);
  v1->m_carvers.m_data = 0i64;
  v1->m_carvers.m_size = 0;
  v1->m_carvers.m_capacityAndFlags = 2147483648;
  v1->m_painters.m_data = 0i64;
  v1->m_painters.m_size = 0;
  v1->m_painters.m_capacityAndFlags = 2147483648;
  v1->m_painterOverlapCallback = 0i64;
  v1->m_defaultConstructionProperties.m_storage = 3;
  v1->m_materialMap.m_data = 0i64;
  v1->m_materialMap.m_size = 0;
  v1->m_materialMap.m_capacityAndFlags = 2147483648;
  v1->m_weldInputVertices.m_bool = 1;
  *(_QWORD *)&v1->m_weldThreshold = 1008981770i64;
  *(_WORD *)&v1->m_characterWidthUsage.m_storage = 257;
  hkaiNavMeshSimplificationUtils::Settings::Settings(&v1->m_simplificationSettings);
  v1->m_carvedMaterialDeprecated = -1879048193;
  v1->m_carvedCuttingMaterialDeprecated = -1879048194;
  *(_WORD *)&v1->m_setBestFaceCenters.m_bool = 1;
  v1->m_saveInputSnapshot.m_bool = 0;
  hkStringPtr::hkStringPtr(&v1->m_snapshotFilename, 0i64);
  v1->m_overrideSettings.m_data = 0i64;
  v1->m_overrideSettings.m_size = 0;
  v1->m_overrideSettings.m_capacityAndFlags = 2147483648;
  v1->m_up.m_quad = _xmm;
  v1->m_boundsAabb.m_min = (hkVector4f)xmmword_141A712A0;
  v1->m_boundsAabb.m_max.m_quad = _mm_xor_ps(
                                    (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                    (__m128)xmmword_141A712A0);
}

// File Line: 125
// RVA: 0xB48550
void __fastcall hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings(hkaiNavMeshGenerationSettings *this, hkFinishLoadedObjectFlag f)
{
  hkaiNavMeshGenerationSettings *v2; // rbx
  int fa; // [rsp+38h] [rbp+10h]

  fa = f.m_finishing;
  v2 = this;
  hkaiNavMeshSimplificationUtils::Settings::Settings(&this->m_simplificationSettings, f);
  hkStringPtr::hkStringPtr(&v2->m_snapshotFilename, (hkFinishLoadedObjectFlag)fa);
}

// File Line: 130
// RVA: 0xB48590
void __fastcall hkaiNavMeshGenerationSettings::~hkaiNavMeshGenerationSettings(hkaiNavMeshGenerationSettings *this)
{
  hkaiNavMeshGenerationSettings *v1; // rbx
  hkaiNavMeshGenerationSettings::OverrideSettings *v2; // rcx
  int v3; // edi
  hkaiNavMeshGenerationSettings::OverrideSettings *v4; // rsi
  int v5; // er8
  int v6; // er8
  hkRefPtr<hkaiMaterialPainter const > *v7; // rsi
  int v8; // eax
  __int64 i; // rdi
  hkReferencedObject *v10; // rcx
  int v11; // er8
  hkRefPtr<hkaiVolume const > *v12; // rsi
  int v13; // eax
  __int64 j; // rdi
  hkReferencedObject *v15; // rcx
  int v16; // er8
  int v17; // er8

  v1 = this;
  v2 = this->m_overrideSettings.m_data;
  v3 = v1->m_overrideSettings.m_size - 1;
  if ( v3 >= 0 )
  {
    v4 = &v2[v3];
    do
    {
      hkaiNavMeshGenerationSettings::OverrideSettings::~OverrideSettings(v4);
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  v5 = v1->m_overrideSettings.m_capacityAndFlags;
  v1->m_overrideSettings.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_overrideSettings.m_data,
      240 * (v5 & 0x3FFFFFFF));
  v1->m_overrideSettings.m_data = 0i64;
  v1->m_overrideSettings.m_capacityAndFlags = 2147483648;
  hkStringPtr::~hkStringPtr(&v1->m_snapshotFilename);
  hkaiNavMeshSimplificationUtils::Settings::~Settings(&v1->m_simplificationSettings);
  v6 = v1->m_materialMap.m_capacityAndFlags;
  v1->m_materialMap.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_materialMap.m_data,
      8 * v6);
  v1->m_materialMap.m_data = 0i64;
  v1->m_materialMap.m_capacityAndFlags = 2147483648;
  v7 = v1->m_painters.m_data;
  v8 = v1->m_painters.m_size - 1;
  for ( i = v8; i >= 0; v7[i--].m_pntr = 0i64 )
  {
    v10 = (hkReferencedObject *)&v7[i].m_pntr->vfptr;
    if ( v10 )
      hkReferencedObject::removeReference(v10);
  }
  v11 = v1->m_painters.m_capacityAndFlags;
  v1->m_painters.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_painters.m_data,
      8 * v11);
  v1->m_painters.m_data = 0i64;
  v1->m_painters.m_capacityAndFlags = 2147483648;
  v12 = v1->m_carvers.m_data;
  v13 = v1->m_carvers.m_size - 1;
  for ( j = v13; j >= 0; v12[j--].m_pntr = 0i64 )
  {
    v15 = (hkReferencedObject *)&v12[j].m_pntr->vfptr;
    if ( v15 )
      hkReferencedObject::removeReference(v15);
  }
  v16 = v1->m_carvers.m_capacityAndFlags;
  v1->m_carvers.m_size = 0;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_carvers.m_data,
      8 * v16);
  v1->m_carvers.m_data = 0i64;
  v1->m_carvers.m_capacityAndFlags = 2147483648;
  v17 = v1->m_regionPruningSettings.m_regionSeedPoints.m_capacityAndFlags;
  v1->m_regionPruningSettings.m_regionSeedPoints.m_size = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_regionPruningSettings.m_regionSeedPoints.m_data,
      16 * v17);
  v1->m_regionPruningSettings.m_regionSeedPoints.m_data = 0i64;
  v1->m_regionPruningSettings.m_regionSeedPoints.m_capacityAndFlags = 2147483648;
}

// File Line: 136
// RVA: 0xB487D0
void __fastcall hkaiNavMeshGenerationSettings::setConstructionPropertiesForMaterial(hkaiNavMeshGenerationSettings *this, int materialIndex, unsigned int constructionFlags)
{
  signed int *v3; // rbx
  unsigned int v4; // edi
  int v5; // esi
  __int64 v6; // rdx
  int *v7; // r8

  v3 = (signed int *)&this->m_materialMap;
  v4 = constructionFlags;
  v5 = materialIndex;
  if ( this->m_materialMap.m_size == (this->m_materialMap.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 8);
  v6 = v3[2];
  v7 = (int *)(*(_QWORD *)v3 + 8 * v6);
  v3[2] = v6 + 1;
  *v7 = v5;
  v7[1] = v4;
}

// File Line: 143
// RVA: 0xB48840
void __fastcall hkaiNavMeshGenerationSettings::setSimplificationSettingsForMaterial(hkaiNavMeshGenerationSettings *this, int material, hkaiNavMeshSimplificationUtils::Settings *settings)
{
  signed int *v3; // rbx
  hkaiNavMeshSimplificationUtils::Settings *v4; // rdi
  int v5; // esi
  hkaiNavMeshGenerationSettings::OverrideSettings *v6; // rcx
  signed __int64 v7; // rcx

  v3 = (signed int *)&this->m_overrideSettings;
  v4 = settings;
  v5 = material;
  if ( this->m_overrideSettings.m_size == (this->m_overrideSettings.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 240);
  v6 = (hkaiNavMeshGenerationSettings::OverrideSettings *)(*(_QWORD *)v3 + 240i64 * v3[2]);
  if ( v6 )
    hkaiNavMeshGenerationSettings::OverrideSettings::OverrideSettings(v6);
  v7 = *(_QWORD *)v3 + 240i64 * v3[2]++;
  *(_DWORD *)(v7 + 8) = v5;
  hkaiNavMeshSimplificationUtils::Settings::operator=((hkaiNavMeshSimplificationUtils::Settings *)(v7 + 80), v4);
}

// File Line: 150
// RVA: 0xB48D30
__int64 __fastcall hkaiNavMeshGenerationSettings::getFirstOverrideSettingIndex(hkaiNavMeshGenerationSettings *this, hkArrayBase<hkVector4f> *points, int materialA, int materialB, bool checkMaterial)
{
  hkArrayBase<hkVector4f> *v5; // rdi
  int v6; // er13
  __int64 *v7; // rdx
  signed int v8; // ebp
  int v9; // er9
  signed int v10; // er8
  hkaiNavMeshGenerationSettings *v11; // r15
  __int64 v12; // r14
  hkaiNavMeshGenerationSettings::OverrideSettings *v13; // rcx
  hkaiVolume *v14; // rsi
  int v15; // ebx
  int v16; // eax
  __int64 *v18; // [rsp+20h] [rbp-48h]
  int v19; // [rsp+28h] [rbp-40h]
  int v20; // [rsp+2Ch] [rbp-3Ch]
  __int64 v21; // [rsp+30h] [rbp-38h]
  int v22; // [rsp+38h] [rbp-30h]
  int v23; // [rsp+80h] [rbp+18h]

  v23 = materialA;
  v5 = points;
  v6 = materialB;
  v7 = &v21;
  v8 = 0;
  v9 = materialA;
  v10 = -2147483647;
  v18 = &v21;
  v22 = 1;
  v20 = -2147483647;
  v11 = this;
  v19 = 1;
  LODWORD(v21) = 0;
  if ( this->m_overrideSettings.m_size <= 0 )
  {
LABEL_13:
    v8 = -1;
    goto LABEL_14;
  }
  v12 = 0i64;
  while ( 1 )
  {
    v13 = v11->m_overrideSettings.m_data;
    v14 = v13[v12].m_volume.m_pntr;
    if ( v14 )
      break;
    if ( checkMaterial )
    {
      v16 = v13[v12].m_material;
      if ( v16 == v9 || v16 == v6 )
        goto LABEL_17;
    }
LABEL_11:
    ++v8;
    ++v12;
    if ( v8 >= v11->m_overrideSettings.m_size )
    {
      v10 = v20;
      goto LABEL_13;
    }
  }
  v15 = 0;
  if ( v5->m_size <= 0 )
    goto LABEL_11;
  while ( 1 )
  {
    *(_DWORD *)v7 &= 0xFFFFFFFE;
    ((void (__fastcall *)(hkaiVolume *, hkVector4f *, signed __int64, __int64 **))v14->vfptr[2].__vecDelDtor)(
      v14,
      &v5->m_data[v15],
      1i64,
      &v18);
    v7 = v18;
    if ( *(_BYTE *)v18 & 1 )
      break;
    if ( ++v15 >= v5->m_size )
    {
      v9 = v23;
      goto LABEL_11;
    }
  }
LABEL_17:
  v10 = v20;
LABEL_14:
  v19 = 0;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v7,
      4 * v10);
  return (unsigned int)v8;
}

// File Line: 180
// RVA: 0xB489A0
signed __int64 __fastcall hkaiNavMeshGenerationSettings::isWalkableBySlope(hkaiNavMeshGenerationSettings *this, hkVector4f *normal, hkArrayBase<hkVector4f> *points, int material)
{
  hkVector4f *v4; // rdi
  hkaiNavMeshGenerationSettings *v5; // rbx
  unsigned int v6; // xmm0_4
  __m128i v7; // xmm6
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
  signed __int64 result; // rax

  v4 = normal;
  v5 = this;
  *(float *)&v6 = hkaiNavMeshGenerationSettings::getMaxWalkableSlope(this, points, material);
  v7 = _mm_load_si128((const __m128i *)_xmm);
  v8 = _mm_add_ps((__m128)v6, *(__m128 *)_xmm);
  v9 = _mm_andnot_ps(*(__m128 *)_xmm, v8);
  v10 = _mm_add_epi32(v7, v7);
  v11 = _mm_andnot_si128(v7, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(*(__m128 *)_xmm, v9)), v7));
  v12 = _mm_cvtepi32_ps(v11);
  v13 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v11, v10), (__m128i)0i64);
  v14 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)DP1_0, v12), v9), _mm_mul_ps(*(__m128 *)DP2, v12)),
          _mm_mul_ps(*(__m128 *)DP3, v12));
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_mul_ps(v5->m_up.m_quad, v4->m_quad);
  v17 = (__m128)(((unsigned int)*(_OWORD *)&_mm_andnot_ps(
                                              v13,
                                              _mm_add_ps(
                                                _mm_sub_ps(
                                                  _mm_mul_ps(
                                                    _mm_mul_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(
                                                          _mm_add_ps(
                                                            _mm_mul_ps(v15, *(__m128 *)cosCoeff0_0),
                                                            *(__m128 *)cosCoeff1),
                                                          v15),
                                                        *(__m128 *)cosCoeff2_0),
                                                      v15),
                                                    v15),
                                                  _mm_mul_ps(v15, *(__m128 *)_xmm)),
                                                *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                                      (float)((float)((float)((float)((float)((float)(v15.m128_f32[0] * -0.00019515296) + 0.0083321612) * v15.m128_f32[0])
                                                                                            + -0.16666655)
                                                                                    * v15.m128_f32[0])
                                                                            * v14.m128_f32[0])
                                                                    + v14.m128_f32[0]) & v13.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v10, v10), v11) << 29) ^ _xmm[0] & v8.m128_i32[0]);
  result = 0i64;
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 170))) >= fmax(
                                                                 COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 0)),
                                                                 COERCE_FLOAT(
                                                                   _mm_shuffle_ps(
                                                                     (__m128)LODWORD(FLOAT_0_0017453284),
                                                                     (__m128)LODWORD(FLOAT_0_0017453284),
                                                                     0))) )
    result = 1i64;
  return result;
}

// File Line: 197
// RVA: 0xB48B60
__int64 __fastcall hkaiNavMeshGenerationSettings::getCharacterWidthUsage(hkaiNavMeshGenerationSettings *this, hkVector4f *point, int material)
{
  __m128 v3; // xmm0
  hkaiNavMeshGenerationSettings *v4; // rbx
  int v5; // eax
  hkEnum<enum hkaiNavMeshGenerationSettings::CharacterWidthUsage,unsigned char> *v6; // rax
  unsigned int v7; // ebx
  hkArrayBase<hkVector4f> points; // [rsp+30h] [rbp-28h]
  __m128 v10; // [rsp+40h] [rbp-18h]

  v3 = point->m_quad;
  v4 = this;
  points.m_capacityAndFlags = -2147483647;
  v10 = v3;
  points.m_data = (hkVector4f *)&v10;
  points.m_size = 1;
  v5 = hkaiNavMeshGenerationSettings::getFirstOverrideSettingIndex(this, &points, material, material, 1);
  if ( v5 == -1 )
    v6 = &v4->m_characterWidthUsage;
  else
    v6 = &v4->m_overrideSettings.m_data[v5].m_characterWidthUsage;
  v7 = (unsigned __int8)v6->m_storage;
  points.m_size = 0;
  if ( points.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      points.m_data,
      16 * points.m_capacityAndFlags);
  return v7;
}

// File Line: 204
// RVA: 0xB48C10
float __fastcall hkaiNavMeshGenerationSettings::getMaxWalkableSlope(hkaiNavMeshGenerationSettings *this, hkArrayBase<hkVector4f> *points, int material)
{
  hkaiNavMeshGenerationSettings *v3; // rbx
  int v4; // eax
  float result; // xmm0_4

  v3 = this;
  v4 = hkaiNavMeshGenerationSettings::getFirstOverrideSettingIndex(this, points, material, material, 1);
  if ( v4 == -1 )
    result = v3->m_maxWalkableSlope;
  else
    result = v3->m_overrideSettings.m_data[v4].m_maxWalkableSlope;
  return result;
}

// File Line: 210
// RVA: 0xB48C60
hkaiNavMeshEdgeMatchingParameters *__fastcall hkaiNavMeshGenerationSettings::getEdgeMatchingParameters(hkaiNavMeshGenerationSettings *this, hkArrayBase<hkVector4f> *points, int materialA, int materialB)
{
  hkaiNavMeshGenerationSettings *v4; // rbx
  int v5; // eax
  hkaiNavMeshEdgeMatchingParameters *result; // rax

  v4 = this;
  v5 = hkaiNavMeshGenerationSettings::getFirstOverrideSettingIndex(this, points, materialA, materialB, 1);
  if ( v5 == -1 )
    result = &v4->m_edgeMatchingParams;
  else
    result = &v4->m_overrideSettings.m_data[v5].m_edgeMatchingParams;
  return result;
}

// File Line: 216
// RVA: 0xB48CB0
hkaiNavMeshSimplificationUtils::Settings *__fastcall hkaiNavMeshGenerationSettings::getSimplificationSettings(hkaiNavMeshGenerationSettings *this, hkArrayBase<hkVector4f> *points, int localSettingsIndex)
{
  int v3; // ebx
  hkaiNavMeshGenerationSettings *v4; // rdi
  int v5; // ecx
  int v7; // eax

  v3 = localSettingsIndex;
  v4 = this;
  v5 = hkaiNavMeshGenerationSettings::getFirstOverrideSettingIndex(this, points, -1, 0, 1);
  if ( v5 < 0 && v3 < 0 )
    return &v4->m_simplificationSettings;
  v7 = v3;
  if ( v5 < v3 )
    v7 = v5;
  if ( v5 > v3 )
    v3 = v5;
  if ( v7 < 0 )
    v7 = v3;
  return &v4->m_overrideSettings.m_data[v7].m_simplificationSettings;
}

