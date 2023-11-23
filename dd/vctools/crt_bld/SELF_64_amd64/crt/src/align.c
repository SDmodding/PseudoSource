// File Line: 68
// RVA: 0x12AFFF8
_QWORD *__fastcall aligned_malloc(unsigned __int64 size, unsigned __int64 alignment)
{
  _QWORD *result; // rax
  unsigned __int64 v3; // rbx
  unsigned __int64 v4; // rbx
  void *v5; // rcx

  if ( ((alignment - 1) & alignment) != 0 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0i64;
  }
  v3 = 8i64;
  if ( alignment > 8 )
    v3 = alignment;
  v4 = v3 - 1;
  if ( size > v4 + size + 8 )
  {
    *errno() = 12;
    return 0i64;
  }
  v5 = malloc(v4 + size + 8);
  result = 0i64;
  if ( v5 )
  {
    result = (_QWORD *)(~v4 & ((unsigned __int64)v5 + v4 + 8));
    *(result - 1) = v5;
  }
  return result;
}

// File Line: 459
// RVA: 0x12AFFDC
void __fastcall aligned_free(unsigned __int64 memblock)
{
  if ( memblock )
    free(*(void **)((memblock & 0xFFFFFFFFFFFFFFF8ui64) - 8));
}

