// File Line: 31
// RVA: 0xE7A480
void __fastcall hkReplayStreamReader::~hkReplayStreamReader(hkReplayStreamReader *this)
{
  hkReplayStreamReader *v1; // rbx
  int v2; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkReplayStreamReader::`vftable;
  hkReferencedObject::removeReference((hkReferencedObject *)&this->m_stream->vfptr);
  v2 = v1->m_buf.m_capacityAndFlags;
  v1->m_buf.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_buf.m_data,
      v2 & 0x3FFFFFFF);
  v1->m_buf.m_data = 0i64;
  v1->m_buf.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 36
// RVA: 0xE7A550
__int64 __fastcall hkReplayStreamReader::read(hkReplayStreamReader *this, void *buf, int nbytes)
{
  int v3; // er14
  unsigned int v4; // esi
  void *v5; // r15
  hkReplayStreamReader *v6; // rbx
  unsigned int v7; // edi
  int v8; // er9
  int v9; // eax
  int v10; // eax
  int v11; // esi
  unsigned int v12; // eax
  int v13; // edi
  int v14; // eax
  int v15; // eax
  int v16; // er9
  hkResult result; // [rsp+60h] [rbp+18h]

  v3 = this->m_buf.m_size;
  v4 = nbytes;
  v5 = buf;
  v6 = this;
  v7 = nbytes + this->m_current - v3;
  if ( (signed int)v7 > 0 )
  {
    v8 = nbytes + this->m_current;
    v9 = this->m_buf.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 >= (signed int)(nbytes + this->m_current) )
    {
      result.m_enum = 0;
    }
    else
    {
      v10 = 2 * v9;
      if ( v8 < v10 )
        v8 = v10;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &this->m_buf, v8, 1);
    }
    v6->m_buf.m_size += v7;
    v11 = ((__int64 (__fastcall *)(hkStreamReader *, char *, _QWORD))v6->m_stream->vfptr[2].__vecDelDtor)(
            v6->m_stream,
            &v6->m_buf.m_data[v3],
            v7);
    v12 = v6->m_current;
    v4 = v3 + v11 - v12;
    v13 = v12 + v4;
    v14 = v6->m_buf.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v14 < v13 )
    {
      v15 = 2 * v14;
      v16 = v13;
      if ( v13 < v15 )
        v16 = v15;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_buf, v16, 1);
    }
    v6->m_buf.m_size = v13;
  }
  hkString::memCpy(v5, &v6->m_buf.m_data[v6->m_current], v4);
  v6->m_current += v4;
  return v4;
}

// File Line: 85
// RVA: 0xE7A080
void __fastcall hkCommandRouter::registerProcess(hkCommandRouter *this, hkProcess *handler)
{
  hkProcessVtbl *v2; // rax
  hkProcess *v3; // rsi
  hkCommandRouter *v4; // rbp
  int v5; // ebx
  __int64 v6; // rdi
  int v7; // [rsp+48h] [rbp+10h]
  __int64 v8; // [rsp+50h] [rbp+18h]

  v2 = handler->vfptr;
  v3 = handler;
  v4 = this;
  v5 = 0;
  v8 = 0i64;
  v7 = 0;
  v2->getConsumableCommands(handler, (char **)&v8, &v7);
  v6 = 0i64;
  if ( v7 > 0 )
  {
    do
    {
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::insert(
        &v4->m_commandMap.m_map,
        *(unsigned __int8 *)(v6 + v8),
        (unsigned __int64)v3);
      ++v5;
      ++v6;
    }
    while ( v5 < v7 );
  }
}

// File Line: 98
// RVA: 0xE7A100
void __fastcall hkCommandRouter::unregisterProcess(hkCommandRouter *this, hkProcess *handler)
{
  hkProcessVtbl *v2; // rax
  hkProcess *v3; // rsi
  hkCommandRouter *v4; // rbp
  int v5; // ebx
  __int64 v6; // rdi
  int v7; // [rsp+48h] [rbp+10h]
  hkResult result; // [rsp+50h] [rbp+18h]
  __int64 v9; // [rsp+58h] [rbp+20h]

  v2 = handler->vfptr;
  v3 = handler;
  v4 = this;
  v5 = 0;
  v9 = 0i64;
  v7 = 0;
  v2->getConsumableCommands(handler, (char **)&v9, &v7);
  v6 = 0i64;
  if ( v7 > 0 )
  {
    do
    {
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
        &v4->m_commandMap.m_map,
        &result,
        *(unsigned __int8 *)(v6 + v9),
        (unsigned __int64)v3);
      ++v5;
      ++v6;
    }
    while ( v5 < v7 );
  }
}

// File Line: 110
// RVA: 0xE7A180
hkBool *__fastcall hkCommandRouter::consumeCommands(hkCommandRouter *this, hkBool *result, hkDisplaySerializeIStream *stream)
{
  hkDisplaySerializeIStream *v3; // r15
  hkBool *v4; // rbx
  hkCommandRouter *v5; // r13
  unsigned __int8 v6; // bp
  char v7; // r12
  hkStreamReader *v8; // rax
  hkStreamReader *v9; // rbx
  _QWORD **v10; // rax
  __int64 v11; // rax
  __int64 v12; // r14
  int v13; // ebx
  unsigned __int64 v14; // rcx
  __int64 v15; // r10
  int v16; // er8
  __int64 i; // rcx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v18; // rax
  hkBool *v19; // rax
  hkBool resulta; // [rsp+20h] [rbp-F8h]
  hkStreamReader *newBuf; // [rsp+28h] [rbp-F0h]
  char v22; // [rsp+30h] [rbp-E8h]
  hkVector4f v; // [rsp+40h] [rbp-D8h]
  hkStringBuf v24; // [rsp+50h] [rbp-C8h]
  hkBool *v25; // [rsp+128h] [rbp+10h]
  unsigned __int8 array; // [rsp+138h] [rbp+20h]

  v25 = result;
  v3 = stream;
  v4 = result;
  v5 = this;
  hkIArchive::readArrayGeneric((hkIArchive *)&stream->vfptr, &array, 1, 1);
  v6 = array;
  if ( hkIArchive::isOk((hkIArchive *)&v3->vfptr, &resulta)->m_bool )
  {
    while ( v6 != -16 )
    {
      v7 = 0;
      if ( (signed int)hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
                         &v5->m_commandMap.m_map,
                         v6) > v5->m_commandMap.m_map.m_hashMod )
        goto LABEL_34;
      v8 = hkIArchive::getStreamReader((hkIArchive *)&v3->vfptr);
      v9 = v8;
      newBuf = v8;
      v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v11 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(v10[11], 48i64);
      v12 = v11;
      if ( v11 )
      {
        *(_DWORD *)(v11 + 8) = 0x1FFFF;
        *(_QWORD *)(v11 + 16) = v9;
        *(_QWORD *)v11 = &hkReplayStreamReader::`vftable;
        *(_DWORD *)(v11 + 24) = 0;
        *(_QWORD *)(v11 + 32) = 0i64;
        *(_DWORD *)(v11 + 40) = 0;
        *(_DWORD *)(v11 + 44) = 2147483648;
        hkReferencedObject::addReference(*(hkReferencedObject **)(v11 + 16));
      }
      else
      {
        v12 = 0i64;
      }
      hkIArchive::setStreamReader((hkIArchive *)&v3->vfptr, (hkStreamReader *)v12);
      v13 = hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
              &v5->m_commandMap.m_map,
              v6);
      while ( v13 <= v5->m_commandMap.m_map.m_hashMod )
      {
        v14 = v5->m_commandMap.m_map.m_elem[v13].val;
        if ( v14 )
        {
          v7 = 1;
          (*(void (__fastcall **)(unsigned __int64, _QWORD))(*(_QWORD *)v14 + 32i64))(v14, v6);
          *(_DWORD *)(v12 + 24) = 0;
        }
        v15 = v5->m_commandMap.m_map.m_hashMod;
        v16 = v13 + 1;
        for ( i = v13 + 1; i > v15; i = 0i64 )
LABEL_16:
          v16 = 0;
        v18 = &v5->m_commandMap.m_map.m_elem[i];
        while ( v18->key != -1i64 )
        {
          if ( v18->key == v6 )
          {
            v13 = v16;
            goto LABEL_19;
          }
          ++i;
          ++v16;
          ++v18;
          if ( i > v15 )
            goto LABEL_16;
        }
        v13 = v15 + 1;
LABEL_19:
        ;
      }
      hkIArchive::setStreamReader((hkIArchive *)&v3->vfptr, newBuf);
      hkReferencedObject::removeReference((hkReferencedObject *)v12);
      if ( !v7 )
      {
LABEL_34:
        if ( v6 == -80 )
        {
          hkDisplaySerializeIStream::readQuadVector4(v3, &v);
          hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &v22, 8, 1);
        }
        else if ( v6 == -79 )
        {
          hkDisplaySerializeIStream::readQuadVector4(v3, &v);
        }
        v24.m_string.m_capacityAndFlags = -2147483520;
        v24.m_string.m_size = 1;
        v24.m_string.m_data = v24.m_string.m_storage;
        v24.m_string.m_storage[0] = 0;
        hkStringBuf::printf(&v24, "VDB: Found a command (%x) with no handler. Could corrupt the stream.", v6);
        v24.m_string.m_size = 0;
        if ( v24.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v24.m_string.m_data,
            v24.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      }
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &array, 1, 1);
      v6 = array;
      if ( !hkIArchive::isOk((hkIArchive *)&v3->vfptr, &resulta)->m_bool )
      {
        v19 = v25;
        v25->m_bool = 1;
        return v19;
      }
    }
    v19 = v25;
    v25->m_bool = 1;
  }
  else
  {
    v4->m_bool = 1;
    v19 = v4;
  }
  return v19;
}

