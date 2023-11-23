// File Line: 82
// RVA: 0xE4CC30
unsigned __int64 __fastcall `anonymous namespace::getArraySizeInBytes<hkPackfileSectionHeader>(
        hkArray<hkPackfileSectionHeader,hkContainerHeapAllocator> *a)
{
  return (unsigned __int64)(unsigned int)a->m_size << 6;
}

// File Line: 112
// RVA: 0xE4C9E0
__int64 __fastcall padUp(hkStreamWriter *w, int pad, char padData)
{
  unsigned int v6; // ebx
  int v7; // eax
  int v8; // edi
  char *v9; // rdx
  int v10; // ebp
  int v11; // r9d
  int v12; // eax
  char *v13; // rdi
  int v14; // eax
  char *array; // [rsp+30h] [rbp-48h] BYREF
  int v17; // [rsp+38h] [rbp-40h]
  int v18; // [rsp+3Ch] [rbp-3Ch]
  char v19[32]; // [rsp+40h] [rbp-38h] BYREF
  hkResult result; // [rsp+90h] [rbp+18h] BYREF

  v6 = 0;
  v7 = ((__int64 (__fastcall *)(hkStreamWriter *))w->vfptr[4].__vecDelDtor)(w);
  v8 = 0;
  v9 = v19;
  v18 = -2147483616;
  v10 = v7;
  array = v19;
  v17 = 0;
  if ( pad > 32 )
  {
    v11 = pad;
    if ( pad < 64 )
      v11 = 64;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v11, 1);
    v8 = v17;
    v9 = array;
  }
  v12 = pad - v8;
  v13 = &v9[v8];
  if ( v12 > 0 )
  {
    memset(v13, padData, v12);
    v9 = array;
  }
  v17 = pad;
  v14 = v10 & (pad - 1);
  if ( v14 )
  {
    v6 = pad - v14;
    ((void (__fastcall *)(hkStreamWriter *, char *, _QWORD))w->vfptr[2].__vecDelDtor)(w, v9, (unsigned int)(pad - v14));
    v9 = array;
  }
  v17 = 0;
  if ( v18 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v9, v18 & 0x3FFFFFFF);
  return v6;
}

// File Line: 127
// RVA: 0xE4B780
void __fastcall hkBinaryPackfileWriter::hkBinaryPackfileWriter(
        hkBinaryPackfileWriter *this,
        hkPackfileWriter::Options *options)
{
  hkPackfileWriter::hkPackfileWriter(this, options);
  this->vfptr = (hkBaseObjectVtbl *)&hkBinaryPackfileWriter::`vftable;
  hkPackfileWriter::addSection(this, hkBinaryPackfileWriter::SECTION_TAG_CLASSNAMES);
  hkPackfileWriter::setSectionForClass(this, &hkClassClass, hkPackfileWriter::SECTION_TAG_TYPES);
  hkPackfileWriter::setSectionForClass(this, &hkClassMemberClass, hkPackfileWriter::SECTION_TAG_TYPES);
  hkPackfileWriter::setSectionForClass(this, &hkClassEnumClass, hkPackfileWriter::SECTION_TAG_TYPES);
  hkPackfileWriter::setSectionForClass(this, &hkClassEnumItemClass, hkPackfileWriter::SECTION_TAG_TYPES);
}

// File Line: 137
// RVA: 0xE4B810
void __fastcall hkBinaryPackfileWriter::~hkBinaryPackfileWriter(hkBinaryPackfileWriter *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkBinaryPackfileWriter::`vftable;
  hkPackfileWriter::~hkPackfileWriter(this);
}

// File Line: 141
// RVA: 0xE4BAD0
void __fastcall hkBinaryPackfileWriter::fillSectionTags(
        hkBinaryPackfileWriter *this,
        hkBinaryPackfileWriter::SaveContext *context)
{
  hkArray<hkPackfileSectionHeader,hkContainerHeapAllocator> *p_m_sectionHeaders; // rsi
  int m_size; // r14d
  int v4; // eax
  int v6; // eax
  int v7; // r9d
  __int64 v8; // rax
  hkPackfileSectionHeader *v9; // rbx
  __int64 v10; // rdi
  unsigned int ArraySizeIn; // eax
  int v12; // ebx
  __int64 v13; // rdi
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  p_m_sectionHeaders = &context->m_sectionHeaders;
  m_size = this->m_knownSections.m_size;
  v4 = context->m_sectionHeaders.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < m_size )
  {
    v6 = 2 * v4;
    v7 = this->m_knownSections.m_size;
    if ( m_size < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&p_m_sectionHeaders->m_data,
      v7,
      64);
  }
  v8 = p_m_sectionHeaders->m_size;
  v9 = &p_m_sectionHeaders->m_data[v8];
  if ( m_size - (int)v8 > 0 )
  {
    v10 = (unsigned int)(m_size - v8);
    do
    {
      if ( v9 )
        hkString::memSet(v9, 0, 8u);
      ++v9;
      --v10;
    }
    while ( v10 );
  }
  p_m_sectionHeaders->m_size = m_size;
  ArraySizeIn = `anonymous namespace::getArraySizeInBytes<hkPackfileSectionHeader>(p_m_sectionHeaders);
  hkString::memSet(p_m_sectionHeaders->m_data, -1, ArraySizeIn);
  v12 = 0;
  if ( this->m_knownSections.m_size > 0 )
  {
    v13 = 0i64;
    do
      hkString::strNcpy(
        p_m_sectionHeaders->m_data[(__int64)v12++].m_sectionTag,
        this->m_knownSections.m_data[v13++],
        0x13u);
    while ( v12 < this->m_knownSections.m_size );
  }
}

// File Line: 153
// RVA: 0xE4CAF0
void __fastcall saveFileHeader(
        hkPlatformObjectWriter *writer,
        hkStreamWriter *stream,
        hkPackfileWriter::Options *options,
        int numSections)
{
  unsigned int m_userTag; // eax
  const char *m_contentsVersion; // rdx
  hkBaseObjectVtbl *vfptr; // rax
  int dst[4]; // [rsp+30h] [rbp-49h] BYREF
  char v12[4]; // [rsp+40h] [rbp-39h] BYREF
  int v13; // [rsp+44h] [rbp-35h]
  char buf[16]; // [rsp+58h] [rbp-21h] BYREF
  __int64 v15; // [rsp+68h] [rbp-11h] BYREF
  hkRelocationInfo v16; // [rsp+70h] [rbp-9h] BYREF
  char v17; // [rsp+F8h] [rbp+7Fh] BYREF

  hkString::memSet(dst, -1, 0x40u);
  m_userTag = options->m_userTag;
  dst[0] = 1474355287;
  dst[1] = 281067536;
  buf[0] = 0;
  v15 = 0i64;
  dst[2] = m_userTag;
  dst[3] = 11;
  hkString::memCpy(v12, &options->m_layout, 4u);
  v13 = numSections;
  hkString::memSet((char *)&v15 + 4, -1, 4u);
  m_contentsVersion = options->m_contentsVersion;
  if ( m_contentsVersion )
    hkString::strNcpy(buf, m_contentsVersion, 0x10u);
  else
    hkPackfileWriter::getCurrentVersion(buf, 16);
  vfptr = writer->vfptr;
  v16.m_local.m_data = 0i64;
  v16.m_local.m_size = 0;
  v16.m_local.m_capacityAndFlags = 0x80000000;
  v16.m_global.m_data = 0i64;
  v16.m_global.m_size = 0;
  v16.m_global.m_capacityAndFlags = 0x80000000;
  v16.m_finish.m_data = 0i64;
  v16.m_finish.m_size = 0;
  v16.m_finish.m_capacityAndFlags = 0x80000000;
  v16.m_imports.m_data = 0i64;
  v16.m_imports.m_size = 0;
  v16.m_imports.m_capacityAndFlags = 0x80000000;
  v16.m_pool = 0i64;
  ((void (__fastcall *)(hkPlatformObjectWriter *, char *, hkStreamWriter *, int *, hkClass *, hkRelocationInfo *))vfptr[1].__first_virtual_table_function__)(
    writer,
    &v17,
    stream,
    dst,
    &hkPackfileHeaderClass,
    &v16);
  hkRelocationInfo::~hkRelocationInfo(&v16);
}

// File Line: 173
// RVA: 0xE4BA00
void __fastcall hkBinaryPackfileWriter::writeClassName(
        hkBinaryPackfileWriter *this,
        hkBinaryPackfileWriter::SaveContext *context,
        hkClass *k,
        int absoluteDataStart)
{
  unsigned int Signature; // eax
  hkStreamWriter *m_stream; // rcx
  const char *Name; // rdi
  int v10; // eax
  hkBaseObjectVtbl *vfptr; // rbx
  int v12; // eax
  unsigned int v13; // [rsp+20h] [rbp-28h] BYREF
  char v14; // [rsp+24h] [rbp-24h]
  unsigned int v15; // [rsp+68h] [rbp+20h]

  Signature = hkClass::getSignature(k, 0);
  if ( context->m_endianSwapRequired.m_bool )
  {
    HIBYTE(v15) = Signature;
    LOBYTE(v15) = HIBYTE(Signature);
    BYTE2(v15) = BYTE1(Signature);
    BYTE1(v15) = BYTE2(Signature);
    Signature = v15;
  }
  m_stream = context->m_stream;
  v14 = 9;
  v13 = Signature;
  ((void (__fastcall *)(hkStreamWriter *, unsigned int *, __int64))m_stream->vfptr[2].__vecDelDtor)(
    m_stream,
    &v13,
    5i64);
  Name = hkClass::getName(k);
  v10 = ((__int64 (__fastcall *)(hkStreamWriter *))context->m_stream->vfptr[4].__vecDelDtor)(context->m_stream);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &context->m_usedClassNames.m_map,
    Name,
    v10 - absoluteDataStart);
  vfptr = context->m_stream->vfptr;
  v12 = hkString::strLen(Name);
  ((void (__fastcall *)(hkStreamWriter *, const char *, _QWORD))vfptr[2].__vecDelDtor)(
    context->m_stream,
    Name,
    (unsigned int)(v12 + 1));
}

// File Line: 196
// RVA: 0xE4BBD0
void __fastcall hkBinaryPackfileWriter::writeAllObjects(
        hkBinaryPackfileWriter *this,
        hkBinaryPackfileWriter::SaveContext *context)
{
  hkPackfileSectionHeader *m_data; // r15
  hkBinaryPackfileWriter *v3; // rdi
  __int64 v5; // r14
  hkClass *v6; // rbx
  const char *Name; // rax
  int v8; // r14d
  __int64 v9; // rbx
  const char *v10; // rax
  Dummy *Key; // rax
  const char *v12; // rax
  int v13; // eax
  int m_size; // r14d
  hkArray<WriteLocation,hkContainerHeapAllocator> *p_m_locations; // rbx
  int v16; // eax
  int v17; // eax
  int v18; // r9d
  __int64 v19; // r12
  int v20; // eax
  int v21; // eax
  int v22; // r9d
  int v23; // r14d
  hkRelocationInfo *v24; // r15
  __int64 v25; // rdx
  hkRelocationInfo *v26; // r8
  int v27; // eax
  __int64 v28; // rdx
  int *p_m_capacityAndFlags; // rax
  int v30; // r12d
  int v31; // r14d
  __int64 v32; // r15
  __int64 v33; // rcx
  char *v34; // r13
  hkPackfileWriter::Options *m_options; // rax
  int v36; // r8d
  __int64 v37; // rcx
  __int64 v38; // rdx
  int v39; // r13d
  int v40; // ecx
  __int64 v41; // r15
  __int64 v42; // r12
  hkPackfileWriter::PendingWrite *v43; // r14
  WriteLocation *v44; // rbx
  int v45; // eax
  __int64 v46; // rdx
  int v47; // r8d
  __int64 v48; // rdx
  int v49; // r15d
  __int64 v50; // r14
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *p_m_map; // rdi
  __int64 v52; // rbx
  unsigned __int64 v53; // r12
  int v54; // edx
  hkRelocationInfo::Global *v55; // rax
  hkRelocationInfo::Import *v56; // rcx
  int v57; // eax
  __int64 v58; // r8
  hkRelocationInfo::Global *v59; // rdx
  hkRelocationInfo::Global *v60; // rax
  signed __int64 v61; // rdx
  __int64 v62; // rcx
  unsigned __int64 v63; // rbx
  hkArray<hkRelocationInfo::Global,hkContainerHeapAllocator> *p_m_global; // rcx
  int v65; // eax
  int v66; // edx
  __int64 v67; // rcx
  __int64 m_hashMod; // r8
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v70; // r14d
  char v71; // r15
  int v72; // eax
  const char *val; // rbx
  int v74; // eax
  __int64 v75; // r8
  int v76; // edx
  __int64 v77; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v78; // rax
  int v79; // r15d
  bool v80; // zf
  __int64 v81; // r14
  hkRelocationInfo::Import *v82; // rbx
  int v83; // eax
  const void *m_pointer; // [rsp+30h] [rbp-A9h]
  hkRelocationInfo::Global *v85; // [rsp+30h] [rbp-A9h]
  char *v86; // [rsp+38h] [rbp-A1h]
  hkRelocationInfo ptr; // [rsp+40h] [rbp-99h] BYREF
  hkOArchive v88; // [rsp+90h] [rbp-49h] BYREF
  __int64 v89; // [rsp+B0h] [rbp-29h]
  __int64 v90; // [rsp+B8h] [rbp-21h]
  hkClass *m_klass; // [rsp+C0h] [rbp-19h]
  char v92[4]; // [rsp+C8h] [rbp-11h] BYREF
  char v93[4]; // [rsp+CCh] [rbp-Dh] BYREF
  hkClass *k[12]; // [rsp+D0h] [rbp-9h]
  unsigned __int64 result; // [rsp+148h] [rbp+6Fh] BYREF
  int v97; // [rsp+150h] [rbp+77h]
  char v98; // [rsp+158h] [rbp+7Fh] BYREF

  m_data = context->m_sectionHeaders.m_data;
  v3 = this;
  m_data->m_absoluteDataStart = ((__int64 (__fastcall *)(hkStreamWriter *))context->m_stream->vfptr[4].__vecDelDtor)(context->m_stream);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&v88,
    0);
  v5 = 0i64;
  k[0] = &hkClassClass;
  k[1] = &hkClassMemberClass;
  k[2] = &hkClassEnumClass;
  k[3] = &hkClassEnumItemClass;
  do
  {
    v6 = k[v5];
    Name = hkClass::getName(v6);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&v88,
      Name,
      1ui64);
    hkBinaryPackfileWriter::writeClassName(v3, context, v6, m_data->m_absoluteDataStart);
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
      Key = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
              (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v88,
              v10);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
        (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v88,
        (hkBool *)&result,
        Key);
      if ( !(_BYTE)result )
      {
        v12 = hkClass::getName(v3->m_pendingWrites.m_data[v9].m_klass);
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
          (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&v88,
          v12,
          1ui64);
        hkBinaryPackfileWriter::writeClassName(
          v3,
          context,
          v3->m_pendingWrites.m_data[v9].m_klass,
          m_data->m_absoluteDataStart);
      }
      ++v8;
      ++v9;
    }
    while ( v8 < v3->m_pendingWrites.m_size );
  }
  padUp(context->m_stream, 16, 255);
  v13 = ((__int64 (__fastcall *)(hkStreamWriter *))context->m_stream->vfptr[4].__vecDelDtor)(context->m_stream)
      - m_data->m_absoluteDataStart;
  m_data->m_localFixupsOffset = v13;
  m_data->m_globalFixupsOffset = v13;
  m_data->m_virtualFixupsOffset = v13;
  m_data->m_exportsOffset = v13;
  m_data->m_importsOffset = v13;
  m_data->m_endOffset = v13;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>((hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&v88);
  m_size = v3->m_pendingWrites.m_size;
  p_m_locations = &context->m_locations;
  v16 = context->m_locations.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v16 < m_size )
  {
    v17 = 2 * v16;
    v18 = v3->m_pendingWrites.m_size;
    if ( m_size < v17 )
      v18 = v17;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&context->m_locations.m_data,
      v18,
      8);
  }
  context->m_locations.m_size = m_size;
  v19 = context->m_sectionHeaders.m_size;
  v20 = context->m_relocsBySect.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v20 < (int)v19 )
  {
    v21 = 2 * v20;
    v22 = context->m_sectionHeaders.m_size;
    if ( (int)v19 < v21 )
      v22 = v21;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&context->m_relocsBySect.m_data,
      v22,
      72);
  }
  v23 = context->m_relocsBySect.m_size - v19 - 1;
  if ( v23 >= 0 )
  {
    v24 = &context->m_relocsBySect.m_data[v19 + v23];
    do
    {
      hkRelocationInfo::~hkRelocationInfo(v24--);
      --v23;
    }
    while ( v23 >= 0 );
  }
  v25 = context->m_relocsBySect.m_size;
  v26 = &context->m_relocsBySect.m_data[v25];
  v27 = v19 - v25;
  v28 = (int)v19 - (int)v25;
  if ( v27 > 0 )
  {
    p_m_capacityAndFlags = &v26->m_global.m_capacityAndFlags;
    do
    {
      if ( p_m_capacityAndFlags != (int *)28 )
      {
        *(p_m_capacityAndFlags - 4) = 0x80000000;
        *(_QWORD *)(p_m_capacityAndFlags - 7) = 0i64;
        *(p_m_capacityAndFlags - 5) = 0;
        *(_QWORD *)(p_m_capacityAndFlags - 3) = 0i64;
        *(p_m_capacityAndFlags - 1) = 0;
        *p_m_capacityAndFlags = 0x80000000;
        *(_QWORD *)(p_m_capacityAndFlags + 1) = 0i64;
        p_m_capacityAndFlags[3] = 0;
        p_m_capacityAndFlags[4] = 0x80000000;
        *(_QWORD *)(p_m_capacityAndFlags + 5) = 0i64;
        p_m_capacityAndFlags[7] = 0;
        p_m_capacityAndFlags[8] = 0x80000000;
        *(_QWORD *)(p_m_capacityAndFlags + 9) = 0i64;
      }
      p_m_capacityAndFlags += 18;
      --v28;
    }
    while ( v28 );
  }
  context->m_relocsBySect.m_size = v19;
  v30 = 1;
  v31 = hkPackfileWriter::sectionTagToIndex(v3, (char *)hkPackfileWriter::SECTION_TAG_TYPES);
  v97 = v31;
  LODWORD(result) = 1;
  v32 = 1i64;
  v90 = 1i64;
  if ( context->m_sectionHeaders.m_size > 1 )
  {
    v33 = 64i64;
    v89 = 64i64;
    do
    {
      v34 = &context->m_sectionHeaders.m_data->m_sectionTag[v33];
      v86 = v34;
      *((_DWORD *)v34 + 5) = ((__int64 (__fastcall *)(hkStreamWriter *))context->m_stream->vfptr[4].__vecDelDtor)(context->m_stream);
      m_options = context->m_options;
      ptr.m_local.m_data = 0i64;
      ptr.m_local.m_size = 0;
      ptr.m_local.m_capacityAndFlags = 0x80000000;
      ptr.m_global.m_data = 0i64;
      ptr.m_global.m_size = 0;
      ptr.m_global.m_capacityAndFlags = 0x80000000;
      ptr.m_finish.m_data = 0i64;
      ptr.m_finish.m_size = 0;
      ptr.m_finish.m_capacityAndFlags = 0x80000000;
      ptr.m_imports.m_data = 0i64;
      ptr.m_imports.m_size = 0;
      ptr.m_imports.m_capacityAndFlags = 0x80000000;
      ptr.m_pool = 0i64;
      if ( m_options->m_writeMetaInfo.m_bool || v32 != v31 )
      {
        v39 = 0;
        if ( v3->m_pendingWrites.m_size > 0 )
        {
          v40 = result;
          v41 = 0i64;
          v42 = 0i64;
          do
          {
            v43 = &v3->m_pendingWrites.m_data[v42];
            if ( v43->m_sectionIndex == v40 )
            {
              m_pointer = v43->m_pointer;
              m_klass = v43->m_klass;
              p_m_locations->m_data[v41].m_sectionIndex = v40;
              v44 = p_m_locations->m_data;
              v45 = ((__int64 (__fastcall *)(hkStreamWriter *))context->m_stream->vfptr[4].__vecDelDtor)(context->m_stream);
              v46 = (__int64)m_klass;
              v44[v41].m_offset = v45 - *((_DWORD *)v86 + 5);
              if ( v46 )
                ((void (__fastcall *)(hkPlatformObjectWriter *, char *, hkStreamWriter *, const void *, __int64, hkRelocationInfo *))context->m_writer.vfptr[1].__first_virtual_table_function__)(
                  &context->m_writer,
                  &v98,
                  context->m_stream,
                  m_pointer,
                  v46,
                  &ptr);
              else
                ((void (__fastcall *)(hkStreamWriter *, const void *, _QWORD))context->m_stream->vfptr[2].__vecDelDtor)(
                  context->m_stream,
                  v43->m_pointer,
                  (unsigned int)v43->m_dataSize);
              v40 = result;
              p_m_locations = &context->m_locations;
            }
            ++v39;
            ++v42;
            ++v41;
          }
          while ( v39 < v3->m_pendingWrites.m_size );
          v30 = result;
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
              p_m_locations->m_data[v37].m_sectionIndex = -1;
              p_m_locations->m_data[v37].m_offset = -1;
            }
            ++v36;
            ++v38;
            ++v37;
          }
          while ( v36 < v3->m_pendingWrites.m_size );
        }
      }
      v47 = 0;
      if ( ptr.m_local.m_size > 0 )
      {
        v48 = 0i64;
        do
        {
          ++v47;
          ptr.m_local.m_data[v48].m_fromOffset -= *((_DWORD *)v34 + 5);
          ptr.m_local.m_data[v48++].m_toOffset -= *((_DWORD *)v34 + 5);
        }
        while ( v47 < ptr.m_local.m_size );
      }
      v49 = ptr.m_global.m_size - 1;
      v50 = ptr.m_global.m_size - 1;
      if ( ptr.m_global.m_size - 1 >= 0 )
      {
        p_m_map = &v3->m_imports.m_map;
        v52 = v49;
        do
        {
          v53 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  p_m_map,
                  (unsigned __int64)ptr.m_global.m_data[v52].m_toAddress,
                  0i64);
          if ( v53 )
          {
            v54 = ptr.m_imports.m_size;
            v55 = &ptr.m_global.m_data[v52];
            v85 = &ptr.m_global.m_data[v52];
            if ( ptr.m_imports.m_size == (ptr.m_imports.m_capacityAndFlags & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&ptr.m_imports.m_data, 16);
              v54 = ptr.m_imports.m_size;
              v55 = v85;
            }
            ptr.m_imports.m_size = v54 + 1;
            v56 = &ptr.m_imports.m_data[v54];
            v56->m_fromOffset = v55->m_fromOffset - *((_DWORD *)v34 + 5);
            v56->m_identifier = (const char *)v53;
            v57 = ptr.m_global.m_size - 1;
            ptr.m_global.m_size = v57;
            if ( v57 != v49 )
            {
              v58 = 4i64;
              v59 = &ptr.m_global.m_data[v57];
              v60 = &ptr.m_global.m_data[v52];
              v61 = (char *)v59 - (char *)&ptr.m_global.m_data[v52];
              do
              {
                v62 = *(_QWORD *)((char *)&v60->m_fromOffset + v61);
                v60 = (hkRelocationInfo::Global *)((char *)v60 + 8);
                *(_QWORD *)&v60[-1].m_related = v62;
                --v58;
              }
              while ( v58 );
            }
          }
          --v49;
          --v52;
          --v50;
        }
        while ( v50 >= 0 );
        v3 = this;
        v30 = result;
      }
      hkOArchive::hkOArchive(&v88, context->m_stream, context->m_endianSwapRequired);
      *((_DWORD *)v34 + 6) = ((__int64 (__fastcall *)(hkStreamWriter *))context->m_stream->vfptr[4].__vecDelDtor)(context->m_stream)
                           - *((_DWORD *)v34 + 5);
      hkOArchive::writeArrayGeneric(&v88, (char *)ptr.m_local.m_data, 4, 2 * ptr.m_local.m_size);
      padUp(context->m_stream, 16, 255);
      *((_DWORD *)v34 + 7) = ((__int64 (__fastcall *)(hkStreamWriter *))context->m_stream->vfptr[4].__vecDelDtor)(context->m_stream)
                           - *((_DWORD *)v34 + 5);
      ((void (__fastcall *)(hkStreamWriter *, char *, _QWORD, __int64))context->m_stream->vfptr[3].__first_virtual_table_function__)(
        context->m_stream,
        v92,
        (unsigned int)(12 * ptr.m_global.m_size),
        1i64);
      v63 = 72i64 * v30;
      p_m_global = &context->m_relocsBySect.m_data->m_global;
      result = v63;
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)((char *)p_m_global + v63),
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&ptr.m_global);
      padUp(context->m_stream, 16, 255);
      *((_DWORD *)v34 + 8) = ((__int64 (__fastcall *)(hkStreamWriter *))context->m_stream->vfptr[4].__vecDelDtor)(context->m_stream)
                           - *((_DWORD *)v34 + 5);
      ((void (__fastcall *)(hkStreamWriter *, char *, _QWORD, __int64))context->m_stream->vfptr[3].__first_virtual_table_function__)(
        context->m_stream,
        v93,
        (unsigned int)(12 * ptr.m_finish.m_size),
        1i64);
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&context->m_relocsBySect.m_data[v63 / 0x48].m_finish,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&ptr.m_finish);
      padUp(context->m_stream, 16, 255);
      v65 = ((__int64 (__fastcall *)(hkStreamWriter *))context->m_stream->vfptr[4].__vecDelDtor)(context->m_stream);
      v66 = 0;
      v67 = 0i64;
      *((_DWORD *)v34 + 9) = v65 - *((_DWORD *)v34 + 5);
      m_hashMod = v3->m_exports.m_map.m_hashMod;
      if ( m_hashMod >= 0 )
      {
        m_elem = v3->m_exports.m_map.m_elem;
        do
        {
          if ( m_elem->key != -1i64 )
            break;
          ++v67;
          ++v66;
          ++m_elem;
        }
        while ( v67 <= m_hashMod );
      }
      v70 = v66;
      v71 = 0;
      if ( v66 <= v3->m_exports.m_map.m_hashMod )
      {
        do
        {
          v72 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  &v3->m_knownObjects.m_map,
                  v3->m_exports.m_map.m_elem[v70].key,
                  0xFFFFFFFFFFFFFFFFui64);
          if ( v72 >= 0 && v3->m_pendingWrites.m_data[v72].m_sectionIndex == v30 )
          {
            v71 = 1;
            val = (const char *)v3->m_exports.m_map.m_elem[v70].val;
            hkOArchive::write32(&v88, context->m_locations.m_data[v72].m_offset);
            v74 = hkString::strLen(val);
            hkOArchive::writeRaw(&v88, val, (unsigned int)(v74 + 1));
            padUp(context->m_stream, 4, 255);
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
          hkOArchive::write32(&v88, -1);
          padUp(context->m_stream, 16, 255);
        }
      }
      v79 = 0;
      *((_DWORD *)v34 + 10) = ((__int64 (__fastcall *)(hkStreamWriter *))context->m_stream->vfptr[4].__vecDelDtor)(context->m_stream)
                            - *((_DWORD *)v34 + 5);
      v80 = ptr.m_imports.m_size == 0;
      if ( ptr.m_imports.m_size > 0 )
      {
        v81 = 0i64;
        do
        {
          v82 = ptr.m_imports.m_data;
          hkOArchive::write32(&v88, ptr.m_imports.m_data[v81].m_fromOffset);
          v83 = hkString::strLen(v82[v81].m_identifier);
          hkOArchive::writeRaw(&v88, v82[v81].m_identifier, (unsigned int)(v83 + 1));
          padUp(context->m_stream, 4, 255);
          ++v79;
          ++v81;
        }
        while ( v79 < ptr.m_imports.m_size );
        v80 = ptr.m_imports.m_size == 0;
      }
      if ( !v80 )
      {
        hkOArchive::write32(&v88, -1);
        hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
          (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)((char *)&context->m_relocsBySect.m_data->m_imports
                                                                       + result),
          &ptr.m_imports);
        padUp(context->m_stream, 16, 255);
      }
      *((_DWORD *)v34 + 11) = ((__int64 (__fastcall *)(hkStreamWriter *))context->m_stream->vfptr[4].__vecDelDtor)(context->m_stream)
                            - *((_DWORD *)v34 + 5);
      hkOArchive::~hkOArchive(&v88);
      hkRelocationInfo::~hkRelocationInfo(&ptr);
      v31 = v97;
      ++v30;
      v32 = v90 + 1;
      v33 = v89 + 64;
      p_m_locations = &context->m_locations;
      ++v90;
      LODWORD(result) = v30;
      v89 += 64i64;
    }
    while ( v30 < context->m_sectionHeaders.m_size );
  }
}

// File Line: 420
// RVA: 0xE4C4D0
void __fastcall hkBinaryPackfileWriter::doDeferredWrites(
        hkBinaryPackfileWriter *this,
        hkBinaryPackfileWriter::SaveContext *context,
        unsigned int sectionHeadersStart)
{
  hkBinaryPackfileWriter::SaveContext *v3; // rbx
  hkBinaryPackfileWriter *v4; // r15
  __int64 v5; // r14
  __int64 v6; // r12
  char *v7; // r13
  unsigned int *v8; // rdx
  char *v9; // r14
  int v10; // ecx
  int v11; // esi
  unsigned int *v12; // rdi
  int v13; // eax
  __int64 v14; // rcx
  int v15; // esi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *p_m_map; // r12
  __int64 v17; // rdi
  __int64 v18; // r15
  int v19; // eax
  __int64 v20; // rdx
  int v21; // r15d
  hkPackfileSectionHeader *m_data; // r13
  __int64 v23; // r14
  char *v24; // rsi
  char *v25; // r13
  int v26; // edi
  __int64 v27; // rdi
  __int64 v28; // r14
  unsigned int v29; // eax
  int i; // edi
  hkBaseObjectVtbl *vfptr; // rax
  hkStreamWriter *m_stream; // r8
  __int64 m_sectionTag; // r9
  hkStructureLayout *Layout; // rax
  hkClass *m_pointer; // rdi
  const char *Name; // rax
  int v37; // eax
  unsigned int *array; // [rsp+30h] [rbp-D0h] BYREF
  signed __int64 nelem; // [rsp+38h] [rbp-C8h]
  unsigned int *v40; // [rsp+40h] [rbp-C0h] BYREF
  signed __int64 v41; // [rsp+48h] [rbp-B8h]
  __int64 v42; // [rsp+50h] [rbp-B0h]
  hkResult v43; // [rsp+58h] [rbp-A8h] BYREF
  __int64 v44; // [rsp+60h] [rbp-A0h]
  hkResult result; // [rsp+68h] [rbp-98h] BYREF
  char v46[4]; // [rsp+6Ch] [rbp-94h] BYREF
  char v47[16]; // [rsp+70h] [rbp-90h] BYREF
  hkRelocationInfo v48; // [rsp+80h] [rbp-80h] BYREF
  hkOArchive v49; // [rsp+D0h] [rbp-30h] BYREF
  hkOArchive v50; // [rsp+F0h] [rbp-10h] BYREF
  hkBinaryPackfileWriter *v51; // [rsp+160h] [rbp+60h] BYREF
  hkBinaryPackfileWriter::SaveContext *v52; // [rsp+168h] [rbp+68h]
  unsigned int v53; // [rsp+170h] [rbp+70h]
  int v54; // [rsp+178h] [rbp+78h]

  v53 = sectionHeadersStart;
  v52 = context;
  v51 = this;
  v3 = context;
  v4 = this;
  hkOArchive::hkOArchive(&v50, context->m_stream, context->m_endianSwapRequired);
  v54 = 0;
  if ( v3->m_sectionHeaders.m_size > 0 )
  {
    v42 = 0i64;
    v5 = 0i64;
    v6 = 0i64;
    v44 = 0i64;
    do
    {
      v7 = &v3->m_sectionHeaders.m_data->m_sectionTag[v5];
      v8 = 0i64;
      v9 = (char *)v3->m_relocsBySect.m_data + v6;
      v10 = 0;
      array = 0i64;
      nelem = 0x8000000000000000ui64;
      v11 = 3 * *((_DWORD *)v9 + 6);
      if ( v11 <= 0 )
      {
        result.m_enum = HK_SUCCESS;
      }
      else
      {
        hkArrayUtil::_reserve(
          &result,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&array,
          3 * *((_DWORD *)v9 + 6),
          4);
        v10 = nelem;
        v8 = array;
      }
      v12 = &v8[v10];
      v13 = v11 - v10;
      v14 = v11 - v10;
      if ( v13 > 0 )
      {
        while ( v14 )
        {
          *v12++ = -1;
          --v14;
        }
      }
      LODWORD(nelem) = v11;
      v15 = 0;
      if ( *((int *)v9 + 6) > 0 )
      {
        p_m_map = &v4->m_knownObjects.m_map;
        v17 = 0i64;
        v18 = 2i64;
        do
        {
          v19 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  p_m_map,
                  *(_QWORD *)(*((_QWORD *)v9 + 2) + v17 + 8),
                  0xFFFFFFFFFFFFFFFDui64);
          if ( v19 >= 0 )
          {
            v20 = v19;
            if ( v3->m_locations.m_data[v20].m_sectionIndex >= 0 )
            {
              v18 += 3i64;
              array[v18 - 5] = *(_DWORD *)(*((_QWORD *)v9 + 2) + v17) - *((_DWORD *)v7 + 5);
              array[v18 - 4] = v3->m_locations.m_data[v20].m_sectionIndex;
              array[v18 - 3] = v3->m_locations.m_data[v20].m_offset;
            }
          }
          ++v15;
          v17 += 32i64;
        }
        while ( v15 < *((_DWORD *)v9 + 6) );
        v6 = v42;
      }
      ((void (__fastcall *)(hkStreamWriter *, char *, _QWORD, _QWORD))v3->m_stream->vfptr[3].__first_virtual_table_function__)(
        v3->m_stream,
        v46,
        (unsigned int)(*((_DWORD *)v7 + 5) + *((_DWORD *)v7 + 7)),
        0i64);
      hkOArchive::writeArray32u(&v50, array, nelem);
      v21 = 0;
      LODWORD(nelem) = 0;
      if ( nelem >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * HIDWORD(nelem));
      m_data = v3->m_sectionHeaders.m_data;
      v23 = v44;
      v24 = (char *)v3->m_relocsBySect.m_data + v6;
      v40 = 0i64;
      v41 = 0x8000000000000000ui64;
      v25 = &m_data->m_sectionTag[v44];
      v26 = 3 * *((_DWORD *)v24 + 10);
      array = 0i64;
      HIDWORD(nelem) = 0x80000000;
      if ( v26 <= 0 )
        v43.m_enum = HK_SUCCESS;
      else
        hkArrayUtil::_reserve(&v43, &hkContainerHeapAllocator::s_alloc, (const void **)&v40, v26, 4);
      LODWORD(v41) = v26;
      if ( *((int *)v24 + 10) > 0 )
      {
        v27 = 2i64;
        v28 = 0i64;
        do
        {
          v40[v27 - 2] = *(_DWORD *)(*((_QWORD *)v24 + 4) + v28) - *((_DWORD *)v25 + 5);
          v40[v27 - 1] = 0;
          v29 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                  (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_usedClassNames,
                  *(const char **)(*((_QWORD *)v24 + 4) + v28 + 8),
                  0xFFFFFFFFFFFFFFFFui64);
          ++v21;
          v40[v27] = v29;
          v28 += 16i64;
          v27 += 3i64;
        }
        while ( v21 < *((_DWORD *)v24 + 10) );
        v3 = v52;
        v6 = v42;
        v23 = v44;
      }
      ((void (__fastcall *)(hkStreamWriter *, char *, _QWORD, _QWORD))v3->m_stream->vfptr[3].__first_virtual_table_function__)(
        v3->m_stream,
        v47,
        (unsigned int)(*((_DWORD *)v25 + 5) + *((_DWORD *)v25 + 8)),
        0i64);
      hkOArchive::writeArray32u(&v50, v40, v41);
      LODWORD(v41) = 0;
      if ( v41 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v40, 4 * HIDWORD(v41));
      v4 = v51;
      v5 = v23 + 64;
      v6 += 72i64;
      v40 = 0i64;
      HIDWORD(v41) = 0x80000000;
      v44 = v5;
      ++v54;
      v42 = v6;
    }
    while ( v54 < v3->m_sectionHeaders.m_size );
  }
  ((void (__fastcall *)(hkStreamWriter *, hkBinaryPackfileWriter **, _QWORD, _QWORD))v3->m_stream->vfptr[3].__first_virtual_table_function__)(
    v3->m_stream,
    &v51,
    v53,
    0i64);
  for ( i = 0; i < v3->m_sectionHeaders.m_size; ++i )
  {
    vfptr = v3->m_writer.vfptr;
    m_stream = v3->m_stream;
    v48.m_local.m_data = 0i64;
    m_sectionTag = (__int64)v3->m_sectionHeaders.m_data[(__int64)i].m_sectionTag;
    v48.m_local.m_size = 0;
    v48.m_local.m_capacityAndFlags = 0x80000000;
    v48.m_global.m_data = 0i64;
    v48.m_global.m_size = 0;
    v48.m_global.m_capacityAndFlags = 0x80000000;
    v48.m_finish.m_data = 0i64;
    v48.m_finish.m_size = 0;
    v48.m_finish.m_capacityAndFlags = 0x80000000;
    v48.m_imports.m_data = 0i64;
    v48.m_imports.m_size = 0;
    v48.m_imports.m_capacityAndFlags = 0x80000000;
    v48.m_pool = 0i64;
    ((void (__fastcall *)(hkPlatformObjectWriter *, hkBinaryPackfileWriter **, hkStreamWriter *, __int64, hkClass *, hkRelocationInfo *, unsigned int *, signed __int64, unsigned int *, signed __int64))vfptr[1].__first_virtual_table_function__)(
      &v3->m_writer,
      &v51,
      m_stream,
      m_sectionTag,
      &hkPackfileSectionHeaderClass,
      &v48,
      array,
      nelem,
      v40,
      v41);
    hkRelocationInfo::~hkRelocationInfo(&v48);
  }
  ((void (__fastcall *)(hkStreamWriter *, hkBinaryPackfileWriter **, __int64))v3->m_stream->vfptr[3].__first_virtual_table_function__)(
    v3->m_stream,
    &v51,
    24i64);
  Layout = hkPlatformObjectWriter::getLayout(&v3->m_writer);
  hkOArchive::hkOArchive(
    &v49,
    v3->m_stream,
    (hkBool)(BYTE1(*(_DWORD *)Layout) != hkStructureLayout::HostLayoutRules.m_littleEndian));
  hkOArchive::write32(&v49, v3->m_locations.m_data[v4->m_contentsPtrPWIndex].m_sectionIndex);
  hkOArchive::write32(&v49, v3->m_locations.m_data[v4->m_contentsPtrPWIndex].m_offset);
  m_pointer = (hkClass *)v4->m_pendingWrites.m_data[v4->m_contentsClassPWIndex].m_pointer;
  hkOArchive::write32(&v49, 0);
  Name = hkClass::getName(m_pointer);
  v37 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
          (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_usedClassNames,
          Name,
          0xFFFFFFFFFFFFFFFFui64);
  hkOArchive::write32(&v49, v37);
  hkOArchive::~hkOArchive(&v49);
  hkOArchive::~hkOArchive(&v50);
}

// File Line: 495
// RVA: 0xE4B830
hkResult *__fastcall hkBinaryPackfileWriter::save(
        hkBinaryPackfileWriter *this,
        hkResult *result,
        hkStreamWriter *origStream,
        hkPackfileWriter::Options *options)
{
  char m_littleEndian; // al
  int v9; // edi
  unsigned int ArraySizeIn; // eax
  unsigned int v11; // ebx
  void **v13; // [rsp+20h] [rbp-69h] BYREF
  int v14; // [rsp+28h] [rbp-61h]
  hkStreamWriter *v15; // [rsp+30h] [rbp-59h]
  int v16; // [rsp+38h] [rbp-51h]
  hkBinaryPackfileWriter::SaveContext context; // [rsp+40h] [rbp-49h] BYREF
  char v18; // [rsp+100h] [rbp+77h] BYREF

  if ( *(_BYTE *)origStream->vfptr[3].__vecDelDtor(origStream, &v18) )
  {
    context.m_options = options;
    context.m_sectionHeaders.m_data = 0i64;
    context.m_sectionHeaders.m_size = 0;
    context.m_sectionHeaders.m_capacityAndFlags = 0x80000000;
    context.m_locations.m_data = 0i64;
    context.m_locations.m_size = 0;
    context.m_locations.m_capacityAndFlags = 0x80000000;
    hkPlatformObjectWriter::hkPlatformObjectWriter(
      &context.m_writer,
      &options->m_layout,
      0i64,
      (hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int>)2);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      &context.m_usedClassNames.m_map,
      0);
    m_littleEndian = options->m_layout.m_rules.m_littleEndian;
    context.m_relocsBySect.m_data = 0i64;
    context.m_relocsBySect.m_size = 0;
    v13 = &hkSubStreamWriter::`vftable;
    context.m_relocsBySect.m_capacityAndFlags = 0x80000000;
    v14 = 0x1FFFF;
    context.m_endianSwapRequired.m_bool = hkStructureLayout::HostLayoutRules.m_littleEndian != (unsigned __int8)m_littleEndian;
    v15 = origStream;
    v16 = ((__int64 (__fastcall *)(hkStreamWriter *))origStream->vfptr[4].__vecDelDtor)(origStream);
    context.m_stream = (hkStreamWriter *)&v13;
    hkBinaryPackfileWriter::fillSectionTags(this, &context);
    saveFileHeader(&context.m_writer, context.m_stream, options, context.m_sectionHeaders.m_size);
    v9 = ((__int64 (__fastcall *)(void ***))v13[8])(&v13);
    ArraySizeIn = `anonymous namespace::getArraySizeInBytes<hkPackfileSectionHeader>(&context.m_sectionHeaders);
    ((void (__fastcall *)(void ***, char *, _QWORD, __int64))v13[7])(&v13, &v18, ArraySizeIn, 1i64);
    hkBinaryPackfileWriter::writeAllObjects(this, &context);
    v11 = ((__int64 (__fastcall *)(void ***))v13[8])(&v13);
    hkBinaryPackfileWriter::doDeferredWrites(this, &context, v9);
    ((void (__fastcall *)(void ***, char *, _QWORD, _QWORD))v13[7])(&v13, &v18, v11, 0i64);
    ((void (__fastcall *)(void ***))v13[5])(&v13);
    result->m_enum = *(_BYTE *)((__int64 (__fastcall *)(void ***, char *))v13[3])(&v13, &v18) == 0;
    v13 = &hkBaseObject::`vftable;
    hkBinaryPackfileWriter::SaveContext::~SaveContext(&context);
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
  return result;
}

