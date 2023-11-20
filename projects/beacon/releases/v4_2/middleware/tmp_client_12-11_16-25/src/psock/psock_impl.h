// File Line: 125
// RVA: 0xEEC2EC
bool __fastcall OSuite::psock::IsSocketValid(OSuite::psock::psock_private *socket)
{
  return socket->socket != -1i64;
}

// File Line: 135
// RVA: 0xEED364
void __fastcall OSuite::psock::new_psock(OSuite::psock::psock_private **r, unsigned __int64 socket, bool async, OSuite::psock::protocol_t prot, bool secure)
{
  void **v5; // rbx
  OSuite::psock::psock_private *v6; // rcx
  OSuite::psock::protocol_t v7; // edi
  bool v8; // si
  unsigned __int64 v9; // rbp

  v5 = (void **)r;
  v6 = *r;
  v7 = prot;
  v8 = async;
  v9 = socket;
  if ( v6 )
  {
    if ( v6->socket != -1i64 )
      OSuite::psock::close(v6);
  }
  else
  {
    *v5 = (void *)((__int64 (__fastcall *)(OSuite::IAllocator *, signed __int64))OSuite::ZObject::m_allocator->vfptr->malloc)(
                    OSuite::ZObject::m_allocator,
                    112i64);
  }
  memset(*v5, 0, 0x70ui64);
  *(_QWORD *)*v5 = v9;
  *((_BYTE *)*v5 + 12) = v8;
  *((_DWORD *)*v5 + 2) = v7;
  *((_DWORD *)*v5 + 4) = 1;
  *((_DWORD *)*v5 + 5) = 0;
  *((_DWORD *)*v5 + 6) = 30000;
  *((_DWORD *)*v5 + 8) = 0;
  *((_QWORD *)*v5 + 5) = 0i64;
  *((_BYTE *)*v5 + 64) = secure;
  *((_QWORD *)*v5 + 9) = 0i64;
  *((_QWORD *)*v5 + 10) = 0i64;
  *((_QWORD *)*v5 + 11) = 0i64;
  *((_QWORD *)*v5 + 12) = 0i64;
  *((_QWORD *)*v5 + 13) = 0i64;
}

// File Line: 169
// RVA: 0xEECC5C
void __fastcall OSuite::psock::enablebroadcast(OSuite::psock::psock_private *socket, bool enable)
{
  int v2; // eax
  unsigned __int64 v3; // rcx
  char optval[4]; // [rsp+30h] [rbp-18h]

  if ( socket )
  {
    v2 = 0;
    if ( socket->protocol == PROT_UDP )
    {
      v3 = socket->socket;
      LOBYTE(v2) = enable != 0;
      *(_DWORD *)optval = v2;
      setsockopt(v3, 0xFFFF, 32, optval, 4);
    }
  }
}

// File Line: 302
// RVA: 0xEECD04
char __fastcall OSuite::psock::getaddrbyname(OSuite::psock::ipv4addr_t *result, const char *hostname)
{
  const char *v2; // rdi
  OSuite::psock::ipv4addr_t *v3; // rbx
  struct hostent *v4; // rax
  u_long v5; // ecx
  unsigned int v6; // eax

  v2 = hostname;
  v3 = result;
  if ( hostname && result )
  {
    v4 = gethostbyname(hostname);
    if ( v4 )
    {
      v5 = ntohl(**(_DWORD **)v4->h_addr_list);
LABEL_6:
      v3->b[3] = v5;
      v3->xlspindex = -1;
      v3->b[0] = HIBYTE(v5);
      v3->b[1] = BYTE2(v5);
      v3->type = 0;
      v3->b[2] = BYTE1(v5);
      return 1;
    }
    v6 = inet_addr(v2);
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
    g_eProxyType = 0;
    OSuite::psock::g_bInitialized = 0;
  }
}

// File Line: 498
// RVA: 0xEECA4C
bool __fastcall OSuite::psock::connectedToNetwork()
{
  unsigned int dwFlags; // [rsp+20h] [rbp-18h]

  return InternetGetConnectedState(&dwFlags, 0) == 1;
}

// File Line: 523
// RVA: 0xEECA84
void __fastcall OSuite::psock::create(OSuite::psock::psock_private **newSocket, OSuite::psock::protocol_t prot, bool async, bool secure)
{
  OSuite::psock::psock_private **v4; // rbx
  bool v5; // r14
  bool v6; // bp
  OSuite::psock::protocol_t v7; // esi
  int v8; // er8
  int v9; // edx
  unsigned __int64 v10; // rax
  SOCKET v11; // rdi

  v4 = newSocket;
  v5 = secure;
  v6 = async;
  v7 = prot;
  if ( prot )
  {
    if ( prot != 2 )
    {
LABEL_3:
      *v4 = 0i64;
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
  if ( v6 && !OSuite::psock::platform::SetAsync(v10, 1) )
  {
    closesocket(v11);
    goto LABEL_3;
  }
  OSuite::psock::new_psock(v4, v11, v6, v7, v5);
  if ( *v4 )
    OSuite::psock::enablebroadcast(*v4, 0);
}

// File Line: 616
// RVA: 0xEEC5A0
void __fastcall OSuite::psock::abort(OSuite::psock::psock_private *socket, OSuite::psock::err_t err)
{
  OSuite::psock::psock_private *v2; // rdi
  OSuite::psock::err_t v3; // ebx

  if ( socket )
  {
    v2 = socket;
    v3 = err;
    shutdown(socket->socket, 2);
    if ( v3 )
    {
      v2->lasterror = v3;
      if ( OSuite::psock::g_ErrorCallback )
        OSuite::psock::g_ErrorCallback(v3);
    }
  }
}

// File Line: 630
// RVA: 0xEEC5E4
bool __fastcall OSuite::psock::close(OSuite::psock::psock_private *socket)
{
  OSuite::psock::psock_private *v1; // rdi
  OSuite::psock::psock_private *v2; // rcx
  bool result; // al
  SOCKET v4; // rcx

  v1 = socket;
  v2 = socket->proxy.socks5;
  if ( !v2 || (result = OSuite::psock::close(v2)) != 0 )
  {
    v4 = v1->socket;
    v1->socket = -1i64;
    v1->state = 5;
    v1->lasterror = 4;
    result = closesocket(v4) == 0;
  }
  return result;
}

// File Line: 650
// RVA: 0xEECCB8
void __fastcall OSuite::psock::free(OSuite::psock::psock_private *socket)
{
  OSuite::psock::psock_private *v1; // rbx

  if ( socket )
  {
    v1 = socket;
    if ( socket->tls.secure )
    {
      ssl_free(socket->tls.ssl);
      OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, v1->tls.buffer);
    }
    if ( !v1->proxy.socks5 )
      OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, v1);
  }
}

// File Line: 673
// RVA: 0xEED304
void __fastcall OSuite::psock::mksockaddr(sockaddr_in *sa, OSuite::psock::ipv4addr_t *addr, int port)
{
  OSuite::psock::ipv4addr_t *v3; // rdi
  u_short v4; // bx
  sockaddr_in *v5; // rsi

  v3 = addr;
  v4 = port;
  v5 = sa;
  memset(sa, 0, 0x10ui64);
  v5->sin_family = 2;
  v5->sin_port = htons(v4);
  v5->sin_addr.S_un.S_un_b.s_b1 = v3->b[0];
  v5->sin_addr.S_un.S_un_b.s_b2 = v3->b[1];
  v5->sin_addr.S_un.S_un_b.s_b3 = v3->b[2];
  v5->sin_addr.S_un.S_un_b.s_b4 = v3->b[3];
}

// File Line: 719
// RVA: 0xEECFE8
char __fastcall OSuite::psock::getsockname(OSuite::psock::psock_private *socket, OSuite::psock::ipv4addr_t *addr, int *port)
{
  unsigned __int64 v3; // rcx
  int *v4; // rdi
  OSuite::psock::ipv4addr_t *v5; // rbx
  char v6; // al
  int namelen; // [rsp+20h] [rbp-28h]
  struct sockaddr name; // [rsp+28h] [rbp-20h]

  v3 = socket->socket;
  v4 = port;
  v5 = addr;
  namelen = 16;
  if ( getsockname(v3, &name, &namelen) )
    return 0;
  if ( v5 )
  {
    v6 = name.sa_data[2];
    v5->type = 0;
    v5->xlspindex = -1;
    v5->b[0] = v6;
    v5->b[1] = name.sa_data[3];
    v5->b[2] = name.sa_data[4];
    v5->b[3] = name.sa_data[5];
  }
  if ( v4 )
    *v4 = htons(*(u_short *)name.sa_data);
  return 1;
}

// File Line: 880
// RVA: 0xEED274
void __fastcall OSuite::psock::mkpsockset(OSuite::psock::psockset_t *out, OSuite::psock::psockset_t *in, fd_set *set)
{
  __int64 v3; // r10
  OSuite::psock::psockset_t *v4; // rdi
  signed __int64 v5; // rsi
  int v6; // er11
  signed __int64 v7; // rdx
  OSuite::psock::psocksetmember_t *v8; // rbx

  out->count = 0;
  v3 = 0i64;
  v4 = in;
  if ( set->fd_count )
  {
    do
    {
      v5 = v4->count;
      v6 = 0;
      v7 = 0i64;
      if ( v5 > 0 )
      {
        v8 = v4->array;
        do
        {
          if ( v7 >= 32 )
            break;
          if ( v8->socket->socket == set->fd_array[v3] )
            break;
          ++v7;
          ++v6;
          ++v8;
        }
        while ( v7 < v5 );
      }
      if ( v6 < v4->count && v7 < 32 )
        _mm_storeu_si128((__m128i *)&out->array[out->count++], (__m128i)v4->array[v7]);
      v3 = (unsigned int)(v3 + 1);
    }
    while ( (unsigned int)v3 < set->fd_count );
  }
}

// File Line: 910
// RVA: 0xEEDFA8
signed __int64 __fastcall OSuite::psock::selectread(OSuite::psock::psockset_t *out, OSuite::psock::psockset_t *in, int timeout)
{
  OSuite::psock::psockset_t *v3; // rbx
  int v4; // er10
  OSuite::psock::psockset_t *v5; // rdi
  __int64 v6; // rdx
  __int64 v7; // r9
  OSuite::psock::psocksetmember_t *v8; // r8
  OSuite::psock::psock_private *v9; // rax
  const struct timeval *v10; // rcx
  int v11; // eax
  int v13; // [rsp+30h] [rbp-248h]
  int v14; // [rsp+34h] [rbp-244h]
  fd_set readfds; // [rsp+40h] [rbp-238h]

  v3 = in;
  v4 = timeout;
  v5 = out;
  readfds.fd_count = in->count;
  v6 = 0i64;
  v7 = (signed int)readfds.fd_count;
  if ( (signed int)readfds.fd_count > 0 )
  {
    v8 = v3->array;
    do
    {
      v9 = v8->socket;
      ++v6;
      ++v8;
      *((_QWORD *)&readfds.fd_count + v6) = v9->socket;
    }
    while ( v6 < v7 );
  }
  v10 = (const struct timeval *)&v13;
  v13 = v4 / 1000;
  v14 = 1000 * (v4 % 1000);
  if ( v4 == -1 )
    v10 = 0i64;
  v11 = select(0, &readfds, 0i64, 0i64, v10);
  if ( v11 == -1 )
    return 1i64;
  if ( !v11 )
    return 3i64;
  OSuite::psock::mkpsockset(v5, v3, &readfds);
  return 0i64;
}

// File Line: 938
// RVA: 0xEEE6D0
__int64 __fastcall OSuite::psock::waitwrite(OSuite::psock::psock_private *socket, int timeout)
{
  bool v2; // zf
  OSuite::psock::psock_private *v3; // rdi
  unsigned __int64 v4; // rcx
  OSuite::psock::err_t v5; // ebx
  char optval[4]; // [rsp+30h] [rbp-448h]
  int optlen; // [rsp+34h] [rbp-444h]
  OSuite::psock::psockset_t in; // [rsp+40h] [rbp-438h]
  OSuite::psock::psockset_t out; // [rsp+250h] [rbp-228h]

  out.count = 0;
  in.array[0].userdata = 0i64;
  v2 = socket->async == 0;
  v3 = socket;
  in.array[0].socket = socket;
  in.count = 1;
  if ( v2 )
  {
    v4 = socket->socket;
    *(_DWORD *)optval = 0;
    optlen = 4;
    getsockopt(v4, 0xFFFF, 4101, optval, &optlen);
    timeout = *(_DWORD *)optval;
  }
  v5 = (unsigned int)OSuite::psock::selectwrite(&out, &in, timeout);
  v3->lasterror = v5;
  if ( OSuite::psock::g_ErrorCallback )
    OSuite::psock::g_ErrorCallback(v5);
  return (unsigned int)v5;
}

// File Line: 974
// RVA: 0xEEE090
signed __int64 __fastcall OSuite::psock::selectwrite(OSuite::psock::psockset_t *out, OSuite::psock::psockset_t *in, int timeout)
{
  OSuite::psock::psockset_t *v3; // rbx
  int v4; // er10
  OSuite::psock::psockset_t *v5; // rdi
  __int64 v6; // rdx
  __int64 v7; // r9
  OSuite::psock::psocksetmember_t *v8; // r8
  OSuite::psock::psock_private *v9; // rax
  const struct timeval *v10; // rcx
  int v11; // eax
  int v13; // [rsp+30h] [rbp-248h]
  int v14; // [rsp+34h] [rbp-244h]
  fd_set writefds; // [rsp+40h] [rbp-238h]

  v3 = in;
  v4 = timeout;
  v5 = out;
  writefds.fd_count = in->count;
  v6 = 0i64;
  v7 = (signed int)writefds.fd_count;
  if ( (signed int)writefds.fd_count > 0 )
  {
    v8 = v3->array;
    do
    {
      v9 = v8->socket;
      ++v6;
      ++v8;
      *((_QWORD *)&writefds.fd_count + v6) = v9->socket;
    }
    while ( v6 < v7 );
  }
  v10 = (const struct timeval *)&v13;
  v13 = v4 / 1000;
  if ( v4 == -1 )
    v10 = 0i64;
  v14 = 1000 * (v4 % 1000);
  v11 = select(0, 0i64, &writefds, 0i64, v10);
  if ( v11 == -1 )
    return 1i64;
  if ( !v11 )
    return 3i64;
  OSuite::psock::mkpsockset(v5, v3, &writefds);
  return 0i64;
}

// File Line: 1089
// RVA: 0xEEE36C
char __fastcall OSuite::psock::settimeout(OSuite::psock::psock_private *socket, int sendtimeout, int recvtimeout, int connecttimeout)
{
  int v4; // edi
  OSuite::psock::psock_private *v5; // rbx
  unsigned __int64 v7; // rcx
  SOCKET v8; // rcx
  char optval[4]; // [rsp+30h] [rbp-18h]

  v4 = sendtimeout;
  v5 = socket;
  if ( socket->async )
    return 0;
  socket->connect_timeout = connecttimeout;
  v7 = socket->socket;
  *(_DWORD *)optval = recvtimeout;
  setsockopt(v7, 0xFFFF, 4102, optval, 4);
  v8 = v5->socket;
  *(_DWORD *)optval = v4;
  setsockopt(v8, 0xFFFF, 4101, optval, 4);
  return 1;
}

// File Line: 1127
// RVA: 0xEECD8C
__int64 __fastcall OSuite::psock::getinterfaces(OSuite::psock::interface_t *dest, int count)
{
  int v2; // ebx
  OSuite::psock::interface_t *v3; // r14
  int v4; // ebp
  _MIB_IPADDRTABLE *v5; // rax
  _MIB_IPADDRTABLE *v6; // rsi
  _IP_ADAPTER_INFO *v7; // rax
  _IP_ADAPTER_INFO *v8; // r12
  unsigned int v9; // er15
  OSuite::psock::address_t *v10; // r13
  _IP_ADAPTER_INFO *v11; // rdx
  unsigned int v12; // eax
  signed __int64 v13; // rdi
  signed __int64 v14; // rbx
  __int64 v15; // rax
  OSuite::psock::address_t *v16; // r8
  OSuite::psock::address_t *v17; // r9
  signed __int64 v18; // r10
  char v19; // cl
  char v20; // dl
  int v22; // [rsp+20h] [rbp-38h]
  unsigned int v23; // [rsp+24h] [rbp-34h]

  v2 = count;
  v22 = count;
  v3 = dest;
  v4 = 0;
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
        if ( v3 )
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
                if ( v6->dwNumEntries > 0 )
                {
                  v10 = &v3->netmask.type;
                  do
                  {
                    if ( v4 >= v2 )
                      break;
                    v11 = v8;
                    while ( 1 )
                    {
                      if ( v6->table[v9].dwIndex == v11->Index )
                      {
                        v12 = v11->Type;
                        if ( v12 == 6 || v12 == 71 )
                          break;
                      }
                      v11 = v11->Next;
                      if ( !v11 )
                        goto LABEL_21;
                    }
                    v13 = (signed __int64)v6 + 24 * v9;
                    v14 = (signed __int64)&v3[v4];
                    memmove((void *)(v14 + 36), v11->Address, 6ui64);
                    memmove((void *)v14, (const void *)(v13 + 4), 4ui64);
                    *((_DWORD *)v10 - 3) = 0;
                    memmove((void *)(v14 + 12), (const void *)(v13 + 12), 4ui64);
                    v2 = v22;
                    *v10 = 0;
                    ++v4;
                    v10 += 11;
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
          v4 = v6->dwNumEntries;
        }
      }
      OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, v6);
    }
  }
  if ( v3 )
  {
    v15 = v4;
    if ( v4 > 0 )
    {
      v16 = &v3->broadcast.type;
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
        *v16 = 0;
        v16 += 11;
        --v15;
      }
      while ( v15 );
    }
  }
  return (unsigned int)v4;
}

// File Line: 1417
// RVA: 0xEEDC78
unsigned __int64 __fastcall OSuite::psock::platform::recv(OSuite::psock::psock_private *socket, void *buf, unsigned __int64 len)
{
  unsigned __int64 v3; // rdi
  OSuite::psock::psock_private *v4; // rbx
  void (__fastcall *v5)(OSuite::psock::err_t); // rax
  signed __int64 v6; // rcx
  int v7; // eax
  __int64 v8; // rsi
  int v10; // eax

  v3 = len;
  v4 = socket;
  if ( socket->state == 5 )
  {
    socket->lasterror = 4;
    v5 = OSuite::psock::g_ErrorCallback;
    if ( OSuite::psock::g_ErrorCallback )
    {
      v6 = 4i64;
LABEL_24:
      ((void (__fastcall *)(signed __int64, void *))v5)(v6, buf);
      return 0i64;
    }
    return 0i64;
  }
  v7 = recv(socket->socket, (char *)buf, len, 0);
  v8 = v7;
  if ( v7 <= 0 )
  {
    if ( !v7 )
    {
LABEL_12:
      v4->lasterror = 4;
      if ( OSuite::psock::g_ErrorCallback )
        OSuite::psock::g_ErrorCallback(ERR_CLOSED);
      v4->state = 5;
      return 0i64;
    }
    v10 = WSAGetLastError();
    if ( v10 != 10035 )
    {
      if ( v10 == 10040 )
      {
        v4->lasterror = 0;
        return v3;
      }
      if ( v10 <= 10052 )
        goto LABEL_28;
      if ( v10 <= 10054 )
        goto LABEL_12;
      if ( v10 != 10060 )
      {
LABEL_28:
        v4->lasterror = 1;
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
    v4->lasterror = 3;
    v5 = OSuite::psock::g_ErrorCallback;
    if ( OSuite::psock::g_ErrorCallback )
      goto LABEL_24;
    return 0i64;
  }
  if ( (unsigned int)(WSAGetLastError() - 10053) <= 1 )
  {
    v4->lasterror = 4;
    if ( OSuite::psock::g_ErrorCallback )
      OSuite::psock::g_ErrorCallback(ERR_CLOSED);
    v4->lasterror = 4;
    v4->state = 5;
  }
  else
  {
    v4->lasterror = 0;
  }
  return v8;
}

// File Line: 1482
// RVA: 0xEEE178
unsigned __int64 __fastcall OSuite::psock::platform::send(OSuite::psock::psock_private *socket, const void *buf, unsigned __int64 len)
{
  OSuite::psock::psock_private *v3; // rbx
  signed __int64 v4; // rcx
  unsigned __int64 result; // rax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  void (__fastcall *v9)(OSuite::psock::err_t); // rax

  v3 = socket;
  if ( socket->state == 5 )
    goto LABEL_2;
  LODWORD(result) = send(socket->socket, (const char *)buf, len, 0);
  if ( (_DWORD)result != -1 )
  {
    v3->lasterror = 0;
    return (signed int)result;
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
    v3->lasterror = v4;
    v9 = OSuite::psock::g_ErrorCallback;
    if ( OSuite::psock::g_ErrorCallback )
      goto LABEL_14;
    return 0i64;
  }
  v3->lasterror = 5;
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
char __fastcall OSuite::psock::platform::connect_statemachine(OSuite::psock::psock_private *socket, OSuite::psock::ipv4addr_t *addr, __int64 port)
{
  OSuite::psock::psock_private *v3; // rbx
  __int32 v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  signed __int64 v8; // rcx
  void (__fastcall *v9)(OSuite::psock::err_t); // rax
  int v11; // eax
  sockaddr_in sa; // [rsp+20h] [rbp-28h]

  v3 = socket;
  v4 = socket->state - 1;
  if ( !v4 )
  {
    if ( addr->type == 1 )
    {
      v3->lasterror = 2;
      v9 = OSuite::psock::g_ErrorCallback;
      if ( !OSuite::psock::g_ErrorCallback )
        return 0;
      v8 = 2i64;
      goto LABEL_10;
    }
    v3->state = 2;
    return 1;
  }
  v5 = v4 - 1;
  if ( !v5 )
  {
    OSuite::psock::mksockaddr(&sa, addr, port);
    OSuite::psock::waitwrite(v3, 100);
    if ( connect(v3->socket, (const struct sockaddr *)&sa, 16) >= 0 )
    {
LABEL_13:
      v3->state = 3;
      return 1;
    }
    if ( !v3->async )
      goto LABEL_8;
    v11 = WSAGetLastError();
    if ( v11 != 10022 )
    {
      if ( v11 <= 10034 )
        goto LABEL_8;
      if ( v11 > 10037 )
      {
        if ( v11 == 10056 )
          goto LABEL_13;
        if ( v11 != 10060 )
          goto LABEL_8;
      }
    }
    v3->lasterror = 3;
    return 1;
  }
  v6 = v5 - 1;
  if ( v6 )
  {
    v7 = v6 - 1;
    if ( v7 && v7 == 1 )
    {
      v8 = 4i64;
      v3->lasterror = 4;
      v9 = OSuite::psock::g_ErrorCallback;
      if ( OSuite::psock::g_ErrorCallback )
        goto LABEL_10;
      return 0;
    }
LABEL_8:
    v3->lasterror = 1;
    v9 = OSuite::psock::g_ErrorCallback;
    if ( OSuite::psock::g_ErrorCallback )
    {
      v8 = 1i64;
LABEL_10:
      ((void (__fastcall *)(signed __int64, OSuite::psock::ipv4addr_t *, __int64))v9)(v8, addr, port);
    }
    return 0;
  }
  return 1;
}

// File Line: 1701
// RVA: 0xEEC630
char __fastcall OSuite::psock::platform::connect(OSuite::psock::psock_private *socket, OSuite::psock::ipv4addr_t *addr, int port)
{
  int v3; // edi
  OSuite::psock::ipv4addr_t *v4; // rsi
  OSuite::psock::psock_private *v5; // rbx
  void (*v6)(void); // rax
  int v8; // ebp

  v3 = port;
  v4 = addr;
  v5 = socket;
  if ( socket->state == 5 )
  {
    socket->lasterror = 4;
    v6 = (void (*)(void))OSuite::psock::g_ErrorCallback;
    if ( OSuite::psock::g_ErrorCallback )
LABEL_3:
      v6();
    return 0;
  }
  if ( !socket->async )
  {
    v8 = clock();
    while ( OSuite::psock::platform::connect_statemachine(v5, v4, v3) )
    {
      if ( v5->state == 3 )
        goto LABEL_9;
      if ( v5->connect_timeout && clock() - v8 >= v5->connect_timeout )
      {
        v5->lasterror = 1;
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
  if ( v5->state != 3 )
  {
    v5->lasterror = 3;
    return 0;
  }
LABEL_9:
  v5->lasterror = 0;
  return 1;
}

