// File Line: 10
// RVA: 0xB8C40
void __fastcall hkpAllCdBodyPairCollector::reset(hkpAllCdBodyPairCollector *this)
{
  this->m_hits.m_size = 0;
  this->m_earlyOut.m_bool = 0;
}

// File Line: 21
// RVA: 0x9DB30
void __fastcall hkpAllCdBodyPairCollector::~hkpAllCdBodyPairCollector(hkpAllCdBodyPairCollector *this)
{
  hkInplaceArray<hkpRootCdBodyPair,16,hkContainerHeapAllocator> *p_m_hits; // rbx
  int m_capacityAndFlags; // r8d

  this->vfptr = (hkpCdBodyPairCollectorVtbl *)&hkpAllCdBodyPairCollector::`vftable;
  p_m_hits = &this->m_hits;
  this->m_hits.m_size = 0;
  m_capacityAndFlags = this->m_hits.m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      p_m_hits->m_data,
      32 * m_capacityAndFlags);
  p_m_hits->m_data = 0i64;
  p_m_hits->m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkpCdBodyPairCollectorVtbl *)&hkpCdBodyPairCollector::`vftable;
}

