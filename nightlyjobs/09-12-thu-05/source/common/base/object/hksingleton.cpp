// File Line: 14
// RVA: 0xC75530
void __fastcall hkSingletonInitNode::populate(hkSingletonInitNode *dstBase, hkSingletonInitNode *srcBase)
{
  hkSingletonInitNode *v2; // rbx
  unsigned __int64 *v3; // rdi
  unsigned __int64 v4; // rax
  hkReferencedObject *v5; // rcx
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> v6; // [rsp+20h] [rbp-28h]

  v2 = dstBase;
  v3 = (unsigned __int64 *)srcBase;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v6,
    0);
  for ( ; v3; v3 = (unsigned __int64 *)v3[2] )
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&v6, *v3, (unsigned __int64)v3);
  for ( ; v2; v2 = v2->m_next )
  {
    v4 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v6,
           (unsigned __int64)v2->m_name,
           0i64);
    if ( v4 )
    {
      *v2->m_value = **(void ***)(v4 + 24);
      v5 = (hkReferencedObject *)*v2->m_value;
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
  hkSingletonInitNode *v2; // rbx
  unsigned __int64 *v3; // rdi
  hkReferencedObject *v4; // rcx
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> v5; // [rsp+20h] [rbp-28h]

  v2 = dstBase;
  v3 = (unsigned __int64 *)srcBase;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v5,
    0);
  for ( ; v3; v3 = (unsigned __int64 *)v3[2] )
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&v5, *v3, (unsigned __int64)v3);
  for ( ; v2; v2 = v2->m_next )
  {
    if ( hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v5,
           (unsigned __int64)v2->m_name,
           0i64) )
    {
      v4 = (hkReferencedObject *)*v2->m_value;
      if ( v4 )
        hkReferencedObject::removeReferenceLockUnchecked(v4);
      *v2->m_value = 0i64;
    }
  }
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v5);
}

// File Line: 54
// RVA: 0xC75690
hkSingletonInitNode *__fastcall hkSingletonInitNode::findByName(hkSingletonInitNode *this, const char *name)
{
  const char *v2; // rdi
  hkSingletonInitNode *v3; // rbx

  v2 = name;
  v3 = this;
  while ( !v3->m_name || (unsigned int)hkString::strCmp(v2, v3->m_name) )
  {
    v3 = v3->m_next;
    if ( !v3 )
      return 0i64;
  }
  return v3;
}

