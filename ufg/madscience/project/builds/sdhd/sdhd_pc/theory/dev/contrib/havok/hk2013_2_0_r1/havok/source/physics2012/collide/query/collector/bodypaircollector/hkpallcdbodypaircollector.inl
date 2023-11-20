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
  hkpAllCdBodyPairCollector *v1; // rdi
  hkInplaceArray<hkpRootCdBodyPair,16,hkContainerHeapAllocator> *v2; // rbx
  int v3; // er8

  v1 = this;
  this->vfptr = (hkpCdBodyPairCollectorVtbl *)&hkpAllCdBodyPairCollector::`vftable;
  v2 = &this->m_hits;
  this->m_hits.m_size = 0;
  v3 = this->m_hits.m_capacityAndFlags;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_data,
      32 * v3);
  v2->m_data = 0i64;
  v2->m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkpCdBodyPairCollectorVtbl *)&hkpCdBodyPairCollector::`vftable;
}

