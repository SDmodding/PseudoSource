// File Line: 111
// RVA: 0xC0EA80
void __fastcall hkaiSearchMemoryLocalStorage::hkaiSearchMemoryLocalStorage(
        hkaiSearchMemoryLocalStorage *this,
        hkaiSearchParameters::BufferSizes *bufferSizes)
{
  int m_maxOpenSetSizeBytes; // edi
  hkLifoAllocator *Value; // rcx
  char *m_cur; // rax
  int v7; // r8d
  char *v8; // rdx
  int m_maxSearchStateSizeBytes; // edi
  hkLifoAllocator *v10; // rax
  char *v11; // rcx
  int v12; // r8d
  char *v13; // rdx

  m_maxOpenSetSizeBytes = bufferSizes->m_maxOpenSetSizeBytes;
  this->m_openSetStorage.m_capacityAndFlags = 0x80000000;
  this->m_openSetStorage.m_data = 0i64;
  this->m_openSetStorage.m_size = 0;
  this->m_openSetStorage.m_initialCapacity = m_maxOpenSetSizeBytes;
  if ( m_maxOpenSetSizeBytes )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)Value->m_cur;
    v7 = (m_maxOpenSetSizeBytes + 127) & 0xFFFFFF80;
    v8 = &m_cur[v7];
    if ( v7 > Value->m_slabSize || v8 > Value->m_end )
      m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v7);
    else
      Value->m_cur = v8;
  }
  else
  {
    m_cur = 0i64;
  }
  this->m_openSetStorage.m_data = m_cur;
  this->m_openSetStorage.m_localMemory = m_cur;
  this->m_openSetStorage.m_capacityAndFlags = m_maxOpenSetSizeBytes | 0x80000000;
  m_maxSearchStateSizeBytes = bufferSizes->m_maxSearchStateSizeBytes;
  this->m_searchStateStorage.m_data = 0i64;
  this->m_searchStateStorage.m_size = 0;
  this->m_searchStateStorage.m_capacityAndFlags = 0x80000000;
  this->m_searchStateStorage.m_initialCapacity = m_maxSearchStateSizeBytes;
  if ( m_maxSearchStateSizeBytes )
  {
    v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (char *)v10->m_cur;
    v12 = (m_maxSearchStateSizeBytes + 127) & 0xFFFFFF80;
    v13 = &v11[v12];
    if ( v12 > v10->m_slabSize || v13 > v10->m_end )
      v11 = (char *)hkLifoAllocator::allocateFromNewSlab(v10, v12);
    else
      v10->m_cur = v13;
  }
  else
  {
    v11 = 0i64;
  }
  this->m_searchStateStorage.m_data = v11;
  this->m_searchStateStorage.m_localMemory = v11;
  this->m_searchStateStorage.m_capacityAndFlags = m_maxSearchStateSizeBytes | 0x80000000;
  this->m_openSetBuffer = this->m_openSetStorage.m_data;
  this->m_openSetSize = this->m_openSetStorage.m_capacityAndFlags & 0x3FFFFFFF;
  this->m_searchStateBuffer = this->m_searchStateStorage.m_data;
  this->m_searchStateSize = this->m_searchStateStorage.m_capacityAndFlags & 0x3FFFFFFF;
}

// File Line: 132
// RVA: 0xBBF0F0
void __fastcall hkaiSearchMemoryStorage::_setupArray(
        hkArray<char,hkContainerTempAllocator> *array,
        char *buffer,
        int size)
{
  int v5; // eax
  int v6; // eax
  int v7; // r9d
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  if ( buffer )
  {
    array->m_data = buffer;
    array->m_size = 0;
    array->m_capacityAndFlags = size | 0x80000000;
  }
  else
  {
    v5 = array->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v5 < size )
    {
      v6 = 2 * v5;
      v7 = size;
      if ( size < v6 )
        v7 = v6;
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, array, v7, 1);
    }
    array->m_size = size;
  }
}

