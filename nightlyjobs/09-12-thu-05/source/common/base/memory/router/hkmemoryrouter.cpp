// File Line: 25
// RVA: 0x15C75A0
__int64 dynamic_initializer_for__hkMemoryRouter::s_memoryRouter__()
{
  hkMemoryRouter::s_memoryRouter.m_slotID = TlsAlloc();
  return atexit(dynamic_atexit_destructor_for__hkMemoryRouter::s_memoryRouter__);
}

// File Line: 28
// RVA: 0xC56830
void __fastcall hkMemoryRouter::replaceInstance(hkMemoryRouter *a)
{
  TlsSetValue(hkMemoryRouter::s_memoryRouter.m_slotID, a);
}

// File Line: 38
// RVA: 0xC56850
void __fastcall hkMemoryRouter::hkMemoryRouter(hkMemoryRouter *this)
{
  hkMemoryRouter *v1; // rbx

  v1 = this;
  hkLifoAllocator::hkLifoAllocator(&this->m_stack, 0x8000);
  v1->m_temp = 0i64;
  v1->m_heap = 0i64;
  v1->m_debug = 0i64;
  v1->m_solver = 0i64;
  v1->m_refObjLocalStore = 0;
}

// File Line: 42
// RVA: 0xC568D0
_QWORD *__fastcall hkMemoryRouter::alignedAlloc(hkMemoryAllocator *b, int nbytes, int alignment)
{
  __int64 v3; // rbx
  hkMemoryAllocator *v4; // rsi
  int v5; // edi
  __int64 v6; // rax
  int v7; // er8
  _QWORD *result; // rax

  v3 = alignment;
  v4 = b;
  v5 = nbytes + alignment;
  v6 = (*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&b->vfptr->__vecDelDtor + 1))(
         b,
         (unsigned int)(nbytes + alignment + 16));
  v7 = v6;
  result = (_QWORD *)(~(v3 - 1) & (v6 + (signed int)v3 - 1 + 16i64));
  *(result - 2) = v4;
  *((_DWORD *)result - 1) = (_DWORD)result - v7;
  *((_DWORD *)result - 2) = v5;
  return result;
}

// File Line: 63
// RVA: 0xC56930
void __fastcall hkMemoryRouter::alignedFree(hkMemoryAllocator *b, void *p)
{
  int v2; // er8
  __int64 v3; // rax

  if ( p )
  {
    v2 = *((_DWORD *)p - 2);
    v3 = *((signed int *)p - 1);
    *((_QWORD *)p - 2) = 0i64;
    b->vfptr->blockFree(b, (char *)p - v3, v2 + 16);
  }
}

// File Line: 74
// RVA: 0xC56960
signed __int64 __fastcall hkMemoryRouter::easyAlloc(hkMemoryAllocator *b, int nbytes)
{
  int v2; // edi
  hkMemoryAllocator *v3; // rbx
  __int64 v4; // rax

  v2 = nbytes;
  v3 = b;
  v4 = (*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&b->vfptr->__vecDelDtor + 1))(
         b,
         (unsigned int)(nbytes + 16));
  *(_QWORD *)v4 = v3;
  *(_DWORD *)(v4 + 8) = v2;
  return v4 + 16;
}

// File Line: 82
// RVA: 0xC569A0
unsigned __int64 __fastcall hkMemoryRouter::getEasyAllocSize(hkMemoryAllocator *b, const void *ptr)
{
  return *((signed int *)ptr - 2);
}

// File Line: 88
// RVA: 0xC569B0
char *__fastcall hkMemoryRouter::getEasyAllocStartAddress(hkMemoryAllocator *b, const void *ptr)
{
  return (char *)ptr - 16;
}

// File Line: 94
// RVA: 0xC569C0
void __fastcall hkMemoryRouter::easyFree(hkMemoryAllocator *b, void *p)
{
  int v2; // er8
  _QWORD *v3; // rdx

  if ( p )
  {
    v2 = *((_DWORD *)p - 2);
    v3 = (char *)p - 16;
    *v3 = 0i64;
    b->vfptr->blockFree(b, v3, v2 + 16);
  }
}

// File Line: 104
// RVA: 0xC56890
void __fastcall hkMemoryRouter::resetPeakMemoryStatistics(hkMemoryRouter *this)
{
  hkMemoryRouter *v1; // rbx

  v1 = this;
  ((void (*)(void))this->m_debug->vfptr->resetPeakMemoryStatistics)();
  ((void (*)(void))v1->m_heap->vfptr->resetPeakMemoryStatistics)();
  ((void (*)(void))v1->m_solver->vfptr->resetPeakMemoryStatistics)();
  ((void (*)(void))v1->m_temp->vfptr->resetPeakMemoryStatistics)();
}

