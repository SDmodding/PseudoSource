// File Line: 26
// RVA: 0x957CD0
Scaleform::Render::Text::LineBuffer::Line *__fastcall Scaleform::Render::Text::LineBuffer::TextLineAllocator::AllocLine(Scaleform::Render::Text::LineBuffer::TextLineAllocator *this, unsigned int size, Scaleform::Render::Text::LineBuffer::LineType lineType)
{
  unsigned int v3; // ebx
  Scaleform::Render::Text::LineBuffer::LineType v4; // edi
  Scaleform::Render::Text::LineBuffer::Line *result; // rax
  unsigned int v6; // ecx

  v3 = size;
  v4 = lineType;
  result = (Scaleform::Render::Text::LineBuffer::Line *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                          Scaleform::Memory::pGlobalHeap,
                                                          this,
                                                          size,
                                                          0i64);
  result->MemSize &= 0xF8000000;
  result->MemSize |= v3 & 0x7FFFFFF;
  v6 = result->MemSize & 0x7FFFFFF;
  if ( v4 )
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
void __fastcall Scaleform::Render::Text::LineBuffer::ReleasePartOfLine(Scaleform::Render::Text::LineBuffer::GlyphEntry *pglyphs, unsigned int n, Scaleform::Render::Text::LineBuffer::FormatDataEntry *pnextFormatData)
{
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *v3; // rbx
  unsigned __int16 *v4; // rdi
  __int64 v5; // rsi
  Scaleform::Render::Text::FontHandle *v6; // rcx
  Scaleform::Render::Text::FontHandle *v7; // rcx
  bool v8; // zf

  if ( n )
  {
    v3 = pnextFormatData;
    v4 = &pglyphs->Flags;
    v5 = n;
    do
    {
      if ( (*v4 >> 14) & 1 )
      {
        if ( (*v4 >> 13) & 1 )
        {
          v6 = v3->pFont;
          if ( !_InterlockedDecrement(&v3->pFont->RefCount) && v6 )
            v6->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, 1u);
          ++v3;
        }
        if ( (*v4 >> 12) & 1 )
          ++v3;
        if ( (*v4 >> 11) & 1 )
        {
          v7 = v3->pFont;
          v8 = v3->pFont->RefCount == 1;
          --v7->RefCount;
          if ( v8 )
            v7->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, 1u);
          ++v3;
        }
      }
      v4 += 4;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 75
// RVA: 0x9ABA90
void __fastcall Scaleform::Render::Text::LineBuffer::GlyphInserter::ResetTo(Scaleform::Render::Text::LineBuffer::GlyphInserter *this, Scaleform::Render::Text::LineBuffer::GlyphInserter *savedPos)
{
  Scaleform::Render::Text::LineBuffer::GlyphInserter *v2; // rdi
  __int64 v3; // rcx
  Scaleform::Render::Text::LineBuffer::GlyphInserter *v4; // rbx
  unsigned int v5; // edx

  v2 = this;
  v3 = savedPos->GlyphIndex;
  v4 = savedPos;
  v5 = v2->GlyphIndex;
  if ( (unsigned int)v3 < v5 && v2->GlyphsCount )
    Scaleform::Render::Text::LineBuffer::ReleasePartOfLine(
      &v4->pGlyphs[v3],
      v5 - v3,
      &v4->pNextFormatData[v4->FormatDataIndex]);
  v2->pGlyphs = v4->pGlyphs;
  v2->pNextFormatData = v4->pNextFormatData;
  v2->GlyphIndex = v4->GlyphIndex;
  v2->GlyphsCount = v4->GlyphsCount;
  v2->FormatDataIndex = v4->FormatDataIndex;
}

// File Line: 92
// RVA: 0x94EF60
void __fastcall Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(Scaleform::Render::Text::LineBuffer::GlyphIterator *this)
{
  Scaleform::Render::Text::LineBuffer::GlyphIterator *v1; // rbx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v2; // rcx
  __int64 v3; // rax
  unsigned __int64 v4; // rdx

  v1 = this;
  v2 = this->pGlyphs;
  if ( v2 && v2 < v1->pEndGlyphs )
  {
    if ( !v1->Delta )
      v1->Delta = (unsigned int)v2->LenAndFontSize >> 12;
    v1->pGlyphs = v2 + 1;
    if ( v2[1].LenAndFontSize & 0xF000 )
    {
      v3 = v1->Delta;
      if ( (_DWORD)v3 )
      {
        v4 = v1->HighlighterIter.CurAdjStartPos;
        if ( v4 < v1->HighlighterIter.NumGlyphs )
        {
          if ( (_DWORD)v3 )
          {
            v1->HighlighterIter.CurAdjStartPos = v4 + v3;
            Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(&v1->HighlighterIter);
          }
          v1->Delta = 0;
        }
      }
    }
    Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(v1);
  }
}

// File Line: 108
// RVA: 0x9BDE40
void __fastcall Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(Scaleform::Render::Text::LineBuffer::GlyphIterator *this)
{
  Scaleform::Render::Text::LineBuffer::GlyphIterator *v1; // rbx
  Scaleform::Render::Text::ImageDesc *v2; // rcx
  bool v3; // zf
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v4; // rax
  unsigned __int16 v5; // cx
  Scaleform::Render::Text::FontHandle *v6; // rdi
  Scaleform::Render::Text::FontHandle *v7; // rcx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v8; // rdx
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *v9; // rcx
  unsigned int v10; // eax
  Scaleform::Render::Text::ImageDesc *v11; // rdi
  Scaleform::Render::Text::ImageDesc *v12; // rcx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v13; // rcx
  unsigned int v14; // eax
  char v15; // al
  unsigned int v16; // eax
  unsigned int v17; // eax

  v1 = this;
  v2 = this->pImage.pObject;
  if ( v2 )
  {
    v3 = v2->RefCount-- == 1;
    if ( v3 )
      v2->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, 1u);
  }
  v1->pImage.pObject = 0i64;
  v4 = v1->pGlyphs;
  if ( v1->pGlyphs && v4 < v1->pEndGlyphs )
  {
    v5 = v4->Flags;
    if ( (v5 >> 14) & 1 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = v1->pNextFormatData->pFont;
        if ( v6 )
          _InterlockedExchangeAdd(&v6->RefCount, 1u);
        v7 = v1->pFontHandle.pObject;
        if ( v7 && !_InterlockedDecrement(&v7->RefCount) && v7 )
          v7->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, 1u);
        v1->pFontHandle.pObject = v6;
        ++v1->pNextFormatData;
      }
      v8 = v1->pGlyphs;
      if ( (v1->pGlyphs->Flags >> 12) & 1 )
      {
        v9 = v1->pNextFormatData;
        v10 = (unsigned int)v9->pFont;
        v1->ColorV = (unsigned int)v9->pFont;
        v1->OrigColor = v10;
        v1->pNextFormatData = v9 + 1;
      }
      if ( (v8->Flags >> 11) & 1 )
      {
        v11 = v1->pNextFormatData->pImage;
        if ( v11 )
          ++v11->RefCount;
        v12 = v1->pImage.pObject;
        if ( v12 )
        {
          v3 = v12->RefCount-- == 1;
          if ( v3 )
            v12->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v12->vfptr, 1u);
        }
        v1->pImage.pObject = v11;
        ++v1->pNextFormatData;
      }
    }
    v13 = v1->pGlyphs;
    if ( (v1->pGlyphs->Flags >> 10) & 1 )
    {
      v14 = v1->ColorV;
      v1->UnderlineStyle = 1;
      v1->UnderlineColor = v14;
    }
    else
    {
      v1->UnderlineStyle = 0;
    }
    if ( v1->HighlighterIter.CurAdjStartPos >= v1->HighlighterIter.NumGlyphs )
    {
      v1->SelectionColor = 0;
      if ( (v13->Flags >> 10) & 1 )
      {
        v17 = v1->ColorV;
        v1->UnderlineStyle = 1;
        v1->UnderlineColor = v17;
      }
    }
    else
    {
      v1->ColorV = v1->OrigColor;
      if ( v13->LenAndFontSize & 0xF000 || (LOBYTE(v13->Flags) >> 3) & 1 )
      {
        if ( v1->HighlighterIter.CurDesc.Info.Flags & 0x10 )
          v1->ColorV = v1->HighlighterIter.CurDesc.Info.TextColor.Raw;
        v15 = v1->HighlighterIter.CurDesc.Info.Flags;
        if ( v15 & 7 )
          v1->UnderlineStyle = v15 & 7;
        if ( v1->HighlighterIter.CurDesc.Info.Flags & 0x20 )
          v16 = v1->HighlighterIter.CurDesc.Info.UnderlineColor.Raw;
        else
          v16 = v1->ColorV;
        v1->UnderlineColor = v16;
        if ( v1->HighlighterIter.CurDesc.Info.Flags & 8 )
          v1->SelectionColor = v1->HighlighterIter.CurDesc.Info.BackgroundColor.Raw;
        else
          v1->SelectionColor = 0;
      }
    }
  }
}

// File Line: 174
// RVA: 0x984AF0
Scaleform::Render::Text::LineBuffer::FormatDataEntry *__fastcall Scaleform::Render::Text::LineBuffer::Line::GetFormatData(Scaleform::Render::Text::LineBuffer::Line *this)
{
  char *v1; // rdx
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *result; // rax

  v1 = &this->Data8.Leading + 1;
  if ( (this->MemSize & 0x80000000) == 0 )
    v1 = (char *)&this->Data8 + 38;
  if ( (this->MemSize & 0x80000000) == 0 )
    result = (Scaleform::Render::Text::LineBuffer::FormatDataEntry *)((unsigned __int64)&v1[8 * this->Data32.GlyphsCount
                                                                                          + 7] & 0xFFFFFFFFFFFFFFF8ui64);
  else
    result = (Scaleform::Render::Text::LineBuffer::FormatDataEntry *)((unsigned __int64)&v1[8
                                                                                          * (unsigned __int8)this->Data8.GlyphsCount
                                                                                          + 7] & 0xFFFFFFFFFFFFFFF8ui64);
  return result;
}

// File Line: 183
// RVA: 0x9A7990
void __fastcall Scaleform::Render::Text::LineBuffer::Line::Release(Scaleform::Render::Text::LineBuffer::Line *this)
{
  Scaleform::Render::Text::LineBuffer::Line *v1; // rbx
  unsigned int v2; // ecx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v3; // r9
  bool v4; // cl
  unsigned int v5; // edx
  signed __int64 v6; // r8
  __int64 v7; // rax

  v1 = this;
  v2 = this->MemSize;
  if ( (v2 >> 30) & 1 )
  {
    v3 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(&v1->Data8.Leading + 1);
    v4 = (v2 & 0x80000000) != 0;
    if ( !v4 )
      v3 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)&v1->Data8 + 38);
    if ( v4 )
      v5 = (unsigned __int8)v1->Data8.GlyphsCount;
    else
      v5 = v1->Data32.GlyphsCount;
    v6 = (signed __int64)(&v1->Data8.Leading + 1);
    if ( v4 )
    {
      v7 = (unsigned __int8)v1->Data8.GlyphsCount;
    }
    else
    {
      v7 = v1->Data32.GlyphsCount;
      v6 = (signed __int64)&v1->Data8 + 38;
    }
    Scaleform::Render::Text::LineBuffer::ReleasePartOfLine(
      v3,
      v5,
      (Scaleform::Render::Text::LineBuffer::FormatDataEntry *)((v6 + 8 * v7 + 7) & 0xFFFFFFFFFFFFFFF8ui64));
    if ( (v1->MemSize & 0x80000000) == 0 )
      v1->Data32.GlyphsCount = 0;
    else
      v1->Data8.GlyphsCount = 0;
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
  Scaleform::Render::Text::LineBuffer *v1; // rbx

  v1 = this;
  this->Geom.Flags |= 1u;
  Scaleform::Render::Text::LineBuffer::RemoveLines(this, 0, this->Lines.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Lines.Data.Data);
}

// File Line: 231
// RVA: 0x988660
Scaleform::Render::Text::LineBuffer::Line *__fastcall Scaleform::Render::Text::LineBuffer::GetLine(Scaleform::Render::Text::LineBuffer *this, unsigned int lineIdx)
{
  Scaleform::Render::Text::LineBuffer::Line *result; // rax

  if ( lineIdx < this->Lines.Data.Size )
    result = this->Lines.Data.Data[lineIdx];
  else
    result = 0i64;
  return result;
}

// File Line: 257
// RVA: 0x995540
Scaleform::Render::Text::LineBuffer::Line *__fastcall Scaleform::Render::Text::LineBuffer::InsertNewLine(Scaleform::Render::Text::LineBuffer *this, unsigned int lineIdx, unsigned int glyphCount, unsigned int formatDataElementsCount, Scaleform::Render::Text::LineBuffer::LineType lineType)
{
  unsigned int v5; // esi
  Scaleform::ArrayData<Scaleform::GFx::AS2::Value *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value *,2>,Scaleform::ArrayDefaultPolicy> *v6; // rdi
  signed int v7; // eax
  unsigned __int64 v8; // rbp
  Scaleform::Render::Text::LineBuffer::Line *result; // rax
  Scaleform::Render::Text::LineBuffer::Line *v10; // rbx
  unsigned __int64 v11; // r8
  Scaleform::Render::Text::LineBuffer::Line **v12; // rcx

  v5 = glyphCount;
  v6 = (Scaleform::ArrayData<Scaleform::GFx::AS2::Value *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value *,2>,Scaleform::ArrayDefaultPolicy> *)this;
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
      result->Data32.GlyphsCount = v5;
    else
      result->Data8.GlyphsCount = v5;
    Scaleform::ArrayData<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      v6,
      v6->Size + 1);
    v11 = v6->Size;
    if ( v8 < v11 - 1 )
      memmove(&v6->Data[v8 + 1], &v6->Data[v8], 8 * (v11 - v8) - 8);
    v12 = (Scaleform::Render::Text::LineBuffer::Line **)&v6->Data[v8];
    if ( v12 )
      *v12 = v10;
    result = v10;
  }
  return result;
}

// File Line: 268
// RVA: 0x9A9E70
void __fastcall Scaleform::Render::Text::LineBuffer::RemoveLines(Scaleform::Render::Text::LineBuffer *this, unsigned int lineIdx, unsigned int num)
{
  unsigned int v3; // ebp
  __int64 v4; // r12
  Scaleform::Render::Text::LineBuffer *v5; // rbx
  unsigned int v6; // edi
  __int64 v7; // r15
  Scaleform::Render::Text::LineBuffer::Line *v8; // r14
  unsigned __int64 v9; // r8

  v3 = 0;
  v4 = lineIdx;
  v5 = this;
  v6 = lineIdx;
  v7 = num;
  if ( num )
  {
    do
    {
      if ( !v5 || v6 >= v5->Lines.Data.Size || (v6 & 0x80000000) != 0 )
        break;
      v8 = v5->Lines.Data.Data[v6];
      if ( v8 )
      {
        Scaleform::Render::Text::LineBuffer::Line::Release(v5->Lines.Data.Data[v6]);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
      }
      if ( v6 < v5->Lines.Data.Size )
        ++v6;
      ++v3;
    }
    while ( v3 < (unsigned int)v7 );
  }
  v9 = v5->Lines.Data.Size;
  if ( v9 == v7 )
  {
    if ( v9 && v5->Lines.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
    {
      if ( v5->Lines.Data.Data )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Text::LineBuffer::Line **, unsigned __int64, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v5->Lines.Data.Data,
          v9,
          v4);
        v5->Lines.Data.Data = 0i64;
      }
      v5->Lines.Data.Policy.Capacity = 0i64;
    }
    v5->Lines.Data.Size = 0i64;
  }
  else
  {
    memmove(&v5->Lines.Data.Data[v4], &v5->Lines.Data.Data[v4 + v7], 8 * (v9 - v4 - v7));
    v5->Lines.Data.Size -= v7;
  }
}

// File Line: 278
// RVA: 0x98EB80
__int64 __fastcall Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(Scaleform::Render::Text::LineBuffer *this)
{
  unsigned __int64 v1; // rax
  unsigned __int64 v2; // rdx
  Scaleform::Render::Text::LineBuffer::Line **v3; // rdx
  Scaleform::Render::Text::LineBuffer::Line *v4; // rcx
  Scaleform::Render::Text::LineBuffer::Line *v5; // rdx
  unsigned int v6; // et1
  unsigned int v7; // et1

  v1 = this->Geom.FirstVisibleLinePos;
  if ( !(_DWORD)v1 )
    return 0i64;
  v2 = this->Lines.Data.Size;
  if ( v1 >= v2 || (v1 & 0x80000000) != 0i64 || !v2 )
    return 0i64;
  v3 = this->Lines.Data.Data;
  v4 = this->Lines.Data.Data[v1];
  v5 = *v3;
  v6 = v4->MemSize;
  v7 = v5->MemSize;
  return (unsigned int)(v4->Data32.OffsetY - v5->Data32.OffsetY);
}

// File Line: 322
// RVA: 0x97A760
Scaleform::Render::Text::LineBuffer::Iterator *__fastcall Scaleform::Render::Text::LineBuffer::FindLineByTextPos(Scaleform::Render::Text::LineBuffer *this, Scaleform::Render::Text::LineBuffer::Iterator *result, unsigned __int64 textPos)
{
  unsigned __int64 v3; // rbx
  Scaleform::Render::Text::LineBuffer *v4; // rsi
  signed __int64 v5; // r9
  signed __int64 v6; // r11
  Scaleform::Render::Text::LineBuffer::Line **v7; // r14
  signed __int64 v8; // rdi
  Scaleform::Render::Text::LineBuffer::Line *v9; // rax
  signed int v10; // ecx
  unsigned int v11; // er8
  Scaleform::Render::Text::LineBuffer::Line *v12; // r8
  unsigned int v13; // ecx
  unsigned int v14; // eax
  unsigned __int8 v15; // al
  Scaleform::Render::Text::LineBuffer::Iterator *v16; // rax

  v3 = textPos;
  v4 = this;
  if ( !this->Lines.Data.Size )
    goto LABEL_30;
  v5 = this->Lines.Data.Size;
  v6 = 0i64;
  if ( v5 > 0 )
  {
    v7 = this->Lines.Data.Data;
    do
    {
      v8 = (v5 >> 1) + v6;
      v9 = v7[v8];
      v10 = v9->Data32.TextPos;
      if ( (v9->MemSize & 0x80000000) != 0 )
      {
        v10 &= 0xFFFFFFu;
        if ( v10 == 0xFFFFFF )
          v10 = -1;
      }
      if ( (signed int)v3 >= v10
        && ((v9->MemSize & 0x80000000) == 0 ? (v11 = v9->Data32.TextLength) : (v11 = HIBYTE(v9->Data8.TextPosAndLength)),
            (signed int)v3 < (signed int)(v11 + v10))
        || v10 - (signed int)v3 >= 0 )
      {
        v5 >>= 1;
      }
      else
      {
        v6 = v8 + 1;
        v5 += -1 - (v5 >> 1);
      }
    }
    while ( v5 > 0 );
  }
  if ( v6 == v4->Lines.Data.Size )
    LODWORD(v6) = v6 - 1;
  v12 = v4->Lines.Data.Data[(unsigned int)v6];
  v13 = v12->Data32.TextPos;
  if ( (v12->MemSize & 0x80000000) != 0 )
  {
    v13 &= 0xFFFFFFu;
    if ( v13 == 0xFFFFFF )
      v13 = -1;
  }
  if ( v3 >= v13
    && ((v12->MemSize & 0x80000000) == 0 ? (v14 = v12->Data32.TextLength) : (v14 = HIBYTE(v12->Data8.TextPosAndLength)),
        v3 <= v14 + v13) )
  {
    v15 = v4->Geom.Flags;
    result->pLineBuffer = v4;
    result->CurrentPos = v6;
    result->YOffset = 0.0;
    result->pHighlight = 0i64;
    result->StaticText = (v15 >> 2) & 1;
    v16 = result;
  }
  else
  {
LABEL_30:
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
Scaleform::Render::Text::LineBuffer::Iterator *__fastcall Scaleform::Render::Text::LineBuffer::FindLineAtYOffset(Scaleform::Render::Text::LineBuffer *this, Scaleform::Render::Text::LineBuffer::Iterator *result, float yoff)
{
  float v3; // xmm3_4
  Scaleform::Render::Text::LineBuffer *v4; // rdi
  signed __int64 v5; // r8
  signed __int64 v6; // r11
  Scaleform::Render::Text::LineBuffer::Line **v7; // r14
  signed __int64 v8; // rbx
  Scaleform::Render::Text::LineBuffer::Line *v9; // rax
  float v10; // xmm2_4
  signed int v11; // er9
  signed int v12; // ecx
  Scaleform::Render::Text::LineBuffer::Line *v13; // r8
  unsigned int v14; // er9
  int v15; // eax
  unsigned __int8 v16; // al
  Scaleform::Render::Text::LineBuffer::Iterator *v17; // rax

  v3 = yoff;
  v4 = this;
  if ( !this->Lines.Data.Size )
    goto LABEL_30;
  v5 = this->Lines.Data.Size;
  v6 = 0i64;
  if ( v5 > 0 )
  {
    v7 = this->Lines.Data.Data;
    do
    {
      v8 = (v5 >> 1) + v6;
      v9 = v7[v8];
      v10 = (float)v7[v8]->Data32.OffsetY;
      if ( v3 >= v10
        && ((v9->MemSize & 0x80000000) == 0 ? (v11 = v9->Data32.Height) : (v11 = v9->Data8.Height),
            (v9->MemSize & 0x80000000) == 0 ? (v12 = v9->Data32.Leading) : (v12 = v9->Data8.Leading),
            v3 < (float)((float)((float)v11 + v10) + (float)v12))
        || (signed int)(float)(v10 - v3) >= 0 )
      {
        v5 >>= 1;
      }
      else
      {
        v6 = v8 + 1;
        v5 += -1 - (v5 >> 1);
      }
    }
    while ( v5 > 0 );
  }
  if ( v6 == v4->Lines.Data.Size )
    LODWORD(v6) = v6 - 1;
  v13 = v4->Lines.Data.Data[(unsigned int)v6];
  if ( v3 >= (float)v4->Lines.Data.Data[(unsigned int)v6]->Data32.OffsetY
    && ((v13->MemSize & 0x80000000) == 0 ? (v14 = v13->Data32.Height) : (v14 = v13->Data8.Height),
        (v13->MemSize & 0x80000000) == 0 ? (v15 = v13->Data32.Leading) : (v15 = v13->Data8.Leading),
        v3 < (float)(signed int)(v13->Data32.OffsetY + v14 + v15)) )
  {
    v16 = v4->Geom.Flags;
    result->pLineBuffer = v4;
    result->CurrentPos = v6;
    result->YOffset = 0.0;
    result->pHighlight = 0i64;
    result->StaticText = (v16 >> 2) & 1;
    v17 = result;
  }
  else
  {
LABEL_30:
    result->pLineBuffer = 0i64;
    *(_QWORD *)&result->CurrentPos = 0i64;
    result->StaticText = 0;
    result->pHighlight = 0i64;
    v17 = result;
  }
  return v17;
}

// File Line: 382
// RVA: 0x997AA0
_BOOL8 __fastcall Scaleform::Render::Text::LineBuffer::IsLineVisible(Scaleform::Render::Text::LineBuffer *this, unsigned int lineIndex, float yOffset)
{
  Scaleform::Render::Text::LineBuffer::Line *v3; // r9
  unsigned int v4; // eax
  unsigned int v5; // et1
  unsigned int v7; // eax

  v3 = this->Lines.Data.Data[lineIndex];
  v4 = this->Geom.FirstVisibleLinePos;
  if ( lineIndex != v4 )
    return lineIndex > v4
        && ((v3->MemSize & 0x80000000) == 0 ? (v7 = v3->Data32.Height) : (v7 = v3->Data8.Height),
            (float)((float)(signed int)(v3->Data32.OffsetY + v7) + yOffset) <= (float)((float)(this->Geom.VisibleRect.y2
                                                                                             - this->Geom.VisibleRect.y1)
                                                                                     + 20.0));
  v5 = v3->MemSize;
  return (float)((float)(this->Geom.VisibleRect.y2 - this->Geom.VisibleRect.y1) + 20.0) >= (float)((float)v3->Data32.OffsetY
                                                                                                 + yOffset);
}

// File Line: 396
// RVA: 0x997BA0
bool __fastcall Scaleform::Render::Text::LineBuffer::IsPartiallyVisible(Scaleform::Render::Text::LineBuffer *this, float yOffset)
{
  unsigned int v2; // eax
  float v3; // xmm3_4
  Scaleform::Render::Text::LineBuffer::Line *v4; // r8
  unsigned int v5; // edx
  unsigned int v6; // edx
  signed int v7; // edx
  float v8; // xmm1_4
  float v9; // xmm0_4
  bool result; // al

  v2 = this->Geom.FirstVisibleLinePos;
  v3 = yOffset;
  result = 0;
  if ( v2 < LODWORD(this->Lines.Data.Size) )
  {
    v4 = this->Lines.Data.Data[v2];
    v5 = (v4->MemSize & 0x80000000) == 0 ? v4->Data32.Width : v4->Data8.Width;
    if ( v5 )
    {
      v6 = (v4->MemSize & 0x80000000) == 0 ? v4->Data32.Height : v4->Data8.Height;
      if ( v6 )
      {
        v7 = (v4->MemSize & 0x80000000) == 0 ? v4->Data32.Height : v4->Data8.Height;
        v8 = (float)(this->Geom.VisibleRect.y2 - this->Geom.VisibleRect.y1) + 20.0;
        v9 = (float)v4->Data32.OffsetY + v3;
        if ( v9 <= v8 && (float)(v9 + (float)v7) > v8 )
          result = 1;
      }
    }
  }
  return result;
}

// File Line: 424
// RVA: 0x9AD830
void __fastcall Scaleform::Render::Text::LineBuffer::Scale(Scaleform::Render::Text::LineBuffer *this, float scaleFactor)
{
  float v2; // xmm6_4
  Scaleform::Render::Text::LineBuffer *v3; // rbx
  unsigned int v4; // edi
  Scaleform::Render::Text::LineBuffer::Line *v5; // rcx
  bool v6; // al
  signed int v7; // edx
  float v8; // xmm1_4
  signed int v9; // edx
  float v10; // xmm2_4
  signed int v11; // edx
  float v12; // xmm0_4
  signed int v13; // edx
  signed int v14; // edx
  signed int v15; // er8
  signed int v16; // eax
  signed int v17; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v18; // rcx
  int v19; // eax
  signed int v20; // eax
  unsigned __int16 v21; // r8
  unsigned __int16 v22; // dx
  float v23; // xmm1_4
  float v24; // xmm1_4
  signed int v25; // er9
  unsigned __int16 v26; // dx
  __int16 v27; // ax
  unsigned int v28; // eax
  Scaleform::Render::Text::ImageDesc *v29; // rcx
  Scaleform::Render::Text::FontHandle *v30; // rcx
  Scaleform::Render::Text::LineBuffer::GlyphIterator result; // [rsp+30h] [rbp-108h]

  v2 = scaleFactor;
  v3 = this;
  v4 = 0;
  while ( v3 && v4 < v3->Lines.Data.Size && (v4 & 0x80000000) == 0 )
  {
    v5 = v3->Lines.Data.Data[v4];
    v6 = (v5->MemSize & 0x80000000) != 0;
    if ( (v5->MemSize & 0x80000000) == 0 )
      v7 = v5->Data32.Leading;
    else
      v7 = v5->Data8.Leading;
    v8 = (float)v7 * v2;
    if ( (v5->MemSize & 0x80000000) == 0 )
      v9 = v5->Data32.Width;
    else
      v9 = v5->Data8.Width;
    v10 = (float)v9 * v2;
    if ( (v5->MemSize & 0x80000000) == 0 )
      v11 = v5->Data32.Height;
    else
      v11 = v5->Data8.Height;
    v12 = (float)v11 * v2;
    v13 = (signed int)v8;
    if ( (v5->MemSize & 0x80000000) == 0 )
      v5->Data32.Leading = v13;
    else
      v5->Data8.Leading = v13;
    v14 = (signed int)v12;
    v15 = (signed int)v10;
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
      v16 = v5->Data32.BaseLineOffset;
    else
      v16 = v5->Data8.BaseLineOffset;
    v17 = (signed int)(float)((float)v16 * v2);
    if ( (v5->MemSize & 0x80000000) == 0 )
      v5->Data32.BaseLineOffset = v17;
    else
      v5->Data8.BaseLineOffset = v17;
    v5->Data32.OffsetX = (signed int)(float)((float)v5->Data32.OffsetX * v2);
    v5->Data32.OffsetY = (signed int)(float)((float)v5->Data32.OffsetY * v2);
    Scaleform::Render::Text::LineBuffer::Line::Begin(v5, &result);
LABEL_27:
    v18 = result.pGlyphs;
    while ( v18 && v18 < result.pEndGlyphs )
    {
      v19 = v18->Advance;
      if ( (LOBYTE(v18->Flags) >> 6) & 1 )
        v19 = -v19;
      v20 = (signed int)(float)((float)v19 * v2);
      if ( v20 < 0 )
      {
        LOWORD(v20) = abs(v20);
        v18->Flags |= 0x40u;
      }
      else
      {
        v18->Flags &= 0xFFBFu;
      }
      v18->Advance = v20;
      v21 = v18->LenAndFontSize;
      v22 = v18->Flags;
      v23 = (float)(v18->LenAndFontSize & 0xFFF);
      if ( v22 & 0x10 )
        v23 = v23 * 0.0625;
      v24 = v23 * v2;
      if ( v24 < 256.0 && (v25 = (signed int)(float)(v24 * 16.0), v25 & 0xF) )
      {
        v26 = v22 | 0x10;
        v27 = v25 ^ v21;
      }
      else
      {
        v26 = v22 & 0xFFEF;
        v27 = v21 ^ (signed int)v24;
      }
      v18->LenAndFontSize = v21 ^ v27 & 0xFFF;
      v18->Flags = v26;
      v18 = result.pGlyphs;
      if ( !result.pGlyphs )
        break;
      if ( result.pGlyphs < result.pEndGlyphs )
      {
        v28 = result.Delta;
        if ( !result.Delta )
        {
          v28 = (unsigned int)result.pGlyphs->LenAndFontSize >> 12;
          result.Delta = (unsigned int)result.pGlyphs->LenAndFontSize >> 12;
        }
        ++result.pGlyphs;
        if ( result.pGlyphs->LenAndFontSize & 0xF000
          && v28
          && result.HighlighterIter.CurAdjStartPos < result.HighlighterIter.NumGlyphs )
        {
          if ( v28 )
          {
            result.HighlighterIter.CurAdjStartPos += v28;
            Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(&result.HighlighterIter);
          }
          result.Delta = 0;
        }
        Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&result);
        goto LABEL_27;
      }
    }
    v29 = result.pImage.pObject;
    if ( result.pImage.pObject )
    {
      --result.pImage.pObject->RefCount;
      if ( !v29->RefCount )
        v29->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v29->vfptr, 1u);
    }
    v30 = result.pFontHandle.pObject;
    if ( result.pFontHandle.pObject && !_InterlockedDecrement(&result.pFontHandle.pObject->RefCount) && v30 )
      v30->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v30->vfptr, 1u);
    if ( v4 < v3->Lines.Data.Size )
      ++v4;
  }
  v3->Geom.Flags |= 1u;
}

// File Line: 553
// RVA: 0x969B50
void __fastcall Scaleform::Render::Text::LineBuffer::CreateVisibleTextLayout(Scaleform::Render::Text::LineBuffer *this, Scaleform::Render::TextLayout::Builder *bld, Scaleform::Render::Text::Highlighter *phighlighter, Scaleform::Render::TextFieldParam *textFieldParam)
{
  Scaleform::Render::Text::Highlighter *v4; // rsi
  Scaleform::Render::TextLayout::Builder *v5; // r12
  Scaleform::Render::Text::LineBuffer *v6; // r13
  int v7; // er10
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // rax
  Scaleform::Render::Text::LineBuffer::Line **v10; // rdx
  Scaleform::Render::Text::LineBuffer::Line *v11; // rcx
  unsigned int v12; // et1
  unsigned int v13; // et1
  float v14; // xmm9_4
  char v15; // r14
  unsigned __int64 v16; // rcx
  unsigned __int64 v17; // rdx
  char *v18; // rax
  unsigned int v19; // edi
  float v20; // xmm7_4
  float v21; // xmm8_4
  char v22; // al
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm6_4
  Scaleform::Render::Text::LineBuffer::Line *v27; // rcx
  unsigned int v28; // eax
  unsigned int v29; // et1
  unsigned int v30; // eax
  Scaleform::Render::Text::LineBuffer::Line *v31; // r15
  float v32; // xmm10_4
  signed int v33; // eax
  char v34; // r9
  int v35; // er14
  Scaleform::Render::Text::HighlightInfo::UnderlineStyle v36; // esi
  unsigned int v37; // ebx
  float v38; // xmm15_4
  signed int v39; // ecx
  signed int v40; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v41; // rcx
  int v42; // xmm13_4
  float v43; // xmm11_4
  int v44; // xmm14_4
  float v45; // xmm12_4
  unsigned __int16 *v46; // r12
  unsigned __int16 v47; // dx
  int v48; // er11
  unsigned int v49; // er10
  float v50; // xmm9_4
  unsigned int v51; // er15
  float v52; // xmm9_4
  float v53; // xmm6_4
  Scaleform::Render::Font *v54; // r9
  float v55; // xmm0_4
  float v56; // xmm6_4
  char *v57; // rsi
  signed int v58; // er12
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *v59; // r13
  char v60; // al
  float v61; // xmm3_4
  float v62; // xmm1_4
  float v63; // xmm2_4
  Scaleform::Render::TextLayout::Builder *v64; // rcx
  Scaleform::Render::Image *v65; // rdx
  __m128 v66; // xmm1
  __m128 v67; // xmm5
  signed int v68; // er15
  unsigned int v69; // esi
  char *v70; // rdi
  signed int v71; // er12
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *v72; // r13
  Scaleform::Render::Font *v73; // r13
  signed int v74; // edi
  float v75; // xmm7_4
  bool v76; // r12
  signed __int16 v77; // ax
  Scaleform::LogMessageId *v78; // rbx
  signed int v79; // edi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *v80; // r12
  signed __int16 v81; // ax
  char *v82; // rbx
  signed int v83; // edi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *v84; // r12
  int v85; // ebx
  __int128 v86; // xmm8
  float v87; // xmm7_4
  float v88; // xmm6_4
  float v89; // xmm8_4
  float v90; // xmm1_4
  char *v91; // rbx
  signed int v92; // edi
  Scaleform::Render::TextLayout::Builder *v93; // r14
  char v94; // dl
  char v95; // cl
  char v96; // al
  char *v97; // rbx
  signed int v98; // edi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *v99; // r14
  unsigned int v100; // eax
  signed __int16 v101; // cx
  float v102; // xmm15_4
  char *v103; // rbx
  signed int v104; // esi
  float v105; // xmm0_4
  char *v106; // rbx
  signed int v107; // esi
  Scaleform::Render::Text::ImageDesc *v108; // rcx
  Scaleform::Render::Text::FontHandle *v109; // rcx
  _QWORD *v110; // rsi
  char v111; // [rsp+30h] [rbp-90h]
  bool v112; // [rsp+31h] [rbp-8Fh]
  char v113; // [rsp+32h] [rbp-8Eh]
  char v114; // [rsp+33h] [rbp-8Dh]
  signed int v115; // [rsp+34h] [rbp-8Ch]
  signed int v116; // [rsp+38h] [rbp-88h]
  Scaleform::Render::Text::HighlightInfo::UnderlineStyle v117; // [rsp+3Ch] [rbp-84h]
  char val[4]; // [rsp+40h] [rbp-80h]
  float v119; // [rsp+44h] [rbp-7Ch]
  float v120; // [rsp+48h] [rbp-78h]
  int v121; // [rsp+4Ch] [rbp-74h]
  Scaleform::Render::Text::LineBuffer::Line *v122; // [rsp+50h] [rbp-70h]
  char v123[2]; // [rsp+58h] [rbp-68h]
  __int16 v124; // [rsp+5Ah] [rbp-66h]
  float v125; // [rsp+5Ch] [rbp-64h]
  char v126[4]; // [rsp+60h] [rbp-60h]
  float v127; // [rsp+64h] [rbp-5Ch]
  unsigned __int16 *v128; // [rsp+68h] [rbp-58h]
  Scaleform::LogMessageId id; // [rsp+70h] [rbp-50h]
  float v130; // [rsp+74h] [rbp-4Ch]
  Scaleform::Render::Font *f; // [rsp+78h] [rbp-48h]
  unsigned int v132; // [rsp+80h] [rbp-40h]
  char v133[2]; // [rsp+88h] [rbp-38h]
  __int16 v134; // [rsp+8Ah] [rbp-36h]
  float v135; // [rsp+8Ch] [rbp-34h]
  float v136; // [rsp+90h] [rbp-30h]
  float v137; // [rsp+94h] [rbp-2Ch]
  unsigned int v138; // [rsp+98h] [rbp-28h]
  Scaleform::Render::Font *v139; // [rsp+A0h] [rbp-20h]
  char v140[4]; // [rsp+A8h] [rbp-18h]
  int v141; // [rsp+ACh] [rbp-14h]
  float v142; // [rsp+B0h] [rbp-10h]
  int v143; // [rsp+B4h] [rbp-Ch]
  float v144; // [rsp+B8h] [rbp-8h]
  int v145; // [rsp+BCh] [rbp-4h]
  char v146[4]; // [rsp+C0h] [rbp+0h]
  int v147; // [rsp+C4h] [rbp+4h]
  float v148; // [rsp+C8h] [rbp+8h]
  int v149; // [rsp+CCh] [rbp+Ch]
  float v150; // [rsp+D0h] [rbp+10h]
  int v151; // [rsp+D4h] [rbp+14h]
  Scaleform::Render::Text::ImageDesc *v152; // [rsp+D8h] [rbp+18h]
  __int128 v153; // [rsp+E0h] [rbp+20h]
  unsigned __int64 v154; // [rsp+F0h] [rbp+30h]
  Scaleform::Render::Text::LineBuffer::GlyphIterator result; // [rsp+100h] [rbp+40h]
  __int64 v156; // [rsp+1A0h] [rbp+E0h]
  __int128 v157; // [rsp+1B0h] [rbp+F0h]
  Scaleform::Render::Text::LineBuffer *v158; // [rsp+2B0h] [rbp+1F0h]
  Scaleform::Render::TextLayout::Builder *v159; // [rsp+2B8h] [rbp+1F8h]
  Scaleform::Render::Text::Highlighter *v160; // [rsp+2C0h] [rbp+200h]
  _QWORD *v161; // [rsp+2C8h] [rbp+208h]

  v156 = -2i64;
  v4 = phighlighter;
  v5 = bld;
  v6 = this;
  v7 = 0;
  v8 = this->Geom.FirstVisibleLinePos;
  v121 = v8;
  if ( (_DWORD)v8 )
  {
    v9 = this->Lines.Data.Size;
    if ( v8 < v9 && (v8 & 0x80000000) == 0i64 && v9 )
    {
      v10 = this->Lines.Data.Data;
      v11 = this->Lines.Data.Data[v8];
      v12 = v11->MemSize;
      v13 = (*v10)->MemSize;
      v7 = v11->Data32.OffsetY - (*v10)->Data32.OffsetY;
    }
  }
  LODWORD(v14) = COERCE_UNSIGNED_INT((float)v7) ^ _xmm[0];
  HIDWORD(v122) = COERCE_UNSIGNED_INT((float)v7) ^ _xmm[0];
  v15 = ((unsigned __int8)v6->Geom.Flags >> 2) & 1;
  v114 = ((unsigned __int8)v6->Geom.Flags >> 2) & 1;
  v157 = 0i64;
  if ( phighlighter )
  {
    if ( !phighlighter->HasUnderline )
    {
      phighlighter->HasUnderline = -1;
      v16 = 0i64;
      v17 = phighlighter->Highlighters.Data.Size;
      if ( v17 )
      {
        v18 = &phighlighter->Highlighters.Data.Data->Info.Flags;
        while ( !(*v18 & 7) )
        {
          ++v16;
          v18 += 64;
          if ( v16 >= v17 )
            goto LABEL_14;
        }
        phighlighter->HasUnderline = 1;
      }
    }
  }
LABEL_14:
  v19 = 0;
  v139 = 0i64;
  v20 = 0.0;
  v21 = 0.0;
  v22 = v6->Geom.Flags;
  if ( v22 & 4 || v22 & 0x20 || !Scaleform::Render::Text::LineBuffer::IsPartiallyVisible(v6, v14) )
  {
    v113 = 0;
  }
  else
  {
    v23 = v6->Geom.VisibleRect.y2;
    v24 = v6->Geom.VisibleRect.x2;
    v25 = v6->Geom.VisibleRect.y1;
    v5->ClipBox.x1 = v6->Geom.VisibleRect.x1;
    v5->ClipBox.y1 = v25;
    v5->ClipBox.x2 = v24;
    v5->ClipBox.y2 = v23;
    v113 = 1;
  }
  v26 = FLOAT_20_0;
LABEL_20:
  v154 = (unsigned int)v8;
  if ( (unsigned int)v8 < v6->Lines.Data.Size && (v8 & 0x80000000) == 0i64 )
  {
    if ( !v15 )
    {
      v27 = v6->Lines.Data.Data[(unsigned int)v8];
      v28 = v6->Geom.FirstVisibleLinePos;
      if ( (_DWORD)v8 == v28 )
      {
        v29 = v27->MemSize;
        if ( (float)((float)(v6->Geom.VisibleRect.y2 - v6->Geom.VisibleRect.y1) + v26) < (float)((float)v27->Data32.OffsetY
                                                                                               + v14) )
          goto LABEL_184;
      }
      else
      {
        if ( (unsigned int)v8 <= v28 )
          goto LABEL_184;
        v30 = (v27->MemSize & 0x80000000) == 0 ? v27->Data32.Height : v27->Data8.Height;
        if ( (float)((float)(signed int)(v27->Data32.OffsetY + v30) + v14) > (float)((float)(v6->Geom.VisibleRect.y2
                                                                                           - v6->Geom.VisibleRect.y1)
                                                                                   + v26) )
          goto LABEL_184;
      }
    }
    v31 = v6->Lines.Data.Data[(unsigned int)v8];
    v122 = v31;
    v32 = (float)v31->Data32.OffsetX + v6->Geom.VisibleRect.x1;
    if ( (v31->MemSize & 0x80000000) == 0 )
      v33 = v31->Data32.BaseLineOffset;
    else
      v33 = v31->Data8.BaseLineOffset;
    *(float *)val = (float)((float)v31->Data32.OffsetY + v6->Geom.VisibleRect.y1) + (float)((float)v33 + v14);
    Scaleform::Render::Text::LineBuffer::Line::Begin(v31, &result, v4);
    v34 = 1;
    v111 = 1;
    v35 = 0;
    v153 = 0i64;
    v36 = 0;
    v117 = 0;
    v37 = 0;
    v116 = 0;
    v38 = 0.0;
    v119 = 0.0;
    if ( (v31->MemSize & 0x80000000) == 0 )
      v39 = v31->Data32.Height;
    else
      v39 = v31->Data8.Height;
    if ( (v31->MemSize & 0x80000000) == 0 )
      v40 = v31->Data32.BaseLineOffset;
    else
      v40 = v31->Data8.BaseLineOffset;
    v120 = (float)v39 - (float)v40;
    v41 = result.pGlyphs;
    v42 = SHIDWORD(v153);
    v43 = *((float *)&v153 + 2);
    v44 = SDWORD1(v153);
    v45 = *(float *)&v153;
    while ( 1 )
    {
      if ( !v41 || v41 >= result.pEndGlyphs )
      {
LABEL_160:
        if ( v37 )
        {
          switch ( v36 )
          {
            case 2:
              v101 = 1;
              break;
            case 3:
              v101 = 2;
              break;
            case 4:
              v101 = 3;
              break;
            case 5:
              v101 = 4;
              break;
            case 6:
              v101 = 5;
              break;
            default:
              v101 = 0;
              break;
          }
          v102 = v38 - (float)(signed int)v6->Geom.HScrollOffset;
          *(_WORD *)v123 = 6;
          v124 = v101;
          v125 = v102;
          *(float *)v126 = (float)(v120 * 0.5) + v119;
          v127 = (float)v116;
          LODWORD(v128) = v37;
          v103 = v123;
          v104 = 20;
          v5 = v159;
          do
          {
            Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(&v5->Data, v103++);
            --v104;
          }
          while ( v104 );
        }
        else
        {
          v5 = v159;
        }
        if ( v35 )
        {
          LODWORD(v105) = COERCE_UNSIGNED_INT((float)(signed int)v6->Geom.HScrollOffset) ^ _xmm[0];
          *(_DWORD *)v140 = 5;
          v141 = v35;
          v142 = v45 + v105;
          v143 = v44;
          v144 = v43 + v105;
          v145 = v42;
          v106 = v140;
          v107 = 24;
          do
          {
            Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(&v5->Data, v106++);
            --v107;
          }
          while ( v107 );
        }
        v108 = result.pImage.pObject;
        if ( result.pImage.pObject )
        {
          --result.pImage.pObject->RefCount;
          if ( !v108->RefCount )
            v108->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v108->vfptr, 1u);
        }
        v109 = result.pFontHandle.pObject;
        if ( result.pFontHandle.pObject && !_InterlockedDecrement(&result.pFontHandle.pObject->RefCount) && v109 )
          v109->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v109->vfptr, 1u);
        v14 = *((float *)&v122 + 1);
        LODWORD(v8) = v121;
        v4 = v160;
        v15 = v114;
        if ( v154 < v6->Lines.Data.Size )
          LODWORD(v8) = v121++ + 1;
        goto LABEL_20;
      }
      v46 = &v41->Flags;
      v128 = &v41->Flags;
      v47 = v41->Flags;
      v48 = v41->Advance;
      if ( ((unsigned __int8)v47 >> 6) & 1 )
        v48 = -v48;
      v115 = v48;
      if ( v41->Index >= 0xFFFFu )
        v49 = -1;
      else
        v49 = v41->Index;
      LODWORD(v122) = v49;
      v152 = 0i64;
      f = 0i64;
      v50 = FLOAT_N1_0;
      v51 = result.SelectionColor;
      if ( result.pImage.pObject )
      {
        v152 = result.pImage.pObject;
        v20 = result.pImage.pObject->ScreenWidth;
      }
      else
      {
        v52 = (float)(v41->LenAndFontSize & 0xFFF);
        if ( v47 & 0x10 )
          v52 = v52 * 0.0625;
        v50 = v52 * v26;
        v53 = v50 * 0.0009765625;
        if ( result.pFontHandle.pObject )
          v54 = result.pFontHandle.pObject->pFont.pObject;
        else
          v54 = 0i64;
        f = v54;
        if ( !(v6->Geom.Flags & 4) )
        {
          if ( v49 == -1 )
          {
            v20 = (float)v48 * v53;
          }
          else
          {
            v20 = v53
                * *(float *)(((__int64 (__fastcall *)(Scaleform::Render::Font *, _QWORD, __int128 *))v54->vfptr[7].__vecDelDtor)(
                               v54,
                               v49,
                               &v157)
                           + 8);
            v41 = result.pGlyphs;
          }
        }
        v34 = v111;
      }
      v55 = (float)(signed int)v6->Geom.HScrollOffset;
      v56 = v32 - v55;
      if ( !(v6->Geom.Flags & 4) )
      {
        v55 = v56 + v20;
        if ( (float)(v56 + v20) <= v6->Geom.VisibleRect.x1 )
          goto LABEL_146;
        if ( (signed int)v56 >= (signed int)v6->Geom.VisibleRect.x2 )
        {
          v26 = FLOAT_20_0;
          v20 = 0.0;
          goto LABEL_160;
        }
      }
      v112 = result.UnderlineStyle != 0;
      if ( v34 )
      {
        *(_DWORD *)val = 3;
        v119 = v56;
        LODWORD(v55) = 3;
        LODWORD(v120) = 3;
        v57 = val;
        v58 = 12;
        v59 = &v159->Data;
        do
        {
          Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(v59, v57++);
          --v58;
        }
        while ( v58 );
        v111 = 0;
        v36 = v117;
        v46 = v128;
        v6 = v158;
      }
      if ( (*v46 >> 9) & 1
        || v113
        || (v60 = v6->Geom.Flags, v60 & 4)
        || v60 & 0x20
        || ((v61 = v6->Geom.VisibleRect.x1, v56 >= v61) || (float)(v56 + v20) <= v61)
        && ((v55 = v6->Geom.VisibleRect.x2, v56 >= v55) || (float)(v56 + v20) <= v55) )
      {
        v64 = v159;
      }
      else
      {
        v62 = v6->Geom.VisibleRect.x2;
        v55 = v6->Geom.VisibleRect.y1 + -40.0;
        v63 = v6->Geom.VisibleRect.y2 + 40.0;
        v64 = v159;
        v159->ClipBox.x1 = v61;
        v64->ClipBox.y1 = v55;
        v64->ClipBox.x2 = v62;
        v64->ClipBox.y2 = v63;
        v113 = 1;
      }
      if ( !v152 )
        break;
      v65 = v152->pImage.pObject;
      if ( !v65 )
      {
        id.Id = 135168;
        Scaleform::LogDebugMessage((Scaleform::LogMessageId)&id, "An image in TextLayout is NULL");
        v41 = result.pGlyphs;
LABEL_146:
        v68 = v115;
        goto LABEL_147;
      }
      v66 = (__m128)LODWORD(v152->Matrix.M[0][1]);
      v67 = (__m128)LODWORD(v152->Matrix.M[0][0]);
      v68 = v115;
      v66.m128_f32[0] = (float)(v66.m128_f32[0] * v66.m128_f32[0])
                      + (float)(v152->Matrix.M[1][1] * v152->Matrix.M[1][1]);
      v67.m128_f32[0] = (float)(v67.m128_f32[0] * v67.m128_f32[0])
                      + (float)(v152->Matrix.M[1][0] * v152->Matrix.M[1][0]);
      Scaleform::Render::TextLayout::Builder::AddImage(
        v64,
        v65,
        COERCE_FLOAT(_mm_sqrt_ps(v67)),
        COERCE_FLOAT(_mm_sqrt_ps(v66)),
        v152->BaseLineY,
        (float)v115);
      v41 = result.pGlyphs;
LABEL_147:
      if ( v41 && v41 < result.pEndGlyphs )
      {
        v100 = result.Delta;
        if ( !result.Delta )
        {
          v100 = (unsigned int)v41->LenAndFontSize >> 12;
          result.Delta = (unsigned int)v41->LenAndFontSize >> 12;
        }
        result.pGlyphs = v41 + 1;
        if ( v41[1].LenAndFontSize & 0xF000
          && v100
          && result.HighlighterIter.CurAdjStartPos < result.HighlighterIter.NumGlyphs )
        {
          if ( v100 )
          {
            result.HighlighterIter.CurAdjStartPos += v100;
            Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(&result.HighlighterIter);
          }
          result.Delta = 0;
        }
        Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&result);
        v41 = result.pGlyphs;
      }
      v32 = v32 + (float)v68;
      v26 = FLOAT_20_0;
      v20 = 0.0;
      v6 = v158;
      v34 = v111;
    }
    v69 = result.ColorV;
    if ( result.ColorV != v19 )
    {
      *(_DWORD *)v126 = 1;
      v127 = *(float *)&result.ColorV;
      v70 = v126;
      v71 = 8;
      v72 = &v64->Data;
      do
      {
        Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(v72, v70++);
        --v71;
      }
      while ( v71 );
      v46 = v128;
    }
    v73 = f;
    if ( f != v139 || v50 != v21 )
    {
      Scaleform::Render::TextLayout::Builder::ChangeFont(v159, f, v50, v55);
      Scaleform::Render::TextLayout::Builder::AddRefCntData(
        v159,
        (Scaleform::RefCountImpl *)&result.pFontHandle.pObject->vfptr);
    }
    if ( *((_BYTE *)v46 + 1) & 1 )
    {
      if ( v37 )
      {
        switch ( v117 )
        {
          case 2:
            v81 = 1;
            break;
          case 3:
            v81 = 2;
            break;
          case 4:
            v81 = 3;
            break;
          case 5:
            v81 = 4;
            break;
          case 6:
            v81 = 5;
            break;
          default:
            v81 = 0;
            break;
        }
        *(_WORD *)v133 = 6;
        v134 = v81;
        v135 = v38 - (float)(signed int)v158->Geom.HScrollOffset;
        v136 = (float)(v120 * 0.5) + v119;
        v137 = (float)v116;
        v138 = v37;
        v82 = v133;
        v83 = 20;
        v84 = &v159->Data;
        do
        {
          Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(v84, v82++);
          --v83;
        }
        while ( v83 );
      }
      v116 = 0;
      v76 = 0;
      v75 = *(float *)val;
      v74 = v115;
    }
    else if ( v37 != result.UnderlineColor || v117 != result.UnderlineStyle )
    {
      if ( v37 )
      {
        switch ( v117 )
        {
          case 2:
            v77 = 1;
            break;
          case 3:
            v77 = 2;
            break;
          case 4:
            v77 = 3;
            break;
          case 5:
            v77 = 4;
            break;
          case 6:
            v77 = 5;
            break;
          default:
            v77 = 0;
            break;
        }
        LOWORD(id.Id) = 6;
        HIWORD(id.Id) = v77;
        v130 = v38 - (float)(signed int)v158->Geom.HScrollOffset;
        *(float *)&f = (float)(v120 * 0.5) + v119;
        *((float *)&f + 1) = (float)v116;
        v132 = v37;
        v78 = &id;
        v79 = 20;
        v80 = &v159->Data;
        do
        {
          Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(v80, (const char *)v78);
          v78 = (Scaleform::LogMessageId *)((char *)v78 + 1);
          --v79;
        }
        while ( v79 );
      }
      v38 = v32;
      v75 = *(float *)val;
      v119 = *(float *)val;
      v74 = v115;
      v116 = v115;
      v76 = v112;
    }
    else
    {
      v74 = v115;
      v75 = *(float *)val;
      v76 = v112;
      if ( result.UnderlineColor )
        v116 += v115;
    }
    if ( result.SelectionColor || v35 )
    {
      v85 = Scaleform::Render::Text::LineBuffer::Line::GetHeight(v122);
      v86 = COERCE_UNSIGNED_INT((float)(Scaleform::Render::Text::LineBuffer::Line::GetNonNegLeading(v122) + v85));
      v87 = v75 - Scaleform::Render::Text::LineBuffer::Line::GetAscent(v122);
      v88 = (float)v74 + v32;
      v89 = *(float *)&v86 + v87;
      if ( v51 == v35 )
      {
        if ( !v51 )
          goto LABEL_132;
        if ( v45 > v32 )
          v45 = v32;
        if ( v43 <= v88 )
          v43 = (float)v74 + v32;
        if ( *(float *)&v44 > v87 )
          *(float *)&v44 = v87;
        if ( *(float *)&v42 > v89 )
          goto LABEL_132;
      }
      else
      {
        if ( v35 )
        {
          LODWORD(v90) = COERCE_UNSIGNED_INT((float)(signed int)v158->Geom.HScrollOffset) ^ _xmm[0];
          *(_DWORD *)v146 = 5;
          v147 = v35;
          v148 = v90 + v45;
          v149 = v44;
          v150 = v90 + v43;
          v151 = v42;
          v91 = v146;
          v92 = 24;
          v93 = v159;
          do
          {
            Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(&v93->Data, v91++);
            --v92;
          }
          while ( v92 );
          v74 = v115;
        }
        v45 = v32;
        *(float *)&v44 = v87;
        v43 = v88;
      }
      *(float *)&v42 = v89;
    }
LABEL_132:
    if ( result.pFontHandle.pObject )
    {
      v94 = result.pFontHandle.pObject->OverridenFontFlags & 1;
      v95 = (result.pFontHandle.pObject->OverridenFontFlags >> 1) & 1;
    }
    else
    {
      v94 = 0;
      v95 = 0;
    }
    v96 = 0;
    if ( (*v128 >> 9) & 1 )
      v96 = 1;
    if ( v95 )
      v96 |= 2u;
    if ( v94 )
      v96 |= 4u;
    v123[0] = 0;
    v123[1] = v96;
    v124 = (signed __int16)v122;
    v125 = (float)v74;
    v97 = v123;
    v98 = 8;
    v99 = &v159->Data;
    do
    {
      Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(v99, v97++);
      --v98;
    }
    while ( v98 );
    v19 = v69;
    v139 = v73;
    v21 = v50;
    v35 = v51;
    v41 = result.pGlyphs;
    v68 = v115;
    if ( v76 )
    {
      v37 = result.UnderlineColor;
      v36 = result.UnderlineStyle;
      v117 = result.UnderlineStyle;
    }
    else
    {
      v37 = 0;
      v36 = 0;
      v117 = 0;
    }
    goto LABEL_147;
  }
LABEL_184:
  v110 = v161;
  v5->Param.TextParam.pFont = (Scaleform::Render::FontCacheHandle *)*v161;
  *(_QWORD *)&v5->Param.TextParam.GlyphIndex = v110[1];
  *(_QWORD *)&v5->Param.TextParam.BlurY = v110[2];
  v5->Param.ShadowParam.pFont = (Scaleform::Render::FontCacheHandle *)v110[3];
  *(_QWORD *)&v5->Param.ShadowParam.GlyphIndex = v110[4];
  *(_QWORD *)&v5->Param.ShadowParam.BlurY = v110[5];
  *(_QWORD *)&v5->Param.ShadowColor = v110[6];
  *(_QWORD *)&v5->Param.ShadowOffsetY = v110[7];
}

// File Line: 795
// RVA: 0x979680
Scaleform::Render::Text::FontHandle *__fastcall Scaleform::Render::Text::LineBuffer::FindFirstFontInfo(Scaleform::Render::Text::LineBuffer *this)
{
  Scaleform::Render::Text::LineBuffer *v1; // r14
  unsigned __int64 v2; // rdi
  unsigned __int64 v3; // rsi
  unsigned int v4; // eax
  Scaleform::Render::Text::ImageDesc *v5; // rcx
  Scaleform::Render::Text::FontHandle *v6; // rcx
  Scaleform::Render::Text::FontHandle *v7; // rdi
  Scaleform::Render::Text::ImageDesc *v8; // rcx
  Scaleform::Render::Text::FontHandle *v9; // rcx
  Scaleform::Render::Text::LineBuffer::GlyphIterator result; // [rsp+30h] [rbp-B8h]

  v1 = this;
  v2 = 0i64;
  v3 = this->Lines.Data.Size;
  if ( v3 )
  {
    do
    {
      Scaleform::Render::Text::LineBuffer::Line::Begin(v1->Lines.Data.Data[v2], &result);
      while ( result.pGlyphs && result.pGlyphs < result.pEndGlyphs )
      {
        if ( (result.pGlyphs->Flags >> 13) & 1 )
        {
          v7 = result.pFontHandle.pObject;
          v8 = result.pImage.pObject;
          if ( result.pImage.pObject )
          {
            --result.pImage.pObject->RefCount;
            if ( !v8->RefCount )
              v8->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v8->vfptr, 1u);
          }
          v9 = result.pFontHandle.pObject;
          if ( result.pFontHandle.pObject && !_InterlockedDecrement(&result.pFontHandle.pObject->RefCount) && v9 )
            v9->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, 1u);
          return v7;
        }
        v4 = result.Delta;
        if ( !result.Delta )
        {
          v4 = (unsigned int)result.pGlyphs->LenAndFontSize >> 12;
          result.Delta = (unsigned int)result.pGlyphs->LenAndFontSize >> 12;
        }
        ++result.pGlyphs;
        if ( result.pGlyphs->LenAndFontSize & 0xF000
          && v4
          && result.HighlighterIter.CurAdjStartPos < result.HighlighterIter.NumGlyphs )
        {
          if ( v4 )
          {
            result.HighlighterIter.CurAdjStartPos += v4;
            Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(&result.HighlighterIter);
          }
          result.Delta = 0;
        }
        Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&result);
      }
      v5 = result.pImage.pObject;
      if ( result.pImage.pObject )
      {
        --result.pImage.pObject->RefCount;
        if ( !v5->RefCount )
          v5->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, 1u);
      }
      v6 = result.pFontHandle.pObject;
      if ( result.pFontHandle.pObject && !_InterlockedDecrement(&result.pFontHandle.pObject->RefCount) && v6 )
        v6->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, 1u);
      ++v2;
    }
    while ( v2 < v3 );
  }
  return 0i64;
}

// File Line: 813
// RVA: 0x998B60
void __fastcall Scaleform::Render::Text::LoadTextFieldParamFromTextFilter(Scaleform::Render::TextFieldParam *params, Scaleform::Render::Text::TextFilter *filter)
{
  params->TextParam.BlurX = (signed int)(float)((float)(filter->BlurX * 16.0) + 0.5);
  params->TextParam.BlurY = (signed int)(float)((float)(filter->BlurY * 16.0) + 0.5);
  params->TextParam.Flags = 128;
  params->TextParam.BlurStrength = (signed int)(float)((float)(filter->BlurStrength * 16.0) + 0.5);
  if ( !(filter->ShadowFlags & 1) )
  {
    params->ShadowParam.Flags = filter->ShadowFlags & 0xFFFE;
    params->ShadowParam.BlurX = (signed int)(float)((float)(filter->ShadowParams.BlurX * 16.0) + 0.5);
    params->ShadowParam.BlurY = (signed int)(float)((float)(filter->ShadowParams.BlurX * 16.0) + 0.5);
    params->ShadowParam.BlurStrength = (signed int)(float)((float)(filter->ShadowParams.Strength * 16.0) + 0.5);
    params->ShadowColor = filter->ShadowParams.Colors[0].Raw;
    params->ShadowOffsetX = filter->ShadowParams.Offset.x;
    params->ShadowOffsetY = filter->ShadowParams.Offset.y;
  }
}

