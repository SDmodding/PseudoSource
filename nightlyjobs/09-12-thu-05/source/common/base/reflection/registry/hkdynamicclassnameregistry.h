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
                      (unsigned __int64)className,
                      0i64);
}

// File Line: 45
// RVA: 0xE38A10
void __fastcall hkDynamicClassNameRegistry::getClasses(hkDynamicClassNameRegistry *this, hkArray<hkClass const *,hkContainerHeapAllocator> *classes)
{
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v2; // rdi
  hkArray<hkClass const *,hkContainerHeapAllocator> *v3; // rbx
  Dummy *v4; // rsi
  unsigned __int64 v5; // rbp
  __int64 v6; // rax
  hkClass **v7; // rcx
  hkBool result; // [rsp+30h] [rbp+8h]

  v2 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_map;
  v3 = classes;
  v4 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_map);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v2, &result, v4);
  while ( result.m_bool )
  {
    v5 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(v2, v4);
    if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 8);
    v6 = v3->m_size;
    v7 = v3->m_data;
    v3->m_size = v6 + 1;
    v7[v6] = (hkClass *)v5;
    v4 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(v2, v4);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v2, &result, v4);
  }
}

// File Line: 59
// RVA: 0xE38DB0
void __fastcall hkDynamicClassNameRegistry::registerClass(hkDynamicClassNameRegistry *this, hkClass *klass, const char *name)
{
  const char *v3; // rax
  hkClass *v4; // rbx
  hkDynamicClassNameRegistry *v5; // rdi

  v3 = name;
  v4 = klass;
  v5 = this;
  if ( !name )
    v3 = hkClass::getName(klass);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &v5->m_map.m_map,
    (unsigned __int64)v3,
    (unsigned __int64)v4);
}

// File Line: 65
// RVA: 0xE38DF0
void __fastcall hkDynamicClassNameRegistry::registerList(hkDynamicClassNameRegistry *this, hkClass *const *classes)
{
  hkClass *const *v2; // rbx
  hkClass *v3; // rdx
  hkDynamicClassNameRegistry *i; // rdi

  v2 = classes;
  v3 = *classes;
  for ( i = this; v3; ++v2 )
  {
    ((void (__fastcall *)(hkDynamicClassNameRegistry *, hkClass *, _QWORD))i->vfptr[3].__first_virtual_table_function__)(
      i,
      v3,
      0i64);
    v3 = (hkClass *)*((_QWORD *)v2 + 1);
  }
}

// File Line: 76
// RVA: 0xE38C60
void __fastcall hkDynamicClassNameRegistry::merge(hkDynamicClassNameRegistry *this, hkStringMap<hkClass const *,hkContainerHeapAllocator> *mergeFromMap)
{
  hkDynamicClassNameRegistry *v2; // rsi
  hkStringMap<hkClass const *,hkContainerHeapAllocator> *v3; // rbx
  Dummy *v4; // rdi
  unsigned __int64 v5; // rax
  hkBool result; // [rsp+38h] [rbp+10h]

  v2 = this;
  v3 = mergeFromMap;
  v4 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)mergeFromMap);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v3,
    &result,
    v4);
  while ( result.m_bool )
  {
    v5 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v3,
           v4);
    ((void (__fastcall *)(hkDynamicClassNameRegistry *, unsigned __int64, _QWORD))v2->vfptr[3].__first_virtual_table_function__)(
      v2,
      v5,
      0i64);
    v4 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v3,
           v4);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v3,
      &result,
      v4);
  }
}

// File Line: 87
// RVA: 0xE38CF0
void __fastcall hkDynamicClassNameRegistry::merge(hkDynamicClassNameRegistry *this, hkClassNameRegistry *mergeFrom)
{
  hkBaseObjectVtbl *v2; // rax
  hkDynamicClassNameRegistry *v3; // rsi
  int v4; // edi
  __int64 v5; // rbx
  char *v6; // [rsp+20h] [rbp-18h]
  int v7; // [rsp+28h] [rbp-10h]
  int v8; // [rsp+2Ch] [rbp-Ch]

  v2 = mergeFrom->vfptr;
  v3 = this;
  v6 = 0i64;
  v7 = 0;
  v8 = 2147483648;
  ((void (__fastcall *)(hkClassNameRegistry *, char **))v2[2].__first_virtual_table_function__)(mergeFrom, &v6);
  v4 = 0;
  if ( v7 > 0 )
  {
    v5 = 0i64;
    do
    {
      ((void (__fastcall *)(hkDynamicClassNameRegistry *, _QWORD, _QWORD))v3->vfptr[3].__first_virtual_table_function__)(
        v3,
        *(_QWORD *)&v6[v5],
        0i64);
      ++v4;
      v5 += 8i64;
    }
    while ( v4 < v7 );
  }
  v7 = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v6,
      8 * v8);
}

