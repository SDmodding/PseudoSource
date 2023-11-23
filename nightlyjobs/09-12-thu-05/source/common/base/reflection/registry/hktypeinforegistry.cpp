// File Line: 12
// RVA: 0x12FEE50
hkReferencedObject *__fastcall hkTypeInfoRegistrycreate()
{
  _QWORD **Value; // rax
  hkReferencedObject *result; // rax
  hkReferencedObject *v2; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkReferencedObject *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  v2 = result;
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkTypeInfoRegistry::`vftable;
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&result[1],
      0);
    *(_DWORD *)&v2[2].m_memSizeAndFlags = 1;
    *(_DWORD *)(&v2[2].m_referenceCount + 1) = 1;
    return v2;
  }
  return result;
}

