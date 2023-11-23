// File Line: 45
// RVA: 0x12BD03C
__int64 __fastcall ftelli64(_iobuf *stream)
{
  __int64 v3; // rdi

  if ( !stream )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return -1i64;
  }
  if ( (int)ioinit() < 0 )
    return -1i64;
  lock_file(stream);
  v3 = ftelli64_nolock(stream);
  unlock_file(stream);
  return v3;
}

// File Line: 56
// RVA: 0x1451E41
_ftelli64$fin$0

// File Line: 81
// RVA: 0x12BD0A4
unsigned __int64 __fastcall ftelli64_nolock(_iobuf *str)
{
  int v2; // eax
  __int64 v3; // rbp
  __int64 v4; // rsi
  int flag; // edx
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
  unsigned __int64 bufsiz; // rbx
  char *base; // rax
  char *v21; // rcx
  bool v22; // zf
  unsigned int NumberOfBytesRead; // [rsp+30h] [rbp-1048h] BYREF
  char Buffer[4096]; // [rsp+40h] [rbp-1038h] BYREF

  v2 = fileno(str);
  v3 = v2;
  if ( str->_cnt < 0 )
    str->_cnt = 0;
  v4 = lseeki64(v2, 0i64, 1);
  if ( v4 < 0 )
    return -1i64;
  flag = str->_flag;
  v7 = v3 >> 5;
  v8 = _pioinfo[v3 >> 5];
  v9 = v3 & 0x1F;
  v10 = (char)(2 * *((_BYTE *)&v8[v9] + 56)) >> 1;
  if ( (flag & 0x108) == 0 )
  {
    v4 -= str->_cnt;
    return v4;
  }
  v11 = str->_ptr - str->_base;
  if ( (flag & 3) != 0 )
  {
    if ( v10 == 1 && v8[v9].utf8translations )
    {
      v12 = v11 >> 1;
      if ( !str->_cnt )
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
            if ( *v16 == 13 )
            {
              if ( v16 < v17 - 1 && v16[1] == 10 )
                ++v16;
            }
            else
            {
              v16 += lookuptrailbytes[(unsigned __int8)*v16];
            }
            ++v16;
          }
          while ( v12 );
        }
        return v15 + v16 - Buffer;
      }
      return -1i64;
    }
    if ( v8[v9].osfile < 0 )
    {
      for ( i = str->_base; i < str->_ptr; ++i )
      {
        if ( *i == 10 )
          ++v11;
      }
    }
  }
  else if ( (flag & 0x80u) == 0 )
  {
    *errno() = 22;
    return -1i64;
  }
  if ( !v4 )
    return v11;
  if ( (flag & 1) != 0 )
  {
    if ( str->_cnt )
    {
      bufsiz = (unsigned __int64)&str->_ptr[str->_cnt - (unsigned __int64)str->_base];
      if ( v8[v9].osfile < 0 )
      {
        if ( lseeki64(v3, 0i64, 2) == v4 )
        {
          base = str->_base;
          v21 = &base[bufsiz];
          while ( base < v21 )
          {
            if ( *base == 10 )
              ++bufsiz;
            ++base;
          }
          v22 = (str->_flag & 0x2000) == 0;
        }
        else
        {
          if ( lseeki64(v3, v4, 0) < 0 )
            return -1i64;
          if ( bufsiz > 0x200 || (str->_flag & 8) == 0 || (bufsiz = 512i64, (str->_flag & 0x400) != 0) )
            bufsiz = str->_bufsiz;
          v22 = (_pioinfo[v7][v9].osfile & 4) == 0;
        }
        if ( !v22 )
          ++bufsiz;
      }
      if ( v10 == 1 )
        bufsiz >>= 1;
      v4 -= bufsiz;
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

