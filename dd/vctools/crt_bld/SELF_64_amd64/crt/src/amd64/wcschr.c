// File Line: 52
// RVA: 0x12BE6E8
const __m128i *__fastcall wcschr(const __m128i *string, wchar_t ch)
{
  __m128i v2; // xmm2
  __int64 v4; // r9
  __m128i v5; // xmm3
  __m128i v6; // xmm1
  unsigned int v7; // eax
  __int64 v8; // rcx
  _WORD *v9; // r8
  __m128i v11; // [rsp+0h] [rbp-18h] BYREF

  v2 = _mm_load_si128(&v11);
  v4 = 0i64;
  v5 = _mm_shuffle_epi32(_mm_shufflelo_epi16(_mm_cvtsi32_si128(ch), 0), 0);
  while ( 1 )
  {
    while ( ((unsigned __int16)string & 0xFFFu) > 0xFF0ui64 )
    {
      if ( string->m128i_i16[0] == ch )
        return string;
      if ( !string->m128i_i16[0] )
        return 0i64;
      string = (const __m128i *)((char *)string + 2);
    }
    v6 = _mm_loadu_si128(string);
    v2 = _mm_or_si128(_mm_cmpeq_epi16(_mm_xor_si128(v2, v2), v6), _mm_cmpeq_epi16(v6, v5));
    v7 = _mm_movemask_epi8(v2);
    if ( v7 )
      break;
    ++string;
  }
  _BitScanForward((unsigned int *)&v8, v7);
  v9 = (__int16 *)((char *)string->m128i_i16 + v8);
  if ( *v9 == ch )
    return (const __m128i *)v9;
  return (const __m128i *)v4;
}

