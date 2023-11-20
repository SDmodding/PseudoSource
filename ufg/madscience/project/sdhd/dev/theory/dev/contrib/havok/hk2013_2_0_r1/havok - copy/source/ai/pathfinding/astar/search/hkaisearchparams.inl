// File Line: 111
// RVA: 0xC0EA80
void __fastcall hkaiSearchMemoryLocalStorage::hkaiSearchMemoryLocalStorage(hkaiSearchMemoryLocalStorage *this, hkaiSearchParameters::BufferSizes *bufferSizes)
{
  int v2; // edi
  hkaiSearchParameters::BufferSizes *v3; // rsi
  hkaiSearchMemoryLocalStorage *v4; // rbx
  hkLifoAllocator *v5; // rax
  hkLifoAllocator *v6; // rcx
  char *v7; // rax
  int v8; // er8
  char *v9; // rdx
  int v10; // edi
  hkLifoAllocator *v11; // rax
  char *v12; // rcx
  int v13; // er8
  char *v14; // rdx

  v2 = bufferSizes->m_maxOpenSetSizeBytes;
  v3 = bufferSizes;
  v4 = this;
  this->m_openSetStorage.m_capacityAndFlags = 2147483648;
  this->m_openSetStorage.m_data = 0i64;
  this->m_openSetStorage.m_size = 0;
  this->m_openSetStorage.m_initialCapacity = v2;
  if ( v2 )
  {
    v5 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = v5;
    v7 = (char *)v5->m_cur;
    v8 = (v2 + 127) & 0xFFFFFF80;
    v9 = &v7[v8];
    if ( v8 > v6->m_slabSize || v9 > v6->m_end )
      v7 = (char *)hkLifoAllocator::allocateFromNewSlab(v6, v8);
    else
      v6->m_cur = v9;
  }
  else
  {
    v7 = 0i64;
  }
  v4->m_openSetStorage.m_data = v7;
  v4->m_openSetStorage.m_localMemory = v7;
  v4->m_openSetStorage.m_capacityAndFlags = v2 | 0x80000000;
  v10 = v3->m_maxSearchStateSizeBytes;
  v4->m_searchStateStorage.m_data = 0i64;
  v4->m_searchStateStorage.m_size = 0;
  v4->m_searchStateStorage.m_capacityAndFlags = 2147483648;
  v4->m_searchStateStorage.m_initialCapacity = v10;
  if ( v10 )
  {
    v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v12 = (char *)v11->m_cur;
    v13 = (v10 + 127) & 0xFFFFFF80;
    v14 = &v12[v13];
    if ( v13 > v11->m_slabSize || v14 > v11->m_end )
      v12 = (char *)hkLifoAllocator::allocateFromNewSlab(v11, v13);
    else
      v11->m_cur = v14;
  }
  else
  {
    v12 = 0i64;
  }
  v4->m_searchStateStorage.m_data = v12;
  v4->m_searchStateStorage.m_localMemory = v12;
  v4->m_searchStateStorage.m_capacityAndFlags = v10 | 0x80000000;
  v4->m_openSetBuffer = v4->m_openSetStorage.m_data;
  v4->m_openSetSize = v4->m_openSetStorage.m_capacityAndFlags & 0x3FFFFFFF;
  v4->m_searchStateBuffer = v4->m_searchStateStorage.m_data;
  v4->m_searchStateSize = v4->m_searchStateStorage.m_capacityAndFlags & 0x3FFFFFFF;
}

// File Line: 132
// RVA: 0xBBF0F0
void __fastcall hkaiSearchMemoryStorage::_setupArray(hkArray<char,hkContainerTempAllocator> *array, char *buffer, int size)
{
  int v3; // ebx
  hkArray<char,hkContainerTempAllocator> *v4; // rdi
  int v5; // eax
  int v6; // eax
  int v7; // er9
  hkResult result; // [rsp+48h] [rbp+10h]

  v3 = size;
  v4 = array;
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
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, array, v7, 1);
    }
    v4->m_size = v3;
  }
}

