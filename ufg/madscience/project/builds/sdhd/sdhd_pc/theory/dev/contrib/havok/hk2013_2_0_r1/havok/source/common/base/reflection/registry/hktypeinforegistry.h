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
hkTypeInfo *__fastcall hkTypeInfoRegistry::finishLoadedObject(
        hkTypeInfoRegistry *this,
        void *obj,
        const char *className)
{
  hkTypeInfo *result; // rax
  hkTypeInfo *v6; // rbx

  result = (hkTypeInfo *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_map,
                           (unsigned __int64)className,
                           0i64);
  v6 = result;
  if ( result )
  {
    hkTypeInfo::finishLoadedObject(result, obj, this->m_finishFlag);
    return v6;
  }
  return result;
}

// File Line: 52
// RVA: 0xB6F40
hkTypeInfo *__fastcall hkTypeInfoRegistry::cleanupLoadedObject(
        hkTypeInfoRegistry *this,
        void *obj,
        const char *className)
{
  hkTypeInfo *result; // rax
  hkTypeInfo *v5; // rbx

  result = (hkTypeInfo *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_map,
                           (unsigned __int64)className,
                           0i64);
  v5 = result;
  if ( result )
  {
    hkTypeInfo::cleanupLoadedObject(result, obj);
    return v5;
  }
  return result;
}

// File Line: 78
// RVA: 0xB8740
void __fastcall hkTypeInfoRegistry::merge(hkTypeInfoRegistry *this, hkTypeInfoRegistry *mergeFrom)
{
  hkStringMap<hkTypeInfo const *,hkContainerHeapAllocator> *p_m_map; // rbx
  Dummy *Iterator; // rsi
  unsigned __int64 Value; // rdi
  unsigned __int64 Key; // rax
  hkBool result; // [rsp+38h] [rbp+10h] BYREF

  p_m_map = &mergeFrom->m_map;
  Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&mergeFrom->m_map);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_map,
    &result,
    Iterator);
  while ( result.m_bool )
  {
    Value = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
              (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_map,
              Iterator);
    Key = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(&p_m_map->m_map, Iterator);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&this->m_map.m_map, Key, Value);
    Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
                 (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_map,
                 Iterator);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_map,
      &result,
      Iterator);
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

