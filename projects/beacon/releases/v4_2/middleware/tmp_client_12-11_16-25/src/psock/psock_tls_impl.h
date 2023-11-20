// File Line: 19
// RVA: 0xEED198
char __fastcall OSuite::psock::match_host(const char *pattern, const char *hostname)
{
  const char *v2; // r15
  const char *v3; // r14
  const char *v4; // r13
  const char *v5; // r12
  const char *v6; // rbx
  char v7; // si
  const char *v8; // rdi
  int v9; // ebp
  int v10; // ebp

  v2 = hostname;
  v3 = pattern;
  v4 = pattern - 1;
  v5 = hostname - 1;
  v6 = &pattern[strlen(pattern) - 1];
  v7 = 1;
  v8 = &v2[strlen(v2) - 1];
  while ( v6 >= v3 && v8 >= v2 )
  {
    v9 = tolower_0(*v6);
    if ( v9 == 42 )
    {
      if ( v6 <= v3 )
        v10 = 46;
      else
        v10 = tolower_0(*(v6 - 1));
      while ( tolower_0(*v8) != v10 )
      {
        if ( --v8 < v2 )
          goto LABEL_11;
      }
      --v6;
      --v8;
LABEL_11:
      --v6;
    }
    else
    {
      if ( v9 != tolower_0(*v8) )
        return 0;
      --v6;
      --v8;
    }
  }
  if ( v6 > v4 || v8 > v5 )
    v7 = 0;
  return v7;
}

// File Line: 57
// RVA: 0xEEE474
bool __fastcall OSuite::psock::tls_matchcerthost(OSuite::psock::psock_private *socket, const char *hostname)
{
  const char *v2; // rsi
  OSuite::psock::psock_private *v3; // rbx
  const char *v4; // rax
  int v5; // edi
  const char *v6; // rax

  v2 = hostname;
  v3 = socket;
  if ( socket->tls.secure )
  {
    v4 = ssl_get_cert_subject_alt_dnsname(socket->tls.ssl, 0);
    v5 = 1;
    while ( v4 )
    {
      if ( OSuite::psock::match_host(v4, v2) )
        goto LABEL_9;
      v4 = ssl_get_cert_subject_alt_dnsname(v3->tls.ssl, v5++);
    }
    v6 = ssl_get_cert_dn(v3->tls.ssl, 0);
    if ( v6 )
      LOBYTE(v6) = OSuite::psock::match_host(v6, v2);
  }
  else
  {
LABEL_9:
    LOBYTE(v6) = 1;
  }
  return (char)v6;
}

// File Line: 83
// RVA: 0xEEC890
bool __fastcall OSuite::psock::connect(OSuite::psock::psock_private *socket, OSuite::psock::ipv4addr_t *addr, int port)
{
  OSuite::psock::psock_private *v3; // rdi
  bool v5; // zf
  _SSL *v6; // rax
  int v7; // ecx
  OSuite::psock::err_t v8; // eax
  int r; // [rsp+30h] [rbp-18h]

  v3 = socket;
  if ( !OSuite::psock::proxy::connect(socket, addr, port) )
    return 0;
  if ( !v3->tls.secure )
    return 1;
  r = 0;
  v5 = v3->tls.ssl == 0i64;
  if ( !v3->tls.ssl )
  {
    v6 = ssl_client_new(OSuite::psock::g_SSLContext, v3->socket, 0i64, 0, &r);
    v7 = r;
    v3->tls.ssl = v6;
    v5 = v6 == 0i64;
    if ( !v6 )
    {
      v8 = OSuite::psock::map_axtls_error(v7);
      v5 = v3->tls.ssl == 0i64;
      v3->lasterror = v8;
    }
  }
  return !v5;
}

// File Line: 103
// RVA: 0xEEE5EC
__int64 __fastcall OSuite::psock::waitread(OSuite::psock::psock_private *socket, int timeout)
{
  OSuite::psock::psock_private *v2; // rbx
  bool v4; // zf
  unsigned __int64 v5; // rcx
  OSuite::psock::err_t v6; // edi
  char optval[4]; // [rsp+30h] [rbp-448h]
  int optlen; // [rsp+34h] [rbp-444h]
  OSuite::psock::psockset_t in; // [rsp+40h] [rbp-438h]
  OSuite::psock::psockset_t out; // [rsp+250h] [rbp-228h]

  v2 = socket;
  if ( socket->tls.secure && socket->tls.ssl && socket->tls.bufferused != socket->tls.bufferindex )
    return 0i64;
  out.count = 0;
  in.array[0].userdata = 0i64;
  v4 = socket->async == 0;
  in.array[0].socket = socket;
  in.count = 1;
  if ( v4 )
  {
    v5 = socket->socket;
    *(_DWORD *)optval = 0;
    optlen = 4;
    getsockopt(v5, 0xFFFF, 4102, optval, &optlen);
    timeout = *(_DWORD *)optval;
  }
  v6 = (unsigned int)OSuite::psock::selectread(&out, &in, timeout);
  v2->lasterror = v6;
  if ( OSuite::psock::g_ErrorCallback )
    OSuite::psock::g_ErrorCallback(v6);
  return (unsigned int)v6;
}

// File Line: 151
// RVA: 0xEEDE78
signed __int64 __fastcall OSuite::psock::recv(OSuite::psock::psock_private *socket, void *buf, unsigned __int64 len)
{
  unsigned __int64 v3; // rsi
  char *v4; // r14
  OSuite::psock::psock_private *v5; // rbx
  __int64 v7; // rbp
  unsigned __int64 v8; // rcx
  size_t v9; // rdi
  int v10; // eax
  size_t v11; // rdi
  char *v12; // rax
  OSuite::psock::err_t v13; // eax
  char *in_data; // [rsp+20h] [rbp-38h]

  v3 = len;
  v4 = (char *)buf;
  v5 = socket;
  if ( !socket->tls.secure )
    return OSuite::psock::proxy::recv(socket, buf, len);
  if ( !socket->tls.ssl )
  {
    socket->lasterror = 9;
    if ( OSuite::psock::g_ErrorCallback )
      OSuite::psock::g_ErrorCallback(ERR_TLS_CONNECT);
    return 0i64;
  }
  v7 = 0i64;
  if ( !len )
    return v7;
  while ( 1 )
  {
    v8 = v5->tls.bufferindex;
    v9 = v5->tls.bufferused - v8;
    if ( v5->tls.bufferused == v8 )
      break;
    if ( v9 > v3 )
      v9 = v3;
    memmove(v4, &v5->tls.buffer[v8], v9);
    v5->tls.bufferindex += v9;
    v4 += v9;
    v3 -= v9;
    v7 += v9;
LABEL_15:
    if ( !v3 )
      return v7;
  }
  v10 = ssl_read(v5->tls.ssl, &in_data);
  if ( v10 > 0 )
  {
    v11 = v10;
    if ( v10 > v5->tls.buffersize )
    {
      v12 = (char *)OSuite::ZObject::m_allocator->vfptr->realloc(
                      OSuite::ZObject::m_allocator,
                      v5->tls.buffer,
                      v10,
                      0i64);
      v5->tls.buffersize = v11;
      v5->tls.buffer = v12;
    }
    memmove(v5->tls.buffer, in_data, v11);
    v5->tls.bufferindex = 0i64;
    v5->tls.bufferused = v11;
    goto LABEL_15;
  }
  if ( v10 < 0 )
  {
    v13 = (unsigned int)OSuite::psock::map_axtls_error(v10);
    v5->lasterror = v13;
    if ( OSuite::psock::g_ErrorCallback )
      OSuite::psock::g_ErrorCallback(v13);
  }
  return v7;
}

// File Line: 211
// RVA: 0xEEE2FC
signed __int64 __fastcall OSuite::psock::send(OSuite::psock::psock_private *socket, const void *buf, unsigned __int64 len)
{
  OSuite::psock::psock_private *v3; // rbx
  _SSL *v4; // rcx
  signed __int64 result; // rax
  OSuite::psock::err_t v6; // eax

  v3 = socket;
  if ( !socket->tls.secure )
    return OSuite::psock::proxy::send(socket, buf, len);
  v4 = socket->tls.ssl;
  if ( !v4 )
  {
    v3->lasterror = 9;
    if ( OSuite::psock::g_ErrorCallback )
      OSuite::psock::g_ErrorCallback(ERR_TLS_CONNECT);
    return 0i64;
  }
  LODWORD(result) = ssl_write(v4, (const char *)buf, len);
  if ( (signed int)result < 0 )
  {
    v6 = (unsigned int)OSuite::psock::map_axtls_error(result);
    v3->lasterror = v6;
    if ( OSuite::psock::g_ErrorCallback )
      OSuite::psock::g_ErrorCallback(v6);
    return 0i64;
  }
  return (signed int)result;
}

