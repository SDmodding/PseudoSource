// File Line: 125
// RVA: 0xEEC2EC
bool __fastcall OSuite::psock::IsSocketValid(OSuite::psock::psock_private *socket)
{
  return socket->socket != -1i64;
}

// File Line: 135
// RVA: 0xEED364
void __fastcall OSuite::psock::new_psock(
        OSuite::psock::psock_private **r,
        unsigned __int64 socket,
        bool async,
        OSuite::psock::protocol_t prot,
        bool secure)
{
  OSuite::psock::psock_private *v6; // rcx

  v6 = *r;
  if ( v6 )
  {
    if ( v6->socket != -1i64 )
      OSuite::psock::close(v6);
  }
  else
  {
    *r = (OSuite::psock::psock_private *)((__int64 (__fastcall *)(OSuite::IAllocator *, __int64))OSuite::ZObject::m_allocator->vfptr->malloc)(
                                           OSuite::ZObject::m_allocator,
                                           112i64);
  }
  memset(*r, 0, sizeof(OSuite::psock::psock_private));
  (*r)->socket = socket;
  (*r)->async = async;
  (*r)->protocol = prot;
  (*r)->state = STATE_CONNECTING_PHASE2;
  (*r)->lasterror = ERR_OK;
  (*r)->connect_timeout = 30000;
  (*r)->proxy.state = PROXYSTATE_INITIAL;
  (*r)->proxy.socks5 = 0i64;
  (*r)->tls.secure = secure;
  (*r)->tls.ssl = 0i64;
  (*r)->tls.buffer = 0i64;
  (*r)->tls.buffersize = 0i64;
  (*r)->tls.bufferused = 0i64;
  (*r)->tls.bufferindex = 0i64;
}

// File Line: 169
// RVA: 0xEECC5C
void __fastcall OSuite::psock::enablebroadcast(OSuite::psock::psock_private *socket, bool enable)
{
  int v2; // eax
  unsigned __int64 v3; // rcx
  char optval[4]; // [rsp+30h] [rbp-18h] BYREF

  if ( socket )
  {
    v2 = 0;
    if ( socket->protocol == PROT_UDP )
    {
      v3 = socket->socket;
      LOBYTE(v2) = enable;
      *(_DWORD *)optval = v2;
      setsockopt(v3, 0xFFFF, 32, optval, 4);
    }
  }
}

// File Line: 302
// RVA: 0xEECD04
char __fastcall OSuite::psock::getaddrbyname(OSuite::psock::ipv4addr_t *result, const char *hostname)
{
  struct hostent *v4; // rax
  u_long v5; // ecx
  unsigned int v6; // eax

  if ( hostname && result )
  {
    v4 = gethostbyname(hostname);
    if ( v4 )
    {
      v5 = ntohl(**(_DWORD **)v4->h_addr_list);
LABEL_6:
      result->b[3] = v5;
      result->xlspindex = -1;
      result->b[0] = HIBYTE(v5);
      result->b[1] = BYTE2(v5);
      result->type = ADDR_IPV4;
      result->b[2] = BYTE1(v5);
      return 1;
    }
    v6 = inet_addr(hostname);
    v5 = ntohl(v6);
    if ( v5 != -1 )
      goto LABEL_6;
  }
  return 0;
}

// File Line: 401
// RVA: 0xEED0D4
__int64 __fastcall OSuite::psock::lasterror(OSuite::psock::psock_private *socket)
{
  return (unsigned int)socket->lasterror;
}

// File Line: 415
// RVA: 0xEEC2F4
char __fastcall OSuite::psock::LoadRootCertitificates(OSuite::psock::tlspolicy_t policy)
{
  _SSL_CTX *v1; // rax

  v1 = ssl_ctx_new(0, 0);
  x509_accept_all = 0;
  OSuite::psock::g_SSLContext = v1;
  return 1;
}

// File Line: 441
// RVA: 0xEED084
char __fastcall OSuite::psock::init()
{
  char result; // al

  if ( !OSuite::psock::g_bInitialized )
  {
    OSuite::psock::g_bInitialized = 1;
    result = OSuite::psock::platform::InitializePlatform();
    if ( !result )
    {
      OSuite::psock::g_bInitialized = 0;
      return result;
    }
    OSuite::psock::platform::GetDefaultProxyServer();
    RNG_initialize(0i64, 0);
    OSuite::psock::uuid::g_lock = CreateMutexA(0i64, 0, 0i64);
  }
  return 1;
}

// File Line: 470
// RVA: 0xEEE400
void __fastcall OSuite::psock::shutdown(OSuite::psock *this)
{
  if ( OSuite::psock::g_bInitialized )
  {
    CloseHandle(OSuite::psock::uuid::g_lock);
    ssl_ctx_free(OSuite::psock::g_SSLContext);
    RNG_terminate();
    if ( g_hIphlpapi )
      FreeLibrary(g_hIphlpapi);
    OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, g_pszProxyHost);
    g_pszProxyHost = 0i64;
    g_nProxyPort = 0;
    g_eProxyType = PROXY_NONE;
    OSuite::psock::g_bInitialized = 0;
  }
}

// File Line: 498
// RVA: 0xEECA4C
bool __fastcall OSuite::psock::connectedToNetwork()
{
  unsigned int dwFlags; // [rsp+20h] [rbp-18h] BYREF

  return InternetGetConnectedState(&dwFlags, 0);
}

// File Line: 523
// RVA: 0xEECA84
void __fastcall OSuite::psock::create(
        OSuite::psock::psock_private **newSocket,
        OSuite::psock::protocol_t prot,
        bool async,
        bool secure)
{
  int v8; // r8d
  int v9; // edx
  SOCKET v10; // rax
  SOCKET v11; // rdi

  if ( prot )
  {
    if ( prot != PROT_TCP )
    {
LABEL_3:
      *newSocket = 0i64;
      return;
    }
    v8 = 0;
    v9 = 1;
  }
  else
  {
    v8 = 17;
    v9 = 2;
  }
  v10 = socket(2, v9, v8);
  v11 = v10;
  if ( v10 == -1i64 )
    goto LABEL_3;
  if ( async && !OSuite::psock::platform::SetAsync(v10, 1) )
  {
    closesocket(v11);
    goto LABEL_3;
  }
  OSuite::psock::new_psock(newSocket, v11, async, prot, secure);
  if ( *newSocket )
    OSuite::psock::enablebroadcast(*newSocket, 0);
}

// File Line: 616
// RVA: 0xEEC5A0
void __fastcall OSuite::psock::abort(OSuite::psock::psock_private *socket, OSuite::psock::err_t err)
{
  if ( socket )
  {
    shutdown(socket->socket, 2);
    if ( err )
    {
      socket->lasterror = err;
      if ( OSuite::psock::g_ErrorCallback )
        OSuite::psock::g_ErrorCallback(err);
    }
  }
}

// File Line: 630
// RVA: 0xEEC5E4
bool __fastcall OSuite::psock::close(OSuite::psock::psock_private *socket)
{
  OSuite::psock::psock_private *socks5; // rcx
  bool result; // al
  unsigned __int64 v4; // rcx

  socks5 = socket->proxy.socks5;
  if ( !socks5 || (result = OSuite::psock::close(socks5)) )
  {
    v4 = socket->socket;
    socket->socket = -1i64;
    socket->state = STATE_CLOSED|STATE_CONNECTING_PHASE2;
    socket->lasterror = ERR_CLOSED;
    return closesocket(v4) == 0;
  }
  return result;
}

// File Line: 650
// RVA: 0xEECCB8
void __fastcall OSuite::psock::free(OSuite::psock::psock_private *socket)
{
  if ( socket )
  {
    if ( socket->tls.secure )
    {
      ssl_free(socket->tls.ssl);
      OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, socket->tls.buffer);
    }
    if ( !socket->proxy.socks5 )
      OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, socket);
  }
}

// File Line: 673
// RVA: 0xEED304
void __fastcall OSuite::psock::mksockaddr(sockaddr_in *sa, OSuite::psock::ipv4addr_t *addr, u_short port)
{
  memset(sa, 0, sizeof(sockaddr_in));
  sa->sin_family = 2;
  sa->sin_port = htons(port);
  sa->sin_addr = *(in_addr *)addr->b;
}

// File Line: 719
// RVA: 0xEECFE8
char __fastcall OSuite::psock::getsockname(
        OSuite::psock::psock_private *socket,
        OSuite::psock::ipv4addr_t *addr,
        int *port)
{
  unsigned __int64 v3; // rcx
  char v6; // al
  int namelen; // [rsp+20h] [rbp-28h] BYREF
  struct sockaddr name; // [rsp+28h] [rbp-20h] BYREF

  v3 = socket->socket;
  namelen = 16;
  if ( getsockname(v3, &name, &namelen) )
    return 0;
  if ( addr )
  {
    v6 = name.sa_data[2];
    addr->type = ADDR_IPV4;
    addr->xlspindex = -1;
    addr->b[0] = v6;
    addr->b[1] = name.sa_data[3];
    addr->b[2] = name.sa_data[4];
    addr->b[3] = name.sa_data[5];
  }
  if ( port )
    *port = htons(*(u_short *)name.sa_data);
  return 1;
}

// File Line: 880
// RVA: 0xEED274
void __fastcall OSuite::psock::mkpsockset(OSuite::psock::psockset_t *out, OSuite::psock::psockset_t *in, fd_set *set)
{
  __int64 i; // r10
  __int64 count; // rsi
  int v6; // r11d
  __int64 v7; // rdx
  OSuite::psock::psocksetmember_t *array; // rbx

  out->count = 0;
  for ( i = 0i64; (unsigned int)i < set->fd_count; i = (unsigned int)(i + 1) )
  {
    count = in->count;
    v6 = 0;
    v7 = 0i64;
    if ( count > 0 )
    {
      array = in->array;
      do
      {
        if ( v7 >= 32 )
          break;
        if ( array->socket->socket == set->fd_array[i] )
          break;
        ++v7;
        ++v6;
        ++array;
      }
      while ( v7 < count );
    }
    if ( v6 < in->count && v7 < 32 )
      out->array[out->count++] = in->array[v7];
  }
}

// File Line: 910
// RVA: 0xEEDFA8
__int64 __fastcall OSuite::psock::selectread(
        OSuite::psock::psockset_t *out,
        OSuite::psock::psockset_t *in,
        int timeout)
{
  __int64 v6; // rdx
  __int64 fd_count; // r9
  OSuite::psock::psocksetmember_t *array; // r8
  OSuite::psock::psock_private *socket; // rax
  const struct timeval *v10; // rcx
  int v11; // eax
  int v13[4]; // [rsp+30h] [rbp-248h] BYREF
  fd_set readfds; // [rsp+40h] [rbp-238h] BYREF

  readfds.fd_count = in->count;
  v6 = 0i64;
  fd_count = (int)readfds.fd_count;
  if ( (int)readfds.fd_count > 0 )
  {
    array = in->array;
    do
    {
      socket = array->socket;
      ++v6;
      ++array;
      *((_QWORD *)&readfds.fd_count + v6) = socket->socket;
    }
    while ( v6 < fd_count );
  }
  v10 = (const struct timeval *)v13;
  v13[0] = timeout / 1000;
  v13[1] = 1000 * (timeout % 1000);
  if ( timeout == -1 )
    v10 = 0i64;
  v11 = select(0, &readfds, 0i64, 0i64, v10);
  if ( v11 == -1 )
    return 1i64;
  if ( !v11 )
    return 3i64;
  OSuite::psock::mkpsockset(out, in, &readfds);
  return 0i64;
}

// File Line: 938
// RVA: 0xEEE6D0
__int64 __fastcall OSuite::psock::waitwrite(OSuite::psock::psock_private *socket, int timeout)
{
  bool v2; // zf
  unsigned __int64 v4; // rcx
  OSuite::psock::err_t v5; // ebx
  char optval[4]; // [rsp+30h] [rbp-448h] BYREF
  int optlen[3]; // [rsp+34h] [rbp-444h] BYREF
  OSuite::psock::psockset_t in; // [rsp+40h] [rbp-438h] BYREF
  OSuite::psock::psockset_t out; // [rsp+250h] [rbp-228h] BYREF

  out.count = 0;
  in.array[0].userdata = 0i64;
  v2 = !socket->async;
  in.array[0].socket = socket;
  in.count = 1;
  if ( v2 )
  {
    v4 = socket->socket;
    *(_DWORD *)optval = 0;
    optlen[0] = 4;
    getsockopt(v4, 0xFFFF, 4101, optval, optlen);
    timeout = *(_DWORD *)optval;
  }
  v5 = (unsigned int)OSuite::psock::selectwrite(&out, &in, timeout);
  socket->lasterror = v5;
  if ( OSuite::psock::g_ErrorCallback )
    OSuite::psock::g_ErrorCallback(v5);
  return (unsigned int)v5;
}

// File Line: 974
// RVA: 0xEEE090
__int64 __fastcall OSuite::psock::selectwrite(
        OSuite::psock::psockset_t *out,
        OSuite::psock::psockset_t *in,
        int timeout)
{
  __int64 v6; // rdx
  __int64 fd_count; // r9
  OSuite::psock::psocksetmember_t *array; // r8
  OSuite::psock::psock_private *socket; // rax
  const struct timeval *v10; // rcx
  int v11; // eax
  int v13[4]; // [rsp+30h] [rbp-248h] BYREF
  fd_set writefds; // [rsp+40h] [rbp-238h] BYREF

  writefds.fd_count = in->count;
  v6 = 0i64;
  fd_count = (int)writefds.fd_count;
  if ( (int)writefds.fd_count > 0 )
  {
    array = in->array;
    do
    {
      socket = array->socket;
      ++v6;
      ++array;
      *((_QWORD *)&writefds.fd_count + v6) = socket->socket;
    }
    while ( v6 < fd_count );
  }
  v10 = (const struct timeval *)v13;
  v13[0] = timeout / 1000;
  if ( timeout == -1 )
    v10 = 0i64;
  v13[1] = 1000 * (timeout % 1000);
  v11 = select(0, 0i64, &writefds, 0i64, v10);
  if ( v11 == -1 )
    return 1i64;
  if ( !v11 )
    return 3i64;
  OSuite::psock::mkpsockset(out, in, &writefds);
  return 0i64;
}

// File Line: 1089
// RVA: 0xEEE36C
char __fastcall OSuite::psock::settimeout(
        OSuite::psock::psock_private *socket,
        int sendtimeout,
        int recvtimeout,
        int connecttimeout)
{
  unsigned __int64 v7; // rcx
  unsigned __int64 v8; // rcx
  char optval[4]; // [rsp+30h] [rbp-18h] BYREF

  if ( socket->async )
    return 0;
  socket->connect_timeout = connecttimeout;
  v7 = socket->socket;
  *(_DWORD *)optval = recvtimeout;
  setsockopt(v7, 0xFFFF, 4102, optval, 4);
  v8 = socket->socket;
  *(_DWORD *)optval = sendtimeout;
  setsockopt(v8, 0xFFFF, 4101, optval, 4);
  return 1;
}

// File Line: 1127
// RVA: 0xEECD8C
__int64 __fastcall OSuite::psock::getinterfaces(OSuite::psock::interface_t *dest, int count)
{
  int v2; // ebx
  int dwNumEntries; // ebp
  _MIB_IPADDRTABLE *v5; // rax
  _MIB_IPADDRTABLE *v6; // rsi
  _IP_ADAPTER_INFO *v7; // rax
  _IP_ADAPTER_INFO *v8; // r12
  unsigned int v9; // r15d
  OSuite::psock::address_t *p_type; // r13
  _IP_ADAPTER_INFO *v11; // rdx
  unsigned int Type; // eax
  unsigned int *v13; // rdi
  OSuite::psock::interface_t *v14; // rbx
  __int64 v15; // rax
  OSuite::psock::address_t *v16; // r8
  OSuite::psock::address_t *v17; // r9
  __int64 v18; // r10
  char v19; // cl
  char v20; // dl
  unsigned int v23; // [rsp+24h] [rbp-34h] BYREF

  v2 = count;
  dwNumEntries = 0;
  if ( !g_fpGetAdaptersInfo || !g_fpGetIpAddrTable )
    return 0i64;
  v23 = 0;
  if ( g_fpGetIpAddrTable(0i64, &v23, 0) == 122 )
  {
    v5 = (_MIB_IPADDRTABLE *)OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, v23, 0i64);
    v6 = v5;
    if ( v5 )
    {
      if ( !g_fpGetIpAddrTable(v5, &v23, 0) )
      {
        if ( dest )
        {
          v23 = 0;
          if ( g_fpGetAdaptersInfo(0i64, &v23) == 111 )
          {
            v7 = (_IP_ADAPTER_INFO *)OSuite::ZObject::m_allocator->vfptr->malloc(
                                       OSuite::ZObject::m_allocator,
                                       v23,
                                       0i64);
            v8 = v7;
            if ( v7 )
            {
              if ( !g_fpGetAdaptersInfo(v7, &v23) )
              {
                v9 = 0;
                if ( v6->dwNumEntries )
                {
                  p_type = &dest->netmask.type;
                  do
                  {
                    if ( dwNumEntries >= v2 )
                      break;
                    v11 = v8;
                    while ( 1 )
                    {
                      if ( v6->table[v9].dwIndex == v11->Index )
                      {
                        Type = v11->Type;
                        if ( Type == 6 || Type == 71 )
                          break;
                      }
                      v11 = v11->Next;
                      if ( !v11 )
                        goto LABEL_21;
                    }
                    v13 = &v6->dwNumEntries + 6 * v9;
                    v14 = &dest[dwNumEntries];
                    memmove(v14->mac, v11->Address, 6ui64);
                    memmove(v14, v13 + 1, 4ui64);
                    *((_DWORD *)p_type - 3) = 0;
                    memmove(&v14->netmask, v13 + 3, 4ui64);
                    v2 = count;
                    *p_type = ADDR_IPV4;
                    ++dwNumEntries;
                    p_type += 11;
LABEL_21:
                    ++v9;
                  }
                  while ( v9 < v6->dwNumEntries );
                }
              }
              OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, v8);
            }
          }
        }
        else
        {
          dwNumEntries = v6->dwNumEntries;
        }
      }
      OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, v6);
    }
  }
  if ( dest )
  {
    v15 = dwNumEntries;
    if ( dwNumEntries > 0 )
    {
      v16 = &dest->broadcast.type;
      do
      {
        v17 = v16 - 4;
        v18 = 4i64;
        do
        {
          v19 = *(_BYTE *)v17;
          v20 = *((_BYTE *)v17 - 12);
          v17 = (OSuite::psock::address_t *)((char *)v17 + 1);
          *((_BYTE *)v17 + 11) = ~v19 | v19 & v20;
          --v18;
        }
        while ( v18 );
        *v16 = ADDR_IPV4;
        v16 += 11;
        --v15;
      }
      while ( v15 );
    }
  }
  return (unsigned int)dwNumEntries;
}

// File Line: 1417
// RVA: 0xEEDC78
__int64 __fastcall OSuite::psock::platform::recv(OSuite::psock::psock_private *socket, char *buf, unsigned __int64 len)
{
  void (__fastcall *v5)(OSuite::psock::err_t); // rax
  __int64 v6; // rcx
  int v7; // eax
  __int64 v8; // rsi
  int Error; // eax

  if ( socket->state == (STATE_CLOSED|STATE_CONNECTING_PHASE2) )
  {
    socket->lasterror = ERR_CLOSED;
    v5 = OSuite::psock::g_ErrorCallback;
    if ( OSuite::psock::g_ErrorCallback )
    {
      v6 = 4i64;
LABEL_24:
      ((void (__fastcall *)(__int64, char *))v5)(v6, buf);
      return 0i64;
    }
    return 0i64;
  }
  v7 = recv(socket->socket, buf, len, 0);
  v8 = v7;
  if ( v7 <= 0 )
  {
    if ( !v7 )
    {
LABEL_12:
      socket->lasterror = ERR_CLOSED;
      if ( OSuite::psock::g_ErrorCallback )
        OSuite::psock::g_ErrorCallback(ERR_CLOSED);
      socket->state = STATE_CLOSED|STATE_CONNECTING_PHASE2;
      return 0i64;
    }
    Error = WSAGetLastError();
    if ( Error != 10035 )
    {
      if ( Error == 10040 )
      {
        socket->lasterror = ERR_OK;
        return len;
      }
      if ( Error <= 10052 )
        goto LABEL_20;
      if ( Error <= 10054 )
        goto LABEL_12;
      if ( Error != 10060 )
      {
LABEL_20:
        socket->lasterror = ERR_FAILED;
        v5 = OSuite::psock::g_ErrorCallback;
        if ( OSuite::psock::g_ErrorCallback )
        {
          v6 = 1i64;
          goto LABEL_24;
        }
        return 0i64;
      }
    }
    v6 = 3i64;
    socket->lasterror = ERR_AGAIN;
    v5 = OSuite::psock::g_ErrorCallback;
    if ( OSuite::psock::g_ErrorCallback )
      goto LABEL_24;
    return 0i64;
  }
  if ( (unsigned int)(WSAGetLastError() - 10053) <= 1 )
  {
    socket->lasterror = ERR_CLOSED;
    if ( OSuite::psock::g_ErrorCallback )
      OSuite::psock::g_ErrorCallback(ERR_CLOSED);
    socket->lasterror = ERR_CLOSED;
    socket->state = STATE_CLOSED|STATE_CONNECTING_PHASE2;
  }
  else
  {
    socket->lasterror = ERR_OK;
  }
  return v8;
}

// File Line: 1482
// RVA: 0xEEE178
unsigned __int64 __fastcall OSuite::psock::platform::send(
        OSuite::psock::psock_private *socket,
        const char *buf,
        unsigned __int64 len)
{
  __int64 v4; // rcx
  unsigned __int64 result; // rax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  void (__fastcall *v9)(OSuite::psock::err_t); // rax

  if ( socket->state == (STATE_CLOSED|STATE_CONNECTING_PHASE2) )
    goto LABEL_2;
  LODWORD(result) = send(socket->socket, buf, len, 0);
  if ( (_DWORD)result != -1 )
  {
    socket->lasterror = ERR_OK;
    return (int)result;
  }
  v6 = WSAGetLastError() - 10035;
  if ( !v6 )
    goto LABEL_12;
  v7 = v6 - 5;
  if ( v7 )
  {
    v8 = v7 - 14;
    if ( !v8 )
    {
LABEL_2:
      v4 = 4i64;
      goto LABEL_13;
    }
    if ( v8 != 6 )
    {
      v4 = 1i64;
      goto LABEL_13;
    }
LABEL_12:
    v4 = 3i64;
LABEL_13:
    socket->lasterror = v4;
    v9 = OSuite::psock::g_ErrorCallback;
    if ( OSuite::psock::g_ErrorCallback )
      goto LABEL_14;
    return 0i64;
  }
  socket->lasterror = ERR_MESSAGE_TOO_BIG;
  v9 = OSuite::psock::g_ErrorCallback;
  if ( OSuite::psock::g_ErrorCallback )
  {
    v4 = 5i64;
LABEL_14:
    v9((OSuite::psock::err_t)v4);
  }
  return 0i64;
}

// File Line: 1535
// RVA: 0xEEC924
char __fastcall OSuite::psock::platform::connect_statemachine(
        OSuite::psock::psock_private *socket,
        OSuite::psock::ipv4addr_t *addr,
        __int64 port)
{
  __int32 v4; // ecx
  __int32 v5; // ecx
  __int32 v6; // ecx
  __int64 v7; // rcx
  void (__fastcall *v8)(OSuite::psock::err_t); // rax
  int Error; // eax
  sockaddr_in sa; // [rsp+20h] [rbp-28h] BYREF

  v4 = socket->state - 1;
  if ( !v4 )
  {
    if ( addr->type == ADDR_LIVESECURE )
    {
      socket->lasterror = ERR_ARGUMENT;
      v8 = OSuite::psock::g_ErrorCallback;
      if ( !OSuite::psock::g_ErrorCallback )
        return 0;
      v7 = 2i64;
      goto LABEL_9;
    }
    socket->state = STATE_CONNECTED;
    return 1;
  }
  v5 = v4 - 1;
  if ( !v5 )
  {
    OSuite::psock::mksockaddr(&sa, addr, port);
    OSuite::psock::waitwrite(socket, 100);
    if ( connect(socket->socket, (const struct sockaddr *)&sa, 16) >= 0 )
    {
LABEL_12:
      socket->state = STATE_CLOSING;
      return 1;
    }
    if ( !socket->async )
      goto LABEL_7;
    Error = WSAGetLastError();
    if ( Error != 10022 )
    {
      if ( Error <= 10034 )
        goto LABEL_7;
      if ( Error > 10037 )
      {
        if ( Error == 10056 )
          goto LABEL_12;
        if ( Error != 10060 )
          goto LABEL_7;
      }
    }
    socket->lasterror = ERR_AGAIN;
    return 1;
  }
  v6 = v5 - 1;
  if ( v6 )
  {
    if ( v6 == 2 )
    {
      v7 = 4i64;
      socket->lasterror = ERR_CLOSED;
      v8 = OSuite::psock::g_ErrorCallback;
      if ( OSuite::psock::g_ErrorCallback )
        goto LABEL_9;
      return 0;
    }
LABEL_7:
    socket->lasterror = ERR_FAILED;
    v8 = OSuite::psock::g_ErrorCallback;
    if ( OSuite::psock::g_ErrorCallback )
    {
      v7 = 1i64;
LABEL_9:
      ((void (__fastcall *)(__int64, OSuite::psock::ipv4addr_t *, __int64))v8)(v7, addr, port);
    }
    return 0;
  }
  return 1;
}

// File Line: 1701
// RVA: 0xEEC630
char __fastcall OSuite::psock::platform::connect(
        OSuite::psock::psock_private *socket,
        OSuite::psock::ipv4addr_t *addr,
        int port)
{
  void (*v6)(void); // rax
  int v8; // ebp

  if ( socket->state == (STATE_CLOSED|STATE_CONNECTING_PHASE2) )
  {
    socket->lasterror = ERR_CLOSED;
    v6 = (void (*)(void))OSuite::psock::g_ErrorCallback;
    if ( OSuite::psock::g_ErrorCallback )
LABEL_3:
      v6();
    return 0;
  }
  if ( !socket->async )
  {
    v8 = clock();
    while ( OSuite::psock::platform::connect_statemachine(socket, addr, port) )
    {
      if ( socket->state == STATE_CLOSING )
        goto LABEL_8;
      if ( socket->connect_timeout && clock() - v8 >= socket->connect_timeout )
      {
        socket->lasterror = ERR_FAILED;
        v6 = (void (*)(void))OSuite::psock::g_ErrorCallback;
        if ( !OSuite::psock::g_ErrorCallback )
          return 0;
        goto LABEL_3;
      }
    }
    return 0;
  }
  if ( !OSuite::psock::platform::connect_statemachine(socket, addr, port) )
    return 0;
  if ( socket->state != STATE_CLOSING )
  {
    socket->lasterror = ERR_AGAIN;
    return 0;
  }
LABEL_8:
  socket->lasterror = ERR_OK;
  return 1;
}

