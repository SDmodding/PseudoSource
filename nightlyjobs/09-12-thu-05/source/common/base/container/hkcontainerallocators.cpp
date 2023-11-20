// File Line: 12
// RVA: 0xC65A90
__int64 __fastcall hkContainerTempAllocator::Allocator::blockAlloc(hkContainerTempAllocator::Allocator *this, int numBytes)
{
  unsigned int v2; // ebx
  _QWORD **v3; // rax

  v2 = numBytes;
  v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v3[10] + 8i64))(v3[10], v2);
}

// File Line: 13
// RVA: 0xC65AC0
void __fastcall hkContainerTempAllocator::Allocator::blockFree(hkContainerTempAllocator::Allocator *this, void *p, int numBytes)
{
  unsigned int v3; // ebx
  void *v4; // rdi
  _QWORD **v5; // rax

  v3 = numBytes;
  v4 = p;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*v5[10] + 16i64))(v5[10], v4, v3);
}

// File Line: 14
// RVA: 0xC65B00
__int64 __fastcall hkContainerTempAllocator::Allocator::bufAlloc(hkContainerTempAllocator::Allocator *this, int *reqNumBytesInOut)
{
  int *v2; // rbx
  _QWORD **v3; // rax

  v2 = reqNumBytesInOut;
  v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, int *))(*v3[10] + 24i64))(v3[10], v2);
}

// File Line: 15
// RVA: 0xC65B30
void __fastcall hkContainerTempAllocator::Allocator::bufFree(hkContainerTempAllocator::Allocator *this, void *p, int numBytes)
{
  unsigned int v3; // ebx
  void *v4; // rdi
  _QWORD **v5; // rax

  v3 = numBytes;
  v4 = p;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*v5[10] + 32i64))(v5[10], v4, v3);
}

// File Line: 16
// RVA: 0xC65B70
__int64 __fastcall hkContainerTempAllocator::Allocator::bufRealloc(hkContainerTempAllocator::Allocator *this, void *pold, int oldNumBytes, int *reqNumBytesInOut)
{
  int *v4; // rbx
  unsigned int v5; // edi
  void *v6; // rsi
  _QWORD **v7; // rax

  v4 = reqNumBytesInOut;
  v5 = oldNumBytes;
  v6 = pold;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, void *, _QWORD, int *))(*v7[10] + 40i64))(v7[10], v6, v5, v4);
}

// File Line: 17
// RVA: 0xC65BC0
void __fastcall hkContainerTempAllocator::Allocator::getMemoryStatistics(hkContainerTempAllocator::Allocator *this, hkMemoryAllocator::MemoryStatistics *u)
{
  hkMemoryAllocator::MemoryStatistics *v2; // rbx
  _QWORD **v3; // rax

  v2 = u;
  v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkMemoryAllocator::MemoryStatistics *))(*v3[10] + 64i64))(v3[10], v2);
}

// File Line: 18
// RVA: 0xC65BF0
__int64 __fastcall hkContainerTempAllocator::Allocator::getAllocatedSize(hkContainerTempAllocator::Allocator *this, const void *obj, int nbytes)
{
  unsigned int v3; // ebx
  const void *v4; // rdi
  _QWORD **v5; // rax

  v3 = nbytes;
  v4 = obj;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, const void *, _QWORD))(*v5[10] + 72i64))(v5[10], v4, v3);
}

// File Line: 19
// RVA: 0x15C7620
__int64 dynamic_initializer_for__hkContainerTempAllocator::s_alloc__()
{
  return atexit(dynamic_atexit_destructor_for__hkContainerTempAllocator::s_alloc__);
}

// File Line: 21
// RVA: 0xC65DD0
__int64 __fastcall hkContainerDebugAllocator::Allocator::blockAlloc(hkContainerDebugAllocator::Allocator *this, int numBytes)
{
  unsigned int v2; // ebx
  _QWORD **v3; // rax

  v2 = numBytes;
  v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v3[12] + 8i64))(v3[12], v2);
}

// File Line: 22
// RVA: 0xC65E00
void __fastcall hkContainerDebugAllocator::Allocator::blockFree(hkContainerDebugAllocator::Allocator *this, void *p, int numBytes)
{
  unsigned int v3; // ebx
  void *v4; // rdi
  _QWORD **v5; // rax

  v3 = numBytes;
  v4 = p;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*v5[12] + 16i64))(v5[12], v4, v3);
}

// File Line: 23
// RVA: 0xC65E40
__int64 __fastcall hkContainerDebugAllocator::Allocator::bufAlloc(hkContainerDebugAllocator::Allocator *this, int *reqNumBytesInOut)
{
  int *v2; // rbx
  _QWORD **v3; // rax

  v2 = reqNumBytesInOut;
  v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, int *))(*v3[12] + 24i64))(v3[12], v2);
}

// File Line: 24
// RVA: 0xC65E70
void __fastcall hkContainerDebugAllocator::Allocator::bufFree(hkContainerDebugAllocator::Allocator *this, void *p, int numBytes)
{
  unsigned int v3; // ebx
  void *v4; // rdi
  _QWORD **v5; // rax

  v3 = numBytes;
  v4 = p;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*v5[12] + 32i64))(v5[12], v4, v3);
}

// File Line: 25
// RVA: 0xC65EB0
__int64 __fastcall hkContainerDebugAllocator::Allocator::bufRealloc(hkContainerDebugAllocator::Allocator *this, void *pold, int oldNumBytes, int *reqNumBytesInOut)
{
  int *v4; // rbx
  unsigned int v5; // edi
  void *v6; // rsi
  _QWORD **v7; // rax

  v4 = reqNumBytesInOut;
  v5 = oldNumBytes;
  v6 = pold;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, void *, _QWORD, int *))(*v7[12] + 40i64))(v7[12], v6, v5, v4);
}

// File Line: 26
// RVA: 0xC65F00
void __fastcall hkContainerDebugAllocator::Allocator::getMemoryStatistics(hkContainerDebugAllocator::Allocator *this, hkMemoryAllocator::MemoryStatistics *u)
{
  hkMemoryAllocator::MemoryStatistics *v2; // rbx
  _QWORD **v3; // rax

  v2 = u;
  v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkMemoryAllocator::MemoryStatistics *))(*v3[12] + 64i64))(v3[12], v2);
}

// File Line: 27
// RVA: 0xC65F30
__int64 __fastcall hkContainerDebugAllocator::Allocator::getAllocatedSize(hkContainerDebugAllocator::Allocator *this, const void *obj, int nbytes)
{
  unsigned int v3; // ebx
  const void *v4; // rdi
  _QWORD **v5; // rax

  v3 = nbytes;
  v4 = obj;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, const void *, _QWORD))(*v5[12] + 72i64))(v5[12], v4, v3);
}

// File Line: 28
// RVA: 0x15C7600
__int64 dynamic_initializer_for__hkContainerDebugAllocator::s_alloc__()
{
  return atexit(dynamic_atexit_destructor_for__hkContainerDebugAllocator::s_alloc__);
}

// File Line: 30
// RVA: 0xC65C30
__int64 __fastcall hkContainerHeapAllocator::Allocator::blockAlloc(hkContainerHeapAllocator::Allocator *this, int numBytes)
{
  unsigned int v2; // ebx
  _QWORD **v3; // rax

  v2 = numBytes;
  v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v3[11] + 8i64))(v3[11], v2);
}

// File Line: 31
// RVA: 0xC65C60
void __fastcall hkContainerHeapAllocator::Allocator::blockFree(hkContainerHeapAllocator::Allocator *this, void *p, int numBytes)
{
  unsigned int v3; // ebx
  void *v4; // rdi
  _QWORD **v5; // rax

  v3 = numBytes;
  v4 = p;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*v5[11] + 16i64))(v5[11], v4, v3);
}

// File Line: 32
// RVA: 0xC65CA0
__int64 __fastcall hkContainerHeapAllocator::Allocator::bufAlloc(hkContainerHeapAllocator::Allocator *this, int *reqNumBytesInOut)
{
  int *v2; // rbx
  _QWORD **v3; // rax

  v2 = reqNumBytesInOut;
  v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, int *))(*v3[11] + 24i64))(v3[11], v2);
}

// File Line: 33
// RVA: 0xC65CD0
void __fastcall hkContainerHeapAllocator::Allocator::bufFree(hkContainerHeapAllocator::Allocator *this, void *p, int numBytes)
{
  unsigned int v3; // ebx
  void *v4; // rdi
  _QWORD **v5; // rax

  v3 = numBytes;
  v4 = p;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*v5[11] + 32i64))(v5[11], v4, v3);
}

// File Line: 34
// RVA: 0xC65D10
__int64 __fastcall hkContainerHeapAllocator::Allocator::bufRealloc(hkContainerHeapAllocator::Allocator *this, void *pold, int oldNumBytes, int *reqNumBytesInOut)
{
  int *v4; // rbx
  unsigned int v5; // edi
  void *v6; // rsi
  _QWORD **v7; // rax

  v4 = reqNumBytesInOut;
  v5 = oldNumBytes;
  v6 = pold;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, void *, _QWORD, int *))(*v7[11] + 40i64))(v7[11], v6, v5, v4);
}

// File Line: 35
// RVA: 0xC65D60
void __fastcall hkContainerHeapAllocator::Allocator::getMemoryStatistics(hkContainerHeapAllocator::Allocator *this, hkMemoryAllocator::MemoryStatistics *u)
{
  hkMemoryAllocator::MemoryStatistics *v2; // rbx
  _QWORD **v3; // rax

  v2 = u;
  v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkMemoryAllocator::MemoryStatistics *))(*v3[11] + 64i64))(v3[11], v2);
}

// File Line: 36
// RVA: 0xC65D90
__int64 __fastcall hkContainerHeapAllocator::Allocator::getAllocatedSize(hkContainerHeapAllocator::Allocator *this, const void *obj, int nbytes)
{
  unsigned int v3; // ebx
  const void *v4; // rdi
  _QWORD **v5; // rax

  v3 = nbytes;
  v4 = obj;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, const void *, _QWORD))(*v5[11] + 72i64))(v5[11], v4, v3);
}

// File Line: 37
// RVA: 0x15C7610
__int64 dynamic_initializer_for__hkContainerHeapAllocator::s_alloc__()
{
  return atexit(dynamic_atexit_destructor_for__hkContainerHeapAllocator::s_alloc__);
}

// File Line: 39
// RVA: 0xC65F70
hkMemoryAllocator *__fastcall hkContainerDefaultMallocAllocator::get(hkContainerDefaultMallocAllocator *this, const void *__formal)
{
  return hkMallocAllocator::m_defaultMallocAllocator;
}

