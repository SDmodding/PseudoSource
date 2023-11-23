// File Line: 31
// RVA: 0xD98630
__int64 __fastcall hkpDynamicsCpIdMgr::newId(hkpDynamicsCpIdMgr *this, char value)
{
  int m_size; // ecx
  unsigned int v5; // r8d
  __int64 v6; // rax
  char *m_data; // r9
  __int64 result; // rax

  m_size = this->m_values.m_size;
  v5 = m_size - 1;
  v6 = m_size - 1;
  if ( m_size - 1 < 0 )
  {
LABEL_5:
    if ( m_size == (this->m_values.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_values.m_data, 1);
    this->m_values.m_data[this->m_values.m_size++] = value;
    return (unsigned int)(this->m_values.m_size - 1);
  }
  else
  {
    m_data = this->m_values.m_data;
    while ( m_data[v6] != -1 )
    {
      --v5;
      if ( --v6 < 0 )
        goto LABEL_5;
    }
    result = v5;
    m_data[v5] = value;
  }
  return result;
}

// File Line: 88
// RVA: 0xD84250
void __fastcall hkpDynamicsCpIdMgr::getAllUsedIds(
        hkpDynamicsCpIdMgr *this,
        hkArray<unsigned short,hkContainerHeapAllocator> *ids)
{
  int i; // ebx

  for ( i = 0; i < this->m_values.m_size; ++i )
  {
    if ( this->m_values.m_data[i] != -1 )
    {
      if ( ids->m_size == (ids->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&ids->m_data, 2);
      ids->m_data[ids->m_size++] = i;
    }
  }
}

