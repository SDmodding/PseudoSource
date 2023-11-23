// File Line: 15
// RVA: 0xB5ACD0
void __fastcall hkaiNavVolumeGenerationSettings::MaterialConstructionInfo::MaterialConstructionInfo(
        hkaiNavVolumeGenerationSettings::MaterialConstructionInfo *this)
{
  this->m_materialIndex = -1;
  this->m_flags.m_storage = 1;
  this->m_resolution = 1;
}

// File Line: 20
// RVA: 0xB5ACF0
void __fastcall hkaiNavVolumeGenerationSettings::MaterialConstructionInfo::MaterialConstructionInfo(
        hkaiNavVolumeGenerationSettings::MaterialConstructionInfo *this,
        hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 39
// RVA: 0xB5AD70
void __fastcall hkaiNavVolumeGenerationSettings::hkaiNavVolumeGenerationSettings(hkaiNavVolumeGenerationSettings *this)
{
  this->m_maxHorizontalRange = 10000.0;
  this->m_maxVerticalRange = 1000.0;
  *(_QWORD *)&this->m_characterHeight = 1071644672i64;
  this->m_characterWidth = 1.0;
  this->m_cellWidth = 1.0;
  this->m_resolutionRoundingMode.m_storage = 1;
  hkaiNavVolumeGenerationSettings::ChunkSettings::ChunkSettings(&this->m_chunkSettings);
  this->m_chunkDomainCallback = 0i64;
  this->m_border = 0.0099999998;
  this->m_useBorderCells.m_bool = 1;
  hkaiNavVolumeGenerationSettings::MergingSettings::MergingSettings(&this->m_mergingSettings);
  this->m_minRegionVolume = 1000.0;
  this->m_minDistanceToSeedPoints = 1.0;
  this->m_regionSeedPoints.m_data = 0i64;
  this->m_regionSeedPoints.m_size = 0;
  this->m_regionSeedPoints.m_capacityAndFlags = 0x80000000;
  hkaiNavVolumeGenerationSettings::MaterialConstructionInfo::MaterialConstructionInfo(&this->m_defaultConstructionInfo);
  this->m_materialMap.m_data = 0i64;
  this->m_materialMap.m_size = 0;
  this->m_materialMap.m_capacityAndFlags = 0x80000000;
  this->m_carvers.m_data = 0i64;
  this->m_carvers.m_size = 0;
  this->m_carvers.m_capacityAndFlags = 0x80000000;
  this->m_painters.m_data = 0i64;
  this->m_painters.m_size = 0;
  this->m_painters.m_capacityAndFlags = 0x80000000;
  this->m_saveInputSnapshot.m_bool = 0;
  hkStringPtr::hkStringPtr(&this->m_snapshotFilename, 0i64);
  this->m_volumeAabb.m_min = (hkVector4f)xmmword_141A712A0;
  this->m_volumeAabb.m_max.m_quad = _mm_xor_ps(
                                      (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                      this->m_volumeAabb.m_min.m_quad);
  this->m_up.m_quad = _xmm;
}

// File Line: 53
// RVA: 0xB5AEA0
void __fastcall hkaiNavVolumeGenerationSettings::hkaiNavVolumeGenerationSettings(
        hkaiNavVolumeGenerationSettings *this,
        hkFinishLoadedObjectFlag f)
{
  hkStringPtr::hkStringPtr(&this->m_snapshotFilename, f);
}

// File Line: 57
// RVA: 0xB5AED0
void __fastcall hkaiNavVolumeGenerationSettings::~hkaiNavVolumeGenerationSettings(
        hkaiNavVolumeGenerationSettings *this)
{
  hkRefPtr<hkaiMaterialPainter const > *m_data; // rsi
  int v3; // eax
  __int64 i; // rdi
  hkReferencedObject *m_pntr; // rcx
  int m_capacityAndFlags; // r8d
  hkRefPtr<hkaiVolume const > *v7; // rsi
  int v8; // eax
  __int64 j; // rdi
  hkReferencedObject *v10; // rcx
  int v11; // r8d
  int v12; // eax
  int v13; // r8d

  hkStringPtr::~hkStringPtr(&this->m_snapshotFilename);
  m_data = this->m_painters.m_data;
  v3 = this->m_painters.m_size - 1;
  for ( i = v3; i >= 0; m_data[i--].m_pntr = 0i64 )
  {
    m_pntr = m_data[i].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
  }
  m_capacityAndFlags = this->m_painters.m_capacityAndFlags;
  this->m_painters.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_painters.m_data,
      8 * m_capacityAndFlags);
  this->m_painters.m_data = 0i64;
  this->m_painters.m_capacityAndFlags = 0x80000000;
  v7 = this->m_carvers.m_data;
  v8 = this->m_carvers.m_size - 1;
  for ( j = v8; j >= 0; v7[j--].m_pntr = 0i64 )
  {
    v10 = v7[j].m_pntr;
    if ( v10 )
      hkReferencedObject::removeReference(v10);
  }
  v11 = this->m_carvers.m_capacityAndFlags;
  this->m_carvers.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_carvers.m_data,
      8 * v11);
  this->m_carvers.m_data = 0i64;
  this->m_carvers.m_capacityAndFlags = 0x80000000;
  v12 = this->m_materialMap.m_capacityAndFlags;
  this->m_materialMap.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_materialMap.m_data,
      12 * (v12 & 0x3FFFFFFF));
  this->m_materialMap.m_data = 0i64;
  this->m_materialMap.m_capacityAndFlags = 0x80000000;
  v13 = this->m_regionSeedPoints.m_capacityAndFlags;
  this->m_regionSeedPoints.m_size = 0;
  if ( v13 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_regionSeedPoints.m_data,
      16 * v13);
  this->m_regionSeedPoints.m_data = 0i64;
  this->m_regionSeedPoints.m_capacityAndFlags = 0x80000000;
}

// File Line: 65
// RVA: 0xB5AD00
void __fastcall hkaiNavVolumeGenerationSettings::ChunkSettings::ChunkSettings(
        hkaiNavVolumeGenerationSettings::ChunkSettings *this)
{
  *(_DWORD *)&this->m_maxChunkSizeX = 16777472;
  this->m_maxChunkSizeZ = 256;
}

// File Line: 69
// RVA: 0xB5AD20
void __fastcall hkaiNavVolumeGenerationSettings::MergingSettings::MergingSettings(
        hkaiNavVolumeGenerationSettings::MergingSettings *this)
{
  this->m_nodeWeight = 10.0;
  this->m_edgeWeight = 1.0;
  this->m_estimateNewEdges.m_bool = 1;
  this->m_multiplier = 1.0;
  this->m_randomSeed = 123;
  this->m_iterationsStabilizationThreshold = 10;
  this->m_slopeThreshold = 1.0;
  this->m_maxMergingIterations = 1000000;
  this->m_useSimpleFirstMergePass.m_bool = 1;
}

// File Line: 84
// RVA: 0xB5B090
void __fastcall hkaiNavVolumeGenerationSettings::setConstructionPropertiesForMaterial(
        hkaiNavVolumeGenerationSettings *this,
        int materialIndex,
        unsigned int constructionFlags,
        int resolution)
{
  hkArray<hkaiNavVolumeGenerationSettings::MaterialConstructionInfo,hkContainerHeapAllocator> *p_m_materialMap; // rbx
  hkaiNavVolumeGenerationSettings::MaterialConstructionInfo *v8; // rcx
  __int64 m_size; // rdx
  hkaiNavVolumeGenerationSettings::MaterialConstructionInfo *v10; // r8

  p_m_materialMap = &this->m_materialMap;
  if ( this->m_materialMap.m_size == (this->m_materialMap.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_materialMap, 12);
  v8 = &p_m_materialMap->m_data[p_m_materialMap->m_size];
  if ( v8 )
    hkaiNavVolumeGenerationSettings::MaterialConstructionInfo::MaterialConstructionInfo(v8);
  m_size = p_m_materialMap->m_size;
  v10 = &p_m_materialMap->m_data[m_size];
  p_m_materialMap->m_size = m_size + 1;
  v10->m_materialIndex = materialIndex;
  v10->m_flags.m_storage = constructionFlags;
  v10->m_resolution = resolution;
}

