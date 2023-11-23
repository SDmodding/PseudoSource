// File Line: 246
// RVA: 0xCF9180
void __fastcall hkpSampledHeightFieldShape::CoarseMinMaxLevel::CoarseMinMaxLevel(
        hkpSampledHeightFieldShape::CoarseMinMaxLevel *this,
        hkpSampledHeightFieldShape::CoarseMinMaxLevel *l)
{
  __int64 m_size; // rcx
  hkVector4f *m_data; // rax
  __int64 v6; // rdx
  char *v7; // r8
  hkVector4f v8; // xmm0
  int v9; // [rsp+30h] [rbp+8h] BYREF

  this->m_minMaxData.m_capacityAndFlags = 0x80000000;
  this->m_minMaxData.m_data = 0i64;
  this->m_minMaxData.m_size = 0;
  this->m_xRes = l->m_xRes;
  this->m_zRes = l->m_zRes;
  if ( (this->m_minMaxData.m_capacityAndFlags & 0x3FFFFFFF) < l->m_minMaxData.m_size )
  {
    if ( this->m_minMaxData.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_minMaxData.m_data,
        16 * this->m_minMaxData.m_capacityAndFlags);
    v9 = 16 * l->m_minMaxData.m_size;
    this->m_minMaxData.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                &hkContainerHeapAllocator::s_alloc,
                                                &v9);
    this->m_minMaxData.m_capacityAndFlags = v9 / 16;
  }
  m_size = l->m_minMaxData.m_size;
  m_data = this->m_minMaxData.m_data;
  this->m_minMaxData.m_size = m_size;
  v6 = m_size;
  if ( (int)m_size > 0 )
  {
    v7 = (char *)((char *)l->m_minMaxData.m_data - (char *)m_data);
    do
    {
      v8.m_quad = *(__m128 *)((char *)m_data++ + (_QWORD)v7);
      m_data[-1] = (hkVector4f)v8.m_quad;
      --v6;
    }
    while ( v6 );
  }
}

