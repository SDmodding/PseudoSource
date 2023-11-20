// File Line: 25
// RVA: 0xE7A660
void __fastcall hkServerDebugDisplayHandler::hkServerDebugDisplayHandler(hkServerDebugDisplayHandler *this, hkDisplaySerializeOStream *outStream, hkDisplaySerializeIStream *inStream)
{
  hkServerDebugDisplayHandler *v3; // rbx
  _QWORD **v4; // rax
  hkCriticalSection *v5; // rax
  hkCriticalSection *v6; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_selectable.m_bool = 0;
  v3 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkServerDebugDisplayHandler::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkProcessVtbl *)&hkServerDebugDisplayHandler::`vftable'{for `hkProcess'};
  this->vfptr = (hkDebugDisplayHandlerVtbl *)&hkServerDebugDisplayHandler::`vftable'{for `hkDebugDisplayHandler'};
  this->m_geometriesAwaitingRequests.m_data = 0i64;
  this->m_geometriesAwaitingRequests.m_size = 0;
  this->m_geometriesAwaitingRequests.m_capacityAndFlags = 2147483648;
  this->m_geometriesAwaitingDeparture.m_data = 0i64;
  this->m_geometriesAwaitingDeparture.m_size = 0;
  this->m_geometriesAwaitingDeparture.m_capacityAndFlags = 2147483648;
  this->m_continueData = 0i64;
  this->m_hashCountMap.m_map.m_elem = 0i64;
  this->m_hashCountMap.m_map.m_numElems = 0;
  this->m_hashCountMap.m_map.m_hashMod = -1;
  *(_QWORD *)&this->m_simpleShapesPerPart = 0i64;
  this->m_sendHashes.m_bool = 0;
  this->m_outStream = outStream;
  this->m_inStream = inStream;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 40i64);
  if ( v5 )
  {
    hkCriticalSection::hkCriticalSection(v5, 1000);
    v3->m_outstreamLock = v6;
  }
  else
  {
    v3->m_outstreamLock = 0i64;
  }
}

// File Line: 32
// RVA: 0xE7A740
void __fastcall hkServerDebugDisplayHandler::~hkServerDebugDisplayHandler(hkServerDebugDisplayHandler *this)
{
  hkCriticalSection *v1; // rdi
  hkServerDebugDisplayHandler *v2; // rbx
  _QWORD **v3; // rax
  __int64 v4; // rsi
  __int64 v5; // rdi
  __int64 v6; // rsi
  __int64 v7; // rdi
  hkReferencedObject *v8; // rcx
  int v9; // eax
  int v10; // eax

  v1 = this->m_outstreamLock;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkServerDebugDisplayHandler::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkProcessVtbl *)&hkServerDebugDisplayHandler::`vftable'{for `hkProcess'};
  this->vfptr = (hkDebugDisplayHandlerVtbl *)&hkServerDebugDisplayHandler::`vftable'{for `hkDebugDisplayHandler'};
  if ( v1 )
  {
    DeleteCriticalSection(&v1->m_section);
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkCriticalSection *, signed __int64))(*v3[11] + 16i64))(v3[11], v1, 40i64);
  }
  v4 = v2->m_geometriesAwaitingRequests.m_size;
  if ( v4 > 0 )
  {
    v5 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_geometriesAwaitingRequests.m_data[v5].m_builder->vfptr);
      hkReferencedObject::removeReference(v2->m_geometriesAwaitingRequests.m_data[v5].m_source);
      ++v5;
      --v4;
    }
    while ( v4 );
  }
  v6 = v2->m_geometriesAwaitingDeparture.m_size;
  if ( v6 > 0 )
  {
    v7 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_geometriesAwaitingDeparture.m_data[v7].m_builder->vfptr);
      hkReferencedObject::removeReference(v2->m_geometriesAwaitingDeparture.m_data[v7].m_source);
      ++v7;
      --v6;
    }
    while ( v6 );
  }
  v8 = v2->m_continueData;
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_hashCountMap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v2->m_hashCountMap);
  v9 = v2->m_geometriesAwaitingDeparture.m_capacityAndFlags;
  v2->m_geometriesAwaitingDeparture.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_geometriesAwaitingDeparture.m_data,
      24 * (v9 & 0x3FFFFFFF));
  v2->m_geometriesAwaitingDeparture.m_data = 0i64;
  v2->m_geometriesAwaitingDeparture.m_capacityAndFlags = 2147483648;
  v10 = v2->m_geometriesAwaitingRequests.m_capacityAndFlags;
  v2->m_geometriesAwaitingRequests.m_size = 0;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_geometriesAwaitingRequests.m_data,
      24 * (v10 & 0x3FFFFFFF));
  v2->m_geometriesAwaitingRequests.m_data = 0i64;
  v2->m_geometriesAwaitingRequests.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkDebugDisplayHandlerVtbl *)&hkDebugDisplayHandler::`vftable';
  v2->vfptr = (hkProcessVtbl *)&hkProcess::`vftable';
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 57
// RVA: 0xE7CB30
__int64 __fastcall getGeometryByteSize(hkArrayBase<hkDisplayGeometry *> *geometries)
{
  int v1; // edi
  hkArrayBase<hkDisplayGeometry *> *v2; // r14
  unsigned int v3; // ebx
  __int64 v4; // rsi
  int v5; // eax

  v1 = 0;
  v2 = geometries;
  v3 = 4;
  if ( geometries->m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = hkDisplaySerializeOStream::computeBytesRequired(v2->m_data[v4]);
      ++v1;
      ++v4;
      v3 += v5;
    }
    while ( v1 < v2->m_size );
  }
  return v3;
}

// File Line: 67
// RVA: 0xE7BE80
void __fastcall hkServerDebugDisplayHandler::sendGeometryData(hkServerDebugDisplayHandler *this, hkArrayBase<hkDisplayGeometry *> *geometries)
{
  hkServerDebugDisplayHandler *v2; // rbp
  hkArrayBase<hkDisplayGeometry *> *v3; // rsi
  int v4; // ebx
  __int64 v5; // rdi

  v2 = this;
  v3 = geometries;
  EnterCriticalSection(&this->m_outstreamLock->m_section);
  hkOArchive::write32((hkOArchive *)&v2->m_outStream->vfptr, v3->m_size);
  v4 = 0;
  if ( v3->m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      hkDisplaySerializeOStream::writeDisplayGeometry(v2->m_outStream, v3->m_data[v5]);
      ++v4;
      ++v5;
    }
    while ( v4 < v3->m_size );
  }
  LeaveCriticalSection(&v2->m_outstreamLock->m_section);
}

// File Line: 80
// RVA: 0xE7A8F0
hkResult *__fastcall hkServerDebugDisplayHandler::addGeometry(hkServerDebugDisplayHandler *this, hkResult *result, hkArrayBase<hkDisplayGeometry *> *geometries, hkTransformf *transform, unsigned __int64 id, int tag, unsigned __int64 shapeIdHint, hkGeometry::GeometryType geomType)
{
  hkServerDebugDisplayHandler *v8; // rbx
  hkTransformf *v9; // rbp
  hkArrayBase<hkDisplayGeometry *> *v10; // rdi
  hkResult *v11; // rsi
  unsigned int v12; // eax
  char v13; // dl
  hkOArchive *v14; // rcx
  bool v15; // di
  hkBool resulta; // [rsp+30h] [rbp+8h]

  v8 = this;
  v9 = transform;
  v10 = geometries;
  v11 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  if ( *(_QWORD *)&v8[-1].m_hashCountMap.m_map.m_numElems )
  {
    v12 = getGeometryByteSize(v10);
    hkOArchive::write32(*(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems, v12 + 41);
    v13 = -46;
    if ( geomType != 1 )
      v13 = 1;
    hkOArchive::write8u(*(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems, v13);
    hkServerDebugDisplayHandler::sendGeometryData((hkServerDebugDisplayHandler *)((char *)v8 - 64), v10);
    hkDisplaySerializeOStream::writeTransform(
      *(hkDisplaySerializeOStream **)&v8[-1].m_hashCountMap.m_map.m_numElems,
      v9);
    hkOArchive::write64u(*(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v14 = *(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems;
  v15 = v14 && hkOArchive::isOk(v14, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v8->m_memSizeAndFlags);
  v11->m_enum = v15 == 0;
  return v11;
}

// File Line: 113
// RVA: 0xE7A9D0
hkResult *__fastcall hkServerDebugDisplayHandler::addGeometryInstance(hkServerDebugDisplayHandler *this, hkResult *result, unsigned __int64 originalInstanceID, hkTransformf *transform, unsigned __int64 id, int tag)
{
  hkServerDebugDisplayHandler *v6; // rbx
  hkTransformf *v7; // rdi
  unsigned __int64 v8; // rbp
  hkResult *v9; // rsi
  hkOArchive *v10; // rcx
  hkOArchive *v11; // rcx
  bool v12; // di
  hkBool resulta; // [rsp+30h] [rbp+8h]

  v6 = this;
  v7 = transform;
  v8 = originalInstanceID;
  v9 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v10 = *(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems;
  if ( v10 )
  {
    hkOArchive::write32(v10, 49);
    hkOArchive::write8u(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, 16);
    hkOArchive::write64u(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, v8);
    hkDisplaySerializeOStream::writeTransform(
      *(hkDisplaySerializeOStream **)&v6[-1].m_hashCountMap.m_map.m_numElems,
      v7);
    hkOArchive::write64u(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v11 = *(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems;
  v12 = v11 && hkOArchive::isOk(v11, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v6->m_memSizeAndFlags);
  v9->m_enum = v12 == 0;
  return v9;
}

// File Line: 138
// RVA: 0xE7AAA0
hkResult *__fastcall hkServerDebugDisplayHandler::setGeometryPickable(hkServerDebugDisplayHandler *this, hkResult *result, hkBool isPickable, unsigned __int64 id, int tag)
{
  hkServerDebugDisplayHandler *v5; // rbx
  unsigned __int64 v6; // rdi
  hkResult *v7; // rsi
  hkOArchive *v8; // rcx
  hkOArchive *v9; // rcx
  bool v10; // di
  hkBool resulta; // [rsp+30h] [rbp+8h]
  char v13; // [rsp+40h] [rbp+18h]

  v13 = isPickable.m_bool;
  v5 = this;
  v6 = id;
  v7 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v8 = *(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems;
  if ( v8 )
  {
    hkOArchive::write32(v8, 14);
    hkOArchive::write8u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, 18);
    hkOArchive::write8u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, v13 != 0);
    hkOArchive::write64u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, v6);
    hkOArchive::write32(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v9 = *(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems;
  v10 = v9 && hkOArchive::isOk(v9, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v5->m_memSizeAndFlags);
  v7->m_enum = v10 == 0;
  return v7;
}

// File Line: 162
// RVA: 0xE7BA40
hkResult *__fastcall hkServerDebugDisplayHandler::displayGeometry(hkServerDebugDisplayHandler *this, hkResult *result, hkArrayBase<hkDisplayGeometry *> *geometries, hkTransformf *transform, unsigned int color, int id, int tag)
{
  hkServerDebugDisplayHandler *v7; // rbx
  hkTransformf *v8; // rbp
  hkArrayBase<hkDisplayGeometry *> *v9; // rdi
  hkResult *v10; // rsi
  unsigned int v11; // eax
  hkOArchive *v12; // rcx
  bool v13; // di
  hkBool resulta; // [rsp+30h] [rbp+8h]

  v7 = this;
  v8 = transform;
  v9 = geometries;
  v10 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  if ( *(_QWORD *)&v7[-1].m_hashCountMap.m_map.m_numElems )
  {
    v11 = getGeometryByteSize(v9);
    hkOArchive::write32(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, v11 + 45);
    hkOArchive::write8u(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, 5);
    hkServerDebugDisplayHandler::sendGeometryData((hkServerDebugDisplayHandler *)((char *)v7 - 64), v9);
    hkDisplaySerializeOStream::writeTransform(
      *(hkDisplaySerializeOStream **)&v7[-1].m_hashCountMap.m_map.m_numElems,
      v8);
    hkOArchive::write32u(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, color);
    hkOArchive::write64u(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v12 = *(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems;
  v13 = v12 && hkOArchive::isOk(v12, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v7->m_memSizeAndFlags);
  v10->m_enum = v13 == 0;
  return v10;
}

// File Line: 189
// RVA: 0xE7BB30
hkResult *__fastcall hkServerDebugDisplayHandler::displayGeometry(hkServerDebugDisplayHandler *this, hkResult *result, hkArrayBase<hkDisplayGeometry *> *geometries, unsigned int color, int id, int tag)
{
  hkServerDebugDisplayHandler *v6; // rbx
  unsigned int v7; // ebp
  hkArrayBase<hkDisplayGeometry *> *v8; // rdi
  hkResult *v9; // rsi
  unsigned int v10; // eax
  hkOArchive *v11; // rcx
  bool v12; // di
  hkBool resulta; // [rsp+30h] [rbp+8h]

  v6 = this;
  v7 = color;
  v8 = geometries;
  v9 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  if ( *(_QWORD *)&v6[-1].m_hashCountMap.m_map.m_numElems )
  {
    v10 = getGeometryByteSize(v8);
    hkOArchive::write32(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, v10 + 17);
    hkOArchive::write8u(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, 6);
    hkServerDebugDisplayHandler::sendGeometryData((hkServerDebugDisplayHandler *)((char *)v6 - 64), v8);
    hkOArchive::write32u(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, v7);
    hkOArchive::write64u(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v11 = *(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems;
  v12 = v11 && hkOArchive::isOk(v11, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v6->m_memSizeAndFlags);
  v9->m_enum = v12 == 0;
  return v9;
}

// File Line: 216
// RVA: 0xE7AB60
hkResult *__fastcall hkServerDebugDisplayHandler::setGeometryColor(hkServerDebugDisplayHandler *this, hkResult *result, unsigned int color, unsigned __int64 id, int tag)
{
  hkServerDebugDisplayHandler *v5; // rbx
  unsigned __int64 v6; // rdi
  unsigned int v7; // ebp
  hkResult *v8; // rsi
  hkOArchive *v9; // rcx
  hkOArchive *v10; // rcx
  bool v11; // di
  hkBool resulta; // [rsp+30h] [rbp+8h]

  v5 = this;
  v6 = id;
  v7 = color;
  v8 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v9 = *(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems;
  if ( v9 )
  {
    hkOArchive::write32u(v9, 0x11u);
    hkOArchive::write8u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, 3);
    hkOArchive::write32u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, v7);
    hkOArchive::write64u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, v6);
    hkOArchive::write32(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v10 = *(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems;
  v11 = v10 && hkOArchive::isOk(v10, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v5->m_memSizeAndFlags);
  v8->m_enum = v11 == 0;
  return v8;
}

// File Line: 240
// RVA: 0xE7AC20
hkResult *__fastcall hkServerDebugDisplayHandler::setGeometryTransparency(hkServerDebugDisplayHandler *this, hkResult *result, float alpha, unsigned __int64 id, int tag)
{
  hkServerDebugDisplayHandler *v5; // rbx
  unsigned __int64 v6; // rdi
  hkResult *v7; // rsi
  hkOArchive *v8; // rcx
  hkOArchive *v9; // rcx
  bool v10; // di
  hkBool resulta; // [rsp+40h] [rbp+8h]

  v5 = this;
  v6 = id;
  v7 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v8 = *(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems;
  if ( v8 )
  {
    hkOArchive::write32u(v8, 0x11u);
    hkOArchive::write8u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, 31);
    hkOArchive::writeFloat32(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, alpha);
    hkOArchive::write64u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, v6);
    hkOArchive::write32(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v9 = *(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems;
  v10 = v9 && hkOArchive::isOk(v9, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v5->m_memSizeAndFlags);
  v7->m_enum = v10 == 0;
  return v7;
}

// File Line: 264
// RVA: 0xE7ACE0
hkResult *__fastcall hkServerDebugDisplayHandler::updateGeometry(hkServerDebugDisplayHandler *this, hkResult *result, hkTransformf *transform, unsigned __int64 id, int tag)
{
  hkServerDebugDisplayHandler *v5; // rbx
  unsigned __int64 v6; // rdi
  hkTransformf *v7; // rbp
  hkResult *v8; // rsi
  hkOArchive *v9; // rcx
  hkOArchive *v10; // rcx
  bool v11; // di
  hkBool resulta; // [rsp+30h] [rbp+8h]

  v5 = this;
  v6 = id;
  v7 = transform;
  v8 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v9 = *(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems;
  if ( v9 )
  {
    hkOArchive::write32u(v9, 0x29u);
    hkOArchive::write8u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, 2);
    hkDisplaySerializeOStream::writeTransform(
      *(hkDisplaySerializeOStream **)&v5[-1].m_hashCountMap.m_map.m_numElems,
      v7);
    hkOArchive::write64u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, v6);
    hkOArchive::write32(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v10 = *(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems;
  v11 = v10 && hkOArchive::isOk(v10, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v5->m_memSizeAndFlags);
  v8->m_enum = v11 == 0;
  return v8;
}

// File Line: 289
// RVA: 0xE7AE70
hkResult *__fastcall hkServerDebugDisplayHandler::updateGeometryVerts(hkServerDebugDisplayHandler *this, hkResult *result, unsigned __int64 geomID, hkArray<hkVector4f,hkContainerHeapAllocator> *newVerts, int tag)
{
  hkServerDebugDisplayHandler *v5; // rdi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v6; // rsi
  unsigned __int64 v7; // rbx
  hkResult *v8; // r14
  hkResultEnum v9; // ebp
  int i; // ebx
  hkOArchive *v11; // rcx
  bool v12; // bl
  hkResult *v13; // rax
  hkBool resulta; // [rsp+40h] [rbp+8h]

  v5 = this;
  v6 = newVerts;
  v7 = geomID;
  v8 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  hkOArchive::write32u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, 12 * v6->m_size + 17);
  hkOArchive::write8u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, 211);
  hkOArchive::write64u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, v7);
  hkOArchive::write32u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, v6->m_size);
  v9 = 0;
  for ( i = 0; i < v6->m_size; ++i )
    hkDisplaySerializeOStream::writeQuadVector4(
      *(hkDisplaySerializeOStream **)&v5[-1].m_hashCountMap.m_map.m_numElems,
      &v6->m_data[i]);
  hkOArchive::write32(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, tag);
  v11 = *(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems;
  v12 = v11 && hkOArchive::isOk(v11, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v5->m_memSizeAndFlags);
  LOBYTE(v9) = v12 == 0;
  v13 = v8;
  v8->m_enum = v9;
  return v13;
}

// File Line: 312
// RVA: 0xE7ADA0
hkResult *__fastcall hkServerDebugDisplayHandler::updateGeometry(hkServerDebugDisplayHandler *this, hkResult *result, hkMatrix4f *transform, unsigned __int64 id, int tag)
{
  hkServerDebugDisplayHandler *v5; // rbx
  unsigned __int64 v6; // rdi
  hkMatrix4f *v7; // rbp
  hkResult *v8; // rsi
  hkOArchive *v9; // rcx
  hkOArchive *v10; // rcx
  bool v11; // di
  hkBool resulta; // [rsp+30h] [rbp+8h]

  v5 = this;
  v6 = id;
  v7 = transform;
  v8 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v9 = *(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems;
  if ( v9 )
  {
    hkOArchive::write32u(v9, 0x4Du);
    hkOArchive::write8u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, 23);
    hkOArchive::write64u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, v6);
    hkOArchive::writeArrayFloat32(
      *(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems,
      v7->m_col0.m_quad.m128_f32,
      16);
    hkOArchive::write32(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v10 = *(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems;
  v11 = v10 && hkOArchive::isOk(v10, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v5->m_memSizeAndFlags);
  v8->m_enum = v11 == 0;
  return v8;
}

// File Line: 336
// RVA: 0xE7AF60
hkResult *__fastcall hkServerDebugDisplayHandler::skinGeometry(hkServerDebugDisplayHandler *this, hkResult *result, unsigned __int64 *ids, int numIds, hkMatrix4f *poseModel, int numPoseModel, hkMatrix4f *worldFromModel, int tag)
{
  hkServerDebugDisplayHandler *v8; // rdi
  __int64 v9; // rsi
  unsigned __int64 *v10; // r14
  hkResult *v11; // r15
  _QWORD *v12; // rax
  _QWORD *v13; // rcx
  _QWORD *v14; // r8
  unsigned __int64 v15; // rax
  signed __int64 v16; // rcx
  hkOArchive *v17; // rcx
  hkResultEnum v18; // ebp
  int v19; // er12
  signed int v20; // er13
  __int64 i; // rbx
  _QWORD *v22; // rax
  unsigned __int64 v23; // rcx
  signed __int64 v24; // rcx
  hkOArchive *v25; // rcx
  bool v26; // bl
  _QWORD *v27; // rax
  _QWORD *v28; // rcx
  _QWORD *v29; // r8
  unsigned __int64 v30; // rax
  signed __int64 v31; // rcx
  hkResult *v32; // rax
  hkBool resulta; // [rsp+50h] [rbp+8h]

  v8 = this;
  v9 = numIds;
  v10 = ids;
  v11 = result;
  v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)v12[1];
  v14 = v12;
  if ( (unsigned __int64)v13 < v12[3] )
  {
    *v13 = "Ttsend skin";
    v15 = __rdtsc();
    v16 = (signed __int64)(v13 + 2);
    *(_DWORD *)(v16 - 8) = v15;
    v14[1] = v16;
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&v8->m_memSizeAndFlags);
  v17 = *(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems;
  v18 = 0;
  if ( v17 )
  {
    v19 = 16 * numPoseModel;
    v20 = 4 * (16 * numPoseModel + 2 * v9) + 77;
    hkOArchive::write32u(v17, v20);
    hkOArchive::write8u(*(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems, 24);
    hkOArchive::write32u(*(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems, v9);
    for ( i = 0i64; i < v9; ++i )
      hkOArchive::write64u(*(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems, v10[i]);
    hkOArchive::write32u(*(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems, numPoseModel);
    hkOArchive::writeArrayFloat32(
      *(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems,
      poseModel->m_col0.m_quad.m128_f32,
      v19);
    hkOArchive::writeArrayFloat32(
      *(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems,
      worldFromModel->m_col0.m_quad.m128_f32,
      16);
    hkOArchive::write32(*(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems, tag);
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
  v25 = *(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems;
  v26 = v25 && hkOArchive::isOk(v25, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v8->m_memSizeAndFlags);
  v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v28 = (_QWORD *)v27[1];
  v29 = v27;
  if ( (unsigned __int64)v28 < v27[3] )
  {
    *v28 = "Et";
    v30 = __rdtsc();
    v31 = (signed __int64)(v28 + 2);
    *(_DWORD *)(v31 - 8) = v30;
    v29[1] = v31;
  }
  v32 = v11;
  LOBYTE(v18) = v26 == 0;
  v11->m_enum = v18;
  return v32;
}

// File Line: 372
// RVA: 0xE7B150
hkResult *__fastcall hkServerDebugDisplayHandler::removeGeometry(hkServerDebugDisplayHandler *this, hkResult *result, unsigned __int64 id, int tag)
{
  hkServerDebugDisplayHandler *v4; // rbx
  int v5; // edi
  unsigned __int64 v6; // rbp
  hkResult *v7; // rsi
  hkOArchive *v8; // rcx
  hkOArchive *v9; // rcx
  bool v10; // di
  hkBool resulta; // [rsp+30h] [rbp+8h]

  v4 = this;
  v5 = tag;
  v6 = id;
  v7 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v8 = *(hkOArchive **)&v4[-1].m_hashCountMap.m_map.m_numElems;
  if ( v8 )
  {
    hkOArchive::write32u(v8, 0xDu);
    hkOArchive::write8u(*(hkOArchive **)&v4[-1].m_hashCountMap.m_map.m_numElems, 4);
    hkOArchive::write64u(*(hkOArchive **)&v4[-1].m_hashCountMap.m_map.m_numElems, v6);
    hkOArchive::write32(*(hkOArchive **)&v4[-1].m_hashCountMap.m_map.m_numElems, v5);
  }
  v9 = *(hkOArchive **)&v4[-1].m_hashCountMap.m_map.m_numElems;
  v10 = v9 && hkOArchive::isOk(v9, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v4->m_memSizeAndFlags);
  v7->m_enum = v10 == 0;
  return v7;
}

// File Line: 396
// RVA: 0xE7B210
hkResult *__fastcall hkServerDebugDisplayHandler::updateCamera(hkServerDebugDisplayHandler *this, hkResult *result, hkVector4f *from, hkVector4f *to, hkVector4f *up, float nearPlane, float farPlane, float fov, const char *name)
{
  hkServerDebugDisplayHandler *v9; // rsi
  hkVector4f *v10; // rbp
  hkVector4f *v11; // r15
  hkResult *v12; // r14
  unsigned int v13; // ebx
  hkOArchive *v14; // rcx
  bool v15; // bl
  hkBool resulta; // [rsp+40h] [rbp+8h]

  v9 = this;
  v10 = to;
  v11 = from;
  v12 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  if ( *(_QWORD *)&v9[-1].m_hashCountMap.m_map.m_numElems )
  {
    v13 = hkString::strLen(name);
    hkOArchive::write32u(*(hkOArchive **)&v9[-1].m_hashCountMap.m_map.m_numElems, v13 + 51);
    hkOArchive::write8u(*(hkOArchive **)&v9[-1].m_hashCountMap.m_map.m_numElems, 13);
    hkDisplaySerializeOStream::writeQuadVector4(
      *(hkDisplaySerializeOStream **)&v9[-1].m_hashCountMap.m_map.m_numElems,
      v11);
    hkDisplaySerializeOStream::writeQuadVector4(
      *(hkDisplaySerializeOStream **)&v9[-1].m_hashCountMap.m_map.m_numElems,
      v10);
    hkDisplaySerializeOStream::writeQuadVector4(
      *(hkDisplaySerializeOStream **)&v9[-1].m_hashCountMap.m_map.m_numElems,
      up);
    hkOArchive::writeFloat32(*(hkOArchive **)&v9[-1].m_hashCountMap.m_map.m_numElems, nearPlane);
    hkOArchive::writeFloat32(*(hkOArchive **)&v9[-1].m_hashCountMap.m_map.m_numElems, farPlane);
    hkOArchive::writeFloat32(*(hkOArchive **)&v9[-1].m_hashCountMap.m_map.m_numElems, fov);
    hkOArchive::write16u(*(hkOArchive **)&v9[-1].m_hashCountMap.m_map.m_numElems, v13);
    hkOArchive::writeRaw(*(hkOArchive **)&v9[-1].m_hashCountMap.m_map.m_numElems, name, v13);
  }
  v14 = *(hkOArchive **)&v9[-1].m_hashCountMap.m_map.m_numElems;
  v15 = v14 && hkOArchive::isOk(v14, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v9->m_memSizeAndFlags);
  v12->m_enum = v15 == 0;
  return v12;
}

// File Line: 427
// RVA: 0xE7B330
hkResult *__fastcall hkServerDebugDisplayHandler::displayPoint(hkServerDebugDisplayHandler *this, hkResult *result, hkVector4f *position, unsigned int color, int id, int tag)
{
  hkServerDebugDisplayHandler *v6; // rbx
  unsigned int v7; // edi
  hkVector4f *v8; // rbp
  hkResult *v9; // rsi
  hkOArchive *v10; // rcx
  hkOArchive *v11; // rcx
  bool v12; // di
  hkBool resulta; // [rsp+30h] [rbp+8h]

  v6 = this;
  v7 = color;
  v8 = position;
  v9 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v10 = *(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems;
  if ( v10 )
  {
    hkOArchive::write32u(v10, 0x1Du);
    hkOArchive::write8u(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, 7);
    hkDisplaySerializeOStream::writeQuadVector4(
      *(hkDisplaySerializeOStream **)&v6[-1].m_hashCountMap.m_map.m_numElems,
      v8);
    hkOArchive::write32u(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, v7);
    hkOArchive::write64u(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v11 = *(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems;
  v12 = v11 && hkOArchive::isOk(v11, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v6->m_memSizeAndFlags);
  v9->m_enum = v12 == 0;
  return v9;
}

// File Line: 452
// RVA: 0xE7B400
hkResult *__fastcall hkServerDebugDisplayHandler::displayLine(hkServerDebugDisplayHandler *this, hkResult *result, hkVector4f *start, hkVector4f *end, unsigned int color, int id, int tag)
{
  hkServerDebugDisplayHandler *v7; // rbx
  hkVector4f *v8; // rdi
  hkVector4f *v9; // rbp
  hkResult *v10; // rsi
  hkOArchive *v11; // rcx
  hkOArchive *v12; // rcx
  bool v13; // di
  hkBool resulta; // [rsp+30h] [rbp+8h]

  v7 = this;
  v8 = end;
  v9 = start;
  v10 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v11 = *(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems;
  if ( v11 )
  {
    hkOArchive::write32u(v11, 0x29u);
    hkOArchive::write8u(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, 8);
    hkDisplaySerializeOStream::writeQuadVector4(
      *(hkDisplaySerializeOStream **)&v7[-1].m_hashCountMap.m_map.m_numElems,
      v9);
    hkDisplaySerializeOStream::writeQuadVector4(
      *(hkDisplaySerializeOStream **)&v7[-1].m_hashCountMap.m_map.m_numElems,
      v8);
    hkOArchive::write32u(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, color);
    hkOArchive::write64u(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v12 = *(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems;
  v13 = v12 && hkOArchive::isOk(v12, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v7->m_memSizeAndFlags);
  v10->m_enum = v13 == 0;
  return v10;
}

// File Line: 478
// RVA: 0xE7B4E0
hkResult *__fastcall hkServerDebugDisplayHandler::displayTriangle(hkServerDebugDisplayHandler *this, hkResult *result, hkVector4f *a, hkVector4f *b, hkVector4f *c, unsigned int color, int id, int tag)
{
  hkServerDebugDisplayHandler *v8; // rbx
  hkVector4f *v9; // rdi
  hkVector4f *v10; // rbp
  hkResult *v11; // rsi
  __int128 v12; // xmm0
  unsigned int v13; // er12
  __m128 v14; // xmm1
  unsigned __int64 v15; // r14
  int v16; // er15
  hkVector4f *v17; // rdi
  signed __int64 v18; // rbp
  hkOArchive *v19; // rcx
  bool v20; // di
  hkVector4f v; // [rsp+20h] [rbp-68h]
  __int128 v23; // [rsp+30h] [rbp-58h]
  __m128 v24; // [rsp+40h] [rbp-48h]
  __m128 v25; // [rsp+50h] [rbp-38h]
  hkBool resulta; // [rsp+90h] [rbp+8h]

  v8 = this;
  v9 = b;
  v10 = a;
  v11 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  if ( *(_QWORD *)&v8[-1].m_hashCountMap.m_map.m_numElems )
  {
    v12 = (__int128)v9->m_quad;
    v13 = color;
    v14 = c->m_quad;
    v.m_quad = v10->m_quad;
    v23 = v12;
    v15 = id;
    v16 = tag;
    v24 = v14;
    v25 = v.m_quad;
    v17 = &v;
    v18 = 3i64;
    do
    {
      hkOArchive::write32u(*(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems, 0x29u);
      hkOArchive::write8u(*(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems, 8);
      hkDisplaySerializeOStream::writeQuadVector4(
        *(hkDisplaySerializeOStream **)&v8[-1].m_hashCountMap.m_map.m_numElems,
        v17);
      ++v17;
      hkDisplaySerializeOStream::writeQuadVector4(
        *(hkDisplaySerializeOStream **)&v8[-1].m_hashCountMap.m_map.m_numElems,
        v17);
      hkOArchive::write32u(*(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems, v13);
      hkOArchive::write64u(*(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems, v15);
      hkOArchive::write32(*(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems, v16);
      --v18;
    }
    while ( v18 );
  }
  v19 = *(hkOArchive **)&v8[-1].m_hashCountMap.m_map.m_numElems;
  v20 = v19 && hkOArchive::isOk(v19, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v8->m_memSizeAndFlags);
  v11->m_enum = v20 == 0;
  return v11;
}

// File Line: 512
// RVA: 0xE7B630
hkResult *__fastcall hkServerDebugDisplayHandler::displayText(hkServerDebugDisplayHandler *this, hkResult *result, const char *text, unsigned int color, int id, int tag)
{
  hkServerDebugDisplayHandler *v6; // rdi
  int v7; // er14
  const char *v8; // rbp
  hkResult *v9; // rsi
  signed int v10; // eax
  unsigned int v11; // ebx
  hkOArchive *v12; // rcx
  bool v13; // bl
  hkBool resulta; // [rsp+40h] [rbp+8h]

  v6 = this;
  v7 = color;
  v8 = text;
  v9 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  if ( *(_QWORD *)&v6[-1].m_hashCountMap.m_map.m_numElems )
  {
    v10 = hkString::strLen(v8);
    v11 = 0xFFFF;
    if ( v10 < 0xFFFF )
      v11 = v10;
    hkOArchive::write32u(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, v11 + 19);
    hkOArchive::write8u(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, 9);
    hkOArchive::write16u(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, v11);
    hkOArchive::writeRaw(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, v8, v11);
    hkOArchive::write32(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, v7);
    hkOArchive::write64u(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v12 = *(hkOArchive **)&v6[-1].m_hashCountMap.m_map.m_numElems;
  v13 = v12 && hkOArchive::isOk(v12, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v6->m_memSizeAndFlags);
  v9->m_enum = v13 == 0;
  return v9;
}

// File Line: 539
// RVA: 0xE7B720
hkResult *__fastcall hkServerDebugDisplayHandler::display3dText(hkServerDebugDisplayHandler *this, hkResult *result, const char *text, hkVector4f *pos, unsigned int color, int id, int tag)
{
  hkServerDebugDisplayHandler *v7; // rdi
  hkVector4f *v8; // rbp
  const char *v9; // r14
  hkResult *v10; // rsi
  signed int v11; // eax
  unsigned int v12; // ebx
  hkOArchive *v13; // rcx
  bool v14; // bl
  hkBool resulta; // [rsp+40h] [rbp+8h]

  v7 = this;
  v8 = pos;
  v9 = text;
  v10 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  if ( *(_QWORD *)&v7[-1].m_hashCountMap.m_map.m_numElems )
  {
    v11 = hkString::strLen(v9);
    v12 = 0xFFFF;
    if ( v11 < 0xFFFF )
      v12 = v11;
    hkOArchive::write32u(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, v12 + 31);
    hkOArchive::write8u(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, 17);
    hkOArchive::write16u(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, v12);
    hkOArchive::writeRaw(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, v9, v12);
    hkOArchive::write32(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, color);
    hkOArchive::write64u(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, tag);
    hkOArchive::writeFloat32(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, v8->m_quad.m128_f32[0]);
    hkOArchive::writeFloat32(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, v8->m_quad.m128_f32[1]);
    hkOArchive::writeFloat32(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, v8->m_quad.m128_f32[2]);
  }
  v13 = *(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems;
  v14 = v13 && hkOArchive::isOk(v13, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v7->m_memSizeAndFlags);
  v10->m_enum = v14 == 0;
  return v10;
}

// File Line: 570
// RVA: 0xE7B840
hkResult *__fastcall hkServerDebugDisplayHandler::displayPoint2d(hkServerDebugDisplayHandler *this, hkResult *result, hkVector4f *position, unsigned int color)
{
  result->m_enum = 0;
  return result;
}

// File Line: 575
// RVA: 0xE7B850
hkResult *__fastcall hkServerDebugDisplayHandler::displayLine2d(hkServerDebugDisplayHandler *this, hkResult *result, hkVector4f *start, hkVector4f *end)
{
  result->m_enum = 0;
  return result;
}

// File Line: 580
// RVA: 0xE7B860
hkResult *__fastcall hkServerDebugDisplayHandler::displayTriangle2d(hkServerDebugDisplayHandler *this, hkResult *result, hkVector4f *a, hkVector4f *b)
{
  result->m_enum = 0;
  return result;
}

// File Line: 585
// RVA: 0xE7B870
hkResult *__fastcall hkServerDebugDisplayHandler::displayText2d(hkServerDebugDisplayHandler *this, hkResult *result, const char *text, hkVector4f *pos)
{
  result->m_enum = 0;
  return result;
}

// File Line: 590
// RVA: 0xE7B880
hkResult *__fastcall hkServerDebugDisplayHandler::displayAnnotation(hkServerDebugDisplayHandler *this, hkResult *result, const char *text, int id, int tag)
{
  hkServerDebugDisplayHandler *v5; // rdi
  unsigned __int64 v6; // r14
  const char *v7; // rbp
  hkResult *v8; // rsi
  signed int v9; // eax
  unsigned int v10; // ebx
  hkOArchive *v11; // rcx
  bool v12; // bl
  hkBool resulta; // [rsp+40h] [rbp+8h]

  v5 = this;
  v6 = id;
  v7 = text;
  v8 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  if ( *(_QWORD *)&v5[-1].m_hashCountMap.m_map.m_numElems )
  {
    v9 = hkString::strLen(v7);
    v10 = 0xFFFF;
    if ( v9 < 0xFFFF )
      v10 = v9;
    hkOArchive::write32u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, v10 + 15);
    hkOArchive::write8u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, 20);
    hkOArchive::write16u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, v10);
    hkOArchive::writeRaw(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, v7, v10);
    hkOArchive::write64u(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, v6);
    hkOArchive::write32(*(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v11 = *(hkOArchive **)&v5[-1].m_hashCountMap.m_map.m_numElems;
  v12 = v11 && hkOArchive::isOk(v11, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v5->m_memSizeAndFlags);
  v8->m_enum = v12 == 0;
  return v8;
}

// File Line: 616
// RVA: 0xE7B960
hkResult *__fastcall hkServerDebugDisplayHandler::displayBone(hkServerDebugDisplayHandler *this, hkResult *result, hkVector4f *a, hkVector4f *b, hkQuaternionf *orientation, unsigned int color, int tag)
{
  hkServerDebugDisplayHandler *v7; // rbx
  hkVector4f *v8; // rdi
  hkVector4f *v9; // rbp
  hkResult *v10; // rsi
  hkOArchive *v11; // rcx
  hkOArchive *v12; // rcx
  bool v13; // di
  hkBool resulta; // [rsp+30h] [rbp+8h]

  v7 = this;
  v8 = b;
  v9 = a;
  v10 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v11 = *(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems;
  if ( v11 )
  {
    hkOArchive::write32u(v11, 0x31u);
    hkOArchive::write8u(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, 30);
    hkDisplaySerializeOStream::writeQuadVector4(
      *(hkDisplaySerializeOStream **)&v7[-1].m_hashCountMap.m_map.m_numElems,
      v9);
    hkDisplaySerializeOStream::writeQuadVector4(
      *(hkDisplaySerializeOStream **)&v7[-1].m_hashCountMap.m_map.m_numElems,
      v8);
    hkOArchive::writeArrayFloat32(
      *(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems,
      orientation->m_vec.m_quad.m128_f32,
      4);
    hkOArchive::write32(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, color);
    hkOArchive::write32(*(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v12 = *(hkOArchive **)&v7[-1].m_hashCountMap.m_map.m_numElems;
  v13 = v12 && hkOArchive::isOk(v12, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v7->m_memSizeAndFlags);
  v10->m_enum = v13 == 0;
  return v10;
}

// File Line: 641
// RVA: 0xE7BC10
hkResult *__fastcall hkServerDebugDisplayHandler::sendMemStatsDump(hkServerDebugDisplayHandler *this, hkResult *result, const char *data, int length)
{
  hkServerDebugDisplayHandler *v4; // rbx
  unsigned int v5; // edi
  const char *v6; // rbp
  hkResult *v7; // rsi
  hkOArchive *v8; // rcx
  hkOArchive *v9; // rcx
  bool v10; // di
  hkBool resulta; // [rsp+30h] [rbp+8h]

  v4 = this;
  v5 = length;
  v6 = data;
  v7 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v8 = *(hkOArchive **)&v4[-1].m_hashCountMap.m_map.m_numElems;
  if ( v8 )
  {
    hkOArchive::write32u(v8, v5 + 5);
    hkOArchive::write8u(*(hkOArchive **)&v4[-1].m_hashCountMap.m_map.m_numElems, 15);
    hkOArchive::write32(*(hkOArchive **)&v4[-1].m_hashCountMap.m_map.m_numElems, v5);
    hkOArchive::writeRaw(*(hkOArchive **)&v4[-1].m_hashCountMap.m_map.m_numElems, v6, v5);
  }
  v9 = *(hkOArchive **)&v4[-1].m_hashCountMap.m_map.m_numElems;
  v10 = v9 && hkOArchive::isOk(v9, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v4->m_memSizeAndFlags);
  v7->m_enum = v10 == 0;
  return v7;
}

// File Line: 664
// RVA: 0xE7BCD0
hkResult *__fastcall hkServerDebugDisplayHandler::holdImmediate(hkServerDebugDisplayHandler *this, hkResult *result)
{
  hkServerDebugDisplayHandler *v2; // rbx
  hkResult *v3; // rsi
  hkOArchive *v4; // rcx
  hkOArchive *v5; // rcx
  bool v6; // di
  hkBool resulta; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v4 = *(hkOArchive **)&v2[-1].m_hashCountMap.m_map.m_numElems;
  if ( v4 )
  {
    hkOArchive::write32u(v4, 1u);
    hkOArchive::write8u(*(hkOArchive **)&v2[-1].m_hashCountMap.m_map.m_numElems, 11);
  }
  v5 = *(hkOArchive **)&v2[-1].m_hashCountMap.m_map.m_numElems;
  v6 = v5 && hkOArchive::isOk(v5, &resulta)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v2->m_memSizeAndFlags);
  v3->m_enum = v6 == 0;
  return v3;
}

// File Line: 690
// RVA: 0xE7BD60
void __fastcall hkServerDebugDisplayHandler::getConsumableCommands(hkServerDebugDisplayHandler *this, char **commands, int *numCommands)
{
  *commands = serverDebugDisplayHandler_cmds;
  *numCommands = 3;
}

// File Line: 696
// RVA: 0xE7BD80
void __fastcall hkServerDebugDisplayHandler::consumeCommand(hkServerDebugDisplayHandler *this, char command)
{
  hkServerDebugDisplayHandler *v2; // rbx
  hkIArchive *v3; // rcx
  int array; // [rsp+38h] [rbp+10h]
  hkStringPtr v5; // [rsp+40h] [rbp+18h]

  v2 = this;
  switch ( command )
  {
    case 48:
      hkDisplaySerializeIStream::readHash((hkDisplaySerializeIStream *)this->vfptr, (unsigned __int64 *)&v5);
      hkServerDebugDisplayHandler::processGeometryWithHashRequested(
        (hkServerDebugDisplayHandler *)((char *)v2 - 16),
        (const unsigned __int64 *)&v5);
      break;
    case 49:
      hkDisplaySerializeIStream::readHash((hkDisplaySerializeIStream *)this->vfptr, (unsigned __int64 *)&v5);
      hkServerDebugDisplayHandler::processGeometryWithHashNotRequested(
        (hkServerDebugDisplayHandler *)((char *)v2 - 16),
        (const unsigned __int64 *)&v5);
      break;
    case 50:
      hkStringPtr::hkStringPtr(&v5);
      hkIArchive::readArrayGeneric((hkIArchive *)v2->vfptr, &array, 4, 1);
      v3 = (hkIArchive *)v2->vfptr;
      LODWORD(v2->m_hashCountMap.m_map.m_elem) = array;
      hkIArchive::readArrayGeneric(v3, &array, 1, 1);
      LOBYTE(v2->m_hashCountMap.m_map.m_numElems) = (_BYTE)array != 0;
      hkIArchive::readArrayGeneric((hkIArchive *)v2->vfptr, &array, 4, 1);
      HIDWORD(v2->m_hashCountMap.m_map.m_elem) = array;
      hkStringPtr::~hkStringPtr(&v5);
      break;
  }
}

// File Line: 727
// RVA: 0xE7CA20
hkResult *__fastcall hkServerDebugDisplayHandler::useGeometryForHash(hkServerDebugDisplayHandler *this, hkResult *result, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *geometries, const unsigned __int64 *hash, hkBool final)
{
  hkServerDebugDisplayHandler *v5; // rbx
  const unsigned __int64 *v6; // rbp
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v7; // rdi
  hkResult *v8; // rsi
  unsigned int v9; // eax
  hkOArchive *v10; // rcx
  bool v11; // di
  hkBool resulta; // [rsp+30h] [rbp+8h]

  v5 = this;
  v6 = hash;
  v7 = geometries;
  v8 = result;
  EnterCriticalSection(&this->m_outstreamLock->m_section);
  if ( v5->m_outStream )
  {
    v9 = getGeometryByteSize((hkArrayBase<hkDisplayGeometry *> *)&v7->m_data);
    hkOArchive::write32((hkOArchive *)&v5->m_outStream->vfptr, v9 + 9);
    hkOArchive::write8u((hkOArchive *)&v5->m_outStream->vfptr, (final.m_bool != 0) + 28);
    hkDisplaySerializeOStream::writeHash(v5->m_outStream, v6);
    hkServerDebugDisplayHandler::sendGeometryData(v5, (hkArrayBase<hkDisplayGeometry *> *)&v7->m_data);
  }
  v10 = (hkOArchive *)&v5->m_outStream->vfptr;
  v11 = v10 && hkOArchive::isOk(v10, &resulta)->m_bool;
  LeaveCriticalSection(&v5->m_outstreamLock->m_section);
  v8->m_enum = v11 == 0;
  return v8;
}

// File Line: 751
// RVA: 0xE7BF80
hkResult *__fastcall hkServerDebugDisplayHandler::addGeometryHash(hkServerDebugDisplayHandler *this, hkResult *result, hkReferencedObject *source, hkDisplayGeometryBuilder *builder, const unsigned __int64 *hash, hkAabb *aabb, unsigned int color, hkTransformf *transform, unsigned __int64 id, int tag)
{
  hkServerDebugDisplayHandler *v10; // rbx
  hkDisplayGeometryBuilder *v11; // r12
  hkResult *v12; // r14
  hkOArchive *v13; // rcx
  const unsigned __int64 *v14; // rbp
  hkOArchive *v15; // rcx
  bool v16; // di
  int v17; // eax
  signed __int64 v18; // rsi
  int v19; // er13
  __int64 v20; // rdx
  unsigned __int64 *v21; // r8
  unsigned __int64 v22; // rax
  hkReferencedObject *v24; // [rsp+60h] [rbp+18h]

  v24 = source;
  v10 = this;
  v11 = builder;
  v12 = result;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)&this->m_memSizeAndFlags);
  v13 = *(hkOArchive **)&v10[-1].m_hashCountMap.m_map.m_numElems;
  v14 = hash;
  if ( v13 )
  {
    hkOArchive::write32(v13, 77);
    hkOArchive::write8u(*(hkOArchive **)&v10[-1].m_hashCountMap.m_map.m_numElems, 27);
    hkDisplaySerializeOStream::writeHash(*(hkDisplaySerializeOStream **)&v10[-1].m_hashCountMap.m_map.m_numElems, v14);
    hkDisplaySerializeOStream::writeAabb(*(hkDisplaySerializeOStream **)&v10[-1].m_hashCountMap.m_map.m_numElems, aabb);
    hkOArchive::write32u(*(hkOArchive **)&v10[-1].m_hashCountMap.m_map.m_numElems, color);
    hkDisplaySerializeOStream::writeTransform(
      *(hkDisplaySerializeOStream **)&v10[-1].m_hashCountMap.m_map.m_numElems,
      transform);
    hkOArchive::write64u(*(hkOArchive **)&v10[-1].m_hashCountMap.m_map.m_numElems, id);
    hkOArchive::write32(*(hkOArchive **)&v10[-1].m_hashCountMap.m_map.m_numElems, tag);
  }
  v15 = *(hkOArchive **)&v10[-1].m_hashCountMap.m_map.m_numElems;
  v16 = v15 && hkOArchive::isOk(v15, (hkBool *)&hash)->m_bool;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)&v10->m_memSizeAndFlags);
  v17 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findOrInsertKey(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v10->m_processHandler,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          *v14,
          0i64);
  v18 = 2i64 * v17;
  v19 = (int)v10->m_processHandler[2 * v17 + 1].vfptr;
  if ( !v19 )
  {
    if ( *(_DWORD *)&v10->m_selectable.m_bool == (*((_DWORD *)&v10->m_selectable + 1) & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v10->vfptr, 24);
    v20 = *(signed int *)&v10->m_selectable.m_bool;
    v21 = (unsigned __int64 *)((char *)v10->vfptr + 24 * v20);
    *(_DWORD *)&v10->m_selectable.m_bool = v20 + 1;
    v22 = *v14;
    v21[2] = (unsigned __int64)v11;
    *v21 = v22;
    v21[1] = (unsigned __int64)v24;
    hkReferencedObject::addReference(v24);
    hkReferencedObject::addReference((hkReferencedObject *)&v11->vfptr);
  }
  v10->m_processHandler[v18 + 1].vfptr = (hkProcessHandlerVtbl *)(v19 + 1);
  v12->m_enum = v16 == 0;
  return v12;
}

// File Line: 798
// RVA: 0xE7C460
void __fastcall hkServerDebugDisplayHandler::processGeometryWithHashRequested(hkServerDebugDisplayHandler *this, const unsigned __int64 *hash)
{
  hkServerDebugDisplayHandler *v2; // rbx
  int v3; // eax
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *v4; // r14
  int v5; // ebp
  signed __int64 v6; // rsi
  __int64 v7; // rdx
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *v8; // r8
  __int64 v9; // rax
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *v10; // rdx
  signed __int64 v11; // r8
  signed __int64 v12; // rax
  signed __int64 v13; // rdx
  signed __int64 v14; // r8
  __int64 v15; // rcx

  v2 = this;
  v3 = hkServerDebugDisplayHandler::findIndexForGeometryAwaitingRequest(this, hash);
  v4 = v2->m_geometriesAwaitingRequests.m_data;
  v5 = v3;
  v6 = v3;
  if ( v2->m_geometriesAwaitingDeparture.m_size == (v2->m_geometriesAwaitingDeparture.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v2->m_geometriesAwaitingDeparture,
      24);
  v7 = v2->m_geometriesAwaitingDeparture.m_size;
  v8 = &v2->m_geometriesAwaitingDeparture.m_data[v7];
  v2->m_geometriesAwaitingDeparture.m_size = v7 + 1;
  v8->m_hash = v4[v6].m_hash;
  v8->m_source = v4[v6].m_source;
  v8->m_builder = v4[v6].m_builder;
  v9 = --v2->m_geometriesAwaitingRequests.m_size;
  if ( (_DWORD)v9 != v5 )
  {
    v10 = v2->m_geometriesAwaitingRequests.m_data;
    v11 = (signed __int64)&v10[v9];
    v12 = (signed __int64)&v10[v6];
    v13 = 3i64;
    v14 = v11 - v12;
    do
    {
      v15 = *(_QWORD *)(v14 + v12);
      v12 += 8i64;
      *(_QWORD *)(v12 - 8) = v15;
      --v13;
    }
    while ( v13 );
  }
}

// File Line: 809
// RVA: 0xE7C560
void __fastcall hkServerDebugDisplayHandler::processGeometryWithHashNotRequested(hkServerDebugDisplayHandler *this, const unsigned __int64 *hash)
{
  const unsigned __int64 *v2; // rbx
  hkServerDebugDisplayHandler *v3; // rsi
  Dummy *v4; // rbp
  signed __int64 v5; // r10
  int v6; // er8
  int v7; // eax
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *v8; // rbx
  int v9; // edi
  signed __int64 v10; // r15
  __int64 v11; // rax
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *v12; // rdx
  signed __int64 v13; // r8
  signed __int64 v14; // r9
  signed __int64 v15; // rax
  signed __int64 v16; // r9
  __int64 v17; // rdx

  v2 = hash;
  v3 = this;
  v4 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
         (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_hashCountMap.m_map.m_elem,
         *hash);
  v5 = (signed __int64)&v3->m_hashCountMap.m_map.m_elem[(signed int)v4];
  v6 = *(_DWORD *)(v5 + 8) - 1;
  *(_QWORD *)(v5 + 8) = v6;
  if ( !v6 )
  {
    v7 = hkServerDebugDisplayHandler::findIndexForGeometryAwaitingRequest(v3, v2);
    v8 = v3->m_geometriesAwaitingRequests.m_data;
    v9 = v7;
    v10 = v7;
    hkReferencedObject::removeReference((hkReferencedObject *)&v8[v7].m_builder->vfptr);
    hkReferencedObject::removeReference(v8[v10].m_source);
    v11 = --v3->m_geometriesAwaitingRequests.m_size;
    if ( (_DWORD)v11 != v9 )
    {
      v12 = v3->m_geometriesAwaitingRequests.m_data;
      v13 = 3i64;
      v14 = (signed __int64)&v12[v11];
      v15 = (signed __int64)&v12[v10];
      v16 = v14 - (_QWORD)&v12[v10];
      do
      {
        v17 = *(_QWORD *)(v16 + v15);
        v15 += 8i64;
        *(_QWORD *)(v15 - 8) = v17;
        --v13;
      }
      while ( v13 );
    }
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_hashCountMap.m_map.m_elem,
      v4);
  }
}

// File Line: 830
// RVA: 0xE7CAF0
signed __int64 __fastcall hkServerDebugDisplayHandler::findIndexForGeometryAwaitingRequest(hkServerDebugDisplayHandler *this, const unsigned __int64 *hash)
{
  __int64 v2; // r10
  unsigned int v3; // er9
  __int64 v4; // r8
  unsigned __int64 v5; // rdx
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *v6; // rax

  v2 = this->m_geometriesAwaitingRequests.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
    return 0xFFFFFFFFi64;
  v5 = *hash;
  v6 = this->m_geometriesAwaitingRequests.m_data;
  while ( v5 != v6->m_hash )
  {
    ++v4;
    ++v3;
    ++v6;
    if ( v4 >= v2 )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 843
// RVA: 0xE7C650
void __fastcall hkServerDebugDisplayHandler::buildAndSendGeometries(hkServerDebugDisplayHandler *this)
{
  int v1; // er12
  hkServerDebugDisplayHandler *v2; // r14
  __int64 v3; // rax
  int v4; // esi
  __int64 v5; // r13
  __int64 v6; // rcx
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *v7; // r15
  char *v8; // r15
  bool v9; // zf
  __int64 v10; // rbx
  signed int v11; // edi
  int v12; // eax
  __int64 v13; // rcx
  __int64 v14; // r8
  hkReferencedObject *v15; // rax
  int v16; // esi
  __int64 i; // rdi
  hkDisplayGeometry *v18; // rcx
  int v19; // eax
  Dummy *v20; // rdi
  signed __int64 v21; // r9
  int v22; // edx
  __int64 v23; // rdx
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *v24; // r8
  int v25; // eax
  int v26; // edi
  __int64 v27; // rbx
  hkDisplayGeometry *v28; // rcx
  hkServerDebugDisplayHandler::UnbuiltGeometryInfo *v29; // rdx
  int v30; // er9
  __int64 v31; // rcx
  hkDisplayGeometryBuilder *v32; // rax
  __int64 v33; // [rsp+30h] [rbp-A8h]
  __int64 v34; // [rsp+38h] [rbp-A0h]
  hkResult v35; // [rsp+40h] [rbp-98h]
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> geometries; // [rsp+50h] [rbp-88h]
  char v37; // [rsp+60h] [rbp-78h]
  hkErrStream v38; // [rsp+78h] [rbp-60h]
  char buf; // [rsp+98h] [rbp-40h]
  char v40; // [rsp+2E8h] [rbp+210h]
  int v41; // [rsp+2F0h] [rbp+218h]
  int v42; // [rsp+2F8h] [rbp+220h]
  hkResult result; // [rsp+300h] [rbp+228h]

  v1 = 1;
  v2 = this;
  if ( this->m_simpleShapesPerFrame )
    v1 = this->m_simpleShapesPerFrame;
  v3 = this->m_geometriesAwaitingDeparture.m_size;
  v4 = 0;
  v5 = 0i64;
  v41 = 0;
  v34 = v3;
  if ( v3 > 0 )
  {
    v6 = 0i64;
    v33 = 0i64;
    while ( 1 )
    {
      if ( !v1 )
      {
LABEL_42:
        if ( v4 > 0 )
        {
          v2->m_geometriesAwaitingDeparture.m_size -= v4;
          v29 = v2->m_geometriesAwaitingDeparture.m_data;
          v30 = 24 * v2->m_geometriesAwaitingDeparture.m_size;
          if ( v30 > 0 )
          {
            v31 = ((unsigned int)(v30 - 1) >> 3) + 1;
            do
            {
              v32 = (hkDisplayGeometryBuilder *)v29[v4].m_hash;
              v29 = (hkServerDebugDisplayHandler::UnbuiltGeometryInfo *)((char *)v29 + 8);
              v29[-1].m_builder = v32;
              --v31;
            }
            while ( v31 );
          }
        }
        return;
      }
      v7 = v2->m_geometriesAwaitingDeparture.m_data;
      geometries.m_size = 0;
      v8 = (char *)v7 + v6;
      v9 = v2->m_simpleShapesPerFrame == 0;
      geometries.m_data = (hkDisplayGeometry **)&v37;
      geometries.m_capacityAndFlags = -2147483640;
      if ( !v9 || v2->m_simpleShapesPerPart )
        break;
      if ( v2->m_continueData )
        goto LABEL_12;
      (*(void (__fastcall **)(_QWORD, _QWORD, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *))(**((_QWORD **)v8 + 2) + 24i64))(
        *((_QWORD *)v8 + 2),
        *((_QWORD *)v8 + 1),
        &geometries);
      LOBYTE(v10) = 1;
LABEL_21:
      v16 = geometries.m_size - 1;
      for ( i = geometries.m_size - 1; i >= 0; --i )
      {
        v18 = geometries.m_data[i];
        if ( v18->m_type == 6 && !v18->m_geometry )
        {
          hkErrStream::hkErrStream(&v38, &buf, 512);
          hkOstream::operator<<((hkOstream *)&v38.vfptr, "Unable to build some display geometry data");
          hkError::messageReport(-1, &buf, "hkServerDebugDisplayHandler.cpp", 909);
          hkOstream::~hkOstream((hkOstream *)&v38.vfptr);
          v19 = geometries.m_size - 1;
          geometries.m_size = v19;
          if ( v19 != v16 )
            geometries.m_data[i] = geometries.m_data[v19];
        }
        --v16;
      }
      if ( (_BYTE)v10 )
      {
        v33 += 24i64;
        v4 = v41 + 1;
        v2->m_continueData = 0i64;
        ++v5;
        v41 = v4;
        hkServerDebugDisplayHandler::useGeometryForHash(
          v2,
          &result,
          &geometries,
          (const unsigned __int64 *)v8,
          (hkBool)1);
        v20 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_hashCountMap.m_map.m_elem,
                *(_QWORD *)v8);
        v21 = (signed __int64)&v2->m_hashCountMap.m_map.m_elem[(signed int)v20];
        v22 = *(_DWORD *)(v21 + 8) - 1;
        *(_QWORD *)(v21 + 8) = v22;
        if ( v22 )
        {
          if ( v2->m_geometriesAwaitingRequests.m_size == (v2->m_geometriesAwaitingRequests.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v2->m_geometriesAwaitingRequests,
              24);
          v23 = v2->m_geometriesAwaitingRequests.m_size;
          v24 = &v2->m_geometriesAwaitingRequests.m_data[v23];
          v2->m_geometriesAwaitingRequests.m_size = v23 + 1;
          v24->m_hash = *(_QWORD *)v8;
          v24->m_source = (hkReferencedObject *)*((_QWORD *)v8 + 1);
          v24->m_builder = (hkDisplayGeometryBuilder *)*((_QWORD *)v8 + 2);
        }
        else
        {
          hkReferencedObject::removeReference(*((hkReferencedObject **)v8 + 2));
          hkReferencedObject::removeReference(*((hkReferencedObject **)v8 + 1));
          hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_hashCountMap.m_map.m_elem,
            v20);
        }
      }
      else
      {
        hkServerDebugDisplayHandler::useGeometryForHash(v2, &v35, &geometries, (const unsigned __int64 *)v8, 0);
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
            v28->vfptr->__vecDelDtor((hkBaseObject *)&v28->vfptr, 1u);
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
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          geometries.m_data,
          8 * geometries.m_capacityAndFlags);
      v6 = v33;
      if ( v5 >= v34 )
        goto LABEL_42;
    }
    if ( !v2->m_continueData )
      v2->m_continueData = (hkReferencedObject *)(*(__int64 (__fastcall **)(_QWORD, _QWORD))(**((_QWORD **)v8 + 2)
                                                                                           + 40i64))(
                                                   *((_QWORD *)v8 + 2),
                                                   *((_QWORD *)v8 + 1));
LABEL_12:
    v11 = 100000000;
    if ( v2->m_simpleShapesPerFrame )
    {
      v11 = v1;
      if ( v1 > 100000000 )
        v11 = 100000000;
    }
    v12 = v2->m_simpleShapesPerPart;
    if ( v12 )
    {
      if ( v11 < v12 )
        v12 = v11;
      v11 = v12;
    }
    v13 = *((_QWORD *)v8 + 2);
    v14 = *((_QWORD *)v8 + 1);
    v15 = v2->m_continueData;
    v42 = v11;
    v10 = *(unsigned __int8 *)(*(__int64 (__fastcall **)(__int64, char *, __int64, int *, hkReferencedObject *, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *))(*(_QWORD *)v13 + 32i64))(
                                v13,
                                &v40,
                                v14,
                                &v42,
                                v15,
                                &geometries);
    if ( v2->m_simpleShapesPerFrame )
      v1 += v42 - v11;
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
hkResult *__fastcall hkServerDebugDisplayHandler::addGeometryPart(hkServerDebugDisplayHandler *this, hkResult *result, hkArrayBase<hkDisplayGeometry *> *geometries, hkTransformf *transform, unsigned __int64 id, int tag, unsigned __int64 shapeIdHint, hkBool final)
{
  hkServerDebugDisplayHandler *v8; // rbx
  hkTransformf *v9; // rbp
  hkArrayBase<hkDisplayGeometry *> *v10; // rdi
  hkResult *v11; // rsi
  unsigned int v12; // eax
  unsigned int v13; // eax
  hkOArchive *v14; // rcx
  bool v15; // di
  hkBool resulta; // [rsp+30h] [rbp+8h]

  v8 = this;
  v9 = transform;
  v10 = geometries;
  v11 = result;
  EnterCriticalSection(&this->m_outstreamLock->m_section);
  if ( v8->m_outStream )
  {
    if ( final.m_bool )
    {
      v12 = getGeometryByteSize(v10);
      hkOArchive::write32((hkOArchive *)&v8->m_outStream->vfptr, v12 + 41);
      hkOArchive::write8u((hkOArchive *)&v8->m_outStream->vfptr, 26);
      hkServerDebugDisplayHandler::sendGeometryData(v8, v10);
      hkDisplaySerializeOStream::writeTransform(v8->m_outStream, v9);
      hkOArchive::write64u((hkOArchive *)&v8->m_outStream->vfptr, id);
      hkOArchive::write32((hkOArchive *)&v8->m_outStream->vfptr, tag);
    }
    else
    {
      v13 = getGeometryByteSize(v10);
      hkOArchive::write32((hkOArchive *)&v8->m_outStream->vfptr, v13 + 1);
      hkOArchive::write8u((hkOArchive *)&v8->m_outStream->vfptr, 25);
      hkServerDebugDisplayHandler::sendGeometryData(v8, v10);
    }
  }
  v14 = (hkOArchive *)&v8->m_outStream->vfptr;
  v15 = v14 && hkOArchive::isOk(v14, &resulta)->m_bool;
  LeaveCriticalSection(&v8->m_outstreamLock->m_section);
  v11->m_enum = v15 == 0;
  return v11;
}

// File Line: 1006
// RVA: 0xE7BF00
hkResult *__fastcall hkServerDebugDisplayHandler::addGeometryLazily(hkServerDebugDisplayHandler *this, hkResult *result, hkReferencedObject *source, hkDisplayGeometryBuilder *builder, hkTransformf *transform, unsigned __int64 id, int tag, unsigned __int64 shapeIdHint)
{
  hkResult *v8; // rbx
  hkResultEnum v9; // ecx
  hkResult *v10; // rax
  hkResult resulta; // [rsp+50h] [rbp+8h]

  v8 = result;
  if ( LODWORD(this->m_outstreamLock) )
    v9 = hkServerDebugDisplayHandler::addGeometryInParts(
           (hkServerDebugDisplayHandler *)((char *)this - 64),
           &resulta,
           source,
           builder,
           transform,
           id,
           tag,
           shapeIdHint)->m_enum;
  else
    v9 = hkDebugDisplayHandler::addGeometryLazily(
           (hkDebugDisplayHandler *)this,
           &resulta,
           source,
           builder,
           transform,
           id,
           tag,
           shapeIdHint)->m_enum;
  v10 = v8;
  v8->m_enum = v9;
  return v10;
}

// File Line: 1020
// RVA: 0xE7C240
hkResult *__fastcall hkServerDebugDisplayHandler::addGeometryInParts(hkServerDebugDisplayHandler *this, hkResult *result, hkReferencedObject *source, hkDisplayGeometryBuilder *builder, hkTransformf *transform, unsigned __int64 id, int tag, unsigned __int64 shapeIdHint)
{
  hkServerDebugDisplayHandler *v8; // r13
  hkDisplayGeometryBuilder *v9; // r12
  hkReferencedObject *v10; // rbx
  __int64 v11; // rax
  unsigned __int64 v12; // r15
  bool v13; // r14
  __int64 v14; // rcx
  char *v15; // rax
  int v16; // edx
  hkBool final; // bl
  int v18; // esi
  __int64 i; // rdi
  hkDisplayGeometry *v20; // rax
  hkResult *v21; // rax
  bool v22; // zf
  hkResult *v23; // r15
  int v24; // er8
  hkArrayBase<hkDisplayGeometry *> geometries; // [rsp+40h] [rbp-C0h]
  hkResult resulta; // [rsp+50h] [rbp-B0h]
  __int64 v28; // [rsp+58h] [rbp-A8h]
  hkErrStream v29; // [rsp+60h] [rbp-A0h]
  char buf; // [rsp+80h] [rbp-80h]
  char v31; // [rsp+2D0h] [rbp+1D0h]
  hkResult *v32; // [rsp+2D8h] [rbp+1D8h]
  hkReferencedObject *v33; // [rsp+2E0h] [rbp+1E0h]
  int v34; // [rsp+2E8h] [rbp+1E8h]

  v33 = source;
  v32 = result;
  v8 = this;
  v9 = builder;
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
  geometries.m_capacityAndFlags = 2147483648;
  do
  {
    v34 = v8->m_simpleShapesPerPart;
    v15 = (char *)((__int64 (__fastcall *)(hkDisplayGeometryBuilder *, char *, hkReferencedObject *, int *, __int64, hkArrayBase<hkDisplayGeometry *> *))v9->vfptr[2].__vecDelDtor)(
                    v9,
                    &v31,
                    v10,
                    &v34,
                    v14,
                    &geometries);
    v16 = geometries.m_size;
    final.m_bool = *v15;
    v18 = geometries.m_size - 1;
    for ( i = geometries.m_size - 1; i >= 0; --i )
    {
      v20 = geometries.m_data[i];
      if ( v20->m_type == 6 && !v20->m_geometry )
      {
        hkErrStream::hkErrStream(&v29, &buf, 512);
        hkOstream::operator<<((hkOstream *)&v29.vfptr, "Unable to build display geometry from source");
        hkError::messageReport(-1, &buf, "hkServerDebugDisplayHandler.cpp", 1039);
        hkOstream::~hkOstream((hkOstream *)&v29.vfptr);
        v16 = geometries.m_size - 1;
        geometries.m_size = v16;
        if ( v16 != v18 )
        {
          geometries.m_data[i] = geometries.m_data[v16];
          v16 = geometries.m_size;
        }
      }
      --v18;
    }
    if ( v16 )
    {
      v21 = hkServerDebugDisplayHandler::addGeometryPart(v8, &resulta, &geometries, transform, id, tag, v12, final);
      v16 = geometries.m_size;
      v13 = v21->m_enum == 0;
    }
    if ( !v13 )
      break;
    hkReferencedObject::removeReferences((hkReferencedObject *const *)geometries.m_data, v16, 8);
    v14 = v28;
    v22 = final.m_bool == 0;
    v10 = v33;
    geometries.m_size = 0;
  }
  while ( v22 );
  v23 = v32;
  v24 = geometries.m_capacityAndFlags;
  geometries.m_size = 0;
  v32->m_enum = v13 == 0;
  if ( v24 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      geometries.m_data,
      8 * v24);
  return v23;
}

