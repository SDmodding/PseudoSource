// File Line: 88
// RVA: 0xEF6CF8
void __fastcall MD2_Init(MD2_CTX *ctx)
{
  memset(ctx, 0, sizeof(MD2_CTX));
}

// File Line: 93
// RVA: 0xEF6D98
void __fastcall md2_process(MD2_CTX *ctx)
{
  unsigned __int8 v2; // cl
  __int64 v3; // r11
  char *buffer; // r8
  __int64 v5; // r10
  char v6; // dl
  char v7; // al
  int i; // edx
  char *state; // r8
  __int64 v10; // r10
  unsigned __int8 v11; // dl

  v2 = 0;
  v3 = 16i64;
  buffer = ctx->buffer;
  v5 = 16i64;
  do
  {
    v6 = *buffer;
    v7 = *(buffer - 48);
    *(++buffer - 33) = v6;
    *(buffer - 17) = v6 ^ v7;
    --v5;
  }
  while ( v5 );
  for ( i = 0; i < 18; ++i )
  {
    state = ctx->state;
    v10 = 48i64;
    do
    {
      v2 = *state ^ PI_SUBST[v2];
      *state++ = v2;
      --v10;
    }
    while ( v10 );
    v2 += i;
  }
  v11 = ctx->cksum[15];
  do
  {
    v11 = ctx->cksum[0] ^ PI_SUBST[v11 ^ (unsigned __int64)(unsigned __int8)ctx->buffer[0]];
    ctx->cksum[0] = v11;
    ctx = (MD2_CTX *)((char *)ctx + 1);
    --v3;
  }
  while ( v3 );
}

// File Line: 121
// RVA: 0xEF6D04
void __fastcall MD2_Update(MD2_CTX *ctx, const char *input, int ilen)
{
  int v3; // esi
  int left; // ecx
  int v7; // ebp

  if ( ilen > 0 )
  {
    v3 = ilen;
    do
    {
      left = ctx->left;
      if ( left + v3 <= 16 )
        v7 = v3;
      else
        v7 = 16 - left;
      memmove(&ctx->buffer[ctx->left], input, v7);
      ctx->left += v7;
      input += v7;
      v3 -= v7;
      if ( ctx->left == 16 )
      {
        ctx->left = 0;
        md2_process(ctx);
      }
    }
    while ( v3 > 0 );
  }
}

// File Line: 149
// RVA: 0xEF6C7C
void __fastcall MD2_Final(char *output, MD2_CTX *ctx)
{
  char v4; // al
  __int64 left; // rdx
  char *v6; // rcx
  size_t v7; // r8

  v4 = 16 - LOBYTE(ctx->left);
  left = ctx->left;
  if ( left < 16 )
  {
    v6 = &ctx->buffer[left];
    v7 = 16 - left;
    LOBYTE(left) = v4;
    memset(v6, left, v7);
  }
  md2_process(ctx);
  memmove(ctx->buffer, ctx, 0x10ui64);
  md2_process(ctx);
  memmove(output, ctx->state, 0x10ui64);
}

