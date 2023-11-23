// File Line: 27
// RVA: 0x896080
void __fastcall Scaleform::GFx::Text::EditorKit::EditorKit(
        Scaleform::GFx::Text::EditorKit *this,
        Scaleform::GFx::Resource *pdocview)
{
  Scaleform::Render::RenderBuffer *vfptr; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,74>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Text::EditorKitBase,74>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::EditorKitBase::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Text::EditorKit::`vftable;
  if ( pdocview )
    Scaleform::Render::RenderBuffer::AddRef(pdocview);
  this->pDocView.pObject = (Scaleform::Render::Text::DocView *)pdocview;
  this->pClipboard.pObject = 0i64;
  this->pKeyMap.pObject = 0i64;
  this->pRestrict.pObject = 0i64;
  this->pRestrict.Owner = 1;
  this->CursorRect.FormatCounter = 0;
  this->Flags = 0;
  this->CursorTimer = 0.0;
  this->CursorPos = 0i64;
  this->CursorColor.Raw = -16777216;
  this->LastAdvanceTime = 0.0;
  this->LastHorizCursorPos = -1.0;
  this->LastClickTime = 0;
  *(_QWORD *)&this->CursorRect.Value.x1 = 0i64;
  *(_QWORD *)&this->CursorRect.Value.x2 = 0i64;
  *(_QWORD *)&this->ActiveSelectionBkColor = -16777216i64;
  *(_QWORD *)&this->InactiveSelectionBkColor = -8355712i64;
  Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)this);
  vfptr = (Scaleform::Render::RenderBuffer *)pdocview[9].vfptr;
  if ( vfptr )
    Scaleform::RefCountImpl::Release(vfptr);
  pdocview[9].vfptr = (Scaleform::GFx::ResourceVtbl *)this;
}

// File Line: 44
// RVA: 0x8A4290
void __fastcall Scaleform::GFx::Text::EditorKit::~EditorKit(Scaleform::GFx::Text::EditorKit *this)
{
  Scaleform::GFx::Text::EditorKit::RestrictParams *pObject; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::Render::RenderBuffer *v4; // rcx
  Scaleform::Render::RenderBuffer *v5; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Text::EditorKit::`vftable;
  pObject = this->pRestrict.pObject;
  if ( pObject )
  {
    if ( this->pRestrict.Owner )
    {
      this->pRestrict.Owner = 0;
      Scaleform::GFx::Text::EditorKit::RestrictParams::`scalar deleting destructor(pObject, 1u);
    }
    this->pRestrict.pObject = 0i64;
  }
  this->pRestrict.Owner = 0;
  v3 = (Scaleform::Render::RenderBuffer *)this->pKeyMap.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v4 = (Scaleform::Render::RenderBuffer *)this->pClipboard.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v5 = (Scaleform::Render::RenderBuffer *)this->pDocView.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::EditorKitBase::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 48
// RVA: 0x906AB0
void __fastcall Scaleform::GFx::Text::EditorKit::SetCursorPos(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned __int64 pos,
        bool selectionAllowed)
{
  unsigned __int64 v4; // rdi
  unsigned __int64 Length; // rax
  Scaleform::Render::Text::DocView *pObject; // rax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *GlyphEntryAtIndex; // rax
  unsigned __int16 LenAndFontSize; // cx
  unsigned __int16 Flags; // cx
  Scaleform::Render::Text::DocView *v11; // rcx
  unsigned __int64 CursorPos; // r8
  unsigned __int64 BeginSelection; // rdx
  Scaleform::Render::Text::DocView::DocumentListener *v14; // rcx
  unsigned __int64 ptextPos; // [rsp+30h] [rbp+8h] BYREF

  v4 = pos;
  if ( pos != -1i64 )
  {
    Length = Scaleform::Render::Text::StyledText::GetLength(this->pDocView.pObject->pDocument.pObject);
    if ( v4 > Length )
      v4 = Length;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Text::EditorKit *))this->vfptr[2].__vecDelDtor)(this) )
      this->Flags &= ~8u;
    else
      this->Flags |= 8u;
    pObject = this->pDocView.pObject;
    this->CursorTimer = 0.0;
    if ( pObject->pImageSubstitutor )
    {
      GlyphEntryAtIndex = Scaleform::GFx::Text::EditorKit::GetGlyphEntryAtIndex(this, v4, &ptextPos);
      if ( GlyphEntryAtIndex )
      {
        LenAndFontSize = GlyphEntryAtIndex->LenAndFontSize;
        if ( (LenAndFontSize & 0xF000) != 4096 && ptextPos != v4 )
        {
          if ( v4 < this->CursorPos )
            v4 = ptextPos;
          else
            v4 = ptextPos + ((unsigned __int64)LenAndFontSize >> 12);
        }
      }
    }
  }
  this->CursorPos = v4;
  --this->CursorRect.FormatCounter;
  this->LastHorizCursorPos = -1.0;
  if ( v4 != -1i64 )
  {
    Scaleform::GFx::Text::EditorKit::ScrollToPosition(this, v4, 1, this->Flags & 0x100);
    Scaleform::Render::Text::DocView::SetDefaultTextAndParaFormat(this->pDocView.pObject, this->CursorPos);
  }
  Flags = this->Flags;
  if ( (Flags & 2) != 0 )
  {
    if ( selectionAllowed && ((Flags & 0x40) != 0 || (Flags & 0x20) != 0) )
    {
      v11 = this->pDocView.pObject;
      CursorPos = this->CursorPos;
      BeginSelection = v11->BeginSelection;
    }
    else
    {
      BeginSelection = this->CursorPos;
      v11 = this->pDocView.pObject;
      CursorPos = BeginSelection;
    }
    Scaleform::Render::Text::DocView::SetSelection(v11, BeginSelection, CursorPos, 1);
  }
  v14 = this->pDocView.pObject->pDocumentListener.pObject;
  if ( v14 )
    v14->vfptr[10].__vecDelDtor(v14, (unsigned int)this);
}

// File Line: 120
// RVA: 0x8B41A0
void __fastcall Scaleform::GFx::Text::EditorKit::Advance(Scaleform::GFx::Text::EditorKit *this, long double timer)
{
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  double v3; // xmm6_8
  double v5; // xmm6_8
  unsigned __int16 Flags; // cx
  unsigned __int16 v7; // cx
  Scaleform::Render::Text::DocView *pObject; // rax
  Scaleform::Render::Text::DocView::DocumentListener *v9; // rcx
  float y; // xmm6_4
  Scaleform::Render::Rect<float> *ViewRect; // rax
  Scaleform::Render::Text::DocView *v12; // rcx
  unsigned int FirstVisibleLinePos; // edx
  unsigned __int64 v14; // rax
  unsigned int v15; // edi
  unsigned __int64 CursorPosInLine; // rax

  vfptr = this->vfptr;
  v3 = timer - this->LastAdvanceTime;
  this->LastAdvanceTime = timer;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Text::EditorKit *))vfptr[2].__vecDelDtor)(this) )
  {
    v5 = v3 + this->CursorTimer;
    if ( v5 <= 0.5 )
    {
      this->CursorTimer = v5;
    }
    else
    {
      Flags = this->Flags;
      if ( (Flags & 0x10) == 0 )
      {
        v7 = (Flags & 8) != 0 ? Flags & 0xFFF7 : Flags | 8;
        pObject = this->pDocView.pObject;
        this->Flags = v7;
        v9 = pObject->pDocumentListener.pObject;
        if ( v9 )
          ((void (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::GFx::Text::EditorKit *, bool))v9->vfptr[11].__vecDelDtor)(
            v9,
            this,
            (this->Flags & 8) != 0);
      }
      this->CursorTimer = 0.0;
      this->Flags &= ~0x10u;
    }
  }
  if ( (this->Flags & 0x20) != 0 )
  {
    y = this->LastMousePos.y;
    ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocView.pObject);
    v12 = this->pDocView.pObject;
    if ( y > ViewRect->y1 )
    {
      if ( Scaleform::Render::Text::DocView::GetViewRect(v12)->y2 <= this->LastMousePos.y )
      {
        v15 = Scaleform::Render::Text::DocView::GetBottomVScroll(this->pDocView.pObject) + 1;
        if ( v15 < Scaleform::Render::Text::DocView::GetLinesCount(this->pDocView.pObject) )
        {
          CursorPosInLine = Scaleform::Render::Text::DocView::GetCursorPosInLine(
                              this->pDocView.pObject,
                              v15,
                              this->LastMousePos.y);
          if ( CursorPosInLine != this->CursorPos )
            Scaleform::GFx::Text::EditorKit::SetCursorPos(this, CursorPosInLine, (this->Flags & 2) != 0);
        }
      }
    }
    else
    {
      FirstVisibleLinePos = v12->mLineBuffer.Geom.FirstVisibleLinePos;
      if ( FirstVisibleLinePos )
      {
        v14 = Scaleform::Render::Text::DocView::GetCursorPosInLine(v12, FirstVisibleLinePos - 1, y);
        if ( v14 != this->CursorPos )
          Scaleform::GFx::Text::EditorKit::SetCursorPos(this, v14, (this->Flags & 2) != 0);
      }
    }
  }
}

// File Line: 184
// RVA: 0x8B89A0
char __fastcall Scaleform::GFx::Text::EditorKit::CalcCursorRectInLineBuffer(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned __int64 charIndex,
        Scaleform::Render::Rect<float> *pcursorRect,
        unsigned int *plineIndex,
        unsigned int *pglyphIndex,
        bool avoidComposStr,
        Scaleform::Render::Text::LineBuffer::Line::Alignment *plineAlignment)
{
  unsigned int LineIndexOfChar; // eax
  unsigned int v11; // r13d
  Scaleform::Render::Text::LineBuffer::Line *v12; // rsi
  __int64 TextPos; // rax
  unsigned __int64 v14; // r15
  unsigned int v15; // ebp
  int v16; // edi
  unsigned int i; // ebx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pEndGlyphs; // rdx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // rcx
  unsigned __int16 Flags; // r8
  int Advance; // eax
  unsigned int *v22; // r14
  unsigned __int16 v23; // dx
  int v24; // eax
  float v25; // xmm3_4
  int v26; // eax
  float v27; // xmm1_4
  float OffsetY; // xmm2_4
  int Height; // eax
  Scaleform::Render::Text::LineBuffer::GlyphIterator result; // [rsp+30h] [rbp-C8h] BYREF

  Scaleform::Render::Text::DocView::ForceReformat(this->pDocView.pObject);
  LineIndexOfChar = Scaleform::Render::Text::DocView::GetLineIndexOfChar(this->pDocView.pObject, charIndex);
  v11 = LineIndexOfChar;
  if ( LineIndexOfChar == -1 )
    return 0;
  v12 = this->pDocView.pObject->mLineBuffer.Lines.Data.Data[LineIndexOfChar];
  if ( plineAlignment )
    *plineAlignment = (v12->MemSize >> 27) & 3;
  if ( (v12->MemSize & 0x80000000) == 0 )
  {
    TextPos = v12->Data32.TextPos;
  }
  else
  {
    TextPos = v12->Data32.TextPos & 0xFFFFFF;
    if ( (_DWORD)TextPos == 0xFFFFFF )
      TextPos = 0xFFFFFFFFi64;
  }
  v14 = charIndex - TextPos;
  v15 = 0;
  v16 = 0;
  Scaleform::Render::Text::LineBuffer::Line::Begin(v12, &result);
  for ( i = 0; ; ++i )
  {
    pEndGlyphs = result.pEndGlyphs;
    pGlyphs = result.pGlyphs;
    if ( !result.pGlyphs )
      break;
    if ( result.pGlyphs >= result.pEndGlyphs )
      break;
    if ( (result.pGlyphs->LenAndFontSize & 0xF000) != 0 )
      break;
    Flags = result.pGlyphs->Flags;
    if ( (Flags & 0x100) != 0 )
      break;
    Advance = result.pGlyphs->Advance;
    if ( (Flags & 0x40) != 0 )
      Advance = -Advance;
    v16 += Advance;
    Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&result);
  }
  v22 = plineIndex;
  if ( v14 )
  {
    do
    {
      if ( !pGlyphs || pGlyphs >= pEndGlyphs )
        break;
      v23 = pGlyphs->Flags;
      v24 = pGlyphs->Advance;
      if ( (v23 & 0x40) != 0 )
        v24 = -v24;
      v16 += v24;
      if ( !avoidComposStr || (v23 & 4) == 0 )
        v15 += pGlyphs->LenAndFontSize >> 12;
      ++i;
      Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&result);
      pEndGlyphs = result.pEndGlyphs;
      pGlyphs = result.pGlyphs;
    }
    while ( v15 < v14 );
    v22 = plineIndex;
  }
  v25 = 0.0;
  if ( pGlyphs && pGlyphs < pEndGlyphs )
  {
    v26 = pGlyphs->Advance;
    if ( (pGlyphs->Flags & 0x40) != 0 )
      v26 = -v26;
    v25 = (float)v26;
  }
  v27 = (float)v12->Data32.OffsetX + (float)v16;
  pcursorRect->x1 = v27;
  OffsetY = (float)v12->Data32.OffsetY;
  pcursorRect->y1 = OffsetY;
  pcursorRect->x2 = v27 + v25;
  if ( (v12->MemSize & 0x80000000) == 0 )
    Height = v12->Data32.Height;
  else
    Height = v12->Data8.Height;
  pcursorRect->y2 = (float)Height + OffsetY;
  if ( v22 )
    *v22 = v11;
  if ( pglyphIndex )
    *pglyphIndex = i;
  if ( result.pImage.pObject )
    Scaleform::RefCountNTSImpl::Release(result.pImage.pObject);
  if ( result.pFontHandle.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pFontHandle.pObject);
  return 1;
}

// File Line: 242
// RVA: 0x8B8C10
__int64 __fastcall Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned __int64 charIndex,
        Scaleform::Render::Rect<float> *pcursorRect,
        unsigned int *plineIndex,
        unsigned int *pglyphIndex,
        bool avoidComposStr,
        Scaleform::Render::Text::LineBuffer::Line::Alignment *plineAlignment)
{
  unsigned __int8 v9; // si
  Scaleform::Render::Text::DocView *pObject; // rcx
  int HScrollOffset; // ebx
  int VScrollOffsetInFixp; // eax
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  Scaleform::Render::Rect<float> *ViewRect; // rax
  Scaleform::Render::Text::DocView *v20; // rcx
  float v21; // xmm6_4
  float v22; // xmm5_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float x1; // xmm0_4
  float y1; // xmm2_4

  v9 = Scaleform::GFx::Text::EditorKit::CalcCursorRectInLineBuffer(
         this,
         charIndex,
         pcursorRect,
         plineIndex,
         pglyphIndex,
         avoidComposStr,
         plineAlignment);
  if ( v9 )
  {
    pObject = this->pDocView.pObject;
    HScrollOffset = pObject->mLineBuffer.Geom.HScrollOffset;
    VScrollOffsetInFixp = Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(&pObject->mLineBuffer);
    LODWORD(v13) = COERCE_UNSIGNED_INT((float)HScrollOffset) ^ _xmm[0];
    v14 = v13 + pcursorRect->x1;
    v15 = v13 + pcursorRect->x2;
    LODWORD(v16) = COERCE_UNSIGNED_INT((float)VScrollOffsetInFixp) ^ _xmm[0];
    pcursorRect->x1 = v14;
    pcursorRect->x2 = v15;
    v17 = v16 + pcursorRect->y1;
    v18 = v16 + pcursorRect->y2;
    pcursorRect->y1 = v17;
    pcursorRect->y2 = v18;
    ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocView.pObject);
    v20 = this->pDocView.pObject;
    v21 = (float)(v20->mLineBuffer.Geom.VisibleRect.y1 - ViewRect->y1) + pcursorRect->y1;
    v22 = (float)(v20->mLineBuffer.Geom.VisibleRect.x1 - ViewRect->x1) + pcursorRect->x1;
    pcursorRect->y1 = v21;
    pcursorRect->x1 = v22;
    v23 = (float)(this->pDocView.pObject->mLineBuffer.Geom.VisibleRect.x1 - ViewRect->x1) + pcursorRect->x2;
    v24 = (float)(this->pDocView.pObject->mLineBuffer.Geom.VisibleRect.y1 - ViewRect->y1) + pcursorRect->y2;
    pcursorRect->y2 = v24;
    pcursorRect->x2 = v23;
    x1 = ViewRect->x1;
    y1 = ViewRect->y1;
    pcursorRect->x1 = ViewRect->x1 + v22;
    pcursorRect->y1 = v21 + y1;
    pcursorRect->x2 = x1 + v23;
    pcursorRect->y2 = v24 + y1;
  }
  return v9;
}

// File Line: 257
// RVA: 0x8D9520
Scaleform::Render::Text::LineBuffer::GlyphEntry *__fastcall Scaleform::GFx::Text::EditorKit::GetGlyphEntryAtIndex(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned __int64 charIndex,
        unsigned __int64 *ptextPos)
{
  unsigned int LineIndexOfChar; // eax
  Scaleform::Render::Text::LineBuffer::Line *Line; // rax
  unsigned int TextPos; // edi
  unsigned __int64 v9; // r14
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v10; // rbp
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pEndGlyphs; // rcx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // rax
  int v13; // ebx
  unsigned int v14; // esi
  Scaleform::Render::Text::LineBuffer::GlyphIterator result; // [rsp+30h] [rbp-B8h] BYREF

  LineIndexOfChar = Scaleform::Render::Text::DocView::GetLineIndexOfChar(this->pDocView.pObject, charIndex);
  if ( LineIndexOfChar == -1 )
    return 0i64;
  Line = Scaleform::Render::Text::LineBuffer::GetLine(&this->pDocView.pObject->mLineBuffer, LineIndexOfChar);
  if ( !Line )
    return 0i64;
  TextPos = Line->Data32.TextPos;
  if ( (Line->MemSize & 0x80000000) != 0 )
  {
    TextPos &= 0xFFFFFFu;
    if ( TextPos == 0xFFFFFF )
      TextPos = -1;
  }
  v9 = charIndex - TextPos;
  Scaleform::Render::Text::LineBuffer::Line::Begin(Line, &result);
  v10 = 0i64;
  while ( 1 )
  {
    pEndGlyphs = result.pEndGlyphs;
    pGlyphs = result.pGlyphs;
    if ( !result.pGlyphs
      || result.pGlyphs >= result.pEndGlyphs
      || (result.pGlyphs->LenAndFontSize & 0xF000) != 0
      || (result.pGlyphs->Flags & 0x100) != 0 )
    {
      break;
    }
    Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&result);
  }
  v13 = 0;
  v14 = 0;
  while ( 1 )
  {
    TextPos += v13;
    if ( !pGlyphs )
      break;
    if ( pGlyphs >= pEndGlyphs )
      break;
    v10 = pGlyphs;
    v13 = pGlyphs->LenAndFontSize >> 12;
    v14 += v13;
    Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&result);
    if ( v14 > v9 )
      break;
    pEndGlyphs = result.pEndGlyphs;
    pGlyphs = result.pGlyphs;
  }
  if ( ptextPos )
    *ptextPos = TextPos;
  if ( result.pImage.pObject )
    Scaleform::RefCountNTSImpl::Release(result.pImage.pObject);
  if ( result.pFontHandle.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pFontHandle.pObject);
  return v10;
}

// File Line: 297
// RVA: 0x919090
void __fastcall Scaleform::GFx::Text::EditorKit::UpdateWideCursor(Scaleform::GFx::Text::EditorKit *this)
{
  Scaleform::Render::Text::Highlighter *HighlighterManager; // rdi
  Scaleform::Render::Text::HighlightDesc *HighlighterPtr; // rax
  Scaleform::Render::Text::HighlightDesc *v4; // rdx
  bool v5; // r8
  unsigned __int64 CursorPos; // rcx
  Scaleform::Render::Text::HighlightDesc desc; // [rsp+20h] [rbp-48h] BYREF

  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Text::EditorKit *))this->vfptr[2].__vecDelDtor)(this)
    && (this->Flags & 0x100) != 0 )
  {
    HighlighterManager = Scaleform::Render::Text::DocView::CreateHighlighterManager(this->pDocView.pObject);
    HighlighterPtr = Scaleform::Render::Text::Highlighter::GetHighlighterPtr(HighlighterManager, 0x7FFFFFFEu);
    v4 = HighlighterPtr;
    if ( HighlighterPtr )
    {
      v5 = HighlighterPtr->Length != 0;
    }
    else
    {
      desc.Info.UnderlineColor.Raw = 0;
      memset(&desc, 0, 40);
      desc.Id = 2147483646;
      *(_QWORD *)&desc.Info.BackgroundColor.Channels.Blue = -16777216i64;
      desc.Info.Flags = 24;
      v4 = Scaleform::Render::Text::Highlighter::CreateHighlighter(HighlighterManager, &desc);
      v5 = 0;
    }
    CursorPos = this->CursorPos;
    if ( v4->StartPos != CursorPos || v5 != ((this->Flags & 8) != 0) )
    {
      v4->StartPos = CursorPos;
      v4->Length = (this->Flags >> 3) & 1;
      Scaleform::Render::Text::DocView::UpdateHighlight(this->pDocView.pObject, v4);
    }
  }
}

// File Line: 350
// RVA: 0x8B0780
void __fastcall Scaleform::GFx::Text::EditorKit::AddDrawCursorInfo(
        Scaleform::GFx::Text::EditorKit *this,
        Scaleform::Render::TextLayout::Builder *bld)
{
  unsigned __int16 Flags; // cx
  unsigned int LineIndexOfChar; // esi
  unsigned __int16 FormatCounter; // cx
  unsigned __int64 CursorPos; // rdx
  float x1; // xmm6_4
  float v9; // xmm7_4
  Scaleform::Render::Text::TextFormat *pObject; // rax
  Scaleform::Render::Text::DocView::HighlightDescLoc *pHighlight; // rcx
  float y1; // xmm0_4
  float y2; // xmm1_4
  unsigned __int16 v14; // cx
  float v15; // xmm1_4
  Scaleform::Render::Text::DocView *v16; // rdi
  float x2; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm6_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm2_4
  float v26; // xmm5_4
  bool IsLineVisible; // al
  unsigned int Raw; // r8d
  Scaleform::Render::Rect<float> r; // [rsp+40h] [rbp-59h] BYREF
  Scaleform::Render::Rect<float> pcursorRect; // [rsp+50h] [rbp-49h] BYREF
  Scaleform::Render::Text::HighlighterPosIterator result; // [rsp+60h] [rbp-39h] BYREF
  unsigned int plineIndex; // [rsp+100h] [rbp+67h] BYREF
  unsigned int pglyphIndex; // [rsp+110h] [rbp+77h] BYREF

  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Text::EditorKit *))this->vfptr[2].__vecDelDtor)(this) )
  {
    Flags = this->Flags;
    if ( (Flags & 0x400) != 0 )
    {
      if ( (Flags & 0x100) != 0 )
      {
        Scaleform::GFx::Text::EditorKit::UpdateWideCursor(this);
      }
      else if ( (Flags & 8) != 0 )
      {
        LineIndexOfChar = -1;
        FormatCounter = this->pDocView.pObject->FormatCounter;
        plineIndex = -1;
        if ( this->CursorRect.FormatCounter != FormatCounter )
        {
          CursorPos = this->CursorPos;
          pcursorRect = 0i64;
          if ( Scaleform::GFx::Text::EditorKit::CalcCursorRectInLineBuffer(
                 this,
                 CursorPos,
                 &pcursorRect,
                 &plineIndex,
                 &pglyphIndex,
                 0,
                 0i64) )
          {
            x1 = pcursorRect.x1;
            v9 = pcursorRect.x1;
            pObject = this->pDocView.pObject->pDocument.pObject->pDefaultTextFormat.pObject;
            if ( pObject && (pObject->PresentMask & 1) != 0 )
              this->CursorColor.Raw = pObject->ColorV;
            pHighlight = this->pDocView.pObject->pHighlight;
            if ( pHighlight )
            {
              Scaleform::Render::Text::Highlighter::GetPosIterator(
                &pHighlight->HighlightManager,
                &result,
                this->CursorPos,
                0xFFFFFFFFFFFFFFFFui64);
              if ( (result.CurDesc.Info.Flags & 0x10) != 0 )
                this->CursorColor.Raw = result.CurDesc.Info.TextColor.Raw;
            }
          }
          else
          {
            pcursorRect = 0i64;
            v9 = 0.0;
            x1 = 0.0;
          }
          y1 = pcursorRect.y1;
          y2 = pcursorRect.y2;
          LineIndexOfChar = plineIndex;
          v14 = this->pDocView.pObject->FormatCounter;
          this->CursorRect.Value.x2 = v9;
          this->CursorRect.Value.x1 = x1;
          this->CursorRect.Value.y1 = y1;
          this->CursorRect.Value.y2 = y2;
          this->CursorRect.FormatCounter = v14;
        }
        v15 = this->CursorRect.Value.y1;
        v16 = this->pDocView.pObject;
        r.x1 = this->CursorRect.Value.x1;
        x2 = this->CursorRect.Value.x2;
        r.y1 = v15;
        v18 = this->CursorRect.Value.y2;
        r.x2 = x2;
        r.y2 = v18;
        LODWORD(v19) = COERCE_UNSIGNED_INT((float)(int)v16->mLineBuffer.Geom.HScrollOffset) ^ _xmm[0];
        r.x1 = r.x1 + v19;
        r.x2 = x2 + v19;
        LODWORD(v20) = COERCE_UNSIGNED_INT((float)(int)Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(&v16->mLineBuffer)) ^ _xmm[0];
        r.y1 = r.y1 + v20;
        r.y2 = r.y2 + v20;
        v21 = v16->mLineBuffer.Geom.VisibleRect.y1;
        v22 = v16->mLineBuffer.Geom.VisibleRect.x1;
        v23 = r.y2 + v21;
        v24 = r.y1 + v21;
        v25 = r.x1 + v22;
        v26 = r.x2 + v22;
        r.y1 = r.y1 + v21;
        r.x1 = r.x1 + v22;
        r.x2 = r.x2 + v22;
        r.y2 = v23;
        if ( v23 > v16->mLineBuffer.Geom.VisibleRect.y2 )
        {
          if ( LineIndexOfChar == -1 )
            LineIndexOfChar = Scaleform::Render::Text::DocView::GetLineIndexOfChar(
                                this->pDocView.pObject,
                                this->CursorPos);
          IsLineVisible = Scaleform::Render::Text::LineBuffer::IsLineVisible(
                            &this->pDocView.pObject->mLineBuffer,
                            LineIndexOfChar);
          v26 = r.x2;
          v24 = r.y1;
          v25 = r.x1;
          if ( IsLineVisible )
          {
            v23 = v16->mLineBuffer.Geom.VisibleRect.y2;
            r.y2 = v23;
          }
          else
          {
            v23 = r.y2;
          }
        }
        if ( v26 <= v16->mLineBuffer.Geom.VisibleRect.x2
          && v23 <= v16->mLineBuffer.Geom.VisibleRect.y2
          && v25 >= v16->mLineBuffer.Geom.VisibleRect.x1
          && v24 >= v16->mLineBuffer.Geom.VisibleRect.y1 )
        {
          Raw = this->CursorColor.Raw;
          r.x2 = v25 + 20.0;
          Scaleform::Render::TextLayout::Builder::AddCursor(bld, &r, Raw);
        }
      }
    }
  }
}

// File Line: 438
// RVA: 0x901150
void __fastcall Scaleform::GFx::Text::EditorKit::ResetBlink(
        Scaleform::GFx::Text::EditorKit *this,
        bool state,
        bool blocked)
{
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Text::EditorKit *))this->vfptr[2].__vecDelDtor)(this) || !state )
    this->Flags &= ~8u;
  else
    this->Flags |= 8u;
  this->CursorTimer = 0.0;
  if ( blocked )
    this->Flags |= 0x10u;
}

// File Line: 460
// RVA: 0x904840
bool __fastcall Scaleform::GFx::Text::EditorKit::ScrollToPosition(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned __int64 pos,
        bool avoidComposStr,
        bool wideCursor)
{
  bool v7; // di
  Scaleform::Render::Text::DocView *pObject; // rcx
  float x1; // xmm1_4
  float v10; // xmm2_4
  float x2; // xmm3_4
  signed int HScrollOffset; // ebx
  int v13; // edx
  signed int v14; // ebp
  bool v15; // sf
  float v16; // xmm0_4
  Scaleform::Render::Text::DocView *v17; // rcx
  Scaleform::Render::Text::DocView *v18; // rcx
  unsigned int v19; // ebx
  int v21; // [rsp+40h] [rbp-38h] BYREF
  unsigned int vscroll[3]; // [rsp+44h] [rbp-34h] BYREF
  Scaleform::Render::Rect<float> pCharRect; // [rsp+50h] [rbp-28h] BYREF

  pCharRect = 0i64;
  v7 = 0;
  if ( !(unsigned __int8)Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(
                           this,
                           pos,
                           &pCharRect,
                           vscroll,
                           0i64,
                           avoidComposStr,
                           (Scaleform::Render::Text::LineBuffer::Line::Alignment *)&v21) )
    return v7;
  pObject = this->pDocView.pObject;
  x1 = pCharRect.x1;
  v10 = wideCursor ? pCharRect.x2 : pCharRect.x1 + 20.0;
  x2 = pObject->mLineBuffer.Geom.VisibleRect.x2;
  if ( x2 >= v10
    && pCharRect.y2 <= pObject->mLineBuffer.Geom.VisibleRect.y2
    && pCharRect.x1 >= pObject->mLineBuffer.Geom.VisibleRect.x1
    && pCharRect.y1 >= pObject->mLineBuffer.Geom.VisibleRect.y1 )
  {
    return v7;
  }
  if ( (pObject->AlignProps & 0x30) != 0 || (pObject->Flags & 1) != 0 )
    return v7;
  HScrollOffset = pObject->mLineBuffer.Geom.HScrollOffset;
  v13 = 1200;
  if ( v21 )
    v13 = 0;
  v14 = pObject->mLineBuffer.Geom.HScrollOffset;
  if ( v10 <= x2 )
  {
    v16 = pObject->mLineBuffer.Geom.VisibleRect.x1;
    if ( pCharRect.x1 >= v16 )
      goto LABEL_23;
    HScrollOffset -= v13 + (int)(float)(v16 - pCharRect.x1);
    v15 = HScrollOffset < 0;
  }
  else
  {
    pCharRect = 0i64;
    HScrollOffset += (int)(float)((float)(x1 - x2) + (float)v13);
    if ( pos
      && Scaleform::Render::Text::DocView::GetExactCharBoundaries(pObject, &pCharRect, pos - 1)
      && (int)(float)(pCharRect.x1 - 40.0) < HScrollOffset )
    {
      HScrollOffset = (int)(float)(pCharRect.x1 - 40.0);
    }
    v15 = HScrollOffset < 0;
  }
  if ( v15 )
    HScrollOffset = 0;
LABEL_23:
  v17 = this->pDocView.pObject;
  if ( (v17->Flags & 8) == 0 || HScrollOffset < v14 )
    v7 = Scaleform::Render::Text::DocView::SetHScrollOffset(v17, HScrollOffset);
  v18 = this->pDocView.pObject;
  v19 = vscroll[0];
  if ( vscroll[0] < v18->mLineBuffer.Geom.FirstVisibleLinePos )
    return v7 | Scaleform::Render::Text::DocView::SetVScrollOffset(v18, vscroll[0]);
  if ( v19 > Scaleform::Render::Text::DocView::GetBottomVScroll(v18) )
    return v7 | Scaleform::Render::Text::DocView::SetBottomVScroll(this->pDocView.pObject, v19);
  return v7;
}

// File Line: 528
// RVA: 0x8EE1E0
// local variable allocation has failed, the output may be wrong!
void __fastcall Scaleform::GFx::Text::EditorKit::OnMouseDown(
        Scaleform::GFx::Text::EditorKit *this,
        double x,
        double y,
        char buttons)
{
  __m128 v5; // xmm6
  Scaleform::Render::Rect<float> *ViewRect; // rax
  __m128 v7; // xmm7
  int v8; // edx
  int v9; // ecx
  char v10; // r14
  char v11; // di
  unsigned __int64 v12; // rcx
  unsigned __int16 Flags; // dx
  Scaleform::Render::Text::DocView *pObject; // rcx
  unsigned __int64 CursorPosAtPoint; // rax
  unsigned __int64 v16; // rbx
  unsigned __int16 v17; // dx
  unsigned __int16 v18; // dx
  Scaleform::Render::Text::Paragraph *pPara; // r13
  unsigned __int64 Length; // rax
  unsigned __int64 v21; // rdi
  unsigned __int64 v22; // rbp
  unsigned __int64 v23; // r15
  wchar_t *pText; // r12
  wchar_t *v25; // rbx
  wchar_t v26; // r14
  wchar_t v27; // r10
  unsigned __int64 v28; // r8
  int v29; // r9d
  int v30; // eax
  int v31; // r9d
  int v32; // eax
  unsigned __int64 StartIndex; // rbx
  unsigned __int64 v34; // rdi
  unsigned __int64 pindexInParagraph; // [rsp+20h] [rbp-68h] BYREF
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator result; // [rsp+28h] [rbp-60h] BYREF

  if ( (buttons & 1) != 0 )
  {
    v5 = *(__m128 *)&y;
    v7 = *(__m128 *)&x;
    ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocView.pObject);
    v7.m128_f32[0] = *(float *)&x - ViewRect->x1;
    v8 = (int)v7.m128_f32[0];
    if ( (int)v7.m128_f32[0] != 0x80000000 && (float)v8 != v7.m128_f32[0] )
      v7.m128_f32[0] = (float)(v8 - (_mm_movemask_ps(_mm_unpacklo_ps(v7, v7)) & 1));
    v5.m128_f32[0] = *(float *)&y - ViewRect->y1;
    v9 = (int)v5.m128_f32[0];
    if ( (int)v5.m128_f32[0] != 0x80000000 && (float)v9 != v5.m128_f32[0] )
      v5.m128_f32[0] = (float)(v9 - (_mm_movemask_ps(_mm_unpacklo_ps(v5, v5)) & 1));
    v10 = 0;
    v11 = 0;
    v12 = Scaleform::Timer::GetTicks() / 0x3E8;
    if ( v7.m128_f32[0] == this->LastMousePos.x
      && v5.m128_f32[0] == this->LastMousePos.y
      && (unsigned int)v12 <= this->LastClickTime + 300 )
    {
      Flags = this->Flags;
      if ( (Flags & 0x200) != 0 )
        v11 = 1;
      else
        v10 = 1;
      this->Flags = Flags | 0x200;
    }
    else
    {
      this->Flags &= ~0x200u;
    }
    this->LastClickTime = v12;
    pObject = this->pDocView.pObject;
    LODWORD(this->LastMousePos.x) = v7.m128_i32[0];
    LODWORD(this->LastMousePos.y) = v5.m128_i32[0];
    CursorPosAtPoint = Scaleform::Render::Text::DocView::GetCursorPosAtPoint(pObject, v7.m128_f32[0], v5.m128_f32[0]);
    v16 = CursorPosAtPoint;
    if ( CursorPosAtPoint != -1i64 )
    {
      Scaleform::GFx::Text::EditorKit::SetCursorPos(this, CursorPosAtPoint, (this->Flags & 2) != 0);
      v17 = this->Flags;
      if ( (v17 & 2) != 0 && (v17 & 0x20) == 0 )
      {
        v18 = v17 | 0x20;
        this->Flags = v18;
        if ( v10 || v11 )
        {
          Scaleform::Render::Text::StyledText::GetParagraphByIndex(
            this->pDocView.pObject->pDocument.pObject,
            &result,
            v16,
            &pindexInParagraph);
          if ( result.pArray && result.CurIndex >= 0 && result.CurIndex < SLODWORD(result.pArray->Data.Size) )
          {
            pPara = result.pArray->Data.Data[result.CurIndex].pPara;
            Length = Scaleform::Render::Text::Paragraph::GetLength(pPara);
            v21 = pindexInParagraph;
            v22 = pindexInParagraph;
            v23 = Length;
            if ( v10 )
            {
              pText = pPara->Text.pText;
              if ( pindexInParagraph )
              {
                v25 = &pText[pindexInParagraph - 1];
                do
                {
                  v26 = *v25;
                  if ( (unsigned int)Scaleform::SFiswspace(*v25) )
                    break;
                  if ( !Scaleform::SFiswalnum(v26) )
                    break;
                  --v25;
                  --v22;
                }
                while ( v22 );
              }
              for ( ; v21 < v23; ++v21 )
              {
                v27 = pText[v21];
                v28 = (unsigned __int64)v27 >> 8;
                v29 = Scaleform::UnicodeSpaceBits[v28];
                if ( Scaleform::UnicodeSpaceBits[v28] )
                {
                  if ( v29 == 1 )
                    break;
                  v30 = Scaleform::UnicodeSpaceBits[v29 + ((v27 >> 4) & 0xF)];
                  if ( _bittest(&v30, v27 & 0xF) )
                    break;
                }
                v31 = Scaleform::UnicodeAlnumBits[v28];
                if ( !Scaleform::UnicodeAlnumBits[v28] )
                  break;
                if ( v31 != 1 )
                {
                  v32 = Scaleform::UnicodeAlnumBits[v31 + ((v27 >> 4) & 0xF)];
                  if ( !_bittest(&v32, v27 & 0xF) )
                    break;
                }
              }
            }
            else
            {
              v22 = 0i64;
              v21 = Length;
            }
            StartIndex = pPara->StartIndex;
            v34 = StartIndex + v21;
            Scaleform::GFx::Text::EditorKit::SetCursorPos(this, v34, (this->Flags & 2) != 0);
            Scaleform::Render::Text::DocView::SetSelection(this->pDocView.pObject, StartIndex + v22, v34, 1);
          }
        }
        else if ( (v18 & 0x40) == 0 )
        {
          Scaleform::Render::Text::DocView::SetSelection(this->pDocView.pObject, v16, v16, 1);
        }
      }
    }
  }
}

// File Line: 618
// RVA: 0x8EE840
// local variable allocation has failed, the output may be wrong!
void __fastcall Scaleform::GFx::Text::EditorKit::OnMouseMove(Scaleform::GFx::Text::EditorKit *this, double x, double y)
{
  __m128 v4; // xmm6
  __m128 v5; // xmm7
  Scaleform::Render::Rect<float> *ViewRect; // rax
  int v7; // edx
  int v8; // ecx
  Scaleform::Render::Text::DocView *pObject; // rcx
  unsigned __int64 CursorPosAtPoint; // rax
  unsigned __int64 v11; // rdi

  v4 = *(__m128 *)&y;
  v5 = *(__m128 *)&x;
  if ( (this->Flags & 0x20) != 0 )
  {
    ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocView.pObject);
    v5.m128_f32[0] = *(float *)&x - ViewRect->x1;
    v7 = (int)v5.m128_f32[0];
    if ( (int)v5.m128_f32[0] != 0x80000000 && (float)v7 != v5.m128_f32[0] )
      v5.m128_f32[0] = (float)(v7 - (_mm_movemask_ps(_mm_unpacklo_ps(v5, v5)) & 1));
    v4.m128_f32[0] = *(float *)&y - ViewRect->y1;
    v8 = (int)v4.m128_f32[0];
    if ( (int)v4.m128_f32[0] != 0x80000000 && (float)v8 != v4.m128_f32[0] )
      v4.m128_f32[0] = (float)(v8 - (_mm_movemask_ps(_mm_unpacklo_ps(v4, v4)) & 1));
    pObject = this->pDocView.pObject;
    LODWORD(this->LastMousePos.x) = v5.m128_i32[0];
    LODWORD(this->LastMousePos.y) = v4.m128_i32[0];
    CursorPosAtPoint = Scaleform::Render::Text::DocView::GetCursorPosAtPoint(pObject, v5.m128_f32[0], v4.m128_f32[0]);
    v11 = CursorPosAtPoint;
    if ( CursorPosAtPoint != -1i64 )
    {
      Scaleform::GFx::Text::EditorKit::SetCursorPos(this, CursorPosAtPoint, (this->Flags & 2) != 0);
      if ( (this->Flags & 2) != 0 )
        Scaleform::Render::Text::DocView::SetSelection(
          this->pDocView.pObject,
          this->pDocView.pObject->BeginSelection,
          v11,
          1);
    }
  }
}

// File Line: 665
// RVA: 0x8ED320
__int64 __fastcall Scaleform::GFx::Text::EditorKit::OnKeyDown(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned int keyCode,
        Scaleform::KeyModifiers *specKeysState)
{
  Scaleform::Render::Text::DocView *pObject; // r14
  Scaleform::Render::Text::StyledText *v5; // rcx
  unsigned __int64 Length; // rax
  Scaleform::Render::Text::DocView::DocumentListener *v8; // rcx
  unsigned __int64 CursorPos; // rdi
  unsigned __int64 v10; // r12
  unsigned int v11; // ecx
  Scaleform::Render::Text::DocView *v12; // r13
  unsigned __int16 Flags; // r15
  float LastHorizCursorPos; // xmm6_4
  unsigned __int64 EndSelection; // rsi
  unsigned __int64 v16; // r14
  unsigned __int64 BeginSelection; // rax
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v18; // rax
  char v19; // r13
  unsigned int LineIndexOfChar; // eax
  Scaleform::Render::Text::DocView *v22; // rcx
  unsigned int FirstVisibleLinePos; // edx
  char v24; // r15
  char v25; // al
  unsigned int v26; // eax
  unsigned int v27; // r12d
  Scaleform::Render::Text::DocView *v28; // rcx
  unsigned __int64 LineLength; // rax
  unsigned __int64 v30; // r15
  unsigned int v31; // eax
  Scaleform::Render::Text::DocView *v32; // rcx
  unsigned int v33; // edi
  unsigned __int64 v34; // rax
  unsigned __int64 v35; // r15
  unsigned __int64 v36; // rdx
  unsigned int BottomVScroll; // eax
  Scaleform::Render::Text::DocView *v38; // rcx
  unsigned int v39; // eax
  unsigned __int64 CursorPosInLine; // rax
  unsigned __int64 v41; // rdx
  unsigned int v42; // eax
  Scaleform::Render::Text::DocView *v43; // rcx
  unsigned int v44; // edi
  unsigned __int64 v45; // rax
  unsigned int v46; // edi
  Scaleform::Render::Text::DocView *v47; // rcx
  unsigned __int64 v48; // rax
  Scaleform::Render::Text::DocView *v49; // rcx
  unsigned __int64 v50; // rax
  unsigned __int16 v51; // cx
  Scaleform::Render::Text::DocView::DocumentListener *v52; // rcx
  bool phasNewLine; // [rsp+40h] [rbp-29h] BYREF
  unsigned int plineIndex[2]; // [rsp+48h] [rbp-21h] BYREF
  Scaleform::Render::Text::DocView *v55; // [rsp+50h] [rbp-19h]
  Scaleform::Render::Rect<float> pcursorRect; // [rsp+60h] [rbp-9h] BYREF
  unsigned int v57; // [rsp+D0h] [rbp+67h] BYREF
  unsigned int v58; // [rsp+D8h] [rbp+6Fh]
  Scaleform::KeyModifiers *specKeys; // [rsp+E0h] [rbp+77h]
  unsigned __int8 v60; // [rsp+E8h] [rbp+7Fh]

  specKeys = specKeysState;
  v58 = keyCode;
  pObject = this->pDocView.pObject;
  v5 = pObject->pDocument.pObject;
  v55 = pObject;
  Length = Scaleform::Render::Text::StyledText::GetLength(v5);
  v8 = pObject->pDocumentListener.pObject;
  CursorPos = this->CursorPos;
  v10 = Length;
  v60 = 0;
  if ( v8 )
    v11 = ((__int64 (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::GFx::Text::EditorKit *, _QWORD))v8->vfptr[7].__vecDelDtor)(
            v8,
            this,
            keyCode);
  else
    v11 = v58;
  v12 = this->pDocView.pObject;
  Flags = this->Flags;
  LastHorizCursorPos = FLOAT_N1_0;
  EndSelection = v12->EndSelection;
  v16 = EndSelection;
  LOBYTE(v57) = (Flags & 0x40) != 0;
  BeginSelection = v12->BeginSelection;
  if ( BeginSelection < EndSelection )
    EndSelection = v12->BeginSelection;
  if ( v16 < BeginSelection )
    v16 = v12->BeginSelection;
  if ( this->pKeyMap.pObject
    && (v18 = Scaleform::GFx::TextKeyMap::Find(this->pKeyMap.pObject, v11, specKeys, State_Down),
        (*(_QWORD *)plineIndex = v18) != 0i64) )
  {
    switch ( v18->Action )
    {
      case KeyAct_EnterSelectionMode:
        if ( (Flags & 2) == 0 )
          goto LABEL_12;
        goto LABEL_14;
      case KeyAct_Left:
        if ( CursorPos == -1i64 )
          CursorPos = v10;
        if ( CursorPos )
          --CursorPos;
        v19 = v57;
        if ( !(_BYTE)v57 && EndSelection != v16 )
        {
          CursorPos = v16;
          if ( EndSelection < v16 )
            CursorPos = EndSelection;
        }
        goto LABEL_38;
      case KeyAct_Right:
        if ( CursorPos == -1i64 )
        {
          CursorPos = v10;
        }
        else if ( CursorPos < v10 )
        {
          ++CursorPos;
        }
        v19 = v57;
        if ( !(_BYTE)v57 && EndSelection != v16 )
        {
          CursorPos = v16;
          if ( v16 < EndSelection )
            CursorPos = EndSelection;
        }
        goto LABEL_38;
      case KeyAct_Up:
        v19 = v57;
        pcursorRect = 0i64;
        if ( !(_BYTE)v57 && EndSelection != v16 )
        {
          CursorPos = v16;
          if ( EndSelection < v16 )
            CursorPos = EndSelection;
          goto LABEL_38;
        }
        v24 = 0;
        if ( (unsigned __int8)Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(
                                this,
                                this->CursorPos,
                                &pcursorRect,
                                &v57,
                                0i64,
                                1,
                                0i64) )
        {
          if ( v57 )
          {
            LastHorizCursorPos = this->LastHorizCursorPos;
            if ( LastHorizCursorPos < 0.0 )
              LastHorizCursorPos = pcursorRect.x1;
            CursorPos = Scaleform::Render::Text::DocView::GetCursorPosInLine(
                          this->pDocView.pObject,
                          v57 - 1,
                          LastHorizCursorPos);
          }
          else
          {
            CursorPos = 0i64;
          }
        }
        goto LABEL_39;
      case KeyAct_Down:
        v19 = v57;
        pcursorRect = 0i64;
        if ( !(_BYTE)v57 && EndSelection != v16 )
        {
          CursorPos = v16;
          if ( v16 < EndSelection )
            CursorPos = EndSelection;
          goto LABEL_38;
        }
        v24 = 0;
        if ( (unsigned __int8)Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(
                                this,
                                this->CursorPos,
                                &pcursorRect,
                                &v57,
                                0i64,
                                1,
                                0i64) )
        {
          v46 = v57 + 1;
          if ( v46 >= Scaleform::Render::Text::DocView::GetLinesCount(this->pDocView.pObject) )
          {
            CursorPos = v10;
          }
          else
          {
            LastHorizCursorPos = this->LastHorizCursorPos;
            if ( LastHorizCursorPos < 0.0 )
              LastHorizCursorPos = pcursorRect.x1;
            CursorPos = Scaleform::Render::Text::DocView::GetCursorPosInLine(
                          this->pDocView.pObject,
                          v46,
                          LastHorizCursorPos);
          }
        }
        goto LABEL_39;
      case KeyAct_PageUp:
        v36 = this->CursorPos;
        v24 = 0;
        pcursorRect = 0i64;
        if ( !(unsigned __int8)Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(
                                 this,
                                 v36,
                                 &pcursorRect,
                                 plineIndex,
                                 0i64,
                                 1,
                                 0i64) )
          goto LABEL_46;
        LastHorizCursorPos = this->LastHorizCursorPos;
        if ( LastHorizCursorPos < 0.0 )
          LastHorizCursorPos = pcursorRect.x1;
        BottomVScroll = Scaleform::Render::Text::DocView::GetBottomVScroll(this->pDocView.pObject);
        v38 = this->pDocView.pObject;
        v39 = BottomVScroll - v38->mLineBuffer.Geom.FirstVisibleLinePos + 1;
        if ( plineIndex[0] >= v39 )
        {
          CursorPosInLine = Scaleform::Render::Text::DocView::GetCursorPosInLine(
                              v38,
                              plineIndex[0] - v39,
                              LastHorizCursorPos);
          v19 = v57;
          CursorPos = CursorPosInLine;
        }
        else
        {
          v19 = v57;
          CursorPos = 0i64;
        }
        goto LABEL_39;
      case KeyAct_PageDown:
        v41 = this->CursorPos;
        v24 = 0;
        pcursorRect = 0i64;
        if ( !(unsigned __int8)Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(
                                 this,
                                 v41,
                                 &pcursorRect,
                                 plineIndex,
                                 0i64,
                                 1,
                                 0i64) )
          goto LABEL_46;
        LastHorizCursorPos = this->LastHorizCursorPos;
        if ( LastHorizCursorPos < 0.0 )
          LastHorizCursorPos = pcursorRect.x1;
        v42 = Scaleform::Render::Text::DocView::GetBottomVScroll(this->pDocView.pObject);
        v43 = this->pDocView.pObject;
        v44 = v42 - v43->mLineBuffer.Geom.FirstVisibleLinePos + plineIndex[0] + 1;
        if ( v44 < Scaleform::Render::Text::DocView::GetLinesCount(v43) )
        {
          v45 = Scaleform::Render::Text::DocView::GetCursorPosInLine(this->pDocView.pObject, v44, LastHorizCursorPos);
          v19 = v57;
          CursorPos = v45;
        }
        else
        {
          v19 = v57;
          CursorPos = v10;
        }
        goto LABEL_39;
      case KeyAct_LineHome:
        LineIndexOfChar = Scaleform::Render::Text::DocView::GetLineIndexOfChar(v12, this->CursorPos);
        if ( LineIndexOfChar == -1 )
          goto LABEL_37;
        v22 = this->pDocView.pObject;
        FirstVisibleLinePos = LineIndexOfChar;
LABEL_36:
        CursorPos = Scaleform::Render::Text::DocView::GetLineOffset(v22, FirstVisibleLinePos);
        goto LABEL_37;
      case KeyAct_LineEnd:
        v26 = Scaleform::Render::Text::DocView::GetLineIndexOfChar(v12, this->CursorPos);
        v27 = v26;
        if ( v26 != -1 )
        {
          v28 = this->pDocView.pObject;
          phasNewLine = 0;
          LineLength = Scaleform::Render::Text::DocView::GetLineLength(v28, v26, &phasNewLine);
          v30 = LineLength;
          if ( phasNewLine )
            v30 = LineLength - 1;
          CursorPos = v30 + Scaleform::Render::Text::DocView::GetLineOffset(this->pDocView.pObject, v27);
        }
        goto LABEL_37;
      case KeyAct_PageHome:
        FirstVisibleLinePos = v12->mLineBuffer.Geom.FirstVisibleLinePos;
        v22 = v12;
        goto LABEL_36;
      case KeyAct_PageEnd:
        v31 = Scaleform::Render::Text::DocView::GetBottomVScroll(v12);
        v32 = this->pDocView.pObject;
        v33 = v31;
        phasNewLine = 0;
        v34 = Scaleform::Render::Text::DocView::GetLineLength(v32, v31, &phasNewLine);
        v35 = v34;
        if ( phasNewLine )
          v35 = v34 - 1;
        CursorPos = v35 + Scaleform::Render::Text::DocView::GetLineOffset(this->pDocView.pObject, v33);
        goto LABEL_37;
      case KeyAct_DocHome:
        v24 = 0;
        CursorPos = 0i64;
LABEL_46:
        v19 = v57;
        goto LABEL_39;
      case KeyAct_DocEnd:
        CursorPos = v10;
        goto LABEL_37;
      case KeyAct_Backspace:
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Text::EditorKit *))this->vfptr[2].__vecDelDtor)(this) )
          goto LABEL_37;
        v47 = this->pDocView.pObject;
        this->Flags &= ~0x40u;
        if ( EndSelection != v16 )
          goto LABEL_89;
        *(_QWORD *)plineIndex = CursorPos;
        v48 = Scaleform::Render::Text::DocView::EditCommand(v47, Cmd_BackspaceChar, plineIndex);
        v19 = v57;
        v24 = 1;
        CursorPos -= v48;
        goto LABEL_39;
      case KeyAct_Delete:
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Text::EditorKit *))this->vfptr[2].__vecDelDtor)(this) )
          goto LABEL_37;
        this->Flags &= ~0x40u;
        if ( EndSelection != v16 )
        {
          v47 = this->pDocView.pObject;
LABEL_89:
          *(_QWORD *)&pcursorRect.x2 = v16;
          *(_QWORD *)&pcursorRect.x1 = EndSelection;
          Scaleform::Render::Text::DocView::EditCommand(v47, Cmd_DeleteText, &pcursorRect);
          goto LABEL_90;
        }
        if ( this->CursorPos >= v10 )
        {
LABEL_37:
          v19 = v57;
LABEL_38:
          v24 = 0;
        }
        else
        {
          v49 = this->pDocView.pObject;
          *(_QWORD *)plineIndex = CursorPos;
          Scaleform::Render::Text::DocView::EditCommand(v49, Cmd_DeleteChar, plineIndex);
          v19 = v57;
          v24 = 1;
        }
        goto LABEL_39;
      case KeyAct_Copy:
      case KeyAct_Cut:
        if ( !this->pClipboard.pObject )
          goto LABEL_37;
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Text::EditorKit *))this->vfptr[2].__vecDelDtor)(this)
          || **(_DWORD **)plineIndex == 19 )
        {
          this->Flags &= ~0x40u;
          Scaleform::GFx::Text::EditorKit::CopyToClipboard(this, EndSelection, v16, (this->Flags & 4) != 0);
          goto LABEL_12;
        }
        this->Flags &= ~0x40u;
        Scaleform::GFx::Text::EditorKit::CutToClipboard(this, EndSelection, v16, (this->Flags & 4) != 0);
LABEL_90:
        v19 = v57;
        CursorPos = v16;
        if ( EndSelection < v16 )
          CursorPos = EndSelection;
        v24 = 1;
LABEL_39:
        if ( this->CursorPos == CursorPos )
        {
          v51 = this->Flags;
          if ( (v51 & 0x40) != 0 || EndSelection == v16 )
          {
            v25 = 0;
          }
          else
          {
            Scaleform::GFx::Text::EditorKit::SetCursorPos(this, CursorPos, (v51 & 2) != 0);
            v25 = 1;
            v60 = 1;
          }
        }
        else
        {
          Scaleform::GFx::Text::EditorKit::SetCursorPos(this, CursorPos, (this->Flags & 2) != 0);
          v25 = 1;
          v60 = 1;
          this->LastHorizCursorPos = LastHorizCursorPos;
        }
        if ( v24 )
        {
          if ( !v25 )
            Scaleform::Render::Text::DocView::SetDefaultTextAndParaFormat(this->pDocView.pObject, this->CursorPos);
          v52 = v55->pDocumentListener.pObject;
          if ( v52 )
            v52->vfptr[9].__vecDelDtor(v52, (unsigned int)this);
        }
        break;
      case KeyAct_Paste:
        v50 = Scaleform::GFx::Text::EditorKit::PasteFromClipboard(this, EndSelection, v16, (Flags & 4) != 0);
        v19 = v57;
        if ( v50 == -1i64 )
          goto LABEL_38;
        CursorPos = v50;
        v24 = 1;
        goto LABEL_39;
      case KeyAct_SelectAll:
        Scaleform::GFx::Text::EditorKit::SetCursorPos(this, v10, (Flags & 2) != 0);
        Scaleform::Render::Text::DocView::SetSelection(this->pDocView.pObject, 0i64, v10, 1);
        goto LABEL_12;
      default:
        goto LABEL_12;
    }
  }
  else
  {
LABEL_12:
    v19 = v57;
  }
  if ( v19 )
LABEL_14:
    this->Flags |= 0x40u;
  return v60;
}

// File Line: 1029
// RVA: 0x8EC250
char __fastcall Scaleform::GFx::Text::EditorKit::OnChar(Scaleform::GFx::Text::EditorKit *this, unsigned int wcharCode)
{
  unsigned int v2; // ebp
  Scaleform::GFx::Text::EditorKit::RestrictParams *pObject; // rbx
  __int64 RangeIndex; // rax
  char v6; // si
  unsigned __int64 Size; // rcx
  bool v8; // cf
  char v9; // al
  int v10; // ebx
  unsigned __int16 v11; // ax
  Scaleform::GFx::Text::EditorKit::RestrictParams *v12; // rbx
  __int64 v13; // rax
  unsigned __int64 v14; // rcx
  char result; // al
  unsigned __int64 CursorPos; // rbx
  Scaleform::Render::Text::DocView *v17; // r13
  char v18; // r12
  unsigned __int64 BeginSelection; // rax
  unsigned __int64 EndSelection; // r14
  unsigned __int64 v21; // rsi
  char v22; // r15
  Scaleform::Render::Text::DocView *v23; // rcx
  Scaleform::Render::Text::DocView *v24; // rcx
  unsigned __int64 v25; // rbx
  unsigned __int64 v26; // rax
  Scaleform::Render::Text::DocView *v27; // rcx
  Scaleform::Render::Text::DocView::DocumentText *v28; // rax
  bool v29; // zf
  unsigned __int8 v30; // al
  __int16 v31; // dx
  unsigned __int64 v32; // rax
  unsigned __int8 v33; // al
  Scaleform::Render::Text::DocView::DocumentListener *v34; // rcx
  unsigned __int64 command; // [rsp+20h] [rbp-48h] BYREF
  unsigned __int64 v36; // [rsp+28h] [rbp-40h]
  __int16 v37; // [rsp+30h] [rbp-38h]

  v2 = wcharCode;
  if ( wcharCode && (this->Flags & 0x20) == 0 )
  {
    pObject = this->pRestrict.pObject;
    if ( !pObject )
      goto LABEL_25;
    RangeIndex = Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::FindRangeIndex(
                   &pObject->RestrictRanges,
                   (unsigned __int16)wcharCode);
    v6 = 0;
    if ( RangeIndex == -1 )
      goto LABEL_11;
    if ( RangeIndex >= 0 )
    {
      Size = pObject->RestrictRanges.Ranges.Data.Size;
      if ( RangeIndex >= Size )
        RangeIndex = Size - 1;
      if ( RangeIndex < 0 )
        goto LABEL_11;
    }
    else
    {
      RangeIndex = 0i64;
    }
    v8 = RangeIndex < pObject->RestrictRanges.Ranges.Data.Size;
    v9 = 0;
    if ( v8 )
    {
LABEL_12:
      if ( !v9 )
        goto LABEL_25;
      v10 = Scaleform::SFtowupper(v2);
      v11 = Scaleform::SFtowlower(v2);
      if ( v2 != v10 )
        v11 = v10;
      v12 = this->pRestrict.pObject;
      LOWORD(v2) = v11;
      if ( !v12 )
        goto LABEL_25;
      v13 = Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::FindRangeIndex(
              &this->pRestrict.pObject->RestrictRanges,
              v11);
      if ( v13 != -1 )
      {
        if ( v13 < 0 )
        {
          v13 = 0i64;
          goto LABEL_22;
        }
        v14 = v12->RestrictRanges.Ranges.Data.Size;
        if ( v13 >= v14 )
          v13 = v14 - 1;
        if ( v13 >= 0 )
        {
LABEL_22:
          if ( v13 < v12->RestrictRanges.Ranges.Data.Size )
            goto LABEL_24;
        }
      }
      v6 = 1;
LABEL_24:
      result = v6 == 0;
      if ( v6 )
        return result;
LABEL_25:
      CursorPos = this->CursorPos;
      v17 = this->pDocView.pObject;
      v18 = 0;
      BeginSelection = v17->BeginSelection;
      EndSelection = v17->EndSelection;
      v21 = EndSelection;
      if ( BeginSelection < EndSelection )
        EndSelection = v17->BeginSelection;
      if ( v21 < BeginSelection )
        v21 = v17->BeginSelection;
      v22 = 0;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Text::EditorKit *))this->vfptr[2].__vecDelDtor)(this) )
        return v18;
      if ( (_WORD)v2 == 13 )
      {
        v27 = this->pDocView.pObject;
        if ( (v27->Flags & 4) == 0 )
          goto LABEL_51;
        this->Flags &= ~0x40u;
        v28 = v27->pDocument.pObject;
        if ( EndSelection == v21 )
        {
          v29 = (v28->RTFlags & 2) == 0;
          v30 = 10;
          if ( !v29 )
            v30 = 13;
          v31 = v30;
          v32 = this->CursorPos;
          LOWORD(v36) = v31;
          command = v32;
          Scaleform::Render::Text::DocView::EditCommand(v27, Cmd_InsertChar, &command);
        }
        else
        {
          v29 = (v28->RTFlags & 2) == 0;
          v33 = 10;
          if ( !v29 )
            v33 = 13;
          command = EndSelection;
          v36 = v21;
          v37 = v33;
          Scaleform::Render::Text::DocView::EditCommand(v27, Cmd_ReplaceTextByChar, &command);
          CursorPos = v21;
          if ( EndSelection < v21 )
            CursorPos = EndSelection;
        }
        ++CursorPos;
      }
      else
      {
        if ( (unsigned __int16)v2 < 0x20u )
          return v18;
        if ( EndSelection != v21 )
          goto LABEL_37;
        if ( SLOBYTE(this->Flags) < 0 )
          ++v21;
        if ( EndSelection == v21 )
        {
          v23 = this->pDocView.pObject;
          command = this->CursorPos;
          LOWORD(v36) = v2;
          CursorPos += Scaleform::Render::Text::DocView::EditCommand(v23, Cmd_InsertChar, &command);
        }
        else
        {
LABEL_37:
          v24 = this->pDocView.pObject;
          command = EndSelection;
          v36 = v21;
          v37 = v2;
          v25 = Scaleform::Render::Text::DocView::EditCommand(v24, Cmd_ReplaceTextByChar, &command);
          v26 = v21;
          if ( EndSelection < v21 )
            v26 = EndSelection;
          CursorPos = v26 + v25;
        }
      }
      v22 = 1;
LABEL_51:
      if ( this->CursorPos != CursorPos || EndSelection != CursorPos || v21 != CursorPos )
      {
        Scaleform::GFx::Text::EditorKit::SetCursorPos(this, CursorPos, 0);
        v18 = 1;
      }
      if ( v22 )
      {
        v34 = v17->pDocumentListener.pObject;
        if ( v34 )
          v34->vfptr[9].__vecDelDtor(v34, (unsigned int)this);
      }
      return v18;
    }
LABEL_11:
    v9 = 1;
    goto LABEL_12;
  }
  return 0;
}

// File Line: 1126
// RVA: 0x8EC5F0
void __fastcall Scaleform::GFx::Text::EditorKit::OnDocumentChanged(
        Scaleform::GFx::Text::EditorKit *this,
        __int16 notifyMask)
{
  unsigned __int64 Length; // rdx

  if ( (notifyMask & 0x102) == 0 )
  {
    if ( this->CursorPos <= Scaleform::Render::Text::StyledText::GetLength(this->pDocView.pObject->pDocument.pObject) )
      return;
    Length = Scaleform::Render::Text::StyledText::GetLength(this->pDocView.pObject->pDocument.pObject);
    goto LABEL_7;
  }
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Text::EditorKit *))this->vfptr[2].__vecDelDtor)(this)
    || (this->Flags & 2) != 0 )
  {
    Length = 0i64;
LABEL_7:
    Scaleform::GFx::Text::EditorKit::SetCursorPos(this, Length, (this->Flags & 2) != 0);
  }
}

// File Line: 1149
// RVA: 0x8EE070
void __fastcall Scaleform::GFx::Text::EditorKit::OnKillFocus(Scaleform::GFx::Text::EditorKit *this)
{
  Scaleform::Render::Text::DocView::SetSelectionTextColor(this->pDocView.pObject, this->InactiveSelectionTextColor);
  Scaleform::Render::Text::DocView::SetSelectionBackgroundColor(this->pDocView.pObject, this->InactiveSelectionBkColor);
  this->Flags &= 0xFB9Fu;
}

// File Line: 1158
// RVA: 0x90BC60
void __fastcall Scaleform::GFx::Text::EditorKit::SetSelection(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Text::EditorKit *))this->vfptr[2].__vecDelDtor)(this)
    || (this->Flags & 2) != 0 )
  {
    Scaleform::GFx::Text::EditorKit::SetCursorPos(this, endPos, (this->Flags & 2) != 0);
  }
  Scaleform::Render::Text::DocView::SetSelection(this->pDocView.pObject, startPos, endPos, (this->Flags & 2) != 0);
}

// File Line: 1167
// RVA: 0x8BE4E0
void __fastcall Scaleform::GFx::Text::EditorKit::CopyToClipboard(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned __int64 startPos,
        unsigned __int64 endPos,
        bool useRichClipboard)
{
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // rdi
  Scaleform::Render::Text::StyledText *v8; // rax
  Scaleform::RefCountNTSImpl *v9; // r14
  unsigned __int64 Length; // rdi
  wchar_t *pText; // rbp
  Scaleform::GFx::Clipboard *pObject; // rbx
  wchar_t *v13; // rdx
  Scaleform::WStringBuffer pBuffer; // [rsp+28h] [rbp-40h] BYREF

  v5 = endPos;
  v6 = startPos;
  if ( this->pClipboard.pObject && (this->pDocView.pObject->Flags & 0x10) == 0 )
  {
    if ( endPos < startPos )
    {
      v6 = endPos;
      v5 = startPos;
    }
    memset(&pBuffer, 0, sizeof(pBuffer));
    Scaleform::Render::Text::StyledText::GetText(this->pDocView.pObject->pDocument.pObject, &pBuffer, v6, v5);
    if ( useRichClipboard )
    {
      v8 = Scaleform::Render::Text::StyledText::CopyStyledText(this->pDocView.pObject->pDocument.pObject, v6, v5);
      v9 = v8;
      Length = pBuffer.Length;
      pText = (wchar_t *)byte_1416A7BD8;
      if ( pBuffer.pText )
        pText = pBuffer.pText;
      pObject = this->pClipboard.pObject;
      Scaleform::GFx::Clipboard::SetStyledText(pObject, v8);
      Scaleform::GFx::Clipboard::SetText(pObject, pText, Length);
      if ( v9 )
        Scaleform::RefCountNTSImpl::Release(v9);
    }
    else
    {
      v13 = (wchar_t *)byte_1416A7BD8;
      if ( pBuffer.pText )
        v13 = pBuffer.pText;
      Scaleform::GFx::Clipboard::SetText(this->pClipboard.pObject, v13, pBuffer.Length);
    }
    Scaleform::WStringBuffer::~WStringBuffer(&pBuffer);
  }
}

// File Line: 1192
// RVA: 0x8C4560
void __fastcall Scaleform::GFx::Text::EditorKit::CutToClipboard(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned __int64 startPos,
        unsigned __int64 endPos,
        bool useRichClipboard)
{
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // rdi
  Scaleform::Render::Text::DocView::DocumentListener *pObject; // rcx
  unsigned __int64 v8; // rbx

  v4 = endPos;
  v5 = startPos;
  if ( this->pClipboard.pObject )
  {
    if ( endPos < startPos )
    {
      v5 = endPos;
      v4 = startPos;
    }
    Scaleform::GFx::Text::EditorKit::CopyToClipboard(this, v5, v4, useRichClipboard);
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Text::EditorKit *))this->vfptr[2].__vecDelDtor)(this) )
    {
      pObject = this->pDocView.pObject->pDocumentListener.pObject;
      if ( !pObject
        || ((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::GFx::Text::EditorKit *, unsigned __int64, unsigned __int64))pObject->vfptr[13].__vecDelDtor)(
             pObject,
             this,
             v5,
             v4 - v5) )
      {
        if ( v4 < v5 )
          v8 = 0i64;
        else
          v8 = v4 - v5;
        Scaleform::Render::Text::StyledText::Remove(this->pDocView.pObject->pDocument.pObject, v5, v8);
      }
    }
  }
}

// File Line: 1216
// RVA: 0x8EF680
__int64 __fastcall Scaleform::GFx::Text::EditorKit::PasteFromClipboard(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned __int64 startPos,
        unsigned __int64 endPos,
        bool useRichClipboard)
{
  __int64 v8; // r14
  Scaleform::GFx::Clipboard *pObject; // rcx
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // r12
  Scaleform::Render::Text::StyledText *v12; // rax
  wchar_t *v13; // rbx
  Scaleform::Render::Text::DocView *v14; // rax
  wchar_t *pText; // r14
  char v16; // al
  Scaleform::WStringBuffer *p_pBuffer; // rcx
  unsigned __int64 *p_Length; // r8
  Scaleform::Render::Text::DocView::CommandType v19; // edx
  wchar_t *v20; // r14
  __int64 v22; // rbx
  Scaleform::Render::Text::DocView *v23; // rcx
  char *v24; // r14
  Scaleform::Render::Text::DocView::DocumentListener *v25; // rcx
  char *v26; // rdx
  __int64 v27; // rcx
  __int64 *v28; // r8
  Scaleform::Render::Text::DocView::CommandType v29; // edx
  char *v30; // rdx
  __int64 v31; // rcx
  unsigned __int64 Length; // rbx
  __int64 v33; // rsi
  unsigned __int64 v34; // r13
  unsigned int CharAt; // eax
  unsigned int v36; // r14d
  Scaleform::GFx::Text::EditorKit::RestrictParams *v37; // rbx
  __int64 RangeIndex; // rax
  unsigned __int64 Size; // rcx
  char v40; // al
  int v41; // ebx
  unsigned __int16 v42; // r15
  Scaleform::GFx::Text::EditorKit::RestrictParams *v43; // rbx
  wchar_t *v44; // rax
  unsigned __int64 v45; // rcx
  char v46; // al
  unsigned __int64 v47; // [rsp+30h] [rbp-A8h] BYREF
  Scaleform::String result; // [rsp+38h] [rbp-A0h] BYREF
  Scaleform::WStringBuffer v49; // [rsp+40h] [rbp-98h] BYREF
  Scaleform::WStringBuffer pBuffer; // [rsp+60h] [rbp-78h] BYREF
  __int64 v51; // [rsp+80h] [rbp-58h]
  __int64 v52[3]; // [rsp+88h] [rbp-50h] BYREF
  __int64 v53[2]; // [rsp+A0h] [rbp-38h] BYREF
  unsigned __int16 v54; // [rsp+B0h] [rbp-28h]
  __int64 command[3]; // [rsp+B8h] [rbp-20h] BYREF
  __int64 v56[12]; // [rsp+D0h] [rbp-8h] BYREF
  __int64 v57; // [rsp+138h] [rbp+60h]

  v56[5] = -2i64;
  v8 = -1i64;
  v57 = -1i64;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Text::EditorKit *))this->vfptr[2].__vecDelDtor)(this) )
  {
    pObject = this->pClipboard.pObject;
    if ( pObject )
    {
      if ( endPos < startPos )
      {
        v10 = endPos;
        endPos = startPos;
        startPos = v10;
      }
      v11 = 0i64;
      if ( !useRichClipboard
        || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Clipboard *))pObject->vfptr[6].__vecDelDtor)(pObject) )
      {
        v22 = ((__int64 (__fastcall *)(Scaleform::GFx::Clipboard *))this->pClipboard.pObject->vfptr[4].__vecDelDtor)(this->pClipboard.pObject);
        if ( !*(_QWORD *)(v22 + 8) )
          goto LABEL_49;
        this->Flags &= ~0x40u;
        v23 = this->pDocView.pObject;
        v24 = byte_1416A7BD8;
        if ( startPos == endPos )
        {
          if ( v23->pDocumentListener.pObject )
          {
            v25 = v23->pDocumentListener.pObject;
            v26 = byte_1416A7BD8;
            if ( *(_QWORD *)v22 )
              v26 = *(char **)v22;
            if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::GFx::Text::EditorKit *, unsigned __int64, _QWORD, char *))v25->vfptr[12].__vecDelDtor)(
                    v25,
                    this,
                    startPos,
                    *(_QWORD *)(v22 + 8),
                    v26) )
              return -1i64;
          }
          v27 = *(_QWORD *)(v22 + 8);
          if ( *(_QWORD *)v22 )
            v24 = *(char **)v22;
          v52[0] = startPos;
          v52[1] = (__int64)v24;
          v52[2] = v27;
          v28 = v52;
          v29 = Cmd_InsertPlainText;
        }
        else
        {
          if ( v23->pDocumentListener.pObject )
          {
            if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::GFx::Text::EditorKit *, unsigned __int64, unsigned __int64))v23->pDocumentListener.pObject->vfptr[13].__vecDelDtor)(
                    v23->pDocumentListener.pObject,
                    this,
                    startPos,
                    endPos - startPos) )
              return -1i64;
            v30 = byte_1416A7BD8;
            if ( *(_QWORD *)v22 )
              v30 = *(char **)v22;
            if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::GFx::Text::EditorKit *, unsigned __int64, _QWORD, char *))this->pDocView.pObject->pDocumentListener.pObject->vfptr[12].__vecDelDtor)(
                    this->pDocView.pObject->pDocumentListener.pObject,
                    this,
                    startPos,
                    *(_QWORD *)(v22 + 8),
                    v30) )
              return -1i64;
          }
          v31 = *(_QWORD *)(v22 + 8);
          if ( *(_QWORD *)v22 )
            v24 = *(char **)v22;
          v56[0] = startPos;
          v56[1] = endPos;
          v56[2] = (__int64)v24;
          v56[3] = v31;
          v28 = v56;
          v29 = Cmd_ReplaceTextByPlainText;
        }
        v8 = Scaleform::Render::Text::DocView::EditCommand(this->pDocView.pObject, v29, v28) + startPos;
        v57 = v8;
        goto LABEL_49;
      }
      v12 = (Scaleform::Render::Text::StyledText *)((__int64 (__fastcall *)(Scaleform::GFx::Clipboard *))this->pClipboard.pObject->vfptr[5].__vecDelDtor)(this->pClipboard.pObject);
      v13 = (wchar_t *)v12;
      if ( v12 )
        ++v12->RefCount;
      v56[4] = (__int64)v12;
      if ( !v12 || !Scaleform::Render::Text::StyledText::GetLength(v12) )
        goto LABEL_29;
      this->Flags &= ~0x40u;
      v14 = this->pDocView.pObject;
      if ( startPos == endPos )
      {
        if ( !v14->pDocumentListener.pObject )
        {
LABEL_17:
          pBuffer.Length = startPos;
          pBuffer.Reserved.pBuffer = v13;
          p_Length = &pBuffer.Length;
          v19 = Cmd_InsertStyledText;
LABEL_28:
          v8 = Scaleform::Render::Text::DocView::EditCommand(this->pDocView.pObject, v19, p_Length) + startPos;
          v57 = v8;
LABEL_29:
          if ( v13 )
            Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v13);
LABEL_49:
          if ( this->pRestrict.pObject )
          {
            Length = Scaleform::Render::Text::StyledText::GetLength(this->pDocView.pObject->pDocument.pObject);
            v47 = Length;
            Scaleform::Render::Text::DocView::GetText(this->pDocView.pObject, &result);
            v33 = 0i64;
            if ( Length )
            {
              v34 = Length;
              do
              {
                CharAt = Scaleform::String::GetCharAt(&result, v11);
                v36 = CharAt;
                v37 = this->pRestrict.pObject;
                if ( !v37 )
                  goto LABEL_78;
                RangeIndex = Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::FindRangeIndex(
                               &this->pRestrict.pObject->RestrictRanges,
                               (unsigned __int16)CharAt);
                if ( RangeIndex == -1 )
                  goto LABEL_61;
                if ( RangeIndex >= 0 )
                {
                  Size = v37->RestrictRanges.Ranges.Data.Size;
                  if ( RangeIndex >= Size )
                    RangeIndex = Size - 1;
                  v51 = RangeIndex;
                  if ( RangeIndex < 0 )
                    goto LABEL_61;
                }
                else
                {
                  RangeIndex = 0i64;
                  v51 = 0i64;
                }
                if ( RangeIndex < v37->RestrictRanges.Ranges.Data.Size )
                {
                  v40 = 0;
                  goto LABEL_62;
                }
LABEL_61:
                v40 = 1;
LABEL_62:
                if ( !v40 )
                  goto LABEL_78;
                v41 = Scaleform::SFtowupper(v36);
                v42 = Scaleform::SFtowlower(v36);
                if ( v36 != v41 )
                  v42 = v41;
                v43 = this->pRestrict.pObject;
                if ( !v43 )
                {
LABEL_77:
                  v53[0] = v33;
                  v53[1] = v33 + 1;
                  v54 = v42;
                  Scaleform::Render::Text::DocView::EditCommand(this->pDocView.pObject, Cmd_ReplaceTextByChar, v53);
                  goto LABEL_78;
                }
                v44 = (wchar_t *)Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::FindRangeIndex(
                                   &this->pRestrict.pObject->RestrictRanges,
                                   v42);
                if ( v44 == (wchar_t *)-1i64 )
                {
LABEL_74:
                  v46 = 1;
                  goto LABEL_75;
                }
                if ( (__int64)v44 >= 0 )
                {
                  v45 = v43->RestrictRanges.Ranges.Data.Size;
                  if ( (unsigned __int64)v44 >= v45 )
                    v44 = (wchar_t *)(v45 - 1);
                  pBuffer.pText = v44;
                  if ( (__int64)v44 < 0 )
                    goto LABEL_74;
                }
                else
                {
                  v44 = 0i64;
                  pBuffer.pText = 0i64;
                }
                if ( (unsigned __int64)v44 >= v43->RestrictRanges.Ranges.Data.Size )
                  goto LABEL_74;
                v46 = 0;
LABEL_75:
                if ( !v46 )
                  goto LABEL_77;
                v47 = v33;
                Scaleform::Render::Text::DocView::EditCommand(this->pDocView.pObject, Cmd_DeleteChar, &v47);
                --v33;
LABEL_78:
                ++v11;
                ++v33;
              }
              while ( v11 < v34 );
            }
            if ( _InterlockedExchangeAdd(
                   (volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
                   0xFFFFFFFF) == 1 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            return v57;
          }
          return v8;
        }
        memset(&pBuffer, 0, sizeof(pBuffer));
        Scaleform::Render::Text::StyledText::GetText((Scaleform::Render::Text::StyledText *)v13, &pBuffer);
        pText = (wchar_t *)byte_1416A7BD8;
        if ( pBuffer.pText )
          pText = pBuffer.pText;
        v16 = ((__int64 (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::GFx::Text::EditorKit *, unsigned __int64, unsigned __int64, wchar_t *))this->pDocView.pObject->pDocumentListener.pObject->vfptr[12].__vecDelDtor)(
                this->pDocView.pObject->pDocumentListener.pObject,
                this,
                startPos,
                pBuffer.Length,
                pText);
        p_pBuffer = &pBuffer;
        if ( v16 )
        {
          Scaleform::WStringBuffer::~WStringBuffer(&pBuffer);
          goto LABEL_17;
        }
        goto LABEL_25;
      }
      if ( v14->pDocumentListener.pObject )
      {
        memset(&v49, 0, sizeof(v49));
        Scaleform::Render::Text::StyledText::GetText((Scaleform::Render::Text::StyledText *)v13, &v49);
        if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::GFx::Text::EditorKit *, unsigned __int64, unsigned __int64))this->pDocView.pObject->pDocumentListener.pObject->vfptr[13].__vecDelDtor)(
                this->pDocView.pObject->pDocumentListener.pObject,
                this,
                startPos,
                endPos - startPos) )
          goto LABEL_24;
        v20 = (wchar_t *)byte_1416A7BD8;
        if ( v49.pText )
          v20 = v49.pText;
        if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::GFx::Text::EditorKit *, unsigned __int64, unsigned __int64, wchar_t *))this->pDocView.pObject->pDocumentListener.pObject->vfptr[12].__vecDelDtor)(
                this->pDocView.pObject->pDocumentListener.pObject,
                this,
                startPos,
                v49.Length,
                v20) )
        {
LABEL_24:
          p_pBuffer = &v49;
LABEL_25:
          Scaleform::WStringBuffer::~WStringBuffer(p_pBuffer);
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v13);
          return -1i64;
        }
        Scaleform::WStringBuffer::~WStringBuffer(&v49);
      }
      command[0] = startPos;
      command[1] = endPos;
      command[2] = (__int64)v13;
      p_Length = (unsigned __int64 *)command;
      v19 = Cmd_ReplaceTextByStyledText;
      goto LABEL_28;
    }
  }
  return v8;
}

// File Line: 1338
// RVA: 0x8E6D50
void __fastcall Scaleform::GFx::Text::EditorKit::InvalidateSelectionColors(Scaleform::GFx::Text::EditorKit *this)
{
  if ( (this->Flags & 0x400) != 0 )
  {
    Scaleform::Render::Text::DocView::SetSelectionTextColor(this->pDocView.pObject, this->ActiveSelectionTextColor);
    Scaleform::Render::Text::DocView::SetSelectionBackgroundColor(this->pDocView.pObject, this->ActiveSelectionBkColor);
  }
  else
  {
    Scaleform::Render::Text::DocView::SetSelectionTextColor(this->pDocView.pObject, this->InactiveSelectionTextColor);
    Scaleform::Render::Text::DocView::SetSelectionBackgroundColor(
      this->pDocView.pObject,
      this->InactiveSelectionBkColor);
  }
}

// File Line: 1419
// RVA: 0x8EF320
char __fastcall Scaleform::GFx::Text::EditorKit::ParseRestrict(
        Scaleform::GFx::Text::EditorKit *this,
        char *restrStr,
        unsigned __int64 restrStrLen)
{
  Scaleform::GFx::Text::EditorKit::RestrictParams *v6; // rax
  Scaleform::GFx::Text::EditorKit::RestrictParams *v7; // rbx
  Scaleform::GFx::Text::EditorKit::RestrictParams *pObject; // rcx
  bool v10; // r12
  const char *v11; // rax
  unsigned int v12; // edi
  unsigned int v13; // r15d
  const char *v14; // r13
  unsigned int Char_Advance0; // ebx
  char *v16; // rax
  Scaleform::GFx::Text::EditorKit::RestrictParams *v17; // rcx
  char *putf8Buffer[6]; // [rsp+20h] [rbp-50h] BYREF
  Scaleform::RangeData<void *> range; // [rsp+50h] [rbp-20h] BYREF
  int v20; // [rsp+C8h] [rbp+58h] BYREF

  putf8Buffer[1] = (char *)-2i64;
  v20 = 325;
  v6 = (Scaleform::GFx::Text::EditorKit::RestrictParams *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                            Scaleform::Memory::pGlobalHeap,
                                                            this,
                                                            32i64,
                                                            &v20);
  v7 = v6;
  putf8Buffer[2] = (char *)v6;
  if ( v6 )
  {
    putf8Buffer[3] = (char *)v6;
    putf8Buffer[4] = (char *)v6;
    putf8Buffer[5] = (char *)v6;
    v6->RestrictRanges.Ranges.Data.Data = 0i64;
    v6->RestrictRanges.Ranges.Data.Size = 0i64;
    v6->RestrictRanges.Ranges.Data.Policy.Capacity = 0i64;
    Scaleform::StringLH::StringLH(&v6->RestrictString);
  }
  else
  {
    v7 = 0i64;
  }
  pObject = this->pRestrict.pObject;
  if ( pObject != v7 )
  {
    if ( pObject && this->pRestrict.Owner )
    {
      this->pRestrict.Owner = 0;
      Scaleform::GFx::Text::EditorKit::RestrictParams::`scalar deleting destructor(pObject, 1);
    }
    this->pRestrict.pObject = v7;
  }
  this->pRestrict.Owner = v7 != 0i64;
  if ( !this->pRestrict.pObject )
    return 0;
  putf8Buffer[0] = restrStr;
  v10 = 0;
  v11 = &restrStr[restrStrLen];
  v12 = 0;
  v13 = 0;
  if ( restrStr < v11 )
  {
    v14 = v11;
    do
    {
      Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)putf8Buffer);
      v16 = putf8Buffer[0];
      if ( !Char_Advance0 )
        v16 = --putf8Buffer[0];
      switch ( Char_Advance0 )
      {
        case ^:
          v10 = !v10;
          break;
        case \\:
          if ( v16 >= v14 )
            return 1;
          Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)putf8Buffer);
          if ( !Char_Advance0 )
            --putf8Buffer[0];
LABEL_23:
          if ( v12 )
          {
            if ( Char_Advance0 < v12 )
              Char_Advance0 = v12;
          }
          else
          {
            v12 = Char_Advance0;
          }
          v17 = this->pRestrict.pObject;
          if ( v10 )
          {
            if ( !v17->RestrictRanges.Ranges.Data.Size )
            {
              range.Index = 0i64;
              range.Length = 0x10000i64;
              range.Data = 0i64;
              Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
                &v17->RestrictRanges,
                &range);
            }
            Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::ClearRange(
              &this->pRestrict.pObject->RestrictRanges,
              v12,
              Char_Advance0 - v12 + 1);
          }
          else
          {
            range.Index = v12;
            range.Length = Char_Advance0 - v12 + 1;
            range.Data = 0i64;
            Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
              &v17->RestrictRanges,
              &range);
          }
          v13 = Char_Advance0;
          v12 = 0;
          v16 = putf8Buffer[0];
          break;
        case -:
          v12 = v13;
          break;
        default:
          goto LABEL_23;
      }
    }
    while ( v16 < v14 );
  }
  return 1;
}

