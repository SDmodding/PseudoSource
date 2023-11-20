// File Line: 83
// RVA: 0x12C09FC
unsigned __int16 *__fastcall wcsrchr(const wchar_t *string, wchar_t ch)
{
  wchar_t v2; // r9
  const __m128i *v3; // r8
  const wchar_t *v4; // rdx
  unsigned __int16 *v5; // rcx
  __int16 v6; // ax
  unsigned __int16 *result; // rax
  signed __int64 v8; // rdx
  __m128i v9; // xmm1
  __m128i v10; // xmm0
  int v11; // ecx
  __m128i v12; // xmm1
  __m128i v13; // xmm0
  unsigned __int8 v14; // zf
  int v15; // ecx

  v2 = ch;
  v3 = (const __m128i *)string;
  if ( _isa_available >= 2 )
  {
    v8 = 0i64;
    while ( ((_BYTE)v3 + 1) & 0xE )
    {
      if ( LOWORD(v3->m128i_i64[0]) == v2 )
        v8 = (signed __int64)v3;
      if ( !LOWORD(v3->m128i_i64[0]) )
        return (unsigned __int16 *)v8;
      v3 = (const __m128i *)((char *)v3 + 2);
    }
    if ( 0 != v2 )
    {
      v12 = _mm_cvtsi32_si128(v2);
      while ( 1 )
      {
        v13 = _mm_loadu_si128(v3);
        v15 = _mm_cmpistri(v12, v13, 65);
        v14 = _mm_cmpistrz(v12, v13, 65);
        if ( _mm_cmpistrc(v12, v13, 65) )
          v8 = (signed __int64)v3->m128i_i64 + 2 * v15;
        if ( v14 )
          break;
        ++v3;
      }
      return (unsigned __int16 *)v8;
    }
    v9 = _mm_cvtsi32_si128(0xFFFF0001);
    while ( 1 )
    {
      v10 = _mm_loadu_si128(v3);
      v11 = _mm_cmpistri(v9, v10, 21);
      if ( _mm_cmpistrz(v9, v10, 21) )
        break;
      ++v3;
    }
    result = (unsigned __int16 *)((char *)v3 + 2 * v11);
  }
  else
  {
    v4 = string;
    v5 = 0i64;
    do
    {
      v6 = v3->m128i_i64[0];
      v3 = (const __m128i *)((char *)v3 + 2);
    }
    while ( v6 );
    do
      v3 = (const __m128i *)((char *)v3 - 2);
    while ( v3 != (const __m128i *)v4 && LOWORD(v3->m128i_i64[0]) != v2 );
    if ( LOWORD(v3->m128i_i64[0]) == v2 )
      v5 = (unsigned __int16 *)v3;
    result = v5;
  }
  return result;
}

