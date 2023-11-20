// File Line: 88
// RVA: 0xEF6CF8
void __fastcall MD2_Init(MD2_CTX *ctx)
{
  memset(ctx, 0, 0x54ui64);
}

// File Line: 93
// RVA: 0xEF6D98
void __fastcall md2_process(MD2_CTX *ctx)
{
  MD2_CTX *v1; // r9
  unsigned __int8 v2; // cl
  signed __int64 v3; // r11
  char *v4; // r8
  signed __int64 v5; // r10
  char v6; // dl
  char v7; // al
  signed int v8; // edx
  char *v9; // r8
  signed __int64 v10; // r10
  unsigned __int8 v11; // dl

  v1 = ctx;
  v2 = 0;
  v3 = 16i64;
  v4 = v1->buffer;
  v5 = 16i64;
  do
  {
    v6 = *v4;
    v7 = *(v4++ - 48);
    *(v4 - 33) = v6;
    *(v4 - 17) = v6 ^ v7;
    --v5;
  }
  while ( v5 );
  v8 = 0;
  do
  {
    v9 = v1->state;
    v10 = 48i64;
    do
    {
      v2 = *v9 ^ PI_SUBST[v2];
      *v9++ = v2;
      --v10;
    }
    while ( v10 );
    v2 += v8++;
  }
  while ( v8 < 18 );
  v11 = v1->cksum[15];
  do
  {
    v11 = v1->cksum[0] ^ PI_SUBST[v11 ^ (unsigned __int64)(unsigned __int8)v1->buffer[0]];
    v1->cksum[0] = v11;
    v1 = (MD2_CTX *)((char *)v1 + 1);
    --v3;
  }
  while ( v3 );
}

// File Line: 121
// RVA: 0xEF6D04
void __fastcall MD2_Update(MD2_CTX *ctx, const char *input, int ilen)
{
  int v3; // esi
  const char *v4; // r14
  MD2_CTX *v5; // rdi
  int v6; // ecx
  int v7; // ebp

  if ( ilen > 0 )
  {
    v3 = ilen;
    v4 = input;
    v5 = ctx;
    do
    {
      v6 = v5->left;
      if ( v6 + v3 <= 16 )
        v7 = v3;
      else
        v7 = 16 - v6;
      memmove(&v5->buffer[v5->left], v4, v7);
      v5->left += v7;
      v4 += v7;
      v3 -= v7;
      if ( v5->left == 16 )
      {
        v5->left = 0;
        md2_process(v5);
      }
    }
    while ( v3 > 0 );
  }
}

// File Line: 149
// RVA: 0xEF6C7C
void __fastcall MD2_Final(char *output, MD2_CTX *ctx)
{
  MD2_CTX *v2; // rbx
  char *v3; // rdi
  char v4; // al
  signed __int64 v5; // rdx
  char *v6; // rcx
  size_t v7; // r8

  v2 = ctx;
  v3 = output;
  v4 = 16 - LOBYTE(ctx->left);
  v5 = ctx->left;
  if ( v5 < 16 )
  {
    v6 = &v2->buffer[v5];
    v7 = 16 - v5;
    LOBYTE(v5) = v4;
    memset(v6, v5, v7);
  }
  md2_process(v2);
  memmove(v2->buffer, v2, 0x10ui64);
  md2_process(v2);
  memmove(v3, v2->state, 0x10ui64);
}

