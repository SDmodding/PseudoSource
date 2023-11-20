// File Line: 29
// RVA: 0xB89D0
void __fastcall hkTypeInfoRegistry::registerTypeInfo(hkTypeInfoRegistry *this, hkTypeInfo *info)
{
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &this->m_map.m_map,
    (unsigned __int64)info->m_typeName,
    (unsigned __int64)info);
}

// File Line: 37
// RVA: 0xB7EE0
hkTypeInfo *__fastcall hkTypeInfoRegistry::finishLoadedObject(hkTypeInfoRegistry *this, void *obj, const char *className)
{
  void *v3; // rsi
  hkTypeInfoRegistry *v4; // rdi
  hkTypeInfo *result; // rax
  hkTypeInfo *v6; // rbx

  v3 = obj;
  v4 = this;
  result = (hkTypeInfo *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_map,
                           (unsigned __int64)className,
                           0i64);
  v6 = result;
  if ( result )
  {
    hkTypeInfo::finishLoadedObject(result, v3, v4->m_finishFlag);
    result = v6;
  }
  return result;
}

// File Line: 52
// RVA: 0xB6F40
hkTypeInfo *__fastcall hkTypeInfoRegistry::cleanupLoadedObject(hkTypeInfoRegistry *this, void *obj, const char *className)
{
  void *v3; // rdi
  hkTypeInfo *result; // rax
  hkTypeInfo *v5; // rbx

  v3 = obj;
  result = (hkTypeInfo *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_map,
                           (unsigned __int64)className,
                           0i64);
  v5 = result;
  if ( result )
  {
    hkTypeInfo::cleanupLoadedObject(result, v3);
    result = v5;
  }
  return result;
}

// File Line: 78
// RVA: 0xB8740
void __fastcall hkTypeInfoRegistry::merge(hkTypeInfoRegistry *this, hkTypeInfoRegistry *mergeFrom)
{
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v2; // rbx
  hkTypeInfoRegistry *v3; // rbp
  Dummy *v4; // rsi
  unsigned __int64 v5; // rdi
  unsigned __int64 v6; // rax
  hkBool result; // [rsp+38h] [rbp+10h]

  v2 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&mergeFrom->m_map;
  v3 = this;
  v4 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&mergeFrom->m_map);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v2, &result, v4);
  while ( result.m_bool )
  {
    v5 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(v2, v4);
    v6 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(
           (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v2,
           v4);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&v3->m_map.m_map, v6, v5);
    v4 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(v2, v4);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v2, &result, v4);
  }
}

// File Line: 89
// RVA: 0xB8040
hkTypeInfo *__fastcall hkTypeInfoRegistry::getTypeInfo(hkTypeInfoRegistry *this, const char *typeName)
{
  return (hkTypeInfo *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_map,
                         (unsigned __int64)typeName,
                         0i64);
}

