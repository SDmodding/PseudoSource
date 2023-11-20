// File Line: 61
// RVA: 0xEF0AF4
_SSL *__fastcall ssl_client_new(_SSL_CTX *ssl_ctx, int client_fd, const char *session_id, char sess_id_size, int *err_code)
{
  unsigned __int8 v5; // di
  const char *v6; // rsi
  _SSL_CTX *v7; // rbp
  _SSL *v8; // rax
  _SSL *v9; // rbx
  int v11; // edi

  v5 = sess_id_size;
  v6 = session_id;
  v7 = ssl_ctx;
  v8 = ssl_new(ssl_ctx, client_fd);
  v9 = v8;
  if ( !v8 )
    return 0i64;
  if ( v6 && v7->num_sessions )
  {
    if ( v5 > 0x20u )
    {
      ssl_free(v8);
      return 0i64;
    }
    memmove(v8->session_id, v6, v5);
    v9->flag |= 8u;
    v9->sess_id_size = v5;
  }
  v9->flag |= 0x10u;
  v11 = do_client_connect(v9);
  if ( v11 )
  {
    ssl_free(v9);
    v9 = 0i64;
  }
  if ( err_code )
    *err_code = v11;
  return v9;
}

// File Line: 103
// RVA: 0xEF068C
__int64 __fastcall do_clnt_handshake(_SSL *ssl, int handshake_type, char *__formal, int hs_len)
{
  unsigned int v4; // ebx
  _SSL *v5; // rdi
  int v6; // edx
  int v7; // edx
  int v8; // edx
  int v9; // edx
  bool v10; // zf
  DISPOSABLE_CTX *v12; // rdx
  char *v13; // rax
  int v14; // ecx
  signed int v15; // ecx

  v4 = 0;
  v5 = ssl;
  if ( !handshake_type )
  {
    disposable_new(ssl);
    return (unsigned int)do_client_connect(v5);
  }
  v6 = handshake_type - 2;
  if ( !v6 )
    return (unsigned int)process_server_hello(ssl);
  v7 = v6 - 9;
  if ( v7 )
  {
    v8 = v7 - 2;
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( v9 )
      {
        if ( v9 == 6 )
        {
          v4 = process_finished(ssl, hs_len);
          disposable_free(v5);
        }
        return v4;
      }
      v10 = (ssl->flag & 0x20) == 0;
      ssl->next_state = 20;
      if ( v10 )
      {
        v4 = send_client_key_xchg(ssl);
        if ( v4 )
          return v4;
      }
      else
      {
        v4 = send_certificate(ssl);
        if ( v4 )
          return v4;
        v4 = send_client_key_xchg(v5);
        if ( v4 )
          return v4;
        send_cert_verify(v5);
      }
      v4 = send_change_cipher_spec(v5);
      if ( v4 )
        return v4;
      return (unsigned int)send_finished(v5);
    }
    v12 = ssl->dc;
    v13 = &ssl->bm_data[v12->bm_proc_index];
    v14 = (unsigned __int8)v13[2];
    LODWORD(v13) = (unsigned __int8)v13[3];
    v5->flag |= 0x20u;
    v5->next_state = 14;
    v15 = (_DWORD)v13 + 16 * v14;
    LODWORD(v13) = v5->bm_index;
    v12->bm_proc_index += v15;
    if ( (signed int)v13 < v15 )
      v4 = -260;
  }
  else
  {
    v4 = process_certificate(ssl, &ssl->x509_ctx);
    if ( v4 == -522 )
      v4 = 0;
  }
  return v4;
}

// File Line: 165
// RVA: 0xEF04B0
__int64 __fastcall do_client_connect(_SSL *ssl)
{
  char *v1; // r14
  _SSL *v2; // rdi
  int v3; // esi
  int v4; // eax
  int v5; // er9
  __int64 v6; // rax
  int v7; // er9
  signed __int64 v8; // rdx
  __int64 v9; // rax
  int v10; // er9
  __int64 v11; // rax
  int v12; // er9
  __int64 v13; // rcx
  __int64 v14; // rax
  int v15; // er9
  __int64 v16; // rax
  _x509_ctx *v17; // rcx
  int v18; // ebx

  v1 = ssl->bm_data;
  v2 = ssl;
  v3 = 0;
  v4 = time64(0i64);
  *(_WORD *)v1 = 1;
  v1[2] = 0;
  *((_WORD *)v1 + 2) = 259;
  v1[6] = HIBYTE(v4);
  v1[7] = BYTE2(v4);
  v1[8] = BYTE1(v4);
  v1[9] = v4;
  get_random(28, v1 + 10);
  memmove(v2->dc->client_random, v1 + 6, 0x20ui64);
  if ( v2->flag & 8 )
  {
    v1[38] = v2->sess_id_size;
    memmove(v1 + 39, v2->session_id, (unsigned __int8)v2->sess_id_size);
    v5 = (unsigned __int8)v2->sess_id_size + 39;
    v2->flag &= 0xFFFFFFF7;
  }
  else
  {
    v1[38] = 0;
    v5 = 39;
  }
  v6 = v5;
  v7 = v5 + 1;
  v8 = 0i64;
  v1[v6] = 0;
  v9 = v7;
  v10 = v7 + 1;
  v1[v9] = 8;
  do
  {
    v11 = v10;
    v12 = v10 + 1;
    v1[v11] = 0;
    v13 = v12;
    LOBYTE(v11) = ssl_prot_prefs[v8++];
    v10 = v12 + 1;
    v1[v13] = v11;
  }
  while ( v8 < 4 );
  v14 = v10;
  v15 = v10 + 1;
  v1[v14] = 1;
  v16 = v15++;
  v1[v16] = 0;
  v1[3] = v15 - 4;
  send_packet(v2, 22, 0i64, v15);
  v17 = v2->x509_ctx;
  v2->next_state = 2;
  v2->bm_read_index = 0;
  v2->hs_status = -1;
  x509_free(v17);
  v18 = 0;
  while ( v2->hs_status )
  {
    v3 = basic_read(v2, 0i64);
    if ( !v3 )
    {
      if ( !v2->hs_status )
        break;
      if ( ++v18 >= 150 )
      {
        v3 = -256;
        v2->hs_status = -2;
        break;
      }
      Sleep(0x64u);
    }
    if ( v3 < 0 )
    {
      if ( v3 != -256 && (unsigned int)send_alert(v2, v3) )
        kill_ssl_session(v2->ssl_ctx->ssl_sessions, v2);
      break;
    }
  }
  v2->hs_status = v3;
  return (unsigned int)v3;
}

// File Line: 284
// RVA: 0xEF07CC
signed __int64 __fastcall process_server_hello(_SSL *ssl)
{
  char *v1; // rsi
  int v2; // er13
  int v3; // er12
  unsigned int v4; // ebp
  _SSL *v5; // rdi
  unsigned __int8 v7; // r15
  SSL_SESSION *v8; // rax
  char v9; // al
  int v10; // edx

  v1 = ssl->bm_data;
  v2 = ssl->bm_index;
  v3 = ssl->ssl_ctx->num_sessions;
  v4 = 0;
  v5 = ssl;
  if ( (unsigned __int8)v1[5] + 16 * (unsigned __int8)v1[4] != 49 )
    return 4294967033i64;
  memmove(ssl->dc->server_random, v1 + 6, 0x20ui64);
  v7 = v1[38];
  if ( v3 )
  {
    v8 = ssl_session_update(v3, v5->ssl_ctx->ssl_sessions, v5, v1 + 39);
    v5->session = v8;
    memmove(v8->session_id, v1 + 39, v7);
    if ( v7 < 0x20u )
      memset(&v5->session->session_id[v7], 0, 32 - v7);
  }
  memmove(v5->session_id, v1 + 39, v7);
  v5->sess_id_size = v7;
  v9 = v5->flag & 8;
  v5->cipher = v1[v7 + 40];
  v10 = v7 + 41;
  v5->next_state = v9 != 0 ? 20 : 11;
  if ( v2 >= v10 )
    v5->dc->bm_proc_index = v10 + 1;
  else
    v4 = -260;
  return v4;
}

// File Line: 345
// RVA: 0xEF0A0C
signed __int64 __fastcall send_client_key_xchg(_SSL *ssl)
{
  char *v1; // rdi
  _SSL *v2; // rsi
  int v3; // ebx
  char in_data[2]; // [rsp+30h] [rbp-48h]
  char rand_data; // [rsp+32h] [rbp-46h]

  v1 = ssl->bm_data;
  v2 = ssl;
  *(_WORD *)v1 = 16;
  *(_WORD *)in_data = 259;
  get_random(46, &rand_data);
  WaitForSingleObject(v2->ssl_ctx->mutex, 0xFFFFFFFF);
  v3 = RSA_encrypt(v2->x509_ctx->rsa_ctx, in_data, 0x30u, v1 + 6, 0);
  ReleaseMutex(v2->ssl_ctx->mutex);
  v1[5] = v3;
  v1[2] = (unsigned __int16)(v3 + 2) >> 8;
  v1[3] = v3 + 2;
  v1[4] = BYTE1(v3);
  generate_master_secret(v2, in_data);
  return send_packet(v2, 22, 0i64, v3 + 6);
}

// File Line: 396
// RVA: 0xEF0920
signed __int64 __fastcall send_cert_verify(_SSL *ssl)
{
  char *v1; // rdi
  RSA_CTX *v2; // rbp
  _SSL *v3; // rsi
  int v4; // ebx
  char v6; // ah
  int v7; // ebx
  char in_data; // [rsp+30h] [rbp-38h]

  v1 = ssl->bm_data;
  v2 = ssl->ssl_ctx->rsa_ctx;
  v3 = ssl;
  *(_WORD *)v1 = 15;
  v4 = 0;
  finished_digest(ssl, 0i64, &in_data);
  if ( v2 )
  {
    WaitForSingleObject(v3->ssl_ctx->mutex, 0xFFFFFFFF);
    v4 = RSA_encrypt(v2, &in_data, 0x24u, v1 + 6, 1);
    ReleaseMutex(v3->ssl_ctx->mutex);
    if ( !v4 )
      return 4294967027i64;
  }
  v6 = BYTE1(v4);
  v1[5] = v4;
  v7 = v4 + 2;
  v1[4] = v6;
  v1[3] = v7;
  v1[2] = BYTE1(v7);
  return send_packet(v3, 22, 0i64, v7 + 4);
}

