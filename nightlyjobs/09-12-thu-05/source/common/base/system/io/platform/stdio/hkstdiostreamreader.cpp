// File Line: 18
// RVA: 0xC83B20
hkStdioStreamReader *__fastcall hkStdioStreamReader::open(char *nameIn)
{
  const wchar_t **v1; // rax
  __int64 v2; // rbx
  _iobuf *v3; // rdi
  _QWORD **Value; // rax
  hkStdioStreamReader *v5; // rax
  __int64 v6; // rax
  hkUtf8::WideFromUtf8 v8; // [rsp+20h] [rbp-18h] BYREF

  hkUtf8::WideFromUtf8::WideFromUtf8(&v8, nameIn);
  v2 = 0i64;
  v3 = wfopen(*v1, L"rb");
  v8.m_wide.m_size = 0;
  if ( v8.m_wide.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v8.m_wide.m_data,
      2 * (v8.m_wide.m_capacityAndFlags & 0x3FFFFFFF));
  if ( !v3 )
    return 0i64;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkStdioStreamReader *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
  if ( v5 )
  {
    hkStdioStreamReader::hkStdioStreamReader(v5, v3);
    return (hkStdioStreamReader *)v6;
  }
  return (hkStdioStreamReader *)v2;
}

// File Line: 33
// RVA: 0xC83BD0
void __fastcall hkStdioStreamReader::hkStdioStreamReader(hkStdioStreamReader *this, void *handle)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkStdioStreamReader::`vftable;
  this->m_handle = handle;
  this->m_isOk.m_bool = handle != 0i64;
}

// File Line: 37
// RVA: 0xC83C00
void __fastcall hkStdioStreamReader::~hkStdioStreamReader(hkStdioStreamReader *this)
{
  _iobuf *m_handle; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkStdioStreamReader::`vftable;
  m_handle = (_iobuf *)this->m_handle;
  if ( m_handle )
    fclose(m_handle);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 45
// RVA: 0xC83C40
unsigned __int64 __fastcall hkStdioStreamReader::read(hkStdioStreamReader *this, void *buf, int nbytes)
{
  unsigned __int64 result; // rax

  result = fread(buf, 1ui64, nbytes, (_iobuf *)this->m_handle);
  if ( (int)result <= 0 )
    this->m_isOk.m_bool = 0;
  return result;
}

// File Line: 56
// RVA: 0xC83C80
hkBool *__fastcall hkStdioStreamReader::isOk(hkStdioStreamReader *this, hkBool *result)
{
  result->m_bool = (char)this->m_isOk;
  return result;
}

// File Line: 61
// RVA: 0xC83C90
__int64 __fastcall hkStdioStreamReader::peek(hkStdioStreamReader *this, void *buf, int nbytes)
{
  _iobuf *m_handle; // rbx
  unsigned int v5; // edi

  m_handle = (_iobuf *)this->m_handle;
  v5 = fread(buf, 1ui64, nbytes, m_handle);
  if ( fseek(m_handle, -v5, 1) < 0 || !v5 )
    this->m_isOk.m_bool = 0;
  return v5;
}

// File Line: 74
// RVA: 0xC83D00
hkResult *__fastcall hkStdioStreamReader::seek(hkStdioStreamReader *this, hkResult *result, int offset, int whence)
{
  bool v6; // zf
  hkResult *v7; // rax

  v6 = fseek((_iobuf *)this->m_handle, offset, whence) == 0;
  v7 = result;
  if ( v6 )
  {
    this->m_isOk.m_bool = 1;
    result->m_enum = HK_SUCCESS;
  }
  else
  {
    result->m_enum = HK_FAILURE;
    this->m_isOk.m_bool = 0;
  }
  return v7;
}

// File Line: 85
// RVA: 0xC83D60
int __fastcall hkStdioStreamReader::tell(hkStdioStreamReader *this)
{
  return ftell((_iobuf *)this->m_handle);
}

