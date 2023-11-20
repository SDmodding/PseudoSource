// File Line: 30
// RVA: 0xBB90E0
void __fastcall hkaiNavMeshInstance::hkaiNavMeshInstance(hkaiNavMeshInstance *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshInstance::`vftable;
  this->m_originalFaces = 0i64;
  this->m_numOriginalFaces = 0;
  this->m_originalEdges = 0i64;
  this->m_numOriginalEdges = 0;
  this->m_originalVertices = 0i64;
  this->m_numOriginalVertices = 0;
  this->m_originalFaceData = 0i64;
  this->m_faceDataStriding = 0;
  this->m_originalEdgeData = 0i64;
  this->m_edgeDataStriding = 0;
  this->m_originalMesh.m_pntr = 0i64;
  this->m_referenceFrame.m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_referenceFrame.m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_referenceFrame.m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_referenceFrame.m_transform.m_translation = 0i64;
  this->m_referenceFrame.m_linearVelocity = 0i64;
  this->m_referenceFrame.m_angularVelocity = 0i64;
  this->m_edgeMap.m_data = 0i64;
  this->m_edgeMap.m_size = 0;
  this->m_edgeMap.m_capacityAndFlags = 2147483648;
  this->m_faceMap.m_data = 0i64;
  this->m_faceMap.m_size = 0;
  this->m_faceMap.m_capacityAndFlags = 2147483648;
  this->m_instancedFaces.m_data = 0i64;
  this->m_instancedFaces.m_size = 0;
  this->m_instancedFaces.m_capacityAndFlags = 2147483648;
  this->m_instancedEdges.m_data = 0i64;
  this->m_instancedEdges.m_size = 0;
  this->m_instancedEdges.m_capacityAndFlags = 2147483648;
  this->m_ownedFaces.m_data = 0i64;
  this->m_ownedFaces.m_size = 0;
  this->m_ownedFaces.m_capacityAndFlags = 2147483648;
  this->m_ownedEdges.m_data = 0i64;
  this->m_ownedEdges.m_size = 0;
  this->m_ownedEdges.m_capacityAndFlags = 2147483648;
  this->m_ownedVertices.m_data = 0i64;
  this->m_ownedVertices.m_size = 0;
  this->m_ownedVertices.m_capacityAndFlags = 2147483648;
  this->m_faceFlags.m_data = 0i64;
  this->m_faceFlags.m_size = 0;
  this->m_faceFlags.m_capacityAndFlags = 2147483648;
  this->m_cuttingInfo.m_data = 0i64;
  this->m_cuttingInfo.m_size = 0;
  this->m_cuttingInfo.m_capacityAndFlags = 2147483648;
  this->m_instancedFaceData.m_data = 0i64;
  this->m_instancedFaceData.m_size = 0;
  this->m_instancedFaceData.m_capacityAndFlags = 2147483648;
  this->m_instancedEdgeData.m_data = 0i64;
  this->m_instancedEdgeData.m_size = 0;
  this->m_instancedEdgeData.m_capacityAndFlags = 2147483648;
  this->m_ownedFaceData.m_data = 0i64;
  this->m_ownedFaceData.m_size = 0;
  this->m_ownedFaceData.m_capacityAndFlags = 2147483648;
  this->m_ownedEdgeData.m_data = 0i64;
  this->m_ownedEdgeData.m_size = 0;
  this->m_ownedEdgeData.m_capacityAndFlags = 2147483648;
  this->m_clearanceCache.m_data = 0i64;
  this->m_clearanceCache.m_size = 0;
  this->m_clearanceCache.m_capacityAndFlags = 2147483648;
  this->m_globalClearanceCache.m_data = 0i64;
  this->m_globalClearanceCache.m_size = 0;
  this->m_globalClearanceCache.m_capacityAndFlags = 2147483648;
  this->m_faceClearanceIndices.m_data = 0i64;
  this->m_faceClearanceIndices.m_size = 0;
  this->m_faceClearanceIndices.m_capacityAndFlags = 2147483648;
  this->m_maxGlobalClearance = 5.0;
  *(_QWORD *)&this->m_sectionUid = -1i64;
}

// File Line: 54
// RVA: 0xBB92F0
void __fastcall hkaiNavMeshInstance::hkaiNavMeshInstance(hkaiNavMeshInstance *this, hkFinishLoadedObjectFlag f)
{
  hkaiNavMeshInstance *v2; // rbx
  hkaiNavMesh *v3; // rcx

  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshInstance::`vftable;
  if ( f.m_finishing )
  {
    v3 = this->m_originalMesh.m_pntr;
    if ( v3 )
    {
      v2->m_originalFaces = v3->m_faces.m_data;
      v2->m_numOriginalFaces = v3->m_faces.m_size;
      v2->m_originalEdges = v3->m_edges.m_data;
      v2->m_numOriginalEdges = v3->m_edges.m_size;
      v2->m_originalVertices = v3->m_vertices.m_data;
      v2->m_numOriginalVertices = v3->m_vertices.m_size;
      v2->m_originalFaceData = v3->m_faceData.m_data;
      v2->m_faceDataStriding = v3->m_faceDataStriding;
      v2->m_originalEdgeData = v3->m_edgeData.m_data;
      v2->m_edgeDataStriding = v3->m_edgeDataStriding;
    }
    hkaiNavMeshInstance::initClearanceCache(v2);
  }
}

// File Line: 81
// RVA: 0xBB9370
void __fastcall hkaiNavMeshInstance::~hkaiNavMeshInstance(hkaiNavMeshInstance *this)
{
  hkaiNavMeshInstance *v1; // rbx
  int v2; // er8
  int v3; // er8
  int v4; // er8
  int v5; // er8
  int v6; // er8
  int v7; // er8
  int v8; // er8
  int v9; // er8
  int v10; // er8
  int v11; // er8
  int v12; // eax
  int v13; // er8
  int v14; // eax
  int v15; // er8
  int v16; // er8
  int v17; // er8
  hkReferencedObject *v18; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshInstance::`vftable;
  v2 = this->m_faceClearanceIndices.m_capacityAndFlags;
  this->m_faceClearanceIndices.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_faceClearanceIndices.m_data,
      4 * v2);
  v1->m_faceClearanceIndices.m_data = 0i64;
  v1->m_faceClearanceIndices.m_capacityAndFlags = 2147483648;
  v3 = v1->m_globalClearanceCache.m_capacityAndFlags;
  v1->m_globalClearanceCache.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_globalClearanceCache.m_data,
      2 * (v3 & 0x3FFFFFFF));
  v1->m_globalClearanceCache.m_data = 0i64;
  v1->m_globalClearanceCache.m_capacityAndFlags = 2147483648;
  v4 = v1->m_clearanceCache.m_capacityAndFlags;
  v1->m_clearanceCache.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_clearanceCache.m_data,
      2 * (v4 & 0x3FFFFFFF));
  v1->m_clearanceCache.m_data = 0i64;
  v1->m_clearanceCache.m_capacityAndFlags = 2147483648;
  v5 = v1->m_ownedEdgeData.m_capacityAndFlags;
  v1->m_ownedEdgeData.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_ownedEdgeData.m_data,
      4 * v5);
  v1->m_ownedEdgeData.m_data = 0i64;
  v1->m_ownedEdgeData.m_capacityAndFlags = 2147483648;
  v6 = v1->m_ownedFaceData.m_capacityAndFlags;
  v1->m_ownedFaceData.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_ownedFaceData.m_data,
      4 * v6);
  v1->m_ownedFaceData.m_data = 0i64;
  v1->m_ownedFaceData.m_capacityAndFlags = 2147483648;
  v7 = v1->m_instancedEdgeData.m_capacityAndFlags;
  v1->m_instancedEdgeData.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_instancedEdgeData.m_data,
      4 * v7);
  v1->m_instancedEdgeData.m_data = 0i64;
  v1->m_instancedEdgeData.m_capacityAndFlags = 2147483648;
  v8 = v1->m_instancedFaceData.m_capacityAndFlags;
  v1->m_instancedFaceData.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_instancedFaceData.m_data,
      4 * v8);
  v1->m_instancedFaceData.m_data = 0i64;
  v1->m_instancedFaceData.m_capacityAndFlags = 2147483648;
  v9 = v1->m_cuttingInfo.m_capacityAndFlags;
  v1->m_cuttingInfo.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_cuttingInfo.m_data,
      2 * (v9 & 0x3FFFFFFF));
  v1->m_cuttingInfo.m_data = 0i64;
  v1->m_cuttingInfo.m_capacityAndFlags = 2147483648;
  v10 = v1->m_faceFlags.m_capacityAndFlags;
  v1->m_faceFlags.m_size = 0;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_faceFlags.m_data,
      v10 & 0x3FFFFFFF);
  v1->m_faceFlags.m_data = 0i64;
  v1->m_faceFlags.m_capacityAndFlags = 2147483648;
  v11 = v1->m_ownedVertices.m_capacityAndFlags;
  v1->m_ownedVertices.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_ownedVertices.m_data,
      16 * v11);
  v1->m_ownedVertices.m_data = 0i64;
  v1->m_ownedVertices.m_capacityAndFlags = 2147483648;
  v12 = v1->m_ownedEdges.m_capacityAndFlags;
  v1->m_ownedEdges.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_ownedEdges.m_data,
      20 * (v12 & 0x3FFFFFFF));
  v1->m_ownedEdges.m_data = 0i64;
  v1->m_ownedEdges.m_capacityAndFlags = 2147483648;
  v13 = v1->m_ownedFaces.m_capacityAndFlags;
  v1->m_ownedFaces.m_size = 0;
  if ( v13 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_ownedFaces.m_data,
      16 * v13);
  v1->m_ownedFaces.m_data = 0i64;
  v1->m_ownedFaces.m_capacityAndFlags = 2147483648;
  v14 = v1->m_instancedEdges.m_capacityAndFlags;
  v1->m_instancedEdges.m_size = 0;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_instancedEdges.m_data,
      20 * (v14 & 0x3FFFFFFF));
  v1->m_instancedEdges.m_data = 0i64;
  v1->m_instancedEdges.m_capacityAndFlags = 2147483648;
  v15 = v1->m_instancedFaces.m_capacityAndFlags;
  v1->m_instancedFaces.m_size = 0;
  if ( v15 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_instancedFaces.m_data,
      16 * v15);
  v1->m_instancedFaces.m_data = 0i64;
  v1->m_instancedFaces.m_capacityAndFlags = 2147483648;
  v16 = v1->m_faceMap.m_capacityAndFlags;
  v1->m_faceMap.m_size = 0;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_faceMap.m_data,
      4 * v16);
  v1->m_faceMap.m_data = 0i64;
  v1->m_faceMap.m_capacityAndFlags = 2147483648;
  v17 = v1->m_edgeMap.m_capacityAndFlags;
  v1->m_edgeMap.m_size = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_edgeMap.m_data,
      4 * v17);
  v1->m_edgeMap.m_data = 0i64;
  v1->m_edgeMap.m_capacityAndFlags = 2147483648;
  v18 = (hkReferencedObject *)&v1->m_originalMesh.m_pntr->vfptr;
  if ( v18 )
    hkReferencedObject::removeReference(v18);
  v1->m_originalMesh.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 85
// RVA: 0xBB9A40
void __fastcall hkaiNavMeshInstance::reinit(hkaiNavMeshInstance *this, hkaiNavMesh *mesh, bool setupClearances)
{
  bool v3; // r9
  unsigned int v4; // er8

  v3 = setupClearances;
  this->m_faceMap.m_size = 0;
  this->m_edgeMap.m_size = 0;
  this->m_faceFlags.m_size = 0;
  v4 = this->m_sectionUid;
  this->m_runtimeId = -1;
  hkaiNavMeshInstance::init(this, mesh, v4, v3);
}

// File Line: 97
// RVA: 0xBB9810
void __fastcall hkaiNavMeshInstance::init(hkaiNavMeshInstance *this, hkaiNavMesh *mesh, unsigned int uid, bool setupClearances)
{
  bool v4; // r15
  hkaiNavMesh *v5; // rdi
  hkaiNavMeshInstance *v6; // rbx
  hkReferencedObject *v7; // rcx
  int v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // er9
  int v12; // edx
  int *v13; // rdi
  __int64 v14; // rcx
  int v15; // ebp
  int v16; // eax
  int v17; // eax
  int v18; // er9
  int v19; // er8
  int *v20; // rdi
  __int64 v21; // rcx
  int v22; // esi
  int v23; // eax
  int v24; // eax
  int v25; // er9
  __int64 v26; // rax
  int v27; // ecx
  hkFlags<enum hkaiNavMesh::FaceFlagBits,unsigned char> *v28; // rdx
  __int64 v29; // rax
  hkResult result; // [rsp+68h] [rbp+20h]

  v4 = setupClearances;
  v5 = mesh;
  v6 = this;
  this->m_sectionUid = uid;
  if ( mesh )
    hkReferencedObject::addReference((hkReferencedObject *)&mesh->vfptr);
  v7 = (hkReferencedObject *)&v6->m_originalMesh.m_pntr->vfptr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  v6->m_originalMesh.m_pntr = v5;
  v6->m_originalFaces = v5->m_faces.m_data;
  v8 = v5->m_faces.m_size;
  v6->m_numOriginalFaces = v8;
  v6->m_originalEdges = v5->m_edges.m_data;
  v6->m_numOriginalEdges = v5->m_edges.m_size;
  v6->m_originalVertices = v5->m_vertices.m_data;
  v6->m_numOriginalVertices = v5->m_vertices.m_size;
  v6->m_originalFaceData = v5->m_faceData.m_data;
  v6->m_faceDataStriding = v5->m_faceDataStriding;
  v6->m_originalEdgeData = v5->m_edgeData.m_data;
  v6->m_edgeDataStriding = v5->m_edgeDataStriding;
  v9 = v6->m_faceMap.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < v8 )
  {
    v10 = 2 * v9;
    v11 = v8;
    if ( v8 < v10 )
      v11 = v10;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_faceMap,
      v11,
      4);
  }
  v12 = v8 - v6->m_faceMap.m_size;
  v13 = &v6->m_faceMap.m_data[v6->m_faceMap.m_size];
  v14 = v12;
  if ( v12 > 0 )
  {
    while ( v14 )
    {
      *v13 = -1;
      ++v13;
      --v14;
    }
  }
  v6->m_faceMap.m_size = v8;
  v15 = v6->m_numOriginalEdges;
  v16 = v6->m_edgeMap.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v16 < v15 )
  {
    v17 = 2 * v16;
    v18 = v6->m_numOriginalEdges;
    if ( v15 < v17 )
      v18 = v17;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_edgeMap,
      v18,
      4);
  }
  v19 = v15 - v6->m_edgeMap.m_size;
  v20 = &v6->m_edgeMap.m_data[v6->m_edgeMap.m_size];
  v21 = v19;
  if ( v19 > 0 )
  {
    while ( v21 )
    {
      *v20 = -1;
      ++v20;
      --v21;
    }
  }
  v6->m_edgeMap.m_size = v15;
  v22 = v6->m_numOriginalFaces;
  v23 = v6->m_faceFlags.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v23 < v22 )
  {
    v24 = 2 * v23;
    v25 = v6->m_numOriginalFaces;
    if ( v22 < v24 )
      v25 = v24;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_faceFlags,
      v25,
      1);
  }
  v26 = v6->m_faceFlags.m_size;
  v27 = v22 - v26;
  v28 = &v6->m_faceFlags.m_data[v26];
  v29 = v22 - (signed int)v26;
  if ( v27 > 0 )
  {
    do
    {
      if ( v28 )
        v28->m_storage = 0;
      ++v28;
      --v29;
    }
    while ( v29 );
  }
  v6->m_faceFlags.m_size = v22;
  v6->m_ownedFaces.m_size = 0;
  v6->m_ownedEdges.m_size = 0;
  v6->m_ownedVertices.m_size = 0;
  v6->m_instancedEdges.m_size = 0;
  v6->m_instancedFaces.m_size = 0;
  if ( v4 )
  {
    hkaiNavMeshInstance::initClearanceCache(v6);
    hkaiNavMeshInstance::resetVertexClearances(v6);
  }
}

// File Line: 182
// RVA: 0xBB9A80
void __fastcall hkaiNavMeshInstance::tempInit(hkaiNavMeshInstance *this, hkaiNavMesh *mesh, bool setupClearances)
{
  bool v3; // si
  hkaiNavMesh *v4; // rdi
  hkaiNavMeshInstance *v5; // rbx
  hkReferencedObject *v6; // rcx
  int v7; // ecx
  hkaiNavMesh::Edge *v8; // rax
  int v9; // ecx
  hkaiNavMesh::Face *v10; // rax
  int v11; // ecx
  int *v12; // rax
  int v13; // ecx
  int *v14; // rax

  v3 = setupClearances;
  v4 = mesh;
  v5 = this;
  this->m_runtimeId = 0;
  if ( mesh )
    hkReferencedObject::addReference((hkReferencedObject *)&mesh->vfptr);
  v6 = (hkReferencedObject *)&v5->m_originalMesh.m_pntr->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v5->m_originalMesh.m_pntr = v4;
  v5->m_originalFaces = v4->m_faces.m_data;
  v5->m_numOriginalFaces = v4->m_faces.m_size;
  v5->m_originalEdges = v4->m_edges.m_data;
  v5->m_numOriginalEdges = v4->m_edges.m_size;
  v5->m_originalVertices = v4->m_vertices.m_data;
  v5->m_numOriginalVertices = v4->m_vertices.m_size;
  v5->m_originalFaceData = v4->m_faceData.m_data;
  v5->m_faceDataStriding = v4->m_faceDataStriding;
  v5->m_originalEdgeData = v4->m_edgeData.m_data;
  v5->m_edgeDataStriding = v4->m_edgeDataStriding;
  v7 = v4->m_edges.m_size;
  v8 = v4->m_edges.m_data;
  v5->m_instancedEdges.m_size = v7;
  v5->m_instancedEdges.m_data = v8;
  v5->m_instancedEdges.m_capacityAndFlags = v7 | 0x80000000;
  v9 = v4->m_faces.m_size;
  v10 = v4->m_faces.m_data;
  v5->m_instancedFaces.m_size = v9;
  v5->m_instancedFaces.m_data = v10;
  v5->m_instancedFaces.m_capacityAndFlags = v9 | 0x80000000;
  v11 = v4->m_edgeData.m_size;
  v12 = v4->m_edgeData.m_data;
  v5->m_instancedEdgeData.m_size = v11;
  v5->m_instancedEdgeData.m_data = v12;
  v5->m_instancedEdgeData.m_capacityAndFlags = v11 | 0x80000000;
  v13 = v4->m_faceData.m_size;
  v14 = v4->m_faceData.m_data;
  v5->m_instancedFaceData.m_size = v13;
  v5->m_instancedFaceData.m_data = v14;
  v5->m_instancedFaceData.m_capacityAndFlags = v13 | 0x80000000;
  if ( v3 )
  {
    hkaiNavMeshInstance::initClearanceCache(v5);
    hkaiNavMeshInstance::resetVertexClearances(v5);
  }
}

// File Line: 218
// RVA: 0xBB9E20
void __fastcall hkaiNavMeshInstance::getAabb(hkaiNavMeshInstance *this, hkAabb *aabbOut)
{
  hkAabb *v2; // r9
  hkaiNavMesh *v3; // rdx
  hkSimdFloat32 extraRadius; // [rsp+20h] [rbp-18h]

  v2 = aabbOut;
  v3 = this->m_originalMesh.m_pntr;
  extraRadius.m_real = ::aabbOut.m_quad;
  hkAabbUtil::calcAabb(&this->m_referenceFrame.m_transform, &v3->m_aabb, &extraRadius, v2);
}

// File Line: 225
// RVA: 0xBBA630
void __fastcall hkaiNavMeshInstance::initClearanceCache(hkaiNavMeshInstance *this)
{
  hkaiNavMeshInstance *v1; // rsi
  _QWORD *v2; // rdi
  _QWORD *v3; // rcx
  unsigned __int64 v4; // rax
  signed __int64 v5; // rcx
  int v6; // ebx
  int v7; // edi
  int v8; // eax
  int v9; // eax
  int v10; // er9
  int v11; // ebp
  int *v12; // rdi
  int index; // er11
  hkaiNavMesh::Face *v14; // r15
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v15; // r9
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v16; // r8
  hkaiNavMesh::Face *v17; // rax
  int v18; // er11
  __int64 v19; // r8
  __int16 *v20; // rdx
  int v21; // ecx
  int v22; // er9
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // er9
  int v28; // edx
  hkHalf *v29; // rdi
  __int64 v30; // rcx
  _QWORD *v31; // rax
  _QWORD *v32; // rcx
  _QWORD *v33; // rdi
  unsigned __int64 v34; // rax
  signed __int64 v35; // rcx
  hkResult result; // [rsp+50h] [rbp+8h]

  v1 = this;
  v2 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v3 = (_QWORD *)v2[1];
  if ( (unsigned __int64)v3 < v2[3] )
  {
    *v3 = "TtinitClearanceCache";
    v4 = __rdtsc();
    v5 = (signed __int64)(v3 + 2);
    *(_DWORD *)(v5 - 8) = v4;
    v2[1] = v5;
  }
  v6 = 0;
  v7 = v1->m_numOriginalFaces + v1->m_ownedFaces.m_size;
  v8 = v1->m_faceClearanceIndices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v7 )
  {
    v9 = 2 * v8;
    v10 = v1->m_numOriginalFaces + v1->m_ownedFaces.m_size;
    if ( v7 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_faceClearanceIndices,
      v10,
      4);
  }
  v1->m_faceClearanceIndices.m_size = v7;
  v11 = v1->m_numOriginalFaces;
  v12 = v1->m_faceClearanceIndices.m_data;
  index = 0;
  if ( v11 > 0 )
  {
    v14 = v1->m_originalFaces;
    v15 = &v1->m_ownedFaces;
    v16 = &v1->m_instancedFaces;
    do
    {
      *v12 = v6;
      ++v12;
      v17 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__0(v14, v11, v16, v15, &v1->m_faceMap, index);
      index = v18 + 1;
      v6 += v17->m_numEdges - 2 + 2 * (v17->m_numEdges - 2);
    }
    while ( index < v11 );
  }
  v19 = v1->m_ownedFaces.m_size;
  if ( v19 > 0 )
  {
    v20 = &v1->m_ownedFaces.m_data->m_numEdges;
    do
    {
      v21 = *v20;
      *v12 = v6;
      ++v12;
      v20 += 8;
      v6 += v21 - 2 + 2 * (v21 - 2);
      --v19;
    }
    while ( v19 );
  }
  v22 = (v6 + 7) & 0xFFFFFFF8;
  v23 = v1->m_clearanceCache.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v23 < v22 )
  {
    v24 = 2 * v23;
    if ( v22 < v24 )
      v22 = v24;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_clearanceCache,
      v22,
      2);
  }
  v25 = v1->m_clearanceCache.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v25 < v6 )
  {
    v26 = 2 * v25;
    v27 = v6;
    if ( v6 < v26 )
      v27 = v26;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_clearanceCache,
      v27,
      2);
  }
  v28 = v6 - v1->m_clearanceCache.m_size;
  v29 = &v1->m_clearanceCache.m_data[v1->m_clearanceCache.m_size];
  v30 = v28;
  if ( v28 > 0 )
  {
    while ( v30 )
    {
      v29->m_value = -16512;
      ++v29;
      --v30;
    }
  }
  v1->m_clearanceCache.m_size = v6;
  hkaiNavMeshInstance::initGlobalClearanceCache(v1);
  v31 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v32 = (_QWORD *)v31[1];
  v33 = v31;
  if ( (unsigned __int64)v32 < v31[3] )
  {
    *v32 = "Et";
    v34 = __rdtsc();
    v35 = (signed __int64)(v32 + 2);
    *(_DWORD *)(v35 - 8) = v34;
    v33[1] = v35;
  }
}

// File Line: 266
// RVA: 0xBBA870
void __fastcall hkaiNavMeshInstance::initGlobalClearanceCache(hkaiNavMeshInstance *this)
{
  hkArray<hkHalf,hkContainerHeapAllocator> *v1; // rsi
  hkaiNavMeshInstance *v2; // rdi
  int v3; // eax
  int v4; // er9
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // er9
  int v10; // edx
  hkHalf *v11; // rdi
  __int64 v12; // rcx
  hkResult result; // [rsp+40h] [rbp+8h]

  v1 = &this->m_globalClearanceCache;
  v2 = this;
  v3 = this->m_globalClearanceCache.m_capacityAndFlags & 0x3FFFFFFF;
  v4 = (this->m_numOriginalVertices + this->m_ownedVertices.m_size + 7) & 0xFFFFFFF8;
  if ( v3 < v4 )
  {
    v5 = 2 * v3;
    if ( v4 < v5 )
      v4 = v5;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v1, v4, 2);
  }
  v6 = v2->m_ownedVertices.m_size + v2->m_numOriginalVertices;
  v7 = v1->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v6 )
  {
    v8 = 2 * v7;
    v9 = v2->m_ownedVertices.m_size + v2->m_numOriginalVertices;
    if ( v6 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v1, v9, 2);
  }
  v10 = v6 - v1->m_size;
  v11 = &v1->m_data[v1->m_size];
  v12 = v10;
  if ( v10 > 0 )
  {
    while ( v12 )
    {
      v11->m_value = 32639;
      ++v11;
      --v12;
    }
  }
  v1->m_size = v6;
}

// File Line: 274
// RVA: 0xBBA950
void __fastcall hkaiNavMeshInstance::resetVertexClearances(hkaiNavMeshInstance *this)
{
  hkaiNavMeshInstance *v1; // rbx
  _QWORD *v2; // r8
  _QWORD *v3; // rcx
  unsigned __int64 v4; // rax
  signed __int64 v5; // rcx
  hkHalf *v6; // rcx
  signed int v7; // edi
  int v8; // eax
  __int64 v9; // rdx
  hkHalf *v10; // rcx
  __int64 v11; // rax
  _QWORD *v12; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx

  v1 = this;
  v2 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v3 = (_QWORD *)v2[1];
  if ( (unsigned __int64)v3 < v2[3] )
  {
    *v3 = "TtresetVertexClearances";
    v4 = __rdtsc();
    v5 = (signed __int64)(v3 + 2);
    *(_DWORD *)(v5 - 8) = v4;
    v2[1] = v5;
  }
  v6 = v1->m_clearanceCache.m_data;
  v7 = (v1->m_globalClearanceCache.m_size + 7) & 0xFFFFFFF8;
  v8 = (signed int)((v1->m_clearanceCache.m_size + 7) & 0xFFFFFFF8) / 8;
  if ( v8 > 0 )
  {
    v9 = (unsigned int)v8;
    do
    {
      *(_DWORD *)&v6->m_value = -1082081408;
      *(_DWORD *)&v6[2].m_value = -1082081408;
      *(_DWORD *)&v6[4].m_value = -1082081408;
      *(_DWORD *)&v6[6].m_value = -1082081408;
      v6 += 8;
      --v9;
    }
    while ( v9 );
  }
  v10 = v1->m_globalClearanceCache.m_data;
  v11 = v7 / 8;
  if ( (signed int)v11 > 0 )
  {
    do
    {
      *(_DWORD *)&v10->m_value = 2139062143;
      *(_DWORD *)&v10[2].m_value = 2139062143;
      *(_DWORD *)&v10[4].m_value = 2139062143;
      *(_DWORD *)&v10[6].m_value = 2139062143;
      v10 += 8;
      --v11;
    }
    while ( v11 );
  }
  v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)v12[1];
  if ( (unsigned __int64)v13 < v12[3] )
  {
    *v13 = "Et";
    v14 = __rdtsc();
    v15 = (signed __int64)(v13 + 2);
    *(_DWORD *)(v15 - 8) = v14;
    v12[1] = v15;
  }
}

// File Line: 293
// RVA: 0xBBA610
void __fastcall hkaiNavMeshInstance::setMaxGlobalClearance(hkaiNavMeshInstance *this, float globalClear)
{
  this->m_maxGlobalClearance = globalClear;
  hkaiNavMeshInstance::resetVertexClearances(this);
}

// File Line: 299
// RVA: 0xBB9BC0
void __fastcall hkaiNavMeshInstance::setEdgeData(hkaiNavMeshInstance *this, int eIdx, int d)
{
  int v3; // eax

  v3 = this->m_numOriginalEdges;
  if ( eIdx < v3 )
  {
    if ( this->m_edgeMap.m_size )
      eIdx = this->m_edgeMap.m_data[eIdx];
    if ( eIdx == -1 )
      LODWORD(MEMORY[0]) = d;
    else
      this->m_instancedEdgeData.m_data[eIdx] = d;
  }
  else
  {
    this->m_ownedEdgeData.m_data[eIdx - v3] = d;
  }
}

// File Line: 304
// RVA: 0xBB9C20
void __fastcall hkaiNavMeshInstance::setFaceData(hkaiNavMeshInstance *this, int fIdx, int d)
{
  int v3; // eax

  v3 = this->m_numOriginalFaces;
  if ( fIdx < v3 )
  {
    if ( this->m_faceMap.m_size )
      fIdx = this->m_faceMap.m_data[fIdx];
    if ( fIdx == -1 )
      LODWORD(MEMORY[0]) = d;
    else
      this->m_instancedFaceData.m_data[fIdx] = d;
  }
  else
  {
    this->m_ownedFaceData.m_data[fIdx - v3] = d;
  }
}

// File Line: 310
// RVA: 0xBB9C80
hkaiNavMesh::Face *__fastcall hkaiNavMeshInstance::instanceFace(hkaiNavMeshInstance *this, int fIdx)
{
  return hkaiNavMeshInstance_instance_hkaiNavMesh::Face_int_(
           this->m_originalFaces,
           &this->m_instancedFaces,
           this->m_originalFaceData,
           &this->m_instancedFaceData,
           &this->m_faceMap,
           fIdx,
           this->m_faceDataStriding);
}

// File Line: 315
// RVA: 0xBB9CD0
hkaiNavMesh::Edge *__fastcall hkaiNavMeshInstance::instanceEdge(hkaiNavMeshInstance *this, int eIdx)
{
  return hkaiNavMeshInstance_instance_hkaiNavMesh::Edge_int_(
           this->m_originalEdges,
           &this->m_instancedEdges,
           this->m_originalEdgeData,
           &this->m_instancedEdgeData,
           &this->m_edgeMap,
           eIdx,
           this->m_edgeDataStriding);
}

// File Line: 320
// RVA: 0xBB9D20
void __fastcall hkaiNavMeshInstance::removeInstancedFace(hkaiNavMeshInstance *this, int fIdx)
{
  __int64 v2; // rdx
  __int64 v3; // r9
  hkaiNavMesh::Face *v4; // rax

  if ( this->m_faceMap.m_size )
  {
    v2 = fIdx;
    v3 = this->m_faceMap.m_data[v2];
    v4 = &this->m_instancedFaces.m_data[v3];
    *(_DWORD *)&v4->m_numEdges = 0;
    v4->m_startEdgeIndex = -1;
    v4->m_startUserEdgeIndex = -1;
    v4->m_clusterIndex = -1;
    v4->m_padding = -12851;
    if ( this->m_faceDataStriding )
      this->m_instancedFaceData.m_data[v3 * this->m_faceDataStriding] = -559023410;
    this->m_faceMap.m_data[v2] = -1;
  }
}

// File Line: 338
// RVA: 0xBB9DA0
void __fastcall hkaiNavMeshInstance::removeInstancedEdge(hkaiNavMeshInstance *this, int eIdx)
{
  __int64 v2; // r10
  signed __int64 v3; // r9
  hkaiNavMesh::Edge *v4; // rax
  signed __int64 v5; // rdx

  if ( this->m_edgeMap.m_size )
  {
    v2 = eIdx;
    v3 = this->m_edgeMap.m_data[v2];
    v4 = this->m_instancedEdges.m_data;
    v5 = v3;
    *(_QWORD *)&v4[v5].m_oppositeEdge = -1i64;
    *(_DWORD *)&v4[v5].m_flags.m_storage = 4;
    if ( this->m_edgeDataStriding )
      this->m_instancedEdgeData.m_data[v3 * this->m_edgeDataStriding] = -559026834;
    this->m_edgeMap.m_data[v2] = -1;
  }
}

// File Line: 357
// RVA: 0xBBA100
void __fastcall hkaiNavMeshInstance::appendVertices(hkaiNavMeshInstance *this, hkVector4f *v, int numV)
{
  hkArrayBase<hkVector4f>::_append(
    (hkArrayBase<hkVector4f> *)&this->m_ownedVertices.m_data,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v,
    numV);
}

// File Line: 363
// RVA: 0xBB9E60
void __fastcall hkaiNavMeshInstance::getFaceContext(hkaiNavMeshInstance *this, int fIdx, hkaiNavMeshInstance::AddFaceContext *ctx)
{
  __int64 v3; // rdi
  hkaiNavMeshInstance::AddFaceContext *v4; // rbx
  hkaiNavMesh::Face *v5; // rax
  hkaiNavMeshInstance *v6; // r11
  char v7; // [rsp+40h] [rbp+8h]

  v3 = fIdx;
  v4 = ctx;
  v5 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__0(
         this->m_originalFaces,
         this->m_numOriginalFaces,
         &this->m_instancedFaces,
         &this->m_ownedFaces,
         &this->m_faceMap,
         fIdx);
  v4->m_face.m_startEdgeIndex = v5->m_startEdgeIndex;
  v4->m_face.m_startUserEdgeIndex = v5->m_startUserEdgeIndex;
  *(_DWORD *)&v4->m_face.m_numEdges = *(_DWORD *)&v5->m_numEdges;
  *(_DWORD *)&v4->m_face.m_clusterIndex = *(_DWORD *)&v5->m_clusterIndex;
  if ( v6->m_faceFlags.m_size )
    v7 = v6->m_faceFlags.m_data[v3].m_storage;
  else
    v7 = 0;
  v4->m_flags.m_storage = v7;
  hkaiNavMeshInstance::getFaceDataForContext(v6, v3, v4);
}

// File Line: 371
// RVA: 0xBB9F00
void __fastcall hkaiNavMeshInstance::getFaceDataForContext(hkaiNavMeshInstance *this, int fIdx, hkaiNavMeshInstance::AddFaceContext *ctx)
{
  int striding; // er10
  hkaiNavMeshInstance::AddFaceContext *v4; // rbx
  const int *v5; // rax
  int v6; // er11
  char *v7; // rcx
  __int64 v8; // rdx
  signed __int64 v9; // r8
  int v10; // eax

  striding = this->m_faceDataStriding;
  v4 = ctx;
  if ( striding )
  {
    v5 = hkaiNavMeshInstance_getWithStriding_int_(
           this->m_originalFaceData,
           this->m_numOriginalFaces,
           &this->m_instancedFaceData,
           &this->m_ownedFaceData,
           &this->m_faceMap,
           fIdx,
           striding);
    v7 = (char *)v4->m_data;
    if ( v6 == 1 )
    {
      *(_DWORD *)v7 = *v5;
    }
    else
    {
      v8 = v6;
      if ( v6 >= 1i64 )
      {
        v9 = (char *)v5 - v7;
        do
        {
          v10 = *(_DWORD *)&v7[v9];
          v7 += 4;
          *((_DWORD *)v7 - 1) = v10;
          --v8;
        }
        while ( v8 );
      }
    }
  }
}

// File Line: 381
// RVA: 0xBBA120
void __fastcall hkaiNavMeshInstance::appendFaces(hkaiNavMeshInstance *this, hkaiNavMeshInstance::AddFaceContext *ctxs, int numFaces)
{
  __int64 v3; // rsi
  hkArray<hkFlags<enum hkaiNavMesh::FaceFlagBits,unsigned char>,hkContainerHeapAllocator> *v4; // rbx
  __int64 v5; // rbp
  __int64 v6; // r14
  hkaiNavMeshInstance::AddFaceContext *v7; // r13
  int v8; // er9
  int v9; // eax
  hkaiNavMeshInstance *v10; // rdi
  int v11; // eax
  hkFlags<enum hkaiNavMesh::FaceFlagBits,unsigned char> *v12; // r12
  hkArray<int,hkContainerHeapAllocator> *v13; // rbx
  __int64 v14; // r15
  int v15; // er9
  int v16; // eax
  int v17; // eax
  signed int *v18; // rdi
  __int64 v19; // r14
  char *v20; // rbx
  int v21; // er9
  int v22; // eax
  int v23; // eax
  __int64 v24; // r11
  _DWORD *v25; // r10
  int *v26; // r8
  char *v27; // rax
  __int64 v28; // rdx
  int v29; // ecx
  hkResult v30; // [rsp+70h] [rbp+8h]
  hkResult result; // [rsp+80h] [rbp+18h]

  v3 = this->m_faceDataStriding;
  v4 = &this->m_faceFlags;
  v5 = numFaces;
  v6 = this->m_faceFlags.m_size;
  v7 = ctxs;
  v8 = v6 + numFaces;
  v9 = this->m_faceFlags.m_capacityAndFlags & 0x3FFFFFFF;
  v10 = this;
  if ( v9 < (signed int)v6 + numFaces )
  {
    v11 = 2 * v9;
    if ( v8 < v11 )
      v8 = v11;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v8, 1);
  }
  v4->m_size += v5;
  v12 = &v4->m_data[v6];
  v13 = &v10->m_ownedFaceData;
  v14 = v10->m_ownedFaceData.m_size;
  v15 = v14 + v5 * v3;
  v16 = v10->m_ownedFaceData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v16 < v15 )
  {
    v17 = 2 * v16;
    if ( v15 < v17 )
      v15 = v17;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v10->m_ownedFaceData,
      v15,
      4);
  }
  v10->m_ownedFaceData.m_size += v5 * v3;
  v18 = (signed int *)&v10->m_ownedFaces;
  v19 = v18[2];
  v20 = (char *)&v13->m_data[v14];
  v21 = v19 + v5;
  v22 = v18[3] & 0x3FFFFFFF;
  if ( v22 < (signed int)v19 + (signed int)v5 )
  {
    v23 = 2 * v22;
    if ( v21 < v23 )
      v21 = v23;
    hkArrayUtil::_reserve(&v30, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v18, v21, 16);
  }
  v18[2] += v5;
  v24 = 0i64;
  v25 = (_DWORD *)(*(_QWORD *)v18 + 16 * v19);
  if ( v5 > 0 )
  {
    v26 = v7->m_data;
    do
    {
      v12[v24] = (hkFlags<enum hkaiNavMesh::FaceFlagBits,unsigned char>)*((char *)v26 - 4);
      *v25 = *(v26 - 5);
      v25[1] = *(v26 - 4);
      v25[2] = *(v26 - 3);
      v25[3] = *(v26 - 2);
      if ( (_DWORD)v3 == 1 )
      {
        *(_DWORD *)v20 = *v26;
      }
      else if ( (signed int)v3 > 0 )
      {
        v27 = v20;
        v28 = v3;
        do
        {
          v29 = *(_DWORD *)&v27[(char *)v26 - v20];
          v27 += 4;
          *((_DWORD *)v27 - 1) = v29;
          --v28;
        }
        while ( v28 );
      }
      ++v24;
      v20 += 4 * v3;
      v25 += 4;
      v26 += 9;
    }
    while ( v24 < v5 );
  }
}

// File Line: 397
// RVA: 0xBB9FA0
void __fastcall hkaiNavMeshInstance::getEdgeContext(hkaiNavMeshInstance *this, int eIdx, hkaiNavMeshInstance::AddEdgeContext *ctx)
{
  __int64 v3; // rsi
  hkaiNavMeshInstance *v4; // rdi
  hkaiNavMeshInstance::AddEdgeContext *v5; // rbx
  hkaiNavMesh::Edge *v6; // rax
  __int64 v7; // rax
  signed __int16 v8; // dx

  v3 = eIdx;
  v4 = this;
  v5 = ctx;
  v6 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__0(
         this->m_originalEdges,
         this->m_numOriginalEdges,
         &this->m_instancedEdges,
         &this->m_ownedEdges,
         &this->m_edgeMap,
         eIdx);
  v5->m_edge.m_a = v6->m_a;
  v5->m_edge.m_b = v6->m_b;
  v5->m_edge.m_oppositeEdge = v6->m_oppositeEdge;
  v5->m_edge.m_oppositeFace = v6->m_oppositeFace;
  v5->m_edge.m_flags.m_storage = v6->m_flags.m_storage;
  v5->m_edge.m_paddingByte = v6->m_paddingByte;
  v5->m_edge.m_userEdgeCost.m_value = v6->m_userEdgeCost.m_value;
  v7 = v4->m_numOriginalEdges;
  if ( (signed int)v3 < (signed int)v7 )
    v8 = -1;
  else
    v8 = v4->m_cuttingInfo.m_data[v3 - v7];
  v5->m_cutInfo = v8;
  hkaiNavMeshInstance::getEdgeDataForContext(v4, v3, v5);
}

// File Line: 405
// RVA: 0xBBA060
void __fastcall hkaiNavMeshInstance::getEdgeDataForContext(hkaiNavMeshInstance *this, int eIdx, hkaiNavMeshInstance::AddEdgeContext *ctx)
{
  int striding; // er10
  hkaiNavMeshInstance::AddEdgeContext *v4; // rbx
  const int *v5; // rax
  int v6; // er11
  char *v7; // rcx
  __int64 v8; // rdx
  signed __int64 v9; // r8
  int v10; // eax

  striding = this->m_edgeDataStriding;
  v4 = ctx;
  if ( striding )
  {
    v5 = hkaiNavMeshInstance_getWithStriding_int_(
           this->m_originalEdgeData,
           this->m_numOriginalEdges,
           &this->m_instancedEdgeData,
           &this->m_ownedEdgeData,
           &this->m_edgeMap,
           eIdx,
           striding);
    v7 = (char *)v4->m_data;
    if ( v6 == 1 )
    {
      *(_DWORD *)v7 = *v5;
    }
    else
    {
      v8 = v6;
      if ( v6 >= 1i64 )
      {
        v9 = (char *)v5 - v7;
        do
        {
          v10 = *(_DWORD *)&v7[v9];
          v7 += 4;
          *((_DWORD *)v7 - 1) = v10;
          --v8;
        }
        while ( v8 );
      }
    }
  }
}

// File Line: 415
// RVA: 0xBBA2E0
hkaiNavMesh::Edge *__fastcall hkaiNavMeshInstance::appendEdges(hkaiNavMeshInstance *this, hkaiNavMeshInstance::AddEdgeContext *ctxs, int numEdges)
{
  __int64 v3; // rbp
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v4; // rbx
  __int64 v5; // rsi
  __int64 v6; // r14
  hkaiNavMeshInstance::AddEdgeContext *v7; // r15
  int v8; // er9
  int v9; // eax
  hkaiNavMeshInstance *v10; // rdi
  int v11; // eax
  hkaiNavMesh::Edge *v12; // rax
  hkArray<int,hkContainerHeapAllocator> *v13; // rbx
  signed __int64 v14; // r13
  __int64 v15; // r12
  int v16; // er9
  int v17; // eax
  int v18; // eax
  signed int *v19; // rdi
  __int64 v20; // r14
  int *v21; // rbx
  int v22; // er9
  int v23; // eax
  int v24; // eax
  __int64 v25; // rax
  __int64 v26; // r11
  signed __int64 v27; // r12
  signed __int64 v28; // r9
  signed __int64 v29; // rdx
  int *v30; // rcx
  __int64 v31; // r8
  int v32; // eax
  hkResult v34; // [rsp+70h] [rbp+8h]
  hkResult result; // [rsp+80h] [rbp+18h]

  v3 = this->m_edgeDataStriding;
  v4 = &this->m_ownedEdges;
  v5 = numEdges;
  v6 = this->m_ownedEdges.m_size;
  v7 = ctxs;
  v8 = v6 + numEdges;
  v9 = this->m_ownedEdges.m_capacityAndFlags & 0x3FFFFFFF;
  v10 = this;
  if ( v9 < (signed int)v6 + numEdges )
  {
    v11 = 2 * v9;
    if ( v8 < v11 )
      v8 = v11;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v8, 20);
  }
  v4->m_size += v5;
  v12 = v4->m_data;
  v13 = &v10->m_ownedEdgeData;
  v14 = (signed __int64)&v12[v6];
  v15 = v10->m_ownedEdgeData.m_size;
  v16 = v15 + v5 * v3;
  v17 = v10->m_ownedEdgeData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v17 < v16 )
  {
    v18 = 2 * v17;
    if ( v16 < v18 )
      v16 = v18;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v10->m_ownedEdgeData,
      v16,
      4);
  }
  v10->m_ownedEdgeData.m_size += v5 * v3;
  v19 = (signed int *)&v10->m_cuttingInfo;
  v20 = v19[2];
  v21 = &v13->m_data[v15];
  v22 = v20 + v5;
  v23 = v19[3] & 0x3FFFFFFF;
  if ( v23 < (signed int)v20 + (signed int)v5 )
  {
    v24 = 2 * v23;
    if ( v22 < v24 )
      v22 = v24;
    hkArrayUtil::_reserve(&v34, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v19, v22, 2);
  }
  v25 = *(_QWORD *)v19;
  v19[2] += v5;
  v26 = 0i64;
  v27 = v25 + 2 * v20;
  if ( v5 > 0 )
  {
    v28 = v14 + 8;
    v29 = (signed __int64)&v7->m_edge.m_oppositeEdge;
    do
    {
      *(_DWORD *)(v28 - 8) = *(_DWORD *)(v29 - 8);
      *(_DWORD *)(v28 - 4) = *(_DWORD *)(v29 - 4);
      *(_DWORD *)v28 = *(_DWORD *)v29;
      *(_DWORD *)(v28 + 4) = *(_DWORD *)(v29 + 4);
      *(_BYTE *)(v28 + 8) = *(_BYTE *)(v29 + 8);
      *(_BYTE *)(v28 + 9) = *(_BYTE *)(v29 + 9);
      *(_WORD *)(v28 + 10) = *(_WORD *)(v29 + 10);
      *(_WORD *)(v27 + 2 * v26) = *(_WORD *)(v29 + 28);
      if ( (_DWORD)v3 == 1 )
      {
        *v21 = *(_DWORD *)(v29 + 12);
      }
      else if ( (signed int)v3 > 0 )
      {
        v30 = v21;
        v31 = v3;
        do
        {
          v32 = *(int *)((char *)v30 + v29 - (_QWORD)v21 + 12);
          ++v30;
          *(v30 - 1) = v32;
          --v31;
        }
        while ( v31 );
      }
      ++v26;
      v21 += v3;
      v28 += 20i64;
      v29 += 40i64;
    }
    while ( v26 < v5 );
  }
  return (hkaiNavMesh::Edge *)v14;
}

// File Line: 435
// RVA: 0xBBA4C0
hkaiNavMesh::Edge *__fastcall hkaiNavMeshInstance::expandEdgesBy(hkaiNavMeshInstance *this, int n)
{
  int v2; // er14
  int v3; // ebx
  int v4; // eax
  hkaiNavMeshInstance *v5; // rbp
  int v6; // eax
  int v7; // er9
  int v8; // edx
  unsigned __int16 *v9; // rdi
  __int64 v10; // rcx
  int v11; // ebx
  int v12; // er9
  int v13; // eax
  int v14; // eax
  __int64 v15; // rbx
  int v16; // er9
  int v17; // eax
  int v18; // eax
  hkaiNavMesh::Edge *v19; // rax
  hkResult result; // [rsp+58h] [rbp+10h]

  v2 = n;
  v3 = n + this->m_cuttingInfo.m_size;
  v4 = this->m_cuttingInfo.m_capacityAndFlags & 0x3FFFFFFF;
  v5 = this;
  if ( v4 < v3 )
  {
    v6 = 2 * v4;
    v7 = n + this->m_cuttingInfo.m_size;
    if ( v3 < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_cuttingInfo,
      v7,
      2);
  }
  v8 = v3 - v5->m_cuttingInfo.m_size;
  v9 = &v5->m_cuttingInfo.m_data[v5->m_cuttingInfo.m_size];
  v10 = v8;
  if ( v8 > 0 )
  {
    while ( v10 )
    {
      *v9 = -1;
      ++v9;
      --v10;
    }
  }
  v5->m_cuttingInfo.m_size = v3;
  v11 = v2 * v5->m_edgeDataStriding;
  v12 = v11 + v5->m_ownedEdgeData.m_size;
  v13 = v5->m_ownedEdgeData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 < v12 )
  {
    v14 = 2 * v13;
    if ( v12 < v14 )
      v12 = v14;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v5->m_ownedEdgeData,
      v12,
      4);
  }
  v5->m_ownedEdgeData.m_size += v11;
  v15 = v5->m_ownedEdges.m_size;
  v16 = v15 + v2;
  v17 = v5->m_ownedEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v17 < (signed int)v15 + v2 )
  {
    v18 = 2 * v17;
    if ( v16 < v18 )
      v16 = v18;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v5->m_ownedEdges,
      v16,
      20);
  }
  v19 = v5->m_ownedEdges.m_data;
  v5->m_ownedEdges.m_size += v2;
  return &v19[v15];
}

// File Line: 443
// RVA: 0xBBAAD0
void __fastcall hkaiNavMeshInstance::checkDeterminism(hkaiNavMeshInstance *this)
{
  hkaiNavMeshInstance *v1; // rbx

  v1 = this;
  hkaiNavMesh::checkDeterminism(this->m_originalMesh.m_pntr);
  hkaiReferenceFrame::checkDeterminism(&v1->m_referenceFrame);
}

