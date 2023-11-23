// File Line: 17
// RVA: 0xC7F9F0
void __fastcall hkFileSystem::TimeStamp::set(hkFileSystem::TimeStamp *this, unsigned __int64 nsSinceEpoch)
{
  this->m_time = nsSinceEpoch;
}

// File Line: 22
// RVA: 0xC7FA00
unsigned __int64 __fastcall hkFileSystem::TimeStamp::get(hkFileSystem::TimeStamp *this)
{
  return this->m_time;
}

// File Line: 27
// RVA: 0xC7FA10
hkBool *__fastcall hkFileSystem::TimeStamp::isValid(hkFileSystem::TimeStamp *this, hkBool *result)
{
  result->m_bool = this->m_time != 0;
  return result;
}

// File Line: 34
// RVA: 0xC7FAF0
hkRefNew<hkStreamReader> *__fastcall hkFileSystem::Entry::openReader(
        hkFileSystem::Entry *this,
        hkRefNew<hkStreamReader> *result,
        unsigned int flags)
{
  ((void (__fastcall *)(hkFileSystem *, hkRefNew<hkStreamReader> *, unsigned __int64, _QWORD))this->m_fs->vfptr[1].__first_virtual_table_function__)(
    this->m_fs,
    result,
    (unsigned __int64)this->m_path.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
    flags);
  return result;
}

// File Line: 39
// RVA: 0xC7FB20
hkRefNew<hkStreamWriter> *__fastcall hkFileSystem::Entry::openWriter(
        hkFileSystem::Entry *this,
        hkRefNew<hkStreamWriter> *result,
        unsigned int flags)
{
  ((void (__fastcall *)(hkFileSystem *, hkRefNew<hkStreamWriter> *, unsigned __int64, _QWORD))this->m_fs->vfptr[2].__vecDelDtor)(
    this->m_fs,
    result,
    (unsigned __int64)this->m_path.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
    flags);
  return result;
}

// File Line: 44
// RVA: 0xC7FA80
void __fastcall hkFileSystem::Entry::setPath(hkFileSystem::Entry *this, hkFileSystem *fs, const char *path)
{
  this->m_fs = fs;
  hkStringPtr::operator=(&this->m_path, path);
}

// File Line: 51
// RVA: 0xC7FA30
char *__fastcall hkFileSystem::Entry::getName(hkFileSystem::Entry *this)
{
  char *result; // rax

  result = hkString::strRchr(
             (const char *)((unsigned __int64)this->m_path.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
             47);
  if ( !result )
    return (char *)((unsigned __int64)this->m_path.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  do
    ++result;
  while ( *result == 47 );
  if ( !*result )
    return (char *)((unsigned __int64)this->m_path.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  return result;
}

// File Line: 70
// RVA: 0xC7FAA0
void __fastcall hkFileSystem::Entry::setAll(
        hkFileSystem::Entry *this,
        hkFileSystem *fs,
        const char *fullPath,
        hkFlags<enum hkFileSystem::Entry::FlagValues,unsigned int> flags,
        hkFileSystem::TimeStamp mt,
        __int64 sz)
{
  this->m_fs = fs;
  hkStringPtr::operator=(&this->m_path, fullPath);
  this->m_flags = flags;
  this->m_mtime = mt;
  this->m_size = sz;
}

// File Line: 79
// RVA: 0xC7FD50
hkResult *__fastcall hkFileSystem::listDirectory(
        hkFileSystem *this,
        hkResult *result,
        const char *basePath,
        hkFileSystem::DirectoryListing *listingOut)
{
  hkFileSystem::Entry *v7; // rdi
  hkFileSystem::Iterator v9; // [rsp+20h] [rbp-58h] BYREF

  hkFileSystem::Iterator::Iterator(&v9, this, basePath, 0i64);
  for ( listingOut->m_fs = this; hkFileSystem::Iterator::advance(&v9); ++listingOut->m_entries.m_size )
  {
    if ( listingOut->m_entries.m_size == (listingOut->m_entries.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&listingOut->m_entries.m_data, 40);
    v7 = &listingOut->m_entries.m_data[listingOut->m_entries.m_size];
    if ( v7 )
    {
      v7->m_fs = v9.m_entry.m_fs;
      hkStringPtr::hkStringPtr(&v7->m_path, &v9.m_entry.m_path);
      v7->m_mtime.m_time = v9.m_entry.m_mtime.m_time;
      v7->m_size = v9.m_entry.m_size;
      v7->m_flags.m_storage = v9.m_entry.m_flags.m_storage;
    }
  }
  result->m_enum = HK_SUCCESS;
  hkFileSystem::Iterator::~Iterator(&v9);
  return result;
}

// File Line: 91
// RVA: 0xC7FB50
void __fastcall hkFileSystem::Iterator::Iterator(
        hkFileSystem::Iterator *this,
        hkFileSystem *fs,
        const char *top,
        const char *wildcard)
{
  hkStringPtr *v8; // rcx
  hkStringPtr strRef; // [rsp+30h] [rbp+8h] BYREF

  if ( fs )
    hkReferencedObject::addReference(fs);
  this->m_fs.m_pntr = fs;
  this->m_wildcard = wildcard;
  this->m_impl.m_pntr = 0i64;
  this->m_entry.m_fs = 0i64;
  hkStringPtr::hkStringPtr(&this->m_entry.m_path);
  this->m_entry.m_mtime.m_time = 0i64;
  this->m_entry.m_size = -1i64;
  this->m_entry.m_flags.m_storage = 0;
  this->m_todo.m_data = 0i64;
  this->m_todo.m_size = 0;
  this->m_todo.m_capacityAndFlags = 0x80000000;
  hkStringPtr::hkStringPtr(&strRef, top);
  if ( this->m_todo.m_size == (this->m_todo.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_todo.m_data, 8);
  v8 = &this->m_todo.m_data[this->m_todo.m_size];
  if ( v8 )
    hkStringPtr::hkStringPtr(v8, &strRef);
  ++this->m_todo.m_size;
  hkStringPtr::~hkStringPtr(&strRef);
}

// File Line: 97
// RVA: 0xC7FC30
char __fastcall hkFileSystem::Iterator::advance(hkFileSystem::Iterator *this)
{
  hkFileSystem::Iterator::Impl *m_pntr; // rcx
  hkFileSystem::Iterator::Impl *v3; // rcx
  hkFileSystem::Iterator::Impl **v4; // rax
  hkFileSystem::Iterator::Impl *v5; // rcx
  hkFileSystem::Iterator::Impl *v6; // rbx
  char v8; // [rsp+30h] [rbp+8h] BYREF

  while ( 1 )
  {
    m_pntr = this->m_impl.m_pntr;
    if ( m_pntr )
    {
      if ( ((unsigned __int8 (__fastcall *)(hkFileSystem::Iterator::Impl *, hkFileSystem::Entry *))m_pntr->vfptr[1].__first_virtual_table_function__)(
             m_pntr,
             &this->m_entry) )
      {
        return 1;
      }
      v3 = this->m_impl.m_pntr;
      if ( v3 )
        hkReferencedObject::removeReference(v3);
      this->m_impl.m_pntr = 0i64;
    }
    if ( !this->m_todo.m_size )
      break;
    v4 = (hkFileSystem::Iterator::Impl **)((__int64 (__fastcall *)(hkFileSystem *, char *, unsigned __int64, const char *))this->m_fs.m_pntr->vfptr[4].__vecDelDtor)(
                                            this->m_fs.m_pntr,
                                            &v8,
                                            (unsigned __int64)this->m_todo.m_data[this->m_todo.m_size - 1].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
                                            this->m_wildcard);
    v5 = this->m_impl.m_pntr;
    v6 = *v4;
    if ( v5 )
      hkReferencedObject::removeReference(v5);
    this->m_impl.m_pntr = v6;
    hkStringPtr::~hkStringPtr(&this->m_todo.m_data[this->m_todo.m_size - 1]);
    --this->m_todo.m_size;
  }
  return 0;
}

// File Line: 123
// RVA: 0xC7FCF0
bool __fastcall hkFileSystem::Iterator::nameAcceptable(const char *name, const char *wildcard)
{
  char v3; // al
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  if ( !*name )
    return 0;
  if ( *name == 46 )
  {
    v3 = name[1];
    if ( !v3 || v3 == 46 && !name[2] )
      return 0;
  }
  if ( wildcard )
    return hkString::endsWith(&result, name, wildcard + 1)->m_bool != 0;
  return 1;
}

// File Line: 140
// RVA: 0xC7FE40
hkStreamReader *__fastcall hkFileSystem::_handleFlags(
        hkFileSystem *this,
        hkStreamReader *sr,
        hkFileSystem::OpenFlags flags)
{
  _QWORD **Value; // rax
  hkBufferedStreamReader *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rdi

  if ( !sr || (flags & 1) == 0 )
    return sr;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkBufferedStreamReader *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 56i64);
  if ( v5 )
  {
    hkBufferedStreamReader::hkBufferedStreamReader(v5, sr, 0x4000);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  hkReferencedObject::removeReference(sr);
  return (hkStreamReader *)v7;
}

// File Line: 155
// RVA: 0xC7FEC0
hkStreamWriter *__fastcall hkFileSystem::_handleFlags(
        hkFileSystem *this,
        hkStreamWriter *sw,
        hkFileSystem::OpenFlags flags)
{
  _QWORD **Value; // rax
  hkBufferedStreamWriter *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rdi

  if ( !sw || (flags & 1) == 0 )
    return sw;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkBufferedStreamWriter *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  if ( v5 )
  {
    hkBufferedStreamWriter::hkBufferedStreamWriter(v5, sw, 4096);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  hkReferencedObject::removeReference(sw);
  return (hkStreamWriter *)v7;
}

// File Line: 168
// RVA: 0x15C7700
hkSingletonInitNode *dynamic_initializer_for__hkSingletonRegisterhkFileSystem__()
{
  hkSingletonInitNode *result; // rax

  hkSingletonRegisterhkFileSystem.m_next = hkSingletonInitList;
  result = &hkSingletonRegisterhkFileSystem;
  hkSingletonInitList = &hkSingletonRegisterhkFileSystem;
  return result;
}

