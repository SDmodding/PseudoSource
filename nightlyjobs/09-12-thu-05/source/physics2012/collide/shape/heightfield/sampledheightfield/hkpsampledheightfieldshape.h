// File Line: 246
// RVA: 0xCF9180
void __fastcall hkpSampledHeightFieldShape::CoarseMinMaxLevel::CoarseMinMaxLevel(hkpSampledHeightFieldShape::CoarseMinMaxLevel *this, hkpSampledHeightFieldShape::CoarseMinMaxLevel *l)
{
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *v2; // rdi
  hkpSampledHeightFieldShape::CoarseMinMaxLevel *v3; // rbx
  __int64 v4; // rcx
  hkVector4f *v5; // rax
  __int64 v6; // rdx
  char *v7; // r8
  hkVector4f v8; // xmm0
  int v9; // [rsp+30h] [rbp+8h]

  this->m_minMaxData.m_capacityAndFlags = 2147483648;
  v2 = l;
  this->m_minMaxData.m_data = 0i64;
  this->m_minMaxData.m_size = 0;
  this->m_xRes = l->m_xRes;
  v3 = this;
  this->m_zRes = l->m_zRes;
  if ( (this->m_minMaxData.m_capacityAndFlags & 0x3FFFFFFF) < l->m_minMaxData.m_size )
  {
    if ( this->m_minMaxData.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        this->m_minMaxData.m_data,
        16 * this->m_minMaxData.m_capacityAndFlags);
    v9 = 16 * v2->m_minMaxData.m_size;
    v3->m_minMaxData.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                              &v9);
    v3->m_minMaxData.m_capacityAndFlags = v9 / 16;
  }
  v4 = v2->m_minMaxData.m_size;
  v5 = v3->m_minMaxData.m_data;
  v3->m_minMaxData.m_size = v4;
  v6 = v4;
  if ( (signed int)v4 > 0 )
  {
    v7 = (char *)((char *)v2->m_minMaxData.m_data - (char *)v5);
    do
    {
      v8.m_quad = *(__m128 *)((char *)v5 + (_QWORD)v7);
      ++v5;
      v5[-1] = (hkVector4f)v8.m_quad;
      --v6;
    }
    while ( v6 );
  }
}

