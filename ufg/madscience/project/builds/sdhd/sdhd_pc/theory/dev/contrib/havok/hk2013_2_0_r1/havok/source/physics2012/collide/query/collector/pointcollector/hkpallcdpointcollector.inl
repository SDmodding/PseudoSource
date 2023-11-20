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
  hkpAllCdPointCollector *v1; // rdi
  hkInplaceArray<hkpRootCdPoint,8,hkContainerHeapAllocator> *v2; // rbx
  int v3; // er8

  v1 = this;
  this->vfptr = (hkpCdPointCollectorVtbl *)&hkpAllCdPointCollector::`vftable;
  v2 = &this->m_hits;
  this->m_hits.m_size = 0;
  v3 = this->m_hits.m_capacityAndFlags;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_data,
      v3 << 6);
  v2->m_data = 0i64;
  v2->m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkpCdPointCollectorVtbl *)&hkpCdPointCollector::`vftable;
}

