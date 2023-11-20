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
void __fastcall OSuite::psock::SetProxyInfo(const char *host, unsigned __int64 hostlen, int port, OSuite::psock::proxy_t type)
{
  const char *v4; // rdi
  int v5; // ebp
  unsigned __int64 v6; // rsi
  OSuite::psock::proxy_t v7; // er14
  const char *v8; // rdx

  v4 = host;
  v5 = port;
  v6 = hostlen;
  v7 = type;
  g_pszProxyHost = (char *)OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, hostlen + 1, 0i64);
  strncpy_s(g_pszProxyHost, v6 + 1, v4, v6);
  v8 = g_pszProxyHost;
  g_nProxyPort = v5;
  g_eProxyType = v7;
  g_pszProxyHost[v6] = 0;
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
  OSuite::psock::psock_private *newSocket; // [rsp+40h] [rbp-B8h]
  OSuite::psock::ipv4addr_t result; // [rsp+48h] [rbp-B0h]
  char buf; // [rsp+58h] [rbp-A0h]
  char string; // [rsp+60h] [rbp-98h]

  sprintf_s(&string, 0x100ui64, http_connect_string);
  if ( !OSuite::psock::getaddrbyname(&result, g_pszProxyHost) )
    return;
  newSocket = 0i64;
  OSuite::psock::create(&newSocket, PROT_TCP, 0, 0);
  if ( !newSocket )
    return;
  if ( !OSuite::psock::platform::connect(newSocket, &result, g_nProxyPort) )
    goto LABEL_19;
  v0 = strlen(&string);
  if ( !OSuite::psock::send(newSocket, &string, v0) )
    goto LABEL_19;
  v1 = 0;
  v2 = 0;
  if ( OSuite::psock::recv(newSocket, &buf, 1ui64) != 1 )
    goto LABEL_19;
  while ( v2 && isdigit(buf) )
  {
    v1 = buf + 2 * (5 * v1 - 24);
LABEL_15:
    if ( OSuite::psock::recv(newSocket, &buf, 1ui64) != 1 )
      goto LABEL_16;
  }
  if ( isspace(buf) && !v2 )
  {
    v2 = 1;
    goto LABEL_15;
  }
  if ( isdigit(buf) || !v1 || !v2 )
    goto LABEL_15;
LABEL_16:
  v3 = g_eProxyType;
  if ( v1 == 200 )
    v3 = 1;
  g_eProxyType = v3;
LABEL_19:
  OSuite::psock::close(newSocket);
}

// File Line: 124
// RVA: 0xEED8B0
char __fastcall OSuite::psock::proxy_socks5connect_statemachine(OSuite::psock::psock_private *socket, OSuite::psock::ipv4addr_t *host, int port, int udpassocport)
{
  OSuite::psock::psock_private *v4; // rbx
  OSuite::psock::proxystate_t v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // edx
  char v12; // ah
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx
  int v18; // ecx
  int v19; // ecx
  bool v20; // zf
  unsigned __int8 v21; // cl
  __int16 v22; // [rsp+20h] [rbp-50h]
  char v23; // [rsp+22h] [rbp-4Eh]
  OSuite::psock::ipv4addr_t addr; // [rsp+28h] [rbp-48h]
  unsigned __int8 buf; // [rsp+38h] [rbp-38h]
  int Src; // [rsp+40h] [rbp-30h]
  int v27; // [rsp+44h] [rbp-2Ch]
  char v28; // [rsp+48h] [rbp-28h]
  char v29; // [rsp+49h] [rbp-27h]
  __int64 Dst; // [rsp+50h] [rbp-20h]
  int v31; // [rsp+58h] [rbp-18h]

  v4 = socket;
  v5 = socket->proxy.state;
  Dst = *(_QWORD *)host->b;
  v6 = udpassocport;
  v31 = *(_DWORD *)&host->xlspindex;
  if ( (signed int)v5 <= 12 )
  {
    if ( v5 == 12 )
    {
      if ( !OSuite::psock::recv(v4, &buf, 1ui64) )
        return 0;
      v13 = (char)buf;
      v4->proxy.substate = 0;
      v14 = v13 - 1;
      if ( v14 )
      {
        v15 = v14 - 2;
        if ( v15 )
        {
          if ( v15 != 1 )
            goto LABEL_12;
          v4->proxy.state = 14;
        }
        else
        {
          v4->proxy.state = 15;
        }
      }
      else
      {
        v4->proxy.state = 13;
      }
    }
    else if ( v5 )
    {
      v7 = v5 - 8;
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
              if ( OSuite::psock::recv(v4, &buf, 1ui64) )
              {
                v10 = v4->proxy.substate;
                if ( *((_BYTE *)&v22 + v4->proxy.substate) == buf )
                {
                  v4->proxy.substate = v10 + 1;
                  if ( v10 == 2 )
                    v4->proxy.state = 12;
                  goto LABEL_27;
                }
                goto LABEL_12;
              }
              return 0;
            }
            goto LABEL_12;
          }
          if ( udpassocport )
          {
            if ( !OSuite::psock::getsockname(v4, &addr, 0i64) )
              goto LABEL_12;
            Src = 16777989;
            v29 = v6;
            v27 = *(_DWORD *)addr.b;
            v12 = BYTE1(v6);
          }
          else
          {
            Src = 16777477;
            v29 = port;
            v27 = Dst;
            v12 = BYTE1(port);
          }
          v28 = v12;
          memmove(&Dst, &Src, 0xAui64);
          OSuite::psock::send(v4, &Dst, 0xAui64);
          v4->proxy.substate = 0;
          v4->proxy.state = 11;
        }
        else
        {
          if ( !OSuite::psock::recv(v4, &buf, 1ui64) )
            return 0;
          if ( buf )
          {
LABEL_12:
            v4->lasterror = 1;
            if ( OSuite::psock::g_ErrorCallback )
              OSuite::psock::g_ErrorCallback(ERR_FAILED);
            return 0;
          }
          v4->proxy.state = 10;
        }
      }
      else
      {
        if ( !OSuite::psock::recv(v4, &buf, 1ui64) )
          return 0;
        if ( buf != 5 )
          goto LABEL_12;
        v4->proxy.state = 9;
      }
    }
    else
    {
      if ( !OSuite::psock::platform::connect(v4, &g_ProxyIP, g_nProxyPort) )
        return 0;
      OSuite::psock::send(v4, versions, 3ui64);
      v4->proxy.state = 8;
    }
LABEL_27:
    v4->lasterror = 3;
    if ( OSuite::psock::g_ErrorCallback )
      OSuite::psock::g_ErrorCallback(ERR_AGAIN);
    return 1;
  }
  v16 = v5 - 13;
  if ( !v16 )
  {
    if ( !OSuite::psock::recv(v4, &buf, 1ui64) )
      return 0;
    if ( v6 )
      v4->proxy.udpaddr.b[v4->proxy.substate] = buf;
    if ( ++v4->proxy.substate != 4 )
      goto LABEL_27;
    if ( !v6 )
    {
      v4->proxy.udpaddr.type = 0;
      v4->proxy.udpport = 0;
    }
LABEL_63:
    v4->proxy.substate = 0;
    goto LABEL_64;
  }
  v17 = v16 - 1;
  if ( !v17 )
  {
    if ( !OSuite::psock::recv(v4, &buf, 1ui64) )
      return 0;
    if ( ++v4->proxy.substate != 16 )
      goto LABEL_27;
    goto LABEL_63;
  }
  v18 = v17 - 1;
  if ( !v18 )
  {
    if ( !OSuite::psock::recv(v4, &buf, 1ui64) )
      return 0;
    v21 = buf;
    v4->proxy.substate = (char)buf;
    v4->proxy.state = 17 - (v21 != 0);
    goto LABEL_27;
  }
  v19 = v18 - 1;
  if ( !v19 )
  {
    if ( !OSuite::psock::recv(v4, &buf, 1ui64) )
      return 0;
    v20 = v4->proxy.substate-- == 1;
    if ( !v20 )
      goto LABEL_27;
LABEL_64:
    v4->proxy.state = 17;
    goto LABEL_27;
  }
  if ( v19 != 1 )
    goto LABEL_12;
  if ( !OSuite::psock::recv(v4, &buf, 1ui64) )
    return 0;
  if ( v6 )
    v4->proxy.udpport = buf + (v4->proxy.udpport << 8);
  if ( ++v4->proxy.substate != 2 )
    goto LABEL_27;
  v4->proxy.substate = 0;
  v4->lasterror = 0;
  v4->proxy.state = 18;
  return 1;
}

// File Line: 375
// RVA: 0xEED444
bool __fastcall OSuite::psock::proxy_httpconnect_statemachine(OSuite::psock::psock_private *socket, OSuite::psock::ipv4addr_t *host, int port)
{
  OSuite::psock::psock_private *v3; // rbx
  OSuite::psock::proxystate_t v4; // ecx
  int v5; // esi
  OSuite::psock::ipv4addr_t *v6; // rdi
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  void (__fastcall *v13)(OSuite::psock::err_t); // rax
  signed __int64 v14; // rcx
  bool v16; // zf
  signed int v17; // ecx
  signed int v18; // eax
  unsigned __int64 i; // rax
  unsigned __int64 j; // rax
  int v21; // eax
  unsigned __int64 k; // rax
  int v23; // edx
  _SSL *v24; // rax
  OSuite::psock::err_t v25; // eax
  int *v26; // ST20_8
  unsigned __int64 v27; // rax
  int *err_code; // [rsp+20h] [rbp-E0h]
  __int64 v29; // [rsp+28h] [rbp-D8h]
  _QWORD v30[2]; // [rsp+30h] [rbp-D0h]
  char buf; // [rsp+40h] [rbp-C0h]
  int r; // [rsp+44h] [rbp-BCh]
  char _Dest[20]; // [rsp+48h] [rbp-B8h]
  char string; // [rsp+60h] [rbp-A0h]

  v3 = socket;
  v4 = socket->proxy.state;
  v5 = port;
  v6 = host;
  if ( v4 == PROXYSTATE_INITIAL )
  {
    if ( !OSuite::psock::platform::connect(v3, &g_ProxyIP, g_nProxyPort) )
      return 0;
    v3->proxy.state = 1;
    goto LABEL_64;
  }
  v7 = v4 - 1;
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
                v3->lasterror = 1;
                v13 = OSuite::psock::g_ErrorCallback;
                if ( !OSuite::psock::g_ErrorCallback )
                  return 0;
                v14 = 1i64;
LABEL_11:
                v13((OSuite::psock::err_t)v14);
                return 0;
              }
              if ( OSuite::psock::recv(v3, &buf, 1ui64) == 1 )
              {
                if ( buf == 10 )
                {
                  v3->lasterror = 0;
                  v3->proxy.state = 18;
                  return 1;
                }
                v3->proxy.state = 4;
LABEL_64:
                v3->lasterror = 3;
LABEL_65:
                if ( OSuite::psock::g_ErrorCallback )
                  OSuite::psock::g_ErrorCallback(ERR_AGAIN);
                return 1;
              }
LABEL_18:
              if ( v3->lasterror != 3 )
                return 0;
              return 1;
            }
            if ( OSuite::psock::recv(v3, &buf, 1ui64) != 1 )
              goto LABEL_18;
            v16 = buf == 13;
            v17 = 7;
          }
          else
          {
            if ( OSuite::psock::recv(v3, &buf, 1ui64) != 1 )
              goto LABEL_18;
            v16 = buf == 10;
            v17 = 6;
          }
          v18 = 4;
          if ( v16 )
            v18 = v17;
LABEL_44:
          v3->proxy.state = v18;
          goto LABEL_64;
        }
        for ( i = OSuite::psock::recv(v3, &buf, 1ui64); i == 1; i = OSuite::psock::recv(v3, &buf, 1ui64) )
        {
          v16 = buf == 13;
          v3->lasterror = 3;
          if ( v16 )
          {
            v3->proxy.state = 5;
            goto LABEL_65;
          }
          if ( OSuite::psock::g_ErrorCallback )
            OSuite::psock::g_ErrorCallback(ERR_AGAIN);
        }
      }
      else
      {
        for ( j = OSuite::psock::recv(v3, &buf, 1ui64); j == 1; j = OSuite::psock::recv(v3, &buf, 1ui64) )
        {
          if ( !isdigit(buf) )
          {
            if ( v3->proxy.substate != 200 )
              goto LABEL_9;
            v18 = 4;
            goto LABEL_44;
          }
          v21 = v3->proxy.substate;
          v3->lasterror = 3;
          v3->proxy.substate = buf + 2 * (5 * v21 - 24);
          if ( OSuite::psock::g_ErrorCallback )
            OSuite::psock::g_ErrorCallback(ERR_AGAIN);
        }
      }
    }
    else
    {
      for ( k = OSuite::psock::recv(v3, &buf, 1ui64); k == 1; k = OSuite::psock::recv(v3, &buf, 1ui64) )
      {
        if ( isspace(buf) )
        {
          *(_QWORD *)&v3->proxy.state = 3i64;
          return 1;
        }
        v3->lasterror = 3;
        if ( OSuite::psock::g_ErrorCallback )
          OSuite::psock::g_ErrorCallback(ERR_AGAIN);
      }
    }
    return v3->lasterror == 3;
  }
  v23 = v3->socket;
  r = 0;
  v24 = ssl_client_new(OSuite::psock::g_SSLContext, v23, 0i64, 0, &r);
  v3->tls.ssl = v24;
  if ( !v24 )
  {
    v25 = (unsigned int)OSuite::psock::map_axtls_error(r);
    v3->lasterror = v25;
    if ( OSuite::psock::g_ErrorCallback )
      OSuite::psock::g_ErrorCallback(v25);
    return 0;
  }
  LODWORD(v29) = (unsigned __int8)v6->b[3];
  LODWORD(err_code) = (unsigned __int8)v6->b[2];
  sprintf_s<20>((char (*)[20])_Dest, "%d.%d.%d.%d", (unsigned __int8)v6->b[0], (unsigned __int8)v6->b[1], err_code, v29);
  LODWORD(v30[0]) = v5;
  LODWORD(v26) = v5;
  sprintf_s(&string, 0x100ui64, http_connect_string, _Dest, v26, _Dest, v30[0]);
  v27 = strlen(&string);
  if ( !OSuite::psock::send(v3, &string, v27) )
  {
    v14 = 9i64;
    v3->lasterror = 9;
    v13 = OSuite::psock::g_ErrorCallback;
    if ( !OSuite::psock::g_ErrorCallback )
      return 0;
    goto LABEL_11;
  }
  v3->proxy.state = 2;
  v3->lasterror = 3;
  if ( OSuite::psock::g_ErrorCallback )
    OSuite::psock::g_ErrorCallback(ERR_AGAIN);
  return 1;
}

// File Line: 558
// RVA: 0xEED80C
bool __fastcall OSuite::psock::proxy_socks5connect(OSuite::psock::psock_private *socket, OSuite::psock::ipv4addr_t *addr, int port, int udpassocport)
{
  int *v4; // rsi
  int v5; // er14
  int v6; // er15
  OSuite::psock::psock_private *v7; // rdi
  int v9; // [rsp+20h] [rbp-10h]
  OSuite::psock::address_t v10; // [rsp+24h] [rbp-Ch]
  int v11; // [rsp+28h] [rbp-8h]

  v4 = (int *)addr;
  v9 = *(_DWORD *)addr->b;
  v5 = udpassocport;
  v10 = addr->type;
  v6 = port;
  v7 = socket;
  v11 = *(_DWORD *)&addr->xlspindex;
  if ( socket->async )
  {
    if ( OSuite::psock::proxy_socks5connect_statemachine(socket, (OSuite::psock::ipv4addr_t *)&v9, port, udpassocport) )
      return v7->proxy.state == 18;
  }
  else
  {
    while ( OSuite::psock::proxy_socks5connect_statemachine(
              socket,
              (OSuite::psock::ipv4addr_t *)&v9,
              port,
              udpassocport) )
    {
      if ( v7->proxy.state == 18 )
        return 1;
      udpassocport = v5;
      port = v6;
      v9 = *v4;
      v10 = v4[1];
      socket = v7;
      v11 = v4[2];
    }
  }
  return 0;
}

// File Line: 586
// RVA: 0xEEC6F8
char __fastcall OSuite::psock::proxy::connect(OSuite::psock::psock_private *socket, OSuite::psock::ipv4addr_t *addr, int port)
{
  int v3; // er14
  int *v4; // rsi
  OSuite::psock::psock_private *v5; // rbx
  OSuite::psock::psock_private **v7; // r15
  OSuite::psock::psock_private *v8; // rax
  int v9; // eax
  void (__fastcall *v10)(OSuite::psock::err_t); // rax
  signed __int64 v11; // rcx
  int v12; // [rsp+20h] [rbp-10h]
  OSuite::psock::address_t v13; // [rsp+24h] [rbp-Ch]
  int v14; // [rsp+28h] [rbp-8h]
  int porta; // [rsp+68h] [rbp+38h]

  v3 = port;
  v4 = (int *)addr;
  v5 = socket;
  if ( g_eProxyType == 1 )
  {
    if ( socket->protocol == 2 )
    {
      v12 = *(_DWORD *)addr->b;
      v13 = addr->type;
      v14 = *(_DWORD *)&addr->xlspindex;
      if ( socket->async )
      {
        if ( OSuite::psock::proxy_httpconnect_statemachine(socket, (OSuite::psock::ipv4addr_t *)&v12, port) )
          return v5->proxy.state == 18;
      }
      else
      {
        while ( OSuite::psock::proxy_httpconnect_statemachine(socket, (OSuite::psock::ipv4addr_t *)&v12, port) )
        {
          if ( v5->proxy.state == 18 )
            return 1;
          port = v3;
          v12 = *v4;
          socket = v5;
          v13 = v4[1];
          v14 = v4[2];
        }
      }
      return 0;
    }
    return OSuite::psock::platform::connect(socket, addr, port);
  }
  if ( g_eProxyType != 2 )
    return OSuite::psock::platform::connect(socket, addr, port);
  if ( socket->protocol == PROT_UDP )
  {
    v7 = &socket->proxy.socks5;
    v8 = socket->proxy.socks5;
    if ( !v8 )
    {
      OSuite::psock::create(&socket->proxy.socks5, PROT_TCP, socket->async, 0);
      *(_DWORD *)v5->proxy.udpaddr.b = *v4;
      v5->proxy.udpaddr.type = v4[1];
      v9 = v4[2];
      v5->proxy.udpport = v3;
      *(_DWORD *)&v5->proxy.udpaddr.xlspindex = v9;
      v8 = *v7;
      if ( !*v7 )
        goto LABEL_15;
    }
    if ( v8->proxy.state != 18 )
    {
      if ( OSuite::psock::getsockname(v8, 0i64, &porta) )
      {
        if ( !OSuite::psock::proxy_socks5connect(*v7, &g_ProxyIP, g_nProxyPort, porta) )
          return 0;
        v11 = 3i64;
        v5->lasterror = 3;
        v10 = OSuite::psock::g_ErrorCallback;
        if ( !OSuite::psock::g_ErrorCallback )
          return 0;
        goto LABEL_17;
      }
LABEL_15:
      v5->lasterror = 1;
      v10 = OSuite::psock::g_ErrorCallback;
      if ( !OSuite::psock::g_ErrorCallback )
        return 0;
      v11 = 1i64;
LABEL_17:
      v10((OSuite::psock::err_t)v11);
      return 0;
    }
    port = v8->proxy.udpport;
    addr = &v8->proxy.udpaddr;
    socket = v5;
    return OSuite::psock::platform::connect(socket, addr, port);
  }
  return OSuite::psock::proxy_socks5connect(socket, addr, port, 0);
}

// File Line: 654
// RVA: 0xEEDD9C
signed __int64 __fastcall OSuite::psock::proxy::recv(OSuite::psock::psock_private *socket, void *buf, unsigned __int64 len)
{
  void *v3; // rbp
  OSuite::psock::psock_private *v4; // rdi
  unsigned __int64 v5; // rbx
  _BYTE *v6; // rax
  _BYTE *v7; // rsi
  signed __int64 result; // rax
  unsigned __int64 v9; // rax
  signed __int64 v10; // rbx

  v3 = buf;
  v4 = socket;
  if ( !socket->proxy.socks5 )
    return OSuite::psock::platform::recv(socket, buf, len);
  v5 = len + 10;
  v6 = (_BYTE *)OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, len + 10, 0i64);
  v7 = v6;
  if ( v6 )
  {
    v9 = OSuite::psock::platform::recv(v4, v6, v5);
    v10 = v9;
    if ( v9 < 0xA )
    {
      if ( v9 )
      {
        v4->lasterror = 5;
        if ( OSuite::psock::g_ErrorCallback )
          OSuite::psock::g_ErrorCallback(ERR_MESSAGE_TOO_BIG);
        v10 = 0i64;
      }
    }
    else if ( !v7[2] )
    {
      v10 = v9 - 10;
      memmove(v3, v7 + 10, v9 - 10);
    }
    OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, v7);
    result = v10;
  }
  else
  {
    v4->lasterror = 5;
    if ( OSuite::psock::g_ErrorCallback )
      OSuite::psock::g_ErrorCallback(ERR_MESSAGE_TOO_BIG);
    result = 0i64;
  }
  return result;
}

// File Line: 691
// RVA: 0xEEE204
signed __int64 __fastcall OSuite::psock::proxy::send(OSuite::psock::psock_private *socket, const void *buf, unsigned __int64 len)
{
  unsigned __int64 v3; // rsi
  const void *v4; // rbp
  OSuite::psock::psock_private *v5; // rbx
  char *v6; // rax
  _BYTE *v7; // rdi
  signed __int64 result; // rax
  unsigned __int64 v9; // rbx

  v3 = len;
  v4 = buf;
  v5 = socket;
  if ( !socket->proxy.socks5 )
    return OSuite::psock::platform::send(socket, buf, len);
  v6 = (char *)OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, len + 10, 0i64);
  v7 = v6;
  if ( v6 )
  {
    memmove(v6 + 10, v4, v3);
    *(_DWORD *)v7 = 0x1000000;
    v7[4] = v5->proxy.udpaddr.b[0];
    v7[5] = v5->proxy.udpaddr.b[1];
    v7[6] = v5->proxy.udpaddr.b[2];
    v7[7] = v5->proxy.udpaddr.b[3];
    v7[8] = LOWORD(v5->proxy.udpport) >> 8;
    v7[9] = v5->proxy.udpport;
    v9 = OSuite::psock::platform::send(v5, v7, v3 + 10);
    OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, v7);
    if ( v9 < 0xA )
      result = v9 & -(signed __int64)(v9 < 1);
    else
      result = v9 - 10;
  }
  else
  {
    v5->lasterror = 5;
    if ( OSuite::psock::g_ErrorCallback )
      OSuite::psock::g_ErrorCallback(ERR_MESSAGE_TOO_BIG);
    result = 0i64;
  }
  return result;
}

