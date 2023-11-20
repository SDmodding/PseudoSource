// File Line: 14
// RVA: 0xCF3430
void __fastcall hkpAllCdBodyPairCollector::addCdBodyPair(hkpAllCdBodyPairCollector *this, hkpCdBody *bodyA, hkpCdBody *bodyB)
{
  hkInplaceArray<hkpRootCdBodyPair,16,hkContainerHeapAllocator> *v3; // rbx
  hkpCdBody *v4; // rdi
  hkpCdBody *v5; // rsi
  hkpCdBody *v6; // rcx
  signed __int64 v7; // rdx
  hkpCdBody *i; // rax
  hkpCdBody *v9; // rcx
  hkpCdBody *j; // rax

  v3 = &this->m_hits;
  v4 = bodyB;
  v5 = bodyA;
  if ( this->m_hits.m_size == (this->m_hits.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 32);
  v6 = v5;
  v7 = (signed __int64)&v3->m_data[v3->m_size++];
  for ( i = v5->m_parent; i; i = i->m_parent )
    v6 = i;
  *(_QWORD *)v7 = v6;
  v9 = v4;
  *(_DWORD *)(v7 + 8) = v5->m_shapeKey;
  for ( j = v4->m_parent; j; j = j->m_parent )
    v9 = j;
  *(_QWORD *)(v7 + 16) = v9;
  *(_DWORD *)(v7 + 24) = v4->m_shapeKey;
}

