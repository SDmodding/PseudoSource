// File Line: 44
// RVA: 0xEDE9FC
void __fastcall OSuite::ZHttpConnection::ZHttpConnection(OSuite::ZHttpConnection *this)
{
  OSuite::ZHttpConnection *v1; // rbx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpConnection::`vftable';
  OSuite::ZUrl::ZUrl(&this->m_url);
  v1->m_socket = 0i64;
  *(_WORD *)&v1->m_bAborted = 0;
}

// File Line: 74
// RVA: 0xEDEAB8
void __fastcall OSuite::ZHttpConnection::BindWithSocket(OSuite::ZHttpConnection *this, OSuite::ZSocket *socket, OSuite::ZUrl *url, bool bPersitent)
{
  OSuite::ZSocket *v4; // rdi
  OSuite::ZHttpConnection *v5; // rbx

  v4 = socket;
  v5 = this;
  this->m_bAborted = 0;
  this->m_bPersistent = bPersitent;
  OSuite::ZUrl::operator=(&this->m_url, url);
  v5->m_socket = v4;
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
  OSuite::ZSocket *v1; // rax
  char v2; // cl

  v1 = this->m_socket;
  v2 = 0;
  if ( v1 && (v1->m_state & 5) == 5 )
    v2 = 1;
  return v2;
}

// File Line: 113
// RVA: 0xEDEBB0
char __fastcall OSuite::ZHttpConnection::IsConnecting(OSuite::ZHttpConnection *this)
{
  OSuite::ZSocket *v1; // rax
  char v2; // cl

  v1 = this->m_socket;
  v2 = 0;
  if ( v1 && (v1->m_state & 3) == 3 )
    v2 = 1;
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
  OSuite::ZHttpConnection *v1; // rbx
  OSuite::ZSocket *v2; // rcx

  v1 = this;
  if ( !this->m_bAborted )
  {
    v2 = this->m_socket;
    if ( v2 )
    {
      if ( (v2->m_state & 5) == 5 )
        OSuite::ZSocket::Abort(v2, 0);
    }
  }
  v1->m_bAborted = 1;
}

// File Line: 149
// RVA: 0xEDEB7C
char __fastcall OSuite::ZHttpConnection::HasFatalError(OSuite::ZHttpConnection *this)
{
  JUMPOUT(this->m_socket, 0i64, OSuite::ZSocket::HasFatalError);
  return 1;
}

// File Line: 156
// RVA: 0xEDEAF4
signed __int64 __fastcall OSuite::ZHttpConnection::GetLastError(OSuite::ZHttpConnection *this)
{
  OSuite::ZSocket *v1; // rcx
  unsigned int v2; // ebx
  OSuite::ZError::EError v3; // ecx
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx

  v1 = this->m_socket;
  v2 = 0;
  if ( v1 )
  {
    v3 = OSuite::ZSocket::GetLastError(v1);
    if ( v3 )
    {
      v4 = v3 - 4;
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
      v2 = 17;
    }
    return v2;
  }
  return 12i64;
}

