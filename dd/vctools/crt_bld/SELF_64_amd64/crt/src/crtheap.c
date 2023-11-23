// File Line: 39
// RVA: 0x12C5860
LPVOID __fastcall malloc_crt(unsigned __int64 cb)
{
  unsigned int v1; // esi
  DWORD v2; // edi
  LPVOID v4; // rbx

  v1 = maxwait;
  v2 = 0;
  do
  {
    v4 = malloc(cb);
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
  void *v5; // rdi

  v2 = 0;
  do
  {
    v5 = calloc_impl(count, size, 0i64);
    if ( v5 || !maxwait )
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
LPVOID __fastcall realloc_crt(void *ptr, unsigned __int64 size)
{
  DWORD v2; // ebx
  LPVOID v5; // rdi

  v2 = 0;
  do
  {
    v5 = realloc(ptr, size);
    if ( v5 || !size || !maxwait )
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
  void *v7; // rbx

  v3 = 0;
  do
  {
    v7 = recalloc(ptr, count, size);
    if ( v7 || !size || !maxwait )
      break;
    Sleep(v3);
    v3 += 1000;
    if ( v3 > maxwait )
      v3 = -1;
  }
  while ( v3 != -1 );
  return v7;
}

