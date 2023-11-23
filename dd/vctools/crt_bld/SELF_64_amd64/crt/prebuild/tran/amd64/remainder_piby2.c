// File Line: 13
// RVA: 0x12CDF20
void __fastcall _remainder_piby2(long double x, long double *r, long double *rr, int *region)
{
  __int64 v5; // r10
  int v7; // r11d
  int v9; // edx
  int v10; // r11d
  __int64 v11; // r8
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // rdx
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rdx
  unsigned __int64 v17; // rdx
  unsigned __int64 v18; // rcx
  unsigned __int64 v19; // rcx
  unsigned __int64 v20; // rdx
  unsigned __int64 v21; // rdx
  unsigned __int64 v22; // rcx
  unsigned __int64 v23; // rcx
  unsigned __int64 v24; // rdx
  unsigned __int64 v25; // rdx
  unsigned __int64 v26; // rcx
  unsigned __int64 v27; // rdx
  unsigned __int64 v28; // rdx
  unsigned __int64 v29; // rcx
  unsigned __int64 v30; // rcx
  unsigned __int64 v31; // rdx
  unsigned __int64 v32; // rdx
  unsigned __int64 v33; // rcx
  unsigned __int64 v34; // rcx
  unsigned __int64 v35; // rdx
  unsigned __int64 v36; // rdx
  unsigned __int64 v37; // rcx
  unsigned __int64 v38; // rcx
  unsigned __int64 v39; // rdx
  unsigned __int64 v40; // rdx
  unsigned __int64 v41; // rcx
  unsigned __int64 v42; // rcx
  unsigned __int64 v43; // rdx
  unsigned __int64 v44; // rbx
  unsigned __int64 v45; // rdx
  __int64 v46; // rbx
  unsigned __int64 v47; // rdx
  int v48; // r9d
  char v49; // cl
  int v50; // esi
  unsigned __int64 v51; // rdx
  __int64 *v52; // r8
  __int64 v53; // r8
  __int64 *v54; // rax
  unsigned __int64 v55; // r8
  int v56; // r11d
  __int64 v57; // rax
  double v58; // xmm7_8
  double v59; // xmm7_8
  double v60; // xmm5_8
  __int64 v61[6]; // [rsp+18h] [rbp-B0h] BYREF
  unsigned __int64 v62; // [rsp+48h] [rbp-80h]
  unsigned __int64 v63; // [rsp+50h] [rbp-78h]
  unsigned __int64 v64; // [rsp+58h] [rbp-70h]
  unsigned __int64 v65; // [rsp+60h] [rbp-68h]
  unsigned __int64 v66; // [rsp+68h] [rbp-60h]
  unsigned __int64 v67; // [rsp+70h] [rbp-58h]
  unsigned __int64 v68; // [rsp+78h] [rbp-50h]

  v67 = 0i64;
  v5 = *(_QWORD *)&x & 0xFFFFFFFFFFFFFi64 | 0x10000000000000i64;
  v7 = ((*(_QWORD *)&x >> 52) & 0x7FF) - 1023;
  v9 = v7 / 10;
  v10 = v7 % 10;
  v11 = v9 + 18;
  v12 = v5 * pibits_1[v11];
  v13 = (v12 >> 10) + v5 * pibits_1[v11 - 1];
  v14 = pibits_1[v11 - 2];
  v66 = v12 & 0x3FF;
  LOWORD(v12) = v13;
  v15 = (v13 >> 10) + v5 * v14;
  v16 = pibits_1[v11 - 3];
  v65 = v12 & 0x3FF;
  LOWORD(v12) = v15;
  v17 = (v15 >> 10) + v5 * v16;
  v18 = pibits_1[v11 - 4];
  v64 = v12 & 0x3FF;
  LOWORD(v12) = v17;
  v19 = (v17 >> 10) + v5 * v18;
  v20 = pibits_1[v11 - 5];
  v63 = v12 & 0x3FF;
  LOWORD(v12) = v19;
  v21 = (v19 >> 10) + v5 * v20;
  v22 = pibits_1[v11 - 6];
  v62 = v12 & 0x3FF;
  LOWORD(v12) = v21;
  v23 = (v21 >> 10) + v5 * v22;
  v24 = pibits_1[v11 - 7];
  v68 = v12 & 0x3FF;
  v25 = (v23 >> 10) + v5 * v24;
  v67 = v23 & 0x3FF;
  v66 = v25 & 0x3FF;
  v26 = (v25 >> 10) + v5 * pibits_1[v11 - 8];
  v27 = pibits_1[v11 - 9];
  v65 = v26 & 0x3FF;
  v28 = (v26 >> 10) + v5 * v27;
  v29 = pibits_1[v11 - 10];
  v64 = v28 & 0x3FF;
  v30 = (v28 >> 10) + v5 * v29;
  v31 = pibits_1[v11 - 11];
  v63 = v30 & 0x3FF;
  v32 = (v30 >> 10) + v5 * v31;
  v33 = pibits_1[v11 - 12];
  v62 = v32 & 0x3FF;
  v34 = (v32 >> 10) + v5 * v33;
  v35 = pibits_1[v11 - 13];
  v61[5] = v34 & 0x3FF;
  v36 = (v34 >> 10) + v5 * v35;
  v37 = pibits_1[v11 - 14];
  v61[4] = v36 & 0x3FF;
  v38 = (v36 >> 10) + v5 * v37;
  v39 = pibits_1[v11 - 15];
  v61[3] = v38 & 0x3FF;
  v40 = (v38 >> 10) + v5 * v39;
  v41 = pibits_1[v11 - 16];
  v61[2] = v40 & 0x3FF;
  v42 = (v40 >> 10) + v5 * v41;
  v43 = pibits_1[v11 - 18];
  v61[1] = v42 & 0x3FF;
  v44 = (v42 >> 10) + v5 * pibits_1[v11 - 17];
  v45 = (v44 >> 10) + v5 * v43;
  v46 = v44 & 0x3FF;
  v61[0] = v46;
  v47 = ((v46 | ((v45 & 0x3FF) << 10)) >> (10 - (unsigned __int8)v10 - 1)) & 7;
  v48 = 1;
  v49 = 10 - v10;
  v50 = v47 & 1;
  if ( (v47 & 1) != 0 )
  {
    *region = ((unsigned __int8)((int)v47 >> 1) + 1) & 3;
    v51 = ~v46 & ((1i64 << v49) - 1);
    if ( v51 < 0x20000000000000i64 )
    {
      v52 = v61;
      do
      {
        ++v52;
        ++v48;
        v51 = (v51 << 10) | ~*v52 & 0x3FF;
      }
      while ( v51 < 0x20000000000000i64 );
    }
    v53 = ~v61[v48];
  }
  else
  {
    *region = (int)v47 >> 1;
    v51 = v46 & ((1i64 << v49) - 1);
    if ( v51 < 0x20000000000000i64 )
    {
      v54 = v61;
      do
      {
        ++v54;
        ++v48;
        v51 = *v54 | (v51 << 10);
      }
      while ( v51 < 0x20000000000000i64 );
    }
    v53 = v61[v48];
  }
  v55 = v53 << 54;
  v56 = v10 - 10 * v48 + 52;
  while ( v51 >= 0x20000000000000i64 )
  {
    ++v56;
    v55 = (v55 >> 1) | (v51 << 63);
    v51 >>= 1;
  }
  v57 = v51 & 0xFFFFFFFFFFFFFi64 | ((v56 + 1023i64) << 52);
  if ( v50 )
    v57 |= 0x8000000000000000ui64;
  v58 = COERCE_DOUBLE(((v56 + 970i64) << 52) | (v55 >> 12)) - COERCE_DOUBLE((v56 + 970i64) << 52);
  if ( v50 )
    v59 = v58 * -2.0;
  else
    v59 = v58 * 2.0;
  v60 = COERCE_DOUBLE(v57 & 0xFFFFFFFFF8000000ui64) * 1.570796310901642
      - *(double *)&v57 * 1.570796326794897
      + (*(double *)&v57 - COERCE_DOUBLE(v57 & 0xFFFFFFFFF8000000ui64)) * 1.570796310901642
      + COERCE_DOUBLE(v57 & 0xFFFFFFFFF8000000ui64) * 0.00000001589325471229586
      + (*(double *)&v57 - COERCE_DOUBLE(v57 & 0xFFFFFFFFF8000000ui64)) * 0.00000001589325471229586
      + v59 * 1.570796326794897
      + *(double *)&v57 * 6.123233995736765e-17;
  *r = v60 + *(double *)&v57 * 1.570796326794897;
  *rr = *(double *)&v57 * 1.570796326794897 - (v60 + *(double *)&v57 * 1.570796326794897) + v60;
}

