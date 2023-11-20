// File Line: 32
// RVA: 0x12BD3D0
signed __int64 __fastcall ungetc_nolock(int ch, _iobuf *str)
{
  _iobuf *v2; // rbx
  int v3; // edi
  int v4; // eax
  ioinfo *v5; // rdx
  ioinfo *v6; // r8
  char *v8; // rax

  v2 = str;
  v3 = ch;
  if ( !(str->_flag & 0x40) )
  {
    v4 = fileno(str);
    v5 = &_badioinfo;
    v6 = (unsigned int)(v4 + 2) <= 1 ? &_badioinfo : &_pioinfo[(signed __int64)v4 >> 5][v4 & 0x1F];
    if ( *((_BYTE *)v6 + 56) & 0x7F )
      goto LABEL_28;
    if ( (unsigned int)(v4 + 2) > 1 )
      v5 = &_pioinfo[(signed __int64)v4 >> 5][v4 & 0x1F];
    if ( *((_BYTE *)v5 + 56) < 0 )
    {
LABEL_28:
      *errno() = 22;
      invalid_parameter_noinfo();
      return 0xFFFFFFFFi64;
    }
  }
  if ( v3 == -1 || !(v2->_flag & 1) && (SLOBYTE(v2->_flag) >= 0 || v2->_flag & 2) )
    return 0xFFFFFFFFi64;
  if ( !v2->_base )
    getbuf(v2);
  if ( v2->_ptr == v2->_base )
  {
    if ( v2->_cnt )
      return 0xFFFFFFFFi64;
    ++v2->_ptr;
  }
  v8 = --v2->_ptr;
  if ( v2->_flag & 0x40 )
  {
    if ( *v8 != (_BYTE)v3 )
    {
      v2->_ptr = v8 + 1;
      return 0xFFFFFFFFi64;
    }
  }
  else
  {
    *v8 = v3;
  }
  ++v2->_cnt;
  v2->_flag &= 0xFFFFFFEF;
  v2->_flag |= 1u;
  return (unsigned __int8)v3;
}

