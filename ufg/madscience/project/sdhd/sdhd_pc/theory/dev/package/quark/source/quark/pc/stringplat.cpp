// File Line: 29
// RVA: 0xA3A300
int __fastcall UFG::qMemCompare(const void *source_a, const void *source_b, unsigned int count)
{
  return memcmp(source_a, source_b, count);
}

// File Line: 34
// RVA: 0xA3A310
void __fastcall UFG::qMemCopy(void *dest, const void *source, unsigned int count)
{
  memmove(dest, source, count);
}

// File Line: 39
// RVA: 0xA3A320
void __fastcall UFG::qMemSet(void *dest, int pattern, unsigned int count)
{
  memset(dest, pattern, count);
}

// File Line: 45
// RVA: 0xA39FF0
bool __fastcall UFG::qIsMemoryValidForRead(char *ptr)
{
  _MEMORY_BASIC_INFORMATION Buffer; // [rsp+20h] [rbp-38h] BYREF

  return !UFG::qMemoryPool::msPageFaultCorruptionDetectorActive
      || UFG::qGetContainingPool(ptr)
      || (unsigned int)VirtualQuery(ptr, &Buffer, 0x30ui64) == 48
      && ((Buffer.Protect & 4) != 0 || (Buffer.Protect & 2) != 0);
}

// File Line: 76
// RVA: 0xA3A040
bool __fastcall UFG::qIsValidPointer(char *ptr, int size)
{
  return ptr && ((size - 1) & (unsigned __int64)ptr) == 0 && UFG::qIsMemoryValidForRead(ptr);
}

// File Line: 170
// RVA: 0xA372C0
void __fastcall UFG::ConvertW2A::ConvertW2A(UFG::ConvertW2A *this, const wchar_t *a_pString)
{
  int v4; // ebp
  unsigned __int64 cbMultiByte; // rdi
  unsigned __int64 v6; // rax
  UFG::allocator::free_link *v7; // rax
  char *lpMultiByteStr; // rax
  wchar_t *m_pStringW; // r8
  int UsedDefaultChar; // [rsp+60h] [rbp+8h] BYREF

  this->m_pStringA = 0i64;
  this->m_pStringW = 0i64;
  UsedDefaultChar = 0;
  v4 = lstrlenW(a_pString) + 1;
  cbMultiByte = WideCharToMultiByte(0, 0, a_pString, v4, 0i64, 0, 0i64, &UsedDefaultChar);
  v6 = 2i64 * v4;
  if ( !is_mul_ok(v4, 2ui64) )
    v6 = -1i64;
  v7 = UFG::qMalloc(v6, "ConvertW2A::StringW", 0i64);
  this->m_pStringW = (wchar_t *)v7;
  StringCchCopyW((wchar_t *)v7, v4, a_pString);
  lpMultiByteStr = (char *)UFG::qMalloc(cbMultiByte, "ConvertW2A::StringA", 0i64);
  m_pStringW = this->m_pStringW;
  this->m_pStringA = lpMultiByteStr;
  WideCharToMultiByte(0, 0, m_pStringW, v4, lpMultiByteStr, cbMultiByte, 0i64, &UsedDefaultChar);
}

// File Line: 184
// RVA: 0xA37710
void __fastcall UFG::ConvertW2A::~ConvertW2A(UFG::ConvertW2A *this)
{
  char *m_pStringA; // rcx
  wchar_t *m_pStringW; // rcx

  m_pStringA = this->m_pStringA;
  if ( m_pStringA )
    operator delete[](m_pStringA);
  m_pStringW = this->m_pStringW;
  if ( m_pStringW )
    operator delete[](m_pStringW);
}

