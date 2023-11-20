// File Line: 15
// RVA: 0xB5ACD0
void __fastcall hkaiNavVolumeGenerationSettings::MaterialConstructionInfo::MaterialConstructionInfo(hkaiNavVolumeGenerationSettings::MaterialConstructionInfo *this)
{
  this->m_materialIndex = -1;
  this->m_flags.m_storage = 1;
  this->m_resolution = 1;
}

// File Line: 20
// RVA: 0xB5ACF0
void __fastcall hkaiNavVolumeGenerationSettings::MaterialConstructionInfo::MaterialConstructionInfo(hkaiNavVolumeGenerationSettings::MaterialConstructionInfo *this, hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 39
// RVA: 0xB5AD70
void __fastcall hkaiNavVolumeGenerationSettings::hkaiNavVolumeGenerationSettings(hkaiNavVolumeGenerationSettings *this)
{
  hkaiNavVolumeGenerationSettings *v1; // rbx

  this->m_maxHorizontalRange = 10000.0;
  this->m_maxVerticalRange = 1000.0;
  *(_QWORD *)&this->m_characterHeight = 1071644672i64;
  this->m_characterWidth = 1.0;
  this->m_cellWidth = 1.0;
  v1 = this;
  this->m_resolutionRoundingMode.m_storage = 1;
  hkaiNavVolumeGenerationSettings::ChunkSettings::ChunkSettings(&this->m_chunkSettings);
  v1->m_chunkDomainCallback = 0i64;
  v1->m_border = 0.0099999998;
  v1->m_useBorderCells.m_bool = 1;
  hkaiNavVolumeGenerationSettings::MergingSettings::MergingSettings(&v1->m_mergingSettings);
  v1->m_minRegionVolume = 1000.0;
  v1->m_minDistanceToSeedPoints = 1.0;
  v1->m_regionSeedPoints.m_data = 0i64;
  v1->m_regionSeedPoints.m_size = 0;
  v1->m_regionSeedPoints.m_capacityAndFlags = 2147483648;
  hkaiNavVolumeGenerationSettings::MaterialConstructionInfo::MaterialConstructionInfo(&v1->m_defaultConstructionInfo);
  v1->m_materialMap.m_data = 0i64;
  v1->m_materialMap.m_size = 0;
  v1->m_materialMap.m_capacityAndFlags = 2147483648;
  v1->m_carvers.m_data = 0i64;
  v1->m_carvers.m_size = 0;
  v1->m_carvers.m_capacityAndFlags = 2147483648;
  v1->m_painters.m_data = 0i64;
  v1->m_painters.m_size = 0;
  v1->m_painters.m_capacityAndFlags = 2147483648;
  v1->m_saveInputSnapshot.m_bool = 0;
  hkStringPtr::hkStringPtr(&v1->m_snapshotFilename, 0i64);
  v1->m_volumeAabb.m_min = (hkVector4f)xmmword_141A712A0;
  v1->m_volumeAabb.m_max.m_quad = _mm_xor_ps(
                                    (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                    v1->m_volumeAabb.m_min.m_quad);
  v1->m_up.m_quad = _xmm;
}

// File Line: 53
// RVA: 0xB5AEA0
void __fastcall hkaiNavVolumeGenerationSettings::hkaiNavVolumeGenerationSettings(hkaiNavVolumeGenerationSettings *this, hkFinishLoadedObjectFlag f)
{
  hkStringPtr::hkStringPtr(&this->m_snapshotFilename, f);
}

// File Line: 57
// RVA: 0xB5AED0
void __fastcall hkaiNavVolumeGenerationSettings::~hkaiNavVolumeGenerationSettings(hkaiNavVolumeGenerationSettings *this)
{
  hkaiNavVolumeGenerationSettings *v1; // rbx
  hkRefPtr<hkaiMaterialPainter const > *v2; // rsi
  int v3; // eax
  __int64 i; // rdi
  hkReferencedObject *v5; // rcx
  int v6; // er8
  hkRefPtr<hkaiVolume const > *v7; // rsi
  int v8; // eax
  __int64 j; // rdi
  hkReferencedObject *v10; // rcx
  int v11; // er8
  int v12; // eax
  int v13; // er8

  v1 = this;
  hkStringPtr::~hkStringPtr(&this->m_snapshotFilename);
  v2 = v1->m_painters.m_data;
  v3 = v1->m_painters.m_size - 1;
  for ( i = v3; i >= 0; v2[i--].m_pntr = 0i64 )
  {
    v5 = (hkReferencedObject *)&v2[i].m_pntr->vfptr;
    if ( v5 )
      hkReferencedObject::removeReference(v5);
  }
  v6 = v1->m_painters.m_capacityAndFlags;
  v1->m_painters.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_painters.m_data,
      8 * v6);
  v1->m_painters.m_data = 0i64;
  v1->m_painters.m_capacityAndFlags = 2147483648;
  v7 = v1->m_carvers.m_data;
  v8 = v1->m_carvers.m_size - 1;
  for ( j = v8; j >= 0; v7[j--].m_pntr = 0i64 )
  {
    v10 = (hkReferencedObject *)&v7[j].m_pntr->vfptr;
    if ( v10 )
      hkReferencedObject::removeReference(v10);
  }
  v11 = v1->m_carvers.m_capacityAndFlags;
  v1->m_carvers.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_carvers.m_data,
      8 * v11);
  v1->m_carvers.m_data = 0i64;
  v1->m_carvers.m_capacityAndFlags = 2147483648;
  v12 = v1->m_materialMap.m_capacityAndFlags;
  v1->m_materialMap.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_materialMap.m_data,
      12 * (v12 & 0x3FFFFFFF));
  v1->m_materialMap.m_data = 0i64;
  v1->m_materialMap.m_capacityAndFlags = 2147483648;
  v13 = v1->m_regionSeedPoints.m_capacityAndFlags;
  v1->m_regionSeedPoints.m_size = 0;
  if ( v13 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_regionSeedPoints.m_data,
      16 * v13);
  v1->m_regionSeedPoints.m_data = 0i64;
  v1->m_regionSeedPoints.m_capacityAndFlags = 2147483648;
}

// File Line: 65
// RVA: 0xB5AD00
void __fastcall hkaiNavVolumeGenerationSettings::ChunkSettings::ChunkSettings(hkaiNavVolumeGenerationSettings::ChunkSettings *this)
{
  *(_DWORD *)&this->m_maxChunkSizeX = 16777472;
  this->m_maxChunkSizeZ = 256;
}

// File Line: 69
// RVA: 0xB5AD20
void __fastcall hkaiNavVolumeGenerationSettings::MergingSettings::MergingSettings(hkaiNavVolumeGenerationSettings::MergingSettings *this)
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
void __fastcall hkaiNavVolumeGenerationSettings::setConstructionPropertiesForMaterial(hkaiNavVolumeGenerationSettings *this, int materialIndex, unsigned int constructionFlags, int resolution)
{
  signed int *v4; // rbx
  int v5; // edi
  unsigned int v6; // esi
  int v7; // ebp
  hkaiNavVolumeGenerationSettings::MaterialConstructionInfo *v8; // rcx
  __int64 v9; // rdx
  int *v10; // r8

  v4 = (signed int *)&this->m_materialMap;
  v5 = resolution;
  v6 = constructionFlags;
  v7 = materialIndex;
  if ( this->m_materialMap.m_size == (this->m_materialMap.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 12);
  v8 = (hkaiNavVolumeGenerationSettings::MaterialConstructionInfo *)(*(_QWORD *)v4 + 12i64 * v4[2]);
  if ( v8 )
    hkaiNavVolumeGenerationSettings::MaterialConstructionInfo::MaterialConstructionInfo(v8);
  v9 = v4[2];
  v10 = (int *)(*(_QWORD *)v4 + 12 * v9);
  v4[2] = v9 + 1;
  *v10 = v7;
  v10[1] = v6;
  v10[2] = v5;
}

