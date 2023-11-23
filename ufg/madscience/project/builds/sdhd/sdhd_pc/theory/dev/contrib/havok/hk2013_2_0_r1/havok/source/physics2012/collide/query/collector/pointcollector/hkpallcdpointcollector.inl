// File Line: 10
// RVA: 0xB8C50
void __fastcall hkpAllCdPointCollector::reset(hkpAllCdPointCollector *this)
{
  this->m_hits.m_size = 0;
  this->m_earlyOutDistance = 3.40282e38;
}

// File Line: 21
// RVA: 0x9DBB0
void __fastcall hkpAllCdPointCollector::~hkpAllCdPointCollector(hkpAllCdPointCollector *this)
{
  hkInplaceArray<hkpRootCdPoint,8,hkContainerHeapAllocator> *p_m_hits; // rbx
  int m_capacityAndFlags; // r8d

  this->vfptr = (hkpCdPointCollectorVtbl *)&hkpAllCdPointCollector::`vftable;
  p_m_hits = &this->m_hits;
  this->m_hits.m_size = 0;
  m_capacityAndFlags = this->m_hits.m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      p_m_hits->m_data,
      m_capacityAndFlags << 6);
  p_m_hits->m_data = 0i64;
  p_m_hits->m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkpCdPointCollectorVtbl *)&hkpCdPointCollector::`vftable;
}

