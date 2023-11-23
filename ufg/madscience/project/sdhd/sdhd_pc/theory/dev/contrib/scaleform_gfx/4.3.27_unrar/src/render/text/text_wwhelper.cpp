// File Line: 170
// RVA: 0x979600
bool __fastcall Scaleform::Render::Text::WordWrapHelper::FindCharWithFlags(
        char wwMode,
        wchar_t c,
        unsigned __int8 charBreakFlags)
{
  __int64 v6; // r8
  __int64 v7; // rcx
  __int64 v8; // rax
  wchar_t Char; // dx

  if ( (wwMode & 2) == 0 )
    return 0;
  v6 = 112i64;
  v7 = 0i64;
  while ( 1 )
  {
    v8 = v7 + (v6 - v7) / 2;
    Char = Scaleform::Render::Text::WordWrapHelper::CharBreakInfoArray[v8].Char;
    if ( c == Char )
      break;
    if ( c >= Char )
      v7 = v8 + 1;
    else
      v6 = v8 - 1;
    if ( v7 > v6 )
      return 0;
  }
  return (charBreakFlags & Scaleform::Render::Text::WordWrapHelper::CharBreakInfoArray[v8].Flags) != 0;
}

// File Line: 194
// RVA: 0x97A940
unsigned __int64 __fastcall Scaleform::Render::Text::WordWrapHelper::FindWordWrapPos(
        unsigned int wwMode,
        unsigned __int64 wordWrapPos,
        const wchar_t *pparaText,
        unsigned __int64 paraLen,
        unsigned __int64 lineStartPos,
        unsigned __int64 lineLen)
{
  __int64 v7; // r14
  __int64 v8; // r15
  const wchar_t *v9; // rdi
  unsigned __int64 v10; // rbx
  wchar_t v11; // cx
  unsigned __int64 v12; // rax
  int v13; // r8d
  int v14; // edx
  int v15; // ecx
  __int64 i; // rax
  wchar_t v17; // r10
  unsigned __int64 v18; // rcx
  int v19; // r9d
  int v20; // edx
  unsigned __int64 j; // r8
  wchar_t v22; // r10
  unsigned __int64 v23; // rax
  int v24; // r9d
  int v25; // ecx
  unsigned __int64 NextNonWhiteSpace; // rax

  if ( (wwMode & 7) == 0 || !lineLen )
    return -1i64;
  v7 = lineLen - 1;
  v8 = paraLen - lineStartPos;
  v9 = &pparaText[lineStartPos];
  v10 = lineLen - 1;
  if ( lineLen == 1 )
    goto LABEL_31;
  while ( 1 )
  {
    v11 = v9[v10];
    v12 = (unsigned __int64)v11 >> 8;
    v13 = Scaleform::UnicodeSpaceBits[v12];
    if ( Scaleform::UnicodeSpaceBits[v12] )
    {
      if ( v13 == 1 )
        break;
      v14 = v11 & 0xF;
      v15 = Scaleform::UnicodeSpaceBits[v13 + ((v11 >> 4) & 0xF)];
      if ( _bittest(&v15, v14) )
        break;
    }
LABEL_17:
    if ( !v10 || !Scaleform::Render::Text::WordWrapHelper::IsLineBreakOpportunityAt(wwMode, v9[v10 - 1], v9[v10]) )
    {
      if ( --v10 )
        continue;
    }
    goto LABEL_31;
  }
  for ( i = v10; i >= 0; --i )
  {
    v17 = v9[i];
    v18 = (unsigned __int64)v17 >> 8;
    v19 = Scaleform::UnicodeSpaceBits[v18];
    if ( Scaleform::UnicodeSpaceBits[v18] )
    {
      if ( v19 == 1 )
        continue;
      v20 = Scaleform::UnicodeSpaceBits[v19 + ((v17 >> 4) & 0xF)];
      if ( _bittest(&v20, v17 & 0xF) )
        continue;
    }
    if ( v17 != 10 )
      break;
  }
  if ( i < 0 )
    i = -1i64;
  if ( i != -1 )
  {
    v10 = i + 1;
    goto LABEL_17;
  }
  for ( j = v10 + 1; ; ++j )
  {
    v22 = v9[j];
    v23 = (unsigned __int64)v22 >> 8;
    v24 = Scaleform::UnicodeSpaceBits[v23];
    if ( !Scaleform::UnicodeSpaceBits[v23] )
      break;
    if ( v24 != 1 )
    {
      v25 = Scaleform::UnicodeSpaceBits[v24 + ((v22 >> 4) & 0xF)];
      if ( !_bittest(&v25, v22 & 0xF) )
        break;
    }
  }
  if ( v9 && v22 == 10 )
    ++j;
  v10 = -1i64;
  if ( j <= v8 - 1 )
    v10 = j;
LABEL_31:
  if ( v10 )
  {
    NextNonWhiteSpace = Scaleform::Render::Text::WordWrapHelper::FindNextNonWhiteSpace(v9, v10, v8 - 1);
    if ( NextNonWhiteSpace == -1i64 )
      return lineLen - 1;
    return NextNonWhiteSpace;
  }
  return v7;
}

