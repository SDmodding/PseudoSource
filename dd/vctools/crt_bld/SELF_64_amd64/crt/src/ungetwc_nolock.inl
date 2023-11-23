// File Line: 31
// RVA: 0x12DC5F4
__int64 __fastcall ungetwc_nolock(wchar_t ch, _iobuf *str)
{
  int v4; // esi
  ioinfo *v5; // r14
  __int64 v6; // rbx
  ioinfo *v7; // rax
  __int64 v8; // rbx
  char *v9; // rdx
  __int64 v10; // rdx
  char v11; // al
  char *v13; // rcx
  char *ptr; // rax
  int pRetValue; // [rsp+20h] [rbp-48h] BYREF
  wchar_t v16; // [rsp+24h] [rbp-44h]
  char dst[8]; // [rsp+28h] [rbp-40h] BYREF

  v16 = ch;
  if ( ch == 0xFFFF )
    return 0xFFFFi64;
  v4 = 2;
  if ( (str->_flag & 1) == 0 && (SLOBYTE(str->_flag) >= 0 || (str->_flag & 2) != 0) )
    return 0xFFFFi64;
  if ( !str->_base )
    getbuf(str);
  if ( (str->_flag & 0x40) != 0
    || ((v5 = &_badioinfo, (unsigned int)fileno(str) == -1) || (unsigned int)fileno(str) == -2
      ? (v7 = &_badioinfo)
      : (v6 = (__int64)(int)fileno(str) >> 5, v7 = &_pioinfo[v6][fileno(str) & 0x1F]),
        v7->osfile >= 0) )
  {
    v13 = str->_base + 2;
    if ( str->_ptr < v13 )
    {
      if ( str->_cnt || (unsigned __int64)str->_bufsiz < 2 )
        return 0xFFFFi64;
      str->_ptr = v13;
    }
    str->_ptr -= 2;
    ptr = str->_ptr;
    if ( (str->_flag & 0x40) != 0 )
    {
      if ( *(_WORD *)ptr != ch )
      {
        str->_ptr = ptr + 2;
        return 0xFFFFi64;
      }
    }
    else
    {
      *(_WORD *)ptr = ch;
    }
LABEL_27:
    str->_cnt += v4;
    str->_flag &= ~0x10u;
    str->_flag |= 1u;
    return ch;
  }
  if ( (unsigned int)fileno(str) != -1 && (unsigned int)fileno(str) != -2 )
  {
    v8 = (__int64)(int)fileno(str) >> 5;
    v5 = &_pioinfo[v8][fileno(str) & 0x1F];
  }
  if ( (*((_BYTE *)v5 + 56) & 0x7F) != 0 )
  {
    dst[0] = ch;
    pRetValue = 2;
    dst[1] = HIBYTE(v16);
  }
  else
  {
    if ( (unsigned int)wctomb_s(&pRetValue, dst, 5ui64, ch) )
      return 0xFFFFi64;
    v4 = pRetValue;
  }
  v9 = &str->_base[v4];
  if ( str->_ptr >= v9 )
    goto LABEL_24;
  if ( !str->_cnt && v4 <= str->_bufsiz )
  {
    str->_ptr = v9;
LABEL_24:
    v10 = v4 - 1;
    if ( v4 - 1 >= 0 )
    {
      do
      {
        --str->_ptr;
        v11 = dst[v10--];
        *str->_ptr = v11;
      }
      while ( v10 >= 0 );
      v4 = pRetValue;
    }
    goto LABEL_27;
  }
  return 0xFFFFi64;
}

