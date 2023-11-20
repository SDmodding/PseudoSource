// File Line: 51
// RVA: 0x12BDC24
signed __int64 __fastcall chsize_s(int filedes, __int64 size)
{
  __int64 v2; // rsi
  __int64 v3; // rdi
  __int64 v5; // rbx
  int *v6; // rax
  unsigned int v7; // ebx

  v2 = size;
  v3 = filedes;
  if ( filedes == -2 )
  {
    *_doserrno() = 0;
    return 9i64;
  }
  if ( (signed int)ioinit() < 0 )
    return 9i64;
  if ( (signed int)v3 >= 0 && (unsigned int)v3 < nhandle && (v5 = v3 & 0x1F, _pioinfo[v3 >> 5][v5].osfile & 1) )
  {
    if ( v2 >= 0 )
    {
      _lock_fhandle(v3);
      if ( _pioinfo[v3 >> 5][v5].osfile & 1 )
      {
        v7 = chsize_nolock(v3, v2);
      }
      else
      {
        v7 = 9;
        *errno() = 9;
      }
      unlock_fhandle(v3);
      return v7;
    }
    *_doserrno() = 0;
    v6 = errno();
    v7 = 22;
  }
  else
  {
    *_doserrno() = 0;
    v6 = errno();
    v7 = 9;
  }
  *v6 = v7;
  invalid_parameter_noinfo();
  return v7;
}

// File Line: 82
// RVA: 0x12BDA8C
__int64 __fastcall chsize_nolock(int filedes, __int64 size)
{
  __int64 v2; // rbp
  signed __int64 v3; // rdi
  int v4; // esi
  __int64 v5; // r15
  __int64 v6; // rax
  signed __int64 v7; // rbx
  HANDLE v8; // rax
  void *v9; // rbp
  int v11; // er14
  unsigned int v12; // er8
  int v13; // eax
  HANDLE v14; // rax
  void *v15; // rax
  int v16; // eax
  unsigned int *v17; // rbx

  v2 = size;
  v3 = 0i64;
  v4 = filedes;
  v5 = lseeki64_nolock(filedes, 0i64, 1);
  if ( v5 == -1 )
    return (unsigned int)*errno();
  v6 = lseeki64_nolock(v4, 0i64, 2);
  if ( v6 == -1 )
    return (unsigned int)*errno();
  v7 = v2 - v6;
  if ( v2 - v6 > 0 )
  {
    v8 = GetProcessHeap();
    v9 = HeapAlloc(v8, 8u, 0x1000ui64);
    if ( !v9 )
    {
      *errno() = 12;
      return (unsigned int)*errno();
    }
    v11 = setmode_nolock(v4, 0x8000);
    while ( 1 )
    {
      v12 = v7;
      if ( v7 >= 4096 )
        v12 = 4096;
      v13 = write_nolock(v4, v9, v12);
      if ( v13 == -1 )
        break;
      v7 -= v13;
      if ( v7 <= 0 )
        goto LABEL_17;
    }
    if ( *_doserrno() == 5 )
      *errno() = 13;
    v3 = -1i64;
LABEL_17:
    setmode_nolock(v4, v11);
    v14 = GetProcessHeap();
    HeapFree(v14, 0, v9);
    goto LABEL_22;
  }
  if ( v2 - v6 < 0 )
  {
    if ( lseeki64_nolock(v4, v2, 0) == -1 )
      return (unsigned int)*errno();
    v15 = (void *)get_osfhandle(v4);
    v16 = -SetEndOfFile(v15);
    v3 = (v16 != 0) - 1i64;
    if ( !v16 )
    {
      *errno() = 13;
      v17 = _doserrno();
      *v17 = GetLastError();
LABEL_22:
      if ( v3 == -1 )
        return (unsigned int)*errno();
      goto LABEL_23;
    }
  }
LABEL_23:
  if ( lseeki64_nolock(v4, v5, 0) == -1 )
    return (unsigned int)*errno();
  return 0i64;
}

