// File Line: 15
// RVA: 0xEE2718
__int64 __fastcall OSuite::ZObject::operator new(unsigned __int64 nSize)
{
  return OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, nSize, 0i64);
}

// File Line: 25
// RVA: 0xEE272C
void __fastcall OSuite::ZObject::operator delete[](void *ptr)
{
  OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, ptr);
}

// File Line: 57
// RVA: 0xEE2750
__int64 __fastcall OSuite::ZObject::malloc(OSuite::ZObject *this, unsigned __int64 size, char *pTag)
{
  return OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, size, pTag);
}

// File Line: 67
// RVA: 0xEE2740
void __fastcall OSuite::ZObject::free(OSuite::ZObject *this, void *ptr)
{
  OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, ptr);
}

// File Line: 90
// RVA: 0xEE2760
__int64 __fastcall online_suite_malloc(unsigned __int64 size, char *pTag)
{
  return OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, size, pTag);
}

// File Line: 95
// RVA: 0xEE2778
void *__fastcall online_suite_realloc(void *ptr, unsigned __int64 size, char *pTag)
{
  return OSuite::ZObject::m_allocator->vfptr->realloc(OSuite::ZObject::m_allocator, ptr, size, pTag);
}

