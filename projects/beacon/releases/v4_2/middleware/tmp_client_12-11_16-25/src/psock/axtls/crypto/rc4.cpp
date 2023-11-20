// File Line: 43
// RVA: 0xEF13B8
void __fastcall RC4_setup(RC4_CTX *ctx, const char *key, int length)
{
  char *v3; // r9
  const char *v4; // rsi
  signed __int64 v5; // r10
  unsigned __int8 v6; // di
  signed int v7; // eax
  char *v8; // rcx
  __int64 v9; // rbx
  __int64 v10; // r8
  char *v11; // r11
  char v12; // al
  char v13; // dl
  unsigned __int8 v14; // al

  v3 = ctx->m;
  *(_WORD *)&ctx->x = 0;
  v4 = key;
  v5 = 256i64;
  v6 = 0;
  v7 = 0;
  v8 = ctx->m;
  do
    *v8++ = v7++;
  while ( v7 < 256 );
  v9 = length;
  v10 = 0i64;
  v11 = v3;
  do
  {
    v12 = v4[v10];
    v13 = *v11;
    ++v10;
    v14 = *v11 + v6 + v12;
    v6 = v14;
    if ( v10 >= v9 )
      v10 = 0i64;
    *v11++ = v3[v14];
    v3[v14] = v13;
    --v5;
  }
  while ( v5 );
}

// File Line: 71
// RVA: 0xEF133C
void __fastcall RC4_crypt(RC4_CTX *ctx, const char *msg, char *out, __int64 length)
{
  unsigned __int8 v4; // r11
  unsigned __int8 v5; // bl
  char *v6; // rdi
  RC4_CTX *v7; // r10
  signed __int64 v8; // rsi
  char v9; // r8
  char v10; // cl

  v4 = ctx->x;
  v5 = ctx->y;
  length = (signed int)length;
  v6 = out;
  v7 = ctx;
  if ( (signed int)length > 0i64 )
  {
    v8 = msg - out;
    do
    {
      v9 = v7->m[++v4];
      v5 += v9;
      v10 = v7->m[v5];
      v7->m[v4] = v10;
      v7->m[v5] = v9;
      *v6 = v6[v8] ^ v7->m[(unsigned __int8)(v9 + v10)];
      ++v6;
      --length;
    }
    while ( length );
  }
  v7->y = v5;
  v7->x = v4;
}

