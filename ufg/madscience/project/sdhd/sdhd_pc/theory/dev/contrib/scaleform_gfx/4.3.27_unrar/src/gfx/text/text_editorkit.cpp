// File Line: 27
// RVA: 0x896080
void __fastcall Scaleform::GFx::Text::EditorKit::EditorKit(Scaleform::GFx::Text::EditorKit *this, Scaleform::Render::Text::DocView *pdocview)
{
  Scaleform::Render::Text::DocView *v2; // rdi
  Scaleform::GFx::Text::EditorKit *v3; // rbx
  Scaleform::Render::RenderBuffer *v4; // rcx

  v2 = pdocview;
  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,74>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Text::EditorKitBase,74>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::EditorKitBase::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Text::EditorKit::`vftable';
  if ( pdocview )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pdocview);
  v3->pDocView.pObject = v2;
  v3->pClipboard.pObject = 0i64;
  v3->pKeyMap.pObject = 0i64;
  v3->pRestrict.pObject = 0i64;
  v3->pRestrict.Owner = 1;
  v3->CursorRect.FormatCounter = 0;
  v3->Flags = 0;
  v3->CursorTimer = 0.0;
  v3->CursorPos = 0i64;
  v3->CursorColor.Raw = -16777216;
  v3->LastAdvanceTime = 0.0;
  v3->LastHorizCursorPos = -1.0;
  v3->LastClickTime = 0;
  *(_QWORD *)&v3->CursorRect.Value.x1 = 0i64;
  *(_QWORD *)&v3->CursorRect.Value.x2 = 0i64;
  *(_QWORD *)&v3->ActiveSelectionBkColor = -16777216i64;
  *(_QWORD *)&v3->InactiveSelectionBkColor = -8355712i64;
  Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v3);
  v4 = (Scaleform::Render::RenderBuffer *)v2->pEditorKit.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v2->pEditorKit.pObject = (Scaleform::Render::Text::EditorKitBase *)&v3->vfptr;
}

// File Line: 44
// RVA: 0x8A4290
void __fastcall Scaleform::GFx::Text::EditorKit::~EditorKit(Scaleform::GFx::Text::EditorKit *this)
{
  Scaleform::GFx::Text::EditorKit *v1; // rbx
  Scaleform::GFx::Text::EditorKit::RestrictParams *v2; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::Render::RenderBuffer *v4; // rcx
  Scaleform::Render::RenderBuffer *v5; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Text::EditorKit::`vftable';
  v2 = this->pRestrict.pObject;
  if ( v2 )
  {
    if ( v1->pRestrict.Owner )
    {
      v1->pRestrict.Owner = 0;
      Scaleform::GFx::Text::EditorKit::RestrictParams::`scalar deleting destructor'(v2, 1u);
    }
    v1->pRestrict.pObject = 0i64;
  }
  v1->pRestrict.Owner = 0;
  v3 = (Scaleform::Render::RenderBuffer *)v1->pKeyMap.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v4 = (Scaleform::Render::RenderBuffer *)v1->pClipboard.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v5 = (Scaleform::Render::RenderBuffer *)v1->pDocView.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::EditorKitBase::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 48
// RVA: 0x906AB0
void __fastcall Scaleform::GFx::Text::EditorKit::SetCursorPos(Scaleform::GFx::Text::EditorKit *this, unsigned __int64 pos, bool selectionAllowed)
{
  bool v3; // si
  unsigned __int64 v4; // rdi
  Scaleform::GFx::Text::EditorKit *v5; // rbx
  unsigned __int64 v6; // rax
  Scaleform::Render::Text::DocView *v7; // rax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v8; // rax
  unsigned __int16 v9; // cx
  unsigned __int16 v10; // cx
  Scaleform::Render::Text::DocView *v11; // rcx
  unsigned __int64 v12; // r8
  unsigned __int64 v13; // rdx
  Scaleform::Render::Text::DocView::DocumentListener *v14; // rcx
  unsigned __int64 ptextPos; // [rsp+30h] [rbp+8h]

  v3 = selectionAllowed;
  v4 = pos;
  v5 = this;
  if ( pos != -1i64 )
  {
    v6 = Scaleform::Render::Text::StyledText::GetLength((Scaleform::Render::Text::StyledText *)&this->pDocView.pObject->pDocument.pObject->vfptr);
    if ( v4 > v6 )
      v4 = v6;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Text::EditorKit *))v5->vfptr[2].__vecDelDtor)(v5) )
      v5->Flags &= 0xFFF7u;
    else
      v5->Flags |= 8u;
    v7 = v5->pDocView.pObject;
    v5->CursorTimer = 0.0;
    if ( v7->pImageSubstitutor )
    {
      v8 = Scaleform::GFx::Text::EditorKit::GetGlyphEntryAtIndex(v5, v4, &ptextPos);
      if ( v8 )
      {
        v9 = v8->LenAndFontSize;
        if ( (v9 & 0xF000) != 4096 && ptextPos != v4 )
        {
          if ( v4 < v5->CursorPos )
            v4 = ptextPos;
          else
            v4 = ptextPos + ((unsigned __int64)v9 >> 12);
        }
      }
    }
  }
  v5->CursorPos = v4;
  --v5->CursorRect.FormatCounter;
  v5->LastHorizCursorPos = -1.0;
  if ( v4 != -1i64 )
  {
    Scaleform::GFx::Text::EditorKit::ScrollToPosition(v5, v4, 1, HIBYTE(v5->Flags) & 1);
    Scaleform::Render::Text::DocView::SetDefaultTextAndParaFormat(v5->pDocView.pObject, v5->CursorPos);
  }
  v10 = v5->Flags;
  if ( ((unsigned __int8)v10 >> 1) & 1 )
  {
    if ( v3 && (((unsigned __int8)v10 >> 6) & 1 || ((unsigned __int8)v10 >> 5) & 1) )
    {
      v11 = v5->pDocView.pObject;
      v12 = v5->CursorPos;
      v13 = v11->BeginSelection;
    }
    else
    {
      v13 = v5->CursorPos;
      v11 = v5->pDocView.pObject;
      v12 = v5->CursorPos;
    }
    Scaleform::Render::Text::DocView::SetSelection(v11, v13, v12, 1);
  }
  v14 = v5->pDocView.pObject->pDocumentListener.pObject;
  if ( v14 )
    v14->vfptr[10].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v14->vfptr, (unsigned int)v5);
}

// File Line: 120
// RVA: 0x8B41A0
void __fastcall Scaleform::GFx::Text::EditorKit::Advance(Scaleform::GFx::Text::EditorKit *this, long double timer)
{
  Scaleform::RefCountImplCoreVtbl *v2; // rax
  double v3; // xmm6_8
  Scaleform::GFx::Text::EditorKit *v4; // rbx
  double v5; // xmm6_8
  unsigned __int16 v6; // cx
  unsigned __int16 v7; // cx
  Scaleform::Render::Text::DocView *v8; // rax
  Scaleform::Render::Text::DocView::DocumentListener *v9; // rcx
  float v10; // xmm6_4
  Scaleform::Render::Rect<float> *v11; // rax
  Scaleform::Render::Text::DocView *v12; // rcx
  unsigned int v13; // edx
  unsigned __int64 v14; // rax
  unsigned int v15; // edi
  unsigned __int64 v16; // rax

  v2 = this->vfptr;
  v3 = timer - this->LastAdvanceTime;
  this->LastAdvanceTime = timer;
  v4 = this;
  if ( !((unsigned __int8 (*)(void))v2[2].__vecDelDtor)() )
  {
    v5 = v3 + v4->CursorTimer;
    if ( v5 <= 0.5 )
    {
      v4->CursorTimer = v5;
    }
    else
    {
      v6 = v4->Flags;
      if ( !(((unsigned __int8)v6 >> 4) & 1) )
      {
        v7 = ((unsigned __int8)v6 >> 3) & 1 ? v6 & 0xFFF7 : v6 | 8;
        v8 = v4->pDocView.pObject;
        v4->Flags = v7;
        v9 = v8->pDocumentListener.pObject;
        if ( v9 )
          ((void (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::GFx::Text::EditorKit *, _QWORD))v9->vfptr[11].__vecDelDtor)(
            v9,
            v4,
            (LOBYTE(v4->Flags) >> 3) & 1);
      }
      v4->CursorTimer = 0.0;
      v4->Flags &= 0xFFEFu;
    }
  }
  if ( (LOBYTE(v4->Flags) >> 5) & 1 )
  {
    v10 = v4->LastMousePos.y;
    v11 = Scaleform::Render::Text::DocView::GetViewRect(v4->pDocView.pObject);
    v12 = v4->pDocView.pObject;
    if ( v10 > v11->y1 )
    {
      if ( Scaleform::Render::Text::DocView::GetViewRect(v12)->y2 <= v4->LastMousePos.y )
      {
        v15 = Scaleform::Render::Text::DocView::GetBottomVScroll(v4->pDocView.pObject) + 1;
        if ( v15 < Scaleform::Render::Text::DocView::GetLinesCount(v4->pDocView.pObject) )
        {
          v16 = Scaleform::Render::Text::DocView::GetCursorPosInLine(v4->pDocView.pObject, v15, v4->LastMousePos.y);
          if ( v16 != v4->CursorPos )
            Scaleform::GFx::Text::EditorKit::SetCursorPos(v4, v16, (LOBYTE(v4->Flags) >> 1) & 1);
        }
      }
    }
    else
    {
      v13 = v12->mLineBuffer.Geom.FirstVisibleLinePos;
      if ( v13 )
      {
        v14 = Scaleform::Render::Text::DocView::GetCursorPosInLine(v12, v13 - 1, v10);
        if ( v14 != v4->CursorPos )
          Scaleform::GFx::Text::EditorKit::SetCursorPos(v4, v14, (LOBYTE(v4->Flags) >> 1) & 1);
      }
    }
  }
}

// File Line: 184
// RVA: 0x8B89A0
char __fastcall Scaleform::GFx::Text::EditorKit::CalcCursorRectInLineBuffer(Scaleform::GFx::Text::EditorKit *this, unsigned __int64 charIndex, Scaleform::Render::Rect<float> *pcursorRect, unsigned int *plineIndex, unsigned int *pglyphIndex, bool avoidComposStr, Scaleform::Render::Text::LineBuffer::Line::Alignment *plineAlignment)
{
  Scaleform::Render::Rect<float> *v7; // r12
  unsigned __int64 v8; // r15
  Scaleform::GFx::Text::EditorKit *v9; // rbx
  unsigned int v10; // eax
  unsigned int v11; // er13
  Scaleform::Render::Text::LineBuffer::Line *v12; // rsi
  signed __int64 v13; // rax
  unsigned __int64 v14; // r15
  unsigned int v15; // ebp
  signed int v16; // edi
  unsigned int v17; // ebx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v18; // rdx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v19; // rcx
  unsigned __int16 v20; // r8
  int v21; // eax
  unsigned int *v22; // r14
  int v23; // eax
  float v24; // xmm3_4
  int v25; // eax
  unsigned int v26; // et1
  float v27; // xmm1_4
  unsigned int v28; // et1
  float v29; // xmm2_4
  signed int v30; // eax
  Scaleform::Render::Text::LineBuffer::GlyphIterator result; // [rsp+30h] [rbp-C8h]
  unsigned int *v33; // [rsp+118h] [rbp+20h]

  v33 = plineIndex;
  v7 = pcursorRect;
  v8 = charIndex;
  v9 = this;
  Scaleform::Render::Text::DocView::ForceReformat(this->pDocView.pObject);
  v10 = Scaleform::Render::Text::DocView::GetLineIndexOfChar(v9->pDocView.pObject, v8);
  v11 = v10;
  if ( v10 == -1 )
    return 0;
  v12 = v9->pDocView.pObject->mLineBuffer.Lines.Data.Data[v10];
  if ( plineAlignment )
    *plineAlignment = (v12->MemSize >> 27) & 3;
  if ( (v12->MemSize & 0x80000000) == 0 )
  {
    v13 = v12->Data32.TextPos;
  }
  else
  {
    v13 = v12->Data32.TextPos & 0xFFFFFF;
    if ( (_DWORD)v13 == 0xFFFFFF )
      v13 = 0xFFFFFFFFi64;
  }
  v14 = v8 - v13;
  v15 = 0;
  v16 = 0;
  Scaleform::Render::Text::LineBuffer::Line::Begin(v12, &result);
  v17 = 0;
  while ( 1 )
  {
    v18 = result.pEndGlyphs;
    v19 = result.pGlyphs;
    if ( !result.pGlyphs )
      break;
    if ( result.pGlyphs >= result.pEndGlyphs )
      break;
    if ( result.pGlyphs->LenAndFontSize & 0xF000 )
      break;
    v20 = result.pGlyphs->Flags;
    if ( v20 & 0x100 )
      break;
    v21 = result.pGlyphs->Advance;
    if ( ((unsigned __int8)v20 >> 6) & 1 )
      v21 = -v21;
    v16 += v21;
    ++v17;
    Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&result);
  }
  v22 = v33;
  if ( v14 )
  {
    do
    {
      if ( !v19 || v19 >= v18 )
        break;
      v23 = v19->Advance;
      if ( ((unsigned __int8)v19->Flags >> 6) & 1 )
        v23 = -v23;
      v16 += v23;
      if ( !avoidComposStr || !(((unsigned __int8)v19->Flags >> 2) & 1) )
        v15 += (unsigned int)v19->LenAndFontSize >> 12;
      ++v17;
      Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&result);
      v18 = result.pEndGlyphs;
      v19 = result.pGlyphs;
    }
    while ( v15 < v14 );
    v22 = v33;
  }
  v24 = 0.0;
  if ( v19 && v19 < v18 )
  {
    v25 = v19->Advance;
    if ( (LOBYTE(v19->Flags) >> 6) & 1 )
      v25 = -v25;
    v24 = (float)v25;
  }
  v26 = v12->MemSize;
  v27 = (float)v12->Data32.OffsetX + (float)v16;
  v7->x1 = v27;
  v28 = v12->MemSize;
  v29 = (float)v12->Data32.OffsetY;
  v7->y1 = v29;
  v7->x2 = v27 + v24;
  if ( (v12->MemSize & 0x80000000) == 0 )
    v30 = v12->Data32.Height;
  else
    v30 = v12->Data8.Height;
  v7->y2 = (float)v30 + v29;
  if ( v22 )
    *v22 = v11;
  if ( pglyphIndex )
    *pglyphIndex = v17;
  if ( result.pImage.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pImage.pObject->vfptr);
  if ( result.pFontHandle.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pFontHandle.pObject);
  return 1;
}

// File Line: 242
// RVA: 0x8B8C10
__int64 __fastcall Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(Scaleform::GFx::Text::EditorKit *this, unsigned __int64 charIndex, Scaleform::Render::Rect<float> *pcursorRect, unsigned int *plineIndex, unsigned int *pglyphIndex, bool avoidComposStr, Scaleform::Render::Text::LineBuffer::Line::Alignment *plineAlignment)
{
  Scaleform::Render::Rect<float> *v7; // rdi
  Scaleform::GFx::Text::EditorKit *v8; // rbp
  unsigned __int8 v9; // si
  Scaleform::Render::Text::DocView *v10; // rcx
  signed int v11; // ebx
  signed int v12; // eax
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  Scaleform::Render::Rect<float> *v19; // rax
  Scaleform::Render::Text::DocView *v20; // rcx
  float v21; // xmm6_4
  float v22; // xmm5_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm1_4
  float v26; // xmm2_4

  v7 = pcursorRect;
  v8 = this;
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
    v10 = v8->pDocView.pObject;
    v11 = v10->mLineBuffer.Geom.HScrollOffset;
    v12 = Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(&v10->mLineBuffer);
    LODWORD(v13) = COERCE_UNSIGNED_INT((float)v11) ^ _xmm[0];
    v14 = v13 + v7->x1;
    v15 = v13 + v7->x2;
    LODWORD(v16) = COERCE_UNSIGNED_INT((float)v12) ^ _xmm[0];
    v7->x1 = v14;
    v7->x2 = v15;
    v17 = v16 + v7->y1;
    v18 = v16 + v7->y2;
    v7->y1 = v17;
    v7->y2 = v18;
    v19 = Scaleform::Render::Text::DocView::GetViewRect(v8->pDocView.pObject);
    v20 = v8->pDocView.pObject;
    v21 = (float)(v20->mLineBuffer.Geom.VisibleRect.y1 - v19->y1) + v7->y1;
    v22 = (float)(v20->mLineBuffer.Geom.VisibleRect.x1 - v19->x1) + v7->x1;
    v7->y1 = v21;
    v7->x1 = v22;
    v23 = (float)(v8->pDocView.pObject->mLineBuffer.Geom.VisibleRect.x1 - v19->x1) + v7->x2;
    v24 = (float)(v8->pDocView.pObject->mLineBuffer.Geom.VisibleRect.y1 - v19->y1) + v7->y2;
    v7->y2 = v24;
    v7->x2 = v23;
    v25 = v19->x1;
    v26 = v19->y1;
    v7->x1 = v19->x1 + v22;
    v7->y1 = v21 + v26;
    v7->x2 = v25 + v23;
    v7->y2 = v24 + v26;
  }
  return v9;
}

// File Line: 257
// RVA: 0x8D9520
Scaleform::Render::Text::LineBuffer::GlyphEntry *__fastcall Scaleform::GFx::Text::EditorKit::GetGlyphEntryAtIndex(Scaleform::GFx::Text::EditorKit *this, unsigned __int64 charIndex, unsigned __int64 *ptextPos)
{
  unsigned __int64 *v3; // r15
  unsigned __int64 v4; // r14
  Scaleform::GFx::Text::EditorKit *v5; // rbx
  unsigned int v6; // eax
  Scaleform::Render::Text::LineBuffer::Line *v7; // rax
  unsigned int v8; // edi
  unsigned __int64 v9; // r14
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v10; // rbp
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v11; // rcx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v12; // rax
  unsigned int v13; // ebx
  unsigned int v14; // esi
  Scaleform::Render::Text::LineBuffer::GlyphIterator result; // [rsp+30h] [rbp-B8h]

  v3 = ptextPos;
  v4 = charIndex;
  v5 = this;
  v6 = Scaleform::Render::Text::DocView::GetLineIndexOfChar(this->pDocView.pObject, charIndex);
  if ( v6 == -1 )
    return 0i64;
  v7 = Scaleform::Render::Text::LineBuffer::GetLine(&v5->pDocView.pObject->mLineBuffer, v6);
  if ( !v7 )
    return 0i64;
  v8 = v7->Data32.TextPos;
  if ( (v7->MemSize & 0x80000000) != 0 )
  {
    v8 &= 0xFFFFFFu;
    if ( v8 == 0xFFFFFF )
      v8 = -1;
  }
  v9 = v4 - v8;
  Scaleform::Render::Text::LineBuffer::Line::Begin(v7, &result);
  v10 = 0i64;
  while ( 1 )
  {
    v11 = result.pEndGlyphs;
    v12 = result.pGlyphs;
    if ( !result.pGlyphs
      || result.pGlyphs >= result.pEndGlyphs
      || result.pGlyphs->LenAndFontSize & 0xF000
      || result.pGlyphs->Flags & 0x100 )
    {
      break;
    }
    Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&result);
  }
  v13 = 0;
  v14 = 0;
  while ( 1 )
  {
    v8 += v13;
    if ( !v12 )
      break;
    if ( v12 >= v11 )
      break;
    v10 = v12;
    v13 = (unsigned int)v12->LenAndFontSize >> 12;
    v14 += v13;
    Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&result);
    if ( v14 > v9 )
      break;
    v11 = result.pEndGlyphs;
    v12 = result.pGlyphs;
  }
  if ( v3 )
    *v3 = v8;
  if ( result.pImage.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pImage.pObject->vfptr);
  if ( result.pFontHandle.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pFontHandle.pObject);
  return v10;
}

// File Line: 297
// RVA: 0x919090
void __fastcall Scaleform::GFx::Text::EditorKit::UpdateWideCursor(Scaleform::GFx::Text::EditorKit *this)
{
  Scaleform::GFx::Text::EditorKit *v1; // rbx
  Scaleform::Render::Text::Highlighter *v2; // rax
  Scaleform::Render::Text::Highlighter *v3; // rdi
  Scaleform::Render::Text::HighlightDesc *v4; // rax
  Scaleform::Render::Text::HighlightDesc *v5; // rdx
  bool v6; // r8
  unsigned __int64 v7; // rcx
  Scaleform::Render::Text::HighlightDesc desc; // [rsp+20h] [rbp-48h]

  v1 = this;
  if ( !((unsigned __int8 (*)(void))this->vfptr[2].__vecDelDtor)() && v1->Flags & 0x100 )
  {
    v2 = Scaleform::Render::Text::DocView::CreateHighlighterManager(v1->pDocView.pObject);
    v3 = v2;
    v4 = Scaleform::Render::Text::Highlighter::GetHighlighterPtr(v2, 0x7FFFFFFEu);
    v5 = v4;
    if ( v4 )
    {
      v6 = v4->Length != 0;
    }
    else
    {
      desc.AdjStartPos = 0i64;
      desc.GlyphNum = 0i64;
      desc.Info.UnderlineColor.Raw = 0;
      desc.StartPos = 0i64;
      desc.Length = 0i64;
      desc.Offset = 0i64;
      desc.Id = 2147483646;
      *(_QWORD *)&desc.Info.BackgroundColor.Channels.Blue = -16777216i64;
      desc.Info.Flags = 24;
      v5 = Scaleform::Render::Text::Highlighter::CreateHighlighter(v3, &desc);
      v6 = 0;
    }
    v7 = v1->CursorPos;
    if ( v5->StartPos != v7 || v6 != ((LOBYTE(v1->Flags) >> 3) & 1) )
    {
      v5->StartPos = v7;
      v5->Length = (v1->Flags >> 3) & 1;
      Scaleform::Render::Text::DocView::UpdateHighlight(v1->pDocView.pObject, v5);
    }
  }
}

// File Line: 350
// RVA: 0x8B0780
void __fastcall Scaleform::GFx::Text::EditorKit::AddDrawCursorInfo(Scaleform::GFx::Text::EditorKit *this, Scaleform::Render::TextLayout::Builder *bld)
{
  Scaleform::Render::TextLayout::Builder *v2; // r14
  Scaleform::GFx::Text::EditorKit *v3; // rbx
  unsigned __int16 v4; // cx
  unsigned int v5; // esi
  unsigned __int16 v6; // cx
  unsigned __int64 v7; // rdx
  float v8; // xmm6_4
  float v9; // xmm7_4
  Scaleform::Render::Text::TextFormat *v10; // rax
  Scaleform::Render::Text::Highlighter *v11; // rcx
  float v12; // xmm0_4
  float v13; // xmm1_4
  unsigned __int16 v14; // cx
  float v15; // xmm1_4
  Scaleform::Render::Text::DocView *v16; // rdi
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm6_4
  signed int v20; // eax
  float v21; // xmm2_4
  float v22; // xmm5_4
  float v23; // xmm1_4
  float v24; // xmm4_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm2_4
  float v31; // xmm5_4
  bool v32; // al
  unsigned int v33; // er8
  Scaleform::Render::Rect<float> r; // [rsp+40h] [rbp-59h]
  Scaleform::Render::Rect<float> pcursorRect; // [rsp+50h] [rbp-49h]
  Scaleform::Render::Text::HighlighterPosIterator result; // [rsp+60h] [rbp-39h]
  unsigned int plineIndex; // [rsp+100h] [rbp+67h]
  unsigned int pglyphIndex; // [rsp+110h] [rbp+77h]

  v2 = bld;
  v3 = this;
  if ( !((unsigned __int8 (*)(void))this->vfptr[2].__vecDelDtor)() )
  {
    v4 = v3->Flags;
    if ( (v4 >> 10) & 1 )
    {
      if ( v4 & 0x100 )
      {
        Scaleform::GFx::Text::EditorKit::UpdateWideCursor(v3);
      }
      else if ( ((unsigned __int8)v4 >> 3) & 1 )
      {
        v5 = -1;
        v6 = v3->pDocView.pObject->FormatCounter;
        plineIndex = -1;
        if ( v3->CursorRect.FormatCounter != v6 )
        {
          v7 = v3->CursorPos;
          pcursorRect = 0i64;
          if ( Scaleform::GFx::Text::EditorKit::CalcCursorRectInLineBuffer(
                 v3,
                 v7,
                 &pcursorRect,
                 &plineIndex,
                 &pglyphIndex,
                 0,
                 0i64) )
          {
            v8 = pcursorRect.x1;
            v9 = pcursorRect.x1;
            v10 = v3->pDocView.pObject->pDocument.pObject->pDefaultTextFormat.pObject;
            if ( v10 && v10->PresentMask & 1 )
              v3->CursorColor.Raw = v10->ColorV;
            v11 = &v3->pDocView.pObject->pHighlight->HighlightManager;
            if ( v11 )
            {
              Scaleform::Render::Text::Highlighter::GetPosIterator(v11, &result, v3->CursorPos, 0xFFFFFFFFFFFFFFFFui64);
              if ( result.CurDesc.Info.Flags & 0x10 )
                v3->CursorColor.Raw = result.CurDesc.Info.TextColor.Raw;
            }
          }
          else
          {
            pcursorRect = 0i64;
            LODWORD(v9) = 0i64 >> 63;
            v8 = 0.0;
          }
          v12 = pcursorRect.y1;
          v13 = pcursorRect.y2;
          v5 = plineIndex;
          v14 = v3->pDocView.pObject->FormatCounter;
          v3->CursorRect.Value.x2 = v9;
          v3->CursorRect.Value.x1 = v8;
          v3->CursorRect.Value.y1 = v12;
          v3->CursorRect.Value.y2 = v13;
          v3->CursorRect.FormatCounter = v14;
        }
        v15 = v3->CursorRect.Value.y1;
        v16 = v3->pDocView.pObject;
        r.x1 = v3->CursorRect.Value.x1;
        v17 = v3->CursorRect.Value.x2;
        r.y1 = v15;
        v18 = v3->CursorRect.Value.y2;
        r.x2 = v17;
        r.y2 = v18;
        LODWORD(v19) = COERCE_UNSIGNED_INT((float)(signed int)v16->mLineBuffer.Geom.HScrollOffset) ^ _xmm[0];
        v20 = Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(&v16->mLineBuffer);
        v21 = r.x1 + v19;
        v22 = v17 + v19;
        r.x1 = v21;
        r.x2 = v22;
        LODWORD(v23) = COERCE_UNSIGNED_INT((float)v20) ^ _xmm[0];
        v24 = r.y1 + v23;
        v25 = r.y2 + v23;
        r.y1 = v24;
        r.y2 = v25;
        v26 = v16->mLineBuffer.Geom.VisibleRect.y1;
        v27 = v16->mLineBuffer.Geom.VisibleRect.x1;
        v28 = v25 + v26;
        v29 = v24 + v26;
        v30 = v21 + v27;
        v31 = v22 + v27;
        r.y1 = v29;
        r.x1 = v30;
        r.x2 = v31;
        r.y2 = v28;
        if ( v28 > v16->mLineBuffer.Geom.VisibleRect.y2 )
        {
          if ( v5 == -1 )
            v5 = Scaleform::Render::Text::DocView::GetLineIndexOfChar(v3->pDocView.pObject, v3->CursorPos);
          v32 = Scaleform::Render::Text::LineBuffer::IsLineVisible(&v3->pDocView.pObject->mLineBuffer, v5);
          v31 = r.x2;
          v29 = r.y1;
          v30 = r.x1;
          if ( v32 )
          {
            v28 = v16->mLineBuffer.Geom.VisibleRect.y2;
            r.y2 = v16->mLineBuffer.Geom.VisibleRect.y2;
          }
          else
          {
            v28 = r.y2;
          }
        }
        if ( v31 <= v16->mLineBuffer.Geom.VisibleRect.x2
          && v28 <= v16->mLineBuffer.Geom.VisibleRect.y2
          && v30 >= v16->mLineBuffer.Geom.VisibleRect.x1
          && v29 >= v16->mLineBuffer.Geom.VisibleRect.y1 )
        {
          v33 = v3->CursorColor.Raw;
          r.x2 = v30 + 20.0;
          Scaleform::Render::TextLayout::Builder::AddCursor(v2, &r, v33);
        }
      }
    }
  }
}

// File Line: 438
// RVA: 0x901150
void __fastcall Scaleform::GFx::Text::EditorKit::ResetBlink(Scaleform::GFx::Text::EditorKit *this, bool state, bool blocked)
{
  bool v3; // si
  bool v4; // di
  Scaleform::GFx::Text::EditorKit *v5; // rbx

  v3 = blocked;
  v4 = state;
  v5 = this;
  if ( ((unsigned __int8 (*)(void))this->vfptr[2].__vecDelDtor)() || !v4 )
    v5->Flags &= 0xFFF7u;
  else
    v5->Flags |= 8u;
  v5->CursorTimer = 0.0;
  if ( v3 )
    v5->Flags |= 0x10u;
}

// File Line: 460
// RVA: 0x904840
bool __fastcall Scaleform::GFx::Text::EditorKit::ScrollToPosition(Scaleform::GFx::Text::EditorKit *this, unsigned __int64 pos, bool avoidComposStr, bool wideCursor)
{
  bool v4; // bl
  unsigned __int64 v5; // r14
  Scaleform::GFx::Text::EditorKit *v6; // rsi
  bool v7; // di
  Scaleform::Render::Text::DocView *v8; // rcx
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  signed int v12; // ebx
  signed int v13; // edx
  signed int v14; // ebp
  bool v15; // sf
  float v16; // xmm0_4
  Scaleform::Render::Text::DocView *v17; // rcx
  Scaleform::Render::Text::DocView *v18; // rcx
  unsigned int v19; // ebx
  int v21; // [rsp+40h] [rbp-38h]
  unsigned int vscroll; // [rsp+44h] [rbp-34h]
  Scaleform::Render::Rect<float> pCharRect; // [rsp+50h] [rbp-28h]

  v4 = wideCursor;
  pCharRect = 0i64;
  v5 = pos;
  v6 = this;
  v7 = 0;
  if ( !(unsigned __int8)Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(
                           this,
                           pos,
                           &pCharRect,
                           &vscroll,
                           0i64,
                           avoidComposStr,
                           (Scaleform::Render::Text::LineBuffer::Line::Alignment *)&v21) )
    return v7;
  v8 = v6->pDocView.pObject;
  v9 = pCharRect.x1;
  v10 = v4 ? pCharRect.x2 : pCharRect.x1 + 20.0;
  v11 = v8->mLineBuffer.Geom.VisibleRect.x2;
  if ( v11 >= v10
    && pCharRect.y2 <= v8->mLineBuffer.Geom.VisibleRect.y2
    && pCharRect.x1 >= v8->mLineBuffer.Geom.VisibleRect.x1
    && pCharRect.y1 >= v8->mLineBuffer.Geom.VisibleRect.y1 )
  {
    return v7;
  }
  if ( v8->AlignProps & 0x30 || v8->Flags & 1 )
    return v7;
  v12 = v8->mLineBuffer.Geom.HScrollOffset;
  v13 = 1200;
  if ( v21 )
    v13 = 0;
  v14 = v8->mLineBuffer.Geom.HScrollOffset;
  if ( v10 <= v11 )
  {
    v16 = v8->mLineBuffer.Geom.VisibleRect.x1;
    if ( pCharRect.x1 >= v16 )
      goto LABEL_23;
    v12 -= v13 + (signed int)(float)(v16 - pCharRect.x1);
    v15 = v12 < 0;
  }
  else
  {
    pCharRect = 0i64;
    v12 += (signed int)(float)((float)(v9 - v11) + (float)v13);
    if ( v5
      && Scaleform::Render::Text::DocView::GetExactCharBoundaries(v8, &pCharRect, v5 - 1)
      && (signed int)(float)(pCharRect.x1 - 40.0) < v12 )
    {
      v12 = (signed int)(float)(pCharRect.x1 - 40.0);
    }
    v15 = v12 < 0;
  }
  if ( v15 )
    v12 = 0;
LABEL_23:
  v17 = v6->pDocView.pObject;
  if ( !(v17->Flags & 8) || v12 < v14 )
    v7 = Scaleform::Render::Text::DocView::SetHScrollOffset(v17, v12);
  v18 = v6->pDocView.pObject;
  v19 = vscroll;
  if ( vscroll < v18->mLineBuffer.Geom.FirstVisibleLinePos )
    return v7 | Scaleform::Render::Text::DocView::SetVScrollOffset(v18, vscroll);
  if ( v19 > Scaleform::Render::Text::DocView::GetBottomVScroll(v18) )
    return v7 | Scaleform::Render::Text::DocView::SetBottomVScroll(v6->pDocView.pObject, v19);
  return v7;
}

// File Line: 528
// RVA: 0x8EE1E0
int Scaleform::GFx::Text::EditorKit::OnMouseDown(...)
{
  Scaleform::GFx::Text::EditorKit *v4; // rsi
  __m128 v5; // xmm6
  Scaleform::Render::Rect<float> *v6; // rax
  __m128 v7; // xmm7
  signed int v8; // edx
  signed int v9; // ecx
  unsigned __int64 v10; // rax
  char v11; // r14
  char v12; // di
  unsigned __int64 v13; // rcx
  unsigned __int16 v14; // dx
  Scaleform::Render::Text::DocView *v15; // rcx
  unsigned __int64 v16; // rax
  unsigned __int64 v17; // rbx
  unsigned __int16 v18; // dx
  unsigned __int16 v19; // dx
  Scaleform::Render::Text::Paragraph *v20; // r13
  unsigned __int64 v21; // rax
  unsigned __int64 v22; // rdi
  unsigned __int64 v23; // rbp
  unsigned __int64 v24; // r15
  wchar_t *v25; // r12
  wchar_t *v26; // rbx
  wchar_t v27; // r14
  wchar_t v28; // r10
  unsigned __int64 v29; // r8
  int v30; // er9
  int v31; // eax
  int v32; // er9
  int v33; // eax
  unsigned __int64 v34; // rbx
  unsigned __int64 v35; // rdi
  unsigned __int64 pindexInParagraph; // [rsp+20h] [rbp-68h]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator result; // [rsp+28h] [rbp-60h]

  if ( buttons & 1 )
  {
    v4 = this;
    v5 = (__m128)y;
    v7 = (__m128)x;
    v6 = Scaleform::Render::Text::DocView::GetViewRect(this->pDocView.pObject);
    v7.m128_f32[0] = *(float *)&x - v6->x1;
    v8 = (signed int)v7.m128_f32[0];
    if ( (signed int)v7.m128_f32[0] != 0x80000000 && (float)v8 != v7.m128_f32[0] )
      v7.m128_f32[0] = (float)(v8 - (_mm_movemask_ps(_mm_unpacklo_ps(v7, v7)) & 1));
    v5.m128_f32[0] = *(float *)&y - v6->y1;
    v9 = (signed int)v5.m128_f32[0];
    if ( (signed int)v5.m128_f32[0] != 0x80000000 && (float)v9 != v5.m128_f32[0] )
      v5.m128_f32[0] = (float)(v9 - (_mm_movemask_ps(_mm_unpacklo_ps(v5, v5)) & 1));
    v10 = Scaleform::Timer::GetTicks();
    v11 = 0;
    v12 = 0;
    v13 = (unsigned __int64)((v10 * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)
                           + ((unsigned __int64)(v10 - (v10 * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)) >> 1)) >> 9;
    if ( v7.m128_f32[0] != v4->LastMousePos.x
      || v5.m128_f32[0] != v4->LastMousePos.y
      || (unsigned int)v13 > v4->LastClickTime + 300 )
    {
      v4->Flags &= 0xFDFFu;
    }
    else
    {
      v14 = v4->Flags;
      if ( (v14 >> 9) & 1 )
        v12 = 1;
      else
        v11 = 1;
      v4->Flags = v14 | 0x200;
    }
    v4->LastClickTime = v13;
    v15 = v4->pDocView.pObject;
    LODWORD(v4->LastMousePos.x) = v7.m128_i32[0];
    LODWORD(v4->LastMousePos.y) = v5.m128_i32[0];
    v16 = Scaleform::Render::Text::DocView::GetCursorPosAtPoint(v15, v7.m128_f32[0], v5.m128_f32[0]);
    v17 = v16;
    if ( v16 != -1i64 )
    {
      Scaleform::GFx::Text::EditorKit::SetCursorPos(v4, v16, (LOBYTE(v4->Flags) >> 1) & 1);
      v18 = v4->Flags;
      if ( ((unsigned __int8)v18 >> 1) & 1 )
      {
        if ( !(((unsigned __int8)v18 >> 5) & 1) )
        {
          v19 = v18 | 0x20;
          v4->Flags = v19;
          if ( v11 || v12 )
          {
            Scaleform::Render::Text::StyledText::GetParagraphByIndex(
              (Scaleform::Render::Text::StyledText *)&v4->pDocView.pObject->pDocument.pObject->vfptr,
              &result,
              v17,
              &pindexInParagraph);
            if ( result.pArray && result.CurIndex >= 0 && result.CurIndex < SLODWORD(result.pArray->Data.Size) )
            {
              v20 = result.pArray->Data.Data[result.CurIndex].pPara;
              v21 = Scaleform::Render::Text::Paragraph::GetLength(v20);
              v22 = pindexInParagraph;
              v23 = pindexInParagraph;
              v24 = v21;
              if ( v11 )
              {
                v25 = v20->Text.pText;
                if ( pindexInParagraph )
                {
                  v26 = &v25[pindexInParagraph - 1];
                  do
                  {
                    v27 = *v26;
                    if ( (unsigned int)Scaleform::SFiswspace(*v26) )
                      break;
                    if ( !Scaleform::SFiswalnum(v27) )
                      break;
                    --v26;
                    --v23;
                  }
                  while ( v23 );
                }
                for ( ; v22 < v24; ++v22 )
                {
                  v28 = v25[v22];
                  v29 = (unsigned __int64)v25[v22] >> 8;
                  v30 = Scaleform::UnicodeSpaceBits[v29];
                  if ( Scaleform::UnicodeSpaceBits[v29] )
                  {
                    if ( v30 == 1 )
                      break;
                    v31 = Scaleform::UnicodeSpaceBits[v30 + (((unsigned int)v28 >> 4) & 0xF)];
                    if ( _bittest(&v31, v28 & 0xF) )
                      break;
                  }
                  v32 = Scaleform::UnicodeAlnumBits[v29];
                  if ( !Scaleform::UnicodeAlnumBits[v29] )
                    break;
                  if ( v32 != 1 )
                  {
                    v33 = Scaleform::UnicodeAlnumBits[v32 + (((unsigned int)v28 >> 4) & 0xF)];
                    if ( !_bittest(&v33, v28 & 0xF) )
                      break;
                  }
                }
              }
              else
              {
                v23 = 0i64;
                v22 = v21;
              }
              v34 = v20->StartIndex;
              v35 = v34 + v22;
              Scaleform::GFx::Text::EditorKit::SetCursorPos(v4, v35, (LOBYTE(v4->Flags) >> 1) & 1);
              Scaleform::Render::Text::DocView::SetSelection(v4->pDocView.pObject, v34 + v23, v35, 1);
            }
          }
          else if ( !(((unsigned __int8)v19 >> 6) & 1) )
          {
            Scaleform::Render::Text::DocView::SetSelection(v4->pDocView.pObject, v17, v17, 1);
          }
        }
      }
    }
  }
}

// File Line: 618
// RVA: 0x8EE840
int Scaleform::GFx::Text::EditorKit::OnMouseMove(...)
{
  Scaleform::GFx::Text::EditorKit *v3; // rbx
  __m128 v4; // xmm6
  __m128 v5; // xmm7
  Scaleform::Render::Rect<float> *v6; // rax
  signed int v7; // edx
  signed int v8; // ecx
  Scaleform::Render::Text::DocView *v9; // rcx
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rdi

  v3 = this;
  v4 = (__m128)y;
  v5 = (__m128)x;
  if ( (LOBYTE(this->Flags) >> 5) & 1 )
  {
    v6 = Scaleform::Render::Text::DocView::GetViewRect(this->pDocView.pObject);
    v5.m128_f32[0] = *(float *)&x - v6->x1;
    v7 = (signed int)v5.m128_f32[0];
    if ( (signed int)v5.m128_f32[0] != 0x80000000 && (float)v7 != v5.m128_f32[0] )
      v5.m128_f32[0] = (float)(v7 - (_mm_movemask_ps(_mm_unpacklo_ps(v5, v5)) & 1));
    v4.m128_f32[0] = *(float *)&y - v6->y1;
    v8 = (signed int)v4.m128_f32[0];
    if ( (signed int)v4.m128_f32[0] != 0x80000000 && (float)v8 != v4.m128_f32[0] )
      v4.m128_f32[0] = (float)(v8 - (_mm_movemask_ps(_mm_unpacklo_ps(v4, v4)) & 1));
    v9 = v3->pDocView.pObject;
    LODWORD(v3->LastMousePos.x) = v5.m128_i32[0];
    LODWORD(v3->LastMousePos.y) = v4.m128_i32[0];
    v10 = Scaleform::Render::Text::DocView::GetCursorPosAtPoint(v9, v5.m128_f32[0], v4.m128_f32[0]);
    v11 = v10;
    if ( v10 != -1i64 )
    {
      Scaleform::GFx::Text::EditorKit::SetCursorPos(v3, v10, (LOBYTE(v3->Flags) >> 1) & 1);
      if ( (LOBYTE(v3->Flags) >> 1) & 1 )
        Scaleform::Render::Text::DocView::SetSelection(
          v3->pDocView.pObject,
          v3->pDocView.pObject->BeginSelection,
          v11,
          1);
    }
  }
}

// File Line: 665
// RVA: 0x8ED320
__int64 __fastcall Scaleform::GFx::Text::EditorKit::OnKeyDown(Scaleform::GFx::Text::EditorKit *this, int keyCode, Scaleform::KeyModifiers *specKeysState)
{
  Scaleform::Render::Text::DocView *v3; // r14
  Scaleform::GFx::Text::EditorKit *v4; // rbx
  Scaleform::Render::Text::StyledText *v5; // rcx
  unsigned int v6; // esi
  unsigned __int64 v7; // rax
  Scaleform::Render::Text::DocView::DocumentListener *v8; // rcx
  unsigned __int64 v9; // rdi
  unsigned __int64 v10; // r12
  unsigned int v11; // ecx
  Scaleform::Render::Text::DocView *v12; // r13
  unsigned __int16 v13; // r15
  float v14; // xmm6_4
  unsigned __int64 v15; // rsi
  unsigned __int64 v16; // r14
  unsigned __int64 v17; // rax
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v18; // rax
  char v19; // r13
  unsigned int v21; // eax
  Scaleform::Render::Text::DocView *v22; // rcx
  unsigned int v23; // edx
  char v24; // r15
  char v25; // al
  unsigned int v26; // eax
  unsigned int v27; // er12
  Scaleform::Render::Text::DocView *v28; // rcx
  unsigned __int64 v29; // rax
  signed __int64 v30; // r15
  unsigned int v31; // eax
  Scaleform::Render::Text::DocView *v32; // rcx
  unsigned int v33; // edi
  unsigned __int64 v34; // rax
  signed __int64 v35; // r15
  unsigned __int64 v36; // rdx
  unsigned int v37; // eax
  Scaleform::Render::Text::DocView *v38; // rcx
  unsigned int v39; // eax
  unsigned __int64 v40; // rax
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
  bool phasNewLine; // [rsp+40h] [rbp-29h]
  unsigned int plineIndex[2]; // [rsp+48h] [rbp-21h]
  Scaleform::Render::Text::DocView *v55; // [rsp+50h] [rbp-19h]
  Scaleform::Render::Rect<float> pcursorRect; // [rsp+60h] [rbp-9h]
  unsigned int v57; // [rsp+D0h] [rbp+67h]
  int v58; // [rsp+D8h] [rbp+6Fh]
  Scaleform::KeyModifiers *specKeys; // [rsp+E0h] [rbp+77h]
  unsigned __int8 v60; // [rsp+E8h] [rbp+7Fh]

  specKeys = specKeysState;
  v58 = keyCode;
  v3 = this->pDocView.pObject;
  v4 = this;
  v5 = (Scaleform::Render::Text::StyledText *)&v3->pDocument.pObject->vfptr;
  v6 = keyCode;
  v55 = v3;
  v7 = Scaleform::Render::Text::StyledText::GetLength(v5);
  v8 = v3->pDocumentListener.pObject;
  v9 = v4->CursorPos;
  v10 = v7;
  v60 = 0;
  if ( v8 )
    v11 = ((__int64 (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::GFx::Text::EditorKit *, _QWORD))v8->vfptr[7].__vecDelDtor)(
            v8,
            v4,
            v6);
  else
    v11 = v58;
  v12 = v4->pDocView.pObject;
  v13 = v4->Flags;
  v14 = FLOAT_N1_0;
  v15 = v12->EndSelection;
  v16 = v12->EndSelection;
  LOBYTE(v57) = ((unsigned __int8)v4->Flags >> 6) & 1;
  v17 = v12->BeginSelection;
  if ( v17 < v15 )
    v15 = v12->BeginSelection;
  if ( v16 < v17 )
    v16 = v12->BeginSelection;
  if ( v4->pKeyMap.pObject
    && (v18 = Scaleform::GFx::TextKeyMap::Find(v4->pKeyMap.pObject, v11, specKeys, 0),
        (*(_QWORD *)plineIndex = v18) != 0i64) )
  {
    switch ( v18->Action )
    {
      case 2:
        if ( !(((unsigned __int8)v13 >> 1) & 1) )
          goto LABEL_12;
        goto LABEL_14;
      case 4:
        if ( v9 == -1i64 )
          v9 = v10;
        if ( v9 )
          --v9;
        v19 = v57;
        if ( !(_BYTE)v57 && v15 != v16 )
        {
          v9 = v16;
          if ( v15 < v16 )
            v9 = v15;
        }
        goto LABEL_38;
      case 5:
        if ( v9 == -1i64 )
        {
          v9 = v10;
        }
        else if ( v9 < v10 )
        {
          ++v9;
        }
        v19 = v57;
        if ( !(_BYTE)v57 && v15 != v16 )
        {
          v9 = v16;
          if ( v16 < v15 )
            v9 = v15;
        }
        goto LABEL_38;
      case 6:
        v19 = v57;
        pcursorRect = 0i64;
        if ( !(_BYTE)v57 && v15 != v16 )
        {
          v9 = v16;
          if ( v15 < v16 )
            v9 = v15;
          goto LABEL_38;
        }
        v24 = 0;
        if ( (unsigned __int8)Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(
                                v4,
                                v4->CursorPos,
                                &pcursorRect,
                                &v57,
                                0i64,
                                1,
                                0i64) )
        {
          if ( v57 )
          {
            v14 = v4->LastHorizCursorPos;
            if ( v14 < 0.0 )
              v14 = pcursorRect.x1;
            v9 = Scaleform::Render::Text::DocView::GetCursorPosInLine(v4->pDocView.pObject, v57 - 1, v14);
          }
          else
          {
            v9 = 0i64;
          }
        }
        goto LABEL_39;
      case 7:
        v19 = v57;
        pcursorRect = 0i64;
        if ( !(_BYTE)v57 && v15 != v16 )
        {
          v9 = v16;
          if ( v16 < v15 )
            v9 = v15;
          goto LABEL_38;
        }
        v24 = 0;
        if ( (unsigned __int8)Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(
                                v4,
                                v4->CursorPos,
                                &pcursorRect,
                                &v57,
                                0i64,
                                1,
                                0i64) )
        {
          v46 = v57 + 1;
          if ( v46 >= Scaleform::Render::Text::DocView::GetLinesCount(v4->pDocView.pObject) )
          {
            v9 = v10;
          }
          else
          {
            v14 = v4->LastHorizCursorPos;
            if ( v14 < 0.0 )
              v14 = pcursorRect.x1;
            v9 = Scaleform::Render::Text::DocView::GetCursorPosInLine(v4->pDocView.pObject, v46, v14);
          }
        }
        goto LABEL_39;
      case 8:
        v36 = v4->CursorPos;
        v24 = 0;
        pcursorRect = 0i64;
        if ( !(unsigned __int8)Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(
                                 v4,
                                 v36,
                                 &pcursorRect,
                                 plineIndex,
                                 0i64,
                                 1,
                                 0i64) )
          goto LABEL_46;
        v14 = v4->LastHorizCursorPos;
        if ( v14 < 0.0 )
          v14 = pcursorRect.x1;
        v37 = Scaleform::Render::Text::DocView::GetBottomVScroll(v4->pDocView.pObject);
        v38 = v4->pDocView.pObject;
        v39 = v37 - v38->mLineBuffer.Geom.FirstVisibleLinePos + 1;
        if ( plineIndex[0] >= v39 )
        {
          v40 = Scaleform::Render::Text::DocView::GetCursorPosInLine(v38, plineIndex[0] - v39, v14);
          v19 = v57;
          v9 = v40;
        }
        else
        {
          v19 = v57;
          v9 = 0i64;
        }
        goto LABEL_39;
      case 9:
        v41 = v4->CursorPos;
        v24 = 0;
        pcursorRect = 0i64;
        if ( !(unsigned __int8)Scaleform::GFx::Text::EditorKit::CalcCursorRectOnScreen(
                                 v4,
                                 v41,
                                 &pcursorRect,
                                 plineIndex,
                                 0i64,
                                 1,
                                 0i64) )
          goto LABEL_46;
        v14 = v4->LastHorizCursorPos;
        if ( v14 < 0.0 )
          v14 = pcursorRect.x1;
        v42 = Scaleform::Render::Text::DocView::GetBottomVScroll(v4->pDocView.pObject);
        v43 = v4->pDocView.pObject;
        v44 = v42 - v43->mLineBuffer.Geom.FirstVisibleLinePos + plineIndex[0] + 1;
        if ( v44 < Scaleform::Render::Text::DocView::GetLinesCount(v43) )
        {
          v45 = Scaleform::Render::Text::DocView::GetCursorPosInLine(v4->pDocView.pObject, v44, v14);
          v19 = v57;
          v9 = v45;
        }
        else
        {
          v19 = v57;
          v9 = v10;
        }
        goto LABEL_39;
      case 0xA:
        v21 = Scaleform::Render::Text::DocView::GetLineIndexOfChar(v12, v4->CursorPos);
        if ( v21 == -1 )
          goto LABEL_37;
        v22 = v4->pDocView.pObject;
        v23 = v21;
        goto LABEL_36;
      case 0xB:
        v26 = Scaleform::Render::Text::DocView::GetLineIndexOfChar(v12, v4->CursorPos);
        v27 = v26;
        if ( v26 != -1 )
        {
          v28 = v4->pDocView.pObject;
          phasNewLine = 0;
          v29 = Scaleform::Render::Text::DocView::GetLineLength(v28, v26, &phasNewLine);
          v30 = v29;
          if ( phasNewLine )
            v30 = v29 - 1;
          v9 = v30 + Scaleform::Render::Text::DocView::GetLineOffset(v4->pDocView.pObject, v27);
        }
        goto LABEL_37;
      case 0xC:
        v23 = v12->mLineBuffer.Geom.FirstVisibleLinePos;
        v22 = v12;
LABEL_36:
        v9 = Scaleform::Render::Text::DocView::GetLineOffset(v22, v23);
        goto LABEL_37;
      case 0xD:
        v31 = Scaleform::Render::Text::DocView::GetBottomVScroll(v12);
        v32 = v4->pDocView.pObject;
        v33 = v31;
        phasNewLine = 0;
        v34 = Scaleform::Render::Text::DocView::GetLineLength(v32, v31, &phasNewLine);
        v35 = v34;
        if ( phasNewLine )
          v35 = v34 - 1;
        v9 = v35 + Scaleform::Render::Text::DocView::GetLineOffset(v4->pDocView.pObject, v33);
        goto LABEL_37;
      case 0xE:
        v24 = 0;
        v9 = 0i64;
LABEL_46:
        v19 = v57;
        goto LABEL_39;
      case 0xF:
        v9 = v10;
        goto LABEL_37;
      case 0x10:
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Text::EditorKit *))v4->vfptr[2].__vecDelDtor)(v4) )
          goto LABEL_37;
        v47 = v4->pDocView.pObject;
        v4->Flags &= 0xFFBFu;
        if ( v15 != v16 )
          goto LABEL_89;
        *(_QWORD *)plineIndex = v9;
        v48 = Scaleform::Render::Text::DocView::EditCommand(v47, Cmd_BackspaceChar, plineIndex);
        v19 = v57;
        v24 = 1;
        v9 -= v48;
        goto LABEL_39;
      case 0x11:
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Text::EditorKit *))v4->vfptr[2].__vecDelDtor)(v4) )
          goto LABEL_37;
        v4->Flags &= 0xFFBFu;
        if ( v15 != v16 )
        {
          v47 = v4->pDocView.pObject;
LABEL_89:
          *(_QWORD *)&pcursorRect.x2 = v16;
          *(_QWORD *)&pcursorRect.x1 = v15;
          Scaleform::Render::Text::DocView::EditCommand(v47, Cmd_DeleteText, &pcursorRect);
          goto LABEL_90;
        }
        if ( v4->CursorPos >= v10 )
        {
LABEL_37:
          v19 = v57;
LABEL_38:
          v24 = 0;
        }
        else
        {
          v49 = v4->pDocView.pObject;
          *(_QWORD *)plineIndex = v9;
          Scaleform::Render::Text::DocView::EditCommand(v49, Cmd_DeleteChar, plineIndex);
          v19 = v57;
          v24 = 1;
        }
        goto LABEL_39;
      case 0x13:
      case 0x15:
        if ( !v4->pClipboard.pObject )
          goto LABEL_37;
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Text::EditorKit *))v4->vfptr[2].__vecDelDtor)(v4)
          || **(_DWORD **)plineIndex == 19 )
        {
          v4->Flags &= 0xFFBFu;
          Scaleform::GFx::Text::EditorKit::CopyToClipboard(v4, v15, v16, ((unsigned __int8)v4->Flags >> 2) & 1);
          goto LABEL_12;
        }
        v4->Flags &= 0xFFBFu;
        Scaleform::GFx::Text::EditorKit::CutToClipboard(v4, v15, v16, ((unsigned __int8)v4->Flags >> 2) & 1);
LABEL_90:
        v19 = v57;
        v9 = v16;
        if ( v15 < v16 )
          v9 = v15;
        v24 = 1;
LABEL_39:
        if ( v4->CursorPos == v9 )
        {
          v51 = v4->Flags;
          if ( ((unsigned __int8)v51 >> 6) & 1 || v15 == v16 )
          {
            v25 = 0;
          }
          else
          {
            Scaleform::GFx::Text::EditorKit::SetCursorPos(v4, v9, ((unsigned __int8)v51 >> 1) & 1);
            v25 = 1;
            v60 = 1;
          }
        }
        else
        {
          Scaleform::GFx::Text::EditorKit::SetCursorPos(v4, v9, (LOBYTE(v4->Flags) >> 1) & 1);
          v25 = 1;
          v60 = 1;
          v4->LastHorizCursorPos = v14;
        }
        if ( v24 )
        {
          if ( !v25 )
            Scaleform::Render::Text::DocView::SetDefaultTextAndParaFormat(v4->pDocView.pObject, v4->CursorPos);
          v52 = v55->pDocumentListener.pObject;
          if ( v52 )
            v52->vfptr[9].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v52->vfptr, (unsigned int)v4);
        }
        break;
      case 0x14:
        v50 = Scaleform::GFx::Text::EditorKit::PasteFromClipboard(v4, v15, v16, ((unsigned __int8)v13 >> 2) & 1);
        v19 = v57;
        if ( v50 == -1i64 )
          goto LABEL_38;
        v9 = v50;
        v24 = 1;
        goto LABEL_39;
      case 0x16:
        Scaleform::GFx::Text::EditorKit::SetCursorPos(v4, v10, ((unsigned __int8)v13 >> 1) & 1);
        Scaleform::Render::Text::DocView::SetSelection(v4->pDocView.pObject, 0i64, v10, 1);
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
    v4->Flags |= 0x40u;
  return v60;
}

// File Line: 1029
// RVA: 0x8EC250
char __fastcall Scaleform::GFx::Text::EditorKit::OnChar(Scaleform::GFx::Text::EditorKit *this, unsigned int wcharCode)
{
  unsigned int v2; // ebp
  Scaleform::GFx::Text::EditorKit *v3; // rdi
  Scaleform::GFx::Text::EditorKit::RestrictParams *v4; // rbx
  signed __int64 v5; // rax
  char v6; // si
  unsigned __int64 v7; // rcx
  bool v8; // cf
  char v9; // al
  int v10; // ebx
  unsigned __int16 v11; // ax
  Scaleform::GFx::Text::EditorKit::RestrictParams *v12; // rbx
  signed __int64 v13; // rax
  unsigned __int64 v14; // rcx
  char result; // al
  unsigned __int64 v16; // rbx
  Scaleform::Render::Text::DocView *v17; // r13
  char v18; // r12
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // r14
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
  __int64 v32; // rax
  unsigned __int8 v33; // al
  Scaleform::Render::Text::DocView::DocumentListener *v34; // rcx
  unsigned __int64 command; // [rsp+20h] [rbp-48h]
  unsigned __int64 v36; // [rsp+28h] [rbp-40h]
  __int16 v37; // [rsp+30h] [rbp-38h]

  v2 = wcharCode;
  v3 = this;
  if ( wcharCode && !((LOBYTE(this->Flags) >> 5) & 1) )
  {
    v4 = this->pRestrict.pObject;
    if ( !v4 )
      goto LABEL_25;
    v5 = Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::FindRangeIndex(
           &v4->RestrictRanges,
           (unsigned __int16)wcharCode);
    v6 = 0;
    if ( v5 == -1 )
      goto LABEL_11;
    if ( v5 >= 0 )
    {
      v7 = v4->RestrictRanges.Ranges.Data.Size;
      if ( v5 >= v7 )
        v5 = v7 - 1;
      if ( v5 < 0 )
        goto LABEL_11;
    }
    else
    {
      v5 = 0i64;
    }
    v8 = v5 < v4->RestrictRanges.Ranges.Data.Size;
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
      v12 = v3->pRestrict.pObject;
      LOWORD(v2) = v11;
      if ( !v12 )
        goto LABEL_25;
      v13 = Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::FindRangeIndex(
              &v3->pRestrict.pObject->RestrictRanges,
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
          goto LABEL_23;
        }
      }
LABEL_23:
      v6 = 1;
LABEL_24:
      result = v6 == 0;
      if ( v6 )
        return result;
LABEL_25:
      v16 = v3->CursorPos;
      v17 = v3->pDocView.pObject;
      v18 = 0;
      v19 = v17->BeginSelection;
      v20 = v17->EndSelection;
      v21 = v17->EndSelection;
      if ( v19 < v20 )
        v20 = v17->BeginSelection;
      if ( v21 < v19 )
        v21 = v17->BeginSelection;
      v22 = 0;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Text::EditorKit *))v3->vfptr[2].__vecDelDtor)(v3) )
        return v18;
      if ( (_WORD)v2 == 13 )
      {
        v27 = v3->pDocView.pObject;
        if ( !(v27->Flags & 4) )
          goto LABEL_51;
        v3->Flags &= 0xFFBFu;
        v28 = v27->pDocument.pObject;
        if ( v20 == v21 )
        {
          v29 = (v28->RTFlags & 2) == 0;
          v30 = 10;
          if ( !v29 )
            v30 = 13;
          v31 = v30;
          v32 = v3->CursorPos;
          LOWORD(v36) = v31;
          command = v32;
          Scaleform::Render::Text::DocView::EditCommand(v27, 0, &command);
        }
        else
        {
          v29 = (v28->RTFlags & 2) == 0;
          v33 = 10;
          if ( !v29 )
            v33 = 13;
          command = v20;
          v36 = v21;
          v37 = v33;
          Scaleform::Render::Text::DocView::EditCommand(v27, Cmd_ReplaceTextByChar, &command);
          v16 = v21;
          if ( v20 < v21 )
            v16 = v20;
        }
        ++v16;
      }
      else
      {
        if ( (unsigned __int16)v2 < 0x20u )
          return v18;
        if ( v20 != v21 )
          goto LABEL_62;
        if ( SLOBYTE(v3->Flags) < 0 )
          ++v21;
        if ( v20 != v21 )
        {
LABEL_62:
          v24 = v3->pDocView.pObject;
          command = v20;
          v36 = v21;
          v37 = v2;
          v25 = Scaleform::Render::Text::DocView::EditCommand(v24, Cmd_ReplaceTextByChar, &command);
          v26 = v21;
          if ( v20 < v21 )
            v26 = v20;
          v16 = v26 + v25;
        }
        else
        {
          v23 = v3->pDocView.pObject;
          command = v3->CursorPos;
          LOWORD(v36) = v2;
          v16 += Scaleform::Render::Text::DocView::EditCommand(v23, 0, &command);
        }
      }
      v22 = 1;
LABEL_51:
      if ( v3->CursorPos != v16 || v20 != v16 || v21 != v16 )
      {
        Scaleform::GFx::Text::EditorKit::SetCursorPos(v3, v16, 0);
        v18 = 1;
      }
      if ( v22 )
      {
        v34 = v17->pDocumentListener.pObject;
        if ( v34 )
          v34->vfptr[9].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v34->vfptr, (unsigned int)v3);
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
void __fastcall Scaleform::GFx::Text::EditorKit::OnDocumentChanged(Scaleform::GFx::Text::EditorKit *this, unsigned int notifyMask)
{
  Scaleform::GFx::Text::EditorKit *v2; // rbx
  unsigned __int64 v3; // rdx

  v2 = this;
  if ( !(notifyMask & 0x102) )
  {
    if ( this->CursorPos <= Scaleform::Render::Text::StyledText::GetLength((Scaleform::Render::Text::StyledText *)&this->pDocView.pObject->pDocument.pObject->vfptr) )
      return;
    v3 = Scaleform::Render::Text::StyledText::GetLength((Scaleform::Render::Text::StyledText *)&v2->pDocView.pObject->pDocument.pObject->vfptr);
    goto LABEL_7;
  }
  if ( !((unsigned __int8 (*)(void))this->vfptr[2].__vecDelDtor)() || (LOBYTE(v2->Flags) >> 1) & 1 )
  {
    v3 = 0i64;
LABEL_7:
    Scaleform::GFx::Text::EditorKit::SetCursorPos(v2, v3, (LOBYTE(v2->Flags) >> 1) & 1);
  }
}

// File Line: 1149
// RVA: 0x8EE070
void __fastcall Scaleform::GFx::Text::EditorKit::OnKillFocus(Scaleform::GFx::Text::EditorKit *this)
{
  Scaleform::GFx::Text::EditorKit *v1; // rbx

  v1 = this;
  Scaleform::Render::Text::DocView::SetSelectionTextColor(this->pDocView.pObject, this->InactiveSelectionTextColor);
  Scaleform::Render::Text::DocView::SetSelectionBackgroundColor(v1->pDocView.pObject, v1->InactiveSelectionBkColor);
  v1->Flags &= 0xFB9Fu;
}

// File Line: 1158
// RVA: 0x90BC60
void __fastcall Scaleform::GFx::Text::EditorKit::SetSelection(Scaleform::GFx::Text::EditorKit *this, unsigned __int64 startPos, unsigned __int64 endPos)
{
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rsi
  Scaleform::GFx::Text::EditorKit *v5; // rbx

  v3 = endPos;
  v4 = startPos;
  v5 = this;
  if ( !((unsigned __int8 (*)(void))this->vfptr[2].__vecDelDtor)() || (LOBYTE(v5->Flags) >> 1) & 1 )
    Scaleform::GFx::Text::EditorKit::SetCursorPos(v5, v3, (LOBYTE(v5->Flags) >> 1) & 1);
  Scaleform::Render::Text::DocView::SetSelection(v5->pDocView.pObject, v4, v3, (LOBYTE(v5->Flags) >> 1) & 1);
}

// File Line: 1167
// RVA: 0x8BE4E0
void __fastcall Scaleform::GFx::Text::EditorKit::CopyToClipboard(Scaleform::GFx::Text::EditorKit *this, unsigned __int64 startPos, unsigned __int64 endPos, bool useRichClipboard)
{
  bool v4; // bp
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // rdi
  Scaleform::GFx::Text::EditorKit *v7; // rsi
  Scaleform::Render::Text::StyledText *v8; // rax
  Scaleform::RefCountNTSImpl *v9; // r14
  unsigned __int64 v10; // rdi
  wchar_t *v11; // rbp
  Scaleform::GFx::Clipboard *v12; // rbx
  wchar_t *v13; // rdx
  Scaleform::WStringBuffer pBuffer; // [rsp+28h] [rbp-40h]

  v4 = useRichClipboard;
  v5 = endPos;
  v6 = startPos;
  v7 = this;
  if ( this->pClipboard.pObject && !(this->pDocView.pObject->Flags & 0x10) )
  {
    if ( endPos < startPos )
    {
      v6 = endPos;
      v5 = startPos;
    }
    pBuffer.pText = 0i64;
    pBuffer.Length = 0i64;
    pBuffer.Reserved.pBuffer = 0i64;
    pBuffer.Reserved.Size = 0i64;
    Scaleform::Render::Text::StyledText::GetText(
      (Scaleform::Render::Text::StyledText *)&this->pDocView.pObject->pDocument.pObject->vfptr,
      &pBuffer,
      v6,
      v5);
    if ( v4 )
    {
      v8 = Scaleform::Render::Text::StyledText::CopyStyledText(
             (Scaleform::Render::Text::StyledText *)&v7->pDocView.pObject->pDocument.pObject->vfptr,
             v6,
             v5);
      v9 = (Scaleform::RefCountNTSImpl *)&v8->vfptr;
      v10 = pBuffer.Length;
      v11 = (wchar_t *)byte_1416A7BD8;
      if ( pBuffer.pText )
        v11 = pBuffer.pText;
      v12 = v7->pClipboard.pObject;
      Scaleform::GFx::Clipboard::SetStyledText(v7->pClipboard.pObject, v8);
      Scaleform::GFx::Clipboard::SetText(v12, v11, v10);
      if ( v9 )
        Scaleform::RefCountNTSImpl::Release(v9);
    }
    else
    {
      v13 = (wchar_t *)byte_1416A7BD8;
      if ( pBuffer.pText )
        v13 = pBuffer.pText;
      Scaleform::GFx::Clipboard::SetText(v7->pClipboard.pObject, v13, pBuffer.Length);
    }
    Scaleform::WStringBuffer::~WStringBuffer(&pBuffer);
  }
}

// File Line: 1192
// RVA: 0x8C4560
void __fastcall Scaleform::GFx::Text::EditorKit::CutToClipboard(Scaleform::GFx::Text::EditorKit *this, unsigned __int64 startPos, unsigned __int64 endPos, bool useRichClipboard)
{
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // rdi
  Scaleform::GFx::Text::EditorKit *v6; // rsi
  Scaleform::Render::Text::DocView::DocumentListener *v7; // rcx
  unsigned __int64 v8; // rbx

  v4 = endPos;
  v5 = startPos;
  v6 = this;
  if ( this->pClipboard.pObject )
  {
    if ( endPos < startPos )
    {
      v5 = endPos;
      v4 = startPos;
    }
    Scaleform::GFx::Text::EditorKit::CopyToClipboard(this, v5, v4, useRichClipboard);
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Text::EditorKit *))v6->vfptr[2].__vecDelDtor)(v6) )
    {
      v7 = v6->pDocView.pObject->pDocumentListener.pObject;
      if ( !v7
        || ((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::GFx::Text::EditorKit *, unsigned __int64, unsigned __int64))v7->vfptr[13].__vecDelDtor)(
             v7,
             v6,
             v5,
             v4 - v5) )
      {
        if ( v4 < v5 )
          v8 = 0i64;
        else
          v8 = v4 - v5;
        Scaleform::Render::Text::StyledText::Remove(
          (Scaleform::Render::Text::StyledText *)&v6->pDocView.pObject->pDocument.pObject->vfptr,
          v5,
          v8);
      }
    }
  }
}

// File Line: 1216
// RVA: 0x8EF680
signed __int64 __fastcall Scaleform::GFx::Text::EditorKit::PasteFromClipboard(Scaleform::GFx::Text::EditorKit *this, unsigned __int64 startPos, unsigned __int64 endPos, bool useRichClipboard)
{
  bool v4; // bl
  unsigned __int64 v5; // r15
  unsigned __int64 v6; // rsi
  Scaleform::GFx::Text::EditorKit *v7; // rdi
  signed __int64 v8; // r14
  Scaleform::GFx::Clipboard *v9; // rcx
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // r12
  Scaleform::Render::Text::StyledText *v12; // rax
  wchar_t *v13; // rbx
  Scaleform::Render::Text::DocView *v14; // rax
  wchar_t *v15; // r14
  char v16; // al
  Scaleform::WStringBuffer *v17; // rcx
  __int64 *v18; // r8
  Scaleform::Render::Text::DocView::CommandType v19; // edx
  wchar_t *v20; // r14
  unsigned __int64 v22; // rax
  __int64 v23; // rbx
  Scaleform::Render::Text::DocView *v24; // rcx
  char *v25; // r14
  Scaleform::Render::Text::DocView::DocumentListener *v26; // rcx
  char *v27; // rdx
  __int64 v28; // rcx
  __int64 *v29; // r8
  Scaleform::Render::Text::DocView::CommandType v30; // edx
  char *v31; // rdx
  __int64 v32; // rcx
  unsigned __int64 v33; // rax
  unsigned __int64 v34; // rbx
  __int64 v35; // rsi
  unsigned __int64 v36; // r13
  unsigned int v37; // eax
  unsigned int v38; // er14
  Scaleform::GFx::Text::EditorKit::RestrictParams *v39; // rbx
  signed __int64 v40; // rax
  unsigned __int64 v41; // rcx
  char v42; // al
  int v43; // ebx
  unsigned __int16 v44; // r15
  Scaleform::GFx::Text::EditorKit::RestrictParams *v45; // rbx
  wchar_t *v46; // rax
  unsigned __int64 v47; // rcx
  char v48; // al
  unsigned __int64 v49; // [rsp+30h] [rbp-A8h]
  Scaleform::String result; // [rsp+38h] [rbp-A0h]
  Scaleform::WStringBuffer v51; // [rsp+40h] [rbp-98h]
  Scaleform::WStringBuffer pBuffer; // [rsp+60h] [rbp-78h]
  __int64 v53; // [rsp+80h] [rbp-58h]
  unsigned __int64 v54; // [rsp+88h] [rbp-50h]
  char *v55; // [rsp+90h] [rbp-48h]
  __int64 v56; // [rsp+98h] [rbp-40h]
  __int64 v57; // [rsp+A0h] [rbp-38h]
  __int64 v58; // [rsp+A8h] [rbp-30h]
  unsigned __int16 v59; // [rsp+B0h] [rbp-28h]
  unsigned __int64 command; // [rsp+B8h] [rbp-20h]
  unsigned __int64 v61; // [rsp+C0h] [rbp-18h]
  wchar_t *v62; // [rsp+C8h] [rbp-10h]
  unsigned __int64 v63; // [rsp+D0h] [rbp-8h]
  unsigned __int64 v64; // [rsp+D8h] [rbp+0h]
  char *v65; // [rsp+E0h] [rbp+8h]
  __int64 v66; // [rsp+E8h] [rbp+10h]
  Scaleform::Render::Text::StyledText *v67; // [rsp+F0h] [rbp+18h]
  __int64 v68; // [rsp+F8h] [rbp+20h]
  __int64 v69; // [rsp+138h] [rbp+60h]

  v68 = -2i64;
  v4 = useRichClipboard;
  v5 = endPos;
  v6 = startPos;
  v7 = this;
  v8 = -1i64;
  v69 = -1i64;
  if ( !((unsigned __int8 (*)(void))this->vfptr[2].__vecDelDtor)() )
  {
    v9 = v7->pClipboard.pObject;
    if ( v9 )
    {
      if ( v5 < v6 )
      {
        v10 = v5;
        v5 = v6;
        v6 = v10;
      }
      v11 = 0i64;
      if ( !v4 || !((unsigned __int8 (*)(void))v9->vfptr[6].__vecDelDtor)() )
      {
        v23 = ((__int64 (*)(void))v7->pClipboard.pObject->vfptr[4].__vecDelDtor)();
        if ( *(_QWORD *)(v23 + 8) <= 0ui64 )
          goto LABEL_49;
        v7->Flags &= 0xFFBFu;
        v24 = v7->pDocView.pObject;
        v25 = byte_1416A7BD8;
        if ( v6 == v5 )
        {
          if ( v24->pDocumentListener.pObject )
          {
            v26 = v24->pDocumentListener.pObject;
            v27 = byte_1416A7BD8;
            if ( *(_QWORD *)v23 )
              v27 = *(char **)v23;
            if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::GFx::Text::EditorKit *, unsigned __int64, _QWORD, char *))v26->vfptr[12].__vecDelDtor)(
                    v26,
                    v7,
                    v6,
                    *(_QWORD *)(v23 + 8),
                    v27) )
              return -1i64;
          }
          v28 = *(_QWORD *)(v23 + 8);
          if ( *(_QWORD *)v23 )
            v25 = *(char **)v23;
          v54 = v6;
          v55 = v25;
          v56 = v28;
          v29 = (__int64 *)&v54;
          v30 = 1;
        }
        else
        {
          if ( v24->pDocumentListener.pObject )
          {
            if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::GFx::Text::EditorKit *, unsigned __int64, unsigned __int64))v24->pDocumentListener.pObject->vfptr[13].__vecDelDtor)(
                    v24->pDocumentListener.pObject,
                    v7,
                    v6,
                    v5 - v6) )
              return -1i64;
            v31 = byte_1416A7BD8;
            if ( *(_QWORD *)v23 )
              v31 = *(char **)v23;
            if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::GFx::Text::EditorKit *, unsigned __int64, _QWORD, char *))v7->pDocView.pObject->pDocumentListener.pObject->vfptr[12].__vecDelDtor)(
                    v7->pDocView.pObject->pDocumentListener.pObject,
                    v7,
                    v6,
                    *(_QWORD *)(v23 + 8),
                    v31) )
              return -1i64;
          }
          v32 = *(_QWORD *)(v23 + 8);
          if ( *(_QWORD *)v23 )
            v25 = *(char **)v23;
          v63 = v6;
          v64 = v5;
          v65 = v25;
          v66 = v32;
          v29 = (__int64 *)&v63;
          v30 = 6;
        }
        v33 = Scaleform::Render::Text::DocView::EditCommand(v7->pDocView.pObject, v30, v29);
        v8 = v33 + v6;
        v69 = v33 + v6;
        goto LABEL_49;
      }
      v12 = (Scaleform::Render::Text::StyledText *)((__int64 (*)(void))v7->pClipboard.pObject->vfptr[5].__vecDelDtor)();
      v13 = (wchar_t *)v12;
      if ( v12 )
        ++v12->RefCount;
      v67 = v12;
      if ( !v12 || !Scaleform::Render::Text::StyledText::GetLength(v12) )
        goto LABEL_29;
      v7->Flags &= 0xFFBFu;
      v14 = v7->pDocView.pObject;
      if ( v6 == v5 )
      {
        if ( !v14->pDocumentListener.pObject )
        {
LABEL_17:
          pBuffer.Length = v6;
          pBuffer.Reserved.pBuffer = v13;
          v18 = (__int64 *)&pBuffer.Length;
          v19 = 2;
LABEL_28:
          v22 = Scaleform::Render::Text::DocView::EditCommand(v7->pDocView.pObject, v19, v18);
          v8 = v22 + v6;
          v69 = v22 + v6;
LABEL_29:
          if ( v13 )
            Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v13);
LABEL_49:
          if ( v7->pRestrict.pObject )
          {
            v34 = Scaleform::Render::Text::StyledText::GetLength((Scaleform::Render::Text::StyledText *)&v7->pDocView.pObject->pDocument.pObject->vfptr);
            v49 = v34;
            Scaleform::Render::Text::DocView::GetText(v7->pDocView.pObject, &result);
            v35 = 0i64;
            if ( v34 )
            {
              v36 = v34;
              do
              {
                v37 = Scaleform::String::GetCharAt(&result, v11);
                v38 = v37;
                v39 = v7->pRestrict.pObject;
                if ( !v39 )
                  goto LABEL_78;
                v40 = Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::FindRangeIndex(
                        &v7->pRestrict.pObject->RestrictRanges,
                        (unsigned __int16)v37);
                if ( v40 == -1 )
                  goto LABEL_61;
                if ( v40 >= 0 )
                {
                  v41 = v39->RestrictRanges.Ranges.Data.Size;
                  if ( v40 >= v41 )
                    v40 = v41 - 1;
                  v53 = v40;
                  if ( v40 < 0 )
                    goto LABEL_61;
                }
                else
                {
                  v40 = 0i64;
                  v53 = 0i64;
                }
                if ( v40 < v39->RestrictRanges.Ranges.Data.Size )
                {
                  v42 = 0;
                  goto LABEL_62;
                }
LABEL_61:
                v42 = 1;
LABEL_62:
                if ( !v42 )
                  goto LABEL_78;
                v43 = Scaleform::SFtowupper(v38);
                v44 = Scaleform::SFtowlower(v38);
                if ( v38 != v43 )
                  v44 = v43;
                v45 = v7->pRestrict.pObject;
                if ( !v45 )
                {
LABEL_77:
                  v57 = v35;
                  v58 = v35 + 1;
                  v59 = v44;
                  Scaleform::Render::Text::DocView::EditCommand(v7->pDocView.pObject, Cmd_ReplaceTextByChar, &v57);
                  goto LABEL_78;
                }
                v46 = (wchar_t *)Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::FindRangeIndex(
                                   &v7->pRestrict.pObject->RestrictRanges,
                                   v44);
                if ( v46 == (wchar_t *)-1i64 )
                {
LABEL_74:
                  v48 = 1;
                  goto LABEL_75;
                }
                if ( (signed __int64)v46 >= 0 )
                {
                  v47 = v45->RestrictRanges.Ranges.Data.Size;
                  if ( (unsigned __int64)v46 >= v47 )
                    v46 = (wchar_t *)(v47 - 1);
                  pBuffer.pText = v46;
                  if ( (signed __int64)v46 < 0 )
                    goto LABEL_74;
                }
                else
                {
                  v46 = 0i64;
                  pBuffer.pText = 0i64;
                }
                if ( (unsigned __int64)v46 >= v45->RestrictRanges.Ranges.Data.Size )
                  goto LABEL_74;
                v48 = 0;
LABEL_75:
                if ( !v48 )
                  goto LABEL_77;
                v49 = v35;
                Scaleform::Render::Text::DocView::EditCommand(v7->pDocView.pObject, Cmd_DeleteChar, &v49);
                --v35;
LABEL_78:
                ++v11;
                ++v35;
              }
              while ( v11 < v36 );
            }
            if ( _InterlockedExchangeAdd(
                   (volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
                   0xFFFFFFFF) == 1 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v8 = v69;
          }
          return v8;
        }
        *(_OWORD *)&pBuffer.pText = 0ui64;
        pBuffer.Reserved.pBuffer = 0i64;
        pBuffer.Reserved.Size = 0i64;
        Scaleform::Render::Text::StyledText::GetText((Scaleform::Render::Text::StyledText *)v13, &pBuffer);
        v15 = (wchar_t *)byte_1416A7BD8;
        if ( pBuffer.pText )
          v15 = pBuffer.pText;
        v16 = ((__int64 (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::GFx::Text::EditorKit *, unsigned __int64, unsigned __int64, wchar_t *))v7->pDocView.pObject->pDocumentListener.pObject->vfptr[12].__vecDelDtor)(
                v7->pDocView.pObject->pDocumentListener.pObject,
                v7,
                v6,
                pBuffer.Length,
                v15);
        v17 = &pBuffer;
        if ( v16 )
        {
          Scaleform::WStringBuffer::~WStringBuffer(&pBuffer);
          goto LABEL_17;
        }
        goto LABEL_25;
      }
      if ( v14->pDocumentListener.pObject )
      {
        v51.pText = 0i64;
        v51.Length = 0i64;
        v51.Reserved.pBuffer = 0i64;
        v51.Reserved.Size = 0i64;
        Scaleform::Render::Text::StyledText::GetText((Scaleform::Render::Text::StyledText *)v13, &v51);
        if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::GFx::Text::EditorKit *, unsigned __int64, unsigned __int64))v7->pDocView.pObject->pDocumentListener.pObject->vfptr[13].__vecDelDtor)(
                v7->pDocView.pObject->pDocumentListener.pObject,
                v7,
                v6,
                v5 - v6) )
          goto LABEL_85;
        v20 = (wchar_t *)byte_1416A7BD8;
        if ( v51.pText )
          v20 = v51.pText;
        if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::GFx::Text::EditorKit *, unsigned __int64, unsigned __int64, wchar_t *))v7->pDocView.pObject->pDocumentListener.pObject->vfptr[12].__vecDelDtor)(
                v7->pDocView.pObject->pDocumentListener.pObject,
                v7,
                v6,
                v51.Length,
                v20) )
        {
LABEL_85:
          v17 = &v51;
LABEL_25:
          Scaleform::WStringBuffer::~WStringBuffer(v17);
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v13);
          return -1i64;
        }
        Scaleform::WStringBuffer::~WStringBuffer(&v51);
      }
      command = v6;
      v61 = v5;
      v62 = v13;
      v18 = (__int64 *)&command;
      v19 = 7;
      goto LABEL_28;
    }
  }
  return v8;
}

// File Line: 1338
// RVA: 0x8E6D50
void __fastcall Scaleform::GFx::Text::EditorKit::InvalidateSelectionColors(Scaleform::GFx::Text::EditorKit *this)
{
  Scaleform::GFx::Text::EditorKit *v1; // rbx

  v1 = this;
  if ( this->Flags & 0x400 )
  {
    Scaleform::Render::Text::DocView::SetSelectionTextColor(this->pDocView.pObject, this->ActiveSelectionTextColor);
    Scaleform::Render::Text::DocView::SetSelectionBackgroundColor(v1->pDocView.pObject, v1->ActiveSelectionBkColor);
  }
  else
  {
    Scaleform::Render::Text::DocView::SetSelectionTextColor(this->pDocView.pObject, this->InactiveSelectionTextColor);
    Scaleform::Render::Text::DocView::SetSelectionBackgroundColor(v1->pDocView.pObject, v1->InactiveSelectionBkColor);
  }
}

// File Line: 1419
// RVA: 0x8EF320
char __fastcall Scaleform::GFx::Text::EditorKit::ParseRestrict(Scaleform::GFx::Text::EditorKit *this, const char *restrStr, unsigned __int64 restrStrLen)
{
  unsigned __int64 v3; // rdi
  char *v4; // r13
  Scaleform::GFx::Text::EditorKit *v5; // r14
  Scaleform::StringLH *v6; // rax
  Scaleform::StringLH *v7; // rbx
  Scaleform::GFx::Text::EditorKit::RestrictParams *v8; // rcx
  bool v10; // r12
  char *v11; // rax
  unsigned int v12; // edi
  unsigned int v13; // er15
  unsigned __int64 v14; // r13
  unsigned int v15; // eax
  unsigned int v16; // ebx
  bool v17; // zf
  char *v18; // rax
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *v19; // rcx
  char *putf8Buffer; // [rsp+20h] [rbp-50h]
  __int64 v21; // [rsp+28h] [rbp-48h]
  Scaleform::StringLH *v22; // [rsp+30h] [rbp-40h]
  Scaleform::StringLH *v23; // [rsp+38h] [rbp-38h]
  Scaleform::StringLH *v24; // [rsp+40h] [rbp-30h]
  Scaleform::StringLH *v25; // [rsp+48h] [rbp-28h]
  Scaleform::RangeData<void *> range; // [rsp+50h] [rbp-20h]
  int v27; // [rsp+C8h] [rbp+58h]

  v21 = -2i64;
  v3 = restrStrLen;
  v4 = (char *)restrStr;
  v5 = this;
  v27 = 325;
  v6 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                Scaleform::Memory::pGlobalHeap,
                                this,
                                32ui64,
                                (Scaleform::AllocInfo *)&v27);
  v7 = v6;
  v22 = v6;
  if ( v6 )
  {
    v23 = v6;
    v24 = v6;
    v25 = v6;
    v6->HeapTypeBits = 0i64;
    v6[1].HeapTypeBits = 0i64;
    v6[2].HeapTypeBits = 0i64;
    Scaleform::StringLH::StringLH(v6 + 3);
  }
  else
  {
    v7 = 0i64;
  }
  v8 = v5->pRestrict.pObject;
  if ( v8 != (Scaleform::GFx::Text::EditorKit::RestrictParams *)v7 )
  {
    if ( v8 && v5->pRestrict.Owner )
    {
      v5->pRestrict.Owner = 0;
      Scaleform::GFx::Text::EditorKit::RestrictParams::`scalar deleting destructor'(v8, 1);
    }
    v5->pRestrict.pObject = (Scaleform::GFx::Text::EditorKit::RestrictParams *)v7;
  }
  v5->pRestrict.Owner = v7 != 0i64;
  if ( !v5->pRestrict.pObject )
    return 0;
  putf8Buffer = v4;
  v10 = 0;
  v11 = &v4[v3];
  v12 = 0;
  v13 = 0;
  if ( v4 < v11 )
  {
    v14 = (unsigned __int64)v11;
    do
    {
      v15 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
      v16 = v15;
      v17 = v15 == 0;
      v18 = putf8Buffer;
      if ( v17 )
        v18 = putf8Buffer-- - 1;
      switch ( v16 )
      {
        case 0x5Eu:
          v10 = v10 == 0;
          break;
        case 0x5Cu:
          if ( (unsigned __int64)v18 >= v14 )
            return 1;
          v16 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
          if ( !v16 )
            --putf8Buffer;
LABEL_23:
          if ( v12 )
          {
            if ( v16 < v12 )
              v16 = v12;
          }
          else
          {
            v12 = v16;
          }
          v19 = &v5->pRestrict.pObject->RestrictRanges;
          if ( v10 )
          {
            if ( !v19->Ranges.Data.Size )
            {
              range.Index = 0i64;
              range.Length = 0x10000i64;
              range.Data = 0i64;
              Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
                v19,
                &range);
            }
            Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::ClearRange(
              &v5->pRestrict.pObject->RestrictRanges,
              v12,
              v16 - v12 + 1);
          }
          else
          {
            range.Index = v12;
            range.Length = v16 - v12 + 1;
            range.Data = 0i64;
            Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
              v19,
              &range);
          }
          v13 = v16;
          v12 = 0;
          v18 = putf8Buffer;
          break;
        case 0x2Du:
          v12 = v13;
          break;
        default:
          goto LABEL_23;
      }
    }
    while ( (unsigned __int64)v18 < v14 );
  }
  return 1;
}

