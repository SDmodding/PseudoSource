// File Line: 62
// RVA: 0x12BB3C8
void *__fastcall realloc(void *pBlock, unsigned __int64 newsize)
{
  unsigned __int64 v2; // rbx
  void *v3; // rdi
  LPVOID v5; // rsi
  int *v6; // rbx
  unsigned int v7; // eax
  int *v8; // rbx
  unsigned int v9; // eax

  v2 = newsize;
  v3 = pBlock;
  if ( !pBlock )
    return malloc(newsize);
  if ( !newsize )
  {
    free(pBlock);
    return 0i64;
  }
  if ( newsize > 0xFFFFFFFFFFFFFFE0ui64 )
  {
LABEL_12:
    callnewh(v2);
    *errno() = 12;
    return 0i64;
  }
  while ( 1 )
  {
    if ( !v2 )
      v2 = 1i64;
    v5 = HeapReAlloc(crtheap, 0, v3, v2);
    if ( v5 )
      return v5;
    if ( !newmode )
    {
      v8 = errno();
      v9 = GetLastError();
      *v8 = get_errno_from_oserr(v9);
      return v5;
    }
    if ( !callnewh(v2) )
    {
      v6 = errno();
      v7 = GetLastError();
      *v6 = get_errno_from_oserr(v7);
      return 0i64;
    }
    if ( v2 > 0xFFFFFFFFFFFFFFE0ui64 )
      goto LABEL_12;
  }
}

