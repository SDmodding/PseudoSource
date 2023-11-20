// File Line: 39
// RVA: 0x9E020
void __fastcall hkpPhantomCallbackShape::operator delete(void *p, unsigned __int64 nbytes)
{
  unsigned __int16 v2; // ax
  void *v3; // rdi
  unsigned int v4; // ebx
  _QWORD **v5; // rax

  v2 = *((_WORD *)p + 4);
  v3 = p;
  v4 = nbytes;
  if ( v2 != -1 )
    v4 = v2;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*v5[11] + 16i64))(v5[11], v3, v4);
}

