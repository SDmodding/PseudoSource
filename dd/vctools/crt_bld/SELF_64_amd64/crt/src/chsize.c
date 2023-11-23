// File Line: 51
// RVA: 0x12BDC24
__int64 __fastcall chsize_s(int filedes, __int64 size)
{
  __int64 v3; // rdi
  __int64 v5; // rbx
  int *v6; // rax
  unsigned int v7; // ebx

  v3 = filedes;
  if ( filedes == -2 )
  {
    *_doserrno() = 0;
    return 9i64;
  }
  if ( (int)ioinit() < 0 )
    return 9i64;
  if ( (int)v3 >= 0 && (unsigned int)v3 < nhandle && (v5 = v3 & 0x1F, (_pioinfo[v3 >> 5][v5].osfile & 1) != 0) )
  {
    if ( size >= 0 )
    {
      _lock_fhandle(v3);
      if ( (_pioinfo[v3 >> 5][v5].osfile & 1) != 0 )
      {
        v7 = chsize_nolock(v3, size);
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
  __int64 v3; // rdi
  __int64 v5; // r15
  __int64 v6; // rax
  __int64 v7; // rbx
  HANDLE ProcessHeap; // rax
  void *v9; // rbp
  int v11; // r14d
  unsigned int v12; // r8d
  int v13; // eax
  HANDLE v14; // rax
  void *osfhandle; // rax
  int v16; // eax
  unsigned int *v17; // rbx

  v3 = 0i64;
  v5 = lseeki64_nolock(filedes, 0i64, 1);
  if ( v5 == -1 )
    return (unsigned int)*errno();
  v6 = lseeki64_nolock(filedes, 0i64, 2);
  if ( v6 == -1 )
    return (unsigned int)*errno();
  v7 = size - v6;
  if ( size - v6 > 0 )
  {
    ProcessHeap = GetProcessHeap();
    v9 = HeapAlloc(ProcessHeap, 8u, 0x1000ui64);
    if ( !v9 )
    {
      *errno() = 12;
      return (unsigned int)*errno();
    }
    v11 = setmode_nolock(filedes, 0x8000);
    while ( 1 )
    {
      v12 = v7;
      if ( v7 >= 4096 )
        v12 = 4096;
      v13 = write_nolock(filedes, v9, v12);
      if ( v13 == -1 )
        break;
      v7 -= v13;
      if ( v7 <= 0 )
        goto LABEL_16;
    }
    if ( *_doserrno() == 5 )
      *errno() = 13;
    v3 = -1i64;
LABEL_16:
    setmode_nolock(filedes, v11);
    v14 = GetProcessHeap();
    HeapFree(v14, 0, v9);
    goto LABEL_21;
  }
  if ( size - v6 < 0 )
  {
    if ( lseeki64_nolock(filedes, size, 0) == -1 )
      return (unsigned int)*errno();
    osfhandle = (void *)get_osfhandle(filedes);
    v16 = -SetEndOfFile(osfhandle);
    v3 = (v16 != 0) - 1i64;
    if ( !v16 )
    {
      *errno() = 13;
      v17 = _doserrno();
      *v17 = GetLastError();
LABEL_21:
      if ( v3 == -1 )
        return (unsigned int)*errno();
    }
  }
  if ( lseeki64_nolock(filedes, v5, 0) == -1 )
    return (unsigned int)*errno();
  return 0i64;
}

