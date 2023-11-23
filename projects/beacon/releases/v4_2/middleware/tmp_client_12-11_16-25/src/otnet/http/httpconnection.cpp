// File Line: 44
// RVA: 0xEDE9FC
void __fastcall OSuite::ZHttpConnection::ZHttpConnection(OSuite::ZHttpConnection *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpConnection::`vftable;
  OSuite::ZUrl::ZUrl(&this->m_url);
  this->m_socket = 0i64;
  *(_WORD *)&this->m_bAborted = 0;
}

// File Line: 74
// RVA: 0xEDEAB8
void __fastcall OSuite::ZHttpConnection::BindWithSocket(
        OSuite::ZHttpConnection *this,
        OSuite::ZSocket *socket,
        OSuite::ZUrl *url,
        bool bPersitent)
{
  this->m_bAborted = 0;
  this->m_bPersistent = bPersitent;
  OSuite::ZUrl::operator=(&this->m_url, url);
  this->m_socket = socket;
}

// File Line: 86
// RVA: 0xEDEBE0
OSuite::ZSocket *__fastcall OSuite::ZHttpConnection::Socket(OSuite::ZHttpConnection *this)
{
  return this->m_socket;
}

// File Line: 104
// RVA: 0xEDEB90
char __fastcall OSuite::ZHttpConnection::IsConnected(OSuite::ZHttpConnection *this)
{
  OSuite::ZSocket *m_socket; // rax
  char v2; // cl

  m_socket = this->m_socket;
  v2 = 0;
  if ( m_socket && (m_socket->m_state & 5) == 5 )
    return 1;
  return v2;
}

// File Line: 113
// RVA: 0xEDEBB0
char __fastcall OSuite::ZHttpConnection::IsConnecting(OSuite::ZHttpConnection *this)
{
  OSuite::ZSocket *m_socket; // rax
  char v2; // cl

  m_socket = this->m_socket;
  v2 = 0;
  if ( m_socket && (m_socket->m_state & 3) == 3 )
    return 1;
  return v2;
}

// File Line: 118
// RVA: 0xEDEBD0
bool __fastcall OSuite::ZHttpConnection::IsPersistent(OSuite::ZHttpConnection *this)
{
  return this->m_bPersistent;
}

// File Line: 123
// RVA: 0xEDEBD8
void __fastcall OSuite::ZHttpConnection::SetPersistent(OSuite::ZHttpConnection *this, bool bPersistent)
{
  this->m_bPersistent = bPersistent;
}

// File Line: 131
// RVA: 0xEDEA7C
void __fastcall OSuite::ZHttpConnection::Abort(OSuite::ZHttpConnection *this)
{
  OSuite::ZSocket *m_socket; // rcx

  if ( !this->m_bAborted )
  {
    m_socket = this->m_socket;
    if ( m_socket )
    {
      if ( (m_socket->m_state & 5) == 5 )
        OSuite::ZSocket::Abort(m_socket, ERR_OK);
    }
  }
  this->m_bAborted = 1;
}

// File Line: 149
// RVA: 0xEDEB7C
bool __fastcall OSuite::ZHttpConnection::HasFatalError(OSuite::ZHttpConnection *this)
{
  OSuite::ZSocket *m_socket; // rcx

  m_socket = this->m_socket;
  return !m_socket || OSuite::ZSocket::HasFatalError(m_socket);
}

// File Line: 156
// RVA: 0xEDEAF4
__int64 __fastcall OSuite::ZHttpConnection::GetLastError(OSuite::ZHttpConnection *this)
{
  OSuite::ZSocket *m_socket; // rcx
  unsigned int v2; // ebx
  OSuite::ZError::EError LastError; // ecx
  __int32 v4; // ecx
  __int32 v5; // ecx
  __int32 v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx

  m_socket = this->m_socket;
  v2 = 0;
  if ( m_socket )
  {
    LastError = OSuite::ZSocket::GetLastError(m_socket);
    if ( LastError )
    {
      v4 = LastError - 4;
      if ( !v4 )
        return 13;
      v5 = v4 - 4;
      if ( !v5 )
        return 16;
      v6 = v5 - 1;
      if ( !v6 )
        return 6;
      v7 = v6 - 1;
      if ( !v7 )
        return 7;
      v8 = v7 - 6;
      if ( !v8 )
        return 14;
      v9 = v8 - 5;
      if ( !v9 )
        return 11;
      v10 = v9 - 1;
      if ( !v10 )
        return 12;
      if ( v10 == 1 )
        return 13;
      return 17;
    }
    return v2;
  }
  return 12i64;
}

