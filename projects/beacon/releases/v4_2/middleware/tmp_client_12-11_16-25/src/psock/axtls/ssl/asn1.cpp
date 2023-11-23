// File Line: 71
// RVA: 0xEF4B74
__int64 __fastcall get_asn1_length(const char *buf, int *offset)
{
  __int64 v3; // rdx
  unsigned int v5; // r8d
  char v6; // al
  int v7; // r10d
  __int64 v8; // rax
  __int64 v9; // rcx
  int v10; // edx

  v3 = *offset;
  LOBYTE(v5) = buf[v3];
  if ( (v5 & 0x80u) != 0 )
  {
    v6 = buf[v3];
    v7 = v3 + 1;
    v5 = 0;
    *offset = v3 + 1;
    v8 = v6 & 0x7F;
    if ( (_DWORD)v8 )
    {
      do
      {
        v9 = v7++;
        v10 = (unsigned __int8)buf[v9];
        *offset = v7;
        v5 = v10 + (v5 << 8);
        --v8;
      }
      while ( v8 );
    }
  }
  else
  {
    v5 = (unsigned __int8)v5;
    *offset = v3 + 1;
  }
  return v5;
}

// File Line: 97
// RVA: 0xEF4844
int __fastcall asn1_next_obj(const char *buf, int *offset, int obj_type)
{
  __int64 v3; // r10

  v3 = *offset;
  if ( (unsigned __int8)buf[v3] != obj_type )
    return -1;
  *offset = v3 + 1;
  return get_asn1_length(buf, offset);
}

// File Line: 109
// RVA: 0xEF4AA8
__int64 __fastcall asn1_skip_obj(const char *buf, int *offset, int obj_type)
{
  __int64 v4; // rdx

  v4 = *offset;
  if ( (unsigned __int8)buf[v4] != obj_type )
    return 0xFFFFFFFFi64;
  *offset = v4 + 1;
  *offset += get_asn1_length(buf, offset);
  return 0i64;
}

// File Line: 125
// RVA: 0xEF4460
char *__fastcall asn1_get_int(const char *buf, int *offset, char **object)
{
  __int64 v4; // rcx
  unsigned int v7; // ebx
  int asn1_length; // eax
  __int64 v9; // rax
  char *result; // rax

  v4 = *offset;
  if ( buf[v4] != 2 )
    return (char *)(unsigned int)-1;
  *offset = v4 + 1;
  asn1_length = get_asn1_length(buf, offset);
  v7 = asn1_length;
  if ( asn1_length < 0 )
    return (char *)v7;
  if ( asn1_length > 1 )
  {
    v9 = *offset;
    if ( !buf[v9] )
    {
      --v7;
      *offset = v9 + 1;
    }
  }
  result = (char *)ax_malloc((int)v7);
  *object = result;
  if ( result )
  {
    memmove(result, &buf[*offset], (int)v7);
    *offset += v7;
    return (char *)v7;
  }
  return result;
}

// File Line: 214
// RVA: 0xEF4600
__int64 __fastcall asn1_get_utc_time(const char *buf, int *offset, __int64 *t)
{
  __int64 v3; // r9
  unsigned int v5; // ecx
  char v6; // r10
  int asn1_length; // eax
  __int64 v10; // rbx
  int v11; // ebp
  int v12; // edx
  int v13; // eax
  tm Dst; // [rsp+20h] [rbp-58h] BYREF

  v3 = *offset;
  v5 = -1;
  v6 = buf[v3];
  *offset = v3 + 1;
  if ( v6 == 23 )
  {
    asn1_length = get_asn1_length(buf, offset);
    v10 = *offset;
    v11 = asn1_length;
    memset(&Dst, 0, sizeof(Dst));
    v12 = (unsigned __int8)buf[v10 + 1] + 2 * (5 * (unsigned __int8)buf[v10] - 264);
    Dst.tm_year = v12;
    if ( v12 <= 50 )
      Dst.tm_year = v12 + 100;
    v13 = (unsigned __int8)buf[v10 + 4];
    Dst.tm_mon = (unsigned __int8)buf[v10 + 3] + 10 * (unsigned __int8)buf[v10 + 2] - 529;
    Dst.tm_mday = (unsigned __int8)buf[v10 + 5] + 2 * (5 * v13 - 264);
    *t = mktime64(&Dst);
    *offset += v11;
    return 0;
  }
  return v5;
}

// File Line: 245
// RVA: 0xEF4B58
__int64 __fastcall asn1_version(const char *cert, int *offset, _x509_ctx *__formal)
{
  *offset += 2;
  return (unsigned int)-((unsigned int)asn1_skip_obj(cert, offset, 2) != 0);
}

// File Line: 261
// RVA: 0xEF4ADC
__int64 __fastcall asn1_validity(const char *cert, int *offset, _x509_ctx *x509_ctx)
{
  __int64 v4; // rcx
  unsigned int v7; // ebx

  v4 = *offset;
  if ( cert[v4] != 48 )
    return 1;
  *offset = v4 + 1;
  v7 = 0;
  if ( get_asn1_length(cert, offset) < 0
    || (unsigned int)asn1_get_utc_time(cert, offset, &x509_ctx->not_before)
    || (unsigned int)asn1_get_utc_time(cert, offset, &x509_ctx->not_after) )
  {
    return 1;
  }
  return v7;
}

// File Line: 295
// RVA: 0xEF44FC
__int64 __fastcall asn1_get_printable_str(const char *buf, int *offset, char **str)
{
  __int64 v4; // rcx
  signed __int64 v5; // rdi
  int v8; // edx
  int asn1_length; // eax
  int v10; // eax
  __int64 v11; // rbx
  char *v12; // rax
  int v13; // r11d
  signed __int64 v14; // r10
  signed __int64 v15; // r8
  int v16; // kr00_4
  char *v17; // rax

  v4 = *offset;
  LODWORD(v5) = -1;
  if ( buf[v4] <= 0x1Eu )
  {
    v8 = 1079513088;
    if ( _bittest(&v8, (unsigned __int8)buf[v4]) )
    {
      *offset = v4 + 1;
      asn1_length = get_asn1_length(buf, offset);
      v5 = asn1_length;
      if ( buf[*offset - 1] == 30 )
      {
        v10 = asn1_length / 2;
        v11 = v10;
        v12 = (char *)ax_malloc(v10 + 1);
        *str = v12;
        if ( v12 )
        {
          v13 = 0;
          v14 = 0i64;
          if ( (int)v5 > 0 )
          {
            do
            {
              v15 = v14 + *offset;
              v14 += 2i64;
              v16 = v13;
              v13 += 2;
              (*str)[v16 / 2] = buf[v15 + 1];
            }
            while ( v14 < v5 );
          }
          (*str)[v11] = 0;
        }
      }
      else
      {
        v17 = (char *)ax_malloc(asn1_length + 1);
        *str = v17;
        if ( v17 )
        {
          memmove(v17, &buf[*offset], v5);
          (*str)[v5] = 0;
        }
      }
      *offset += v5;
    }
  }
  return (unsigned int)v5;
}

// File Line: 341
// RVA: 0xEF46E0
__int64 __fastcall asn1_name(const char *cert, int *offset, char **dn)
{
  __int64 v4; // rcx
  unsigned int v5; // ebp
  __int64 v8; // rcx
  __int64 v9; // rcx
  __int64 v10; // rcx
  int v11; // esi
  int asn1_length; // eax
  int v13; // r9d
  __int64 v14; // rdx
  char v15; // r8
  int v16; // edx
  __int64 v17; // rax
  int v18; // edx
  char v19; // cl
  __int64 v20; // rcx
  char *str; // [rsp+40h] [rbp+8h] BYREF

  str = 0i64;
  v4 = *offset;
  v5 = -1;
  if ( cert[v4] == 48 )
  {
    *offset = v4 + 1;
    if ( get_asn1_length(cert, offset) >= 0 )
    {
LABEL_3:
      while ( 1 )
      {
        v8 = *offset;
        if ( cert[v8] != 49 )
          return 0;
        *offset = v8 + 1;
        if ( get_asn1_length(cert, offset) < 0 )
          return 0;
        v9 = *offset;
        if ( cert[v9] != 48 )
          return v5;
        *offset = v9 + 1;
        if ( get_asn1_length(cert, offset) < 0 )
          return v5;
        v10 = *offset;
        v11 = 0;
        if ( cert[v10] == 6 )
        {
          *offset = v10 + 1;
          asn1_length = get_asn1_length(cert, offset);
          v13 = asn1_length;
          if ( asn1_length >= 0 )
          {
            if ( asn1_length != 3 )
              goto LABEL_13;
            v14 = *offset;
            v15 = cert[v14];
            v16 = v14 + 1;
            *offset = v16;
            if ( v15 != 85 )
              goto LABEL_13;
            v17 = v16;
            v18 = v16 + 1;
            v19 = cert[v17];
            *offset = v18;
            if ( v19 == 4 )
            {
              v11 = (unsigned __int8)cert[v18];
              *offset = v18 + 1;
            }
            else
            {
LABEL_13:
              *offset += v13;
            }
          }
        }
        if ( (int)asn1_get_printable_str(cert, offset, &str) < 0 )
        {
          ax_free(str);
          return v5;
        }
        v20 = 0i64;
        while ( v11 != (unsigned __int8)g_dn_types[v20] || dn[v20] )
        {
          if ( ++v20 >= 3 )
          {
            ax_free(str);
            goto LABEL_3;
          }
        }
        dn[v20] = str;
      }
    }
  }
  return v5;
}

// File Line: 392
// RVA: 0xEF4860
__int64 __fastcall asn1_public_key(const char *cert, int *offset, _x509_ctx *x509_ctx)
{
  __int64 v4; // rcx
  unsigned int v5; // ebx
  __int64 v8; // rcx
  __int64 v9; // rcx
  int v10; // ebx
  int pub_len; // eax
  char *object; // [rsp+50h] [rbp+8h] BYREF
  char *pub_exp; // [rsp+58h] [rbp+10h] BYREF

  object = 0i64;
  pub_exp = 0i64;
  v4 = *offset;
  v5 = -1;
  if ( cert[v4] == 48 )
  {
    *offset = v4 + 1;
    if ( get_asn1_length(cert, offset) >= 0 && !asn1_skip_obj(cert, offset, 48) )
    {
      v8 = *offset;
      if ( cert[v8] == 3 )
      {
        *offset = v8 + 1;
        if ( get_asn1_length(cert, offset) >= 0 )
        {
          v9 = ++*offset;
          if ( cert[v9] == 48 )
          {
            *offset = v9 + 1;
            if ( get_asn1_length(cert, offset) >= 0 )
            {
              v10 = (unsigned int)asn1_get_int(cert, offset, &object);
              pub_len = (unsigned int)asn1_get_int(cert, offset, &pub_exp);
              RSA_pub_key_new(&x509_ctx->rsa_ctx, object, v10, pub_exp, pub_len);
              ax_free(object);
              ax_free(pub_exp);
              return 0;
            }
          }
        }
      }
    }
  }
  return v5;
}

// File Line: 424
// RVA: 0xEF4960
__int64 __fastcall asn1_signature(const char *cert, int *offset, _x509_ctx *x509_ctx)
{
  __int64 v3; // r9
  unsigned int v4; // esi
  char v6; // r10
  char *v9; // rax

  v3 = *offset;
  v4 = -1;
  v6 = cert[v3];
  *offset = v3 + 1;
  if ( v6 == 3 )
  {
    x509_ctx->sig_len = get_asn1_length(cert, offset) - 1;
    ++*offset;
    v9 = (char *)ax_malloc(x509_ctx->sig_len);
    x509_ctx->signature = v9;
    if ( v9 )
    {
      memmove(v9, &cert[*offset], x509_ctx->sig_len);
      *offset += x509_ctx->sig_len;
      return 0;
    }
  }
  return v4;
}

// File Line: 464
// RVA: 0xEF4BC8
void __fastcall remove_ca_certs(CA_CERT_CTX *ca_cert_ctx)
{
  int v2; // esi
  CA_CERT_CTX *v3; // rdi

  if ( ca_cert_ctx )
  {
    v2 = 0;
    v3 = ca_cert_ctx;
    do
    {
      if ( !v3->cert[0] )
        break;
      x509_free(v3->cert[0]);
      v3->cert[0] = 0i64;
      ++v2;
      v3 = (CA_CERT_CTX *)((char *)v3 + 8);
    }
    while ( v2 < 512 );
    ax_free(ca_cert_ctx);
  }
}

// File Line: 484
// RVA: 0xEF42D8
int __fastcall asn1_compare_dn(const char **dn1, char *const *dn2)
{
  __int64 v2; // rdi
  const char **v3; // rbx
  signed __int64 v4; // rsi
  __int64 v5; // rax

  v2 = 0i64;
  v3 = dn1;
  v4 = (char *)dn2 - (char *)dn1;
  while ( 1 )
  {
    v5 = *(__int64 *)((char *)v3 + v4);
    if ( *v3 )
    {
      if ( !v5 )
        break;
      LODWORD(v5) = strcmp(*v3, *(const char **)((char *)v3 + v4));
    }
    else if ( v5 )
    {
      break;
    }
    if ( (_DWORD)v5 )
      break;
    ++v2;
    ++v3;
    if ( v2 >= 3 )
      return v5;
  }
  LODWORD(v5) = 1;
  return v5;
}

// File Line: 498
// RVA: 0xEF433C
__int64 __fastcall asn1_find_oid(const char *cert, int *offset, const char *oid, int oid_length)
{
  __int64 v5; // rcx
  size_t v6; // rbp
  int asn1_length; // eax
  int v10; // r14d
  bool i; // cc
  __int64 v12; // rcx
  int v13; // ebx
  int v14; // r15d
  __int64 v15; // rcx
  int v16; // ebx
  int v17; // eax

  v5 = *offset;
  v6 = oid_length;
  if ( cert[v5] == 48 )
  {
    *offset = v5 + 1;
    asn1_length = get_asn1_length(cert, offset);
    if ( asn1_length > 0 )
    {
      v10 = *offset + asn1_length;
      for ( i = *offset < v10; i; i = v14 < v10 )
      {
        v12 = *offset;
        v13 = (unsigned __int8)cert[v12];
        *offset = v12 + 1;
        v14 = get_asn1_length(cert, offset) + *offset;
        if ( v13 == 48 )
        {
          v15 = *offset;
          v16 = (unsigned __int8)cert[v15];
          *offset = v15 + 1;
          v17 = get_asn1_length(cert, offset);
          if ( v16 == 6 && v17 == (_DWORD)v6 && !memcmp(&cert[*offset], oid, v6) )
          {
            *offset += v6;
            return 1i64;
          }
        }
        *offset = v14;
      }
    }
  }
  return 0i64;
}

// File Line: 531
// RVA: 0xEF4418
__int64 __fastcall asn1_find_subjectaltname(const char *cert, int offset)
{
  int oid; // eax
  int offseta; // [rsp+20h] [rbp-18h] BYREF

  offseta = offset;
  oid = asn1_find_oid(cert, &offseta, sig_subject_alt_name, 3);
  return offseta & (unsigned int)-(oid != 0);
}

// File Line: 549
// RVA: 0xEF49E8
__int64 __fastcall asn1_signature_type(const char *cert, int *offset, _x509_ctx *x509_ctx)
{
  __int64 v3; // r9
  unsigned int v4; // esi
  char v6; // r10
  int asn1_length; // r14d

  v3 = *offset;
  v4 = -1;
  v6 = cert[v3];
  *offset = v3 + 1;
  if ( v6 == 6 )
  {
    asn1_length = get_asn1_length(cert, offset);
    if ( asn1_length == 5 && !memcmp(sig_iis6_oid, &cert[*offset], 5ui64) )
    {
      x509_ctx->sig_type = 5;
LABEL_7:
      *offset += asn1_length;
      asn1_skip_obj(cert, offset, 5);
      return 0;
    }
    if ( !memcmp(sig_oid_prefix, &cert[*offset], 8ui64) )
    {
      x509_ctx->sig_type = cert[*offset + 8];
      goto LABEL_7;
    }
  }
  return v4;
}

