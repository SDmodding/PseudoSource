// File Line: 47
// RVA: 0xE66C80
__int64 __fastcall hkFloatParseUtil::getFloatType(float f)
{
  if ( (LODWORD(f) & 0x7F800000) != 2139095040 )
    return 5i64;
  if ( f == INFINITY )
    return 1i64;
  if ( f == -INFINITY )
    return 0i64;
  if ( f == NAN )
    return 4i64;
  return (f >= 0.0) | 2u;
}

// File Line: 73
// RVA: 0xE66CE0
__int64 __fastcall hkFloatParseUtil::getFloatType(long double f)
{
  if ( (*(_QWORD *)&f & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 )
    return 5i64;
  if ( f == INFINITY )
    return 1i64;
  if ( f == -INFINITY )
    return 0i64;
  if ( f == NAN )
    return 4i64;
  return 3 - (unsigned int)(f < 0.0);
}

// File Line: 99
// RVA: 0xE66D60
bool __fastcall hkFloatParseUtil::equals(float a, float b)
{
  int FloatType; // ebx

  FloatType = hkFloatParseUtil::getFloatType(a);
  if ( FloatType != (unsigned int)hkFloatParseUtil::getFloatType(b) )
    return 0;
  return FloatType != 5 || a == b;
}

// File Line: 114
// RVA: 0xE66DE0
bool __fastcall hkFloatParseUtil::equals(long double a, long double b)
{
  int FloatType; // ebx

  FloatType = hkFloatParseUtil::getFloatType(a);
  if ( FloatType != (unsigned int)hkFloatParseUtil::getFloatType(b) )
    return 0;
  return FloatType != 5 || a == b;
}

// File Line: 129
// RVA: 0xE66E60
void __fastcall hkFloatParseUtil::calcFloatText(float a, hkStringBuf *buf)
{
  int FloatType; // eax

  FloatType = hkFloatParseUtil::getFloatType(a);
  if ( FloatType == 5 )
    hkStringBuf::printf(buf, "%g", a);
  else
    hkStringBuf::operator=(buf, s_textLut[FloatType]);
}

// File Line: 142
// RVA: 0xE66ED0
void __fastcall hkFloatParseUtil::calcFloatText(long double a, hkStringBuf *buf)
{
  int FloatType; // eax

  FloatType = hkFloatParseUtil::getFloatType(a);
  if ( FloatType == 5 )
    hkStringBuf::printf(buf, "%g", (double)a);
  else
    hkStringBuf::operator=(buf, s_textLut[FloatType]);
}

// File Line: 155
// RVA: 0xE66F30
void __fastcall hkFloatParseUtil::calcFloatTextWithPoint(float a, hkStringBuf *buf)
{
  int FloatType; // eax

  FloatType = hkFloatParseUtil::getFloatType(a);
  if ( FloatType == 5 )
  {
    hkStringBuf::printf(buf, "%g", a);
    if ( (unsigned int)hkStringBuf::indexOf(buf, 46, 0, 0x7FFFFFFF) == -1 )
      hkStringBuf::operator+=(buf, ".0");
  }
  else
  {
    hkStringBuf::operator=(buf, s_textLut[FloatType]);
  }
}

// File Line: 170
// RVA: 0xE66FC0
void __fastcall hkFloatParseUtil::calcFloatTextWithPoint(long double a, hkStringBuf *buf)
{
  int FloatType; // eax

  FloatType = hkFloatParseUtil::getFloatType(a);
  if ( FloatType == 5 )
  {
    hkStringBuf::printf(buf, "%g", (double)a);
    if ( (unsigned int)hkStringBuf::indexOf(buf, 46, 0, 0x7FFFFFFF) == -1 )
      hkStringBuf::operator+=(buf, ".0");
  }
  else
  {
    hkStringBuf::operator=(buf, s_textLut[FloatType]);
  }
}

// File Line: 185
// RVA: 0xE67050
hkResult *__fastcall hkFloatParseUtil::parseFloat(hkResult *result, hkSubString *str, float *valueOut)
{
  const char *m_end; // rbx
  const char *m_start; // rdi
  const char *v9; // rax
  float v10; // xmm0_4
  int v11; // edi
  const char **v12; // rbx
  char dst[104]; // [rsp+20h] [rbp-68h] BYREF
  hkBool resulta; // [rsp+98h] [rbp+10h] BYREF

  if ( LODWORD(str->m_end) - LODWORD(str->m_start) <= 64 )
  {
    m_end = str->m_end;
    m_start = str->m_start;
    v9 = str->m_start;
    if ( str->m_start >= m_end )
    {
LABEL_6:
      hkString::strNcpy(dst, str->m_start, (_DWORD)m_end - (_DWORD)m_start);
      dst[m_end - m_start] = 0;
      v10 = hkString::atof(dst);
      result->m_enum = HK_SUCCESS;
      *valueOut = v10;
    }
    else
    {
      while ( *v9 != 35 )
      {
        if ( ++v9 >= m_end )
          goto LABEL_6;
      }
      v11 = 0;
      v12 = (const char **)s_textLut;
      while ( !hkSubString::operator==(str, &resulta, *v12)->m_bool )
      {
        ++v12;
        ++v11;
        if ( (__int64)v12 >= (__int64)"-1.#INF00" )
        {
          result->m_enum = HK_FAILURE;
          return result;
        }
      }
      result->m_enum = HK_SUCCESS;
      *valueOut = *(float *)&hkFloatParseUtil::s_valuesLut[v11];
    }
    return result;
  }
  else
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
}

