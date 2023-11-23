// File Line: 84
// RVA: 0xC7F060
void __fastcall s_convertFileNameToNative(hkStringBuf *filename)
{
  hkStringBuf::replace(filename, 47, 92, REPLACE_ALL);
}

// File Line: 101
// RVA: 0xC7F080
unsigned __int64 __fastcall s_combineHiLoDwords(unsigned int high, unsigned int low)
{
  return low + ((unsigned __int64)high << 32);
}

// File Line: 106
// RVA: 0xC7F0A0
unsigned __int64 __fastcall s_convertWindowsFiletimeToUnixTime(unsigned int high, unsigned int low)
{
  return 100 * (low + ((unsigned __int64)high << 32) - 116444736000000000i64);
}

// File Line: 113
// RVA: 0xC7F0D0
void __fastcall s_entryFromFindData(hkFileSystem::Entry *e, hkFileSystem *fs, const char *top, _WIN32_FIND_DATAW *f)
{
  __int64 v8; // r9
  hkFileSystem::TimeStamp mt; // rdi
  BOOL v10; // ebx
  const char **v11; // rax
  const char *v12; // rsi
  hkStringBuf *v13; // rax
  __int64 sz; // rax
  const char *v15; // r8
  hkUtf8::Utf8FromWide v16; // [rsp+30h] [rbp-B8h] BYREF
  hkStringBuf v17; // [rsp+40h] [rbp-A8h] BYREF

  mt.m_time = s_convertWindowsFiletimeToUnixTime(f->ftLastWriteTime.dwHighDateTime, f->ftLastWriteTime.dwLowDateTime);
  v10 = (*(_BYTE *)v8 & 0x10) != 0;
  hkUtf8::Utf8FromWide::Utf8FromWide(&v16, (const wchar_t *)(v8 + 44));
  v12 = *v11;
  hkStringBuf::hkStringBuf(&v17, top);
  hkStringBuf::pathAppend(v13, v12, 0i64, 0i64);
  sz = s_combineHiLoDwords(f->nFileSizeHigh, f->nFileSizeLow);
  hkFileSystem::Entry::setAll(e, fs, v15, (hkFlags<enum hkFileSystem::Entry::FlagValues,unsigned int>)(v10 + 1), mt, sz);
  v17.m_string.m_size = 0;
  if ( v17.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v17.m_string.m_data,
      v17.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  v17.m_string.m_data = 0i64;
  v17.m_string.m_capacityAndFlags = 0x80000000;
  v16.m_utf8.m_size = 0;
  if ( v16.m_utf8.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v16.m_utf8.m_data,
      v16.m_utf8.m_capacityAndFlags & 0x3FFFFFFF);
}

// File Line: 125
// RVA: 0xC7EB30
hkRefNew<hkStreamReader> *__fastcall hkWin32FileSystem::openReader(
        hkWin32FileSystem *this,
        hkRefNew<hkStreamReader> *result,
        const char *name,
        hkFileSystem::OpenFlags flags)
{
  hkStdioStreamReader *v7; // rax
  hkStreamReader *v8; // rax
  int m_capacityAndFlags; // r8d
  hkStringBuf filename; // [rsp+20h] [rbp-98h] BYREF

  hkStringBuf::hkStringBuf(&filename, name);
  s_convertFileNameToNative(&filename);
  v7 = hkStdioStreamReader::open(filename.m_string.m_data);
  v8 = hkFileSystem::_handleFlags(this, v7, (hkFileSystem::OpenFlags)(flags & 0xFFFFFFFE));
  m_capacityAndFlags = filename.m_string.m_capacityAndFlags;
  filename.m_string.m_size = 0;
  result->m_pntr = v8;
  if ( m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      filename.m_string.m_data,
      m_capacityAndFlags & 0x3FFFFFFF);
  return result;
}

// File Line: 132
// RVA: 0xC7EBD0
hkRefNew<hkStreamWriter> *__fastcall hkWin32FileSystem::openWriter(
        hkWin32FileSystem *this,
        hkRefNew<hkStreamWriter> *result,
        const char *name,
        hkFileSystem::OpenFlags flags)
{
  int v7; // edx
  hkWin32StreamWriter *v8; // rax
  hkStreamWriter *v9; // rax
  int m_capacityAndFlags; // r8d
  hkStringBuf filename; // [rsp+20h] [rbp-98h] BYREF

  hkStringBuf::hkStringBuf(&filename, name);
  s_convertFileNameToNative(&filename);
  v7 = 4;
  if ( (flags & 2) != 0 )
    v7 = 2;
  v8 = hkWin32StreamWriter::open(filename.m_string.m_data, v7);
  v9 = hkFileSystem::_handleFlags(this, v8, flags);
  m_capacityAndFlags = filename.m_string.m_capacityAndFlags;
  filename.m_string.m_size = 0;
  result->m_pntr = v9;
  if ( m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      filename.m_string.m_data,
      m_capacityAndFlags & 0x3FFFFFFF);
  return result;
}

// File Line: 144
// RVA: 0xC7EC80
_BOOL8 __fastcall hkWin32FileSystem::remove(hkWin32FileSystem *this, const char *path)
{
  LPCWSTR *v2; // rax
  BOOL v3; // eax
  BOOL v4; // ebx
  hkUtf8::WideFromUtf8 v6; // [rsp+20h] [rbp-A8h] BYREF
  hkStringBuf filename; // [rsp+30h] [rbp-98h] BYREF

  hkStringBuf::hkStringBuf(&filename, path);
  s_convertFileNameToNative(&filename);
  hkUtf8::WideFromUtf8::WideFromUtf8(&v6, filename.m_string.m_data);
  v3 = DeleteFileW(*v2);
  v6.m_wide.m_size = 0;
  v4 = !v3;
  if ( v6.m_wide.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v6.m_wide.m_data,
      2 * (v6.m_wide.m_capacityAndFlags & 0x3FFFFFFF));
  v6.m_wide.m_data = 0i64;
  v6.m_wide.m_capacityAndFlags = 0x80000000;
  filename.m_string.m_size = 0;
  if ( filename.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      filename.m_string.m_data,
      filename.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return v4;
}

// File Line: 149
// RVA: 0xC7ED40
_BOOL8 __fastcall hkWin32FileSystem::mkdir(hkWin32FileSystem *this, const char *path)
{
  LPCWSTR *v2; // rax
  BOOL DirectoryW; // eax
  BOOL v4; // ebx
  hkUtf8::WideFromUtf8 v6; // [rsp+20h] [rbp-A8h] BYREF
  hkStringBuf filename; // [rsp+30h] [rbp-98h] BYREF

  hkStringBuf::hkStringBuf(&filename, path);
  s_convertFileNameToNative(&filename);
  hkUtf8::WideFromUtf8::WideFromUtf8(&v6, filename.m_string.m_data);
  DirectoryW = CreateDirectoryW(*v2, 0i64);
  v6.m_wide.m_size = 0;
  v4 = !DirectoryW;
  if ( v6.m_wide.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v6.m_wide.m_data,
      2 * (v6.m_wide.m_capacityAndFlags & 0x3FFFFFFF));
  v6.m_wide.m_data = 0i64;
  v6.m_wide.m_capacityAndFlags = 0x80000000;
  filename.m_string.m_size = 0;
  if ( filename.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      filename.m_string.m_data,
      filename.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return v4;
}

// File Line: 156
// RVA: 0xC7EE10
__int64 __fastcall hkWin32FileSystem::stat(hkWin32FileSystem *this, const char *path, hkFileSystem::Entry *entryOut)
{
  unsigned int v6; // ebx
  LPCWSTR *v7; // rax
  HANDLE FirstFileW; // rax
  void *v9; // rdi
  __int64 sz; // rax
  hkFileSystem::TimeStamp mt; // r8
  hkFlags<enum hkFileSystem::Entry::FlagValues,unsigned int> v12; // r9d
  hkUtf8::WideFromUtf8 v14; // [rsp+30h] [rbp-2F8h] BYREF
  hkStringBuf filename; // [rsp+40h] [rbp-2E8h] BYREF
  _WIN32_FIND_DATAW FindFileData; // [rsp+D0h] [rbp-258h] BYREF

  hkStringBuf::hkStringBuf(&filename, path);
  s_convertFileNameToNative(&filename);
  v6 = 1;
  while ( (unsigned int)hkStringBuf::endsWith(&filename, "\\") )
    hkStringBuf::chompEnd(&filename, 1);
  hkUtf8::WideFromUtf8::WideFromUtf8(&v14, filename.m_string.m_data);
  FirstFileW = FindFirstFileW(*v7, &FindFileData);
  v14.m_wide.m_size = 0;
  v9 = FirstFileW;
  if ( v14.m_wide.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v14.m_wide.m_data,
      2 * (v14.m_wide.m_capacityAndFlags & 0x3FFFFFFF));
  v14.m_wide.m_data = 0i64;
  v14.m_wide.m_capacityAndFlags = 0x80000000;
  if ( v9 != (void *)-1i64 )
  {
    s_convertWindowsFiletimeToUnixTime(
      FindFileData.ftLastWriteTime.dwHighDateTime,
      FindFileData.ftLastWriteTime.dwLowDateTime);
    sz = s_combineHiLoDwords(FindFileData.nFileSizeHigh, FindFileData.nFileSizeLow);
    hkFileSystem::Entry::setAll(entryOut, this, path, v12, mt, sz);
    FindClose(v9);
    v6 = 0;
  }
  filename.m_string.m_size = 0;
  if ( filename.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      filename.m_string.m_data,
      filename.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return v6;
}

// File Line: 199
// RVA: 0xC7F2A0
char __fastcall `anonymous namespace::Win32Impl::advance(Win32Impl *this, hkFileSystem::Entry *e)
{
  char v4; // di
  _QWORD *v5; // rax
  LPCWSTR *v6; // rax
  HANDLE FirstFileW; // rax
  int m_capacityAndFlags; // r8d
  char v9; // bl
  const char **v10; // rax
  bool v11; // al
  bool v12; // di
  void *m_handle; // rcx
  const char **v15; // rax
  bool v16; // al
  bool v17; // di
  hkUtf8::WideFromUtf8 v18; // [rsp+20h] [rbp-E0h] BYREF
  hkStringBuf filename; // [rsp+30h] [rbp-D0h] BYREF
  _WIN32_FIND_DATAW FindFileData; // [rsp+C0h] [rbp-40h] BYREF
  hkStringPtr v21; // [rsp+340h] [rbp+240h] BYREF
  hkStringPtr v22; // [rsp+350h] [rbp+250h] BYREF

  LODWORD(v21.m_stringAndFlag) = 0;
  if ( !this->m_handle )
  {
    hkStringBuf::hkStringBuf(&filename, &this->m_top);
    if ( ((unsigned __int64)this->m_wildcard.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    {
      v4 = 1;
      hkStringPtr::hkStringPtr(&v22, &this->m_wildcard);
    }
    else
    {
      v4 = 2;
      hkStringPtr::hkStringPtr(&v21, pattern);
    }
    hkStringBuf::pathAppend(&filename, (const char *)(*v5 & 0xFFFFFFFFFFFFFFFEui64), 0i64, 0i64);
    if ( (v4 & 2) != 0 )
    {
      v4 &= ~2u;
      hkStringPtr::~hkStringPtr(&v21);
    }
    if ( (v4 & 1) != 0 )
      hkStringPtr::~hkStringPtr(&v22);
    s_convertFileNameToNative(&filename);
    hkUtf8::WideFromUtf8::WideFromUtf8(&v18, filename.m_string.m_data);
    FirstFileW = FindFirstFileW(*v6, &FindFileData);
    m_capacityAndFlags = v18.m_wide.m_capacityAndFlags;
    v18.m_wide.m_size = 0;
    this->m_handle = FirstFileW;
    if ( m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v18.m_wide.m_data,
        2 * (m_capacityAndFlags & 0x3FFFFFFF));
    if ( this->m_handle == (void *)-1i64 )
    {
      v9 = 0;
LABEL_17:
      filename.m_string.m_size = 0;
      if ( filename.m_string.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          filename.m_string.m_data,
          filename.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      return v9;
    }
    hkUtf8::Utf8FromWide::Utf8FromWide((hkUtf8::Utf8FromWide *)&v18, FindFileData.cFileName);
    v11 = hkFileSystem::Iterator::nameAcceptable(*v10, 0i64);
    v18.m_wide.m_size = 0;
    v12 = v11;
    if ( v18.m_wide.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v18.m_wide.m_data,
        v18.m_wide.m_capacityAndFlags & 0x3FFFFFFF);
    if ( v12 )
    {
      s_entryFromFindData(
        e,
        this->m_fs,
        (const char *)((unsigned __int64)this->m_top.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
        &FindFileData);
      v9 = 1;
      goto LABEL_17;
    }
    filename.m_string.m_size = 0;
    if ( filename.m_string.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        filename.m_string.m_data,
        filename.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  }
  m_handle = this->m_handle;
  if ( m_handle == (void *)-1i64 )
    return 0;
  if ( !FindNextFileW(m_handle, &FindFileData) )
  {
LABEL_28:
    FindClose(this->m_handle);
    this->m_handle = (void *)-1i64;
    return 0;
  }
  while ( 1 )
  {
    hkUtf8::Utf8FromWide::Utf8FromWide((hkUtf8::Utf8FromWide *)&v18, FindFileData.cFileName);
    v16 = hkFileSystem::Iterator::nameAcceptable(*v15, 0i64);
    v18.m_wide.m_size = 0;
    v17 = v16;
    if ( v18.m_wide.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v18.m_wide.m_data,
        v18.m_wide.m_capacityAndFlags & 0x3FFFFFFF);
    v18.m_wide.m_data = 0i64;
    v18.m_wide.m_capacityAndFlags = 0x80000000;
    if ( v17 )
      break;
    if ( !FindNextFileW(this->m_handle, &FindFileData) )
      goto LABEL_28;
  }
  s_entryFromFindData(
    e,
    this->m_fs,
    (const char *)((unsigned __int64)this->m_top.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
    &FindFileData);
  return 1;
}

// File Line: 252
// RVA: 0xC7EFB0
hkRefNew<hkFileSystem::Iterator::Impl> *__fastcall hkWin32FileSystem::createIterator(
        hkWin32FileSystem *this,
        hkRefNew<hkFileSystem::Iterator::Impl> *result,
        const char *top,
        const char *wildcard)
{
  _QWORD **Value; // rax
  __int64 v9; // rax
  __int64 v10; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  v10 = v9;
  if ( v9 )
  {
    *(_DWORD *)(v9 + 8) = 0x1FFFF;
    *(_QWORD *)(v9 + 16) = this;
    *(_QWORD *)v9 = &`anonymous namespace::Win32Impl::`vftable;
    hkStringPtr::hkStringPtr((hkStringPtr *)(v9 + 24), top);
    hkStringPtr::hkStringPtr((hkStringPtr *)(v10 + 32), wildcard);
    *(_QWORD *)(v10 + 40) = 0i64;
    result->m_pntr = (hkFileSystem::Iterator::Impl *)v10;
  }
  else
  {
    result->m_pntr = 0i64;
  }
  return result;
}

