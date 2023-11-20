// File Line: 88
// RVA: 0x12DCCEC
int __fastcall fputwc_nolock(wchar_t ch, _iobuf *str)
{
  _iobuf *v2; // rdi
  wchar_t v3; // si
  ioinfo *v4; // rbp
  signed __int64 v5; // rbx
  ioinfo *v6; // rax
  signed __int64 v7; // rbx
  ioinfo *v8; // rax
  signed __int64 v9; // rbx
  int v10; // ebx
  int result; // eax
  char *v12; // r14
  bool v13; // sf
  int v14; // ecx
  int v15; // eax
  int pRetValue; // [rsp+20h] [rbp-38h]
  char dst; // [rsp+24h] [rbp-34h]

  v2 = str;
  v3 = ch;
  if ( str->_flag & 0x40 )
    goto LABEL_31;
  v4 = &_badioinfo;
  if ( (unsigned int)fileno(str) == -1 || (unsigned int)fileno(v2) == -2 )
  {
    v6 = &_badioinfo;
  }
  else
  {
    v5 = (signed __int64)(signed int)fileno(v2) >> 5;
    v6 = &_pioinfo[v5][fileno(v2) & 0x1F];
  }
  if ( (*((_BYTE *)v6 + 56) & 0x7F) == 2 )
    goto LABEL_31;
  if ( (unsigned int)fileno(v2) == -1 || (unsigned int)fileno(v2) == -2 )
  {
    v8 = &_badioinfo;
  }
  else
  {
    v7 = (signed __int64)(signed int)fileno(v2) >> 5;
    v8 = &_pioinfo[v7][fileno(v2) & 0x1F];
  }
  if ( (*((_BYTE *)v8 + 56) & 0x7F) == 1 )
    goto LABEL_31;
  if ( (unsigned int)fileno(v2) != -1 && (unsigned int)fileno(v2) != -2 )
  {
    v9 = (signed __int64)(signed int)fileno(v2) >> 5;
    v4 = &_pioinfo[v9][fileno(v2) & 0x1F];
  }
  if ( v4->osfile >= 0 )
  {
LABEL_31:
    v15 = v2->_cnt - 2;
    v2->_cnt = v15;
    if ( v15 < 0 )
    {
      result = flswbuf(v3, v2);
    }
    else
    {
      *(_WORD *)v2->_ptr = v3;
      v2->_ptr += 2;
      result = v3;
    }
  }
  else
  {
    v10 = 0;
    if ( (unsigned int)wctomb_s(&pRetValue, &dst, 5ui64, v3) )
      return 0xFFFF;
    if ( pRetValue > 0 )
    {
      v12 = &dst;
      do
      {
        v13 = v2->_cnt-- - 1 < 0;
        if ( v13 )
        {
          v14 = flsbuf(*v12, v2);
        }
        else
        {
          *v2->_ptr = *v12;
          v14 = *(unsigned __int8 *)v2->_ptr++;
        }
        if ( v14 == -1 )
          return 0xFFFF;
        ++v10;
        ++v12;
      }
      while ( v10 < pRetValue );
    }
    result = v3;
  }
  return result;
}

