// File Line: 66
// RVA: 0xCF4B90
void __fastcall hkpProcessCollisionData::ToiInfo::flip(hkpProcessCollisionData::ToiInfo *this)
{
  hkGskCache16 *v1; // r9
  int v2; // edx
  char v3; // cl
  int v4; // eax
  unsigned __int16 v5; // r8
  __int64 v6; // rax
  unsigned __int16 v7; // cx

  v1 = &this->m_gskCache;
  this->m_contactPoint.m_separatingNormal.m_quad = _mm_xor_ps(
                                                     (__m128)_mm_shuffle_epi32(
                                                               _mm_insert_epi16((__m128i)0i64, 0x8000u, 1),
                                                               64),
                                                     this->m_contactPoint.m_separatingNormal.m_quad);
  v2 = (unsigned __int8)this->m_gskCache.m_dimA;
  v3 = 16 * (*((_BYTE *)&this->m_gskCache.0 + 10) & 0xF) | (*((_BYTE *)&this->m_gskCache.0 + 10) >> 4);
  v4 = (unsigned __int8)v1->m_dimB;
  v1->m_dimB = v2;
  v1->m_dimA = v4;
  *((_BYTE *)&v1->0 + 10) = v3;
  v5 = v1->m_vertices[0];
  v6 = v2 + v4 - 1;
  v1->m_vertices[0] = v1->m_vertices[v6];
  v1->m_vertices[v6] = v5;
  if ( (v1->m_dimB & v1->m_dimA) == 2 )
  {
    v7 = v1->m_vertices[1];
    v1->m_vertices[1] = v1->m_vertices[2];
    v1->m_vertices[2] = v7;
  }
}

