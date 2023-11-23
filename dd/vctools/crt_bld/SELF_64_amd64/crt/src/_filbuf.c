// File Line: 100
// RVA: 0x12DD008
__int64 __fastcall filwbuf(_iobuf *str)
{
  int flag; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  __int64 v6; // rbx
  ioinfo *v7; // rax
  char *ptr; // rcx
  __int64 result; // rax

  if ( !str )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFi64;
  }
  if ( (int)ioinit() < 0 )
    return 0xFFFFi64;
  flag = str->_flag;
  if ( (flag & 0x83) == 0 || (flag & 0x40) != 0 )
    return 0xFFFFi64;
  if ( (flag & 2) != 0 )
  {
    str->_flag = flag | 0x20;
    return 0xFFFFi64;
  }
  v3 = flag | 1;
  str->_flag = v3;
  if ( (v3 & 0x10C) != 0 )
    str->_ptr = str->_base;
  else
    getbuf(str);
  v4 = fileno(str);
  v5 = read(v4, str->_base, str->_bufsiz);
  str->_cnt = v5;
  if ( (unsigned int)(v5 + 1) <= 2 )
  {
    str->_flag |= v5 != 0 ? 32 : 16;
    str->_cnt = 0;
    return 0xFFFFi64;
  }
  if ( (str->_flag & 0x82) == 0 )
  {
    if ( (unsigned int)fileno(str) == -1 || (unsigned int)fileno(str) == -2 )
    {
      v7 = &_badioinfo;
    }
    else
    {
      v6 = (__int64)(int)fileno(str) >> 5;
      v7 = &_pioinfo[v6][fileno(str) & 0x1F];
    }
    if ( (v7->osfile & 0x82) == 0x82 )
      str->_flag |= 0x2000u;
  }
  if ( str->_bufsiz == 512 && (str->_flag & 8) != 0 && (str->_flag & 0x400) == 0 )
    str->_bufsiz = 4096;
  ptr = str->_ptr;
  str->_cnt -= 2;
  result = *(unsigned __int16 *)ptr;
  str->_ptr = ptr + 2;
  return result;
}

