// File Line: 49
// RVA: 0x12B10C0
char *__fastcall strchr(unsigned __int64 string, unsigned __int8 ch)
{
  __m128i *v2; // r8
  __int64 v3; // r9
  int v4; // r10d
  __m128i v5; // xmm3
  __int64 v6; // rdx
  char *v7; // rdx

  v2 = (__m128i *)(string & 0xFFFFFFFFFFFFFFF0ui64);
  v3 = 0i64;
  v4 = ch | (ch << 8);
  v5 = _mm_shuffle_epi32(_mm_shufflelo_epi16(_mm_cvtsi32_si128(v4), 0), 0);
  for ( LODWORD(v6) = (-1 << (string & 0xF)) & _mm_movemask_epi8(
                                                 _mm_or_si128(
                                                   _mm_cmpeq_epi8(v5, *(__m128i *)(string & 0xFFFFFFFFFFFFFFF0ui64)),
                                                   _mm_cmpeq_epi8(
                                                     (__m128i)0i64,
                                                     *(__m128i *)(string & 0xFFFFFFFFFFFFFFF0ui64))));
        !(_DWORD)v6;
        LODWORD(v6) = _mm_movemask_epi8(_mm_or_si128(_mm_cmpeq_epi8(v5, *v2), _mm_cmpeq_epi8((__m128i)0i64, *v2))) )
  {
    ++v2;
  }
  _BitScanForward((unsigned int *)&v6, v6);
  v7 = &v2->m128i_i8[v6];
  if ( *v7 == (_BYTE)v4 )
    return v7;
  return (char *)v3;
}

