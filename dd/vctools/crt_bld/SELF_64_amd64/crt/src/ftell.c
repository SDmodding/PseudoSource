// File Line: 45
// RVA: 0x12B9998
signed __int64 __fastcall ftell(_iobuf *stream)
{
  _iobuf *v1; // rbx
  signed __int64 result; // rax
  unsigned int v3; // edi

  v1 = stream;
  if ( stream )
  {
    lock_file(stream);
    v3 = ftell_nolock(v1);
    unlock_file(v1);
    result = v3;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 82
// RVA: 0x12B96A4
signed __int64 __fastcall ftell_nolock(_iobuf *str)
{
  _iobuf *v1; // rdi
  int v3; // eax
  __int64 v4; // rbp
  int v5; // eax
  unsigned int v6; // esi
  int v7; // edx
  __int64 v8; // r13
  ioinfo *v9; // rcx
  unsigned __int64 v10; // r15
  char v11; // r12
  unsigned int v12; // er14
  unsigned __int64 v13; // rbx
  __int64 v14; // rax
  ioinfo *v15; // rcx
  __int64 v16; // rdi
  char *v17; // rcx
  char *v18; // rdx
  char *i; // rax
  unsigned int v20; // ebx
  char *v21; // rax
  char *v22; // rcx
  bool v23; // zf
  unsigned int NumberOfBytesRead; // [rsp+30h] [rbp-1048h]
  char Buffer[4096]; // [rsp+40h] [rbp-1038h]

  v1 = str;
  if ( !str )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  v3 = fileno(str);
  v4 = v3;
  if ( v1->_cnt < 0 )
    v1->_cnt = 0;
  v5 = lseek(v3, 0, 1);
  v6 = v5;
  if ( v5 < 0 )
    return 0xFFFFFFFFi64;
  v7 = v1->_flag;
  v8 = v4 >> 5;
  v9 = _pioinfo[v4 >> 5];
  v10 = v4 & 0x1F;
  v11 = (char)(2 * *((_BYTE *)&v9[v10] + 56)) >> 1;
  if ( !(v7 & 0x108) )
    return (unsigned int)(v5 - v1->_cnt);
  v12 = LODWORD(v1->_ptr) - LODWORD(v1->_base);
  if ( !(v7 & 3) )
  {
    if ( (v7 & 0x80u) == 0 )
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
      for ( i = v1->_base; i < v1->_ptr; ++i )
      {
        if ( *i == 10 )
          ++v12;
      }
    }
LABEL_34:
    if ( !v6 )
      return v12;
    if ( v7 & 1 )
    {
      if ( v1->_cnt )
      {
        v20 = v1->_cnt + LODWORD(v1->_ptr) - LODWORD(v1->_base);
        if ( v9[v10].osfile < 0 )
        {
          if ( lseek(v4, 0, 2) == v6 )
          {
            v21 = v1->_base;
            v22 = &v21[v20];
            while ( v21 < v22 )
            {
              if ( *v21 == 10 )
                ++v20;
              ++v21;
            }
            v23 = (v1->_flag & 0x2000) == 0;
          }
          else
          {
            if ( lseek(v4, v6, 0) < 0 )
              return 0xFFFFFFFFi64;
            if ( v20 > 0x200 || !(v1->_flag & 8) || (v20 = 512, v1->_flag & 0x400) )
              v20 = v1->_bufsiz;
            v23 = (_pioinfo[v8][v10].osfile & 4) == 0;
          }
          if ( !v23 )
            ++v20;
          if ( v11 == 1 )
            v20 >>= 1;
        }
        v6 -= v20;
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
  v13 = (_QWORD)(v1->_ptr - v1->_base) >> 1;
  if ( !v1->_cnt )
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
      if ( *v17++ == 13 )
      {
        if ( v17 < v18 - 1 && v17[1] == 10 )
          ++v17;
      }
      else
      {
        v17 += lookuptrailbytes[(unsigned __int8)*v17];
      }
    }
    while ( v13 );
  }
  return v16 + v17 - Buffer;
}

