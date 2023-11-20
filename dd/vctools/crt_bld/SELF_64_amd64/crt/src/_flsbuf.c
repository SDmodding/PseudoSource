// File Line: 93
// RVA: 0x12C9D50
signed __int64 __fastcall flsbuf(int ch, _iobuf *str)
{
  _iobuf *v2; // rbx
  int v3; // edi
  int v5; // eax
  int v6; // ecx
  __int64 v7; // rsi
  int v8; // eax
  unsigned int v9; // eax
  char *v10; // rdx
  signed int v11; // ebp
  ioinfo *v12; // rcx
  int buf; // [rsp+30h] [rbp+8h]

  buf = ch;
  v2 = str;
  v3 = 0;
  if ( (signed int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  v5 = fileno(v2);
  v6 = v2->_flag;
  v7 = v5;
  if ( !(v6 & 0x82) )
  {
    *errno() = 9;
    goto LABEL_5;
  }
  if ( v6 & 0x40 )
  {
    *errno() = 34;
    goto LABEL_5;
  }
  if ( v6 & 1 )
  {
    v2->_cnt = 0;
    if ( !(v6 & 0x10) )
    {
      v2->_flag = v6 | 0x20;
      return 0xFFFFFFFFi64;
    }
    v2->_ptr = v2->_base;
    v2->_flag = v6 & 0xFFFFFFFE;
  }
  v8 = v2->_flag;
  v2->_cnt = 0;
  v9 = v8 & 0xFFFFFFEF | 2;
  v2->_flag = v9;
  if ( !(v9 & 0x10C) && (v2 != &_iob_func()[1] && v2 != &_iob_func()[2] || !(unsigned int)isatty(v7)) )
    getbuf(v2);
  if ( v2->_flag & 0x108 )
  {
    v10 = v2->_base;
    v11 = LODWORD(v2->_ptr) - LODWORD(v2->_base);
    v2->_ptr = v10 + 1;
    v2->_cnt = v2->_bufsiz - 1;
    if ( v11 <= 0 )
    {
      if ( (unsigned int)(v7 + 2) <= 1 )
        v12 = &_badioinfo;
      else
        v12 = &_pioinfo[v7 >> 5][v7 & 0x1F];
      if ( v12->osfile & 0x20 && lseeki64(v7, 0i64, 2) == -1 )
        goto LABEL_5;
    }
    else
    {
      v3 = write(v7, v10, v11);
    }
    *v2->_base = buf;
  }
  else
  {
    v11 = 1;
    v3 = write(v7, &buf, 1u);
  }
  if ( v3 != v11 )
  {
LABEL_5:
    v2->_flag |= 0x20u;
    return 0xFFFFFFFFi64;
  }
  return (unsigned __int8)buf;
}

