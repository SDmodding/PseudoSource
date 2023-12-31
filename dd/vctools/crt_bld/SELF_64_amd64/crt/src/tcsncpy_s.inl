// File Line: 13
// RVA: 0x12B2004
__int64 __fastcall wcsncpy_s(char *_Dst, unsigned __int64 _SizeInWords, const wchar_t *_Src, unsigned __int64 _Count)
{
  int *v5; // rax
  unsigned int v6; // ebx
  char *v7; // r11
  unsigned __int64 v8; // r10
  signed __int64 v9; // r11
  __int16 v10; // ax
  signed __int64 v11; // r8
  __int16 v12; // ax

  if ( _Count )
  {
    if ( !_Dst )
    {
LABEL_11:
      v5 = errno();
      v6 = 22;
LABEL_12:
      *v5 = v6;
      invalid_parameter_noinfo();
      return v6;
    }
  }
  else if ( !_Dst )
  {
    if ( !_SizeInWords )
      return 0i64;
    goto LABEL_11;
  }
  if ( !_SizeInWords )
    goto LABEL_11;
  if ( !_Count )
  {
    *(_WORD *)_Dst = 0;
    return 0i64;
  }
  if ( !_Src )
  {
    *(_WORD *)_Dst = 0;
    goto LABEL_11;
  }
  v7 = _Dst;
  v8 = _SizeInWords;
  if ( _Count == -1i64 )
  {
    v9 = _Dst - (char *)_Src;
    do
    {
      v10 = *_Src;
      *(const wchar_t *)((char *)_Src + v9) = *_Src;
      ++_Src;
      if ( !v10 )
        break;
      --v8;
    }
    while ( v8 );
  }
  else
  {
    v11 = (char *)_Src - _Dst;
    do
    {
      v12 = *(_WORD *)&v7[v11];
      *(_WORD *)v7 = v12;
      v7 += 2;
      if ( !v12 )
        break;
      if ( !--v8 )
        break;
      --_Count;
    }
    while ( _Count );
    if ( !_Count )
      *(_WORD *)v7 = 0;
  }
  if ( v8 )
    return 0i64;
  if ( _Count != -1i64 )
  {
    *(_WORD *)_Dst = 0;
    v5 = errno();
    v6 = 34;
    goto LABEL_12;
  }
  *(_WORD *)&_Dst[2 * _SizeInWords - 2] = 0;
  return 80i64;
}

