// File Line: 85
// RVA: 0xE5F4C0
void __fastcall hkStorageStringMap<hkTrackerLayoutHandler *,hkContainerHeapAllocator>::clear(
        hkStorageStringMap<int,hkContainerHeapAllocator> *this)
{
  Dummy *Iterator; // rdi
  char *Key; // rax
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)this);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)this,
    &result,
    Iterator);
  while ( result.m_bool )
  {
    Key = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(&this->m_map, Iterator);
    hkString::strFree(Key, &hkContainerHeapAllocator::s_alloc);
    Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
                 (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)this,
                 Iterator);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)this,
      &result,
      Iterator);
  }
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(&this->m_map);
}

