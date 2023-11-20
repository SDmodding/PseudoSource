// File Line: 39
// RVA: 0x1326800
void __fastcall hkpCompressedMeshShapeBuilder::hkpCompressedMeshShapeBuilder(hkpCompressedMeshShapeBuilder *this)
{
  this->m_overlapRatio = 0.40000001;
  *(_WORD *)&this->m_weldVertices = 256;
  this->m_TjunctionTolerance = 0.000099999997;
  this->m_weldTolerance = 0.001;
  this->m_stripperPasses = 1;
  this->m_leftOver.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable';
  *(_DWORD *)&this->m_leftOver.m_memSizeAndFlags = 0x1FFFF;
  this->m_leftOver.m_vertices.m_data = 0i64;
  this->m_leftOver.m_vertices.m_size = 0;
  this->m_leftOver.m_vertices.m_capacityAndFlags = 2147483648;
  this->m_leftOver.m_triangles.m_data = 0i64;
  this->m_leftOver.m_triangles.m_size = 0;
  this->m_leftOver.m_triangles.m_capacityAndFlags = 2147483648;
  this->m_Tjunctions.m_data = 0i64;
  this->m_Tjunctions.m_size = 0;
  this->m_Tjunctions.m_capacityAndFlags = 2147483648;
  this->m_weldedVertices.m_data = 0i64;
  this->m_weldedVertices.m_size = 0;
  this->m_weldedVertices.m_capacityAndFlags = 2147483648;
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
  this->m_bigMapping.m_capacityAndFlags = 2147483648;
  this->subparts.m_data = 0i64;
  this->subparts.m_size = 0;
  this->subparts.m_capacityAndFlags = 2147483648;
  this->m_shapeKeys.m_data = 0i64;
  this->m_shapeKeys.m_size = 0;
  this->m_shapeKeys.m_capacityAndFlags = 2147483648;
  this->m_createMapping = 0;
  this->m_geometry.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable';
  *(_DWORD *)&this->m_geometry.m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry.m_vertices.m_data = 0i64;
  this->m_geometry.m_vertices.m_size = 0;
  this->m_geometry.m_vertices.m_capacityAndFlags = 2147483648;
  this->m_geometry.m_triangles.m_data = 0i64;
  this->m_geometry.m_triangles.m_size = 0;
  this->m_geometry.m_triangles.m_capacityAndFlags = 2147483648;
}

// File Line: 273
// RVA: 0x1326940
void __fastcall hkpCompressedMeshShapeBuilder::MappingTree::~MappingTree(hkpCompressedMeshShapeBuilder::MappingTree *this)
{
  hkpCompressedMeshShapeBuilder::MappingTree *v1; // rbx
  hkpCompressedMeshShapeBuilder::MappingTree *v2; // rcx
  hkpCompressedMeshShapeBuilder::MappingTree *v3; // rcx
  int v4; // eax

  v1 = this;
  v2 = this->m_left;
  if ( v2 )
    hkpCompressedMeshShapeBuilder::MappingTree::`scalar deleting destructor'(v2, 1u);
  v3 = v1->m_right;
  if ( v3 )
    hkpCompressedMeshShapeBuilder::MappingTree::`scalar deleting destructor'(v3, 1u);
  v4 = v1->m_triangles.m_capacityAndFlags;
  v1->m_triangles.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_triangles.m_data,
      20 * (v4 & 0x3FFFFFFF));
  v1->m_triangles.m_capacityAndFlags = 2147483648;
  v1->m_triangles.m_data = 0i64;
}

