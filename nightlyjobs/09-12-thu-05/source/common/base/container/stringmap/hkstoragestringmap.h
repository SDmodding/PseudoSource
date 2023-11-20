// File Line: 85
// RVA: 0xE5F4C0
void __fastcall hkStorageStringMap<hkTrackerLayoutHandler *,hkContainerHeapAllocator>::clear(hkStorageStringMap<int,hkContainerHeapAllocator> *this)
{
  hkStorageStringMap<int,hkContainerHeapAllocator> *v1; // rbx
  Dummy *v2; // rdi
  char *v3; // rax
  hkBool result; // [rsp+30h] [rbp+8h]

  v1 = this;
  v2 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)this);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v1,
    &result,
    v2);
  while ( result.m_bool )
  {
    v3 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(&v1->m_map, v2);
    hkString::strFree(v3, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    v2 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v1,
           v2);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v1,
      &result,
      v2);
  }
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(&v1->m_map);
}

