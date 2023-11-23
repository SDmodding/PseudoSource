// File Line: 125
// RVA: 0xEF3EFC
__int64 __fastcall ax_malloc(unsigned __int64 s)
{
  return online_suite_malloc(s, 0i64);
}

// File Line: 130
// RVA: 0xEF3F04
void *__fastcall ax_realloc(void *y, unsigned __int64 s)
{
  return online_suite_realloc(y, s, 0i64);
}

// File Line: 135
// RVA: 0xEF3EB4
void *__fastcall ax_calloc(unsigned __int64 n, unsigned __int64 s)
{
  size_t v2; // rdi
  void *result; // rax
  void *v4; // rbx

  v2 = s * n;
  result = (void *)online_suite_malloc(s * n, 0i64);
  v4 = result;
  if ( result )
  {
    memset(result, 0, v2);
    return v4;
  }
  return result;
}

// File Line: 146
// RVA: 0xEF3EF4
// attributes: thunk
void __fastcall ax_free(void *mem)
{
  OSuite::ZObject::operator delete[](mem);
}

