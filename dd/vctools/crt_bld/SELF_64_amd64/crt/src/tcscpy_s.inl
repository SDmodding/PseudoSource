// File Line: 13
// RVA: 0x12B93A4
__int64 __fastcall wcscpy_s(char *_Dst, unsigned __int64 _SizeInWords, const wchar_t *_Src)
{
  int *v3; // rax
  unsigned int v4; // ebx
  signed __int64 v6; // r9
  __int16 v7; // ax

  if ( !_Dst || !_SizeInWords )
    goto LABEL_5;
  if ( !_Src )
  {
    *(_WORD *)_Dst = 0;
LABEL_5:
    v3 = errno();
    v4 = 22;
LABEL_6:
    *v3 = v4;
    invalid_parameter_noinfo();
    return v4;
  }
  v6 = _Dst - (char *)_Src;
  do
  {
    v7 = *_Src;
    *(const wchar_t *)((char *)_Src + v6) = *_Src;
    ++_Src;
    if ( !v7 )
      break;
    --_SizeInWords;
  }
  while ( _SizeInWords );
  if ( !_SizeInWords )
  {
    *(_WORD *)_Dst = 0;
    v3 = errno();
    v4 = 34;
    goto LABEL_6;
  }
  return 0i64;
}

