// File Line: 14
// RVA: 0xC75530
void __fastcall hkSingletonInitNode::populate(hkSingletonInitNode *dstBase, hkSingletonInitNode *srcBase)
{
  unsigned __int64 v4; // rax
  hkReferencedObject *v5; // rcx
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> v6; // [rsp+20h] [rbp-28h] BYREF

  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v6,
    0);
  for ( ; srcBase; srcBase = srcBase->m_next )
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
      &v6,
      srcBase->m_name,
      (unsigned __int64)srcBase);
  for ( ; dstBase; dstBase = dstBase->m_next )
  {
    v4 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v6,
           dstBase->m_name,
           0i64);
    if ( v4 )
    {
      *dstBase->m_value = **(void ***)(v4 + 24);
      v5 = (hkReferencedObject *)*dstBase->m_value;
      if ( v5 )
        hkReferencedObject::addReferenceLockUnchecked(v5);
    }
  }
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v6);
}

// File Line: 34
// RVA: 0xC755E0
void __fastcall hkSingletonInitNode::depopulate(hkSingletonInitNode *dstBase, hkSingletonInitNode *srcBase)
{
  hkReferencedObject *v4; // rcx
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> v5; // [rsp+20h] [rbp-28h] BYREF

  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v5,
    0);
  for ( ; srcBase; srcBase = srcBase->m_next )
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
      &v5,
      srcBase->m_name,
      (unsigned __int64)srcBase);
  for ( ; dstBase; dstBase = dstBase->m_next )
  {
    if ( hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v5,
           dstBase->m_name,
           0i64) )
    {
      v4 = (hkReferencedObject *)*dstBase->m_value;
      if ( v4 )
        hkReferencedObject::removeReferenceLockUnchecked(v4);
      *dstBase->m_value = 0i64;
    }
  }
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v5);
}

// File Line: 54
// RVA: 0xC75690
hkSingletonInitNode *__fastcall hkSingletonInitNode::findByName(hkSingletonInitNode *this, const char *name)
{
  while ( !this->m_name || (unsigned int)hkString::strCmp(name, this->m_name) )
  {
    this = this->m_next;
    if ( !this )
      return 0i64;
  }
  return this;
}

