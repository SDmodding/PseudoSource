// File Line: 18
// RVA: 0xE6C850
void __fastcall hkRemoteObjectClientSideListener::sendObject(
        hkRemoteObjectClientSideListener *this,
        hkReferencedObject *object)
{
  void (__fastcall *m_sendFunc)(hkReferencedObject *); // rax

  m_sendFunc = this->m_sendFunc;
  if ( m_sendFunc )
    m_sendFunc(object);
}

// File Line: 27
// RVA: 0xE6C870
void __fastcall hkRemoteObjectProcess::hkRemoteObjectProcess(hkRemoteObjectProcess *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_selectable.m_bool = 1;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkRemoteObjectProcess::`vftable{for `hkReferencedObject};
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkRemoteObjectProcess::`vftable{for `hkProcess};
  this->m_listeners.m_capacityAndFlags = 0x80000000;
  this->m_listeners.m_data = 0i64;
  this->m_listeners.m_size = 0;
}

// File Line: 31
// RVA: 0xE6C8B0
void __fastcall hkRemoteObjectProcess::~hkRemoteObjectProcess(hkRemoteObjectProcess *this)
{
  int m_capacityAndFlags; // r8d

  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkRemoteObjectProcess::`vftable{for `hkReferencedObject};
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkRemoteObjectProcess::`vftable{for `hkProcess};
  m_capacityAndFlags = this->m_listeners.m_capacityAndFlags;
  this->m_listeners.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_listeners.m_data,
      8 * m_capacityAndFlags);
  this->m_listeners.m_data = 0i64;
  this->m_listeners.m_capacityAndFlags = 0x80000000;
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkProcess::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 35
// RVA: 0xE6CA70
void __fastcall hkRemoteObjectProcess::init(hkRemoteObjectProcess *this)
{
  ;
}

// File Line: 39
// RVA: 0xE6C930
void __fastcall hkRemoteObjectProcess::addListener(
        hkRemoteObjectProcess *this,
        hkRemoteObjectServerSideListener *listener)
{
  hkArray<hkRemoteObjectServerSideListener *,hkContainerHeapAllocator> *p_m_listeners; // rbx

  p_m_listeners = &this->m_listeners;
  if ( this->m_listeners.m_size == (this->m_listeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_listeners->m_data, 8);
  p_m_listeners->m_data[p_m_listeners->m_size++] = listener;
}

// File Line: 44
// RVA: 0xE6C990
void __fastcall hkRemoteObjectProcess::removeListener(
        hkRemoteObjectProcess *this,
        hkRemoteObjectServerSideListener *listener)
{
  __int64 m_size; // r11
  int v3; // r8d
  __int64 v4; // r9
  hkRemoteObjectServerSideListener **i; // rax

  m_size = this->m_listeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( (int)m_size > 0 )
  {
    for ( i = this->m_listeners.m_data; *i != listener; ++i )
    {
      ++v4;
      ++v3;
      if ( v4 >= m_size )
        return;
    }
    if ( v3 != -1 )
    {
      this->m_listeners.m_size = m_size - 1;
      if ( (_DWORD)m_size - 1 != v3 )
        this->m_listeners.m_data[v3] = this->m_listeners.m_data[(int)m_size - 1];
    }
  }
}

// File Line: 53
// RVA: 0xE6C9F0
void __fastcall hkRemoteObjectProcess::sendObject(
        hkDisplaySerializeOStream *stream,
        hkReferencedObject *object,
        hkRemoteObjectProcess::SendObjectType objType)
{
  hkStructureLayout *v6; // rax
  hkStructureLayout v7; // [rsp+50h] [rbp+8h] BYREF

  if ( stream )
  {
    if ( object )
    {
      hkStructureLayout::hkStructureLayout(&v7, (hkStructureLayout *)&hkStructureLayout::MsvcWin32LayoutRules);
      hkObjectSerialize::writeObject(
        stream,
        object,
        1,
        objType == SEND_OBJECT_PACKFILE,
        *v6,
        0i64,
        (hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int>)2);
    }
  }
}

// File Line: 64
// RVA: 0xE6CA80
void __fastcall hkRemoteObjectProcess::getConsumableCommands(
        hkRemoteObjectProcess *this,
        char **commands,
        int *numCommands)
{
  *commands = remoteObject_cmds;
  *numCommands = 1;
}

// File Line: 70
// RVA: 0xE6CAA0
void __fastcall hkRemoteObjectProcess::consumeCommand(hkRemoteObjectProcess *this, char command)
{
  int v3; // ebx
  hkReferencedObject *v4; // rbp
  __int64 v5; // rax
  __int64 v6; // r14
  __int64 v7; // rsi
  int v8; // r9d
  hkSerializeUtil::ErrorDetails errorDetails; // [rsp+20h] [rbp-238h] BYREF
  hkErrStream v10; // [rsp+30h] [rbp-228h] BYREF
  char buf[520]; // [rsp+50h] [rbp-208h] BYREF

  if ( command == 64 )
  {
    v3 = 0;
    errorDetails.id.m_storage = 0;
    hkStringPtr::hkStringPtr(&errorDetails.defaultMessage);
    v4 = hkObjectSerialize::readObject((hkDisplaySerializeIStream *)this->hkProcess::vfptr, &errorDetails);
    if ( v4
      && (v5 = ((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__first_virtual_table_function__)(hkSingleton<hkBuiltinTypeRegistry>::s_instance),
          (v6 = (*(__int64 (__fastcall **)(__int64, hkReferencedObject *))(*(_QWORD *)v5 + 40i64))(v5, v4)) != 0) )
    {
      if ( SLODWORD(this->m_processHandler) > 0 )
      {
        v7 = 0i64;
        do
        {
          (*((void (__fastcall **)(hkDebugDisplayHandlerVtbl *, hkReferencedObject *, __int64))this->m_displayHandler[v7].vfptr->__vecDelDtor
           + 1))(
            this->m_displayHandler[v7].vfptr,
            v4,
            v6);
          ++v3;
          ++v7;
        }
        while ( v3 < SLODWORD(this->m_processHandler) );
      }
      hkReferencedObject::removeReference(v4);
    }
    else
    {
      if ( errorDetails.id.m_storage )
      {
        hkErrStream::hkErrStream(&v10, buf, 512);
        hkOstream::operator<<(
          &v10,
          (const char *)((unsigned __int64)errorDetails.defaultMessage.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
        v8 = 92;
      }
      else
      {
        hkErrStream::hkErrStream(&v10, buf, 512);
        hkOstream::operator<<(&v10, "Could not load object from network for unknown reason");
        v8 = 96;
      }
      hkError::messageWarning(0x6345FEDu, buf, "Process\\hkRemoteObjectProcess.cpp", v8);
      hkOstream::~hkOstream(&v10);
    }
    hkStringPtr::~hkStringPtr(&errorDetails.defaultMessage);
  }
}

// File Line: 105
// RVA: 0xE6CC00
hkProcess *__fastcall hkRemoteObjectProcess::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  _QWORD **Value; // rax
  hkRemoteObjectProcess *v2; // rax
  __int64 v3; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v2 = (hkRemoteObjectProcess *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
  if ( v2 && (hkRemoteObjectProcess::hkRemoteObjectProcess(v2), v3) )
    return (hkProcess *)(v3 + 16);
  else
    return 0i64;
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

