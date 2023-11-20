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
hkRefNew<hkStreamReader> *__fastcall hkFileSystem::Entry::openReader(hkFileSystem::Entry *this, hkRefNew<hkStreamReader> *result, hkFileSystem::OpenFlags flags)
{
  hkRefNew<hkStreamReader> *v3; // rbx

  v3 = result;
  ((void (__fastcall *)(hkFileSystem *, hkRefNew<hkStreamReader> *, unsigned __int64, _QWORD))this->m_fs->vfptr[1].__first_virtual_table_function__)(
    this->m_fs,
    result,
    (_QWORD)this->m_path.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
    (unsigned int)flags);
  return v3;
}

// File Line: 39
// RVA: 0xC7FB20
hkRefNew<hkStreamWriter> *__fastcall hkFileSystem::Entry::openWriter(hkFileSystem::Entry *this, hkRefNew<hkStreamWriter> *result, hkFileSystem::OpenFlags flags)
{
  hkRefNew<hkStreamWriter> *v3; // rbx

  v3 = result;
  ((void (__fastcall *)(hkFileSystem *, hkRefNew<hkStreamWriter> *, unsigned __int64, _QWORD))this->m_fs->vfptr[2].__vecDelDtor)(
    this->m_fs,
    result,
    (_QWORD)this->m_path.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
    (unsigned int)flags);
  return v3;
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
  hkFileSystem::Entry *v1; // rbx
  char *result; // rax

  v1 = this;
  result = hkString::strRchr((const char *)((_QWORD)this->m_path.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64), 47);
  if ( !result )
    return (char *)((_QWORD)v1->m_path.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  do
    ++result;
  while ( *result == 47 );
  if ( !*result )
    return (char *)((_QWORD)v1->m_path.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  return result;
}

// File Line: 70
// RVA: 0xC7FAA0
void __fastcall hkFileSystem::Entry::setAll(hkFileSystem::Entry *this, hkFileSystem *fs, const char *fullPath, hkFlags<enum hkFileSystem::Entry::FlagValues,unsigned int> flags, hkFileSystem::TimeStamp mt, __int64 sz)
{
  hkFileSystem::Entry *v6; // rbx
  unsigned int v7; // [rsp+48h] [rbp+20h]

  v7 = flags.m_storage;
  this->m_fs = fs;
  v6 = this;
  hkStringPtr::operator=(&this->m_path, fullPath);
  v6->m_flags.m_storage = v7;
  v6->m_mtime = mt;
  v6->m_size = sz;
}

// File Line: 79
// RVA: 0xC7FD50
hkResult *__fastcall hkFileSystem::listDirectory(hkFileSystem *this, hkResult *result, const char *basePath, hkFileSystem::DirectoryListing *listingOut)
{
  hkResult *v4; // rsi
  hkFileSystem *v5; // rdi
  hkFileSystem::DirectoryListing *v6; // rbx
  signed __int64 v7; // rdi
  hkFileSystem::Iterator v9; // [rsp+20h] [rbp-58h]

  v4 = result;
  v5 = this;
  v6 = listingOut;
  hkFileSystem::Iterator::Iterator(&v9, this, basePath, 0i64);
  for ( v6->m_fs = v5; hkFileSystem::Iterator::advance(&v9); ++v6->m_entries.m_size )
  {
    if ( v6->m_entries.m_size == (v6->m_entries.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 40);
    v7 = (signed __int64)&v6->m_entries.m_data[v6->m_entries.m_size];
    if ( v7 )
    {
      *(_QWORD *)v7 = v9.m_entry.m_fs;
      hkStringPtr::hkStringPtr((hkStringPtr *)(v7 + 8), &v9.m_entry.m_path);
      *(_QWORD *)(v7 + 16) = v9.m_entry.m_mtime.m_time;
      *(_QWORD *)(v7 + 24) = v9.m_entry.m_size;
      *(_DWORD *)(v7 + 32) = v9.m_entry.m_flags.m_storage;
    }
  }
  v4->m_enum = 0;
  hkFileSystem::Iterator::~Iterator(&v9);
  return v4;
}

// File Line: 91
// RVA: 0xC7FB50
void __fastcall hkFileSystem::Iterator::Iterator(hkFileSystem::Iterator *this, hkFileSystem *fs, const char *top, const char *wildcard)
{
  const char *v4; // rsi
  const char *v5; // rbp
  hkFileSystem *v6; // rbx
  hkFileSystem::Iterator *v7; // rdi
  hkStringPtr *v8; // rcx
  hkStringPtr strRef; // [rsp+30h] [rbp+8h]

  v4 = wildcard;
  v5 = top;
  v6 = fs;
  v7 = this;
  if ( fs )
    hkReferencedObject::addReference((hkReferencedObject *)&fs->vfptr);
  v7->m_fs.m_pntr = v6;
  v7->m_wildcard = v4;
  v7->m_impl.m_pntr = 0i64;
  v7->m_entry.m_fs = 0i64;
  hkStringPtr::hkStringPtr(&v7->m_entry.m_path);
  v7->m_entry.m_mtime.m_time = 0i64;
  v7->m_entry.m_size = -1i64;
  v7->m_entry.m_flags.m_storage = 0;
  v7->m_todo.m_data = 0i64;
  v7->m_todo.m_size = 0;
  v7->m_todo.m_capacityAndFlags = 2147483648;
  hkStringPtr::hkStringPtr(&strRef, v5);
  if ( v7->m_todo.m_size == (v7->m_todo.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_todo, 8);
  v8 = &v7->m_todo.m_data[v7->m_todo.m_size];
  if ( v8 )
    hkStringPtr::hkStringPtr(v8, &strRef);
  ++v7->m_todo.m_size;
  hkStringPtr::~hkStringPtr(&strRef);
}

// File Line: 97
// RVA: 0xC7FC30
char __fastcall hkFileSystem::Iterator::advance(hkFileSystem::Iterator *this)
{
  hkFileSystem::Iterator *i; // rdi
  hkFileSystem::Iterator::Impl *v2; // rcx
  hkReferencedObject *v3; // rcx
  hkFileSystem::Iterator::Impl **v4; // rax
  hkReferencedObject *v5; // rcx
  hkFileSystem::Iterator::Impl *v6; // rbx
  char v8; // [rsp+30h] [rbp+8h]

  for ( i = this; ; --i->m_todo.m_size )
  {
    v2 = i->m_impl.m_pntr;
    if ( v2 )
    {
      if ( ((unsigned __int8 (__fastcall *)(hkFileSystem::Iterator::Impl *, hkFileSystem::Entry *))v2->vfptr[1].__first_virtual_table_function__)(
             v2,
             &i->m_entry) )
      {
        return 1;
      }
      v3 = (hkReferencedObject *)&i->m_impl.m_pntr->vfptr;
      if ( v3 )
        hkReferencedObject::removeReference(v3);
      i->m_impl.m_pntr = 0i64;
    }
    if ( !i->m_todo.m_size )
      break;
    v4 = (hkFileSystem::Iterator::Impl **)((__int64 (__fastcall *)(hkFileSystem *, char *, unsigned __int64, const char *))i->m_fs.m_pntr->vfptr[4].__vecDelDtor)(
                                            i->m_fs.m_pntr,
                                            &v8,
                                            (_QWORD)i->m_todo.m_data[i->m_todo.m_size - 1].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
                                            i->m_wildcard);
    v5 = (hkReferencedObject *)&i->m_impl.m_pntr->vfptr;
    v6 = *v4;
    if ( v5 )
      hkReferencedObject::removeReference(v5);
    i->m_impl.m_pntr = v6;
    hkStringPtr::~hkStringPtr(&i->m_todo.m_data[i->m_todo.m_size - 1i64]);
  }
  return 0;
}

// File Line: 123
// RVA: 0xC7FCF0
bool __fastcall hkFileSystem::Iterator::nameAcceptable(const char *name, const char *wildcard)
{
  char v3; // al
  hkBool result; // [rsp+30h] [rbp+8h]

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
hkStreamReader *__fastcall hkFileSystem::_handleFlags(hkFileSystem *this, hkStreamReader *sr, hkFileSystem::OpenFlags flags)
{
  hkStreamReader *v3; // rbx
  _QWORD **v4; // rax
  hkBufferedStreamReader *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rdi

  v3 = sr;
  if ( !sr || !(flags & 1) )
    return sr;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkBufferedStreamReader *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 56i64);
  if ( v5 )
  {
    hkBufferedStreamReader::hkBufferedStreamReader(v5, v3, 0x4000);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v3->vfptr);
  return (hkStreamReader *)v7;
}

// File Line: 155
// RVA: 0xC7FEC0
hkStreamWriter *__fastcall hkFileSystem::_handleFlags(hkFileSystem *this, hkStreamWriter *sw, hkFileSystem::OpenFlags flags)
{
  hkStreamWriter *v3; // rbx
  _QWORD **v4; // rax
  hkBufferedStreamWriter *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rdi

  v3 = sw;
  if ( !sw || !(flags & 1) )
    return sw;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkBufferedStreamWriter *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 48i64);
  if ( v5 )
  {
    hkBufferedStreamWriter::hkBufferedStreamWriter(v5, v3, 4096);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v3->vfptr);
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

