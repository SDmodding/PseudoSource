// File Line: 88
// RVA: 0x12DCCEC
int __fastcall fputwc_nolock(wchar_t ch, _iobuf *str)
{
  ioinfo *v4; // rbp
  __int64 v5; // rbx
  ioinfo *v6; // rax
  __int64 v7; // rbx
  ioinfo *v8; // rax
  __int64 v9; // rbx
  int v10; // ebx
  char *i; // r14
  int v14; // ecx
  int v15; // eax
  int pRetValue; // [rsp+20h] [rbp-38h] BYREF
  char dst[12]; // [rsp+24h] [rbp-34h] BYREF

  if ( (str->_flag & 0x40) != 0 )
    goto LABEL_26;
  v4 = &_badioinfo;
  if ( (unsigned int)fileno(str) == -1 || (unsigned int)fileno(str) == -2 )
  {
    v6 = &_badioinfo;
  }
  else
  {
    v5 = (__int64)(int)fileno(str) >> 5;
    v6 = &_pioinfo[v5][fileno(str) & 0x1F];
  }
  if ( (*((_BYTE *)v6 + 56) & 0x7F) == 2 )
    goto LABEL_26;
  if ( (unsigned int)fileno(str) == -1 || (unsigned int)fileno(str) == -2 )
  {
    v8 = &_badioinfo;
  }
  else
  {
    v7 = (__int64)(int)fileno(str) >> 5;
    v8 = &_pioinfo[v7][fileno(str) & 0x1F];
  }
  if ( (*((_BYTE *)v8 + 56) & 0x7F) == 1 )
    goto LABEL_26;
  if ( (unsigned int)fileno(str) != -1 && (unsigned int)fileno(str) != -2 )
  {
    v9 = (__int64)(int)fileno(str) >> 5;
    v4 = &_pioinfo[v9][fileno(str) & 0x1F];
  }
  if ( v4->osfile >= 0 )
  {
LABEL_26:
    v15 = str->_cnt - 2;
    str->_cnt = v15;
    if ( v15 < 0 )
    {
      return flswbuf(ch, str);
    }
    else
    {
      *(_WORD *)str->_ptr = ch;
      str->_ptr += 2;
      return ch;
    }
  }
  else
  {
    v10 = 0;
    if ( (unsigned int)wctomb_s(&pRetValue, dst, 5ui64, ch) )
      return 0xFFFF;
    if ( pRetValue > 0 )
    {
      for ( i = dst; ; ++i )
      {
        if ( --str->_cnt < 0 )
        {
          v14 = flsbuf(*i, str);
        }
        else
        {
          *str->_ptr = *i;
          v14 = *(unsigned __int8 *)str->_ptr++;
        }
        if ( v14 == -1 )
          break;
        if ( ++v10 >= pRetValue )
          return ch;
      }
      return 0xFFFF;
    }
    return ch;
  }
}

