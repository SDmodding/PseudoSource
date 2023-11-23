// File Line: 25
// RVA: 0xE7A660
void __fastcall hkServerDebugDisplayHandler::hkServerDebugDisplayHandler(
        hkServerDebugDisplayHandler *this,
        hkDisplaySerializeOStream *outStream,
        hkDisplaySerializeIStream *inStream)
{
  _QWORD **Value; // rax
  hkCriticalSection *v5; // rax
  hkCriticalSection *v6; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_selectable.m_bool = 0;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkServerDebugDisplayHandler::`vftable{for `hkReferencedObject};
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkServerDebugDisplayHandler::`vftable{for `hkProcess};
  this->hkDebugDisplayHandler::vfptr = (hkDebugDisplayHandlerVtbl *)&hkServerDebugDisplayHandler::`vftable{for `hkDebugDisplayHandler};
  this->m_geometriesAwaitingRequests.m_data = 0i64;
  this->m_geometriesAwaitingRequests.m_size = 0;
  this->m_geometriesAwaitingRequests.m_capacityAndFlags = 0x80000000;
  this->m_geometriesAwaitingDeparture.m_data = 0i64;
  this->m_geometriesAwaitingDeparture.m_size = 0;
  this->m_geometriesAwaitingDeparture.m_capacityAndFlags = 0x80000000;
  this->m_continueData = 0i64;
  this->m_hashCountMap.m_map.m_elem = 0i64;
  this->m_hashCountMap.m_map.m_numElems = 0;
  this->m_hashCountMap.m_map.m_hashMod = -1;
  *(_QWORD *)&this->m_simpleShapesPerPart = 0i64;
  this->m_sendHashes.m_bool = 0;
  this->m_outStream = outStream;
  this->m_inStream = inStream;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  if ( v5 )
  {
    hkCriticalSection::hkCriticalSection(v5, 0x3E8u);
    this->m_outstreamLock = v6;
  }
  else
  {
    this->m_outstreamLock = 0i64;
  }
}

// File Line: 32
// RVA: 0xE7A740
void __fastcall hkServerDebugDisplayHandler::~hkServerDebugDisplayHandler(hkServerDebugDisplayHandler *this)
{
  hkCriticalSection *m_outstreamLock; // rdi
  _QWORD **Value; // rax
  __int64 m_size; // rsi
  __int64 v5; // rdi
  __int64 v6; // rsi
  __int64 v7; // rdi
  hkReferencedObject *m_continueData; // rcx
  int m_capacityAndFlags; // eax
  int v10; // eax

  m_outstreamLock = this->m_outstreamLock;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkServerDebugDisplayHandler::`vftable{for `hkReferencedObject};
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkServerDebugDisplayHandler::`vftable{for `hkProcess};
  this->hkDebugDisplayHandler::vfptr = (hkDebugDisplayHandlerVtbl *)&hkServerDebugDisplayHandler::`vftable{for `hkDebugDisplayHandler};
  if ( m_outstreamLock )
  {
    DeleteCriticalSection(&m_outstreamLock->m_section);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkCriticalSection *, __int64))(*Value[11] + 16i64))(
      Value[11],
      m_outstreamLock,
      40i64);
  }
  m_size = this->m_geometriesAwaitingRequests.m_size;
  if ( m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_geometriesAwaitingRequests.m_data[v5].m_builder);
      hkReferencedObject::removeReference(this->m_geometriesAwaitingRequests.m_data[v5++].m_source);
      --m_size;
    }
    while ( m_size );
  }
  v6 = this->m_geometriesAwaitingDeparture.m_size;
  if ( v6 > 0 )
  {
    v7 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_geometriesAwaitingDeparture.m_data[v7].m_builder);
      hkReferencedObject::removeReference(this->m_geometriesAwaitingDeparture.m_data[v7++].m_source);
      --v6;
    }
    while ( v6 );
  }
  m_continueData = this->m_continueData;
  if ( m_continueData )
    hkReferencedObject::removeReference(m_continueData);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_hashCountMap.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_hashCountMap);
  m_capacityAndFlags = this->m_geometriesAwaitingDeparture.m_capacityAndFlags;
  this->m_geometriesAwaitingDeparture.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_geometriesAwaitingDeparture.m_data,
      24 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_geometriesAwaitingDeparture.m_data = 0i64;
  this->m_geometriesAwaitingDeparture.m_capacityAndFlags = 0x80000000;
  v10 = this->m_geometriesAwaitingRequests.m_capacityAndFlags;
  this->m_geometriesAwaitingRequests.m_size = 0;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_geometriesAwaitingRequests.m_data,
      24 * (v10 & 0x3FFFFFFF));
  this->m_geometriesAwaitingRequests.m_data = 0i64;
  this->m_geometriesAwaitingRequests.m_capacityAndFlags = 0x80000000;
  this->hkDebugDisplayHandler::vfptr = (hkDebugDisplayHandlerVtbl *)&hkDebugDisplayHandler::`vftable;
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkProcess::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 57
// RVA: 0xE7CB30
__int64 __fastcall getGeometryByteSize(hkArrayBase<hkDisplayGeometry *> *geometries)
{
  int v1; // edi
  unsigned int v3; // ebx
  __int64 v4; // rsi
  int v5; // eax

  v1 = 0;
  v3 = 4;
  if ( geometries->m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = hkDisplaySerializeOStream::computeBytesRequired((hkDisplayMesh *)geometries->m_data[v4]);
      ++v1;
      ++v4;
      v3 += v5;
    }
    while ( v1 < geometries->m_size );
  }
  return v3;
}

// File Line: 67
// RVA: 0xE7BE80
void __fastcall hkServerDebugDisplayHandler::sendGeometryData(
        hkServerDebugDisplayHandler *this,
        hkArrayBase<hkDisplayGeometry *> *geometries)
{
  int v4; // ebx
  __int64 v5; // rdi

  EnterCriticalSection(&this->m_outstreamLock->m_section);
  hkOArchive::write32(this->m_outStream, geometries->m_size);
  v4 = 0;
  if ( geometries->m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      hkDisplaySerializeOStream::writeDisplayGeometry(this->m_outStream, (hkDisplayAABB *)geometries->m_data[v5]);
      ++v4;
      ++v5;
    }
    while ( v4 < geometries->m_size );
  }
  LeaveCriticalSection(&this->m_outstreamLock->m_section);
}

// File Line: 80
// RVA: 0xE7A8F0
hkResult *__fastcall hkServerDebugDisplayHandler::addGeometry(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        hkArrayBase<hkDisplayGeometry *> *geometries,
        hkTransformf *transform,
        __int64 id,
        int tag,
        unsigned __int64 shapeIdHint,
        hkGeometry::GeometryType geomType)
{
  unsigned int GeometryByteSize; // eax
  char v13; // dl
  hkOArchive *v14; // rcx
  bool v15; // di
  hkBool resulta; // [rsp+30h] [rbp+8h] BYREF

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  if ( *(_QWORD *)&this[-1].m_hashCountMap.m_map.m_numElems )
  {
    GeometryByteSize = getGeometryByteSize(geometries);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, GeometryByteSize + 41);
    v13 = -46;
    if ( geomType != GEOMETRY_DYNAMIC_VERTICES )
      v13 = 1;
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, v13);
    hkServerDebugDisplayHandler::sendGeometryData((hkServerDebugDisplayHandler *)((char *)this - 64), geometries);
    hkDisplaySerializeOStream::writeTransform(
      *(hkDisplaySerializeOStream **)&this[-1].m_hashCountMap.m_map.m_numElems,
      transform);
    hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v14 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v15 = v14 && hkOArchive::isOk(v14, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v15;
  return result;
}

// File Line: 113
// RVA: 0xE7A9D0
hkResult *__fastcall hkServerDebugDisplayHandler::addGeometryInstance(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        __int64 originalInstanceID,
        hkTransformf *transform,
        __int64 id,
        int tag)
{
  hkOArchive *v10; // rcx
  hkOArchive *v11; // rcx
  bool v12; // di
  hkBool resulta; // [rsp+30h] [rbp+8h] BYREF

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v10 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  if ( v10 )
  {
    hkOArchive::write32(v10, 49);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 16);
    hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, originalInstanceID);
    hkDisplaySerializeOStream::writeTransform(
      *(hkDisplaySerializeOStream **)&this[-1].m_hashCountMap.m_map.m_numElems,
      transform);
    hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v11 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v12 = v11 && hkOArchive::isOk(v11, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v12;
  return result;
}

// File Line: 138
// RVA: 0xE7AAA0
hkResult *__fastcall hkServerDebugDisplayHandler::setGeometryPickable(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        hkBool isPickable,
        __int64 id,
        int tag)
{
  hkOArchive *v8; // rcx
  hkOArchive *v9; // rcx
  bool v10; // di
  hkBool resulta; // [rsp+30h] [rbp+8h] BYREF
  char m_bool; // [rsp+40h] [rbp+18h]

  m_bool = isPickable.m_bool;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v8 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  if ( v8 )
  {
    hkOArchive::write32(v8, 14);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 18);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, m_bool != 0);
    hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v9 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v10 = v9 && hkOArchive::isOk(v9, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v10;
  return result;
}

// File Line: 162
// RVA: 0xE7BA40
hkResult *__fastcall hkServerDebugDisplayHandler::displayGeometry(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        hkArrayBase<hkDisplayGeometry *> *geometries,
        hkTransformf *transform,
        unsigned int color,
        int id,
        int tag)
{
  unsigned int GeometryByteSize; // eax
  hkOArchive *v12; // rcx
  bool v13; // di
  hkBool resulta; // [rsp+30h] [rbp+8h] BYREF

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  if ( *(_QWORD *)&this[-1].m_hashCountMap.m_map.m_numElems )
  {
    GeometryByteSize = getGeometryByteSize(geometries);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, GeometryByteSize + 45);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 5);
    hkServerDebugDisplayHandler::sendGeometryData((hkServerDebugDisplayHandler *)((char *)this - 64), geometries);
    hkDisplaySerializeOStream::writeTransform(
      *(hkDisplaySerializeOStream **)&this[-1].m_hashCountMap.m_map.m_numElems,
      transform);
    hkOArchive::write32u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, color);
    hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v12 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v13 = v12 && hkOArchive::isOk(v12, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v13;
  return result;
}

// File Line: 189
// RVA: 0xE7BB30
hkResult *__fastcall hkServerDebugDisplayHandler::displayGeometry(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        hkArrayBase<hkDisplayGeometry *> *geometries,
        unsigned int color,
        int id,
        int tag)
{
  unsigned int GeometryByteSize; // eax
  hkOArchive *v11; // rcx
  bool v12; // di
  hkBool resulta; // [rsp+30h] [rbp+8h] BYREF

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  if ( *(_QWORD *)&this[-1].m_hashCountMap.m_map.m_numElems )
  {
    GeometryByteSize = getGeometryByteSize(geometries);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, GeometryByteSize + 17);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 6);
    hkServerDebugDisplayHandler::sendGeometryData((hkServerDebugDisplayHandler *)((char *)this - 64), geometries);
    hkOArchive::write32u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, color);
    hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v11 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v12 = v11 && hkOArchive::isOk(v11, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v12;
  return result;
}

// File Line: 216
// RVA: 0xE7AB60
hkResult *__fastcall hkServerDebugDisplayHandler::setGeometryColor(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        unsigned int color,
        __int64 id,
        int tag)
{
  hkOArchive *v9; // rcx
  hkOArchive *v10; // rcx
  bool v11; // di
  hkBool resulta; // [rsp+30h] [rbp+8h] BYREF

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v9 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  if ( v9 )
  {
    hkOArchive::write32u(v9, 0x11u);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 3);
    hkOArchive::write32u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, color);
    hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v10 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v11 = v10 && hkOArchive::isOk(v10, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v11;
  return result;
}

// File Line: 240
// RVA: 0xE7AC20
hkResult *__fastcall hkServerDebugDisplayHandler::setGeometryTransparency(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        float alpha,
        __int64 id,
        int tag)
{
  hkOArchive *v8; // rcx
  hkOArchive *v9; // rcx
  bool v10; // di
  hkBool resulta; // [rsp+40h] [rbp+8h] BYREF

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v8 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  if ( v8 )
  {
    hkOArchive::write32u(v8, 0x11u);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 31);
    hkOArchive::writeFloat32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, alpha);
    hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v9 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v10 = v9 && hkOArchive::isOk(v9, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v10;
  return result;
}

// File Line: 264
// RVA: 0xE7ACE0
hkResult *__fastcall hkServerDebugDisplayHandler::updateGeometry(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        hkTransformf *transform,
        __int64 id,
        int tag)
{
  hkOArchive *v9; // rcx
  hkOArchive *v10; // rcx
  bool v11; // di
  hkBool resulta; // [rsp+30h] [rbp+8h] BYREF

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v9 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  if ( v9 )
  {
    hkOArchive::write32u(v9, 0x29u);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 2);
    hkDisplaySerializeOStream::writeTransform(
      *(hkDisplaySerializeOStream **)&this[-1].m_hashCountMap.m_map.m_numElems,
      transform);
    hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v10 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v11 = v10 && hkOArchive::isOk(v10, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v11;
  return result;
}

// File Line: 289
// RVA: 0xE7AE70
hkResult *__fastcall hkServerDebugDisplayHandler::updateGeometryVerts(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        __int64 geomID,
        hkArray<hkVector4f,hkContainerHeapAllocator> *newVerts,
        int tag)
{
  hkResultEnum v9; // ebp
  int i; // ebx
  hkOArchive *v11; // rcx
  bool v12; // bl
  hkResult *v13; // rax
  hkBool resulta; // [rsp+40h] [rbp+8h] BYREF

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  hkOArchive::write32u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 12 * newVerts->m_size + 17);
  hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 211);
  hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, geomID);
  hkOArchive::write32u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, newVerts->m_size);
  v9 = HK_SUCCESS;
  for ( i = 0; i < newVerts->m_size; ++i )
    hkDisplaySerializeOStream::writeQuadVector4(
      *(hkDisplaySerializeOStream **)&this[-1].m_hashCountMap.m_map.m_numElems,
      &newVerts->m_data[i]);
  hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, tag);
  v11 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v12 = v11 && hkOArchive::isOk(v11, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  LOBYTE(v9) = !v12;
  v13 = result;
  result->m_enum = v9;
  return v13;
}

// File Line: 312
// RVA: 0xE7ADA0
hkResult *__fastcall hkServerDebugDisplayHandler::updateGeometry(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        hkMatrix4f *transform,
        __int64 id,
        int tag)
{
  hkOArchive *v9; // rcx
  hkOArchive *v10; // rcx
  bool v11; // di
  hkBool resulta; // [rsp+30h] [rbp+8h] BYREF

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v9 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  if ( v9 )
  {
    hkOArchive::write32u(v9, 0x4Du);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 23);
    hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::writeArrayFloat32(
      *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems,
      transform->m_col0.m_quad.m128_f32,
      16);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v10 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v11 = v10 && hkOArchive::isOk(v10, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v11;
  return result;
}

// File Line: 336
// RVA: 0xE7AF60
hkResult *__fastcall hkServerDebugDisplayHandler::skinGeometry(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        unsigned __int64 *ids,
        int numIds,
        hkMatrix4f *poseModel,
        int numPoseModel,
        hkMatrix4f *worldFromModel,
        int tag)
{
  __int64 v9; // rsi
  _QWORD *Value; // rax
  _QWORD *v13; // rcx
  _QWORD *v14; // r8
  unsigned __int64 v15; // rax
  _QWORD *v16; // rcx
  hkOArchive *v17; // rcx
  hkResultEnum v18; // ebp
  int v19; // r12d
  signed int v20; // r13d
  __int64 i; // rbx
  _QWORD *v22; // rax
  unsigned __int64 v23; // rcx
  unsigned __int64 v24; // rcx
  hkOArchive *v25; // rcx
  bool v26; // bl
  _QWORD *v27; // rax
  _QWORD *v28; // rcx
  _QWORD *v29; // r8
  unsigned __int64 v30; // rax
  _QWORD *v31; // rcx
  hkResult *v32; // rax
  hkBool resulta; // [rsp+50h] [rbp+8h] BYREF

  v9 = numIds;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)Value[1];
  v14 = Value;
  if ( (unsigned __int64)v13 < Value[3] )
  {
    *v13 = "Ttsend skin";
    v15 = __rdtsc();
    v16 = v13 + 2;
    *((_DWORD *)v16 - 2) = v15;
    v14[1] = v16;
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v17 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v18 = HK_SUCCESS;
  if ( v17 )
  {
    v19 = 16 * numPoseModel;
    v20 = 4 * (16 * numPoseModel + 2 * v9) + 77;
    hkOArchive::write32u(v17, v20);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 24);
    hkOArchive::write32u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, v9);
    for ( i = 0i64; i < v9; ++i )
      hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, ids[i]);
    hkOArchive::write32u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, numPoseModel);
    hkOArchive::writeArrayFloat32(
      *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems,
      poseModel->m_col0.m_quad.m128_f32,
      v19);
    hkOArchive::writeArrayFloat32(
      *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems,
      worldFromModel->m_col0.m_quad.m128_f32,
      16);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, tag);
    v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v23 = v22[1];
    if ( v23 < v22[3] )
    {
      v24 = v23 + 16;
      *(_QWORD *)(v24 - 16) = "Mibytes";
      *(float *)(v24 - 8) = (float)v20;
      v22[1] = v24;
    }
  }
  v25 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v26 = v25 && hkOArchive::isOk(v25, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v28 = (_QWORD *)v27[1];
  v29 = v27;
  if ( (unsigned __int64)v28 < v27[3] )
  {
    *v28 = "Et";
    v30 = __rdtsc();
    v31 = v28 + 2;
    *((_DWORD *)v31 - 2) = v30;
    v29[1] = v31;
  }
  v32 = result;
  LOBYTE(v18) = !v26;
  result->m_enum = v18;
  return v32;
}

// File Line: 372
// RVA: 0xE7B150
hkResult *__fastcall hkServerDebugDisplayHandler::removeGeometry(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        __int64 id,
        int tag)
{
  hkOArchive *v8; // rcx
  hkOArchive *v9; // rcx
  bool v10; // di
  hkBool resulta; // [rsp+30h] [rbp+8h] BYREF

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v8 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  if ( v8 )
  {
    hkOArchive::write32u(v8, 0xDu);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 4);
    hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v9 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v10 = v9 && hkOArchive::isOk(v9, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v10;
  return result;
}

// File Line: 396
// RVA: 0xE7B210
hkResult *__fastcall hkServerDebugDisplayHandler::updateCamera(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        hkVector4f *from,
        hkVector4f *to,
        hkVector4f *up,
        float nearPlane,
        float farPlane,
        float fov,
        const char *name)
{
  unsigned int v13; // ebx
  hkOArchive *v14; // rcx
  bool v15; // bl
  hkBool resulta; // [rsp+40h] [rbp+8h] BYREF

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  if ( *(_QWORD *)&this[-1].m_hashCountMap.m_map.m_numElems )
  {
    v13 = hkString::strLen(name);
    hkOArchive::write32u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, v13 + 51);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 13);
    hkDisplaySerializeOStream::writeQuadVector4(
      *(hkDisplaySerializeOStream **)&this[-1].m_hashCountMap.m_map.m_numElems,
      from);
    hkDisplaySerializeOStream::writeQuadVector4(
      *(hkDisplaySerializeOStream **)&this[-1].m_hashCountMap.m_map.m_numElems,
      to);
    hkDisplaySerializeOStream::writeQuadVector4(
      *(hkDisplaySerializeOStream **)&this[-1].m_hashCountMap.m_map.m_numElems,
      up);
    hkOArchive::writeFloat32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, nearPlane);
    hkOArchive::writeFloat32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, farPlane);
    hkOArchive::writeFloat32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, fov);
    hkOArchive::write16u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, v13);
    hkOArchive::writeRaw(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, name, v13);
  }
  v14 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v15 = v14 && hkOArchive::isOk(v14, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v15;
  return result;
}

// File Line: 427
// RVA: 0xE7B330
hkResult *__fastcall hkServerDebugDisplayHandler::displayPoint(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        hkVector4f *position,
        unsigned int color,
        int id,
        int tag)
{
  hkOArchive *v10; // rcx
  hkOArchive *v11; // rcx
  bool v12; // di
  hkBool resulta; // [rsp+30h] [rbp+8h] BYREF

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v10 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  if ( v10 )
  {
    hkOArchive::write32u(v10, 0x1Du);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 7);
    hkDisplaySerializeOStream::writeQuadVector4(
      *(hkDisplaySerializeOStream **)&this[-1].m_hashCountMap.m_map.m_numElems,
      position);
    hkOArchive::write32u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, color);
    hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v11 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v12 = v11 && hkOArchive::isOk(v11, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v12;
  return result;
}

// File Line: 452
// RVA: 0xE7B400
hkResult *__fastcall hkServerDebugDisplayHandler::displayLine(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        hkVector4f *start,
        hkVector4f *end,
        unsigned int color,
        int id,
        int tag)
{
  hkOArchive *v11; // rcx
  hkOArchive *v12; // rcx
  bool v13; // di
  hkBool resulta; // [rsp+30h] [rbp+8h] BYREF

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v11 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  if ( v11 )
  {
    hkOArchive::write32u(v11, 0x29u);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 8);
    hkDisplaySerializeOStream::writeQuadVector4(
      *(hkDisplaySerializeOStream **)&this[-1].m_hashCountMap.m_map.m_numElems,
      start);
    hkDisplaySerializeOStream::writeQuadVector4(
      *(hkDisplaySerializeOStream **)&this[-1].m_hashCountMap.m_map.m_numElems,
      end);
    hkOArchive::write32u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, color);
    hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v12 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v13 = v12 && hkOArchive::isOk(v12, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v13;
  return result;
}

// File Line: 478
// RVA: 0xE7B4E0
hkResult *__fastcall hkServerDebugDisplayHandler::displayTriangle(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c,
        unsigned int color,
        int id,
        int tag)
{
  __m128 m_quad; // xmm0
  unsigned int v13; // r12d
  __m128 v14; // xmm1
  __int64 v15; // r14
  int v16; // r15d
  hkVector4f *p_v; // rdi
  __int64 v18; // rbp
  hkOArchive *v19; // rcx
  bool v20; // di
  hkVector4f v; // [rsp+20h] [rbp-68h] BYREF
  __m128 v23; // [rsp+30h] [rbp-58h]
  __m128 v24; // [rsp+40h] [rbp-48h]
  __m128 v25; // [rsp+50h] [rbp-38h]
  hkBool resulta; // [rsp+90h] [rbp+8h] BYREF

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  if ( *(_QWORD *)&this[-1].m_hashCountMap.m_map.m_numElems )
  {
    m_quad = b->m_quad;
    v13 = color;
    v14 = c->m_quad;
    v.m_quad = a->m_quad;
    v23 = m_quad;
    v15 = id;
    v16 = tag;
    v24 = v14;
    v25 = v.m_quad;
    p_v = &v;
    v18 = 3i64;
    do
    {
      hkOArchive::write32u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 0x29u);
      hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 8);
      hkDisplaySerializeOStream::writeQuadVector4(
        *(hkDisplaySerializeOStream **)&this[-1].m_hashCountMap.m_map.m_numElems,
        p_v++);
      hkDisplaySerializeOStream::writeQuadVector4(
        *(hkDisplaySerializeOStream **)&this[-1].m_hashCountMap.m_map.m_numElems,
        p_v);
      hkOArchive::write32u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, v13);
      hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, v15);
      hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, v16);
      --v18;
    }
    while ( v18 );
  }
  v19 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v20 = v19 && hkOArchive::isOk(v19, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v20;
  return result;
}

// File Line: 512
// RVA: 0xE7B630
hkResult *__fastcall hkServerDebugDisplayHandler::displayText(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        const char *text,
        int color,
        int id,
        int tag)
{
  int v10; // eax
  unsigned int v11; // ebx
  hkOArchive *v12; // rcx
  bool v13; // bl
  hkBool resulta; // [rsp+40h] [rbp+8h] BYREF

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  if ( *(_QWORD *)&this[-1].m_hashCountMap.m_map.m_numElems )
  {
    v10 = hkString::strLen(text);
    v11 = 0xFFFF;
    if ( v10 < 0xFFFF )
      v11 = v10;
    hkOArchive::write32u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, v11 + 19);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 9);
    hkOArchive::write16u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, v11);
    hkOArchive::writeRaw(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, text, v11);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, color);
    hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v12 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v13 = v12 && hkOArchive::isOk(v12, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v13;
  return result;
}

// File Line: 539
// RVA: 0xE7B720
hkResult *__fastcall hkServerDebugDisplayHandler::display3dText(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        const char *text,
        hkVector4f *pos,
        int color,
        int id,
        int tag)
{
  int v11; // eax
  unsigned int v12; // ebx
  hkOArchive *v13; // rcx
  bool v14; // bl
  hkBool resulta; // [rsp+40h] [rbp+8h] BYREF

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  if ( *(_QWORD *)&this[-1].m_hashCountMap.m_map.m_numElems )
  {
    v11 = hkString::strLen(text);
    v12 = 0xFFFF;
    if ( v11 < 0xFFFF )
      v12 = v11;
    hkOArchive::write32u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, v12 + 31);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 17);
    hkOArchive::write16u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, v12);
    hkOArchive::writeRaw(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, text, v12);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, color);
    hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, tag);
    hkOArchive::writeFloat32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, pos->m_quad.m128_f32[0]);
    hkOArchive::writeFloat32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, pos->m_quad.m128_f32[1]);
    hkOArchive::writeFloat32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, pos->m_quad.m128_f32[2]);
  }
  v13 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v14 = v13 && hkOArchive::isOk(v13, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v14;
  return result;
}

// File Line: 570
// RVA: 0xE7B840
hkResult *__fastcall hkServerDebugDisplayHandler::displayPoint2d(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        hkVector4f *position,
        unsigned int color)
{
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 575
// RVA: 0xE7B850
hkResult *__fastcall hkServerDebugDisplayHandler::displayLine2d(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        hkVector4f *start,
        hkVector4f *end)
{
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 580
// RVA: 0xE7B860
hkResult *__fastcall hkServerDebugDisplayHandler::displayTriangle2d(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        hkVector4f *a,
        hkVector4f *b)
{
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 585
// RVA: 0xE7B870
hkResult *__fastcall hkServerDebugDisplayHandler::displayText2d(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        const char *text,
        hkVector4f *pos)
{
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 590
// RVA: 0xE7B880
hkResult *__fastcall hkServerDebugDisplayHandler::displayAnnotation(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        const char *text,
        int id,
        int tag)
{
  __int64 v6; // r14
  int v9; // eax
  unsigned int v10; // ebx
  hkOArchive *v11; // rcx
  bool v12; // bl
  hkBool resulta; // [rsp+40h] [rbp+8h] BYREF

  v6 = id;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  if ( *(_QWORD *)&this[-1].m_hashCountMap.m_map.m_numElems )
  {
    v9 = hkString::strLen(text);
    v10 = 0xFFFF;
    if ( v9 < 0xFFFF )
      v10 = v9;
    hkOArchive::write32u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, v10 + 15);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 20);
    hkOArchive::write16u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, v10);
    hkOArchive::writeRaw(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, text, v10);
    hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, v6);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v11 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v12 = v11 && hkOArchive::isOk(v11, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v12;
  return result;
}

// File Line: 616
// RVA: 0xE7B960
hkResult *__fastcall hkServerDebugDisplayHandler::displayBone(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        hkVector4f *a,
        hkVector4f *b,
        hkQuaternionf *orientation,
        int color,
        int tag)
{
  hkOArchive *v11; // rcx
  hkOArchive *v12; // rcx
  bool v13; // di
  hkBool resulta; // [rsp+30h] [rbp+8h] BYREF

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v11 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  if ( v11 )
  {
    hkOArchive::write32u(v11, 0x31u);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 30);
    hkDisplaySerializeOStream::writeQuadVector4(
      *(hkDisplaySerializeOStream **)&this[-1].m_hashCountMap.m_map.m_numElems,
      a);
    hkDisplaySerializeOStream::writeQuadVector4(
      *(hkDisplaySerializeOStream **)&this[-1].m_hashCountMap.m_map.m_numElems,
      b);
    hkOArchive::writeArrayFloat32(
      *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems,
      orientation->m_vec.m_quad.m128_f32,
      4);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, color);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v12 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v13 = v12 && hkOArchive::isOk(v12, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v13;
  return result;
}

// File Line: 641
// RVA: 0xE7BC10
hkResult *__fastcall hkServerDebugDisplayHandler::sendMemStatsDump(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        const char *data,
        unsigned int length)
{
  hkOArchive *v8; // rcx
  hkOArchive *v9; // rcx
  bool v10; // di
  hkBool resulta; // [rsp+30h] [rbp+8h] BYREF

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v8 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  if ( v8 )
  {
    hkOArchive::write32u(v8, length + 5);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 15);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, length);
    hkOArchive::writeRaw(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, data, length);
  }
  v9 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v10 = v9 && hkOArchive::isOk(v9, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v10;
  return result;
}

// File Line: 664
// RVA: 0xE7BCD0
hkResult *__fastcall hkServerDebugDisplayHandler::holdImmediate(hkServerDebugDisplayHandler *this, hkResult *result)
{
  hkOArchive *v4; // rcx
  hkOArchive *v5; // rcx
  bool v6; // di
  hkBool resulta; // [rsp+30h] [rbp+8h] BYREF

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v4 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  if ( v4 )
  {
    hkOArchive::write32u(v4, 1u);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 11);
  }
  v5 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v6 = v5 && hkOArchive::isOk(v5, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  result->m_enum = !v6;
  return result;
}

// File Line: 690
// RVA: 0xE7BD60
void __fastcall hkServerDebugDisplayHandler::getConsumableCommands(
        hkServerDebugDisplayHandler *this,
        char **commands,
        int *numCommands)
{
  *commands = serverDebugDisplayHandler_cmds;
  *numCommands = 3;
}

// File Line: 696
// RVA: 0xE7BD80
void __fastcall hkServerDebugDisplayHandler::consumeCommand(hkServerDebugDisplayHandler *this, char command)
{
  hkProcessVtbl *vfptr; // rcx
  int array; // [rsp+38h] [rbp+10h] BYREF
  hkStringPtr v5; // [rsp+40h] [rbp+18h] BYREF

  switch ( command )
  {
    case 0:
      hkDisplaySerializeIStream::readHash((hkDisplaySerializeIStream *)this->hkProcess::vfptr, (unsigned __int64 *)&v5);
      hkServerDebugDisplayHandler::processGeometryWithHashRequested(
        (hkServerDebugDisplayHandler *)((char *)this - 16),
        (const unsigned __int64 *)&v5);
      break;
    case 1:
      hkDisplaySerializeIStream::readHash((hkDisplaySerializeIStream *)this->hkProcess::vfptr, (unsigned __int64 *)&v5);
      hkServerDebugDisplayHandler::processGeometryWithHashNotRequested(
        (hkServerDebugDisplayHandler *)((char *)this - 16),
        (const unsigned __int64 *)&v5);
      break;
    case 2:
      hkStringPtr::hkStringPtr(&v5);
      hkIArchive::readArrayGeneric((hkIArchive *)this->hkProcess::vfptr, &array, 4, 1);
      vfptr = this->hkProcess::vfptr;
      LODWORD(this->m_hashCountMap.m_map.m_elem) = array;
      hkIArchive::readArrayGeneric((hkIArchive *)vfptr, &array, 1, 1);
      LOBYTE(this->m_hashCountMap.m_map.m_numElems) = (_BYTE)array != 0;
      hkIArchive::readArrayGeneric((hkIArchive *)this->hkProcess::vfptr, &array, 4, 1);
      HIDWORD(this->m_hashCountMap.m_map.m_elem) = array;
      hkStringPtr::~hkStringPtr(&v5);
      break;
  }
}

// File Line: 727
// RVA: 0xE7CA20
hkResult *__fastcall hkServerDebugDisplayHandler::useGeometryForHash(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *geometries,
        const unsigned __int64 *hash,
        hkBool final)
{
  unsigned int GeometryByteSize; // eax
  hkDisplaySerializeOStream *m_outStream; // rcx
  bool v11; // di
  hkBool resulta; // [rsp+30h] [rbp+8h] BYREF

  EnterCriticalSection(&this->m_outstreamLock->m_section);
  if ( this->m_outStream )
  {
    GeometryByteSize = getGeometryByteSize(geometries);
    hkOArchive::write32(this->m_outStream, GeometryByteSize + 9);
    hkOArchive::write8u(this->m_outStream, (final.m_bool != 0) + 28);
    hkDisplaySerializeOStream::writeHash(this->m_outStream, hash);
    hkServerDebugDisplayHandler::sendGeometryData(this, geometries);
  }
  m_outStream = this->m_outStream;
  v11 = m_outStream && hkOArchive::isOk(m_outStream, &resulta)->m_bool;
  LeaveCriticalSection(&this->m_outstreamLock->m_section);
  result->m_enum = !v11;
  return result;
}

// File Line: 751
// RVA: 0xE7BF80
hkResult *__fastcall hkServerDebugDisplayHandler::addGeometryHash(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        hkReferencedObject *source,
        hkDisplayGeometryBuilder *builder,
        const unsigned __int64 *hash,
        hkAabb *aabb,
        unsigned int color,
        hkTransformf *transform,
        __int64 id,
        int tag)
{
  hkOArchive *v13; // rcx
  const unsigned __int64 *v14; // rbp
  hkOArchive *v15; // rcx
  bool v16; // di
  int inserted; // eax
  __int64 v18; // rsi
  int vfptr; // r13d
  __int64 v20; // rdx
  unsigned __int64 *v21; // r8
  unsigned __int64 v22; // rax

  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v13 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v14 = hash;
  if ( v13 )
  {
    hkOArchive::write32(v13, 77);
    hkOArchive::write8u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, 27);
    hkDisplaySerializeOStream::writeHash(*(hkDisplaySerializeOStream **)&this[-1].m_hashCountMap.m_map.m_numElems, v14);
    hkDisplaySerializeOStream::writeAabb(*(hkDisplaySerializeOStream **)&this[-1].m_hashCountMap.m_map.m_numElems, aabb);
    hkOArchive::write32u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, color);
    hkDisplaySerializeOStream::writeTransform(
      *(hkDisplaySerializeOStream **)&this[-1].m_hashCountMap.m_map.m_numElems,
      transform);
    hkOArchive::write64u(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v15 = *(hkOArchive **)&this[-1].m_hashCountMap.m_map.m_numElems;
  v16 = v15 && hkOArchive::isOk(v15, (hkBool *)&hash)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  inserted = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findOrInsertKey(
               (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_processHandler,
               &hkContainerHeapAllocator::s_alloc,
               *v14,
               0i64);
  v18 = 2i64 * inserted;
  vfptr = (int)this->m_processHandler[2 * inserted + 1].vfptr;
  if ( !vfptr )
  {
    if ( *(_DWORD *)&this->m_selectable.m_bool == (*((_DWORD *)&this->m_selectable + 1) & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->hkProcess::vfptr, 24);
    v20 = *(int *)&this->m_selectable.m_bool;
    v21 = (unsigned __int64 *)this->hkProcess::vfptr + 3 * v20;
    *(_DWORD *)&this->m_selectable.m_bool = v20 + 1;
    v22 = *v14;
    v21[2] = (unsigned __int64)builder;
    *v21 = v22;
    v21[1] = (unsigned __int64)source;
    hkReferencedObject::addReference(source);
    hkReferencedObject::addReference(builder);
  }
  this->m_processHandler[v18 + 1].vfptr = (hkProcessHandlerVtbl *)(vfptr + 1);
  result->m_enum = !v16;
  return result;
}

// File Line: 798
// RVA: 0xE7C460
void __fastcall hkServerDebugDisplayHandler::processGeometryWithHashRequested(
        hkServerDebugDisplayHandler *this,
        const unsigned __int64 *hash)
{
  int IndexForGeometryAwaitingRequest; // eax
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *m_data; // r14
  int v5; // ebp
  __int64 v6; // rsi
  __int64 m_size; // rdx
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *v8; // r8
  __int64 v9; // rax
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *v10; // rdx
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *v11; // r8
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *v12; // rax
  __int64 v13; // rdx
  signed __int64 v14; // r8
  hkDisplayGeometryBuilder *v15; // rcx

  IndexForGeometryAwaitingRequest = hkServerDebugDisplayHandler::findIndexForGeometryAwaitingRequest(this, hash);
  m_data = this->m_geometriesAwaitingRequests.m_data;
  v5 = IndexForGeometryAwaitingRequest;
  v6 = IndexForGeometryAwaitingRequest;
  if ( this->m_geometriesAwaitingDeparture.m_size == (this->m_geometriesAwaitingDeparture.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_geometriesAwaitingDeparture.m_data,
      24);
  m_size = this->m_geometriesAwaitingDeparture.m_size;
  v8 = &this->m_geometriesAwaitingDeparture.m_data[m_size];
  this->m_geometriesAwaitingDeparture.m_size = m_size + 1;
  v8->m_hash = m_data[v6].m_hash;
  v8->m_source = m_data[v6].m_source;
  v8->m_builder = m_data[v6].m_builder;
  v9 = --this->m_geometriesAwaitingRequests.m_size;
  if ( (_DWORD)v9 != v5 )
  {
    v10 = this->m_geometriesAwaitingRequests.m_data;
    v11 = &v10[v9];
    v12 = &v10[v6];
    v13 = 3i64;
    v14 = (char *)v11 - (char *)v12;
    do
    {
      v15 = *(hkDisplayGeometryBuilder **)((char *)&v12->m_hash + v14);
      v12 = (hkServerDebugDisplayHandler::UnbuiltGeometryInfo *)((char *)v12 + 8);
      v12[-1].m_builder = v15;
      --v13;
    }
    while ( v13 );
  }
}

// File Line: 809
// RVA: 0xE7C560
void __fastcall hkServerDebugDisplayHandler::processGeometryWithHashNotRequested(
        hkServerDebugDisplayHandler *this,
        unsigned __int64 *hash)
{
  __int64 Key; // rbp
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v5; // r10
  int v6; // r8d
  int IndexForGeometryAwaitingRequest; // eax
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *m_data; // rbx
  int v9; // edi
  __int64 v10; // r15
  __int64 v11; // rax
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *v12; // rdx
  __int64 v13; // r8
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *v14; // r9
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *v15; // rax
  signed __int64 v16; // r9
  hkDisplayGeometryBuilder *v17; // rdx

  Key = (__int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                   &this->m_hashCountMap.m_map,
                   *hash);
  v5 = &this->m_hashCountMap.m_map.m_elem[(int)Key];
  v6 = LODWORD(v5->val) - 1;
  v5->val = v6;
  if ( !v6 )
  {
    IndexForGeometryAwaitingRequest = hkServerDebugDisplayHandler::findIndexForGeometryAwaitingRequest(this, hash);
    m_data = this->m_geometriesAwaitingRequests.m_data;
    v9 = IndexForGeometryAwaitingRequest;
    v10 = IndexForGeometryAwaitingRequest;
    hkReferencedObject::removeReference(m_data[v10].m_builder);
    hkReferencedObject::removeReference(m_data[v10].m_source);
    v11 = --this->m_geometriesAwaitingRequests.m_size;
    if ( (_DWORD)v11 != v9 )
    {
      v12 = this->m_geometriesAwaitingRequests.m_data;
      v13 = 3i64;
      v14 = &v12[v11];
      v15 = &v12[v10];
      v16 = (char *)v14 - (char *)&v12[v10];
      do
      {
        v17 = *(hkDisplayGeometryBuilder **)((char *)&v15->m_hash + v16);
        v15 = (hkServerDebugDisplayHandler::UnbuiltGeometryInfo *)((char *)v15 + 8);
        v15[-1].m_builder = v17;
        --v13;
      }
      while ( v13 );
    }
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
      &this->m_hashCountMap.m_map,
      Key);
  }
}

// File Line: 830
// RVA: 0xE7CAF0
__int64 __fastcall hkServerDebugDisplayHandler::findIndexForGeometryAwaitingRequest(
        hkServerDebugDisplayHandler *this,
        const unsigned __int64 *hash)
{
  __int64 m_size; // r10
  unsigned int v3; // r9d
  __int64 v4; // r8
  __int64 v5; // rdx
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *i; // rax

  m_size = this->m_geometriesAwaitingRequests.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
    return 0xFFFFFFFFi64;
  v5 = *hash;
  for ( i = this->m_geometriesAwaitingRequests.m_data; v5 != i->m_hash; ++i )
  {
    ++v4;
    ++v3;
    if ( v4 >= m_size )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 843
// RVA: 0xE7C650
void __fastcall hkServerDebugDisplayHandler::buildAndSendGeometries(hkServerDebugDisplayHandler *this)
{
  int m_simpleShapesPerFrame; // r12d
  __int64 m_size; // rax
  int v4; // esi
  __int64 v5; // r13
  __int64 v6; // rcx
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *v7; // r15
  char *v8; // r15
  bool v9; // zf
  char v10; // bl
  int v11; // edi
  int m_simpleShapesPerPart; // eax
  __int64 v13; // rcx
  __int64 v14; // r8
  hkReferencedObject *m_continueData; // rax
  int v16; // esi
  __int64 i; // rdi
  hkDisplayGeometry *v18; // rcx
  int v19; // eax
  __int64 Key; // rdi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v21; // r9
  int v22; // edx
  __int64 v23; // rdx
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *v24; // r8
  int v25; // eax
  int v26; // edi
  __int64 v27; // rbx
  hkDisplayGeometry *v28; // rcx
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *m_data; // rdx
  int v30; // r9d
  __int64 v31; // rcx
  hkDisplayGeometryBuilder *m_hash; // rax
  __int64 v33; // [rsp+30h] [rbp-A8h]
  __int64 v34; // [rsp+38h] [rbp-A0h]
  hkResult v35; // [rsp+40h] [rbp-98h] BYREF
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> geometries; // [rsp+50h] [rbp-88h] BYREF
  char v37; // [rsp+60h] [rbp-78h] BYREF
  hkErrStream v38; // [rsp+78h] [rbp-60h] BYREF
  char buf[560]; // [rsp+98h] [rbp-40h] BYREF
  char v40[8]; // [rsp+2E8h] [rbp+210h] BYREF
  int v41; // [rsp+2F0h] [rbp+218h]
  int v42; // [rsp+2F8h] [rbp+220h] BYREF
  hkResult result; // [rsp+300h] [rbp+228h] BYREF

  m_simpleShapesPerFrame = 1;
  if ( this->m_simpleShapesPerFrame )
    m_simpleShapesPerFrame = this->m_simpleShapesPerFrame;
  m_size = this->m_geometriesAwaitingDeparture.m_size;
  v4 = 0;
  v5 = 0i64;
  v41 = 0;
  v34 = m_size;
  if ( m_size > 0 )
  {
    v6 = 0i64;
    v33 = 0i64;
    while ( 1 )
    {
      if ( !m_simpleShapesPerFrame )
      {
LABEL_42:
        if ( v4 > 0 )
        {
          this->m_geometriesAwaitingDeparture.m_size -= v4;
          m_data = this->m_geometriesAwaitingDeparture.m_data;
          v30 = 24 * this->m_geometriesAwaitingDeparture.m_size;
          if ( v30 > 0 )
          {
            v31 = ((unsigned int)(v30 - 1) >> 3) + 1;
            do
            {
              m_hash = (hkDisplayGeometryBuilder *)m_data[v4].m_hash;
              m_data = (hkServerDebugDisplayHandler::UnbuiltGeometryInfo *)((char *)m_data + 8);
              m_data[-1].m_builder = m_hash;
              --v31;
            }
            while ( v31 );
          }
        }
        return;
      }
      v7 = this->m_geometriesAwaitingDeparture.m_data;
      geometries.m_size = 0;
      v8 = (char *)v7 + v6;
      v9 = this->m_simpleShapesPerFrame == 0;
      geometries.m_data = (hkDisplayGeometry **)&v37;
      geometries.m_capacityAndFlags = -2147483640;
      if ( !v9 || this->m_simpleShapesPerPart )
        break;
      if ( this->m_continueData )
        goto LABEL_12;
      (*(void (__fastcall **)(_QWORD, _QWORD, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *))(**((_QWORD **)v8 + 2) + 24i64))(
        *((_QWORD *)v8 + 2),
        *((_QWORD *)v8 + 1),
        &geometries);
      v10 = 1;
LABEL_21:
      v16 = geometries.m_size - 1;
      for ( i = geometries.m_size - 1; i >= 0; --i )
      {
        v18 = geometries.m_data[i];
        if ( v18->m_type == HK_DISPLAY_CONVEX && !v18->m_geometry )
        {
          hkErrStream::hkErrStream(&v38, buf, 512);
          hkOstream::operator<<(&v38, "Unable to build some display geometry data");
          hkError::messageReport(0xFFFFFFFF, buf, "hkServerDebugDisplayHandler.cpp", 909);
          hkOstream::~hkOstream(&v38);
          v19 = geometries.m_size - 1;
          geometries.m_size = v19;
          if ( v19 != v16 )
            geometries.m_data[i] = geometries.m_data[v19];
        }
        --v16;
      }
      if ( v10 )
      {
        v33 += 24i64;
        v4 = v41 + 1;
        this->m_continueData = 0i64;
        ++v5;
        v41 = v4;
        hkServerDebugDisplayHandler::useGeometryForHash(
          this,
          &result,
          &geometries,
          (const unsigned __int64 *)v8,
          (hkBool)1);
        Key = (__int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                         &this->m_hashCountMap.m_map,
                         *(_QWORD *)v8);
        v21 = &this->m_hashCountMap.m_map.m_elem[(int)Key];
        v22 = LODWORD(v21->val) - 1;
        v21->val = v22;
        if ( v22 )
        {
          if ( this->m_geometriesAwaitingRequests.m_size == (this->m_geometriesAwaitingRequests.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&this->m_geometriesAwaitingRequests.m_data,
              24);
          v23 = this->m_geometriesAwaitingRequests.m_size;
          v24 = &this->m_geometriesAwaitingRequests.m_data[v23];
          this->m_geometriesAwaitingRequests.m_size = v23 + 1;
          v24->m_hash = *(_QWORD *)v8;
          v24->m_source = (hkReferencedObject *)*((_QWORD *)v8 + 1);
          v24->m_builder = (hkDisplayGeometryBuilder *)*((_QWORD *)v8 + 2);
        }
        else
        {
          hkReferencedObject::removeReference(*((hkReferencedObject **)v8 + 2));
          hkReferencedObject::removeReference(*((hkReferencedObject **)v8 + 1));
          hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
            &this->m_hashCountMap.m_map,
            Key);
        }
      }
      else
      {
        hkServerDebugDisplayHandler::useGeometryForHash(this, &v35, &geometries, (const unsigned __int64 *)v8, 0);
        v4 = v41;
      }
      v25 = geometries.m_size;
      v26 = 0;
      if ( geometries.m_size > 0 )
      {
        v27 = 0i64;
        do
        {
          v28 = geometries.m_data[v27];
          if ( v28 )
          {
            v28->vfptr->__vecDelDtor(v28, 1u);
            v25 = geometries.m_size;
          }
          ++v26;
          ++v27;
        }
        while ( v26 < v25 );
      }
      geometries.m_size = 0;
      if ( geometries.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          geometries.m_data,
          8 * geometries.m_capacityAndFlags);
      v6 = v33;
      if ( v5 >= v34 )
        goto LABEL_42;
    }
    if ( !this->m_continueData )
      this->m_continueData = (hkReferencedObject *)(*(__int64 (__fastcall **)(_QWORD, _QWORD))(**((_QWORD **)v8 + 2)
                                                                                             + 40i64))(
                                                     *((_QWORD *)v8 + 2),
                                                     *((_QWORD *)v8 + 1));
LABEL_12:
    v11 = 100000000;
    if ( this->m_simpleShapesPerFrame )
    {
      v11 = m_simpleShapesPerFrame;
      if ( m_simpleShapesPerFrame > 100000000 )
        v11 = 100000000;
    }
    m_simpleShapesPerPart = this->m_simpleShapesPerPart;
    if ( m_simpleShapesPerPart )
    {
      if ( v11 < m_simpleShapesPerPart )
        m_simpleShapesPerPart = v11;
      v11 = m_simpleShapesPerPart;
    }
    v13 = *((_QWORD *)v8 + 2);
    v14 = *((_QWORD *)v8 + 1);
    m_continueData = this->m_continueData;
    v42 = v11;
    v10 = *(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, __int64, int *, hkReferencedObject *, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *))(*(_QWORD *)v13 + 32i64))(
                      v13,
                      v40,
                      v14,
                      &v42,
                      m_continueData,
                      &geometries);
    if ( this->m_simpleShapesPerFrame )
      m_simpleShapesPerFrame += v42 - v11;
    goto LABEL_21;
  }
}f ( this->m_simpleShapesPerFrame )
      m_simpleShapesPerFrame += v42 - v11;
    goto LABEL_21;
  }
}

// File Line: 958
// RVA: 0xE7BE70
void __fastcall hkServerDebugDisplayHandler::step(hkServerDebugDisplayHandler *this, float frameTimeInMs)
{
  hkServerDebugDisplayHandler::buildAndSendGeometries((hkServerDebugDisplayHandler *)((char *)this - 16));
}

// File Line: 963
// RVA: 0xE7BF70
hkBool *__fastcall hkServerDebugDisplayHandler::doesSupportHashes(hkServerDebugDisplayHandler *this, hkBool *result)
{
  result->m_bool = (char)this->m_geometriesAwaitingRequests.m_data;
  return result;
}

// File Line: 968
// RVA: 0xE7C130
hkResult *__fastcall hkServerDebugDisplayHandler::addGeometryPart(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        hkArrayBase<hkDisplayGeometry *> *geometries,
        hkTransformf *transform,
        __int64 id,
        int tag,
        unsigned __int64 shapeIdHint,
        hkBool final)
{
  unsigned int GeometryByteSize; // eax
  unsigned int v13; // eax
  hkDisplaySerializeOStream *m_outStream; // rcx
  bool v15; // di
  hkBool resulta; // [rsp+30h] [rbp+8h] BYREF

  EnterCriticalSection(&this->m_outstreamLock->m_section);
  if ( this->m_outStream )
  {
    if ( final.m_bool )
    {
      GeometryByteSize = getGeometryByteSize(geometries);
      hkOArchive::write32(this->m_outStream, GeometryByteSize + 41);
      hkOArchive::write8u(this->m_outStream, 26);
      hkServerDebugDisplayHandler::sendGeometryData(this, geometries);
      hkDisplaySerializeOStream::writeTransform(this->m_outStream, transform);
      hkOArchive::write64u(this->m_outStream, id);
      hkOArchive::write32(this->m_outStream, tag);
    }
    else
    {
      v13 = getGeometryByteSize(geometries);
      hkOArchive::write32(this->m_outStream, v13 + 1);
      hkOArchive::write8u(this->m_outStream, 25);
      hkServerDebugDisplayHandler::sendGeometryData(this, geometries);
    }
  }
  m_outStream = this->m_outStream;
  v15 = m_outStream && hkOArchive::isOk(m_outStream, &resulta)->m_bool;
  LeaveCriticalSection(&this->m_outstreamLock->m_section);
  result->m_enum = !v15;
  return result;
}

// File Line: 1006
// RVA: 0xE7BF00
hkResult *__fastcall hkServerDebugDisplayHandler::addGeometryLazily(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        hkReferencedObject *source,
        hkDisplayGeometryBuilder *builder,
        hkTransformf *transform,
        unsigned __int64 id,
        int tag,
        unsigned __int64 shapeIdHint)
{
  hkResultEnum m_enum; // ecx
  hkResult *v10; // rax
  hkResult resulta; // [rsp+50h] [rbp+8h] BYREF

  if ( LODWORD(this->m_outstreamLock) )
    m_enum = hkServerDebugDisplayHandler::addGeometryInParts(
               (hkServerDebugDisplayHandler *)((char *)this - 64),
               &resulta,
               source,
               builder,
               transform,
               id,
               tag,
               shapeIdHint)->m_enum;
  else
    m_enum = hkDebugDisplayHandler::addGeometryLazily(
               (hkDebugDisplayHandler *)this,
               &resulta,
               source,
               builder,
               transform,
               id,
               tag,
               shapeIdHint)->m_enum;
  v10 = result;
  result->m_enum = m_enum;
  return v10;
}

// File Line: 1020
// RVA: 0xE7C240
hkResult *__fastcall hkServerDebugDisplayHandler::addGeometryInParts(
        hkServerDebugDisplayHandler *this,
        hkResult *result,
        hkReferencedObject *source,
        hkDisplayGeometryBuilder *builder,
        hkTransformf *transform,
        __int64 id,
        int tag,
        unsigned __int64 shapeIdHint)
{
  hkReferencedObject *v10; // rbx
  __int64 v11; // rax
  unsigned __int64 v12; // r15
  bool v13; // r14
  __int64 v14; // rcx
  char *v15; // rax
  int m_size; // edx
  hkBool final; // bl
  int v18; // esi
  __int64 i; // rdi
  hkDisplayGeometry *v20; // rax
  hkResult *v21; // rax
  bool v22; // zf
  hkResult *v23; // r15
  int m_capacityAndFlags; // r8d
  hkArrayBase<hkDisplayGeometry *> geometries; // [rsp+40h] [rbp-C0h] BYREF
  hkResult resulta; // [rsp+50h] [rbp-B0h] BYREF
  __int64 v28; // [rsp+58h] [rbp-A8h]
  hkErrStream v29; // [rsp+60h] [rbp-A0h] BYREF
  char buf[576]; // [rsp+80h] [rbp-80h] BYREF
  char v31; // [rsp+2D0h] [rbp+1D0h] BYREF
  hkResult *v32; // [rsp+2D8h] [rbp+1D8h]
  hkReferencedObject *v33; // [rsp+2E0h] [rbp+1E0h]
  int m_simpleShapesPerPart; // [rsp+2E8h] [rbp+1E8h] BYREF

  v33 = source;
  v32 = result;
  v10 = source;
  v11 = ((__int64 (__fastcall *)(hkDisplayGeometryBuilder *, hkReferencedObject *))builder->vfptr[2].__first_virtual_table_function__)(
          builder,
          source);
  v12 = shapeIdHint;
  v13 = 1;
  v14 = v11;
  v28 = v11;
  geometries.m_data = 0i64;
  geometries.m_size = 0;
  geometries.m_capacityAndFlags = 0x80000000;
  do
  {
    m_simpleShapesPerPart = this->m_simpleShapesPerPart;
    v15 = (char *)((__int64 (__fastcall *)(hkDisplayGeometryBuilder *, char *, hkReferencedObject *, int *, __int64, hkArrayBase<hkDisplayGeometry *> *))builder->vfptr[2].__vecDelDtor)(
                    builder,
                    &v31,
                    v10,
                    &m_simpleShapesPerPart,
                    v14,
                    &geometries);
    m_size = geometries.m_size;
    final.m_bool = *v15;
    v18 = geometries.m_size - 1;
    for ( i = geometries.m_size - 1; i >= 0; --i )
    {
      v20 = geometries.m_data[i];
      if ( v20->m_type == HK_DISPLAY_CONVEX && !v20->m_geometry )
      {
        hkErrStream::hkErrStream(&v29, buf, 512);
        hkOstream::operator<<(&v29, "Unable to build display geometry from source");
        hkError::messageReport(0xFFFFFFFF, buf, "hkServerDebugDisplayHandler.cpp", 1039);
        hkOstream::~hkOstream(&v29);
        m_size = geometries.m_size - 1;
        geometries.m_size = m_size;
        if ( m_size != v18 )
        {
          geometries.m_data[i] = geometries.m_data[m_size];
          m_size = geometries.m_size;
        }
      }
      --v18;
    }
    if ( m_size )
    {
      v21 = hkServerDebugDisplayHandler::addGeometryPart(this, &resulta, &geometries, transform, id, tag, v12, final);
      m_size = geometries.m_size;
      v13 = v21->m_enum == HK_SUCCESS;
    }
    if ( !v13 )
      break;
    hkReferencedObject::removeReferences(geometries.m_data, m_size, 8);
    v14 = v28;
    v22 = final.m_bool == 0;
    v10 = v33;
    geometries.m_size = 0;
  }
  while ( v22 );
  v23 = v32;
  m_capacityAndFlags = geometries.m_capacityAndFlags;
  geometries.m_size = 0;
  v32->m_enum = !v13;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      geometries.m_data,
      8 * m_capacityAndFlags);
  return v23;
}

