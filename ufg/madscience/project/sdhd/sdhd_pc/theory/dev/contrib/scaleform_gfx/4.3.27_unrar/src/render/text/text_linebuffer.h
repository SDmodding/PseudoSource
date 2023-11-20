// File Line: 304
// RVA: 0x897230
void __fastcall Scaleform::Render::Text::LineBuffer::GlyphIterator::GlyphIterator(Scaleform::Render::Text::LineBuffer::GlyphIterator *this, void *pglyphs, unsigned int glyphsCount, Scaleform::Render::Text::LineBuffer::FormatDataEntry *pfmtData)
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
  this->pGlyphs = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)pglyphs;
  this->pEndGlyphs = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)pglyphs + 8 * glyphsCount);
  this->pNextFormatData = pfmtData;
  Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(this);
}

// File Line: 314
// RVA: 0x93C8F0
void __fastcall Scaleform::Render::Text::LineBuffer::GlyphIterator::GlyphIterator(Scaleform::Render::Text::LineBuffer::GlyphIterator *this, void *pglyphs, unsigned int glyphsCount, Scaleform::Render::Text::LineBuffer::FormatDataEntry *pfmtData, Scaleform::Render::Text::Highlighter *highlighter, unsigned __int64 lineStartPos)
{
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *v6; // rsi
  __int64 v7; // rbx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v8; // rdi
  Scaleform::Render::Text::LineBuffer::GlyphIterator *v9; // r14
  Scaleform::Render::Text::HighlighterPosIterator v10; // [rsp+28h] [rbp-58h]

  v6 = pfmtData;
  v7 = glyphsCount;
  v8 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)pglyphs;
  v9 = this;
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
  *(_OWORD *)&v10.pManager = __PAIR__(lineStartPos, (unsigned __int64)highlighter);
  v10.NumGlyphs = -1i64;
  *(_OWORD *)&v10.CurDesc.StartPos = 0xFFFFFFFFFFFFFFFFui64;
  *(_OWORD *)&v10.CurDesc.Offset = 0xFFFFFFFFFFFFFFFFui64;
  *(_OWORD *)&v10.CurDesc.GlyphNum = 0ui64;
  *(_QWORD *)&v10.CurDesc.Info.TextColor.Channels.Blue = 0i64;
  v10.CurDesc.Info.Flags = 0;
  Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(&v10);
  *(_OWORD *)&v9->HighlighterIter.pManager = *(_OWORD *)&v10.pManager;
  v9->HighlighterIter.NumGlyphs = v10.NumGlyphs;
  *(_OWORD *)&v9->HighlighterIter.CurDesc.StartPos = *(_OWORD *)&v10.CurDesc.StartPos;
  *(_OWORD *)&v9->HighlighterIter.CurDesc.Offset = *(_OWORD *)&v10.CurDesc.Offset;
  *(_OWORD *)&v9->HighlighterIter.CurDesc.GlyphNum = *(_OWORD *)&v10.CurDesc.GlyphNum;
  *(_QWORD *)&v9->HighlighterIter.CurDesc.Info.TextColor.Channels.Blue = *(_QWORD *)&v10.CurDesc.Info.TextColor.Channels.Blue;
  v9->HighlighterIter.CurDesc.Info.Flags = v10.CurDesc.Info.Flags;
  v9->pGlyphs = v8;
  v9->pEndGlyphs = &v8[v7];
  v9->pNextFormatData = v6;
  Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(v9);
}

// File Line: 695
// RVA: 0x980010
float __fastcall Scaleform::Render::Text::LineBuffer::Line::GetAscent(Scaleform::Render::Text::LineBuffer::Line *this)
{
  signed int v1; // eax

  if ( (this->MemSize & 0x80000000) == 0 )
    v1 = this->Data32.BaseLineOffset;
  else
    v1 = this->Data8.BaseLineOffset;
  return (float)v1;
}

// File Line: 700
// RVA: 0x98A220
int __fastcall Scaleform::Render::Text::LineBuffer::Line::GetNonNegLeading(Scaleform::Render::Text::LineBuffer::Line *this)
{
  int result; // eax

  if ( (this->MemSize & 0x80000000) == 0 )
  {
    LOWORD(result) = this->Data32.Leading;
    if ( (signed __int16)result > 0 )
      return (signed __int16)result;
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
__int64 __fastcall Scaleform::Render::Text::LineBuffer::Line::GetHeight(Scaleform::Render::Text::LineBuffer::Line *this)
{
  __int64 result; // rax

  if ( (this->MemSize & 0x80000000) == 0 )
    result = this->Data32.Height;
  else
    result = this->Data8.Height;
  return result;
}

// File Line: 718
// RVA: 0x8B6B00
Scaleform::Render::Text::LineBuffer::GlyphIterator *__fastcall Scaleform::Render::Text::LineBuffer::Line::Begin(Scaleform::Render::Text::LineBuffer::Line *this, Scaleform::Render::Text::LineBuffer::GlyphIterator *result)
{
  Scaleform::Render::Text::LineBuffer::GlyphIterator *v2; // rsi
  unsigned int v3; // edi
  char *v4; // rbx
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *v5; // rax

  v2 = result;
  if ( (this->MemSize & 0x80000000) == 0 )
    v3 = this->Data32.GlyphsCount;
  else
    v3 = (unsigned __int8)this->Data8.GlyphsCount;
  v4 = &this->Data8.Leading + 1;
  if ( (this->MemSize & 0x80000000) == 0 )
    v4 = (char *)&this->Data8 + 38;
  v5 = Scaleform::Render::Text::LineBuffer::Line::GetFormatData(this);
  Scaleform::Render::Text::LineBuffer::GlyphIterator::GlyphIterator(v2, v4, v3, v5);
  return v2;
}

// File Line: 720
// RVA: 0x95A350
Scaleform::Render::Text::LineBuffer::GlyphIterator *__fastcall Scaleform::Render::Text::LineBuffer::Line::Begin(Scaleform::Render::Text::LineBuffer::Line *this, Scaleform::Render::Text::LineBuffer::GlyphIterator *result, Scaleform::Render::Text::Highlighter *phighlighter)
{
  Scaleform::Render::Text::Highlighter *highlighter; // rdi
  Scaleform::Render::Text::LineBuffer::GlyphIterator *v4; // rbx
  unsigned int v5; // edx
  char *v6; // r8
  __int64 v7; // rax
  unsigned int v8; // er10
  char *v9; // rcx

  highlighter = phighlighter;
  v4 = result;
  if ( phighlighter )
  {
    v5 = this->Data32.TextPos;
    if ( (this->MemSize & 0x80000000) != 0 )
    {
      v5 &= 0xFFFFFFu;
      if ( v5 == 0xFFFFFF )
        v5 = -1;
    }
    v6 = &this->Data8.Leading + 1;
    if ( (this->MemSize & 0x80000000) != 0 )
    {
      v7 = (unsigned __int8)this->Data8.GlyphsCount;
    }
    else
    {
      v6 = (char *)&this->Data8 + 38;
      v7 = this->Data32.GlyphsCount;
    }
    if ( (this->MemSize & 0x80000000) == 0 )
      v8 = this->Data32.GlyphsCount;
    else
      v8 = (unsigned __int8)this->Data8.GlyphsCount;
    if ( (this->MemSize & 0x80000000) == 0 )
      v9 = (char *)&this->Data8 + 38;
    else
      v9 = &this->Data8.Leading + 1;
    Scaleform::Render::Text::LineBuffer::GlyphIterator::GlyphIterator(
      v4,
      v9,
      v8,
      (Scaleform::Render::Text::LineBuffer::FormatDataEntry *)((unsigned __int64)&v6[8 * v7 + 7] & 0xFFFFFFFFFFFFFFF8ui64),
      highlighter,
      v5);
  }
  else
  {
    Scaleform::Render::Text::LineBuffer::Line::Begin(this, result);
  }
  return v4;
}

// File Line: 1072
// RVA: 0x8E7400
bool __fastcall Scaleform::Render::Text::LineBuffer::IsLineVisible(Scaleform::Render::Text::LineBuffer *this, unsigned int lineIndex)
{
  unsigned int v2; // ebx
  Scaleform::Render::Text::LineBuffer *v3; // rdi
  signed int v4; // eax

  v2 = lineIndex;
  v3 = this;
  v4 = Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(this);
  return Scaleform::Render::Text::LineBuffer::IsLineVisible(
           v3,
           v2,
           COERCE_FLOAT(COERCE_UNSIGNED_INT((float)v4) ^ _xmm[0]));
}

