// File Line: 36
// RVA: 0xEDE178
void __fastcall OSuite::ZSocket::ZSocket(OSuite::ZSocket *this)
{
  OSuite::ZSocket *v1; // rbx

  this->m_socket = 0i64;
  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZSocket::`vftable';
  OSuite::ZString::ZString(&this->m_sHost);
  v1->m_operationRetry = 0i64;
  v1->m_nBytesSent = 0i64;
  v1->m_nBytesReceived = 0i64;
  v1->m_state = 0;
}

// File Line: 61
// RVA: 0xEDE1B8
void __fastcall OSuite::ZSocket::~ZSocket(OSuite::ZSocket *this)
{
  OSuite::ZSocket *v1; // rbx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZSocket::`vftable';
  if ( OSuite::ZSocket::GetLastError(this) & 0xFFFFFFF7 || v1->m_state )
    OSuite::ZSocket::Close(v1);
  OSuite::psock::free(v1->m_socket);
  v1->m_socket = 0i64;
  OSuite::ZString::~ZString(&v1->m_sHost);
}

// File Line: 74
// RVA: 0xEDE518
char __fastcall OSuite::ZSocket::Open(OSuite::ZSocket *this, bool bSecure, bool bAsynch)
{
  bool v3; // si
  bool v4; // bp
  OSuite::ZSocket *v5; // rdi

  v3 = bAsynch;
  v4 = bSecure;
  v5 = this;
  if ( this->m_state )
    OSuite::ZSocket::Close(this);
  OSuite::psock::create(&v5->m_socket, PROT_TCP, v3, v4);
  if ( !v5->m_socket )
    return 0;
  v5->m_state = 1;
  return 1;
}

// File Line: 94
// RVA: 0xEDE284
void __fastcall OSuite::ZSocket::Close(OSuite::ZSocket *this)
{
  OSuite::ZSocket *v1; // rbx
  OSuite::psock::psock_private *v2; // rcx
  OSuite::psock::psock_private *v3; // rcx
  OSuite::ZString that; // [rsp+20h] [rbp-28h]

  v1 = this;
  if ( OSuite::ZSocket::GetLastError(this) & 0xFFFFFFF7 )
  {
    v2 = v1->m_socket;
    if ( v2 )
      OSuite::psock::IsSocketValid(v2);
  }
  v3 = v1->m_socket;
  if ( v3 )
    OSuite::psock::close(v3);
  v1->m_state = 0;
  OSuite::ZString::ZString(&that, &customWorldMapCaption);
  OSuite::ZString::operator=(&v1->m_sHost, &that);
  OSuite::ZString::~ZString(&that);
  v1->m_nPort = 0;
  v1->m_nBytesSent = 0i64;
  v1->m_nBytesReceived = 0i64;
}

// File Line: 119
// RVA: 0xEDE234
void __fastcall OSuite::ZSocket::Abort(OSuite::ZSocket *this, OSuite::psock::err_t err)
{
  OSuite::ZSocket *v2; // rbx
  OSuite::psock::psock_private *v3; // rcx
  OSuite::psock::err_t v4; // edi
  BOOL v5; // eax

  v2 = this;
  v3 = this->m_socket;
  v4 = err;
  if ( v3 && OSuite::psock::IsSocketValid(v3) )
    OSuite::psock::abort(v2->m_socket, v4);
  v5 = (v2->m_state & 5) == 5;
  v2->m_operationRetry = 0i64;
  v2->m_state = v5;
}

// File Line: 137
// RVA: 0xEDE4A4
OSuite::psock::ipv4addr_t *__fastcall OSuite::ZSocket::GetResolveAddr(OSuite::ZSocket *this, OSuite::psock::ipv4addr_t *result)
{
  OSuite::psock::ipv4addr_t *v2; // rdi
  OSuite::ZSocket *v3; // rbx
  const char *v4; // rax

  v2 = result;
  v3 = this;
  memset(result, 0, 0xCui64);
  if ( OSuite::ZString::Count(&v3->m_sHost) )
  {
    v4 = OSuite::ZString::c_str(&v3->m_sHost);
    OSuite::psock::getaddrbyname(v2, v4);
  }
  return v2;
}

// File Line: 157
// RVA: 0xEDE2F8
char __fastcall OSuite::ZSocket::Connect(OSuite::ZSocket *this, const char *sHost, int nPort, bool bSecure, bool bAsynch, int nConnectTimeoutMs, int nSendRecvTimeoutMs)
{
  bool v7; // r14
  int v8; // ebp
  const char *v9; // rsi
  OSuite::ZSocket *v10; // rbx
  OSuite::psock::psock_private *v11; // rcx
  char v12; // al
  OSuite::ZString that; // [rsp+28h] [rbp-60h]
  OSuite::psock::ipv4addr_t result; // [rsp+40h] [rbp-48h]

  v7 = bSecure;
  v8 = nPort;
  v9 = sHost;
  v10 = this;
  if ( !OSuite::psock::connectedToNetwork()
    || (v10->m_state & 5) == 5
    || !OSuite::psock::getaddrbyname(&result, v9)
    || !(v10->m_state & 1) && !OSuite::ZSocket::Open(v10, v7, bAsynch) )
  {
    goto LABEL_18;
  }
  if ( !bAsynch && v10->m_state & 1 )
    OSuite::psock::settimeout(v10->m_socket, nSendRecvTimeoutMs, nSendRecvTimeoutMs, nConnectTimeoutMs);
  v11 = v10->m_socket;
  v10->m_state = 3;
  if ( OSuite::psock::connect(v11, &result, v8) )
  {
    v10->m_state = 5;
    OSuite::ZString::ZString(&that, v9);
    OSuite::ZString::operator=(&v10->m_sHost, &that);
    OSuite::ZString::~ZString(&that);
    v10->m_operationRetry = 0i64;
    v10->m_nPort = v8;
    v12 = 1;
  }
  else
  {
LABEL_18:
    if ( ++v10->m_operationRetry < 0x96 )
    {
      if ( OSuite::ZSocket::GetLastError(v10) & 0xFFFFFFF7 )
        OSuite::ZSocket::Close(v10);
    }
    else
    {
      OSuite::ZSocket::Abort(v10, ERR_FAILED);
    }
    v12 = 0;
  }
  return v12;
}

// File Line: 200
// RVA: 0xEDE9AC
char __fastcall OSuite::ZSocket::VerifyConnection(OSuite::ZSocket *this)
{
  OSuite::ZSocket *v1; // rbx
  OSuite::psock::err_t v2; // eax
  OSuite::psock::err_t v3; // eax

  v1 = this;
  if ( (this->m_state & 5) != 5 )
    return 0;
  v2 = OSuite::psock::waitread(this->m_socket, 0);
  if ( v2 && v2 != 3 || (v3 = OSuite::psock::waitwrite(v1->m_socket, 0)) != 0 && v3 != 3 )
  {
    OSuite::ZSocket::Close(v1);
    return 0;
  }
  return 1;
}

// File Line: 222
// RVA: 0xEDE98C
void __fastcall OSuite::ZSocket::SetTimeout(OSuite::ZSocket *this, int nConnectTimeoutMs, int nSendRecvTimeoutMs)
{
  if ( this->m_state & 1 )
    OSuite::psock::settimeout(this->m_socket, nSendRecvTimeoutMs, nSendRecvTimeoutMs, nConnectTimeoutMs);
}

// File Line: 277
// RVA: 0xEDE8A0
char __fastcall OSuite::ZSocket::SendBuffer(OSuite::ZSocket *this, const void *pBuffer, unsigned __int64 nLength)
{
  unsigned __int64 v3; // rdi
  char *v4; // rsi
  OSuite::ZSocket *v5; // rbx
  signed int v7; // ebp
  unsigned __int64 v8; // rax

  v3 = nLength;
  v4 = (char *)pBuffer;
  v5 = this;
  if ( (this->m_state & 5) != 5 )
    return 0;
  this->m_operationRetry = 0i64;
  if ( nLength )
  {
    while ( v5->m_operationRetry < 0x96 )
    {
      v7 = v3;
      if ( v3 > 0x8000 )
        v7 = 0x8000;
      if ( OSuite::psock::waitwrite(v5->m_socket, 100) || (v8 = OSuite::psock::send(v5->m_socket, v4, v7)) == 0 )
      {
        ++v5->m_operationRetry;
        if ( OSuite::ZSocket::GetLastError(v5) & 0xFFFFFFF7 )
        {
          OSuite::ZSocket::Close(v5);
          return 0;
        }
      }
      else
      {
        v5->m_nBytesSent += v8;
        v4 += v8;
        v3 -= v8;
        v5->m_operationRetry = 0i64;
      }
      if ( !v3 )
        goto LABEL_12;
    }
    goto LABEL_13;
  }
LABEL_12:
  if ( v5->m_operationRetry >= 0x96 )
  {
LABEL_13:
    OSuite::ZSocket::Abort(v5, ERR_FAILED);
    return 0;
  }
  return 1;
}

// File Line: 342
// RVA: 0xEDE758
char *__fastcall OSuite::ZSocket::ReceiveString(OSuite::ZSocket *this, char *pszString, unsigned __int64 nMaxLength)
{
  unsigned __int64 v3; // rbp
  char *v4; // rbx
  OSuite::ZSocket *v5; // rsi
  char *result; // rax
  char *v7; // rdi
  bool v8; // cf
  bool i; // zf
  int v10; // eax

  v3 = nMaxLength;
  v4 = pszString;
  v5 = this;
  if ( (this->m_state & 5) != 5 )
    return 0i64;
  this->m_operationRetry = 0i64;
  v7 = pszString;
  v8 = nMaxLength < 1;
  for ( i = nMaxLength == 1; !v8 && !i && v5->m_operationRetry < 0x96; i = v3 == 1 )
  {
    v10 = OSuite::ZSocket::ReceiveByte(v5);
    if ( v10 >= 0 )
    {
      if ( v10 != 13 )
      {
        *v4 = v10;
        --v3;
        ++v4;
        if ( v10 == 10 )
          break;
      }
    }
    else if ( OSuite::ZSocket::GetLastError(v5) & 0xFFFFFFF7 )
    {
      if ( v4 == v7 )
        return 0i64;
      break;
    }
    v8 = v3 < 1;
  }
  result = v7;
  *v4 = 0;
  return result;
}

// File Line: 385
// RVA: 0xEDE708
signed __int64 __fastcall OSuite::ZSocket::ReceiveByte(OSuite::ZSocket *this)
{
  signed __int64 result; // rax
  unsigned __int8 pDest; // [rsp+20h] [rbp-18h]

  if ( (this->m_state & 5) != 5 || OSuite::ZSocket::Recv(this, &pDest, 1ui64) != 1 )
    result = 0xFFFFFFFFi64;
  else
    result = pDest;
  return result;
}

// File Line: 406
// RVA: 0xEDE680
__int64 __fastcall OSuite::ZSocket::ReceiveBuffer(OSuite::ZSocket *this, void *pBuffer, unsigned __int64 nLength)
{
  unsigned __int64 v3; // rdi
  char *v4; // rbp
  OSuite::ZSocket *v5; // rsi
  __int64 v7; // rbx
  bool i; // zf
  unsigned __int64 v9; // rax

  v3 = nLength;
  v4 = (char *)pBuffer;
  v5 = this;
  if ( (this->m_state & 5) != 5 )
    return 0i64;
  v7 = 0i64;
  this->m_operationRetry = 0i64;
  for ( i = nLength == 0; !i && v5->m_operationRetry < 0x96; i = v3 == 0 )
  {
    v9 = OSuite::ZSocket::Recv(v5, v4, v3);
    if ( v9 )
    {
      v4 += v9;
      v7 += v9;
      v3 -= v9;
    }
    else if ( OSuite::ZSocket::GetLastError(v5) & 0xFFFFFFF7 )
    {
      return v7;
    }
  }
  return v7;
}

// File Line: 451
// RVA: 0xEDE50C
bool __fastcall OSuite::ZSocket::MatchSecureHostName(OSuite::ZSocket *this, const char *sHost)
{
  return OSuite::psock::tls_matchcerthost(this->m_socket, sHost);
}

// File Line: 460
// RVA: 0xEDE46C
signed __int64 __fastcall OSuite::ZSocket::GetProxyType()
{
  OSuite::psock::proxy_t v0; // eax
  int v1; // eax
  int v2; // eax

  v0 = OSuite::psock::getproxytype();
  if ( v0 )
  {
    v1 = v0 - 1;
    if ( !v1 )
      return 1i64;
    v2 = v1 - 1;
    if ( !v2 )
      return 2i64;
    if ( v2 == 1 )
      return 3i64;
  }
  return 0i64;
}

// File Line: 478
// RVA: 0xEDE45C
const char *__fastcall OSuite::ZSocket::GetProxyHost()
{
  return OSuite::psock::getproxyhost();
}

// File Line: 483
// RVA: 0xEDE464
int __fastcall OSuite::ZSocket::GetProxyPort()
{
  return OSuite::psock::getproxyport();
}

// File Line: 545
// RVA: 0xEDE4F4
bool __fastcall OSuite::ZSocket::HasFatalError(OSuite::ZSocket *this)
{
  return (OSuite::ZSocket::GetLastError(this) & 0xFFFFFFF7) != 0;
}

// File Line: 553
// RVA: 0xEDE434
OSuite::ZError::EError __fastcall OSuite::ZSocket::GetLastError(OSuite::ZSocket *this)
{
  OSuite::psock::psock_private *v1; // rcx
  OSuite::psock::err_t v3; // eax
  char *details; // [rsp+30h] [rbp+8h]

  v1 = this->m_socket;
  if ( !v1 )
    return 22;
  v3 = OSuite::psock::lasterror(v1);
  return OSuite::ZSocket::PSockErrorToOsError(v3, (const char **)&details);
}

// File Line: 562
// RVA: 0xEDE580
signed __int64 __fastcall OSuite::ZSocket::PSockErrorToOsError(OSuite::psock::err_t error, const char **details)
{
  __int32 v2; // ecx
  int v3; // ecx
  int v4; // ecx
  const char *v6; // rax
  __int32 v7; // ecx
  int v8; // ecx
  int v9; // ecx

  *details = &customWorldMapCaption;
  if ( (signed int)error <= 5 )
  {
    if ( error == 5 )
    {
      v6 = "Message to big";
    }
    else
    {
      if ( error == ERR_OK )
        return 0i64;
      v2 = error - 1;
      if ( !v2 )
        return 16i64;
      v3 = v2 - 1;
      if ( v3 )
      {
        v4 = v3 - 1;
        if ( !v4 )
        {
          *details = "Timeout error (or \"wouldblock\" for asynch communication)";
          return 8i64;
        }
        if ( v4 == 1 )
          return 22i64;
        return 1i64;
      }
      v6 = "Argument error";
    }
    goto LABEL_23;
  }
  v7 = error - 6;
  if ( !v7 )
  {
    v6 = "X509 certificate not trusted";
    goto LABEL_23;
  }
  v8 = v7 - 1;
  if ( !v8 )
  {
    v6 = "X509 certificate invalid date";
    goto LABEL_23;
  }
  v9 = v8 - 1;
  if ( !v9 )
  {
    v6 = "Invalid X509 certificate";
LABEL_23:
    *details = v6;
    return 23i64;
  }
  if ( v9 != 1 )
    return 1i64;
  *details = "TLS fail to connect";
  return 9i64;
}

// File Line: 600
// RVA: 0x15D8B58
void (__fastcall *dynamic_initializer_for__OSuite::ZSocket::m_staticSocketInitializer__())(OSuite::psock::err_t psockError)
{
  void (__fastcall *result)(OSuite::psock::err_t); // rax

  result = OSuite::ZSocket::StaticSocketInitializer::PSockInternalErrorCallback;
  OSuite::psock::g_ErrorCallback = OSuite::ZSocket::StaticSocketInitializer::PSockInternalErrorCallback;
  return result;
}

// File Line: 608
// RVA: 0xEDE620
void __fastcall OSuite::ZSocket::StaticSocketInitializer::PSockInternalErrorCallback(OSuite::psock::err_t psockError)
{
  OSuite::ZError::EError v1; // edi
  OSuite::ZError *v2; // rax
  OSuite::ZString v3; // [rsp+20h] [rbp-28h]
  char *details; // [rsp+58h] [rbp+10h]

  details = 0i64;
  v1 = (unsigned int)OSuite::ZSocket::PSockErrorToOsError(psockError, (const char **)&details);
  OSuite::ZString::ZString(&v3, details);
  v2 = OSuite::TSingleton<OSuite::ZError>::Object();
  OSuite::ZError::SetThreadLastError(v2, v1, &v3, (v1 & 0xFFFFFFF7) != 0);
  OSuite::ZString::~ZString(&v3);
}

// File Line: 617
// RVA: 0xEDE7F0
unsigned __int64 __fastcall OSuite::ZSocket::Recv(OSuite::ZSocket *this, void *pDest, unsigned __int64 nLength)
{
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rbp
  void *v5; // rsi
  OSuite::ZSocket *v6; // rbx

  v3 = 0i64;
  v4 = nLength;
  v5 = pDest;
  v6 = this;
  if ( pDest )
  {
    this->m_state = 21;
    if ( OSuite::psock::waitread(this->m_socket, 100) == ERR_OK )
      v3 = OSuite::psock::recv(v6->m_socket, v5, v4);
    v6->m_state = 5;
    if ( OSuite::ZSocket::GetLastError(v6) & 0xFFFFFFF7 )
    {
      OSuite::ZSocket::Close(v6);
      return v3;
    }
    if ( v3 )
      v6->m_operationRetry = 0i64;
    else
      ++v6->m_operationRetry;
  }
  if ( v6->m_operationRetry >= 0x96 )
    OSuite::ZSocket::Abort(v6, ERR_FAILED);
  v6->m_nBytesReceived += v3;
  return v3;
}

