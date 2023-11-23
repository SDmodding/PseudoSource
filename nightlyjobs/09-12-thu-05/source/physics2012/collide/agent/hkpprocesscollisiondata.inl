// File Line: 66
// RVA: 0xCF4B90
void __fastcall hkpProcessCollisionData::ToiInfo::flip(hkpProcessCollisionData::ToiInfo *this)
{
  hkGskCache16 *p_m_gskCache; // r9
  int m_dimA; // edx
  char v3; // cl
  int m_dimB; // eax
  unsigned __int16 v5; // r8
  unsigned __int16 *v6; // rcx
  unsigned __int16 v7; // cx

  p_m_gskCache = &this->m_gskCache;
  this->m_contactPoint.m_separatingNormal.m_quad = _mm_xor_ps(
                                                     (__m128)_mm_shuffle_epi32(
                                                               _mm_insert_epi16((__m128i)0i64, 0x8000u, 1),
                                                               64),
                                                     this->m_contactPoint.m_separatingNormal.m_quad);
  m_dimA = (unsigned __int8)this->m_gskCache.m_dimA;
  v3 = (16 * (*((_BYTE *)&this->m_gskCache.hkpGskCache + 10) & 0xF)) | (*((_BYTE *)&this->m_gskCache.hkpGskCache + 10) >> 4);
  m_dimB = (unsigned __int8)p_m_gskCache->m_dimB;
  p_m_gskCache->m_dimB = m_dimA;
  p_m_gskCache->m_dimA = m_dimB;
  *((_BYTE *)&p_m_gskCache->hkpGskCache + 10) = v3;
  v5 = p_m_gskCache->m_vertices[0];
  v6 = &p_m_gskCache->m_vertices[m_dimA - 1 + m_dimB];
  p_m_gskCache->m_vertices[0] = *v6;
  *v6 = v5;
  if ( (p_m_gskCache->m_dimB & p_m_gskCache->m_dimA) == 2 )
  {
    v7 = p_m_gskCache->m_vertices[1];
    p_m_gskCache->m_vertices[1] = p_m_gskCache->m_vertices[2];
    p_m_gskCache->m_vertices[2] = v7;
  }
}

