// File Line: 93
// RVA: 0x12C9D50
__int64 __fastcall flsbuf(int ch, _iobuf *str)
{
  int v3; // edi
  int v5; // eax
  int flag; // ecx
  __int64 v7; // rsi
  int v8; // eax
  int v9; // eax
  char *base; // rdx
  signed int v11; // ebp
  ioinfo *v12; // rcx
  int buf; // [rsp+30h] [rbp+8h] BYREF

  buf = ch;
  v3 = 0;
  if ( (int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  v5 = fileno(str);
  flag = str->_flag;
  v7 = v5;
  if ( (flag & 0x82) == 0 )
  {
    *errno() = 9;
    goto LABEL_5;
  }
  if ( (flag & 0x40) != 0 )
  {
    *errno() = 34;
    goto LABEL_5;
  }
  if ( (flag & 1) != 0 )
  {
    str->_cnt = 0;
    if ( (flag & 0x10) == 0 )
    {
      str->_flag = flag | 0x20;
      return 0xFFFFFFFFi64;
    }
    str->_ptr = str->_base;
    str->_flag = flag & 0xFFFFFFFE;
  }
  v8 = str->_flag;
  str->_cnt = 0;
  v9 = v8 & 0xFFFFFFED | 2;
  str->_flag = v9;
  if ( (v9 & 0x10C) == 0 && (str != &_iob_func()[1] && str != &_iob_func()[2] || !(unsigned int)isatty(v7)) )
    getbuf(str);
  if ( (str->_flag & 0x108) != 0 )
  {
    base = str->_base;
    v11 = LODWORD(str->_ptr) - LODWORD(str->_base);
    str->_ptr = base + 1;
    str->_cnt = str->_bufsiz - 1;
    if ( v11 <= 0 )
    {
      if ( (unsigned int)(v7 + 2) <= 1 )
        v12 = &_badioinfo;
      else
        v12 = &_pioinfo[v7 >> 5][v7 & 0x1F];
      if ( (v12->osfile & 0x20) != 0 && lseeki64(v7, 0i64, 2) == -1 )
        goto LABEL_5;
    }
    else
    {
      v3 = write(v7, base, v11);
    }
    *str->_base = buf;
  }
  else
  {
    v11 = 1;
    v3 = write(v7, &buf, 1u);
  }
  if ( v3 != v11 )
  {
LABEL_5:
    str->_flag |= 0x20u;
    return 0xFFFFFFFFi64;
  }
  return (unsigned __int8)buf;
}

