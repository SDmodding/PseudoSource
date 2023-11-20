// File Line: 28
// RVA: 0xBBC5A0
hkaiNavMesh::Edge *__fastcall hkaiNavMeshInstance_get_hkaiNavMesh::Edge__2(hkaiNavMesh::Edge *originalArray, int numOriginal, hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *instancedArray, hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *ownedArray, hkArray<int,hkContainerHeapAllocator> *instanceMap, int index)
{
  hkaiNavMesh::Edge *result; // rax
  int v7; // edx

  if ( index >= numOriginal )
    return &ownedArray->m_data[index - numOriginal];
  if ( instanceMap->m_size )
    v7 = instanceMap->m_data[index];
  else
    v7 = index;
  if ( v7 == -1 )
    result = &originalArray[index];
  else
    result = &instancedArray->m_data[v7];
  return result;
}

// File Line: 56
// RVA: 0xBBC650
int *__fastcall hkaiNavMeshInstance_getWithStriding_int__0(const int *originalArray, int numOriginal, hkArray<int,hkContainerHeapAllocator> *instancedArray, hkArray<int,hkContainerHeapAllocator> *ownedArray, hkArray<int,hkContainerHeapAllocator> *instanceMap, int index, int striding)
{
  int *result; // rax
  int v8; // edx

  if ( index >= numOriginal )
    return &ownedArray->m_data[striding * (index - numOriginal)];
  if ( instanceMap->m_size )
    v8 = instanceMap->m_data[index];
  else
    v8 = index;
  if ( v8 == -1 )
    result = (int *)&originalArray[striding * index];
  else
    result = &instancedArray->m_data[striding * v8];
  return result;
}

// File Line: 83
// RVA: 0xBD9930
hkaiNavMesh::Edge *__fastcall hkaiNavMeshInstance_getWithData_hkaiNavMesh::Edge_int__1(hkaiNavMesh::Edge *originalArray, int numOriginal, hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *instancedArray, hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *ownedArray, const int *originalData, hkArray<int,hkContainerHeapAllocator> *instancedData, hkArray<int,hkContainerHeapAllocator> *ownedData, hkArray<int,hkContainerHeapAllocator> *instanceMap, int index, int striding, const int **dataPtrOut)
{
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v11; // rbx
  hkaiNavMesh::Edge *result; // rax
  int v13; // er8

  v11 = instancedArray;
  if ( index < numOriginal )
  {
    if ( instanceMap->m_size )
      v13 = instanceMap->m_data[index];
    else
      v13 = index;
    if ( v13 == -1 )
    {
      *dataPtrOut = &originalData[striding * index];
      result = &originalArray[index];
    }
    else
    {
      *dataPtrOut = &instancedData->m_data[striding * v13];
      result = &v11->m_data[v13];
    }
  }
  else
  {
    *dataPtrOut = &ownedData->m_data[striding * (index - numOriginal)];
    result = &ownedArray->m_data[index - numOriginal];
  }
  return result;
}

// File Line: 113
// RVA: 0xC1AAB0
hkaiNavMesh::Edge *__fastcall hkaiNavMeshInstance_instance_hkaiNavMesh::Edge_int__4(hkaiNavMesh::Edge *originalArray, hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *instancedArray, const int *originalData, hkArray<int,hkContainerHeapAllocator> *instancedData, hkArray<int,hkContainerHeapAllocator> *instanceMap, int index, int dataStriding)
{
  __int64 v7; // rsi
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v8; // rbx
  hkArray<int,hkContainerHeapAllocator> *v9; // rdi
  hkaiNavMesh::Edge *v10; // r15
  __int64 v11; // rdx
  __int64 v12; // r13
  int v13; // ebp
  __int64 v14; // rdx
  hkaiNavMesh::Edge *v15; // r14
  int v16; // ebx
  signed __int64 v17; // rcx
  __int64 v18; // r15
  int v19; // er9
  int v20; // eax
  int v21; // eax
  int *v22; // rax
  signed __int64 v23; // rcx
  signed __int64 v24; // r9
  __int64 v25; // r8
  int v26; // edx
  hkaiNavMesh::Edge *result; // rax
  const int *v28; // [rsp+70h] [rbp+18h]

  v28 = originalData;
  v7 = index;
  v8 = instancedArray;
  v9 = instancedData;
  v10 = originalArray;
  v11 = instanceMap->m_data[index];
  v12 = index;
  if ( (_DWORD)v11 != -1 )
    return &v8->m_data[v11];
  v13 = v8->m_size;
  if ( v13 == (v8->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, 20);
  v14 = v8->m_size;
  v15 = &v8->m_data[v14];
  v8->m_size = v14 + 1;
  v16 = dataStriding;
  v17 = (signed __int64)&v10[v7];
  v15->m_a = v10[v7].m_a;
  v15->m_b = *(_DWORD *)(v17 + 4);
  v15->m_oppositeEdge = *(_DWORD *)(v17 + 8);
  v15->m_oppositeFace = *(_DWORD *)(v17 + 12);
  v15->m_flags.m_storage = *(_BYTE *)(v17 + 16);
  v15->m_paddingByte = *(_BYTE *)(v17 + 17);
  v15->m_userEdgeCost.m_value = *(_WORD *)(v17 + 18);
  if ( v16 )
  {
    v18 = v9->m_size;
    v19 = v18 + v16;
    v20 = v9->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v20 < (signed int)v18 + v16 )
    {
      v21 = 2 * v20;
      if ( v19 < v21 )
        v19 = v21;
      hkArrayUtil::_reserve(
        (hkResult *)&index,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v9,
        v19,
        4);
    }
    v22 = v9->m_data;
    v9->m_size += v16;
    v23 = (signed __int64)&v22[v18];
    if ( 4 * v16 > 0 )
    {
      v24 = (signed __int64)&v28[v16 * (signed int)v7] - v23;
      v25 = ((unsigned int)(4 * v16 - 1) >> 2) + 1;
      do
      {
        v26 = *(_DWORD *)(v24 + v23);
        v23 += 4i64;
        *(_DWORD *)(v23 - 4) = v26;
        --v25;
      }
      while ( v25 );
    }
  }
  result = v15;
  instanceMap->m_data[v12] = v13;
  return result;
}

// File Line: 461
// RVA: 0xBCCD50
void __fastcall hkaiNavMeshInstance::copyOwnedEdge(hkaiNavMeshInstance *this, int dstIndex, int srcIndex)
{
  hkaiNavMesh::Edge *v3; // r9
  signed __int64 v4; // r11
  signed __int64 v5; // r10
  signed __int64 v6; // r9
  int *v7; // rcx
  char *v8; // r8
  char *v9; // rax
  signed __int64 v10; // rdx
  signed __int64 v11; // r8
  int v12; // ecx

  v3 = this->m_ownedEdges.m_data;
  v4 = (signed __int64)&v3[srcIndex];
  v5 = (signed __int64)&v3[dstIndex];
  *(_DWORD *)v5 = *(_DWORD *)v4;
  *(_DWORD *)(v5 + 4) = *(_DWORD *)(v4 + 4);
  *(_DWORD *)(v5 + 8) = *(_DWORD *)(v4 + 8);
  *(_DWORD *)(v5 + 12) = *(_DWORD *)(v4 + 12);
  *(_BYTE *)(v5 + 16) = *(_BYTE *)(v4 + 16);
  *(_BYTE *)(v5 + 17) = *(_BYTE *)(v4 + 17);
  *(_WORD *)(v5 + 18) = *(_WORD *)(v4 + 18);
  this->m_cuttingInfo.m_data[dstIndex] = this->m_cuttingInfo.m_data[srcIndex];
  v6 = this->m_edgeDataStriding;
  v7 = this->m_ownedEdgeData.m_data;
  v8 = (char *)&v7[srcIndex * (signed int)v6];
  v9 = (char *)&v7[dstIndex * (signed int)v6];
  if ( (_DWORD)v6 == 1 )
  {
    *(_DWORD *)v9 = *(_DWORD *)v8;
  }
  else
  {
    v10 = v6;
    if ( v6 >= 1 )
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
  hkaiNavMesh::Face *v3; // r10
  __int64 v4; // rbp
  hkaiNavMesh::Face *v5; // r11
  hkFlags<enum hkaiNavMesh::FaceFlagBits,unsigned char> *v6; // rdx
  signed __int64 v7; // rdx
  int *v8; // rcx
  char *v9; // r8
  char *v10; // rax
  signed __int64 v11; // r8
  int v12; // ecx

  v3 = this->m_ownedFaces.m_data;
  v4 = dstIndex;
  v5 = &v3[dstIndex];
  v5->m_startEdgeIndex = v3[srcIndex].m_startEdgeIndex;
  v5->m_startUserEdgeIndex = v3[srcIndex].m_startUserEdgeIndex;
  *(_DWORD *)&v5->m_numEdges = *(_DWORD *)&v3[srcIndex].m_numEdges;
  *(_DWORD *)&v5->m_clusterIndex = *(_DWORD *)&v3[srcIndex].m_clusterIndex;
  v6 = &this->m_faceFlags.m_data[this->m_numOriginalFaces];
  v6[v4] = v6[srcIndex];
  this->m_faceClearanceIndices.m_data[v4 + this->m_numOriginalFaces] = this->m_faceClearanceIndices.m_data[this->m_numOriginalFaces + (signed __int64)srcIndex];
  v7 = this->m_faceDataStriding;
  v8 = this->m_ownedFaceData.m_data;
  v9 = (char *)&v8[srcIndex * (signed int)v7];
  v10 = (char *)&v8[(signed int)v4 * (signed int)v7];
  if ( (_DWORD)v7 == 1 )
  {
    *(_DWORD *)v10 = *(_DWORD *)v9;
  }
  else if ( v7 >= 1 )
  {
    v11 = v9 - v10;
    do
    {
      v12 = *(_DWORD *)&v10[v11];
      v10 += 4;
      *((_DWORD *)v10 - 1) = v12;
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 478
// RVA: 0xBCCC90
void __fastcall hkaiNavMeshInstance::copyInstancedEdge(hkaiNavMeshInstance *this, int dstIndex, int srcIndex)
{
  hkaiNavMesh::Edge *v3; // r10
  signed __int64 v4; // r11
  signed __int64 v5; // r9
  signed __int64 v6; // r9
  int *v7; // rcx
  char *v8; // r8
  char *v9; // rax
  signed __int64 v10; // rdx
  signed __int64 v11; // r8
  int v12; // ecx

  v3 = this->m_instancedEdges.m_data;
  v4 = (signed __int64)&v3[srcIndex];
  v5 = dstIndex;
  v3[v5].m_a = *(_DWORD *)v4;
  v3[v5].m_b = *(_DWORD *)(v4 + 4);
  v3[v5].m_oppositeEdge = *(_DWORD *)(v4 + 8);
  v3[v5].m_oppositeFace = *(_DWORD *)(v4 + 12);
  v3[v5].m_flags.m_storage = *(_BYTE *)(v4 + 16);
  v3[v5].m_paddingByte = *(_BYTE *)(v4 + 17);
  v3[v5].m_userEdgeCost.m_value = *(_WORD *)(v4 + 18);
  v6 = this->m_edgeDataStriding;
  v7 = this->m_instancedEdgeData.m_data;
  v8 = (char *)&v7[srcIndex * (signed int)v6];
  v9 = (char *)&v7[dstIndex * (signed int)v6];
  if ( (_DWORD)v6 == 1 )
  {
    *(_DWORD *)v9 = *(_DWORD *)v8;
  }
  else
  {
    v10 = v6;
    if ( v6 >= 1 )
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

// File Line: 485
// RVA: 0xBCD000
void __fastcall hkaiNavMeshInstance::setNumOwnedEdges(hkaiNavMeshInstance *this, int numOwnedEdges)
{
  int v2; // ebx
  hkaiNavMeshInstance *v3; // rsi
  int v4; // eax
  int v5; // eax
  int v6; // er9
  int v7; // eax
  int v8; // eax
  int v9; // er9
  int v10; // edi
  int v11; // eax
  int v12; // eax
  int v13; // er9
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = numOwnedEdges;
  v3 = this;
  v4 = this->m_ownedEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < numOwnedEdges )
  {
    v5 = 2 * v4;
    v6 = numOwnedEdges;
    if ( numOwnedEdges < v5 )
      v6 = v5;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_ownedEdges,
      v6,
      20);
  }
  v3->m_ownedEdges.m_size = v2;
  v7 = v3->m_cuttingInfo.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v2 )
  {
    v8 = 2 * v7;
    v9 = v2;
    if ( v2 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v3->m_cuttingInfo,
      v9,
      2);
  }
  v3->m_cuttingInfo.m_size = v2;
  v10 = v2 * v3->m_edgeDataStriding;
  v11 = v3->m_ownedEdgeData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < v10 )
  {
    v12 = 2 * v11;
    v13 = v2 * v3->m_edgeDataStriding;
    if ( v10 < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v3->m_ownedEdgeData,
      v13,
      4);
  }
  v3->m_ownedEdgeData.m_size = v10;
}

// File Line: 492
// RVA: 0xBCD0F0
void __fastcall hkaiNavMeshInstance::setNumOwnedFaces(hkaiNavMeshInstance *this, int numOwnedFaces)
{
  int v2; // esi
  int v3; // eax
  int v4; // ebx
  hkaiNavMeshInstance *v5; // rdi
  int v6; // eax
  int v7; // er9
  int v8; // eax
  int v9; // eax
  int v10; // er9
  int v11; // eax
  int v12; // eax
  int v13; // er9
  int v14; // ebx
  int v15; // eax
  int v16; // eax
  int v17; // er9
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = numOwnedFaces;
  v3 = this->m_ownedFaces.m_capacityAndFlags & 0x3FFFFFFF;
  v4 = numOwnedFaces + this->m_numOriginalFaces;
  v5 = this;
  if ( v3 < numOwnedFaces )
  {
    v6 = 2 * v3;
    v7 = numOwnedFaces;
    if ( numOwnedFaces < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_ownedFaces,
      v7,
      16);
  }
  v5->m_ownedFaces.m_size = v2;
  v8 = v5->m_faceFlags.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v4 )
  {
    v9 = 2 * v8;
    v10 = v4;
    if ( v4 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v5->m_faceFlags,
      v10,
      1);
  }
  v5->m_faceFlags.m_size = v4;
  v11 = v5->m_faceClearanceIndices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < v4 )
  {
    v12 = 2 * v11;
    v13 = v4;
    if ( v4 < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v5->m_faceClearanceIndices,
      v13,
      4);
  }
  v5->m_faceClearanceIndices.m_size = v4;
  v14 = v2 * v5->m_faceDataStriding;
  v15 = v5->m_ownedFaceData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v15 < v14 )
  {
    v16 = 2 * v15;
    v17 = v2 * v5->m_faceDataStriding;
    if ( v14 < v16 )
      v17 = v16;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v5->m_ownedFaceData,
      v17,
      4);
  }
  v5->m_ownedFaceData.m_size = v14;
}

// File Line: 501
// RVA: 0xBCCF50
void __fastcall hkaiNavMeshInstance::setNumInstancedEdges(hkaiNavMeshInstance *this, int numInstancedEdges)
{
  int v2; // edi
  hkaiNavMeshInstance *v3; // rsi
  int v4; // eax
  int v5; // eax
  int v6; // er9
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // er9
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = numInstancedEdges;
  v3 = this;
  v4 = this->m_instancedEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < numInstancedEdges )
  {
    v5 = 2 * v4;
    v6 = numInstancedEdges;
    if ( numInstancedEdges < v5 )
      v6 = v5;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_instancedEdges,
      v6,
      20);
  }
  v3->m_instancedEdges.m_size = v2;
  v7 = v2 * v3->m_edgeDataStriding;
  v8 = v3->m_instancedEdgeData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v7 )
  {
    v9 = 2 * v8;
    v10 = v2 * v3->m_edgeDataStriding;
    if ( v7 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v3->m_instancedEdgeData,
      v10,
      4);
  }
  v3->m_instancedEdgeData.m_size = v7;
}

