// File Line: 120
// RVA: 0xE778E0
hkResult *__fastcall hkVersionReporter::sendVersionInformation(hkResult *result, hkStreamWriter *connection)
{
  hkStreamWriter *v2; // rdi
  hkResult *v3; // rsi
  signed int v4; // ebx
  unsigned int v5; // ebx
  hkArray<char,hkContainerHeapAllocator> buf; // [rsp+20h] [rbp-99h]
  hkDisplaySerializeOStream v8; // [rsp+30h] [rbp-89h]
  hkDisplaySerializeOStream v9; // [rsp+50h] [rbp-69h]
  hkStringBuf v10; // [rsp+70h] [rbp-49h]

  v2 = connection;
  v3 = result;
  buf.m_capacityAndFlags = 2147483648;
  buf.m_data = 0i64;
  buf.m_size = 0;
  hkDisplaySerializeOStream::hkDisplaySerializeOStream(&v8, &buf);
  hkOArchive::write8u((hkOArchive *)&v8.vfptr, 144);
  hkOArchive::write32((hkOArchive *)&v8.vfptr, hkVersionReporter::m_protocolVersion);
  hkOArchive::write32((hkOArchive *)&v8.vfptr, hkVersionReporter::m_protocolMinimumCompatible);
  v4 = hkString::strLen("PC_64");
  if ( v4 > 0xFFFF )
    v4 = 0xFFFF;
  hkOArchive::write16u((hkOArchive *)&v8.vfptr, v4);
  hkOArchive::writeRaw((hkOArchive *)&v8.vfptr, "PC_64", (unsigned int)v4);
  v10.m_string.m_data = v10.m_string.m_storage;
  v10.m_string.m_capacityAndFlags = -2147483520;
  v10.m_string.m_size = 1;
  v10.m_string.m_storage[0] = 0;
  hkStringBuf::printf(&v10, "%s:%i", "MSVC", 1700i64);
  v5 = v10.m_string.m_size - 1;
  if ( v10.m_string.m_size - 1 > 0xFFFF )
    v5 = 0xFFFF;
  hkOArchive::write16u((hkOArchive *)&v8.vfptr, v5);
  hkOArchive::writeRaw((hkOArchive *)&v8.vfptr, v10.m_string.m_data, v5);
  hkDisplaySerializeOStream::hkDisplaySerializeOStream(&v9, v2);
  hkOArchive::write32((hkOArchive *)&v9.vfptr, buf.m_size);
  hkOArchive::writeRaw((hkOArchive *)&v9.vfptr, buf.m_data, (unsigned int)buf.m_size);
  v3->m_enum = 0;
  hkOArchive::~hkOArchive((hkOArchive *)&v9.vfptr);
  v10.m_string.m_size = 0;
  if ( v10.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v10.m_string.m_data,
      v10.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  v10.m_string.m_data = 0i64;
  v10.m_string.m_capacityAndFlags = 2147483648;
  hkOArchive::~hkOArchive((hkOArchive *)&v8.vfptr);
  buf.m_size = 0;
  if ( buf.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      buf.m_data,
      buf.m_capacityAndFlags & 0x3FFFFFFF);
  return v3;
}

// File Line: 171
// RVA: 0xE77AC0
hkResult *__fastcall hkVersionReporter::sendStructureLayout(hkResult *result, hkStreamWriter *connection)
{
  hkResult *v2; // rbx
  hkDisplaySerializeOStream v4; // [rsp+20h] [rbp-28h]

  v2 = result;
  hkDisplaySerializeOStream::hkDisplaySerializeOStream(&v4, connection);
  hkOArchive::write32u((hkOArchive *)&v4.vfptr, 5u);
  hkOArchive::write8u((hkOArchive *)&v4.vfptr, 145);
  hkOArchive::write8u((hkOArchive *)&v4.vfptr, hkStructureLayout::HostLayoutRules.m_bytesInPointer);
  hkOArchive::write8u((hkOArchive *)&v4.vfptr, hkStructureLayout::HostLayoutRules.m_littleEndian);
  hkOArchive::write8u((hkOArchive *)&v4.vfptr, hkStructureLayout::HostLayoutRules.m_reusePaddingOptimization);
  hkOArchive::write8u((hkOArchive *)&v4.vfptr, hkStructureLayout::HostLayoutRules.m_emptyBaseClassOptimization);
  v2->m_enum = 0;
  hkOArchive::~hkOArchive((hkOArchive *)&v4.vfptr);
  return v2;
}

// File Line: 188
// RVA: 0xE77B60
hkResult *__fastcall hkVersionReporter::receiveVersionInformation(hkResult *result, hkStreamReader *connection, int *protocolVersion, int *protocolMinimumCompatible, hkStringPtr *platformString, hkStringPtr *compilerString)
{
  hkResult *v6; // rsi
  int *v7; // rbx
  int *v8; // rdi
  hkDisplaySerializeIStream chunkStream; // [rsp+30h] [rbp-28h]

  v6 = result;
  v7 = protocolMinimumCompatible;
  v8 = protocolVersion;
  hkDisplaySerializeIStream::hkDisplaySerializeIStream(&chunkStream, connection);
  hkVersionReporter::receiveVersionInformation(v6, &chunkStream, v8, v7, platformString, compilerString);
  hkIArchive::~hkIArchive((hkIArchive *)&chunkStream.vfptr);
  return v6;
}

// File Line: 194
// RVA: 0xE77BE0
hkResult *__fastcall hkVersionReporter::receiveVersionInformation(hkResult *result, hkDisplaySerializeIStream *chunkStream, int *protocolVersion, int *protocolMinimumCompatible, hkStringPtr *platformString, hkStringPtr *compilerString)
{
  hkDisplaySerializeIStream *v6; // r14
  int *v7; // rbx
  int *v8; // r15
  hkResult *v9; // rdi
  __int64 v10; // rsi
  char *v11; // rdx
  int v12; // ebx
  int v13; // er9
  hkStringPtr *v14; // rcx
  __int64 v15; // rsi
  int v16; // ebx
  int v17; // er9
  const char *v18; // rdx
  int v19; // er8
  void *buf; // [rsp+30h] [rbp-D0h]
  int v22; // [rsp+38h] [rbp-C8h]
  int v23; // [rsp+3Ch] [rbp-C4h]
  char v24; // [rsp+40h] [rbp-C0h]
  int array; // [rsp+1060h] [rbp+F60h]

  v6 = chunkStream;
  v7 = protocolMinimumCompatible;
  v8 = protocolVersion;
  v9 = result;
  hkIArchive::readArrayGeneric((hkIArchive *)&chunkStream->vfptr, &array, 4, 1);
  *v8 = array;
  hkIArchive::readArrayGeneric((hkIArchive *)&v6->vfptr, &array, 4, 1);
  *v7 = array;
  hkIArchive::readArrayGeneric((hkIArchive *)&v6->vfptr, &array, 2, 1);
  v10 = (unsigned __int16)array;
  v11 = &v24;
  v12 = (unsigned __int16)array + 1;
  buf = &v24;
  v22 = 0;
  v23 = -2147479552;
  if ( v12 > 4096 )
  {
    v13 = (unsigned __int16)array + 1;
    if ( v12 < 0x2000 )
      v13 = 0x2000;
    hkArrayUtil::_reserve(
      (hkResult *)&array,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &buf,
      v13,
      1);
    v11 = (char *)buf;
  }
  v22 = v12;
  hkIArchive::readRaw((hkIArchive *)&v6->vfptr, v11, v10);
  v14 = platformString;
  *((_BYTE *)buf + v10) = 0;
  hkStringPtr::operator=(v14, (const char *)buf);
  if ( *v8 < 7001 )
  {
    v18 = "UNAVAILABLE";
  }
  else
  {
    hkIArchive::readArrayGeneric((hkIArchive *)&v6->vfptr, &array, 2, 1);
    v15 = (unsigned __int16)array;
    v16 = (unsigned __int16)array + 1;
    if ( (v23 & 0x3FFFFFFF) < v16 )
    {
      v17 = (unsigned __int16)array + 1;
      if ( v16 < 2 * (v23 & 0x3FFFFFFF) )
        v17 = 2 * (v23 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(
        (hkResult *)&array,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &buf,
        v17,
        1);
    }
    v22 = v16;
    hkIArchive::readRaw((hkIArchive *)&v6->vfptr, buf, v15);
    *((_BYTE *)buf + v15) = 0;
    v18 = (const char *)buf;
  }
  hkStringPtr::operator=(compilerString, v18);
  v19 = v23;
  v9->m_enum = 0;
  v22 = 0;
  if ( v19 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      buf,
      v19 & 0x3FFFFFFF);
  return v9;
}

