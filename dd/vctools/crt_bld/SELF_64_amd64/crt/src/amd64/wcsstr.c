// File Line: 84
// RVA: 0x12BA650
const __m128i *__fastcall wcsstr(const wchar_t *wcs1, const wchar_t *wcs2)
{
  wchar_t v2; // di
  const wchar_t *v3; // rbx
  const __m128i *v4; // r8
  __m128i v6; // xmm3
  __m128i v7; // xmm0
  unsigned int v8; // eax
  unsigned __int64 v9; // rcx
  const __m128i *v10; // rdx
  const __m128i *i; // r9
  __m128i v12; // xmm1
  unsigned int v13; // eax
  unsigned __int64 v14; // rcx
  __m128i v15; // xmm0
  const wchar_t *v16; // rcx
  signed __int64 v17; // r9
  wchar_t v18; // dx
  __m128i v19; // xmm1
  unsigned __int8 v20; // cf
  const __m128i *v21; // rdx
  const __m128i *j; // r9
  __m128i v23; // xmm1
  __m128i v24; // xmm2
  unsigned __int8 v25; // sf

  v2 = *wcs2;
  v3 = wcs2;
  v4 = (const __m128i *)wcs1;
  if ( !*wcs2 )
    return (const __m128i *)wcs1;
  if ( _isa_available < 2 )
  {
    v6 = _mm_shuffle_epi32(_mm_shufflelo_epi16(_mm_cvtsi32_si128(v2), 0), 0);
    while ( 1 )
    {
      if ( ((unsigned __int16)v4 & 0xFFFu) > 0xFF0ui64 )
        goto LABEL_9;
      v7 = _mm_loadu_si128(v4);
      v8 = _mm_movemask_epi8(_mm_or_si128(_mm_cmpeq_epi16(v7, (__m128i)0i64), _mm_cmpeq_epi16(v7, v6)));
      if ( v8 )
      {
        _BitScanForward((unsigned int *)&v9, v8);
        v4 = (const __m128i *)((char *)v4 + 2 * (v9 >> 1));
LABEL_9:
        if ( 0 == LOWORD(v4->m128i_i64[0]) )
          return 0i64;
        if ( v2 == LOWORD(v4->m128i_i64[0]) )
        {
          v10 = v4;
          for ( i = (const __m128i *)v3; ; i = (const __m128i *)((char *)i + 2) )
          {
            while ( 2 )
            {
              if ( ((unsigned __int16)i & 0xFFFu) <= 0xFF0ui64 && ((unsigned __int16)v10 & 0xFFFu) <= 0xFF0ui64 )
              {
                v12 = _mm_loadu_si128(i);
                v13 = _mm_movemask_epi8(
                        _mm_or_si128(
                          _mm_cmpeq_epi16(v12, (__m128i)0i64),
                          _mm_cmpeq_epi16(_mm_cmpeq_epi16(_mm_loadu_si128(v10), v12), (__m128i)0i64)));
                if ( !v13 )
                {
                  ++v10;
                  ++i;
                  continue;
                }
                _BitScanForward(&v13, v13);
                v14 = 2 * ((unsigned __int64)v13 >> 1);
                v10 = (const __m128i *)((char *)v10 + v14);
                i = (const __m128i *)((char *)i + v14);
              }
              break;
            }
            if ( 0 == LOWORD(i->m128i_i64[0]) )
              return v4;
            if ( LOWORD(v10->m128i_i64[0]) != LOWORD(i->m128i_i64[0]) )
              break;
            v10 = (const __m128i *)((char *)v10 + 2);
          }
        }
        v4 = (const __m128i *)((char *)v4 + 2);
      }
      else
      {
        ++v4;
      }
    }
  }
  if ( ((unsigned __int16)wcs2 & 0xFFFu) > 0xFF0ui64 )
  {
    v16 = wcs2;
    v15 = 0i64;
    v17 = 8i64;
    v18 = *wcs2;
    do
    {
      v15 = _mm_insert_epi16(_mm_srli_si128(v15, 2), v18, 7);
      if ( 0 != v18 )
      {
        ++v16;
        v18 = *v16;
      }
      --v17;
    }
    while ( v17 );
  }
  else
  {
    v15 = _mm_loadu_si128((const __m128i *)wcs2);
  }
  while ( 1 )
  {
    while ( ((unsigned __int16)v4 & 0xFFFu) > 0xFF0ui64 )
    {
      if ( 0 == LOWORD(v4->m128i_i64[0]) )
        return 0i64;
      if ( LOWORD(v4->m128i_i64[0]) == v2 )
        goto LABEL_32;
LABEL_40:
      v4 = (const __m128i *)((char *)v4 + 2);
    }
    v19 = _mm_loadu_si128(v4);
    v20 = _mm_cmpistrc(v15, v19, 13);
    if ( v20 | _mm_cmpistrz(v15, v19, 13) )
      break;
    ++v4;
  }
  if ( !v20 )
    return 0i64;
  v4 = (const __m128i *)((char *)v4 + 2 * _mm_cmpistri(v15, v19, 13));
LABEL_32:
  v21 = v4;
  for ( j = (const __m128i *)v3; ; ++j )
  {
    while ( ((unsigned __int16)v21 & 0xFFFu) > 0xFF0ui64 || ((unsigned __int16)j & 0xFFFu) > 0xFF0ui64 )
    {
      if ( 0 == LOWORD(j->m128i_i64[0]) )
        return v4;
      if ( LOWORD(v21->m128i_i64[0]) != LOWORD(j->m128i_i64[0]) )
        goto LABEL_40;
      v21 = (const __m128i *)((char *)v21 + 2);
      j = (const __m128i *)((char *)j + 2);
    }
    v23 = _mm_loadu_si128(v21);
    v24 = _mm_loadu_si128(j);
    v25 = _mm_cmpistrs(v24, v23, 13);
    if ( !_mm_cmpistro(v24, v23, 13) )
      goto LABEL_40;
    if ( v25 )
      break;
    ++v21;
  }
  return v4;
}

