// File Line: 80
// RVA: 0x12B52F4
__m128i *__fastcall strrchr(unsigned __int64 string, int ch)
{
  __m128i *v2; // r8
  __m128i *v3; // r9
  const __m128i *v4; // rdx
  __int64 v5; // rax
  __m128i *v7; // r10
  int v8; // r9d
  __m128i v9; // xmm3
  int v10; // edx
  int i; // ecx
  __int64 v12; // rcx
  __m128i *v13; // rcx
  int v14; // edx
  __int64 v15; // rcx
  char *v16; // rcx
  __m128i v17; // xmm0
  unsigned __int8 v18; // zf
  int v19; // ecx

  v2 = 0i64;
  v3 = (__m128i *)string;
  if ( ch )
  {
    if ( _isa_available >= 2 )
    {
      if ( (string & 0xF) != 0 )
      {
        while ( 1 )
        {
          if ( v3->m128i_i8[0] == ch )
            v2 = v3;
          if ( !v3->m128i_i8[0] )
            break;
          v3 = (__m128i *)((char *)v3 + 1);
          if ( ((unsigned __int8)v3 & 0xF) == 0 )
            goto LABEL_18;
        }
      }
      else
      {
LABEL_18:
        v17 = _mm_cvtsi32_si128((unsigned __int8)ch);
        while ( 1 )
        {
          v19 = _mm_cmpistri(v17, *v3, 64);
          v18 = _mm_cmpistrz(v17, *v3, 64);
          if ( _mm_cmpistrc(v17, *v3, 64) )
          {
            v2 = (__m128i *)((char *)v3 + v19);
            v18 = _mm_cmpistrz(v17, *v3, 64);
          }
          if ( v18 )
            break;
          ++v3;
        }
      }
    }
    else
    {
      v7 = (__m128i *)(string & 0xFFFFFFFFFFFFFFF0ui64);
      v8 = -1 << (string & 0xF);
      v9 = _mm_shuffle_epi32(
             _mm_shufflelo_epi16(_mm_cvtsi32_si128((unsigned __int8)ch | ((unsigned __int8)ch << 8)), 0),
             0);
      v10 = v8 & _mm_movemask_epi8(_mm_cmpeq_epi8(v9, *(__m128i *)(string & 0xFFFFFFFFFFFFFFF0ui64)));
      for ( i = v8 & _mm_movemask_epi8(_mm_cmpeq_epi8((__m128i)0i64, *(__m128i *)(string & 0xFFFFFFFFFFFFFFF0ui64)));
            !i;
            v10 = _mm_movemask_epi8(_mm_cmpeq_epi8(v9, *v7)) )
      {
        _BitScanReverse((unsigned int *)&v12, v10);
        v13 = (__m128i *)((char *)v7 + v12);
        if ( v10 )
          v2 = v13;
        i = _mm_movemask_epi8(_mm_cmpeq_epi8((__m128i)0i64, *++v7));
      }
      v14 = ((i & -i) - 1) & v10;
      _BitScanReverse((unsigned int *)&v15, v14);
      v16 = &v7->m128i_i8[v15];
      if ( v14 )
        return (__m128i *)v16;
    }
    return v2;
  }
  else
  {
    v4 = (const __m128i *)(string & 0xFFFFFFFFFFFFFFF0ui64);
    for ( LODWORD(v5) = (-1 << (string & 0xF)) & _mm_movemask_epi8(
                                                   _mm_cmpeq_epi8(
                                                     _mm_load_si128((const __m128i *)(string & 0xFFFFFFFFFFFFFFF0ui64)),
                                                     (__m128i)0i64));
          !(_DWORD)v5;
          LODWORD(v5) = _mm_movemask_epi8(_mm_cmpeq_epi8(_mm_load_si128(v4), (__m128i)0i64)) )
    {
      ++v4;
    }
    _BitScanForward((unsigned int *)&v5, v5);
    return (__m128i *)((char *)v4 + v5);
  }
}

