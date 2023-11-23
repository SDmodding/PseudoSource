// File Line: 24
// RVA: 0x9DFE0
void __fastcall hkpCollidable::operator delete(void *p, unsigned __int64 nbytes)
{
  _QWORD **Value; // rax

  if ( p )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, void *, __int64))(*Value[11] + 16i64))(Value[11], p, 112i64);
  }
}

