// File Line: 16
// RVA: 0x12D2BC0
__int64 __fastcall _sse4_sin2(
        int a1,
        __int64 a2,
        int a3,
        int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        __int64 a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        __int128 *a28,
        int a29,
        __int128 *a30,
        __int128 *a31)
{
  __m128d v31; // xmm0
  __int64 result; // rax
  int v33; // edx

  result = (unsigned int)_mm_movemask_pd((__m128d)_mm_cmpgt_epi32(
                                                    (__m128i)_mm_and_pd(v31, *(__m128d *)&MMIABSMASK_0),
                                                    *(__m128i *)&MMDHUGE_0));
  if ( (_DWORD)result )
  {
    v33 = _mm_movemask_pd((__m128d)_mm_cmpgt_epi32(
                                     *(__m128i *)&TWO_POW_30_0,
                                     (__m128i)_mm_and_pd(v31, *(__m128d *)&MMIABSMASK_0))) ^ 3;
    if ( v33 )
      return B1_7_0(
               a1,
               v33,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               a13,
               a14,
               a15,
               a16,
               a17,
               a18,
               a19,
               a20,
               a21,
               a22,
               a23,
               a24,
               a25,
               a26,
               a27,
               a28);
    else
      return 2TAG_PACKET_16_0_2_4_0(
               a1,
               0,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               a13,
               a14,
               a15,
               a16,
               a17,
               a18,
               a19,
               a20,
               a21,
               a22,
               a23,
               a24,
               a25,
               a26,
               a27,
               (_DWORD)a28,
               a29,
               a30,
               a31);
  }
  return result;
}

