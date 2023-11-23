// File Line: 26
// RVA: 0x957CD0
Scaleform::Render::Text::LineBuffer::Line *__fastcall Scaleform::Render::Text::LineBuffer::TextLineAllocator::AllocLine(
        Scaleform::Render::Text::LineBuffer::TextLineAllocator *this,
        unsigned int size,
        Scaleform::Render::Text::LineBuffer::LineType lineType)
{
  Scaleform::Render::Text::LineBuffer::Line *result; // rax
  unsigned int v6; // ecx

  result = (Scaleform::Render::Text::LineBuffer::Line *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                          Scaleform::Memory::pGlobalHeap,
                                                          this,
                                                          size,
                                                          0i64);
  result->MemSize &= 0xF8000000;
  result->MemSize |= size & 0x7FFFFFF;
  v6 = result->MemSize & 0x7FFFFFF;
  if ( lineType )
  {
    result->MemSize = v6 | 0x40000000;
    *(_QWORD *)&result->Data32.GlyphsCount = 0i64;
    *(_DWORD *)((char *)&result->Data8 + 34) = 0;
    *(_QWORD *)&result->Data8.OffsetX = 0i64;
    *(_QWORD *)&result->Data8.Width = 0i64;
    result->Data32.TextLength = 0;
  }
  else
  {
    result->MemSize = v6 | 0xC0000000;
    *(_DWORD *)&result->Data8.BaseLineOffset = 0;
    *(_QWORD *)&result->Data8.TextPosAndLength = 0i64;
    *(_QWORD *)&result->Data8.OffsetY = 0i64;
  }
  return result;
}

// File Line: 48
// RVA: 0x9A8210
void __fastcall Scaleform::Render::Text::LineBuffer::ReleasePartOfLine(
        Scaleform::Render::Text::LineBuffer::GlyphEntry *pglyphs,
        unsigned int n,
        Scaleform::Render::Text::LineBuffer::FormatDataEntry *pnextFormatData)
{
  unsigned __int16 *p_Flags; // rdi
  __int64 v5; // rsi
  Scaleform::Render::Text::FontHandle *pFont; // rcx
  Scaleform::Render::Text::FontHandle *v7; // rcx

  if ( n )
  {
    p_Flags = &pglyphs->Flags;
    v5 = n;
    do
    {
      if ( (*p_Flags & 0x4000) != 0 )
      {
        if ( (*p_Flags & 0x2000) != 0 )
        {
          pFont = pnextFormatData->pFont;
          if ( !_InterlockedDecrement(&pnextFormatData->pFont->RefCount) && pFont )
            pFont->vfptr->__vecDelDtor(pFont, 1u);
          ++pnextFormatData;
        }
        if ( (*p_Flags & 0x1000) != 0 )
          ++pnextFormatData;
        if ( (*p_Flags & 0x800) != 0 )
        {
          v7 = pnextFormatData->pFont;
          if ( pnextFormatData->pFont->RefCount-- == 1 )
            v7->vfptr->__vecDelDtor(v7, 1u);
          ++pnextFormatData;
        }
      }
      p_Flags += 4;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 75
// RVA: 0x9ABA90
void __fastcall Scaleform::Render::Text::LineBuffer::GlyphInserter::ResetTo(
        Scaleform::Render::Text::LineBuffer::GlyphInserter *this,
        Scaleform::Render::Text::LineBuffer::GlyphInserter *savedPos)
{
  __int64 GlyphIndex; // rcx
  unsigned int v5; // edx

  GlyphIndex = savedPos->GlyphIndex;
  v5 = this->GlyphIndex;
  if ( (unsigned int)GlyphIndex < v5 && this->GlyphsCount )
    Scaleform::Render::Text::LineBuffer::ReleasePartOfLine(
      &savedPos->pGlyphs[GlyphIndex],
      v5 - GlyphIndex,
      &savedPos->pNextFormatData[savedPos->FormatDataIndex]);
  this->pGlyphs = savedPos->pGlyphs;
  this->pNextFormatData = savedPos->pNextFormatData;
  this->GlyphIndex = savedPos->GlyphIndex;
  this->GlyphsCount = savedPos->GlyphsCount;
  this->FormatDataIndex = savedPos->FormatDataIndex;
}

// File Line: 92
// RVA: 0x94EF60
void __fastcall Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(
        Scaleform::Render::Text::LineBuffer::GlyphIterator *this)
{
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // rcx
  __int64 Delta; // rax
  unsigned __int64 CurAdjStartPos; // rdx

  pGlyphs = this->pGlyphs;
  if ( pGlyphs && pGlyphs < this->pEndGlyphs )
  {
    if ( !this->Delta )
      this->Delta = pGlyphs->LenAndFontSize >> 12;
    this->pGlyphs = pGlyphs + 1;
    if ( (pGlyphs[1].LenAndFontSize & 0xF000) != 0 )
    {
      Delta = this->Delta;
      if ( (_DWORD)Delta )
      {
        CurAdjStartPos = this->HighlighterIter.CurAdjStartPos;
        if ( CurAdjStartPos < this->HighlighterIter.NumGlyphs )
        {
          this->HighlighterIter.CurAdjStartPos = CurAdjStartPos + Delta;
          Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(&this->HighlighterIter);
          this->Delta = 0;
        }
      }
    }
    Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(this);
  }
}

// File Line: 108
// RVA: 0x9BDE40
void __fastcall Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(
        Scaleform::Render::Text::LineBuffer::GlyphIterator *this)
{
  Scaleform::Render::Text::ImageDesc *pObject; // rcx
  bool v3; // zf
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // rax
  unsigned __int16 Flags; // cx
  Scaleform::Render::Text::FontHandle *pFont; // rdi
  Scaleform::Render::Text::FontHandle *v7; // rcx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v8; // rdx
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *pNextFormatData; // rcx
  unsigned int ColorV; // eax
  Scaleform::Render::Text::ImageDesc *pImage; // rdi
  Scaleform::Render::Text::ImageDesc *v12; // rcx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v13; // rcx
  unsigned int v14; // eax
  char v15; // al
  unsigned int Raw; // eax
  unsigned int v17; // eax

  pObject = this->pImage.pObject;
  if ( pObject )
  {
    v3 = pObject->RefCount-- == 1;
    if ( v3 )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
  }
  this->pImage.pObject = 0i64;
  pGlyphs = this->pGlyphs;
  if ( this->pGlyphs && pGlyphs < this->pEndGlyphs )
  {
    Flags = pGlyphs->Flags;
    if ( (Flags & 0x4000) != 0 )
    {
      if ( (Flags & 0x2000) != 0 )
      {
        pFont = this->pNextFormatData->pFont;
        if ( pFont )
          _InterlockedExchangeAdd(&pFont->RefCount, 1u);
        v7 = this->pFontHandle.pObject;
        if ( v7 && !_InterlockedDecrement(&v7->RefCount) )
          v7->vfptr->__vecDelDtor(v7, 1u);
        this->pFontHandle.pObject = pFont;
        ++this->pNextFormatData;
      }
      v8 = this->pGlyphs;
      if ( (this->pGlyphs->Flags & 0x1000) != 0 )
      {
        pNextFormatData = this->pNextFormatData;
        ColorV = pNextFormatData->ColorV;
        this->ColorV = pNextFormatData->ColorV;
        this->OrigColor = ColorV;
        this->pNextFormatData = pNextFormatData + 1;
      }
      if ( (v8->Flags & 0x800) != 0 )
      {
        pImage = this->pNextFormatData->pImage;
        if ( pImage )
          ++pImage->RefCount;
        v12 = this->pImage.pObject;
        if ( v12 )
        {
          v3 = v12->RefCount-- == 1;
          if ( v3 )
            v12->vfptr->__vecDelDtor(v12, 1u);
        }
        this->pImage.pObject = pImage;
        ++this->pNextFormatData;
      }
    }
    v13 = this->pGlyphs;
    if ( (this->pGlyphs->Flags & 0x400) != 0 )
    {
      v14 = this->ColorV;
      this->UnderlineStyle = Underline_Single;
      this->UnderlineColor = v14;
    }
    else
    {
      this->UnderlineStyle = Underline_None;
    }
    if ( this->HighlighterIter.CurAdjStartPos >= this->HighlighterIter.NumGlyphs )
    {
      this->SelectionColor = 0;
      if ( (v13->Flags & 0x400) != 0 )
      {
        v17 = this->ColorV;
        this->UnderlineStyle = Underline_Single;
        this->UnderlineColor = v17;
      }
    }
    else
    {
      this->ColorV = this->OrigColor;
      if ( (v13->LenAndFontSize & 0xF000) != 0 || (v13->Flags & 8) != 0 )
      {
        if ( (this->HighlighterIter.CurDesc.Info.Flags & 0x10) != 0 )
          this->ColorV = this->HighlighterIter.CurDesc.Info.TextColor.Raw;
        v15 = this->HighlighterIter.CurDesc.Info.Flags;
        if ( (v15 & 7) != 0 )
          this->UnderlineStyle = v15 & 7;
        if ( (this->HighlighterIter.CurDesc.Info.Flags & 0x20) != 0 )
          Raw = this->HighlighterIter.CurDesc.Info.UnderlineColor.Raw;
        else
          Raw = this->ColorV;
        this->UnderlineColor = Raw;
        if ( (this->HighlighterIter.CurDesc.Info.Flags & 8) != 0 )
          this->SelectionColor = this->HighlighterIter.CurDesc.Info.BackgroundColor.Raw;
        else
          this->SelectionColor = 0;
      }
    }
  }
}

// File Line: 174
// RVA: 0x984AF0
Scaleform::Render::Text::LineBuffer::FormatDataEntry *__fastcall Scaleform::Render::Text::LineBuffer::Line::GetFormatData(
        Scaleform::Render::Text::LineBuffer::Line *this)
{
  char *v1; // rdx

  v1 = &this->Data8.Leading + 1;
  if ( (this->MemSize & 0x80000000) == 0 )
    v1 = (char *)&this->Data8 + 38;
  if ( (this->MemSize & 0x80000000) == 0 )
    return (Scaleform::Render::Text::LineBuffer::FormatDataEntry *)((unsigned __int64)&v1[8 * this->Data32.GlyphsCount
                                                                                        + 7] & 0xFFFFFFFFFFFFFFF8ui64);
  else
    return (Scaleform::Render::Text::LineBuffer::FormatDataEntry *)((unsigned __int64)&v1[8
                                                                                        * (unsigned __int8)this->Data8.GlyphsCount
                                                                                        + 7] & 0xFFFFFFFFFFFFFFF8ui64);
}

// File Line: 183
// RVA: 0x9A7990
void __fastcall Scaleform::Render::Text::LineBuffer::Line::Release(Scaleform::Render::Text::LineBuffer::Line *this)
{
  signed int MemSize; // ecx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v3; // r9
  bool v4; // cl
  unsigned int GlyphsCount; // edx
  char *v6; // r8
  __int64 v7; // rax

  MemSize = this->MemSize;
  if ( (MemSize & 0x40000000) != 0 )
  {
    v3 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(&this->Data8.Leading + 1);
    v4 = MemSize < 0;
    if ( !v4 )
      v3 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)&this->Data8 + 38);
    if ( v4 )
      GlyphsCount = (unsigned __int8)this->Data8.GlyphsCount;
    else
      GlyphsCount = this->Data32.GlyphsCount;
    v6 = &this->Data8.Leading + 1;
    if ( v4 )
    {
      v7 = (unsigned __int8)this->Data8.GlyphsCount;
    }
    else
    {
      v7 = this->Data32.GlyphsCount;
      v6 = (char *)&this->Data8 + 38;
    }
    Scaleform::Render::Text::LineBuffer::ReleasePartOfLine(
      v3,
      GlyphsCount,
      (Scaleform::Render::Text::LineBuffer::FormatDataEntry *)((unsigned __int64)&v6[8 * v7 + 7] & 0xFFFFFFFFFFFFFFF8ui64));
    if ( (this->MemSize & 0x80000000) == 0 )
      this->Data32.GlyphsCount = 0;
    else
      this->Data8.GlyphsCount = 0;
  }
}

// File Line: 211
// RVA: 0x93E0C0
void __fastcall Scaleform::Render::Text::LineBuffer::LineBuffer(Scaleform::Render::Text::LineBuffer *this)
{
  this->Lines.Data.Data = 0i64;
  this->Lines.Data.Size = 0i64;
  this->Lines.Data.Policy.Capacity = 0i64;
  this->Geom.FirstVisibleLinePos = 0;
  *(_QWORD *)&this->Geom.VisibleRect.x2 = 0i64;
  *(_QWORD *)&this->Geom.VisibleRect.y2 = 0i64;
  this->Geom.Flags = 0;
  *(_QWORD *)&this->Geom.VisibleRect.x1 = 0i64;
  this->Geom.VisibleRect.x2 = 0.0;
  this->LastHScrollOffset = -1;
}

// File Line: 217
// RVA: 0x94B1A0
void __fastcall Scaleform::Render::Text::LineBuffer::~LineBuffer(Scaleform::Render::Text::LineBuffer *this)
{
  this->Geom.Flags |= 1u;
  Scaleform::Render::Text::LineBuffer::RemoveLines(this, 0, this->Lines.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Lines.Data.Data);
}

// File Line: 231
// RVA: 0x988660
Scaleform::Render::Text::LineBuffer::Line *__fastcall Scaleform::Render::Text::LineBuffer::GetLine(
        Scaleform::Render::Text::LineBuffer *this,
        unsigned int lineIdx)
{
  if ( lineIdx < this->Lines.Data.Size )
    return this->Lines.Data.Data[lineIdx];
  else
    return 0i64;
}

// File Line: 257
// RVA: 0x995540
Scaleform::Render::Text::LineBuffer::Line *__fastcall Scaleform::Render::Text::LineBuffer::InsertNewLine(
        Scaleform::Render::Text::LineBuffer *this,
        unsigned int lineIdx,
        unsigned int glyphCount,
        unsigned int formatDataElementsCount,
        Scaleform::Render::Text::LineBuffer::LineType lineType)
{
  int v7; // eax
  unsigned __int64 v8; // rbp
  Scaleform::Render::Text::LineBuffer::Line *result; // rax
  Scaleform::Render::Text::LineBuffer::Line *v10; // rbx
  unsigned __int64 Size; // r8
  Scaleform::Render::Text::LineBuffer::Line **v12; // rcx

  v7 = 38;
  if ( lineType == Line8 )
    v7 = 26;
  v8 = lineIdx;
  result = Scaleform::Render::Text::LineBuffer::TextLineAllocator::AllocLine(
             &this->LineAllocator,
             ((v7 + 8 * glyphCount + 11) & 0xFFFFFFF8) + 8 * formatDataElementsCount,
             lineType);
  v10 = result;
  if ( result )
  {
    if ( (result->MemSize & 0x80000000) == 0 )
      result->Data32.GlyphsCount = glyphCount;
    else
      result->Data8.GlyphsCount = glyphCount;
    Scaleform::ArrayData<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      (Scaleform::ArrayData<Scaleform::GFx::AS2::Value *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value *,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this->Lines.Data.Size + 1);
    Size = this->Lines.Data.Size;
    if ( v8 < Size - 1 )
      memmove(&this->Lines.Data.Data[v8 + 1], &this->Lines.Data.Data[v8], 8 * (Size - v8) - 8);
    v12 = &this->Lines.Data.Data[v8];
    if ( v12 )
      *v12 = v10;
    return v10;
  }
  return result;
}

// File Line: 268
// RVA: 0x9A9E70
void __fastcall Scaleform::Render::Text::LineBuffer::RemoveLines(
        Scaleform::Render::Text::LineBuffer *this,
        int lineIdx,
        unsigned int num)
{
  unsigned int v3; // ebp
  __int64 v4; // r12
  int v6; // edi
  __int64 v7; // r15
  Scaleform::Render::Text::LineBuffer::Line *v8; // r14
  unsigned __int64 Size; // r8

  v3 = 0;
  v4 = (unsigned int)lineIdx;
  v6 = lineIdx;
  v7 = num;
  if ( num )
  {
    do
    {
      if ( !this || (unsigned int)v6 >= this->Lines.Data.Size || v6 < 0 )
        break;
      v8 = this->Lines.Data.Data[v6];
      if ( v8 )
      {
        Scaleform::Render::Text::LineBuffer::Line::Release(this->Lines.Data.Data[v6]);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
      }
      if ( (unsigned int)v6 < this->Lines.Data.Size )
        ++v6;
      ++v3;
    }
    while ( v3 < (unsigned int)v7 );
  }
  Size = this->Lines.Data.Size;
  if ( Size == v7 )
  {
    if ( Size && (this->Lines.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    {
      if ( this->Lines.Data.Data )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Text::LineBuffer::Line **, unsigned __int64, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          this->Lines.Data.Data,
          Size,
          v4);
        this->Lines.Data.Data = 0i64;
      }
      this->Lines.Data.Policy.Capacity = 0i64;
    }
    this->Lines.Data.Size = 0i64;
  }
  else
  {
    memmove(&this->Lines.Data.Data[v4], &this->Lines.Data.Data[v4] + v7, 8 * (Size - v4 - v7));
    this->Lines.Data.Size -= v7;
  }
}

// File Line: 278
// RVA: 0x98EB80
__int64 __fastcall Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(
        Scaleform::Render::Text::LineBuffer *this)
{
  unsigned __int64 FirstVisibleLinePos; // rax
  unsigned __int64 Size; // rdx

  FirstVisibleLinePos = this->Geom.FirstVisibleLinePos;
  if ( (_DWORD)FirstVisibleLinePos
    && (Size = this->Lines.Data.Size, FirstVisibleLinePos < Size)
    && (FirstVisibleLinePos & 0x80000000) == 0i64
    && Size )
  {
    return (unsigned int)(this->Lines.Data.Data[FirstVisibleLinePos]->Data32.OffsetY
                        - (*this->Lines.Data.Data)->Data32.OffsetY);
  }
  else
  {
    return 0i64;
  }
}

// File Line: 322
// RVA: 0x97A760
Scaleform::Render::Text::LineBuffer::Iterator *__fastcall Scaleform::Render::Text::LineBuffer::FindLineByTextPos(
        Scaleform::Render::Text::LineBuffer *this,
        Scaleform::Render::Text::LineBuffer::Iterator *result,
        unsigned __int64 textPos)
{
  __int64 Size; // r9
  __int64 v6; // r11
  Scaleform::Render::Text::LineBuffer::Line **Data; // r14
  __int64 v8; // rdi
  Scaleform::Render::Text::LineBuffer::Line *v9; // rax
  int v10; // ecx
  unsigned int TextLength; // r8d
  Scaleform::Render::Text::LineBuffer::Line *v12; // r8
  unsigned int v13; // ecx
  unsigned int TextPosAndLength_high; // eax
  char Flags; // al
  Scaleform::Render::Text::LineBuffer::Iterator *v16; // rax

  if ( !this->Lines.Data.Size )
    goto LABEL_27;
  Size = this->Lines.Data.Size;
  v6 = 0i64;
  if ( Size > 0 )
  {
    Data = this->Lines.Data.Data;
    do
    {
      v8 = (Size >> 1) + v6;
      v9 = Data[v8];
      v10 = v9->Data32.TextPos;
      if ( (v9->MemSize & 0x80000000) != 0 )
      {
        v10 &= 0xFFFFFFu;
        if ( v10 == 0xFFFFFF )
          v10 = -1;
      }
      if ( (int)textPos >= v10
        && ((v9->MemSize & 0x80000000) == 0
          ? (TextLength = v9->Data32.TextLength)
          : (TextLength = HIBYTE(v9->Data8.TextPosAndLength)),
            (int)textPos < (int)(TextLength + v10))
        || v10 - (int)textPos >= 0 )
      {
        Size >>= 1;
      }
      else
      {
        v6 = v8 + 1;
        Size += -1 - (Size >> 1);
      }
    }
    while ( Size > 0 );
  }
  if ( v6 == this->Lines.Data.Size )
    LODWORD(v6) = v6 - 1;
  v12 = this->Lines.Data.Data[(unsigned int)v6];
  v13 = v12->Data32.TextPos;
  if ( (v12->MemSize & 0x80000000) != 0 )
  {
    v13 &= 0xFFFFFFu;
    if ( v13 == 0xFFFFFF )
      v13 = -1;
  }
  if ( textPos >= v13
    && ((v12->MemSize & 0x80000000) == 0
      ? (TextPosAndLength_high = v12->Data32.TextLength)
      : (TextPosAndLength_high = HIBYTE(v12->Data8.TextPosAndLength)),
        textPos <= TextPosAndLength_high + v13) )
  {
    Flags = this->Geom.Flags;
    result->pLineBuffer = this;
    result->CurrentPos = v6;
    result->YOffset = 0.0;
    result->pHighlight = 0i64;
    result->StaticText = (Flags & 4) != 0;
    return result;
  }
  else
  {
LABEL_27:
    result->pLineBuffer = 0i64;
    *(_QWORD *)&result->CurrentPos = 0i64;
    result->StaticText = 0;
    v16 = result;
    result->pHighlight = 0i64;
  }
  return v16;
}

// File Line: 337
// RVA: 0x97A5F0
Scaleform::Render::Text::LineBuffer::Iterator *__fastcall Scaleform::Render::Text::LineBuffer::FindLineAtYOffset(
        Scaleform::Render::Text::LineBuffer *this,
        Scaleform::Render::Text::LineBuffer::Iterator *result,
        float yoff)
{
  __int64 Size; // r8
  __int64 v6; // r11
  Scaleform::Render::Text::LineBuffer::Line **Data; // r14
  __int64 v8; // rbx
  Scaleform::Render::Text::LineBuffer::Line *v9; // rax
  float OffsetY; // xmm2_4
  int Height; // r9d
  int Leading; // ecx
  Scaleform::Render::Text::LineBuffer::Line *v13; // r8
  unsigned int v14; // r9d
  int v15; // eax
  char Flags; // al

  if ( !this->Lines.Data.Size )
    goto LABEL_27;
  Size = this->Lines.Data.Size;
  v6 = 0i64;
  if ( Size > 0 )
  {
    Data = this->Lines.Data.Data;
    do
    {
      v8 = (Size >> 1) + v6;
      v9 = Data[v8];
      OffsetY = (float)v9->Data32.OffsetY;
      if ( yoff >= OffsetY
        && ((v9->MemSize & 0x80000000) == 0 ? (Height = v9->Data32.Height) : (Height = v9->Data8.Height),
            (v9->MemSize & 0x80000000) == 0 ? (Leading = v9->Data32.Leading) : (Leading = v9->Data8.Leading),
            yoff < (float)((float)((float)Height + OffsetY) + (float)Leading))
        || (int)(float)(OffsetY - yoff) >= 0 )
      {
        Size >>= 1;
      }
      else
      {
        v6 = v8 + 1;
        Size += -1 - (Size >> 1);
      }
    }
    while ( Size > 0 );
  }
  if ( v6 == this->Lines.Data.Size )
    LODWORD(v6) = v6 - 1;
  v13 = this->Lines.Data.Data[(unsigned int)v6];
  if ( yoff >= (float)v13->Data32.OffsetY
    && ((v13->MemSize & 0x80000000) == 0 ? (v14 = v13->Data32.Height) : (v14 = v13->Data8.Height),
        (v13->MemSize & 0x80000000) == 0 ? (v15 = v13->Data32.Leading) : (v15 = v13->Data8.Leading),
        yoff < (float)(int)(v13->Data32.OffsetY + v14 + v15)) )
  {
    Flags = this->Geom.Flags;
    result->pLineBuffer = this;
    result->CurrentPos = v6;
    result->YOffset = 0.0;
    result->pHighlight = 0i64;
    result->StaticText = (Flags & 4) != 0;
    return result;
  }
  else
  {
LABEL_27:
    result->pLineBuffer = 0i64;
    *(_QWORD *)&result->CurrentPos = 0i64;
    result->StaticText = 0;
    result->pHighlight = 0i64;
    return result;
  }
}

// File Line: 382
// RVA: 0x997AA0
_BOOL8 __fastcall Scaleform::Render::Text::LineBuffer::IsLineVisible(
        Scaleform::Render::Text::LineBuffer *this,
        unsigned int lineIndex,
        float yOffset)
{
  Scaleform::Render::Text::LineBuffer::Line *v3; // r9
  unsigned int FirstVisibleLinePos; // eax
  int v6; // eax

  v3 = this->Lines.Data.Data[lineIndex];
  FirstVisibleLinePos = this->Geom.FirstVisibleLinePos;
  if ( lineIndex == FirstVisibleLinePos )
    return (float)((float)(this->Geom.VisibleRect.y2 - this->Geom.VisibleRect.y1) + 20.0) >= (float)((float)v3->Data32.OffsetY + yOffset);
  if ( lineIndex <= FirstVisibleLinePos )
    return 0i64;
  v6 = (v3->MemSize & 0x80000000) == 0 ? v3->Data32.Height : v3->Data8.Height;
  return (float)((float)(v3->Data32.OffsetY + v6) + yOffset) <= (float)((float)(this->Geom.VisibleRect.y2
                                                                              - this->Geom.VisibleRect.y1)
                                                                      + 20.0);
}

// File Line: 396
// RVA: 0x997BA0
bool __fastcall Scaleform::Render::Text::LineBuffer::IsPartiallyVisible(
        Scaleform::Render::Text::LineBuffer *this,
        float yOffset)
{
  unsigned int FirstVisibleLinePos; // eax
  Scaleform::Render::Text::LineBuffer::Line *v4; // r8
  int v7; // edx
  float v8; // xmm1_4
  float v9; // xmm0_4
  bool result; // al

  FirstVisibleLinePos = this->Geom.FirstVisibleLinePos;
  result = 0;
  if ( FirstVisibleLinePos < LODWORD(this->Lines.Data.Size) )
  {
    v4 = this->Lines.Data.Data[FirstVisibleLinePos];
    if ( (v4->MemSize & 0x80000000) == 0 ? v4->Data32.Width : v4->Data8.Width )
    {
      if ( (v4->MemSize & 0x80000000) == 0 ? v4->Data32.Height : v4->Data8.Height )
      {
        v7 = (v4->MemSize & 0x80000000) == 0 ? v4->Data32.Height : v4->Data8.Height;
        v8 = (float)(this->Geom.VisibleRect.y2 - this->Geom.VisibleRect.y1) + 20.0;
        v9 = (float)v4->Data32.OffsetY + yOffset;
        if ( v9 <= v8 && (float)(v9 + (float)v7) > v8 )
          return 1;
      }
    }
  }
  return result;
}

// File Line: 424
// RVA: 0x9AD830
void __fastcall Scaleform::Render::Text::LineBuffer::Scale(
        Scaleform::Render::Text::LineBuffer *this,
        float scaleFactor)
{
  int v4; // edi
  Scaleform::Render::Text::LineBuffer::Line *v5; // rcx
  bool v6; // al
  int Leading; // edx
  float v8; // xmm1_4
  int Width; // edx
  float v10; // xmm2_4
  int Height; // edx
  float v12; // xmm0_4
  int v13; // edx
  int v14; // edx
  int v15; // r8d
  int BaseLineOffset; // eax
  int v17; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // rcx
  int Advance; // eax
  int v20; // eax
  unsigned __int16 LenAndFontSize; // r8
  unsigned __int16 Flags; // dx
  float v23; // xmm1_4
  float v24; // xmm1_4
  int v25; // r9d
  unsigned __int16 v26; // dx
  __int16 v27; // ax
  unsigned int Delta; // eax
  Scaleform::Render::Text::ImageDesc *pObject; // rcx
  Scaleform::Render::Text::FontHandle *v30; // rcx
  Scaleform::Render::Text::LineBuffer::GlyphIterator result; // [rsp+30h] [rbp-108h] BYREF

  v4 = 0;
  while ( this && (unsigned int)v4 < this->Lines.Data.Size && v4 >= 0 )
  {
    v5 = this->Lines.Data.Data[v4];
    v6 = (v5->MemSize & 0x80000000) != 0;
    if ( (v5->MemSize & 0x80000000) == 0 )
      Leading = v5->Data32.Leading;
    else
      Leading = v5->Data8.Leading;
    v8 = (float)Leading * scaleFactor;
    if ( (v5->MemSize & 0x80000000) == 0 )
      Width = v5->Data32.Width;
    else
      Width = v5->Data8.Width;
    v10 = (float)Width * scaleFactor;
    if ( (v5->MemSize & 0x80000000) == 0 )
      Height = v5->Data32.Height;
    else
      Height = v5->Data8.Height;
    v12 = (float)Height * scaleFactor;
    v13 = (int)v8;
    if ( (v5->MemSize & 0x80000000) == 0 )
      v5->Data32.Leading = v13;
    else
      v5->Data8.Leading = v13;
    v14 = (int)v12;
    v15 = (int)v10;
    if ( v6 )
    {
      v5->Data8.Width = v15;
      v5->Data8.Height = v14;
    }
    else
    {
      v5->Data32.Width = v15;
      v5->Data32.Height = v14;
    }
    if ( (v5->MemSize & 0x80000000) == 0 )
      BaseLineOffset = v5->Data32.BaseLineOffset;
    else
      BaseLineOffset = v5->Data8.BaseLineOffset;
    v17 = (int)(float)((float)BaseLineOffset * scaleFactor);
    if ( (v5->MemSize & 0x80000000) == 0 )
      v5->Data32.BaseLineOffset = v17;
    else
      v5->Data8.BaseLineOffset = v17;
    v5->Data32.OffsetX = (int)(float)((float)v5->Data32.OffsetX * scaleFactor);
    v5->Data32.OffsetY = (int)(float)((float)v5->Data32.OffsetY * scaleFactor);
    Scaleform::Render::Text::LineBuffer::Line::Begin(v5, &result);
LABEL_27:
    pGlyphs = result.pGlyphs;
    while ( pGlyphs && pGlyphs < result.pEndGlyphs )
    {
      Advance = pGlyphs->Advance;
      if ( (pGlyphs->Flags & 0x40) != 0 )
        Advance = -Advance;
      v20 = (int)(float)((float)Advance * scaleFactor);
      if ( v20 < 0 )
      {
        LOWORD(v20) = abs32(v20);
        pGlyphs->Flags |= 0x40u;
      }
      else
      {
        pGlyphs->Flags &= ~0x40u;
      }
      pGlyphs->Advance = v20;
      LenAndFontSize = pGlyphs->LenAndFontSize;
      Flags = pGlyphs->Flags;
      v23 = (float)(LenAndFontSize & 0xFFF);
      if ( (Flags & 0x10) != 0 )
        v23 = v23 * 0.0625;
      v24 = v23 * scaleFactor;
      if ( v24 < 256.0 && (v25 = (int)(float)(v24 * 16.0), (v25 & 0xF) != 0) )
      {
        v26 = Flags | 0x10;
        v27 = v25 ^ LenAndFontSize;
      }
      else
      {
        v26 = Flags & 0xFFEF;
        v27 = LenAndFontSize ^ (int)v24;
      }
      pGlyphs->LenAndFontSize = LenAndFontSize ^ v27 & 0xFFF;
      pGlyphs->Flags = v26;
      pGlyphs = result.pGlyphs;
      if ( !result.pGlyphs )
        break;
      if ( result.pGlyphs < result.pEndGlyphs )
      {
        Delta = result.Delta;
        if ( !result.Delta )
        {
          Delta = result.pGlyphs->LenAndFontSize >> 12;
          result.Delta = Delta;
        }
        ++result.pGlyphs;
        if ( (result.pGlyphs->LenAndFontSize & 0xF000) != 0
          && Delta
          && result.HighlighterIter.CurAdjStartPos < result.HighlighterIter.NumGlyphs )
        {
          result.HighlighterIter.CurAdjStartPos += Delta;
          Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(&result.HighlighterIter);
          result.Delta = 0;
        }
        Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&result);
        goto LABEL_27;
      }
    }
    pObject = result.pImage.pObject;
    if ( result.pImage.pObject )
    {
      --result.pImage.pObject->RefCount;
      if ( !pObject->RefCount )
        pObject->vfptr->__vecDelDtor(pObject, 1u);
    }
    v30 = result.pFontHandle.pObject;
    if ( result.pFontHandle.pObject && !_InterlockedDecrement(&result.pFontHandle.pObject->RefCount) && v30 )
      v30->vfptr->__vecDelDtor(v30, 1u);
    if ( (unsigned int)v4 < this->Lines.Data.Size )
      ++v4;
  }
  this->Geom.Flags |= 1u;
}

// File Line: 553
// RVA: 0x969B50
void __fastcall Scaleform::Render::Text::LineBuffer::CreateVisibleTextLayout(
        Scaleform::Render::Text::LineBuffer *this,
        Scaleform::Render::TextLayout::Builder *bld,
        Scaleform::Render::Text::Highlighter *phighlighter,
        Scaleform::Render::TextFieldParam *textFieldParam)
{
  Scaleform::Render::Text::Highlighter *v4; // rsi
  Scaleform::Render::Text::LineBuffer *v6; // r13
  int v7; // r10d
  unsigned __int64 FirstVisibleLinePos; // rbx
  unsigned __int64 Size; // rax
  float v10; // xmm9_4
  bool v11; // r14
  unsigned __int64 v12; // rcx
  unsigned __int64 v13; // rdx
  char *p_Flags; // rax
  unsigned int v15; // edi
  float ScreenWidth; // xmm7_4
  float v17; // xmm8_4
  char Flags; // al
  float y2; // xmm2_4
  float x2; // xmm1_4
  float y1; // xmm0_4
  float v22; // xmm6_4
  Scaleform::Render::Text::LineBuffer::Line *v23; // rcx
  unsigned int v24; // eax
  int v25; // eax
  Scaleform::Render::Text::LineBuffer::Line *v26; // r15
  float v27; // xmm10_4
  int BaseLineOffset; // eax
  char v29; // r9
  int v30; // r14d
  Scaleform::Render::Text::HighlightInfo::UnderlineStyle UnderlineStyle; // esi
  unsigned int UnderlineColor; // ebx
  float v33; // xmm15_4
  int Height; // ecx
  int v35; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // rcx
  int v37; // xmm13_4
  float v38; // xmm11_4
  int v39; // xmm14_4
  float v40; // xmm12_4
  unsigned __int16 *v41; // r12
  unsigned __int16 v42; // dx
  int Advance; // r11d
  unsigned int Index; // r10d
  float v45; // xmm9_4
  unsigned int SelectionColor; // r15d
  float v47; // xmm9_4
  float v48; // xmm6_4
  Scaleform::Render::Font *v49; // r9
  float v50; // xmm6_4
  char *v51; // rsi
  int v52; // r12d
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *p_Data; // r13
  char v54; // al
  float x1; // xmm3_4
  float v56; // xmm0_4
  float v57; // xmm1_4
  float v58; // xmm0_4
  float v59; // xmm2_4
  Scaleform::Render::TextLayout::Builder *v60; // rcx
  Scaleform::RefCountImpl *v61; // rdx
  __m128 v62; // xmm1
  __m128 v63; // xmm5
  int v64; // r15d
  unsigned int ColorV; // esi
  char *v66; // rdi
  int v67; // r12d
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *v68; // r13
  Scaleform::Render::Font *v69; // r13
  int v70; // edi
  float v71; // xmm7_4
  bool v72; // r12
  __int16 v73; // ax
  Scaleform::LogMessageId *p_id; // rbx
  int v75; // edi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *v76; // r12
  __int16 v77; // ax
  char *v78; // rbx
  int v79; // edi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *v80; // r12
  int v81; // ebx
  float v82; // xmm8_4
  float v83; // xmm7_4
  float v84; // xmm6_4
  float v85; // xmm8_4
  float v86; // xmm1_4
  char *v87; // rbx
  int v88; // edi
  Scaleform::Render::TextLayout::Builder *v89; // r14
  char v90; // dl
  bool v91; // cl
  char v92; // al
  char *v93; // rbx
  int v94; // edi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *v95; // r14
  unsigned int Delta; // eax
  __int16 v97; // cx
  float v98; // xmm15_4
  char *v99; // rbx
  int v100; // esi
  float v101; // xmm0_4
  char *v102; // rbx
  int v103; // esi
  Scaleform::Render::Text::ImageDesc *pObject; // rcx
  Scaleform::Render::Text::FontHandle *v105; // rcx
  Scaleform::Render::FontCacheHandle **v106; // rsi
  char v107; // [rsp+30h] [rbp-90h]
  bool v108; // [rsp+31h] [rbp-8Fh]
  char v109; // [rsp+32h] [rbp-8Eh]
  bool v110; // [rsp+33h] [rbp-8Dh]
  int v111; // [rsp+34h] [rbp-8Ch]
  int v112; // [rsp+38h] [rbp-88h]
  Scaleform::Render::Text::HighlightInfo::UnderlineStyle v113; // [rsp+3Ch] [rbp-84h]
  char val[4]; // [rsp+40h] [rbp-80h] BYREF
  float v115; // [rsp+44h] [rbp-7Ch]
  int v116; // [rsp+48h] [rbp-78h]
  int v117; // [rsp+4Ch] [rbp-74h]
  Scaleform::Render::Text::LineBuffer::Line *v118; // [rsp+50h] [rbp-70h]
  char v119[2]; // [rsp+58h] [rbp-68h] BYREF
  __int16 v120; // [rsp+5Ah] [rbp-66h]
  float v121; // [rsp+5Ch] [rbp-64h]
  char v122[4]; // [rsp+60h] [rbp-60h] BYREF
  float v123; // [rsp+64h] [rbp-5Ch]
  unsigned __int16 *v124; // [rsp+68h] [rbp-58h]
  Scaleform::LogMessageId id; // [rsp+70h] [rbp-50h] BYREF
  float v126; // [rsp+74h] [rbp-4Ch]
  Scaleform::Render::Font *f; // [rsp+78h] [rbp-48h]
  unsigned int v128; // [rsp+80h] [rbp-40h]
  char v129[2]; // [rsp+88h] [rbp-38h] BYREF
  __int16 v130; // [rsp+8Ah] [rbp-36h]
  float v131; // [rsp+8Ch] [rbp-34h]
  float v132; // [rsp+90h] [rbp-30h]
  float v133; // [rsp+94h] [rbp-2Ch]
  unsigned int v134; // [rsp+98h] [rbp-28h]
  Scaleform::Render::Font *v135; // [rsp+A0h] [rbp-20h]
  char v136[4]; // [rsp+A8h] [rbp-18h] BYREF
  int v137; // [rsp+ACh] [rbp-14h]
  float v138; // [rsp+B0h] [rbp-10h]
  int v139; // [rsp+B4h] [rbp-Ch]
  float v140; // [rsp+B8h] [rbp-8h]
  int v141; // [rsp+BCh] [rbp-4h]
  char v142[4]; // [rsp+C0h] [rbp+0h] BYREF
  int v143; // [rsp+C4h] [rbp+4h]
  float v144; // [rsp+C8h] [rbp+8h]
  int v145; // [rsp+CCh] [rbp+Ch]
  float v146; // [rsp+D0h] [rbp+10h]
  int v147; // [rsp+D4h] [rbp+14h]
  Scaleform::Render::Text::ImageDesc *v148; // [rsp+D8h] [rbp+18h]
  __int128 v149; // [rsp+E0h] [rbp+20h]
  unsigned __int64 v150; // [rsp+F0h] [rbp+30h]
  Scaleform::Render::Text::LineBuffer::GlyphIterator result; // [rsp+100h] [rbp+40h] BYREF
  __int64 v152; // [rsp+1A0h] [rbp+E0h]
  __int128 v153[15]; // [rsp+1B0h] [rbp+F0h] BYREF
  Scaleform::Render::Text::LineBuffer *v154; // [rsp+2B0h] [rbp+1F0h]
  Scaleform::Render::TextLayout::Builder *v155; // [rsp+2B8h] [rbp+1F8h]
  Scaleform::Render::Text::Highlighter *v156; // [rsp+2C0h] [rbp+200h]
  Scaleform::Render::FontCacheHandle **v157; // [rsp+2C8h] [rbp+208h]

  v152 = -2i64;
  v4 = phighlighter;
  v6 = this;
  v7 = 0;
  FirstVisibleLinePos = this->Geom.FirstVisibleLinePos;
  v117 = FirstVisibleLinePos;
  if ( (_DWORD)FirstVisibleLinePos )
  {
    Size = this->Lines.Data.Size;
    if ( FirstVisibleLinePos < Size && (FirstVisibleLinePos & 0x80000000) == 0i64 && Size )
      v7 = this->Lines.Data.Data[FirstVisibleLinePos]->Data32.OffsetY - (*this->Lines.Data.Data)->Data32.OffsetY;
  }
  LODWORD(v10) = COERCE_UNSIGNED_INT((float)v7) ^ _xmm[0];
  *((float *)&v118 + 1) = v10;
  v11 = (this->Geom.Flags & 4) != 0;
  v110 = v11;
  v153[0] = 0i64;
  if ( phighlighter )
  {
    if ( !phighlighter->HasUnderline )
    {
      phighlighter->HasUnderline = -1;
      v12 = 0i64;
      v13 = phighlighter->Highlighters.Data.Size;
      if ( v13 )
      {
        p_Flags = &phighlighter->Highlighters.Data.Data->Info.Flags;
        while ( (*p_Flags & 7) == 0 )
        {
          ++v12;
          p_Flags += 64;
          if ( v12 >= v13 )
            goto LABEL_14;
        }
        phighlighter->HasUnderline = 1;
      }
    }
  }
LABEL_14:
  v15 = 0;
  v135 = 0i64;
  ScreenWidth = 0.0;
  v17 = 0.0;
  Flags = v6->Geom.Flags;
  if ( (Flags & 4) != 0 || (Flags & 0x20) != 0 || !Scaleform::Render::Text::LineBuffer::IsPartiallyVisible(v6, v10) )
  {
    v109 = 0;
  }
  else
  {
    y2 = v6->Geom.VisibleRect.y2;
    x2 = v6->Geom.VisibleRect.x2;
    y1 = v6->Geom.VisibleRect.y1;
    bld->ClipBox.x1 = v6->Geom.VisibleRect.x1;
    bld->ClipBox.y1 = y1;
    bld->ClipBox.x2 = x2;
    bld->ClipBox.y2 = y2;
    v109 = 1;
  }
  v22 = FLOAT_20_0;
LABEL_20:
  v150 = (unsigned int)FirstVisibleLinePos;
  if ( (unsigned int)FirstVisibleLinePos < v6->Lines.Data.Size && (FirstVisibleLinePos & 0x80000000) == 0i64 )
  {
    if ( !v11 )
    {
      v23 = v6->Lines.Data.Data[(unsigned int)FirstVisibleLinePos];
      v24 = v6->Geom.FirstVisibleLinePos;
      if ( (_DWORD)FirstVisibleLinePos == v24 )
      {
        if ( (float)((float)(v6->Geom.VisibleRect.y2 - v6->Geom.VisibleRect.y1) + v22) < (float)((float)v23->Data32.OffsetY
                                                                                               + v10) )
          goto LABEL_180;
      }
      else
      {
        if ( (unsigned int)FirstVisibleLinePos <= v24 )
          goto LABEL_180;
        v25 = (v23->MemSize & 0x80000000) == 0 ? v23->Data32.Height : v23->Data8.Height;
        if ( (float)((float)(v23->Data32.OffsetY + v25) + v10) > (float)((float)(v6->Geom.VisibleRect.y2
                                                                               - v6->Geom.VisibleRect.y1)
                                                                       + v22) )
          goto LABEL_180;
      }
    }
    v26 = v6->Lines.Data.Data[(unsigned int)FirstVisibleLinePos];
    v118 = v26;
    v27 = (float)v26->Data32.OffsetX + v6->Geom.VisibleRect.x1;
    if ( (v26->MemSize & 0x80000000) == 0 )
      BaseLineOffset = v26->Data32.BaseLineOffset;
    else
      BaseLineOffset = v26->Data8.BaseLineOffset;
    *(float *)val = (float)((float)v26->Data32.OffsetY + v6->Geom.VisibleRect.y1) + (float)((float)BaseLineOffset + v10);
    Scaleform::Render::Text::LineBuffer::Line::Begin(v26, &result, v4);
    v29 = 1;
    v107 = 1;
    v30 = 0;
    v149 = 0i64;
    UnderlineStyle = Underline_None;
    v113 = Underline_None;
    UnderlineColor = 0;
    v112 = 0;
    v33 = 0.0;
    v115 = 0.0;
    if ( (v26->MemSize & 0x80000000) == 0 )
      Height = v26->Data32.Height;
    else
      Height = v26->Data8.Height;
    if ( (v26->MemSize & 0x80000000) == 0 )
      v35 = v26->Data32.BaseLineOffset;
    else
      v35 = v26->Data8.BaseLineOffset;
    *(float *)&v116 = (float)Height - (float)v35;
    pGlyphs = result.pGlyphs;
    v37 = SHIDWORD(v149);
    v38 = *((float *)&v149 + 2);
    v39 = SDWORD1(v149);
    v40 = *(float *)&v149;
    while ( 1 )
    {
      if ( !pGlyphs || pGlyphs >= result.pEndGlyphs )
      {
LABEL_156:
        if ( UnderlineColor )
        {
          switch ( UnderlineStyle )
          {
            case Underline_Thick:
              v97 = 1;
              break;
            case Underline_Dotted:
              v97 = 2;
              break;
            case Underline_DottedThick:
              v97 = 3;
              break;
            case Underline_DitheredSingle:
              v97 = 4;
              break;
            case Underline_DitheredThick:
              v97 = 5;
              break;
            default:
              v97 = 0;
              break;
          }
          v98 = v33 - (float)(int)v6->Geom.HScrollOffset;
          *(_WORD *)v119 = 6;
          v120 = v97;
          v121 = v98;
          *(float *)v122 = (float)(*(float *)&v116 * 0.5) + v115;
          v123 = (float)v112;
          LODWORD(v124) = UnderlineColor;
          v99 = v119;
          v100 = 20;
          bld = v155;
          do
          {
            Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(&bld->Data, v99++);
            --v100;
          }
          while ( v100 );
        }
        else
        {
          bld = v155;
        }
        if ( v30 )
        {
          LODWORD(v101) = COERCE_UNSIGNED_INT((float)(int)v6->Geom.HScrollOffset) ^ _xmm[0];
          *(_DWORD *)v136 = 5;
          v137 = v30;
          v138 = v40 + v101;
          v139 = v39;
          v140 = v38 + v101;
          v141 = v37;
          v102 = v136;
          v103 = 24;
          do
          {
            Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(&bld->Data, v102++);
            --v103;
          }
          while ( v103 );
        }
        pObject = result.pImage.pObject;
        if ( result.pImage.pObject )
        {
          --result.pImage.pObject->RefCount;
          if ( !pObject->RefCount )
            pObject->vfptr->__vecDelDtor(pObject, 1u);
        }
        v105 = result.pFontHandle.pObject;
        if ( result.pFontHandle.pObject && !_InterlockedDecrement(&result.pFontHandle.pObject->RefCount) && v105 )
          v105->vfptr->__vecDelDtor(v105, 1u);
        v10 = *((float *)&v118 + 1);
        LODWORD(FirstVisibleLinePos) = v117;
        v4 = v156;
        v11 = v110;
        if ( v150 < v6->Lines.Data.Size )
          LODWORD(FirstVisibleLinePos) = ++v117;
        goto LABEL_20;
      }
      v41 = &pGlyphs->Flags;
      v124 = &pGlyphs->Flags;
      v42 = pGlyphs->Flags;
      Advance = pGlyphs->Advance;
      if ( (v42 & 0x40) != 0 )
        Advance = -Advance;
      v111 = Advance;
      if ( pGlyphs->Index == 0xFFFF )
        Index = -1;
      else
        Index = pGlyphs->Index;
      LODWORD(v118) = Index;
      v148 = 0i64;
      f = 0i64;
      v45 = FLOAT_N1_0;
      SelectionColor = result.SelectionColor;
      if ( result.pImage.pObject )
      {
        v148 = result.pImage.pObject;
        ScreenWidth = result.pImage.pObject->ScreenWidth;
      }
      else
      {
        v47 = (float)(pGlyphs->LenAndFontSize & 0xFFF);
        if ( (v42 & 0x10) != 0 )
          v47 = v47 * 0.0625;
        v45 = v47 * v22;
        v48 = v45 * 0.0009765625;
        if ( result.pFontHandle.pObject )
          v49 = result.pFontHandle.pObject->pFont.pObject;
        else
          v49 = 0i64;
        f = v49;
        if ( (v6->Geom.Flags & 4) == 0 )
        {
          if ( Index == -1 )
          {
            ScreenWidth = (float)Advance * v48;
          }
          else
          {
            ScreenWidth = v48
                        * *(float *)(((__int64 (__fastcall *)(Scaleform::Render::Font *, _QWORD, __int128 *))v49->vfptr[7].__vecDelDtor)(
                                       v49,
                                       Index,
                                       v153)
                                   + 8);
            pGlyphs = result.pGlyphs;
          }
        }
        v29 = v107;
      }
      v50 = v27 - (float)(int)v6->Geom.HScrollOffset;
      if ( (v6->Geom.Flags & 4) == 0 )
      {
        if ( (float)(v50 + ScreenWidth) <= v6->Geom.VisibleRect.x1 )
          goto LABEL_144;
        if ( (int)v50 >= (int)v6->Geom.VisibleRect.x2 )
        {
          v22 = FLOAT_20_0;
          ScreenWidth = 0.0;
          goto LABEL_156;
        }
      }
      v108 = result.UnderlineStyle != Underline_None;
      if ( v29 )
      {
        *(_DWORD *)val = 3;
        v115 = v50;
        v116 = 3;
        v51 = val;
        v52 = 12;
        p_Data = &v155->Data;
        do
        {
          Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(p_Data, v51++);
          --v52;
        }
        while ( v52 );
        v107 = 0;
        UnderlineStyle = v113;
        v41 = v124;
        v6 = v154;
      }
      if ( (*v41 & 0x200) != 0
        || v109
        || (v54 = v6->Geom.Flags, (v54 & 4) != 0)
        || (v54 & 0x20) != 0
        || ((x1 = v6->Geom.VisibleRect.x1, v50 >= x1) || (float)(v50 + ScreenWidth) <= x1)
        && ((v56 = v6->Geom.VisibleRect.x2, v50 >= v56) || (float)(v50 + ScreenWidth) <= v56) )
      {
        v60 = v155;
      }
      else
      {
        v57 = v6->Geom.VisibleRect.x2;
        v58 = v6->Geom.VisibleRect.y1 + -40.0;
        v59 = v6->Geom.VisibleRect.y2 + 40.0;
        v60 = v155;
        v155->ClipBox.x1 = x1;
        v60->ClipBox.y1 = v58;
        v60->ClipBox.x2 = v57;
        v60->ClipBox.y2 = v59;
        v109 = 1;
      }
      if ( !v148 )
        break;
      v61 = (Scaleform::RefCountImpl *)v148->pImage.pObject;
      if ( !v61 )
      {
        id.Id = 135168;
        Scaleform::LogDebugMessage((Scaleform::LogMessageId)&id, "An image in TextLayout is NULL");
        pGlyphs = result.pGlyphs;
LABEL_144:
        v64 = v111;
        goto LABEL_145;
      }
      v62 = (__m128)LODWORD(v148->Matrix.M[0][1]);
      v63 = (__m128)LODWORD(v148->Matrix.M[0][0]);
      v64 = v111;
      v62.m128_f32[0] = (float)(v62.m128_f32[0] * v62.m128_f32[0])
                      + (float)(v148->Matrix.M[1][1] * v148->Matrix.M[1][1]);
      v63.m128_f32[0] = (float)(v63.m128_f32[0] * v63.m128_f32[0])
                      + (float)(v148->Matrix.M[1][0] * v148->Matrix.M[1][0]);
      Scaleform::Render::TextLayout::Builder::AddImage(
        v60,
        v61,
        _mm_sqrt_ps(v63).m128_f32[0],
        _mm_sqrt_ps(v62).m128_f32[0],
        v148->BaseLineY,
        (float)v111);
      pGlyphs = result.pGlyphs;
LABEL_145:
      if ( pGlyphs && pGlyphs < result.pEndGlyphs )
      {
        Delta = result.Delta;
        if ( !result.Delta )
        {
          Delta = pGlyphs->LenAndFontSize >> 12;
          result.Delta = Delta;
        }
        result.pGlyphs = pGlyphs + 1;
        if ( (pGlyphs[1].LenAndFontSize & 0xF000) != 0
          && Delta
          && result.HighlighterIter.CurAdjStartPos < result.HighlighterIter.NumGlyphs )
        {
          result.HighlighterIter.CurAdjStartPos += Delta;
          Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(&result.HighlighterIter);
          result.Delta = 0;
        }
        Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&result);
        pGlyphs = result.pGlyphs;
      }
      v27 = v27 + (float)v64;
      v22 = FLOAT_20_0;
      ScreenWidth = 0.0;
      v6 = v154;
      v29 = v107;
    }
    ColorV = result.ColorV;
    if ( result.ColorV != v15 )
    {
      *(_DWORD *)v122 = 1;
      v123 = *(float *)&result.ColorV;
      v66 = v122;
      v67 = 8;
      v68 = &v60->Data;
      do
      {
        Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(v68, v66++);
        --v67;
      }
      while ( v67 );
      v41 = v124;
    }
    v69 = f;
    if ( f != v135 || v45 != v17 )
    {
      Scaleform::Render::TextLayout::Builder::ChangeFont(v155, f, v45);
      Scaleform::Render::TextLayout::Builder::AddRefCntData(v155, result.pFontHandle.pObject);
    }
    if ( (*((_BYTE *)v41 + 1) & 1) != 0 )
    {
      if ( UnderlineColor )
      {
        switch ( v113 )
        {
          case Underline_Thick:
            v77 = 1;
            break;
          case Underline_Dotted:
            v77 = 2;
            break;
          case Underline_DottedThick:
            v77 = 3;
            break;
          case Underline_DitheredSingle:
            v77 = 4;
            break;
          case Underline_DitheredThick:
            v77 = 5;
            break;
          default:
            v77 = 0;
            break;
        }
        *(_WORD *)v129 = 6;
        v130 = v77;
        v131 = v33 - (float)(int)v154->Geom.HScrollOffset;
        v132 = (float)(*(float *)&v116 * 0.5) + v115;
        v133 = (float)v112;
        v134 = UnderlineColor;
        v78 = v129;
        v79 = 20;
        v80 = &v155->Data;
        do
        {
          Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(v80, v78++);
          --v79;
        }
        while ( v79 );
      }
      v112 = 0;
      v72 = 0;
      v71 = *(float *)val;
      v70 = v111;
    }
    else if ( UnderlineColor == result.UnderlineColor && v113 == result.UnderlineStyle )
    {
      v70 = v111;
      v71 = *(float *)val;
      v72 = v108;
      if ( result.UnderlineColor )
        v112 += v111;
    }
    else
    {
      if ( UnderlineColor )
      {
        switch ( v113 )
        {
          case Underline_Thick:
            v73 = 1;
            break;
          case Underline_Dotted:
            v73 = 2;
            break;
          case Underline_DottedThick:
            v73 = 3;
            break;
          case Underline_DitheredSingle:
            v73 = 4;
            break;
          case Underline_DitheredThick:
            v73 = 5;
            break;
          default:
            v73 = 0;
            break;
        }
        LOWORD(id.Id) = 6;
        HIWORD(id.Id) = v73;
        v126 = v33 - (float)(int)v154->Geom.HScrollOffset;
        *(float *)&f = (float)(*(float *)&v116 * 0.5) + v115;
        *((float *)&f + 1) = (float)v112;
        v128 = UnderlineColor;
        p_id = &id;
        v75 = 20;
        v76 = &v155->Data;
        do
        {
          Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(v76, (const char *)p_id);
          p_id = (Scaleform::LogMessageId *)((char *)p_id + 1);
          --v75;
        }
        while ( v75 );
      }
      v33 = v27;
      v71 = *(float *)val;
      v115 = *(float *)val;
      v70 = v111;
      v112 = v111;
      v72 = v108;
    }
    if ( result.SelectionColor || v30 )
    {
      v81 = Scaleform::Render::Text::LineBuffer::Line::GetHeight(v118);
      v82 = (float)(Scaleform::Render::Text::LineBuffer::Line::GetNonNegLeading(v118) + v81);
      v83 = v71 - Scaleform::Render::Text::LineBuffer::Line::GetAscent(v118);
      v84 = (float)v70 + v27;
      v85 = v82 + v83;
      if ( SelectionColor == v30 )
      {
        if ( !SelectionColor )
          goto LABEL_132;
        if ( v40 > v27 )
          v40 = v27;
        if ( v38 <= v84 )
          v38 = (float)v70 + v27;
        if ( *(float *)&v39 > v83 )
          *(float *)&v39 = v83;
        if ( *(float *)&v37 > v85 )
          goto LABEL_132;
      }
      else
      {
        if ( v30 )
        {
          LODWORD(v86) = COERCE_UNSIGNED_INT((float)(int)v154->Geom.HScrollOffset) ^ _xmm[0];
          *(_DWORD *)v142 = 5;
          v143 = v30;
          v144 = v86 + v40;
          v145 = v39;
          v146 = v86 + v38;
          v147 = v37;
          v87 = v142;
          v88 = 24;
          v89 = v155;
          do
          {
            Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(&v89->Data, v87++);
            --v88;
          }
          while ( v88 );
          v70 = v111;
        }
        v40 = v27;
        *(float *)&v39 = v83;
        v38 = v84;
      }
      *(float *)&v37 = v85;
    }
LABEL_132:
    if ( result.pFontHandle.pObject )
    {
      v90 = result.pFontHandle.pObject->OverridenFontFlags & 1;
      v91 = (result.pFontHandle.pObject->OverridenFontFlags & 2) != 0;
    }
    else
    {
      v90 = 0;
      v91 = 0;
    }
    v92 = (*v124 & 0x200) != 0;
    if ( v91 )
      v92 |= 2u;
    if ( v90 )
      v92 |= 4u;
    v119[0] = 0;
    v119[1] = v92;
    v120 = (__int16)v118;
    v121 = (float)v70;
    v93 = v119;
    v94 = 8;
    v95 = &v155->Data;
    do
    {
      Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(v95, v93++);
      --v94;
    }
    while ( v94 );
    v15 = ColorV;
    v135 = v69;
    v17 = v45;
    v30 = SelectionColor;
    pGlyphs = result.pGlyphs;
    v64 = v111;
    if ( v72 )
    {
      UnderlineColor = result.UnderlineColor;
      UnderlineStyle = result.UnderlineStyle;
      v113 = result.UnderlineStyle;
    }
    else
    {
      UnderlineColor = 0;
      UnderlineStyle = Underline_None;
      v113 = Underline_None;
    }
    goto LABEL_145;
  }
LABEL_180:
  v106 = v157;
  bld->Param.TextParam.pFont = *v157;
  *(_QWORD *)&bld->Param.TextParam.GlyphIndex = v106[1];
  *(_QWORD *)&bld->Param.TextParam.BlurY = v106[2];
  bld->Param.ShadowParam.pFont = v106[3];
  *(_QWORD *)&bld->Param.ShadowParam.GlyphIndex = v106[4];
  *(_QWORD *)&bld->Param.ShadowParam.BlurY = v106[5];
  *(_QWORD *)&bld->Param.ShadowColor = v106[6];
  *(_QWORD *)&bld->Param.ShadowOffsetY = v106[7];
}

// File Line: 795
// RVA: 0x979680
Scaleform::Render::Text::FontHandle *__fastcall Scaleform::Render::Text::LineBuffer::FindFirstFontInfo(
        Scaleform::Render::Text::LineBuffer *this)
{
  unsigned __int64 v2; // rdi
  unsigned __int64 Size; // rsi
  unsigned int Delta; // eax
  Scaleform::Render::Text::ImageDesc *v5; // rcx
  Scaleform::Render::Text::FontHandle *v6; // rcx
  Scaleform::Render::Text::FontHandle *pObject; // rdi
  Scaleform::Render::Text::ImageDesc *v8; // rcx
  Scaleform::Render::Text::FontHandle *v9; // rcx
  Scaleform::Render::Text::LineBuffer::GlyphIterator result; // [rsp+30h] [rbp-B8h] BYREF

  v2 = 0i64;
  Size = this->Lines.Data.Size;
  if ( Size )
  {
    do
    {
      Scaleform::Render::Text::LineBuffer::Line::Begin(this->Lines.Data.Data[v2], &result);
      while ( result.pGlyphs && result.pGlyphs < result.pEndGlyphs )
      {
        if ( (result.pGlyphs->Flags & 0x2000) != 0 )
        {
          pObject = result.pFontHandle.pObject;
          v8 = result.pImage.pObject;
          if ( result.pImage.pObject )
          {
            --result.pImage.pObject->RefCount;
            if ( !v8->RefCount )
              v8->vfptr->__vecDelDtor(v8, 1u);
          }
          v9 = result.pFontHandle.pObject;
          if ( result.pFontHandle.pObject && !_InterlockedDecrement(&result.pFontHandle.pObject->RefCount) && v9 )
            v9->vfptr->__vecDelDtor(v9, 1u);
          return pObject;
        }
        Delta = result.Delta;
        if ( !result.Delta )
        {
          Delta = result.pGlyphs->LenAndFontSize >> 12;
          result.Delta = Delta;
        }
        ++result.pGlyphs;
        if ( (result.pGlyphs->LenAndFontSize & 0xF000) != 0
          && Delta
          && result.HighlighterIter.CurAdjStartPos < result.HighlighterIter.NumGlyphs )
        {
          result.HighlighterIter.CurAdjStartPos += Delta;
          Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(&result.HighlighterIter);
          result.Delta = 0;
        }
        Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&result);
      }
      v5 = result.pImage.pObject;
      if ( result.pImage.pObject )
      {
        --result.pImage.pObject->RefCount;
        if ( !v5->RefCount )
          v5->vfptr->__vecDelDtor(v5, 1u);
      }
      v6 = result.pFontHandle.pObject;
      if ( result.pFontHandle.pObject && !_InterlockedDecrement(&result.pFontHandle.pObject->RefCount) && v6 )
        v6->vfptr->__vecDelDtor(v6, 1u);
      ++v2;
    }
    while ( v2 < Size );
  }
  return 0i64;
}

// File Line: 813
// RVA: 0x998B60
void __fastcall Scaleform::Render::Text::LoadTextFieldParamFromTextFilter(
        Scaleform::Render::TextFieldParam *params,
        Scaleform::Render::Text::TextFilter *filter)
{
  params->TextParam.BlurX = (int)(float)((float)(filter->BlurX * 16.0) + 0.5);
  params->TextParam.BlurY = (int)(float)((float)(filter->BlurY * 16.0) + 0.5);
  params->TextParam.Flags = 128;
  params->TextParam.BlurStrength = (int)(float)((float)(filter->BlurStrength * 16.0) + 0.5);
  if ( (filter->ShadowFlags & 1) == 0 )
  {
    params->ShadowParam.Flags = filter->ShadowFlags & 0xFFFE;
    params->ShadowParam.BlurX = (int)(float)((float)(filter->ShadowParams.BlurX * 16.0) + 0.5);
    params->ShadowParam.BlurY = (int)(float)((float)(filter->ShadowParams.BlurX * 16.0) + 0.5);
    params->ShadowParam.BlurStrength = (int)(float)((float)(filter->ShadowParams.Strength * 16.0) + 0.5);
    params->ShadowColor = filter->ShadowParams.Colors[0].Raw;
    *(Scaleform::Render::Point<float> *)&params->ShadowOffsetX = filter->ShadowParams.Offset;
  }
}

