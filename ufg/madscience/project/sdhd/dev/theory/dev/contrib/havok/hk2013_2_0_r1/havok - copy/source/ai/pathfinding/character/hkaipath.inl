// File Line: 105
// RVA: 0xC0CF70
void __fastcall hkaiPath::addPoint(hkaiPath *this, hkVector4f *p, hkVector4f *n, int sectionId, unsigned int userEdgeData, hkFlags<enum hkaiPath::PathPointBits,unsigned char> pointFlags)
{
  signed int *v6; // rbx
  int v7; // edi
  hkVector4f *v8; // rsi
  hkVector4f *v9; // rbp
  __int64 v10; // rcx
  signed __int64 v11; // rdx

  v6 = (signed int *)&this->m_points;
  v7 = sectionId;
  v8 = n;
  v9 = p;
  if ( this->m_points.m_size == (this->m_points.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 48);
  v10 = v6[2];
  v6[2] = v10 + 1;
  v11 = *(_QWORD *)v6 + 48 * v10;
  *(hkVector4f *)v11 = (hkVector4f)v9->m_quad;
  *(hkVector4f *)(v11 + 16) = (hkVector4f)v8->m_quad;
  *(_DWORD *)(v11 + 36) = v7;
  *(_DWORD *)(v11 + 32) = userEdgeData;
  *(hkFlags<enum hkaiPath::PathPointBits,unsigned char> *)(v11 + 40) = pointFlags;
}

