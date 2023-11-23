// File Line: 18
// RVA: 0xC83DD0
hkWin32StreamWriter *__fastcall hkWin32StreamWriter::open(char *fname, DWORD dwCreationDisposition)
{
  __int64 v3; // rdi
  LPCWSTR *v4; // rax
  HANDLE FileW; // rax
  void *v6; // rbx
  _QWORD **Value; // rax
  hkWin32StreamWriter *v8; // rax
  __int64 v9; // rax
  hkUtf8::WideFromUtf8 v11; // [rsp+40h] [rbp-18h] BYREF

  hkUtf8::WideFromUtf8::WideFromUtf8(&v11, fname);
  v3 = 0i64;
  FileW = CreateFileW(*v4, 0x40000000u, 1u, 0i64, dwCreationDisposition, 0x80u, 0i64);
  v11.m_wide.m_size = 0;
  v6 = FileW;
  if ( v11.m_wide.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v11.m_wide.m_data,
      2 * (v11.m_wide.m_capacityAndFlags & 0x3FFFFFFF));
  if ( v6 == (void *)-1i64 )
    return 0i64;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkWin32StreamWriter *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 24i64);
  if ( v8 )
  {
    hkWin32StreamWriter::hkWin32StreamWriter(v8, v6);
    return (hkWin32StreamWriter *)v9;
  }
  return (hkWin32StreamWriter *)v3;
}

// File Line: 33
// RVA: 0xC83EA0
void __fastcall hkWin32StreamWriter::hkWin32StreamWriter(hkWin32StreamWriter *this, void *handle)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_handle = handle;
  this->vfptr = (hkBaseObjectVtbl *)&hkWin32StreamWriter::`vftable;
}

// File Line: 37
// RVA: 0xC83EF0
void __fastcall hkWin32StreamWriter::close(hkWin32StreamWriter *this)
{
  void *m_handle; // rcx

  m_handle = this->m_handle;
  if ( m_handle != (void *)-1i64 )
    CloseHandle(m_handle);
}

// File Line: 45
// RVA: 0xC83EC0
void __fastcall hkWin32StreamWriter::~hkWin32StreamWriter(hkWin32StreamWriter *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkWin32StreamWriter::`vftable;
  hkWin32StreamWriter::close(this);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 50
// RVA: 0xC83F10
__int64 __fastcall hkWin32StreamWriter::write(hkWin32StreamWriter *this, const void *buf, int nbytes)
{
  void *m_handle; // rcx
  __int64 result; // rax
  unsigned int NumberOfBytesWritten; // [rsp+40h] [rbp+8h] BYREF

  m_handle = this->m_handle;
  if ( m_handle == (void *)-1i64 || nbytes <= 0 )
    return 0i64;
  WriteFile(m_handle, buf, nbytes, &NumberOfBytesWritten, 0i64);
  result = NumberOfBytesWritten;
  if ( !NumberOfBytesWritten )
  {
    hkWin32StreamWriter::close(this);
    return NumberOfBytesWritten;
  }
  return result;
}

// File Line: 65
// RVA: 0xC83F70
void __fastcall hkWin32StreamWriter::flush(hkWin32StreamWriter *this)
{
  void *m_handle; // rcx

  m_handle = this->m_handle;
  if ( m_handle != (void *)-1i64 )
    FlushFileBuffers(m_handle);
}

// File Line: 73
// RVA: 0xC83F90
hkBool *__fastcall hkWin32StreamWriter::isOk(hkWin32StreamWriter *this, hkBool *result)
{
  result->m_bool = this->m_handle != (void *)-1i64;
  return result;
}

// File Line: 78
// RVA: 0xC83FB0
hkResult *__fastcall hkWin32StreamWriter::seek(hkWin32StreamWriter *this, hkResult *result, LONG offset, DWORD whence)
{
  bool v5; // zf
  hkResult *v6; // rax

  v5 = SetFilePointer(this->m_handle, offset, 0i64, whence) == -1;
  v6 = result;
  result->m_enum = v5;
  return v6;
}

// File Line: 91
// RVA: 0xC83FF0
__int64 __fastcall hkWin32StreamWriter::tell(hkWin32StreamWriter *this)
{
  DWORD v1; // eax
  unsigned int v2; // ecx

  v1 = SetFilePointer(this->m_handle, 0, 0i64, 1u);
  v2 = -1;
  if ( v1 != -1 )
    return v1;
  return v2;
}

