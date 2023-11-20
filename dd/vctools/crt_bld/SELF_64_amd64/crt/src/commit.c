// File Line: 39
// RVA: 0x12C2574
signed __int64 __fastcall commit(int filedes)
{
  __int64 v1; // rdi
  __int64 v3; // rbx
  void *v4; // rax
  DWORD v5; // ebx

  v1 = filedes;
  if ( filedes != -2 )
  {
    if ( (signed int)ioinit() < 0 )
      return 9i64;
    if ( (signed int)v1 < 0 || (unsigned int)v1 >= nhandle || (v3 = v1 & 0x1F, !(_pioinfo[v1 >> 5][v3].osfile & 1)) )
    {
      *errno() = 9;
      invalid_parameter_noinfo();
      return 0xFFFFFFFFi64;
    }
    _lock_fhandle(v1);
    if ( _pioinfo[v1 >> 5][v3].osfile & 1 )
    {
      v4 = (void *)get_osfhandle(v1);
      if ( FlushFileBuffers(v4) )
        v5 = 0;
      else
        v5 = GetLastError();
      if ( !v5 )
        goto $good;
      *_doserrno() = v5;
    }
    *errno() = 9;
    v5 = -1;
$good:
    unlock_fhandle(v1);
    return v5;
  }
  *errno() = 9;
  return 0xFFFFFFFFi64;
}

// File Line: 73
// RVA: 0x1451EF1
_close$fin$0

