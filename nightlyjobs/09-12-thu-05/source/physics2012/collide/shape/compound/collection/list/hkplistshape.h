// File Line: 145
// RVA: 0xCF0590
__int64 __fastcall hkpListShape::getNumChildShapes(hkpListShape *this)
{
  return LODWORD(this->m_userData) - (unsigned int)WORD1(this->hkpShapeCollection::hkpShapeContainer::vfptr);
}

// File Line: 148
// RVA: 0xCF0510
__int64 __fastcall hkpListShape::getFirstKey(hkpListShape *this)
{
  int m_userData; // r8d
  __int64 result; // rax

  m_userData = this->m_userData;
  result = 0i64;
  if ( m_userData <= 0 )
    return 0xFFFFFFFFi64;
  while ( (unsigned int)result < 0x100
       && (this->m_aabbHalfExtents.m_quad.m128_i32[(unsigned __int64)(unsigned int)result >> 5] & (1 << (result & 0x1F))) == 0 )
  {
    result = (unsigned int)(result + 1);
    if ( (int)result >= m_userData )
      return 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 152
// RVA: 0xCF0550
__int64 __fastcall hkpListShape::getNextKey(hkpListShape *this, unsigned int key)
{
  __int64 result; // rax

  for ( result = key + 1; (int)result < SLODWORD(this->m_userData); result = (unsigned int)(result + 1) )
  {
    if ( (unsigned int)result >= 0x100
      || (this->m_aabbHalfExtents.m_quad.m128_i32[(unsigned __int64)(unsigned int)result >> 5] & (1 << (result & 0x1F))) != 0 )
    {
      return result;
    }
  }
  return 0xFFFFFFFFi64;
}

