// File Line: 105
// RVA: 0xC0CF70
void __fastcall hkaiPath::addPoint(
        hkaiPath *this,
        hkVector4f *p,
        hkVector4f *n,
        int sectionId,
        unsigned int userEdgeData,
        hkFlags<enum hkaiPath::PathPointBits,unsigned char> pointFlags)
{
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *p_m_points; // rbx
  __int64 m_size; // rcx
  __int64 v11; // rdx

  p_m_points = &this->m_points;
  if ( this->m_points.m_size == (this->m_points.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_points, 48);
  m_size = p_m_points->m_size;
  p_m_points->m_size = m_size + 1;
  v11 = (__int64)&p_m_points->m_data[m_size];
  *(hkVector4f *)v11 = (hkVector4f)p->m_quad;
  *(hkVector4f *)(v11 + 16) = (hkVector4f)n->m_quad;
  *(_DWORD *)(v11 + 36) = sectionId;
  *(_DWORD *)(v11 + 32) = userEdgeData;
  *(hkFlags<enum hkaiPath::PathPointBits,unsigned char> *)(v11 + 40) = pointFlags;
}

