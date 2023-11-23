// File Line: 120
// RVA: 0xE778E0
hkResult *__fastcall hkVersionReporter::sendVersionInformation(hkResult *result, hkStreamWriter *connection)
{
  int v4; // ebx
  unsigned int v5; // ebx
  hkArray<char,hkContainerHeapAllocator> buf; // [rsp+20h] [rbp-99h] BYREF
  hkDisplaySerializeOStream v8; // [rsp+30h] [rbp-89h] BYREF
  hkDisplaySerializeOStream v9; // [rsp+50h] [rbp-69h] BYREF
  hkStringBuf v10; // [rsp+70h] [rbp-49h] BYREF

  buf.m_capacityAndFlags = 0x80000000;
  buf.m_data = 0i64;
  buf.m_size = 0;
  hkDisplaySerializeOStream::hkDisplaySerializeOStream(&v8, &buf);
  hkOArchive::write8u(&v8, 144);
  hkOArchive::write32(&v8, hkVersionReporter::m_protocolVersion);
  hkOArchive::write32(&v8, hkVersionReporter::m_protocolMinimumCompatible);
  v4 = hkString::strLen("PC_64");
  if ( v4 > 0xFFFF )
    v4 = 0xFFFF;
  hkOArchive::write16u(&v8, v4);
  hkOArchive::writeRaw(&v8, "PC_64", (unsigned int)v4);
  v10.m_string.m_data = v10.m_string.m_storage;
  v10.m_string.m_capacityAndFlags = -2147483520;
  v10.m_string.m_size = 1;
  v10.m_string.m_storage[0] = 0;
  hkStringBuf::printf(&v10, "%s:%i", "MSVC", 1700i64);
  v5 = v10.m_string.m_size - 1;
  if ( v10.m_string.m_size - 1 > 0xFFFF )
    v5 = 0xFFFF;
  hkOArchive::write16u(&v8, v5);
  hkOArchive::writeRaw(&v8, v10.m_string.m_data, v5);
  hkDisplaySerializeOStream::hkDisplaySerializeOStream(&v9, connection);
  hkOArchive::write32(&v9, buf.m_size);
  hkOArchive::writeRaw(&v9, buf.m_data, (unsigned int)buf.m_size);
  result->m_enum = HK_SUCCESS;
  hkOArchive::~hkOArchive(&v9);
  v10.m_string.m_size = 0;
  if ( v10.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v10.m_string.m_data,
      v10.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  v10.m_string.m_data = 0i64;
  v10.m_string.m_capacityAndFlags = 0x80000000;
  hkOArchive::~hkOArchive(&v8);
  buf.m_size = 0;
  if ( buf.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      buf.m_data,
      buf.m_capacityAndFlags & 0x3FFFFFFF);
  return result;
}

// File Line: 171
// RVA: 0xE77AC0
hkResult *__fastcall hkVersionReporter::sendStructureLayout(hkResult *result, hkStreamWriter *connection)
{
  hkDisplaySerializeOStream v4; // [rsp+20h] [rbp-28h] BYREF

  hkDisplaySerializeOStream::hkDisplaySerializeOStream(&v4, connection);
  hkOArchive::write32u(&v4, 5u);
  hkOArchive::write8u(&v4, 145);
  hkOArchive::write8u(&v4, hkStructureLayout::HostLayoutRules.m_bytesInPointer);
  hkOArchive::write8u(&v4, hkStructureLayout::HostLayoutRules.m_littleEndian);
  hkOArchive::write8u(&v4, hkStructureLayout::HostLayoutRules.m_reusePaddingOptimization);
  hkOArchive::write8u(&v4, hkStructureLayout::HostLayoutRules.m_emptyBaseClassOptimization);
  result->m_enum = HK_SUCCESS;
  hkOArchive::~hkOArchive(&v4);
  return result;
}

// File Line: 188
// RVA: 0xE77B60
hkResult *__fastcall hkVersionReporter::receiveVersionInformation(
        hkResult *result,
        hkStreamReader *connection,
        int *protocolVersion,
        int *protocolMinimumCompatible,
        hkStringPtr *platformString,
        hkStringPtr *compilerString)
{
  hkDisplaySerializeIStream chunkStream; // [rsp+30h] [rbp-28h] BYREF

  hkDisplaySerializeIStream::hkDisplaySerializeIStream(&chunkStream, connection);
  hkVersionReporter::receiveVersionInformation(
    result,
    &chunkStream,
    protocolVersion,
    protocolMinimumCompatible,
    platformString,
    compilerString);
  hkIArchive::~hkIArchive(&chunkStream);
  return result;
}

// File Line: 194
// RVA: 0xE77BE0
hkResult *__fastcall hkVersionReporter::receiveVersionInformation(
        hkResult *result,
        hkDisplaySerializeIStream *chunkStream,
        hkResultEnum *protocolVersion,
        hkResultEnum *protocolMinimumCompatible,
        hkStringPtr *platformString,
        hkStringPtr *compilerString)
{
  __int64 m_enum_low; // rsi
  char *v11; // rdx
  int v12; // ebx
  int v13; // r9d
  hkStringPtr *v14; // rcx
  __int64 v15; // rsi
  int v16; // ebx
  int v17; // r9d
  const char *v18; // rdx
  int v19; // r8d
  void *buf; // [rsp+30h] [rbp-D0h] BYREF
  int v22; // [rsp+38h] [rbp-C8h]
  int v23; // [rsp+3Ch] [rbp-C4h]
  char v24[4096]; // [rsp+40h] [rbp-C0h] BYREF
  hkResult array; // [rsp+1060h] [rbp+F60h] BYREF

  hkIArchive::readArrayGeneric(chunkStream, &array, 4, 1);
  *(hkResult *)protocolVersion = array;
  hkIArchive::readArrayGeneric(chunkStream, &array, 4, 1);
  *(hkResult *)protocolMinimumCompatible = array;
  hkIArchive::readArrayGeneric(chunkStream, &array, 2, 1);
  m_enum_low = LOWORD(array.m_enum);
  v11 = v24;
  v12 = LOWORD(array.m_enum) + 1;
  buf = v24;
  v22 = 0;
  v23 = -2147479552;
  if ( v12 > 4096 )
  {
    v13 = LOWORD(array.m_enum) + 1;
    if ( v12 < 0x2000 )
      v13 = 0x2000;
    hkArrayUtil::_reserve(&array, &hkContainerHeapAllocator::s_alloc, (const void **)&buf, v13, 1);
    v11 = (char *)buf;
  }
  v22 = v12;
  hkIArchive::readRaw(chunkStream, v11, m_enum_low);
  v14 = platformString;
  *((_BYTE *)buf + m_enum_low) = 0;
  hkStringPtr::operator=(v14, (const char *)buf);
  if ( *(int *)protocolVersion < 7001 )
  {
    v18 = "UNAVAILABLE";
  }
  else
  {
    hkIArchive::readArrayGeneric(chunkStream, &array, 2, 1);
    v15 = LOWORD(array.m_enum);
    v16 = LOWORD(array.m_enum) + 1;
    if ( (v23 & 0x3FFFFFFF) < v16 )
    {
      v17 = LOWORD(array.m_enum) + 1;
      if ( v16 < 2 * (v23 & 0x3FFFFFFF) )
        v17 = 2 * (v23 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&array, &hkContainerHeapAllocator::s_alloc, (const void **)&buf, v17, 1);
    }
    v22 = v16;
    hkIArchive::readRaw(chunkStream, buf, v15);
    *((_BYTE *)buf + v15) = 0;
    v18 = (const char *)buf;
  }
  hkStringPtr::operator=(compilerString, v18);
  v19 = v23;
  result->m_enum = HK_SUCCESS;
  v22 = 0;
  if ( v19 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, buf, v19 & 0x3FFFFFFF);
  return result;
}

