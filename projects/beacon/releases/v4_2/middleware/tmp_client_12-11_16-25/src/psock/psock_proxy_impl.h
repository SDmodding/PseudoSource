// File Line: 21
// RVA: 0xEECFE0
__int64 __fastcall OSuite::psock::getproxytype()
{
  return (unsigned int)g_eProxyType;
}

// File Line: 26
// RVA: 0xEECFD0
char *__fastcall OSuite::psock::getproxyhost()
{
  return g_pszProxyHost;
}

// File Line: 31
// RVA: 0xEECFD8
__int64 __fastcall OSuite::psock::getproxyport()
{
  return (unsigned int)g_nProxyPort;
}

// File Line: 44
// RVA: 0xEEC510
void __fastcall OSuite::psock::SetProxyInfo(
        const char *host,
        unsigned __int64 hostlen,
        int port,
        OSuite::psock::proxy_t type)
{
  const char *v8; // rdx

  g_pszProxyHost = (char *)OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, hostlen + 1, 0i64);
  strncpy_s(g_pszProxyHost, hostlen + 1, host, hostlen);
  v8 = g_pszProxyHost;
  g_nProxyPort = port;
  g_eProxyType = type;
  g_pszProxyHost[hostlen] = 0;
  OSuite::psock::getaddrbyname(&g_ProxyIP, v8);
}

// File Line: 77
// RVA: 0xEEC318
void OSuite::psock::ProbeHttpProxy()
{
  unsigned __int64 v0; // rax
  int v1; // esi
  char v2; // di
  OSuite::psock::proxy_t v3; // eax
  OSuite::psock::psock_private *newSocket; // [rsp+40h] [rbp-B8h] BYREF
  OSuite::psock::ipv4addr_t result; // [rsp+48h] [rbp-B0h] BYREF
  char buf[8]; // [rsp+58h] [rbp-A0h] BYREF
  char string[248]; // [rsp+60h] [rbp-98h] BYREF

  sprintf_s(string, 0x100ui64, http_connect_string);
  if ( !OSuite::psock::getaddrbyname(&result, g_pszProxyHost) )
    return;
  newSocket = 0i64;
  OSuite::psock::create(&newSocket, PROT_TCP, 0, 0);
  if ( !newSocket )
    return;
  if ( !OSuite::psock::platform::connect(newSocket, &result, g_nProxyPort) )
    goto LABEL_19;
  v0 = strlen(string);
  if ( !OSuite::psock::send(newSocket, string, v0) )
    goto LABEL_19;
  v1 = 0;
  v2 = 0;
  if ( OSuite::psock::recv(newSocket, buf, 1ui64) != 1 )
    goto LABEL_19;
  while ( v2 && isdigit(buf[0]) )
  {
    v1 = buf[0] + 2 * (5 * v1 - 24);
LABEL_15:
    if ( OSuite::psock::recv(newSocket, buf, 1ui64) != 1 )
      goto LABEL_16;
  }
  if ( isspace(buf[0]) && !v2 )
  {
    v2 = 1;
    goto LABEL_15;
  }
  if ( isdigit(buf[0]) || !v1 || !v2 )
    goto LABEL_15;
LABEL_16:
  v3 = g_eProxyType;
  if ( v1 == 200 )
    v3 = PROXY_HTTP_CONNECT;
  g_eProxyType = v3;
LABEL_19:
  OSuite::psock::close(newSocket);
}

// File Line: 124
// RVA: 0xEED8B0
char __fastcall OSuite::psock::proxy_socks5connect_statemachine(
        OSuite::psock::psock_private *socket,
        OSuite::psock::ipv4addr_t *host,
        __int16 port,
        int udpassocport)
{
  OSuite::psock::proxystate_t state; // ecx
  __int32 v7; // ecx
  __int32 v8; // ecx
  __int32 v9; // ecx
  int substate; // edx
  char v12; // ah
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  __int32 v16; // ecx
  __int32 v17; // ecx
  __int32 v18; // ecx
  int v19; // ecx
  unsigned __int8 v21; // cl
  __int16 v22; // [rsp+20h] [rbp-50h]
  char v23; // [rsp+22h] [rbp-4Eh]
  OSuite::psock::ipv4addr_t addr; // [rsp+28h] [rbp-48h] BYREF
  char buf[8]; // [rsp+38h] [rbp-38h] BYREF
  int Src; // [rsp+40h] [rbp-30h] BYREF
  int v27; // [rsp+44h] [rbp-2Ch]
  char v28; // [rsp+48h] [rbp-28h]
  char v29; // [rsp+49h] [rbp-27h]
  OSuite::psock::ipv4addr_t Dst; // [rsp+50h] [rbp-20h] BYREF

  state = socket->proxy.state;
  Dst = *host;
  if ( state <= PROXYSTATE_SOCKS_RECV_REPLY_ADDRTYPE )
  {
    if ( state == PROXYSTATE_SOCKS_RECV_REPLY_ADDRTYPE )
    {
      if ( !OSuite::psock::recv(socket, buf, 1ui64) )
        return 0;
      v13 = buf[0];
      socket->proxy.substate = 0;
      v14 = v13 - 1;
      if ( v14 )
      {
        v15 = v14 - 2;
        if ( v15 )
        {
          if ( v15 != 1 )
            goto LABEL_12;
          socket->proxy.state = PROXYSTATE_SOCKS_RECV_REPLY_IPV6;
        }
        else
        {
          socket->proxy.state = PROXYSTATE_SOCKS_RECV_REPLY_DOMAIN_1;
        }
      }
      else
      {
        socket->proxy.state = PROXYSTATE_SOCKS_RECV_REPLY_IPV4;
      }
    }
    else if ( state )
    {
      v7 = state - 8;
      if ( v7 )
      {
        v8 = v7 - 1;
        if ( v8 )
        {
          v9 = v8 - 1;
          if ( v9 )
          {
            if ( v9 == 1 )
            {
              v23 = 0;
              v22 = 5;
              if ( OSuite::psock::recv(socket, buf, 1ui64) )
              {
                substate = socket->proxy.substate;
                if ( *((_BYTE *)&v22 + substate) == buf[0] )
                {
                  socket->proxy.substate = substate + 1;
                  if ( substate == 2 )
                    socket->proxy.state = PROXYSTATE_SOCKS_RECV_REPLY_ADDRTYPE;
                  goto LABEL_26;
                }
                goto LABEL_12;
              }
              return 0;
            }
            goto LABEL_12;
          }
          if ( udpassocport )
          {
            if ( !OSuite::psock::getsockname(socket, &addr, 0i64) )
              goto LABEL_12;
            Src = 16777989;
            v29 = udpassocport;
            v27 = *(_DWORD *)addr.b;
            v12 = BYTE1(udpassocport);
          }
          else
          {
            Src = 16777477;
            v29 = port;
            v27 = *(_DWORD *)Dst.b;
            v12 = HIBYTE(port);
          }
          v28 = v12;
          memmove(&Dst, &Src, 0xAui64);
          OSuite::psock::send(socket, &Dst, 0xAui64);
          socket->proxy.substate = 0;
          socket->proxy.state = PROXYSTATE_SOCKS_RECV_REPLY_1;
        }
        else
        {
          if ( !OSuite::psock::recv(socket, buf, 1ui64) )
            return 0;
          if ( buf[0] )
          {
LABEL_12:
            socket->lasterror = ERR_FAILED;
            if ( OSuite::psock::g_ErrorCallback )
              OSuite::psock::g_ErrorCallback(ERR_FAILED);
            return 0;
          }
          socket->proxy.state = PROXYSTATE_SOCKS_SEND_CONNECT;
        }
      }
      else
      {
        if ( !OSuite::psock::recv(socket, buf, 1ui64) )
          return 0;
        if ( buf[0] != 5 )
          goto LABEL_12;
        socket->proxy.state = PROXYSTATE_RECV_METHOD;
      }
    }
    else
    {
      if ( !OSuite::psock::platform::connect(socket, &g_ProxyIP, g_nProxyPort) )
        return 0;
      OSuite::psock::send(socket, versions, 3ui64);
      socket->proxy.state = PROXYSTATE_RECV_METHOD_VER;
    }
LABEL_26:
    socket->lasterror = ERR_AGAIN;
    if ( OSuite::psock::g_ErrorCallback )
      OSuite::psock::g_ErrorCallback(ERR_AGAIN);
    return 1;
  }
  v16 = state - 13;
  if ( !v16 )
  {
    if ( !OSuite::psock::recv(socket, buf, 1ui64) )
      return 0;
    if ( udpassocport )
      socket->proxy.udpaddr.b[socket->proxy.substate] = buf[0];
    if ( ++socket->proxy.substate != 4 )
      goto LABEL_26;
    if ( !udpassocport )
    {
      socket->proxy.udpaddr.type = ADDR_IPV4;
      socket->proxy.udpport = 0;
    }
LABEL_62:
    socket->proxy.substate = 0;
    goto LABEL_63;
  }
  v17 = v16 - 1;
  if ( !v17 )
  {
    if ( !OSuite::psock::recv(socket, buf, 1ui64) )
      return 0;
    if ( ++socket->proxy.substate != 16 )
      goto LABEL_26;
    goto LABEL_62;
  }
  v18 = v17 - 1;
  if ( !v18 )
  {
    if ( !OSuite::psock::recv(socket, buf, 1ui64) )
      return 0;
    v21 = buf[0];
    socket->proxy.substate = buf[0];
    socket->proxy.state = 17 - (v21 != 0);
    goto LABEL_26;
  }
  v19 = v18 - 1;
  if ( !v19 )
  {
    if ( !OSuite::psock::recv(socket, buf, 1ui64) )
      return 0;
    if ( socket->proxy.substate-- != 1 )
      goto LABEL_26;
LABEL_63:
    socket->proxy.state = PROXYSTATE_SOCKS_RECV_REPLY_PORT;
    goto LABEL_26;
  }
  if ( v19 != 1 )
    goto LABEL_12;
  if ( !OSuite::psock::recv(socket, buf, 1ui64) )
    return 0;
  if ( udpassocport )
    socket->proxy.udpport = (unsigned __int8)buf[0] + (socket->proxy.udpport << 8);
  if ( ++socket->proxy.substate != 2 )
    goto LABEL_26;
  socket->proxy.substate = 0;
  socket->lasterror = ERR_OK;
  socket->proxy.state = PROXYSTATE_CONNECTED;
  return 1;
}

// File Line: 375
// RVA: 0xEED444
bool __fastcall OSuite::psock::proxy_httpconnect_statemachine(
        OSuite::psock::psock_private *socket,
        OSuite::psock::ipv4addr_t *host,
        int port)
{
  OSuite::psock::proxystate_t state; // ecx
  __int32 v7; // ecx
  __int32 v8; // ecx
  __int32 v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  void (__fastcall *v13)(OSuite::psock::err_t); // rax
  __int64 v14; // rcx
  bool v16; // zf
  int v17; // ecx
  OSuite::psock::proxystate_t v18; // eax
  int substate; // eax
  int v20; // edx
  _SSL *v21; // rax
  OSuite::psock::err_t v22; // eax
  unsigned __int64 v23; // rax
  int *err_code; // [rsp+20h] [rbp-E0h]
  int *err_codea; // [rsp+20h] [rbp-E0h]
  char buf[4]; // [rsp+40h] [rbp-C0h] BYREF
  int r; // [rsp+44h] [rbp-BCh] BYREF
  char _Dest[20]; // [rsp+48h] [rbp-B8h] BYREF
  char string[256]; // [rsp+60h] [rbp-A0h] BYREF

  state = socket->proxy.state;
  if ( state == PROXYSTATE_INITIAL )
  {
    if ( !OSuite::psock::platform::connect(socket, &g_ProxyIP, g_nProxyPort) )
      return 0;
    socket->proxy.state = PROXYSTATE_SEND;
    goto LABEL_60;
  }
  v7 = state - 1;
  if ( v7 )
  {
    v8 = v7 - 1;
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( v9 )
      {
        v10 = v9 - 1;
        if ( v10 )
        {
          v11 = v10 - 1;
          if ( v11 )
          {
            v12 = v11 - 1;
            if ( v12 )
            {
              if ( v12 != 1 )
              {
LABEL_9:
                socket->lasterror = ERR_FAILED;
                v13 = OSuite::psock::g_ErrorCallback;
                if ( !OSuite::psock::g_ErrorCallback )
                  return 0;
                v14 = 1i64;
LABEL_11:
                v13((OSuite::psock::err_t)v14);
                return 0;
              }
              if ( OSuite::psock::recv(socket, buf, 1ui64) == 1 )
              {
                if ( buf[0] == 10 )
                {
                  socket->lasterror = ERR_OK;
                  socket->proxy.state = PROXYSTATE_CONNECTED;
                  return 1;
                }
                socket->proxy.state = PROXYSTATE_CRLF_1;
LABEL_60:
                socket->lasterror = ERR_AGAIN;
LABEL_61:
                if ( OSuite::psock::g_ErrorCallback )
                  OSuite::psock::g_ErrorCallback(ERR_AGAIN);
                return 1;
              }
              return socket->lasterror == ERR_AGAIN;
            }
            if ( OSuite::psock::recv(socket, buf, 1ui64) != 1 )
              return socket->lasterror == ERR_AGAIN;
            v16 = buf[0] == 13;
            v17 = 7;
          }
          else
          {
            if ( OSuite::psock::recv(socket, buf, 1ui64) != 1 )
              return socket->lasterror == ERR_AGAIN;
            v16 = buf[0] == 10;
            v17 = 6;
          }
          v18 = PROXYSTATE_CRLF_1;
          if ( v16 )
            v18 = v17;
LABEL_41:
          socket->proxy.state = v18;
          goto LABEL_60;
        }
        while ( OSuite::psock::recv(socket, buf, 1ui64) == 1 )
        {
          v16 = buf[0] == 13;
          socket->lasterror = ERR_AGAIN;
          if ( v16 )
          {
            socket->proxy.state = PROXYSTATE_CRLF_2;
            goto LABEL_61;
          }
          if ( OSuite::psock::g_ErrorCallback )
            OSuite::psock::g_ErrorCallback(ERR_AGAIN);
        }
      }
      else
      {
        while ( OSuite::psock::recv(socket, buf, 1ui64) == 1 )
        {
          if ( !isdigit(buf[0]) )
          {
            if ( socket->proxy.substate != 200 )
              goto LABEL_9;
            v18 = PROXYSTATE_CRLF_1;
            goto LABEL_41;
          }
          substate = socket->proxy.substate;
          socket->lasterror = ERR_AGAIN;
          socket->proxy.substate = buf[0] + 2 * (5 * substate - 24);
          if ( OSuite::psock::g_ErrorCallback )
            OSuite::psock::g_ErrorCallback(ERR_AGAIN);
        }
      }
    }
    else
    {
      while ( OSuite::psock::recv(socket, buf, 1ui64) == 1 )
      {
        if ( isspace(buf[0]) )
        {
          *(_QWORD *)&socket->proxy.state = 3i64;
          return 1;
        }
        socket->lasterror = ERR_AGAIN;
        if ( OSuite::psock::g_ErrorCallback )
          OSuite::psock::g_ErrorCallback(ERR_AGAIN);
      }
    }
    return socket->lasterror == ERR_AGAIN;
  }
  v20 = socket->socket;
  r = 0;
  v21 = ssl_client_new(OSuite::psock::g_SSLContext, v20, 0i64, 0, &r);
  socket->tls.ssl = v21;
  if ( !v21 )
  {
    v22 = (unsigned int)OSuite::psock::map_axtls_error(r);
    socket->lasterror = v22;
    if ( OSuite::psock::g_ErrorCallback )
      OSuite::psock::g_ErrorCallback(v22);
    return 0;
  }
  LODWORD(err_code) = (unsigned __int8)host->b[2];
  sprintf_s<20>(
    (char (*)[20])_Dest,
    "%d.%d.%d.%d",
    (unsigned __int8)host->b[0],
    (unsigned __int8)host->b[1],
    err_code,
    (unsigned __int8)host->b[3]);
  LODWORD(err_codea) = port;
  sprintf_s(string, 0x100ui64, http_connect_string, _Dest, err_codea, _Dest, port);
  v23 = strlen(string);
  if ( !OSuite::psock::send(socket, string, v23) )
  {
    v14 = 9i64;
    socket->lasterror = ERR_TLS_CONNECT;
    v13 = OSuite::psock::g_ErrorCallback;
    if ( !OSuite::psock::g_ErrorCallback )
      return 0;
    goto LABEL_11;
  }
  socket->proxy.state = PROXYSTATE_RECV_1;
  socket->lasterror = ERR_AGAIN;
  if ( OSuite::psock::g_ErrorCallback )
    OSuite::psock::g_ErrorCallback(ERR_AGAIN);
  return 1;
}

// File Line: 558
// RVA: 0xEED80C
bool __fastcall OSuite::psock::proxy_socks5connect(
        OSuite::psock::psock_private *socket,
        OSuite::psock::ipv4addr_t *addr,
        int port,
        int udpassocport)
{
  int v5; // r14d
  int v6; // r15d
  OSuite::psock::psock_private *v7; // rdi
  OSuite::psock::ipv4addr_t v9; // [rsp+20h] [rbp-10h] BYREF

  v9 = *addr;
  v5 = udpassocport;
  v6 = port;
  v7 = socket;
  if ( socket->async )
  {
    if ( OSuite::psock::proxy_socks5connect_statemachine(socket, &v9, port, udpassocport) )
      return v7->proxy.state == PROXYSTATE_CONNECTED;
  }
  else
  {
    while ( OSuite::psock::proxy_socks5connect_statemachine(socket, &v9, port, udpassocport) )
    {
      if ( v7->proxy.state == PROXYSTATE_CONNECTED )
        return 1;
      udpassocport = v5;
      port = v6;
      v9 = *addr;
      socket = v7;
    }
  }
  return 0;
}

// File Line: 586
// RVA: 0xEEC6F8
char __fastcall OSuite::psock::proxy::connect(
        OSuite::psock::psock_private *socket,
        OSuite::psock::ipv4addr_t *addr,
        int port)
{
  int v3; // r14d
  OSuite::psock::ipv4addr_t *v4; // rsi
  OSuite::psock::psock_private *v5; // rbx
  OSuite::psock::psock_private **p_socks5; // r15
  OSuite::psock::psock_private *socks5; // rax
  int v9; // eax
  void (__fastcall *v10)(OSuite::psock::err_t); // rax
  __int64 v11; // rcx
  OSuite::psock::ipv4addr_t v12; // [rsp+20h] [rbp-10h] BYREF
  int porta; // [rsp+68h] [rbp+38h] BYREF

  v3 = port;
  v4 = addr;
  v5 = socket;
  if ( g_eProxyType == PROXY_HTTP_CONNECT )
  {
    if ( socket->protocol == PROT_TCP )
    {
      v12 = *addr;
      if ( socket->async )
      {
        if ( OSuite::psock::proxy_httpconnect_statemachine(socket, &v12, port) )
          return v5->proxy.state == PROXYSTATE_CONNECTED;
      }
      else
      {
        while ( OSuite::psock::proxy_httpconnect_statemachine(socket, &v12, port) )
        {
          if ( v5->proxy.state == PROXYSTATE_CONNECTED )
            return 1;
          port = v3;
          v12 = *v4;
          socket = v5;
        }
      }
      return 0;
    }
    return OSuite::psock::platform::connect(socket, addr, port);
  }
  if ( g_eProxyType != PROXY_SOCKS5 )
    return OSuite::psock::platform::connect(socket, addr, port);
  if ( socket->protocol == PROT_UDP )
  {
    p_socks5 = &socket->proxy.socks5;
    socks5 = socket->proxy.socks5;
    if ( !socks5 )
    {
      OSuite::psock::create(&socket->proxy.socks5, PROT_TCP, socket->async, 0);
      *(_DWORD *)v5->proxy.udpaddr.b = *(_DWORD *)v4->b;
      v5->proxy.udpaddr.type = v4->type;
      v9 = *(_DWORD *)&v4->xlspindex;
      v5->proxy.udpport = v3;
      *(_DWORD *)&v5->proxy.udpaddr.xlspindex = v9;
      socks5 = *p_socks5;
      if ( !*p_socks5 )
        goto LABEL_15;
    }
    if ( socks5->proxy.state != PROXYSTATE_CONNECTED )
    {
      if ( OSuite::psock::getsockname(socks5, 0i64, &porta) )
      {
        if ( !OSuite::psock::proxy_socks5connect(*p_socks5, &g_ProxyIP, g_nProxyPort, porta) )
          return 0;
        v11 = 3i64;
        v5->lasterror = ERR_AGAIN;
        v10 = OSuite::psock::g_ErrorCallback;
        if ( !OSuite::psock::g_ErrorCallback )
          return 0;
        goto LABEL_17;
      }
LABEL_15:
      v5->lasterror = ERR_FAILED;
      v10 = OSuite::psock::g_ErrorCallback;
      if ( !OSuite::psock::g_ErrorCallback )
        return 0;
      v11 = 1i64;
LABEL_17:
      v10((OSuite::psock::err_t)v11);
      return 0;
    }
    port = socks5->proxy.udpport;
    addr = &socks5->proxy.udpaddr;
    socket = v5;
    return OSuite::psock::platform::connect(socket, addr, port);
  }
  return OSuite::psock::proxy_socks5connect(socket, addr, port, 0);
}

// File Line: 654
// RVA: 0xEEDD9C
__int64 __fastcall OSuite::psock::proxy::recv(OSuite::psock::psock_private *socket, char *buf, unsigned __int64 len)
{
  unsigned __int64 v5; // rbx
  char *v6; // rax
  char *v7; // rsi
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rbx

  if ( !socket->proxy.socks5 )
    return OSuite::psock::platform::recv(socket, buf, len);
  v5 = len + 10;
  v6 = (char *)OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, len + 10, 0i64);
  v7 = v6;
  if ( v6 )
  {
    v9 = OSuite::psock::platform::recv(socket, v6, v5);
    v10 = v9;
    if ( v9 < 0xA )
    {
      if ( v9 )
      {
        socket->lasterror = ERR_MESSAGE_TOO_BIG;
        if ( OSuite::psock::g_ErrorCallback )
          OSuite::psock::g_ErrorCallback(ERR_MESSAGE_TOO_BIG);
        v10 = 0i64;
      }
    }
    else if ( !v7[2] )
    {
      v10 = v9 - 10;
      memmove(buf, v7 + 10, v9 - 10);
    }
    OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, v7);
    return v10;
  }
  else
  {
    socket->lasterror = ERR_MESSAGE_TOO_BIG;
    if ( OSuite::psock::g_ErrorCallback )
      OSuite::psock::g_ErrorCallback(ERR_MESSAGE_TOO_BIG);
    return 0i64;
  }
}

// File Line: 691
// RVA: 0xEEE204
__int64 __fastcall OSuite::psock::proxy::send(
        OSuite::psock::psock_private *socket,
        const char *buf,
        unsigned __int64 len)
{
  __int64 v6; // rax
  __int64 v7; // rdi
  unsigned __int64 v9; // rbx

  if ( !socket->proxy.socks5 )
    return OSuite::psock::platform::send(socket, buf, len);
  v6 = OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, len + 10, 0i64);
  v7 = v6;
  if ( v6 )
  {
    memmove((void *)(v6 + 10), buf, len);
    *(_DWORD *)v7 = 0x1000000;
    *(_BYTE *)(v7 + 4) = socket->proxy.udpaddr.b[0];
    *(_BYTE *)(v7 + 5) = socket->proxy.udpaddr.b[1];
    *(_BYTE *)(v7 + 6) = socket->proxy.udpaddr.b[2];
    *(_BYTE *)(v7 + 7) = socket->proxy.udpaddr.b[3];
    *(_BYTE *)(v7 + 8) = BYTE1(socket->proxy.udpport);
    *(_BYTE *)(v7 + 9) = socket->proxy.udpport;
    v9 = OSuite::psock::platform::send(socket, (const char *)v7, len + 10);
    OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, (void *)v7);
    if ( v9 < 0xA )
      return v9 & -(__int64)(v9 == 0);
    else
      return v9 - 10;
  }
  else
  {
    socket->lasterror = ERR_MESSAGE_TOO_BIG;
    if ( OSuite::psock::g_ErrorCallback )
      OSuite::psock::g_ErrorCallback(ERR_MESSAGE_TOO_BIG);
    return 0i64;
  }
}

