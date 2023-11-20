// File Line: 74
// RVA: 0x12D61D8
__int64 __fastcall iswctype(unsigned __int16 c, unsigned __int16 mask)
{
  unsigned __int16 v2; // bx
  unsigned __int16 v4; // ax
  BOOL v5; // eax
  unsigned __int16 v6; // cx
  wchar_t SrcStr; // [rsp+30h] [rbp+8h]
  unsigned __int16 CharType; // [rsp+40h] [rbp+18h]

  SrcStr = c;
  v2 = mask;
  if ( c == -1 )
    return 0i64;
  if ( c >= 0x100u )
  {
    v5 = GetStringTypeW(1u, &SrcStr, 1, &CharType);
    v6 = 0;
    if ( v5 )
      v6 = CharType;
    v4 = v6;
  }
  else
  {
    v4 = pwctype[c];
  }
  return (unsigned __int16)(v2 & v4);
}

