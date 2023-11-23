// File Line: 45
// RVA: 0x12B9998
__int64 __fastcall ftell(_iobuf *stream)
{
  unsigned int v3; // edi

  if ( stream )
  {
    lock_file(stream);
    v3 = ftell_nolock(stream);
    unlock_file(stream);
    return v3;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
}

// File Line: 82
// RVA: 0x12B96A4
__int64 __fastcall ftell_nolock(_iobuf *str)
{
  int v3; // eax
  __int64 v4; // rbp
  int v5; // eax
  unsigned int v6; // esi
  int flag; // edx
  __int64 v8; // r13
  ioinfo *v9; // rcx
  unsigned __int64 v10; // r15
  char v11; // r12
  unsigned int v12; // r14d
  unsigned __int64 v13; // rbx
  __int64 v14; // rax
  ioinfo *v15; // rcx
  __int64 v16; // rdi
  char *v17; // rcx
  char *v18; // rdx
  char *i; // rax
  unsigned int bufsiz; // ebx
  char *base; // rax
  char *v22; // rcx
  bool v23; // zf
  unsigned int NumberOfBytesRead; // [rsp+30h] [rbp-1048h] BYREF
  char Buffer[4096]; // [rsp+40h] [rbp-1038h] BYREF

  if ( !str )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  v3 = fileno(str);
  v4 = v3;
  if ( str->_cnt < 0 )
    str->_cnt = 0;
  v5 = lseek(v3, 0, 1);
  v6 = v5;
  if ( v5 < 0 )
    return 0xFFFFFFFFi64;
  flag = str->_flag;
  v8 = v4 >> 5;
  v9 = _pioinfo[v4 >> 5];
  v10 = v4 & 0x1F;
  v11 = (char)(2 * *((_BYTE *)&v9[v10] + 56)) >> 1;
  if ( (flag & 0x108) == 0 )
    return (unsigned int)(v5 - str->_cnt);
  v12 = LODWORD(str->_ptr) - LODWORD(str->_base);
  if ( (flag & 3) == 0 )
  {
    if ( (flag & 0x80u) == 0 )
    {
      *errno() = 22;
      return 0xFFFFFFFFi64;
    }
    goto LABEL_34;
  }
  if ( v11 != 1 || !v9[v10].utf8translations )
  {
    if ( v9[v10].osfile < 0 )
    {
      for ( i = str->_base; i < str->_ptr; ++i )
      {
        if ( *i == 10 )
          ++v12;
      }
    }
LABEL_34:
    if ( !v6 )
      return v12;
    if ( (flag & 1) != 0 )
    {
      if ( str->_cnt )
      {
        bufsiz = str->_cnt + LODWORD(str->_ptr) - LODWORD(str->_base);
        if ( v9[v10].osfile < 0 )
        {
          if ( lseek(v4, 0, 2) == v6 )
          {
            base = str->_base;
            v22 = &base[bufsiz];
            while ( base < v22 )
            {
              if ( *base == 10 )
                ++bufsiz;
              ++base;
            }
            v23 = (str->_flag & 0x2000) == 0;
          }
          else
          {
            if ( lseek(v4, v6, 0) < 0 )
              return 0xFFFFFFFFi64;
            if ( bufsiz > 0x200 || (str->_flag & 8) == 0 || (bufsiz = 512, (str->_flag & 0x400) != 0) )
              bufsiz = str->_bufsiz;
            v23 = (_pioinfo[v8][v10].osfile & 4) == 0;
          }
          if ( !v23 )
            ++bufsiz;
          if ( v11 == 1 )
            bufsiz >>= 1;
        }
        v6 -= bufsiz;
      }
      else
      {
        v12 = 0;
      }
    }
    if ( v11 == 1 )
      v12 >>= 1;
    return v12 + v6;
  }
  v13 = (unsigned __int64)(str->_ptr - str->_base) >> 1;
  if ( !str->_cnt )
    return v6;
  v14 = lseeki64(v4, v9[v10].startpos, 0);
  v15 = _pioinfo[v8];
  v16 = v14;
  if ( v14 != v15[v10].startpos
    || !ReadFile((HANDLE)v15[v10].osfhnd, Buffer, 0x1000u, &NumberOfBytesRead, 0i64)
    || lseek(v4, v6, 0) < 0
    || v13 > NumberOfBytesRead )
  {
    return 0xFFFFFFFFi64;
  }
  v17 = Buffer;
  if ( v13 )
  {
    v18 = &Buffer[NumberOfBytesRead];
    do
    {
      --v13;
      if ( v17 >= v18 )
        break;
      if ( *v17 == 13 )
      {
        if ( v17 < v18 - 1 && v17[1] == 10 )
          ++v17;
      }
      else
      {
        v17 += lookuptrailbytes[(unsigned __int8)*v17];
      }
      ++v17;
    }
    while ( v13 );
  }
  return v16 + v17 - Buffer;
}

