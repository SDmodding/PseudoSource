// File Line: 18
// RVA: 0xE76D90
void __fastcall hkServerProcessHandler::hkServerProcessHandler(
        hkServerProcessHandler *this,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts,
        hkStreamReader *inStream,
        hkStreamWriter *outStream)
{
  hkProcessHandler *v6; // r13
  hkProcess *v9; // rsi
  __int64 m_size; // rcx
  hkProcessContext **m_data; // rax
  __int64 v12; // rdx
  char *v13; // r8
  hkProcessContext *v14; // rcx
  _QWORD **Value; // rax
  hkDisplaySerializeIStream *v16; // rax
  hkDisplaySerializeIStream *v17; // rax
  _QWORD **v18; // rax
  hkDisplaySerializeOStream *v19; // rax
  hkDisplaySerializeOStream *v20; // rax
  _QWORD **v21; // rax
  hkServerDebugDisplayHandler *v22; // rax
  __int64 v23; // rax
  hkDebugDisplayHandler *v24; // rcx
  int v25; // [rsp+50h] [rbp+8h] BYREF

  this->m_memSizeAndFlags = -1;
  this->m_referenceCount = 1;
  this->m_selectable.m_bool = 0;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkServerProcessHandler::`vftable{for `hkReferencedObject};
  v6 = &this->hkProcessHandler;
  this->hkProcessHandler::vfptr = (hkProcessHandlerVtbl *)&hkServerProcessHandler::`vftable{for `hkProcessHandler};
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkServerProcessHandler::`vftable{for `hkProcess};
  this->m_commandRouter.vfptr = (hkBaseObjectVtbl *)&hkCommandRouter::`vftable;
  *(_DWORD *)&this->m_commandRouter.m_memSizeAndFlags = 0x1FFFF;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&this->m_commandRouter.m_commandMap.m_map);
  v9 = 0i64;
  this->m_processList.m_capacityAndFlags = 0x80000000;
  this->m_processList.m_data = 0i64;
  this->m_processList.m_size = 0;
  this->m_contexts.m_data = 0i64;
  this->m_contexts.m_size = 0;
  this->m_contexts.m_capacityAndFlags = 0x80000000;
  hkCommandRouter::registerProcess(&this->m_commandRouter, &this->hkProcess);
  if ( (this->m_contexts.m_capacityAndFlags & 0x3FFFFFFF) < contexts->m_size )
  {
    if ( this->m_contexts.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_contexts.m_data,
        8 * this->m_contexts.m_capacityAndFlags);
    v25 = 8 * contexts->m_size;
    this->m_contexts.m_data = (hkProcessContext **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                     &hkContainerHeapAllocator::s_alloc,
                                                     &v25);
    this->m_contexts.m_capacityAndFlags = v25 / 8;
  }
  m_size = contexts->m_size;
  m_data = this->m_contexts.m_data;
  this->m_contexts.m_size = m_size;
  v12 = m_size;
  if ( (int)m_size > 0 )
  {
    v13 = (char *)((char *)contexts->m_data - (char *)m_data);
    do
    {
      v14 = *(hkProcessContext **)((char *)m_data++ + (_QWORD)v13);
      *(m_data - 1) = v14;
      --v12;
    }
    while ( v12 );
  }
  if ( inStream
    && (Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID),
        (v16 = (hkDisplaySerializeIStream *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                              Value[11],
                                              32i64)) != 0i64) )
  {
    hkDisplaySerializeIStream::hkDisplaySerializeIStream(v16, inStream);
  }
  else
  {
    v17 = 0i64;
  }
  this->m_inStream = v17;
  if ( outStream
    && (v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID),
        (v19 = (hkDisplaySerializeOStream *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v18[11] + 8i64))(
                                              v18[11],
                                              32i64)) != 0i64) )
  {
    hkDisplaySerializeOStream::hkDisplaySerializeOStream(v19, outStream);
  }
  else
  {
    v20 = 0i64;
  }
  this->m_outStream = v20;
  v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = (hkServerDebugDisplayHandler *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v21[11] + 8i64))(v21[11], 152i64);
  if ( v22 )
  {
    hkServerDebugDisplayHandler::hkServerDebugDisplayHandler(v22, this->m_outStream, this->m_inStream);
    if ( v23 )
    {
      v24 = (hkDebugDisplayHandler *)(v23 + 64);
      goto LABEL_21;
    }
  }
  else
  {
    v23 = 0i64;
  }
  v24 = 0i64;
LABEL_21:
  this->m_displayHandler = v24;
  if ( v23 )
    v9 = (hkProcess *)(v23 + 16);
  hkCommandRouter::registerProcess(&this->m_commandRouter, v9);
  this->m_processHandler = v6;
}

// File Line: 32
// RVA: 0xE76FF0
void __fastcall hkServerProcessHandler::~hkServerProcessHandler(hkServerProcessHandler *this)
{
  int m_size; // edi
  int v3; // edi
  __int64 v4; // rsi
  hkProcess *v5; // rcx
  __int64 v6; // rax
  hkDisplaySerializeIStream *m_inStream; // rcx
  hkDisplaySerializeOStream *m_outStream; // rcx
  hkDebugDisplayHandler *m_displayHandler; // rcx
  int m_capacityAndFlags; // r8d
  int v11; // r8d

  m_size = this->m_processList.m_size;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkServerProcessHandler::`vftable{for `hkReferencedObject};
  v3 = m_size - 1;
  this->hkProcessHandler::vfptr = (hkProcessHandlerVtbl *)&hkServerProcessHandler::`vftable{for `hkProcessHandler};
  v4 = v3;
  for ( this->hkProcess::vfptr = (hkProcessVtbl *)&hkServerProcessHandler::`vftable{for `hkProcess}; v4 >= 0; --v4 )
  {
    v5 = this->m_processList.m_data[v4];
    v6 = --this->m_processList.m_size;
    if ( (_DWORD)v6 != v3 )
      this->m_processList.m_data[v4] = this->m_processList.m_data[v6];
    if ( v5 )
      v5->vfptr->__vecDelDtor(v5, 1u);
    --v3;
  }
  m_inStream = this->m_inStream;
  if ( m_inStream )
    m_inStream->vfptr->__vecDelDtor(m_inStream, 1u);
  m_outStream = this->m_outStream;
  if ( m_outStream )
    m_outStream->vfptr->__vecDelDtor(m_outStream, 1u);
  m_displayHandler = this->m_displayHandler;
  if ( m_displayHandler )
    m_displayHandler->vfptr->__vecDelDtor(m_displayHandler, 1u);
  m_capacityAndFlags = this->m_contexts.m_capacityAndFlags;
  this->m_contexts.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_contexts.m_data,
      8 * m_capacityAndFlags);
  this->m_contexts.m_data = 0i64;
  this->m_contexts.m_capacityAndFlags = 0x80000000;
  v11 = this->m_processList.m_capacityAndFlags;
  this->m_processList.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_processList.m_data,
      8 * v11);
  this->m_processList.m_data = 0i64;
  this->m_processList.m_capacityAndFlags = 0x80000000;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&this->m_commandRouter.m_commandMap.m_map);
  this->m_commandRouter.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkProcess::`vftable;
  this->hkProcessHandler::vfptr = (hkProcessHandlerVtbl *)&hkProcessHandler::`vftable;
}

// File Line: 48
// RVA: 0xE77160
void __fastcall hkServerProcessHandler::getConsumableCommands(
        hkServerProcessHandler *this,
        char **commands,
        int *numCommands)
{
  *commands = cmds;
  *numCommands = 2;
}

// File Line: 54
// RVA: 0xE77180
void __fastcall hkServerProcessHandler::consumeCommand(hkServerProcessHandler *this, unsigned __int8 command)
{
  char v3[4]; // [rsp+20h] [rbp-18h] BYREF
  char v4[20]; // [rsp+24h] [rbp-14h] BYREF
  hkBool result; // [rsp+48h] [rbp+10h] BYREF
  hkBool v6; // [rsp+50h] [rbp+18h] BYREF
  unsigned int array; // [rsp+58h] [rbp+20h] BYREF

  if ( command == 194 )
  {
    hkIArchive::readArrayGeneric((hkIArchive *)this->hkProcessHandler::vfptr, &array, 4, 1);
    if ( hkIArchive::isOk((hkIArchive *)this->hkProcessHandler::vfptr, &v6)->m_bool )
      (*(void (__fastcall **)(int *, char *, _QWORD))(*(_QWORD *)&this[-1].m_contexts.m_size + 56i64))(
        &this[-1].m_contexts.m_size,
        v4,
        array);
  }
  else if ( command == 195 )
  {
    hkIArchive::readArrayGeneric((hkIArchive *)this->hkProcessHandler::vfptr, &array, 4, 1);
    if ( hkIArchive::isOk((hkIArchive *)this->hkProcessHandler::vfptr, &result)->m_bool )
      (*(void (__fastcall **)(int *, char *, _QWORD))(*(_QWORD *)&this[-1].m_contexts.m_size + 64i64))(
        &this[-1].m_contexts.m_size,
        v3,
        array);
  }
}

// File Line: 80
// RVA: 0xE77340
hkResult *__fastcall hkServerProcessHandler::createProcess(
        hkServerProcessHandler *this,
        hkResult *result,
        unsigned int id)
{
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *p_m_contexts; // r14
  hkProcess *Process; // rax
  hkProcess *v9; // rsi
  hkServerProcessHandler *v10; // rcx
  char v11; // [rsp+40h] [rbp+8h] BYREF

  p_m_contexts = &this[-1].m_contexts;
  if ( hkServerProcessHandler::findProcessByTag((hkServerProcessHandler *)((char *)this - 16), id) < 0 )
  {
    Process = hkProcessFactory::createProcess(
                hkSingleton<hkProcessFactory>::s_instance,
                id,
                (hkArray<hkProcessContext *,hkContainerHeapAllocator> *)&this->m_processList);
    v9 = Process;
    if ( Process )
    {
      Process->m_inStream = (hkDisplaySerializeIStream *)this->hkProcess::vfptr;
      Process->m_outStream = *(hkDisplaySerializeOStream **)&this->m_selectable.m_bool;
      v10 = 0i64;
      if ( p_m_contexts )
        v10 = this;
      Process->m_processHandler = (hkProcessHandler *)v10;
      Process->m_displayHandler = (hkDebugDisplayHandler *)this->m_inStream;
      if ( *(_DWORD *)&this->m_commandRouter.m_haveClientVersion == (*((_DWORD *)&this->m_commandRouter.m_haveClientVersion
                                                                     + 1) & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&this->m_commandRouter.m_commandMap.m_map.m_numElems,
          8);
      *(_QWORD *)(*(_QWORD *)&this->m_commandRouter.m_commandMap.m_map.m_numElems
                + 8i64 * (int)(*(_DWORD *)&this->m_commandRouter.m_haveClientVersion)++) = v9;
      hkCommandRouter::registerProcess((hkCommandRouter *)&this->m_displayHandler, v9);
      v9->vfptr->init(v9);
      ((void (__fastcall *)(hkServerProcessHandler *, char *, _QWORD))this->hkReferencedObject::hkBaseObject::vfptr[3].__vecDelDtor)(
        this,
        &v11,
        id);
      result->m_enum = HK_SUCCESS;
    }
    else
    {
      result->m_enum = HK_FAILURE;
    }
    return result;
  }
  else
  {
    result->m_enum = HK_SUCCESS;
    return result;
  }
}

// File Line: 108
// RVA: 0xE77720
__int64 __fastcall hkServerProcessHandler::findProcessByTag(hkServerProcessHandler *this, int tag)
{
  __int64 m_size; // rsi
  unsigned int v3; // edi
  __int64 v6; // rbx
  hkProcess *v7; // rcx

  m_size = this->m_processList.m_size;
  v3 = 0;
  v6 = 0i64;
  if ( m_size <= 0 )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    v7 = this->m_processList.m_data[v6];
    if ( v7->vfptr->getProcessTag(v7) == tag )
      break;
    ++v6;
    ++v3;
    if ( v6 >= m_size )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 119
// RVA: 0xE77450
hkResult *__fastcall hkServerProcessHandler::deleteProcess(hkServerProcessHandler *this, hkResult *result, int id)
{
  int ProcessByTag; // eax
  hkProcess *v6; // rsi
  __int64 v7; // r8

  ProcessByTag = hkServerProcessHandler::findProcessByTag((hkServerProcessHandler *)((char *)this - 16), id);
  if ( ProcessByTag < 0 )
  {
    result->m_enum = HK_SUCCESS;
    return result;
  }
  else
  {
    v6 = *(hkProcess **)(8i64 * ProcessByTag + *(_QWORD *)&this->m_commandRouter.m_commandMap.m_map.m_numElems);
    v7 = (int)--*(_DWORD *)&this->m_commandRouter.m_haveClientVersion;
    if ( (_DWORD)v7 != ProcessByTag )
      *(_QWORD *)(*(_QWORD *)&this->m_commandRouter.m_commandMap.m_map.m_numElems + 8i64 * ProcessByTag) = *(_QWORD *)(*(_QWORD *)&this->m_commandRouter.m_commandMap.m_map.m_numElems + 8 * v7);
    hkCommandRouter::unregisterProcess((hkCommandRouter *)&this->m_displayHandler, v6);
    if ( v6 )
      v6->vfptr->__vecDelDtor(v6, 1u);
    result->m_enum = HK_SUCCESS;
    return result;
  }
}

// File Line: 136
// RVA: 0xE77500
hkProcess *__fastcall hkServerProcessHandler::getProcessByName(hkServerProcessHandler *this, const char *name)
{
  int v3; // eax
  int ProcessByTag; // eax

  v3 = (int)this->hkReferencedObject::hkBaseObject::vfptr[1].__vecDelDtor(this, name);
  if ( v3 == -1 )
    return 0i64;
  ProcessByTag = hkServerProcessHandler::findProcessByTag((hkServerProcessHandler *)((char *)this - 16), v3);
  if ( ProcessByTag == -1 )
    return 0i64;
  else
    return *(hkProcess **)(*(_QWORD *)&this->m_commandRouter.m_commandMap.m_map.m_numElems + 8i64 * ProcessByTag);
}

// File Line: 151
// RVA: 0xE77550
void __fastcall hkServerProcessHandler::getProcessesByType(
        hkServerProcessHandler *this,
        int type,
        hkArray<hkProcess *,hkContainerHeapAllocator> *processes)
{
  int v3; // edi
  __int64 v7; // rsi
  __int64 v8; // r14

  v3 = 0;
  processes->m_size = 0;
  if ( *(int *)&this->m_commandRouter.m_haveClientVersion > 0 )
  {
    v7 = 0i64;
    do
    {
      if ( (*(unsigned int (__fastcall **)(_QWORD))(**(_QWORD **)(v7
                                                                + *(_QWORD *)&this->m_commandRouter.m_commandMap.m_map.m_numElems)
                                                  + 16i64))(*(_QWORD *)(v7
                                                                      + *(_QWORD *)&this->m_commandRouter.m_commandMap.m_map.m_numElems)) == type )
      {
        v8 = *(_QWORD *)&this->m_commandRouter.m_commandMap.m_map.m_numElems;
        if ( processes->m_size == (processes->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&processes->m_data, 8);
        processes->m_data[processes->m_size++] = *(hkProcess **)(v8 + v7);
      }
      ++v3;
      v7 += 8i64;
    }
    while ( v3 < *(_DWORD *)&this->m_commandRouter.m_haveClientVersion );
  }
}

// File Line: 164
// RVA: 0xE77230
hkResult *__fastcall hkServerProcessHandler::registerProcess(
        hkServerProcessHandler *this,
        hkResult *result,
        const char *name,
        int id)
{
  int v8; // ebx

  v8 = hkString::strLen(name);
  if ( v8 > 0xFFFF )
    v8 = 0xFFFF;
  hkOArchive::write32(*(hkOArchive **)&this->m_selectable.m_bool, v8 + 7);
  hkOArchive::write8u(*(hkOArchive **)&this->m_selectable.m_bool, 192);
  hkOArchive::write32(*(hkOArchive **)&this->m_selectable.m_bool, id);
  hkOArchive::write16u(*(hkOArchive **)&this->m_selectable.m_bool, v8);
  hkOArchive::writeRaw(*(hkOArchive **)&this->m_selectable.m_bool, name, (unsigned int)v8);
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 184
// RVA: 0xE77690
hkResult *__fastcall hkServerProcessHandler::registerAllAvailableProcesss(
        hkServerProcessHandler *this,
        hkResult *result)
{
  hkProcessFactory *v2; // rbp
  int v3; // ebx
  hkProcessHandler *v5; // r14
  __int64 v6; // rsi
  char v8; // [rsp+48h] [rbp+10h] BYREF

  v2 = hkSingleton<hkProcessFactory>::s_instance;
  v3 = 0;
  if ( hkSingleton<hkProcessFactory>::s_instance->m_name2creationFunction.m_size <= 0 )
  {
    result->m_enum = HK_SUCCESS;
    return result;
  }
  else
  {
    v5 = &this->hkProcessHandler;
    v6 = 0i64;
    do
      (*(void (__fastcall **)(hkProcessHandler *, char *, unsigned __int64, _QWORD))v5->vfptr->gap8)(
        v5,
        &v8,
        (unsigned __int64)v2->m_name2creationFunction.m_data[v6++].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
        (unsigned int)v3++);
    while ( v3 < v2->m_name2creationFunction.m_size );
    result->m_enum = HK_SUCCESS;
    return result;
  }
}

// File Line: 198
// RVA: 0xE772E0
hkResult *__fastcall hkServerProcessHandler::selectProcess(hkServerProcessHandler *this, hkResult *result, int id)
{
  hkOArchive::write32(*(hkOArchive **)&this->m_selectable.m_bool, 5);
  hkOArchive::write8u(*(hkOArchive **)&this->m_selectable.m_bool, 193);
  hkOArchive::write32(*(hkOArchive **)&this->m_selectable.m_bool, id);
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 210
// RVA: 0xE77600
void __fastcall hkServerProcessHandler::step(hkServerProcessHandler *this, float frameTimeInMs)
{
  int v3; // eax
  __int64 i; // rbx
  __int64 v5; // rcx
  hkDisplaySerializeIStream *vfptr; // r8
  __int64 v7; // rax
  __int64 v8; // rcx
  hkBool result; // [rsp+40h] [rbp+8h] BYREF

  v3 = this->m_commandRouter.m_commandMap.m_map.m_numElems - 1;
  for ( i = v3; i >= 0; --i )
  {
    v5 = *(&this->m_commandRouter.m_commandMap.m_map.m_elem->key + i);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 56i64))(v5);
  }
  vfptr = (hkDisplaySerializeIStream *)this->hkProcessHandler::vfptr;
  if ( vfptr )
    hkCommandRouter::consumeCommands((hkCommandRouter *)&this->m_outStream, &result, vfptr);
  v7 = *(_QWORD *)&this->m_selectable.m_bool;
  if ( v7 )
    v8 = v7 - 64;
  else
    v8 = 0i64;
  (*(void (__fastcall **)(__int64))(*(_QWORD *)(v8 + 16) + 56i64))(v8 + 16);
}

