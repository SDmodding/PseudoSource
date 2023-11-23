// File Line: 46
// RVA: 0x93B120
void __fastcall Scaleform::Render::Text::DocView::DocView(
        Scaleform::Render::Text::DocView *this,
        Scaleform::Render::Text::Allocator *pallocator,
        Scaleform::Render::Text::FontManagerBase *pfontMgr,
        Scaleform::Log *plog)
{
  Scaleform::Render::Text::StyledText *v7; // rax
  Scaleform::Render::Text::DocView::DocumentText *v8; // rdi
  Scaleform::Render::Text::DocView::DocumentText *pObject; // rcx
  Scaleform::Render::Text::LineBuffer *v11; // [rsp+28h] [rbp-40h]
  Scaleform::Render::Text::LineBuffer *v12; // [rsp+30h] [rbp-38h]
  int v13; // [rsp+80h] [rbp+18h] BYREF
  Scaleform::Render::Text::LineBuffer *p_mLineBuffer; // [rsp+88h] [rbp+20h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,74>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Text::DocView,74>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::DocView::`vftable;
  this->pDocument.pObject = 0i64;
  if ( pfontMgr )
    _InterlockedExchangeAdd(&pfontMgr->RefCount, 1u);
  this->pFontManager.pObject = pfontMgr;
  this->pDocumentListener.pObject = 0i64;
  this->pHighlight = 0i64;
  p_mLineBuffer = &this->mLineBuffer;
  v11 = &this->mLineBuffer;
  v12 = &this->mLineBuffer;
  this->mLineBuffer.Lines.Data.Data = 0i64;
  this->mLineBuffer.Lines.Data.Size = 0i64;
  this->mLineBuffer.Lines.Data.Policy.Capacity = 0i64;
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
  if ( plog )
    _InterlockedExchangeAdd(&plog->RefCount, 1u);
  this->pLog.pObject = plog;
  *(_QWORD *)&this->BorderColor = 0i64;
  v13 = 74;
  v7 = (Scaleform::Render::Text::StyledText *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Text::DocView *, __int64, int *, __int64, Scaleform::Render::Text::LineBuffer *, Scaleform::Render::Text::LineBuffer *))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                80i64,
                                                &v13,
                                                -2i64,
                                                v11,
                                                v12);
  v8 = (Scaleform::Render::Text::DocView::DocumentText *)v7;
  p_mLineBuffer = (Scaleform::Render::Text::LineBuffer *)v7;
  if ( v7 )
  {
    Scaleform::Render::Text::StyledText::StyledText(v7, pallocator);
    v8->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Text::DocView::DocumentText::`vftable;
    v8->pDocument = this;
  }
  else
  {
    v8 = 0i64;
  }
  pObject = this->pDocument.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
  }
  this->pDocument.pObject = v8;
  *(_QWORD *)&this->FormatCounter = 1310721i64;
  this->EndSelection = -1i64;
  this->BeginSelection = -1i64;
  this->AlignProps &= 0xC0u;
  *(_WORD *)&this->FlagsEx = 0;
  this->Flags = 0;
  *(_QWORD *)&this->ViewRect.x1 = 0i64;
  *(_QWORD *)&this->ViewRect.x2 = 0i64;
  this->pImageSubstitutor = 0i64;
  this->RTFlags &= ~4u;
  this->MaxLength = 0;
  this->Flags |= 0x80u;
  Scaleform::Render::Text::DocView::SetDefaultShadow(this);
  *(_QWORD *)&this->TextWidth = 0i64;
}

// File Line: 66
// RVA: 0x949A00
void __fastcall Scaleform::Render::Text::DocView::~DocView(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView::ImageSubstitutor *pImageSubstitutor; // rbx
  Scaleform::Render::Text::DocView::HighlightDescLoc *pHighlight; // rbx
  Scaleform::Log *pObject; // rcx
  Scaleform::Render::GradientData *v5; // rcx
  Scaleform::Render::Text::EditorKitBase *v6; // rcx
  Scaleform::Render::Text::DocView::DocumentListener *v7; // rcx
  bool v8; // zf
  Scaleform::Render::Text::FontManagerBase *v9; // rcx
  Scaleform::Render::Text::DocView::DocumentText *v10; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::DocView::`vftable;
  Scaleform::Render::Text::DocView::Close(this);
  pImageSubstitutor = this->pImageSubstitutor;
  if ( pImageSubstitutor )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy>(&pImageSubstitutor->Elements.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pImageSubstitutor);
  }
  this->pImageSubstitutor = 0i64;
  pHighlight = this->pHighlight;
  if ( pHighlight )
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(
      Scaleform::Memory::pGlobalHeap,
      pHighlight->HighlightManager.Highlighters.Data.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pHighlight);
  }
  pObject = this->pLog.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  v5 = this->Filter.ShadowParams.Gradient.pObject;
  if ( v5 && !_InterlockedDecrement(&v5->RefCount) )
    v5->vfptr->__vecDelDtor(v5, 1u);
  this->Filter.vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  v6 = this->pEditorKit.pObject;
  if ( v6 && !_InterlockedDecrement(&v6->RefCount) )
    v6->vfptr->__vecDelDtor(v6, 1u);
  this->mLineBuffer.Geom.Flags |= 1u;
  Scaleform::Render::Text::LineBuffer::RemoveLines(&this->mLineBuffer, 0, this->mLineBuffer.Lines.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->mLineBuffer.Lines.Data.Data);
  v7 = this->pDocumentListener.pObject;
  if ( v7 )
  {
    v8 = v7->RefCount-- == 1;
    if ( v8 )
      v7->vfptr->__vecDelDtor(v7, 1u);
  }
  v9 = this->pFontManager.pObject;
  if ( v9 && !_InterlockedDecrement(&v9->RefCount) )
    v9->vfptr->__vecDelDtor(v9, 1u);
  v10 = this->pDocument.pObject;
  if ( v10 )
  {
    v8 = v10->RefCount-- == 1;
    if ( v8 )
      v10->vfptr->__vecDelDtor(v10, 1u);
  }
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 117
// RVA: 0x954430
void __fastcall Scaleform::Render::Text::DocView::ImageSubstitutor::AddImageDesc(
        Scaleform::Render::Text::DocView::ImageSubstitutor *this,
        Scaleform::Render::Text::DocView::ImageSubstitutor::Element *elem)
{
  __int64 Size; // r10
  unsigned __int64 v5; // rsi
  __int64 SubStringLen; // r9
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element *v7; // rcx
  __int64 v8; // rdx
  int v9; // edi
  char *v10; // r11
  int v11; // eax
  int v12; // r8d
  int v13; // eax

  if ( !Scaleform::Render::Text::DocView::ImageSubstitutor::FindImageDesc(
          this,
          elem->SubString,
          (unsigned __int8)elem->SubStringLen,
          0i64) )
  {
    Size = this->Elements.Data.Size;
    v5 = 0i64;
    while ( Size > 0 )
    {
      SubStringLen = (unsigned __int8)elem->SubStringLen;
      v7 = &this->Elements.Data.Data[(Size >> 1) + v5];
      v8 = (unsigned __int8)v7->SubStringLen;
      if ( elem->SubStringLen )
      {
        v9 = (unsigned __int8)v7->SubStringLen;
        v10 = (char *)((char *)elem - (char *)v7);
        do
        {
          v11 = *(unsigned __int16 *)((char *)v7->SubString + (_QWORD)v10);
          v12 = v7->SubString[0];
          v7 = (Scaleform::Render::Text::DocView::ImageSubstitutor::Element *)((char *)v7 + 2);
          if ( !--SubStringLen || !v11 )
            break;
          if ( v11 != v12 )
            goto LABEL_13;
          --v8;
        }
        while ( v8 );
        if ( v11 == v12 && v8 && SubStringLen )
        {
          v13 = (unsigned __int8)elem->SubStringLen - v9;
          goto LABEL_15;
        }
LABEL_13:
        v13 = v11 - v12;
      }
      else
      {
        v13 = -(int)v8;
      }
LABEL_15:
      if ( v13 <= 0 )
      {
        Size >>= 1;
      }
      else
      {
        v5 += (Size >> 1) + 1;
        Size += -1 - (Size >> 1);
      }
    }
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
      &this->Elements,
      v5,
      elem);
  }
}

// File Line: 131
// RVA: 0x97A200
Scaleform::Render::Text::ImageDesc *__fastcall Scaleform::Render::Text::DocView::ImageSubstitutor::FindImageDesc(
        Scaleform::Render::Text::DocView::ImageSubstitutor *this,
        const wchar_t *pstr,
        unsigned __int64 maxlen,
        unsigned __int64 *ptextLen)
{
  __int64 Size; // r10
  unsigned __int64 v5; // r14
  unsigned __int64 *v7; // rbx
  Scaleform::Render::Text::DocView::ImageSubstitutor *v9; // r8
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element *Data; // r12
  unsigned __int64 v11; // r9
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element *v12; // rcx
  __int64 SubStringLen; // r8
  int v14; // esi
  char *v15; // r11
  int v16; // eax
  int v17; // edx
  int v18; // eax
  __int64 v19; // r14
  unsigned __int64 v20; // r9
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element *v21; // r10
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element *v22; // rcx
  __int64 v23; // rdx
  char *v24; // r15
  int v25; // eax
  int v26; // r8d
  int v27; // edi
  int v28; // eax

  Size = this->Elements.Data.Size;
  v5 = 0i64;
  v7 = ptextLen;
  v9 = this;
  if ( Size > 0 )
  {
    Data = this->Elements.Data.Data;
    do
    {
      v11 = maxlen;
      v12 = &Data[(Size >> 1) + v5];
      SubStringLen = (unsigned __int8)v12->SubStringLen;
      if ( maxlen )
      {
        v14 = (unsigned __int8)v12->SubStringLen;
        v15 = (char *)((char *)pstr - (char *)v12);
        do
        {
          v16 = *(unsigned __int16 *)((char *)v12->SubString + (_QWORD)v15);
          v17 = v12->SubString[0];
          v12 = (Scaleform::Render::Text::DocView::ImageSubstitutor::Element *)((char *)v12 + 2);
          if ( !--v11 || !v16 )
            break;
          if ( v16 != v17 )
            goto LABEL_12;
          --SubStringLen;
        }
        while ( SubStringLen );
        if ( v16 == v17 && SubStringLen )
        {
          v18 = maxlen - v14;
          goto LABEL_14;
        }
LABEL_12:
        v18 = v16 - v17;
      }
      else
      {
        v18 = -(int)SubStringLen;
      }
LABEL_14:
      if ( v18 <= 0 )
      {
        Size >>= 1;
      }
      else
      {
        v5 += (Size >> 1) + 1;
        Size += -1 - (Size >> 1);
      }
    }
    while ( Size > 0 );
    v9 = this;
    v7 = ptextLen;
  }
  if ( v5 >= v9->Elements.Data.Size )
    return 0i64;
  v19 = v5;
  v20 = maxlen;
  v21 = &v9->Elements.Data.Data[v19];
  v22 = v21;
  v23 = (unsigned __int8)v21->SubStringLen;
  if ( maxlen )
  {
    v24 = (char *)((char *)pstr - (char *)v21);
    do
    {
      v25 = *(unsigned __int16 *)((char *)v22->SubString + (_QWORD)v24);
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
      v9 = this;
      v27 = maxlen - (unsigned __int8)v21->SubStringLen;
      goto LABEL_31;
    }
LABEL_29:
    v28 = v25 - v26;
    v9 = this;
    v27 = v28;
  }
  else
  {
    v27 = -(int)v23;
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
void __fastcall Scaleform::Render::Text::DocView::ImageSubstitutor::RemoveImageDesc(
        Scaleform::Render::Text::DocView::ImageSubstitutor *this,
        Scaleform::Render::Text::ImageDesc *pimgDesc)
{
  unsigned __int64 v4; // rdi
  __int64 v5; // rsi
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element *v6; // rcx
  Scaleform::Render::Text::ImageDesc *pObject; // rcx

  v4 = 0i64;
  if ( this->Elements.Data.Size )
  {
    v5 = 0i64;
    do
    {
      v6 = &this->Elements.Data.Data[v5];
      if ( v6->pImageDesc.pObject == pimgDesc )
      {
        if ( this->Elements.Data.Size == 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &this->Elements.Data,
            this,
            0i64);
        }
        else
        {
          pObject = v6->pImageDesc.pObject;
          if ( pObject )
          {
            if ( pObject->RefCount-- == 1 )
              pObject->vfptr->__vecDelDtor(pObject, 1u);
          }
          memmove(
            &this->Elements.Data.Data[v5],
            &this->Elements.Data.Data[v5 + 1],
            56 * (this->Elements.Data.Size - v4 - 1));
          --this->Elements.Data.Size;
        }
      }
      else
      {
        ++v4;
        ++v5;
      }
    }
    while ( v4 < this->Elements.Data.Size );
  }
}

// File Line: 154
// RVA: 0x9B4160
void __fastcall Scaleform::Render::Text::DocView::SetText(
        Scaleform::Render::Text::DocView *this,
        char *putf8String,
        unsigned __int64 stringSize)
{
  Scaleform::Render::Text::DocView::DocumentText *pObject; // rbx

  pObject = this->pDocument.pObject;
  Scaleform::Render::Text::StyledText::Clear(pObject);
  Scaleform::Render::Text::StyledText::AppendString(
    pObject,
    putf8String,
    stringSize,
    NLP_ReplaceCRLF,
    pObject->pDefaultTextFormat.pObject,
    pObject->pDefaultParagraphFormat.pObject);
  this->vfptr[1].__vecDelDtor(this, 262u);
}

// File Line: 160
// RVA: 0x9B41E0
void __fastcall Scaleform::Render::Text::DocView::SetText(
        Scaleform::Render::Text::DocView *this,
        const wchar_t *pstring,
        unsigned __int64 length)
{
  Scaleform::Render::Text::DocView::DocumentText *pObject; // rbx

  pObject = this->pDocument.pObject;
  Scaleform::Render::Text::StyledText::Clear(pObject);
  Scaleform::Render::Text::StyledText::AppendString(
    pObject,
    pstring,
    length,
    NLP_ReplaceCRLF,
    pObject->pDefaultTextFormat.pObject,
    pObject->pDefaultParagraphFormat.pObject);
  this->vfptr[1].__vecDelDtor(this, 262u);
}

// File Line: 166
// RVA: 0x9B43C0
void __fastcall Scaleform::Render::Text::DocView::SetTextFormat(
        Scaleform::Render::Text::DocView *this,
        Scaleform::Render::Text::TextFormat *fmt,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  this->RTFlags &= ~0x10u;
  Scaleform::Render::Text::StyledText::SetTextFormat(this->pDocument.pObject, fmt, startPos, endPos);
  this->vfptr[1].__vecDelDtor(this, 1u);
}

// File Line: 173
// RVA: 0x9B2540
void __fastcall Scaleform::Render::Text::DocView::SetParagraphFormat(
        Scaleform::Render::Text::DocView *this,
        Scaleform::Render::Text::ParagraphFormat *fmt,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  Scaleform::Render::Text::StyledText::SetParagraphFormat(this->pDocument.pObject, fmt, startPos, endPos);
  this->vfptr[1].__vecDelDtor(this, 1u);
}

// File Line: 179
// RVA: 0x99CC10
void __fastcall Scaleform::Render::Text::DocView::DocumentText::OnParagraphRemoving(
        Scaleform::Render::Text::DocView::DocumentText *this,
        Scaleform::Render::Text::Paragraph *para)
{
  this->pDocument->vfptr[2].__vecDelDtor(this->pDocument, (unsigned int)para);
}

// File Line: 190
// RVA: 0x99CD50
void __fastcall Scaleform::Render::Text::DocView::DocumentText::OnTextInserting(
        Scaleform::Render::Text::DocView::DocumentText *this,
        unsigned __int64 startPos,
        unsigned __int64 length)
{
  ((void (__fastcall *)(Scaleform::Render::Text::DocView *, __int64, unsigned __int64))this->pDocument->vfptr[1].__vecDelDtor)(
    this->pDocument,
    2i64,
    length);
}

// File Line: 202
// RVA: 0x96F510
unsigned __int64 __fastcall Scaleform::Render::Text::DocView::EditCommand(
        Scaleform::Render::Text::DocView *this,
        Scaleform::Render::Text::DocView::CommandType cmdId,
        const wchar_t *command)
{
  unsigned __int64 newLinePolicy; // rsi
  unsigned __int64 inserted; // rbx
  unsigned __int64 MaxLength; // rsi
  unsigned __int64 v8; // rbx
  Scaleform::Render::Text::DocView::DocumentText *pObject; // r13
  unsigned __int64 Length; // rax
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
  Scaleform::Render::Text::StyledText::NewLinePolicy v21; // r9d
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
  Scaleform::Render::Text::StyledText::NewLinePolicy v32; // r10d
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
  Scaleform::Render::Text::Paragraph *pPara; // r13
  Scaleform::Render::Text::ParagraphFormat *v45; // rcx
  signed __int16 PresentMask; // dx
  unsigned int *pTabStops; // r14
  Scaleform::MemoryHeapVtbl *vfptr; // rax
  unsigned int v49; // ebx
  Scaleform::Render::Text::Allocator *Allocator; // rax
  __int16 Indent; // r8
  unsigned int *v52; // r14
  Scaleform::MemoryHeapVtbl *v53; // rax
  unsigned int v54; // ebx
  Scaleform::Render::Text::Allocator *v55; // rax
  unsigned __int64 v56; // rdx
  unsigned __int64 v57; // r8
  unsigned __int64 v58; // r8
  unsigned __int64 v59; // rbx
  unsigned __int64 v60; // r14
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator result; // [rsp+48h] [rbp-38h] BYREF
  Scaleform::Render::Text::ParagraphFormat fmt; // [rsp+58h] [rbp-28h] BYREF
  unsigned __int64 pindexInParagraph; // [rsp+D8h] [rbp+58h] BYREF

  newLinePolicy = 0i64;
  inserted = 0i64;
  switch ( cmdId )
  {
    case Cmd_InsertChar:
      MaxLength = this->MaxLength;
      if ( !(_DWORD)MaxLength
        || Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject) + 1 <= MaxLength )
      {
        inserted = Scaleform::Render::Text::StyledText::InsertString(
                     this->pDocument.pObject,
                     command + 4,
                     *(_QWORD *)command,
                     1ui64,
                     NLP_ReplaceCRLF,
                     this->pDocument.pObject->pDefaultTextFormat.pObject,
                     this->pDocument.pObject->pDefaultParagraphFormat.pObject);
        this->vfptr[1].__vecDelDtor(this, 2u);
      }
      return inserted;
    case Cmd_InsertPlainText:
      v8 = *((_QWORD *)command + 2);
      pObject = this->pDocument.pObject;
      Length = Scaleform::Render::Text::StyledText::GetLength(pObject);
      v11 = this->MaxLength;
      if ( v11 && Length + v8 > v11 )
        v8 = v11 - Length;
      if ( (this->Flags & 4) == 0 )
        LODWORD(newLinePolicy) = 2;
      inserted = Scaleform::Render::Text::StyledText::InsertString(
                   pObject,
                   *((const wchar_t **)command + 1),
                   *(_QWORD *)command,
                   v8,
                   (Scaleform::Render::Text::StyledText::NewLinePolicy)newLinePolicy,
                   pObject->pDefaultTextFormat.pObject,
                   pObject->pDefaultParagraphFormat.pObject);
      goto LABEL_91;
    case Cmd_InsertStyledText:
      v12 = -1i64;
      v13 = this->MaxLength;
      if ( (_DWORD)v13 )
      {
        v14 = Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject);
        if ( v14
           + Scaleform::Render::Text::StyledText::GetLength(*((Scaleform::Render::Text::StyledText **)command + 1)) > v13 )
          v12 = (unsigned int)v13 - v14;
      }
      inserted = Scaleform::Render::Text::StyledText::InsertStyledText(
                   this->pDocument.pObject,
                   *((Scaleform::Render::Text::StyledText **)command + 1),
                   *(_QWORD *)command,
                   v12);
      goto LABEL_91;
    case Cmd_DeleteChar:
      v56 = *(_QWORD *)command;
      v57 = *(_QWORD *)command + 1i64;
      if ( v57 < v56 )
        v58 = 0i64;
      else
        v58 = v57 - v56;
      Scaleform::Render::Text::StyledText::Remove(this->pDocument.pObject, v56, v58);
      inserted = 1i64;
      goto LABEL_91;
    case Cmd_DeleteText:
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
      Scaleform::Render::Text::StyledText::Remove(this->pDocument.pObject, v60, newLinePolicy);
      inserted = v59 - v60;
      goto LABEL_91;
    case Cmd_ReplaceTextByChar:
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
        v18 = Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject);
        v19 = v18;
        if ( v15 < v18 )
          v19 = v15;
        v20 = v18;
        if ( v16 < v18 )
          v20 = v16;
        if ( v18 + v20 - v19 + 1 > v17 )
          return inserted;
      }
      v21 = NLP_CompressCRLF;
      if ( (this->Flags & 4) == 0 )
        v21 = NLP_IgnoreCRLF;
      inserted = Scaleform::Render::Text::StyledText::InsertString(
                   this->pDocument.pObject,
                   command + 8,
                   v16,
                   1ui64,
                   v21,
                   this->pDocument.pObject->pDefaultTextFormat.pObject,
                   this->pDocument.pObject->pDefaultParagraphFormat.pObject);
      v22 = v16 + 1;
      if ( v15 + 1 < v16 + 1 )
LABEL_28:
        v23 = 0i64;
      else
        v23 = v15 - v16;
      goto LABEL_29;
    case Cmd_ReplaceTextByPlainText:
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
        v28 = Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject);
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
      v32 = NLP_CompressCRLF;
      if ( (this->Flags & 4) == 0 )
        v32 = NLP_IgnoreCRLF;
      inserted = Scaleform::Render::Text::StyledText::InsertString(
                   this->pDocument.pObject,
                   *((const wchar_t **)command + 2),
                   v25,
                   v26,
                   v32,
                   this->pDocument.pObject->pDefaultTextFormat.pObject,
                   this->pDocument.pObject->pDefaultParagraphFormat.pObject);
      v22 = inserted + v25;
      if ( v24 + inserted < inserted + v25 )
        goto LABEL_28;
      v23 = v24 - v25;
LABEL_29:
      Scaleform::Render::Text::StyledText::Remove(this->pDocument.pObject, v22, v23);
      goto LABEL_91;
    case Cmd_ReplaceTextByStyledText:
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
        v36 = Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject);
        v37 = v36;
        if ( v33 < v36 )
          v37 = v33;
        v38 = v36;
        if ( v34 < v36 )
          v38 = v34;
        v39 = v36 + v38 - v37;
        v40 = Scaleform::Render::Text::StyledText::GetLength(*((Scaleform::Render::Text::StyledText **)command + 2));
        v41 = this->MaxLength;
        if ( v39 + v40 > v41 )
          v35 = (unsigned int)v41 - v39;
      }
      inserted = Scaleform::Render::Text::StyledText::InsertStyledText(
                   this->pDocument.pObject,
                   *((Scaleform::Render::Text::StyledText **)command + 2),
                   v34,
                   v35);
      if ( v33 + inserted < inserted + v34 )
        v42 = 0i64;
      else
        v42 = v33 - v34;
      Scaleform::Render::Text::StyledText::Remove(this->pDocument.pObject, inserted + v34, v42);
      goto LABEL_91;
    case Cmd_BackspaceChar:
      inserted = 1i64;
      v43 = 0;
      pindexInParagraph = 0i64;
      Scaleform::Render::Text::StyledText::GetParagraphByIndex(
        this->pDocument.pObject,
        &result,
        *(_QWORD *)command,
        &pindexInParagraph);
      if ( !result.pArray )
        goto LABEL_77;
      if ( result.CurIndex < 0 )
        goto LABEL_77;
      if ( result.CurIndex >= SLODWORD(result.pArray->Data.Size) )
        goto LABEL_77;
      if ( pindexInParagraph )
        goto LABEL_77;
      pPara = result.pArray->Data.Data[result.CurIndex].pPara;
      v45 = pPara->pFormat.pObject;
      if ( !v45 )
        goto LABEL_77;
      PresentMask = v45->PresentMask;
      if ( (PresentMask & 0x80u) != 0 && PresentMask < 0 )
      {
        fmt.pAllocator = 0i64;
        fmt.RefCount = 1;
        fmt.pTabStops = 0i64;
        fmt.BlockIndent = v45->BlockIndent;
        fmt.Indent = v45->Indent;
        fmt.Leading = v45->Leading;
        fmt.LeftMargin = v45->LeftMargin;
        fmt.RightMargin = v45->RightMargin;
        fmt.PresentMask = PresentMask;
        pTabStops = v45->pTabStops;
        vfptr = Scaleform::Memory::pGlobalHeap->vfptr;
        if ( pTabStops )
        {
          v49 = *pTabStops;
          vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
          fmt.pTabStops = 0i64;
          fmt.pTabStops = (unsigned int *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                            Scaleform::Memory::pGlobalHeap,
                                            4i64 * (v49 + 1),
                                            0i64);
          *fmt.pTabStops = v49;
          memmove(fmt.pTabStops + 1, pTabStops + 1, 4i64 * v49);
        }
        else
        {
          vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
          fmt.pTabStops = 0i64;
        }
        fmt.PresentMask &= ~0x8000u;
        fmt.PresentMask |= 0x80u;
        Allocator = Scaleform::Render::Text::StyledText::GetAllocator(this->pDocument.pObject);
        Scaleform::Render::Text::Paragraph::SetFormat(pPara, Allocator, &fmt);
        v43 = 1;
LABEL_69:
        if ( fmt.pAllocator )
        {
          pindexInParagraph = (unsigned __int64)&fmt;
          Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
            &fmt.pAllocator->ParagraphFormatStorage,
            (Scaleform::Render::Text::ParagraphFormat **)&pindexInParagraph);
        }
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, fmt.pTabStops);
        fmt.pTabStops = 0i64;
        goto LABEL_79;
      }
      Indent = v45->Indent;
      if ( *(_DWORD *)&v45->BlockIndent )
      {
        fmt.pAllocator = 0i64;
        fmt.RefCount = 1;
        fmt.pTabStops = 0i64;
        fmt.BlockIndent = v45->BlockIndent;
        fmt.Indent = Indent;
        fmt.Leading = v45->Leading;
        fmt.LeftMargin = v45->LeftMargin;
        fmt.RightMargin = v45->RightMargin;
        fmt.PresentMask = PresentMask;
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
        v55 = Scaleform::Render::Text::StyledText::GetAllocator(this->pDocument.pObject);
        Scaleform::Render::Text::Paragraph::SetFormat(pPara, v55, &fmt);
        v43 = 1;
        goto LABEL_69;
      }
LABEL_77:
      if ( *(_QWORD *)command )
      {
        Scaleform::Render::Text::StyledText::Remove(
          this->pDocument.pObject,
          *(_QWORD *)command - 1i64,
          *(_QWORD *)command >= (unsigned __int64)(*(_QWORD *)command - 1i64));
        return inserted;
      }
LABEL_79:
      inserted = 0i64;
      if ( v43 )
LABEL_91:
        this->vfptr[1].__vecDelDtor(this, 2u);
      return inserted;
    default:
      return inserted;
  }
}

// File Line: 438
// RVA: 0x98C650
Scaleform::String *__fastcall Scaleform::Render::Text::DocView::GetText(
        Scaleform::Render::Text::DocView *this,
        Scaleform::String *result)
{
  Scaleform::Render::Text::StyledText::GetText(this->pDocument.pObject, result);
  return result;
}

// File Line: 443
// RVA: 0x98C690
Scaleform::String *__fastcall Scaleform::Render::Text::DocView::GetText(
        Scaleform::Render::Text::DocView *this,
        Scaleform::String *retStr)
{
  return Scaleform::Render::Text::StyledText::GetText(this->pDocument.pObject, retStr);
}

// File Line: 448
// RVA: 0x985440
Scaleform::String *__fastcall Scaleform::Render::Text::DocView::GetHtml(
        Scaleform::Render::Text::DocView *this,
        Scaleform::String *result)
{
  Scaleform::Render::Text::StyledText::GetHtml(this->pDocument.pObject, result);
  return result;
}

// File Line: 466
// RVA: 0x99E590
void __fastcall Scaleform::Render::Text::DocView::ParseHtml(
        Scaleform::Render::Text::DocView *this,
        const char *putf8Str,
        unsigned __int64 utf8Len,
        bool condenseWhite,
        Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *pimgInfoArr,
        Scaleform::Render::Text::StyleManagerBase *pstyleMgr,
        Scaleform::Render::Text::TextFormat *txtFmt,
        Scaleform::Render::Text::ParagraphFormat *paraFmt)
{
  Scaleform::Render::Text::StyledText::Clear(this->pDocument.pObject);
  if ( utf8Len == -1i64 )
  {
    do
      ++utf8Len;
    while ( putf8Str[utf8Len] );
  }
  Scaleform::Render::Text::StyledText::ParseHtml(
    this->pDocument.pObject,
    putf8Str,
    utf8Len,
    pimgInfoArr,
    (this->Flags & 4) != 0,
    condenseWhite,
    pstyleMgr,
    txtFmt,
    paraFmt);
  this->vfptr[1].__vecDelDtor(this, 262u);
}

// File Line: 478
// RVA: 0x99E650
void __fastcall Scaleform::Render::Text::DocView::ParseHtml(
        Scaleform::Render::Text::DocView *this,
        const wchar_t *pwStr,
        unsigned __int64 strLen,
        bool condenseWhite,
        Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *pimgInfoArr,
        Scaleform::Render::Text::StyleManagerBase *pstyleMgr,
        Scaleform::Render::Text::TextFormat *txtFmt,
        Scaleform::Render::Text::ParagraphFormat *paraFmt)
{
  Scaleform::Render::Text::StyledText::Clear(this->pDocument.pObject);
  if ( strLen == -1i64 )
  {
    do
      ++strLen;
    while ( pwStr[strLen] );
  }
  Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>(this->pDocument.pObject, pwStr, strLen, pimgInfoArr);
  this->vfptr[1].__vecDelDtor(this, 262u);
}

// File Line: 499
// RVA: 0x959D20
void __fastcall Scaleform::Render::Text::DocView::AppendText(
        Scaleform::Render::Text::DocView *this,
        char *putf8Str,
        unsigned __int64 utf8Len)
{
  unsigned __int64 Length; // rax
  Scaleform::Render::Text::ParagraphFormat *ppdestParaFmt; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::Render::Text::TextFormat *ppdestTextFmt; // [rsp+58h] [rbp+20h] BYREF

  Length = Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject);
  if ( Length
    && Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
         this->pDocument.pObject,
         &ppdestTextFmt,
         &ppdestParaFmt,
         Length - 1) )
  {
    Scaleform::Render::Text::StyledText::AppendString(
      this->pDocument.pObject,
      putf8Str,
      utf8Len,
      (Scaleform::Render::Text::StyledText::NewLinePolicy)((this->RTFlags & 8) == 0),
      ppdestTextFmt,
      ppdestParaFmt);
  }
  else
  {
    Scaleform::Render::Text::StyledText::AppendString(
      this->pDocument.pObject,
      putf8Str,
      utf8Len,
      (Scaleform::Render::Text::StyledText::NewLinePolicy)((this->RTFlags & 8) == 0),
      this->pDocument.pObject->pDefaultTextFormat.pObject,
      this->pDocument.pObject->pDefaultParagraphFormat.pObject);
  }
  this->vfptr[1].__vecDelDtor(this, 6u);
}

// File Line: 519
// RVA: 0x958F90
void __fastcall Scaleform::Render::Text::DocView::AppendHtml(
        Scaleform::Render::Text::DocView *this,
        const char *putf8Str,
        unsigned __int64 utf8Len,
        bool condenseWhite,
        Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *pimgInfoArr)
{
  if ( utf8Len == -1i64 )
  {
    do
      ++utf8Len;
    while ( putf8Str[utf8Len] );
  }
  Scaleform::Render::Text::StyledText::ParseHtml(
    this->pDocument.pObject,
    putf8Str,
    utf8Len,
    pimgInfoArr,
    (this->Flags & 4) != 0,
    condenseWhite,
    0i64,
    0i64,
    0i64);
  this->vfptr[1].__vecDelDtor(this, 6u);
}

// File Line: 532
// RVA: 0x9AA880
__int64 __fastcall Scaleform::Render::Text::DocView::ReplaceText(
        Scaleform::Render::Text::DocView *this,
        const wchar_t *pstr,
        unsigned __int64 startPos,
        unsigned __int64 endPos,
        unsigned __int64 strLen)
{
  unsigned __int64 v8; // r9

  if ( endPos < startPos )
    v8 = 0i64;
  else
    v8 = endPos - startPos;
  Scaleform::Render::Text::StyledText::Remove(this->pDocument.pObject, startPos, v8);
  return Scaleform::Render::Text::StyledText::InsertString(
           this->pDocument.pObject,
           pstr,
           startPos,
           strLen,
           NLP_ReplaceCRLF,
           this->pDocument.pObject->pDefaultTextFormat.pObject,
           this->pDocument.pObject->pDefaultParagraphFormat.pObject);
}

// File Line: 540
// RVA: 0x9611E0
void __fastcall Scaleform::Render::Text::DocView::Close(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView::DocumentText *pObject; // rcx
  bool v3; // zf
  Scaleform::Render::Text::DocView::DocumentListener *v4; // rcx
  Scaleform::Render::Text::EditorKitBase *v5; // rcx

  pObject = this->pDocument.pObject;
  if ( pObject )
  {
    v3 = pObject->RefCount-- == 1;
    if ( v3 )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
    this->pDocument.pObject = 0i64;
    v4 = this->pDocumentListener.pObject;
    if ( v4 )
    {
      v3 = v4->RefCount-- == 1;
      if ( v3 )
        v4->vfptr->__vecDelDtor(v4, 1u);
    }
    this->pDocumentListener.pObject = 0i64;
    v5 = this->pEditorKit.pObject;
    if ( v5 )
    {
      if ( !_InterlockedDecrement(&v5->RefCount) )
        v5->vfptr->__vecDelDtor(v5, 1u);
    }
    this->pEditorKit.pObject = 0i64;
    this->mLineBuffer.Geom.Flags |= 1u;
    Scaleform::Render::Text::LineBuffer::RemoveLines(&this->mLineBuffer, 0, this->mLineBuffer.Lines.Data.Size);
  }
}

// File Line: 552
// RVA: 0x962AB0
char __fastcall Scaleform::Render::Text::DocView::ContainsNonLeftAlignment(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView::DocumentText *pObject; // r8
  int v2; // eax
  unsigned int Size; // r9d
  __int64 i; // rdx

  pObject = this->pDocument.pObject;
  v2 = 0;
  Size = pObject->Paragraphs.Data.Size;
  if ( !Size )
    return 0;
  for ( i = 0i64; (pObject->Paragraphs.Data.Data[i].pPara->pFormat.pObject->PresentMask & 0x600) == 0; ++i )
  {
    if ( ++v2 >= Size )
      return 0;
  }
  return 1;
}

// File Line: 564
// RVA: 0x9B5A70
void __fastcall Scaleform::Render::Text::DocView::SetViewRect(
        Scaleform::Render::Text::DocView *this,
        Scaleform::Render::Rect<float> *rect,
        Scaleform::Render::Text::DocView::UseType ut)
{
  float x1; // xmm2_4
  float y2; // xmm4_4
  float x2; // xmm3_4
  float v7; // xmm0_4
  float y1; // xmm2_4
  unsigned int v9; // ecx
  float v10; // xmm0_4
  char AlignProps; // di
  unsigned int v12; // eax
  unsigned int v13; // esi
  unsigned int MaxHScroll; // eax
  unsigned int MaxVScroll; // edi
  unsigned int v16; // eax
  Scaleform::Render::Text::DocView::DocumentListener *pObject; // rcx

  x1 = this->ViewRect.x1;
  if ( rect->x1 != x1 || this->ViewRect.x2 != rect->x2 || this->ViewRect.y1 != rect->y1 || this->ViewRect.y2 != rect->y2 )
  {
    y2 = rect->y2;
    x2 = rect->x2;
    v7 = this->ViewRect.x2 - x1;
    y1 = rect->y1;
    v9 = (int)v7;
    v10 = this->ViewRect.y2 - this->ViewRect.y1;
    this->ViewRect.x1 = rect->x1;
    this->ViewRect.y1 = y1;
    this->ViewRect.x2 = x2;
    this->ViewRect.y2 = y2;
    this->mLineBuffer.Geom.VisibleRect.x1 = this->ViewRect.x1 + 40.0;
    this->mLineBuffer.Geom.VisibleRect.y1 = y1 + 40.0;
    this->mLineBuffer.Geom.VisibleRect.x2 = x2 - 40.0;
    this->mLineBuffer.Geom.VisibleRect.y2 = y2 - 40.0;
    if ( ut == UseExternally )
    {
      AlignProps = this->AlignProps;
      v12 = (int)(float)(this->ViewRect.x2 - this->ViewRect.x1);
      v13 = (int)(float)(this->ViewRect.y2 - this->ViewRect.y1);
      if ( (AlignProps & 0x30) != 0
        || v9 != v12
        && ((this->Flags & 8) != 0
         || v12 < v9 && (this->mLineBuffer.Geom.Flags & 0x20) != 0
         || (AlignProps & 3) != 0
         || Scaleform::Render::Text::DocView::ContainsNonLeftAlignment(this))
        || v13 < (int)v10 && (this->mLineBuffer.Geom.Flags & 0x20) != 0
        || (AlignProps & 0xCu) > 4 )
      {
        this->RTFlags |= 2u;
      }
      else
      {
        ++this->FormatCounter;
        MaxHScroll = Scaleform::Render::Text::DocView::GetMaxHScroll(this);
        if ( this->mLineBuffer.Geom.HScrollOffset > MaxHScroll )
          Scaleform::Render::Text::DocView::SetHScrollOffset(this, MaxHScroll);
        MaxVScroll = Scaleform::Render::Text::DocView::GetMaxVScroll(this);
        if ( this->mLineBuffer.Geom.FirstVisibleLinePos > MaxVScroll )
        {
          v16 = Scaleform::Render::Text::DocView::GetMaxVScroll(this);
          if ( MaxVScroll > v16 )
            MaxVScroll = v16;
          if ( this->mLineBuffer.Geom.FirstVisibleLinePos != MaxVScroll )
          {
            this->mLineBuffer.Geom.FirstVisibleLinePos = MaxVScroll;
            this->mLineBuffer.Geom.Flags |= 1u;
            pObject = this->pDocumentListener.pObject;
            if ( pObject )
              ((void (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::Render::Text::DocView *, _QWORD))pObject->vfptr[4].__vecDelDtor)(
                pObject,
                this,
                MaxVScroll);
          }
        }
        this->mLineBuffer.Geom.Flags |= 1u;
      }
    }
  }
}

// File Line: 619
// RVA: 0x99CA00
void __fastcall Scaleform::Render::Text::DocView::OnDocumentChanged(
        Scaleform::Render::Text::DocView *this,
        __int16 notifyMask)
{
  if ( (notifyMask & 0x100) != 0 )
    this->RTFlags |= 2u;
  else
    this->RTFlags |= 1u;
}

// File Line: 627
// RVA: 0x99CA20
void __fastcall Scaleform::Render::Text::DocView::OnDocumentParagraphRemoving(
        Scaleform::Render::Text::DocView *this,
        Scaleform::Render::Text::Paragraph *para)
{
  __int64 v2; // r8
  char v4; // bl
  Scaleform::Render::Text::LineBuffer *p_mLineBuffer; // r9
  int *v6; // rcx
  int v7; // r11d

  v2 = 0i64;
  v4 = 0;
  p_mLineBuffer = &this->mLineBuffer;
  while ( p_mLineBuffer && (unsigned int)v2 < p_mLineBuffer->Lines.Data.Size && (int)v2 >= 0 )
  {
    v6 = (int *)p_mLineBuffer->Lines.Data.Data[v2];
    if ( *v6 >= 0 )
      v7 = v6[7];
    else
      v7 = v6[1];
    if ( para->UniqueId == v7 )
    {
      v4 = 1;
      if ( *v6 >= 0 )
        v6[2] = -1;
      else
        v6[2] |= 0xFFFFFFu;
    }
    else if ( v4 )
    {
      break;
    }
    if ( (unsigned int)v2 < p_mLineBuffer->Lines.Data.Size )
      v2 = (unsigned int)(v2 + 1);
  }
  this->RTFlags |= 1u;
}

// File Line: 645
// RVA: 0x979820
Scaleform::Render::Text::FontHandle *__fastcall Scaleform::Render::Text::DocView::FindFont(
        Scaleform::Render::Text::DocView *this,
        Scaleform::Render::Text::DocView::FindFontInfo *pfontInfo,
        bool quietMode)
{
  Scaleform::Render::Text::DocView::FindFontInfo *v3; // r15
  Scaleform::Render::Text::DocView *v4; // rdi
  Scaleform::Ptr<Scaleform::Render::Text::FontHandle> *p_pCurrentFont; // r12
  Scaleform::Render::Text::TextFormat *pPrevFormat; // rdx
  Scaleform::Render::Text::TextFormat **p_pCurrentFormat; // r13
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,74>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF> > *p_mHash; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,74>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF> > v9; // rbx
  __int64 v10; // rax
  unsigned __int64 *v11; // rsi
  Scaleform::Render::Text::FontHandle **v12; // rsi
  Scaleform::Ptr<Scaleform::Render::Text::FontHandle> v13; // rcx
  Scaleform::Render::Text::TextFormat *pCurrentFormat; // rdx
  unsigned __int16 PresentMask; // cx
  Scaleform::Render::RenderBuffer *FontHandle; // rax
  __int64 v17; // rdi
  __int16 v18; // cx
  bool v19; // r14
  char v20; // si
  char v21; // di
  Scaleform::StringDH *FontList; // rax
  __int64 v23; // r9
  __int64 v24; // rdi
  Scaleform::Render::Text::FontHandle *v25; // rcx
  __int16 v26; // r15
  bool v27; // r14
  char v28; // si
  char v29; // di
  Scaleform::StringDH *v30; // rax
  __int64 v31; // r9
  __int64 v32; // r15
  Scaleform::Render::Text::DocView::DocumentListener *v33; // rcx
  Scaleform::String *v34; // rax
  char v35; // di
  const char *v36; // rsi
  unsigned __int64 v37; // rdi
  Scaleform::StringDH *v38; // rax
  Scaleform::Render::Text::FontHandle *v39; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,74>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeHashF> > *v40; // rcx
  Scaleform::Render::Text::FontManagerBase *pObject; // [rsp+38h] [rbp-61h]
  Scaleform::String v43; // [rsp+40h] [rbp-59h] BYREF
  __int64 v44; // [rsp+48h] [rbp-51h] BYREF
  Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeRef key; // [rsp+50h] [rbp-49h] BYREF
  int v46; // [rsp+60h] [rbp-39h] BYREF
  const char *v47; // [rsp+68h] [rbp-31h]
  __int64 v48; // [rsp+70h] [rbp-29h]
  __int64 v49; // [rsp+78h] [rbp-21h]
  __int64 v50; // [rsp+80h] [rbp-19h]
  char v51; // [rsp+88h] [rbp-11h]
  Scaleform::MemoryHeap *v52; // [rsp+90h] [rbp-9h]
  __int64 v53; // [rsp+98h] [rbp-1h]
  __int64 v54; // [rsp+A0h] [rbp+7h]
  unsigned __int64 v58; // [rsp+118h] [rbp+7Fh] BYREF

  v54 = -2i64;
  v3 = pfontInfo;
  v4 = this;
  p_pCurrentFont = &pfontInfo->pCurrentFont;
  if ( pfontInfo->pCurrentFont.pObject )
  {
    pPrevFormat = pfontInfo->pPrevFormat;
    if ( pPrevFormat )
    {
      p_pCurrentFormat = &v3->pCurrentFormat;
      if ( Scaleform::Render::Text::TextFormat::IsFontSame(v3->pCurrentFormat, pPrevFormat) )
        goto LABEL_57;
    }
  }
  p_mHash = &v3->pFontCache->mHash;
  if ( v3->pFontCache )
  {
    p_pCurrentFormat = &v3->pCurrentFormat;
    v9.pTable = p_mHash->pTable;
    if ( p_mHash->pTable )
    {
      v10 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,74>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF>>::findIndexCore<Scaleform::Render::Text::TextFormat const *>(
              p_mHash,
              &v3->pCurrentFormat,
              (unsigned __int64)*p_pCurrentFormat & v9.pTable->SizeMask);
      if ( v10 >= 0 )
      {
        v11 = &v9.pTable[1].SizeMask + 3 * v10;
        if ( v11 )
        {
          v12 = (Scaleform::Render::Text::FontHandle **)(v11 + 1);
          if ( v12 )
          {
            if ( *v12 )
              _InterlockedExchangeAdd(&(*v12)->RefCount, 1u);
            v13.pObject = p_pCurrentFont->pObject;
            if ( p_pCurrentFont->pObject && !_InterlockedDecrement(&v13.pObject->RefCount) && v13.pObject )
              ((void (__fastcall *)(Scaleform::Ptr<Scaleform::Render::Text::FontHandle>, __int64))v13.pObject->vfptr->__vecDelDtor)(
                v13,
                1i64);
            p_pCurrentFont->pObject = *v12;
            goto LABEL_57;
          }
        }
      }
    }
  }
  p_pCurrentFormat = &v3->pCurrentFormat;
  pCurrentFormat = v3->pCurrentFormat;
  PresentMask = pCurrentFormat->PresentMask;
  if ( (PresentMask & 0x800) != 0 )
  {
    FontHandle = Scaleform::Render::Text::TextFormat::GetFontHandle(v3->pCurrentFormat);
    v17 = (__int64)FontHandle;
    if ( FontHandle )
      _InterlockedExchangeAdd(&FontHandle->RefCount, 1u);
  }
  else
  {
    pObject = v4->pFontManager.pObject;
    if ( (PresentMask & 4) != 0 )
    {
      v18 = PresentMask >> 12;
      LOBYTE(v18) = v18 & 1;
      LOWORD(v58) = v18;
      v19 = (v4->Flags & 0x20) != 0;
      v20 = (unsigned __int8)pCurrentFormat->FormatFlags >> 1;
      v21 = pCurrentFormat->FormatFlags & 1;
      FontList = Scaleform::Render::Text::TextFormat::GetFontList(pCurrentFormat);
      LOBYTE(v23) = (_BYTE)v58 == 0;
      v24 = ((__int64 (__fastcall *)(Scaleform::Render::Text::FontManagerBase *, unsigned __int64, _QWORD, __int64, _QWORD))pObject->vfptr[1].__vecDelDtor)(
              pObject,
              (FontList->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
              (v19 ? 0x10 : 0) | ((v20 & 1) != 0) | (v21 != 0 ? 2 : 0),
              v23,
              0i64);
      v25 = p_pCurrentFont->pObject;
      if ( p_pCurrentFont->pObject && !_InterlockedDecrement(&v25->RefCount) && v25 )
        v25->vfptr->__vecDelDtor(v25, 1u);
      p_pCurrentFont->pObject = (Scaleform::Render::Text::FontHandle *)v24;
      v4 = this;
    }
    if ( p_pCurrentFont->pObject )
      goto LABEL_55;
    if ( !quietMode && (v4->RTFlags & 0x10) == 0 && v4->pLog.pObject )
    {
      v46 = 1;
      v47 = 0i64;
      v48 = 0i64;
      v49 = 0i64;
      v50 = 512i64;
      v51 = 0;
      v52 = Scaleform::Memory::pGlobalHeap;
      v26 = (*p_pCurrentFormat)->PresentMask >> 12;
      v27 = (v4->Flags & 0x20) != 0;
      v28 = (unsigned __int8)(*p_pCurrentFormat)->FormatFlags >> 1;
      v29 = (*p_pCurrentFormat)->FormatFlags & 1;
      v30 = Scaleform::Render::Text::TextFormat::GetFontList(*p_pCurrentFormat);
      LOBYTE(v31) = (v26 & 1) == 0;
      v32 = ((__int64 (__fastcall *)(Scaleform::Render::Text::FontManagerBase *, unsigned __int64, _QWORD, __int64, int *))pObject->vfptr[1].__vecDelDtor)(
              pObject,
              (v30->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
              (v27 ? 0x10 : 0) | ((v28 & 1) != 0) | (v29 != 0 ? 2 : 0),
              v31,
              &v46);
      v53 = v32;
      v33 = this->pDocumentListener.pObject;
      if ( v33 )
      {
        v34 = (Scaleform::String *)v33->vfptr[14].__vecDelDtor(v33, (unsigned int)&v44);
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
      if ( (v35 & 2) != 0 )
      {
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v58 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v35 &= ~2u;
      }
      if ( (v35 & 1) != 0 && !_InterlockedDecrement((volatile signed __int32 *)((v44 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v36 = &customCaption;
      if ( v47 )
        v36 = v47;
      v37 = v43.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
      v38 = Scaleform::Render::Text::TextFormat::GetFontList(*p_pCurrentFormat);
      Scaleform::Log::LogError(
        this->pLog.pObject,
        "Missing font \"%s\" in \"%s\". Search log:\n%s",
        (const char *)((v38->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
        (const char *)(v37 + 12),
        v36);
      this->RTFlags |= 0x10u;
      if ( !_InterlockedDecrement((volatile signed __int32 *)(v37 + 8)) )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v37);
      if ( v32 && !_InterlockedDecrement((volatile signed __int32 *)(v32 + 8)) )
        (**(void (__fastcall ***)(__int64, __int64))v32)(v32, 1i64);
      if ( v47 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v3 = pfontInfo;
    }
    v17 = ((__int64 (__fastcall *)(Scaleform::Render::Text::FontManagerBase *))pObject->vfptr[2].__vecDelDtor)(pObject);
  }
  v39 = p_pCurrentFont->pObject;
  if ( p_pCurrentFont->pObject && !_InterlockedDecrement(&v39->RefCount) && v39 )
    v39->vfptr->__vecDelDtor(v39, 1u);
  p_pCurrentFont->pObject = (Scaleform::Render::Text::FontHandle *)v17;
LABEL_55:
  v40 = &v3->pFontCache->mHash;
  if ( v3->pFontCache )
  {
    key.pFirst = p_pCurrentFormat;
    key.pSecond = p_pCurrentFont;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,74>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeRef>(
      v40,
      v40[1].pTable,
      &key);
  }
LABEL_57:
  v3->pPrevFormat = *p_pCurrentFormat;
  return p_pCurrentFont->pObject;
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
void __fastcall Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(
        Scaleform::Render::Text::GFxLineCursor *this,
        Scaleform::Render::Text::DocView *pview,
        Scaleform::Render::Text::Paragraph *ppara)
{
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

// File Line: 890
// RVA: 0x94A5E0
void __fastcall Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(Scaleform::Render::Text::GFxLineCursor *this)
{
  Scaleform::Render::Text::TextFormat *pObject; // rbx
  bool v3; // zf
  Scaleform::Render::Text::TextFormat *v4; // rbx
  Scaleform::Render::Text::FontHandle *v5; // rcx

  pObject = this->CharInfoHolder.pFormat.pObject;
  if ( pObject )
  {
    v3 = pObject->RefCount-- == 1;
    if ( v3 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  v4 = this->CharIter.PlaceHolder.pFormat.pObject;
  if ( v4 )
  {
    v3 = v4->RefCount-- == 1;
    if ( v3 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v4);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  v5 = this->pLastFont.pObject;
  if ( v5 )
  {
    if ( !_InterlockedDecrement(&v5->RefCount) )
      v5->vfptr->__vecDelDtor(v5, 1u);
  }
}

// File Line: 967
// RVA: 0x94EDA0
Scaleform::Render::Text::Paragraph::CharacterInfo *__fastcall Scaleform::Render::Text::GFxLineCursor::operator*(
        Scaleform::Render::Text::GFxLineCursor *this)
{
  Scaleform::Render::Text::Paragraph::CharactersIterator *v2; // rax

  this->CharInfoHolder.Index = Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(&this->CharIter)->PlaceHolder.Index;
  v2 = Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(&this->CharIter);
  Scaleform::Render::Text::Paragraph::CharacterInfo::operator=(&this->CharInfoHolder, &v2->PlaceHolder);
  if ( (this->pDocView->Flags & 0x10) != 0 && this->CharInfoHolder.Character )
    this->CharInfoHolder.Character = 42;
  return &this->CharInfoHolder;
}

// File Line: 1033
// RVA: 0x9BA4D0
void __fastcall Scaleform::Render::Text::GFxLineCursor::TrackFontParams(
        Scaleform::Render::Text::GFxLineCursor *this,
        Scaleform::Render::Font *pfont,
        float scale)
{
  float Ascent; // xmm0_4
  float Descent; // xmm1_4
  float MaxFontAscent; // xmm3_4
  float v6; // xmm0_4
  float MaxFontDescent; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float MaxFontLeading; // xmm0_4

  Ascent = pfont->Ascent;
  Descent = pfont->Descent;
  if ( Ascent == 0.0 )
    Ascent = FLOAT_960_0;
  if ( Descent == 0.0 )
    Descent = FLOAT_64_0;
  MaxFontAscent = this->MaxFontAscent;
  v6 = Ascent * scale;
  if ( v6 >= MaxFontAscent )
    MaxFontAscent = v6;
  MaxFontDescent = this->MaxFontDescent;
  v8 = Descent * scale;
  this->MaxFontAscent = MaxFontAscent;
  if ( v8 >= MaxFontDescent )
    MaxFontDescent = v8;
  this->MaxFontDescent = MaxFontDescent;
  v9 = scale * pfont->Leading;
  MaxFontLeading = this->MaxFontLeading;
  if ( v9 >= MaxFontLeading )
    this->MaxFontLeading = v9;
  else
    this->MaxFontLeading = MaxFontLeading;
}

// File Line: 1137
// RVA: 0x9406C0
void __fastcall Scaleform::Render::Text::ParagraphFormatter::ParagraphFormatter(
        Scaleform::Render::Text::ParagraphFormatter *this,
        Scaleform::Render::Text::DocView *pdoc,
        Scaleform::Log *plog)
{
  Scaleform::Render::Text::Allocator *pObject; // rcx
  Scaleform::MemoryHeap *pHeap; // rcx
  Scaleform::Render::Text::FontHandle *v8; // rcx

  this->pDocView = pdoc;
  this->pParagraph = 0i64;
  this->pParaFormat = 0i64;
  this->pTempLine = 0i64;
  Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&this->LineCursor);
  pObject = pdoc->pDocument.pObject->pTextAllocator.pObject;
  if ( pObject )
    pHeap = pObject->pHeap;
  else
    pHeap = (Scaleform::MemoryHeap *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap)(Scaleform::Memory::pGlobalHeap);
  this->FontCache.mHash.pTable = 0i64;
  this->FontCache.mHash.pHeap = pHeap;
  this->FindFontInfo.pFontCache = &this->FontCache;
  this->FindFontInfo.pCurrentFont.pObject = 0i64;
  this->FindFontInfo.pPrevFormat = 0i64;
  this->FindFontInfo.pCurrentFormat = 0i64;
  v8 = this->FindFontInfo.pCurrentFont.pObject;
  if ( v8 && !_InterlockedDecrement(&v8->RefCount) )
    v8->vfptr->__vecDelDtor(v8, 1u);
  this->FindFontInfo.pCurrentFont.pObject = 0i64;
  Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&this->StartPoint);
  Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&this->HalfPoint);
  Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&this->WordWrapPoint);
  this->pFontHandle.pObject = 0i64;
  this->pDynLine = 0i64;
  *(_QWORD *)&this->NextOffsetY = 0i64;
  *(_WORD *)&this->NeedRecenterLines = 0;
  this->pLog = plog;
  *(_QWORD *)&this->NewLen = 0i64;
  this->NewParaText = 0i64;
  this->IndexMap = 0i64;
  this->MirroredBits = 0i64;
}

// File Line: 1151
// RVA: 0x94BC50
void __fastcall Scaleform::Render::Text::ParagraphFormatter::~ParagraphFormatter(
        Scaleform::Render::Text::ParagraphFormatter *this)
{
  Scaleform::Render::Text::LineBuffer::Line *pDynLine; // rbx
  Scaleform::Render::Text::FontHandle *pObject; // rcx
  Scaleform::Render::Text::FontHandle *v4; // rcx

  pDynLine = this->pDynLine;
  if ( pDynLine )
  {
    Scaleform::Render::Text::LineBuffer::Line::Release(this->pDynLine);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pDynLine);
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->NewParaText);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->IndexMap);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->MirroredBits);
  pObject = this->pFontHandle.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(&this->WordWrapPoint);
  Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(&this->HalfPoint);
  Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(&this->StartPoint);
  v4 = this->FindFontInfo.pCurrentFont.pObject;
  if ( v4 && !_InterlockedDecrement(&v4->RefCount) )
    v4->vfptr->__vecDelDtor(v4, 1u);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,74>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,74>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF>>(&this->FontCache.mHash);
  Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(&this->LineCursor);
}

// File Line: 1160
// RVA: 0x9939A0
void __fastcall Scaleform::Render::Text::ParagraphFormatter::InitParagraph(
        Scaleform::Render::Text::ParagraphFormatter *this,
        Scaleform::Render::Text::Paragraph *paragraph)
{
  Scaleform::Render::Text::GFxLineCursor *v4; // rax
  Scaleform::Render::Text::GFxLineCursor *v5; // rax
  Scaleform::Render::Text::GFxLineCursor *v6; // rax
  Scaleform::Render::Text::DocView *pDocView; // rcx
  Scaleform::Render::Text::EditorKitBase *pObject; // rcx
  unsigned __int64 v9; // rsi
  signed __int16 PresentMask; // cx
  unsigned int v11; // ebx
  Scaleform::Render::Text::LineBuffer::Line *TempLineBuff; // rax
  Scaleform::Render::Text::LineBuffer::Line *pDynLine; // r14
  unsigned int v14; // ebx
  __int64 v15; // rax
  Scaleform::Render::Text::LineBuffer::Line *v16; // rax
  unsigned int v17; // ebx
  Scaleform::Render::Text::LineBuffer::Line *pTempLine; // rcx
  Scaleform::Render::Text::LineBuffer::Line *v19; // rcx
  unsigned __int64 StartIndex; // rdx
  Scaleform::Render::Text::EditorKitBase *v21; // rcx
  Scaleform::Render::Text::LineBuffer::Line *v22; // rcx
  Scaleform::Render::Text::LineBuffer::Line *v23; // rcx
  char *v24; // rdx
  __int64 GlyphsCount; // rax
  unsigned int v26; // r9d
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v27; // rcx
  Scaleform::Render::Text::GFxLineCursor __that; // [rsp+20h] [rbp-E0h] BYREF
  __int64 v29; // [rsp+128h] [rbp+28h]
  Scaleform::Render::Text::GFxLineCursor v30; // [rsp+130h] [rbp+30h] BYREF

  v29 = -2i64;
  this->pParagraph = paragraph;
  this->pParaFormat = paragraph->pFormat.pObject;
  Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&v30, this->pDocView, paragraph);
  Scaleform::Render::Text::GFxLineCursor::operator=(&this->LineCursor, v4);
  Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(&v30);
  memset(&__that, 0, 40);
  __that.ComposStrPosition = -1i64;
  memset(&__that.ComposStrLength, 0, 74);
  __that.CharIter.pFormatInfo = 0i64;
  __that.CharIter.FormatIterator.pArray = 0i64;
  __that.CharIter.FormatIterator.Index = -1i64;
  memset(&__that.CharIter.pText, 0, 34);
  *(_QWORD *)&__that.Indent = 0i64;
  __that.RightMargin = 0;
  memset(&__that.GlyphIns, 0, 28);
  *(_QWORD *)&__that.NumOfSpaces = 0i64;
  LODWORD(__that.FontScaleFactor) = (_DWORD)FLOAT_1_0;
  *(_WORD *)&__that.LastKerning = 0;
  __that.NumChars = 0i64;
  v5 = Scaleform::Render::Text::GFxLineCursor::operator=(&this->WordWrapPoint, &__that);
  v6 = Scaleform::Render::Text::GFxLineCursor::operator=(&this->HalfPoint, v5);
  Scaleform::Render::Text::GFxLineCursor::operator=(&this->StartPoint, v6);
  Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(&__that);
  pDocView = this->pDocView;
  this->LineCursor.FontScaleFactor = (float)this->pDocView->FontScaleFactor * 0.050000001;
  pObject = pDocView->pEditorKit.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))pObject->vfptr[3].__vecDelDtor)(pObject);
  Scaleform::Render::Text::ParagraphFormatter::InitCustomWordWrapping(this);
  this->pDocView->RTFlags &= ~0x40u;
  v9 = paragraph->Text.Size + this->LineCursor.ComposStrLength;
  PresentMask = this->pParaFormat->PresentMask;
  if ( (PresentMask & 0x80u) != 0 && PresentMask < 0 )
    LODWORD(v9) = v9 + 1;
  v11 = ((8 * v9 + 49) & 0xFFFFFFF8) + 16 * v9;
  if ( v11 >= 0x400 )
  {
    pDynLine = this->pDynLine;
    if ( pDynLine )
    {
      if ( v11 >= (pDynLine->MemSize & 0x7FFFFFF) )
      {
        Scaleform::Render::Text::LineBuffer::Line::Release(this->pDynLine);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pDynLine);
        v14 = v11 + 100;
        v15 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Text::LineBuffer::TextLineAllocator *, _QWORD, _QWORD, Scaleform::Render::Text::LineBuffer::GlyphEntry *, Scaleform::Render::Text::FontHandle *, _QWORD, _QWORD, _QWORD, unsigned __int64, unsigned __int64, unsigned __int64, Scaleform::Render::Text::DocView *, Scaleform::Render::Text::Paragraph *, _QWORD, _QWORD, _QWORD, Scaleform::Render::Text::TextFormat *, unsigned __int64, _DWORD, Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *, Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *, __int64, Scaleform::Render::Text::Paragraph::TextBuffer *, unsigned __int64, Scaleform::Render::Text::TextFormat *, unsigned __int64, _DWORD, _QWORD, int, Scaleform::Render::Text::LineBuffer::GlyphEntry *, Scaleform::Render::Text::LineBuffer::FormatDataEntry *, _QWORD, unsigned int, _QWORD, _QWORD, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                Scaleform::Memory::pGlobalHeap,
                &this->pDocView->mLineBuffer.LineAllocator,
                v14,
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
                *(_DWORD *)&__that.CharIter.PlaceHolder.Character,
                __that.CharIter.pFormatInfo,
                __that.CharIter.FormatIterator.pArray,
                __that.CharIter.FormatIterator.Index,
                __that.CharIter.pText,
                __that.CharIter.CurTextIndex,
                __that.CharInfoHolder.pFormat.pObject,
                __that.CharInfoHolder.Index,
                *(_DWORD *)&__that.CharInfoHolder.Character,
                *(_QWORD *)&__that.Indent,
                __that.RightMargin,
                __that.GlyphIns.pGlyphs,
                __that.GlyphIns.pNextFormatData,
                *(_QWORD *)&__that.GlyphIns.GlyphIndex,
                __that.GlyphIns.FormatDataIndex,
                *(_QWORD *)&__that.NumOfSpaces,
                *(_QWORD *)&__that.FontScaleFactor,
                __that.NumChars);
        *(_DWORD *)v15 = v14 & 0x7FFFFFF | 0x40000000;
        *(_QWORD *)(v15 + 4) = 0i64;
        *(_DWORD *)(v15 + 38) = 0;
        *(_QWORD *)(v15 + 12) = 0i64;
        *(_QWORD *)(v15 + 20) = 0i64;
        *(_DWORD *)(v15 + 32) = 0;
        this->pDynLine = (Scaleform::Render::Text::LineBuffer::Line *)v15;
      }
      v16 = this->pDynLine;
    }
    else
    {
      v17 = v11 + 100;
      v16 = (Scaleform::Render::Text::LineBuffer::Line *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Text::LineBuffer::TextLineAllocator *, _QWORD, _QWORD, Scaleform::Render::Text::LineBuffer::GlyphEntry *, Scaleform::Render::Text::FontHandle *, _QWORD, _QWORD, _QWORD, unsigned __int64, unsigned __int64, unsigned __int64, Scaleform::Render::Text::DocView *, Scaleform::Render::Text::Paragraph *, _QWORD, _QWORD, _QWORD, Scaleform::Render::Text::TextFormat *, unsigned __int64, _DWORD, Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *, Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *, __int64, Scaleform::Render::Text::Paragraph::TextBuffer *, unsigned __int64, Scaleform::Render::Text::TextFormat *, unsigned __int64, _DWORD, _QWORD, int, Scaleform::Render::Text::LineBuffer::GlyphEntry *, Scaleform::Render::Text::LineBuffer::FormatDataEntry *, _QWORD, unsigned int, _QWORD, _QWORD, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           &this->pDocView->mLineBuffer.LineAllocator,
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
                                                           *(_DWORD *)&__that.CharIter.PlaceHolder.Character,
                                                           __that.CharIter.pFormatInfo,
                                                           __that.CharIter.FormatIterator.pArray,
                                                           __that.CharIter.FormatIterator.Index,
                                                           __that.CharIter.pText,
                                                           __that.CharIter.CurTextIndex,
                                                           __that.CharInfoHolder.pFormat.pObject,
                                                           __that.CharInfoHolder.Index,
                                                           *(_DWORD *)&__that.CharInfoHolder.Character,
                                                           *(_QWORD *)&__that.Indent,
                                                           __that.RightMargin,
                                                           __that.GlyphIns.pGlyphs,
                                                           __that.GlyphIns.pNextFormatData,
                                                           *(_QWORD *)&__that.GlyphIns.GlyphIndex,
                                                           __that.GlyphIns.FormatDataIndex,
                                                           *(_QWORD *)&__that.NumOfSpaces,
                                                           *(_QWORD *)&__that.FontScaleFactor,
                                                           __that.NumChars);
      v16->MemSize = v17 & 0x7FFFFFF | 0x40000000;
      *(_QWORD *)&v16->Data32.GlyphsCount = 0i64;
      *(_DWORD *)((char *)&v16->Data8 + 34) = 0;
      *(_QWORD *)&v16->Data8.OffsetX = 0i64;
      *(_QWORD *)&v16->Data8.Width = 0i64;
      v16->Data32.TextLength = 0;
      this->pDynLine = v16;
    }
    this->pTempLine = v16;
  }
  else
  {
    TempLineBuff = (Scaleform::Render::Text::LineBuffer::Line *)this->TempLineBuff;
    if ( this == (Scaleform::Render::Text::ParagraphFormatter *)-1792i64 )
      TempLineBuff = 0i64;
    else
      TempLineBuff->MemSize = 0;
    this->pTempLine = TempLineBuff;
    TempLineBuff->MemSize &= 0xF8000000;
    TempLineBuff->MemSize |= v11 & 0x7FFFFFF;
  }
  pTempLine = this->pTempLine;
  pTempLine->MemSize = pTempLine->MemSize & 0x7FFFFFF | 0x40000000;
  *(_QWORD *)&pTempLine->Data32.GlyphsCount = 0i64;
  *(_DWORD *)((char *)&pTempLine->Data8 + 34) = 0;
  *(_QWORD *)&pTempLine->Data8.OffsetX = 0i64;
  *(_QWORD *)&pTempLine->Data8.Width = 0i64;
  pTempLine->Data32.TextLength = 0;
  this->pTempLine->MemSize &= ~0x40000000u;
  v19 = this->pTempLine;
  if ( (v19->MemSize & 0x80000000) == 0 )
    v19->Data32.GlyphsCount = v9;
  else
    v19->Data8.GlyphsCount = v9;
  StartIndex = paragraph->StartIndex;
  v21 = this->pDocView->pEditorKit.pObject;
  if ( v21 )
    LODWORD(StartIndex) = v21->vfptr[4].__vecDelDtor(v21, StartIndex);
  v22 = this->pTempLine;
  if ( (v22->MemSize & 0x80000000) == 0 )
  {
    v22->Data32.TextPos = StartIndex;
  }
  else
  {
    v22->Data32.TextPos &= 0xFF000000;
    v22->Data32.TextPos |= StartIndex & 0xFFFFFF;
  }
  v23 = this->pTempLine;
  v24 = &v23->Data8.Leading + 1;
  if ( (v23->MemSize & 0x80000000) == 0 )
    v24 = (char *)&v23->Data8 + 38;
  if ( (v23->MemSize & 0x80000000) == 0 )
    GlyphsCount = v23->Data32.GlyphsCount;
  else
    GlyphsCount = (unsigned __int8)v23->Data8.GlyphsCount;
  if ( (v23->MemSize & 0x80000000) == 0 )
    v26 = v23->Data32.GlyphsCount;
  else
    v26 = (unsigned __int8)v23->Data8.GlyphsCount;
  if ( (v23->MemSize & 0x80000000) == 0 )
    v27 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)&v23->Data8 + 38);
  else
    v27 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(&v23->Data8.Leading + 1);
  this->LineCursor.GlyphIns.pGlyphs = v27;
  this->LineCursor.GlyphIns.pNextFormatData = (Scaleform::Render::Text::LineBuffer::FormatDataEntry *)((unsigned __int64)&v24[8 * GlyphsCount + 7] & 0xFFFFFFFFFFFFFFF8ui64);
  this->LineCursor.GlyphIns.GlyphIndex = 0;
  this->LineCursor.GlyphIns.GlyphsCount = v26;
  this->LineCursor.GlyphIns.FormatDataIndex = 0;
  *(_QWORD *)&this->ParaWidth = 0i64;
  this->ParaLines = 0;
  this->DeltaText = 1;
  this->Pass = 1;
  this->HyphenationRequested = 0;
  this->RequestedWordWrapPos = 0;
  this->isSpace = 0;
  this->TextRectWidth = this->pDocView->mLineBuffer.Geom.VisibleRect.x2
                      - this->pDocView->mLineBuffer.Geom.VisibleRect.x1;
  *(_QWORD *)&this->TabStopsNum = 0i64;
}

// File Line: 1271
// RVA: 0x992FE0
void __fastcall Scaleform::Render::Text::ParagraphFormatter::InitCustomWordWrapping(
        Scaleform::Render::Text::ParagraphFormatter *this)
{
  Scaleform::Render::Text::DocView *pDocView; // r11
  Scaleform::Render::Text::DocView::DocumentListener *pObject; // rax
  bool v4; // zf
  bool v5; // al
  Scaleform::Render::Text::Paragraph *pParagraph; // rdx
  unsigned __int64 Size; // rbx
  unsigned __int64 v8; // rax
  bool v9; // cf
  wchar_t *v10; // rax
  unsigned __int64 ComposStrPosition; // r8
  unsigned __int64 StartIndex; // r9
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // rcx
  wchar_t *v15; // rcx
  unsigned __int64 v16; // rcx
  char v17; // bp
  unsigned __int64 v18; // rax
  wchar_t *v19; // rax
  wchar_t *TextBufForCustomFormat; // rsi
  Scaleform::Render::Text::Allocator *Allocator; // rax

  pDocView = this->pDocView;
  pObject = this->pDocView->pDocumentListener.pObject;
  if ( !pObject || (v4 = (pObject->HandlersMask & 1) == 0, v5 = 1, v4) )
    v5 = 0;
  this->HasLineFormatHandler = v5;
  this->pTextBufForCustomFormat = 0i64;
  if ( v5 )
  {
    pParagraph = this->pParagraph;
    Size = pParagraph->Text.Size;
    if ( Size )
    {
      v8 = Size - 1;
      if ( !pParagraph->Text.pText || (v9 = v8 < Size, v10 = &pParagraph->Text.pText[v8], !v9) )
        v10 = 0i64;
      if ( !*v10 )
        --Size;
    }
    ComposStrPosition = this->LineCursor.ComposStrPosition;
    StartIndex = pParagraph->StartIndex;
    if ( ComposStrPosition < StartIndex )
      goto LABEL_26;
    v13 = pParagraph->Text.Size;
    if ( v13 )
    {
      v14 = v13 - 1;
      if ( !pParagraph->Text.pText || (v9 = v14 < v13, v15 = &pParagraph->Text.pText[v14], !v9) )
        v15 = 0i64;
      if ( !*v15 )
        --v13;
    }
    if ( ComposStrPosition > StartIndex + v13 )
    {
LABEL_26:
      v17 = 0;
    }
    else
    {
      v16 = pParagraph->Text.Size;
      v17 = 1;
      if ( v16 )
      {
        v18 = v16 - 1;
        if ( !pParagraph->Text.pText || (v9 = v18 < v16, v19 = &pParagraph->Text.pText[v18], !v9) )
          v19 = 0i64;
        if ( !*v19 )
          --v16;
      }
      Size = v16 + this->LineCursor.ComposStrLength;
    }
    if ( Size >= 0x100 )
    {
      Allocator = Scaleform::Render::Text::StyledText::GetAllocator(pDocView->pDocument.pObject);
      TextBufForCustomFormat = (wchar_t *)Allocator->pHeap->vfptr->Alloc(Allocator->pHeap, 2 * Size + 2, 0i64);
    }
    else
    {
      TextBufForCustomFormat = this->TextBufForCustomFormat;
    }
    if ( !v17 || !this->LineCursor.ComposStrLength )
      memmove(TextBufForCustomFormat, this->pParagraph->Text.pText, 2 * Size);
    TextBufForCustomFormat[Size] = 0;
    this->pTextBufForCustomFormat = TextBufForCustomFormat;
    this->TextBufLen = Size;
  }
}

// File Line: 1318
// RVA: 0x97FC70
float __fastcall Scaleform::Render::Text::ParagraphFormatter::GetActualFontSize(
        Scaleform::Render::Text::ParagraphFormatter *this)
{
  float FontScaleFactor; // xmm1_4
  float result; // xmm0_4

  FontScaleFactor = this->FindFontInfo.pCurrentFont.pObject->FontScaleFactor;
  result = (float)this->FindFontInfo.pCurrentFormat->FontSize * 0.050000001;
  if ( FontScaleFactor != 1.0 )
    result = result * FontScaleFactor;
  if ( (this->pDocView->RTFlags & 4) != 0 )
    return result * (float)((float)this->pDocView->FontScaleFactor * 0.050000001);
  return result;
}

// File Line: 1405
// RVA: 0x978070
void __fastcall Scaleform::Render::Text::ParagraphFormatter::FinalizeLine(
        Scaleform::Render::Text::ParagraphFormatter *this)
{
  float LastAdvance; // xmm0_4
  float v3; // xmm0_4
  int v4; // r8d
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pPrevGrec; // rcx
  Scaleform::Render::Text::ParagraphFormat *pParaFormat; // rcx
  int RightMargin; // eax
  float MaxFontLeading; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  unsigned int v11; // r12d
  float v12; // xmm0_4
  int v13; // r13d
  int LineWidth; // ecx
  int LineWidthWithoutTrailingSpaces; // eax
  __int64 GlyphIndex; // rbp
  __int64 FormatDataIndex; // r15
  Scaleform::Render::Text::LineBuffer::Iterator *pLinesIter; // rbx
  unsigned __int64 v19; // rax
  Scaleform::Render::Text::LineBuffer::Line *inserted; // rax
  unsigned __int64 Size; // rax
  Scaleform::Render::Text::LineBuffer::Line *v22; // rsi
  unsigned int UniqueId; // edx
  bool v24; // cl
  unsigned __int16 ModCounter; // dx
  Scaleform::Render::Text::LineBuffer::Line *pTempLine; // rdx
  const void *v27; // rdx
  bool v28; // zf
  void *v29; // rcx
  Scaleform::Render::Text::LineBuffer::Line *v30; // rax
  char *v31; // rdx
  unsigned int GlyphsCount; // ecx
  char *v33; // r9
  char *v34; // rcx
  __int64 v35; // rax
  Scaleform::Render::Text::LineBuffer::Line *v36; // rcx
  unsigned int v37; // eax
  int TextPos; // ecx
  unsigned int LineLength; // ecx
  int MaxFontAscent; // eax
  unsigned int v41; // ecx
  Scaleform::Render::Text::ParagraphFormat *v42; // rax
  int v43; // ebp
  int v44; // r14d
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // rcx
  unsigned __int16 Flags; // dx
  int Advance; // eax
  int v48; // eax
  Scaleform::Render::Text::ImageDesc *pObject; // rcx
  Scaleform::Render::Text::FontHandle *v50; // rcx
  int v51; // r8d
  int NextOffsetY; // ecx
  unsigned int MemSize; // ecx
  signed int v54; // ecx
  int v55; // eax
  signed int v56; // ecx
  int v57; // eax
  int LeftMargin; // ecx
  float v59; // xmm1_4
  float v60; // xmm1_4
  bool v61; // sf
  int v62; // eax
  signed int v63; // ecx
  int v64; // eax
  float TextRectWidth; // xmm0_4
  float v66; // xmm0_4
  int ParaWidth; // ecx
  int v68; // ecx
  double v69; // xmm1_8
  double v70; // xmm1_8
  Scaleform::Render::Text::FontHandle *v71; // rcx
  Scaleform::Render::Text::LineBuffer::GlyphIterator result; // [rsp+40h] [rbp-E8h] BYREF

  LastAdvance = this->LineCursor.LastAdvance;
  if ( LastAdvance <= 0.0 )
    v3 = LastAdvance - 0.5;
  else
    v3 = LastAdvance + 0.5;
  v4 = (int)v3;
  pPrevGrec = this->LineCursor.pPrevGrec;
  if ( pPrevGrec )
  {
    if ( v4 < 0 )
    {
      pPrevGrec->Advance = abs32(v4);
      pPrevGrec->Flags |= 0x40u;
    }
    else
    {
      pPrevGrec->Advance = v4;
      pPrevGrec->Flags &= ~0x40u;
    }
  }
  if ( this->LineCursor.pLastFont.pObject )
    this->LineCursor.LineWidth += this->LineCursor.LastGlyphWidth;
  else
    this->LineCursor.LineWidth += v4;
  pParaFormat = this->pParaFormat;
  if ( (pParaFormat->PresentMask & 1) != 0
    && ((pParaFormat->PresentMask & 0x600) == 512
     || (pParaFormat->PresentMask & 1) != 0 && (pParaFormat->PresentMask & 0x600) == 1536) )
  {
    RightMargin = this->LineCursor.RightMargin;
    this->LineCursor.LineWidth += RightMargin;
    this->LineCursor.LineWidthWithoutTrailingSpaces += RightMargin;
  }
  if ( (pParaFormat->PresentMask & 8) != 0 )
    MaxFontLeading = (float)pParaFormat->Leading * 20.0;
  else
    MaxFontLeading = this->LineCursor.MaxFontLeading;
  v9 = this->LineCursor.MaxFontDescent + this->LineCursor.MaxFontAscent;
  if ( v9 <= 0.0 )
    v10 = v9 - 0.5;
  else
    v10 = v9 + 0.5;
  v11 = (int)v10;
  if ( MaxFontLeading <= 0.0 )
    v12 = MaxFontLeading - 0.5;
  else
    v12 = MaxFontLeading + 0.5;
  v13 = (int)v12;
  LineWidth = this->LineCursor.LineWidth;
  if ( LineWidth < 0 )
    LineWidth = 0;
  this->LineCursor.LineWidth = LineWidth;
  LineWidthWithoutTrailingSpaces = this->LineCursor.LineWidthWithoutTrailingSpaces;
  if ( LineWidthWithoutTrailingSpaces < 0 )
    LineWidthWithoutTrailingSpaces = 0;
  this->LineCursor.LineWidthWithoutTrailingSpaces = LineWidthWithoutTrailingSpaces;
  GlyphIndex = this->LineCursor.GlyphIns.GlyphIndex;
  FormatDataIndex = this->LineCursor.GlyphIns.FormatDataIndex;
  if ( (this->pDocView->AlignProps & 0x30) != 0
    || this->LineCursor.LineLength > 0xFF
    || (unsigned int)GlyphIndex > 0xFF
    || (unsigned int)(v13 + 128) > 0xFF
    || v11 > 0xFFFF
    || (unsigned int)LineWidth > 0xFFFF )
  {
    pLinesIter = this->pLinesIter;
    LODWORD(Size) = pLinesIter->CurrentPos;
    if ( (Size & 0x80000000) != 0i64 )
      Size = pLinesIter->pLineBuffer->Lines.Data.Size;
    inserted = Scaleform::Render::Text::LineBuffer::InsertNewLine(
                 pLinesIter->pLineBuffer,
                 Size,
                 GlyphIndex,
                 FormatDataIndex,
                 Line32);
  }
  else
  {
    pLinesIter = this->pLinesIter;
    LODWORD(v19) = pLinesIter->CurrentPos;
    if ( (v19 & 0x80000000) != 0i64 )
      v19 = pLinesIter->pLineBuffer->Lines.Data.Size;
    inserted = Scaleform::Render::Text::LineBuffer::InsertNewLine(
                 pLinesIter->pLineBuffer,
                 v19,
                 GlyphIndex,
                 FormatDataIndex,
                 Line8);
  }
  ++pLinesIter->CurrentPos;
  v22 = inserted;
  UniqueId = this->LineCursor.pParagraph->UniqueId;
  v24 = (inserted->MemSize & 0x80000000) != 0;
  if ( (inserted->MemSize & 0x80000000) == 0 )
    inserted->Data32.ParagraphId = UniqueId;
  else
    inserted->Data32.GlyphsCount = UniqueId;
  ModCounter = this->LineCursor.pParagraph->ModCounter;
  if ( v24 )
    inserted->Data8.ParagraphModId = ModCounter;
  else
    inserted->Data32.ParagraphModId = ModCounter;
  pTempLine = this->pTempLine;
  if ( (pTempLine->MemSize & 0x80000000) == 0 )
    v27 = (char *)&pTempLine->Data8 + 38;
  else
    v27 = &pTempLine->Data8.Leading + 1;
  v28 = !v24;
  v29 = &inserted->Data8.Leading + 1;
  if ( v28 )
    v29 = (char *)&inserted->Data8 + 38;
  memmove(v29, v27, 8 * GlyphIndex);
  v30 = this->pTempLine;
  v31 = &v30->Data8.Leading + 1;
  if ( (v30->MemSize & 0x80000000) == 0 )
    v31 = (char *)&v30->Data8 + 38;
  if ( (v30->MemSize & 0x80000000) == 0 )
    GlyphsCount = v30->Data32.GlyphsCount;
  else
    GlyphsCount = (unsigned __int8)v30->Data8.GlyphsCount;
  v33 = &v31[8 * GlyphsCount];
  v34 = &v22->Data8.Leading + 1;
  if ( (v22->MemSize & 0x80000000) == 0 )
    v34 = (char *)&v22->Data8 + 38;
  if ( (v22->MemSize & 0x80000000) == 0 )
    v35 = v22->Data32.GlyphsCount;
  else
    v35 = (unsigned __int8)v22->Data8.GlyphsCount;
  memmove(
    (void *)((unsigned __int64)&v34[8 * v35 + 7] & 0xFFFFFFFFFFFFFFF8ui64),
    (const void *)((unsigned __int64)(v33 + 7) & 0xFFFFFFFFFFFFFFF8ui64),
    8 * FormatDataIndex);
  v36 = this->pTempLine;
  v37 = v36->MemSize >> 31;
  TextPos = v36->Data32.TextPos;
  if ( (v37 & 1) != 0 )
  {
    TextPos &= 0xFFFFFFu;
    if ( TextPos == 0xFFFFFF )
      TextPos = -1;
  }
  if ( (v22->MemSize & 0x80000000) == 0 )
  {
    v22->Data32.TextPos = TextPos;
  }
  else
  {
    v22->Data32.TextPos &= 0xFF000000;
    v22->Data32.TextPos |= TextPos & 0xFFFFFF;
  }
  LineLength = this->LineCursor.LineLength;
  if ( (v22->MemSize & 0x80000000) == 0 )
    v22->Data32.TextLength = LineLength;
  else
    HIBYTE(v22->Data8.TextPosAndLength) = LineLength;
  MaxFontAscent = (int)this->LineCursor.MaxFontAscent;
  if ( (v22->MemSize & 0x80000000) == 0 )
    v22->Data32.BaseLineOffset = MaxFontAscent;
  else
    v22->Data8.BaseLineOffset = MaxFontAscent;
  if ( !this->LineCursor.LineHasNewLine && (this->pDocView->Flags & 8) != 0 )
  {
    v41 = this->LineCursor.NumOfSpaces - this->LineCursor.NumOfTrailingSpaces;
    if ( v41 )
    {
      v42 = this->pParaFormat;
      if ( (v42->PresentMask & 1) != 0 && (v42->PresentMask & 0x600) == 1024 )
      {
        v43 = (int)(float)(this->TextRectWidth - 30.0)
            - this->LineCursor.RightMargin
            - this->LineCursor.LeftMargin
            - this->LineCursor.Indent
            - this->LineCursor.LineWidthWithoutTrailingSpaces;
        if ( v43 > 0 )
        {
          v44 = v43 / v41;
          Scaleform::Render::Text::LineBuffer::Line::Begin(v22, &result);
          while ( 1 )
          {
            pGlyphs = result.pGlyphs;
            if ( !result.pGlyphs || result.pGlyphs >= result.pEndGlyphs )
              break;
            Flags = result.pGlyphs->Flags;
            if ( (Flags & 2) != 0 )
            {
              Advance = result.pGlyphs->Advance;
              if ( (Flags & 0x40) != 0 )
                Advance = -Advance;
              v48 = v44 + Advance;
              if ( v48 < 0 )
              {
                LOWORD(v48) = abs32(v48);
                result.pGlyphs->Flags |= 0x40u;
              }
              else
              {
                result.pGlyphs->Flags &= ~0x40u;
              }
              pGlyphs->Advance = v48;
            }
            Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&result);
          }
          this->LineCursor.LineWidth += v43;
          pObject = result.pImage.pObject;
          if ( result.pImage.pObject )
          {
            --result.pImage.pObject->RefCount;
            if ( !pObject->RefCount )
              pObject->vfptr->__vecDelDtor(pObject, 1u);
          }
          v50 = result.pFontHandle.pObject;
          if ( result.pFontHandle.pObject && !_InterlockedDecrement(&result.pFontHandle.pObject->RefCount) && v50 )
            v50->vfptr->__vecDelDtor(v50, 1u);
        }
      }
    }
  }
  v51 = this->LineCursor.Indent + this->LineCursor.LeftMargin;
  NextOffsetY = this->NextOffsetY;
  v22->Data32.OffsetX = v51;
  v22->Data32.OffsetY = NextOffsetY;
  MemSize = v22->MemSize;
  if ( (v22->MemSize & 0x80000000) == 0 )
    v22->Data32.Leading = v13;
  else
    v22->Data8.Leading = v13;
  if ( ((this->pParaFormat->PresentMask >> 9) & 3) == 1 )
  {
    v63 = MemSize & 0xE7FFFFFF | 0x8000000;
    v22->MemSize = v63;
    v64 = this->LineCursor.LineWidthWithoutTrailingSpaces;
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
    TextRectWidth = this->TextRectWidth;
    if ( TextRectWidth <= 0.0 )
      v66 = TextRectWidth - 0.5;
    else
      v66 = TextRectWidth + 0.5;
    v61 = (int)v66 - this->LineCursor.LineWidthWithoutTrailingSpaces < 0;
    v62 = (int)v66 - this->LineCursor.LineWidthWithoutTrailingSpaces;
  }
  else
  {
    if ( ((this->pParaFormat->PresentMask >> 9) & 3) != 3 )
    {
      v54 = MemSize & 0xE7FFFFFF;
      v22->MemSize = v54;
      v55 = this->LineCursor.LineWidth;
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
      goto LABEL_125;
    }
    v56 = MemSize & 0xE7FFFFFF | 0x10000000;
    v22->MemSize = v56;
    v57 = this->LineCursor.LineWidthWithoutTrailingSpaces;
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
    LeftMargin = this->LineCursor.LeftMargin;
    v59 = (float)((float)(this->TextRectWidth - (float)LeftMargin) * 0.5)
        - (float)(this->LineCursor.LineWidthWithoutTrailingSpaces / 2);
    if ( v59 <= 0.0 )
      v60 = v59 - 0.5;
    else
      v60 = v59 + 0.5;
    v61 = LeftMargin + (int)v60 < 0;
    v62 = LeftMargin + (int)v60;
  }
  if ( v61 )
    v62 = 0;
  v22->Data32.OffsetX = v62;
  if ( (this->pDocView->Flags & 1) != 0 || (this->pDocView->AlignProps & 0x30) != 0 )
    this->NeedRecenterLines = 1;
LABEL_125:
  ParaWidth = v51 + this->LineCursor.LineWidth;
  if ( ParaWidth < this->ParaWidth )
    ParaWidth = this->ParaWidth;
  this->ParaWidth = ParaWidth;
  v68 = this->NextOffsetY;
  this->ParaHeight = v11 + v68 - this->ParaYOffset;
  v69 = (double)(int)(v11 + v13);
  if ( v69 <= 0.0 )
    v70 = v69 - 0.5;
  else
    v70 = v69 + 0.5;
  this->NextOffsetY = v68 + (int)v70;
  this->LineCursor.Indent = 0;
  this->LineCursor.GlyphIns.FormatDataIndex = 0;
  this->LineCursor.GlyphIns.GlyphIndex = 0;
  this->LineCursor.LastColor = 0;
  v71 = this->LineCursor.pLastFont.pObject;
  if ( v71 && !_InterlockedDecrement(&v71->RefCount) )
    v71->vfptr->__vecDelDtor(v71, 1u);
  this->LineCursor.pLastFont.pObject = 0i64;
}

// File Line: 1567
// RVA: 0x990920
char __fastcall Scaleform::Render::Text::ParagraphFormatter::HandleCustomWordWrap(
        Scaleform::Render::Text::ParagraphFormatter *this)
{
  Scaleform::Render::Text::FontHandle *pObject; // rdi
  int Pass; // eax
  Scaleform::Render::Text::Paragraph::TextBuffer *pText; // rax
  __m128i v5; // xmm2
  Scaleform::Render::Font *v6; // rdi
  unsigned __int64 *NumChars; // rsi
  unsigned int v8; // xmm2_4
  Scaleform::Render::Text::LineBuffer::Line *pTempLine; // rcx
  __int64 TextPos; // rcx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // eax
  char *v15; // r13
  Scaleform::Render::Text::Allocator *Allocator; // rax
  unsigned int v17; // r10d
  unsigned int GlyphIndex; // edi
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // rsi
  float v20; // xmm2_4
  __int64 v21; // r9
  unsigned __int16 *v22; // rcx
  unsigned __int16 *p_Flags; // rdx
  unsigned __int16 *p_LenAndFontSize; // r8
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  unsigned __int16 *p_Advance; // rcx
  int v30; // eax
  float v31; // xmm1_4
  __int64 v32; // r11
  __int64 v33; // rdi
  float *v34; // rcx
  int v35; // eax
  unsigned int v36; // r10d
  __int64 v37; // rdx
  __int64 v38; // r8
  char v39; // r15
  unsigned __int64 v40; // rdx
  Scaleform::Render::Text::Paragraph::TextBuffer *v41; // rax
  Scaleform::Render::Text::GFxLineCursor *p_WordWrapPoint; // rdx
  Scaleform::Render::Text::Paragraph::TextBuffer *v43; // rax
  __int64 v44; // rdx
  unsigned int v45; // r9d
  Scaleform::Render::Text::GFxLineCursor *v46; // rax
  Scaleform::Render::Text::TextFormat *Index; // rdi
  bool v48; // zf
  Scaleform::Render::Text::TextFormat *ComposStrLength; // rdi
  Scaleform::Render::Text::FontHandle *v50; // rcx
  Scaleform::Render::Text::GFxLineCursor *v52; // rax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v53; // rdi
  float LastAdvance; // xmm0_4
  float v55; // xmm0_4
  int v56; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pPrevGrec; // rcx
  unsigned int v58; // esi
  unsigned __int16 LenAndFontSize; // dx
  float FontSize; // xmm1_4
  int v61; // ecx
  double v62; // xmm0_8
  float v63; // xmm7_4
  float v64; // xmm1_4
  float v65; // xmm1_4
  unsigned int v66; // eax
  __int64 v67[4]; // [rsp+20h] [rbp-A8h] BYREF
  unsigned __int64 v68; // [rsp+40h] [rbp-88h]
  __int64 v69; // [rsp+48h] [rbp-80h]
  __int64 v70; // [rsp+50h] [rbp-78h]
  __int64 v71; // [rsp+58h] [rbp-70h]
  __int64 v72; // [rsp+60h] [rbp-68h]
  _BOOL8 v73; // [rsp+68h] [rbp-60h]
  Scaleform::Render::Text::GFxLineCursor __that; // [rsp+70h] [rbp-58h] BYREF
  char v75[1128]; // [rsp+268h] [rbp+1A0h] BYREF
  unsigned __int64 *p_Index; // [rsp+6D8h] [rbp+610h]
  unsigned __int64 *p_ComposStrLength; // [rsp+6E0h] [rbp+618h]

  *(_QWORD *)&__that.GlyphIns.FormatDataIndex = -2i64;
  pObject = this->LineCursor.pLastFont.pObject;
  if ( pObject )
  {
    Pass = this->Pass;
    if ( Pass == 1 && this->HasLineFormatHandler )
    {
      pText = this->WordWrapPoint.CharIter.pText;
      if ( pText && this->WordWrapPoint.CharIter.CurTextIndex < pText->Size )
      {
        v5 = _mm_cvtsi32_si128(this->WordWrapPoint.LineWidth);
        v6 = this->WordWrapPoint.pLastFont.pObject->pFont.pObject;
        NumChars = (unsigned __int64 *)this->WordWrapPoint.NumChars;
      }
      else
      {
        v5 = _mm_cvtsi32_si128(this->LineCursor.LineWidth);
        v6 = pObject->pFont.pObject;
        NumChars = (unsigned __int64 *)this->LineCursor.NumChars;
      }
      p_Index = NumChars;
      v8 = _mm_cvtepi32_ps(v5).m128_u32[0];
      v67[0] = (__int64)this->pTextBufForCustomFormat;
      v67[1] = this->TextBufLen;
      pTempLine = this->pTempLine;
      if ( (pTempLine->MemSize & 0x80000000) == 0 )
      {
        TextPos = pTempLine->Data32.TextPos;
      }
      else
      {
        TextPos = pTempLine->Data32.TextPos & 0xFFFFFF;
        if ( (_DWORD)TextPos == 0xFFFFFF )
          TextPos = 0xFFFFFFFFi64;
      }
      v67[3] = TextPos - this->pParagraph->StartIndex;
      v68 = this->LineCursor.NumChars;
      v11 = (this->pParaFormat->PresentMask >> 9) & 3;
      if ( v11 )
      {
        v12 = v11 - 1;
        if ( v12 )
        {
          v13 = v12 - 1;
          if ( v13 )
          {
            if ( v13 == 1 )
              LOBYTE(v71) = 2;
          }
          else
          {
            LOBYTE(v71) = 3;
          }
        }
        else
        {
          LOBYTE(v71) = 1;
        }
      }
      else
      {
        LOBYTE(v71) = 0;
      }
      *(float *)&v69 = this->TextRectWidth;
      *((float *)&v69 + 1) = (float)this->LineCursor.LineWidth;
      LODWORD(v70) = v8;
      v14 = (int)v6->vfptr[2].__vecDelDtor(v6, 45u);
      if ( v14 > 0 )
        HIDWORD(v70) = ((float (__fastcall *)(Scaleform::Render::Font *, _QWORD))v6->vfptr[5].__vecDelDtor)(
                         v6,
                         (unsigned int)v14);
      v72 = (__int64)NumChars;
      v15 = v75;
      if ( v68 + 1 > 0x100 )
      {
        Allocator = Scaleform::Render::Text::StyledText::GetAllocator(this->pDocView->pDocument.pObject);
        v15 = (char *)Allocator->pHeap->vfptr->Alloc(Allocator->pHeap, 4 * v68 + 4, 0i64);
      }
      v17 = 0;
      GlyphIndex = this->LineCursor.GlyphIns.GlyphIndex;
      pGlyphs = this->LineCursor.GlyphIns.pGlyphs;
      v20 = 0.0;
      v21 = 0i64;
      if ( (int)GlyphIndex < 4 )
      {
LABEL_44:
        if ( v17 < GlyphIndex )
        {
          p_Advance = &pGlyphs[v21].Advance;
          do
          {
            if ( (p_Advance[1] & 0xF000) != 0 )
              break;
            v30 = *p_Advance;
            if ( (p_Advance[2] & 0x40) != 0 )
              v30 = -v30;
            v20 = v20 + (float)v30;
            p_Advance += 4;
            ++v17;
          }
          while ( v17 < GlyphIndex );
        }
      }
      else
      {
        v22 = &pGlyphs->Advance;
        p_Flags = &pGlyphs->Flags;
        p_LenAndFontSize = &pGlyphs->LenAndFontSize;
        while ( (*p_LenAndFontSize & 0xF000) == 0 )
        {
          v25 = *v22;
          if ( (*(_BYTE *)p_Flags & 0x40) != 0 )
            v25 = -v25;
          v20 = v20 + (float)v25;
          if ( (p_LenAndFontSize[4] & 0xF000) != 0 )
          {
            ++v17;
            break;
          }
          v26 = v22[4];
          if ( (p_Flags[4] & 0x40) != 0 )
            v26 = -v26;
          v20 = v20 + (float)v26;
          if ( (p_LenAndFontSize[8] & 0xF000) != 0 )
          {
            v17 += 2;
            break;
          }
          v27 = v22[8];
          if ( (p_Flags[8] & 0x40) != 0 )
            v27 = -v27;
          v20 = v20 + (float)v27;
          if ( (p_LenAndFontSize[12] & 0xF000) != 0 )
          {
            v17 += 3;
            break;
          }
          v28 = v22[12];
          if ( (p_Flags[12] & 0x40) != 0 )
            v28 = -v28;
          v20 = v20 + (float)v28;
          v21 += 4i64;
          p_LenAndFontSize += 16;
          p_Flags += 16;
          v22 += 16;
          v17 += 4;
          if ( v17 >= GlyphIndex - 3 )
            goto LABEL_44;
        }
      }
      v67[2] = (__int64)v15;
      *(float *)&v69 = *(float *)&v69 - v20;
      *((float *)&v69 + 1) = *((float *)&v69 + 1) - v20;
      *(float *)&v70 = *(float *)&v70 - v20;
      v31 = 0.0;
      v32 = 0i64;
      if ( v17 < GlyphIndex )
      {
        v21 = (__int64)&pGlyphs[v17].Advance;
        v33 = GlyphIndex - v17;
        do
        {
          v34 = (float *)&v15[4 * v32];
          *v34 = v31;
          v35 = *(unsigned __int16 *)v21;
          if ( (*(_BYTE *)(v21 + 4) & 0x40) != 0 )
            v35 = -v35;
          v31 = v31 + (float)v35;
          v36 = *(unsigned __int16 *)(v21 + 2) >> 12;
          if ( v36 >= 2 )
          {
            v37 = v32;
            v38 = v36;
            do
            {
              this->pTextBufForCustomFormat[v37] = 160;
              *v34 = 0.0;
              ++v37;
              ++v34;
              --v38;
            }
            while ( v38 );
          }
          v32 += v36;
          v21 += 8i64;
          --v33;
        }
        while ( v33 );
      }
      *(float *)&v15[4 * v32] = v31;
      LOBYTE(v73) = 0;
      v39 = ((__int64 (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::Render::Text::DocView *, __int64 *, __int64))this->pDocView->pDocumentListener.pObject->vfptr[1].__vecDelDtor)(
              this->pDocView->pDocumentListener.pObject,
              this->pDocView,
              v67,
              v21);
      if ( v39 )
      {
        this->HyphenationRequested = v73;
        v40 = v72;
        if ( !v72 )
          v40 = 1i64;
        v72 = v40;
        if ( (unsigned __int64 *)v40 != p_Index )
        {
          v41 = this->WordWrapPoint.CharIter.pText;
          if ( v41 && this->WordWrapPoint.CharIter.CurTextIndex < v41->Size && v40 > this->WordWrapPoint.NumChars )
          {
            Scaleform::Render::Text::LineBuffer::GlyphInserter::ResetTo(
              &this->LineCursor.GlyphIns,
              &this->WordWrapPoint.GlyphIns);
            p_WordWrapPoint = &this->WordWrapPoint;
          }
          else
          {
            v43 = this->HalfPoint.CharIter.pText;
            if ( v43 && this->HalfPoint.CharIter.CurTextIndex < v43->Size && v40 > this->HalfPoint.NumChars )
            {
              Scaleform::Render::Text::LineBuffer::GlyphInserter::ResetTo(
                &this->LineCursor.GlyphIns,
                &this->HalfPoint.GlyphIns);
              p_WordWrapPoint = &this->HalfPoint;
            }
            else
            {
              v44 = this->StartPoint.GlyphIns.GlyphIndex;
              v45 = this->LineCursor.GlyphIns.GlyphIndex;
              if ( (unsigned int)v44 < v45 && this->LineCursor.GlyphIns.GlyphsCount )
                Scaleform::Render::Text::LineBuffer::ReleasePartOfLine(
                  &this->StartPoint.GlyphIns.pGlyphs[v44],
                  v45 - v44,
                  &this->StartPoint.GlyphIns.pNextFormatData[this->StartPoint.GlyphIns.FormatDataIndex]);
              this->LineCursor.GlyphIns.pGlyphs = this->StartPoint.GlyphIns.pGlyphs;
              this->LineCursor.GlyphIns.pNextFormatData = this->StartPoint.GlyphIns.pNextFormatData;
              this->LineCursor.GlyphIns.GlyphIndex = this->StartPoint.GlyphIns.GlyphIndex;
              this->LineCursor.GlyphIns.GlyphsCount = this->StartPoint.GlyphIns.GlyphsCount;
              this->LineCursor.GlyphIns.FormatDataIndex = this->StartPoint.GlyphIns.FormatDataIndex;
              p_WordWrapPoint = &this->StartPoint;
            }
          }
          Scaleform::Render::Text::GFxLineCursor::operator=(&this->LineCursor, p_WordWrapPoint);
          this->Pass = 2;
          this->RequestedWordWrapPos = v72;
          this->DeltaText = 0;
        }
      }
      if ( v15 != v75 )
      {
        Scaleform::Render::Text::StyledText::GetAllocator(this->pDocView->pDocument.pObject);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v15);
      }
      v69 = 0i64;
      v70 = 0i64;
      v71 = 0i64;
      v72 = -1i64;
      v73 = 0i64;
      memset(&__that, 0, 66);
      p_ComposStrLength = &__that.ComposStrLength;
      __that.pParagraph = 0i64;
      *(_QWORD *)&__that.LineWidth = 0i64;
      *(_QWORD *)&__that.LineLength = -1i64;
      memset(&__that.MaxFontDescent, 0, 34);
      p_Index = &__that.CharIter.PlaceHolder.Index;
      __that.CharIter.FormatIterator.pArray = 0i64;
      LODWORD(__that.CharIter.FormatIterator.Index) = 0;
      memset(&__that.CharIter.pText, 0, 28);
      *(_QWORD *)&__that.CharInfoHolder.Character = 0i64;
      __that.Indent = (int)FLOAT_1_0;
      LOWORD(__that.LeftMargin) = 0;
      *(_QWORD *)&__that.RightMargin = 0i64;
      v46 = Scaleform::Render::Text::GFxLineCursor::operator=(&this->HalfPoint, &__that);
      Scaleform::Render::Text::GFxLineCursor::operator=(&this->StartPoint, v46);
      p_Index = &__that.CharIter.PlaceHolder.Index;
      Index = (Scaleform::Render::Text::TextFormat *)__that.CharIter.PlaceHolder.Index;
      if ( __that.CharIter.PlaceHolder.Index )
      {
        v48 = (*(_DWORD *)(__that.CharIter.PlaceHolder.Index + 8))-- == 1;
        if ( v48 )
        {
          Scaleform::Render::Text::TextFormat::~TextFormat(Index);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, Index);
        }
      }
      p_Index = &__that.ComposStrLength;
      ComposStrLength = (Scaleform::Render::Text::TextFormat *)__that.ComposStrLength;
      if ( __that.ComposStrLength )
      {
        v48 = (*(_DWORD *)(__that.ComposStrLength + 8))-- == 1;
        if ( v48 )
        {
          Scaleform::Render::Text::TextFormat::~TextFormat(ComposStrLength);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ComposStrLength);
        }
      }
      v50 = __that.pLastFont.pObject;
      if ( __that.pLastFont.pObject
        && _InterlockedExchangeAdd(&__that.pLastFont.pObject->RefCount, 0xFFFFFFFF) == 1
        && v50 )
      {
        v50->vfptr->__vecDelDtor(v50, 1u);
      }
      if ( v39 && this->Pass == 2 )
        return 1;
    }
    else if ( Pass == 2 )
    {
      Scaleform::Render::Text::GFxLineCursor::GFxLineCursor((Scaleform::Render::Text::GFxLineCursor *)&__that.NumOfSpaces);
      Scaleform::Render::Text::GFxLineCursor::operator=(&this->WordWrapPoint, v52);
      Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor((Scaleform::Render::Text::GFxLineCursor *)&__that.NumOfSpaces);
      this->Pass = 1;
    }
    if ( this->HyphenationRequested )
    {
      v53 = &this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex];
      *v53 = 0i64;
      LastAdvance = this->LineCursor.LastAdvance;
      if ( LastAdvance <= 0.0 )
        v55 = LastAdvance - 0.5;
      else
        v55 = LastAdvance + 0.5;
      v56 = (int)v55;
      pPrevGrec = this->LineCursor.pPrevGrec;
      if ( pPrevGrec )
      {
        if ( v56 < 0 )
        {
          pPrevGrec->Advance = abs32(v56);
          pPrevGrec->Flags |= 0x40u;
        }
        else
        {
          pPrevGrec->Advance = v56;
          pPrevGrec->Flags &= ~0x40u;
        }
      }
      v58 = (unsigned int)this->LineCursor.pLastFont.pObject->pFont.pObject->vfptr[2].__vecDelDtor(
                            this->LineCursor.pLastFont.pObject->pFont.pObject,
                            45i64);
      v53->Index = v58;
      v53->LenAndFontSize &= 0xFFFu;
      LenAndFontSize = v53->LenAndFontSize;
      FontSize = this->FontSize;
      if ( FontSize < 256.0 && (v61 = (int)(float)(FontSize * 16.0), (v61 & 0xF) != 0) )
      {
        v53->Flags |= 0x10u;
        v53->LenAndFontSize = LenAndFontSize ^ (LenAndFontSize ^ v61) & 0xFFF;
      }
      else
      {
        v53->Flags &= ~0x10u;
        v53->LenAndFontSize = LenAndFontSize ^ (LenAndFontSize ^ (int)FontSize) & 0xFFF;
      }
      this->LineCursor.LineWidth = this->NewLineWidth;
      v62 = ((double (__fastcall *)(Scaleform::Render::Font *, _QWORD))this->LineCursor.pLastFont.pObject->pFont.pObject->vfptr[3].__vecDelDtor)(
              this->LineCursor.pLastFont.pObject->pFont.pObject,
              v58);
      v63 = *(float *)&v62 * this->Scale;
      *(_OWORD *)&__that.GlyphIns.pNextFormatData = 0i64;
      v64 = (float)(*(float *)(((__int64 (__fastcall *)(Scaleform::Render::Font *, _QWORD, Scaleform::Render::Text::LineBuffer::FormatDataEntry **))this->pFont->vfptr[7].__vecDelDtor)(
                                 this->pFont,
                                 v58,
                                 &__that.GlyphIns.pNextFormatData)
                             + 8)
                  * this->Scale)
          + 20.0;
      if ( v63 >= v64 )
        v64 = v63;
      if ( v64 <= 0.0 )
        v65 = v64 - 0.5;
      else
        v65 = v64 + 0.5;
      this->LineCursor.LastAdvance = (float)(int)v65;
      this->LineCursor.LastGlyphWidth = (int)v65;
      this->LineCursor.LastGlyphIndex = v58;
      this->LineCursor.NumOfTrailingSpaces = 0;
      this->LineCursor.LineWidthWithoutTrailingSpaces = this->NewLineWidth + (int)v65;
      this->HyphenationRequested = 0;
      this->LineCursor.pPrevGrec = v53;
      if ( this->LineCursor.GlyphIns.pGlyphs )
      {
        v66 = this->LineCursor.GlyphIns.GlyphIndex;
        if ( v66 < this->LineCursor.GlyphIns.GlyphsCount )
          this->LineCursor.GlyphIns.GlyphIndex = v66 + 1;
      }
    }
  }
  return 0;
}

// File Line: 1749
// RVA: 0x95EB30
char __fastcall Scaleform::Render::Text::ParagraphFormatter::CheckWordWrap(
        Scaleform::Render::Text::ParagraphFormatter *this)
{
  int Pass; // ecx
  char v3; // bp
  Scaleform::Render::Text::Paragraph::TextBuffer *pText; // rax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // rsi
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *pNextFormatData; // r14
  __int64 GlyphIndex; // rbx
  unsigned int GlyphsCount; // r15d
  __int64 FormatDataIndex; // rbp
  unsigned int v10; // edx
  Scaleform::Render::Text::GFxLineCursor *v11; // rax
  unsigned __int64 StartIndex; // rbx
  unsigned __int64 v13; // rbx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pPrevGrec; // rax
  Scaleform::Render::Text::LineBuffer::Line *pTempLine; // rcx
  Scaleform::Render::Text::GFxLineCursor v17; // [rsp+28h] [rbp-120h] BYREF

  Pass = this->Pass;
  if ( Pass == 1
    && (this->pDocView->Flags & 8) != 0
    && !this->isSpace
    && (float)(this->LineCursor.Indent + this->LineCursor.LeftMargin + this->AdjLineWidth + this->NewLineWidth) > (float)(this->TextRectWidth - (float)this->LineCursor.RightMargin)
    || Pass == 2 && this->LineCursor.NumChars == this->RequestedWordWrapPos )
  {
    if ( Scaleform::Render::Text::ParagraphFormatter::HandleCustomWordWrap(this) )
      return 1;
    this->NewLineWidth = 0;
    v3 = 0;
    pText = this->WordWrapPoint.CharIter.pText;
    if ( pText && this->WordWrapPoint.CharIter.CurTextIndex < pText->Size )
    {
      pGlyphs = this->WordWrapPoint.GlyphIns.pGlyphs;
      pNextFormatData = this->WordWrapPoint.GlyphIns.pNextFormatData;
      GlyphIndex = this->WordWrapPoint.GlyphIns.GlyphIndex;
      GlyphsCount = this->WordWrapPoint.GlyphIns.GlyphsCount;
      FormatDataIndex = this->WordWrapPoint.GlyphIns.FormatDataIndex;
      v10 = this->LineCursor.GlyphIns.GlyphIndex;
      if ( (unsigned int)GlyphIndex < v10 && this->LineCursor.GlyphIns.GlyphsCount )
        Scaleform::Render::Text::LineBuffer::ReleasePartOfLine(
          &pGlyphs[GlyphIndex],
          v10 - GlyphIndex,
          &pNextFormatData[FormatDataIndex]);
      this->LineCursor.GlyphIns.pGlyphs = pGlyphs;
      this->LineCursor.GlyphIns.pNextFormatData = pNextFormatData;
      this->LineCursor.GlyphIns.GlyphIndex = GlyphIndex;
      this->LineCursor.GlyphIns.GlyphsCount = GlyphsCount;
      this->LineCursor.GlyphIns.FormatDataIndex = FormatDataIndex;
      Scaleform::Render::Text::GFxLineCursor::operator=(&this->LineCursor, &this->WordWrapPoint);
      this->isSpace = 0;
      v3 = 1;
      this->DeltaText = 0;
    }
    Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&v17);
    Scaleform::Render::Text::GFxLineCursor::operator=(&this->WordWrapPoint, v11);
    Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(&v17);
    StartIndex = this->pParagraph->StartIndex;
    v13 = Scaleform::Render::Text::GFxLineCursor::operator*(&this->LineCursor)->Index + StartIndex;
    pPrevGrec = this->LineCursor.pPrevGrec;
    if ( pPrevGrec )
      pPrevGrec->Flags |= 8u;
    *(_QWORD *)&this->LineCursor.LastAdvance = 0i64;
    this->LineCursor.pPrevGrec = 0i64;
    Scaleform::Render::Text::ParagraphFormatter::FinalizeLine(this);
    this->LineCursor.pPrevGrec = 0i64;
    *(_QWORD *)&this->LineCursor.MaxFontDescent = 0i64;
    *(_QWORD *)&this->LineCursor.LineLength = 0i64;
    this->LineCursor.LastAdvance = 0.0;
    *(_WORD *)&this->LineCursor.LastKerning = 0;
    this->LineCursor.LineWidthWithoutTrailingSpaces = 0;
    *(_QWORD *)&this->LineCursor.NumOfSpaces = 0i64;
    this->LineCursor.NumChars = 0i64;
    this->LineCursor.LastCharCode = 0;
    this->TabStopsIndex = 0;
    pTempLine = this->pTempLine;
    if ( (pTempLine->MemSize & 0x80000000) == 0 )
    {
      pTempLine->Data32.TextPos = v13;
    }
    else
    {
      pTempLine->Data32.TextPos &= 0xFF000000;
      pTempLine->Data32.TextPos |= v13 & 0xFFFFFF;
    }
    if ( v3 )
    {
      this->LineCursor.LineWidth = 0;
      return 1;
    }
  }
  return 0;
}

// File Line: 1813
// RVA: 0x97BF20
void __fastcall Scaleform::Render::Text::ParagraphFormatter::Format(
        Scaleform::Render::Text::ParagraphFormatter *this,
        Scaleform::Render::Text::Paragraph *paragraph)
{
  Scaleform::Render::Text::ParagraphFormat *pParaFormat; // rdx
  __int16 PresentMask; // cx
  __int64 GlyphIndex; // rbx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // rdi
  Scaleform::Render::Text::Paragraph::CharacterInfo *v7; // rax
  Scaleform::Render::Text::TextFormat *pObject; // rcx
  Scaleform::Render::Text::FontHandle *Font; // rax
  Scaleform::Render::Text::FontHandle *v10; // rsi
  unsigned __int16 Flags; // r14
  float v12; // xmm0_4
  int v13; // eax
  unsigned __int16 v14; // r14
  unsigned int ColorV; // ebx
  unsigned int v16; // eax
  Scaleform::Render::Text::FontHandle *v17; // rcx
  Scaleform::Render::Text::ParagraphFormat *v18; // rdx
  unsigned int *p_TabStopsNum; // r12
  unsigned int *pTabStops; // rax
  Scaleform::Render::Text::LineBuffer::FormatDataEntry v21; // rbx
  Scaleform::Render::Text::Paragraph::TextBuffer *pText; // rax
  Scaleform::Render::Text::Paragraph::CharactersIterator *p_CharIter; // r14
  Scaleform::Render::Text::Paragraph::CharactersIterator *v24; // rsi
  Scaleform::Render::Text::TextFormat *v25; // rdi
  bool v26; // zf
  float TextRectWidth; // xmm6_4
  Scaleform::Render::Text::DocView::ImageSubstitutor *pImageSubstitutor; // r10
  Scaleform::Render::Text::Paragraph::TextBuffer *v29; // rax
  unsigned __int64 Size; // r8
  unsigned __int64 CurTextIndex; // rcx
  unsigned __int64 v32; // r8
  const wchar_t *v33; // rdx
  Scaleform::Render::Text::ImageDesc *ImageDesc; // rax
  Scaleform::Render::Text::TextFormat *v35; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v36; // rax
  Scaleform::Render::Text::HTMLImageTagDesc *v37; // rdi
  bool v38; // al
  wchar_t Character; // cx
  unsigned __int64 v40; // rax
  int v41; // r8d
  int v42; // eax
  bool v43; // al
  Scaleform::Render::Text::FontHandle *v44; // rcx
  Scaleform::Render::Text::FontHandle *v45; // rcx
  Scaleform::Render::Text::FontHandle *v46; // rax
  Scaleform::Render::Text::FontHandle *v47; // rdi
  Scaleform::Render::Text::FontHandle *v48; // rcx
  Scaleform::Render::Font *v49; // rdi
  float ActualFontSize; // xmm0_4
  wchar_t v51; // dx
  unsigned __int8 v52; // al
  int v53; // eax
  Scaleform::Render::Text::TextFormat *pCurrentFormat; // rcx
  __int16 v55; // r14
  bool v56; // si
  char v57; // di
  char v58; // bl
  Scaleform::StringDH *FontList; // rax
  __int64 v60; // r9
  __int64 v61; // r12
  Scaleform::Render::Text::DocView::DocumentListener *v62; // rcx
  Scaleform::String *v63; // rax
  int v64; // r14d
  const char *v65; // rsi
  unsigned __int64 v66; // rbx
  unsigned __int64 v67; // rdi
  Scaleform::StringDH *v68; // rax
  wchar_t v69; // cx
  unsigned __int64 v70; // rax
  int v71; // r8d
  int v72; // eax
  unsigned int v73; // eax
  float v74; // xmm0_4
  float v75; // xmm0_4
  float v76; // xmm0_4
  float GlyphAdvance; // xmm0_4
  float v78; // xmm0_4
  int v79; // eax
  float v80; // xmm0_4
  float v81; // xmm0_4
  float LastAdvance; // xmm1_4
  float v83; // xmm1_4
  int v84; // edx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pPrevGrec; // rcx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v86; // rdi
  float v87; // xmm1_4
  float MaxFontAscent; // xmm0_4
  float v89; // xmm0_4
  float MaxFontDescent; // xmm1_4
  Scaleform::Render::Text::TextFormat *v91; // rcx
  unsigned int v92; // esi
  float FontSize; // xmm1_4
  int v94; // eax
  unsigned __int16 v95; // ax
  Scaleform::Render::Text::FontHandle *v96; // rdx
  wchar_t v97; // dx
  unsigned __int8 v98; // al
  __int64 v99; // rdx
  Scaleform::Render::Text::TextFormat *v100; // rcx
  Scaleform::Render::Text::FontHandle *v101; // rcx
  Scaleform::Render::Text::FontHandle *v102; // rcx
  __int64 TabStopsIndex; // r8
  int v104; // edx
  int NewLineWidth; // eax
  __m128 FontSize_low; // xmm1
  int v107; // ecx
  float v108; // xmm1_4
  __m128 v109; // xmm3
  __m128 v110; // xmm2
  int v111; // ecx
  float v112; // xmm1_4
  Scaleform::Render::Text::TextFormat *v113; // rcx
  int GlyphWidth; // eax
  unsigned int v115; // eax
  unsigned int DeltaText; // eax
  __int64 v117; // rdi
  Scaleform::Render::Text::ParagraphFormatter *pTextBufForCustomFormat; // rcx
  __int64 v119; // [rsp+20h] [rbp-E0h]
  __int64 v120; // [rsp+30h] [rbp-D0h]
  int v121; // [rsp+50h] [rbp-B0h]
  __int64 v122; // [rsp+58h] [rbp-A8h]
  __int128 v123; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::String v124; // [rsp+70h] [rbp-90h] BYREF
  unsigned __int64 v125; // [rsp+78h] [rbp-88h]
  __int64 v126; // [rsp+80h] [rbp-80h] BYREF
  unsigned __int64 ptextLen; // [rsp+88h] [rbp-78h] BYREF
  int v128; // [rsp+90h] [rbp-70h] BYREF
  const char *v129; // [rsp+98h] [rbp-68h]
  __int64 v130; // [rsp+A0h] [rbp-60h]
  __int64 v131; // [rsp+A8h] [rbp-58h]
  __int64 v132; // [rsp+B0h] [rbp-50h]
  char v133; // [rsp+B8h] [rbp-48h]
  Scaleform::MemoryHeap *v134; // [rsp+C0h] [rbp-40h]
  Scaleform::Render::Text::FontHandle *v135; // [rsp+C8h] [rbp-38h]
  __int64 v136; // [rsp+D0h] [rbp-30h]
  __int64 v137; // [rsp+D8h] [rbp-28h]
  Scaleform::Render::Text::ImageDesc *v138; // [rsp+1C0h] [rbp+C0h]
  unsigned __int64 v139; // [rsp+1D0h] [rbp+D0h] BYREF
  __int64 v140; // [rsp+1D8h] [rbp+D8h] BYREF

  v136 = -2i64;
  v121 = 0;
  this->pDocView->RTFlags &= ~0x40u;
  Scaleform::Render::Text::ParagraphFormatter::InitParagraph(this, paragraph);
  this->LineCursor.LeftMargin = 0;
  pParaFormat = this->pParaFormat;
  PresentMask = pParaFormat->PresentMask;
  if ( (PresentMask & 0x80u) == 0 || PresentMask >= 0 )
  {
    this->LineCursor.Indent = 20 * pParaFormat->Indent;
  }
  else
  {
    GlyphIndex = this->LineCursor.GlyphIns.GlyphIndex;
    pGlyphs = this->LineCursor.GlyphIns.pGlyphs;
    pGlyphs[GlyphIndex] = 0i64;
    v7 = Scaleform::Render::Text::GFxLineCursor::operator*(&this->LineCursor);
    pObject = v7->pFormat.pObject;
    this->FindFontInfo.pCurrentFormat = v7->pFormat.pObject;
    if ( pObject )
    {
      Font = Scaleform::Render::Text::DocView::FindFont(this->pDocView, &this->FindFontInfo, 0);
      v10 = Font;
      if ( Font )
        _InterlockedExchangeAdd(&Font->RefCount, 1u);
      v135 = Font;
      pGlyphs[GlyphIndex].Index = (unsigned __int16)Font->pFont.pObject->vfptr[2].__vecDelDtor(
                                                      Font->pFont.pObject,
                                                      8226u);
      pGlyphs[GlyphIndex].Advance = 300;
      pGlyphs[GlyphIndex].Flags &= ~0x40u;
      Flags = pGlyphs[GlyphIndex].Flags;
      v12 = (float)(Scaleform::Render::Text::ParagraphFormatter::GetActualFontSize(this) * 2.0) * 0.33333334;
      if ( v12 < 256.0 && (v13 = (int)(float)(v12 * 16.0), (v13 & 0xF) != 0) )
      {
        v14 = Flags | 0x10;
      }
      else
      {
        v14 = Flags & 0xFFEF;
        v13 = (int)v12;
      }
      pGlyphs[GlyphIndex].LenAndFontSize &= 0xF000u;
      pGlyphs[GlyphIndex].LenAndFontSize |= v13 & 0xFFF;
      pGlyphs[GlyphIndex].Flags = v14;
      pGlyphs[GlyphIndex].LenAndFontSize &= 0xFFFu;
      ColorV = this->FindFontInfo.pCurrentFormat->ColorV;
      this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x4000u;
      this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x2000u;
      this->LineCursor.GlyphIns.pNextFormatData[this->LineCursor.GlyphIns.FormatDataIndex++].pFont = v10;
      _InterlockedExchangeAdd(&v10->RefCount, 1u);
      this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x4000u;
      this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x1000u;
      this->LineCursor.GlyphIns.pNextFormatData[this->LineCursor.GlyphIns.FormatDataIndex++].ColorV = ColorV;
      if ( this->LineCursor.GlyphIns.pGlyphs )
      {
        v16 = this->LineCursor.GlyphIns.GlyphIndex;
        if ( v16 < this->LineCursor.GlyphIns.GlyphsCount )
          this->LineCursor.GlyphIns.GlyphIndex = v16 + 1;
      }
      _InterlockedExchangeAdd(&v10->RefCount, 1u);
      v17 = this->LineCursor.pLastFont.pObject;
      if ( v17 && !_InterlockedDecrement(&v17->RefCount) )
        v17->vfptr->__vecDelDtor(v17, 1u);
      this->LineCursor.pLastFont.pObject = v10;
      this->LineCursor.LastColor = ColorV;
      if ( !_InterlockedDecrement(&v10->RefCount) )
        v10->vfptr->__vecDelDtor(v10, 1u);
    }
    this->LineCursor.LeftMargin = 700;
    this->LineCursor.LineWidth = 700;
    this->LineCursor.Indent = -300;
  }
  v18 = this->pParaFormat;
  this->LineCursor.LeftMargin += 20 * (v18->BlockIndent + v18->LeftMargin);
  this->LineCursor.RightMargin = 20 * v18->RightMargin;
  p_TabStopsNum = &this->TabStopsNum;
  pTabStops = v18->pTabStops;
  if ( pTabStops )
  {
    if ( this != (Scaleform::Render::Text::ParagraphFormatter *)-1140i64 )
      *p_TabStopsNum = *pTabStops;
    v122 = (__int64)(v18->pTabStops + 1);
  }
  else
  {
    v122 = 0i64;
  }
  v21.pFont = 0i64;
  while ( 1 )
  {
    pText = this->LineCursor.CharIter.pText;
    if ( !pText || this->LineCursor.CharIter.CurTextIndex >= pText->Size )
      break;
    p_CharIter = &this->LineCursor.CharIter;
    this->LineCursor.CharInfoHolder.Index = Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(&this->LineCursor.CharIter)->PlaceHolder.Index;
    v24 = Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(&this->LineCursor.CharIter);
    if ( v24->PlaceHolder.pFormat.pObject )
      ++v24->PlaceHolder.pFormat.pObject->RefCount;
    v25 = this->LineCursor.CharInfoHolder.pFormat.pObject;
    if ( v25 )
    {
      v26 = v25->RefCount-- == 1;
      if ( v26 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v25);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v25);
      }
    }
    this->LineCursor.CharInfoHolder.pFormat.pObject = v24->PlaceHolder.pFormat.pObject;
    this->LineCursor.CharInfoHolder.Index = v24->PlaceHolder.Index;
    this->LineCursor.CharInfoHolder.Character = v24->PlaceHolder.Character;
    if ( (this->LineCursor.pDocView->Flags & 0x10) != 0 && this->LineCursor.CharInfoHolder.Character )
      this->LineCursor.CharInfoHolder.Character = 42;
    if ( this->Pass == 1 )
    {
      if ( (this->pDocView->Flags & 8) != 0
        && !v21.pFont
        && Scaleform::Render::Text::WordWrapHelper::IsLineBreakOpportunityAt(
             7u,
             this->LineCursor.LastCharCode,
             this->LineCursor.CharInfoHolder.Character) )
      {
        Scaleform::Render::Text::GFxLineCursor::operator=(&this->WordWrapPoint, &this->LineCursor);
      }
      if ( this->Pass == 1 && this->HasLineFormatHandler )
      {
        TextRectWidth = this->TextRectWidth;
        if ( !this->LineCursor.LineWidth && !this->StartPoint.pDocView )
          Scaleform::Render::Text::GFxLineCursor::operator=(&this->StartPoint, &this->LineCursor);
        if ( (float)this->LineCursor.LineWidth > (float)(TextRectWidth * 0.5) && !this->HalfPoint.pDocView )
          Scaleform::Render::Text::GFxLineCursor::operator=(&this->HalfPoint, &this->LineCursor);
      }
    }
    this->DeltaText = 1;
    if ( v21.pFont )
    {
      v26 = v21.pFont->RefCount-- == 1;
      if ( v26 )
        ((void (__fastcall *)(Scaleform::Render::Text::LineBuffer::FormatDataEntry, __int64))v21.pFont->vfptr->__vecDelDtor)(
          v21,
          1i64);
    }
    v21.pFont = 0i64;
    v138 = 0i64;
    pImageSubstitutor = this->pDocView->pImageSubstitutor;
    if ( !pImageSubstitutor )
      goto LABEL_61;
    v29 = this->LineCursor.CharIter.pText;
    if ( v29 && (Size = v29->Size, CurTextIndex = this->LineCursor.CharIter.CurTextIndex, CurTextIndex < Size) )
    {
      v32 = Size - CurTextIndex;
      v125 = v32;
      v33 = &v29->pText[CurTextIndex];
    }
    else
    {
      v32 = 0i64;
      v125 = 0i64;
      v33 = 0i64;
    }
    ImageDesc = Scaleform::Render::Text::DocView::ImageSubstitutor::FindImageDesc(
                  pImageSubstitutor,
                  v33,
                  v32,
                  &ptextLen);
    v21.pFont = (Scaleform::Render::Text::FontHandle *)ImageDesc;
    if ( ImageDesc )
      ++ImageDesc->RefCount;
    v138 = ImageDesc;
    if ( ImageDesc )
    {
      this->DeltaText = ptextLen;
    }
    else
    {
LABEL_61:
      v35 = this->LineCursor.CharInfoHolder.pFormat.pObject;
      if ( v35 && (v35->PresentMask & 0x200) != 0 && this->LineCursor.CharInfoHolder.Character )
      {
        v36 = Scaleform::Render::Text::TextFormat::GetImageDesc(v35);
        v37 = v36;
        if ( v36 )
          ++v36->RefCount;
        if ( v21.pFont )
        {
          v26 = v21.pFont->RefCount-- == 1;
          if ( v26 )
            ((void (__fastcall *)(Scaleform::Render::Text::LineBuffer::FormatDataEntry, __int64))v21.pFont->vfptr->__vecDelDtor)(
              v21,
              1i64);
        }
        v21.pFont = (Scaleform::Render::Text::FontHandle *)v37;
        v138 = v37;
      }
    }
    this->pFont = 0i64;
    this->Scale = 1.0;
    this->FontSize = -1.0;
    if ( v21.pFont )
    {
      this->FindFontInfo.pCurrentFormat = this->LineCursor.CharInfoHolder.pFormat.pObject;
      v80 = *(float *)&v21.pFont->FontName.pData;
      if ( v80 <= 0.0 )
        v81 = v80 - 0.5;
      else
        v81 = v80 + 0.5;
      v79 = (int)v81;
      this->GlyphWidth = (int)v81;
      this->GlyphAdvance = (float)(int)v81 + 40.0;
      LastAdvance = this->LineCursor.LastAdvance;
      if ( LastAdvance <= 0.0 )
        v83 = LastAdvance - 0.5;
      else
        v83 = LastAdvance + 0.5;
      this->LastAdvance = (int)v83;
      this->GlyphIndex = -1;
      *(_WORD *)&this->isSpace = 0;
      goto LABEL_151;
    }
    v38 = this->LineCursor.CharInfoHolder.Character == 160;
    this->isNbsp = v38;
    Character = this->LineCursor.CharInfoHolder.Character;
    v43 = 1;
    if ( Character )
    {
      if ( v38
        || (v40 = (unsigned __int64)Character >> 8, (v41 = Scaleform::UnicodeSpaceBits[v40]) == 0)
        || v41 != 1
        && (v42 = Scaleform::UnicodeSpaceBits[v41 + ((Character >> 4) & 0xF)], !_bittest(&v42, Character & 0xF)) )
      {
        v43 = 0;
      }
    }
    this->isSpace = v43;
    v44 = this->FindFontInfo.pCurrentFont.pObject;
    if ( v44 && this->FindFontInfo.pCurrentFormat == this->LineCursor.CharInfoHolder.pFormat.pObject )
    {
      _InterlockedExchangeAdd(&v44->RefCount, 1u);
      v21.pFont = (Scaleform::Render::Text::FontHandle *)v138;
      v45 = this->pFontHandle.pObject;
      if ( v45 )
      {
        if ( !_InterlockedDecrement(&v45->RefCount) )
          v45->vfptr->__vecDelDtor(v45, 1u);
        v21.pFont = (Scaleform::Render::Text::FontHandle *)v138;
      }
      this->pFontHandle.pObject = this->FindFontInfo.pCurrentFont.pObject;
    }
    else
    {
      this->FindFontInfo.pCurrentFormat = this->LineCursor.CharInfoHolder.pFormat.pObject;
      v46 = Scaleform::Render::Text::DocView::FindFont(
              this->pDocView,
              &this->FindFontInfo,
              this->LineCursor.CharInfoHolder.Character == 0);
      v47 = v46;
      if ( v46 )
      {
        _InterlockedExchangeAdd(&v46->RefCount, 1u);
        v21.pFont = (Scaleform::Render::Text::FontHandle *)v138;
      }
      v48 = this->pFontHandle.pObject;
      if ( v48 )
      {
        if ( !_InterlockedDecrement(&v48->RefCount) )
          v48->vfptr->__vecDelDtor(v48, 1u);
        v21.pFont = (Scaleform::Render::Text::FontHandle *)v138;
      }
      this->pFontHandle.pObject = v47;
      if ( !v47 )
        goto LABEL_227;
    }
    v49 = this->pFontHandle.pObject->pFont.pObject;
    this->pFont = v49;
    ActualFontSize = Scaleform::Render::Text::ParagraphFormatter::GetActualFontSize(this);
    this->FontSize = ActualFontSize;
    this->Scale = (float)(ActualFontSize * 20.0) * 0.0009765625;
    v51 = this->LineCursor.CharInfoHolder.Character;
    v52 = 10;
    if ( (this->pDocView->pDocument.pObject->RTFlags & 2) != 0 )
      v52 = 13;
    if ( v51 == v52 || !v51 )
    {
      v73 = (unsigned int)v49->vfptr[2].__vecDelDtor(v49, 32u);
      this->GlyphIndex = v73;
      this->GlyphAdvance = (float)(((float (__fastcall *)(Scaleform::Render::Font *, _QWORD))this->pFont->vfptr[3].__vecDelDtor)(
                                     this->pFont,
                                     v73)
                                 * 0.5)
                         * this->Scale;
    }
    else if ( v51 == 9 )
    {
      this->GlyphIndex = -1;
      this->GlyphAdvance = 0.0;
    }
    else
    {
      v53 = ((__int64 (__fastcall *)(Scaleform::Render::Font *))v49->vfptr[2].__vecDelDtor)(v49);
      this->GlyphIndex = v53;
      if ( v53 == -1 )
      {
        if ( this->isNbsp )
          this->GlyphIndex = (int)this->pFont->vfptr[2].__vecDelDtor(this->pFont, 32i64);
        if ( this->GlyphIndex == -1 && this->pLog && (this->pDocView->RTFlags & 0x10) == 0 )
        {
          v128 = 1;
          v129 = 0i64;
          v130 = 0i64;
          v131 = 0i64;
          v132 = 512i64;
          v133 = 0;
          v134 = Scaleform::Memory::pGlobalHeap;
          pCurrentFormat = this->FindFontInfo.pCurrentFormat;
          v55 = pCurrentFormat->PresentMask >> 12;
          v56 = (this->pDocView->Flags & 0x20) != 0;
          v57 = (unsigned __int8)pCurrentFormat->FormatFlags >> 1;
          v58 = pCurrentFormat->FormatFlags & 1;
          FontList = Scaleform::Render::Text::TextFormat::GetFontList(pCurrentFormat);
          LOBYTE(v60) = (v55 & 1) == 0;
          v61 = ((__int64 (__fastcall *)(Scaleform::Render::Text::FontManagerBase *, unsigned __int64, _QWORD, __int64, int *))this->pDocView->pFontManager.pObject->vfptr[1].__vecDelDtor)(
                  this->pDocView->pFontManager.pObject,
                  (FontList->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
                  (v56 ? 0x10 : 0) | ((v57 & 1) != 0) | (v58 != 0 ? 2 : 0),
                  v60,
                  &v128);
          v137 = v61;
          v62 = this->pDocView->pDocumentListener.pObject;
          if ( v62 )
          {
            v63 = (Scaleform::String *)v62->vfptr[14].__vecDelDtor(v62, (unsigned int)&v126);
            v121 |= 1u;
          }
          else
          {
            v139 = (unsigned __int64)&Scaleform::String::NullData;
            _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
            v63 = (Scaleform::String *)&v139;
            v121 |= 2u;
          }
          Scaleform::String::String(&v124, v63);
          if ( (v121 & 2) != 0 )
          {
            v121 &= ~2u;
            if ( !_InterlockedDecrement((volatile signed __int32 *)((v139 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          }
          if ( (v121 & 1) != 0 )
          {
            v121 &= ~1u;
            if ( !_InterlockedDecrement((volatile signed __int32 *)((v126 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          }
          this->pFont->vfptr[20].__vecDelDtor(this->pFont, (unsigned int)&v140);
          v64 = ((__int64 (__fastcall *)(Scaleform::Render::Font *))this->pFont->vfptr[18].__vecDelDtor)(this->pFont);
          v65 = &customCaption;
          if ( v129 )
            v65 = v129;
          v66 = v140 & 0xFFFFFFFFFFFFFFFCui64;
          v67 = v124.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
          v68 = Scaleform::Render::Text::TextFormat::GetFontList(this->FindFontInfo.pCurrentFormat);
          LODWORD(v120) = v64;
          LODWORD(v119) = this->LineCursor.CharInfoHolder.Character;
          Scaleform::Log::LogError(
            this->pLog,
            "Missing \"%s\" glyph %c (0x%x) in \"%s\".\nFont has %u glyphs, ranges %s.\nSearch log: \n%s",
            (const char *)((v68->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
            (unsigned int)SLOBYTE(this->LineCursor.CharInfoHolder.Character),
            v119,
            (const char *)(v67 + 12),
            v120,
            (const char *)(v66 + 12),
            v65);
          this->pDocView->RTFlags |= 0x10u;
          if ( !_InterlockedDecrement((volatile signed __int32 *)((v140 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          if ( !_InterlockedDecrement((volatile signed __int32 *)(v67 + 8)) )
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v67);
          if ( v61 && !_InterlockedDecrement((volatile signed __int32 *)(v61 + 8)) )
            (**(void (__fastcall ***)(__int64, __int64))v61)(v61, 1i64);
          if ( v129 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          p_TabStopsNum = &this->TabStopsNum;
          p_CharIter = &this->LineCursor.CharIter;
          v21.pFont = (Scaleform::Render::Text::FontHandle *)v138;
        }
      }
      this->GlyphAdvance = ((float (__fastcall *)(Scaleform::Render::Font *, _QWORD))this->pFont->vfptr[3].__vecDelDtor)(
                             this->pFont,
                             (unsigned int)this->GlyphIndex)
                         * this->Scale;
      v69 = this->LineCursor.CharInfoHolder.Character;
      v70 = (unsigned __int64)v69 >> 8;
      v71 = Scaleform::UnicodeNonSpacingMarksBits[v70];
      if ( Scaleform::UnicodeNonSpacingMarksBits[v70] )
      {
        if ( v71 == 1
          || (v72 = Scaleform::UnicodeNonSpacingMarksBits[v71 + ((v69 >> 4) & 0xF)], _bittest(&v72, v69 & 0xF)) )
        {
          this->GlyphAdvance = 0.0;
        }
      }
    }
    if ( this->LineCursor.pPrevGrec )
    {
      v74 = 0.0;
      if ( this->LineCursor.LastKerning )
        v74 = ((float (__fastcall *)(Scaleform::Render::Font *, _QWORD, _QWORD))this->LineCursor.pLastFont.pObject->pFont.pObject->vfptr[4].__vecDelDtor)(
                this->LineCursor.pLastFont.pObject->pFont.pObject,
                this->LineCursor.LastCharCode,
                this->LineCursor.CharInfoHolder.Character)
            * this->Scale;
      v75 = v74 + this->LineCursor.LastAdvance;
      if ( v75 > 0.0 )
      {
        v76 = v75 + 0.5;
        goto LABEL_138;
      }
    }
    else
    {
      v75 = this->LineCursor.LastAdvance;
      if ( v75 > 0.0 )
      {
        v76 = v75 + 0.5;
        goto LABEL_138;
      }
    }
    v76 = v75 - 0.5;
LABEL_138:
    this->LastAdvance = (int)v76;
    GlyphAdvance = this->GlyphAdvance;
    if ( GlyphAdvance <= 0.0 )
      v78 = GlyphAdvance - 0.5;
    else
      v78 = GlyphAdvance + 0.5;
    v79 = (int)v78;
    this->GlyphWidth = (int)v78;
    if ( this->isSpace )
      v79 = 0;
LABEL_151:
    this->AdjLineWidth = v79;
    v84 = this->LastAdvance;
    this->NewLineWidth = v84 + this->LineCursor.LineWidth;
    pPrevGrec = this->LineCursor.pPrevGrec;
    if ( pPrevGrec )
    {
      if ( v84 < 0 )
      {
        pPrevGrec->Advance = abs32(v84);
        pPrevGrec->Flags |= 0x40u;
      }
      else
      {
        pPrevGrec->Advance = v84;
        pPrevGrec->Flags &= ~0x40u;
      }
    }
    if ( !Scaleform::Render::Text::ParagraphFormatter::CheckWordWrap(this) )
    {
      v86 = &this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex];
      *v86 = 0i64;
      v86->Index = this->GlyphIndex;
      if ( v21.pFont )
      {
        this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x4000u;
        this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x800u;
        this->LineCursor.GlyphIns.pNextFormatData[this->LineCursor.GlyphIns.FormatDataIndex++] = v21;
        ++v21.pFont->RefCount;
        v86->LenAndFontSize = (LOWORD(this->DeltaText) << 12) | v86->LenAndFontSize & 0xFFF;
        this->LineCursor.LastKerning = 0;
        LODWORD(v87) = COERCE_UNSIGNED_INT(
                         (float)((float)(*((float *)&v21.pFont[1].RefCount + 1) + *(float *)&v21.pFont[1].RefCount) * 0.0)
                       + *((float *)&v21.pFont[1].pFontManager + 1)) ^ _xmm[0];
        MaxFontAscent = this->LineCursor.MaxFontAscent;
        if ( v87 >= MaxFontAscent )
          LODWORD(MaxFontAscent) = COERCE_UNSIGNED_INT(
                                     (float)((float)(*((float *)&v21.pFont[1].RefCount + 1)
                                                   + *(float *)&v21.pFont[1].RefCount)
                                           * 0.0)
                                   + *((float *)&v21.pFont[1].pFontManager + 1)) ^ _xmm[0];
        this->LineCursor.MaxFontAscent = MaxFontAscent;
        v89 = *((float *)&v21.pFont->FontName.HeapTypeBits + 1) - v87;
        MaxFontDescent = this->LineCursor.MaxFontDescent;
        if ( v89 >= MaxFontDescent )
          MaxFontDescent = v89;
        this->LineCursor.MaxFontDescent = MaxFontDescent;
        this->LineCursor.NumOfTrailingSpaces = 0;
        this->LineCursor.LineWidthWithoutTrailingSpaces = this->AdjLineWidth + this->NewLineWidth;
        v91 = this->FindFontInfo.pCurrentFormat;
        if ( (v91->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&v91->Url) )
          v86->Flags |= 0x80u;
        else
          v86->Flags &= ~0x80u;
LABEL_209:
        if ( this->LineCursor.CharInfoHolder.Character == 9 )
        {
          TabStopsIndex = this->TabStopsIndex;
          if ( (unsigned int)TabStopsIndex >= *p_TabStopsNum )
          {
            FontSize_low = (__m128)LODWORD(this->FontSize);
            FontSize_low.m128_f32[0] = (float)((float)(FontSize_low.m128_f32[0] * 2.0) + 8.0) * 0.125;
            v107 = (int)FontSize_low.m128_f32[0];
            if ( (int)FontSize_low.m128_f32[0] != 0x80000000 && (float)v107 != FontSize_low.m128_f32[0] )
              FontSize_low.m128_f32[0] = (float)(v107
                                               - (_mm_movemask_ps(_mm_unpacklo_ps(FontSize_low, FontSize_low)) & 1));
            v108 = (float)(FontSize_low.m128_f32[0] * 8.0) * 20.0;
            v109 = (__m128)COERCE_UNSIGNED_INT((float)this->NewLineWidth);
            v110 = v109;
            v110.m128_f32[0] = (float)(v109.m128_f32[0] + v108) / v108;
            v111 = (int)v110.m128_f32[0];
            if ( (int)v110.m128_f32[0] != 0x80000000 && (float)v111 != v110.m128_f32[0] )
              v110.m128_f32[0] = (float)(v111 - (_mm_movemask_ps(_mm_unpacklo_ps(v110, v110)) & 1));
            this->GlyphAdvance = (float)(v110.m128_f32[0] * v108) - v109.m128_f32[0];
          }
          else
          {
            v104 = 20 * *(_DWORD *)(v122 + 4 * TabStopsIndex);
            this->TabStopsIndex = TabStopsIndex + 1;
            NewLineWidth = this->NewLineWidth;
            if ( v104 > NewLineWidth )
              this->GlyphAdvance = (float)(v104 - NewLineWidth);
          }
        }
        this->LineCursor.LineLength += v86->LenAndFontSize >> 12;
        this->LineCursor.pPrevGrec = v86;
        this->LineCursor.LastCharCode = this->LineCursor.CharInfoHolder.Character;
        this->LineCursor.LineWidth = this->NewLineWidth;
        this->LineCursor.LastGlyphIndex = this->GlyphIndex;
        v112 = this->GlyphAdvance;
        this->LineCursor.LastAdvance = v112;
        v113 = this->FindFontInfo.pCurrentFormat;
        if ( (v113->PresentMask & 2) != 0 )
          this->LineCursor.LastAdvance = (float)((float)(v113->LetterSpacing * 0.050000001) * 20.0) + v112;
        GlyphWidth = this->GlyphWidth;
        this->LineCursor.LastGlyphWidth = GlyphWidth;
        if ( !this->LineCursor.GlyphIns.GlyphIndex )
          this->LineCursor.FirstGlyphWidth = GlyphWidth;
        if ( this->LineCursor.GlyphIns.pGlyphs )
        {
          v115 = this->LineCursor.GlyphIns.GlyphIndex;
          if ( v115 < this->LineCursor.GlyphIns.GlyphsCount )
            this->LineCursor.GlyphIns.GlyphIndex = v115 + 1;
        }
        goto LABEL_227;
      }
      v92 = this->FindFontInfo.pCurrentFormat->ColorV;
      FontSize = this->FontSize;
      if ( FontSize < 256.0 && (v94 = (int)(float)(FontSize * 16.0), (v94 & 0xF) != 0) )
      {
        v86->Flags = 16;
        v95 = v94 & 0xFFF;
      }
      else
      {
        v86->Flags = 0;
        v95 = (int)FontSize & 0xFFF;
      }
      v86->LenAndFontSize = v95;
      v96 = this->pFontHandle.pObject;
      if ( v96 != this->LineCursor.pLastFont.pObject )
      {
        this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x4000u;
        this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x2000u;
        this->LineCursor.GlyphIns.pNextFormatData[this->LineCursor.GlyphIns.FormatDataIndex++].pFont = v96;
        _InterlockedExchangeAdd(&v96->RefCount, 1u);
        v21.pFont = (Scaleform::Render::Text::FontHandle *)v138;
      }
      if ( v92 != this->LineCursor.LastColor )
      {
        this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x4000u;
        this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex].Flags |= 0x1000u;
        this->LineCursor.GlyphIns.pNextFormatData[this->LineCursor.GlyphIns.FormatDataIndex++].ColorV = v92;
      }
      v97 = this->LineCursor.CharInfoHolder.Character;
      v98 = 10;
      if ( (this->pDocView->pDocument.pObject->RTFlags & 2) != 0 )
        v98 = 13;
      if ( v97 == v98 )
      {
        if ( !v97 )
          goto LABEL_191;
        v86->LenAndFontSize &= 0xFFFu;
        v86->LenAndFontSize |= 0x1000u;
      }
      else
      {
        if ( v97 )
        {
          if ( !this->isSpace && !this->isNbsp )
          {
            this->LineCursor.NumOfTrailingSpaces = 0;
            goto LABEL_188;
          }
          v86->Flags |= 2u;
          v99 = (unsigned int)this->GlyphIndex;
          if ( (int)v99 >= 0 )
          {
            v123 = 0i64;
            ((void (__fastcall *)(Scaleform::Render::Font *, __int64, __int128 *))this->pFont->vfptr[7].__vecDelDtor)(
              this->pFont,
              v99,
              &v123);
            if ( *(float *)&v123 >= *((float *)&v123 + 2) || *((float *)&v123 + 1) >= *((float *)&v123 + 3) )
              v86->Flags |= 0x200u;
          }
          else
          {
            v86->Flags |= 0x200u;
          }
          ++this->LineCursor.NumOfSpaces;
          if ( this->isSpace )
          {
            ++this->LineCursor.NumOfTrailingSpaces;
          }
          else
          {
            this->LineCursor.NumOfTrailingSpaces = 0;
LABEL_188:
            this->LineCursor.LineWidthWithoutTrailingSpaces = this->AdjLineWidth + this->NewLineWidth;
          }
          v86->LenAndFontSize &= 0xFFFu;
          v86->LenAndFontSize |= 0x1000u;
LABEL_194:
          Scaleform::Render::Text::GFxLineCursor::TrackFontParams(&this->LineCursor, this->pFont, this->Scale);
LABEL_195:
          if ( (this->FindFontInfo.pCurrentFormat->FormatFlags & 4) != 0 )
            v86->Flags |= 0x400u;
          else
            v86->Flags &= ~0x400u;
          v100 = this->FindFontInfo.pCurrentFormat;
          if ( (v100->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&v100->Url) )
            v86->Flags |= 0x80u;
          else
            v86->Flags &= ~0x80u;
          v101 = this->pFontHandle.pObject;
          if ( v101 )
          {
            _InterlockedExchangeAdd(&v101->RefCount, 1u);
            v21.pFont = (Scaleform::Render::Text::FontHandle *)v138;
          }
          v102 = this->LineCursor.pLastFont.pObject;
          if ( v102 )
          {
            if ( !_InterlockedDecrement(&v102->RefCount) )
              v102->vfptr->__vecDelDtor(v102, 1u);
            v21.pFont = (Scaleform::Render::Text::FontHandle *)v138;
          }
          this->LineCursor.pLastFont.pObject = this->pFontHandle.pObject;
          this->LineCursor.LastColor = v92;
          this->LineCursor.LastKerning = (this->FindFontInfo.pCurrentFormat->FormatFlags & 8) != 0;
          goto LABEL_209;
        }
LABEL_191:
        v86->LenAndFontSize &= 0xFFFu;
      }
      v86->Flags |= 0x300u;
      this->GlyphWidth = 0;
      this->LineCursor.LineHasNewLine = 1;
      if ( !this->LineCursor.CharInfoHolder.Index )
        goto LABEL_194;
      goto LABEL_195;
    }
LABEL_227:
    DeltaText = this->DeltaText;
    if ( DeltaText )
    {
      v117 = DeltaText;
      Scaleform::Render::Text::Paragraph::CharactersIterator::operator+=(p_CharIter, DeltaText);
      this->LineCursor.NumChars += v117;
    }
  }
  if ( this->pTempLine )
    Scaleform::Render::Text::ParagraphFormatter::FinalizeLine(this);
  pTextBufForCustomFormat = (Scaleform::Render::Text::ParagraphFormatter *)this->pTextBufForCustomFormat;
  if ( pTextBufForCustomFormat
    && pTextBufForCustomFormat != (Scaleform::Render::Text::ParagraphFormatter *)this->TextBufForCustomFormat )
  {
    Scaleform::Render::Text::StyledText::GetAllocator(this->pDocView->pDocument.pObject);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pTextBufForCustomFormat);
  }
  if ( v21.pFont )
  {
    v26 = v21.pFont->RefCount-- == 1;
    if ( v26 )
      ((void (__fastcall *)(Scaleform::Render::Text::LineBuffer::FormatDataEntry, __int64))v21.pFont->vfptr->__vecDelDtor)(
        v21,
        1i64);
  }
}

// File Line: 2217
// RVA: 0x97AEE0
void __fastcall Scaleform::Render::Text::DocView::Format(Scaleform::Render::Text::DocView *this)
{
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm3_4
  Scaleform::Render::Text::DocView::DocumentText *pObject; // rbx
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // rdi
  __int64 v7; // rbx
  float v8; // xmm13_4
  signed int v9; // r11d
  Scaleform::Render::Text::LineBuffer *v10; // r10
  unsigned int v11; // edx
  Scaleform::Render::Text::Paragraph *pPara; // r9
  unsigned __int64 Size; // rbx
  Scaleform::Render::Text::LineBuffer::Line **Data; // rdi
  Scaleform::Render::Text::LineBuffer::Line *v15; // rax
  unsigned int v16; // r8d
  unsigned __int16 v17; // cx
  Scaleform::Render::Text::ParagraphFormat *StartIndex; // r8
  Scaleform::Render::Text::EditorKitBase *v19; // rcx
  Scaleform::Render::Text::LineBuffer::Line *v20; // rbx
  unsigned int ParagraphId; // ecx
  int OffsetX; // edi
  bool v23; // cl
  __int64 TextLength; // rax
  int Width; // eax
  Scaleform::Render::Text::EditorKitBase *v26; // rcx
  unsigned int Height; // ecx
  unsigned int v28; // ecx
  int Leading; // eax
  int MemSize; // edx
  float v31; // xmm0_4
  float v32; // xmm0_4
  signed int v33; // eax
  int v34; // ecx
  float v35; // xmm0_4
  float v36; // xmm0_4
  unsigned int v37; // ecx
  int v38; // eax
  int TextPos; // ecx
  unsigned int v40; // r9d
  unsigned int v41; // r11d
  int j; // r8d
  int *v43; // rcx
  int v44; // eax
  unsigned int UniqueId; // r11d
  unsigned int GlyphsCount; // ecx
  unsigned __int16 v47; // cx
  unsigned int v48; // r9d
  int i; // r8d
  int *v50; // rcx
  int v51; // eax
  int ParaWidth; // eax
  unsigned __int64 v53; // rax
  unsigned __int64 v54; // rcx
  wchar_t *v55; // rcx
  Scaleform::Render::Text::EditorKitBase *v56; // rcx
  unsigned __int64 v57; // r8
  int v58; // r9d
  char v59; // si
  Scaleform::Render::Text::DocView *v60; // rbx
  int v61; // edi
  char Flags; // dl
  float y2; // xmm8_4
  float x2; // xmm9_4
  float y1; // xmm10_4
  float x1; // xmm11_4
  float v67; // xmm6_4
  float v68; // xmm2_4
  float v69; // xmm4_4
  float v70; // xmm3_4
  float v71; // xmm5_4
  float v72; // xmm1_4
  int v73; // eax
  float v74; // xmm5_4
  float v75; // xmm3_4
  float v76; // xmm7_4
  float v77; // xmm4_4
  float v78; // xmm0_4
  float v79; // xmm1_4
  float v80; // xmm3_4
  float v81; // xmm4_4
  float v82; // xmm2_4
  Scaleform::Render::Text::LineBuffer *v83; // rdx
  __int64 v84; // rdx
  int v85; // r8d
  unsigned __int64 v86; // r10
  Scaleform::Render::Text::LineBuffer::Line *v87; // rcx
  int v88; // eax
  unsigned int MaxVScroll; // ebx
  unsigned int v90; // eax
  Scaleform::Render::Text::DocView *v91; // rdx
  Scaleform::Render::Text::LineBuffer *v92; // r11
  Scaleform::Render::Text::DocView::DocumentListener *v93; // rcx
  int v94; // eax
  bool v95; // zf
  Scaleform::Render::Text::DocView *v96; // rsi
  float v97; // xmm10_4
  float v98; // xmm11_4
  float v99; // xmm8_4
  float v100; // xmm9_4
  float v101; // xmm4_4
  float v102; // xmm3_4
  float v103; // xmm0_4
  float v104; // xmm2_4
  float TextHeight; // xmm1_4
  float v106; // xmm7_4
  int v107; // edi
  int v108; // edi
  float v109; // xmm6_4
  int BottomVScroll; // r8d
  int v111; // r9d
  Scaleform::Render::Text::LineBuffer::Line *v112; // rcx
  int v113; // edx
  int v114; // eax
  unsigned int v115; // ebx
  unsigned int v116; // r10d
  Scaleform::Render::Text::LineBuffer::Line *v117; // r8
  int v118; // ecx
  float v119; // xmm0_4
  float v120; // xmm0_4
  signed int v121; // eax
  int v122; // r9d
  float v123; // xmm0_4
  float v124; // xmm0_4
  unsigned int v125; // ecx
  int v126; // eax
  int v127; // edi
  Scaleform::Render::Text::EditorKitBase *v128; // rcx
  char v129; // al
  int v130; // ecx
  int TextWidth; // eax
  float v132; // xmm1_4
  float v133; // xmm1_4
  unsigned int v134; // eax
  Scaleform::Render::Text::EditorKitBase *v135; // rcx
  int v136; // eax
  float v137; // xmm1_4
  float v138; // xmm1_4
  Scaleform::Render::Text::DocView::DocumentListener *v139; // rcx
  char v140; // al
  Scaleform::Render::Text::DocView::DocumentListener *v141; // rcx
  Scaleform::Render::Text::DocView::DocumentListener *v142; // rcx
  Scaleform::Render::Text::EditorKitBase *v143; // rcx
  Scaleform::Render::Text::EditorKitBase *v144; // rcx
  Scaleform::Render::Text::CompositionStringBase *v145; // rax
  Scaleform::Render::Text::LineBuffer::Line *v146; // rcx
  Scaleform::Render::Text::FontHandle *FirstFontInfo; // rax
  __int64 v149; // [rsp+20h] [rbp-C0h]
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *v150; // [rsp+28h] [rbp-B8h]
  Scaleform::Render::Text::Paragraph *v151; // [rsp+30h] [rbp-B0h]
  int OffsetY; // [rsp+38h] [rbp-A8h]
  Scaleform::Render::Text::LineBuffer *p_mLineBuffer; // [rsp+40h] [rbp-A0h]
  Scaleform::Render::Text::LineBuffer *v154[2]; // [rsp+48h] [rbp-98h] BYREF
  unsigned int lineIdx[2]; // [rsp+58h] [rbp-88h]
  Scaleform::Render::Text::ParagraphFormatter v156; // [rsp+60h] [rbp-80h] BYREF
  Scaleform::Render::Text::DocView *pdoc; // [rsp+C50h] [rbp+B70h]
  int v158; // [rsp+C58h] [rbp+B78h]
  int vars0; // [rsp+C60h] [rbp+B80h]
  void *retaddr; // [rsp+C68h] [rbp+B88h]

  v156.pTempLine = (Scaleform::Render::Text::LineBuffer::Line *)-2i64;
  v2 = this->ViewRect.x2 - 40.0;
  v3 = this->ViewRect.y1 + 40.0;
  v4 = this->ViewRect.y2 - 40.0;
  this->mLineBuffer.Geom.VisibleRect.x1 = this->ViewRect.x1 + 40.0;
  this->mLineBuffer.Geom.VisibleRect.y1 = v3;
  this->mLineBuffer.Geom.VisibleRect.x2 = v2;
  this->mLineBuffer.Geom.VisibleRect.y2 = v4;
  pObject = this->pDocument.pObject;
  if ( !pObject )
    return;
  HIDWORD(v156.pParagraph) = Scaleform::Render::Text::DocView::GetMaxHScrollValue(this);
  LODWORD(v156.pParagraph) = this->MaxVScroll.Value;
  if ( (this->AlignProps & 0x30) != 0 )
    this->RTFlags |= 2u;
  p_Paragraphs = &pObject->Paragraphs;
  v150 = &pObject->Paragraphs;
  v7 = 0i64;
  v149 = 0i64;
  p_mLineBuffer = &this->mLineBuffer;
  v154[0] = &this->mLineBuffer;
  v154[1] = 0i64;
  *(_QWORD *)lineIdx = 0i64;
  v8 = 0.0;
  LOBYTE(v156.pDocView) = (this->mLineBuffer.Geom.Flags & 4) != 0;
  Scaleform::Render::Text::ParagraphFormatter::ParagraphFormatter(&v156, this, this->pLog.pObject);
  v9 = 0;
  vars0 = 0;
  LODWORD(retaddr) = 0;
LABEL_5:
  v10 = v154[0];
  v11 = lineIdx[0];
  while ( p_Paragraphs && v7 >= 0 && v7 < SLODWORD(p_Paragraphs->Data.Size) )
  {
    pPara = p_Paragraphs->Data.Data[v7].pPara;
    v151 = pPara;
    if ( v10 )
    {
      Size = v10->Lines.Data.Size;
      if ( v11 >= Size || (v11 & 0x80000000) != 0 )
        goto LABEL_119;
      Data = v10->Lines.Data.Data;
      v15 = v10->Lines.Data.Data[v11];
      if ( (this->RTFlags & 2) == 0 )
      {
        v16 = (v15->MemSize & 0x80000000) == 0 ? v15->Data32.ParagraphId : v15->Data32.GlyphsCount;
        if ( pPara->UniqueId == v16 )
        {
          v17 = (v15->MemSize & 0x80000000) == 0 ? v15->Data32.ParagraphModId : v15->Data8.ParagraphModId;
          if ( pPara->ModCounter == v17 )
          {
            StartIndex = (Scaleform::Render::Text::ParagraphFormat *)pPara->StartIndex;
            v19 = this->pEditorKit.pObject;
            if ( v19 )
            {
              StartIndex = (Scaleform::Render::Text::ParagraphFormat *)v19->vfptr[4].__vecDelDtor(
                                                                         v19,
                                                                         pPara->StartIndex);
              v11 = lineIdx[0];
              v10 = v154[0];
              pPara = v151;
              v9 = vars0;
            }
            while ( 2 )
            {
              if ( !v10
                || v11 >= v10->Lines.Data.Size
                || (v11 & 0x80000000) != 0
                || ((v20 = v10->Lines.Data.Data[v11], (v20->MemSize & 0x80000000) == 0)
                  ? (ParagraphId = v20->Data32.ParagraphId)
                  : (ParagraphId = v20->Data32.GlyphsCount),
                    pPara->UniqueId != ParagraphId) )
              {
                v7 = v149;
                p_Paragraphs = v150;
                goto LABEL_82;
              }
              if ( (v20->MemSize & 0x80000000) == 0 )
              {
                v20->Data32.TextPos = (unsigned int)StartIndex;
              }
              else
              {
                v20->Data32.TextPos &= 0xFF000000;
                v20->Data32.TextPos |= (unsigned int)StartIndex & 0xFFFFFF;
              }
              OffsetX = v20->Data32.OffsetX;
              v23 = (v20->MemSize & 0x80000000) != 0;
              OffsetY = v20->Data32.OffsetY;
              if ( (v20->MemSize & 0x80000000) == 0 )
                TextLength = v20->Data32.TextLength;
              else
                TextLength = HIBYTE(v20->Data8.TextPosAndLength);
              v156.pParaFormat = (Scaleform::Render::Text::ParagraphFormat *)((char *)StartIndex + TextLength);
              v20->Data32.OffsetY = v156.NextOffsetY;
              if ( v23 )
                Width = v20->Data8.Width;
              else
                Width = v20->Data32.Width;
              if ( Width < v9 )
                Width = v9;
              vars0 = Width;
              if ( Scaleform::Render::Text::Paragraph::GetLength(pPara)
                || (v26 = this->pEditorKit.pObject) != 0i64
                && !((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))v26->vfptr[2].__vecDelDtor)(v26) )
              {
                if ( (v20->MemSize & 0x80000000) == 0 )
                  Height = v20->Data32.Height;
                else
                  Height = v20->Data8.Height;
                LODWORD(retaddr) = Height + v156.NextOffsetY;
              }
              if ( (v20->MemSize & 0x80000000) == 0 )
                v28 = v20->Data32.Height;
              else
                v28 = v20->Data8.Height;
              if ( (v20->MemSize & 0x80000000) == 0 )
                Leading = v20->Data32.Leading;
              else
                Leading = v20->Data8.Leading;
              v156.NextOffsetY += v28 + Leading;
              if ( (this->Flags & 1) != 0 )
              {
                MemSize = v20->MemSize;
                if ( ((v20->MemSize >> 27) & 3) == 1 )
                {
                  v35 = this->mLineBuffer.Geom.VisibleRect.x2 - this->mLineBuffer.Geom.VisibleRect.x1;
                  if ( v35 <= 0.0 )
                    v36 = v35 - 0.5;
                  else
                    v36 = v35 + 0.5;
                  if ( MemSize >= 0 )
                    v37 = v20->Data32.Width;
                  else
                    v37 = v20->Data8.Width;
                  v38 = (int)v36 - v37;
                  if ( v38 < 0 )
                    v38 = 0;
                  v20->Data32.OffsetX = v38;
LABEL_75:
                  v156.NeedRecenterLines = 1;
                }
                else if ( ((v20->MemSize >> 27) & 3) == 2 )
                {
                  v31 = (float)(this->mLineBuffer.Geom.VisibleRect.x2 - this->mLineBuffer.Geom.VisibleRect.x1) * 0.5;
                  if ( v31 <= 0.0 )
                    v32 = v31 - 0.5;
                  else
                    v32 = v31 + 0.5;
                  if ( MemSize >= 0 )
                    v33 = v20->Data32.Width;
                  else
                    v33 = v20->Data8.Width;
                  v34 = (int)v32 - v33 / 2;
                  if ( v34 < 0 )
                    v34 = 0;
                  v20->Data32.OffsetX = v34;
                  goto LABEL_75;
                }
              }
              if ( OffsetX != v20->Data32.OffsetX || OffsetY != v20->Data32.OffsetY )
                this->mLineBuffer.Geom.Flags |= 1u;
              v11 = lineIdx[0];
              v10 = v154[0];
              StartIndex = v156.pParaFormat;
              pPara = v151;
              v9 = vars0;
              if ( lineIdx[0] < v154[0]->Lines.Data.Size )
                v11 = ++lineIdx[0];
              continue;
            }
          }
        }
      }
      TextPos = v15->Data32.TextPos;
      if ( (v15->MemSize & 0x80000000) != 0 )
      {
        TextPos &= 0xFFFFFFu;
        if ( TextPos == 0xFFFFFF )
          TextPos = -1;
      }
      if ( TextPos != -1 )
      {
        UniqueId = pPara->UniqueId;
        if ( (v15->MemSize & 0x80000000) == 0 )
          GlyphsCount = v15->Data32.ParagraphId;
        else
          GlyphsCount = v15->Data32.GlyphsCount;
        if ( UniqueId == GlyphsCount )
        {
          v47 = (v15->MemSize & 0x80000000) == 0 ? v15->Data32.ParagraphModId : v15->Data8.ParagraphModId;
          if ( pPara->ModCounter != v47 )
          {
            v48 = 0;
            for ( i = v11; (unsigned int)i < Size && i >= 0; ++i )
            {
              v50 = (int *)Data[i];
              v51 = *v50 >= 0 ? v50[7] : v50[1];
              if ( v51 != UniqueId )
                break;
              ++v48;
            }
            Scaleform::Render::Text::LineBuffer::RemoveLines(v10, v11, v48);
            this->mLineBuffer.Geom.Flags |= 1u;
            pPara = v151;
          }
        }
        p_Paragraphs = v150;
LABEL_119:
        v7 = v149;
        goto LABEL_120;
      }
      v40 = 0;
      if ( (v15->MemSize & 0x80000000) == 0 )
        v41 = v15->Data32.ParagraphId;
      else
        v41 = v15->Data32.GlyphsCount;
      for ( j = v11; (unsigned int)j < Size && j >= 0; ++j )
      {
        v43 = (int *)Data[j];
        v44 = *v43 >= 0 ? v43[7] : v43[1];
        if ( v44 != v41 )
          break;
        ++v40;
      }
      v7 = v149;
      p_Paragraphs = v150;
      v9 = vars0;
      if ( v40 )
      {
        Scaleform::Render::Text::LineBuffer::RemoveLines(v10, v11, v40);
        this->mLineBuffer.Geom.Flags |= 1u;
        v9 = vars0;
        goto LABEL_5;
      }
    }
    else
    {
LABEL_120:
      v156.pLinesIter = (Scaleform::Render::Text::LineBuffer::Iterator *)v154;
      v156.ParaYOffset = v156.NextOffsetY;
      Scaleform::Render::Text::ParagraphFormatter::Format(&v156, pPara);
      this->mLineBuffer.Geom.Flags |= 1u;
      ParaWidth = v156.ParaWidth;
      if ( v156.ParaWidth < vars0 )
        ParaWidth = vars0;
      vars0 = ParaWidth;
      v53 = v151->Text.Size;
      if ( v53 )
      {
        v54 = v53 - 1;
        if ( v151->Text.pText && v54 < v53 )
          v55 = &v151->Text.pText[v54];
        else
          v55 = 0i64;
        if ( !*v55 )
          --v53;
        if ( v53 )
          goto LABEL_132;
      }
      v56 = this->pEditorKit.pObject;
      if ( v56 )
      {
        if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))v56->vfptr[2].__vecDelDtor)(v56) )
LABEL_132:
          LODWORD(retaddr) = v156.ParaYOffset + v156.ParaHeight;
      }
      v11 = lineIdx[0];
      v10 = v154[0];
      v9 = vars0;
LABEL_82:
      if ( v7 < (signed __int64)p_Paragraphs->Data.Size )
        v149 = ++v7;
    }
  }
  if ( v10 )
  {
    v57 = v10->Lines.Data.Size;
    if ( v11 < v57 && (v11 & 0x80000000) == 0 )
    {
      if ( v11 < v57 )
      {
        Scaleform::Render::Text::LineBuffer::RemoveLines(v10, v11, this->mLineBuffer.Lines.Data.Size - v11);
        v9 = vars0;
      }
      this->mLineBuffer.Geom.Flags |= 1u;
    }
  }
  this->TextWidth = v9;
  v58 = (int)retaddr;
  this->TextHeight = (unsigned int)retaddr;
  ++this->FormatCounter;
  this->RTFlags &= 0xFCu;
  v59 = 0;
  v60 = pdoc;
  v61 = ((unsigned __int8)pdoc->AlignProps >> 2) & 3;
  Flags = pdoc->Flags;
  if ( (Flags & 1) != 0 || (Flags & 2) != 0 || v156.ForceVerticalCenterAutoSize )
  {
    y2 = pdoc->ViewRect.y2;
    x2 = pdoc->ViewRect.x2;
    y1 = pdoc->ViewRect.y1;
    x1 = pdoc->ViewRect.x1;
    v67 = x1;
    v68 = y1;
    v69 = x2;
    v70 = y2;
    if ( (Flags & 1) != 0 )
    {
      v71 = (float)v9 + 80.0;
      if ( (pdoc->AlignProps & 3) == 1 )
      {
        v67 = x2 - v71;
      }
      else if ( (pdoc->AlignProps & 3) == 2 )
      {
        v67 = x1 + (float)((float)((float)(x2 - x1) * 0.5) - (float)(v71 * 0.5));
      }
      v69 = v67 + v71;
    }
    if ( (Flags & 2) != 0 || v156.ForceVerticalCenterAutoSize )
    {
      v72 = (float)(int)retaddr + 80.0;
      switch ( v61 )
      {
        case 0:
          if ( !v156.ForceVerticalCenterAutoSize )
            break;
LABEL_155:
          v68 = (float)((float)((float)(y2 - y1) * 0.5) - (float)(v72 * 0.5)) + y1;
          break;
        case 3:
          goto LABEL_155;
        case 2:
          v68 = y2 - v72;
          break;
      }
      v70 = v68 + v72;
      v59 = 1;
    }
    if ( v67 != x1 || (v69 != x2 || v68 != y1 || v70 != y2) && (v67 != x1 || v69 != x2 || v68 != y1 || v70 != y2) )
    {
      pdoc->ViewRect.x1 = v67;
      v60->ViewRect.y1 = v68;
      v60->ViewRect.x2 = v69;
      v60->ViewRect.y2 = v70;
      v60->mLineBuffer.Geom.VisibleRect.x1 = v60->ViewRect.x1 + 40.0;
      v60->mLineBuffer.Geom.VisibleRect.y1 = v68 + 40.0;
      v60->mLineBuffer.Geom.VisibleRect.x2 = v69 - 40.0;
      v60->mLineBuffer.Geom.VisibleRect.y2 = v70 - 40.0;
    }
  }
  v73 = ((unsigned __int8)v60->AlignProps >> 4) & 3;
  if ( v73 )
  {
    v74 = v60->ViewRect.x1 + 40.0;
    v75 = v60->ViewRect.x2 - 40.0;
    v76 = v60->ViewRect.y1 + 40.0;
    v77 = v60->ViewRect.y2 - 40.0;
    if ( (v60->Flags & 4) == 0 && !v61 )
      v61 = 3;
    v78 = *(float *)&FLOAT_1_0;
    v79 = *(float *)&FLOAT_1_0;
    if ( v73 == 1 )
    {
      v80 = v75 - v74;
      if ( (float)v9 > v80 )
        v78 = v80 / (float)v9;
      v81 = v77 - v76;
      if ( (float)(int)retaddr > v81 )
        v79 = v81 / (float)(int)retaddr;
      if ( v79 >= v78 )
        v79 = v78;
      goto LABEL_187;
    }
    if ( v73 == 2 )
    {
      v79 = FLOAT_3_4028235e38;
      v82 = FLOAT_3_4028235e38;
      if ( v9 >= 20 )
        v82 = (float)(v75 - v74) / (float)v9;
      if ( (int)retaddr >= 20 )
        v79 = (float)(v77 - v76) / (float)(int)retaddr;
      if ( v79 >= v82 )
        v79 = v82;
      if ( v79 != 3.4028235e38 )
      {
LABEL_187:
        if ( v79 != 1.0 )
        {
          v83 = &v60->mLineBuffer;
          if ( LODWORD(v60->mLineBuffer.Lines.Data.Size) )
          {
            v84 = 0i64;
            v85 = 0x7FFFFFFF;
            while ( p_mLineBuffer )
            {
              v86 = p_mLineBuffer->Lines.Data.Size;
              if ( (unsigned int)v84 >= v86 || (int)v84 < 0 )
                break;
              v87 = p_mLineBuffer->Lines.Data.Data[v84];
              if ( (v87->MemSize & 0x80000000) == 0 )
                v88 = v87->Data32.Height;
              else
                v88 = v87->Data8.Height;
              if ( v88 < v85 )
                v85 = v88;
              if ( (unsigned int)v84 < v86 )
                v84 = (unsigned int)(v84 + 1);
            }
            v60 = pdoc;
            v58 = (int)retaddr;
            v83 = &pdoc->mLineBuffer;
            if ( v85 > 0 && (float)((float)v85 * v79) < 120.0 )
              v79 = 120.0 / (float)v85;
          }
          v60->TextWidth = (int)(float)((float)v9 * v79);
          v60->TextHeight = (int)(float)((float)v58 * v79);
          Scaleform::Render::Text::LineBuffer::Scale(v83, v79);
        }
      }
    }
  }
  LOBYTE(v158) = 0;
  MaxVScroll = Scaleform::Render::Text::DocView::GetMaxVScroll(v60);
  if ( pdoc->mLineBuffer.Geom.FirstVisibleLinePos <= MaxVScroll )
  {
    v94 = (unsigned __int8)v158;
    if ( MaxVScroll != LODWORD(v156.pParagraph) )
      v94 = 1;
    v158 = v94;
    goto LABEL_213;
  }
  v90 = Scaleform::Render::Text::DocView::GetMaxVScroll(pdoc);
  if ( MaxVScroll > v90 )
    MaxVScroll = v90;
  v91 = pdoc;
  if ( pdoc->mLineBuffer.Geom.FirstVisibleLinePos == MaxVScroll )
  {
LABEL_213:
    v92 = p_mLineBuffer;
    goto LABEL_214;
  }
  v92 = &pdoc->mLineBuffer;
  pdoc->mLineBuffer.Geom.FirstVisibleLinePos = MaxVScroll;
  v91->mLineBuffer.Geom.Flags |= 1u;
  v93 = v91->pDocumentListener.pObject;
  if ( v93 )
  {
    ((void (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::Render::Text::DocView *, _QWORD))v93->vfptr[4].__vecDelDtor)(
      v93,
      v91,
      MaxVScroll);
    goto LABEL_213;
  }
LABEL_214:
  v95 = v59 == 0;
  v96 = pdoc;
  if ( v95 && v61 && (pdoc->Flags & 2) == 0 )
  {
    v97 = pdoc->ViewRect.x1 + 40.0;
    v98 = pdoc->ViewRect.x2 - 40.0;
    v99 = pdoc->ViewRect.y1 + 40.0;
    v100 = pdoc->ViewRect.y2 - 40.0;
    v101 = pdoc->mLineBuffer.Geom.VisibleRect.y2;
    v102 = pdoc->mLineBuffer.Geom.VisibleRect.x2;
    v103 = pdoc->mLineBuffer.Geom.VisibleRect.y1;
    v104 = pdoc->mLineBuffer.Geom.VisibleRect.x1;
    TextHeight = (float)(int)pdoc->TextHeight;
    v106 = v100 - v99;
    if ( TextHeight >= (float)(v100 - v99) )
    {
      if ( (unsigned int)(v61 - 2) <= 1 )
      {
        v109 = 0.0;
        BottomVScroll = Scaleform::Render::Text::DocView::GetBottomVScroll(pdoc);
        v111 = 0;
        v92 = &v96->mLineBuffer;
        while ( v96 != (Scaleform::Render::Text::DocView *)-80i64
             && (unsigned int)BottomVScroll < v96->mLineBuffer.Lines.Data.Size
             && BottomVScroll >= 0 )
        {
          v112 = v92->Lines.Data.Data[BottomVScroll];
          if ( (v112->MemSize & 0x80000000) == 0 )
            v113 = v112->Data32.Height;
          else
            v113 = v112->Data8.Height;
          if ( v111 )
          {
            if ( (v112->MemSize & 0x80000000) == 0 )
              v114 = v112->Data32.Leading;
            else
              v114 = v112->Data8.Leading;
            v113 += v114;
          }
          if ( (float)((float)v113 + v109) > v106 )
            break;
          v109 = (float)v113 + v109;
          --BottomVScroll;
          ++v111;
        }
        if ( v61 == 2 )
          v99 = v100 - v109;
        else
          v99 = (float)((float)(v106 * 0.5) - (float)(v109 * 0.5)) + v99;
      }
      v96->mLineBuffer.Geom.VisibleRect.x1 = v97;
      v96->mLineBuffer.Geom.VisibleRect.y1 = v99;
      v96->mLineBuffer.Geom.VisibleRect.x2 = v98;
      v96->mLineBuffer.Geom.VisibleRect.y2 = v100;
    }
    else
    {
      v107 = v61 - 1;
      if ( v107 )
      {
        v108 = v107 - 1;
        if ( v108 )
        {
          if ( v108 == 1 )
            v103 = (float)((float)(v106 * 0.5) - (float)(TextHeight * 0.5)) + v99;
        }
        else
        {
          v103 = v100 - TextHeight;
        }
      }
      else
      {
        v104 = pdoc->ViewRect.x1 + 40.0;
        v103 = pdoc->ViewRect.y1 + 40.0;
        v102 = pdoc->ViewRect.x2 - 40.0;
        v101 = pdoc->ViewRect.y2 - 40.0;
      }
      pdoc->mLineBuffer.Geom.VisibleRect.x1 = v104;
      v96->mLineBuffer.Geom.VisibleRect.y1 = v103;
      v96->mLineBuffer.Geom.VisibleRect.x2 = v102;
      v96->mLineBuffer.Geom.VisibleRect.y2 = v101;
    }
  }
  v115 = 0;
  if ( v156.NeedRecenterLines )
  {
    v116 = 0;
    while ( v92 && v116 < v96->mLineBuffer.Lines.Data.Size && (v116 & 0x80000000) == 0 )
    {
      v117 = v96->mLineBuffer.Lines.Data.Data[v116];
      v118 = v117->MemSize;
      if ( ((v117->MemSize >> 27) & 3) == 1 )
      {
        v123 = v96->mLineBuffer.Geom.VisibleRect.x2 - v96->mLineBuffer.Geom.VisibleRect.x1;
        if ( v123 <= 0.0 )
          v124 = v123 - 0.5;
        else
          v124 = v123 + 0.5;
        if ( v118 >= 0 )
          v125 = v117->Data32.Width;
        else
          v125 = v117->Data8.Width;
        v126 = (int)v124 - v125;
        if ( v126 < 0 )
          v126 = 0;
        v117->Data32.OffsetX = v126;
      }
      else if ( ((v117->MemSize >> 27) & 3) == 2 )
      {
        v119 = (float)(v96->mLineBuffer.Geom.VisibleRect.x2 - v96->mLineBuffer.Geom.VisibleRect.x1) * 0.5;
        if ( v119 <= 0.0 )
          v120 = v119 - 0.5;
        else
          v120 = v119 + 0.5;
        if ( v118 >= 0 )
          v121 = v117->Data32.Width;
        else
          v121 = v117->Data8.Width;
        v122 = (int)v120 - v121 / 2;
        if ( v122 < 0 )
          v122 = 0;
        v117->Data32.OffsetX = v122;
      }
      v92 = &v96->mLineBuffer;
      if ( v116 < v96->mLineBuffer.Lines.Data.Size )
      {
        ++v116;
        v92 = &v96->mLineBuffer;
      }
    }
  }
  if ( (v96->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(v96);
    v96->RTFlags &= 0xFCu;
  }
  v127 = 1200;
  if ( (v96->Flags & 8) == 0 )
  {
    v128 = v96->pEditorKit.pObject;
    if ( !v128
      || (v129 = ((__int64 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))v128->vfptr[2].__vecDelDtor)(v128),
          v130 = 1200,
          v129) )
    {
      v130 = 0;
    }
    TextWidth = v96->TextWidth;
    if ( TextWidth )
      v132 = (float)TextWidth;
    else
      v132 = 0.0;
    v133 = (float)(v132 - (float)(v96->mLineBuffer.Geom.VisibleRect.x2 - v96->mLineBuffer.Geom.VisibleRect.x1))
         + (float)v130;
    if ( v133 < 0.0 )
      v133 = 0.0;
    v115 = (int)v133;
  }
  if ( v96->mLineBuffer.Geom.HScrollOffset <= v115 )
  {
    v140 = v158;
    if ( v115 != HIDWORD(v156.pParagraph) )
      v140 = 1;
  }
  else
  {
    if ( (v96->RTFlags & 3) != 0 )
    {
      Scaleform::Render::Text::DocView::Format(v96);
      v96->RTFlags &= 0xFCu;
    }
    if ( (v96->Flags & 8) != 0 )
    {
      v134 = 0;
    }
    else
    {
      v135 = v96->pEditorKit.pObject;
      if ( !v135
        || ((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))v135->vfptr[2].__vecDelDtor)(v135) )
      {
        v127 = 0;
      }
      v136 = v96->TextWidth;
      if ( v136 )
        v137 = (float)v136;
      else
        v137 = 0.0;
      v138 = (float)(v137 - (float)(v96->mLineBuffer.Geom.VisibleRect.x2 - v96->mLineBuffer.Geom.VisibleRect.x1))
           + (float)v127;
      if ( v138 >= 0.0 )
        v8 = v138;
      v134 = (int)v8;
    }
    if ( v115 > v134 )
      v115 = v134;
    if ( v96->mLineBuffer.Geom.HScrollOffset != v115 )
    {
      v96->mLineBuffer.Geom.HScrollOffset = v115;
      v139 = v96->pDocumentListener.pObject;
      if ( v139 )
        ((void (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::Render::Text::DocView *, _QWORD))v139->vfptr[3].__vecDelDtor)(
          v139,
          v96,
          v115);
    }
    v140 = v158;
  }
  v141 = v96->pDocumentListener.pObject;
  if ( v141 )
  {
    if ( v140 && (v141->HandlersMask & 4) != 0 )
      v141->vfptr[5].__vecDelDtor(v141, (unsigned int)v96);
    v142 = v96->pDocumentListener.pObject;
    if ( (v142->HandlersMask & 8) != 0 )
      v142->vfptr[6].__vecDelDtor(v142, (unsigned int)v96);
  }
  v143 = v96->pEditorKit.pObject;
  if ( v143
    && !((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))v143->vfptr[2].__vecDelDtor)(v143)
    || (float)(int)v96->TextWidth > (float)(v96->ViewRect.x2 - v96->ViewRect.x1)
    || (float)(int)v96->TextHeight > (float)(v96->ViewRect.y2 - v96->ViewRect.y1)
    || v96->mLineBuffer.Geom.HScrollOffset )
  {
    v96->mLineBuffer.Geom.Flags &= ~0x20u;
  }
  else
  {
    v96->mLineBuffer.Geom.Flags |= 0x20u;
  }
  if ( v96->pHighlight )
  {
    v144 = v96->pEditorKit.pObject;
    if ( v144 )
      v145 = (Scaleform::Render::Text::CompositionStringBase *)((__int64 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))v144->vfptr[7].__vecDelDtor)(v144);
    else
      v145 = 0i64;
    Scaleform::Render::Text::Highlighter::UpdateGlyphIndices(&v96->pHighlight->HighlightManager, v145);
  }
  v96->RTFlags &= ~0x20u;
  if ( v96->mLineBuffer.Lines.Data.Size )
  {
    v146 = *v96->mLineBuffer.Lines.Data.Data;
    if ( (v146->MemSize & 0x80000000) == 0 ? v146->Data32.GlyphsCount : (unsigned __int8)v146->Data8.GlyphsCount )
    {
      FirstFontInfo = Scaleform::Render::Text::LineBuffer::FindFirstFontInfo(&v96->mLineBuffer);
      if ( FirstFontInfo )
      {
        if ( (FirstFontInfo->pFont.pObject->Flags & 0x8000) != 0 )
          v96->RTFlags |= 0x20u;
      }
    }
  }
  Scaleform::Render::Text::ParagraphFormatter::~ParagraphFormatter(&v156);
}caleform::Render::Text::CompositionStringBase *)((__int64 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))v144->vfptr[7].__vecDelDtor)(v144);
    else
      v145 = 0i64;
    Scaleform::Render::Text::Highlighter::UpdateGlyphIndices(&v96->pHighlight->HighlightManager, v145);
  }
  v96->RTFlags &= ~0x20u;
  if ( v96->mLineBuffer.Lines.Data.Size )
  {
    v146 = *v96->mLineBuffer.Lines.Data.Data;
    if ( (v146->MemSize & 0x80000000) == 0 ? v146->Data32.GlyphsCount : (unsigned __int8)v146->Data8.GlyphsCount )
    {
      FirstFontInfo = Scaleform::Render::Text

// File Line: 2630
// RVA: 0x969900
void __fastcall Scaleform::Render::Text::DocView::CreateVisibleTextLayout(
        Scaleform::Render::Text::DocView *this,
        Scaleform::Render::TextLayout::Builder *bld)
{
  Scaleform::Render::Text::DocView::HighlightDescLoc *pHighlight; // rax
  Scaleform::Render::Text::EditorKitBase *pObject; // rcx
  Scaleform::Render::Text::CompositionStringBase *v6; // rax
  char Flags; // dl
  __int16 v8; // cx
  __int16 v9; // ax
  char RTFlags; // dl
  __int16 v11; // ax
  __int16 v12; // cx
  char FlagsEx; // al
  __int16 v14; // cx
  __int16 v15; // cx
  Scaleform::Render::Text::DocView::HighlightDescLoc *v16; // r8
  unsigned int BorderColor; // ecx
  unsigned int BackgroundColor; // eax
  char *v19; // rdi
  int v20; // esi
  Scaleform::Render::Text::EditorKitBase *v21; // rcx
  float x1; // eax
  float y2; // xmm2_4
  float y1; // xmm0_4
  char val[4]; // [rsp+20h] [rbp-50h] BYREF
  unsigned int v26; // [rsp+24h] [rbp-4Ch]
  unsigned int v27; // [rsp+28h] [rbp-48h]
  Scaleform::Render::TextFieldParam params; // [rsp+30h] [rbp-40h] BYREF

  if ( (this->RTFlags & 0x40) == 0 )
  {
    pHighlight = this->pHighlight;
    if ( pHighlight )
    {
      if ( !pHighlight->HighlightManager.Valid )
      {
        pObject = this->pEditorKit.pObject;
        if ( pObject )
          v6 = (Scaleform::Render::Text::CompositionStringBase *)((__int64 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))pObject->vfptr[7].__vecDelDtor)(pObject);
        else
          v6 = 0i64;
        Scaleform::Render::Text::Highlighter::UpdateGlyphIndices(&this->pHighlight->HighlightManager, v6);
        this->pHighlight->HighlightManager.Valid = 1;
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
  Scaleform::Render::Text::LoadTextFieldParamFromTextFilter(&params, &this->Filter);
  Flags = this->Flags;
  v8 = params.TextParam.Flags;
  v9 = params.ShadowParam.Flags;
  if ( (Flags & 0x40) != 0 )
  {
    v8 = params.TextParam.Flags | 1;
    v9 = params.ShadowParam.Flags | 1;
    params.ShadowParam.Flags |= 1u;
  }
  if ( Flags < 0 )
  {
    v8 |= 2u;
    params.ShadowParam.Flags = v9 | 2;
  }
  RTFlags = this->RTFlags;
  if ( (RTFlags & 0x20) != 0 )
  {
    v8 = v8 & 0xFEFC | 0x101;
    v11 = -5;
  }
  else
  {
    v11 = -257;
  }
  v12 = v11 & v8;
  FlagsEx = this->FlagsEx;
  if ( (FlagsEx & 1) != 0 )
    v14 = v12 | 8;
  else
    v14 = v12 & 0xFFF7;
  if ( (FlagsEx & 2) != 0 )
    v15 = v14 | 0x10;
  else
    v15 = v14 & 0xFFEF;
  v16 = this->pHighlight;
  params.TextParam.Flags = v15 & 0xFFF | ((unsigned __int16)(int)this->Outline << 12);
  if ( !v16 || (RTFlags & 0x40) != 0 )
    v16 = 0i64;
  Scaleform::Render::Text::LineBuffer::CreateVisibleTextLayout(&this->mLineBuffer, bld, &v16->HighlightManager, &params);
  BorderColor = this->BorderColor;
  if ( HIBYTE(BorderColor) || HIBYTE(this->BackgroundColor) )
  {
    BackgroundColor = this->BackgroundColor;
    *(_DWORD *)val = 2;
    v27 = BorderColor;
    v19 = val;
    v26 = BackgroundColor;
    v20 = 12;
    do
    {
      Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(&bld->Data, v19++);
      --v20;
    }
    while ( v20 );
  }
  v21 = this->pEditorKit.pObject;
  if ( v21 )
    v21->vfptr[1].__vecDelDtor(v21, (unsigned int)bld);
  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  x1 = this->ViewRect.x1;
  y2 = this->ViewRect.y2;
  y1 = this->ViewRect.y1;
  bld->Bounds.x2 = this->ViewRect.x2;
  bld->Bounds.y2 = y2;
  bld->Bounds.x1 = x1;
  bld->Bounds.y1 = y1;
}

// File Line: 2673
// RVA: 0x9B09E0
char __fastcall Scaleform::Render::Text::DocView::SetHScrollOffset(
        Scaleform::Render::Text::DocView *this,
        unsigned int hscroll)
{
  unsigned int MaxHScrollValue; // eax
  Scaleform::Render::Text::DocView::DocumentListener *pObject; // rcx

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  MaxHScrollValue = Scaleform::Render::Text::DocView::GetMaxHScrollValue(this);
  if ( hscroll > MaxHScrollValue )
    hscroll = MaxHScrollValue;
  if ( this->mLineBuffer.Geom.HScrollOffset == hscroll )
    return 0;
  pObject = this->pDocumentListener.pObject;
  this->mLineBuffer.Geom.HScrollOffset = hscroll;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::Render::Text::DocView *, _QWORD))pObject->vfptr[3].__vecDelDtor)(
      pObject,
      this,
      hscroll);
  return 1;
}

// File Line: 2691
// RVA: 0x9B5690
char __fastcall Scaleform::Render::Text::DocView::SetVScrollOffset(
        Scaleform::Render::Text::DocView *this,
        unsigned int vscroll)
{
  unsigned int MaxVScroll; // eax
  Scaleform::Render::Text::DocView::DocumentListener *pObject; // rcx

  MaxVScroll = Scaleform::Render::Text::DocView::GetMaxVScroll(this);
  if ( vscroll > MaxVScroll )
    vscroll = MaxVScroll;
  if ( this->mLineBuffer.Geom.FirstVisibleLinePos == vscroll )
    return 0;
  this->mLineBuffer.Geom.FirstVisibleLinePos = vscroll;
  this->mLineBuffer.Geom.Flags |= 1u;
  pObject = this->pDocumentListener.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::Render::Text::DocView *, _QWORD))pObject->vfptr[4].__vecDelDtor)(
      pObject,
      this,
      vscroll);
  return 1;
}

// File Line: 2709
// RVA: 0x985240
__int64 __fastcall Scaleform::Render::Text::DocView::GetHScrollOffset(Scaleform::Render::Text::DocView *this)
{
  if ( (this->RTFlags & 3) == 0 )
    return this->mLineBuffer.Geom.HScrollOffset;
  Scaleform::Render::Text::DocView::Format(this);
  this->RTFlags &= 0xFCu;
  return this->mLineBuffer.Geom.HScrollOffset;
}

// File Line: 2720
// RVA: 0x98EB50
__int64 __fastcall Scaleform::Render::Text::DocView::GetVScrollOffset(Scaleform::Render::Text::DocView *this)
{
  if ( (this->RTFlags & 3) == 0 )
    return this->mLineBuffer.Geom.FirstVisibleLinePos;
  Scaleform::Render::Text::DocView::Format(this);
  this->RTFlags &= 0xFCu;
  return this->mLineBuffer.Geom.FirstVisibleLinePos;
}

// File Line: 2731
// RVA: 0x98D8D0
float __fastcall Scaleform::Render::Text::DocView::GetTextWidth(Scaleform::Render::Text::DocView *this)
{
  signed int TextWidth; // eax
  float result; // xmm0_4

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  TextWidth = this->TextWidth;
  result = 0.0;
  if ( TextWidth )
    return (float)TextWidth;
  return result;
}

// File Line: 2743
// RVA: 0x98D890
float __fastcall Scaleform::Render::Text::DocView::GetTextHeight(Scaleform::Render::Text::DocView *this)
{
  signed int TextHeight; // eax
  float result; // xmm0_4

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  TextHeight = this->TextHeight;
  result = 0.0;
  if ( TextHeight )
    return (float)TextHeight;
  return result;
}

// File Line: 2756
// RVA: 0x988B60
__int64 __fastcall Scaleform::Render::Text::DocView::GetLinesCount(Scaleform::Render::Text::DocView *this)
{
  if ( (this->RTFlags & 3) == 0 )
    return LODWORD(this->mLineBuffer.Lines.Data.Size);
  Scaleform::Render::Text::DocView::Format(this);
  this->RTFlags &= 0xFCu;
  return LODWORD(this->mLineBuffer.Lines.Data.Size);
}

// File Line: 2767
// RVA: 0x988FA0
__int64 __fastcall Scaleform::Render::Text::DocView::GetMaxHScrollValue(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // rcx
  int v4; // ecx
  signed int TextWidth; // eax
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm1_4

  if ( (this->Flags & 8) != 0 )
    return 0i64;
  pObject = this->pEditorKit.pObject;
  if ( !pObject
    || ((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))pObject->vfptr[2].__vecDelDtor)(pObject) )
  {
    v4 = 0;
  }
  else
  {
    v4 = 1200;
  }
  TextWidth = this->TextWidth;
  v6 = 0.0;
  if ( TextWidth )
    v7 = (float)TextWidth;
  else
    v7 = 0.0;
  v8 = (float)(v7 - (float)(this->mLineBuffer.Geom.VisibleRect.x2 - this->mLineBuffer.Geom.VisibleRect.x1)) + (float)v4;
  if ( v8 >= 0.0 )
    v6 = v8;
  return (unsigned int)(int)v6;
}

// File Line: 2782
// RVA: 0x988F70
__int64 __fastcall Scaleform::Render::Text::DocView::GetMaxHScroll(Scaleform::Render::Text::DocView *this)
{
  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  return Scaleform::Render::Text::DocView::GetMaxHScrollValue(this);
}

// File Line: 2793
// RVA: 0x989070
__int64 __fastcall Scaleform::Render::Text::DocView::GetMaxVScroll(Scaleform::Render::Text::DocView *this)
{
  unsigned __int16 FormatCounter; // ax
  __int64 result; // rax
  Scaleform::Render::Text::EditorKitBase *pObject; // rcx
  int v5; // esi
  __int64 v6; // rdi
  Scaleform::Render::Text::LineBuffer::Line *v7; // r14
  unsigned __int64 Size; // r8
  Scaleform::Render::Text::LineBuffer::Line **Data; // r9
  Scaleform::Render::Text::LineBuffer::Line *v11; // rax
  unsigned int Height; // edx

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  FormatCounter = this->FormatCounter;
  if ( this->MaxVScroll.FormatCounter == FormatCounter )
    return this->MaxVScroll.Value;
  if ( !LODWORD(this->mLineBuffer.Lines.Data.Size) )
  {
    this->MaxVScroll.Value = 0;
    this->MaxVScroll.FormatCounter = FormatCounter;
    return this->MaxVScroll.Value;
  }
  pObject = this->pEditorKit.pObject;
  v5 = 0;
  v6 = (unsigned int)(LODWORD(this->mLineBuffer.Lines.Data.Size) - 1);
  v7 = this->mLineBuffer.Lines.Data.Data[(unsigned int)v6];
  if ( (!pObject
     || ((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))pObject->vfptr[2].__vecDelDtor)(pObject))
    && !((v7->MemSize & 0x80000000) == 0 ? v7->Data32.TextLength : HIBYTE(v7->Data8.TextPosAndLength)) )
  {
    if ( (int)v6 >= 0 )
      v6 = (unsigned int)(v6 - 1);
    v5 = 1;
  }
  Size = this->mLineBuffer.Lines.Data.Size;
  if ( (unsigned int)v6 >= Size || (int)v6 < 0 )
  {
    this->MaxVScroll.FormatCounter = this->FormatCounter;
    this->MaxVScroll.Value = 0;
    return this->MaxVScroll.Value;
  }
  else
  {
    Data = this->mLineBuffer.Lines.Data.Data;
    v11 = Data[v6];
    if ( (v11->MemSize & 0x80000000) == 0 )
      Height = v11->Data32.Height;
    else
      Height = v11->Data8.Height;
    while ( (unsigned int)v6 < Size
         && (int)v6 >= 0
         && (!v5
          || (float)Data[v6]->Data32.OffsetY >= (float)((float)((float)(int)(v11->Data32.OffsetY + Height)
                                                              - this->mLineBuffer.Geom.VisibleRect.y2)
                                                      + this->mLineBuffer.Geom.VisibleRect.y1)) )
    {
      v6 = (unsigned int)(v6 - 1);
      ++v5;
    }
    result = (unsigned int)(Size - v5);
    this->MaxVScroll.FormatCounter = this->FormatCounter;
    this->MaxVScroll.Value = result;
  }
  return result;
}

// File Line: 2847
// RVA: 0x9AE2D0
void __fastcall Scaleform::Render::Text::DocView::SetAutoSizeX(Scaleform::Render::Text::DocView *this)
{
  char Flags; // al

  Flags = this->Flags;
  if ( (Flags & 1) == 0 )
  {
    this->RTFlags |= 2u;
    this->Flags = Flags | 1;
  }
}

// File Line: 2856
// RVA: 0x9AE2F0
void __fastcall Scaleform::Render::Text::DocView::SetAutoSizeY(Scaleform::Render::Text::DocView *this)
{
  char Flags; // al

  Flags = this->Flags;
  if ( (Flags & 2) == 0 )
  {
    this->RTFlags |= 2u;
    this->Flags = Flags | 2;
  }
}

// File Line: 2865
// RVA: 0x9B5F20
void __fastcall Scaleform::Render::Text::DocView::SetWordWrap(Scaleform::Render::Text::DocView *this)
{
  char Flags; // al

  Flags = this->Flags;
  if ( (Flags & 8) == 0 )
  {
    this->RTFlags |= 2u;
    this->Flags = Flags | 8;
  }
}

// File Line: 2874
// RVA: 0x960630
void __fastcall Scaleform::Render::Text::DocView::ClearWordWrap(Scaleform::Render::Text::DocView *this)
{
  char Flags; // al

  Flags = this->Flags;
  if ( (Flags & 8) != 0 )
  {
    this->RTFlags |= 2u;
    this->Flags = Flags & 0xF7;
  }
}

// File Line: 2883
// RVA: 0x97AE90
char __fastcall Scaleform::Render::Text::DocView::ForceReformat(Scaleform::Render::Text::DocView *this)
{
  if ( (this->RTFlags & 3) == 0 )
    return 0;
  Scaleform::Render::Text::DocView::Format(this);
  this->RTFlags &= 0xFCu;
  return 1;
}

// File Line: 2894
// RVA: 0x98FC00
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::Text::DocView::GetViewRect(
        Scaleform::Render::Text::DocView *this)
{
  if ( (this->RTFlags & 3) == 0 )
    return &this->ViewRect;
  Scaleform::Render::Text::DocView::Format(this);
  this->RTFlags &= 0xFCu;
  return &this->ViewRect;
}

// File Line: 2900
// RVA: 0x981320
__int64 __fastcall Scaleform::Render::Text::DocView::GetCharIndexAtPoint(
        Scaleform::Render::Text::DocView *this,
        float x,
        float y)
{
  float v4; // xmm6_4
  Scaleform::Render::Text::LineBuffer *p_mLineBuffer; // rcx
  int v6; // edx
  unsigned __int64 FirstVisibleLinePos; // rax
  Scaleform::Render::Text::LineBuffer::Line *v8; // rdi
  float OffsetX; // xmm1_4
  int v10; // eax
  float v11; // xmm6_4
  int v12; // ebx
  int v13; // esi
  int Advance; // eax
  unsigned int Delta; // edx
  int TextPos; // eax
  __int64 v17; // rbx
  Scaleform::Render::Text::ImageDesc *pObject; // rcx
  Scaleform::Render::Text::FontHandle *v19; // rcx
  Scaleform::Render::Text::LineBuffer::Iterator result; // [rsp+28h] [rbp-F0h] BYREF
  Scaleform::Render::Text::LineBuffer::GlyphIterator v22; // [rsp+50h] [rbp-C8h] BYREF

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  v4 = x - (float)(this->mLineBuffer.Geom.VisibleRect.x1 - this->ViewRect.x1);
  p_mLineBuffer = &this->mLineBuffer;
  v6 = 0;
  FirstVisibleLinePos = this->mLineBuffer.Geom.FirstVisibleLinePos;
  if ( (_DWORD)FirstVisibleLinePos
    && this != (Scaleform::Render::Text::DocView *)-80i64
    && FirstVisibleLinePos < this->mLineBuffer.Lines.Data.Size
    && (FirstVisibleLinePos & 0x80000000) == 0i64
    && this->mLineBuffer.Lines.Data.Size )
  {
    v6 = p_mLineBuffer->Lines.Data.Data[(unsigned int)FirstVisibleLinePos]->Data32.OffsetY
       - (*p_mLineBuffer->Lines.Data.Data)->Data32.OffsetY;
  }
  Scaleform::Render::Text::LineBuffer::FindLineAtYOffset(
    p_mLineBuffer,
    &result,
    (float)v6 + (float)(y - (float)(this->mLineBuffer.Geom.VisibleRect.y1 - this->ViewRect.y1)));
  if ( !result.pLineBuffer )
    return -1i64;
  if ( result.CurrentPos >= result.pLineBuffer->Lines.Data.Size )
    return -1i64;
  if ( (result.CurrentPos & 0x80000000) != 0 )
    return -1i64;
  v8 = result.pLineBuffer->Lines.Data.Data[result.CurrentPos];
  OffsetX = (float)v8->Data32.OffsetX;
  if ( v4 < OffsetX )
    return -1i64;
  v10 = (v8->MemSize & 0x80000000) == 0 ? v8->Data32.Width : v8->Data8.Width;
  if ( v4 > (float)((float)v10 + OffsetX) )
    return -1i64;
  v11 = v4 - OffsetX;
  v12 = 0;
  Scaleform::Render::Text::LineBuffer::Line::Begin(v8, &v22);
  v13 = 0;
  while ( v22.pGlyphs && v22.pGlyphs < v22.pEndGlyphs )
  {
    Advance = v22.pGlyphs->Advance;
    if ( (v22.pGlyphs->Flags & 0x40) != 0 )
      Advance = -Advance;
    v12 += Advance;
    if ( (float)v12 > v11 )
      break;
    v13 += v22.pGlyphs->LenAndFontSize >> 12;
    Delta = v22.Delta;
    if ( !v22.Delta )
      Delta = v22.pGlyphs->LenAndFontSize >> 12;
    v22.Delta = Delta;
    ++v22.pGlyphs;
    if ( (v22.pGlyphs->LenAndFontSize & 0xF000) != 0
      && Delta
      && v22.HighlighterIter.CurAdjStartPos < v22.HighlighterIter.NumGlyphs )
    {
      v22.HighlighterIter.CurAdjStartPos += Delta;
      Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(&v22.HighlighterIter);
      v22.Delta = 0;
    }
    Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&v22);
  }
  TextPos = v8->Data32.TextPos;
  if ( (v8->MemSize & 0x80000000) != 0 )
  {
    TextPos &= 0xFFFFFFu;
    if ( TextPos == 0xFFFFFF )
      TextPos = -1;
  }
  v17 = (unsigned int)(v13 + TextPos);
  pObject = v22.pImage.pObject;
  if ( v22.pImage.pObject )
  {
    --v22.pImage.pObject->RefCount;
    if ( !pObject->RefCount )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
  }
  v19 = v22.pFontHandle.pObject;
  if ( v22.pFontHandle.pObject && !_InterlockedDecrement(&v22.pFontHandle.pObject->RefCount) && v19 )
    v19->vfptr->__vecDelDtor(v19, 1u);
  return v17;
}

// File Line: 2936
// RVA: 0x981CA0
unsigned __int64 __fastcall Scaleform::Render::Text::DocView::GetCursorPosInLine(
        Scaleform::Render::Text::DocView *this,
        unsigned int lineIndex,
        float x)
{
  if ( lineIndex >= LODWORD(this->mLineBuffer.Lines.Data.Size) )
    return -1i64;
  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  return Scaleform::Render::Text::DocView::GetCursorPosInLineByOffset(this, lineIndex, x);
}

// File Line: 2945
// RVA: 0x981D10
unsigned __int64 __fastcall Scaleform::Render::Text::DocView::GetCursorPosInLineByOffset(
        Scaleform::Render::Text::DocView *this,
        unsigned int lineIndex,
        float relativeOffsetX)
{
  Scaleform::Render::Text::LineBuffer::Line *v4; // rdi
  float v5; // xmm6_4
  int v6; // esi
  int v7; // ebx
  unsigned __int16 Flags; // r8
  unsigned int Advance; // edx
  unsigned int Delta; // eax
  int TextPos; // eax
  __int64 v12; // rbx
  Scaleform::Render::Text::ImageDesc *pObject; // rcx
  Scaleform::Render::Text::FontHandle *v14; // rcx
  Scaleform::Render::Text::LineBuffer::GlyphIterator result; // [rsp+30h] [rbp-B8h] BYREF

  if ( lineIndex >= LODWORD(this->mLineBuffer.Lines.Data.Size) )
    return -1i64;
  v4 = this->mLineBuffer.Lines.Data.Data[lineIndex];
  v5 = (float)(relativeOffsetX - (float)v4->Data32.OffsetX) + (float)(int)this->mLineBuffer.Geom.HScrollOffset;
  v6 = 0;
  Scaleform::Render::Text::LineBuffer::Line::Begin(v4, &result);
  v7 = 0;
  while ( result.pGlyphs && result.pGlyphs < result.pEndGlyphs )
  {
    Flags = result.pGlyphs->Flags;
    Advance = result.pGlyphs->Advance;
    if ( (Flags & 0x40) != 0 )
      Advance = -Advance;
    if ( (float)(int)(Advance + v6) > v5 )
    {
      if ( (float)(v5 - (float)v6) > (float)(Advance >> 1) )
        v7 += result.pGlyphs->LenAndFontSize >> 12;
      break;
    }
    v6 += Advance;
    if ( (Flags & 0x100) == 0 )
      v7 += result.pGlyphs->LenAndFontSize >> 12;
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
  TextPos = v4->Data32.TextPos;
  if ( (v4->MemSize & 0x80000000) != 0 )
  {
    TextPos &= 0xFFFFFFu;
    if ( TextPos == 0xFFFFFF )
      TextPos = -1;
  }
  v12 = (unsigned int)(TextPos + v7);
  pObject = result.pImage.pObject;
  if ( result.pImage.pObject )
  {
    --result.pImage.pObject->RefCount;
    if ( !pObject->RefCount )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
  }
  v14 = result.pFontHandle.pObject;
  if ( result.pFontHandle.pObject && !_InterlockedDecrement(&result.pFontHandle.pObject->RefCount) && v14 )
    v14->vfptr->__vecDelDtor(v14, 1u);
  return v12;
}

// File Line: 2983
// RVA: 0x981B30
__int64 __fastcall Scaleform::Render::Text::DocView::GetCursorPosAtPoint(
        Scaleform::Render::Text::DocView *this,
        float x,
        float y)
{
  unsigned __int64 FirstVisibleLinePos; // rax
  int v5; // ecx
  float v6; // xmm7_4
  float v7; // xmm6_4
  Scaleform::Render::Text::LineBuffer *pLineBuffer; // rdx
  int CurrentPos; // ecx
  Scaleform::Render::Text::LineBuffer::Iterator result; // [rsp+20h] [rbp-68h] BYREF
  __int64 v12; // [rsp+50h] [rbp-38h]
  __int64 v13; // [rsp+58h] [rbp-30h]

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  FirstVisibleLinePos = this->mLineBuffer.Geom.FirstVisibleLinePos;
  v5 = 0;
  v6 = x - (float)(this->mLineBuffer.Geom.VisibleRect.x1 - this->ViewRect.x1);
  v7 = y - (float)(this->mLineBuffer.Geom.VisibleRect.y1 - this->ViewRect.y1);
  if ( (_DWORD)FirstVisibleLinePos
    && this != (Scaleform::Render::Text::DocView *)-80i64
    && FirstVisibleLinePos < this->mLineBuffer.Lines.Data.Size
    && (FirstVisibleLinePos & 0x80000000) == 0i64
    && this->mLineBuffer.Lines.Data.Size )
  {
    v5 = this->mLineBuffer.Lines.Data.Data[(unsigned int)FirstVisibleLinePos]->Data32.OffsetY
       - (*this->mLineBuffer.Lines.Data.Data)->Data32.OffsetY;
  }
  Scaleform::Render::Text::LineBuffer::FindLineAtYOffset(&this->mLineBuffer, &result, (float)v5 + v7);
  pLineBuffer = result.pLineBuffer;
  if ( !result.pLineBuffer
    || (CurrentPos = result.CurrentPos, result.CurrentPos >= result.pLineBuffer->Lines.Data.Size)
    || (result.CurrentPos & 0x80000000) != 0 )
  {
    pLineBuffer = &this->mLineBuffer;
    result.pHighlight = 0i64;
    if ( v7 > 0.0 )
      v12 = (unsigned int)(LODWORD(this->mLineBuffer.Lines.Data.Size) - 1);
    else
      v12 = 0i64;
    CurrentPos = v12;
    LOBYTE(v13) = (this->mLineBuffer.Geom.Flags & 4) != 0;
    *(_QWORD *)&result.StaticText = v13;
  }
  if ( pLineBuffer && (unsigned int)CurrentPos < pLineBuffer->Lines.Data.Size && CurrentPos >= 0 )
    return Scaleform::Render::Text::DocView::GetCursorPosInLineByOffset(this, CurrentPos, v6);
  else
    return -(__int64)(LODWORD(this->mLineBuffer.Lines.Data.Size) != 0);
}

// File Line: 3005
// RVA: 0x997EE0
__int64 __fastcall Scaleform::Render::Text::DocView::IsUrlAtPoint(
        Scaleform::Render::Text::DocView *this,
        float x,
        float y,
        Scaleform::Range *purlPosRange)
{
  float v6; // xmm6_4
  Scaleform::Render::Text::LineBuffer *p_mLineBuffer; // rcx
  int v8; // edx
  unsigned __int64 FirstVisibleLinePos; // rax
  unsigned __int8 v10; // r12
  Scaleform::Render::Text::LineBuffer::Line *v11; // r14
  float OffsetX; // xmm1_4
  int v13; // eax
  float v14; // xmm6_4
  int v15; // edi
  int v16; // r15d
  __int64 v17; // r8
  int Advance; // eax
  unsigned int Delta; // edx
  int TextPos; // eax
  unsigned __int64 v21; // r14
  Scaleform::Render::Text::Paragraph *v22; // rsi
  Scaleform::Render::Text::TextFormat *TextFormat; // rax
  unsigned __int64 v24; // rdi
  Scaleform::Render::Text::TextFormat *pObject; // rcx
  unsigned __int8 *v26; // rax
  unsigned __int64 v27; // r8
  int v28; // ecx
  int v29; // edx
  unsigned __int64 Size; // rax
  Scaleform::Render::Text::TextFormat *v31; // rbx
  Scaleform::Render::Text::ImageDesc *v33; // rcx
  Scaleform::Render::Text::FontHandle *v34; // rcx
  Scaleform::Render::Text::Paragraph::FormatRunIterator v36; // [rsp+20h] [rbp-B8h] BYREF
  Scaleform::Render::Text::LineBuffer::Iterator result; // [rsp+68h] [rbp-70h] BYREF
  Scaleform::Render::Text::LineBuffer::GlyphIterator v38; // [rsp+88h] [rbp-50h] BYREF
  Scaleform::Render::Text::TextFormat v39; // [rsp+128h] [rbp+50h] BYREF
  Scaleform::Render::Text::TextFormat v40; // [rsp+178h] [rbp+A0h] BYREF
  unsigned __int64 pindexInParagraph[3]; // [rsp+218h] [rbp+140h] BYREF

  v36.CurTextIndex = -2i64;
  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  v6 = x - (float)(this->mLineBuffer.Geom.VisibleRect.x1 - this->ViewRect.x1);
  p_mLineBuffer = &this->mLineBuffer;
  v8 = 0;
  FirstVisibleLinePos = this->mLineBuffer.Geom.FirstVisibleLinePos;
  if ( (_DWORD)FirstVisibleLinePos
    && this != (Scaleform::Render::Text::DocView *)-80i64
    && FirstVisibleLinePos < this->mLineBuffer.Lines.Data.Size
    && (FirstVisibleLinePos & 0x80000000) == 0i64
    && this->mLineBuffer.Lines.Data.Size )
  {
    v8 = p_mLineBuffer->Lines.Data.Data[(unsigned int)FirstVisibleLinePos]->Data32.OffsetY
       - (*p_mLineBuffer->Lines.Data.Data)->Data32.OffsetY;
  }
  Scaleform::Render::Text::LineBuffer::FindLineAtYOffset(
    p_mLineBuffer,
    &result,
    (float)v8 + (float)(y - (float)(this->mLineBuffer.Geom.VisibleRect.y1 - this->ViewRect.y1)));
  v10 = 0;
  if ( result.pLineBuffer )
  {
    if ( result.CurrentPos < result.pLineBuffer->Lines.Data.Size && (result.CurrentPos & 0x80000000) == 0 )
    {
      v11 = result.pLineBuffer->Lines.Data.Data[result.CurrentPos];
      OffsetX = (float)v11->Data32.OffsetX;
      if ( v6 >= OffsetX )
      {
        v13 = (v11->MemSize & 0x80000000) == 0 ? v11->Data32.Width : v11->Data8.Width;
        if ( v6 <= (float)((float)v13 + OffsetX) )
        {
          v14 = (float)(v6 - OffsetX) + (float)(int)this->mLineBuffer.Geom.HScrollOffset;
          v15 = 0;
          Scaleform::Render::Text::LineBuffer::Line::Begin(v11, &v38);
          v16 = 0;
          while ( 1 )
          {
            v17 = 61440i64;
            if ( !v38.pGlyphs || v38.pGlyphs >= v38.pEndGlyphs )
              goto LABEL_64;
            Advance = v38.pGlyphs->Advance;
            if ( (v38.pGlyphs->Flags & 0x40) != 0 )
              Advance = -Advance;
            v15 += Advance;
            if ( (float)v15 > v14 )
              break;
            v16 += v38.pGlyphs->LenAndFontSize >> 12;
            Delta = v38.Delta;
            if ( !v38.Delta )
              Delta = v38.pGlyphs->LenAndFontSize >> 12;
            v38.Delta = Delta;
            ++v38.pGlyphs;
            if ( (v38.pGlyphs->LenAndFontSize & 0xF000) != 0
              && Delta
              && v38.HighlighterIter.CurAdjStartPos < v38.HighlighterIter.NumGlyphs )
            {
              v38.HighlighterIter.CurAdjStartPos += Delta;
              Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(&v38.HighlighterIter);
              v38.Delta = 0;
            }
            Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&v38);
          }
          v10 = LOBYTE(v38.pGlyphs->Flags) >> 7;
          if ( SLOBYTE(v38.pGlyphs->Flags) < 0 && purlPosRange )
          {
            purlPosRange->Index = 0i64;
            purlPosRange->Length = 0i64;
            TextPos = v11->Data32.TextPos;
            if ( (v11->MemSize & 0x80000000) != 0 )
            {
              TextPos &= 0xFFFFFFu;
              if ( TextPos == 0xFFFFFF )
                TextPos = -1;
            }
            v21 = (unsigned int)(v16 + TextPos);
            pindexInParagraph[0] = 0i64;
            Scaleform::Render::Text::StyledText::GetParagraphByIndex(
              this->pDocument.pObject,
              (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator *)&result.pHighlight,
              v21,
              pindexInParagraph);
            if ( result.pHighlight )
            {
              if ( *(__int64 *)&result.CurrentPos >= 0
                && *(__int64 *)&result.CurrentPos < SLODWORD(result.pHighlight->Highlighters.Data.Size) )
              {
                v22 = (Scaleform::Render::Text::Paragraph *)*(&result.pHighlight->Highlighters.Data.Data->StartPos
                                                            + *(_QWORD *)&result.CurrentPos);
                TextFormat = Scaleform::Render::Text::Paragraph::GetTextFormat(
                               v22,
                               &v40,
                               pindexInParagraph[0],
                               pindexInParagraph[0] + 1);
                Scaleform::Render::Text::TextFormat::TextFormat(&v39, TextFormat, 0i64);
                Scaleform::Render::Text::TextFormat::~TextFormat(&v40);
                Scaleform::Render::Text::Paragraph::GetIterator(v22, &v36);
                if ( v36.CurTextIndex < v36.pText->Size )
                {
                  do
                  {
                    v24 = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v36)->PlaceHolder.Index
                        + v22->StartIndex;
                    pObject = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v36)->PlaceHolder.pFormat.pObject;
                    if ( (pObject->PresentMask & 0x100) == 0 || !Scaleform::String::GetLength(&pObject->Url) )
                      goto LABEL_49;
                    v26 = (unsigned __int8 *)((Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v36)->PlaceHolder.pFormat.pObject->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                            + 12);
                    v27 = (v39.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12 - (_QWORD)v26;
                    do
                    {
                      v28 = v26[v27];
                      v29 = *v26 - v28;
                      if ( v29 )
                        break;
                      ++v26;
                    }
                    while ( v28 );
                    if ( !v29 )
                    {
                      if ( purlPosRange->Index + purlPosRange->Length >= v24 )
                      {
                        purlPosRange->Length += Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v36)->PlaceHolder.Length;
                      }
                      else
                      {
                        if ( v24 > v21 )
                          break;
                        purlPosRange->Index = v24;
                        purlPosRange->Length = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v36)->PlaceHolder.Length;
                      }
                    }
                    else
                    {
LABEL_49:
                      if ( v24 > v21 )
                        break;
                      purlPosRange->Index = 0i64;
                      purlPosRange->Length = 0i64;
                    }
                    if ( v36.FormatIterator.Index < 0
                      || v36.FormatIterator.Index >= v36.FormatIterator.pArray->Ranges.Data.Size )
                    {
                      Size = v36.pText->Size;
                    }
                    else
                    {
                      if ( v36.CurTextIndex >= v36.FormatIterator.pArray->Ranges.Data.Data[v36.FormatIterator.Index].Index )
                      {
                        Size = v36.FormatIterator.pArray->Ranges.Data.Data[v36.FormatIterator.Index].Length
                             + v36.CurTextIndex;
                        v36.CurTextIndex = Size;
                        if ( v36.FormatIterator.Index < (signed __int64)v36.FormatIterator.pArray->Ranges.Data.Size )
                          ++v36.FormatIterator.Index;
                        continue;
                      }
                      Size = v36.FormatIterator.pArray->Ranges.Data.Data[v36.FormatIterator.Index].Index;
                    }
                    v36.CurTextIndex = Size;
                  }
                  while ( Size < v36.pText->Size );
                }
                v36.pText = (Scaleform::Render::Text::Paragraph::TextBuffer *)&v36;
                v31 = v36.PlaceHolder.pFormat.pObject;
                if ( v36.PlaceHolder.pFormat.pObject )
                {
                  if ( v36.PlaceHolder.pFormat.pObject->RefCount-- == 1 )
                  {
                    Scaleform::Render::Text::TextFormat::~TextFormat(v31);
                    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v31);
                  }
                }
                Scaleform::Render::Text::TextFormat::~TextFormat(&v39);
              }
            }
          }
LABEL_64:
          v33 = v38.pImage.pObject;
          if ( v38.pImage.pObject )
          {
            --v38.pImage.pObject->RefCount;
            if ( !v33->RefCount )
              ((void (__fastcall *)(Scaleform::Render::Text::ImageDesc *, __int64, __int64))v33->vfptr->__vecDelDtor)(
                v33,
                1i64,
                v17);
          }
          v34 = v38.pFontHandle.pObject;
          if ( v38.pFontHandle.pObject && !_InterlockedDecrement(&v38.pFontHandle.pObject->RefCount) && v34 )
            v34->vfptr->__vecDelDtor(v34, 1u);
        }
      }
    }
  }
  return v10;
}

// File Line: 3087
// RVA: 0x9AFE90
void __fastcall Scaleform::Render::Text::DocView::SetFontScaleFactor(Scaleform::Render::Text::DocView *this, float f)
{
  if ( f == 1.0 )
  {
    this->RTFlags &= ~4u;
    this->FontScaleFactor = 20;
  }
  else
  {
    this->RTFlags |= 4u;
    this->FontScaleFactor = (int)(float)(f * 20.0);
  }
}

// File Line: 3102
// RVA: 0x988680
__int64 __fastcall Scaleform::Render::Text::DocView::GetLineIndexAtPoint(
        Scaleform::Render::Text::DocView *this,
        float x,
        float y)
{
  unsigned __int64 FirstVisibleLinePos; // rax
  Scaleform::Render::Text::LineBuffer *p_mLineBuffer; // rcx
  int v6; // edx
  __int64 CurrentPos; // rax
  Scaleform::Render::Text::LineBuffer::Iterator result; // [rsp+20h] [rbp-38h] BYREF

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  FirstVisibleLinePos = this->mLineBuffer.Geom.FirstVisibleLinePos;
  p_mLineBuffer = &this->mLineBuffer;
  v6 = 0;
  if ( (_DWORD)FirstVisibleLinePos
    && this != (Scaleform::Render::Text::DocView *)-80i64
    && FirstVisibleLinePos < this->mLineBuffer.Lines.Data.Size
    && (FirstVisibleLinePos & 0x80000000) == 0i64
    && this->mLineBuffer.Lines.Data.Size )
  {
    v6 = p_mLineBuffer->Lines.Data.Data[(unsigned int)FirstVisibleLinePos]->Data32.OffsetY
       - (*p_mLineBuffer->Lines.Data.Data)->Data32.OffsetY;
  }
  Scaleform::Render::Text::LineBuffer::FindLineAtYOffset(p_mLineBuffer, &result, (float)v6 + y);
  if ( !result.pLineBuffer )
    return 0xFFFFFFFFi64;
  CurrentPos = result.CurrentPos;
  if ( result.CurrentPos >= result.pLineBuffer->Lines.Data.Size || (result.CurrentPos & 0x80000000) != 0 )
    return 0xFFFFFFFFi64;
  return CurrentPos;
}

// File Line: 3115
// RVA: 0x988740
__int64 __fastcall Scaleform::Render::Text::DocView::GetLineIndexOfChar(
        Scaleform::Render::Text::DocView *this,
        unsigned __int64 indexOfChar)
{
  __int64 CurrentPos; // rax
  Scaleform::Render::Text::LineBuffer::Iterator result; // [rsp+20h] [rbp-28h] BYREF

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  Scaleform::Render::Text::LineBuffer::FindLineByTextPos(&this->mLineBuffer, &result, indexOfChar);
  if ( !result.pLineBuffer )
    return 0xFFFFFFFFi64;
  CurrentPos = result.CurrentPos;
  if ( result.CurrentPos >= result.pLineBuffer->Lines.Data.Size || (result.CurrentPos & 0x80000000) != 0 )
    return 0xFFFFFFFFi64;
  return CurrentPos;
}

// File Line: 3127
// RVA: 0x9889C0
unsigned __int64 __fastcall Scaleform::Render::Text::DocView::GetLineOffset(
        Scaleform::Render::Text::DocView *this,
        unsigned int lineIndex)
{
  unsigned __int64 v2; // rdi
  Scaleform::Render::Text::LineBuffer::Line *v4; // rcx
  unsigned __int64 result; // rax

  v2 = lineIndex;
  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  if ( this == (Scaleform::Render::Text::DocView *)-80i64
    || v2 >= this->mLineBuffer.Lines.Data.Size
    || (v2 & 0x80000000) != 0i64 )
  {
    return -1i64;
  }
  v4 = this->mLineBuffer.Lines.Data.Data[v2];
  if ( (v4->MemSize & 0x80000000) == 0 )
    return v4->Data32.TextPos;
  result = v4->Data32.TextPos & 0xFFFFFF;
  if ( (_DWORD)result == 0xFFFFFF )
    return 0xFFFFFFFFi64;
  return result;
}

// File Line: 3139
// RVA: 0x9887A0
unsigned __int64 __fastcall Scaleform::Render::Text::DocView::GetLineLength(
        Scaleform::Render::Text::DocView *this,
        unsigned int lineIndex,
        bool *phasNewLine)
{
  unsigned __int64 v4; // rsi
  Scaleform::Render::Text::LineBuffer *p_mLineBuffer; // rbx
  Scaleform::Render::Text::LineBuffer::Line *v7; // rcx
  unsigned int GlyphsCount; // edx
  __int64 v9; // rcx
  __int64 v10; // rax
  bool v11; // al
  Scaleform::Render::Text::LineBuffer::Line *v12; // rcx

  v4 = lineIndex;
  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  p_mLineBuffer = &this->mLineBuffer;
  if ( p_mLineBuffer && v4 < p_mLineBuffer->Lines.Data.Size && (v4 & 0x80000000) == 0i64 )
  {
    if ( phasNewLine )
    {
      v7 = p_mLineBuffer->Lines.Data.Data[v4];
      if ( (v7->MemSize & 0x80000000) == 0 )
        GlyphsCount = v7->Data32.GlyphsCount;
      else
        GlyphsCount = (unsigned __int8)v7->Data8.GlyphsCount;
      v11 = 0;
      if ( GlyphsCount )
      {
        v9 = (v7->MemSize & 0x80000000) == 0 ? (__int64)&v7->Data8 + 38 : (__int64)(&v7->Data8.Leading + 1);
        v10 = GlyphsCount - 1;
        if ( (*(_BYTE *)(v9 + 8 * v10 + 7) & 1) != 0 && (*(_WORD *)(v9 + 8 * v10 + 4) & 0xF000) != 0 )
          v11 = 1;
      }
      *phasNewLine = v11;
    }
    v12 = p_mLineBuffer->Lines.Data.Data[v4];
    if ( (v12->MemSize & 0x80000000) == 0 )
      return v12->Data32.TextLength;
    else
      return HIBYTE(v12->Data8.TextPosAndLength);
  }
  else
  {
    if ( phasNewLine )
      *phasNewLine = 0;
    return -1i64;
  }
}

// File Line: 3155
// RVA: 0x988A50
wchar_t *__fastcall Scaleform::Render::Text::DocView::GetLineText(
        Scaleform::Render::Text::DocView *this,
        unsigned int lineIndex,
        unsigned __int64 *plen)
{
  unsigned __int64 v4; // rsi
  Scaleform::Render::Text::LineBuffer *p_mLineBuffer; // rdi
  int *v8; // rcx
  unsigned int v9; // eax
  Scaleform::Render::Text::DocView::DocumentText *pObject; // rcx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *pArray; // r8
  __int64 CurIndex; // rdx
  Scaleform::Render::Text::LineBuffer::Line *v13; // rcx
  unsigned __int64 TextLength; // rax
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator result; // [rsp+20h] [rbp-28h] BYREF
  unsigned __int64 pindexInParagraph; // [rsp+60h] [rbp+18h] BYREF

  v4 = lineIndex;
  if ( !plen )
    return 0i64;
  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  p_mLineBuffer = &this->mLineBuffer;
  if ( this == (Scaleform::Render::Text::DocView *)-80i64
    || v4 >= this->mLineBuffer.Lines.Data.Size
    || (v4 & 0x80000000) != 0i64 )
  {
    return 0i64;
  }
  v8 = (int *)p_mLineBuffer->Lines.Data.Data[v4];
  v9 = v8[2];
  if ( *v8 < 0 )
  {
    v9 &= 0xFFFFFFu;
    if ( v9 == 0xFFFFFF )
      v9 = -1;
  }
  pObject = this->pDocument.pObject;
  pindexInParagraph = 0i64;
  Scaleform::Render::Text::StyledText::GetParagraphByIndex(pObject, &result, v9, &pindexInParagraph);
  pArray = result.pArray;
  if ( !result.pArray )
    return 0i64;
  CurIndex = result.CurIndex;
  if ( result.CurIndex < 0 || result.CurIndex >= SLODWORD(result.pArray->Data.Size) )
    return 0i64;
  v13 = p_mLineBuffer->Lines.Data.Data[v4];
  if ( (v13->MemSize & 0x80000000) == 0 )
    TextLength = v13->Data32.TextLength;
  else
    TextLength = HIBYTE(v13->Data8.TextPosAndLength);
  *plen = TextLength;
  return &pArray->Data.Data[CurIndex].pPara->Text.pText[pindexInParagraph];
}

// File Line: 3176
// RVA: 0x98A390
unsigned __int64 __fastcall Scaleform::Render::Text::DocView::GetParagraphLength(
        Scaleform::Render::Text::DocView *this,
        unsigned __int64 charIndex)
{
  Scaleform::Render::Text::DocView::DocumentText *pObject; // rdi
  wchar_t *v5; // rsi
  __int64 Size; // rdx
  unsigned __int64 v7; // r10
  unsigned __int64 v8; // r11
  Scaleform::Render::Text::Paragraph *pPara; // rax
  unsigned __int64 StartIndex; // r9
  Scaleform::Render::Text::Paragraph *v11; // rax
  unsigned __int64 v12; // rdx
  Scaleform::Render::Text::Paragraph *v13; // rdx
  unsigned __int64 result; // rax
  wchar_t *pText; // rdx
  unsigned __int64 v16; // rcx

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  pObject = this->pDocument.pObject;
  v5 = 0i64;
  Size = pObject->Paragraphs.Data.Size;
  v7 = 0i64;
  while ( Size > 0 )
  {
    v8 = (Size >> 1) + v7;
    pPara = pObject->Paragraphs.Data.Data[v8].pPara;
    StartIndex = pPara->StartIndex;
    if ( charIndex >= StartIndex && charIndex < StartIndex + pPara->Text.Size || (int)StartIndex - (int)charIndex >= 0 )
    {
      Size >>= 1;
    }
    else
    {
      v7 = v8 + 1;
      Size += -1 - (Size >> 1);
    }
  }
  if ( v7 >= pObject->Paragraphs.Data.Size )
    return -1i64;
  v11 = pObject->Paragraphs.Data.Data[v7].pPara;
  v12 = v11->StartIndex;
  if ( (charIndex < v12 || charIndex >= v12 + v11->Text.Size) && (_DWORD)v12 != (_DWORD)charIndex )
    return -1i64;
  if ( (v7 & 0x80000000) != 0i64 || (int)v7 >= (__int64)SLODWORD(pObject->Paragraphs.Data.Size) )
    return -1i64;
  v13 = pObject->Paragraphs.Data.Data[(int)v7].pPara;
  result = v13->Text.Size;
  if ( result )
  {
    pText = v13->Text.pText;
    v16 = result - 1;
    if ( pText && v16 < result )
      v5 = &pText[v16];
    if ( !*v5 )
      --result;
  }
  return result;
}

// File Line: 3189
// RVA: 0x988890
char __fastcall Scaleform::Render::Text::DocView::GetLineMetrics(
        Scaleform::Render::Text::DocView *this,
        unsigned int lineIndex,
        Scaleform::Render::Text::DocView::LineMetrics *pmetrics)
{
  unsigned __int64 v4; // rsi
  Scaleform::Render::Text::LineBuffer::Line *v6; // rcx
  int BaseLineOffset; // eax
  int Height; // edx
  int v9; // eax
  unsigned int Width; // eax
  unsigned int v11; // eax
  int Leading; // eax

  v4 = lineIndex;
  if ( !pmetrics )
    return 0;
  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  if ( this == (Scaleform::Render::Text::DocView *)-80i64
    || v4 >= this->mLineBuffer.Lines.Data.Size
    || (v4 & 0x80000000) != 0i64 )
  {
    return 0;
  }
  v6 = this->mLineBuffer.Lines.Data.Data[v4];
  if ( (v6->MemSize & 0x80000000) == 0 )
    BaseLineOffset = v6->Data32.BaseLineOffset;
  else
    BaseLineOffset = v6->Data8.BaseLineOffset;
  pmetrics->Ascent = (int)(float)BaseLineOffset;
  if ( (v6->MemSize & 0x80000000) == 0 )
    Height = v6->Data32.Height;
  else
    Height = v6->Data8.Height;
  if ( (v6->MemSize & 0x80000000) == 0 )
    v9 = v6->Data32.BaseLineOffset;
  else
    v9 = v6->Data8.BaseLineOffset;
  pmetrics->Descent = (int)(float)((float)Height - (float)v9);
  if ( (v6->MemSize & 0x80000000) == 0 )
    Width = v6->Data32.Width;
  else
    Width = v6->Data8.Width;
  pmetrics->Width = Width;
  if ( (v6->MemSize & 0x80000000) == 0 )
    v11 = v6->Data32.Height;
  else
    v11 = v6->Data8.Height;
  pmetrics->Height = v11;
  if ( (v6->MemSize & 0x80000000) == 0 )
    Leading = v6->Data32.Leading;
  else
    Leading = v6->Data8.Leading;
  pmetrics->Leading = Leading;
  pmetrics->FirstCharXOff = v6->Data32.OffsetX;
  return 1;
}

// File Line: 3212
// RVA: 0x981080
char __fastcall Scaleform::Render::Text::DocView::GetCharBoundaries(
        Scaleform::Render::Text::DocView *this,
        Scaleform::Render::Rect<float> *pCharRect,
        unsigned __int64 indexOfChar)
{
  char v6; // r15
  Scaleform::Render::Text::LineBuffer::Line *v7; // rdi
  __int64 TextPos; // rax
  __int64 v9; // rbp
  int OffsetX; // esi
  int i; // ebx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // rcx
  int v13; // eax
  unsigned int Delta; // eax
  int Advance; // eax
  float v16; // xmm3_4
  int Height; // eax
  float v18; // xmm0_4
  float OffsetY; // xmm2_4
  Scaleform::Render::Text::ImageDesc *pObject; // rcx
  Scaleform::Render::Text::FontHandle *v21; // rcx
  Scaleform::Render::Text::LineBuffer::Iterator result; // [rsp+28h] [rbp-F0h] BYREF
  Scaleform::Render::Text::LineBuffer::GlyphIterator v24; // [rsp+50h] [rbp-C8h] BYREF

  if ( !pCharRect || indexOfChar >= Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject) )
    return 0;
  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  Scaleform::Render::Text::LineBuffer::FindLineByTextPos(&this->mLineBuffer, &result, indexOfChar);
  v6 = 0;
  if ( result.pLineBuffer
    && result.CurrentPos < result.pLineBuffer->Lines.Data.Size
    && (result.CurrentPos & 0x80000000) == 0 )
  {
    v7 = result.pLineBuffer->Lines.Data.Data[result.CurrentPos];
    if ( (v7->MemSize & 0x80000000) == 0 )
    {
      TextPos = v7->Data32.TextPos;
    }
    else
    {
      TextPos = v7->Data32.TextPos & 0xFFFFFF;
      if ( (_DWORD)TextPos == 0xFFFFFF )
        TextPos = 0xFFFFFFFFi64;
    }
    v9 = indexOfChar - TextPos;
    Scaleform::Render::Text::LineBuffer::Line::Begin(v7, &v24);
    OffsetX = v7->Data32.OffsetX;
    for ( i = 0; ; ++i )
    {
      pGlyphs = v24.pGlyphs;
      if ( !v24.pGlyphs || v24.pGlyphs >= v24.pEndGlyphs )
        break;
      if ( i == v9 )
      {
        if ( (v24.pGlyphs->Flags & 0x100) == 0 )
        {
          v6 = 1;
          *(_QWORD *)&pCharRect->x1 = 0i64;
          *(_QWORD *)&pCharRect->x2 = 0i64;
          Advance = pGlyphs->Advance;
          if ( (pGlyphs->Flags & 0x40) != 0 )
            Advance = -Advance;
          v16 = (float)Advance;
          pCharRect->x2 = (float)Advance;
          pCharRect->y1 = 40.0;
          if ( (v7->MemSize & 0x80000000) == 0 )
            Height = v7->Data32.Height;
          else
            Height = v7->Data8.Height;
          pCharRect->y2 = (float)Height;
          v18 = (float)OffsetX + 40.0;
          OffsetY = (float)v7->Data32.OffsetY;
          pCharRect->x1 = v18;
          pCharRect->x2 = v16 + v18;
          pCharRect->y1 = OffsetY + 40.0;
          pCharRect->y2 = OffsetY + (float)Height;
        }
        break;
      }
      v13 = v24.pGlyphs->Advance;
      if ( (v24.pGlyphs->Flags & 0x40) != 0 )
        v13 = -v13;
      OffsetX += v13;
      Delta = v24.Delta;
      if ( !v24.Delta )
      {
        Delta = v24.pGlyphs->LenAndFontSize >> 12;
        v24.Delta = Delta;
      }
      ++v24.pGlyphs;
      if ( (v24.pGlyphs->LenAndFontSize & 0xF000) != 0
        && Delta
        && v24.HighlighterIter.CurAdjStartPos < v24.HighlighterIter.NumGlyphs )
      {
        v24.HighlighterIter.CurAdjStartPos += Delta;
        Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(&v24.HighlighterIter);
        v24.Delta = 0;
      }
      Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&v24);
    }
    pObject = v24.pImage.pObject;
    if ( v24.pImage.pObject )
    {
      --v24.pImage.pObject->RefCount;
      if ( !pObject->RefCount )
        pObject->vfptr->__vecDelDtor(pObject, 1u);
    }
    v21 = v24.pFontHandle.pObject;
    if ( v24.pFontHandle.pObject && !_InterlockedDecrement(&v24.pFontHandle.pObject->RefCount) && v21 )
      v21->vfptr->__vecDelDtor(v21, 1u);
  }
  return v6;
}

// File Line: 3251
// RVA: 0x982F10
char __fastcall Scaleform::Render::Text::DocView::GetExactCharBoundaries(
        Scaleform::Render::Text::DocView *this,
        Scaleform::Render::Rect<float> *pCharRect,
        unsigned __int64 indexOfChar)
{
  unsigned __int64 Length; // rax
  char v7; // r13
  Scaleform::Render::Text::LineBuffer::Line *v8; // r14
  unsigned int v9; // r12d
  __int64 TextPos; // rax
  __int64 v11; // rbp
  int v12; // r15d
  int i; // edi
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // rbx
  int v15; // eax
  unsigned int Delta; // eax
  unsigned __int16 Flags; // cx
  float *v18; // rdi
  float v19; // xmm6_4
  float v20; // xmm6_4
  unsigned __int16 Index; // cx
  unsigned __int16 v22; // ax
  int Advance; // eax
  float v24; // xmm1_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  int BaseLineOffset; // eax
  float v28; // xmm3_4
  float v29; // xmm6_4
  float v30; // xmm1_4
  float OffsetY; // xmm2_4
  float v32; // xmm0_4
  Scaleform::Render::Text::ImageDesc *pObject; // rax
  float v34; // xmm3_4
  float v35; // xmm4_4
  Scaleform::Render::Text::ImageDesc *v36; // rcx
  Scaleform::Render::Text::FontHandle *v37; // rcx
  Scaleform::Render::Text::LineBuffer::GlyphIterator v39; // [rsp+30h] [rbp-F8h] BYREF
  Scaleform::Render::Text::LineBuffer::Iterator result; // [rsp+D0h] [rbp-58h] BYREF

  Length = Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject);
  if ( !pCharRect || indexOfChar > Length )
    return 0;
  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  Scaleform::Render::Text::LineBuffer::FindLineByTextPos(&this->mLineBuffer, &result, indexOfChar);
  v7 = 0;
  if ( result.pLineBuffer
    && result.CurrentPos < result.pLineBuffer->Lines.Data.Size
    && (result.CurrentPos & 0x80000000) == 0 )
  {
    v8 = result.pLineBuffer->Lines.Data.Data[result.CurrentPos];
    v9 = -1;
    if ( (v8->MemSize & 0x80000000) == 0 )
    {
      TextPos = v8->Data32.TextPos;
    }
    else
    {
      TextPos = v8->Data32.TextPos & 0xFFFFFF;
      if ( (_DWORD)TextPos == 0xFFFFFF )
        TextPos = 0xFFFFFFFFi64;
    }
    v11 = indexOfChar - TextPos;
    Scaleform::Render::Text::LineBuffer::Line::Begin(v8, &v39);
    v12 = 0;
    for ( i = 0; ; ++i )
    {
      pGlyphs = v39.pGlyphs;
      if ( !v39.pGlyphs || v39.pGlyphs >= v39.pEndGlyphs )
        break;
      if ( i == v11 )
      {
        Flags = v39.pGlyphs->Flags;
        v7 = 1;
        if ( (Flags & 0x800) != 0 )
        {
          pObject = v39.pImage.pObject;
          LODWORD(v34) = LODWORD(v39.pImage.pObject->BaseLineX) ^ _xmm[0];
          pCharRect->x1 = v34;
          LODWORD(v35) = LODWORD(pObject->BaseLineY) ^ _xmm[0];
          pCharRect->y1 = v35;
          v26 = v34 + pObject->ScreenWidth;
          pCharRect->x2 = v26;
          v29 = v35 + pObject->ScreenHeight;
          pCharRect->y2 = v29;
          v30 = (float)v12 + 40.0;
          OffsetY = (float)v8->Data32.OffsetY + 40.0;
          pCharRect->x1 = v34 + v30;
          v32 = OffsetY + v35;
        }
        else
        {
          v18 = (float *)v39.pFontHandle.pObject;
          if ( v39.pFontHandle.pObject )
            v18 = (float *)v39.pFontHandle.pObject->pFont.pObject;
          v19 = (float)(v39.pGlyphs->LenAndFontSize & 0xFFF);
          if ( (Flags & 0x10) != 0 )
            v19 = v19 * 0.0625;
          v20 = (float)(v19 * 20.0) * 0.0009765625;
          Index = v39.pGlyphs->Index;
          v22 = v39.pGlyphs->Index;
          if ( v39.pGlyphs->Index == 0xFFFF )
            v22 = -1;
          if ( v22 == 0xFFFF )
          {
            pCharRect->x1 = 0.0;
            Advance = pGlyphs->Advance;
            if ( (pGlyphs->Flags & 0x40) != 0 )
              Advance = -Advance;
            pCharRect->x2 = (float)Advance;
          }
          else
          {
            if ( Index != 0xFFFF )
              v9 = Index;
            (*(void (__fastcall **)(float *, _QWORD, Scaleform::Render::Rect<float> *))(*(_QWORD *)v18 + 56i64))(
              v18,
              v9,
              pCharRect);
          }
          if ( (pGlyphs->Flags & 0x100) != 0 )
            pCharRect->x2 = pCharRect->x1 + (float)((float)(pCharRect->x2 - pCharRect->x1) * 0.33333334);
          v24 = (float)(v18[5] + v18[4]) * v20;
          v25 = v20 * pCharRect->x1;
          pCharRect->x1 = v25;
          v26 = v20 * pCharRect->x2;
          pCharRect->x2 = v26;
          if ( (v8->MemSize & 0x80000000) == 0 )
            BaseLineOffset = v8->Data32.BaseLineOffset;
          else
            BaseLineOffset = v8->Data8.BaseLineOffset;
          v28 = (float)((float)BaseLineOffset - (float)(v18[4] * v20)) + 40.0;
          pCharRect->y1 = v28;
          v29 = v28 + v24;
          pCharRect->y2 = v28 + v24;
          v30 = (float)v12 + 40.0;
          OffsetY = (float)v8->Data32.OffsetY;
          pCharRect->x1 = v30 + v25;
          v32 = OffsetY + v28;
        }
        pCharRect->y2 = OffsetY + v29;
        pCharRect->y1 = v32;
        pCharRect->x2 = v30 + v26;
        break;
      }
      v15 = v39.pGlyphs->Advance;
      if ( (v39.pGlyphs->Flags & 0x40) != 0 )
        v15 = -v15;
      v12 += v15;
      Delta = v39.Delta;
      if ( !v39.Delta )
      {
        Delta = v39.pGlyphs->LenAndFontSize >> 12;
        v39.Delta = Delta;
      }
      ++v39.pGlyphs;
      if ( (v39.pGlyphs->LenAndFontSize & 0xF000) != 0
        && Delta
        && v39.HighlighterIter.CurAdjStartPos < v39.HighlighterIter.NumGlyphs )
      {
        v39.HighlighterIter.CurAdjStartPos += Delta;
        Scaleform::Render::Text::HighlighterPosIterator::InitCurDesc(&v39.HighlighterIter);
        v39.Delta = 0;
      }
      Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&v39);
    }
    v36 = v39.pImage.pObject;
    if ( v39.pImage.pObject )
    {
      --v39.pImage.pObject->RefCount;
      if ( !v36->RefCount )
        v36->vfptr->__vecDelDtor(v36, 1u);
    }
    v37 = v39.pFontHandle.pObject;
    if ( v39.pFontHandle.pObject && !_InterlockedDecrement(&v39.pFontHandle.pObject->RefCount) && v37 )
      v37->vfptr->__vecDelDtor(v37, 1u);
  }
  return v7;
}

// File Line: 3318
// RVA: 0x984770
unsigned __int64 __fastcall Scaleform::Render::Text::DocView::GetFirstCharInParagraph(
        Scaleform::Render::Text::DocView *this,
        unsigned __int64 indexOfChar)
{
  Scaleform::Render::Text::DocView::DocumentText *pObject; // rdi
  unsigned __int64 v3; // r11
  __int64 Size; // r8
  unsigned __int64 v6; // rbx
  Scaleform::Render::Text::Paragraph *pPara; // rax
  unsigned __int64 StartIndex; // r10
  Scaleform::Render::Text::Paragraph *v9; // rax
  unsigned __int64 v10; // rdx

  pObject = this->pDocument.pObject;
  v3 = 0i64;
  Size = pObject->Paragraphs.Data.Size;
  while ( Size > 0 )
  {
    v6 = (Size >> 1) + v3;
    pPara = pObject->Paragraphs.Data.Data[v6].pPara;
    StartIndex = pPara->StartIndex;
    if ( indexOfChar >= StartIndex && indexOfChar < StartIndex + pPara->Text.Size
      || (int)StartIndex - (int)indexOfChar >= 0 )
    {
      Size >>= 1;
    }
    else
    {
      v3 = v6 + 1;
      Size += -1 - (Size >> 1);
    }
  }
  if ( v3 < pObject->Paragraphs.Data.Size
    && ((v9 = pObject->Paragraphs.Data.Data[v3].pPara, v10 = v9->StartIndex, indexOfChar >= v10)
     && indexOfChar < v10 + v9->Text.Size
     || (_DWORD)v10 == (_DWORD)indexOfChar)
    && (v3 & 0x80000000) == 0i64
    && (int)v3 < (__int64)SLODWORD(pObject->Paragraphs.Data.Size) )
  {
    return pObject->Paragraphs.Data.Data[(int)v3].pPara->StartIndex;
  }
  else
  {
    return -1i64;
  }
}

// File Line: 3329
// RVA: 0x980260
__int64 __fastcall Scaleform::Render::Text::DocView::GetBottomVScroll(Scaleform::Render::Text::DocView *this)
{
  unsigned __int64 FirstVisibleLinePos; // rbx
  Scaleform::Render::Text::LineBuffer *p_mLineBuffer; // rdi
  unsigned int v4; // esi
  int v5; // ecx
  bool v6; // bp
  float v7; // xmm6_4

  Scaleform::Render::Text::DocView::ForceReformat(this);
  FirstVisibleLinePos = this->mLineBuffer.Geom.FirstVisibleLinePos;
  p_mLineBuffer = &this->mLineBuffer;
  v4 = 0;
  v5 = 0;
  if ( (_DWORD)FirstVisibleLinePos
    && p_mLineBuffer
    && FirstVisibleLinePos < p_mLineBuffer->Lines.Data.Size
    && (FirstVisibleLinePos & 0x80000000) == 0i64
    && p_mLineBuffer->Lines.Data.Size )
  {
    v5 = p_mLineBuffer->Lines.Data.Data[FirstVisibleLinePos]->Data32.OffsetY
       - (*p_mLineBuffer->Lines.Data.Data)->Data32.OffsetY;
  }
  v6 = (p_mLineBuffer->Geom.Flags & 4) != 0;
  LODWORD(v7) = COERCE_UNSIGNED_INT((float)v5) ^ _xmm[0];
  while ( p_mLineBuffer
       && (unsigned int)FirstVisibleLinePos < p_mLineBuffer->Lines.Data.Size
       && (FirstVisibleLinePos & 0x80000000) == 0i64
       && (v6 || Scaleform::Render::Text::LineBuffer::IsLineVisible(p_mLineBuffer, FirstVisibleLinePos, v7)) )
  {
    v4 = FirstVisibleLinePos;
    LODWORD(FirstVisibleLinePos) = FirstVisibleLinePos + 1;
  }
  return v4;
}

// File Line: 3341
// RVA: 0x9AE5A0
char __fastcall Scaleform::Render::Text::DocView::SetBottomVScroll(
        Scaleform::Render::Text::DocView *this,
        int newBottomMostLine)
{
  unsigned int Size; // eax
  Scaleform::Render::Text::LineBuffer *p_mLineBuffer; // r14
  __int64 v5; // r8
  unsigned __int64 v6; // rdi
  Scaleform::Render::Text::LineBuffer::Line *v7; // rax
  unsigned int Height; // r10d
  int v9; // ecx
  unsigned int v10; // ebx
  char v11; // di
  unsigned int MaxVScroll; // eax
  Scaleform::Render::Text::DocView::DocumentListener *pObject; // rcx

  Size = this->mLineBuffer.Lines.Data.Size;
  if ( newBottomMostLine >= Size )
    newBottomMostLine = Size - 1;
  p_mLineBuffer = &this->mLineBuffer;
  v5 = (unsigned int)newBottomMostLine;
  if ( this == (Scaleform::Render::Text::DocView *)-80i64 )
    return 0;
  v6 = this->mLineBuffer.Lines.Data.Size;
  if ( (unsigned int)newBottomMostLine >= v6 || newBottomMostLine < 0 )
    return 0;
  v7 = p_mLineBuffer->Lines.Data.Data[newBottomMostLine];
  if ( (v7->MemSize & 0x80000000) == 0 )
    Height = v7->Data32.Height;
  else
    Height = v7->Data8.Height;
  if ( (v7->MemSize & 0x80000000) == 0 )
  {
    LOWORD(v9) = v7->Data32.Leading;
    if ( (__int16)v9 > 0 )
    {
      v9 = (__int16)v9;
      goto LABEL_15;
    }
  }
  else
  {
    LOBYTE(v9) = v7->Data8.Leading;
    if ( (char)v9 > 0 )
    {
      v9 = (char)v9;
      goto LABEL_15;
    }
  }
  v9 = 0;
LABEL_15:
  v10 = newBottomMostLine;
  do
  {
    if ( (unsigned int)newBottomMostLine >= v6 )
      break;
    if ( newBottomMostLine < 0 )
      break;
    if ( (float)p_mLineBuffer->Lines.Data.Data[newBottomMostLine]->Data32.OffsetY < (float)((float)((float)(int)(v7->Data32.OffsetY + v9 + Height)
                                                                                                  - this->mLineBuffer.Geom.VisibleRect.y2)
                                                                                          + this->mLineBuffer.Geom.VisibleRect.y1) )
      break;
    v10 = v5;
    --newBottomMostLine;
    --v5;
  }
  while ( v5 >= 0 );
  v11 = 0;
  MaxVScroll = Scaleform::Render::Text::DocView::GetMaxVScroll(this);
  if ( v10 > MaxVScroll )
    v10 = MaxVScroll;
  if ( this->mLineBuffer.Geom.FirstVisibleLinePos != v10 )
  {
    p_mLineBuffer->Geom.FirstVisibleLinePos = v10;
    p_mLineBuffer->Geom.Flags |= 1u;
    pObject = this->pDocumentListener.pObject;
    if ( pObject )
      ((void (__fastcall *)(Scaleform::Render::Text::DocView::DocumentListener *, Scaleform::Render::Text::DocView *, _QWORD))pObject->vfptr[4].__vecDelDtor)(
        pObject,
        this,
        v10);
    return 1;
  }
  return v11;
}

// File Line: 3368
// RVA: 0x967860
Scaleform::Render::Text::DocView::HighlightDescLoc *__fastcall Scaleform::Render::Text::DocView::CreateHighlighterManager(
        Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView::HighlightDescLoc *result; // rax
  int v3; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::Render::Text::DocView::HighlightDescLoc *v4; // [rsp+60h] [rbp+18h]
  Scaleform::Render::Text::DocView::HighlightDescLoc *v5; // [rsp+68h] [rbp+20h]

  if ( this->pHighlight )
    return this->pHighlight;
  v3 = 74;
  result = (Scaleform::Render::Text::DocView::HighlightDescLoc *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Text::DocView *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
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
  this->pHighlight = result;
  return result;
}

// File Line: 3389
// RVA: 0x9BE550
void __fastcall Scaleform::Render::Text::DocView::UpdateHighlight(
        Scaleform::Render::Text::DocView *this,
        Scaleform::Render::Text::HighlightDesc *desc)
{
  Scaleform::Render::Text::DocView::HighlightDescLoc *pHighlight; // rax

  pHighlight = this->pHighlight;
  if ( pHighlight )
  {
    if ( (this->RTFlags & 0x40) == 0 )
      *(_WORD *)&pHighlight->HighlightManager.Valid = 0;
  }
}

// File Line: 3397
// RVA: 0x98B550
Scaleform::Render::Text::HighlightDesc *__fastcall Scaleform::Render::Text::DocView::GetSelectionHighlighterDesc(
        Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView::HighlightDescLoc *pHighlight; // rbx
  Scaleform::Render::Text::HighlightDesc *result; // rax
  Scaleform::Render::Text::HighlightDesc desc; // [rsp+20h] [rbp-48h] BYREF

  pHighlight = this->pHighlight;
  if ( !pHighlight || (this->RTFlags & 0x40) != 0 )
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
    return Scaleform::Render::Text::Highlighter::CreateHighlighter(&pHighlight->HighlightManager, &desc);
  }
  return result;
}

// File Line: 3416
// RVA: 0x98B490
Scaleform::Render::Text::HighlightDesc *__fastcall Scaleform::Render::Text::DocView::GetSelectionHighlighterDesc(
        Scaleform::Render::Text::DocView *this)
{
  __int64 v3; // rax
  int v4; // [rsp+58h] [rbp+10h] BYREF
  __int64 v5; // [rsp+60h] [rbp+18h]
  __int64 v6; // [rsp+68h] [rbp+20h]

  if ( (this->RTFlags & 0x40) != 0 )
    return 0i64;
  if ( !this->pHighlight )
  {
    v4 = 74;
    v3 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Text::DocView *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
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
    this->pHighlight = (Scaleform::Render::Text::DocView::HighlightDescLoc *)v3;
  }
  return Scaleform::Render::Text::DocView::GetSelectionHighlighterDesc(this);
}

// File Line: 3425
// RVA: 0x9B3AE0
void __fastcall Scaleform::Render::Text::DocView::SetSelection(
        Scaleform::Render::Text::DocView *this,
        unsigned __int64 startPos,
        unsigned __int64 endPos,
        bool highlightSelection)
{
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // rsi
  __int64 v7; // rax
  unsigned __int64 v8; // rax
  Scaleform::Render::Text::HighlightDesc *SelectionHighlighterDesc; // rax
  unsigned __int64 v10; // rdi
  int v11; // [rsp+78h] [rbp+20h] BYREF

  v4 = endPos;
  v5 = startPos;
  this->BeginSelection = startPos;
  this->EndSelection = endPos;
  if ( highlightSelection )
  {
    if ( !this->pHighlight )
    {
      v11 = 74;
      v7 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Text::DocView *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
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
      this->pHighlight = (Scaleform::Render::Text::DocView::HighlightDescLoc *)v7;
    }
    if ( v4 < v5 )
    {
      v8 = v4;
      v4 = v5;
      v5 = v8;
    }
    if ( (this->RTFlags & 0x40) == 0 )
    {
      SelectionHighlighterDesc = Scaleform::Render::Text::DocView::GetSelectionHighlighterDesc(this);
      v10 = v4 - v5;
      if ( SelectionHighlighterDesc->StartPos != v5 || SelectionHighlighterDesc->Length != v10 )
      {
        SelectionHighlighterDesc->StartPos = v5;
        SelectionHighlighterDesc->Length = v10;
        *(_WORD *)&this->pHighlight->HighlightManager.Valid = 0;
      }
    }
  }
}

// File Line: 3474
// RVA: 0x9B3BD0
void __fastcall Scaleform::Render::Text::DocView::SetSelectionBackgroundColor(
        Scaleform::Render::Text::DocView *this,
        unsigned int color)
{
  Scaleform::Render::Text::HighlightDesc *SelectionHighlighterDesc; // rax
  char Flags; // r8
  unsigned int Raw; // [rsp+30h] [rbp+8h]

  if ( (this->RTFlags & 0x40) == 0 )
  {
    SelectionHighlighterDesc = Scaleform::Render::Text::DocView::GetSelectionHighlighterDesc(this);
    Flags = SelectionHighlighterDesc->Info.Flags;
    if ( (Flags & 8) != 0 )
      Raw = SelectionHighlighterDesc->Info.BackgroundColor.Raw;
    else
      Raw = 0;
    if ( Raw != color )
    {
      SelectionHighlighterDesc->Info.Flags = Flags | 8;
      SelectionHighlighterDesc->Info.BackgroundColor.Raw = color;
      *(_WORD *)&this->pHighlight->HighlightManager.Valid = 0;
    }
  }
}

// File Line: 3487
// RVA: 0x9B3C40
void __fastcall Scaleform::Render::Text::DocView::SetSelectionTextColor(
        Scaleform::Render::Text::DocView *this,
        unsigned int color)
{
  Scaleform::Render::Text::HighlightDesc *SelectionHighlighterDesc; // rax
  char Flags; // r8
  unsigned int Raw; // [rsp+30h] [rbp+8h]

  if ( (this->RTFlags & 0x40) == 0 )
  {
    SelectionHighlighterDesc = Scaleform::Render::Text::DocView::GetSelectionHighlighterDesc(this);
    Flags = SelectionHighlighterDesc->Info.Flags;
    if ( (Flags & 0x10) != 0 )
      Raw = SelectionHighlighterDesc->Info.TextColor.Raw;
    else
      Raw = 0;
    if ( Raw != color )
    {
      SelectionHighlighterDesc->Info.Flags = Flags | 0x10;
      SelectionHighlighterDesc->Info.TextColor.Raw = color;
      *(_WORD *)&this->pHighlight->HighlightManager.Valid = 0;
    }
  }
}

// File Line: 3516
// RVA: 0x9AEFB0
void __fastcall Scaleform::Render::Text::DocView::SetDefaultTextAndParaFormat(
        Scaleform::Render::Text::DocView *this,
        unsigned __int64 cursorPos)
{
  unsigned __int64 FirstCharInParagraph; // rax
  unsigned __int64 v5; // r9
  Scaleform::Render::Text::DocView::DocumentText *pObject; // rbx
  Scaleform::Render::Text::ParagraphFormat *v7; // rdi
  Scaleform::Render::Text::ParagraphFormat *v8; // rcx
  Scaleform::Render::Text::TextFormat *v9; // rdx
  Scaleform::Render::Text::ParagraphFormat *ppdestParaFmt; // [rsp+40h] [rbp+18h] BYREF
  Scaleform::Render::Text::TextFormat *ppdestTextFmt; // [rsp+48h] [rbp+20h] BYREF

  ppdestParaFmt = 0i64;
  ppdestTextFmt = 0i64;
  FirstCharInParagraph = Scaleform::Render::Text::DocView::GetFirstCharInParagraph(this, cursorPos);
  if ( FirstCharInParagraph != -1i64 )
  {
    v5 = cursorPos - 1;
    if ( FirstCharInParagraph == cursorPos )
      v5 = cursorPos;
    if ( (unsigned __int8)Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
                            this->pDocument.pObject,
                            &ppdestTextFmt,
                            &ppdestParaFmt,
                            v5) )
    {
      pObject = this->pDocument.pObject;
      v7 = ppdestParaFmt;
      if ( ppdestParaFmt )
        ++ppdestParaFmt->RefCount;
      v8 = pObject->pDefaultParagraphFormat.pObject;
      if ( v8 )
        Scaleform::Render::Text::ParagraphFormat::Release(v8);
      v9 = ppdestTextFmt;
      pObject->pDefaultParagraphFormat.pObject = v7;
      Scaleform::Render::Text::StyledText::SetDefaultTextFormat(this->pDocument.pObject, v9);
    }
  }
}

