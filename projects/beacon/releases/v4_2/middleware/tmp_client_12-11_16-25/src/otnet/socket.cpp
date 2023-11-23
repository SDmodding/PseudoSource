// File Line: 36
// RVA: 0xEDE178
void __fastcall OSuite::ZSocket::ZSocket(OSuite::ZSocket *this)
{
  this->m_socket = 0i64;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZSocket::`vftable;
  OSuite::ZString::ZString(&this->m_sHost);
  this->m_operationRetry = 0i64;
  this->m_nBytesSent = 0i64;
  this->m_nBytesReceived = 0i64;
  this->m_state = ZSOCKSTATE_NONE;
}

// File Line: 61
// RVA: 0xEDE1B8
void __fastcall OSuite::ZSocket::~ZSocket(OSuite::ZSocket *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZSocket::`vftable;
  if ( (OSuite::ZSocket::GetLastError(this) & 0xFFFFFFF7) != 0 || this->m_state )
    OSuite::ZSocket::Close(this);
  OSuite::psock::free(this->m_socket);
  this->m_socket = 0i64;
  OSuite::ZString::~ZString(&this->m_sHost);
}

// File Line: 74
// RVA: 0xEDE518
char __fastcall OSuite::ZSocket::Open(OSuite::ZSocket *this, bool bSecure, bool bAsynch)
{
  if ( this->m_state )
    OSuite::ZSocket::Close(this);
  OSuite::psock::create(&this->m_socket, PROT_TCP, bAsynch, bSecure);
  if ( !this->m_socket )
    return 0;
  this->m_state = ZSOCKSTATE_OPENED;
  return 1;
}

// File Line: 94
// RVA: 0xEDE284
void __fastcall OSuite::ZSocket::Close(OSuite::ZSocket *this)
{
  OSuite::psock::psock_private *m_socket; // rcx
  OSuite::psock::psock_private *v3; // rcx
  OSuite::ZString that; // [rsp+20h] [rbp-28h] BYREF

  if ( (OSuite::ZSocket::GetLastError(this) & 0xFFFFFFF7) != 0 )
  {
    m_socket = this->m_socket;
    if ( m_socket )
      OSuite::psock::IsSocketValid(m_socket);
  }
  v3 = this->m_socket;
  if ( v3 )
    OSuite::psock::close(v3);
  this->m_state = ZSOCKSTATE_NONE;
  OSuite::ZString::ZString(&that, &customCaption);
  OSuite::ZString::operator=(&this->m_sHost, &that);
  OSuite::ZString::~ZString(&that);
  this->m_nPort = 0;
  this->m_nBytesSent = 0i64;
  this->m_nBytesReceived = 0i64;
}

// File Line: 119
// RVA: 0xEDE234
void __fastcall OSuite::ZSocket::Abort(OSuite::ZSocket *this, OSuite::psock::err_t err)
{
  OSuite::psock::psock_private *m_socket; // rcx
  BOOL v5; // eax

  m_socket = this->m_socket;
  if ( m_socket && OSuite::psock::IsSocketValid(m_socket) )
    OSuite::psock::abort(this->m_socket, err);
  v5 = (this->m_state & 5) == 5;
  this->m_operationRetry = 0i64;
  this->m_state = v5;
}

// File Line: 137
// RVA: 0xEDE4A4
OSuite::psock::ipv4addr_t *__fastcall OSuite::ZSocket::GetResolveAddr(
        OSuite::ZSocket *this,
        OSuite::psock::ipv4addr_t *result)
{
  const char *v4; // rax

  memset(result, 0, sizeof(OSuite::psock::ipv4addr_t));
  if ( OSuite::ZString::Count(&this->m_sHost) )
  {
    v4 = OSuite::ZString::c_str(&this->m_sHost);
    OSuite::psock::getaddrbyname(result, v4);
  }
  return result;
}

// File Line: 157
// RVA: 0xEDE2F8
char __fastcall OSuite::ZSocket::Connect(
        OSuite::ZSocket *this,
        const char *sHost,
        int nPort,
        bool bSecure,
        bool bAsynch,
        int nConnectTimeoutMs,
        int nSendRecvTimeoutMs)
{
  OSuite::psock::psock_private *m_socket; // rcx
  OSuite::ZString that; // [rsp+28h] [rbp-60h] BYREF
  OSuite::psock::ipv4addr_t result; // [rsp+40h] [rbp-48h] BYREF

  if ( !OSuite::psock::connectedToNetwork()
    || (this->m_state & 5) == 5
    || !OSuite::psock::getaddrbyname(&result, sHost)
    || (this->m_state & 1) == 0 && !OSuite::ZSocket::Open(this, bSecure, bAsynch) )
  {
    goto LABEL_11;
  }
  if ( !bAsynch && (this->m_state & 1) != 0 )
    OSuite::psock::settimeout(this->m_socket, nSendRecvTimeoutMs, nSendRecvTimeoutMs, nConnectTimeoutMs);
  m_socket = this->m_socket;
  this->m_state = ZSOCKSTATE_CONNECTING;
  if ( OSuite::psock::connect(m_socket, &result, nPort) )
  {
    this->m_state = ZSOCKSTATE_CONNECTED;
    OSuite::ZString::ZString(&that, sHost);
    OSuite::ZString::operator=(&this->m_sHost, &that);
    OSuite::ZString::~ZString(&that);
    this->m_operationRetry = 0i64;
    this->m_nPort = nPort;
    return 1;
  }
  else
  {
LABEL_11:
    if ( ++this->m_operationRetry < 0x96 )
    {
      if ( (OSuite::ZSocket::GetLastError(this) & 0xFFFFFFF7) != 0 )
        OSuite::ZSocket::Close(this);
    }
    else
    {
      OSuite::ZSocket::Abort(this, ERR_FAILED);
    }
    return 0;
  }
}

// File Line: 200
// RVA: 0xEDE9AC
char __fastcall OSuite::ZSocket::VerifyConnection(OSuite::ZSocket *this)
{
  OSuite::psock::err_t v2; // eax
  OSuite::psock::err_t v3; // eax

  if ( (this->m_state & 5) != 5 )
    return 0;
  v2 = OSuite::psock::waitread(this->m_socket, 0);
  if ( v2 && v2 != ERR_AGAIN || (v3 = OSuite::psock::waitwrite(this->m_socket, 0)) != ERR_OK && v3 != ERR_AGAIN )
  {
    OSuite::ZSocket::Close(this);
    return 0;
  }
  return 1;
}

// File Line: 222
// RVA: 0xEDE98C
void __fastcall OSuite::ZSocket::SetTimeout(OSuite::ZSocket *this, int nConnectTimeoutMs, int nSendRecvTimeoutMs)
{
  if ( (this->m_state & 1) != 0 )
    OSuite::psock::settimeout(this->m_socket, nSendRecvTimeoutMs, nSendRecvTimeoutMs, nConnectTimeoutMs);
}

// File Line: 277
// RVA: 0xEDE8A0
char __fastcall OSuite::ZSocket::SendBuffer(OSuite::ZSocket *this, char *pBuffer, unsigned __int64 nLength)
{
  unsigned __int64 v3; // rdi
  int v7; // ebp
  unsigned __int64 v8; // rax

  v3 = nLength;
  if ( (this->m_state & 5) != 5 )
    return 0;
  this->m_operationRetry = 0i64;
  if ( nLength )
  {
    while ( this->m_operationRetry < 0x96 )
    {
      v7 = v3;
      if ( v3 > 0x8000 )
        v7 = 0x8000;
      if ( OSuite::psock::waitwrite(this->m_socket, 100) || (v8 = OSuite::psock::send(this->m_socket, pBuffer, v7)) == 0 )
      {
        ++this->m_operationRetry;
        if ( (OSuite::ZSocket::GetLastError(this) & 0xFFFFFFF7) != 0 )
        {
          OSuite::ZSocket::Close(this);
          return 0;
        }
      }
      else
      {
        this->m_nBytesSent += v8;
        pBuffer += v8;
        v3 -= v8;
        this->m_operationRetry = 0i64;
      }
      if ( !v3 )
        goto LABEL_12;
    }
    goto LABEL_13;
  }
LABEL_12:
  if ( this->m_operationRetry >= 0x96 )
  {
LABEL_13:
    OSuite::ZSocket::Abort(this, ERR_FAILED);
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
  char *result; // rax
  bool i; // cc
  int v9; // eax

  v3 = nMaxLength;
  v4 = pszString;
  if ( (this->m_state & 5) != 5 )
    return 0i64;
  this->m_operationRetry = 0i64;
  for ( i = nMaxLength <= 1; !i && this->m_operationRetry < 0x96; i = v3 <= 1 )
  {
    v9 = OSuite::ZSocket::ReceiveByte(this);
    if ( v9 >= 0 )
    {
      if ( v9 != 13 )
      {
        *v4 = v9;
        --v3;
        ++v4;
        if ( v9 == 10 )
          break;
      }
    }
    else if ( (OSuite::ZSocket::GetLastError(this) & 0xFFFFFFF7) != 0 )
    {
      if ( v4 == pszString )
        return 0i64;
      break;
    }
  }
  result = pszString;
  *v4 = 0;
  return result;
}

// File Line: 385
// RVA: 0xEDE708
__int64 __fastcall OSuite::ZSocket::ReceiveByte(OSuite::ZSocket *this)
{
  char pDest[8]; // [rsp+20h] [rbp-18h] BYREF

  if ( (this->m_state & 5) == 5 && OSuite::ZSocket::Recv(this, pDest, 1ui64) == 1 )
    return (unsigned __int8)pDest[0];
  else
    return 0xFFFFFFFFi64;
}

// File Line: 406
// RVA: 0xEDE680
__int64 __fastcall OSuite::ZSocket::ReceiveBuffer(OSuite::ZSocket *this, char *pBuffer, unsigned __int64 nLength)
{
  unsigned __int64 v3; // rdi
  __int64 v7; // rbx
  bool i; // zf
  unsigned __int64 v9; // rax

  v3 = nLength;
  if ( (this->m_state & 5) != 5 )
    return 0i64;
  v7 = 0i64;
  this->m_operationRetry = 0i64;
  for ( i = nLength == 0; !i && this->m_operationRetry < 0x96; i = v3 == 0 )
  {
    v9 = OSuite::ZSocket::Recv(this, pBuffer, v3);
    if ( v9 )
    {
      pBuffer += v9;
      v7 += v9;
      v3 -= v9;
    }
    else if ( (OSuite::ZSocket::GetLastError(this) & 0xFFFFFFF7) != 0 )
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
__int64 __fastcall OSuite::ZSocket::GetProxyType()
{
  OSuite::psock::proxy_t v0; // eax
  __int32 v1; // eax
  __int32 v2; // eax

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
// attributes: thunk
const char *__fastcall OSuite::ZSocket::GetProxyHost()
{
  return OSuite::psock::getproxyhost();
}

// File Line: 483
// RVA: 0xEDE464
// attributes: thunk
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
  OSuite::psock::psock_private *m_socket; // rcx
  OSuite::psock::err_t v3; // eax
  char *details; // [rsp+30h] [rbp+8h] BYREF

  m_socket = this->m_socket;
  if ( !m_socket )
    return 22;
  v3 = OSuite::psock::lasterror(m_socket);
  return OSuite::ZSocket::PSockErrorToOsError(v3, (const char **)&details);
}

// File Line: 562
// RVA: 0xEDE580
__int64 __fastcall OSuite::ZSocket::PSockErrorToOsError(int error, const char **details)
{
  int v2; // ecx
  int v3; // ecx
  int v4; // ecx
  const char *v6; // rax
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx

  *details = &customCaption;
  if ( error <= 5 )
  {
    if ( error == 5 )
    {
      v6 = "Message to big";
    }
    else
    {
      if ( !error )
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
void (__fastcall *dynamic_initializer_for__OSuite::ZSocket::m_staticSocketInitializer__())(int psockError)
{
  void (__fastcall *result)(int); // rax

  result = OSuite::ZSocket::StaticSocketInitializer::PSockInternalErrorCallback;
  OSuite::psock::g_ErrorCallback = (void (__fastcall *)(OSuite::psock::err_t))OSuite::ZSocket::StaticSocketInitializer::PSockInternalErrorCallback;
  return result;
}

// File Line: 608
// RVA: 0xEDE620
void __fastcall OSuite::ZSocket::StaticSocketInitializer::PSockInternalErrorCallback(int psockError)
{
  OSuite::ZError::EError v1; // edi
  OSuite::ZError *v2; // rax
  OSuite::ZString v3; // [rsp+20h] [rbp-28h] BYREF
  char *details; // [rsp+58h] [rbp+10h] BYREF

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

  v3 = 0i64;
  if ( pDest )
  {
    this->m_state = ZSOCKSTATE_RECEIVING;
    if ( OSuite::psock::waitread(this->m_socket, 100) == ERR_OK )
      v3 = OSuite::psock::recv(this->m_socket, pDest, nLength);
    this->m_state = ZSOCKSTATE_CONNECTED;
    if ( (OSuite::ZSocket::GetLastError(this) & 0xFFFFFFF7) != 0 )
    {
      OSuite::ZSocket::Close(this);
      return v3;
    }
    if ( v3 )
      this->m_operationRetry = 0i64;
    else
      ++this->m_operationRetry;
  }
  if ( this->m_operationRetry >= 0x96 )
    OSuite::ZSocket::Abort(this, ERR_FAILED);
  this->m_nBytesReceived += v3;
  return v3;
}

