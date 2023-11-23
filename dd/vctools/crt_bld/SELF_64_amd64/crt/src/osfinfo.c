// File Line: 52
// RVA: 0x12C2E90
__int64 __fastcall alloc_osfhnd()
{
  unsigned int v0; // esi
  int i; // edi
  ioinfo *v3; // rbx
  ioinfo *v4; // rax
  int v5; // edi

  v0 = -1;
  if ( !mtinitlocknum(11) || (int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  lock(11);
  for ( i = 0; i < 64; ++i )
  {
    v3 = _pioinfo[i];
    if ( !v3 )
    {
      v4 = (ioinfo *)calloc_crt(0x20ui64, 0x58ui64);
      if ( v4 )
      {
        _pioinfo[i] = v4;
        nhandle += 32;
        while ( v4 < &_pioinfo[i][32] )
        {
          *(_WORD *)&v4->osfile = 2560;
          v4->osfhnd = -1i64;
          v4->lockinitflag = 0;
          ++v4;
        }
        v5 = 32 * i;
        _pioinfo[(__int64)v5 >> 5][v5 & 0x1F].osfile = 1;
        if ( !(unsigned int)_lock_fhandle(v5) )
          v5 = -1;
        v0 = v5;
      }
      break;
    }
    while ( v3 < &_pioinfo[i][32] )
    {
      if ( (v3->osfile & 1) == 0 )
      {
        if ( !v3->lockinitflag )
        {
          lock(10);
          if ( !v3->lockinitflag )
          {
            InitializeCriticalSectionAndSpinCount(&v3->lock, 0xFA0u);
            ++v3->lockinitflag;
          }
          unlock(10);
        }
        EnterCriticalSection(&v3->lock);
        if ( (v3->osfile & 1) == 0 )
        {
          v3->osfile = 1;
          v3->osfhnd = -1i64;
          v0 = 32 * i + ((int)v3 - LODWORD(_pioinfo[i])) / 88;
          break;
        }
        LeaveCriticalSection(&v3->lock);
      }
      ++v3;
    }
    if ( v0 != -1 )
      break;
  }
  unlock(11);
  return v0;
}

// File Line: 99
// RVA: 0x1451F21
_alloc_osfhnd$fin$0

// File Line: 172
// RVA: 0x1451F3C
_alloc_osfhnd$fin$1

// File Line: 207
// RVA: 0x12C32BC
__int64 __fastcall set_osfhnd(unsigned int fh, void *value)
{
  __int64 v3; // rsi
  __int64 v4; // rdi
  unsigned int v5; // ecx
  DWORD v6; // ecx

  if ( (fh & 0x80000000) == 0 && fh < nhandle )
  {
    v3 = (__int64)(int)fh >> 5;
    v4 = fh & 0x1F;
    if ( _pioinfo[v3][v4].osfhnd == -1 )
    {
      if ( _app_type == 1 )
      {
        if ( !fh )
        {
          v6 = -10;
          goto LABEL_11;
        }
        v5 = fh - 1;
        if ( !v5 )
        {
          v6 = -11;
          goto LABEL_11;
        }
        if ( v5 == 1 )
        {
          v6 = -12;
LABEL_11:
          SetStdHandle(v6, value);
        }
      }
      _pioinfo[v3][v4].osfhnd = (__int64)value;
      return 0i64;
    }
  }
  *errno() = 9;
  *_doserrno() = 0;
  return 0xFFFFFFFFi64;
}

// File Line: 257
// RVA: 0x12C3090
__int64 __fastcall free_osfhnd(unsigned int fh)
{
  __int64 v1; // rdi
  __int64 v2; // rbx
  ioinfo *v3; // rax
  unsigned int v4; // ecx
  DWORD v5; // ecx

  if ( (fh & 0x80000000) == 0 && fh < nhandle )
  {
    v1 = (__int64)(int)fh >> 5;
    v2 = fh & 0x1F;
    v3 = _pioinfo[v1];
    if ( (v3[v2].osfile & 1) != 0 && v3[fh & 0x1F].osfhnd != -1 )
    {
      if ( _app_type == 1 )
      {
        if ( !fh )
        {
          v5 = -10;
          goto LABEL_12;
        }
        v4 = fh - 1;
        if ( !v4 )
        {
          v5 = -11;
          goto LABEL_12;
        }
        if ( v4 == 1 )
        {
          v5 = -12;
LABEL_12:
          SetStdHandle(v5, 0i64);
        }
      }
      _pioinfo[v1][v2].osfhnd = -1i64;
      return 0i64;
    }
  }
  *errno() = 9;
  *_doserrno() = 0;
  return 0xFFFFFFFFi64;
}

// File Line: 306
// RVA: 0x12C313C
__int64 __fastcall get_osfhandle(int fh)
{
  __int64 v1; // rbx
  ioinfo *v2; // rax

  v1 = fh;
  if ( fh == -2 )
  {
    *_doserrno() = 0;
    *errno() = 9;
  }
  else if ( (int)ioinit() >= 0 )
  {
    if ( (int)v1 >= 0 && (unsigned int)v1 < nhandle )
    {
      v2 = _pioinfo[v1 >> 5];
      if ( (v2[v1 & 0x1F].osfile & 1) != 0 )
        return v2[v1 & 0x1F].osfhnd;
    }
    *_doserrno() = 0;
    *errno() = 9;
    invalid_parameter_noinfo();
  }
  return -1i64;
}

// File Line: 338
// RVA: 0x12C31C0
__int64 __fastcall open_osfhandle(void *osfhandle, __int16 flags)
{
  char v3; // bl
  DWORD FileType; // eax
  unsigned int LastError; // eax
  int v7; // eax
  __int64 v8; // rdi
  __int64 v9; // rdx

  v3 = 0;
  if ( (flags & 8) != 0 )
    v3 = 32;
  if ( (flags & 0x4000) != 0 )
    v3 |= 0x80u;
  if ( (flags & 0x80u) != 0 )
    v3 |= 0x10u;
  FileType = GetFileType(osfhandle);
  switch ( FileType )
  {
    case 0u:
      LastError = GetLastError();
      dosmaperr(LastError);
      return 0xFFFFFFFFi64;
    case 2u:
      v3 |= 0x40u;
      break;
    case 3u:
      v3 |= 8u;
      break;
  }
  v7 = alloc_osfhnd();
  v8 = v7;
  if ( v7 == -1 )
  {
    *errno() = 24;
    *_doserrno() = 0;
    return 0xFFFFFFFFi64;
  }
  set_osfhnd(v7, (__int64)osfhandle);
  v9 = v8 & 0x1F;
  _pioinfo[v8 >> 5][v9].osfile = v3 | 1;
  *((_BYTE *)&_pioinfo[v8 >> 5][v9] + 56) &= 0x80u;
  *((_BYTE *)&_pioinfo[v8 >> 5][v9] + 56) &= ~0x80u;
  unlock_fhandle(v8);
  return (unsigned int)v8;
}

// File Line: 396
// RVA: 0x1451F55
_open_osfhandle$fin$0

// File Line: 431
// RVA: 0x12C2DF8
__int64 __fastcall _lock_fhandle(int fh)
{
  __int64 v1; // rsi
  unsigned __int64 v2; // rbx
  ioinfo *v3; // rdi

  v1 = (__int64)fh >> 5;
  v2 = fh & 0x1F;
  v3 = _pioinfo[v1];
  if ( !v3[v2].lockinitflag )
  {
    lock(10);
    if ( !v3[v2].lockinitflag )
    {
      InitializeCriticalSectionAndSpinCount(&v3[v2].lock, 0xFA0u);
      ++v3[v2].lockinitflag;
    }
    unlock(10);
  }
  EnterCriticalSection(&_pioinfo[v1][v2].lock);
  return 1i64;
}

// File Line: 446
// RVA: 0x1451F08
__lock_fhandle$fin$0

// File Line: 478
// RVA: 0x12C336C
void __fastcall unlock_fhandle(int fh)
{
  LeaveCriticalSection(&_pioinfo[(__int64)fh >> 5][fh & 0x1F].lock);
}

