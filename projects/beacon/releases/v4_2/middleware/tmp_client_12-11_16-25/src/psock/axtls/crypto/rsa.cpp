// File Line: 89
// RVA: 0xEF4220
void __fastcall RSA_pub_key_new(RSA_CTX **ctx, const char *modulus, int mod_len, const char *pub_exp, int pub_len)
{
  RSA_CTX *v6; // rcx
  RSA_CTX *v10; // rdi
  BI_CTX *v11; // rbx
  _bigint *v12; // rax
  _bigint *v13; // rax

  v6 = *ctx;
  if ( v6 )
    RSA_free(v6);
  v10 = (RSA_CTX *)ax_calloc(1ui64, 0x50ui64);
  *ctx = v10;
  if ( v10 )
  {
    v11 = bi_initialize();
    v10->num_octets = mod_len & 0xFFF0;
    v10->bi_ctx = v11;
    v12 = bi_import(v11, modulus, mod_len);
    v10->m = v12;
    bi_set_mod(v11, v12, 0);
    v13 = bi_import(v11, pub_exp, pub_len);
    v10->e = v13;
    bi_permanent(v13);
  }
}

// File Line: 114
// RVA: 0xEF411C
void __fastcall RSA_free(RSA_CTX *rsa_ctx)
{
  BI_CTX *bi_ctx; // rdi
  _bigint *d; // rcx

  if ( rsa_ctx )
  {
    bi_ctx = rsa_ctx->bi_ctx;
    bi_depermanent(rsa_ctx->e);
    bi_free(bi_ctx, rsa_ctx->e);
    bi_free_mod(rsa_ctx->bi_ctx, 0);
    d = rsa_ctx->d;
    if ( d )
    {
      bi_depermanent(d);
      bi_free(bi_ctx, rsa_ctx->d);
      bi_depermanent(rsa_ctx->dP);
      bi_depermanent(rsa_ctx->dQ);
      bi_depermanent(rsa_ctx->qInv);
      bi_free(bi_ctx, rsa_ctx->dP);
      bi_free(bi_ctx, rsa_ctx->dQ);
      bi_free(bi_ctx, rsa_ctx->qInv);
      bi_free_mod(rsa_ctx->bi_ctx, 1);
      bi_free_mod(rsa_ctx->bi_ctx, 2);
    }
    bi_terminate(bi_ctx);
    ax_free(rsa_ctx);
  }
}

// File Line: 156
// RVA: 0xEF3F0C
__int64 __fastcall RSA_decrypt(RSA_CTX *ctx, const char *in_data, char *out_data, int is_decryption)
{
  signed __int64 num_octets; // rbx
  char *v9; // rdi
  __int64 result; // rax
  _bigint *v11; // rdx
  _bigint *v12; // rax
  int v13; // ecx
  __int64 v14; // rdx
  char *v15; // rdx
  char v16; // al
  char v17; // al
  int v18; // ebx

  num_octets = ctx->num_octets;
  v9 = (char *)ax_malloc(num_octets);
  if ( !v9 )
    return 0xFFFFFFFFi64;
  memset(out_data, 0, num_octets);
  v11 = bi_import(ctx->bi_ctx, in_data, num_octets);
  if ( is_decryption )
  {
    v12 = RSA_private(ctx, v11);
  }
  else
  {
    ctx->bi_ctx->mod_offset = 0;
    v12 = bi_mod_power(ctx->bi_ctx, v11, ctx->e);
  }
  bi_export(ctx->bi_ctx, v12, v9, num_octets);
  v13 = 10;
  v14 = 10i64;
  if ( is_decryption )
  {
    do
    {
      v17 = v9[v14];
      ++v13;
      ++v14;
    }
    while ( v17 && v14 < num_octets );
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
    while ( v16 == -1 && v13 < (int)num_octets );
    if ( v9[v13 - 2] != -1 )
      v13 = num_octets;
  }
  v18 = num_octets - v13;
  if ( v18 > 0 )
    memmove(out_data, &v9[v13], v18);
  ax_free(v9);
  result = 0xFFFFFFFFi64;
  if ( v18 )
    return (unsigned int)v18;
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
__int64 __fastcall RSA_encrypt(
        RSA_CTX *ctx,
        const char *in_data,
        unsigned __int16 in_len,
        char *out_data,
        int is_signing)
{
  unsigned int num_octets; // ebp
  signed int v10; // esi
  _bigint *v11; // rdx
  _bigint *v12; // rax

  num_octets = ctx->num_octets;
  *out_data = 0;
  v10 = num_octets - in_len - 3;
  if ( is_signing )
  {
    out_data[1] = 1;
    memset(out_data + 2, 255, v10);
  }
  else
  {
    out_data[1] = 2;
    get_random_NZ(v10, out_data + 2);
  }
  out_data[v10 + 2] = 0;
  memmove(&out_data[v10 + 3], in_data, in_len);
  v11 = bi_import(ctx->bi_ctx, out_data, num_octets);
  if ( is_signing )
  {
    v12 = RSA_private(ctx, v11);
  }
  else
  {
    ctx->bi_ctx->mod_offset = 0;
    v12 = bi_mod_power(ctx->bi_ctx, v11, ctx->e);
  }
  bi_export(ctx->bi_ctx, v12, out_data, num_octets);
  bi_clear_cache(ctx->bi_ctx);
  return num_octets;
}

