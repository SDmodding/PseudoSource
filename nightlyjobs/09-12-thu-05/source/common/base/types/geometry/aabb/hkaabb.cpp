// File Line: 12
// RVA: 0xC5C350
bool __fastcall hkAabb::isValid(hkAabb *this)
{
  hkVector4f v1; // xmm1
  hkVector4f v2; // xmm2
  bool result; // al

  v1.m_quad = (__m128)this->m_min;
  result = 0;
  if ( !(_mm_movemask_ps(_mm_cmpunordps(v1.m_quad, v1.m_quad)) & 7) )
  {
    v2.m_quad = (__m128)this->m_max;
    if ( !(_mm_movemask_ps(_mm_cmpunordps(v2.m_quad, v2.m_quad)) & 7)
      && (_mm_movemask_ps(_mm_cmpleps(v1.m_quad, v2.m_quad)) & 7) == 7 )
    {
      result = 1;
    }
  }
  return result;
}

