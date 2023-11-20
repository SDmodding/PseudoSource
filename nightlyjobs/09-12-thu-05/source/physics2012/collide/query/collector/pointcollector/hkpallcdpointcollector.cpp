// File Line: 14
// RVA: 0xCED530
void __fastcall hkpAllCdPointCollector::addCdPoint(hkpAllCdPointCollector *this, hkpCdPoint *event)
{
  hkInplaceArray<hkpRootCdPoint,8,hkContainerHeapAllocator> *v2; // rbx
  hkpCdPoint *v3; // rdi
  signed __int64 v4; // rdx
  hkpCdBody *v5; // rcx
  hkpCdBody *i; // rax
  hkpCdBody *v7; // rcx
  hkpCdBody *j; // rax

  v2 = &this->m_hits;
  v3 = event;
  if ( this->m_hits.m_size == (this->m_hits.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 64);
  v4 = (signed __int64)&v2->m_data[(signed __int64)v2->m_size++];
  *(hkVector4f *)v4 = v3->m_contact.m_position;
  *(hkVector4f *)(v4 + 16) = v3->m_contact.m_separatingNormal;
  v5 = v3->m_cdBodyA;
  for ( i = v5->m_parent; i; i = i->m_parent )
    v5 = i;
  *(_QWORD *)(v4 + 32) = v5;
  *(_DWORD *)(v4 + 40) = v3->m_cdBodyA->m_shapeKey;
  v7 = v3->m_cdBodyB;
  for ( j = v7->m_parent; j; j = j->m_parent )
    v7 = j;
  *(_QWORD *)(v4 + 48) = v7;
  *(_DWORD *)(v4 + 56) = v3->m_cdBodyB->m_shapeKey;
}

// File Line: 26
// RVA: 0xCED500
void __fastcall hkpAllCdPointCollector::sortHits(hkpAllCdPointCollector *this)
{
  int v1; // er8

  v1 = this->m_hits.m_size;
  if ( v1 > 1 )
    hkAlgorithm::quickSortRecursive<hkpRootCdPoint,hkAlgorithm::less<hkpRootCdPoint>>(this->m_hits.m_data, 0, v1 - 1, 0);
}

