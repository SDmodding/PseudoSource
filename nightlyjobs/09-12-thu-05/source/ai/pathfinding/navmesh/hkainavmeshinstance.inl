// File Line: 28
// RVA: 0xC463C0
hkaiNavMesh::Edge *__fastcall hkaiNavMeshInstance_get_hkaiNavMesh::Edge__23(hkaiNavMesh::Edge *originalArray, int numOriginal, hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *instancedArray, hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *ownedArray, hkArray<int,hkContainerHeapAllocator> *instanceMap, int index)
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
// RVA: 0xC46470
int *__fastcall hkaiNavMeshInstance_getWithStriding_int__4(const int *originalArray, int numOriginal, hkArray<int,hkContainerHeapAllocator> *instancedArray, hkArray<int,hkContainerHeapAllocator> *ownedArray, hkArray<int,hkContainerHeapAllocator> *instanceMap, int index, int striding)
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

