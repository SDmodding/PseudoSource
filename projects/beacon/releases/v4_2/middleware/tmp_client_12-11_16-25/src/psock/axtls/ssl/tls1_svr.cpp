// File Line: 75
// RVA: 0xEF4C1C
__int64 __fastcall do_svr_handshake(_SSL *ssl, int handshake_type, char *buf, int hs_len)
{
  unsigned int v4; // ebx
  int v5; // esi
  char *v6; // rbp
  _SSL *v7; // rdi
  int v8; // edx
  int v9; // edx
  int v10; // edx
  int v11; // edx
  _x509_ctx **v13; // rsi
  int v14; // eax

  v4 = 0;
  v5 = hs_len;
  v6 = buf;
  v7 = ssl;
  ssl->hs_status = -1;
  v8 = handshake_type - 1;
  if ( !v8 )
  {
    v4 = process_client_hello(ssl);
    if ( v4 )
      return v4;
    return (unsigned int)send_server_hello_sequence(v7);
  }
  v9 = v8 - 10;
  if ( v9 )
  {
    v10 = v9 - 4;
    if ( !v10 )
    {
      v4 = process_cert_verify(ssl);
      add_packet(v7, v6, v5);
      return v4;
    }
    v11 = v10 - 1;
    if ( v11 )
    {
      if ( v11 == 4 )
      {
        v4 = process_finished(ssl, hs_len);
        disposable_free(v7);
      }
      return v4;
    }
    return (unsigned int)process_client_key_xchg(ssl);
  }
  v13 = &ssl->x509_ctx;
  v4 = process_certificate(ssl, &ssl->x509_ctx);
  if ( !v4 )
  {
    v14 = x509_verify(v7->ssl_ctx->ca_cert_ctx, *v13);
    v4 = v14 != 0 ? v14 - 512 : 0;
  }
  return v4;
}

// File Line: 122
// RVA: 0xEF4E04
signed __int64 __fastcall process_client_hello(_SSL *ssl)
{
  char *v1; // rsi
  int v2; // er14
  unsigned int v3; // ebx
  _SSL *v4; // rdi
  signed int v5; // ebp
  SSL_SESSION *v7; // rax
  int v8; // ebp
  __int64 v9; // rax
  int v10; // ebp
  int v11; // ecx
  int v12; // edx
  signed __int64 v13; // rax
  __int64 v14; // r8
  __int64 v15; // rcx

  v1 = ssl->bm_data;
  v2 = ssl->bm_index;
  v3 = 0;
  v4 = ssl;
  if ( (unsigned __int8)ssl->hmac_header[2] + 16 * (unsigned __int8)ssl->hmac_header[1] >= 49 )
  {
    memmove(ssl->dc->client_random, v1 + 6, 0x20ui64);
    v5 = (unsigned __int8)v1[38];
    if ( v5 > 32 )
      return 4294967031i64;
    v7 = ssl_session_update(
           v4->ssl_ctx->num_sessions,
           v4->ssl_ctx->ssl_sessions,
           v4,
           (const char *)((unsigned __int64)(v1 + 39) & -(signed __int64)(v5 != 0)));
    v8 = v5 + 39;
    v4->session = v7;
    v9 = v8;
    v10 = v8 + 3;
    v11 = (unsigned __int8)v1[v9 + 1] + ((unsigned __int8)v1[v9] << 8);
    if ( v2 >= v10 )
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
      while ( ssl_prot_prefs[v13] != v1[v10 + v15] )
      {
        v15 += 2i64;
        if ( v15 >= v14 )
          goto LABEL_11;
      }
      v4->cipher = ssl_prot_prefs[v12];
    }
    else
    {
      v3 = -260;
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
  char *v1; // rsi
  _SSL *v2; // r14
  int v3; // ebp
  int v4; // ebx
  int v5; // eax
  __int64 v6; // r13
  int v7; // er12
  int v8; // er15
  signed int v9; // edi
  int v11; // edx
  signed __int64 v12; // rax
  __int64 v13; // rcx
  __int64 v14; // rax
  _SSL_CTX *v15; // rdx
  int v16; // [rsp+60h] [rbp+8h]

  v1 = ssl->bm_data;
  v2 = ssl;
  v3 = (unsigned __int8)v1[1] + ((*v1 & 0x7F) << 8);
  v4 = (unsigned __int8)v1[4] + 16 * (unsigned __int8)v1[3];
  v5 = recv_0(ssl->client_fd, v1, v3 - 3, 0);
  v6 = (unsigned __int8)v1[1];
  v7 = (unsigned __int8)v1[3];
  v8 = v5;
  v16 = (unsigned __int8)v1[5];
  v9 = 0;
  OSuite::ZOEdmBase::CleanTempData((int)v2);
  if ( v4 < 49 )
    return -263;
  add_packet(v2, v1, v8);
  if ( v3 < 0 )
    return -256;
  v11 = 0;
  v12 = 0i64;
  while ( 1 )
  {
    v13 = 0i64;
    if ( (signed int)v6 > 0 )
      break;
LABEL_9:
    ++v12;
    ++v11;
    if ( v12 >= 4 )
      return -266;
  }
  while ( ssl_prot_prefs[v12] != v1[v13 + 8] )
  {
    v13 += 3i64;
    if ( v13 >= v6 )
      goto LABEL_9;
  }
  v14 = v11;
  v15 = v2->ssl_ctx;
  v2->cipher = ssl_prot_prefs[v14];
  v2->session = ssl_session_update(
                  v15->num_sessions,
                  v15->ssl_sessions,
                  v2,
                  (const char *)((unsigned __int64)&v1[(signed int)v6 + 6] & -(signed __int64)(v7 != 0)));
  if ( v16 == 16 )
    v9 = 16;
  memmove(&v2->dc->client_random[v9], &v1[v7 + 6 + (signed int)v6], v16);
  return send_server_hello_sequence(v2);
}

// File Line: 261
// RVA: 0xEF5214
int __fastcall send_server_hello_sequence(_SSL *ssl)
{
  char *v1; // rsi
  _SSL *v2; // rdi
  bool v3; // zf
  _SSL_CTX *v4; // rax
  int result; // eax
  signed __int16 v6; // cx

  v1 = ssl->bm_data;
  v2 = ssl;
  *(_WORD *)v1 = 2;
  v1[2] = 0;
  *((_WORD *)v1 + 2) = 259;
  get_random(32, v1 + 6);
  memmove(v2->dc->server_random, v1 + 6, 0x20ui64);
  v3 = (v2->flag & 8) == 0;
  v1[38] = 32;
  if ( v3 )
  {
    get_random(32, v1 + 39);
    memmove(v2->session_id, v1 + 39, 0x20ui64);
    v4 = v2->ssl_ctx;
    v2->sess_id_size = 32;
    if ( v4->num_sessions )
      memmove(v2->session->session_id, v2->session_id, 0x20ui64);
  }
  else
  {
    memmove(v1 + 39, v2->session->session_id, 0x20ui64);
    memmove(v2->session_id, v2->session->session_id, 0x20ui64);
    v2->sess_id_size = 32;
  }
  v1[71] = 0;
  v1[72] = v2->cipher;
  v1[73] = 0;
  v1[3] = 70;
  result = send_packet(v2, 22, 0i64, 74);
  if ( !result )
  {
    if ( v2->flag & 8 )
    {
      result = send_change_cipher_spec(v2);
      if ( result )
        return result;
      result = send_finished(v2);
      v6 = 20;
    }
    else
    {
      result = send_certificate(v2);
      if ( result )
        return result;
      if ( v2->flag & 0x10000 )
      {
        result = send_packet(v2, 22, g_cert_request, 8);
        if ( result )
          return result;
        result = send_packet(v2, 22, g_hello_done, 4);
        v6 = 11;
      }
      else
      {
        result = send_packet(v2, 22, g_hello_done, 4);
        v6 = 16;
      }
    }
    v2->next_state = v6;
  }
  return result;
}

// File Line: 376
// RVA: 0xEF4F40
__int64 __fastcall process_client_key_xchg(_SSL *ssl)
{
  _SSL_CTX *v1; // r9
  RSA_CTX *v2; // r14
  unsigned int v3; // esi
  char *v4; // rbx
  _SSL *v5; // rdi
  signed int v6; // ebp
  int v7; // er8
  int v8; // ebx
  __int64 result; // rax
  char out_data; // [rsp+20h] [rbp-228h]
  char v11; // [rsp+21h] [rbp-227h]

  v1 = ssl->ssl_ctx;
  v2 = v1->rsa_ctx;
  v3 = 0;
  v4 = &ssl->bm_data[ssl->dc->bm_proc_index];
  v5 = ssl;
  v6 = 4;
  if ( v2 )
  {
    v7 = v2->num_octets;
    if ( ((unsigned __int8)v4[2] << 8) + (unsigned __int8)v4[3] - 2 == v7 )
      v6 = 6;
    if ( ssl->bm_index >= v7 + v6 )
    {
      WaitForSingleObject(v1->mutex, 0xFFFFFFFF);
      v8 = RSA_decrypt(v2, &v4[v6], &out_data, 1);
      ReleaseMutex(v5->ssl_ctx->mutex);
      if ( v8 != 48 || out_data != 3 || v11 != 1 )
        memset(&out_data, 0, 0x30ui64);
      generate_master_secret(v5, &out_data);
      v5->next_state = (v5->flag & 0x10000) != 0 ? 15 : 20;
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
  v5->dc->bm_proc_index += v6 + LOWORD(v2->num_octets);
  return result;
}

// File Line: 445
// RVA: 0xEF4CF0
__int64 __fastcall process_cert_verify(_SSL *ssl)
{
  _x509_ctx *v1; // rbp
  signed int v2; // esi
  char *v3; // rbx
  _SSL *v4; // rdi
  unsigned int v5; // ecx
  int v6; // ebx
  char digest; // [rsp+20h] [rbp-248h]
  char out_data; // [rsp+50h] [rbp-218h]

  v1 = ssl->x509_ctx;
  v2 = 0;
  v3 = &ssl->bm_data[ssl->dc->bm_proc_index];
  v4 = ssl;
  if ( ssl->bm_index >= v1->rsa_ctx->num_octets + 6 )
  {
    WaitForSingleObject(ssl->ssl_ctx->mutex, 0xFFFFFFFF);
    v6 = RSA_decrypt(v1->rsa_ctx, v3 + 6, &out_data, 0);
    ReleaseMutex(v4->ssl_ctx->mutex);
    if ( v6 == 36 )
    {
      finished_digest(v4, 0i64, &digest);
      if ( memcmp(&out_data, &digest, 0x24ui64) )
        v2 = -269;
      v5 = v2;
    }
    else
    {
      v5 = -269;
    }
    v4->next_state = 20;
  }
  else
  {
    v5 = -260;
  }
  return v5;
}

