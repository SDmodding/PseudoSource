// File Line: 13
// RVA: 0xE5CF20
void __fastcall hkRelocationInfo::~hkRelocationInfo(hkRelocationInfo *this)
{
  hkStorageStringMap<int,hkContainerHeapAllocator> *m_pool; // rdi
  _QWORD **Value; // rax
  int m_capacityAndFlags; // r8d
  int v5; // r8d
  int v6; // r8d
  int v7; // r8d

  m_pool = this->m_pool;
  if ( m_pool )
  {
    hkStorageStringMap<hkTrackerLayoutHandler *,hkContainerHeapAllocator>::clear(this->m_pool);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&m_pool->m_map);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkStorageStringMap<int,hkContainerHeapAllocator> *, __int64))(*Value[11] + 16i64))(
      Value[11],
      m_pool,
      24i64);
  }
  m_capacityAndFlags = this->m_imports.m_capacityAndFlags;
  this->m_imports.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_imports.m_data,
      16 * m_capacityAndFlags);
  this->m_imports.m_data = 0i64;
  this->m_imports.m_capacityAndFlags = 0x80000000;
  v5 = this->m_finish.m_capacityAndFlags;
  this->m_finish.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_finish.m_data, 16 * v5);
  this->m_finish.m_data = 0i64;
  this->m_finish.m_capacityAndFlags = 0x80000000;
  v6 = this->m_global.m_capacityAndFlags;
  this->m_global.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_global.m_data, 32 * v6);
  this->m_global.m_data = 0i64;
  this->m_global.m_capacityAndFlags = 0x80000000;
  v7 = this->m_local.m_capacityAndFlags;
  this->m_local.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_local.m_data, 8 * v7);
  this->m_local.m_capacityAndFlags = 0x80000000;
  this->m_local.m_data = 0i64;
}

// File Line: 18
// RVA: 0xE5D180
void __fastcall hkRelocationInfo::applyLocalAndGlobal(hkRelocationInfo *this, char *buffer)
{
  int v2; // r9d
  int v5; // r11d
  __int64 v6; // rcx
  __int64 v7; // rdx

  v2 = 0;
  v5 = 0;
  if ( this->m_local.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      ++v5;
      ++v6;
      *(_QWORD *)&buffer[this->m_local.m_data[v6 - 1].m_fromOffset] = &buffer[this->m_local.m_data[v6 - 1].m_toOffset];
    }
    while ( v5 < this->m_local.m_size );
  }
  if ( this->m_global.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      ++v2;
      ++v7;
      *(_QWORD *)&buffer[this->m_global.m_data[v7 - 1].m_fromOffset] = this->m_global.m_data[v7 - 1].m_toAddress;
    }
    while ( v2 < this->m_global.m_size );
  }
}

// File Line: 37
// RVA: 0xE5D060
void __fastcall hkRelocationInfo::addImport(hkRelocationInfo *this, int off, char *name)
{
  _QWORD **Value; // rax
  hkStorageStringMap<int,hkContainerHeapAllocator> *v7; // rbx
  hkStorageStringMap<int,hkContainerHeapAllocator> *m_pool; // rbx
  Dummy *Key; // rbp
  char *v10; // rsi
  hkRelocationInfo::Import *v11; // rcx
  __int64 v12; // [rsp+20h] [rbp-28h]
  hkBool result; // [rsp+58h] [rbp+10h] BYREF

  if ( !this->m_pool )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v7 = (hkStorageStringMap<int,hkContainerHeapAllocator> *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                               Value[11],
                                                               24i64);
    if ( v7 )
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
        &v7->m_map,
        0);
    else
      v7 = 0i64;
    this->m_pool = v7;
  }
  m_pool = this->m_pool;
  Key = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
          (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)m_pool,
          name);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)m_pool,
    &result,
    Key);
  if ( result.m_bool )
  {
    v10 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(&m_pool->m_map, Key);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::setValue(&m_pool->m_map, Key, 0i64);
  }
  else
  {
    v10 = hkString::strDup(name, &hkContainerHeapAllocator::s_alloc);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&m_pool->m_map, v10, 0i64);
  }
  LODWORD(v12) = off;
  if ( this->m_imports.m_size == (this->m_imports.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_imports.m_data, 16);
  v11 = &this->m_imports.m_data[this->m_imports.m_size];
  *(_QWORD *)&v11->m_fromOffset = v12;
  v11->m_identifier = v10;
  ++this->m_imports.m_size;
}

