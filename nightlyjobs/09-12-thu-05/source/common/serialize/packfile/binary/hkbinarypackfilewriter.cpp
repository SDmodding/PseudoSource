// File Line: 82
// RVA: 0xE4CC30
unsigned __int64 __fastcall `anonymous namespace'::getArraySizeInBytes<hkPackfileSectionHeader>(hkArray<hkPackfileSectionHeader,hkContainerHeapAllocator> *a)
{
  return (unsigned __int64)(unsigned int)a->m_size << 6;
}

// File Line: 112
// RVA: 0xE4C9E0
__int64 __fastcall padUp(hkStreamWriter *w, int pad, char padData)
{
  char v3; // r15
  int v4; // esi
  hkStreamWriter *v5; // r14
  unsigned int v6; // ebx
  int v7; // eax
  int v8; // edi
  char *v9; // rdx
  int v10; // ebp
  int v11; // er9
  int v12; // eax
  char *v13; // rdi
  int v14; // eax
  char *array; // [rsp+30h] [rbp-48h]
  int v17; // [rsp+38h] [rbp-40h]
  int v18; // [rsp+3Ch] [rbp-3Ch]
  char v19; // [rsp+40h] [rbp-38h]
  hkResult result; // [rsp+90h] [rbp+18h]

  v3 = padData;
  v4 = pad;
  v5 = w;
  v6 = 0;
  v7 = ((__int64 (*)(void))w->vfptr[4].__vecDelDtor)();
  v8 = 0;
  v9 = &v19;
  v18 = -2147483616;
  v10 = v7;
  array = &v19;
  v17 = 0;
  if ( v4 > 32 )
  {
    v11 = v4;
    if ( v4 < 64 )
      v11 = 64;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v11, 1);
    v8 = v17;
    v9 = array;
  }
  v12 = v4 - v8;
  v13 = &v9[v8];
  if ( v12 > 0 )
  {
    memset(v13, v3, v12);
    v9 = array;
  }
  v17 = v4;
  v14 = v10 & (v4 - 1);
  if ( v10 & (v4 - 1) )
  {
    v6 = v4 - v14;
    ((void (__fastcall *)(hkStreamWriter *, char *, _QWORD))v5->vfptr[2].__vecDelDtor)(v5, v9, (unsigned int)(v4 - v14));
    v9 = array;
  }
  v17 = 0;
  if ( v18 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v9,
      v18 & 0x3FFFFFFF);
  return v6;
}

// File Line: 127
// RVA: 0xE4B780
void __fastcall hkBinaryPackfileWriter::hkBinaryPackfileWriter(hkBinaryPackfileWriter *this, hkPackfileWriter::Options *options)
{
  hkBinaryPackfileWriter *v2; // rbx

  v2 = this;
  hkPackfileWriter::hkPackfileWriter((hkPackfileWriter *)&this->vfptr, options);
  v2->vfptr = (hkBaseObjectVtbl *)&hkBinaryPackfileWriter::`vftable';
  hkPackfileWriter::addSection((hkPackfileWriter *)&v2->vfptr, hkBinaryPackfileWriter::SECTION_TAG_CLASSNAMES);
  hkPackfileWriter::setSectionForClass(
    (hkPackfileWriter *)&v2->vfptr,
    &hkClassClass,
    hkPackfileWriter::SECTION_TAG_TYPES);
  hkPackfileWriter::setSectionForClass(
    (hkPackfileWriter *)&v2->vfptr,
    &hkClassMemberClass,
    hkPackfileWriter::SECTION_TAG_TYPES);
  hkPackfileWriter::setSectionForClass(
    (hkPackfileWriter *)&v2->vfptr,
    &hkClassEnumClass,
    hkPackfileWriter::SECTION_TAG_TYPES);
  hkPackfileWriter::setSectionForClass(
    (hkPackfileWriter *)&v2->vfptr,
    &hkClassEnumItemClass,
    hkPackfileWriter::SECTION_TAG_TYPES);
}

// File Line: 137
// RVA: 0xE4B810
void __fastcall hkBinaryPackfileWriter::~hkBinaryPackfileWriter(hkBinaryPackfileWriter *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkBinaryPackfileWriter::`vftable';
  hkPackfileWriter::~hkPackfileWriter((hkPackfileWriter *)&this->vfptr);
}

// File Line: 141
// RVA: 0xE4BAD0
void __fastcall hkBinaryPackfileWriter::fillSectionTags(hkBinaryPackfileWriter *this, hkBinaryPackfileWriter::SaveContext *context)
{
  hkArray<hkPackfileSectionHeader,hkContainerHeapAllocator> *v2; // rsi
  int v3; // er14
  int v4; // eax
  hkBinaryPackfileWriter *v5; // rbp
  int v6; // eax
  int v7; // er9
  __int64 v8; // rax
  hkPackfileSectionHeader *v9; // rbx
  __int64 v10; // rdi
  int v11; // eax
  int v12; // ebx
  __int64 v13; // rdi
  hkResult result; // [rsp+50h] [rbp+8h]

  v2 = &context->m_sectionHeaders;
  v3 = this->m_knownSections.m_size;
  v4 = context->m_sectionHeaders.m_capacityAndFlags & 0x3FFFFFFF;
  v5 = this;
  if ( v4 < v3 )
  {
    v6 = 2 * v4;
    v7 = this->m_knownSections.m_size;
    if ( v3 < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, v7, 64);
  }
  v8 = v2->m_size;
  v9 = &v2->m_data[v8];
  if ( v3 - (signed int)v8 > 0 )
  {
    v10 = (unsigned int)(v3 - v8);
    do
    {
      if ( v9 )
        hkString::memSet(v9, 0, 8);
      ++v9;
      --v10;
    }
    while ( v10 );
  }
  v2->m_size = v3;
  v11 = `anonymous namespace'::getArraySizeInBytes<hkPackfileSectionHeader>(v2);
  hkString::memSet(v2->m_data, -1, v11);
  v12 = 0;
  if ( v5->m_knownSections.m_size > 0 )
  {
    v13 = 0i64;
    do
    {
      hkString::strNcpy(v2->m_data[(signed __int64)v12++].m_sectionTag, v5->m_knownSections.m_data[v13], 19);
      ++v13;
    }
    while ( v12 < v5->m_knownSections.m_size );
  }
}

// File Line: 153
// RVA: 0xE4CAF0
void __fastcall saveFileHeader(hkPlatformObjectWriter *writer, hkStreamWriter *stream, hkPackfileWriter::Options *options, int numSections)
{
  hkPlatformObjectWriter *v4; // rsi
  hkPackfileWriter::Options *v5; // rdi
  hkStreamWriter *v6; // r14
  int v7; // ebx
  int v8; // eax
  const char *v9; // rdx
  hkBaseObjectVtbl *v10; // rax
  int dst; // [rsp+30h] [rbp-49h]
  int v12; // [rsp+34h] [rbp-45h]
  int v13; // [rsp+38h] [rbp-41h]
  int v14; // [rsp+3Ch] [rbp-3Dh]
  char v15; // [rsp+40h] [rbp-39h]
  int v16; // [rsp+44h] [rbp-35h]
  char buf; // [rsp+58h] [rbp-21h]
  __int64 v18; // [rsp+68h] [rbp-11h]
  hkRelocationInfo v19; // [rsp+70h] [rbp-9h]
  char v20; // [rsp+F8h] [rbp+7Fh]

  v4 = writer;
  v5 = options;
  v6 = stream;
  v7 = numSections;
  hkString::memSet(&dst, -1, 64);
  v8 = v5->m_userTag;
  dst = 1474355287;
  v12 = 281067536;
  buf = 0;
  v18 = 0i64;
  v13 = v8;
  v14 = 11;
  hkString::memCpy(&v15, &v5->m_layout, 4);
  v16 = v7;
  hkString::memSet((char *)&v18 + 4, -1, 4);
  v9 = v5->m_contentsVersion;
  if ( v9 )
    hkString::strNcpy(&buf, v9, 16);
  else
    hkPackfileWriter::getCurrentVersion(&buf, 16);
  v10 = v4->vfptr;
  v19.m_local.m_data = 0i64;
  v19.m_local.m_size = 0;
  v19.m_local.m_capacityAndFlags = 2147483648;
  v19.m_global.m_data = 0i64;
  v19.m_global.m_size = 0;
  v19.m_global.m_capacityAndFlags = 2147483648;
  v19.m_finish.m_data = 0i64;
  v19.m_finish.m_size = 0;
  v19.m_finish.m_capacityAndFlags = 2147483648;
  v19.m_imports.m_data = 0i64;
  v19.m_imports.m_size = 0;
  v19.m_imports.m_capacityAndFlags = 2147483648;
  v19.m_pool = 0i64;
  ((void (__fastcall *)(hkPlatformObjectWriter *, char *, hkStreamWriter *, int *, hkClass *, hkRelocationInfo *))v10[1].__first_virtual_table_function__)(
    v4,
    &v20,
    v6,
    &dst,
    &hkPackfileHeaderClass,
    &v19);
  hkRelocationInfo::~hkRelocationInfo(&v19);
}

// File Line: 173
// RVA: 0xE4BA00
void __fastcall hkBinaryPackfileWriter::writeClassName(hkBinaryPackfileWriter *this, hkBinaryPackfileWriter::SaveContext *context, hkClass *k, int absoluteDataStart)
{
  hkBinaryPackfileWriter::SaveContext *v4; // rsi
  int v5; // ebp
  hkClass *v6; // rbx
  unsigned int v7; // eax
  hkStreamWriter *v8; // rcx
  const char *v9; // rdi
  int v10; // eax
  hkBaseObjectVtbl *v11; // rbx
  int v12; // eax
  unsigned int v13; // [rsp+20h] [rbp-28h]
  char v14; // [rsp+24h] [rbp-24h]
  unsigned int v15; // [rsp+68h] [rbp+20h]

  v4 = context;
  v5 = absoluteDataStart;
  v6 = k;
  v7 = hkClass::getSignature(k, 0);
  if ( v4->m_endianSwapRequired.m_bool )
  {
    v15 = v7;
    HIBYTE(v15) = v7;
    LOBYTE(v15) = HIBYTE(v7);
    BYTE2(v15) = BYTE1(v15);
    BYTE1(v15) = BYTE2(v7);
    v7 = v15;
  }
  v8 = v4->m_stream;
  v14 = 9;
  v13 = v7;
  ((void (__fastcall *)(hkStreamWriter *, unsigned int *, signed __int64))v8->vfptr[2].__vecDelDtor)(v8, &v13, 5i64);
  v9 = hkClass::getName(v6);
  v10 = ((__int64 (*)(void))v4->m_stream->vfptr[4].__vecDelDtor)();
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &v4->m_usedClassNames.m_map,
    (unsigned __int64)v9,
    v10 - v5);
  v11 = v4->m_stream->vfptr;
  v12 = hkString::strLen(v9);
  ((void (__fastcall *)(hkStreamWriter *, const char *, _QWORD))v11[2].__vecDelDtor)(
    v4->m_stream,
    v9,
    (unsigned int)(v12 + 1));
}

// File Line: 196
// RVA: 0xE4BBD0
void __fastcall hkBinaryPackfileWriter::writeAllObjects(hkBinaryPackfileWriter *this, hkBinaryPackfileWriter::SaveContext *context)
{
  hkPackfileSectionHeader *v2; // r15
  hkBinaryPackfileWriter *v3; // rdi
  hkBinaryPackfileWriter::SaveContext *v4; // rsi
  signed __int64 v5; // r14
  hkClass *v6; // rbx
  const char *v7; // rax
  int v8; // er14
  __int64 v9; // rbx
  const char *v10; // rax
  Dummy *v11; // rax
  const char *v12; // rax
  int v13; // eax
  int v14; // er14
  hkArray<WriteLocation,hkContainerHeapAllocator> *v15; // rbx
  int v16; // eax
  int v17; // eax
  int v18; // er9
  __int64 v19; // r12
  int v20; // eax
  int v21; // eax
  int v22; // er9
  int v23; // er14
  hkRelocationInfo *v24; // r15
  __int64 v25; // rdx
  signed __int64 v26; // r8
  int v27; // eax
  __int64 v28; // rdx
  signed __int64 v29; // rax
  signed int v30; // er12
  int v31; // er14
  __int64 v32; // r15
  __int64 v33; // rcx
  char *v34; // r13
  hkPackfileWriter::Options *v35; // rax
  int v36; // er8
  __int64 v37; // rcx
  __int64 v38; // rdx
  int v39; // er13
  int v40; // ecx
  __int64 v41; // r15
  __int64 v42; // r12
  hkPackfileWriter::PendingWrite *v43; // r14
  WriteLocation *v44; // rbx
  int v45; // eax
  __int64 v46; // rdx
  int v47; // er8
  __int64 v48; // rdx
  int v49; // er15
  __int64 v50; // r14
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v51; // rdi
  signed __int64 v52; // rbx
  unsigned __int64 v53; // r12
  int v54; // edx
  hkRelocationInfo::Import *v55; // rax
  __int64 v56; // rcx
  int v57; // eax
  signed __int64 v58; // r8
  hkRelocationInfo::Import *v59; // rdx
  hkRelocationInfo::Import *v60; // rax
  unsigned __int64 v61; // rdx
  const char *v62; // rcx
  signed __int64 v63; // rbx
  signed __int64 v64; // rcx
  int v65; // eax
  int v66; // edx
  __int64 v67; // rcx
  __int64 v68; // r8
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v69; // rax
  int v70; // er14
  char v71; // r15
  int v72; // eax
  const char *v73; // rbx
  int v74; // eax
  __int64 v75; // r8
  int v76; // edx
  __int64 v77; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v78; // rax
  int v79; // er15
  bool v80; // zf
  __int64 v81; // r14
  __int64 v82; // rbx
  int v83; // eax
  const void *v84; // [rsp+30h] [rbp-A9h]
  hkRelocationInfo::Import *v85; // [rsp+30h] [rbp-A9h]
  char *v86; // [rsp+38h] [rbp-A1h]
  void *ptr; // [rsp+40h] [rbp-99h]
  int v88; // [rsp+48h] [rbp-91h]
  int v89; // [rsp+4Ch] [rbp-8Dh]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> a; // [rsp+50h] [rbp-89h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v91; // [rsp+60h] [rbp-79h]
  __int64 array; // [rsp+70h] [rbp-69h]
  int v93; // [rsp+78h] [rbp-61h]
  int v94; // [rsp+7Ch] [rbp-5Dh]
  __int64 v95; // [rsp+80h] [rbp-59h]
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> v96; // [rsp+90h] [rbp-49h]
  __int64 v97; // [rsp+B0h] [rbp-29h]
  __int64 v98; // [rsp+B8h] [rbp-21h]
  hkClass *v99; // [rsp+C0h] [rbp-19h]
  char v100; // [rsp+C8h] [rbp-11h]
  char v101; // [rsp+CCh] [rbp-Dh]
  hkClass *k; // [rsp+D0h] [rbp-9h]
  hkClass *v103; // [rsp+D8h] [rbp-1h]
  hkClass *v104; // [rsp+E0h] [rbp+7h]
  hkClass *v105; // [rsp+E8h] [rbp+Fh]
  hkBinaryPackfileWriter *v106; // [rsp+140h] [rbp+67h]
  hkBool result; // [rsp+148h] [rbp+6Fh]
  int v108; // [rsp+150h] [rbp+77h]
  char v109; // [rsp+158h] [rbp+7Fh]

  v106 = this;
  v2 = context->m_sectionHeaders.m_data;
  v3 = this;
  v4 = context;
  v2->m_absoluteDataStart = ((__int64 (*)(void))context->m_stream->vfptr[4].__vecDelDtor)();
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v96,
    0);
  v5 = 0i64;
  k = &hkClassClass;
  v103 = &hkClassMemberClass;
  v104 = &hkClassEnumClass;
  v105 = &hkClassEnumItemClass;
  do
  {
    v6 = *(&k + v5);
    v7 = hkClass::getName(*(&k + v5));
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&v96, (unsigned __int64)v7, 1ui64);
    hkBinaryPackfileWriter::writeClassName(v3, v4, v6, v2->m_absoluteDataStart);
    ++v5;
  }
  while ( v5 < 4 );
  v8 = 0;
  if ( v3->m_pendingWrites.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      v10 = hkClass::getName(v3->m_pendingWrites.m_data[v9].m_klass);
      v11 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
              (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v96,
              (unsigned __int64)v10);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
        (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v96,
        &result,
        v11);
      if ( !result.m_bool )
      {
        v12 = hkClass::getName(v3->m_pendingWrites.m_data[v9].m_klass);
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&v96, (unsigned __int64)v12, 1ui64);
        hkBinaryPackfileWriter::writeClassName(v3, v4, v3->m_pendingWrites.m_data[v9].m_klass, v2->m_absoluteDataStart);
      }
      ++v8;
      ++v9;
    }
    while ( v8 < v3->m_pendingWrites.m_size );
  }
  padUp(v4->m_stream, 16, 255);
  v13 = (unsigned __int64)((__int64 (*)(void))v4->m_stream->vfptr[4].__vecDelDtor)() - v2->m_absoluteDataStart;
  v2->m_localFixupsOffset = v13;
  v2->m_globalFixupsOffset = v13;
  v2->m_virtualFixupsOffset = v13;
  v2->m_exportsOffset = v13;
  v2->m_importsOffset = v13;
  v2->m_endOffset = v13;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v96);
  v14 = v3->m_pendingWrites.m_size;
  v15 = &v4->m_locations;
  v16 = v4->m_locations.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v16 < v14 )
  {
    v17 = 2 * v16;
    v18 = v3->m_pendingWrites.m_size;
    if ( v14 < v17 )
      v18 = v17;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v4->m_locations,
      v18,
      8);
  }
  v4->m_locations.m_size = v14;
  v19 = v4->m_sectionHeaders.m_size;
  v20 = v4->m_relocsBySect.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v20 < (signed int)v19 )
  {
    v21 = 2 * v20;
    v22 = v4->m_sectionHeaders.m_size;
    if ( (signed int)v19 < v21 )
      v22 = v21;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v4->m_relocsBySect,
      v22,
      72);
  }
  v23 = v4->m_relocsBySect.m_size - v19 - 1;
  if ( v23 >= 0 )
  {
    v24 = &v4->m_relocsBySect.m_data[v19 + v23];
    do
    {
      hkRelocationInfo::~hkRelocationInfo(v24);
      --v24;
      --v23;
    }
    while ( v23 >= 0 );
  }
  v25 = v4->m_relocsBySect.m_size;
  v26 = (signed __int64)&v4->m_relocsBySect.m_data[v25];
  v27 = v19 - v25;
  v28 = (signed int)v19 - (signed int)v25;
  if ( v27 > 0 )
  {
    v29 = v26 + 28;
    do
    {
      if ( v29 != 28 )
      {
        *(_DWORD *)(v29 - 16) = 2147483648;
        *(_QWORD *)(v29 - 28) = 0i64;
        *(_DWORD *)(v29 - 20) = 0;
        *(_QWORD *)(v29 - 12) = 0i64;
        *(_DWORD *)(v29 - 4) = 0;
        *(_DWORD *)v29 = 2147483648;
        *(_QWORD *)(v29 + 4) = 0i64;
        *(_DWORD *)(v29 + 12) = 0;
        *(_DWORD *)(v29 + 16) = 2147483648;
        *(_QWORD *)(v29 + 20) = 0i64;
        *(_DWORD *)(v29 + 28) = 0;
        *(_DWORD *)(v29 + 32) = 2147483648;
        *(_QWORD *)(v29 + 36) = 0i64;
      }
      v29 += 72i64;
      --v28;
    }
    while ( v28 );
  }
  v4->m_relocsBySect.m_size = v19;
  v30 = 1;
  v31 = hkPackfileWriter::sectionTagToIndex((hkPackfileWriter *)&v3->vfptr, hkPackfileWriter::SECTION_TAG_TYPES);
  v108 = v31;
  *(_DWORD *)&result.m_bool = 1;
  v32 = 1i64;
  v98 = 1i64;
  if ( v4->m_sectionHeaders.m_size > 1 )
  {
    v33 = 64i64;
    v97 = 64i64;
    do
    {
      v34 = &v4->m_sectionHeaders.m_data->m_sectionTag[v33];
      v86 = &v4->m_sectionHeaders.m_data->m_sectionTag[v33];
      *((_DWORD *)v34 + 5) = ((__int64 (*)(void))v4->m_stream->vfptr[4].__vecDelDtor)();
      v35 = v4->m_options;
      ptr = 0i64;
      v88 = 0;
      v89 = 2147483648;
      a.m_data = 0i64;
      a.m_size = 0;
      a.m_capacityAndFlags = 2147483648;
      v91.m_data = 0i64;
      v91.m_size = 0;
      v91.m_capacityAndFlags = 2147483648;
      array = 0i64;
      v93 = 0;
      v94 = 2147483648;
      v95 = 0i64;
      if ( v35->m_writeMetaInfo.m_bool || v32 != v31 )
      {
        v39 = 0;
        if ( v3->m_pendingWrites.m_size > 0 )
        {
          v40 = *(_DWORD *)&result.m_bool;
          v41 = 0i64;
          v42 = 0i64;
          do
          {
            v43 = &v3->m_pendingWrites.m_data[v42];
            if ( v43->m_sectionIndex == v40 )
            {
              v84 = v43->m_pointer;
              v99 = v43->m_klass;
              v15->m_data[v41].m_sectionIndex = v40;
              v44 = v15->m_data;
              v45 = ((__int64 (*)(void))v4->m_stream->vfptr[4].__vecDelDtor)();
              v46 = (__int64)v99;
              v44[v41].m_offset = v45 - *((_DWORD *)v86 + 5);
              if ( v46 )
                ((void (__fastcall *)(hkPlatformObjectWriter *, char *, hkStreamWriter *, const void *, __int64, void **))v4->m_writer.vfptr[1].__first_virtual_table_function__)(
                  &v4->m_writer,
                  &v109,
                  v4->m_stream,
                  v84,
                  v46,
                  &ptr);
              else
                ((void (__fastcall *)(hkStreamWriter *, const void *, _QWORD))v4->m_stream->vfptr[2].__vecDelDtor)(
                  v4->m_stream,
                  v43->m_pointer,
                  (unsigned int)v43->m_dataSize);
              v40 = *(_DWORD *)&result.m_bool;
              v15 = &v4->m_locations;
            }
            ++v39;
            ++v42;
            ++v41;
          }
          while ( v39 < v3->m_pendingWrites.m_size );
          v30 = *(_DWORD *)&result.m_bool;
        }
        v34 = v86;
      }
      else
      {
        v36 = 0;
        if ( v3->m_pendingWrites.m_size > 0 )
        {
          v37 = 0i64;
          v38 = 0i64;
          do
          {
            if ( v3->m_pendingWrites.m_data[v38].m_sectionIndex == v31 )
            {
              v15->m_data[v37].m_sectionIndex = -1;
              v15->m_data[v37].m_offset = -1;
            }
            ++v36;
            ++v38;
            ++v37;
          }
          while ( v36 < v3->m_pendingWrites.m_size );
        }
      }
      v47 = 0;
      if ( v88 > 0 )
      {
        v48 = 0i64;
        do
        {
          ++v47;
          *(_DWORD *)((char *)ptr + v48) -= *((_DWORD *)v34 + 5);
          *(_DWORD *)((char *)ptr + v48 + 4) -= *((_DWORD *)v34 + 5);
          v48 += 8i64;
        }
        while ( v47 < v88 );
      }
      v49 = a.m_size - 1;
      v50 = a.m_size - 1;
      if ( a.m_size - 1 >= 0 )
      {
        v51 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_imports.m_map.m_elem;
        v52 = 2i64 * v49;
        do
        {
          v53 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  v51,
                  (unsigned __int64)a.m_data[v52].m_identifier,
                  0i64);
          if ( v53 )
          {
            v54 = v93;
            v55 = &a.m_data[v52];
            v85 = &a.m_data[v52];
            if ( v93 == (v94 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
              v54 = v93;
              v55 = v85;
            }
            v93 = v54 + 1;
            v56 = array + 16i64 * v54;
            *(_DWORD *)v56 = v55->m_fromOffset - *((_DWORD *)v34 + 5);
            *(_QWORD *)(v56 + 8) = v53;
            v57 = a.m_size - 1;
            a.m_size = v57;
            if ( v57 != v49 )
            {
              v58 = 4i64;
              v59 = &a.m_data[2 * v57];
              v60 = &a.m_data[v52];
              v61 = (char *)v59 - (char *)&a.m_data[v52];
              do
              {
                v62 = *(const char **)((char *)&v60->m_fromOffset + v61);
                v60 = (hkRelocationInfo::Import *)((char *)v60 + 8);
                v60[-1].m_identifier = v62;
                --v58;
              }
              while ( v58 );
            }
          }
          --v49;
          v52 -= 2i64;
          --v50;
        }
        while ( v50 >= 0 );
        v3 = v106;
        v30 = *(_DWORD *)&result.m_bool;
      }
      hkOArchive::hkOArchive((hkOArchive *)&v96, v4->m_stream, v4->m_endianSwapRequired);
      *((_DWORD *)v34 + 6) = (unsigned __int64)((__int64 (*)(void))v4->m_stream->vfptr[4].__vecDelDtor)()
                           - *((_DWORD *)v34 + 5);
      hkOArchive::writeArrayGeneric((hkOArchive *)&v96, ptr, 4, 2 * v88);
      padUp(v4->m_stream, 16, 255);
      *((_DWORD *)v34 + 7) = (unsigned __int64)((__int64 (*)(void))v4->m_stream->vfptr[4].__vecDelDtor)()
                           - *((_DWORD *)v34 + 5);
      ((void (__fastcall *)(hkStreamWriter *, char *, _QWORD, signed __int64))v4->m_stream->vfptr[3].__first_virtual_table_function__)(
        v4->m_stream,
        &v100,
        (unsigned int)(12 * a.m_size),
        1i64);
      v63 = 72i64 * v30;
      v64 = (signed __int64)&v4->m_relocsBySect.m_data->m_global;
      *(_QWORD *)&result.m_bool = v63;
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)(v63 + v64),
        &a);
      padUp(v4->m_stream, 16, 255);
      *((_DWORD *)v34 + 8) = (unsigned __int64)((__int64 (*)(void))v4->m_stream->vfptr[4].__vecDelDtor)()
                           - *((_DWORD *)v34 + 5);
      ((void (__fastcall *)(hkStreamWriter *, char *, _QWORD, signed __int64))v4->m_stream->vfptr[3].__first_virtual_table_function__)(
        v4->m_stream,
        &v101,
        (unsigned int)(12 * v91.m_size),
        1i64);
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v4->m_relocsBySect.m_data[(unsigned __int64)v63
                                                                                               / 0x48].m_finish,
        &v91);
      padUp(v4->m_stream, 16, 255);
      v65 = ((__int64 (*)(void))v4->m_stream->vfptr[4].__vecDelDtor)();
      v66 = 0;
      v67 = 0i64;
      *((_DWORD *)v34 + 9) = v65 - *((_DWORD *)v34 + 5);
      v68 = v3->m_exports.m_map.m_hashMod;
      if ( v68 >= 0 )
      {
        v69 = v3->m_exports.m_map.m_elem;
        do
        {
          if ( v69->key != -1i64 )
            break;
          ++v67;
          ++v66;
          ++v69;
        }
        while ( v67 <= v68 );
      }
      v70 = v66;
      v71 = 0;
      if ( v66 <= v3->m_exports.m_map.m_hashMod )
      {
        do
        {
          v72 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_knownObjects.m_map.m_elem,
                  v3->m_exports.m_map.m_elem[v70].key,
                  0xFFFFFFFFFFFFFFFFui64);
          if ( v72 >= 0 && v3->m_pendingWrites.m_data[v72].m_sectionIndex == v30 )
          {
            v71 = 1;
            v73 = (const char *)v3->m_exports.m_map.m_elem[v70].val;
            hkOArchive::write32((hkOArchive *)&v96, v4->m_locations.m_data[v72].m_offset);
            v74 = hkString::strLen(v73);
            hkOArchive::writeRaw((hkOArchive *)&v96, v73, (unsigned int)(v74 + 1));
            padUp(v4->m_stream, 4, 255);
          }
          v75 = v3->m_exports.m_map.m_hashMod;
          v76 = v70 + 1;
          v77 = v70 + 1;
          if ( v77 <= v75 )
          {
            v78 = &v3->m_exports.m_map.m_elem[v76];
            do
            {
              if ( v78->key != -1i64 )
                break;
              ++v77;
              ++v76;
              ++v78;
            }
            while ( v77 <= v75 );
          }
          v70 = v76;
        }
        while ( v76 <= v3->m_exports.m_map.m_hashMod );
        v34 = v86;
        if ( v71 )
        {
          hkOArchive::write32((hkOArchive *)&v96, -1);
          padUp(v4->m_stream, 16, 255);
        }
      }
      v79 = 0;
      *((_DWORD *)v34 + 10) = (unsigned __int64)((__int64 (*)(void))v4->m_stream->vfptr[4].__vecDelDtor)()
                            - *((_DWORD *)v34 + 5);
      v80 = v93 == 0;
      if ( v93 > 0 )
      {
        v81 = 0i64;
        do
        {
          v82 = array;
          hkOArchive::write32((hkOArchive *)&v96, *(_DWORD *)(array + v81));
          v83 = hkString::strLen(*(const char **)(v82 + v81 + 8));
          hkOArchive::writeRaw((hkOArchive *)&v96, *(const void **)(v82 + v81 + 8), (unsigned int)(v83 + 1));
          padUp(v4->m_stream, 4, 255);
          ++v79;
          v81 += 16i64;
        }
        while ( v79 < v93 );
        v80 = v93 == 0;
      }
      if ( !v80 )
      {
        hkOArchive::write32((hkOArchive *)&v96, -1);
        hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
          (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)((char *)&v4->m_relocsBySect.m_data->m_imports
                                                                       + *(_QWORD *)&result.m_bool),
          (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array);
        padUp(v4->m_stream, 16, 255);
      }
      *((_DWORD *)v34 + 11) = (unsigned __int64)((__int64 (*)(void))v4->m_stream->vfptr[4].__vecDelDtor)()
                            - *((_DWORD *)v34 + 5);
      hkOArchive::~hkOArchive((hkOArchive *)&v96);
      hkRelocationInfo::~hkRelocationInfo((hkRelocationInfo *)&ptr);
      v31 = v108;
      ++v30;
      v32 = v98 + 1;
      v33 = v97 + 64;
      v15 = &v4->m_locations;
      ++v98;
      *(_DWORD *)&result.m_bool = v30;
      v97 += 64i64;
    }
    while ( v30 < v4->m_sectionHeaders.m_size );
  }
}

// File Line: 420
// RVA: 0xE4C4D0
void __fastcall hkBinaryPackfileWriter::doDeferredWrites(hkBinaryPackfileWriter *this, hkBinaryPackfileWriter::SaveContext *context, int sectionHeadersStart)
{
  hkBinaryPackfileWriter::SaveContext *v3; // rbx
  hkBinaryPackfileWriter *v4; // r15
  signed __int64 v5; // r14
  __int64 v6; // r12
  hkPackfileSectionHeader *v7; // r13
  signed __int64 v8; // r13
  unsigned int *v9; // rdx
  char *v10; // r14
  int v11; // ecx
  int v12; // esi
  int v13; // er9
  unsigned int *v14; // rdi
  int v15; // eax
  __int64 v16; // rcx
  int v17; // esi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v18; // r12
  __int64 v19; // rdi
  signed __int64 v20; // r15
  int v21; // eax
  signed __int64 v22; // rdx
  int v23; // er15
  hkPackfileSectionHeader *v24; // r13
  __int64 v25; // r14
  char *v26; // rsi
  __int64 v27; // r13
  int v28; // edi
  int v29; // er9
  signed __int64 v30; // rdi
  __int64 v31; // r14
  unsigned int v32; // eax
  int i; // edi
  hkBaseObjectVtbl *v34; // rax
  hkStreamWriter *v35; // r8
  signed __int64 v36; // r9
  hkStructureLayout *v37; // rax
  hkClass *v38; // rdi
  const char *v39; // rax
  int v40; // eax
  unsigned int *array; // [rsp+30h] [rbp-D0h]
  int nelem; // [rsp+38h] [rbp-C8h]
  int v43; // [rsp+3Ch] [rbp-C4h]
  unsigned int *v44; // [rsp+40h] [rbp-C0h]
  int v45; // [rsp+48h] [rbp-B8h]
  int v46; // [rsp+4Ch] [rbp-B4h]
  __int64 v47; // [rsp+50h] [rbp-B0h]
  hkResult v48; // [rsp+58h] [rbp-A8h]
  __int64 v49; // [rsp+60h] [rbp-A0h]
  hkResult result; // [rsp+68h] [rbp-98h]
  char v51; // [rsp+6Ch] [rbp-94h]
  char v52; // [rsp+70h] [rbp-90h]
  hkRelocationInfo v53; // [rsp+80h] [rbp-80h]
  hkOArchive v54; // [rsp+D0h] [rbp-30h]
  hkOArchive v55; // [rsp+F0h] [rbp-10h]
  hkBinaryPackfileWriter *v56; // [rsp+160h] [rbp+60h]
  hkBinaryPackfileWriter::SaveContext *v57; // [rsp+168h] [rbp+68h]
  unsigned int v58; // [rsp+170h] [rbp+70h]
  int v59; // [rsp+178h] [rbp+78h]

  v58 = sectionHeadersStart;
  v57 = context;
  v56 = this;
  v3 = context;
  v4 = this;
  hkOArchive::hkOArchive(&v55, context->m_stream, context->m_endianSwapRequired);
  v59 = 0;
  if ( v3->m_sectionHeaders.m_size > 0 )
  {
    v47 = 0i64;
    v5 = 0i64;
    v6 = 0i64;
    v49 = 0i64;
    do
    {
      v7 = v3->m_sectionHeaders.m_data;
      v43 = 2147483648;
      v8 = (signed __int64)&v7->m_sectionTag[v5];
      v9 = 0i64;
      v10 = (char *)v3->m_relocsBySect.m_data + v6;
      v11 = 0;
      array = 0i64;
      nelem = 0;
      v12 = 3 * *((_DWORD *)v10 + 6);
      if ( v12 <= 0 )
      {
        result.m_enum = 0;
      }
      else
      {
        v13 = 3 * *((_DWORD *)v10 + 6);
        if ( v12 < 0 )
          v13 = 0;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v13, 4);
        v11 = nelem;
        v9 = array;
      }
      v14 = &v9[v11];
      v15 = v12 - v11;
      v16 = v12 - v11;
      if ( v15 > 0 )
      {
        while ( v16 )
        {
          *v14 = -1;
          ++v14;
          --v16;
        }
      }
      nelem = v12;
      v17 = 0;
      if ( *((_DWORD *)v10 + 6) > 0 )
      {
        v18 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v4->m_knownObjects.m_map.m_elem;
        v19 = 0i64;
        v20 = 2i64;
        do
        {
          v21 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  v18,
                  *(_QWORD *)(*((_QWORD *)v10 + 2) + v19 + 8),
                  0xFFFFFFFFFFFFFFFDui64);
          if ( v21 >= 0 )
          {
            v22 = v21;
            if ( v3->m_locations.m_data[v22].m_sectionIndex >= 0 )
            {
              v20 += 3i64;
              array[v20 - 5] = *(_DWORD *)(*((_QWORD *)v10 + 2) + v19) - *(_DWORD *)(v8 + 20);
              array[v20 - 4] = v3->m_locations.m_data[v22].m_sectionIndex;
              array[v20 - 3] = v3->m_locations.m_data[v22].m_offset;
            }
          }
          ++v17;
          v19 += 32i64;
        }
        while ( v17 < *((_DWORD *)v10 + 6) );
        v6 = v47;
      }
      ((void (__fastcall *)(hkStreamWriter *, char *, _QWORD, _QWORD))v3->m_stream->vfptr[3].__first_virtual_table_function__)(
        v3->m_stream,
        &v51,
        (unsigned int)(*(_DWORD *)(v8 + 20) + *(_DWORD *)(v8 + 28)),
        0i64);
      hkOArchive::writeArray32u(&v55, array, nelem);
      v23 = 0;
      nelem = 0;
      if ( v43 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          4 * v43);
      v24 = v3->m_sectionHeaders.m_data;
      v25 = v49;
      v26 = (char *)v3->m_relocsBySect.m_data + v6;
      v44 = 0i64;
      v45 = 0;
      v46 = 2147483648;
      v27 = (__int64)&v24->m_sectionTag[v49];
      v28 = 3 * *((_DWORD *)v26 + 10);
      array = 0i64;
      v43 = 2147483648;
      if ( v28 <= 0 )
      {
        v48.m_enum = 0;
      }
      else
      {
        v29 = v28;
        if ( v28 < 0 )
          v29 = 0;
        hkArrayUtil::_reserve(&v48, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v44, v29, 4);
      }
      v45 = v28;
      if ( *((_DWORD *)v26 + 10) > 0 )
      {
        v30 = 2i64;
        v31 = 0i64;
        do
        {
          v44[v30 - 2] = *(_DWORD *)(*((_QWORD *)v26 + 4) + v31) - *(_DWORD *)(v27 + 20);
          v44[v30 - 1] = 0;
          v32 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                  (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_usedClassNames,
                  *(_QWORD *)(*((_QWORD *)v26 + 4) + v31 + 8),
                  0xFFFFFFFFFFFFFFFFui64);
          ++v23;
          v44[v30] = v32;
          v31 += 16i64;
          v30 += 3i64;
        }
        while ( v23 < *((_DWORD *)v26 + 10) );
        v3 = v57;
        v6 = v47;
        v25 = v49;
      }
      ((void (__fastcall *)(hkStreamWriter *, char *, _QWORD, _QWORD))v3->m_stream->vfptr[3].__first_virtual_table_function__)(
        v3->m_stream,
        &v52,
        (unsigned int)(*(_DWORD *)(v27 + 20) + *(_DWORD *)(v27 + 32)),
        0i64);
      hkOArchive::writeArray32u(&v55, v44, v45);
      v45 = 0;
      if ( v46 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v44,
          4 * v46);
      v4 = v56;
      v5 = v25 + 64;
      v6 += 72i64;
      v44 = 0i64;
      v46 = 2147483648;
      v49 = v5;
      ++v59;
      v47 = v6;
    }
    while ( v59 < v3->m_sectionHeaders.m_size );
  }
  ((void (__fastcall *)(hkStreamWriter *, hkBinaryPackfileWriter **, _QWORD, _QWORD))v3->m_stream->vfptr[3].__first_virtual_table_function__)(
    v3->m_stream,
    &v56,
    v58,
    0i64);
  for ( i = 0; i < v3->m_sectionHeaders.m_size; ++i )
  {
    v34 = v3->m_writer.vfptr;
    v35 = v3->m_stream;
    v53.m_local.m_data = 0i64;
    v36 = (signed __int64)v3->m_sectionHeaders.m_data[(signed __int64)i].m_sectionTag;
    v53.m_local.m_size = 0;
    v53.m_local.m_capacityAndFlags = 2147483648;
    v53.m_global.m_data = 0i64;
    v53.m_global.m_size = 0;
    v53.m_global.m_capacityAndFlags = 2147483648;
    v53.m_finish.m_data = 0i64;
    v53.m_finish.m_size = 0;
    v53.m_finish.m_capacityAndFlags = 2147483648;
    v53.m_imports.m_data = 0i64;
    v53.m_imports.m_size = 0;
    v53.m_imports.m_capacityAndFlags = 2147483648;
    v53.m_pool = 0i64;
    ((void (__fastcall *)(hkPlatformObjectWriter *, hkBinaryPackfileWriter **, hkStreamWriter *, signed __int64, hkClass *, hkRelocationInfo *, unsigned int *, _QWORD, unsigned int *, _QWORD))v34[1].__first_virtual_table_function__)(
      &v3->m_writer,
      &v56,
      v35,
      v36,
      &hkPackfileSectionHeaderClass,
      &v53,
      array,
      *(_QWORD *)&nelem,
      v44,
      *(_QWORD *)&v45);
    hkRelocationInfo::~hkRelocationInfo(&v53);
  }
  ((void (__fastcall *)(hkStreamWriter *, hkBinaryPackfileWriter **, signed __int64))v3->m_stream->vfptr[3].__first_virtual_table_function__)(
    v3->m_stream,
    &v56,
    24i64);
  v37 = hkPlatformObjectWriter::getLayout(&v3->m_writer);
  hkOArchive::hkOArchive(
    &v54,
    v3->m_stream,
    (hkBool)(*(_WORD *)&v37->m_rules.m_bytesInPointer >> 8 != hkStructureLayout::HostLayoutRules.m_littleEndian));
  hkOArchive::write32(&v54, v3->m_locations.m_data[v4->m_contentsPtrPWIndex].m_sectionIndex);
  hkOArchive::write32(&v54, v3->m_locations.m_data[v4->m_contentsPtrPWIndex].m_offset);
  v38 = (hkClass *)v4->m_pendingWrites.m_data[v4->m_contentsClassPWIndex].m_pointer;
  hkOArchive::write32(&v54, 0);
  v39 = hkClass::getName(v38);
  v40 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
          (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_usedClassNames,
          (unsigned __int64)v39,
          0xFFFFFFFFFFFFFFFFui64);
  hkOArchive::write32(&v54, v40);
  hkOArchive::~hkOArchive(&v54);
  hkOArchive::~hkOArchive(&v55);
}

// File Line: 495
// RVA: 0xE4B830
hkResult *__fastcall hkBinaryPackfileWriter::save(hkBinaryPackfileWriter *this, hkResult *result, hkStreamWriter *origStream, hkPackfileWriter::Options *options)
{
  hkResult *v4; // r14
  hkBinaryPackfileWriter *v5; // r12
  hkPackfileWriter::Options *v6; // rdi
  hkStreamWriter *v7; // rbx
  char v8; // al
  int v9; // edi
  unsigned int v10; // eax
  unsigned int v11; // ebx
  void **v13; // [rsp+20h] [rbp-69h]
  int v14; // [rsp+28h] [rbp-61h]
  hkStreamWriter *v15; // [rsp+30h] [rbp-59h]
  int v16; // [rsp+38h] [rbp-51h]
  hkBinaryPackfileWriter::SaveContext context; // [rsp+40h] [rbp-49h]
  char v18; // [rsp+100h] [rbp+77h]

  v4 = result;
  v5 = this;
  v6 = options;
  v7 = origStream;
  if ( *(_BYTE *)origStream->vfptr[3].__vecDelDtor((hkBaseObject *)origStream, (unsigned int)&v18) )
  {
    context.m_options = v6;
    context.m_sectionHeaders.m_data = 0i64;
    context.m_sectionHeaders.m_size = 0;
    context.m_sectionHeaders.m_capacityAndFlags = 2147483648;
    context.m_locations.m_data = 0i64;
    context.m_locations.m_size = 0;
    context.m_locations.m_capacityAndFlags = 2147483648;
    hkPlatformObjectWriter::hkPlatformObjectWriter(
      &context.m_writer,
      &v6->m_layout,
      0i64,
      (hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int>)2);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      &context.m_usedClassNames.m_map,
      0);
    v8 = v6->m_layout.m_rules.m_littleEndian;
    context.m_relocsBySect.m_data = 0i64;
    context.m_relocsBySect.m_size = 0;
    v13 = &hkSubStreamWriter::`vftable';
    context.m_relocsBySect.m_capacityAndFlags = 2147483648;
    v14 = 0x1FFFF;
    context.m_endianSwapRequired.m_bool = hkStructureLayout::HostLayoutRules.m_littleEndian != v8;
    v15 = v7;
    v16 = ((__int64 (__fastcall *)(hkStreamWriter *))v7->vfptr[4].__vecDelDtor)(v7);
    context.m_stream = (hkStreamWriter *)&v13;
    hkBinaryPackfileWriter::fillSectionTags(v5, &context);
    saveFileHeader(&context.m_writer, context.m_stream, v6, context.m_sectionHeaders.m_size);
    v9 = ((__int64 (__fastcall *)(void ***))v13[8])(&v13);
    v10 = `anonymous namespace'::getArraySizeInBytes<hkPackfileSectionHeader>(&context.m_sectionHeaders);
    ((void (__fastcall *)(void ***, char *, _QWORD, signed __int64))v13[7])(&v13, &v18, v10, 1i64);
    hkBinaryPackfileWriter::writeAllObjects(v5, &context);
    v11 = ((__int64 (__fastcall *)(void ***))v13[8])(&v13);
    hkBinaryPackfileWriter::doDeferredWrites(v5, &context, v9);
    ((void (__fastcall *)(void ***, char *, _QWORD, _QWORD))v13[7])(&v13, &v18, v11, 0i64);
    ((void (__fastcall *)(void ***))v13[5])(&v13);
    v4->m_enum = *(_BYTE *)((__int64 (__fastcall *)(void ***, char *))v13[3])(&v13, &v18) == 0;
    v13 = &hkBaseObject::`vftable';
    hkBinaryPackfileWriter::SaveContext::~SaveContext(&context);
  }
  else
  {
    v4->m_enum = 1;
  }
  return v4;
}

