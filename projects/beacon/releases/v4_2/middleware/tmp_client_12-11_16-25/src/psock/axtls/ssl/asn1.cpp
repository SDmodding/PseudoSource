// File Line: 71
// RVA: 0xEF4B74
__int64 __fastcall get_asn1_length(const char *buf, int *offset)
{
  int *v2; // r9
  __int64 v3; // rdx
  const char *v4; // r11
  unsigned int v5; // er8
  char v6; // al
  int v7; // er10
  __int64 v8; // rax
  __int64 v9; // rcx
  int v10; // edx

  v2 = offset;
  v3 = *offset;
  v4 = buf;
  LOBYTE(v5) = buf[v3];
  if ( (v5 & 0x80u) != 0 )
  {
    v6 = buf[v3];
    v7 = v3 + 1;
    v5 = 0;
    *v2 = v3 + 1;
    v8 = v6 & 0x7F;
    if ( (signed int)v8 > 0 )
    {
      do
      {
        v9 = v7++;
        v10 = (unsigned __int8)v4[v9];
        *v2 = v7;
        v5 = v10 + (v5 << 8);
        --v8;
      }
      while ( v8 );
    }
  }
  else
  {
    v5 = (unsigned __int8)v5;
    *v2 = v3 + 1;
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
signed __int64 __fastcall asn1_skip_obj(const char *buf, int *offset, int obj_type)
{
  int *v3; // rbx
  __int64 v4; // rdx

  v3 = offset;
  v4 = *offset;
  if ( (unsigned __int8)buf[v4] != obj_type )
    return 0xFFFFFFFFi64;
  *v3 = v4 + 1;
  *v3 += get_asn1_length(buf, v3);
  return 0i64;
}

// File Line: 125
// RVA: 0xEF4460
char *__fastcall asn1_get_int(const char *buf, int *offset, char **object)
{
  const char *v3; // rsi
  __int64 v4; // rcx
  char **v5; // r14
  int *v6; // rdi
  unsigned int v7; // ebx
  int v8; // eax
  __int64 v9; // rax
  char *result; // rax

  v3 = buf;
  v4 = *offset;
  v5 = object;
  v6 = offset;
  if ( v3[v4] != 2 )
    return (char *)(unsigned int)-1;
  *offset = v4 + 1;
  v8 = get_asn1_length(v3, offset);
  v7 = v8;
  if ( v8 < 0 )
    return (char *)v7;
  if ( v8 > 1 )
  {
    v9 = *v6;
    if ( !v3[v9] )
    {
      --v7;
      *v6 = v9 + 1;
    }
  }
  result = (char *)ax_malloc((signed int)v7);
  *v5 = result;
  if ( result )
  {
    memmove(result, &v3[*v6], (signed int)v7);
    *v6 += v7;
    return (char *)v7;
  }
  return result;
}

// File Line: 214
// RVA: 0xEF4600
__int64 __fastcall asn1_get_utc_time(const char *buf, int *offset, __int64 *t)
{
  __int64 v3; // r9
  const char *v4; // rdi
  unsigned int v5; // ecx
  char v6; // r10
  __int64 *v7; // r14
  int *v8; // rsi
  int v9; // eax
  __int64 v10; // rbx
  int v11; // ebp
  int v12; // edx
  int v13; // eax
  char Dst; // [rsp+20h] [rbp-58h]
  int v16; // [rsp+2Ch] [rbp-4Ch]
  int v17; // [rsp+30h] [rbp-48h]
  int v18; // [rsp+34h] [rbp-44h]

  v3 = *offset;
  v4 = buf;
  v5 = -1;
  v6 = v4[v3];
  v7 = t;
  v8 = offset;
  *offset = v3 + 1;
  if ( v6 == 23 )
  {
    v9 = get_asn1_length(v4, offset);
    v10 = *v8;
    v11 = v9;
    memset(&Dst, 0, 0x24ui64);
    v12 = (unsigned __int8)v4[v10 + 1] + 2 * (5 * (unsigned __int8)v4[v10] - 264);
    v18 = v12;
    if ( v12 <= 50 )
      v18 = v12 + 100;
    v13 = (unsigned __int8)v4[v10 + 4];
    v17 = (unsigned __int8)v4[v10 + 3] + 10 * (unsigned __int8)v4[v10 + 2] - 529;
    v16 = (unsigned __int8)v4[v10 + 5] + 2 * (5 * v13 - 264);
    *v7 = mktime64((tm *)&Dst);
    *v8 += v11;
    v5 = 0;
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
  const char *v3; // rsi
  __int64 v4; // rcx
  _x509_ctx *v5; // rbp
  int *v6; // rdi
  unsigned int v7; // ebx

  v3 = cert;
  v4 = *offset;
  v5 = x509_ctx;
  v6 = offset;
  if ( v3[v4] != 48
    || (*offset = v4 + 1, v7 = 0, get_asn1_length(v3, offset) < 0)
    || (unsigned int)asn1_get_utc_time(v3, v6, &v5->not_before)
    || (unsigned int)asn1_get_utc_time(v3, v6, &v5->not_after) )
  {
    v7 = 1;
  }
  return v7;
}

// File Line: 295
// RVA: 0xEF44FC
__int64 __fastcall asn1_get_printable_str(const char *buf, int *offset, char **str)
{
  const char *v3; // rbp
  __int64 v4; // rcx
  signed __int64 v5; // rdi
  char **v6; // r14
  int *v7; // rsi
  signed int v8; // edx
  int v9; // eax
  int v10; // eax
  __int64 v11; // rbx
  __int64 v12; // rax
  int v13; // er11
  signed __int64 v14; // r10
  signed __int64 v15; // r8
  int v16; // kr00_4
  char *v17; // rax

  v3 = buf;
  v4 = *offset;
  LODWORD(v5) = -1;
  v6 = str;
  v7 = offset;
  if ( v3[v4] <= 0x1Eu )
  {
    v8 = 1079513088;
    if ( _bittest(&v8, (unsigned __int8)v3[v4]) )
    {
      *v7 = v4 + 1;
      v9 = get_asn1_length(v3, v7);
      v5 = v9;
      if ( v3[*v7 - 1] == 30 )
      {
        v10 = v9 / 2;
        v11 = v10;
        v12 = ax_malloc(v10 + 1);
        *v6 = (char *)v12;
        if ( v12 )
        {
          v13 = 0;
          v14 = 0i64;
          if ( (signed int)v5 > 0 )
          {
            do
            {
              v15 = v14 + *v7;
              v14 += 2i64;
              v16 = v13;
              v13 += 2;
              (*v6)[v16 / 2] = v3[v15 + 1];
            }
            while ( v14 < v5 );
          }
          (*v6)[v11] = 0;
        }
      }
      else
      {
        v17 = (char *)ax_malloc(v9 + 1);
        *v6 = v17;
        if ( v17 )
        {
          memmove(v17, &v3[*v7], v5);
          (*v6)[v5] = 0;
        }
      }
      *v7 += v5;
    }
  }
  return (unsigned int)v5;
}

// File Line: 341
// RVA: 0xEF46E0
__int64 __fastcall asn1_name(const char *cert, int *offset, char **dn)
{
  const char *v3; // rdi
  __int64 v4; // rcx
  unsigned int v5; // ebp
  char **v6; // r14
  int *v7; // rbx
  __int64 v8; // rcx
  __int64 v9; // rcx
  __int64 v10; // rcx
  int v11; // esi
  int v12; // eax
  int v13; // er9
  __int64 v14; // rdx
  char v15; // r8
  int v16; // edx
  __int64 v17; // rax
  int v18; // edx
  char v19; // cl
  __int64 v20; // rcx
  char *str; // [rsp+40h] [rbp+8h]

  str = 0i64;
  v3 = cert;
  v4 = *offset;
  v5 = -1;
  v6 = dn;
  v7 = offset;
  if ( v3[v4] == 48 )
  {
    *offset = v4 + 1;
    if ( get_asn1_length(v3, offset) >= 0 )
    {
LABEL_3:
      while ( 1 )
      {
        v8 = *v7;
        if ( v3[v8] != 49 )
          break;
        *v7 = v8 + 1;
        if ( get_asn1_length(v3, v7) < 0 )
          break;
        v9 = *v7;
        if ( v3[v9] != 48 )
          return v5;
        *v7 = v9 + 1;
        if ( get_asn1_length(v3, v7) < 0 )
          return v5;
        v10 = *v7;
        v11 = 0;
        if ( v3[v10] == 6 )
        {
          *v7 = v10 + 1;
          v12 = get_asn1_length(v3, v7);
          v13 = v12;
          if ( v12 >= 0 )
          {
            if ( v12 != 3 )
              goto LABEL_27;
            v14 = *v7;
            v15 = v3[v14];
            v16 = v14 + 1;
            *v7 = v16;
            if ( v15 != 85 || (v17 = v16, v18 = v16 + 1, v19 = v3[v17], *v7 = v18, v19 != 4) )
            {
LABEL_27:
              *v7 += v13;
            }
            else
            {
              v11 = (unsigned __int8)v3[v18];
              *v7 = v18 + 1;
            }
            if ( v11 < 0 )
              return v5;
          }
        }
        if ( (signed int)asn1_get_printable_str(v3, v7, &str) < 0 )
        {
          ax_free(str);
          return v5;
        }
        v20 = 0i64;
        while ( v11 != (unsigned __int8)g_dn_types[v20] || v6[v20] )
        {
          if ( ++v20 >= 3 )
          {
            ax_free(str);
            goto LABEL_3;
          }
        }
        v6[v20] = str;
      }
      v5 = 0;
    }
  }
  return v5;
}

// File Line: 392
// RVA: 0xEF4860
__int64 __fastcall asn1_public_key(const char *cert, int *offset, _x509_ctx *x509_ctx)
{
  const char *v3; // rsi
  __int64 v4; // rcx
  unsigned int v5; // ebx
  _x509_ctx *v6; // rbp
  int *v7; // rdi
  __int64 v8; // rcx
  __int64 v9; // rcx
  int v10; // ebx
  int pub_len; // eax
  char *object; // [rsp+50h] [rbp+8h]
  char *pub_exp; // [rsp+58h] [rbp+10h]

  object = 0i64;
  pub_exp = 0i64;
  v3 = cert;
  v4 = *offset;
  v5 = -1;
  v6 = x509_ctx;
  v7 = offset;
  if ( v3[v4] == 48 )
  {
    *offset = v4 + 1;
    if ( get_asn1_length(v3, offset) >= 0 && !asn1_skip_obj(v3, v7, 48) )
    {
      v8 = *v7;
      if ( v3[v8] == 3 )
      {
        *v7 = v8 + 1;
        if ( get_asn1_length(v3, v7) >= 0 )
        {
          v9 = ++*v7;
          if ( v3[v9] == 48 )
          {
            *v7 = v9 + 1;
            if ( get_asn1_length(v3, v7) >= 0 )
            {
              v10 = (unsigned __int64)asn1_get_int(v3, v7, &object);
              pub_len = (unsigned __int64)asn1_get_int(v3, v7, &pub_exp);
              RSA_pub_key_new(&v6->rsa_ctx, object, v10, pub_exp, pub_len);
              ax_free(object);
              ax_free(pub_exp);
              v5 = 0;
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
  _x509_ctx *v5; // rdi
  char v6; // r10
  int *v7; // rbx
  const char *v8; // rbp
  char *v9; // rax

  v3 = *offset;
  v4 = -1;
  v5 = x509_ctx;
  v6 = cert[v3];
  v7 = offset;
  v8 = cert;
  *offset = v3 + 1;
  if ( v6 == 3 )
  {
    x509_ctx->sig_len = get_asn1_length(cert, offset) - 1;
    ++*v7;
    v9 = (char *)ax_malloc(v5->sig_len);
    v5->signature = v9;
    if ( v9 )
    {
      memmove(v9, &v8[*v7], v5->sig_len);
      *v7 += v5->sig_len;
      v4 = 0;
    }
  }
  return v4;
}

// File Line: 464
// RVA: 0xEF4BC8
void __fastcall remove_ca_certs(CA_CERT_CTX *ca_cert_ctx)
{
  CA_CERT_CTX *v1; // rbx
  signed int v2; // esi
  CA_CERT_CTX *v3; // rdi

  if ( ca_cert_ctx )
  {
    v1 = ca_cert_ctx;
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
    ax_free(v1);
  }
}

// File Line: 484
// RVA: 0xEF42D8
int __fastcall asn1_compare_dn(char *const *dn1, char *const *dn2)
{
  signed __int64 v2; // rdi
  const char **v3; // rbx
  signed __int64 v4; // rsi
  __int64 v5; // rax

  v2 = 0i64;
  v3 = (const char **)dn1;
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
signed __int64 __fastcall asn1_find_oid(const char *cert, int *offset, const char *oid, int oid_length)
{
  const char *v4; // rsi
  __int64 v5; // rcx
  size_t v6; // rbp
  const char *v7; // r12
  int *v8; // rdi
  int v9; // eax
  int v10; // er14
  bool i; // sf
  unsigned __int8 v12; // of
  __int64 v13; // rcx
  int v14; // ebx
  int v15; // er15
  __int64 v16; // rcx
  int v17; // ebx
  int v18; // eax

  v4 = cert;
  v5 = *offset;
  v6 = oid_length;
  v7 = oid;
  v8 = offset;
  if ( v4[v5] == 48 )
  {
    *offset = v5 + 1;
    v9 = get_asn1_length(v4, offset);
    if ( v9 > 0 )
    {
      v10 = *v8 + v9;
      v12 = __OFSUB__(*v8, v10);
      for ( i = -v9 < 0; i ^ v12; i = v15 - v10 < 0 )
      {
        v13 = *v8;
        v14 = (unsigned __int8)v4[v13];
        *v8 = v13 + 1;
        v15 = get_asn1_length(v4, v8) + *v8;
        if ( v14 == 48 )
        {
          v16 = *v8;
          v17 = (unsigned __int8)v4[v16];
          *v8 = v16 + 1;
          v18 = get_asn1_length(v4, v8);
          if ( v17 == 6 && v18 == (_DWORD)v6 && !memcmp(&v4[*v8], v7, v6) )
          {
            *v8 += v6;
            return 1i64;
          }
        }
        *v8 = v15;
        v12 = __OFSUB__(v15, v10);
      }
    }
  }
  return 0i64;
}

// File Line: 531
// RVA: 0xEF4418
__int64 __fastcall asn1_find_subjectaltname(const char *cert, int offset)
{
  int v2; // eax
  int offseta; // [rsp+20h] [rbp-18h]

  offseta = offset;
  v2 = asn1_find_oid(cert, &offseta, sig_subject_alt_name, 3);
  return offseta & (unsigned int)-(v2 != 0);
}

// File Line: 549
// RVA: 0xEF49E8
__int64 __fastcall asn1_signature_type(const char *cert, int *offset, _x509_ctx *x509_ctx)
{
  __int64 v3; // r9
  unsigned int v4; // esi
  _x509_ctx *v5; // rbp
  char v6; // r10
  int *v7; // rbx
  const char *v8; // rdi
  int v9; // er14

  v3 = *offset;
  v4 = -1;
  v5 = x509_ctx;
  v6 = cert[v3];
  v7 = offset;
  v8 = cert;
  *offset = v3 + 1;
  if ( v6 == 6 )
  {
    v9 = get_asn1_length(cert, offset);
    if ( v9 == 5 && !memcmp(sig_iis6_oid, &v8[*v7], 5ui64) )
    {
      v5->sig_type = 5;
LABEL_7:
      *v7 += v9;
      asn1_skip_obj(v8, v7, 5);
      return 0;
    }
    if ( !memcmp(sig_oid_prefix, &v8[*v7], 8ui64) )
    {
      v5->sig_type = v8[*v7 + 8];
      goto LABEL_7;
    }
  }
  return v4;
}

