// File Line: 54
// RVA: 0x12D7FC0
void *__fastcall recalloc(void *memblock, unsigned __int64 count, unsigned __int64 size)
{
  SIZE_T v3; // rdi
  void *v4; // rsi
  void *result; // rax
  unsigned __int64 v6; // rbx
  char *v7; // rax
  void *v8; // rsi

  v3 = 0i64;
  v4 = memblock;
  if ( count && 0xFFFFFFFFFFFFFFE0ui64 / count < size )
  {
    *errno() = 12;
    result = 0i64;
  }
  else
  {
    v6 = size * count;
    if ( memblock )
      v3 = msize(memblock);
    v7 = (char *)realloc(v4, v6);
    v8 = v7;
    if ( v7 )
    {
      if ( v3 < v6 )
        memset(&v7[v3], 0, v6 - v3);
    }
    result = v8;
  }
  return result;
}

