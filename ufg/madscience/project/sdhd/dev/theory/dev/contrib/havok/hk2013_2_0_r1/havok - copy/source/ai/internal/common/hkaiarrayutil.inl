// File Line: 86
// RVA: 0xBE4920
hkaiArrayUtil *__fastcall hkaiArrayUtil::reserveSmall<hkaiNavMesh::Edge,hkContainerHeapAllocator>(
        hkaiArrayUtil *this,
        hkResult *result,
        hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *array,
        int n)
{
  __int32 v5; // ecx
  signed int v6; // eax

  v5 = result[3].m_enum & 0x3FFFFFFF;
  if ( v5 >= (int)array )
    goto LABEL_13;
  if ( (result[3].m_enum & 0x3FFFFFFFu) >= 0x400 )
    v6 = (3 * (v5 / 2 + 5)) & 0xFFFFFFF0;
  else
    v6 = 2 * v5;
  if ( v5 < n )
  {
    if ( v6 < n )
      n = v6;
    v6 = n;
  }
  if ( (int)array < v6 )
    LODWORD(array) = v6;
  if ( v5 >= (int)array )
  {
LABEL_13:
    *(_DWORD *)this = 0;
    return this;
  }
  else
  {
    hkArrayUtil::_reserve((hkResult *)this, &hkContainerHeapAllocator::s_alloc, result, (int)array, 20);
    return this;
  }
}

