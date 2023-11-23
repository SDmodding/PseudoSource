// File Line: 28
// RVA: 0xBBC5A0
hkaiNavMesh::Edge *__fastcall hkaiNavMeshInstance_get_hkaiNavMesh::Edge__2(
        hkaiNavMesh::Edge *originalArray,
        int numOriginal,
        hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *instancedArray,
        hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *ownedArray,
        hkArray<int,hkContainerHeapAllocator> *instanceMap,
        int index)
{
  int v7; // edx

  if ( index >= numOriginal )
    return &ownedArray->m_data[index - numOriginal];
  if ( instanceMap->m_size )
    v7 = instanceMap->m_data[index];
  else
    v7 = index;
  if ( v7 == -1 )
    return &originalArray[index];
  else
    return &instancedArray->m_data[v7];
}

// File Line: 56
// RVA: 0xBBC650
int *__fastcall hkaiNavMeshInstance_getWithStriding_int__0(
        const int *originalArray,
        int numOriginal,
        hkArray<int,hkContainerHeapAllocator> *instancedArray,
        hkArray<int,hkContainerHeapAllocator> *ownedArray,
        hkArray<int,hkContainerHeapAllocator> *instanceMap,
        int index,
        int striding)
{
  int v8; // edx

  if ( index >= numOriginal )
    return &ownedArray->m_data[striding * (index - numOriginal)];
  if ( instanceMap->m_size )
    v8 = instanceMap->m_data[index];
  else
    v8 = index;
  if ( v8 == -1 )
    return (int *)&originalArray[striding * index];
  else
    return &instancedArray->m_data[striding * v8];
}

// File Line: 83
// RVA: 0xBD9930
hkaiNavMesh::Edge *__fastcall hkaiNavMeshInstance_getWithData_hkaiNavMesh::Edge_int__1(
        hkaiNavMesh::Edge *originalArray,
        int numOriginal,
        hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *instancedArray,
        hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *ownedArray,
        const int *originalData,
        hkArray<int,hkContainerHeapAllocator> *instancedData,
        hkArray<int,hkContainerHeapAllocator> *ownedData,
        hkArray<int,hkContainerHeapAllocator> *instanceMap,
        int index,
        int striding,
        const int **dataPtrOut)
{
  int v13; // r8d

  if ( index < numOriginal )
  {
    if ( instanceMap->m_size )
      v13 = instanceMap->m_data[index];
    else
      v13 = index;
    if ( v13 == -1 )
    {
      *dataPtrOut = &originalData[striding * index];
      return &originalArray[index];
    }
    else
    {
      *dataPtrOut = &instancedData->m_data[striding * v13];
      return &instancedArray->m_data[v13];
    }
  }
  else
  {
    *dataPtrOut = &ownedData->m_data[striding * (index - numOriginal)];
    return &ownedArray->m_data[index - numOriginal];
  }
}

// File Line: 113
// RVA: 0xC1AAB0
hkaiNavMesh::Edge *__fastcall hkaiNavMeshInstance_instance_hkaiNavMesh::Edge_int__4(
        hkaiNavMesh::Edge *originalArray,
        hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *instancedArray,
        const int *originalData,
        hkArray<int,hkContainerHeapAllocator> *instancedData,
        hkArray<int,hkContainerHeapAllocator> *instanceMap,
        int index,
        int dataStriding)
{
  __int64 v7; // rsi
  __int64 v11; // rdx
  __int64 v12; // r13
  int m_size; // ebp
  __int64 v14; // rdx
  hkaiNavMesh::Edge *v15; // r14
  int v16; // ebx
  hkaiNavMesh::Edge *v17; // rcx
  __int64 v18; // r15
  int v19; // r9d
  int v20; // eax
  int v21; // eax
  int *m_data; // rax
  char *v23; // rcx
  signed __int64 v24; // r9
  __int64 v25; // r8
  int v26; // edx
  hkaiNavMesh::Edge *result; // rax

  v7 = index;
  v11 = instanceMap->m_data[index];
  v12 = index;
  if ( (_DWORD)v11 != -1 )
    return &instancedArray->m_data[v11];
  m_size = instancedArray->m_size;
  if ( m_size == (instancedArray->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, instancedArray, 20);
  v14 = instancedArray->m_size;
  v15 = &instancedArray->m_data[v14];
  instancedArray->m_size = v14 + 1;
  v16 = dataStriding;
  v17 = &originalArray[v7];
  v15->m_a = v17->m_a;
  v15->m_b = v17->m_b;
  v15->m_oppositeEdge = v17->m_oppositeEdge;
  v15->m_oppositeFace = v17->m_oppositeFace;
  v15->m_flags.m_storage = v17->m_flags.m_storage;
  v15->m_paddingByte = v17->m_paddingByte;
  v15->m_userEdgeCost.m_value = v17->m_userEdgeCost.m_value;
  if ( v16 )
  {
    v18 = instancedData->m_size;
    v19 = v18 + v16;
    v20 = instancedData->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v20 < (int)v18 + v16 )
    {
      v21 = 2 * v20;
      if ( v19 < v21 )
        v19 = v21;
      hkArrayUtil::_reserve((hkResult *)&index, &hkContainerHeapAllocator::s_alloc, instancedData, v19, 4);
    }
    m_data = instancedData->m_data;
    instancedData->m_size += v16;
    v23 = (char *)&m_data[v18];
    if ( 4 * v16 > 0 )
    {
      v24 = (char *)&originalData[v16 * (int)v7] - v23;
      v25 = ((unsigned int)(4 * v16 - 1) >> 2) + 1;
      do
      {
        v26 = *(_DWORD *)&v23[v24];
        v23 += 4;
        *((_DWORD *)v23 - 1) = v26;
        --v25;
      }
      while ( v25 );
    }
  }
  result = v15;
  instanceMap->m_data[v12] = m_size;
  return result;
}

// File Line: 461
// RVA: 0xBCCD50
void __fastcall hkaiNavMeshInstance::copyOwnedEdge(hkaiNavMeshInstance *this, int dstIndex, int srcIndex)
{
  hkaiNavMesh::Edge *m_data; // r9
  hkaiNavMesh::Edge *v4; // r11
  hkaiNavMesh::Edge *v5; // r10
  __int64 m_edgeDataStriding; // r9
  int *v7; // rcx
  char *v8; // r8
  char *v9; // rax
  __int64 v10; // rdx
  signed __int64 v11; // r8
  int v12; // ecx

  m_data = this->m_ownedEdges.m_data;
  v4 = &m_data[srcIndex];
  v5 = &m_data[dstIndex];
  v5->m_a = v4->m_a;
  v5->m_b = v4->m_b;
  v5->m_oppositeEdge = v4->m_oppositeEdge;
  v5->m_oppositeFace = v4->m_oppositeFace;
  v5->m_flags.m_storage = v4->m_flags.m_storage;
  v5->m_paddingByte = v4->m_paddingByte;
  v5->m_userEdgeCost.m_value = v4->m_userEdgeCost.m_value;
  this->m_cuttingInfo.m_data[dstIndex] = this->m_cuttingInfo.m_data[srcIndex];
  m_edgeDataStriding = this->m_edgeDataStriding;
  v7 = this->m_ownedEdgeData.m_data;
  v8 = (char *)&v7[srcIndex * (int)m_edgeDataStriding];
  v9 = (char *)&v7[dstIndex * (int)m_edgeDataStriding];
  if ( (_DWORD)m_edgeDataStriding == 1 )
  {
    *(_DWORD *)v9 = *(_DWORD *)v8;
  }
  else
  {
    v10 = m_edgeDataStriding;
    if ( m_edgeDataStriding >= 1 )
    {
      v11 = v8 - v9;
      do
      {
        v12 = *(_DWORD *)&v9[v11];
        v9 += 4;
        *((_DWORD *)v9 - 1) = v12;
        --v10;
      }
      while ( v10 );
    }
  }
}

// File Line: 470
// RVA: 0xBCCE40
void __fastcall hkaiNavMeshInstance::copyOwnedFace(hkaiNavMeshInstance *this, int dstIndex, int srcIndex)
{
  __int64 v3; // rbp
  hkFlags<enum hkaiNavMesh::FaceFlagBits,unsigned char> *v4; // rdx
  __int64 m_faceDataStriding; // rdx
  int *m_data; // rcx
  char *v7; // r8
  char *v8; // rax
  signed __int64 v9; // r8
  int v10; // ecx

  v3 = dstIndex;
  this->m_ownedFaces.m_data[dstIndex] = this->m_ownedFaces.m_data[srcIndex];
  v4 = &this->m_faceFlags.m_data[this->m_numOriginalFaces];
  v4[v3] = v4[srcIndex];
  this->m_faceClearanceIndices.m_data[v3 + this->m_numOriginalFaces] = this->m_faceClearanceIndices.m_data[this->m_numOriginalFaces + (__int64)srcIndex];
  m_faceDataStriding = this->m_faceDataStriding;
  m_data = this->m_ownedFaceData.m_data;
  v7 = (char *)&m_data[srcIndex * (int)m_faceDataStriding];
  v8 = (char *)&m_data[(int)v3 * (int)m_faceDataStriding];
  if ( (_DWORD)m_faceDataStriding == 1 )
  {
    *(_DWORD *)v8 = *(_DWORD *)v7;
  }
  else if ( m_faceDataStriding >= 1 )
  {
    v9 = v7 - v8;
    do
    {
      v10 = *(_DWORD *)&v8[v9];
      v8 += 4;
      *((_DWORD *)v8 - 1) = v10;
      --m_faceDataStriding;
    }
    while ( m_faceDataStriding );
  }
}

// File Line: 478
// RVA: 0xBCCC90
void __fastcall hkaiNavMeshInstance::copyInstancedEdge(hkaiNavMeshInstance *this, int dstIndex, int srcIndex)
{
  __int64 m_edgeDataStriding; // r9
  int *m_data; // rcx
  char *v5; // r8
  char *v6; // rax
  __int64 v7; // rdx
  signed __int64 v8; // r8
  int v9; // ecx

  this->m_instancedEdges.m_data[dstIndex] = this->m_instancedEdges.m_data[srcIndex];
  m_edgeDataStriding = this->m_edgeDataStriding;
  m_data = this->m_instancedEdgeData.m_data;
  v5 = (char *)&m_data[srcIndex * (int)m_edgeDataStriding];
  v6 = (char *)&m_data[dstIndex * (int)m_edgeDataStriding];
  if ( (_DWORD)m_edgeDataStriding == 1 )
  {
    *(_DWORD *)v6 = *(_DWORD *)v5;
  }
  else
  {
    v7 = m_edgeDataStriding;
    if ( m_edgeDataStriding >= 1 )
    {
      v8 = v5 - v6;
      do
      {
        v9 = *(_DWORD *)&v6[v8];
        v6 += 4;
        *((_DWORD *)v6 - 1) = v9;
        --v7;
      }
      while ( v7 );
    }
  }
}

// File Line: 485
// RVA: 0xBCD000
void __fastcall hkaiNavMeshInstance::setNumOwnedEdges(hkaiNavMeshInstance *this, int numOwnedEdges)
{
  int v4; // eax
  int v5; // eax
  int v6; // r9d
  int v7; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // edi
  int v11; // eax
  int v12; // eax
  int v13; // r9d
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  v4 = this->m_ownedEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < numOwnedEdges )
  {
    v5 = 2 * v4;
    v6 = numOwnedEdges;
    if ( numOwnedEdges < v5 )
      v6 = v5;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_ownedEdges, v6, 20);
  }
  this->m_ownedEdges.m_size = numOwnedEdges;
  v7 = this->m_cuttingInfo.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < numOwnedEdges )
  {
    v8 = 2 * v7;
    v9 = numOwnedEdges;
    if ( numOwnedEdges < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_cuttingInfo, v9, 2);
  }
  this->m_cuttingInfo.m_size = numOwnedEdges;
  v10 = numOwnedEdges * this->m_edgeDataStriding;
  v11 = this->m_ownedEdgeData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < v10 )
  {
    v12 = 2 * v11;
    v13 = numOwnedEdges * this->m_edgeDataStriding;
    if ( v10 < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_ownedEdgeData, v13, 4);
  }
  this->m_ownedEdgeData.m_size = v10;
}

// File Line: 492
// RVA: 0xBCD0F0
void __fastcall hkaiNavMeshInstance::setNumOwnedFaces(hkaiNavMeshInstance *this, int numOwnedFaces)
{
  int v3; // eax
  int v4; // ebx
  int v6; // eax
  int v7; // r9d
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  int v11; // eax
  int v12; // eax
  int v13; // r9d
  int v14; // ebx
  int v15; // eax
  int v16; // eax
  int v17; // r9d
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  v3 = this->m_ownedFaces.m_capacityAndFlags & 0x3FFFFFFF;
  v4 = numOwnedFaces + this->m_numOriginalFaces;
  if ( v3 < numOwnedFaces )
  {
    v6 = 2 * v3;
    v7 = numOwnedFaces;
    if ( numOwnedFaces < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_ownedFaces, v7, 16);
  }
  this->m_ownedFaces.m_size = numOwnedFaces;
  v8 = this->m_faceFlags.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v4 )
  {
    v9 = 2 * v8;
    v10 = v4;
    if ( v4 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_faceFlags, v10, 1);
  }
  this->m_faceFlags.m_size = v4;
  v11 = this->m_faceClearanceIndices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < v4 )
  {
    v12 = 2 * v11;
    v13 = v4;
    if ( v4 < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_faceClearanceIndices, v13, 4);
  }
  this->m_faceClearanceIndices.m_size = v4;
  v14 = numOwnedFaces * this->m_faceDataStriding;
  v15 = this->m_ownedFaceData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v15 < v14 )
  {
    v16 = 2 * v15;
    v17 = numOwnedFaces * this->m_faceDataStriding;
    if ( v14 < v16 )
      v17 = v16;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_ownedFaceData, v17, 4);
  }
  this->m_ownedFaceData.m_size = v14;
}

// File Line: 501
// RVA: 0xBCCF50
void __fastcall hkaiNavMeshInstance::setNumInstancedEdges(hkaiNavMeshInstance *this, int numInstancedEdges)
{
  int v4; // eax
  int v5; // eax
  int v6; // r9d
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  v4 = this->m_instancedEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < numInstancedEdges )
  {
    v5 = 2 * v4;
    v6 = numInstancedEdges;
    if ( numInstancedEdges < v5 )
      v6 = v5;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_instancedEdges, v6, 20);
  }
  this->m_instancedEdges.m_size = numInstancedEdges;
  v7 = numInstancedEdges * this->m_edgeDataStriding;
  v8 = this->m_instancedEdgeData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v7 )
  {
    v9 = 2 * v8;
    v10 = numInstancedEdges * this->m_edgeDataStriding;
    if ( v7 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_instancedEdgeData, v10, 4);
  }
  this->m_instancedEdgeData.m_size = v7;
}

