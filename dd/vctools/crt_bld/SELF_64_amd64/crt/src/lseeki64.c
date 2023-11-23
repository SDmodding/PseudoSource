// File Line: 59
// RVA: 0x12CF16C
__int64 __fastcall lseeki64(int fh, __int64 pos, int mthd)
{
  __int64 v5; // rdi
  __int64 v6; // rbx
  __int64 v7; // rbx

  v5 = fh;
  if ( fh == -2 )
  {
    *_doserrno() = 0;
    *errno() = 9;
    return -1i64;
  }
  if ( (int)ioinit() < 0 )
    return -1i64;
  if ( (int)v5 < 0 || (unsigned int)v5 >= nhandle || (v6 = v5 & 0x1F, (_pioinfo[v5 >> 5][v6].osfile & 1) == 0) )
  {
    *_doserrno() = 0;
    *errno() = 9;
    invalid_parameter_noinfo();
    return -1i64;
  }
  _lock_fhandle(v5);
  if ( (_pioinfo[v5 >> 5][v6].osfile & 1) != 0 )
  {
    v7 = lseeki64_nolock(v5, pos, mthd);
  }
  else
  {
    *errno() = 9;
    *_doserrno() = 0;
    v7 = -1i64;
  }
  unlock_fhandle(v5);
  return v7;
}

// File Line: 80
// RVA: 0x1452308
_read$fin$0

// File Line: 107
// RVA: 0x12CF25C
_LARGE_INTEGER __fastcall lseeki64_nolock(int fh, LARGE_INTEGER pos, DWORD mthd)
{
  __int64 v3; // rbx
  void *osfhandle; // rax
  unsigned int LastError; // eax
  _LARGE_INTEGER NewFilePointer; // [rsp+48h] [rbp+20h] BYREF

  v3 = fh;
  osfhandle = (void *)get_osfhandle(fh);
  if ( osfhandle == (void *)-1i64 )
  {
    *errno() = 9;
    return (_LARGE_INTEGER)-1i64;
  }
  if ( !SetFilePointerEx(osfhandle, pos, &NewFilePointer, mthd) )
  {
    LastError = GetLastError();
    dosmaperr(LastError);
    return (_LARGE_INTEGER)-1i64;
  }
  _pioinfo[v3 >> 5][v3 & 0x1F].osfile &= ~2u;
  return NewFilePointer;
}

