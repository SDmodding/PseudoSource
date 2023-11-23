// File Line: 52
// RVA: 0x9973F0
bool __fastcall Scaleform::Render::Text::WordWrapHelper::IsAsianChar(char wwMode, wchar_t c)
{
  if ( (wwMode & 4) != 0
    && ((unsigned __int16)(c - 4352) <= 0xFFu
     || (unsigned __int16)(c - 12592) <= 0x5Fu
     || (unsigned __int16)(c + 21504) <= 0x2BA3u) )
  {
    return 0;
  }
  return (unsigned __int16)(c - 4352) <= 0xFFu
      || (unsigned __int16)(c - 12288) <= 0xA7AFu
      || (unsigned __int16)(c + 1792) <= 0x1FFu
      || (unsigned __int16)(c + 256) <= 0xDCu;
}

// File Line: 91
// RVA: 0x997990
char __fastcall Scaleform::Render::Text::WordWrapHelper::IsLineBreakOpportunityAt(
        char wwMode,
        wchar_t prevChar,
        wchar_t curChar)
{
  unsigned __int64 v7; // rax
  int v8; // r8d
  int v9; // ecx
  unsigned __int64 v10; // rax
  int v11; // r8d
  int v12; // ecx
  char v13; // di

  if ( !prevChar )
    return 0;
  v7 = (unsigned __int64)prevChar >> 8;
  v8 = Scaleform::UnicodeSpaceBits[v7];
  if ( !Scaleform::UnicodeSpaceBits[v7]
    || v8 != 1 && (v9 = Scaleform::UnicodeSpaceBits[v8 + ((prevChar >> 4) & 0xF)], !_bittest(&v9, prevChar & 0xF)) )
  {
    if ( !Scaleform::Render::Text::WordWrapHelper::IsAsianChar(wwMode, curChar)
      && !Scaleform::Render::Text::WordWrapHelper::IsAsianChar(wwMode, prevChar)
      && prevChar != 45 )
    {
      return 0;
    }
  }
  v10 = (unsigned __int64)curChar >> 8;
  v11 = Scaleform::UnicodeSpaceBits[v10];
  if ( Scaleform::UnicodeSpaceBits[v10] )
  {
    if ( v11 == 1 )
      return 0;
    v12 = Scaleform::UnicodeSpaceBits[v11 + ((curChar >> 4) & 0xF)];
    if ( _bittest(&v12, curChar & 0xF) )
      return 0;
  }
  v13 = 1;
  if ( Scaleform::Render::Text::WordWrapHelper::FindCharWithFlags(wwMode, curChar, 1u)
    || Scaleform::Render::Text::WordWrapHelper::FindCharWithFlags(wwMode, prevChar, 2u) )
  {
    return 0;
  }
  return v13;
}

// File Line: 101
// RVA: 0x97A8B0
unsigned __int64 __fastcall Scaleform::Render::Text::WordWrapHelper::FindNextNonWhiteSpace(
        const wchar_t *pwstr,
        unsigned __int64 pos,
        unsigned __int64 maxPos)
{
  wchar_t v4; // r10
  unsigned __int64 v5; // rax
  int v6; // r9d
  int v7; // ecx
  unsigned __int64 result; // rax

  while ( 1 )
  {
    v4 = pwstr[pos];
    v5 = (unsigned __int64)v4 >> 8;
    v6 = Scaleform::UnicodeSpaceBits[v5];
    if ( !Scaleform::UnicodeSpaceBits[v5] )
      break;
    if ( v6 != 1 )
    {
      v7 = Scaleform::UnicodeSpaceBits[v6 + ((v4 >> 4) & 0xF)];
      if ( !_bittest(&v7, v4 & 0xF) )
        break;
    }
    ++pos;
  }
  if ( pwstr && v4 == 10 )
    ++pos;
  result = -1i64;
  if ( pos <= maxPos )
    return pos;
  return result;
}

