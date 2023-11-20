// File Line: 30
// RVA: 0x12DC3E8
int __fastcall fgetwc_nolock(_iobuf *stream)
{
  _iobuf *v1; // rdi
  int result; // eax
  ioinfo *v3; // rsi
  signed __int64 v4; // rbx
  ioinfo *v5; // rax
  bool v6; // sf
  int v7; // ecx
  int v8; // ecx
  signed __int64 v9; // rbx
  signed int v10; // ebx
  int v11; // ecx
  int v12; // ecx
  int v13; // eax
  wchar_t pwc; // [rsp+48h] [rbp+10h]
  char s; // [rsp+50h] [rbp+18h]
  char v16; // [rsp+51h] [rbp+19h]

  v1 = stream;
  if ( (signed int)ioinit() < 0 )
    return 0xFFFF;
  v3 = &_badioinfo;
  if ( !(v1->_flag & 0x40) )
  {
    if ( (unsigned int)fileno(v1) == -1 || (unsigned int)fileno(v1) == -2 )
    {
      v5 = &_badioinfo;
    }
    else
    {
      v4 = (signed __int64)(signed int)fileno(v1) >> 5;
      v5 = &_pioinfo[v4][fileno(v1) & 0x1F];
    }
    if ( *((_BYTE *)v5 + 56) & 0x7F )
    {
      v6 = v1->_cnt-- - 1 < 0;
      if ( v6 )
        v7 = filbuf(v1);
      else
        v7 = *(unsigned __int8 *)v1->_ptr++;
      if ( v7 == -1 )
        return 0xFFFF;
      v6 = v1->_cnt-- - 1 < 0;
      LOBYTE(pwc) = v7;
      if ( v6 )
        v8 = filbuf(v1);
      else
        v8 = *(unsigned __int8 *)v1->_ptr++;
      if ( v8 == -1 )
        return 0xFFFF;
      HIBYTE(pwc) = v8;
      return pwc;
    }
    if ( !(v1->_flag & 0x40) )
    {
      if ( (unsigned int)fileno(v1) != -1 && (unsigned int)fileno(v1) != -2 )
      {
        v9 = (signed __int64)(signed int)fileno(v1) >> 5;
        v3 = &_pioinfo[v9][fileno(v1) & 0x1F];
      }
      if ( v3->osfile < 0 )
      {
        v6 = v1->_cnt-- - 1 < 0;
        v10 = 1;
        if ( v6 )
          v11 = filbuf(v1);
        else
          v11 = *(unsigned __int8 *)v1->_ptr++;
        if ( v11 == -1 )
          return 0xFFFF;
        s = v11;
        if ( (unsigned int)isleadbyte((unsigned __int8)v11) )
        {
          v6 = v1->_cnt-- - 1 < 0;
          if ( v6 )
            v12 = filbuf(v1);
          else
            v12 = *(unsigned __int8 *)v1->_ptr++;
          if ( v12 == -1 )
          {
            ungetc(s, v1);
            return 0xFFFF;
          }
          v16 = v12;
          v10 = 2;
        }
        if ( (unsigned int)mbtowc(&pwc, &s, v10) != -1 )
          return pwc;
        *errno() = 42;
        return 0xFFFF;
      }
    }
  }
  v13 = v1->_cnt - 2;
  v1->_cnt = v13;
  if ( v13 < 0 )
    return filwbuf(v1);
  result = *(unsigned __int16 *)v1->_ptr;
  v1->_ptr += 2;
  return result;
}

