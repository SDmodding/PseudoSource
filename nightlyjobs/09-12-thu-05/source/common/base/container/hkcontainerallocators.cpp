// File Line: 12
// RVA: 0xC65A90
__int64 __fastcall hkContainerTempAllocator::Allocator::blockAlloc(
        hkContainerTempAllocator::Allocator *this,
        unsigned int numBytes)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*Value[10] + 8i64))(Value[10], numBytes);
}

// File Line: 13
// RVA: 0xC65AC0
void __fastcall hkContainerTempAllocator::Allocator::blockFree(
        hkContainerTempAllocator::Allocator *this,
        void *p,
        unsigned int numBytes)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*Value[10] + 16i64))(Value[10], p, numBytes);
}

// File Line: 14
// RVA: 0xC65B00
__int64 __fastcall hkContainerTempAllocator::Allocator::bufAlloc(
        hkContainerTempAllocator::Allocator *this,
        int *reqNumBytesInOut)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, int *))(*Value[10] + 24i64))(Value[10], reqNumBytesInOut);
}

// File Line: 15
// RVA: 0xC65B30
void __fastcall hkContainerTempAllocator::Allocator::bufFree(
        hkContainerTempAllocator::Allocator *this,
        void *p,
        unsigned int numBytes)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*Value[10] + 32i64))(Value[10], p, numBytes);
}

// File Line: 16
// RVA: 0xC65B70
__int64 __fastcall hkContainerTempAllocator::Allocator::bufRealloc(
        hkContainerTempAllocator::Allocator *this,
        void *pold,
        unsigned int oldNumBytes,
        int *reqNumBytesInOut)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, void *, _QWORD, int *))(*Value[10] + 40i64))(
           Value[10],
           pold,
           oldNumBytes,
           reqNumBytesInOut);
}

// File Line: 17
// RVA: 0xC65BC0
void __fastcall hkContainerTempAllocator::Allocator::getMemoryStatistics(
        hkContainerTempAllocator::Allocator *this,
        hkMemoryAllocator::MemoryStatistics *u)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkMemoryAllocator::MemoryStatistics *))(*Value[10] + 64i64))(Value[10], u);
}

// File Line: 18
// RVA: 0xC65BF0
__int64 __fastcall hkContainerTempAllocator::Allocator::getAllocatedSize(
        hkContainerTempAllocator::Allocator *this,
        const void *obj,
        unsigned int nbytes)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, const void *, _QWORD))(*Value[10] + 72i64))(Value[10], obj, nbytes);
}

// File Line: 19
// RVA: 0x15C7620
__int64 dynamic_initializer_for__hkContainerTempAllocator::s_alloc__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__hkContainerTempAllocator::s_alloc__);
}

// File Line: 21
// RVA: 0xC65DD0
__int64 __fastcall hkContainerDebugAllocator::Allocator::blockAlloc(
        hkContainerDebugAllocator::Allocator *this,
        unsigned int numBytes)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*Value[12] + 8i64))(Value[12], numBytes);
}

// File Line: 22
// RVA: 0xC65E00
void __fastcall hkContainerDebugAllocator::Allocator::blockFree(
        hkContainerDebugAllocator::Allocator *this,
        void *p,
        unsigned int numBytes)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*Value[12] + 16i64))(Value[12], p, numBytes);
}

// File Line: 23
// RVA: 0xC65E40
__int64 __fastcall hkContainerDebugAllocator::Allocator::bufAlloc(
        hkContainerDebugAllocator::Allocator *this,
        int *reqNumBytesInOut)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, int *))(*Value[12] + 24i64))(Value[12], reqNumBytesInOut);
}

// File Line: 24
// RVA: 0xC65E70
void __fastcall hkContainerDebugAllocator::Allocator::bufFree(
        hkContainerDebugAllocator::Allocator *this,
        void *p,
        unsigned int numBytes)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*Value[12] + 32i64))(Value[12], p, numBytes);
}

// File Line: 25
// RVA: 0xC65EB0
__int64 __fastcall hkContainerDebugAllocator::Allocator::bufRealloc(
        hkContainerDebugAllocator::Allocator *this,
        void *pold,
        unsigned int oldNumBytes,
        int *reqNumBytesInOut)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, void *, _QWORD, int *))(*Value[12] + 40i64))(
           Value[12],
           pold,
           oldNumBytes,
           reqNumBytesInOut);
}

// File Line: 26
// RVA: 0xC65F00
void __fastcall hkContainerDebugAllocator::Allocator::getMemoryStatistics(
        hkContainerDebugAllocator::Allocator *this,
        hkMemoryAllocator::MemoryStatistics *u)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkMemoryAllocator::MemoryStatistics *))(*Value[12] + 64i64))(Value[12], u);
}

// File Line: 27
// RVA: 0xC65F30
__int64 __fastcall hkContainerDebugAllocator::Allocator::getAllocatedSize(
        hkContainerDebugAllocator::Allocator *this,
        const void *obj,
        unsigned int nbytes)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, const void *, _QWORD))(*Value[12] + 72i64))(Value[12], obj, nbytes);
}

// File Line: 28
// RVA: 0x15C7600
__int64 dynamic_initializer_for__hkContainerDebugAllocator::s_alloc__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__hkContainerDebugAllocator::s_alloc__);
}

// File Line: 30
// RVA: 0xC65C30
__int64 __fastcall hkContainerHeapAllocator::Allocator::blockAlloc(
        hkContainerHeapAllocator::Allocator *this,
        unsigned int numBytes)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*Value[11] + 8i64))(Value[11], numBytes);
}

// File Line: 31
// RVA: 0xC65C60
void __fastcall hkContainerHeapAllocator::Allocator::blockFree(
        hkContainerHeapAllocator::Allocator *this,
        void *p,
        unsigned int numBytes)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*Value[11] + 16i64))(Value[11], p, numBytes);
}

// File Line: 32
// RVA: 0xC65CA0
__int64 __fastcall hkContainerHeapAllocator::Allocator::bufAlloc(
        hkContainerHeapAllocator::Allocator *this,
        int *reqNumBytesInOut)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, int *))(*Value[11] + 24i64))(Value[11], reqNumBytesInOut);
}

// File Line: 33
// RVA: 0xC65CD0
void __fastcall hkContainerHeapAllocator::Allocator::bufFree(
        hkContainerHeapAllocator::Allocator *this,
        void *p,
        unsigned int numBytes)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*Value[11] + 32i64))(Value[11], p, numBytes);
}

// File Line: 34
// RVA: 0xC65D10
__int64 __fastcall hkContainerHeapAllocator::Allocator::bufRealloc(
        hkContainerHeapAllocator::Allocator *this,
        void *pold,
        unsigned int oldNumBytes,
        int *reqNumBytesInOut)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, void *, _QWORD, int *))(*Value[11] + 40i64))(
           Value[11],
           pold,
           oldNumBytes,
           reqNumBytesInOut);
}

// File Line: 35
// RVA: 0xC65D60
void __fastcall hkContainerHeapAllocator::Allocator::getMemoryStatistics(
        hkContainerHeapAllocator::Allocator *this,
        hkMemoryAllocator::MemoryStatistics *u)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkMemoryAllocator::MemoryStatistics *))(*Value[11] + 64i64))(Value[11], u);
}

// File Line: 36
// RVA: 0xC65D90
__int64 __fastcall hkContainerHeapAllocator::Allocator::getAllocatedSize(
        hkContainerHeapAllocator::Allocator *this,
        const void *obj,
        unsigned int nbytes)
{
  _QWORD **Value; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  return (*(__int64 (__fastcall **)(_QWORD *, const void *, _QWORD))(*Value[11] + 72i64))(Value[11], obj, nbytes);
}

// File Line: 37
// RVA: 0x15C7610
__int64 dynamic_initializer_for__hkContainerHeapAllocator::s_alloc__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__hkContainerHeapAllocator::s_alloc__);
}

// File Line: 39
// RVA: 0xC65F70
hkMemoryAllocator *__fastcall hkContainerDefaultMallocAllocator::get(
        hkContainerDefaultMallocAllocator *this,
        const void *__formal)
{
  return hkMallocAllocator::m_defaultMallocAllocator;
}

