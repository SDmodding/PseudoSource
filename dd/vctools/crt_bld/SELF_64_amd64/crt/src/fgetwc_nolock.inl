// File Line: 30
// RVA: 0x12DC3E8
int __fastcall fgetwc_nolock(_iobuf *stream)
{
  int result; // eax
  ioinfo *v3; // rsi
  __int64 v4; // rbx
  ioinfo *v5; // rax
  bool v6; // sf
  int v7; // ecx
  int v8; // ecx
  __int64 v9; // rbx
  int v10; // ebx
  int v11; // ecx
  int v12; // ecx
  int v13; // eax
  wchar_t pwc; // [rsp+48h] [rbp+10h] BYREF
  char s; // [rsp+50h] [rbp+18h] BYREF
  char v16; // [rsp+51h] [rbp+19h]

  if ( (int)ioinit() < 0 )
    return 0xFFFF;
  v3 = &_badioinfo;
  if ( (stream->_flag & 0x40) == 0 )
  {
    if ( (unsigned int)fileno(stream) == -1 || (unsigned int)fileno(stream) == -2 )
    {
      v5 = &_badioinfo;
    }
    else
    {
      v4 = (__int64)(int)fileno(stream) >> 5;
      v5 = &_pioinfo[v4][fileno(stream) & 0x1F];
    }
    if ( (*((_BYTE *)v5 + 56) & 0x7F) != 0 )
    {
      v6 = --stream->_cnt < 0;
      if ( v6 )
        v7 = filbuf(stream);
      else
        v7 = *(unsigned __int8 *)stream->_ptr++;
      if ( v7 == -1 )
        return 0xFFFF;
      v6 = --stream->_cnt < 0;
      LOBYTE(pwc) = v7;
      if ( v6 )
        v8 = filbuf(stream);
      else
        v8 = *(unsigned __int8 *)stream->_ptr++;
      if ( v8 == -1 )
        return 0xFFFF;
      HIBYTE(pwc) = v8;
      return pwc;
    }
    if ( (stream->_flag & 0x40) == 0 )
    {
      if ( (unsigned int)fileno(stream) != -1 && (unsigned int)fileno(stream) != -2 )
      {
        v9 = (__int64)(int)fileno(stream) >> 5;
        v3 = &_pioinfo[v9][fileno(stream) & 0x1F];
      }
      if ( v3->osfile < 0 )
      {
        v6 = --stream->_cnt < 0;
        v10 = 1;
        if ( v6 )
          v11 = filbuf(stream);
        else
          v11 = *(unsigned __int8 *)stream->_ptr++;
        if ( v11 == -1 )
          return 0xFFFF;
        s = v11;
        if ( (unsigned int)isleadbyte(v11) )
        {
          v6 = --stream->_cnt < 0;
          if ( v6 )
            v12 = filbuf(stream);
          else
            v12 = *(unsigned __int8 *)stream->_ptr++;
          if ( v12 == -1 )
          {
            ungetc(s, stream);
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
  v13 = stream->_cnt - 2;
  stream->_cnt = v13;
  if ( v13 < 0 )
    return filwbuf(stream);
  result = *(unsigned __int16 *)stream->_ptr;
  stream->_ptr += 2;
  return result;
}

