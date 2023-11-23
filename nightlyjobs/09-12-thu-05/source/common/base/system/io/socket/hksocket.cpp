// File Line: 124
// RVA: 0xC801C0
void __fastcall hkSocketCreate()
{
  _QWORD **Value; // rax
  hkBsdSocket *v1; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v1 = (hkBsdSocket *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 72i64);
  if ( v1 )
    hkBsdSocket::hkBsdSocket(v1, 0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 138
// RVA: 0xC7FFE0
void __fastcall hkSocket::hkSocket(hkSocket *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkSocket::`vftable;
  *(_DWORD *)&this->m_reader.m_memSizeAndFlags = 0x1FFFF;
  this->m_reader.vfptr = (hkBaseObjectVtbl *)&hkSocket::ReaderAdapter::`vftable;
  *(_DWORD *)&this->m_writer.m_memSizeAndFlags = 0x1FFFF;
  this->m_writer.vfptr = (hkBaseObjectVtbl *)&hkSocket::WriterAdapter::`vftable;
  this->m_reader.m_socket = this;
  this->m_writer.m_socket = this;
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
__int64 __fastcall hkSocket::ReaderAdapter::read(hkSocket::ReaderAdapter *this, char *buf, unsigned int nbytes)
{
  int v3; // ebx
  int v7; // eax

  v3 = 0;
  if ( (int)nbytes <= 0 )
    return nbytes;
  while ( 1 )
  {
    v7 = ((__int64 (__fastcall *)(hkSocket *, char *, _QWORD))this->m_socket->vfptr[2].__first_virtual_table_function__)(
           this->m_socket,
           &buf[v3],
           nbytes - v3);
    v3 += v7;
    if ( !v7 )
      break;
    if ( v3 >= (int)nbytes )
      return nbytes;
  }
  return (unsigned int)v3;
}

// File Line: 166
// RVA: 0xC800E0
hkBool *__fastcall hkSocket::ReaderAdapter::isOk(hkSocket::ReaderAdapter *this, hkBool *result)
{
  this->m_socket->vfptr[1].__first_virtual_table_function__(this->m_socket);
  return result;
}

// File Line: 171
// RVA: 0xC80110
__int64 __fastcall hkSocket::WriterAdapter::write(hkSocket::WriterAdapter *this, char *buf, unsigned int nbytes)
{
  int v3; // ebx
  int v7; // eax

  v3 = 0;
  if ( (int)nbytes <= 0 )
    return nbytes;
  while ( 1 )
  {
    v7 = ((__int64 (__fastcall *)(hkSocket *, char *, _QWORD))this->m_socket->vfptr[3].__vecDelDtor)(
           this->m_socket,
           &buf[v3],
           nbytes - v3);
    v3 += v7;
    if ( !v7 )
      break;
    if ( v3 >= (int)nbytes )
      return nbytes;
  }
  return (unsigned int)v3;
}

// File Line: 188
// RVA: 0xC80190
hkBool *__fastcall hkSocket::WriterAdapter::isOk(hkSocket::WriterAdapter *this, hkBool *result)
{
  this->m_socket->vfptr[1].__first_virtual_table_function__(this->m_socket);
  return result;
}

