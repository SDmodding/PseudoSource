// File Line: 15
// RVA: 0xE6CDB0
void __fastcall hkProcessContext::syncTimers(hkProcessContext *this, hkThreadPool *threadPool)
{
  const char *v4; // rbp
  const char *v5; // rbp

  this->m_monitorStreamBegins.m_size = 0;
  this->m_monitorStreamEnds.m_size = 0;
  v4 = *(const char **)TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  if ( this->m_monitorStreamBegins.m_size == (this->m_monitorStreamBegins.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_monitorStreamBegins.m_data, 8);
  this->m_monitorStreamBegins.m_data[this->m_monitorStreamBegins.m_size++] = v4;
  v5 = (const char *)*((_QWORD *)TlsGetValue(hkMonitorStream__m_instance.m_slotID) + 1);
  if ( this->m_monitorStreamEnds.m_size == (this->m_monitorStreamEnds.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_monitorStreamEnds.m_data, 8);
  this->m_monitorStreamEnds.m_data[this->m_monitorStreamEnds.m_size++] = v5;
  if ( threadPool )
    hkProcessContext::addThreadPoolTimers(this, threadPool);
}

// File Line: 27
// RVA: 0xE6CE80
void __fastcall hkProcessContext::addThreadPoolTimers(hkProcessContext *this, hkThreadPool *threadPool)
{
  _QWORD *Value; // rax
  int v5; // ebp
  hkInplaceArray<char const *,6,hkContainerHeapAllocator> *p_m_monitorStreamEnds; // rbx
  hkInplaceArray<char const *,6,hkContainerHeapAllocator> *p_m_monitorStreamBegins; // rdi
  __int64 v8; // rsi
  char *v9; // r14
  char *v10; // r14
  const char *v11; // rax
  char *v12; // [rsp+20h] [rbp-18h] BYREF
  int v13; // [rsp+28h] [rbp-10h]
  int v14; // [rsp+2Ch] [rbp-Ch]

  v12 = 0i64;
  v13 = 0;
  v14 = 0x80000000;
  Value = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  ((void (__fastcall *)(hkThreadPool *, char **, _QWORD))threadPool->vfptr[4].__vecDelDtor)(threadPool, &v12, Value[10]);
  v5 = 0;
  if ( v13 > 0 )
  {
    p_m_monitorStreamEnds = &this->m_monitorStreamEnds;
    p_m_monitorStreamBegins = &this->m_monitorStreamBegins;
    v8 = 0i64;
    do
    {
      v9 = v12;
      if ( p_m_monitorStreamBegins->m_size == (p_m_monitorStreamBegins->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&p_m_monitorStreamBegins->m_data,
          8);
      p_m_monitorStreamBegins->m_data[p_m_monitorStreamBegins->m_size++] = *(const char **)&v9[v8];
      v10 = v12;
      if ( p_m_monitorStreamEnds->m_size == (p_m_monitorStreamEnds->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_monitorStreamEnds->m_data, 8);
      ++v5;
      v11 = *(const char **)&v10[v8 + 8];
      v8 += 16i64;
      p_m_monitorStreamEnds->m_data[p_m_monitorStreamEnds->m_size++] = v11;
    }
    while ( v5 < v13 );
  }
  v13 = 0;
  if ( v14 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v12, 16 * v14);
}

// File Line: 38
// RVA: 0xE6CD00
void __fastcall hkProcessContext::~hkProcessContext(hkProcessContext *this)
{
  hkVisualDebugger *m_owner; // rcx
  int m_capacityAndFlags; // r8d
  int v4; // r8d

  this->vfptr = (hkProcessContextVtbl *)&hkProcessContext::`vftable;
  m_owner = this->m_owner;
  if ( m_owner )
    hkVisualDebugger::removeContext(m_owner, this);
  m_capacityAndFlags = this->m_monitorStreamEnds.m_capacityAndFlags;
  this->m_monitorStreamEnds.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_monitorStreamEnds.m_data,
      8 * m_capacityAndFlags);
  this->m_monitorStreamEnds.m_data = 0i64;
  this->m_monitorStreamEnds.m_capacityAndFlags = 0x80000000;
  v4 = this->m_monitorStreamBegins.m_capacityAndFlags;
  this->m_monitorStreamBegins.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_monitorStreamBegins.m_data,
      8 * v4);
  this->m_monitorStreamBegins.m_capacityAndFlags = 0x80000000;
  this->m_monitorStreamBegins.m_data = 0i64;
}

