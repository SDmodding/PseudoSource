// File Line: 31
// RVA: 0xE7A480
void __fastcall hkReplayStreamReader::~hkReplayStreamReader(hkReplayStreamReader *this)
{
  int m_capacityAndFlags; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkReplayStreamReader::`vftable;
  hkReferencedObject::removeReference(this->m_stream);
  m_capacityAndFlags = this->m_buf.m_capacityAndFlags;
  this->m_buf.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_buf.m_data,
      m_capacityAndFlags & 0x3FFFFFFF);
  this->m_buf.m_data = 0i64;
  this->m_buf.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 36
// RVA: 0xE7A550
__int64 __fastcall hkReplayStreamReader::read(hkReplayStreamReader *this, void *buf, unsigned int nbytes)
{
  int m_size; // r14d
  unsigned int v4; // esi
  int v7; // edi
  int v8; // r9d
  int v9; // eax
  int v10; // eax
  int v11; // esi
  unsigned int m_current; // eax
  int v13; // edi
  int v14; // eax
  int v15; // eax
  int v16; // r9d
  hkResult result; // [rsp+60h] [rbp+18h] BYREF

  m_size = this->m_buf.m_size;
  v4 = nbytes;
  v7 = nbytes + this->m_current - m_size;
  if ( v7 > 0 )
  {
    v8 = nbytes + this->m_current;
    v9 = this->m_buf.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 >= v8 )
    {
      result.m_enum = HK_SUCCESS;
    }
    else
    {
      v10 = 2 * v9;
      if ( v8 < v10 )
        v8 = v10;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_buf.m_data, v8, 1);
    }
    this->m_buf.m_size += v7;
    v11 = ((__int64 (__fastcall *)(hkStreamReader *, char *, _QWORD))this->m_stream->vfptr[2].__vecDelDtor)(
            this->m_stream,
            &this->m_buf.m_data[m_size],
            (unsigned int)v7);
    m_current = this->m_current;
    v4 = m_size + v11 - m_current;
    v13 = m_current + v4;
    v14 = this->m_buf.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v14 < v13 )
    {
      v15 = 2 * v14;
      v16 = v13;
      if ( v13 < v15 )
        v16 = v15;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_buf.m_data, v16, 1);
    }
    this->m_buf.m_size = v13;
  }
  hkString::memCpy(buf, &this->m_buf.m_data[this->m_current], v4);
  this->m_current += v4;
  return v4;
}

// File Line: 85
// RVA: 0xE7A080
void __fastcall hkCommandRouter::registerProcess(hkCommandRouter *this, hkProcess *handler)
{
  hkProcessVtbl *vfptr; // rax
  int v5; // ebx
  __int64 v6; // rdi
  int v7; // [rsp+48h] [rbp+10h] BYREF
  __int64 v8; // [rsp+50h] [rbp+18h] BYREF

  vfptr = handler->vfptr;
  v5 = 0;
  v8 = 0i64;
  v7 = 0;
  vfptr->getConsumableCommands(handler, (char **)&v8, &v7);
  v6 = 0i64;
  if ( v7 > 0 )
  {
    do
    {
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::insert(
        &this->m_commandMap.m_map,
        *(unsigned __int8 *)(v6 + v8),
        (unsigned __int64)handler);
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
  hkProcessVtbl *vfptr; // rax
  int v5; // ebx
  __int64 v6; // rdi
  int v7; // [rsp+48h] [rbp+10h] BYREF
  hkResult result; // [rsp+50h] [rbp+18h] BYREF
  __int64 v9; // [rsp+58h] [rbp+20h] BYREF

  vfptr = handler->vfptr;
  v5 = 0;
  v9 = 0i64;
  v7 = 0;
  vfptr->getConsumableCommands(handler, (char **)&v9, &v7);
  v6 = 0i64;
  if ( v7 > 0 )
  {
    do
    {
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
        &this->m_commandMap.m_map,
        &result,
        *(unsigned __int8 *)(v6 + v9),
        (unsigned __int64)handler);
      ++v5;
      ++v6;
    }
    while ( v5 < v7 );
  }
}

// File Line: 110
// RVA: 0xE7A180
hkBool *__fastcall hkCommandRouter::consumeCommands(
        hkCommandRouter *this,
        hkBool *result,
        hkDisplaySerializeIStream *stream)
{
  unsigned __int8 v6; // bp
  char v7; // r12
  hkStreamReader *StreamReader; // rbx
  _QWORD **Value; // rax
  __int64 v10; // rax
  __int64 v11; // r14
  int Key; // ebx
  unsigned __int64 val; // rcx
  __int64 m_hashMod; // r10
  int v15; // r8d
  __int64 i; // rcx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v17; // rax
  hkBool *v18; // rax
  hkBool resulta; // [rsp+20h] [rbp-F8h] BYREF
  hkStreamReader *newBuf; // [rsp+28h] [rbp-F0h]
  char v21[16]; // [rsp+30h] [rbp-E8h] BYREF
  hkVector4f v; // [rsp+40h] [rbp-D8h] BYREF
  hkStringBuf v23; // [rsp+50h] [rbp-C8h] BYREF
  unsigned __int8 array; // [rsp+138h] [rbp+20h] BYREF

  hkIArchive::readArrayGeneric(stream, &array, 1, 1);
  v6 = array;
  if ( hkIArchive::isOk(stream, &resulta)->m_bool )
  {
    while ( v6 != 0xF0 )
    {
      v7 = 0;
      if ( (int)hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
                  &this->m_commandMap.m_map,
                  v6) > this->m_commandMap.m_map.m_hashMod )
        goto LABEL_21;
      StreamReader = hkIArchive::getStreamReader(stream);
      newBuf = StreamReader;
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v10 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
      v11 = v10;
      if ( v10 )
      {
        *(_DWORD *)(v10 + 8) = 0x1FFFF;
        *(_QWORD *)(v10 + 16) = StreamReader;
        *(_QWORD *)v10 = &hkReplayStreamReader::`vftable;
        *(_DWORD *)(v10 + 24) = 0;
        *(_QWORD *)(v10 + 32) = 0i64;
        *(_DWORD *)(v10 + 40) = 0;
        *(_DWORD *)(v10 + 44) = 0x80000000;
        hkReferencedObject::addReference(*(hkReferencedObject **)(v10 + 16));
      }
      else
      {
        v11 = 0i64;
      }
      hkIArchive::setStreamReader(stream, (hkStreamReader *)v11);
      Key = hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
              &this->m_commandMap.m_map,
              v6);
      while ( Key <= this->m_commandMap.m_map.m_hashMod )
      {
        val = this->m_commandMap.m_map.m_elem[Key].val;
        if ( val )
        {
          v7 = 1;
          (*(void (__fastcall **)(unsigned __int64, _QWORD))(*(_QWORD *)val + 32i64))(val, v6);
          *(_DWORD *)(v11 + 24) = 0;
        }
        m_hashMod = this->m_commandMap.m_map.m_hashMod;
        v15 = Key + 1;
        for ( i = Key + 1; i > m_hashMod; i = 0i64 )
LABEL_16:
          v15 = 0;
        v17 = &this->m_commandMap.m_map.m_elem[i];
        while ( v17->key != -1i64 )
        {
          if ( v17->key == v6 )
          {
            Key = v15;
            goto LABEL_19;
          }
          ++i;
          ++v15;
          ++v17;
          if ( i > m_hashMod )
            goto LABEL_16;
        }
        Key = m_hashMod + 1;
LABEL_19:
        ;
      }
      hkIArchive::setStreamReader(stream, newBuf);
      hkReferencedObject::removeReference((hkReferencedObject *)v11);
      if ( !v7 )
      {
LABEL_21:
        if ( v6 == 0xB0 )
        {
          hkDisplaySerializeIStream::readQuadVector4(stream, &v);
          hkIArchive::readArrayGeneric(stream, v21, 8, 1);
        }
        else if ( v6 == 0xB1 )
        {
          hkDisplaySerializeIStream::readQuadVector4(stream, &v);
        }
        v23.m_string.m_capacityAndFlags = -2147483520;
        v23.m_string.m_size = 1;
        v23.m_string.m_data = v23.m_string.m_storage;
        v23.m_string.m_storage[0] = 0;
        hkStringBuf::printf(&v23, "VDB: Found a command (%x) with no handler. Could corrupt the stream.", v6);
        v23.m_string.m_size = 0;
        if ( v23.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            v23.m_string.m_data,
            v23.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      }
      hkIArchive::readArrayGeneric(stream, &array, 1, 1);
      v6 = array;
      if ( !hkIArchive::isOk(stream, &resulta)->m_bool )
      {
        v18 = result;
        result->m_bool = 1;
        return v18;
      }
    }
    v18 = result;
    result->m_bool = 1;
  }
  else
  {
    result->m_bool = 1;
    return result;
  }
  return v18;
}

