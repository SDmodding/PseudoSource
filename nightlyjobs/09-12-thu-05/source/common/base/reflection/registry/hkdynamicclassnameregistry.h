// File Line: 33
// RVA: 0xE38FC0
void __fastcall UFG::CoverObjectBase::SetCoverObjectGroup(hkDynamicClassNameRegistry *this, const char *name)
{
  this->m_name = name;
}

// File Line: 39
// RVA: 0xE389D0
hkClass *__fastcall hkDynamicClassNameRegistry::getClassByName(hkDynamicClassNameRegistry *this, const char *className)
{
  return (hkClass *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_map,
                      className,
                      0i64);
}

// File Line: 45
// RVA: 0xE38A10
void __fastcall hkDynamicClassNameRegistry::getClasses(
        hkDynamicClassNameRegistry *this,
        hkArray<hkClass const *,hkContainerHeapAllocator> *classes)
{
  hkStringMap<hkClass const *,hkContainerHeapAllocator> *p_m_map; // rdi
  Dummy *Iterator; // rsi
  unsigned __int64 Value; // rbp
  hkClass **m_data; // rcx
  __int64 m_size; // rdx
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  p_m_map = &this->m_map;
  Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_map);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_map,
    &result,
    Iterator);
  while ( result.m_bool )
  {
    Value = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
              (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_map,
              Iterator);
    if ( classes->m_size == (classes->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&classes->m_data, 8);
    m_data = classes->m_data;
    m_size = classes->m_size;
    classes->m_size = m_size + 1;
    m_data[m_size] = (hkClass *)Value;
    Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
                 (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_map,
                 Iterator);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_map,
      &result,
      Iterator);
  }
}

// File Line: 59
// RVA: 0xE38DB0
void __fastcall hkDynamicClassNameRegistry::registerClass(
        hkDynamicClassNameRegistry *this,
        hkClass *klass,
        const char *name)
{
  const char *v3; // rax

  v3 = name;
  if ( !name )
    v3 = hkClass::getName(klass);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &this->m_map.m_map,
    v3,
    (unsigned __int64)klass);
}

// File Line: 65
// RVA: 0xE38DF0
void __fastcall hkDynamicClassNameRegistry::registerList(hkDynamicClassNameRegistry *this, hkClass *const *classes)
{
  hkClass *const *v2; // rbx
  hkClass *i; // rdx

  v2 = classes;
  for ( i = *classes; i; ++v2 )
  {
    ((void (__fastcall *)(hkDynamicClassNameRegistry *, hkClass *, _QWORD))this->vfptr[3].__first_virtual_table_function__)(
      this,
      i,
      0i64);
    i = (hkClass *)*((_QWORD *)v2 + 1);
  }
}

// File Line: 76
// RVA: 0xE38C60
void __fastcall hkDynamicClassNameRegistry::merge(
        hkDynamicClassNameRegistry *this,
        hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *mergeFromMap)
{
  Dummy *Iterator; // rdi
  unsigned __int64 Value; // rax
  hkBool result; // [rsp+38h] [rbp+10h] BYREF

  Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator(mergeFromMap);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(mergeFromMap, &result, Iterator);
  while ( result.m_bool )
  {
    Value = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(mergeFromMap, Iterator);
    ((void (__fastcall *)(hkDynamicClassNameRegistry *, unsigned __int64, _QWORD))this->vfptr[3].__first_virtual_table_function__)(
      this,
      Value,
      0i64);
    Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(mergeFromMap, Iterator);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(mergeFromMap, &result, Iterator);
  }
}

// File Line: 87
// RVA: 0xE38CF0
void __fastcall hkDynamicClassNameRegistry::merge(hkDynamicClassNameRegistry *this, hkClassNameRegistry *mergeFrom)
{
  hkBaseObjectVtbl *vfptr; // rax
  int v4; // edi
  __int64 v5; // rbx
  char *v6; // [rsp+20h] [rbp-18h] BYREF
  int v7; // [rsp+28h] [rbp-10h]
  int v8; // [rsp+2Ch] [rbp-Ch]

  vfptr = mergeFrom->vfptr;
  v6 = 0i64;
  v7 = 0;
  v8 = 0x80000000;
  ((void (__fastcall *)(hkClassNameRegistry *, char **))vfptr[2].__first_virtual_table_function__)(mergeFrom, &v6);
  v4 = 0;
  if ( v7 > 0 )
  {
    v5 = 0i64;
    do
    {
      ((void (__fastcall *)(hkDynamicClassNameRegistry *, _QWORD, _QWORD))this->vfptr[3].__first_virtual_table_function__)(
        this,
        *(_QWORD *)&v6[v5],
        0i64);
      ++v4;
      v5 += 8i64;
    }
    while ( v4 < v7 );
  }
  v7 = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v6, 8 * v8);
}

