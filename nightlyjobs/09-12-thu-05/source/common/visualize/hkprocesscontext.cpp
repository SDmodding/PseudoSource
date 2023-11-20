// File Line: 15
// RVA: 0xE6CDB0
void __fastcall hkProcessContext::syncTimers(hkProcessContext *this, hkThreadPool *threadPool)
{
  hkProcessContext *v2; // rdi
  hkThreadPool *v3; // rsi
  const char *v4; // rbp
  const char *v5; // rbp

  v2 = this;
  v3 = threadPool;
  this->m_monitorStreamBegins.m_size = 0;
  this->m_monitorStreamEnds.m_size = 0;
  v4 = *(const char **)TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  if ( v2->m_monitorStreamBegins.m_size == (v2->m_monitorStreamBegins.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v2->m_monitorStreamBegins,
      8);
  v2->m_monitorStreamBegins.m_data[v2->m_monitorStreamBegins.m_size++] = v4;
  v5 = (const char *)*((_QWORD *)TlsGetValue(hkMonitorStream__m_instance.m_slotID) + 1);
  if ( v2->m_monitorStreamEnds.m_size == (v2->m_monitorStreamEnds.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v2->m_monitorStreamEnds,
      8);
  v2->m_monitorStreamEnds.m_data[v2->m_monitorStreamEnds.m_size++] = v5;
  if ( v3 )
    hkProcessContext::addThreadPoolTimers(v2, v3);
}

// File Line: 27
// RVA: 0xE6CE80
void __fastcall hkProcessContext::addThreadPoolTimers(hkProcessContext *this, hkThreadPool *threadPool)
{
  hkProcessContext *v2; // rsi
  hkThreadPool *v3; // rbx
  _QWORD *v4; // rax
  int v5; // ebp
  hkInplaceArray<char const *,6,hkContainerHeapAllocator> *v6; // rbx
  hkInplaceArray<char const *,6,hkContainerHeapAllocator> *v7; // rdi
  __int64 v8; // rsi
  char *v9; // r14
  char *v10; // r14
  const char *v11; // rax
  char *v12; // [rsp+20h] [rbp-18h]
  int v13; // [rsp+28h] [rbp-10h]
  int v14; // [rsp+2Ch] [rbp-Ch]

  v2 = this;
  v3 = threadPool;
  v12 = 0i64;
  v13 = 0;
  v14 = 2147483648;
  v4 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  ((void (__fastcall *)(hkThreadPool *, char **, _QWORD))v3->vfptr[4].__vecDelDtor)(v3, &v12, v4[10]);
  v5 = 0;
  if ( v13 > 0 )
  {
    v6 = &v2->m_monitorStreamEnds;
    v7 = &v2->m_monitorStreamBegins;
    v8 = 0i64;
    do
    {
      v9 = v12;
      if ( v7->m_size == (v7->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 8);
      v7->m_data[v7->m_size++] = *(const char **)&v9[v8];
      v10 = v12;
      if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 8);
      ++v5;
      v11 = *(const char **)&v10[v8 + 8];
      v8 += 16i64;
      v6->m_data[v6->m_size++] = v11;
    }
    while ( v5 < v13 );
  }
  v13 = 0;
  if ( v14 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v12,
      16 * v14);
}

// File Line: 38
// RVA: 0xE6CD00
void __fastcall hkProcessContext::~hkProcessContext(hkProcessContext *this)
{
  hkProcessContext *v1; // rbx
  hkVisualDebugger *v2; // rcx
  int v3; // er8
  int v4; // er8

  v1 = this;
  this->vfptr = (hkProcessContextVtbl *)&hkProcessContext::`vftable';
  v2 = this->m_owner;
  if ( v2 )
    hkVisualDebugger::removeContext(v2, v1);
  v3 = v1->m_monitorStreamEnds.m_capacityAndFlags;
  v1->m_monitorStreamEnds.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_monitorStreamEnds.m_data,
      8 * v3);
  v1->m_monitorStreamEnds.m_data = 0i64;
  v1->m_monitorStreamEnds.m_capacityAndFlags = 2147483648;
  v4 = v1->m_monitorStreamBegins.m_capacityAndFlags;
  v1->m_monitorStreamBegins.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_monitorStreamBegins.m_data,
      8 * v4);
  v1->m_monitorStreamBegins.m_capacityAndFlags = 2147483648;
  v1->m_monitorStreamBegins.m_data = 0i64;
}

