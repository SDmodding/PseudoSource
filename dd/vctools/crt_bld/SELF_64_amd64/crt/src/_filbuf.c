// File Line: 100
// RVA: 0x12DD008
signed __int64 __fastcall filwbuf(_iobuf *str)
{
  _iobuf *v1; // rdi
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  signed __int64 v6; // rbx
  ioinfo *v7; // rax
  char *v8; // rcx
  signed __int64 result; // rax

  v1 = str;
  if ( !str )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFi64;
  }
  if ( (signed int)ioinit() < 0 )
    return 0xFFFFi64;
  v2 = v1->_flag;
  if ( !(v2 & 0x83) || v2 & 0x40 )
    return 0xFFFFi64;
  if ( v2 & 2 )
  {
    v1->_flag = v2 | 0x20;
    return 0xFFFFi64;
  }
  v3 = v2 | 1;
  v1->_flag = v3;
  if ( v3 & 0x10C )
    v1->_ptr = v1->_base;
  else
    getbuf(v1);
  v4 = fileno(v1);
  v5 = read(v4, v1->_base, v1->_bufsiz);
  v1->_cnt = v5;
  if ( (unsigned int)(v5 + 1) <= 2 )
  {
    v1->_flag |= v5 != 0 ? 32 : 16;
    v1->_cnt = 0;
    return 0xFFFFi64;
  }
  if ( !(v1->_flag & 0x82) )
  {
    if ( (unsigned int)fileno(v1) == -1 || (unsigned int)fileno(v1) == -2 )
    {
      v7 = &_badioinfo;
    }
    else
    {
      v6 = (signed __int64)(signed int)fileno(v1) >> 5;
      v7 = &_pioinfo[v6][fileno(v1) & 0x1F];
    }
    if ( (v7->osfile & 0x82) == -126 )
      v1->_flag |= 0x2000u;
  }
  if ( v1->_bufsiz == 512 && v1->_flag & 8 && !(v1->_flag & 0x400) )
    v1->_bufsiz = 4096;
  v8 = v1->_ptr;
  v1->_cnt -= 2;
  result = *(unsigned __int16 *)v8;
  v1->_ptr = v8 + 2;
  return result;
}

