// File Line: 45
// RVA: 0x12BD03C
__int64 __fastcall ftelli64(_iobuf *stream)
{
  _iobuf *v1; // rbx
  __int64 v3; // rdi

  v1 = stream;
  if ( !stream )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return -1i64;
  }
  if ( (signed int)ioinit() < 0 )
    return -1i64;
  lock_file(v1);
  v3 = ftelli64_nolock(v1);
  unlock_file(v1);
  return v3;
}

// File Line: 56
// RVA: 0x1451E41
_ftelli64$fin$0

// File Line: 81
// RVA: 0x12BD0A4
unsigned __int64 __fastcall ftelli64_nolock(_iobuf *str)
{
  _iobuf *v1; // r14
  int v2; // eax
  __int64 v3; // rbp
  __int64 v4; // rsi
  int v6; // edx
  __int64 v7; // r13
  ioinfo *v8; // rcx
  unsigned __int64 v9; // r15
  char v10; // r12
  unsigned __int64 v11; // rdi
  unsigned __int64 v12; // rdi
  __int64 v13; // rax
  ioinfo *v14; // rcx
  __int64 v15; // rbx
  char *v16; // rcx
  char *v17; // rdx
  char *i; // rax
  unsigned __int64 v19; // rbx
  char *v20; // rax
  char *v21; // rcx
  bool v22; // zf
  unsigned int NumberOfBytesRead; // [rsp+30h] [rbp-1048h]
  char Buffer[4096]; // [rsp+40h] [rbp-1038h]

  v1 = str;
  v2 = fileno(str);
  v3 = v2;
  if ( v1->_cnt < 0 )
    v1->_cnt = 0;
  v4 = lseeki64(v2, 0i64, 1);
  if ( v4 < 0 )
    return -1i64;
  v6 = v1->_flag;
  v7 = v3 >> 5;
  v8 = _pioinfo[v3 >> 5];
  v9 = v3 & 0x1F;
  v10 = (char)(2 * *((_BYTE *)&v8[v9] + 56)) >> 1;
  if ( !(v6 & 0x108) )
  {
    v4 -= v1->_cnt;
    return v4;
  }
  v11 = v1->_ptr - v1->_base;
  if ( v6 & 3 )
  {
    if ( v10 == 1 && v8[v9].utf8translations )
    {
      v12 = v11 >> 1;
      if ( !v1->_cnt )
        return v4;
      v13 = lseeki64(v3, v8[v9].startpos, 0);
      v14 = _pioinfo[v7];
      v15 = v13;
      if ( v13 == v14[v9].startpos
        && ReadFile((HANDLE)v14[v9].osfhnd, Buffer, 0x1000u, &NumberOfBytesRead, 0i64)
        && lseeki64(v3, v4, 0) >= 0
        && v12 <= NumberOfBytesRead )
      {
        v16 = Buffer;
        if ( v12 )
        {
          v17 = &Buffer[NumberOfBytesRead];
          do
          {
            --v12;
            if ( v16 >= v17 )
              break;
            if ( *v16++ == 13 )
            {
              if ( v16 < v17 - 1 && v16[1] == 10 )
                ++v16;
            }
            else
            {
              v16 += lookuptrailbytes[(unsigned __int8)*v16];
            }
          }
          while ( v12 );
        }
        return v15 + v16 - Buffer;
      }
      return -1i64;
    }
    if ( v8[v9].osfile < 0 )
    {
      for ( i = v1->_base; i < v1->_ptr; ++i )
      {
        if ( *i == 10 )
          ++v11;
      }
    }
  }
  else if ( (v6 & 0x80u) == 0 )
  {
    *errno() = 22;
    return -1i64;
  }
  if ( !v4 )
    return v11;
  if ( v6 & 1 )
  {
    if ( v1->_cnt )
    {
      v19 = (unsigned __int64)&v1->_ptr[v1->_cnt - (unsigned __int64)v1->_base];
      if ( v8[v9].osfile < 0 )
      {
        if ( lseeki64(v3, 0i64, 2) == v4 )
        {
          v20 = v1->_base;
          v21 = &v20[v19];
          while ( v20 < v21 )
          {
            if ( *v20 == 10 )
              ++v19;
            ++v20;
          }
          v22 = (v1->_flag & 0x2000) == 0;
        }
        else
        {
          if ( lseeki64(v3, v4, 0) < 0 )
            return -1i64;
          if ( v19 > 0x200 || !(v1->_flag & 8) || (v19 = 512i64, v1->_flag & 0x400) )
            v19 = v1->_bufsiz;
          v22 = (_pioinfo[v7][v9].osfile & 4) == 0;
        }
        if ( !v22 )
          ++v19;
      }
      if ( v10 == 1 )
        v19 >>= 1;
      v4 -= v19;
    }
    else
    {
      v11 = 0i64;
    }
  }
  if ( v10 == 1 )
    v11 >>= 1;
  return v11 + v4;
}

