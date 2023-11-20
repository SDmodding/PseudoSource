// File Line: 12
// RVA: 0x12FEE50
hkReferencedObject *__fastcall hkTypeInfoRegistrycreate()
{
  _QWORD **v0; // rax
  hkReferencedObject *result; // rax
  hkReferencedObject *v2; // rbx

  v0 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkReferencedObject *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v0[11] + 8i64))(v0[11], 48i64);
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
    result = v2;
  }
  return result;
}

