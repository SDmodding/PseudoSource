// File Line: 106
// RVA: 0xEF31CC
void __fastcall MD5_Init(MD5_CTX *ctx)
{
  ctx->count[1] = 0;
  ctx->count[0] = 0;
  ctx->state[0] = 1732584193;
  ctx->state[1] = -271733879;
  ctx->state[2] = -1732584194;
  ctx->state[3] = 271733878;
}

// File Line: 121
// RVA: 0xEF31F0
void __fastcall MD5_Update(MD5_CTX *ctx, const char *msg, int len)
{
  MD5_CTX *v3; // rdi
  int v4; // esi
  unsigned int v5; // er9
  const char *v6; // rbp
  unsigned int v7; // ecx
  int v8; // ebx

  v3 = ctx;
  v4 = len;
  v5 = ctx->count[0] + 8 * len;
  v6 = msg;
  v7 = (ctx->count[0] >> 3) & 0x3F;
  v3->count[0] = v5;
  if ( v5 < 8 * len )
    ++v3->count[1];
  v8 = 64 - v7;
  v3->count[1] += (unsigned int)len >> 29;
  if ( len < (signed int)(64 - v7) )
  {
    v8 = 0;
  }
  else
  {
    memmove(&v3->buffer[v7], msg, v8);
    MD5Transform(v3->state, v3->buffer);
    while ( v8 + 63 < v4 )
    {
      MD5Transform(v3->state, &v6[v8]);
      v8 += 64;
    }
    v7 = 0;
  }
  memmove(&v3->buffer[v7], &v6[v8], v4 - v8);
}

// File Line: 157
// RVA: 0xEF30E4
void __fastcall MD5_Final(char *digest, MD5_CTX *ctx)
{
  __int64 v2; // rdi
  MD5_CTX *v3; // rbx
  char *v4; // rsi
  signed __int64 v5; // r9
  unsigned int v6; // er8
  char *v7; // rdx
  __int64 v8; // rcx
  unsigned int v9; // ecx
  int v10; // er8
  _BYTE *v11; // rdx
  signed __int64 v12; // r8
  char v13; // al
  char msg; // [rsp+20h] [rbp-18h]
  char v15; // [rsp+22h] [rbp-16h]

  v2 = 0i64;
  v3 = ctx;
  v4 = digest;
  v5 = 2i64;
  v6 = 0;
  v7 = &v15;
  do
  {
    v8 = v6++;
    *(v7 - 2) = v3->count[v8];
    *(v7 - 1) = BYTE1(v3->count[v8]);
    *v7 = BYTE2(v3->count[v8]);
    v7 += 4;
    *(v7 - 3) = HIBYTE(v3->count[v8]);
    --v5;
  }
  while ( v5 );
  v9 = (v3->count[0] >> 3) & 0x3F;
  v10 = 120 - v9;
  if ( v9 < 0x38 )
    v10 = 56 - v9;
  MD5_Update(v3, PADDING, v10);
  MD5_Update(v3, &msg, 8);
  v11 = v4 + 2;
  v12 = 4i64;
  do
  {
    *(v11 - 2) = v3->state[v2];
    *(v11 - 1) = BYTE1(v3->state[v2]);
    *v11 = BYTE2(v3->state[v2]);
    v13 = HIBYTE(v3->state[v2]);
    v2 = (unsigned int)(v2 + 1);
    v11[1] = v13;
    v11 += 4;
    --v12;
  }
  while ( v12 );
}

// File Line: 181
// RVA: 0xEF27F8
void __fastcall MD5Transform(unsigned int *state, const char *block)
{
  unsigned int v2; // edi
  unsigned int v3; // er10
  unsigned int v4; // er11
  unsigned int v5; // ebx
  __int64 v6; // r8
  const char *v7; // rdx
  signed __int64 v8; // r9
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // er8
  int v13; // er9
  int v14; // er10
  int v15; // er11
  int v16; // edx
  int v17; // er8
  int v18; // er9
  int v19; // er10
  int v20; // edx
  int v21; // edi
  int v22; // er9
  int v23; // er11
  int v24; // ebx
  int v25; // er8
  int v26; // er10
  int v27; // er9
  int v28; // er11
  int v29; // er8
  int v30; // edx
  int v31; // er10
  int v32; // er9
  int v33; // er11
  int v34; // er8
  int v35; // edx
  int v36; // er10
  int v37; // er9
  int v38; // er11
  int v39; // ebx
  int v40; // edx
  int v41; // er8
  int v42; // er9
  int v43; // er10
  int v44; // edx
  int v45; // er8
  int v46; // er9
  int v47; // er10
  int v48; // er11
  int v49; // edx
  int v50; // er8
  int v51; // er9
  int v52; // er10
  int v53; // er11
  int v54; // er8
  int v55; // edx
  int v56; // er9
  int v57; // ecx
  int v58; // er10
  int v59; // er8
  int v60; // edx
  int v61; // er9
  int v62; // ecx
  int v63; // er10
  int v64; // er8
  int v65; // edx
  int v66; // er9
  int v67; // ecx
  int v68; // er10
  int v69; // er8
  int v70; // edx
  int v71; // er11
  int v72; // er9
  int v73; // ecx
  int v74; // er8
  int v75; // edx
  int v76; // eax
  unsigned int *v77; // r9
  int v78; // edx
  int v79; // ecx
  unsigned int v80; // [rsp+0h] [rbp-60h]
  unsigned int *v81; // [rsp+8h] [rbp-58h]
  int v82; // [rsp+10h] [rbp-50h]
  int v83; // [rsp+14h] [rbp-4Ch]
  int v84; // [rsp+18h] [rbp-48h]
  int v85; // [rsp+1Ch] [rbp-44h]
  int v86; // [rsp+20h] [rbp-40h]
  int v87; // [rsp+24h] [rbp-3Ch]
  int v88; // [rsp+28h] [rbp-38h]
  int v89; // [rsp+2Ch] [rbp-34h]
  int v90; // [rsp+30h] [rbp-30h]
  int v91; // [rsp+34h] [rbp-2Ch]
  int v92; // [rsp+38h] [rbp-28h]
  int v93; // [rsp+3Ch] [rbp-24h]
  int v94; // [rsp+40h] [rbp-20h]
  int v95; // [rsp+44h] [rbp-1Ch]
  int v96; // [rsp+48h] [rbp-18h]
  int v97; // [rsp+4Ch] [rbp-14h]

  v2 = *state;
  v3 = state[1];
  v4 = state[2];
  v5 = state[3];
  v6 = 0i64;
  v80 = *state;
  v81 = state;
  v7 = block + 2;
  v8 = 16i64;
  do
  {
    v9 = *(unsigned __int8 *)v7;
    v10 = *((unsigned __int8 *)v7 + 1);
    v7 += 4;
    *(&v82 + v6) = *((unsigned __int8 *)v7 - 6) | ((*((unsigned __int8 *)v7 - 5) | ((v9 | (v10 << 8)) << 8)) << 8);
    v6 = (unsigned int)(v6 + 1);
    --v8;
  }
  while ( v8 );
  v11 = v3 + __ROL4__(v2 + v82 + (v3 & v4 | v5 & ~v3) - 680876936, 7);
  v12 = v11
      + __ROL4__(
          v5 + v83 + (v11 & v3 | v4 & ~(v3 + __ROL4__(v2 + v82 + (v3 & v4 | v5 & ~v3) - 680876936, 7))) - 389564586,
          12);
  v13 = v12 + __ROR4__(v4 + 606105819 + v84 + (v11 & v12 | v3 & ~v12), 15);
  v14 = v13 + __ROR4__(v85 + (v13 & v12 | v11 & ~v13) + v3 - 1044525330, 10);
  v15 = v14 + __ROL4__(v11 - 176418897 + v86 + (v14 & v13 | v12 & ~v14), 7);
  v16 = v15 + __ROL4__(v12 + 1200080426 + v87 + (v15 & v14 | v13 & ~v15), 12);
  v17 = v16 + __ROR4__(v13 - 1473231341 + v88 + (v15 & v16 | v14 & ~v16), 15);
  v18 = v17
      + __ROR4__(
          v14
        - 45705983
        + v89
        + (v17 & v16 | v15 & ~(v16 + __ROR4__(v13 - 1473231341 + v88 + (v15 & v16 | v14 & ~v16), 15))),
          10);
  v19 = v18 + __ROL4__(v15 + v90 + (v18 & v17 | v16 & ~v18) + 1770035416, 7);
  v20 = v19
      + __ROL4__(
          v91
        + (v19 & v18 | v17 & ~(v18 + __ROL4__(v15 + v90 + (v18 & v17 | v16 & ~v18) + 1770035416, 7)))
        - 1958414417
        + v16,
          12);
  v21 = v20 + __ROR4__(v17 + v92 + (v19 & v20 | v18 & ~v20) - 42063, 15);
  v22 = v21 + __ROR4__(v93 + (v21 & v20 | v19 & ~v21) + v18 - 1990404162, 10);
  v23 = v22 + __ROL4__(v19 + 1804603682 + v94 + (v22 & v21 | v20 & ~v22), 7);
  v24 = v23 + __ROL4__(v20 - 40341101 + v95 + (v23 & v22 | v21 & ~v23), 12);
  v25 = ~(v23 + __ROL4__(v20 - 40341101 + v95 + (v23 & v22 | v21 & ~v23), 12));
  v26 = v24 + __ROR4__(v21 - 1502002290 + v96 + (v23 & v24 | v22 & v25), 15);
  v27 = v26 + __ROR4__(v97 + (v26 & v24 | v23 & ~v26) + v22 + 1236535329, 10);
  v28 = v27 + __ROL4__(v83 + (v27 & v24 | v26 & v25) - 165796510 + v23, 5);
  v29 = v28 + __ROL4__(v24 + v88 + (v27 & ~v26 | v28 & v26) - 1069501632, 9);
  v30 = v29 + __ROL4__(v26 + 643717713 + v93 + (v27 & v29 | v28 & ~v27), 14);
  v31 = v30 + __ROR4__(v27 - 373897302 + v82 + (v28 & v30 | v29 & ~v28), 12);
  v32 = v31 + __ROL4__(v28 - 701558691 + v87 + (v31 & v29 | v30 & ~v29), 5);
  v33 = v32 + __ROL4__(v29 + 38016083 + v92 + (v32 & v30 | v31 & ~v30), 9);
  v34 = v33 + __ROL4__(v30 - 660478335 + v97 + (v31 & v33 | v32 & ~v31), 14);
  v35 = v34 + __ROR4__(v31 - 405537848 + v86 + (v32 & v34 | v33 & ~v32), 12);
  v36 = v35 + __ROL4__(v32 + 568446438 + v91 + (v35 & v33 | v34 & ~v33), 5);
  v37 = v36 + __ROL4__(v33 - 1019803690 + v96 + (v36 & v34 | v35 & ~v34), 9);
  v38 = v37 + __ROL4__(v34 - 187363961 + v85 + (v35 & v37 | v36 & ~v35), 14);
  v39 = v38 + __ROR4__(v35 + 1163531501 + v90 + (v36 & v38 | v37 & ~v36), 12);
  v40 = v39 + __ROL4__(v36 - 1444681467 + v95 + (v39 & v37 | v38 & ~v37), 5);
  v41 = v40 + __ROL4__(v37 - 51403784 + v84 + (v40 & v38 | v39 & ~v38), 9);
  v42 = v41 + __ROL4__(v38 + v89 + (v39 & v41 | v40 & ~v39) + 1735328473, 14);
  v43 = v42
      + __ROR4__(
          v39
        + v94
        + (v40 & (v41 + __ROL4__(v38 + v89 + (v39 & v41 | v40 & ~v39) + 1735328473, 14)) | v41 & ~v40)
        - 1926607734,
          12);
  v44 = v43 + __ROL4__(v87 + (v43 ^ v42 ^ v41) - 378558 + v40, 4);
  v45 = v44 + __ROL4__(v90 + (v44 ^ v43 ^ v42) - 2022574463 + v41, 11);
  v46 = v45 + __ROL4__(v93 + (v44 ^ v43 ^ v45) + 1839030562 + v42, 16);
  v47 = v46 + __ROR4__(v96 + (v44 ^ v46 ^ v45) + v43 - 35309556, 9);
  v48 = v47 + __ROL4__(v44 + v83 + (v47 ^ v46 ^ v45) - 1530992060, 4);
  v49 = v48 + __ROL4__(v45 + 1272893353 + v86 + (v48 ^ v47 ^ v46), 11);
  v50 = v49
      + __ROL4__(
          v46 - 155497632 + v89 + (v48 ^ v47 ^ (v48 + __ROL4__(v45 + 1272893353 + v86 + (v48 ^ v47 ^ v46), 11))),
          16);
  v51 = v50 + __ROR4__(v47 - 1094730640 + v92 + (v48 ^ v50 ^ v49), 9);
  v52 = v51 + __ROL4__(v48 + 681279174 + (v51 ^ v50 ^ v49) + v95, 4);
  v53 = v52 + __ROL4__(v49 - 358537222 + v82 + (v52 ^ v51 ^ v50), 11);
  v54 = v53 + __ROL4__(v85 + (v52 ^ v51 ^ v53) + v50 - 722521979, 16);
  v55 = v54 + __ROR4__(v51 + 76029189 + v88 + (v52 ^ v54 ^ v53), 9);
  v56 = v55 + __ROL4__(v52 + v91 + (v55 ^ v54 ^ v53) - 640364487, 4);
  v57 = v56 + __ROL4__(v53 + v94 + (v56 ^ v55 ^ v54) - 421815835, 11);
  v58 = v57 + __ROL4__(v54 + 530742520 + v97 + (v56 ^ v55 ^ v57), 16);
  v59 = v58 + __ROR4__(v55 - 995338651 + v84 + (v56 ^ v58 ^ v57), 9);
  v60 = v59 + __ROL4__(v56 - 198630844 + v82 + (v58 ^ (v59 | ~v57)), 6);
  v61 = v60 + __ROL4__(v57 + 1126891415 + v89 + (v59 ^ (v60 | ~v58)), 10);
  v62 = v61 + __ROL4__(v58 - 1416354905 + v96 + (v60 ^ (v61 | ~v59)), 15);
  v63 = v62 + __ROR4__(v59 - 57434055 + v87 + (v61 ^ (v62 | ~v60)), 11);
  v64 = v63 + __ROL4__(v60 + 1700485571 + v94 + (v62 ^ (v63 | ~v61)), 6);
  v65 = v64 + __ROL4__(v61 - 1894986606 + v85 + (v63 ^ (v64 | ~v62)), 10);
  v66 = v65 + __ROL4__(v62 - 1051523 + v92 + (v64 ^ (v65 | ~v63)), 15);
  v67 = v66 + __ROR4__(v63 - 2054922799 + v83 + (v65 ^ (v66 | ~v64)), 11);
  v68 = v67 + __ROL4__(v64 + 1873313359 + v90 + (v66 ^ (v67 | ~v65)), 6);
  v69 = v68 + __ROL4__(v65 - 30611744 + v97 + (v67 ^ (v68 | ~v66)), 10);
  v70 = v69 + __ROL4__(v66 - 1560198380 + v88 + (v68 ^ (v69 | ~v67)), 15);
  v71 = v70 + __ROR4__(v67 + 1309151649 + v95 + (v69 ^ (v70 | ~v68)), 11);
  v72 = v71 + __ROL4__(v68 + v86 + (v70 ^ (v71 | ~v69)) - 145523070, 6);
  v73 = ~(v71 + __ROL4__(v68 + v86 + (v70 ^ (v71 | ~v69)) - 145523070, 6));
  v74 = v72 + __ROL4__(v93 + (v71 ^ (v72 | ~v70)) - 1120210379 + v69, 10);
  v75 = v84 + (v72 ^ (v74 | ~v71)) + 718787259 + v70;
  v76 = v72 + v80;
  v77 = v81;
  *v81 = v76;
  v78 = v74 + __ROL4__(v75, 15);
  v77[2] += v78;
  v79 = v78 + v81[1] + __ROR4__(v71 - 343485551 + v91 + (v74 ^ (v78 | v73)), 11);
  v77[3] += v74;
  v81[1] = v79;
}

