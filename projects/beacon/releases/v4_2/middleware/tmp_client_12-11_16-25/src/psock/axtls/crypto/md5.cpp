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
void __fastcall MD5_Update(MD5_CTX *ctx, const char *msg, unsigned int len)
{
  unsigned int v5; // r9d
  unsigned int v7; // ecx
  signed int v8; // ebx

  v5 = ctx->count[0] + 8 * len;
  v7 = (ctx->count[0] >> 3) & 0x3F;
  ctx->count[0] = v5;
  if ( v5 < 8 * len )
    ++ctx->count[1];
  v8 = 64 - v7;
  ctx->count[1] += len >> 29;
  if ( (int)len < (int)(64 - v7) )
  {
    v8 = 0;
  }
  else
  {
    memmove(&ctx->buffer[v7], msg, v8);
    MD5Transform(ctx->state, ctx->buffer);
    while ( v8 + 63 < (int)len )
    {
      MD5Transform(ctx->state, &msg[v8]);
      v8 += 64;
    }
    v7 = 0;
  }
  memmove(&ctx->buffer[v7], &msg[v8], (int)(len - v8));
}

// File Line: 157
// RVA: 0xEF30E4
void __fastcall MD5_Final(char *digest, MD5_CTX *ctx)
{
  __int64 v2; // rdi
  __int64 v5; // r9
  unsigned int v6; // r8d
  char *v7; // rdx
  __int64 v8; // rcx
  unsigned int v9; // ecx
  int v10; // r8d
  char *v11; // rdx
  __int64 v12; // r8
  char v13; // al
  char msg[2]; // [rsp+20h] [rbp-18h] BYREF
  char v15; // [rsp+22h] [rbp-16h] BYREF

  v2 = 0i64;
  v5 = 2i64;
  v6 = 0;
  v7 = &v15;
  do
  {
    v8 = v6++;
    *(v7 - 2) = ctx->count[v8];
    *(v7 - 1) = BYTE1(ctx->count[v8]);
    *v7 = BYTE2(ctx->count[v8]);
    v7 += 4;
    *(v7 - 3) = HIBYTE(ctx->count[v8]);
    --v5;
  }
  while ( v5 );
  v9 = (ctx->count[0] >> 3) & 0x3F;
  v10 = 120 - v9;
  if ( v9 < 0x38 )
    v10 = 56 - v9;
  MD5_Update(ctx, PADDING, v10);
  MD5_Update(ctx, msg, 8);
  v11 = digest + 2;
  v12 = 4i64;
  do
  {
    *(v11 - 2) = ctx->state[v2];
    *(v11 - 1) = BYTE1(ctx->state[v2]);
    *v11 = BYTE2(ctx->state[v2]);
    v13 = HIBYTE(ctx->state[v2]);
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
  int v2; // edi
  unsigned int v3; // r10d
  unsigned int v4; // r11d
  unsigned int v5; // ebx
  __int64 v6; // r8
  const char *v7; // rdx
  __int64 v8; // r9
  int v9; // eax
  int v10; // ecx
  unsigned int v11; // edx
  unsigned int v12; // r8d
  unsigned int v13; // r9d
  unsigned int v14; // r10d
  unsigned int v15; // r11d
  unsigned int v16; // edx
  unsigned int v17; // r8d
  unsigned int v18; // r9d
  unsigned int v19; // r10d
  int v20; // edx
  int v21; // edi
  int v22; // r9d
  int v23; // r11d
  int v24; // ebx
  int v25; // r10d
  int v26; // r9d
  int v27; // r11d
  int v28; // r8d
  int v29; // edx
  int v30; // r10d
  int v31; // r9d
  int v32; // r11d
  int v33; // r8d
  int v34; // edx
  int v35; // r10d
  int v36; // r9d
  int v37; // r11d
  int v38; // ebx
  int v39; // edx
  int v40; // r8d
  int v41; // r9d
  int v42; // r10d
  int v43; // edx
  int v44; // r8d
  int v45; // r9d
  int v46; // r10d
  int v47; // r11d
  int v48; // edx
  int v49; // r8d
  int v50; // r9d
  int v51; // r10d
  int v52; // r11d
  int v53; // r8d
  int v54; // edx
  int v55; // r9d
  int v56; // ecx
  int v57; // r10d
  int v58; // r8d
  int v59; // edx
  int v60; // r9d
  int v61; // ecx
  int v62; // r10d
  int v63; // r8d
  int v64; // edx
  int v65; // r9d
  int v66; // ecx
  int v67; // r10d
  int v68; // r8d
  int v69; // edx
  int v70; // r11d
  int v71; // r9d
  int v72; // r8d
  int v73; // edx
  int v74; // edx
  unsigned int v75; // ecx
  int v76; // [rsp+0h] [rbp-60h]
  int v78; // [rsp+10h] [rbp-50h]
  int v79; // [rsp+14h] [rbp-4Ch]
  int v80; // [rsp+18h] [rbp-48h]
  int v81; // [rsp+1Ch] [rbp-44h]
  int v82; // [rsp+20h] [rbp-40h]
  int v83; // [rsp+24h] [rbp-3Ch]
  int v84; // [rsp+28h] [rbp-38h]
  int v85; // [rsp+2Ch] [rbp-34h]
  int v86; // [rsp+30h] [rbp-30h]
  int v87; // [rsp+34h] [rbp-2Ch]
  int v88; // [rsp+38h] [rbp-28h]
  int v89; // [rsp+3Ch] [rbp-24h]
  int v90; // [rsp+40h] [rbp-20h]
  int v91; // [rsp+44h] [rbp-1Ch]
  int v92; // [rsp+48h] [rbp-18h]
  int v93; // [rsp+4Ch] [rbp-14h]

  v2 = *state;
  v3 = state[1];
  v4 = state[2];
  v5 = state[3];
  v6 = 0i64;
  v76 = *state;
  v7 = block + 2;
  v8 = 16i64;
  do
  {
    v9 = *(unsigned __int8 *)v7;
    v10 = *((unsigned __int8 *)v7 + 1);
    v7 += 4;
    *(&v78 + v6) = *((unsigned __int8 *)v7 - 6) | ((*((unsigned __int8 *)v7 - 5) | ((v9 | (v10 << 8)) << 8)) << 8);
    v6 = (unsigned int)(v6 + 1);
    --v8;
  }
  while ( v8 );
  v11 = v3 + __ROL4__(v2 + v78 + (v3 & v4 | v5 & ~v3) - 680876936, 7);
  v12 = v11 + __ROL4__(v5 + v79 + (v11 & v3 | v4 & ~v11) - 389564586, 12);
  v13 = v12 + __ROR4__(v4 + 606105819 + v80 + (v11 & v12 | v3 & ~v12), 15);
  v14 = v13 + __ROR4__(v81 + (v13 & v12 | v11 & ~v13) + v3 - 1044525330, 10);
  v15 = v14 + __ROL4__(v11 - 176418897 + v82 + (v14 & v13 | v12 & ~v14), 7);
  v16 = v15 + __ROL4__(v12 + 1200080426 + v83 + (v15 & v14 | v13 & ~v15), 12);
  v17 = v16 + __ROR4__(v13 - 1473231341 + v84 + (v15 & v16 | v14 & ~v16), 15);
  v18 = v17 + __ROR4__(v14 - 45705983 + v85 + (v17 & v16 | v15 & ~v17), 10);
  v19 = v18 + __ROL4__(v15 + v86 + (v18 & v17 | v16 & ~v18) + 1770035416, 7);
  v20 = v19 + __ROL4__(v87 + (v19 & v18 | v17 & ~v19) - 1958414417 + v16, 12);
  v21 = v20 + __ROR4__(v17 + v88 + (v19 & v20 | v18 & ~v20) - 42063, 15);
  v22 = v21 + __ROR4__(v89 + (v21 & v20 | v19 & ~v21) + v18 - 1990404162, 10);
  v23 = v22 + __ROL4__(v19 + 1804603682 + v90 + (v22 & v21 | v20 & ~v22), 7);
  v24 = v23 + __ROL4__(v20 - 40341101 + v91 + (v23 & v22 | v21 & ~v23), 12);
  v25 = v24 + __ROR4__(v21 - 1502002290 + v92 + (v23 & v24 | v22 & ~v24), 15);
  v26 = v25 + __ROR4__(v93 + (v25 & v24 | v23 & ~v25) + v22 + 1236535329, 10);
  v27 = v26 + __ROL4__(v79 + (v26 & v24 | v25 & ~v24) - 165796510 + v23, 5);
  v28 = v27 + __ROL4__(v24 + v84 + (v26 & ~v25 | v27 & v25) - 1069501632, 9);
  v29 = v28 + __ROL4__(v25 + 643717713 + v89 + (v26 & v28 | v27 & ~v26), 14);
  v30 = v29 + __ROR4__(v26 - 373897302 + v78 + (v27 & v29 | v28 & ~v27), 12);
  v31 = v30 + __ROL4__(v27 - 701558691 + v83 + (v30 & v28 | v29 & ~v28), 5);
  v32 = v31 + __ROL4__(v28 + 38016083 + v88 + (v31 & v29 | v30 & ~v29), 9);
  v33 = v32 + __ROL4__(v29 - 660478335 + v93 + (v30 & v32 | v31 & ~v30), 14);
  v34 = v33 + __ROR4__(v30 - 405537848 + v82 + (v31 & v33 | v32 & ~v31), 12);
  v35 = v34 + __ROL4__(v31 + 568446438 + v87 + (v34 & v32 | v33 & ~v32), 5);
  v36 = v35 + __ROL4__(v32 - 1019803690 + v92 + (v35 & v33 | v34 & ~v33), 9);
  v37 = v36 + __ROL4__(v33 - 187363961 + v81 + (v34 & v36 | v35 & ~v34), 14);
  v38 = v37 + __ROR4__(v34 + 1163531501 + v86 + (v35 & v37 | v36 & ~v35), 12);
  v39 = v38 + __ROL4__(v35 - 1444681467 + v91 + (v38 & v36 | v37 & ~v36), 5);
  v40 = v39 + __ROL4__(v36 - 51403784 + v80 + (v39 & v37 | v38 & ~v37), 9);
  v41 = v40 + __ROL4__(v37 + v85 + (v38 & v40 | v39 & ~v38) + 1735328473, 14);
  v42 = v41 + __ROR4__(v38 + v90 + (v39 & v41 | v40 & ~v39) - 1926607734, 12);
  v43 = v42 + __ROL4__(v83 + (v42 ^ v41 ^ v40) - 378558 + v39, 4);
  v44 = v43 + __ROL4__(v86 + (v43 ^ v42 ^ v41) - 2022574463 + v40, 11);
  v45 = v44 + __ROL4__(v89 + (v43 ^ v42 ^ v44) + 1839030562 + v41, 16);
  v46 = v45 + __ROR4__(v92 + (v43 ^ v45 ^ v44) + v42 - 35309556, 9);
  v47 = v46 + __ROL4__(v43 + v79 + (v46 ^ v45 ^ v44) - 1530992060, 4);
  v48 = v47 + __ROL4__(v44 + 1272893353 + v82 + (v47 ^ v46 ^ v45), 11);
  v49 = v48 + __ROL4__(v45 - 155497632 + v85 + (v47 ^ v46 ^ v48), 16);
  v50 = v49 + __ROR4__(v46 - 1094730640 + v88 + (v47 ^ v49 ^ v48), 9);
  v51 = v50 + __ROL4__(v47 + 681279174 + (v50 ^ v49 ^ v48) + v91, 4);
  v52 = v51 + __ROL4__(v48 - 358537222 + v78 + (v51 ^ v50 ^ v49), 11);
  v53 = v52 + __ROL4__(v81 + (v51 ^ v50 ^ v52) + v49 - 722521979, 16);
  v54 = v53 + __ROR4__(v50 + 76029189 + v84 + (v51 ^ v53 ^ v52), 9);
  v55 = v54 + __ROL4__(v51 + v87 + (v54 ^ v53 ^ v52) - 640364487, 4);
  v56 = v55 + __ROL4__(v52 + v90 + (v55 ^ v54 ^ v53) - 421815835, 11);
  v57 = v56 + __ROL4__(v53 + 530742520 + v93 + (v55 ^ v54 ^ v56), 16);
  v58 = v57 + __ROR4__(v54 - 995338651 + v80 + (v55 ^ v57 ^ v56), 9);
  v59 = v58 + __ROL4__(v55 - 198630844 + v78 + (v57 ^ (v58 | ~v56)), 6);
  v60 = v59 + __ROL4__(v56 + 1126891415 + v85 + (v58 ^ (v59 | ~v57)), 10);
  v61 = v60 + __ROL4__(v57 - 1416354905 + v92 + (v59 ^ (v60 | ~v58)), 15);
  v62 = v61 + __ROR4__(v58 - 57434055 + v83 + (v60 ^ (v61 | ~v59)), 11);
  v63 = v62 + __ROL4__(v59 + 1700485571 + v90 + (v61 ^ (v62 | ~v60)), 6);
  v64 = v63 + __ROL4__(v60 - 1894986606 + v81 + (v62 ^ (v63 | ~v61)), 10);
  v65 = v64 + __ROL4__(v61 - 1051523 + v88 + (v63 ^ (v64 | ~v62)), 15);
  v66 = v65 + __ROR4__(v62 - 2054922799 + v79 + (v64 ^ (v65 | ~v63)), 11);
  v67 = v66 + __ROL4__(v63 + 1873313359 + v86 + (v65 ^ (v66 | ~v64)), 6);
  v68 = v67 + __ROL4__(v64 - 30611744 + v93 + (v66 ^ (v67 | ~v65)), 10);
  v69 = v68 + __ROL4__(v65 - 1560198380 + v84 + (v67 ^ (v68 | ~v66)), 15);
  v70 = v69 + __ROR4__(v66 + 1309151649 + v91 + (v68 ^ (v69 | ~v67)), 11);
  v71 = v70 + __ROL4__(v67 + v82 + (v69 ^ (v70 | ~v68)) - 145523070, 6);
  v72 = v71 + __ROL4__(v89 + (v70 ^ (v71 | ~v69)) - 1120210379 + v68, 10);
  v73 = v80 + (v71 ^ (v72 | ~v70)) + 718787259 + v69;
  *state = v71 + v76;
  v74 = v72 + __ROL4__(v73, 15);
  state[2] += v74;
  v75 = v74 + state[1] + __ROR4__(v70 - 343485551 + v87 + (v72 ^ (v74 | ~v71)), 11);
  state[3] += v72;
  state[1] = v75;
}

