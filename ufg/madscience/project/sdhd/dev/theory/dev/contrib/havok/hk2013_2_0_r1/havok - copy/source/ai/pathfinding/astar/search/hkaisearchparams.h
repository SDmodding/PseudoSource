// File Line: 150
// RVA: 0xBBEFD0
void __fastcall hkaiSearchMemoryStorage::~hkaiSearchMemoryStorage(hkaiSearchMemoryStorage *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d

  m_capacityAndFlags = this->m_searchStateStorage.m_capacityAndFlags;
  this->m_searchStateStorage.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      this->m_searchStateStorage.m_data,
      m_capacityAndFlags & 0x3FFFFFFF);
  this->m_searchStateStorage.m_data = 0i64;
  this->m_searchStateStorage.m_capacityAndFlags = 0x80000000;
  v3 = this->m_openSetStorage.m_capacityAndFlags;
  this->m_openSetStorage.m_size = 0;
  if ( v3 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      this->m_openSetStorage.m_data,
      v3 & 0x3FFFFFFF);
  this->m_openSetStorage.m_capacityAndFlags = 0x80000000;
  this->m_openSetStorage.m_data = 0i64;
}

