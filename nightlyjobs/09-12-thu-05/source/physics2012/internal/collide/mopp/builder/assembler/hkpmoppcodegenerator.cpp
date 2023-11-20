// File Line: 23
// RVA: 0xDFA8C0
void __fastcall hkpMoppCodeGenerator::hkpMoppCodeGenerator(hkpMoppCodeGenerator *this, int size)
{
  hkpMoppCodeGenerator *v2; // rdi
  unsigned int v3; // ebx
  _QWORD **v4; // rax
  __int64 v5; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppCodeGenerator::`vftable';
  this->m_jumpCommands.m_data = 0i64;
  this->m_jumpCommands.m_size = 0;
  this->m_jumpCommands.m_capacityAndFlags = 2147483648;
  v3 = size;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v4[10] + 8i64))(v4[10], v3);
  v2->m_size = v3;
  v2->m_code = (char *)v5;
  v2->m_pos = 0;
}

// File Line: 33
// RVA: 0xDFA930
void __fastcall hkpMoppCodeGenerator::~hkpMoppCodeGenerator(hkpMoppCodeGenerator *this)
{
  char *v1; // rsi
  hkpMoppCodeGenerator *v2; // rdi
  unsigned int v3; // ebx
  _QWORD **v4; // rax
  int v5; // er8

  v1 = this->m_code;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppCodeGenerator::`vftable';
  if ( v1 )
  {
    v3 = this->m_size;
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v4[10] + 16i64))(v4[10], v1, v3);
  }
  v5 = v2->m_jumpCommands.m_capacityAndFlags;
  v2->m_jumpCommands.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_jumpCommands.m_data,
      8 * v5);
  v2->m_jumpCommands.m_data = 0i64;
  v2->m_jumpCommands.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 39
// RVA: 0xDFAB50
void __fastcall hkpMoppCodeGenerator::resize(hkpMoppCodeGenerator *this)
{
  hkpMoppCodeGenerator *v1; // rbp
  unsigned int v2; // ebx
  _QWORD **v3; // rax
  char *v4; // rsi
  unsigned int v5; // ebx
  char *v6; // rdi
  _QWORD **v7; // rax
  int v8; // eax

  v1 = this;
  v2 = 2 * this->m_size;
  v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (char *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v3[10] + 8i64))(v3[10], v2);
  hkString::memSet(v4, 205, v1->m_size);
  hkString::memCpy(&v4[v1->m_size], v1->m_code, v1->m_size);
  v5 = v1->m_size;
  v6 = v1->m_code;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v7[10] + 16i64))(v7[10], v6, v5);
  v8 = v1->m_size;
  v1->m_code = v4;
  v1->m_size = 2 * v8;
}

// File Line: 58
// RVA: 0xDFA9D0
hkpMoppCode *__fastcall hkpMoppCodeGenerator::compileCode(hkpMoppCodeGenerator *this)
{
  __int64 v1; // r15
  hkpMoppCodeGenerator *v2; // r14
  _QWORD **v3; // rax
  __int64 v4; // rax
  hkpMoppCode *v5; // rsi
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // er9
  unsigned int v10; // ebx
  char *v11; // rdi
  _QWORD **v12; // rax
  hkpMoppCode *v13; // rax
  hkResult result; // [rsp+50h] [rbp+8h]

  v1 = this->m_pos;
  v2 = this;
  v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v3[11] + 8i64))(v3[11], 64i64);
  v5 = (hkpMoppCode *)v4;
  if ( v4 )
  {
    *(_DWORD *)(v4 + 8) = 0x1FFFF;
    *(_QWORD *)v4 = &hkpMoppCode::`vftable';
    *(_QWORD *)(v4 + 32) = 0i64;
    *(_DWORD *)(v4 + 40) = 0;
    *(_DWORD *)(v4 + 44) = 2147483648;
    *(_BYTE *)(v4 + 48) = 2;
    *(_OWORD *)(v4 + 16) = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = v1 + 3;
  if ( (v5->m_data.m_capacityAndFlags & 0x3FFFFFFF) < (signed int)v1 + 3 )
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v5->m_data, v6, 1);
  v7 = v5->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v6 )
  {
    v8 = 2 * v7;
    v9 = v1 + 3;
    if ( v6 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v5->m_data, v9, 1);
  }
  v5->m_data.m_size = v6;
  hkString::memCpy(v5->m_data.m_data, &v2->m_code[v2->m_size - v2->m_pos], v1);
  hkString::memSet(&v5->m_data.m_data[v1], 205, 3);
  v10 = v2->m_size;
  v11 = v2->m_code;
  v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v12[10] + 16i64))(v12[10], v11, v10);
  v13 = v5;
  v2->m_code = 0i64;
  v2->m_pos = 0;
  v2->m_size = v1;
  return v13;
}

// File Line: 81
// RVA: 0xDFAB40
void __fastcall hkpMoppCodeGenerator::validateJumpCommands(hkpMoppCodeGenerator *this)
{
  ;
}

