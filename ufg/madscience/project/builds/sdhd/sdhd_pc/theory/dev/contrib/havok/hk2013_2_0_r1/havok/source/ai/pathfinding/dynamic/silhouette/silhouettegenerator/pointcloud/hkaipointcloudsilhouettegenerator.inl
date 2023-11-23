// File Line: 50
// RVA: 0xF59B0
void __fastcall hkaiPointCloudSilhouetteGenerator::setLocalPoints(
        hkaiPointCloudSilhouetteGenerator *this,
        hkArrayBase<hkVector4f> *points)
{
  __int64 m_size; // rcx
  hkVector4f *m_data; // rax
  __int64 v6; // rdx
  char *v7; // r8
  hkVector4f v8; // xmm0
  int v9; // [rsp+30h] [rbp+8h] BYREF

  if ( (this->m_localPoints.m_capacityAndFlags & 0x3FFFFFFF) < points->m_size )
  {
    if ( this->m_localPoints.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_localPoints.m_data,
        16 * this->m_localPoints.m_capacityAndFlags);
    v9 = 16 * points->m_size;
    this->m_localPoints.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                 &hkContainerHeapAllocator::s_alloc,
                                                 &v9);
    this->m_localPoints.m_capacityAndFlags = v9 / 16;
  }
  m_size = points->m_size;
  m_data = this->m_localPoints.m_data;
  this->m_localPoints.m_size = m_size;
  v6 = m_size;
  if ( (int)m_size > 0 )
  {
    v7 = (char *)((char *)points->m_data - (char *)m_data);
    do
    {
      v8.m_quad = *(__m128 *)((char *)m_data++ + (_QWORD)v7);
      m_data[-1] = (hkVector4f)v8.m_quad;
      --v6;
    }
    while ( v6 );
  }
  this->m_silhouetteSizes.m_size = 0;
  this->m_localPointsChanged.m_bool = 1;
  hkAabbUtil::calcAabb(this->m_localPoints.m_data, this->m_localPoints.m_size, &this->m_localAabb);
  ((void (__fastcall *)(hkaiPointCloudSilhouetteGenerator *))this->vfptr[2].__vecDelDtor)(this);
}

