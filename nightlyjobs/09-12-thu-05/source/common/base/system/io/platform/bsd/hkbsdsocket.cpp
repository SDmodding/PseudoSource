// File Line: 60
// RVA: 0xC84DE0
void hkBsdNetworkInit(void)
{
  hkErrStream v0; // [rsp+20h] [rbp-3C8h]
  char buf; // [rsp+40h] [rbp-3A8h]
  WSAData WSAData; // [rsp+240h] [rbp-1A8h]

  if ( !g_defaultPlatformInitOnce.m_bool )
  {
    if ( WSAStartup_0(0x202u, &WSAData) == -1 )
    {
      hkErrStream::hkErrStream(&v0, &buf, 512);
      hkOstream::operator<<((hkOstream *)&v0.vfptr, "(Windows)WSAStartup failed with error!");
      if ( (unsigned int)hkError::messageError(840443384, &buf, "System\\Io\\Platform\\Bsd\\hkBsdSocket.cpp", 83) )
        __debugbreak();
      hkOstream::~hkOstream((hkOstream *)&v0.vfptr);
    }
    g_defaultPlatformInitOnce.m_bool = 1;
  }
}

// File Line: 98
// RVA: 0xC84E70
void hkBsdNetworkQuit(void)
{
  ;
}

// File Line: 104
// RVA: 0xC845D0
void __fastcall hkBsdSocket::hkBsdSocket(hkBsdSocket *this, unsigned __int64 s)
{
  unsigned __int64 v2; // rbx
  hkBsdSocket *v3; // rdi
  hkResult result; // [rsp+30h] [rbp+8h]

  v2 = s;
  v3 = this;
  hkSocket::hkSocket((hkSocket *)&this->vfptr);
  v3->m_socket = v2;
  v3->vfptr = (hkBaseObjectVtbl *)&hkBsdSocket::`vftable;
  if ( v2 == -1i64 )
    hkBsdSocket::createSocket(v3, &result);
}

// File Line: 112
// RVA: 0xC84660
hkBool *__fastcall hkBsdSocket::isOk(hkBsdSocket *this, hkBool *result)
{
  result->m_bool = this->m_socket != -1i64;
  return result;
}

// File Line: 117
// RVA: 0xC84680
void __fastcall hkBsdSocket::close(hkBsdSocket *this)
{
  hkBsdSocket *v1; // rbx
  unsigned __int64 v2; // rcx

  v1 = this;
  v2 = this->m_socket;
  if ( v2 != -1i64 )
  {
    closesocket_0(v2);
    v1->m_socket = -1i64;
  }
}

// File Line: 130
// RVA: 0xC84D80
hkResult *__fastcall hkBsdSocket::createSocket(hkBsdSocket *this, hkResult *result)
{
  hkResult *v2; // rdi
  hkBsdSocket *v3; // rbx
  SOCKET v4; // rax
  bool v5; // zf
  hkResult *v6; // rax

  v2 = result;
  v3 = this;
  ((void (*)(void))this->vfptr[2].__vecDelDtor)();
  v4 = socket_0(2, 1, 0);
  v3->m_socket = v4;
  v5 = v4 == -1i64;
  v6 = v2;
  v2->m_enum = v5 != 0;
  return v6;
}

// File Line: 146
// RVA: 0xC84620
void __fastcall hkBsdSocket::~hkBsdSocket(hkBsdSocket *this)
{
  hkBsdSocket *v1; // rbx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkBsdSocket::`vftable;
  hkBsdSocket::close(this);
  v1->m_writer.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  v1->m_reader.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 152
// RVA: 0xC846B0
int __fastcall hkBsdSocket::read(hkBsdSocket *this, void *buf, int nbytes)
{
  hkBsdSocket *v3; // rbx
  unsigned __int64 v4; // rcx
  int result; // eax

  v3 = this;
  v4 = this->m_socket;
  if ( v4 != -1i64 )
  {
    result = recv_0(v4, (char *)buf, nbytes, 0);
    if ( result >= 1 )
      return result;
    if ( WSAGetLastError_0() != 10035 )
      ((void (__fastcall *)(hkBsdSocket *))v3->vfptr[2].__vecDelDtor)(v3);
  }
  return 0;
}

// File Line: 173
// RVA: 0xC84700
int __fastcall hkBsdSocket::write(hkBsdSocket *this, const void *buf, int nbytes)
{
  hkBsdSocket *v3; // rbx
  unsigned __int64 v4; // rcx
  int result; // eax

  v3 = this;
  v4 = this->m_socket;
  if ( v4 != -1i64 )
  {
    result = send_0(v4, (const char *)buf, nbytes, 0);
    if ( result >= 1 )
      return result;
    if ( WSAGetLastError_0() != 10035 )
      ((void (__fastcall *)(hkBsdSocket *))v3->vfptr[2].__vecDelDtor)(v3);
  }
  return 0;
}

// File Line: 197
// RVA: 0xC84E80
hkBool *__fastcall hkIsDigit(hkBool *result, int c)
{
  result->m_bool = (unsigned int)(c - 48) <= 9;
  return result;
}

// File Line: 202
// RVA: 0xC84750
hkResult *__fastcall hkBsdSocket::connect(hkBsdSocket *this, hkResult *result, const char *servername, int portNumber)
{
  hkResult *v4; // rdi
  const char *v5; // rbp
  hkBsdSocket *v6; // rsi
  u_short v7; // bx
  u_short v8; // ax
  int v9; // edx
  struct hostent *v10; // rax
  __int16 dst; // [rsp+20h] [rbp-18h]
  u_short v13; // [rsp+22h] [rbp-16h]
  unsigned int v14; // [rsp+24h] [rbp-14h]
  hkBool resulta; // [rsp+50h] [rbp+18h]

  v4 = result;
  v5 = servername;
  v6 = this;
  v7 = portNumber;
  hkString::memSet(&dst, 0, 16);
  dst = 2;
  v8 = htons_0(v7);
  v9 = *v5;
  v13 = v8;
  if ( hkIsDigit(&resulta, v9)->m_bool )
  {
    v14 = inet_addr_0(v5);
  }
  else
  {
    v10 = gethostbyname_0(v5);
    if ( !v10 )
    {
LABEL_11:
      v4->m_enum = 1;
      return v4;
    }
    hkString::memCpy(&v14, *(const void **)v10->h_addr_list, v10->h_length);
  }
  if ( v6->m_socket == -1i64 && hkBsdSocket::createSocket(v6, (hkResult *)&resulta)->m_enum )
    goto LABEL_11;
  if ( connect_0(v6->m_socket, (const struct sockaddr *)&dst, 16) < 0 && WSAGetLastError_0() != 10035 )
  {
    ((void (__fastcall *)(hkBsdSocket *))v6->vfptr[2].__vecDelDtor)(v6);
    goto LABEL_11;
  }
  v4->m_enum = 0;
  return v4;
}

// File Line: 269
// RVA: 0xC84850
hkResult *__fastcall hkBsdSocket::asyncSelect(hkBsdSocket *this, hkResult *result, void *notificationHandle, unsigned int message, hkSocket::SOCKET_EVENTS events)
{
  hkResult *v5; // rbx
  bool v6; // zf
  hkResult *v7; // rax

  v5 = result;
  v6 = WSAAsyncSelect_0(this->m_socket, (HWND)notificationHandle, message, events & 3 | 4 * (events & 0xC)) == 0;
  v7 = v5;
  v5->m_enum = !v6;
  return v7;
}

// File Line: 311
// RVA: 0xC84920
hkResult *__fastcall hkBsdSocket::listen(hkBsdSocket *this, hkResult *result, int port)
{
  hkResult *v3; // rbx
  int v4; // esi
  hkBsdSocket *v5; // rdi
  u_short v6; // ax
  SOCKET v7; // rcx
  hkOstream *v8; // rax
  hkOstream *v9; // rax
  hkOstream *v10; // rax
  int v11; // er8
  hkResult resulta; // [rsp+30h] [rbp-D0h]
  struct sockaddr name; // [rsp+38h] [rbp-C8h]
  hkErrStream v15; // [rsp+48h] [rbp-B8h]
  hkStringBuf str; // [rsp+60h] [rbp-A0h]
  char s; // [rsp+F0h] [rbp-10h]
  char buf; // [rsp+1F0h] [rbp+F0h]
  int optval; // [rsp+428h] [rbp+328h]

  v3 = result;
  v4 = port;
  v5 = this;
  if ( hkBsdSocket::createSocket(this, &resulta)->m_enum )
  {
    v3->m_enum = 1;
  }
  else
  {
    name.sa_family = 2;
    *(_DWORD *)&name.sa_data[2] = 0;
    v6 = htons_0(v4);
    v7 = v5->m_socket;
    *(_WORD *)name.sa_data = v6;
    optval = 1;
    setsockopt_0(v7, 0xFFFF, 4, (const char *)&optval, 4);
    if ( bind_0(v5->m_socket, &name, 16) == -1 || listen_0(v5->m_socket, 2) == -1 )
    {
      ((void (__fastcall *)(hkBsdSocket *))v5->vfptr[2].__vecDelDtor)(v5);
      v3->m_enum = 1;
    }
    else
    {
      str.m_string.m_capacityAndFlags = -2147483520;
      str.m_string.m_size = 1;
      str.m_string.m_storage[0] = 0;
      str.m_string.m_data = str.m_string.m_storage;
      gethostname_0(&s, 256);
      hkStringBuf::operator=(&str, &s);
      hkErrStream::hkErrStream(&v15, &buf, 512);
      v8 = hkOstream::operator<<((hkOstream *)&v15.vfptr, "Listening on host[");
      v9 = hkOstream::operator<<(v8, &str);
      v10 = hkOstream::operator<<(v9, "] port ");
      hkOstream::operator<<(v10, v4, (int)v10);
      hkError::messageReport(-1, &buf, "System\\Io\\Platform\\Bsd\\hkBsdSocket.cpp", 423);
      hkOstream::~hkOstream((hkOstream *)&v15.vfptr);
      v11 = str.m_string.m_capacityAndFlags;
      v3->m_enum = 0;
      str.m_string.m_size = 0;
      if ( v11 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          str.m_string.m_data,
          v11 & 0x3FFFFFFF);
    }
  }
  return v3;
}

// File Line: 428
// RVA: 0xC848B0
bool __fastcall hkBsdSocket::canRead(hkBsdSocket *this)
{
  unsigned __int64 v1; // rax
  fd_set readfds; // [rsp+30h] [rbp-218h]
  __int64 timeout; // [rsp+250h] [rbp+8h]

  v1 = this->m_socket;
  if ( v1 == -1i64 )
    return 0;
  readfds.fd_array[0] = this->m_socket;
  readfds.fd_count = 1;
  return select_0(v1 + 1, &readfds, 0i64, 0i64, (const struct timeval *)&timeout) > 0;
}

// File Line: 444
// RVA: 0xC84B00
hkSocket *__fastcall hkBsdSocket::pollForNewClient(hkBsdSocket *this)
{
  unsigned __int64 v1; // rax
  hkBsdSocket *v2; // rbx
  SOCKET v3; // rcx
  SOCKET v4; // rdi
  unsigned int v5; // ebx
  char *v6; // rax
  _QWORD **v8; // rax
  hkBsdSocket *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rbx
  struct sockaddr addr; // [rsp+30h] [rbp-D0h]
  hkErrStream v13; // [rsp+40h] [rbp-C0h]
  hkStringBuf str; // [rsp+60h] [rbp-A0h]
  fd_set readfds; // [rsp+F0h] [rbp-10h]
  fd_set exceptfds; // [rsp+300h] [rbp+200h]
  char buf; // [rsp+510h] [rbp+410h]
  int addrlen; // [rsp+730h] [rbp+630h]
  int optval; // [rsp+738h] [rbp+638h]
  struct timeval timeout; // [rsp+740h] [rbp+640h]

  v1 = this->m_socket;
  v2 = this;
  if ( v1 == -1i64 )
    return 0i64;
  readfds.fd_array[0] = this->m_socket;
  exceptfds.fd_array[0] = v1;
  readfds.fd_count = 1;
  exceptfds.fd_count = 1;
  timeout = 0i64;
  if ( select_0(v1 + 1, &readfds, 0i64, &exceptfds, &timeout) <= 0 || !_WSAFDIsSet_0(v2->m_socket, &readfds) )
    return 0i64;
  v3 = v2->m_socket;
  addrlen = 16;
  v4 = accept_0(v3, &addr, &addrlen);
  str.m_string.m_capacityAndFlags = -2147483520;
  str.m_string.m_size = 1;
  str.m_string.m_storage[0] = 0;
  str.m_string.m_data = str.m_string.m_storage;
  v5 = ntohs_0(*(u_short *)addr.sa_data);
  v6 = inet_ntoa_0(*(struct in_addr *)&addr.sa_data[2]);
  hkStringBuf::printf(&str, "Socket got connection from [%s:%d]\n", v6, v5);
  hkErrStream::hkErrStream(&v13, &buf, 512);
  hkOstream::operator<<((hkOstream *)&v13.vfptr, &str);
  hkError::messageReport(-1, &buf, "System\\Io\\Platform\\Bsd\\hkBsdSocket.cpp", 478);
  hkOstream::~hkOstream((hkOstream *)&v13.vfptr);
  if ( v4 == -1i64 )
  {
    str.m_string.m_size = 0;
    if ( str.m_string.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        str.m_string.m_data,
        str.m_string.m_capacityAndFlags & 0x3FFFFFFF);
    return 0i64;
  }
  optval = 1;
  setsockopt_0(v4, 6, 1, (const char *)&optval, 4);
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkBsdSocket *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 72i64);
  if ( v9 )
  {
    hkBsdSocket::hkBsdSocket(v9, v4);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  str.m_string.m_size = 0;
  if ( str.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      str.m_string.m_data,
      str.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return (hkSocket *)v11;
}

// File Line: 504
// RVA: 0xC84D30
hkResult *__fastcall hkBsdSocket::setBlocking(hkBsdSocket *this, hkResult *result, hkBool blocking)
{
  unsigned __int64 v3; // rcx
  hkResult *v4; // rdi
  bool v5; // zf
  hkResult *v6; // rax
  u_long argp; // [rsp+30h] [rbp+8h]

  v3 = this->m_socket;
  v4 = result;
  argp = blocking.m_bool == 0;
  v5 = ioctlsocket_0(v3, -2147195266, &argp) == 0;
  v6 = v4;
  v4->m_enum = !v5;
  return v6;
}

