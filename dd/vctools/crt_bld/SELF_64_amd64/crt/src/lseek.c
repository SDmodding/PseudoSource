// File Line: 60
// RVA: 0x12CEFE8
__int64 __fastcall lseek(int fh, int pos, int mthd)
{
  __int64 v5; // rdi
  __int64 v6; // rbx
  unsigned int v7; // ebx

  v5 = fh;
  if ( fh == -2 )
  {
    *_doserrno() = 0;
    *errno() = 9;
    return 0xFFFFFFFFi64;
  }
  if ( (int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  if ( (int)v5 < 0 || (unsigned int)v5 >= nhandle || (v6 = v5 & 0x1F, (_pioinfo[v5 >> 5][v6].osfile & 1) == 0) )
  {
    *_doserrno() = 0;
    *errno() = 9;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  _lock_fhandle(v5);
  if ( (_pioinfo[v5 >> 5][v6].osfile & 1) != 0 )
  {
    v7 = lseek_nolock(v5, pos, mthd);
  }
  else
  {
    *errno() = 9;
    *_doserrno() = 0;
    v7 = -1;
  }
  unlock_fhandle(v5);
  return v7;
}

// File Line: 94
// RVA: 0x12CF0D4
__int64 __fastcall lseek_nolock(int fh, LONG pos, DWORD mthd)
{
  __int64 v3; // rbx
  void *osfhandle; // rax
  DWORD v8; // edi
  unsigned int LastError; // eax

  v3 = fh;
  osfhandle = (void *)get_osfhandle(fh);
  if ( osfhandle == (void *)-1i64 )
  {
    *errno() = 9;
    return 0xFFFFFFFFi64;
  }
  v8 = SetFilePointer(osfhandle, pos, 0i64, mthd);
  if ( v8 == -1 )
    LastError = GetLastError();
  else
    LastError = 0;
  if ( LastError )
  {
    dosmaperr(LastError);
    return 0xFFFFFFFFi64;
  }
  _pioinfo[v3 >> 5][v3 & 0x1F].osfile &= ~2u;
  return v8;
}

