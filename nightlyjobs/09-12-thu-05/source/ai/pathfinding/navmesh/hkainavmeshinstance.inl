// File Line: 28
// RVA: 0xC463C0
hkaiNavMesh::Edge *__fastcall hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(
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
// RVA: 0xC46470
int *__fastcall hkaiNavMeshInstance_getWithStriding_int__4(
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

