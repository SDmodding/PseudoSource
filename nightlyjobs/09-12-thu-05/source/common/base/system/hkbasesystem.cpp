// File Line: 62
// RVA: 0xC60DC0
void __fastcall hkGetHardwareInfo(hkHardwareInfo *info)
{
  hkHardwareInfo *v1; // r14
  unsigned int v2; // edx
  HMODULE v3; // rax
  HMODULE v4; // rsi
  FARPROC v5; // rax
  void (__fastcall *v6)(char *, unsigned int *); // rdi
  int v7; // ebx
  char *v8; // rcx
  __int64 v9; // rdx
  _SYSTEM_INFO SystemInfo; // [rsp+20h] [rbp-1038h]
  char v11; // [rsp+50h] [rbp-1008h]
  char v12; // [rsp+58h] [rbp-1000h]
  unsigned int v13; // [rsp+1060h] [rbp+8h]

  v1 = info;
  GetSystemInfo(&SystemInfo);
  v2 = 12;
  if ( (signed int)SystemInfo.dwNumberOfProcessors < 12 )
    v2 = SystemInfo.dwNumberOfProcessors;
  v1->m_numThreads = v2;
  v3 = LoadLibraryA("kernel32.dll");
  v4 = v3;
  if ( v3 )
  {
    v5 = GetProcAddress(v3, "GetLogicalProcessorInformation");
    v6 = (void (__fastcall *)(char *, unsigned int *))v5;
    if ( v5 )
    {
      v7 = 0;
      v13 = 0;
      ((void (__fastcall *)(_QWORD, unsigned int *))v5)(0i64, &v13);
      if ( v13 <= 0x1000 )
      {
        v6(&v11, &v13);
        if ( v13 )
        {
          v8 = &v12;
          v9 = ((v13 - 1) >> 5) + 1;
          do
          {
            if ( !*(_DWORD *)v8 )
              ++v7;
            v8 += 32;
            --v9;
          }
          while ( v9 );
        }
        v1->m_numThreads = v7;
      }
    }
    FreeLibrary(v4);
  }
}

// File Line: 247
// RVA: 0xC61430
void showHavokBuild()
{
  ;
}

// File Line: 288
// RVA: 0xC61170
void __fastcall hkBaseSystem::initSingletons(hkBaseSystem *this)
{
  hkSingletonInitNode *v1; // rbx
  int v2; // ecx
  hkSingletonInitNode **v3; // r14
  __int64 (*v4)(void); // rax
  __int64 v5; // rax
  int v6; // esi
  __int64 v7; // rdi
  __int64 v8; // rbx
  __int64 v9; // rax
  int v10; // ecx
  _QWORD *array; // [rsp+20h] [rbp-18h]
  int v12; // [rsp+28h] [rbp-10h]
  int v13; // [rsp+2Ch] [rbp-Ch]

  v1 = hkSingletonInitList;
  v13 = 2147483648;
  v2 = 0;
  v3 = &hkSingletonInitList;
  array = 0i64;
  v12 = 0;
  if ( !hkSingletonInitList )
    goto LABEL_16;
  do
  {
    if ( *v1->m_value )
      goto LABEL_6;
    v4 = (__int64 (*)(void))v1->m_createFunc;
    if ( !v4 )
      goto LABEL_6;
    v5 = v4();
    if ( v5 )
    {
      *v1->m_value = (void *)v5;
      v2 = v12;
LABEL_6:
      v3 = &v1->m_next;
      v1 = v1->m_next;
      continue;
    }
    v10 = v12;
    if ( v12 == (v13 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 8);
      v10 = v12;
    }
    array[v10] = v1;
    ++v12;
    v1 = v1->m_next;
    (*v3)->m_next = 0i64;
    *v3 = v1;
    v2 = v12;
  }
  while ( v1 );
  if ( v2 )
  {
    while ( 1 )
    {
      v6 = v2 - 1;
      v7 = v2 - 1;
      if ( v2 - 1 >= 0 )
        break;
LABEL_15:
      if ( !v2 )
        goto LABEL_16;
    }
    while ( 2 )
    {
      v8 = array[v7];
      v9 = (*(__int64 (**)(void))(v8 + 8))();
      if ( v9 )
      {
        **(_QWORD **)(v8 + 24) = v9;
        *v3 = (hkSingletonInitNode *)v8;
        v2 = v12 - 1;
        v3 = (hkSingletonInitNode **)(v8 + 16);
        v12 = v2;
        if ( v2 != v6 )
        {
          array[v7] = array[v2];
          goto LABEL_13;
        }
      }
      else
      {
LABEL_13:
        v2 = v12;
      }
      --v6;
      if ( --v7 < 0 )
        goto LABEL_15;
      continue;
    }
  }
LABEL_16:
  v12 = 0;
  if ( v13 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      8 * v13);
}

// File Line: 374
// RVA: 0xC61300
void __fastcall hkBaseSystem::quitSingletons(hkBaseSystem *this)
{
  hkSingletonInitNode *v1; // rbx
  int v2; // ecx
  signed int v3; // er8
  __int64 v4; // rbx
  char *array; // [rsp+20h] [rbp-418h]
  int v6; // [rsp+28h] [rbp-410h]
  int i; // [rsp+2Ch] [rbp-40Ch]
  char v8; // [rsp+30h] [rbp-408h]

  v1 = hkSingletonInitList;
  v2 = 0;
  v3 = -2147483520;
  array = &v8;
  v6 = 0;
  for ( i = -2147483520; v1; v1 = v1->m_next )
  {
    if ( *v1->m_value && v1->m_createFunc )
    {
      if ( v2 == (v3 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
        v2 = v6;
      }
      *(_QWORD *)&array[8 * v2] = v1;
      v3 = i;
      v2 = v6++ + 1;
    }
  }
  v4 = v2 - 1;
  if ( v2 - 1 >= 0 )
  {
    do
    {
      hkReferencedObject::removeReferenceLockUnchecked(**(hkReferencedObject ***)(*(_QWORD *)&array[8 * v4--] + 24i64));
      **(_QWORD **)(*(_QWORD *)&array[8 * v4 + 8] + 24i64) = 0i64;
    }
    while ( v4 >= 0 );
    v3 = i;
  }
  v6 = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v3);
}

// File Line: 401
// RVA: 0xC60ED0
hkResult *__fastcall hkBaseSystem::init(hkResult *result, hkMemoryRouter *memoryRouter, void (__fastcall *errorReportFunction)(const char *, void *), void *errorReportObject)
{
  void *v4; // rsi
  void (__fastcall *v5)(const char *, void *); // rbp
  hkResult *v6; // rbx
  _QWORD **v7; // rax
  __int64 v8; // rax
  hkFileSystem *v9; // rdi
  _QWORD **v10; // rax
  hkDefaultError *v11; // rax
  hkError *v12; // rax
  hkError *v13; // rdi
  hkBaseSystem *v14; // rcx
  hkResult *v15; // rax
  hkResult resulta; // [rsp+30h] [rbp+8h]

  v4 = errorReportObject;
  v5 = errorReportFunction;
  v6 = result;
  if ( hkBaseSystemIsInitialized.m_bool )
  {
    v15 = result;
    result->m_enum = 0;
  }
  else
  {
    hkBaseSystem::initThread(&resulta, memoryRouter);
    hkReferencedObject::initializeLock();
    v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 16i64);
    v9 = (hkFileSystem *)v8;
    if ( v8 )
    {
      *(_DWORD *)(v8 + 8) = 0x1FFFF;
      *(_QWORD *)v8 = &hkWin32FileSystem::`vftable;
    }
    else
    {
      v9 = 0i64;
    }
    if ( hkSingleton<hkFileSystem>::s_instance )
      hkReferencedObject::removeReferenceLockUnchecked((hkReferencedObject *)&hkSingleton<hkFileSystem>::s_instance->vfptr);
    hkSingleton<hkFileSystem>::s_instance = v9;
    v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (hkDefaultError *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(v10[11], 72i64);
    if ( v11 )
    {
      hkDefaultError::hkDefaultError(v11, v5, v4);
      v13 = v12;
    }
    else
    {
      v13 = 0i64;
    }
    v14 = (hkBaseSystem *)hkSingleton<hkError>::s_instance;
    if ( hkSingleton<hkError>::s_instance )
      hkReferencedObject::removeReferenceLockUnchecked((hkReferencedObject *)&hkSingleton<hkError>::s_instance->vfptr);
    hkSingleton<hkError>::s_instance = v13;
    hkBaseSystem::initSingletons(v14);
    ((void (*)(void))hkSingleton<hkDummySingleton>::s_instance->vfptr[1].__first_virtual_table_function__)();
    hkProductFeatures::initialize();
    hkBaseSystemIsInitialized.m_bool = 1;
    v6->m_enum = 0;
    v15 = v6;
  }
  return v15;
}

// File Line: 438
// RVA: 0xC61010
hkResult *__fastcall hkBaseSystem::initThread(hkResult *result, hkMemoryRouter *memoryRouter)
{
  hkResult *v2; // rdi
  hkMemoryRouter *v3; // rbx

  v2 = result;
  v3 = memoryRouter;
  TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkMemoryRouter::replaceInstance(v3);
  hkMonitorStream::init();
  v2->m_enum = 0;
  return v2;
}

// File Line: 462
// RVA: 0xC61060
hkResult *__fastcall hkBaseSystem::quitThread(hkResult *result)
{
  hkResult *v1; // rbx
  hkMonitorStream *v2; // rax
  hkResult *v3; // rax

  v1 = result;
  v2 = (hkMonitorStream *)TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  if ( v2 )
    hkMonitorStream::quit(v2);
  if ( TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) )
    hkMemoryRouter::replaceInstance(0i64);
  v3 = v1;
  v1->m_enum = 0;
  return v3;
}

// File Line: 477
// RVA: 0xC610B0
hkResult *__fastcall hkBaseSystem::quit(hkResult *result)
{
  bool v1; // zf
  hkResult *v2; // rbx
  hkBaseSystem *v3; // rcx
  hkResult resulta; // [rsp+30h] [rbp+8h]

  v1 = hkBaseSystemIsInitialized.m_bool == 0;
  v2 = result;
  result->m_enum = 0;
  if ( !v1 )
  {
    hkReferencedObject::setLockMode(0);
    hkBaseSystem::quitSingletons(v3);
    if ( hkSocket::s_platformNetInitialized.m_bool && hkSocket::s_platformNetQuit )
    {
      hkSocket::s_platformNetQuit();
      hkSocket::s_platformNetInitialized.m_bool = 0;
    }
    if ( hkSingleton<hkError>::s_instance )
      hkReferencedObject::removeReferenceLockUnchecked((hkReferencedObject *)&hkSingleton<hkError>::s_instance->vfptr);
    hkSingleton<hkError>::s_instance = 0i64;
    if ( hkSingleton<hkFileSystem>::s_instance )
      hkReferencedObject::removeReferenceLockUnchecked((hkReferencedObject *)&hkSingleton<hkFileSystem>::s_instance->vfptr);
    hkSingleton<hkFileSystem>::s_instance = 0i64;
    hkReferencedObject::deinitializeLock();
    hkBaseSystem::quitThread(&resulta);
    hkBaseSystemIsInitialized.m_bool = 0;
  }
  return v2;
}

// File Line: 510
// RVA: 0xC61150
hkBool *__fastcall hkBaseSystem::isInitialized(hkBool *result)
{
  result->m_bool = hkBaseSystemIsInitialized.m_bool;
  return result;
}

// File Line: 519
// RVA: 0x15C75E0
hkSingletonInitNode *dynamic_initializer_for__hkSingletonRegisterhkDummySingleton__()
{
  hkSingletonInitNode *result; // rax

  hkSingletonRegisterhkDummySingleton.m_next = hkSingletonInitList;
  result = &hkSingletonRegisterhkDummySingleton;
  hkSingletonInitList = &hkSingletonRegisterhkDummySingleton;
  return result;
}

