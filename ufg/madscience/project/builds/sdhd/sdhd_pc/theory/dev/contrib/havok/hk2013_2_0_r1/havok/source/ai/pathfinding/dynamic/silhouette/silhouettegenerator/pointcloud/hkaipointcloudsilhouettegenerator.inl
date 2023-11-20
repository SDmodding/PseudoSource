// File Line: 50
// RVA: 0xF59B0
void __fastcall hkaiPointCloudSilhouetteGenerator::setLocalPoints(hkaiPointCloudSilhouetteGenerator *this, hkArrayBase<hkVector4f> *points)
{
  hkArrayBase<hkVector4f> *v2; // rdi
  hkaiPointCloudSilhouetteGenerator *v3; // rbx
  __int64 v4; // rcx
  hkVector4f *v5; // rax
  __int64 v6; // rdx
  char *v7; // r8
  hkVector4f v8; // xmm0
  int v9; // [rsp+30h] [rbp+8h]

  v2 = points;
  v3 = this;
  if ( (this->m_localPoints.m_capacityAndFlags & 0x3FFFFFFF) < points->m_size )
  {
    if ( this->m_localPoints.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        this->m_localPoints.m_data,
        16 * this->m_localPoints.m_capacityAndFlags);
    v9 = 16 * v2->m_size;
    v3->m_localPoints.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                               (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                               &v9);
    v3->m_localPoints.m_capacityAndFlags = v9 / 16;
  }
  v4 = v2->m_size;
  v5 = v3->m_localPoints.m_data;
  v3->m_localPoints.m_size = v4;
  v6 = v4;
  if ( (signed int)v4 > 0 )
  {
    v7 = (char *)((char *)v2->m_data - (char *)v5);
    do
    {
      v8.m_quad = *(__m128 *)((char *)v5 + (_QWORD)v7);
      ++v5;
      v5[-1] = (hkVector4f)v8.m_quad;
      --v6;
    }
    while ( v6 );
  }
  v3->m_silhouetteSizes.m_size = 0;
  v3->m_localPointsChanged.m_bool = 1;
  hkAabbUtil::calcAabb(v3->m_localPoints.m_data, v3->m_localPoints.m_size, &v3->m_localAabb);
  ((void (__fastcall *)(hkaiPointCloudSilhouetteGenerator *))v3->vfptr[2].__vecDelDtor)(v3);
}

