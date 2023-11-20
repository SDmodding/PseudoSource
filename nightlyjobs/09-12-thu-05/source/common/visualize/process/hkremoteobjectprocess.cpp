// File Line: 18
// RVA: 0xE6C850
void __fastcall hkRemoteObjectClientSideListener::sendObject(hkRemoteObjectClientSideListener *this, hkReferencedObject *object)
{
  void (__fastcall *v2)(hkReferencedObject *); // rax

  v2 = this->m_sendFunc;
  if ( v2 )
    v2(object);
}

// File Line: 27
// RVA: 0xE6C870
void __fastcall hkRemoteObjectProcess::hkRemoteObjectProcess(hkRemoteObjectProcess *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_selectable.m_bool = 1;
  this->vfptr = (hkBaseObjectVtbl *)&hkRemoteObjectProcess::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkProcessVtbl *)&hkRemoteObjectProcess::`vftable'{for `hkProcess'};
  this->m_listeners.m_capacityAndFlags = 2147483648;
  this->m_listeners.m_data = 0i64;
  this->m_listeners.m_size = 0;
}

// File Line: 31
// RVA: 0xE6C8B0
void __fastcall hkRemoteObjectProcess::~hkRemoteObjectProcess(hkRemoteObjectProcess *this)
{
  hkRemoteObjectProcess *v1; // rbx
  int v2; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkRemoteObjectProcess::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkProcessVtbl *)&hkRemoteObjectProcess::`vftable'{for `hkProcess'};
  v2 = this->m_listeners.m_capacityAndFlags;
  this->m_listeners.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_listeners.m_data,
      8 * v2);
  v1->m_listeners.m_data = 0i64;
  v1->m_listeners.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkProcessVtbl *)&hkProcess::`vftable';
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 35
// RVA: 0xE6CA70
void __fastcall hkRemoteObjectProcess::init(hkRemoteObjectProcess *this)
{
  ;
}

// File Line: 39
// RVA: 0xE6C930
void __fastcall hkRemoteObjectProcess::addListener(hkRemoteObjectProcess *this, hkRemoteObjectServerSideListener *listener)
{
  hkArray<hkRemoteObjectServerSideListener *,hkContainerHeapAllocator> *v2; // rbx
  hkRemoteObjectServerSideListener *v3; // rdi

  v2 = &this->m_listeners;
  v3 = listener;
  if ( this->m_listeners.m_size == (this->m_listeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
}

// File Line: 44
// RVA: 0xE6C990
void __fastcall hkRemoteObjectProcess::removeListener(hkRemoteObjectProcess *this, hkRemoteObjectServerSideListener *listener)
{
  __int64 v2; // r11
  int v3; // er8
  __int64 v4; // r9
  hkRemoteObjectServerSideListener **v5; // rax

  v2 = this->m_listeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( (signed int)v2 > 0 )
  {
    v5 = this->m_listeners.m_data;
    while ( *v5 != listener )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        return;
    }
    if ( v3 != -1 )
    {
      this->m_listeners.m_size = v2 - 1;
      if ( (_DWORD)v2 - 1 != v3 )
        this->m_listeners.m_data[v3] = this->m_listeners.m_data[(signed int)v2 - 1];
    }
  }
}

// File Line: 53
// RVA: 0xE6C9F0
void __fastcall hkRemoteObjectProcess::sendObject(hkDisplaySerializeOStream *stream, hkReferencedObject *object, hkRemoteObjectProcess::SendObjectType objType)
{
  hkRemoteObjectProcess::SendObjectType v3; // esi
  hkReferencedObject *v4; // rbx
  hkDisplaySerializeOStream *v5; // rdi
  hkStructureLayout *v6; // rax
  hkStructureLayout v7; // [rsp+50h] [rbp+8h]

  if ( stream )
  {
    v3 = objType;
    v4 = object;
    v5 = stream;
    if ( object )
    {
      hkStructureLayout::hkStructureLayout(&v7, &hkStructureLayout::MsvcWin32LayoutRules);
      hkObjectSerialize::writeObject(
        v5,
        v4,
        1,
        v3 == 0,
        *v6,
        0i64,
        (hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int>)2);
    }
  }
}

// File Line: 64
// RVA: 0xE6CA80
void __fastcall hkRemoteObjectProcess::getConsumableCommands(hkRemoteObjectProcess *this, char **commands, int *numCommands)
{
  *commands = remoteObject_cmds;
  *numCommands = 1;
}

// File Line: 70
// RVA: 0xE6CAA0
void __fastcall hkRemoteObjectProcess::consumeCommand(hkRemoteObjectProcess *this, char command)
{
  hkRemoteObjectProcess *v2; // rdi
  int v3; // ebx
  hkReferencedObject *v4; // rbp
  __int64 v5; // rax
  __int64 v6; // r14
  __int64 v7; // rsi
  int v8; // er9
  hkSerializeUtil::ErrorDetails errorDetails; // [rsp+20h] [rbp-238h]
  hkErrStream v10; // [rsp+30h] [rbp-228h]
  char buf; // [rsp+50h] [rbp-208h]

  if ( command == 64 )
  {
    v2 = this;
    v3 = 0;
    errorDetails.id.m_storage = 0;
    hkStringPtr::hkStringPtr(&errorDetails.defaultMessage);
    v4 = hkObjectSerialize::readObject((hkDisplaySerializeIStream *)v2->vfptr, &errorDetails);
    if ( v4
      && (v5 = ((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__first_virtual_table_function__)(),
          (v6 = (*(__int64 (__fastcall **)(__int64, hkReferencedObject *))(*(_QWORD *)v5 + 40i64))(v5, v4)) != 0) )
    {
      if ( SLODWORD(v2->m_processHandler) > 0 )
      {
        v7 = 0i64;
        do
        {
          (*((void (__fastcall **)(hkDebugDisplayHandlerVtbl *, hkReferencedObject *, __int64))v2->m_displayHandler[v7].vfptr->__vecDelDtor
           + 1))(
            v2->m_displayHandler[v7].vfptr,
            v4,
            v6);
          ++v3;
          ++v7;
        }
        while ( v3 < SLODWORD(v2->m_processHandler) );
      }
      hkReferencedObject::removeReference(v4);
    }
    else
    {
      if ( errorDetails.id.m_storage )
      {
        hkErrStream::hkErrStream(&v10, &buf, 512);
        hkOstream::operator<<(
          (hkOstream *)&v10.vfptr,
          (const char *)((_QWORD)errorDetails.defaultMessage.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
        v8 = 92;
      }
      else
      {
        hkErrStream::hkErrStream(&v10, &buf, 512);
        hkOstream::operator<<((hkOstream *)&v10.vfptr, "Could not load object from network for unknown reason");
        v8 = 96;
      }
      hkError::messageWarning(104095725, &buf, "Process\\hkRemoteObjectProcess.cpp", v8);
      hkOstream::~hkOstream((hkOstream *)&v10.vfptr);
    }
    hkStringPtr::~hkStringPtr(&errorDetails.defaultMessage);
  }
}

// File Line: 105
// RVA: 0xE6CC00
hkProcess *__fastcall hkRemoteObjectProcess::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  _QWORD **v1; // rax
  hkRemoteObjectProcess *v2; // rax
  __int64 v3; // rax
  hkProcess *result; // rax

  v1 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v2 = (hkRemoteObjectProcess *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v1[11] + 8i64))(v1[11], 80i64);
  if ( v2 && (hkRemoteObjectProcess::hkRemoteObjectProcess(v2), v3) )
    result = (hkProcess *)(v3 + 16);
  else
    result = 0i64;
  return result;
}

// File Line: 110
// RVA: 0xE6CC50
void hkRemoteObjectProcess::registerProcess(void)
{
  hkRemoteObjectProcess::m_tag = hkProcessFactory::registerProcess(
                                   hkSingleton<hkProcessFactory>::s_instance,
                                   "RemoteObject",
                                   hkRemoteObjectProcess::create);
}

