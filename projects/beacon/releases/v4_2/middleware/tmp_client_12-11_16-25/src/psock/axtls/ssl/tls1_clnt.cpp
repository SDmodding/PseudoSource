// File Line: 61
// RVA: 0xEF0AF4
_SSL *__fastcall ssl_client_new(
        _SSL_CTX *ssl_ctx,
        int client_fd,
        const char *session_id,
        unsigned __int8 sess_id_size,
        int *err_code)
{
  _SSL *v8; // rax
  _SSL *v9; // rbx
  int v11; // edi

  v8 = ssl_new(ssl_ctx, client_fd);
  v9 = v8;
  if ( !v8 )
    return 0i64;
  if ( session_id && ssl_ctx->num_sessions )
  {
    if ( sess_id_size > 0x20u )
    {
      ssl_free(v8);
      return 0i64;
    }
    memmove(v8->session_id, session_id, sess_id_size);
    v9->flag |= 8u;
    v9->sess_id_size = sess_id_size;
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
  int v6; // edx
  int v7; // edx
  int v8; // edx
  int v9; // edx
  bool v10; // zf
  DISPOSABLE_CTX *dc; // rdx
  char *v13; // rax
  int v14; // ecx
  int v15; // ecx

  v4 = 0;
  if ( !handshake_type )
  {
    disposable_new(ssl);
    return (unsigned int)do_client_connect(ssl);
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
          disposable_free(ssl);
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
        v4 = send_client_key_xchg(ssl);
        if ( v4 )
          return v4;
        send_cert_verify(ssl);
      }
      v4 = send_change_cipher_spec(ssl);
      if ( v4 )
        return v4;
      return (unsigned int)send_finished(ssl);
    }
    dc = ssl->dc;
    v13 = &ssl->bm_data[dc->bm_proc_index];
    v14 = (unsigned __int8)v13[2];
    LODWORD(v13) = (unsigned __int8)v13[3];
    ssl->flag |= 0x20u;
    ssl->next_state = 14;
    v15 = (_DWORD)v13 + 16 * v14;
    LODWORD(v13) = ssl->bm_index;
    dc->bm_proc_index += v15;
    if ( (int)v13 < v15 )
      return (unsigned int)-260;
  }
  else
  {
    v4 = process_certificate(ssl, &ssl->x509_ctx);
    if ( v4 == -522 )
      return 0;
  }
  return v4;
}

// File Line: 165
// RVA: 0xEF04B0
__int64 __fastcall do_client_connect(_SSL *ssl)
{
  char *bm_data; // r14
  int v3; // esi
  int v4; // eax
  int v5; // r9d
  __int64 v6; // rax
  int v7; // r9d
  __int64 v8; // rdx
  __int64 v9; // rax
  int v10; // r9d
  __int64 v11; // rax
  int v12; // r9d
  __int64 v13; // rcx
  __int64 v14; // rax
  int v15; // r9d
  __int64 v16; // rax
  _x509_ctx *x509_ctx; // rcx
  int v18; // ebx

  bm_data = ssl->bm_data;
  v3 = 0;
  v4 = time64(0i64);
  *(_WORD *)bm_data = 1;
  bm_data[2] = 0;
  *((_WORD *)bm_data + 2) = 259;
  bm_data[6] = HIBYTE(v4);
  bm_data[7] = BYTE2(v4);
  bm_data[8] = BYTE1(v4);
  bm_data[9] = v4;
  get_random(0x1Cu, bm_data + 10);
  memmove(ssl->dc->client_random, bm_data + 6, 0x20ui64);
  if ( (ssl->flag & 8) != 0 )
  {
    bm_data[38] = ssl->sess_id_size;
    memmove(bm_data + 39, ssl->session_id, (unsigned __int8)ssl->sess_id_size);
    v5 = (unsigned __int8)ssl->sess_id_size + 39;
    ssl->flag &= ~8u;
  }
  else
  {
    bm_data[38] = 0;
    v5 = 39;
  }
  v6 = v5;
  v7 = v5 + 1;
  v8 = 0i64;
  bm_data[v6] = 0;
  v9 = v7;
  v10 = v7 + 1;
  bm_data[v9] = 8;
  do
  {
    v11 = v10;
    v12 = v10 + 1;
    bm_data[v11] = 0;
    v13 = v12;
    LOBYTE(v11) = ssl_prot_prefs[v8++];
    v10 = v12 + 1;
    bm_data[v13] = v11;
  }
  while ( v8 < 4 );
  v14 = v10;
  v15 = v10 + 1;
  bm_data[v14] = 1;
  v16 = v15++;
  bm_data[v16] = 0;
  bm_data[3] = v15 - 4;
  send_packet(ssl, 22, 0i64, v15);
  x509_ctx = ssl->x509_ctx;
  ssl->next_state = 2;
  ssl->bm_read_index = 0;
  ssl->hs_status = -1;
  x509_free(x509_ctx);
  v18 = 0;
  while ( ssl->hs_status )
  {
    v3 = basic_read(ssl, 0i64);
    if ( !v3 )
    {
      if ( !ssl->hs_status )
        break;
      if ( ++v18 >= 150 )
      {
        v3 = -256;
        ssl->hs_status = -2;
        break;
      }
      Sleep(0x64u);
    }
    if ( v3 < 0 )
    {
      if ( v3 != -256 && (unsigned int)send_alert(ssl, v3) )
        kill_ssl_session(ssl->ssl_ctx->ssl_sessions, ssl);
      break;
    }
  }
  ssl->hs_status = v3;
  return (unsigned int)v3;
}

// File Line: 284
// RVA: 0xEF07CC
signed __int64 __fastcall process_server_hello(_SSL *ssl)
{
  char *bm_data; // rsi
  int bm_index; // r13d
  int num_sessions; // r12d
  unsigned int v4; // ebp
  unsigned __int8 v7; // r15
  SSL_SESSION *v8; // rax
  char v9; // al

  bm_data = ssl->bm_data;
  bm_index = ssl->bm_index;
  num_sessions = ssl->ssl_ctx->num_sessions;
  v4 = 0;
  if ( (unsigned __int8)bm_data[5] + 16 * (unsigned __int8)bm_data[4] != 49 )
    return 4294967033i64;
  memmove(ssl->dc->server_random, bm_data + 6, 0x20ui64);
  v7 = bm_data[38];
  if ( num_sessions )
  {
    v8 = ssl_session_update(num_sessions, ssl->ssl_ctx->ssl_sessions, ssl, bm_data + 39);
    ssl->session = v8;
    memmove(v8->session_id, bm_data + 39, v7);
    if ( v7 < 0x20u )
      memset(&ssl->session->session_id[v7], 0, 32 - v7);
  }
  memmove(ssl->session_id, bm_data + 39, v7);
  ssl->sess_id_size = v7;
  v9 = ssl->flag & 8;
  ssl->cipher = bm_data[v7 + 40];
  ssl->next_state = v9 != 0 ? 20 : 11;
  if ( bm_index >= v7 + 41 )
    ssl->dc->bm_proc_index = v7 + 42;
  else
    return (unsigned int)-260;
  return v4;
}

// File Line: 345
// RVA: 0xEF0A0C
__int64 __fastcall send_client_key_xchg(_SSL *ssl)
{
  char *bm_data; // rdi
  int v3; // ebx
  char in_data[2]; // [rsp+30h] [rbp-48h] BYREF
  char rand_data[46]; // [rsp+32h] [rbp-46h] BYREF

  bm_data = ssl->bm_data;
  *(_WORD *)bm_data = 16;
  *(_WORD *)in_data = 259;
  get_random(0x2Eu, rand_data);
  WaitForSingleObject(ssl->ssl_ctx->mutex, 0xFFFFFFFF);
  v3 = RSA_encrypt(ssl->x509_ctx->rsa_ctx, in_data, 0x30u, bm_data + 6, 0);
  ReleaseMutex(ssl->ssl_ctx->mutex);
  bm_data[5] = v3;
  bm_data[2] = (unsigned __int16)(v3 + 2) >> 8;
  bm_data[3] = v3 + 2;
  bm_data[4] = BYTE1(v3);
  generate_master_secret(ssl, in_data);
  return send_packet(ssl, 22, 0i64, v3 + 6);
}

// File Line: 396
// RVA: 0xEF0920
__int64 __fastcall send_cert_verify(_SSL *ssl)
{
  char *bm_data; // rdi
  RSA_CTX *rsa_ctx; // rbp
  int v4; // ebx
  char v6; // ah
  int v7; // ebx
  char in_data[40]; // [rsp+30h] [rbp-38h] BYREF

  bm_data = ssl->bm_data;
  rsa_ctx = ssl->ssl_ctx->rsa_ctx;
  *(_WORD *)bm_data = 15;
  v4 = 0;
  finished_digest(ssl, 0i64, in_data);
  if ( rsa_ctx )
  {
    WaitForSingleObject(ssl->ssl_ctx->mutex, 0xFFFFFFFF);
    v4 = RSA_encrypt(rsa_ctx, in_data, 0x24u, bm_data + 6, 1);
    ReleaseMutex(ssl->ssl_ctx->mutex);
    if ( !v4 )
      return 4294967027i64;
  }
  v6 = BYTE1(v4);
  bm_data[5] = v4;
  v7 = v4 + 2;
  bm_data[4] = v6;
  bm_data[3] = v7;
  bm_data[2] = BYTE1(v7);
  return send_packet(ssl, 22, 0i64, v7 + 4);
}

