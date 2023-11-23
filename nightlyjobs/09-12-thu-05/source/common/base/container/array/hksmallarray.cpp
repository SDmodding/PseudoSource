// File Line: 22
// RVA: 0x12FE6B0
void __fastcall hkSmallArrayUtil::_reserve(const void **array, int numElem, int sizeElem)
{
  _QWORD **Value; // rax
  void *v7; // r14
  __int16 v8; // si
  unsigned int v9; // esi
  const void *v10; // rbx
  _QWORD **v11; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (void *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*Value[11] + 8i64))(
                 Value[11],
                 (unsigned int)(sizeElem * numElem));
  memmove(v7, *array, sizeElem * *((unsigned __int16 *)array + 4));
  v8 = *((_WORD *)array + 5);
  if ( v8 >= 0 )
  {
    v9 = sizeElem * (v8 & 0x3FFF);
    v10 = *array;
    v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, const void *, _QWORD))(*v11[11] + 16i64))(v11[11], v10, v9);
  }
  *((_WORD *)array + 5) &= 0x4000u;
  *((_WORD *)array + 5) |= numElem;
  *array = v7;
}

// File Line: 45
// RVA: 0x12FE770
void __fastcall hkSmallArrayUtil::_reserveMore(const void **array, int sizeElem)
{
  unsigned __int16 v2; // ax
  int v5; // esi
  _QWORD **Value; // rax
  void *v7; // r14
  __int16 v8; // bp
  unsigned int v9; // ebp
  const void *v10; // rbx
  _QWORD **v11; // rax

  v2 = *((_WORD *)array + 4);
  if ( v2 )
    v5 = 2 * v2;
  else
    v5 = 1;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (void *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*Value[11] + 8i64))(
                 Value[11],
                 (unsigned int)(sizeElem * v5));
  memmove(v7, *array, sizeElem * *((unsigned __int16 *)array + 4));
  v8 = *((_WORD *)array + 5);
  if ( v8 >= 0 )
  {
    v9 = sizeElem * (v8 & 0x3FFF);
    v10 = *array;
    v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, const void *, _QWORD))(*v11[11] + 16i64))(v11[11], v10, v9);
  }
  *((_WORD *)array + 5) &= 0x4000u;
  *((_WORD *)array + 5) |= v5;
  *array = v7;
}

