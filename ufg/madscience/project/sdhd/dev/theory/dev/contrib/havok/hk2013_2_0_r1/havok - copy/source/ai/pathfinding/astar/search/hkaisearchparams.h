// File Line: 150
// RVA: 0xBBEFD0
void __fastcall hkaiSearchMemoryStorage::~hkaiSearchMemoryStorage(hkaiSearchMemoryStorage *this)
{
  int v1; // er8
  hkaiSearchMemoryStorage *v2; // rbx
  int v3; // er8

  v1 = this->m_searchStateStorage.m_capacityAndFlags;
  v2 = this;
  this->m_searchStateStorage.m_size = 0;
  if ( v1 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      this->m_searchStateStorage.m_data,
      v1 & 0x3FFFFFFF);
  v2->m_searchStateStorage.m_data = 0i64;
  v2->m_searchStateStorage.m_capacityAndFlags = 2147483648;
  v3 = v2->m_openSetStorage.m_capacityAndFlags;
  v2->m_openSetStorage.m_size = 0;
  if ( v3 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v2->m_openSetStorage.m_data,
      v3 & 0x3FFFFFFF);
  v2->m_openSetStorage.m_capacityAndFlags = 2147483648;
  v2->m_openSetStorage.m_data = 0i64;
}

