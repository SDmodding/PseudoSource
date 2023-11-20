// File Line: 13
// RVA: 0x13352A0
void __fastcall hkMatrix6fAdd(hkMatrix6f *aOut, hkMatrix6f *b)
{
  aOut->m_m[0][0].m_col0.m_quad = _mm_add_ps(aOut->m_m[0][0].m_col0.m_quad, b->m_m[0][0].m_col0.m_quad);
  aOut->m_m[0][0].m_col1.m_quad = _mm_add_ps(b->m_m[0][0].m_col1.m_quad, aOut->m_m[0][0].m_col1.m_quad);
  aOut->m_m[0][0].m_col2.m_quad = _mm_add_ps(b->m_m[0][0].m_col2.m_quad, aOut->m_m[0][0].m_col2.m_quad);
  aOut->m_m[0][1].m_col0.m_quad = _mm_add_ps(b->m_m[0][1].m_col0.m_quad, aOut->m_m[0][1].m_col0.m_quad);
  aOut->m_m[0][1].m_col1.m_quad = _mm_add_ps(b->m_m[0][1].m_col1.m_quad, aOut->m_m[0][1].m_col1.m_quad);
  aOut->m_m[0][1].m_col2.m_quad = _mm_add_ps(b->m_m[0][1].m_col2.m_quad, aOut->m_m[0][1].m_col2.m_quad);
  aOut->m_m[1][0].m_col0.m_quad = _mm_add_ps(aOut->m_m[1][0].m_col0.m_quad, b->m_m[1][0].m_col0.m_quad);
  aOut->m_m[1][0].m_col1.m_quad = _mm_add_ps(b->m_m[1][0].m_col1.m_quad, aOut->m_m[1][0].m_col1.m_quad);
  aOut->m_m[1][0].m_col2.m_quad = _mm_add_ps(b->m_m[1][0].m_col2.m_quad, aOut->m_m[1][0].m_col2.m_quad);
  aOut->m_m[1][1].m_col0.m_quad = _mm_add_ps(aOut->m_m[1][1].m_col0.m_quad, b->m_m[1][1].m_col0.m_quad);
  aOut->m_m[1][1].m_col1.m_quad = _mm_add_ps(b->m_m[1][1].m_col1.m_quad, aOut->m_m[1][1].m_col1.m_quad);
  aOut->m_m[1][1].m_col2.m_quad = _mm_add_ps(b->m_m[1][1].m_col2.m_quad, aOut->m_m[1][1].m_col2.m_quad);
}

// File Line: 18
// RVA: 0x1335360
void __fastcall hkMatrix6fSub(hkMatrix6f *aOut, hkMatrix6f *b)
{
  aOut->m_m[0][0].m_col0.m_quad = _mm_sub_ps(aOut->m_m[0][0].m_col0.m_quad, b->m_m[0][0].m_col0.m_quad);
  aOut->m_m[0][0].m_col1.m_quad = _mm_sub_ps(aOut->m_m[0][0].m_col1.m_quad, b->m_m[0][0].m_col1.m_quad);
  aOut->m_m[0][0].m_col2.m_quad = _mm_sub_ps(aOut->m_m[0][0].m_col2.m_quad, b->m_m[0][0].m_col2.m_quad);
  aOut->m_m[0][1].m_col0.m_quad = _mm_sub_ps(aOut->m_m[0][1].m_col0.m_quad, b->m_m[0][1].m_col0.m_quad);
  aOut->m_m[0][1].m_col1.m_quad = _mm_sub_ps(aOut->m_m[0][1].m_col1.m_quad, b->m_m[0][1].m_col1.m_quad);
  aOut->m_m[0][1].m_col2.m_quad = _mm_sub_ps(aOut->m_m[0][1].m_col2.m_quad, b->m_m[0][1].m_col2.m_quad);
  aOut->m_m[1][0].m_col0.m_quad = _mm_sub_ps(aOut->m_m[1][0].m_col0.m_quad, b->m_m[1][0].m_col0.m_quad);
  aOut->m_m[1][0].m_col1.m_quad = _mm_sub_ps(aOut->m_m[1][0].m_col1.m_quad, b->m_m[1][0].m_col1.m_quad);
  aOut->m_m[1][0].m_col2.m_quad = _mm_sub_ps(aOut->m_m[1][0].m_col2.m_quad, b->m_m[1][0].m_col2.m_quad);
  aOut->m_m[1][1].m_col0.m_quad = _mm_sub_ps(aOut->m_m[1][1].m_col0.m_quad, b->m_m[1][1].m_col0.m_quad);
  aOut->m_m[1][1].m_col1.m_quad = _mm_sub_ps(aOut->m_m[1][1].m_col1.m_quad, b->m_m[1][1].m_col1.m_quad);
  aOut->m_m[1][1].m_col2.m_quad = _mm_sub_ps(aOut->m_m[1][1].m_col2.m_quad, b->m_m[1][1].m_col2.m_quad);
}

// File Line: 23
// RVA: 0x1335420
void __fastcall hkMatrix6fSetMul(hkMatrix6f *out, hkMatrix6f *a, hkMatrix6f *b)
{
  __m128 *v3; // rax
  signed __int64 v4; // rcx
  hkVector4f *v5; // rbx
  signed __int64 v6; // rdi
  signed __int64 v7; // rsi
  signed __int64 v8; // rbp
  signed __int64 v9; // rdx
  __m128 *v10; // rcx
  char *v11; // r9
  char *v12; // r10
  char *v13; // r11
  signed __int64 v14; // r8
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm7
  __m128 v19; // xmm6
  __m128 v20; // xmm1
  __m128 v21; // xmm5
  __m128 v22; // xmm2
  __m128 v23; // xmm5
  __m128 v24; // xmm2
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm0

  v3 = &a->m_m[0][1].m_col2.m_quad;
  v4 = (char *)out - (char *)a - (_QWORD)b;
  v5 = &b->m_m[1][0].m_col2;
  v6 = v4 - 192;
  v7 = v4 - 176;
  v8 = v4 - 208;
  v9 = 2i64;
  do
  {
    v10 = &v5->m_quad;
    v11 = (char *)v3 + v6;
    v12 = (char *)v3 + v7;
    v13 = (char *)v3 + v8;
    v14 = 2i64;
    do
    {
      v15 = v3[-5];
      v16 = v3[-4];
      v17 = v3[-3];
      v18 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v10[-8], v10[-8], 0), v15),
                _mm_mul_ps(_mm_shuffle_ps(v10[-8], v10[-8], 85), v16)),
              _mm_mul_ps(_mm_shuffle_ps(v10[-8], v10[-8], 170), v17));
      v19 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v10[-7], v10[-7], 0), v15),
                _mm_mul_ps(_mm_shuffle_ps(v10[-7], v10[-7], 85), v16)),
              _mm_mul_ps(_mm_shuffle_ps(v10[-7], v10[-7], 170), v17));
      v20 = v10[-6];
      v21 = _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v15);
      v22 = v10[-2];
      v23 = _mm_add_ps(
              _mm_add_ps(v21, _mm_mul_ps(_mm_shuffle_ps(v10[-6], v20, 85), v16)),
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v17));
      *(__m128 *)&v13[(_QWORD)v10] = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(v10[-2], v22, 0), v3[-2]),
                                         _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v3[-1])),
                                       _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), *v3));
      v24 = v10[-1];
      *(__m128 *)&v11[(_QWORD)v10] = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v3[-1]),
                                         _mm_mul_ps(_mm_shuffle_ps(v10[-1], v24, 0), v3[-2])),
                                       _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), *v3));
      v25 = _mm_add_ps(*(__m128 *)&v13[(_QWORD)v10], v18);
      *(__m128 *)&v12[(_QWORD)v10] = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(*v10, *v10, 85), v3[-1]),
                                         _mm_mul_ps(_mm_shuffle_ps(*v10, *v10, 0), v3[-2])),
                                       _mm_mul_ps(_mm_shuffle_ps(*v10, *v10, 170), *v3));
      v26 = *(__m128 *)&v11[(_QWORD)v10];
      *(__m128 *)&v13[(_QWORD)v10] = v25;
      v27 = *(__m128 *)&v12[(_QWORD)v10];
      *(__m128 *)&v11[(_QWORD)v10] = _mm_add_ps(v26, v19);
      *(__m128 *)&v12[(_QWORD)v10] = _mm_add_ps(v27, v23);
      v10 += 3;
      --v14;
    }
    while ( v14 );
    v3 += 6;
    --v9;
  }
  while ( v9 );
}

// File Line: 28
// RVA: 0x1335600
void __fastcall hkMatrix6fSetMulV(hkVector8f *out, hkMatrix6f *a, hkVector8f *b)
{
  __m128 v3; // xmm4
  hkVector4f v4; // xmm1
  __m128 v5; // xmm3
  hkVector4f v6; // xmm1
  hkVector4f v7; // xmm2
  hkVector4f v8; // xmm0

  v3 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(b->m_lin.m_quad, b->m_lin.m_quad, 85), a->m_m[0][0].m_col1.m_quad),
           _mm_mul_ps(_mm_shuffle_ps(b->m_lin.m_quad, b->m_lin.m_quad, 0), a->m_m[0][0].m_col0.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(b->m_lin.m_quad, b->m_lin.m_quad, 170), a->m_m[0][0].m_col2.m_quad));
  v4.m_quad = (__m128)b->m_ang;
  out->m_lin.m_quad = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 85), a->m_m[0][1].m_col1.m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(b->m_ang.m_quad, v4.m_quad, 0), a->m_m[0][1].m_col0.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 170), a->m_m[0][1].m_col2.m_quad));
  v5 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(b->m_lin.m_quad, b->m_lin.m_quad, 85), a->m_m[1][0].m_col1.m_quad),
           _mm_mul_ps(_mm_shuffle_ps(b->m_lin.m_quad, b->m_lin.m_quad, 0), a->m_m[1][0].m_col0.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(b->m_lin.m_quad, b->m_lin.m_quad, 170), a->m_m[1][0].m_col2.m_quad));
  v6.m_quad = (__m128)b->m_ang;
  v7.m_quad = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 85), a->m_m[1][1].m_col1.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(b->m_ang.m_quad, v6.m_quad, 0), a->m_m[1][1].m_col0.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 170), a->m_m[1][1].m_col2.m_quad));
  v8.m_quad = _mm_add_ps(out->m_lin.m_quad, v3);
  out->m_ang = (hkVector4f)v7.m_quad;
  out->m_lin = (hkVector4f)v8.m_quad;
  out->m_ang.m_quad = _mm_add_ps(v7.m_quad, v5);
}

// File Line: 33
// RVA: 0x13356D0
void __fastcall hkMatrix6fSetTranspose(hkMatrix6f *out, hkMatrix6f *in)
{
  hkMatrix3f *v2; // rbx
  hkMatrix3f *v3; // rdi

  v2 = (hkMatrix3f *)in;
  v3 = (hkMatrix3f *)out;
  hkMatrix3f::setTranspose((hkMatrix3f *)out, (hkMatrix3f *)in);
  hkMatrix3f::setTranspose(v3 + 1, v2 + 2);
  hkMatrix3f::setTranspose(v3 + 2, v2 + 1);
  hkMatrix3f::setTranspose(v3 + 3, v2 + 3);
}

// File Line: 38
// RVA: 0x1335730
void __fastcall hkMatrix6fSetInvert(hkMatrix6f *out, hkMatrix6f *in)
{
  hkMatrix6f::setInvert(out, in);
}

// File Line: 44
// RVA: 0x1334FF0
void __fastcall hkMatrix6f::setInvert(hkMatrix6f *this, hkMatrix6f *tmpIn)
{
  hkMatrix6f *v2; // rdi
  __int128 *v3; // rcx
  signed __int64 v4; // rax
  hkVector4f v5; // xmm0
  hkVector4f v6; // xmm1
  hkVector4f v7; // xmm0
  hkVector4f v8; // xmm1
  hkVector4f v9; // xmm0
  hkVector4f v10; // xmm1
  hkVector4f v11; // xmm0
  hkVector4f v12; // xmm1
  hkVector4f v13; // xmm1
  hkVector4f v14; // xmm0
  hkVector4f v15; // xmm1
  signed __int64 v16; // r10
  __int128 *v17; // r14
  signed __int64 v18; // rsi
  __m128 *v19; // rbx
  signed __int64 v20; // r9
  float *v21; // rbp
  __int64 v22; // r8
  signed __int64 v23; // r11
  __m128 v24; // xmm2
  __m128 v25; // xmm0
  signed __int64 v26; // rdx
  signed __int64 v27; // rax
  __m128 v28; // xmm2
  __m128 v29; // xmm0
  __int128 Dst[6]; // [rsp+20h] [rbp-D8h]
  __int128 v31[6]; // [rsp+80h] [rbp-78h]
  unsigned int v32; // [rsp+100h] [rbp+8h]

  v2 = this;
  v3 = Dst;
  if ( ((unsigned __int8)Dst | (unsigned __int8)tmpIn) & 0xF )
  {
    memmove(Dst, tmpIn, 0xC0ui64);
  }
  else
  {
    v4 = 1i64;
    do
    {
      v5.m_quad = (__m128)tmpIn->m_m[0][0].m_col0;
      v6.m_quad = (__m128)tmpIn->m_m[0][0].m_col1;
      v3 += 8;
      tmpIn = (hkMatrix6f *)((char *)tmpIn + 128);
      *(v3 - 8) = (__int128)v5.m_quad;
      v7.m_quad = (__m128)tmpIn[-1].m_m[1][0].m_col0;
      *(v3 - 7) = (__int128)v6.m_quad;
      v8.m_quad = (__m128)tmpIn[-1].m_m[1][0].m_col1;
      *(v3 - 6) = (__int128)v7.m_quad;
      v9.m_quad = (__m128)tmpIn[-1].m_m[1][0].m_col2;
      *(v3 - 5) = (__int128)v8.m_quad;
      v10.m_quad = (__m128)tmpIn[-1].m_m[1][1].m_col0;
      *(v3 - 4) = (__int128)v9.m_quad;
      v11.m_quad = (__m128)tmpIn[-1].m_m[1][1].m_col1;
      *(v3 - 3) = (__int128)v10.m_quad;
      v12.m_quad = (__m128)tmpIn[-1].m_m[1][1].m_col2;
      *(v3 - 2) = (__int128)v11.m_quad;
      *(v3 - 1) = (__int128)v12.m_quad;
      --v4;
    }
    while ( v4 );
    v13.m_quad = (__m128)tmpIn->m_m[0][0].m_col1;
    *v3 = (__int128)tmpIn->m_m[0][0].m_col0;
    v14.m_quad = (__m128)tmpIn->m_m[0][0].m_col2;
    v3[1] = (__int128)v13.m_quad;
    v15.m_quad = (__m128)tmpIn->m_m[0][1].m_col0;
    v3[2] = (__int128)v14.m_quad;
    v3[3] = (__int128)v15.m_quad;
  }
  v2->m_m[0][0].m_col0 = (hkVector4f)transform.m_quad;
  v16 = 0i64;
  v17 = Dst;
  v18 = (char *)v2 - (char *)v31;
  v19 = (__m128 *)v31;
  v2->m_m[0][0].m_col1 = (hkVector4f)direction.m_quad;
  v2->m_m[0][0].m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v2->m_m[0][1].m_col0 = 0i64;
  v2->m_m[0][1].m_col1 = 0i64;
  v2->m_m[0][1].m_col2 = 0i64;
  v2->m_m[1][0].m_col0 = 0i64;
  v2->m_m[1][0].m_col1 = 0i64;
  v2->m_m[1][0].m_col2 = 0i64;
  v2->m_m[1][1].m_col0 = (hkVector4f)transform.m_quad;
  v2->m_m[1][1].m_col1 = (hkVector4f)direction.m_quad;
  v2->m_m[1][1].m_col2 = (hkVector4f)stru_141A71280.m_quad;
  do
  {
    v20 = 0i64;
    v21 = (float *)v17;
    do
    {
      v22 = 0i64;
      v23 = 0i64;
      v24 = _mm_shuffle_ps((__m128)COERCE_UNSIGNED_INT(1.0 / *v21), (__m128)COERCE_UNSIGNED_INT(1.0 / *v21), 0);
      v19[-6] = _mm_mul_ps(v24, v19[-6]);
      v25 = _mm_mul_ps(*(__m128 *)((char *)v19 + v18), v24);
      *v19 = _mm_mul_ps(v24, *v19);
      *(__m128 *)((char *)v19 + v18) = v25;
      *(__m128 *)((char *)v19 + v18 + 96) = _mm_mul_ps(*(__m128 *)((char *)v19 + v18 + 96), v24);
      do
      {
        v26 = 0i64;
        do
        {
          if ( v22 != v16 || v26 != v20 )
          {
            v27 = v23 + v26;
            v32 = *((_DWORD *)Dst + v20 + 4 * (v26 + 2 * (v22 + 2 * v16) + v22 + 2 * v16)) ^ _xmm[0];
            v28 = _mm_shuffle_ps((__m128)v32, (__m128)v32, 0);
            Dst[v27] = (__int128)_mm_add_ps(_mm_mul_ps(v28, v19[-6]), (__m128)Dst[v23 + v26]);
            v29 = _mm_add_ps(
                    _mm_mul_ps(*(__m128 *)((char *)v19 + v18), v28),
                    *(&v2->m_m[0][0].m_col0.m_quad + v23 + v26));
            v31[v27] = (__int128)_mm_add_ps(_mm_mul_ps(v28, *v19), (__m128)v31[v23 + v26]);
            *(__m128 *)((char *)&v2->m_m[0][0].m_col0.m_quad + 4 * v27) = v29;
            *(&v2->m_m[0][0].m_col0.m_quad + v23 + v26 + 6) = _mm_add_ps(
                                                                _mm_mul_ps(*(__m128 *)((char *)v19 + v18 + 96), v28),
                                                                *(&v2->m_m[0][0].m_col0.m_quad + v23 + v26 + 6));
          }
          ++v26;
        }
        while ( v26 < 3 );
        v23 += 3i64;
        ++v22;
      }
      while ( v23 < 6 );
      ++v20;
      ++v19;
      v21 += 5;
    }
    while ( v20 < 3 );
    ++v16;
    v17 += 9;
  }
  while ( v16 < 2 );
}

