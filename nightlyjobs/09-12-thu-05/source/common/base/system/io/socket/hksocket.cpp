// File Line: 124
// RVA: 0xC801C0
void __fastcall hkSocketCreate()
{
  _QWORD **v0; // rax
  hkBsdSocket *v1; // rax

  v0 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v1 = (hkBsdSocket *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v0[11] + 8i64))(v0[11], 72i64);
  if ( v1 )
    hkBsdSocket::hkBsdSocket(v1, 0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 138
// RVA: 0xC7FFE0
void __fastcall hkSocket::hkSocket(hkSocket *this)
{
  hkSocket *v1; // rbx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkSocket::`vftable';
  *(_DWORD *)&this->m_reader.m_memSizeAndFlags = 0x1FFFF;
  this->m_reader.vfptr = (hkBaseObjectVtbl *)&hkSocket::ReaderAdapter::`vftable';
  *(_DWORD *)&this->m_writer.m_memSizeAndFlags = 0x1FFFF;
  this->m_writer.vfptr = (hkBaseObjectVtbl *)&hkSocket::WriterAdapter::`vftable';
  v1->m_reader.m_socket = v1;
  v1->m_writer.m_socket = v1;
  if ( !hkSocket::s_platformNetInitialized.m_bool )
  {
    if ( hkSocket::s_platformNetInit )
    {
      hkSocket::s_platformNetInit();
      hkSocket::s_platformNetInitialized.m_bool = 1;
    }
  }
}

// File Line: 150
// RVA: 0xC80060
__int64 __fastcall hkSocket::ReaderAdapter::read(hkSocket::ReaderAdapter *this, void *buf, int nbytes)
{
  signed int v3; // ebx
  unsigned int v4; // edi
  char *v5; // rsi
  hkSocket::ReaderAdapter *v6; // rbp
  int v7; // eax

  v3 = 0;
  v4 = nbytes;
  v5 = (char *)buf;
  v6 = this;
  if ( nbytes <= 0 )
    return v4;
  while ( 1 )
  {
    v7 = ((__int64 (__fastcall *)(hkSocket *, char *, _QWORD))v6->m_socket->vfptr[2].__first_virtual_table_function__)(
           v6->m_socket,
           &v5[v3],
           v4 - v3);
    v3 += v7;
    if ( !v7 )
      break;
    if ( v3 >= (signed int)v4 )
      return v4;
  }
  return (unsigned int)v3;
}

// File Line: 166
// RVA: 0xC800E0
hkBool *__fastcall hkSocket::ReaderAdapter::isOk(hkSocket::ReaderAdapter *this, hkBool *result)
{
  hkBool *v2; // rbx

  v2 = result;
  ((void (*)(void))this->m_socket->vfptr[1].__first_virtual_table_function__)();
  return v2;
}

// File Line: 171
// RVA: 0xC80110
__int64 __fastcall hkSocket::WriterAdapter::write(hkSocket::WriterAdapter *this, const void *buf, int nbytes)
{
  signed int v3; // ebx
  unsigned int v4; // edi
  char *v5; // rsi
  hkSocket::WriterAdapter *v6; // rbp
  int v7; // eax

  v3 = 0;
  v4 = nbytes;
  v5 = (char *)buf;
  v6 = this;
  if ( nbytes <= 0 )
    return v4;
  while ( 1 )
  {
    v7 = ((__int64 (__fastcall *)(hkSocket *, char *, _QWORD))v6->m_socket->vfptr[3].__vecDelDtor)(
           v6->m_socket,
           &v5[v3],
           v4 - v3);
    v3 += v7;
    if ( !v7 )
      break;
    if ( v3 >= (signed int)v4 )
      return v4;
  }
  return (unsigned int)v3;
}

// File Line: 188
// RVA: 0xC80190
hkBool *__fastcall hkSocket::WriterAdapter::isOk(hkSocket::WriterAdapter *this, hkBool *result)
{
  hkBool *v2; // rbx

  v2 = result;
  ((void (*)(void))this->m_socket->vfptr[1].__first_virtual_table_function__)();
  return v2;
}

