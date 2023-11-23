// File Line: 183
// RVA: 0xEEE8BC
void __fastcall OSuite::ZOEdmBase::CleanTempData(int __formal)
{
  ;
}

// File Line: 191
// RVA: 0xEEFEEC
_SSL_CTX *__fastcall ssl_ctx_new(int options, int num_sessions)
{
  __int64 v2; // rdi
  _exception *v4; // rax
  _SSL_CTX *v5; // rbx
  SSL_SESSION **v7; // rax

  v2 = num_sessions;
  v4 = (_exception *)ax_calloc(1ui64, 0x60ui64);
  v5 = (_SSL_CTX *)v4;
  if ( !v4 )
    return 0i64;
  v4->type = options;
  if ( OSuite::FComputeHashBegin(v4) < 0 )
  {
    ax_free(v5);
    return 0i64;
  }
  v5->num_sessions = v2;
  v5->mutex = CreateMutexA(0i64, 0, 0i64);
  if ( (_DWORD)v2 )
  {
    v7 = (SSL_SESSION **)ax_calloc(1ui64, 8 * v2);
    v5->ssl_sessions = v7;
    if ( !v7 )
    {
      v5->num_sessions = 0;
      ssl_ctx_free(v5);
      return 0i64;
    }
  }
  return v5;
}

// File Line: 232
// RVA: 0xEEFE00
void __fastcall ssl_ctx_free(_SSL_CTX *ssl_ctx)
{
  _SSL *head; // rcx
  _SSL *next; // rbx
  int v4; // esi
  __int64 v5; // rbx
  SSL_SESSION **ssl_sessions; // rbp
  SSL_SESSION *v7; // rcx
  __int64 v8; // rsi
  SSL_CERT *certs; // rbx
  void *mutex; // rcx

  if ( ssl_ctx )
  {
    head = ssl_ctx->head;
    if ( head )
    {
      do
      {
        next = head->next;
        ssl_free(head);
        head = next;
      }
      while ( next );
    }
    v4 = 0;
    if ( ssl_ctx->num_sessions )
    {
      v5 = 0i64;
      do
      {
        ssl_sessions = ssl_ctx->ssl_sessions;
        v7 = ssl_sessions[v5];
        if ( v7 )
        {
          ax_free(v7);
          ssl_sessions[v5] = 0i64;
        }
        ++v4;
        ++v5;
      }
      while ( v4 < ssl_ctx->num_sessions );
    }
    ax_free(ssl_ctx->ssl_sessions);
    v8 = 0i64;
    certs = ssl_ctx->certs;
    do
    {
      if ( !certs->buf )
        break;
      ax_free(certs->buf);
      ++v8;
      certs->buf = 0i64;
      ++certs;
    }
    while ( v8 < 2 );
    remove_ca_certs(ssl_ctx->ca_cert_ctx);
    mutex = ssl_ctx->mutex;
    ssl_ctx->chain_length = 0;
    CloseHandle(mutex);
    RSA_free(ssl_ctx->rsa_ctx);
    RNG_terminate();
    ax_free(ssl_ctx);
  }
}

// File Line: 278
// RVA: 0xEEFF94
void __fastcall ssl_free(_SSL *ssl)
{
  _SSL_CTX *ssl_ctx; // rdi
  _SSL *prev; // rcx
  _SSL *next; // rax
  _SSL *v5; // rcx
  _SSL *v6; // rax

  if ( ssl )
  {
    send_alert(ssl, 0);
    ssl_ctx = ssl->ssl_ctx;
    WaitForSingleObject(ssl_ctx->mutex, 0xFFFFFFFF);
    prev = ssl->prev;
    next = ssl->next;
    if ( prev )
      prev->next = next;
    else
      ssl_ctx->head = next;
    v5 = ssl->next;
    v6 = ssl->prev;
    if ( v5 )
      v5->prev = v6;
    else
      ssl_ctx->tail = v6;
    ReleaseMutex(ssl_ctx->mutex);
    ax_free(ssl->encrypt_ctx);
    ax_free(ssl->decrypt_ctx);
    disposable_free(ssl);
    x509_free(ssl->x509_ctx);
    ax_free(ssl);
  }
}

// File Line: 319
// RVA: 0xEF017C
__int64 __fastcall ssl_read(_SSL *ssl, char **in_data)
{
  unsigned int v3; // ebx

  v3 = basic_read(ssl, in_data);
  if ( (int)(v3 + 0x80000000) >= 0 && v3 != -256 )
  {
    send_alert(ssl, v3);
    kill_ssl_session(ssl->ssl_ctx->ssl_sessions, ssl);
  }
  return v3;
}

// File Line: 342
// RVA: 0xEF0380
__int64 __fastcall ssl_write(_SSL *ssl, const char *out_data, unsigned int out_len)
{
  unsigned int v3; // edi
  int v6; // ebx
  int v7; // esi
  int v8; // r9d
  int v9; // eax

  v3 = out_len;
  v6 = out_len;
  v7 = 0;
  while ( 1 )
  {
    v8 = v6;
    if ( v6 > 0x4000 )
      v8 = 0x4000;
    v9 = send_packet(ssl, 23, &out_data[v7], v8);
    if ( v9 <= 0 )
      break;
    v6 -= v9;
    v7 += v9;
    if ( v6 <= 0 )
      return v3;
  }
  return (unsigned int)v9;
}

// File Line: 475
// RVA: 0xEF0048
char *__fastcall ssl_get_cert_dn(_SSL *ssl, int component)
{
  _x509_ctx *x509_ctx; // r8
  int v4; // edx
  int v5; // edx
  int v6; // edx
  int v7; // edx

  x509_ctx = ssl->x509_ctx;
  if ( !x509_ctx )
    return 0i64;
  if ( !component )
    return x509_ctx->cert_dn[0];
  v4 = component - 1;
  if ( !v4 )
    return x509_ctx->cert_dn[1];
  v5 = v4 - 1;
  if ( !v5 )
    return x509_ctx->cert_dn[2];
  v6 = v5 - 1;
  if ( !v6 )
    return x509_ctx->ca_cert_dn[0];
  v7 = v6 - 1;
  if ( !v7 )
    return x509_ctx->ca_cert_dn[1];
  if ( v7 != 1 )
    return 0i64;
  return x509_ctx->ca_cert_dn[2];
}

// File Line: 509
// RVA: 0xEF008C
char *__fastcall ssl_get_cert_subject_alt_dnsname(_SSL *ssl, int dnsindex)
{
  _x509_ctx *x509_ctx; // rax
  char **subject_alt_dnsnames; // rax
  __int64 v4; // r8
  __int64 v5; // rcx
  char **i; // rdx

  x509_ctx = ssl->x509_ctx;
  if ( x509_ctx )
  {
    subject_alt_dnsnames = x509_ctx->subject_alt_dnsnames;
    if ( subject_alt_dnsnames )
    {
      v4 = 0i64;
      v5 = dnsindex;
      if ( dnsindex <= 0 )
        return subject_alt_dnsnames[v5];
      for ( i = subject_alt_dnsnames; *i; ++i )
      {
        if ( ++v4 >= v5 )
          return subject_alt_dnsnames[v5];
      }
    }
  }
  return 0i64;
}

// File Line: 602
// RVA: 0xEF00C8
_SSL *__fastcall ssl_new(_SSL_CTX *ssl_ctx, int client_fd)
{
  _SSL *result; // rax
  _SSL *v5; // rbx
  void *mutex; // rcx

  result = (_SSL *)ax_calloc(1ui64, 0x44D8ui64);
  v5 = result;
  if ( result )
  {
    result->ssl_ctx = ssl_ctx;
    result->need_bytes = 5;
    result->client_fd = client_fd;
    result->bm_data = &result->bm_all_data[5];
    result->flag = 1;
    result->hs_status = -1;
    disposable_new(result);
    v5->flag |= ssl_ctx->options;
    WaitForSingleObject(ssl_ctx->mutex, 0xFFFFFFFF);
    if ( ssl_ctx->head )
    {
      v5->prev = ssl_ctx->tail;
      ssl_ctx->tail->next = v5;
    }
    else
    {
      ssl_ctx->head = v5;
    }
    mutex = ssl_ctx->mutex;
    ssl_ctx->tail = v5;
    ReleaseMutex(mutex);
    return v5;
  }
  return result;
}

// File Line: 689
// RVA: 0xEEE8C0
void __fastcall add_hmac_digest(_SSL *ssl, int mode, char *hmac_header, const char *buf, int buf_len, char *hmac_buf)
{
  char *v10; // rax
  char *v11; // rdi
  char *read_sequence; // rdx
  char *client_mac; // r8

  v10 = (char *)ax_malloc(buf_len + 23);
  v11 = v10;
  if ( v10 )
  {
    read_sequence = ssl->read_sequence;
    if ( ((mode - 1) & 0xFFFFFFFD) == 0 )
      read_sequence = ssl->write_sequence;
    memmove(v10, read_sequence, 8ui64);
    memmove(v11 + 8, hmac_header, 5ui64);
    memmove(v11 + 13, buf, buf_len);
    client_mac = ssl->client_mac;
    if ( (unsigned int)(mode - 1) <= 1 )
      client_mac = ssl->server_mac;
    ssl->cipher_info->hmac(v11, buf_len + 13, client_mac, (unsigned __int8)ssl->cipher_info->digest_size, hmac_buf);
    ax_free(v11);
  }
}

// File Line: 741
// RVA: 0xEF03F4
__int64 __fastcall verify_digest(_SSL *ssl, int mode, const char *buf, int read_len)
{
  cipher_info_t *cipher_info; // rdx
  int digest_size; // eax
  int buf_len; // ebx
  char Buf1[24]; // [rsp+30h] [rbp-38h] BYREF

  cipher_info = ssl->cipher_info;
  digest_size = (unsigned __int8)cipher_info->digest_size;
  if ( cipher_info->padding_size )
    buf_len = read_len - (unsigned __int8)buf[read_len - 1] - digest_size - 1;
  else
    buf_len = read_len - digest_size;
  if ( buf_len < 0 )
    return 4294967034i64;
  ssl->hmac_header[3] = BYTE1(buf_len);
  ssl->hmac_header[4] = buf_len;
  add_hmac_digest(ssl, mode, ssl->hmac_header, buf, buf_len, Buf1);
  if ( memcmp(Buf1, &buf[buf_len], (unsigned __int8)ssl->cipher_info->digest_size) )
    return (unsigned int)-262;
  return (unsigned int)buf_len;
}

// File Line: 777
// RVA: 0xEEE9AC
void __fastcall add_packet(_SSL *ssl, const char *pkt, unsigned int len)
{
  MD5_Update(&ssl->dc->md5_ctx, pkt, len);
  SHA1_Update(&ssl->dc->sha1_ctx, pkt, len);
}

// File Line: 843
// RVA: 0xEEF1E8
void __fastcall prf(const char *sec, int sec_len, char *seed, int seed_len, char *out, int olen)
{
  size_t v7; // r13
  char *v9; // r15
  __int64 v10; // rbx
  const char *v11; // rsi
  int v12; // ebx
  __int64 v13; // r14
  char *v14; // r14
  __int64 v15; // r15
  __int64 i; // rcx
  char Src[32]; // [rsp+40h] [rbp-C0h] BYREF
  char msg[16]; // [rsp+60h] [rbp-A0h] BYREF
  char Dst[4]; // [rsp+70h] [rbp-90h] BYREF
  char v21[108]; // [rsp+74h] [rbp-8Ch] BYREF
  char v22[256]; // [rsp+E0h] [rbp-20h] BYREF
  char digest[256]; // [rsp+1E0h] [rbp+E0h] BYREF

  v7 = seed_len;
  v9 = digest;
  v10 = sec_len / 2;
  v11 = &sec[v10];
  v12 = (sec_len & 1) + v10;
  hmac_md5(seed, seed_len, sec, v12, msg);
  memmove(Dst, seed, v7);
  hmac_md5(msg, v7 + 16, sec, v12, digest);
  if ( olen > 16 )
  {
    v13 = ((unsigned int)(olen - 17) >> 4) + 1;
    do
    {
      v9 += 16;
      hmac_md5(msg, 16, sec, v12, Src);
      memmove(msg, Src, 0x10ui64);
      hmac_md5(msg, v7 + 16, sec, v12, v9);
      --v13;
    }
    while ( v13 );
  }
  v14 = v22;
  hmac_sha1(seed, v7, v11, v12, msg);
  memmove(v21, seed, v7);
  hmac_sha1(msg, v7 + 20, v11, v12, v22);
  if ( olen > 20 )
  {
    v15 = (olen - 21) / 0x14u + 1;
    do
    {
      v14 += 20;
      hmac_sha1(msg, 20, v11, v12, Src);
      memmove(msg, Src, 0x14ui64);
      hmac_sha1(msg, v7 + 20, v11, v12, v14);
      --v15;
    }
    while ( v15 );
  }
  for ( i = 0i64; i < olen; ++i )
    out[i] = digest[i] ^ v22[i];
}

// File Line: 866
// RVA: 0xEEF0A4
void __fastcall generate_master_secret(_SSL *ssl, const char *premaster_secret)
{
  char _Dst[13]; // [rsp+30h] [rbp-98h] BYREF
  char Dst[32]; // [rsp+3Dh] [rbp-8Bh] BYREF
  char v6[83]; // [rsp+5Dh] [rbp-6Bh] BYREF

  strcpy_s(_Dst, 0x80ui64, "master secret");
  memmove(Dst, ssl->dc->client_random, 0x20ui64);
  memmove(v6, ssl->dc->server_random, 0x20ui64);
  prf(premaster_secret, 48, _Dst, 77, ssl->dc->master_secret, 48);
}

// File Line: 901
// RVA: 0xEEEE58
void __fastcall finished_digest(_SSL *ssl, const char *label, char *digest)
{
  DISPOSABLE_CTX *dc; // r8
  char *v7; // rbx
  char *v8; // rbx
  MD5_CTX ctx; // [rsp+30h] [rbp-D0h] BYREF
  SHA1_CTX context; // [rsp+90h] [rbp-70h] BYREF
  char _Dst[128]; // [rsp+F0h] [rbp-10h] BYREF

  dc = ssl->dc;
  v7 = _Dst;
  ctx = dc->md5_ctx;
  context = dc->sha1_ctx;
  if ( label )
  {
    strcpy_s(_Dst, 0x80ui64, label);
    v7 = &_Dst[strlen(label)];
  }
  MD5_Final(v7, &ctx);
  v8 = v7 + 16;
  SHA1_Final(v8, &context);
  if ( label )
    prf(ssl->dc->master_secret, 48, _Dst, (_DWORD)v8 - (unsigned int)_Dst + 20, digest, 12);
  else
    memmove(digest, _Dst, 0x24ui64);
}

// File Line: 945
// RVA: 0xEEEC48
aes_key_st *__fastcall crypt_new(_SSL *ssl, char *key, char *iv, int is_decrypt)
{
  char cipher; // al
  aes_key_st *v8; // rax
  aes_key_st *v9; // rbx
  AES_MODE v10; // r9d
  RC4_CTX *v12; // rax

  cipher = ssl->cipher;
  if ( (unsigned __int8)cipher >= 4u )
  {
    if ( (unsigned __int8)cipher <= 5u )
    {
      v12 = (RC4_CTX *)ax_malloc(0x102ui64);
      v9 = (aes_key_st *)v12;
      if ( v12 )
      {
        RC4_setup(v12, key, 16);
        return v9;
      }
    }
    else if ( cipher == 47 )
    {
      v8 = (aes_key_st *)ax_malloc(0x1F4ui64);
      v9 = v8;
      if ( v8 )
      {
        v10 = AES_MODE_128;
LABEL_9:
        AES_set_key(v8, key, iv, v10);
        if ( is_decrypt )
          AES_convert_key(v9);
        return v9;
      }
    }
    else if ( cipher == 53 )
    {
      v8 = (aes_key_st *)ax_malloc(0x1F4ui64);
      v9 = v8;
      if ( v8 )
      {
        v10 = AES_MODE_256;
        goto LABEL_9;
      }
    }
  }
  return 0i64;
}

// File Line: 998
// RVA: 0xEEFA40
__int64 __fastcall send_raw_packet(_SSL *ssl, char protocol)
{
  int bm_index; // ebp
  int v3; // ebp
  int v6; // edi
  unsigned int v7; // esi
  int v8; // eax
  fd_set writefds; // [rsp+30h] [rbp-238h] BYREF

  bm_index = ssl->bm_index;
  ssl->bm_all_data[0] = protocol;
  *(_WORD *)&ssl->bm_all_data[1] = 259;
  v3 = bm_index + 5;
  ssl->bm_all_data[3] = HIBYTE(ssl->bm_index);
  v6 = 0;
  v7 = 0;
  ssl->bm_all_data[4] = ssl->bm_index;
  if ( v3 <= 0 )
  {
LABEL_8:
    ssl->flag |= 1u;
    ssl->bm_index = 0;
    if ( protocol != 23 )
      return 0;
    return v7;
  }
  else
  {
    while ( 1 )
    {
      v8 = send_0(ssl->client_fd, &ssl->bm_all_data[v6], v3 - v6, 0);
      v7 = v8;
      if ( v8 < 0 )
      {
        if ( GetLastError() != 10035 )
          return 4294967040i64;
      }
      else
      {
        v6 += v8;
      }
      if ( v6 == v3 )
        goto LABEL_8;
      writefds.fd_array[0] = ssl->client_fd;
      writefds.fd_count = 1;
      if ( select_0(LODWORD(writefds.fd_array[0]) + 1, 0i64, &writefds, 0i64, 0i64) < 0 )
        return 4294967040i64;
      if ( v6 >= v3 )
        goto LABEL_8;
    }
  }
}

// File Line: 1107
// RVA: 0xEEF8A0
__int64 __fastcall send_packet(_SSL *ssl, char protocol, const char *in, int length)
{
  bool v4; // zf
  __int64 buf_len; // rsi
  unsigned int flag; // ebx
  int v10; // ebx
  char *bm_data; // rdx
  char *v12; // r9
  int v13; // r14d
  cipher_info_t *cipher_info; // rax
  int padding_size; // ecx
  int v16; // ebx
  char *v17; // rcx
  char *v18; // rdx
  int v19; // eax
  char hmac_header; // [rsp+30h] [rbp-38h] BYREF
  __int16 v21; // [rsp+31h] [rbp-37h]
  char v22; // [rsp+33h] [rbp-35h]
  char v23; // [rsp+34h] [rbp-34h]

  v4 = ssl->hs_status == -2;
  buf_len = length;
  ssl->bm_index = length;
  if ( v4 )
    return 4294967040i64;
  if ( in )
    memmove(ssl->bm_data, in, length);
  flag = ssl->flag;
  if ( (ssl->flag & 2) != 0 )
  {
    hmac_header = protocol;
    v21 = 259;
    v10 = (flag & 0x10 | 8) >> 3;
    v22 = BYTE1(buf_len);
    v23 = buf_len;
    if ( protocol == 22 )
    {
      bm_data = ssl->bm_data;
      if ( *bm_data )
        add_packet(ssl, bm_data, ssl->bm_index);
    }
    v12 = ssl->bm_data;
    v13 = buf_len + (unsigned __int8)ssl->cipher_info->digest_size;
    ssl->bm_index = buf_len + (unsigned __int8)ssl->cipher_info->digest_size;
    add_hmac_digest(ssl, v10, &hmac_header, v12, buf_len, &v12[buf_len]);
    cipher_info = ssl->cipher_info;
    if ( cipher_info->padding_size )
    {
      padding_size = (unsigned __int8)cipher_info->padding_size;
      v16 = padding_size - v13 % padding_size;
      if ( padding_size == v13 % padding_size )
        v16 = (unsigned __int8)cipher_info->padding_size;
      memset(&ssl->bm_data[v13], v16 - 1, v16);
      v13 += v16;
      ssl->bm_index = v13;
    }
    v17 = &ssl->write_sequence[7];
    do
    {
      v4 = (*v17)++ == -1;
      if ( !v4 )
        break;
      --v17;
    }
    while ( (__int64)&v17[-17608i64 - (_QWORD)ssl] >= 0 );
    ssl->cipher_info->encrypt(ssl->encrypt_ctx, ssl->bm_data, ssl->bm_data, v13);
  }
  else if ( protocol == 22 )
  {
    v18 = ssl->bm_data;
    if ( *v18 )
      add_packet(ssl, v18, ssl->bm_index);
  }
  v19 = send_raw_packet(ssl, protocol);
  if ( v19 <= 0 )
    LODWORD(buf_len) = v19;
  return (unsigned int)buf_len;
}

// File Line: 1192
// RVA: 0xEEFB54
void __fastcall set_key_block(_SSL *ssl, int is_write)
{
  char cipher; // dl
  cipher_info_t *v5; // rax
  int v6; // ecx
  cipher_info_t *v7; // r13
  unsigned int v8; // edi
  DISPOSABLE_CTX *dc; // rax
  int olen; // esi
  const char *master_secret; // r14
  char *server_random; // rbx
  char *client_random; // rdi
  DISPOSABLE_CTX *v14; // rax
  char *key_block; // rbx
  size_t digest_size; // r8
  char *v17; // rbx
  char *v18; // rbx
  size_t key_size; // r8
  char *v20; // rbx
  char *v21; // rbx
  unsigned __int8 iv_size; // al
  void *encrypt_ctx; // rcx
  char *final_finish_mac; // r8
  _SSL *v25; // rcx
  char *v26; // r8
  char *v27; // rdx
  char *v28; // r8
  char *v29; // rdx
  unsigned int v30; // [rsp+30h] [rbp-A8h]
  char *out; // [rsp+38h] [rbp-A0h]
  char v32[16]; // [rsp+40h] [rbp-98h] BYREF
  char iv[8]; // [rsp+50h] [rbp-88h] BYREF
  char v34[8]; // [rsp+58h] [rbp-80h] BYREF
  char key[24]; // [rsp+60h] [rbp-78h] BYREF
  char _Dst[13]; // [rsp+78h] [rbp-60h] BYREF
  char Dst[32]; // [rsp+85h] [rbp-53h] BYREF
  char v38[83]; // [rsp+A5h] [rbp-33h] BYREF

  cipher = ssl->cipher;
  v5 = cipher_info;
  v6 = 0;
  while ( v5->cipher != cipher )
  {
    ++v5;
    ++v6;
    if ( (__int64)v5 >= (__int64)"server finished" )
    {
      v7 = 0i64;
      goto LABEL_6;
    }
  }
  v7 = &cipher_info[v6];
LABEL_6:
  v8 = ssl->flag & 0x10;
  v30 = v8;
  if ( !ssl->dc->key_block )
  {
    ssl->dc->key_block = (char *)ax_malloc((unsigned __int8)v7->key_block_size);
    dc = ssl->dc;
    out = dc->key_block;
    if ( out )
    {
      olen = (unsigned __int8)v7->key_block_size;
      master_secret = dc->master_secret;
      server_random = dc->server_random;
      client_random = dc->client_random;
      strcpy_s(_Dst, 0x80ui64, "key expansion");
      memmove(Dst, server_random, 0x20ui64);
      memmove(v38, client_random, 0x20ui64);
      prf(master_secret, 48, _Dst, 77, out, olen);
      v8 = v30;
    }
  }
  v14 = ssl->dc;
  key_block = v14->key_block;
  if ( !v8 )
  {
    if ( is_write )
      goto LABEL_14;
    goto LABEL_13;
  }
  if ( is_write )
LABEL_13:
    memmove(ssl->client_mac, v14->key_block, (unsigned __int8)v7->digest_size);
LABEL_14:
  digest_size = (unsigned __int8)v7->digest_size;
  v17 = &key_block[digest_size];
  if ( v8 )
  {
    if ( is_write )
      goto LABEL_19;
    goto LABEL_18;
  }
  if ( is_write )
LABEL_18:
    memmove(ssl->server_mac, v17, digest_size);
LABEL_19:
  v18 = &v17[(unsigned __int8)v7->digest_size];
  memmove(v34, v18, (unsigned __int8)v7->key_size);
  key_size = (unsigned __int8)v7->key_size;
  v20 = &v18[key_size];
  memmove(key, v20, key_size);
  v21 = &v20[(unsigned __int8)v7->key_size];
  iv_size = v7->iv_size;
  if ( iv_size )
  {
    memmove(v32, v21, iv_size);
    memmove(iv, &v21[(unsigned __int8)v7->iv_size], (unsigned __int8)v7->iv_size);
  }
  if ( is_write )
    encrypt_ctx = ssl->encrypt_ctx;
  else
    encrypt_ctx = ssl->decrypt_ctx;
  ax_free(encrypt_ctx);
  final_finish_mac = ssl->dc->final_finish_mac;
  if ( !v8 )
  {
    finished_digest(ssl, client_finished, final_finish_mac);
    v25 = ssl;
    if ( is_write )
    {
      v26 = iv;
      v27 = key;
      goto LABEL_30;
    }
    v28 = v32;
    v29 = v34;
LABEL_32:
    ssl->decrypt_ctx = crypt_new(v25, v29, v28, 1);
    goto LABEL_33;
  }
  finished_digest(ssl, server_finished, final_finish_mac);
  v25 = ssl;
  if ( !is_write )
  {
    v28 = iv;
    v29 = key;
    goto LABEL_32;
  }
  v26 = v32;
  v27 = v34;
LABEL_30:
  ssl->encrypt_ctx = crypt_new(v25, v27, v26, 0);
LABEL_33:
  ssl->cipher_info = v7;
}

// File Line: 1278
// RVA: 0xEEE9F0
__int64 __fastcall basic_read(_SSL *ssl, char **in_data)
{
  unsigned __int8 *bm_data; // rsi
  int v5; // edi
  unsigned int v6; // r15d
  int v7; // ebp
  unsigned __int16 got_bytes; // ax
  unsigned int flag; // r9d
  int v11; // ebp
  int v12; // eax
  unsigned __int16 v13; // cx
  int v14; // r9d
  char *v15; // rcx
  char *v17; // rcx

  bm_data = (unsigned __int8 *)ssl->bm_data;
  v5 = 0;
  v6 = ssl->flag & 0x10;
  v7 = recv_0(ssl->client_fd, (char *)&bm_data[ssl->bm_read_index], ssl->need_bytes - ssl->got_bytes, 0);
  if ( v7 < 0 && GetLastError() == 10035 )
    return 0i64;
  if ( v7 > 0 )
  {
    ssl->got_bytes += v7;
    got_bytes = ssl->got_bytes;
    ssl->bm_read_index += v7;
    if ( got_bytes < ssl->need_bytes )
      return 0i64;
    flag = ssl->flag;
    v11 = got_bytes;
    ssl->got_bytes = 0;
    if ( (flag & 1) != 0 )
    {
      if ( (*bm_data & 0x80u) != 0 && bm_data[2] == 1 && bm_data[3] == 3 )
      {
        add_packet(ssl, (const char *)bm_data + 2, 3u);
        v12 = process_sslv23_client_hello(ssl);
LABEL_17:
        v5 = v12;
        goto $error_1;
      }
      v13 = bm_data[4] + (bm_data[3] << 8);
      ssl->need_bytes = v13;
      if ( v13 <= 0x43FBu )
      {
        ssl->flag = flag & 0xFFFFFFFE;
        memmove(ssl->hmac_header, bm_data, 3ui64);
        ssl->record_type = *bm_data;
        goto $error_1;
      }
    }
    else
    {
      v14 = flag | 1;
      ssl->flag = v14;
      ssl->need_bytes = 5;
      if ( (v14 & 4) != 0 )
      {
        ssl->cipher_info->decrypt(ssl->decrypt_ctx, (const char *)bm_data, (char *)bm_data, got_bytes);
        v12 = verify_digest(ssl, v6 != 0 ? 2 : 0, (const char *)bm_data, v11);
        v11 = v12;
        if ( v12 < 0 )
          goto LABEL_17;
        v15 = &ssl->read_sequence[7];
        do
        {
          if ( (*v15)++ != -1 )
            break;
          --v15;
        }
        while ( (__int64)&v15[-17600i64 - (_QWORD)ssl] >= 0 );
      }
      switch ( ssl->record_type )
      {
        case 0x14:
          if ( ssl->next_state == 20 )
          {
            ssl->flag |= 4u;
            set_key_block(ssl, 0);
            memset(ssl->read_sequence, 0, sizeof(ssl->read_sequence));
          }
          else
          {
            v5 = -260;
          }
          goto $error_1;
        case 0x15:
          v5 = -bm_data[1];
          goto $error_1;
        case 0x16:
          ssl->dc->bm_proc_index = 0;
          v12 = do_handshake(ssl, (char *)bm_data, v11);
          goto LABEL_17;
        case 0x17:
          if ( in_data )
          {
            v17 = ssl->bm_data;
            *in_data = v17;
            v17[v11] = 0;
          }
          v5 = v11;
          goto $error_1;
      }
    }
    v5 = -261;
    goto $error_1;
  }
  v5 = -256;
  ssl->hs_status = -2;
$error_1:
  ssl->bm_read_index = 0;
  if ( v5 < 0 )
  {
    if ( in_data )
      *in_data = 0i64;
  }
  return (unsigned int)v5;
}

// File Line: 1441
// RVA: 0xEEED8C
int __fastcall do_handshake(_SSL *ssl, char *buf, int read_len)
{
  int v3; // eax
  int v4; // ebx
  unsigned __int8 v6; // cl
  unsigned int v8; // edx
  int v10; // ebx
  int v11; // r10d
  int result; // eax
  int v13; // ebx
  int v14; // [rsp+40h] [rbp+8h]
  unsigned int v15; // [rsp+50h] [rbp+18h]

  v3 = (unsigned __int8)buf[3];
  v4 = (unsigned __int8)buf[2];
  v6 = *buf;
  v8 = ssl->flag & 0x10;
  v10 = v3 + (v4 << 8);
  v15 = v8;
  if ( read_len - 4 < v10 )
    return -260;
  v11 = v6;
  v14 = v6;
  if ( v6 != ssl->next_state && (!v8 || v6 != 13 || ssl->next_state != 14) )
    return -260;
  v13 = v10 + 4;
  ssl->bm_index = v13;
  if ( v6 != 15 && v6 )
  {
    add_packet(ssl, buf, v13);
    v8 = v15;
    v11 = v14;
  }
  if ( v8 )
    result = do_clnt_handshake(ssl, v11, buf, v13);
  else
    result = do_svr_handshake(ssl, v11, buf, v13);
  if ( v13 < read_len && !result )
    return do_handshake(ssl, &buf[v13], read_len - v13);
  return result;
}

// File Line: 1489
// RVA: 0xEEF7CC
__int64 __fastcall send_change_cipher_spec(_SSL *ssl)
{
  int v2; // eax
  unsigned int v3; // ebx

  v2 = send_packet(ssl, 20, g_chg_cipher_spec_pkt, 1);
  ssl->flag |= 2u;
  v3 = v2;
  set_key_block(ssl, 1);
  memset(ssl->write_sequence, 0, sizeof(ssl->write_sequence));
  return v3;
}

// File Line: 1502
// RVA: 0xEEF820
int __fastcall send_finished(_SSL *ssl)
{
  char *bm_data; // r8
  const char *v2; // rdx
  char *v4; // r8

  bm_data = ssl->bm_data;
  v2 = server_finished;
  *(_DWORD *)bm_data = 201326612;
  v4 = bm_data + 4;
  if ( (ssl->flag & 0x10) != 0 )
    v2 = client_finished;
  finished_digest(ssl, v2, v4);
  if ( (ssl->flag & 8) == 0 && ssl->ssl_ctx->num_sessions )
    memmove(ssl->session->master_secret, ssl->dc->master_secret, 0x30ui64);
  return send_packet(ssl, 22, 0i64, 16);
}

// File Line: 1533
// RVA: 0xEEF5D8
__int64 __fastcall send_alert(_SSL *ssl, int error_code)
{
  unsigned int v2; // ebx
  bool v4; // zf
  char v5; // cl
  int v6; // edi
  char v8; // al
  char in[8]; // [rsp+20h] [rbp-18h] BYREF

  v2 = 0;
  v4 = ssl->hs_status == -2;
  v5 = 0;
  v6 = 0;
  if ( v4 )
    return 4294967040i64;
  if ( error_code > -263 )
  {
    if ( error_code != -262 )
    {
      if ( error_code <= -260 )
      {
        v5 = 40;
      }
      else
      {
        if ( error_code != -256 && error_code )
        {
LABEL_9:
          v8 = 10;
          if ( error_code <= -512 )
            v8 = 42;
          v5 = v8;
          goto LABEL_22;
        }
        v6 = 1;
      }
      goto LABEL_22;
    }
LABEL_21:
    v5 = 20;
    goto LABEL_22;
  }
  switch ( error_code )
  {
    case -263:
      v5 = 70;
      goto LABEL_22;
    case -271:
      goto LABEL_21;
    case -269:
LABEL_13:
      v5 = 47;
      goto LABEL_22;
  }
  if ( error_code != -268 )
  {
    if ( (unsigned int)(error_code + 266) > 1 )
      goto LABEL_9;
    goto LABEL_13;
  }
  v5 = 42;
LABEL_22:
  in[1] = v5;
  in[0] = 2 - (v6 != 0);
  send_packet(ssl, 21, in, 2);
  LOBYTE(v2) = v6 == 0;
  return v2;
}

// File Line: 1602
// RVA: 0xEEF51C
__int64 __fastcall process_finished(_SSL *ssl, int __formal)
{
  __int16 v2; // bx
  unsigned int v3; // ebp
  unsigned int v4; // r14d
  unsigned int v6; // edi

  HIBYTE(v2) = 0;
  v3 = ssl->flag & 8;
  v4 = ssl->flag & 0x10;
  v6 = 0;
  if ( ssl->bm_index >= 0x10u )
  {
    if ( memcmp(ssl->dc->final_finish_mac, ssl->bm_data + 4, 0xCui64) )
      return 4294967025i64;
    if ( v4 )
    {
      if ( !v3 )
      {
LABEL_11:
        ssl->hs_status = v6;
        LOBYTE(v2) = v4 == 0;
        ssl->next_state = v2;
        return v6;
      }
    }
    else if ( v3 )
    {
      goto LABEL_11;
    }
    v6 = send_change_cipher_spec(ssl);
    if ( !v6 )
      v6 = send_finished(ssl);
    goto LABEL_11;
  }
  return (unsigned int)-260;
}

// File Line: 1632
// RVA: 0xEEF6E0
int __fastcall send_certificate(_SSL *ssl)
{
  char *bm_data; // rdi
  int v2; // r15d
  int v4; // esi
  __int64 v5; // r14
  _SSL_CTX *ssl_ctx; // rbx
  __int64 v7; // rax
  int v8; // esi
  __int64 v9; // rax

  bm_data = ssl->bm_data;
  v2 = 0;
  *(_WORD *)bm_data = 11;
  bm_data[4] = 0;
  v4 = 7;
  if ( ssl->ssl_ctx->chain_length )
  {
    v5 = 0i64;
    do
    {
      ssl_ctx = ssl->ssl_ctx;
      v7 = v4;
      v8 = v4 + 1;
      bm_data[v7] = 0;
      v9 = v8++;
      bm_data[v9] = BYTE1(ssl_ctx->certs[v5].size);
      bm_data[v8++] = ssl_ctx->certs[v5].size;
      memmove(&bm_data[v8], ssl_ctx->certs[v5].buf, ssl_ctx->certs[v5].size);
      v4 = ssl_ctx->certs[v5].size + v8;
      ++v2;
      ++v5;
    }
    while ( v2 < (unsigned __int8)ssl->ssl_ctx->chain_length );
  }
  bm_data[6] = v4 - 7;
  bm_data[3] = v4 - 7 + 3;
  bm_data[5] = (unsigned __int16)(v4 - 7) >> 8;
  bm_data[2] = (unsigned __int16)(v4 - 7 + 3) >> 8;
  ssl->bm_index = v4;
  return send_packet(ssl, 22, 0i64, v4);
}

// File Line: 1668
// RVA: 0xEEED48
void __fastcall disposable_new(_SSL *ssl)
{
  DISPOSABLE_CTX *v2; // rax

  if ( !ssl->dc )
  {
    v2 = (DISPOSABLE_CTX *)ax_calloc(1ui64, 0x140ui64);
    ssl->dc = v2;
    if ( v2 )
    {
      MD5_Init(&v2->md5_ctx);
      SHA1_Init(&ssl->dc->sha1_ctx);
    }
  }
}

// File Line: 1684
// RVA: 0xEEED04
void __fastcall disposable_free(_SSL *ssl)
{
  DISPOSABLE_CTX *dc; // rcx

  dc = ssl->dc;
  if ( dc )
  {
    ax_free(dc->key_block);
    memset(ssl->dc, 0, sizeof(DISPOSABLE_CTX));
    ax_free(ssl->dc);
    ssl->dc = 0i64;
  }
}

// File Line: 1702
// RVA: 0xEF01D0
SSL_SESSION *__fastcall ssl_session_update(
        int max_sessions,
        SSL_SESSION **ssl_sessions,
        _SSL *ssl,
        const char *session_id)
{
  SSL_SESSION *v8; // r14
  __int64 v9; // r12
  __int64 conn_time; // r15
  int v12; // ebx
  SSL_SESSION *v13; // rcx
  int v14; // ebx
  SSL_SESSION *v15; // rcx
  DISPOSABLE_CTX *dc; // rcx
  _SSL_CTX *ssl_ctx; // rcx
  SSL_SESSION *v18; // rax
  _SSL_CTX *v19; // rcx

  v8 = 0i64;
  v9 = time64(0i64);
  conn_time = v9;
  if ( !max_sessions )
    return 0i64;
  WaitForSingleObject(ssl->ssl_ctx->mutex, 0xFFFFFFFF);
  if ( session_id )
  {
    v12 = 0;
    if ( max_sessions > 0 )
    {
      while ( 1 )
      {
        v13 = ssl_sessions[v12];
        if ( v13 )
        {
          if ( v9 <= v13->conn_time + 86400 )
          {
            if ( !memcmp(v13->session_id, session_id, 0x20ui64) )
            {
              dc = ssl->dc;
              ssl->session_index = v12;
              memmove(dc->master_secret, ssl_sessions[v12]->master_secret, 0x30ui64);
              ssl_ctx = ssl->ssl_ctx;
              ssl->flag |= 8u;
              ReleaseMutex(ssl_ctx->mutex);
              return ssl_sessions[v12];
            }
          }
          else
          {
            ax_free(v13);
            ssl_sessions[v12] = 0i64;
          }
        }
        if ( ++v12 >= max_sessions )
        {
          conn_time = v9;
          break;
        }
      }
    }
  }
  v14 = 0;
  if ( max_sessions <= 0 )
  {
LABEL_16:
    v8->conn_time = v9;
    memset(v8->session_id, 0, 4ui64);
    memset(v8->master_secret, 0, 4ui64);
    ReleaseMutex(ssl->ssl_ctx->mutex);
    return v8;
  }
  while ( 1 )
  {
    v15 = ssl_sessions[v14];
    if ( !v15 )
      break;
    if ( v15->conn_time <= conn_time )
    {
      conn_time = v15->conn_time;
      v8 = ssl_sessions[v14];
      ssl->session_index = v14;
    }
    if ( ++v14 >= max_sessions )
      goto LABEL_16;
  }
  v18 = (SSL_SESSION *)ax_calloc(1ui64, 0x58ui64);
  ssl_sessions[v14] = v18;
  if ( !v18 )
    return 0i64;
  v18->conn_time = v9;
  v19 = ssl->ssl_ctx;
  ssl->session_index = v14;
  ReleaseMutex(v19->mutex);
  return ssl_sessions[v14];
}

// File Line: 1790
// RVA: 0xEEF160
void __fastcall kill_ssl_session(SSL_SESSION **ssl_sessions, _SSL *ssl)
{
  __int64 session_index; // rdi
  SSL_SESSION *v5; // rcx

  WaitForSingleObject(ssl->ssl_ctx->mutex, 0xFFFFFFFF);
  if ( ssl->ssl_ctx->num_sessions )
  {
    session_index = ssl->session_index;
    v5 = ssl_sessions[session_index];
    if ( v5 )
    {
      ax_free(v5);
      ssl_sessions[session_index] = 0i64;
    }
    ssl->session = 0i64;
  }
  ReleaseMutex(ssl->ssl_ctx->mutex);
}

// File Line: 1895
// RVA: 0xEEF40C
__int64 __fastcall process_certificate(_SSL *ssl, _x509_ctx **x509_ctx)
{
  unsigned int v2; // ebx
  char *v3; // r13
  int v4; // edi
  unsigned int v5; // r15d
  int v8; // ebp
  int v9; // edi
  __int64 v10; // rax
  int v11; // edi
  int v12; // r12d
  int bm_index; // [rsp+50h] [rbp+8h]

  v2 = 0;
  v3 = &ssl->bm_data[ssl->dc->bm_proc_index];
  bm_index = ssl->bm_index;
  v4 = 7;
  v5 = ssl->flag & 0x10;
  v8 = (unsigned __int8)v3[6] + ((unsigned __int8)v3[5] << 8);
  if ( v8 < 7 )
    return (unsigned int)-260;
  if ( v8 <= 7 )
  {
LABEL_5:
    if ( bm_index >= v4 )
    {
      if ( v5 && (ssl->flag & 0x20000) == 0 )
        v2 = ssl_verify_cert_win(v3 + 7, v8);
      ssl->next_state = v5 != 0 ? 14 : 16;
      ssl->dc->bm_proc_index += v4;
      return v2;
    }
    return (unsigned int)-260;
  }
  while ( 1 )
  {
    v9 = v4 + 1;
    v10 = v9;
    v11 = v9 + 2;
    v12 = ((unsigned __int8)v3[v10] << 8) + (unsigned __int8)v3[v10 + 1];
    if ( x509_new(&v3[v11], 0i64, x509_ctx) )
      return (unsigned int)-268;
    v4 = v12 + v11;
    x509_ctx = &(*x509_ctx)->next;
    if ( v4 >= v8 )
      goto LABEL_5;
  }
}

