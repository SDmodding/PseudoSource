// File Line: 137
// RVA: 0x12CD270
__int64 __fastcall mtinitlocks()
{
  int v0; // esi
  $8E2FCADB8B1A21CF4E0353D18BB81613 *v1; // rbx
  __int64 v2; // rdi
  __int64 v3; // rax
  _RTL_CRITICAL_SECTION *v4; // rcx

  v0 = 0;
  v1 = locktable;
  v2 = 36i64;
  do
  {
    if ( v1->kind == lkPrealloc )
    {
      v3 = v0++;
      v4 = &lclcritsects[v3];
      v1->lock = v4;
      InitializeCriticalSectionAndSpinCount(v4, 0xFA0u);
    }
    ++v1;
    --v2;
  }
  while ( v2 );
  return 1i64;
}

// File Line: 183
// RVA: 0x12CD12C
void mtdeletelocks()
{
  __int64 v0; // rdi
  $8E2FCADB8B1A21CF4E0353D18BB81613 *v1; // rbx
  __int64 v2; // rbp
  LPCRITICAL_SECTION lock; // rsi
  $1DD7A03358E0D01DD359262876E6A0F0 *p_kind; // rbx
  _RTL_CRITICAL_SECTION *v5; // rcx

  v0 = 36i64;
  v1 = locktable;
  v2 = 36i64;
  do
  {
    lock = v1->lock;
    if ( v1->lock && v1->kind != lkPrealloc )
    {
      DeleteCriticalSection(v1->lock);
      free(lock);
      v1->lock = 0i64;
    }
    ++v1;
    --v2;
  }
  while ( v2 );
  p_kind = &locktable[0].kind;
  do
  {
    v5 = (_RTL_CRITICAL_SECTION *)*((_QWORD *)p_kind - 1);
    if ( v5 )
    {
      if ( *p_kind == lkPrealloc )
        DeleteCriticalSection(v5);
    }
    p_kind += 4;
    --v0;
  }
  while ( v0 );
}

// File Line: 254
// RVA: 0x12CD1B4
__int64 __fastcall mtinitlocknum(int locknum)
{
  __int64 v1; // rbx
  _RTL_CRITICAL_SECTION *v3; // rdi

  if ( !crtheap )
  {
    FF_MSGBANNER();
    NMSG_WRITE(30);
    _crtExitProcess(0xFFu);
  }
  v1 = locknum;
  if ( locktable[locknum].lock )
    return 1i64;
  v3 = (_RTL_CRITICAL_SECTION *)malloc_crt(0x28ui64);
  if ( v3 )
  {
    lock(10);
    if ( locktable[v1].lock )
    {
      free(v3);
    }
    else
    {
      InitializeCriticalSectionAndSpinCount(v3, 0xFA0u);
      locktable[v1].lock = v3;
    }
    LeaveCriticalSection(locktable[10].lock);
    return 1i64;
  }
  *errno() = 12;
  return 0i64;
}

// File Line: 290
// RVA: 0x1452299
_mtinitlocknum$fin$0

// File Line: 323
// RVA: 0x12CD0E8
void __fastcall lock(int locknum)
{
  __int64 v1; // rbx

  v1 = locknum;
  if ( !locktable[locknum].lock && !mtinitlocknum(locknum) )
    amsg_exit(17);
  EnterCriticalSection(locktable[v1].lock);
}

// File Line: 361
// RVA: 0x12CD2D0
void __fastcall unlock(int locknum)
{
  LeaveCriticalSection(locktable[locknum].lock);
}

