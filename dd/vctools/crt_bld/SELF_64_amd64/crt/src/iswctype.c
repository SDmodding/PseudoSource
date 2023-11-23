// File Line: 74
// RVA: 0x12D61D8
__int64 __fastcall iswctype(wchar_t c, unsigned __int16 mask)
{
  unsigned __int16 v4; // ax
  BOOL StringTypeW; // eax
  unsigned __int16 v6; // cx
  wchar_t SrcStr; // [rsp+30h] [rbp+8h] BYREF
  unsigned __int16 CharType; // [rsp+40h] [rbp+18h] BYREF

  SrcStr = c;
  if ( c == 0xFFFF )
    return 0i64;
  if ( c >= 0x100u )
  {
    StringTypeW = GetStringTypeW(1u, &SrcStr, 1, &CharType);
    v6 = 0;
    if ( StringTypeW )
      v6 = CharType;
    v4 = v6;
  }
  else
  {
    v4 = pwctype[c];
  }
  return (unsigned __int16)(mask & v4);
}

