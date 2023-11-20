// File Line: 18
// RVA: 0xC83DD0
hkWin32StreamWriter *__fastcall hkWin32StreamWriter::open(const char *fname, int dwCreationDisposition)
{
  int v2; // ebx
  __int64 v3; // rdi
  LPCWSTR *v4; // rax
  HANDLE v5; // rax
  void *v6; // rbx
  _QWORD **v7; // rax
  hkWin32StreamWriter *v8; // rax
  __int64 v9; // rax
  hkUtf8::WideFromUtf8 v11; // [rsp+40h] [rbp-18h]

  v2 = dwCreationDisposition;
  hkUtf8::WideFromUtf8::WideFromUtf8(&v11, fname);
  v3 = 0i64;
  v5 = CreateFileW(*v4, 0x40000000u, 1u, 0i64, v2, 0x80u, 0i64);
  v11.m_wide.m_size = 0;
  v6 = v5;
  if ( v11.m_wide.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v11.m_wide.m_data,
      2 * (v11.m_wide.m_capacityAndFlags & 0x3FFFFFFF));
  if ( v6 == (void *)-1i64 )
    return 0i64;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkWin32StreamWriter *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 24i64);
  if ( v8 )
  {
    hkWin32StreamWriter::hkWin32StreamWriter(v8, v6);
    v3 = v9;
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
  void *v1; // rcx

  v1 = this->m_handle;
  if ( v1 != (void *)-1i64 )
    CloseHandle(v1);
}

// File Line: 45
// RVA: 0xC83EC0
void __fastcall hkWin32StreamWriter::~hkWin32StreamWriter(hkWin32StreamWriter *this)
{
  hkWin32StreamWriter *v1; // rbx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkWin32StreamWriter::`vftable;
  hkWin32StreamWriter::close(this);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 50
// RVA: 0xC83F10
__int64 __fastcall hkWin32StreamWriter::write(hkWin32StreamWriter *this, const void *buf, int nbytes)
{
  hkWin32StreamWriter *v3; // rbx
  void *v4; // rcx
  __int64 result; // rax
  unsigned int NumberOfBytesWritten; // [rsp+40h] [rbp+8h]

  v3 = this;
  v4 = this->m_handle;
  if ( v4 == (void *)-1i64 || nbytes <= 0 )
    return 0i64;
  WriteFile(v4, buf, nbytes, &NumberOfBytesWritten, 0i64);
  result = NumberOfBytesWritten;
  if ( !NumberOfBytesWritten )
  {
    hkWin32StreamWriter::close(v3);
    result = NumberOfBytesWritten;
  }
  return result;
}

// File Line: 65
// RVA: 0xC83F70
void __fastcall hkWin32StreamWriter::flush(hkWin32StreamWriter *this)
{
  void *v1; // rcx

  v1 = this->m_handle;
  if ( v1 != (void *)-1i64 )
    FlushFileBuffers(v1);
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
hkResult *__fastcall hkWin32StreamWriter::seek(hkWin32StreamWriter *this, hkResult *result, int offset, hkStreamWriter::SeekWhence whence)
{
  hkResult *v4; // rbx
  bool v5; // zf
  hkResult *v6; // rax

  v4 = result;
  v5 = SetFilePointer(this->m_handle, offset, 0i64, whence) == -1;
  v6 = v4;
  v4->m_enum = v5;
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
    v2 = v1;
  return v2;
}

