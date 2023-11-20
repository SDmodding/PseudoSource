// File Line: 183
// RVA: 0xEF3A98
void __fastcall AES_set_key(aes_key_st *ctx, const char *key, const char *iv, AES_MODE mode)
{
  const char *v4; // rbp
  aes_key_st *v5; // r11
  unsigned __int16 v6; // ax
  signed int v7; // er8
  unsigned int *v8; // r10
  const char *v9; // rdx
  _DWORD *v10; // r9
  __int64 v11; // rbx
  int v12; // ecx
  int v13; // eax
  const char *v14; // r14
  int v15; // ebx
  int v16; // edi
  unsigned int v17; // er9

  v4 = iv;
  v5 = ctx;
  if ( mode )
  {
    if ( mode != 1 )
      return;
    v6 = 14;
    v7 = 8;
  }
  else
  {
    v6 = 10;
    v7 = 4;
  }
  ctx->rounds = v6;
  ctx->key_size = v7;
  v8 = ctx->ks;
  if ( v7 > 0 )
  {
    v9 = key + 2;
    v10 = ctx->ks;
    v11 = ((unsigned int)(v7 - 1) >> 1) + 1;
    do
    {
      v12 = *((unsigned __int8 *)v9 - 1) | (*((unsigned __int8 *)v9 - 2) << 8);
      v13 = *(unsigned __int8 *)v9;
      v9 += 8;
      *v10 = *((unsigned __int8 *)v9 - 7) | ((v13 | (v12 << 8)) << 8);
      v10 += 2;
      *(v10 - 1) = *((unsigned __int8 *)v9 - 3) | ((*((unsigned __int8 *)v9 - 4) | ((*((unsigned __int8 *)v9 - 5) | (*((unsigned __int8 *)v9 - 6) << 8)) << 8)) << 8);
      --v11;
    }
    while ( v11 );
  }
  v14 = Rcon;
  v15 = v7;
  v16 = 4 * v5->rounds + 4;
  if ( v7 < v16 )
  {
    do
    {
      v17 = v8[v7 - 1];
      if ( !(v15 % v7) )
        v17 = (*(unsigned __int8 *)v14++ << 24) ^ ((unsigned __int8)aes_sbox[(unsigned __int64)v17 >> 24] | (((unsigned __int8)aes_sbox[(unsigned __int8)v17] | (((unsigned __int8)aes_sbox[BYTE1(v17)] | ((unsigned __int8)aes_sbox[BYTE2(v17)] << 8)) << 8)) << 8));
      if ( v7 == 8 && v15 % 8 == 4 )
        v17 = (unsigned __int8)aes_sbox[(unsigned __int8)v17] | (((unsigned __int8)aes_sbox[BYTE1(v17)] | ((((unsigned __int8)aes_sbox[(unsigned __int64)v17 >> 24] << 8) | (unsigned __int8)aes_sbox[BYTE2(v17)]) << 8)) << 8);
      ++v15;
      v8[v7] = v17 ^ *v8;
      ++v8;
    }
    while ( v15 < v16 );
  }
  memmove(v5->iv, v4, 0x10ui64);
}

// File Line: 257
// RVA: 0xEF3564
void __fastcall AES_convert_key(aes_key_st *ctx)
{
  unsigned int *v1; // r10
  int v2; // eax
  __int64 v3; // r11
  unsigned int v4; // er8
  unsigned int v5; // er9
  unsigned int v6; // edx
  unsigned int v7; // eax

  v1 = &ctx->ks[4];
  v2 = 4 * ctx->rounds;
  if ( v2 > 4 )
  {
    v3 = (unsigned int)(v2 - 4);
    do
    {
      v4 = *v1;
      v5 = 2 * v4 & 0xFEFEFEFE ^ ((*v1 & 0x80808080) - ((*v1 & 0x80808080) >> 7)) & 0x1B1B1B1B;
      v6 = 2 * v5 & 0xFEFEFEFE ^ ((v5 & 0x80808080) - ((v5 & 0x80808080) >> 7)) & 0x1B1B1B1B;
      v7 = v4 ^ 2 * v6 & 0xFEFEFEFE ^ (((2 * v5 & 0xFEFEFEFE ^ ((v5 & 0x80808080) - ((v5 & 0x80808080) >> 7)) & 0x1B1B1B1B) & 0x80808080)
                                     - (((2 * v5 & 0xFEFEFEFE ^ ((v5 & 0x80808080) - ((v5 & 0x80808080) >> 7)) & 0x1B1B1B1B) & 0x80808080) >> 7)) & 0x1B1B1B1B;
      *v1 = v5 ^ v6 ^ 2 * v6 & 0xFEFEFEFE ^ (((2 * v5 & 0xFEFEFEFE ^ ((v5 & 0x80808080) - ((v5 & 0x80808080) >> 7)) & 0x1B1B1B1B) & 0x80808080)
                                           - (((2 * v5 & 0xFEFEFEFE ^ ((v5 & 0x80808080) - ((v5 & 0x80808080) >> 7)) & 0x1B1B1B1B) & 0x80808080) >> 7)) & 0x1B1B1B1B ^ __ROL4__(v7 ^ v5, 8) ^ __ROL4__(v7 ^ v6, 16) ^ __ROR4__(v7, 8);
      ++v1;
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 276
// RVA: 0xEF3414
void __fastcall AES_cbc_encrypt(aes_key_st *ctx, const char *msg, char *out, int length)
{
  char *v4; // r13
  char *v5; // r15
  const char *v6; // r12
  int v7; // esi
  signed __int64 v8; // rbx
  signed __int64 v9; // rdi
  u_long v10; // eax
  int v11; // esi
  aes_key_st *v12; // r13
  unsigned __int64 v13; // rsi
  signed __int64 v14; // rdi
  u_long v15; // eax
  __int64 v16; // rdi
  signed __int64 v17; // r14
  u_long v18; // ecx
  u_long v19; // eax
  int v20; // [rsp+1Ch] [rbp-64h]
  u_long hostlong[4]; // [rsp+20h] [rbp-60h]
  char *v22; // [rsp+30h] [rbp-50h]
  aes_key_st *ctxa; // [rsp+38h] [rbp-48h]
  int v24; // [rsp+44h] [rbp-3Ch]
  int Dst[4]; // [rsp+48h] [rbp-38h]
  u_long netlong[3]; // [rsp+58h] [rbp-28h]
  int v27; // [rsp+64h] [rbp-1Ch]
  char Src; // [rsp+68h] [rbp-18h]

  v4 = ctx->iv;
  ctxa = ctx;
  v5 = out;
  v6 = msg;
  v7 = length;
  v22 = ctx->iv;
  memmove(Dst, ctx->iv, 0x10ui64);
  v8 = 0i64;
  v9 = 0i64;
  do
  {
    v10 = ntohl_0(Dst[v9]);
    ++v9;
    *(int *)((char *)&v20 + v9 * 4) = v10;
  }
  while ( v9 < 4 );
  v11 = v7 - 16;
  if ( v11 >= 0 )
  {
    v12 = ctxa;
    v13 = (unsigned __int64)(unsigned int)(v11 + 16) >> 4;
    do
    {
      memmove(netlong, v6, 0x10ui64);
      v6 += 16;
      v14 = 0i64;
      do
      {
        v15 = ntohl_0(netlong[v14]);
        ++v14;
        *(_DWORD *)((char *)&v22 + v14 * 4 + 4) = *(int *)((char *)&v20 + v14 * 4) ^ v15;
      }
      while ( v14 < 4 );
      AES_encrypt(v12, (unsigned int *)&ctxa);
      v16 = 0i64;
      v17 = 4i64;
      do
      {
        v18 = *(_DWORD *)((char *)&ctxa + v16 * 4);
        hostlong[v16] = v18;
        ++v16;
        *(int *)((char *)&v27 + v16 * 4) = htonl_0(v18);
        --v17;
      }
      while ( v17 );
      memmove(v5, &Src, 0x10ui64);
      v5 += 16;
      --v13;
    }
    while ( v13 );
    v4 = v22;
  }
  do
  {
    v19 = htonl_0(hostlong[v8]);
    ++v8;
    *(int *)((char *)&v24 + v8 * 4) = v19;
  }
  while ( v8 < 4 );
  memmove(v4, Dst, 0x10ui64);
}

// File Line: 315
// RVA: 0xEF32B0
void __fastcall AES_cbc_decrypt(aes_key_st *ctx, const char *msg, char *out, int length)
{
  char *v4; // r13
  char *v5; // r15
  const char *v6; // r12
  int v7; // esi
  signed __int64 v8; // rbx
  signed __int64 v9; // rdi
  u_long v10; // eax
  int v11; // esi
  aes_key_st *v12; // r13
  unsigned __int64 v13; // rsi
  signed __int64 v14; // r14
  __int64 v15; // rdi
  u_long v16; // eax
  __int64 v17; // rdi
  signed __int64 v18; // r14
  u_long v19; // ecx
  u_long v20; // eax
  int v21; // [rsp+1Ch] [rbp-5Dh]
  u_long hostlong[4]; // [rsp+20h] [rbp-59h]
  char *v23; // [rsp+30h] [rbp-49h]
  int v24[7]; // [rsp+38h] [rbp-41h]
  int v25; // [rsp+54h] [rbp-25h]
  aes_key_st *ctxa; // [rsp+58h] [rbp-21h]
  int v27; // [rsp+64h] [rbp-15h]
  int Dst[3]; // [rsp+68h] [rbp-11h]
  int v29; // [rsp+74h] [rbp-5h]
  char Src; // [rsp+78h] [rbp-1h]
  u_long netlong[4]; // [rsp+88h] [rbp+Fh]

  v4 = ctx->iv;
  ctxa = ctx;
  v5 = out;
  v6 = msg;
  v7 = length;
  v23 = ctx->iv;
  memmove(Dst, ctx->iv, 0x10ui64);
  v8 = 0i64;
  v9 = 0i64;
  do
  {
    v10 = ntohl_0(Dst[v9]);
    ++v9;
    *(int *)((char *)&v21 + v9 * 4) = v10;
  }
  while ( v9 < 4 );
  v11 = v7 - 16;
  if ( v11 >= 0 )
  {
    v12 = ctxa;
    v13 = (unsigned __int64)(unsigned int)(v11 + 16) >> 4;
    do
    {
      memmove(netlong, v6, 0x10ui64);
      v6 += 16;
      v14 = 4i64;
      v15 = 0i64;
      do
      {
        v16 = ntohl_0(netlong[v15]);
        ++v15;
        *(_DWORD *)((char *)&v23 + v15 * 4 + 4) = v16;
        *(int *)((char *)&v25 + v15 * 4) = v16;
        --v14;
      }
      while ( v14 );
      AES_decrypt(v12, (unsigned int *)&ctxa);
      v17 = 0i64;
      v18 = 4i64;
      do
      {
        v19 = hostlong[v17] ^ *(_DWORD *)((char *)&ctxa + v17 * 4);
        hostlong[v17] = v24[v17];
        ++v17;
        *(int *)((char *)&v29 + v17 * 4) = htonl_0(v19);
        --v18;
      }
      while ( v18 );
      memmove(v5, &Src, 0x10ui64);
      v5 += 16;
      --v13;
    }
    while ( v13 );
    v4 = v23;
  }
  do
  {
    v20 = htonl_0(hostlong[v8]);
    ++v8;
    *(int *)((char *)&v27 + v8 * 4) = v20;
  }
  while ( v8 < 4 );
  memmove(v4, Dst, 0x10ui64);
}

// File Line: 358
// RVA: 0xEF38D0
void __fastcall AES_encrypt(aes_key_st *ctx, unsigned int *data)
{
  int v2; // er14
  unsigned int *v3; // rbx
  unsigned int *v4; // rdi
  unsigned int *v5; // rcx
  signed __int64 v6; // rdx
  unsigned int v7; // eax
  int v8; // ebp
  int v9; // er9
  unsigned int v10; // esi
  char *v11; // r13
  char v12; // r15
  int v13; // er11
  int v14; // edx
  int v15; // er8
  __int64 v16; // rax
  int v17; // ecx
  char v18; // r8
  int v19; // er10
  char v20; // dl
  int v21; // er10
  unsigned __int8 v22; // cl
  unsigned __int8 v23; // cl
  unsigned __int8 v24; // cl
  char v25; // r9
  unsigned __int8 v26; // cl
  unsigned __int8 v27; // al
  bool v28; // zf
  _DWORD *v29; // rcx
  signed __int64 v30; // rdx
  int v31; // eax
  char v32[72]; // [rsp+0h] [rbp-48h]
  int v33; // [rsp+50h] [rbp+8h]
  int v34; // [rsp+60h] [rbp+18h]
  int v35; // [rsp+68h] [rbp+20h]

  v2 = ctx->rounds;
  v3 = ctx->ks;
  v4 = data;
  v5 = data;
  v6 = 4i64;
  do
  {
    v7 = *v3;
    ++v3;
    *v5 ^= v7;
    ++v5;
    --v6;
  }
  while ( v6 );
  v8 = 0;
  if ( v2 > 0 )
  {
    v9 = v2 - 1;
    do
    {
      v10 = 0;
      v11 = v32;
      v12 = 0;
      do
      {
        v13 = (unsigned __int8)aes_sbox[HIBYTE(v4[v12 & 3])];
        v14 = (unsigned __int8)aes_sbox[BYTE2(v4[(v12 + 1) & 3])];
        v34 = (unsigned __int8)aes_sbox[BYTE2(v4[(v12 + 1) & 3])];
        v15 = (unsigned __int8)aes_sbox[BYTE1(v4[((_BYTE)v10 - 2) & 3])];
        v16 = ((_BYTE)v10 - 1) & 3;
        v33 = (unsigned __int8)aes_sbox[BYTE1(v4[((_BYTE)v10 - 2) & 3])];
        v17 = (unsigned __int8)aes_sbox[LOBYTE(v4[v16])];
        v35 = (unsigned __int8)aes_sbox[LOBYTE(v4[v16])];
        if ( v8 < v9 )
        {
          v18 = v33 ^ v17;
          v19 = v14 ^ v33 ^ v17;
          v20 = v13 ^ v14;
          v21 = v13 ^ v19;
          v22 = 2 * v20;
          if ( v20 < 0 )
            v22 = 2 * v20 ^ 0x1B;
          v13 ^= v21 ^ v22;
          v23 = 2 * (v34 ^ v33);
          if ( ((v34 ^ v33) & 0x80u) != 0 )
            v23 = 2 * (v34 ^ v33) ^ 0x1B;
          v14 = v21 ^ v23 ^ v34;
          v24 = 2 * v18;
          if ( v18 < 0 )
            v24 = 2 * v18 ^ 0x1B;
          v25 = v35 ^ aes_sbox[HIBYTE(v4[v12 & 3])];
          v15 = v21 ^ v24 ^ v33;
          v26 = 2 * v25;
          v27 = 2 * v25 ^ 0x1B;
          v28 = v25 >= 0;
          v9 = v2 - 1;
          if ( !v28 )
            v26 = v27;
          v17 = v21 ^ v26 ^ v35;
        }
        ++v10;
        ++v12;
        *(_DWORD *)v11 = v17 | ((v15 | ((v14 | (v13 << 8)) << 8)) << 8);
        v11 += 4;
      }
      while ( v10 < 4 );
      v29 = v4;
      v30 = 4i64;
      do
      {
        v31 = *v3 ^ *(_DWORD *)((char *)v29 + v32 - (char *)v4);
        ++v3;
        *v29 = v31;
        ++v29;
        --v30;
      }
      while ( v30 );
      ++v8;
    }
    while ( v8 < v2 );
  }
}

// File Line: 408
// RVA: 0xEF3618
void __fastcall AES_decrypt(aes_key_st *ctx, unsigned int *data)
{
  int v2; // er12
  unsigned int *v3; // r13
  int v4; // edx
  unsigned int *v5; // r14
  _DWORD *v6; // rcx
  int v7; // ebx
  signed int v8; // er9
  char *v9; // r8
  char v10; // r15
  int v11; // ebp
  int v12; // er10
  int v13; // er11
  __int64 v14; // rcx
  int v15; // esi
  unsigned __int8 v16; // cl
  int v17; // edi
  unsigned __int8 v18; // cl
  int v19; // ebx
  unsigned __int8 v20; // cl
  char v21; // si
  int v22; // er11
  unsigned __int8 v23; // cl
  int v24; // er8
  unsigned __int8 v25; // cl
  int v26; // er10
  char v27; // dl
  unsigned __int8 v28; // cl
  int v29; // er9
  unsigned __int8 v30; // dl
  int v31; // ecx
  int v32; // er8
  int v33; // er8
  int v34; // eax
  int v35; // eax
  signed int v36; // er8
  int *v37; // rcx
  signed int v38; // [rsp+0h] [rbp-68h]
  int v39; // [rsp+4h] [rbp-64h]
  char *v40; // [rsp+8h] [rbp-60h]
  char v41[12]; // [rsp+18h] [rbp-50h]
  char v42; // [rsp+24h] [rbp-44h]
  int v43; // [rsp+70h] [rbp+8h]
  int v44; // [rsp+80h] [rbp+18h]
  int v45; // [rsp+88h] [rbp+20h]

  v2 = ctx->rounds;
  v3 = data;
  v4 = 4;
  v5 = &ctx->ks[4 * v2 + 4];
  v6 = v3 + 3;
  do
  {
    --v5;
    *v6 ^= *v5;
    --v6;
    --v4;
  }
  while ( v4 );
  v44 = 0;
  if ( v2 > 0 )
  {
    v7 = v2 - 1;
    do
    {
      v8 = 4;
      v9 = &v42;
      v40 = &v42;
      v38 = 4;
      v10 = 5;
      do
      {
        v11 = (unsigned __int8)aes_isbox[HIBYTE(v3[(v10 - 2) & 3])];
        v12 = (unsigned __int8)aes_isbox[BYTE2(v3[(v10 + 1) & 3])];
        v39 = (unsigned __int8)aes_isbox[BYTE2(v3[(v10 + 1) & 3])];
        v13 = (unsigned __int8)aes_isbox[BYTE1(v3[v10 & 3])];
        v14 = LOBYTE(v3[(v10 - 1) & 3]);
        v45 = (unsigned __int8)aes_isbox[BYTE1(v3[v10 & 3])];
        v15 = (unsigned __int8)aes_isbox[v14];
        v43 = (unsigned __int8)aes_isbox[v14];
        if ( v4 >= v7 )
        {
          *(_DWORD *)v9 = v15 | ((v13 | ((v12 | (v11 << 8)) << 8)) << 8);
        }
        else
        {
          v16 = 2 * (v11 ^ v12);
          if ( ((v11 ^ v12) & 0x80u) != 0 )
            v16 = 2 * (v11 ^ v12) ^ 0x1B;
          v17 = v16;
          v18 = 2 * (v12 ^ v13);
          if ( ((v12 ^ v13) & 0x80u) != 0 )
            v18 = 2 * (v12 ^ v13) ^ 0x1B;
          v19 = v18;
          v20 = 2 * (v13 ^ v15);
          if ( ((v13 ^ v15) & 0x80u) != 0 )
            v20 = 2 * (v13 ^ v15) ^ 0x1B;
          v21 = v11 ^ v15;
          v22 = v20;
          v23 = 2 * (v17 ^ v19);
          if ( ((v17 ^ v19) & 0x80u) != 0 )
            v23 = 2 * (v17 ^ v19) ^ 0x1B;
          v24 = v23;
          v25 = 2 * (v19 ^ v22);
          if ( ((unsigned __int8)v19 ^ (unsigned __int8)v22) & 0x80 )
            v25 = 2 * (v19 ^ v22) ^ 0x1B;
          v26 = v25;
          v27 = v24 ^ v25;
          v28 = 2 * (v24 ^ v25);
          if ( v27 & 0x80 )
            v28 ^= 0x1Bu;
          v29 = v28;
          v30 = 2 * v21;
          v31 = v24 ^ v28;
          v32 = v11 ^ v45 ^ v43 ^ v19 ^ v26 ^ v29 | ((v39 ^ v45 ^ v43 ^ v17 ^ v31) << 8);
          v7 = v2 - 1;
          v33 = (v11 ^ v39 ^ v43 ^ v22 ^ v31 | (v32 << 8)) << 8;
          if ( v21 & 0x80 )
            v30 = 2 * v21 ^ 0x1B;
          v34 = v30;
          v4 = v44;
          v35 = v29 ^ v34;
          v8 = v38;
          *(_DWORD *)v40 = v11 ^ v39 ^ v45 ^ v26 ^ v35 | v33;
          v9 = v40;
        }
        v9 -= 4;
        --v10;
        --v8;
        v40 = v9;
        v38 = v8;
      }
      while ( v8 );
      v36 = 4;
      v37 = (int *)(v3 + 3);
      do
      {
        --v5;
        *v37 = *v5 ^ *(int *)((char *)v37 + v41 - (char *)v3);
        --v37;
        --v36;
      }
      while ( v36 );
      v4 = v44 + 1;
      v44 = v4;
    }
    while ( v4 < v2 );
  }
}

