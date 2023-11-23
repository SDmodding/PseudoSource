// File Line: 39
// RVA: 0x12C2574
__int64 __fastcall commit(int filedes)
{
  __int64 v1; // rdi
  __int64 v3; // rbx
  void *osfhandle; // rax
  DWORD LastError; // ebx

  v1 = filedes;
  if ( filedes != -2 )
  {
    if ( (int)ioinit() < 0 )
      return 9i64;
    if ( (int)v1 < 0 || (unsigned int)v1 >= nhandle || (v3 = v1 & 0x1F, (_pioinfo[v1 >> 5][v3].osfile & 1) == 0) )
    {
      *errno() = 9;
      invalid_parameter_noinfo();
      return 0xFFFFFFFFi64;
    }
    _lock_fhandle(v1);
    if ( (_pioinfo[v1 >> 5][v3].osfile & 1) != 0 )
    {
      osfhandle = (void *)get_osfhandle(v1);
      if ( FlushFileBuffers(osfhandle) )
        LastError = 0;
      else
        LastError = GetLastError();
      if ( !LastError )
        goto $good;
      *_doserrno() = LastError;
    }
    *errno() = 9;
    LastError = -1;
$good:
    unlock_fhandle(v1);
    return LastError;
  }
  *errno() = 9;
  return 0xFFFFFFFFi64;
}

// File Line: 73
// RVA: 0x1451EF1
_close$fin$0

