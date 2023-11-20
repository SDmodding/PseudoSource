// File Line: 39
// RVA: 0x12C5860
void *__fastcall malloc_crt(unsigned __int64 cb)
{
  unsigned int v1; // esi
  DWORD v2; // edi
  unsigned __int64 v3; // rbp
  void *v4; // rbx

  v1 = maxwait;
  v2 = 0;
  v3 = cb;
  do
  {
    v4 = malloc(v3);
    if ( v4 || !v1 )
      break;
    Sleep(v2);
    v1 = maxwait;
    v2 += 1000;
    if ( v2 > maxwait )
      v2 = -1;
  }
  while ( v2 != -1 );
  return v4;
}

// File Line: 54
// RVA: 0x12C57E0
void *__fastcall calloc_crt(unsigned __int64 count, unsigned __int64 size)
{
  DWORD v2; // ebx
  unsigned __int64 v3; // rsi
  unsigned __int64 v4; // rbp
  void *v5; // rdi

  v2 = 0;
  v3 = size;
  v4 = count;
  do
  {
    v5 = calloc_impl(v4, v3, 0i64);
    if ( v5 || maxwait <= 0 )
      break;
    Sleep(v2);
    v2 += 1000;
    if ( v2 > maxwait )
      v2 = -1;
  }
  while ( v2 != -1 );
  return v5;
}

// File Line: 71
// RVA: 0x12C58DC
void *__fastcall realloc_crt(void *ptr, unsigned __int64 size)
{
  DWORD v2; // ebx
  unsigned __int64 v3; // rsi
  void *v4; // rbp
  void *v5; // rdi

  v2 = 0;
  v3 = size;
  v4 = ptr;
  do
  {
    v5 = realloc(v4, v3);
    if ( v5 || !v3 || maxwait <= 0 )
      break;
    Sleep(v2);
    v2 += 1000;
    if ( v2 > maxwait )
      v2 = -1;
  }
  while ( v2 != -1 );
  return v5;
}

// File Line: 86
// RVA: 0x12C5960
void *__fastcall recalloc_crt(void *ptr, unsigned __int64 count, unsigned __int64 size)
{
  DWORD v3; // edi
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rbp
  void *v6; // r14
  void *v7; // rbx

  v3 = 0;
  v4 = size;
  v5 = count;
  v6 = ptr;
  do
  {
    v7 = recalloc(v6, v5, v4);
    if ( v7 || !v4 || maxwait <= 0 )
      break;
    Sleep(v3);
    v3 += 1000;
    if ( v3 > maxwait )
      v3 = -1;
  }
  while ( v3 != -1 );
  return v7;
}

