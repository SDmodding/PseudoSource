// File Line: 60
// RVA: 0xC84DE0
void hkBsdNetworkInit(void)
{
  hkErrStream v0; // [rsp+20h] [rbp-3C8h] BYREF
  char buf[512]; // [rsp+40h] [rbp-3A8h] BYREF
  WSAData WSAData; // [rsp+240h] [rbp-1A8h] BYREF

  if ( !g_defaultPlatformInitOnce.m_bool )
  {
    if ( WSAStartup_0(0x202u, &WSAData) == -1 )
    {
      hkErrStream::hkErrStream(&v0, buf, 512);
      hkOstream::operator<<(&v0, "(Windows)WSAStartup failed with error!");
      if ( (unsigned int)hkError::messageError(0x321825F8u, buf, "System\\Io\\Platform\\Bsd\\hkBsdSocket.cpp", 83) )
        __debugbreak();
      hkOstream::~hkOstream(&v0);
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
  hkResult result; // [rsp+30h] [rbp+8h] BYREF

  hkSocket::hkSocket(this);
  this->m_socket = s;
  this->vfptr = (hkBaseObjectVtbl *)&hkBsdSocket::`vftable;
  if ( s == -1i64 )
    hkBsdSocket::createSocket(this, &result);
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
  unsigned __int64 m_socket; // rcx

  m_socket = this->m_socket;
  if ( m_socket != -1i64 )
  {
    closesocket_0(m_socket);
    this->m_socket = -1i64;
  }
}

// File Line: 130
// RVA: 0xC84D80
hkResult *__fastcall hkBsdSocket::createSocket(hkBsdSocket *this, hkResult *result)
{
  unsigned __int64 v4; // rax
  bool v5; // zf
  hkResult *v6; // rax

  ((void (__fastcall *)(hkBsdSocket *))this->vfptr[2].__vecDelDtor)(this);
  v4 = socket_0(2, 1, 0);
  this->m_socket = v4;
  v5 = v4 == -1i64;
  v6 = result;
  result->m_enum = v5;
  return v6;
}

// File Line: 146
// RVA: 0xC84620
void __fastcall hkBsdSocket::~hkBsdSocket(hkBsdSocket *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkBsdSocket::`vftable;
  hkBsdSocket::close(this);
  this->m_writer.hkSocket::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  this->m_reader.hkSocket::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 152
// RVA: 0xC846B0
int __fastcall hkBsdSocket::read(hkBsdSocket *this, char *buf, int nbytes)
{
  unsigned __int64 m_socket; // rcx
  int result; // eax

  m_socket = this->m_socket;
  if ( m_socket != -1i64 )
  {
    result = recv_0(m_socket, buf, nbytes, 0);
    if ( result >= 1 )
      return result;
    if ( WSAGetLastError_0() != 10035 )
      ((void (__fastcall *)(hkBsdSocket *))this->vfptr[2].__vecDelDtor)(this);
  }
  return 0;
}

// File Line: 173
// RVA: 0xC84700
int __fastcall hkBsdSocket::write(hkBsdSocket *this, const char *buf, int nbytes)
{
  unsigned __int64 m_socket; // rcx
  int result; // eax

  m_socket = this->m_socket;
  if ( m_socket != -1i64 )
  {
    result = send_0(m_socket, buf, nbytes, 0);
    if ( result >= 1 )
      return result;
    if ( WSAGetLastError_0() != 10035 )
      ((void (__fastcall *)(hkBsdSocket *))this->vfptr[2].__vecDelDtor)(this);
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
hkResult *__fastcall hkBsdSocket::connect(
        hkBsdSocket *this,
        hkResult *result,
        const char *servername,
        u_short portNumber)
{
  u_short v8; // ax
  int v9; // edx
  struct hostent *v10; // rax
  struct sockaddr dst; // [rsp+20h] [rbp-18h] BYREF
  hkResult resulta; // [rsp+50h] [rbp+18h] BYREF

  hkString::memSet(&dst, 0, 0x10u);
  dst.sa_family = 2;
  v8 = htons_0(portNumber);
  v9 = *servername;
  *(_WORD *)dst.sa_data = v8;
  if ( hkIsDigit((hkBool *)&resulta, v9)->m_bool )
  {
    *(_DWORD *)&dst.sa_data[2] = inet_addr_0(servername);
  }
  else
  {
    v10 = gethostbyname_0(servername);
    if ( !v10 )
    {
LABEL_11:
      result->m_enum = HK_FAILURE;
      return result;
    }
    hkString::memCpy(&dst.sa_data[2], *(const void **)v10->h_addr_list, v10->h_length);
  }
  if ( this->m_socket == -1i64 && hkBsdSocket::createSocket(this, &resulta)->m_enum )
    goto LABEL_11;
  if ( connect_0(this->m_socket, &dst, 16) < 0 && WSAGetLastError_0() != 10035 )
  {
    ((void (__fastcall *)(hkBsdSocket *))this->vfptr[2].__vecDelDtor)(this);
    goto LABEL_11;
  }
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 269
// RVA: 0xC84850
hkResult *__fastcall hkBsdSocket::asyncSelect(
        hkBsdSocket *this,
        hkResult *result,
        HWND notificationHandle,
        u_int message,
        hkSocket::SOCKET_EVENTS events)
{
  bool v6; // zf
  hkResult *v7; // rax

  v6 = WSAAsyncSelect_0(this->m_socket, notificationHandle, message, events & 3 | (4 * (events & 0xC))) == 0;
  v7 = result;
  result->m_enum = !v6;
  return v7;
}

// File Line: 311
// RVA: 0xC84920
hkResult *__fastcall hkBsdSocket::listen(hkBsdSocket *this, hkResult *result, unsigned int port)
{
  u_short v6; // ax
  unsigned __int64 m_socket; // rcx
  hkOstream *v8; // rax
  hkOstream *v9; // rax
  hkOstream *v10; // rax
  int m_capacityAndFlags; // r8d
  hkResult resulta; // [rsp+30h] [rbp-D0h] BYREF
  struct sockaddr name; // [rsp+38h] [rbp-C8h] BYREF
  hkErrStream v15; // [rsp+48h] [rbp-B8h] BYREF
  hkStringBuf str; // [rsp+60h] [rbp-A0h] BYREF
  char s[256]; // [rsp+F0h] [rbp-10h] BYREF
  char buf[528]; // [rsp+1F0h] [rbp+F0h] BYREF
  int optval; // [rsp+428h] [rbp+328h] BYREF

  if ( hkBsdSocket::createSocket(this, &resulta)->m_enum )
  {
    result->m_enum = HK_FAILURE;
  }
  else
  {
    name.sa_family = 2;
    *(_DWORD *)&name.sa_data[2] = 0;
    v6 = htons_0(port);
    m_socket = this->m_socket;
    *(_WORD *)name.sa_data = v6;
    optval = 1;
    setsockopt_0(m_socket, 0xFFFF, 4, (const char *)&optval, 4);
    if ( bind_0(this->m_socket, &name, 16) == -1 || listen_0(this->m_socket, 2) == -1 )
    {
      ((void (__fastcall *)(hkBsdSocket *))this->vfptr[2].__vecDelDtor)(this);
      result->m_enum = HK_FAILURE;
    }
    else
    {
      str.m_string.m_capacityAndFlags = -2147483520;
      str.m_string.m_size = 1;
      str.m_string.m_storage[0] = 0;
      str.m_string.m_data = str.m_string.m_storage;
      gethostname_0(s, 256);
      hkStringBuf::operator=(&str, s);
      hkErrStream::hkErrStream(&v15, buf, 512);
      v8 = hkOstream::operator<<(&v15, "Listening on host[");
      v9 = hkOstream::operator<<(v8, &str);
      v10 = hkOstream::operator<<(v9, "] port ");
      hkOstream::operator<<(v10, port);
      hkError::messageReport(0xFFFFFFFF, buf, "System\\Io\\Platform\\Bsd\\hkBsdSocket.cpp", 423);
      hkOstream::~hkOstream(&v15);
      m_capacityAndFlags = str.m_string.m_capacityAndFlags;
      result->m_enum = HK_SUCCESS;
      str.m_string.m_size = 0;
      if ( m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          str.m_string.m_data,
          m_capacityAndFlags & 0x3FFFFFFF);
    }
  }
  return result;
}

// File Line: 428
// RVA: 0xC848B0
bool __fastcall hkBsdSocket::canRead(hkBsdSocket *this)
{
  unsigned __int64 m_socket; // rax
  fd_set readfds; // [rsp+30h] [rbp-218h] BYREF
  struct timeval timeout; // [rsp+250h] [rbp+8h] BYREF

  m_socket = this->m_socket;
  if ( m_socket == -1i64 )
    return 0;
  readfds.fd_array[0] = this->m_socket;
  readfds.fd_count = 1;
  timeout = 0i64;
  return select_0(m_socket + 1, &readfds, 0i64, 0i64, &timeout) > 0;
}

// File Line: 444
// RVA: 0xC84B00
hkSocket *__fastcall hkBsdSocket::pollForNewClient(hkBsdSocket *this)
{
  unsigned __int64 m_socket; // rax
  unsigned __int64 v3; // rcx
  SOCKET v4; // rdi
  unsigned int v5; // ebx
  char *v6; // rax
  _QWORD **Value; // rax
  hkBsdSocket *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rbx
  struct sockaddr addr; // [rsp+30h] [rbp-D0h] BYREF
  hkErrStream v13; // [rsp+40h] [rbp-C0h] BYREF
  hkStringBuf str; // [rsp+60h] [rbp-A0h] BYREF
  fd_set readfds; // [rsp+F0h] [rbp-10h] BYREF
  fd_set exceptfds; // [rsp+300h] [rbp+200h] BYREF
  char buf[528]; // [rsp+510h] [rbp+410h] BYREF
  int addrlen; // [rsp+730h] [rbp+630h] BYREF
  int optval; // [rsp+738h] [rbp+638h] BYREF
  struct timeval timeout; // [rsp+740h] [rbp+640h] BYREF

  m_socket = this->m_socket;
  if ( m_socket == -1i64 )
    return 0i64;
  readfds.fd_array[0] = this->m_socket;
  exceptfds.fd_array[0] = m_socket;
  readfds.fd_count = 1;
  exceptfds.fd_count = 1;
  timeout = 0i64;
  if ( select_0(m_socket + 1, &readfds, 0i64, &exceptfds, &timeout) <= 0 || !_WSAFDIsSet_0(this->m_socket, &readfds) )
    return 0i64;
  v3 = this->m_socket;
  addrlen = 16;
  v4 = accept_0(v3, &addr, &addrlen);
  str.m_string.m_capacityAndFlags = -2147483520;
  str.m_string.m_size = 1;
  str.m_string.m_storage[0] = 0;
  str.m_string.m_data = str.m_string.m_storage;
  v5 = ntohs_0(*(u_short *)addr.sa_data);
  v6 = inet_ntoa_0(*(struct in_addr *)&addr.sa_data[2]);
  hkStringBuf::printf(&str, "Socket got connection from [%s:%d]\n", v6, v5);
  hkErrStream::hkErrStream(&v13, buf, 512);
  hkOstream::operator<<(&v13, &str);
  hkError::messageReport(0xFFFFFFFF, buf, "System\\Io\\Platform\\Bsd\\hkBsdSocket.cpp", 478);
  hkOstream::~hkOstream(&v13);
  if ( v4 == -1i64 )
  {
    str.m_string.m_size = 0;
    if ( str.m_string.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        str.m_string.m_data,
        str.m_string.m_capacityAndFlags & 0x3FFFFFFF);
    return 0i64;
  }
  optval = 1;
  setsockopt_0(v4, 6, 1, (const char *)&optval, 4);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkBsdSocket *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 72i64);
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
      &hkContainerTempAllocator::s_alloc,
      str.m_string.m_data,
      str.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return (hkSocket *)v11;
}

// File Line: 504
// RVA: 0xC84D30
hkResult *__fastcall hkBsdSocket::setBlocking(hkBsdSocket *this, hkResult *result, hkBool blocking)
{
  unsigned __int64 m_socket; // rcx
  bool v5; // zf
  hkResult *v6; // rax
  u_long argp; // [rsp+30h] [rbp+8h] BYREF

  m_socket = this->m_socket;
  argp = blocking.m_bool == 0;
  v5 = ioctlsocket_0(m_socket, -2147195266, &argp) == 0;
  v6 = result;
  result->m_enum = !v5;
  return v6;
}

