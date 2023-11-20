// File Line: 46
// RVA: 0x93B120
void __fastcall Scaleform::Render::Text::DocView::DocView(Scaleform::Render::Text::DocView *this, Scaleform::Render::Text::Allocator *pallocator, Scaleform::Render::Text::FontManagerBase *pfontMgr, Scaleform::Log *plog)
{
  Scaleform::Log *v4; // rdi
  Scaleform::Render::Text::Allocator *v5; // rsi
  Scaleform::Render::Text::DocView *v6; // rbx
  Scaleform::Render::Text::LineBuffer *v7; // rax
  Scaleform::Render::Text::StyledText *v8; // rax
  Scaleform::Render::Text::DocView::DocumentText *v9; // rdi
  Scaleform::Render::Text::DocView::DocumentText *v10; // rcx
  bool v11; // zf
  Scaleform::Render::Text::LineBuffer *v12; // [rsp+28h] [rbp-40h]
  Scaleform::Render::Text::LineBuffer *v13; // [rsp+30h] [rbp-38h]
  int v14; // [rsp+80h] [rbp+18h]
  Scaleform::Render::Text::StyledText *v15; // [rsp+88h] [rbp+20h]

  v4 = plog;
  v5 = pallocator;
  v6 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,74>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Text::DocView,74>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::DocView::`vftable';
  this->pDocument.pObject = 0i64;
  if ( pfontMgr )
    _InterlockedExchangeAdd(&pfontMgr->RefCount, 1u);
  this->pFontManager.pObject = pfontMgr;
  this->pDocumentListener.pObject = 0i64;
  this->pHighlight = 0i64;
  v7 = &this->mLineBuffer;
  v15 = (Scaleform::Render::Text::StyledText *)v7;
  v12 = &this->mLineBuffer;
  v13 = &this->mLineBuffer;
  v7->Lines.Data.Data = 0i64;
  v7->Lines.Data.Size = 0i64;
  v7->Lines.Data.Policy.Capacity = 0i64;
  this->mLineBuffer.Geom.FirstVisibleLinePos = 0;
  *(_QWORD *)&this->mLineBuffer.Geom.VisibleRect.x2 = 0i64;
  *(_QWORD *)&this->mLineBuffer.Geom.VisibleRect.y2 = 0i64;
  this->mLineBuffer.Geom.Flags = 0;
  *(_QWORD *)&this->mLineBuffer.Geom.VisibleRect.x1 = 0i64;
  this->mLineBuffer.Geom.VisibleRect.x2 = 0.0;
  this->mLineBuffer.LastHScrollOffset = -1;
  *(_QWORD *)&this->ViewRect.x1 = 0i64;
  *(_QWORD *)&this->ViewRect.x2 = 0i64;
  this->MaxVScroll.FormatCounter = 0;
  this->pEditorKit.pObject = 0i64;
  Scaleform::Render::Text::TextFilter::TextFilter(&this->Filter);
  if ( v4 )
    _InterlockedExchangeAdd(&v4->RefCount, 1u);
  v6->pLog.pObject = v4;
  *(_QWORD *)&v6->BorderColor = 0i64;
  v14 = 74;
  v8 = (Scaleform::Render::Text::StyledText *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Text::DocView *, signed __int64, int *, signed __int64, Scaleform::Render::Text::LineBuffer *, Scaleform::Render::Text::LineBuffer *))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                Scaleform::Memory::pGlobalHeap,
                                                v6,
                                                80i64,
                                                &v14,
                                                -2i64,
                                                v12,
                                                v13);
  v9 = (Scaleform::Render::Text::DocView::DocumentText *)v8;
  v15 = v8;
  if ( v8 )
  {
    Scaleform::Render::Text::StyledText::StyledText(v8, v5);
    v9->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Text::DocView::DocumentText::`vftable';
    v9->pDocument = v6;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = v6->pDocument.pObject;
  if ( v10 )
  {
    v11 = v10->RefCount-- == 1;
    if ( v11 )
      v10->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v10->vfptr, 1u);
  }
  v6->pDocument.pObject = v9;
  *(_QWORD *)&v6->FormatCounter = 1310721i64;
  v6->EndSelection = -1i64;
  v6->BeginSelection = -1i64;
  v6->AlignProps &= 0xC0u;
  *(_WORD *)&v6->FlagsEx = 0;
  v6->Flags = 0;
  *(_QWORD *)&v6->ViewRect.x1 = 0i64;
  *(_QWORD *)&v6->ViewRect.x2 = 0i64;
  v6->pImageSubstitutor = 0i64;
  v6->RTFlags &= 0xFBu;
  v6->MaxLength = 0;
  v6->Flags |= 0x80u;
  Scaleform::Render::Text::DocView::SetDefaultShadow(v6);
  *(_QWORD *)&v6->TextWidth = 0i64;
}

// File Line: 66
// RVA: 0x949A00
void __fastcall Scaleform::Render::Text::DocView::~DocView(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView *v1; // rsi
  Scaleform::ArrayDataBase<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy> *v2; // rbx
  void **v3; // rbx
  Scaleform::Log *v4; // rcx
  Scaleform::Render::GradientData *v5; // rcx
  Scaleform::Render::Text::EditorKitBase *v6; // rcx
  Scaleform::Render::Text::DocView::DocumentListener *v7; // rcx
  bool v8; // zf
  Scaleform::Render::Text::FontManagerBase *v9; // rcx
  Scaleform::Render::Text::DocView::DocumentText *v10; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::DocView::`vftable';
  Scaleform::Render::Text::DocView::Close(this);
  v2 = (Scaleform::ArrayDataBase<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy> *)&v1->pImageSubstitutor->Elements.Data.Data;
  if ( v2 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy>(v2);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
  }
  v1->pImageSubstitutor = 0i64;
  v3 = (void **)&v1->pHighlight->HighlightManager.Highlighters.Data.Data;
  if ( v3 )
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *v3);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
  }
  v4 = v1->pLog.pObject;
  if ( v4 && !_InterlockedDecrement(&v4->RefCount) && v4 )
    v4->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
  v5 = v1->Filter.ShadowParams.Gradient.pObject;
  if ( v5 && !_InterlockedDecrement(&v5->RefCount) && v5 )
    v5->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, 1u);
  v1->Filter.vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable';
  v6 = v1->pEditorKit.pObject;
  if ( v6 && !_InterlockedDecrement(&v6->RefCount) && v6 )
    v6->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, 1u);
  v1->mLineBuffer.Geom.Flags |= 1u;
  Scaleform::Render::Text::LineBuffer::RemoveLines(&v1->mLineBuffer, 0, v1->mLineBuffer.Lines.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->mLineBuffer.Lines.Data.Data);
  v7 = v1->pDocumentListener.pObject;
  if ( v7 )
  {
    v8 = v7->RefCount-- == 1;
    if ( v8 )
      v7->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v7->vfptr, 1u);
  }
  v9 = v1->pFontManager.pObject;
  if ( v9 && !_InterlockedDecrement(&v9->RefCount) && v9 )
    v9->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, 1u);
  v10 = v1->pDocument.pObject;
  if ( v10 )
  {
    v8 = v10->RefCount-- == 1;
    if ( v8 )
      v10->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v10->vfptr, 1u);
  }
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
}

// File Line: 117
// RVA: 0x954430
void __fastcall Scaleform::Render::Text::DocView::ImageSubstitutor::AddImageDesc(Scaleform::Render::Text::DocView::ImageSubstitutor *this, Scaleform::Render::Text::DocView::ImageSubstitutor::Element *elem)
{
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element *v2; // r15
  Scaleform::Render::Text::DocView::ImageSubstitutor *v3; // r12
  signed __int64 v4; // r10
  unsigned __int64 v5; // rsi
  __int64 v6; // r9
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element *v7; // rcx
  __int64 v8; // rdx
  int v9; // edi
  signed __int64 v10; // r11
  int v11; // eax
  int v12; // er8
  int v13; // eax

  v2 = elem;
  v3 = this;
  if ( !Scaleform::Render::Text::DocView::ImageSubstitutor::FindImageDesc(
          this,
          elem->SubString,
          (unsigned __int8)elem->SubStringLen,
          0i64) )
  {
    v4 = v3->Elements.Data.Size;
    v5 = 0i64;
    while ( v4 > 0 )
    {
      v6 = (unsigned __int8)v2->SubStringLen;
      v7 = &v3->Elements.Data.Data[(v4 >> 1) + v5];
      v8 = (unsigned __int8)v7->SubStringLen;
      if ( v2->SubStringLen )
      {
        v9 = (unsigned __int8)v7->SubStringLen;
        v10 = (char *)v2 - (char *)v7;
        do
        {
          v11 = *(wchar_t *)((char *)v7->SubString + v10);
          v12 = v7->SubString[0];
          v7 = (Scaleform::Render::Text::DocView::ImageSubstitutor::Element *)((char *)v7 + 2);
          if ( !--v6 || !v11 )
            break;
          if ( v11 != v12 )
            goto LABEL_13;
          --v8;
        }
        while ( v8 );
        if ( v11 == v12 && v8 && v6 )
        {
          v13 = (unsigned __int8)v2->SubStringLen - v9;
          goto LABEL_15;
        }
LABEL_13:
        v13 = v11 - v12;
      }
      else
      {
        v13 = -(signed int)v8;
      }
LABEL_15:
      if ( -v13 >= 0 )
      {
        v4 >>= 1;
      }
      else
      {
        v5 += (v4 >> 1) + 1;
        v4 += -1 - (v4 >> 1);
      }
    }
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy> > *)&v3->Elements.Data,
      v5,
      v2);
  }
}

// File Line: 131
// RVA: 0x97A200
Scaleform::Render::Text::ImageDesc *__fastcall Scaleform::Render::Text::DocView::ImageSubstitutor::FindImageDesc(Scaleform::Render::Text::DocView::ImageSubstitutor *this, const wchar_t *pstr, unsigned __int64 maxlen, unsigned __int64 *ptextLen)
{
  signed __int64 v4; // r10
  unsigned __int64 v5; // r14
  unsigned __int64 v6; // rdi
  unsigned __int64 *v7; // rbx
  const wchar_t *v8; // r15
  Scaleform::Render::Text::DocView::ImageSubstitutor *v9; // r8
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element *v10; // r12
  unsigned __int64 v11; // r9
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element *v12; // rcx
  __int64 v13; // r8
  int v14; // esi
  signed __int64 v15; // r11
  int v16; // eax
  int v17; // edx
  int v18; // eax
  signed __int64 v19; // r14
  unsigned __int64 v20; // r9
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element *v21; // r10
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element *v22; // rcx
  __int64 v23; // rdx
  char *v24; // r15
  int v25; // eax
  int v26; // er8
  int v27; // edi
  int v28; // eax
  Scaleform::Render::Text::DocView::ImageSubstitutor *v30; // [rsp+30h] [rbp+8h]
  unsigned __int64 *v31; // [rsp+48h] [rbp+20h]

  v31 = ptextLen;
  v30 = this;
  v4 = this->Elements.Data.Size;
  v5 = 0i64;
  v6 = maxlen;
  v7 = ptextLen;
  v8 = pstr;
  v9 = this;
  if ( v4 > 0 )
  {
    v10 = this->Elements.Data.Data;
    do
    {
      v11 = v6;
      v12 = &v10[(v4 >> 1) + v5];
      v13 = (unsigned __int8)v12->SubStringLen;
      if ( v6 )
      {
        v14 = (unsigned __int8)v12->SubStringLen;
        v15 = (char *)v8 - (char *)v12;
        do
        {
          v16 = *(wchar_t *)((char *)v12->SubString + v15);
          v17 = v12->SubString[0];
          v12 = (Scaleform::Render::Text::DocView::ImageSubstitutor::Element *)((char *)v12 + 2);
          if ( !--v11 || !v16 )
            break;
          if ( v16 != v17 )
            goto LABEL_12;
          --v13;
        }
        while ( v13 );
        if ( v16 == v17 && v13 )
        {
          v18 = v6 - v14;
          goto LABEL_14;
        }
LABEL_12:
        v18 = v16 - v17;
      }
      else
      {
        v18 = -(signed int)v13;
      }
LABEL_14:
      if ( -v18 >= 0 )
      {
        v4 >>= 1;
      }
      else
      {
        v5 += (v4 >> 1) + 1;
        v4 += -1 - (v4 >> 1);
      }
    }
    while ( v4 > 0 );
    v9 = v30;
    v7 = v31;
  }
  if ( v5 >= v9->Elements.Data.Size )
    return 0i64;
  v19 = v5;
  v20 = v6;
  v21 = &v9->Elements.Data.Data[v19];
  v22 = v21;
  v23 = (unsigned __int8)v21->SubStringLen;
  if ( v6 )
  {
    v24 = (char *)((char *)v8 - (char *)v21);
    do
    {
      v25 = *(wchar_t *)((char *)v22->SubString + (_QWORD)v24);
      v26 = v22->SubString[0];
      v22 = (Scaleform::Render::Text::DocView::ImageSubstitutor::Element *)((char *)v22 + 2);
      if ( !--v20 || !v25 )
        break;
      if ( v25 != v26 )
        goto LABEL_29;
      --v23;
    }
    while ( v23 );
    if ( v25 == v26 && v23 )
    {
      v9 = v30;
      v27 = v6 - (unsigned __int8)v21->SubStringLen;
      goto LABEL_31;
    }
LABEL_29:
    v28 = v25 - v26;
    v9 = v30;
    v27 = v28;
  }
  else
  {
    v27 = -(signed int)v23;
  }
LABEL_31:
  if ( v27 )
    return 0i64;
  if ( v7 )
    *v7 = (unsigned __int8)v21->SubStringLen;
  return v9->Elements.Data.Data[v19].pImageDesc.pObject;
}

// File Line: 143
// RVA: 0x9A9DB0
void __fastcall Scaleform::Render::Text::DocView::ImageSubstitutor::RemoveImageDesc(Scaleform::Render::Text::DocView::ImageSubstitutor *this, Scaleform::Render::Text::ImageDesc *pimgDesc)
{
  Scaleform::Render::Text::ImageDesc *v2; // rbp
  Scaleform::Render::Text::DocView::ImageSubstitutor *v3; // rbx
  unsigned __int64 v4; // rdi
  __int64 v5; // rsi
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element *v6; // rcx
  Scaleform::Render::Text::ImageDesc *v7; // rcx
  bool v8; // zf

  v2 = pimgDesc;
  v3 = this;
  v4 = 0i64;
  if ( this->Elements.Data.Size )
  {
    v5 = 0i64;
    do
    {
      v6 = &v3->Elements.Data.Data[v5];
      if ( v6->pImageDesc.pObject == v2 )
      {
        if ( v3->Elements.Data.Size == 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            (Scaleform::ArrayDataBase<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy> *)&v3->Elements.Data.Data,
            v3,
            0i64);
        }
        else
        {
          v7 = v6->pImageDesc.pObject;
          if ( v7 )
          {
            v8 = v7->RefCount-- == 1;
            if ( v8 )
              v7->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v7->vfptr, 1u);
          }
          memmove(&v3->Elements.Data.Data[v5], &v3->Elements.Data.Data[v5 + 1], 56 * (v3->Elements.Data.Size - v4 - 1));
          --v3->Elements.Data.Size;
        }
      }
      else
      {
        ++v4;
        ++v5;
      }
    }
    while ( v4 < v3->Elements.Data.Size );
  }
}

// File Line: 154
// RVA: 0x9B4160
void __fastcall Scaleform::Render::Text::DocView::SetText(Scaleform::Render::Text::DocView *this, const char *putf8String, unsigned __int64 stringSize)
{
  Scaleform::Render::Text::DocView::DocumentText *v3; // rbx
  Scaleform::Render::Text::DocView *v4; // r14
  unsigned __int64 v5; // rdi
  const char *v6; // rsi

  v3 = this->pDocument.pObject;
  v4 = this;
  v5 = stringSize;
  v6 = putf8String;
  Scaleform::Render::Text::StyledText::Clear((Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr);
  Scaleform::Render::Text::StyledText::AppendString(
    (Scaleform::Render::Text::StyledText *)&v3->vfptr,
    v6,
    v5,
    NLP_ReplaceCRLF,
    v3->pDefaultTextFormat.pObject,
    v3->pDefaultParagraphFormat.pObject);
  v4->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 262u);
}

// File Line: 160
// RVA: 0x9B41E0
void __fastcall Scaleform::Render::Text::DocView::SetText(Scaleform::Render::Text::DocView *this, const wchar_t *pstring, unsigned __int64 length)
{
  Scaleform::Render::Text::DocView::DocumentText *v3; // rbx
  Scaleform::Render::Text::DocView *v4; // r14
  unsigned __int64 v5; // rdi
  const wchar_t *v6; // rsi

  v3 = this->pDocument.pObject;
  v4 = this;
  v5 = length;
  v6 = pstring;
  Scaleform::Render::Text::StyledText::Clear((Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr);
  Scaleform::Render::Text::StyledText::AppendString(
    (Scaleform::Render::Text::StyledText *)&v3->vfptr,
    v6,
    v5,
    NLP_ReplaceCRLF,
    v3->pDefaultTextFormat.pObject,
    v3->pDefaultParagraphFormat.pObject);
  v4->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 262u);
}

// File Line: 166
// RVA: 0x9B43C0
void __fastcall Scaleform::Render::Text::DocView::SetTextFormat(Scaleform::Render::Text::DocView *this, Scaleform::Render::Text::TextFormat *fmt, unsigned __int64 startPos, unsigned __int64 endPos)
{
  Scaleform::Render::Text::DocView *v4; // rbx

  this->RTFlags &= 0xEFu;
  v4 = this;
  Scaleform::Render::Text::StyledText::SetTextFormat(
    (Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr,
    fmt,
    startPos,
    endPos);
  v4->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
}

// File Line: 173
// RVA: 0x9B2540
void __fastcall Scaleform::Render::Text::DocView::SetParagraphFormat(Scaleform::Render::Text::DocView *this, Scaleform::Render::Text::ParagraphFormat *fmt, unsigned __int64 startPos, unsigned __int64 endPos)
{
  Scaleform::Render::Text::DocView *v4; // rbx

  v4 = this;
  Scaleform::Render::Text::StyledText::SetParagraphFormat(
    (Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr,
    fmt,
    startPos,
    endPos);
  v4->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
}

// File Line: 179
// RVA: 0x99CC10
void __fastcall Scaleform::Render::Text::DocView::DocumentText::OnParagraphRemoving(Scaleform::Render::Text::DocView::DocumentText *this, Scaleform::Render::Text::Paragraph *para)
{
  this->pDocument->vfptr[2].__vecDelDtor((Scaleform::RefCountImplCore *)this->pDocument, (unsigned int)para);
}

// File Line: 190
// RVA: 0x99CD50
void __fastcall Scaleform::Render::Text::DocView::DocumentText::OnTextInserting(Scaleform::Render::Text::DocView::DocumentText *this, unsigned __int64 startPos, unsigned __int64 length)
{
  ((void (__fastcall *)(Scaleform::Render::Text::DocView *, signed __int64, unsigned __int64))this->pDocument->vfptr[1].__vecDelDtor)(
    this->pDocument,
    2i64,
    length);
}

// File Line: 202
// RVA: 0x96F510
unsigned __int64 __fastcall Scaleform::Render::Text::DocView::EditCommand(Scaleform::Render::Text::DocView *this, Scaleform::Render::Text::DocView::CommandType cmdId, const void *command)
{
  const wchar_t *v3; // r14
  Scaleform::Render::Text::DocView *v4; // rdi
  unsigned __int64 newLinePolicy; // rsi
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rsi
  unsigned __int64 v8; // rbx
  Scaleform::Render::Text::DocView::DocumentText *v9; // r13
  unsigned __int64 v10; // rax
  unsigned int v11; // ecx
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // rsi
  unsigned __int64 v14; // r15
  unsigned __int64 v15; // r13
  unsigned __int64 v16; // r12
  unsigned __int64 v17; // r15
  unsigned __int64 v18; // rax
  unsigned __int64 v19; // rdx
  unsigned __int64 v20; // rcx
  Scaleform::Render::Text::StyledText::NewLinePolicy v21; // er9
  unsigned __int64 v22; // rdx
  unsigned __int64 v23; // r8
  unsigned __int64 v24; // r12
  unsigned __int64 v25; // r13
  unsigned __int64 v26; // rbx
  unsigned __int64 v27; // r15
  unsigned __int64 v28; // rax
  unsigned __int64 v29; // rdx
  unsigned __int64 v30; // rcx
  unsigned __int64 v31; // rax
  Scaleform::Render::Text::StyledText::NewLinePolicy v32; // er10
  unsigned __int64 v33; // r15
  unsigned __int64 v34; // r13
  unsigned __int64 v35; // rbx
  unsigned __int64 v36; // rax
  unsigned __int64 v37; // rdx
  unsigned __int64 v38; // r12
  unsigned __int64 v39; // r12
  unsigned __int64 v40; // rax
  unsigned __int64 v41; // rcx
  unsigned __int64 v42; // r8
  char v43; // r15
  Scaleform::Render::Text::Paragraph *v44; // r13
  Scaleform::Render::Text::ParagraphFormat *v45; // rcx
  unsigned __int16 v46; // dx
  unsigned int *v47; // r14
  Scaleform::MemoryHeapVtbl *v48; // rax
  unsigned int v49; // ebx
  Scaleform::Render::Text::Allocator *v50; // rax
  __int16 v51; // r8
  unsigned int *v52; // r14
  Scaleform::MemoryHeapVtbl *v53; // rax
  unsigned int v54; // ebx
  Scaleform::Render::Text::Allocator *v55; // rax
  unsigned __int64 v56; // rdx
  unsigned __int64 v57; // r8
  unsigned __int64 v58; // r8
  unsigned __int64 v59; // rbx
  unsigned __int64 v60; // r14
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator result; // [rsp+48h] [rbp-38h]
  Scaleform::Render::Text::ParagraphFormat fmt; // [rsp+58h] [rbp-28h]
  unsigned __int64 pindexInParagraph; // [rsp+D8h] [rbp+58h]

  v3 = (const wchar_t *)command;
  v4 = this;
  newLinePolicy = 0i64;
  v6 = 0i64;
  switch ( cmdId )
  {
    case 0:
      v7 = this->MaxLength;
      if ( !(_DWORD)v7
        || Scaleform::Render::Text::StyledText::GetLength((Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr)
         + 1 <= v7 )
      {
        v6 = Scaleform::Render::Text::StyledText::InsertString(
               (Scaleform::Render::Text::StyledText *)&v4->pDocument.pObject->vfptr,
               v3 + 4,
               *(_QWORD *)v3,
               1ui64,
               NLP_ReplaceCRLF,
               v4->pDocument.pObject->pDefaultTextFormat.pObject,
               v4->pDocument.pObject->pDefaultParagraphFormat.pObject);
        v4->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 2u);
      }
      return v6;
    case 1:
      v8 = *((_QWORD *)command + 2);
      v9 = this->pDocument.pObject;
      v10 = Scaleform::Render::Text::StyledText::GetLength((Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr);
      v11 = v4->MaxLength;
      if ( v11 && v10 + v8 > v11 )
        v8 = v11 - v10;
      if ( !(((unsigned __int8)v4->Flags >> 2) & 1) )
        LODWORD(newLinePolicy) = 2;
      v6 = Scaleform::Render::Text::StyledText::InsertString(
             (Scaleform::Render::Text::StyledText *)&v9->vfptr,
             *((const wchar_t **)v3 + 1),
             *(_QWORD *)v3,
             v8,
             (Scaleform::Render::Text::StyledText::NewLinePolicy)newLinePolicy,
             v9->pDefaultTextFormat.pObject,
             v9->pDefaultParagraphFormat.pObject);
      goto LABEL_92;
    case 2:
      v12 = -1i64;
      v13 = this->MaxLength;
      if ( (_DWORD)v13 )
      {
        v14 = Scaleform::Render::Text::StyledText::GetLength((Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr);
        if ( v14 + Scaleform::Render::Text::StyledText::GetLength(*((Scaleform::Render::Text::StyledText **)v3 + 1)) > v13 )
          v12 = (unsigned int)v13 - v14;
      }
      v6 = Scaleform::Render::Text::StyledText::InsertStyledText(
             (Scaleform::Render::Text::StyledText *)&v4->pDocument.pObject->vfptr,
             *((Scaleform::Render::Text::StyledText **)v3 + 1),
             *(_QWORD *)v3,
             v12);
      goto LABEL_92;
    case 3:
      v56 = *(_QWORD *)command;
      v57 = *(_QWORD *)command + 1i64;
      if ( v57 < v56 )
        v58 = 0i64;
      else
        v58 = v57 - v56;
      Scaleform::Render::Text::StyledText::Remove(
        (Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr,
        v56,
        v58);
      v6 = 1i64;
      goto LABEL_92;
    case 4:
      v59 = *(_QWORD *)command;
      if ( *(_QWORD *)command <= *((_QWORD *)command + 1) )
      {
        v60 = *(_QWORD *)command;
        v59 = *((_QWORD *)command + 1);
      }
      else
      {
        v60 = *((_QWORD *)command + 1);
      }
      if ( v59 >= v60 )
        newLinePolicy = v59 - v60;
      Scaleform::Render::Text::StyledText::Remove(
        (Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr,
        v60,
        newLinePolicy);
      v6 = v59 - v60;
      goto LABEL_92;
    case 5:
      v15 = *(_QWORD *)command;
      if ( *(_QWORD *)command <= *((_QWORD *)command + 1) )
      {
        v16 = *(_QWORD *)command;
        v15 = *((_QWORD *)command + 1);
      }
      else
      {
        v16 = *((_QWORD *)command + 1);
      }
      v17 = this->MaxLength;
      if ( (_DWORD)v17 )
      {
        v18 = Scaleform::Render::Text::StyledText::GetLength((Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr);
        v19 = v18;
        if ( v15 < v18 )
          v19 = v15;
        v20 = v18;
        if ( v16 < v18 )
          v20 = v16;
        if ( v18 + v20 - v19 + 1 > v17 )
          return v6;
      }
      v21 = 0;
      if ( !(((unsigned __int8)v4->Flags >> 2) & 1) )
        v21 = 2;
      v6 = Scaleform::Render::Text::StyledText::InsertString(
             (Scaleform::Render::Text::StyledText *)&v4->pDocument.pObject->vfptr,
             v3 + 8,
             v16,
             1ui64,
             v21,
             v4->pDocument.pObject->pDefaultTextFormat.pObject,
             v4->pDocument.pObject->pDefaultParagraphFormat.pObject);
      v22 = v16 + 1;
      if ( v15 + 1 < v16 + 1 )
        goto LABEL_28;
      v23 = v15 - v16;
      goto LABEL_29;
    case 6:
      v24 = *(_QWORD *)command;
      if ( *(_QWORD *)command <= *((_QWORD *)command + 1) )
      {
        v25 = *(_QWORD *)command;
        v24 = *((_QWORD *)command + 1);
      }
      else
      {
        v25 = *((_QWORD *)command + 1);
      }
      v26 = *((_QWORD *)command + 3);
      v27 = this->MaxLength;
      if ( (_DWORD)v27 )
      {
        v28 = Scaleform::Render::Text::StyledText::GetLength((Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr);
        v29 = v28;
        if ( v24 < v28 )
          v29 = v24;
        v30 = v28;
        if ( v25 < v28 )
          v30 = v25;
        v31 = v30 - v29 + v28;
        if ( v26 + v31 > v27 )
          v26 = (unsigned int)v27 - v31;
      }
      v32 = 0;
      if ( !(((unsigned __int8)v4->Flags >> 2) & 1) )
        v32 = 2;
      v6 = Scaleform::Render::Text::StyledText::InsertString(
             (Scaleform::Render::Text::StyledText *)&v4->pDocument.pObject->vfptr,
             *((const wchar_t **)v3 + 2),
             v25,
             v26,
             v32,
             v4->pDocument.pObject->pDefaultTextFormat.pObject,
             v4->pDocument.pObject->pDefaultParagraphFormat.pObject);
      v22 = v6 + v25;
      if ( v24 + v6 < v6 + v25 )
LABEL_28:
        v23 = 0i64;
      else
        v23 = v24 - v25;
LABEL_29:
      Scaleform::Render::Text::StyledText::Remove(
        (Scaleform::Render::Text::StyledText *)&v4->pDocument.pObject->vfptr,
        v22,
        v23);
      goto LABEL_92;
    case 7:
      v33 = *(_QWORD *)command;
      if ( *(_QWORD *)command <= *((_QWORD *)command + 1) )
      {
        v34 = *(_QWORD *)command;
        v33 = *((_QWORD *)command + 1);
      }
      else
      {
        v34 = *((_QWORD *)command + 1);
      }
      v35 = -1i64;
      if ( this->MaxLength )
      {
        v36 = Scaleform::Render::Text::StyledText::GetLength((Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr);
        v37 = v36;
        if ( v33 < v36 )
          v37 = v33;
        v38 = v36;
        if ( v34 < v36 )
          v38 = v34;
        v39 = v36 + v38 - v37;
        v40 = Scaleform::Render::Text::StyledText::GetLength(*((Scaleform::Render::Text::StyledText **)v3 + 2));
        v41 = v4->MaxLength;
        if ( v39 + v40 > v41 )
          v35 = (unsigned int)v41 - v39;
      }
      v6 = Scaleform::Render::Text::StyledText::InsertStyledText(
             (Scaleform::Render::Text::StyledText *)&v4->pDocument.pObject->vfptr,
             *((Scaleform::Render::Text::StyledText **)v3 + 2),
             v34,
             v35);
      if ( v33 + v6 < v6 + v34 )
        v42 = 0i64;
      else
        v42 = v33 - v34;
      Scaleform::Render::Text::StyledText::Remove(
        (Scaleform::Render::Text::StyledText *)&v4->pDocument.pObject->vfptr,
        v6 + v34,
        v42);
      goto LABEL_92;
    case 8:
      v6 = 1i64;
      v43 = 0;
      pindexInParagraph = 0i64;
      Scaleform::Render::Text::StyledText::GetParagraphByIndex(
        (Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr,
        &result,
        *(_QWORD *)command,
        &pindexInParagraph);
      if ( !result.pArray )
        goto LABEL_78;
      if ( result.CurIndex < 0 )
        goto LABEL_78;
      if ( result.CurIndex >= SLODWORD(result.pArray->Data.Size) )
        goto LABEL_78;
      if ( pindexInParagraph )
        goto LABEL_78;
      v44 = result.pArray->Data.Data[result.CurIndex].pPara;
      v45 = v44->pFormat.pObject;
      if ( !v45 )
        goto LABEL_78;
      v46 = v45->PresentMask;
      if ( (v46 & 0x80u) != 0 && (v46 & 0x8000u) != 0 )
      {
        fmt.pAllocator = 0i64;
        fmt.RefCount = 1;
        fmt.pTabStops = 0i64;
        fmt.BlockIndent = v45->BlockIndent;
        fmt.Indent = v45->Indent;
        fmt.Leading = v45->Leading;
        fmt.LeftMargin = v45->LeftMargin;
        fmt.RightMargin = v45->RightMargin;
        fmt.PresentMask = v46;
        v47 = v45->pTabStops;
        v48 = Scaleform::Memory::pGlobalHeap->vfptr;
        if ( v47 )
        {
          v49 = *v47;
          v48->Free(Scaleform::Memory::pGlobalHeap, 0i64);
          fmt.pTabStops = 0i64;
          fmt.pTabStops = (unsigned int *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                            Scaleform::Memory::pGlobalHeap,
                                            4i64 * (v49 + 1),
                                            0i64);
          *fmt.pTabStops = v49;
          memmove(fmt.pTabStops + 1, v47 + 1, 4i64 * v49);
        }
        else
        {
          v48->Free(Scaleform::Memory::pGlobalHeap, 0i64);
          fmt.pTabStops = 0i64;
        }
        fmt.PresentMask = fmt.PresentMask & 0x7FFF | 0x80;
        v50 = Scaleform::Render::Text::StyledText::GetAllocator((Scaleform::Render::Text::StyledText *)&v4->pDocument.pObject->vfptr);
        Scaleform::Render::Text::Paragraph::SetFormat(v44, v50, &fmt);
        v43 = 1;
LABEL_69:
        if ( fmt.pAllocator )
        {
          pindexInParagraph = (unsigned __int64)&fmt;
          Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
            (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)&fmt.pAllocator->ParagraphFormatStorage.pTable,
            (Scaleform::Render::Text::ParagraphFormat *const *)&pindexInParagraph);
        }
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, fmt.pTabStops);
        fmt.pTabStops = 0i64;
        goto LABEL_80;
      }
      v51 = v45->Indent;
      if ( v51 || v45->BlockIndent )
      {
        fmt.pAllocator = 0i64;
        fmt.RefCount = 1;
        fmt.pTabStops = 0i64;
        fmt.BlockIndent = v45->BlockIndent;
        fmt.Indent = v51;
        fmt.Leading = v45->Leading;
        fmt.LeftMargin = v45->LeftMargin;
        fmt.RightMargin = v45->RightMargin;
        fmt.PresentMask = v46;
        v52 = v45->pTabStops;
        v53 = Scaleform::Memory::pGlobalHeap->vfptr;
        if ( v52 )
        {
          v54 = *v52;
          v53->Free(Scaleform::Memory::pGlobalHeap, 0i64);
          fmt.pTabStops = 0i64;
          fmt.pTabStops = (unsigned int *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                            Scaleform::Memory::pGlobalHeap,
                                            4i64 * (v54 + 1),
                                            0i64);
          *fmt.pTabStops = v54;
          memmove(fmt.pTabStops + 1, v52 + 1, 4i64 * v54);
        }
        else
        {
          v53->Free(Scaleform::Memory::pGlobalHeap, 0i64);
          fmt.pTabStops = 0i64;
        }
        *(_DWORD *)&fmt.BlockIndent = 0;
        fmt.PresentMask |= 6u;
        v55 = Scaleform::Render::Text::StyledText::GetAllocator((Scaleform::Render::Text::StyledText *)&v4->pDocument.pObject->vfptr);
        Scaleform::Render::Text::Paragraph::SetFormat(v44, v55, &fmt);
        v43 = 1;
        goto LABEL_69;
      }
LABEL_78:
      if ( *(_QWORD *)v3 )
      {
        Scaleform::Render::Text::StyledText::Remove(
          (Scaleform::Render::Text::StyledText *)&v4->pDocument.pObject->vfptr,
          *(_QWORD *)v3 - 1i64,
          *(_QWORD *)v3 >= (unsigned __int64)(*(_QWORD *)v3 - 1i64));
        return v6;
      }
LABEL_80:
      v6 = 0i64;
      if ( v43 )
LABEL_92:
        v4->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 2u);
      return v6;
    default:
      return v6;
  }
}

// File Line: 438
// RVA: 0x98C650
Scaleform::String *__fastcall Scaleform::Render::Text::DocView::GetText(Scaleform::Render::Text::DocView *this, Scaleform::String *result)
{
  Scaleform::String *v2; // rbx

  v2 = result;
  Scaleform::Render::Text::StyledText::GetText(
    (Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr,
    result);
  return v2;
}

// File Line: 443
// RVA: 0x98C690
Scaleform::String *__fastcall Scaleform::Render::Text::DocView::GetText(Scaleform::Render::Text::DocView *this, Scaleform::String *retStr)
{
  return Scaleform::Render::Text::StyledText::GetText(
           (Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr,
           retStr);
}

// File Line: 448
// RVA: 0x985440
Scaleform::String *__fastcall Scaleform::Render::Text::DocView::GetHtml(Scaleform::Render::Text::DocView *this, Scaleform::String *result)
{
  Scaleform::String *v2; // rbx

  v2 = result;
  Scaleform::Render::Text::StyledText::GetHtml(
    (Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr,
    result);
  return v2;
}

// File Line: 466
// RVA: 0x99E590
void __fastcall Scaleform::Render::Text::DocView::ParseHtml(Scaleform::Render::Text::DocView *this, const char *putf8Str, unsigned __int64 utf8Len, bool condenseWhite, Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *pimgInfoArr, Scaleform::Render::Text::StyleManagerBase *pstyleMgr, Scaleform::Render::Text::TextFormat *txtFmt, Scaleform::Render::Text::ParagraphFormat *paraFmt)
{
  Scaleform::Render::Text::DocView *v8; // rsi
  bool v9; // bp
  unsigned __int64 v10; // rbx
  const char *v11; // rdi

  v8 = this;
  v9 = condenseWhite;
  v10 = utf8Len;
  v11 = putf8Str;
  Scaleform::Render::Text::StyledText::Clear((Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr);
  if ( v10 == -1i64 )
  {
    do
      ++v10;
    while ( v11[v10] );
  }
  Scaleform::Render::Text::StyledText::ParseHtml(
    (Scaleform::Render::Text::StyledText *)&v8->pDocument.pObject->vfptr,
    v11,
    v10,
    pimgInfoArr,
    ((unsigned __int8)v8->Flags >> 2) & 1,
    v9,
    pstyleMgr,
    txtFmt,
    paraFmt);
  v8->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v8->vfptr, 262u);
}

// File Line: 478
// RVA: 0x99E650
void __fastcall Scaleform::Render::Text::DocView::ParseHtml(Scaleform::Render::Text::DocView *this, const wchar_t *pwStr, unsigned __int64 strLen, bool condenseWhite, Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *pimgInfoArr, Scaleform::Render::Text::StyleManagerBase *pstyleMgr, Scaleform::Render::Text::TextFormat *txtFmt, Scaleform::Render::Text::ParagraphFormat *paraFmt)
{
  Scaleform::Render::Text::DocView *v8; // rsi
  unsigned __int64 v9; // rbx
  const wchar_t *v10; // rdi
  bool multiline; // ST20_1

  v8 = this;
  v9 = strLen;
  v10 = pwStr;
  Scaleform::Render::Text::StyledText::Clear((Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr);
  if ( v9 == -1i64 )
  {
    do
      ++v9;
    while ( v10[v9] );
  }
  multiline = ((unsigned __int8)v8->Flags >> 2) & 1;
  Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>(
    (Scaleform::Render::Text::StyledText *)&v8->pDocument.pObject->vfptr,
    v10,
    v9,
    pimgInfoArr);
  v8->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v8->vfptr, 262u);
}

// File Line: 499
// RVA: 0x959D20
void __fastcall Scaleform::Render::Text::DocView::AppendText(Scaleform::Render::Text::DocView *this, const char *putf8Str, unsigned __int64 utf8Len)
{
  Scaleform::Render::Text::DocView *v3; // rbx
  unsigned __int64 v4; // rsi
  const char *v5; // rbp
  unsigned __int64 v6; // rax
  Scaleform::Render::Text::ParagraphFormat *ppdestParaFmt; // [rsp+40h] [rbp+8h]
  Scaleform::Render::Text::TextFormat *ppdestTextFmt; // [rsp+58h] [rbp+20h]

  v3 = this;
  v4 = utf8Len;
  v5 = putf8Str;
  v6 = Scaleform::Render::Text::StyledText::GetLength((Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr);
  if ( v6
    && Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
         (Scaleform::Render::Text::StyledText *)&v3->pDocument.pObject->vfptr,
         &ppdestTextFmt,
         &ppdestParaFmt,
         v6 - 1) )
  {
    Scaleform::Render::Text::StyledText::AppendString(
      (Scaleform::Render::Text::StyledText *)&v3->pDocument.pObject->vfptr,
      v5,
      v4,
      (Scaleform::Render::Text::StyledText::NewLinePolicy)(~((unsigned __int8)v3->RTFlags >> 3) & 1),
      ppdestTextFmt,
      ppdestParaFmt);
  }
  else
  {
    Scaleform::Render::Text::StyledText::AppendString(
      (Scaleform::Render::Text::StyledText *)&v3->pDocument.pObject->vfptr,
      v5,
      v4,
      (Scaleform::Render::Text::StyledText::NewLinePolicy)(~((unsigned __int8)v3->RTFlags >> 3) & 1),
      v3->pDocument.pObject->pDefaultTextFormat.pObject,
      v3->pDocument.pObject->pDefaultParagraphFormat.pObject);
  }
  v3->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 6u);
}

// File Line: 519
// RVA: 0x958F90
void __fastcall Scaleform::Render::Text::DocView::AppendHtml(Scaleform::Render::Text::DocView *this, const char *putf8Str, unsigned __int64 utf8Len, bool condenseWhite, Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *pimgInfoArr)
{
  Scaleform::Render::Text::DocView *v5; // rbx

  v5 = this;
  if ( utf8Len == -1i64 )
  {
    do
      ++utf8Len;
    while ( putf8Str[utf8Len] );
  }
  Scaleform::Render::Text::StyledText::ParseHtml(
    (Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr,
    putf8Str,
    utf8Len,
    pimgInfoArr,
    ((unsigned __int8)this->Flags >> 2) & 1,
    condenseWhite,
    0i64,
    0i64,
    0i64);
  v5->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, 6u);
}

// File Line: 532
// RVA: 0x9AA880
__int64 __fastcall Scaleform::Render::Text::DocView::ReplaceText(Scaleform::Render::Text::DocView *this, const wchar_t *pstr, unsigned __int64 startPos, unsigned __int64 endPos, unsigned __int64 strLen)
{
  unsigned __int64 v5; // rbx
  const wchar_t *v6; // rsi
  Scaleform::Render::Text::DocView *v7; // rdi
  unsigned __int64 v8; // r9

  v5 = startPos;
  v6 = pstr;
  v7 = this;
  if ( endPos < startPos )
    v8 = 0i64;
  else
    v8 = endPos - startPos;
  Scaleform::Render::Text::StyledText::Remove(
    (Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr,
    startPos,
    v8);
  return Scaleform::Render::Text::StyledText::InsertString(
           (Scaleform::Render::Text::StyledText *)&v7->pDocument.pObject->vfptr,
           v6,
           v5,
           strLen,
           NLP_ReplaceCRLF,
           v7->pDocument.pObject->pDefaultTextFormat.pObject,
           v7->pDocument.pObject->pDefaultParagraphFormat.pObject);
}

// File Line: 540
// RVA: 0x9611E0
void __fastcall Scaleform::Render::Text::DocView::Close(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView *v1; // rbx
  Scaleform::Render::Text::DocView::DocumentText *v2; // rcx
  bool v3; // zf
  Scaleform::Render::Text::DocView::DocumentListener *v4; // rcx
  Scaleform::Render::Text::EditorKitBase *v5; // rcx

  v1 = this;
  v2 = this->pDocument.pObject;
  if ( v2 )
  {
    v3 = v2->RefCount-- == 1;
    if ( v3 )
      v2->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, 1u);
    v1->pDocument.pObject = 0i64;
    v4 = v1->pDocumentListener.pObject;
    if ( v4 )
    {
      v3 = v4->RefCount-- == 1;
      if ( v3 )
        v4->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, 1u);
    }
    v1->pDocumentListener.pObject = 0i64;
    v5 = v1->pEditorKit.pObject;
    if ( v5 && !_InterlockedDecrement(&v5->RefCount) )
    {
      if ( v5 )
        v5->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, 1u);
    }
    v1->pEditorKit.pObject = 0i64;
    v1->mLineBuffer.Geom.Flags |= 1u;
    Scaleform::Render::Text::LineBuffer::RemoveLines(&v1->mLineBuffer, 0, v1->mLineBuffer.Lines.Data.Size);
  }
}

// File Line: 552
// RVA: 0x962AB0
char __fastcall Scaleform::Render::Text::DocView::ContainsNonLeftAlignment(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView::DocumentText *v1; // r8
  unsigned int v2; // eax
  unsigned int v3; // er9
  __int64 v4; // rdx
  Scaleform::Render::Text::Paragraph *v5; // rcx

  v1 = this->pDocument.pObject;
  v2 = 0;
  v3 = v1->Paragraphs.Data.Size;
  if ( !v3 )
    return 0;
  v4 = 0i64;
  if ( v3 <= 0 )
  {
    v5 = 0i64;
    goto LABEL_5;
  }
  while ( 1 )
  {
    v5 = v1->Paragraphs.Data.Data[v4].pPara;
LABEL_5:
    if ( v5->pFormat.pObject->PresentMask & 0x600 )
      break;
    ++v2;
    ++v4;
    if ( v2 >= v3 )
      return 0;
  }
  return 1;
}

// File Line: 564
// RVA: 0x9B5A70
void __fastcall Scaleform::Render::Text::DocView::SetViewRect(Scaleform::Render::Text::DocView *this, Scaleform::Render::Rect<float> *rect, Scaleform::Render::Text::DocView::UseType ut)
{
  float v3; // xmm2_4
  Scaleform::Render::Text::DocView *v4; // rbx
  float v5; // xmm4_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  unsigned int v9; // ecx
  float v10; // xmm0_4
  char v11; // di
  unsigned int v12; // eax
  unsigned int v13; // esi
  unsigned int v14; // eax
  unsigned int v15; // edi
  unsigned int v16; // eax
  Scaleform::Render::Text::DocView::DocumentListener *v17; // rcx

  v3 = this->ViewRect.x1;
  v4 = this;
  if ( rect->x1 != v3 || this->ViewRect.x2 != rect->x2 || this->ViewRect.y1 != rect->y1 || this->ViewRect.y2 != rect->y2 )
  {
    v5 = rect->y2;
    v6 = rect->x2;
    v7 = this->ViewRect.x2 - v3;
    v8 = rect->y1;
    v9 = (signed int)v7;
    v10 = v4->ViewRect.y2 - v4->ViewRect.y1;
    v4->ViewRect.x1 = rect->x1;
    v4->ViewRect.y1 = v8;
    v4->ViewRect.x2 = v6;
    v4->ViewRect.y2 = v5;
    v4->mLineBuffer.Geom.VisibleRect.x1 = v4->ViewRect.x1 + 40.0;
    v4->mLineBuffer.Geom.VisibleRect.y1 = v8 + 40.0;
    v4->mLineBuffer.Geom.VisibleRect.x2 = v6 - 40.0;
    v4->mLineBuffer.Geom.VisibleRect.y2 = v5 - 40.0;
    if ( ut == 1 )
    {
      v11 = v4->AlignProps;
      v12 = (signed int)(float)(v4->ViewRect.x2 - v4->ViewRect.x1);
      v13 = (signed int)(float)(v4->ViewRect.y2 - v4->ViewRect.y1);
      if ( v11 & 0x30
        || v9 != v12
        && (v4->Flags & 8
         || v12 < v9 && v4->mLineBuffer.Geom.Flags & 0x20
         || v11 & 3
         || Scaleform::Render::Text::DocView::ContainsNonLeftAlignment(v4))
        || v13 < (signed int)v10 && v4->mLineBuffer.Geom.Flags & 0x20
        || (v11 & 0xCu) > 4 )
      {
        v4->RTFlags |= 2u;
      }
      else
      {
        ++v4->FormatCounter;
        v14 = Scaleform::Render::Text::DocView::GetMaxHScroll(v4);
        if ( v4->mLineBuffer.Geom.HScrollOffset > v14 )
          Scaleform::Render::Text::DocView::SetHScrollOffset(v4, v14);
        v15 = Scaleform::Render::Text::DocView::GetMaxVScroll(v4);
        if ( v4->mLineBuffer.Geom.FirstVisibleLinePos > v15 )
        {
          v16 = Scaleform::Render::Text::DocView::GetMaxVScroll(v4);
          if ( v15 > v16 )
            v15 = v16;
          if ( v4->mLineBuffer.Geom.FirstVisibleLinePos != v15 )
          {
            v4->mLineBuffer.Geom.FirstVisibleLinePos = v15;
            v4->mLineBuffer.Geom.Flags |= 1u;
            v17 = v4->pDocumentListener.pObject;
            if ( v17 )
              ((void (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::Render::Text::DocView *, _QWORD))v17->vfptr[4].__vecDelDtor)(
                v17,
                v4,
                v15);
          }
        }
        v4->mLineBuffer.Geom.Flags |= 1u;
      }
    }
  }
}

// File Line: 619
// RVA: 0x99CA00
void __fastcall Scaleform::Render::Text::DocView::OnDocumentChanged(Scaleform::Render::Text::DocView *this, unsigned int notifyMask)
{
  if ( _bittest((const signed int *)&notifyMask, 8u) )
    this->RTFlags |= 2u;
  else
    this->RTFlags |= 1u;
}

// File Line: 627
// RVA: 0x99CA20
void __fastcall Scaleform::Render::Text::DocView::OnDocumentParagraphRemoving(Scaleform::Render::Text::DocView *this, Scaleform::Render::Text::Paragraph *para)
{
  __int64 v2; // r8
  Scaleform::Render::Text::DocView *v3; // r10
  char v4; // bl
  Scaleform::Render::Text::LineBuffer *v5; // r9
  Scaleform::Render::Text::LineBuffer::Line *v6; // rcx
  unsigned int v7; // er11

  v2 = 0i64;
  v3 = this;
  v4 = 0;
  v5 = &this->mLineBuffer;
  while ( v5 && (unsigned int)v2 < v5->Lines.Data.Size && (signed int)v2 >= 0 )
  {
    v6 = v5->Lines.Data.Data[v2];
    if ( (v6->MemSize & 0x80000000) == 0 )
      v7 = v6->Data32.ParagraphId;
    else
      v7 = v6->Data32.GlyphsCount;
    if ( para->UniqueId == v7 )
    {
      v4 = 1;
      if ( (v6->MemSize & 0x80000000) == 0 )
        v6->Data32.TextPos = -1;
      else
        v6->Data32.TextPos |= 0xFFFFFFu;
    }
    else if ( v4 )
    {
      break;
    }
    if ( (unsigned int)v2 < v5->Lines.Data.Size )
      v2 = (unsigned int)(v2 + 1);
  }
  v3->RTFlags |= 1u;
}

// File Line: 645
// RVA: 0x979820
Scaleform::Render::Text::FontHandle *__fastcall Scaleform::Render::Text::DocView::FindFont(Scaleform::Render::Text::DocView *this, Scaleform::Render::Text::DocView::FindFontInfo *pfontInfo, bool quietMode)
{
  Scaleform::Render::Text::DocView::FindFontInfo *v3; // r15
  Scaleform::Render::Text::DocView *v4; // rdi
  Scaleform::Ptr<Scaleform::Render::Text::FontHandle> *v5; // r12
  Scaleform::Render::Text::TextFormat *v6; // rdx
  Scaleform::Render::Text::TextFormat **v7; // r13
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,74>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF> > *v8; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,74>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF> > v9; // rbx
  signed __int64 v10; // rax
  signed __int64 v11; // rsi
  signed __int64 v12; // rsi
  Scaleform::Ptr<Scaleform::Render::Text::FontHandle> v13; // rcx
  Scaleform::Render::Text::TextFormat *v14; // rdx
  unsigned __int16 v15; // cx
  Scaleform::Render::RenderBuffer *v16; // rax
  __int64 v17; // rdi
  __int16 v18; // cx
  char v19; // r14
  char v20; // si
  char v21; // di
  Scaleform::StringDH *v22; // rax
  __int64 v23; // r9
  __int64 v24; // rdi
  Scaleform::Render::Text::FontHandle *v25; // rcx
  __int16 v26; // r15
  char v27; // r14
  char v28; // si
  char v29; // di
  Scaleform::StringDH *v30; // rax
  __int64 v31; // r9
  __int64 v32; // r15
  Scaleform::Render::Text::DocView::DocumentListener *v33; // rcx
  Scaleform::String *v34; // rax
  char v35; // di
  char *v36; // rsi
  volatile signed __int32 *v37; // rdi
  Scaleform::StringDH *v38; // rax
  Scaleform::Render::Text::FontHandle *v39; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,74>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF> > *v40; // rcx
  Scaleform::Render::Text::FontManagerBase *v42; // [rsp+38h] [rbp-61h]
  Scaleform::String v43; // [rsp+40h] [rbp-59h]
  __int64 v44; // [rsp+48h] [rbp-51h]
  Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeRef key; // [rsp+50h] [rbp-49h]
  int v46; // [rsp+60h] [rbp-39h]
  char *v47; // [rsp+68h] [rbp-31h]
  __int64 v48; // [rsp+70h] [rbp-29h]
  __int64 v49; // [rsp+78h] [rbp-21h]
  __int64 v50; // [rsp+80h] [rbp-19h]
  char v51; // [rsp+88h] [rbp-11h]
  Scaleform::MemoryHeap *v52; // [rsp+90h] [rbp-9h]
  __int64 v53; // [rsp+98h] [rbp-1h]
  __int64 v54; // [rsp+A0h] [rbp+7h]
  Scaleform::Render::Text::DocView *v55; // [rsp+100h] [rbp+67h]
  Scaleform::Render::Text::DocView::FindFontInfo *v56; // [rsp+108h] [rbp+6Fh]
  bool v57; // [rsp+110h] [rbp+77h]
  unsigned __int64 v58; // [rsp+118h] [rbp+7Fh]

  v57 = quietMode;
  v56 = pfontInfo;
  v55 = this;
  v54 = -2i64;
  v3 = pfontInfo;
  v4 = this;
  v5 = &pfontInfo->pCurrentFont;
  if ( pfontInfo->pCurrentFont.pObject )
  {
    v6 = pfontInfo->pPrevFormat;
    if ( v6 )
    {
      v7 = &v3->pCurrentFormat;
      if ( Scaleform::Render::Text::TextFormat::IsFontSame(v3->pCurrentFormat, v6) )
        goto LABEL_57;
    }
  }
  v8 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,74>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextF)&v3->pFontCache->mHash.pTable;
  if ( v3->pFontCache )
  {
    v7 = &v3->pCurrentFormat;
    v9.pTable = v8->pTable;
    if ( v8->pTable )
    {
      v10 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,74>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF>>::findIndexCore<Scaleform::Render::Text::TextFormat const *>(
              v8,
              &v3->pCurrentFormat,
              (unsigned __int64)*v7 & v9.pTable->SizeMask);
      if ( v10 >= 0 )
      {
        v11 = (signed __int64)v9.pTable + 8 * (3 * v10 + 3);
        if ( v11 )
        {
          v12 = v11 + 8;
          if ( v12 )
          {
            if ( *(_QWORD *)v12 )
              _InterlockedExchangeAdd((volatile signed __int32 *)(*(_QWORD *)v12 + 8i64), 1u);
            v13.pObject = v5->pObject;
            if ( v5->pObject && !_InterlockedDecrement(&v13.pObject->RefCount) && v13.pObject )
              ((void (__fastcall *)(Scaleform::Ptr<Scaleform::Render::Text::FontHandle>, signed __int64))v13.pObject->vfptr->__vecDelDtor)(
                v13,
                1i64);
            v5->pObject = *(Scaleform::Render::Text::FontHandle **)v12;
            goto LABEL_57;
          }
        }
      }
    }
  }
  v7 = &v3->pCurrentFormat;
  v14 = v3->pCurrentFormat;
  v15 = v14->PresentMask;
  if ( (v15 >> 11) & 1 )
  {
    v16 = Scaleform::Render::Text::TextFormat::GetFontHandle(v3->pCurrentFormat);
    v17 = (__int64)v16;
    if ( v16 )
      _InterlockedExchangeAdd(&v16->RefCount, 1u);
  }
  else
  {
    v42 = v4->pFontManager.pObject;
    if ( ((unsigned __int8)v15 >> 2) & 1 )
    {
      v18 = v15 >> 12;
      LOBYTE(v18) = v18 & 1;
      LOWORD(v58) = v18;
      v19 = ((unsigned __int8)v4->Flags >> 5) & 1;
      v20 = (unsigned __int8)v14->FormatFlags >> 1;
      v21 = v14->FormatFlags & 1;
      v22 = Scaleform::Render::Text::TextFormat::GetFontList(v14);
      LOBYTE(v23) = (_BYTE)v58 == 0;
      v24 = ((__int64 (__fastcall *)(Scaleform::Render::Text::FontManagerBase *, unsigned __int64, _QWORD, __int64, _QWORD))v42->vfptr[1].__vecDelDtor)(
              v42,
              (v22->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
              (v19 != 0 ? 0x10 : 0) | ((v20 & 1) != 0) | (v21 != 0 ? 2 : 0),
              v23,
              0i64);
      v25 = v5->pObject;
      if ( v5->pObject && !_InterlockedDecrement(&v25->RefCount) && v25 )
        v25->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v25->vfptr, 1u);
      v5->pObject = (Scaleform::Render::Text::FontHandle *)v24;
      v4 = v55;
    }
    if ( v5->pObject )
      goto LABEL_55;
    if ( !v57 && !(v4->RTFlags & 0x10) && v4->pLog.pObject )
    {
      v46 = 1;
      v47 = 0i64;
      v48 = 0i64;
      v49 = 0i64;
      v50 = 512i64;
      v51 = 0;
      v52 = Scaleform::Memory::pGlobalHeap;
      v26 = (*v7)->PresentMask >> 12;
      v27 = ((unsigned __int8)v4->Flags >> 5) & 1;
      v28 = (unsigned __int8)(*v7)->FormatFlags >> 1;
      v29 = (*v7)->FormatFlags & 1;
      v30 = Scaleform::Render::Text::TextFormat::GetFontList(*v7);
      LOBYTE(v31) = (v26 & 1) == 0;
      v32 = ((__int64 (__fastcall *)(Scaleform::Render::Text::FontManagerBase *, unsigned __int64, _QWORD, __int64, int *))v42->vfptr[1].__vecDelDtor)(
              v42,
              (v30->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
              (v27 != 0 ? 0x10 : 0) | ((v28 & 1) != 0) | (v29 != 0 ? 2 : 0),
              v31,
              &v46);
      v53 = v32;
      v33 = v55->pDocumentListener.pObject;
      if ( v33 )
      {
        v34 = (Scaleform::String *)v33->vfptr[14].__vecDelDtor(
                                     (Scaleform::RefCountNTSImplCore *)&v33->vfptr,
                                     (unsigned int)&v44);
        v35 = 1;
      }
      else
      {
        v58 = (unsigned __int64)&Scaleform::String::NullData;
        _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
        v34 = (Scaleform::String *)&v58;
        v35 = 2;
      }
      Scaleform::String::String(&v43, v34);
      if ( v35 & 2 )
      {
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v58 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v35 &= 0xFDu;
      }
      if ( v35 & 1 && !_InterlockedDecrement((volatile signed __int32 *)((v44 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v36 = &customWorldMapCaption;
      if ( v47 )
        v36 = v47;
      v37 = (volatile signed __int32 *)(v43.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
      v38 = Scaleform::Render::Text::TextFormat::GetFontList(*v7);
      Scaleform::Log::LogError(
        v55->pLog.pObject,
        "Missing font \"%s\" in \"%s\". Search log:\n%s",
        (v38->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
        v37 + 3,
        v36);
      v55->RTFlags |= 0x10u;
      if ( !_InterlockedDecrement(v37 + 2) )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v37);
      if ( v32 && !_InterlockedDecrement((volatile signed __int32 *)(v32 + 8)) )
        (**(void (__fastcall ***)(__int64, signed __int64))v32)(v32, 1i64);
      if ( v47 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v3 = v56;
    }
    v17 = ((__int64 (*)(void))v42->vfptr[2].__vecDelDtor)();
  }
  v39 = v5->pObject;
  if ( v5->pObject && !_InterlockedDecrement(&v39->RefCount) && v39 )
    v39->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v39->vfptr, 1u);
  v5->pObject = (Scaleform::Render::Text::FontHandle *)v17;
LABEL_55:
  v40 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,74>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextF)&v3->pFontCache->mHash.pTable;
  if ( v3->pFontCache )
  {
    key.pFirst = v7;
    key.pSecond = v5;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,74>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeRef>(
      v40,
      v40[1].pTable,
      &key);
  }
LABEL_57:
  v3->pPrevFormat = *v7;
  return v5->pObject;
}

// File Line: 869
// RVA: 0x93C240
void __fastcall Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(Scaleform::Render::Text::GFxLineCursor *this)
{
  this->pPrevGrec = 0i64;
  this->pLastFont.pObject = 0i64;
  *(_QWORD *)&this->LastCharCode = 0i64;
  *(_QWORD *)&this->LastAdvance = 0i64;
  *(_QWORD *)&this->FirstGlyphWidth = 0i64;
  this->ComposStrPosition = -1i64;
  this->ComposStrLength = 0i64;
  this->ComposStrCurPos = 0i64;
  this->pDocView = 0i64;
  this->pParagraph = 0i64;
  *(_QWORD *)&this->LineWidth = 0i64;
  *(_QWORD *)&this->LineLength = 0i64;
  *(_QWORD *)&this->MaxFontDescent = 0i64;
  this->CharIter.PlaceHolder.pFormat.pObject = 0i64;
  this->CharIter.PlaceHolder.Index = 0i64;
  this->CharIter.PlaceHolder.Character = 0;
  this->CharIter.pFormatInfo = 0i64;
  this->CharIter.FormatIterator.pArray = 0i64;
  this->CharIter.FormatIterator.Index = -1i64;
  this->CharIter.pText = 0i64;
  this->CharIter.CurTextIndex = 0i64;
  this->CharInfoHolder.pFormat.pObject = 0i64;
  this->CharInfoHolder.Index = 0i64;
  this->CharInfoHolder.Character = 0;
  *(_QWORD *)&this->Indent = 0i64;
  this->RightMargin = 0;
  this->GlyphIns.pGlyphs = 0i64;
  this->GlyphIns.pNextFormatData = 0i64;
  *(_QWORD *)&this->GlyphIns.GlyphIndex = 0i64;
  this->GlyphIns.FormatDataIndex = 0;
  *(_QWORD *)&this->NumOfSpaces = 0i64;
  this->FontScaleFactor = 1.0;
  *(_WORD *)&this->LastKerning = 0;
  this->NumChars = 0i64;
}

// File Line: 884
// RVA: 0x93C160
void __fastcall Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(Scaleform::Render::Text::GFxLineCursor *this, Scaleform::Render::Text::DocView *pview, Scaleform::Render::Text::Paragraph *ppara)
{
  Scaleform::Render::Text::GFxLineCursor *v3; // rbx

  v3 = this;
  this->pPrevGrec = 0i64;
  this->pLastFont.pObject = 0i64;
  *(_QWORD *)&this->LastCharCode = 0i64;
  *(_QWORD *)&this->LastAdvance = 0i64;
  *(_QWORD *)&this->FirstGlyphWidth = 0i64;
  this->ComposStrPosition = -1i64;
  this->ComposStrLength = 0i64;
  this->ComposStrCurPos = 0i64;
  this->pDocView = pview;
  this->pParagraph = ppara;
  *(_QWORD *)&this->LineWidth = 0i64;
  *(_QWORD *)&this->LineLength = 0i64;
  *(_QWORD *)&this->MaxFontDescent = 0i64;
  Scaleform::Render::Text::Paragraph::GetCharactersIterator(ppara, &this->CharIter, 0i64);
  v3->CharInfoHolder.pFormat.pObject = 0i64;
  v3->CharInfoHolder.Index = 0i64;
  v3->CharInfoHolder.Character = 0;
  *(_QWORD *)&v3->Indent = 0i64;
  v3->RightMargin = 0;
  v3->GlyphIns.pGlyphs = 0i64;
  v3->GlyphIns.pNextFormatData = 0i64;
  *(_QWORD *)&v3->GlyphIns.GlyphIndex = 0i64;
  v3->GlyphIns.FormatDataIndex = 0;
  *(_QWORD *)&v3->NumOfSpaces = 0i64;
  v3->FontScaleFactor = 1.0;
  *(_WORD *)&v3->LastKerning = 0;
  v3->NumChars = 0i64;
}

// File Line: 890
// RVA: 0x94A5E0
void __fastcall Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(Scaleform::Render::Text::GFxLineCursor *this)
{
  Scaleform::Render::Text::GFxLineCursor *v1; // rdi
  Scaleform::Render::Text::TextFormat *v2; // rbx
  bool v3; // zf
  Scaleform::Render::Text::TextFormat *v4; // rbx
  Scaleform::Render::Text::FontHandle *v5; // rcx

  v1 = this;
  v2 = this->CharInfoHolder.pFormat.pObject;
  if ( v2 )
  {
    v3 = v2->RefCount-- == 1;
    if ( v3 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v2);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
    }
  }
  v4 = v1->CharIter.PlaceHolder.pFormat.pObject;
  if ( v4 )
  {
    v3 = v4->RefCount-- == 1;
    if ( v3 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v4);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  v5 = v1->pLastFont.pObject;
  if ( v5 && !_InterlockedDecrement(&v5->RefCount) )
  {
    if ( v5 )
      v5->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, 1u);
  }
}

// File Line: 967
// RVA: 0x94EDA0
Scaleform::Render::Text::Paragraph::CharacterInfo *__fastcall Scaleform::Render::Text::GFxLineCursor::operator*(Scaleform::Render::Text::GFxLineCursor *this)
{
  Scaleform::Render::Text::GFxLineCursor *v1; // rsi
  Scaleform::Render::Text::Paragraph::CharactersIterator *v2; // rax

  v1 = this;
  this->CharInfoHolder.Index = Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(&this->CharIter)->PlaceHolder.Index;
  v2 = Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(&v1->CharIter);
  Scaleform::Render::Text::Paragraph::CharacterInfo::operator=(&v1->CharInfoHolder, &v2->PlaceHolder);
  if ( v1->pDocView->Flags & 0x10 && v1->CharInfoHolder.Character )
    v1->CharInfoHolder.Character = 42;
  return &v1->CharInfoHolder;
}

// File Line: 1033
// RVA: 0x9BA4D0
void __fastcall Scaleform::Render::Text::GFxLineCursor::TrackFontParams(Scaleform::Render::Text::GFxLineCursor *this, Scaleform::Render::Font *pfont, float scale)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4

  v3 = pfont->Ascent;
  v4 = pfont->Descent;
  if ( v3 == 0.0 )
    v3 = FLOAT_960_0;
  if ( v4 == 0.0 )
    v4 = FLOAT_64_0;
  v5 = this->MaxFontAscent;
  v6 = v3 * scale;
  if ( v6 >= v5 )
    v5 = v6;
  v7 = this->MaxFontDescent;
  v8 = v4 * scale;
  this->MaxFontAscent = v5;
  if ( v8 >= v7 )
    v7 = v8;
  this->MaxFontDescent = v7;
  v9 = scale * pfont->Leading;
  v10 = this->MaxFontLeading;
  if ( v9 >= v10 )
    this->MaxFontLeading = v9;
  else
    this->MaxFontLeading = v10;
}

// File Line: 1137
// RVA: 0x9406C0
void __fastcall Scaleform::Render::Text::ParagraphFormatter::ParagraphFormatter(Scaleform::Render::Text::ParagraphFormatter *this, Scaleform::Render::Text::DocView *pdoc, Scaleform::Log *plog)
{
  Scaleform::Log *v3; // rsi
  Scaleform::Render::Text::DocView *v4; // rbx
  Scaleform::Render::Text::ParagraphFormatter *v5; // rdi
  Scaleform::Render::Text::Allocator *v6; // rcx
  __int64 v7; // rcx
  Scaleform::Render::Text::FontHandle *v8; // rcx
  Scaleform::Render::Text::DocView::FindFontInfo *v9; // [rsp+58h] [rbp+10h]

  v3 = plog;
  v4 = pdoc;
  v5 = this;
  this->pDocView = pdoc;
  this->pParagraph = 0i64;
  this->pParaFormat = 0i64;
  this->pTempLine = 0i64;
  Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&this->LineCursor);
  v6 = v4->pDocument.pObject->pTextAllocator.pObject;
  if ( v6 )
    v7 = (__int64)v6->pHeap;
  else
    v7 = ((__int64 (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap)(Scaleform::Memory::pGlobalHeap);
  v5->FontCache.mHash.pTable = 0i64;
  v5->FontCache.mHash.pHeap = (void *)v7;
  v9 = &v5->FindFontInfo;
  v9->pFontCache = &v5->FontCache;
  v9->pCurrentFont.pObject = 0i64;
  v5->FindFontInfo.pPrevFormat = 0i64;
  v5->FindFontInfo.pCurrentFormat = 0i64;
  v8 = v5->FindFontInfo.pCurrentFont.pObject;
  if ( v8 && !_InterlockedDecrement(&v8->RefCount) && v8 )
    v8->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v8->vfptr, 1u);
  v5->FindFontInfo.pCurrentFont.pObject = 0i64;
  Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&v5->StartPoint);
  Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&v5->HalfPoint);
  Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&v5->WordWrapPoint);
  v5->pFontHandle.pObject = 0i64;
  v5->pDynLine = 0i64;
  *(_QWORD *)&v5->NextOffsetY = 0i64;
  *(_WORD *)&v5->NeedRecenterLines = 0;
  v5->pLog = v3;
  *(_QWORD *)&v5->NewLen = 0i64;
  v5->NewParaText = 0i64;
  v5->IndexMap = 0i64;
  v5->MirroredBits = 0i64;
}

// File Line: 1151
// RVA: 0x94BC50
void __fastcall Scaleform::Render::Text::ParagraphFormatter::~ParagraphFormatter(Scaleform::Render::Text::ParagraphFormatter *this)
{
  Scaleform::Render::Text::ParagraphFormatter *v1; // rdi
  Scaleform::Render::Text::LineBuffer::Line *v2; // rbx
  Scaleform::Render::Text::FontHandle *v3; // rcx
  Scaleform::Render::Text::FontHandle *v4; // rcx

  v1 = this;
  v2 = this->pDynLine;
  if ( v2 )
  {
    Scaleform::Render::Text::LineBuffer::Line::Release(this->pDynLine);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->NewParaText);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->IndexMap);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->MirroredBits);
  v3 = v1->pFontHandle.pObject;
  if ( v3 && !_InterlockedDecrement(&v3->RefCount) && v3 )
    v3->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 1u);
  Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(&v1->WordWrapPoint);
  Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(&v1->HalfPoint);
  Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(&v1->StartPoint);
  v4 = v1->FindFontInfo.pCurrentFont.pObject;
  if ( v4 && !_InterlockedDecrement(&v4->RefCount) && v4 )
    v4->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,74>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,74>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,74>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextF)&v1->FontCache.mHash.pTable);
  Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(&v1->LineCursor);
}

// File Line: 1160
// RVA: 0x9939A0
void __fastcall Scaleform::Render::Text::ParagraphFormatter::InitParagraph(Scaleform::Render::Text::ParagraphFormatter *this, Scaleform::Render::Text::Paragraph *paragraph)
{
  Scaleform::Render::Text::Paragraph *v2; // r15
  Scaleform::Render::Text::ParagraphFormatter *v3; // rdi
  Scaleform::Render::Text::GFxLineCursor *v4; // rax
  Scaleform::Render::Text::GFxLineCursor *v5; // rax
  Scaleform::Render::Text::GFxLineCursor *v6; // rax
  __int64 v7; // rdx
  __int64 v8; // r8
  __int64 v9; // r9
  Scaleform::Render::Text::DocView *v10; // rcx
  Scaleform::Render::Text::EditorKitBase *v11; // rcx
  unsigned __int64 v12; // rsi
  unsigned __int16 v13; // cx
  unsigned int v14; // ebx
  char *v15; // rax
  Scaleform::Render::Text::LineBuffer::Line *v16; // r14
  unsigned int v17; // ebx
  __int64 v18; // rax
  __int64 v19; // rax
  unsigned int v20; // ebx
  Scaleform::Render::Text::LineBuffer::Line *v21; // rcx
  Scaleform::Render::Text::LineBuffer::Line *v22; // rcx
  unsigned __int64 v23; // rdx
  Scaleform::Render::Text::EditorKitBase *v24; // rcx
  Scaleform::Render::Text::LineBuffer::Line *v25; // rcx
  Scaleform::Render::Text::LineBuffer::Line *v26; // rcx
  signed __int64 v27; // rdx
  __int64 v28; // rax
  unsigned int v29; // er9
  signed __int64 v30; // rcx
  Scaleform::Render::Text::GFxLineCursor __that; // [rsp+20h] [rbp-E0h]
  __int64 v32; // [rsp+128h] [rbp+28h]
  Scaleform::Render::Text::GFxLineCursor v33; // [rsp+130h] [rbp+30h]

  v32 = -2i64;
  v2 = paragraph;
  v3 = this;
  this->pParagraph = paragraph;
  this->pParaFormat = paragraph->pFormat.pObject;
  Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&v33, this->pDocView, paragraph);
  Scaleform::Render::Text::GFxLineCursor::operator=(&v3->LineCursor, v4);
  Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(&v33);
  __that.pPrevGrec = 0i64;
  __that.pLastFont.pObject = 0i64;
  *(_QWORD *)&__that.LastCharCode = 0i64;
  *(_QWORD *)&__that.LastAdvance = 0i64;
  *(_QWORD *)&__that.FirstGlyphWidth = 0i64;
  __that.ComposStrPosition = -1i64;
  __that.ComposStrLength = 0i64;
  __that.ComposStrCurPos = 0i64;
  __that.pDocView = 0i64;
  __that.pParagraph = 0i64;
  *(_QWORD *)&__that.LineWidth = 0i64;
  *(_QWORD *)&__that.LineLength = 0i64;
  *(_QWORD *)&__that.MaxFontDescent = 0i64;
  __that.CharIter.PlaceHolder.pFormat.pObject = 0i64;
  __that.CharIter.PlaceHolder.Index = 0i64;
  __that.CharIter.PlaceHolder.Character = 0;
  __that.CharIter.pFormatInfo = 0i64;
  __that.CharIter.FormatIterator.pArray = 0i64;
  __that.CharIter.FormatIterator.Index = -1i64;
  __that.CharIter.pText = 0i64;
  __that.CharIter.CurTextIndex = 0i64;
  __that.CharInfoHolder.pFormat.pObject = 0i64;
  __that.CharInfoHolder.Index = 0i64;
  __that.CharInfoHolder.Character = 0;
  *(_QWORD *)&__that.Indent = 0i64;
  __that.RightMargin = 0;
  __that.GlyphIns.pGlyphs = 0i64;
  __that.GlyphIns.pNextFormatData = 0i64;
  *(_QWORD *)&__that.GlyphIns.GlyphIndex = 0i64;
  __that.GlyphIns.FormatDataIndex = 0;
  *(_QWORD *)&__that.NumOfSpaces = 0i64;
  LODWORD(__that.FontScaleFactor) = (_DWORD)FLOAT_1_0;
  *(_WORD *)&__that.LastKerning = 0;
  __that.NumChars = 0i64;
  v5 = Scaleform::Render::Text::GFxLineCursor::operator=(&v3->WordWrapPoint, &__that);
  v6 = Scaleform::Render::Text::GFxLineCursor::operator=(&v3->HalfPoint, v5);
  Scaleform::Render::Text::GFxLineCursor::operator=(&v3->StartPoint, v6);
  Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(&__that);
  v10 = v3->pDocView;
  v3->LineCursor.FontScaleFactor = (float)v3->pDocView->FontScaleFactor * 0.050000001;
  v11 = v10->pEditorKit.pObject;
  if ( v11 )
    ((void (__cdecl *)(Scaleform::Render::Text::EditorKitBase *, __int64, __int64, __int64, Scaleform::Render::Text::LineBuffer::GlyphEntry *, Scaleform::Render::Text::FontHandle *, _QWORD, _QWORD, _QWORD, unsigned __int64, unsigned __int64, unsigned __int64, Scaleform::Render::Text::DocView *, Scaleform::Render::Text::Paragraph *, _QWORD, _QWORD, _QWORD, Scaleform::Render::Text::TextFormat *, unsigned __int64, _QWORD, Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *, Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *, __int64, Scaleform::Render::Text::Paragraph::TextBuffer *, unsigned __int64, Scaleform::Render::Text::TextFormat *, unsigned __int64, _QWORD, _QWORD, _QWORD, Scaleform::Render::Text::L)v11->vfptr[3].__vecDelDtor)(
      v11,
      v7,
      v8,
      v9,
      __that.pPrevGrec,
      __that.pLastFont.pObject,
      *(_QWORD *)&__that.LastCharCode,
      *(_QWORD *)&__that.LastAdvance,
      *(_QWORD *)&__that.FirstGlyphWidth,
      __that.ComposStrPosition,
      __that.ComposStrLength,
      __that.ComposStrCurPos,
      __that.pDocView,
      __that.pParagraph,
      *(_QWORD *)&__that.LineWidth,
      *(_QWORD *)&__that.LineLength,
      *(_QWORD *)&__that.MaxFontDescent,
      __that.CharIter.PlaceHolder.pFormat.pObject,
      __that.CharIter.PlaceHolder.Index,
      *(_QWORD *)&__that.CharIter.PlaceHolder.Character,
      __that.CharIter.pFormatInfo,
      __that.CharIter.FormatIterator.pArray,
      __that.CharIter.FormatIterator.Index,
      __that.CharIter.pText,
      __that.CharIter.CurTextIndex,
      __that.CharInfoHolder.pFormat.pObject,
      __that.CharInfoHolder.Index,
      *(_QWORD *)&__that.CharInfoHolder.Character,
      *(_QWORD *)&__that.Indent,
      *(_QWORD *)&__that.RightMargin,
      __that.GlyphIns.pGlyphs,
      __that.GlyphIns.pNextFormatData,
      *(_QWORD *)&__that.GlyphIns.GlyphIndex);
  Scaleform::Render::Text::ParagraphFormatter::InitCustomWordWrapping(v3);
  v3->pDocView->RTFlags &= 0xBFu;
  v12 = v2->Text.Size + v3->LineCursor.ComposStrLength;
  v13 = v3->pParaFormat->PresentMask;
  if ( (v13 & 0x80u) != 0 && (v13 & 0x8000u) != 0 )
    LODWORD(v12) = v12 + 1;
  v14 = ((8 * v12 + 49) & 0xFFFFFFF8) + 16 * v12;
  if ( v14 >= 0x400 )
  {
    v16 = v3->pDynLine;
    if ( v16 )
    {
      if ( v14 >= (v16->MemSize & 0x7FFFFFF) )
      {
        Scaleform::Render::Text::LineBuffer::Line::Release(v3->pDynLine);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v16);
        v17 = v14 + 100;
        v18 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Text::LineBuffer::TextLineAllocator *, _QWORD, _QWORD, Scaleform::Render::Text::LineBuffer::GlyphEntry *, Scaleform::Render::Text::FontHandle *, _QWORD, _QWORD, _QWORD, unsigned __int64, unsigned __int64, unsigned __int64, Scaleform::Render::Text::DocView *, Scaleform::Render::Text::Paragraph *, _QWORD, _QWORD, _QWORD, Scaleform::Render::Text::TextFormat *, unsigned __int64, _QWORD, Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *, Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *, __int64, Scaleform::Render::Text::Paragraph::TextBuffer *, unsigned __int64, Scaleform::Render::Text::TextFormat *, unsigned __int64, _QWORD, _QWORD)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                Scaleform::Memory::pGlobalHeap,
                &v3->pDocView->mLineBuffer.LineAllocator,
                v17,
                0i64,
                __that.pPrevGrec,
                __that.pLastFont.pObject,
                *(_QWORD *)&__that.LastCharCode,
                *(_QWORD *)&__that.LastAdvance,
                *(_QWORD *)&__that.FirstGlyphWidth,
                __that.ComposStrPosition,
                __that.ComposStrLength,
                __that.ComposStrCurPos,
                __that.pDocView,
                __that.pParagraph,
                *(_QWORD *)&__that.LineWidth,
                *(_QWORD *)&__that.LineLength,
                *(_QWORD *)&__that.MaxFontDescent,
                __that.CharIter.PlaceHolder.pFormat.pObject,
                __that.CharIter.PlaceHolder.Index,
                *(_QWORD *)&__that.CharIter.PlaceHolder.Character,
                __that.CharIter.pFormatInfo,
                __that.CharIter.FormatIterator.pArray,
                __that.CharIter.FormatIterator.Index,
                __that.CharIter.pText,
                __that.CharIter.CurTextIndex,
                __that.CharInfoHolder.pFormat.pObject,
                __that.CharInfoHolder.Index,
                *(_QWORD *)&__that.CharInfoHolder.Character,
                *(_QWORD *)&__that.Indent,
                *(_QWORD *)&__that.RightMargin,
                __that.GlyphIns.pGlyphs,
                __that.GlyphIns.pNextFormatData,
                *(_QWORD *)&__that.GlyphIns.GlyphIndex,
                *(_QWORD *)&__that.GlyphIns.FormatDataIndex,
                *(_QWORD *)&__that.NumOfSpaces,
                *(_QWORD *)&__that.FontScaleFactor,
                __that.NumChars);
        *(_DWORD *)v18 = v17 & 0x7FFFFFF | 0x40000000;
        *(_QWORD *)(v18 + 4) = 0i64;
        *(_DWORD *)(v18 + 38) = 0;
        *(_QWORD *)(v18 + 12) = 0i64;
        *(_QWORD *)(v18 + 20) = 0i64;
        *(_DWORD *)(v18 + 32) = 0;
        v3->pDynLine = (Scaleform::Render::Text::LineBuffer::Line *)v18;
      }
      v19 = (__int64)v3->pDynLine;
    }
    else
    {
      v20 = v14 + 100;
      v19 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Text::LineBuffer::TextLineAllocator *, _QWORD, _QWORD, Scaleform::Render::Text::LineBuffer::GlyphEntry *, Scaleform::Render::Text::FontHandle *, _QWORD, _QWORD, _QWORD, unsigned __int64, unsigned __int64, unsigned __int64, Scaleform::Render::Text::DocView *, Scaleform::Render::Text::Paragraph *, _QWORD, _QWORD, _QWORD, Scaleform::Render::Text::TextFormat *, unsigned __int64, _QWORD, Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *, Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *, __int64, Scaleform::Render::Text::Paragraph::TextBuffer *, unsigned __int64, Scaleform::Render::Text::TextFormat *, unsigned __int64, _QWORD, _QWORD)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
              Scaleform::Memory::pGlobalHeap,
              &v3->pDocView->mLineBuffer.LineAllocator,
              v20,
              0i64,
              __that.pPrevGrec,
              __that.pLastFont.pObject,
              *(_QWORD *)&__that.LastCharCode,
              *(_QWORD *)&__that.LastAdvance,
              *(_QWORD *)&__that.FirstGlyphWidth,
              __that.ComposStrPosition,
              __that.ComposStrLength,
              __that.ComposStrCurPos,
              __that.pDocView,
              __that.pParagraph,
              *(_QWORD *)&__that.LineWidth,
              *(_QWORD *)&__that.LineLength,
              *(_QWORD *)&__that.MaxFontDescent,
              __that.CharIter.PlaceHolder.pFormat.pObject,
              __that.CharIter.PlaceHolder.Index,
              *(_QWORD *)&__that.CharIter.PlaceHolder.Character,
              __that.CharIter.pFormatInfo,
              __that.CharIter.FormatIterator.pArray,
              __that.CharIter.FormatIterator.Index,
              __that.CharIter.pText,
              __that.CharIter.CurTextIndex,
              __that.CharInfoHolder.pFormat.pObject,
              __that.CharInfoHolder.Index,
              *(_QWORD *)&__that.CharInfoHolder.Character,
              *(_QWORD *)&__that.Indent,
              *(_QWORD *)&__that.RightMargin,
              __that.GlyphIns.pGlyphs,
              __that.GlyphIns.pNextFormatData,
              *(_QWORD *)&__that.GlyphIns.GlyphIndex,
              *(_QWORD *)&__that.GlyphIns.FormatDataIndex,
              *(_QWORD *)&__that.NumOfSpaces,
              *(_QWORD *)&__that.FontScaleFactor,
              __that.NumChars);
      *(_DWORD *)v19 = v20 & 0x7FFFFFF | 0x40000000;
      *(_QWORD *)(v19 + 4) = 0i64;
      *(_DWORD *)(v19 + 38) = 0;
      *(_QWORD *)(v19 + 12) = 0i64;
      *(_QWORD *)(v19 + 20) = 0i64;
      *(_DWORD *)(v19 + 32) = 0;
      v3->pDynLine = (Scaleform::Render::Text::LineBuffer::Line *)v19;
    }
    v3->pTempLine = (Scaleform::Render::Text::LineBuffer::Line *)v19;
  }
  else
  {
    v15 = v3->TempLineBuff;
    if ( v3 == (Scaleform::Render::Text::ParagraphFormatter *)-1792i64 )
      v15 = 0i64;
    else
      *(_DWORD *)v15 = 0;
    v3->pTempLine = (Scaleform::Render::Text::LineBuffer::Line *)v15;
    *(_DWORD *)v15 &= 0xF8000000;
    *(_DWORD *)v15 |= v14 & 0x7FFFFFF;
  }
  v21 = v3->pTempLine;
  v21->MemSize = v21->MemSize & 0x7FFFFFF | 0x40000000;
  *(_QWORD *)&v21->Data32.GlyphsCount = 0i64;
  *(_DWORD *)((char *)&v21->Data8 + 34) = 0;
  *(_QWORD *)&v21->Data8.OffsetX = 0i64;
  *(_QWORD *)&v21->Data8.Width = 0i64;
  v21->Data32.TextLength = 0;
  v3->pTempLine->MemSize &= 0xBFFFFFFF;
  v22 = v3->pTempLine;
  if ( (v22->MemSize & 0x80000000) == 0 )
    v22->Data32.GlyphsCount = v12;
  else
    v22->Data8.GlyphsCount = v12;
  v23 = v2->StartIndex;
  v24 = v3->pDocView->pEditorKit.pObject;
  if ( v24 )
    LODWORD(v23) = (__int64)v24->vfptr[4].__vecDelDtor((Scaleform::RefCountImplCore *)&v24->vfptr, v23);
  v25 = v3->pTempLine;
  if ( (v25->MemSize & 0x80000000) == 0 )
  {
    v25->Data32.TextPos = v23;
  }
  else
  {
    v25->Data32.TextPos &= 0xFF000000;
    v25->Data32.TextPos |= v23 & 0xFFFFFF;
  }
  v26 = v3->pTempLine;
  v27 = (signed __int64)(&v26->Data8.Leading + 1);
  if ( (v26->MemSize & 0x80000000) == 0 )
    v27 = (signed __int64)&v26->Data8 + 38;
  if ( (v26->MemSize & 0x80000000) == 0 )
    v28 = v26->Data32.GlyphsCount;
  else
    v28 = (unsigned __int8)v26->Data8.GlyphsCount;
  if ( (v26->MemSize & 0x80000000) == 0 )
    v29 = v26->Data32.GlyphsCount;
  else
    v29 = (unsigned __int8)v26->Data8.GlyphsCount;
  if ( (v26->MemSize & 0x80000000) == 0 )
    v30 = (signed __int64)&v26->Data8 + 38;
  else
    v30 = (signed __int64)(&v26->Data8.Leading + 1);
  v3->LineCursor.GlyphIns.pGlyphs = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)v30;
  v3->LineCursor.GlyphIns.pNextFormatData = (Scaleform::Render::Text::LineBuffer::FormatDataEntry *)((v27 + 8 * v28 + 7) & 0xFFFFFFFFFFFFFFF8ui64);
  v3->LineCursor.GlyphIns.GlyphIndex = 0;
  v3->LineCursor.GlyphIns.GlyphsCount = v29;
  v3->LineCursor.GlyphIns.FormatDataIndex = 0;
  *(_QWORD *)&v3->ParaWidth = 0i64;
  v3->ParaLines = 0;
  v3->DeltaText = 1;
  v3->Pass = 1;
  v3->HyphenationRequested = 0;
  v3->RequestedWordWrapPos = 0;
  v3->isSpace = 0;
  v3->TextRectWidth = v3->pDocView->mLineBuffer.Geom.VisibleRect.x2 - v3->pDocView->mLineBuffer.Geom.VisibleRect.x1;
  *(_QWORD *)&v3->TabStopsNum = 0i64;
}

// File Line: 1271
// RVA: 0x992FE0
void __fastcall Scaleform::Render::Text::ParagraphFormatter::InitCustomWordWrapping(Scaleform::Render::Text::ParagraphFormatter *this)
{
  Scaleform::Render::Text::DocView *v1; // r11
  Scaleform::Render::Text::ParagraphFormatter *v2; // rdi
  Scaleform::Render::Text::DocView::DocumentListener *v3; // rax
  bool v4; // zf
  bool v5; // al
  Scaleform::Render::Text::Paragraph *v6; // rdx
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // rax
  bool v9; // cf
  wchar_t *v10; // rax
  unsigned __int64 v11; // r8
  unsigned __int64 v12; // r9
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // rcx
  wchar_t *v15; // rcx
  unsigned __int64 v16; // rcx
  char v17; // bp
  unsigned __int64 v18; // rax
  wchar_t *v19; // rax
  wchar_t *v20; // rsi
  Scaleform::Render::Text::Allocator *v21; // rax

  v1 = this->pDocView;
  v2 = this;
  v3 = this->pDocView->pDocumentListener.pObject;
  if ( !v3 || (v4 = (v3->HandlersMask & 1) == 0, v5 = 1, v4) )
    v5 = 0;
  this->HasLineFormatHandler = v5;
  this->pTextBufForCustomFormat = 0i64;
  if ( v5 )
  {
    v6 = this->pParagraph;
    v7 = v6->Text.Size;
    if ( v7 )
    {
      v8 = v7 - 1;
      if ( !v6->Text.pText || (v9 = v8 < v7, v10 = &v6->Text.pText[v8], !v9) )
        v10 = 0i64;
      if ( !*v10 )
        --v7;
    }
    v11 = this->LineCursor.ComposStrPosition;
    v12 = v6->StartIndex;
    if ( v11 < v12 )
      goto LABEL_36;
    v13 = v6->Text.Size;
    if ( v13 )
    {
      v14 = v13 - 1;
      if ( !v6->Text.pText || (v9 = v14 < v13, v15 = &v6->Text.pText[v14], !v9) )
        v15 = 0i64;
      if ( !*v15 )
        --v13;
    }
    if ( v11 > v12 + v13 )
    {
LABEL_36:
      v17 = 0;
    }
    else
    {
      v16 = v6->Text.Size;
      v17 = 1;
      if ( v16 )
      {
        v18 = v16 - 1;
        if ( !v6->Text.pText || (v9 = v18 < v16, v19 = &v6->Text.pText[v18], !v9) )
          v19 = 0i64;
        if ( !*v19 )
          --v16;
      }
      v7 = v16 + v2->LineCursor.ComposStrLength;
    }
    if ( v7 >= 0x100 )
    {
      v21 = Scaleform::Render::Text::StyledText::GetAllocator((Scaleform::Render::Text::StyledText *)&v1->pDocument.pObject->vfptr);
      v20 = (wchar_t *)v21->pHeap->vfptr->Alloc(v21->pHeap, 2 * v7 + 2, 0i64);
    }
    else
    {
      v20 = v2->TextBufForCustomFormat;
    }
    if ( !v17 || v2->LineCursor.ComposStrLength <= 0 )
      memmove(v20, v2->pParagraph->Text.pText, 2 * v7);
    v20[v7] = 0;
    v2->pTextBufForCustomFormat = v20;
    v2->TextBufLen = v7;
  }
}

// File Line: 1318
// RVA: 0x97FC70
float __fastcall Scaleform::Render::Text::ParagraphFormatter::GetActualFontSize(Scaleform::Render::Text::ParagraphFormatter *this)
{
  float v1; // xmm1_4
  float result; // xmm0_4

  v1 = this->FindFontInfo.pCurrentFont.pObject->FontScaleFactor;
  result = (float)this->FindFontInfo.pCurrentFormat->FontSize * 0.050000001;
  if ( v1 != 1.0 )
    result = result * v1;
  if ( this->pDocView->RTFlags & 4 )
    result = result * (float)((float)this->pDocView->FontScaleFactor * 0.050000001);
  return result;
}

// File Line: 1405
// RVA: 0x978070
void __fastcall Scaleform::Render::Text::ParagraphFormatter::FinalizeLine(Scaleform::Render::Text::ParagraphFormatter *this)
{
  Scaleform::Render::Text::ParagraphFormatter *v1; // rdi
  float v2; // xmm0_4
  float v3; // xmm0_4
  signed int v4; // er8
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v5; // rcx
  Scaleform::Render::Text::ParagraphFormat *v6; // rcx
  int v7; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  unsigned int v11; // er12
  float v12; // xmm0_4
  signed int v13; // er13
  unsigned int v14; // ecx
  int v15; // eax
  __int64 v16; // rbp
  __int64 v17; // r15
  Scaleform::Render::Text::LineBuffer::Iterator *v18; // rbx
  unsigned __int64 v19; // rax
  Scaleform::Render::Text::LineBuffer::Line *v20; // rax
  unsigned __int64 v21; // rax
  Scaleform::Render::Text::LineBuffer::Line *v22; // rsi
  unsigned int v23; // edx
  bool v24; // cl
  unsigned __int16 v25; // dx
  Scaleform::Render::Text::LineBuffer::Line *v26; // rdx
  const void *v27; // rdx
  bool v28; // zf
  void *v29; // rcx
  Scaleform::Render::Text::LineBuffer::Line *v30; // rax
  signed __int64 v31; // rdx
  unsigned int v32; // ecx
  signed __int64 v33; // r9
  signed __int64 v34; // rcx
  __int64 v35; // rax
  Scaleform::Render::Text::LineBuffer::Line *v36; // rcx
  unsigned int v37; // eax
  signed int v38; // ecx
  unsigned int v39; // ecx
  signed int v40; // eax
  Scaleform::Render::Text::ParagraphFormat *v41; // rax
  int v42; // ebp
  unsigned int v43; // er14
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v44; // rcx
  unsigned __int16 v45; // dx
  int v46; // eax
  int v47; // eax
  Scaleform::Render::Text::ImageDesc *v48; // rcx
  Scaleform::Render::Text::FontHandle *v49; // rcx
  int v50; // er8
  int v51; // ecx
  unsigned int v52; // et1
  unsigned int v53; // ecx
  signed int v54; // ecx
  int v55; // eax
  signed int v56; // ecx
  int v57; // eax
  int v58; // ecx
  float v59; // xmm1_4
  float v60; // xmm1_4
  bool v61; // sf
  int v62; // eax
  signed int v63; // ecx
  int v64; // eax
  float v65; // xmm0_4
  float v66; // xmm0_4
  int v67; // ecx
  int v68; // ecx
  double v69; // xmm1_8
  double v70; // xmm1_8
  Scaleform::Render::Text::FontHandle *v71; // rcx
  Scaleform::Render::Text::LineBuffer::GlyphIterator result; // [rsp+40h] [rbp-E8h]

  v1 = this;
  v2 = this->LineCursor.LastAdvance;
  if ( v2 <= 0.0 )
    v3 = v2 - 0.5;
  else
    v3 = v2 + 0.5;
  v4 = (signed int)v3;
  v5 = this->LineCursor.pPrevGrec;
  if ( v5 )
  {
    if ( v4 < 0 )
    {
      v5->Advance = abs(v4);
      v5->Flags |= 0x40u;
    }
    else
    {
      v5->Advance = v4;
      v5->Flags &= 0xFFBFu;
    }
  }
  if ( v1->LineCursor.pLastFont.pObject )
    v1->LineCursor.LineWidth += v1->LineCursor.LastGlyphWidth;
  else
    v1->LineCursor.LineWidth += v4;
  v6 = v1->pParaFormat;
  if ( v6->PresentMask & 1
    && ((v6->PresentMask & 0x600) == 512 || v6->PresentMask & 1 && (v6->PresentMask & 0x600) == 1536) )
  {
    v7 = v1->LineCursor.RightMargin;
    v1->LineCursor.LineWidth += v7;
    v1->LineCursor.LineWidthWithoutTrailingSpaces += v7;
  }
  if ( (LOBYTE(v6->PresentMask) >> 3) & 1 )
    v8 = (float)v6->Leading * 20.0;
  else
    v8 = v1->LineCursor.MaxFontLeading;
  v9 = v1->LineCursor.MaxFontDescent + v1->LineCursor.MaxFontAscent;
  if ( v9 <= 0.0 )
    v10 = v9 - 0.5;
  else
    v10 = v9 + 0.5;
  v11 = (signed int)v10;
  if ( v8 <= 0.0 )
    v12 = v8 - 0.5;
  else
    v12 = v8 + 0.5;
  v13 = (signed int)v12;
  v14 = v1->LineCursor.LineWidth;
  if ( (v14 & 0x80000000) != 0 )
    v14 = 0;
  v1->LineCursor.LineWidth = v14;
  v15 = v1->LineCursor.LineWidthWithoutTrailingSpaces;
  if ( v15 < 0 )
    v15 = 0;
  v1->LineCursor.LineWidthWithoutTrailingSpaces = v15;
  v16 = v1->LineCursor.GlyphIns.GlyphIndex;
  v17 = v1->LineCursor.GlyphIns.FormatDataIndex;
  if ( v1->pDocView->AlignProps & 0x30
    || v1->LineCursor.LineLength > 0xFF
    || (unsigned int)v16 > 0xFF
    || (unsigned int)(v13 + 128) > 0xFF
    || v11 > 0xFFFF
    || v14 > 0xFFFF )
  {
    v18 = v1->pLinesIter;
    LODWORD(v21) = v18->CurrentPos;
    if ( (v21 & 0x80000000) != 0i64 || (_DWORD)v21 == -1 )
      v21 = v18->pLineBuffer->Lines.Data.Size;
    v20 = Scaleform::Render::Text::LineBuffer::InsertNewLine(v18->pLineBuffer, v21, v16, v17, Line32);
  }
  else
  {
    v18 = v1->pLinesIter;
    LODWORD(v19) = v18->CurrentPos;
    if ( (v19 & 0x80000000) != 0i64 || (_DWORD)v19 == -1 )
      v19 = v18->pLineBuffer->Lines.Data.Size;
    v20 = Scaleform::Render::Text::LineBuffer::InsertNewLine(v18->pLineBuffer, v19, v16, v17, 0);
  }
  ++v18->CurrentPos;
  v22 = v20;
  v23 = v1->LineCursor.pParagraph->UniqueId;
  v24 = (v20->MemSize & 0x80000000) != 0;
  if ( (v20->MemSize & 0x80000000) == 0 )
    v20->Data32.ParagraphId = v23;
  else
    v20->Data32.GlyphsCount = v23;
  v25 = v1->LineCursor.pParagraph->ModCounter;
  if ( v24 )
    v20->Data8.ParagraphModId = v25;
  else
    v20->Data32.ParagraphModId = v25;
  v26 = v1->pTempLine;
  if ( (v26->MemSize & 0x80000000) == 0 )
    v27 = (char *)&v26->Data8 + 38;
  else
    v27 = &v26->Data8.Leading + 1;
  v28 = v24 == 0;
  v29 = &v20->Data8.Leading + 1;
  if ( v28 )
    v29 = (char *)&v20->Data8 + 38;
  memmove(v29, v27, 8 * v16);
  v30 = v1->pTempLine;
  v31 = (signed __int64)(&v30->Data8.Leading + 1);
  if ( (v30->MemSize & 0x80000000) == 0 )
    v31 = (signed __int64)&v30->Data8 + 38;
  if ( (v30->MemSize & 0x80000000) == 0 )
    v32 = v30->Data32.GlyphsCount;
  else
    v32 = (unsigned __int8)v30->Data8.GlyphsCount;
  v33 = v31 + 8i64 * v32;
  v34 = (signed __int64)(&v22->Data8.Leading + 1);
  if ( (v22->MemSize & 0x80000000) == 0 )
    v34 = (signed __int64)&v22->Data8 + 38;
  if ( (v22->MemSize & 0x80000000) == 0 )
    v35 = v22->Data32.GlyphsCount;
  else
    v35 = (unsigned __int8)v22->Data8.GlyphsCount;
  memmove(
    (void *)((v34 + 8 * v35 + 7) & 0xFFFFFFFFFFFFFFF8ui64),
    (const void *)((v33 + 7) & 0xFFFFFFFFFFFFFFF8ui64),
    8 * v17);
  v36 = v1->pTempLine;
  v37 = v36->MemSize >> 31;
  v38 = v36->Data32.TextPos;
  if ( v37 & 1 )
  {
    v38 &= 0xFFFFFFu;
    if ( v38 == 0xFFFFFF )
      v38 = -1;
  }
  if ( (v22->MemSize & 0x80000000) == 0 )
  {
    v22->Data32.TextPos = v38;
  }
  else
  {
    v22->Data32.TextPos &= 0xFF000000;
    v22->Data32.TextPos |= v38 & 0xFFFFFF;
  }
  v39 = v1->LineCursor.LineLength;
  if ( (v22->MemSize & 0x80000000) == 0 )
    v22->Data32.TextLength = v39;
  else
    HIBYTE(v22->Data8.TextPosAndLength) = v39;
  v40 = (signed int)v1->LineCursor.MaxFontAscent;
  if ( (v22->MemSize & 0x80000000) == 0 )
    v22->Data32.BaseLineOffset = v40;
  else
    v22->Data8.BaseLineOffset = v40;
  if ( !v1->LineCursor.LineHasNewLine )
  {
    if ( v1->pDocView->Flags & 8 )
    {
      if ( v1->LineCursor.NumOfSpaces != v1->LineCursor.NumOfTrailingSpaces )
      {
        v41 = v1->pParaFormat;
        if ( v41->PresentMask & 1 )
        {
          if ( (v41->PresentMask & 0x600) == 1024 )
          {
            v42 = (signed int)(float)(v1->TextRectWidth - 30.0)
                - v1->LineCursor.RightMargin
                - v1->LineCursor.LeftMargin
                - v1->LineCursor.Indent
                - v1->LineCursor.LineWidthWithoutTrailingSpaces;
            if ( v42 > 0 )
            {
              v43 = v42 / (v1->LineCursor.NumOfSpaces - v1->LineCursor.NumOfTrailingSpaces);
              Scaleform::Render::Text::LineBuffer::Line::Begin(v22, &result);
              while ( 1 )
              {
                v44 = result.pGlyphs;
                if ( !result.pGlyphs || result.pGlyphs >= result.pEndGlyphs )
                  break;
                v45 = result.pGlyphs->Flags;
                if ( ((unsigned __int8)v45 >> 1) & 1 )
                {
                  v46 = result.pGlyphs->Advance;
                  if ( ((unsigned __int8)v45 >> 6) & 1 )
                    v46 = -v46;
                  v47 = v43 + v46;
                  if ( v47 < 0 )
                  {
                    LOWORD(v47) = abs(v47);
                    result.pGlyphs->Flags |= 0x40u;
                  }
                  else
                  {
                    result.pGlyphs->Flags &= 0xFFBFu;
                  }
                  v44->Advance = v47;
                }
                Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&result);
              }
              v1->LineCursor.LineWidth += v42;
              v48 = result.pImage.pObject;
              if ( result.pImage.pObject )
              {
                --result.pImage.pObject->RefCount;
                if ( !v48->RefCount )
                  v48->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v48->vfptr, 1u);
              }
              v49 = result.pFontHandle.pObject;
              if ( result.pFontHandle.pObject && !_InterlockedDecrement(&result.pFontHandle.pObject->RefCount) && v49 )
                v49->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v49->vfptr, 1u);
            }
          }
        }
      }
    }
  }
  v50 = v1->LineCursor.Indent + v1->LineCursor.LeftMargin;
  v51 = v1->NextOffsetY;
  v52 = v22->MemSize;
  v22->Data32.OffsetX = v50;
  v22->Data32.OffsetY = v51;
  v53 = v22->MemSize;
  if ( (v22->MemSize & 0x80000000) == 0 )
    v22->Data32.Leading = v13;
  else
    v22->Data8.Leading = v13;
  if ( (((unsigned int)v1->pParaFormat->PresentMask >> 9) & 3) == 1 )
  {
    v63 = v53 & 0xEFFFFFFF | 0x8000000;
    v22->MemSize = v63;
    v64 = v1->LineCursor.LineWidthWithoutTrailingSpaces;
    if ( v63 >= 0 )
    {
      v22->Data32.Width = v64;
      v22->Data32.Height = v11;
    }
    else
    {
      v22->Data8.Width = v64;
      v22->Data8.Height = v11;
    }
    v65 = v1->TextRectWidth;
    if ( v65 <= 0.0 )
      v66 = v65 - 0.5;
    else
      v66 = v65 + 0.5;
    v61 = (signed int)v66 - v1->LineCursor.LineWidthWithoutTrailingSpaces < 0;
    v62 = (signed int)v66 - v1->LineCursor.LineWidthWithoutTrailingSpaces;
  }
  else
  {
    if ( (((unsigned int)v1->pParaFormat->PresentMask >> 9) & 3) != 3 )
    {
      v54 = v53 & 0xE7FFFFFF;
      v22->MemSize = v54;
      v55 = v1->LineCursor.LineWidth;
      if ( v54 >= 0 )
      {
        v22->Data32.Width = v55;
        v22->Data32.Height = v11;
      }
      else
      {
        v22->Data8.Width = v55;
        v22->Data8.Height = v11;
      }
      goto LABEL_127;
    }
    v56 = v53 & 0xF7FFFFFF | 0x10000000;
    v22->MemSize = v56;
    v57 = v1->LineCursor.LineWidthWithoutTrailingSpaces;
    if ( v56 >= 0 )
    {
      v22->Data32.Width = v57;
      v22->Data32.Height = v11;
    }
    else
    {
      v22->Data8.Width = v57;
      v22->Data8.Height = v11;
    }
    v58 = v1->LineCursor.LeftMargin;
    v59 = (float)((float)(v1->TextRectWidth - (float)v1->LineCursor.LeftMargin) * 0.5)
        - (float)(v1->LineCursor.LineWidthWithoutTrailingSpaces / 2);
    if ( v59 <= 0.0 )
      v60 = v59 - 0.5;
    else
      v60 = v59 + 0.5;
    v61 = v58 + (signed int)v60 < 0;
    v62 = v58 + (signed int)v60;
  }
  if ( v61 )
    v62 = 0;
  v22->Data32.OffsetX = v62;
  if ( v1->pDocView->Flags & 1 || v1->pDocView->AlignProps & 0x30 )
    v1->NeedRecenterLines = 1;
LABEL_127:
  v67 = v50 + v1->LineCursor.LineWidth;
  if ( v67 < v1->ParaWidth )
    v67 = v1->ParaWidth;
  v1->ParaWidth = v67;
  v68 = v1->NextOffsetY;
  v1->ParaHeight = v11 + v1->NextOffsetY - v1->ParaYOffset;
  v69 = (double)(signed int)(v11 + v13);
  if ( v69 <= 0.0 )
    v70 = v69 - 0.5;
  else
    v70 = v69 + 0.5;
  v1->NextOffsetY = v68 + (signed int)v70;
  v1->LineCursor.Indent = 0;
  v1->LineCursor.GlyphIns.FormatDataIndex = 0;
  v1->LineCursor.GlyphIns.GlyphIndex = 0;
  v1->LineCursor.LastColor = 0;
  v71 = v1->LineCursor.pLastFont.pObject;
  if ( v71 && !_InterlockedDecrement(&v71->RefCount) && v71 )
    v71->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v71->vfptr, 1u);
  v1->LineCursor.pLastFont.pObject = 0i64;
}0;
  v1->LineCursor.Indent = 0;
  v1->LineCursor.GlyphIns.FormatDataIndex = 0;
  v1->LineCursor.GlyphIns.GlyphIndex = 0;
  v1->LineCursor.LastColor = 0;
  v71 = v1->LineCursor.pLastFont.pObject;
  if ( v71 && !_InterlockedDecrement(&v71->RefCount) && v71 )
    v71->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v71->vfptr, 1u);
  v1->LineCursor.pLastFont.pObjec

// File Line: 1567
// RVA: 0x990920
char __fastcall Scaleform::Render::Text::ParagraphFormatter::HandleCustomWordWrap(Scaleform::Render::Text::ParagraphFormatter *this)
{
  Scaleform::Render::Text::ParagraphFormatter *v1; // rbx
  Scaleform::Render::Text::FontHandle *v2; // rdi
  int v3; // eax
  Scaleform::Render::Text::Paragraph::TextBuffer *v4; // rax
  __m128i v5; // xmm2
  Scaleform::Render::Font *v6; // rdi
  unsigned __int64 *v7; // rsi
  int v8; // xmm2_4
  Scaleform::Render::Text::LineBuffer::Line *v9; // rcx
  signed __int64 v10; // rcx
  unsigned int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  float v14; // xmm0_4
  signed int v15; // eax
  char *v16; // r13
  Scaleform::Render::Text::Allocator *v17; // rax
  unsigned int v18; // er10
  unsigned int v19; // edi
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v20; // rsi
  float v21; // xmm2_4
  signed __int64 v22; // r9
  unsigned __int16 *v23; // rcx
  unsigned __int16 *v24; // rdx
  unsigned __int16 *v25; // r8
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  unsigned __int16 *v30; // rcx
  int v31; // eax
  float v32; // xmm1_4
  signed __int64 v33; // r11
  __int64 v34; // rdi
  float *v35; // rcx
  int v36; // eax
  unsigned int v37; // er10
  signed __int64 v38; // rdx
  __int64 v39; // r8
  char v40; // r15
  unsigned __int64 v41; // rdx
  Scaleform::Render::Text::Paragraph::TextBuffer *v42; // rax
  Scaleform::Render::Text::GFxLineCursor *v43; // rdx
  Scaleform::Render::Text::Paragraph::TextBuffer *v44; // rax
  __int64 v45; // rdx
  unsigned int v46; // er9
  Scaleform::Render::Text::GFxLineCursor *v47; // rax
  Scaleform::Render::Text::TextFormat *v48; // rdi
  bool v49; // zf
  Scaleform::Render::Text::TextFormat *v50; // rdi
  Scaleform::Render::Text::FontHandle *v51; // rcx
  Scaleform::Render::Text::GFxLineCursor *v53; // rax
  signed __int64 v54; // rdi
  float v55; // xmm0_4
  float v56; // xmm0_4
  signed int v57; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v58; // rcx
  unsigned int v59; // esi
  __int16 v60; // dx
  float v61; // xmm1_4
  signed int v62; // ecx
  float v63; // xmm7_4
  float v64; // xmm1_4
  float v65; // xmm1_4
  unsigned int v66; // eax
  wchar_t *v67; // [rsp+20h] [rbp-A8h]
  unsigned __int64 v68; // [rsp+28h] [rbp-A0h]
  char *v69; // [rsp+30h] [rbp-98h]
  unsigned __int64 v70; // [rsp+38h] [rbp-90h]
  unsigned __int64 v71; // [rsp+40h] [rbp-88h]
  __int64 v72; // [rsp+48h] [rbp-80h]
  __int64 v73; // [rsp+50h] [rbp-78h]
  __int64 v74; // [rsp+58h] [rbp-70h]
  __int64 v75; // [rsp+60h] [rbp-68h]
  _BOOL8 v76; // [rsp+68h] [rbp-60h]
  Scaleform::Render::Text::GFxLineCursor __that; // [rsp+70h] [rbp-58h]
  char v78; // [rsp+268h] [rbp+1A0h]
  unsigned __int64 *v79; // [rsp+6D8h] [rbp+610h]
  unsigned __int64 *v80; // [rsp+6E0h] [rbp+618h]

  *(_QWORD *)&__that.GlyphIns.FormatDataIndex = -2i64;
  v1 = this;
  v2 = this->LineCursor.pLastFont.pObject;
  if ( v2 )
  {
    v3 = this->Pass;
    if ( v3 == 1 && this->HasLineFormatHandler )
    {
      v4 = this->WordWrapPoint.CharIter.pText;
      if ( v4 && this->WordWrapPoint.CharIter.CurTextIndex < v4->Size )
      {
        v5 = _mm_cvtsi32_si128(this->WordWrapPoint.LineWidth);
        v6 = this->WordWrapPoint.pLastFont.pObject->pFont.pObject;
        v7 = (unsigned __int64 *)this->WordWrapPoint.NumChars;
      }
      else
      {
        v5 = _mm_cvtsi32_si128(this->LineCursor.LineWidth);
        v6 = v2->pFont.pObject;
        v7 = (unsigned __int64 *)this->LineCursor.NumChars;
      }
      v79 = v7;
      v8 = (unsigned __int128)_mm_cvtepi32_ps(v5);
      v67 = this->pTextBufForCustomFormat;
      v68 = this->TextBufLen;
      v9 = this->pTempLine;
      if ( (v9->MemSize & 0x80000000) == 0 )
      {
        v10 = v9->Data32.TextPos;
      }
      else
      {
        v10 = v9->Data32.TextPos & 0xFFFFFF;
        if ( (_DWORD)v10 == 0xFFFFFF )
          v10 = 0xFFFFFFFFi64;
      }
      v70 = v10 - v1->pParagraph->StartIndex;
      v71 = v1->LineCursor.NumChars;
      v11 = ((unsigned int)v1->pParaFormat->PresentMask >> 9) & 3;
      if ( v11 )
      {
        v12 = v11 - 1;
        if ( v12 )
        {
          v13 = v12 - 1;
          if ( v13 )
          {
            if ( v13 == 1 )
              LOBYTE(v74) = 2;
          }
          else
          {
            LOBYTE(v74) = 3;
          }
        }
        else
        {
          LOBYTE(v74) = 1;
        }
      }
      else
      {
        LOBYTE(v74) = 0;
      }
      v14 = v1->TextRectWidth;
      *(float *)&v72 = v1->TextRectWidth;
      *((float *)&v72 + 1) = (float)v1->LineCursor.LineWidth;
      LODWORD(v73) = v8;
      v15 = (__int64)v6->vfptr[2].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, 45u);
      if ( v15 > 0 )
      {
        v6->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, v15);
        *((float *)&v73 + 1) = v14;
      }
      v75 = (__int64)v7;
      v16 = &v78;
      if ( v71 + 1 > 0x100 )
      {
        v17 = Scaleform::Render::Text::StyledText::GetAllocator((Scaleform::Render::Text::StyledText *)&v1->pDocView->pDocument.pObject->vfptr);
        v16 = (char *)v17->pHeap->vfptr->Alloc(v17->pHeap, 4 * v71 + 4, 0i64);
      }
      v18 = 0;
      v19 = v1->LineCursor.GlyphIns.GlyphIndex;
      v20 = v1->LineCursor.GlyphIns.pGlyphs;
      v21 = 0.0;
      v22 = 0i64;
      if ( (signed int)v19 < 4 )
      {
LABEL_44:
        if ( v18 < v19 )
        {
          v30 = &v20[v22].Advance;
          do
          {
            if ( v30[1] & 0xF000 )
              break;
            v31 = *v30;
            if ( (*((_BYTE *)v30 + 4) >> 6) & 1 )
              v31 = -v31;
            v21 = v21 + (float)v31;
            v30 += 4;
            ++v18;
          }
          while ( v18 < v19 );
        }
      }
      else
      {
        v23 = &v20->Advance;
        v24 = &v20->Flags;
        v25 = &v20->LenAndFontSize;
        while ( !(*v25 & 0xF000) )
        {
          v26 = *v23;
          if ( (*(_BYTE *)v24 >> 6) & 1 )
            v26 = -v26;
          v21 = v21 + (float)v26;
          if ( v25[4] & 0xF000 )
          {
            ++v18;
            break;
          }
          v27 = v23[4];
          if ( (*((_BYTE *)v24 + 8) >> 6) & 1 )
            v27 = -v27;
          v21 = v21 + (float)v27;
          if ( v25[8] & 0xF000 )
          {
            v18 += 2;
            break;
          }
          v28 = v23[8];
          if ( (*((_BYTE *)v24 + 16) >> 6) & 1 )
            v28 = -v28;
          v21 = v21 + (float)v28;
          if ( v25[12] & 0xF000 )
          {
            v18 += 3;
            break;
          }
          v29 = v23[12];
          if ( (*((_BYTE *)v24 + 24) >> 6) & 1 )
            v29 = -v29;
          v21 = v21 + (float)v29;
          v22 += 4i64;
          v25 += 16;
          v24 += 16;
          v23 += 16;
          v18 += 4;
          if ( v18 >= v19 - 3 )
            goto LABEL_44;
        }
      }
      v69 = v16;
      *(float *)&v72 = *(float *)&v72 - v21;
      *((float *)&v72 + 1) = *((float *)&v72 + 1) - v21;
      *(float *)&v73 = *(float *)&v73 - v21;
      v32 = 0.0;
      v33 = 0i64;
      if ( v18 < v19 )
      {
        v22 = (signed __int64)&v20[v18].Advance;
        v34 = v19 - v18;
        do
        {
          v35 = (float *)&v16[4 * v33];
          *v35 = v32;
          v36 = *(unsigned __int16 *)v22;
          if ( (*(_BYTE *)(v22 + 4) >> 6) & 1 )
            v36 = -v36;
          v32 = v32 + (float)v36;
          v37 = (unsigned int)*(unsigned __int16 *)(v22 + 2) >> 12;
          if ( v37 >= 2 )
          {
            v38 = v33;
            v39 = v37;
            do
            {
              v1->pTextBufForCustomFormat[v38] = 160;
              *v35 = 0.0;
              ++v38;
              ++v35;
              --v39;
            }
            while ( v39 );
          }
          v33 += v37;
          v22 += 8i64;
          --v34;
        }
        while ( v34 );
      }
      *(float *)&v16[4 * v33] = v32;
      LOBYTE(v76) = 0;
      v40 = ((__int64 (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::Render::Text::DocView *, wchar_t **, signed __int64, wchar_t *, unsigned __int64, char *, unsigned __int64))v1->pDocView->pDocumentListener.pObject->vfptr[1].__vecDelDtor)(
              v1->pDocView->pDocumentListener.pObject,
              v1->pDocView,
              &v67,
              v22,
              v67,
              v68,
              v69,
              v70);
      if ( v40 )
      {
        v1->HyphenationRequested = v76;
        v41 = v75;
        if ( !v75 )
          v41 = 1i64;
        v75 = v41;
        if ( (unsigned __int64 *)v41 != v79 )
        {
          v42 = v1->WordWrapPoint.CharIter.pText;
          if ( v42 && v1->WordWrapPoint.CharIter.CurTextIndex < v42->Size && v41 > v1->WordWrapPoint.NumChars )
          {
            Scaleform::Render::Text::LineBuffer::GlyphInserter::ResetTo(
              &v1->LineCursor.GlyphIns,
              &v1->WordWrapPoint.GlyphIns);
            v43 = &v1->WordWrapPoint;
          }
          else
          {
            v44 = v1->HalfPoint.CharIter.pText;
            if ( v44 && v1->HalfPoint.CharIter.CurTextIndex < v44->Size && v41 > v1->HalfPoint.NumChars )
            {
              Scaleform::Render::Text::LineBuffer::GlyphInserter::ResetTo(
                &v1->LineCursor.GlyphIns,
                &v1->HalfPoint.GlyphIns);
              v43 = &v1->HalfPoint;
            }
            else
            {
              v45 = v1->StartPoint.GlyphIns.GlyphIndex;
              v46 = v1->LineCursor.GlyphIns.GlyphIndex;
              if ( (unsigned int)v45 < v46 && v1->LineCursor.GlyphIns.GlyphsCount )
                Scaleform::Render::Text::LineBuffer::ReleasePartOfLine(
                  &v1->StartPoint.GlyphIns.pGlyphs[v45],
                  v46 - v45,
                  &v1->StartPoint.GlyphIns.pNextFormatData[v1->StartPoint.GlyphIns.FormatDataIndex]);
              v1->LineCursor.GlyphIns.pGlyphs = v1->StartPoint.GlyphIns.pGlyphs;
              v1->LineCursor.GlyphIns.pNextFormatData = v1->StartPoint.GlyphIns.pNextFormatData;
              v1->LineCursor.GlyphIns.GlyphIndex = v1->StartPoint.GlyphIns.GlyphIndex;
              v1->LineCursor.GlyphIns.GlyphsCount = v1->StartPoint.GlyphIns.GlyphsCount;
              v1->LineCursor.GlyphIns.FormatDataIndex = v1->StartPoint.GlyphIns.FormatDataIndex;
              v43 = &v1->StartPoint;
            }
          }
          Scaleform::Render::Text::GFxLineCursor::operator=(&v1->LineCursor, v43);
          v1->Pass = 2;
          v1->RequestedWordWrapPos = v75;
          v1->DeltaText = 0;
        }
      }
      if ( v16 != &v78 )
      {
        Scaleform::Render::Text::StyledText::GetAllocator((Scaleform::Render::Text::StyledText *)&v1->pDocView->pDocument.pObject->vfptr);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v16);
      }
      v72 = 0i64;
      v73 = 0i64;
      v74 = 0i64;
      v75 = -1i64;
      v76 = 0i64;
      __that.pPrevGrec = 0i64;
      __that.pLastFont.pObject = 0i64;
      *(_QWORD *)&__that.LastCharCode = 0i64;
      *(_QWORD *)&__that.LastAdvance = 0i64;
      *(_QWORD *)&__that.FirstGlyphWidth = 0i64;
      __that.ComposStrPosition = 0i64;
      v80 = &__that.ComposStrLength;
      __that.ComposStrLength = 0i64;
      __that.ComposStrCurPos = 0i64;
      LOWORD(__that.pDocView) = 0;
      __that.pParagraph = 0i64;
      *(_QWORD *)&__that.LineWidth = 0i64;
      *(_QWORD *)&__that.LineLength = -1i64;
      *(_QWORD *)&__that.MaxFontDescent = 0i64;
      __that.CharIter.PlaceHolder.pFormat.pObject = 0i64;
      v79 = &__that.CharIter.PlaceHolder.Index;
      *(_OWORD *)&__that.CharIter.PlaceHolder.Index = 0ui64;
      LOWORD(__that.CharIter.pFormatInfo) = 0;
      __that.CharIter.FormatIterator.pArray = 0i64;
      LODWORD(__that.CharIter.FormatIterator.Index) = 0;
      __that.CharIter.pText = 0i64;
      __that.CharIter.CurTextIndex = 0i64;
      __that.CharInfoHolder.pFormat.pObject = 0i64;
      LODWORD(__that.CharInfoHolder.Index) = 0;
      *(_QWORD *)&__that.CharInfoHolder.Character = 0i64;
      __that.Indent = (signed int)FLOAT_1_0;
      LOWORD(__that.LeftMargin) = 0;
      *(_QWORD *)&__that.RightMargin = 0i64;
      v47 = Scaleform::Render::Text::GFxLineCursor::operator=(&v1->HalfPoint, &__that);
      Scaleform::Render::Text::GFxLineCursor::operator=(&v1->StartPoint, v47);
      v79 = &__that.CharIter.PlaceHolder.Index;
      v48 = (Scaleform::Render::Text::TextFormat *)__that.CharIter.PlaceHolder.Index;
      if ( __that.CharIter.PlaceHolder.Index )
      {
        v49 = (*(_DWORD *)(__that.CharIter.PlaceHolder.Index + 8))-- == 1;
        if ( v49 )
        {
          Scaleform::Render::Text::TextFormat::~TextFormat(v48);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v48);
        }
      }
      v79 = &__that.ComposStrLength;
      v50 = (Scaleform::Render::Text::TextFormat *)__that.ComposStrLength;
      if ( __that.ComposStrLength )
      {
        v49 = (*(_DWORD *)(__that.ComposStrLength + 8))-- == 1;
        if ( v49 )
        {
          Scaleform::Render::Text::TextFormat::~TextFormat(v50);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v50);
        }
      }
      v51 = __that.pLastFont.pObject;
      if ( __that.pLastFont.pObject
        && _InterlockedExchangeAdd(&__that.pLastFont.pObject->RefCount, 0xFFFFFFFF) == 1
        && v51 )
      {
        v51->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v51->vfptr, 1u);
      }
      if ( v40 && v1->Pass == 2 )
        return 1;
    }
    else if ( v3 == 2 )
    {
      Scaleform::Render::Text::GFxLineCursor::GFxLineCursor((Scaleform::Render::Text::GFxLineCursor *)((char *)&__that + 240));
      Scaleform::Render::Text::GFxLineCursor::operator=(&v1->WordWrapPoint, v53);
      Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor((Scaleform::Render::Text::GFxLineCursor *)((char *)&__that + 240));
      v1->Pass = 1;
    }
    if ( v1->HyphenationRequested )
    {
      v54 = (signed __int64)&v1->LineCursor.GlyphIns.pGlyphs[v1->LineCursor.GlyphIns.GlyphIndex];
      *(_QWORD *)v54 = 0i64;
      v55 = v1->LineCursor.LastAdvance;
      if ( v55 <= 0.0 )
        v56 = v55 - 0.5;
      else
        v56 = v55 + 0.5;
      v57 = (signed int)v56;
      v58 = v1->LineCursor.pPrevGrec;
      if ( v58 )
      {
        if ( v57 < 0 )
        {
          v58->Advance = abs(v57);
          v58->Flags |= 0x40u;
        }
        else
        {
          v58->Advance = v57;
          v58->Flags &= 0xFFBFu;
        }
      }
      v59 = (__int64)v1->LineCursor.pLastFont.pObject->pFont.pObject->vfptr[2].__vecDelDtor(
                       (Scaleform::RefCountImplCore *)&v1->LineCursor.pLastFont.pObject->pFont.pObject->vfptr,
                       45u);
      *(_WORD *)v54 = v59;
      *(_WORD *)(v54 + 4) &= 0xFFFu;
      v60 = *(_WORD *)(v54 + 4);
      v61 = v1->FontSize;
      if ( v61 < 256.0 && (v56 = v61 * 16.0, v62 = (signed int)(float)(v61 * 16.0), v62 & 0xF) )
      {
        *(_WORD *)(v54 + 6) |= 0x10u;
        *(_WORD *)(v54 + 4) = v60 ^ (v60 ^ v62) & 0xFFF;
      }
      else
      {
        *(_WORD *)(v54 + 6) &= 0xFFEFu;
        *(_WORD *)(v54 + 4) = v60 ^ (v60 ^ (signed int)v61) & 0xFFF;
      }
      v1->LineCursor.LineWidth = v1->NewLineWidth;
      v1->LineCursor.pLastFont.pObject->pFont.pObject->vfptr[3].__vecDelDtor(
        (Scaleform::RefCountImplCore *)v1->LineCursor.pLastFont.pObject->pFont.pObject,
        v59);
      v63 = v56 * v1->Scale;
      *(_OWORD *)&__that.GlyphIns.pNextFormatData = 0i64;
      v64 = (float)(*(float *)(((__int64 (__fastcall *)(Scaleform::Render::Font *, _QWORD, Scaleform::Render::Text::LineBuffer::FormatDataEntry **))v1->pFont->vfptr[7].__vecDelDtor)(
                                 v1->pFont,
                                 v59,
                                 &__that.GlyphIns.pNextFormatData)
                             + 8)
                  * v1->Scale)
          + 20.0;
      if ( v63 >= v64 )
        v64 = v63;
      if ( v64 <= 0.0 )
        v65 = v64 - 0.5;
      else
        v65 = v64 + 0.5;
      v1->LineCursor.LastAdvance = (float)(signed int)v65;
      v1->LineCursor.LastGlyphWidth = (signed int)v65;
      v1->LineCursor.LastGlyphIndex = v59;
      v1->LineCursor.NumOfTrailingSpaces = 0;
      v1->LineCursor.LineWidthWithoutTrailingSpaces = v1->NewLineWidth + (signed int)v65;
      v1->HyphenationRequested = 0;
      v1->LineCursor.pPrevGrec = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)v54;
      if ( v1->LineCursor.GlyphIns.pGlyphs )
      {
        v66 = v1->LineCursor.GlyphIns.GlyphIndex;
        if ( v66 < v1->LineCursor.GlyphIns.GlyphsCount )
          v1->LineCursor.GlyphIns.GlyphIndex = v66 + 1;
      }
    }
  }
  return 0;
}

// File Line: 1749
// RVA: 0x95EB30
char __fastcall Scaleform::Render::Text::ParagraphFormatter::CheckWordWrap(Scaleform::Render::Text::ParagraphFormatter *this)
{
  Scaleform::Render::Text::ParagraphFormatter *v1; // rdi
  int v2; // ecx
  char v3; // bp
  Scaleform::Render::Text::Paragraph::TextBuffer *v4; // rax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v5; // rsi
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *v6; // r14
  __int64 v7; // rbx
  unsigned int v8; // er15
  __int64 v9; // rbp
  unsigned int v10; // edx
  Scaleform::Render::Text::GFxLineCursor *v11; // rax
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // rbx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v14; // rax
  Scaleform::Render::Text::LineBuffer::Line *v15; // rcx
  Scaleform::Render::Text::GFxLineCursor v17; // [rsp+28h] [rbp-120h]

  v1 = this;
  v2 = this->Pass;
  if ( v2 == 1
    && v1->pDocView->Flags & 8
    && !v1->isSpace
    && (float)(v1->LineCursor.Indent + v1->LineCursor.LeftMargin + v1->AdjLineWidth + v1->NewLineWidth) > (float)(v1->TextRectWidth - (float)v1->LineCursor.RightMargin)
    || v2 == 2 && v1->LineCursor.NumChars == v1->RequestedWordWrapPos )
  {
    if ( Scaleform::Render::Text::ParagraphFormatter::HandleCustomWordWrap(v1) )
      return 1;
    v1->NewLineWidth = 0;
    v3 = 0;
    v4 = v1->WordWrapPoint.CharIter.pText;
    if ( v4 && v1->WordWrapPoint.CharIter.CurTextIndex < v4->Size )
    {
      v5 = v1->WordWrapPoint.GlyphIns.pGlyphs;
      v6 = v1->WordWrapPoint.GlyphIns.pNextFormatData;
      v7 = v1->WordWrapPoint.GlyphIns.GlyphIndex;
      v8 = v1->WordWrapPoint.GlyphIns.GlyphsCount;
      v9 = v1->WordWrapPoint.GlyphIns.FormatDataIndex;
      v10 = v1->LineCursor.GlyphIns.GlyphIndex;
      if ( (unsigned int)v7 < v10 && v1->LineCursor.GlyphIns.GlyphsCount > 0 )
        Scaleform::Render::Text::LineBuffer::ReleasePartOfLine(&v5[v7], v10 - v7, &v6[v9]);
      v1->LineCursor.GlyphIns.pGlyphs = v5;
      v1->LineCursor.GlyphIns.pNextFormatData = v6;
      v1->LineCursor.GlyphIns.GlyphIndex = v7;
      v1->LineCursor.GlyphIns.GlyphsCount = v8;
      v1->LineCursor.GlyphIns.FormatDataIndex = v9;
      Scaleform::Render::Text::GFxLineCursor::operator=(&v1->LineCursor, &v1->WordWrapPoint);
      v1->isSpace = 0;
      v3 = 1;
      v1->DeltaText = 0;
    }
    Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&v17);
    Scaleform::Render::Text::GFxLineCursor::operator=(&v1->WordWrapPoint, v11);
    Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(&v17);
    v12 = v1->pParagraph->StartIndex;
    v13 = Scaleform::Render::Text::GFxLineCursor::operator*(&v1->LineCursor)->Index + v12;
    v14 = v1->LineCursor.pPrevGrec;
    if ( v14 )
      v14->Flags |= 8u;
    *(_QWORD *)&v1->LineCursor.LastAdvance = 0i64;
    v1->LineCursor.pPrevGrec = 0i64;
    Scaleform::Render::Text::ParagraphFormatter::FinalizeLine(v1);
    v1->LineCursor.pPrevGrec = 0i64;
    *(_QWORD *)&v1->LineCursor.MaxFontDescent = 0i64;
    *(_QWORD *)&v1->LineCursor.LineLength = 0i64;
    v1->LineCursor.LastAdvance = 0.0;
    *(_WORD *)&v1->LineCursor.LastKerning = 0;
    v1->LineCursor.LineWidthWithoutTrailingSpaces = 0;
    *(_QWORD *)&v1->LineCursor.NumOfSpaces = 0i64;
    v1->LineCursor.NumChars = 0i64;
    v1->LineCursor.LastCharCode = 0;
    v1->TabStopsIndex = 0;
    v15 = v1->pTempLine;
    if ( (v15->MemSize & 0x80000000) == 0 )
    {
      v15->Data32.TextPos = v13;
    }
    else
    {
      v15->Data32.TextPos &= 0xFF000000;
      v15->Data32.TextPos |= v13 & 0xFFFFFF;
    }
    if ( v3 )
    {
      v1->LineCursor.LineWidth = 0;
      return 1;
    }
  }
  return 0;
}

// File Line: 1813
// RVA: 0x97BF20
void __fastcall Scaleform::Render::Text::ParagraphFormatter::Format(Scaleform::Render::Text::ParagraphFormatter *this, Scaleform::Render::Text::Paragraph *paragraph)
{
  Scaleform::Render::Text::ParagraphFormatter *v2; // r15
  Scaleform::Render::Text::ParagraphFormat *v3; // rdx
  unsigned __int16 v4; // cx
  __int64 v5; // rbx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v6; // rdi
  Scaleform::Render::Text::Paragraph::CharacterInfo *v7; // rax
  Scaleform::Render::Text::TextFormat *v8; // rcx
  Scaleform::Render::Text::FontHandle *v9; // rax
  Scaleform::Render::Text::FontHandle *v10; // rsi
  unsigned __int16 v11; // r14
  float v12; // xmm0_4
  signed int v13; // eax
  unsigned __int16 v14; // r14
  unsigned int v15; // ebx
  unsigned int v16; // eax
  Scaleform::Render::Text::FontHandle *v17; // rcx
  Scaleform::Render::Text::ParagraphFormat *v18; // rdx
  unsigned int *v19; // r12
  unsigned int *v20; // rax
  Scaleform::Render::Text::ImageDesc *v21; // rbx
  Scaleform::Render::Text::Paragraph::TextBuffer *v22; // rax
  Scaleform::Render::Text::Paragraph::CharactersIterator *v23; // r14
  Scaleform::Render::Text::Paragraph::CharactersIterator *v24; // rax
  Scaleform::Render::Text::Paragraph::CharactersIterator *v25; // rsi
  Scaleform::Render::Text::TextFormat *v26; // rax
  Scaleform::Render::Text::TextFormat *v27; // rdi
  bool v28; // zf
  float v29; // xmm6_4
  Scaleform::Render::Text::DocView::ImageSubstitutor *v30; // r10
  Scaleform::Render::Text::Paragraph::TextBuffer *v31; // rax
  unsigned __int64 v32; // r8
  unsigned __int64 v33; // rcx
  unsigned __int64 v34; // r8
  const wchar_t *v35; // rdx
  Scaleform::Render::Text::ImageDesc *v36; // rax
  Scaleform::Render::Text::TextFormat *v37; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v38; // rax
  Scaleform::Render::Text::HTMLImageTagDesc *v39; // rdi
  bool v40; // al
  wchar_t v41; // cx
  unsigned __int64 v42; // rax
  int v43; // er8
  int v44; // eax
  bool v45; // al
  Scaleform::Render::Text::FontHandle *v46; // rcx
  Scaleform::Render::Text::FontHandle *v47; // rcx
  Scaleform::Render::Text::FontHandle *v48; // rax
  Scaleform::Render::Text::FontHandle *v49; // rdi
  Scaleform::Render::Text::FontHandle *v50; // rcx
  Scaleform::Render::Font *v51; // rdi
  float v52; // xmm0_4
  float v53; // xmm0_4
  wchar_t v54; // dx
  unsigned __int8 v55; // al
  int v56; // eax
  Scaleform::Render::Text::TextFormat *v57; // rcx
  __int16 v58; // r14
  char v59; // si
  char v60; // di
  char v61; // bl
  Scaleform::StringDH *v62; // rax
  __int64 v63; // r9
  __int64 v64; // r12
  Scaleform::Render::Text::DocView::DocumentListener *v65; // rcx
  Scaleform::String *v66; // rax
  int v67; // er14
  char *v68; // rsi
  unsigned __int64 v69; // rbx
  volatile signed __int32 *v70; // rdi
  Scaleform::StringDH *v71; // rax
  wchar_t v72; // cx
  unsigned __int64 v73; // rax
  int v74; // er8
  int v75; // eax
  unsigned int v76; // eax
  float v77; // xmm0_4
  float v78; // xmm0_4
  float v79; // xmm0_4
  float v80; // xmm0_4
  float v81; // xmm0_4
  signed int v82; // eax
  float v83; // xmm0_4
  float v84; // xmm0_4
  float v85; // xmm1_4
  float v86; // xmm1_4
  int v87; // edx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v88; // rcx
  signed __int64 v89; // rdi
  float v90; // xmm1_4
  float v91; // xmm0_4
  float v92; // xmm0_4
  float v93; // xmm1_4
  Scaleform::Render::Text::TextFormat *v94; // rcx
  unsigned int v95; // esi
  float v96; // xmm1_4
  signed int v97; // eax
  __int16 v98; // ax
  Scaleform::Render::Text::FontHandle *v99; // rdx
  wchar_t v100; // dx
  unsigned __int8 v101; // al
  __int64 v102; // rdx
  Scaleform::Render::Text::TextFormat *v103; // rcx
  Scaleform::Render::Text::FontHandle *v104; // rcx
  Scaleform::Render::Text::FontHandle *v105; // rcx
  __int64 v106; // r8
  int v107; // edx
  int v108; // eax
  __m128 v109; // xmm1
  signed int v110; // ecx
  float v111; // xmm1_4
  __m128 v112; // xmm3
  __m128 v113; // xmm2
  signed int v114; // ecx
  float v115; // xmm1_4
  Scaleform::Render::Text::TextFormat *v116; // rcx
  int v117; // eax
  unsigned int v118; // eax
  unsigned int v119; // eax
  __int64 v120; // rdi
  Scaleform::Render::Text::ParagraphFormatter *v121; // rcx
  int *v122; // [rsp+20h] [rbp-E0h]
  __int64 v123; // [rsp+30h] [rbp-D0h]
  int v124; // [rsp+50h] [rbp-B0h]
  signed __int64 v125; // [rsp+58h] [rbp-A8h]
  __int128 v126; // [rsp+60h] [rbp-A0h]
  Scaleform::String v127; // [rsp+70h] [rbp-90h]
  unsigned __int64 v128; // [rsp+78h] [rbp-88h]
  __int64 v129; // [rsp+80h] [rbp-80h]
  unsigned __int64 ptextLen; // [rsp+88h] [rbp-78h]
  int v131; // [rsp+90h] [rbp-70h]
  char *v132; // [rsp+98h] [rbp-68h]
  __int64 v133; // [rsp+A0h] [rbp-60h]
  __int64 v134; // [rsp+A8h] [rbp-58h]
  __int64 v135; // [rsp+B0h] [rbp-50h]
  char v136; // [rsp+B8h] [rbp-48h]
  Scaleform::MemoryHeap *v137; // [rsp+C0h] [rbp-40h]
  Scaleform::Render::Text::FontHandle *v138; // [rsp+C8h] [rbp-38h]
  __int64 v139; // [rsp+D0h] [rbp-30h]
  __int64 v140; // [rsp+D8h] [rbp-28h]
  Scaleform::Render::Text::ImageDesc *v141; // [rsp+1C0h] [rbp+C0h]
  unsigned __int64 v142; // [rsp+1D0h] [rbp+D0h]
  __int64 v143; // [rsp+1D8h] [rbp+D8h]

  v139 = -2i64;
  v2 = this;
  v124 = 0;
  this->pDocView->RTFlags &= 0xBFu;
  Scaleform::Render::Text::ParagraphFormatter::InitParagraph(this, paragraph);
  v2->LineCursor.LeftMargin = 0;
  v3 = v2->pParaFormat;
  v4 = v3->PresentMask;
  if ( (v4 & 0x80u) == 0 || (v4 & 0x8000u) == 0 )
  {
    v2->LineCursor.Indent = 20 * v3->Indent;
  }
  else
  {
    v5 = v2->LineCursor.GlyphIns.GlyphIndex;
    v6 = v2->LineCursor.GlyphIns.pGlyphs;
    v6[v5] = 0i64;
    v7 = Scaleform::Render::Text::GFxLineCursor::operator*(&v2->LineCursor);
    v8 = v7->pFormat.pObject;
    v2->FindFontInfo.pCurrentFormat = v7->pFormat.pObject;
    if ( v8 )
    {
      v9 = Scaleform::Render::Text::DocView::FindFont(v2->pDocView, &v2->FindFontInfo, 0);
      v10 = v9;
      if ( v9 )
        _InterlockedExchangeAdd(&v9->RefCount, 1u);
      v138 = v9;
      v6[v5].Index = (__int64)v9->pFont.pObject->vfptr[2].__vecDelDtor(
                                (Scaleform::RefCountImplCore *)&v9->pFont.pObject->vfptr,
                                8226u);
      v6[v5].Advance = 300;
      v6[v5].Flags &= 0xFFBFu;
      v11 = v6[v5].Flags;
      v12 = (float)(Scaleform::Render::Text::ParagraphFormatter::GetActualFontSize(v2) * 2.0) * 0.33333334;
      if ( v12 < 256.0 && (v13 = (signed int)(float)(v12 * 16.0), v13 & 0xF) )
      {
        v14 = v11 | 0x10;
      }
      else
      {
        v14 = v11 & 0xFFEF;
        v13 = (signed int)v12;
      }
      v6[v5].LenAndFontSize &= 0xF000u;
      v6[v5].LenAndFontSize |= v13 & 0xFFF;
      v6[v5].Flags = v14;
      v6[v5].LenAndFontSize &= 0xFFFu;
      v15 = v2->FindFontInfo.pCurrentFormat->ColorV;
      v2->LineCursor.GlyphIns.pGlyphs[v2->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x4000u;
      v2->LineCursor.GlyphIns.pGlyphs[v2->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x2000u;
      v2->LineCursor.GlyphIns.pNextFormatData[v2->LineCursor.GlyphIns.FormatDataIndex++].pFont = v10;
      _InterlockedExchangeAdd(&v10->RefCount, 1u);
      v2->LineCursor.GlyphIns.pGlyphs[v2->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x4000u;
      v2->LineCursor.GlyphIns.pGlyphs[v2->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x1000u;
      v2->LineCursor.GlyphIns.pNextFormatData[v2->LineCursor.GlyphIns.FormatDataIndex++].ColorV = v15;
      if ( v2->LineCursor.GlyphIns.pGlyphs )
      {
        v16 = v2->LineCursor.GlyphIns.GlyphIndex;
        if ( v16 < v2->LineCursor.GlyphIns.GlyphsCount )
          v2->LineCursor.GlyphIns.GlyphIndex = v16 + 1;
      }
      _InterlockedExchangeAdd(&v10->RefCount, 1u);
      v17 = v2->LineCursor.pLastFont.pObject;
      if ( v17 && !_InterlockedDecrement(&v17->RefCount) && v17 )
        v17->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v17->vfptr, 1u);
      v2->LineCursor.pLastFont.pObject = v10;
      v2->LineCursor.LastColor = v15;
      if ( !_InterlockedDecrement(&v10->RefCount) )
        v10->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, 1u);
    }
    v2->LineCursor.LeftMargin = 700;
    v2->LineCursor.LineWidth = 700;
    v2->LineCursor.Indent = -300;
  }
  v18 = v2->pParaFormat;
  v2->LineCursor.LeftMargin += 20 * (v18->BlockIndent + v18->LeftMargin);
  v2->LineCursor.RightMargin = 20 * v18->RightMargin;
  v19 = &v2->TabStopsNum;
  v20 = v18->pTabStops;
  if ( v20 )
  {
    if ( v2 != (Scaleform::Render::Text::ParagraphFormatter *)-1140i64 )
      *v19 = *v20;
    v125 = (signed __int64)(v18->pTabStops + 1);
  }
  else
  {
    v125 = 0i64;
  }
  v21 = 0i64;
  while ( 1 )
  {
    v22 = v2->LineCursor.CharIter.pText;
    if ( !v22 || v2->LineCursor.CharIter.CurTextIndex >= v22->Size )
      break;
    v23 = &v2->LineCursor.CharIter;
    v2->LineCursor.CharInfoHolder.Index = Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(&v2->LineCursor.CharIter)->PlaceHolder.Index;
    v24 = Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(&v2->LineCursor.CharIter);
    v25 = v24;
    v26 = v24->PlaceHolder.pFormat.pObject;
    if ( v26 )
      ++v26->RefCount;
    v27 = v2->LineCursor.CharInfoHolder.pFormat.pObject;
    if ( v27 )
    {
      v28 = v27->RefCount-- == 1;
      if ( v28 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v27);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v27);
      }
    }
    v2->LineCursor.CharInfoHolder.pFormat.pObject = v25->PlaceHolder.pFormat.pObject;
    v2->LineCursor.CharInfoHolder.Index = v25->PlaceHolder.Index;
    v2->LineCursor.CharInfoHolder.Character = v25->PlaceHolder.Character;
    if ( v2->LineCursor.pDocView->Flags & 0x10 && v2->LineCursor.CharInfoHolder.Character )
      v2->LineCursor.CharInfoHolder.Character = 42;
    if ( v2->Pass == 1 )
    {
      if ( v2->pDocView->Flags & 8
        && !v21
        && Scaleform::Render::Text::WordWrapHelper::IsLineBreakOpportunityAt(
             7u,
             v2->LineCursor.LastCharCode,
             v2->LineCursor.CharInfoHolder.Character) )
      {
        Scaleform::Render::Text::GFxLineCursor::operator=(&v2->WordWrapPoint, &v2->LineCursor);
      }
      if ( v2->Pass == 1 && v2->HasLineFormatHandler )
      {
        v29 = v2->TextRectWidth;
        if ( !v2->LineCursor.LineWidth && !v2->StartPoint.pDocView )
          Scaleform::Render::Text::GFxLineCursor::operator=(&v2->StartPoint, &v2->LineCursor);
        if ( (float)v2->LineCursor.LineWidth > (float)(v29 * 0.5) && !v2->HalfPoint.pDocView )
          Scaleform::Render::Text::GFxLineCursor::operator=(&v2->HalfPoint, &v2->LineCursor);
      }
    }
    v2->DeltaText = 1;
    if ( v21 )
    {
      v28 = v21->RefCount-- == 1;
      if ( v28 )
        v21->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v21->vfptr, 1u);
    }
    v21 = 0i64;
    v141 = 0i64;
    v30 = v2->pDocView->pImageSubstitutor;
    if ( !v30 )
      goto LABEL_245;
    v31 = v2->LineCursor.CharIter.pText;
    if ( v31 && (v32 = v31->Size, v33 = v2->LineCursor.CharIter.CurTextIndex, v33 < v32) )
    {
      v34 = v32 - v33;
      v128 = v34;
      v35 = &v31->pText[v33];
    }
    else
    {
      v34 = 0i64;
      v128 = 0i64;
      v35 = 0i64;
    }
    v36 = Scaleform::Render::Text::DocView::ImageSubstitutor::FindImageDesc(v30, v35, v34, &ptextLen);
    v21 = v36;
    if ( v36 )
      ++v36->RefCount;
    v141 = v36;
    if ( v36 )
    {
      v2->DeltaText = ptextLen;
    }
    else
    {
LABEL_245:
      v37 = v2->LineCursor.CharInfoHolder.pFormat.pObject;
      if ( v37 && (v37->PresentMask >> 9) & 1 && v2->LineCursor.CharInfoHolder.Character )
      {
        v38 = Scaleform::Render::Text::TextFormat::GetImageDesc(v37);
        v39 = v38;
        if ( v38 )
          ++v38->RefCount;
        if ( v21 )
        {
          v28 = v21->RefCount-- == 1;
          if ( v28 )
            v21->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v21->vfptr, 1u);
        }
        v21 = (Scaleform::Render::Text::ImageDesc *)&v39->vfptr;
        v141 = (Scaleform::Render::Text::ImageDesc *)&v39->vfptr;
      }
    }
    v2->pFont = 0i64;
    v2->Scale = 1.0;
    v2->FontSize = -1.0;
    if ( v21 )
    {
      v2->FindFontInfo.pCurrentFormat = v2->LineCursor.CharInfoHolder.pFormat.pObject;
      v83 = v21->ScreenWidth;
      if ( v83 <= 0.0 )
        v84 = v83 - 0.5;
      else
        v84 = v83 + 0.5;
      v82 = (signed int)v84;
      v2->GlyphWidth = (signed int)v84;
      v2->GlyphAdvance = (float)(signed int)v84 + 40.0;
      v85 = v2->LineCursor.LastAdvance;
      if ( v85 <= 0.0 )
        v86 = v85 - 0.5;
      else
        v86 = v85 + 0.5;
      v2->LastAdvance = (signed int)v86;
      v2->GlyphIndex = -1;
      *(_WORD *)&v2->isSpace = 0;
      goto LABEL_156;
    }
    v40 = v2->LineCursor.CharInfoHolder.Character == 160;
    v2->isNbsp = v40;
    v41 = v2->LineCursor.CharInfoHolder.Character;
    v45 = 1;
    if ( v41 )
    {
      if ( v40
        || (v42 = (unsigned __int64)v41 >> 8, (v43 = Scaleform::UnicodeSpaceBits[v42]) == 0)
        || v43 != 1
        && (v44 = Scaleform::UnicodeSpaceBits[v43 + (((unsigned int)v41 >> 4) & 0xF)], !_bittest(&v44, v41 & 0xF)) )
      {
        v45 = 0;
      }
    }
    v2->isSpace = v45;
    v46 = v2->FindFontInfo.pCurrentFont.pObject;
    if ( v46 && v2->FindFontInfo.pCurrentFormat == v2->LineCursor.CharInfoHolder.pFormat.pObject )
    {
      if ( v46 )
      {
        _InterlockedExchangeAdd(&v46->RefCount, 1u);
        v21 = v141;
      }
      v47 = v2->pFontHandle.pObject;
      if ( v47 )
      {
        if ( !_InterlockedDecrement(&v47->RefCount) && v47 )
          v47->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v47->vfptr, 1u);
        v21 = v141;
      }
      v2->pFontHandle.pObject = v2->FindFontInfo.pCurrentFont.pObject;
    }
    else
    {
      v2->FindFontInfo.pCurrentFormat = v2->LineCursor.CharInfoHolder.pFormat.pObject;
      v48 = Scaleform::Render::Text::DocView::FindFont(
              v2->pDocView,
              &v2->FindFontInfo,
              v2->LineCursor.CharInfoHolder.Character == 0);
      v49 = v48;
      if ( v48 )
      {
        _InterlockedExchangeAdd(&v48->RefCount, 1u);
        v21 = v141;
      }
      v50 = v2->pFontHandle.pObject;
      if ( v50 )
      {
        if ( !_InterlockedDecrement(&v50->RefCount) && v50 )
          v50->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v50->vfptr, 1u);
        v21 = v141;
      }
      v2->pFontHandle.pObject = v49;
      if ( !v49 )
        goto LABEL_233;
    }
    v51 = v2->pFontHandle.pObject->pFont.pObject;
    v2->pFont = v51;
    v52 = Scaleform::Render::Text::ParagraphFormatter::GetActualFontSize(v2);
    v2->FontSize = v52;
    v53 = (float)(v52 * 20.0) * 0.0009765625;
    v2->Scale = v53;
    v54 = v2->LineCursor.CharInfoHolder.Character;
    v55 = 10;
    if ( v2->pDocView->pDocument.pObject->RTFlags & 2 )
      v55 = 13;
    if ( v54 != v55 && v54 )
    {
      if ( v54 == 9 )
      {
        v2->GlyphIndex = -1;
        v2->GlyphAdvance = 0.0;
      }
      else
      {
        v56 = ((__int64 (__fastcall *)(Scaleform::Render::Font *))v51->vfptr[2].__vecDelDtor)(v51);
        v2->GlyphIndex = v56;
        if ( v56 == -1 )
        {
          if ( v2->isNbsp )
            v2->GlyphIndex = (__int64)v2->pFont->vfptr[2].__vecDelDtor(
                                        (Scaleform::RefCountImplCore *)&v2->pFont->vfptr,
                                        32u);
          if ( v2->GlyphIndex == -1 && v2->pLog && !(v2->pDocView->RTFlags & 0x10) )
          {
            v131 = 1;
            v132 = 0i64;
            v133 = 0i64;
            v134 = 0i64;
            v135 = 512i64;
            v136 = 0;
            v137 = Scaleform::Memory::pGlobalHeap;
            v57 = v2->FindFontInfo.pCurrentFormat;
            v58 = v57->PresentMask >> 12;
            v59 = ((unsigned __int8)v2->pDocView->Flags >> 5) & 1;
            v60 = (unsigned __int8)v57->FormatFlags >> 1;
            v61 = v57->FormatFlags & 1;
            v62 = Scaleform::Render::Text::TextFormat::GetFontList(v57);
            LOBYTE(v63) = (v58 & 1) == 0;
            v122 = &v131;
            v64 = ((__int64 (__fastcall *)(Scaleform::Render::Text::FontManagerBase *, unsigned __int64, _QWORD, __int64))v2->pDocView->pFontManager.pObject->vfptr[1].__vecDelDtor)(
                    v2->pDocView->pFontManager.pObject,
                    (v62->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
                    (v59 != 0 ? 0x10 : 0) | ((v60 & 1) != 0) | (v61 != 0 ? 2 : 0),
                    v63);
            v140 = v64;
            v65 = v2->pDocView->pDocumentListener.pObject;
            if ( v65 )
            {
              v66 = (Scaleform::String *)v65->vfptr[14].__vecDelDtor(
                                           (Scaleform::RefCountNTSImplCore *)&v65->vfptr,
                                           (unsigned int)&v129);
              v124 |= 1u;
            }
            else
            {
              v142 = (unsigned __int64)&Scaleform::String::NullData;
              _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
              v66 = (Scaleform::String *)&v142;
              v124 |= 2u;
            }
            Scaleform::String::String(&v127, v66);
            if ( v124 & 2 )
            {
              v124 &= 0xFFFFFFFD;
              if ( !_InterlockedDecrement((volatile signed __int32 *)((v142 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            }
            if ( v124 & 1 )
            {
              v124 &= 0xFFFFFFFE;
              if ( !_InterlockedDecrement((volatile signed __int32 *)((v129 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            }
            v2->pFont->vfptr[20].__vecDelDtor((Scaleform::RefCountImplCore *)&v2->pFont->vfptr, (unsigned int)&v143);
            v67 = ((__int64 (*)(void))v2->pFont->vfptr[18].__vecDelDtor)();
            v68 = &customWorldMapCaption;
            if ( v132 )
              v68 = v132;
            v69 = v143 & 0xFFFFFFFFFFFFFFFCui64;
            v70 = (volatile signed __int32 *)(v127.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
            v71 = Scaleform::Render::Text::TextFormat::GetFontList(v2->FindFontInfo.pCurrentFormat);
            LODWORD(v123) = v67;
            LODWORD(v122) = v2->LineCursor.CharInfoHolder.Character;
            Scaleform::Log::LogError(
              v2->pLog,
              "Missing \"%s\" glyph '%c' (0x%x) in \"%s\".\nFont has %u glyphs, ranges %s.\nSearch log: \n%s",
              (v71->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
              (unsigned int)SLOBYTE(v2->LineCursor.CharInfoHolder.Character),
              v122,
              v70 + 3,
              v123,
              v69 + 12,
              v68);
            v2->pDocView->RTFlags |= 0x10u;
            if ( !_InterlockedDecrement((volatile signed __int32 *)((v143 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            if ( !_InterlockedDecrement(v70 + 2) )
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v70);
            if ( v64 && !_InterlockedDecrement((volatile signed __int32 *)(v64 + 8)) )
              (**(void (__fastcall ***)(__int64, signed __int64))v64)(v64, 1i64);
            if ( v132 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v19 = &v2->TabStopsNum;
            v23 = &v2->LineCursor.CharIter;
            v21 = v141;
          }
        }
        v2->pFont->vfptr[3].__vecDelDtor((Scaleform::RefCountImplCore *)v2->pFont, v2->GlyphIndex);
        v2->GlyphAdvance = v53 * v2->Scale;
        v72 = v2->LineCursor.CharInfoHolder.Character;
        v73 = (unsigned __int64)v2->LineCursor.CharInfoHolder.Character >> 8;
        v74 = Scaleform::UnicodeNonSpacingMarksBits[v73];
        if ( Scaleform::UnicodeNonSpacingMarksBits[v73] )
        {
          if ( v74 == 1
            || (v75 = Scaleform::UnicodeNonSpacingMarksBits[v74 + (((unsigned int)v72 >> 4) & 0xF)],
                _bittest(&v75, v72 & 0xF)) )
          {
            v2->GlyphAdvance = 0.0;
          }
        }
      }
    }
    else
    {
      v76 = (__int64)v51->vfptr[2].__vecDelDtor((Scaleform::RefCountImplCore *)&v51->vfptr, 32u);
      v2->GlyphIndex = v76;
      v2->pFont->vfptr[3].__vecDelDtor((Scaleform::RefCountImplCore *)v2->pFont, v76);
      v2->GlyphAdvance = (float)(v53 * 0.5) * v2->Scale;
    }
    if ( v2->LineCursor.pPrevGrec )
    {
      v77 = 0.0;
      if ( v2->LineCursor.LastKerning )
      {
        ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, _QWORD))v2->LineCursor.pLastFont.pObject->pFont.pObject->vfptr[4].__vecDelDtor)(
          v2->LineCursor.pLastFont.pObject->pFont.pObject,
          v2->LineCursor.LastCharCode,
          v2->LineCursor.CharInfoHolder.Character);
        v77 = 0.0 * v2->Scale;
      }
      v78 = v77 + v2->LineCursor.LastAdvance;
      if ( v78 > 0.0 )
      {
        v79 = v78 + 0.5;
        goto LABEL_143;
      }
    }
    else
    {
      v78 = v2->LineCursor.LastAdvance;
      if ( v78 > 0.0 )
      {
        v79 = v78 + 0.5;
        goto LABEL_143;
      }
    }
    v79 = v78 - 0.5;
LABEL_143:
    v2->LastAdvance = (signed int)v79;
    v80 = v2->GlyphAdvance;
    if ( v80 <= 0.0 )
      v81 = v80 - 0.5;
    else
      v81 = v80 + 0.5;
    v82 = (signed int)v81;
    v2->GlyphWidth = (signed int)v81;
    if ( v2->isSpace )
      v82 = 0;
LABEL_156:
    v2->AdjLineWidth = v82;
    v87 = v2->LastAdvance;
    v2->NewLineWidth = v87 + v2->LineCursor.LineWidth;
    v88 = v2->LineCursor.pPrevGrec;
    if ( v88 )
    {
      if ( v87 < 0 )
      {
        v88->Advance = abs((_WORD)v87);
        v88->Flags |= 0x40u;
      }
      else
      {
        v88->Advance = v87;
        v88->Flags &= 0xFFBFu;
      }
    }
    if ( !Scaleform::Render::Text::ParagraphFormatter::CheckWordWrap(v2) )
    {
      v89 = (signed __int64)&v2->LineCursor.GlyphIns.pGlyphs[v2->LineCursor.GlyphIns.GlyphIndex];
      *(_QWORD *)v89 = 0i64;
      *(_WORD *)v89 = v2->GlyphIndex;
      if ( v21 )
      {
        v2->LineCursor.GlyphIns.pGlyphs[v2->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x4000u;
        v2->LineCursor.GlyphIns.pGlyphs[v2->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x800u;
        v2->LineCursor.GlyphIns.pNextFormatData[v2->LineCursor.GlyphIns.FormatDataIndex++].pFont = (Scaleform::Render::Text::FontHandle *)v21;
        ++v21->RefCount;
        *(_WORD *)(v89 + 4) = (LOWORD(v2->DeltaText) << 12) | *(_WORD *)(v89 + 4) & 0xFFF;
        v2->LineCursor.LastKerning = 0;
        LODWORD(v90) = COERCE_UNSIGNED_INT((float)((float)(v21->Matrix.M[1][1] + v21->Matrix.M[1][0]) * 0.0) + v21->Matrix.M[1][3]) ^ _xmm[0];
        v91 = v2->LineCursor.MaxFontAscent;
        if ( v90 >= v91 )
          LODWORD(v91) = COERCE_UNSIGNED_INT((float)((float)(v21->Matrix.M[1][1] + v21->Matrix.M[1][0]) * 0.0) + v21->Matrix.M[1][3]) ^ _xmm[0];
        v2->LineCursor.MaxFontAscent = v91;
        v92 = v21->ScreenHeight - v90;
        v93 = v2->LineCursor.MaxFontDescent;
        if ( v92 >= v93 )
          v93 = v92;
        v2->LineCursor.MaxFontDescent = v93;
        v2->LineCursor.NumOfTrailingSpaces = 0;
        v2->LineCursor.LineWidthWithoutTrailingSpaces = v2->AdjLineWidth + v2->NewLineWidth;
        v94 = v2->FindFontInfo.pCurrentFormat;
        if ( v94->PresentMask & 0x100 && Scaleform::String::GetLength((Scaleform::String *)&v94->Url.0) )
          *(_WORD *)(v89 + 6) |= 0x80u;
        else
          *(_WORD *)(v89 + 6) &= 0xFF7Fu;
LABEL_215:
        if ( v2->LineCursor.CharInfoHolder.Character == 9 )
        {
          v106 = v2->TabStopsIndex;
          if ( (unsigned int)v106 >= *v19 )
          {
            v109 = (__m128)LODWORD(v2->FontSize);
            v109.m128_f32[0] = (float)((float)(v109.m128_f32[0] * 2.0) + 8.0) * 0.125;
            v110 = (signed int)v109.m128_f32[0];
            if ( (signed int)v109.m128_f32[0] != 0x80000000 && (float)v110 != v109.m128_f32[0] )
              v109.m128_f32[0] = (float)(v110 - (_mm_movemask_ps(_mm_unpacklo_ps(v109, v109)) & 1));
            v111 = (float)(v109.m128_f32[0] * 8.0) * 20.0;
            v112 = (__m128)COERCE_UNSIGNED_INT((float)v2->NewLineWidth);
            v113 = v112;
            v113.m128_f32[0] = (float)(v112.m128_f32[0] + v111) / v111;
            v114 = (signed int)v113.m128_f32[0];
            if ( (signed int)v113.m128_f32[0] != 0x80000000 && (float)v114 != v113.m128_f32[0] )
              v113.m128_f32[0] = (float)(v114 - (_mm_movemask_ps(_mm_unpacklo_ps(v113, v113)) & 1));
            v2->GlyphAdvance = (float)(v113.m128_f32[0] * v111) - v112.m128_f32[0];
          }
          else
          {
            v107 = 20 * *(_DWORD *)(v125 + 4 * v106);
            v2->TabStopsIndex = v106 + 1;
            v108 = v2->NewLineWidth;
            if ( v107 > v108 )
              v2->GlyphAdvance = (float)(v107 - v108);
          }
        }
        v2->LineCursor.LineLength += (unsigned int)*(unsigned __int16 *)(v89 + 4) >> 12;
        v2->LineCursor.pPrevGrec = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)v89;
        v2->LineCursor.LastCharCode = v2->LineCursor.CharInfoHolder.Character;
        v2->LineCursor.LineWidth = v2->NewLineWidth;
        v2->LineCursor.LastGlyphIndex = v2->GlyphIndex;
        v115 = v2->GlyphAdvance;
        v2->LineCursor.LastAdvance = v115;
        v116 = v2->FindFontInfo.pCurrentFormat;
        if ( (LOBYTE(v116->PresentMask) >> 1) & 1 )
          v2->LineCursor.LastAdvance = (float)((float)(v116->LetterSpacing * 0.050000001) * 20.0) + v115;
        v117 = v2->GlyphWidth;
        v2->LineCursor.LastGlyphWidth = v117;
        if ( !v2->LineCursor.GlyphIns.GlyphIndex )
          v2->LineCursor.FirstGlyphWidth = v117;
        if ( v2->LineCursor.GlyphIns.pGlyphs )
        {
          v118 = v2->LineCursor.GlyphIns.GlyphIndex;
          if ( v118 < v2->LineCursor.GlyphIns.GlyphsCount )
            v2->LineCursor.GlyphIns.GlyphIndex = v118 + 1;
        }
        goto LABEL_233;
      }
      v95 = v2->FindFontInfo.pCurrentFormat->ColorV;
      v96 = v2->FontSize;
      if ( v96 < 256.0 && (v97 = (signed int)(float)(v96 * 16.0), v97 & 0xF) )
      {
        *(_WORD *)(v89 + 6) = 16;
        v98 = v97 & 0xFFF;
      }
      else
      {
        *(_WORD *)(v89 + 6) = 0;
        v98 = (signed int)v96 & 0xFFF;
      }
      *(_WORD *)(v89 + 4) = v98;
      v99 = v2->pFontHandle.pObject;
      if ( v99 != v2->LineCursor.pLastFont.pObject )
      {
        v2->LineCursor.GlyphIns.pGlyphs[v2->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x4000u;
        v2->LineCursor.GlyphIns.pGlyphs[v2->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x2000u;
        v2->LineCursor.GlyphIns.pNextFormatData[v2->LineCursor.GlyphIns.FormatDataIndex++].pFont = v99;
        _InterlockedExchangeAdd(&v99->RefCount, 1u);
        v21 = v141;
      }
      if ( v95 != v2->LineCursor.LastColor )
      {
        v2->LineCursor.GlyphIns.pGlyphs[v2->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x4000u;
        v2->LineCursor.GlyphIns.pGlyphs[v2->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x1000u;
        v2->LineCursor.GlyphIns.pNextFormatData[v2->LineCursor.GlyphIns.FormatDataIndex++].ColorV = v95;
      }
      v100 = v2->LineCursor.CharInfoHolder.Character;
      v101 = 10;
      if ( v2->pDocView->pDocument.pObject->RTFlags & 2 )
        v101 = 13;
      if ( v100 == v101 )
      {
        if ( !v100 )
          goto LABEL_196;
        *(_WORD *)(v89 + 4) &= 0xFFFu;
        *(_WORD *)(v89 + 4) |= 0x1000u;
      }
      else
      {
        if ( v100 )
        {
          if ( !v2->isSpace && !v2->isNbsp )
          {
            v2->LineCursor.NumOfTrailingSpaces = 0;
            goto LABEL_193;
          }
          *(_WORD *)(v89 + 6) |= 2u;
          v102 = (unsigned int)v2->GlyphIndex;
          if ( (signed int)v102 >= 0 )
          {
            v126 = 0i64;
            ((void (__fastcall *)(Scaleform::Render::Font *, __int64, __int128 *))v2->pFont->vfptr[7].__vecDelDtor)(
              v2->pFont,
              v102,
              &v126);
            if ( *(float *)&v126 >= *((float *)&v126 + 2) || *((float *)&v126 + 1) >= *((float *)&v126 + 3) )
              *(_WORD *)(v89 + 6) |= 0x200u;
          }
          else
          {
            *(_WORD *)(v89 + 6) |= 0x200u;
          }
          ++v2->LineCursor.NumOfSpaces;
          if ( v2->isSpace )
          {
            ++v2->LineCursor.NumOfTrailingSpaces;
          }
          else
          {
            v2->LineCursor.NumOfTrailingSpaces = 0;
LABEL_193:
            v2->LineCursor.LineWidthWithoutTrailingSpaces = v2->AdjLineWidth + v2->NewLineWidth;
          }
          *(_WORD *)(v89 + 4) &= 0xFFFu;
          *(_WORD *)(v89 + 4) |= 0x1000u;
LABEL_199:
          Scaleform::Render::Text::GFxLineCursor::TrackFontParams(&v2->LineCursor, v2->pFont, v2->Scale);
LABEL_200:
          if ( v2->FindFontInfo.pCurrentFormat->FormatFlags & 4 )
            *(_WORD *)(v89 + 6) |= 0x400u;
          else
            *(_WORD *)(v89 + 6) &= 0xFBFFu;
          v103 = v2->FindFontInfo.pCurrentFormat;
          if ( v103->PresentMask & 0x100 && Scaleform::String::GetLength((Scaleform::String *)&v103->Url.0) )
            *(_WORD *)(v89 + 6) |= 0x80u;
          else
            *(_WORD *)(v89 + 6) &= 0xFF7Fu;
          v104 = v2->pFontHandle.pObject;
          if ( v104 )
          {
            _InterlockedExchangeAdd(&v104->RefCount, 1u);
            v21 = v141;
          }
          v105 = v2->LineCursor.pLastFont.pObject;
          if ( v105 )
          {
            if ( !_InterlockedDecrement(&v105->RefCount) && v105 )
              v105->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v105->vfptr, 1u);
            v21 = v141;
          }
          v2->LineCursor.pLastFont.pObject = v2->pFontHandle.pObject;
          v2->LineCursor.LastColor = v95;
          v2->LineCursor.LastKerning = ((unsigned __int8)v2->FindFontInfo.pCurrentFormat->FormatFlags >> 3) & 1;
          goto LABEL_215;
        }
LABEL_196:
        *(_WORD *)(v89 + 4) &= 0xFFFu;
      }
      *(_WORD *)(v89 + 6) |= 0x300u;
      v2->GlyphWidth = 0;
      v2->LineCursor.LineHasNewLine = 1;
      if ( !v2->LineCursor.CharInfoHolder.Index )
        goto LABEL_199;
      goto LABEL_200;
    }
LABEL_233:
    v119 = v2->DeltaText;
    if ( v119 )
    {
      v120 = v119;
      Scaleform::Render::Text::Paragraph::CharactersIterator::operator+=(v23, v119);
      v2->LineCursor.NumChars += v120;
    }
  }
  if ( v2->pTempLine )
    Scaleform::Render::Text::ParagraphFormatter::FinalizeLine(v2);
  v121 = (Scaleform::Render::Text::ParagraphFormatter *)v2->pTextBufForCustomFormat;
  if ( v121 && v121 != (Scaleform::Render::Text::ParagraphFormatter *)v2->TextBufForCustomFormat )
  {
    Scaleform::Render::Text::StyledText::GetAllocator((Scaleform::Render::Text::StyledText *)&v2->pDocView->pDocument.pObject->vfptr);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2->pTextBufForCustomFormat);
  }
  if ( v21 )
  {
    v28 = v21->RefCount-- == 1;
    if ( v28 )
      v21->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v21->vfptr, 1u);
  }
}v28 )
      v21->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v21->vfptr, 1u);
  }
}

// File Line: 2217
// RVA: 0x97AEE0
void __fastcall Scaleform::Render::Text::DocView::Format(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView *v1; // rsi
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm3_4
  Scaleform::Render::Text::DocView::DocumentText *v5; // rbx
  _QWORD *v6; // rdi
  signed __int64 v7; // rbx
  float v8; // xmm13_4
  signed int v9; // er11
  Scaleform::Render::Text::LineBuffer *v10; // r10
  unsigned int v11; // edx
  Scaleform::Render::Text::Paragraph *v12; // r9
  unsigned __int64 v13; // rbx
  Scaleform::Render::Text::LineBuffer::Line **v14; // rdi
  Scaleform::Render::Text::LineBuffer::Line *v15; // rax
  unsigned int v16; // er8
  unsigned __int16 v17; // cx
  Scaleform::Render::Text::ParagraphFormat *v18; // r8
  Scaleform::Render::Text::EditorKitBase *v19; // rcx
  Scaleform::Render::Text::LineBuffer::Line *v20; // rbx
  unsigned int v21; // ecx
  int v22; // edi
  bool v23; // cl
  __int64 v24; // rax
  int v25; // eax
  Scaleform::Render::Text::EditorKitBase *v26; // rcx
  unsigned int v27; // ecx
  unsigned int v28; // ecx
  int v29; // eax
  signed int v30; // edx
  float v31; // xmm0_4
  float v32; // xmm0_4
  signed int v33; // eax
  int v34; // ecx
  float v35; // xmm0_4
  float v36; // xmm0_4
  unsigned int v37; // ecx
  int v38; // eax
  __int64 v39; // rax
  signed int v40; // ecx
  unsigned int v41; // er9
  unsigned int v42; // er11
  unsigned int j; // er8
  Scaleform::Render::Text::LineBuffer::Line *v44; // rcx
  unsigned int v45; // eax
  unsigned int v46; // er11
  unsigned int v47; // ecx
  unsigned __int16 v48; // cx
  unsigned int v49; // er9
  unsigned int i; // er8
  Scaleform::Render::Text::LineBuffer::Line *v51; // rcx
  unsigned int v52; // eax
  int v53; // eax
  unsigned __int64 v54; // rax
  unsigned __int64 v55; // rcx
  wchar_t *v56; // rcx
  Scaleform::Render::Text::EditorKitBase *v57; // rcx
  unsigned __int64 v58; // r8
  signed int v59; // er9
  char v60; // si
  Scaleform::Render::Text::DocView *v61; // rbx
  unsigned int v62; // edi
  char v63; // dl
  float v64; // xmm8_4
  float v65; // xmm9_4
  float v66; // xmm10_4
  float v67; // xmm11_4
  float v68; // xmm6_4
  float v69; // xmm2_4
  float v70; // xmm4_4
  float v71; // xmm3_4
  float v72; // xmm5_4
  float v73; // xmm1_4
  unsigned int v74; // eax
  float v75; // xmm5_4
  float v76; // xmm3_4
  float v77; // xmm7_4
  float v78; // xmm4_4
  float v79; // xmm0_4
  float v80; // xmm1_4
  float v81; // xmm3_4
  float v82; // xmm4_4
  float v83; // xmm2_4
  Scaleform::Render::Text::LineBuffer *v84; // rdx
  __int64 v85; // rdx
  signed int v86; // er8
  unsigned __int64 v87; // r10
  Scaleform::Render::Text::LineBuffer::Line *v88; // rcx
  signed int v89; // eax
  unsigned int v90; // ebx
  unsigned int v91; // eax
  Scaleform::Render::Text::DocView *v92; // rdx
  Scaleform::Render::Text::LineBuffer *v93; // r11
  Scaleform::Render::Text::DocView::DocumentListener *v94; // rcx
  signed int v95; // eax
  bool v96; // zf
  Scaleform::Render::Text::DocView *v97; // rsi
  float v98; // xmm10_4
  float v99; // xmm11_4
  float v100; // xmm8_4
  float v101; // xmm9_4
  float v102; // xmm4_4
  float v103; // xmm3_4
  float v104; // xmm0_4
  float v105; // xmm2_4
  float v106; // xmm1_4
  float v107; // xmm7_4
  int v108; // edi
  int v109; // edi
  float v110; // xmm6_4
  unsigned int v111; // er8
  int v112; // er9
  Scaleform::Render::Text::LineBuffer::Line *v113; // rcx
  signed int v114; // edx
  int v115; // eax
  unsigned int v116; // ebx
  unsigned int v117; // er10
  Scaleform::Render::Text::LineBuffer::Line *v118; // r8
  signed int v119; // ecx
  float v120; // xmm0_4
  float v121; // xmm0_4
  signed int v122; // eax
  int v123; // er9
  float v124; // xmm0_4
  float v125; // xmm0_4
  unsigned int v126; // ecx
  int v127; // eax
  signed int v128; // edi
  Scaleform::Render::Text::EditorKitBase *v129; // rcx
  char v130; // al
  signed int v131; // ecx
  signed int v132; // eax
  float v133; // xmm1_4
  float v134; // xmm1_4
  unsigned int v135; // eax
  Scaleform::Render::Text::EditorKitBase *v136; // rcx
  signed int v137; // eax
  float v138; // xmm1_4
  float v139; // xmm1_4
  Scaleform::Render::Text::DocView::DocumentListener *v140; // rcx
  char v141; // al
  Scaleform::Render::Text::DocView::DocumentListener *v142; // rcx
  Scaleform::Render::Text::DocView::DocumentListener *v143; // rcx
  Scaleform::Render::Text::EditorKitBase *v144; // rcx
  Scaleform::Render::Text::EditorKitBase *v145; // rcx
  Scaleform::Render::Text::CompositionStringBase *v146; // rax
  Scaleform::Render::Text::LineBuffer::Line *v147; // rcx
  unsigned int v148; // eax
  Scaleform::Render::Text::FontHandle *v149; // rax
  signed __int64 v150; // [rsp+20h] [rbp-C0h]
  signed __int64 v151; // [rsp+28h] [rbp-B8h]
  Scaleform::Render::Text::Paragraph *v152; // [rsp+30h] [rbp-B0h]
  int v153; // [rsp+38h] [rbp-A8h]
  Scaleform::Render::Text::LineBuffer *v154; // [rsp+40h] [rbp-A0h]
  Scaleform::Render::Text::LineBuffer *v155; // [rsp+48h] [rbp-98h]
  __int64 v156; // [rsp+50h] [rbp-90h]
  unsigned int lineIdx[2]; // [rsp+58h] [rbp-88h]
  Scaleform::Render::Text::ParagraphFormatter v158; // [rsp+60h] [rbp-80h]
  Scaleform::Render::Text::DocView *pdoc; // [rsp+C50h] [rbp+B70h]
  int v160; // [rsp+C58h] [rbp+B78h]
  int vars0; // [rsp+C60h] [rbp+B80h]
  int retaddr; // [rsp+C68h] [rbp+B88h]

  v158.pTempLine = (Scaleform::Render::Text::LineBuffer::Line *)-2i64;
  v1 = this;
  v2 = this->ViewRect.x2 - 40.0;
  v3 = this->ViewRect.y1 + 40.0;
  v4 = this->ViewRect.y2 - 40.0;
  this->mLineBuffer.Geom.VisibleRect.x1 = this->ViewRect.x1 + 40.0;
  this->mLineBuffer.Geom.VisibleRect.y1 = v3;
  this->mLineBuffer.Geom.VisibleRect.x2 = v2;
  this->mLineBuffer.Geom.VisibleRect.y2 = v4;
  v5 = this->pDocument.pObject;
  if ( !v5 )
    return;
  HIDWORD(v158.pParagraph) = Scaleform::Render::Text::DocView::GetMaxHScrollValue(this);
  LODWORD(v158.pParagraph) = v1->MaxVScroll.Value;
  if ( v1->AlignProps & 0x30 )
    v1->RTFlags |= 2u;
  v6 = &v5->Paragraphs.Data.Data;
  v151 = (signed __int64)&v5->Paragraphs;
  v7 = 0i64;
  v150 = 0i64;
  v154 = &v1->mLineBuffer;
  v155 = &v1->mLineBuffer;
  v156 = 0i64;
  *(_QWORD *)lineIdx = 0i64;
  v8 = 0.0;
  LOBYTE(v158.pDocView) = ((unsigned __int8)v1->mLineBuffer.Geom.Flags >> 2) & 1;
  Scaleform::Render::Text::ParagraphFormatter::ParagraphFormatter(&v158, v1, v1->pLog.pObject);
  v9 = 0;
  vars0 = 0;
  retaddr = 0;
LABEL_5:
  v10 = v155;
  v11 = lineIdx[0];
  while ( v6 && v7 >= 0 && v7 < *((signed int *)v6 + 2) )
  {
    v12 = *(Scaleform::Render::Text::Paragraph **)(*v6 + 8 * v7);
    v152 = *(Scaleform::Render::Text::Paragraph **)(*v6 + 8 * v7);
    if ( v10 )
    {
      v13 = v10->Lines.Data.Size;
      if ( v11 >= v13 || (v11 & 0x80000000) != 0 )
        goto LABEL_119;
      v14 = v10->Lines.Data.Data;
      v15 = v10->Lines.Data.Data[v11];
      if ( !(v1->RTFlags & 2) )
      {
        v16 = (v15->MemSize & 0x80000000) == 0 ? v15->Data32.ParagraphId : v15->Data32.GlyphsCount;
        if ( v12->UniqueId == v16 )
        {
          v17 = (v15->MemSize & 0x80000000) == 0 ? v15->Data32.ParagraphModId : v15->Data8.ParagraphModId;
          if ( v12->ModCounter == v17 )
          {
            v18 = (Scaleform::Render::Text::ParagraphFormat *)v12->StartIndex;
            v19 = v1->pEditorKit.pObject;
            if ( v19 )
            {
              v18 = (Scaleform::Render::Text::ParagraphFormat *)v19->vfptr[4].__vecDelDtor(
                                                                  (Scaleform::RefCountImplCore *)&v19->vfptr,
                                                                  v12->StartIndex);
              v11 = lineIdx[0];
              v10 = v155;
              v12 = v152;
              v9 = vars0;
            }
            while ( 2 )
            {
              if ( !v10
                || v11 >= v10->Lines.Data.Size
                || (v11 & 0x80000000) != 0
                || ((v20 = v10->Lines.Data.Data[v11], (v20->MemSize & 0x80000000) == 0) ? (v21 = v20->Data32.ParagraphId) : (v21 = v20->Data32.GlyphsCount),
                    v12->UniqueId != v21) )
              {
                v7 = v150;
                v6 = (_QWORD *)v151;
                goto LABEL_82;
              }
              if ( (v20->MemSize & 0x80000000) == 0 )
              {
                v20->Data32.TextPos = (unsigned int)v18;
              }
              else
              {
                v20->Data32.TextPos &= 0xFF000000;
                v20->Data32.TextPos |= (unsigned int)v18 & 0xFFFFFF;
              }
              v22 = v20->Data32.OffsetX;
              v23 = (v20->MemSize & 0x80000000) != 0;
              v153 = v20->Data32.OffsetY;
              if ( (v20->MemSize & 0x80000000) == 0 )
                v24 = v20->Data32.TextLength;
              else
                v24 = HIBYTE(v20->Data8.TextPosAndLength);
              v158.pParaFormat = (Scaleform::Render::Text::ParagraphFormat *)((char *)v18 + v24);
              v20->Data32.OffsetY = v158.NextOffsetY;
              if ( v23 )
                v25 = v20->Data8.Width;
              else
                v25 = v20->Data32.Width;
              if ( v25 < v9 )
                v25 = v9;
              vars0 = v25;
              if ( Scaleform::Render::Text::Paragraph::GetLength(v12)
                || (v26 = v1->pEditorKit.pObject) != 0i64 && !((unsigned __int8 (*)(void))v26->vfptr[2].__vecDelDtor)() )
              {
                if ( (v20->MemSize & 0x80000000) == 0 )
                  v27 = v20->Data32.Height;
                else
                  v27 = v20->Data8.Height;
                retaddr = v27 + v158.NextOffsetY;
              }
              if ( (v20->MemSize & 0x80000000) == 0 )
                v28 = v20->Data32.Height;
              else
                v28 = v20->Data8.Height;
              if ( (v20->MemSize & 0x80000000) == 0 )
                v29 = v20->Data32.Leading;
              else
                v29 = v20->Data8.Leading;
              v158.NextOffsetY += v28 + v29;
              if ( v1->Flags & 1 )
              {
                v30 = v20->MemSize;
                if ( ((v20->MemSize >> 27) & 3) == 1 )
                {
                  v35 = v1->mLineBuffer.Geom.VisibleRect.x2 - v1->mLineBuffer.Geom.VisibleRect.x1;
                  if ( v35 <= 0.0 )
                    v36 = v35 - 0.5;
                  else
                    v36 = v35 + 0.5;
                  if ( v30 >= 0 )
                    v37 = v20->Data32.Width;
                  else
                    v37 = v20->Data8.Width;
                  v38 = (signed int)v36 - v37;
                  if ( v38 < 0 )
                    v38 = 0;
                  v20->Data32.OffsetX = v38;
LABEL_75:
                  v158.NeedRecenterLines = 1;
                }
                else if ( ((v20->MemSize >> 27) & 3) == 2 )
                {
                  v31 = (float)(v1->mLineBuffer.Geom.VisibleRect.x2 - v1->mLineBuffer.Geom.VisibleRect.x1) * 0.5;
                  if ( v31 <= 0.0 )
                    v32 = v31 - 0.5;
                  else
                    v32 = v31 + 0.5;
                  if ( v30 >= 0 )
                    v33 = v20->Data32.Width;
                  else
                    v33 = v20->Data8.Width;
                  v34 = (signed int)v32 - v33 / 2;
                  if ( v34 < 0 )
                    v34 = 0;
                  v20->Data32.OffsetX = v34;
                  goto LABEL_75;
                }
              }
              v39 = v20->MemSize >> 31;
              if ( v22 != v20->Data32.OffsetX || v153 != v20->Data32.OffsetY )
                v1->mLineBuffer.Geom.Flags |= 1u;
              v11 = lineIdx[0];
              v10 = v155;
              v18 = v158.pParaFormat;
              v12 = v152;
              v9 = vars0;
              if ( lineIdx[0] < v155->Lines.Data.Size )
                v11 = lineIdx[0]++ + 1;
              continue;
            }
          }
        }
      }
      v40 = v15->Data32.TextPos;
      if ( (v15->MemSize & 0x80000000) != 0 )
      {
        v40 &= 0xFFFFFFu;
        if ( v40 == 0xFFFFFF )
          v40 = -1;
      }
      if ( v40 != -1 )
      {
        v46 = v12->UniqueId;
        if ( (v15->MemSize & 0x80000000) == 0 )
          v47 = v15->Data32.ParagraphId;
        else
          v47 = v15->Data32.GlyphsCount;
        if ( v46 == v47 )
        {
          v48 = (v15->MemSize & 0x80000000) == 0 ? v15->Data32.ParagraphModId : v15->Data8.ParagraphModId;
          if ( v12->ModCounter != v48 )
          {
            v49 = 0;
            for ( i = v11; i < v13 && (i & 0x80000000) == 0; ++i )
            {
              v51 = v14[i];
              v52 = (v51->MemSize & 0x80000000) == 0 ? v51->Data32.ParagraphId : v51->Data32.GlyphsCount;
              if ( v52 != v46 )
                break;
              ++v49;
            }
            Scaleform::Render::Text::LineBuffer::RemoveLines(v10, v11, v49);
            v1->mLineBuffer.Geom.Flags |= 1u;
            v12 = v152;
          }
        }
        v6 = (_QWORD *)v151;
LABEL_119:
        v7 = v150;
        goto LABEL_120;
      }
      v41 = 0;
      if ( (v15->MemSize & 0x80000000) == 0 )
        v42 = v15->Data32.ParagraphId;
      else
        v42 = v15->Data32.GlyphsCount;
      for ( j = v11; j < v13 && (j & 0x80000000) == 0; ++j )
      {
        v44 = v14[j];
        v45 = (v44->MemSize & 0x80000000) == 0 ? v44->Data32.ParagraphId : v44->Data32.GlyphsCount;
        if ( v45 != v42 )
          break;
        ++v41;
      }
      v7 = v150;
      v6 = (_QWORD *)v151;
      v9 = vars0;
      if ( v41 )
      {
        Scaleform::Render::Text::LineBuffer::RemoveLines(v10, v11, v41);
        v1->mLineBuffer.Geom.Flags |= 1u;
        v9 = vars0;
        goto LABEL_5;
      }
    }
    else
    {
LABEL_120:
      v158.pLinesIter = (Scaleform::Render::Text::LineBuffer::Iterator *)&v155;
      v158.ParaYOffset = v158.NextOffsetY;
      Scaleform::Render::Text::ParagraphFormatter::Format(&v158, v12);
      v1->mLineBuffer.Geom.Flags |= 1u;
      v53 = v158.ParaWidth;
      if ( v158.ParaWidth < vars0 )
        v53 = vars0;
      vars0 = v53;
      v54 = v152->Text.Size;
      if ( v54 )
      {
        v55 = v54 - 1;
        if ( v152->Text.pText && v55 < v54 )
          v56 = &v152->Text.pText[v55];
        else
          v56 = 0i64;
        if ( !*v56 )
          --v54;
        if ( v54 )
          goto LABEL_335;
      }
      v57 = v1->pEditorKit.pObject;
      if ( v57 )
      {
        if ( !((unsigned __int8 (*)(void))v57->vfptr[2].__vecDelDtor)() )
LABEL_335:
          retaddr = v158.ParaYOffset + v158.ParaHeight;
      }
      v11 = lineIdx[0];
      v10 = v155;
      v9 = vars0;
LABEL_82:
      if ( v7 < v6[1] )
        v150 = ++v7;
    }
  }
  if ( v10 )
  {
    v58 = v10->Lines.Data.Size;
    if ( v11 < v58 && (v11 & 0x80000000) == 0 )
    {
      if ( v11 < v58 )
      {
        Scaleform::Render::Text::LineBuffer::RemoveLines(v10, v11, v1->mLineBuffer.Lines.Data.Size - v11);
        v9 = vars0;
      }
      v1->mLineBuffer.Geom.Flags |= 1u;
    }
  }
  v1->TextWidth = v9;
  v59 = retaddr;
  v1->TextHeight = retaddr;
  ++v1->FormatCounter;
  v1->RTFlags &= 0xFCu;
  v60 = 0;
  v61 = pdoc;
  v62 = ((unsigned int)(unsigned __int8)pdoc->AlignProps >> 2) & 3;
  v63 = pdoc->Flags;
  if ( v63 & 1 || v63 & 2 || v158.ForceVerticalCenterAutoSize )
  {
    v64 = pdoc->ViewRect.y2;
    v65 = pdoc->ViewRect.x2;
    v66 = pdoc->ViewRect.y1;
    v67 = pdoc->ViewRect.x1;
    v68 = pdoc->ViewRect.x1;
    v69 = pdoc->ViewRect.y1;
    v70 = pdoc->ViewRect.x2;
    v71 = pdoc->ViewRect.y2;
    if ( v63 & 1 )
    {
      v72 = (float)v9 + 80.0;
      if ( (pdoc->AlignProps & 3) == 1 )
      {
        v68 = v65 - v72;
      }
      else if ( (pdoc->AlignProps & 3) == 2 )
      {
        v68 = v68 + (float)((float)((float)(v65 - v68) * 0.5) - (float)(v72 * 0.5));
      }
      v70 = v68 + v72;
    }
    if ( v63 & 2 || v158.ForceVerticalCenterAutoSize )
    {
      v73 = (float)retaddr + 80.0;
      switch ( v62 )
      {
        case 0u:
          if ( !v158.ForceVerticalCenterAutoSize )
            break;
LABEL_155:
          v69 = (float)((float)((float)(v64 - v66) * 0.5) - (float)(v73 * 0.5)) + v66;
          break;
        case 3u:
          goto LABEL_155;
        case 2u:
          v69 = v64 - v73;
          break;
      }
      v71 = v69 + v73;
      v60 = 1;
    }
    if ( v68 != v67
      || (v70 != v65 || v69 != v66 || v71 != v64) && (v68 != v67 || v70 != v65 || v69 != v66 || v71 != v64) )
    {
      pdoc->ViewRect.x1 = v68;
      v61->ViewRect.y1 = v69;
      v61->ViewRect.x2 = v70;
      v61->ViewRect.y2 = v71;
      v61->mLineBuffer.Geom.VisibleRect.x1 = v61->ViewRect.x1 + 40.0;
      v61->mLineBuffer.Geom.VisibleRect.y1 = v69 + 40.0;
      v61->mLineBuffer.Geom.VisibleRect.x2 = v70 - 40.0;
      v61->mLineBuffer.Geom.VisibleRect.y2 = v71 - 40.0;
    }
  }
  v74 = ((unsigned int)(unsigned __int8)v61->AlignProps >> 4) & 3;
  if ( v74 )
  {
    v75 = v61->ViewRect.x1 + 40.0;
    v76 = v61->ViewRect.x2 - 40.0;
    v77 = v61->ViewRect.y1 + 40.0;
    v78 = v61->ViewRect.y2 - 40.0;
    if ( !(v61->Flags & 4) && !v62 )
      v62 = 3;
    v79 = *(float *)&FLOAT_1_0;
    v80 = *(float *)&FLOAT_1_0;
    if ( v74 == 1 )
    {
      v81 = v76 - v75;
      if ( (float)v9 > v81 )
        v79 = v81 / (float)v9;
      v82 = v78 - v77;
      if ( (float)retaddr > v82 )
        v80 = v82 / (float)retaddr;
      if ( v80 >= v79 )
        v80 = v79;
      goto LABEL_187;
    }
    if ( v74 == 2 )
    {
      v80 = FLOAT_3_4028235e38;
      v83 = FLOAT_3_4028235e38;
      if ( v9 >= 20 )
        v83 = (float)(v76 - v75) / (float)v9;
      if ( retaddr >= 20 )
        v80 = (float)(v78 - v77) / (float)retaddr;
      if ( v80 >= v83 )
        v80 = v83;
      if ( v80 != 3.4028235e38 )
      {
LABEL_187:
        if ( v80 != 1.0 )
        {
          v84 = &v61->mLineBuffer;
          if ( LODWORD(v61->mLineBuffer.Lines.Data.Size) )
          {
            v85 = 0i64;
            v86 = 0x7FFFFFFF;
            while ( v154 )
            {
              v87 = v154->Lines.Data.Size;
              if ( (unsigned int)v85 >= v87 || (signed int)v85 < 0 )
                break;
              v88 = v154->Lines.Data.Data[v85];
              if ( (v88->MemSize & 0x80000000) == 0 )
                v89 = v88->Data32.Height;
              else
                v89 = v88->Data8.Height;
              if ( v89 < v86 )
                v86 = v89;
              if ( (unsigned int)v85 < v87 )
                v85 = (unsigned int)(v85 + 1);
            }
            v61 = pdoc;
            v59 = retaddr;
            v84 = &pdoc->mLineBuffer;
            if ( v86 > 0 && (float)((float)v86 * v80) < 120.0 )
              v80 = 120.0 / (float)v86;
          }
          v61->TextWidth = (signed int)(float)((float)v9 * v80);
          v61->TextHeight = (signed int)(float)((float)v59 * v80);
          Scaleform::Render::Text::LineBuffer::Scale(v84, v80);
        }
      }
    }
  }
  LOBYTE(v160) = 0;
  v90 = Scaleform::Render::Text::DocView::GetMaxVScroll(v61);
  if ( pdoc->mLineBuffer.Geom.FirstVisibleLinePos <= v90 )
  {
    v95 = (unsigned __int8)v160;
    if ( v90 != LODWORD(v158.pParagraph) )
      v95 = 1;
    v160 = v95;
    goto LABEL_213;
  }
  v91 = Scaleform::Render::Text::DocView::GetMaxVScroll(pdoc);
  if ( v90 > v91 )
    v90 = v91;
  v92 = pdoc;
  if ( pdoc->mLineBuffer.Geom.FirstVisibleLinePos == v90 )
  {
LABEL_213:
    v93 = v154;
    goto LABEL_214;
  }
  v93 = &pdoc->mLineBuffer;
  v93->Geom.FirstVisibleLinePos = v90;
  v93->Geom.Flags |= 1u;
  v94 = v92->pDocumentListener.pObject;
  if ( v94 )
  {
    ((void (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::Render::Text::DocView *, _QWORD))v94->vfptr[4].__vecDelDtor)(
      v94,
      v92,
      v90);
    goto LABEL_213;
  }
LABEL_214:
  v96 = v60 == 0;
  v97 = pdoc;
  if ( v96 && v62 && !(pdoc->Flags & 2) )
  {
    v98 = pdoc->ViewRect.x1 + 40.0;
    v99 = pdoc->ViewRect.x2 - 40.0;
    v100 = pdoc->ViewRect.y1 + 40.0;
    v101 = pdoc->ViewRect.y2 - 40.0;
    v102 = pdoc->mLineBuffer.Geom.VisibleRect.y2;
    v103 = pdoc->mLineBuffer.Geom.VisibleRect.x2;
    v104 = pdoc->mLineBuffer.Geom.VisibleRect.y1;
    v105 = pdoc->mLineBuffer.Geom.VisibleRect.x1;
    v106 = (float)(signed int)pdoc->TextHeight;
    v107 = v101 - v100;
    if ( v106 >= (float)(v101 - v100) )
    {
      if ( v62 - 2 <= 1 )
      {
        v110 = 0.0;
        v111 = Scaleform::Render::Text::DocView::GetBottomVScroll(pdoc);
        v112 = 0;
        v93 = &v97->mLineBuffer;
        while ( v97 != (Scaleform::Render::Text::DocView *)-80i64
             && v111 < v97->mLineBuffer.Lines.Data.Size
             && (v111 & 0x80000000) == 0 )
        {
          v113 = v93->Lines.Data.Data[v111];
          if ( (v113->MemSize & 0x80000000) == 0 )
            v114 = v113->Data32.Height;
          else
            v114 = v113->Data8.Height;
          if ( v112 )
          {
            if ( (v113->MemSize & 0x80000000) == 0 )
              v115 = v113->Data32.Leading;
            else
              v115 = v113->Data8.Leading;
            v114 += v115;
          }
          if ( (float)((float)v114 + v110) > v107 )
            break;
          v110 = (float)v114 + v110;
          --v111;
          ++v112;
        }
        if ( v62 == 2 )
          v100 = v101 - v110;
        else
          v100 = (float)((float)(v107 * 0.5) - (float)(v110 * 0.5)) + v100;
      }
      v97->mLineBuffer.Geom.VisibleRect.x1 = v98;
      v97->mLineBuffer.Geom.VisibleRect.y1 = v100;
      v97->mLineBuffer.Geom.VisibleRect.x2 = v99;
      v97->mLineBuffer.Geom.VisibleRect.y2 = v101;
    }
    else
    {
      v108 = v62 - 1;
      if ( v108 )
      {
        v109 = v108 - 1;
        if ( v109 )
        {
          if ( v109 == 1 )
            v104 = (float)((float)(v107 * 0.5) - (float)(v106 * 0.5)) + v100;
        }
        else
        {
          v104 = v101 - v106;
        }
      }
      else
      {
        v105 = pdoc->ViewRect.x1 + 40.0;
        v104 = pdoc->ViewRect.y1 + 40.0;
        v103 = pdoc->ViewRect.x2 - 40.0;
        v102 = pdoc->ViewRect.y2 - 40.0;
      }
      pdoc->mLineBuffer.Geom.VisibleRect.x1 = v105;
      v97->mLineBuffer.Geom.VisibleRect.y1 = v104;
      v97->mLineBuffer.Geom.VisibleRect.x2 = v103;
      v97->mLineBuffer.Geom.VisibleRect.y2 = v102;
    }
  }
  v116 = 0;
  if ( v158.NeedRecenterLines )
  {
    v117 = 0;
    while ( v93 && v117 < v97->mLineBuffer.Lines.Data.Size && (v117 & 0x80000000) == 0 )
    {
      v118 = v97->mLineBuffer.Lines.Data.Data[v117];
      v119 = v118->MemSize;
      if ( ((v118->MemSize >> 27) & 3) == 1 )
      {
        v124 = v97->mLineBuffer.Geom.VisibleRect.x2 - v97->mLineBuffer.Geom.VisibleRect.x1;
        if ( v124 <= 0.0 )
          v125 = v124 - 0.5;
        else
          v125 = v124 + 0.5;
        if ( v119 >= 0 )
          v126 = v118->Data32.Width;
        else
          v126 = v118->Data8.Width;
        v127 = (signed int)v125 - v126;
        if ( v127 < 0 )
          v127 = 0;
        v118->Data32.OffsetX = v127;
      }
      else if ( ((v118->MemSize >> 27) & 3) == 2 )
      {
        v120 = (float)(v97->mLineBuffer.Geom.VisibleRect.x2 - v97->mLineBuffer.Geom.VisibleRect.x1) * 0.5;
        if ( v120 <= 0.0 )
          v121 = v120 - 0.5;
        else
          v121 = v120 + 0.5;
        if ( v119 >= 0 )
          v122 = v118->Data32.Width;
        else
          v122 = v118->Data8.Width;
        v123 = (signed int)v121 - v122 / 2;
        if ( v123 < 0 )
          v123 = 0;
        v118->Data32.OffsetX = v123;
      }
      v93 = &v97->mLineBuffer;
      if ( v117 < v97->mLineBuffer.Lines.Data.Size )
      {
        ++v117;
        v93 = &v97->mLineBuffer;
      }
    }
  }
  if ( v97->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(v97);
    v97->RTFlags &= 0xFCu;
  }
  v128 = 1200;
  if ( !(v97->Flags & 8) )
  {
    v129 = v97->pEditorKit.pObject;
    if ( !v129 || (v130 = ((__int64 (*)(void))v129->vfptr[2].__vecDelDtor)(), v131 = 1200, v130) )
      v131 = 0;
    v132 = v97->TextWidth;
    if ( v132 )
      v133 = (float)v132;
    else
      v133 = 0.0;
    v134 = (float)(v133 - (float)(v97->mLineBuffer.Geom.VisibleRect.x2 - v97->mLineBuffer.Geom.VisibleRect.x1))
         + (float)v131;
    if ( v134 < 0.0 )
      v134 = 0.0;
    v116 = (signed int)v134;
  }
  if ( v97->mLineBuffer.Geom.HScrollOffset <= v116 )
  {
    v141 = v160;
    if ( v116 != HIDWORD(v158.pParagraph) )
      v141 = 1;
  }
  else
  {
    if ( v97->RTFlags & 3 )
    {
      Scaleform::Render::Text::DocView::Format(v97);
      v97->RTFlags &= 0xFCu;
    }
    if ( v97->Flags & 8 )
    {
      v135 = 0;
    }
    else
    {
      v136 = v97->pEditorKit.pObject;
      if ( !v136 || ((unsigned __int8 (*)(void))v136->vfptr[2].__vecDelDtor)() )
        v128 = 0;
      v137 = v97->TextWidth;
      if ( v137 )
        v138 = (float)v137;
      else
        v138 = 0.0;
      v139 = (float)(v138 - (float)(v97->mLineBuffer.Geom.VisibleRect.x2 - v97->mLineBuffer.Geom.VisibleRect.x1))
           + (float)v128;
      if ( v139 >= 0.0 )
        v8 = v139;
      v135 = (signed int)v8;
    }
    if ( v116 > v135 )
      v116 = v135;
    if ( v97->mLineBuffer.Geom.HScrollOffset != v116 )
    {
      v97->mLineBuffer.Geom.HScrollOffset = v116;
      v140 = v97->pDocumentListener.pObject;
      if ( v140 )
        ((void (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::Render::Text::DocView *, _QWORD))v140->vfptr[3].__vecDelDtor)(
          v140,
          v97,
          v116);
    }
    v141 = v160;
  }
  v142 = v97->pDocumentListener.pObject;
  if ( v142 )
  {
    if ( v141 && v142->HandlersMask & 4 )
      v142->vfptr[5].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v142->vfptr, (unsigned int)v97);
    v143 = v97->pDocumentListener.pObject;
    if ( v143->HandlersMask & 8 )
      v143->vfptr[6].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v143->vfptr, (unsigned int)v97);
  }
  v144 = v97->pEditorKit.pObject;
  if ( v144 && !((unsigned __int8 (*)(void))v144->vfptr[2].__vecDelDtor)()
    || (float)(signed int)v97->TextWidth > (float)(v97->ViewRect.x2 - v97->ViewRect.x1)
    || (float)(signed int)v97->TextHeight > (float)(v97->ViewRect.y2 - v97->ViewRect.y1)
    || v97->mLineBuffer.Geom.HScrollOffset )
  {
    v97->mLineBuffer.Geom.Flags &= 0xDFu;
  }
  else
  {
    v97->mLineBuffer.Geom.Flags |= 0x20u;
  }
  if ( v97->pHighlight )
  {
    v145 = v97->pEditorKit.pObject;
    if ( v145 )
      v146 = (Scaleform::Render::Text::CompositionStringBase *)((__int64 (*)(void))v145->vfptr[7].__vecDelDtor)();
    else
      v146 = 0i64;
    Scaleform::Render::Text::Highlighter::UpdateGlyphIndices(&v97->pHighlight->HighlightManager, v146);
  }
  v97->RTFlags &= 0xDFu;
  if ( v97->mLineBuffer.Lines.Data.Size )
  {
    v147 = *v97->mLineBuffer.Lines.Data.Data;
    v148 = (v147->MemSize & 0x80000000) == 0 ? v147->Data32.GlyphsCount : (unsigned __int8)v147->Data8.GlyphsCount;
    if ( v148 )
    {
      v149 = Scaleform::Render::Text::LineBuffer::FindFirstFontInfo(&v97->mLineBuffer);
      if ( v149 )
      {
        if ( (v149->pFont.pObject->Flags >> 15) & 1 )
          v97->RTFlags |= 0x20u;
      }
    }
  }
  Scaleform::Render::Text::ParagraphFormatter::~ParagraphFormatter(&v158);
}7->RTFlags |= 0x20u;
      }
    }
  }
  Scaleform::Render::Text::ParagraphFormatter::~ParagraphFormatter(&v158);
}

// File Line: 2630
// RVA: 0x969900
void __fastcall Scaleform::Render::Text::DocView::CreateVisibleTextLayout(Scaleform::Render::Text::DocView *this, Scaleform::Render::TextLayout::Builder *bld)
{
  Scaleform::Render::TextLayout::Builder *v2; // r14
  Scaleform::Render::Text::DocView *v3; // rbx
  Scaleform::Render::Text::DocView::HighlightDescLoc *v4; // rax
  Scaleform::Render::Text::EditorKitBase *v5; // rcx
  Scaleform::Render::Text::CompositionStringBase *v6; // rax
  char v7; // dl
  __int16 v8; // cx
  __int16 v9; // ax
  char v10; // dl
  signed __int16 v11; // ax
  __int16 v12; // cx
  char v13; // al
  __int16 v14; // cx
  __int16 v15; // cx
  Scaleform::Render::Text::Highlighter *v16; // r8
  int v17; // ecx
  int v18; // eax
  char *v19; // rdi
  signed int v20; // esi
  Scaleform::Render::Text::EditorKitBase *v21; // rcx
  float v22; // eax
  float v23; // xmm2_4
  float v24; // xmm0_4
  char val[4]; // [rsp+20h] [rbp-50h]
  int v26; // [rsp+24h] [rbp-4Ch]
  int v27; // [rsp+28h] [rbp-48h]
  Scaleform::Render::TextFieldParam params; // [rsp+30h] [rbp-40h]

  v2 = bld;
  v3 = this;
  if ( !(this->RTFlags & 0x40) )
  {
    v4 = this->pHighlight;
    if ( v4 )
    {
      if ( !v4->HighlightManager.Valid )
      {
        v5 = this->pEditorKit.pObject;
        if ( v5 )
          v6 = (Scaleform::Render::Text::CompositionStringBase *)((__int64 (*)(void))v5->vfptr[7].__vecDelDtor)();
        else
          v6 = 0i64;
        Scaleform::Render::Text::Highlighter::UpdateGlyphIndices(&v3->pHighlight->HighlightManager, v6);
        v3->pHighlight->HighlightManager.Valid = 1;
      }
    }
  }
  params.TextParam.pFont = 0i64;
  *(_QWORD *)&params.TextParam.GlyphIndex = 0i64;
  *(_DWORD *)&params.TextParam.BlurY = 0x100000;
  params.ShadowParam.pFont = 0i64;
  *(_QWORD *)&params.ShadowParam.GlyphIndex = 0i64;
  *(_DWORD *)&params.ShadowParam.BlurY = 0x100000;
  *(_QWORD *)&params.ShadowColor = 0i64;
  params.ShadowOffsetY = 0.0;
  Scaleform::Render::Text::LoadTextFieldParamFromTextFilter(&params, &v3->Filter);
  v7 = v3->Flags;
  v8 = params.TextParam.Flags;
  v9 = params.ShadowParam.Flags;
  if ( v7 & 0x40 )
  {
    v8 = params.TextParam.Flags | 1;
    v9 = params.ShadowParam.Flags | 1;
    params.ShadowParam.Flags |= 1u;
  }
  if ( v7 < 0 )
  {
    v8 |= 2u;
    params.ShadowParam.Flags = v9 | 2;
  }
  v10 = v3->RTFlags;
  if ( v10 & 0x20 )
  {
    v8 = (v8 | 0x101) & 0xFFFD;
    v11 = -5;
  }
  else
  {
    v11 = -257;
  }
  v12 = v11 & v8;
  v13 = v3->FlagsEx;
  if ( v13 & 1 )
    v14 = v12 | 8;
  else
    v14 = v12 & 0xFFF7;
  if ( v13 & 2 )
    v15 = v14 | 0x10;
  else
    v15 = v14 & 0xFFEF;
  v16 = &v3->pHighlight->HighlightManager;
  params.TextParam.Flags = v15 & 0xFFF | ((unsigned __int16)(signed int)v3->Outline << 12);
  if ( !v16 || v10 & 0x40 )
    v16 = 0i64;
  Scaleform::Render::Text::LineBuffer::CreateVisibleTextLayout(&v3->mLineBuffer, v2, v16, &params);
  v17 = v3->BorderColor;
  if ( v3->BorderColor >> 24 || v3->BackgroundColor >> 24 )
  {
    v18 = v3->BackgroundColor;
    *(_DWORD *)val = 2;
    v27 = v17;
    v19 = val;
    v26 = v18;
    v20 = 12;
    do
    {
      Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(&v2->Data, v19++);
      --v20;
    }
    while ( v20 );
  }
  v21 = v3->pEditorKit.pObject;
  if ( v21 )
    v21->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v21->vfptr, (unsigned int)v2);
  if ( v3->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(v3);
    v3->RTFlags &= 0xFCu;
  }
  v22 = v3->ViewRect.x1;
  v23 = v3->ViewRect.y2;
  v24 = v3->ViewRect.y1;
  v2->Bounds.x2 = v3->ViewRect.x2;
  v2->Bounds.y2 = v23;
  v2->Bounds.x1 = v22;
  v2->Bounds.y1 = v24;
}

// File Line: 2673
// RVA: 0x9B09E0
char __fastcall Scaleform::Render::Text::DocView::SetHScrollOffset(Scaleform::Render::Text::DocView *this, unsigned int hscroll)
{
  unsigned int v2; // edi
  Scaleform::Render::Text::DocView *v3; // rbx
  unsigned int v4; // eax
  Scaleform::Render::Text::DocView::DocumentListener *v5; // rcx

  v2 = hscroll;
  v3 = this;
  if ( this->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    v3->RTFlags &= 0xFCu;
  }
  v4 = Scaleform::Render::Text::DocView::GetMaxHScrollValue(v3);
  if ( v2 > v4 )
    v2 = v4;
  if ( v3->mLineBuffer.Geom.HScrollOffset == v2 )
    return 0;
  v5 = v3->pDocumentListener.pObject;
  v3->mLineBuffer.Geom.HScrollOffset = v2;
  if ( v5 )
    ((void (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::Render::Text::DocView *, _QWORD))v5->vfptr[3].__vecDelDtor)(
      v5,
      v3,
      v2);
  return 1;
}

// File Line: 2691
// RVA: 0x9B5690
char __fastcall Scaleform::Render::Text::DocView::SetVScrollOffset(Scaleform::Render::Text::DocView *this, unsigned int vscroll)
{
  unsigned int v2; // edi
  Scaleform::Render::Text::DocView *v3; // rbx
  unsigned int v4; // eax
  Scaleform::Render::Text::DocView::DocumentListener *v5; // rcx

  v2 = vscroll;
  v3 = this;
  v4 = Scaleform::Render::Text::DocView::GetMaxVScroll(this);
  if ( v2 > v4 )
    v2 = v4;
  if ( v3->mLineBuffer.Geom.FirstVisibleLinePos == v2 )
    return 0;
  v3->mLineBuffer.Geom.FirstVisibleLinePos = v2;
  v3->mLineBuffer.Geom.Flags |= 1u;
  v5 = v3->pDocumentListener.pObject;
  if ( v5 )
    ((void (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::Render::Text::DocView *, _QWORD))v5->vfptr[4].__vecDelDtor)(
      v5,
      v3,
      v2);
  return 1;
}

// File Line: 2709
// RVA: 0x985240
__int64 __fastcall Scaleform::Render::Text::DocView::GetHScrollOffset(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView *v1; // rbx

  v1 = this;
  if ( !(this->RTFlags & 3) )
    return this->mLineBuffer.Geom.HScrollOffset;
  Scaleform::Render::Text::DocView::Format(this);
  v1->RTFlags &= 0xFCu;
  return v1->mLineBuffer.Geom.HScrollOffset;
}

// File Line: 2720
// RVA: 0x98EB50
__int64 __fastcall Scaleform::Render::Text::DocView::GetVScrollOffset(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView *v1; // rbx

  v1 = this;
  if ( !(this->RTFlags & 3) )
    return this->mLineBuffer.Geom.FirstVisibleLinePos;
  Scaleform::Render::Text::DocView::Format(this);
  v1->RTFlags &= 0xFCu;
  return v1->mLineBuffer.Geom.FirstVisibleLinePos;
}

// File Line: 2731
// RVA: 0x98D8D0
float __fastcall Scaleform::Render::Text::DocView::GetTextWidth(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView *v1; // rbx
  signed int v2; // eax
  float result; // xmm0_4

  v1 = this;
  if ( this->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    v1->RTFlags &= 0xFCu;
  }
  v2 = v1->TextWidth;
  result = 0.0;
  if ( v2 )
    result = (float)v2;
  return result;
}

// File Line: 2743
// RVA: 0x98D890
float __fastcall Scaleform::Render::Text::DocView::GetTextHeight(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView *v1; // rbx
  signed int v2; // eax
  float result; // xmm0_4

  v1 = this;
  if ( this->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    v1->RTFlags &= 0xFCu;
  }
  v2 = v1->TextHeight;
  result = 0.0;
  if ( v2 )
    result = (float)v2;
  return result;
}

// File Line: 2756
// RVA: 0x988B60
__int64 __fastcall Scaleform::Render::Text::DocView::GetLinesCount(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView *v1; // rbx

  v1 = this;
  if ( !(this->RTFlags & 3) )
    return LODWORD(this->mLineBuffer.Lines.Data.Size);
  Scaleform::Render::Text::DocView::Format(this);
  v1->RTFlags &= 0xFCu;
  return LODWORD(v1->mLineBuffer.Lines.Data.Size);
}

// File Line: 2767
// RVA: 0x988FA0
__int64 __fastcall Scaleform::Render::Text::DocView::GetMaxHScrollValue(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView *v1; // rbx
  Scaleform::Render::Text::EditorKitBase *v3; // rcx
  signed int v4; // ecx
  signed int v5; // eax
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm1_4

  v1 = this;
  if ( this->Flags & 8 )
    return 0i64;
  v3 = this->pEditorKit.pObject;
  if ( !v3 || ((unsigned __int8 (*)(void))v3->vfptr[2].__vecDelDtor)() )
    v4 = 0;
  else
    v4 = 1200;
  v5 = v1->TextWidth;
  v6 = 0.0;
  if ( v5 )
    v7 = (float)v5;
  else
    v7 = 0.0;
  v8 = (float)(v7 - (float)(v1->mLineBuffer.Geom.VisibleRect.x2 - v1->mLineBuffer.Geom.VisibleRect.x1)) + (float)v4;
  if ( v8 >= 0.0 )
    v6 = v8;
  return (unsigned int)(signed int)v6;
}

// File Line: 2782
// RVA: 0x988F70
__int64 __fastcall Scaleform::Render::Text::DocView::GetMaxHScroll(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView *v1; // rbx

  v1 = this;
  if ( this->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    v1->RTFlags &= 0xFCu;
  }
  return Scaleform::Render::Text::DocView::GetMaxHScrollValue(v1);
}

// File Line: 2793
// RVA: 0x989070
__int64 __fastcall Scaleform::Render::Text::DocView::GetMaxVScroll(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView *v1; // rbx
  unsigned __int16 v2; // ax
  __int64 result; // rax
  Scaleform::Render::Text::EditorKitBase *v4; // rcx
  signed int v5; // esi
  __int64 v6; // rdi
  Scaleform::Render::Text::LineBuffer::Line *v7; // r14
  unsigned int v8; // eax
  unsigned __int64 v9; // r8
  Scaleform::Render::Text::LineBuffer::Line **v10; // r9
  Scaleform::Render::Text::LineBuffer::Line *v11; // rax
  unsigned int v12; // edx
  Scaleform::Render::Text::LineBuffer::Line *v13; // rcx
  unsigned int v14; // et1

  v1 = this;
  if ( this->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    v1->RTFlags &= 0xFCu;
  }
  v2 = v1->FormatCounter;
  if ( v1->MaxVScroll.FormatCounter == v2 )
    return v1->MaxVScroll.Value;
  if ( !LODWORD(v1->mLineBuffer.Lines.Data.Size) )
  {
    v1->MaxVScroll.Value = 0;
    v1->MaxVScroll.FormatCounter = v2;
    return v1->MaxVScroll.Value;
  }
  v4 = v1->pEditorKit.pObject;
  v5 = 0;
  v6 = (unsigned int)(LODWORD(v1->mLineBuffer.Lines.Data.Size) - 1);
  v7 = v1->mLineBuffer.Lines.Data.Data[(unsigned int)v6];
  if ( !v4 || ((unsigned __int8 (*)(void))v4->vfptr[2].__vecDelDtor)() )
  {
    v8 = (v7->MemSize & 0x80000000) == 0 ? v7->Data32.TextLength : HIBYTE(v7->Data8.TextPosAndLength);
    if ( !v8 )
    {
      if ( (signed int)v6 >= 0 )
        v6 = (unsigned int)(v6 - 1);
      v5 = 1;
    }
  }
  v9 = v1->mLineBuffer.Lines.Data.Size;
  if ( (unsigned int)v6 >= v9 || (signed int)v6 < 0 )
  {
    v1->MaxVScroll.FormatCounter = v1->FormatCounter;
    v1->MaxVScroll.Value = 0;
    result = v1->MaxVScroll.Value;
  }
  else
  {
    v10 = v1->mLineBuffer.Lines.Data.Data;
    v11 = v10[v6];
    if ( (v11->MemSize & 0x80000000) == 0 )
      v12 = v11->Data32.Height;
    else
      v12 = v11->Data8.Height;
    while ( (unsigned int)v6 < v9 )
    {
      if ( (signed int)v6 < 0 )
        break;
      v13 = v10[v6];
      if ( v5 )
      {
        v14 = v13->MemSize;
        if ( (float)v13->Data32.OffsetY < (float)((float)((float)(signed int)(v11->Data32.OffsetY + v12)
                                                        - v1->mLineBuffer.Geom.VisibleRect.y2)
                                                + v1->mLineBuffer.Geom.VisibleRect.y1) )
          break;
      }
      v6 = (unsigned int)(v6 - 1);
      ++v5;
    }
    result = (unsigned int)(v9 - v5);
    v1->MaxVScroll.FormatCounter = v1->FormatCounter;
    v1->MaxVScroll.Value = result;
  }
  return result;
}

// File Line: 2847
// RVA: 0x9AE2D0
void __fastcall Scaleform::Render::Text::DocView::SetAutoSizeX(Scaleform::Render::Text::DocView *this)
{
  char v1; // al

  v1 = this->Flags;
  if ( !(v1 & 1) )
  {
    this->RTFlags |= 2u;
    this->Flags = v1 | 1;
  }
}

// File Line: 2856
// RVA: 0x9AE2F0
void __fastcall Scaleform::Render::Text::DocView::SetAutoSizeY(Scaleform::Render::Text::DocView *this)
{
  char v1; // al

  v1 = this->Flags;
  if ( !(v1 & 2) )
  {
    this->RTFlags |= 2u;
    this->Flags = v1 | 2;
  }
}

// File Line: 2865
// RVA: 0x9B5F20
void __fastcall Scaleform::Render::Text::DocView::SetWordWrap(Scaleform::Render::Text::DocView *this)
{
  char v1; // al

  v1 = this->Flags;
  if ( !(v1 & 8) )
  {
    this->RTFlags |= 2u;
    this->Flags = v1 | 8;
  }
}

// File Line: 2874
// RVA: 0x960630
void __fastcall Scaleform::Render::Text::DocView::ClearWordWrap(Scaleform::Render::Text::DocView *this)
{
  char v1; // al

  v1 = this->Flags;
  if ( v1 & 8 )
  {
    this->RTFlags |= 2u;
    this->Flags = v1 & 0xF7;
  }
}

// File Line: 2883
// RVA: 0x97AE90
char __fastcall Scaleform::Render::Text::DocView::ForceReformat(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView *v1; // rbx

  v1 = this;
  if ( !(this->RTFlags & 3) )
    return 0;
  Scaleform::Render::Text::DocView::Format(this);
  v1->RTFlags &= 0xFCu;
  return 1;
}

// File Line: 2894
// RVA: 0x98FC00
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::Text::DocView::GetViewRect(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView *v1; // rbx

  v1 = this;
  if ( !(this->RTFlags & 3) )
    return &this->ViewRect;
  Scaleform::Render::Text::DocView::Format(this);
  v1->RTFlags &= 0xFCu;
  return &v1->ViewRect;
}

// File Line: 2900
// RVA: 0x981320
__int64 __fastcall Scaleform::Render::Text::DocView::GetCharIndexAtPoint(Scaleform::Render::Text::DocView *this, float x, float y)
{
  Scaleform::Render::Text::DocView *v3; // rbx
  float v4; // xmm6_4
  Scaleform::Render::Text::LineBuffer *v5; // rcx
  int v6; // edx
  unsigned __int64 v7; // rax
  Scaleform::Render::Text::LineBuffer::Line *v8; // rdx
  unsigned int v9; // et1
  Scaleform::Render::Text::LineBuffer::Line *v10; // r8
  unsigned int v11; // et1
  Scaleform::Render::Text::LineBuffer::Line *v12; // rdi
  float v13; // xmm1_4
  signed int v14; // eax
  float v15; // xmm6_4
  signed int v16; // ebx
  int v17; // esi
  int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // edx
  signed int v21; // eax
  __int64 v22; // rbx
  Scaleform::Render::Text::ImageDesc *v23; // rcx
  Scaleform::Render::Text::FontHandle *v24; // rcx
  Scaleform::Render::Text::LineBuffer::Iterator result; // [rsp+28h] [rbp-F0h]
  Scaleform::Render::Text::LineBuffer::GlyphIterator v27; // [rsp+50h] [rbp-C8h]

  v3 = this;
  if ( this->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    v3->RTFlags &= 0xFCu;
  }
  v4 = x - (float)(v3->mLineBuffer.Geom.VisibleRect.x1 - v3->ViewRect.x1);
  v5 = &v3->mLineBuffer;
  v6 = 0;
  v7 = v3->mLineBuffer.Geom.FirstVisibleLinePos;
  if ( (_DWORD)v7
    && v3 != (Scaleform::Render::Text::DocView *)-80i64
    && v7 < v3->mLineBuffer.Lines.Data.Size
    && (v7 & 0x80000000) == 0i64
    && v3 != (Scaleform::Render::Text::DocView *)-80i64
    && v3->mLineBuffer.Lines.Data.Size > 0 )
  {
    v8 = v5->Lines.Data.Data[(unsigned int)v7];
    v9 = v8->MemSize;
    v10 = *v5->Lines.Data.Data;
    v11 = v10->MemSize;
    v6 = v8->Data32.OffsetY - v10->Data32.OffsetY;
  }
  Scaleform::Render::Text::LineBuffer::FindLineAtYOffset(
    v5,
    &result,
    (float)v6 + (float)(y - (float)(v3->mLineBuffer.Geom.VisibleRect.y1 - v3->ViewRect.y1)));
  if ( !result.pLineBuffer )
    return -1i64;
  if ( result.CurrentPos >= result.pLineBuffer->Lines.Data.Size )
    return -1i64;
  if ( (result.CurrentPos & 0x80000000) != 0 )
    return -1i64;
  v12 = result.pLineBuffer->Lines.Data.Data[result.CurrentPos];
  v13 = (float)result.pLineBuffer->Lines.Data.Data[result.CurrentPos]->Data32.OffsetX;
  if ( v4 < v13 )
    return -1i64;
  v14 = (v12->MemSize & 0x80000000) == 0 ? v12->Data32.Width : v12->Data8.Width;
  if ( v4 > (float)((float)v14 + v13) )
    return -1i64;
  v15 = v4 - v13;
  v16 = 0;
  Scaleform::Render::Text::LineBuffer::Line::Begin(v12, &v27);
  v17 = 0;
  while ( v27.pGlyphs && v27.pGlyphs < v27.pEndGlyphs )
  {
    v18 = v27.pGlyphs->Advance;
    if ( (LOBYTE(v27.pGlyphs->Flags) >> 6) & 1 )
      v18 = -v18;
    v16 += v18;
    if ( (float)v16 > v15 )
      break;
    v19 = (unsigned int)v27.pGlyphs->LenAndFontSize >> 12;
    v17 += v19;
    v20 = v27.Delta;
    if ( !v27.Delta )
      v20 = (unsigned int)v27.pGlyphs->LenAndFontSize >> 12;
    v27.Delta = v20;
    ++v27.pGlyphs;
    if ( v27.pGlyphs->LenAndFontSize & 0xF000
      && v20
      && v27.HighlighterIter.CurAdjStartPos < v27.HighlighterIter.NumGlyphs )
    {
      if ( v20 )
      {
        v27.HighlighterIter.CurAdjStartPos += v20;
        Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(&v27.HighlighterIter);
      }
      v27.Delta = 0;
    }
    Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&v27);
  }
  v21 = v12->Data32.TextPos;
  if ( (v12->MemSize & 0x80000000) != 0 )
  {
    v21 &= 0xFFFFFFu;
    if ( v21 == 0xFFFFFF )
      v21 = -1;
  }
  v22 = (unsigned int)(v17 + v21);
  v23 = v27.pImage.pObject;
  if ( v27.pImage.pObject )
  {
    --v27.pImage.pObject->RefCount;
    if ( !v23->RefCount )
      v23->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v23->vfptr, 1u);
  }
  v24 = v27.pFontHandle.pObject;
  if ( v27.pFontHandle.pObject && !_InterlockedDecrement(&v27.pFontHandle.pObject->RefCount) && v24 )
    v24->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v24->vfptr, 1u);
  return v22;
}t->RefCount) && v24 )
    v24->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v

// File Line: 2936
// RVA: 0x981CA0
unsigned __int64 __fastcall Scaleform::Render::Text::DocView::GetCursorPosInLine(Scaleform::Render::Text::DocView *this, unsigned int lineIndex, float x)
{
  unsigned int v3; // edi
  Scaleform::Render::Text::DocView *v4; // rbx

  v3 = lineIndex;
  v4 = this;
  if ( lineIndex >= LODWORD(this->mLineBuffer.Lines.Data.Size) )
    return -1i64;
  if ( this->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    v4->RTFlags &= 0xFCu;
  }
  return Scaleform::Render::Text::DocView::GetCursorPosInLineByOffset(v4, v3, x);
}

// File Line: 2945
// RVA: 0x981D10
unsigned __int64 __fastcall Scaleform::Render::Text::DocView::GetCursorPosInLineByOffset(Scaleform::Render::Text::DocView *this, unsigned int lineIndex, float relativeOffsetX)
{
  Scaleform::Render::Text::LineBuffer::Line *v4; // rdi
  unsigned int v5; // et1
  float v6; // xmm6_4
  signed int v7; // esi
  int v8; // ebx
  unsigned __int16 v9; // r8
  unsigned int v10; // edx
  unsigned int v11; // eax
  signed int v12; // eax
  __int64 v13; // rbx
  Scaleform::Render::Text::ImageDesc *v14; // rcx
  Scaleform::Render::Text::FontHandle *v15; // rcx
  Scaleform::Render::Text::LineBuffer::GlyphIterator result; // [rsp+30h] [rbp-B8h]

  if ( lineIndex >= LODWORD(this->mLineBuffer.Lines.Data.Size) )
    return -1i64;
  v4 = this->mLineBuffer.Lines.Data.Data[lineIndex];
  v5 = v4->MemSize;
  v6 = (float)(relativeOffsetX - (float)this->mLineBuffer.Lines.Data.Data[lineIndex]->Data32.OffsetX)
     + (float)(signed int)this->mLineBuffer.Geom.HScrollOffset;
  v7 = 0;
  Scaleform::Render::Text::LineBuffer::Line::Begin(v4, &result);
  v8 = 0;
  while ( result.pGlyphs && result.pGlyphs < result.pEndGlyphs )
  {
    v9 = result.pGlyphs->Flags;
    v10 = result.pGlyphs->Advance;
    if ( ((unsigned __int8)v9 >> 6) & 1 )
      v10 = -v10;
    if ( (float)(signed int)(v10 + v7) > v6 )
    {
      if ( (float)(v6 - (float)v7) > (float)(v10 >> 1) )
        v8 += (unsigned int)result.pGlyphs->LenAndFontSize >> 12;
      break;
    }
    v7 += v10;
    if ( !(v9 & 0x100) )
      v8 += (unsigned int)result.pGlyphs->LenAndFontSize >> 12;
    v11 = result.Delta;
    if ( !result.Delta )
    {
      v11 = (unsigned int)result.pGlyphs->LenAndFontSize >> 12;
      result.Delta = (unsigned int)result.pGlyphs->LenAndFontSize >> 12;
    }
    ++result.pGlyphs;
    if ( result.pGlyphs->LenAndFontSize & 0xF000
      && v11
      && result.HighlighterIter.CurAdjStartPos < result.HighlighterIter.NumGlyphs )
    {
      if ( v11 )
      {
        result.HighlighterIter.CurAdjStartPos += v11;
        Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(&result.HighlighterIter);
      }
      result.Delta = 0;
    }
    Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&result);
  }
  v12 = v4->Data32.TextPos;
  if ( (v4->MemSize & 0x80000000) != 0 )
  {
    v12 &= 0xFFFFFFu;
    if ( v12 == 0xFFFFFF )
      v12 = -1;
  }
  v13 = (unsigned int)(v12 + v8);
  v14 = result.pImage.pObject;
  if ( result.pImage.pObject )
  {
    --result.pImage.pObject->RefCount;
    if ( !v14->RefCount )
      v14->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v14->vfptr, 1u);
  }
  v15 = result.pFontHandle.pObject;
  if ( result.pFontHandle.pObject && !_InterlockedDecrement(&result.pFontHandle.pObject->RefCount) && v15 )
    v15->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v15->vfptr, 1u);
  return v13;
}

// File Line: 2983
// RVA: 0x981B30
signed __int64 __fastcall Scaleform::Render::Text::DocView::GetCursorPosAtPoint(Scaleform::Render::Text::DocView *this, float x, float y)
{
  Scaleform::Render::Text::DocView *v3; // rbx
  unsigned __int64 v4; // rax
  Scaleform::Render::Text::LineBuffer *v5; // rdi
  int v6; // ecx
  float v7; // xmm7_4
  float v8; // xmm6_4
  Scaleform::Render::Text::LineBuffer::Line *v9; // rcx
  unsigned int v10; // et1
  Scaleform::Render::Text::LineBuffer::Line *v11; // rdx
  unsigned int v12; // et1
  Scaleform::Render::Text::LineBuffer *v13; // rdx
  unsigned int v14; // ecx
  signed __int64 v15; // rax
  Scaleform::Render::Text::LineBuffer::Iterator result; // [rsp+20h] [rbp-68h]
  __int64 v17; // [rsp+50h] [rbp-38h]
  __int64 v18; // [rsp+58h] [rbp-30h]

  v3 = this;
  if ( this->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    v3->RTFlags &= 0xFCu;
  }
  v4 = v3->mLineBuffer.Geom.FirstVisibleLinePos;
  v5 = &v3->mLineBuffer;
  v6 = 0;
  v7 = x - (float)(v3->mLineBuffer.Geom.VisibleRect.x1 - v3->ViewRect.x1);
  v8 = y - (float)(v3->mLineBuffer.Geom.VisibleRect.y1 - v3->ViewRect.y1);
  if ( (_DWORD)v4
    && v3 != (Scaleform::Render::Text::DocView *)-80i64
    && v4 < v3->mLineBuffer.Lines.Data.Size
    && (v4 & 0x80000000) == 0i64
    && v3 != (Scaleform::Render::Text::DocView *)-80i64
    && v3->mLineBuffer.Lines.Data.Size > 0 )
  {
    v9 = v5->Lines.Data.Data[(unsigned int)v4];
    v10 = v9->MemSize;
    v11 = *v5->Lines.Data.Data;
    v12 = v11->MemSize;
    v6 = v9->Data32.OffsetY - v11->Data32.OffsetY;
  }
  Scaleform::Render::Text::LineBuffer::FindLineAtYOffset(&v3->mLineBuffer, &result, (float)v6 + v8);
  v13 = result.pLineBuffer;
  if ( !result.pLineBuffer
    || (v14 = result.CurrentPos, result.CurrentPos >= result.pLineBuffer->Lines.Data.Size)
    || (result.CurrentPos & 0x80000000) != 0 )
  {
    v13 = &v3->mLineBuffer;
    result.pHighlight = 0i64;
    if ( v8 > 0.0 )
      v17 = (unsigned int)(LODWORD(v3->mLineBuffer.Lines.Data.Size) - 1);
    else
      v17 = 0i64;
    v14 = v17;
    LOBYTE(v18) = ((unsigned __int8)v3->mLineBuffer.Geom.Flags >> 2) & 1;
    *(_QWORD *)&result.StaticText = v18;
  }
  if ( v13 && v14 < v13->Lines.Data.Size && (v14 & 0x80000000) == 0 )
    v15 = Scaleform::Render::Text::DocView::GetCursorPosInLineByOffset(v3, v14, v7);
  else
    v15 = -(signed __int64)(LODWORD(v3->mLineBuffer.Lines.Data.Size) != 0);
  return v15;
}

// File Line: 3005
// RVA: 0x997EE0
__int64 __fastcall Scaleform::Render::Text::DocView::IsUrlAtPoint(Scaleform::Render::Text::DocView *this, float x, float y, Scaleform::Range *purlPosRange)
{
  Scaleform::Range *v4; // rbx
  Scaleform::Render::Text::DocView *v5; // rsi
  float v6; // xmm6_4
  Scaleform::Render::Text::LineBuffer *v7; // rcx
  int v8; // edx
  unsigned __int64 v9; // rax
  Scaleform::Render::Text::LineBuffer::Line *v10; // rdx
  unsigned int v11; // et1
  Scaleform::Render::Text::LineBuffer::Line *v12; // r8
  unsigned int v13; // et1
  unsigned __int8 v14; // r12
  Scaleform::Render::Text::LineBuffer::Line *v15; // r14
  float v16; // xmm1_4
  signed int v17; // eax
  float v18; // xmm6_4
  signed int v19; // edi
  int v20; // er15
  signed __int64 v21; // r8
  int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // edx
  signed int v25; // eax
  unsigned __int64 v26; // r14
  Scaleform::Render::Text::Paragraph *v27; // rsi
  Scaleform::Render::Text::TextFormat *v28; // rax
  unsigned __int64 v29; // rdi
  Scaleform::Render::Text::TextFormat *v30; // rcx
  unsigned __int8 *v31; // rax
  unsigned __int64 v32; // r8
  int v33; // ecx
  int v34; // edx
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v35; // r11
  unsigned __int64 v36; // rax
  Scaleform::Render::Text::TextFormat *v37; // rbx
  bool v38; // zf
  Scaleform::Render::Text::ImageDesc *v39; // rcx
  Scaleform::Render::Text::FontHandle *v40; // rcx
  Scaleform::Render::Text::Paragraph::FormatRunIterator v42; // [rsp+20h] [rbp-B8h]
  Scaleform::Render::Text::LineBuffer::Iterator result; // [rsp+68h] [rbp-70h]
  Scaleform::Render::Text::LineBuffer::GlyphIterator v44; // [rsp+88h] [rbp-50h]
  Scaleform::Render::Text::TextFormat v45; // [rsp+128h] [rbp+50h]
  Scaleform::Render::Text::TextFormat v46; // [rsp+178h] [rbp+A0h]
  unsigned __int64 pindexInParagraph; // [rsp+218h] [rbp+140h]

  v42.CurTextIndex = -2i64;
  v4 = purlPosRange;
  v5 = this;
  if ( this->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    v5->RTFlags &= 0xFCu;
  }
  v6 = x - (float)(v5->mLineBuffer.Geom.VisibleRect.x1 - v5->ViewRect.x1);
  v7 = &v5->mLineBuffer;
  v8 = 0;
  v9 = v5->mLineBuffer.Geom.FirstVisibleLinePos;
  if ( (_DWORD)v9
    && v5 != (Scaleform::Render::Text::DocView *)-80i64
    && v9 < v5->mLineBuffer.Lines.Data.Size
    && (v9 & 0x80000000) == 0i64
    && v5 != (Scaleform::Render::Text::DocView *)-80i64
    && v5->mLineBuffer.Lines.Data.Size > 0 )
  {
    v10 = v7->Lines.Data.Data[(unsigned int)v9];
    v11 = v10->MemSize;
    v12 = *v7->Lines.Data.Data;
    v13 = v12->MemSize;
    v8 = v10->Data32.OffsetY - v12->Data32.OffsetY;
  }
  Scaleform::Render::Text::LineBuffer::FindLineAtYOffset(
    v7,
    &result,
    (float)v8 + (float)(y - (float)(v5->mLineBuffer.Geom.VisibleRect.y1 - v5->ViewRect.y1)));
  v14 = 0;
  if ( result.pLineBuffer )
  {
    if ( result.CurrentPos < result.pLineBuffer->Lines.Data.Size && (result.CurrentPos & 0x80000000) == 0 )
    {
      v15 = result.pLineBuffer->Lines.Data.Data[result.CurrentPos];
      v16 = (float)result.pLineBuffer->Lines.Data.Data[result.CurrentPos]->Data32.OffsetX;
      if ( v6 >= v16 )
      {
        v17 = (v15->MemSize & 0x80000000) == 0 ? v15->Data32.Width : v15->Data8.Width;
        if ( v6 <= (float)((float)v17 + v16) )
        {
          v18 = (float)(v6 - v16) + (float)(signed int)v5->mLineBuffer.Geom.HScrollOffset;
          v19 = 0;
          Scaleform::Render::Text::LineBuffer::Line::Begin(v15, &v44);
          v20 = 0;
          while ( 1 )
          {
            v21 = 61440i64;
            if ( !v44.pGlyphs || v44.pGlyphs >= v44.pEndGlyphs )
              goto LABEL_67;
            v22 = v44.pGlyphs->Advance;
            if ( (LOBYTE(v44.pGlyphs->Flags) >> 6) & 1 )
              v22 = -v22;
            v19 += v22;
            if ( (float)v19 > v18 )
              break;
            v23 = (unsigned int)v44.pGlyphs->LenAndFontSize >> 12;
            v20 += v23;
            v24 = v44.Delta;
            if ( !v44.Delta )
              v24 = (unsigned int)v44.pGlyphs->LenAndFontSize >> 12;
            v44.Delta = v24;
            ++v44.pGlyphs;
            if ( v44.pGlyphs->LenAndFontSize & 0xF000
              && v24
              && v44.HighlighterIter.CurAdjStartPos < v44.HighlighterIter.NumGlyphs )
            {
              if ( v24 )
              {
                v44.HighlighterIter.CurAdjStartPos += v24;
                Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(&v44.HighlighterIter);
              }
              v44.Delta = 0;
            }
            Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&v44);
          }
          v14 = LOBYTE(v44.pGlyphs->Flags) >> 7;
          if ( SLOBYTE(v44.pGlyphs->Flags) < 0 && v4 )
          {
            v4->Index = 0i64;
            v4->Length = 0i64;
            v25 = v15->Data32.TextPos;
            if ( (v15->MemSize & 0x80000000) != 0 )
            {
              v25 &= 0xFFFFFFu;
              if ( v25 == 0xFFFFFF )
                v25 = -1;
            }
            v26 = (unsigned int)(v20 + v25);
            pindexInParagraph = 0i64;
            Scaleform::Render::Text::StyledText::GetParagraphByIndex(
              (Scaleform::Render::Text::StyledText *)&v5->pDocument.pObject->vfptr,
              (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator *)&result.pHighlight,
              v26,
              &pindexInParagraph);
            if ( result.pHighlight )
            {
              if ( *(_QWORD *)&result.CurrentPos >= 0i64
                && *(_QWORD *)&result.CurrentPos < (signed __int64)SLODWORD(result.pHighlight->Highlighters.Data.Size) )
              {
                v27 = (Scaleform::Render::Text::Paragraph *)*(&result.pHighlight->Highlighters.Data.Data->StartPos
                                                            + *(_QWORD *)&result.CurrentPos);
                v28 = Scaleform::Render::Text::Paragraph::GetTextFormat(
                        *((Scaleform::Render::Text::Paragraph **)&result.pHighlight->Highlighters.Data.Data->StartPos
                        + *(_QWORD *)&result.CurrentPos),
                        &v46,
                        pindexInParagraph,
                        pindexInParagraph + 1);
                Scaleform::Render::Text::TextFormat::TextFormat(&v45, v28, 0i64);
                Scaleform::Render::Text::TextFormat::~TextFormat(&v46);
                Scaleform::Render::Text::Paragraph::GetIterator(v27, &v42);
                if ( v42.CurTextIndex < v42.pText->Size )
                {
                  do
                  {
                    v29 = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v42)->PlaceHolder.Index
                        + v27->StartIndex;
                    v30 = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v42)->PlaceHolder.pFormat.pObject;
                    if ( !(v30->PresentMask & 0x100) || !Scaleform::String::GetLength((Scaleform::String *)&v30->Url.0) )
                      goto LABEL_77;
                    v31 = (unsigned __int8 *)((Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v42)->PlaceHolder.pFormat.pObject->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                            + 12);
                    v32 = (v45.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12 - (_QWORD)v31;
                    do
                    {
                      v33 = v31[v32];
                      v34 = *v31 - v33;
                      if ( *v31 != v33 )
                        break;
                      ++v31;
                    }
                    while ( v33 );
                    if ( !v34 )
                    {
                      if ( v4->Index + v4->Length >= v29 )
                      {
                        v4->Length += Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v42)->PlaceHolder.Length;
                      }
                      else
                      {
                        if ( v29 > v26 )
                          break;
                        v4->Index = v29;
                        v4->Length = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v42)->PlaceHolder.Length;
                      }
                    }
                    else
                    {
LABEL_77:
                      if ( v29 > v26 )
                        break;
                      v4->Index = 0i64;
                      v4->Length = 0i64;
                    }
                    if ( v42.FormatIterator.Index < 0
                      || v42.FormatIterator.Index >= v42.FormatIterator.pArray->Ranges.Data.Size )
                    {
                      v36 = v42.pText->Size;
                    }
                    else
                    {
                      v35 = v42.FormatIterator.pArray->Ranges.Data.Data;
                      if ( v42.CurTextIndex >= v42.FormatIterator.pArray->Ranges.Data.Data[v42.FormatIterator.Index].Index )
                      {
                        v36 = v35[v42.FormatIterator.Index].Length + v42.CurTextIndex;
                        v42.CurTextIndex += v35[v42.FormatIterator.Index].Length;
                        if ( v42.FormatIterator.Index < (signed __int64)v42.FormatIterator.pArray->Ranges.Data.Size )
                          ++v42.FormatIterator.Index;
                        continue;
                      }
                      v36 = v42.FormatIterator.pArray->Ranges.Data.Data[v42.FormatIterator.Index].Index;
                    }
                    v42.CurTextIndex = v36;
                  }
                  while ( v36 < v42.pText->Size );
                }
                v42.pText = (Scaleform::Render::Text::Paragraph::TextBuffer *)&v42;
                v37 = v42.PlaceHolder.pFormat.pObject;
                if ( v42.PlaceHolder.pFormat.pObject )
                {
                  v38 = v42.PlaceHolder.pFormat.pObject->RefCount-- == 1;
                  if ( v38 )
                  {
                    Scaleform::Render::Text::TextFormat::~TextFormat(v37);
                    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v37);
                  }
                }
                Scaleform::Render::Text::TextFormat::~TextFormat(&v45);
              }
            }
          }
LABEL_67:
          v39 = v44.pImage.pObject;
          if ( v44.pImage.pObject )
          {
            --v44.pImage.pObject->RefCount;
            if ( !v39->RefCount )
              ((void (__fastcall *)(Scaleform::Render::Text::ImageDesc *, signed __int64, signed __int64))v39->vfptr->__vecDelDtor)(
                v39,
                1i64,
                v21);
          }
          v40 = v44.pFontHandle.pObject;
          if ( v44.pFontHandle.pObject && !_InterlockedDecrement(&v44.pFontHandle.pObject->RefCount) && v40 )
            v40->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v40->vfptr, 1u);
        }
      }
    }
  }
  return v14;
}

// File Line: 3087
// RVA: 0x9AFE90
void __fastcall Scaleform::Render::Text::DocView::SetFontScaleFactor(Scaleform::Render::Text::DocView *this, float f)
{
  if ( f == 1.0 )
  {
    this->RTFlags &= 0xFBu;
    this->FontScaleFactor = 20;
  }
  else
  {
    this->RTFlags |= 4u;
    this->FontScaleFactor = (signed int)(float)(f * 20.0);
  }
}

// File Line: 3102
// RVA: 0x988680
signed __int64 __fastcall Scaleform::Render::Text::DocView::GetLineIndexAtPoint(Scaleform::Render::Text::DocView *this, float x, float y)
{
  Scaleform::Render::Text::DocView *v3; // rbx
  unsigned __int64 v4; // rax
  Scaleform::Render::Text::LineBuffer *v5; // rcx
  int v6; // edx
  Scaleform::Render::Text::LineBuffer::Line *v7; // rdx
  unsigned int v8; // et1
  Scaleform::Render::Text::LineBuffer::Line *v9; // r8
  unsigned int v10; // et1
  signed __int64 v11; // rax
  Scaleform::Render::Text::LineBuffer::Iterator result; // [rsp+20h] [rbp-38h]

  v3 = this;
  if ( this->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    v3->RTFlags &= 0xFCu;
  }
  v4 = v3->mLineBuffer.Geom.FirstVisibleLinePos;
  v5 = &v3->mLineBuffer;
  v6 = 0;
  if ( (_DWORD)v4
    && v3 != (Scaleform::Render::Text::DocView *)-80i64
    && v4 < v3->mLineBuffer.Lines.Data.Size
    && (v4 & 0x80000000) == 0i64
    && v3 != (Scaleform::Render::Text::DocView *)-80i64
    && v3->mLineBuffer.Lines.Data.Size > 0 )
  {
    v7 = v5->Lines.Data.Data[(unsigned int)v4];
    v8 = v7->MemSize;
    v9 = *v5->Lines.Data.Data;
    v10 = v9->MemSize;
    v6 = v7->Data32.OffsetY - v9->Data32.OffsetY;
  }
  Scaleform::Render::Text::LineBuffer::FindLineAtYOffset(v5, &result, (float)v6 + y);
  if ( !result.pLineBuffer
    || (v11 = result.CurrentPos, result.CurrentPos >= result.pLineBuffer->Lines.Data.Size)
    || (signed int)v11 < 0 )
  {
    v11 = 0xFFFFFFFFi64;
  }
  return v11;
}

// File Line: 3115
// RVA: 0x988740
signed __int64 __fastcall Scaleform::Render::Text::DocView::GetLineIndexOfChar(Scaleform::Render::Text::DocView *this, unsigned __int64 indexOfChar)
{
  unsigned __int64 v2; // rdi
  Scaleform::Render::Text::DocView *v3; // rbx
  signed __int64 v4; // rax
  Scaleform::Render::Text::LineBuffer::Iterator result; // [rsp+20h] [rbp-28h]

  v2 = indexOfChar;
  v3 = this;
  if ( this->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    v3->RTFlags &= 0xFCu;
  }
  Scaleform::Render::Text::LineBuffer::FindLineByTextPos(&v3->mLineBuffer, &result, v2);
  if ( !result.pLineBuffer
    || (v4 = result.CurrentPos, result.CurrentPos >= result.pLineBuffer->Lines.Data.Size)
    || (signed int)v4 < 0 )
  {
    v4 = 0xFFFFFFFFi64;
  }
  return v4;
}

// File Line: 3127
// RVA: 0x9889C0
unsigned __int64 __fastcall Scaleform::Render::Text::DocView::GetLineOffset(Scaleform::Render::Text::DocView *this, unsigned int lineIndex)
{
  unsigned __int64 v2; // rdi
  Scaleform::Render::Text::DocView *v3; // rbx
  Scaleform::Render::Text::LineBuffer::Line *v4; // rcx
  unsigned __int64 result; // rax

  v2 = lineIndex;
  v3 = this;
  if ( this->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    v3->RTFlags &= 0xFCu;
  }
  if ( v3 == (Scaleform::Render::Text::DocView *)-80i64
    || v2 >= v3->mLineBuffer.Lines.Data.Size
    || (v2 & 0x80000000) != 0i64 )
  {
    return -1i64;
  }
  v4 = v3->mLineBuffer.Lines.Data.Data[v2];
  if ( (v4->MemSize & 0x80000000) == 0 )
    return v4->Data32.TextPos;
  result = v4->Data32.TextPos & 0xFFFFFF;
  if ( (_DWORD)result == 0xFFFFFF )
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 3139
// RVA: 0x9887A0
unsigned __int64 __fastcall Scaleform::Render::Text::DocView::GetLineLength(Scaleform::Render::Text::DocView *this, unsigned int lineIndex, bool *phasNewLine)
{
  bool *v3; // rdi
  unsigned __int64 v4; // rsi
  Scaleform::Render::Text::DocView *v5; // rbx
  Scaleform::Render::Text::LineBuffer *v6; // rbx
  Scaleform::Render::Text::LineBuffer::Line *v7; // rcx
  unsigned int v8; // edx
  signed __int64 v9; // rcx
  __int64 v10; // rax
  __int64 v11; // rdx
  bool v12; // al
  Scaleform::Render::Text::LineBuffer::Line *v13; // rcx
  unsigned __int64 result; // rax

  v3 = phasNewLine;
  v4 = lineIndex;
  v5 = this;
  if ( this->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    v5->RTFlags &= 0xFCu;
  }
  v6 = &v5->mLineBuffer;
  if ( v6 && v4 < v6->Lines.Data.Size && (v4 & 0x80000000) == 0i64 )
  {
    if ( v3 )
    {
      v7 = v6->Lines.Data.Data[v4];
      if ( (v7->MemSize & 0x80000000) == 0 )
        v8 = v7->Data32.GlyphsCount;
      else
        v8 = (unsigned __int8)v7->Data8.GlyphsCount;
      v12 = 0;
      if ( v8 )
      {
        v9 = (signed __int64)((v7->MemSize & 0x80000000) == 0 ? (Scaleform::Render::Text::LineBuffer::LineData8 *)((char *)&v7->Data8 + 38) : &v7->Data8.Leading + 1);
        v10 = v8 - 1;
        v11 = v8 - 1;
        if ( *(_BYTE *)(v9 + 8 * v10 + 7) & 1 )
        {
          if ( *(_WORD *)(v9 + 8 * v11 + 4) & 0xF000 )
            v12 = 1;
        }
      }
      *v3 = v12;
    }
    v13 = v6->Lines.Data.Data[v4];
    if ( (v13->MemSize & 0x80000000) == 0 )
      result = v13->Data32.TextLength;
    else
      result = HIBYTE(v13->Data8.TextPosAndLength);
  }
  else
  {
    if ( v3 )
      *v3 = 0;
    result = -1i64;
  }
  return result;
}

// File Line: 3155
// RVA: 0x988A50
wchar_t *__fastcall Scaleform::Render::Text::DocView::GetLineText(Scaleform::Render::Text::DocView *this, unsigned int lineIndex, unsigned __int64 *plen)
{
  unsigned __int64 *v3; // r14
  unsigned __int64 v4; // rsi
  Scaleform::Render::Text::DocView *v5; // rbx
  Scaleform::Render::Text::LineBuffer *v7; // rdi
  Scaleform::Render::Text::LineBuffer::Line *v8; // rcx
  unsigned int v9; // eax
  Scaleform::Render::Text::StyledText *v10; // rcx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *v11; // r8
  __int64 v12; // rdx
  Scaleform::Render::Text::LineBuffer::Line *v13; // rcx
  unsigned __int64 v14; // rax
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator result; // [rsp+20h] [rbp-28h]
  unsigned __int64 pindexInParagraph; // [rsp+60h] [rbp+18h]

  v3 = plen;
  v4 = lineIndex;
  v5 = this;
  if ( !plen )
    return 0i64;
  if ( this->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    v5->RTFlags &= 0xFCu;
  }
  v7 = &v5->mLineBuffer;
  if ( v5 == (Scaleform::Render::Text::DocView *)-80i64
    || v4 >= v5->mLineBuffer.Lines.Data.Size
    || (v4 & 0x80000000) != 0i64 )
  {
    return 0i64;
  }
  v8 = v7->Lines.Data.Data[v4];
  v9 = v8->Data32.TextPos;
  if ( (v8->MemSize & 0x80000000) != 0 )
  {
    v9 &= 0xFFFFFFu;
    if ( v9 == 0xFFFFFF )
      v9 = -1;
  }
  v10 = (Scaleform::Render::Text::StyledText *)&v5->pDocument.pObject->vfptr;
  pindexInParagraph = 0i64;
  Scaleform::Render::Text::StyledText::GetParagraphByIndex(v10, &result, v9, &pindexInParagraph);
  v11 = result.pArray;
  if ( !result.pArray )
    return 0i64;
  v12 = result.CurIndex;
  if ( result.CurIndex < 0 || result.CurIndex >= SLODWORD(result.pArray->Data.Size) )
    return 0i64;
  v13 = v7->Lines.Data.Data[v4];
  if ( (v13->MemSize & 0x80000000) == 0 )
    v14 = v13->Data32.TextLength;
  else
    v14 = HIBYTE(v13->Data8.TextPosAndLength);
  *v3 = v14;
  return &v11->Data.Data[v12].pPara->Text.pText[pindexInParagraph];
}

// File Line: 3176
// RVA: 0x98A390
unsigned __int64 __fastcall Scaleform::Render::Text::DocView::GetParagraphLength(Scaleform::Render::Text::DocView *this, unsigned __int64 charIndex)
{
  unsigned __int64 v2; // rbx
  Scaleform::Render::Text::DocView *v3; // rdi
  Scaleform::Render::Text::DocView::DocumentText *v4; // rdi
  wchar_t *v5; // rsi
  signed __int64 v6; // rdx
  unsigned __int64 v7; // r10
  unsigned __int64 v8; // r11
  Scaleform::Render::Text::Paragraph *v9; // rax
  unsigned __int64 v10; // r9
  Scaleform::Render::Text::Paragraph *v11; // rax
  unsigned __int64 v12; // rdx
  Scaleform::Render::Text::Paragraph *v13; // rdx
  unsigned __int64 result; // rax
  wchar_t *v15; // rdx
  unsigned __int64 v16; // rcx

  v2 = charIndex;
  v3 = this;
  if ( this->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    v3->RTFlags &= 0xFCu;
  }
  v4 = v3->pDocument.pObject;
  v5 = 0i64;
  v6 = v4->Paragraphs.Data.Size;
  v7 = 0i64;
  while ( v6 > 0 )
  {
    v8 = (v6 >> 1) + v7;
    v9 = v4->Paragraphs.Data.Data[v8].pPara;
    v10 = v9->StartIndex;
    if ( v2 >= v10 && v2 < v10 + v9->Text.Size || (signed int)v10 - (signed int)v2 >= 0 )
    {
      v6 >>= 1;
    }
    else
    {
      v7 = v8 + 1;
      v6 += -1 - (v6 >> 1);
    }
  }
  if ( v7 >= v4->Paragraphs.Data.Size )
    return -1i64;
  v11 = v4->Paragraphs.Data.Data[v7].pPara;
  v12 = v11->StartIndex;
  if ( (v2 < v12 || v2 >= v12 + v11->Text.Size) && (_DWORD)v12 != (_DWORD)v2 )
    return -1i64;
  if ( (v7 & 0x80000000) != 0i64 || (signed int)v7 >= (signed __int64)SLODWORD(v4->Paragraphs.Data.Size) )
    return -1i64;
  v13 = v4->Paragraphs.Data.Data[(signed int)v7].pPara;
  result = v13->Text.Size;
  if ( result )
  {
    v15 = v13->Text.pText;
    v16 = result - 1;
    if ( v15 && v16 < result )
      v5 = &v15[v16];
    if ( !*v5 )
      --result;
  }
  return result;
}

// File Line: 3189
// RVA: 0x988890
char __fastcall Scaleform::Render::Text::DocView::GetLineMetrics(Scaleform::Render::Text::DocView *this, unsigned int lineIndex, Scaleform::Render::Text::DocView::LineMetrics *pmetrics)
{
  Scaleform::Render::Text::DocView::LineMetrics *v3; // rbx
  unsigned __int64 v4; // rsi
  Scaleform::Render::Text::DocView *v5; // rdi
  Scaleform::Render::Text::LineBuffer::Line *v6; // rcx
  signed int v7; // eax
  signed int v8; // edx
  signed int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  int v12; // eax
  bool v13; // zf

  v3 = pmetrics;
  v4 = lineIndex;
  v5 = this;
  if ( !pmetrics )
    return 0;
  if ( this->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    v5->RTFlags &= 0xFCu;
  }
  if ( v5 == (Scaleform::Render::Text::DocView *)-80i64
    || v4 >= v5->mLineBuffer.Lines.Data.Size
    || (v4 & 0x80000000) != 0i64 )
  {
    return 0;
  }
  v6 = v5->mLineBuffer.Lines.Data.Data[v4];
  if ( (v6->MemSize & 0x80000000) == 0 )
    v7 = v6->Data32.BaseLineOffset;
  else
    v7 = v6->Data8.BaseLineOffset;
  v3->Ascent = (signed int)(float)v7;
  if ( (v6->MemSize & 0x80000000) == 0 )
    v8 = v6->Data32.Height;
  else
    v8 = v6->Data8.Height;
  if ( (v6->MemSize & 0x80000000) == 0 )
    v9 = v6->Data32.BaseLineOffset;
  else
    v9 = v6->Data8.BaseLineOffset;
  v3->Descent = (signed int)(float)((float)v8 - (float)v9);
  if ( (v6->MemSize & 0x80000000) == 0 )
    v10 = v6->Data32.Width;
  else
    v10 = v6->Data8.Width;
  v3->Width = v10;
  if ( (v6->MemSize & 0x80000000) == 0 )
    v11 = v6->Data32.Height;
  else
    v11 = v6->Data8.Height;
  v3->Height = v11;
  if ( (v6->MemSize & 0x80000000) == 0 )
    v12 = v6->Data32.Leading;
  else
    v12 = v6->Data8.Leading;
  v3->Leading = v12;
  v13 = (v6->MemSize & 0x80000000) == 0;
  v3->FirstCharXOff = v6->Data32.OffsetX;
  return 1;
}

// File Line: 3212
// RVA: 0x981080
char __fastcall Scaleform::Render::Text::DocView::GetCharBoundaries(Scaleform::Render::Text::DocView *this, Scaleform::Render::Rect<float> *pCharRect, unsigned __int64 indexOfChar)
{
  unsigned __int64 v3; // rbp
  Scaleform::Render::Rect<float> *v4; // r14
  Scaleform::Render::Text::DocView *v5; // rbx
  char v6; // r15
  Scaleform::Render::Text::LineBuffer::Line *v7; // rdi
  signed __int64 v8; // rax
  unsigned __int64 v9; // rbp
  __int64 v10; // rax
  signed int v11; // esi
  int i; // ebx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v13; // rcx
  int v14; // eax
  unsigned int v15; // eax
  int v16; // eax
  float v17; // xmm3_4
  signed int v18; // eax
  bool v19; // zf
  float v20; // xmm0_4
  float v21; // xmm2_4
  Scaleform::Render::Text::ImageDesc *v22; // rcx
  Scaleform::Render::Text::FontHandle *v23; // rcx
  Scaleform::Render::Text::LineBuffer::Iterator result; // [rsp+28h] [rbp-F0h]
  Scaleform::Render::Text::LineBuffer::GlyphIterator v26; // [rsp+50h] [rbp-C8h]

  v3 = indexOfChar;
  v4 = pCharRect;
  v5 = this;
  if ( !pCharRect
    || indexOfChar >= Scaleform::Render::Text::StyledText::GetLength((Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr) )
  {
    return 0;
  }
  if ( v5->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(v5);
    v5->RTFlags &= 0xFCu;
  }
  Scaleform::Render::Text::LineBuffer::FindLineByTextPos(&v5->mLineBuffer, &result, v3);
  v6 = 0;
  if ( result.pLineBuffer
    && result.CurrentPos < result.pLineBuffer->Lines.Data.Size
    && (result.CurrentPos & 0x80000000) == 0 )
  {
    v7 = result.pLineBuffer->Lines.Data.Data[result.CurrentPos];
    if ( (v7->MemSize & 0x80000000) == 0 )
    {
      v8 = v7->Data32.TextPos;
    }
    else
    {
      v8 = v7->Data32.TextPos & 0xFFFFFF;
      if ( (_DWORD)v8 == 0xFFFFFF )
        v8 = 0xFFFFFFFFi64;
    }
    v9 = v3 - v8;
    Scaleform::Render::Text::LineBuffer::Line::Begin(v7, &v26);
    v10 = v7->MemSize >> 31;
    v11 = v7->Data32.OffsetX;
    for ( i = 0; ; ++i )
    {
      v13 = v26.pGlyphs;
      if ( !v26.pGlyphs || v26.pGlyphs >= v26.pEndGlyphs )
        break;
      if ( i == v9 )
      {
        if ( !(v26.pGlyphs->Flags & 0x100) )
        {
          v6 = 1;
          *(_QWORD *)&v4->x1 = 0i64;
          *(_QWORD *)&v4->x2 = 0i64;
          v16 = v13->Advance;
          if ( (LOBYTE(v13->Flags) >> 6) & 1 )
            v16 = -v16;
          v17 = (float)v16;
          v4->x2 = (float)v16;
          v4->y1 = 40.0;
          if ( (v7->MemSize & 0x80000000) == 0 )
            v18 = v7->Data32.Height;
          else
            v18 = v7->Data8.Height;
          v4->y2 = (float)v18;
          v19 = (v7->MemSize & 0x80000000) == 0;
          v20 = (float)v11 + 40.0;
          v21 = (float)v7->Data32.OffsetY;
          v4->x1 = v20;
          v4->x2 = v17 + v20;
          v4->y1 = v21 + 40.0;
          v4->y2 = v21 + (float)v18;
        }
        break;
      }
      v14 = v26.pGlyphs->Advance;
      if ( (LOBYTE(v26.pGlyphs->Flags) >> 6) & 1 )
        v14 = -v14;
      v11 += v14;
      v15 = v26.Delta;
      if ( !v26.Delta )
      {
        v15 = (unsigned int)v26.pGlyphs->LenAndFontSize >> 12;
        v26.Delta = (unsigned int)v26.pGlyphs->LenAndFontSize >> 12;
      }
      ++v26.pGlyphs;
      if ( v26.pGlyphs->LenAndFontSize & 0xF000
        && v15
        && v26.HighlighterIter.CurAdjStartPos < v26.HighlighterIter.NumGlyphs )
      {
        if ( v15 )
        {
          v26.HighlighterIter.CurAdjStartPos += v15;
          Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(&v26.HighlighterIter);
        }
        v26.Delta = 0;
      }
      Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&v26);
    }
    v22 = v26.pImage.pObject;
    if ( v26.pImage.pObject )
    {
      --v26.pImage.pObject->RefCount;
      if ( !v22->RefCount )
        v22->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v22->vfptr, 1u);
    }
    v23 = v26.pFontHandle.pObject;
    if ( v26.pFontHandle.pObject && !_InterlockedDecrement(&v26.pFontHandle.pObject->RefCount) && v23 )
      v23->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v23->vfptr, 1u);
  }
  return v6;
}

// File Line: 3251
// RVA: 0x982F10
char __fastcall Scaleform::Render::Text::DocView::GetExactCharBoundaries(Scaleform::Render::Text::DocView *this, Scaleform::Render::Rect<float> *pCharRect, unsigned __int64 indexOfChar)
{
  unsigned __int64 v3; // rbp
  Scaleform::Render::Rect<float> *v4; // rsi
  Scaleform::Render::Text::DocView *v5; // rbx
  unsigned __int64 v6; // rax
  char v7; // r13
  Scaleform::Render::Text::LineBuffer::Line *v8; // r14
  unsigned int v9; // er12
  signed __int64 v10; // rax
  unsigned __int64 v11; // rbp
  signed int v12; // er15
  int i; // edi
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v14; // rbx
  int v15; // eax
  unsigned int v16; // eax
  unsigned __int16 v17; // cx
  float *v18; // rdi
  float v19; // xmm6_4
  float v20; // xmm6_4
  unsigned __int16 v21; // cx
  unsigned __int16 v22; // ax
  int v23; // eax
  float v24; // xmm1_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  signed int v27; // eax
  float v28; // xmm3_4
  float v29; // xmm6_4
  bool v30; // zf
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  Scaleform::Render::Text::ImageDesc *v34; // rax
  float v35; // xmm3_4
  float v36; // xmm4_4
  Scaleform::Render::Text::ImageDesc *v37; // rcx
  Scaleform::Render::Text::FontHandle *v38; // rcx
  Scaleform::Render::Text::LineBuffer::GlyphIterator v40; // [rsp+30h] [rbp-F8h]
  Scaleform::Render::Text::LineBuffer::Iterator result; // [rsp+D0h] [rbp-58h]

  v3 = indexOfChar;
  v4 = pCharRect;
  v5 = this;
  v6 = Scaleform::Render::Text::StyledText::GetLength((Scaleform::Render::Text::StyledText *)&this->pDocument.pObject->vfptr);
  if ( !v4 || v3 > v6 )
    return 0;
  if ( v5->RTFlags & 3 )
  {
    Scaleform::Render::Text::DocView::Format(v5);
    v5->RTFlags &= 0xFCu;
  }
  Scaleform::Render::Text::LineBuffer::FindLineByTextPos(&v5->mLineBuffer, &result, v3);
  v7 = 0;
  if ( result.pLineBuffer
    && result.CurrentPos < result.pLineBuffer->Lines.Data.Size
    && (result.CurrentPos & 0x80000000) == 0 )
  {
    v8 = result.pLineBuffer->Lines.Data.Data[result.CurrentPos];
    v9 = -1;
    if ( (v8->MemSize & 0x80000000) == 0 )
    {
      v10 = v8->Data32.TextPos;
    }
    else
    {
      v10 = v8->Data32.TextPos & 0xFFFFFF;
      if ( (_DWORD)v10 == 0xFFFFFF )
        v10 = 0xFFFFFFFFi64;
    }
    v11 = v3 - v10;
    Scaleform::Render::Text::LineBuffer::Line::Begin(v8, &v40);
    v12 = 0;
    for ( i = 0; ; ++i )
    {
      v14 = v40.pGlyphs;
      if ( !v40.pGlyphs || v40.pGlyphs >= v40.pEndGlyphs )
        break;
      if ( i == v11 )
      {
        v17 = v40.pGlyphs->Flags;
        v7 = 1;
        if ( (v17 >> 11) & 1 )
        {
          v34 = v40.pImage.pObject;
          LODWORD(v35) = LODWORD(v40.pImage.pObject->BaseLineX) ^ _xmm[0];
          v4->x1 = v35;
          LODWORD(v36) = LODWORD(v34->BaseLineY) ^ _xmm[0];
          v4->y1 = v36;
          v26 = v35 + v34->ScreenWidth;
          v4->x2 = v26;
          v29 = v36 + v34->ScreenHeight;
          v4->y2 = v29;
          v30 = (v8->MemSize & 0x80000000) == 0;
          v31 = (float)v12 + 40.0;
          v32 = (float)v8->Data32.OffsetY + 40.0;
          v4->x1 = v35 + v31;
          v33 = v32 + v36;
        }
        else
        {
          v18 = (float *)v40.pFontHandle.pObject;
          if ( v40.pFontHandle.pObject )
            v18 = (float *)v40.pFontHandle.pObject->pFont.pObject;
          v19 = (float)(v40.pGlyphs->LenAndFontSize & 0xFFF);
          if ( v17 & 0x10 )
            v19 = v19 * 0.0625;
          v20 = (float)(v19 * 20.0) * 0.0009765625;
          v21 = v40.pGlyphs->Index;
          v22 = v40.pGlyphs->Index;
          if ( v40.pGlyphs->Index >= 0xFFFFu )
            v22 = -1;
          if ( v22 == 0xFFFF )
          {
            v4->x1 = 0.0;
            v23 = v14->Advance;
            if ( (LOBYTE(v14->Flags) >> 6) & 1 )
              v23 = -v23;
            v4->x2 = (float)v23;
          }
          else
          {
            if ( v21 < 0xFFFFu )
              v9 = v21;
            (*(void (__fastcall **)(float *, _QWORD, Scaleform::Render::Rect<float> *))(*(_QWORD *)v18 + 56i64))(
              v18,
              v9,
              v4);
          }
          if ( v14->Flags & 0x100 )
            v4->x2 = v4->x1 + (float)((float)(v4->x2 - v4->x1) * 0.33333334);
          v24 = (float)(v18[5] + v18[4]) * v20;
          v25 = v20 * v4->x1;
          v4->x1 = v25;
          v26 = v20 * v4->x2;
          v4->x2 = v26;
          if ( (v8->MemSize & 0x80000000) == 0 )
            v27 = v8->Data32.BaseLineOffset;
          else
            v27 = v8->Data8.BaseLineOffset;
          v28 = (float)((float)v27 - (float)(v18[4] * v20)) + 40.0;
          v4->y1 = v28;
          v29 = v28 + v24;
          v4->y2 = v28 + v24;
          v30 = (v8->MemSize & 0x80000000) == 0;
          v31 = (float)v12 + 40.0;
          v32 = (float)v8->Data32.OffsetY;
          v4->x1 = v31 + v25;
          v33 = v32 + v28;
        }
        v4->y2 = v32 + v29;
        v4->y1 = v33;
        v4->x2 = v31 + v26;
        break;
      }
      v15 = v40.pGlyphs->Advance;
      if ( (LOBYTE(v40.pGlyphs->Flags) >> 6) & 1 )
        v15 = -v15;
      v12 += v15;
      v16 = v40.Delta;
      if ( !v40.Delta )
      {
        v16 = (unsigned int)v40.pGlyphs->LenAndFontSize >> 12;
        v40.Delta = (unsigned int)v40.pGlyphs->LenAndFontSize >> 12;
      }
      ++v40.pGlyphs;
      if ( v40.pGlyphs->LenAndFontSize & 0xF000
        && v16
        && v40.HighlighterIter.CurAdjStartPos < v40.HighlighterIter.NumGlyphs )
      {
        if ( v16 )
        {
          v40.HighlighterIter.CurAdjStartPos += v16;
          Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(&v40.HighlighterIter);
        }
        v40.Delta = 0;
      }
      Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&v40);
    }
    v37 = v40.pImage.pObject;
    if ( v40.pImage.pObject )
    {
      --v40.pImage.pObject->RefCount;
      if ( !v37->RefCount )
        v37->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v37->vfptr, 1u);
    }
    v38 = v40.pFontHandle.pObject;
    if ( v40.pFontHandle.pObject && !_InterlockedDecrement(&v40.pFontHandle.pObject->RefCount) && v38 )
      v38->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v38->vfptr, 1u);
  }
  return v7;
}

// File Line: 3318
// RVA: 0x984770
unsigned __int64 __fastcall Scaleform::Render::Text::DocView::GetFirstCharInParagraph(Scaleform::Render::Text::DocView *this, unsigned __int64 indexOfChar)
{
  Scaleform::Render::Text::DocView::DocumentText *v2; // rdi
  unsigned __int64 v3; // r11
  unsigned __int64 v4; // r9
  signed __int64 v5; // r8
  unsigned __int64 v6; // rbx
  Scaleform::Render::Text::Paragraph *v7; // rax
  unsigned __int64 v8; // r10
  Scaleform::Render::Text::Paragraph *v9; // rax
  unsigned __int64 v10; // rdx
  unsigned __int64 result; // rax

  v2 = this->pDocument.pObject;
  v3 = 0i64;
  v4 = indexOfChar;
  v5 = v2->Paragraphs.Data.Size;
  while ( v5 > 0 )
  {
    v6 = (v5 >> 1) + v3;
    v7 = v2->Paragraphs.Data.Data[v6].pPara;
    v8 = v7->StartIndex;
    if ( indexOfChar >= v8 && indexOfChar < v8 + v7->Text.Size || (signed int)v8 - (signed int)indexOfChar >= 0 )
    {
      v5 >>= 1;
    }
    else
    {
      v3 = v6 + 1;
      v5 += -1 - (v5 >> 1);
    }
  }
  if ( v3 >= v2->Paragraphs.Data.Size
    || ((v9 = v2->Paragraphs.Data.Data[v3].pPara, v10 = v9->StartIndex, v4 < v10) || v4 >= v10 + v9->Text.Size)
    && (_DWORD)v10 != (_DWORD)v4
    || (v3 & 0x80000000) != 0i64
    || (signed int)v3 >= (signed __int64)SLODWORD(v2->Paragraphs.Data.Size) )
  {
    result = -1i64;
  }
  else
  {
    result = v2->Paragraphs.Data.Data[(signed int)v3].pPara->StartIndex;
  }
  return result;
}

// File Line: 3329
// RVA: 0x980260
__int64 __fastcall Scaleform::Render::Text::DocView::GetBottomVScroll(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView *v1; // rdi
  unsigned __int64 v2; // rbx
  Scaleform::Render::Text::LineBuffer *v3; // rdi
  unsigned int v4; // esi
  int v5; // ecx
  Scaleform::Render::Text::LineBuffer::Line *v6; // rcx
  unsigned int v7; // et1
  Scaleform::Render::Text::LineBuffer::Line *v8; // rdx
  unsigned int v9; // et1
  char v10; // bp
  float v11; // xmm6_4

  v1 = this;
  Scaleform::Render::Text::DocView::ForceReformat(this);
  v2 = v1->mLineBuffer.Geom.FirstVisibleLinePos;
  v3 = &v1->mLineBuffer;
  v4 = 0;
  v5 = 0;
  if ( (_DWORD)v2 && v3 && v2 < v3->Lines.Data.Size && (v2 & 0x80000000) == 0i64 && v3 && v3->Lines.Data.Size > 0 )
  {
    v6 = v3->Lines.Data.Data[v2];
    v7 = v6->MemSize;
    v8 = *v3->Lines.Data.Data;
    v9 = v8->MemSize;
    v5 = v6->Data32.OffsetY - v8->Data32.OffsetY;
  }
  v10 = ((unsigned __int8)v3->Geom.Flags >> 2) & 1;
  LODWORD(v11) = COERCE_UNSIGNED_INT((float)v5) ^ _xmm[0];
  while ( v3
       && (unsigned int)v2 < v3->Lines.Data.Size
       && (v2 & 0x80000000) == 0i64
       && (v10 || Scaleform::Render::Text::LineBuffer::IsLineVisible(v3, v2, v11)) )
  {
    v4 = v2;
    LODWORD(v2) = v2 + 1;
  }
  return v4;
}

// File Line: 3341
// RVA: 0x9AE5A0
char __fastcall Scaleform::Render::Text::DocView::SetBottomVScroll(Scaleform::Render::Text::DocView *this, unsigned int newBottomMostLine)
{
  unsigned int v2; // eax
  Scaleform::Render::Text::DocView *v3; // rsi
  Scaleform::Render::Text::LineBuffer *v4; // r14
  __int64 v5; // r8
  unsigned __int64 v6; // rdi
  Scaleform::Render::Text::LineBuffer::Line **v7; // r15
  Scaleform::Render::Text::LineBuffer::Line *v8; // rax
  unsigned int v9; // er10
  int v10; // ecx
  unsigned int v11; // ebx
  unsigned int v12; // et1
  char v13; // di
  unsigned int v14; // eax
  Scaleform::Render::Text::DocView::DocumentListener *v15; // rcx

  v2 = this->mLineBuffer.Lines.Data.Size;
  v3 = this;
  if ( newBottomMostLine >= v2 )
    newBottomMostLine = v2 - 1;
  v4 = &this->mLineBuffer;
  v5 = newBottomMostLine;
  if ( this == (Scaleform::Render::Text::DocView *)-80i64 )
    return 0;
  v6 = this->mLineBuffer.Lines.Data.Size;
  if ( newBottomMostLine >= v6 || (newBottomMostLine & 0x80000000) != 0 )
    return 0;
  v7 = v4->Lines.Data.Data;
  v8 = v4->Lines.Data.Data[newBottomMostLine];
  if ( (v8->MemSize & 0x80000000) == 0 )
    v9 = v8->Data32.Height;
  else
    v9 = v8->Data8.Height;
  if ( (v8->MemSize & 0x80000000) == 0 )
  {
    LOWORD(v10) = v8->Data32.Leading;
    if ( (signed __int16)v10 > 0 )
    {
      v10 = (signed __int16)v10;
      goto LABEL_15;
    }
  }
  else
  {
    LOBYTE(v10) = v8->Data8.Leading;
    if ( (char)v10 > 0 )
    {
      v10 = (char)v10;
      goto LABEL_15;
    }
  }
  v10 = 0;
LABEL_15:
  v11 = newBottomMostLine;
  do
  {
    if ( newBottomMostLine >= v6 )
      break;
    if ( (newBottomMostLine & 0x80000000) != 0 )
      break;
    v12 = v7[newBottomMostLine]->MemSize;
    if ( (float)v7[newBottomMostLine]->Data32.OffsetY < (float)((float)((float)(signed int)(v8->Data32.OffsetY + v10 + v9)
                                                                      - v3->mLineBuffer.Geom.VisibleRect.y2)
                                                              + v3->mLineBuffer.Geom.VisibleRect.y1) )
      break;
    v11 = v5;
    --newBottomMostLine;
    --v5;
  }
  while ( v5 >= 0 );
  v13 = 0;
  v14 = Scaleform::Render::Text::DocView::GetMaxVScroll(v3);
  if ( v11 > v14 )
    v11 = v14;
  if ( v3->mLineBuffer.Geom.FirstVisibleLinePos != v11 )
  {
    v4->Geom.FirstVisibleLinePos = v11;
    v4->Geom.Flags |= 1u;
    v15 = v3->pDocumentListener.pObject;
    if ( v15 )
      ((void (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::Render::Text::DocView *, _QWORD))v15->vfptr[4].__vecDelDtor)(
        v15,
        v3,
        v11);
    v13 = 1;
  }
  return v13;
}

// File Line: 3368
// RVA: 0x967860
Scaleform::Render::Text::DocView::HighlightDescLoc *__fastcall Scaleform::Render::Text::DocView::CreateHighlighterManager(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView *v1; // rbx
  Scaleform::Render::Text::DocView::HighlightDescLoc *result; // rax
  int v3; // [rsp+58h] [rbp+10h]
  Scaleform::Render::Text::DocView::HighlightDescLoc *v4; // [rsp+60h] [rbp+18h]
  Scaleform::Render::Text::DocView::HighlightDescLoc *v5; // [rsp+68h] [rbp+20h]

  v1 = this;
  if ( this->pHighlight )
    return this->pHighlight;
  v3 = 74;
  result = (Scaleform::Render::Text::DocView::HighlightDescLoc *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Text::DocView *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                                   Scaleform::Memory::pGlobalHeap,
                                                                   this,
                                                                   72i64,
                                                                   &v3,
                                                                   -2i64);
  v4 = result;
  if ( result )
  {
    v5 = result;
    result->HighlightManager.Highlighters.Data.Data = 0i64;
    result->HighlightManager.Highlighters.Data.Size = 0i64;
    result->HighlightManager.Highlighters.Data.Policy.Capacity = 0i64;
    result->HighlightManager.LastId = 0;
    result->HighlightManager.CorrectionPos = 0i64;
    result->HighlightManager.CorrectionLen = 0i64;
    *(_WORD *)&result->HighlightManager.Valid = 0;
    result->HScrollOffset = -1.0;
    result->VScrollOffset = -1.0;
    result->FormatCounter = 0;
  }
  else
  {
    result = 0i64;
  }
  v1->pHighlight = result;
  return result;
}

// File Line: 3389
// RVA: 0x9BE550
void __fastcall Scaleform::Render::Text::DocView::UpdateHighlight(Scaleform::Render::Text::DocView *this, Scaleform::Render::Text::HighlightDesc *desc)
{
  Scaleform::Render::Text::DocView::HighlightDescLoc *v2; // rax

  v2 = this->pHighlight;
  if ( v2 )
  {
    if ( !(this->RTFlags & 0x40) )
      *(_WORD *)&v2->HighlightManager.Valid = 0;
  }
}

// File Line: 3397
// RVA: 0x98B550
Scaleform::Render::Text::HighlightDesc *__fastcall Scaleform::Render::Text::DocView::GetSelectionHighlighterDesc(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView::HighlightDescLoc *v1; // rbx
  Scaleform::Render::Text::HighlightDesc *result; // rax
  Scaleform::Render::Text::HighlightDesc desc; // [rsp+20h] [rbp-48h]

  v1 = this->pHighlight;
  if ( !v1 || this->RTFlags & 0x40 )
    return 0i64;
  result = Scaleform::Render::Text::Highlighter::GetHighlighterPtr(&this->pHighlight->HighlightManager, 0x7FFFFFFFu);
  if ( !result )
  {
    desc.Offset = -1i64;
    desc.AdjStartPos = 0i64;
    desc.GlyphNum = 0i64;
    desc.Info.UnderlineColor.Raw = 0;
    desc.StartPos = 0i64;
    desc.Length = 0i64;
    desc.Id = 0x7FFFFFFF;
    *(_QWORD *)&desc.Info.BackgroundColor.Channels.Blue = -16777216i64;
    desc.Info.Flags = 24;
    result = Scaleform::Render::Text::Highlighter::CreateHighlighter(&v1->HighlightManager, &desc);
  }
  return result;
}

// File Line: 3416
// RVA: 0x98B490
Scaleform::Render::Text::HighlightDesc *__fastcall Scaleform::Render::Text::DocView::GetSelectionHighlighterDesc(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView *v1; // rbx
  __int64 v3; // rax
  int v4; // [rsp+58h] [rbp+10h]
  __int64 v5; // [rsp+60h] [rbp+18h]
  __int64 v6; // [rsp+68h] [rbp+20h]

  v1 = this;
  if ( this->RTFlags & 0x40 )
    return 0i64;
  if ( !this->pHighlight )
  {
    v4 = 74;
    v3 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Text::DocView *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
           Scaleform::Memory::pGlobalHeap,
           this,
           72i64,
           &v4,
           -2i64);
    v5 = v3;
    if ( v3 )
    {
      v6 = v3;
      *(_QWORD *)v3 = 0i64;
      *(_QWORD *)(v3 + 8) = 0i64;
      *(_QWORD *)(v3 + 16) = 0i64;
      *(_DWORD *)(v3 + 24) = 0;
      *(_QWORD *)(v3 + 32) = 0i64;
      *(_QWORD *)(v3 + 40) = 0i64;
      *(_WORD *)(v3 + 48) = 0;
      *(_DWORD *)(v3 + 56) = -1082130432;
      *(_DWORD *)(v3 + 60) = -1082130432;
      *(_WORD *)(v3 + 64) = 0;
    }
    else
    {
      v3 = 0i64;
    }
    v1->pHighlight = (Scaleform::Render::Text::DocView::HighlightDescLoc *)v3;
  }
  return Scaleform::Render::Text::DocView::GetSelectionHighlighterDesc(v1);
}

// File Line: 3425
// RVA: 0x9B3AE0
void __fastcall Scaleform::Render::Text::DocView::SetSelection(Scaleform::Render::Text::DocView *this, unsigned __int64 startPos, unsigned __int64 endPos, bool highlightSelection)
{
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // rsi
  Scaleform::Render::Text::DocView *v6; // rbx
  __int64 v7; // rax
  unsigned __int64 v8; // rax
  Scaleform::Render::Text::HighlightDesc *v9; // rax
  unsigned __int64 v10; // rdi
  int v11; // [rsp+78h] [rbp+20h]

  v4 = endPos;
  v5 = startPos;
  v6 = this;
  this->BeginSelection = startPos;
  this->EndSelection = endPos;
  if ( highlightSelection )
  {
    if ( !this->pHighlight )
    {
      v11 = 74;
      v7 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Text::DocView *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
             Scaleform::Memory::pGlobalHeap,
             this,
             72i64,
             &v11,
             -2i64);
      if ( v7 )
      {
        *(_QWORD *)v7 = 0i64;
        *(_QWORD *)(v7 + 8) = 0i64;
        *(_QWORD *)(v7 + 16) = 0i64;
        *(_DWORD *)(v7 + 24) = 0;
        *(_QWORD *)(v7 + 32) = 0i64;
        *(_QWORD *)(v7 + 40) = 0i64;
        *(_WORD *)(v7 + 48) = 0;
        *(_DWORD *)(v7 + 56) = -1082130432;
        *(_DWORD *)(v7 + 60) = -1082130432;
        *(_WORD *)(v7 + 64) = 0;
      }
      else
      {
        v7 = 0i64;
      }
      v6->pHighlight = (Scaleform::Render::Text::DocView::HighlightDescLoc *)v7;
    }
    if ( v4 < v5 )
    {
      v8 = v4;
      v4 = v5;
      v5 = v8;
    }
    if ( !(v6->RTFlags & 0x40) )
    {
      v9 = Scaleform::Render::Text::DocView::GetSelectionHighlighterDesc(v6);
      v10 = v4 - v5;
      if ( v9->StartPos != v5 || v9->Length != v10 )
      {
        v9->StartPos = v5;
        v9->Length = v10;
        *(_WORD *)&v6->pHighlight->HighlightManager.Valid = 0;
      }
    }
  }
}

// File Line: 3474
// RVA: 0x9B3BD0
void __fastcall Scaleform::Render::Text::DocView::SetSelectionBackgroundColor(Scaleform::Render::Text::DocView *this, unsigned int color)
{
  unsigned int v2; // edi
  Scaleform::Render::Text::DocView *v3; // rbx
  Scaleform::Render::Text::HighlightDesc *v4; // rax
  char v5; // r8
  unsigned int v6; // [rsp+30h] [rbp+8h]

  v2 = color;
  v3 = this;
  if ( !(this->RTFlags & 0x40) )
  {
    v4 = Scaleform::Render::Text::DocView::GetSelectionHighlighterDesc(this);
    v5 = v4->Info.Flags;
    if ( v5 & 8 )
    {
      v6 = v4->Info.BackgroundColor.Raw;
    }
    else
    {
      *(_WORD *)((char *)&v6 + 1) = 0;
      LOBYTE(v6) = 0;
      HIBYTE(v6) = 0;
    }
    if ( v6 != v2 )
    {
      v4->Info.Flags = v5 | 8;
      v4->Info.BackgroundColor.Raw = v2;
      *(_WORD *)&v3->pHighlight->HighlightManager.Valid = 0;
    }
  }
}

// File Line: 3487
// RVA: 0x9B3C40
void __fastcall Scaleform::Render::Text::DocView::SetSelectionTextColor(Scaleform::Render::Text::DocView *this, unsigned int color)
{
  unsigned int v2; // edi
  Scaleform::Render::Text::DocView *v3; // rbx
  Scaleform::Render::Text::HighlightDesc *v4; // rax
  char v5; // r8
  unsigned int v6; // [rsp+30h] [rbp+8h]

  v2 = color;
  v3 = this;
  if ( !(this->RTFlags & 0x40) )
  {
    v4 = Scaleform::Render::Text::DocView::GetSelectionHighlighterDesc(this);
    v5 = v4->Info.Flags;
    if ( v5 & 0x10 )
    {
      v6 = v4->Info.TextColor.Raw;
    }
    else
    {
      *(_WORD *)((char *)&v6 + 1) = 0;
      LOBYTE(v6) = 0;
      HIBYTE(v6) = 0;
    }
    if ( v6 != v2 )
    {
      v4->Info.Flags = v5 | 0x10;
      v4->Info.TextColor.Raw = v2;
      *(_WORD *)&v3->pHighlight->HighlightManager.Valid = 0;
    }
  }
}

// File Line: 3516
// RVA: 0x9AEFB0
void __fastcall Scaleform::Render::Text::DocView::SetDefaultTextAndParaFormat(Scaleform::Render::Text::DocView *this, unsigned __int64 cursorPos)
{
  unsigned __int64 v2; // rbx
  Scaleform::Render::Text::DocView *v3; // rsi
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // r9
  Scaleform::Render::Text::DocView::DocumentText *v6; // rbx
  Scaleform::Render::Text::ParagraphFormat *v7; // rdi
  Scaleform::Render::Text::ParagraphFormat *v8; // rcx
  Scaleform::Render::Text::TextFormat *v9; // rdx
  Scaleform::Render::Text::ParagraphFormat *ppdestParaFmt; // [rsp+40h] [rbp+18h]
  Scaleform::Render::Text::TextFormat *ppdestTextFmt; // [rsp+48h] [rbp+20h]

  v2 = cursorPos;
  v3 = this;
  ppdestParaFmt = 0i64;
  ppdestTextFmt = 0i64;
  v4 = Scaleform::Render::Text::DocView::GetFirstCharInParagraph(this, cursorPos);
  if ( v4 != -1i64 )
  {
    v5 = v2 - 1;
    if ( v4 == v2 )
      v5 = v2;
    if ( (unsigned __int8)Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
                            (Scaleform::Render::Text::StyledText *)&v3->pDocument.pObject->vfptr,
                            &ppdestTextFmt,
                            &ppdestParaFmt,
                            v5) )
    {
      v6 = v3->pDocument.pObject;
      v7 = ppdestParaFmt;
      if ( ppdestParaFmt )
        ++ppdestParaFmt->RefCount;
      v8 = v6->pDefaultParagraphFormat.pObject;
      if ( v8 )
        Scaleform::Render::Text::ParagraphFormat::Release(v8);
      v9 = ppdestTextFmt;
      v6->pDefaultParagraphFormat.pObject = v7;
      Scaleform::Render::Text::StyledText::SetDefaultTextFormat(
        (Scaleform::Render::Text::StyledText *)&v3->pDocument.pObject->vfptr,
        v9);
    }
  }
}

