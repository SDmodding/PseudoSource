// File Line: 183
// RVA: 0xEEE8BC
void __fastcall OSuite::ZOEdmBase::CleanTempData(int __formal)
{
  ;
}

// File Line: 191
// RVA: 0xEEFEEC
_SSL_CTX *__fastcall ssl_ctx_new(unsigned int options, int num_sessions)
{
  __int64 v2; // rdi
  unsigned int v3; // esi
  _exception *v4; // rax
  _SSL_CTX *v5; // rbx
  SSL_SESSION **v7; // rax

  v2 = num_sessions;
  v3 = options;
  v4 = (_exception *)ax_calloc(1ui64, 0x60ui64);
  v5 = (_SSL_CTX *)v4;
  if ( !v4 )
    return 0i64;
  v4->type = v3;
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
  _SSL_CTX *v1; // rdi
  _SSL *v2; // rcx
  _SSL *v3; // rbx
  signed int v4; // esi
  __int64 v5; // rbx
  SSL_SESSION **v6; // rbp
  SSL_SESSION *v7; // rcx
  signed __int64 v8; // rsi
  void **v9; // rbx
  void *v10; // rcx

  if ( ssl_ctx )
  {
    v1 = ssl_ctx;
    v2 = ssl_ctx->head;
    if ( v2 )
    {
      do
      {
        v3 = v2->next;
        ssl_free(v2);
        v2 = v3;
      }
      while ( v3 );
    }
    v4 = 0;
    if ( v1->num_sessions > 0u )
    {
      v5 = 0i64;
      do
      {
        v6 = v1->ssl_sessions;
        v7 = v6[v5];
        if ( v7 )
        {
          ax_free(v7);
          v6[v5] = 0i64;
        }
        ++v4;
        ++v5;
      }
      while ( v4 < v1->num_sessions );
    }
    ax_free(v1->ssl_sessions);
    v8 = 0i64;
    v9 = (void **)v1->certs;
    do
    {
      if ( !*v9 )
        break;
      ax_free(*v9);
      ++v8;
      *v9 = 0i64;
      v9 += 2;
    }
    while ( v8 < 2 );
    remove_ca_certs(v1->ca_cert_ctx);
    v10 = v1->mutex;
    v1->chain_length = 0;
    CloseHandle(v10);
    RSA_free(v1->rsa_ctx);
    RNG_terminate();
    ax_free(v1);
  }
}

// File Line: 278
// RVA: 0xEEFF94
void __fastcall ssl_free(_SSL *ssl)
{
  _SSL *v1; // rbx
  _SSL_CTX *v2; // rdi
  _SSL *v3; // rcx
  _SSL *v4; // rax
  _SSL *v5; // rcx
  _SSL *v6; // rax

  if ( ssl )
  {
    v1 = ssl;
    send_alert(ssl, 0);
    v2 = v1->ssl_ctx;
    WaitForSingleObject(v2->mutex, 0xFFFFFFFF);
    v3 = v1->prev;
    v4 = v1->next;
    if ( v3 )
      v3->next = v4;
    else
      v2->head = v4;
    v5 = v1->next;
    v6 = v1->prev;
    if ( v5 )
      v5->prev = v6;
    else
      v2->tail = v6;
    ReleaseMutex(v2->mutex);
    ax_free(v1->encrypt_ctx);
    ax_free(v1->decrypt_ctx);
    disposable_free(v1);
    x509_free(v1->x509_ctx);
    ax_free(v1);
  }
}

// File Line: 319
// RVA: 0xEF017C
__int64 __fastcall ssl_read(_SSL *ssl, char **in_data)
{
  _SSL *v2; // rdi
  unsigned int v3; // ebx

  v2 = ssl;
  v3 = basic_read(ssl, in_data);
  if ( (signed int)(v3 + 2147483648) >= 0 && v3 != -256 )
  {
    send_alert(v2, v3);
    kill_ssl_session(v2->ssl_ctx->ssl_sessions, v2);
  }
  return v3;
}

// File Line: 342
// RVA: 0xEF0380
__int64 __fastcall ssl_write(_SSL *ssl, const char *out_data, int out_len)
{
  unsigned int v3; // edi
  const char *v4; // rbp
  _SSL *v5; // r14
  int v6; // ebx
  int v7; // esi
  int v8; // er9
  unsigned int v9; // eax

  v3 = out_len;
  v4 = out_data;
  v5 = ssl;
  v6 = out_len;
  v7 = 0;
  while ( 1 )
  {
    v8 = v6;
    if ( v6 > 0x4000 )
      v8 = 0x4000;
    v9 = send_packet(v5, 23, &v4[v7], v8);
    if ( (signed int)v9 <= 0 )
      break;
    v6 -= v9;
    v7 += v9;
    if ( v6 <= 0 )
      return v3;
  }
  return v9;
}

// File Line: 475
// RVA: 0xEF0048
char *__fastcall ssl_get_cert_dn(_SSL *ssl, int component)
{
  _x509_ctx *v2; // r8
  int v4; // edx
  int v5; // edx
  int v6; // edx
  int v7; // edx

  v2 = ssl->x509_ctx;
  if ( !v2 )
    return 0i64;
  if ( !component )
    return v2->cert_dn[0];
  v4 = component - 1;
  if ( !v4 )
    return v2->cert_dn[1];
  v5 = v4 - 1;
  if ( !v5 )
    return v2->cert_dn[2];
  v6 = v5 - 1;
  if ( !v6 )
    return v2->ca_cert_dn[0];
  v7 = v6 - 1;
  if ( !v7 )
    return v2->ca_cert_dn[1];
  if ( v7 != 1 )
    return 0i64;
  return v2->ca_cert_dn[2];
}

// File Line: 509
// RVA: 0xEF008C
char *__fastcall ssl_get_cert_subject_alt_dnsname(_SSL *ssl, int dnsindex)
{
  _x509_ctx *v2; // rax
  char **v3; // rax
  __int64 v4; // r8
  __int64 v5; // rcx
  char **v6; // rdx

  v2 = ssl->x509_ctx;
  if ( v2 )
  {
    v3 = v2->subject_alt_dnsnames;
    if ( v3 )
    {
      v4 = 0i64;
      v5 = dnsindex;
      if ( dnsindex <= 0 )
        return v3[v5];
      v6 = v3;
      while ( *v6 )
      {
        ++v4;
        ++v6;
        if ( v4 >= v5 )
          return v3[v5];
      }
    }
  }
  return 0i64;
}

// File Line: 602
// RVA: 0xEF00C8
_SSL *__fastcall ssl_new(_SSL_CTX *ssl_ctx, int client_fd)
{
  int v2; // esi
  _SSL_CTX *v3; // rdi
  _SSL *result; // rax
  _SSL *v5; // rbx
  void *v6; // rcx

  v2 = client_fd;
  v3 = ssl_ctx;
  result = (_SSL *)ax_calloc(1ui64, 0x44D8ui64);
  v5 = result;
  if ( result )
  {
    result->ssl_ctx = v3;
    result->need_bytes = 5;
    result->client_fd = v2;
    result->bm_data = &result->bm_all_data[5];
    result->flag = 1;
    result->hs_status = -1;
    disposable_new(result);
    v5->flag |= v3->options;
    WaitForSingleObject(v3->mutex, 0xFFFFFFFF);
    if ( v3->head )
    {
      v5->prev = v3->tail;
      v3->tail->next = v5;
    }
    else
    {
      v3->head = v5;
    }
    v6 = v3->mutex;
    v3->tail = v5;
    ReleaseMutex(v6);
    result = v5;
  }
  return result;
}

// File Line: 689
// RVA: 0xEEE8C0
void __fastcall add_hmac_digest(_SSL *ssl, int mode, char *hmac_header, const char *buf, int buf_len, char *hmac_buf)
{
  _SSL *v6; // rbx
  const char *v7; // r15
  char *v8; // r12
  int v9; // esi
  char *v10; // rax
  char *v11; // rdi
  char *v12; // rdx
  signed __int64 v13; // r8

  v6 = ssl;
  v7 = buf;
  v8 = hmac_header;
  v9 = mode;
  v10 = (char *)ax_malloc(buf_len + 23);
  v11 = v10;
  if ( v10 )
  {
    v12 = v6->read_sequence;
    if ( !((v9 - 1) & 0xFFFFFFFD) )
      v12 = v6->write_sequence;
    memmove(v10, v12, 8ui64);
    memmove(v11 + 8, v8, 5ui64);
    memmove(v11 + 13, v7, buf_len);
    v13 = (signed __int64)v6->client_mac;
    if ( (unsigned int)(v9 - 1) <= 1 )
      v13 = (signed __int64)v6->server_mac;
    v6->cipher_info->hmac(v11, buf_len + 13, (const char *)v13, (unsigned __int8)v6->cipher_info->digest_size, hmac_buf);
    ax_free(v11);
  }
}

// File Line: 741
// RVA: 0xEF03F4
signed __int64 __fastcall verify_digest(_SSL *ssl, int mode, const char *buf, int read_len)
{
  int v4; // er10
  cipher_info_t *v5; // rdx
  int v6; // eax
  const char *v7; // rsi
  _SSL *v8; // rdi
  int buf_len; // ebx
  char Buf1; // [rsp+30h] [rbp-38h]

  v4 = mode;
  v5 = ssl->cipher_info;
  v6 = (unsigned __int8)v5->digest_size;
  v7 = buf;
  v8 = ssl;
  if ( v5->padding_size )
    buf_len = read_len - (unsigned __int8)buf[read_len - 1] - v6 - 1;
  else
    buf_len = read_len - v6;
  if ( buf_len < 0 )
    return 4294967034i64;
  ssl->hmac_header[3] = BYTE1(buf_len);
  ssl->hmac_header[4] = buf_len;
  add_hmac_digest(ssl, v4, ssl->hmac_header, buf, buf_len, &Buf1);
  if ( memcmp(&Buf1, &v7[buf_len], (unsigned __int8)v8->cipher_info->digest_size) )
    buf_len = -262;
  return (unsigned int)buf_len;
}

// File Line: 777
// RVA: 0xEEE9AC
void __fastcall add_packet(_SSL *ssl, const char *pkt, int len)
{
  _SSL *v3; // rbx
  int v4; // edi
  const char *v5; // rsi

  v3 = ssl;
  v4 = len;
  v5 = pkt;
  MD5_Update(&ssl->dc->md5_ctx, pkt, len);
  SHA1_Update(&v3->dc->sha1_ctx, v5, v4);
}

// File Line: 843
// RVA: 0xEEF1E8
void __fastcall prf(const char *sec, int sec_len, char *seed, int seed_len, char *out, int olen)
{
  char *v6; // rdi
  size_t v7; // r13
  const char *v8; // r12
  char *v9; // r15
  __int64 v10; // rbx
  const char *v11; // rsi
  int v12; // ebx
  __int64 v13; // r14
  char *v14; // r14
  __int64 v15; // r15
  signed __int64 v16; // rcx
  const char *v17; // [rsp+30h] [rbp-D0h]
  char Src; // [rsp+40h] [rbp-C0h]
  char msg; // [rsp+60h] [rbp-A0h]
  char Dst; // [rsp+70h] [rbp-90h]
  char v21; // [rsp+74h] [rbp-8Ch]
  char v22[256]; // [rsp+E0h] [rbp-20h]
  char digest[256]; // [rsp+1E0h] [rbp+E0h]

  v6 = seed;
  v17 = seed;
  v7 = seed_len;
  v8 = sec;
  v9 = digest;
  v10 = sec_len / 2;
  v11 = &sec[v10];
  v12 = (sec_len & 1) + v10;
  hmac_md5(seed, seed_len, sec, v12, &msg);
  memmove(&Dst, v6, v7);
  hmac_md5(&msg, v7 + 16, v8, v12, digest);
  if ( olen > 16 )
  {
    v13 = ((unsigned int)(olen - 17) >> 4) + 1;
    do
    {
      v9 += 16;
      hmac_md5(&msg, 16, v8, v12, &Src);
      memmove(&msg, &Src, 0x10ui64);
      hmac_md5(&msg, v7 + 16, v8, v12, v9);
      --v13;
    }
    while ( v13 );
  }
  v14 = v22;
  hmac_sha1(v17, v7, v11, v12, &msg);
  memmove(&v21, v17, v7);
  hmac_sha1(&msg, v7 + 20, v11, v12, v22);
  if ( olen > 20 )
  {
    v15 = (olen - 21) / 0x14u + 1;
    do
    {
      v14 += 20;
      hmac_sha1(&msg, 20, v11, v12, &Src);
      memmove(&msg, &Src, 0x14ui64);
      hmac_sha1(&msg, v7 + 20, v11, v12, v14);
      --v15;
    }
    while ( v15 );
  }
  v16 = 0i64;
  if ( olen > 0 )
  {
    do
    {
      out[v16] = digest[v16] ^ v22[v16];
      ++v16;
    }
    while ( v16 < olen );
  }
}

// File Line: 866
// RVA: 0xEEF0A4
void __fastcall generate_master_secret(_SSL *ssl, const char *premaster_secret)
{
  _SSL *v2; // rbx
  const char *v3; // rdi
  char _Dst; // [rsp+30h] [rbp-98h]
  char Dst; // [rsp+3Dh] [rbp-8Bh]
  char v6; // [rsp+5Dh] [rbp-6Bh]

  v2 = ssl;
  v3 = premaster_secret;
  strcpy_s(&_Dst, 0x80ui64, "master secret");
  memmove(&Dst, v2->dc->client_random, 0x20ui64);
  memmove(&v6, v2->dc->server_random, 0x20ui64);
  prf(v3, 48, &_Dst, 77, v2->dc->master_secret, 48);
}

// File Line: 901
// RVA: 0xEEEE58
void __fastcall finished_digest(_SSL *ssl, const char *label, char *digest)
{
  char *out; // rsi
  unsigned int *v4; // r8
  const char *v5; // rdi
  _SSL *v6; // r14
  char *v7; // rbx
  char *v8; // rbx
  MD5_CTX ctx; // [rsp+30h] [rbp-D0h]
  SHA1_CTX context; // [rsp+90h] [rbp-70h]
  char _Dst[128]; // [rsp+F0h] [rbp-10h]

  out = digest;
  v4 = ssl->dc->md5_ctx.state;
  v5 = label;
  v6 = ssl;
  v7 = _Dst;
  ctx.state[0] = *v4;
  ctx.state[1] = v4[1];
  ctx.state[2] = v4[2];
  ctx.state[3] = v4[3];
  ctx.count[0] = v4[4];
  ctx.count[1] = v4[5];
  *(_DWORD *)ctx.buffer = v4[6];
  *(_DWORD *)&ctx.buffer[4] = v4[7];
  *(_DWORD *)&ctx.buffer[8] = v4[8];
  *(_DWORD *)&ctx.buffer[12] = v4[9];
  *(_DWORD *)&ctx.buffer[16] = v4[10];
  *(_DWORD *)&ctx.buffer[20] = v4[11];
  *(_DWORD *)&ctx.buffer[24] = v4[12];
  *(_DWORD *)&ctx.buffer[28] = v4[13];
  *(_DWORD *)&ctx.buffer[32] = v4[14];
  *(_DWORD *)&ctx.buffer[36] = v4[15];
  *(_DWORD *)&ctx.buffer[40] = v4[16];
  *(_DWORD *)&ctx.buffer[44] = v4[17];
  *(_DWORD *)&ctx.buffer[48] = v4[18];
  *(_DWORD *)&ctx.buffer[52] = v4[19];
  *(_DWORD *)&ctx.buffer[56] = v4[20];
  *(_DWORD *)&ctx.buffer[60] = v4[21];
  context.state[0] = v4[22];
  context.state[1] = v4[23];
  context.state[2] = v4[24];
  context.state[3] = v4[25];
  context.state[4] = v4[26];
  context.count[0] = v4[27];
  context.count[1] = v4[28];
  *(_DWORD *)context.buffer = v4[29];
  *(_DWORD *)&context.buffer[4] = v4[30];
  *(_DWORD *)&context.buffer[8] = v4[31];
  *(_DWORD *)&context.buffer[12] = v4[32];
  *(_DWORD *)&context.buffer[16] = v4[33];
  *(_DWORD *)&context.buffer[20] = v4[34];
  *(_DWORD *)&context.buffer[24] = v4[35];
  *(_DWORD *)&context.buffer[28] = v4[36];
  *(_DWORD *)&context.buffer[32] = v4[37];
  *(_DWORD *)&context.buffer[36] = v4[38];
  *(_DWORD *)&context.buffer[40] = v4[39];
  *(_DWORD *)&context.buffer[44] = v4[40];
  *(_DWORD *)&context.buffer[48] = v4[41];
  *(_DWORD *)&context.buffer[52] = v4[42];
  *(_DWORD *)&context.buffer[56] = v4[43];
  *(_DWORD *)&context.buffer[60] = v4[44];
  if ( label )
  {
    strcpy_s(_Dst, 0x80ui64, label);
    v7 = &_Dst[strlen(v5)];
  }
  MD5_Final(v7, &ctx);
  v8 = v7 + 16;
  SHA1_Final(v8, &context);
  if ( v5 )
    prf(v6->dc->master_secret, 48, _Dst, (_DWORD)v8 - (unsigned __int64)_Dst + 20, out, 12);
  else
    memmove(out, _Dst, 0x24ui64);
}

// File Line: 945
// RVA: 0xEEEC48
aes_key_st *__fastcall crypt_new(_SSL *ssl, char *key, char *iv, int is_decrypt)
{
  char v4; // al
  int v5; // esi
  char *v6; // rbp
  char *v7; // rdi
  aes_key_st *v8; // rax
  aes_key_st *v9; // rbx
  AES_MODE v10; // er9
  RC4_CTX *v12; // rax

  v4 = ssl->cipher;
  v5 = is_decrypt;
  v6 = iv;
  v7 = key;
  if ( (unsigned __int8)v4 >= 4u )
  {
    if ( (unsigned __int8)v4 <= 5u )
    {
      v12 = (RC4_CTX *)ax_malloc(0x102ui64);
      v9 = (aes_key_st *)v12;
      if ( v12 )
      {
        RC4_setup(v12, v7, 16);
        return v9;
      }
    }
    else if ( v4 == 47 )
    {
      v8 = (aes_key_st *)ax_malloc(0x1F4ui64);
      v9 = v8;
      if ( v8 )
      {
        v10 = 0;
LABEL_9:
        AES_set_key(v8, v7, v6, v10);
        if ( v5 )
          AES_convert_key(v9);
        return v9;
      }
    }
    else if ( v4 == 53 )
    {
      v8 = (aes_key_st *)ax_malloc(0x1F4ui64);
      v9 = v8;
      if ( v8 )
      {
        v10 = 1;
        goto LABEL_9;
      }
    }
  }
  return 0i64;
}

// File Line: 998
// RVA: 0xEEFA40
signed __int64 __fastcall send_raw_packet(_SSL *ssl, char protocol)
{
  int v2; // ebp
  int v3; // ebp
  char v4; // r14
  _SSL *v5; // rbx
  int v6; // edi
  unsigned int v7; // esi
  int v8; // eax
  signed __int64 result; // rax
  fd_set writefds; // [rsp+30h] [rbp-238h]

  v2 = ssl->bm_index;
  ssl->bm_all_data[0] = protocol;
  *(_WORD *)&ssl->bm_all_data[1] = 259;
  v3 = v2 + 5;
  ssl->bm_all_data[3] = HIBYTE(ssl->bm_index);
  v4 = protocol;
  v5 = ssl;
  v6 = 0;
  v7 = 0;
  ssl->bm_all_data[4] = ssl->bm_index;
  if ( v3 <= 0 )
  {
LABEL_8:
    v5->flag |= 1u;
    v5->bm_index = 0;
    if ( v4 != 23 )
      v7 = 0;
    result = v7;
  }
  else
  {
    while ( 1 )
    {
      v8 = send_0(v5->client_fd, &v5->bm_all_data[v6], v3 - v6, 0);
      v7 = v8;
      if ( v8 < 0 )
      {
        if ( GetLastError() != 10035 )
          break;
      }
      else
      {
        v6 += v8;
      }
      if ( v6 == v3 )
        goto LABEL_8;
      writefds.fd_array[0] = v5->client_fd;
      writefds.fd_count = 1;
      if ( select_0(LODWORD(writefds.fd_array[0]) + 1, 0i64, &writefds, 0i64, 0i64) < 0 )
        break;
      if ( v6 >= v3 )
        goto LABEL_8;
    }
    result = 4294967040i64;
  }
  return result;
}

// File Line: 1107
// RVA: 0xEEF8A0
signed __int64 __fastcall send_packet(_SSL *ssl, char protocol, const char *in, int length)
{
  bool v4; // zf
  __int64 buf_len; // rsi
  char v6; // bp
  _SSL *v7; // rdi
  unsigned int v9; // ebx
  int v10; // ebx
  const char *v11; // rdx
  const char *v12; // r9
  int v13; // er14
  cipher_info_t *v14; // rax
  int v15; // ecx
  int v16; // ebx
  char *v17; // rcx
  const char *v18; // rdx
  int v19; // eax
  char hmac_header; // [rsp+30h] [rbp-38h]
  __int16 v21; // [rsp+31h] [rbp-37h]
  char v22; // [rsp+33h] [rbp-35h]
  char v23; // [rsp+34h] [rbp-34h]

  v4 = ssl->hs_status == -2;
  buf_len = length;
  v6 = protocol;
  v7 = ssl;
  ssl->bm_index = length;
  if ( v4 )
    return 4294967040i64;
  if ( in )
    memmove(ssl->bm_data, in, length);
  v9 = v7->flag;
  if ( v7->flag & 2 )
  {
    hmac_header = v6;
    v21 = 259;
    v10 = (v9 & 0x10 | 8) >> 3;
    v22 = BYTE1(buf_len);
    v23 = buf_len;
    if ( v6 == 22 )
    {
      v11 = v7->bm_data;
      if ( *v11 )
        add_packet(v7, v11, v7->bm_index);
    }
    v12 = v7->bm_data;
    v13 = buf_len + (unsigned __int8)v7->cipher_info->digest_size;
    v7->bm_index = buf_len + (unsigned __int8)v7->cipher_info->digest_size;
    add_hmac_digest(v7, v10, &hmac_header, v12, buf_len, (char *)&v12[buf_len]);
    v14 = v7->cipher_info;
    if ( v14->padding_size )
    {
      v15 = (unsigned __int8)v14->padding_size;
      v16 = v15 - v13 % v15;
      if ( v15 == v13 % v15 )
        v16 = (unsigned __int8)v14->padding_size;
      memset(&v7->bm_data[v13], v16 - 1, v16);
      v13 += v16;
      v7->bm_index = v13;
    }
    v17 = &v7->write_sequence[7];
    do
    {
      v4 = (*v17)++ == -1;
      if ( !v4 )
        break;
      --v17;
    }
    while ( (signed __int64)&v17[-17608i64 - (_QWORD)v7] >= 0 );
    v7->cipher_info->encrypt(v7->encrypt_ctx, v7->bm_data, v7->bm_data, v13);
  }
  else if ( v6 == 22 )
  {
    v18 = v7->bm_data;
    if ( *v18 )
      add_packet(v7, v18, v7->bm_index);
  }
  v19 = send_raw_packet(v7, v6);
  if ( v19 <= 0 )
    LODWORD(buf_len) = v19;
  return (unsigned int)buf_len;
}

// File Line: 1192
// RVA: 0xEEFB54
void __fastcall set_key_block(_SSL *ssl, int is_write)
{
  _SSL *v2; // r15
  int v3; // er12
  char v4; // dl
  cipher_info_t *v5; // rax
  int v6; // ecx
  cipher_info_t *v7; // r13
  int v8; // edi
  DISPOSABLE_CTX *v9; // rax
  int olen; // esi
  const char *v11; // r14
  char *v12; // rbx
  char *v13; // rdi
  DISPOSABLE_CTX *v14; // rax
  char *v15; // rbx
  size_t v16; // r8
  char *v17; // rbx
  char *v18; // rbx
  size_t v19; // r8
  char *v20; // rbx
  char *v21; // rbx
  unsigned __int8 v22; // al
  void *v23; // rcx
  char *v24; // r8
  _SSL *v25; // rcx
  char *v26; // r8
  char *v27; // rdx
  char *v28; // r8
  char *v29; // rdx
  int v30; // [rsp+30h] [rbp-A8h]
  char *out; // [rsp+38h] [rbp-A0h]
  char v32; // [rsp+40h] [rbp-98h]
  char iv; // [rsp+50h] [rbp-88h]
  char v34; // [rsp+58h] [rbp-80h]
  char key; // [rsp+60h] [rbp-78h]
  char _Dst; // [rsp+78h] [rbp-60h]
  char Dst; // [rsp+85h] [rbp-53h]
  char v38; // [rsp+A5h] [rbp-33h]

  v2 = ssl;
  v3 = is_write;
  v4 = ssl->cipher;
  v5 = cipher_info;
  v6 = 0;
  while ( v5->cipher != v4 )
  {
    ++v5;
    ++v6;
    if ( (signed __int64)v5 >= (signed __int64)"server finished" )
    {
      v7 = 0i64;
      goto LABEL_6;
    }
  }
  v7 = &cipher_info[v6];
LABEL_6:
  v8 = v2->flag & 0x10;
  v30 = v2->flag & 0x10;
  if ( !v2->dc->key_block )
  {
    v2->dc->key_block = (char *)ax_malloc((unsigned __int8)v7->key_block_size);
    v9 = v2->dc;
    out = v9->key_block;
    if ( out )
    {
      olen = (unsigned __int8)v7->key_block_size;
      v11 = v9->master_secret;
      v12 = v9->server_random;
      v13 = v9->client_random;
      strcpy_s(&_Dst, 0x80ui64, "key expansion");
      memmove(&Dst, v12, 0x20ui64);
      memmove(&v38, v13, 0x20ui64);
      prf(v11, 48, &_Dst, 77, out, olen);
      v8 = v30;
    }
  }
  v14 = v2->dc;
  v15 = v14->key_block;
  if ( !v8 )
  {
    if ( v3 )
      goto LABEL_14;
    goto LABEL_13;
  }
  if ( v3 )
LABEL_13:
    memmove(v2->client_mac, v14->key_block, (unsigned __int8)v7->digest_size);
LABEL_14:
  v16 = (unsigned __int8)v7->digest_size;
  v17 = &v15[v16];
  if ( v8 )
  {
    if ( v3 )
      goto LABEL_19;
    goto LABEL_18;
  }
  if ( v3 )
LABEL_18:
    memmove(v2->server_mac, v17, v16);
LABEL_19:
  v18 = &v17[(unsigned __int8)v7->digest_size];
  memmove(&v34, v18, (unsigned __int8)v7->key_size);
  v19 = (unsigned __int8)v7->key_size;
  v20 = &v18[v19];
  memmove(&key, v20, v19);
  v21 = &v20[(unsigned __int8)v7->key_size];
  v22 = v7->iv_size;
  if ( v22 )
  {
    memmove(&v32, v21, v22);
    memmove(&iv, &v21[(unsigned __int8)v7->iv_size], (unsigned __int8)v7->iv_size);
  }
  if ( v3 )
    v23 = v2->encrypt_ctx;
  else
    v23 = v2->decrypt_ctx;
  ax_free(v23);
  v24 = v2->dc->final_finish_mac;
  if ( !v8 )
  {
    finished_digest(v2, client_finished, v24);
    v25 = v2;
    if ( v3 )
    {
      v26 = &iv;
      v27 = &key;
      goto LABEL_30;
    }
    v28 = &v32;
    v29 = &v34;
LABEL_32:
    v2->decrypt_ctx = crypt_new(v25, v29, v28, 1);
    goto LABEL_33;
  }
  finished_digest(v2, server_finished, v24);
  v25 = v2;
  if ( !v3 )
  {
    v28 = &iv;
    v29 = &key;
    goto LABEL_32;
  }
  v26 = &v32;
  v27 = &v34;
LABEL_30:
  v2->encrypt_ctx = crypt_new(v25, v27, v26, 0);
LABEL_33:
  v2->cipher_info = v7;
}

// File Line: 1278
// RVA: 0xEEE9F0
__int64 __fastcall basic_read(_SSL *ssl, char **in_data)
{
  unsigned __int8 *v2; // rsi
  char **v3; // r14
  _SSL *v4; // rbx
  int v5; // edi
  unsigned int v6; // er15
  int v7; // ebp
  unsigned __int16 v9; // ax
  unsigned int v10; // er9
  int v11; // ebp
  int v12; // eax
  unsigned __int16 v13; // cx
  int v14; // er9
  char *v15; // rcx
  bool v16; // zf
  char *v17; // rcx

  v2 = (unsigned __int8 *)ssl->bm_data;
  v3 = in_data;
  v4 = ssl;
  v5 = 0;
  v6 = ssl->flag & 0x10;
  v7 = recv_0(ssl->client_fd, (char *)&v2[ssl->bm_read_index], ssl->need_bytes - ssl->got_bytes, 0);
  if ( v7 < 0 && GetLastError() == 10035 )
    return 0i64;
  if ( v7 > 0 )
  {
    v4->got_bytes += v7;
    v9 = v4->got_bytes;
    v4->bm_read_index += v7;
    if ( v9 < v4->need_bytes )
      return 0i64;
    v10 = v4->flag;
    v11 = v9;
    v4->got_bytes = 0;
    if ( v10 & 1 )
    {
      if ( (*v2 & 0x80u) != 0 && v2[2] == 1 && v2[3] == 3 )
      {
        add_packet(v4, (const char *)v2 + 2, 3);
        v12 = process_sslv23_client_hello(v4);
LABEL_17:
        v5 = v12;
        goto $error_1;
      }
      v13 = v2[4] + (v2[3] << 8);
      v4->need_bytes = v13;
      if ( v13 <= 0x43FBu )
      {
        v4->flag = v10 & 0xFFFFFFFE;
        memmove(v4->hmac_header, v2, 3ui64);
        v4->record_type = *v2;
        goto $error_1;
      }
    }
    else
    {
      v14 = v10 | 1;
      v4->flag = v14;
      v4->need_bytes = 5;
      if ( v14 & 4 )
      {
        v4->cipher_info->decrypt(v4->decrypt_ctx, (const char *)v2, (char *)v2, v9);
        v12 = verify_digest(v4, v6 != 0 ? 2 : 0, (const char *)v2, v11);
        v11 = v12;
        if ( v12 < 0 )
          goto LABEL_17;
        v15 = &v4->read_sequence[7];
        do
        {
          v16 = (*v15)++ == -1;
          if ( !v16 )
            break;
          --v15;
        }
        while ( (signed __int64)&v15[-17600i64 - (_QWORD)v4] >= 0 );
      }
      switch ( v4->record_type )
      {
        case 0x14:
          if ( v4->next_state == 20 )
          {
            v4->flag |= 4u;
            set_key_block(v4, 0);
            memset(v4->read_sequence, 0, 8ui64);
          }
          else
          {
            v5 = -260;
          }
          goto $error_1;
        case 0x15:
          v5 = -v2[1];
          goto $error_1;
        case 0x16:
          v4->dc->bm_proc_index = 0;
          v12 = do_handshake(v4, (char *)v2, v11);
          goto LABEL_17;
        case 0x17:
          if ( v3 )
          {
            v17 = v4->bm_data;
            *v3 = v17;
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
  v4->hs_status = -2;
$error_1:
  v4->bm_read_index = 0;
  if ( v5 < 0 )
  {
    if ( v3 )
      *v3 = 0i64;
  }
  return (unsigned int)v5;
}

// File Line: 1441
// RVA: 0xEEED8C
int __fastcall do_handshake(_SSL *ssl, char *buf, int read_len)
{
  int v3; // eax
  int v4; // ebx
  _SSL *v5; // rdi
  unsigned __int8 v6; // cl
  char *v7; // rsi
  int v8; // edx
  int v9; // ebp
  int v10; // ebx
  int v11; // er10
  int result; // eax
  int v13; // ebx
  int v14; // [rsp+40h] [rbp+8h]
  int v15; // [rsp+50h] [rbp+18h]

  v3 = (unsigned __int8)buf[3];
  v4 = (unsigned __int8)buf[2];
  v5 = ssl;
  v6 = *buf;
  v7 = buf;
  v8 = v5->flag & 0x10;
  v9 = read_len;
  v10 = v3 + (v4 << 8);
  v15 = v5->flag & 0x10;
  if ( read_len - 4 < v10 )
    return -260;
  v11 = v6;
  v14 = v6;
  if ( v6 != v5->next_state && (!v8 || v6 != 13 || v5->next_state != 14) )
    return -260;
  v13 = v10 + 4;
  v5->bm_index = v13;
  if ( v6 != 15 && v6 )
  {
    add_packet(v5, v7, v13);
    v8 = v15;
    v11 = v14;
  }
  if ( v8 )
    result = do_clnt_handshake(v5, v11, v7, v13);
  else
    result = do_svr_handshake(v5, v11, v7, v13);
  if ( v13 < v9 && !result )
    result = do_handshake(v5, &v7[v13], v9 - v13);
  return result;
}

// File Line: 1489
// RVA: 0xEEF7CC
__int64 __fastcall send_change_cipher_spec(_SSL *ssl)
{
  _SSL *v1; // rdi
  int v2; // eax
  unsigned int v3; // ebx

  v1 = ssl;
  v2 = send_packet(ssl, 20, g_chg_cipher_spec_pkt, 1);
  v1->flag |= 2u;
  v3 = v2;
  set_key_block(v1, 1);
  memset(v1->write_sequence, 0, 8ui64);
  return v3;
}

// File Line: 1502
// RVA: 0xEEF820
int __fastcall send_finished(_SSL *ssl)
{
  char *v1; // r8
  const char *v2; // rdx
  _SSL *v3; // rbx
  char *v4; // r8

  v1 = ssl->bm_data;
  v2 = server_finished;
  v3 = ssl;
  *(_DWORD *)v1 = 201326612;
  v4 = v1 + 4;
  if ( ssl->flag & 0x10 )
    v2 = client_finished;
  finished_digest(ssl, v2, v4);
  if ( !(v3->flag & 8) && v3->ssl_ctx->num_sessions )
    memmove(v3->session->master_secret, v3->dc->master_secret, 0x30ui64);
  return send_packet(v3, 22, 0i64, 16);
}

// File Line: 1533
// RVA: 0xEEF5D8
signed __int64 __fastcall send_alert(_SSL *ssl, int error_code)
{
  unsigned int v2; // ebx
  _SSL *v3; // r10
  bool v4; // zf
  char v5; // cl
  signed int v6; // edi
  char v8; // al
  char in; // [rsp+20h] [rbp-18h]
  char v10; // [rsp+21h] [rbp-17h]

  v2 = 0;
  v3 = ssl;
  v4 = ssl->hs_status == -2;
  v5 = 0;
  v6 = 0;
  if ( v4 )
    return 4294967040i64;
  if ( error_code > -263 )
  {
    if ( error_code != -262 )
    {
      if ( error_code <= -262 )
        goto LABEL_9;
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
          goto LABEL_23;
        }
        v6 = 1;
      }
      goto LABEL_23;
    }
LABEL_22:
    v5 = 20;
    goto LABEL_23;
  }
  switch ( error_code )
  {
    case -263:
      v5 = 70;
      goto LABEL_23;
    case -271:
      goto LABEL_22;
    case -269:
LABEL_13:
      v5 = 47;
      goto LABEL_23;
  }
  if ( error_code != -268 )
  {
    if ( (unsigned int)(error_code + 266) > 1 )
      goto LABEL_9;
    goto LABEL_13;
  }
  v5 = 42;
LABEL_23:
  v10 = v5;
  in = 2 - (v6 != 0);
  send_packet(v3, 21, &in, 2);
  LOBYTE(v2) = v6 == 0;
  return v2;
}

// File Line: 1602
// RVA: 0xEEF51C
signed __int64 __fastcall process_finished(_SSL *ssl, int __formal)
{
  __int16 v2; // bx
  unsigned int v3; // ebp
  unsigned int v4; // er14
  _SSL *v5; // rsi
  unsigned int v6; // edi

  HIBYTE(v2) = 0;
  v3 = ssl->flag & 8;
  v4 = ssl->flag & 0x10;
  v5 = ssl;
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
        v5->hs_status = v6;
        LOBYTE(v2) = v4 == 0;
        v5->next_state = v2;
        return v6;
      }
    }
    else if ( v3 )
    {
      goto LABEL_11;
    }
    v6 = send_change_cipher_spec(v5);
    if ( !v6 )
      v6 = send_finished(v5);
    goto LABEL_11;
  }
  return (unsigned int)-260;
}

// File Line: 1632
// RVA: 0xEEF6E0
int __fastcall send_certificate(_SSL *ssl)
{
  char *v1; // rdi
  signed int v2; // er15
  _SSL *v3; // rbp
  int v4; // esi
  __int64 v5; // r14
  _SSL_CTX *v6; // rbx
  __int64 v7; // rax
  int v8; // esi
  __int64 v9; // rax

  v1 = ssl->bm_data;
  v2 = 0;
  v3 = ssl;
  *(_WORD *)v1 = 11;
  v1[4] = 0;
  v4 = 7;
  if ( ssl->ssl_ctx->chain_length )
  {
    v5 = 0i64;
    do
    {
      v6 = v3->ssl_ctx;
      v7 = v4;
      v8 = v4 + 1;
      v1[v7] = 0;
      v9 = v8++;
      v1[v9] = LOWORD(v6->certs[v5].size) >> 8;
      v1[v8++] = v6->certs[v5].size;
      memmove(&v1[v8], v6->certs[v5].buf, v6->certs[v5].size);
      v4 = v6->certs[v5].size + v8;
      ++v2;
      ++v5;
    }
    while ( v2 < (unsigned __int8)v3->ssl_ctx->chain_length );
  }
  v1[6] = v4 - 7;
  v1[3] = v4 - 7 + 3;
  v1[5] = (unsigned __int16)(v4 - 7) >> 8;
  v1[2] = (unsigned __int16)(v4 - 7 + 3) >> 8;
  v3->bm_index = v4;
  return send_packet(v3, 22, 0i64, v4);
}

// File Line: 1668
// RVA: 0xEEED48
void __fastcall disposable_new(_SSL *ssl)
{
  _SSL *v1; // rbx
  MD5_CTX *v2; // rax

  v1 = ssl;
  if ( !ssl->dc )
  {
    v2 = (MD5_CTX *)ax_calloc(1ui64, 0x140ui64);
    v1->dc = (DISPOSABLE_CTX *)v2;
    if ( v2 )
    {
      MD5_Init(v2);
      SHA1_Init(&v1->dc->sha1_ctx);
    }
  }
}

// File Line: 1684
// RVA: 0xEEED04
void __fastcall disposable_free(_SSL *ssl)
{
  _SSL *v1; // rbx
  DISPOSABLE_CTX *v2; // rcx

  v1 = ssl;
  v2 = ssl->dc;
  if ( v2 )
  {
    ax_free(v2->key_block);
    memset(v1->dc, 0, 0x140ui64);
    ax_free(v1->dc);
    v1->dc = 0i64;
  }
}

// File Line: 1702
// RVA: 0xEF01D0
SSL_SESSION *__fastcall ssl_session_update(int max_sessions, SSL_SESSION **ssl_sessions, _SSL *ssl, const char *session_id)
{
  int v4; // ebp
  const char *v5; // r13
  _SSL *v6; // rdi
  SSL_SESSION **v7; // rsi
  SSL_SESSION *v8; // r14
  signed __int64 v9; // r12
  signed __int64 v10; // r15
  int v12; // ebx
  SSL_SESSION *v13; // rcx
  int v14; // ebx
  SSL_SESSION *v15; // rcx
  DISPOSABLE_CTX *v16; // rcx
  _SSL_CTX *v17; // rcx
  SSL_SESSION *v18; // rax
  _SSL_CTX *v19; // rcx

  v4 = max_sessions;
  v5 = session_id;
  v6 = ssl;
  v7 = ssl_sessions;
  v8 = 0i64;
  v9 = time64(0i64);
  v10 = v9;
  if ( !v4 )
    return 0i64;
  WaitForSingleObject(v6->ssl_ctx->mutex, 0xFFFFFFFF);
  if ( v5 )
  {
    v12 = 0;
    if ( v4 > 0 )
    {
      while ( 1 )
      {
        v13 = v7[v12];
        if ( v13 )
        {
          if ( v9 <= v13->conn_time + 86400 )
          {
            if ( !memcmp(v13->session_id, v5, 0x20ui64) )
            {
              v16 = v6->dc;
              v6->session_index = v12;
              memmove(v16->master_secret, v7[v12]->master_secret, 0x30ui64);
              v17 = v6->ssl_ctx;
              v6->flag |= 8u;
              ReleaseMutex(v17->mutex);
              return v7[v12];
            }
          }
          else
          {
            ax_free(v13);
            v7[v12] = 0i64;
          }
        }
        if ( ++v12 >= v4 )
        {
          v10 = v9;
          break;
        }
      }
    }
  }
  v14 = 0;
  if ( v4 <= 0 )
  {
LABEL_16:
    v8->conn_time = v9;
    memset(v8->session_id, 0, 4ui64);
    memset(v8->master_secret, 0, 4ui64);
    ReleaseMutex(v6->ssl_ctx->mutex);
    return v8;
  }
  while ( 1 )
  {
    v15 = v7[v14];
    if ( !v15 )
      break;
    if ( v15->conn_time <= v10 )
    {
      v10 = v15->conn_time;
      v8 = v7[v14];
      v6->session_index = v14;
    }
    if ( ++v14 >= v4 )
      goto LABEL_16;
  }
  v18 = (SSL_SESSION *)ax_calloc(1ui64, 0x58ui64);
  v7[v14] = v18;
  if ( !v18 )
    return 0i64;
  v18->conn_time = v9;
  v19 = v6->ssl_ctx;
  v6->session_index = v14;
  ReleaseMutex(v19->mutex);
  return v7[v14];
}

// File Line: 1790
// RVA: 0xEEF160
void __fastcall kill_ssl_session(SSL_SESSION **ssl_sessions, _SSL *ssl)
{
  SSL_SESSION **v2; // rsi
  _SSL *v3; // rbx
  __int64 v4; // rdi
  SSL_SESSION *v5; // rcx

  v2 = ssl_sessions;
  v3 = ssl;
  WaitForSingleObject(ssl->ssl_ctx->mutex, 0xFFFFFFFF);
  if ( v3->ssl_ctx->num_sessions )
  {
    v4 = v3->session_index;
    v5 = v2[v4];
    if ( v5 )
    {
      ax_free(v5);
      v2[v4] = 0i64;
    }
    v3->session = 0i64;
  }
  ReleaseMutex(v3->ssl_ctx->mutex);
}

// File Line: 1895
// RVA: 0xEEF40C
__int64 __fastcall process_certificate(_SSL *ssl, _x509_ctx **x509_ctx)
{
  unsigned int v2; // ebx
  char *v3; // r13
  int v4; // edi
  unsigned int v5; // er15
  _x509_ctx **v6; // r14
  _SSL *v7; // rsi
  int v8; // ebp
  int v9; // edi
  __int64 v10; // rax
  int v11; // edi
  int v12; // er12
  int v14; // [rsp+50h] [rbp+8h]

  v2 = 0;
  v3 = &ssl->bm_data[ssl->dc->bm_proc_index];
  v14 = ssl->bm_index;
  v4 = 7;
  v5 = ssl->flag & 0x10;
  v6 = x509_ctx;
  v7 = ssl;
  v8 = (unsigned __int8)v3[6] + ((unsigned __int8)v3[5] << 8);
  if ( v8 < 7 )
    return (unsigned int)-260;
  if ( v8 <= 7 )
  {
LABEL_5:
    if ( v14 >= v4 )
    {
      if ( v5 && !(v7->flag & 0x20000) )
        v2 = ssl_verify_cert_win(v3 + 7, v8);
      v7->next_state = v5 != 0 ? 14 : 16;
      v7->dc->bm_proc_index += v4;
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
    if ( x509_new(&v3[v11], 0i64, v6) )
      return (unsigned int)-268;
    v4 = v12 + v11;
    v6 = &(*v6)->next;
    if ( v4 >= v8 )
      goto LABEL_5;
  }
}

