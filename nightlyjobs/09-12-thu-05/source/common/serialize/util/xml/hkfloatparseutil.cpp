// File Line: 47
// RVA: 0xE66C80
signed __int64 __fastcall hkFloatParseUtil::getFloatType(float f)
{
  if ( (LODWORD(f) & 0x7F800000) != 2139095040 )
    return 5i64;
  if ( f == 3.4028237e38/*+Inf*/ )
    return 1i64;
  if ( f == -3.4028237e38/*-Inf*/ )
    return 0i64;
  if ( f == -5.1042355e38/*NaN*/ )
    return 4i64;
  return (f >= 0.0) | 2u;
}

// File Line: 73
// RVA: 0xE66CE0
signed __int64 __fastcall hkFloatParseUtil::getFloatType(long double f)
{
  if ( (*(_QWORD *)&f & 0x7FF0000000000000i64) != 9218868437227405312i64 )
    return 5i64;
  if ( f == 1.797693134862316e308/*+Inf*/ )
    return 1i64;
  if ( f == -1.797693134862316e308/*-Inf*/ )
    return 0i64;
  if ( f == -2.696539702293474e308/*NaN*/ )
    return 4i64;
  return 3 - (unsigned int)(f < 0.0);
}

// File Line: 99
// RVA: 0xE66D60
char __fastcall hkFloatParseUtil::equals(float a, float b)
{
  int v2; // ebx

  v2 = hkFloatParseUtil::getFloatType(a);
  if ( v2 != (unsigned int)hkFloatParseUtil::getFloatType(b) )
    return 0;
  if ( v2 != 5 || a == b )
    return 1;
  return 0;
}

// File Line: 114
// RVA: 0xE66DE0
char __fastcall hkFloatParseUtil::equals(long double a, long double b)
{
  int v2; // ebx

  v2 = hkFloatParseUtil::getFloatType(a);
  if ( v2 != (unsigned int)hkFloatParseUtil::getFloatType(b) )
    return 0;
  if ( v2 != 5 || a == b )
    return 1;
  return 0;
}

// File Line: 129
// RVA: 0xE66E60
void __fastcall hkFloatParseUtil::calcFloatText(float a, hkStringBuf *buf)
{
  hkStringBuf *v2; // rbx
  int v3; // eax

  v2 = buf;
  v3 = hkFloatParseUtil::getFloatType(a);
  if ( v3 == 5 )
    hkStringBuf::printf(v2, "%g", a);
  else
    hkStringBuf::operator=(v2, s_textLut[v3]);
}

// File Line: 142
// RVA: 0xE66ED0
void __fastcall hkFloatParseUtil::calcFloatText(long double a, hkStringBuf *buf)
{
  hkStringBuf *v2; // rbx
  int v3; // eax

  v2 = buf;
  v3 = hkFloatParseUtil::getFloatType(a);
  if ( v3 == 5 )
    hkStringBuf::printf(v2, "%g", a);
  else
    hkStringBuf::operator=(v2, s_textLut[v3]);
}

// File Line: 155
// RVA: 0xE66F30
void __fastcall hkFloatParseUtil::calcFloatTextWithPoint(float a, hkStringBuf *buf)
{
  hkStringBuf *v2; // rbx
  int v3; // eax

  v2 = buf;
  v3 = hkFloatParseUtil::getFloatType(a);
  if ( v3 == 5 )
  {
    hkStringBuf::printf(v2, "%g", a);
    if ( (unsigned int)hkStringBuf::indexOf(v2, 46, 0, 0x7FFFFFFF) == -1 )
      hkStringBuf::operator+=(v2, ".0");
  }
  else
  {
    hkStringBuf::operator=(v2, s_textLut[v3]);
  }
}

// File Line: 170
// RVA: 0xE66FC0
void __fastcall hkFloatParseUtil::calcFloatTextWithPoint(long double a, hkStringBuf *buf)
{
  hkStringBuf *v2; // rbx
  int v3; // eax

  v2 = buf;
  v3 = hkFloatParseUtil::getFloatType(a);
  if ( v3 == 5 )
  {
    hkStringBuf::printf(v2, "%g", a);
    if ( (unsigned int)hkStringBuf::indexOf(v2, 46, 0, 0x7FFFFFFF) == -1 )
      hkStringBuf::operator+=(v2, ".0");
  }
  else
  {
    hkStringBuf::operator=(v2, s_textLut[v3]);
  }
}

// File Line: 185
// RVA: 0xE67050
hkResult *__fastcall hkFloatParseUtil::parseFloat(hkResult *result, hkSubString *str, float *valueOut)
{
  float *v3; // r15
  hkSubString *v4; // r14
  hkResult *v5; // rsi
  hkResult *v6; // rax
  const char *v7; // rbx
  const char *v8; // rdi
  const char *v9; // rax
  float v10; // xmm0_4
  int v11; // edi
  const char **v12; // rbx
  char dst[104]; // [rsp+20h] [rbp-68h]
  hkBool resulta; // [rsp+98h] [rbp+10h]

  v3 = valueOut;
  v4 = str;
  v5 = result;
  if ( LODWORD(str->m_end) - LODWORD(str->m_start) <= 64 )
  {
    v7 = str->m_end;
    v8 = str->m_start;
    v9 = str->m_start;
    if ( str->m_start >= v7 )
    {
LABEL_6:
      hkString::strNcpy(dst, str->m_start, (_DWORD)v7 - (_DWORD)v8);
      dst[v7 - v8] = 0;
      v10 = hkString::atof(dst);
      v5->m_enum = 0;
      *v3 = v10;
    }
    else
    {
      while ( *v9 != 35 )
      {
        if ( ++v9 >= v7 )
          goto LABEL_6;
      }
      v11 = 0;
      v12 = (const char **)s_textLut;
      while ( !hkSubString::operator==(v4, &resulta, *v12)->m_bool )
      {
        ++v12;
        ++v11;
        if ( (signed __int64)v12 >= (signed __int64)"-1.#INF00" )
        {
          v5->m_enum = 1;
          goto LABEL_11;
        }
      }
      v5->m_enum = 0;
      *v3 = *(float *)&hkFloatParseUtil::s_valuesLut[v11];
    }
LABEL_11:
    v6 = v5;
  }
  else
  {
    result->m_enum = 1;
    v6 = result;
  }
  return v6;
}

