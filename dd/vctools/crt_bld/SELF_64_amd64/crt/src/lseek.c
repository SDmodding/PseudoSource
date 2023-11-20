// File Line: 60
// RVA: 0x12CEFE8
signed __int64 __fastcall lseek(int fh, int pos, int mthd)
{
  int v3; // er14
  int v4; // er15
  __int64 v5; // rdi
  __int64 v6; // rbx
  unsigned int v7; // ebx

  v3 = mthd;
  v4 = pos;
  v5 = fh;
  if ( fh == -2 )
  {
    *_doserrno() = 0;
    *errno() = 9;
    return 0xFFFFFFFFi64;
  }
  if ( (signed int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  if ( (signed int)v5 < 0 || (unsigned int)v5 >= nhandle || (v6 = v5 & 0x1F, !(_pioinfo[v5 >> 5][v6].osfile & 1)) )
  {
    *_doserrno() = 0;
    *errno() = 9;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  _lock_fhandle(v5);
  if ( _pioinfo[v5 >> 5][v6].osfile & 1 )
  {
    v7 = lseek_nolock(v5, v4, v3);
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
signed __int64 __fastcall lseek_nolock(int fh, int pos, int mthd)
{
  __int64 v3; // rbx
  int v4; // edi
  int v5; // esi
  void *v6; // rax
  DWORD v8; // edi
  unsigned int v9; // eax

  v3 = fh;
  v4 = mthd;
  v5 = pos;
  v6 = (void *)get_osfhandle(fh);
  if ( v6 == (void *)-1i64 )
  {
    *errno() = 9;
    return 0xFFFFFFFFi64;
  }
  v8 = SetFilePointer(v6, v5, 0i64, v4);
  if ( v8 == -1 )
    v9 = GetLastError();
  else
    v9 = 0;
  if ( v9 )
  {
    dosmaperr(v9);
    return 0xFFFFFFFFi64;
  }
  _pioinfo[v3 >> 5][v3 & 0x1F].osfile &= 0xFDu;
  return v8;
}

