// File Line: 170
// RVA: 0x979600
bool __fastcall Scaleform::Render::Text::WordWrapHelper::FindCharWithFlags(unsigned int wwMode, wchar_t c, unsigned int charBreakFlags)
{
  unsigned __int8 v3; // r11
  wchar_t v4; // r9
  signed __int64 v6; // r8
  signed __int64 v7; // rcx
  signed __int64 v8; // rax
  wchar_t v9; // dx

  v3 = charBreakFlags;
  v4 = c;
  if ( !(wwMode & 2) )
    return 0;
  v6 = 112i64;
  v7 = 0i64;
  while ( 1 )
  {
    v8 = v7 + (v6 - v7) / 2;
    v9 = Scaleform::Render::Text::WordWrapHelper::CharBreakInfoArray[v8].Char;
    if ( v4 == v9 )
      break;
    if ( v4 >= v9 )
      v7 = v8 + 1;
    else
      v6 = v8 - 1;
    if ( v7 > v6 )
      return 0;
  }
  return (v3 & Scaleform::Render::Text::WordWrapHelper::CharBreakInfoArray[v8].Flags) != 0;
}

// File Line: 194
// RVA: 0x97A940
unsigned __int64 __fastcall Scaleform::Render::Text::WordWrapHelper::FindWordWrapPos(unsigned int wwMode, unsigned __int64 wordWrapPos, const wchar_t *pparaText, unsigned __int64 paraLen, unsigned __int64 lineStartPos, unsigned __int64 lineLen)
{
  unsigned int v6; // ebp
  unsigned __int64 v7; // r14
  unsigned __int64 v8; // r15
  const wchar_t *v9; // rdi
  signed __int64 v10; // rbx
  wchar_t v11; // cx
  unsigned __int64 v12; // rax
  int v13; // er8
  int v14; // edx
  int v15; // ecx
  signed __int64 i; // rax
  wchar_t v17; // r10
  unsigned __int64 v18; // rcx
  int v19; // er9
  int v20; // edx
  unsigned __int64 j; // r8
  wchar_t v22; // r10
  unsigned __int64 v23; // rax
  int v24; // er9
  int v25; // ecx
  unsigned __int64 v26; // rax

  v6 = wwMode;
  if ( !(wwMode & 7) || !lineLen )
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
    v12 = (unsigned __int64)v9[v10] >> 8;
    v13 = Scaleform::UnicodeSpaceBits[v12];
    if ( Scaleform::UnicodeSpaceBits[v12] )
    {
      if ( v13 == 1 )
        break;
      v14 = v11 & 0xF;
      v15 = Scaleform::UnicodeSpaceBits[v13 + (((unsigned int)v11 >> 4) & 0xF)];
      if ( _bittest(&v15, v14) )
        break;
    }
LABEL_17:
    if ( !v10 || !Scaleform::Render::Text::WordWrapHelper::IsLineBreakOpportunityAt(v6, v9[v10 - 1], v9[v10]) )
    {
      if ( --v10 )
        continue;
    }
    goto LABEL_31;
  }
  for ( i = v10; i >= 0; --i )
  {
    v17 = v9[i];
    v18 = (unsigned __int64)v9[i] >> 8;
    v19 = Scaleform::UnicodeSpaceBits[v18];
    if ( !Scaleform::UnicodeSpaceBits[v18]
      || v19 != 1
      && (v20 = Scaleform::UnicodeSpaceBits[v19 + (((unsigned int)v17 >> 4) & 0xF)], !_bittest(&v20, v17 & 0xF)) )
    {
      if ( v17 != 10 )
        break;
    }
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
    v23 = (unsigned __int64)v9[j] >> 8;
    v24 = Scaleform::UnicodeSpaceBits[v23];
    if ( !Scaleform::UnicodeSpaceBits[v23] )
      break;
    if ( v24 != 1 )
    {
      v25 = Scaleform::UnicodeSpaceBits[v24 + (((unsigned int)v22 >> 4) & 0xF)];
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
    v26 = Scaleform::Render::Text::WordWrapHelper::FindNextNonWhiteSpace(v9, v10, v8 - 1);
    if ( v26 == -1i64 )
      v26 = lineLen - 1;
    v7 = v26;
  }
  return v7;
}

