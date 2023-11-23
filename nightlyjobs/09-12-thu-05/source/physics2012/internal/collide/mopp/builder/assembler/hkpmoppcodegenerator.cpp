// File Line: 23
// RVA: 0xDFA8C0
void __fastcall hkpMoppCodeGenerator::hkpMoppCodeGenerator(hkpMoppCodeGenerator *this, unsigned int size)
{
  _QWORD **Value; // rax
  char *v5; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppCodeGenerator::`vftable;
  this->m_jumpCommands.m_data = 0i64;
  this->m_jumpCommands.m_size = 0;
  this->m_jumpCommands.m_capacityAndFlags = 0x80000000;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (char *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*Value[10] + 8i64))(Value[10], size);
  this->m_size = size;
  this->m_code = v5;
  this->m_pos = 0;
}

// File Line: 33
// RVA: 0xDFA930
void __fastcall hkpMoppCodeGenerator::~hkpMoppCodeGenerator(hkpMoppCodeGenerator *this)
{
  char *m_code; // rsi
  unsigned int m_size; // ebx
  _QWORD **Value; // rax
  int m_capacityAndFlags; // r8d

  m_code = this->m_code;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppCodeGenerator::`vftable;
  if ( m_code )
  {
    m_size = this->m_size;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*Value[10] + 16i64))(Value[10], m_code, m_size);
  }
  m_capacityAndFlags = this->m_jumpCommands.m_capacityAndFlags;
  this->m_jumpCommands.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_jumpCommands.m_data,
      8 * m_capacityAndFlags);
  this->m_jumpCommands.m_data = 0i64;
  this->m_jumpCommands.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 39
// RVA: 0xDFAB50
void __fastcall hkpMoppCodeGenerator::resize(hkpMoppCodeGenerator *this)
{
  unsigned int v2; // ebx
  _QWORD **Value; // rax
  char *v4; // rsi
  unsigned int m_size; // ebx
  char *m_code; // rdi
  _QWORD **v7; // rax
  int v8; // eax

  v2 = 2 * this->m_size;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (char *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*Value[10] + 8i64))(Value[10], v2);
  hkString::memSet(v4, 205, this->m_size);
  hkString::memCpy(&v4[this->m_size], this->m_code, this->m_size);
  m_size = this->m_size;
  m_code = this->m_code;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v7[10] + 16i64))(v7[10], m_code, m_size);
  v8 = this->m_size;
  this->m_code = v4;
  this->m_size = 2 * v8;
}

// File Line: 58
// RVA: 0xDFA9D0
hkpMoppCode *__fastcall hkpMoppCodeGenerator::compileCode(hkpMoppCodeGenerator *this)
{
  __int64 m_pos; // r15
  _QWORD **Value; // rax
  __int64 v4; // rax
  hkpMoppCode *v5; // rsi
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // r9d
  unsigned int m_size; // ebx
  char *m_code; // rdi
  _QWORD **v12; // rax
  hkpMoppCode *v13; // rax
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  m_pos = this->m_pos;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 64i64);
  v5 = (hkpMoppCode *)v4;
  if ( v4 )
  {
    *(_DWORD *)(v4 + 8) = 0x1FFFF;
    *(_QWORD *)v4 = &hkpMoppCode::`vftable;
    *(_QWORD *)(v4 + 32) = 0i64;
    *(_DWORD *)(v4 + 40) = 0;
    *(_DWORD *)(v4 + 44) = 0x80000000;
    *(_BYTE *)(v4 + 48) = 2;
    *(_OWORD *)(v4 + 16) = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = m_pos + 3;
  if ( (v5->m_data.m_capacityAndFlags & 0x3FFFFFFF) < (int)m_pos + 3 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v5->m_data.m_data, v6, 1);
  v7 = v5->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v6 )
  {
    v8 = 2 * v7;
    v9 = m_pos + 3;
    if ( v6 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v5->m_data.m_data, v9, 1);
  }
  v5->m_data.m_size = v6;
  hkString::memCpy(v5->m_data.m_data, &this->m_code[this->m_size - this->m_pos], m_pos);
  hkString::memSet(&v5->m_data.m_data[m_pos], 205, 3u);
  m_size = this->m_size;
  m_code = this->m_code;
  v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v12[10] + 16i64))(v12[10], m_code, m_size);
  v13 = v5;
  this->m_code = 0i64;
  this->m_pos = 0;
  this->m_size = m_pos;
  return v13;
}

// File Line: 81
// RVA: 0xDFAB40
void __fastcall hkpMoppCodeGenerator::validateJumpCommands(hkpMoppCodeGenerator *this)
{
  ;
}

