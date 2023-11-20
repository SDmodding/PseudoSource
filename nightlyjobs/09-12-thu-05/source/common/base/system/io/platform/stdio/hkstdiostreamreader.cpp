// File Line: 18
// RVA: 0xC83B20
hkStdioStreamReader *__fastcall hkStdioStreamReader::open(const char *nameIn)
{
  const wchar_t **v1; // rax
  __int64 v2; // rbx
  _iobuf *v3; // rdi
  _QWORD **v4; // rax
  hkStdioStreamReader *v5; // rax
  __int64 v6; // rax
  hkUtf8::WideFromUtf8 v8; // [rsp+20h] [rbp-18h]

  hkUtf8::WideFromUtf8::WideFromUtf8(&v8, nameIn);
  v2 = 0i64;
  v3 = wfopen(*v1, L"rb");
  v8.m_wide.m_size = 0;
  if ( v8.m_wide.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v8.m_wide.m_data,
      2 * (v8.m_wide.m_capacityAndFlags & 0x3FFFFFFF));
  if ( !v3 )
    return 0i64;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkStdioStreamReader *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 32i64);
  if ( v5 )
  {
    hkStdioStreamReader::hkStdioStreamReader(v5, v3);
    v2 = v6;
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
  hkStdioStreamReader *v1; // rbx
  _iobuf *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkStdioStreamReader::`vftable;
  v2 = (_iobuf *)this->m_handle;
  if ( v2 )
    fclose(v2);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 45
// RVA: 0xC83C40
unsigned __int64 __fastcall hkStdioStreamReader::read(hkStdioStreamReader *this, void *buf, int nbytes)
{
  hkStdioStreamReader *v3; // rbx
  unsigned __int64 result; // rax

  v3 = this;
  result = fread(buf, 1ui64, nbytes, (_iobuf *)this->m_handle);
  if ( (signed int)result <= 0 )
    v3->m_isOk.m_bool = 0;
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
  _iobuf *v3; // rbx
  hkStdioStreamReader *v4; // rsi
  unsigned int v5; // edi

  v3 = (_iobuf *)this->m_handle;
  v4 = this;
  v5 = fread(buf, 1ui64, nbytes, (_iobuf *)this->m_handle);
  if ( fseek(v3, -v5, 1) < 0 || !v5 )
    v4->m_isOk.m_bool = 0;
  return v5;
}

// File Line: 74
// RVA: 0xC83D00
hkResult *__fastcall hkStdioStreamReader::seek(hkStdioStreamReader *this, hkResult *result, int offset, hkSeekableStreamReader::SeekWhence whence)
{
  hkStdioStreamReader *v4; // rdi
  hkResult *v5; // rbx
  bool v6; // zf
  hkResult *v7; // rax

  v4 = this;
  v5 = result;
  v6 = fseek((_iobuf *)this->m_handle, offset, whence) == 0;
  v7 = v5;
  if ( v6 )
  {
    v4->m_isOk.m_bool = 1;
    v5->m_enum = 0;
  }
  else
  {
    v5->m_enum = 1;
    v4->m_isOk.m_bool = 0;
  }
  return v7;
}

// File Line: 85
// RVA: 0xC83D60
int __fastcall hkStdioStreamReader::tell(hkStdioStreamReader *this)
{
  return ftell((_iobuf *)this->m_handle);
}

