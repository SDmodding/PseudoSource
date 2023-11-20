// File Line: 53
// RVA: 0x12B3AA0
_iobuf *__fastcall _iob_func()
{
  return iob;
}

// File Line: 109
// RVA: 0x12B39D8
signed __int64 __fastcall _initstdio()
{
  signed int v0; // eax
  __int64 v1; // rbx
  signed __int64 v2; // rdi
  void **v3; // rax
  _iobuf *v5; // rcx

  v0 = nstream;
  v1 = 0i64;
  v2 = 20i64;
  if ( nstream )
  {
    if ( nstream < 20 )
      v0 = 20;
  }
  else
  {
    v0 = 512;
  }
  nstream = v0;
  v3 = (void **)calloc_crt(v0, 8ui64);
  _piob = v3;
  if ( !v3 )
  {
    nstream = 20;
    v3 = (void **)calloc_crt(0x14ui64, 8ui64);
    _piob = v3;
    if ( !v3 )
      return 26i64;
  }
  v5 = iob;
  while ( 1 )
  {
    v3[v1] = v5;
    ++v5;
    ++v1;
    if ( !--v2 )
      break;
    v3 = _piob;
  }
  return 0i64;
}

// File Line: 173
// RVA: 0x12B3A70
void _endstdio()
{
  flushall();
  if ( exitflag )
    fcloseall();
  free(_piob);
  _piob = 0i64;
}

// File Line: 203
// RVA: 0x12B3AA8
void __fastcall lock_file(_iobuf *pf)
{
  _iobuf *v1; // rbx
  unsigned __int64 v2; // rdx

  v1 = pf;
  if ( pf < iob || pf > &iob[19] )
  {
    EnterCriticalSection((LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    v2 = (signed __int64)((unsigned __int128)(((char *)pf - (char *)iob) * (signed __int128)3074457345618258603i64) >> 64) >> 3;
    lock(v2 + (v2 >> 63) + 16);
    v1->_flag |= 0x8000u;
  }
}

// File Line: 246
// RVA: 0x12B3B10
void __fastcall lock_file2(int i, void *s)
{
  _DWORD *v2; // rbx

  v2 = s;
  if ( i >= 20 )
  {
    EnterCriticalSection((LPCRITICAL_SECTION)((char *)s + 48));
  }
  else
  {
    lock(i + 16);
    v2[6] |= 0x8000u;
  }
}

// File Line: 288
// RVA: 0x12B3B44
void __fastcall unlock_file(_iobuf *pf)
{
  unsigned __int64 v1; // rdx

  if ( pf < iob || pf > &iob[19] )
  {
    LeaveCriticalSection((LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    pf->_flag &= 0xFFFF7FFF;
    v1 = (signed __int64)((unsigned __int128)(((char *)pf - (char *)iob) * (signed __int128)3074457345618258603i64) >> 64) >> 3;
    unlock(v1 + (v1 >> 63) + 16);
  }
}

// File Line: 331
// RVA: 0x12B3B94
void __fastcall unlock_file2(int i, void *s)
{
  if ( i >= 20 )
  {
    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)s + 48));
  }
  else
  {
    *((_DWORD *)s + 6) &= 0xFFFF7FFF;
    unlock(i + 16);
  }
}

