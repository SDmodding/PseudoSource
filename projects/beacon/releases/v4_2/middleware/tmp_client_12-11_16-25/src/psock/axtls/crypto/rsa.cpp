// File Line: 89
// RVA: 0xEF4220
void __fastcall RSA_pub_key_new(RSA_CTX **ctx, const char *modulus, int mod_len, const char *pub_exp, int pub_len)
{
  RSA_CTX **v5; // rbx
  RSA_CTX *v6; // rcx
  const char *v7; // rbp
  int v8; // esi
  const char *v9; // r14
  RSA_CTX *v10; // rdi
  BI_CTX *v11; // rbx
  _bigint *v12; // rax
  _bigint *v13; // rax

  v5 = ctx;
  v6 = *ctx;
  v7 = pub_exp;
  v8 = mod_len;
  v9 = modulus;
  if ( v6 )
    RSA_free(v6);
  v10 = (RSA_CTX *)ax_calloc(1ui64, 0x50ui64);
  *v5 = v10;
  if ( v10 )
  {
    v11 = bi_initialize();
    v10->num_octets = v8 & 0xFFF0;
    v10->bi_ctx = v11;
    v12 = bi_import(v11, v9, v8);
    v10->m = v12;
    bi_set_mod(v11, v12, 0);
    v13 = bi_import(v11, v7, pub_len);
    v10->e = v13;
    bi_permanent(v13);
  }
}

// File Line: 114
// RVA: 0xEF411C
void __fastcall RSA_free(RSA_CTX *rsa_ctx)
{
  BI_CTX *v1; // rdi
  RSA_CTX *v2; // rbx
  _bigint *v3; // rcx

  if ( rsa_ctx )
  {
    v1 = rsa_ctx->bi_ctx;
    v2 = rsa_ctx;
    bi_depermanent(rsa_ctx->e);
    bi_free(v1, v2->e);
    bi_free_mod(v2->bi_ctx, 0);
    v3 = v2->d;
    if ( v3 )
    {
      bi_depermanent(v3);
      bi_free(v1, v2->d);
      bi_depermanent(v2->dP);
      bi_depermanent(v2->dQ);
      bi_depermanent(v2->qInv);
      bi_free(v1, v2->dP);
      bi_free(v1, v2->dQ);
      bi_free(v1, v2->qInv);
      bi_free_mod(v2->bi_ctx, 1);
      bi_free_mod(v2->bi_ctx, 2);
    }
    bi_terminate(v1);
    ax_free(v2);
  }
}

// File Line: 156
// RVA: 0xEF3F0C
signed __int64 __fastcall RSA_decrypt(RSA_CTX *ctx, const char *in_data, char *out_data, int is_decryption)
{
  signed __int64 v4; // rbx
  RSA_CTX *v5; // rsi
  int v6; // er14
  char *v7; // r12
  const char *v8; // r15
  char *v9; // rdi
  signed __int64 result; // rax
  _bigint *v11; // rdx
  _bigint *v12; // rax
  signed int v13; // ecx
  signed __int64 v14; // rdx
  char *v15; // rdx
  char v16; // al
  char v17; // al
  unsigned int v18; // ebx

  v4 = ctx->num_octets;
  v5 = ctx;
  v6 = is_decryption;
  v7 = out_data;
  v8 = in_data;
  v9 = (char *)ax_malloc(v4);
  if ( !v9 )
    return 0xFFFFFFFFi64;
  memset(v7, 0, v4);
  v11 = bi_import(v5->bi_ctx, v8, v4);
  if ( v6 )
  {
    v12 = RSA_private(v5, v11);
  }
  else
  {
    v5->bi_ctx->mod_offset = 0;
    v12 = bi_mod_power(v5->bi_ctx, v11, v5->e);
  }
  bi_export(v5->bi_ctx, v12, v9, v4);
  v13 = 10;
  v14 = 10i64;
  if ( v6 )
  {
    do
    {
      v17 = v9[v14];
      ++v13;
      ++v14;
    }
    while ( v17 && v14 < v4 );
  }
  else
  {
    v15 = v9 + 10;
    do
    {
      v16 = *v15;
      ++v13;
      ++v15;
    }
    while ( v16 == -1 && v13 < (signed int)v4 );
    if ( v9[v13 - 2] != -1 )
      v13 = v4;
  }
  v18 = v4 - v13;
  if ( (signed int)v18 > 0 )
    memmove(v7, &v9[v13], (signed int)v18);
  ax_free(v9);
  result = 0xFFFFFFFFi64;
  if ( v18 )
    result = v18;
  return result;
}

// File Line: 214
// RVA: 0xEF41E8
_bigint *__fastcall RSA_private(RSA_CTX *c, _bigint *bi_msg)
{
  return bi_crt(c->bi_ctx, bi_msg, c->dP, c->dQ, c->p, c->q, c->qInv);
}

// File Line: 257
// RVA: 0xEF402C
__int64 __fastcall RSA_encrypt(RSA_CTX *ctx, const char *in_data, unsigned __int16 in_len, char *out_data, int is_signing)
{
  unsigned int v5; // ebp
  unsigned __int16 v6; // r14
  char *v7; // rdi
  const char *v8; // r12
  RSA_CTX *v9; // rbx
  int v10; // esi
  int v11; // esi
  _bigint *v12; // rdx
  _bigint *v13; // rax

  v5 = ctx->num_octets;
  v6 = in_len;
  v7 = out_data;
  v8 = in_data;
  v9 = ctx;
  v10 = ctx->num_octets - in_len;
  *out_data = 0;
  v11 = v10 - 3;
  if ( is_signing )
  {
    out_data[1] = 1;
    memset(out_data + 2, 255, v11);
  }
  else
  {
    out_data[1] = 2;
    get_random_NZ(v11, out_data + 2);
  }
  v7[v11 + 2] = 0;
  memmove(&v7[v11 + 3], v8, v6);
  v12 = bi_import(v9->bi_ctx, v7, v5);
  if ( is_signing )
  {
    v13 = RSA_private(v9, v12);
  }
  else
  {
    v9->bi_ctx->mod_offset = 0;
    v13 = bi_mod_power(v9->bi_ctx, v12, v9->e);
  }
  bi_export(v9->bi_ctx, v13, v7, v5);
  bi_clear_cache(v9->bi_ctx);
  return v5;
}

