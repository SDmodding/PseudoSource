// File Line: 29
// RVA: 0xE74EB0
void __fastcall hkVisualDebugger::hkVisualDebugger(hkVisualDebugger *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts, hkVtableClassRegistry *reg)
{
  int v3; // ebx
  hkVisualDebugger *v4; // rdi
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v5; // r14
  __int64 v6; // rsi
  hkReferencedObject *v7; // rcx
  hkErrStream v8; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkVisualDebugger::`vftable;
  v3 = 0;
  this->m_server = 0i64;
  this->s_SuppressPollForNewClients = 0;
  this->m_clients.m_data = 0i64;
  this->m_clients.m_size = 0;
  this->m_clients.m_capacityAndFlags = 2147483648;
  this->m_contexts.m_data = 0i64;
  this->m_contexts.m_size = 0;
  this->m_contexts.m_capacityAndFlags = 2147483648;
  this->m_trackedObjects.m_data = 0i64;
  this->m_trackedObjects.m_size = 0;
  this->m_trackedObjects.m_capacityAndFlags = 2147483648;
  this->m_trackCallbacks.m_data = 0i64;
  this->m_trackCallbacks.m_size = 0;
  this->m_trackCallbacks.m_capacityAndFlags = 2147483648;
  this->m_trackCallbackHandles.m_data = 0i64;
  this->m_trackCallbackHandles.m_size = 0;
  this->m_trackCallbackHandles.m_capacityAndFlags = 2147483648;
  this->m_classReg = reg;
  this->m_defaultProcesses.m_data = 0i64;
  this->m_defaultProcesses.m_size = 0;
  this->m_defaultProcesses.m_capacityAndFlags = 2147483648;
  this->m_requiredProcesses.m_data = 0i64;
  this->m_requiredProcesses.m_size = 0;
  this->m_requiredProcesses.m_capacityAndFlags = 2147483648;
  this->m_amTimingFrame.m_bool = 0;
  this->m_frameTimer.m_name = "Frame Timer";
  this->m_frameTimer.m_ticks_at_start = 0i64;
  this->m_frameTimer.m_ticks_total = 0i64;
  this->m_frameTimer.m_ticks_at_split = 0i64;
  this->m_frameTimer.m_split_total = 0i64;
  this->m_frameTimer.m_running_flag.m_bool = 0;
  this->m_frameTimer.m_num_timings = 0;
  this->m_overrideFrameTimeIfZero.m_bool = 1;
  v4 = this;
  v5 = contexts;
  if ( contexts->m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      hkVisualDebugger::addContext(v4, v5->m_data[v6]);
      ++v3;
      ++v6;
    }
    while ( v3 < v5->m_size );
  }
  ((void (__fastcall *)(hkError *, signed __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    311668207i64,
    "Visual Debugger");
  hkErrStream::hkErrStream(&v8, &buf, 512);
  hkOstream::operator<<((hkOstream *)&v8.vfptr, "VDB Server instance has been created");
  hkError::messageReport(-1, &buf, "hkVisualDebugger.cpp", 37);
  hkOstream::~hkOstream((hkOstream *)&v8.vfptr);
  hkProcessRegisterUtil::registerAllCommonProcesses();
  hkVisualDebugger::addDefaultProcess(v4, "Debug Display");
  hkVisualDebugger::addDefaultProcess(v4, "Shapes");
  hkVisualDebugger::addDefaultProcess(v4, "Mouse Picking");
  hkVisualDebugger::addDefaultProcess(v4, "RemoteObject");
  v7 = (hkReferencedObject *)&v4->m_classReg->vfptr;
  if ( v7 )
    hkReferencedObject::addReference(v7);
  ((void (*)(void))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)();
}

// File Line: 52
// RVA: 0xE762D0
void __fastcall hkVisualDebugger::~hkVisualDebugger(hkVisualDebugger *this)
{
  hkVisualDebugger *v1; // rbx
  int v2; // esi
  __int64 v3; // rdi
  int v4; // edi
  hkStringPtr *v5; // rsi
  int v6; // edi
  hkStringPtr *v7; // rsi
  hkReferencedObject *v8; // rcx
  int v9; // edi
  hkStringPtr *v10; // rsi
  int v11; // er8
  int v12; // edi
  hkStringPtr *v13; // rsi
  int v14; // er8
  int v15; // er8
  int v16; // er8
  int v17; // eax
  int v18; // er8
  int v19; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkVisualDebugger::`vftable;
  hkVisualDebugger::shutdown(this);
  v2 = 0;
  if ( v1->m_contexts.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v1->m_contexts.m_data[v3]->vfptr->setOwner(v1->m_contexts.m_data[v3], 0i64);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_contexts.m_size );
  }
  v4 = v1->m_defaultProcesses.m_size - 1;
  if ( v4 >= 0 )
  {
    v5 = &v1->m_defaultProcesses.m_data[v4];
    do
    {
      hkStringPtr::~hkStringPtr(v5);
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v1->m_defaultProcesses.m_size = 0;
  v6 = v1->m_requiredProcesses.m_size - 1;
  if ( v6 >= 0 )
  {
    v7 = &v1->m_requiredProcesses.m_data[v6];
    do
    {
      hkStringPtr::~hkStringPtr(v7);
      --v7;
      --v6;
    }
    while ( v6 >= 0 );
  }
  v1->m_requiredProcesses.m_size = 0;
  v8 = (hkReferencedObject *)&v1->m_classReg->vfptr;
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  v9 = v1->m_requiredProcesses.m_size - 1;
  if ( v9 >= 0 )
  {
    v10 = &v1->m_requiredProcesses.m_data[v9];
    do
    {
      hkStringPtr::~hkStringPtr(v10);
      --v10;
      --v9;
    }
    while ( v9 >= 0 );
  }
  v11 = v1->m_requiredProcesses.m_capacityAndFlags;
  v1->m_requiredProcesses.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_requiredProcesses.m_data,
      8 * v11);
  v1->m_requiredProcesses.m_data = 0i64;
  v1->m_requiredProcesses.m_capacityAndFlags = 2147483648;
  v12 = v1->m_defaultProcesses.m_size - 1;
  if ( v12 >= 0 )
  {
    v13 = &v1->m_defaultProcesses.m_data[v12];
    do
    {
      hkStringPtr::~hkStringPtr(v13);
      --v13;
      --v12;
    }
    while ( v12 >= 0 );
  }
  v14 = v1->m_defaultProcesses.m_capacityAndFlags;
  v1->m_defaultProcesses.m_size = 0;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_defaultProcesses.m_data,
      8 * v14);
  v1->m_defaultProcesses.m_data = 0i64;
  v1->m_defaultProcesses.m_capacityAndFlags = 2147483648;
  v15 = v1->m_trackCallbackHandles.m_capacityAndFlags;
  v1->m_trackCallbackHandles.m_size = 0;
  if ( v15 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_trackCallbackHandles.m_data,
      8 * v15);
  v1->m_trackCallbackHandles.m_data = 0i64;
  v1->m_trackCallbackHandles.m_capacityAndFlags = 2147483648;
  v16 = v1->m_trackCallbacks.m_capacityAndFlags;
  v1->m_trackCallbacks.m_size = 0;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_trackCallbacks.m_data,
      8 * v16);
  v1->m_trackCallbacks.m_data = 0i64;
  v1->m_trackCallbacks.m_capacityAndFlags = 2147483648;
  v17 = v1->m_trackedObjects.m_capacityAndFlags;
  v1->m_trackedObjects.m_size = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_trackedObjects.m_data,
      24 * (v17 & 0x3FFFFFFF));
  v1->m_trackedObjects.m_data = 0i64;
  v1->m_trackedObjects.m_capacityAndFlags = 2147483648;
  v18 = v1->m_contexts.m_capacityAndFlags;
  v1->m_contexts.m_size = 0;
  if ( v18 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_contexts.m_data,
      8 * v18);
  v1->m_contexts.m_data = 0i64;
  v1->m_contexts.m_capacityAndFlags = 2147483648;
  v19 = v1->m_clients.m_capacityAndFlags;
  v1->m_clients.m_size = 0;
  if ( v19 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_clients.m_data,
      16 * v19);
  v1->m_clients.m_data = 0i64;
  v1->m_clients.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 69
// RVA: 0xE76750
void __fastcall hkVisualDebugger::addContext(hkVisualDebugger *this, hkProcessContext *context)
{
  hkProcessContext *v2; // rdi
  hkVisualDebugger *v3; // rbx

  v2 = context;
  v3 = this;
  context->vfptr->setOwner(context, this);
  if ( v3->m_contexts.m_size == (v3->m_contexts.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_contexts, 8);
  v3->m_contexts.m_data[v3->m_contexts.m_size++] = v2;
}

// File Line: 76
// RVA: 0xE75780
void __fastcall hkVisualDebugger::shutdown(hkVisualDebugger *this)
{
  hkVisualDebugger *v1; // rdi
  int i; // ebx
  hkSocket *v3; // rcx
  hkErrStream v4; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v1 = this;
  ((void (__fastcall *)(hkError *, signed __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    311668207i64,
    "Shutting down Visual Debugger..");
  for ( i = v1->m_clients.m_size - 1; i >= 0; --i )
  {
    hkVisualDebugger::writeStep(v1, i, 0.0);
    hkVisualDebugger::deleteClient(v1, i);
    hkErrStream::hkErrStream(&v4, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v4.vfptr, "Client deleted.");
    hkError::messageReport(-1, &buf, "hkVisualDebugger.cpp", 86);
    hkOstream::~hkOstream((hkOstream *)&v4.vfptr);
  }
  v3 = v1->m_server;
  if ( v3 )
  {
    v3->vfptr->__vecDelDtor((hkBaseObject *)&v3->vfptr, 1u);
    v1->m_server = 0i64;
    hkErrStream::hkErrStream(&v4, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v4.vfptr, "Server deleted.");
    hkError::messageReport(-1, &buf, "hkVisualDebugger.cpp", 93);
    hkOstream::~hkOstream((hkOstream *)&v4.vfptr);
  }
  ((void (*)(void))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)();
}

// File Line: 99
// RVA: 0xE750C0
void __fastcall hkVisualDebugger::serve(hkVisualDebugger *this, int listenPort)
{
  hkVisualDebugger *v2; // rbx
  unsigned int v3; // edi
  hkSocket *v4; // rax
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  int v7; // er9
  hkErrStream v8; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]
  char v10; // [rsp+250h] [rbp+8h]

  v2 = this;
  v3 = listenPort;
  ((void (__fastcall *)(hkError *, signed __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    311668200i64,
    "Serving");
  if ( v2->m_server )
  {
    hkErrStream::hkErrStream(&v8, &buf, 512);
    hkOstream::operator<<(
      (hkOstream *)&v8.vfptr,
      "Server has already been created, only one server allowed per visual debugger instance");
    v7 = 127;
    goto LABEL_8;
  }
  v4 = hkSocket::create();
  v2->m_server = v4;
  if ( !v4 )
    goto LABEL_6;
  if ( *(_DWORD *)((__int64 (__fastcall *)(hkSocket *, char *, _QWORD))v4->vfptr[4].__vecDelDtor)(v4, &v10, v3) )
  {
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_server->vfptr);
    v2->m_server = 0i64;
LABEL_6:
    hkErrStream::hkErrStream(&v8, &buf, 512);
    hkOstream::operator<<(
      (hkOstream *)&v8.vfptr,
      "Server could not be created, please check that you platform supports sockets with the hkBase library");
    v7 = 122;
    goto LABEL_8;
  }
  hkErrStream::hkErrStream(&v8, &buf, 512);
  v5 = hkOstream::operator<<((hkOstream *)&v8.vfptr, "Server created and will poll for new client(s) on port ");
  v6 = hkOstream::operator<<(v5, v3, (int)v5);
  hkOstream::operator<<(v6, " every frame");
  v7 = 111;
LABEL_8:
  hkError::messageReport(-1, &buf, "hkVisualDebugger.cpp", v7);
  hkOstream::~hkOstream((hkOstream *)&v8.vfptr);
  ((void (*)(void))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)();
}

// File Line: 134
// RVA: 0xE75D50
void __fastcall hkVisualDebugger::createRequiredAndDefaultProcessList(hkVisualDebugger *this, hkVisualDebuggerClient *vdbClient, hkStringBuf *viewerNames)
{
  hkVisualDebuggerClient *v3; // r13
  hkVisualDebugger *v4; // rsi
  hkStringBuf *v5; // r12
  __int64 v6; // rbx
  int v7; // edi
  int v8; // ebp
  int v9; // er15
  __int64 v10; // r14
  __int64 v11; // rbp
  hkStringPtr *v12; // r12
  int v13; // edi
  unsigned __int64 v14; // rax
  int v15; // eax
  unsigned int v16; // [rsp+80h] [rbp+8h]
  hkStringBuf *v17; // [rsp+90h] [rbp+18h]
  char v18; // [rsp+98h] [rbp+20h]

  v17 = viewerNames;
  v3 = vdbClient;
  v4 = this;
  v5 = viewerNames;
  hkStringBuf::operator=(viewerNames, "Turning on the following viewers: [");
  v6 = 0i64;
  v7 = 0;
  if ( v4->m_requiredProcesses.m_size > 0 )
  {
    do
    {
      v8 = v3->m_processHandler->vfptr->getProcessId(
             (hkProcessHandler *)&v3->m_processHandler->vfptr,
             (const char *)(*(_QWORD *)((_BYTE *)&v4->m_requiredProcesses.m_data->m_stringAndFlag + v6) & 0xFFFFFFFFFFFFFFFEui64));
      if ( v8 >= 0 )
      {
        hkStringBuf::appendJoin(
          v5,
          " ",
          (const char *)(*(_QWORD *)((_BYTE *)&v4->m_requiredProcesses.m_data->m_stringAndFlag + v6) & 0xFFFFFFFFFFFFFFFEui64),
          0i64,
          0i64,
          0i64,
          0i64);
        v3->m_processHandler->vfptr->createProcess(
          (hkProcessHandler *)&v3->m_processHandler->vfptr,
          (hkResult *)&v16,
          v8);
      }
      ++v7;
      v6 += 8i64;
    }
    while ( v7 < v4->m_requiredProcesses.m_size );
    v6 = 0i64;
  }
  v9 = 0;
  if ( v4->m_defaultProcesses.m_size <= 0 )
    goto LABEL_21;
  v10 = 0i64;
  do
  {
    v16 = v3->m_processHandler->vfptr->getProcessId(
            (hkProcessHandler *)&v3->m_processHandler->vfptr,
            (const char *)((_QWORD)v4->m_defaultProcesses.m_data[v10].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
    if ( (v16 & 0x80000000) != 0 )
      goto LABEL_20;
    v11 = v4->m_requiredProcesses.m_size;
    v12 = v4->m_defaultProcesses.m_data;
    v13 = 0;
    if ( v11 <= 0 )
      goto LABEL_18;
    while ( 1 )
    {
      v14 = (_QWORD)v12[v10].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64;
      if ( !((_QWORD)v4->m_requiredProcesses.m_data[v6].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64) )
        break;
      if ( v14 )
      {
        v15 = hkString::strCmp(
                (const char *)((_QWORD)v4->m_requiredProcesses.m_data[v6].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                (const char *)((_QWORD)v12[v10].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
        goto LABEL_14;
      }
LABEL_15:
      ++v6;
      ++v13;
      if ( v6 >= v11 )
        goto LABEL_18;
    }
    v15 = -(v14 != 0);
LABEL_14:
    if ( v15 )
      goto LABEL_15;
    if ( v13 == -1 )
    {
LABEL_18:
      v5 = v17;
      v6 = 0i64;
      hkStringBuf::appendJoin(
        v17,
        " ",
        (const char *)((_QWORD)v4->m_defaultProcesses.m_data[v10].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
        0i64,
        0i64,
        0i64,
        0i64);
      v3->m_processHandler->vfptr->createProcess(
        (hkProcessHandler *)&v3->m_processHandler->vfptr,
        (hkResult *)&v18,
        v16);
    }
    else
    {
      v5 = v17;
      v6 = 0i64;
    }
LABEL_20:
    ++v9;
    ++v10;
  }
  while ( v9 < v4->m_defaultProcesses.m_size );
LABEL_21:
  hkStringBuf::operator+=(v5, "]");
}

// File Line: 165
// RVA: 0xE75220
void __fastcall hkVisualDebugger::capture(hkVisualDebugger *this, const char *captureFilename)
{
  hkVisualDebugger *v2; // rsi
  const char *v3; // rdi
  hkStreamWriter *v4; // rbx
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  int v7; // eax
  hkOstream *v8; // rax
  hkOstream *v9; // rax
  hkErrStream v10; // [rsp+20h] [rbp-E0h]
  hkStringBuf viewerNames; // [rsp+40h] [rbp-C0h]
  char buf; // [rsp+D0h] [rbp-30h]
  char v13; // [rsp+300h] [rbp+200h]
  char v14; // [rsp+308h] [rbp+208h]

  v2 = this;
  v3 = captureFilename;
  ((void (__fastcall *)(hkError *, signed __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    311668199i64,
    "Capturing");
  v4 = *(hkStreamWriter **)((__int64 (__fastcall *)(hkFileSystem *, char *, const char *, signed __int64))hkSingleton<hkFileSystem>::s_instance->vfptr[2].__vecDelDtor)(
                             hkSingleton<hkFileSystem>::s_instance,
                             &v14,
                             v3,
                             3i64);
  if ( v4
    && *(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, char *))v4->vfptr[1].__first_virtual_table_function__)(
                   v4,
                   &v13) )
  {
    hkErrStream::hkErrStream(&v10, &buf, 512);
    v5 = hkOstream::operator<<((hkOstream *)&v10.vfptr, "Capturing simulation state to ");
    v6 = hkOstream::operator<<(v5, v3);
    hkOstream::operator<<(v6, "");
    hkError::messageReport(-1, &buf, "hkVisualDebugger.cpp", 171);
    hkOstream::~hkOstream((hkOstream *)&v10.vfptr);
    hkVisualDebugger::createClient(v2, 0i64, 0i64, v4);
    v7 = v2->m_clients.m_size - 1;
    viewerNames.m_string.m_capacityAndFlags = -2147483520;
    viewerNames.m_string.m_size = 1;
    viewerNames.m_string.m_data = viewerNames.m_string.m_storage;
    viewerNames.m_string.m_storage[0] = 0;
    hkVisualDebugger::createRequiredAndDefaultProcessList(v2, &v2->m_clients.m_data[v7], &viewerNames);
    hkErrStream::hkErrStream(&v10, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v10.vfptr, viewerNames.m_string.m_data);
    hkError::messageReport(-1, &buf, "hkVisualDebugger.cpp", 182);
    hkOstream::~hkOstream((hkOstream *)&v10.vfptr);
    viewerNames.m_string.m_size = 0;
    if ( viewerNames.m_string.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        viewerNames.m_string.m_data,
        viewerNames.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  }
  else
  {
    hkErrStream::hkErrStream(&v10, &buf, 512);
    v8 = hkOstream::operator<<((hkOstream *)&v10.vfptr, "Capture file ");
    v9 = hkOstream::operator<<(v8, v3);
    hkOstream::operator<<(v9, " could not be opened for writing");
    hkError::messageReport(-1, &buf, "hkVisualDebugger.cpp", 186);
    hkOstream::~hkOstream((hkOstream *)&v10.vfptr);
  }
  ((void (*)(void))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)();
  if ( v4 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v4->vfptr);
}

// File Line: 193
// RVA: 0xE75460
void __fastcall hkVisualDebugger::capture(hkVisualDebugger *this, hkMemoryTrack *outgoingMemory, hkMemoryTrack *incommingMemory)
{
  hkVisualDebugger *v3; // r14
  hkMemoryTrack *v4; // rsi
  hkMemoryTrack *v5; // rdi
  _QWORD **v6; // rax
  __int64 v7; // rax
  hkStreamWriter *v8; // rbx
  _QWORD **v9; // rax
  hkMemoryTrackStreamReader *v10; // rax
  hkStreamReader *v11; // rax
  hkStreamReader *v12; // rdi
  int v13; // eax
  hkVisualDebuggerClient *v14; // rbx
  hkStreamWriter *v15; // rax
  hkErrStream v16; // [rsp+20h] [rbp-E0h]
  hkStringBuf viewerNames; // [rsp+40h] [rbp-C0h]
  char buf; // [rsp+D0h] [rbp-30h]
  char v19; // [rsp+308h] [rbp+208h]

  v3 = this;
  v4 = incommingMemory;
  v5 = outgoingMemory;
  ((void (__fastcall *)(hkError *, signed __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    3200188100i64,
    "Capturing to memory stream");
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 32i64);
  v8 = (hkStreamWriter *)v7;
  if ( v7 )
  {
    *(_DWORD *)(v7 + 8) = 0x1FFFF;
    *(_QWORD *)(v7 + 16) = v5;
    *(_QWORD *)v7 = &hkMemoryTrackStreamWriter::`vftable;
    *(_DWORD *)(v7 + 24) = 1;
  }
  else
  {
    v8 = 0i64;
  }
  v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkMemoryTrackStreamReader *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v9[11] + 8i64))(
                                       v9[11],
                                       40i64);
  if ( v10 )
  {
    hkMemoryTrackStreamReader::hkMemoryTrackStreamReader(v10, v4, MEMORY_INPLACE, 1);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  if ( v8
    && *(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, char *))v8->vfptr[1].__first_virtual_table_function__)(
                   v8,
                   &v19)
    && v12
    && *(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, char *))v12->vfptr[1].__first_virtual_table_function__)(
                   v12,
                   &v19) )
  {
    hkErrStream::hkErrStream(&v16, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v16.vfptr, "Capturing simulation state to memory stream.");
    hkError::messageReport(-1, &buf, "hkVisualDebugger.cpp", 200);
    hkOstream::~hkOstream((hkOstream *)&v16.vfptr);
    hkVisualDebugger::createClient(v3, 0i64, v12, v8);
    hkReferencedObject::removeReference((hkReferencedObject *)&v8->vfptr);
    hkReferencedObject::removeReference((hkReferencedObject *)&v12->vfptr);
    v13 = v3->m_clients.m_size - 1;
    viewerNames.m_string.m_capacityAndFlags = -2147483520;
    viewerNames.m_string.m_size = 1;
    viewerNames.m_string.m_data = viewerNames.m_string.m_storage;
    viewerNames.m_string.m_storage[0] = 0;
    v14 = &v3->m_clients.m_data[v13];
    hkVisualDebugger::createRequiredAndDefaultProcessList(v3, v14, &viewerNames);
    hkErrStream::hkErrStream(&v16, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v16.vfptr, viewerNames.m_string.m_data);
    hkError::messageReport(-1, &buf, "hkVisualDebugger.cpp", 213);
    hkOstream::~hkOstream((hkOstream *)&v16.vfptr);
    v15 = hkOArchive::getStreamWriter((hkOArchive *)&v14->m_processHandler->m_outStream->vfptr);
    v15->vfptr[2].__first_virtual_table_function__((hkBaseObject *)&v15->vfptr);
    viewerNames.m_string.m_size = 0;
    if ( viewerNames.m_string.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        viewerNames.m_string.m_data,
        viewerNames.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  }
  else
  {
    hkErrStream::hkErrStream(&v16, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v16.vfptr, "Could not create memory stream for writing.");
    hkError::messageReport(-1, &buf, "hkVisualDebugger.cpp", 220);
    hkOstream::~hkOstream((hkOstream *)&v16.vfptr);
  }
  ((void (*)(void))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)();
}16.vfptr);
  }

// File Line: 227
// RVA: 0xE75720
void __fastcall hkVisualDebugger::endCapture(hkVisualDebugger *this)
{
  hkVisualDebugger *v1; // rsi
  int v2; // ebx
  signed __int64 v3; // rdi

  v1 = this;
  v2 = this->m_clients.m_size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      if ( !v1->m_clients.m_data[v3].m_socket )
        hkVisualDebugger::deleteClient(v1, v2);
      --v3;
      --v2;
    }
    while ( v2 >= 0 );
  }
}

// File Line: 240
// RVA: 0xE76960
void __fastcall hkVisualDebugger::deleteClient(hkVisualDebugger *this, int i)
{
  hkVisualDebuggerClient *v2; // rsi
  int v3; // ebp
  hkVisualDebugger *v4; // rbx
  signed __int64 v5; // rdi
  hkReferencedObject *v6; // rcx
  hkReferencedObject *v7; // rcx
  __int64 v8; // rcx
  hkVisualDebuggerClient *v9; // rax
  signed __int64 v10; // rdx
  signed __int64 v11; // r8
  signed __int64 v12; // rax
  signed __int64 v13; // r8
  __int64 v14; // rcx

  v2 = this->m_clients.m_data;
  v3 = i;
  v4 = this;
  v5 = i;
  v6 = (hkReferencedObject *)&v2[v5].m_processHandler->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v7 = (hkReferencedObject *)&v2[v5].m_socket->vfptr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  v8 = --v4->m_clients.m_size;
  if ( (_DWORD)v8 != v3 )
  {
    v9 = v4->m_clients.m_data;
    v10 = 2i64;
    v11 = (signed __int64)&v9[v8];
    v12 = (signed __int64)&v9[v5];
    v13 = v11 - v12;
    do
    {
      v14 = *(_QWORD *)(v13 + v12);
      v12 += 8i64;
      *(_QWORD *)(v12 - 8) = v14;
      --v10;
    }
    while ( v10 );
  }
}

// File Line: 254
// RVA: 0xE76A00
void __fastcall hkVisualDebugger::createClient(hkVisualDebugger *this, hkSocket *socket, hkStreamReader *reader, hkStreamWriter *writer)
{
  hkStreamWriter *v4; // rbx
  hkStreamReader *v5; // r14
  hkSocket *v6; // r15
  hkVisualDebugger *v7; // rsi
  __int64 v8; // rbp
  int v9; // er9
  int v10; // eax
  int v11; // eax
  hkVisualDebuggerClient *v12; // r13
  _QWORD **v13; // rax
  hkServerProcessHandler *v14; // rax
  int v15; // ebx
  __int64 v16; // rdi
  int v17; // eax
  int v18; // ebp
  int v19; // er15
  __int64 v20; // r14
  __int64 v21; // rbp
  hkStringPtr *v22; // r12
  int v23; // edi
  __int64 v24; // rbx
  const char *v25; // rdx
  const char *v26; // rcx
  int v27; // eax
  hkResult result; // [rsp+70h] [rbp+8h]
  hkResult v29; // [rsp+78h] [rbp+10h]
  char v30; // [rsp+88h] [rbp+20h]

  v4 = writer;
  v5 = reader;
  v6 = socket;
  v7 = this;
  if ( writer )
  {
    hkVersionReporter::sendStructureLayout(&result, writer);
    hkVersionReporter::sendVersionInformation(&result, v4);
  }
  v8 = v7->m_clients.m_size;
  v9 = v8 + 1;
  v10 = v7->m_clients.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 >= (signed int)v8 + 1 )
  {
    result.m_enum = 0;
  }
  else
  {
    v11 = 2 * v10;
    if ( v9 < v11 )
      v9 = v11;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v7->m_clients,
      v9,
      16);
  }
  ++v7->m_clients.m_size;
  v12 = &v7->m_clients.m_data[v8];
  v12->m_socket = v6;
  v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (hkServerProcessHandler *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v13[11] + 8i64))(
                                    v13[11],
                                    144i64);
  if ( v14 )
    hkServerProcessHandler::hkServerProcessHandler(v14, &v7->m_contexts, v5, v4);
  v12->m_processHandler = v14;
  hkServerProcessHandler::registerAllAvailableProcesss(v14, &v29);
  v15 = 0;
  if ( v7->m_requiredProcesses.m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      v17 = v12->m_processHandler->vfptr->getProcessId(
              (hkProcessHandler *)&v12->m_processHandler->vfptr,
              (const char *)((_QWORD)v7->m_requiredProcesses.m_data[v16].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
      v18 = v17;
      if ( v17 >= 0 )
      {
        v12->m_processHandler->vfptr->createProcess((hkProcessHandler *)&v12->m_processHandler->vfptr, &v29, v17);
        v12->m_processHandler->vfptr->selectProcess(
          (hkProcessHandler *)&v12->m_processHandler->vfptr,
          (hkResult *)&v30,
          v18);
      }
      ++v15;
      ++v16;
    }
    while ( v15 < v7->m_requiredProcesses.m_size );
  }
  v19 = 0;
  if ( v7->m_defaultProcesses.m_size <= 0 )
    goto LABEL_29;
  v20 = 0i64;
  do
  {
    v29.m_enum = v12->m_processHandler->vfptr->getProcessId(
                   (hkProcessHandler *)&v12->m_processHandler->vfptr,
                   (const char *)((_QWORD)v7->m_defaultProcesses.m_data[v20].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
    if ( (signed int)v29.m_enum < 0 )
      goto LABEL_28;
    v21 = v7->m_requiredProcesses.m_size;
    v22 = v7->m_defaultProcesses.m_data;
    v23 = 0;
    v24 = 0i64;
    if ( v21 <= 0 )
      goto LABEL_27;
    while ( 1 )
    {
      v25 = (const char *)((_QWORD)v22[v20].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
      v26 = (const char *)((_QWORD)v7->m_requiredProcesses.m_data[v24].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
      if ( !v26 )
        break;
      if ( v25 )
      {
        v27 = hkString::strCmp(v26, v25);
        goto LABEL_23;
      }
LABEL_24:
      ++v24;
      ++v23;
      if ( v24 >= v21 )
        goto LABEL_27;
    }
    v27 = -(v25 != 0i64);
LABEL_23:
    if ( v27 )
      goto LABEL_24;
    if ( v23 == -1 )
LABEL_27:
      v12->m_processHandler->vfptr->selectProcess(
        (hkProcessHandler *)&v12->m_processHandler->vfptr,
        (hkResult *)&v30,
        v29.m_enum);
LABEL_28:
    ++v19;
    ++v20;
  }
  while ( v19 < v7->m_defaultProcesses.m_size );
LABEL_29:
  hkVisualDebugger::writeStep(v7, v7->m_clients.m_size - 1, 0.0);
}

// File Line: 294
// RVA: 0xE76950
void __fastcall hkVisualDebugger::SupressPollForNewClient(hkVisualDebugger *this, bool val)
{
  this->s_SuppressPollForNewClients = val;
}

// File Line: 299
// RVA: 0xE761C0
void __fastcall hkVisualDebugger::pollForNewClients(hkVisualDebugger *this)
{
  hkVisualDebugger *v1; // rbx
  unsigned __int64 v2; // rax
  unsigned __int64 v3; // rcx
  hkSocket *v4; // rcx
  hkSocket *v5; // rdi
  unsigned __int64 v6; // rax
  hkErrStream v7; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v1 = this;
  if ( !this->s_SuppressPollForNewClients )
  {
    if ( this->m_amTimingFrame.m_bool && this->m_frameTimer.m_running_flag.m_bool )
    {
      v2 = hkStopwatch::getTickCounter();
      v1->m_frameTimer.m_running_flag.m_bool = 0;
      v3 = v2 - v1->m_frameTimer.m_ticks_at_start;
      v1->m_frameTimer.m_split_total += v2 - v1->m_frameTimer.m_ticks_at_split;
      v1->m_frameTimer.m_ticks_total += v3;
      ++v1->m_frameTimer.m_num_timings;
    }
    v4 = v1->m_server;
    if ( v4 )
    {
      v5 = (hkSocket *)((__int64 (*)(void))v4->vfptr[5].__first_virtual_table_function__)();
      if ( v5 )
      {
        hkErrStream::hkErrStream(&v7, &buf, 512);
        hkOstream::operator<<(
          (hkOstream *)&v7.vfptr,
          "A new network client has been received (host name not available at present)");
        hkError::messageReport(-1, &buf, "hkVisualDebugger.cpp", 312);
        hkOstream::~hkOstream((hkOstream *)&v7.vfptr);
        hkVisualDebugger::createClient(
          v1,
          v5,
          (hkStreamReader *)&v5->m_reader.vfptr,
          (hkStreamWriter *)&v5->m_writer.vfptr);
      }
    }
    if ( v1->m_amTimingFrame.m_bool )
    {
      v1->m_frameTimer.m_running_flag.m_bool = 1;
      v6 = hkStopwatch::getTickCounter();
      v1->m_frameTimer.m_ticks_at_start = v6;
      v1->m_frameTimer.m_ticks_at_split = v6;
    }
  }
}

// File Line: 324
// RVA: 0xE76C40
void __fastcall hkVisualDebugger::writeStep(hkVisualDebugger *this, int i, float t)
{
  hkVisualDebuggerClient *v3; // rbx
  hkOArchive *v4; // rbx
  hkStreamWriter *v5; // rax

  v3 = &this->m_clients.m_data[i];
  if ( v3->m_processHandler->vfptr->isOk((hkProcess *)&v3->m_processHandler->vfptr) )
  {
    v4 = (hkOArchive *)&v3->m_processHandler->m_outStream->vfptr;
    hkOArchive::write32u(v4, 5u);
    hkOArchive::write8u(v4, 0);
    hkOArchive::writeFloat32(v4, t);
    v5 = hkOArchive::getStreamWriter(v4);
    v5->vfptr[2].__first_virtual_table_function__((hkBaseObject *)&v5->vfptr);
  }
}

// File Line: 337
// RVA: 0xE75F70
void __fastcall hkVisualDebugger::step(hkVisualDebugger *this, float frameTimeInMs)
{
  float v2; // xmm6_4
  hkVisualDebugger *v3; // rbx
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rcx
  int v8; // edi
  signed __int64 v9; // rsi
  hkVisualDebuggerClient *v10; // rbp
  unsigned __int64 v11; // rax
  hkErrStream v12; // [rsp+20h] [rbp-248h]
  char buf; // [rsp+40h] [rbp-228h]

  v2 = FLOAT_16_0;
  v3 = this;
  if ( this->m_amTimingFrame.m_bool )
  {
    v4 = this->m_frameTimer.m_ticks_total;
    if ( this->m_frameTimer.m_running_flag.m_bool )
      v4 += hkStopwatch::getTickCounter() - this->m_frameTimer.m_ticks_at_start;
    v5 = hkStopwatch::getTicksPerSecond();
    v2 = hkStopwatch::divide64(v4, v5) * 1000.0;
    v6 = hkStopwatch::getTickCounter();
    v3->m_frameTimer.m_running_flag.m_bool = 0;
    v7 = v6 - v3->m_frameTimer.m_ticks_at_start;
    v3->m_frameTimer.m_split_total += v6 - v3->m_frameTimer.m_ticks_at_split;
    v3->m_frameTimer.m_ticks_total += v7;
    ++v3->m_frameTimer.m_num_timings;
  }
  v3->m_amTimingFrame.m_bool = 1;
  if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(frameTimeInMs)) >> 1) > 0.00000011920929
    || !v3->m_overrideFrameTimeIfZero.m_bool )
  {
    v2 = frameTimeInMs;
  }
  ((void (__fastcall *)(hkVisualDebugger *))v3->vfptr[2].__vecDelDtor)(v3);
  v8 = v3->m_clients.m_size - 1;
  if ( v8 >= 0 )
  {
    v9 = v8;
    do
    {
      v10 = v3->m_clients.m_data;
      if ( v10[v9].m_processHandler->vfptr->isOk((hkProcess *)&v10[v9].m_processHandler->vfptr) )
      {
        ((void (__fastcall *)(hkProcessVtbl **))v10[v9].m_processHandler->vfptr->step)(&v10[v9].m_processHandler->vfptr);
        hkVisualDebugger::writeStep(v3, v8, v2);
      }
      if ( !v10[v9].m_processHandler->vfptr->isOk((hkProcess *)&v10[v9].m_processHandler->vfptr) )
      {
        ((void (__fastcall *)(hkError *, signed __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
          hkSingleton<hkError>::s_instance,
          1994630722i64,
          "Client Dies");
        hkErrStream::hkErrStream(&v12, &buf, 512);
        hkOstream::operator<<(
          (hkOstream *)&v12.vfptr,
          "Client has died, cleaning up (host name not available at present)");
        hkError::messageReport(-1, &buf, "hkVisualDebugger.cpp", 368);
        hkOstream::~hkOstream((hkOstream *)&v12.vfptr);
        ((void (*)(void))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)();
        hkVisualDebugger::deleteClient(v3, v8);
      }
      --v9;
      --v8;
    }
    while ( v8 >= 0 );
  }
  if ( v3->m_amTimingFrame.m_bool )
  {
    v3->m_frameTimer.m_ticks_at_start = 0i64;
    v3->m_frameTimer.m_ticks_total = 0i64;
    v3->m_frameTimer.m_ticks_at_split = 0i64;
    v3->m_frameTimer.m_split_total = 0i64;
    v3->m_frameTimer.m_num_timings = 0;
    v3->m_frameTimer.m_running_flag.m_bool = 1;
    v11 = hkStopwatch::getTickCounter();
    v3->m_frameTimer.m_ticks_at_start = v11;
    v3->m_frameTimer.m_ticks_at_split = v11;
  }
}

// File Line: 382
// RVA: 0xE758A0
void __fastcall hkVisualDebugger::clearDefaultAndRequiredProcesses(hkVisualDebugger *this)
{
  hkVisualDebugger *v1; // rsi
  hkStringPtr *v2; // rcx
  int v3; // ebx
  hkStringPtr *v4; // rdi
  int v5; // ebx
  hkStringPtr *v6; // rdi

  v1 = this;
  v2 = this->m_defaultProcesses.m_data;
  v3 = v1->m_defaultProcesses.m_size - 1;
  if ( v3 >= 0 )
  {
    v4 = &v2[v3];
    do
    {
      hkStringPtr::~hkStringPtr(v4);
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  v1->m_defaultProcesses.m_size = 0;
  v5 = v1->m_requiredProcesses.m_size - 1;
  if ( v5 >= 0 )
  {
    v6 = &v1->m_requiredProcesses.m_data[v5];
    do
    {
      hkStringPtr::~hkStringPtr(v6);
      --v6;
      --v5;
    }
    while ( v5 >= 0 );
  }
  v1->m_requiredProcesses.m_size = 0;
}

// File Line: 388
// RVA: 0xE75930
void __fastcall hkVisualDebugger::addDefaultProcess(hkVisualDebugger *this, const char *processName)
{
  signed int *v2; // rbx
  const char *v3; // rdi
  hkStringPtr *v4; // rcx
  __int64 v5; // rdx
  hkStringPtr *v6; // rcx

  v2 = (signed int *)&this->m_defaultProcesses;
  v3 = processName;
  if ( this->m_defaultProcesses.m_size == (this->m_defaultProcesses.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v4 = (hkStringPtr *)(*(_QWORD *)v2 + 8i64 * v2[2]);
  if ( v4 )
    hkStringPtr::hkStringPtr(v4);
  v5 = v2[2];
  v6 = (hkStringPtr *)(*(_QWORD *)v2 + 8 * v5);
  v2[2] = v5 + 1;
  hkStringPtr::operator=(v6, v3);
}

// File Line: 393
// RVA: 0xE759B0
void __fastcall hkVisualDebugger::removeDefaultProcess(hkVisualDebugger *this, const char *processName)
{
  int v2; // edi
  const char *v3; // rbp
  hkVisualDebugger *v4; // rsi
  __int64 v5; // rbx
  hkOstream *v6; // rax
  hkOstream *v7; // rax
  signed __int64 v8; // rbx
  hkStringPtr *v9; // rax
  int v10; // ecx
  __int64 v11; // rdx
  const char *v12; // rcx
  hkErrStream v13; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v2 = 0;
  v3 = processName;
  v4 = this;
  if ( this->m_defaultProcesses.m_size <= 0 )
  {
LABEL_5:
    ((void (__fastcall *)(hkError *, signed __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
      hkSingleton<hkError>::s_instance,
      1985369172i64,
      "removeDefaultProcess");
    hkErrStream::hkErrStream(&v13, &buf, 512);
    v6 = hkOstream::operator<<((hkOstream *)&v13.vfptr, "The default Process");
    v7 = hkOstream::operator<<(v6, v3);
    hkOstream::operator<<(v7, ", cannot not be removed from the default process list as it cannot be found!");
    hkError::messageReport(-1, &buf, "hkVisualDebugger.cpp", 406);
    hkOstream::~hkOstream((hkOstream *)&v13.vfptr);
    ((void (*)(void))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)();
  }
  else
  {
    v5 = 0i64;
    while ( (unsigned int)hkString::strCmp(
                            (const char *)((_QWORD)v4->m_defaultProcesses.m_data[v5].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                            v3) )
    {
      ++v2;
      ++v5;
      if ( v2 >= v4->m_defaultProcesses.m_size )
        goto LABEL_5;
    }
    v8 = v2;
    hkStringPtr::~hkStringPtr(&v4->m_defaultProcesses.m_data[v8]);
    --v4->m_defaultProcesses.m_size;
    v9 = &v4->m_defaultProcesses.m_data[v8];
    v10 = 8 * (v4->m_defaultProcesses.m_size - v2);
    if ( v10 > 0 )
    {
      v11 = ((unsigned int)(v10 - 1) >> 3) + 1;
      do
      {
        v12 = v9[1].m_stringAndFlag;
        ++v9;
        v9[-1].m_stringAndFlag = v12;
        --v11;
      }
      while ( v11 );
    }
  }
}

// File Line: 411
// RVA: 0xE75B10
void __fastcall hkVisualDebugger::addRequiredProcess(hkVisualDebugger *this, const char *processName)
{
  signed int *v2; // rbx
  const char *v3; // rdi
  hkStringPtr *v4; // rcx
  __int64 v5; // rdx
  hkStringPtr *v6; // rcx

  v2 = (signed int *)&this->m_requiredProcesses;
  v3 = processName;
  if ( this->m_requiredProcesses.m_size == (this->m_requiredProcesses.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v4 = (hkStringPtr *)(*(_QWORD *)v2 + 8i64 * v2[2]);
  if ( v4 )
    hkStringPtr::hkStringPtr(v4);
  v5 = v2[2];
  v6 = (hkStringPtr *)(*(_QWORD *)v2 + 8 * v5);
  v2[2] = v5 + 1;
  hkStringPtr::operator=(v6, v3);
}

// File Line: 416
// RVA: 0xE75B90
void __fastcall hkVisualDebugger::addTrackedObject(hkVisualDebugger *this, void *obj, hkClass *klass, const char *group, unsigned __int64 tagId)
{
  hkClass *v5; // rbp
  void *v6; // r14
  hkVisualDebugger *v7; // rdi
  __int64 v8; // rdx
  int v9; // esi
  hkVisualDebuggerTrackedObject *v10; // r8
  __int64 v11; // rbx

  v5 = klass;
  v6 = obj;
  v7 = this;
  if ( this->m_trackedObjects.m_size == (this->m_trackedObjects.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_trackedObjects,
      24);
  v8 = v7->m_trackedObjects.m_size;
  v9 = 0;
  v10 = &v7->m_trackedObjects.m_data[v8];
  v7->m_trackedObjects.m_size = v8 + 1;
  v10->m_ptr = v6;
  v10->m_class = v5;
  v10->m_tag = tagId;
  if ( v7->m_trackCallbacks.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      LOBYTE(v10) = 1;
      ((void (__fastcall *)(void *, hkClass *, hkVisualDebuggerTrackedObject *, unsigned __int64, void *))v7->m_trackCallbacks.m_data[v11])(
        v6,
        v5,
        v10,
        tagId,
        v7->m_trackCallbackHandles.m_data[v11]);
      ++v9;
      ++v11;
    }
    while ( v9 < v7->m_trackCallbacks.m_size );
  }
}

// File Line: 428
// RVA: 0xE75C60
void __fastcall hkVisualDebugger::removeTrackedObject(hkVisualDebugger *this, void *obj)
{
  int v2; // esi
  hkVisualDebugger *v3; // rbx
  void *v4; // rbp
  __int64 v5; // rdx
  int v6; // er8
  __int64 v7; // rcx
  hkVisualDebuggerTrackedObject *v8; // rax
  __int64 v9; // rax
  hkVisualDebuggerTrackedObject *v10; // rdx
  signed __int64 v11; // r9
  signed __int64 v12; // rax
  signed __int64 v13; // rdx
  signed __int64 v14; // r9
  __int64 v15; // rcx
  __int64 v16; // rdi

  v2 = 0;
  v3 = this;
  v4 = obj;
  v5 = this->m_trackedObjects.m_size;
  v6 = 0;
  v7 = 0i64;
  if ( v5 > 0 )
  {
    v8 = v3->m_trackedObjects.m_data;
    while ( v8->m_ptr != v4 )
    {
      ++v7;
      ++v6;
      ++v8;
      if ( v7 >= v5 )
        return;
    }
    v9 = --v3->m_trackedObjects.m_size;
    if ( (_DWORD)v9 != v6 )
    {
      v10 = v3->m_trackedObjects.m_data;
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
    if ( v3->m_trackCallbacks.m_size > 0 )
    {
      v16 = 0i64;
      do
      {
        ((void (__fastcall *)(void *, _QWORD, _QWORD, _QWORD, void *))v3->m_trackCallbacks.m_data[v16])(
          v4,
          0i64,
          0i64,
          0i64,
          v3->m_trackCallbackHandles.m_data[v16]);
        ++v2;
        ++v16;
      }
      while ( v2 < v3->m_trackCallbacks.m_size );
    }
  }
}

// File Line: 444
// RVA: 0xE76830
void __fastcall hkVisualDebugger::addTrackedObjectCallback(hkVisualDebugger *this, void (__fastcall *callback)(void *, hkClass *, hkBool, unsigned __int64, void *), void *userHandle)
{
  void *v3; // rsi
  void (__fastcall *v4)(void *, hkClass *, hkBool, unsigned __int64, void *); // rbp
  hkVisualDebugger *v5; // rdi

  v3 = userHandle;
  v4 = callback;
  v5 = this;
  if ( this->m_trackCallbacks.m_size == (this->m_trackCallbacks.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &this->m_trackCallbacks, 8);
  v5->m_trackCallbacks.m_data[v5->m_trackCallbacks.m_size++] = v4;
  if ( v5->m_trackCallbackHandles.m_size == (v5->m_trackCallbackHandles.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v5->m_trackCallbackHandles,
      8);
  v5->m_trackCallbackHandles.m_data[v5->m_trackCallbackHandles.m_size++] = v3;
}

// File Line: 450
// RVA: 0xE768D0
void __fastcall hkVisualDebugger::removeTrackedObjectCallback(hkVisualDebugger *this, void (__fastcall *callback)(void *, hkClass *, hkBool, unsigned __int64, void *))
{
  __int64 v2; // r11
  int v3; // er8
  __int64 v4; // r9
  void (__fastcall **v5)(void *, hkClass *, hkBool, unsigned __int64, void *); // rax
  __int64 v6; // rax

  v2 = this->m_trackCallbacks.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( (signed int)v2 > 0 )
  {
    v5 = this->m_trackCallbacks.m_data;
    while ( *v5 != callback )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        return;
    }
    if ( v3 >= 0 )
    {
      this->m_trackCallbacks.m_size = v2 - 1;
      if ( (_DWORD)v2 - 1 != v3 )
        this->m_trackCallbacks.m_data[v3] = this->m_trackCallbacks.m_data[(signed int)v2 - 1];
      v6 = --this->m_trackCallbackHandles.m_size;
      if ( (_DWORD)v6 != v3 )
        this->m_trackCallbackHandles.m_data[v3] = this->m_trackCallbackHandles.m_data[v6];
    }
  }
}

// File Line: 460
// RVA: 0xE765B0
void __fastcall hkVisualDebugger::getCurrentProcesses(hkVisualDebugger *this, hkArray<hkProcess *,hkContainerHeapAllocator> *process)
{
  __int64 v2; // rdi
  hkArray<hkProcess *,hkContainerHeapAllocator> *v3; // rbp
  hkVisualDebugger *v4; // rsi
  __int64 v5; // rbx
  hkServerProcessHandler *v6; // r9

  v2 = this->m_clients.m_size;
  v3 = process;
  v4 = this;
  if ( v2 > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v4->m_clients.m_data[v5].m_processHandler;
      if ( v6 )
        hkArrayBase<hkpEntity *>::_insertAt(
          (hkArrayBase<hkProcess *> *)&v3->m_data,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v3->m_size,
          v6->m_processList.m_data,
          v6->m_processList.m_size);
      ++v5;
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 474
// RVA: 0xE767B0
void __fastcall hkVisualDebugger::removeContext(hkVisualDebugger *this, hkProcessContext *context)
{
  int v2; // er9
  hkVisualDebugger *v3; // r11
  __int64 v4; // rcx
  __int64 v5; // r8
  hkProcessContext **v6; // rax
  signed __int64 v7; // rax
  int v8; // edx
  __int64 v9; // rdx
  __int64 v10; // rcx

  v2 = 0;
  v3 = this;
  v4 = this->m_contexts.m_size;
  v5 = 0i64;
  if ( (signed int)v4 > 0 )
  {
    v6 = v3->m_contexts.m_data;
    while ( *v6 != context )
    {
      ++v5;
      ++v2;
      ++v6;
      if ( v5 >= v4 )
        return;
    }
    if ( v2 >= 0 )
    {
      v3->m_contexts.m_size = v4 - 1;
      v7 = (signed __int64)&v3->m_contexts.m_data[v2];
      v8 = 8 * (v4 - 1 - v2);
      if ( v8 > 0 )
      {
        v9 = ((unsigned int)(v8 - 1) >> 3) + 1;
        do
        {
          v10 = *(_QWORD *)(v7 + 8);
          v7 += 8i64;
          *(_QWORD *)(v7 - 8) = v10;
          --v9;
        }
        while ( v9 );
      }
    }
  }
}

// File Line: 483
// RVA: 0xE76640
hkProcess *__fastcall hkVisualDebugger::getCurrentProcessByName(hkVisualDebugger *this, const char *name)
{
  hkVisualDebugger *v2; // rbx
  int v3; // esi
  int v4; // ebx
  __int64 v5; // rdi
  hkProcess *v7; // rbx
  hkArray<hkProcess *,hkContainerHeapAllocator> process; // [rsp+20h] [rbp-18h]

  v2 = this;
  v3 = hkProcessFactory::getProcessId(hkSingleton<hkProcessFactory>::s_instance, name);
  if ( v3 == -1 )
    return 0i64;
  process.m_data = 0i64;
  process.m_size = 0;
  process.m_capacityAndFlags = 2147483648;
  hkVisualDebugger::getCurrentProcesses(v2, &process);
  v4 = 0;
  if ( process.m_size <= 0 )
  {
LABEL_6:
    process.m_size = 0;
    if ( process.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        process.m_data,
        8 * process.m_capacityAndFlags);
    return 0i64;
  }
  v5 = 0i64;
  while ( ((unsigned int (*)(void))process.m_data[v5]->vfptr->getProcessTag)() != v3 )
  {
    ++v4;
    ++v5;
    if ( v4 >= process.m_size )
      goto LABEL_6;
  }
  v7 = process.m_data[v4];
  process.m_size = 0;
  if ( process.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      process.m_data,
      8 * process.m_capacityAndFlags);
  return v7;
}

