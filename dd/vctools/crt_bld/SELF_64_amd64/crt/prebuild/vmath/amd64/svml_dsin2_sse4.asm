// File Line: 16
// RVA: 0x12D2BC0
__int64 __usercall _sse4_sin2@<rax>(__int64 a1@<rcx>, __int64 a2@<r8>, __int64 a3@<r9>, __m128d a4@<xmm0>, __int64 a5@<rdx>, __int64 a6, __int64 a7, __int64 a8, __int64 a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, __int64 a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38, __int128 *a39, int a40, int a41, int a42, int a43, int a44, int a45, int a46, int a47, int a48, int a49, int a50, int a51, __int128 *a52, __int128 *a53)
{
  __int64 result; // rax
  __int64 v54; // rdx

  result = (unsigned int)_mm_movemask_pd((__m128d)_mm_cmpgt_epi32(
                                                    (__m128i)_mm_and_pd(a4, *(__m128d *)&MMIABSMASK_0),
                                                    *(__m128i *)&MMDHUGE_0));
  if ( (_DWORD)result )
  {
    v54 = _mm_movemask_pd((__m128d)_mm_cmpgt_epi32(
                                     *(__m128i *)&TWO_POW_30_0,
                                     (__m128i)_mm_and_pd(a4, *(__m128d *)&MMIABSMASK_0))) ^ 3u;
    if ( (_DWORD)v54 )
    {
      JUMPOUT(result, 3, B1_7_0);
      result = B1_7_0(
                 a1,
                 v54,
                 a2,
                 a3,
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
                 a28,
                 a29,
                 a30,
                 a31,
                 a32,
                 a33,
                 a34,
                 a35,
                 a36,
                 a37,
                 a38,
                 a39);
    }
    else
    {
      result = 2TAG_PACKET_16_0_2_4_0(
                 a1,
                 0,
                 a2,
                 a3,
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
                 a28,
                 a29,
                 a30,
                 a31,
                 a32,
                 a33,
                 a34,
                 a35,
                 a36,
                 a37,
                 a38,
                 (_DWORD)a39,
                 a40,
                 a41,
                 a42,
                 a43,
                 a44,
                 a45,
                 a46,
                 a47,
                 a48,
                 a49,
                 a50,
                 a51,
                 a52,
                 a53);
    }
  }
  return result;
}

