// File Line: 14
// RVA: 0xD08E90
void __fastcall hkpAllRayHitCollector::addRayHit(
        hkpAllRayHitCollector *this,
        hkpCdBody *cdBody,
        hkpShapeRayCastCollectorOutput *hitInfo)
{
  hkInplaceArray<hkpWorldRayCastOutput,8,hkContainerHeapAllocator> *p_m_hits; // rbx
  __int64 v6; // rcx
  __int64 m_size; // rcx
  hkVector4f *p_m_normal; // rdi
  hkpCdBody *m_parent; // rax
  hkpCdBody *v10; // rcx

  p_m_hits = &this->m_hits;
  if ( this->m_hits.m_size == (this->m_hits.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_hits->m_data, 96);
  v6 = (__int64)&p_m_hits->m_data[p_m_hits->m_size];
  if ( v6 )
  {
    *(_DWORD *)(v6 + 16) = 1065353216;
    *(_DWORD *)(v6 + 20) = -1;
    *(_DWORD *)(v6 + 64) = 0;
    *(_DWORD *)(v6 + 32) = -1;
    *(_QWORD *)(v6 + 80) = 0i64;
  }
  m_size = p_m_hits->m_size;
  p_m_hits->m_size = m_size + 1;
  p_m_normal = &p_m_hits->m_data[m_size].m_normal;
  *p_m_normal = hitInfo->m_normal;
  p_m_normal[1].m_quad.m128_i32[0] = LODWORD(hitInfo->m_hitFraction);
  p_m_normal[1].m_quad.m128_i32[1] = hitInfo->m_extraInfo;
  p_m_normal[1].m_quad.m128_i32[2] = hitInfo->m_pad[0];
  p_m_normal[1].m_quad.m128_i32[3] = hitInfo->m_pad[1];
  hkpRayHitCollector::shapeKeysFromCdBody((unsigned int *)&p_m_normal[2], 8, cdBody);
  m_parent = cdBody->m_parent;
  if ( m_parent )
  {
    do
    {
      v10 = m_parent;
      m_parent = m_parent->m_parent;
    }
    while ( m_parent );
    p_m_normal[5].m_quad.m128_u64[0] = (unsigned __int64)v10;
  }
  else
  {
    p_m_normal[5].m_quad.m128_u64[0] = (unsigned __int64)cdBody;
  }
}

// File Line: 23
// RVA: 0xD08E60
void __fastcall hkpAllRayHitCollector::sortHits(hkpAllRayHitCollector *this)
{
  int m_size; // r8d

  m_size = this->m_hits.m_size;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkpWorldRayCastOutput,hkAlgorithm::less<hkpWorldRayCastOutput>>(
      this->m_hits.m_data,
      0,
      m_size - 1,
      0);
}

