// File Line: 18
// RVA: 0xE76D90
void __fastcall hkServerProcessHandler::hkServerProcessHandler(hkServerProcessHandler *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts, hkStreamReader *inStream, hkStreamWriter *outStream)
{
  hkServerProcessHandler *v4; // rdi
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v5; // r14
  hkProcessHandler *v6; // r13
  hkStreamWriter *v7; // r15
  hkStreamReader *v8; // rbp
  hkProcess *v9; // rsi
  __int64 v10; // rcx
  hkProcessContext **v11; // rax
  __int64 v12; // rdx
  char *v13; // r8
  hkProcessContext *v14; // rcx
  _QWORD **v15; // rax
  hkDisplaySerializeIStream *v16; // rax
  hkDisplaySerializeIStream *v17; // rax
  _QWORD **v18; // rax
  hkDisplaySerializeOStream *v19; // rax
  hkDisplaySerializeOStream *v20; // rax
  _QWORD **v21; // rax
  hkServerDebugDisplayHandler *v22; // rax
  __int64 v23; // rax
  signed __int64 v24; // rcx
  int v25; // [rsp+50h] [rbp+8h]

  v4 = this;
  v5 = contexts;
  this->m_memSizeAndFlags = -1;
  this->m_referenceCount = 1;
  this->m_selectable.m_bool = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkServerProcessHandler::`vftable{for `hkReferencedObject};
  v6 = (hkProcessHandler *)&this->vfptr;
  this->vfptr = (hkProcessHandlerVtbl *)&hkServerProcessHandler::`vftable{for `hkProcessHandler};
  v7 = outStream;
  this->vfptr = (hkProcessVtbl *)&hkServerProcessHandler::`vftable{for `hkProcess};
  v8 = inStream;
  this->m_commandRouter.vfptr = (hkBaseObjectVtbl *)&hkCommandRouter::`vftable;
  *(_DWORD *)&this->m_commandRouter.m_memSizeAndFlags = 0x1FFFF;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&this->m_commandRouter.m_commandMap.m_map);
  v9 = 0i64;
  v4->m_processList.m_capacityAndFlags = 2147483648;
  v4->m_processList.m_data = 0i64;
  v4->m_processList.m_size = 0;
  v4->m_contexts.m_data = 0i64;
  v4->m_contexts.m_size = 0;
  v4->m_contexts.m_capacityAndFlags = 2147483648;
  hkCommandRouter::registerProcess(&v4->m_commandRouter, (hkProcess *)&v4->vfptr);
  if ( (v4->m_contexts.m_capacityAndFlags & 0x3FFFFFFF) < v5->m_size )
  {
    if ( v4->m_contexts.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v4->m_contexts.m_data,
        8 * v4->m_contexts.m_capacityAndFlags);
    v25 = 8 * v5->m_size;
    v4->m_contexts.m_data = (hkProcessContext **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                   (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                   &v25);
    v4->m_contexts.m_capacityAndFlags = v25 / 8;
  }
  v10 = v5->m_size;
  v11 = v4->m_contexts.m_data;
  v4->m_contexts.m_size = v10;
  v12 = v10;
  if ( (signed int)v10 > 0 )
  {
    v13 = (char *)((char *)v5->m_data - (char *)v11);
    do
    {
      v14 = *(hkProcessContext **)((char *)v11 + (_QWORD)v13);
      ++v11;
      *(v11 - 1) = v14;
      --v12;
    }
    while ( v12 );
  }
  if ( v8
    && (v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID),
        (v16 = (hkDisplaySerializeIStream *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v15[11] + 8i64))(
                                              v15[11],
                                              32i64)) != 0i64) )
  {
    hkDisplaySerializeIStream::hkDisplaySerializeIStream(v16, v8);
  }
  else
  {
    v17 = 0i64;
  }
  v4->m_inStream = v17;
  if ( v7
    && (v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID),
        (v19 = (hkDisplaySerializeOStream *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v18[11] + 8i64))(
                                              v18[11],
                                              32i64)) != 0i64) )
  {
    hkDisplaySerializeOStream::hkDisplaySerializeOStream(v19, v7);
  }
  else
  {
    v20 = 0i64;
  }
  v4->m_outStream = v20;
  v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = (hkServerDebugDisplayHandler *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v21[11] + 8i64))(
                                         v21[11],
                                         152i64);
  if ( v22 )
  {
    hkServerDebugDisplayHandler::hkServerDebugDisplayHandler(v22, v4->m_outStream, v4->m_inStream);
    if ( v23 )
    {
      v24 = v23 + 64;
      goto LABEL_21;
    }
  }
  else
  {
    v23 = 0i64;
  }
  v24 = 0i64;
LABEL_21:
  v4->m_displayHandler = (hkDebugDisplayHandler *)v24;
  if ( v23 )
    v9 = (hkProcess *)(v23 + 16);
  hkCommandRouter::registerProcess(&v4->m_commandRouter, v9);
  v4->m_processHandler = v6;
}

// File Line: 32
// RVA: 0xE76FF0
void __fastcall hkServerProcessHandler::~hkServerProcessHandler(hkServerProcessHandler *this)
{
  int v1; // edi
  hkServerProcessHandler *v2; // rbx
  int v3; // edi
  __int64 v4; // rsi
  hkProcess *v5; // rcx
  __int64 v6; // rax
  hkDisplaySerializeIStream *v7; // rcx
  hkDisplaySerializeOStream *v8; // rcx
  hkDebugDisplayHandler *v9; // rcx
  int v10; // er8
  int v11; // er8

  v1 = this->m_processList.m_size;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkServerProcessHandler::`vftable{for `hkReferencedObject};
  v3 = v1 - 1;
  this->vfptr = (hkProcessHandlerVtbl *)&hkServerProcessHandler::`vftable{for `hkProcessHandler};
  v4 = v3;
  for ( this->vfptr = (hkProcessVtbl *)&hkServerProcessHandler::`vftable{for `hkProcess}; v4 >= 0; --v4 )
  {
    v5 = v2->m_processList.m_data[v4];
    v6 = --v2->m_processList.m_size;
    if ( (_DWORD)v6 != v3 )
      v2->m_processList.m_data[v4] = v2->m_processList.m_data[v6];
    if ( v5 )
      v5->vfptr->__vecDelDtor(v5, 1u);
    --v3;
  }
  v7 = v2->m_inStream;
  if ( v7 )
    v7->vfptr->__vecDelDtor((hkBaseObject *)&v7->vfptr, 1u);
  v8 = v2->m_outStream;
  if ( v8 )
    v8->vfptr->__vecDelDtor((hkBaseObject *)&v8->vfptr, 1u);
  v9 = v2->m_displayHandler;
  if ( v9 )
    v9->vfptr->__vecDelDtor(v9, 1u);
  v10 = v2->m_contexts.m_capacityAndFlags;
  v2->m_contexts.m_size = 0;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_contexts.m_data,
      8 * v10);
  v2->m_contexts.m_data = 0i64;
  v2->m_contexts.m_capacityAndFlags = 2147483648;
  v11 = v2->m_processList.m_capacityAndFlags;
  v2->m_processList.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_processList.m_data,
      8 * v11);
  v2->m_processList.m_data = 0i64;
  v2->m_processList.m_capacityAndFlags = 2147483648;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v2->m_commandRouter.m_commandMap.m_map);
  v2->m_commandRouter.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  v2->vfptr = (hkProcessVtbl *)&hkProcess::`vftable;
  v2->vfptr = (hkProcessHandlerVtbl *)&hkProcessHandler::`vftable;
}

// File Line: 48
// RVA: 0xE77160
void __fastcall hkServerProcessHandler::getConsumableCommands(hkServerProcessHandler *this, char **commands, int *numCommands)
{
  *commands = cmds;
  *numCommands = 2;
}

// File Line: 54
// RVA: 0xE77180
void __fastcall hkServerProcessHandler::consumeCommand(hkServerProcessHandler *this, char command)
{
  hkServerProcessHandler *v2; // rbx
  char v3; // [rsp+20h] [rbp-18h]
  char v4; // [rsp+24h] [rbp-14h]
  hkBool result; // [rsp+48h] [rbp+10h]
  hkBool v6; // [rsp+50h] [rbp+18h]
  unsigned int array; // [rsp+58h] [rbp+20h]

  v2 = this;
  if ( (unsigned __int8)command == 194 )
  {
    hkIArchive::readArrayGeneric((hkIArchive *)this->vfptr, &array, 4, 1);
    if ( hkIArchive::isOk((hkIArchive *)v2->vfptr, &v6)->m_bool )
      (*(void (__fastcall **)(int *, char *, _QWORD))(*(_QWORD *)&v2[-1].m_contexts.m_size + 56i64))(
        &v2[-1].m_contexts.m_size,
        &v4,
        array);
  }
  else if ( (unsigned __int8)command == 195 )
  {
    hkIArchive::readArrayGeneric((hkIArchive *)this->vfptr, &array, 4, 1);
    if ( hkIArchive::isOk((hkIArchive *)v2->vfptr, &result)->m_bool )
      (*(void (__fastcall **)(int *, char *, _QWORD))(*(_QWORD *)&v2[-1].m_contexts.m_size + 64i64))(
        &v2[-1].m_contexts.m_size,
        &v3,
        array);
  }
}

// File Line: 80
// RVA: 0xE77340
hkResult *__fastcall hkServerProcessHandler::createProcess(hkServerProcessHandler *this, hkResult *result, int id)
{
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v3; // r14
  hkResult *v4; // rbx
  hkServerProcessHandler *v5; // rdi
  unsigned int v6; // ebp
  hkResult *v7; // rax
  hkProcess *v8; // rax
  hkProcess *v9; // rsi
  hkProcessHandler *v10; // rcx
  char v11; // [rsp+40h] [rbp+8h]

  v3 = &this[-1].m_contexts;
  v4 = result;
  v5 = this;
  v6 = id;
  if ( hkServerProcessHandler::findProcessByTag((hkServerProcessHandler *)((char *)this - 16), id) < 0 )
  {
    v8 = hkProcessFactory::createProcess(
           hkSingleton<hkProcessFactory>::s_instance,
           v6,
           (hkArray<hkProcessContext *,hkContainerHeapAllocator> *)&v5->m_processList);
    v9 = v8;
    if ( v8 )
    {
      v8->m_inStream = (hkDisplaySerializeIStream *)v5->vfptr;
      v8->m_outStream = *(hkDisplaySerializeOStream **)&v5->m_selectable.m_bool;
      v10 = 0i64;
      if ( v3 )
        v10 = (hkProcessHandler *)v5;
      v8->m_processHandler = v10;
      v8->m_displayHandler = (hkDebugDisplayHandler *)v5->m_inStream;
      if ( *(_DWORD *)&v5->m_commandRouter.m_haveClientVersion == (*((_DWORD *)&v5->m_commandRouter.m_haveClientVersion
                                                                   + 1) & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v5->m_commandRouter.m_commandMap.m_map.m_numElems,
          8);
      *(_QWORD *)(*(_QWORD *)&v5->m_commandRouter.m_commandMap.m_map.m_numElems
                + 8i64 * (signed int)(*(_DWORD *)&v5->m_commandRouter.m_haveClientVersion)++) = v9;
      hkCommandRouter::registerProcess((hkCommandRouter *)&v5->m_displayHandler, v9);
      v9->vfptr->init(v9);
      ((void (__fastcall *)(hkServerProcessHandler *, char *, _QWORD))v5->vfptr[3].__vecDelDtor)(v5, &v11, v6);
      v4->m_enum = 0;
    }
    else
    {
      v4->m_enum = 1;
    }
    v7 = v4;
  }
  else
  {
    v4->m_enum = 0;
    v7 = v4;
  }
  return v7;
}

// File Line: 108
// RVA: 0xE77720
signed __int64 __fastcall hkServerProcessHandler::findProcessByTag(hkServerProcessHandler *this, int tag)
{
  __int64 v2; // rsi
  unsigned int v3; // edi
  int v4; // er14
  hkServerProcessHandler *v5; // rbp
  __int64 v6; // rbx

  v2 = this->m_processList.m_size;
  v3 = 0;
  v4 = tag;
  v5 = this;
  v6 = 0i64;
  if ( v2 <= 0 )
    return 0xFFFFFFFFi64;
  while ( ((unsigned int (*)(void))v5->m_processList.m_data[v6]->vfptr->getProcessTag)() != v4 )
  {
    ++v6;
    ++v3;
    if ( v6 >= v2 )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 119
// RVA: 0xE77450
hkResult *__fastcall hkServerProcessHandler::deleteProcess(hkServerProcessHandler *this, hkResult *result, int id)
{
  hkResult *v3; // rbx
  hkServerProcessHandler *v4; // rdi
  int v5; // eax
  hkProcess *v6; // rsi
  __int64 v7; // r8
  hkResult *v8; // rax

  v3 = result;
  v4 = this;
  v5 = hkServerProcessHandler::findProcessByTag((hkServerProcessHandler *)((char *)this - 16), id);
  if ( v5 < 0 )
  {
    v3->m_enum = 0;
    v8 = v3;
  }
  else
  {
    v6 = *(hkProcess **)(8i64 * v5 + *(_QWORD *)&v4->m_commandRouter.m_commandMap.m_map.m_numElems);
    v7 = (signed int)--*(_DWORD *)&v4->m_commandRouter.m_haveClientVersion;
    if ( (_DWORD)v7 != v5 )
      *(_QWORD *)(*(_QWORD *)&v4->m_commandRouter.m_commandMap.m_map.m_numElems + 8i64 * v5) = *(_QWORD *)(*(_QWORD *)&v4->m_commandRouter.m_commandMap.m_map.m_numElems + 8 * v7);
    hkCommandRouter::unregisterProcess((hkCommandRouter *)&v4->m_displayHandler, v6);
    if ( v6 )
      v6->vfptr->__vecDelDtor(v6, 1u);
    v3->m_enum = 0;
    v8 = v3;
  }
  return v8;
}

// File Line: 136
// RVA: 0xE77500
hkProcess *__fastcall hkServerProcessHandler::getProcessByName(hkServerProcessHandler *this, const char *name)
{
  hkServerProcessHandler *v2; // rbx
  int v3; // eax
  int v4; // eax
  hkProcess *result; // rax

  v2 = this;
  v3 = (__int64)this->vfptr[1].__vecDelDtor((hkBaseObject *)this, (unsigned int)name);
  if ( v3 == -1
    || (v4 = hkServerProcessHandler::findProcessByTag((hkServerProcessHandler *)((char *)v2 - 16), v3), v4 == -1) )
  {
    result = 0i64;
  }
  else
  {
    result = *(hkProcess **)(*(_QWORD *)&v2->m_commandRouter.m_commandMap.m_map.m_numElems + 8i64 * v4);
  }
  return result;
}

// File Line: 151
// RVA: 0xE77550
void __fastcall hkServerProcessHandler::getProcessesByType(hkServerProcessHandler *this, int type, hkArray<hkProcess *,hkContainerHeapAllocator> *processes)
{
  int v3; // edi
  hkArray<hkProcess *,hkContainerHeapAllocator> *v4; // rbx
  int v5; // er15
  hkServerProcessHandler *v6; // rbp
  __int64 v7; // rsi
  __int64 v8; // r14

  v3 = 0;
  v4 = processes;
  v5 = type;
  processes->m_size = 0;
  v6 = this;
  if ( *(_DWORD *)&this->m_commandRouter.m_haveClientVersion > 0 )
  {
    v7 = 0i64;
    do
    {
      if ( (*(unsigned int (**)(void))(**(_QWORD **)(v7 + *(_QWORD *)&v6->m_commandRouter.m_commandMap.m_map.m_numElems)
                                     + 16i64))() == v5 )
      {
        v8 = *(_QWORD *)&v6->m_commandRouter.m_commandMap.m_map.m_numElems;
        if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
        v4->m_data[v4->m_size++] = *(hkProcess **)(v8 + v7);
      }
      ++v3;
      v7 += 8i64;
    }
    while ( v3 < *(_DWORD *)&v6->m_commandRouter.m_haveClientVersion );
  }
}

// File Line: 164
// RVA: 0xE77230
hkResult *__fastcall hkServerProcessHandler::registerProcess(hkServerProcessHandler *this, hkResult *result, const char *name, int id)
{
  hkServerProcessHandler *v4; // rsi
  int v5; // edi
  const char *v6; // rbp
  hkResult *v7; // r14
  signed int v8; // ebx

  v4 = this;
  v5 = id;
  v6 = name;
  v7 = result;
  v8 = hkString::strLen(name);
  if ( v8 > 0xFFFF )
    v8 = 0xFFFF;
  hkOArchive::write32(*(hkOArchive **)&v4->m_selectable.m_bool, v8 + 7);
  hkOArchive::write8u(*(hkOArchive **)&v4->m_selectable.m_bool, 192);
  hkOArchive::write32(*(hkOArchive **)&v4->m_selectable.m_bool, v5);
  hkOArchive::write16u(*(hkOArchive **)&v4->m_selectable.m_bool, v8);
  hkOArchive::writeRaw(*(hkOArchive **)&v4->m_selectable.m_bool, v6, (unsigned int)v8);
  v7->m_enum = 0;
  return v7;
}

// File Line: 184
// RVA: 0xE77690
hkResult *__fastcall hkServerProcessHandler::registerAllAvailableProcesss(hkServerProcessHandler *this, hkResult *result)
{
  hkProcessFactory *v2; // rbp
  int v3; // ebx
  hkResult *v4; // rdi
  hkProcessHandler *v5; // r14
  __int64 v6; // rsi
  hkResult *v7; // rax
  char v8; // [rsp+48h] [rbp+10h]

  v2 = hkSingleton<hkProcessFactory>::s_instance;
  v3 = 0;
  v4 = result;
  if ( hkSingleton<hkProcessFactory>::s_instance->m_name2creationFunction.m_size <= 0 )
  {
    result->m_enum = 0;
    v7 = result;
  }
  else
  {
    v5 = (hkProcessHandler *)&this->vfptr;
    v6 = 0i64;
    do
    {
      (*(void (__fastcall **)(hkProcessHandler *, char *, unsigned __int64, _QWORD))v5->vfptr->gap8)(
        v5,
        &v8,
        (_QWORD)v2->m_name2creationFunction.m_data[v6].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
        (unsigned int)v3++);
      ++v6;
    }
    while ( v3 < v2->m_name2creationFunction.m_size );
    v4->m_enum = 0;
    v7 = v4;
  }
  return v7;
}

// File Line: 198
// RVA: 0xE772E0
hkResult *__fastcall hkServerProcessHandler::selectProcess(hkServerProcessHandler *this, hkResult *result, int id)
{
  hkServerProcessHandler *v3; // rbx
  hkResult *v4; // rsi
  int v5; // edi

  v3 = this;
  v4 = result;
  v5 = id;
  hkOArchive::write32(*(hkOArchive **)&this->m_selectable.m_bool, 5);
  hkOArchive::write8u(*(hkOArchive **)&v3->m_selectable.m_bool, 193);
  hkOArchive::write32(*(hkOArchive **)&v3->m_selectable.m_bool, v5);
  v4->m_enum = 0;
  return v4;
}

// File Line: 210
// RVA: 0xE77600
void __fastcall hkServerProcessHandler::step(hkServerProcessHandler *this, float frameTimeInMs)
{
  hkServerProcessHandler *v2; // rdi
  int v3; // eax
  __int64 i; // rbx
  hkDisplaySerializeIStream *v5; // r8
  __int64 v6; // rax
  signed __int64 v7; // rcx
  hkBool result; // [rsp+40h] [rbp+8h]

  v2 = this;
  v3 = this->m_commandRouter.m_commandMap.m_map.m_numElems - 1;
  for ( i = v3;
        i >= 0;
        (*(void (**)(void))(**((_QWORD **)&v2->m_commandRouter.m_commandMap.m_map.m_elem->key + i--) + 56i64))() )
  {
    ;
  }
  v5 = (hkDisplaySerializeIStream *)v2->vfptr;
  if ( v5 )
    hkCommandRouter::consumeCommands((hkCommandRouter *)&v2->m_outStream, &result, v5);
  v6 = *(_QWORD *)&v2->m_selectable.m_bool;
  if ( v6 )
    v7 = v6 - 64;
  else
    v7 = 0i64;
  (*(void (__fastcall **)(signed __int64))(*(_QWORD *)(v7 + 16) + 56i64))(v7 + 16);
}

