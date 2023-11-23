// File Line: 32
// RVA: 0x12BD3D0
__int64 __fastcall ungetc_nolock(int ch, _iobuf *str)
{
  int v4; // eax
  ioinfo *v5; // rdx
  ioinfo *v6; // r8
  char *v8; // rax

  if ( (str->_flag & 0x40) == 0 )
  {
    v4 = fileno(str);
    v5 = &_badioinfo;
    v6 = (unsigned int)(v4 + 2) <= 1 ? &_badioinfo : &_pioinfo[(__int64)v4 >> 5][v4 & 0x1F];
    if ( (*((_BYTE *)v6 + 56) & 0x7F) != 0 )
      goto LABEL_9;
    if ( (unsigned int)(v4 + 2) > 1 )
      v5 = &_pioinfo[(__int64)v4 >> 5][v4 & 0x1F];
    if ( *((char *)v5 + 56) < 0 )
    {
LABEL_9:
      *errno() = 22;
      invalid_parameter_noinfo();
      return 0xFFFFFFFFi64;
    }
  }
  if ( ch == -1 || (str->_flag & 1) == 0 && (SLOBYTE(str->_flag) >= 0 || (str->_flag & 2) != 0) )
    return 0xFFFFFFFFi64;
  if ( !str->_base )
    getbuf(str);
  if ( str->_ptr == str->_base )
  {
    if ( str->_cnt )
      return 0xFFFFFFFFi64;
    ++str->_ptr;
  }
  v8 = --str->_ptr;
  if ( (str->_flag & 0x40) != 0 )
  {
    if ( *v8 != (_BYTE)ch )
    {
      str->_ptr = v8 + 1;
      return 0xFFFFFFFFi64;
    }
  }
  else
  {
    *v8 = ch;
  }
  ++str->_cnt;
  str->_flag &= ~0x10u;
  str->_flag |= 1u;
  return (unsigned __int8)ch;
}

