// File Line: 79
// RVA: 0x9D7B0
void __fastcall hkExternalJobProfiler::~hkExternalJobProfiler(hkExternalJobProfiler *this)
{
  this->vfptr = (hkExternalJobProfilerVtbl *)&hkExternalJobProfiler::`vftable;
}

// File Line: 155
// RVA: 0x9DF60
void __fastcall hkJobQueue::operator delete(void *p, unsigned __int64 nbytes)
{
  void *v2; // rbx
  _QWORD **v3; // rax

  if ( p )
  {
    v2 = p;
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, void *, signed __int64))(*v3[11] + 16i64))(v3[11], v2, 1024i64);
  }
}

