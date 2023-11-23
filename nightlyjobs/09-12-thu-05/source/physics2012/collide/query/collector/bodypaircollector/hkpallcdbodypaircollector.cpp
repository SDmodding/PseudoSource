// File Line: 14
// RVA: 0xCF3430
void __fastcall hkpAllCdBodyPairCollector::addCdBodyPair(
        hkpAllCdBodyPairCollector *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB)
{
  hkInplaceArray<hkpRootCdBodyPair,16,hkContainerHeapAllocator> *p_m_hits; // rbx
  hkpCdBody *v6; // rcx
  __int64 v7; // rdx
  hkpCdBody *i; // rax
  hkpCdBody *v9; // rcx
  hkpCdBody *j; // rax

  p_m_hits = &this->m_hits;
  if ( this->m_hits.m_size == (this->m_hits.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_hits->m_data, 32);
  v6 = bodyA;
  v7 = (__int64)&p_m_hits->m_data[p_m_hits->m_size++];
  for ( i = bodyA->m_parent; i; i = i->m_parent )
    v6 = i;
  *(_QWORD *)v7 = v6;
  v9 = bodyB;
  *(_DWORD *)(v7 + 8) = bodyA->m_shapeKey;
  for ( j = bodyB->m_parent; j; j = j->m_parent )
    v9 = j;
  *(_QWORD *)(v7 + 16) = v9;
  *(_DWORD *)(v7 + 24) = bodyB->m_shapeKey;
}

