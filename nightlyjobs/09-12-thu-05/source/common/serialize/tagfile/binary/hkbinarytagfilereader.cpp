// File Line: 94
// RVA: 0xE4E520
void __fastcall `anonymous namespace'::IntReader::readArray(IntReader *this, hkDataArray *arr)
{
  __int64 v2; // r15
  hkDataArray *v3; // r13
  IntReader *v4; // rbx
  int v5; // er9
  __int64 v6; // rbp
  const char *v7; // r8
  unsigned __int8 v8; // al
  const char *v9; // r8
  int v10; // er9
  char *v11; // rdx
  hkIArchive *v12; // rcx
  char *v13; // rcx
  signed int v14; // esi
  int v15; // er14
  unsigned int v16; // edi
  char v17; // al
  int v18; // er9
  char *v19; // rdx
  hkIArchive *v20; // rcx
  char *v21; // rcx
  char v22; // cl
  _DWORD *v23; // [rsp+30h] [rbp-38h]
  int v24; // [rsp+38h] [rbp-30h]
  int v25; // [rsp+3Ch] [rbp-2Ch]
  __int64 v26; // [rsp+70h] [rbp+8h]

  v2 = this->m_remaining;
  v3 = arr;
  v4 = this;
  v23 = 0i64;
  v24 = 0;
  v25 = 2147483648;
  if ( (signed int)v2 > 0 )
  {
    v5 = v2;
    if ( (signed int)v2 < 0 )
      v5 = 0;
    hkArrayUtil::_reserve((hkResult *)&v26, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v23, v5, 4);
  }
  v24 = v2;
  v6 = 0i64;
  if ( (signed int)v2 > 0 )
  {
    do
    {
      v7 = v4->m_cur;
      if ( v7 >= v4->m_end )
      {
        v10 = v4->m_remaining;
        v11 = v4->m_buffer.m_data;
        v12 = v4->m_archive;
        v4->m_buffer.m_size = v4->m_remaining;
        hkIArchive::readArrayGeneric(v12, v11, 1, v10);
        v13 = v4->m_buffer.m_data;
        v4->m_cur = v13;
        v9 = v13 + 1;
        v4->m_end = &v13[v4->m_buffer.m_size];
        v8 = *v13;
      }
      else
      {
        v8 = *v7;
        v9 = v7 + 1;
      }
      v4->m_cur = v9;
      v14 = 6;
      v15 = v8 & 1;
      v16 = ((unsigned int)v8 >> 1) & 0x7FFFFFBF;
      if ( (v8 & 0x80u) != 0 )
      {
        do
        {
          if ( v9 >= v4->m_end )
          {
            v18 = v4->m_remaining;
            v19 = v4->m_buffer.m_data;
            v20 = v4->m_archive;
            v4->m_buffer.m_size = v4->m_remaining;
            hkIArchive::readArrayGeneric(v20, v19, 1, v18);
            v21 = v4->m_buffer.m_data;
            v4->m_cur = v21;
            v9 = v21 + 1;
            v4->m_end = &v21[v4->m_buffer.m_size];
            v17 = *v21;
          }
          else
          {
            v17 = *v9++;
          }
          v22 = v14;
          v14 += 7;
          v4->m_cur = v9;
          v16 |= (v17 & 0x7F) << v22;
        }
        while ( v17 < 0 );
      }
      --v4->m_remaining;
      if ( v15 )
        v16 = -v16;
      v23[++v6 - 1] = v16;
    }
    while ( v6 < v2 );
  }
  ((void (__fastcall *)(hkDataArrayImpl *, _DWORD *, _QWORD))v3->m_impl->vfptr[32].__vecDelDtor)(
    v3->m_impl,
    v23,
    (unsigned int)v2);
  v24 = 0;
  if ( v25 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v23,
      4 * v25);
}

// File Line: 133
// RVA: 0xE4D440
void __fastcall `anonymous namespace'::Reader::Reader(Reader *this, hkStreamReader *sr, hkDataWorld *cont)
{
  hkDataWorld *v3; // rbx
  Reader *v4; // rsi

  v3 = cont;
  v4 = this;
  LODWORD(this->m_parser.vfptr) = -1;
  hkIArchive::hkIArchive((hkIArchive *)&this->m_parser.m_memSizeAndFlags, sr, 0);
  v4->m_parser.m_keys.m_data = (const char **)v3;
  *(_QWORD *)&v4->m_parser.m_keys.m_size = 0i64;
  v4->m_parser.m_keyStorage.m_data = 0i64;
  v4->m_parser.m_keyStorage.m_size = 0;
  v4->m_parser.m_keyStorage.m_capacityAndFlags = 2147483648;
  v4->m_parser.m_lex.vfptr = 0i64;
  *(_DWORD *)&v4->m_parser.m_lex.m_memSizeAndFlags = 0;
  *(_DWORD *)(&v4->m_parser.m_lex.m_referenceCount + 1) = 2147483648;
  LODWORD(v4->m_parser.m_lex.m_buffer.vfptr) = 0;
  *(_QWORD *)&v4->m_parser.m_lex.m_buffer.m_memSizeAndFlags = 0i64;
  v4->m_parser.m_lex.m_buffer.m_bufferStart = 0;
  v4->m_parser.m_lex.m_buffer.m_lexemeStart = 2147483648;
  v4->m_parser.m_lex.m_buffer.m_pos = 0i64;
  LODWORD(v4->m_parser.m_lex.m_buffer.m_buffer.m_data) = 0;
  HIDWORD(v4->m_parser.m_lex.m_buffer.m_buffer.m_data) = -1;
  if ( v4->m_parser.m_keyStorage.m_size == (v4->m_parser.m_keyStorage.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v4->m_parser.m_keyStorage,
      8);
  *(_QWORD *)&v4->m_parser.m_keyStorage.m_data[8 * v4->m_parser.m_keyStorage.m_size++] = 0i64;
  if ( *(_DWORD *)&v4->m_parser.m_lex.m_memSizeAndFlags == (*(_DWORD *)(&v4->m_parser.m_lex.m_referenceCount + 1) & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_parser.m_lex, 8);
  *((_QWORD *)&v4->m_parser.m_lex.vfptr->__vecDelDtor + (signed int)(*(_DWORD *)&v4->m_parser.m_lex.m_memSizeAndFlags)++) = &customWorldMapCaption;
  if ( *(_DWORD *)&v4->m_parser.m_lex.m_memSizeAndFlags == (*(_DWORD *)(&v4->m_parser.m_lex.m_referenceCount + 1) & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_parser.m_lex, 8);
  *((_QWORD *)&v4->m_parser.m_lex.vfptr->__vecDelDtor + (signed int)(*(_DWORD *)&v4->m_parser.m_lex.m_memSizeAndFlags)++) = 0i64;
  LODWORD(v4->m_parser.m_lex.m_buffer.vfptr) = 2;
}

// File Line: 144
// RVA: 0xE4D600
void __fastcall `anonymous namespace'::Reader::~Reader(Reader *this)
{
  __int64 v1; // rsi
  Reader *v2; // rdi
  signed __int64 v3; // r14
  void *v4; // rbx
  hkMemoryAllocator **v5; // rax
  int v6; // er8
  int v7; // er8
  int v8; // er8

  v1 = SLODWORD(this->m_parser.m_lex.m_buffer.vfptr);
  v2 = this;
  if ( (signed int)v1 < *(_DWORD *)&this->m_parser.m_lex.m_memSizeAndFlags )
  {
    v3 = 8 * v1;
    do
    {
      v4 = *(void *(__fastcall **)(hkBaseObject *, unsigned int))((char *)&v2->m_parser.m_lex.vfptr->__vecDelDtor + v3);
      v5 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      hkMemoryRouter::easyFree(v5[11], v4);
      LODWORD(v1) = v1 + 1;
      v3 += 8i64;
    }
    while ( (signed int)v1 < *(_DWORD *)&v2->m_parser.m_lex.m_memSizeAndFlags );
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_parser.m_lex.m_buffer.m_pos,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v2->m_parser.m_lex.m_buffer.m_pos);
  v6 = v2->m_parser.m_lex.m_buffer.m_lexemeStart;
  v2->m_parser.m_lex.m_buffer.m_bufferStart = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)&v2->m_parser.m_lex.m_buffer.m_memSizeAndFlags,
      8 * v6);
  *(_QWORD *)&v2->m_parser.m_lex.m_buffer.m_memSizeAndFlags = 0i64;
  v2->m_parser.m_lex.m_buffer.m_lexemeStart = 2147483648;
  v7 = *(_DWORD *)(&v2->m_parser.m_lex.m_referenceCount + 1);
  *(_DWORD *)&v2->m_parser.m_lex.m_memSizeAndFlags = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_parser.m_lex.vfptr,
      8 * v7);
  v2->m_parser.m_lex.vfptr = 0i64;
  *(_DWORD *)(&v2->m_parser.m_lex.m_referenceCount + 1) = 2147483648;
  v8 = v2->m_parser.m_keyStorage.m_capacityAndFlags;
  v2->m_parser.m_keyStorage.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_parser.m_keyStorage.m_data,
      8 * v8);
  v2->m_parser.m_keyStorage.m_data = 0i64;
  v2->m_parser.m_keyStorage.m_capacityAndFlags = 2147483648;
  hkIArchive::~hkIArchive((hkIArchive *)&v2->m_parser.m_memSizeAndFlags);
}

// File Line: 154
// RVA: 0xE4F1D0
hkResult *__fastcall `anonymous namespace'::Reader::readHeader(Reader *this, hkResult *result, hkBinaryTagfile::Header *out)
{
  hkIArchive *v3; // rsi
  hkBinaryTagfile::Header *v4; // r12
  hkResult *v5; // rbx
  int v7; // ecx
  signed int v8; // er14
  int v9; // er13
  signed int v10; // er15
  unsigned int v11; // edi
  char v12; // cl
  int v13; // er15
  unsigned int v14; // edi
  char v15; // cl
  signed int v16; // eax
  const char *v17; // rax
  hkOstream *v18; // rax
  char v19; // [rsp+20h] [rbp-E0h]
  unsigned int array; // [rsp+24h] [rbp-DCh]
  int v21; // [rsp+28h] [rbp-D8h]
  hkErrStream v22; // [rsp+30h] [rbp-D0h]
  char buf; // [rsp+50h] [rbp-B0h]
  int *v24; // [rsp+290h] [rbp+190h]
  hkBool resulta; // [rsp+2A8h] [rbp+1A8h]
  char v26; // [rsp+2A9h] [rbp+1A9h]
  char v27; // [rsp+2AAh] [rbp+1AAh]
  char v28; // [rsp+2ABh] [rbp+1ABh]

  v24 = (int *)this;
  v3 = (hkIArchive *)&this->m_parser.m_memSizeAndFlags;
  v4 = out;
  v5 = result;
  hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 4, 1);
  if ( !hkIArchive::isOk(v3, &resulta)->m_bool )
    goto LABEL_30;
  hkIArchive::readArrayGeneric(v3, &v21, 4, 1);
  if ( !hkIArchive::isOk(v3, &resulta)->m_bool )
    goto LABEL_30;
  v7 = v21;
  if ( array != -894431970 || v21 != -804128050 )
  {
    v28 = array;
    resulta.m_bool = HIBYTE(array);
    v26 = BYTE2(array);
    v27 = BYTE1(array);
    if ( *(_DWORD *)&resulta.m_bool != -894431970
      || (v28 = v21,
          resulta.m_bool = HIBYTE(v21),
          v26 = BYTE2(v21),
          v27 = BYTE1(v7),
          *(_DWORD *)&resulta.m_bool != -804128050) )
    {
LABEL_30:
      v5->m_enum = 1;
      return v5;
    }
  }
  v4->m_magic1 = array;
  v4->m_magic2 = v7;
  hkIArchive::readArrayGeneric(v3, &resulta, 1, 1);
  v8 = 6;
  v9 = resulta.m_bool & 1;
  v10 = 6;
  v11 = ((unsigned int)(unsigned __int8)resulta.m_bool >> 1) & 0x7FFFFFBF;
  if ( resulta.m_bool < 0 )
  {
    do
    {
      hkIArchive::readArrayGeneric(v3, &v19, 1, 1);
      v12 = v10;
      v10 += 7;
      v11 |= (v19 & 0x7F) << v12;
    }
    while ( v19 < 0 );
  }
  if ( v9 )
    v11 = -v11;
  v4->m_fileInfo = v11;
  if ( !hkIArchive::isOk(v3, &resulta)->m_bool )
    goto LABEL_26;
  hkIArchive::readArrayGeneric(v3, &resulta, 1, 1);
  v13 = resulta.m_bool & 1;
  v14 = ((unsigned int)(unsigned __int8)resulta.m_bool >> 1) & 0x7FFFFFBF;
  if ( resulta.m_bool < 0 )
  {
    do
    {
      hkIArchive::readArrayGeneric(v3, &v19, 1, 1);
      v15 = v8;
      v8 += 7;
      v14 |= (v19 & 0x7F) << v15;
    }
    while ( v19 < 0 );
  }
  if ( v13 )
    v14 = -v14;
  v4->m_version = v14;
  if ( !hkIArchive::isOk(v3, &resulta)->m_bool )
    goto LABEL_26;
  v16 = v4->m_version;
  if ( v16 < 0 )
  {
LABEL_25:
    hkErrStream::hkErrStream(&v22, &buf, 512);
    v18 = hkOstream::operator<<((hkOstream *)&v22.vfptr, "Unrecognised tagfile version ");
    hkOstream::operator<<(v18, *v24, (int)v18);
    hkError::messageWarning(716571503, &buf, "Tagfile\\Binary\\hkBinaryTagfileReader.cpp", 193);
    hkOstream::~hkOstream((hkOstream *)&v22.vfptr);
LABEL_26:
    v5->m_enum = 1;
    return v5;
  }
  if ( v16 > 3 )
  {
    if ( v16 == 4 )
    {
      if ( v24[26] == (v24[27] & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v24 + 24, 8);
      *(_QWORD *)(*((_QWORD *)v24 + 12) + 8i64 * v24[26]++) = 0i64;
      v17 = `anonymous namespace'::Reader::readString((Reader *)v24);
      hkStringPtr::operator=(&v4->m_sdk, v17);
      goto LABEL_24;
    }
    goto LABEL_25;
  }
LABEL_24:
  v5->m_enum = 0;
  return v5;
}

// File Line: 253
// RVA: 0xE50190
const char *__fastcall `anonymous namespace'::Reader::readString(Reader *this)
{
  Reader *v1; // r14
  signed int v2; // edi
  int v3; // ebp
  int v4; // ebx
  char v5; // cl
  hkMemoryAllocator **v6; // rax
  void *v7; // rdi
  unsigned __int8 array; // [rsp+40h] [rbp+8h]
  char v10; // [rsp+48h] [rbp+10h]

  v1 = this;
  hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 1, 1);
  v2 = 6;
  v3 = array & 1;
  v4 = ((unsigned int)array >> 1) & 0x7FFFFFBF;
  if ( (array & 0x80u) != 0 )
  {
    do
    {
      hkIArchive::readArrayGeneric((hkIArchive *)&v1->m_parser.m_memSizeAndFlags, &v10, 1, 1);
      v5 = v2;
      v2 += 7;
      v4 |= (v10 & 0x7F) << v5;
    }
    while ( v10 < 0 );
  }
  if ( v3 )
    v4 = -v4;
  if ( v4 <= 0 )
    return (const char *)*((_QWORD *)&v1->m_parser.m_lex.vfptr->__vecDelDtor - v4);
  v6 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (void *)hkMemoryRouter::easyAlloc(v6[11], v4 + 1);
  hkIArchive::readRaw((hkIArchive *)&v1->m_parser.m_memSizeAndFlags, v7, v4);
  *((_BYTE *)v7 + v4) = 0;
  if ( *(_DWORD *)&v1->m_parser.m_lex.m_memSizeAndFlags == (*(_DWORD *)(&v1->m_parser.m_lex.m_referenceCount + 1) & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v1->m_parser.m_lex, 8);
  *((_QWORD *)&v1->m_parser.m_lex.vfptr->__vecDelDtor + (signed int)(*(_DWORD *)&v1->m_parser.m_lex.m_memSizeAndFlags)++) = v7;
  return (const char *)v7;
}

// File Line: 270
// RVA: 0xE4F1A0
float __fastcall `anonymous namespace'::Reader::readFloat(Reader *this)
{
  float array; // [rsp+30h] [rbp+8h]

  hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 4, 1);
  return array;
}

// File Line: 275
// RVA: 0xE4EC20
void __fastcall `anonymous namespace'::Reader::readBitfield(Reader *this, int numMembers, hkLocalArray<unsigned char> *bout)
{
  int v3; // edi
  Reader *v4; // r14
  signed int v5; // esi
  hkLocalArray<unsigned char> *v6; // rbx
  int v7; // ecx
  __int64 v8; // rbp
  int v9; // ecx
  int v10; // er9
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
  int v21; // er9
  char array[64]; // [rsp+30h] [rbp-58h]
  hkResult result; // [rsp+98h] [rbp+10h]

  v3 = numMembers;
  v4 = this;
  v5 = (numMembers + 7) & 0xFFFFFFF8;
  v6 = bout;
  v7 = bout->m_capacityAndFlags & 0x3FFFFFFF;
  v8 = v5 / 8;
  if ( v7 < v5 )
  {
    v9 = 2 * v7;
    v10 = (numMembers + 7) & 0xFFFFFFF8;
    if ( v5 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, bout, v10, 1);
  }
  v6->m_size = v5;
  hkIArchive::readArrayGeneric((hkIArchive *)&v4->m_parser.m_memSizeAndFlags, array, 1, v8);
  v11 = 0i64;
  if ( (signed int)v8 > 0 )
  {
    do
    {
      v12 = (unsigned __int8)array[v11++];
      v13 = v12;
      v12 >>= 1;
      v6->m_data[8 * v11 - 8] = v13 & 1;
      v14 = v12 & 1;
      v12 >>= 1;
      v6->m_data[8 * v11 - 7] = v14;
      v15 = v12 & 1;
      v12 >>= 1;
      v6->m_data[8 * v11 - 6] = v15;
      v16 = v12 & 1;
      v12 >>= 1;
      v6->m_data[8 * v11 - 5] = v16;
      v17 = v12 & 1;
      v12 >>= 1;
      v6->m_data[8 * v11 - 4] = v17;
      v18 = v12 & 1;
      v12 >>= 1;
      v6->m_data[8 * v11 - 3] = v18;
      v6->m_data[8 * v11 - 2] = v12 & 1;
      v6->m_data[8 * v11 - 1] = (v12 >> 1) & 1;
    }
    while ( v11 < v8 );
  }
  v19 = v6->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v19 < v3 )
  {
    v20 = 2 * v19;
    v21 = v3;
    if ( v3 < v20 )
      v21 = v20;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, v21, 1);
  }
  v6->m_size = v3;
}

// File Line: 308
// RVA: 0xE4D740
void __fastcall `anonymous namespace'::Reader::_readArrayInts(Reader *this, hkDataArray *arr, int size)
{
  hkDataArray *v3; // rbx
  char *v4; // rax
  IntReader v5; // [rsp+30h] [rbp-38h]
  __int64 v6; // [rsp+80h] [rbp+18h]

  if ( size > 0 )
  {
    v5.m_remaining = size;
    v3 = arr;
    v5.m_archive = (hkIArchive *)&this->m_parser.m_memSizeAndFlags;
    v4 = 0i64;
    v5.m_buffer.m_data = 0i64;
    v5.m_buffer.m_size = 0;
    v5.m_buffer.m_capacityAndFlags = 2147483648;
    if ( size > 0 )
    {
      hkArrayUtil::_reserve(
        (hkResult *)&v6,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        &v5.m_buffer,
        size,
        1);
      v4 = v5.m_buffer.m_data;
    }
    v5.m_buffer.m_size = 0;
    v5.m_cur = v4;
    v5.m_end = v4;
    `anonymous namespace'::IntReader::readArray(&v5, v3);
    v5.m_buffer.m_size = 0;
    if ( v5.m_buffer.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v5.m_buffer.m_data,
        v5.m_buffer.m_capacityAndFlags & 0x3FFFFFFF);
  }
}

// File Line: 318
// RVA: 0xE4D7F0
void __fastcall `anonymous namespace'::Reader::_readArrayItems(Reader *this, hkDataArray *arr, int nelem)
{
  Reader *v3; // rdi
  int v4; // esi
  hkTypeManager::Type *v5; // rax
  hkTypeManager::Type *v6; // rbx
  hkTypeManager::SubType v7; // eax
  hkResultEnum v8; // ecx
  void *v9; // rax
  void *v10; // rdx
  unsigned int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // er9
  hkDataArrayImpl *v15; // rdx
  hkDataArrayImpl *v16; // rdi
  int v17; // ecx
  unsigned int v18; // ebx
  signed int v19; // esi
  char v20; // cl
  hkDataArrayImpl *v21; // rdi
  unsigned __int64 v22; // rbx
  int v23; // ecx
  int v24; // esi
  hkIArchive *v25; // rdi
  char v26; // cl
  __int32 v27; // ecx
  void *v28; // r10
  unsigned int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // er9
  int v33; // eax
  unsigned int v34; // ebx
  signed int v35; // edi
  int v36; // eax
  hkIArchive *v37; // rsi
  char v38; // cl
  int v39; // eax
  hkDataArrayImpl *v40; // rdx
  int v41; // er9
  int v42; // er8
  _DWORD *v43; // r9
  _DWORD *v44; // rcx
  unsigned int v45; // eax
  __int64 v46; // rdx
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int *v51; // r9
  _DWORD *v52; // rcx
  __int64 v53; // rdx
  int v54; // eax
  int v55; // ebx
  signed int v56; // edi
  int v57; // ecx
  hkIArchive *v58; // rsi
  char v59; // cl
  int v60; // edi
  hkIArchive *v61; // rax
  int j; // edi
  int i; // edi
  const char *v64; // rax
  __int64 v65; // rax
  __int64 v66; // rbx
  hkResultEnum v67; // eax
  hkLifoAllocator *v68; // rax
  char *v69; // rcx
  unsigned __int64 v70; // rdx
  __int64 v71; // r8
  int v72; // edx
  hkLifoAllocator *v73; // rax
  char *v74; // rcx
  int v75; // edx
  char *v76; // r9
  char *v77; // rax
  signed __int64 v78; // r9
  int v79; // eax
  __int64 v80; // rdx
  char *v81; // rax
  __int64 v82; // rcx
  __int64 v83; // rdx
  char *v84; // rbx
  hkDataArrayImpl *v85; // rax
  hkDataArrayImpl *v86; // rcx
  __int64 v87; // rdx
  int v88; // ebx
  hkTypeManager::Type *v89; // rdi
  hkDataArrayImpl *v90; // rax
  int v91; // eax
  hkDataArrayImpl *v92; // rcx
  bool v93; // zf
  bool v94; // sf
  unsigned __int8 v95; // of
  int v96; // eax
  char *v97; // rsi
  signed int v98; // ebx
  hkLifoAllocator *v99; // rax
  int v100; // er8
  int v101; // eax
  char *v102; // rsi
  signed int v103; // ebx
  hkLifoAllocator *v104; // rax
  int v105; // er8
  hkDataArrayImpl *v106; // rdi
  hkIArchive *v107; // rax
  int v108; // ecx
  unsigned int v109; // ebx
  int v110; // esi
  hkIArchive *v111; // rdi
  char v112; // cl
  hkDataArrayImpl *v113; // rax
  hkDataArrayImpl *v114; // rcx
  char v115; // [rsp+30h] [rbp-89h]
  __m128i array; // [rsp+40h] [rbp-79h]
  __int64 v117; // [rsp+50h] [rbp-69h]
  __int64 v118; // [rsp+58h] [rbp-61h]
  hkDataArray v119; // [rsp+60h] [rbp-59h]
  hkDataArray v120[2]; // [rsp+70h] [rbp-49h]
  char *v121; // [rsp+80h] [rbp-39h]
  int v122; // [rsp+88h] [rbp-31h]
  int v123; // [rsp+8Ch] [rbp-2Dh]
  void *p; // [rsp+90h] [rbp-29h]
  hkResultEnum v125; // [rsp+98h] [rbp-21h]
  int v126; // [rsp+A0h] [rbp-19h]
  hkResult result; // [rsp+A4h] [rbp-15h]
  hkLocalArray<unsigned char> bout; // [rsp+B0h] [rbp-9h]
  Reader *v129; // [rsp+120h] [rbp+67h]
  hkDataArray *arra; // [rsp+128h] [rbp+6Fh]
  int v131; // [rsp+130h] [rbp+77h]
  hkResult v132; // [rsp+138h] [rbp+7Fh]

  v131 = nelem;
  arra = arr;
  v129 = this;
  v3 = this;
  v4 = nelem;
  v5 = (hkTypeManager::Type *)((__int64 (*)(void))arr->m_impl->vfptr[1].__vecDelDtor)();
  v6 = v5;
  v7 = v5->m_subType;
  switch ( v7 )
  {
    case 2:
      v8 = v4;
      array.m128i_i64[0] = 0i64;
      array.m128i_i64[1] = 0x8000000000000000i64;
      if ( v4 )
      {
        v132.m_enum = v4;
        v9 = hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
               (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
               (int *)&v132);
        v8 = v132.m_enum;
        v10 = v9;
      }
      else
      {
        v10 = 0i64;
      }
      v11 = 2147483648;
      array.m128i_i64[0] = (__int64)v10;
      if ( v8 )
        v11 = v8;
      array.m128i_i64[1] = __PAIR__(v11, v4);
      v12 = v11 & 0x3FFFFFFF;
      if ( v12 >= v4 )
      {
        result.m_enum = 0;
      }
      else
      {
        v13 = 2 * v12;
        v14 = v4;
        if ( v4 < v13 )
          v14 = v13;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v14, 1);
        v10 = (void *)array.m128i_i64[0];
      }
      hkIArchive::readArrayGeneric((hkIArchive *)&v129->m_parser.m_memSizeAndFlags, v10, 1, v4);
      ((void (__fastcall *)(hkDataArrayImpl *, __int64, _QWORD))arra->m_impl->vfptr[35].__vecDelDtor)(
        arra->m_impl,
        array.m128i_i64[0],
        (unsigned int)v4);
      array.m128i_i32[2] = 0;
      if ( array.m128i_i32[3] >= 0 )
        goto LABEL_13;
      return;
    case 3:
      v27 = v4;
      array.m128i_i64[0] = 0i64;
      array.m128i_i64[1] = 0x8000000000000000i64;
      if ( v4 )
      {
        v132.m_enum = 4 * v4;
        v28 = hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                (int *)&v132);
        v27 = v132.m_enum / 4;
      }
      else
      {
        v28 = 0i64;
      }
      v29 = 2147483648;
      array.m128i_i64[0] = (__int64)v28;
      if ( v27 )
        v29 = v27;
      array.m128i_i64[1] = __PAIR__(v29, v4);
      v30 = v29 & 0x3FFFFFFF;
      if ( v30 < v4 )
      {
        v31 = 2 * v30;
        v32 = v4;
        if ( v4 < v31 )
          v32 = v31;
        hkArrayUtil::_reserve(&v132, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v32, 4);
        v28 = (void *)array.m128i_i64[0];
      }
      array.m128i_i32[2] = v4;
      hkIArchive::readArrayGeneric((hkIArchive *)&v129->m_parser.m_memSizeAndFlags, v28, 4, v4);
      ((void (__fastcall *)(hkDataArrayImpl *, __int64, _QWORD))arra->m_impl->vfptr[28].__vecDelDtor)(
        arra->m_impl,
        array.m128i_i64[0],
        array.m128i_u32[2]);
      array.m128i_i32[2] = 0;
      if ( array.m128i_i32[3] >= 0 )
      {
LABEL_13:
        v15 = (hkDataArrayImpl *)array.m128i_i64[0];
        goto LABEL_14;
      }
      return;
    case 4:
      if ( SLODWORD(v3->m_parser.vfptr) < 3 )
        goto LABEL_33;
      v16 = (hkDataArrayImpl *)&v3->m_parser.m_memSizeAndFlags;
      v120[0].m_impl = v16;
      hkIArchive::readArrayGeneric((hkIArchive *)v16, &v132, 1, 1);
      v17 = v132.m_enum & 1;
      v18 = ((unsigned int)LOBYTE(v132.m_enum) >> 1) & 0x7FFFFFBF;
      LODWORD(v118) = v132.m_enum & 1;
      if ( SLOBYTE(v132.m_enum) < 0 )
      {
        v19 = 6;
        do
        {
          hkIArchive::readArrayGeneric((hkIArchive *)v16, &v115, 1, 1);
          v20 = v19;
          v19 += 7;
          v18 |= (v115 & 0x7F) << v20;
        }
        while ( v115 < 0 );
        v4 = v131;
        v17 = v118;
      }
      if ( v17 )
        v18 = -v18;
      if ( v18 == 4 )
      {
        v3 = v129;
LABEL_33:
        `anonymous namespace'::Reader::_readArrayInts(v3, arra, v4);
        return;
      }
      LODWORD(v21) = 0;
      v119.m_impl = 0i64;
      if ( v4 > 0 )
      {
        do
        {
          hkIArchive::readArrayGeneric((hkIArchive *)v120[0].m_impl, &v132, 1, 1);
          LODWORD(v118) = 6;
          v22 = ((unsigned __int64)LOBYTE(v132.m_enum) >> 1) & 0x7FFFFFFFFFFFFFBFi64;
          v23 = v132.m_enum & 1;
          LODWORD(v117) = v132.m_enum & 1;
          if ( SLOBYTE(v132.m_enum) < 0 )
          {
            v24 = v118;
            v25 = (hkIArchive *)v120[0].m_impl;
            do
            {
              hkIArchive::readArrayGeneric(v25, &v115, 1, 1);
              v26 = v24;
              v24 += 7;
              v22 |= (unsigned __int64)(v115 & 0x7F) << v26;
            }
            while ( v115 < 0 );
            LODWORD(v21) = v119.m_impl;
            v4 = v131;
            v23 = v117;
          }
          if ( v23 )
            v22 = -(signed __int64)v22;
          ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, unsigned __int64))arra->m_impl->vfptr[20].__vecDelDtor)(
            arra->m_impl,
            (unsigned int)v21,
            v22);
          v21 = (hkDataArrayImpl *)(unsigned int)((_DWORD)v21 + 1);
          v119.m_impl = v21;
        }
        while ( (signed int)v21 < v4 );
      }
      break;
    case 5:
      for ( i = 0; i < v4; ++i )
      {
        v64 = `anonymous namespace'::Reader::readString(v129);
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, const char *))arra->m_impl->vfptr[14].__vecDelDtor)(
          arra->m_impl,
          (unsigned int)i,
          v64);
      }
      break;
    case 6:
      arra->m_impl->vfptr[4].__vecDelDtor((hkDataRefCounted *)arra->m_impl, v4);
      v65 = ((__int64 (*)(void))arra->m_impl->vfptr[6].__vecDelDtor)();
      v66 = v65;
      v67 = (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v65 + 72i64))(v65);
      bout.m_data = 0i64;
      bout.m_size = 0;
      bout.m_capacityAndFlags = 2147483648;
      v132.m_enum = v67;
      bout.m_initialCapacity = 128;
      v68 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v69 = (char *)v68->m_cur;
      v70 = (unsigned __int64)(v69 + 128);
      if ( v68->m_slabSize < 128 || (void *)v70 > v68->m_end )
        v69 = (char *)hkLifoAllocator::allocateFromNewSlab(v68, 128);
      else
        v68->m_cur = (void *)v70;
      bout.m_data = v69;
      bout.m_localMemory = v69;
      bout.m_capacityAndFlags = -2147483520;
      `anonymous namespace'::Reader::readBitfield(v129, v132.m_enum, &bout);
      v71 = (unsigned int)v132.m_enum;
      v72 = 0;
      v121 = 0i64;
      v122 = 0;
      v123 = 2147483648;
      v125 = v132.m_enum;
      if ( v132.m_enum )
      {
        v73 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v71 = (unsigned int)v132.m_enum;
        v74 = (char *)v73->m_cur;
        v75 = (32 * v132.m_enum + 127) & 0xFFFFFF80;
        v76 = &v74[v75];
        if ( v75 > v73->m_slabSize || v76 > v73->m_end )
        {
          v77 = (char *)hkLifoAllocator::allocateFromNewSlab(v73, v75);
          v71 = (unsigned int)v132.m_enum;
          v72 = v122;
          v74 = v77;
        }
        else
        {
          v73->m_cur = v76;
          v72 = v122;
        }
      }
      else
      {
        v74 = 0i64;
      }
      v121 = v74;
      p = v74;
      v123 = v71 | 0x80000000;
      v78 = 32i64 * v72 + 16;
      v79 = v71 - v72;
      v80 = (signed int)v71 - v72;
      if ( v79 > 0 )
      {
        v81 = &v74[v78];
        do
        {
          if ( v81 != (char *)16 )
          {
            *((_QWORD *)v81 - 2) = 0i64;
            *((_QWORD *)v81 - 1) = 0i64;
            *(_QWORD *)v81 = 0i64;
            *((_QWORD *)v81 + 1) = 0i64;
          }
          v81 += 32;
          --v80;
        }
        while ( v80 );
      }
      v122 = v71;
      (*(void (__fastcall **)(__int64, char **, __int64, signed __int64))(*(_QWORD *)v66 + 96i64))(v66, &v121, v71, v78);
      v82 = 0i64;
      v118 = 0i64;
      if ( (signed int)v132.m_enum > 0i64 )
      {
        v83 = 0i64;
        v117 = 0i64;
        do
        {
          v84 = v121;
          if ( bout.m_data[v82] )
          {
            v85 = (hkDataArrayImpl *)arra->m_impl->vfptr[10].__vecDelDtor(
                                       (hkDataRefCounted *)arra->m_impl,
                                       *(_QWORD *)&v121[v83]);
            v86 = v85;
            v119.m_impl = v85;
            if ( v85 )
            {
              ++v85->m_externalCount;
              ++v85->m_count;
              v86 = v119.m_impl;
            }
            v87 = *(_QWORD *)&v84[v117 + 16];
            if ( *(_DWORD *)v87 == 9 && (**(_DWORD **)(v87 + 8) != 3 || (*(_DWORD *)(v87 + 16) - 4) & 0xFFFFFFF3) )
            {
              v88 = 0;
              if ( v4 > 0 )
              {
                v89 = (hkTypeManager::Type *)v87;
                do
                {
                  v90 = (hkDataArrayImpl *)v86->vfptr[23].__vecDelDtor((hkDataRefCounted *)&v86->vfptr, v88);
                  v120[0].m_impl = v90;
                  if ( v90 )
                  {
                    ++v90->m_externalCount;
                    ++v90->m_count;
                  }
                  v91 = hkTypeManager::Type::getTupleSize(v89);
                  `anonymous namespace'::Reader::_readArrayItems(v129, v120, v91);
                  v92 = v120[0].m_impl;
                  if ( v120[0].m_impl )
                  {
                    --v120[0].m_impl->m_externalCount;
                    v93 = v92->m_count-- == 1;
                    if ( v93 )
                      v92->vfptr->__vecDelDtor((hkDataRefCounted *)&v92->vfptr, 1u);
                  }
                  v86 = v119.m_impl;
                  ++v88;
                }
                while ( v88 < v4 );
              }
            }
            else
            {
              `anonymous namespace'::Reader::_readArrayItems(v129, &v119, v4);
              v86 = v119.m_impl;
            }
            if ( v86 )
            {
              --v86->m_externalCount;
              v93 = v86->m_count-- == 1;
              if ( v93 )
                v86->vfptr->__vecDelDtor((hkDataRefCounted *)&v86->vfptr, 1u);
            }
          }
          v117 += 32i64;
          v83 = v117;
          v95 = __OFSUB__(v118 + 1, v132.m_enum);
          v94 = v118 + 1 - (signed int)v132.m_enum < 0;
          v82 = v118++ + 1;
        }
        while ( v94 ^ v95 );
      }
      v96 = v122;
      v97 = (char *)p;
      if ( p == v121 )
        v96 = 0;
      v122 = v96;
      v98 = (32 * v125 + 127) & 0xFFFFFF80;
      v99 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v100 = (v98 + 15) & 0xFFFFFFF0;
      if ( v98 > v99->m_slabSize || &v97[v100] != v99->m_cur || v99->m_firstNonLifoEnd == v97 )
        hkLifoAllocator::slowBlockFree(v99, v97, v100);
      else
        v99->m_cur = v97;
      v122 = 0;
      if ( v123 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v121,
          32 * v123);
      v101 = bout.m_size;
      v102 = bout.m_localMemory;
      v121 = 0i64;
      if ( bout.m_localMemory == bout.m_data )
        v101 = 0;
      v123 = 2147483648;
      v103 = (bout.m_initialCapacity + 127) & 0xFFFFFF80;
      bout.m_size = v101;
      v104 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v105 = (v103 + 15) & 0xFFFFFFF0;
      if ( v103 > v104->m_slabSize || &v102[v105] != v104->m_cur || v104->m_firstNonLifoEnd == v102 )
        hkLifoAllocator::slowBlockFree(v104, v102, v105);
      else
        v104->m_cur = v102;
      bout.m_size = 0;
      if ( bout.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          bout.m_data,
          bout.m_capacityAndFlags & 0x3FFFFFFF);
      break;
    case 7:
      for ( j = 0; j < v4; ++j )
      {
        array.m128i_i32[2] = j;
        *(hkDataArray *)array.m128i_i8 = (hkDataArray)arra->m_impl;
        _mm_store_si128((__m128i *)v120, array);
        `anonymous namespace'::Reader::readObjectIntoValue<hkDataArray_Value>(v129, (hkDataArray_Value *)v120);
      }
      break;
    case 8:
      arra->m_impl->vfptr[4].__vecDelDtor((hkDataRefCounted *)arra->m_impl, v4);
      LODWORD(v106) = 0;
      v119.m_impl = 0i64;
      if ( v4 > 0 )
      {
        v107 = (hkIArchive *)&v129->m_parser.m_memSizeAndFlags;
        array.m128i_i64[0] = (__int64)&v129->m_parser.m_memSizeAndFlags;
        do
        {
          hkIArchive::readArrayGeneric(v107, &v132, 1, 1);
          LODWORD(v117) = 6;
          v108 = v132.m_enum & 1;
          v109 = ((unsigned int)LOBYTE(v132.m_enum) >> 1) & 0x7FFFFFBF;
          LODWORD(v118) = v132.m_enum & 1;
          if ( SLOBYTE(v132.m_enum) < 0 )
          {
            v110 = v117;
            v111 = (hkIArchive *)array.m128i_i64[0];
            do
            {
              hkIArchive::readArrayGeneric(v111, &v115, 1, 1);
              v112 = v110;
              v110 += 7;
              v109 |= (v115 & 0x7F) << v112;
            }
            while ( v115 < 0 );
            LODWORD(v106) = v119.m_impl;
            v4 = v131;
            v108 = v118;
          }
          if ( v108 )
            v109 = -v109;
          v113 = (hkDataArrayImpl *)arra->m_impl->vfptr[23].__vecDelDtor(
                                      (hkDataRefCounted *)arra->m_impl,
                                      (unsigned int)v106);
          v120[0].m_impl = v113;
          if ( v113 )
          {
            ++v113->m_externalCount;
            ++v113->m_count;
            v113 = v120[0].m_impl;
          }
          v113->vfptr[4].__vecDelDtor((hkDataRefCounted *)&v113->vfptr, v109);
          `anonymous namespace'::Reader::_readArrayItems(v129, v120, v109);
          v114 = v120[0].m_impl;
          if ( v120[0].m_impl )
          {
            --v120[0].m_impl->m_externalCount;
            v93 = v114->m_count-- == 1;
            if ( v93 )
              v114->vfptr->__vecDelDtor((hkDataRefCounted *)&v114->vfptr, 1u);
          }
          v107 = (hkIArchive *)array.m128i_i64[0];
          v106 = (hkDataArrayImpl *)(unsigned int)((_DWORD)v106 + 1);
          v119.m_impl = v106;
        }
        while ( (signed int)v106 < v4 );
      }
      break;
    case 9:
      if ( v7 == 9 && v6->m_parent->m_subType == 3 && !((v6->m_extra.m_size - 4) & 0xFFFFFFF3) )
      {
        ((void (__fastcall *)(hkDataArrayImpl *, int *, char **))arra->m_impl->vfptr[8].__vecDelDtor)(
          arra->m_impl,
          &v126,
          &v121);
        if ( v126 )
        {
          v55 = hkTypeManager::Type::getTupleSize(v6);
          if ( v55 == 4 )
          {
            bout.m_capacityAndFlags = 0;
            array.m128i_i64[0] = (__int64)&v3->m_parser.m_memSizeAndFlags;
            hkIArchive::readArrayGeneric((hkIArchive *)&v3->m_parser.m_memSizeAndFlags, &v132, 1, 1);
            v56 = 6;
            v57 = v132.m_enum & 1;
            v55 = ((unsigned int)LOBYTE(v132.m_enum) >> 1) & 0x7FFFFFBF;
            LODWORD(v117) = v132.m_enum & 1;
            if ( SLOBYTE(v132.m_enum) < 0 )
            {
              v58 = (hkIArchive *)array.m128i_i64[0];
              do
              {
                hkIArchive::readArrayGeneric(v58, &v115, 1, 1);
                v59 = v56;
                v56 += 7;
                v55 |= (v115 & 0x7F) << v59;
              }
              while ( v115 < 0 );
              v4 = v131;
              v57 = v117;
            }
            if ( v57 )
              v55 = -v55;
          }
          v60 = 0;
          if ( v4 > 0 )
          {
            v61 = (hkIArchive *)&v129->m_parser.m_memSizeAndFlags;
            *(_QWORD *)&v132.m_enum = (char *)v129 + 8;
            do
            {
              hkIArchive::readArrayGeneric(v61, &bout, 4, v55);
              ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, hkLocalArray<unsigned char> *))arra->m_impl->vfptr[12].__vecDelDtor)(
                arra->m_impl,
                (unsigned int)v60,
                &bout);
              v61 = *(hkIArchive **)&v132.m_enum;
              ++v60;
            }
            while ( v60 < v4 );
          }
        }
        else
        {
          v33 = hkTypeManager::Type::getTupleSize(v6);
          LODWORD(v118) = v33;
          v34 = v33;
          if ( v33 == 4 )
          {
            array.m128i_i64[0] = (__int64)&v3->m_parser.m_memSizeAndFlags;
            hkIArchive::readArrayGeneric((hkIArchive *)&v3->m_parser.m_memSizeAndFlags, &v132, 1, 1);
            v35 = 6;
            v36 = v132.m_enum & 1;
            v34 = ((unsigned int)LOBYTE(v132.m_enum) >> 1) & 0x7FFFFFBF;
            LODWORD(v117) = v132.m_enum & 1;
            if ( SLOBYTE(v132.m_enum) < 0 )
            {
              v37 = (hkIArchive *)array.m128i_i64[0];
              do
              {
                hkIArchive::readArrayGeneric(v37, &v115, 1, 1);
                v38 = v35;
                v35 += 7;
                v34 |= (v115 & 0x7F) << v38;
              }
              while ( v115 < 0 );
              v4 = v131;
              v36 = v117;
            }
            if ( v36 )
              v34 = -v34;
            v33 = v118;
          }
          v39 = v4 * v33;
          v40 = 0i64;
          v120[1].m_impl = (hkDataArrayImpl *)0x8000000000000000i64;
          LODWORD(v117) = v39;
          v120[0].m_impl = 0i64;
          if ( v39 > 0 )
          {
            v41 = v39;
            if ( v39 < 0 )
              v41 = 0;
            hkArrayUtil::_reserve(
              (hkResult *)&v119,
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
              v120,
              v41,
              4);
            v40 = v120[0].m_impl;
            v39 = v117;
          }
          LODWORD(v120[1].m_impl) = v39;
          hkIArchive::readArrayGeneric((hkIArchive *)&v129->m_parser.m_memSizeAndFlags, v40, 4, v4 * v34);
          if ( (_DWORD)v118 != v34 )
          {
            v42 = 0;
            v43 = (_DWORD *)((char *)v120[0].m_impl + 4 * (signed int)(v34 * (v4 - 1)));
            v44 = (_DWORD *)((char *)v120[0].m_impl + 4 * (signed int)v118 * (v4 - 1));
            if ( v4 >= 4 )
            {
              v45 = ((unsigned int)(v4 - 4) >> 2) + 1;
              v46 = v45;
              v42 = 4 * v45;
              do
              {
                v44[3] = 0;
                v44 -= 16;
                v44[18] = v43[2];
                v47 = v43[1];
                v43 -= 12;
                v44[17] = v47;
                v48 = v43[12];
                v44[15] = 0;
                v44[16] = v48;
                v44[14] = v43[11];
                v44[13] = v43[10];
                v49 = v43[9];
                v44[11] = 0;
                v44[12] = v49;
                v44[10] = v43[8];
                v44[9] = v43[7];
                v50 = v43[6];
                v44[7] = 0;
                v44[8] = v50;
                v44[6] = v43[5];
                v44[5] = v43[4];
                v44[4] = v43[3];
                --v46;
              }
              while ( v46 );
            }
            if ( v42 < v4 )
            {
              v51 = v43 + 1;
              v52 = v44 + 2;
              v53 = (unsigned int)(v4 - v42);
              do
              {
                v52[1] = 0;
                v52 -= 4;
                v52[4] = v51[1];
                v54 = *v51;
                v51 -= 3;
                v52[3] = v54;
                v52[2] = v51[2];
                --v53;
              }
              while ( v53 );
            }
          }
          ((void (__fastcall *)(hkDataArrayImpl *, hkDataArrayImpl *, _QWORD))arra->m_impl->vfptr[28].__vecDelDtor)(
            arra->m_impl,
            v120[0].m_impl,
            (unsigned int)v4);
          LODWORD(v120[1].m_impl) = 0;
          if ( SHIDWORD(v120[1].m_impl) >= 0 )
          {
            v15 = v120[0].m_impl;
LABEL_14:
            ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkDataArrayImpl *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
              &hkContainerTempAllocator::s_alloc,
              v15);
          }
        }
      }
      break;
    default:
      return;
  }
}cator::s_alloc,
              v15);
          }
        }
      }
      break;
    default:
      return;
  }
}

// File Line: 510
// RVA: 0xE4E700
void __usercall `anonymous namespace'::Reader::readBinaryValue(Reader *this@<rcx>, hkDataObject_Value *value@<rdx>, hkDataClass_MemberInfo *minfo@<r8>, hkDataArrayImpl *a4@<rbx>)
{
  Reader *v4; // r14
  hkDataObjectImpl *v5; // rcx
  hkDataClass_MemberInfo *v6; // rbx
  hkDataObject_Value *v7; // rsi
  hkTypeManager::Type *v8; // rdi
  hkTypeManager::SubType v9; // edx
  hkDataArrayImpl *v10; // rax
  hkDataArrayImpl *v11; // rbx
  int v12; // eax
  signed int v13; // ebx
  signed int v14; // edi
  int v15; // er13
  unsigned int v16; // er15
  char v17; // cl
  hkTypeManager::Type *v18; // rcx
  int v19; // er13
  signed int v20; // edi
  char v21; // cl
  const char *v22; // rax
  hkTypeManager::Type *v23; // rax
  hkDataArrayImpl *v24; // rax
  bool v25; // zf
  signed int v26; // ebx
  int v27; // er15
  unsigned __int64 v28; // rdi
  char v29; // cl
  int v30; // eax
  __int64 v31; // rbx
  __int64 v32; // r15
  const char *v33; // rbx
  const char *v34; // rax
  hkDataClassImpl *v35; // rax
  hkDataObject *v36; // rax
  hkDataObjectImpl *v37; // rcx
  const char *v38; // rax
  __int64 v39; // rcx
  hkDataObject result; // [rsp+18h] [rbp-29h]
  int v41; // [rsp+24h] [rbp-1Dh]
  hkDataObject_Value v42; // [rsp+28h] [rbp-19h]
  hkTypeManager::Type *v43; // [rsp+38h] [rbp-9h]
  const void *v44; // [rsp+40h] [rbp-1h]
  hkDataArray arr; // [rsp+B0h] [rbp+6Fh]
  char array; // [rsp+B8h] [rbp+77h]
  hkDataObjectImpl *v47; // [rsp+C0h] [rbp+7Fh]

  arr.m_impl = a4;
  v4 = this;
  v5 = value->m_impl;
  v6 = minfo;
  v7 = value;
  v47 = v5;
  if ( v5 )
  {
    ++v5->m_externalCount;
    ++v5->m_count;
  }
  v8 = minfo->m_type;
  v9 = v8->m_subType;
  if ( v8->m_subType == 9 && (v8->m_parent->m_subType != 3 || (v8->m_extra.m_size - 4) & 0xFFFFFFF3) )
  {
    v10 = (hkDataArrayImpl *)v7->m_impl->vfptr[10].__vecDelDtor(
                               (hkDataRefCounted *)v7->m_impl,
                               (unsigned int)v7->m_handle);
    v11 = v10;
    arr.m_impl = v10;
    if ( v10 )
    {
      ++v10->m_externalCount;
      ++v10->m_count;
    }
    v12 = hkTypeManager::Type::getTupleSize(v8);
    `anonymous namespace'::Reader::_readArrayItems(v4, &arr, v12);
    if ( v11 )
    {
LABEL_25:
      --v11->m_externalCount;
      v25 = v11->m_count-- == 1;
      if ( v25 )
        v11->vfptr->__vecDelDtor((hkDataRefCounted *)&v11->vfptr, 1u);
      goto LABEL_47;
    }
  }
  else
  {
    if ( v9 == 8 )
    {
      (*((void (**)(void))*v4->m_parser.m_keys.m_data + 11))();
      v42 = *(hkDataObject_Value *)&v6->m_name;
      v43 = v6->m_type;
      v44 = v6->m_valuePtr;
      hkIArchive::readArrayGeneric((hkIArchive *)&v4->m_parser.m_memSizeAndFlags, &arr, 1, 1);
      v13 = 6;
      v14 = 6;
      v15 = (_QWORD)arr.m_impl & 1;
      v16 = ((unsigned int)LOBYTE(arr.m_impl) >> 1) & 0x7FFFFFBF;
      if ( SLOBYTE(arr.m_impl) < 0 )
      {
        do
        {
          hkIArchive::readArrayGeneric((hkIArchive *)&v4->m_parser.m_memSizeAndFlags, &array, 1, 1);
          v17 = v14;
          v14 += 7;
          v16 |= (array & 0x7F) << v17;
        }
        while ( array < 0 );
      }
      if ( v15 )
        v16 = -v16;
      v18 = hkDataObject_Value::getType(v7)->m_parent;
      if ( v18->m_subType == 6 && !hkTypeManager::Type::getTypeName(v18) )
      {
        hkIArchive::readArrayGeneric((hkIArchive *)&v4->m_parser.m_memSizeAndFlags, &arr, 1, 1);
        v19 = (_QWORD)arr.m_impl & 1;
        v20 = ((unsigned int)LOBYTE(arr.m_impl) >> 1) & 0x7FFFFFBF;
        if ( SLOBYTE(arr.m_impl) < 0 )
        {
          do
          {
            hkIArchive::readArrayGeneric((hkIArchive *)&v4->m_parser.m_memSizeAndFlags, &array, 1, 1);
            v21 = v13;
            v13 += 7;
            v20 |= (array & 0x7F) << v21;
          }
          while ( array < 0 );
        }
        if ( v19 )
          v20 = -v20;
        v22 = (const char *)(*(__int64 (**)(void))(**(_QWORD **)&v4->m_parser.m_keyStorage.m_data[8 * v20] + 16i64))();
        v23 = hkTypeManager::addClass((hkTypeManager *)result.m_impl, v22);
        v43 = hkTypeManager::makeArray((hkTypeManager *)result.m_impl, v23);
      }
      v24 = (hkDataArrayImpl *)(*((__int64 (__fastcall **)(const char **, hkDataObjectImpl **, const struct _hkDataObject_MemberHandle *, hkDataObject_Value *))*v4->m_parser.m_keys.m_data
                                + 5))(
                                 v4->m_parser.m_keys.m_data,
                                 &v47,
                                 v7->m_handle,
                                 &v42);
      v11 = v24;
      arr.m_impl = v24;
      if ( v24 )
      {
        ++v24->m_externalCount;
        ++v24->m_count;
      }
      v24->vfptr[4].__vecDelDtor((hkDataRefCounted *)&v24->vfptr, v16);
      `anonymous namespace'::Reader::_readArrayItems(v4, &arr, v16);
      goto LABEL_25;
    }
    switch ( v9 )
    {
      case 2:
        hkIArchive::readArrayGeneric((hkIArchive *)&v4->m_parser.m_memSizeAndFlags, &arr, 1, 1);
        ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, _QWORD))v7->m_impl->vfptr[17].__vecDelDtor)(
          v7->m_impl,
          v7->m_handle,
          LOBYTE(arr.m_impl));
        break;
      case 3:
        `anonymous namespace'::Reader::readFloat(v4);
        v7->m_impl->vfptr[20].__vecDelDtor((hkDataRefCounted *)v7->m_impl, (unsigned int)v7->m_handle);
        break;
      case 4:
        hkIArchive::readArrayGeneric((hkIArchive *)&v4->m_parser.m_memSizeAndFlags, &arr, 1, 1);
        v26 = 6;
        v27 = (_QWORD)arr.m_impl & 1;
        v28 = ((unsigned __int64)LOBYTE(arr.m_impl) >> 1) & 0x7FFFFFFFFFFFFFBFi64;
        if ( SLOBYTE(arr.m_impl) < 0 )
        {
          do
          {
            hkIArchive::readArrayGeneric((hkIArchive *)&v4->m_parser.m_memSizeAndFlags, &array, 1, 1);
            v29 = v26;
            v26 += 7;
            v28 |= (unsigned __int64)(array & 0x7F) << v29;
          }
          while ( array < 0 );
        }
        if ( v27 )
          v28 = -(signed __int64)v28;
        ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, unsigned __int64))v7->m_impl->vfptr[16].__vecDelDtor)(
          v7->m_impl,
          v7->m_handle,
          v28);
        break;
      case 5:
        v38 = `anonymous namespace'::Reader::readString(v4);
        ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, const char *))v7->m_impl->vfptr[21].__vecDelDtor)(
          v7->m_impl,
          v7->m_handle,
          v38);
        break;
      case 6:
        if ( SLODWORD(v4->m_parser.vfptr) < 2 )
          goto $LN4_199;
        v33 = *v4->m_parser.m_keys.m_data;
        v34 = hkTypeManager::Type::getTypeName(v8);
        v35 = (hkDataClassImpl *)(*((__int64 (__fastcall **)(const char **, const char *))v33 + 9))(
                                   v4->m_parser.m_keys.m_data,
                                   v34);
        v36 = `anonymous namespace'::Reader::readObjectTopLevel(v4, &result, TAG_OBJECT, v35);
        ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, hkDataObjectImpl *))v7->m_impl->vfptr[23].__vecDelDtor)(
          v7->m_impl,
          v7->m_handle,
          v36->m_impl);
        v37 = result.m_impl;
        if ( result.m_impl )
        {
          --result.m_impl->m_externalCount;
          v25 = v37->m_count-- == 1;
          if ( v25 )
            v37->vfptr->__vecDelDtor((hkDataRefCounted *)&v37->vfptr, 1u);
        }
        break;
      case 7:
$LN4_199:
        v42 = *v7;
        `anonymous namespace'::Reader::readObjectIntoValue<hkDataObject_Value>(v4, &v42);
        break;
      case 9:
        if ( v9 == 9 && v8->m_parent->m_subType == 3 && !((v8->m_extra.m_size - 4) & 0xFFFFFFF3) )
        {
          v30 = hkTypeManager::Type::getTupleSize(v8);
          v31 = 0i64;
          v32 = v30;
          if ( v30 > 0 )
          {
            do
            {
              hkIArchive::readArrayGeneric((hkIArchive *)&v4->m_parser.m_memSizeAndFlags, &arr, 4, 1);
              *(&v41 + ++v31) = (int)arr.m_impl;
            }
            while ( v31 < v32 );
          }
          ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, hkDataObject_Value *, _QWORD))v7->m_impl->vfptr[18].__vecDelDtor)(
            v7->m_impl,
            v7->m_handle,
            &v42,
            (unsigned int)v32);
        }
        break;
      default:
        break;
    }
  }
LABEL_47:
  v39 = (__int64)v47;
  if ( v47 )
  {
    --v47->m_externalCount;
    v25 = (*(_DWORD *)(v39 + 12))-- == 1;
    if ( v25 )
      (**(void (__fastcall ***)(__int64, signed __int64))v39)(v39, 1i64);
  }
}

// File Line: 624
// RVA: 0xE4D020
void __fastcall `anonymous namespace'::Reader::readObjectIntoValue<hkDataArray_Value>(Reader *this, hkDataArray_Value *value)
{
  hkDataArray_Value *v2; // r14
  Reader *v3; // rdi
  signed int v4; // esi
  int v5; // er15
  signed int v6; // ebx
  char v7; // cl
  __int64 v8; // rbx
  bool v9; // zf
  char **v10; // rsi
  int v11; // eax
  signed __int64 v12; // rdi
  _DWORD *v13; // rbx
  _QWORD **v14; // rax
  hkDataArray_Value v15; // xmm0
  hkDataArray_Value *v16; // rax
  __int64 v17; // rcx
  hkDataArray_Value v18; // [rsp+20h] [rbp-38h]
  __int64 array; // [rsp+60h] [rbp+8h]
  char v20; // [rsp+70h] [rbp+18h]

  v2 = value;
  v3 = this;
  if ( SLODWORD(this->m_parser.vfptr) < 2 )
  {
    `anonymous namespace'::Reader::readObjectTopLevel(this, (hkDataObject *)&array, 0, 0i64);
    ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))v2->m_impl->vfptr[22].__vecDelDtor)(
      v2->m_impl,
      (unsigned int)v2->m_index,
      array);
    v17 = array;
    if ( array )
    {
      --*(_WORD *)(array + 10);
      v9 = (*(_DWORD *)(v17 + 12))-- == 1;
      if ( v9 )
        (**(void (__fastcall ***)(__int64, signed __int64))v17)(v17, 1i64);
    }
  }
  else
  {
    hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 1, 1);
    v4 = 6;
    v5 = array & 1;
    v6 = ((unsigned int)(unsigned __int8)array >> 1) & 0x7FFFFFBF;
    if ( (array & 0x80u) != 0i64 )
    {
      do
      {
        hkIArchive::readArrayGeneric((hkIArchive *)&v3->m_parser.m_memSizeAndFlags, &v20, 1, 1);
        v7 = v4;
        v4 += 7;
        v6 |= (v20 & 0x7F) << v7;
      }
      while ( v20 < 0 );
    }
    if ( v5 )
      v6 = -v6;
    if ( v6 >= v3->m_parser.m_lex.m_buffer.m_bufferStart )
    {
      v10 = &v3->m_parser.m_lex.m_buffer.m_pos;
      v11 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findOrInsertKey(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_parser.m_lex.m_buffer.m_pos,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              v6,
              0i64);
      v12 = 2i64 * v11;
      v13 = *(_DWORD **)&(*v10)[16 * v11 + 8];
      if ( !v13 )
      {
        v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v13 = (_DWORD *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(v14[11], 32i64);
        if ( v13 )
        {
          v13[3] = 2147483648;
          *(_QWORD *)v13 = 0i64;
          v13[2] = 0;
          *((_QWORD *)v13 + 2) = 0i64;
          v13[6] = 0;
          v13[7] = 2147483648;
        }
        else
        {
          v13 = 0i64;
        }
        *(_QWORD *)&(*v10)[8 * v12 + 8] = v13;
      }
      v15 = *v2;
      v18 = *v2;
      if ( v13[2] == (v13[3] & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v13, 16);
        v15 = v18;
      }
      v16 = (hkDataArray_Value *)(*(_QWORD *)v13 + 16i64 * (signed int)v13[2]);
      if ( v16 )
        *v16 = v15;
      ++v13[2];
    }
    else
    {
      v8 = *(_QWORD *)(*(_QWORD *)&v3->m_parser.m_lex.m_buffer.m_memSizeAndFlags + 8i64 * v6);
      if ( v8 )
      {
        ++*(_WORD *)(v8 + 10);
        ++*(_DWORD *)(v8 + 12);
      }
      ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))v2->m_impl->vfptr[22].__vecDelDtor)(
        v2->m_impl,
        (unsigned int)v2->m_index,
        v8);
      if ( v8 )
      {
        --*(_WORD *)(v8 + 10);
        v9 = (*(_DWORD *)(v8 + 12))-- == 1;
        if ( v9 )
          (**(void (__fastcall ***)(__int64, signed __int64))v8)(v8, 1i64);
      }
    }
  }
}

// File Line: 658
// RVA: 0xE4F530
hkDataObject *__fastcall `anonymous namespace'::Reader::readObjectTopLevel(Reader *this, hkDataObject *result, hkBinaryTagfile::TagType objectTag, hkDataClassImpl *klassImpl)
{
  hkDataClassImpl *v4; // r14
  int v5; // edi
  hkDataObject *v6; // r12
  Reader *v7; // r13
  signed int v8; // esi
  signed int v9; // ebx
  int v10; // er12
  char v11; // cl
  int v12; // er14
  signed int v13; // ebx
  char v14; // cl
  hkDataObjectImpl *v15; // rdx
  int v16; // er15
  signed int v17; // ebx
  char v18; // cl
  __int64 v19; // r15
  hkDataObjectImpl *v20; // rax
  hkDataObjectImpl *v21; // rbx
  int v22; // edi
  unsigned __int64 v23; // r14
  Dummy *v24; // rax
  Dummy *v25; // r14
  Reader::ForwardReferences *v26; // rdi
  _QWORD **v27; // rax
  hkLifoAllocator *v28; // rax
  char *v29; // rcx
  unsigned __int64 v30; // rdx
  int v31; // edx
  hkLifoAllocator *v32; // rax
  char *v33; // rcx
  int v34; // edx
  char *v35; // r8
  char *v36; // rax
  int v37; // eax
  signed __int64 v38; // r8
  __int64 v39; // rdx
  char *v40; // rax
  hkLifoAllocator *v41; // rax
  hkLifoAllocator *v42; // rcx
  char *v43; // rax
  int v44; // edx
  char *v45; // r8
  int v46; // er14
  __int64 i; // rdi
  hkDataClass_MemberInfo *v48; // r8
  int v49; // eax
  char *v50; // r14
  unsigned int v51; // ecx
  signed int v52; // edi
  hkLifoAllocator *v53; // rax
  int v54; // er8
  int v55; // eax
  char *v56; // r14
  signed int v57; // edi
  hkLifoAllocator *v58; // rax
  int v59; // er8
  int v60; // eax
  char *v61; // r14
  signed int v62; // edi
  hkLifoAllocator *v63; // rax
  int v64; // er8
  bool v65; // zf
  char v67; // [rsp+20h] [rbp-E0h]
  char *v68; // [rsp+28h] [rbp-D8h]
  int v69; // [rsp+30h] [rbp-D0h]
  int v70; // [rsp+34h] [rbp-CCh]
  void *v71; // [rsp+38h] [rbp-C8h]
  int v72; // [rsp+40h] [rbp-C0h]
  char *v73; // [rsp+48h] [rbp-B8h]
  int v74; // [rsp+50h] [rbp-B0h]
  int v75; // [rsp+54h] [rbp-ACh]
  void *p; // [rsp+58h] [rbp-A8h]
  int v77; // [rsp+60h] [rbp-A0h]
  hkLocalArray<unsigned char> bout; // [rsp+68h] [rbp-98h]
  hkDataClassImpl *v79; // [rsp+88h] [rbp-78h]
  hkDataObject o[2]; // [rsp+90h] [rbp-70h]
  hkErrStream v81; // [rsp+A0h] [rbp-60h]
  char buf; // [rsp+C0h] [rbp-40h]
  hkDataObject *v83; // [rsp+308h] [rbp+208h]
  unsigned __int8 array; // [rsp+310h] [rbp+210h]

  v83 = result;
  v4 = klassImpl;
  v5 = objectTag;
  v6 = result;
  v7 = this;
  v8 = 6;
  if ( objectTag == TAG_NONE )
  {
    hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 1, 1);
    v9 = 6;
    v10 = array & 1;
    v5 = ((unsigned int)array >> 1) & 0x7FFFFFBF;
    if ( (array & 0x80u) != 0 )
    {
      do
      {
        hkIArchive::readArrayGeneric((hkIArchive *)&v7->m_parser.m_memSizeAndFlags, &v67, 1, 1);
        v11 = v9;
        v9 += 7;
        v5 |= (v67 & 0x7F) << v11;
      }
      while ( v67 < 0 );
    }
    if ( v10 )
      v5 = -v5;
    v6 = v83;
  }
  if ( v5 == 5 )
  {
    hkIArchive::readArrayGeneric((hkIArchive *)&v7->m_parser.m_memSizeAndFlags, &array, 1, 1);
    v12 = array & 1;
    v13 = ((unsigned int)array >> 1) & 0x7FFFFFBF;
    if ( (array & 0x80u) != 0 )
    {
      do
      {
        hkIArchive::readArrayGeneric((hkIArchive *)&v7->m_parser.m_memSizeAndFlags, &v67, 1, 1);
        v14 = v8;
        v8 += 7;
        v13 |= (v67 & 0x7F) << v14;
      }
      while ( v67 < 0 );
    }
    if ( v12 )
      v13 = -v13;
    v15 = *(hkDataObjectImpl **)(*(_QWORD *)&v7->m_parser.m_lex.m_buffer.m_memSizeAndFlags + 8i64 * v13);
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
    if ( !v4 )
    {
      hkIArchive::readArrayGeneric((hkIArchive *)&v7->m_parser.m_memSizeAndFlags, &array, 1, 1);
      v16 = array & 1;
      v17 = ((unsigned int)array >> 1) & 0x7FFFFFBF;
      if ( (array & 0x80u) != 0 )
      {
        do
        {
          hkIArchive::readArrayGeneric((hkIArchive *)&v7->m_parser.m_memSizeAndFlags, &v67, 1, 1);
          v18 = v8;
          v8 += 7;
          v17 |= (v67 & 0x7F) << v18;
        }
        while ( v67 < 0 );
      }
      if ( v16 )
        v17 = -v17;
      v4 = *(hkDataClassImpl **)&v7->m_parser.m_keyStorage.m_data[8 * v17];
    }
    v79 = v4;
    v19 = ((signed int (__fastcall *)(hkDataClassImpl *))v4->vfptr[9].__vecDelDtor)(v4);
    v20 = (hkDataObjectImpl *)(*((__int64 (__fastcall **)(const char **, hkDataClassImpl **, _QWORD))*v7->m_parser.m_keys.m_data
                               + 4))(
                                v7->m_parser.m_keys.m_data,
                                &v79,
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
        v23 = v7->m_parser.m_lex.m_buffer.m_bufferStart;
        if ( v7->m_parser.m_lex.m_buffer.m_bufferStart == (v7->m_parser.m_lex.m_buffer.m_lexemeStart & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v7->m_parser.m_lex.m_buffer.m_memSizeAndFlags,
            8);
        *(_QWORD *)(*(_QWORD *)&v7->m_parser.m_lex.m_buffer.m_memSizeAndFlags
                  + 8i64 * v7->m_parser.m_lex.m_buffer.m_bufferStart++) = v21;
        v24 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v7->m_parser.m_lex.m_buffer.m_pos,
                v23);
        v25 = v24;
        if ( (signed int)v24 <= SHIDWORD(v7->m_parser.m_lex.m_buffer.m_buffer.m_data) )
        {
          v26 = *(Reader::ForwardReferences **)&v7->m_parser.m_lex.m_buffer.m_pos[16 * (signed int)v24 + 8];
          `anonymous namespace'::Reader::ForwardReferences::assign(
            *(Reader::ForwardReferences **)&v7->m_parser.m_lex.m_buffer.m_pos[16 * (signed int)v24 + 8],
            o);
          if ( v26 )
          {
            `anonymous namespace'::Reader::ForwardReferences::~ForwardReferences(v26);
            v27 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            (*(void (__fastcall **)(_QWORD *, Reader::ForwardReferences *, signed __int64))(*v27[11] + 16i64))(
              v27[11],
              v26,
              32i64);
          }
          hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v7->m_parser.m_lex.m_buffer.m_pos,
            v25);
        }
      }
      else
      {
        hkErrStream::hkErrStream(&v81, &buf, 512);
        hkOstream::operator<<((hkOstream *)&v81.vfptr, "corrupt file");
        if ( (unsigned int)hkError::messageError(1212781781, &buf, "Tagfile\\Binary\\hkBinaryTagfileReader.cpp", 701) )
          __debugbreak();
        hkOstream::~hkOstream((hkOstream *)&v81.vfptr);
      }
    }
    bout.m_capacityAndFlags = 2147483648;
    bout.m_data = 0i64;
    bout.m_size = 0;
    bout.m_initialCapacity = 128;
    v28 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v29 = (char *)v28->m_cur;
    v30 = (unsigned __int64)(v29 + 128);
    if ( v28->m_slabSize < 128 || (void *)v30 > v28->m_end )
      v29 = (char *)hkLifoAllocator::allocateFromNewSlab(v28, 128);
    else
      v28->m_cur = (void *)v30;
    bout.m_data = v29;
    bout.m_localMemory = v29;
    bout.m_capacityAndFlags = -2147483520;
    `anonymous namespace'::Reader::readBitfield(v7, v19, &bout);
    v31 = 0;
    v68 = 0i64;
    v69 = 0;
    v70 = 2147483648;
    v72 = v19;
    if ( (_DWORD)v19 )
    {
      v32 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v33 = (char *)v32->m_cur;
      v34 = (32 * v19 + 127) & 0xFFFFFF80;
      v35 = &v33[v34];
      if ( v34 > v32->m_slabSize || v35 > v32->m_end )
      {
        v36 = (char *)hkLifoAllocator::allocateFromNewSlab(v32, v34);
        v31 = v69;
        v33 = v36;
      }
      else
      {
        v32->m_cur = v35;
        v31 = v69;
      }
    }
    else
    {
      v33 = 0i64;
    }
    v37 = v19 - v31;
    v38 = 32i64 * v31 + 16;
    v68 = v33;
    v71 = v33;
    v70 = v19 | 0x80000000;
    v39 = (signed int)v19 - v31;
    if ( v37 > 0 )
    {
      v40 = &v33[v38];
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
    v69 = v19;
    ((void (__fastcall *)(hkDataClassImpl *, char **, signed __int64))v79->vfptr[12].__vecDelDtor)(v79, &v68, v38);
    v73 = 0i64;
    v74 = 0;
    v75 = 2147483648;
    v77 = v19;
    if ( (_DWORD)v19 )
    {
      v41 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v42 = v41;
      v43 = (char *)v41->m_cur;
      v44 = (8 * v19 + 127) & 0xFFFFFF80;
      v45 = &v43[v44];
      if ( v44 > v42->m_slabSize || v45 > v42->m_end )
        v43 = (char *)hkLifoAllocator::allocateFromNewSlab(v42, v44);
      else
        v42->m_cur = v45;
    }
    else
    {
      v43 = 0i64;
    }
    v73 = v43;
    v75 = v19 | 0x80000000;
    p = v43;
    v74 = v19;
    v21->vfptr[29].__vecDelDtor((hkDataRefCounted *)&v21->vfptr, (unsigned int)&v73);
    v46 = 0;
    for ( i = 0i64; i < v19; ++v46 )
    {
      if ( bout.m_data[i] )
      {
        o[0].m_impl = v21;
        v48 = (hkDataClass_MemberInfo *)&v68[32 * v46];
        o[1] = *(hkDataObject *)&v73[8 * i];
        _mm_store_si128((__m128i *)&v81, *(__m128i *)&o[0].m_impl);
        `anonymous namespace'::Reader::readBinaryValue(v7, (hkDataObject_Value *)&v81, v48, (hkDataArrayImpl *)v21);
      }
      ++i;
    }
    ++v21->m_externalCount;
    ++v21->m_count;
    v49 = v74;
    v50 = (char *)p;
    v51 = hkMemoryRouter::s_memoryRouter.m_slotID;
    v6->m_impl = v21;
    if ( v50 == v73 )
      v49 = 0;
    v74 = v49;
    v52 = (8 * v77 + 127) & 0xFFFFFF80;
    v53 = (hkLifoAllocator *)TlsGetValue(v51);
    v54 = (v52 + 15) & 0xFFFFFFF0;
    if ( v52 > v53->m_slabSize || &v50[v54] != v53->m_cur || v53->m_firstNonLifoEnd == v50 )
      hkLifoAllocator::slowBlockFree(v53, v50, v54);
    else
      v53->m_cur = v50;
    v74 = 0;
    if ( v75 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v73,
        8 * v75);
    v55 = v69;
    v56 = (char *)v71;
    v73 = 0i64;
    if ( v71 == v68 )
      v55 = 0;
    v75 = 2147483648;
    v69 = v55;
    v57 = (32 * v72 + 127) & 0xFFFFFF80;
    v58 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v59 = (v57 + 15) & 0xFFFFFFF0;
    if ( v57 > v58->m_slabSize || &v56[v59] != v58->m_cur || v58->m_firstNonLifoEnd == v56 )
      hkLifoAllocator::slowBlockFree(v58, v56, v59);
    else
      v58->m_cur = v56;
    v69 = 0;
    if ( v70 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v68,
        32 * v70);
    v60 = bout.m_size;
    v61 = bout.m_localMemory;
    v68 = 0i64;
    if ( bout.m_localMemory == bout.m_data )
      v60 = 0;
    v70 = 2147483648;
    v62 = (bout.m_initialCapacity + 127) & 0xFFFFFF80;
    bout.m_size = v60;
    v63 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v64 = (v62 + 15) & 0xFFFFFFF0;
    if ( v62 > v63->m_slabSize || &v61[v64] != v63->m_cur || v63->m_firstNonLifoEnd == v61 )
      hkLifoAllocator::slowBlockFree(v63, v61, v64);
    else
      v63->m_cur = v61;
    bout.m_size = 0;
    if ( bout.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        bout.m_data,
        bout.m_capacityAndFlags & 0x3FFFFFFF);
    bout.m_data = 0i64;
    bout.m_capacityAndFlags = 2147483648;
    --v21->m_externalCount;
    v65 = v21->m_count-- == 1;
    if ( v65 )
      v21->vfptr->__vecDelDtor((hkDataRefCounted *)&v21->vfptr, 1u);
  }
  return v6;
}

// File Line: 734
// RVA: 0xE4ED90
hkResult *__fastcall `anonymous namespace'::Reader::readClass(Reader *this, hkResult *result)
{
  int v2; // er15
  hkResult *v3; // r12
  Reader *v4; // r13
  signed int v5; // edi
  int v6; // esi
  unsigned int v7; // ebx
  char v8; // cl
  const char **v9; // rcx
  signed int v10; // edi
  int v11; // esi
  signed int v12; // ebx
  char v13; // cl
  __int64 v14; // rcx
  signed int v15; // edi
  int v16; // esi
  int v17; // ebx
  char v18; // cl
  int v19; // er9
  __int64 v20; // r12
  char *v21; // rbx
  signed int v22; // ebx
  int v23; // esi
  signed int v24; // edi
  char v25; // cl
  signed int v26; // esi
  int v27; // er15
  int v28; // ebx
  char v29; // cl
  const char *v30; // rsi
  const char *v31; // rax
  hkTypeManager *v32; // rax
  hkTypeManager::Type *v33; // rax
  __int64 v34; // rdi
  __int64 v35; // rcx
  char *v36; // rax
  char v38; // [rsp+30h] [rbp-48h]
  int v39; // [rsp+34h] [rbp-44h]
  char *v40; // [rsp+38h] [rbp-40h]
  const char *v41; // [rsp+40h] [rbp-38h]
  unsigned int v42; // [rsp+48h] [rbp-30h]
  __int64 v43; // [rsp+50h] [rbp-28h]
  char *v44; // [rsp+58h] [rbp-20h]
  int v45; // [rsp+60h] [rbp-18h]
  int v46; // [rsp+64h] [rbp-14h]
  unsigned __int8 array; // [rsp+C0h] [rbp+48h]
  hkResult *v48; // [rsp+C8h] [rbp+50h]
  char v49; // [rsp+D0h] [rbp+58h]
  hkResult resulta; // [rsp+D8h] [rbp+60h]

  v48 = result;
  v2 = 0;
  v3 = result;
  v4 = this;
  v44 = 0i64;
  v45 = 0;
  v46 = 2147483648;
  v41 = `anonymous namespace'::Reader::readString(this);
  hkIArchive::readArrayGeneric((hkIArchive *)&v4->m_parser.m_memSizeAndFlags, &array, 1, 1);
  v5 = 6;
  v6 = array & 1;
  v7 = ((unsigned int)array >> 1) & 0x7FFFFFBF;
  if ( (array & 0x80u) != 0 )
  {
    do
    {
      hkIArchive::readArrayGeneric((hkIArchive *)&v4->m_parser.m_memSizeAndFlags, &v49, 1, 1);
      v8 = v5;
      v5 += 7;
      v7 |= (v49 & 0x7F) << v8;
    }
    while ( v49 < 0 );
  }
  if ( v6 )
    v7 = -v7;
  v9 = v4->m_parser.m_keys.m_data;
  v42 = v7;
  if ( *(_DWORD *)(*((__int64 (__fastcall **)(const char **, unsigned __int8 *))*v9 + 6))(v9, &array) )
  {
    hkIArchive::readArrayGeneric((hkIArchive *)&v4->m_parser.m_memSizeAndFlags, &array, 1, 1);
    v10 = 6;
    v11 = array & 1;
    v12 = ((unsigned int)array >> 1) & 0x7FFFFFBF;
    if ( (array & 0x80u) != 0 )
    {
      do
      {
        hkIArchive::readArrayGeneric((hkIArchive *)&v4->m_parser.m_memSizeAndFlags, &v49, 1, 1);
        v13 = v10;
        v10 += 7;
        v12 |= (v49 & 0x7F) << v13;
      }
      while ( v49 < 0 );
    }
    if ( v11 )
      v12 = -v12;
    if ( v12 >= 0 && (v14 = *(_QWORD *)&v4->m_parser.m_keyStorage.m_data[8 * v12]) != 0 )
      v43 = (*(__int64 (**)(void))(*(_QWORD *)v14 + 16i64))();
    else
      v43 = 0i64;
    hkIArchive::readArrayGeneric((hkIArchive *)&v4->m_parser.m_memSizeAndFlags, &array, 1, 1);
    v15 = 6;
    v16 = array & 1;
    v17 = ((unsigned int)array >> 1) & 0x7FFFFFBF;
    if ( (array & 0x80u) != 0 )
    {
      do
      {
        hkIArchive::readArrayGeneric((hkIArchive *)&v4->m_parser.m_memSizeAndFlags, &v49, 1, 1);
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
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v44, v19, 24);
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
        *(_QWORD *)v21 = `anonymous namespace'::Reader::readString(v4);
        hkIArchive::readArrayGeneric((hkIArchive *)&v4->m_parser.m_memSizeAndFlags, &array, 1, 1);
        v22 = 6;
        v23 = array & 1;
        v24 = ((unsigned int)array >> 1) & 0x7FFFFFBF;
        if ( (array & 0x80u) != 0 )
        {
          do
          {
            hkIArchive::readArrayGeneric((hkIArchive *)&v4->m_parser.m_memSizeAndFlags, &v49, 1, 1);
            v25 = v22;
            v22 += 7;
            v24 |= (v49 & 0x7F) << v25;
          }
          while ( v49 < 0 );
        }
        if ( v23 )
          v24 = -v24;
        if ( v24 & 0x20 )
        {
          hkIArchive::readArrayGeneric((hkIArchive *)&v4->m_parser.m_memSizeAndFlags, &resulta, 1, 1);
          v26 = 6;
          v27 = resulta.m_enum & 1;
          v28 = ((unsigned int)LOBYTE(resulta.m_enum) >> 1) & 0x7FFFFFBF;
          if ( SLOBYTE(resulta.m_enum) < 0 )
          {
            do
            {
              hkIArchive::readArrayGeneric((hkIArchive *)&v4->m_parser.m_memSizeAndFlags, &v38, 1, 1);
              v29 = v26;
              v26 += 7;
              v28 |= (v38 & 0x7F) << v29;
            }
            while ( v38 < 0 );
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
          v31 = `anonymous namespace'::Reader::readString(v4);
          v30 = v31;
          if ( v31 )
            (*((void (__fastcall **)(const char **, const char *))*v4->m_parser.m_keys.m_data + 9))(
              v4->m_parser.m_keys.m_data,
              v31);
        }
        else
        {
          v30 = 0i64;
        }
        v32 = (hkTypeManager *)(*((__int64 (**)(void))*v4->m_parser.m_keys.m_data + 11))();
        v33 = hkTypeManager::getType(v32, (hkLegacyType::Type)v24, v30, v28);
        ++v2;
        v20 += 24i64;
        *((_QWORD *)v40 + 1) = v33;
        v39 = v2;
      }
      while ( v2 < v45 );
      v3 = v48;
    }
    v34 = (*((__int64 (__fastcall **)(const char **, const char **))*v4->m_parser.m_keys.m_data + 3))(
            v4->m_parser.m_keys.m_data,
            &v41);
    if ( v4->m_parser.m_keyStorage.m_size == (v4->m_parser.m_keyStorage.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v4->m_parser.m_keyStorage,
        8);
    v35 = v4->m_parser.m_keyStorage.m_size;
    v36 = v4->m_parser.m_keyStorage.m_data;
    v3->m_enum = 0;
    *(_QWORD *)&v36[8 * v35] = v34;
    ++v4->m_parser.m_keyStorage.m_size;
    v45 = 0;
  }
  else
  {
    v3->m_enum = 1;
    v45 = 0;
  }
  if ( v46 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v44,
      24 * (v46 & 0x3FFFFFFF));
  return v3;
}

// File Line: 782
// RVA: 0xE4FC70
hkDataObject *__fastcall `anonymous namespace'::Reader::readObjectTree(Reader *this, hkDataObject *result)
{
  hkDataObject *v2; // r14
  Reader *v3; // r13
  signed int v4; // esi
  int v5; // er15
  unsigned int v6; // ebx
  char v7; // cl
  signed int v8; // esi
  int v9; // er15
  unsigned int v10; // ebx
  char v11; // cl
  signed int v12; // esi
  int v13; // er15
  unsigned int v14; // ebx
  char v15; // cl
  hkDataObjectImpl *v16; // rcx
  bool v17; // zf
  signed int v18; // esi
  int v19; // er15
  char v20; // cl
  hkOstream *v21; // rax
  int v23; // eax
  hkDataObjectImpl *v24; // rcx
  unsigned __int8 v25; // [rsp+20h] [rbp-E0h]
  char v26; // [rsp+21h] [rbp-DFh]
  char v27; // [rsp+22h] [rbp-DEh]
  hkDataObject v28; // [rsp+28h] [rbp-D8h]
  hkResult resulta; // [rsp+30h] [rbp-D0h]
  hkErrStream v30; // [rsp+38h] [rbp-C8h]
  char buf; // [rsp+50h] [rbp-B0h]
  int array; // [rsp+290h] [rbp+190h]
  int v33; // [rsp+2A0h] [rbp+1A0h]
  unsigned __int8 v34; // [rsp+2A8h] [rbp+1A8h]

  v2 = result;
  v3 = this;
  hkIArchive::readArrayGeneric((hkIArchive *)&this->m_parser.m_memSizeAndFlags, &array, 4, 1);
  hkIArchive::readArrayGeneric((hkIArchive *)&v3->m_parser.m_memSizeAndFlags, &v33, 4, 1);
  if ( array != -894431970 || v33 != -804128050 )
  {
    hkErrStream::hkErrStream(&v30, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v30.vfptr, "This does not look like a binary tagfile (magic number mismatch)");
    hkError::messageWarning(716571503, &buf, "Tagfile\\Binary\\hkBinaryTagfileReader.cpp", 791);
    hkOstream::~hkOstream((hkOstream *)&v30.vfptr);
    v2->m_impl = 0i64;
    return v2;
  }
  hkIArchive::readArrayGeneric((hkIArchive *)&v3->m_parser.m_memSizeAndFlags, &array, 1, 1);
  v4 = 6;
  v5 = array & 1;
  v6 = ((unsigned int)(unsigned __int8)array >> 1) & 0x7FFFFFBF;
  if ( (array & 0x80u) != 0 )
  {
    do
    {
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->m_parser.m_memSizeAndFlags, &v33, 1, 1);
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
      case 1u:
        hkIArchive::readArrayGeneric((hkIArchive *)&v3->m_parser.m_memSizeAndFlags, &array, 1, 1);
        v8 = 6;
        v9 = array & 1;
        v10 = ((unsigned int)(unsigned __int8)array >> 1) & 0x7FFFFFBF;
        if ( (array & 0x80u) != 0 )
        {
          do
          {
            hkIArchive::readArrayGeneric((hkIArchive *)&v3->m_parser.m_memSizeAndFlags, &v33, 1, 1);
            v11 = v8;
            v8 += 7;
            v10 |= (v33 & 0x7F) << v11;
          }
          while ( (v33 & 0x80u) != 0 );
        }
        if ( v9 )
          v10 = -v10;
        LODWORD(v3->m_parser.vfptr) = v10;
        if ( !v10 )
          goto LABEL_36;
        if ( v10 == 1 )
        {
          hkIArchive::readArrayGeneric((hkIArchive *)&v3->m_parser.m_memSizeAndFlags, &v34, 1, 1);
          v12 = 6;
          v13 = v34 & 1;
          v14 = ((unsigned int)v34 >> 1) & 0x7FFFFFBF;
          if ( (v34 & 0x80u) != 0 )
          {
            do
            {
              hkIArchive::readArrayGeneric((hkIArchive *)&v3->m_parser.m_memSizeAndFlags, &v27, 1, 1);
              v15 = v12;
              v12 += 7;
              v14 |= (v27 & 0x7F) << v15;
            }
            while ( v27 < 0 );
          }
          if ( v13 )
            v14 = -v14;
          if ( v14 != 1 )
            goto LABEL_41;
          *(_DWORD *)&v3->m_parser.m_lex.m_memSizeAndFlags = 0;
          if ( 0 == (*(_DWORD *)(&v3->m_parser.m_lex.m_referenceCount + 1) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v3->m_parser.m_lex,
              8);
          *((_QWORD *)&v3->m_parser.m_lex.vfptr->__vecDelDtor
          + (signed int)(*(_DWORD *)&v3->m_parser.m_lex.m_memSizeAndFlags)++) = &customWorldMapCaption;
          if ( *(_DWORD *)&v3->m_parser.m_lex.m_memSizeAndFlags == (*(_DWORD *)(&v3->m_parser.m_lex.m_referenceCount + 1) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v3->m_parser.m_lex,
              8);
          *((_QWORD *)&v3->m_parser.m_lex.vfptr->__vecDelDtor
          + (signed int)(*(_DWORD *)&v3->m_parser.m_lex.m_memSizeAndFlags)++) = 0i64;
          hkArrayBase<unsigned __int64>::_append(
            (hkArrayBase<char *> *)&v3->m_parser.m_lex,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            (char *const *)HK_TAG_STRING_LIST,
            1752);
          LODWORD(v3->m_parser.m_lex.m_buffer.vfptr) = 1754;
LABEL_36:
          hkIArchive::readArrayGeneric((hkIArchive *)&v3->m_parser.m_memSizeAndFlags, &v25, 1, 1);
          v18 = 6;
          v19 = v25 & 1;
          v6 = ((unsigned int)v25 >> 1) & 0x7FFFFFBF;
          if ( (v25 & 0x80u) != 0 )
          {
            do
            {
              hkIArchive::readArrayGeneric((hkIArchive *)&v3->m_parser.m_memSizeAndFlags, &v26, 1, 1);
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
        if ( v10 - 2 <= 2 )
        {
          if ( v3->m_parser.m_lex.m_buffer.m_bufferStart == (v3->m_parser.m_lex.m_buffer.m_lexemeStart & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v3->m_parser.m_lex.m_buffer.m_memSizeAndFlags,
              8);
          *(_QWORD *)(*(_QWORD *)&v3->m_parser.m_lex.m_buffer.m_memSizeAndFlags
                    + 8i64 * v3->m_parser.m_lex.m_buffer.m_bufferStart++) = 0i64;
          if ( LODWORD(v3->m_parser.vfptr) == 4 )
            `anonymous namespace'::Reader::readString(v3);
          goto LABEL_36;
        }
        hkErrStream::hkErrStream(&v30, &buf, 512);
        v21 = hkOstream::operator<<((hkOstream *)&v30.vfptr, "Unrecognised tagfile version ");
        hkOstream::operator<<(v21, (int)v3->m_parser.vfptr, (int)v21);
        hkError::messageWarning(716571503, &buf, "Tagfile\\Binary\\hkBinaryTagfileReader.cpp", 843);
        hkOstream::~hkOstream((hkOstream *)&v30.vfptr);
LABEL_41:
        v2->m_impl = 0i64;
        return v2;
      case 2u:
        if ( `anonymous namespace'::Reader::readClass(v3, &resulta)->m_enum == 1 )
          goto LABEL_41;
        goto LABEL_36;
      case 3u:
      case 4u:
      case 6u:
        `anonymous namespace'::Reader::readObjectTopLevel(v3, &v28, (hkBinaryTagfile::TagType)v6, 0i64);
        v16 = v28.m_impl;
        if ( SLODWORD(v3->m_parser.vfptr) < 2 )
        {
          v2->m_impl = v28.m_impl;
          if ( v16 )
          {
            v23 = v16->m_count;
            v16->m_count = v23;
            if ( !v23 )
              v16->vfptr->__vecDelDtor((hkDataRefCounted *)&v16->vfptr, 1u);
          }
          return v2;
        }
        if ( v28.m_impl )
        {
          --v28.m_impl->m_externalCount;
          v17 = v16->m_count-- == 1;
          if ( v17 )
            v16->vfptr->__vecDelDtor((hkDataRefCounted *)&v16->vfptr, 1u);
        }
        goto LABEL_36;
      case 7u:
        v24 = *(hkDataObjectImpl **)(*(_QWORD *)&v3->m_parser.m_lex.m_buffer.m_memSizeAndFlags + 8i64);
        v2->m_impl = v24;
        if ( v24 )
        {
          ++v24->m_externalCount;
          ++v24->m_count;
        }
        return v2;
      default:
        goto LABEL_41;
    }
  }
}

// File Line: 912
// RVA: 0xE4E480
void __fastcall `anonymous namespace'::Reader::ForwardReferences::assign(Reader::ForwardReferences *this, hkDataObject *o)
{
  int v2; // edi
  hkDataObject *v3; // r14
  Reader::ForwardReferences *v4; // rbx
  int v5; // ebp
  __int64 v6; // rsi
  __int64 v7; // rsi

  v2 = 0;
  v3 = o;
  v4 = this;
  v5 = 0;
  if ( this->m_arrayRefs.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, hkDataObjectImpl *))v4->m_arrayRefs.m_data[v6].m_impl->vfptr[22].__vecDelDtor)(
        v4->m_arrayRefs.m_data[v6].m_impl,
        (unsigned int)v4->m_arrayRefs.m_data[v6].m_index,
        v3->m_impl);
      ++v5;
      ++v6;
    }
    while ( v5 < v4->m_arrayRefs.m_size );
  }
  if ( v4->m_objectRefs.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, hkDataObjectImpl *))v4->m_objectRefs.m_data[v7].m_impl->vfptr[23].__vecDelDtor)(
        v4->m_objectRefs.m_data[v7].m_impl,
        v4->m_objectRefs.m_data[v7].m_handle,
        v3->m_impl);
      ++v2;
      ++v7;
    }
    while ( v2 < v4->m_objectRefs.m_size );
  }
}

// File Line: 933
// RVA: 0xE4CF50
void __fastcall hkBinaryTagfileReader::hkBinaryTagfileReader(hkBinaryTagfileReader *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkBinaryTagfileReader::`vftable';
}

// File Line: 937
// RVA: 0xE4CF70
hkDataObject *__fastcall hkBinaryTagfileReader::load(hkBinaryTagfileReader *this, hkDataObject *result, hkStreamReader *stream, hkDataWorld *cont)
{
  hkDataObject *v4; // rbx
  char v6; // [rsp+20h] [rbp-88h]

  v4 = result;
  `anonymous namespace'::Reader::Reader((Reader *)&v6, stream, cont);
  `anonymous namespace'::Reader::readObjectTree((Reader *)&v6, v4);
  `anonymous namespace'::Reader::~Reader((Reader *)&v6);
  return v4;
}

// File Line: 943
// RVA: 0xE4CFC0
hkResult *__fastcall hkBinaryTagfileReader::readHeader(hkBinaryTagfileReader *this, hkResult *result, hkStreamReader *stream, hkBinaryTagfile::Header *out)
{
  hkResult *v4; // rdi
  hkBinaryTagfile::Header *v5; // rbx
  char v7; // [rsp+20h] [rbp-88h]

  v4 = result;
  v5 = out;
  `anonymous namespace'::Reader::Reader((Reader *)&v7, stream, 0i64);
  `anonymous namespace'::Reader::readHeader((Reader *)&v7, v4, v5);
  `anonymous namespace'::Reader::~Reader((Reader *)&v7);
  return v4;
}

