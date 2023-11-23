// File Line: 85
// RVA: 0xEF0DA0
__int64 __fastcall x509_new(const char *cert, int *len, _x509_ctx **ctx)
{
  int *v3; // r12
  unsigned int v5; // r15d
  _x509_ctx *v7; // rsi
  __int64 v8; // rbx
  BI_CTX *bi_ctx; // r14
  char sig_type; // al
  int v11; // r8d
  int v12; // eax
  int v13; // ecx
  int v14; // r14d
  __int64 v15; // r13
  int v16; // eax
  int v17; // r15d
  int v18; // ebx
  size_t asn1_length; // r12
  char **v20; // rax
  __int64 v21; // rbx
  char *v22; // rcx
  int v25; // [rsp+28h] [rbp-71h] BYREF
  int subjectaltname; // [rsp+2Ch] [rbp-6Dh] BYREF
  int v27; // [rsp+30h] [rbp-69h] BYREF
  int offset[3]; // [rsp+34h] [rbp-65h] BYREF
  SHA1_CTX ctxa; // [rsp+40h] [rbp-59h] BYREF
  char digest[24]; // [rsp+A0h] [rbp+7h] BYREF

  v25 = 0;
  offset[0] = 0;
  v3 = len;
  v5 = -1;
  v7 = (_x509_ctx *)ax_calloc(1ui64, 0x70ui64);
  *ctx = v7;
  if ( v7 )
  {
    asn1_skip_obj(cert, offset, 48);
    if ( asn1_next_obj(cert, &v25, 48) >= 0 )
    {
      v8 = v25;
      v27 = v25;
      asn1_skip_obj(cert, &v27, 48);
      if ( asn1_next_obj(cert, &v25, 48) >= 0
        && (cert[v25] != -96 || !asn1_version(cert, &v25, v7))
        && !asn1_skip_obj(cert, &v25, 2)
        && asn1_next_obj(cert, &v25, 48) >= 0 )
      {
        if ( asn1_signature_type(cert, &v25, v7) )
          return (unsigned int)-8;
        if ( !asn1_name(cert, &v25, v7->ca_cert_dn)
          && !asn1_validity(cert, &v25, v7)
          && !asn1_name(cert, &v25, v7->cert_dn)
          && !asn1_public_key(cert, &v25, v7) )
        {
          bi_ctx = v7->rsa_ctx->bi_ctx;
          sig_type = v7->sig_type;
          switch ( sig_type )
          {
            case 4:
              MD5_Init((MD5_CTX *)&ctxa);
              MD5_Update((MD5_CTX *)&ctxa, &cert[v8], v27 - v8);
              MD5_Final(digest, (MD5_CTX *)&ctxa);
              break;
            case 5:
              SHA1_Init(&ctxa);
              SHA1_Update(&ctxa, &cert[v8], v27 - v8);
              SHA1_Final(digest, &ctxa);
              v11 = 20;
LABEL_21:
              v7->digest = bi_import(bi_ctx, digest, v11);
LABEL_22:
              if ( cert[v25] == -93 )
              {
                ++v25;
                get_asn1_length(cert, &v25);
                subjectaltname = asn1_find_subjectaltname(cert, v25);
                if ( subjectaltname > 0 && asn1_next_obj(cert, &subjectaltname, 4) > 0 )
                {
                  v12 = asn1_next_obj(cert, &subjectaltname, 48);
                  if ( v12 > 0 )
                  {
                    v13 = subjectaltname;
                    v14 = 0;
                    v15 = 0i64;
                    v16 = subjectaltname + v12;
                    if ( subjectaltname < v16 )
                    {
                      v17 = v16;
                      do
                      {
                        v18 = (unsigned __int8)cert[v13];
                        subjectaltname = v13 + 1;
                        asn1_length = get_asn1_length(cert, &subjectaltname);
                        if ( v18 == 130 )
                        {
                          v20 = (char **)ax_realloc(v7->subject_alt_dnsnames, 8i64 * (v14 + 2));
                          v7->subject_alt_dnsnames = v20;
                          if ( v20 )
                          {
                            v21 = v15++;
                            v7->subject_alt_dnsnames[v21] = (char *)ax_malloc((int)asn1_length + 1);
                            v7->subject_alt_dnsnames[v15] = 0i64;
                            v22 = v7->subject_alt_dnsnames[v21];
                            if ( v22 )
                            {
                              memmove(v22, &cert[subjectaltname], asn1_length);
                              v7->subject_alt_dnsnames[v21][asn1_length] = 0;
                            }
                            ++v14;
                          }
                          else
                          {
                            v14 = 0;
                            v15 = 0i64;
                          }
                        }
                        v13 = asn1_length + subjectaltname;
                        subjectaltname = v13;
                      }
                      while ( v13 < v17 );
                      v3 = len;
                      v5 = -1;
                    }
                  }
                }
              }
              v25 = v27;
              if ( !asn1_skip_obj(cert, &v25, 48) && !asn1_signature(cert, &v25, v7) )
              {
                if ( v3 )
                  *v3 = offset[0];
                return 0;
              }
              return v5;
            case 2:
              MD2_Init((MD2_CTX *)&ctxa);
              MD2_Update((MD2_CTX *)&ctxa, &cert[v8], v27 - v8);
              MD2_Final(digest, (MD2_CTX *)&ctxa);
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
  __int64 i; // rbx
  _bigint *digest; // rdx
  void **subject_alt_dnsnames; // rax
  __int64 j; // rbx
  _x509_ctx *next; // rbx

  if ( x509_ctx )
  {
    v1 = x509_ctx;
    do
    {
      for ( i = 0i64; i < 3; ++i )
      {
        ax_free(v1->ca_cert_dn[i]);
        ax_free(v1->cert_dn[i]);
      }
      ax_free(v1->signature);
      digest = v1->digest;
      if ( digest )
        bi_free(v1->rsa_ctx->bi_ctx, digest);
      subject_alt_dnsnames = (void **)v1->subject_alt_dnsnames;
      if ( subject_alt_dnsnames )
      {
        for ( j = 0i64; *subject_alt_dnsnames; subject_alt_dnsnames = (void **)&v1->subject_alt_dnsnames[j] )
        {
          ax_free(*subject_alt_dnsnames);
          ++j;
        }
        ax_free(v1->subject_alt_dnsnames);
      }
      RSA_free(v1->rsa_ctx);
      next = v1->next;
      ax_free(v1);
      v1 = next;
    }
    while ( next );
  }
}

// File Line: 293
// RVA: 0xEF0BAC
_bigint *__fastcall sig_verify(BI_CTX *ctx, const char *sig, int sig_len, _bigint *modulus, _bigint *pub_exp)
{
  __int64 v5; // rdi
  _bigint *v9; // rbx
  _bigint *result; // rax
  char *v11; // rsi
  _bigint *v12; // rax
  _bigint *v13; // rax
  int v14; // edx
  __int64 v15; // rcx
  char v16; // al
  const char *v17; // rdi
  char v18; // cl
  int asn1_length; // eax
  const char *v20; // rdx
  int offset; // [rsp+20h] [rbp-58h] BYREF

  v5 = sig_len;
  v9 = 0i64;
  result = (_bigint *)ax_malloc(sig_len);
  v11 = (char *)result;
  if ( result )
  {
    v12 = bi_import(ctx, sig, v5);
    ctx->mod_offset = 0;
    v13 = bi_mod_power2(ctx, v12, modulus, pub_exp);
    bi_export(ctx, v13, v11, v5);
    v14 = 10;
    ctx->mod_offset = 0;
    v15 = 10i64;
    do
    {
      v16 = v11[v15];
      ++v14;
      ++v15;
    }
    while ( v16 && v15 < v5 );
    if ( (int)v5 - v14 > 0 )
    {
      v17 = &v11[v14];
      offset = 0;
      if ( asn1_next_obj(v17, &offset, 48) >= 0 && !asn1_skip_obj(v17, &offset, 48) )
      {
        v18 = v17[offset++];
        if ( v18 == 4 )
        {
          asn1_length = get_asn1_length(v17, &offset);
          v20 = &v17[offset];
          if ( v20 )
            v9 = bi_import(ctx, v20, asn1_length);
        }
      }
    }
    bi_clear_cache(ctx);
    ax_free(v11);
    return v9;
  }
  return result;
}

// File Line: 351
// RVA: 0xEF117C
__int64 __fastcall x509_verify(CA_CERT_CTX *ca_cert_ctx, _x509_ctx *cert)
{
  int v4; // ebx
  int v5; // eax
  char v6; // bp
  _x509_ctx *next; // rsi
  CA_CERT_CTX *v8; // rax
  unsigned int v9; // ebx
  RSA_CTX *v10; // rax
  BI_CTX *bi_ctx; // rcx
  _bigint *e; // rdx
  _bigint *pub_exp; // rbx
  _bigint *v14; // rax
  _bigint *v15; // rax
  _bigint *digest; // rdx
  RSA_CTX *rsa_ctx; // rax
  _bigint *bi; // [rsp+30h] [rbp-28h]
  _bigint *bia; // [rsp+30h] [rbp-28h]
  int v21; // [rsp+70h] [rbp+18h]
  CA_CERT_CTX *v22; // [rsp+70h] [rbp+18h]
  BI_CTX *ctx; // [rsp+78h] [rbp+20h]

  if ( x509_accept_all )
    return 0i64;
  v4 = 0;
  v21 = 0;
  if ( !cert )
    return (unsigned int)-2;
  v5 = asn1_compare_dn(cert->ca_cert_dn, cert->cert_dn);
  v6 = 0;
  next = cert->next;
  if ( !v5 )
    v6 = 1;
  if ( next )
  {
    if ( asn1_compare_dn(cert->ca_cert_dn, next->cert_dn) )
      return (unsigned int)-7;
    rsa_ctx = next->rsa_ctx;
    bi_ctx = rsa_ctx->bi_ctx;
    bi = rsa_ctx->m;
    e = rsa_ctx->e;
    ctx = bi_ctx;
    if ( !v6 )
    {
LABEL_15:
      pub_exp = bi_clone(bi_ctx, e);
      v14 = bi_clone(ctx, bi);
      v15 = sig_verify(ctx, cert->signature, cert->sig_len, v14, pub_exp);
      bia = v15;
      if ( v15 && (digest = cert->digest) != 0i64 )
      {
        v9 = 0;
        if ( bi_compare(v15, digest) )
          v9 = -3;
        bi_free(ctx, bia);
      }
      else
      {
        v9 = -3;
      }
      if ( v6 )
      {
        return v21 != 0 ? -10 : -6;
      }
      else if ( next )
      {
        return (unsigned int)x509_verify(ca_cert_ctx, next);
      }
      return v9;
    }
    return (unsigned int)-6;
  }
  v8 = ca_cert_ctx;
  if ( ca_cert_ctx )
  {
    v22 = ca_cert_ctx;
    while ( v8->cert[0] )
    {
      if ( !asn1_compare_dn(cert->ca_cert_dn, v8->cert[0]->cert_dn) )
      {
        v21 = 1;
        v10 = ca_cert_ctx->cert[v4]->rsa_ctx;
        bi_ctx = v10->bi_ctx;
        bi = v10->m;
        e = v10->e;
        ctx = bi_ctx;
        goto LABEL_15;
      }
      ++v4;
      v8 = (CA_CERT_CTX *)&v22->cert[1];
      v22 = (CA_CERT_CTX *)((char *)v22 + 8);
      if ( v4 >= 512 )
        break;
    }
  }
  if ( v6 )
    return (unsigned int)-6;
  return (unsigned int)-2;
}

