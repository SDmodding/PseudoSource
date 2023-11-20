// File Line: 13
// RVA: 0xE5CF20
void __fastcall hkRelocationInfo::~hkRelocationInfo(hkRelocationInfo *this)
{
  hkStorageStringMap<int,hkContainerHeapAllocator> *v1; // rdi
  hkRelocationInfo *v2; // rbx
  _QWORD **v3; // rax
  int v4; // er8
  int v5; // er8
  int v6; // er8
  int v7; // er8

  v1 = this->m_pool;
  v2 = this;
  if ( v1 )
  {
    hkStorageStringMap<hkTrackerLayoutHandler *,hkContainerHeapAllocator>::clear(this->m_pool);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v1->m_map);
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkStorageStringMap<int,hkContainerHeapAllocator> *, signed __int64))(*v3[11] + 16i64))(
      v3[11],
      v1,
      24i64);
  }
  v4 = v2->m_imports.m_capacityAndFlags;
  v2->m_imports.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_imports.m_data,
      16 * v4);
  v2->m_imports.m_data = 0i64;
  v2->m_imports.m_capacityAndFlags = 2147483648;
  v5 = v2->m_finish.m_capacityAndFlags;
  v2->m_finish.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_finish.m_data,
      16 * v5);
  v2->m_finish.m_data = 0i64;
  v2->m_finish.m_capacityAndFlags = 2147483648;
  v6 = v2->m_global.m_capacityAndFlags;
  v2->m_global.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_global.m_data,
      32 * v6);
  v2->m_global.m_data = 0i64;
  v2->m_global.m_capacityAndFlags = 2147483648;
  v7 = v2->m_local.m_capacityAndFlags;
  v2->m_local.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_local.m_data,
      8 * v7);
  v2->m_local.m_capacityAndFlags = 2147483648;
  v2->m_local.m_data = 0i64;
}

// File Line: 18
// RVA: 0xE5D180
void __fastcall hkRelocationInfo::applyLocalAndGlobal(hkRelocationInfo *this, void *buffer)
{
  int v2; // er9
  char *v3; // r10
  hkRelocationInfo *v4; // r8
  int v5; // er11
  __int64 v6; // rcx
  __int64 v7; // rdx

  v2 = 0;
  v3 = (char *)buffer;
  v4 = this;
  v5 = 0;
  if ( this->m_local.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      ++v5;
      ++v6;
      *(_QWORD *)((char *)buffer + v4->m_local.m_data[v6 - 1].m_fromOffset) = (char *)buffer
                                                                            + *((signed int *)&v4->m_local.m_data[v6] - 1);
    }
    while ( v5 < v4->m_local.m_size );
  }
  if ( v4->m_global.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      ++v2;
      ++v7;
      *(_QWORD *)&v3[v4->m_global.m_data[v7 - 1].m_fromOffset] = *((_QWORD *)&v4->m_global.m_data[v7] - 3);
    }
    while ( v2 < v4->m_global.m_size );
  }
}

// File Line: 37
// RVA: 0xE5D060
void __fastcall hkRelocationInfo::addImport(hkRelocationInfo *this, int off, const char *name)
{
  const char *v3; // rsi
  int v4; // er14
  hkRelocationInfo *v5; // rdi
  _QWORD **v6; // rax
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *v7; // rbx
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v8; // rbx
  Dummy *v9; // rbp
  char *v10; // rsi
  hkRelocationInfo::Import *v11; // rcx
  __int64 v12; // [rsp+20h] [rbp-28h]
  hkBool result; // [rsp+58h] [rbp+10h]

  v3 = name;
  v4 = off;
  v5 = this;
  if ( !this->m_pool )
  {
    v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v7 = (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(
                                                                              v6[11],
                                                                              24i64);
    if ( v7 )
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
        v7,
        0);
    else
      v7 = 0i64;
    v5->m_pool = (hkStorageStringMap<int,hkContainerHeapAllocator> *)v7;
  }
  v8 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v5->m_pool;
  v9 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v5->m_pool,
         (unsigned __int64)v3);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v8, &result, v9);
  if ( result.m_bool )
  {
    v10 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(
                    (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v8,
                    v9);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::setValue(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v8,
      v9,
      0i64);
  }
  else
  {
    v10 = hkString::strDup(v3, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v8,
      (unsigned __int64)v10,
      0i64);
  }
  LODWORD(v12) = v4;
  if ( v5->m_imports.m_size == (v5->m_imports.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v5->m_imports, 16);
  v11 = &v5->m_imports.m_data[v5->m_imports.m_size];
  *(_QWORD *)&v11->m_fromOffset = v12;
  v11->m_identifier = v10;
  ++v5->m_imports.m_size;
}

