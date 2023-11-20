// File Line: 52
// RVA: 0x12BE6E8
const __m128i *__fastcall wcschr(const wchar_t *string, wchar_t ch)
{
  __m128i v2; // xmm2
  const __m128i *v3; // r8
  _WORD *v4; // r9
  __m128i v5; // xmm3
  __m128i v6; // xmm1
  unsigned int v7; // eax
  __int64 v8; // rcx
  _WORD *v9; // r8
  __int128 v11; // [rsp+0h] [rbp-18h]

  v2 = _mm_load_si128((const __m128i *)&v11);
  v3 = (const __m128i *)string;
  v4 = 0i64;
  v5 = _mm_shuffle_epi32(_mm_shufflelo_epi16(_mm_cvtsi32_si128(ch), 0), 0);
  while ( 1 )
  {
    while ( ((unsigned __int16)v3 & 0xFFFu) > 0xFF0ui64 )
    {
      if ( LOWORD(v3->m128i_i64[0]) == ch )
        return v3;
      if ( !LOWORD(v3->m128i_i64[0]) )
        return 0i64;
      v3 = (const __m128i *)((char *)v3 + 2);
    }
    v6 = _mm_loadu_si128(v3);
    v2 = _mm_or_si128(_mm_cmpeq_epi16(_mm_xor_si128(v2, v2), v6), _mm_cmpeq_epi16(v6, v5));
    v7 = _mm_movemask_epi8(v2);
    if ( v7 )
      break;
    ++v3;
  }
  _BitScanForward((unsigned int *)&v8, v7);
  v9 = (_WORD *)((char *)v3->m128i_i64 + v8);
  if ( *v9 == ch )
    v4 = v9;
  return (const __m128i *)v4;
}

