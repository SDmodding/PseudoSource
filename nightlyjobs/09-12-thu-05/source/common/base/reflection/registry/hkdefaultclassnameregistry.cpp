// File Line: 12
// RVA: 0x12FEDE0
hkReferencedObject *__fastcall hkDefaultClassNameRegistrycreate()
{
  _QWORD **Value; // rax
  hkReferencedObject *result; // rax
  hkReferencedObject *v2; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkReferencedObject *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 56i64);
  v2 = result;
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkDynamicClassNameRegistry::`vftable;
    result[1].vfptr = (hkBaseObjectVtbl *)"hk_2013.2.0-r1";
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&result[1].m_memSizeAndFlags,
      0);
    v2->vfptr = (hkBaseObjectVtbl *)&hkDefaultClassNameRegistry::`vftable;
    return v2;
  }
  return result;
}

