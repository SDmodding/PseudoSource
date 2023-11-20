// File Line: 82
// RVA: 0x12B1E24
const __m128i *__fastcall strstr(const char *str1, const char *str2)
{
  char v2; // di
  const char *v3; // rbx
  const __m128i *v4; // r8
  __m128i v6; // xmm3
  __m128i v7; // xmm0
  __int64 v8; // rax
  const __m128i *v9; // rdx
  const __m128i *i; // r9
  __m128i v11; // xmm1
  unsigned int v12; // eax
  __m128i v13; // xmm0
  const char *v14; // rcx
  signed __int64 v15; // r9
  char v16; // dl
  __m128i v17; // xmm1
  unsigned __int8 v18; // cf
  const __m128i *v19; // rdx
  const __m128i *j; // r9
  __m128i v21; // xmm1
  __m128i v22; // xmm2
  unsigned __int8 v23; // sf

  v2 = *str2;
  v3 = str2;
  v4 = (const __m128i *)str1;
  if ( !*str2 )
    return (const __m128i *)str1;
  if ( _isa_available < 2 )
  {
    v6 = _mm_shuffle_epi32(
           _mm_shufflelo_epi16(
             _mm_cvtsi32_si128(*(unsigned __int8 *)str2 | ((unsigned int)*(unsigned __int8 *)str2 << 8)),
             0),
           0);
    while ( 1 )
    {
      if ( ((unsigned __int16)v4 & 0xFFFu) > 0xFF0ui64 )
        goto LABEL_9;
      v7 = _mm_loadu_si128(v4);
      LODWORD(v8) = _mm_movemask_epi8(_mm_or_si128(_mm_cmpeq_epi8(v7, (__m128i)0i64), _mm_cmpeq_epi8(v7, v6)));
      if ( (_DWORD)v8 )
      {
        _BitScanForward((unsigned int *)&v8, v8);
        v4 = (const __m128i *)((char *)v4 + v8);
LABEL_9:
        if ( !LOBYTE(v4->m128i_i64[0]) )
          return 0i64;
        if ( v2 == LOBYTE(v4->m128i_i64[0]) )
        {
          v9 = v4;
          for ( i = (const __m128i *)v3; ; i = (const __m128i *)((char *)i + 1) )
          {
            while ( 2 )
            {
              if ( ((unsigned __int16)i & 0xFFFu) <= 0xFF0ui64 && ((unsigned __int16)v9 & 0xFFFu) <= 0xFF0ui64 )
              {
                v11 = _mm_loadu_si128(i);
                v12 = _mm_movemask_epi8(
                        _mm_or_si128(
                          _mm_cmpeq_epi8(v11, (__m128i)0i64),
                          _mm_cmpeq_epi8(_mm_cmpeq_epi8(_mm_loadu_si128(v9), v11), (__m128i)0i64)));
                if ( !v12 )
                {
                  ++v9;
                  ++i;
                  continue;
                }
                _BitScanForward(&v12, v12);
                v9 = (const __m128i *)((char *)v9 + v12);
                i = (const __m128i *)((char *)i + v12);
              }
              break;
            }
            if ( !LOBYTE(i->m128i_i64[0]) )
              return v4;
            if ( LOBYTE(v9->m128i_i64[0]) != LOBYTE(i->m128i_i64[0]) )
              break;
            v9 = (const __m128i *)((char *)v9 + 1);
          }
        }
        v4 = (const __m128i *)((char *)v4 + 1);
      }
      else
      {
        ++v4;
      }
    }
  }
  if ( ((unsigned __int16)str2 & 0xFFFu) > 0xFF0ui64 )
  {
    v14 = str2;
    v13 = 0i64;
    v15 = 16i64;
    v16 = *str2;
    do
    {
      v13 = _mm_insert_epi8(_mm_srli_si128(v13, 1), v16, 15);
      if ( v16 )
        v16 = *++v14;
      --v15;
    }
    while ( v15 );
  }
  else
  {
    v13 = _mm_loadu_si128((const __m128i *)str2);
  }
  while ( 1 )
  {
    while ( ((unsigned __int16)v4 & 0xFFFu) > 0xFF0ui64 )
    {
      if ( !LOBYTE(v4->m128i_i64[0]) )
        return 0i64;
      if ( LOBYTE(v4->m128i_i64[0]) == v2 )
        goto LABEL_32;
LABEL_40:
      v4 = (const __m128i *)((char *)v4 + 1);
    }
    v17 = _mm_loadu_si128(v4);
    v18 = _mm_cmpistrc(v13, v17, 12);
    if ( v18 | _mm_cmpistrz(v13, v17, 12) )
      break;
    ++v4;
  }
  if ( !v18 )
    return 0i64;
  v4 = (const __m128i *)((char *)v4 + _mm_cmpistri(v13, v17, 12));
LABEL_32:
  v19 = v4;
  for ( j = (const __m128i *)v3; ; ++j )
  {
    while ( ((unsigned __int16)v19 & 0xFFFu) > 0xFF0ui64 || ((unsigned __int16)j & 0xFFFu) > 0xFF0ui64 )
    {
      if ( !LOBYTE(j->m128i_i64[0]) )
        return v4;
      if ( LOBYTE(v19->m128i_i64[0]) != LOBYTE(j->m128i_i64[0]) )
        goto LABEL_40;
      v19 = (const __m128i *)((char *)v19 + 1);
      j = (const __m128i *)((char *)j + 1);
    }
    v21 = _mm_loadu_si128(v19);
    v22 = _mm_loadu_si128(j);
    v23 = _mm_cmpistrs(v22, v21, 12);
    if ( !_mm_cmpistro(v22, v21, 12) )
      goto LABEL_40;
    if ( v23 )
      break;
    ++v19;
  }
  return v4;
}

