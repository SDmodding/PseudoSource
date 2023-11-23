// File Line: 43
// RVA: 0xEF13B8
void __fastcall RC4_setup(RC4_CTX *ctx, const char *key, int length)
{
  char *m; // r9
  __int64 v5; // r10
  unsigned __int8 v6; // di
  int v7; // eax
  char *v8; // rcx
  __int64 v9; // rbx
  __int64 v10; // r8
  char *v11; // r11
  char v12; // al
  char v13; // dl
  unsigned __int8 v14; // al

  m = ctx->m;
  *(_WORD *)&ctx->x = 0;
  v5 = 256i64;
  v6 = 0;
  v7 = 0;
  v8 = ctx->m;
  do
    *v8++ = v7++;
  while ( v7 < 256 );
  v9 = length;
  v10 = 0i64;
  v11 = m;
  do
  {
    v12 = key[v10];
    v13 = *v11;
    ++v10;
    v14 = *v11 + v6 + v12;
    v6 = v14;
    if ( v10 >= v9 )
      v10 = 0i64;
    *v11++ = m[v14];
    m[v14] = v13;
    --v5;
  }
  while ( v5 );
}

// File Line: 71
// RVA: 0xEF133C
void __fastcall RC4_crypt(RC4_CTX *ctx, const char *msg, char *out, __int64 length)
{
  unsigned __int8 x; // r11
  unsigned __int8 y; // bl
  char *v6; // rdi
  __int64 v8; // rsi
  char v9; // r8
  char v10; // cl

  x = ctx->x;
  y = ctx->y;
  length = (int)length;
  v6 = out;
  if ( (int)length > 0 )
  {
    v8 = msg - out;
    do
    {
      v9 = ctx->m[++x];
      y += v9;
      v10 = ctx->m[y];
      ctx->m[x] = v10;
      ctx->m[y] = v9;
      *v6 = v6[v8] ^ ctx->m[(unsigned __int8)(v9 + v10)];
      ++v6;
      --length;
    }
    while ( length );
  }
  ctx->y = y;
  ctx->x = x;
}

