// File Line: 94
// RVA: 0xE4E520
void __fastcall `anonymous namespace::IntReader::readArray(IntReader *this, hkDataArray *arr)
{
  __int64 m_remaining; // r15
  __int64 v5; // rbp
  const char *m_cur; // r8
  unsigned __int8 v7; // al
  const char *v8; // r8
  int v9; // r9d
  char *m_data; // rdx
  hkIArchive *m_archive; // rcx
  char *v12; // rcx
  int v13; // esi
  int v14; // r14d
  int v15; // edi
  char v16; // al
  int v17; // r9d
  char *v18; // rdx
  hkIArchive *v19; // rcx
  char *v20; // rcx
  char v21; // cl
  _DWORD *v22; // [rsp+30h] [rbp-38h] BYREF
  int v23; // [rsp+38h] [rbp-30h]
  int v24; // [rsp+3Ch] [rbp-2Ch]
  hkResult v25; // [rsp+70h] [rbp+8h] BYREF

  m_remaining = this->m_remaining;
  v22 = 0i64;
  v23 = 0;
  v24 = 0x80000000;
  if ( (int)m_remaining > 0 )
    hkArrayUtil::_reserve(&v25, &hkContainerTempAllocator::s_alloc, (const void **)&v22, m_remaining, 4);
  v23 = m_remaining;
  v5 = 0i64;
  if ( (int)m_remaining > 0 )
  {
    do
    {
      m_cur = this->m_cur;
      if ( m_cur >= this->m_end )
      {
        v9 = this->m_remaining;
        m_data = this->m_buffer.m_data;
        m_archive = this->m_archive;
        this->m_buffer.m_size = this->m_remaining;
        hkIArchive::readArrayGeneric(m_archive, m_data, 1, v9);
        v12 = this->m_buffer.m_data;
        this->m_cur = v12;
        v8 = v12 + 1;
        this->m_end = &v12[this->m_buffer.m_size];
        v7 = *v12;
      }
      else
      {
        v7 = *m_cur;
        v8 = m_cur + 1;
      }
      this->m_cur = v8;
      v13 = 6;
      v14 = v7 & 1;
      v15 = (v7 >> 1) & 0x7FFFFFBF;
      if ( (v7 & 0x80u) != 0 )
      {
        do
        {
          if ( v8 >= this->m_end )
          {
            v17 = this->m_remaining;
            v18 = this->m_buffer.m_data;
            v19 = this->m_archive;
            this->m_buffer.m_size = this->m_remaining;
            hkIArchive::readArrayGeneric(v19, v18, 1, v17);
            v20 = this->m_buffer.m_data;
            this->m_cur = v20;
            v8 = v20 + 1;
            this->m_end = &v20[this->m_buffer.m_size];
            v16 = *v20;
          }
          else
          {
            v16 = *v8++;
          }
          v21 = v13;
          v13 += 7;
          this->m_cur = v8;
          v15 |= (v16 & 0x7F) << v21;
        }
        while ( v16 < 0 );
      }
      --this->m_remaining;
      if ( v14 )
        v15 = -v15;
      v22[v5++] = v15;
    }
    while ( v5 < m_remaining );
  }
  ((void (__fastcall *)(hkDataArrayImpl *, _DWORD *, _QWORD))arr->m_impl->vfptr[32].__vecDelDtor)(
    arr->m_impl,
    v22,
    (unsigned int)m_remaining);
  v23 = 0;
  if ( v24 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v22, 4 * v24);
}

// File Line: 133
// RVA: 0xE4D440
void __fastcall `anonymous namespace::Reader::Reader(Reader *this, hkStreamReader *sr, hkDataWorld *cont)
{
  LODWORD(this->m_parser.vfptr) = -1;
  hkIArchive::hkIArchive((hkIArchive *)&this->m_parser.m_memSizeAndFlags, sr, 0);
  this->m_parser.m_keys.m_data = (const char **)cont;
  *(_QWORD *)&this->m_parser.m_keys.m_size = 0i64;
  this->m_parser.m_keyStorage.m_data = 0i64;
  this->m_parser.m_keyStorage.m_size = 0;
  this->m_parser.m_keyStorage.m_capacityAndFlags = 0x80000000;
  this->m_parser.m_lex.vfptr = 0i64;
  *(_DWORD *)&this->m_parser.m_lex.m_memSizeAndFlags = 0;
  *(_DWORD *)(&this->m_parser.m_lex.m_referenceCount + 1) = 0x80000000;
  LODWORD(this->m_parser.m_lex.m_buffer.vfptr) = 0;
  *(_QWORD *)&this->m_parser.m_lex.m_buffer.m_memSizeAndFlags = 0i64;
  this->m_parser.m_lex.m_buffer.m_bufferStart = 0;
  this->m_parser.m_lex.m_buffer.m_lexemeStart = 0x80000000;
  this->m_parser.m_lex.m_buffer.m_pos = 0i64;
  LODWORD(this->m_parser.m_lex.m_buffer.m_buffer.m_data) = 0;
  HIDWORD(this->m_parser.m_lex.m_buffer.m_buffer.m_data) = -1;
  if ( this->m_parser.m_keyStorage.m_size == (this->m_parser.m_keyStorage.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_parser.m_keyStorage.m_data, 8);
  *(_QWORD *)&this->m_parser.m_keyStorage.m_data[8 * this->m_parser.m_keyStorage.m_size++] = 0i64;
  if ( *(_DWORD *)&this->m_parser.m_lex.m_memSizeAndFlags == (*(_DWORD *)(&this->m_parser.m_lex.m_referenceCount + 1) & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_parser.m_lex.vfptr, 8);
  *((_QWORD *)&this->m_parser.m_lex.vfptr->__vecDelDtor + (int)(*(_DWORD *)&this->m_parser.m_lex.m_memSizeAndFlags)++) = &customCaption;
  if ( *(_DWORD *)&this->m_parser.m_lex.m_memSizeAndFlags == (*(_DWORD *)(&this->m_parser.m_lex.m_referenceCount + 1) & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_parser.m_lex.vfptr, 8);
  *((_QWORD *)&this->m_parser.m_lex.vfptr->__vecDelDtor + (int)(*(_DWORD *)&this->m_parser.m_lex.m_memSizeAndFlags)++) = 0i64;
  LODWORD(this->m_parser.m_lex.m_buffer.vfptr) = 2;
}

// File Line: 144
// RVA: 0xE4D600
void __fastcall `anonymous namespace::Reader::~Reader(Reader *this)
{
  __int64 vfptr_low; // rsi
  __int64 v3; // r14
  _DWORD *v4; // rbx
  hkMemoryAllocator **Value; // rax
  int m_lexemeStart; // r8d
  int v7; // r8d
  int m_capacityAndFlags; // r8d

  vfptr_low = SLODWORD(this->m_parser.m_lex.m_buffer.vfptr);
  if ( (int)vfptr_low < *(_DWORD *)&this->m_parser.m_lex.m_memSizeAndFlags )
  {
    v3 = 8 * vfptr_low;
    do
    {
      v4 = *(void *(__fastcall **)(hkBaseObject *, unsigned int))((char *)&this->m_parser.m_lex.vfptr->__vecDelDtor + v3);
      Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      hkMemoryRouter::easyFree(Value[11], v4);
      LODWORD(vfptr_low) = vfptr_low + 1;
      v3 += 8i64;
    }
    while ( (int)vfptr_low < *(_DWORD *)&this->m_parser.m_lex.m_memSizeAndFlags );
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_parser.m_lex.m_buffer.m_pos,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_parser.m_lex.m_buffer.m_pos);
  m_lexemeStart = this->m_parser.m_lex.m_buffer.m_lexemeStart;
  this->m_parser.m_lex.m_buffer.m_bufferStart = 0;
  if ( m_lexemeStart >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)&this->m_parser.m_lex.m_buffer.m_memSizeAndFlags,
      8 * m_lexemeStart);
  *(_QWORD *)&this->m_parser.m_lex.m_buffer.m_memSizeAndFlags = 0i64;
  this->m_parser.m_lex.m_buffer.m_lexemeStart = 0x80000000;
  v7 = *(_DWORD *)(&this->m_parser.m_lex.m_referenceCount + 1);
  *(_DWORD *)&this->m_parser.m_lex.m_memSizeAndFlags = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_parser.m_lex.vfptr,
      8 * v7);
  this->m_parser.m_lex.vfptr = 0i64;
  *(_DWORD *)(&this->m_parser.m_lex.m_referenceCount + 1) = 0x80000000;
  m_capacityAndFlags = this->m_parser.m_keyStorage.m_capacityAndFlags;
  this->m_parser.m_keyStorage.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_parser.m_keyStorage.m_data,
      8 * m_capacityAndFlags);
  this->m_parser.m_keyStorage.m_data = 0i64;
  this->m_parser.m_keyStorage.m_capacityAndFlags = 0x80000000;
  hkIArchive::~hkIArchive((hkIArchive *)&this->m_parser.m_memSizeAndFlags);
}

// File Line: 154
// RVA: 0xE4F1D0
hkResult *__fastcall `anonymous namespace::Reader::readHeader(
        Reader *this,
        hkResult *result,
        hkBinaryTagfile::Header *out)
{
  unsigned __int16 *p_m_memSizeAndFlags; // rsi
  unsigned int v7; // ecx
  int v8; // r14d
  int v9; // r13d
  int v10; // r15d
  int v11; // edi
  char v12; // cl
  int v13; // r15d
  int v14; // edi
  char v15; // cl
  int m_version; // eax
  const char *String; // rax
  hkOstream *v18; // rax
  char v19[4]; // [rsp+20h] [rbp-E0h] BYREF
  unsigned int array; // [rsp+24h] [rbp-DCh] BYREF
  unsigned int v21; // [rsp+28h] [rbp-D8h] BYREF
  hkErrStream v22; // [rsp+30h] [rbp-D0h] BYREF
  char buf[512]; // [rsp+50h] [rbp-B0h] BYREF
  int resulta; // [rsp+2A8h] [rbp+1A8h] BYREF

  p_m_memSizeAndFlags = &this->m_parser.m_memSizeAndFlags;
  hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 4, 1);
  if ( !hkIArchive::isOk((hkIArchive *)p_m_memSizeAndFlags, (hkBool *)&resulta)->m_bool )
    goto LABEL_2;
  hkIArchive::readArrayGeneric((hkIArchive *)p_m_memSizeAndFlags, &v21, 4, 1);
  if ( !hkIArchive::isOk((hkIArchive *)p_m_memSizeAndFlags, (hkBool *)&resulta)->m_bool )
    goto LABEL_2;
  v7 = v21;
  if ( array != -894431970 || v21 != -804128050 )
  {
    HIBYTE(resulta) = array;
    LOBYTE(resulta) = HIBYTE(array);
    BYTE1(resulta) = BYTE2(array);
    BYTE2(resulta) = BYTE1(array);
    if ( resulta != -894431970
      || (HIBYTE(resulta) = v21,
          LOBYTE(resulta) = HIBYTE(v21),
          BYTE1(resulta) = BYTE2(v21),
          BYTE2(resulta) = BYTE1(v21),
          resulta != -804128050) )
    {
LABEL_2:
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  out->m_magic1 = array;
  out->m_magic2 = v7;
  hkIArchive::readArrayGeneric((hkIArchive *)p_m_memSizeAndFlags, &resulta, 1, 1);
  v8 = 6;
  v9 = resulta & 1;
  v10 = 6;
  v11 = ((unsigned __int8)resulta >> 1) & 0x7FFFFFBF;
  if ( (resulta & 0x80u) != 0 )
  {
    do
    {
      hkIArchive::readArrayGeneric((hkIArchive *)p_m_memSizeAndFlags, v19, 1, 1);
      v12 = v10;
      v10 += 7;
      v11 |= (v19[0] & 0x7F) << v12;
    }
    while ( v19[0] < 0 );
  }
  if ( v9 )
    v11 = -v11;
  out->m_fileInfo = v11;
  if ( !hkIArchive::isOk((hkIArchive *)p_m_memSizeAndFlags, (hkBool *)&resulta)->m_bool )
    goto LABEL_26;
  hkIArchive::readArrayGeneric((hkIArchive *)p_m_memSizeAndFlags, &resulta, 1, 1);
  v13 = resulta & 1;
  v14 = ((unsigned __int8)resulta >> 1) & 0x7FFFFFBF;
  if ( (resulta & 0x80u) != 0 )
  {
    do
    {
      hkIArchive::readArrayGeneric((hkIArchive *)p_m_memSizeAndFlags, v19, 1, 1);
      v15 = v8;
      v8 += 7;
      v14 |= (v19[0] & 0x7F) << v15;
    }
    while ( v19[0] < 0 );
  }
  if ( v13 )
    v14 = -v14;
  out->m_version = v14;
  if ( !hkIArchive::isOk((hkIArchive *)p_m_memSizeAndFlags, (hkBool *)&resulta)->m_bool )
    goto LABEL_26;
  m_version = out->m_version;
  if ( m_version < 0 )
  {
LABEL_25:
    hkErrStream::hkErrStream(&v22, buf, 512);
    v18 = hkOstream::operator<<(&v22, "Unrecognised tagfile version ");
    hkOstream::operator<<(v18, (unsigned int)this->m_parser.vfptr);
    hkError::messageWarning(0x2AB6036Fu, buf, "Tagfile\\Binary\\hkBinaryTagfileReader.cpp", 193);
    hkOstream::~hkOstream(&v22);
LABEL_26:
    result->m_enum = HK_FAILURE;
    return result;
  }
  if ( m_version > 3 )
  {
    if ( m_version == 4 )
    {
      if ( this->m_parser.m_lex.m_buffer.m_bufferStart == (this->m_parser.m_lex.m_buffer.m_lexemeStart & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&this->m_parser.m_lex.m_buffer.m_memSizeAndFlags,
          8);
      *(_QWORD *)(*(_QWORD *)&this->m_parser.m_lex.m_buffer.m_memSizeAndFlags
                + 8i64 * this->m_parser.m_lex.m_buffer.m_bufferStart++) = 0i64;
      String = `anonymous namespace::Reader::readString(this);
      hkStringPtr::operator=(&out->m_sdk, String);
      goto LABEL_24;
    }
    goto LABEL_25;
  }
LABEL_24:
  result->m_enum = HK_SUCCESS;
  return result;
}String);
      goto LABEL_24;
    }
    goto LABE

// File Line: 253
// RVA: 0xE50190
const char *__fastcall `anonymous namespace::Reader::readString(Reader *this)
{
  int v2; // edi
  int v3; // ebp
  int v4; // ebx
  char v5; // cl
  hkMemoryAllocator **Value; // rax
  void *v7; // rdi
  unsigned __int8 array; // [rsp+40h] [rbp+8h] BYREF
  char v10; // [rsp+48h] [rbp+10h] BYREF

  hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 1, 1);
  v2 = 6;
  v3 = array & 1;
  v4 = (array >> 1) & 0x7FFFFFBF;
  if ( (array & 0x80u) != 0 )
  {
    do
    {
      hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &v10, 1, 1);
      v5 = v2;
      v2 += 7;
      v4 |= (v10 & 0x7F) << v5;
    }
    while ( v10 < 0 );
  }
  if ( v3 )
    v4 = -v4;
  if ( v4 <= 0 )
    return (const char *)*((_QWORD *)&this->m_parser.m_lex.vfptr->__vecDelDtor - v4);
  Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (void *)hkMemoryRouter::easyAlloc(Value[11], v4 + 1);
  hkIArchive::readRaw((hkIArchive *)&this->m_parser.m_memSizeAndFlags, v7, v4);
  *((_BYTE *)v7 + v4) = 0;
  if ( *(_DWORD *)&this->m_parser.m_lex.m_memSizeAndFlags == (*(_DWORD *)(&this->m_parser.m_lex.m_referenceCount + 1) & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_parser.m_lex.vfptr, 8);
  *((_QWORD *)&this->m_parser.m_lex.vfptr->__vecDelDtor + (int)(*(_DWORD *)&this->m_parser.m_lex.m_memSizeAndFlags)++) = v7;
  return (const char *)v7;
}

// File Line: 270
// RVA: 0xE4F1A0
float __fastcall `anonymous namespace::Reader::readFloat(Reader *this)
{
  float array; // [rsp+30h] [rbp+8h] BYREF

  hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 4, 1);
  return array;
}

// File Line: 275
// RVA: 0xE4EC20
void __fastcall `anonymous namespace::Reader::readBitfield(
        Reader *this,
        int numMembers,
        hkLocalArray<unsigned char> *bout)
{
  int v5; // esi
  int v7; // ecx
  __int64 v8; // rbp
  int v9; // ecx
  int v10; // r9d
  __int64 v11; // r8
  unsigned int v12; // edx
  char v13; // cl
  char v14; // cl
  char v15; // cl
  char v16; // cl
  char v17; // cl
  char v18; // cl
  int v19; // eax
  int v20; // eax
  int v21; // r9d
  char array[64]; // [rsp+30h] [rbp-58h] BYREF
  hkResult result; // [rsp+98h] [rbp+10h] BYREF

  v5 = (numMembers + 7) & 0xFFFFFFF8;
  v7 = bout->m_capacityAndFlags & 0x3FFFFFFF;
  v8 = v5 / 8;
  if ( v7 < v5 )
  {
    v9 = 2 * v7;
    v10 = (numMembers + 7) & 0xFFFFFFF8;
    if ( v5 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&bout->m_data, v10, 1);
  }
  bout->m_size = v5;
  hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, array, 1, v8);
  v11 = 0i64;
  if ( (int)v8 > 0 )
  {
    do
    {
      v12 = (unsigned __int8)array[v11++];
      v13 = v12;
      v12 >>= 1;
      bout->m_data[8 * v11 - 8] = v13 & 1;
      v14 = v12 & 1;
      v12 >>= 1;
      bout->m_data[8 * v11 - 7] = v14;
      v15 = v12 & 1;
      v12 >>= 1;
      bout->m_data[8 * v11 - 6] = v15;
      v16 = v12 & 1;
      v12 >>= 1;
      bout->m_data[8 * v11 - 5] = v16;
      v17 = v12 & 1;
      v12 >>= 1;
      bout->m_data[8 * v11 - 4] = v17;
      v18 = v12 & 1;
      v12 >>= 1;
      bout->m_data[8 * v11 - 3] = v18;
      bout->m_data[8 * v11 - 2] = v12 & 1;
      bout->m_data[8 * v11 - 1] = (v12 & 2) != 0;
    }
    while ( v11 < v8 );
  }
  v19 = bout->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v19 < numMembers )
  {
    v20 = 2 * v19;
    v21 = numMembers;
    if ( numMembers < v20 )
      v21 = v20;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&bout->m_data, v21, 1);
  }
  bout->m_size = numMembers;
}

// File Line: 308
// RVA: 0xE4D740
void __fastcall `anonymous namespace::Reader::_readArrayInts(Reader *this, hkDataArray *arr, int size)
{
  IntReader v4; // [rsp+30h] [rbp-38h] BYREF
  hkResult v5; // [rsp+80h] [rbp+18h] BYREF

  if ( size > 0 )
  {
    v4.m_remaining = size;
    v4.m_archive = (hkIArchive *)&this->m_parser.m_memSizeAndFlags;
    v4.m_buffer.m_data = 0i64;
    v4.m_buffer.m_size = 0;
    v4.m_buffer.m_capacityAndFlags = 0x80000000;
    hkArrayUtil::_reserve(&v5, &hkContainerTempAllocator::s_alloc, (const void **)&v4.m_buffer.m_data, size, 1);
    v4.m_buffer.m_size = 0;
    v4.m_cur = v4.m_buffer.m_data;
    v4.m_end = v4.m_buffer.m_data;
    `anonymous namespace::IntReader::readArray(&v4, arr);
    v4.m_buffer.m_size = 0;
    if ( v4.m_buffer.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v4.m_buffer.m_data,
        v4.m_buffer.m_capacityAndFlags & 0x3FFFFFFF);
  }
}

// File Line: 318
// RVA: 0xE4D7F0
void __fastcall `anonymous namespace::Reader::_readArrayItems(Reader *this, hkDataArray *arr, int nelem)
{
  Reader *v3; // rdi
  int v4; // esi
  __int64 v5; // rbx
  int v6; // ecx
  void *v7; // rax
  void *v8; // rdx
  unsigned int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // r9d
  hkDataArrayImpl *v13; // rdx
  hkDataArrayImpl *p_m_memSizeAndFlags; // rdi
  int v15; // ecx
  int v16; // ebx
  int v17; // esi
  char v18; // cl
  hkDataArrayImpl *v19; // rdi
  unsigned __int64 v20; // rbx
  int v21; // ecx
  int v22; // esi
  hkIArchive *m_impl; // rdi
  char v24; // cl
  int v25; // ecx
  void *v26; // r10
  unsigned int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // r9d
  int v31; // eax
  int v32; // ebx
  int v33; // edi
  int v34; // eax
  hkIArchive *v35; // rsi
  char v36; // cl
  int v37; // eax
  hkDataArrayImpl *v38; // rdx
  int v39; // r8d
  _DWORD *v40; // r9
  _DWORD *v41; // rcx
  unsigned int v42; // eax
  __int64 v43; // rdx
  int v44; // eax
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int *v48; // r9
  _DWORD *v49; // rcx
  __int64 v50; // rdx
  int v51; // eax
  int v52; // ebx
  int v53; // edi
  int v54; // ecx
  hkIArchive *v55; // rsi
  char v56; // cl
  int v57; // edi
  unsigned __int16 *v58; // rax
  int j; // edi
  int i; // edi
  const char *String; // rax
  __int64 v62; // rbx
  int v63; // eax
  hkLifoAllocator *Value; // rax
  char *m_cur; // rcx
  char *v66; // rdx
  __int64 v67; // r8
  int v68; // edx
  hkLifoAllocator *v69; // rax
  char *v70; // rcx
  int v71; // edx
  char *v72; // r9
  __int64 v73; // rax
  __int64 v74; // r9
  int v75; // eax
  __int64 v76; // rdx
  char *v77; // rax
  __int64 v78; // rcx
  __int64 v79; // rdx
  char *v80; // rbx
  hkDataArrayImpl *v81; // rax
  hkDataArrayImpl *v82; // rcx
  __int64 v83; // rdx
  int v84; // ebx
  hkTypeManager::Type *v85; // rdi
  hkDataArrayImpl *v86; // rax
  int TupleSize; // eax
  hkDataArrayImpl *v88; // rcx
  bool v89; // zf
  bool v90; // cc
  int v91; // eax
  char *v92; // rsi
  signed int v93; // ebx
  hkLifoAllocator *v94; // rax
  int v95; // r8d
  int m_size; // eax
  char *m_localMemory; // rsi
  signed int v98; // ebx
  hkLifoAllocator *v99; // rax
  int v100; // r8d
  hkDataArrayImpl *v101; // rdi
  unsigned __int16 *v102; // rax
  int v103; // ecx
  unsigned int v104; // ebx
  int v105; // esi
  hkIArchive *v106; // rdi
  char v107; // cl
  hkDataArrayImpl *v108; // rax
  hkDataArrayImpl *v109; // rcx
  char v110[16]; // [rsp+30h] [rbp-89h] BYREF
  __int128 array; // [rsp+40h] [rbp-79h] BYREF
  __int64 v112; // [rsp+50h] [rbp-69h]
  __int64 v113; // [rsp+58h] [rbp-61h]
  hkDataArray v114; // [rsp+60h] [rbp-59h] BYREF
  hkDataArray v115[2]; // [rsp+70h] [rbp-49h] BYREF
  char *v116; // [rsp+80h] [rbp-39h] BYREF
  int v117; // [rsp+88h] [rbp-31h]
  int v118; // [rsp+8Ch] [rbp-2Dh]
  void *p; // [rsp+90h] [rbp-29h]
  int v120; // [rsp+98h] [rbp-21h]
  int v121; // [rsp+A0h] [rbp-19h] BYREF
  hkResult result; // [rsp+A4h] [rbp-15h] BYREF
  hkLocalArray<unsigned char> bout; // [rsp+B0h] [rbp-9h] BYREF
  unsigned __int16 *v127; // [rsp+138h] [rbp+7Fh] BYREF

  v3 = this;
  v4 = nelem;
  v5 = ((__int64 (__fastcall *)(hkDataArrayImpl *))arr->m_impl->vfptr[1].__vecDelDtor)(arr->m_impl);
  switch ( *(_DWORD *)v5 )
  {
    case 2:
      v6 = v4;
      *(_QWORD *)&array = 0i64;
      *((_QWORD *)&array + 1) = 0x8000000000000000ui64;
      if ( v4 )
      {
        LODWORD(v127) = v4;
        v7 = hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &v127);
        v6 = (int)v127;
        v8 = v7;
      }
      else
      {
        v8 = 0i64;
      }
      v9 = 0x80000000;
      *(_QWORD *)&array = v8;
      if ( v6 )
        v9 = v6;
      *((_QWORD *)&array + 1) = __PAIR64__(v9, v4);
      v10 = v9 & 0x3FFFFFFF;
      if ( v10 >= v4 )
      {
        result.m_enum = HK_SUCCESS;
      }
      else
      {
        v11 = 2 * v10;
        v12 = v4;
        if ( v4 < v11 )
          v12 = v11;
        hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&array, v12, 1);
        v8 = (void *)array;
      }
      hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, v8, 1, v4);
      ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))arr->m_impl->vfptr[35].__vecDelDtor)(
        arr->m_impl,
        array,
        (unsigned int)v4);
      DWORD2(array) = 0;
      if ( array >= 0 )
        goto LABEL_13;
      return;
    case 3:
      v25 = v4;
      *(_QWORD *)&array = 0i64;
      *((_QWORD *)&array + 1) = 0x8000000000000000ui64;
      if ( v4 )
      {
        LODWORD(v127) = 4 * v4;
        v26 = hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &v127);
        v25 = (int)v127 / 4;
      }
      else
      {
        v26 = 0i64;
      }
      v27 = 0x80000000;
      *(_QWORD *)&array = v26;
      if ( v25 )
        v27 = v25;
      *((_QWORD *)&array + 1) = __PAIR64__(v27, v4);
      v28 = v27 & 0x3FFFFFFF;
      if ( v28 < v4 )
      {
        v29 = 2 * v28;
        v30 = v4;
        if ( v4 < v29 )
          v30 = v29;
        hkArrayUtil::_reserve((hkResult *)&v127, &hkContainerTempAllocator::s_alloc, (const void **)&array, v30, 4);
        v26 = (void *)array;
      }
      DWORD2(array) = v4;
      hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, v26, 4, v4);
      ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))arr->m_impl->vfptr[28].__vecDelDtor)(
        arr->m_impl,
        array,
        DWORD2(array));
      DWORD2(array) = 0;
      if ( array >= 0 )
      {
LABEL_13:
        v13 = (hkDataArrayImpl *)array;
        goto LABEL_14;
      }
      return;
    case 4:
      if ( SLODWORD(v3->m_parser.vfptr) < 3 )
        goto LABEL_33;
      p_m_memSizeAndFlags = (hkDataArrayImpl *)&v3->m_parser.m_memSizeAndFlags;
      v115[0].m_impl = p_m_memSizeAndFlags;
      hkIArchive::readArrayGeneric((hkIArchive *)p_m_memSizeAndFlags, &v127, 1, 1);
      v15 = (unsigned __int8)v127 & 1;
      v16 = ((unsigned __int8)v127 >> 1) & 0x7FFFFFBF;
      LODWORD(v113) = (unsigned __int8)v15;
      if ( (char)v127 < 0 )
      {
        v17 = 6;
        do
        {
          hkIArchive::readArrayGeneric((hkIArchive *)p_m_memSizeAndFlags, v110, 1, 1);
          v18 = v17;
          v17 += 7;
          v16 |= (v110[0] & 0x7F) << v18;
        }
        while ( v110[0] < 0 );
        v4 = nelem;
        v15 = v113;
      }
      if ( v15 )
        v16 = -v16;
      if ( v16 == 4 )
      {
        v3 = this;
LABEL_33:
        `anonymous namespace::Reader::_readArrayInts(v3, arr, v4);
        return;
      }
      LODWORD(v19) = 0;
      v114.m_impl = 0i64;
      if ( v4 > 0 )
      {
        do
        {
          hkIArchive::readArrayGeneric((hkIArchive *)v115[0].m_impl, &v127, 1, 1);
          LODWORD(v113) = 6;
          v20 = ((unsigned __int64)(unsigned __int8)v127 >> 1) & 0x7FFFFFFFFFFFFFBFi64;
          v21 = (unsigned __int8)v127 & 1;
          LODWORD(v112) = v21;
          if ( (char)v127 < 0 )
          {
            v22 = v113;
            m_impl = (hkIArchive *)v115[0].m_impl;
            do
            {
              hkIArchive::readArrayGeneric(m_impl, v110, 1, 1);
              v24 = v22;
              v22 += 7;
              v20 |= (unsigned __int64)(v110[0] & 0x7F) << v24;
            }
            while ( v110[0] < 0 );
            LODWORD(v19) = v114.m_impl;
            v4 = nelem;
            v21 = v112;
          }
          if ( v21 )
            v20 = -(__int64)v20;
          ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, unsigned __int64))arr->m_impl->vfptr[20].__vecDelDtor)(
            arr->m_impl,
            (unsigned int)v19,
            v20);
          v19 = (hkDataArrayImpl *)(unsigned int)((_DWORD)v19 + 1);
          v114.m_impl = v19;
        }
        while ( (int)v19 < v4 );
      }
      return;
    case 5:
      for ( i = 0; i < v4; ++i )
      {
        String = `anonymous namespace::Reader::readString(this);
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, const char *))arr->m_impl->vfptr[14].__vecDelDtor)(
          arr->m_impl,
          (unsigned int)i,
          String);
      }
      return;
    case 6:
      arr->m_impl->vfptr[4].__vecDelDtor(arr->m_impl, v4);
      v62 = ((__int64 (__fastcall *)(hkDataArrayImpl *))arr->m_impl->vfptr[6].__vecDelDtor)(arr->m_impl);
      v63 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v62 + 72i64))(v62);
      bout.m_data = 0i64;
      bout.m_size = 0;
      bout.m_capacityAndFlags = 0x80000000;
      LODWORD(v127) = v63;
      bout.m_initialCapacity = 128;
      Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (char *)Value->m_cur;
      v66 = m_cur + 128;
      if ( Value->m_slabSize < 128 || v66 > Value->m_end )
        m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, 128);
      else
        Value->m_cur = v66;
      bout.m_data = m_cur;
      bout.m_localMemory = m_cur;
      bout.m_capacityAndFlags = -2147483520;
      `anonymous namespace::Reader::readBitfield(this, (int)v127, &bout);
      v67 = (unsigned int)v127;
      v68 = 0;
      v116 = 0i64;
      v117 = 0;
      v118 = 0x80000000;
      v120 = (int)v127;
      if ( (_DWORD)v127 )
      {
        v69 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v67 = (unsigned int)v127;
        v70 = (char *)v69->m_cur;
        v71 = (32 * (_DWORD)v127 + 127) & 0xFFFFFF80;
        v72 = &v70[v71];
        if ( v71 > v69->m_slabSize || v72 > v69->m_end )
        {
          v73 = hkLifoAllocator::allocateFromNewSlab(v69, v71);
          v67 = (unsigned int)v127;
          v68 = v117;
          v70 = (char *)v73;
        }
        else
        {
          v69->m_cur = v72;
          v68 = v117;
        }
      }
      else
      {
        v70 = 0i64;
      }
      v116 = v70;
      p = v70;
      v118 = v67 | 0x80000000;
      v74 = 32i64 * v68 + 16;
      v75 = v67 - v68;
      v76 = (int)v67 - v68;
      if ( v75 > 0 )
      {
        v77 = &v70[v74];
        do
        {
          if ( v77 != (char *)16 )
          {
            *((_QWORD *)v77 - 2) = 0i64;
            *((_QWORD *)v77 - 1) = 0i64;
            *(_QWORD *)v77 = 0i64;
            *((_QWORD *)v77 + 1) = 0i64;
          }
          v77 += 32;
          --v76;
        }
        while ( v76 );
      }
      v117 = v67;
      (*(void (__fastcall **)(__int64, char **, __int64, __int64))(*(_QWORD *)v62 + 96i64))(v62, &v116, v67, v74);
      v78 = 0i64;
      v113 = 0i64;
      if ( (int)v127 > 0 )
      {
        v79 = 0i64;
        v112 = 0i64;
        do
        {
          v80 = v116;
          if ( bout.m_data[v78] )
          {
            v81 = (hkDataArrayImpl *)arr->m_impl->vfptr[10].__vecDelDtor(arr->m_impl, *(_QWORD *)&v116[v79]);
            v82 = v81;
            v114.m_impl = v81;
            if ( v81 )
            {
              ++v81->m_externalCount;
              ++v81->m_count;
              v82 = v114.m_impl;
            }
            v83 = *(_QWORD *)&v80[v112 + 16];
            if ( *(_DWORD *)v83 == 9 && (**(_DWORD **)(v83 + 8) != 3 || ((*(_DWORD *)(v83 + 16) - 4) & 0xFFFFFFF3) != 0) )
            {
              v84 = 0;
              if ( v4 > 0 )
              {
                v85 = (hkTypeManager::Type *)v83;
                do
                {
                  v86 = (hkDataArrayImpl *)v82->vfptr[23].__vecDelDtor(v82, v84);
                  v115[0].m_impl = v86;
                  if ( v86 )
                  {
                    ++v86->m_externalCount;
                    ++v86->m_count;
                  }
                  TupleSize = hkTypeManager::Type::getTupleSize(v85);
                  `anonymous namespace::Reader::_readArrayItems(this, v115, TupleSize);
                  v88 = v115[0].m_impl;
                  if ( v115[0].m_impl )
                  {
                    --v115[0].m_impl->m_externalCount;
                    v89 = v88->m_count-- == 1;
                    if ( v89 )
                      v88->vfptr->__vecDelDtor(v88, 1u);
                  }
                  v82 = v114.m_impl;
                  ++v84;
                }
                while ( v84 < v4 );
              }
            }
            else
            {
              `anonymous namespace::Reader::_readArrayItems(this, &v114, v4);
              v82 = v114.m_impl;
            }
            if ( v82 )
            {
              --v82->m_externalCount;
              v89 = v82->m_count-- == 1;
              if ( v89 )
                v82->vfptr->__vecDelDtor(v82, 1u);
            }
          }
          v112 += 32i64;
          v79 = v112;
          v90 = v113 + 1 < (int)v127;
          v78 = ++v113;
        }
        while ( v90 );
      }
      v91 = v117;
      v92 = (char *)p;
      if ( p == v116 )
        v91 = 0;
      v117 = v91;
      v93 = (32 * v120 + 127) & 0xFFFFFF80;
      v94 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v95 = (v93 + 15) & 0xFFFFFFF0;
      if ( v93 > v94->m_slabSize || &v92[v95] != v94->m_cur || v94->m_firstNonLifoEnd == v92 )
        hkLifoAllocator::slowBlockFree(v94, v92, v95);
      else
        v94->m_cur = v92;
      v117 = 0;
      if ( v118 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v116, 32 * v118);
      m_size = bout.m_size;
      m_localMemory = bout.m_localMemory;
      v116 = 0i64;
      if ( bout.m_localMemory == bout.m_data )
        m_size = 0;
      v118 = 0x80000000;
      v98 = (bout.m_initialCapacity + 127) & 0xFFFFFF80;
      bout.m_size = m_size;
      v99 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v100 = (v98 + 15) & 0xFFFFFFF0;
      if ( v98 > v99->m_slabSize || &m_localMemory[v100] != v99->m_cur || v99->m_firstNonLifoEnd == m_localMemory )
        hkLifoAllocator::slowBlockFree(v99, m_localMemory, v100);
      else
        v99->m_cur = m_localMemory;
      bout.m_size = 0;
      if ( bout.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          bout.m_data,
          bout.m_capacityAndFlags & 0x3FFFFFFF);
      return;
    case 7:
      for ( j = 0; j < v4; ++j )
      {
        DWORD2(array) = j;
        *(hkDataArray *)&array = (hkDataArray)arr->m_impl;
        *(_OWORD *)&v115[0].m_impl = array;
        `anonymous namespace::Reader::readObjectIntoValue<hkDataArray_Value>(this, (hkDataArray_Value *)v115);
      }
      return;
    case 8:
      arr->m_impl->vfptr[4].__vecDelDtor(arr->m_impl, v4);
      LODWORD(v101) = 0;
      v114.m_impl = 0i64;
      if ( v4 > 0 )
      {
        v102 = &this->m_parser.m_memSizeAndFlags;
        *(_QWORD *)&array = &this->m_parser.m_memSizeAndFlags;
        do
        {
          hkIArchive::readArrayGeneric((hkIArchive *)v102, &v127, 1, 1);
          LODWORD(v112) = 6;
          v103 = (unsigned __int8)v127 & 1;
          v104 = ((unsigned __int8)v127 >> 1) & 0x7FFFFFBF;
          LODWORD(v113) = (unsigned __int8)v103;
          if ( (char)v127 < 0 )
          {
            v105 = v112;
            v106 = (hkIArchive *)array;
            do
            {
              hkIArchive::readArrayGeneric(v106, v110, 1, 1);
              v107 = v105;
              v105 += 7;
              v104 |= (v110[0] & 0x7F) << v107;
            }
            while ( v110[0] < 0 );
            LODWORD(v101) = v114.m_impl;
            v4 = nelem;
            v103 = v113;
          }
          if ( v103 )
            v104 = -v104;
          v108 = (hkDataArrayImpl *)arr->m_impl->vfptr[23].__vecDelDtor(arr->m_impl, (unsigned int)v101);
          v115[0].m_impl = v108;
          if ( v108 )
          {
            ++v108->m_externalCount;
            ++v108->m_count;
            v108 = v115[0].m_impl;
          }
          v108->vfptr[4].__vecDelDtor(v108, v104);
          `anonymous namespace::Reader::_readArrayItems(this, v115, v104);
          v109 = v115[0].m_impl;
          if ( v115[0].m_impl )
          {
            --v115[0].m_impl->m_externalCount;
            v89 = v109->m_count-- == 1;
            if ( v89 )
              v109->vfptr->__vecDelDtor(v109, 1u);
          }
          v102 = (unsigned __int16 *)array;
          v101 = (hkDataArrayImpl *)(unsigned int)((_DWORD)v101 + 1);
          v114.m_impl = v101;
        }
        while ( (int)v101 < v4 );
      }
      return;
    case 9:
      if ( *(_DWORD *)v5 == 9 && **(_DWORD **)(v5 + 8) == 3 && ((*(_DWORD *)(v5 + 16) - 4) & 0xFFFFFFF3) == 0 )
      {
        ((void (__fastcall *)(hkDataArrayImpl *, int *, char **))arr->m_impl->vfptr[8].__vecDelDtor)(
          arr->m_impl,
          &v121,
          &v116);
        if ( v121 )
        {
          v52 = hkTypeManager::Type::getTupleSize((hkTypeManager::Type *)v5);
          if ( v52 == 4 )
          {
            bout.m_capacityAndFlags = 0;
            *(_QWORD *)&array = &v3->m_parser.m_memSizeAndFlags;
            hkIArchive::readArrayGeneric((hkIArchive *)&v3->m_parser.m_memSizeAndFlags, &v127, 1, 1);
            v53 = 6;
            v54 = (unsigned __int8)v127 & 1;
            v52 = ((unsigned __int8)v127 >> 1) & 0x7FFFFFBF;
            LODWORD(v112) = (unsigned __int8)v54;
            if ( (char)v127 < 0 )
            {
              v55 = (hkIArchive *)array;
              do
              {
                hkIArchive::readArrayGeneric(v55, v110, 1, 1);
                v56 = v53;
                v53 += 7;
                v52 |= (v110[0] & 0x7F) << v56;
              }
              while ( v110[0] < 0 );
              v4 = nelem;
              v54 = v112;
            }
            if ( v54 )
              v52 = -v52;
          }
          v57 = 0;
          if ( v4 > 0 )
          {
            v58 = &this->m_parser.m_memSizeAndFlags;
            v127 = &this->m_parser.m_memSizeAndFlags;
            do
            {
              hkIArchive::readArrayGeneric((hkIArchive *)v58, &bout, 4, v52);
              ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, hkLocalArray<unsigned char> *))arr->m_impl->vfptr[12].__vecDelDtor)(
                arr->m_impl,
                (unsigned int)v57,
                &bout);
              v58 = v127;
              ++v57;
            }
            while ( v57 < v4 );
          }
        }
        else
        {
          v31 = hkTypeManager::Type::getTupleSize((hkTypeManager::Type *)v5);
          LODWORD(v113) = v31;
          v32 = v31;
          if ( v31 == 4 )
          {
            *(_QWORD *)&array = &v3->m_parser.m_memSizeAndFlags;
            hkIArchive::readArrayGeneric((hkIArchive *)&v3->m_parser.m_memSizeAndFlags, &v127, 1, 1);
            v33 = 6;
            v34 = (unsigned __int8)v127 & 1;
            v32 = ((unsigned __int8)v127 >> 1) & 0x7FFFFFBF;
            LODWORD(v112) = (unsigned __int8)v34;
            if ( (char)v127 < 0 )
            {
              v35 = (hkIArchive *)array;
              do
              {
                hkIArchive::readArrayGeneric(v35, v110, 1, 1);
                v36 = v33;
                v33 += 7;
                v32 |= (v110[0] & 0x7F) << v36;
              }
              while ( v110[0] < 0 );
              v4 = nelem;
              v34 = v112;
            }
            if ( v34 )
              v32 = -v32;
            v31 = v113;
          }
          v37 = v4 * v31;
          v38 = 0i64;
          v115[1].m_impl = (hkDataArrayImpl *)0x8000000000000000i64;
          LODWORD(v112) = v37;
          v115[0].m_impl = 0i64;
          if ( v37 > 0 )
          {
            hkArrayUtil::_reserve(
              (hkResult *)&v114,
              &hkContainerTempAllocator::s_alloc,
              (const void **)&v115[0].m_impl,
              v37,
              4);
            v38 = v115[0].m_impl;
            v37 = v112;
          }
          LODWORD(v115[1].m_impl) = v37;
          hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, v38, 4, v4 * v32);
          if ( (_DWORD)v113 != v32 )
          {
            v39 = 0;
            v40 = (_DWORD *)v115[0].m_impl + v32 * (v4 - 1);
            v41 = (_DWORD *)v115[0].m_impl + (int)v113 * (v4 - 1);
            if ( v4 >= 4 )
            {
              v42 = ((unsigned int)(v4 - 4) >> 2) + 1;
              v43 = v42;
              v39 = 4 * v42;
              do
              {
                v41[3] = 0;
                v41 -= 16;
                v41[18] = v40[2];
                v44 = v40[1];
                v40 -= 12;
                v41[17] = v44;
                v45 = v40[12];
                v41[15] = 0;
                v41[16] = v45;
                v41[14] = v40[11];
                v41[13] = v40[10];
                v46 = v40[9];
                v41[11] = 0;
                v41[12] = v46;
                v41[10] = v40[8];
                v41[9] = v40[7];
                v47 = v40[6];
                v41[7] = 0;
                v41[8] = v47;
                v41[6] = v40[5];
                v41[5] = v40[4];
                v41[4] = v40[3];
                --v43;
              }
              while ( v43 );
            }
            if ( v39 < v4 )
            {
              v48 = v40 + 1;
              v49 = v41 + 2;
              v50 = (unsigned int)(v4 - v39);
              do
              {
                v49[1] = 0;
                v49 -= 4;
                v49[4] = v48[1];
                v51 = *v48;
                v48 -= 3;
                v49[3] = v51;
                v49[2] = v48[2];
                --v50;
              }
              while ( v50 );
            }
          }
          ((void (__fastcall *)(hkDataArrayImpl *, hkDataArrayImpl *, _QWORD))arr->m_impl->vfptr[28].__vecDelDtor)(
            arr->m_impl,
            v115[0].m_impl,
            (unsigned int)v4);
          LODWORD(v115[1].m_impl) = 0;
          if ( SHIDWORD(v115[1].m_impl) >= 0 )
          {
            v13 = v115[0].m_impl;
LABEL_14:
            ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkDataArrayImpl *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
              &hkContainerTempAllocator::s_alloc,
              v13);
          }
        }
      }
      return;
    default:
      return;
  }
}

// File Line: 510
// RVA: 0xE4E700
void __fastcall `anonymous namespace::Reader::readBinaryValue(
        Reader *this,
        hkDataObject_Value *value,
        hkDataClass_MemberInfo *minfo)
{
  hkDataArrayImpl *v3; // rbx
  hkDataObjectImpl *m_impl; // rcx
  hkTypeManager::Type *m_type; // rdi
  hkTypeManager::SubType m_subType; // edx
  hkDataArrayImpl *v10; // rax
  hkDataArrayImpl *v11; // rbx
  int TupleSize; // eax
  int v13; // ebx
  int v14; // edi
  int v15; // r13d
  unsigned int v16; // r15d
  char v17; // cl
  hkTypeManager::Type *m_parent; // rcx
  int v19; // r13d
  int v20; // edi
  char v21; // cl
  __int64 v22; // rcx
  const char *v23; // rax
  hkTypeManager::Type *v24; // rax
  hkDataArrayImpl *v25; // rax
  bool v26; // zf
  int v27; // ebx
  int v28; // r15d
  unsigned __int64 v29; // rdi
  char v30; // cl
  int v31; // eax
  __int64 v32; // rbx
  __int64 i; // r15
  const char *v34; // rbx
  const char *TypeName; // rax
  hkDataClassImpl *v36; // rax
  hkDataObject *v37; // rax
  hkDataObjectImpl *v38; // rcx
  const char *String; // rax
  __int64 v40; // rcx
  hkDataObject result; // [rsp+18h] [rbp-29h] BYREF
  int v42; // [rsp+24h] [rbp-1Dh]
  hkDataObject_Value v43; // [rsp+28h] [rbp-19h] BYREF
  hkTypeManager::Type *v44; // [rsp+38h] [rbp-9h]
  const void *m_valuePtr; // [rsp+40h] [rbp-1h]
  hkDataArray arr; // [rsp+B0h] [rbp+6Fh] BYREF
  char array; // [rsp+B8h] [rbp+77h] BYREF
  hkDataObjectImpl *v48; // [rsp+C0h] [rbp+7Fh] BYREF

  arr.m_impl = v3;
  m_impl = value->m_impl;
  v48 = m_impl;
  if ( m_impl )
  {
    ++m_impl->m_externalCount;
    ++m_impl->m_count;
  }
  m_type = minfo->m_type;
  m_subType = m_type->m_subType;
  if ( m_type->m_subType == SUB_TYPE_TUPLE
    && (m_type->m_parent->m_subType != SUB_TYPE_REAL || ((m_type->m_extra.m_size - 4) & 0xFFFFFFF3) != 0) )
  {
    v10 = (hkDataArrayImpl *)value->m_impl->vfptr[10].__vecDelDtor(value->m_impl, value->m_handle);
    v11 = v10;
    arr.m_impl = v10;
    if ( v10 )
    {
      ++v10->m_externalCount;
      ++v10->m_count;
    }
    TupleSize = hkTypeManager::Type::getTupleSize(m_type);
    `anonymous namespace::Reader::_readArrayItems(this, &arr, TupleSize);
    if ( v11 )
    {
LABEL_25:
      --v11->m_externalCount;
      v26 = v11->m_count-- == 1;
      if ( v26 )
        v11->vfptr->__vecDelDtor(v11, 1u);
    }
  }
  else
  {
    if ( m_subType == SUB_TYPE_ARRAY )
    {
      (*((void (__fastcall **)(const char **))*this->m_parser.m_keys.m_data + 11))(this->m_parser.m_keys.m_data);
      v43 = *(hkDataObject_Value *)&minfo->m_name;
      v44 = minfo->m_type;
      m_valuePtr = minfo->m_valuePtr;
      hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &arr, 1, 1);
      v13 = 6;
      v14 = 6;
      v15 = (__int64)arr.m_impl & 1;
      v16 = (LOBYTE(arr.m_impl) >> 1) & 0x7FFFFFBF;
      if ( SLOBYTE(arr.m_impl) < 0 )
      {
        do
        {
          hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 1, 1);
          v17 = v14;
          v14 += 7;
          v16 |= (array & 0x7F) << v17;
        }
        while ( array < 0 );
      }
      if ( v15 )
        v16 = -v16;
      m_parent = hkDataObject_Value::getType(value)->m_parent;
      if ( m_parent->m_subType == SUB_TYPE_CLASS && !hkTypeManager::Type::getTypeName(m_parent) )
      {
        hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &arr, 1, 1);
        v19 = (__int64)arr.m_impl & 1;
        v20 = (LOBYTE(arr.m_impl) >> 1) & 0x7FFFFFBF;
        if ( SLOBYTE(arr.m_impl) < 0 )
        {
          do
          {
            hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 1, 1);
            v21 = v13;
            v13 += 7;
            v20 |= (array & 0x7F) << v21;
          }
          while ( array < 0 );
        }
        if ( v19 )
          v20 = -v20;
        v22 = *(_QWORD *)&this->m_parser.m_keyStorage.m_data[8 * v20];
        v23 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v22 + 16i64))(v22);
        v24 = hkTypeManager::addClass((hkTypeManager *)result.m_impl, v23);
        v44 = hkTypeManager::makeArray((hkTypeManager *)result.m_impl, v24);
      }
      v25 = (hkDataArrayImpl *)(*((__int64 (__fastcall **)(const char **, hkDataObjectImpl **, const struct _hkDataObject_MemberHandle *, hkDataObject_Value *))*this->m_parser.m_keys.m_data
                                + 5))(
                                 this->m_parser.m_keys.m_data,
                                 &v48,
                                 value->m_handle,
                                 &v43);
      v11 = v25;
      arr.m_impl = v25;
      if ( v25 )
      {
        ++v25->m_externalCount;
        ++v25->m_count;
      }
      v25->vfptr[4].__vecDelDtor(v25, v16);
      `anonymous namespace::Reader::_readArrayItems(this, &arr, v16);
      goto LABEL_25;
    }
    switch ( m_subType )
    {
      case SUB_TYPE_BYTE:
        hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &arr, 1, 1);
        ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, _QWORD))value->m_impl->vfptr[17].__vecDelDtor)(
          value->m_impl,
          value->m_handle,
          LOBYTE(arr.m_impl));
        break;
      case SUB_TYPE_REAL:
        `anonymous namespace::Reader::readFloat(this);
        value->m_impl->vfptr[20].__vecDelDtor(value->m_impl, (unsigned int)value->m_handle);
        break;
      case SUB_TYPE_INT:
        hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &arr, 1, 1);
        v27 = 6;
        v28 = (__int64)arr.m_impl & 1;
        v29 = ((unsigned __int64)LOBYTE(arr.m_impl) >> 1) & 0x7FFFFFFFFFFFFFBFi64;
        if ( SLOBYTE(arr.m_impl) < 0 )
        {
          do
          {
            hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 1, 1);
            v30 = v27;
            v27 += 7;
            v29 |= (unsigned __int64)(array & 0x7F) << v30;
          }
          while ( array < 0 );
        }
        if ( v28 )
          v29 = -(__int64)v29;
        ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, unsigned __int64))value->m_impl->vfptr[16].__vecDelDtor)(
          value->m_impl,
          value->m_handle,
          v29);
        break;
      case SUB_TYPE_CSTRING:
        String = `anonymous namespace::Reader::readString(this);
        ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, const char *))value->m_impl->vfptr[21].__vecDelDtor)(
          value->m_impl,
          value->m_handle,
          String);
        break;
      case SUB_TYPE_CLASS:
        if ( SLODWORD(this->m_parser.vfptr) < 2 )
          goto $LN4_199;
        v34 = *this->m_parser.m_keys.m_data;
        TypeName = hkTypeManager::Type::getTypeName(m_type);
        v36 = (hkDataClassImpl *)(*((__int64 (__fastcall **)(const char **, const char *))v34 + 9))(
                                   this->m_parser.m_keys.m_data,
                                   TypeName);
        v37 = `anonymous namespace::Reader::readObjectTopLevel(this, &result, TAG_OBJECT, v36);
        ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, hkDataObjectImpl *))value->m_impl->vfptr[23].__vecDelDtor)(
          value->m_impl,
          value->m_handle,
          v37->m_impl);
        v38 = result.m_impl;
        if ( result.m_impl )
        {
          --result.m_impl->m_externalCount;
          v26 = v38->m_count-- == 1;
          if ( v26 )
            v38->vfptr->__vecDelDtor(v38, 1u);
        }
        break;
      case SUB_TYPE_POINTER:
$LN4_199:
        v43 = *value;
        `anonymous namespace::Reader::readObjectIntoValue<hkDataObject_Value>(this, &v43);
        break;
      case SUB_TYPE_TUPLE:
        if ( m_subType == SUB_TYPE_TUPLE
          && m_type->m_parent->m_subType == SUB_TYPE_REAL
          && ((m_type->m_extra.m_size - 4) & 0xFFFFFFF3) == 0 )
        {
          v31 = hkTypeManager::Type::getTupleSize(m_type);
          v32 = 0i64;
          for ( i = v31; v32 < i; *(&v42 + v32) = (int)arr.m_impl )
          {
            hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &arr, 4, 1);
            ++v32;
          }
          ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, hkDataObject_Value *, _QWORD))value->m_impl->vfptr[18].__vecDelDtor)(
            value->m_impl,
            value->m_handle,
            &v43,
            (unsigned int)i);
        }
        break;
      default:
        break;
    }
  }
  v40 = (__int64)v48;
  if ( v48 )
  {
    --v48->m_externalCount;
    v26 = (*(_DWORD *)(v40 + 12))-- == 1;
    if ( v26 )
      (**(void (__fastcall ***)(__int64, __int64))v40)(v40, 1i64);
  }
}

// File Line: 624
// RVA: 0xE4D020
void __fastcall `anonymous namespace::Reader::readObjectIntoValue<hkDataArray_Value>(
        Reader *this,
        hkDataArray_Value *value)
{
  int v4; // esi
  int v5; // r15d
  int v6; // ebx
  char v7; // cl
  __int64 v8; // rbx
  bool v9; // zf
  char **p_m_pos; // rsi
  int inserted; // eax
  __int64 v12; // rdi
  __int64 v13; // rbx
  _QWORD **v14; // rax
  __int128 v15; // xmm0
  _OWORD *v16; // rax
  hkDataObjectImpl *m_impl; // rcx
  __int128 v18; // [rsp+20h] [rbp-38h]
  hkDataObject array; // [rsp+60h] [rbp+8h] BYREF
  char v20; // [rsp+70h] [rbp+18h] BYREF

  if ( SLODWORD(this->m_parser.vfptr) < 2 )
  {
    `anonymous namespace::Reader::readObjectTopLevel(this, &array, TAG_NONE, 0i64);
    ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, hkDataObjectImpl *))value->m_impl->vfptr[22].__vecDelDtor)(
      value->m_impl,
      (unsigned int)value->m_index,
      array.m_impl);
    m_impl = array.m_impl;
    if ( array.m_impl )
    {
      --array.m_impl->m_externalCount;
      v9 = m_impl->m_count-- == 1;
      if ( v9 )
        m_impl->vfptr->__vecDelDtor(m_impl, 1u);
    }
  }
  else
  {
    hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 1, 1);
    v4 = 6;
    v5 = (__int64)array.m_impl & 1;
    v6 = (LOBYTE(array.m_impl) >> 1) & 0x7FFFFFBF;
    if ( SLOBYTE(array.m_impl) < 0 )
    {
      do
      {
        hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &v20, 1, 1);
        v7 = v4;
        v4 += 7;
        v6 |= (v20 & 0x7F) << v7;
      }
      while ( v20 < 0 );
    }
    if ( v5 )
      v6 = -v6;
    if ( v6 >= this->m_parser.m_lex.m_buffer.m_bufferStart )
    {
      p_m_pos = &this->m_parser.m_lex.m_buffer.m_pos;
      inserted = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findOrInsertKey(
                   (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_parser.m_lex.m_buffer.m_pos,
                   &hkContainerHeapAllocator::s_alloc,
                   v6,
                   0i64);
      v12 = 2i64 * inserted;
      v13 = *(_QWORD *)&(*p_m_pos)[16 * inserted + 8];
      if ( !v13 )
      {
        v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v13 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v14[11] + 8i64))(v14[11], 32i64);
        if ( v13 )
        {
          *(_DWORD *)(v13 + 12) = 0x80000000;
          *(_QWORD *)v13 = 0i64;
          *(_DWORD *)(v13 + 8) = 0;
          *(_QWORD *)(v13 + 16) = 0i64;
          *(_DWORD *)(v13 + 24) = 0;
          *(_DWORD *)(v13 + 28) = 0x80000000;
        }
        else
        {
          v13 = 0i64;
        }
        *(_QWORD *)&(*p_m_pos)[8 * v12 + 8] = v13;
      }
      v15 = (__int128)*value;
      v18 = (__int128)*value;
      if ( *(_DWORD *)(v13 + 8) == (*(_DWORD *)(v13 + 12) & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)v13, 16);
        v15 = v18;
      }
      v16 = (_OWORD *)(*(_QWORD *)v13 + 16i64 * *(int *)(v13 + 8));
      if ( v16 )
        *v16 = v15;
      ++*(_DWORD *)(v13 + 8);
    }
    else
    {
      v8 = *(_QWORD *)(*(_QWORD *)&this->m_parser.m_lex.m_buffer.m_memSizeAndFlags + 8i64 * v6);
      if ( v8 )
      {
        ++*(_WORD *)(v8 + 10);
        ++*(_DWORD *)(v8 + 12);
      }
      ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))value->m_impl->vfptr[22].__vecDelDtor)(
        value->m_impl,
        (unsigned int)value->m_index,
        v8);
      if ( v8 )
      {
        --*(_WORD *)(v8 + 10);
        v9 = (*(_DWORD *)(v8 + 12))-- == 1;
        if ( v9 )
          (**(void (__fastcall ***)(__int64, __int64))v8)(v8, 1i64);
      }
    }
  }
}

// File Line: 658
// RVA: 0xE4F530
hkDataObject *__fastcall `anonymous namespace::Reader::readObjectTopLevel(
        Reader *this,
        hkDataObject *result,
        int objectTag,
        hkDataClassImpl *klassImpl)
{
  int v5; // edi
  hkDataObject *v6; // r12
  int v8; // esi
  int v9; // ebx
  int v10; // r12d
  char v11; // cl
  int v12; // r14d
  int v13; // ebx
  char v14; // cl
  hkDataObjectImpl *v15; // rdx
  int v16; // r15d
  int v17; // ebx
  char v18; // cl
  __int64 v19; // r15
  hkDataObjectImpl *v20; // rax
  hkDataObjectImpl *v21; // rbx
  int v22; // edi
  unsigned __int64 m_bufferStart; // r14
  __int64 Key; // rax
  __int64 v25; // r14
  Reader::ForwardReferences *v26; // rdi
  _QWORD **Value; // rax
  hkLifoAllocator *v28; // rax
  char *m_cur; // rcx
  char *v30; // rdx
  int v31; // edx
  hkLifoAllocator *v32; // rax
  hkDataClass_MemberInfo *v33; // rcx
  int v34; // edx
  char *v35; // r8
  __int64 v36; // rax
  int v37; // eax
  __int64 v38; // r8
  __int64 v39; // rdx
  char *v40; // rax
  hkLifoAllocator *v41; // rcx
  char *v42; // rax
  int v43; // edx
  char *v44; // r8
  int v45; // r14d
  __int64 i; // rdi
  int v47; // eax
  char *v48; // r14
  unsigned int m_slotID; // ecx
  signed int v50; // edi
  hkLifoAllocator *v51; // rax
  int v52; // r8d
  int v53; // eax
  char *v54; // r14
  signed int v55; // edi
  hkLifoAllocator *v56; // rax
  int v57; // r8d
  int m_size; // eax
  char *m_localMemory; // r14
  signed int v60; // edi
  hkLifoAllocator *v61; // rax
  int v62; // r8d
  char v65[8]; // [rsp+20h] [rbp-E0h] BYREF
  hkDataClass_MemberInfo *v66; // [rsp+28h] [rbp-D8h] BYREF
  int v67; // [rsp+30h] [rbp-D0h]
  int v68; // [rsp+34h] [rbp-CCh]
  void *v69; // [rsp+38h] [rbp-C8h]
  int v70; // [rsp+40h] [rbp-C0h]
  char *v71; // [rsp+48h] [rbp-B8h] BYREF
  int v72; // [rsp+50h] [rbp-B0h]
  int v73; // [rsp+54h] [rbp-ACh]
  void *p; // [rsp+58h] [rbp-A8h]
  int v75; // [rsp+60h] [rbp-A0h]
  hkLocalArray<unsigned char> bout; // [rsp+68h] [rbp-98h] BYREF
  hkDataClassImpl *v77; // [rsp+88h] [rbp-78h] BYREF
  hkDataObject o[2]; // [rsp+90h] [rbp-70h] BYREF
  hkErrStream v79; // [rsp+A0h] [rbp-60h] BYREF
  char buf[560]; // [rsp+C0h] [rbp-40h] BYREF
  unsigned __int8 array; // [rsp+310h] [rbp+210h] BYREF

  v5 = objectTag;
  v6 = result;
  v8 = 6;
  if ( !objectTag )
  {
    hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 1, 1);
    v9 = 6;
    v10 = array & 1;
    v5 = (array >> 1) & 0x7FFFFFBF;
    if ( (array & 0x80u) != 0 )
    {
      do
      {
        hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, v65, 1, 1);
        v11 = v9;
        v9 += 7;
        v5 |= (v65[0] & 0x7F) << v11;
      }
      while ( v65[0] < 0 );
    }
    if ( v10 )
      v5 = -v5;
    v6 = result;
  }
  if ( v5 == 5 )
  {
    hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 1, 1);
    v12 = array & 1;
    v13 = (array >> 1) & 0x7FFFFFBF;
    if ( (array & 0x80u) != 0 )
    {
      do
      {
        hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, v65, 1, 1);
        v14 = v8;
        v8 += 7;
        v13 |= (v65[0] & 0x7F) << v14;
      }
      while ( v65[0] < 0 );
    }
    if ( v12 )
      v13 = -v13;
    v15 = *(hkDataObjectImpl **)(*(_QWORD *)&this->m_parser.m_lex.m_buffer.m_memSizeAndFlags + 8i64 * v13);
    v6->m_impl = v15;
    if ( v15 )
    {
      ++v15->m_externalCount;
      ++v15->m_count;
    }
  }
  else if ( v5 == 6 )
  {
    v6->m_impl = 0i64;
  }
  else
  {
    if ( !klassImpl )
    {
      hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 1, 1);
      v16 = array & 1;
      v17 = (array >> 1) & 0x7FFFFFBF;
      if ( (array & 0x80u) != 0 )
      {
        do
        {
          hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, v65, 1, 1);
          v18 = v8;
          v8 += 7;
          v17 |= (v65[0] & 0x7F) << v18;
        }
        while ( v65[0] < 0 );
      }
      if ( v16 )
        v17 = -v17;
      klassImpl = *(hkDataClassImpl **)&this->m_parser.m_keyStorage.m_data[8 * v17];
    }
    v77 = klassImpl;
    v19 = ((int (__fastcall *)(hkDataClassImpl *))klassImpl->vfptr[9].__vecDelDtor)(klassImpl);
    v20 = (hkDataObjectImpl *)(*((__int64 (__fastcall **)(const char **, hkDataClassImpl **, _QWORD))*this->m_parser.m_keys.m_data
                               + 4))(
                                this->m_parser.m_keys.m_data,
                                &v77,
                                0i64);
    v21 = v20;
    o[0].m_impl = v20;
    if ( v20 )
    {
      ++v20->m_externalCount;
      ++v20->m_count;
    }
    v22 = v5 - 3;
    if ( v22 )
    {
      if ( v22 == 1 )
      {
        m_bufferStart = this->m_parser.m_lex.m_buffer.m_bufferStart;
        if ( this->m_parser.m_lex.m_buffer.m_bufferStart == (this->m_parser.m_lex.m_buffer.m_lexemeStart & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&this->m_parser.m_lex.m_buffer.m_memSizeAndFlags,
            8);
        *(_QWORD *)(*(_QWORD *)&this->m_parser.m_lex.m_buffer.m_memSizeAndFlags
                  + 8i64 * this->m_parser.m_lex.m_buffer.m_bufferStart++) = v21;
        Key = (__int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                         (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_parser.m_lex.m_buffer.m_pos,
                         m_bufferStart);
        v25 = Key;
        if ( (int)Key <= SHIDWORD(this->m_parser.m_lex.m_buffer.m_buffer.m_data) )
        {
          v26 = *(Reader::ForwardReferences **)&this->m_parser.m_lex.m_buffer.m_pos[16 * (int)Key + 8];
          `anonymous namespace::Reader::ForwardReferences::assign(v26, o);
          if ( v26 )
          {
            `anonymous namespace::Reader::ForwardReferences::~ForwardReferences(v26);
            Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            (*(void (__fastcall **)(_QWORD *, Reader::ForwardReferences *, __int64))(*Value[11] + 16i64))(
              Value[11],
              v26,
              32i64);
          }
          hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_parser.m_lex.m_buffer.m_pos,
            v25);
        }
      }
      else
      {
        hkErrStream::hkErrStream(&v79, buf, 512);
        hkOstream::operator<<(&v79, "corrupt file");
        if ( (unsigned int)hkError::messageError(0x484994D5u, buf, "Tagfile\\Binary\\hkBinaryTagfileReader.cpp", 701) )
          __debugbreak();
        hkOstream::~hkOstream(&v79);
      }
    }
    bout.m_capacityAndFlags = 0x80000000;
    bout.m_data = 0i64;
    bout.m_size = 0;
    bout.m_initialCapacity = 128;
    v28 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)v28->m_cur;
    v30 = m_cur + 128;
    if ( v28->m_slabSize < 128 || v30 > v28->m_end )
      m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(v28, 128);
    else
      v28->m_cur = v30;
    bout.m_data = m_cur;
    bout.m_localMemory = m_cur;
    bout.m_capacityAndFlags = -2147483520;
    `anonymous namespace::Reader::readBitfield(this, v19, &bout);
    v31 = 0;
    v66 = 0i64;
    v67 = 0;
    v68 = 0x80000000;
    v70 = v19;
    if ( (_DWORD)v19 )
    {
      v32 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v33 = (hkDataClass_MemberInfo *)v32->m_cur;
      v34 = (32 * v19 + 127) & 0xFFFFFF80;
      v35 = (char *)v33 + v34;
      if ( v34 > v32->m_slabSize || v35 > v32->m_end )
      {
        v36 = hkLifoAllocator::allocateFromNewSlab(v32, v34);
        v31 = v67;
        v33 = (hkDataClass_MemberInfo *)v36;
      }
      else
      {
        v32->m_cur = v35;
        v31 = v67;
      }
    }
    else
    {
      v33 = 0i64;
    }
    v37 = v19 - v31;
    v38 = 32i64 * v31 + 16;
    v66 = v33;
    v69 = v33;
    v68 = v19 | 0x80000000;
    v39 = (int)v19 - v31;
    if ( v37 > 0 )
    {
      v40 = (char *)v33 + v38;
      do
      {
        if ( v40 != (char *)16 )
        {
          *((_QWORD *)v40 - 2) = 0i64;
          *((_QWORD *)v40 - 1) = 0i64;
          *(_QWORD *)v40 = 0i64;
          *((_QWORD *)v40 + 1) = 0i64;
        }
        v40 += 32;
        --v39;
      }
      while ( v39 );
    }
    v67 = v19;
    ((void (__fastcall *)(hkDataClassImpl *, hkDataClass_MemberInfo **, __int64))v77->vfptr[12].__vecDelDtor)(
      v77,
      &v66,
      v38);
    v71 = 0i64;
    v72 = 0;
    v73 = 0x80000000;
    v75 = v19;
    if ( (_DWORD)v19 )
    {
      v41 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v42 = (char *)v41->m_cur;
      v43 = (8 * v19 + 127) & 0xFFFFFF80;
      v44 = &v42[v43];
      if ( v43 > v41->m_slabSize || v44 > v41->m_end )
        v42 = (char *)hkLifoAllocator::allocateFromNewSlab(v41, v43);
      else
        v41->m_cur = v44;
    }
    else
    {
      v42 = 0i64;
    }
    v71 = v42;
    v73 = v19 | 0x80000000;
    p = v42;
    v72 = v19;
    v21->vfptr[29].__vecDelDtor(v21, (unsigned int)&v71);
    v45 = 0;
    for ( i = 0i64; i < v19; ++v45 )
    {
      if ( bout.m_data[i] )
      {
        o[0].m_impl = v21;
        o[1] = *(hkDataObject *)&v71[8 * i];
        v79.hkReferencedObject = *(hkReferencedObject *)&o[0].m_impl;
        `anonymous namespace::Reader::readBinaryValue(this, (hkDataObject_Value *)&v79, &v66[v45]);
      }
      ++i;
    }
    ++v21->m_externalCount;
    ++v21->m_count;
    v47 = v72;
    v48 = (char *)p;
    m_slotID = hkMemoryRouter::s_memoryRouter.m_slotID;
    v6->m_impl = v21;
    if ( v48 == v71 )
      v47 = 0;
    v72 = v47;
    v50 = (8 * v75 + 127) & 0xFFFFFF80;
    v51 = (hkLifoAllocator *)TlsGetValue(m_slotID);
    v52 = (v50 + 15) & 0xFFFFFFF0;
    if ( v50 > v51->m_slabSize || &v48[v52] != v51->m_cur || v51->m_firstNonLifoEnd == v48 )
      hkLifoAllocator::slowBlockFree(v51, v48, v52);
    else
      v51->m_cur = v48;
    v72 = 0;
    if ( v73 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v71, 8 * v73);
    v53 = v67;
    v54 = (char *)v69;
    v71 = 0i64;
    if ( v69 == v66 )
      v53 = 0;
    v73 = 0x80000000;
    v67 = v53;
    v55 = (32 * v70 + 127) & 0xFFFFFF80;
    v56 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v57 = (v55 + 15) & 0xFFFFFFF0;
    if ( v55 > v56->m_slabSize || &v54[v57] != v56->m_cur || v56->m_firstNonLifoEnd == v54 )
      hkLifoAllocator::slowBlockFree(v56, v54, v57);
    else
      v56->m_cur = v54;
    v67 = 0;
    if ( v68 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v66, 32 * v68);
    m_size = bout.m_size;
    m_localMemory = bout.m_localMemory;
    v66 = 0i64;
    if ( bout.m_localMemory == bout.m_data )
      m_size = 0;
    v68 = 0x80000000;
    v60 = (bout.m_initialCapacity + 127) & 0xFFFFFF80;
    bout.m_size = m_size;
    v61 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v62 = (v60 + 15) & 0xFFFFFFF0;
    if ( v60 > v61->m_slabSize || &m_localMemory[v62] != v61->m_cur || v61->m_firstNonLifoEnd == m_localMemory )
      hkLifoAllocator::slowBlockFree(v61, m_localMemory, v62);
    else
      v61->m_cur = m_localMemory;
    bout.m_size = 0;
    if ( bout.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        bout.m_data,
        bout.m_capacityAndFlags & 0x3FFFFFFF);
    bout.m_data = 0i64;
    bout.m_capacityAndFlags = 0x80000000;
    --v21->m_externalCount;
    if ( v21->m_count-- == 1 )
      v21->vfptr->__vecDelDtor(v21, 1u);
  }
  return v6;
}cityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        bout.m_data,
        bout.m_capacityAndFlags & 0x3FFFFFFF);
    bout.m_data = 0i64;
    bout.m_capacityAndFlags = 0x80000000;
    --v21->m_externalCount;
    if (

// File Line: 734
// RVA: 0xE4ED90
hkResult *__fastcall `anonymous namespace::Reader::readClass(Reader *this, hkResult *result)
{
  int v2; // r15d
  hkResult *v3; // r12
  int v5; // edi
  int v6; // esi
  int v7; // ebx
  char v8; // cl
  const char **m_data; // rcx
  int v10; // edi
  int v11; // esi
  int v12; // ebx
  char v13; // cl
  __int64 v14; // rcx
  int v15; // edi
  int v16; // esi
  int v17; // ebx
  char v18; // cl
  int v19; // r9d
  __int64 v20; // r12
  char *v21; // rbx
  int v22; // ebx
  int v23; // esi
  int v24; // edi
  char v25; // cl
  int v26; // esi
  int v27; // r15d
  int v28; // ebx
  char v29; // cl
  const char *v30; // rsi
  const char *v31; // rax
  hkTypeManager *v32; // rax
  hkTypeManager::Type *Type; // rax
  __int64 v34; // rdi
  __int64 m_size; // rcx
  char *v36; // rax
  char v38[4]; // [rsp+30h] [rbp-48h] BYREF
  int v39; // [rsp+34h] [rbp-44h]
  char *v40; // [rsp+38h] [rbp-40h]
  const char *String; // [rsp+40h] [rbp-38h] BYREF
  int v42; // [rsp+48h] [rbp-30h]
  __int64 v43; // [rsp+50h] [rbp-28h]
  char *v44; // [rsp+58h] [rbp-20h] BYREF
  int v45; // [rsp+60h] [rbp-18h]
  int v46; // [rsp+64h] [rbp-14h]
  unsigned __int8 array; // [rsp+C0h] [rbp+48h] BYREF
  hkResult *v48; // [rsp+C8h] [rbp+50h]
  char v49; // [rsp+D0h] [rbp+58h] BYREF
  hkResult resulta; // [rsp+D8h] [rbp+60h] BYREF

  v48 = result;
  v2 = 0;
  v3 = result;
  v44 = 0i64;
  v45 = 0;
  v46 = 0x80000000;
  String = `anonymous namespace::Reader::readString(this);
  hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 1, 1);
  v5 = 6;
  v6 = array & 1;
  v7 = (array >> 1) & 0x7FFFFFBF;
  if ( (array & 0x80u) != 0 )
  {
    do
    {
      hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &v49, 1, 1);
      v8 = v5;
      v5 += 7;
      v7 |= (v49 & 0x7F) << v8;
    }
    while ( v49 < 0 );
  }
  if ( v6 )
    v7 = -v7;
  m_data = this->m_parser.m_keys.m_data;
  v42 = v7;
  if ( *(_DWORD *)(*((__int64 (__fastcall **)(const char **, unsigned __int8 *))*m_data + 6))(m_data, &array) )
  {
    hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 1, 1);
    v10 = 6;
    v11 = array & 1;
    v12 = (array >> 1) & 0x7FFFFFBF;
    if ( (array & 0x80u) != 0 )
    {
      do
      {
        hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &v49, 1, 1);
        v13 = v10;
        v10 += 7;
        v12 |= (v49 & 0x7F) << v13;
      }
      while ( v49 < 0 );
    }
    if ( v11 )
      v12 = -v12;
    if ( v12 >= 0 && (v14 = *(_QWORD *)&this->m_parser.m_keyStorage.m_data[8 * v12]) != 0 )
      v43 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 16i64))(v14);
    else
      v43 = 0i64;
    hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 1, 1);
    v15 = 6;
    v16 = array & 1;
    v17 = (array >> 1) & 0x7FFFFFBF;
    if ( (array & 0x80u) != 0 )
    {
      do
      {
        hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &v49, 1, 1);
        v18 = v15;
        v15 += 7;
        v17 |= (v49 & 0x7F) << v18;
      }
      while ( v49 < 0 );
    }
    if ( v16 )
      v17 = -v17;
    if ( (v46 & 0x3FFFFFFF) < v17 )
    {
      v19 = v17;
      if ( v17 < 2 * (v46 & 0x3FFFFFFF) )
        v19 = 2 * (v46 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&v44, v19, 24);
    }
    v45 = v17;
    v39 = 0;
    if ( v17 > 0 )
    {
      v20 = 0i64;
      do
      {
        v21 = &v44[v20];
        v40 = &v44[v20];
        *(_QWORD *)v21 = `anonymous namespace::Reader::readString(this);
        hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 1, 1);
        v22 = 6;
        v23 = array & 1;
        v24 = (array >> 1) & 0x7FFFFFBF;
        if ( (array & 0x80u) != 0 )
        {
          do
          {
            hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &v49, 1, 1);
            v25 = v22;
            v22 += 7;
            v24 |= (v49 & 0x7F) << v25;
          }
          while ( v49 < 0 );
        }
        if ( v23 )
          v24 = -v24;
        if ( (v24 & 0x20) != 0 )
        {
          hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &resulta, 1, 1);
          v26 = 6;
          v27 = resulta.m_enum & 1;
          v28 = (LOBYTE(resulta.m_enum) >> 1) & 0x7FFFFFBF;
          if ( SLOBYTE(resulta.m_enum) < 0 )
          {
            do
            {
              hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, v38, 1, 1);
              v29 = v26;
              v26 += 7;
              v28 |= (v38[0] & 0x7F) << v29;
            }
            while ( v38[0] < 0 );
          }
          if ( v27 )
            v28 = -v28;
          v2 = v39;
        }
        else
        {
          v28 = 0;
        }
        if ( (v24 & 0xFu) - 8 <= 1 )
        {
          v31 = `anonymous namespace::Reader::readString(this);
          v30 = v31;
          if ( v31 )
            (*((void (__fastcall **)(const char **, const char *))*this->m_parser.m_keys.m_data + 9))(
              this->m_parser.m_keys.m_data,
              v31);
        }
        else
        {
          v30 = 0i64;
        }
        v32 = (hkTypeManager *)(*((__int64 (__fastcall **)(const char **))*this->m_parser.m_keys.m_data + 11))(this->m_parser.m_keys.m_data);
        Type = hkTypeManager::getType(v32, (hkLegacyType::Type)v24, v30, v28);
        ++v2;
        v20 += 24i64;
        *((_QWORD *)v40 + 1) = Type;
        v39 = v2;
      }
      while ( v2 < v45 );
      v3 = v48;
    }
    v34 = (*((__int64 (__fastcall **)(const char **, const char **))*this->m_parser.m_keys.m_data + 3))(
            this->m_parser.m_keys.m_data,
            &String);
    if ( this->m_parser.m_keyStorage.m_size == (this->m_parser.m_keyStorage.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_parser.m_keyStorage.m_data,
        8);
    m_size = this->m_parser.m_keyStorage.m_size;
    v36 = this->m_parser.m_keyStorage.m_data;
    v3->m_enum = HK_SUCCESS;
    *(_QWORD *)&v36[8 * m_size] = v34;
    ++this->m_parser.m_keyStorage.m_size;
    v45 = 0;
  }
  else
  {
    v3->m_enum = HK_FAILURE;
    v45 = 0;
  }
  if ( v46 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v44, 24 * (v46 & 0x3FFFFFFF));
  return v3;
}

// File Line: 782
// RVA: 0xE4FC70
hkDataObject *__fastcall `anonymous namespace::Reader::readObjectTree(Reader *this, hkDataObject *result)
{
  int v4; // esi
  int v5; // r15d
  int v6; // ebx
  char v7; // cl
  int v8; // esi
  int v9; // r15d
  int v10; // ebx
  char v11; // cl
  int v12; // esi
  int v13; // r15d
  int v14; // ebx
  char v15; // cl
  hkDataObjectImpl *m_impl; // rcx
  int v18; // esi
  int v19; // r15d
  char v20; // cl
  hkOstream *v21; // rax
  int m_count; // eax
  hkDataObjectImpl *v24; // rcx
  unsigned __int8 v25; // [rsp+20h] [rbp-E0h] BYREF
  char v26; // [rsp+21h] [rbp-DFh] BYREF
  char v27[6]; // [rsp+22h] [rbp-DEh] BYREF
  hkDataObject v28; // [rsp+28h] [rbp-D8h] BYREF
  hkResult resulta; // [rsp+30h] [rbp-D0h] BYREF
  hkErrStream v30; // [rsp+38h] [rbp-C8h] BYREF
  char buf[512]; // [rsp+50h] [rbp-B0h] BYREF
  int array; // [rsp+290h] [rbp+190h] BYREF
  int v33; // [rsp+2A0h] [rbp+1A0h] BYREF
  unsigned __int8 v34; // [rsp+2A8h] [rbp+1A8h] BYREF

  hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 4, 1);
  hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &v33, 4, 1);
  if ( array != -894431970 || v33 != -804128050 )
  {
    hkErrStream::hkErrStream(&v30, buf, 512);
    hkOstream::operator<<(&v30, "This does not look like a binary tagfile (magic number mismatch)");
    hkError::messageWarning(0x2AB6036Fu, buf, "Tagfile\\Binary\\hkBinaryTagfileReader.cpp", 791);
    hkOstream::~hkOstream(&v30);
    result->m_impl = 0i64;
    return result;
  }
  hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 1, 1);
  v4 = 6;
  v5 = array & 1;
  v6 = ((unsigned __int8)array >> 1) & 0x7FFFFFBF;
  if ( (array & 0x80u) != 0 )
  {
    do
    {
      hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &v33, 1, 1);
      v7 = v4;
      v4 += 7;
      v6 |= (v33 & 0x7F) << v7;
    }
    while ( (v33 & 0x80u) != 0 );
  }
  if ( v5 )
    v6 = -v6;
  while ( 2 )
  {
    if ( v6 == -1 )
      goto LABEL_41;
    switch ( v6 )
    {
      case 1:
        hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 1, 1);
        v8 = 6;
        v9 = array & 1;
        v10 = ((unsigned __int8)array >> 1) & 0x7FFFFFBF;
        if ( (array & 0x80u) != 0 )
        {
          do
          {
            hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &v33, 1, 1);
            v11 = v8;
            v8 += 7;
            v10 |= (v33 & 0x7F) << v11;
          }
          while ( (v33 & 0x80u) != 0 );
        }
        if ( v9 )
          v10 = -v10;
        LODWORD(this->m_parser.vfptr) = v10;
        if ( !v10 )
          goto LABEL_36;
        if ( v10 == 1 )
        {
          hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &v34, 1, 1);
          v12 = 6;
          v13 = v34 & 1;
          v14 = (v34 >> 1) & 0x7FFFFFBF;
          if ( (v34 & 0x80u) != 0 )
          {
            do
            {
              hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, v27, 1, 1);
              v15 = v12;
              v12 += 7;
              v14 |= (v27[0] & 0x7F) << v15;
            }
            while ( v27[0] < 0 );
          }
          if ( v13 )
            v14 = -v14;
          if ( v14 != 1 )
            goto LABEL_41;
          *(_DWORD *)&this->m_parser.m_lex.m_memSizeAndFlags = 0;
          if ( (*(_DWORD *)(&this->m_parser.m_lex.m_referenceCount + 1) & 0x3FFFFFFF) == 0 )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_parser.m_lex.vfptr, 8);
          *((_QWORD *)&this->m_parser.m_lex.vfptr->__vecDelDtor
          + (int)(*(_DWORD *)&this->m_parser.m_lex.m_memSizeAndFlags)++) = &customCaption;
          if ( *(_DWORD *)&this->m_parser.m_lex.m_memSizeAndFlags == (*(_DWORD *)(&this->m_parser.m_lex.m_referenceCount
                                                                                + 1) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_parser.m_lex.vfptr, 8);
          *((_QWORD *)&this->m_parser.m_lex.vfptr->__vecDelDtor
          + (int)(*(_DWORD *)&this->m_parser.m_lex.m_memSizeAndFlags)++) = 0i64;
          hkArrayBase<unsigned __int64>::_append(
            (hkArrayBase<char *> *)&this->m_parser.m_lex,
            &hkContainerHeapAllocator::s_alloc,
            (char *const *)HK_TAG_STRING_LIST,
            1752);
          LODWORD(this->m_parser.m_lex.m_buffer.vfptr) = 1754;
LABEL_36:
          hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &v25, 1, 1);
          v18 = 6;
          v19 = v25 & 1;
          v6 = (v25 >> 1) & 0x7FFFFFBF;
          if ( (v25 & 0x80u) != 0 )
          {
            do
            {
              hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &v26, 1, 1);
              v20 = v18;
              v18 += 7;
              v6 |= (v26 & 0x7F) << v20;
            }
            while ( v26 < 0 );
          }
          if ( v19 )
            v6 = -v6;
          continue;
        }
        if ( (unsigned int)(v10 - 2) <= 2 )
        {
          if ( this->m_parser.m_lex.m_buffer.m_bufferStart == (this->m_parser.m_lex.m_buffer.m_lexemeStart & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&this->m_parser.m_lex.m_buffer.m_memSizeAndFlags,
              8);
          *(_QWORD *)(*(_QWORD *)&this->m_parser.m_lex.m_buffer.m_memSizeAndFlags
                    + 8i64 * this->m_parser.m_lex.m_buffer.m_bufferStart++) = 0i64;
          if ( LODWORD(this->m_parser.vfptr) == 4 )
            `anonymous namespace::Reader::readString(this);
          goto LABEL_36;
        }
        hkErrStream::hkErrStream(&v30, buf, 512);
        v21 = hkOstream::operator<<(&v30, "Unrecognised tagfile version ");
        hkOstream::operator<<(v21, (unsigned int)this->m_parser.vfptr);
        hkError::messageWarning(0x2AB6036Fu, buf, "Tagfile\\Binary\\hkBinaryTagfileReader.cpp", 843);
        hkOstream::~hkOstream(&v30);
LABEL_41:
        result->m_impl = 0i64;
        return result;
      case 2:
        if ( `anonymous namespace::Reader::readClass(this, &resulta)->m_enum == HK_FAILURE )
          goto LABEL_41;
        goto LABEL_36;
      case 3:
      case 4:
      case 6:
        `anonymous namespace::Reader::readObjectTopLevel(this, &v28, v6, 0i64);
        m_impl = v28.m_impl;
        if ( SLODWORD(this->m_parser.vfptr) < 2 )
        {
          result->m_impl = v28.m_impl;
          if ( m_impl )
          {
            m_count = m_impl->m_count;
            m_impl->m_count = m_count;
            if ( !m_count )
              m_impl->vfptr->__vecDelDtor(m_impl, 1u);
          }
          return result;
        }
        if ( v28.m_impl )
        {
          --v28.m_impl->m_externalCount;
          if ( m_impl->m_count-- == 1 )
            m_impl->vfptr->__vecDelDtor(m_impl, 1u);
        }
        goto LABEL_36;
      case 7:
        v24 = *(hkDataObjectImpl **)(*(_QWORD *)&this->m_parser.m_lex.m_buffer.m_memSizeAndFlags + 8i64);
        result->m_impl = v24;
        if ( v24 )
        {
          ++v24->m_externalCount;
          ++v24->m_count;
        }
        return result;
      default:
        goto LABEL_41;
    }
  }
}

// File Line: 912
// RVA: 0xE4E480
void __fastcall `anonymous namespace::Reader::ForwardReferences::assign(
        Reader::ForwardReferences *this,
        hkDataObject *o)
{
  int v2; // edi
  int v5; // ebp
  __int64 v6; // rsi
  __int64 v7; // rsi

  v2 = 0;
  v5 = 0;
  if ( this->m_arrayRefs.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, hkDataObjectImpl *))this->m_arrayRefs.m_data[v6].m_impl->vfptr[22].__vecDelDtor)(
        this->m_arrayRefs.m_data[v6].m_impl,
        (unsigned int)this->m_arrayRefs.m_data[v6].m_index,
        o->m_impl);
      ++v5;
      ++v6;
    }
    while ( v5 < this->m_arrayRefs.m_size );
  }
  if ( this->m_objectRefs.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, hkDataObjectImpl *))this->m_objectRefs.m_data[v7].m_impl->vfptr[23].__vecDelDtor)(
        this->m_objectRefs.m_data[v7].m_impl,
        this->m_objectRefs.m_data[v7].m_handle,
        o->m_impl);
      ++v2;
      ++v7;
    }
    while ( v2 < this->m_objectRefs.m_size );
  }
}

// File Line: 933
// RVA: 0xE4CF50
void __fastcall hkBinaryTagfileReader::hkBinaryTagfileReader(hkBinaryTagfileReader *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkBinaryTagfileReader::`vftable;
}

// File Line: 937
// RVA: 0xE4CF70
hkDataObject *__fastcall hkBinaryTagfileReader::load(
        hkBinaryTagfileReader *this,
        hkDataObject *result,
        hkStreamReader *stream,
        hkDataWorld *cont)
{
  char v6[136]; // [rsp+20h] [rbp-88h] BYREF

  `anonymous namespace::Reader::Reader((Reader *)v6, stream, cont);
  `anonymous namespace::Reader::readObjectTree((Reader *)v6, result);
  `anonymous namespace::Reader::~Reader((Reader *)v6);
  return result;
}

// File Line: 943
// RVA: 0xE4CFC0
hkResult *__fastcall hkBinaryTagfileReader::readHeader(
        hkBinaryTagfileReader *this,
        hkResult *result,
        hkStreamReader *stream,
        hkBinaryTagfile::Header *out)
{
  char v7[136]; // [rsp+20h] [rbp-88h] BYREF

  `anonymous namespace::Reader::Reader((Reader *)v7, stream, 0i64);
  `anonymous namespace::Reader::readHeader((Reader *)v7, result, out);
  `anonymous namespace::Reader::~Reader((Reader *)v7);
  return result;
}

