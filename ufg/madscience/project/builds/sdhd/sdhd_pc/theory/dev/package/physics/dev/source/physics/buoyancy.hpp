// File Line: 39
// RVA: 0x9E020
void __fastcall hkpPhantomCallbackShape::operator delete(_WORD *p, unsigned __int64 nbytes)
{
  unsigned __int16 v2; // ax
  unsigned int v4; // ebx
  _QWORD **Value; // rax

  v2 = p[4];
  v4 = nbytes;
  if ( v2 != 0xFFFF )
    v4 = v2;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, _WORD *, _QWORD))(*Value[11] + 16i64))(Value[11], p, v4);
}

