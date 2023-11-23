// File Line: 14
// RVA: 0xCED530
void __fastcall hkpAllCdPointCollector::addCdPoint(hkpAllCdPointCollector *this, hkpCdPoint *event)
{
  hkInplaceArray<hkpRootCdPoint,8,hkContainerHeapAllocator> *p_m_hits; // rbx
  hkVector4f *p_m_position; // rdx
  hkpCdBody *m_cdBodyA; // rcx
  hkpCdBody *i; // rax
  hkpCdBody *m_cdBodyB; // rcx
  hkpCdBody *j; // rax

  p_m_hits = &this->m_hits;
  if ( this->m_hits.m_size == (this->m_hits.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_hits->m_data, 64);
  p_m_position = &p_m_hits->m_data[(__int64)p_m_hits->m_size++].m_contact.m_position;
  *p_m_position = event->m_contact.m_position;
  p_m_position[1] = event->m_contact.m_separatingNormal;
  m_cdBodyA = event->m_cdBodyA;
  for ( i = m_cdBodyA->m_parent; i; i = i->m_parent )
    m_cdBodyA = i;
  p_m_position[2].m_quad.m128_u64[0] = (unsigned __int64)m_cdBodyA;
  p_m_position[2].m_quad.m128_i32[2] = event->m_cdBodyA->m_shapeKey;
  m_cdBodyB = event->m_cdBodyB;
  for ( j = m_cdBodyB->m_parent; j; j = j->m_parent )
    m_cdBodyB = j;
  p_m_position[3].m_quad.m128_u64[0] = (unsigned __int64)m_cdBodyB;
  p_m_position[3].m_quad.m128_i32[2] = event->m_cdBodyB->m_shapeKey;
}

// File Line: 26
// RVA: 0xCED500
void __fastcall hkpAllCdPointCollector::sortHits(hkpAllCdPointCollector *this)
{
  int m_size; // r8d

  m_size = this->m_hits.m_size;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkpRootCdPoint,hkAlgorithm::less<hkpRootCdPoint>>(
      this->m_hits.m_data,
      0,
      m_size - 1,
      0);
}

