// File Line: 15
// RVA: 0xE6C340
void __fastcall hkProcessFactory::hkProcessFactory(hkProcessFactory *this)
{
  _QWORD **Value; // rax
  hkCriticalSection *v3; // rax
  hkCriticalSection *v4; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkProcessFactory::`vftable;
  this->m_freeTag = 0;
  this->m_name2creationFunction.m_data = 0i64;
  this->m_name2creationFunction.m_size = 0;
  this->m_name2creationFunction.m_capacityAndFlags = 0x80000000;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  if ( v3 )
  {
    hkCriticalSection::hkCriticalSection(v3, 0x7D0u);
    this->m_criticalSection = v4;
  }
  else
  {
    this->m_criticalSection = 0i64;
  }
}

// File Line: 20
// RVA: 0xE6C3D0
void __fastcall hkProcessFactory::~hkProcessFactory(hkProcessFactory *this)
{
  hkCriticalSection *m_criticalSection; // rbx
  _QWORD **Value; // rax
  int v4; // ebx
  hkProcessFactory::ProcessIdPair *v5; // rdi
  int m_capacityAndFlags; // eax

  m_criticalSection = this->m_criticalSection;
  this->vfptr = (hkBaseObjectVtbl *)&hkProcessFactory::`vftable;
  if ( m_criticalSection )
  {
    DeleteCriticalSection(&m_criticalSection->m_section);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkCriticalSection *, __int64))(*Value[11] + 16i64))(
      Value[11],
      m_criticalSection,
      40i64);
  }
  v4 = this->m_name2creationFunction.m_size - 1;
  if ( v4 >= 0 )
  {
    v5 = &this->m_name2creationFunction.m_data[v4];
    do
    {
      hkStringPtr::~hkStringPtr(&v5->m_name);
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
  m_capacityAndFlags = this->m_name2creationFunction.m_capacityAndFlags;
  this->m_name2creationFunction.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_name2creationFunction.m_data,
      24 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_name2creationFunction.m_data = 0i64;
  this->m_name2creationFunction.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 25
// RVA: 0xE6C4A0
__int64 __fastcall hkProcessFactory::registerProcess(
        hkProcessFactory *this,
        const char *viewerName,
        hkProcess *(__fastcall *creationFunction)(hkArray<hkProcessContext *,hkContainerHeapAllocator> *))
{
  int v6; // edi
  __int64 v7; // rsi
  const char *v8; // rcx
  int v9; // eax
  hkProcessFactory::ProcessIdPair *v10; // rdi
  __int64 m_size; // rsi
  int v12; // r9d
  int v13; // eax
  int v14; // eax
  hkProcessFactory::ProcessIdPair *v15; // rcx
  hkProcessFactory::ProcessIdPair *m_data; // rax
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  EnterCriticalSection(&this->m_criticalSection->m_section);
  v6 = 0;
  if ( this->m_name2creationFunction.m_size <= 0 )
  {
LABEL_11:
    m_size = this->m_name2creationFunction.m_size;
    v12 = m_size + 1;
    v13 = this->m_name2creationFunction.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v13 >= (int)m_size + 1 )
    {
      result.m_enum = HK_SUCCESS;
    }
    else
    {
      v14 = 2 * v13;
      if ( v12 < v14 )
        v12 = v14;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_name2creationFunction.m_data,
        v12,
        24);
    }
    v15 = &this->m_name2creationFunction.m_data[this->m_name2creationFunction.m_size];
    if ( v15 )
      hkStringPtr::hkStringPtr(&v15->m_name);
    m_data = this->m_name2creationFunction.m_data;
    ++this->m_name2creationFunction.m_size;
    v10 = &m_data[m_size];
    hkStringPtr::operator=(&v10->m_name, viewerName);
    v10->m_processCreationFunction = creationFunction;
    v10->m_tag = this->m_freeTag++;
    goto LABEL_19;
  }
  v7 = 0i64;
  while ( 1 )
  {
    v8 = (const char *)((unsigned __int64)this->m_name2creationFunction.m_data[v7].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
    if ( !v8 )
      break;
    if ( viewerName )
    {
      v9 = hkString::strCmp(v8, viewerName);
      goto LABEL_7;
    }
LABEL_8:
    ++v6;
    ++v7;
    if ( v6 >= this->m_name2creationFunction.m_size )
      goto LABEL_11;
  }
  v9 = -(viewerName != 0i64);
LABEL_7:
  if ( v9 )
    goto LABEL_8;
  v10 = &this->m_name2creationFunction.m_data[v6];
  if ( !v10 )
    goto LABEL_11;
LABEL_19:
  LeaveCriticalSection(&this->m_criticalSection->m_section);
  return (unsigned int)v10->m_tag;
}

// File Line: 59
// RVA: 0xE6C5D0
const char *__fastcall hkProcessFactory::getProcessName(hkProcessFactory *this, int id)
{
  __int64 v3; // rbx
  unsigned __int64 v4; // rbx

  v3 = id;
  EnterCriticalSection(&this->m_criticalSection->m_section);
  v4 = (unsigned __int64)this->m_name2creationFunction.m_data[v3].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64;
  LeaveCriticalSection(&this->m_criticalSection->m_section);
  return (const char *)v4;
}

// File Line: 67
// RVA: 0xE6C620
__int64 __fastcall hkProcessFactory::getProcessId(hkProcessFactory *this, const char *name)
{
  int v4; // ebx
  __int64 v5; // rdi
  const char *v6; // rcx
  int v7; // eax

  EnterCriticalSection(&this->m_criticalSection->m_section);
  v4 = 0;
  if ( this->m_name2creationFunction.m_size <= 0 )
  {
LABEL_9:
    LeaveCriticalSection(&this->m_criticalSection->m_section);
    return 0xFFFFFFFFi64;
  }
  v5 = 0i64;
  while ( 1 )
  {
    v6 = (const char *)((unsigned __int64)this->m_name2creationFunction.m_data[v5].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
    if ( !v6 )
      break;
    if ( name )
    {
      v7 = hkString::strCmp(v6, name);
      goto LABEL_7;
    }
LABEL_8:
    ++v4;
    ++v5;
    if ( v4 >= this->m_name2creationFunction.m_size )
      goto LABEL_9;
  }
  v7 = -(name != 0i64);
LABEL_7:
  if ( v7 )
    goto LABEL_8;
  LeaveCriticalSection(&this->m_criticalSection->m_section);
  return (unsigned int)v4;
}

// File Line: 83
// RVA: 0xE6C740
hkProcess *__fastcall hkProcessFactory::createProcess(
        hkProcessFactory *this,
        int tag,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkCriticalSection *m_criticalSection; // rsi
  __int64 v6; // rbx
  hkProcess *v7; // rbx

  m_criticalSection = this->m_criticalSection;
  v6 = tag;
  EnterCriticalSection(&m_criticalSection->m_section);
  v7 = this->m_name2creationFunction.m_data[v6].m_processCreationFunction(contexts);
  LeaveCriticalSection(&m_criticalSection->m_section);
  return v7;
}

// File Line: 95
// RVA: 0xE6C6C0
hkProcess *__fastcall hkProcessFactory::createProcess(
        hkProcessFactory *this,
        const char *processName,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkCriticalSection *m_criticalSection; // rdi
  int ProcessId; // eax
  hkProcess *Process; // rbx

  m_criticalSection = this->m_criticalSection;
  EnterCriticalSection(&m_criticalSection->m_section);
  ProcessId = hkProcessFactory::getProcessId(this, processName);
  if ( ProcessId >= 0 )
    Process = hkProcessFactory::createProcess(this, ProcessId, contexts);
  else
    Process = 0i64;
  LeaveCriticalSection(&m_criticalSection->m_section);
  return Process;
}

// File Line: 105
// RVA: 0x15D8A30
hkSingletonInitNode *dynamic_initializer_for__hkSingletonRegisterhkProcessFactory__()
{
  hkSingletonInitNode *result; // rax

  hkSingletonRegisterhkProcessFactory.m_next = hkSingletonInitList;
  result = &hkSingletonRegisterhkProcessFactory;
  hkSingletonInitList = &hkSingletonRegisterhkProcessFactory;
  return result;
}

