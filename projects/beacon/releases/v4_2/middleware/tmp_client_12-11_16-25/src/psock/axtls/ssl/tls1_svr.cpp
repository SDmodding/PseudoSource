// File Line: 75
// RVA: 0xEF4C1C
__int64 __fastcall do_svr_handshake(_SSL *ssl, int handshake_type, char *buf, unsigned int hs_len)
{
  unsigned int v4; // ebx
  int v8; // edx
  int v9; // edx
  int v10; // edx
  int v11; // edx
  _x509_ctx **p_x509_ctx; // rsi
  int v14; // eax

  v4 = 0;
  ssl->hs_status = -1;
  v8 = handshake_type - 1;
  if ( !v8 )
  {
    v4 = process_client_hello(ssl);
    if ( v4 )
      return v4;
    return (unsigned int)send_server_hello_sequence(ssl);
  }
  v9 = v8 - 10;
  if ( v9 )
  {
    v10 = v9 - 4;
    if ( !v10 )
    {
      v4 = process_cert_verify(ssl);
      add_packet(ssl, buf, hs_len);
      return v4;
    }
    v11 = v10 - 1;
    if ( v11 )
    {
      if ( v11 == 4 )
      {
        v4 = process_finished(ssl, hs_len);
        disposable_free(ssl);
      }
      return v4;
    }
    return (unsigned int)process_client_key_xchg(ssl);
  }
  p_x509_ctx = &ssl->x509_ctx;
  v4 = process_certificate(ssl, &ssl->x509_ctx);
  if ( !v4 )
  {
    v14 = x509_verify(ssl->ssl_ctx->ca_cert_ctx, *p_x509_ctx);
    return (v14 - 512) & (unsigned int)-(v14 != 0);
  }
  return v4;
}

// File Line: 122
// RVA: 0xEF4E04
__int64 __fastcall process_client_hello(_SSL *ssl)
{
  char *bm_data; // rsi
  int bm_index; // r14d
  unsigned int v3; // ebx
  unsigned int v5; // ebp
  SSL_SESSION *v7; // rax
  signed int v8; // ebp
  __int64 v9; // rax
  int v10; // ebp
  int v11; // ecx
  int v12; // edx
  __int64 v13; // rax
  __int64 v14; // r8
  __int64 v15; // rcx

  bm_data = ssl->bm_data;
  bm_index = ssl->bm_index;
  v3 = 0;
  if ( (unsigned __int8)ssl->hmac_header[2] + 16 * (unsigned __int8)ssl->hmac_header[1] >= 49 )
  {
    memmove(ssl->dc->client_random, bm_data + 6, 0x20ui64);
    v5 = (unsigned __int8)bm_data[38];
    if ( v5 > 0x20 )
      return 4294967031i64;
    v7 = ssl_session_update(
           ssl->ssl_ctx->num_sessions,
           ssl->ssl_ctx->ssl_sessions,
           ssl,
           (const char *)((unsigned __int64)(bm_data + 39) & -(__int64)(v5 != 0)));
    v8 = v5 + 39;
    ssl->session = v7;
    v9 = v8;
    v10 = v8 + 3;
    v11 = (unsigned __int8)bm_data[v9 + 1] + ((unsigned __int8)bm_data[v9] << 8);
    if ( bm_index >= v10 )
    {
      v12 = 0;
      v13 = 0i64;
      v14 = v11;
      while ( 1 )
      {
        v15 = 0i64;
        if ( v14 > 0 )
          break;
LABEL_11:
        ++v13;
        ++v12;
        if ( v13 >= 4 )
          return (unsigned int)-266;
      }
      while ( ssl_prot_prefs[v13] != bm_data[v10 + v15] )
      {
        v15 += 2i64;
        if ( v15 >= v14 )
          goto LABEL_11;
      }
      ssl->cipher = ssl_prot_prefs[v12];
    }
    else
    {
      return (unsigned int)-260;
    }
  }
  else
  {
    v3 = -263;
    OSuite::ZOEdmBase::CleanTempData(-263);
  }
  return v3;
}

// File Line: 184
// RVA: 0xEF5098
int __fastcall process_sslv23_client_hello(_SSL *ssl)
{
  char *bm_data; // rsi
  int v3; // ebp
  int v4; // ebx
  int v5; // eax
  __int64 v6; // r13
  int v7; // r12d
  unsigned int v8; // r15d
  int v9; // edi
  int v11; // edx
  __int64 v12; // rax
  __int64 v13; // rcx
  __int64 v14; // rax
  _SSL_CTX *ssl_ctx; // rdx
  int v16; // [rsp+60h] [rbp+8h]

  bm_data = ssl->bm_data;
  v3 = (unsigned __int8)bm_data[1] + ((*bm_data & 0x7F) << 8);
  v4 = (unsigned __int8)bm_data[4] + 16 * (unsigned __int8)bm_data[3];
  v5 = recv_0(ssl->client_fd, bm_data, v3 - 3, 0);
  v6 = (unsigned __int8)bm_data[1];
  v7 = (unsigned __int8)bm_data[3];
  v8 = v5;
  v16 = (unsigned __int8)bm_data[5];
  v9 = 0;
  OSuite::ZOEdmBase::CleanTempData((int)ssl);
  if ( v4 < 49 )
    return -263;
  add_packet(ssl, bm_data, v8);
  if ( v3 < 0 )
    return -256;
  v11 = 0;
  v12 = 0i64;
  while ( 1 )
  {
    v13 = 0i64;
    if ( (int)v6 > 0 )
      break;
LABEL_9:
    ++v12;
    ++v11;
    if ( v12 >= 4 )
      return -266;
  }
  while ( ssl_prot_prefs[v12] != bm_data[v13 + 8] )
  {
    v13 += 3i64;
    if ( v13 >= v6 )
      goto LABEL_9;
  }
  v14 = v11;
  ssl_ctx = ssl->ssl_ctx;
  ssl->cipher = ssl_prot_prefs[v14];
  ssl->session = ssl_session_update(
                   ssl_ctx->num_sessions,
                   ssl_ctx->ssl_sessions,
                   ssl,
                   (const char *)((unsigned __int64)&bm_data[(int)v6 + 6] & -(__int64)(v7 != 0)));
  if ( v16 == 16 )
    v9 = 16;
  memmove(&ssl->dc->client_random[v9], &bm_data[v7 + 6 + (int)v6], v16);
  return send_server_hello_sequence(ssl);
}

// File Line: 261
// RVA: 0xEF5214
int __fastcall send_server_hello_sequence(_SSL *ssl)
{
  char *bm_data; // rsi
  bool v3; // zf
  _SSL_CTX *ssl_ctx; // rax
  int result; // eax
  __int16 v6; // cx

  bm_data = ssl->bm_data;
  *(_WORD *)bm_data = 2;
  bm_data[2] = 0;
  *((_WORD *)bm_data + 2) = 259;
  get_random(0x20u, bm_data + 6);
  memmove(ssl->dc->server_random, bm_data + 6, 0x20ui64);
  v3 = (ssl->flag & 8) == 0;
  bm_data[38] = 32;
  if ( v3 )
  {
    get_random(0x20u, bm_data + 39);
    memmove(ssl->session_id, bm_data + 39, 0x20ui64);
    ssl_ctx = ssl->ssl_ctx;
    ssl->sess_id_size = 32;
    if ( ssl_ctx->num_sessions )
      memmove(ssl->session->session_id, ssl->session_id, 0x20ui64);
  }
  else
  {
    memmove(bm_data + 39, ssl->session->session_id, 0x20ui64);
    memmove(ssl->session_id, ssl->session->session_id, 0x20ui64);
    ssl->sess_id_size = 32;
  }
  bm_data[71] = 0;
  bm_data[72] = ssl->cipher;
  bm_data[73] = 0;
  bm_data[3] = 70;
  result = send_packet(ssl, 22, 0i64, 74);
  if ( !result )
  {
    if ( (ssl->flag & 8) != 0 )
    {
      result = send_change_cipher_spec(ssl);
      if ( result )
        return result;
      result = send_finished(ssl);
      v6 = 20;
    }
    else
    {
      result = send_certificate(ssl);
      if ( result )
        return result;
      if ( (ssl->flag & 0x10000) != 0 )
      {
        result = send_packet(ssl, 22, g_cert_request, 8);
        if ( result )
          return result;
        result = send_packet(ssl, 22, g_hello_done, 4);
        v6 = 11;
      }
      else
      {
        result = send_packet(ssl, 22, g_hello_done, 4);
        v6 = 16;
      }
    }
    ssl->next_state = v6;
  }
  return result;
}

// File Line: 376
// RVA: 0xEF4F40
__int64 __fastcall process_client_key_xchg(_SSL *ssl)
{
  _SSL_CTX *ssl_ctx; // r9
  RSA_CTX *rsa_ctx; // r14
  unsigned int v3; // esi
  char *v4; // rbx
  int v6; // ebp
  int num_octets; // r8d
  int v8; // ebx
  __int64 result; // rax
  char out_data[512]; // [rsp+20h] [rbp-228h] BYREF

  ssl_ctx = ssl->ssl_ctx;
  rsa_ctx = ssl_ctx->rsa_ctx;
  v3 = 0;
  v4 = &ssl->bm_data[ssl->dc->bm_proc_index];
  v6 = 4;
  if ( rsa_ctx )
  {
    num_octets = rsa_ctx->num_octets;
    if ( ((unsigned __int8)v4[2] << 8) + (unsigned __int8)v4[3] - 2 == num_octets )
      v6 = 6;
    if ( ssl->bm_index >= num_octets + v6 )
    {
      WaitForSingleObject(ssl_ctx->mutex, 0xFFFFFFFF);
      v8 = RSA_decrypt(rsa_ctx, &v4[v6], out_data, 1);
      ReleaseMutex(ssl->ssl_ctx->mutex);
      if ( v8 != 48 || out_data[0] != 3 || out_data[1] != 1 )
        memset(out_data, 0, 0x30ui64);
      generate_master_secret(ssl, out_data);
      ssl->next_state = (ssl->flag & 0x10000) != 0 ? 15 : 20;
    }
    else
    {
      v3 = -260;
    }
  }
  else
  {
    v3 = -272;
  }
  result = v3;
  ssl->dc->bm_proc_index += v6 + LOWORD(rsa_ctx->num_octets);
  return result;
}

// File Line: 445
// RVA: 0xEF4CF0
__int64 __fastcall process_cert_verify(_SSL *ssl)
{
  _x509_ctx *x509_ctx; // rbp
  int v2; // esi
  char *v3; // rbx
  unsigned int v5; // ecx
  int v6; // ebx
  char digest[48]; // [rsp+20h] [rbp-248h] BYREF
  char out_data[512]; // [rsp+50h] [rbp-218h] BYREF

  x509_ctx = ssl->x509_ctx;
  v2 = 0;
  v3 = &ssl->bm_data[ssl->dc->bm_proc_index];
  if ( ssl->bm_index >= x509_ctx->rsa_ctx->num_octets + 6 )
  {
    WaitForSingleObject(ssl->ssl_ctx->mutex, 0xFFFFFFFF);
    v6 = RSA_decrypt(x509_ctx->rsa_ctx, v3 + 6, out_data, 0);
    ReleaseMutex(ssl->ssl_ctx->mutex);
    if ( v6 == 36 )
    {
      finished_digest(ssl, 0i64, digest);
      if ( memcmp(out_data, digest, 0x24ui64) )
        v2 = -269;
      v5 = v2;
    }
    else
    {
      v5 = -269;
    }
    ssl->next_state = 20;
  }
  else
  {
    return (unsigned int)-260;
  }
  return v5;
}

