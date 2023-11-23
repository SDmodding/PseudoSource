// File Line: 39
// RVA: 0x1326800
void __fastcall hkpCompressedMeshShapeBuilder::hkpCompressedMeshShapeBuilder(hkpCompressedMeshShapeBuilder *this)
{
  this->m_overlapRatio = 0.40000001;
  *(_WORD *)&this->m_weldVertices = 256;
  this->m_TjunctionTolerance = 0.000099999997;
  this->m_weldTolerance = 0.001;
  this->m_stripperPasses = 1;
  this->m_leftOver.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  *(_DWORD *)&this->m_leftOver.m_memSizeAndFlags = 0x1FFFF;
  this->m_leftOver.m_vertices.m_data = 0i64;
  this->m_leftOver.m_vertices.m_size = 0;
  this->m_leftOver.m_vertices.m_capacityAndFlags = 0x80000000;
  this->m_leftOver.m_triangles.m_data = 0i64;
  this->m_leftOver.m_triangles.m_size = 0;
  this->m_leftOver.m_triangles.m_capacityAndFlags = 0x80000000;
  this->m_Tjunctions.m_data = 0i64;
  this->m_Tjunctions.m_size = 0;
  this->m_Tjunctions.m_capacityAndFlags = 0x80000000;
  this->m_weldedVertices.m_data = 0i64;
  this->m_weldedVertices.m_size = 0;
  this->m_weldedVertices.m_capacityAndFlags = 0x80000000;
  *(_QWORD *)&this->m_statistics.m_numVertices = 0i64;
  *(_QWORD *)&this->m_statistics.m_maxExtent = 0i64;
  *(_QWORD *)&this->m_statistics.m_error = 0i64;
  *(_QWORD *)&this->m_statistics.m_numBigVertices = 0i64;
  *(_QWORD *)&this->m_statistics.m_numChunks = 0i64;
  *(_QWORD *)&this->m_statistics.m_compressRatio = 0i64;
  *(_QWORD *)&this->m_statistics.m_maxOverlap = 0x800000i64;
  this->m_statistics.m_numChunkClones = 0;
  this->m_bigMapping.m_data = 0i64;
  this->m_bigMapping.m_size = 0;
  this->m_bigMapping.m_capacityAndFlags = 0x80000000;
  this->subparts.m_data = 0i64;
  this->subparts.m_size = 0;
  this->subparts.m_capacityAndFlags = 0x80000000;
  this->m_shapeKeys.m_data = 0i64;
  this->m_shapeKeys.m_size = 0;
  this->m_shapeKeys.m_capacityAndFlags = 0x80000000;
  this->m_createMapping = 0;
  this->m_geometry.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  *(_DWORD *)&this->m_geometry.m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry.m_vertices.m_data = 0i64;
  this->m_geometry.m_vertices.m_size = 0;
  this->m_geometry.m_vertices.m_capacityAndFlags = 0x80000000;
  this->m_geometry.m_triangles.m_data = 0i64;
  this->m_geometry.m_triangles.m_size = 0;
  this->m_geometry.m_triangles.m_capacityAndFlags = 0x80000000;
}

// File Line: 273
// RVA: 0x1326940
void __fastcall hkpCompressedMeshShapeBuilder::MappingTree::~MappingTree(
        hkpCompressedMeshShapeBuilder::MappingTree *this)
{
  hkpCompressedMeshShapeBuilder::MappingTree *m_left; // rcx
  hkpCompressedMeshShapeBuilder::MappingTree *m_right; // rcx
  int m_capacityAndFlags; // eax

  m_left = this->m_left;
  if ( m_left )
    hkpCompressedMeshShapeBuilder::MappingTree::`scalar deleting destructor(m_left, 1u);
  m_right = this->m_right;
  if ( m_right )
    hkpCompressedMeshShapeBuilder::MappingTree::`scalar deleting destructor(m_right, 1u);
  m_capacityAndFlags = this->m_triangles.m_capacityAndFlags;
  this->m_triangles.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_triangles.m_data,
      20 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_triangles.m_capacityAndFlags = 0x80000000;
  this->m_triangles.m_data = 0i64;
}

