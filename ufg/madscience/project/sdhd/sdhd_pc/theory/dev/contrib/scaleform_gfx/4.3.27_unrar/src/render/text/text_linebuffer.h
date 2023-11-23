// File Line: 304
// RVA: 0x897230
void __fastcall Scaleform::Render::Text::LineBuffer::GlyphIterator::GlyphIterator(
        Scaleform::Render::Text::LineBuffer::GlyphIterator *this,
        Scaleform::Render::Text::LineBuffer::GlyphEntry *pglyphs,
        unsigned int glyphsCount,
        Scaleform::Render::Text::LineBuffer::FormatDataEntry *pfmtData)
{
  this->HighlighterIter.CurDesc.StartPos = -1i64;
  this->HighlighterIter.CurDesc.Length = 0i64;
  this->HighlighterIter.CurDesc.Offset = -1i64;
  this->HighlighterIter.CurDesc.AdjStartPos = 0i64;
  this->HighlighterIter.CurDesc.GlyphNum = 0i64;
  *(_QWORD *)&this->HighlighterIter.CurDesc.Id = 0i64;
  *(_QWORD *)&this->HighlighterIter.CurDesc.Info.TextColor.Channels.Blue = 0i64;
  this->HighlighterIter.CurDesc.Info.Flags = 0;
  this->HighlighterIter.NumGlyphs = 0i64;
  this->HighlighterIter.CurAdjStartPos = 0i64;
  *(_QWORD *)&this->ColorV = 0i64;
  *(_QWORD *)&this->UnderlineColor = 0i64;
  this->pFontHandle.pObject = 0i64;
  this->pImage.pObject = 0i64;
  *(_QWORD *)&this->UnderlineStyle = 0i64;
  this->pGlyphs = pglyphs;
  this->pEndGlyphs = &pglyphs[glyphsCount];
  this->pNextFormatData = pfmtData;
  Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(this);
}

// File Line: 314
// RVA: 0x93C8F0
void __fastcall Scaleform::Render::Text::LineBuffer::GlyphIterator::GlyphIterator(
        Scaleform::Render::Text::LineBuffer::GlyphIterator *this,
        Scaleform::Render::Text::LineBuffer::GlyphEntry *pglyphs,
        unsigned int glyphsCount,
        Scaleform::Render::Text::LineBuffer::FormatDataEntry *pfmtData,
        Scaleform::Render::Text::Highlighter *highlighter,
        unsigned __int64 lineStartPos)
{
  __int64 v7; // rbx
  Scaleform::Render::Text::HighlighterPosIterator v10; // [rsp+28h] [rbp-58h] BYREF

  v7 = glyphsCount;
  this->HighlighterIter.CurDesc.StartPos = -1i64;
  this->HighlighterIter.CurDesc.Length = 0i64;
  this->HighlighterIter.CurDesc.Offset = -1i64;
  this->HighlighterIter.CurDesc.AdjStartPos = 0i64;
  this->HighlighterIter.CurDesc.GlyphNum = 0i64;
  *(_QWORD *)&this->HighlighterIter.CurDesc.Id = 0i64;
  *(_QWORD *)&this->HighlighterIter.CurDesc.Info.TextColor.Channels.Blue = 0i64;
  this->HighlighterIter.CurDesc.Info.Flags = 0;
  this->HighlighterIter.NumGlyphs = 0i64;
  this->HighlighterIter.CurAdjStartPos = 0i64;
  *(_QWORD *)&this->ColorV = 0i64;
  *(_QWORD *)&this->UnderlineColor = 0i64;
  this->pFontHandle.pObject = 0i64;
  this->pImage.pObject = 0i64;
  *(_QWORD *)&this->UnderlineStyle = 0i64;
  v10.pManager = highlighter;
  v10.CurAdjStartPos = lineStartPos;
  v10.NumGlyphs = -1i64;
  v10.CurDesc.StartPos = -1i64;
  v10.CurDesc.Length = 0i64;
  v10.CurDesc.Offset = -1i64;
  memset(&v10.CurDesc.AdjStartPos, 0, 33);
  Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(&v10);
  this->HighlighterIter = v10;
  this->pGlyphs = pglyphs;
  this->pEndGlyphs = &pglyphs[v7];
  this->pNextFormatData = pfmtData;
  Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(this);
}

// File Line: 695
// RVA: 0x980010
float __fastcall Scaleform::Render::Text::LineBuffer::Line::GetAscent(Scaleform::Render::Text::LineBuffer::Line *this)
{
  if ( (this->MemSize & 0x80000000) == 0 )
    return (float)this->Data32.BaseLineOffset;
  else
    return (float)this->Data8.BaseLineOffset;
}

// File Line: 700
// RVA: 0x98A220
int __fastcall Scaleform::Render::Text::LineBuffer::Line::GetNonNegLeading(
        Scaleform::Render::Text::LineBuffer::Line *this)
{
  int result; // eax

  if ( (this->MemSize & 0x80000000) == 0 )
  {
    LOWORD(result) = this->Data32.Leading;
    if ( (__int16)result > 0 )
      return (__int16)result;
  }
  else
  {
    LOBYTE(result) = this->Data8.Leading;
    if ( (char)result > 0 )
      return (char)result;
  }
  return 0;
}

// File Line: 704
// RVA: 0x8D9A90
__int64 __fastcall Scaleform::Render::Text::LineBuffer::Line::GetHeight(
        Scaleform::Render::Text::LineBuffer::Line *this)
{
  if ( (this->MemSize & 0x80000000) == 0 )
    return this->Data32.Height;
  else
    return this->Data8.Height;
}

// File Line: 718
// RVA: 0x8B6B00
Scaleform::Render::Text::LineBuffer::GlyphIterator *__fastcall Scaleform::Render::Text::LineBuffer::Line::Begin(
        Scaleform::Render::Text::LineBuffer::Line *this,
        Scaleform::Render::Text::LineBuffer::GlyphIterator *result)
{
  unsigned int GlyphsCount; // edi
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v4; // rbx
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *FormatData; // rax

  if ( (this->MemSize & 0x80000000) == 0 )
    GlyphsCount = this->Data32.GlyphsCount;
  else
    GlyphsCount = (unsigned __int8)this->Data8.GlyphsCount;
  v4 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(&this->Data8.Leading + 1);
  if ( (this->MemSize & 0x80000000) == 0 )
    v4 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)&this->Data8 + 38);
  FormatData = Scaleform::Render::Text::LineBuffer::Line::GetFormatData(this);
  Scaleform::Render::Text::LineBuffer::GlyphIterator::GlyphIterator(result, v4, GlyphsCount, FormatData);
  return result;
}

// File Line: 720
// RVA: 0x95A350
Scaleform::Render::Text::LineBuffer::GlyphIterator *__fastcall Scaleform::Render::Text::LineBuffer::Line::Begin(
        Scaleform::Render::Text::LineBuffer::Line *this,
        Scaleform::Render::Text::LineBuffer::GlyphIterator *result,
        Scaleform::Render::Text::Highlighter *phighlighter)
{
  unsigned int TextPos; // edx
  char *v6; // r8
  __int64 GlyphsCount; // rax
  unsigned int v8; // r10d
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v9; // rcx

  if ( phighlighter )
  {
    TextPos = this->Data32.TextPos;
    if ( (this->MemSize & 0x80000000) != 0 )
    {
      TextPos &= 0xFFFFFFu;
      if ( TextPos == 0xFFFFFF )
        TextPos = -1;
    }
    v6 = &this->Data8.Leading + 1;
    if ( (this->MemSize & 0x80000000) != 0 )
    {
      GlyphsCount = (unsigned __int8)this->Data8.GlyphsCount;
    }
    else
    {
      v6 = (char *)&this->Data8 + 38;
      GlyphsCount = this->Data32.GlyphsCount;
    }
    if ( (this->MemSize & 0x80000000) == 0 )
      v8 = this->Data32.GlyphsCount;
    else
      v8 = (unsigned __int8)this->Data8.GlyphsCount;
    if ( (this->MemSize & 0x80000000) == 0 )
      v9 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)&this->Data8 + 38);
    else
      v9 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(&this->Data8.Leading + 1);
    Scaleform::Render::Text::LineBuffer::GlyphIterator::GlyphIterator(
      result,
      v9,
      v8,
      (Scaleform::Render::Text::LineBuffer::FormatDataEntry *)((unsigned __int64)&v6[8 * GlyphsCount + 7] & 0xFFFFFFFFFFFFFFF8ui64),
      phighlighter,
      TextPos);
  }
  else
  {
    Scaleform::Render::Text::LineBuffer::Line::Begin(this, result);
  }
  return result;
}

// File Line: 1072
// RVA: 0x8E7400
bool __fastcall Scaleform::Render::Text::LineBuffer::IsLineVisible(
        Scaleform::Render::Text::LineBuffer *this,
        unsigned int lineIndex)
{
  int VScrollOffsetInFixp; // eax

  VScrollOffsetInFixp = Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(this);
  return Scaleform::Render::Text::LineBuffer::IsLineVisible(
           this,
           lineIndex,
           COERCE_FLOAT(COERCE_UNSIGNED_INT((float)VScrollOffsetInFixp) ^ _xmm[0]));
}

