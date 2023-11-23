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
  _QWORD **Value; // rax

  if ( p )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, void *, __int64))(*Value[11] + 16i64))(Value[11], p, 1024i64);
  }
}

