// File Line: 183
// RVA: 0xEF3A98
void __fastcall AES_set_key(aes_key_st *ctx, const char *key, const char *iv, AES_MODE mode)
{
  unsigned __int16 v6; // ax
  int v7; // r8d
  unsigned int *ks; // r10
  const char *v9; // rdx
  unsigned int *v10; // r9
  __int64 v11; // rbx
  int v12; // ecx
  int v13; // eax
  const char *v14; // r14
  int v15; // ebx
  int v16; // edi
  unsigned int v17; // r9d

  if ( mode )
  {
    if ( mode != AES_MODE_256 )
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
  ks = ctx->ks;
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
  v14 = Rcon;
  v15 = v7;
  v16 = 4 * ctx->rounds + 4;
  if ( v7 < v16 )
  {
    do
    {
      v17 = ks[v7 - 1];
      if ( !(v15 % v7) )
        v17 = (*(unsigned __int8 *)v14++ << 24) ^ ((unsigned __int8)aes_sbox[(unsigned __int64)v17 >> 24] | (((unsigned __int8)aes_sbox[(unsigned __int8)v17] | (((unsigned __int8)aes_sbox[BYTE1(v17)] | ((unsigned __int8)aes_sbox[BYTE2(v17)] << 8)) << 8)) << 8));
      if ( v7 == 8 && v15 % 8 == 4 )
        v17 = (unsigned __int8)aes_sbox[(unsigned __int8)v17] | (((unsigned __int8)aes_sbox[BYTE1(v17)] | ((((unsigned __int8)aes_sbox[(unsigned __int64)v17 >> 24] << 8) | (unsigned __int8)aes_sbox[BYTE2(v17)]) << 8)) << 8);
      ++v15;
      ks[v7] = v17 ^ *ks;
      ++ks;
    }
    while ( v15 < v16 );
  }
  memmove(ctx->iv, iv, 0x10ui64);
}

// File Line: 257
// RVA: 0xEF3564
void __fastcall AES_convert_key(aes_key_st *ctx)
{
  unsigned int *v1; // r10
  int v2; // eax
  __int64 v3; // r11
  unsigned int v4; // r9d
  unsigned int v5; // edx
  unsigned int v6; // eax

  v1 = &ctx->ks[4];
  v2 = 4 * ctx->rounds;
  if ( v2 > 4 )
  {
    v3 = (unsigned int)(v2 - 4);
    do
    {
      v4 = (2 * *v1) & 0xFEFEFEFE ^ ((*v1 & 0x80808080) - ((*v1 & 0x80808080) >> 7)) & 0x1B1B1B1B;
      v5 = (2 * v4) & 0xFEFEFEFE ^ ((v4 & 0x80808080) - ((v4 & 0x80808080) >> 7)) & 0x1B1B1B1B;
      v6 = (2 * v5) & 0xFEFEFEFE ^ ((v5 & 0x80808080) - ((v5 & 0x80808080) >> 7)) & 0x1B1B1B1B;
      *v1 = v4 ^ v5 ^ v6 ^ __ROL4__(*v1 ^ v6 ^ v4, 8) ^ __ROL4__(*v1 ^ v6 ^ v5, 16) ^ __ROR4__(*v1 ^ v6, 8);
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
  char *iv; // r13
  __int64 v8; // rbx
  __int64 i; // rdi
  u_long v10; // eax
  int v11; // esi
  aes_key_st *v12; // r13
  unsigned __int64 v13; // rsi
  __int64 j; // rdi
  u_long v15; // eax
  __int64 v16; // rdi
  __int64 v17; // r14
  u_long v18; // ecx
  u_long v19; // eax
  int v20[5]; // [rsp+1Ch] [rbp-64h]
  char *v21; // [rsp+30h] [rbp-50h]
  aes_key_st *ctxa[2]; // [rsp+38h] [rbp-48h] BYREF
  int Dst[4]; // [rsp+48h] [rbp-38h] BYREF
  u_long netlong[4]; // [rsp+58h] [rbp-28h] BYREF
  char Src[16]; // [rsp+68h] [rbp-18h] BYREF

  iv = ctx->iv;
  ctxa[0] = ctx;
  v21 = ctx->iv;
  memmove(Dst, ctx->iv, 0x10ui64);
  v8 = 0i64;
  for ( i = 0i64; i < 4; v20[i] = v10 )
    v10 = ntohl_0(Dst[i++]);
  v11 = length - 16;
  if ( v11 >= 0 )
  {
    v12 = ctxa[0];
    v13 = (unsigned __int64)(unsigned int)(v11 + 16) >> 4;
    do
    {
      memmove(netlong, msg, 0x10ui64);
      msg += 16;
      for ( j = 0i64; j < 4; *(_DWORD *)((char *)&v21 + j * 4 + 4) = v20[j] ^ v15 )
        v15 = ntohl_0(netlong[j++]);
      AES_encrypt(v12, (unsigned int *)ctxa);
      v16 = 0i64;
      v17 = 4i64;
      do
      {
        v18 = *(_DWORD *)((char *)ctxa + v16 * 4);
        v20[++v16] = v18;
        netlong[v16 + 3] = htonl_0(v18);
        --v17;
      }
      while ( v17 );
      memmove(out, Src, 0x10ui64);
      out += 16;
      --v13;
    }
    while ( v13 );
    iv = v21;
  }
  do
  {
    v19 = htonl_0(v20[++v8]);
    *(_DWORD *)((char *)&ctxa[1] + v8 * 4 + 4) = v19;
  }
  while ( v8 < 4 );
  memmove(iv, Dst, 0x10ui64);
}

// File Line: 315
// RVA: 0xEF32B0
void __fastcall AES_cbc_decrypt(aes_key_st *ctx, const char *msg, char *out, int length)
{
  char *iv; // r13
  __int64 v8; // rbx
  __int64 i; // rdi
  u_long v10; // eax
  int v11; // esi
  aes_key_st *v12; // r13
  unsigned __int64 v13; // rsi
  __int64 v14; // r14
  __int64 v15; // rdi
  u_long v16; // eax
  __int64 v17; // rdi
  __int64 v18; // r14
  int v19; // ecx
  u_long v20; // eax
  int v21[5]; // [rsp+1Ch] [rbp-5Dh]
  __int64 v22[5]; // [rsp+30h] [rbp-49h]
  aes_key_st *ctxa[2]; // [rsp+58h] [rbp-21h] BYREF
  int Dst[4]; // [rsp+68h] [rbp-11h] BYREF
  char Src[16]; // [rsp+78h] [rbp-1h] BYREF
  u_long netlong[4]; // [rsp+88h] [rbp+Fh] BYREF

  iv = ctx->iv;
  ctxa[0] = ctx;
  v22[0] = (__int64)ctx->iv;
  memmove(Dst, ctx->iv, 0x10ui64);
  v8 = 0i64;
  for ( i = 0i64; i < 4; v21[i] = v10 )
    v10 = ntohl_0(Dst[i++]);
  v11 = length - 16;
  if ( v11 >= 0 )
  {
    v12 = ctxa[0];
    v13 = (unsigned __int64)(unsigned int)(v11 + 16) >> 4;
    do
    {
      memmove(netlong, msg, 0x10ui64);
      msg += 16;
      v14 = 4i64;
      v15 = 0i64;
      do
      {
        v16 = ntohl_0(netlong[v15++]);
        *(_DWORD *)((char *)v22 + v15 * 4 + 4) = v16;
        *(_DWORD *)((char *)&v22[4] + v15 * 4 + 4) = v16;
        --v14;
      }
      while ( v14 );
      AES_decrypt(v12, (unsigned int *)ctxa);
      v17 = 0i64;
      v18 = 4i64;
      do
      {
        v19 = v21[v17 + 1] ^ *(_DWORD *)((char *)ctxa + v17 * 4);
        v21[v17 + 1] = *(_DWORD *)((char *)&v22[1] + v17 * 4);
        Dst[++v17 + 3] = htonl_0(v19);
        --v18;
      }
      while ( v18 );
      memmove(out, Src, 0x10ui64);
      out += 16;
      --v13;
    }
    while ( v13 );
    iv = (char *)v22[0];
  }
  do
  {
    v20 = htonl_0(v21[++v8]);
    *(_DWORD *)((char *)&ctxa[1] + v8 * 4 + 4) = v20;
  }
  while ( v8 < 4 );
  memmove(iv, Dst, 0x10ui64);
}

// File Line: 358
// RVA: 0xEF38D0
void __fastcall AES_encrypt(aes_key_st *ctx, char *data)
{
  int rounds; // r14d
  unsigned int *ks; // rbx
  char *v5; // rcx
  __int64 v6; // rdx
  int v7; // eax
  int v8; // ebp
  int v9; // r9d
  unsigned int v10; // esi
  char *v11; // r13
  char v12; // r15
  int v13; // r11d
  int v14; // edx
  int v15; // r8d
  int v16; // ecx
  char v17; // r8
  int v18; // r10d
  char v19; // dl
  int v20; // r10d
  unsigned __int8 v21; // cl
  unsigned __int8 v22; // cl
  unsigned __int8 v23; // cl
  char v24; // r9
  unsigned __int8 v25; // cl
  unsigned __int8 v26; // al
  bool v27; // zf
  char *v28; // rcx
  __int64 v29; // rdx
  int v30; // eax
  char v31[72]; // [rsp+0h] [rbp-48h] BYREF
  int v32; // [rsp+50h] [rbp+8h]
  int v33; // [rsp+60h] [rbp+18h]
  int v34; // [rsp+68h] [rbp+20h]

  rounds = ctx->rounds;
  ks = ctx->ks;
  v5 = data;
  v6 = 4i64;
  do
  {
    v7 = *ks++;
    *(_DWORD *)v5 ^= v7;
    v5 += 4;
    --v6;
  }
  while ( v6 );
  v8 = 0;
  if ( rounds > 0 )
  {
    v9 = rounds - 1;
    do
    {
      v10 = 0;
      v11 = v31;
      v12 = 0;
      do
      {
        v13 = (unsigned __int8)aes_sbox[(unsigned __int8)data[4 * (v12 & 3) + 3]];
        v14 = (unsigned __int8)aes_sbox[(unsigned __int8)data[4 * ((v12 + 1) & 3) + 2]];
        v33 = v14;
        v15 = (unsigned __int8)aes_sbox[(unsigned __int8)data[4 * (((_BYTE)v10 - 2) & 3) + 1]];
        v32 = v15;
        v16 = (unsigned __int8)aes_sbox[(unsigned __int8)data[4 * (((_BYTE)v10 - 1) & 3)]];
        v34 = v16;
        if ( v8 < v9 )
        {
          v17 = v15 ^ v16;
          v18 = v14 ^ v32 ^ v16;
          v19 = v13 ^ v14;
          v20 = v13 ^ v18;
          v21 = 2 * v19;
          if ( v19 < 0 )
            v21 = (2 * v19) ^ 0x1B;
          v13 ^= v20 ^ v21;
          v22 = 2 * (v33 ^ v32);
          if ( ((v33 ^ v32) & 0x80u) != 0 )
            v22 = (2 * (v33 ^ v32)) ^ 0x1B;
          v14 = v20 ^ v22 ^ v33;
          v23 = 2 * v17;
          if ( v17 < 0 )
            v23 = (2 * v17) ^ 0x1B;
          v24 = v34 ^ aes_sbox[(unsigned __int8)data[4 * (v12 & 3) + 3]];
          v15 = v20 ^ v23 ^ v32;
          v25 = 2 * v24;
          v26 = (2 * v24) ^ 0x1B;
          v27 = v24 >= 0;
          v9 = rounds - 1;
          if ( !v27 )
            v25 = v26;
          v16 = v20 ^ v25 ^ v34;
        }
        ++v10;
        ++v12;
        *(_DWORD *)v11 = v16 | ((v15 | ((v14 | (v13 << 8)) << 8)) << 8);
        v11 += 4;
      }
      while ( v10 < 4 );
      v28 = data;
      v29 = 4i64;
      do
      {
        v30 = *ks++ ^ *(_DWORD *)&v28[v31 - data];
        *(_DWORD *)v28 = v30;
        v28 += 4;
        --v29;
      }
      while ( v29 );
      ++v8;
    }
    while ( v8 < rounds );
  }
}

// File Line: 408
// RVA: 0xEF3618
void __fastcall AES_decrypt(aes_key_st *ctx, char *data)
{
  int rounds; // r12d
  int v4; // edx
  unsigned int *v5; // r14
  unsigned int *v6; // rcx
  int v7; // ebx
  int v8; // r9d
  char *v9; // r8
  char v10; // r15
  int v11; // ebp
  int v12; // r10d
  int v13; // r11d
  int v14; // esi
  unsigned __int8 v15; // cl
  int v16; // edi
  unsigned __int8 v17; // cl
  int v18; // ebx
  unsigned __int8 v19; // cl
  char v20; // si
  int v21; // r11d
  unsigned __int8 v22; // cl
  int v23; // r8d
  unsigned __int8 v24; // cl
  int v25; // r10d
  char v26; // dl
  unsigned __int8 v27; // cl
  int v28; // r9d
  unsigned __int8 v29; // dl
  int v30; // ecx
  int v31; // r8d
  int v32; // r8d
  int v33; // eax
  int v34; // eax
  int v35; // r8d
  unsigned int *v36; // rcx
  int v37; // [rsp+0h] [rbp-68h]
  int v38; // [rsp+4h] [rbp-64h]
  char *v39; // [rsp+8h] [rbp-60h]
  char v40; // [rsp+18h] [rbp-50h] BYREF
  char v41[68]; // [rsp+24h] [rbp-44h] BYREF
  int v42; // [rsp+70h] [rbp+8h]
  int v43; // [rsp+80h] [rbp+18h]
  int v44; // [rsp+88h] [rbp+20h]

  rounds = ctx->rounds;
  v4 = 4;
  v5 = &ctx->ks[4 * rounds + 4];
  v6 = (unsigned int *)(data + 12);
  do
  {
    *v6-- ^= *--v5;
    --v4;
  }
  while ( v4 );
  v43 = 0;
  if ( rounds > 0 )
  {
    v7 = rounds - 1;
    do
    {
      v8 = 4;
      v9 = v41;
      v39 = v41;
      v37 = 4;
      v10 = 5;
      do
      {
        v11 = (unsigned __int8)aes_isbox[(unsigned __int8)data[4 * ((v10 - 2) & 3) + 3]];
        v12 = (unsigned __int8)aes_isbox[(unsigned __int8)data[4 * ((v10 + 1) & 3) + 2]];
        v38 = v12;
        v13 = (unsigned __int8)aes_isbox[(unsigned __int8)data[4 * (v10 & 3) + 1]];
        v44 = v13;
        v14 = (unsigned __int8)aes_isbox[(unsigned __int8)data[4 * ((v10 - 1) & 3)]];
        v42 = v14;
        if ( v4 >= v7 )
        {
          *(_DWORD *)v9 = v14 | ((v13 | ((v12 | (v11 << 8)) << 8)) << 8);
        }
        else
        {
          v15 = 2 * (v11 ^ v12);
          if ( ((v11 ^ v12) & 0x80u) != 0 )
            v15 = (2 * (v11 ^ v12)) ^ 0x1B;
          v16 = v15;
          v17 = 2 * (v12 ^ v13);
          if ( ((v12 ^ v13) & 0x80u) != 0 )
            v17 = (2 * (v12 ^ v13)) ^ 0x1B;
          v18 = v17;
          v19 = 2 * (v13 ^ v14);
          if ( ((v13 ^ v14) & 0x80u) != 0 )
            v19 = (2 * (v13 ^ v14)) ^ 0x1B;
          v20 = v11 ^ v14;
          v21 = v19;
          v22 = 2 * (v16 ^ v18);
          if ( ((v16 ^ v18) & 0x80u) != 0 )
            v22 = (2 * (v16 ^ v18)) ^ 0x1B;
          v23 = v22;
          v24 = 2 * (v18 ^ v21);
          if ( (((unsigned __int8)v18 ^ (unsigned __int8)v21) & 0x80) != 0 )
            v24 = (2 * (v18 ^ v21)) ^ 0x1B;
          v25 = v24;
          v26 = v23 ^ v24;
          v27 = 2 * (v23 ^ v24);
          if ( (v26 & 0x80) != 0 )
            v27 ^= 0x1Bu;
          v28 = v27;
          v29 = 2 * v20;
          v30 = v23 ^ v27;
          v31 = v11 ^ v44 ^ v42 ^ v18 ^ v25 ^ v28 | ((v38 ^ v44 ^ v42 ^ v16 ^ v30) << 8);
          v7 = rounds - 1;
          v32 = (v11 ^ v38 ^ v42 ^ v21 ^ v30 | (v31 << 8)) << 8;
          if ( (v20 & 0x80) != 0 )
            v29 = (2 * v20) ^ 0x1B;
          v33 = v29;
          v4 = v43;
          v34 = v28 ^ v33;
          v8 = v37;
          *(_DWORD *)v39 = v11 ^ v38 ^ v44 ^ v25 ^ v34 | v32;
          v9 = v39;
        }
        v9 -= 4;
        --v10;
        --v8;
        v39 = v9;
        v37 = v8;
      }
      while ( v8 );
      v35 = 4;
      v36 = (unsigned int *)(data + 12);
      do
      {
        *v36 = *--v5 ^ *(unsigned int *)((char *)v36 + &v40 - data);
        --v36;
        --v35;
      }
      while ( v35 );
      v4 = v43 + 1;
      v43 = v4;
    }
    while ( v4 < rounds );
  }
}

