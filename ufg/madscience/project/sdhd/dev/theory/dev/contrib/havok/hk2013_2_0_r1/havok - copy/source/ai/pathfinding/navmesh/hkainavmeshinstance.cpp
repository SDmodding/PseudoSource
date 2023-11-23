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
  this->m_edgeMap.m_capacityAndFlags = 0x80000000;
  this->m_faceMap.m_data = 0i64;
  this->m_faceMap.m_size = 0;
  this->m_faceMap.m_capacityAndFlags = 0x80000000;
  this->m_instancedFaces.m_data = 0i64;
  this->m_instancedFaces.m_size = 0;
  this->m_instancedFaces.m_capacityAndFlags = 0x80000000;
  this->m_instancedEdges.m_data = 0i64;
  this->m_instancedEdges.m_size = 0;
  this->m_instancedEdges.m_capacityAndFlags = 0x80000000;
  this->m_ownedFaces.m_data = 0i64;
  this->m_ownedFaces.m_size = 0;
  this->m_ownedFaces.m_capacityAndFlags = 0x80000000;
  this->m_ownedEdges.m_data = 0i64;
  this->m_ownedEdges.m_size = 0;
  this->m_ownedEdges.m_capacityAndFlags = 0x80000000;
  this->m_ownedVertices.m_data = 0i64;
  this->m_ownedVertices.m_size = 0;
  this->m_ownedVertices.m_capacityAndFlags = 0x80000000;
  this->m_faceFlags.m_data = 0i64;
  this->m_faceFlags.m_size = 0;
  this->m_faceFlags.m_capacityAndFlags = 0x80000000;
  this->m_cuttingInfo.m_data = 0i64;
  this->m_cuttingInfo.m_size = 0;
  this->m_cuttingInfo.m_capacityAndFlags = 0x80000000;
  this->m_instancedFaceData.m_data = 0i64;
  this->m_instancedFaceData.m_size = 0;
  this->m_instancedFaceData.m_capacityAndFlags = 0x80000000;
  this->m_instancedEdgeData.m_data = 0i64;
  this->m_instancedEdgeData.m_size = 0;
  this->m_instancedEdgeData.m_capacityAndFlags = 0x80000000;
  this->m_ownedFaceData.m_data = 0i64;
  this->m_ownedFaceData.m_size = 0;
  this->m_ownedFaceData.m_capacityAndFlags = 0x80000000;
  this->m_ownedEdgeData.m_data = 0i64;
  this->m_ownedEdgeData.m_size = 0;
  this->m_ownedEdgeData.m_capacityAndFlags = 0x80000000;
  this->m_clearanceCache.m_data = 0i64;
  this->m_clearanceCache.m_size = 0;
  this->m_clearanceCache.m_capacityAndFlags = 0x80000000;
  this->m_globalClearanceCache.m_data = 0i64;
  this->m_globalClearanceCache.m_size = 0;
  this->m_globalClearanceCache.m_capacityAndFlags = 0x80000000;
  this->m_faceClearanceIndices.m_data = 0i64;
  this->m_faceClearanceIndices.m_size = 0;
  this->m_faceClearanceIndices.m_capacityAndFlags = 0x80000000;
  this->m_maxGlobalClearance = 5.0;
  *(_QWORD *)&this->m_sectionUid = -1i64;
}

// File Line: 54
// RVA: 0xBB92F0
void __fastcall hkaiNavMeshInstance::hkaiNavMeshInstance(hkaiNavMeshInstance *this, hkFinishLoadedObjectFlag f)
{
  hkaiNavMesh *m_pntr; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshInstance::`vftable;
  if ( f.m_finishing )
  {
    m_pntr = this->m_originalMesh.m_pntr;
    if ( m_pntr )
    {
      this->m_originalFaces = m_pntr->m_faces.m_data;
      this->m_numOriginalFaces = m_pntr->m_faces.m_size;
      this->m_originalEdges = m_pntr->m_edges.m_data;
      this->m_numOriginalEdges = m_pntr->m_edges.m_size;
      this->m_originalVertices = m_pntr->m_vertices.m_data;
      this->m_numOriginalVertices = m_pntr->m_vertices.m_size;
      this->m_originalFaceData = m_pntr->m_faceData.m_data;
      this->m_faceDataStriding = m_pntr->m_faceDataStriding;
      this->m_originalEdgeData = m_pntr->m_edgeData.m_data;
      this->m_edgeDataStriding = m_pntr->m_edgeDataStriding;
    }
    hkaiNavMeshInstance::initClearanceCache(this);
  }
}

// File Line: 81
// RVA: 0xBB9370
void __fastcall hkaiNavMeshInstance::~hkaiNavMeshInstance(hkaiNavMeshInstance *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d
  int v4; // r8d
  int v5; // r8d
  int v6; // r8d
  int v7; // r8d
  int v8; // r8d
  int v9; // r8d
  int v10; // r8d
  int v11; // r8d
  int v12; // eax
  int v13; // r8d
  int v14; // eax
  int v15; // r8d
  int v16; // r8d
  int v17; // r8d
  hkaiNavMesh *m_pntr; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshInstance::`vftable;
  m_capacityAndFlags = this->m_faceClearanceIndices.m_capacityAndFlags;
  this->m_faceClearanceIndices.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_faceClearanceIndices.m_data,
      4 * m_capacityAndFlags);
  this->m_faceClearanceIndices.m_data = 0i64;
  this->m_faceClearanceIndices.m_capacityAndFlags = 0x80000000;
  v3 = this->m_globalClearanceCache.m_capacityAndFlags;
  this->m_globalClearanceCache.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_globalClearanceCache.m_data,
      2 * (v3 & 0x3FFFFFFF));
  this->m_globalClearanceCache.m_data = 0i64;
  this->m_globalClearanceCache.m_capacityAndFlags = 0x80000000;
  v4 = this->m_clearanceCache.m_capacityAndFlags;
  this->m_clearanceCache.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_clearanceCache.m_data,
      2 * (v4 & 0x3FFFFFFF));
  this->m_clearanceCache.m_data = 0i64;
  this->m_clearanceCache.m_capacityAndFlags = 0x80000000;
  v5 = this->m_ownedEdgeData.m_capacityAndFlags;
  this->m_ownedEdgeData.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_ownedEdgeData.m_data,
      4 * v5);
  this->m_ownedEdgeData.m_data = 0i64;
  this->m_ownedEdgeData.m_capacityAndFlags = 0x80000000;
  v6 = this->m_ownedFaceData.m_capacityAndFlags;
  this->m_ownedFaceData.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_ownedFaceData.m_data,
      4 * v6);
  this->m_ownedFaceData.m_data = 0i64;
  this->m_ownedFaceData.m_capacityAndFlags = 0x80000000;
  v7 = this->m_instancedEdgeData.m_capacityAndFlags;
  this->m_instancedEdgeData.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_instancedEdgeData.m_data,
      4 * v7);
  this->m_instancedEdgeData.m_data = 0i64;
  this->m_instancedEdgeData.m_capacityAndFlags = 0x80000000;
  v8 = this->m_instancedFaceData.m_capacityAndFlags;
  this->m_instancedFaceData.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_instancedFaceData.m_data,
      4 * v8);
  this->m_instancedFaceData.m_data = 0i64;
  this->m_instancedFaceData.m_capacityAndFlags = 0x80000000;
  v9 = this->m_cuttingInfo.m_capacityAndFlags;
  this->m_cuttingInfo.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_cuttingInfo.m_data,
      2 * (v9 & 0x3FFFFFFF));
  this->m_cuttingInfo.m_data = 0i64;
  this->m_cuttingInfo.m_capacityAndFlags = 0x80000000;
  v10 = this->m_faceFlags.m_capacityAndFlags;
  this->m_faceFlags.m_size = 0;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_faceFlags.m_data,
      v10 & 0x3FFFFFFF);
  this->m_faceFlags.m_data = 0i64;
  this->m_faceFlags.m_capacityAndFlags = 0x80000000;
  v11 = this->m_ownedVertices.m_capacityAndFlags;
  this->m_ownedVertices.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_ownedVertices.m_data,
      16 * v11);
  this->m_ownedVertices.m_data = 0i64;
  this->m_ownedVertices.m_capacityAndFlags = 0x80000000;
  v12 = this->m_ownedEdges.m_capacityAndFlags;
  this->m_ownedEdges.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_ownedEdges.m_data,
      20 * (v12 & 0x3FFFFFFF));
  this->m_ownedEdges.m_data = 0i64;
  this->m_ownedEdges.m_capacityAndFlags = 0x80000000;
  v13 = this->m_ownedFaces.m_capacityAndFlags;
  this->m_ownedFaces.m_size = 0;
  if ( v13 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_ownedFaces.m_data,
      16 * v13);
  this->m_ownedFaces.m_data = 0i64;
  this->m_ownedFaces.m_capacityAndFlags = 0x80000000;
  v14 = this->m_instancedEdges.m_capacityAndFlags;
  this->m_instancedEdges.m_size = 0;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_instancedEdges.m_data,
      20 * (v14 & 0x3FFFFFFF));
  this->m_instancedEdges.m_data = 0i64;
  this->m_instancedEdges.m_capacityAndFlags = 0x80000000;
  v15 = this->m_instancedFaces.m_capacityAndFlags;
  this->m_instancedFaces.m_size = 0;
  if ( v15 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_instancedFaces.m_data,
      16 * v15);
  this->m_instancedFaces.m_data = 0i64;
  this->m_instancedFaces.m_capacityAndFlags = 0x80000000;
  v16 = this->m_faceMap.m_capacityAndFlags;
  this->m_faceMap.m_size = 0;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_faceMap.m_data,
      4 * v16);
  this->m_faceMap.m_data = 0i64;
  this->m_faceMap.m_capacityAndFlags = 0x80000000;
  v17 = this->m_edgeMap.m_capacityAndFlags;
  this->m_edgeMap.m_size = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_edgeMap.m_data,
      4 * v17);
  this->m_edgeMap.m_data = 0i64;
  this->m_edgeMap.m_capacityAndFlags = 0x80000000;
  m_pntr = this->m_originalMesh.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_originalMesh.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 85
// RVA: 0xBB9A40
void __fastcall hkaiNavMeshInstance::reinit(hkaiNavMeshInstance *this, hkaiNavMesh *mesh, bool setupClearances)
{
  unsigned int m_sectionUid; // r8d

  this->m_faceMap.m_size = 0;
  this->m_edgeMap.m_size = 0;
  this->m_faceFlags.m_size = 0;
  m_sectionUid = this->m_sectionUid;
  this->m_runtimeId = -1;
  hkaiNavMeshInstance::init(this, mesh, m_sectionUid, setupClearances);
}

// File Line: 97
// RVA: 0xBB9810
void __fastcall hkaiNavMeshInstance::init(
        hkaiNavMeshInstance *this,
        hkaiNavMesh *mesh,
        unsigned int uid,
        bool setupClearances)
{
  hkaiNavMesh *m_pntr; // rcx
  int m_size; // esi
  int v9; // eax
  int v10; // eax
  int v11; // r9d
  int v12; // edx
  int *v13; // rdi
  __int64 v14; // rcx
  int m_numOriginalEdges; // ebp
  int v16; // eax
  int v17; // eax
  int v18; // r9d
  int v19; // r8d
  int *v20; // rdi
  __int64 v21; // rcx
  int m_numOriginalFaces; // esi
  int v23; // eax
  int v24; // eax
  int v25; // r9d
  __int64 v26; // rdx
  int v27; // ecx
  hkFlags<enum hkaiNavMesh::FaceFlagBits,unsigned char> *v28; // rdx
  __int64 v29; // rax
  hkResult result; // [rsp+68h] [rbp+20h] BYREF

  this->m_sectionUid = uid;
  if ( mesh )
    hkReferencedObject::addReference(mesh);
  m_pntr = this->m_originalMesh.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_originalMesh.m_pntr = mesh;
  this->m_originalFaces = mesh->m_faces.m_data;
  m_size = mesh->m_faces.m_size;
  this->m_numOriginalFaces = m_size;
  this->m_originalEdges = mesh->m_edges.m_data;
  this->m_numOriginalEdges = mesh->m_edges.m_size;
  this->m_originalVertices = mesh->m_vertices.m_data;
  this->m_numOriginalVertices = mesh->m_vertices.m_size;
  this->m_originalFaceData = mesh->m_faceData.m_data;
  this->m_faceDataStriding = mesh->m_faceDataStriding;
  this->m_originalEdgeData = mesh->m_edgeData.m_data;
  this->m_edgeDataStriding = mesh->m_edgeDataStriding;
  v9 = this->m_faceMap.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < m_size )
  {
    v10 = 2 * v9;
    v11 = m_size;
    if ( m_size < v10 )
      v11 = v10;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_faceMap, v11, 4);
  }
  v12 = m_size - this->m_faceMap.m_size;
  v13 = &this->m_faceMap.m_data[this->m_faceMap.m_size];
  v14 = v12;
  if ( v12 > 0 )
  {
    while ( v14 )
    {
      *v13++ = -1;
      --v14;
    }
  }
  this->m_faceMap.m_size = m_size;
  m_numOriginalEdges = this->m_numOriginalEdges;
  v16 = this->m_edgeMap.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v16 < m_numOriginalEdges )
  {
    v17 = 2 * v16;
    v18 = this->m_numOriginalEdges;
    if ( m_numOriginalEdges < v17 )
      v18 = v17;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_edgeMap, v18, 4);
  }
  v19 = m_numOriginalEdges - this->m_edgeMap.m_size;
  v20 = &this->m_edgeMap.m_data[this->m_edgeMap.m_size];
  v21 = v19;
  if ( v19 > 0 )
  {
    while ( v21 )
    {
      *v20++ = -1;
      --v21;
    }
  }
  this->m_edgeMap.m_size = m_numOriginalEdges;
  m_numOriginalFaces = this->m_numOriginalFaces;
  v23 = this->m_faceFlags.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v23 < m_numOriginalFaces )
  {
    v24 = 2 * v23;
    v25 = this->m_numOriginalFaces;
    if ( m_numOriginalFaces < v24 )
      v25 = v24;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_faceFlags, v25, 1);
  }
  v26 = this->m_faceFlags.m_size;
  v27 = m_numOriginalFaces - v26;
  v28 = &this->m_faceFlags.m_data[v26];
  v29 = v27;
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
  this->m_faceFlags.m_size = m_numOriginalFaces;
  this->m_ownedFaces.m_size = 0;
  this->m_ownedEdges.m_size = 0;
  this->m_ownedVertices.m_size = 0;
  this->m_instancedEdges.m_size = 0;
  this->m_instancedFaces.m_size = 0;
  if ( setupClearances )
  {
    hkaiNavMeshInstance::initClearanceCache(this);
    hkaiNavMeshInstance::resetVertexClearances(this);
  }
}

// File Line: 182
// RVA: 0xBB9A80
void __fastcall hkaiNavMeshInstance::tempInit(hkaiNavMeshInstance *this, hkaiNavMesh *mesh, bool setupClearances)
{
  hkaiNavMesh *m_pntr; // rcx
  int m_size; // ecx
  hkaiNavMesh::Edge *m_data; // rax
  int v9; // ecx
  hkaiNavMesh::Face *v10; // rax
  int v11; // ecx
  int *v12; // rax
  int v13; // ecx
  int *v14; // rax

  this->m_runtimeId = 0;
  if ( mesh )
    hkReferencedObject::addReference(mesh);
  m_pntr = this->m_originalMesh.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_originalMesh.m_pntr = mesh;
  this->m_originalFaces = mesh->m_faces.m_data;
  this->m_numOriginalFaces = mesh->m_faces.m_size;
  this->m_originalEdges = mesh->m_edges.m_data;
  this->m_numOriginalEdges = mesh->m_edges.m_size;
  this->m_originalVertices = mesh->m_vertices.m_data;
  this->m_numOriginalVertices = mesh->m_vertices.m_size;
  this->m_originalFaceData = mesh->m_faceData.m_data;
  this->m_faceDataStriding = mesh->m_faceDataStriding;
  this->m_originalEdgeData = mesh->m_edgeData.m_data;
  this->m_edgeDataStriding = mesh->m_edgeDataStriding;
  m_size = mesh->m_edges.m_size;
  m_data = mesh->m_edges.m_data;
  this->m_instancedEdges.m_size = m_size;
  this->m_instancedEdges.m_data = m_data;
  this->m_instancedEdges.m_capacityAndFlags = m_size | 0x80000000;
  v9 = mesh->m_faces.m_size;
  v10 = mesh->m_faces.m_data;
  this->m_instancedFaces.m_size = v9;
  this->m_instancedFaces.m_data = v10;
  this->m_instancedFaces.m_capacityAndFlags = v9 | 0x80000000;
  v11 = mesh->m_edgeData.m_size;
  v12 = mesh->m_edgeData.m_data;
  this->m_instancedEdgeData.m_size = v11;
  this->m_instancedEdgeData.m_data = v12;
  this->m_instancedEdgeData.m_capacityAndFlags = v11 | 0x80000000;
  v13 = mesh->m_faceData.m_size;
  v14 = mesh->m_faceData.m_data;
  this->m_instancedFaceData.m_size = v13;
  this->m_instancedFaceData.m_data = v14;
  this->m_instancedFaceData.m_capacityAndFlags = v13 | 0x80000000;
  if ( setupClearances )
  {
    hkaiNavMeshInstance::initClearanceCache(this);
    hkaiNavMeshInstance::resetVertexClearances(this);
  }
}

// File Line: 218
// RVA: 0xBB9E20
void __fastcall hkaiNavMeshInstance::getAabb(hkaiNavMeshInstance *this, hkAabb *aabbOut)
{
  hkaiNavMesh *m_pntr; // rdx
  hkSimdFloat32 extraRadius; // [rsp+20h] [rbp-18h] BYREF

  m_pntr = this->m_originalMesh.m_pntr;
  extraRadius.m_real = ::aabbOut.m_quad;
  hkAabbUtil::calcAabb(&this->m_referenceFrame.m_transform, &m_pntr->m_aabb, &extraRadius, aabbOut);
}

// File Line: 225
// RVA: 0xBBA630
void __fastcall hkaiNavMeshInstance::initClearanceCache(hkaiNavMeshInstance *this)
{
  _QWORD *Value; // rdi
  _QWORD *v3; // rcx
  unsigned __int64 v4; // rax
  _QWORD *v5; // rcx
  int v6; // ebx
  int v7; // edi
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  int m_numOriginalFaces; // ebp
  int *m_data; // rdi
  int index; // r11d
  hkaiNavMesh::Face *m_originalFaces; // r15
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_ownedFaces; // r9
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_instancedFaces; // r8
  hkaiNavMesh::Face *v17; // rax
  int v18; // r11d
  __int64 m_size; // r8
  __int16 *p_m_numEdges; // rdx
  int v21; // ecx
  int v22; // r9d
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // r9d
  int v28; // edx
  hkHalf *v29; // rdi
  __int64 v30; // rcx
  _QWORD *v31; // rax
  _QWORD *v32; // rcx
  _QWORD *v33; // rdi
  unsigned __int64 v34; // rax
  _QWORD *v35; // rcx
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v3 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v3 < Value[3] )
  {
    *v3 = "TtinitClearanceCache";
    v4 = __rdtsc();
    v5 = v3 + 2;
    *((_DWORD *)v5 - 2) = v4;
    Value[1] = v5;
  }
  v6 = 0;
  v7 = this->m_numOriginalFaces + this->m_ownedFaces.m_size;
  v8 = this->m_faceClearanceIndices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v7 )
  {
    v9 = 2 * v8;
    v10 = this->m_numOriginalFaces + this->m_ownedFaces.m_size;
    if ( v7 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_faceClearanceIndices, v10, 4);
  }
  this->m_faceClearanceIndices.m_size = v7;
  m_numOriginalFaces = this->m_numOriginalFaces;
  m_data = this->m_faceClearanceIndices.m_data;
  index = 0;
  if ( m_numOriginalFaces > 0 )
  {
    m_originalFaces = this->m_originalFaces;
    p_m_ownedFaces = &this->m_ownedFaces;
    p_m_instancedFaces = &this->m_instancedFaces;
    do
    {
      *m_data++ = v6;
      v17 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__0(
              m_originalFaces,
              m_numOriginalFaces,
              p_m_instancedFaces,
              p_m_ownedFaces,
              &this->m_faceMap,
              index);
      index = v18 + 1;
      v6 += v17->m_numEdges - 2 + 2 * (v17->m_numEdges - 2);
    }
    while ( index < m_numOriginalFaces );
  }
  m_size = this->m_ownedFaces.m_size;
  if ( m_size > 0 )
  {
    p_m_numEdges = &this->m_ownedFaces.m_data->m_numEdges;
    do
    {
      v21 = *p_m_numEdges;
      *m_data++ = v6;
      p_m_numEdges += 8;
      v6 += v21 - 2 + 2 * (v21 - 2);
      --m_size;
    }
    while ( m_size );
  }
  v22 = (v6 + 7) & 0xFFFFFFF8;
  v23 = this->m_clearanceCache.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v23 < v22 )
  {
    v24 = 2 * v23;
    if ( v22 < v24 )
      v22 = v24;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_clearanceCache, v22, 2);
  }
  v25 = this->m_clearanceCache.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v25 < v6 )
  {
    v26 = 2 * v25;
    v27 = v6;
    if ( v6 < v26 )
      v27 = v26;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_clearanceCache, v27, 2);
  }
  v28 = v6 - this->m_clearanceCache.m_size;
  v29 = &this->m_clearanceCache.m_data[this->m_clearanceCache.m_size];
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
  this->m_clearanceCache.m_size = v6;
  hkaiNavMeshInstance::initGlobalClearanceCache(this);
  v31 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v32 = (_QWORD *)v31[1];
  v33 = v31;
  if ( (unsigned __int64)v32 < v31[3] )
  {
    *v32 = "Et";
    v34 = __rdtsc();
    v35 = v32 + 2;
    *((_DWORD *)v35 - 2) = v34;
    v33[1] = v35;
  }
}

// File Line: 266
// RVA: 0xBBA870
void __fastcall hkaiNavMeshInstance::initGlobalClearanceCache(hkaiNavMeshInstance *this)
{
  hkArray<hkHalf,hkContainerHeapAllocator> *p_m_globalClearanceCache; // rsi
  int v3; // eax
  int v4; // r9d
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // edx
  hkHalf *v11; // rdi
  __int64 v12; // rcx
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  p_m_globalClearanceCache = &this->m_globalClearanceCache;
  v3 = this->m_globalClearanceCache.m_capacityAndFlags & 0x3FFFFFFF;
  v4 = (this->m_numOriginalVertices + this->m_ownedVertices.m_size + 7) & 0xFFFFFFF8;
  if ( v3 < v4 )
  {
    v5 = 2 * v3;
    if ( v4 < v5 )
      v4 = v5;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_globalClearanceCache, v4, 2);
  }
  v6 = this->m_ownedVertices.m_size + this->m_numOriginalVertices;
  v7 = p_m_globalClearanceCache->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v6 )
  {
    v8 = 2 * v7;
    v9 = this->m_ownedVertices.m_size + this->m_numOriginalVertices;
    if ( v6 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_globalClearanceCache, v9, 2);
  }
  v10 = v6 - p_m_globalClearanceCache->m_size;
  v11 = &p_m_globalClearanceCache->m_data[p_m_globalClearanceCache->m_size];
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
  p_m_globalClearanceCache->m_size = v6;
}

// File Line: 274
// RVA: 0xBBA950
void __fastcall hkaiNavMeshInstance::resetVertexClearances(hkaiNavMeshInstance *this)
{
  _QWORD *Value; // r8
  _QWORD *v3; // rcx
  unsigned __int64 v4; // rax
  _QWORD *v5; // rcx
  hkHalf *m_data; // rcx
  signed int v7; // edi
  __int64 v8; // kr00_8
  int v9; // eax
  __int64 v10; // rdx
  hkHalf *v11; // rcx
  __int64 v12; // rax
  _QWORD *v13; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  _QWORD *v16; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v3 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v3 < Value[3] )
  {
    *v3 = "TtresetVertexClearances";
    v4 = __rdtsc();
    v5 = v3 + 2;
    *((_DWORD *)v5 - 2) = v4;
    Value[1] = v5;
  }
  m_data = this->m_clearanceCache.m_data;
  v7 = (this->m_globalClearanceCache.m_size + 7) & 0xFFFFFFF8;
  v8 = (int)((this->m_clearanceCache.m_size + 7) & 0xFFFFFFF8);
  v9 = ((BYTE4(v8) & 7) + (int)v8) >> 3;
  if ( v9 > 0 )
  {
    v10 = (unsigned int)v9;
    do
    {
      *(_DWORD *)&m_data->m_value = -1082081408;
      *(_DWORD *)&m_data[2].m_value = -1082081408;
      *(_DWORD *)&m_data[4].m_value = -1082081408;
      *(_DWORD *)&m_data[6].m_value = -1082081408;
      m_data += 8;
      --v10;
    }
    while ( v10 );
  }
  v11 = this->m_globalClearanceCache.m_data;
  v12 = (unsigned int)(v7 / 8);
  if ( (int)v12 > 0 )
  {
    do
    {
      *(_DWORD *)&v11->m_value = 2139062143;
      *(_DWORD *)&v11[2].m_value = 2139062143;
      *(_DWORD *)&v11[4].m_value = 2139062143;
      *(_DWORD *)&v11[6].m_value = 2139062143;
      v11 += 8;
      --v12;
    }
    while ( v12 );
  }
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = (_QWORD *)v13[1];
  if ( (unsigned __int64)v14 < v13[3] )
  {
    *v14 = "Et";
    v15 = __rdtsc();
    v16 = v14 + 2;
    *((_DWORD *)v16 - 2) = v15;
    v13[1] = v16;
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
  int m_numOriginalEdges; // eax

  m_numOriginalEdges = this->m_numOriginalEdges;
  if ( eIdx < m_numOriginalEdges )
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
    this->m_ownedEdgeData.m_data[eIdx - m_numOriginalEdges] = d;
  }
}

// File Line: 304
// RVA: 0xBB9C20
void __fastcall hkaiNavMeshInstance::setFaceData(hkaiNavMeshInstance *this, int fIdx, int d)
{
  int m_numOriginalFaces; // eax

  m_numOriginalFaces = this->m_numOriginalFaces;
  if ( fIdx < m_numOriginalFaces )
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
    this->m_ownedFaceData.m_data[fIdx - m_numOriginalFaces] = d;
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
  __int64 v3; // r9
  hkaiNavMesh::Edge *m_data; // rax
  __int64 v5; // rdx

  if ( this->m_edgeMap.m_size )
  {
    v2 = eIdx;
    v3 = this->m_edgeMap.m_data[v2];
    m_data = this->m_instancedEdges.m_data;
    v5 = v3;
    *(_QWORD *)&m_data[v5].m_oppositeEdge = -1i64;
    *(_DWORD *)&m_data[v5].m_flags.m_storage = 4;
    if ( this->m_edgeDataStriding )
      this->m_instancedEdgeData.m_data[v3 * this->m_edgeDataStriding] = -559026834;
    this->m_edgeMap.m_data[v2] = -1;
  }
}

// File Line: 357
// RVA: 0xBBA100
void __fastcall hkaiNavMeshInstance::appendVertices(hkaiNavMeshInstance *this, hkVector4f *v, int numV)
{
  hkArrayBase<hkVector4f>::_append(&this->m_ownedVertices, &hkContainerHeapAllocator::s_alloc, v, numV);
}

// File Line: 363
// RVA: 0xBB9E60
void __fastcall hkaiNavMeshInstance::getFaceContext(
        hkaiNavMeshInstance *this,
        int fIdx,
        hkaiNavMeshInstance::AddFaceContext *ctx)
{
  __int64 v3; // rdi
  hkaiNavMeshInstance *v5; // r11
  char m_storage; // [rsp+40h] [rbp+8h]

  v3 = fIdx;
  ctx->m_face = *hkaiNavMeshInstance_get_hkaiNavMesh::Face__0(
                   this->m_originalFaces,
                   this->m_numOriginalFaces,
                   &this->m_instancedFaces,
                   &this->m_ownedFaces,
                   &this->m_faceMap,
                   fIdx);
  if ( v5->m_faceFlags.m_size )
    m_storage = v5->m_faceFlags.m_data[v3].m_storage;
  else
    m_storage = 0;
  ctx->m_flags.m_storage = m_storage;
  hkaiNavMeshInstance::getFaceDataForContext(v5, v3, ctx);
}

// File Line: 371
// RVA: 0xBB9F00
void __fastcall hkaiNavMeshInstance::getFaceDataForContext(
        hkaiNavMeshInstance *this,
        int fIdx,
        hkaiNavMeshInstance::AddFaceContext *ctx)
{
  int striding; // r10d
  const int *v5; // rax
  int v6; // r11d
  int *m_data; // rcx
  __int64 v8; // rdx
  signed __int64 v9; // r8
  int v10; // eax

  striding = this->m_faceDataStriding;
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
    m_data = ctx->m_data;
    if ( v6 == 1 )
    {
      *m_data = *v5;
    }
    else
    {
      v8 = v6;
      if ( v6 >= 1i64 )
      {
        v9 = (char *)v5 - (char *)m_data;
        do
        {
          v10 = *(int *)((char *)m_data++ + v9);
          *(m_data - 1) = v10;
          --v8;
        }
        while ( v8 );
      }
    }
  }
}

// File Line: 381
// RVA: 0xBBA120
void __fastcall hkaiNavMeshInstance::appendFaces(
        hkaiNavMeshInstance *this,
        hkaiNavMeshInstance::AddFaceContext *ctxs,
        int numFaces)
{
  __int64 m_faceDataStriding; // rsi
  hkArray<hkFlags<enum hkaiNavMesh::FaceFlagBits,unsigned char>,hkContainerHeapAllocator> *p_m_faceFlags; // rbx
  __int64 v5; // rbp
  __int64 m_size; // r14
  int v8; // r9d
  int v9; // eax
  int v11; // eax
  hkFlags<enum hkaiNavMesh::FaceFlagBits,unsigned char> *v12; // r12
  hkArray<int,hkContainerHeapAllocator> *p_m_ownedFaceData; // rbx
  __int64 v14; // r15
  int v15; // r9d
  int v16; // eax
  int v17; // eax
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_ownedFaces; // rdi
  __int64 v19; // r14
  int *v20; // rbx
  int v21; // r9d
  int v22; // eax
  int v23; // eax
  __int64 v24; // r11
  hkaiNavMesh::Face *v25; // r10
  int *m_data; // r8
  int *v27; // rax
  __int64 v28; // rdx
  int v29; // ecx
  hkResult v30; // [rsp+70h] [rbp+8h] BYREF
  hkResult result; // [rsp+80h] [rbp+18h] BYREF

  m_faceDataStriding = this->m_faceDataStriding;
  p_m_faceFlags = &this->m_faceFlags;
  v5 = numFaces;
  m_size = this->m_faceFlags.m_size;
  v8 = m_size + numFaces;
  v9 = this->m_faceFlags.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < (int)m_size + numFaces )
  {
    v11 = 2 * v9;
    if ( v8 < v11 )
      v8 = v11;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_faceFlags, v8, 1);
  }
  p_m_faceFlags->m_size += v5;
  v12 = &p_m_faceFlags->m_data[m_size];
  p_m_ownedFaceData = &this->m_ownedFaceData;
  v14 = this->m_ownedFaceData.m_size;
  v15 = v14 + v5 * m_faceDataStriding;
  v16 = this->m_ownedFaceData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v16 < v15 )
  {
    v17 = 2 * v16;
    if ( v15 < v17 )
      v15 = v17;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_ownedFaceData, v15, 4);
  }
  this->m_ownedFaceData.m_size += v5 * m_faceDataStriding;
  p_m_ownedFaces = &this->m_ownedFaces;
  v19 = p_m_ownedFaces->m_size;
  v20 = &p_m_ownedFaceData->m_data[v14];
  v21 = v19 + v5;
  v22 = p_m_ownedFaces->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v22 < (int)v19 + (int)v5 )
  {
    v23 = 2 * v22;
    if ( v21 < v23 )
      v21 = v23;
    hkArrayUtil::_reserve(&v30, &hkContainerHeapAllocator::s_alloc, p_m_ownedFaces, v21, 16);
  }
  p_m_ownedFaces->m_size += v5;
  v24 = 0i64;
  v25 = &p_m_ownedFaces->m_data[v19];
  if ( v5 > 0 )
  {
    m_data = ctxs->m_data;
    do
    {
      v12[v24] = *(hkFlags<enum hkaiNavMesh::FaceFlagBits,unsigned char> *)(m_data - 1);
      v25->m_startEdgeIndex = *(m_data - 5);
      v25->m_startUserEdgeIndex = *(m_data - 4);
      *(_DWORD *)&v25->m_numEdges = *(m_data - 3);
      *(_DWORD *)&v25->m_clusterIndex = *(m_data - 2);
      if ( (_DWORD)m_faceDataStriding == 1 )
      {
        *v20 = *m_data;
      }
      else if ( (int)m_faceDataStriding > 0 )
      {
        v27 = v20;
        v28 = m_faceDataStriding;
        do
        {
          v29 = *(int *)((char *)v27++ + (char *)m_data - (char *)v20);
          *(v27 - 1) = v29;
          --v28;
        }
        while ( v28 );
      }
      ++v24;
      v20 += m_faceDataStriding;
      ++v25;
      m_data += 9;
    }
    while ( v24 < v5 );
  }
}

// File Line: 397
// RVA: 0xBB9FA0
void __fastcall hkaiNavMeshInstance::getEdgeContext(
        hkaiNavMeshInstance *this,
        int eIdx,
        hkaiNavMeshInstance::AddEdgeContext *ctx)
{
  __int64 v3; // rsi
  __int64 m_numOriginalEdges; // rax
  unsigned __int16 v7; // dx

  v3 = eIdx;
  ctx->m_edge = *hkaiNavMeshInstance_get_hkaiNavMesh::Edge__0(
                   this->m_originalEdges,
                   this->m_numOriginalEdges,
                   &this->m_instancedEdges,
                   &this->m_ownedEdges,
                   &this->m_edgeMap,
                   eIdx);
  m_numOriginalEdges = this->m_numOriginalEdges;
  if ( (int)v3 < (int)m_numOriginalEdges )
    v7 = -1;
  else
    v7 = this->m_cuttingInfo.m_data[v3 - m_numOriginalEdges];
  ctx->m_cutInfo = v7;
  hkaiNavMeshInstance::getEdgeDataForContext(this, v3, ctx);
}

// File Line: 405
// RVA: 0xBBA060
void __fastcall hkaiNavMeshInstance::getEdgeDataForContext(
        hkaiNavMeshInstance *this,
        int eIdx,
        hkaiNavMeshInstance::AddEdgeContext *ctx)
{
  int striding; // r10d
  const int *v5; // rax
  int v6; // r11d
  int *m_data; // rcx
  __int64 v8; // rdx
  signed __int64 v9; // r8
  int v10; // eax

  striding = this->m_edgeDataStriding;
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
    m_data = ctx->m_data;
    if ( v6 == 1 )
    {
      *m_data = *v5;
    }
    else
    {
      v8 = v6;
      if ( v6 >= 1i64 )
      {
        v9 = (char *)v5 - (char *)m_data;
        do
        {
          v10 = *(int *)((char *)m_data++ + v9);
          *(m_data - 1) = v10;
          --v8;
        }
        while ( v8 );
      }
    }
  }
}

// File Line: 415
// RVA: 0xBBA2E0
hkaiNavMesh::Edge *__fastcall hkaiNavMeshInstance::appendEdges(
        hkaiNavMeshInstance *this,
        hkaiNavMeshInstance::AddEdgeContext *ctxs,
        int numEdges)
{
  __int64 m_edgeDataStriding; // rbp
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_ownedEdges; // rbx
  __int64 v5; // rsi
  __int64 m_size; // r14
  int v8; // r9d
  int v9; // eax
  int v11; // eax
  hkaiNavMesh::Edge *m_data; // rax
  hkArray<int,hkContainerHeapAllocator> *p_m_ownedEdgeData; // rbx
  hkaiNavMesh::Edge *v14; // r13
  __int64 v15; // r12
  int v16; // r9d
  int v17; // eax
  int v18; // eax
  hkArray<unsigned short,hkContainerHeapAllocator> *p_m_cuttingInfo; // rdi
  __int64 v20; // r14
  char *v21; // rbx
  int v22; // r9d
  int v23; // eax
  int v24; // eax
  unsigned __int16 *v25; // rax
  __int64 v26; // r11
  unsigned __int16 *v27; // r12
  unsigned int *p_m_oppositeEdge; // r9
  unsigned int *v29; // rdx
  char *v30; // rcx
  __int64 v31; // r8
  int v32; // eax
  hkResult v34; // [rsp+70h] [rbp+8h] BYREF
  hkResult result; // [rsp+80h] [rbp+18h] BYREF

  m_edgeDataStriding = this->m_edgeDataStriding;
  p_m_ownedEdges = &this->m_ownedEdges;
  v5 = numEdges;
  m_size = this->m_ownedEdges.m_size;
  v8 = m_size + numEdges;
  v9 = this->m_ownedEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < (int)m_size + numEdges )
  {
    v11 = 2 * v9;
    if ( v8 < v11 )
      v8 = v11;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_ownedEdges, v8, 20);
  }
  p_m_ownedEdges->m_size += v5;
  m_data = p_m_ownedEdges->m_data;
  p_m_ownedEdgeData = &this->m_ownedEdgeData;
  v14 = &m_data[m_size];
  v15 = this->m_ownedEdgeData.m_size;
  v16 = v15 + v5 * m_edgeDataStriding;
  v17 = this->m_ownedEdgeData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v17 < v16 )
  {
    v18 = 2 * v17;
    if ( v16 < v18 )
      v16 = v18;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_ownedEdgeData, v16, 4);
  }
  this->m_ownedEdgeData.m_size += v5 * m_edgeDataStriding;
  p_m_cuttingInfo = &this->m_cuttingInfo;
  v20 = p_m_cuttingInfo->m_size;
  v21 = (char *)&p_m_ownedEdgeData->m_data[v15];
  v22 = v20 + v5;
  v23 = p_m_cuttingInfo->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v23 < (int)v20 + (int)v5 )
  {
    v24 = 2 * v23;
    if ( v22 < v24 )
      v22 = v24;
    hkArrayUtil::_reserve(&v34, &hkContainerHeapAllocator::s_alloc, p_m_cuttingInfo, v22, 2);
  }
  v25 = p_m_cuttingInfo->m_data;
  p_m_cuttingInfo->m_size += v5;
  v26 = 0i64;
  v27 = &v25[v20];
  if ( v5 > 0 )
  {
    p_m_oppositeEdge = &v14->m_oppositeEdge;
    v29 = &ctxs->m_edge.m_oppositeEdge;
    do
    {
      *(p_m_oppositeEdge - 2) = *(v29 - 2);
      *(p_m_oppositeEdge - 1) = *(v29 - 1);
      *p_m_oppositeEdge = *v29;
      p_m_oppositeEdge[1] = v29[1];
      *((_BYTE *)p_m_oppositeEdge + 8) = *((_BYTE *)v29 + 8);
      *((_BYTE *)p_m_oppositeEdge + 9) = *((_BYTE *)v29 + 9);
      *((_WORD *)p_m_oppositeEdge + 5) = *((_WORD *)v29 + 5);
      v27[v26] = *((_WORD *)v29 + 14);
      if ( (_DWORD)m_edgeDataStriding == 1 )
      {
        *(_DWORD *)v21 = v29[3];
      }
      else if ( (int)m_edgeDataStriding > 0 )
      {
        v30 = v21;
        v31 = m_edgeDataStriding;
        do
        {
          v32 = *(_DWORD *)&v30[(char *)v29 - v21 + 12];
          v30 += 4;
          *((_DWORD *)v30 - 1) = v32;
          --v31;
        }
        while ( v31 );
      }
      ++v26;
      v21 += 4 * m_edgeDataStriding;
      p_m_oppositeEdge += 5;
      v29 += 10;
    }
    while ( v26 < v5 );
  }
  return v14;
}

// File Line: 435
// RVA: 0xBBA4C0
hkaiNavMesh::Edge *__fastcall hkaiNavMeshInstance::expandEdgesBy(hkaiNavMeshInstance *this, int n)
{
  int v3; // ebx
  int v4; // eax
  int v6; // eax
  int v7; // r9d
  int v8; // edx
  unsigned __int16 *v9; // rdi
  __int64 v10; // rcx
  int v11; // ebx
  int v12; // r9d
  int v13; // eax
  int v14; // eax
  __int64 m_size; // rbx
  int v16; // r9d
  int v17; // eax
  int v18; // eax
  hkaiNavMesh::Edge *m_data; // rax
  hkResult result; // [rsp+58h] [rbp+10h] BYREF

  v3 = n + this->m_cuttingInfo.m_size;
  v4 = this->m_cuttingInfo.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < v3 )
  {
    v6 = 2 * v4;
    v7 = n + this->m_cuttingInfo.m_size;
    if ( v3 < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_cuttingInfo, v7, 2);
  }
  v8 = v3 - this->m_cuttingInfo.m_size;
  v9 = &this->m_cuttingInfo.m_data[this->m_cuttingInfo.m_size];
  v10 = v8;
  if ( v8 > 0 )
  {
    while ( v10 )
    {
      *v9++ = -1;
      --v10;
    }
  }
  this->m_cuttingInfo.m_size = v3;
  v11 = n * this->m_edgeDataStriding;
  v12 = v11 + this->m_ownedEdgeData.m_size;
  v13 = this->m_ownedEdgeData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 < v12 )
  {
    v14 = 2 * v13;
    if ( v12 < v14 )
      v12 = v14;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_ownedEdgeData, v12, 4);
  }
  this->m_ownedEdgeData.m_size += v11;
  m_size = this->m_ownedEdges.m_size;
  v16 = m_size + n;
  v17 = this->m_ownedEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v17 < (int)m_size + n )
  {
    v18 = 2 * v17;
    if ( v16 < v18 )
      v16 = v18;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_ownedEdges, v16, 20);
  }
  m_data = this->m_ownedEdges.m_data;
  this->m_ownedEdges.m_size += n;
  return &m_data[m_size];
}

// File Line: 443
// RVA: 0xBBAAD0
void __fastcall hkaiNavMeshInstance::checkDeterminism(hkaiNavMeshInstance *this)
{
  hkaiNavMesh::checkDeterminism(this->m_originalMesh.m_pntr);
  hkaiReferenceFrame::checkDeterminism(&this->m_referenceFrame);
}

