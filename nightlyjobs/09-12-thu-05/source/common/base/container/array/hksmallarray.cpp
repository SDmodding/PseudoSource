// File Line: 22
// RVA: 0x12FE6B0
void __fastcall hkSmallArrayUtil::_reserve(void *array, int numElem, int sizeElem)
{
  const void **v3; // rdi
  int v4; // ebx
  int v5; // ebp
  _QWORD **v6; // rax
  void *v7; // r14
  __int16 v8; // si
  unsigned int v9; // esi
  const void *v10; // rbx
  _QWORD **v11; // rax

  v3 = (const void **)array;
  v4 = sizeElem;
  v5 = numElem;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (void *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v6[11] + 8i64))(v6[11], (unsigned int)(v4 * v5));
  memmove(v7, *v3, v4 * *((unsigned __int16 *)v3 + 4));
  v8 = *((_WORD *)v3 + 5);
  if ( v8 >= 0 )
  {
    v9 = v4 * (v8 & 0x3FFF);
    v10 = *v3;
    v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, const void *, _QWORD))(*v11[11] + 16i64))(v11[11], v10, v9);
  }
  *((_WORD *)v3 + 5) &= 0x4000u;
  *((_WORD *)v3 + 5) |= v5;
  *v3 = v7;
}

// File Line: 45
// RVA: 0x12FE770
void __fastcall hkSmallArrayUtil::_reserveMore(void *array, int sizeElem)
{
  unsigned __int16 v2; // ax
  int v3; // ebx
  const void **v4; // rdi
  int v5; // esi
  _QWORD **v6; // rax
  void *v7; // r14
  __int16 v8; // bp
  unsigned int v9; // ebp
  const void *v10; // rbx
  _QWORD **v11; // rax

  v2 = *((_WORD *)array + 4);
  v3 = sizeElem;
  v4 = (const void **)array;
  if ( v2 )
    v5 = 2 * v2;
  else
    v5 = 1;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (void *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v6[11] + 8i64))(v6[11], (unsigned int)(v3 * v5));
  memmove(v7, *v4, v3 * *((unsigned __int16 *)v4 + 4));
  v8 = *((_WORD *)v4 + 5);
  if ( v8 >= 0 )
  {
    v9 = v3 * (v8 & 0x3FFF);
    v10 = *v4;
    v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, const void *, _QWORD))(*v11[11] + 16i64))(v11[11], v10, v9);
  }
  *((_WORD *)v4 + 5) &= 0x4000u;
  *((_WORD *)v4 + 5) |= v5;
  *v4 = v7;
}

