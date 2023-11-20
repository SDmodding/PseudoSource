// File Line: 52
// RVA: 0x9973F0
char __fastcall Scaleform::Render::Text::WordWrapHelper::IsAsianChar(unsigned int wwMode, wchar_t c)
{
  if ( wwMode & 4
    && ((unsigned __int16)(c - 4352) <= 0xFFu
     || (unsigned __int16)(c - 12592) <= 0x5Fu
     || (unsigned __int16)(c + 21504) <= 0x2BA3u) )
  {
    return 0;
  }
  if ( (unsigned __int16)(c - 4352) <= 0xFFu
    || (unsigned __int16)(c - 12288) <= 0xA7AFu
    || (unsigned __int16)(c + 1792) <= 0x1FFu
    || (unsigned __int16)(c + 256) <= 0xDCu )
  {
    return 1;
  }
  return 0;
}

// File Line: 91
// RVA: 0x997990
char __fastcall Scaleform::Render::Text::WordWrapHelper::IsLineBreakOpportunityAt(unsigned int wwMode, wchar_t prevChar, wchar_t curChar)
{
  wchar_t v3; // bp
  wchar_t v4; // bx
  unsigned int v5; // esi
  unsigned __int64 v7; // rax
  int v8; // er8
  int v9; // ecx
  unsigned __int64 v10; // rax
  int v11; // er8
  int v12; // ecx
  char v13; // di

  v3 = curChar;
  v4 = prevChar;
  v5 = wwMode;
  if ( !prevChar )
    return 0;
  v7 = (unsigned __int64)prevChar >> 8;
  v8 = Scaleform::UnicodeSpaceBits[v7];
  if ( (!Scaleform::UnicodeSpaceBits[v7]
     || v8 != 1
     && (v9 = Scaleform::UnicodeSpaceBits[v8 + (((unsigned int)prevChar >> 4) & 0xF)], !_bittest(&v9, prevChar & 0xF)))
    && !Scaleform::Render::Text::WordWrapHelper::IsAsianChar(v5, v3)
    && !Scaleform::Render::Text::WordWrapHelper::IsAsianChar(v5, v4)
    && v4 != 45
    || (v10 = (unsigned __int64)v3 >> 8, (v11 = Scaleform::UnicodeSpaceBits[v10]) != 0)
    && (v11 == 1 || (v12 = Scaleform::UnicodeSpaceBits[v11 + (((unsigned int)v3 >> 4) & 0xF)], _bittest(&v12, v3 & 0xF)))
    || (v13 = 1, Scaleform::Render::Text::WordWrapHelper::FindCharWithFlags(v5, v3, 1u))
    || Scaleform::Render::Text::WordWrapHelper::FindCharWithFlags(v5, v4, 2u) )
  {
    v13 = 0;
  }
  return v13;
}

// File Line: 101
// RVA: 0x97A8B0
unsigned __int64 __fastcall Scaleform::Render::Text::WordWrapHelper::FindNextNonWhiteSpace(const wchar_t *pwstr, unsigned __int64 pos, unsigned __int64 maxPos)
{
  const wchar_t *v3; // r11
  wchar_t v4; // r10
  unsigned __int64 v5; // rax
  int v6; // er9
  int v7; // ecx
  unsigned __int64 result; // rax

  v3 = pwstr;
  while ( 1 )
  {
    v4 = v3[pos];
    v5 = (unsigned __int64)v3[pos] >> 8;
    v6 = Scaleform::UnicodeSpaceBits[v5];
    if ( !Scaleform::UnicodeSpaceBits[v5] )
      break;
    if ( v6 != 1 )
    {
      v7 = Scaleform::UnicodeSpaceBits[v6 + (((unsigned int)v4 >> 4) & 0xF)];
      if ( !_bittest(&v7, v4 & 0xF) )
        break;
    }
    ++pos;
  }
  if ( v3 && v4 == 10 )
    ++pos;
  result = -1i64;
  if ( pos <= maxPos )
    result = pos;
  return result;
}

