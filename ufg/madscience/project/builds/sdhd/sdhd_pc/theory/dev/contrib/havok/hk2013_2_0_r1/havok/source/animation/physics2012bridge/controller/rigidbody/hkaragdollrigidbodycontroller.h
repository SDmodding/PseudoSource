// File Line: 24
// RVA: 0x9DFE0
void __fastcall hkpCollidable::operator delete(void *p, unsigned __int64 nbytes)
{
  void *v2; // rbx
  _QWORD **v3; // rax

  if ( p )
  {
    v2 = p;
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, void *, signed __int64))(*v3[11] + 16i64))(v3[11], v2, 112i64);
  }
}
