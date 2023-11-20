// File Line: 86
// RVA: 0xBE4920
hkResult *__fastcall hkaiArrayUtil::reserveSmall<hkaiNavMesh::Edge,hkContainerHeapAllocator>(hkaiArrayUtil *this, hkResult *result, hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *array, int n)
{
  hkResult *v4; // rbx
  __int32 v5; // ecx
  signed int v6; // eax
  hkResult *v7; // rax

  v4 = (hkResult *)this;
  v5 = result[3].m_enum & 0x3FFFFFFF;
  if ( v5 >= (signed int)array )
    goto LABEL_16;
  if ( v5 >= 1024 )
    v6 = 3 * (v5 / 2 + 5) & 0xFFFFFFF0;
  else
    v6 = 2 * v5;
  if ( v5 < n )
  {
    if ( v6 < n )
      n = v6;
    v6 = n;
  }
  if ( (signed int)array < v6 )
    LODWORD(array) = v6;
  if ( v5 >= (signed int)array )
  {
LABEL_16:
    v4->m_enum = 0;
    v7 = v4;
  }
  else
  {
    hkArrayUtil::_reserve(v4, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, result, (int)array, 20);
    v7 = v4;
  }
  return v7;
}

