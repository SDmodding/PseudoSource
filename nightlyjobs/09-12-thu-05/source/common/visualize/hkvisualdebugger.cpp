// File Line: 29
// RVA: 0xE74EB0
void __fastcall hkVisualDebugger::hkVisualDebugger(
        hkVisualDebugger *this,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts,
        hkVtableClassRegistry *reg)
{
  int v3; // ebx
  __int64 v6; // rsi
  hkVtableClassRegistry *m_classReg; // rcx
  hkErrStream v8; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkVisualDebugger::`vftable;
  v3 = 0;
  this->m_server = 0i64;
  this->s_SuppressPollForNewClients = 0;
  this->m_clients.m_data = 0i64;
  this->m_clients.m_size = 0;
  this->m_clients.m_capacityAndFlags = 0x80000000;
  this->m_contexts.m_data = 0i64;
  this->m_contexts.m_size = 0;
  this->m_contexts.m_capacityAndFlags = 0x80000000;
  this->m_trackedObjects.m_data = 0i64;
  this->m_trackedObjects.m_size = 0;
  this->m_trackedObjects.m_capacityAndFlags = 0x80000000;
  this->m_trackCallbacks.m_data = 0i64;
  this->m_trackCallbacks.m_size = 0;
  this->m_trackCallbacks.m_capacityAndFlags = 0x80000000;
  this->m_trackCallbackHandles.m_data = 0i64;
  this->m_trackCallbackHandles.m_size = 0;
  this->m_trackCallbackHandles.m_capacityAndFlags = 0x80000000;
  this->m_classReg = reg;
  this->m_defaultProcesses.m_data = 0i64;
  this->m_defaultProcesses.m_size = 0;
  this->m_defaultProcesses.m_capacityAndFlags = 0x80000000;
  this->m_requiredProcesses.m_data = 0i64;
  this->m_requiredProcesses.m_size = 0;
  this->m_requiredProcesses.m_capacityAndFlags = 0x80000000;
  this->m_amTimingFrame.m_bool = 0;
  this->m_frameTimer.m_name = "Frame Timer";
  this->m_frameTimer.m_ticks_at_start = 0i64;
  this->m_frameTimer.m_ticks_total = 0i64;
  this->m_frameTimer.m_ticks_at_split = 0i64;
  this->m_frameTimer.m_split_total = 0i64;
  this->m_frameTimer.m_running_flag.m_bool = 0;
  this->m_frameTimer.m_num_timings = 0;
  this->m_overrideFrameTimeIfZero.m_bool = 1;
  if ( contexts->m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      hkVisualDebugger::addContext(this, contexts->m_data[v6]);
      ++v3;
      ++v6;
    }
    while ( v3 < contexts->m_size );
  }
  ((void (__fastcall *)(hkError *, __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    311668207i64,
    "Visual Debugger");
  hkErrStream::hkErrStream(&v8, buf, 512);
  hkOstream::operator<<(&v8, "VDB Server instance has been created");
  hkError::messageReport(0xFFFFFFFF, buf, "hkVisualDebugger.cpp", 37);
  hkOstream::~hkOstream(&v8);
  hkProcessRegisterUtil::registerAllCommonProcesses();
  hkVisualDebugger::addDefaultProcess(this, "Debug Display");
  hkVisualDebugger::addDefaultProcess(this, "Shapes");
  hkVisualDebugger::addDefaultProcess(this, "Mouse Picking");
  hkVisualDebugger::addDefaultProcess(this, "RemoteObject");
  m_classReg = this->m_classReg;
  if ( m_classReg )
    hkReferencedObject::addReference(m_classReg);
  ((void (__fastcall *)(hkError *))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)(hkSingleton<hkError>::s_instance);
}

// File Line: 52
// RVA: 0xE762D0
void __fastcall hkVisualDebugger::~hkVisualDebugger(hkVisualDebugger *this)
{
  int v2; // esi
  __int64 v3; // rdi
  int v4; // edi
  hkStringPtr *v5; // rsi
  int v6; // edi
  hkStringPtr *v7; // rsi
  hkVtableClassRegistry *m_classReg; // rcx
  int v9; // edi
  hkStringPtr *v10; // rsi
  int m_capacityAndFlags; // r8d
  int v12; // edi
  hkStringPtr *v13; // rsi
  int v14; // r8d
  int v15; // r8d
  int v16; // r8d
  int v17; // eax
  int v18; // r8d
  int v19; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkVisualDebugger::`vftable;
  hkVisualDebugger::shutdown(this);
  v2 = 0;
  if ( this->m_contexts.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      this->m_contexts.m_data[v3]->vfptr->setOwner(this->m_contexts.m_data[v3], 0i64);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_contexts.m_size );
  }
  v4 = this->m_defaultProcesses.m_size - 1;
  if ( v4 >= 0 )
  {
    v5 = &this->m_defaultProcesses.m_data[v4];
    do
    {
      hkStringPtr::~hkStringPtr(v5--);
      --v4;
    }
    while ( v4 >= 0 );
  }
  this->m_defaultProcesses.m_size = 0;
  v6 = this->m_requiredProcesses.m_size - 1;
  if ( v6 >= 0 )
  {
    v7 = &this->m_requiredProcesses.m_data[v6];
    do
    {
      hkStringPtr::~hkStringPtr(v7--);
      --v6;
    }
    while ( v6 >= 0 );
  }
  this->m_requiredProcesses.m_size = 0;
  m_classReg = this->m_classReg;
  if ( m_classReg )
    hkReferencedObject::removeReference(m_classReg);
  v9 = this->m_requiredProcesses.m_size - 1;
  if ( v9 >= 0 )
  {
    v10 = &this->m_requiredProcesses.m_data[v9];
    do
    {
      hkStringPtr::~hkStringPtr(v10--);
      --v9;
    }
    while ( v9 >= 0 );
  }
  m_capacityAndFlags = this->m_requiredProcesses.m_capacityAndFlags;
  this->m_requiredProcesses.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_requiredProcesses.m_data,
      8 * m_capacityAndFlags);
  this->m_requiredProcesses.m_data = 0i64;
  this->m_requiredProcesses.m_capacityAndFlags = 0x80000000;
  v12 = this->m_defaultProcesses.m_size - 1;
  if ( v12 >= 0 )
  {
    v13 = &this->m_defaultProcesses.m_data[v12];
    do
    {
      hkStringPtr::~hkStringPtr(v13--);
      --v12;
    }
    while ( v12 >= 0 );
  }
  v14 = this->m_defaultProcesses.m_capacityAndFlags;
  this->m_defaultProcesses.m_size = 0;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_defaultProcesses.m_data,
      8 * v14);
  this->m_defaultProcesses.m_data = 0i64;
  this->m_defaultProcesses.m_capacityAndFlags = 0x80000000;
  v15 = this->m_trackCallbackHandles.m_capacityAndFlags;
  this->m_trackCallbackHandles.m_size = 0;
  if ( v15 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_trackCallbackHandles.m_data,
      8 * v15);
  this->m_trackCallbackHandles.m_data = 0i64;
  this->m_trackCallbackHandles.m_capacityAndFlags = 0x80000000;
  v16 = this->m_trackCallbacks.m_capacityAndFlags;
  this->m_trackCallbacks.m_size = 0;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_trackCallbacks.m_data,
      8 * v16);
  this->m_trackCallbacks.m_data = 0i64;
  this->m_trackCallbacks.m_capacityAndFlags = 0x80000000;
  v17 = this->m_trackedObjects.m_capacityAndFlags;
  this->m_trackedObjects.m_size = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_trackedObjects.m_data,
      24 * (v17 & 0x3FFFFFFF));
  this->m_trackedObjects.m_data = 0i64;
  this->m_trackedObjects.m_capacityAndFlags = 0x80000000;
  v18 = this->m_contexts.m_capacityAndFlags;
  this->m_contexts.m_size = 0;
  if ( v18 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_contexts.m_data,
      8 * v18);
  this->m_contexts.m_data = 0i64;
  this->m_contexts.m_capacityAndFlags = 0x80000000;
  v19 = this->m_clients.m_capacityAndFlags;
  this->m_clients.m_size = 0;
  if ( v19 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_clients.m_data,
      16 * v19);
  this->m_clients.m_data = 0i64;
  this->m_clients.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 69
// RVA: 0xE76750
void __fastcall hkVisualDebugger::addContext(hkVisualDebugger *this, hkProcessContext *context)
{
  context->vfptr->setOwner(context, this);
  if ( this->m_contexts.m_size == (this->m_contexts.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_contexts.m_data, 8);
  this->m_contexts.m_data[this->m_contexts.m_size++] = context;
}

// File Line: 76
// RVA: 0xE75780
void __fastcall hkVisualDebugger::shutdown(hkVisualDebugger *this)
{
  int i; // ebx
  hkSocket *m_server; // rcx
  hkErrStream v4; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  ((void (__fastcall *)(hkError *, __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    311668207i64,
    "Shutting down Visual Debugger..");
  for ( i = this->m_clients.m_size - 1; i >= 0; --i )
  {
    hkVisualDebugger::writeStep(this, i, 0.0);
    hkVisualDebugger::deleteClient(this, i);
    hkErrStream::hkErrStream(&v4, buf, 512);
    hkOstream::operator<<(&v4, "Client deleted.");
    hkError::messageReport(0xFFFFFFFF, buf, "hkVisualDebugger.cpp", 86);
    hkOstream::~hkOstream(&v4);
  }
  m_server = this->m_server;
  if ( m_server )
  {
    m_server->vfptr->__vecDelDtor(m_server, 1u);
    this->m_server = 0i64;
    hkErrStream::hkErrStream(&v4, buf, 512);
    hkOstream::operator<<(&v4, "Server deleted.");
    hkError::messageReport(0xFFFFFFFF, buf, "hkVisualDebugger.cpp", 93);
    hkOstream::~hkOstream(&v4);
  }
  ((void (__fastcall *)(hkError *))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)(hkSingleton<hkError>::s_instance);
}

// File Line: 99
// RVA: 0xE750C0
void __fastcall hkVisualDebugger::serve(hkVisualDebugger *this, unsigned int listenPort)
{
  hkSocket *v4; // rax
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  int v7; // r9d
  hkErrStream v8; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF
  char v10; // [rsp+250h] [rbp+8h] BYREF

  ((void (__fastcall *)(hkError *, __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    311668200i64,
    "Serving");
  if ( this->m_server )
  {
    hkErrStream::hkErrStream(&v8, buf, 512);
    hkOstream::operator<<(&v8, "Server has already been created, only one server allowed per visual debugger instance");
    v7 = 127;
    goto LABEL_8;
  }
  v4 = hkSocket::create();
  this->m_server = v4;
  if ( !v4 )
    goto LABEL_6;
  if ( *(_DWORD *)((__int64 (__fastcall *)(hkSocket *, char *, _QWORD))v4->vfptr[4].__vecDelDtor)(v4, &v10, listenPort) )
  {
    hkReferencedObject::removeReference(this->m_server);
    this->m_server = 0i64;
LABEL_6:
    hkErrStream::hkErrStream(&v8, buf, 512);
    hkOstream::operator<<(
      &v8,
      "Server could not be created, please check that you platform supports sockets with the hkBase library");
    v7 = 122;
    goto LABEL_8;
  }
  hkErrStream::hkErrStream(&v8, buf, 512);
  v5 = hkOstream::operator<<(&v8, "Server created and will poll for new client(s) on port ");
  v6 = hkOstream::operator<<(v5, listenPort);
  hkOstream::operator<<(v6, " every frame");
  v7 = 111;
LABEL_8:
  hkError::messageReport(0xFFFFFFFF, buf, "hkVisualDebugger.cpp", v7);
  hkOstream::~hkOstream(&v8);
  ((void (__fastcall *)(hkError *))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)(hkSingleton<hkError>::s_instance);
}

// File Line: 134
// RVA: 0xE75D50
void __fastcall hkVisualDebugger::createRequiredAndDefaultProcessList(
        hkVisualDebugger *this,
        hkVisualDebuggerClient *vdbClient,
        hkStringBuf *viewerNames)
{
  hkStringBuf *v5; // r12
  __int64 v6; // rbx
  int v7; // edi
  int v8; // ebp
  int v9; // r15d
  __int64 v10; // r14
  __int64 m_size; // rbp
  hkStringPtr *m_data; // r12
  int v13; // edi
  unsigned __int64 v14; // rax
  int v15; // eax
  int v16; // [rsp+80h] [rbp+8h] BYREF
  hkStringBuf *v17; // [rsp+90h] [rbp+18h]
  char v18; // [rsp+98h] [rbp+20h] BYREF

  v17 = viewerNames;
  v5 = viewerNames;
  hkStringBuf::operator=(viewerNames, "Turning on the following viewers: [");
  v6 = 0i64;
  v7 = 0;
  if ( this->m_requiredProcesses.m_size > 0 )
  {
    do
    {
      v8 = vdbClient->m_processHandler->vfptr->getProcessId(
             &vdbClient->m_processHandler->hkProcessHandler,
             (const char *)(*(unsigned __int64 *)((_BYTE *)&this->m_requiredProcesses.m_data->m_stringAndFlag + v6) & 0xFFFFFFFFFFFFFFFEui64));
      if ( v8 >= 0 )
      {
        hkStringBuf::appendJoin(
          v5,
          " ",
          (const char *)(*(unsigned __int64 *)((_BYTE *)&this->m_requiredProcesses.m_data->m_stringAndFlag + v6) & 0xFFFFFFFFFFFFFFFEui64),
          0i64,
          0i64,
          0i64,
          0i64);
        vdbClient->m_processHandler->vfptr->createProcess(
          &vdbClient->m_processHandler->hkProcessHandler,
          (hkResult *)&v16,
          v8);
      }
      ++v7;
      v6 += 8i64;
    }
    while ( v7 < this->m_requiredProcesses.m_size );
    v6 = 0i64;
  }
  v9 = 0;
  if ( this->m_defaultProcesses.m_size <= 0 )
    goto LABEL_21;
  v10 = 0i64;
  do
  {
    v16 = vdbClient->m_processHandler->vfptr->getProcessId(
            &vdbClient->m_processHandler->hkProcessHandler,
            (const char *)((unsigned __int64)this->m_defaultProcesses.m_data[v10].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
    if ( v16 < 0 )
      goto LABEL_20;
    m_size = this->m_requiredProcesses.m_size;
    m_data = this->m_defaultProcesses.m_data;
    v13 = 0;
    if ( m_size <= 0 )
      goto LABEL_18;
    while ( 1 )
    {
      v14 = (unsigned __int64)m_data[v10].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64;
      if ( ((unsigned __int64)this->m_requiredProcesses.m_data[v6].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64) == 0 )
        break;
      if ( v14 )
      {
        v15 = hkString::strCmp(
                (const char *)((unsigned __int64)this->m_requiredProcesses.m_data[v6].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                (const char *)((unsigned __int64)m_data[v10].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
        goto LABEL_14;
      }
LABEL_15:
      ++v6;
      ++v13;
      if ( v6 >= m_size )
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
        (const char *)((unsigned __int64)this->m_defaultProcesses.m_data[v10].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
        0i64,
        0i64,
        0i64,
        0i64);
      vdbClient->m_processHandler->vfptr->createProcess(
        &vdbClient->m_processHandler->hkProcessHandler,
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
  while ( v9 < this->m_defaultProcesses.m_size );
LABEL_21:
  hkStringBuf::operator+=(v5, "]");
}

// File Line: 165
// RVA: 0xE75220
void __fastcall hkVisualDebugger::capture(hkVisualDebugger *this, const char *captureFilename)
{
  hkStreamWriter *v4; // rbx
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  int v7; // eax
  hkOstream *v8; // rax
  hkOstream *v9; // rax
  hkErrStream v10; // [rsp+20h] [rbp-E0h] BYREF
  hkStringBuf viewerNames; // [rsp+40h] [rbp-C0h] BYREF
  char buf[528]; // [rsp+D0h] [rbp-30h] BYREF
  char v13; // [rsp+300h] [rbp+200h] BYREF
  char v14; // [rsp+308h] [rbp+208h] BYREF

  ((void (__fastcall *)(hkError *, __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    311668199i64,
    "Capturing");
  v4 = *(hkStreamWriter **)((__int64 (__fastcall *)(hkFileSystem *, char *, const char *, __int64))hkSingleton<hkFileSystem>::s_instance->vfptr[2].__vecDelDtor)(
                             hkSingleton<hkFileSystem>::s_instance,
                             &v14,
                             captureFilename,
                             3i64);
  if ( v4
    && *(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, char *))v4->vfptr[1].__first_virtual_table_function__)(
                   v4,
                   &v13) )
  {
    hkErrStream::hkErrStream(&v10, buf, 512);
    v5 = hkOstream::operator<<(&v10, "Capturing simulation state to ");
    v6 = hkOstream::operator<<(v5, captureFilename);
    hkOstream::operator<<(v6, "");
    hkError::messageReport(0xFFFFFFFF, buf, "hkVisualDebugger.cpp", 171);
    hkOstream::~hkOstream(&v10);
    hkVisualDebugger::createClient(this, 0i64, 0i64, v4);
    v7 = this->m_clients.m_size - 1;
    viewerNames.m_string.m_capacityAndFlags = -2147483520;
    viewerNames.m_string.m_size = 1;
    viewerNames.m_string.m_data = viewerNames.m_string.m_storage;
    viewerNames.m_string.m_storage[0] = 0;
    hkVisualDebugger::createRequiredAndDefaultProcessList(this, &this->m_clients.m_data[v7], &viewerNames);
    hkErrStream::hkErrStream(&v10, buf, 512);
    hkOstream::operator<<(&v10, viewerNames.m_string.m_data);
    hkError::messageReport(0xFFFFFFFF, buf, "hkVisualDebugger.cpp", 182);
    hkOstream::~hkOstream(&v10);
    viewerNames.m_string.m_size = 0;
    if ( viewerNames.m_string.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        viewerNames.m_string.m_data,
        viewerNames.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  }
  else
  {
    hkErrStream::hkErrStream(&v10, buf, 512);
    v8 = hkOstream::operator<<(&v10, "Capture file ");
    v9 = hkOstream::operator<<(v8, captureFilename);
    hkOstream::operator<<(v9, " could not be opened for writing");
    hkError::messageReport(0xFFFFFFFF, buf, "hkVisualDebugger.cpp", 186);
    hkOstream::~hkOstream(&v10);
  }
  ((void (__fastcall *)(hkError *))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)(hkSingleton<hkError>::s_instance);
  if ( v4 )
    hkReferencedObject::removeReference(v4);
}

// File Line: 193
// RVA: 0xE75460
void __fastcall hkVisualDebugger::capture(
        hkVisualDebugger *this,
        hkMemoryTrack *outgoingMemory,
        hkMemoryTrack *incommingMemory)
{
  _QWORD **Value; // rax
  __int64 v7; // rax
  hkStreamWriter *v8; // rbx
  _QWORD **v9; // rax
  hkMemoryTrackStreamReader *v10; // rax
  hkStreamReader *v11; // rax
  hkStreamReader *v12; // rdi
  int v13; // eax
  hkVisualDebuggerClient *v14; // rbx
  hkStreamWriter *StreamWriter; // rax
  hkErrStream v16; // [rsp+20h] [rbp-E0h] BYREF
  hkStringBuf viewerNames; // [rsp+40h] [rbp-C0h] BYREF
  char buf[512]; // [rsp+D0h] [rbp-30h] BYREF
  char v19; // [rsp+308h] [rbp+208h] BYREF

  ((void (__fastcall *)(hkError *, __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    3200188100i64,
    "Capturing to memory stream");
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
  v8 = (hkStreamWriter *)v7;
  if ( v7 )
  {
    *(_DWORD *)(v7 + 8) = 0x1FFFF;
    *(_QWORD *)(v7 + 16) = outgoingMemory;
    *(_QWORD *)v7 = &hkMemoryTrackStreamWriter::`vftable;
    *(_DWORD *)(v7 + 24) = 1;
  }
  else
  {
    v8 = 0i64;
  }
  v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkMemoryTrackStreamReader *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v9[11] + 8i64))(v9[11], 40i64);
  if ( v10 )
  {
    hkMemoryTrackStreamReader::hkMemoryTrackStreamReader(v10, incommingMemory, MEMORY_INPLACE, 1);
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
    hkErrStream::hkErrStream(&v16, buf, 512);
    hkOstream::operator<<(&v16, "Capturing simulation state to memory stream.");
    hkError::messageReport(0xFFFFFFFF, buf, "hkVisualDebugger.cpp", 200);
    hkOstream::~hkOstream(&v16);
    hkVisualDebugger::createClient(this, 0i64, v12, v8);
    hkReferencedObject::removeReference(v8);
    hkReferencedObject::removeReference(v12);
    v13 = this->m_clients.m_size - 1;
    viewerNames.m_string.m_capacityAndFlags = -2147483520;
    viewerNames.m_string.m_size = 1;
    viewerNames.m_string.m_data = viewerNames.m_string.m_storage;
    viewerNames.m_string.m_storage[0] = 0;
    v14 = &this->m_clients.m_data[v13];
    hkVisualDebugger::createRequiredAndDefaultProcessList(this, v14, &viewerNames);
    hkErrStream::hkErrStream(&v16, buf, 512);
    hkOstream::operator<<(&v16, viewerNames.m_string.m_data);
    hkError::messageReport(0xFFFFFFFF, buf, "hkVisualDebugger.cpp", 213);
    hkOstream::~hkOstream(&v16);
    StreamWriter = hkOArchive::getStreamWriter(v14->m_processHandler->m_outStream);
    StreamWriter->vfptr[2].__first_virtual_table_function__(StreamWriter);
    viewerNames.m_string.m_size = 0;
    if ( viewerNames.m_string.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        viewerNames.m_string.m_data,
        viewerNames.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  }
  else
  {
    hkErrStream::hkErrStream(&v16, buf, 512);
    hkOstream::operator<<(&v16, "Could not create memory stream for writing.");
    hkError::messageReport(0xFFFFFFFF, buf, "hkVisualDebugger.cpp", 220);
    hkOstream::~hkOstream(&v16);
  }
  ((void (__fastcall *)(hkError *))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)(hkSingleton<hkError>::s_instance);
}

// File Line: 227
// RVA: 0xE75720
void __fastcall hkVisualDebugger::endCapture(hkVisualDebugger *this)
{
  int v2; // ebx
  __int64 v3; // rdi

  v2 = this->m_clients.m_size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      if ( !this->m_clients.m_data[v3].m_socket )
        hkVisualDebugger::deleteClient(this, v2);
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
  hkVisualDebuggerClient *m_data; // rsi
  __int64 v5; // rdi
  hkReferencedObject *m_processHandler; // rcx
  hkReferencedObject *m_socket; // rcx
  __int64 v8; // rcx
  hkVisualDebuggerClient *v9; // rax
  __int64 v10; // rdx
  hkVisualDebuggerClient *v11; // r8
  hkVisualDebuggerClient *v12; // rax
  signed __int64 v13; // r8
  hkServerProcessHandler *v14; // rcx

  m_data = this->m_clients.m_data;
  v5 = i;
  m_processHandler = m_data[v5].m_processHandler;
  if ( m_processHandler )
    hkReferencedObject::removeReference(m_processHandler);
  m_socket = m_data[v5].m_socket;
  if ( m_socket )
    hkReferencedObject::removeReference(m_socket);
  v8 = --this->m_clients.m_size;
  if ( (_DWORD)v8 != i )
  {
    v9 = this->m_clients.m_data;
    v10 = 2i64;
    v11 = &v9[v8];
    v12 = &v9[v5];
    v13 = (char *)v11 - (char *)v12;
    do
    {
      v14 = *(hkServerProcessHandler **)((char *)&v12->m_socket + v13);
      v12 = (hkVisualDebuggerClient *)((char *)v12 + 8);
      v12[-1].m_processHandler = v14;
      --v10;
    }
    while ( v10 );
  }
}

// File Line: 254
// RVA: 0xE76A00
void __fastcall hkVisualDebugger::createClient(
        hkVisualDebugger *this,
        hkSocket *socket,
        hkStreamReader *reader,
        hkStreamWriter *writer)
{
  __int64 m_size; // rbp
  int v9; // r9d
  int v10; // eax
  int v11; // eax
  hkVisualDebuggerClient *v12; // r13
  _QWORD **Value; // rax
  hkServerProcessHandler *v14; // rax
  int v15; // ebx
  __int64 v16; // rdi
  int v17; // eax
  int v18; // ebp
  int v19; // r15d
  __int64 v20; // r14
  __int64 v21; // rbp
  hkStringPtr *m_data; // r12
  int v23; // edi
  __int64 v24; // rbx
  const char *v25; // rdx
  const char *v26; // rcx
  int v27; // eax
  hkResult result; // [rsp+70h] [rbp+8h] BYREF
  hkResult v29; // [rsp+78h] [rbp+10h] BYREF
  char v30; // [rsp+88h] [rbp+20h] BYREF

  if ( writer )
  {
    hkVersionReporter::sendStructureLayout(&result, writer);
    hkVersionReporter::sendVersionInformation(&result, writer);
  }
  m_size = this->m_clients.m_size;
  v9 = m_size + 1;
  v10 = this->m_clients.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 >= (int)m_size + 1 )
  {
    result.m_enum = HK_SUCCESS;
  }
  else
  {
    v11 = 2 * v10;
    if ( v9 < v11 )
      v9 = v11;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_clients.m_data, v9, 16);
  }
  ++this->m_clients.m_size;
  v12 = &this->m_clients.m_data[m_size];
  v12->m_socket = socket;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (hkServerProcessHandler *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 144i64);
  if ( v14 )
    hkServerProcessHandler::hkServerProcessHandler(v14, &this->m_contexts, reader, writer);
  v12->m_processHandler = v14;
  hkServerProcessHandler::registerAllAvailableProcesss(v14, &v29);
  v15 = 0;
  if ( this->m_requiredProcesses.m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      v17 = v12->m_processHandler->vfptr->getProcessId(
              &v12->m_processHandler->hkProcessHandler,
              (const char *)((unsigned __int64)this->m_requiredProcesses.m_data[v16].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
      v18 = v17;
      if ( v17 >= 0 )
      {
        v12->m_processHandler->vfptr->createProcess(&v12->m_processHandler->hkProcessHandler, &v29, v17);
        v12->m_processHandler->vfptr->selectProcess(&v12->m_processHandler->hkProcessHandler, (hkResult *)&v30, v18);
      }
      ++v15;
      ++v16;
    }
    while ( v15 < this->m_requiredProcesses.m_size );
  }
  v19 = 0;
  if ( this->m_defaultProcesses.m_size <= 0 )
    goto LABEL_29;
  v20 = 0i64;
  do
  {
    v29.m_enum = v12->m_processHandler->vfptr->getProcessId(
                   &v12->m_processHandler->hkProcessHandler,
                   (const char *)((unsigned __int64)this->m_defaultProcesses.m_data[v20].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
    if ( v29.m_enum < HK_SUCCESS )
      goto LABEL_28;
    v21 = this->m_requiredProcesses.m_size;
    m_data = this->m_defaultProcesses.m_data;
    v23 = 0;
    v24 = 0i64;
    if ( v21 <= 0 )
      goto LABEL_27;
    while ( 1 )
    {
      v25 = (const char *)((unsigned __int64)m_data[v20].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
      v26 = (const char *)((unsigned __int64)this->m_requiredProcesses.m_data[v24].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
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
        &v12->m_processHandler->hkProcessHandler,
        (hkResult *)&v30,
        v29.m_enum);
LABEL_28:
    ++v19;
    ++v20;
  }
  while ( v19 < this->m_defaultProcesses.m_size );
LABEL_29:
  hkVisualDebugger::writeStep(this, this->m_clients.m_size - 1, 0.0);
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
  unsigned __int64 TickCounter; // rax
  unsigned __int64 v3; // rcx
  hkSocket *m_server; // rcx
  hkSocket *v5; // rdi
  unsigned __int64 v6; // rax
  hkErrStream v7; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  if ( !this->s_SuppressPollForNewClients )
  {
    if ( this->m_amTimingFrame.m_bool && this->m_frameTimer.m_running_flag.m_bool )
    {
      TickCounter = hkStopwatch::getTickCounter();
      this->m_frameTimer.m_running_flag.m_bool = 0;
      v3 = TickCounter - this->m_frameTimer.m_ticks_at_start;
      this->m_frameTimer.m_split_total += TickCounter - this->m_frameTimer.m_ticks_at_split;
      this->m_frameTimer.m_ticks_total += v3;
      ++this->m_frameTimer.m_num_timings;
    }
    m_server = this->m_server;
    if ( m_server )
    {
      v5 = (hkSocket *)((__int64 (*)(void))m_server->vfptr[5].__first_virtual_table_function__)();
      if ( v5 )
      {
        hkErrStream::hkErrStream(&v7, buf, 512);
        hkOstream::operator<<(&v7, "A new network client has been received (host name not available at present)");
        hkError::messageReport(0xFFFFFFFF, buf, "hkVisualDebugger.cpp", 312);
        hkOstream::~hkOstream(&v7);
        hkVisualDebugger::createClient(this, v5, &v5->m_reader, &v5->m_writer);
      }
    }
    if ( this->m_amTimingFrame.m_bool )
    {
      this->m_frameTimer.m_running_flag.m_bool = 1;
      v6 = hkStopwatch::getTickCounter();
      this->m_frameTimer.m_ticks_at_start = v6;
      this->m_frameTimer.m_ticks_at_split = v6;
    }
  }
}

// File Line: 324
// RVA: 0xE76C40
void __fastcall hkVisualDebugger::writeStep(hkVisualDebugger *this, int i, float t)
{
  hkVisualDebuggerClient *v3; // rbx
  hkOArchive *m_outStream; // rbx
  hkStreamWriter *StreamWriter; // rax

  v3 = &this->m_clients.m_data[i];
  if ( v3->m_processHandler->vfptr->isOk(&v3->m_processHandler->hkProcess) )
  {
    m_outStream = v3->m_processHandler->m_outStream;
    hkOArchive::write32u(m_outStream, 5u);
    hkOArchive::write8u(m_outStream, 0);
    hkOArchive::writeFloat32(m_outStream, t);
    StreamWriter = hkOArchive::getStreamWriter(m_outStream);
    StreamWriter->vfptr[2].__first_virtual_table_function__(StreamWriter);
  }
}

// File Line: 337
// RVA: 0xE75F70
void __fastcall hkVisualDebugger::step(hkVisualDebugger *this, float frameTimeInMs)
{
  float v2; // xmm6_4
  unsigned __int64 m_ticks_total; // rdi
  unsigned __int64 TicksPerSecond; // rax
  unsigned __int64 TickCounter; // rax
  unsigned __int64 v7; // rcx
  int v8; // edi
  __int64 v9; // rsi
  hkVisualDebuggerClient *m_data; // rbp
  unsigned __int64 v11; // rax
  hkErrStream v12; // [rsp+20h] [rbp-248h] BYREF
  char buf[512]; // [rsp+40h] [rbp-228h] BYREF

  v2 = FLOAT_16_0;
  if ( this->m_amTimingFrame.m_bool )
  {
    m_ticks_total = this->m_frameTimer.m_ticks_total;
    if ( this->m_frameTimer.m_running_flag.m_bool )
      m_ticks_total += hkStopwatch::getTickCounter() - this->m_frameTimer.m_ticks_at_start;
    TicksPerSecond = hkStopwatch::getTicksPerSecond();
    v2 = hkStopwatch::divide64(m_ticks_total, TicksPerSecond) * 1000.0;
    TickCounter = hkStopwatch::getTickCounter();
    this->m_frameTimer.m_running_flag.m_bool = 0;
    v7 = TickCounter - this->m_frameTimer.m_ticks_at_start;
    this->m_frameTimer.m_split_total += TickCounter - this->m_frameTimer.m_ticks_at_split;
    this->m_frameTimer.m_ticks_total += v7;
    ++this->m_frameTimer.m_num_timings;
  }
  this->m_amTimingFrame.m_bool = 1;
  if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(frameTimeInMs)) >> 1) > 0.00000011920929
    || !this->m_overrideFrameTimeIfZero.m_bool )
  {
    v2 = frameTimeInMs;
  }
  ((void (__fastcall *)(hkVisualDebugger *))this->vfptr[2].__vecDelDtor)(this);
  v8 = this->m_clients.m_size - 1;
  if ( v8 >= 0 )
  {
    v9 = v8;
    do
    {
      m_data = this->m_clients.m_data;
      if ( m_data[v9].m_processHandler->vfptr->isOk(&m_data[v9].m_processHandler->hkProcess) )
      {
        ((void (__fastcall *)(hkProcess *))m_data[v9].m_processHandler->vfptr->step)(&m_data[v9].m_processHandler->hkProcess);
        hkVisualDebugger::writeStep(this, v8, v2);
      }
      if ( !m_data[v9].m_processHandler->vfptr->isOk(&m_data[v9].m_processHandler->hkProcess) )
      {
        ((void (__fastcall *)(hkError *, __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
          hkSingleton<hkError>::s_instance,
          1994630722i64,
          "Client Dies");
        hkErrStream::hkErrStream(&v12, buf, 512);
        hkOstream::operator<<(&v12, "Client has died, cleaning up (host name not available at present)");
        hkError::messageReport(0xFFFFFFFF, buf, "hkVisualDebugger.cpp", 368);
        hkOstream::~hkOstream(&v12);
        ((void (__fastcall *)(hkError *))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)(hkSingleton<hkError>::s_instance);
        hkVisualDebugger::deleteClient(this, v8);
      }
      --v9;
      --v8;
    }
    while ( v8 >= 0 );
  }
  if ( this->m_amTimingFrame.m_bool )
  {
    this->m_frameTimer.m_ticks_at_start = 0i64;
    this->m_frameTimer.m_ticks_total = 0i64;
    this->m_frameTimer.m_ticks_at_split = 0i64;
    this->m_frameTimer.m_split_total = 0i64;
    this->m_frameTimer.m_num_timings = 0;
    this->m_frameTimer.m_running_flag.m_bool = 1;
    v11 = hkStopwatch::getTickCounter();
    this->m_frameTimer.m_ticks_at_start = v11;
    this->m_frameTimer.m_ticks_at_split = v11;
  }
}

// File Line: 382
// RVA: 0xE758A0
void __fastcall hkVisualDebugger::clearDefaultAndRequiredProcesses(hkVisualDebugger *this)
{
  hkStringPtr *m_data; // rcx
  int v3; // ebx
  hkStringPtr *v4; // rdi
  int v5; // ebx
  hkStringPtr *v6; // rdi

  m_data = this->m_defaultProcesses.m_data;
  v3 = this->m_defaultProcesses.m_size - 1;
  if ( v3 >= 0 )
  {
    v4 = &m_data[v3];
    do
    {
      hkStringPtr::~hkStringPtr(v4--);
      --v3;
    }
    while ( v3 >= 0 );
  }
  this->m_defaultProcesses.m_size = 0;
  v5 = this->m_requiredProcesses.m_size - 1;
  if ( v5 >= 0 )
  {
    v6 = &this->m_requiredProcesses.m_data[v5];
    do
    {
      hkStringPtr::~hkStringPtr(v6--);
      --v5;
    }
    while ( v5 >= 0 );
  }
  this->m_requiredProcesses.m_size = 0;
}

// File Line: 388
// RVA: 0xE75930
void __fastcall hkVisualDebugger::addDefaultProcess(hkVisualDebugger *this, const char *processName)
{
  hkArray<hkStringPtr,hkContainerHeapAllocator> *p_m_defaultProcesses; // rbx
  hkStringPtr *v4; // rcx
  __int64 m_size; // rdx
  hkStringPtr *v6; // rcx

  p_m_defaultProcesses = &this->m_defaultProcesses;
  if ( this->m_defaultProcesses.m_size == (this->m_defaultProcesses.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_defaultProcesses->m_data, 8);
  v4 = &p_m_defaultProcesses->m_data[p_m_defaultProcesses->m_size];
  if ( v4 )
    hkStringPtr::hkStringPtr(v4);
  m_size = p_m_defaultProcesses->m_size;
  v6 = &p_m_defaultProcesses->m_data[m_size];
  p_m_defaultProcesses->m_size = m_size + 1;
  hkStringPtr::operator=(v6, processName);
}

// File Line: 393
// RVA: 0xE759B0
void __fastcall hkVisualDebugger::removeDefaultProcess(hkVisualDebugger *this, const char *processName)
{
  int v2; // edi
  __int64 v5; // rbx
  hkOstream *v6; // rax
  hkOstream *v7; // rax
  __int64 v8; // rbx
  hkStringPtr *v9; // rax
  int v10; // ecx
  __int64 v11; // rdx
  const char *m_stringAndFlag; // rcx
  hkErrStream v13; // [rsp+20h] [rbp-228h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  v2 = 0;
  if ( this->m_defaultProcesses.m_size <= 0 )
  {
LABEL_5:
    ((void (__fastcall *)(hkError *, __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
      hkSingleton<hkError>::s_instance,
      1985369172i64,
      "removeDefaultProcess");
    hkErrStream::hkErrStream(&v13, buf, 512);
    v6 = hkOstream::operator<<(&v13, "The default Process");
    v7 = hkOstream::operator<<(v6, processName);
    hkOstream::operator<<(v7, ", cannot not be removed from the default process list as it cannot be found!");
    hkError::messageReport(0xFFFFFFFF, buf, "hkVisualDebugger.cpp", 406);
    hkOstream::~hkOstream(&v13);
    ((void (__fastcall *)(hkError *))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)(hkSingleton<hkError>::s_instance);
  }
  else
  {
    v5 = 0i64;
    while ( (unsigned int)hkString::strCmp(
                            (const char *)((unsigned __int64)this->m_defaultProcesses.m_data[v5].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                            processName) )
    {
      ++v2;
      ++v5;
      if ( v2 >= this->m_defaultProcesses.m_size )
        goto LABEL_5;
    }
    v8 = v2;
    hkStringPtr::~hkStringPtr(&this->m_defaultProcesses.m_data[v8]);
    --this->m_defaultProcesses.m_size;
    v9 = &this->m_defaultProcesses.m_data[v8];
    v10 = 8 * (this->m_defaultProcesses.m_size - v2);
    if ( v10 > 0 )
    {
      v11 = ((unsigned int)(v10 - 1) >> 3) + 1;
      do
      {
        m_stringAndFlag = v9[1].m_stringAndFlag;
        ++v9;
        v9[-1].m_stringAndFlag = m_stringAndFlag;
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
  hkArray<hkStringPtr,hkContainerHeapAllocator> *p_m_requiredProcesses; // rbx
  hkStringPtr *v4; // rcx
  __int64 m_size; // rdx
  hkStringPtr *v6; // rcx

  p_m_requiredProcesses = &this->m_requiredProcesses;
  if ( this->m_requiredProcesses.m_size == (this->m_requiredProcesses.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_requiredProcesses->m_data, 8);
  v4 = &p_m_requiredProcesses->m_data[p_m_requiredProcesses->m_size];
  if ( v4 )
    hkStringPtr::hkStringPtr(v4);
  m_size = p_m_requiredProcesses->m_size;
  v6 = &p_m_requiredProcesses->m_data[m_size];
  p_m_requiredProcesses->m_size = m_size + 1;
  hkStringPtr::operator=(v6, processName);
}

// File Line: 416
// RVA: 0xE75B90
void __fastcall hkVisualDebugger::addTrackedObject(
        hkVisualDebugger *this,
        void *obj,
        hkClass *klass,
        const char *group,
        unsigned __int64 tagId)
{
  __int64 m_size; // rdx
  int v9; // esi
  hkVisualDebuggerTrackedObject *v10; // r8
  __int64 v11; // rbx

  if ( this->m_trackedObjects.m_size == (this->m_trackedObjects.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_trackedObjects.m_data, 24);
  m_size = this->m_trackedObjects.m_size;
  v9 = 0;
  v10 = &this->m_trackedObjects.m_data[m_size];
  this->m_trackedObjects.m_size = m_size + 1;
  v10->m_ptr = obj;
  v10->m_class = klass;
  v10->m_tag = tagId;
  if ( this->m_trackCallbacks.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      LOBYTE(v10) = 1;
      ((void (__fastcall *)(void *, hkClass *, hkVisualDebuggerTrackedObject *, unsigned __int64, void *))this->m_trackCallbacks.m_data[v11])(
        obj,
        klass,
        v10,
        tagId,
        this->m_trackCallbackHandles.m_data[v11]);
      ++v9;
      ++v11;
    }
    while ( v9 < this->m_trackCallbacks.m_size );
  }
}

// File Line: 428
// RVA: 0xE75C60
void __fastcall hkVisualDebugger::removeTrackedObject(hkVisualDebugger *this, void *obj)
{
  int v2; // esi
  __int64 m_size; // rdx
  int v6; // r8d
  __int64 v7; // rcx
  hkVisualDebuggerTrackedObject *i; // rax
  __int64 v9; // rax
  hkVisualDebuggerTrackedObject *m_data; // rdx
  hkVisualDebuggerTrackedObject *v11; // r9
  hkVisualDebuggerTrackedObject *v12; // rax
  __int64 v13; // rdx
  signed __int64 v14; // r9
  unsigned __int64 v15; // rcx
  __int64 v16; // rdi

  v2 = 0;
  m_size = this->m_trackedObjects.m_size;
  v6 = 0;
  v7 = 0i64;
  if ( m_size > 0 )
  {
    for ( i = this->m_trackedObjects.m_data; i->m_ptr != obj; ++i )
    {
      ++v7;
      ++v6;
      if ( v7 >= m_size )
        return;
    }
    v9 = --this->m_trackedObjects.m_size;
    if ( (_DWORD)v9 != v6 )
    {
      m_data = this->m_trackedObjects.m_data;
      v11 = &m_data[v9];
      v12 = &m_data[v6];
      v13 = 3i64;
      v14 = (char *)v11 - (char *)v12;
      do
      {
        v15 = *(unsigned __int64 *)((char *)&v12->m_ptr + v14);
        v12 = (hkVisualDebuggerTrackedObject *)((char *)v12 + 8);
        v12[-1].m_tag = v15;
        --v13;
      }
      while ( v13 );
    }
    if ( this->m_trackCallbacks.m_size > 0 )
    {
      v16 = 0i64;
      do
      {
        ((void (__fastcall *)(void *, _QWORD, _QWORD, _QWORD, void *))this->m_trackCallbacks.m_data[v16])(
          obj,
          0i64,
          0i64,
          0i64,
          this->m_trackCallbackHandles.m_data[v16]);
        ++v2;
        ++v16;
      }
      while ( v2 < this->m_trackCallbacks.m_size );
    }
  }
}

// File Line: 444
// RVA: 0xE76830
void __fastcall hkVisualDebugger::addTrackedObjectCallback(
        hkVisualDebugger *this,
        void (__fastcall *callback)(void *, hkClass *, hkBool, unsigned __int64, void *),
        void *userHandle)
{
  if ( this->m_trackCallbacks.m_size == (this->m_trackCallbacks.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_trackCallbacks.m_data, 8);
  this->m_trackCallbacks.m_data[this->m_trackCallbacks.m_size++] = callback;
  if ( this->m_trackCallbackHandles.m_size == (this->m_trackCallbackHandles.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_trackCallbackHandles.m_data,
      8);
  this->m_trackCallbackHandles.m_data[this->m_trackCallbackHandles.m_size++] = userHandle;
}

// File Line: 450
// RVA: 0xE768D0
void __fastcall hkVisualDebugger::removeTrackedObjectCallback(
        hkVisualDebugger *this,
        void (__fastcall *callback)(void *, hkClass *, hkBool, unsigned __int64, void *))
{
  __int64 m_size; // r11
  int v3; // r8d
  __int64 v4; // r9
  void (__fastcall **i)(void *, hkClass *, hkBool, unsigned __int64, void *); // rax
  __int64 v6; // rax

  m_size = this->m_trackCallbacks.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( (int)m_size > 0 )
  {
    for ( i = this->m_trackCallbacks.m_data; *i != callback; ++i )
    {
      ++v4;
      ++v3;
      if ( v4 >= m_size )
        return;
    }
    if ( v3 >= 0 )
    {
      this->m_trackCallbacks.m_size = m_size - 1;
      if ( (_DWORD)m_size - 1 != v3 )
        this->m_trackCallbacks.m_data[v3] = this->m_trackCallbacks.m_data[(int)m_size - 1];
      v6 = --this->m_trackCallbackHandles.m_size;
      if ( (_DWORD)v6 != v3 )
        this->m_trackCallbackHandles.m_data[v3] = this->m_trackCallbackHandles.m_data[v6];
    }
  }
}

// File Line: 460
// RVA: 0xE765B0
void __fastcall hkVisualDebugger::getCurrentProcesses(
        hkVisualDebugger *this,
        hkArray<hkProcess *,hkContainerHeapAllocator> *process)
{
  __int64 m_size; // rdi
  __int64 v5; // rbx
  hkServerProcessHandler *m_processHandler; // r9

  m_size = this->m_clients.m_size;
  if ( m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      m_processHandler = this->m_clients.m_data[v5].m_processHandler;
      if ( m_processHandler )
        hkArrayBase<hkpEntity *>::_insertAt(
          process,
          &hkContainerHeapAllocator::s_alloc,
          process->m_size,
          m_processHandler->m_processList.m_data,
          m_processHandler->m_processList.m_size);
      ++v5;
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 474
// RVA: 0xE767B0
void __fastcall hkVisualDebugger::removeContext(hkVisualDebugger *this, hkProcessContext *context)
{
  int v2; // r9d
  __int64 m_size; // rcx
  __int64 v5; // r8
  hkProcessContext **i; // rax
  hkProcessContext **v7; // rax
  int v8; // edx
  __int64 v9; // rdx
  hkProcessContext *v10; // rcx

  v2 = 0;
  m_size = this->m_contexts.m_size;
  v5 = 0i64;
  if ( (int)m_size > 0 )
  {
    for ( i = this->m_contexts.m_data; *i != context; ++i )
    {
      ++v5;
      ++v2;
      if ( v5 >= m_size )
        return;
    }
    if ( v2 >= 0 )
    {
      this->m_contexts.m_size = m_size - 1;
      v7 = &this->m_contexts.m_data[v2];
      v8 = 8 * (m_size - 1 - v2);
      if ( v8 > 0 )
      {
        v9 = ((unsigned int)(v8 - 1) >> 3) + 1;
        do
        {
          v10 = v7[1];
          *v7++ = v10;
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
  int ProcessId; // esi
  int v4; // ebx
  __int64 v5; // rdi
  hkProcess *v7; // rbx
  hkArray<hkProcess *,hkContainerHeapAllocator> process; // [rsp+20h] [rbp-18h] BYREF

  ProcessId = hkProcessFactory::getProcessId(hkSingleton<hkProcessFactory>::s_instance, name);
  if ( ProcessId == -1 )
    return 0i64;
  process.m_data = 0i64;
  process.m_size = 0;
  process.m_capacityAndFlags = 0x80000000;
  hkVisualDebugger::getCurrentProcesses(this, &process);
  v4 = 0;
  if ( process.m_size <= 0 )
  {
LABEL_6:
    process.m_size = 0;
    if ( process.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        process.m_data,
        8 * process.m_capacityAndFlags);
    return 0i64;
  }
  v5 = 0i64;
  while ( process.m_data[v5]->vfptr->getProcessTag(process.m_data[v5]) != ProcessId )
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
      &hkContainerHeapAllocator::s_alloc,
      process.m_data,
      8 * process.m_capacityAndFlags);
  return v7;
}

