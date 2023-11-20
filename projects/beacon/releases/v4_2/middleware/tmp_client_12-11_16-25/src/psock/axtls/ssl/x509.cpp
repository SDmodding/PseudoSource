// File Line: 85
// RVA: 0xEF0DA0
__int64 __fastcall x509_new(const char *cert, int *len, _x509_ctx **ctx)
{
  int *v3; // r12
  const char *v4; // rdi
  unsigned int v5; // er15
  _x509_ctx **v6; // rbx
  _x509_ctx *v7; // rsi
  __int64 v8; // rbx
  BI_CTX *v9; // r14
  char v10; // al
  int v11; // er8
  int v12; // eax
  int v13; // ecx
  int v14; // er14
  signed __int64 v15; // r13
  int v16; // eax
  int v17; // er15
  int v18; // ebx
  size_t v19; // r12
  char **v20; // rax
  signed __int64 v21; // rbx
  char *v22; // rcx
  int *v24; // [rsp+20h] [rbp-79h]
  int v25; // [rsp+28h] [rbp-71h]
  int v26; // [rsp+2Ch] [rbp-6Dh]
  int v27; // [rsp+30h] [rbp-69h]
  int offset; // [rsp+34h] [rbp-65h]
  MD5_CTX ctxa; // [rsp+40h] [rbp-59h]
  char digest; // [rsp+A0h] [rbp+7h]

  v25 = 0;
  offset = 0;
  v3 = len;
  v24 = len;
  v4 = cert;
  v5 = -1;
  v6 = ctx;
  v7 = (_x509_ctx *)ax_calloc(1ui64, 0x70ui64);
  *v6 = v7;
  if ( v7 )
  {
    asn1_skip_obj(v4, &offset, 48);
    if ( asn1_next_obj(v4, &v25, 48) >= 0 )
    {
      v8 = v25;
      v27 = v25;
      asn1_skip_obj(v4, &v27, 48);
      if ( asn1_next_obj(v4, &v25, 48) >= 0
        && (v4[v25] != -96 || !asn1_version(v4, &v25, v7))
        && !asn1_skip_obj(v4, &v25, 2)
        && asn1_next_obj(v4, &v25, 48) >= 0 )
      {
        if ( asn1_signature_type(v4, &v25, v7) )
          return (unsigned int)-8;
        if ( !asn1_name(v4, &v25, v7->ca_cert_dn)
          && !asn1_validity(v4, &v25, v7)
          && !asn1_name(v4, &v25, v7->cert_dn)
          && !asn1_public_key(v4, &v25, v7) )
        {
          v9 = v7->rsa_ctx->bi_ctx;
          v10 = v7->sig_type;
          switch ( v10 )
          {
            case 4:
              MD5_Init(&ctxa);
              MD5_Update(&ctxa, &v4[v8], v27 - v8);
              MD5_Final(&digest, &ctxa);
              break;
            case 5:
              SHA1_Init((SHA1_CTX *)&ctxa);
              SHA1_Update((SHA1_CTX *)&ctxa, &v4[v8], v27 - v8);
              SHA1_Final(&digest, (SHA1_CTX *)&ctxa);
              v11 = 20;
LABEL_21:
              v7->digest = bi_import(v9, &digest, v11);
LABEL_22:
              if ( v4[v25] == -93 )
              {
                ++v25;
                get_asn1_length(v4, &v25);
                v26 = asn1_find_subjectaltname(v4, v25);
                if ( v26 > 0 && asn1_next_obj(v4, &v26, 4) > 0 )
                {
                  v12 = asn1_next_obj(v4, &v26, 48);
                  if ( v12 > 0 )
                  {
                    v13 = v26;
                    v14 = 0;
                    v15 = 0i64;
                    v16 = v26 + v12;
                    if ( v26 < v16 )
                    {
                      v17 = v16;
                      do
                      {
                        v18 = (unsigned __int8)v4[v13];
                        v26 = v13 + 1;
                        v19 = get_asn1_length(v4, &v26);
                        if ( v18 == 130 )
                        {
                          v20 = (char **)ax_realloc(v7->subject_alt_dnsnames, 8i64 * (v14 + 2));
                          v7->subject_alt_dnsnames = v20;
                          if ( v20 )
                          {
                            v21 = v15++;
                            v7->subject_alt_dnsnames[v21] = (char *)ax_malloc((signed int)v19 + 1);
                            v7->subject_alt_dnsnames[v15] = 0i64;
                            v22 = v7->subject_alt_dnsnames[v21];
                            if ( v22 )
                            {
                              memmove(v22, &v4[v26], v19);
                              v7->subject_alt_dnsnames[v21][v19] = 0;
                            }
                            ++v14;
                          }
                          else
                          {
                            v14 = 0;
                            v15 = 0i64;
                          }
                        }
                        v13 = v19 + v26;
                        v26 = v13;
                      }
                      while ( v13 < v17 );
                      v3 = v24;
                      v5 = -1;
                    }
                  }
                }
              }
              v25 = v27;
              if ( !asn1_skip_obj(v4, &v25, 48) && !asn1_signature(v4, &v25, v7) )
              {
                if ( v3 )
                  *v3 = offset;
                v5 = 0;
              }
              return v5;
            case 2:
              MD2_Init((MD2_CTX *)&ctxa);
              MD2_Update((MD2_CTX *)&ctxa, &v4[v8], v27 - v8);
              MD2_Final(&digest, (MD2_CTX *)&ctxa);
              break;
            default:
              goto LABEL_22;
          }
          v11 = 16;
          goto LABEL_21;
        }
      }
    }
  }
  return v5;
}

// File Line: 249
// RVA: 0xEF0CEC
void __fastcall x509_free(_x509_ctx *x509_ctx)
{
  _x509_ctx *v1; // rdi
  signed __int64 v2; // rbx
  _bigint *v3; // rdx
  void **v4; // rax
  __int64 i; // rbx
  _x509_ctx *v6; // rbx

  if ( x509_ctx )
  {
    v1 = x509_ctx;
    do
    {
      v2 = 0i64;
      do
      {
        ax_free(v1->ca_cert_dn[v2]);
        ax_free(v1->cert_dn[v2++]);
      }
      while ( v2 < 3 );
      ax_free(v1->signature);
      v3 = v1->digest;
      if ( v3 )
        bi_free(v1->rsa_ctx->bi_ctx, v3);
      v4 = (void **)v1->subject_alt_dnsnames;
      if ( v4 )
      {
        for ( i = 0i64; *v4; v4 = (void **)&v1->subject_alt_dnsnames[i] )
        {
          ax_free(*v4);
          ++i;
        }
        ax_free(v1->subject_alt_dnsnames);
      }
      RSA_free(v1->rsa_ctx);
      v6 = v1->next;
      ax_free(v1);
      v1 = v6;
    }
    while ( v6 );
  }
}

// File Line: 293
// RVA: 0xEF0BAC
_bigint *__fastcall sig_verify(BI_CTX *ctx, const char *sig, int sig_len, _bigint *modulus, _bigint *pub_exp)
{
  signed __int64 v5; // rdi
  BI_CTX *v6; // rbp
  _bigint *v7; // r12
  const char *v8; // r15
  _bigint *v9; // rbx
  _bigint *result; // rax
  char *v11; // rsi
  _bigint *v12; // rax
  _bigint *v13; // rax
  signed int v14; // edx
  signed __int64 v15; // rcx
  char v16; // al
  const char *v17; // rdi
  char v18; // cl
  int v19; // eax
  const char *v20; // rdx
  int offset; // [rsp+20h] [rbp-58h]

  v5 = sig_len;
  v6 = ctx;
  v7 = modulus;
  v8 = sig;
  v9 = 0i64;
  result = (_bigint *)ax_malloc(sig_len);
  v11 = (char *)result;
  if ( result )
  {
    v12 = bi_import(v6, v8, v5);
    v6->mod_offset = 0;
    v13 = bi_mod_power2(v6, v12, v7, pub_exp);
    bi_export(v6, v13, v11, v5);
    v14 = 10;
    v6->mod_offset = 0;
    v15 = 10i64;
    do
    {
      v16 = v11[v15];
      ++v14;
      ++v15;
    }
    while ( v16 && v15 < v5 );
    if ( (signed int)v5 - v14 > 0 )
    {
      v17 = &v11[v14];
      offset = 0;
      if ( asn1_next_obj(v17, &offset, 48) >= 0 && !asn1_skip_obj(v17, &offset, 48) )
      {
        v18 = v17[offset++];
        if ( v18 == 4 )
        {
          v19 = get_asn1_length(v17, &offset);
          v20 = &v17[offset];
          if ( v20 )
            v9 = bi_import(v6, v20, v19);
        }
      }
    }
    bi_clear_cache(v6);
    ax_free(v11);
    result = v9;
  }
  return result;
}

// File Line: 351
// RVA: 0xEF117C
__int64 __fastcall x509_verify(CA_CERT_CTX *ca_cert_ctx, _x509_ctx *cert)
{
  _x509_ctx *v2; // rdi
  signed int v4; // ebx
  int v5; // eax
  char v6; // bp
  _x509_ctx *v7; // rsi
  signed __int64 v8; // rax
  unsigned int v9; // ebx
  RSA_CTX *v10; // rax
  BI_CTX *v11; // rcx
  _bigint *v12; // rdx
  _bigint *pub_exp; // rbx
  _bigint *v14; // rax
  _bigint *v15; // rax
  _bigint *v16; // rdx
  RSA_CTX *v17; // rax
  _bigint *bi; // [rsp+30h] [rbp-28h]
  _bigint *bia; // [rsp+30h] [rbp-28h]
  CA_CERT_CTX *ca_cert_ctxa; // [rsp+60h] [rbp+8h]
  signed int v21; // [rsp+70h] [rbp+18h]
  CA_CERT_CTX *v22; // [rsp+70h] [rbp+18h]
  BI_CTX *ctx; // [rsp+78h] [rbp+20h]

  ca_cert_ctxa = ca_cert_ctx;
  v2 = cert;
  if ( x509_accept_all )
    return 0i64;
  v4 = 0;
  v21 = 0;
  if ( !cert )
    return (unsigned int)-2;
  v5 = asn1_compare_dn(cert->ca_cert_dn, cert->cert_dn);
  v6 = 0;
  v7 = v2->next;
  if ( !v5 )
    v6 = 1;
  if ( v7 )
  {
    if ( asn1_compare_dn(v2->ca_cert_dn, v7->cert_dn) )
      return (unsigned int)-7;
    v17 = v7->rsa_ctx;
    v11 = v17->bi_ctx;
    bi = v17->m;
    v12 = v17->e;
    ctx = v17->bi_ctx;
    if ( !v6 )
    {
LABEL_15:
      pub_exp = bi_clone(v11, v12);
      v14 = bi_clone(ctx, bi);
      v15 = sig_verify(ctx, v2->signature, v2->sig_len, v14, pub_exp);
      bia = v15;
      if ( v15 && (v16 = v2->digest) != 0i64 )
      {
        v9 = 0;
        if ( bi_compare(v15, v16) )
          v9 = -3;
        bi_free(ctx, bia);
      }
      else
      {
        v9 = -3;
      }
      if ( v6 )
      {
        v9 = v21 != 0 ? -10 : -6;
      }
      else if ( v7 )
      {
        v9 = x509_verify(ca_cert_ctxa, v7);
      }
      return v9;
    }
    return (unsigned int)-6;
  }
  v8 = (signed __int64)ca_cert_ctxa;
  if ( ca_cert_ctxa )
  {
    v22 = ca_cert_ctxa;
    while ( *(_QWORD *)v8 )
    {
      if ( !asn1_compare_dn(v2->ca_cert_dn, (char *const *)(*(_QWORD *)v8 + 24i64)) )
      {
        v21 = 1;
        v10 = ca_cert_ctxa->cert[v4]->rsa_ctx;
        v11 = v10->bi_ctx;
        bi = v10->m;
        v12 = v10->e;
        ctx = v10->bi_ctx;
        goto LABEL_15;
      }
      ++v4;
      v8 = (signed __int64)&v22->cert[1];
      v22 = (CA_CERT_CTX *)((char *)v22 + 8);
      if ( v4 >= 512 )
        break;
    }
  }
  if ( v6 )
    return (unsigned int)-6;
  return (unsigned int)-2;
}

