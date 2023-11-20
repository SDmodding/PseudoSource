// File Line: 15
// RVA: 0xE6C340
void __fastcall hkProcessFactory::hkProcessFactory(hkProcessFactory *this)
{
  hkProcessFactory *v1; // rbx
  _QWORD **v2; // rax
  hkCriticalSection *v3; // rax
  hkCriticalSection *v4; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkProcessFactory::`vftable';
  this->m_freeTag = 0;
  this->m_name2creationFunction.m_data = 0i64;
  this->m_name2creationFunction.m_size = 0;
  this->m_name2creationFunction.m_capacityAndFlags = 2147483648;
  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 40i64);
  if ( v3 )
  {
    hkCriticalSection::hkCriticalSection(v3, 2000);
    v1->m_criticalSection = v4;
  }
  else
  {
    v1->m_criticalSection = 0i64;
  }
}

// File Line: 20
// RVA: 0xE6C3D0
void __fastcall hkProcessFactory::~hkProcessFactory(hkProcessFactory *this)
{
  hkCriticalSection *v1; // rbx
  hkProcessFactory *v2; // rsi
  _QWORD **v3; // rax
  int v4; // ebx
  hkStringPtr *v5; // rdi
  int v6; // eax

  v1 = this->m_criticalSection;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkProcessFactory::`vftable';
  if ( v1 )
  {
    DeleteCriticalSection(&v1->m_section);
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkCriticalSection *, signed __int64))(*v3[11] + 16i64))(v3[11], v1, 40i64);
  }
  v4 = v2->m_name2creationFunction.m_size - 1;
  if ( v4 >= 0 )
  {
    v5 = &v2->m_name2creationFunction.m_data[v4].m_name;
    do
    {
      hkStringPtr::~hkStringPtr(v5);
      v5 -= 3;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v6 = v2->m_name2creationFunction.m_capacityAndFlags;
  v2->m_name2creationFunction.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_name2creationFunction.m_data,
      24 * (v6 & 0x3FFFFFFF));
  v2->m_name2creationFunction.m_data = 0i64;
  v2->m_name2creationFunction.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 25
// RVA: 0xE6C4A0
__int64 __fastcall hkProcessFactory::registerProcess(hkProcessFactory *this, const char *viewerName, hkProcess *(__fastcall *creationFunction)(hkArray<hkProcessContext *,hkContainerHeapAllocator> *))
{
  hkProcessFactory *v3; // rbx
  hkProcess *(__fastcall *v4)(hkArray<hkProcessContext *,hkContainerHeapAllocator> *); // r14
  const char *v5; // rbp
  int v6; // edi
  __int64 v7; // rsi
  const char *v8; // rcx
  int v9; // eax
  signed __int64 v10; // rdi
  __int64 v11; // rsi
  int v12; // er9
  int v13; // eax
  int v14; // eax
  hkStringPtr *v15; // rcx
  hkProcessFactory::ProcessIdPair *v16; // rax
  hkResult result; // [rsp+50h] [rbp+8h]

  v3 = this;
  v4 = creationFunction;
  v5 = viewerName;
  EnterCriticalSection(&this->m_criticalSection->m_section);
  v6 = 0;
  if ( v3->m_name2creationFunction.m_size <= 0 )
  {
LABEL_11:
    v11 = v3->m_name2creationFunction.m_size;
    v12 = v11 + 1;
    v13 = v3->m_name2creationFunction.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v13 >= (signed int)v11 + 1 )
    {
      result.m_enum = 0;
    }
    else
    {
      v14 = 2 * v13;
      if ( v12 < v14 )
        v12 = v14;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v3->m_name2creationFunction,
        v12,
        24);
    }
    v15 = &v3->m_name2creationFunction.m_data[v3->m_name2creationFunction.m_size].m_name;
    if ( v15 )
      hkStringPtr::hkStringPtr(v15);
    v16 = v3->m_name2creationFunction.m_data;
    ++v3->m_name2creationFunction.m_size;
    v10 = (signed __int64)&v16[v11];
    hkStringPtr::operator=(&v16[v11].m_name, v5);
    *(_QWORD *)(v10 + 8) = v4;
    *(_DWORD *)(v10 + 16) = v3->m_freeTag++;
    goto LABEL_19;
  }
  v7 = 0i64;
  while ( 1 )
  {
    v8 = (const char *)((_QWORD)v3->m_name2creationFunction.m_data[v7].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
    if ( !v8 )
      break;
    if ( v5 )
    {
      v9 = hkString::strCmp(v8, v5);
      goto LABEL_7;
    }
LABEL_8:
    ++v6;
    ++v7;
    if ( v6 >= v3->m_name2creationFunction.m_size )
      goto LABEL_11;
  }
  v9 = -(v5 != 0i64);
LABEL_7:
  if ( v9 )
    goto LABEL_8;
  v10 = (signed __int64)&v3->m_name2creationFunction.m_data[v6];
  if ( !v10 )
    goto LABEL_11;
LABEL_19:
  LeaveCriticalSection(&v3->m_criticalSection->m_section);
  return *(unsigned int *)(v10 + 16);
}

// File Line: 59
// RVA: 0xE6C5D0
const char *__fastcall hkProcessFactory::getProcessName(hkProcessFactory *this, int id)
{
  hkProcessFactory *v2; // rdi
  __int64 v3; // rbx
  unsigned __int64 v4; // rbx

  v2 = this;
  v3 = id;
  EnterCriticalSection(&this->m_criticalSection->m_section);
  v4 = (_QWORD)v2->m_name2creationFunction.m_data[v3].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64;
  LeaveCriticalSection(&v2->m_criticalSection->m_section);
  return (const char *)v4;
}

// File Line: 67
// RVA: 0xE6C620
signed __int64 __fastcall hkProcessFactory::getProcessId(hkProcessFactory *this, const char *name)
{
  hkProcessFactory *v2; // rsi
  const char *v3; // rbp
  int v4; // ebx
  __int64 v5; // rdi
  const char *v6; // rcx
  int v7; // eax

  v2 = this;
  v3 = name;
  EnterCriticalSection(&this->m_criticalSection->m_section);
  v4 = 0;
  if ( v2->m_name2creationFunction.m_size <= 0 )
  {
LABEL_9:
    LeaveCriticalSection(&v2->m_criticalSection->m_section);
    return 0xFFFFFFFFi64;
  }
  v5 = 0i64;
  while ( 1 )
  {
    v6 = (const char *)((_QWORD)v2->m_name2creationFunction.m_data[v5].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
    if ( !v6 )
      break;
    if ( v3 )
    {
      v7 = hkString::strCmp(v6, v3);
      goto LABEL_7;
    }
LABEL_8:
    ++v4;
    ++v5;
    if ( v4 >= v2->m_name2creationFunction.m_size )
      goto LABEL_9;
  }
  v7 = -(v3 != 0i64);
LABEL_7:
  if ( v7 )
    goto LABEL_8;
  LeaveCriticalSection(&v2->m_criticalSection->m_section);
  return (unsigned int)v4;
}

// File Line: 83
// RVA: 0xE6C740
hkProcess *__fastcall hkProcessFactory::createProcess(hkProcessFactory *this, int tag, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkCriticalSection *v3; // rsi
  hkProcessFactory *v4; // rdi
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v5; // rbp
  __int64 v6; // rbx
  __int64 v7; // rbx

  v3 = this->m_criticalSection;
  v4 = this;
  v5 = contexts;
  v6 = tag;
  EnterCriticalSection(&this->m_criticalSection->m_section);
  v7 = (__int64)v4->m_name2creationFunction.m_data[v6].m_processCreationFunction(v5);
  LeaveCriticalSection(&v3->m_section);
  return (hkProcess *)v7;
}

// File Line: 95
// RVA: 0xE6C6C0
hkProcess *__fastcall hkProcessFactory::createProcess(hkProcessFactory *this, const char *processName, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkCriticalSection *v3; // rdi
  hkProcessFactory *v4; // rsi
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v5; // rbp
  const char *v6; // rbx
  int v7; // eax
  hkProcess *v8; // rbx

  v3 = this->m_criticalSection;
  v4 = this;
  v5 = contexts;
  v6 = processName;
  EnterCriticalSection(&this->m_criticalSection->m_section);
  v7 = hkProcessFactory::getProcessId(v4, v6);
  if ( v7 >= 0 )
    v8 = hkProcessFactory::createProcess(v4, v7, v5);
  else
    v8 = 0i64;
  LeaveCriticalSection(&v3->m_section);
  return v8;
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

