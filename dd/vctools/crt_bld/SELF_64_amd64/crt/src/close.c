// File Line: 41
// RVA: 0x12BF21C
signed __int64 __fastcall close(int fh)
{
  __int64 v1; // rdi
  __int64 v2; // rbx
  unsigned int v3; // ebx

  v1 = fh;
  if ( fh == -2 )
  {
    *_doserrno() = 0;
    *errno() = 9;
    return 0xFFFFFFFFi64;
  }
  if ( (signed int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  if ( (signed int)v1 < 0 || (unsigned int)v1 >= nhandle || (v2 = v1 & 0x1F, !(_pioinfo[v1 >> 5][v2].osfile & 1)) )
  {
    *_doserrno() = 0;
    *errno() = 9;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  _lock_fhandle(v1);
  if ( _pioinfo[v1 >> 5][v2].osfile & 1 )
  {
    v3 = close_nolock(v1);
  }
  else
  {
    *errno() = 9;
    v3 = -1;
  }
  unlock_fhandle(v1);
  return v3;
}

// File Line: 72
// RVA: 0x12BF2EC
signed __int64 __fastcall close_nolock(int fh)
{
  __int64 v1; // rdi
  __int64 v3; // rbx
  void *v4; // rax
  unsigned int v5; // ebx

  v1 = fh;
  if ( (signed int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  if ( get_osfhandle(v1) == -1
    || ((_DWORD)v1 == 1 && _pioinfo[0][2].osfile & 1 || (_DWORD)v1 == 2 && _pioinfo[0][1].osfile & 1)
    && (v3 = get_osfhandle(2), get_osfhandle(1) == v3)
    || (v4 = (void *)get_osfhandle(v1), CloseHandle(v4)) )
  {
    v5 = 0;
  }
  else
  {
    v5 = GetLastError();
  }
  free_osfhnd(v1);
  _pioinfo[v1 >> 5][v1 & 0x1F].osfile = 0;
  if ( v5 )
  {
    dosmaperr(v5);
    return 0xFFFFFFFFi64;
  }
  return 0i64;
}

