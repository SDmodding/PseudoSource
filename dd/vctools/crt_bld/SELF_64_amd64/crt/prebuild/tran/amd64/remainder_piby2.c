// File Line: 13
// RVA: 0x12CDF20
void __fastcall _remainder_piby2(long double x, long double *r, long double *rr, int *region)
{
  long double *v4; // r14
  signed __int64 v5; // r10
  int *v6; // rdi
  int v7; // er11
  long double *v8; // r15
  int v9; // edx
  int v10; // er11
  __int64 v11; // r8
  unsigned __int64 v12; // rdx
  unsigned __int64 v13; // rcx
  __int16 v14; // ax
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rdx
  __int16 v17; // ax
  unsigned __int64 v18; // rdx
  unsigned __int64 v19; // rcx
  __int16 v20; // ax
  unsigned __int64 v21; // rcx
  unsigned __int64 v22; // rdx
  __int16 v23; // ax
  unsigned __int64 v24; // rdx
  unsigned __int64 v25; // rcx
  __int16 v26; // ax
  unsigned __int64 v27; // rcx
  unsigned __int64 v28; // rdx
  unsigned __int64 v29; // rdx
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
  unsigned __int64 v44; // rdx
  unsigned __int64 v45; // rcx
  unsigned __int64 v46; // rcx
  unsigned __int64 v47; // rdx
  unsigned __int64 v48; // rax
  unsigned __int64 v49; // rbx
  unsigned __int64 v50; // rdx
  signed int v51; // er9
  char v52; // cl
  int v53; // esi
  unsigned __int64 v54; // rdx
  __int64 *v55; // r8
  __int64 v56; // r8
  __int64 *v57; // rax
  unsigned __int64 v58; // r8
  int v59; // er11
  unsigned __int64 v60; // rax
  double v61; // xmm7_8
  double v62; // xmm5_8
  unsigned __int64 v63; // [rsp+18h] [rbp-B0h]
  unsigned __int64 v64; // [rsp+20h] [rbp-A8h]
  unsigned __int64 v65; // [rsp+28h] [rbp-A0h]
  unsigned __int64 v66; // [rsp+30h] [rbp-98h]
  unsigned __int64 v67; // [rsp+38h] [rbp-90h]
  unsigned __int64 v68; // [rsp+40h] [rbp-88h]
  unsigned __int64 v69; // [rsp+48h] [rbp-80h]
  unsigned __int64 v70; // [rsp+50h] [rbp-78h]
  unsigned __int64 v71; // [rsp+58h] [rbp-70h]
  unsigned __int64 v72; // [rsp+60h] [rbp-68h]
  unsigned __int64 v73; // [rsp+68h] [rbp-60h]
  unsigned __int64 v74; // [rsp+70h] [rbp-58h]
  __int64 v75; // [rsp+78h] [rbp-50h]

  v4 = r;
  v74 = 0i64;
  v5 = *(_QWORD *)&x & 0xFFFFFFFFFFFFFi64 | 0x10000000000000i64;
  v6 = region;
  v7 = ((*(_QWORD *)&x >> 52) & 0x7FF) - 1023;
  v8 = rr;
  v9 = v7 / 10;
  v10 = v7 % 10;
  v11 = v9 + 18;
  v12 = (v5 * pibits_1[v11] >> 10) + v5 * pibits_1[v11 - 1];
  v13 = pibits_1[v11 - 2];
  v73 = LOWORD(x) * LOWORD(pibits_1[v11]) & 0x3FF;
  v14 = v12;
  v15 = (v12 >> 10) + v5 * v13;
  v16 = pibits_1[v11 - 3];
  v72 = v14 & 0x3FF;
  v17 = v15;
  v18 = (v15 >> 10) + v5 * v16;
  v19 = pibits_1[v11 - 4];
  v71 = v17 & 0x3FF;
  v20 = v18;
  v21 = (v18 >> 10) + v5 * v19;
  v22 = pibits_1[v11 - 5];
  v70 = v20 & 0x3FF;
  v23 = v21;
  v24 = (v21 >> 10) + v5 * v22;
  v25 = pibits_1[v11 - 6];
  v69 = v23 & 0x3FF;
  v26 = v24;
  v27 = (v24 >> 10) + v5 * v25;
  v28 = pibits_1[v11 - 7];
  v75 = v26 & 0x3FF;
  v29 = (v27 >> 10) + v5 * v28;
  v74 = v27 & 0x3FF;
  v73 = v29 & 0x3FF;
  v30 = (v29 >> 10) + v5 * pibits_1[v11 - 8];
  v31 = pibits_1[v11 - 9];
  v72 = v30 & 0x3FF;
  v32 = (v30 >> 10) + v5 * v31;
  v33 = pibits_1[v11 - 10];
  v71 = v32 & 0x3FF;
  v34 = (v32 >> 10) + v5 * v33;
  v35 = pibits_1[v11 - 11];
  v70 = v34 & 0x3FF;
  v36 = (v34 >> 10) + v5 * v35;
  v37 = pibits_1[v11 - 12];
  v69 = v36 & 0x3FF;
  v38 = (v36 >> 10) + v5 * v37;
  v39 = pibits_1[v11 - 13];
  v68 = v38 & 0x3FF;
  v40 = (v38 >> 10) + v5 * v39;
  v41 = pibits_1[v11 - 14];
  v67 = v40 & 0x3FF;
  v42 = (v40 >> 10) + v5 * v41;
  v43 = pibits_1[v11 - 15];
  v66 = v42 & 0x3FF;
  v44 = (v42 >> 10) + v5 * v43;
  v45 = pibits_1[v11 - 16];
  v65 = v44 & 0x3FF;
  v46 = (v44 >> 10) + v5 * v45;
  v47 = pibits_1[v11 - 18];
  v64 = v46 & 0x3FF;
  v48 = (v46 >> 10) + v5 * pibits_1[v11 - 17];
  v49 = v48 & 0x3FF;
  v63 = v48 & 0x3FF;
  v50 = ((v49 | ((((v48 >> 10) + v5 * v47) & 0x3FF) << 10)) >> (10 - (unsigned __int8)v10 - 1)) & 7;
  v51 = 1;
  v52 = 10 - v10;
  v53 = v50 & 1;
  if ( v50 & 1 )
  {
    *v6 = ((unsigned __int8)((signed int)v50 >> 1) + 1) & 3;
    v54 = ~v49 & ((1i64 << v52) - 1);
    if ( v54 < 0x20000000000000i64 )
    {
      v55 = (__int64 *)&v63;
      do
      {
        ++v55;
        ++v51;
        v54 = (v54 << 10) | ~*v55 & 0x3FF;
      }
      while ( v54 < 0x20000000000000i64 );
    }
    v56 = ~*(&v63 + v51);
  }
  else
  {
    *v6 = (signed int)v50 >> 1;
    v54 = v49 & ((1i64 << v52) - 1);
    if ( v54 < 0x20000000000000i64 )
    {
      v57 = (__int64 *)&v63;
      do
      {
        ++v57;
        ++v51;
        v54 = *v57 | (v54 << 10);
      }
      while ( v54 < 0x20000000000000i64 );
    }
    v56 = *(&v63 + v51);
  }
  v58 = v56 << 54;
  v59 = v10 - 10 * v51 + 52;
  while ( v54 >= 0x20000000000000i64 )
  {
    ++v59;
    v58 = (v58 >> 1) | (v54 << 63);
    v54 >>= 1;
  }
  v60 = v54 & 0xFFFFFFFFFFFFFi64 | ((v59 + 1023i64) << 52);
  if ( v53 )
    v60 = v54 & 0xFFFFFFFFFFFFFi64 | ((v59 + 1023i64) << 52) | 0x8000000000000000ui64;
  if ( v53 )
    v61 = (COERCE_DOUBLE(((v59 + 970i64) << 52) | (v58 >> 12)) - COERCE_DOUBLE((v59 + 970i64) << 52)) * -2.0;
  else
    v61 = (COERCE_DOUBLE(((v59 + 970i64) << 52) | (v58 >> 12)) - COERCE_DOUBLE((v59 + 970i64) << 52)) * 2.0;
  v62 = COERCE_DOUBLE(v60 & 0xFFFFFFFFF8000000ui64) * 1.570796310901642
      - *(double *)&v60 * 1.570796326794897
      + (*(double *)&v60 - COERCE_DOUBLE(v60 & 0xFFFFFFFFF8000000ui64)) * 1.570796310901642
      + COERCE_DOUBLE(v60 & 0xFFFFFFFFF8000000ui64) * 0.00000001589325471229586
      + (*(double *)&v60 - COERCE_DOUBLE(v60 & 0xFFFFFFFFF8000000ui64)) * 0.00000001589325471229586
      + v61 * 1.570796326794897
      + *(double *)&v60 * 6.123233995736765e-17;
  *v4 = v62 + *(double *)&v60 * 1.570796326794897;
  *v8 = *(double *)&v60 * 1.570796326794897 - (v62 + *(double *)&v60 * 1.570796326794897) + v62;
}

