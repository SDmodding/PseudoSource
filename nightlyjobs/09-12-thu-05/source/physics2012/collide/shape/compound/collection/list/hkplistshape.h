// File Line: 145
// RVA: 0xCF0590
__int64 __fastcall hkpListShape::getNumChildShapes(hkpListShape *this)
{
  return LODWORD(this->m_userData) - (unsigned int)WORD1(this->vfptr);
}

// File Line: 148
// RVA: 0xCF0510
signed __int64 __fastcall hkpListShape::getFirstKey(hkpListShape *this)
{
  signed int v1; // er8
  signed __int64 result; // rax

  v1 = this->m_userData;
  result = 0i64;
  if ( v1 <= 0 )
    return 0xFFFFFFFFi64;
  while ( (unsigned int)result < 0x100
       && !(this->m_aabbHalfExtents.m_quad.m128_i32[(unsigned __int64)(unsigned int)result >> 5] & (1 << (result & 0x1F))) )
  {
    result = (unsigned int)(result + 1);
    if ( (signed int)result >= v1 )
      return 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 152
// RVA: 0xCF0550
signed __int64 __fastcall hkpListShape::getNextKey(hkpListShape *this, unsigned int key)
{
  signed __int64 result; // rax

  for ( result = key + 1; (signed int)result < SLODWORD(this->m_userData); result = (unsigned int)(result + 1) )
  {
    if ( (unsigned int)result >= 0x100
      || this->m_aabbHalfExtents.m_quad.m128_i32[(unsigned __int64)(unsigned int)result >> 5] & (1 << (result & 0x1F)) )
    {
      return result;
    }
  }
  return 0xFFFFFFFFi64;
}

