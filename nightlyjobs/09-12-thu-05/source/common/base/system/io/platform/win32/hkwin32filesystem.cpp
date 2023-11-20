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
  hkFileSystem *v4; // r15
  hkFileSystem::Entry *v5; // r12
  _WIN32_FIND_DATAW *v6; // r14
  const char *v7; // rbp
  __int64 v8; // r9
  hkFileSystem::TimeStamp mt; // rdi
  BOOL v10; // ebx
  const char **v11; // rax
  const char *v12; // rsi
  hkStringBuf *v13; // rax
  char *v14; // r8
  __int64 sz; // rax
  const char *v16; // r8
  hkUtf8::Utf8FromWide v17; // [rsp+30h] [rbp-B8h]
  hkStringBuf v18; // [rsp+40h] [rbp-A8h]

  v4 = fs;
  v5 = e;
  v6 = f;
  v7 = top;
  mt.m_time = s_convertWindowsFiletimeToUnixTime(f->ftLastWriteTime.dwHighDateTime, f->ftLastWriteTime.dwLowDateTime);
  v10 = (*(_BYTE *)v8 & 0x10) != 0;
  hkUtf8::Utf8FromWide::Utf8FromWide(&v17, (const wchar_t *)(v8 + 44));
  v12 = *v11;
  hkStringBuf::hkStringBuf(&v18, v7);
  v14 = hkStringBuf::pathAppend(v13, v12, 0i64, 0i64)->m_string.m_data;
  sz = s_combineHiLoDwords(v6->nFileSizeHigh, v6->nFileSizeLow);
  hkFileSystem::Entry::setAll(
    v5,
    v4,
    v16,
    (hkFlags<enum hkFileSystem::Entry::FlagValues,unsigned int>)(v10 + 1),
    mt,
    sz);
  v18.m_string.m_size = 0;
  if ( v18.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v18.m_string.m_data,
      v18.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  v18.m_string.m_data = 0i64;
  v18.m_string.m_capacityAndFlags = 2147483648;
  v17.m_utf8.m_size = 0;
  if ( v17.m_utf8.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v17.m_utf8.m_data,
      v17.m_utf8.m_capacityAndFlags & 0x3FFFFFFF);
}

// File Line: 125
// RVA: 0xC7EB30
hkRefNew<hkStreamReader> *__fastcall hkWin32FileSystem::openReader(hkWin32FileSystem *this, hkRefNew<hkStreamReader> *result, const char *name, hkFileSystem::OpenFlags flags)
{
  hkWin32FileSystem *v4; // rbx
  hkRefNew<hkStreamReader> *v5; // rsi
  hkFileSystem::OpenFlags v6; // edi
  hkStdioStreamReader *v7; // rax
  hkStreamReader *v8; // rax
  int v9; // er8
  hkStringBuf filename; // [rsp+20h] [rbp-98h]

  v4 = this;
  v5 = result;
  v6 = flags;
  hkStringBuf::hkStringBuf(&filename, name);
  s_convertFileNameToNative(&filename);
  v7 = hkStdioStreamReader::open(filename.m_string.m_data);
  v8 = hkFileSystem::_handleFlags(
         (hkFileSystem *)&v4->vfptr,
         (hkStreamReader *)&v7->vfptr,
         (hkFileSystem::OpenFlags)(v6 & 0xFFFFFFFE));
  v9 = filename.m_string.m_capacityAndFlags;
  filename.m_string.m_size = 0;
  v5->m_pntr = v8;
  if ( v9 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      filename.m_string.m_data,
      v9 & 0x3FFFFFFF);
  return v5;
}

// File Line: 132
// RVA: 0xC7EBD0
hkRefNew<hkStreamWriter> *__fastcall hkWin32FileSystem::openWriter(hkWin32FileSystem *this, hkRefNew<hkStreamWriter> *result, const char *name, hkFileSystem::OpenFlags flags)
{
  hkWin32FileSystem *v4; // rbx
  hkRefNew<hkStreamWriter> *v5; // rsi
  hkFileSystem::OpenFlags v6; // edi
  int v7; // edx
  hkWin32StreamWriter *v8; // rax
  hkStreamWriter *v9; // rax
  int v10; // er8
  hkStringBuf filename; // [rsp+20h] [rbp-98h]

  v4 = this;
  v5 = result;
  v6 = flags;
  hkStringBuf::hkStringBuf(&filename, name);
  s_convertFileNameToNative(&filename);
  v7 = 4;
  if ( v6 & 2 )
    v7 = 2;
  v8 = hkWin32StreamWriter::open(filename.m_string.m_data, v7);
  v9 = hkFileSystem::_handleFlags((hkFileSystem *)&v4->vfptr, (hkStreamWriter *)&v8->vfptr, v6);
  v10 = filename.m_string.m_capacityAndFlags;
  filename.m_string.m_size = 0;
  v5->m_pntr = v9;
  if ( v10 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      filename.m_string.m_data,
      v10 & 0x3FFFFFFF);
  return v5;
}

// File Line: 144
// RVA: 0xC7EC80
__int64 __fastcall hkWin32FileSystem::remove(hkWin32FileSystem *this, const char *path)
{
  LPCWSTR *v2; // rax
  BOOL v3; // eax
  BOOL v4; // ebx
  hkUtf8::WideFromUtf8 v6; // [rsp+20h] [rbp-A8h]
  hkStringBuf filename; // [rsp+30h] [rbp-98h]

  hkStringBuf::hkStringBuf(&filename, path);
  s_convertFileNameToNative(&filename);
  hkUtf8::WideFromUtf8::WideFromUtf8(&v6, filename.m_string.m_data);
  v3 = DeleteFileW(*v2);
  v6.m_wide.m_size = 0;
  v4 = v3 == 0;
  if ( v6.m_wide.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v6.m_wide.m_data,
      2 * (v6.m_wide.m_capacityAndFlags & 0x3FFFFFFF));
  v6.m_wide.m_data = 0i64;
  v6.m_wide.m_capacityAndFlags = 2147483648;
  filename.m_string.m_size = 0;
  if ( filename.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      filename.m_string.m_data,
      filename.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return (unsigned int)v4;
}

// File Line: 149
// RVA: 0xC7ED40
__int64 __fastcall hkWin32FileSystem::mkdir(hkWin32FileSystem *this, const char *path)
{
  LPCWSTR *v2; // rax
  BOOL v3; // eax
  BOOL v4; // ebx
  hkUtf8::WideFromUtf8 v6; // [rsp+20h] [rbp-A8h]
  hkStringBuf filename; // [rsp+30h] [rbp-98h]

  hkStringBuf::hkStringBuf(&filename, path);
  s_convertFileNameToNative(&filename);
  hkUtf8::WideFromUtf8::WideFromUtf8(&v6, filename.m_string.m_data);
  v3 = CreateDirectoryW(*v2, 0i64);
  v6.m_wide.m_size = 0;
  v4 = v3 == 0;
  if ( v6.m_wide.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v6.m_wide.m_data,
      2 * (v6.m_wide.m_capacityAndFlags & 0x3FFFFFFF));
  v6.m_wide.m_data = 0i64;
  v6.m_wide.m_capacityAndFlags = 2147483648;
  filename.m_string.m_size = 0;
  if ( filename.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      filename.m_string.m_data,
      filename.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return (unsigned int)v4;
}

// File Line: 156
// RVA: 0xC7EE10
__int64 __fastcall hkWin32FileSystem::stat(hkWin32FileSystem *this, const char *path, hkFileSystem::Entry *entryOut)
{
  hkWin32FileSystem *v3; // r14
  hkFileSystem::Entry *v4; // rbp
  const char *v5; // rsi
  unsigned int v6; // ebx
  LPCWSTR *v7; // rax
  HANDLE v8; // rax
  void *v9; // rdi
  __int64 sz; // rax
  hkFileSystem::TimeStamp mt; // r8
  hkFlags<enum hkFileSystem::Entry::FlagValues,unsigned int> v12; // er9
  hkUtf8::WideFromUtf8 v14; // [rsp+30h] [rbp-2F8h]
  hkStringBuf filename; // [rsp+40h] [rbp-2E8h]
  _WIN32_FIND_DATAW FindFileData; // [rsp+D0h] [rbp-258h]

  v3 = this;
  v4 = entryOut;
  v5 = path;
  hkStringBuf::hkStringBuf(&filename, path);
  s_convertFileNameToNative(&filename);
  v6 = 1;
  while ( (unsigned int)hkStringBuf::endsWith(&filename, "\\") )
    hkStringBuf::chompEnd(&filename, 1);
  hkUtf8::WideFromUtf8::WideFromUtf8(&v14, filename.m_string.m_data);
  v8 = FindFirstFileW(*v7, &FindFileData);
  v14.m_wide.m_size = 0;
  v9 = v8;
  if ( v14.m_wide.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v14.m_wide.m_data,
      2 * (v14.m_wide.m_capacityAndFlags & 0x3FFFFFFF));
  v14.m_wide.m_data = 0i64;
  v14.m_wide.m_capacityAndFlags = 2147483648;
  if ( v9 != (void *)-1i64 )
  {
    s_convertWindowsFiletimeToUnixTime(
      FindFileData.ftLastWriteTime.dwHighDateTime,
      FindFileData.ftLastWriteTime.dwLowDateTime);
    sz = s_combineHiLoDwords(FindFileData.nFileSizeHigh, FindFileData.nFileSizeLow);
    hkFileSystem::Entry::setAll(v4, (hkFileSystem *)&v3->vfptr, v5, v12, mt, sz);
    FindClose(v9);
    v6 = 0;
  }
  filename.m_string.m_size = 0;
  if ( filename.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      filename.m_string.m_data,
      filename.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return v6;
}

// File Line: 199
// RVA: 0xC7F2A0
char __fastcall `anonymous namespace'::Win32Impl::advance(Win32Impl *this, hkFileSystem::Entry *e)
{
  hkFileSystem::Entry *v2; // r14
  Win32Impl *v3; // rbx
  char v4; // di
  _QWORD *v5; // rax
  LPCWSTR *v6; // rax
  HANDLE v7; // rax
  int v8; // er8
  char v9; // bl
  const char **v10; // rax
  bool v11; // al
  bool v12; // di
  void *v14; // rcx
  const char **v15; // rax
  bool v16; // al
  bool v17; // di
  hkUtf8::WideFromUtf8 v18; // [rsp+20h] [rbp-E0h]
  hkStringBuf filename; // [rsp+30h] [rbp-D0h]
  _WIN32_FIND_DATAW FindFileData; // [rsp+C0h] [rbp-40h]
  hkStringPtr v21; // [rsp+340h] [rbp+240h]
  hkStringPtr v22; // [rsp+350h] [rbp+250h]

  v2 = e;
  v3 = this;
  LODWORD(v21.m_stringAndFlag) = 0;
  if ( !this->m_handle )
  {
    hkStringBuf::hkStringBuf(&filename, &this->m_top);
    if ( (_QWORD)v3->m_wildcard.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v4 = 1;
      hkStringPtr::hkStringPtr(&v22, &v3->m_wildcard);
    }
    else
    {
      v4 = 2;
      hkStringPtr::hkStringPtr(&v21, pattern);
    }
    hkStringBuf::pathAppend(&filename, (const char *)(*v5 & 0xFFFFFFFFFFFFFFFEui64), 0i64, 0i64);
    if ( v4 & 2 )
    {
      v4 &= 0xFDu;
      hkStringPtr::~hkStringPtr(&v21);
    }
    if ( v4 & 1 )
      hkStringPtr::~hkStringPtr(&v22);
    s_convertFileNameToNative(&filename);
    hkUtf8::WideFromUtf8::WideFromUtf8(&v18, filename.m_string.m_data);
    v7 = FindFirstFileW(*v6, &FindFileData);
    v8 = v18.m_wide.m_capacityAndFlags;
    v18.m_wide.m_size = 0;
    v3->m_handle = v7;
    if ( v8 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v18.m_wide.m_data,
        2 * (v8 & 0x3FFFFFFF));
    if ( v3->m_handle == (void *)-1i64 )
    {
      v9 = 0;
LABEL_17:
      filename.m_string.m_size = 0;
      if ( filename.m_string.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
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
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v18.m_wide.m_data,
        v18.m_wide.m_capacityAndFlags & 0x3FFFFFFF);
    if ( v12 )
    {
      s_entryFromFindData(
        v2,
        v3->m_fs,
        (const char *)((_QWORD)v3->m_top.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
        &FindFileData);
      v9 = 1;
      goto LABEL_17;
    }
    filename.m_string.m_size = 0;
    if ( filename.m_string.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        filename.m_string.m_data,
        filename.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  }
  v14 = v3->m_handle;
  if ( v14 == (void *)-1i64 )
    return 0;
  if ( !FindNextFileW(v14, &FindFileData) )
  {
LABEL_28:
    FindClose(v3->m_handle);
    v3->m_handle = (void *)-1i64;
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
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v18.m_wide.m_data,
        v18.m_wide.m_capacityAndFlags & 0x3FFFFFFF);
    v18.m_wide.m_data = 0i64;
    v18.m_wide.m_capacityAndFlags = 2147483648;
    if ( v17 )
      break;
    if ( !FindNextFileW(v3->m_handle, &FindFileData) )
      goto LABEL_28;
  }
  s_entryFromFindData(
    v2,
    v3->m_fs,
    (const char *)((_QWORD)v3->m_top.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
    &FindFileData);
  return 1;
}

// File Line: 252
// RVA: 0xC7EFB0
hkRefNew<hkFileSystem::Iterator::Impl> *__fastcall hkWin32FileSystem::createIterator(hkWin32FileSystem *this, hkRefNew<hkFileSystem::Iterator::Impl> *result, const char *top, const char *wildcard)
{
  hkWin32FileSystem *v4; // r14
  const char *v5; // rsi
  const char *v6; // rbp
  hkRefNew<hkFileSystem::Iterator::Impl> *v7; // rdi
  _QWORD **v8; // rax
  __int64 v9; // rax
  hkStringPtr *v10; // rbx

  v4 = this;
  v5 = wildcard;
  v6 = top;
  v7 = result;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 48i64);
  v10 = (hkStringPtr *)v9;
  if ( v9 )
  {
    *(_DWORD *)(v9 + 8) = 0x1FFFF;
    *(_QWORD *)(v9 + 16) = v4;
    *(_QWORD *)v9 = &`anonymous namespace'::Win32Impl::`vftable';
    hkStringPtr::hkStringPtr((hkStringPtr *)(v9 + 24), v6);
    hkStringPtr::hkStringPtr(v10 + 4, v5);
    v10[5].m_stringAndFlag = 0i64;
    v7->m_pntr = (hkFileSystem::Iterator::Impl *)v10;
  }
  else
  {
    v7->m_pntr = 0i64;
  }
  return v7;
}

