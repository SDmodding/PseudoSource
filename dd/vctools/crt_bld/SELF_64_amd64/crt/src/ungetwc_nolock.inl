// File Line: 31
// RVA: 0x12DC5F4
signed __int64 __fastcall ungetwc_nolock(unsigned __int16 ch, _iobuf *str)
{
  _iobuf *v2; // rdi
  unsigned __int16 v3; // bp
  int v4; // esi
  ioinfo *v5; // r14
  signed __int64 v6; // rbx
  ioinfo *v7; // rax
  signed __int64 v8; // rbx
  char *v9; // rdx
  __int64 v10; // rdx
  char v11; // al
  unsigned __int64 v13; // rcx
  _WORD *v14; // rax
  int pRetValue; // [rsp+20h] [rbp-48h]
  unsigned __int16 v16; // [rsp+24h] [rbp-44h]
  char dst; // [rsp+28h] [rbp-40h]
  char v18; // [rsp+29h] [rbp-3Fh]

  v2 = str;
  v3 = ch;
  v16 = ch;
  if ( ch == -1 )
    return 0xFFFFi64;
  v4 = 2;
  if ( !(str->_flag & 1) && (SLOBYTE(str->_flag) >= 0 || str->_flag & 2) )
    return 0xFFFFi64;
  if ( !str->_base )
    getbuf(str);
  if ( v2->_flag & 0x40
    || ((v5 = &_badioinfo, (unsigned int)fileno(v2) == -1) || (unsigned int)fileno(v2) == -2 ? (v7 = &_badioinfo) : (v6 = (signed __int64)(signed int)fileno(v2) >> 5, v7 = &_pioinfo[v6][fileno(v2) & 0x1F]),
        v7->osfile >= 0) )
  {
    v13 = (unsigned __int64)(v2->_base + 2);
    if ( v2->_ptr < (char *)v13 )
    {
      if ( v2->_cnt || (unsigned __int64)v2->_bufsiz < 2 )
        return 0xFFFFi64;
      v2->_ptr = (char *)v13;
    }
    v2->_ptr -= 2;
    v14 = v2->_ptr;
    if ( v2->_flag & 0x40 )
    {
      if ( *v14 != v3 )
      {
        v2->_ptr = (char *)(v14 + 1);
        return 0xFFFFi64;
      }
    }
    else
    {
      *v14 = v3;
    }
LABEL_27:
    v2->_cnt += v4;
    v2->_flag &= 0xFFFFFFEF;
    v2->_flag |= 1u;
    return v3;
  }
  if ( (unsigned int)fileno(v2) != -1 && (unsigned int)fileno(v2) != -2 )
  {
    v8 = (signed __int64)(signed int)fileno(v2) >> 5;
    v5 = &_pioinfo[v8][fileno(v2) & 0x1F];
  }
  if ( *((_BYTE *)v5 + 56) & 0x7F )
  {
    dst = v3;
    pRetValue = 2;
    v18 = HIBYTE(v16);
  }
  else
  {
    if ( (unsigned int)wctomb_s(&pRetValue, &dst, 5ui64, v3) )
      return 0xFFFFi64;
    v4 = pRetValue;
  }
  v9 = &v2->_base[v4];
  if ( v2->_ptr >= v9 )
    goto LABEL_24;
  if ( !v2->_cnt && v4 <= v2->_bufsiz )
  {
    v2->_ptr = v9;
LABEL_24:
    v10 = v4 - 1;
    if ( v4 - 1 >= 0 )
    {
      do
      {
        --v2->_ptr;
        v11 = *(&dst + v10--);
        *v2->_ptr = v11;
      }
      while ( v10 >= 0 );
      v4 = pRetValue;
    }
    goto LABEL_27;
  }
  return 0xFFFFi64;
}

